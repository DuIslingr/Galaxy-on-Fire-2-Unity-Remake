import struct, json, os, glob
D='../obbdata/47947_GOF2CONTENT_ETC/assets/data/'
L=json.load(open('../lang_gb.json'))
class R:
    def __init__(s,p): s.b=open(p,'rb').read(); s.o=0; s.p=p
    def left(s): return len(s.b)-s.o
    def _u(s,fmt): n=struct.calcsize(fmt); v=struct.unpack(fmt,s.b[s.o:s.o+n]); s.o+=n; return v[0] if len(v)==1 else v
    def ib(s): return s._u('>i')      # ReadSwitched int (big-endian)
    def sb(s): return s._u('>h')      # ReadSwitched short
    def il(s): return s._u('<i')      # plain Read int (little-endian)
    def sl(s): return s._u('<h')
    def usl(s): return s._u('<H')
    def fl(s): return s._u('<f')
    def c(s): return s._u('b')
    def strb(s): n=s._u('>H'); v=s.b[s.o:s.o+n].decode('utf8','replace'); s.o+=n; return v
res={}; report={}
def done(name,r,obj): res[name]=obj; report[name]=dict(bytes=len(r.b),leftover=r.left())

r=R(D+'bin/agents.bin'); ag=[]
for _ in range(27):
    name=r.strb(); idx,station,system,race,male,sellSys,sellBp,sellMod,sellPrice=[r.ib() for _ in range(9)]
    a=dict(index=idx,name=name,station=station,system=system,race=race,raceName=L[406+race] if 0<=race<10 else None,male=male==1,
           sellItemSystem=sellSys,sellBlueprint=sellBp,sellMod=sellMod,sellItemPrice=sellPrice)
    n=r.ib()
    if n>0: a['portraitParts']=[r.c() for _ in range(5)]
    ag.append(a)
done('agents',r,ag)

r=R(D+'bin/wanted.bin'); wa=[]
for _ in range(25):
    name=r.strb(); v=[r.ib() for _ in range(13)]
    w=dict(index=v[0],name=name,board=v[1],race=v[2],raceName=L[406+v[2]] if 0<=v[2]<10 else None,male=v[3]==1,ship=v[4],weapon=v[5],hitpoints=v[6],
           loot=v[7],lootAmount=v[8],reward=v[9],requiredBounties=v[10],requiredMission=v[11],numWingmen=v[12])
    n=r.ib()
    if n>0: w['portraitParts']=[r.c() for _ in range(5)]
    wa.append(w)
done('wanted',r,wa)

names={}
for f in sorted(glob.glob(D+'bin/names_*.bin')):
    r=R(f); n=r.ib(); names[os.path.basename(f)[6:-4]]=[r.strb() for _ in range(n)]; report[os.path.basename(f)]=dict(bytes=len(r.b),leftover=r.left())
res['names']=names

r=R(D+'bin/ticker.bin'); tk=[]
for i in range(59):
    flag=r.ib(); bools=[r.il()!=0 for _ in range(4)]; a=r.ib(); b=r.ib()
    tk.append(dict(index=i,flag=flag!=0,conditions=bools,param1=a,param2=b))
done('ticker',r,tk)

r=R(D+'bin/shipparts.bin'); sp=[]
while r.left()>0:
    ship=r.c(); n=r.c(); parts=[]
    for _ in range(n):
        t=r.sb(); x,y,z=r.ib(),r.ib(),r.ib(); rest=[r.sb() for _ in range(6)]
        parts.append(dict(type=t,position=[x,y,z],values=rest))
    sp.append(dict(ship=ship-1,shipName=L[913+ship-1] if 0<ship<=64 else None,parts=parts))
done('shipparts',r,sp)

r=R(D+'bin/stationparts.bin'); st=[]
while r.left()>0:
    sid=r.c(); x=r.sb(); n=r.c(); parts=[]
    for _ in range(n):
        t=r.sb(); a,b,c=r.ib(),r.ib(),r.ib(); rest=[r.sb() for _ in range(3)]
        parts.append(dict(type=t,position=[a,b,c],values=rest))
    st.append(dict(station=sid-1,headerValue=x,parts=parts))
done('stationparts',r,st)

def collisions(path):
    r=R(path); out=[]
    while r.left()>=8:
        sid=r.il(); n=r.il()+1; out.append(dict(id=sid,values=[r.il() for _ in range(n)]))
    return r,out
for fn in ('collision','wreck_collisions','static_collisions','collision_test'):
    r,o=collisions(D+f'bin/{fn}.bin'); done(fn,r,o)
r,o=collisions(D+'assets/valkyrie/bin/v_collisions.bin'); done('v_collisions',r,o)

def weapons(path):
    r=R(path); out=[]
    while r.left()>=4:
        ship=r.sl(); n=r.sl(); ws=[]
        for _ in range(n):
            t=r.sl(); a,b,c=r.sl(),r.sl(),r.sl()
            w=dict(slotType=t,position_file=[a,b,c],position_engine=[a,c,-b])
            if t==3: w['turretAngles']=[r.fl(),r.fl(),r.fl()]
            ws.append(w)
        out.append(dict(ship=ship,shipName=L[913+ship] if 0<=ship<64 else None,mounts=ws))
    return r,out
for fn in ('weapons_hd','weapons_sd'):
    r,o=weapons(D+f'bin/{fn}.bin'); done(fn,r,o)
for f in sorted(glob.glob(D+'assets/*/bin/*_weapons.bin')):
    r,o=weapons(f); done(os.path.basename(f)[:-4],r,o)

def docks(path, header=True):
    r=R(path); out=[]
    while r.left()>=4:
        sid=r.usl(); n=r.usl(); pts=[]
        for _ in range(n):
            pid=r.usl(); p=[r.fl() for _ in range(3)]; rot=[r.fl() for _ in range(3)]; ex=[r.fl() for _ in range(3)]
            pts.append(dict(id=pid,position_file=p,position_engine=[p[0],p[2],-p[1]],rotationDeg_file=rot,extra=ex))
        out.append(dict(station=sid,points=pts))
    return r,out
for fn in ('docks_hd','docks'):
    r,o=docks(D+f'bin/{fn}.bin'); done(fn,r,o)
for f in sorted(glob.glob(D+'assets/*/bin/*docking_points*.bin')):
    r,o=docks(f); done(os.path.basename(f)[:-4],r,o)

os.makedirs('../unitypkg/Assets/GoF2/Data',exist_ok=True)
for k,v in res.items(): json.dump(v,open(f'../unitypkg/Assets/GoF2/Data/{k}.json','w'),ensure_ascii=False,indent=1)
json.dump(report,open('../unitypkg/Assets/GoF2/Data/_bin_decode_report.json','w'),indent=1)
for k,v in report.items(): print(k,v)
