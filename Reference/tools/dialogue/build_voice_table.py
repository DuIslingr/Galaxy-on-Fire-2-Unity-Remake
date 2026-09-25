# Globals::getDialogueSoundId's text -> voice table (0x255210, 1504 pairs) as event names, for the remake:
#   python Reference/tools/dialogue/build_voice_table.py   -> Assets/Resources/GoF2Data/voice_table.json
# {"items": [{"text": 443, "voice": "MSG_ENTER_NIVELIAN_SYSTEM_0"}, ...]}; the voice name is the .ogg stem the story
# assets index (StoryAssets.Voice). Rows whose sound id has no event name are left out. The per-race generic rules of
# getDialogueSoundId (no table entry) are in GenericVoice.cs.
import os, sys, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import fev_events as F
from binary import ROOT

ev, oggs = F.events()
items = []
for text, sid in F.voice_table():
    name = F.name_of(sid, ev)
    if name and name in oggs:
        items.append({'text': text, 'voice': name})
out = os.path.join(ROOT, 'Assets', 'Resources', 'GoF2Data', 'voice_table.json')
json.dump({'items': items}, open(out, 'w', encoding='utf-8'), indent=0)
print('%d of %d pairs -> %s' % (len(items), len(F.voice_table()), out))
