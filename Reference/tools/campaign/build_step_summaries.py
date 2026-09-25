"""build_step_summaries.py
Writes Assets/Resources/GoF2Data/step_summaries.json for the main menu's Admin mission list (remake-only): per story
step 0-162 a short title and a one-line summary, taken from the research notes:
  - summary: the description column of the step table in Reference/research/campaign_flow.md;
  - title:   the level heading in campaign_levels_a/b/c.md when the step has an in-space level ("Index 40 - ...",
             "Mission 102 (0x66) - ...", "3.17 0x9d (157) ..."), else empty (the menu then shows the target station).
Markdown emphasis and code quotes are stripped. Run from the repo root:  python Reference/tools/campaign/build_step_summaries.py
"""
import json
import os
import re

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..'))
RESEARCH = os.path.join(ROOT, 'Reference', 'research')
OUT = os.path.join(ROOT, 'Assets', 'Resources', 'GoF2Data', 'step_summaries.json')


def clean(s):
    s = s.replace('**', '').replace('`', '').replace('\\|', '|')
    s = re.sub(r'\s+', ' ', s).strip()
    return s.rstrip('.').strip()


def summaries():
    rows = {}
    pat = re.compile(r'^\| (\d+) \| [^|]* \| [^|]* \| [^|]* \| [^|]* \| [^|]* \| (.*) \|\s*$')
    with open(os.path.join(RESEARCH, 'campaign_flow.md'), encoding='utf-8') as f:
        for line in f:
            m = pat.match(line)
            if m:
                i = int(m.group(1))
                if 0 <= i <= 162 and i not in rows:
                    rows[i] = clean(m.group(2))
    return rows


def titles():
    out = {}
    heads = [
        re.compile(r'^### [\d.]+ Indices (\d+) and (\d+) [—-] (.+)$'),
        re.compile(r'^### [\d.]+ Index (\d+) [—-] (.+)$'),
        re.compile(r'^### Missions? (\d+) \(0x[0-9a-f]+\) - (.+)$'),
        re.compile(r'^### [\d.]+ 0x[0-9a-f]+ \((\d+)\) (.+)$'),
    ]
    for name in ('campaign_levels_a.md', 'campaign_levels_b.md', 'campaign_levels_c.md'):
        with open(os.path.join(RESEARCH, name), encoding='utf-8') as f:
            for line in f:
                line = line.rstrip()
                m = heads[0].match(line)
                if m:
                    for g in (1, 2):
                        out.setdefault(int(m.group(g)), clean(m.group(3)))
                    continue
                for p in heads[1:]:
                    m = p.match(line)
                    if m:
                        text = clean(m.group(2))
                        if 'station-side only' in text or text.startswith('no content'):
                            break
                        out.setdefault(int(m.group(1)), text)
                        break
    return out


def main():
    s, t = summaries(), titles()
    steps = [{'index': i, 'title': t.get(i, ''), 'summary': s.get(i, '')} for i in range(163)]
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    with open(OUT, 'w', encoding='utf-8', newline='\n') as f:
        json.dump({'steps': steps}, f, ensure_ascii=False, indent=1)
    print(f'{OUT}: {sum(1 for x in steps if x["summary"])} summaries, {sum(1 for x in steps if x["title"])} titles')


if __name__ == '__main__':
    main()
