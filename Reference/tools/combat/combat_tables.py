# Ship combat research helper (see Reference/research/ship_combat.md).
#   python Reference/tools/combat/combat_tables.py             -> image rects, NPC hull/damage tables, loot odds
#   python Reference/tools/combat/combat_tables.py crops DIR   -> also cuts every image into DIR (PNG, on a dark bg)
import sys, os, glob
here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(here, '..', 'shop'))
import atlas  # noqa: E402

IMAGES = [
    # Radar::Radar 0x1545e0 (ship markers, Radar::draw ship loop)
    (0x4cc, 'ship dot, enemy (red)            Radar+0x60'),
    (0x4cd, 'ship dot, friend (green)         Radar+0x68'),
    (0x4cb, 'ship dot, neutral (yellow)       Radar+0x78'),
    (0x4c8, 'ring, locked enemy               Radar+0x90 / +0x7c'),
    (0x4ca, 'ring, locked friend              Radar+0x94 / +0x80'),
    (0x4c9, 'ring, locked neutral             Radar+0x98 / +0x84'),
    (0x4db, 'bracket, locked enemy (near)     Radar+0x5c'),
    (0x4d2, 'bracket, locked friend (near)    Radar+0x64'),
    (0x4dc, 'bracket, locked neutral (near)   Radar+0x74'),
    (0x4f2, 'white bracket: crate / wreck near Radar+0x9c'),
    (0x4f1, 'small white dot: crate far       Radar+0xa0/+0xa4'),
    (0x451, 'off-screen crate marker          Radar+0xa8'),
    (0x44d, 'off-screen crate marker (void)   Radar+0xb4'),
    (0x44f, 'off-screen marker (KIPlayer+0x39 objects) Radar+0xb0'),
    (0x44c, 'Radar+0xac (not used in the ship loop)'),
    (0x4da, 'hull bar frame, enemy (red)      Radar+0xe0'),
    (0x4d9, 'hull bar fill, enemy             Radar+0xd0'),
    (0x4d3, 'hull bar frame, friend (green)   Radar+0xe4'),
    (0x4d4, 'hull bar fill, friend            Radar+0xd4'),
    (0x4d5, 'hull bar frame, neutral (yellow) Radar+0xe8'),
    (0x4d6, 'hull bar fill, neutral           Radar+0xd8'),
    (0x4d8, 'EMP bar frame                    Radar+0xec'),
    (0x4d7, 'EMP bar fill                     Radar+0xdc'),
    (0x456, 'lock ring, 24 frames 80x80       Radar+0xf4'),
    (0x4c4, 'top target plate                 Radar+0xcc'),
    # Hud::init 0x18cf20 (player status, hit indicators)
    (0x4ac, 'shield icon                      Hud+0x244'),
    (0x4ad, 'shield icon, hit (500 ms)        Hud+0x248'),
    (0x4a9, 'status row plate                 Hud+0x274'),
    (0x4ae, 'shield bar frame                 Hud+0x24c'),
    (0x4af, 'shield bar fill                  Hud+0x250'),
    (0x4aa, 'hull icon (armor > 0)            Hud+0x254'),
    (0x4ab, 'hull icon (no armor left)        Hud+0x258'),
    (0x4a7, 'hull/armor bar frame             Hud+0x25c'),
    (0x524, 'hull bar fill                    Hud+0x264'),
    (0x4a8, 'armor bar fill (over the hull)   Hud+0x260'),
    (0x1f59, 'gamma icon (supernova)          Hud+0x270'),
    (0x1f5a, 'gamma bar frame                 Hud+0x26c'),
    (0x1f5b, 'gamma bar fill                  Hud+0x268'),
    (0x52c, 'hit indicator side, shield up    Hud+0x30c'),
    (0x52b, 'hit indicator top/bottom, shield up Hud+0x308'),
    (0x526, 'hit indicator side, shield down  Hud+0x304'),
    (0x525, 'hit indicator top/bottom, shield down Hud+0x300'),
    (0x4c0, 'crosshair (PlayerEgo+0x23c)'),
    (0x4ce, 'crosshair, hit (PlayerEgo+0x240)'),
    (0x4a1, 'race icon 0 Terran'), (0x49c, 'race icon 1 Vossk'), (0x49f, 'race icon 2 Nivelian'),
    (0x49e, 'race icon 3 Midorian'), (0x4a0, 'race icon 8 Pirate'), (0x49d, 'race icon 9 Void'),
]

