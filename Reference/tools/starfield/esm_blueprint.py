import struct, sys, zlib, collections, json
# Index every record's (sig, edid, subrecords of interest); then dump a blueprint ship's cell: its REFRs' base forms.
def subrecords(data):
    i=0; xl=None
    while i+6<=len(data):
        sig=data[i:i+4]; sz=struct.unpack('<H',data[i+4:i+6])[0]; i+=6
        if sig==b'XXXX': xl=struct.unpack('<I',data[i:i+4])[0]; i+=4; continue
        if xl is not None: sz=xl; xl=None
        yield sig, data[i:i+sz]; i+=sz
def records(path, want):
    with open(path,'rb') as f:
        h=f.read(24); size=struct.unpack('<I',h[4:8])[0]; f.seek(size,1)
        f.seek(0,2); end=f.tell(); f.seek(24+size)
        stack=[(end,None)]
        while f.tell()<end:
            while f.tell()>=stack[-1][0] and len(stack)>1: stack.pop()
            h=f.read(24)
            if len(h)<24: break
            sig=h[:4]; size=struct.unpack('<I',h[4:8])[0]
            if sig==b'GRUP':
                label=h[8:12]; gtype=struct.unpack('<i',h[12:16])[0]
                stack.append((f.tell()+size-24,(label,gtype))); continue
            flags=struct.unpack('<I',h[8:12])[0]; fid=struct.unpack('<I',h[12:16])[0]
            s=sig.decode('latin1')
            if s not in want: f.seek(size,1); continue
            data=f.read(size)
            if flags&0x40000: data=zlib.decompress(data[4:])
            yield s,fid,list(subrecords(data)),stack[-1][1]
mode=sys.argv[1]
if mode=='index':  # build fid -> (sig, edid, model) for non-REFR records
    out={}
    for p in sys.argv[2:]:
        for s,fid,subs,grp in records(p,{'GBFM','MSTT','STAT','PKIN','COBJ','CELL','ACTI','CONT','FURN','LIGH','MISC','WEAP','DOOR','TERM'}):
            edid=model=None; comps=[]
            for ss,sd in subs:
                if ss==b'EDID': edid=sd.rstrip(b'\0').decode('latin1')
                elif ss==b'MODL' and model is None: model=sd.rstrip(b'\0').decode('latin1')
                elif ss==b'BFCB': comps.append(sd.rstrip(b'\0').decode('latin1'))
            out[f'{fid:08x}']=(s,edid,model,comps)
    json.dump(out,open(sys.argv[2]+'.index.json','w'))
    print(len(out),'indexed')
elif mode=='cells':  # BlueprintShips: for each CELL its edid, and all REFRs under it with base fid + position
    idx=json.load(open(sys.argv[3]))
    cells=collections.OrderedDict(); cur=None
    for s,fid,subs,grp in records(sys.argv[2],{'CELL','REFR'}):
        if s=='CELL':
            edid=None
            for ss,sd in subs:
                if ss==b'EDID': edid=sd.rstrip(b'\0').decode('latin1')
            cur=edid or f'{fid:08x}'; cells[cur]=[]
        else:
            base=pos=None
            for ss,sd in subs:
                if ss==b'NAME': base=struct.unpack('<I',sd)[0]
                elif ss==b'DATA' and len(sd)>=24: pos=struct.unpack('<6f',sd[:24])
            cells[cur].append((f'{base:08x}' if base is not None else None,pos))
    target=sys.argv[4].lower()
    for c,refs in cells.items():
        if target in c.lower():
            print('CELL',c,len(refs),'refs')
            cnt=collections.Counter()
            for b,pos in refs:
                e=idx.get(b,('?',b,None,[])); cnt[(e[0],e[1],e[2])]+=1
            for (s,e,m),n in cnt.most_common(80): print(f'  {n:3} {s} {e} {m}')
    print('cells total',len(cells), 'sample:', list(cells)[:12])
