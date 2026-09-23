# Star-system level props: asteroids, gas clouds, junk, dust, traffic

How the original fills an in-space level (`Level(3)`, created by `MGame::OnInitialize`) with asteroids and ambient props.
Mesh assembly (LOD sets, fx meshes) is in `Reference/tools/asset_conversion/assemblies/rules/assemblies_level_notes.md`; this file covers **placement and behaviour**.

All positions and distances are in **game units**. Unity = `(x, y, -z) * 0.05`. Angles are radians, time is ms.
The station (`PlayerStation`) sits at the origin. The gas-cloud code keeps clouds 25000 units away from the origin, which confirms this.
Floats the decompiler lost were recovered from the Thumb disassembly (capstone; `armdis.py` no longer exists, a replacement is trivial: literal pool = `((pc+4)&~3)+imm`).

## Level build order (`Level::init` 0xbb49c)

1. `createSpace` 0xbbba0: skybox, station, jumpgates, wormhole, `StarSystem`.
2. `createPlayer` (only for level type 3).
3. **`createAsteroids` + `createGasClouds`**, unless the level type (`Level+0xc0`) is 4 or 0x17 (cut-scene types). Every flight level is `Level(3)`, so **every orbit gets an asteroid field**: normal stations, empty orbits, alien orbits, mission levels.
4. `createMission` (empty/freelance mission: ambient traffic) or `createCampaignMission`.
5. `createStaticObjects` 0xcadb0.
6. `createSentryGuns` 0xcb0d8, `createFighterTurrets` 0xcb200, `createWingmen` 0xcb338 (skipped for types 4/0x17 and for scene type 2 during campaign mission 0x2b).
7. `assignGuns`, `connectPlayers`. Particle systems (dust/fog) are set up in `initParticleSystems` 0xcc990.

## 6. Random number generator (read first)

`AbyssEngine::AERandom` (0x7acde..0x7ae6a) **is `java.util.Random`**: 48-bit LCG, multiplier 0x5DEECE66D, increment 0xB.
- `setSeed(s)`: state = `(s ^ 0x5DEECE66D) & (2^48-1)`.
- `nextInt(n)`: the Java algorithm. Power of two: `(n * next(31)) >> 31`. Otherwise loop `bits = next(31); val = bits % n` while `bits - val + (n-1)` overflows.
- `reset()` and the default ctor seed from `time(NULL)`.

The one global `Globals::rnd` is used everywhere. Layout code seeds it with the **station index** (`setSeed((int64)Station::getIndex())`), draws the values that must be stable, then calls `reset()` (time seed). Everything after that is different on every visit.

| Where | Seed | Stable values | Then |
|---|---|---|---|
| `createSpace` | station index | skybox rotation (3 x `nextInt(65536)/65536*2π`), jumpgate placement | `reset()` |
| `createAsteroids` | station index | asteroid **count** and field **centre** | `reset()`: positions, types, scales, rotations are random per visit |
| `createGasClouds`, `createMission`, junk, traffic | none (time) | nothing | |

A C# port of `java.util.Random` reproduces the original stable values exactly. Sample values (verified against Java's `new Random(0).nextInt(100) == 60`):

| Station | Count | Centre (game) |
|---|---|---|
| 0 | 40 | (-44052, -1971, 36447) |
| 1 | 65 | (14588, -8153, 90313) |
| 2 | 68 | (-28628, -5960, 45067) |
| 10 | 73 | (42380, -22707, 43290) |
| 100 | 75 | (26250, -42126, 95988) |

## 1. Asteroid fields

### `Level::createAsteroids` 0xbcfd0

**Setup (seeded with the station index):**
```
setSeed(stationIndex)
count = nextInt(40) + 40                      // 40..79, array Level+0xfc
cx = nextInt(100000) - 50000                  // -50000..49999
cy = nextInt(100000) - 50000
cz = nextInt(100000) + 20000                  //  20000..119999 (in front of the station, +Z game = -Z Unity)
reset()                                       // time seed from here on
```
Centre overrides (checked in this order; count stays random):

