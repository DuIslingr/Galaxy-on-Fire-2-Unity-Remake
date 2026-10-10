#!/usr/bin/env python3
"""Measures a space game's flight behaviour from gameplay recordings (black-box: the video only).

Made to tune the remake's free flight (FlightModel.StepFree) against EVERSPACE 2's feel: how fast a ship reaches its top
speed and stops, how its turn and roll rates build up, how long a boost lasts. Nothing of the game itself is read; the
numbers come from what the screen shows. The recording protocol is Reference/research/es2_flight_measurements.md.

Needs ffmpeg / ffprobe and the tesseract CLI on the PATH, and numpy.

  es2measure.py probe  clip.mp4 [--at 1.0 2.5 ...] [--out dir]
        Video info, and full-size PNG frames at the given times (to find the speed readout's rectangle).
  es2measure.py speed  clip.mp4 --crop X,Y,W,H [--start S] [--end S] [--step N] [--csv out.csv] [--invert]
        Reads the speed readout in that rectangle (source pixels) on every Nth frame: CSV t,speed.
  es2measure.py rate   clip.mp4 --hfov DEG [--mask X,Y,W,H ...] [--hud] [--static] [--start S] [--end S] [--step N] [--csv out.csv]
        Yaw / pitch / roll rates (deg/s) from how the background moves between frames (phase correlation; roll in
        log-polar space). --hfov: the game's horizontal field of view; --mask: HUD parts and the ship to ignore.
  es2measure.py zoom   clip.mp4 [--mask X,Y,W,H ...] [--hud] [--static] [--top SPEED --plateau S0,S1] [--csv out.csv]
        Flying straight at a surface: how fast the view around the centre grows (1/s = speed / distance), from the scale
        change between frames in log-polar space. With --top (the speed reached on the plateau S0..S1 seconds, e.g. a
        known top speed) also the distance and the speed over time: distance' = -speed, speed = growth x distance.
  es2measure.py bar    clip.mp4 --crop X,Y,W,H [--vertical] [--threshold T] [--start S] [--end S] [--csv out.csv]
        How full a bar (the boost energy) is, 0..1: the share of its length lit, read along the bar's middle.
  es2measure.py total  data.csv --column yaw [--start S] [--end S]
        The angle a rate column adds up to (degrees): a known 360-degree turn checks the field of view given to 'rate'.
  es2measure.py fit    data.csv [--column speed] [--abs] [--start S] [--end S]
        Fits the change in a column: a constant rate (linear ramp) against an exponential approach, with the top /
        settled value, the 10-90 % time and which shape matches better.
"""

import argparse
import csv
import json
import math
import os
import subprocess
import sys

import numpy as np

WORK_WIDTH = 640   # frames are scaled to this width for the motion measurements
MIN_CONF, MIN_ROLL_CONF = 0.1, 0.08   # phase correlation peaks below these are no measurement (tested on synthetic clips)
STATIC_RATIO = 0.15   # --hud: a moving peak counts when it reaches this share of the HUD's no-motion peak


# ---- video ----------------------------------------------------------------------------------------------------------

def probe(path):
    out = subprocess.run(["ffprobe", "-v", "error", "-select_streams", "v:0", "-show_entries",
                          "stream=width,height,r_frame_rate,nb_frames:format=duration", "-of", "json", path],
                         capture_output=True, text=True, check=True).stdout
    j = json.loads(out)
    s = j["streams"][0]
    num, den = (int(x) for x in s["r_frame_rate"].split("/"))
    return {"width": int(s["width"]), "height": int(s["height"]), "fps": num / den,
            "duration": float(j["format"]["duration"])}


def frames(path, vf, width, height, start=None, end=None, gray=True):
    """Yields (time, frame) for every frame after the filter 'vf' (which must produce width x height)."""
    info = probe(path)
    cmd = ["ffmpeg", "-v", "error"]
    if start is not None:
        cmd += ["-ss", str(start)]
    cmd += ["-i", path]
    if end is not None:
        cmd += ["-t", str(end - (start or 0.0))]
    fmt = "gray" if gray else "rgb24"
    cmd += ["-vf", f"{vf},format={fmt}" if vf else f"format={fmt}", "-f", "rawvideo", "-"]
    ch = 1 if gray else 3
    size = width * height * ch
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE)
    i = 0
    t0 = start or 0.0
    try:
        while True:
            buf = p.stdout.read(size)
            if len(buf) < size:
                break
            a = np.frombuffer(buf, np.uint8).reshape(height, width) if gray else \
                np.frombuffer(buf, np.uint8).reshape(height, width, 3)
            yield t0 + i / info["fps"], a
            i += 1
    finally:
        p.stdout.close()
        p.wait()


