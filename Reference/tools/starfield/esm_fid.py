import struct, sys, zlib
want=set(int(x,16) for x in sys.argv[2:])
def subrecords(data):
    i=0; xl=None
    while i+6<=len(data):
        sig=data[i:i+4]; sz=struct.unpack('<H',data[i+4:i+6])[0]; i+=6
        if sig==b'XXXX': xl=struct.unpack('<I',data[i:i+4])[0]; i+=4; continue
        if xl is not None: sz=xl; xl=None
        yield sig, data[i:i+sz]; i+=sz
with open(sys.argv[1],'rb') as f:
    h=f.read(24); size=struct.unpack('<I',h[4:8])[0]; f.seek(size,1); f.seek(0,2); end=f.tell(); f.seek(24+size)
    while f.tell()<end and want:
        h=f.read(24)
        if len(h)<24: break
        sig=h[:4]; size=struct.unpack('<I',h[4:8])[0]
        if sig==b'GRUP': continue
        flags,fid=struct.unpack('<II',h[8:16])
        if fid not in want: f.seek(size,1); continue
        want.discard(fid); data=f.read(size)
        if flags&0x40000: data=zlib.decompress(data[4:])
        print('==',sig.decode(),f'{fid:08x}')
        for ss,sd in subrecords(data):
            txt=sd.rstrip(b'\0')
            show=txt.decode('latin1') if all(32<=c<127 for c in txt) and len(txt)>1 else sd[:24].hex()
            print('  ',ss.decode('latin1'),len(sd),show[:120])
