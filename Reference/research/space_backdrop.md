# Space backdrop: sun, lens flare, planets, rings, skybox layers

How the original draws the backdrop of a star system, recovered from `libgof2hdaa.so`. The work was done with the decompiled code, capstone disassembly for the floats the decompiler lost, and the data tables in the binary. Everything here is in **GAME units**; the Unity conversion is `(x, y, -z) * 0.05`. Angles are radians, and the angular sizes given are the full width.

Reproduction script: `Reference/research/space_backdrop_sim.py`. It runs the engine RNG and prints the layout for every station; the tables in the appendix come from it.

## Functions

| Function | Address | Role |
|---|---|---|
| `Level::createSpace` | 0xbbba0 | picks the sky meshes and textures, the random sky rotation (seeded) and the extra sky layers; creates the `StarSystem` |
| `Level::renderBG` | 0xd43f0 | draws the whole backdrop with no depth test: sky layers, then `StarSystem::render`, then the extra layers |
| `Level::render` | 0xd4950 | 3D scene; the **last** call is `StarSystem::renderSunStreak` |
| `Level::render2D` / `MGame::OnRender2D` | 0xd4ae8 / 0x1b10bc | calls `StarSystem::render2D` (lens flare) |
| `StarSystem::StarSystem(int mode)` | 0x15c200 | sun and planet textures, scales and directions (seeded RNG); the ring |
| `StarSystem::initLight` | 0x15d080 | ambient, rim, two GL lights, fog |
| `StarSystem::render` | 0x15db84 | per frame: sun billboard, sun-streak matrix, orbit-planet zoom, planets, ring |
| `StarSystem::renderSunStreak` | 0x15db3c | streak quad, additive |
| `StarSystem::render2D` | 0x15dfc0 | projects the sun and calls `LensFlare::render2D` |
| `StarSystem::getLightDirection` | 0x15d812 | returns `this+0x30` (unit vector **toward** the sun) |
| `StarSystem::switchPlanetForIntro`, `switchSunForSupernova{Intro,Expansion,Reversal}`, `scaleSunDuringSupernovaIntro`, `updateSupernova` | 0x15d820, 0x15d904 / 0x15da20 / 0x15d8a0, 0x15da68, 0x15dad4 | campaign special cases (called from `LevelScript`) |
| `LensFlare::LensFlare` / `update` / `render2D` | 0x142130 / 0x1421ba / 0x1421c0 | 2D flare |
| `Status::inPlanetRingOrbit` / `orbitHasPlanetRing` / `inStormOrbit` / `inFogSkyboxOrbit` / `inSupernovaSystem` / `inAlienOrbit` | 0xb8f76 / 0xb8fac / 0xb8fca / 0xb904e / 0xb9014 / 0xb6810 | layer conditions |
| `PaintCanvas::SetBlendMode` / `BeginBG` | 0x86df4 / 0x886f0 | blend-mode enum, background render state |
| `AEMath::MatrixSetRotation(m,x,y,z)` / `MatrixGetLookAt` / `MatrixSetScaling` | 0x8b09c / 0x8b73c / 0x8b56c | math conventions (below) |
| `AERandom::setSeed` / `nextInt(n)` | 0x7ad04 / 0x7add2 | the engine RNG is **exactly `java.util.Random`** (the 48-bit LCG 0x5DEECE66D, `nextInt(n)` with the power-of-two fast path and the rejection loop) |

### Engine conventions used below
- Matrices are row-major 3x4: the columns are the local X, Y and Z axes, and the translation is m[3], m[7], m[11]. `MatrixGetDir` = local **+Z**. `AEGeometry::moveForward(d)`: `pos += normalize(localZ) * d`.
- `MatrixSetRotation(x, y, z)` (the rotation order used by `AEGeometry`, which defaults to 0) builds **R = Rx(x) * Ry(y) * Rz(z)** for column vectors. This was checked against the disassembly: m[2] = sin y, m[6] = -sin x cos y, m[10] = cos x cos y.
- `MatrixGetLookAt(eye, target, up)`: z = normalize(eye - target), x = normalize(up × z), y = z × x, pos = eye.
- `MatrixSetScaling(m, sx, sy, sz)` **multiplies** the local axes. It also modifies its input matrix in place, which matters for the streak.
- The camera looks along its local **-Z** (`CameraIsPointinViewFrustum`).
- Everything in the backdrop is drawn at `position + cameraPosition` every frame, so it stays at infinity. Sun and planets sit 20000 units from the camera; the sky meshes are spheres of radius about 400 (nebula) and 450 (stars).
- Blend modes (`SetBlendMode`):
  - 0 = opaque (culling on, blending off, depth write on)
  - 1 = alpha (`SRC_ALPHA, ONE_MINUS_SRC_ALPHA`, depth write off)
  - 2 = **additive** (`ONE, ONE`, depth write off)
  - 8 = alpha + lighting
  - 21 = alpha with texture RGB + vertex colour (fixed-function `GL_ADD` combiner; used to tint fogged planets)
- `BeginBG`: depth test off, depth write off, frustum culling off, so the backdrop is drawn in painter's order.
- The shared quad `plane` (mesh id 6768 = `Models/main/misc/plane.fbx`) is a **double-sided** square of ±32500 units in XY, with u along +X and v along +Y. Its world size is `65000 * scale`.

## Draw order in one frame

1. `Level::renderBG` (camera rotation only, no translation, no depth):
   1. **stars sphere**, blend 0 (opaque)
   2. **nebula sphere**, blend 2 (additive). Both are rotated by the sky rotation R_sky.
   3. [ring-orbit sky layer, blend 1; not rotated by R_sky]
   4. `StarSystem::render`:
      - index 0 is the **sun** billboard, blend 2
      - indices 1..n are the **planets**, blend 1 (21 when fog is on)
      - the **ring** follows its planet, blend 1
   5. [supernova flare meshes, blend 2]
   6. [storm layer, blend 2, re-rotated randomly every animation loop]
   7. [asteroid belt, blend 8 (lit), only if the effects setting `options+0x28` ≥ 1.0 (default 1.0)]
2. 3D scene, then `renderSunStreak`: blend 2, drawn after all objects and particles, with the 3D depth test.
3. 2D pass (alpha blending): **lens flare** and the full-screen glare.

## Skybox layers (`Level::createSpace`, `renderBG`)

| Layer | Mesh | Texture | Blend | Rule |
|---|---|---|---|---|
| stars (`Level+8`) | 17850 + (systemIndex % 3), all = `Models/main/skyboxes/skybox_stars.fbx` | `Textures/main/skyboxes/skybox_stars_00{systemIndex % 3}.png` (10086 + i) | 0 | **system index % 3**, not the nebula index. Alien orbit: mesh 17852, `skybox_stars_002` |
| nebula (`Level+4`) | 17800 + textureIndex | 10065 + textureIndex (`skybox_000`..`010`, `valkyrie/skyboxes/v_skybox_011`..`014`, `supernova/skyboxes/sn_skybox_015`..`018`) | 2 | see the exceptions below. Mesh 17814 is `v_skybox_013.fbx` reused with the `v_skybox_014.png` texture |
| planet ring sky (`Level+0x1b4`) | 18847 `supernova/skyboxes/sn_skybox_planet_ring_alpha.fbx` | 29018 `sn_skybox_planet_ring.png` | 1 | `inPlanetRingOrbit`: the current station is 120, 126, 130 or 132. Camera-centred, world-aligned |
| storms (`Level+0x1bc`) | 18848 `sn_skybox_storms_anim_add.fbx` (animated) | 29019 `sn_skybox_storms.png` | 2 | `inStormOrbit`: campaign mission ≥ 90 and (supernova system, or textureIndex 16 or 18). Gets a new random rotation (3 × `nextInt(65536)`, unseeded) each time the animation wraps |
| supernova flares (`Level+0x10`, `+0x18`) | 17824 / 17825 `sn_skybox_015_flares_{1,2}_anim.fbx` | 10084 `sn_skybox_015_flares.png` (mission < 106), otherwise 10085 `..._flares_nasty.png` | 2 | supernova system, mission ≠ 89 and < 158. Animation speed ×1.0, or ×1.5 when mission > 106 |
| asteroid belt (`Level+0x1cc`) | 14375 `skybox_asteroid_belt_alpha.fbx` | 33410 diffuse + 33411 normal/specular | 8 + light 0 | systems **24, 25, 26** only. Identity model matrix: camera-centred, world-aligned, **not** rotated by R_sky |

Nebula exceptions:
- Alien orbit (`inAlienOrbit`): 17810 / `skybox_010`. **No system uses textureIndex 10**; `skybox_010` is the Void/alien sky.
- Campaign mission 0 with `Level+0xc0 == 3` (the intro): 17803 / `skybox_003`.
- Supernova system (27 and mission < 158):
  - mission 89 (0x59): 17805 / `skybox_005`
  - otherwise: 17815 / `sn_skybox_015`, plus the flare layers
- Post-effect (bloom) on and textureIndex > 15: the nebula mesh's field `+0x1c` = 0.22 (probably a glow weight; see Uncertainties).

**Sky rotation R_sky** (shared by the stars and nebula spheres only; applied as the model matrix, `view *= R`):
- Normal case: seed = `stationIndex * 2` (seed -1 if there is no station). Draw rx, ry, rz = `nextInt(65536) / 65536 * 2π`, in that order, then R_sky = Rx(rx) · Ry(ry) · Rz(rz).
  - So the sky orientation depends on the **station (orbit)**, not the system.
  - The first draw is nearly the same for every small seed (about 263°), because that is how `java.util.Random` behaves; it is faithful.
