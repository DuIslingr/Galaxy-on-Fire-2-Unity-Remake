# Blueprint / ship-mod / Kaamo research helper (see Reference/research/blueprints_mods.md).
#   python Reference/tools/blueprints/blueprint_table.py          -> blueprint table, unlock sources, hidden wrecks,
#                                                                    ship mods, Kaamo tables (text)
#   python Reference/tools/blueprints/blueprint_table.py json OUT -> the same as JSON (the table a remake would ship)
#
# Ingredients/quantities come from items.bin (FileRead::loadItemsBinary 0x145f48: per item int[] ingredients,
# int[] quantities, int[] attributes), already decoded into Assets/Resources/GoF2Data/items.json ("blueprint").
# Constant tables are read from libgof2hdaa.so (needs `pip install pyelftools`); addresses use Ghidra base 0x10000.
import sys, os, json, struct

here = os.path.dirname(os.path.abspath(__file__))
root = os.path.join(here, '..', '..', '..')
D = os.path.join(root, 'Assets', 'Resources', 'GoF2Data')
ITEMS = json.load(open(os.path.join(D, 'items.json'), encoding='utf-8'))
AGENTS = json.load(open(os.path.join(D, 'agents.json'), encoding='utf-8'))
SHIPS = json.load(open(os.path.join(D, 'ships.json'), encoding='utf-8'))
SHIPS = SHIPS if isinstance(SHIPS, list) else SHIPS['ships']
STATIONS = {s['index']: s for s in json.load(open(os.path.join(D, 'stations.json'), encoding='utf-8'))}
TEXT = json.load(open(os.path.join(root, 'Assets', 'Localization', 'text_en.json'), encoding='utf-8'))

try:
    from elftools.elf.elffile import ELFFile
    _elf = ELFFile(open(os.path.join(here, '..', '..', 'binaries', 'libgof2hdaa.so'), 'rb'))
except Exception:  # pyelftools or the binary missing: fall back to the values recorded in the .md
    _elf = None


def ints(addr, n):
    if _elf is None:
        return None
    a = addr - 0x10000
    for s in _elf.iter_segments():
        if s['p_type'] == 'PT_LOAD' and s['p_vaddr'] <= a < s['p_vaddr'] + s['p_filesz']:
            return list(struct.unpack('<%di' % n, s.data()[a - s['p_vaddr']:a - s['p_vaddr'] + 4 * n]))


def floats(addr, n):
    if _elf is None:
        return None
    a = addr - 0x10000
    for s in _elf.iter_segments():
        if s['p_type'] == 'PT_LOAD' and s['p_vaddr'] <= a < s['p_vaddr'] + s['p_filesz']:
            return list(struct.unpack('<%df' % n, s.data()[a - s['p_vaddr']:a - s['p_vaddr'] + 4 * n]))


def item_name(i):
    return TEXT[1274 + i]


def station_name(s):
    return STATIONS.get(s, {}).get('name', '?')


# --- constant tables (value recorded in the .md as fallback) -------------------------------------------------------
HIDDEN_STATIONS = ints(0x25273c, 5) or [132, 133, 134, 129, 123]      # Station::stationHasHiddenBlueprint (= 0x259840)
HIDDEN_BLUEPRINTS = ints(0x2521f0, 5) or [226, 221, 223, 225, 227]    # PlayerEgo::update -> Status::unlockBluePrint
HIDDEN_WRECK_RACE = ints(0x253754, 5) or [1, 3, 2, 0, 2]              # Level::createMission createShip(race, 1, ship)
HIDDEN_WRECK_POS = floats(0x253768, 15) or [-20000, 30000, 80000, 40000, -30000, 100000, -80000, 80000, -90000,
                                            40000, 20000, 140000, 40000, 20000, 140000]
