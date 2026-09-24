# Generic bar-agent portraits: coverage of ImageFactory::createChar(male, race) 0x14173c against the part textures.
#   python Reference/tools/lounge/agent_portraits.py                 per portrait set: counts, image ids, files, heights
#   python Reference/tools/lounge/agent_portraits.py --races         race/gender -> portrait set (createChar rules)
#   python Reference/tools/lounge/agent_portraits.py --sheet out.png every variant of every generic set (one row per
#                                                                    set and part, composed with variant 0 elsewhere)
#   python Reference/tools/lounge/agent_portraits.py --random N out.png   N random agents (createChar + compose)
# Output images go wherever you point them; keep them out of Assets/ (copyrighted game material).
#
# createChar(male, race): race 3 (Midorian) -> 1/4 set 0, 3/4 set 2; set 0 and not male -> 10; race 5 (Cyborg) -> 0;
# parts[1..4] = nextInt(COUNTS[set][k]). Portrait = the same composition as the story speakers
# (tools/dialogue/portrait.py compose(): bg 0x485, part2, part1, part0, part3, frame 0x511).
import sys, os, random
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', 'dialogue'))
sys.path.insert(0, os.path.join(HERE, '..', 'shop'))
import portrait as P
import atlas
from binary import ROOT

GENERIC_SETS = [0, 1, 2, 4, 6, 7, 10]          # what createChar can return for races 0..7
RACE = ['Terran', 'Vossk', 'Nivelian', 'Midorian', 'Multipod', 'Cyborg', 'Bobolian', 'Grey', 'Pirate', 'Void']


def create_char(male, race, rnd=random):
    """Python port of ImageFactory::createChar(bool male, int race) 0x14173c."""
    if race == 3:
        race = 0 if rnd.randrange(4) == 0 else 2
    s = race
    if race == 0 and not male:
        s = 10
    if s == 5:
        s = 0
    return [s] + [rnd.randrange(P.COUNTS[s][k]) if P.COUNTS[s][k] > 0 else 0 for k in range(4)]


def part_info(s, k, v):
    base = P.BASE_IDS[s][k]
    if base < 0:
        return None
    iid = base + v
    if iid not in atlas.IMAGES:
        return (iid, None, None, False)
    png, rect = P.part_png(iid, False)
    return (iid, os.path.basename(png), rect, os.path.exists(png))


def coverage():
    offs = P.offsets('large')
    for s in range(13):
        print('set %2d %-40s counts %s bases %s' % (s, P.BODY[s], P.COUNTS[s], P.BASE_IDS[s]))
        for k in range(4):
            n = P.COUNTS[s][k]
            if P.BASE_IDS[s][k] < 0:
                print('   part %d: unused (base -1)%s' % (k, '' if n <= 1 else '  (count %d)' % n))
                continue
            rows, missing = [], 0
            for v in range(max(n, 1)):
                r = part_info(s, k, v)
                if not r or not r[3]:
                    missing += 1
                rows.append('%d:%s%s' % (v, r[1] if r and r[1] else '?', '' if r and r[3] else '(MISSING)'))
            anchor, y = offs[s][k]
            print('   part %d: ids %d..%d, anchor %s y %d, %d variants, %d missing' % (
                k, P.BASE_IDS[s][k], P.BASE_IDS[s][k] + max(n, 1) - 1, 'bottom' if anchor & 32 else 'top', y,
                n, missing))
            print('      ' + ' '.join(rows))


def races():
    for r in range(8):
        for male in ((True, False) if r == 0 else (True,)):
            sets = {}
            for _ in range(4000):
                s = create_char(male, r)[0]
                sets[s] = sets.get(s, 0) + 1
            print('%-9s %-6s -> %s' % (RACE[r], 'male' if male else 'female',
                                       ', '.join('set %d %.0f%%' % (s, c / 40) for s, c in sorted(sets.items()))))


def sheet(out):
    from PIL import Image, ImageDraw
    rows = []
    for s in GENERIC_SETS:
        for k in range(4):
            n = P.COUNTS[s][k]
            if P.BASE_IDS[s][k] < 0 or n <= 0:
                continue
            tiles = []
            for v in range(n):
                d = [s, 0, 0, 0, 0]
                d[k + 1] = v
                tiles.append(P.compose(d))
            rows.append(('set %d part %d' % (s, k), tiles))
    w, h = 160, 200
    cols = max(len(t) for _, t in rows)
    im = Image.new('RGBA', (cols * w + 110, len(rows) * h), (40, 40, 40, 255))
    dr = ImageDraw.Draw(im)
    for i, (label, tiles) in enumerate(rows):
        dr.text((4, i * h + 4), label, fill='white')
        for j, t in enumerate(tiles):
            im.alpha_composite(t, (110 + j * w, i * h))
    im.save(out)


def random_sheet(n, out):
    from PIL import Image, ImageDraw
    rnd = random.Random(1)
    tiles = []
    for i in range(n):
        race = rnd.randrange(8)
        male = True if race != 0 else rnd.randrange(100) < 60
        d = create_char(male, race, rnd)
        tiles.append((RACE[race] + ('' if male else ' f'), d, P.compose(d)))
    cols = 8
    im = Image.new('RGBA', (cols * 160, ((n + cols - 1) // cols) * 214), (40, 40, 40, 255))
    dr = ImageDraw.Draw(im)
    for i, (label, d, t) in enumerate(tiles):
        x, y = (i % cols) * 160, (i // cols) * 214
        im.alpha_composite(t, (x, y))
        dr.text((x + 2, y + 200), '%s %s' % (label, d), fill='white')
    im.save(out)


if __name__ == '__main__':
    a = sys.argv[1:]
    if not a:
        coverage()
    elif a[0] == '--races':
        races()
    elif a[0] == '--sheet':
        sheet(a[1])
    elif a[0] == '--random':
        random_sheet(int(a[1]), a[2])
