# Freelance missions / bar agents of Galaxy on Fire 2 (HD), ported from the decompiled code for the remake.
# See Reference/research/freelance_missions.md. PRIVATE: reads the game's data files, never publish its output.
#
#   python Reference/tools/missions/mission_tables.py offers 55 --seed 3 --level 5 --campaign 20
#   python Reference/tools/missions/mission_tables.py reward --type 0 --difficulty 5 --from 55 --to 78 --level 5
#   python Reference/tools/missions/mission_tables.py stats 55 --n 20000 --level 5
#
# The original uses one time-seeded java.util.Random (Globals::rnd) for everything, so offers are not reproducible;
# this script uses Python's random.Random(seed) and only reproduces the rules and distributions.
import argparse, json, math, os, random, collections

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, '..', '..', '..'))
DATA = os.path.join(ROOT, 'Assets', 'Resources', 'GoF2Data')
TEXT = os.path.join(ROOT, 'Assets', 'Localization', 'text_en.json')


def load(name):
    with open(os.path.join(DATA, name), encoding='utf-8') as f:
        return json.load(f)


SYSTEMS = load('systems.json')
STATIONS = load('stations.json')
ITEMS = load('items.json')
NAMES = load('names.json')
STORY_AGENTS = load('agents.json')
with open(TEXT, encoding='utf-8') as f:
    T = json.load(f)

# Generator::generateStationIndex 0xa1e2c: stations never used as mission targets (DAT_00251e70, 52 entries)
EXCLUDED_TARGETS = {10, 22, 27, 29, 30, 48, 55, 56, 76, 79, 91, 98, 1, 33, 47, 86, 58, 65, 66, 74, 81, 100, 101, 102,
                    103, 104, 105, 106, 107, 108, 83, 85, 92, 109, 110, 11, 113, 121, 126, 131, 38, 90, 91, 93, 94, 82,
                    40, 15, 60, 95, 70, 80}
EARLY_TYPES = [11, 0, 7, 4, 12]          # DAT_00251f60: types before campaign mission 16
TYPE_NAME = {t: T[354 + t] for t in range(16)}   # Mission::getName: text 0x162 + type
RACE_NAME = {i: T[406 + i] for i in range(10)}


def item_price(i):                        # Item+0x18 "single price", initialised to (min + max) / 2
    return (ITEMS[i]['minPrice'] + ITEMS[i]['maxPrice']) // 2


def has_ingredients(i):
    return bool(ITEMS[i].get('blueprint'))


def system_of(station):
    return STATIONS[station]['system']


def distance(sa, sb):                     # Galaxy::distance 0x1a4e7c: map x, y and z / 10 (int)
    if sa == sb:
        return 0.0
    a, b = SYSTEMS[sa]['mapPosition'], SYSTEMS[sb]['mapPosition']
    return math.sqrt((a['x'] - b['x']) ** 2 + (a['y'] - b['y']) ** 2 + (int(a['z'] / 10) - int(b['z'] / 10)) ** 2)


def round50(x):
    """The original's rounding to 50 credits: down, except a remainder of exactly 25 rounds up."""
    x = int(x)
    m = x % 50
    return x + m if m in (0, 25) else x - m


def standing_bonus(race, s0, s1):         # Standing::getMissionBonus 0x142b34: max(0, standing toward race / 100)
    v = {0: s0, 1: -s0, 2: s1, 3: -s1}.get(race)
    return 0.0 if v is None else max(0.0, v / 100.0)


class Ctx:
    def __init__(self, rng, level=0, campaign=20, s0=30, s1=0, visible=None, hardcore=False):
        self.rng, self.level, self.campaign, self.s0, self.s1, self.hardcore = rng, level, campaign, s0, s1, hardcore
        self.visible = visible if visible is not None else [s['initiallyVisible'] for s in SYSTEMS]
        self.used_types = [0] * 15        # Status+0x50: mission-type flags, reset once 14 are used

    def rnd(self, n):
        return self.rng.randrange(n) if n > 0 else 0


