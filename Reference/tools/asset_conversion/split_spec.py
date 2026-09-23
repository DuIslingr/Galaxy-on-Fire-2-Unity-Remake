import glob,os
from PIL import Image
from multiprocessing import Pool
T='../unitypkg/Assets/GoF2/Textures'
def job(f):
    im=Image.open(f)
    if im.mode!='RGBA': return None
    a=im.getchannel('A')
    out=f.replace('_normal_specular.png','_metallic_smoothness.png')
    Image.merge('LA',(Image.new('L',im.size,0),a)).save(out,compress_level=6)
    return out
if __name__=='__main__':
    fs=glob.glob(T+'/**/*_normal_specular*.png',recursive=True)
    with Pool(2) as p: r=p.map(job,fs)
    print(len([x for x in r if x]))
