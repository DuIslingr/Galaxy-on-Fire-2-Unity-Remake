# FMOD event system ids (FModSound::play(id) -> EventSystem::getEventBySystemID, ids < 0x8f5) -> event names,
# rebuilt from the string table (STRR chunk) of Assets/Audio/_FMOD_GOF2.fev.bytes.
#   python Reference/tools/dialogue/fev_events.py                 id <tab> name <tab> .ogg files (eng) for all events
#   python Reference/tools/dialogue/fev_events.py --check         validate against the text->voice table 0x255210
#   python Reference/tools/dialogue/fev_events.py --voice-table   text id -> sound id -> event name -> file (1504 rows)
#   python Reference/tools/dialogue/fev_events.py --json out.json
# Model: STRR lists event, group and parameter names in project (depth-first) order, followed by sound-definition /
# wave names (from '/Atmo_Hangar_FX/...' on). The system id of an event = number of event names before it.
#   group     = all-caps name without digits (VOICE, STORY, GENERIC, DLC, TURRET, ...) that is not an .ogg stem
#   parameter = starts lower-case ('loop', 'time', 'param00', 'drill_speed', ...) or in PARAMS
#   event     = everything else (all voice events are named like their .ogg file: MISSION_11_0, RADIO_0_3, ...)
# Verified: every text->sound pair of Globals::getDialogueSoundId's table (0x255210) whose event name can be derived
# from the dialogue / radio tables lands on exactly that name (see --check).
import sys, os, re, struct, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from binary import ROOT, ints
AUDIO = os.path.join(ROOT, 'Assets', 'Audio')
# capitalised parameter names (found by aligning with the anchors in research/fmod_event_ids.txt)
PARAMS = {'SpawnIntensity', 'Vertical', 'Horizontal', 'Loop', 'Whoosh_Loop_Speed_Param'}


def strr():
    b = open(os.path.join(AUDIO, '_FMOD_GOF2.fev.bytes'), 'rb').read()
    off = 12
    # walk RIFF -> LIST PROJ -> chunks
    def chunks(o, end):
        while o + 8 <= end:
            cid = b[o:o + 4]; sz = struct.unpack('<I', b[o + 4:o + 8])[0]
            yield cid, o + 8, sz
            o += 8 + sz + (sz & 1)
    for cid, o, sz in chunks(12, len(b)):
        if cid == b'LIST':
            for c2, o2, s2 in chunks(o + 4, o + sz):
                if c2 == b'STRR':
                    d = b[o2:o2 + s2]
                    n = struct.unpack('<I', d[:4])[0]
                    offs = struct.unpack('<%dI' % n, d[4:4 + 4 * n])
                    base = 4 + 4 * n
                    return [d[base + x:d.index(b'\0', base + x)].decode('latin1') for x in offs]
    raise SystemExit('no STRR chunk')


def ogg_index():
    idx = {}
    for d in sorted(os.listdir(AUDIO)):
        p = os.path.join(AUDIO, d)
        if os.path.isdir(p):
            for f in os.listdir(p):
                if f.endswith('.ogg'):
                    idx.setdefault(f[:-4], []).append(d + '/' + f)
    return idx


def events():
    s = strr()
    oggs = ogg_index()
    end = next(i for i, x in enumerate(s) if x.startswith('/'))
    ev = []
    for i, x in enumerate(s[:end]):
        if i == 0 or x in ('_eng', '_deu'):
            continue
        if x in oggs:
            ev.append(x)
        elif re.fullmatch(r'[A-Z_]+', x):
            continue            # group
        elif (x[:1].islower() and x != 'game_over') or x in PARAMS:
            continue            # parameter
        else:
            ev.append(x)
    return ev, oggs


# ids 656..659 are 4 events whose names are not in STRR (duplicate names are stored once); every later id is
# shifted by 4. Anchors: Nivelian generic voices (<= 655, offset 0) and Terran-female ones (>= 660, offset 4) in
# Globals::getDialogueSoundId 0xfa110, plus all story voices (163..548 offset 0, 1123..2237 offset 4).
GAP_START, GAP = 656, 4


_LGCY = None


def name_of(sid, ev):
    """The event name of a system id: from the LGCY data (tools/audio/fev_lgcy.py, exact), else the name-order guess below
    (ids 656-659 missing, drifting from 2255 on)."""
    global _LGCY
    if _LGCY is None:
        try:
            sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', 'audio'))
            import fev_lgcy
            _LGCY = [n for _, n, _, _ in fev_lgcy.ids_table(fev_lgcy.parse())]
        except Exception:
            _LGCY = []
    if _LGCY:
        return _LGCY[sid] if 0 <= sid < len(_LGCY) else None
    return name_of_by_order(sid, ev)


def name_of_by_order(sid, ev):
    if sid < GAP_START:
        return ev[sid] if sid < len(ev) else None
    if sid < GAP_START + GAP:
        return None
    return ev[sid - GAP] if sid - GAP < len(ev) else None


def voice_table():
    w = ints(0x255210, 0xbc0)
    return [(w[i], w[i + 1]) for i in range(0, len(w), 2)]


def check():
    import dialogue_tables as D, radio_tables as R
    ev, _ = events()
    name = {}
    for m in range(162):
        for k, (sp, t) in enumerate(D.brief(m)):
            name.setdefault(t, set()).add('MISSION_%d_%d' % (m, k))
        for k, (sp, t) in enumerate(D.success(m)):
            name.setdefault(t, set()).add('MISSION_END_%d_%d' % (m, k))
    for m, r in R.table().items():
        for k, x in enumerate(r['messages']):
            name.setdefault(x['text'], set()).add('RADIO_%d_%d' % (m, k))
    ok = bad = unknown = 0
    for t, sid in voice_table():
        exp = name.get(t)
        got = name_of(sid, ev)
        if not exp:
            unknown += 1
        elif got in exp:
            ok += 1
        else:
            bad += 1
            print('mismatch text %d sound %d -> %s, expected %s' % (t, sid, got, sorted(exp)))
    print('events %d; voice pairs ok %d, mismatch %d, not derivable %d' % (len(ev), ok, bad, unknown))


def main(a):
    ev, oggs = events()
    if '--check' in a:
        check()
    elif '--voice-table' in a:
        for t, sid in voice_table():
            n = name_of(sid, ev) or '?'
            print('%d\t%d\t%s\t%s' % (t, sid, n, ' | '.join(f for f in oggs.get(n, []) if '_deu/' not in f)))
    elif '--json' in a:
        json.dump([{'id': i, 'name': n, 'files': oggs.get(n, [])} for i, n in enumerate(ev)],
                  open(a[a.index('--json') + 1], 'w'), indent=1)
    else:
        for i, n in enumerate(ev):
            print('%d\t%s\t%s' % (i, n, ' | '.join(f for f in oggs.get(n, []) if '_deu/' not in f)))


if __name__ == '__main__':
    main(sys.argv[1:])
