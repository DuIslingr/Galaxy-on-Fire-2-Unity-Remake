# Campaign radio messages from Level::createRadioMessages(int campaignMission) (0xd0574), recovered by tracing the
# Thumb code of every switch case (tbh table at 0xd058e, 162 cases) and reading the constant arguments of the
# RadioMessage constructors:
#   0x17c4d0 RadioMessage(text, image, type, param)              -> enemy index list = [param]
#   0x17c512 RadioMessage(text, image, type, param, count)       -> enemy index list = param .. param+count-1
#   0x17c574 RadioMessage(text, image, Objective*)               -> type 0xb (objective achieved)
#   python Reference/tools/dialogue/radio_tables.py            table
#   python Reference/tools/dialogue/radio_tables.py --text     with English text (local use only)
#   python Reference/tools/dialogue/radio_tables.py --json out.json
# "image" is the speaker id (name = text 1597 + image; portrait: see Radio::update 0x180380 and
# research/dialogue_cutscenes.md).
import sys, os, json, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from binary import rd, text
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
FUNC, TBH, NCASE = 0xd0574, 0xd058e, 162
# the calls go through PLT stubs (exported symbols): _ZN12RadioMessageC1Eiiii 0x6cc80, ...C1Eiiiii 0x6cc8c,
# ArraySetLength<RadioMessage*> 0x6cc74; direct addresses kept as fallbacks
CTOR4, CTOR5, CTOROBJ, SETLEN = (0x6cc80, 0x17c4d0), (0x6cc8c, 0x17c512), (0x17c574,), (0x6cc74, 0xd3dcc)
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)


def insn(a):
    for i in md.disasm(rd(a, 4), a, 1):
        return i
    return None


def imm(s):
    s = s.strip().lstrip('#')
    return int(s, 0)


def signed(v):
    if v is None:
        return None
    return v - 0x100000000 if v >= 0x80000000 else v


def trace(start):
    """follow one switch case (unconditional branches included) until the function returns"""
    regs, stack, out, a, n, setlen = {}, {}, [], start, 0, None
    while n < 4000:
        n += 1
        i = insn(a)
        if i is None:
            break
        m, ops = i.mnemonic, [o.strip() for o in i.op_str.split(',')]
        nxt = a + i.size
        try:
            if m in ('movs', 'mov', 'mov.w', 'movw', 'mvn', 'mvns', 'mvn.w') and len(ops) > 1 and ops[1].startswith('#'):
                v = imm(ops[1])
                regs[ops[0]] = (~v & 0xffffffff) if m.startswith('mvn') else v
            elif m == 'movt':
                regs[ops[0]] = (regs.get(ops[0], 0) & 0xffff) | (imm(ops[1]) << 16)
            elif m in ('mov', 'movs') and ops[1] in regs:
                regs[ops[0]] = regs[ops[1]]
            elif m in ('mov', 'movs'):
                regs.pop(ops[0], None)
            elif m.startswith('ldr') and '[pc' in i.op_str:
                off = imm(i.op_str.split('#')[-1].rstrip(']'))
                lit = ((a + 4) & ~3) + off
                regs[ops[0]] = struct.unpack('<I', rd(lit, 4))[0]
            elif m in ('adds', 'add', 'add.w', 'subs', 'sub', 'sub.w', 'addw', 'subw') and ops[-1].startswith('#'):
                src = ops[1] if len(ops) == 3 else ops[0]
                if src in regs and src != 'sp':
                    v = imm(ops[-1])
                    regs[ops[0]] = (regs[src] + (v if m.startswith('add') else -v)) & 0xffffffff
                else:
                    regs.pop(ops[0], None)
            elif m in ('str', 'str.w') and ops[1] == '[sp]':
                stack[0] = regs.get(ops[0])
            elif m in ('str', 'str.w') and ops[1] == '[sp':
                stack[imm(ops[2].rstrip(']'))] = regs.get(ops[0])
            elif m == 'strd' and ops[2] in ('[sp]', '[sp'):
                o = 0 if ops[2] == '[sp]' else imm(ops[3].rstrip(']'))
                stack[o] = regs.get(ops[0])
                stack[o + 4] = regs.get(ops[1])
            elif m in ('bl', 'blx'):
                t = imm(ops[0])
                if t in CTOR4:
                    out.append(dict(text=signed(regs.get('r1')), image=signed(regs.get('r2')),
                                    type=signed(regs.get('r3')), param=signed(stack.get(0)), count=1, at=hex(a)))
                elif t in CTOR5:
                    out.append(dict(text=signed(regs.get('r1')), image=signed(regs.get('r2')),
                                    type=signed(regs.get('r3')), param=signed(stack.get(0)),
                                    count=signed(stack.get(4)), at=hex(a)))
                elif t in CTOROBJ:
                    out.append(dict(text=signed(regs.get('r1')), image=signed(regs.get('r2')), type=0xb,
                                    param='objective', count=0, at=hex(a)))
                elif t in SETLEN:
                    setlen = regs.get('r0')
                for r in ('r0', 'r1', 'r2', 'r3', 'r12'):
                    regs.pop(r, None)
            elif m in ('b', 'b.w') and ops[0].startswith('#'):
                nxt = imm(ops[0])
            elif m.startswith('pop') and 'pc' in i.op_str:
                break
            elif m == 'bx':
                break
            elif m.startswith(('str', 'cmp', 'tst', 'push', 'cb', 'b')):
                pass
            elif ops and ops[0] in regs:
                regs.pop(ops[0], None)
        except (ValueError, IndexError):
            if ops and ops[0] in regs:
                regs.pop(ops[0], None)
        a = nxt
    return setlen, out


