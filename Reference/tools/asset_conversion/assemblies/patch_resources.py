# Adds the meshes that the BuildResourceList() emulation recorded wrongly back into resources.json.
#
# 19 mesh ids are registered by the game but came out of the emulator as garbage: 17 as "material"
# records (shader 0x61746164 = "data", i.e. a path string; the real materialId sits in textures[2])
# and 2 (11761/11762, supernova sun explosion) as "texture" records holding the .aem path.
# The id -> path mapping was confirmed from the disassembly (rules/aem_ids_from_disasm.json).
# 11761/11762 have no recoverable material; they get materialId -1.
#
#   python Reference/tools/asset_conversion/assemblies/patch_resources.py      (from the project root)
import json, os
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..', '..'))
RES = os.path.join(ROOT, 'Assets/Resources/GoF2Data/resources.json')
EMU = os.path.join(ROOT, 'Reference/decompiled/native/BuildResourceList_EMULATED_OUTPUT.json')
IDS = os.path.join(os.path.dirname(__file__), 'rules', 'aem_ids_from_disasm.json')

def model_path(src):
    p = src[len('data/'):] if src.startswith('data/') else src
    p = p.replace('assets/', '', 1).replace('3d/meshes/', '')
    return 'Models/' + os.path.splitext(p)[0] + '.fbx'

res = json.load(open(RES))
emu = {r['id']: r for r in json.load(open(EMU))}
path_by_id = {v: k for k, v in json.load(open(IDS)).items()}
have = {m['id'] for m in res['meshes']}
mats = {m['id'] for m in res['materials']}
added = []
for mid, src in sorted(path_by_id.items()):
    if mid in have: continue
    r = emu.get(mid)
    if r is None: continue
    if r['kind'] == 'material' and r.get('shader') == 0x61746164:
        mat = r['textures'][2]
    elif r['kind'] == 'texture' and r.get('path', '').endswith('.aem'):
        mat = -1
    else:
        continue
    model = model_path(src)
    if not os.path.exists(os.path.join(ROOT, 'Assets', model)): continue
    res['meshes'].append(dict(id=mid, model=model, source=src, materialId=mat if mat in mats else -1))
    added.append((mid, model, mat))

# Remake: the Valkyrie Vossk fighters' engine glows. Globals::getShipGroup skips the player's engine child for idx
# 0x27 / 0x29 (the game never registered 17939 / 17941), but the OBB has both meshes, mapped onto the right half of
# v_ship_engine_glow.png (its green Vossk glows): material 34815, like the other Valkyrie ships' glows (37 / 38 / 40).
REMAKE = [(17939, 'valkyrie/3d/meshes/ships/v_ship_039_vossk_engine_glow_add.aem', 34815),
          (17941, 'valkyrie/3d/meshes/ships/v_ship_041_vossk_engine_glow_add.aem', 34815)]
for mid, src, mat in REMAKE:
    if mid in have or any(m['id'] == mid for m in res['meshes']): continue
    src = 'data/assets/' + src
    model = model_path(src)
    if not os.path.exists(os.path.join(ROOT, 'Assets', model)): continue
    res['meshes'].append(dict(id=mid, model=model, source=src, materialId=mat if mat in mats else -1))
    added.append((mid, model, mat))

json.dump(res, open(RES, 'w'), indent=1)
for a in added: print(*a)
print(len(added), 'meshes added')
