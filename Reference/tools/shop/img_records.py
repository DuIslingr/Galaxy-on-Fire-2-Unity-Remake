# Recover ALL Image2D records (id -> textureId, region) from the BuildResourceList disassembly,
# including the resolution-specific branches that the emulation (default flags) never executed.
# A record is built as: new(0x10) res; new(4) data; strh tex,[data,#0]; strh region,[data,#2];
# strh id,[res,#0]; type 3 -> AddResource.   Output: list of (addr, id, tex, region).
#   python Reference/tools/shop/img_records.py [id ...]
import re, sys, os
here = os.path.dirname(os.path.abspath(__file__))
path = os.path.join(here, '..', '..', 'decompiled', 'native', 'game', 'BuildResourceList_DISASSEMBLY.txt')
regs = {}
data_reg = res_reg = None
cur = {}
out = []
for line in open(path, encoding='utf-8', errors='replace'):
    p = line.rstrip('\n').split('\t')
    if len(p) < 2:
        continue
    addr, ins = p[0], p[1]
    m = re.match(r'(movw|movs|mov\.w|mov) (r\d+),#(0x[0-9a-f]+|\d+)$', ins)
    if m:
        regs[m.group(2)] = int(m.group(3), 0)
        continue
    m = re.match(r'mov (r\d+),(r\d+)$', ins)
    if m:
        if m.group(2) in regs:
            regs[m.group(1)] = regs[m.group(2)]
        else:
            regs.pop(m.group(1), None)
        continue
    m = re.match(r'strh (r\d+),\[(r\d+),#(0x[0-9a-f]+)\]$', ins)
    if m:
        v = regs.get(m.group(1)); base = m.group(2); off = int(m.group(3), 16)
        cur.setdefault(base, {})[off] = v
        continue
    if 'CALL AbyssEngine::PaintCanvas::AddResource' in line:
        # find the base holding a 2-short data block (tex, region) and the one holding id at +0
        tex = reg = rid = None
        for b, d in cur.items():
            if 0 in d and 2 in d and d.get(2) is not None:
                tex, reg = d[0], d[2]
        for b, d in cur.items():
            if 0 in d and 2 not in d:
                rid = d[0]
        if tex is not None and rid is not None:
            out.append((addr, rid, tex, reg))
        cur = {}
        continue
    if 'CALL operator.new' in ins:
        pass
if __name__ == '__main__':
    want = set(int(a, 0) for a in sys.argv[1:])
    for a, i, t, r in out:
        if not want or i in want:
            print(a, hex(i), i, hex(t) if t is not None else None, r)
    if not want:
        print(len(out), 'records')
