import struct,json,os
D='obbdata/47947_GOF2CONTENT_ETC/assets/data/bin/'
class R:
    def __init__(s,p): s.b=open(p,'rb').read(); s.o=0
    def i(s): v=struct.unpack('>i',s.b[s.o:s.o+4])[0]; s.o+=4; return v
    def arr(s): n=s.i(); return [s.i() for _ in range(n)] if n>0 else []
    def str(s): n=struct.unpack('>H',s.b[s.o:s.o+2])[0]; s.o+=2; v=s.b[s.o:s.o+n].decode('utf8'); s.o+=n; return v
    def left(s): return len(s.b)-s.o
def lang(p):
    b=open(p,'rb').read(); o=0; out=[]
    while o+2<=len(b):
        n=struct.unpack('>H',b[o:o+2])[0]; o+=2; out.append(b[o:o+n].decode('utf8','replace')); o+=n
    return out
L=lang('x/apk/assets/gb.lang'); print('lang strings',len(L))
r=R(D+'ships.bin'); ships=[[r.i() for _ in range(9)] for _ in range(64)]; print('ships left',r.left()); print(ships[:5])
r=R(D+'items.bin'); items=[]
for k in range(233): items.append(dict(ingredients=r.arr(),quantities=r.arr(),attrs=r.arr()))
print('items left',r.left()); print(items[0]); print(items[100])
r=R(D+'systems.bin'); systems=[]
for k in range(34):
    systems.append(dict(name=r.str(),v=[r.i() for _ in range(8)],a0=[r.i() for _ in range(r.i())],a1=r.arr(),a2=r.arr(),a3=r.arr()))
print('systems left',r.left()); print(systems[0])
r=R(D+'stations.bin'); stations=[]
while r.left()>0: stations.append(dict(name=r.str(),v=[r.i() for _ in range(4)]))
print('stations',len(stations),stations[:3])
json.dump(dict(ships=ships,items=items,systems=systems,stations=stations),open('raw_parsed.json','w'))
json.dump(L,open('lang_gb.json','w'),ensure_ascii=False)
