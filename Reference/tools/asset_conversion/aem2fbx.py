import sys, os, json, glob, traceback, time
import numpy as np, bpy
sys.path.insert(0, os.path.dirname(__file__))
import aem

D = os.path.abspath(os.path.join(os.path.dirname(__file__), '../obbdata/47947_GOF2CONTENT_ETC/assets/data'))
OUT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../unitypkg/Assets/Models'))

def reset():
    bpy.ops.wm.read_factory_settings(use_empty=True)

def to_blender(v):  # engine (GL, Y-up, right-handed) -> Blender (Z-up, right-handed)
    return np.stack([-v[:, 0], v[:, 2], v[:, 1]], axis=1)  # engine -Z forward -> Blender -Y -> Unity +Z

def build_object(sm, name, parent, mat):
    pos = to_blender(sm['pos'])
    nv = len(pos)
    idx = sm.get('indices')
    if idx is None or len(idx) == 0:
        idx = np.arange(nv - nv % 3, dtype=np.uint32)
    idx = np.asarray(idx, dtype=np.int64)
    idx = idx[: len(idx) - len(idx) % 3]
    valid = (idx < nv).all() if len(idx) else True
    if not valid:
        idx = idx[(idx.reshape(-1, 3) < nv).all(1).repeat(3)]
    tris = idx.reshape(-1, 3)
    me = bpy.data.meshes.new(name)
    if nv and len(tris):
        me.vertices.add(nv)
        me.vertices.foreach_set('co', pos.astype(np.float32).ravel())
        nt = len(tris)
        me.loops.add(nt * 3)
        me.loops.foreach_set('vertex_index', tris.ravel().astype(np.int32))
        me.polygons.add(nt)
        me.polygons.foreach_set('loop_start', (np.arange(nt) * 3).astype(np.int32))
        me.polygons.foreach_set('loop_total', np.full(nt, 3, np.int32))
        loop_v = tris.ravel()
        if 'uv' in sm:
            uv = me.uv_layers.new(name='UVMap')
            uv.data.foreach_set('uv', sm['uv'][loop_v].astype(np.float32).ravel())
        if 'col' in sm:
            ca = me.color_attributes.new(name='Col', type='FLOAT_COLOR', domain='POINT')
            ca.data.foreach_set('color', np.clip(sm['col'], 0, 1).astype(np.float32).ravel())
        me.validate(clean_customdata=False)
        me.update()
        if 'nrm' in sm and len(me.loops) == nt * 3:
            n = to_blender(sm['nrm'])
            ln = n[me.loops.values() and np.array([l.vertex_index for l in me.loops])] if False else None
            vi = np.empty(len(me.loops), np.int32); me.loops.foreach_get('vertex_index', vi)
            ln = n[vi]
            l = np.linalg.norm(ln, axis=1, keepdims=True); l[l == 0] = 1
            try:
                me.normals_split_custom_set((ln / l).tolist())
            except Exception:
                pass
    me.materials.append(mat)
    ob = bpy.data.objects.new(name, me)
    bpy.context.scene.collection.objects.link(ob)
    if parent is not None:
        ob.parent = parent
    return ob

def anim_json(sm):
    a = sm.get('anim', {})
    out = {}
    for k in ('position', 'rotation', 'scale'):
        v = a.get(k)
        if not v: continue
        if v.get('mode') == 1 and v.get('keys'):
            out[k] = {'mode': 'vector', 'keys': v['keys']}
        elif v.get('mode') == 0 and any(v.get('channels', [])):
            out[k] = {'mode': 'channels', 'channels': v['channels']}
    if a.get('extra'): out['extra'] = a['extra']
    if a.get('v5channels') and any(a['v5channels']): out['v5channels'] = a['v5channels']
    if a.get('bsphere'): out['bsphere'] = a['bsphere']
    return out

def convert(path):
    rel = os.path.relpath(path, D)
    rel = rel.replace('assets/', '', 1) if rel.startswith('assets/') else rel
    rel = rel.replace('3d/meshes/', '')
    base = os.path.splitext(os.path.basename(path))[0]
    out = os.path.join(OUT, os.path.splitext(rel)[0] + '.fbx')
    os.makedirs(os.path.dirname(out), exist_ok=True)
    m = aem.load(path)
    reset()
    mat = bpy.data.materials.new(base)
    root = bpy.data.objects.new(base, None)
    bpy.context.scene.collection.objects.link(root)
    meta = {'source': os.path.relpath(path, D), 'version': m['version'], 'flags': m['flags'],
            'parts': [], 'truncated': m.get('truncated', False)}
    counter = [0]
    def walk(sm, parent, depth):
        i = counter[0]; counter[0] += 1
        ob = build_object(sm, f'{base}_part{i}', parent, mat)
        meta['parts'].append({'name': ob.name, 'parent': parent.name if parent else None,
                              'vertices': int(sm['nv']), 'pivot': sm.get('pivot'),
                              'hasUV': 'uv' in sm, 'hasNormals': 'nrm' in sm, 'hasColors': 'col' in sm,
                              'animation': anim_json(sm)})
        for c in sm['children']:
            walk(c, ob, depth + 1)
    for sm in m['meshes']:
        walk(sm, root, 0)
    bpy.ops.export_scene.fbx(filepath=out, use_selection=False, apply_scale_options='FBX_SCALE_ALL',
                             axis_forward='-Z', axis_up='Y', bake_space_transform=True,
                             object_types={'EMPTY', 'MESH'}, use_mesh_modifiers=False,
                             mesh_smooth_type='OFF', add_leaf_bones=False, bake_anim=False,
                             colors_type='LINEAR', path_mode='STRIP')
    json.dump(meta, open(os.path.splitext(out)[0] + '.gof2mesh.json', 'w'))
    return out

if __name__ == '__main__':
    files = sorted(glob.glob(D + '/**/*.aem', recursive=True))
    if len(sys.argv) > 1 and sys.argv[1] != 'all':
        files = [f for f in files if any(s in f for s in sys.argv[1:])]
    log = []
    t0 = time.time()
    for i, f in enumerate(files):
        try:
            convert(f); log.append({'file': f, 'ok': True})
        except Exception as e:
            log.append({'file': f, 'ok': False, 'error': repr(e)}); traceback.print_exc()
        if i % 50 == 0: print(i, len(files), round(time.time() - t0), flush=True)
    json.dump(log, open(os.path.join(OUT, '_mesh_convert_log.json'), 'w'), indent=0)
    print('done', sum(l['ok'] for l in log), '/', len(log))
