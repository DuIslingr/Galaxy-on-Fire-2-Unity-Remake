# Reference implementation of the free-flight NPC rules (see Reference/research/npc_traffic_ai.md).
# Plain Python, no game data needed except Assets/Resources/GoF2Data/{systems,stations,ships}.json.
#   python Reference/tools/npc/npc_tables.py                 tables: HP / guns by level, fighter pools, raider odds
#   python Reference/tools/npc/npc_tables.py orbit 78 10     Monte-Carlo of the traffic of station 78 at player level 10
# All distances in game units, times in ms. Functions mirror the original function names.
import json, os, random, sys

HERE = os.path.dirname(os.path.abspath(__file__))
DATA = os.path.join(HERE, '..', '..', '..', 'Assets', 'Resources', 'GoF2Data')
def load(name):
    return json.load(open(os.path.join(DATA, name), encoding='utf-8'))

# DAT_00254990: race of ship index (first 64 entries; only 0..36 are rolled)
SHIP_RACE = [3, 0, 8, 3, 2, 0, 3, 0, 9, 1, 0, 8, 2, 0, 0, 0, 2, 0, 2, 3, 3, 2, 0, 8, 8, 8, 0, 0, 0, 8, 3, 2,
             8, 0, 0, 2, 0, 0, 0, 1, 0, 1, 1, 2, 1, 3, 3, 3, 3, 1, 1, 0, 8, 1, 1, 0, 3, 2, 0, 0]
ENEMY_RACE = [1, 0, 3, 2]            # DAT_00252020, Standing::getEnemyRace / SolarSystem::getAttackRace (else 8)
NPC_SHOT_SOUND = [52, 55, 54, 53, 61, 61, 61, 61, 61, 62, 2276]   # DAT_002526c0[race], >= 11 -> 61
LEVEL_XP = [0, 7, 21, 42, 70, 105, 147, 196, 252, 315, 385, 462, 546, 637, 735, 840, 952, 1071, 1197, 1330, 1650]
PIRATE_BASE_STATIONS = [1, 33, 47, 86]   # DAT_00251f90 (only while the outpost is not destroyed)

def enemy_race(race):
    return ENEMY_RACE[race] if 0 <= race < 4 else 8

def fighter_pool(race, dlc1_won=False):
    """Globals::getRandomEnemyFighter 0xf9034 as (ship, probability) pairs."""
    r = race if race < 4 else (race if race in (9, 10) else 8)
    if r == 1:
        return [(9, .60), (41, .25), (39, .15)] if dlc1_won else [(9, 1.0)]
    if r == 9:
        return [(8, 1.0)]
    if r == 10:
        return [(44, 1.0)]
    ships = [i for i in range(37) if (i & ~4) - 9 not in (0, 1) and not (i < 16 and (0x8101 >> i) & 1)
             and SHIP_RACE[i] == r]
    return [(s, 1.0 / len(ships)) for s in ships]

def random_fighter(race, rng, dlc1_won=False):
    pool = fighter_pool(race, dlc1_won)
    x = rng.random(); acc = 0.0
    for s, p in pool:
        acc += p
        if x < acc:
            return s
    return pool[-1][0]

def npc_hp(level, campaign=20, kind=0, ship=0, hardcore=False, game_won=False):
    """Level::createShip 0xcf83c: hull points (NPCs have no shield/armor) and EMP points."""
    L = min(level, 20)
    hp = (180 if game_won else 4 * campaign) + 14 * L + 20
    if ship == 0x33: hp = int(hp * 1.7)
    elif ship == 0x31: hp = int(hp * 17.0)
    elif ship == 0x2c: hp = int(hp * 2.25)
    if 0 <= campaign - 0x31 < 8 and (0x8f >> (campaign - 0x31)) & 1:
        hp = 270
    emp = 5 * L + 40
    emp_regen = 15000
    if kind == 1:                                   # freighter / battleship (PlayerFixedObject)
        hp *= 25 if ship == 14 else 5
        emp *= 3; emp_regen = 45000
    d = 1.5 if hardcore else 0.5                     # Globals::options+0x44
    hp = int(hp + hp * (d - 0.5))
    radius = 650 if hardcore else 1000               # Player radius = bullet hit cube half size
    return dict(hp=hp, emp=emp, emp_regen_ms=emp_regen, radius=radius)

