# Converts the per-item weapon table of Reference/research/weapons.md (section 4) into
# Assets/Resources/GoF2Data/weapon_fx.json: projectile / muzzle flash / impact mesh names, shot sound
# (FMOD event id + .ogg name) and whether the sound loops, per item index. Run from the project root:
#   python Reference/tools/weapons/build_weapon_fx.py
import json, os, re

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..')
md = open(os.path.join(ROOT, 'Reference', 'research', 'weapons.md'), encoding='utf-8').read()
section = md[md.index('## 4. Tables per item'):md.index('## 5. Sounds')]

def mesh(cell):
    cell = cell.strip()
    if cell in ('', '-') or cell.startswith('-') or cell.startswith('('):
        return ''
    cell = cell.replace('beam ', '')
    return re.split(r'[ (]', cell)[0]

out = []
for line in section.splitlines():
    cols = [c.strip() for c in line.strip().strip('|').split('|')]
    if len(cols) < 13 or not re.fullmatch(r'\d+', cols[0]):
        continue
    idx = int(cols[0])
    sound = cols[12]
    m = re.match(r'(\d+)\s*(.*)', sound)
    sid, rest = (int(m.group(1)), m.group(2)) if m else (-1, '')
    name = ''
    arrow = re.search(r'→\s*([\w\-]+)\.ogg', rest)
    if arrow:
        name = arrow.group(1)
    else:
        w = re.match(r'([A-Za-z][\w\-]*)', rest)
        if w and w.group(1) not in ('DLC',):
            name = w.group(1)
    out.append({
        'item': idx,
        'projectile': mesh(cols[9]),
        'muzzle': mesh(cols[10]),
        'impact': mesh(cols[11]),
        'beam': cols[7] == 'beam',
        'soundId': sid,
        'sound': name,
        'soundLoops': '(loop' in sound or 'loop)' in sound,
    })

dst = os.path.join(ROOT, 'Assets', 'Resources', 'GoF2Data', 'weapon_fx.json')
json.dump(out, open(dst, 'w', encoding='utf-8'), indent=1)
print(f'{len(out)} weapons -> {dst}')
for e in out:
    if e['item'] in (2, 22, 36):
        print(e)