| Condition | Centre |
|---|---|
| alien orbit (`Status::inAlienOrbit`) | (-30000, 0, 30000); (-70000, 0, 30000) during campaign mission 0x9a |
| campaign mission 0x72 at station 0x53 | (30000, 0, 80000) |
| campaign mission 0x59 in the supernova orbit (station 0x6d) | (-100000, 0, -50000) |
| campaign mission 0x5b at station 0x6e | (60000, 0, 50000) |
| campaign mission 0x91 at station 0x70 | (50000, 0, 70000) |
| current campaign mission == 0 (and level type 3) | (0, 0, 0), around the station |

The centre is stored at `Level+0xc8`. `Level+0xd8` gets a `Waypoint` at the centre (`getAsteroidWaypoint`, used by the HUD/autopilot target in `MGame::OnTouchEnd`). `Level+0xc4` gets a `BoundingSphere` at the centre with **radius 100000**. `Level::isInAsteroidCenterRange` / `Level::collide` test against it; `Radar::draw` uses it.

**Per asteroid** (after `reset()`):
```
nBig = nextInt(8) + 2                                   // first 2..9 asteroids are "big"
for i in 0..count-1:
    ore   = pick ore item (see "Ore choice")            // alien orbit: always 0xa4 (Void Crystals)
    type  = 0; if system == 22 (Beidan): 2; if alien orbit: 1; if ore == 0xd9 (Novanium): 3
    mesh  = {16900, 16921, 16904, 18836}[type]          // table UNK_00251fb0
    side  = i < nBig ? 60000 : 100000
    repeat:
        pos = centre - side/2 + (nextInt(side), nextInt(side), nextInt(side))   // axis-aligned CUBE
    until spacingOk(i, pos)
    scale = i < nBig ? (nextInt(100) + 120) * 0.01      // 1.20..2.19
                     : (nextInt(70)  +  30) * 0.01      // 0.30..0.99
    quality: scale < 0.4 -> 4 (D), < 0.7 -> 5 (C), < 0.92 -> 6 (B),
             else nextInt(2) == 0 ? 7 (A) : 4 + nextInt(3)   // big asteroids always take this branch
    new PlayerAsteroid(mesh, geom, type, ore, pos, scale, quality)
    setAsteroidCenter(centre)
```
`spacingOk` (disassembly 0xbd47a..0xbd4d6) only applies to big asteroids `1 <= i < nBig`. It walks the earlier asteroids j = 0.. and accepts the position as soon as **one** of them is more than 8000 units away; it retries only when all earlier ones are within 8000. It was probably meant to require all of them to be more than 8000 away. The small asteroids have no spacing check.

The shape is a cube, not a sphere: the big ones spread over ±30000 around the centre, the rest over ±50000.

**Meshes and assemblies.json names**

| type | When | Mesh (LODs = id+1..+3) | assemblies.json | Explosion (type+2) |
|---|---|---|---|---|
| 0 | default | 16900 `asteroid_01` | `asteroid_01` | `asteroid_01_explosion_anim` |
| 1 | alien orbit | 16921 `asteroid_void` | `asteroid_void` | `asteroid_void_explosion_anim` |
| 2 | system 22 (Beidan, texture index 12, ice) | 16904 `v_asteroid_ice` | `v_asteroid_ice` | `v_asteroid_ice_explosion_anim` |
| 3 | ore 0xd9 (supernova orbit after mission 0x59) | 18836 `sn_asteroid_magma` | `sn_asteroid_magma` | `sn_asteroid_magma_explosion_anim` |

Mesh bounding radius (sidecar `bsphere`): asteroid_01 / magma 3547, void 6064, ice 2835 units (before scale).

**LOD distances** (`setLodMeshes`, 3 LODs, ids +1/+2/+3; no last-visible distance):
- phone, big asteroid: 60000 / 100000 / 120000
- phone, small asteroid: 40000 / 70000 / 90000
- iPad: 100000 / 120000 / 150000

