import struct, numpy as np, texture2ddecoder
from PIL import Image
def load(path):
    b=open(path,'rb').read()
    assert b[:7]==b'AEimage', path
    t=b[8]; w,h,n=struct.unpack('<HHH',b[9:15]); o=15
    regions=[list(struct.unpack('<4H',b[o+8*i:o+8*i+8])) for i in range(n)]; o+=8*n
    info=dict(type=t,width=w,height=h,regions=regions,hasAlpha=bool(t&2))
    if t in (1,3,0x81):
        data=b[o:o+w*h*4]; o+=w*h*4
        img=Image.frombytes('RGBA',(w,h),data)
        info['format']='RGBA8'+(' cubemap-strip(6 faces, vertical)' if t==0x81 else '')
    elif t in (0x14,0x16,0x17,0x40,0x42):
        size=struct.unpack('<I',b[o:o+4])[0]; o+=4
        data=b[o:o+size]; o+=size
        lvl0=data[:max(8,w*h//2)]
        rgba=texture2ddecoder.decode_etc1(lvl0,w,h)   # returns BGRA
        img=Image.frombytes('RGBA',(w,h),rgba,'raw','BGRA')
        info['format']='ETC1'+(' +mips' if t&2 else '')
    else:
        raise ValueError('unsupported type %x'%t)
    info['leftover']=len(b)-o
    return img,info
