# Wingmen and Most Wanted research helper (see Reference/research/wingmen_wanted.md). PRIVATE: reads game data.
#   python Reference/tools/wingmen/wingmen_wanted.py wingman "Name Surname" RACE   ship a hired wingman flies (seeded)
#   python Reference/tools/wingmen/wingmen_wanted.py formation                     spawn + formation offsets
#   python Reference/tools/wingmen/wingmen_wanted.py wanted [LEVEL] [extreme]      wanted table: HP, guns, jump bounds
#   python Reference/tools/wingmen/wingmen_wanted.py simulate IDX [STEPS] [SEED]   activateNewWanted + moveWanted walk
#   python Reference/tools/wingmen/wingmen_wanted.py medals                        medal thresholds (DAT_00259860)
#   python Reference/tools/wingmen/wingmen_wanted.py texts                         the text ids used by both systems
# Functions mirror the original names; addresses are Ghidra addresses (image base 0x10000). Game units, ms.
import json, os, random, sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.join(HERE, '..', '..', '..')
DATA = os.path.join(ROOT, 'Assets', 'Resources', 'GoF2Data')
def load(name):
    return json.load(open(os.path.join(DATA, name), encoding='utf-8'))
TEXT = json.load(open(os.path.join(ROOT, 'Assets', 'Localization', 'text_en.json'), encoding='utf-8'))
SYSTEMS = load('systems.json')
STATIONS = {s['index']: s for s in load('stations.json')}
WANTED = load('wanted.json')

# ---- java.util.Random (AbyssEngine::AERandom 0x7ad04..) --------------------------------------------------------
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

# DAT_00254990: race of ship index (only 0..36 are rolled)
SHIP_RACE = [3, 0, 8, 3, 2, 0, 3, 0, 9, 1, 0, 8, 2, 0, 0, 0, 2, 0, 2, 3, 3, 2, 0, 8, 8, 8, 0, 0, 0, 8, 3, 2,
             8, 0, 0, 2, 0, 0, 0, 1, 0, 1, 1, 2, 1, 3, 3, 3, 3, 1, 1, 0, 8, 1, 1, 0, 3, 2, 0, 0]
RACE = ['Terran', 'Vossk', 'Nivelian', 'Midorian', 'Multipod', 'Cyborg', 'Bobolian', 'Grey', 'Pirate', 'Void', '???']

def ship_name(i): return TEXT[913 + i]
def item_name(i): return TEXT[1274 + i]
def station_label(i):
    s = STATIONS[i]; return f"{s['name']} ({SYSTEMS[s['system']]['name'].strip()})"

def get_random_enemy_fighter(race, rnd, dlc1_won=False):
    """Globals::getRandomEnemyFighter 0xf9034 with an explicit RNG."""
    r = race if race < 4 else (race if race in (9, 10) else 8)
    if r == 1:
        if not dlc1_won: return 9
        x = rnd.nextInt(100); return 9 if x < 60 else 41 if x < 85 else 39
    if r == 9: return 8
    if r == 10: return 44
    while True:
        u = rnd.nextInt(37)
        if ((u & ~4) - 9) & 0xffffffff < 2: continue
        if (u < 16 and (0x8101 >> u) & 1) or SHIP_RACE[u] != r: continue
        return u

def wingman_ship(name, race):
    """Level::createWingmen 0xcb338: AERandom::setSeed(5 * name.length) right before getRandomEnemyFighter(race), so
    a wingman's ship depends only on the length of its name (UTF-16 units) and the hired race."""
    return get_random_enemy_fighter(race, JavaRandom(5 * len(name)))

# ---- wanted -------------------------------------------------------------------------------------------------
EXCLUDED_SYSTEMS = {6, 25, 26, 27, 28}          # Wolf-Reiser, Loma, Shima, Ginoya, Talidor
def jump_bounds(i):
    """activateNewWanted / moveWanted: allowed getSystemPath node counts (start and end included) = jumps + 1."""
    if i < 2: return 2, 4
    k = (i - 1) % 6
    return k // 3 + 2, k // 2 + 4

