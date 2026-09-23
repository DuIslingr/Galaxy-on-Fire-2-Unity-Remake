# Ship assembly: notes (Globals::getShipGroup)

Sources: `Globals::getShipGroup` @0x000f94a4 (_ALL_FUNCTIONS.c ~120747), `AEGeometry::*` @0x000b0d20..0x000b1a86,
`LODManager::addObject/update/forceUpdate` @0x000a03ac..0x000a051c, `Level::createShip` @0x000cf83c,
`PlayerEgo::setShip` @0x000a6088, `CutScene::replacePlayerShip` @0x000a53b4, `ListItemWindow::set` @0x00159468,
`PlayerFixedObject::setWreckedMeshId` @0x0017f318, `PlayerFighter::setExhaustVisible` @0x000f0a60,
`PaintCanvas::MeshCreate(ushort,uint&,bool)` @0x00083cc8, `PaintCanvas::MeshChangeResourceMaterial` @0x00084600,
`loadLowTexturesAndMaterials` @0x0013baec.
Lost float args were recovered with a small Thumb-2 decoder (`scratchpad/thumb.py`, `br.py`; listing in `getShipGroup.dis`).
The ABI is **softfp**: float args travel in r1..r3 / stack, not s0..s2 as Ghidra shows. Generator: `build_ships.py`.

## Parameters

`getShipGroup(int shipIndex, int param_2, bool param_3)`

- **param_2 = race** (0 Terran, 1 Vossk, 2 Nivelian, 3 Midorian). Only the hand-written idx-15 branch reads it, to pick the
  freighter hull: race 0 gives cargo_003_terran, race 3 gives cargo_001_midorian, anything else gives cargo_002_nivelian.
  Callers: `Level::createShip(race, kind, shipIdx, …)` passes its `race` argument, `PlayerEgo::setShip(idx, race)`, and
  `ListItemWindow::set` passes `Ship::getRace`.