def random_name(ctx, race, male):         # Globals::getRandomName 0xf85a0 + FileRead::loadNamesBinary 0x146290
    r = ctx.rnd
    if race == 0:
        first, last = ('terran_0_m' if male else 'terran_0_w'), 'terran_1'
    elif race == 3:                       # Midorians use Terran or Nivelian names (two independent 50 % picks)
        first = 'terran_0_m' if r(2) == 0 else 'nivelian_0'
        last = 'terran_1' if r(2) == 0 else 'nivelian_1'
    else:
        key = {1: 'vossk', 2: 'nivelian', 4: 'multipod', 5: 'cyborg', 6: 'bobolan', 7: 'grey'}.get(race)
        if key is None:
            return ''
        first, last = key + '_0', (key + '_1' if key not in ('cyborg', 'grey') else None)
    f = NAMES[first][r(len(NAMES[first]))]
    return f if not last else f + ' ' + NAMES[last][r(len(NAMES[last]))]


def generate_station_index(ctx, agent_station, cur_station):   # Generator::generateStationIndex 0xa1e2c
    r, cur_sys = ctx.rnd, system_of(cur_station)
    while True:
        if r(100) < 20:
            st = agent_station
        elif r(100) < 40:
            sts = SYSTEMS[cur_sys]['stations']
            st = sts[r(len(sts))]
        else:
            st = r(135)
        if cur_sys == 15:                 # Mido: always a station of the current system
            sts = SYSTEMS[cur_sys]['stations']
            st = sts[r(len(sts))]
        sysi = system_of(st)
        ok = st not in EXCLUDED_TARGETS and ctx.visible[sysi] and not (109 <= st <= 113)
        if not SYSTEMS[sysi]['jumpRoutesTo'] and sysi != cur_sys:
            ok = False
        if ok:
            return st


def pick_type(ctx, agent_race):           # the rnd(15) loop of Generator::createMission 0xa2a7c
    t = 0
    for _ in range(1000):
        t = ctx.rnd(15)
        if t == 8 or (t == 10 and agent_race > 3):
            continue                      # purchase only through offer 5; intercept only for races 0-3
        if not ctx.used_types[t]:
            ctx.used_types[t] = 1
            break
        if sum(ctx.used_types) == 14:
            ctx.used_types = [0] * 15
    if ctx.campaign < 16:
        t = EARLY_TYPES[ctx.rnd(5)]
    return t