### Ore choice (`Galaxy::getAsteroidProbabilities` 0x1a4fb0)

For each ore item 154..163 (Gold, Titanium, Iron, Orichalzine, Pyresium, Sodil, Doxtrite, Cesogen, Perrius, Hypanium):
`p = 100 - trunc(dist)`, where `dist` is the galaxy-map distance (`SolarSystem::getX/getY` = `systems.json mapPosition.x/.y`) between the current system and the ore's `lowestPriceSystem`. If `p < 50` then `p = 0`. Item 164 (Void Crystals) is appended with p = 0 (100 in alien orbit).
The 11 pairs are bubble-sorted by p (descending, stable), then `p[k] -= 2k` for positive entries. In the supernova orbit after campaign mission 0x59, every item id is replaced by 0xd9 (Novanium Ore).

Picking (0xbd34a..0xbd3a8): an index `k` (starting at 0, kept between asteroids) walks the pairs:
```
loop: if nextInt(100) < p[k]:
          item = ore[k]; k += 1 (wraps to 0 after pair 5)
          if item < 0xa4 or item == 0xd9: accept
      else: k = 0
```
Only the top 6 pairs can ever be chosen. The top ore dominates, the next ones appear when earlier rolls succeed. Top ores per system (p after the -2k adjustment):

```
 0 Suteo: Iron 100, Cesogen 75, Gold 65          17 Nesla: Pyresium 88, Gold 83, Cesogen 66
 1 Pan: Sodil 79, Iron 72, Cesogen 55            18 Pescal Inartu: Sodil 100, Hypanium 71, Iron 60
 2 Behon: Iron 85, Gold 80, Cesogen 76           19 Augmenta: Cesogen 100, Perrius 85, Gold 79
 3 V'ikka: Hypanium 87, Cesogen 81, Perrius 77   20 K'ontrr: Titanium 87, Hypanium 81, Doxtrite 64
 4 Eanya: Pyresium 100, Gold 71, Iron 56         21 Ni'mrrod: Titanium 100, Hypanium 68, Doxtrite 58
 5 S'kolptorr: Hypanium 100, Doxtrite 74         22 Beidan: Doxtrite 85, Perrius 63, Orichalzine 60
 6 Wolf-Reiser: Orichalzine 90, Doxtrite 71      23 Herjaza: Hypanium 85, Sodil 82, Titanium 66
 7 Aquila: Orichalzine 100, Perrius 70           24 Skavac: Titanium 78, Sodil 72, Hypanium 70
 8 Buntta: Iron 83, Cesogen 80, Sodil 74         25 Loma: Gold 78, Orichalzine 74, Pyresium 67
 9 Weymire: Gold 100, Cesogen 81, Perrius 74     26 Shima: Gold 87, Pyresium 77, Orichalzine 66
10 Y'mirr: Doxtrite 84, Hypanium 81, Titan. 74   27 Ginoya: Pyresium 93, Gold 69, Cesogen 50
11 Union: Perrius 85, Gold 82, Orichalzine 80    28 Talidor: Pyresium 88, Gold 72, Orichalzine 54
12 Oom'bak: Hypanium 88, Doxtrite 85, Perr. 80   29 Paraah: Pyresium 84, Gold 77, Iron 72
13 Vulpes: Doxtrite 100, Perrius 77              30 Me'enkk: Titanium 87, Hypanium 64, Sodil 56
14 Magnetar: Perrius 100, Cesogen 85             31 Wah'norr: Doxtrite 80, Titanium 73
15 Mido: Pyresium 86, Gold 77                    32 Skor Terpa: Orichalzine 80, Gold 69
16 Prospero: Doxtrite 85, Orichalzine 78         33 Alda: Sodil 90, Hypanium 74, Titanium 60
```

### `PlayerAsteroid::PlayerAsteroid` 0xf68e4

