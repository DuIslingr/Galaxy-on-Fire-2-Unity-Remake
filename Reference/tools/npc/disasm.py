# Thumb disassembly of libgof2hdaa.so with names (Ghidra addresses, image base 0x10000).
#   python Reference/tools/npc/disasm.py <start hex> <end hex>        e.g. f0d90 f36b0
#   python Reference/tools/npc/disasm.py --func "PlayerFighter::update"
# Annotates: bl/blx targets (PLT imports -> demangled symbol, local code -> _FUNCTIONS.tsv name),
# pc-relative literal loads (hex + float), vldr literal floats.
import sys, os, struct
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
from elftools.elf.elffile import ELFFile
def dem(s):
    # minimal Itanium demangler: _ZN..E nested names and _Z<len>name (arguments dropped)
    if not s.startswith('_Z'):
        return s
    t = s[2:]; nested = t.startswith('N')
    if nested:
        t = t[1:]
        while t and t[0] in 'KVr':
            t = t[1:]
    parts = []
    while t and t[0].isdigit():
        k = 0
        while t[k].isdigit(): k += 1
        n = int(t[:k]); parts.append(t[k:k + n]); t = t[k + n:]
        if not nested: break
        if t.startswith(('C1', 'C2', 'D0', 'D1', 'D2')):
            parts.append(('~' if t[0] == 'D' else '') + parts[-1]); break
    return '::'.join(parts) if parts else s
HERE = os.path.dirname(os.path.abspath(__file__))
REF = os.path.join(HERE, '..', '..')
BASE = 0x10000
elf = ELFFile(open(os.path.join(REF, 'binaries', 'libgof2hdaa.so'), 'rb'))
segs = [(s['p_vaddr'], s.data()) for s in elf.iter_segments() if s['p_type'] == 'PT_LOAD']
def rd(a, n):
    for v, d in segs:
        if v <= a < v + len(d):
            return d[a - v:a - v + n]
    return b'\0' * n
# PLT map: entry i of .rel.plt <-> stub at plt + 0x14 + 12*i
plt = elf.get_section_by_name('.plt'); relplt = elf.get_section_by_name('.rel.plt')
dsym = elf.get_section_by_name('.dynsym')
pltmap = {}
for i, r in enumerate(relplt.iter_relocations()):
    name = dsym.get_symbol(r['r_info_sym']).name
    pltmap[plt['sh_addr'] + 0x14 + 12 * i + BASE] = dem(name)
funcs = {}
tsv = os.path.join(REF, 'decompiled', 'native', '_FUNCTIONS.tsv')
for line in open(tsv, encoding='utf-8', errors='replace'):
    p = line.rstrip('\n').split('\t')
    if len(p) >= 2:
        try: funcs[int(p[1], 16)] = p[0]
        except ValueError: pass
def name_of(a):
    return pltmap.get(a) or funcs.get(a) or funcs.get(a & ~1)
def main():
    if sys.argv[1] == '--func':
        want = sys.argv[2]
        cands = [(a, n) for a, n in funcs.items() if n == want]
        rows = [l.split('\t') for l in open(tsv, encoding='utf-8', errors='replace')]
        size = {int(r[1], 16): int(r[2]) for r in rows if len(r) >= 3 and r[2].strip().isdigit()}
        a0 = cands[0][0]; a1 = a0 + size.get(a0, 0x400)
    else:
        a0 = int(sys.argv[1], 16); a1 = int(sys.argv[2], 16)
    code = rd(a0 - BASE, a1 - a0)
    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
    md.skipdata = True
    for i in md.disasm(code, a0):
        extra = ''
        if i.mnemonic in ('bl', 'blx', 'b.w', 'b') and i.op_str.startswith('#'):
            t = int(i.op_str[1:], 16); n = name_of(t)
            if n: extra = '  ; ' + n
        elif '[pc' in i.op_str and ('ldr' in i.mnemonic or 'vldr' in i.mnemonic):
            try:
                off = i.op_str.split('#')[-1].rstrip(']').strip()
                off = int(off, 16) if off.lower().startswith(('0x', '-0x')) else int(off)
                lit = ((i.address + 4) & ~3) + off
                raw = rd(lit - BASE, 8)
                v = struct.unpack('<I', raw[:4])[0]; f = struct.unpack('<f', raw[:4])[0]
                extra = '  ; [%x] =0x%x (%g)' % (lit, v, f)
                if i.mnemonic.startswith('vldr') and i.op_str.startswith('d'):
                    extra += ' dbl=%g' % struct.unpack('<d', raw)[0]
            except Exception:
                pass
        print('%08x  %-8s %s%s' % (i.address, i.mnemonic, i.op_str, extra))
if __name__ == '__main__':
    main()
