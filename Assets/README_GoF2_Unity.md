# GoF2 assets for Unity

Everything from the Galaxy on Fire 2 Full HD mod (game version 2.0.16, release `GOF2FHD09142026`), converted into formats Unity imports natively.

**Keep this private.** It's Deep Silver's copyrighted art, audio and text. It's fine for a personal build; don't publish it.

## Import it

1. Create a Unity project (Unity 2021 LTS or newer; Built-in or URP both work).
2. Unzip every `GoF2_Unity_*.zip` into the project's `Assets/` folder. They all merge into `Assets/`.
3. Let Unity import everything. The first import takes a while (about 1,100 models and 1,300 textures). The included `GoF2AssetPostprocessor` automatically applies these import settings:
   - scale = 0.05 m per game unit
   - normal maps flagged as normal maps
   - cubemaps imported as cubemaps
   - UI art imported as sprites
   - music streamed from disk
4. Menu **GoF2 → Build Materials And Prefabs**. This creates one material per game material and one prefab per game mesh, wired exactly as the original game does.
5. Menu **GoF2 → Create Flight Test Scene**, then press Play. WASD/arrows steer, Q/E change throttle, Space boosts, R levels the ship.

## What's inside

| Folder | Contents | Count |
|---|---|---|
| `Models/` | Every `.aem` mesh converted to `.fbx`. Includes UVs, the original normals, vertex colours and the part hierarchy. Each has a `.gof2mesh.json` sidecar holding pivots, bounding spheres and the original keyframes. | 1,125 of 1,125 |
| `Textures/` | Every `.aei` texture as `.png` (ETC1 and RGBA decoded). `*_metallic_smoothness.png` files are generated from the specular alpha channel for the Standard/URP Lit shaders. `_texture_manifest.json` lists the sprite regions for the UI sheets. | 1,145 of 1,145 (+136 generated) |
| `Audio/` | All 22 FMOD banks extracted to `.ogg` with their original names, one folder per bank (English and German voices). | 4,416 of 4,416 |
| `Resources/GoF2Data/` | All game data as JSON. Details below. | 51 of 51 `.bin` files |
| `Localization/` | All 11 languages as `text_<lang>.json`, plus `GoF2_strings.csv` with one row per string and a column per language (usable with Unity Localization's CSV import). Arabic has 3,291 strings; the other languages have 3,401. | 11 |
| `Shaders/` | Small unlit/additive/alpha shaders that work in both Built-in and URP. | 4 |
| `Shaders_Original_GLSL/` | The game's own GLSL shaders, as reference text. | 23 |
| `Scripts/` | Flight model, ship controller, chase camera, data loader, keyframe player (runtime) and the importer/prefab builder (editor). | |

## Game data (`Resources/GoF2Data`)

- **Economy and universe:** `ships`, `items` (stats, prices, blueprints), `systems`, `stations`.
- **Characters:**
  - `agents`: bar characters, including what they sell and their portrait parts
  - `wanted`: bounty targets, including ship, weapon, HP, loot and reward
  - `names`: generated pilot names per race
  - `ticker`: news ticker entries
- **Placement:**
  - `weapons_hd`: gun mount points per ship
  - `docks_hd`: docking and spawn points per station
  - `shipparts` / `stationparts`: part placements per ship/station (most likely engine flames, lights and turrets)
  - the collision tables
  - the DLC variants (`sn_*`, `v_*`)
- **`resources.json`:** the game's complete resource table: 1,080 meshes, 558 materials and 709 textures, all with their original IDs. It was recovered by running the game's own `BuildResourceList()` routine in an ARM emulator, because that function is too large for Ghidra to decompile. It tells you which texture and shader each mesh uses, and the IDs match what the decompiled code refers to.

Every `.bin` decoded with 0 bytes left over (see `_bin_decode_report.json`).

## Coordinates and scale

- Game coordinates to Unity: `(x, y, z)` becomes `(x, y, -z)`, times 0.05. Ships face +Z in Unity.
- Positions in the data files (`weapons_hd`, `docks_hd`) are provided both as stored (`position_file`) and converted to game space (`position_engine`). Apply the rule above to get Unity space.
- Keyframe times are in milliseconds. Rotations are in radians.

## Known limits

- **Keyframe animation** (`GoF2PartAnimation`) is on for `_anim` models by default. The position axis mapping is confirmed; the rotation axis mapping isn't, so it's editable in the inspector. The `extra` channel (0–100) looks like opacity, and the `v5_*` channels look like UV/colour effects. Neither is applied yet.
- **Sound IDs:** the game plays sounds by FMOD event ID. The event file (`Audio/_FMOD_GOF2.fev.bytes`) isn't parsed yet, so ID-to-sample mapping is still to do. The sample names are descriptive (e.g. `Autopilot_Activate_01`).
- **Missing files:** 13 meshes/textures referenced by the code aren't shipped in the OBB (dev leftovers such as `test_dock`, `carrier`).
- **Material look:** the original's rim/cube/glow shader effects are approximated with Standard/URP Lit plus the simple additive/alpha shaders.
