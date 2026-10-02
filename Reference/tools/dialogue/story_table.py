# One machine-readable table of the campaign's presentation data: dialogue pages, radio messages, speakers
# (name + portrait descriptor) and voice lines (FMOD event id -> event name -> .ogg per language).
#   python Reference/tools/dialogue/story_table.py --json out.json      (write it OUTSIDE Assets/ unless you mean to
#                                                                         import it; it quotes no text, only ids)
#   python Reference/tools/dialogue/story_table.py --summary            per-mission counts
# Sources: dialogue_tables.py (DialogueWindow tables), radio_tables.py (Level::createRadioMessages),
# portrait.py (speaker descriptors), fev_events.py (FEV event names), voice table 0x255210
# (Globals::getDialogueSoundId: text id -> FMOD event id, checked first for every line).
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import dialogue_tables as D, radio_tables as R, portrait as P, fev_events as F
from binary import text


def build():
    ev, oggs = F.events()
    voice = dict(F.voice_table())

    def vo(t):
        sid = voice.get(t)
        if sid is None:
            return None
        n = F.name_of(sid, ev)
        files = oggs.get(n, []) if n else []
        if n and not files:
            # Re-recorded lines keep the event name but their waves are named <event>_Alt2 (Brillo Lampeter's 11 Supernova
            # lines, MISSION_END_95_8_Alt2 ...); StoryAssets.Voice finds them by the event name too.
            files = next((oggs[k] for k in oggs if k.lower() in (n.lower() + '_alt2', n.lower() + '_alt')), [])
        return {'event': sid, 'name': n,
                'eng': next((f for f in files if '_eng/' in f), None),
                'deu': next((f for f in files if '_deu/' in f), None)}
    speakers = [{'id': s, 'nameText': 1597 + s, 'name': text(1597 + s), 'portrait': P.speaker(s)} for s in range(63)]
    missions = []
    radio = R.table()
    for m in range(D.N):
        b = [{'speaker': s, 'text': t, 'voice': vo(t)} for s, t in D.brief(m)]
        su = [{'speaker': s, 'text': t, 'voice': vo(t)} for s, t in D.success(m)]
        rm = []
        for k, x in enumerate(radio.get(m, {}).get('messages', [])):
            rm.append({'index': k, 'text': x['text'], 'speaker': x['image'], 'trigger': x['type'],
                       'param': x['param'], 'count': x['count'], 'voice': vo(x['text']) if isinstance(x['text'], int) else None})
        if b or su or rm:
            missions.append({'mission': m, 'briefing': b, 'success': su, 'radio': rm})
    broker = {k: [{'speaker': s, 'text': t, 'voice': vo(t)} for s, t in D.broker(big)]
              for k, big in (('purchase', False), ('firstVisit', True))}
    return {'speakers': speakers, 'missions': missions, 'homeBaseBroker': broker,
            'portraitParts': {'baseImageId': P.BASE_IDS, 'variantCount': P.COUNTS,
                              'offsetsHD': P.offsets('large'), 'background': 0x485, 'frame': 0x511},
            'radioTriggerTypes': {str(k): v for k, v in R.TYPES.items()} if hasattr(R, 'TYPES') else {}}


def main(a):
    t = build()
    if '--json' in a:
        json.dump(t, open(a[a.index('--json') + 1], 'w'), indent=1)
    else:
        nv = sum(1 for m in t['missions'] for k in ('briefing', 'success', 'radio') for p in m[k] if p['voice'])
        np_ = sum(1 for m in t['missions'] for k in ('briefing', 'success', 'radio') for p in m[k])
        for m in t['missions']:
            print('mission %3d  briefing %2d  success %2d  radio %2d' % (m['mission'], len(m['briefing']),
                                                                     len(m['success']), len(m['radio'])))
        print('%d missions with content, %d lines, %d voiced' % (len(t['missions']), np_, nv))


if __name__ == '__main__':
    main(sys.argv[1:])
