import struct, numpy as np
class Buf:
    def __init__(s,b): s.b=b; s.o=0
    def read(s,n):
        if s.o+n>len(s.b): raise EOFError(f'need {n} at {s.o}/{len(s.b)}')
        v=s.b[s.o:s.o+n]; s.o+=n; return v
    def u8(s): return s.read(1)[0]
    def u16(s): return struct.unpack('<H',s.read(2))[0]
    def i16(s): return struct.unpack('<h',s.read(2))[0]
    def f32(s): return struct.unpack('<f',s.read(4))[0]
    def arr(s,dt,n): return np.frombuffer(s.read(np.dtype(dt).itemsize*n),dtype=dt).copy()

V2,V3,AE,V4,V5=1,2,4,8,16
def version(b):
    h=b[:7]
    for name,flag in ((b'V2AEMes',V2),(b'V3AEMes',V3),(b'V4AEMes',V4),(b'V5AEMes',V5)):
        if h==name: return flag
    if b[:6]==b'AEMesh': return AE
    raise ValueError('not an AEMesh: %r'%h)

def read_anim_block(r, kind):
    t=r.i16()
    out={'mode':t}
    if t==1:
        n=r.u16(); out['keys']=[(r.f32(),r.arr('<f4',3).tolist()) for _ in range(n)]
    elif t==0:
        ch=[]
        for c in range(3):
            n=r.u16(); ch.append([(r.f32(),r.f32()) for _ in range(n)])
        out['channels']=ch
    return out

def read_enhanced(r, ver):
    e={'bsphere':r.arr('<f4',4).tolist()}
    e['position']=read_anim_block(r,'pos')
    e['rotation']=read_anim_block(r,'rot')
    e['scale']=read_anim_block(r,'scale')
    if ver & (V4|V5):
        t=r.i16(); e['extra_mode']=t
        if t==2:
            n=r.u16(); e['extra']=[(r.f32(),r.f32()) for _ in range(n)]
    if ver & V5:
        n=r.u16(); chans=[]
        if n:
            for c in range(7):
                k=r.i16(); chans.append([(r.f32(),r.f32()) for _ in range(max(k,0))])
        e['v5channels']=chans
    return e

def read_mesh(r, ver, flags, depth=0):
    m={'flags':flags}
    enh = ver & (V3|V4|V5)
    if enh: m['pivot']=r.arr('<f4',3).tolist()
    if flags & 0x10:
        ni=r.u16(); m['indices']=r.arr('<u2',ni)
    nv=r.u16(); m['nv']=nv
    if ver & AE: m['pos']=r.arr('<i2',nv*3).astype(np.float32).reshape(-1,3)
    elif ver & (V2|V3): m['pos']=r.arr('<i4',nv*3).astype(np.float32).reshape(-1,3)
    else: m['pos']=r.arr('<f4',nv*3).reshape(-1,3)
    if flags & 2:
        if ver & (AE|V2|V3): m['uv']=(r.arr('<i2',nv*2).astype(np.float32)*(1/4096)).reshape(-1,2)
        else: m['uv']=r.arr('<f4',nv*2).reshape(-1,2)
    if flags & 4:
        if ver & (AE|V2|V3):
            n=r.arr('<i2',nv*3).astype(np.float32).reshape(-1,3)
            l=np.linalg.norm(n,axis=1,keepdims=True); l[l==0]=1; m['nrm']=n/l
        else: m['nrm']=r.arr('<f4',nv*3).reshape(-1,3)
    if flags & 8:
        if ver & (AE|V2|V3): m['col']=r.arr('u1',nv*4).astype(np.float32).reshape(-1,4)/255
        else: m['col']=r.arr('<f4',nv*4).reshape(-1,4)
    m['children']=[]
    if enh:
        try:
            m['anim']=read_enhanced(r,ver)
            nc=r.u16()
        except EOFError:
            m['anim']={}; m['truncated']=True; nc=0
        for _ in range(nc): m['children'].append(read_mesh(r,ver,flags,depth+1))
    return m

def load(path):
    b=open(path,'rb').read(); r=Buf(b); ver=version(b)
    r.read(7)
    if ver & (V2|V3|V4|V5): r.read(2)
    flags=r.u8()
    meshes=[]; truncated=False
    if ver & (V3|V4|V5):
        n=r.u16()
        for _ in range(max(n,1)):
            try: meshes.append(read_mesh(r,ver,flags))
            except EOFError:
                truncated=True; break
    else:
        meshes.append(read_mesh(r,ver,flags))
    return dict(version=ver,flags=flags,meshes=meshes,consumed=r.o,size=len(b),truncated=truncated)
