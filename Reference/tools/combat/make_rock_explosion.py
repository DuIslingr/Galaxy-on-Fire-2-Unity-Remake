"""Remake: a rock-coloured copy of the asteroid explosion texture for the ordinary asteroids.

The original shares one billboard (mesh 0x4213, asteroid_explosion.png) between Explosion types 2 (asteroid_01) and
3 (the Void asteroid): its top-left cell is a spray of purple fragments that suits the Void Crystals but not ordinary
rock. This copy keeps every pixel's brightness and alpha but gives the fragment cell asteroid_01_diffuse's colour; the
smoke cell (top right) stays as it is.

Writes Assets/Resources/GoF2Combat/asteroid_explosion_rock.png (OrbitBuilder.SpawnAsteroids hands it to the ordinary
asteroids' Target.explosionTexture). Run from the project root: python Reference/tools/combat/make_rock_explosion.py
"""
from PIL import Image

SRC = "Assets/Textures/main/misc/asteroid_explosion.png"
ROCK = "Assets/Textures/main/misc/asteroid_01_diffuse.png"
OUT = "Assets/Resources/GoF2Combat/asteroid_explosion_rock.png"


def lum(r, g, b):
    return 0.299 * r + 0.587 * g + 0.114 * b


def main():
    im = Image.open(SRC).convert("RGBA")
    rock = Image.open(ROCK).convert("RGB").resize((64, 64))
    px = list(rock.get_flattened_data() if hasattr(rock, "get_flattened_data") else rock.getdata())
    avg = [sum(p[i] for p in px) / len(px) for i in range(3)]
    ref = lum(*avg)
    tint = [c / ref for c in avg]          # the rock's colour at brightness 1

    w, h = im.size
    data = im.load()
    for y in range(h // 2):                # the fragment cell: the top-left quarter
        for x in range(w // 2):
            r, g, b, a = data[x, y]
            if a == 0:
                continue
            l = lum(r, g, b) * 1.15        # the purple read brighter than its luminance; a little lift
            data[x, y] = tuple(min(255, round(l * t)) for t in tint) + (a,)
    im.save(OUT)
    print("wrote", OUT, "tint", [round(t, 3) for t in tint])


if __name__ == "__main__":
    main()
