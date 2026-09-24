# Campaign dialogue pages from DialogueWindow::loadContent (0x194cd0) / length (0x195ca4) / init (0x194734).
#   python Reference/tools/dialogue/dialogue_tables.py                 table: mission -> briefing / success pages
#   python Reference/tools/dialogue/dialogue_tables.py --text          include the English text (local use only)
#   python Reference/tools/dialogue/dialogue_tables.py --json out.json machine-readable dump
#   python Reference/tools/dialogue/dialogue_tables.py --mission 1     one mission
# Tables (Ghidra addresses):
#   0x259ed0 int[162]  briefing word count per campaign mission (pages = count / 2)     hasBriefingDialogue 0x194c90
#   0x25a158 int[162]  success  word count per campaign mission                          hasSuccessDialogue  0x194cb0
#   0x25a3e0 int[]     briefing pages, (speaker, textId) pairs, concatenated in mission order
#   0x25a5c0 int[]     success pages, same layout
#   speaker -> portrait descriptor PTR 0x2647ec[speaker], name text 0x63d (1597) + speaker
#   home-base broker (non-campaign mission whose target station is 108): 0x25c680 (6 pages) or, when
#       Status+0x114 == 2, 0x25c5f0 (18 pages)
import sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from binary import ints, text
N = 162
BRIEF_LEN = ints(0x259ed0, N)
SUCC_LEN = ints(0x25a158, N)
def pages(table, lens, m):
    off = sum(lens[:m])
    w = ints(table + 4 * off, lens[m])
    return [(w[i], w[i + 1]) for i in range(0, lens[m], 2)]
def brief(m): return pages(0x25a3e0, BRIEF_LEN, m)
def success(m): return pages(0x25a5c0, SUCC_LEN, m)
def broker(big):
    return [tuple(ints((0x25c5f0 if big else 0x25c680) + 8 * i, 2)) for i in range(18 if big else 6)]
def fmt(p, show):
    s, t = p
    r = '    %2d %-18s %4d' % (s, text(1597 + s), t)
    if show:
        r += '  ' + (text(t) or '').replace('\r', '').replace('\n', ' / ')[:140]
    return r
def main(a):
    show = '--text' in a
    if '--json' in a:
        out = {'missions': [{'mission': m, 'briefing': brief(m), 'success': success(m)} for m in range(N)],
               'broker_small': broker(False), 'broker_big': broker(True),
               'speakers': {s: text(1597 + s) for s in range(63)}}
        json.dump(out, open(a[a.index('--json') + 1], 'w'), indent=1)
        return
    ms = [int(a[a.index('--mission') + 1])] if '--mission' in a else range(N)
    tb = ts = 0
    for m in ms:
        b, s = brief(m), success(m)
        tb += len(b); ts += len(s)
        if not b and not s:
            continue
        print('mission %d: briefing %d pages, success %d pages' % (m, len(b), len(s)))
        for p in b: print('  B' + fmt(p, show)[3:])
        for p in s: print('  S' + fmt(p, show)[3:])
    if '--mission' not in a:
        print('total briefing pages %d, success pages %d' % (tb, ts))
        print('home base broker (6 pages):'); [print(fmt(p, show)) for p in broker(False)]
        print('home base broker (18 pages, Status+0x114 == 2):'); [print(fmt(p, show)) for p in broker(True)]
if __name__ == '__main__':
    main(sys.argv[1:])
