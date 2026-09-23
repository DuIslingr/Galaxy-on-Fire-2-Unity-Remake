# Non-flight scene assemblies: notes

Outputs are in this scratchpad folder:
- `assemblies_scenes.json`: 77 entries, all positions in game units. Built by `scn_build_assemblies.py`, which reads the tables straight from `libgof2hdaa.so` through `gof2bin`.
- `name_groups.json`: 221 name groups with 955 members. Built by `scn_name_groups.py`.
- Helpers: `scn_dis.py` (a Thumb disassembler, a copy of `armdis.py`) and the disassembly dumps `scn_*.s`.

## Which code builds each scene

| Scene | Built by | Level mode |
|---|---|---|
| Hangar | `ModStation::OnInitialize` -> `CutScene(0x17)` -> `Level(0x17)` -> `Level::createScene` @0xc2910 (branch 0x17) | 0x17 |
| Hangar turret on player ship | `CutScene::checkForTurret` @0xa4594 (also called from ModStation when equipment changes) | - |
| Bar | `SpaceLounge` -> `CutScene(4)` -> `Level::createScene` (branch 4), plus the extra props in `CutScene::initialize` @0xa4074 | 4 |
| Main menu background | `ModMainMenu` / `ModStation` (on undock) -> `CutScene(2)`. This is a normal space level at a random station, so it isn't a separate asset set. In campaign mission 0x2b, `createScene` mode 2 also adds `beer` (0x37d0) and `bra` (0x37d1) statics at (0,0,0). | 2 |
| Galaxy map | `StarMap::StarMap` (galaxy view), `StarMap::init` (background), `StarMap::initStarSystem` (system view) | - |
| Shop ship preview | `ListItemWindow` (tables `DAT_00258630` main mesh and `DAT_002586b0` lights mesh, per ship index) | - |

`SpaceLounge`, `HangarWindow`, `ModStation` and `MTitle` create no meshes of their own. There's no separate intro or cutscene mesh set: "CutScene" is only the wrapper for these three Level modes.

## Rules I recovered (from the disassembly where Ghidra lost the float arguments)

### Placement and animation
- `PlayerStatic(-1, geom, x, y, z)`: x goes in `r3`, and y and z are on the stack.
  - Hangar and bar statics are all at (0,0,0).
  - Hangar statics get `setRotation(0, pi, 0)`. Bar statics get no rotation.
- Animation: every geometry in the Level's enemies list gets `Transform::Update(dt)` every frame in `CutScene::process`. So the `*_anim*` room meshes loop without an explicit animation state.
- The animation state values (from usage):
  - `SetAnimationState(3,0)` followed by `SetAnimationState(1,0)` restarts a one-shot.
  - State 2 is used for the looping galaxy-map wormhole.

### Hangar
- Room meshes: `UNK_00253e48[raceIdx][4]`.
  - `raceIdx` is the system race 0..3. Station 100 uses 7 (deep science) and station 101 uses 8 (battlestation).
- Child props: ids `DAT_00251fd0[race] + k` for `k < UNK_00251fc0[race]`. This only applies to races 0, 2 and 3.
  - The loop adds these props to each static (room, add and alpha), so the original draws them up to 3 times.
- Player ship: placed at (0, `DAT_00253d48[shipIndex]`, 0).
- Parked ships:
  - Count is `nextInt(UNK_00253ee8[race] + 1)`.
  - Slot tables:

    | Race | Table |
    |---|---|
    | 0 | `UNK_00253f10` |
    | 1 | `DAT_00253f28` |
    | 2 | `DAT_00253fe8` |
    | 3 | `DAT_00253f94` |
    | 7 | `UNK_00253fc4` |
    | 8 | `DAT_00253fb8` |

  - The ship's `DAT_00253d48` y offset is added to the slot's y.
  - Each ship is rotated about Y by `nextInt(300)/100` rad.
- Camera tables (use not verified): `DAT_002546c4`, and `DAT_0025464c` on iPad.

### Hangar turret
- The base and the gun are both placed at `loadWeaponPositions(ship)[2][0]`.
- The gun is then translated by a per-item offset: 60, 55, 60, 84, 88, 88, 80, 38, 75 or 82 in y, plus x/z for items 0xb5 and 0xb6.
- The base and gun are rotated by pi, except for the plasma collectors (items 0xc6..0xc8).

### Bar
- Room meshes: `DAT_00254150[race][3]` (Vossk has only 2).
- Visitors: one per Station agent, in a random free slot out of 7 from `UNK_00254000[race]`.
  - Visitor mesh: `DAT_00254380[agentRace]`; female Terran uses 0x3984.
  - Glow: `0x37c9 + barRace` (`DAT_00251fe0`), at the same position as the visitor.
  - Shadow: 0x380c, at y + 20.
