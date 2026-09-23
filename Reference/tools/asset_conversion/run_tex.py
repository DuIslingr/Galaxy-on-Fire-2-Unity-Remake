import aei,glob,os,json,sys
from multiprocessing import Pool
D='../obbdata/47947_GOF2CONTENT_ETC/assets/data'
OUT='../unitypkg/Assets/Textures'
def job(f):
    rel=os.path.relpath(f,D)
    rel=rel.replace('assets/','',1) if rel.startswith('assets/') else rel
    rel=rel.replace('3d/textures/low/etc/','').replace('3d/textures/','')
    out=os.path.join(OUT,os.path.splitext(rel)[0]+'.png')
    os.makedirs(os.path.dirname(out),exist_ok=True)
    try:
        img,info=aei.load(f)
        # drop alpha channel when fully opaque to keep files small
        if img.getextrema()[3]==(255,255): img=img.convert('RGB')
        img.save(out,optimize=False,compress_level=6)
        info['source']=os.path.relpath(f,D); info['png']=os.path.relpath(out,OUT)
        return info
    except Exception as e:
        return {'source':os.path.relpath(f,D),'error':str(e)}
if __name__=='__main__':
    files=sorted(glob.glob(D+'/**/*.aei',recursive=True))
    with Pool(os.cpu_count()) as p: res=p.map(job,files,chunksize=4)
    json.dump(res,open(OUT+'/_texture_manifest.json','w'),indent=0)
    print(len(res),'errors',sum('error' in r for r in res))
