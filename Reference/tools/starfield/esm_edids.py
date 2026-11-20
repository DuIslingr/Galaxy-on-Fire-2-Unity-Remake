import struct, sys, zlib, collections
# Walk every record in an ESM, collect EDID per record type (zlib-compressed records: flag 0x40000).
WANT=set(sys.argv[2].split(',')) if len(sys.argv)>2 else None
def subrecords(data):
    i=0; xl=None
    while i+6<=len(data):
        sig=data[i:i+4]; sz=struct.unpack('<H',data[i+4:i+6])[0]; i+=6
        if sig==b'XXXX': xl=struct.unpack('<I',data[i:i+4])[0]; i+=4; continue
        if xl is not None: sz=xl; xl=None
        yield sig, data[i:i+sz]; i+=sz
def walk(f, end, out, counts):
    while f.tell()<end:
        h=f.read(24)
        if len(h)<24: return
        sig=h[:4]; size=struct.unpack('<I',h[4:8])[0]
        if sig==b'GRUP':
            walk(f, f.tell()+size-24, out, counts); continue
        flags=struct.unpack('<I',h[8:12])[0]; fid=struct.unpack('<I',h[12:16])[0]
        s=sig.decode('latin1'); counts[s]+=1
        if WANT is None or s not in WANT: f.seek(size,1); continue
        data=f.read(size)
        if flags&0x40000:
            dl=struct.unpack('<I',data[:4])[0]; data=zlib.decompress(data[4:])
        edid=None; full=None; anam=None
        for ssig,sd in subrecords(data):
            if ssig==b'EDID': edid=sd.rstrip(b'\0').decode('latin1')
            elif ssig==b'FULL': full=sd
            elif ssig==b'ANAM' and anam is None: anam=sd
        out[s].append((fid,edid,full.hex() if full else None, anam[:64] if anam else None))
path=sys.argv[1]
with open(path,'rb') as f:
    h=f.read(24); size=struct.unpack('<I',h[4:8])[0]; f.seek(size,1)
    f.seek(0,2); end=f.tell(); f.seek(24+size)
    out=collections.defaultdict(list); counts=collections.Counter()
    walk(f,end,out,counts)
print('COUNTS', dict(counts))
for k,v in out.items():
    print('==',k,len(v))
    for fid,e,fu,an in v: print(f'{fid:08x}\t{e}\t{fu}\t{an}')