- `inFogSkyboxOrbit` (textureIndex 17 or 18): rx = ry = rz = 0.
- **System 27** (Ginoya) when not in the alien orbit: R_sky is built from the sun direction L instead:
  - a = normalize(L), b = normalize((1,0,0) × a)
  - X = a × b, Y = a, Z = b
  - So the sky's **+Y axis points at the sun** (the supernova nebula centres on the sun).
- Unity: M_u = S · M_g · S with S = diag(1, 1, -1). For the Euler form that is `Quaternion.AngleAxis(-rx, right) * AngleAxis(-ry, up) * AngleAxis(rz, forward)` (degrees).

## StarSystem layout (`StarSystem::StarSystem`)

Arrays: `+0x1c` geometries, `+0x14` textures, `+0x20` base positions.
- Index 0 is the **sun**.
- Index i ≥ 1 is **the planet of station `system.stations[i-1]`**. There is one planet per station, in the system's station order.

All of them use the `plane` mesh. Each one gets `setRotation(pitch, yaw, 0)` and then `moveForward(-20000)`, so:

```
dir(p, y) = local +Z of Rx(p)·Ry(y) = ( sin y,  -sin p · cos y,  cos p · cos y )
position  = -20000 · dir          (relative to the camera, re-added every frame)
L (sun)   = -dir(sun)             (this+0x30, unit vector toward the sun)
yaw       = slot · 0xAAA / 65536 · 2π      (slot · 14.996°, slots 0..23)
```

Note that pitch has almost no effect near yaw ±90° (a consequence of the Rx·Ry order). The sun's elevation is `asin(sin p · cos y)`, at most ±11.25°.

**RNG:** `setSeed(currentStationIndex * 300)`, then the draws below in exactly this order. `AERandom::reset()` is called afterwards.

**Sun (index 0):**
1. `r = nextInt(14)`. This is always drawn.
2. t = the texture index of the **current station**.
   - If t is in {9, 13, 14, 18, 20}: slot = 6. If t = 21: slot = 4.
   - Otherwise slot = r + 5 (5..18), and if t = 22, slot = 16.
   - (The table is `DAT_00258e20` indexed by t-9, masked with 0x1a31.)
3. `pitch = (nextInt(4096) - 2048) / 65536 · 2π` (±11.25°).
4. Texture: `DAT_00258960[system.textureIndex]`: `Textures/main/suns/sun_000`..`010`, then 11 → `sun_001`, 12 → `sun_008`, 13 → `sun_004`, 14 → `sun_000`, 15 → `supernova/fx/sn_supernova`, 16 → `sun_007`, 17 → `sun_002`, 18 → `sun_006`.
   - Supernova overrides: if (mission == 89 and inSupernovaSystem) or (mission > 157 and system == 27), use `supernova/suns/sn_sun_011` (11742) and flare colour 3.
5. Scale: 0x3e6a6000 = **0.22888184** (= 15000/65536). That is a 14877-unit quad at 20000 units, about 40.8° wide including the halo.
   - Supernova (inSupernovaSystem): 0.99182 when mission < 106, otherwise 1.37329.
6. The sun textures are RGB with no alpha, drawn **additive**.

**The station's own planet ("orbit planet", station == current):**
1. `s = nextInt(20000) + 20000`. In campaign mission 0: `s = int(s * 0.5)`.
2. If not in a ring orbit:
   - current-station texture t in {6, 11, 12, 17}: `s = nextInt(15000) + 35000`
   - t in {9, 16}: `s = nextInt(13000) + 32500`
3. Ring orbit (stations 120, 126, 130, 132): s = 26000.
4. scale = s / 65536, stored in `+0x58`:
   - default 0.305..0.610 (53°..89°)
   - the t=6/11/12/17 case 0.534..0.763 (82°..102°)
   - the t=9/16 case 0.496..0.694
   - ring orbit 0.397 (66°)
5. slot 0, pitch 0, yaw 0, so direction (0, 0, -20000). That is straight down **game -Z**, i.e. Unity **+Z at 1000 m**. No RNG is used for the direction.
6. Texture: `DAT_00258a34[station.textureIndex]` = the `*_big` textures:
   - `Textures/main/planets/planet_000_big`..`019_big`
   - 20..22 `valkyrie/planets/v_planet_02x_big`
   - 23 `main/planets/planet_void_big`
   - 24..26 `supernova/planets/sn_planet_02x_big`
   - The intro (mode 3 in mission 0) uses `planet_001_big`, then `switchPlanetForIntro` changes it to `planet_000_big`.

**Other planets (station ≠ current):**
1. Repeat `slot = nextInt(11) + 7` (7..17) until |slot - sunSlot| ≥ 3 and the slot is free.
2. `scale = (nextInt(40) · 0.01 + 0.8) · 0.03509521484375` (double math). That is 0.0281..0.0418, i.e. 1825..2715 units, 5.2°..7.8°.
3. `pitch = (nextInt(4096) - 2048) / 65536 · 2π`.
4. Texture: `DAT_00258aa0[station.textureIndex]` = the `*_small` textures (same families; index 23 reuses `v_planet_022_small`).

