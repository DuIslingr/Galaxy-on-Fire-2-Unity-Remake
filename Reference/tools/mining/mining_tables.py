# Mining minigame tables and derived numbers (see Reference/research/mining.md).
#   python Reference/tools/mining/mining_tables.py            -> tables, drills, perfect-run ore
#   python Reference/tools/mining/mining_tables.py crops DIR  -> also crop the minigame images (iPad-large atlas) into DIR
import json, os, sys, struct
here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(here, '..', 'shop'))
from rb import table                       # Ghidra-address table reader (image base 0x10000)
root = os.path.join(here, '..', '..', '..')

LAYER_SPEEDS = table(0x26ad2c, 7, 'f')     # symbol LAYER_SPEEDS
_d = table(0x26ad48, 49, 'i')              # symbol LAYER_DIAMETERS, row = 7 - quality
LAYER_DIAMETERS = [_d[r * 7:r * 7 + 7] for r in range(7)]

def f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]

def perfect_run(quality, yield_, dt=16):
    """Ore (float) after a run that never leaves the ring. MiningGame::update 0x143e28, dt in ms."""
    ore, layer, t = 0.0, 0, 0
    while True:
        ore = f32(ore + dt * f32(yield_ * f32((layer + 1) / 7.0 * 2.35 + 0.15)) / 1000.0)
        t += dt
        if t > 6000:
            t = 0
            layer += 1
            if layer >= quality:
                return ore

def main():
    print('LAYER_SPEEDS', LAYER_SPEEDS)
    print('FMOD param 0 of event 1 per layer', [round((s - 5) / 33 * 3, 3) for s in LAYER_SPEEDS])
    for q in (7, 6, 5, 4):
        row = LAYER_DIAMETERS[7 - q]
        print('quality %d (%s): diameters %s -> ring radius px (HD, x layout+0xe8=2 / 2) %s'
              % (q, 'ABCD'[7 - q], row[:q], row[:q]))
    items = json.load(open(os.path.join(root, 'Assets', 'Resources', 'GoF2Data', 'items.json'), encoding='utf-8'))
    print('\ndrill                steady(+0x2c) yield(+0x28)  perfect ore  D     C     B     A(+core)')
    for it in items:
        if it['categoryId'] != 19:
            continue
        a = it['rawAttributes']
        steady = int(a['32']) / 100 * 1.5 + 0.3
        y = int(a['33']) / 100
        ores = [int(perfect_run(q, y)) for q in (4, 5, 6, 7)]
        print('%3d %-18s %.2f          %.2f          ' % (it['index'], it['name'], steady, y)
              + '     '.join('%-2d' % o for o in ores))
    print('\nlock time (Radar+0x1b4, lock when timer > value-200): none 8000; scanners:',
          [(it['name'], int(it['rawAttributes']['29'])) for it in items if it['categoryId'] == 17])

def crops(out):
    import glob
    import atlas
    from PIL import Image
    os.makedirs(out, exist_ok=True)
    for i in list(range(0x4dd, 0x4ee)) + [0x522, 0x523, 0x536, 0x44e, 0x456, 0x4c4]:
        png, (x, y, w, h) = atlas.rect(i)
        p = glob.glob(os.path.join(root, 'Assets', 'Textures', '**', png), recursive=True)[0]
        Image.open(p).convert('RGBA').crop((x, y, x + w, y + h)).save(os.path.join(out, '%x.png' % i))
        print(hex(i), png, [x, y, w, h])

if __name__ == '__main__':
    main()
    if len(sys.argv) > 2 and sys.argv[1] == 'crops':
        crops(sys.argv[2])
