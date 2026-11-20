import struct, sys
# Top-level GRUP labels of a TES4-family ESM: record sig(4) size(u32) ... ; GRUP: 'GRUP' size(u32, incl header) label(4) type(i32) ...
# Starfield header size is 24 bytes (same as FO4).
def scan(path):
    with open(path,'rb') as f:
        hdr=f.read(24); sig=hdr[:4]; size=struct.unpack('<I',hdr[4:8])[0]
        f.seek(24+size)
        out=[]
        while True:
            h=f.read(24)
            if len(h)<24: break
            sig=h[:4]; size=struct.unpack('<I',h[4:8])[0]
            if sig==b'GRUP':
                label=h[8:12]; gtype=struct.unpack('<i',h[12:16])[0]
                out.append((label.decode('latin1'),size))
                f.seek(size-24,1)
            else:
                out.append((sig.decode('latin1')+'(rec)',size)); f.seek(size,1)
        return out
for p in sys.argv[1:]:
    print('==',p.split('/')[-1])
    for l,s in scan(p): print(f'{l:6} {s:>12,}')
