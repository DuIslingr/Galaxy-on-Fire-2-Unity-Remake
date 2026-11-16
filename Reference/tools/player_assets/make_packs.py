# make_packs.py: the packs that carry what the player's copy doesn't provide (docs/notes/player-assets.md "Packs"),
# distributed separately, never on GitHub. A pack is a zip (.gof2pack) of files at their converted copy's paths and a
# gof2pack.json manifest; the game keeps it and writes it over the converted copy (OriginalPacks). Made from a checkout
# with the originals and the derived assets (the main project):
#   python3 Reference/tools/player_assets/make_packs.py --project <repo> [--out ~/GOF2UnityRemakeMods/packs] [--version N]
# hd    the HD pack (order 2): the HD textures (every edition's optional list from packs.json and the common optional
#       ones; with each normal map its metallic / smoothness map, which the converter would otherwise make from the
#       edition's lower one), the Real-ESRGAN skies and their star lists (GoF2SkyHd), the sky patches made from them
#       (GoF2SkyLayers/patch_*) and the 3D planets (GoF2Planets3D, from the planet_rebuild tools).
# (The common and gap packs follow once their sounds and models have a format the copy can read: the project's are
# .ogg and .fbx, the converted copy's .mp3 / .wav and .aem.)
import argparse, datetime, glob, json, os, zipfile

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", ".."))


def hd_files(project, packs):
    A = os.path.join(project, "Assets")
    files = set()
    for ed in packs["editions"]:
        files |= {a for a in packs["optional_hd"][ed]["assets"] if a.startswith("Textures/")}
    files |= {a for a in packs["common_pack"]["optional"]["assets"] if a.startswith("Textures/")}
    for t in list(files):
        if t.endswith("_normal_specular.png"):
            m = t.replace("_normal_specular.png", "_metallic_smoothness.png")
            if os.path.exists(os.path.join(A, m)): files.add(m)
    out = [(t, os.path.join(A, t)) for t in sorted(files)]
    for pattern in ("Resources/GoF2SkyHd/*.png", "Resources/GoF2SkyHd/*.bytes", "Resources/GoF2SkyLayers/patch_*.png",
                    "Resources/GoF2Planets3D/*/*.png", "Resources/GoF2Planets3D/*/*.json"):
        for f in sorted(glob.glob(os.path.join(A, pattern))):
            out.append((os.path.relpath(f, A).replace(os.sep, "/"), f))
    return out


def write(path, manifest, files):
    tmp = path + ".tmp"
    total = 0
    with zipfile.ZipFile(tmp, "w", zipfile.ZIP_STORED, allowZip64=True) as z:   # (pngs are compressed already)
        for rel, src in files:
            z.write(src, rel); total += os.path.getsize(src)
        manifest.update(files=len(files), bytes=total)
        z.writestr("gof2pack.json", json.dumps(manifest))
    os.replace(tmp, path)
    print(f"{os.path.basename(path)}: {len(files)} files, {total / 1e6:.0f} MB")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--project", required=True)
    ap.add_argument("--out", default=os.path.expanduser("~/GOF2UnityRemakeMods/packs"))
    ap.add_argument("--version", type=int, default=int(datetime.date.today().strftime("%Y%m%d")))
    a = ap.parse_args()
    packs = json.load(open(os.path.join(ROOT, "Reference", "player_assets", "packs.json")))
    os.makedirs(a.out, exist_ok=True)
    files = hd_files(a.project, packs)
    missing = [r for r, s in files if not os.path.exists(s)]
    if missing: raise SystemExit(f"missing in the project: {missing[:5]}")
    write(os.path.join(a.out, "gof2_hd.gof2pack"),
          {"name": "hd", "title": "HD pack", "version": a.version, "order": 2, "edition": ""}, files)


if __name__ == "__main__":
    main()
