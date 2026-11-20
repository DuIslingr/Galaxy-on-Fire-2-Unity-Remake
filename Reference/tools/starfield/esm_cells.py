import struct, sys, zlib, collections, json
import os; sys.path.insert(0, os.path.dirname(os.path.abspath(sys.argv[0])))
from esm_blueprint import records  # noqa
idx=json.load(open(sys.argv[2]))
targets=[t.lower() for t in sys.argv[3].split(',')]
cells=collections.OrderedDict(); cur=None
for s,fid,subs,grp in records(sys.argv[1],{'CELL','REFR'}):
    if s=='CELL':
        edid=None
        for ss,sd in subs:
            if ss==b'EDID': edid=sd.rstrip(b'\0').decode('latin1')
        cur=edid or f'{fid:08x}'
        if any(t in cur.lower() for t in targets): cells[cur]=[]
        else: cur=None
    elif cur is not None:
        cells[cur].append(subs)
for c,refs in cells.items():
    print('CELL',c,len(refs),'refs')
    cnt=collections.Counter(); links=collections.Counter(); subsigs=collections.Counter()
    for subs in refs:
        base=None
        for ss,sd in subs:
            subsigs[ss.decode('latin1')]+=1
            if ss==b'NAME': base=struct.unpack('<I',sd)[0]
            elif len(sd)==4 and ss not in (b'NAME',):
                v=struct.unpack('<I',sd)[0]; e=idx.get(f'{v:08x}')
                if e and e[0] in ('PKIN','GBFM','MSTT','STAT'): links[(ss.decode('latin1'),e[0],e[1],e[2])]+=1
        e=idx.get(f'{base:08x}',('?',f'{base:08x}',None,[])) if base is not None else ('?',None,None,[])
        cnt[(e[0],e[1],e[2])]+=1
    print(' subrecord sigs:',dict(subsigs.most_common(25)))
    for (s,e,m),n in cnt.most_common(25): print(f'  {n:3} {s} {e} {m}')
    print(' links through 4-byte subrecords:')
    for (ss,s,e,m),n in links.most_common(60): print(f'  {n:3} {ss} -> {s} {e} {m}')
