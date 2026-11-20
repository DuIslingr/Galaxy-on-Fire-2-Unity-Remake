# What the remake can take from Starfield

Survey of 2026-11-19, done without the Editor. Sources: the Steam copy of Starfield 1.16.244 (143 GB, Data in
`/run/media/duislingr/7ffcb807-e332-4b18-a937-f605d1a0e713/SteamLibrary/steamapps/common/Starfield/Data`), the decomp
workspace `~/Downloads/Archive/starfield-re` (its `docs/STATUS.md`: the Ghidra project, CommonLibSF, the SFSE anchors, the
CDB toolkit under `ext/sftools`), against the remake's mod format (docs/notes/mods*.md). Everything below was read from the
files with the probe scripts in `Reference/tools/starfield` (Python 3, Pillow for the textures, nothing else); the lines
marked *proven* were run today. Keep this file current as work lands, like the GoF3 and ES2 roadmaps in the importer repos.

## Where Starfield keeps things

- **Archives:** 97 `.ba2` (BTDX). Version 2 `GNRL` holds everything but textures, one zlib stream per file, 32-byte header
  (the FO4 header plus 8 bytes). Version 3 `DX10` holds the textures, 36-byte header, every chunk an **LZ4 block** (no
  frame), the DDS header to rebuild from the entry (width, height, mips, DXGI format, cube flag). *Proven:*
  `ba2_extract.py` on Materials, Localization, Misc, WwiseSounds and Meshes; `ba2_dx10.py` on Textures10 (BC1 sRGB id 72,
  BC5 84, BC7 sRGB 99; Pillow decodes them once the sRGB ids are mapped to the plain ones, 72 -> 71, 99 -> 98).
- **Plugins:** `Starfield.esm` (1.46 GB), `BlueprintShips-Starfield.esm` (304 MB: the ships), `ShatteredSpace.esm`, the
  `SFBGS*.esm` DLCs. TES4-family records, 24-byte headers, zlib on records with flag 0x40000, components `BFCB`..`BFCE` on
  the new Starfield forms. Names are localized: `FULL` is a string id into `strings/starfield_en.strings` (48,875 entries;
  `strings.py` joins them, *proven* on the 354 ship names).
- **Meshes:** 68,459 `.nif` (Gamebryo 20.2.0.7, `BSGeometry`) are scene graphs only: node transforms, material names
  (`Materials\Ships\ShipCommon\ShipsDecal02.mat`), and the geometry by hash path `geometries/<20 hex>/<20 hex>.mesh`
  (675,406 files). The `.mesh` is simple: u32 version (2), u32 index count, u16 indices, f32 scale, u32 weights per vertex,
  u32 vertex count, i16 xyz (x scale / 32767), then counted blocks of UV1 (half2), UV2, colours (4 bytes), normals and
  tangents (packed 4 bytes), weights. *Proven:* the Deimos DS10 cockpit (117 geometry refs; its hull block 4,284 triangles,
  8 x 13.6 x 6 units).
- **Materials:** one file, `materials/materialsbeta.cdb` (105 MB, "BETH v8" component database): material object -> layers
  -> material -> `TextureSetID` -> texture set with `MRTextureFile` paths. The CDB toolkit (`cdbtool.py find | object`)
  walks it; its `material` command stops at the first object, so an importer follows `_Material1 -> TextureSetID` itself.
  fo76utils has a complete C++ reader of this (its CE2 material code).
- **Textures:** PBR sets `_color / _normal / _rough / _metal / _ao / _opacity / _emissive / _height`, 51,000 DDS. The ships
  use trim sheets (`textures/ships/shipcommon`, 423 files) plus decals, not one map per hull: 916 ship textures in all.
- **Sound:** Wwise. 26,662 `.wem` (Vorbis, 48 kHz; `vgmstream-cli` decodes them, *proven* on an engine throttle and a
  space music phrase), named only by id; `sound/soundbanks/soundbanksinfo.json` (29 MB, in WwiseSounds05) maps every id to
  its source path (`VEH\Player_Spaceship\Flying\VEH_3rd_Player_Engine_Throttle_Up_01.wav`). 18 `.bnk` banks hold the
  event logic (VEH, WPN, MUS, AMB, NPC ...; wwiser reads them).
