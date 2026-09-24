# Writes Assets/Resources/GoF2Data/story.json for the remake from the campaign tables decoded by
# campaign_flow_tables.py (Status::nextCampaignMission cases, DialogueWindow page tables, MissionsWindow objective texts).
#   python Reference/tools/campaign/build_story_json.py
# One entry per campaign index 0..162:
#   index, type (-1 = empty mission), reward, station (-1 = none / any), value (statusValue), goodsItem / goodsAmount
#   (Mission::setProductionGoods; goodsItem 0 with an amount = passengers), visible, objectiveText (DAT_00258f68, -1 past
#   the table), briefing / success pages [{speaker, text}] (speaker name = text 1597 + speaker).
# Also, from Reference/tools/dialogue/story_table.py (dialogue_cutscenes.md):
#   pages get 'voice' (the .ogg name, '' = silent; German files are the same name with 'de_' in the _deu folder),
#   speakers [{portrait: [body, part0..3], layers: [{key, anchor, y}]}] (index = speaker id; layers in draw order, key =
#   the part texture's name without _ipad_large, resolved through the image ids like portrait.py: bodies 11 / 12 do not
#   follow the body_part_variant naming), portraitOffsets[body][part] = [anchor 16 top / 32 bottom, y],
#   radio[index] = [{text, speaker, trigger, param, count, voice}] (Level::createRadioMessages per campaign index).
# The side effects of each step (loaner ships, items, systems...) are code in Story, not data.
import json, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'dialogue'))
import campaign_flow_tables as C
import story_table as ST
import portrait as PT

P = ST.build()
by_mission = {m['mission']: m for m in P['missions']}
def voice(v):
    return v['name'] if v and (v.get('eng') or v.get('deu')) else ''

root = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..'))
out = os.path.join(root, 'Assets', 'Resources', 'GoF2Data', 'story.json')

steps = []
for n in range(163):
    t = C.T.get(n, {})
    typ = t.get('type')
    goods = t.get('goods') or (-1, 0)
    pm = by_mission.get(n, {})
    vmap = {}
    for kind in ('briefing', 'success'):
        for pg in pm.get(kind, []):
            vmap[(kind, pg['text'])] = voice(pg.get('voice'))
    pages = lambda tab, kind: [dict(speaker=s, text=x, voice=vmap.get((kind, x), '')) for s, x in tab[n]] if n < C.N_DIALOG else []
    steps.append(dict(
        index=n,
        type=typ if isinstance(typ, int) else -1,
        reward=t.get('reward') if isinstance(t.get('reward'), int) else 0,   # 60: '50000 + 50000*v' is set in code
        station=t.get('station') if isinstance(t.get('station'), int) else -1,
        value=t.get('value') if isinstance(t.get('value'), int) else 0,   # 13: 'missionCount+1' is set in code
        goodsItem=goods[0] if goods[0] is not None else -1,
        goodsAmount=goods[1],
        visible=bool(t.get('visible', True)),
        objectiveText=C.OBJECTIVE[n] if n < 164 else -1,
        briefing=pages(C.BRIEF, 'briefing'),
        success=pages(C.SUCC, 'success'),
        radio=[dict(text=r['text'], speaker=r['speaker'], trigger=r['trigger'], param=r['param'], count=r.get('count', 1),
                    voice=voice(r.get('voice'))) for r in pm.get('radio', [])],
    ))

def layers(desc):
    out = []
    if not desc or desc[0] < 0:
        return out
    offs = PT.offsets('large')
    body = desc[0]
    for k in (2, 1, 0, 3):
        v = desc[k + 1]
        if v == -1 or PT.BASE_IDS[body][k] < 0:
            continue
        png, rect = PT.part_png(PT.BASE_IDS[body][k] + v, False)
        anchor, y = offs[body][k]
        out.append(dict(key=os.path.basename(png).replace('_ipad_large.png', ''), anchor=anchor, y=y))
    return out
speakers = [dict(portrait=sp['portrait'] or [-1, -1, -1, -1, -1], layers=layers(sp['portrait'])) for sp in P['speakers']]
offsets = [dict(parts=[dict(anchor=o[0], y=o[1]) for o in body]) for body in P['portraitParts']['offsetsHD']]
json.dump(dict(steps=steps, speakers=speakers, portraitOffsets=offsets), open(out, 'w', encoding='utf-8'), indent=1)
print('wrote', out, len(steps), 'steps,', sum(len(x['radio']) for x in steps), 'radio messages,', sum(len(s['briefing']) for s in steps), 'briefing pages,',
      sum(len(s['success']) for s in steps), 'success pages')
