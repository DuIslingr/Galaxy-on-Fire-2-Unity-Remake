# Star map / inter-system travel research helper (see Reference/research/starmap_travel.md).
#   python Reference/tools/starmap/starmap_tables.py                 -> image rects, galaxy positions, routes,
#                                                                       jump distances, system-map layouts
#   python Reference/tools/starmap/starmap_tables.py crops DIR       -> also cuts every 2D image into DIR
#   python Reference/tools/starmap/starmap_tables.py path A B        -> gate path / energy cells from system A to B
#   python Reference/tools/starmap/starmap_tables.py sysmap S        -> system-map planet layout of system S
# Everything is decoded from libgof2hdaa.so (addresses in the .md). Game units unless noted.
import sys, os, glob, json
here = os.path.dirname(os.path.abspath(__file__))
root = os.path.join(here, '..', '..', '..')
sys.path.insert(0, os.path.join(here, '..', 'shop'))
import atlas  # noqa: E402

D = os.path.join(root, 'Assets', 'Resources', 'GoF2Data')
SYSTEMS = json.load(open(os.path.join(D, 'systems.json'), encoding='utf-8'))
STATIONS = {s['index']: s for s in json.load(open(os.path.join(D, 'stations.json'), encoding='utf-8'))}
TEXT = json.load(open(os.path.join(root, 'Assets', 'Localization', 'text_en.json'), encoding='utf-8'))

IMAGES = [
    (0x48a, 'system / planet ring, not selected (99x99, centred on the object)'),
    (0x48c, 'system / planet ring, selected (143x143, centred)'),
    (0x4fd, 'pulsing "you are here" marker (99x99, centred on the current system / station)'),
    (0x4a2, 'icon slot 0: "Already visited" (all stations / this station visited)'),
    (0x454, 'icon slot 1: story (campaign) mission target'),
    (0x455, 'icon slot 2: freelance mission target'),
    (0x453, 'icon slot 3: jumpgate station (system view only)'),
    (0x452, 'icon slot 4: products finished (pending production at a station)'),
    (0x545, 'extra icon next to Shima (system 26) when Status+0x114 == 3 (supernova DLC state)'),
    (0x4a1, 'race icon 36x36 Terran (galaxy label)'), (0x49c, 'race icon Vossk'),
    (0x49f, 'race icon Nivelian'), (0x49e, 'race icon Midorian'),
    (0x4a6, 'big race logo Terran (system-view header, orbit info)'), (0x4a3, 'big race logo Vossk'),
    (0x4a5, 'big race logo Nivelian'), (0x4a4, 'big race logo Midorian'),
]

# ---- galaxy view (StarMap::StarMap 0xd6880) ------------------------------------------------------------
def sun_position(s):
    """world position of the system's sun sprite (plane mesh 18070 + textureIndex, scale 0.012)."""
    p = s['mapPosition']
    x = int((100 - p['x']) / 100.0 * 14000.0) - 10000
    y = int((100 - p['y']) / 100.0 * 13000.0) - 9000
    z = int((100 - p['z']) / 100.0 * 6000.0) + 1000
    return (x, y, z)

# ---- gate routes (SystemPathFinder 0x14062e.., BFS, edges only into visible systems) -------------------
def gate_path(a, b, visible):
    if a == b:
        return None                      # getSystemPath returns null for a == b (0 nodes)
    prev = {a: None}; q = [a]
    while q:
        n = q.pop(0)
        if n == b:
            path = [b]
            while prev[path[-1]] is not None:
                path.append(prev[path[-1]])
            return path[::-1]
        for m in SYSTEMS[n]['jumpRoutesTo']:
            if visible[m] and m not in prev:
                prev[m] = n; q.append(m)
    return None

def energy_cells(a, b, visible, hardcore=False):
    """StarMap::OnTouchBegin: cells = gate jumps on the path, 4 if unreachable (and the target has
    no gate: 'noGate' flag -> warning 581 when cells < 2 * needed); x2 in hardcore mode."""
    p = gate_path(a, b, visible)
    n = len(p) - 1 if p else 0
    no_gate = False
    if n == 0 and a != b:
        n = 4
        no_gate = not SYSTEMS[b]['jumpRoutesTo']
    if hardcore:
        n *= 2
    return n, no_gate