def gate_path(a, b, visible):
    """SystemPathFinder::getSystemPath 0x14065c (BFS, edges only into visible systems); None for a == b."""
    if a == b: return None
    prev = {a: None}; q = [a]
    while q:
        n = q.pop(0)
        if n == b:
            p = [b]
            while prev[p[-1]] is not None: p.append(prev[p[-1]])
            return p[::-1]
        for m in SYSTEMS[n]['jumpRoutesTo']:
            if visible[m] and m not in prev:
                prev[m] = n; q.append(m)
    return None

def valid_station(st, visible):
    sy = STATIONS[st]['system']
    return bool(SYSTEMS[sy]['jumpRoutesTo']) and visible[sy] and sy not in EXCLUDED_SYSTEMS

def activate(i, rnd, visible):
    """Status::activateNewWanted 0xba2ac, the part after the board / mission / bounty checks."""
    lo, hi = jump_bounds(i)
    while True:
        s1 = rnd.randrange(135)
        while not valid_station(s1, visible): s1 = rnd.randrange(135)
        s2 = rnd.randrange(135)
        while not (valid_station(s2, visible) and STATIONS[s2]['system'] != STATIONS[s1]['system']):
            s2 = rnd.randrange(135)
        p = gate_path(STATIONS[s1]['system'], STATIONS[s2]['system'], visible)
        if p and lo <= len(p) <= hi: break
    sysx = p[rnd.randrange(len(p))]
    cur = SYSTEMS[sysx]['stations'][rnd.randrange(len(SYSTEMS[sysx]['stations']))]
    return dict(lastSeen=s1, travelsTo=s2, current=cur)

def move(i, w, rnd, visible, player_station=-1, programmed=-1):
    """Status::moveWanted 0xb6858, one orbit change (player_station = the orbit being entered)."""
    cur = w['current']
    if cur == player_station or cur == programmed: return 'waits'
    sc, sd = STATIONS[cur]['system'], STATIONS[w['travelsTo']]['system']
    if cur == w['travelsTo']:
        lo, hi = jump_bounds(i)
        w['lastSeen'] = cur
        while True:
            s = rnd.randrange(135); sy = STATIONS[s]['system']
            p = gate_path(sc, sy, visible)
            if p and SYSTEMS[sy]['jumpRoutesTo'] and lo <= len(p) <= hi and visible[sy] \
                    and sy not in EXCLUDED_SYSTEMS and sy != sc: break
        w['travelsTo'] = s
        return 'arrived, new destination'
    if sc == sd:
        w['current'] = w['travelsTo']; return 'to its destination station'
    p = gate_path(sc, sd, visible)
    w['current'] = SYSTEMS[p[1]]['jumpgateStation']
    return f"to the gate station of {SYSTEMS[p[1]]['name'].strip()}"

def wanted_hp(w, level, extreme=False, cm=45):
    """Level::createMission: h = 15*min(level, 20) + hitpoints + 4*cm (cm = 45 once the game is won, always true for
    campaign >= 128); x (1 + (d - 0.5)), d = 0.5 normal / 1.5 extreme. Its wingmen get h/2."""
    h = 15 * min(level, 20) + w['hitpoints'] + 4 * cm
    d = 1.5 if extreme else 0.5
    h = int(h + h * (d - 0.5))
    return h, h // 2

# ---- tables ---------------------------------------------------------------------------------------------------
MEDALS = [(0, -1, -1), (5, 15, 30), (11, 8, 5), (11, 8, 5), (250, 100, 50), (200, 100, 25), (1000, 500, 100),
          (25, 10, 3), (1000, 100, 25), (22, 16, 5), (150, 100, 30), (100, 50, 25), (22, 10, 5), (13, 6, 3), (13, 6, 3),
          (20, 10, 5), (50, 25, 5), (100, 50, 10), (50, 20, 5), (5, 3, 2), (50, 20, 5), (25, 10, 5), (0, -1, -1),
          (4, 3, 2), (500, 200, 50), (1000000, 500000, 125000), (100, 50, 20), (20, 10, 3), (1, -1, -1),
          (250, 150, 50), (0, -1, -1), (500, 250, 100), (50, -1, -1), (10, -1, -1), (12, -1, -1), (0, -1, -1),
          (3000, -1, -1), (50, -1, -1), (10, -1, -1), (20, -1, -1), (100, -1, -1), (3, -1, -1), (15, -1, -1),
          (5, -1, -1), (8, -1, -1)]

