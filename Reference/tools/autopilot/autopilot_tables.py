# Autopilot / travel research helper (see Reference/research/autopilot_travel.md).
#   python Reference/tools/autopilot/autopilot_tables.py            -> image rects + distance-format samples
#   python Reference/tools/autopilot/autopilot_tables.py crops DIR  -> also cuts every image into DIR (PNG, on a dark bg)
import sys, os, glob
here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(here, '..', 'shop'))
import atlas  # noqa: E402

IMAGES = [
    (0x456, 'lock ring, 24 frames 80x80 (Radar+0xf4)'),
    (0x4c4, 'top target plate (Radar+0xcc)'),
    (0x4c7, 'quarter ellipse, drawn 4x mirrored around the screen centre; off-screen markers clamp to it'),
    (0x4f2, 'landmark bracket (station/jumpgate near the screen centre)'),
    (0x453, 'jumpgate icon (off-centre gate landmark; gate planet marker)'),
    (0x450, 'wormhole icon (off-centre)'),
    (0x454, 'campaign-mission target marker on a planet'),
    (0x455, 'freelance-mission target marker on a planet'),
    (0x4f0, 'route waypoint marker (on screen)'),
    (0x4ef, 'route waypoint arrow (off screen, scanner only)'),
    (0x536, 'arrow on the fire button (target locked, fire = action)'),
    (0x4b4, 'fire button'), (0x4b5, 'fire button pressed'),
    (0x4b0, 'autopilot button (off)'), (0x4b1, 'autopilot button (on / pressed)'),
    (0x53f, 'pill background behind fast-forward + autopilot buttons'),
    (0x541, 'fast-forward button'), (0x540, 'fast-forward button pressed'),
    (0x543, 'time-extender button (same slot, normal flight)'), (0x542, 'time-extender pressed'),
    (0x4f4, 'autopilot menu title icon'),
    (0x4a1, 'race icon frame 0 Terran'), (0x49c, 'race icon frame 1 Vossk'),
    (0x49f, 'race icon frame 2 Nivelian'), (0x49e, 'race icon frame 3 Midorian'),
    (0x4a0, 'race icon frame 8 (alien orbit, dlc1 won)'), (0x49d, 'race icon frame 9 (alien orbit)'),
]

def calc_distance(d):
    """Radar::calcDistance 0x15827c: d = distance in game units -> HUD string."""
    m = int(d / 128.0) * 8                      # sqrt(((d/2)^2)/4096)*8, truncated
    if m < 1000:
        return '%dm' % m
    frac = m % 1000
    digit = str(frac)[0] if frac >= 100 else '0'
    return '%d.%skm' % (m // 1000, digit)

if __name__ == '__main__':
    for i, what in IMAGES:
        print('0x%x %-40s %s' % (i, str(atlas.rect(i)), what))
    for d in (500, 10000, 15999, 16000, 20000, 80000, 100000, 1000000):
        print('distance %7d units -> %s' % (d, calc_distance(d)))
    if len(sys.argv) > 2 and sys.argv[1] == 'crops':
        from PIL import Image
        out = sys.argv[2]; os.makedirs(out, exist_ok=True)
        root = os.path.join(here, '..', '..', '..', 'Assets', 'Textures')
        cache = {}
        for i, _ in IMAGES:
            png, r = atlas.rect(i)
            p = glob.glob(os.path.join(root, '**', png), recursive=True)[0]
            if p not in cache:
                cache[p] = Image.open(p).convert('RGBA')
            im = cache[p].crop((r[0], r[1], r[0] + r[2], r[1] + r[3]))
            bg = Image.new('RGBA', im.size, (40, 40, 60, 255)); bg.alpha_composite(im)
            bg.save(os.path.join(out, '%x.png' % i))