def parse_rect(s):
    x, y, w, h = (int(v) for v in s.split(","))
    return x, y, w, h


# ---- probe ----------------------------------------------------------------------------------------------------------

def cmd_probe(a):
    info = probe(a.video)
    print(json.dumps(info, indent=1))
    if a.at:
        os.makedirs(a.out, exist_ok=True)
        for t in a.at:
            png = os.path.join(a.out, f"{os.path.splitext(os.path.basename(a.video))[0]}_{t:07.2f}.png")
            subprocess.run(["ffmpeg", "-v", "error", "-y", "-ss", str(t), "-i", a.video, "-frames:v", "1", png], check=True)
            print(png)


# ---- speed readout (OCR) --------------------------------------------------------------------------------------------

def otsu(img):
    hist = np.bincount(img.ravel(), minlength=256).astype(float)
    total = img.size
    sum_all = np.dot(np.arange(256), hist)
    best, thr, w_b, sum_b = -1.0, 127, 0.0, 0.0
    for t in range(256):
        w_b += hist[t]
        if w_b == 0 or w_b == total:
            continue
        sum_b += t * hist[t]
        m_b = sum_b / w_b
        m_f = (sum_all - sum_b) / (total - w_b)
        between = w_b * (total - w_b) * (m_b - m_f) ** 2
        if between > best:
            best, thr = between, t
    return thr


def open_binary(bw, r):
    """Morphological opening with a (2r+1)^2 square: specks smaller than the square (stars in the crop) go, strokes stay."""
    def shift_all(a, op):
        p = np.pad(a, r, constant_values=op is np.logical_or)
        out = a.copy()
        for dy in range(2 * r + 1):
            for dx in range(2 * r + 1):
                out = op(out, p[dy:dy + a.shape[0], dx:dx + a.shape[1]])
        return out
    eroded = shift_all(bw, np.logical_and)
    p = np.pad(eroded, r, constant_values=False)
    out = eroded.copy()
    for dy in range(2 * r + 1):
        for dx in range(2 * r + 1):
            out |= p[dy:dy + bw.shape[0], dx:dx + bw.shape[1]]
    return out


def ocr_number(img, invert):
    """The number in a small grey crop (bright digits on a dark HUD unless 'invert'), or None. Units after it ("m",
    "km") are allowed in the recognised characters, so tesseract doesn't read them as digits, then dropped."""
    from io import BytesIO
    from PIL import Image
    h, w = img.shape
    big = np.array(Image.fromarray(img.astype(np.uint8)).resize((w * 3, h * 3), Image.LANCZOS))   # small HUD digits read far better scaled up
    thr = otsu(big)
    bw = (big > thr) if not invert else (big < thr)
    bw = open_binary(bw, 2)
    page = np.pad(np.where(bw, 0, 255).astype(np.uint8), 20, constant_values=255)   # black text on white
    png = BytesIO()
    Image.fromarray(page).save(png, "PNG")          # the tesseract CLI reads no PNM from stdin
    out = subprocess.run(["tesseract", "stdin", "stdout", "--psm", "7", "-c", "tessedit_char_whitelist=0123456789.km"],
                         input=png.getvalue(), capture_output=True).stdout.decode(errors="ignore").strip()
    digits = "".join(ch for ch in out.split()[0] if ch.isdigit() or ch == ".") if out.split() else ""
    try:
        return float(digits) if digits else None
    except ValueError:
        return None


def cmd_speed(a):
    x, y, w, h = parse_rect(a.crop)
    rows, prev = [], None
    for i, (t, img) in enumerate(frames(a.video, f"crop={w}:{h}:{x}:{y}", w, h, a.start, a.end)):
        if i % a.step:
            continue
        v = ocr_number(img, a.invert)
        # A misread (a lost or doubled digit) jumps by far more than any ship changes speed in one frame.
        if v is not None and prev is not None and abs(v - prev) > max(a.max_jump, 0.5 * abs(prev)):
            v = None
        if v is not None:
            prev = v
        rows.append((round(t, 4), v))
    write_csv(a.csv, ["t", "speed"], rows)
    good = sum(1 for _, v in rows if v is not None)
    print(f"{good} / {len(rows)} frames read -> {a.csv or 'stdout'}", file=sys.stderr)