- `Player(1500, 30)`, then radius = `transformRadius(+0xe0) * scale * 0.7`, max HP = `scale * 100 + 30`.
- Uniform scale = `scale` on the geometry and the explosion. Explosion type = asteroid type + 2.
- Minable (`+0x138`) = quality > 3, so always true. Quality letters: 7 A, 6 B, 5 C, 4 D (`getQualityString`; "E" is unreachable).
- **Initial rotation**: `setRotation(a, b, c)` with `a, b, c = nextInt(100) * 0.01 * 2π` each (three independent draws, Euler radians).
- **Spin** (`+0x13c`): `(nextInt(3)-1, nextInt(3)-1, nextInt(3)-1) * (1 - clamp(scale, 0.9, 1.0))`. Each axis is -1, 0 or +1, times 0.1 for scale ≤ 0.9, `1-scale` between 0.9 and 1, and **0 for scale ≥ 1**: big asteroids don't spin.
- A random vector `(nextInt(8192)-4096)/4096` per axis is written to the global `tmp_vector2` and never used. It only consumes RNG draws.

### `PlayerAsteroid::update` 0xf7060

- Every frame, if rotation is enabled (`+0x148`, set in the ctor): `geometry.rotate(spin * dt * 0.001)`. That gives 0.1 rad/s per non-zero axis for small asteroids.
- When hit, `+0x158` = 0.1 and `+0x15c` = 0.001 (a hit flash or wobble; not applied in update).
- **Bomb push**: while `Player::getBombForce() > 0` in state 3, the asteroid moves along the hit vector by `force * 1024 * (1 - max(scale, 0.6)/100)` and the force decays `*0.98` per frame (0 below 0.05). `initPush`/`push` (0xf6db8/0xf6f10): a push of `(1 - d/r) * 5000` ms with a random tumble axis * 0.2.
- **Death** (HP ≤ 0, state 0 -> 3): `Level::asteroidDied`, stat `Status+0xd8`++. Loot: quality 7 drops a crate with 4% chance, others 20%. The crate contains the ore, or for quality A the "core" item (ore + 11, Novanium 0xd9 -> 0xda). Amount: 1 for A, else `nextInt(3)+1`. `createCrate(1)` (type 2 for Void Crystals). Then the explosion plays; state 4 deactivates.
- Mining itself (the mining laser minigame) is elsewhere and not covered here.

## 2. Gas clouds (Supernova plasma)

### `Level::createGasClouds` 0xbd750 (runs right after createAsteroids)

- **Only if the player's ship has a Spectral filter** (`Ship::getFirstEquipmentOfSort(0x21)`, items 196/219/220) and not in an alien orbit.
- Plasma probabilities (`Galaxy::getPlasmaProbabilities` 0x1a518c) use the same distance formula over items 201..204 (Green, Blue, Purple, Red) and sort them. Only the **top** plasma type is used; all clouds in the level share it.
- Skip: if system != 10 and the top plasma is Red (204) and `SolarSystem+0x3c` (`getRoutes`) is null, no clouds.
- **Count** = `trunc((nextInt(4) + 4) * pTop / 100)`, plus 3 during campaign mission 0x8e at station 0x4f. That is 2..7 per system; most systems get 3..5 (pTop 70..100).
- **Position**: uniform in the cube ±80000 around the origin, rejected while `|pos| < 25000` (station) or `|pos - asteroidCentre| < 30000`. Not seeded, so different every visit. Mission 0x8e at station 0x4f: the first cloud is at (92000, 0, 36000).
- KIPlayer geometry = mesh 14289 (`bra.fbx`, a dummy). Array `Level+0xf4`.

### `PlayerGasCloud` 0x1a5330 / update 0x1a5a1c / render 0x1a5f2c

- `Player(0, 9999999)` with max HP 1: one shot "explodes" it into sparks (`explode` 0x1a55f0).
- Visible cloud: one billboard mesh, rebuilt each frame to face the camera (`setDirection(-cameraDir, cameraUp)`), no scaling. Mesh bounding radius is about 3550 units, so the cloud is about 7000 units across.

