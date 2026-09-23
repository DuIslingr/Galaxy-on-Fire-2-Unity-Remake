# Emulate BuildResourceList() from libgof2hdaa.so to recover the game's full resource table
# (textures, materials, meshes with IDs) exactly as the game builds it at startup.
import struct, json, sys
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
from unicorn import *
from unicorn.arm_const import *

SO = sys.argv[1] if len(sys.argv) > 1 else '../libgof2hdaa.so'
BASE = 0x10000                      # match Ghidra addresses
f = open(SO, 'rb'); e = ELFFile(f); raw = open(SO, 'rb').read()
mu = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
try:
    mu.ctl_set_cpu_model(UC_CPU_ARM_CORTEX_A15)
except Exception as ex: print('cpu model', ex)
mu.reg_write(UC_ARM_REG_C1_C0_2, mu.reg_read(UC_ARM_REG_C1_C0_2) | (0xf << 20))
mu.reg_write(UC_ARM_REG_FPEXC, 0x40000000)
PAGE = 0x1000
def up(x): return (x + PAGE - 1) & ~(PAGE - 1)
hi = max(s['p_vaddr'] + s['p_memsz'] for s in e.iter_segments() if s['p_type'] == 'PT_LOAD')
mu.mem_map(BASE, up(hi + 0x10000))
for s in e.iter_segments():
    if s['p_type'] == 'PT_LOAD':
        mu.mem_write(BASE + s['p_vaddr'], s.data())
THUNK = 0x40000000; HEAP = 0x50000000; STACK = 0x70000000; MISC = 0x60000000
mu.mem_map(THUNK, 0x100000); mu.mem_map(HEAP, 0x8000000); mu.mem_map(STACK, 0x200000); mu.mem_map(MISC, 0x100000)
dynsym = e.get_section_by_name('.dynsym'); syms = list(dynsym.iter_symbols())
thunk_names = {}
def thunk_for(name):
    idx = len(thunk_names); addr = THUNK + idx * 4
    mu.mem_write(addr, b'\x70\x47\x00\xbf')   # bx lr ; nop
    thunk_names[addr] = name; return addr
OVERRIDE = {'_Znwj', '_Znaj', 'malloc', 'calloc', 'realloc', 'free', '_ZdlPv', '_ZdaPv', '__aeabi_memcpy', '__aeabi_memcpy4',
            'memcpy', 'memset', '__aeabi_memclr', '__aeabi_memclr4', 'strlen', 'strcpy',
            '_ZN11AbyssEngine11PaintCanvas11AddResourceEPNS_8ResourceE',
            '_ZN11AbyssEngine11PaintCanvas15SetResourceListEv'}
stack_guard = MISC + 0x100; mu.mem_write(stack_guard, struct.pack('<I', 0x1234))
for sec in e.iter_sections():
    if not isinstance(sec, RelocationSection): continue
    for r in sec.iter_relocations():
        off = BASE + r['r_offset']; t = r['r_info_type']; sym = syms[r['r_info_sym']] if r['r_info_sym'] else None
        if t == 23:  # R_ARM_RELATIVE
            v = struct.unpack('<I', bytes(mu.mem_read(off, 4)))[0]; mu.mem_write(off, struct.pack('<I', v + BASE))
        elif t in (21, 22, 2):  # GLOB_DAT, JUMP_SLOT, ABS32
            name = sym.name
            if name == '__stack_chk_guard': val = stack_guard
            elif sym['st_value'] and name not in OVERRIDE and not ('AEFile' in name or 'FMod' in name or (name.startswith('_ZN11AbyssEngine') and any(k in name for k in ('TextureCreate','Image','Sound','Mesh','Material')))):
                val = BASE + sym['st_value']
            elif t == 22 or sym['st_info']['type'] == 'STT_FUNC' or name in OVERRIDE or sym['st_value']:
                val = thunk_for(name) | 1
            else:
                val = MISC + 0x800  # dummy data object
            if t == 2 and sym['st_value'] == 0: pass
            mu.mem_write(off, struct.pack('<I', val))
heap_ptr = [HEAP + 0x10]
def alloc(n):
    p = heap_ptr[0]; heap_ptr[0] += (max(n, 4) + 15) & ~15
    if heap_ptr[0] > HEAP + 0x7ff0000: raise MemoryError
    return p
resources = []; calls = {}
def rd32(a): return struct.unpack('<I', bytes(mu.mem_read(a, 4)))[0]
def rdstr(a, n=512):
    b = bytes(mu.mem_read(a, n)); return b.split(b'\0')[0].decode('latin1')
