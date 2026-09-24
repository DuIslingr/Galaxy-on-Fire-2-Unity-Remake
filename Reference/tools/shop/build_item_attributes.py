# Writes Assets/Resources/GoF2Data/item_attributes.json: every item's original attribute pairs (Item+0x30,
# attribute id -> value) as parallel lists, because JsonUtility can't read the rawAttributes dictionary of items.json.
# Loaded by Database (ItemData.attributes). Attribute ids: see Reference/research/shop.md section 2.4.
#   python Reference/tools/shop/build_item_attributes.py
import json, os
here = os.path.dirname(os.path.abspath(__file__))
D = os.path.join(here, '..', '..', '..', 'Assets', 'Resources', 'GoF2Data')
items = json.load(open(os.path.join(D, 'items.json'), encoding='utf-8'))
out = []
for it in items:
    raw = it.get('rawAttributes', {})
    keys = sorted(int(k) for k in raw)
    out.append({'index': it['index'], 'keys': keys, 'values': [raw[str(k)] for k in keys]})
json.dump(out, open(os.path.join(D, 'item_attributes.json'), 'w', encoding='utf-8'), separators=(',', ':'))
print(len(out), 'items')
