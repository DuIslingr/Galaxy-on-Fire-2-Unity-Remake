# Read 32-bit constants (DAT_xxxxxxxx) from libgof2hdaa.so as float and hex.
# Ghidra addresses use image base 0x10000, so pass them exactly as shown in the decompiled code.
#   python Reference/tools/rf.py 000a8178 000a8180
import sys, struct, os
from elftools.elf.elffile import ELFFile   # pip install pyelftools
here = os.path.dirname(os.path.abspath(__file__))
e = ELFFile(open(os.path.join(here, '..', 'binaries', 'libgof2hdaa.so'), 'rb'))
def rd(a):
    for s in e.iter_segments():
        if s['p_type'] == 'PT_LOAD' and s['p_vaddr'] <= a < s['p_vaddr'] + s['p_filesz']:
            return s.data()[a - s['p_vaddr']:a - s['p_vaddr'] + 4]
for x in sys.argv[1:]:
    b = rd(int(x, 16) - 0x10000)
    print(x, struct.unpack('<f', b)[0] if b else None, hex(struct.unpack('<I', b)[0]) if b else None)