def hook(uc, addr, size, ud):
    name = thunk_names.get(addr & ~1) or thunk_names.get(addr)
    if name is None: return
    calls[name] = calls.get(name, 0) + 1
    r0, r1, r2 = uc.reg_read(UC_ARM_REG_R0), uc.reg_read(UC_ARM_REG_R1), uc.reg_read(UC_ARM_REG_R2)
    ret = 0
    if name in ('_Znwj', '_Znaj', 'malloc'): ret = alloc(r0); uc.mem_write(ret, b'\0' * max(r0, 4))
    elif name == 'calloc': n = r0 * r1; ret = alloc(n); uc.mem_write(ret, b'\0' * max(n, 4))
    elif name == 'realloc':
        ret = alloc(r1)
        if r0: uc.mem_write(ret, bytes(uc.mem_read(r0, r1)))
    elif name in ('__aeabi_memcpy', '__aeabi_memcpy4', 'memcpy'):
        if r2: uc.mem_write(r0, bytes(uc.mem_read(r1, r2)))
        ret = r0
    elif name == 'memset': uc.mem_write(r0, bytes([r1 & 0xff]) * r2); ret = r0
    elif name in ('__aeabi_memclr', '__aeabi_memclr4'): uc.mem_write(r0, b'\0' * r1)
    elif name == 'strlen': ret = len(rdstr(r0, 4096))
    elif name == 'strcpy': s = rdstr(r1, 4096).encode() + b'\0'; uc.mem_write(r0, s); ret = r0
    elif name.endswith('AddResourceEPNS_8ResourceE'): resources.append(r1)
    elif name.endswith('SetResourceListEPKPNS_8ResourceEj') or 'SetResourceList' in name:
        for i in range(r2): resources.append(rd32(r1 + 4*i))
    uc.reg_write(UC_ARM_REG_R0, ret)
mu.hook_add(UC_HOOK_CODE, hook, begin=THUNK, end=THUNK + 0x100000)
# fake Engine: engine+0x28 -> ptr -> canvas object (zeroed, big)
canvas = alloc(0x1000); holder = alloc(16); mu.mem_write(holder, struct.pack('<I', canvas))
engine = alloc(0x1000); mu.mem_write(engine + 0x28, struct.pack('<I', holder))
sp = STACK + 0x1f0000
mu.reg_write(UC_ARM_REG_SP, sp); mu.reg_write(UC_ARM_REG_R0, engine)
RET = THUNK + 0xff000; mu.mem_write(RET, b'\x70\x47\x00\xbf'); mu.reg_write(UC_ARM_REG_LR, RET | 1)
entry = BASE + next(s['st_value'] for s in syms if s.name == '_Z17BuildResourceListPN11AbyssEngine6EngineE' and s['st_value'])
try:
    mu.emu_start(entry | 1, RET, count=50_000_000)
except UcError as ex:
    print('emu error', ex, hex(mu.reg_read(UC_ARM_REG_PC)))
n_c = rd32(canvas + 0x134); arr = rd32(canvas + 0x138)
print('canvas list', n_c)
resources += [rd32(arr + 4*i) for i in range(n_c)]
print('resources', len(resources), 'calls', sorted(calls.items(), key=lambda x: -x[1])[:12])
TYPES = {2: 'texture', 4: 'mesh'}
out = []
for p in resources:
    rid = struct.unpack('<H', bytes(mu.mem_read(p, 2)))[0]
    typ, handle, data = rd32(p + 4), rd32(p + 8), rd32(p + 12)
    rec = {'id': rid, 'type': typ}
    try:
        if typ == 2:
            rec['kind'] = 'texture'; rec['path'] = rdstr(rd32(data)); rec['param'] = struct.unpack('<f', bytes(mu.mem_read(data + 4, 4)))[0]
        elif typ == 4:
            rec['kind'] = 'mesh'; rec['path'] = rdstr(rd32(data)); rec['material'] = struct.unpack('<H', bytes(mu.mem_read(data + 4, 2)))[0]
            rec['flag'] = bytes(mu.mem_read(data + 6, 1))[0]
        else:
            b = bytes(mu.mem_read(data, 0x28))
            tex = list(struct.unpack('<8H', b[:16]))
            if typ == 6:
                rec['kind'] = 'material'
                rec['textures'] = [t for t in tex if t != 0xffff]
                rec['shader'], rec['i14'], rec['i18'] = struct.unpack('<3i', b[16:28]); rec['vec'] = list(struct.unpack('<3f', b[28:40]))
            else:
                rec['kind'] = f'type{typ}'; rec['raw'] = b[:16].hex(); rec['data'] = hex(data)
    except UcError as ex:
        rec['error'] = str(ex)
    out.append(rec)
json.dump(out, open('resources_raw.json', 'w'), indent=0)
import collections; print(collections.Counter(r.get('kind') for r in out))
