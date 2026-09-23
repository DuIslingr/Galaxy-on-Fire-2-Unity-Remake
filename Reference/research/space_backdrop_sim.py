# Reproduces StarSystem::StarSystem (0x15c200) planet/sun layout and the Level::createSpace (0xbbba0) sky
# rotation for every station, using the engine RNG (AbyssEngine::AERandom == java.util.Random).
# Game units / radians. See space_backdrop.md. Usage: python Reference/research/space_backdrop_sim.py
import json, math, sys
import os
R=os.path.join(os.path.dirname(os.path.abspath(__file__)),'..','..','Assets','GoF2','Resources','GoF2Data')+os.sep
systems=json.load(open(R+'systems.json',encoding='utf-8'))
stations=json.load(open(R+'stations.json',encoding='utf-8'))
ST={s['index']:s for s in stations}
MASK=(1<<48)-1
class JR:
    def __init__(s,seed): s.s=(seed ^ 0x5DEECE66D)&MASK
    def next(s,b):
        s.s=(s.s*0x5DEECE66D+0xB)&MASK; r=s.s>>(48-b)
        return r-(1<<32) if r>=(1<<31) else r
    def nextInt(s,n):
        if n&-n==n: return (n*s.next(31))>>31
        while True:
            bits=s.next(31); val=bits%n
            if bits-val+(n-1) < (1<<31): return val
SUNTEX=['sun_000','sun_001','sun_002','sun_003','sun_004','sun_005','sun_006','sun_007','sun_008','sun_009','sun_010','sun_001','sun_008','sun_004','sun_000','sn_supernova','sun_007','sun_002','sun_006']
FLARE=[3,1,3,2,0,3,1,4,2,4,1,3,1,3,2,3,3,0,2,1,2,3,2,0,3,1,2,5,3,3,3,3,3,3]
SLOTTAB=[6]*12+[4]
RINGST={120,126,130,132}
TWO_PI=6.2831855
def ang(v): return v*1.52587890625e-05*TWO_PI
def dirOf(pitch,yaw):
    # local +Z of Rx(pitch)Ry(yaw); position = -20000*dir; light dir = -dir
    return (math.sin(yaw), -math.sin(pitch)*math.cos(yaw), math.cos(pitch)*math.cos(yaw))
def planetTexName(t,big):
    big_ids=[f'planet_{i:03d}_big' for i in range(20)]+['v_planet_020_big','v_planet_021_big','v_planet_022_big','planet_void_big','sn_planet_024_big','sn_planet_025_big','sn_planet_026_big']
    small=[f'planet_{i:03d}_small' for i in range(20)]+['v_planet_020_small','v_planet_021_small','v_planet_022_small','v_planet_022_small','sn_planet_024_small','sn_planet_025_small','sn_planet_026_small']
    return (big_ids if big else small)[t]
def sim(sysIdx, curSt, mission=1):
    sy=systems[sysIdx]; sts=sy['stations']
    rnd=JR(curSt*300)
    occ=[0]*24
    out=[]
    curTex=ST[curSt]['textureIndex']
    ringOrbit = curSt in RINGST
    sunSlot=None
    for u in range(len(sts)+1):
        if u==0:
            r=rnd.nextInt(14)
            k=curTex-9
            if 0<=k<13 and (0x1a31>>k)&1: slot=SLOTTAB[k]
            else:
                slot=r+5
                if curTex==22: slot=16
            occ[slot]=1; sunSlot=slot
            p=rnd.nextInt(4096)-2048
            out.append(dict(kind='sun',slot=slot,pitchRaw=p,pitch=ang(p),yaw=ang(slot*0xaaa),scale=0.2288818359375,flip=False,tex=SUNTEX[sy['textureIndex']]))
        else:
            st=sts[u-1]; t=ST[st]['textureIndex']
            if st==curSt:
                s=rnd.nextInt(20000)+20000
                if mission==0: s=int(s*0.5)
                if not ringOrbit:
                    if curTex<18:
                        b=1<<curTex
                        if b&0x21840: s=rnd.nextInt(15000)+35000
                        elif b&0x10200: s=rnd.nextInt(13000)+32500
                else: s=26000
                slot=0; occ[0]=1
                out.append(dict(kind='orbit',station=st,slot=0,pitchRaw=0,pitch=0.0,yaw=0.0,scale=s/65536,flip=sunSlot>=12,tex=planetTexName(t,True),ring=False))
            else:
                while True:
                    slot=rnd.nextInt(11)+7
                    if abs(slot-sunSlot)>=3 and not occ[slot]: break
                n=rnd.nextInt(40)
                sc=(n*0.01+0.800000011920929)*0.03509521484375
                flip = not (sunSlot-slot<12) or sunSlot<=slot
                occ[slot]=1
                p=rnd.nextInt(4096)-2048
                out.append(dict(kind='far',station=st,slot=slot,pitchRaw=p,pitch=ang(p),yaw=ang(slot*0xaaa),scale=sc,flip=flip,tex=planetTexName(t,False),ring=st in RINGST))
    return out
def skyRot(curSt):
    rnd=JR(curSt*2)
    return [ang(rnd.nextInt(0x10000)) for _ in range(3)]
if __name__=='__main__':
    rows=[]
    for sy in systems:
        for st in sy['stations']:
            o=sim(sy['index'],st)
            sun=o[0]; d=dirOf(sun['pitch'],sun['yaw']); L=tuple(-x for x in d)
            fog = sy['textureIndex'] in (17,18)
            rx,ry,rz = (0,0,0) if fog else skyRot(st)
            rows.append((sy['index'],st,o,L,(rx,ry,rz)))
    for a,b,o,L,r in rows:
        print(a,b,[ (x['kind'],x['slot'],round(math.degrees(x['pitch']),2),round(x['scale'],4),x['flip'],x['tex']) for x in o], [round(v,3) for v in L],[round(math.degrees(v),1) for v in r])
