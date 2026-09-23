# Thumb disassembly of libgof2hdaa.so at Ghidra addresses (image base 0x10000).
#   python Reference/tools/shop/thumb.py <start hex> <end hex>
import sys, os, struct
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from rb import rd
a0 = int(sys.argv[1], 16); a1 = int(sys.argv[2], 16)
code = rd(a0 - 0x10000, a1 - a0)
md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
for i in md.disasm(code, a0):
    extra = ''
    if i.mnemonic.startswith('ldr') and '[pc' in i.op_str:
        try:
            off = int(i.op_str.split('#')[-1].rstrip(']'), 16)
            lit = ((i.address + 4) & ~3) + off
            extra = '  ; =0x%x' % struct.unpack('<I', rd(lit - 0x10000, 4))[0]
        except Exception:
            pass
    print('%08x  %-8s %s%s' % (i.address, i.mnemonic, i.op_str, extra))
