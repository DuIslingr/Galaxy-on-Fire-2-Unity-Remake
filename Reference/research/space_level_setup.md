# In-space level setup: flow, player, station, jumpgate, lights, camera

Scope: how the original builds a star-system orbit level (`Level(3)`), where the player, station and jumpgate go, and how travel works.
Related notes (not repeated here):
- Mesh assembly: `tools/asset_conversion/assemblies/rules/assemblies_{level,stations,scenes}_notes.md`.
- Sun/planet billboard layout and sky rotation: `space_backdrop_sim.py` (and its .md).
- Asteroids, gas clouds, junk, dust, NPC traffic: `space_props.md`.

All positions are GAME units. Unity = `(x, y, -z) * 0.05`. Angles are radians unless noted. Game time is ms.

## 0. Conventions verified in the engine

| Fact | Source |
|---|---|
| Matrices are row-major. The translation is in m[3], m[7], m[11]. `MatrixGetDir` = column 2 (local **+Z**), `MatrixGetUp` = column 1. | `AEMath::MatrixGetDir` 0x8ae24, `MatrixGetUp` 0x8ae16 |
| `setDirection(dir, up)` writes `dir` into column 2. So "direction" = local +Z. | `AEGeometry::setDirection` 0xb10c4 |
| Ships fly along local +Z: `moveForward(dt * speed)` with speed > 0. The chase camera sits at local −Z (see §7). | `PlayerEgo::update` 0xa8ed0, `AEGeometry::moveForward` 0xb1440 |
| `MatrixSetRotation(M, x, y, z)` = Rx(x)·Ry(y)·Rz(z) (column vectors). Local +Z of (x, y, 0) = `(sin y, −sin x·cos y, cos x·cos y)`. A yaw θ gives forward `(sin θ, 0, cos θ)`. | `AEMath::MatrixSetRotation` 0x8b09c |
| `AERandom` is `java.util.Random`: 48-bit LCG, multiplier 0x5DEECE66D, addend 0xB; `setSeed(s)` = `(s ^ 0x5DEECE66D) & (2^48−1)`; Java's `nextInt(n)`; `reset()` reseeds from `time()`. | 0x7ad04..0x7ae6a |

Orientation in Unity: convert direction vectors with the same `(x, y, −z)` rule and build the rotation with `LookRotation(fwd, up)`. The prefabs face +Z like the game's local +Z. Because z is mirrored, a game yaw θ becomes a Unity yaw of **π − θ**: game (0, π, 0) becomes Unity yaw 0. Check this against the flight test scene.

## 1. Build flow (MGame, module 2 = "in space")

`MGame::OnInitialize` 0x1a6ebc runs every frame until `Level::init` returns 1 (loading screen):
1. **Reflection cubemap:** `TextureCreate(0x2efe + system.textureIndex)` (alien orbit: 0x2f08), then `ChangeCubeTexture`.
2. **Sound preload list.**
3. **`new Level(3)`.** `Level::Level` 0xbaf80 only zeroes fields; `+0xc0` = level type (3 = flight, 2 = main-menu background, 4 = bar, 0x17 = hangar).
4. **`Level::init` 0xbb49c, two passes:**
   - **Pass 1** (`+0x134 == 0`):
     - Creates the LODManager and 10 ParticleSystemManagers (resource ids 0x4e85, 0x6a72, 0x4e83, 0x4e7a, 0x5e20, 0x4e7f (0x4ea9 when sysTex == 12), 0x4e7c, 0x6a7c, 0x6ab9, 0x6aaf).
     - Calls `createSpace()` (§3).
     - If type 3: `createPlayer()` (§5), then the spawn position (§4).
     - Returns 0.
   - **Pass 2:**
     - Types other than 4/0x17: `createAsteroids`, `createGasClouds`.
     - Then one of:
       - campaign mission active and not won: `createCampaignMission`;
       - otherwise: `createMission` (free flight), plus the black-market offset (§4);
       - type ≠ 3: `createScene`.
     - Then `createStaticObjects`.
     - Unless type 4, 0x17, or type 2 with mission 0x2b: `createSentryGuns`, `createFighterTurrets`, `createWingmen`.
     - Then `assignGuns`, `connectPlayers`, `PlayerEgo::setRoute`. Type is forced to 3.
