# Print English text ids:  python Reference/tools/shop/tx.py 173 265-290 0x109
import sys, json, os
here = os.path.dirname(os.path.abspath(__file__))
t = json.load(open(os.path.join(here, '..', '..', '..', 'Assets', 'Localization', 'text_en.json'), encoding='utf-8'))
for a in sys.argv[1:]:
    if '-' in a:
        lo, hi = [int(x, 0) for x in a.split('-')]
    else:
        lo = hi = int(a, 0)
    for i in range(lo, hi + 1):
        print(i, hex(i), repr(t[i]))
