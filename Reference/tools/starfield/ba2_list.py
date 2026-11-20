import struct, sys, os
# BA2 (BTDX) name table lister: header magic(4) version(u32) type(4) fileCount(u32) nameTableOffset(u64)
def names(path):
    with open(path,'rb') as f:
        h=f.read(24)
        magic,ver,typ,count,nto=struct.unpack('<4sI4sIQ',h)
        assert magic==b'BTDX', path
        f.seek(nto)
        out=[]
        for i in range(count):
            n=struct.unpack('<H',f.read(2))[0]
            out.append(f.read(n).decode('latin1'))
        return ver,typ.decode(),count,out
for p in sys.argv[1:]:
    ver,typ,count,ns=names(p)
    base=os.path.basename(p)
    outp=os.path.join(os.environ['SP'],'lists',base+'.txt')
    os.makedirs(os.path.dirname(outp),exist_ok=True)
    open(outp,'w').write('\n'.join(ns))
    print(f'{base}: v{ver} {typ} {count} files')