MOD_PRICE_PCT = ints(0x252090, 4) or [20, 30, 40, 20]                 # Agent::getModPricePercentage (else 40)
MOD_TEXT_VALUE = ints(0x254400, 8) or [0, 40, 1, 30, 2, 1, 3, 20]     # (mod, #N) pairs for texts 907-910
KAAMO_SHIPS = ints(0x251f40, 6) or [55, 56, 57, 58, 59, 60]           # Generator::createAgents offer 10
KAAMO_SPECIALS = ints(0x251d10, 9) or [200, 220, 208, 213, 216, 228, 229, 230, 231]  # offer 9

# Status::nextCampaignMission side effects (case = old index, the step reached = old + 1)
CAMPAIGN = {
    85:  dict(step=34, preInvested=[(164, 50)], station=10, note='50 Void Crystals removed from cargo and pre-invested'),
    179: dict(step=58, preInvested=[(127, 5)], station=101, note='also sold by agent 18 (Sao Perula); step 59 calls '
                                                                  'BluePrint::lock, which sets the unlocked flag (bug)'),
    183: dict(step=72, preInvested=[], station=None, note='+1 Void Essence (175) into cargo'),
    206: dict(step=104, preInvested=[(163, 10)], station=10, note='mission 0xa6: bring 1x Gamma Shield II to station 10'),
    210: dict(step=141, preInvested=[(201, 847), (202, 834), (203, 861), (204, 892)], station=112,
              note='remaining 83/96/69/38'),
}
VOLATILE = (204, 209)          # HangarWindow::OnTouchBegin: can't be shipped to the production station (text 289)
NEEDS_ROUTES = (210, 223)      # HangarWindow::setSellMode: start refused (528) in a system without gate routes


def base_quantity(it):
    return 10 if it['type'] == 'secondary' else 1          # BluePrint::BluePrint: getType == 1 -> 10


def mid_price(it):
    return (it['minPrice'] + it['maxPrice']) // 2          # Item::init: price = (min + max) / 2


def autocomplete_price(it, remaining=None):
    # BluePrint::getAutoCompletionPrice 0x1a64c8
    if it['index'] == 210:
        rem = remaining if remaining is not None else [i['amount'] for i in it['blueprint']]
        return 2000000 + sum(r * mid_price(ITEMS[i['item']]) for r, i in zip(rem, it['blueprint']))
    return int(float(base_quantity(it) * it['maxPrice']) * 1.25)


def unlock_sources(idx):
    out = []
    for a in AGENTS:
        if a['sellBlueprint'] == idx:
            out.append('agent %d %s @ %d %s, %d$' % (a['index'], a['name'], a['station'], station_name(a['station']),
                                                     a['sellItemPrice']))
    if idx in CAMPAIGN:
        c = CAMPAIGN[idx]
        pre = ', '.join('%dx %s' % (n, item_name(i)) for i, n in c['preInvested'])
        out.append('campaign step %d%s' % (c['step'], (' (pre-invested %s at %d %s)' % (pre, c['station'],
                                                                                     station_name(c['station'])))
                                            if pre else ''))
    if idx in HIDDEN_BLUEPRINTS:
        k = HIDDEN_BLUEPRINTS.index(idx)
        out.append('hidden wreck at station %d %s (hacking game)' % (HIDDEN_STATIONS[k], station_name(HIDDEN_STATIONS[k])))
    if idx == 232:
        out.append('all gold medals + all Supernova medals (ModStation::checkHints, text 651)')
    return out


def table():
    rows = []
    for it in ITEMS:
        if not it['blueprint']:
            continue
        ing_value = sum(i['amount'] * mid_price(ITEMS[i['item']]) for i in it['blueprint'])
        rows.append(dict(
            item=it['index'], name=item_name(it['index']), type=it['type'], category=it['category'],
            baseQuantity=base_quantity(it),
            ingredients=[dict(item=i['item'], name=item_name(i['item']), amount=i['amount'],
                              isBlueprintProduct=bool(ITEMS[i['item']]['blueprint']),
                              volatile=i['item'] in VOLATILE) for i in it['blueprint']],
            autocompletePrice=autocomplete_price(it),
            ingredientValueAtMidPrice=ing_value,
            productMaxPrice=it['maxPrice'] * base_quantity(it),
            needsGateRoutes=it['index'] in NEEDS_ROUTES,
            unlock=unlock_sources(it['index'])))
    return rows


