import struct, sys
def load(path, lengthprefixed):
    d=open(path,'rb').read(); n,size=struct.unpack('<II',d[:8]); base=8+n*8; out={}
    for i in range(n):
        sid,off=struct.unpack('<II',d[8+i*8:16+i*8]); p=base+off
        if lengthprefixed:
            l=struct.unpack('<I',d[p:p+4])[0]; s=d[p+4:p+4+l]
        else:
            e=d.index(b'\0',p); s=d[p:e]
        out[sid]=s.rstrip(b'\0').decode('utf-8','replace')
    return out
if __name__=='__main__':
    st=load(sys.argv[1],False); print(len(st),'strings')
    # join: file with lines fid\tedid\tfullhex
    for line in open(sys.argv[2]):
        if line.startswith('COUNTS') or line.startswith('=='): continue
        fid,edid,full,an=line.rstrip('\n').split('\t')
        name=None
        if full and full!='None' and len(full)==8:
            sid=struct.unpack('<I',bytes.fromhex(full))[0]; name=st.get(sid)
        print(f'{edid}\t{name}')
