# Shared read-only access to libgof2hdaa.so for the dialogue tools.
# Ghidra addresses (image base 0x10000) everywhere. Pointers in .data are R_ARM_RELATIVE: the stored
# word is the file vaddr, so a pointer p is read back with rd(p + 0x10000).
import os, struct, json
from elftools.elf.elffile import ELFFile   # pip install pyelftools
HERE = os.path.dirname(os.path.abspath(__file__))
REF = os.path.join(HERE, '..', '..')
ROOT = os.path.join(REF, '..')
BASE = 0x10000
_elf = ELFFile(open(os.path.join(REF, 'binaries', 'libgof2hdaa.so'), 'rb'))
_segs = [(s['p_vaddr'], s.data()) for s in _elf.iter_segments() if s['p_type'] == 'PT_LOAD']
def rd(addr, n):
    a = addr - BASE
    for v, d in _segs:
        if v <= a < v + len(d):
            return d[a - v:a - v + n]
    return None
def ints(addr, n):
    return list(struct.unpack('<%di' % n, rd(addr, 4 * n)))
def ptr(addr):
    """read a pointer word and return it as a Ghidra address (0 -> None)"""
    v = struct.unpack('<I', rd(addr, 4))[0]
    return v + BASE if v else None
_text = None
def text(i):
    global _text
    if _text is None:
        _text = json.load(open(os.path.join(ROOT, 'Assets', 'Localization', 'text_en.json'), encoding='utf-8'))
    return _text[i] if 0 <= i < len(_text) else None