def npc_gun(level, race, campaign=20, hardcore=False, game_won=False, always_friend=False, wingman=False):
    """Level::assignGuns 0xcb638, the normal free-flight case."""
    v = int(0.9 * (level - 2)) if 0.9 * (level - 2) < 20 else 20
    v = max(v, 0)
    d = 1.5 if hardcore else 0.5
    v = int(v + (d - 0.5) * v)
    v = 22 if v > 21 else v
    dmg = 3 if v == 0 else v + 2
    if campaign == 4: dmg = 1
    if race == 9 and not wingman and not always_friend:
        dmg = int(dmg * (2 if campaign == 0x10 else 0.8))
    item, projectile = {0: (0, 6754), 1: (3, 6760), 2: (7, 6764), 3: (25, 6802), 9: (5, 6762),
                        10: (229, 19091)}.get(race, (19, 6795))
    if race == 10: dmg = int(dmg * 0.7)
    reload_ms = 600 - 2 * (45 if game_won else campaign)
    return dict(damage=dmg, item_for_visuals=item, projectile_mesh=projectile, bullets=4, lifetime_ms=3000,
                reload_ms=reload_ms, speed=16.0, range=48000, sound=NPC_SHOT_SOUND[race] if race < 11 else 61)

def raider_chance(security, hardcore=False, mido_tutorial=False):
    """Level::createMission: P(raider group) in %."""
    if mido_tutorial and not hardcore:
        return 0
    s = security - 1 if (hardcore and security >= 1) else security
    return {0: 90, 1: 65, 2: 35}.get(s, 10)

def free_flight_traffic(station, level, rng, campaign=20, hardcore=False, wanted_wingmen=None,
                        station_attacked_friends=False):
    """Counts of Level::createMission's empty-mission branch for a normal orbit (no freelance mission,
    no alien attack, no hidden blueprint, no campaign special). Returns the groups in array order."""
    systems = load('systems.json')
    sysd = next(s for s in systems if station in s['stations'])
    sec, race = sysd['securityLevel'], sysd['raceId']
    mido_tutorial = sysd['index'] == 15 and campaign < 16
    r100 = rng.randrange(100)
    escorts = 0
    pirate_base_system = any(p in sysd['stations'] for p in PIRATE_BASE_STATIONS)
    if pirate_base_system:
        escorts = 2
    sec_eff = sec - 1 if (hardcore and sec >= 1) else sec
    raiders_on = r100 < raider_chance(sec, hardcore, mido_tutorial)
    raider_race = 8 if rng.randrange(100) < 75 else enemy_race(race)
    raiders = rng.randrange(4) if raiders_on else 0
    if raiders > 0:
        if hardcore: raiders = rng.randrange(6) + 2
        raiders = int(raiders * (2 if hardcore else 1))
        raiders += level // 4
    if sec_eff == 3 and raiders_on and not hardcore:
        raiders = rng.randrange(2) + 1
    if station == 78:
        jumpers = freighters = extra = 0
    else:
        jumpers = rng.randrange(2); freighters = rng.randrange(5); extra = rng.randrange(2)
    base = rng.randrange(2) if mido_tutorial else sec_eff
    local = base + extra + freighters // 4
    if raiders_on and campaign > 0x1f and rng.randrange(100) < 8:
        raiders = local = 9
    if pirate_base_system:
        escorts = (rng.randrange(3) + 4) if hardcore else 2
        raiders_on = False; raiders = 0
    if wanted_wingmen is not None:
        local = min(local, 2)
    if station_attacked_friends:
        local = max(local, 7)
    if jumpers + local + freighters + raiders + escorts == 0:
        local = 4
    if station in (100, 101, 108, 10):
        local = jumpers = freighters = raiders = 0
    elif station in (102, 103, 104):
        local = jumpers = freighters = 0; raiders = rng.randrange(5) + 3; raider_race = 8
    if sysd['index'] == 25:                                        # black market (Loma)
        escorts = local = jumpers = freighters = 0; raiders = rng.randrange(4) + 6; raider_race = 8
    if sysd['index'] in (32, 33):                                  # pirate loot orbits
        escorts = local = jumpers = freighters = 0; raiders = rng.randrange(4) + 10; raider_race = 8
    if wanted_wingmen is not None:
        local += wanted_wingmen + 1
    return dict(system=sysd['name'], security=sec, race=race, local=local, jumpers=jumpers,
                freighters=freighters, raiders=raiders if raiders_on or station in (102, 103, 104)
                or sysd['index'] in (25, 32, 33) else 0, raider_race=raider_race, pirate_escorts=escorts)

