import json
r=json.load(open('raw_parsed.json')); L=json.load(open('lang_gb.json'))
ATTR={0:'index',1:'type',2:'category',3:'techLevel',4:'lowestPriceSystem',5:'highestPriceSystem',6:'occurrence',7:'minPrice',8:'maxPrice',
 9:'damage',10:'empDamage',11:'loadingTimeMs',12:'range',13:'projectileSpeed',14:'magnitude',15:'steerable',16:'automatic',17:'handling',
 18:'shieldCapacity',19:'shieldRegenTime',20:'armor',21:'empDefense',22:'cargoBonus',23:'automatic_2',24:'timeToLock',
 25:'boostSpeed',26:'boostRechargeMs',27:'boostDurationMs',28:'agility',29:'timeToLock_2',30:'showClassAAsteroids',31:'radarShowsCargo',
 32:'handling_2',33:'miningYield',34:'cabinSize',35:'effect_35',36:'loadingSpeed_36',37:'loadingSpeed_37',38:'energyConsumption',
 39:'fireRateFactor',40:'damageFactor',41:'effect_41',42:'effect_42',43:'loadingSpeed_43',44:'range_44',45:'showOnRadar',46:'effect_46',
 47:'range_47',48:'cabinSize_48',49:'speed_49',50:'magnitude_50',51:'range_51',52:'gammaShielding',53:'range_53',54:'effect_54',
 55:'count',56:'effect_56',57:'showInfo',58:'showOnRadar_58',59:'plasmaConsumption',60:'raceSpecific_guess',61:'iconIndex_guess'}
TYPES=['primary','secondary','turret','equipment','commodity']
RACES={i:L[406+i] for i in range(10)}
items=[]
for idx,it in enumerate(r['items']):
    a=dict(zip(it['attrs'][::2],it['attrs'][1::2]))
    stats={ATTR.get(k,f'attr_{k}'):v for k,v in a.items() if k>=9}
    items.append(dict(index=idx,name=L[1274+idx],description=L[1041+idx],type=TYPES[a[1]],category=L[221+a[2]],categoryId=a[2],
        techLevel=a[3],occurrence=a[6],minPrice=a[7],maxPrice=a[8],lowestPriceSystem=a[4],highestPriceSystem=a[5],stats=stats,
        blueprint=[dict(item=i,name=L[1274+i],amount=q) for i,q in zip(it['ingredients'],it['quantities'])] or None,
        rawAttributes=a))
ships=[]
for s in r['ships']:
    i,hp,cargo,price,p,sec,tur,eq,hand=s
    ships.append(dict(index=i,name=L[913+i],description=L[977+i],armor=hp,cargo=cargo,price=price,
        slots=dict(primary=p,secondary=sec,turret=tur,equipment=eq),handling=hand,handlingMultiplier=hand/100))
systems=[]
for k,s in enumerate(r['systems']):
    v=s['v']
    systems.append(dict(index=k,name=s['name'],securityLevel=v[0],initiallyVisible=v[1]==1,race=RACES.get(v[2],v[2]),raceId=v[2],
        mapPosition=dict(x=v[3],y=v[4],z=v[5]),jumpgateStation=v[6],textureIndex=v[7],unknownTriple=s['a0'],
        stations=s['a1'],jumpRoutesTo=s['a2'],forbiddenGoodsOrUnknown=s['a3']))
stations=[dict(index=s['v'][0],name=s['name'],system=s['v'][1],systemName=systems[s['v'][1]]['name'] if 0<=s['v'][1]<len(systems) else None,
               techLevel=s['v'][2],textureIndex=s['v'][3]) for s in r['stations']]
for n,o in [('items',items),('ships',ships),('systems',systems),('stations',stations)]:
    json.dump(o,open(f'out/data/{n}.json','w'),ensure_ascii=False,indent=1)
json.dump(L,open('out/data/text_en.json','w'),ensure_ascii=False,indent=0)
print(len(items),len(ships),len(systems),len(stations))
print(json.dumps(items[0],ensure_ascii=False)[:600]); print(ships[0]); print(stations[0])
bp=[i for i in items if i['blueprint']]; print('blueprints',len(bp), bp[0]['name'], bp[0]['blueprint'])