LEVEL_XP = [0, 7, 21, 42, 70, 105, 147, 196, 252, 315, 385, 462, 546, 637, 735, 840, 952, 1071, 1197, 1330, 1650]  # DAT_00252b0c

def npc_hull(level, campaign=0, game_won=False, difficulty=0.5, fixed=False, ship=-1):
    """Level::createShip 0xcf83c: hull HP of a generated NPC (no shield, no armor)."""
    lv = min(level, 20)
    hp = (180 if game_won else campaign * 4) + lv * 14 + 20
    if ship == 0x33: hp = int(hp * 1.7)
    elif ship == 0x31: hp = int(hp * 17.0)
    elif ship == 0x2c: hp = int(hp * 2.25)
    if fixed:                       # PlayerFixedObject (freighter, battleship)
        hp *= 25 if ship == 14 else 5
    return int(hp + hp * (difficulty - 0.5))

def npc_emp(level, fixed=False):
    e = min(level, 20) * 5 + 40
    return (e * 3, 45000) if fixed else (e, 15000)   # (EMP points, recovery ms)

def npc_gun_damage(level, difficulty=0.5, campaign=0):
    """Level::assignGuns 0xcb638: damage per NPC bullet (standard fighter gun)."""
    f = 0.9 * (level - 2)
    base = 20.0 if f >= 20 else (0.0 if f < 0 else float(int(f)))
    d = int(base + (difficulty - 0.5) * base)
    if d > 21: d = 22
    d = 3 if d == 0 else d + 2
    return 1 if campaign == 4 else d

def npc_gun_reload(campaign=0, game_won=False):
    return 600 - 2 * (0x2d if game_won else campaign)

LOOT_TYPE_PCT = [10, 40, 2, 10, 100, 10]  # DAT_00251e5c: per item type (0 primary, 1 secondary, 2 turret, 3 equipment, 4 commodity, 5 ?)

if __name__ == '__main__':
    for i, what in IMAGES:
        print('0x%x %-58s %s' % (i, str(atlas.rect(i)), what))
    print('\nlevel  XP   hull(normal) hull(hardcore)  gun dmg(normal/hardcore)  EMP')
    for lv in range(0, 21):
        print('%5d %5d %8d %12d %14d / %-6d %s' % (lv, LEVEL_XP[lv], npc_hull(lv), npc_hull(lv, difficulty=1.5),
              npc_gun_damage(lv), npc_gun_damage(lv, 1.5), npc_emp(lv)))
    print('\nloot type %% (Generator::getLootList):', LOOT_TYPE_PCT)
    if len(sys.argv) > 2 and sys.argv[1] == 'crops':
        from PIL import Image
        out = sys.argv[2]; os.makedirs(out, exist_ok=True)
        root = os.path.join(here, '..', '..', '..', 'Assets', 'Textures')
        cache = {}
        for i, _ in IMAGES:
            r = atlas.rect(i)
            if not r or not r[1]:
                continue
            png, rc = r
            p = glob.glob(os.path.join(root, '**', png), recursive=True)[0]
            if p not in cache:
                cache[p] = Image.open(p).convert('RGBA')
            im = cache[p].crop((rc[0], rc[1], rc[0] + rc[2], rc[1] + rc[3]))
            bg = Image.new('RGBA', im.size, (40, 40, 60, 255)); bg.alpha_composite(im)
            bg.save(os.path.join(out, '%x.png' % i))
