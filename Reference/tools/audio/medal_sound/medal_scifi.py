# Sci-fi variants of the station chime (C): stereo, pure Python.
import math, random, struct, sys, wave
sys.path.insert(0, __file__.rsplit('\\', 1)[0] if '\\' in __file__ else __file__.rsplit('/', 1)[0])
from medal_synth import SR, note, reverb

def zeros(sec): return [0.0] * int(SR * sec)

def mix_into(buf, start, samples, gain=1.0):
    i0 = int(start * SR)
    for i, s in enumerate(samples):
        if 0 <= i0 + i < len(buf): buf[i0 + i] += s * gain

def glide_chime(freq, dur, decay=2.0, glide=0.06, glide_ms=60, metallic=0.0):
    """The chime with each note sliding up into pitch; 'metallic' adds an inharmonic FM partial (ratio 2.76)."""
    out, ph1, ph2, ph3 = [], 0.0, 0.0, 0.0
    for i in range(int(SR * dur)):
        t = i / SR
        f = freq * (1 - glide * math.exp(-t * 1000 / glide_ms))
        ph1 += 2 * math.pi * f / SR
        ph2 += 2 * math.pi * f * 1.004 / SR
        ph3 += 2 * math.pi * f * 2.76 / SR
        env = math.exp(-decay * t) * min(1.0, t / 0.006)
        mod = metallic * math.exp(-4 * t) * math.sin(ph3)
        s = 0.5 * (math.sin(ph1 + mod) + math.sin(ph2 + mod * 0.7))
        s += 0.22 * math.sin(2 * ph1) * math.exp(-3 * t)
        s += metallic * 0.18 * math.sin(ph3) * math.exp(-5 * t)
        out.append(env * s)
    return out

def whoosh(dur, f0=300, f1=4000, q=6.0, gain=0.25, seed=3):
    """Noise through a resonant band-pass sweeping up (state-variable filter), swelling in and out."""
    rng = random.Random(seed)
    out, low, band = [], 0.0, 0.0
    n = int(SR * dur)
    for i in range(n):
        p = i / n
        fc = f0 * (f1 / f0) ** p
        fq = 2 * math.sin(math.pi * min(fc, SR / 6) / SR)
        x = rng.uniform(-1, 1)
        low += fq * band
        high = x - low - band / q
        band += fq * high
        env = math.sin(math.pi * p) ** 2
        out.append(band * env * gain)
    return out

def sub_pulse(dur=0.6, f=55):
    out = []
    for i in range(int(SR * dur)):
        t = i / SR
        ff = f * (1 + 1.5 * math.exp(-t * 25))   # a quick downward drop: the "thrum"
        out.append(math.sin(2 * math.pi * ff * t) * math.exp(-5 * t) * min(1, t / 0.004))
    return out

def blips(count=6, start_hz=1800, step=1.12, spacing=0.045, seed=7):
    rng = random.Random(seed)
    out = zeros(count * spacing + 0.1)
    for k in range(count):
        f = start_hz * step ** k * (1 + rng.uniform(-0.01, 0.01))
        i0 = int(k * spacing * SR)
        for j in range(int(SR * 0.03)):
            t = j / SR
            sq = 1.0 if math.sin(2 * math.pi * f * t) > 0 else -1.0
            out[i0 + j] += 0.12 * sq * math.exp(-90 * t)
    return out

def flanger(buf, depth_ms=2.5, rate=0.35, mix=0.5):
    out = list(buf)
    for i in range(len(buf)):
        d = (depth_ms / 1000 * SR) * (0.5 + 0.5 * math.sin(2 * math.pi * rate * i / SR))
        j = i - d
        j0 = int(j)
        if j0 >= 0:
            frac = j - j0
            s = buf[j0] * (1 - frac) + (buf[j0 + 1] if j0 + 1 < len(buf) else 0) * frac
            out[i] = buf[i] * (1 - mix * 0.5) + s * mix * 0.5
    return out

def ping_pong(mono, delay=0.16, feedback=0.45, wet=0.35, taps=5):
    """Digital echoes alternating left / right."""
    n = len(mono) + int(SR * delay * taps)
    L, R = zeros(n / SR), zeros(n / SR)
    for i, s in enumerate(mono): L[i] += s; R[i] += s
    g = wet
    for k in range(1, taps + 1):
        off = int(SR * delay * k)
        tgt = L if k % 2 else R
        for i, s in enumerate(mono):
            if i + off < n: tgt[i + off] += s * g
        g *= feedback
    return L, R

def write_stereo(path, L, R, peak=0.8):
    m = max(1e-9, max(max(abs(x) for x in L), max(abs(x) for x in R)))
    k = peak / m
    with wave.open(path, 'wb') as w:
        w.setnchannels(2); w.setsampwidth(2); w.setframerate(SR)
        fr = bytearray()
        for l, r in zip(L, R):
            fr += struct.pack('<hh', int(max(-1, min(1, l * k)) * 32767), int(max(-1, min(1, r * k)) * 32767))
        w.writeframes(bytes(fr))

def chord(notes, gap, tail, **kw):
    buf = zeros(gap * len(notes) + tail)
    for i, n in enumerate(notes):
        mix_into(buf, i * gap, glide_chime(note(n), tail, **kw), 0.55)
    return buf

NOTES = ['C5', 'E5', 'G5', 'C6']

def c1():
    buf = chord(NOTES, 0.14, 2.0)
    buf = reverb(buf, 0.3, 0.85)
    return ping_pong(buf, 0.16, 0.45, 0.3)

def c2():
    buf = chord(NOTES, 0.14, 2.0, metallic=0.9)
    mix_into(buf, 0.0, whoosh(0.9), 1.0)
    buf = flanger(buf)
    buf = reverb(buf, 0.32, 0.85)
    return ping_pong(buf, 0.18, 0.35, 0.2, 3)

def c3():
    buf = chord(NOTES, 0.14, 2.0, metallic=0.9)
    mix_into(buf, 0.0, whoosh(0.9), 1.0)
    mix_into(buf, 0.0, sub_pulse(), 0.5)
    mix_into(buf, 0.42, blips(), 1.0)
    buf = flanger(buf)
    buf = reverb(buf, 0.32, 0.85)
    return ping_pong(buf, 0.18, 0.35, 0.2, 3)

if __name__ == '__main__':
    out = sys.argv[1]
    for name, fn in (('medal_C1_glide_echo', c1), ('medal_C2_metal_whoosh', c2), ('medal_C3_full', c3)):
        L, R = fn()
        write_stereo(f'{out}/{name}.wav', L, R)
    print('ok')
