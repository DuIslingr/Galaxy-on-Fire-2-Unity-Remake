#!/usr/bin/env python3
"""Reads EVERSPACE 2's target label distance ("813m", shown when the crosshair is on a station) in every frame of a
1920 x 1080 recording: finds the label's thin white left bar near the centre, OCRs the line under the name.

  label_distance.py clip.mkv out.csv      -> t, speed (= the distance read, m), bar_x, bar_y

The distance only reads in metres under 1 km. Misreads (a dropped digit, 6 read as 8, the "m" as a 1) are left in; the
analysis keeps the readings on a smooth path (es2_flight_measurements.md, "Forward acceleration")."""
import sys, csv, subprocess, numpy as np
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import es2measure as m
video, out = sys.argv[1], sys.argv[2]
X0, Y0, W, H = 700, 300, 1000, 480            # search area (1920 x 1080 source): around the crosshair
def find_bar(g):
    # A label's left edge: a bright, thin vertical line ~55 px tall with darker pixels either side.
    bright = g > 200
    best = None
    for x in range(2, W - 60):
        col = bright[:, x]
        if col.sum() < 40: continue
        # the longest run of bright pixels in this column
        run, best_run, end = 0, 0, 0
        for y, b in enumerate(col):
            run = run + 1 if b else 0
            if run > best_run: best_run, end = run, y
        if best_run < 45 or best_run > 75: continue
        y0 = end - best_run + 1
        side = (g[y0:end, x - 2].mean() + g[y0:end, x + 3].mean()) / 2
        if side > 150: continue                   # not a thin line
        if best is None or best_run > best[2]: best = (x, y0, best_run)
    return best
rows = []
for t, img in m.frames(video, f"crop={W}:{H}:{X0}:{Y0}", W, H):
    g = img.astype(np.int16)
    bar = find_bar(g)
    v = None
    if bar:
        x, y0, n = bar
        crop = img[y0 + 31:y0 + 53, x + 6:x + 60]   # the distance line, the "m" cut off by the whitelist
        if crop.size: v = m.ocr_number(crop, False)
    rows.append((round(t, 4), v, bar[0] + X0 if bar else "", bar[1] + Y0 if bar else ""))
with open(out, "w", newline="") as f:
    w = csv.writer(f); w.writerow(["t", "speed", "bar_x", "bar_y"]); w.writerows(rows)
print(sum(1 for r in rows if r[1] is not None), "/", len(rows), "read")
