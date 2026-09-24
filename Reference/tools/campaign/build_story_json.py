# Writes Assets/Resources/GoF2Data/story.json for the remake from the campaign tables decoded by
# campaign_flow_tables.py (Status::nextCampaignMission cases, DialogueWindow page tables, MissionsWindow objective texts).
#   python Reference/tools/campaign/build_story_json.py
# One entry per campaign index 0..162:
#   index, type (-1 = empty mission), reward, station (-1 = none / any), value (statusValue), goodsItem / goodsAmount
#   (Mission::setProductionGoods; goodsItem 0 with an amount = passengers), visible, objectiveText (DAT_00258f68, -1 past
#   the table), briefing / success pages [{speaker, text}] (speaker name = text 1597 + speaker).
# The side effects of each step (loaner ships, items, systems...) are code in GoF2StoryEffects, not data.
import json, os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import campaign_flow_tables as C

root = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..'))
out = os.path.join(root, 'Assets', 'Resources', 'GoF2Data', 'story.json')

steps = []
for n in range(163):
    t = C.T.get(n, {})
    typ = t.get('type')
    goods = t.get('goods') or (-1, 0)
    pages = lambda tab: [dict(speaker=s, text=x) for s, x in tab[n]] if n < C.N_DIALOG else []
    steps.append(dict(
        index=n,
        type=typ if isinstance(typ, int) else -1,
        reward=t.get('reward', 0) or 0,
        station=t.get('station') if isinstance(t.get('station'), int) else -1,
        value=t.get('value') if isinstance(t.get('value'), int) else 0,   # 13: 'missionCount+1' is set in code
        goodsItem=goods[0] if goods[0] is not None else -1,
        goodsAmount=goods[1],
        visible=bool(t.get('visible', True)),
        objectiveText=C.OBJECTIVE[n] if n < 164 else -1,
        briefing=pages(C.BRIEF),
        success=pages(C.SUCC),
    ))

json.dump(dict(steps=steps), open(out, 'w', encoding='utf-8'), indent=1)
print('wrote', out, len(steps), 'steps,', sum(len(s['briefing']) for s in steps), 'briefing pages,',
      sum(len(s['success']) for s in steps), 'success pages')