# ---- Standing (two axes: [0] Terran(+)/Vossk(-), [1] Nivelian(+)/Midorian(-); start 30, 0) ----
def standing_is_enemy(s, race, signature=-1):
    if signature >= 0:
        return {1: signature == 0, 3: signature == 2, 2: signature == 3, 0: signature == 1}.get(race, False)
    return {0: s[0] <= -71, 1: s[0] > 70, 2: s[1] <= -71, 3: s[1] > 70}.get(race, False)

def standing_is_friend(s, race, signature=-1):
    if signature >= 0:
        return signature == race and race < 4
    return {0: s[0] >= 71, 1: s[0] < -70, 2: s[1] >= 71, 3: s[1] < -70}.get(race, False)

def apply_delict(s, race, points, hardcore=False):
    p = points << (1 if hardcore else 0)
    if race == 0: s[0] -= p
    elif race == 1: s[0] += p
    elif race == 2: s[1] -= p
    elif race == 3: s[1] += p
    s[0] = max(-100, min(100, s[0])); s[1] = max(-100, min(100, s[1]))

def hostile_to_player(npc_race, s, signature=-1):
    """PlayerFighter::update: Player+0x5c before the turned/always flags."""
    if npc_race in (8, 9):
        return True
    return standing_is_enemy(s, npc_race, signature)

def races_hostile(a, b):
    """PlayerFighter::update / PlayerTurret::pickEnemy race table (non-wingman NPC vs NPC)."""
    return ((a == 8) != (b == 8)) or ((a == 9) != (b == 9)) or ((a == 10) != (b == 10)) \
        or {a, b} == {0, 1} or {a, b} == {2, 3}

def main():
    if len(sys.argv) >= 2 and sys.argv[1] == 'orbit':
        st = int(sys.argv[2]); lvl = int(sys.argv[3]) if len(sys.argv) > 3 else 0
        rng = random.Random(1); n = 20000; acc = {}
        for _ in range(n):
            t = free_flight_traffic(st, lvl, rng)
            for k in ('local', 'jumpers', 'freighters', 'raiders', 'pirate_escorts'):
                acc.setdefault(k, []).append(t[k])
        print('station', st, t['system'], 'security', t['security'], 'race', t['race'], 'level', lvl)
        for k, v in acc.items():
            print('  %-15s mean %.2f  P(>0) %.0f%%  max %d' % (k, sum(v) / n, 100.0 * sum(1 for x in v if x) / n, max(v)))
        return
    print('NPC hull HP / EMP / gun by player level (campaign mission 20, normal difficulty):')
    print('  level  fighterHP  freighterHP  battleshipHP  EMP  gunDamage  reload')
    for L in (0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20):
        g = npc_gun(L, 0)
        print('  %5d  %9d  %11d  %12d  %3d  %9d  %6d' % (L, npc_hp(L)['hp'], npc_hp(L, kind=1, ship=15)['hp'],
              npc_hp(L, kind=1, ship=14)['hp'], npc_hp(L)['emp'], g['damage'], g['reload_ms']))
    ships = load('ships.json')
    print('\nFighter pools (getRandomEnemyFighter):')
    for r, name in ((0, 'Terran'), (1, 'Vossk'), (2, 'Nivelian'), (3, 'Midorian'), (8, 'Pirate'), (9, 'Void'), (10, '???')):
        print('  %-9s' % name, ', '.join('%d %s %.0f%%' % (s, ships[s]['name'], p * 100) for s, p in fighter_pool(r)))
    print('\nRaider group chance by security (normal / hardcore):',
          ', '.join('%d: %d%% / %d%%' % (s, raider_chance(s), raider_chance(s, True)) for s in range(4)))

if __name__ == '__main__':
    main()
