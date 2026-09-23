# Recover the BoundingAAB boxes that Level::createShip (0xcf83c) gives to kind-1 ships (freighters,
# battleship). The decompiler lost the float arguments; they are movw/movt immediates in the code.
#   python Reference/tools/npc/freighter_boxes.py
# BoundingAAB(x, y, z, a, b, c, d, e, f): x,y,z = ship position (registers), then 6 stack floats.
# Printed as (a, b, c) = box centre offset from the ship and (d, e, f) = full box size (BoundingAAB::
# BoundingAAB 0xa3b1c stores |size|/2 as the half extents), ship space, engine units, nose = +Z.
import os, sys, struct, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from disasm import rd, BASE, name_of
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
a0, a1 = 0xcf83c, 0xd0464
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB); md.skipdata = True
regs = {}; stack = {}
f = lambda v: struct.unpack('<f', struct.pack('<I', v & 0xffffffff))[0]
boxes = []
for i in md.disasm(rd(a0 - BASE, a1 - a0), a0):
    m, op = i.mnemonic, i.op_str
    mm = re.match(r'(r\d+|ip|sb|sl|fp|lr), #(0x[0-9a-f]+|\d+)$', op)
    if m in ('movw', 'movs', 'mov.w') and mm:
        regs[mm.group(1)] = int(mm.group(2), 0)
    elif m == 'movt' and mm:
        regs[mm.group(1)] = (regs.get(mm.group(1), 0) & 0xffff) | (int(mm.group(2), 0) << 16)
    elif m == 'strd':
        mm = re.match(r'(\w+), (\w+), \[sp(?:, #(0x[0-9a-f]+|\d+))?\]', op)
        if mm:
            off = int(mm.group(3), 0) if mm.group(3) else 0
            stack[off] = regs.get(mm.group(1)); stack[off + 4] = regs.get(mm.group(2))
    elif m in ('bl', 'blx') and op.startswith('#'):
        if name_of(int(op[1:], 16)) == 'BoundingAAB::BoundingAAB':
            vals = [stack.get(o) for o in range(0, 0x18, 4)]
            boxes.append((i.address, [None if v is None else f(v) for v in vals]))
        stack = {}
labels = ['race 0 battleship (ship 14), 11 boxes, wreck 18304'] * 11 + \
         ['race 1 Vossk freighter (ship 13), 5 boxes, wreck 18303'] * 5 + \
         ['race 2 Nivelian freighter, 3 boxes, wreck 18301'] * 3 + \
         ['race 3 Midorian freighter, 2 boxes, wreck 18300'] * 2 + \
         ['race 0 Terran freighter (ship 15), 3 boxes, wreck 18302'] * 3
for (addr, v), lab in zip(boxes, labels):
    fmt = lambda t: '(' + ', '.join('?' if x is None else '%g' % x for x in t) + ')'
    print('%08x  %-50s offset %s  size %s' % (addr, lab, fmt(v[:3]), fmt(v[3:])))
