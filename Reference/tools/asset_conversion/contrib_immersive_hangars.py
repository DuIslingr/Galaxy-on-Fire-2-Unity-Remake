"""Contributed models -> the game's FBX files (run with Blender: blender -b --python contrib_immersive_hangars.py [-- outdir]).

Reference/contrib/immersive_hangars (Blender OBJ exports, 2026-10-06): the Midorian hangar extended into a whole room (its props
copied around the new floor, a third row of pads) and station_078_midorian's hangar mouth. They replace the converted originals in
Assets/Models/main (same files, so the .meta GUIDs, the per-mesh prefabs and the assemblies keep working; the old geometry is
no longer in the project). Written the way aem2fbx.py writes a mesh: an empty '<base>' with '<base>_partN' mesh children, one
material '<base>', the same FBX export settings.

The OBJs are the Unity-imported meshes at 1/5 scale, mirrored on x: Unity = 5 * (-x, y, z) + offset, normals (-x, y, z), UVs as
they are. Each hangar file was moved on its own before export (1.3-1.6 m against the others); the offsets put the vertices each
file kept from the original exactly back in place (shell 4717 of them, alpha 230, add 80, every prop set; the station unmoved).
Unity's import of these FBX (ImportSettings 0.05, ModelOrientationPostprocessor's 180 deg yaw) gives Unity = 0.05 * (bx, bz, by)
for Blender coordinates b, so b = (Ux, Uz, Uy) / 0.05. The two mirrors (OBJ -> Unity, Unity -> Blender) cancel: the OBJ's own
triangle order stays front-facing. Vertices are split by normal (the OBJs are welded: a double-sided panel's back face shared its
front's vertices); degenerate and repeated triangles are left out (Blender's validate would drop them, and the custom normals
would no longer line up with the loops: Unity then made its own).
Fixed on the way: one triangle of the station's new hangar-mouth panel faced inward (half the panel was culled from outside).
"""
import os, sys
import bpy

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '../../..'))
SRC = os.path.join(ROOT, 'Reference/contrib/immersive_hangars')
OUT = sys.argv[sys.argv.index('--') + 1] if '--' in sys.argv and len(sys.argv) > sys.argv.index('--') + 1 else os.path.join(ROOT, 'Assets/Models/main')

SCALE = 5.0
UNITY_PER_BLENDER = 0.05
PROPS = (-200.75001, 52.14999, 398.85145)
H = 'hangars_modified/'
S = 'stations_modified/'

# fbx (under OUT) -> its parts in order; a part = the OBJ pieces (file, object or None = all, offset) merged into one mesh.
FILES = {
    'hangars/hangar_midorian': [[(H + 'hangar_midorian_modified.obj', None, (-202.31689, 51.90917, 398.05086))]],
    'hangars/hangar_midorian_add': [[(H + 'hangar_midorian_add_modified.obj', None, (-202.01978, 52.28171, 398.34997))]],
    # Two parts like the original: the forcefield, then the light shafts and the rest (they sort as separate transparent meshes).
    'hangars/hangar_midorian_alpha': [[(H + 'hangar_midorian_alpha_modified.obj', 'hangar_midorian_alpha_WELDED', (-202.35563, 51.8, 398.14996))],
                                      [(H + 'hangar_midorian_alpha_modified.obj', 'hangar_midorian_alpha.001_WELDED', (-202.35563, 51.8, 398.14996))]],
    'stations/station_078_midorian': [[(S + 'station_78_midorian_modified.obj', None, (0, 0, 0))]],
    'stations/station_078_midorian_emissive': [[(S + 'station_78_midorian__emissive_x1_modified.obj', None, (0, 0, 0)),
                                                (S + 'station_78_midorian__emissive_x2_modified.obj', None, (0, 0, 0))]],
}
for k in range(1, 7):
    FILES[f'hangars/hangar_midorian_x{k}'] = [[(H + f'hangar_midorian_x{k}_modified.obj', None, PROPS)]]
    FILES[f'hangars/hangar_midorian_x{k}_shadow_alpha'] = [[(H + f'hangar_midorian_x{k}_shadow_alpha_modified.obj', None, PROPS)]]

# The panel's inward triangle: (5, 8, 11) with the back's normal; the rest of the front uses normal 18.
FACE_FIXES = {S + 'station_78_midorian__emissive_x2_modified.obj': {'5/8/9 8/20/9 11/7/9': '5/8/18 11/7/18 8/20/18'}}