- **param_3 = "player / showcase quality"**.
  - `true` is used by `PlayerEgo::setShip` (the player's own ship) and `ListItemWindow::set` (the hangar/shop 3D preview).
  - `false` is used by `Level::createShip` (all NPC fighters and freighters; every call site passes false) and by
    `CutScene::replacePlayerShip`.
  - Effects in the generic path only:
    - true: engine child = `17900+idx` (`*_engine_glow_add`), skipped for idx 0x27/0x29 (no mesh). Default materials (34200+idx
      for ships 0–36). LODs built with `setLodMeshes(ids)`.
    - false: engine child = `18000+idx` (`*_engine_add`). The root mesh and every LOD mesh are created as unique instances and
      switched to material **32200+idx** (`MaterialCreate` + `MeshChangeResourceMaterial`). LODs are built with
      `setLodMeshesWithMeshIds` from those pre-created instances.
- **Material 32200+idx.** These are duplicate ship materials registered by `loadLowTexturesAndMaterials`. They use the
  same shader (28, bump) and the same texture files as 34200+idx, but through separate texture resources 32000/32100+idx
  (the "low" set). They only exist for idx 0–36; for 37+ the lookup fails and `MeshChangeResourceMaterial` returns without
  doing anything.
  - Practical purpose: NPC ships don't share the player's `Material` object. PlayerEgo/PlayerFighter cloaking rewrites
    `material+0x20` (blend mode 0xe) and clones materials.
  - For Unity: visually identical. Use a separate material instance per NPC if you implement cloaking the same way.

## Generic path (every idx except 13, 14, 15)

Assembly order (it matters, see LOD below):

1. Root: `AEGeometry(DAT_00254a90[idx] (u16), unique=true)`. The root mesh lives in the base transform (+0x18).
2. `DAT_00254b10[idx]` (u16), if not 0xFFFF: `MeshCreate(id, unique=true)`, added as a child, and the mesh handle is stored at
   **AEGeometry+0x20**.
3. NPC only: material swap (see above).
4. `DAT_00254b90[idx]` (u16), if not 0xFFFF: a plain shared-mesh child.
5. Engine child (player: 17900+idx; NPC: 18000+idx). This is the **last child** (+0x14).
6. LOD tables `DAT_00254c10` / `DAT_00254f10`: int32, stride 0xC (3 columns per ship), **only the first 2 columns are read**.
   Entries equal to 0xFFFF are skipped.
   - LOD k gets mesh `c10[idx][k]` at distance `5000 + 8000*k` (so 5000 and 13000).
   - If `f10` has entries, `setLodChildMeshes(f10[idx])`.
7. `setLodLastVisibleDistance(80000)`, always called in the generic path (r2:r3 = 0x13880 at 0xf9bc0).

**The +0x20 child (table B).** It's a lights/emissive mesh, just like table C. The only difference is that it's created as a
**unique mesh instance** (`MeshCreate(...,true)` clones the Mesh, so it has its own material pointer and shader-anim values),
and its handle is kept at AEGeometry+0x20.
- I found no reader of AEGeometry+0x20 anywhere in the decompiled code. The only writer is getShipGroup; the constructors
  set it to -1.
- Which ships use B and which use C is per model: Nivelian, Void and Vossk light meshes are in B; Terran, Midorian and pirate
  ones are in C.
- Ships 55–60 have the same `*_lights_add` in both B and C, so it's drawn twice.
- Ship 63 has lights_emissive in B and lights_add in C.
- Treat B and C children identically in Unity (just tag B as "unique").
- The hangar preview uses parallel tables `DAT_00258630`/`DAT_002586b0`, which are mostly root plus B.

**Unused table data:**
- The third LOD column holds ids 17102, 17105, … that don't exist (a LOD_3 that was never used). For ship 9 it duplicates
  lod_2.
- For idx 60–63, `c10` holds **0 instead of 0xFFFF**, so the code builds 2 LOD levels with the nonexistent mesh 0. For idx
  62–63, `f10` also holds 0.
- Ship 42/43 B ids (18742/18743) don't exist.
- NPC engine meshes 18042/18043 and 18055–18063 don't exist (those ships only have engine_glow).
- Some lod meshes exist but aren't referenced: 17240/17241 (042), 17246/17247 (043), 17252/17253 (044).

## Special branches

- **idx 13 (0xD), Vossk freighter.**
  - Root 17013. Children 18713 (lights_emissive) and 17038 (engine_add, last).
  - LOD 17139 @35000 and 17140 @45000. LOD child meshes 17040/17041 are **missing** from resources.
  - Doesn't depend on param_2 or param_3. Root is not unique, no material swap, no last-visible distance.
- **idx 14 (0xE), Terran battleship.**
  - Root 14311. Children 14316 (lights_emissive) and 14315 (lights_add, last).
  - LOD 14312 @35000 and 14313 @60000. LOD child meshes 14316 and 14316.
  - **setScaling(2,2,2)**, recovered: `mov.w r1/r2/r3,#0x40000000` then blx setScaling at 0xf97a4.
  - No engine mesh is attached; `battleship_terran_engine_add.fbx` exists but has no resource id.
- **idx 15 (0xF), freighter by race.**
  - race 0: root 17065.
    - Children 17070 (lights_emissive), 17074 (lights_add), 17069 (engine, last).
    - LOD 17066 @25000 and 17067 @45000, LOD child meshes 17070 and 17070.
  - race 3: root 17049.
    - Child 17055 (lights_emissive).
    - Then **0–3 random containers** (`AERandom::nextInt(4)`), then 17054 (engine, last).
    - Each container i is a transform with 17052 plus a parallel transform with 17053 (container_lod_1). Both get local
      translation (0, 0, z) with **z = -2150, +2150, +4300** for i = 0, 1, 2.
      - Recovered from: `vldr s16,=-2150.0` @0xf95fa (literal @0xf98c0); `adr r0,0xf9c84`; i==1 reads 2150.0 @0xf9c88, i>=2
        reads 4300.0 @0xf9c84; x = y = 0 via r2 = r3 = 0; `MatrixSetTranslation` writes m[3], m[7], m[11] in place.
    - Containers 2 and 3 are children of container 1, so their absolute z is -2150, 0 and +2150.
    - Only the 17052 chain is `addChild`-ed to the root. The 17053 chain is attached to every LOD transform with
      `setLodChildTransform` (with -1 when there are no containers).
    - The first container transform gets `Transform+0xe0 = 100000.0`. That field is the bounding-sphere radius used by
      `Transform::InCameraVF`, so this prevents frustum culling.
    - LOD: 17050 @35000 (one level).
  - race other (1, 2): root 17060.
    - Children 17061 (lights_add) and 17064 (engine, last).
    - LOD 17062 @35000 and 17063 @60000. No LOD child meshes.
- The generic table rows for idx 13–15 are dead data; ids 17014 and 17015 don't exist.

## LOD semantics (AEGeometry)

- `setLodMeshes` / `setLodMeshesWithMeshIds(ids, dist, n)`:
  - For each level it creates a **separate transform** holding the LOD mesh, and stores `dist²` as u64 (+0x64).
  - It re-parents the **current last child (+0x14)** under each LOD transform, as well as the base transform. (Transforms can
    have several parents; the base transform keeps it.)
  - +0x50 = number of levels; +0x54 = the LOD transforms.
- `setLodChildMeshes(ids[n])`: for level i it creates a transform with mesh `ids[i]` under LOD transform i, then removes and
  re-adds the last child so that it stays last.
- `setLodChildTransform(t)`: adds transform `t` (a whole sub-hierarchy) under every LOD transform.
- **What a level shows:**
  - Level 0 (base, +0x18): the root mesh plus **all** children.
  - Level k >= 1: **only** the LOD mesh, plus the LOD child mesh / child transform, plus the last child (normally the engine).
  - All other children (lights in B/C, lights_emissive…) are dropped unless the LOD child table re-adds them.
- `updateLod(camPos, detail)`, called by `LODManager::forceUpdate` every 1000 ms:
  - `distSq` = |object - camera|². It uses the parent transform +0x24 if set (KIPlayer puts the ship group under a parent).
  - Factor = 1.0 if detail > 0.66, 0.75 if detail > 0.33, otherwise 0.5.
  - It picks the highest i with `distSq > factor * lodDist[i]²`, i.e. switches when `d > lodDist*sqrt(factor)`. If none
    match, it uses the base transform.
  - Switching swaps which transform is `+0xc` (the rendered transform); the matrix is copied across and the animation time
    is synced.
  - **Caveat: in this binary the level loop starts with `mov.w r5,#0` @0xb1962** instead of loading the level count, so the
    loop never runs and the **base (full-detail) transform is always used**.
    - The following `add r4,r1,r5,lsl#3` still computes an offset from r5, which a compiler would have constant-folded.
    - So this looks like a patch (the HD/"Price" mod build forcing full detail). The original instruction was probably
      `ldr.w r5,[r11,#0x50]`.
    - The intended semantics are the ones described above.
- `LODManager::addObject` only registers geometries with `hasLod()` (+0x54 != 0).
  - Ships without LOD meshes (37, 38, 40, 42–59) are never LOD-updated, so their last-visible distance never takes effect.
  - Ships 60–63 have `hasLod` = true because of the 0 entries.
  - The player ship is never added. NPCs are added unless level type 1 or 0x17.

## Last-visible distance

- `setLodLastVisibleDistance(u64 d)` stores `d²` at +0x70.
- In `updateLod`, if it's non-zero and `distSq >= d²`, then `visible (+0x48) = false` and `+0x28 = -1`, i.e. the object is
  **hidden entirely** (root and all children).
- Generic ships use d = 80000 game units (4 km in Unity at 0.05 m per unit). Special ships 13, 14, 15 never call it (0 means
  never hidden).
- This check is still active in this binary; it runs before the patched loop.

## Other ship-related attachments

- **Freighters** (`Level::createShip` with kind == 1, i.e. PlayerFixedObject):
  - `setWreckedMeshId` builds a separate AEGeometry with the explosion_anim mesh, chosen by **race**:
    - race 0: 18302 (ship 14: 18304)
    - race 1: 18303
    - race 2: 18301
    - race 3: 18300
  - The wreck transform radius is set to 500000.0.
  - Wreck collision index from `getWreckCollision`: idx 13 gives 4, 14 gives 0, 15 gives race 3→1 / race 2→2 / other→3,
    0x37a3 gives 5.
  - Bounding boxes (3/11/5/3/2 per race) are built from floats Ghidra lost; I didn't recover them.
- **Fighters:** no per-ship wreck. `PlayerFighter` uses `Explosion(0)`, which is root 16821 (explosion_anim_lookat_alpha) plus
  child 16820 (explosion_anim_lookat_add), plus fire streaks.
- **Exhaust / cloak:**
  - `PlayerFighter::setExhaustVisible` toggles the geometry's last child (+0x14), i.e. the engine mesh.
  - PlayerEgo cloaking sets the colour of children +0x10 and +0x14 and hides +0x14.
  - The player also has engine particle systems (ParticleSystemManager systems 9/0xf/0x2a at the ship matrix), an optional
    emergency-system mesh 14374 (item-based) and turrets (`CutScene::checkForTurret`, item-based). None of these are part of
    the ship group.
- Coordinates in the JSON are game units in engine space. Convert with `(x, y, -z) * 0.05` for Unity.
