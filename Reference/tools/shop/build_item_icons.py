# Build Reference/research/item_icons.json: shop icons for every item / ship + the shop UI images.
# Image ids: ImageFactory::getItemImageId (0x141ab0) = (idx < 176 ? 2200 : 3824) + idx;
#            ImageFactory::drawShip (0x141b38)     = 2417 + shipIdx.
# Atlas/rect: atlas.rect(id) (resource table record -> region list of the loaded resolution variant).
#   python Reference/tools/shop/build_item_icons.py
import json, os, sys
here = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, here)
from atlas import rect, manifest, IMAGES
root = os.path.join(here, '..', '..', '..')
D = os.path.join(root, 'Assets', 'Resources', 'GoF2Data')
items = json.load(open(os.path.join(D, 'items.json'), encoding='utf-8'))
ships = json.load(open(os.path.join(D, 'ships.json'), encoding='utf-8'))
text = json.load(open(os.path.join(root, 'Assets', 'Localization', 'text_en.json'), encoding='utf-8'))
TYPE = {'primary': 0, 'secondary': 1, 'turret': 2, 'equipment': 3, 'commodity': 4}
# ImageFactory::reload 0x1415fc: Sprite frames [0x4fa, 0x4fb, 0x4f7, 0x4f8, 0x4f9, 0x4fc], frame = item type (ship = 5)
FRAME = [0x4fa, 0x4fb, 0x4f7, 0x4f8, 0x4f9, 0x4fc]
IPHONE4 = {'gof2_items.png': 'gof2_items_iphone4.png', 'gof2_items_2.png': 'gof2_items_iphone4_2.png',
           'gof2_interface.png': 'gof2_interface_iphone4.png'}


def variants(i):
    a, b = rect(i, True), rect(i, False)
    v = {'atlas': a[0], 'rect': a[1]}
    if b:
        v['base'] = {'atlas': b[0], 'rect': b[1]}
        iph = IPHONE4.get(b[0])
        if iph:
            tid, reg = IMAGES[i]
            v['iphone4'] = {'atlas': iph, 'rect': manifest(iph)['regions'][reg]}
    return v


out = {'note': 'GoF2 shop icons. atlas/rect = the variant the Android HD build loads on a >=1700x1080 screen '
               '(Globals::iPadLarge): items from gof2_items_ipad_large / gof2_items_ipad_2_large (178x86 cells), '
               'the item frames and several UI images re-bound to gof2_interface2_ipad_large, other UI from '
               'gof2_interface_iphone4. rect = [x, y, w, h] in pixels, top-left origin. base = 1x variant '
               '(gof2_items / gof2_interface, 58x28 item cells), iphone4 = 2x phone variant (116x56 item cells). '
               'Item icons are drawn on top of the frame image of their type (frameImageId), same top-left. '
               'See Reference/research/shop.md section 1.',
       'entries': []}
E = out['entries']
for it in items:
    i = it['index']; iid = (2200 if i < 176 else 3824) + i; t = TYPE[it['type']]
    e = {'kind': 'item', 'index': i, 'name': text[1274 + i], 'type': it['type'], 'imageId': iid}
    e.update(variants(iid)); e['frameImageId'] = FRAME[t]
    E.append(e)
for s in ships:
    i = s['index']; iid = 2417 + i
    e = {'kind': 'ship', 'index': i, 'name': text[913 + i], 'imageId': iid}
    e.update(variants(iid)); e['frameImageId'] = FRAME[5]
    E.append(e)
UI = [
    (FRAME[0], 'frame_primary', 'striped item background, red; under primary-weapon icons (ImageFactory frame 0)'),
    (FRAME[1], 'frame_secondary', 'orange; secondary weapons (frame 1)'),
    (FRAME[2], 'frame_turret', 'yellow; turrets (frame 2)'),
    (FRAME[3], 'frame_equipment', 'green; equipment (frame 3)'),
    (FRAME[4], 'frame_commodity', 'grey; commodities (frame 4)'),
    (FRAME[5], 'frame_ship', 'blue; ships (frame 5, ImageFactory::drawShip)'),
    (0x544, 'marker_new', 'orange plus: item never looked at (Status+0x54 flag unset), shop tab only (HangarWindow+0xec)'),
    (0x52e, 'marker_mounted', 'small dot: item mounted on the ship / ship has this equipment (HangarWindow+0xe8)'),
    (0x470, 'button_info', 'row button 0: opens the item details window (ListItemWindow), sound 0x61'),
    (0x532, 'button_mount', 'ship tab, cargo item: mount (sound 0x62)'),
    (0x533, 'button_demount', 'ship tab, mounted item: demount (sound 0x60)'),
    (0x475, 'progress_frame', 'blueprint completion bar frame'),
    (0x476, 'progress_fill', 'blueprint completion bar fill (drawn as a region, width = rate * w)'),
    (0x477, 'progress_cap', 'blueprint completion bar end cap'),
    (0x6ae, 'btn_sell_left_normal', 'TouchButton style 8 (row button 8, sell one = to station) left arrow piece, normal (iPad table 0x25c890)'),
    (0x6b0, 'btn_mid_normal', 'style 7/8/9 middle piece, normal'),
    (0x6b2, 'btn_right_normal', 'style 7/8 right piece, normal'),
    (0x6b3, 'btn_sell_left_pressed', 'style 8 left arrow piece, pressed'),
    (0x6b5, 'btn_mid_pressed', 'style 7/8/9 middle piece, pressed'),
    (0x6ad, 'btn_right_pressed', 'style 7/8 right piece, pressed'),
    (0x6b1, 'btn_left_normal', 'style 7/9 left piece, normal'),
    (0x6af, 'btn_buy_right_normal', 'style 9 (row button 9, buy one = to ship) right arrow piece, normal'),
    (0x6b6, 'btn_left_pressed', 'style 7/9 left piece, pressed'),
    (0x6b4, 'btn_buy_right_pressed', 'style 9 right arrow piece, pressed'),
    (0x465, 'tab_left', 'TouchButton style 3 (Ship / Shop / Blueprints tabs) left, normal'),
    (0x464, 'tab_mid', 'style 3 middle, normal'),
    (0x466, 'tab_right', 'style 3 right, normal'),
    (0x469, 'tab_left_pressed', 'style 3 left, pressed'),
    (0x468, 'tab_mid_pressed', 'style 3 middle, pressed'),
    (0x46a, 'tab_right_pressed', 'style 3 right, pressed'),
    (0x46d, 'tab_left_active', 'style 3 left, always-pressed (current tab)'),
    (0x46c, 'tab_mid_active', 'style 3 middle, current tab'),
    (0x46e, 'tab_right_active', 'style 3 right, current tab'),
    (0x2522, 'btn_credits_left', 'TouchButton style 0xb (credits button, footer) left, normal'),
    (0x2524, 'btn_credits_mid', 'style 0xb middle, normal'),
    (0x2526, 'btn_credits_right', 'style 0xb right, normal'),
]
for iid, name, use in UI:
    e = {'kind': 'ui', 'name': name, 'imageId': iid, 'use': use}
    e.update(variants(iid))
    E.append(e)
json.dump(out, open(os.path.join(root, 'Reference', 'research', 'item_icons.json'), 'w', encoding='utf-8'),
          ensure_ascii=False, indent=1)
print(len(E), 'entries')
