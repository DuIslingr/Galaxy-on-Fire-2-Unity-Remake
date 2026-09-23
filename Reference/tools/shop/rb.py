# Dump a table from libgof2hdaa.so at a Ghidra address (image base 0x10000).
#   python Reference/tools/shop/rb.py <addr hex> <count> [b|h|i|f]   (b = u8, h = s16, i = s32, f = float)
import sys, struct, os
from elftools.elf.elffile import ELFFile
here = os.path.dirname(os.path.abspath(__file__))
e = ELFFile(open(os.path.join(here, '..', '..', 'binaries', 'libgof2hdaa.so'), 'rb'))
segs = [(s['p_vaddr'], s.data()) for s in e.iter_segments() if s['p_type'] == 'PT_LOAD']
def rd(a, n):
    for v, d in segs:
        if v <= a < v + len(d):
            return d[a - v:a - v + n]
    return b'\0' * n  # .bss
def table(addr, count, fmt='i'):
    sz = {'b': 1, 'h': 2, 'i': 4, 'f': 4}[fmt]
    code = {'b': '<B', 'h': '<h', 'i': '<i', 'f': '<f'}[fmt]
    b = rd(addr - 0x10000, sz * count)
    return [struct.unpack(code, b[k * sz:(k + 1) * sz])[0] for k in range(count)]
if __name__ == '__main__':
    a = int(sys.argv[1], 16); n = int(sys.argv[2]); f = sys.argv[3] if len(sys.argv) > 3 else 'i'
    print(table(a, n, f))