# ---- turn / roll rates (phase correlation) --------------------------------------------------------------------------

def hann2(h, w):
    return np.outer(np.hanning(h), np.hanning(w))


def phase_shift(a, b, window=None, ignore_static=False):
    """Sub-pixel translation of b against a (dx, dy): content that moved right / down is positive.
    ignore_static: a HUD drawn over the view makes a peak at no motion; the strongest peak elsewhere is taken instead
    when it stands out from the noise (STATIC_RATIO of the no-motion peak), else no motion."""
    if window is not None:
        a, b = a * window, b * window
    fa, fb = np.fft.fft2(a), np.fft.fft2(b)
    r = fb * np.conj(fa)
    r /= np.abs(r) + 1e-9
    c = np.fft.ifft2(r).real
    py, px = np.unravel_index(np.argmax(c), c.shape)
    if ignore_static and abs(((py + c.shape[0] // 2) % c.shape[0]) - c.shape[0] // 2) <= 1 \
            and abs(((px + c.shape[1] // 2) % c.shape[1]) - c.shape[1] // 2) <= 1:
        zero = float(c[py, px])
        moved = c.copy()
        for dy in (-2, -1, 0, 1, 2):
            for dx in (-2, -1, 0, 1, 2):
                moved[dy % c.shape[0], dx % c.shape[1]] = -1e9
        qy, qx = np.unravel_index(np.argmax(moved), c.shape)
        noise = float(np.std(c))
        if moved[qy, qx] > max(STATIC_RATIO * zero, 6 * noise):
            py, px = qy, qx

    def sub(cm, cp, c0):
        d = cm - 2 * c0 + cp
        return 0.0 if abs(d) < 1e-12 else 0.5 * (cm - cp) / d

    h, w = c.shape
    dx = px + sub(c[py, (px - 1) % w], c[py, (px + 1) % w], c[py, px])
    dy = py + sub(c[(py - 1) % h, px], c[(py + 1) % h, px], c[py, px])
    if dx > w / 2:
        dx -= w
    if dy > h / 2:
        dy -= h
    return dx, dy, float(c[py, px])


def log_polar(img, rmin, rmax, n_r=96, n_theta=720):
    h, w = img.shape
    cy, cx = (h - 1) / 2, (w - 1) / 2
    r = np.exp(np.linspace(math.log(rmin), math.log(rmax), n_r))
    th = np.linspace(0, 2 * math.pi, n_theta, endpoint=False)
    xs = (cx + np.outer(r, np.cos(th))).round().astype(int).clip(0, w - 1)
    ys = (cy + np.outer(r, np.sin(th))).round().astype(int).clip(0, h - 1)
    return img[ys, xs]   # rows = radius, columns = angle


def cmd_rate(a):
    info = probe(a.video)
    sw, sh = info["width"], info["height"]
    w = WORK_WIDTH
    h = int(round(sh * w / sw / 2)) * 2
    scale = w / sw
    focal = (w / 2) / math.tan(math.radians(a.hfov) / 2)   # pixels, at the working width
    masks = [tuple(int(round(v * scale)) for v in parse_rect(m)) for m in (a.mask or [])]
    win = hann2(h, w)
    rmax = min(w, h) * 0.48
    rows, prev, prev_t, prev_lp = [], None, None, None
    clip = [(t, img) for i, (t, img) in enumerate(frames(a.video, f"scale={w}:{h}", w, h, a.start, a.end)) if i % a.step == 0]
    # --static: each pixel's median over the clip is the still overlay (HUD, cockpit frame); taking it away keeps it from
    # outweighing a dark, low-contrast scene that turns fast.
    static = np.median(np.stack([f for _, f in clip[::3]]), axis=0).astype(np.float32) if a.static else None
    for t, img in clip:
        f = img.astype(np.float32)
        if static is not None: f -= static
        m = f.mean()
        for (mx, my, mw, mh) in masks:
            f[my:my + mh, mx:mx + mw] = m      # the HUD and the ship don't move with the view
        f -= f.mean()
        lp = log_polar(f, 8, rmax)
        lp -= lp.mean(axis=1, keepdims=True)
        if prev is not None:
            dt = t - prev_t
            dx, dy, conf = phase_shift(prev, f, win, a.hud)
            # The view turned right -> the background slides left (dx < 0); nose up -> it slides down (dy > 0).
            yaw = -math.degrees(math.atan(dx / focal)) / dt
            pitch = math.degrees(math.atan(dy / focal)) / dt
            dth, _, rconf = phase_shift(prev_lp, lp, None, a.hud)   # columns = angle: a roll shifts the columns
            roll = -dth * 360.0 / lp.shape[1] / dt          # rolled right (clockwise) -> the view turns anticlockwise
            # A weak correlation peak means the motion wasn't that kind (a roll smears the pan's peak, a pan the roll's).
            ok, rok = (conf >= MIN_CONF, rconf >= MIN_ROLL_CONF) if not a.hud else (True, True)
            rows.append((round(t, 4), round(yaw, 3) if ok else "", round(pitch, 3) if ok else "",
                         round(roll, 3) if rok else "", round(conf, 4), round(rconf, 4)))
        prev, prev_t, prev_lp = f, t, lp
    write_csv(a.csv, ["t", "yaw", "pitch", "roll", "conf", "roll_conf"], rows)
    print(f"{len(rows)} frame pairs -> {a.csv or 'stdout'} (focal {focal:.1f} px at {w} px wide)", file=sys.stderr)


# ---- forward motion from the view's growth --------------------------------------------------------------------------

def cmd_zoom(a):
    info = probe(a.video)
    sw, sh = info["width"], info["height"]
    w = WORK_WIDTH
    h = int(round(sh * w / sw / 2)) * 2
    scale = w / sw
    masks = [tuple(int(round(v * scale)) for v in parse_rect(m)) for m in (a.mask or [])]
    rmin, rmax, n_r = 6.0, min(w, h) * 0.48, 128
    step = math.log(rmax / rmin) / (n_r - 1)       # log-radius per row
    clip = [(t, img.astype(np.float32)) for t, img in frames(a.video, f"scale={w}:{h}", w, h, a.start, a.end)]
    # A HUD drawn over the view never moves: each pixel's median over the clip is that overlay (and the far, still
    # parts of the scene); taking it away leaves the moving scene, so the overlay's no-motion peak doesn't pull the
    # estimate toward zero.
    static = np.median(np.stack([f for _, f in clip[::3]]), axis=0) if a.static else None
    rows, prev, prev_t = [], None, None
    for t, f in clip:
        if static is not None: f = f - static
        m = f.mean()
        for (mx, my, mw, mh) in masks:
            f[my:my + mh, mx:mx + mw] = m
        lp = log_polar(f - m, rmin, rmax, n_r, 360)
        lp -= lp.mean(axis=1, keepdims=True)
        if prev is not None:
            _, dr, conf = phase_shift(prev, lp, None, a.hud)
            # Rows are log-radius: content moving outward (approaching) shifts to higher rows.
            rows.append([round(t, 4), dr * step / (t - prev_t), round(conf, 4)])
        prev, prev_t = lp, t
    if a.top is not None and rows:
        # distance' = -v and v = growth * distance: distance = d0 * exp(-integral of growth). d0 is set so the plateau's
        # mean speed is the given top speed (the growth gives speed / distance only).
        t = np.array([r[0] for r in rows]); g = smooth(np.array([r[1] for r in rows]), 5)
        dt = np.diff(t, prepend=t[0])
        rel = np.exp(-np.cumsum(g * dt))
        p0, p1 = (float(x) for x in a.plateau.split(","))
        sel = (t >= p0) & (t <= p1)
        d0 = a.top / np.mean(np.abs(g[sel] * rel[sel]))
        for r, gi, ri in zip(rows, g, rel):
            r += [round(d0 * ri, 2), round(gi * d0 * ri, 3)]
        header = ["t", "growth", "conf", "distance", "speed"]
        print(f"distance to the surface at the start: {d0:.0f} (units of --top x seconds)", file=sys.stderr)
    else:
        header = ["t", "growth", "conf"]
    for r in rows: r[1] = round(r[1], 5)
    write_csv(a.csv, header, rows)
    print(f"{len(rows)} frame pairs -> {a.csv or 'stdout'}", file=sys.stderr)


# ---- bars (boost energy) --------------------------------------------------------------------------------------------

def cmd_bar(a):
    x, y, w, h = parse_rect(a.crop)
    times, bands = [], []
    for t, img in frames(a.video, f"crop={w}:{h}:{x}:{y}", w, h, a.start, a.end):
        # Read along the bar's middle (3 pixels wide): a vertical bar fills upward, from the bottom.
        band = img[:, max(0, w // 2 - 1):w // 2 + 2].mean(axis=1)[::-1] if a.vertical else \
            img[max(0, h // 2 - 1):h // 2 + 2, :].mean(axis=0)
        times.append(t)
        bands.append(band)
    bands = np.array(bands)
    # Lit against empty over the whole clip (one frame may be all full or all empty).
    thr = a.threshold if a.threshold is not None else otsu(bands.clip(0, 255).astype(np.uint8))
    rows = []
    for t, band in zip(times, bands):
        lit = band > thr
        n = len(lit) if lit.all() else int(np.argmin(lit))   # the lit run from the filling end
        rows.append((round(t, 4), round(n / len(lit), 4)))
    write_csv(a.csv, ["t", "fill"], rows)
    print(f"{len(rows)} frames, threshold {thr} -> {a.csv or 'stdout'}", file=sys.stderr)


def cmd_total(a):
    total, prev_t = 0.0, None
    with open(a.csv) as f:
        for row in csv.DictReader(f):
            t = float(row["t"])
            if (a.start is not None and t < a.start) or (a.end is not None and t > a.end):
                prev_t = None
                continue
            val = row.get(a.column)
            if prev_t is not None and val not in (None, "", "None"):
                total += float(val) * (t - prev_t)
            prev_t = t
    print(f"{a.column}: {total:.2f} degrees")


# ---- fitting --------------------------------------------------------------------------------------------------------

def smooth(v, n=5):
    """Outliers (a misread digit, a bad correlation) replaced by the running median, then a running mean: a median
    alone is biased on values that alternate frame to frame (a pan of 7, 8, 7, 8 pixels)."""
    if len(v) < n:
        return v
    pad = n // 2
    p = np.pad(v, pad, mode="edge")
    med = np.array([np.median(p[i:i + n]) for i in range(len(v))])
    dev = np.abs(v - med)
    mad = np.median(dev) + 1e-9
    v = np.where(dev > 6 * mad + 0.25 * np.abs(med) + 1e-3, med, v)   # a lost or extra digit is far more than 25 %
    p = np.pad(v, pad, mode="edge")
    return np.convolve(p, np.ones(n) / n, mode="valid")


def cmd_fit(a):
    t, v = [], []
    with open(a.csv) as f:
        for row in csv.DictReader(f):
            val = row.get(a.column)
            tt_ = float(row["t"])
            if val in (None, "", "None") or (a.start is not None and tt_ < a.start) or (a.end is not None and tt_ > a.end):
                continue
            t.append(tt_)
            v.append(abs(float(val)) if a.abs else float(val))
    t, v = np.array(t), smooth(np.array(v))
    if len(t) < 8:
        sys.exit("too few samples")
    n = max(3, len(v) // 10)
    v_start, v_end = float(np.mean(v[:n])), float(np.mean(v[-n:]))
    span = v_end - v_start
    if abs(span) < 1e-6:
        sys.exit("the value doesn't change")
    frac = (v - v_start) / span          # 0 at the start level, 1 at the settled one (rise or fall alike)
    onset = int(np.argmax(frac > 0.02))
    t0 = t[onset]
    i10, i90 = int(np.argmax(frac >= 0.1)), int(np.argmax(frac >= 0.9))
    t10, t90 = t[i10], t[i90]
    tt = t[onset:] - t0
    ff = frac[onset:]

    # A constant rate: the slope between 10 % and 90 %, clipped at the settled value.
    rate = 0.8 / max(t90 - t10, 1e-6)
    lin = np.clip(ff[0] + rate * tt, None, 1.0)
    # An exponential approach: ln(1 - frac) is a line of slope -1 / tau over the 5-90 % part.
    sel = (ff > 0.05) & (ff < 0.9)
    tau = float("nan")
    if sel.sum() >= 3:
        k = np.polyfit(tt[sel], np.log(1 - ff[sel]), 1)[0]
        tau = -1.0 / k if k < 0 else float("nan")
    expo = 1 - np.exp(-tt / tau) if tau == tau else np.full_like(tt, np.nan)
    # An eased start and end (smoothstep over the full time): rises slowly, then steeply, then settles.
    t100 = (t90 - t10) / 0.8 * 1.0
    ss = np.clip(tt / max(t100 * 1.25, 1e-6), 0, 1)
    smoothstep = ss * ss * (3 - 2 * ss)

    def rms(model):
        return float(np.sqrt(np.nanmean((model - ff) ** 2)))

    fits = {"constant rate": rms(lin), "exponential": rms(expo), "smoothstep": rms(smoothstep)}
    best = min(fits, key=lambda k: fits[k] if fits[k] == fits[k] else 9e9)
    print(json.dumps({
        "column": a.column,
        "start_value": round(v_start, 3), "settled_value": round(v_end, 3),
        "onset_s": round(float(t0), 3), "t10_90_s": round(float(t90 - t10), 3),
        "rate_per_s": round(span * rate, 3), "tau_s": round(tau, 3) if tau == tau else None,
        "rms_by_shape": {k: round(x, 4) for k, x in fits.items()}, "best_shape": best,
    }, indent=1))


# ---- output ---------------------------------------------------------------------------------------------------------

def write_csv(path, header, rows):
    f = open(path, "w", newline="") if path else sys.stdout
    w = csv.writer(f)
    w.writerow(header)
    w.writerows(rows)
    if path:
        f.close()


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)

    s = sub.add_parser("probe")
    s.add_argument("video")
    s.add_argument("--at", type=float, nargs="*")
    s.add_argument("--out", default="es2_frames")
    s.set_defaults(fn=cmd_probe)

    s = sub.add_parser("speed")
    s.add_argument("video")
    s.add_argument("--crop", required=True, help="X,Y,W,H of the speed readout in source pixels")
    s.add_argument("--start", type=float)
    s.add_argument("--end", type=float)
    s.add_argument("--step", type=int, default=1)
    s.add_argument("--max-jump", type=float, default=60.0, help="largest believable change between read frames")
    s.add_argument("--invert", action="store_true", help="dark digits on a light background")
    s.add_argument("--csv")
    s.set_defaults(fn=cmd_speed)

    s = sub.add_parser("rate")
    s.add_argument("video")
    s.add_argument("--hfov", type=float, required=True, help="horizontal field of view, degrees")
    s.add_argument("--mask", action="append", help="X,Y,W,H in source pixels to ignore (HUD, ship); repeatable")
    s.add_argument("--hud", action="store_true", help="a fixed HUD / ship over the view: ignore the no-motion peak")
    s.add_argument("--static", action="store_true", help="take away each pixel's median over the clip (a still overlay)")
    s.add_argument("--start", type=float)
    s.add_argument("--end", type=float)
    s.add_argument("--step", type=int, default=1)
    s.add_argument("--csv")
    s.set_defaults(fn=cmd_rate)

    s = sub.add_parser("zoom")
    s.add_argument("video")
    s.add_argument("--mask", action="append", help="X,Y,W,H in source pixels to ignore (HUD, ship); repeatable")
    s.add_argument("--hud", action="store_true", help="a fixed HUD / ship over the view: ignore the no-motion peak")
    s.add_argument("--static", action="store_true", help="take away each pixel's median over the clip (a still HUD)")
    s.add_argument("--top", type=float, help="the speed on the plateau (e.g. the known top speed), for distance / speed")
    s.add_argument("--plateau", default="0,0", help="S0,S1: the seconds of the clip at that top speed")
    s.add_argument("--start", type=float)
    s.add_argument("--end", type=float)
    s.add_argument("--csv")
    s.set_defaults(fn=cmd_zoom)

    s = sub.add_parser("bar")
    s.add_argument("video")
    s.add_argument("--crop", required=True, help="X,Y,W,H of the bar in source pixels")
    s.add_argument("--vertical", action="store_true", help="a bar that fills upward")
    s.add_argument("--threshold", type=float, help="brightness of a lit part (default: Otsu on the first frame)")
    s.add_argument("--start", type=float)
    s.add_argument("--end", type=float)
    s.add_argument("--csv")
    s.set_defaults(fn=cmd_bar)

    s = sub.add_parser("total")
    s.add_argument("csv")
    s.add_argument("--column", required=True)
    s.add_argument("--start", type=float)
    s.add_argument("--end", type=float)
    s.set_defaults(fn=cmd_total)

    s = sub.add_parser("fit")
    s.add_argument("csv")
    s.add_argument("--column", default="speed")
    s.add_argument("--abs", action="store_true", help="fit the magnitude (turns in either direction)")
    s.add_argument("--start", type=float, help="only from this time (s): one part of a clip, e.g. the drain")
    s.add_argument("--end", type=float)
    s.set_defaults(fn=cmd_fit)

    a = p.parse_args()
    a.fn(a)


if __name__ == "__main__":
    main()