| Plasma item | Cloud mesh | Spark mesh | assemblies.json |
|---|---|---|---|
| 201 Green (default) | 18997 | 19001 | `sn_gas_cloud_green_anim_lookat_add` |
| 202 Blue | 18998 | 19002 | `sn_gas_cloud_blue_anim_lookat_add` |
| 203 Purple | 18999 | 19003 | `sn_gas_cloud_violet_anim_lookat_add` |
| 204 Red | 19000 | 19004 | `sn_gas_cloud_red_anim_lookat_add` |

- Sparks: they slow down by `0.08*dt` per frame to a minimum speed. With a Plasma collector (sort 0x23, attribute 0x31 = speed) they fly towards the turret position when it is in sight. They are collected within 800 units (after 2000 ms) in turret mode: +1 plasma cargo, sound 0x8d0. Spark alpha: `(d - 800)/2700` up to 3500, fades out over 1500 ms after collection.

## 3. Space junk, wrecks and static objects

**Normal (non-mission) levels have no junk or wrecks.** `createStaticObjects` 0xcadb0 only adds campaign objects:

| Condition | Object | Position |
|---|---|---|
| station 0x70 (112), campaign mission 0x80..0x91, not alien orbit | plasma array stage by mission: <0x83 0x493e, <0x87 0x4941, <0x8a 0x4944, <0x8e 0x4947, ≤0x91 0x494a (`sn_plasma_array_midorian_stage_001..005`) | (-50000, 0, 50000), facing `StarSystem::getLightDirection`, name text 3207, always friend, not moving |
| station 0x67 (103, an empty orbit), campaign mission > 0x54 and != 0x87, not alien orbit | mining plant 0x4a88 = 19080 (`sn_station_mining_plant`) | (0, 0, 0), name text 3210, docking type 1, always friend |

Other level objects that are not scenery:
- `createSentryGuns`: only when the player owns a Sentry Gun (sort 0x27). Creates 9 inactive guns (0x49c0 + i/3) parked at (50000, 50000, 50000) until deployed.
- `createFighterTurrets`: turrets on ships whose `KIPlayer+0x78` is 0x2d or 0x33 (offsets (0, 172.25, -460.7) and (0, 470, -83)).
- `createWingmen`: the player's hired wingmen.

**Space junk** (`createStaticObject(wp, 0x4215, true)` in `createMission`, **mission type 7 only**, probably the "destroy space waste" freelance job):
- Route waypoint at (rand ±20000, rand ±10000, 40000 + nextInt(30000)).
- Count = `trunc(2 * difficulty) + 15` junk pieces, plus `trunc(difficulty / 5)` pirate fighters (race 8). Time limit `Level+0x130` = 121000 ms.
- Each piece: position = waypoint + (nextInt(20000) - 10000) per axis (the `param_3 = true` spread). Mesh `nextInt(3)`: 0 -> 16917 `space_junk_001`, 1 -> 16918 `_002`, 2 -> 16919 `_003`. `Player(1000, 1)`: 1 HP. Always enemy.
- Rotation: `AEGeometry::rotate(x, y, z)` with **its own position coordinates as radians** (disassembly 0xcdb70), effectively random.
- `PlayerJunk::update` 0x18afb4: on death `Level::junkDied`, sound 0x16, a manual explosion particle. 10% chance of a crate (type 3) with item 99 "Space Waste" x `nextInt(10)+1`.
- The single meshes need no assembly. 16920 `space_junk_004` is a loot crate model (`createCrate` type 3).

Wrecks: `PlayerFixedObject::setWreckedMeshId` is only used for mission objects (cargo container 0x4260 -> 18300, supernova stations). None are placed in free flight.

## 4. Ambient space dust and fog (particle systems around the camera)

