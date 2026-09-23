# Image-id -> atlas rect helpers for the GoF2 2D image table.
# The resource table (BuildResourceList, emulated) stores each Image2D as (textureId, regionIndex) in
# the first 4 bytes of its record; the region list itself is stored in the .aei of every resolution
# variant (Assets/Textures/_texture_manifest.json "regions", [x, y, w, h], top-left origin).
import json, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
here = os.path.dirname(os.path.abspath(__file__))
root = os.path.join(here, '..', '..', '..')
_man = {e['png'].split('/')[-1]: e for e in json.load(open(os.path.join(root, 'Assets', 'Textures', '_texture_manifest.json')))}
_res = json.load(open(os.path.join(root, 'Assets', 'Resources', 'GoF2Data', 'resources.json'), encoding='utf-8'))
_tex = {t['id']: t['path'].split('/')[-1] for t in _res['textures']}
_emu = json.load(open(os.path.join(root, 'Reference', 'decompiled', 'native', 'BuildResourceList_EMULATED_OUTPUT.json')))
IMAGES = {}
for e in _emu:
    if e['type'] == 3:
        b = bytes.fromhex(e['raw'])
        IMAGES[e['id']] = (int.from_bytes(b[0:2], 'little'), int.from_bytes(b[2:4], 'little'))
# Base texture (as registered for the non-retina build) -> variant loaded on Android HD with a
# >= 1700x1080 screen (Globals::iPadLarge = retinaDisplay = iPad = 1, iPadHD = 0), see shop.md 1.2.
LARGE = {
    'gof2_items.png': 'gof2_items_ipad_large.png',
    'gof2_items_2.png': 'gof2_items_ipad_2_large.png',
    'gof2_interface.png': 'gof2_interface_iphone4.png',
    'gof2_credits.png': 'gof2_credits_iphone4.png',
    'gof2_interface3.png': 'gof2_interface3_ipad_large.png',
    'gof2_shop_button.png': 'gof2_shop_button_ipad_large.png',
    'gof2_dlc_interface.png': 'gof2_dlc_interface_ipad_large.png',
    'gof2_challenge_interface.png': 'gof2_challenge_interface_ipad_large.png',
}
# The iPad branch of BuildResourceList (taken on Android HD when iPadLarge) re-binds ~111 interface
# image ids to gof2_interface2_ipad_large.png (texture 0x274f) with AddResource calls that run before
# the common bulk list, so they win the first-match lookup in PaintCanvas::Image2DCreate.
import img_records as _R
IPAD_OVERRIDE = {i: r for a, i, t, r in _R.out if 0x12e304 <= int(a, 16) < 0x1314e2 and t == 0x274f}
def rect(image_id, large=True):
    """-> (png file name, [x, y, w, h]) or None"""
    if large and image_id in IPAD_OVERRIDE:
        png = 'gof2_interface2_ipad_large.png'
        return (png, _man[png]['regions'][IPAD_OVERRIDE[image_id]])
    if image_id not in IMAGES:
        return None
    tid, reg = IMAGES[image_id]
    png = _tex.get(tid)
    if png is None:
        return None
    if large:
        png = LARGE.get(png, png)
    regs = _man[png]['regions']
    return (png, regs[reg]) if reg < len(regs) else (png, None)
def manifest(png):
    return _man[png]