5. **`MGame::reset` 0x1a793c:** camera (§7), `TargetFollowCamera`, HUD, Radar, **`LevelScript`** (runs after the Level, so its positions win, see §6), `LevelScript::resetCamera`, `initParticleSystems`.
6. **Restore HP** from `Status+0x64/0x5c/0x60/0x68` when they are ≥ 0.

`Level::createScene` 0xc2910 is only used for types ≠ 3:
- Type 2 (main-menu background) = `createPlayer` + `createMission` with an empty mission, i.e. a normal orbit. In mission 0x2b it also adds the static meshes 0x37d0 and 0x37d1.
- Types 4 and 0x17 are in `assemblies_scenes_notes.md`.

## 2. What is in an orbit level

**One level = one station orbit.** Other stations of the system are **not** present as 3D objects. They appear only as planet billboards (`StarSystem`, one per station of the system plus the sun), which double as radar/autopilot targets (`StarSystem::getPlanetTargets` = `+0x18`, one `PlayerStatic` per station).

The landmarks array is `Level+0x100`, 4 entries:

| Index | Object | Exists when |
|---|---|---|
| 0 | `PlayerStation` of the current station | Not in an empty orbit (below). Exception: stations 27, 110 and 111 are built even when the orbit is "empty". |
| 1 | `PlayerJumpgate`, visible ("stream") | `system != null && system.warpGateIndex == currentStation` (`SolarSystem::currentOrbitHasWarpGate` 0x180bd8), i.e. only in the orbit of `systems.json.jumpgateStation`. Systems with −1 (Mido, Y'mirr, Beidan, Herjaza, Skavac, Skor Terpa, Alda) have none. |
| 2 | `PlayerJumpgate`, **invisible** (`setVisible(false)`, no bounding volume) | Always, as long as there is a current station. Used as the arrival point (§4). |
| 3 | `PlayerWormHole` (mesh 0x4262 = 16994) | `!Status::gameWon()` (mission ≤ 0x2c). |

Wormhole visibility and placement:
- Visible only if `(comingFromAlienWorld || station.isAttackedByAliens() || inAlienOrbit) && mission < 0x2b`. Otherwise it exists but is hidden.
- Radius 40000, animation state 2.
- Position is time-seeded, random on every visit: x = rand(80000) − 40000, y = rand(40000) − 20000, z = rand(40000) + 40000.

**Empty orbit** (`Status::inEmptyOrbit` 0xb8ee8) means no station object. It applies to:
- station 78 while mission ≤ 1;
- stations 102, 103, 104, 109, 110, 132, 133, 134;
- station 111 when mission > 93;
- station 101 when mission ≥ 84;
- alien orbit when mission is 43..83 or ≥ 154.

Docking is disabled there (`Level::collideStation` returns 0).

## 3. `Level::createSpace` 0xbbba0 (station, jumpgates, wormhole, colours)

### 3.1 Station
- `new PlayerStation(Status::getStation())` 0x146cf0. The mesh/assembly is chosen by station index and race; see `assemblies_stations_notes.md`.
  - Regular stations: root 21000 + index, then 21800 + i and 22000 + i for races 0, 2 and 3. The `assemblies.json` entry is named `station_<idx>_<race>`, e.g. `station_078_midorian`.
  - Vossk stations: `station_vossk` (16436). Void: `station_void`. Special ones: `v_station_*`, `sn_*`.
- **Position: (0, 0, 0).** The `PlayerStaticFar` ctor gets (0, 0, 0), and nothing moves the station.
- **Rotation: (0, π, 0).** Radius 15000, max HP 9999999.
- The station is added to the LODManager. After DLC1 (mission > 0x53) station 0x65's name is copied over.

### 3.2 Jumpgates (landmarks 1 and 2)
Seed `setSeed(2 · stationIndex)`, or −1 if there is no station. It is reset (time seed) right after the loop. `A` starts at 0 (`Level+0x138`). For i = 1 (only if the orbit has the gate), then i = 2:
```
s = rnd.nextInt(2); k = rnd.nextInt(500)
A += (s == 0 ? -(250 + k) : (250 + k)) * 16          // |step| 4000..11984 of 65536 per turn
r  = (i == 1 ? 90000 : 120000) + 3.0 * A              // float, A is the running int
pos = Ry(A / 65536 * 2π) · (0, 0, r)  = (r·sin a, 0, r·cos a),  y forced to 0
```
Floats recovered from the literal pool:
- 120000 at 0xbc968, 90000 at 0xbc96c;
- the factor 3.0 (`vmov s16, #3.0` at 0xbc258).

Gate geometry, by race = `SolarSystem::getRace` (0 in an alien orbit):
- **Meshes** from `DAT_00254360[race*4 + 0..3]`:
  - main: 15000 / 15004 / 15008 / 15012;
  - emissive child: +2;
  - anim_add child: +1;
  - jump animation handle: +3 (`addJumpAnimationHandle`, swapped in by `PlayerJumpgate::activate`).
- **LODs:** `DAT_00251fa0[race]`, at 40000 / 70000 (squared internally). Vossk gets extra LOD child meshes 0x3ab0/0x3ab1 (15024/15025).
- `assemblies.json`: `jumpgate_terran`, `jumpgate_vossk_anim`, `jumpgate_nivelian`, `jumpgate_midorian`.
- `PlayerJumpgate(0xf, geom, x, y, z, visible = (i != 2))` 0xb1a8c:
  - **Rotation is always (0, π, 0)**, recovered from 0xb1b6a; it doesn't face the station.
  - The visible gate gets radius and a BoundingSphere of **7500** (Vossk system: **11250**).
- Beyond 295001 units the gate is drawn as an impostor at 295000 (`PlayerStaticFar::update` 0x141310).

**Alien orbit:** landmark 2 is then moved to `(0, rand(20000) − 10000, rand(50000) + 170000)` and set facing the origin. `A` is reset to 0.

After the loop: `A += 0x8000`. If this is **not** a stream-out arrival, `A = rnd.nextInt(2) == 0 ? +1600 : −1600` (time-seeded). `createPlayer` uses `A` as the player's yaw (§5).

**Reference values** (exact, from the RNG port; `space_backdrop_sim.py` has the same RNG). Hidden gate = landmark 2 in the gate orbit. "Light dir" is the unit vector toward the sun (§6):

| System | Gate station | Jumpgate (landmark 1) | A1 | Hidden gate (landmark 2) | A2 | Light dir (toward sun) |
|---|---|---|---|---|---|---|
| 0 Suteo | 0 | (108380, 0, 59219) | 11168 | (184, 0, 120048) | 16 | (0.966, −0.034, 0.258) |
| 1 Pan | 5 | (98939, 0, 68327) | 10080 | (17109, 0, 123137) | 1440 | (−0.708, 0.096, 0.700) |
| 2 Behén | 30 | (91095, 0, 74526) | 9232 | (168939, 0, −63092) | 20112 | (−1, 0, 0) |
| 3 V'ikka | 15 | (97197, 0, 69801) | 9888 | (52272, 0, 121941) | 4224 | (−1, 0, 0) |
| 4 Eanya | 20 | (92903, 0, 73193) | 9424 | (14383, 0, 122809) | 1216 | (0.866, −0.051, 0.498) |
| 5 S'kolptorr | 25 | (100089, 0, 67322) | 10208 | (160257, 0, 30856) | 14400 | (−1, 0, 0) |
| 6 Wolf-Reiser | 10 | (106772, 0, 60919) | 10976 | (34056, 0, 123801) | 2800 | (−1, 0, 0) |
| 7 Aquila | 35 | (85412, 0, 78373) | 8640 | (54538, 0, 121523) | 4400 | (−0.259, −0.177, 0.949) |
| 8 Buntta | 40 | (94099, 0, 72281) | 9552 | (1663, 0, 120421) | 144 | (−0.966, −0.011, −0.259) |
| 9 Weymire | 45 | (83694, 0, 79439) | 8464 | (−9011, 0, 117254) | −800 | (−0.259, 0.048, 0.965) |
| 11 Union | 55 | (68128, 0, 87298) | 6912 | (−25569, 0, 109913) | −2384 | (0.258, 0.093, 0.962) |
| 12 Oom'bak | 60 | (77196, 0, 83101) | 7808 | (15938, 0, 123004) | 1344 | (−0.501, −0.103, 0.860) |
| 13 Vulpes | 65 | (69434, 0, 86756) | 7040 | (28408, 0, 123839) | 2352 | (0.866, 0.097, 0.491) |
| 14 Magnetar | 70 | (59582, 0, 90366) | 6080 | (140705, 0, 66021) | 11808 | (−1, 0, 0) |
| 16 Prospero | 80 | (38491, 0, 94562) | 4032 | (103563, 0, 101362) | 8304 | (−0.966, 0.038, 0.256) |
| 17 Nesla | 85 | (51649, 0, 92492) | 5312 | (163831, 0, 20972) | 15056 | (−1, 0, 0) |
| 18 Pescal Inartu | 90 | (60901, 0, 89946) | 6208 | (151741, 0, 48841) | 13136 | (−0.708, 0.030, 0.706) |
| 19 Augmenta | 95 | (49666, 0, 92919) | 5120 | (141568, 0, 64843) | 11904 | (−1, 0, 0) |
| 20 K'ontrr | 62 | (77836, 0, 82765) | 7872 | (168333, 0, 4132) | 16128 | (−1, 0, 0) |
| 21 Ni'mrrod | 12 | (107311, 0, 60357) | 11040 | (171832, 0, −37480) | 18624 | (0.866, −0.055, 0.498) |
| 25 Loma | 105 | (52972, 0, 92184) | 5440 | (1477, 0, 120375) | 128 | (−1, 0, 0) |
| 26 Shima | 108 | (42255, 0, 94153) | 4400 | (−2016, 0, 119455) | −176 | (0.966, 0.038, 0.257) |
| 27 Ginoya | 112 | (104034, 0, 63664) | 10656 | (168285, 0, −66402) | 20304 | (0.258, −0.026, 0.966) |
| 28 Talidor | 116 | (105137, 0, 62579) | 10784 | (−552, 0, 119855) | −48 | (−1, 0, 0) |
| 29 Paréah | 120 | (46202, 0, 93567) | 4784 | (−53777, 0, 87575) | −5744 | (0.966, 0.034, 0.258) |
| 30 Me'enkk | 125 | (112665, 0, 54348) | 11696 | (15548, 0, 122957) | 1312 | (−0.966, −0.049, −0.255) |
| 31 Wah'norr | 130 | (85878, 0, 78076) | 8688 | (171910, 0, −35018) | 18480 | (−0.259, −0.042, 0.965) |

In a non-gate orbit, landmark 2 is computed with only one step: A2 = ±(4000..11984), r = 120000 + 3·A2. For example, station 78 (new game) gives (73037, 0, 116522).

For all 27 gate stations the first `nextInt(2)` returns 1 (Java's first output is strongly correlated with small seeds). So the visible gate always sits on the +X side, 22°..66° from +Z, at a distance of 102000..126000.

### 3.3 Colours
- `Level` globals `r, g, b` = `SolarSystem +0/+4/+8` (the ints called `unknownTriple` in `systems.json`, e.g. Mido (8, 11, 21)); with no system, (10, 136, 10).
- `r_min/g_min/b_min` = value / 3.
- They are used only by `Level::flashScreen` / `Level::update` (screen flash colour), not by lighting.

## 4. Player spawn position (`Level::init`, after `createPlayer`)

`Level::initStreamOutPosition` (static) is 1 when the level is entered by **travel**, 0 when **undocking**:

| Set to 1 | Set to 0 |
|---|---|
| `StarMap::depart`, `MGame::updateJumpScene` (jumpgate / jump drive), planet local jump in `MGame::OnUpdate`, some `ModStation`/`LevelScript` campaign departures | Normal launch from `ModStation`; some campaign departures |

| Case | Position | Orientation |
|---|---|---|
| **Undock** (`initStreamOut == 0`) | **(10, 10, 10000)**, recovered from 0xbb7a8 | yaw ±1600/65536·2π = **±0.1534 rad (±8.79°)**, random sign, so roughly facing +Z, away from the station at the origin. Speed = 2 (the `PlayerEgo` ctor sets `+0xb8 = 2.0`, throttle `+0xbc = 1.0`). |
| Travel into the **gate orbit** (`currentOrbitHasWarpGate`), or no station stack / no system | Position of **landmark 2** (hidden gate) | yaw = A2 + π, i.e. facing the origin/station |
| Travel into a **non-gate orbit** | `4 × position of the planet billboard of the previous station` (station stack entry [1], looked up in the current system's station list; planet geometry index k+1). If the previous station is not in this system: `4 × (0, 0, 25000)` = **(0, 0, 100000)**. The planet billboards sit at −20000·dir, so this is about 80000 units out. | `setDirection(normalize(−pos), up (0, 1, 0))`: facing the station |
| Black-market system (index 25, only via `createMission` and stream-out) | + (0, 0, 40000) on top of the above | |
| Campaign mission 1 | (0, 0, −110000) in `Level::init`, but `LevelScript` then overrides it (§6) | |

The station stack (`Status+0x19c`, 3 entries, [0] = current) is pushed by `Status::addStationToStack` from `departStation`.

## 5. `Level::createPlayer` 0xbca00

- `Player(0x4b0, maxHP, primarySlots, secondarySlots, turretSlots)`, shield/armor from the ship. `PlayerEgo` is 0x3a0 bytes.
- `PlayerEgo::setShip(shipIndex, race)`: the player variant of `Globals::getShipGroup`, `*_engine_glow_add` (see ships notes).
- Rotation `(0, A/65536·2π, 0)` with `A = Level+0x138` from §3.2. The position is set afterwards in §4.
- Guns:
  - `FileRead::loadWeaponPositions(shipIndex)` (`weapons_hd.json`).
  - Primary/secondary guns use `Gun::setOffset(weaponPos[type][Ship::getSlotPos(item)])`.
  - Turret: `PlayerEgo::setTurretPosition(weaponPos[2][0])`.
  - Primary damage × `Ship::getDamageFactor`, reload × `getFireRateFactor`.

## 6. Lights and fog (`StarSystem::StarSystem` 0x15c200 → `StarSystem::initLight` 0x15d080)

### Sun direction
- The sun and planets are billboards on `plane` (0x1a70), redrawn at camera + offset every frame (`StarSystem::render` 0x15db84).
- Seed `setSeed(300 · stationIndex)`.
- Each body is placed with `setRotation(pitch, yaw, 0)` then `moveForward(−20000)` (literal 0xc69c4000), so its position is −20000·dir.
- **Light direction** `StarSystem+0x30` = −dir(sun) = the unit vector from the origin **toward the sun** (`getLightDirection` 0x15d812).
- Sun yaw = slot·0xaaa/65536·2π (15° steps):
  - slot = `nextInt(14) + 5`;
  - forced to 6 for station textureIndex 9, 13, 14, 18, 20, and to 4 for 21 (`DAT_00258e20`); 16 for texture 22.
- Sun pitch = (nextInt(4096) − 2048)/65536·2π (±11.25°).
- The current station's planet is slot 0, pitch 0: it is always at **(0, 0, −20000)**, behind the undocking player.
- The full planet/sun algorithm is in `space_backdrop_sim.py`.

### `initLight`
Floats recovered from the disassembly. `sysTex` = system textureIndex, `stTex` = station textureIndex.

| Setting | Value |
|---|---|
| Light count (engine `+0x31c`) | 2 |
| `sunColor` (StarSystem+0..8) | `DAT_00258b0c[sysTex*3 .. +2]` (19 rows); × 0.5 for sysTex 15 when mission == 0x59 or ≥ 0x9e |
| Global scene ambient | `a · sunColor`. a = 0.15; for sysTex 15 (mission ≠ 0x59): 0.15 if mission ≥ 0x9e, else 0.7 (`DAT_0015d6e0/e4`) |
| Rim colour | `3 · DAT_00258d34[sysTex*3 ..]` |
| Material ambient / diffuse / specular | (1, 1, 1) |
| Material shininess | 20 |
| **LIGHT0** (0x4000) | direction = light dir (toward the sun), ambient (0, 0, 0), diffuse = `clamp(k · sunColor, 0, 2)` per channel with k = 15 (30 for sysTex 15 when mission < 0x9e and ≠ 0x59), specular (2, 2, 2) |
| **LIGHT1** (0x4001) | direction **(0, 0, −1)** (toward the current planet at (0, 0, −20000)); diffuse = specular = `1.5 · DAT_00258bf0[stTex*3 ..]` (27 rows, planet bounce colour); no system: row index 23 |
| Particle ambient | sunColor |
| Fog | Off by default (`FogEnable(0)`) |

Colour tables (r, g, b):

| sysTex | sunColor 0x258b0c | rim/3 0x258d34 |
|---|---|---|
| 0 | .21 .32 .25 | same |
| 1 | .50 .29 .28 | same |
| 2 | .24 .40 .37 | same |
| 3 | .22 .32 .43 | same |
| 4 | .18 .23 .27 | same |
| 5 | .38 .13 .11 | same |
| 6 | .34 .34 .30 | same |
| 7 | .24 .26 .25 | same |
| 8 | .21 .23 .27 | same |
| 9 | .43 .47 .47 | same |
| 10 | .43 .21 .34 | same |
| 11 | .85 .41 .14 | .20 .11 .04 |
| 12 | .08 .24 .48 | same |
| 13 | .20 .25 .20 | same |
| 14 | .30 .35 .15 | same |
| 15 | 1.0 .52 .24 | .50 .26 .12 |
| 16 | .39 .48 .44 | same |
| 17 | .41 .52 .58 | same |
| 18 | .67 .63 .46 | same |

Planet light by stTex (`0x258bf0`, then ×1.5):

| stTex | r g b | stTex | r g b | stTex | r g b |
|---|---|---|---|---|---|
| 0 | .29 .35 .31 | 9 | .075 .065 .045 | 18 | .07 .07 .07 |
| 1 | .25 .22 .14 | 10 | .20 .43 .35 | 19 | .26 .29 .31 |
| 2 | .20 .17 .09 | 11 | .27 .09 .04 | 20 | .13 .10 .06 |
| 3 | .30 .27 .31 | 12 | .38 .29 .16 | 21 | .31 .31 .21 |
| 4 | .25 .34 .41 | 13 | .06 .05 .03 | 22 | .39 .32 .25 |
| 5 | .39 .165 .045 | 14 | .11 .10 .11 | 23 | .64 .50 .67 |
| 6 | .37 .43 .26 | 15 | .25 .23 .20 | 24 | .45 .38 .34 |
| 7 | .42 .22 .11 | 16 | .25 .19 .135 | 25 | .48 .52 .58 |
| 8 | .18 .25 .28 | 17 | .17 .35 .48 | 26 | .21 .27 .34 |

**Fog.** Linear (GL 0x2601), start 0, density 1. Colour is RRGGBBAA; planet billboards get the fog colour × 0.7 as tint (`transform+0x48`).

| sysTex | End | Colour |
|---|---|---|
| 11 | 50000 | 0xdb6923ff |
| 12 | 50000 | 0x163e7cff |
| 15 (not mission 0x59) | 100000 | 0x82441fff; planets tinted with the same colour |
| 16 | 150000 | 0x47665eff |
| 17 | 150000 | 0x738d95ff |
| 18 | 150000 | 0xaba075ff |
| Other | fog off | |

## 7. Camera (`MGame::reset` 0x1a793c, `LevelScript::resetCamera` 0x16f418)

- `CameraSetPerspective(cam, fov = 1.22, near = 20, far = 300000)`. Values recovered at 0x1a7a00.
  - Alien orbit: far = 450000 if mission < 0x50, else 300000.
  - Docking camera (`PlayerEgo::setDockingCamera`) also uses 300000/450000.
- `fov` is a full angle in radians (the engine takes tan(fov/2); 1.22 rad = 69.9°). It is most likely vertical.
- Chase camera (`TargetFollowCamera` on the player geometry): target offset **(0, 600, −650)**, camera offset **(0, 600, −1338)**, in local space, behind and above.
- `LevelScript` ctor 0x15e650 stores an intro/fly-by camera offset:
  - undock: (±(500..2499), ±(500..2499), 9000);
  - arrival: (±(500..999), ±(500..999), 7000).
  - Its exact use was not traced.

## 8. Docking and travel

| Action | Trigger | Result |
|---|---|---|
| **Dock at station** (`MGame::dockEvent` 0x1afebc) | Autopilot target = station (`goingToStation`) AND (player position inside a station bounding volume from `collision.json` (`Level::collideStation` → `PlayerStation` collide), OR `|playerPos| < 16000` (`PlayerEgo::calcCollision` 0xab550 sets `collidesWithStation`)). Not in an alien or empty orbit. | Save HP, switch to module 5 (`ModStation`) |
| **Jumpgate** ("stream") | Autopilot to landmark 1 (`goingToStream`) and inside its sphere (r 7500/11250, `Level::collideStream`) → `PlayerEgo::dockToStream` | With no programmed station, the StarMap opens in jump mode to pick one. With one, `MGame::updateJumpScene` 0x1afad4 runs: gate animation (`PlayerJumpgate::activate` when the camera z < player z − 10000; jump sound 0x1f at −16500); once `animationEnded`: `Status::departStation(programmedStation)`, `setInitStreamOut`, `jumpgateUsed`, reload module 2 **directly in the target station's orbit** (any station of the target system, not necessarily its gate station) |
| **Local jump to another station of the same system** | `LevelScript::setAutoPilotToProgrammedStation` 0x160b50 sets the autopilot to that station's **planet target**. When the radar lock on it completes (`Radar::draw` 0x1554fc; lock time `Radar+0x1b4` = 8000 ms, or attribute 0x1d of the equipped item of sort 0x11) → `PlayerEgo::dockToPlanet` 0xadd20 | Speed 8 u/ms, look-at camera. `isDockedToPlanet` after **3000 ms** → `departStation(planet's station)`, `setInitStreamOut`, reload. Target in another system without a gate here: the autopilot goes to the planet of the gate station first; in the gate orbit it goes to landmark 1 |
| **Jump drive** (item 0x7a energy cells) | `MGame::startChargingJumpDrive` 0x1a9710 → `startJumpScene` 0x1abf10 (khador jump mesh `+0x10c`) → `updateJumpScene` | Same departure path; no gate needed |

## 9. New game (campaign start)

- `startGOF2` → **`Status::resetGame` 0xba78c:**
  - campaign mission 0 = `Mission(4, 0, 0x4e)`;
  - **ship index 10 "Phantom"** (`Globals::ships[10]`);
  - **station 78 "Var Hastra", system 15 "Mido"** (Midorian, sysTex 9, no jumpgate);
  - equipment items (index = pointer offset / 4):
    - 2 and 2: Nirai Charged Pulse ×2;
    - 54: Fluxed Matter Shield;
    - 59: T'yol;
    - 82: Telta Ecoscan;
    - 73: Synchrotron Boost;
    - 36: Edo ×6 (secondary);
  - `options[0x35]` (Valkyrie) makes system 25 visible.
- Then module 2 (`MGame`), directly in space (no dock).
- **Mission 0 and station 78 form an empty orbit**, so there is no station and no gate. Special cases:
  - skybox 0x458b (createSpace);
  - planet texture 0x273b for the current planet;
  - current planet scale halved.
- `createCampaignMission` case 0:
  - 3 pirate ships (race 8, kinds 2 / 0x17 / 2) at (50000, 50000, 50000), asleep, always enemy, 150 HP, exhaust hidden;
  - player invulnerable (HP 9999999).
- `LevelScript` ctor, mission 0:
  - player computer-controlled at **(0, 0, −60000)**, direction (0, 0, 1);
  - camera at (−1000, −500, −40000), look-at;
  - pirates hidden;
  - `hyper_drive` geometry 0x3ab3 (15027) created.
- Mission 1 (same empty orbit):
  - one Midorian ship (race 3, kind 0x1e) at (300, 50, −6000) with route (0, 0, −5000) → (0, 0, 0);
  - `LevelScript`: player frozen at **(0, 0, 0)**, rotation (0.462, 0.462, 1.5339), exhaust off;
  - camera at (1500, 1600, −3000), look-at, 5 s fade-in.

## 10. Functions used

| Function | Address |
|---|---|
| `Level::Level` / `init` / `createSpace` / `createPlayer` / `createScene` / `createCampaignMission` | 0xbaf80 / 0xbb49c / 0xbbba0 / 0xbca00 / 0xc2910 / 0xc3370 |
| `Level::collideStream` / `collideStation` / `render` | 0xd4378 / 0xd4398 / 0xd4950 |
| `PlayerStation::PlayerStation` / `setPosition` | 0x146cf0 / 0x147ec4 |
| `PlayerJumpgate::PlayerJumpgate` / `activate` / `timeToJump` / `animationEnded` | 0xb1a8c / 0xb1c00 / 0xb1c4c / 0xb1c78 |
| `PlayerStaticFar::PlayerStaticFar` / `update` | 0x141284 / 0x141310 |
| `PlayerWormHole::PlayerWormHole` | 0xb1d3c |
| `StarSystem::StarSystem` / `initLight` / `render` | 0x15c200 / 0x15d080 / 0x15db84 |
| `MGame::OnInitialize` / `reset` / `dockEvent` / `updateJumpScene` | 0x1a6ebc / 0x1a793c / 0x1afebc / 0x1afad4 |
| `LevelScript::LevelScript` / `resetCamera` / `setAutoPilotToProgrammedStation` | 0x15e650 / 0x16f418 / 0x160b50 |
| `Status::resetGame` / `inEmptyOrbit` / `departStation` / `addStationToStack` | 0xba78c / 0xb8ee8 / 0xb63e0 / 0xb6140 |
| `PlayerEgo::PlayerEgo` / `goingToStream` / `goingToStation` / `dockToPlanet` / `isDockedToPlanet` | 0xa5610 / 0xa7804 / 0xa7822 / 0xadd20 / 0xaddb8 |
| `StarMap::depart` | 0xd81ac |
| `AERandom::setSeed` / `nextInt(int)` | 0x7ad04 / 0x7add2 |

## Uncertainties
- **Unity rotation mapping** (§0): whether "game yaw θ → Unity yaw π − θ" holds depends on how the FBX export mirrored the meshes. Verify with one known case: the station's (0, π, 0) against an undocking player at ±8.8°. The station and the undocking player should face opposite directions.
- **FOV axis:** 1.22 rad is most likely the vertical FOV (landscape), but I didn't check which projection term uses it.
- **LIGHT1 space:** direction (0, 0, −1) is stored normalized in the engine. I assume world space (it points toward the current planet); the shaders weren't checked.
- **Landmark 2:** it is invisible, has no bounding volume, and its only confirmed uses are the arrival point and the alien-orbit spot. Generic loops over all landmarks (Radar, PlayerFighter) may touch it; not traced.
- **Local-jump lock time:** it assumes the item of sort 0x11 is the scanner-type item that shortens the lock (attribute 0x1d). The exact lock condition in `Radar::draw` (11 KB) was only partly read.
- **Mission 1 position:** `Level::init` sets (0, 0, −110000), then the `LevelScript` ctor sets (0, 0, 0). I assume the LevelScript value is final, since the LevelScript is built later in `MGame::reset`.
- **Intro camera offset:** the `LevelScript +0x28..0x30` vector (9000 / 7000 z) is assumed to be the launch fly-by camera; its use in `LevelScript::process` wasn't traced.
- **Wormhole bool:** the visible flag comes from `[sp+0x10]` (alien condition && mission < 0x2b), traced in the disassembly at 0xbc0b8.
- **Main-menu level (type 2):** the player position isn't set by `init` (no `createPlayer` spawn branch). `CutScene` drives it; not covered here.
- **Item/ship indices** in `resetGame` are derived from the pointer offsets divided by 4 into `Globals::items` / `Globals::ships`, assuming those arrays are in `items.json` / `ships.json` order.
