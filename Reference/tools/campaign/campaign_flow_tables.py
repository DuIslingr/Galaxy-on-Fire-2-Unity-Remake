# Campaign (story) flow research helper (see Reference/research/campaign_flow.md).
#   python Reference/tools/campaign/campaign_flow_tables.py             -> markdown table, one row per campaign index
#   python Reference/tools/campaign/campaign_flow_tables.py dialog N    -> full briefing + success dialogue of index N
#   python Reference/tools/campaign/campaign_flow_tables.py json OUT    -> everything as JSON (for a remake data file)
#
# Sources (Ghidra addresses, image base 0x10000):
#   Status::nextCampaignMission(bool)      0x0b6c98  transition table below (hand-transcribed, one case per index)
#   Status::resetGame                      0x0ba78c  index 0: Mission(4, 0, 78)
#   DialogueWindow::init / loadContent     0x194734 / 0x194cd0
#       DAT_00259ed0[162]  briefing length per index (ints = 2 * pages)
#       DAT_0025a158[162]  success  length per index
#       DAT_0025a3e0[...]  briefing pages: (speaker, textId) pairs, concatenated in index order
#       DAT_0025a5c0[...]  success  pages: (speaker, textId) pairs, concatenated in index order
#       speaker name = text 1597 + speaker, portrait = PTR_DAT_002647ec[speaker]
#   MissionsWindow::init                   0x17a604  DAT_00258f68[164] objective text per index ('#' = target station)
#   Status::missionCompleted               0x0b924c  completion rule per mission type (TYPE_RULES below)
import sys, os, json, struct
from elftools.elf.elffile import ELFFile   # pip install pyelftools

here = os.path.dirname(os.path.abspath(__file__))
root = os.path.join(here, '..', '..', '..')
D = os.path.join(root, 'Assets', 'Resources', 'GoF2Data')
TEXT = json.load(open(os.path.join(root, 'Assets', 'Localization', 'text_en.json'), encoding='utf-8'))
STATIONS = {s['index']: s for s in json.load(open(os.path.join(D, 'stations.json'), encoding='utf-8'))}
_items = json.load(open(os.path.join(D, 'items.json'), encoding='utf-8'))
ITEMS = _items['items'] if isinstance(_items, dict) else _items
_ships = json.load(open(os.path.join(D, 'ships.json'), encoding='utf-8'))
SHIPS = _ships['ships'] if isinstance(_ships, dict) else _ships

_elf = ELFFile(open(os.path.join(root, 'Reference', 'binaries', 'libgof2hdaa.so'), 'rb'))
_segs = [(s['p_vaddr'], s['p_filesz'], s.data()) for s in _elf.iter_segments() if s['p_type'] == 'PT_LOAD']


def ints(addr, n):
    a = addr - 0x10000
    for v, sz, d in _segs:
        if v <= a < v + sz:
            o = a - v
            return list(struct.unpack('<%di' % n, d[o:o + 4 * n]))
    raise ValueError(hex(addr))


N_DIALOG = 162                      # DialogueWindow::hasBriefingDialogue: index > 0xa1 -> none
BRIEF_LEN = ints(0x259ed0, N_DIALOG)
SUCC_LEN = ints(0x25a158, N_DIALOG)
_B = ints(0x25a3e0, sum(BRIEF_LEN))
_S = ints(0x25a5c0, sum(SUCC_LEN))
OBJECTIVE = ints(0x258f68, 164)     # MissionsWindow::init: only used while index < 0xa4


