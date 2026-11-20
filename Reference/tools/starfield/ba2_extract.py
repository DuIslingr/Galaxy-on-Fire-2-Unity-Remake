import struct, sys, os, zlib
# GNRL (BTDX v1/v2) extractor. Usage: ba2_extract.py <ba2> <outdir> <substring...>
def read_header(f):
    h=f.read(24); magic,ver,typ,count,nto=struct.unpack('<4sI4sIQ',h)
    extra=f.read(16); f.seek(24)
    # v2 has 8 extra header bytes, v3 12; detect by the first entry's align field 0xBAADF00D
    for hdr in (24,32,36):
        f.seek(hdr); e=f.read(36)
        if len(e)==36 and struct.unpack('<I',e[32:36])[0]==0xBAADF00D: return ver,typ.decode(),count,nto,hdr
    raise SystemExit('unknown header')
def entries(f,count,hdr):
    f.seek(hdr); out=[]
    for i in range(count):
        e=f.read(36); nh,ext,dh,flags,off,psz,usz,al=struct.unpack('<I4sIIQIII',e); out.append((off,psz,usz))
    return out
def names(f,count,nto):
    f.seek(nto); out=[]
    for i in range(count):
        n=struct.unpack('<H',f.read(2))[0]; out.append(f.read(n).decode('latin1'))
    return out
p,outdir=sys.argv[1],sys.argv[2]; subs=[s.lower() for s in sys.argv[3:]]
with open(p,'rb') as f:
    ver,typ,count,nto,hdr=read_header(f); print(f'v{ver} {typ} count={count} hdr={hdr}')
    ents=entries(f,count,hdr); ns=names(f,count,nto)
    for (off,psz,usz),n in zip(ents,ns):
        if subs and not any(s in n.lower() for s in subs): continue
        f.seek(off); d=f.read(psz if psz else usz)
        if psz: d=zlib.decompress(d)
        assert len(d)==usz,(n,len(d),usz)
        o=os.path.join(outdir,n.replace('\\','/')); os.makedirs(os.path.dirname(o),exist_ok=True); open(o,'wb').write(d); print('wrote',n,usz)