- Terran bar: adds `bar_terran_bot_anim` with `_add` as a child (continuously animated).
- Midorian bar: adds `bar_midorian_alpha_anim` as a one-shot (30% chance every 2 s).
- Vossk bar: fog is set to 5000 in `CutScene::resetCamera` and `process`.

### Galaxy map
- Background: the bg plane and two fog layers are all at (-3000, -2500, 0) with rotation (0, pi, 0).
- Suns: mesh `18070 + texIdx` (all `plane.fbx`), scale 0.012.
  - Position: x = `int((100-X)*140)-10000`, y = `int((100-Y)*130)-9000`, z = `int((100-Z)*60)+1000`.
- Planets: mesh `18180 + stationTexIdx`, scale `DAT_00254484[tex]*16/65536`.
  - Planets are placed on circles about Y. Radius starts at 6400; each step adds `1600 + rand(5600)`.
- Ring: mesh 0x41d5, copied onto the planet's matrix.
  - Always for texture indices 9, 16 and 21 (bitmask 0x210200); otherwise only if `orbitHasPlanetRing`.
- Orbit: mesh 0x1a7b, scale `2r/65536`.
- System container: scale 1/128, rotation (-pi/8, pi/8, -pi/32).

## Uncertainties and anomalies
1. **Axis convention for rotations and `translate`.** I assumed `setRotation(x,y,z)` takes Euler radians in that order, and that `translate()` works in the parent/unrotated frame. The gun offset is applied before the gun's own rotation.
2. **Shadow at y + 20.** It's odd for a shadow to sit above the visitor, but that is what the code does (`vadd s20, s20, #20`). It may depend on where the mesh pivot is.
3. **`hangar_midorian`.** Ids 14401/14402 duplicate x5 in `resources.json`. The x6 FBX files have no id. It could be a bug in the original table or in the emulated resource list, so check `BuildResourceList_DISASSEMBLY.txt` if it matters.
4. **Unused meshes.** No code creates:
   - `hangar_terran_bot_a..d_anim(+_add)` or `hangar_nivelian_bot_a..c`. `CutScene+0x38` is never filled; `process` would animate them with a 20% chance every 3 s.
   - The `bar_vossk_bot_*` and `bar_vossk_alpha` FBX files. They also have no resource ids.
   - `map_sun_*`, `sn_map_sun_011`, and `main/map_planet_020..022`. Ids 18200..18202 point to the `v_map_planet` versions instead.
5. **Battlestation hangar index.** `CutScene::process` uses index 10 for station 101, while `createScene` uses 8. It only affects the process branch, which then updates nothing extra.
6. **Camera table.** Its meaning (hangar vs. bar, camera vs. look-at) isn't verified.
7. **`bar_visitor_glow`.** It has 4 resource ids for the same FBX (one material per bar race).
8. **Shop preview.** Only the lights mesh is added, never engine or glow meshes. Ships 42/43 point to ids 18742/18743, and ships 50/53 to 17287/17305; none of these ids are in `resources.json`.

## Name grouping (`name_groups.json`)
- **Layer tokens:** `add alpha emissive lookat anim lights engine glow shadow`, plus `lod_N` (`lod_N` may also appear mid-name, for example `..._lod_1_part1`). Removing these gives the "layer group": one object drawn with one transform.
- **Families:** a layer group whose base is `<existing base>_<extra>` (at least 2 tokens) becomes a subpart of that base. Examples: `_gun`, `_x1`, `_bot_a`, `_explosion`, `_damaged`, `_container`, `_jump`, `_laser`, `_emitters`, `_fire`, `_turret`, `_shield`. `<x>_partN` and `<x>_N` siblings get a virtual root.
- **Ambiguous cases** (listed in `ambiguous`):
  - `bar_visitor` (`_glow` and `_shadow` are standalone meshes).
  - `bar_midorian` (no plain main mesh).
  - `hangar_midorian` (the x5/x6 issue).
  - `map_planet` and `map_sun` (not groups).
  - `plane.fbx` (many ids share it).
  - `lens_flare_N`, `map_fog_layer_N`, `sn_carrier_terran_1..3`.
  - Explosion families: 1-token bases are not merged.
- `modelsWithSeveralIds` lists FBX files that are referenced by more than one id.
- The `subpartLegend` field says which subparts are permanent children (layers, lods, gun, x-props) and which are alternate-state objects (explosion, wrecked, damaged, fire, jump).