**Flip (mirror):** after placement, the geometry gets `rotate(0, π, 0)` (a 180° yaw about its own vertical axis, which mirrors the texture horizontally as seen from the camera) when:
- orbit planet: `sunSlot >= 12`
- other planets: `planetSlot > sunSlot` (the code's test is `!(sun-planet < 12) || sun <= planet`, and the first clause can never be true)
- In other words: flip when `wrap(yaw_planet - yaw_sun) > 0`. The planet PNGs have their lit rim on the **right**, so the flip is meant to put the lit side toward the sun (see Uncertainties).

**Planets are not billboards.** Each one keeps its fixed world orientation (a quad facing the origin, up = (0, cos p, sin p)); only the position follows the camera. The sun **is** a billboard (below).

**Ring:** for every planet other than the current one whose station has a ring (`orbitHasPlanetRing`: stations 120, 126, 130, 132, via mask 0x1441 over 120..132):
- a second `plane` with texture 29080 `Textures/supernova/planets/sn_planet_ring.png`, blend 1
- drawn right after that planet with **the planet's matrix × 4** (same centre, same orientation and flip), so it is 4× the planet size
- The ring's own orbit shows the sky-ring layer instead (see the sky table).

**Void branch** (`Status::getSystem() == 0`):
- sun `sun_010` at scale 0.2289, rotation 0, so it sits at (0, 0, -20000) and L = (0, 0, -1)
- one planet `planet_void_big` with scale (rand(20000) + 20000) / 65536 (unseeded), rotation (0, 5.2347097, 0)
- streak scale (0.4577, 0.0458, 0.2289)

**Post-effect tweak:** with bloom on, when system.textureIndex > 14, the `plane` mesh field `+0x1c` = 0.22. The same happens for the streak mesh in the supernova system. The mesh is shared, so this affects the sun and the planets together.

## Per-frame rendering (`StarSystem::render`, `renderSunStreak`, `LensFlare`)

Let `C` be the camera position, `(sx, sy, sz)` the sun scale, and `I` the flare intensity from the **previous** 2D pass (`LensFlare+0`; `update()` zeroes it every frame before `render2D` recomputes it).

- **Sun billboard:**
  - M = LookAt(eye = sunPos + C, target = C, up = camera up). Local +Z points away from the viewer, and the sun rolls with the camera, so its baked horizontal spike stays horizontal on screen.
  - `e = max((I - 10) / 64, 0)`, then `M.scale(sx + e, sy + e, sz)`. The **sun swells when it is near the screen centre**: at the centre, I = 64 gives e = 0.84, about 4.7× the size.
  - Supernova: up = (1, 0, 0) and no swelling; a second streak is drawn inline with the sun scale × 0.3 and texture `sn_sun_011`.
- **Sun streak** (mesh `+0x40`, texture = the sun texture, or `sn_sun_011` in the supernova system, blend 2, drawn at the end of `Level::render`):
  - Its matrix is the **already-scaled** sun matrix, scaled again by `(e · (sx + e + 1), sy / ((1 - e) · 6 + 6), sz)`.
  - Resulting world size = 65000 × `(sx + e) · e · (sx + e + 1)` wide by 65000 × `(sy + e) · sy / (12 - 6e)` tall.
  - At e = 0 it has zero width (invisible). At e = 0.84 it is about 122000 × 2300 units: a horizontal lens streak across the screen.
  - The constructor scales for the streak (0.4577, 0.0458, 0.2289; supernova 1.98, 0.198, 0.992) are overwritten by this `setMatrix`.
- **Orbit-planet zoom** (not in the void, not in a ring orbit):
  - `f = clamp(C.z / -800000, -0.2, +0.2)` → `+0x5c` (`getPlanetScaleFactor`)
  - scale = base + f, uniform
  - The planet grows as you fly toward it along game -Z (maximum +0.2, reached at C.z = -160000).
- **Planets:** `setPosition(basePos + C)`, blend 1 (21 if fog is on), then the ring.
- **Lens flare** (`StarSystem::render2D` → `LensFlare::render2D(x, y, z, colourIdx)`):
  - The projected point is `C + L · 65536`. The flare is drawn only if `GetScreenPosition` succeeds, the projected z < 0 (in front), and −W < x < 2W, −H < y < 2H, where W and H are the canvas size.
  - **There is no occlusion test at all**: the flare shows even behind stations and ships.
  - `d` = the distance in pixels from the screen centre `(W/2, H/2)` to the sun.
  - `I = K · (1 - d / (H/2))`, with K = 64, or 80 for colour index 5. I is negative once the sun is more than H/2 from the centre.
  - Colour `(R, G, B)` by `colourIdx = DAT_002589ac[systemIndex]` (tables `DAT_00258530` / `DAT_00258510` / `DAT_002584f0`):
    - 0 = (200, 200, 255) blue
    - 1 = (200, 255, 200) green
    - 2 = (255, 200, 200) red
    - 3 = (255, 255, 255) white
    - 4 = (255, 255, 200) yellow
    - 5 = white, with K = 80 (Ginoya only)
  - The elements are 2D images from `Textures/textures/gof2_interface.png` (64×64 regions from `_texture_manifest.json`):
    - img0 = id 1288 at [71, 934]
    - img1 = 1289 at [160, 902]
    - img2 = 1290 at [285, 601]
  - Each element sits at `centre + (sun - centre) · t` and is **centred** on that point. Anchor 0x11 means screen top-left; pivot 0x44 means the image centre.
  - Sizes are relative to the image width w (64 px); alpha is out of 255, and negative values clamp to 0:

    | # | image | t | size | alpha |
    |---|---|---|---|---|
    | 1 | img0 | 0.5 | 1.0w | 70 + I |
    | 2 | img0 | 0.25 | 0.75w | 70 + I |
    | 3 | img1 | 0.75 | 0.5w | 70 + I |
    | 4 | img0 | 0.125 | 1.25w | 40 + I (only if I > -40) |
    | 5 | img1 | 1/11 | 0.5w | 70 + I |
    | 6 | img2 | -0.75 | 2.0w | 70 + I |
    | 7 | img2 | -0.2 | 0.5w | 70 + I |
    | glare | full-screen rect | - | - | `int(I)` (only if I > 0; at most 25% or 31%) |

  - The elements are alpha blended (the `Begin2d` state) and tinted with the flare colour.

## Lighting (`StarSystem::initLight`): yes, the sun direction lights the ships

Colour tables:
- sunColour = `DAT_00258b0c[3·tex]` (tex = system.textureIndex; the void uses row 10)
- rimTab = `DAT_00258d34[3·tex]`
- planetTab = `DAT_00258bf0[3·stationTex]` (stationTex = the current station's texture)

| Call | Value |
|---|---|
| engine `+0x31c` | 2 (light count) |
| `LightSetGlobalSceneColorAmbient` | kA · sunColour, kA = 0.15. For tex 15 with mission ≠ 89 and < 158, kA = 0.7 |
| `LightSetRimColor` | 3 · rimTab |
| material ambient / diffuse / specular / shininess | 1, 1, 1 / 20 |
| **LIGHT0** direction | **L** (unit vector toward the sun; `this+0x30`, the same vector used for the sun and the flare) |
| LIGHT0 ambient / diffuse / specular | 0 / `clamp(kD · sunColour, 0, 2)` per channel, kD = 15 (30 for tex 15 pre-supernova) / (2, 2, 2) |
| **LIGHT1** direction | (0, 0, -1), i.e. **toward the orbit planet** at game -Z: planet-shine |
| LIGHT1 diffuse = specular | 1.5 · planetTab. Void: indexed with the constant 23 **without** ×3, so (0.11, 0.18, 0.25) × 1.5 |
| `LightSetParticleAmbient` | sunColour |
| supernova reversal (tex 15 and (mission 89 or ≥ 158)) | sunColour × 0.5 first |

With kD = 15, LIGHT0 saturates at 2.0 for any channel ≥ 0.134. That makes it white ×2 for most systems; the only exceptions are tex 5 (2, 1.95, 1.65) and tex 12 (1.2, 2, 2).

L is also used:
- by `PlayerEgo::update`: an attached geometry (`+0x34`) is `setDirection(L, up (0, 1, 0))`
- by `Level::createStaticObjects`: one static object faces L
- by `Level::initParticleSystems`: in the supernova, the particle wind is `-L · 2000`

**Fog** (the `GL_LINEAR` fog enabled in `initLight`; start 0, `+0x54` = 1):

| textureIndex | colour | end (units) |
|---|---|---|
| 11 | #db6923 | 50000 |
| 12 | #163e7c | 50000 |
| 15 (mission ≠ 89) | #82441f | 100000 |
| 16 | #47665e | 150000 |
| 17 | #738d95 | 150000 |
| 18 | #aba075 | 150000 |

In fog systems every planet (index ≥ 1) is drawn with blend 21 and transform colour = 0.7 × fog RGB (tex 15: the full fog colour), which adds the fog tint to the planet texture. The sky spheres (r ≈ 400) are practically unaffected by the fog.

`systems.json unknownTriple` is the system's RGB flash colour (`Level::flashScreen` → `i_r / i_g / i_b`, with `r_min = r/3`), used for explosion and EMP screen flashes, not for the backdrop. The void default is (10, 136, 10).

## Comparison with `SkyboxBaker.cs` (mismatches)

1. **Wrong stars layer.** The baker uses `skybox_stars_{nebulaIndex % 3}`; the game uses `systemIndex % 3`. A sky is really the pair (textureIndex, systemIndex % 3). For example, Suteo (system 0) is `skybox_004` with `stars_000`, but the baker bakes `004` with `stars_001`. About 2/3 of the systems get the wrong stars.
2. **Only 000..010 are baked.** Systems 22..32 use `v_skybox_011`..`014` and `sn_skybox_015`..`018` (textureIndex 11..18), which are loaded from `Models/valkyrie|supernova/skyboxes/...`. `LoadMesh($"Models/main/skyboxes/{name}")` cannot find them. Index 14 must use the mesh `v_skybox_013.fbx` with the texture `v_skybox_014.png`.
3. `skybox_010` is the Void/alien sky (always with `stars_002`), not a system sky.
4. **No orientation.** Both layers are rotated per station by R_sky (random Euler XYZ, seeded with stationIndex·2), zero in the tex 17/18 systems, and sun-aligned in system 27. `Skybox/Cubemap` only supports a Y rotation, so this needs a custom skybox shader (sample with R_skyᵀ · dir) or a camera-centred sky mesh.
5. The extra layers are not in the bake: ring sky, storms, supernova flares, asteroid belt. They are camera-centred and drawn after the sun and planets (the ring sky is drawn before them). The ring sky, the storms (their own random rotation) and the belt are world-aligned; **the supernova flares keep `renderBG`'s view · R_sky matrix** (Level+0x1d0 is only reset for the ring and storm layers), so in system 27 they are sun-aligned like the nebula: the fire streams out of the supernova.
6. Draw order and blending are correct: stars opaque, then nebula additive. The stars sphere (r 450) lies outside the nebula sphere (r 400), but with no depth test only the draw order matters.

## Unity rebuild cheat-sheet
- Place the sun and planets 1000 m from the camera (20000 × 0.05) in a background pass with no depth, drawn after the sky and before the scene. Quad size = 3250 m × scale (65000 × 0.05). Directions: `(x, y, -z)` of the game vectors above.
- Sun: additive camera-facing quad with the camera's up; swelling from e; horizontal streak drawn after the scene (additive).
- Directional light: forward = `-(Lx, Ly, -Lz)`, intensity from `clamp(15 · sunColour, 0, 2)`. Second light from Unity +Z (toward the orbit planet) coloured 1.5 · planetTab. Ambient kA · sunColour.
- Flare: UI Toolkit or screen-space overlay with the element table above; no occlusion.

## Uncertainties
- **Flip handedness.** From the matrices, the unflipped quad shows the PNG un-mirrored to a camera at the origin (u → +X = screen right), and the flip rule then puts the lit (right) rim *away* from the sun. That is implausible, so either the FBX X axis or the game→Unity mirror is off for flat quads. Implement the intent: mirror each planet so its lit rim faces the sun's side on screen. Check against footage.
- The LIGHT0 diffuse clamp to [0, 2] was read from branchy VFP code; the decompiler showed only one channel. LIGHT1 direction (0, 0, -1): world versus eye space is not confirmed (it depends on the modelview at `LightSetLightDirection` time). World space fits the planet-shine reading.
- `view *= R_sky` was assumed to be `view · R` (model rotation), not `R · view`.
- Mesh field `+0x1c` = 0.22 under the post effect: the meaning is unknown (likely a bloom or glow weight).
- The storm-layer random rotation arguments were lost by the decompiler; it is assumed to be three random Euler angles.
- The lens-flare image sizes use `GetImage2DWidth` (64 at the base resolution); the HD scaling of 2D images was not checked.
- The void-branch trigger (`Status::getSystem() == 0`) was not traced to a game situation.
- Campaign scripts (`LevelScript`) change the sun during the supernova (`switchSunForSupernova*`, sun scale + t·4e-5 per ms during the intro, explosion meshes 11761 / 11762, textures 11763 / 11764); only the constructor paths are documented here.
- Station textureIndex comes from `stations.json`. It is assumed to match `Station::getTextureIndex` and `loadStationsBinary` order = `systems.json stations` order.

## Appendix A: per-system selection (all 34 systems)

Nebula = `17800 + tex` / texture `10065 + tex`. Stars = `skybox_stars_{sys % 3}`. Sun texture = `DAT_00258960[tex]`. Flare colour = `DAT_002589ac[sys]`. The sun colour feeds the ambient and LIGHT0; the rim colour is multiplied by 3.

| sys | name | tex | stars layer | nebula layer | sun texture | flare col | sun colour (0x258b0c) | rim colour (0x258d34) | fog | extra layers |
|---|---|---|---|---|---|---|---|---|---|---|
| 0 | Suteo | 4 | skybox_stars_000 | skybox_004 | sun_004 | 3 | [0.18, 0.23, 0.27] | [0.18, 0.23, 0.27] | - | - |
| 1 | Pan | 2 | skybox_stars_001 | skybox_002 | sun_002 | 1 | [0.24, 0.4, 0.37] | [0.24, 0.4, 0.37] | - | - |
| 2 | Behén | 9 | skybox_stars_002 | skybox_009 | sun_009 | 3 | [0.43, 0.47, 0.47] | [0.43, 0.47, 0.47] | - | - |
| 3 | V'ikka | 5 | skybox_stars_000 | skybox_005 | sun_005 | 2 | [0.38, 0.13, 0.11] | [0.38, 0.13, 0.11] | - | - |
| 4 | Eanya | 8 | skybox_stars_001 | skybox_008 | sun_008 | 0 | [0.21, 0.23, 0.27] | [0.21, 0.23, 0.27] | - | - |
| 5 | S'kolptorr | 9 | skybox_stars_002 | skybox_009 | sun_009 | 3 | [0.43, 0.47, 0.47] | [0.43, 0.47, 0.47] | - | - |
| 6 | Wolf-Reiser | 0 | skybox_stars_000 | skybox_000 | sun_000 | 1 | [0.21, 0.32, 0.25] | [0.21, 0.32, 0.25] | - | - |
| 7 | Aquila | 7 | skybox_stars_001 | skybox_007 | sun_007 | 4 | [0.24, 0.26, 0.25] | [0.24, 0.26, 0.25] | - | - |
| 8 | Buntta | 1 | skybox_stars_002 | skybox_001 | sun_001 | 2 | [0.5, 0.29, 0.28] | [0.5, 0.29, 0.28] | - | - |
| 9 | Weymire | 7 | skybox_stars_000 | skybox_007 | sun_007 | 4 | [0.24, 0.26, 0.25] | [0.24, 0.26, 0.25] | - | - |
| 10 | Y'mirr | 6 | skybox_stars_001 | skybox_006 | sun_006 | 1 | [0.34, 0.34, 0.3] | [0.34, 0.34, 0.3] | - | - |
| 11 | Union | 3 | skybox_stars_002 | skybox_003 | sun_003 | 3 | [0.22, 0.32, 0.43] | [0.22, 0.32, 0.43] | - | - |
| 12 | Oom'bak | 0 | skybox_stars_000 | skybox_000 | sun_000 | 1 | [0.21, 0.32, 0.25] | [0.21, 0.32, 0.25] | - | - |
| 13 | Vulpes | 4 | skybox_stars_001 | skybox_004 | sun_004 | 3 | [0.18, 0.23, 0.27] | [0.18, 0.23, 0.27] | - | - |
| 14 | Magnetar | 5 | skybox_stars_002 | skybox_005 | sun_005 | 2 | [0.38, 0.13, 0.11] | [0.38, 0.13, 0.11] | - | - |
| 15 | Mido | 9 | skybox_stars_000 | skybox_009 | sun_009 | 3 | [0.43, 0.47, 0.47] | [0.43, 0.47, 0.47] | - | - |
| 16 | Prospero | 3 | skybox_stars_001 | skybox_003 | sun_003 | 3 | [0.22, 0.32, 0.43] | [0.22, 0.32, 0.43] | - | - |
| 17 | Nesla | 8 | skybox_stars_002 | skybox_008 | sun_008 | 0 | [0.21, 0.23, 0.27] | [0.21, 0.23, 0.27] | - | - |
| 18 | Pescal Inartu | 1 | skybox_stars_000 | skybox_001 | sun_001 | 2 | [0.5, 0.29, 0.28] | [0.5, 0.29, 0.28] | - | - |
| 19 | Augmenta | 6 | skybox_stars_001 | skybox_006 | sun_006 | 1 | [0.34, 0.34, 0.3] | [0.34, 0.34, 0.3] | - | - |
| 20 | K'ontrr | 1 | skybox_stars_002 | skybox_001 | sun_001 | 2 | [0.5, 0.29, 0.28] | [0.5, 0.29, 0.28] | - | - |
| 21 | Ni'mrrod | 9 | skybox_stars_000 | skybox_009 | sun_009 | 3 | [0.43, 0.47, 0.47] | [0.43, 0.47, 0.47] | - | - |
| 22 | Beidan | 12 | skybox_stars_001 | v_skybox_012 | sun_008 | 2 | [0.08, 0.24, 0.48] | [0.08, 0.24, 0.48] | #163e7c 0..50000 | - |
| 23 | Herjaza | 11 | skybox_stars_002 | v_skybox_011 | sun_001 | 0 | [0.85, 0.41, 0.14] | [0.2, 0.11, 0.04] | #db6923 0..50000 | - |
| 24 | Skavac | 13 | skybox_stars_000 | v_skybox_013 | sun_004 | 3 | [0.2, 0.25, 0.2] | [0.2, 0.25, 0.2] | - | asteroid belt |
| 25 | Loma | 14 | skybox_stars_001 | v_skybox_014 (mesh v_skybox_013) | sun_000 | 1 | [0.3, 0.35, 0.15] | [0.3, 0.35, 0.15] | - | asteroid belt |
| 26 | Shima | 1 | skybox_stars_002 | skybox_001 | sun_001 | 2 | [0.5, 0.29, 0.28] | [0.5, 0.29, 0.28] | - | asteroid belt |
| 27 | Ginoya | 15 | skybox_stars_000 | sn_skybox_015 | sn_supernova | 5 | [1.0, 0.52, 0.24] | [0.5, 0.26, 0.12] | #82441f 0..100000 | storms (mission>=90), supernova flares, sun/sky special |
| 28 | Talidor | 17 | skybox_stars_001 | sn_skybox_017 | sun_002 | 3 | [0.41, 0.52, 0.58] | [0.41, 0.52, 0.58] | #738d95 0..150000 (no sky rot.) | - |
| 29 | Paréah | 16 | skybox_stars_002 | sn_skybox_016 | sun_007 | 3 | [0.39, 0.48, 0.44] | [0.39, 0.48, 0.44] | #47665e 0..150000 | planet ring (st 120), storms (mission>=90) |
| 30 | Me'enkk | 9 | skybox_stars_000 | skybox_009 | sun_009 | 3 | [0.43, 0.47, 0.47] | [0.43, 0.47, 0.47] | - | planet ring (st 126) |
| 31 | Wah'norr | 18 | skybox_stars_001 | sn_skybox_018 | sun_006 | 3 | [0.67, 0.63, 0.46] | [0.67, 0.63, 0.46] | #aba075 0..150000 (no sky rot.) | planet ring (st 130), storms (mission>=90) |
| 32 | Skor Terpa | 13 | skybox_stars_002 | v_skybox_013 | sun_004 | 3 | [0.2, 0.25, 0.2] | [0.2, 0.25, 0.2] | - | planet ring (st 132) |
| 33 | Alda | 7 | skybox_stars_000 | skybox_007 | sun_007 | 3 | [0.24, 0.26, 0.25] | [0.24, 0.26, 0.25] | - | - |

## Appendix B: per-station layout (the default, not campaign mission 0)

Generated by `space_backdrop_sim.py`.
- sun slot → yaw = slot · 14.996°; pitch in degrees
- L = unit vector toward the sun in game space (Unity: negate z)
- orbit planet: scale, with `F` = flipped
- far planets: `station:slot/pitch/scale[/F flipped][/R has ring]`
- sky Euler (rx, ry, rz) in degrees, game convention R = Rx·Ry·Rz

| sys | station (tex) | sun slot / pitch | light dir L (game) | orbit planet: scale, flip | far planets: station:slot/pitch/scale/flip | sky Euler XYZ (deg) |
|---|---|---|---|---|---|---|
| 0 | 0 (0) | 17 / 7.45 | (0.9656, -0.0337, 0.2577) | 0.4277 F | 1:12/-4.30/0.0404 2:9/2.19/0.0284 3:7/-5.56/0.0411 4:8/-10.73/0.0295 | 263.1, 299.3, 86.6 |
| 0 | 1 (15) | 14 / 6.67 | (0.4992, -0.1006, 0.8606) | 0.5038 F | 0:11/5.27/0.0414 2:7/-8.71/0.0354 3:9/-0.87/0.0361 4:8/0.44/0.0354 | 263.2, 105.6, 324.5 |
| 0 | 2 (11) | 13 / 3.19 | (0.2580, -0.0537, 0.9646) | 0.6885 F | 0:8/1.49/0.0326 1:9/8.86/0.0288 3:10/-10.15/0.0319 4:7/-3.77/0.0344 | 263.0, 326.7, 330.7 |
| 0 | 3 (19) | 13 / -3.52 | (0.2580, 0.0593, 0.9643) | 0.4280 F | 0:8/9.37/0.0358 1:17/-1.43/0.0351/F 2:16/8.03/0.0319/F 4:7/-1.00/0.0400 | 263.1, 133.0, 208.7 |
| 0 | 4 (8) | 12 / -7.00 | (-0.0008, 0.1219, 0.9925) | 0.3802 F | 0:15/5.59/0.0411/F 1:7/-10.87/0.0368 2:9/-9.91/0.0284 3:8/9.14/0.0309 | 262.9, 354.1, 214.9 |
| 1 | 5 (3) | 9 / -7.79 | (-0.7075, 0.0958, 0.7002) | 0.4669 | 6:16/-3.64/0.0386/F 7:15/-3.47/0.0397/F 8:12/-10.71/0.0333/F 9:17/-3.94/0.0330/F | 263.0, 160.4, 92.8 |
| 1 | 6 (10) | 11 / -3.49 | (-0.2595, 0.0589, 0.9639) | 0.3061 | 5:17/-8.39/0.0344/F 7:16/-10.65/0.0323/F 8:7/5.77/0.0379 9:8/4.38/0.0344 | 262.8, 21.5, 99.0 |
| 1 | 7 (14) | 6 / -5.99 | (-1.0000, -0.0000, -0.0004) | 0.3585 | 5:15/-9.58/0.0390/F 6:17/-6.22/0.0368/F 8:14/-7.76/0.0386/F 9:10/10.12/0.0326/F | 262.8, 187.8, 337.0 |
| 1 | 8 (13) | 6 / 6.93 | (-1.0000, 0.0000, -0.0004) | 0.4143 | 5:10/-1.79/0.0340/F 6:9/4.25/0.0400/F 7:16/-8.08/0.0351/F 9:14/3.52/0.0376/F | 263.7, 189.7, 190.0 |
| 1 | 9 (17) | 18 / -2.47 | (1.0000, 0.0000, 0.0011) | 0.7498 F | 5:9/0.13/0.0316 6:13/10.42/0.0302 7:12/4.60/0.0407 8:14/5.06/0.0365 | 263.7, 356.0, 67.9 |
| 2 | 30 (1) | 6 / -2.77 | (-1.0000, -0.0000, -0.0004) | 0.4725 | 31:14/0.97/0.0309/F 32:12/8.40/0.0400/F 33:15/7.33/0.0372/F | 262.2, 131.2, 355.6 |
| 2 | 31 (8) | 5 / -6.26 | (-0.9658, -0.0282, -0.2576) | 0.6028 | 30:17/-7.79/0.0414/F 32:9/4.71/0.0418/F 33:14/-9.40/0.0418/F | 262.3, 297.5, 233.5 |
| 2 | 32 (13) | 6 / 9.54 | (-1.0000, 0.0001, -0.0004) | 0.5766 | 30:13/6.87/0.0361/F 31:17/-4.55/0.0393/F 33:14/3.93/0.0358/F | 261.1, 17.8, 32.9 |
| 2 | 33 (9) | 6 / -2.75 | (-1.0000, -0.0000, -0.0004) | 0.5966 | 30:11/1.93/0.0365/F 31:10/7.22/0.0393/F 32:14/6.05/0.0351/F | 261.1, 184.1, 270.8 |
| 3 | 15 (17) | 6 / -3.63 | (-1.0000, -0.0000, -0.0004) | 0.6088 | 16:14/1.09/0.0379/F 17:17/6.58/0.0305/F 18:16/4.34/0.0281/F 19:15/9.34/0.0386/F | 263.3, 78.2, 80.4 |
| 3 | 16 (4) | 18 / -2.21 | (1.0000, 0.0000, 0.0011) | 0.3390 F | 15:7/-6.92/0.0379 17:13/-9.70/0.0305 18:9/10.35/0.0397 19:8/-10.07/0.0354 | 262.1, 158.6, 239.7 |
| 3 | 17 (18) | 6 / -2.99 | (-1.0000, -0.0000, -0.0004) | 0.4408 | 15:15/-4.74/0.0347/F 16:11/0.79/0.0407/F 18:13/10.34/0.0368/F 19:17/-4.75/0.0309/F | 262.2, 324.9, 117.7 |
| 3 | 18 (5) | 18 / -3.60 | (1.0000, 0.0001, 0.0011) | 0.6031 F | 15:9/-1.79/0.0291 16:8/1.68/0.0400 17:13/-3.42/0.0288 19:10/-9.15/0.0354 | 262.0, 186.0, 123.9 |
| 3 | 19 (6) | 18 / -2.18 | (1.0000, 0.0000, 0.0011) | 0.6601 F | 15:8/-0.99/0.0383 16:13/6.76/0.0418 17:11/-0.69/0.0316 18:9/2.91/0.0397 | 262.1, 352.3, 1.8 |
| 4 | 20 (11) | 16 / 5.83 | (0.8655, -0.0509, 0.4983) | 0.5351 F | 21:13/-6.03/0.0414 22:10/-0.53/0.0326 23:9/-5.10/0.0372 24:11/6.69/0.0365 | 261.9, 213.4, 8.0 |
| 4 | 21 (14) | 6 / -2.59 | (-1.0000, -0.0000, -0.0004) | 0.3925 | 20:16/-1.11/0.0323/F 22:12/-7.75/0.0288/F 23:15/2.72/0.0383/F 24:10/-10.50/0.0361/F | 261.9, 19.7, 246.0 |
| 4 | 22 (3) | 8 / 10.33 | (-0.8663, -0.0896, 0.4915) | 0.4742 | 20:11/6.69/0.0414/F 21:14/0.40/0.0323/F 23:17/-0.26/0.0414/F 24:16/10.68/0.0414/F | 261.7, 240.8, 252.2 |
| 4 | 23 (5) | 7 / 6.85 | (-0.9660, -0.0308, 0.2565) | 0.3662 | 20:16/-3.85/0.0340/F 21:14/-9.46/0.0407/F 22:12/-5.19/0.0344/F 24:17/8.64/0.0288/F | 261.8, 47.1, 130.1 |
| 4 | 24 (7) | 8 / 11.15 | (-0.8663, -0.0966, 0.4901) | 0.3960 | 20:16/10.44/0.0305/F 21:17/10.48/0.0330/F 22:12/-5.49/0.0281/F 23:13/-1.16/0.0358/F | 262.6, 48.9, 343.2 |
| 5 | 25 (0) | 6 / 10.36 | (-1.0000, 0.0001, -0.0004) | 0.4412 | 26:16/-6.09/0.0319/F 27:14/-0.42/0.0400/F 28:12/-5.58/0.0393/F 29:17/-4.07/0.0361/F | 262.7, 215.2, 221.1 |
| 5 | 26 (17) | 5 / 6.88 | (-0.9658, 0.0310, -0.2573) | 0.6564 | 25:8/8.84/0.0330/F 27:17/-5.81/0.0354/F 28:15/-0.83/0.0281/F 29:11/10.26/0.0284/F | 262.5, 76.3, 227.3 |
| 5 | 27 (4) | 5 / 0.17 | (-0.9658, 0.0008, -0.2591) | 0.4461 | 25:9/-5.78/0.0361/F 26:17/3.50/0.0291/F 28:15/-10.11/0.0411/F 29:13/7.96/0.0376/F | 262.6, 242.6, 105.2 |
| 5 | 28 (10) | 6 / -6.28 | (-1.0000, -0.0000, -0.0004) | 0.4380 | 25:16/8.77/0.0411/F 26:10/4.28/0.0351/F 27:15/8.73/0.0351/F 29:14/10.92/0.0340/F | 262.4, 103.8, 111.5 |
| 5 | 29 (18) | 6 / -7.07 | (-1.0000, -0.0000, -0.0004) | 0.4977 | 25:13/10.95/0.0379/F 26:12/7.11/0.0284/F 27:16/-6.00/0.0340/F 28:14/-4.56/0.0411/F | 262.4, 270.0, 349.4 |
| 6 | 10 (9) | 6 / 5.54 | (-1.0000, 0.0000, -0.0004) | 0.6572 | - | 263.5, 217.1, 74.2 |
| 7 | 35 (6) | 11 / 10.56 | (-0.2595, -0.1770, 0.9494) | 0.7520 | 36:14/5.84/0.0393/F 37:16/-10.06/0.0323/F 38:17/6.84/0.0411/F 39:15/-2.50/0.0281/F | 261.0, 211.5, 155.0 |
| 7 | 36 (16) | 10 / 7.07 | (-0.5006, -0.1065, 0.8591) | 0.5411 | 35:14/3.64/0.0337/F 37:7/9.31/0.0298 38:17/-8.03/0.0330/F 39:13/6.02/0.0309/F | 260.8, 72.6, 161.2 |
| 7 | 37 (11) | 7 / 6.29 | (-0.9660, -0.0283, 0.2568) | 0.6134 | 35:10/5.82/0.0305/F 36:14/0.82/0.0333/F 38:12/-5.04/0.0354/F 39:17/3.47/0.0411/F | 260.9, 238.9, 39.1 |
| 7 | 38 (9) | 6 / 10.59 | (-1.0000, 0.0001, -0.0004) | 0.5374 | 35:13/0.17/0.0309/F 36:9/7.69/0.0361/F 37:17/-7.40/0.0319/F 39:10/-6.06/0.0354/F | 260.7, 100.0, 45.3 |
| 7 | 39 (18) | 6 / -3.91 | (-1.0000, -0.0000, -0.0004) | 0.3202 | 35:9/-9.57/0.0386/F 36:11/0.24/0.0351/F 37:12/2.37/0.0361/F 38:15/-9.42/0.0407/F | 260.8, 266.3, 283.3 |
| 8 | 40 (16) | 5 / -2.48 | (-0.9658, -0.0112, -0.2589) | 0.5234 | 41:11/-1.62/0.0393/F 42:16/-3.57/0.0319/F 43:15/-11.09/0.0365/F 44:9/-1.30/0.0404/F | 261.6, 268.2, 136.3 |
| 8 | 41 (2) | 16 / -10.90 | (0.8655, 0.0947, 0.4919) | 0.4742 F | 40:9/-1.82/0.0379 42:13/-1.74/0.0386 43:8/-4.76/0.0330 44:12/-5.09/0.0400 | 261.7, 74.5, 14.2 |
| 8 | 42 (13) | 6 / -2.88 | (-1.0000, -0.0000, -0.0004) | 0.4012 | 40:17/-5.25/0.0340/F 41:9/8.25/0.0302/F 43:11/4.46/0.0351/F 44:13/-6.82/0.0354/F | 261.5, 295.6, 20.5 |
| 8 | 43 (19) | 12 / -1.46 | (-0.0008, 0.0255, 0.9997) | 0.4544 F | 40:9/2.20/0.0383 41:15/-0.48/0.0376/F 42:16/5.27/0.0358/F 44:8/-8.81/0.0319 | 261.5, 101.9, 258.4 |
| 8 | 44 (10) | 13 / 9.43 | (0.2580, -0.1582, 0.9531) | 0.3990 F | 40:9/-4.44/0.0333 41:16/-1.26/0.0411/F 42:8/-0.83/0.0383 43:10/-1.72/0.0326 | 261.3, 323.0, 264.6 |
| 9 | 45 (3) | 11 / -2.86 | (-0.2595, 0.0481, 0.9645) | 0.5040 | 46:14/2.16/0.0337/F 47:16/-10.08/0.0379/F 48:17/7.22/0.0326/F 49:8/-2.87/0.0323 | 261.4, 129.3, 142.5 |
| 9 | 46 (12) | 8 / 10.06 | (-0.8663, -0.0873, 0.4919) | 0.7331 | 45:13/8.48/0.0323/F 47:15/-7.58/0.0361/F 48:12/7.79/0.0368/F 49:11/-5.54/0.0411/F | 261.2, 350.4, 148.7 |
| 9 | 47 (17) | 10 / 9.45 | (-0.5006, -0.1422, 0.8539) | 0.5390 | 45:15/4.78/0.0319/F 46:17/-2.09/0.0379/F 48:13/-7.14/0.0344/F 49:16/2.01/0.0288/F | 261.3, 156.7, 26.7 |
| 9 | 48 (0) | 18 / -10.63 | (1.0000, 0.0002, 0.0011) | 0.3629 F | 45:9/-8.48/0.0288 46:15/-0.40/0.0312 47:12/-6.53/0.0372 49:7/0.48/0.0404 | 260.1, 237.1, 186.0 |
| 9 | 49 (14) | 6 / 11.08 | (-1.0000, 0.0001, -0.0004) | 0.5998 | 45:13/-6.70/0.0414/F 46:9/3.42/0.0295/F 47:17/-7.27/0.0411/F 48:16/0.68/0.0319/F | 260.1, 43.4, 64.0 |
| 10 | 50 (1) | 18 / 10.47 | (1.0000, -0.0002, 0.0011) | 0.3819 F | 51:10/-11.14/0.0284 52:12/-7.33/0.0333 53:8/-1.54/0.0365 54:7/-6.38/0.0330 | 259.9, 264.5, 70.2 |
| 10 | 51 (15) | 15 / 0.89 | (0.7064, -0.0110, 0.7077) | 0.5441 F | 50:10/-2.59/0.0358 52:8/9.39/0.0347 53:9/-10.04/0.0407 54:7/-4.32/0.0323 | 260.0, 70.8, 308.1 |
| 10 | 52 (5) | 14 / -2.59 | (0.4992, 0.0392, 0.8656) | 0.5430 F | 50:17/-6.37/0.0411/F 51:7/4.44/0.0386 53:10/8.31/0.0305 54:8/9.99/0.0386 | 259.8, 291.9, 314.3 |
| 10 | 53 (7) | 15 / 10.50 | (0.7064, -0.1290, 0.6959) | 0.5703 F | 50:8/-8.71/0.0365 51:9/-3.71/0.0414 52:11/-3.07/0.0351 54:7/6.56/0.0298 | 259.9, 98.2, 192.3 |
| 10 | 54 (8) | 12 / 0.92 | (-0.0008, -0.0160, 0.9999) | 0.4889 F | 50:9/5.34/0.0372 51:16/-9.49/0.0288/F 52:7/-3.64/0.0333 53:17/-5.80/0.0344/F | 259.7, 319.3, 198.5 |
| 11 | 55 (4) | 13 / -5.54 | (0.2580, 0.0932, 0.9616) | 0.4239 F | 56:9/1.99/0.0372 57:16/-6.16/0.0397/F | 259.7, 125.6, 76.4 |
| 11 | 56 (15) | 13 / 10.26 | (0.2580, -0.1720, 0.9507) | 0.6011 F | 55:7/3.27/0.0330 57:17/-7.93/0.0358/F | 260.6, 127.4, 289.5 |
| 11 | 57 (6) | 12 / -2.03 | (-0.0008, 0.0354, 0.9994) | 0.5352 F | 55:7/-11.02/0.0393 56:8/3.15/0.0333 | 260.6, 293.7, 167.4 |
| 12 | 60 (6) | 10 / 6.80 | (-0.5006, -0.1025, 0.8596) | 0.6157 | 61:7/0.94/0.0397 | 260.3, 182.3, 57.8 |
| 12 | 61 (18) | 6 / 6.02 | (-1.0000, 0.0000, -0.0004) | 0.5092 | 60:12/7.61/0.0358/F | 260.4, 348.6, 295.7 |
| 13 | 65 (2) | 16 / -11.17 | (0.8655, 0.0970, 0.4914) | 0.3824 F | 66:12/6.57/0.0312 67:7/-5.51/0.0400 68:11/7.65/0.0302 69:10/5.67/0.0361 | 267.3, 308.6, 71.9 |
| 13 | 66 (8) | 14 / -3.16 | (0.4992, 0.0477, 0.8652) | 0.5027 F | 65:8/-3.46/0.0393 67:10/11.04/0.0411 68:7/-7.95/0.0288 69:11/-1.29/0.0302 | 267.1, 169.7, 78.1 |
| 13 | 67 (10) | 15 / 1.14 | (0.7064, -0.0141, 0.7076) | 0.4704 F | 65:7/-10.90/0.0365 66:9/3.92/0.0340 68:11/1.37/0.0316 69:10/-7.24/0.0400 | 267.2, 336.0, 316.1 |
| 13 | 68 (17) | 13 / 9.15 | (0.2580, -0.1537, 0.9538) | 0.7241 F | 65:16/0.64/0.0365/F 66:9/-3.53/0.0305 67:10/3.93/0.0316 69:8/-7.21/0.0326 | 267.0, 197.1, 322.3 |
| 13 | 69 (19) | 7 / -2.14 | (-0.9660, 0.0096, 0.2582) | 0.4038 | 65:17/0.16/0.0368/F 66:12/1.60/0.0298/F 67:10/5.94/0.0418/F 68:13/-2.79/0.0407/F | 267.1, 3.4, 200.2 |
| 14 | 70 (13) | 6 / 2.16 | (-1.0000, 0.0000, -0.0004) | 0.5654 | 71:12/-9.18/0.0302/F 72:13/-5.51/0.0365/F 73:17/9.92/0.0323/F 74:14/1.99/0.0386/F | 266.9, 224.5, 206.4 |
| 14 | 71 (7) | 6 / 10.17 | (-1.0000, 0.0001, -0.0004) | 0.4962 | 70:16/7.97/0.0316/F 72:13/9.53/0.0330/F 73:11/-3.37/0.0344/F 74:12/-6.69/0.0284/F | 267.0, 30.8, 84.3 |
| 14 | 72 (5) | 18 / -10.90 | (1.0000, 0.0002, 0.0011) | 0.4997 F | 70:8/-7.09/0.0354 71:13/1.40/0.0379 73:15/3.42/0.0333 74:7/6.51/0.0312 | 267.8, 32.7, 297.4 |
| 14 | 73 (9) | 6 / -8.82 | (-1.0000, -0.0001, -0.0004) | 0.5146 | 70:9/-4.82/0.0407/F 71:10/-8.49/0.0354/F 72:11/5.30/0.0312/F 74:14/-10.28/0.0411/F | 267.9, 199.0, 175.3 |
| 14 | 74 (16) | 18 / 10.20 | (1.0000, -0.0002, 0.0011) | 0.5185 F | 70:12/-1.52/0.0407 71:8/-0.58/0.0298 72:15/9.27/0.0414 73:7/1.82/0.0333 | 267.7, 60.1, 181.6 |
| 15 | 75 (4) | 15 / 0.62 | (0.7064, -0.0077, 0.7077) | 0.6092 F | 76:10/-2.44/0.0298 77:7/-5.64/0.0333 78:8/5.95/0.0358 79:9/-6.37/0.0351 | 267.7, 226.4, 59.5 |
| 15 | 76 (10) | 12 / 1.00 | (-0.0008, -0.0174, 0.9998) | 0.4933 F | 75:7/8.03/0.0418 77:16/-10.60/0.0309/F 78:15/-3.56/0.0323/F 79:8/2.36/0.0400 | 267.5, 87.5, 65.7 |
| 15 | 77 (18) | 6 / 11.22 | (-1.0000, 0.0001, -0.0004) | 0.5076 | 75:10/-3.12/0.0326/F 76:17/7.24/0.0383/F 78:15/-9.27/0.0358/F 79:14/-10.79/0.0418/F | 267.6, 253.8, 303.6 |
| 15 | 78 (0) | 8 / 1.64 | (-0.8663, -0.0143, 0.4994) | 0.5569 | 75:11/6.53/0.0361/F 76:14/7.64/0.0330/F 77:15/-9.89/0.0295/F 79:16/-5.34/0.0288/F | 267.4, 114.9, 309.8 |
| 15 | 79 (11) | 10 / 1.03 | (-0.5006, -0.0155, 0.8656) | 0.5815 | 75:13/2.83/0.0383/F 76:16/6.18/0.0411/F 77:17/3.58/0.0379/F 78:14/3.83/0.0281/F | 267.5, 281.2, 187.8 |
| 16 | 80 (6) | 7 / -8.55 | (-0.9660, 0.0384, 0.2555) | 0.6197 | 81:10/7.27/0.0302/F 82:17/-11.23/0.0351/F 83:11/3.60/0.0319/F 84:15/-6.60/0.0323/F | 266.2, 1.6, 347.1 |
| 16 | 81 (19) | 6 / 1.66 | (-1.0000, 0.0000, -0.0004) | 0.5274 | 80:12/-10.04/0.0365/F 82:9/6.60/0.0298/F 83:11/-7.14/0.0291/F 84:15/6.90/0.0368/F | 266.3, 167.9, 225.1 |
| 16 | 82 (12) | 10 / -1.92 | (-0.5006, 0.0290, 0.8652) | 0.6164 | 80:16/4.60/0.0383/F 81:17/1.10/0.0404/F 83:7/-9.81/0.0288 84:15/-6.60/0.0319/F | 266.1, 29.0, 231.3 |
| 16 | 83 (15) | 7 / 11.00 | (-0.9660, -0.0493, 0.2536) | 0.3363 | 80:12/-4.63/0.0404/F 81:10/-6.21/0.0309/F 82:13/1.47/0.0365/F 84:11/10.91/0.0333/F | 266.2, 195.3, 109.2 |
| 16 | 84 (2) | 6 / 7.52 | (-1.0000, 0.0001, -0.0004) | 0.5106 | 80:16/8.61/0.0386/F 81:17/3.72/0.0330/F 82:12/7.87/0.0365/F 83:14/11.01/0.0372/F | 266.0, 56.4, 115.4 |
| 17 | 85 (13) | 6 / 9.61 | (-1.0000, 0.0001, -0.0004) | 0.5137 | 86:9/6.16/0.0291/F 87:13/-7.99/0.0404/F 88:10/4.97/0.0288/F 89:14/-2.74/0.0319/F | 266.1, 222.7, 353.4 |
| 17 | 86 (9) | 6 / 11.03 | (-1.0000, 0.0001, -0.0004) | 0.6190 | 85:10/-4.17/0.0337/F 87:16/-2.39/0.0284/F 88:14/10.99/0.0288/F 89:13/-7.03/0.0347/F | 265.9, 83.8, 359.6 |
| 17 | 87 (8) | 16 / -3.46 | (0.8655, 0.0302, 0.5000) | 0.3732 F | 85:10/-7.60/0.0298 86:12/-6.95/0.0347 88:11/-5.82/0.0298 89:13/-9.26/0.0383 | 265.9, 250.1, 237.5 |
| 17 | 88 (7) | 18 / 0.84 | (1.0000, -0.0000, 0.0012) | 0.4861 F | 85:7/-0.07/0.0281 86:12/2.48/0.0291 87:8/-1.85/0.0312 89:10/1.89/0.0288 | 266.8, 251.9, 90.6 |
| 17 | 89 (16) | 12 / -10.45 | (-0.0008, 0.1813, 0.9834) | 0.6152 F | 85:8/2.13/0.0386 86:15/7.61/0.0400/F 87:9/-7.82/0.0302 88:17/-6.05/0.0393/F | 266.8, 58.2, 328.5 |
| 18 | 90 (1) | 9 / -2.44 | (-0.7075, 0.0301, 0.7061) | 0.3465 | 91:15/-7.62/0.0291/F 92:17/0.16/0.0365/F 93:13/-3.18/0.0309/F 94:16/3.07/0.0397/F | 266.6, 279.3, 334.7 |
| 18 | 91 (4) | 11 / 1.86 | (-0.2595, -0.0314, 0.9652) | 0.5779 | 90:8/7.26/0.0372 92:16/-6.95/0.0319/F 93:7/3.72/0.0418 94:14/2.87/0.0305/F | 266.7, 85.6, 212.6 |
| 18 | 92 (14) | 6 / 9.87 | (-1.0000, 0.0001, -0.0004) | 0.6065 | 90:17/3.82/0.0361/F 91:9/0.47/0.0316/F 93:14/10.01/0.0372/F 94:12/4.64/0.0323/F | 266.5, 306.7, 218.8 |
| 18 | 93 (17) | 7 / -2.41 | (-0.9660, 0.0108, 0.2582) | 0.6808 | 90:10/5.66/0.0393/F 91:16/10.49/0.0344/F 92:17/5.82/0.0404/F 94:15/-8.06/0.0418/F | 266.6, 113.0, 96.8 |
| 18 | 94 (5) | 9 / 1.89 | (-0.7075, -0.0233, 0.7063) | 0.3962 | 90:13/-8.43/0.0312/F 91:14/8.76/0.0379/F 92:15/6.00/0.0326/F 93:17/2.48/0.0323/F | 266.4, 334.2, 103.0 |
| 19 | 95 (3) | 6 / 9.90 | (-1.0000, 0.0001, -0.0004) | 0.3669 | 96:17/9.87/0.0316/F 97:13/4.46/0.0400/F 98:11/7.97/0.0368/F 99:14/-1.07/0.0302/F | 266.4, 140.5, 340.9 |
| 19 | 96 (8) | 17 / -7.31 | (0.9656, 0.0331, 0.2578) | 0.5549 F | 95:12/10.67/0.0340 97:7/10.39/0.0358 98:13/-3.71/0.0288 99:14/-8.56/0.0347 | 265.2, 220.8, 140.3 |
| 19 | 97 (14) | 6 / -8.10 | (-1.0000, -0.0001, -0.0004) | 0.5503 | 95:12/-1.64/0.0404/F 96:16/-1.18/0.0347/F 98:13/-10.94/0.0319/F 99:14/-10.87/0.0386/F | 265.3, 27.1, 18.2 |
| 19 | 98 (12) | 13 / 10.92 | (0.2580, -0.1830, 0.9486) | 0.5564 F | 95:7/-5.42/0.0316 96:9/-2.80/0.0347 97:16/-5.00/0.0407/F 99:10/6.00/0.0333 | 265.1, 248.2, 24.4 |
| 19 | 99 (6) | 15 / -7.28 | (0.7064, 0.0897, 0.7021) | 0.5871 F | 95:7/2.25/0.0354 96:11/-9.28/0.0344 97:9/3.10/0.0281 98:12/-4.13/0.0298 | 265.1, 54.5, 262.4 |
| 20 | 62 (14) | 6 / -11.20 | (-1.0000, -0.0001, -0.0004) | 0.3929 | 59:15/-0.53/0.0302/F 58:9/-9.13/0.0319/F 63:10/5.57/0.0302/F 64:13/9.44/0.0298/F | 260.2, 209.7, 301.9 |
| 20 | 59 (11) | 11 / 10.28 | (-0.2595, -0.1724, 0.9502) | 0.6654 | 62:8/9.21/0.0333 58:15/-8.61/0.0295/F 63:7/4.71/0.0393 64:16/5.92/0.0281/F | 260.5, 321.1, 51.5 |
| 20 | 58 (1) | 10 / 5.99 | (-0.5006, -0.0903, 0.8610) | 0.4079 | 62:17/1.73/0.0302/F 59:15/-9.14/0.0358/F 63:7/6.28/0.0358 64:14/-8.26/0.0284/F | 260.4, 154.9, 173.6 |
| 20 | 63 (3) | 16 / -3.19 | (0.8655, 0.0278, 0.5001) | 0.3346 F | 62:8/-9.40/0.0390 59:9/-10.64/0.0305 58:10/9.40/0.0333 64:12/-3.94/0.0330 | 260.2, 16.0, 179.8 |
| 20 | 64 (12) | 17 / 1.11 | (0.9656, -0.0050, 0.2598) | 0.6555 F | 62:11/-2.48/0.0351 59:8/4.75/0.0400 58:12/-0.69/0.0397 63:10/-4.14/0.0379 | 267.3, 142.3, 194.0 |
| 21 | 11 (16) | 14 / 6.96 | (0.4992, -0.1050, 0.8601) | 0.6665 F | 12:8/-8.20/0.0358 13:10/-0.12/0.0383 14:11/-4.51/0.0284 34:17/8.72/0.0295/F | 263.6, 23.4, 312.1 |
| 21 | 12 (7) | 16 / 6.35 | (0.8655, -0.0554, 0.4978) | 0.3406 F | 11:13/0.46/0.0340 13:12/-7.62/0.0368 14:11/9.65/0.0351 34:9/-3.12/0.0407 | 263.4, 244.5, 318.3 |
| 21 | 13 (12) | 14 / 5.57 | (0.4992, -0.0841, 0.8624) | 0.5916 F | 11:9/2.64/0.0309 12:8/-5.50/0.0376 14:10/1.19/0.0414 34:7/-10.59/0.0386 | 263.5, 50.8, 196.2 |
| 21 | 14 (2) | 5 / 7.98 | (-0.9658, 0.0360, -0.2566) | 0.3222 | 11:11/-11.02/0.0295/F 12:15/-11.04/0.0365/F 13:17/-8.53/0.0316/F 34:16/1.71/0.0326/F | 263.3, 271.9, 202.4 |
| 21 | 34 (1) | 16 / 5.27 | (0.8655, -0.0460, 0.4988) | 0.5530 F | 11:10/-1.51/0.0354 12:12/2.41/0.0365 13:7/8.48/0.0407 14:8/-6.55/0.0368 | 261.0, 45.2, 277.0 |
| 22 | 100 (0) | 13 / 0.73 | (0.2580, -0.0123, 0.9661) | 0.5499 F | - | 265.0, 275.6, 268.6 |
| 23 | 101 (1) | 11 / 10.95 | (-0.2595, -0.1834, 0.9482) | 0.5085 | 102:17/3.17/0.0407/F | 265.0, 81.9, 146.5 |
| 23 | 102 (2) | 11 / 4.24 | (-0.2595, -0.0714, 0.9631) | 0.5830 | 101:8/8.40/0.0354 | 264.8, 303.0, 152.7 |
| 24 | 103 (3) | 18 / 1.75 | (1.0000, -0.0000, 0.0011) | 0.4525 F | 104:10/-5.77/0.0368 | 264.9, 109.3, 30.6 |
| 24 | 104 (4) | 15 / -7.83 | (0.7064, 0.0965, 0.7012) | 0.5236 F | 103:9/-8.69/0.0330 | 265.7, 111.2, 243.7 |
| 25 | 105 (20) | 6 / 5.26 | (-1.0000, 0.0000, -0.0004) | 0.4880 | 106:9/-7.04/0.0365/F 107:10/0.91/0.0319/F | 265.8, 277.5, 121.6 |
| 25 | 106 (21) | 4 / 1.77 | (-0.8659, 0.0155, -0.5000) | 0.4731 | 105:17/-10.55/0.0386/F 107:16/-4.49/0.0305/F | 265.6, 138.6, 127.9 |
| 25 | 107 (22) | 16 / -7.81 | (0.8655, 0.0680, 0.4962) | 0.5371 F | 105:10/-2.76/0.0333 106:9/3.65/0.0312 | 265.7, 304.9, 5.8 |
| 26 | 108 (11) | 17 / -8.42 | (0.9656, 0.0380, 0.2571) | 0.5556 F | - | 265.5, 166.0, 12.0 |
| 27 | 109 (14) | 6 / -9.20 | (-1.0000, -0.0001, -0.0004) | 0.4444 | 110:11/8.04/0.0284/F 111:15/-7.47/0.0407/F 112:10/-5.20/0.0365/F 113:14/9.28/0.0354/F | 265.5, 332.3, 249.9 |
| 27 | 110 (8) | 14 / -10.75 | (0.4992, 0.1616, 0.8513) | 0.4715 F | 109:8/-5.66/0.0312 111:7/5.20/0.0305 112:11/-2.39/0.0312 113:17/-3.65/0.0351/F | 265.3, 193.4, 256.1 |
| 27 | 111 (12) | 16 / 11.14 | (0.8655, -0.0968, 0.4914) | 0.7413 F | 109:8/-4.65/0.0386 110:7/5.95/0.0379 112:9/4.91/0.0386 113:13/-4.23/0.0390 | 265.4, 359.7, 134.1 |
| 27 | 112 (24) | 13 / 1.56 | (0.2580, -0.0263, 0.9658) | 0.4021 F | 109:8/3.11/0.0418 110:10/-8.40/0.0383 111:16/-4.27/0.0390/F 113:17/8.03/0.0316/F | 264.2, 80.1, 293.4 |
| 27 | 113 (9) | 6 / -10.72 | (-1.0000, -0.0001, -0.0004) | 0.5396 | 109:14/4.95/0.0337/F 110:10/5.34/0.0291/F 111:16/8.95/0.0340/F 112:17/-1.07/0.0330/F | 264.2, 246.4, 171.4 |
| 28 | 114 (25) | 13 / 0.16 | (0.2580, -0.0028, 0.9661) | 0.4757 F | 115:9/4.58/0.0319 116:16/-7.82/0.0309/F 117:8/9.42/0.0418 118:7/-1.74/0.0305 | 0.0, 0.0, 0.0 |
| 28 | 115 (10) | 11 / 1.59 | (-0.2595, -0.0268, 0.9654) | 0.5817 | 114:7/-10.67/0.0333 116:14/-0.51/0.0288/F 117:8/-2.08/0.0326 118:16/-6.82/0.0400/F | 0.0, 0.0, 0.0 |
| 28 | 116 (18) | 6 / 9.60 | (-1.0000, 0.0001, -0.0004) | 0.3529 | 114:17/2.08/0.0383/F 115:11/5.82/0.0316/F 117:15/9.37/0.0379/F 118:13/-4.49/0.0386/F | 0.0, 0.0, 0.0 |
| 28 | 117 (12) | 18 / 1.19 | (1.0000, -0.0000, 0.0012) | 0.6735 F | 114:7/8.93/0.0361 115:9/-6.94/0.0337 116:12/7.43/0.0397 118:13/-3.54/0.0284 | 0.0, 0.0, 0.0 |
| 28 | 118 (11) | 18 / 2.61 | (1.0000, -0.0001, 0.0011) | 0.5489 F | 114:10/-6.12/0.0372 115:9/0.49/0.0404 116:8/2.28/0.0418 117:12/-10.09/0.0347 | 0.0, 0.0, 0.0 |
| 29 | 119 (5) | 16 / 10.62 | (0.8655, -0.0923, 0.4923) | 0.3642 F | 120:11/3.81/0.0319/R 121:8/1.56/0.0386 122:10/-10.67/0.0305 123:7/-8.76/0.0288 | 263.9, 328.6, 183.8 |
| 29 | 120 (26) | 17 / -7.59 | (0.9656, 0.0343, 0.2576) | 0.3967 F | 119:7/-2.02/0.0344 121:14/-10.73/0.0298 122:9/-7.03/0.0316 123:8/11.05/0.0302 | 264.7, 330.4, 36.9 |
| 29 | 121 (9) | 6 / -8.37 | (-1.0000, -0.0001, -0.0004) | 0.6633 | 119:12/0.16/0.0316/F 120:15/-10.18/0.0309/F/R 122:11/4.87/0.0414/F 123:14/9.38/0.0312/F | 264.8, 136.7, 274.8 |
| 29 | 122 (7) | 14 / 10.65 | (0.4992, -0.1601, 0.8516) | 0.4748 F | 119:9/-3.62/0.0368 120:8/-1.34/0.0288/R 121:11/-10.50/0.0281 123:10/1.55/0.0298 | 264.6, 357.8, 281.0 |
| 29 | 123 (20) | 6 / -6.56 | (-1.0000, -0.0000, -0.0004) | 0.3116 | 119:17/5.30/0.0295/F 120:16/7.92/0.0372/F/R 121:13/9.26/0.0407/F 122:11/6.97/0.0354/F | 264.6, 164.1, 158.9 |
| 30 | 124 (3) | 6 / 1.45 | (-1.0000, 0.0000, -0.0004) | 0.5472 | 125:11/8.94/0.0295/F 126:9/-5.11/0.0291/F/R 127:15/4.83/0.0376/F | 264.4, 25.3, 165.2 |
| 30 | 125 (11) | 5 / -10.83 | (-0.9658, -0.0487, -0.2545) | 0.7589 | 124:10/3.70/0.0319/F 126:13/-7.04/0.0288/F/R 127:8/-11.06/0.0354/F | 264.5, 191.5, 43.1 |
| 30 | 126 (22) | 16 / 4.96 | (0.8655, -0.0433, 0.4990) | 0.3967 F | 124:11/-10.91/0.0351 125:12/-2.76/0.0418 127:8/6.20/0.0386 | 264.3, 52.7, 49.3 |
| 30 | 127 (24) | 18 / 1.48 | (1.0000, -0.0000, 0.0011) | 0.4706 F | 124:15/0.52/0.0305 125:10/-5.94/0.0368 126:14/-10.85/0.0340/R | 264.4, 219.0, 287.2 |
| 31 | 128 (18) | 6 / 5.77 | (-1.0000, 0.0000, -0.0004) | 0.6007 | 129:12/-8.82/0.0383/F 130:9/9.45/0.0326/F/R 131:17/-5.73/0.0418/F | 0.0, 0.0, 0.0 |
| 31 | 129 (14) | 6 / 4.99 | (-1.0000, 0.0000, -0.0004) | 0.5499 | 128:12/-4.98/0.0354/F 130:14/-6.42/0.0284/F/R 131:13/0.90/0.0365/F | 0.0, 0.0, 0.0 |
| 31 | 130 (3) | 11 / 2.49 | (-0.2595, -0.0420, 0.9648) | 0.3967 | 128:7/-7.37/0.0383 129:14/10.32/0.0309/F 131:8/-11.09/0.0316 | 0.0, 0.0, 0.0 |
| 31 | 131 (12) | 11 / -4.21 | (-0.2595, 0.0710, 0.9631) | 0.6742 | 128:7/0.51/0.0414 129:8/7.59/0.0379 130:17/-9.70/0.0404/F/R | 0.0, 0.0, 0.0 |
| 32 | 132 (24) | 10 / -7.70 | (-0.5006, 0.1159, 0.8579) | 0.3967 | - | 271.1, 40.1, 69.7 |
| 33 | 133 (6) | 8 / -8.48 | (-0.8663, 0.0737, 0.4941) | 0.7087 | 134:11/4.15/0.0386/F | 271.2, 206.4, 307.6 |
| 33 | 134 (5) | 9 / -4.19 | (-0.7075, 0.0516, 0.7048) | 0.4555 | 133:13/-7.36/0.0418/F | 271.0, 67.5, 313.8 |