def _pages(flat, lens):
    out, o = [], 0
    for n in lens:
        out.append([(flat[o + 2 * k], flat[o + 2 * k + 1]) for k in range(n // 2)])
        o += n
    return out


BRIEF = _pages(_B, BRIEF_LEN)
SUCC = _pages(_S, SUCC_LEN)


def speaker(i):
    return TEXT[1597 + i]


def st(i):
    if i is None or i < 0:
        return '-' if i is None else 'any/%d' % i
    s = STATIONS.get(i)
    return '%d %s (%s)' % (i, s['name'], s['systemName'].strip()) if s else str(i)


def item(i):
    return '%d %s' % (i, ITEMS[i]['name'])


def ship(i):
    return '%d %s' % (i, SHIPS[i]['name'])


# Mission types used by the campaign (Mission::Mission(int type, int reward, int targetStation) 0x187cc0) and the
# rule Status::missionCompleted(docked, inLoungeIntroDone, levelTimeMs) 0x0b924c applies to them.
# "level" = not completed there; the in-space level (Level::createCampaignMission 0x0c3370 / LevelScript::process
# 0x160d50, MGame::successCheck 0x1b0620 via Level::checkObjective) decides.
TYPE_RULES = {
    0x00: 'docked at target (same as 0xb)',
    0x01: 'level (freelance "Defense" type reused)',
    0x04: 'level: scripted campaign fight/event in the target orbit',
    0x06: 'level (freelance "Wanted" type reused: hunt a named ship)',
    0x08: 'docked at target with goods(index, amount) in cargo ("Purchase" type); special case at index 143',
    0x0a: 'level (freelance "Intercept" type reused)',
    0x0b: 'docked at the target station',
    0x0c: 'level (freelance "Challenge" type reused: race / kill contest)',
    0x96: 'freelance missions completed (Status+0x1c4) >= statusValue',
    0x9a: 'current cargo load (t) >= statusValue',
    0x9c: 'in space (not docked), in the target orbit, level time >= 10000 ms',
    0x9e: 'a primary weapon (item type 0) and an item of sort 10 mounted',
    0xa0: 'docked anywhere, or in space >= 10000 ms in an orbit other than the target (target -1 = any)',
    0xa1: 'level: Void-invasion orbit (Status+0x80); never completed by missionCompleted',
    0xa3: 'all entries of Status+0x90 (target station list) negative (= destroyed / done)',
    0xa4: 'in space (not docked) for > 10000 ms (a radio call after launch)',
    0xa5: 'in space in the target orbit (target -1: only via the level)',
    0xa6: 'docked at target with goods(index, amount) in cargo, or goods index mounted',
    0xa8: 'Status+0x174 counter >= statusValue (then counter reset)',
    0xaa: 'statusValue == 1 (set by the level script / cinematic)',
    0xab: 'docked at target and inside its Space Lounge with the lounge intro finished',
    0xac: 'as 0xab and goods(index, amount) in cargo',
    0xae: 'statusValue >= goods amount (counter, e.g. mined tons)',
    0xb8: 'statusValue == 0 (passengers still to move; decremented by the level); index 92 also needs the '
          'transporter dock (Status+0x78 / station 113)',
    0xbd: 'docked with an equipment item of sort == statusValue mounted',
}

# Status::nextCampaignMission 0x0b6c98: `case k` runs when the index goes k -> k+1 and creates the campaign
# mission for the NEW index. Keyed by the new index N.  (type, reward, targetStation, statusValue, goods, visible, effects)
# goods = Mission::setProductionGoods(index, amount); statusValue None = constructor default 0.
T = {}
def m(n, typ, reward=0, stn=-1, value=None, goods=None, visible=True, fx=''):
    T[n] = dict(type=typ, reward=reward, station=stn, value=value, goods=goods, visible=visible, effects=fx)

m(0, 0x04, 0, 78, fx='Status::resetGame: prologue level (3598 A.D.), ship 10 Phantom; active level mission = this')
m(1, 0x0b, 0, 78, fx='Status+400 (active mission) = campaign mission. ModStation::OnInitialize at index 1: ship -> '
                     '0 Betty (race 8) with 90 Gunant\'s Drill + 81 Telta Quickscan, both unsaleable')
m(2, 0x9a, 0, 78, value=10)
m(3, 0x0b, 0, 78)
m(4, 0x9a, 0, 78, value=25, fx='cargo cleared (Ship::setCargo(null))')
m(5, 0x0b, 0, 78)
m(6, 0x9e, 0, 78, fx='Ship::removeAllCargo')
m(7, 0x04, 0, 78)
m(8, 0x0b, 0, 78, fx='all equipment + cargo made saleable, prices reset to Item::getSinglePrice')
m(9, 0x0b, 0, 78)
m(10, 0x0b, 0, 79, fx='drill (sort 19) replaced by 86 IMT Extract 1.3')
m(11, 0x0b, 0, 76)
m(12, 0x0b, 0, 79)
m(13, 0x96, 0, 0, value='missionCount+1', visible=False)
m(14, 0x04, 0, 79)
m(15, 0x0b, 0, 98)
m(16, 0x04, 0, 98)
m(17, 0x0b, 0, 98)
m(18, 0x9c, 0, 56, fx='ship race -> 0 (Terran)')
m(19, 0x9c, 0, 55)
m(20, 0xbd, 0, 55, value=6)
m(21, 0x04, 0, 55)
m(22, 0x0b, 0, 55)
m(23, 0x0b, 20000, 10, fx='system 6 (Wolf-Reiser) made visible')
m(24, 0x04, 0, 48, fx='Void invasion: Status+0x7c = 9, +0x80 = 48')
m(25, 0x9c, 0, -1, fx='cargo 131 Alien Remains made unsaleable')
m(26, 0x04, 0, 48, fx='Status+0x7c/+0x80 = -1')
m(27, 0x0b, 0, 10)
m(28, 0x04, 0, 91, fx='Void invasion: Status+0x7c = 18, +0x80 = 91')
m(29, 0x04, 0, -1)
m(30, 0x9c, 0, 91)
m(31, 0x0b, 30000, 98)
m(32, 0x0b, 0, 10)
m(33, 0x08, 0, 10, goods=(164, 50))
m(34, 0x0b, 0, 30, fx='50 Void Crystals removed; blueprint 85 Khador Drive unlocked (+164 x50 ingredient at station 10)')
m(35, 0x0b, 0, 29)
m(36, 0x0c, 0, 27)
m(37, 0xa0, 0, 27, visible=False)
m(38, 0x04, 0, 22)
m(39, 0x0b, 0, 30)
m(40, 0xa1, 0, -1)
m(41, 0x04, 0, -1)
m(42, 0xa0, 0, -1, fx='Status+0x7c/+0x80 = -10 (no more Void invasions)')
m(43, 0x0b, 0, 10)
m(44, 0x0b, 0, 10)
m(45, None, 0, None, visible=False, fx='empty Mission(); +40000 credits; Status+0x7c/+0x80 = -10 -> gameWon() (index > 44)')
m(46, 'keep', fx='default case: index only (transient, see Valkyrie start)')
m(47, 0x0b, 0, 74)
m(48, 0x0b, 0, 58, fx='own ship saved to Status+0x8c; loaner 9 H\'Soc (Vossk) with 58 D\'iol + 83 Hiroto Proscan')
m(49, 0x9c, 0, 58, fx='loaner 41 K\'Suukk (Vossk): 3x 177 Berger FlaK 9-9, 58, 83, 52 H\'Belam')
m(50, 0x9c, 0, 62)
m(51, 0x9c, 0, 25)
m(52, 0xa0, 0, 25, visible=False)
m(53, 'skip', fx='never reached: case 0x34 loops, 52 -> 54 directly')
m(54, 0x0b, 200000, 74)
m(55, 0x0b, 0, 101, fx='system 23 (Herjaza) visible; own ship restored from Status+0x8c')
m(56, 0x04, 0, 102, fx='own ship saved; loaner 39 S\'Kanarr (Vossk): 181 Skuld AT XR turret, 52, 58, 83')
m(57, 0x0b, 150000, 101)
m(58, 0xa6, 0, 101, goods=(179, 10), fx='blueprint 179 Liberator unlocked (+127 Microchips x5 at 101); own ship restored')
m(59, 0xa3, 0, 101, value=0, fx='Status+0x90 = [56, 45, 22] (freighter targets); blueprint 179 locked; Status+0x10c = 0')
m(60, 0x0b, '50000 + 50000*v', 101, value='v > 0', fx='v = statusValue of the index-59 mission')
m(61, 0xa4, 0, 101)
m(62, 0x0b, 0, 100, fx='system 22 (Beidan) visible')
m(63, 0x04, 0, 103, fx='system 24 (Skavac) visible')
m(64, 0x04, 0, 104)
m(65, 0x0b, 0, 100)
m(66, 0x0b, 0, 101)
m(67, 0x04, 0, 104, value=0, fx='current station gets 5x each of mines 60, 61, 62')
m(68, 0x08, 0, 66, goods=(175, 1))
m(69, 0x06, 0, 66, fx='Void Essence removed')
m(70, 0x06, 0, 65)
m(71, 0x0b, 0, 66)
m(72, 0xa4, 150000, 101, fx='blueprint 183 Disruptor Laser unlocked; +1 175 Void Essence; Status+0x10c = 0')
m(73, 0x0a, 0, 81)
m(74, 0x0b, 0, 100)
m(75, 0x0b, 0, 100, fx='Station::removeShips (current station)')
m(76, 0x0b, 0, 100)
m(77, 0x0b, 0, 101, fx='jump drive (sort 18) made unsaleable')
m(78, 0x04, 0, 101, fx='jump drive removed (equipment or cargo 85); blueprints of station 101 reset')
m(79, 0xa5, 0, -1)
m(80, 0x01, 0, 100)
m(81, 0x04, 0, -1)
m(82, 0x0b, 0, 100)
m(83, 0x0b, 0, 100)
m(84, None, 0, None, visible=False, fx='jump drive saleable again; +1 85 Khador Drive cargo; empty Mission() -> dlc1Won() (index > 83)')
m(85, 0xa4, 0, 0)
m(86, 0x0b, 0, 100)
m(87, 0x04, 0, 10)
m(88, 0x0b, 0, 10)
m(89, 0x04, 0, 109, fx='10x 104 Luxury removed; systems 27 (Ginoya), 28 (Talidor) visible')
m(90, 0x0b, 0, 10, fx='Status+0x1d0 (stations visited) -1; Galaxy visited[109] = 0')
m(91, 0xb8, 0, 110, value=10, goods=(0, 10), fx='systems 27/28 visible; Status+0x174 = 0')
m(92, 0xb8, 0, 113, value=10, goods=(0, 10))
m(93, 0x0b, 0, 114)
m(94, 0xb8, 0, 111, value=83, goods=(0, 83), fx='+1 205 Gamma Shield I cargo; Status+0x174 = 0')
m(95, 0xaa, 0, 10, value=0)
m(96, 0x0b, 0, 98)
m(97, 0x04, 0, 85)
m(98, 0x0b, 0, 120, fx='system 29 (Paraah) visible')
m(99, 0xaa, 0, 10, value=0)
m(100, 0x04, 0, 98)
m(101, 0x0b, 0, 98)
m(102, 0xb8, 0, 113, value=1700, goods=(0, 1700), fx='+1 207 Nirai SPP-C1 repair beam cargo')
m(103, 0x0b, 0, 10)
m(104, 0xa6, 0, 10, goods=(206, 1), fx='blueprint 206 Gamma Shield II unlocked (+163 Hypanium x10 at 10)')
m(105, 0x04, 0, 109)
m(106, 0x04, 0, 111)
m(107, 'keep', fx='no case 0x6a: default, index only (next step driven by the level)')
m(108, 0x0b, 0, 10)
m(109, 0xaa, 0, 114, value=0)
m(110, 0xab, 0, 10)
m(111, 0xab, 0, 38)
m(112, 0xac, 0, 38, goods=(146, 1))
m(113, 0xab, 0, 82, fx='146 Magnetar Juice removed')
m(114, 0x04, 0, 83)
m(115, 0xab, 0, 82)
m(116, 0xab, 0, 93, value=0, fx='statusValue = bitmask of searched lounges 90..94 (ModStation::OnUpdate)')
m(117, 0x0b, 0, 126, fx='system 30 (Me\'enkk) visible')
m(118, 0x08, 0, 126, goods=(209, 1))
m(119, 0xaa, 0, 10, value=0, fx='209 K\'mirkk Toad Mutagen made unsaleable')
m(120, 0x04, 0, 40)
m(121, 0x08, 0, 93, goods=(209, 1))
m(122, 0x0b, 0, 10, fx='mutagen saleable, then removed')
m(123, 0x04, 0, 121)
m(124, 0x0b, 0, 121)
m(125, 0x04, 0, 55)
m(126, 0xaa, 0, 120, value=0)
m(127, 0x0b, 0, 98)
m(128, None, 0, None, visible=False, fx='empty Mission() (wanted hunt: Pal Tyyrt); ModStation: Status::activateNewWanted')
m(129, 'skip', fx='never reached: case 0x80 loops, 128 -> 130 directly')
m(130, None, 0, None, visible=False, fx='empty Mission() (wanted hunt: Kehnor)')
m(131, 0x04, 0, 112)
m(132, 0x0b, 0, 112)
m(133, 0xaa, 0, 120, value=0)
m(134, 0x0b, 0, 22, value=0)
m(135, 0xae, 0, 103, value=0, goods=(155, 140))
m(136, 0x0b, 0, 112)
m(137, 0x04, 0, 58)
m(138, 0x0b, 0, 58)
m(139, 0xa8, 0, 131, value=10, fx='system 31 (Wah\'norr) visible; Status+0x174 = 0')
m(140, 0x0b, 0, 112)
m(141, 0x0b, 0, 78, fx='blueprint 210 Chromo Plasma unlocked, ingredients 201/202/203/204 plasma (847/834/861/892) at 112')
m(142, 0x04, 0, 79, fx='cargo +15 197 Ion Lambda Mk1, +1 196 Spectral Filter, +1 198 PE Proton')
m(143, 0x08, 0, 112, goods=(210, 1))
m(144, 0xaa, 0, 112, value=0, fx='210 Chromo Plasma removed')
m(145, 0x04, 0, 112)
m(146, 0x0b, 0, 112)
m(147, 0x04, 0, -1)
for _n in (148, 149, 150, 151):
    m(_n, 0xab, 0, 96)
m(152, 0xa5, 0, -1)
m(153, 0x0b, 0, 98)
m(154, 0x04, 0, -1)
m(155, 0xa4, 0, 0)
m(156, 0x0b, 0, 99)
m(157, 0x04, 0, 112)
m(158, 0x04, 0, 111)
m(159, 0x0b, 0, 10)
m(160, 0xaa, 0, 10)
m(161, 0xaa, 0, 93, value=0)
m(162, None, 0, None, visible=False, fx='empty Mission(): end of the Supernova story')

# Indices whose objective summary is shown only on "gameWon" etc. are handled in the doc; the milestone predicates:
GAME_WON = 45      # Status::gameWon 0x0b6832: index > 0x2c
DLC1_WON = 84      # Status::dlc1Won 0x0b8eda: index > 0x53
STORY_RADIO = (93, 111, 143)   # DAT_00252b00: Status+0x178 set when the index becomes one of these
CINEMATIC = (95, 99, 109, 119, 126, 133, 160, 161)   # LevelScript::LevelScript: invisible player, look-at camera


def row(n):
    t = T.get(n, {})
    typ = t.get('type')
    typs = ('0x%02x' % typ) if isinstance(typ, int) else (typ or '-')
    goods = t.get('goods')
    g = ''
    if goods:
        g = (item(goods[0]) if goods[0] else 'passengers') + ' x%d' % goods[1]
    brief = [p[1] for p in BRIEF[n]] if n < N_DIALOG else []
    succ = [p[1] for p in SUCC[n]] if n < N_DIALOG else []
    obj = OBJECTIVE[n] if n < 164 else None
    return dict(index=n, type=typs, station=st(t.get('station')) if isinstance(typ, int) else '-',
                reward=t.get('reward', 0), value=t.get('value'), goods=g, visible=t.get('visible', True),
                effects=t.get('effects', ''), objective=obj, brief=brief, success=succ)


def rng(ids):
    if not ids:
        return '-'
    return '%d-%d (%d)' % (ids[0], ids[-1], len(ids)) if len(ids) > 1 else str(ids[0])


def main():
    if len(sys.argv) > 2 and sys.argv[1] == 'dialog':
        n = int(sys.argv[2], 0)
        for name, pages in (('briefing', BRIEF[n]), ('success', SUCC[n])):
            print('--- %s (%d pages)' % (name, len(pages)))
            for sp, tid in pages:
                print('%5d  %-18s %s' % (tid, speaker(sp), TEXT[tid].replace('\r\n', ' ')))
        return
    if len(sys.argv) > 2 and sys.argv[1] == 'json':
        json.dump([row(n) for n in range(163)], open(sys.argv[2], 'w', encoding='utf-8'), indent=1)
        return
    print('| idx | type | target | reward | value / goods | objective text | briefing ids | success ids | effects |')
    print('|---|---|---|---|---|---|---|---|---|')
    for n in range(163):
        r = row(n)
        vg = ' '.join(str(x) for x in (r['value'], r['goods']) if x not in (None, ''))
        print('| %d | %s%s | %s | %s | %s | %s | %s | %s | %s |' % (
            n, r['type'], '' if r['visible'] else ' (hidden)', r['station'], r['reward'] or '', vg,
            r['objective'], rng(r['brief']), rng(r['success']), r['effects']))


if __name__ == '__main__':
    main()
