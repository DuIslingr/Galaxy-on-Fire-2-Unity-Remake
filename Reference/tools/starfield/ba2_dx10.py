import struct, sys, os, zlib
# BTDX v3 DX10 extractor: writes a DDS (DX10 header) for one texture; LZ4 block decoder in pure Python.
def lz4_block(src, usz):
    dst=bytearray(); i=0; n=len(src)
    while i<n:
        tok=src[i]; i+=1; ll=tok>>4; ml=tok&15
        if ll==15:
            while True:
                b=src[i]; i+=1; ll+=b
                if b!=255: break
        dst+=src[i:i+ll]; i+=ll
        if i>=n: break
        off=src[i]|(src[i+1]<<8); i+=2
        if ml==15:
            while True:
                b=src[i]; i+=1; ml+=b
                if b!=255: break
        ml+=4; start=len(dst)-off
        for k in range(ml): dst.append(dst[start+k])
    return bytes(dst)
def dds_header(w,h,mips,dxgi,cube):
    flags=0x1|0x2|0x4|0x1000|0x20000|0x80000
    hdr=struct.pack('<4sIIIIIII',b'DDS ',124,flags,h,w,0,0,mips)+b'\0'*44
    hdr+=struct.pack('<II4sIIIII',32,4,b'DX10',0,0,0,0,0)
    caps2=0xFE00 if cube else 0
    hdr+=struct.pack('<IIIII',0x1000|0x400000|(0x8 if cube else 0),caps2,0,0,0)
    hdr+=struct.pack('<IIIII',dxgi,3,4 if cube else 0,1,0)
    return hdr
p,outdir=sys.argv[1],sys.argv[2]; subs=[s.lower() for s in sys.argv[3:]]
with open(p,'rb') as f:
    magic,ver,typ,count,nto=struct.unpack('<4sI4sIQ',f.read(24)); assert typ==b'DX10'
    f.seek(nto); names=[]
    for i in range(count):
        n=struct.unpack('<H',f.read(2))[0]; names.append(f.read(n).decode('latin1'))
    # find header size: v3 has 12 extra bytes
    for hdr in (24,32,36):
        f.seek(hdr); e=f.read(24); nchunks=e[13]; chunkhdrlen=struct.unpack('<H',e[14:16])[0]
        f.seek(hdr+24); c=f.read(24)
        if struct.unpack('<I',c[20:24])[0]==0xBAADF00D: break
    f.seek(32); comp=struct.unpack('<I',f.read(4))[0]
    print(f'v{ver} count={count} hdr={hdr} compression field={comp}')
    f.seek(hdr); ents=[]
    for i in range(count):
        e=f.read(24); nh,ext,dh,unk8,nchunks,chl,hgt,wid,mips,fmt,flags=struct.unpack('<I4sIBBHHHBBH',e)
        chunks=[struct.unpack('<QIIHHI',f.read(24)) for k in range(nchunks)]
        ents.append((hgt,wid,mips,fmt,flags,chunks))
    for n,(hgt,wid,mips,fmt,flags,chunks) in zip(names,ents):
        if subs and not any(s in n.lower() for s in subs): continue
        data=b''
        for off,psz,usz,m0,m1,al in chunks:
            f.seek(off); raw=f.read(psz if psz else usz)
            if psz:
                try: d=zlib.decompress(raw); how='zlib'
                except Exception: d=lz4_block(raw,usz); how='lz4'
            else: d=raw; how='raw'
            assert len(d)==usz,(n,len(d),usz); data+=d
        cube=bool(flags&0x1)
        o=os.path.join(outdir,n.replace('\\','/')); os.makedirs(os.path.dirname(o),exist_ok=True)
        open(o,'wb').write(dds_header(wid,hgt,mips,fmt,cube)+data)
        print('wrote',n,wid,'x',hgt,'mips',mips,'dxgi',fmt,'flags',hex(flags),how,len(data))
