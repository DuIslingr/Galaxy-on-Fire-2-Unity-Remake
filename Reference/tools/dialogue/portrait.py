# Compose GoF2 character portraits exactly like ImageFactory::loadChar (0x1417bc) + drawChar (0x1419a0).
#   python Reference/tools/dialogue/portrait.py --table                 list the 63 story speakers
#   python Reference/tools/dialogue/portrait.py --speaker 8 out.png     compose story speaker 8 (Jean Baffour)
#   python Reference/tools/dialogue/portrait.py --parts 0 6 8 8 7 out.png   compose {race, p0, p1, p2, p3}
#   python Reference/tools/dialogue/portrait.py --sheet out.png         all story speakers on one sheet
#   add --lowres for the 60x75 phone parts instead of the Android-HD 160x200 (_ipad_large) ones
#   add --flip to mirror (DialogueWindow does this for speaker 0, Keith, when the portrait flag is set)
# Output goes wherever you point it; keep it out of Assets/ (the images are copyrighted game material).
#
# Data (Ghidra addresses):
#   char descriptor int[5] = {bodyType, part0, part1, part2, part3} (variant index per part, -1 = none)
#   0x2583f0 int[13][4]  first Image2D id of each (bodyType, part)  -> image id = base + variant; -1 = part unused
#   0x258320 int[13][4]  number of variants (used by ImageFactory::createChar 0x14173c for random agents)
#   IMAGE_OFFSETS_IPAD_LARGE 0x26a84c int[13][4][2] = {anchor, y}: anchor 16 = top, 32 = bottom (J2ME style),
#       x is always the portrait's left edge (drawn with anchor|1 -> left). Other tables: IMAGE_OFFSETS 0x26ab8c
#       (phone 60x75), _IPAD 0x26a9ec (100x125), _IPAD_HD 0x26a6ac (retina copy source 0x258180 = 1440 variant)
#   story speakers: PTR 0x2647ec[63] -> descriptor; speaker 0 (Keith) points at an all-zero .bss array
#       (0x26d3bc) = {0,0,0,0,0}
#   background image 0x485 (1157), frame 0x511 (1297); gof2_interface2_ipad_large.png [1459,955,160,200] /
#       [1879,249,160,200] on Android HD.
# Draw order: background, part2, part1, part0, part3, frame (loadChar swaps array slots 0 and 2).
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from binary import ints, ptr, text, ROOT, REF
BASE_IDS = [ints(0x2583f0 + 16 * r, 4) for r in range(13)]
COUNTS = [ints(0x258320 + 16 * r, 4) for r in range(13)]
OFFS = {'large': 0x26a84c, 'phone': 0x26ab8c, 'ipad': 0x26a9ec, 'ipad_hd': 0x26a6ac}
BODY = {0: 'Terran male', 1: 'Vossk', 2: 'Nivelian', 3: '(Midorian: never drawn, createChar maps to 0/2)',
        4: 'Multipod', 5: '(maps to 0)', 6: 'Bobolian', 7: 'Grey', 8: '(unused)', 9: 'Void', 10: 'Terran female',
        11: 'computer screen', 12: 'robot (Corny)'}
def offsets(kind='large'):
    a = OFFS[kind]
    return [[tuple(ints(a + 32 * r + 8 * k, 2)) for k in range(4)] for r in range(13)]
def speaker(i):
    if i == 0:
        return [0, 0, 0, 0, 0]
    p = ptr(0x2647ec + 4 * i)
    return ints(p, 5)
def part_png(image_id, lowres):
    sys.path.insert(0, os.path.join(REF, 'tools', 'shop'))
    import atlas
    tid, reg = atlas.IMAGES[image_id]
    png = atlas._tex[tid]
    if not lowres:
        png = png[:-4] + '_ipad_large.png'
    return os.path.join(ROOT, 'Assets', 'Textures', 'textures', png), atlas._man[png]['regions'][0]
def compose(desc, lowres=False, flip=False):
    from PIL import Image
    sys.path.insert(0, os.path.join(REF, 'tools', 'shop'))
    import atlas
    W, H = (60, 75) if lowres else (160, 200)
    offs = offsets('phone' if lowres else 'large')
    out = Image.new('RGBA', (W, H), (0, 0, 0, 0))
    def blit(png, rect, y, anchor):
        im = Image.open(png).convert('RGBA').crop((rect[0], rect[1], rect[0] + rect[2], rect[1] + rect[3]))
        if flip:
            im = im.transpose(Image.FLIP_LEFT_RIGHT)
        top = y - rect[3] if anchor & 32 else y
        out.alpha_composite(im, (0, top))
    bg = atlas.rect(0x485, not lowres); fr = atlas.rect(0x511, not lowres)
    tex = os.path.join(ROOT, 'Assets', 'Textures', 'textures')
    blit(os.path.join(tex, bg[0]), bg[1], 0, 16)
    body = desc[0]
    for k in (2, 1, 0, 3):
        v = desc[k + 1]
        if v == -1 or BASE_IDS[body][k] < 0:
            continue
        png, rect = part_png(BASE_IDS[body][k] + v, lowres)
        anchor, y = offs[body][k]
        blit(png, rect, y, anchor)
    blit(os.path.join(tex, fr[0]), fr[1], 0, 16)
    return out
def main(a):
    lowres = '--lowres' in a; flip = '--flip' in a
    a = [x for x in a if x not in ('--lowres', '--flip')]
    if a[0] == '--table':
        for i in range(63):
            d = speaker(i)
            print('%2d  %-22s body %2d %-14s parts %s' % (i, text(1597 + i), d[0], BODY[d[0]], d[1:]))
    elif a[0] == '--speaker':
        compose(speaker(int(a[1])), lowres, flip).save(a[2])
    elif a[0] == '--parts':
        compose([int(x) for x in a[1:6]], lowres, flip).save(a[6])
    elif a[0] == '--sheet':
        from PIL import Image, ImageDraw
        tiles = [compose(speaker(i), lowres) for i in range(63)]
        w, h = tiles[0].size; cols = 9
        sheet = Image.new('RGBA', (cols * w, ((63 + cols - 1) // cols) * (h + 14)), (40, 40, 40, 255))
        dr = ImageDraw.Draw(sheet)
        for i, t in enumerate(tiles):
            x, y = (i % cols) * w, (i // cols) * (h + 14)
            sheet.alpha_composite(t, (x, y)); dr.text((x + 2, y + h), '%d %s' % (i, text(1597 + i)), fill='white')
        sheet.save(a[1])
if __name__ == '__main__':
    main(sys.argv[1:])
