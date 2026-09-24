# Space Lounge agent voices: SpaceLounge::getSoundId 0x19fdb4 + getSpecificSoundForRace 0x1a0080 -> FMOD event -> .ogg.
#   python Reference/tools/lounge/lounge_voices.py            category x race table with event ids and English files
#   python Reference/tools/lounge/lounge_voices.py --json f   the same as JSON ({category: {race_set: [{id, name, eng, deu}]}})
#   python Reference/tools/lounge/lounge_voices.py --check    verify every set is the 48-event LOUNGE block the offsets assume
#
# getSoundId picks a *base* id (Bobolan numbering, 759..806 = the 48 LOUNGE events of one race); getSpecificSoundForRace
# adds the race offset when base - 759 < 48 (race 6 Bobolan: no range check). Event names come from
# tools/dialogue/fev_events.py (system id -> name, with the 656..659 gap).
import sys, os, json
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', 'dialogue'))
import fev_events as F

BASE = 0x2f7          # 759
# voice set -> offset added to the base id (getSpecificSoundForRace); key = (race argument, male)
SETS = [('BOBOLAN', 0), ('GREY', 0x30), ('MULTIPOD', 0x60), ('NIVELIAN', 0x90), ('TERRAN_FEMALE', 0xc0),
        ('TERRAN_MALE', 0xf0), ('VOSSK', 0x120)]
# getSoundId categories: (label, first base id, count, when)
CATS = [
    ('seller', 0x2f7, 2, 'offers 2 item, 3 blueprint, 8 mod, 9 Kaamo special, 10 ship dealer'),
    ('challenge', 0x2fa, 4, 'offer 0, mission type 12 Challenge'),
    ('coordinates', 0x2fe, 2, 'offer 4 system coordinates'),
    ('delivery', 0x301, 4, 'offer 0, mission type 0 Courier or 11 Passenger'),
    ('diplomat', 0x305, 4, 'offer 7 diplomat'),
    ('fight', 0x309, 4, 'offer 0, any other mission type (50 %)'),
    ('special', 799, 4, 'offer 0, any other mission type (the other 50 %)'),
    ('purchase', 0x31b, 4, 'offer 5 wants to buy goods'),
    ('wingman', 0x323, 4, 'offer 6 wingmen'),
    ('generic', 0x30d, 2, 'offer 1 small talk; 30 % of all other offers; any agent whose offer was accepted; '
                          'the Kaamo ship dealer (offer 10) while the club is not owned (greeting only)'),
    ('generic_neg', 0x314, 2, 'small talk whose text is exactly 820 / 824 / 827 / 833 (the rude lines)'),
]


def load():
    ev, oggs = F.events()
    def files(n):
        # German banks store the same stems with a "de_" prefix (LOUNGE_deu/de_<NAME>.ogg)
        fs = oggs.get(n, []) + oggs.get('de_' + n, [])
        return ([f for f in fs if '_eng/' in f] or [None])[0], ([f for f in fs if '_deu/' in f] or [None])[0]
    return ev, files


def table():
    ev, files = load()
    out = {}
    for label, first, n, when in CATS:
        out[label] = {'when': when, 'base_ids': list(range(first, first + n)), 'sets': {}}
        for name, off in SETS:
            rows = []
            for b in range(first, first + n):
                sid = b + off
                nm = F.name_of(sid, ev)
                eng, deu = files(nm) if nm else (None, None)
                rows.append({'id': sid, 'name': nm, 'eng': eng, 'deu': deu})
            out[label]['sets'][name] = rows
    return out


def check():
    ev, files = load()
    ok = True
    for name, off in SETS:
        first = F.name_of(BASE + off, ev)
        last = F.name_of(BASE + off + 47, ev)
        good = first and first.startswith(name + '_GREETING_LOUNGE_BLUEPRINT_01') and last and \
            last.startswith(name + '_GREETING_LOUNGE_WINGMAN_04')
        ok &= bool(good)
        print('%-14s %4d..%4d  %s .. %s  %s' % (name, BASE + off, BASE + off + 47, first, last, 'ok' if good else 'MISMATCH'))
    print('all sets aligned' if ok else 'MISALIGNED')


def main(a):
    if '--check' in a:
        check()
        return
    t = table()
    if '--json' in a:
        json.dump(t, open(a[a.index('--json') + 1], 'w'), indent=1)
        return
    for label, c in t.items():
        print('%s  (base %s)  %s' % (label, c['base_ids'], c['when']))
        for name, rows in c['sets'].items():
            print('   %-14s %s' % (name, '  '.join('%d %s%s' % (r['id'], (r['name'] or '?').split('_LOUNGE_')[-1],
                                                           '' if r['eng'] else '(no eng)') for r in rows)))


if __name__ == '__main__':
    main(sys.argv[1:])
