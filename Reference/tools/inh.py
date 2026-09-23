import subprocess
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
f=open('apk/lib/armeabi-v7a/libgof2hdaa.so','rb'); e=ELFFile(f)
dsym=e.get_section_by_name('.dynsym')
syms=list(dsym.iter_symbols())
addr2sym={s['st_value']:s.name for s in syms if s['st_value'] and s.name}
rel={}
for sec in e.iter_sections():
    if isinstance(sec,RelocationSection):
        for r in sec.iter_relocations():
            rel[r['r_offset']]=(r['r_info_type'],r['r_info_sym'])
def readword(a):
    for s in e.iter_sections():
        if s['sh_addr']<=a<s['sh_addr']+s['sh_size'] and s['sh_type']!='SHT_NOBITS':
            return int.from_bytes(s.data()[a-s['sh_addr']:a-s['sh_addr']+4],'little')
def target(a):
    if a in rel:
        t,si=rel[a]
        if si: return syms[si].name
        return addr2sym.get(readword(a))
    return addr2sym.get(readword(a))
dem=lambda n: subprocess.run(['c++filt'],input=n,capture_output=True,text=True).stdout.strip().replace('typeinfo for ','')
out=[]
for s in syms:
    if s.name.startswith('_ZTI') and s['st_value']:
        a=s['st_value']; vt=target(a) or ''
        if 'si_class' in vt:
            b=target(a+8); out.append((s.name,[b]))
        elif 'vmi_class' in vt:
            n=readword(a+12); bs=[target(a+16+8*i) for i in range(n)]; out.append((s.name,bs))
        else: out.append((s.name,[]))
names=set(n for n,_ in out)|set(b for _,bs in out for b in bs if b)
m={n:dem(n) for n in names if n}
for n,bs in sorted(out,key=lambda x:m[x[0]]):
    print(m[n],'<-',', '.join(m.get(b,str(b)) for b in bs if b))
