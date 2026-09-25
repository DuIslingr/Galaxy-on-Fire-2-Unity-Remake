"""Reference/research/fmod_event_ids.txt from the FEV's LGCY data (fev_lgcy.py): every event's system id (the id the game
passes to FModSound::play), name, group path and its wave files resolved to the converted .ogg under Assets/Audio (the
wave's bank = the folder, FMOD_GOF2_<folder>). Replaces the old name-order heuristic (off by one from 159 on)."""
import os, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import fev_lgcy as L

ROOT = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
AUDIO = os.path.join(ROOT, 'Assets', 'Audio')


def main():
    res = L.parse()
    folders = {f.lower(): f for f in os.listdir(AUDIO) if os.path.isdir(os.path.join(AUDIO, f))}
    by_name = {}   # lower basename -> [folder/file]
    for f in folders.values():
        for fn in os.listdir(os.path.join(AUDIO, f)):
            if fn.endswith('.ogg'):
                by_name.setdefault(fn[:-4].lower(), []).append(f + '/' + fn)
    def ogg(w):
        base = os.path.splitext(os.path.basename(w['file'].replace(chr(92), '/')))[0].lower()
        bank = res['banks'][w['bank']]['name']
        folder = bank[len('FMOD_GOF2_'):] if bank.startswith('FMOD_GOF2_') else bank
        hits = by_name.get(base, [])
        same = [h for h in hits if h.split('/')[0].lower() == folder.lower()]
        return (same or hits or ['?' + folder + '/' + base + '.ogg'])[0]
    out = ['# FMOD event system id (FModSound::play(id)) -> event name -> group -> .ogg files (Assets/Audio/...), from the FEV LGCY',
           '# data by Reference/tools/audio/build_event_table.py (fev_lgcy.py). "?" = no converted file of that name.']
    for fi in res['system_order']:
        e = res['events'][fi]
        defs = [e['sound']['sounddef']] if e['type'] == 'simple' else [s['sounddef'] for ly in e['layers'] for s in ly['sounds']]
        files = []
        for d in defs:
            for w in res['sounddefs'][d]['waves']:
                if w['type'] == 0:
                    f = ogg(w)
                    if f not in files:
                        files.append(f)
        out.append('%d\t0x%x\t%s\t%s\t%s' % (e['system_id'], e['system_id'], e['name'], e['group'], ' | '.join(files)))
    path = os.path.join(ROOT, 'Reference', 'research', 'fmod_event_ids.txt')
    open(path, 'w', encoding='utf-8', newline='\n').write('\n'.join(out) + '\n')
    print('%d events -> %s, %d unresolved files' % (len(out) - 2, path, sum(l.count('\t?') + l.count('| ?') for l in out[2:])))


if __name__ == '__main__':
    main()