# ---- system view (StarMap::initStarSystem 0xd7810) ------------------------------------------------------
MASK = (1 << 48) - 1
class JavaRandom:
    def __init__(s, seed): s.s = (seed ^ 0x5DEECE66D) & MASK
    def next(s, b):
        s.s = (s.s * 0x5DEECE66D + 0xB) & MASK; r = s.s >> (48 - b)
        return r - (1 << 32) if r >= (1 << 31) else r
    def nextInt(s, n):
        if n & -n == n: return (n * s.next(31)) >> 31
        while True:
            bits = s.next(31); val = bits % n
            if bits - val + (n - 1) < (1 << 31): return val

PLANET_SCALE = [320, 192, 256, 256, 192, 256, 192, 192, 320, 256, 192, 192, 320, 256, 320, 256, 256, 256, 320,
                192, 320, 256, 256, 0, 256, 256, 192, 256]          # DAT_00254484, x16/65536
RING_TEX = {9, 16, 21}                                              # bitmask 0x210200
RING_STATIONS = {120, 126, 130, 132}                                # Status::orbitHasPlanetRing

def system_map(sys_idx):
    s = SYSTEMS[sys_idx]; sts = s['stations']; n = len(sts)
    rnd = JavaRandom(sys_idx * 1000)
    used = [False] * (n + 1); out = []; prev_r = None
    for k, st in enumerate(sts):
        while True:
            slot = rnd.nextInt(n + 1)
            if not used[slot]: break
        used[slot] = True
        angle = slot * (65536 // (n + 1))                           # 1/65536 turn
        base = 6400 if prev_r is None else prev_r
        r = base + rnd.nextInt(5600) + 1600
        prev_r = r
        tex = STATIONS[st]['textureIndex']
        out.append(dict(station=st, name=STATIONS[st]['name'], slot=slot, angle=angle, radius=r,
                        mesh=18180 + tex, scale=PLANET_SCALE[tex] * 16 / 65536.0,
                        ring=(tex in RING_TEX) or (st in RING_STATIONS),
                        gate=(st == s['jumpgateStation'])))
    for o in out:                                                     # orbit loop runs after all planets
        o['orbitRotY'] = rnd.nextInt(3141) / 1000.0
        o['orbitScale'] = 2 * o['radius'] / 65536.0
    return out

def main():
    for i, what in IMAGES:
        print('0x%x %-55s %s' % (i, str(atlas.rect(i)), what))
    print()
    vis0 = [bool(s['initiallyVisible']) for s in SYSTEMS]
    print('idx name              sun position (x, y, z)      vis gate routes')
    for s in SYSTEMS:
        print('%2d  %-16s %-26s %-3s %4s %s' % (s['index'], s['name'], sun_position(s), 'yes' if s['initiallyVisible'] else '-',
                                              s['jumpgateStation'], s['jumpRoutesTo']))
    print()
    allvis = [True] * len(SYSTEMS)
    print('energy cells from Mido (15) / Augmenta (19), all systems visible:')
    for b in range(len(SYSTEMS)):
        print('  ->%2d %-14s %s %s' % (b, SYSTEMS[b]['name'], energy_cells(15, b, allvis), energy_cells(19, b, allvis)))
    if len(sys.argv) > 2 and sys.argv[1] == 'crops':
        from PIL import Image
        out = sys.argv[2]; os.makedirs(out, exist_ok=True)
        troot = os.path.join(root, 'Assets', 'Textures'); cache = {}
        for i, _ in IMAGES:
            png, r = atlas.rect(i)
            p = glob.glob(os.path.join(troot, '**', png), recursive=True)[0]
            if p not in cache:
                cache[p] = Image.open(p).convert('RGBA')
            im = cache[p].crop((r[0], r[1], r[0] + r[2], r[1] + r[3]))
            bg = Image.new('RGBA', im.size, (40, 40, 60, 255)); bg.alpha_composite(im)
            bg.save(os.path.join(out, '%x.png' % i))

if __name__ == '__main__':
    if len(sys.argv) > 3 and sys.argv[1] == 'path':
        a, b = int(sys.argv[2]), int(sys.argv[3]); vis = [True] * len(SYSTEMS)
        print(gate_path(a, b, vis), energy_cells(a, b, vis))
    elif len(sys.argv) > 2 and sys.argv[1] == 'sysmap':
        for o in system_map(int(sys.argv[2])):
            print(o)
    else:
        main()