Particle definitions: `ParticleSettings::init` 0x1b4d80 fills `ParticleSettingsRef::cur/init`, 48 sets of 0x9c bytes. Two are attached to the **camera matrix** in `Level::initParticleSystems` 0xcc990 and use the **area-exit** mode (flag 0x80, `ParticleSystemSprite::updateAreaExitParticle` 0x1b3844).

Relevant set fields (offset in the 0x9c entry): `+0x08` flags, `+0x0c` count, `+0x10` base size, `+0x14` random extra size (`size = base + nextInt(extra)`), `+0x24` lifetime, `+0x30`/`+0x34` colour RGBA as `0xRRGGBBAA`, `+0x3c` inner radius, `+0x54` velocity, `+0x74` R (outer), `+0x78` fade-out start, `+0x7c` fade-in end, `+0x84..+0x90` UV rect.

**Area-exit rule** (both systems): emitted at `camera + uniform cube ±R`. Each frame, with `d` = distance to the camera:
- `d ≥ R`: alpha 0. When `d > 1.01·R`, respawn at `camera + randomUnitDir * R` with velocity `+0x54`. The direction comes from a random quaternion; the draw is retried next frame when `|q|² < 1`.
- `R78 ≤ d < R`: alpha = `(R² - d²) / (R² - R78²)` (fade out).
- `R7c ≤ d < R78`: full colour.
- `inner ≤ d < R7c`: alpha = `(d² - inner²) / (R7c² - inner²)` (fade in near the camera).
- `d < inner`: alpha 0.

The particles do not move (velocity 0, except the supernova wind below), so the ship flies through them. That is the speed/parallax cue. There are no velocity streaks.

| | SET_STARS (index 4) | SET_FOG (index 7) |
|---|---|---|
| Manager / material | `Level+0x88`, material 20092 (`Textures/main/misc/space_particle_diffuse.png` + normal map, shading "lit") | `Level+0x7c`, material 20095 `Textures/main/fx/fog.png` (additive); texture index 12 (Beidan): 20137 `Textures/valkyrie/fx/v_fog_ice.png` |
| Count | 500 | 15 |
| Size | 20 + nextInt(40) = 20..59 units (1..3 m) | 10000 units (500 m) |
| R / fade-out start / fade-in end / inner | 10000 / 5000 / 2000 / 0 | 10000 / 5000 / 1000 / 0 |
| Colour | 0xFFFFFFFF (white) | per-system tint (below) |
| UV rect | (0,1)-(1,0) | 0.01..0.99 |
| Visibility | `Level::enableMovingStars` 0xd6600, called from `PlayerEgo::render` every frame: on while the player is alive, `PlayerEgo+0x24 == 0` and `PlayerEgo+0x1c4 != 1` | always |

**Fog tint** (`initParticleSystems`): `rgb = DAT_00252ca0[system.textureIndex] * 0.6` with alpha 0xbb. In a supernova system: `*0.5` and alpha 0xff. Alien orbit: 0x9274d4 with the default alpha.
Table (textureIndex: R,G,B): 0: 0,160,32 · 1: 140,20,2 · 2: 0,109,123 · 3: 44,155,216 · 4: 122,122,122 · 5: 206,90,70 · 6: 105,160,125 · 7: 167,160,126 · 8: 126,181,159 · 9: 206,222,225 · 10: 146,116,212 · 11: 219,105,35 · 12: 255,255,255 · 13: 154,228,255 · 14: 174,183,125 · 15: 219,105,35 · 16: 71,102,94 · 17: 115,141,149 · 18: 171,160,117.

**Supernova wind**: in a supernova system (except campaign mission 0x59, and only before mission 0x9e), fog velocity `+0x54` = `-normalize(lightDir) * 2000`. The fog drifts away from the sun.

**SET_FOG_STATIC (index 8)**: only in systems with a pirate base, attached to the pirate station (type 0x37a3) reference matrix. 30 sprites of size 32768, spread ±40000 (`+0x44`, `+0x48`), colour 0xE2282880 (red, alpha 128), infinite lifetime, flags 0x1000041 (not area-exit).