def read_obj(rel, only, offset):
    """Corners of the triangles in Unity space: [(position, uv, normal)] * 3 per triangle, in the OBJ's order."""
    pos, tex, nrm, tris = [], [], [], []
    current = None
    fixes = FACE_FIXES.get(rel, {})
    for raw in open(os.path.join(SRC, rel), encoding='utf-8'):
        p = raw.split()
        if not p:
            continue
        if p[0] == 'o':
            current = p[1] if len(p) > 1 else None
        elif p[0] == 'v':
            x, y, z = map(float, p[1:4])
            pos.append((-x * SCALE + offset[0], y * SCALE + offset[1], z * SCALE + offset[2]))
        elif p[0] == 'vt':
            tex.append((float(p[1]), float(p[2])))
        elif p[0] == 'vn':
            x, y, z = map(float, p[1:4])
            nrm.append((-x, y, z))
        elif p[0] == 'f':
            if only is not None and current != only:
                continue
            body = ' '.join(p[1:])
            p = ['f'] + fixes.get(body, body).split()
            corners = []
            for c in p[1:]:
                i = c.split('/')
                corners.append((pos[int(i[0]) - 1],
                                tex[int(i[1]) - 1] if len(i) > 1 and i[1] else (0.0, 0.0),
                                nrm[int(i[2]) - 1] if len(i) > 2 and i[2] else None))
            for k in range(1, len(corners) - 1):   # a fan
                tris.append((corners[0], corners[k], corners[k + 1]))
    return tris


def to_blender(v):
    return (v[0] / UNITY_PER_BLENDER, v[2] / UNITY_PER_BLENDER, v[1] / UNITY_PER_BLENDER)


def build_part(name, tris, parent, mat):
    verts, index, loops, uvs, normals = [], {}, [], [], []
    seen = set()
    for tri in tris:
        # A vertex per position and normal: the OBJs are welded, and a double-sided panel's back face would otherwise share
        # its front's three vertices, which Blender drops as a repeated face.
        for p, _, n in tri:
            if (p, n) not in index:
                index[(p, n)] = len(verts)
                verts.append(to_blender(p))
        ids = tuple(index[(p, n)] for p, _, n in tri)
        if len({p for p, _, _ in tri}) < 3 or frozenset(ids) in seen:
            continue
        seen.add(frozenset(ids))
        for p, uv, n in tri:
            loops.append(index[(p, n)])
            uvs.append(uv)
            normals.append((n[0], n[2], n[1]) if n is not None else None)
    me = bpy.data.meshes.new(name)
    me.from_pydata(verts, [], [loops[i:i + 3] for i in range(0, len(loops), 3)])
    uvl = me.uv_layers.new(name='UVMap')
    for i, uv in enumerate(uvs):
        uvl.data[i].uv = uv
    me.validate(clean_customdata=False)
    me.update()
    if len(me.loops) != len(normals):
        raise RuntimeError(f'{name}: Blender dropped faces ({len(me.loops)} loops for {len(normals)} corners)')
    if all(n is not None for n in normals):
        me.normals_split_custom_set(normals)
    me.materials.append(mat)
    ob = bpy.data.objects.new(name, me)
    bpy.context.scene.collection.objects.link(ob)
    ob.parent = parent
    return ob


def convert(rel, parts):
    base = os.path.basename(rel)
    bpy.ops.wm.read_factory_settings(use_empty=True)
    mat = bpy.data.materials.new(base)
    root = bpy.data.objects.new(base, None)
    bpy.context.scene.collection.objects.link(root)
    for i, pieces in enumerate(parts):
        tris = []
        for obj, only, offset in pieces:
            tris += read_obj(obj, only, offset)
        build_part(f'{base}_part{i}', tris, root, mat)
    out = os.path.join(OUT, rel + '.fbx')
    os.makedirs(os.path.dirname(out), exist_ok=True)
    bpy.ops.export_scene.fbx(filepath=out, use_selection=False, apply_scale_options='FBX_SCALE_ALL',
                             axis_forward='-Z', axis_up='Y', bake_space_transform=True,
                             object_types={'EMPTY', 'MESH'}, use_mesh_modifiers=False,
                             mesh_smooth_type='OFF', add_leaf_bones=False, bake_anim=False,
                             colors_type='LINEAR', path_mode='STRIP')
    print('wrote', out, sum(len(p) for p in parts), 'piece(s)')


if __name__ == '__main__':
    for rel, parts in FILES.items():
        convert(rel, parts)