# RadioMessage::triggered 0x17c5d8 (param = RadioMessage+0x14, list = enemy indices param..param+count-1;
# "time" = the level-script clock LevelScript+8, reset when the briefing opens)
TYPES = {
    0: 'player route: current waypoint moved past #param (Route::getCurrent)',
    1: 'any listed enemy dead',
    2: 'any listed enemy with Player+0x5d set is dead',
    3: 'Level::getEnemiesLeft() < 1',
    4: 'Level::getFriendsLeft() < 1',
    5: 'time >= param ms',
    6: 'radio message #param has been triggered (chain; shown after it)',
    8: 'any listed non-asteroid enemy active',
    9: 'all listed enemies dead',
    10: 'any listed non-asteroid enemy with Player+0x5d set active',
    11: 'Objective::achieved',
    12: 'any listed enemy below 1/2 hit points',
    14: 'KIPlayer(enemy #param)+0x65 set',
    15: 'any non-asteroid enemy dead',
    16: 'any active non-asteroid enemy that is not always-friend',
    17: 'fires at once (decompiled loop always ends in trigger; uncertain)',
    18: 'KIPlayer(enemy #param)+0x65 set -> trigger, else KIPlayer+0x66',
    19: 'any listed enemy below 1/4 hit points',
    20: '>= param non-asteroid enemies dead',
    21: 'KIPlayer(enemy #param)+0x20 set',
    22: 'Level+0x1c >= param',
    23: 'Radar::stationLocked()',
    24: 'enemy #param inactive and alive, and time > 60000 ms',
    25: 'player route advanced from waypoint 0 and >= param enemies alive',
    26: 'enemy 0 active and alive and within 5000 units of param on one axis',
    27: 'LevelScript::getEvent() == param (script step)',
    28: 'player armor HP < 1',
    30: 'dead enemies among indices 2..5 == param',
    31: 'any listed enemy below 3/4 hit points',
}


def cases():
    tbl = struct.unpack('<%dH' % NCASE, rd(TBH, 2 * NCASE))
    res = {}
    for c in range(NCASE):
        res.setdefault(TBH + 2 * tbl[c], []).append(c)
    return res


def table():
    rows = {}
    for tgt, cs in sorted(cases().items()):
        setlen, msgs = trace(tgt)
        if msgs:
            for c in cs:
                rows[c] = dict(target=hex(tgt), length=setlen, messages=msgs)
    return rows


def main(a):
    show = '--text' in a
    rows = table()
    if '--json' in a:
        json.dump(rows, open(a[a.index('--json') + 1], 'w'), indent=1)
        return
    for c in sorted(rows):
        r = rows[c]
        print('mission %d: %d messages (array length %s) @%s' % (c, len(r['messages']), r['length'], r['target']))
        for k, m in enumerate(r['messages']):
            img = m['image']
            nm = text(1597 + img) if isinstance(img, int) and 0 <= img < 71 else img
            line = '  %2d text %-5s img %-4s %-18s type %-5s param %-9s cnt %s' % (
                k, m['text'], img, nm, m['type'], m['param'], m['count'])
            if show and isinstance(m['text'], int):
                line += '  ' + (text(m['text']) or '').replace('\r', '').replace('\n', ' / ')[:110]
            print(line)


if __name__ == '__main__':
    main(sys.argv[1:])