def hidden():
    return [dict(station=s, stationName=station_name(s), blueprint=b, blueprintName=item_name(b), wreckRace=r,
                 wreckShip=13 if k == 0 else 15, position=HIDDEN_WRECK_POS[k * 3:k * 3 + 3], radioText=3156 + k)
            for k, (s, b, r) in enumerate(zip(HIDDEN_STATIONS, HIDDEN_BLUEPRINTS, HIDDEN_WRECK_RACE))]


def mods():
    names = ['armor +40 hp', 'cargo +30 t', '+1 equipment slot', 'handling +0.2 (shown +20)']
    value = dict(zip(MOD_TEXT_VALUE[0::2], MOD_TEXT_VALUE[1::2]))
    out = []
    for m in range(4):
        a = [x for x in AGENTS if x['sellMod'] == m][0]
        out.append(dict(mod=m, effect=names[m], pricePercentOfShip=MOD_PRICE_PCT[m], textN=value[m],
                        offerText=907 + m, agent=a['index'], agentName=a['name']))
    return out


def main():
    if len(sys.argv) > 2 and sys.argv[1] == 'json':
        json.dump(dict(blueprints=table(), hiddenBlueprints=hidden(), shipMods=mods(),
                       kaamoShips=KAAMO_SHIPS, kaamoSpecialItems=KAAMO_SPECIALS), open(sys.argv[2], 'w'), indent=1)
        print('wrote', sys.argv[2])
        return
    print('== Blueprints (Status+0x18, one per item with ingredients; %s) ==' %
          ('constants from libgof2hdaa.so' if _elf else 'constants from fallback values'))
    for r in table():
        print('\n%3d %s [%s, %s] x%d  autocomplete %s$  ingredients@mid %s$  product max %s$%s' % (
            r['item'], r['name'], r['type'], r['category'], r['baseQuantity'], format(r['autocompletePrice'], ','),
            format(r['ingredientValueAtMidPrice'], ','), format(r['productMaxPrice'], ','),
            '  [needs gate routes]' if r['needsGateRoutes'] else ''))
        for i in r['ingredients']:
            print('      %4d x %3d %s%s%s' % (i['amount'], i['item'], i['name'],
                                          '  (blueprint product)' if i['isBlueprintProduct'] else '',
                                          '  (volatile)' if i['volatile'] else ''))
        for u in r['unlock']:
            print('      unlock: ' + u)
    print('\n== Hidden blueprints (Supernova wrecks) ==')
    for h in hidden():
        print('  station %d %-10s -> %d %-20s wreck createShip(race %d, kind 1, ship %d) at %s, radio text %d' % (
            h['station'], h['stationName'], h['blueprint'], h['blueprintName'], h['wreckRace'], h['wreckShip'],
            h['position'], h['radioText']))
    print('\n== Ship mods (Ship::addMod; sellers at Kaamo 108) ==')
    for m in mods():
        print('  mod %d %-26s price %d%% of the current ship  (#N %d, text %d)  agent %d %s' % (
            m['mod'], m['effect'], m['pricePercentOfShip'], m['textN'], m['offerText'], m['agent'], m['agentName']))
    print('\n== Kaamo ==')
    print('  ship dealer (agent 26) ships:', ', '.join('%d %s' % (s, TEXT[913 + s]) for s in KAAMO_SHIPS))
    print('  special items (agent 25):', ', '.join('%d %s' % (i, item_name(i)) for i in KAAMO_SPECIALS))


if __name__ == '__main__':
    main()