- **Particles** are `.psfx` (833, Bethesda's own particle system): not convertible, only their textures are.
- **UI** is Scaleform `.swf` (ship HUD, star map, ship builder): reference only. **Videos** `.bk2`: not relevant.
- **Data tables worth more than the records:** `Misc.ba2` `space/stars.csv` (122 rows: the HYG catalogue with x, y, z in
  parsecs, spectral class, luminosity, the habitable zones) and `space/galaxy.csv` (1,813 bodies: star, mean orbit,
  eccentricity, radius, mass, gravity, day, year, type, rings, atmosphere, hydro %, ice caps, heat, life, settled).
- **ESM record types that matter:** `GBFM` generic base forms (ships, modules, stations: 3,141 + 356), `PKIN` pack-ins
  (prefabs, each with its own cell: 11,281), `CELL` / `REFR`, `STDT` 123 stars, `PNDT` 1,765 planets, `SUNP` 52 sun
  presets, `MUSC` / `MUST`, `FACT` 812, `GMST` (274 `fSpaceship*` and friends), `AVIF` (the ship stats), `COBJ` (the ship
  builder's listings: 268 `co_SMS_*`), `WEAP` (14 ship turret weapons), `EXPL`, `PROJ`. `SFBK / SFPC / SFPT / SFTR` are
  terrain, not ships.

## How a ship is built (*proven* on the Frontier)

`BlueprintShips-Starfield.esm` has 356 ship `GBFM` templates, 354 named: Frontier, Razorleaf, Star Eagle, Kepler R / S,
Mantis, Narwhal, Abyss Trekker, Shieldbreaker, Wanderwell, the manufacturers' lines (Deimos Dagger / Gladius / Longsword,
Nova Kfir / Mustang, Stroud Trebuchet / Warmonger, Taiyo Mako / Sparrow / Stingray, HopeTech Watchdog, each in I-IV
tiers), the cruisers / destroyers / freighters / cargo / personnel classes, the Crimson Fleet, Ecliptic, Va'ruun and Spacer
hulls, Starborn Guardian I-VI, Helix and Scorpius, and six starstations (Polvo, the outpost station, UC01). Each has an
exterior and an interior cell (`BlueprintExterior<Name>`). The exterior cell's `REFR`s carry `GNAM` / `JNAM` links to the
module pack-ins `ShipPI_SMOD_*` (structure) and `ShipPI_EMOD_*` (weapons) with position and rotation in `DATA`; each
pack-in's cell holds the module's `MSTT` with its NIF under `Ships\Modules\...` (turrets under `Ships\Rigged\TurretEMOD`).
The Frontier resolves to: Magellan C2 cockpit, NG-6 bay, 2 x White Dwarf 2000 engines, R-2300 reactor, NG150 grav drive,
10S Protector shields, Sextant 100CM cargo, Frontier 2L1W1H hab, CL-3C struct, 4 x RE-J01 landers, 100G fuel tank, Dragon
221MW laser, Atlatl 270A missiles, Mauler 104L cannon. The lights, decals (`PDCL`), nav thruster and engine fx are REFRs of
their own in the same cell. The module library: 1,444 NIFs under `meshes/ships/modules` (struct 423, hab 222, equipment
149, eng 81, cargo 74, lander 62, thrust 54, fuel 52, cockpit 45, shield 41, grav 30, reactor 25, bay 22, docker 21) and 38
rigged turrets. `Starfield.esm`'s 1,280 further named ship forms (`EncShip_*`, `LvlShip_*`) are crew / level variants of
these blueprints, not new hulls.

The main ESM's 1,918 ship-related `GBFM` by prefix: `SMS_` structure (hab 213, struct 174, cargo 55, cockpit 44, fuel 36,
lander 35, docker 13, thrust 10, bay 8), `SMA_ / SMB_ / SMC_` class A / B / C equipment (weapons 53 / 89 / 81, engines
56 / 37 / 16, shields 51 / 21 / 19, reactors 21 / 15 / 17, grav drives 16 / 12 / 12), `SMM_` the matching NPC-only ones.

## What fits, and how

