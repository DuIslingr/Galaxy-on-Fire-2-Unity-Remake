# Print a C++ vtable of libgof2hdaa.so resolved through the dynamic relocations.
#   python Reference/tools/npc/vtable.py 2640c8 40      (Ghidra address of the vtable pointer target, slot count)
# The address is the value stored in the object (e.g. PTR__PlayerFighter_002640c8); slot i = +4*i.
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from disasm import elf, dem, funcs, BASE
dsym = elf.get_section_by_name('.dynsym')
rel = {}
for sec in ('.rel.dyn', '.rel.plt'):
    for r in elf.get_section_by_name(sec).iter_relocations():
        rel[r['r_offset']] = r
def slot_name(a):
    r = rel.get(a - BASE)
    if r is None:
        return '?'
    sym = dsym.get_symbol(r['r_info_sym'])
    if sym.name:
        return dem(sym.name)
    return 'reloc type %d' % r['r_info_type']
if __name__ == '__main__':
    a = int(sys.argv[1], 16); n = int(sys.argv[2]) if len(sys.argv) > 2 else 32
    for i in range(n):
        print('+0x%02x  %s' % (4 * i, slot_name(a + 4 * i)))
