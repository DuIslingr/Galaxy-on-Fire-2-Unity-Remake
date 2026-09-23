import json,os,collections
R=json.load(open('resources_raw.json'))
U='../unitypkg/Assets'
def rel(p):
    p=p[len('data/'):] if p.startswith('data/') else p
    return p.replace('assets/','',1) if p.startswith('assets/') else p
def mesh_path(p): return 'Models/'+os.path.splitext(rel(p).replace('3d/meshes/',''))[0]+'.fbx'
def tex_path(p): return 'Textures/'+os.path.splitext(rel(p).replace('3d/textures/low/etc/','').replace('3d/textures/',''))[0]+'.png'
SHADER={0:'unlit',1:'alpha',2:'additive',3:'additive_anim',6:'lit',8:'lit',10:'lit_alpha_test',18:'alpha_anim',28:'bump',34:'lit',36:'lit',4:'lit',24:'lit'}
byid={}
for r in R: byid.setdefault(r['id'],r)
tex={}; mats={}; meshes=[]; images=[]; missing=[]
for r in R:
    if r['kind']=='texture':
        up=tex_path(r['path']); tex[r['id']]=up
        if not os.path.exists(os.path.join(U,up)): missing.append(up)
for r in R:
    if r['kind']=='material':
        ts=[tex.get(t) for t in r['textures']]
        sh=r['shader'] if isinstance(r['shader'],int) and 0<=r['shader']<1000 else -1
        mats[r['id']]=dict(id=r['id'],shaderId=sh,shading=SHADER.get(sh,'lit'),textures=[t or '' for t in ts])
for r in R:
    if r['kind']=='mesh':
        up=mesh_path(r['path']); m=mats.get(r['material'])
        if not os.path.exists(os.path.join(U,up)): missing.append(up)
        meshes.append(dict(id=r['id'],model=up,source=r['path'],materialId=r['material'] if m else -1))
    elif r['kind']=='type3':
        tid=int.from_bytes(bytes.fromhex(r['raw'][:4]),'little')
        images.append(dict(id=r['id'],texture=tex.get(tid),textureId=tid))
out=dict(note='Recovered by emulating BuildResourceList() from libgof2hdaa.so. IDs are the game\'s own resource IDs.',
         meshes=meshes,materials=list(mats.values()),textures=[dict(id=k,path=v) for k,v in tex.items()],images2D=images)
json.dump(out,open(U+'/Resources/GoF2Data/resources.json','w'),indent=1)
print(len(meshes),len(mats),len(tex),len(images),'missing',len(set(missing)),sorted(set(missing))[:10])
print(collections.Counter(m['shading'] for m in mats.values()))
