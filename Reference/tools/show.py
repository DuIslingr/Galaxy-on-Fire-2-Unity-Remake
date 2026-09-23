# Print decompiled functions whose name matches a regex.
#   python Reference/tools/show.py "^PlayerFighter::update$" [maxchars]
import sys, re, os
here = os.path.dirname(os.path.abspath(__file__))
t = open(os.path.join(here, '..', 'decompiled', 'native', '_ALL_FUNCTIONS.c'), encoding='utf-8', errors='replace').read()
pat = re.compile(sys.argv[1]); lim = int(sys.argv[2]) if len(sys.argv) > 2 else 20000
for p in t.split('//@@FUNC\t')[1:]:
    if pat.search(p.split('\t')[0]):
        print('//@@', re.sub(r'\n\s*\n', '\n', p)[:lim])