Assets (the remake's mod format already has a place for them):

| # | What | From | Into | Feasibility |
|---|---|---|---|---|
| A1 | **Named ships**, ~250 distinct hulls | the blueprint cells -> module pack-ins -> NIF + `.mesh`, materials through the CDB | one GLB per ship, `ships.json` (fighters ~20-40 m, cruisers 80 m and more; `scale` sets it) | Feasible, the biggest payoff. Interiors not needed. Per hull ~10-40 modules merged into one mesh. |
| A2 | **The ship builder's modules as a kit** | `co_SMS_*` listings, the module NIFs with their snap helpers (`ShipSnapNodeHelper_*`) | `shipkits.json` (customizable ships) | Partial: the remake's kits are slot-based, Starfield's builder is free snapping. A per-manufacturer kit with cockpit / struct / engine / wing slots works; the full 1,444-part grid doesn't. |
| A3 | **Ship weapons**, 178 named (Dragon / Reza / Blaze lasers, Disruptor / PB / Obliterator particle beams, KE / Mauler / Dangan cannons, Jishaku / Marauder railguns, Atlatl / CE / Hunter / Infiltrator missiles, EMP Suppressors) | the `SMA/SMB/SMC_Weapon_*` forms' components (damage, range, rate, power), the EMOD NIFs and turret rigs | `items.json` primaries / secondaries / turrets with their models | Feasible. The shot fx are `.psfx`: use the remake's fx kinds with Starfield's colours and sounds. |
| A4 | **Ship and weapon sounds** | the VEH bank (engines by manufacturer, throttle, boost, grav jump sequence, shield impacts, cockpit shake) and WPN (each ship weapon's fire) | `ships.json` `sounds`, the weapons' sounds | Feasible; every clip names itself through soundbanksinfo. |
| A5 | **Music** | the score is generative: 1,060 `MUS\Score` phrases (~20 s: Space A / B / C palettes 87 / 94 / 83, Main menu 66, combat, stingers); whole tracks only under `MUS\Diegetic` (Terrabrew 24, The Well 14, SSNN 13, Marco's 10, Euphorika 8, Astral Lounge 6, Crimson Fleet 5, Madame Sauvage 4, Volii hotel 3, Jake's 3) | `music/` (lounge tracks, the main-menu palette) | Partial. A space ambience needs the Wwise logic (`.bnk`, wwiser) or our own sequencing of the phrases. |
| A6 | **Stations**: The Key, The Eye, the Deimos / Stroud-Eklund / Trident staryards, The Clinic, the Vigilance, Polvo, outpost starstations, Spacer stations | cells (`scStationTheKey`, `ssTheEyeExt`, `ssSettleStroudEklundStaryard` ...) of statics (`StarStations\Gen` 758, catwalks 348, modules 225, `Architecture\SpaceStationKit`) plus `StnPI_Star_*` pack-ins | `stations.json` `model` | Feasible, the same cell-merge pipeline as the ships. The staryard cell is interior-heavy (3,363 refs): take the exterior pack-ins only. |
| A7 | **Asteroids**, 156 NIFs (rock 90, ice 66) | `landscape/rocks/asteroids`, `landscape/ice/asteroids` | mining fields, obstacles | Easy. |
| A8 | **Space sky** | no skyboxes: Starfield draws the stars from the catalogue over `textures/sky/milkyway_color.dds` (4096 x 2048 equirectangular band, *proven*) | a layered-sky band, stars from `stars.csv` | Partial: the band and a star layer, not a nebula per system. |
| A9 | **Planets** | `houdiniplanet*.nif` spheres shaded from biome masks / atmosphere maps (1,927 textures, shader-driven); real texture sets only for Earth, Luna, Mars, Jupiter | `planetSphere` for the four; the rest by type from `galaxy.csv` | Partial. |
| A10 | **The universe** | 122 stars with 3D positions and spectral class, 1,813 bodies with orbits and types, 52 sun presets, the factions (UC, Freestar, Crimson Fleet, Ecliptic, Spacers, Va'ruun, Starborn) | `systems.json` (map position from x, y, z), `sunTexture / sunColor`, mod races, the stations in their systems | Feasible: a `starfield_systems` mod like `gof3_systems`. |
| A11 | Characters | 3D heads (FaceMeshes 1.3 GB, FaceAnimation 17 GB), no 2D portraits | `characters.json` portraits rendered in Blender | Low. |

Gameplay (rules from the data; the exe only where said):

| # | What | From | Into | Feasibility |
|---|---|---|---|---|
| G1 | **Starfield flight**: throttle, reactor power split between weapons / engines / shields / grav drive, boost, turn scale at throttle | 274 `GMST` (`fSpaceshipTurnScaleAtMaxThrottle`, `fSpaceshipMaxAngularAccel`, `fSpaceshipPhysicsLinDamping` ...), the ship `AVIF`s (`SpaceshipForwardForcePerPower`, `SpaceshipEnginePartMaxForwardSpeed` ...); the formulas in the exe (the decomp's job) | a fourth flight style (`ModFlight`, flight rules) | Medium. Only this needs the Ghidra project. |
| G2 | **Ship systems damage**: engines / shields / weapons / grav drive as damageable systems, EM damage, targeting mode | `AVIF` `ShipSystem*Health`, `iSpaceship*DamagePriority`, `fTargetingModeTimeScale` | the capital-ship subsystems exist; for fighters a new feature | Medium. |
| G3 | **Grav jump** fx and sounds | the GravJumpSequence clips, `ShipPI_SMOD_Grav_*` models | `items.json` `jumpFx` | Easy. |
| G4 | **Scan jammers** | 3 `SMS_ScanJammer*` | items against the police scan | Easy. |
| G5 | Ship classes A / B / C (reactor, piloting skill) | the equipment prefixes | loosely tech levels | Low. |
| G6 | Boarding and interiors | the interior cells | nothing in the remake | No. |

Not worth taking: the Scaleform UI, the `.psfx` particles (textures aside), the planets' surface content (terrain, biomes,
POIs, 17 GB of face animation), the quests and dialogue (126,347 `INFO` records, the game's own story).

## What the decomp is for

Every item above is data: ESM + BA2 + CDB, all read with the scripts here. The Ghidra project is needed only for G1 / G2
(the movement and damage formulas that combine the GMSTs and AVIFs) and if a format detail ran out of documentation; it did
not today (`.mesh` is community-documented and reads as such, the CDB has its toolkit, fo76utils reads both). The RTTI
names the classes to start from: `Spaceship`, `BGSSpaceshipEquipment`, `BGSSpaceshipHullCode`, `BGSSpaceshipWeaponBinding`,
`SpaceshipEditor`, `CombatTargetSelectorSpaceship`, `bhkCharacterStateSpaceship`.

## Tooling on Linux

- `Reference/tools/starfield`: `ba2_list.py` (names), `ba2_extract.py` (GNRL, by substring), `ba2_dx10.py` (DX10 -> DDS,
  pure-Python LZ4 block decoder), `esm_groups.py` (top-level record types), `esm_edids.py` (EDID / FULL per type),
  `esm_fid.py` (one form's subrecords), `esm_blueprint.py index` (form id -> type, EDID, model, components; writes
  `<esm>.index.json`, ~3 min on Starfield.esm), `esm_cells.py` (a cell's REFRs, bases and pack-in links), `strings.py`.
- **fo76utils** (github.com/fo76utils/fo76utils, C++, scons; cloned to the session scratchpad, the build was not run
  here): `baunpack` (both BA2 versions), `nif_info -obj` (Starfield NIF with external geometry), `esmdump`, `bcdecode`, and
  the CE2 material reader. The ready-made path for NIF -> OBJ with materials; a Python `.mesh` -> glTF writer is the
  alternative (the format above, glTF written like `es2_ships_importer/tools/glbtool.py`).
- **Blender** add-ons Void SFG Bridge / Starfield Geometry Bridge import NIF + `.mesh` (a headless route to GLB, as the
  Chorus importer does with its exporter).
- `vgmstream-cli` (installed) for `.wem`; wwiser for the `.bnk` logic; the CDB toolkit for materials.
- Scale: the `.mesh` units read as metres for the cockpit (8 wide, 13.6 long); confirm against the NIF node scales and a
  known hull (the Frontier is ~40 m long) before fixing `scale`.

## The ships importer (2026-11-20)

Step 1 below exists: `~/GOF2UnityRemakeMods/starfield_ships_importer` (its README and ROADMAP), which reads the
archives, plugins, `.mesh` geometry and the material database in Python and writes the `starfield_ships` mod: 353 named
hulls assembled from their modules, materials as ships.json entries over shared maps, mounts from the weapon modules
and engines, the engine sounds by manufacturer family, Blender icons. Learned on the way: Bethesda's reference rotations
are `Rx(-x) Ry(-y) Rz(-z)` (checked on the Frontier's mirrored lasers), the `.mesh` normals and tangents are unsigned
10:10:10:2, Starfield's normal maps are DirectX-style (measured by integrability on the bolt decals), the triangle
winding agrees with the normals, and a material's texture set inherits its files from its parent object (a child stores
only what differs, so every CDB lookup climbs the parent chain).

## Suggested order

1. A1 ships with A4 sounds and A3 weapons: a `starfield_ships` importer (blueprint -> modules -> one GLB, materials from
   the CDB, the names from the strings), the same shape as `chorus_ships_importer` (reads the player's own copy, ships
   nothing of Starfield's).
2. A6 stations, A10 universe, A8 sky band: a `starfield_systems` part, like `gof3_systems`.
3. A7 asteroids, G3 jump fx, G4 jammers.
4. A2 kit, A5 music, G1 / G2 only if a Starfield flight style is wanted (then the decomp).

## Numbers found today

| Item | Count |
|---|---|
| BA2 archives / files in Meshes01+02+Patch | 97 / 745,062 (68,459 NIF, 675,406 mesh) |
| Textures (11 archives) | 42,745 |
| Ship blueprints / named / main-ESM ship forms | 356 / 354 / 1,280 |
| Ship module NIFs / rigged turrets / ship textures | 1,444 / 38 / 916 |
| Named ship weapons | 178 |
| Stars / planets (ESM) / bodies (galaxy.csv) / sun presets | 123 / 1,765 / 1,813 / 52 |
| Station NIFs (gen, catwalks, modules, exterior kit) | 758 / 348 / 225 / 60 |
| Asteroid NIFs | 156 |
| Wwise clips / banks / score phrases / diegetic tracks | 26,662 / 18 / 1,060 / 121 |
| English strings | 48,875 |