def create_mission(ctx, agent, cur_station, purchase=False):   # Generator::createMission 0xa2a7c
    r = ctx.rnd
    target = generate_station_index(ctx, agent['station'], cur_station)
    if system_of(cur_station) == 15:
        target = SYSTEMS[15]['stations'][0] + r(4)
    race = agent['race']
    mtype = pick_type(ctx, race)
    if mtype == 12:
        target = agent['station']
    if purchase:                          # offer 5
        target, mtype = agent['station'], 8
    else:
        if mtype in (0, 11, 14):          # mask 0x4801: never the station you are at
            while target == cur_station:
                target = generate_station_index(ctx, agent['station'], cur_station)
        if race < 4 and mtype == 13:      # informer: a station of the agent's race, else defense / pirate hunting
            if SYSTEMS[system_of(agent['station'])]['jumpRoutesTo']:
                while SYSTEMS[system_of(target)]['raceId'] != race:
                    target = generate_station_index(ctx, agent['station'], cur_station)
            else:
                mtype = 1 if r(2) == 0 else 4
    diff = r(2) if ctx.campaign < 16 else r(9)
    good, amount = 0, 0
    if mtype == 8:
        while True:
            off = r(len(ITEMS) - 97)
            idx = off + 97
            if ITEMS[idx]['occurrence'] == 0 or item_price(idx) == 0:
                continue
            if idx in (115, 116, 117, 131, 164, 175, 217, 218) or has_ingredients(idx):
                continue
            break
        good, amount = idx, r(15) + 5
        diff = ITEMS[idx]['techLevel']
    else:
        diff += 1
        d = diff / 10.0
        if mtype == 0:
            good, amount = r(7), int(d * 95.0) + 5          # good = cargo description 813 + good
        elif mtype == 2:
            amount = r(4) + 2                               # mining ships to protect
        elif mtype in (3, 5):
            good, amount = (116 if mtype == 3 else 117), int(d * 8.0) + 2   # ships, the last carries the crate
        elif mtype == 11:
            amount = int(d * 18.0) + 2                      # passengers
        elif mtype == 15:
            amount = r(90) + 30                             # tons of ore (type unreachable, see the doc)
    diff = min(diff, 10)
    dist = distance(system_of(cur_station), system_of(target))
    rew = float(int(diff / 10.0 * 5500.0) + 1500) * (dist / 1200.0 + 1.0)
    if mtype == 9:
        rew *= 1.2
    elif mtype == 7:
        rew *= 0.7
    elif mtype == 8:
        rew = float(amount * ITEMS[good]['maxPrice']) * 1.7
    elif mtype in (3, 5):
        rew += rew
    elif mtype == 11:
        rew = rew * 0.6 + amount * (rew * 0.6 / 5.0)
    rew += 10 * ctx.level ** 3
    bonus = 0 if mtype in (8, 12) else round50(rew * standing_bonus(race, ctx.s0, ctx.s1))
    reward = round50(rew)
    costs = int(reward / 10.0 + r(reward // 10))
    if mtype == 8:
        costs = int(costs * 0.5)
    m = dict(type=mtype, target=target, difficulty=diff, good=good, amount=amount, reward=reward, bonus=bonus,
             costs=round50(costs), client=agent['name'], race=race, distance=dist)
    if mtype == 6:
        m['targetName'] = random_name(ctx, 0, True)          # args lost in the decompile; race assumed Terran
    return m


def create_agent(ctx, station):           # Generator::createAgent 0xa26c0
    r = ctx.rnd
    race = SYSTEMS[system_of(station)]['raceId']
    if r(100) < 20:
        race = r(8)
    while True:
        offer = r(7)
        if race == 1 and offer == 6:
            continue
        if offer in (3, 4):
            continue
        break
    if r(100) < 33:
        offer = 0
    elif offer in (5, 6) and ctx.campaign < 16:
        offer = 0
    male = True
    if race == 0 and offer != 6:
        male = r(100) < 60
    a = dict(name=random_name(ctx, race, male), race=race, male=male, station=station, offer=offer)
    if offer == 6:
        friends = r(3)
        a['wingmen'] = [random_name(ctx, race, True) for _ in range(friends)]
        a['costs'] = (r(1300) + 700) * (friends + 1) * (7 if ctx.hardcore else 1)
    elif offer == 2:
        while True:
            idx = r(len(ITEMS))
            if idx in (131, 164, 175, 217, 218):
                continue
            if has_ingredients(idx) or item_price(idx) == 0 or ITEMS[idx]['occurrence'] == 0:
                continue
            break
        q = r(15)
        q = 1 if ITEMS[idx]['type'] in ('primary', 'turret', 'equipment') else q + 5
        pct = r(120) + 40
        a.update(item=idx, qty=q, price=int(pct / 100.0 * item_price(idx)) * q)
    return a


def create_agents(ctx, station):          # Generator::createAgents 0xa1fd0 (generic part; story agents listed only)
    r = ctx.rnd
    story = [s for s in STORY_AGENTS if s['station'] == station] if ctx.campaign > 16 else []
    n = len(story)
    if station != 108:
        n = n + 3 + r(2) if r(2) + n + 3 < 5 else 5
    agents, wingman = [], False
    for _ in range(max(0, n - len(story))):
        a = create_agent(ctx, station)
        if a['offer'] == 6:
            if wingman:
                a['offer'] = 1
            wingman = True
        elif a['offer'] == 0:
            a['mission'] = create_mission(ctx, a, station)
        agents.append(a)
    if r(100) < 35:                       # diplomats for hostile races (DAT_00251f80 = 2, 3, 0, 1)
        for race in (2, 3, 0, 1):
            s = {0: ctx.s0, 1: -ctx.s0, 2: ctx.s1, 3: -ctx.s1}[race]
            if s <= -71:
                for i, a in enumerate(agents):
                    if a['offer'] != 7:
                        cost = int(abs(ctx.s0 if race < 2 else ctx.s1) / 100.0 * 16000.0)
                        agents[i] = dict(name=random_name(ctx, race, True), race=race, male=True, station=station,
                                         offer=7, costs=cost)
                        break
    if r(100) == 1:                       # 1 %: the first mission under 50 000 pays 10x (max 50 000)
        for a in agents:
            m = a.get('mission')
            if m and m['reward'] < 50000:
                m['reward'] = min(m['reward'] * 10, 50000)
                break
    for a in agents:                      # offer 5 creates its purchase mission when you first talk to the agent
        if a['offer'] == 5:
            a['mission'] = create_mission(ctx, a, station, purchase=True)
    return story, agents


def fill(s, **kv):
    for k, v in kv.items():
        s = s.replace('#' + k, str(v))
    return s


def offer_text(a):                        # SpaceLounge::startChat 0x198974 (generic agent, first talk)
    o = a['offer']
    if o == 1:
        return '(small talk, texts 820-840)'
    if o == 7:
        t = {2: 878, 3: 880, 0: 881, 1: 882}[a['race']]
        return fill(T[t], C=f"{a['costs']:,}")
    if o == 6:
        return fill(T[779 + len(a['wingmen'])], C=f"{a['costs']:,}", W=(a['wingmen'] or [''])[0])
    if o == 2:
        return fill(T[773], Q=a['qty'], P=T[1274 + a['item']], C=f"{a['price']:,}")
    m = a['mission']
    if o == 5:
        return fill(T[777], Q=m['amount'], P=T[1274 + m['good']], C=f"{m['reward']:,}")
    t = m['type']
    if t == 12:
        return fill(T[798], C=f"{m['reward']:,}")
    txt = T[786 + t] + ((' ' + T[802]) if t in (3, 5) else '')
    good = T[1274 + m['good']] if t == 15 else (T[813 + m['good']] if t == 0 else '')
    tgt = SYSTEMS[system_of(m['target'])]['name'] if t == 14 else STATIONS[m['target']]['name']
    txt = fill(txt, P=good, Q=m['amount'], S=tgt, N=m.get('targetName', ''))
    total = m['reward'] + m['bonus']
    extra = f" (incl. {m['bonus']:,} standing bonus)" if m['bonus'] else ''
    return txt + ' ' + fill(T[765], C=f'{total:,}') + extra


def cmd_offers(args):
    ctx = Ctx(random.Random(args.seed), args.level, args.campaign, args.s0, args.s1,
              [True] * len(SYSTEMS) if args.all_visible else None, args.hardcore)
    st = args.station
    story, agents = create_agents(ctx, st)
    print(f"Station {st} {STATIONS[st]['name']} ({SYSTEMS[system_of(st)]['name']}), level {ctx.level}, "
          f"campaign {ctx.campaign}, standing T/V {ctx.s0} N/M {ctx.s1}")
    for s in story:
        print(f"  story agent {s['index']:2d} {s['name']} ({s['raceName']})")
    for a in agents:
        g = 'm' if a['male'] else 'f'
        head = f"  {a['name']} ({RACE_NAME[a['race']]}, {g}) offer {a['offer']}"
        m = a.get('mission')
        if m:
            head += (f" | {TYPE_NAME[m['type']]} -> {STATIONS[m['target']]['name']} "
                     f"({SYSTEMS[system_of(m['target'])]['name']}), difficulty {m['difficulty']}, "
                     f"reward {m['reward']:,} + bonus {m['bonus']:,}, risk text {808 + int(m['difficulty'] / 10 * 5)}")
        print(head)
        print('      ' + offer_text(a))


def cmd_reward(args):
    ctx = Ctx(random.Random(args.seed), args.level, 20, args.s0, args.s1)
    d = min(args.difficulty, 10)
    dist = distance(system_of(args.frm), system_of(args.to))
    base = float(int(d / 10.0 * 5500.0) + 1500) * (dist / 1200.0 + 1.0)
    t = args.type
    rew = base * {9: 1.2, 7: 0.7, 3: 2.0, 5: 2.0}.get(t, 1.0)
    if t == 11:
        rew = base * 0.6 + args.amount * (base * 0.6 / 5.0)
    if t == 8:
        rew = float(args.amount * ITEMS[args.item]['maxPrice']) * 1.7
    rew += 10 * ctx.level ** 3
    bonus = 0 if t in (8, 12) else round50(rew * standing_bonus(args.race, ctx.s0, ctx.s1))
    print(f"type {t} {TYPE_NAME[t]}, difficulty {d}, distance {dist:.2f} (factor {dist / 1200 + 1:.4f}), "
          f"level term {10 * ctx.level ** 3}: reward {round50(rew):,} + bonus {bonus:,}")


def cmd_stats(args):
    ctx = Ctx(random.Random(args.seed), args.level, args.campaign, args.s0, args.s1,
              [True] * len(SYSTEMS) if args.all_visible else None, args.hardcore)
    offers, types, rewards, counts = collections.Counter(), collections.Counter(), collections.defaultdict(list), \
        collections.Counter()
    for _ in range(args.n):
        story, agents = create_agents(ctx, args.station)
        counts[len(story) + len(agents)] += 1
        for a in agents:
            offers[a['offer']] += 1
            if a.get('mission'):
                m = a['mission']
                types[m['type']] += 1
                rewards[m['type']].append(m['reward'] + m['bonus'])
    tot = sum(offers.values())
    print('visitors per bar:', dict(sorted(counts.items())))
    print('offers:', {k: f'{v / tot:.1%}' for k, v in sorted(offers.items())})
    tt = sum(types.values())
    for t, v in sorted(types.items()):
        rw = sorted(rewards[t])
        print(f"  {t:2d} {TYPE_NAME[t]:15s} {v / tt:6.1%}  reward min {rw[0]:>9,} median {rw[len(rw) // 2]:>9,} "
              f"max {rw[-1]:>9,}")


def main():
    p = argparse.ArgumentParser()
    sub = p.add_subparsers(dest='cmd', required=True)
    for name in ('offers', 'stats'):
        q = sub.add_parser(name)
        q.add_argument('station', type=int)
        q.add_argument('--seed', type=int, default=1)
        q.add_argument('--level', type=int, default=0, help='player level 0..20 (Status+0x1c8)')
        q.add_argument('--campaign', type=int, default=20, help='campaign mission (remake free play = 20)')
        q.add_argument('--s0', type=int, default=30, help='standing Terran(+)/Vossk(-)')
        q.add_argument('--s1', type=int, default=0, help='standing Nivelian(+)/Midorian(-)')
        q.add_argument('--all-visible', action='store_true', help='all systems discovered')
        q.add_argument('--hardcore', action='store_true')
        if name == 'stats':
            q.add_argument('--n', type=int, default=5000)
    q = sub.add_parser('reward')
    q.add_argument('--type', type=int, required=True)
    q.add_argument('--difficulty', type=int, default=5)
    q.add_argument('--from', dest='frm', type=int, required=True, help='current station')
    q.add_argument('--to', type=int, required=True, help='target station')
    q.add_argument('--level', type=int, default=0)
    q.add_argument('--race', type=int, default=0, help='client race (standing bonus)')
    q.add_argument('--amount', type=int, default=10, help='passengers (11) / purchase amount (8)')
    q.add_argument('--item', type=int, default=122, help='purchase item (8)')
    q.add_argument('--s0', type=int, default=30)
    q.add_argument('--s1', type=int, default=0)
    q.add_argument('--seed', type=int, default=1)
    args = p.parse_args()
    {'offers': cmd_offers, 'reward': cmd_reward, 'stats': cmd_stats}[args.cmd](args)


if __name__ == '__main__':
    main()