def cmd_wingman(a):
    name, race = a[0], int(a[1])
    s = wingman_ship(name, race)
    print(f'{name!r} (len {len(name)}, seed {5 * len(name)}), race {race} {RACE[race]} -> ship {s} {ship_name(s)}')
    print('all lengths 3..30 for this race:', {n: wingman_ship('x' * n, race) for n in range(3, 31)})

def cmd_formation(_):
    print('spawn (createWingmen, relative to the player at level start; facing the player direction, up = world Y):')
    for i, (r, up) in enumerate([(-1000, 0), (2000, 0), (0, 1000)]):
        print(f'  wingman {i}: player + right*{r} - forward*2000 + (0, {up}, 0)')
    print('formation point, command 1 (PlayerFighter::update ~0xf1040, recomputed every frame, 1-point looping route):')
    for i, off in enumerate(['- right*4000 - forward*3000', '+ right*4000 - forward*3000', '+ up*2000 - forward*2000']):
        print(f'  slot {i}: player {off}')

def cmd_wanted(a):
    level = int(a[0]) if a else 10; extreme = len(a) > 1
    unlock = {6: 45, 12: 46, 18: 47, 24: 48}
    for w in WANTED:
        i = w['index']; hp, whp = wanted_hp(w, level, extreme)
        lo, hi = jump_bounds(i)
        race = w['race'] if w['race'] < 4 else 8
        print(f"{i:2d} {w['name']:<18} board {w['board']} race {w['race']}->{race} ship {w['ship']:2d} {ship_name(w['ship']):<14}"
              f" gun {w['weapon']:3d} {item_name(w['weapon']):<22} HP {hp:5d} (+{w['numWingmen']}x{whp})"
              f" reward {w['reward']:6d} reqB {w['requiredBounties']} reqM {w['requiredMission']} path {lo}..{hi}"
              + (f" -> unlocks ship {unlock[i]} {ship_name(unlock[i])} at Quineros" if i in unlock else '')
              + (' STORYLINE' if i in (0, 1) else ''))

def cmd_simulate(a):
    i = int(a[0]); steps = int(a[1]) if len(a) > 1 else 12; rnd = random.Random(int(a[2]) if len(a) > 2 else 1)
    visible = [bool(s['initiallyVisible']) for s in SYSTEMS]
    for k in (25,): visible[k] = True
    w = activate(i, rnd, visible)
    print(f"activate {WANTED[i]['name']}: lastSeen {station_label(w['lastSeen'])}, travelsTo {station_label(w['travelsTo'])},"
          f" current {station_label(w['current'])}")
    for n in range(steps):
        what = move(i, w, rnd, visible)
        print(f"  orbit change {n + 1:2d}: {what:<40} now {station_label(w['current'])} -> {station_label(w['travelsTo'])}")

def cmd_medals(_):
    for i, t in enumerate(MEDALS):
        hint = TEXT[1552 + i] if 1552 + i < len(TEXT) else ''
        print(f'{i:2d} gold/silver/bronze > {t}  {hint[:70]!r}')

def cmd_texts(_):
    ids = [306, 307, 308, 309, 310, 311, 312, 313, 567, 637, 649, 779, 780, 781, 782, 783, 784, 785, 866, 867, 1579,
           3358, 601, 613, 3132, 3133, 3134, 3135, 3136, 3137, 3138, 3139, 3140] + list(range(3141, 3156)) + \
          list(range(3219, 3233)) + [3174, 3198]
    for t in ids:
        print(f'{t:5d}: {TEXT[t][:110]!r}')

if __name__ == '__main__':
    cmd = sys.argv[1] if len(sys.argv) > 1 else 'wanted'
    {'wingman': cmd_wingman, 'formation': cmd_formation, 'wanted': cmd_wanted, 'simulate': cmd_simulate,
     'medals': cmd_medals, 'texts': cmd_texts}[cmd](sys.argv[2:])
