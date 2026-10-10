#!/usr/bin/env python3
"""Reads EVERSPACE 2's cockpit speed gauge (km/h) in every frame of a dashboard recording at the game's 4K resolution
(x11grab of the game window with crop=640:400:1600:1500, the cockpit camera view): finds the gauge ring by cross-correlating
edge maps with a template from the first frame (the cockpit sways), OCRs the digits at its centre.

  gauge_speed.py dash.mkv out.csv      -> t, kmh, cx, cy

A dropped digit now and then ("17" for 172) is left in; drop readings that don't fit their neighbours."""
import sys, csv, numpy as np
from collections import Counter
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import es2measure as m
video, out = sys.argv[1], sys.argv[2]
W, H = 640, 400
frames = list(m.frames(video, "", W, H))
def edges(f):
    f = f.astype(np.float32)
    gx = np.zeros_like(f); gy = np.zeros_like(f)
    gx[:, 1:] = np.abs(np.diff(f, axis=1)); gy[1:, :] = np.abs(np.diff(f, axis=0))
    return gx + gy
# The ring in the first frame: the gauge digits sit at about (190, 200) of this crop (run 6's layout).
CX, CY, TW, TH = 190, 200, 150, 140
t0 = edges(frames[0][1])
tpl = t0[CY - TH // 2:CY + TH // 2, CX - TW // 2:CX + TW // 2]
tpl = tpl - tpl.mean()
pad = np.zeros((H, W), np.float32); pad[:TH, :TW] = tpl
Ft = np.conj(np.fft.fft2(pad))
rows = []
for t, img in frames:
    e = edges(img); e = e - e.mean()
    c = np.fft.ifft2(np.fft.fft2(e) * Ft).real
    y, x = np.unravel_index(np.argmax(c), c.shape)      # top-left of the best match
    cx, cy = x + TW // 2, y + TH // 2
    # The digits only (+-25 x +-11 px, a little right of / above the ring's centre): a wider crop takes in the gauge's
    # inner ring once there are four digits and reads it as extra 1s. The most common reading of nine small offsets.
    votes = Counter()
    for dx in (-3, 0, 3):
        for dy in (-2, 0, 2):
            crop = img[cy - 2 + dy - 11:cy - 2 + dy + 11, cx + 4 + dx - 25:cx + 4 + dx + 25]
            if crop.shape != (22, 50): continue
            v = m.ocr_number(crop, False)
            if v is not None and v == int(v): votes[int(v)] += 1
    v = votes.most_common(1)[0][0] if votes else None
    rows.append((round(t, 4), v, cx, cy))
with open(out, "w", newline="") as f:
    w = csv.writer(f); w.writerow(["t", "kmh", "cx", "cy"]); w.writerows(rows)
print(sum(1 for r in rows if r[1] is not None), "/", len(rows), "read")