**Not used**: the `MovingStars` class (50 billboards, texture 10001). `PlayerEgo::PlayerEgo` constructs it, but its `update`/`render` have no callers. `SET_MESH_STARS` / `SET_MESH_STARS_BOOST` (5/6) are never added to any manager.

## 5. Ambient NPC traffic (overview only)

Everything is in **`Level::createMission` 0xbda70** (the empty-mission branch after `Mission::isEmpty`, time-seeded) and uses `Level::createShip(race, kind, shipIndex, waypoint, ...)` 0xcf83c, where kind 1 = freighter/static, and `Globals::getRandomEnemyFighter(race)`. Counters:

| Field | Meaning | Rule (summary) |
|---|---|---|
| `Level+0x160` | local fighters (system race) near a route at (±10000, ±10000, 20000..50000) | `security + nextInt(2) + freighters/4` (security lowered by 1 in hardcore). The first slot can be the Wanted target + wingmen. Forced ≥ 7 if the station was attacked (`hasAttackedFriends`); 4 if everything would be 0. |
| `Level+0x164` | 0..1 "jumpers" | inactive, arrive later through a jump route (±200000, ±100000, 50000..150000) |
| `Level+0x168` | 0..4 freighters (ship 0xf, 0xd for race 1), moving | at (±(20000..80000), ±20000, ±80000). 30% chance race 2 instead of the system race. |
| `Level+0x16c` | raiders: pirates (race 8, 75%) or the system's enemy race | Only if `nextInt(100) <` 90/65/35/10 for security 0/1/2/3+. Count = `nextInt(4)` (+difficulty option, + playerLevel/4; hardcore 2..7). Route `Level+0x180` at (±50000, 0, 50000..100000). 8% chance of 9 after mission 0x1f. |
| `local_194` | pirate-base guards / freelance escort | 2 (hardcore more) in pirate-base systems |

Special orbits: black market system (6..9 pirates), pirate loot orbit (10..13), stations 100/101/108 and 10 (none), 102..104 (3..7 pirates), station 0x6c (pirate stations + fighters), alien orbit (2+ aliens, race 9, cube ±60000/±40000). Later AI/steps: `KIPlayer`, `PlayerFighter::update`, `Route`, `Waypoint`, `Level::update` 0xd5fcc.

## Uncertainties

- **Station at the origin**: inferred from the gas-cloud 25000 rule and createSpace, not from an explicit `setPosition` in `PlayerStation`.
- **Asteroid spacing** is implemented as decoded ("accept if any earlier big asteroid is > 8000 away"). It is probably a bug; either version looks similar in practice.
- **`campaign mission == 0` centre (0,0,0)**: what "mission 0" means for free play isn't verified (`Status+0x1e8`). It may apply to a new game before the first campaign step.
- **Euler order** of `setRotation`/`rotate` (`MatrixSetRotation`) isn't decoded. The initial rotation is random anyway, but the spin axes depend on it.
- **Bomb push formula**: the constants come from the decompile (`1024`, `0.98`, `0.6`). The float order was not checked in the disassembly.
- **Velocity units** of the particle `+0x54` (the supernova fog wind 2000): multiplied by the frame time argument of `updateAreaExitParticle`; that argument could be ms or s.
- **Gas-cloud skip rule** (red plasma + `SolarSystem+0x3c == null`): the meaning of `+0x3c` (`getRoutes`) is unclear.
- **SET_STARS rendering**: the material is "lit" (diffuse + normal). Whether the sprite system actually lights the particles isn't checked; rendering them as white unlit billboards is probably close.
- `PlayerEgo+0x24` / `+0x1c4` in the dust visibility condition are unidentified; `+0x1c4 == 1` is probably a camera or turret mode.
- Traffic counts are summarised from one read of `createMission`; wanted/escort/hardcore branches need a proper pass when implementing AI.
