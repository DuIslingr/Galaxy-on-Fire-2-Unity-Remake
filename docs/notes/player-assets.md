# Player-provided assets

The remake built so it ships **without any of Galaxy on Fire 2's own assets**: the player gives the game their own copy
of GoF2 at first start and the game converts it (the user's decision, 2026-11-15). Work on branch `player-assets` (fork
first, proposed upstream once complete); the current `Resources` path keeps working until the new one replaces it.

## Decisions (2026-11-15)

- **Sources:** Android HD (APK + content OBB, `GOF2CONTENT_ETC`) and iOS HD (the .ipa; 1.1.19 checked) now; the macOS
  "Full HD" release later (the user will provide its files; formats not yet looked at).
- **The conversion runs inside the game**, on every platform including phones: C# ports of
  `Reference/tools/asset_conversion` (no Python or Blender on the player's machine).
- **Derived assets** (made from the originals by the remake's tools) can't ship either. The cheap ones are made on the
  player's machine after the conversion (3D planets, sky layers, reflections, the assembled prefabs); the Real-ESRGAN sky
  upscales are an **optional desktop step** ("enhance"), without it the original skies (Settings.SkyStyle Enhanced /
  Combined then use the original images).
- **What the player's copy can't provide is set aside, distributed separately, not on GitHub** (the user, 2026-11-15):
  every file whose converted form the converter doesn't reproduce exactly (KiritoJPK's "Higher quality textures and
  metallic maps", 2026-10-07; the remake's resized or edited images; derived assets that can't be made on the player's
  machine, such as the Real-ESRGAN upscales) goes into a **supplement pack**: a download of its own, installed beside the
  converted cache, layered over it. The list comes from the importers' exact comparisons against the project's files,
  not from rules.
  - **Per source:** what one edition has and another lacks goes into that edition's own gap pack (the user,
  2026-11-15): a player with the iOS or macOS copy gets the Android-only assets that way, and the reverse. So the packs
  are a common one (nothing provides it) plus one per edition (what that edition lacks). Found so far (file names,
  2026-11-15): iOS lacks 21 Supernova `.bin` (docking points, ship weapon mounts), `ar.lang`, the Vossk 063 textures
  (named `..._prototype` on iOS: an alias to map, not necessarily a gap), two hangar bot animations and the iPad 1440
  interface images; Android lacks the German voice banks and `zs` / `zt.lang`, and ~90 meshes / 27 textures iOS keeps at
  other paths (asteroid fields, explosions: to map before calling them gaps).
  - **Lower-resolution copies** (the user, 2026-11-15): iOS 1.1.19's PVRTC textures are 1/2 (359), 1/4 (47) or 1/8 (9)
  of Android's resolution. An iOS player's game runs from the iOS copy's own textures; Android's full-resolution versions
  are an optional "HD textures" part of the iOS gap pack. The same rule for any edition: what it has at lower quality is
  an optional upgrade, what it lacks entirely is required.
  - The mapping is per project asset: its source entry in each edition (aliases included) and whether that edition's
  conversion reproduces it; `Reference/tools/player_assets` gets that table, and the packs are made from it.
- Not decided here: `Reference/binaries` (the Android APK, `libgof2hdaa.so`, `libfmodevent.so`, default economy .bin) and
  `Reference/decompiled` are in the repository too; whether they stay is upstream's call. They aren't part of a build.

## Inventory (`Reference/tools/player_assets/inventory.py`, output `Reference/player_assets/inventory.json`)

Per folder, by path rule, checked against the iOS 1.1.19 app (2026-11-15):

| Kind | Folders | Files | Source in the player's copy |
| --- | --- | --- | --- |
| original | `Textures/` | 1,262 | AEI; 1,115 named as a file in the app (the rest: the remake's generated `_metallic_smoothness` maps, derived) |
| original | `Models/` (.fbx + .gof2mesh.json) | 2,255 | AEM; 1,124 of 1,127 meshes named as in the app |
| original | `Audio/` | 4,417 | FSB banks: all 22 banks' sample counts equal the folders' file counts |
| original | `Skyboxes/`, `Resources/GoF2Sky`, `GoF2Backdrop`, `GoF2Station` | 198 | AEI (cubemap strips, sun / planet images) |
| original | `Resources/GoF2Icons`, `GoF2Hud`, `GoF2Races`, `UI/Original`, `Sprite Assets/gof2_text_icons` | 672 | regions of the interface AEI atlases (AEI region tables) |
| original | `UI/AppIcon`, `UI/MainMenu/card_*` | ~25 | the app's logo / key art: to be replaced by the remake's own, not converted |
| original | `Localization/text_*`, `GoF2_strings.csv` | 15 | `.lang` files (the remake's own translations nl / hi / zh / ar...: see below) |
| original | `Resources/GoF2Data/` | 53 | `.bin` files and the resource table (per file to sort out: some tables are the remake's) |
| original | `Shaders_Original_GLSL/` | 23 | the app's shader source; reference only, nothing converts it |
| derived | `Resources/Assembled/`, `Prefabs/`, `Materials/`, `GoF2Weapons/item_*` | 2,030 | built at run time from the converted meshes, textures and `assemblies.json` / `resources.json` |
| derived | `Resources/GoF2SkyHd`, `GoF2SkyLayers`, `GoF2Planets3D`, `GoF2Reflections` | 257 | made on the player's machine (SkyHd: the optional step) |
| own | everything else (scripts, shaders, settings, fonts, `GoF2Mods`, `GoF2Localization` extras...) | ~1,400 | ships |

**Hard references** (an own asset pointing at an original or derived one by GUID; these can't stay): 19 files.
- Sound tables: `GoF2Story/StoryAssets` (4,307 clips), `GoF2ModBuilder/GameAudioIndex` (330), `GoF2Combat/CombatAssets`
  (120), `GoF2Events/EventAudio`, `GoF2Story/SupernovaAssets`, `GoF2Weapons/CombatAudio`, `GoF2StarMap/StarMapAssets`,
  `GoF2Music/MenuTheme`; the Station (69 clips) and MainMenu (31) scenes. All name lookups: the content layer serves a clip
  by its bank and name.
- `GoF2LanguageTables` (the 14 text tables), `GoF2Mods/ModAssets` (3 materials), the Space scene's `SpaceSky.mat`.
- The six build profiles' app icons (`UI/AppIcon`): the remake needs its own icon.

**`Resources.Load`:** 161 calls in 102 files; those loading originals go through the content layer.

## Formats in the player's copy

- **iOS HD 1.1.19** (`Payload/Galaxy on Fire 2 HD.app/`, data files not encrypted; only the executable is, FairPlay):
  `data/textures`, `data/meshes`, `data/assets/{main,supernova,valkyrie}/...` (1,215 .aem, 1,163 .aei), `data/bin` (30
  .bin), 12 `.lang`, 22 FSB5 banks + one .fev, `data/shader` (.vert / .frag).
  - AEI types: 0x01 RGBA8 (702), 0x03 RGBA8 + alpha (2), 0x81 RGBA8 cubemap strip (23), and PVRTC: 0x10 (126), 0x12
    (307), 0x0d (2), 0x24 (1). `aei.py` reads only the RGBA8 and ETC1 types: PVRTC 2 / 4 bpp needs a decoder.
  - FSB5 codecs: MPEG (4,121 samples: voices, music), IMA ADPCM (291: effects), PCM16 (4). No Vorbis (no setup-header
    rebuilding); MP3 needs a managed decoder (or Unity's own where the platform has one), IMA ADPCM is a few lines.
- **Android HD 2.0.16** (`net.fishlabs.gof2hdallandroid2012`; checked from the user's XAPK, 2026-11-15): the APK holds the
  code only; the content is the OBB `main.47947006.net.fishlabs.gof2hdallandroid2012.obb`, a zip (2,466 entries) of
  `47947_GOF2CONTENT_ETC/assets/...`: 1,145 .aei, 1,127 .aem, 51 .bin, 11 .lang, 17 FSB5 banks + .fev, the shaders.
  - AEI types: 0x01 (684) and 0x03 (258) RGBA8, 0x81 cubemap strips (23), 0x42 ETC1 with mips (180): all read by `aei.py`.
  - FSB5: the same codecs as iOS (MPEG, IMA ADPCM, PCM16).
  - An XAPK is a zip holding the APK and `Android/obb/<package>/main.*.obb`: the converter takes the XAPK, the OBB or a
    folder holding either.
- **What each copy has** (against the project's 22 banks, 2026-11-15): Android has no German voices (`VOICE_deu`,
  `DLC_VOICE_deu`, `DLC2_VOICE_deu`, `GENERIC_deu`, `LOUNGE_deu`) and no Chinese text; iOS has no Arabic text (`ar.lang`)
  but both Chinese tables (`zs`, `zt`). Every other bank has the same samples in both. The converter takes either or both
  (layered); without German voices the game falls back to the English ones.

## Importers so far

- **AeiImage** (`Scripts/Runtime/Core/Content/AeiImage.cs`, GoF2.Core, plain C#; 2026-11-15): the header and regions,
  RGBA8 / cubemap strips, ETC1, PVRTC 4 and 2 bpp, level 0 only. Checked outside Unity (a console harness on the
  Editor's own .NET SDK): Android 2.0.16's 1,145 textures, 0 failures, byte-identical to the project's original
  conversion wherever the remake didn't edit a texture later (438 of 447 against the files before KiritoJPK's 2026-10-07
  update; the 9 others and 12 resized are the remake's edits: the Vossk hangar and stations, the suns); iOS 1.1.19's 435
  PVRTC textures byte-identical to texture2ddecoder. The words' Morton order puts y in the even bits (x there decoded each
  image mirrored about its diagonal). Type 0x24 (iOS' unused cloak map) isn't read.
- **AemMesh** (`Scripts/Runtime/Core/Content/AemMesh.cs`, 2026-11-15): parts, geometry, keyframes and the
  `.gof2mesh.json` sidecar (convert_remodel.py's format, what PartAnimation reads). Android's 1,127 and iOS' 1,215 meshes
  read with geometry identical to aem.py's (one iOS file ends inside its last part, as the game's own may: dropped as
  aem.py drops it; `v_ship_040_deep_science` carries 12 NaN UVs in both copies). The sidecars equal the project's for
  1,093 of 1,126; the other 33 are the remake's remodels (the contributed Midorian hangar room 2026-10-07, the Vossk /
  Nivelian hangars, the remade Vossk bar 2026-10-25, a few Supernova / Valkyrie add meshes): common-pack material.
  Still to do: the Unity mesh itself, in the space the FBX import gives (aem2fbx's axes, Blender's validate, Unity's
  x flip and ModelOrientationPostprocessor's 180 deg).
- **FsbBank** (`Scripts/Runtime/Core/Content/FsbBank.cs`, 2026-11-15): FSB5 banks, each sample as a file ModAudio loads:
  MPEG as its own frames (`.mp3`, the bank's zero padding between frames dropped: lossless), IMA ADPCM decoded to a 16-bit
  `.wav` (Xbox IMA: per channel and 0x24-byte block the header's sample, then the first 63 nibbles; the 64th is never
  played), PCM16 as a `.wav` trimmed to the sample count (its data is padded). Checked on the user's copies: 4,416 iOS and
  2,373 Android samples, every name one of the project's audio files; the 224 IMA / PCM samples sample-identical to
  vgmstream's decode, the MPEG ones the same length and within 2 LSB of vgmstream's (mpg123 vs ffmpeg rounding, 73 dB+).
- **LangFile** (`Scripts/Runtime/Core/Content/LangFile.cs`, 2026-11-15): the `.lang` text tables (big-endian u16 length +
  UTF-8, string after string) to text_<lang>.json (gb -> en, ptl -> pt, zs -> zh, zt -> zh-Hant). Android's tables equal
  the project's except the remake's corrections (3,392-3,399 of 3,401 a language: "Rockets", "S'kolptorr", "your next
  target", lowercase gods, 2026-11-01) and Arabic (Android's `ar.lang` is an older 3,291-string table; the project's was
  realigned and completed, #224, 2026-11-03 / 05). iOS' tables have 3,402 strings and wording of its own (English 3,281
  the same, Portuguese 2,961, Chinese: the original's `zs` vs the remake's PR #50 table 2,124). The corrections, the
  remake's own translations (ar, nl, hi, zh) and an edition's differing strings are string overlays in the packs.
  - iOS' `v_galaxymap_planets` has no alpha (Android's ring quadrant is translucent): a real difference between the
  copies, so that texture is in the iOS gap pack.

- **GameTables** (`Scripts/Runtime/Core/Content/GameTables.cs`, 2026-11-15): the data tables from the copy's .bin files and
  English .lang (ports of parse_bins.py, parse.py + export.py with items.json's statList / `"blueprint": []`, and
  build_item_attributes.py), values written in the scripts' key order (JsonObj, TableJson). Android: 40 tables, 39 equal
  to the project's by value, items.json differing only by the remake's text fix (so the string overlay goes on the
  English table before the tables are built); iOS: 19 tables, 15 equal, the other 4 (items, item_attributes, ships,
  weapons_hd) its Default Economy's numbers, as traced.

## The packs (`Reference/tools/player_assets/packs.py` -> `Reference/player_assets/packs.json`, 2026-11-15)

From the converter's own output for each edition (`Reference/tools/player_assets/convert`), against the project's files:
exact / lower (the same picture at a lower resolution, or the same size encoded worse, 30 dB+) / differs / missing. Per
edition an asset is required (missing or differs) or optional (lower: the edition's version works, the project's is an
upgrade). First run (Android 2.0.16 XAPK, iOS 1.1.19 ipa):

| | Android | iOS |
| --- | --- | --- |
| exact | 4,165 | 5,993 |
| lower | 369 | 399 |
| differs | 87 | 261 |
| missing | 2,047 | 15 |

- **Common pack:** required 58 (the remake's remodelled meshes, edited textures, `sn_sun_012`, `hangar_terran_alpha_diffuse`
  and the like: in no copy as the project has them); **optional 388** (KiritoJPK's 2026-10-07 textures: upscales and
  cleaner encodes of pictures both copies have, an "HD textures" pack; perhaps the macOS Full HD release's own, to check
  when its files come).
- **Android's gap:** 2,076, nearly all the five German voice banks (2,043 samples). **iOS' gap:** 218: Android's versions
  of hangar meshes iOS 1.1.19 has in other versions (143 main-game sidecars differ: vertex counts, keyframes), the
  interface images it lacks, 17 more optional upgrades.
- **Text:** a string overlay per language of the remake's corrections and translations (see LangFile); iOS' own wording
  where it differs (English 120 strings, Portuguese 440, French 33).

## Data tables (`Resources/GoF2Data`, traced 2026-11-15 by re-running the generators on both copies)

- **42 rebuild from the player's .bin / .lang** byte-identical (`parse_bins.py`: agents, wanted, names, ticker, collisions,
  docks, weapons_hd / sd, the `sn_*` / `v_*` tables; `parse.py` + `export.py`: ships, systems, stations, items (plus 3 text
  fixes: an overlay)); `item_attributes`, `economy_default`, `weapons_hd_default` from those.
  - The economies differ per copy: iOS' `items.bin` / `ships.bin` / `weapons_hd.bin` are the Default Economy's (byte-
    identical to `Reference/binaries/default_economy`), Android's the main one; so each edition's gap carries the other
    economy's numbers. The 21 `.bin` iOS lacks aren't read at run time.
- **No original bytes, recovered facts:** `resources.json` (the resource table, from emulating Android's
  `BuildResourceList` + disassembly IDs + the remake's additions), `assemblies.json` (the remake's composition rules),
  `story.json` and `voice_table` (IDs and FMOD event names from the .so); weapon_fx (a hand table). Not rebuildable from
  an iOS copy (its executable is encrypted). **They ship with the game** (the user, 2026-11-15: facts, no art, text or
  code of the original's, and every edition needs them).
- **The remake's own:** step_summaries, hangar_heights, nozzle_shapes, void_station_extra, generated_lods (derived from
  the meshes: rebuildable on the player's machine with the run-time simplifier). `_bin_decode_report`: unused, drop.

## The content layer: what has to run in the game (mapped 2026-11-15)

The originals reach the game two ways: loaded as they are (textures, clips, text, data), and through **editor builders**
that make Resources folders from them. Each builder becomes a run-time step over the converted cache:

| Builder (editor-tools.md) | Makes | Run-time replacement |
| --- | --- | --- |
| Materials And Prefabs (`PrefabBuilder`) | `Materials/`, `Prefabs/` (a material per game material, a prefab per mesh, from resources.json) | meshes from the cache's .aem in the FBX import's space, materials by shading kind |
| Assembled Prefabs (`AssemblyBuilder`) | `Resources/Assembled/` (319) from assemblies.json | templates built on first use, as ModShips.Template does for mods |
| HUD Images, Item Icons, Hull Icons, Text Icons | `GoF2Hud`, `GoF2Icons`, `GoF2Races`, `Sprite Assets/gof2_text_icons` | cut from the interface atlases (AEI regions) after the conversion |
| Space Skies, Sky Layers, the skyboxes | `GoF2Sky`, `GoF2Backdrop` sky materials, `Skyboxes/` | cubemaps from the cubemap strips |
| Combat / Star Map / Event Audio, the story's | `CombatAssets`, `StarMapAssets`, `EventAudio`, `StoryAssets` (4,307 clips)... | clips by bank and name from the cache |
| Hangar Shadows, reflections, 3D planets, generated LODs | `GoF2Station/ShipShadows`, `GoF2Reflections`, `GoF2Planets3D`, `generated_lods` | made after the conversion (cheap) |

Testing it needs a Unity project without the originals: this branch's worktree with the original and derived folders
left out (sparse checkout) is exactly a shipped build's content, a fast import, and the cache supplies the rest.
- **The test bed** (2026-11-15): a worktree (`git worktree add`, `GIT_LFS_SKIP_SMUDGE=1`) with a non-cone sparse checkout
  made from the inventory (every original / derived file and its .meta left out: 17 whole folders, 427 single files);
  1,470 asset files, 53 MB. **Don't run a plain `git lfs pull` there:** git-lfs writes every LFS file into the working
  tree, the sparse ones too; remove them and `git sparse-checkout reapply` if it happens (or pull with `--include`).

## Content layer so far

- **GameContent** (`Scripts/Runtime/Core/GameContent.cs`, 2026-11-15): the converted cache (`GamePaths.Data/Original`, its
  `_manifest.tsv` marks it installed) first, Resources as the fallback: `Text` / `Bytes` (a table by its Resources path),
  `LanguageText` (text_<code>.json). The data tables (Database, CollisionVolume, Agent, GenericVoice, NewsTicker,
  SpacePoints, StepSummaries, StoryTable, GameLods, the Mod Builder's voice list) and Localization's tables read through it
  (Localization takes the cache's language without a table asset). `PlayerCopyTests` (EditMode, ignored without a
  converted copy: `$GOF2_ORIGINAL_CACHE` or the tools' cache_android) pass in the test bed: the database and the text from
  the player's Android copy with no original in the project.
- **OriginalModels** (`Scripts/Runtime/Space/Content/OriginalModels.cs`, 2026-11-15): OriginalTextures (a cache PNG as the
  importer set it up; the game's normal maps, specular in alpha, rewritten (1, G, B, R) so URP reads X right on desktop and
  Android), OriginalMaterials (PrefabBuilder.CreateMaterial + PostProcessing.ApplyGlow), OriginalModels (a model from the
  cache's .aem as its per-mesh prefab: parts, PartAnimation from the sidecar as a run-time TextAsset, ResourceInfo) and
  OriginalAssemblies (AssemblyBuilder: templates kept under an inactive holder); AssembledObject.LoadPrefab falls back to
  them when Resources has no prefab. The converter now writes the `_metallic_smoothness` maps (split_spec.py's: metallic
  0, smoothness the normal map's alpha). **The mesh space** (OriginalModelsTests, 2026-11-15, three models imported into
  the test bed against the same models built from the cache: parts, bounds, signed volume all equal): a vertex (x, y, z)
  of the original -> (-x, y, z) x 0.05, normals (-x, y, z), the triangles' order reversed. All 319 assemblies build from
  the Android copy in the test bed (1,937 renderers, 47 s for all of them in edit mode, their textures included): the
  remodelled ones from the original meshes until the common pack replaces them.
- **Sounds** (2026-11-15): OriginalAudio (GoF2.Game): a cache sound as an AudioClip on the spot: WAV read as it is, MP3 by
  **NLayer 3.0.1** (`Assets/Plugins/NLayer`, MIT, the user's choice over background preloading; matches ffmpeg on all 2,078
  Android MP3s: equal lengths, no dropped frames), over 30 s streamed (a PCM reader on the MP3). **OriginalRefs**: the own
  assets' references to originals, recorded by `Reference/tools/player_assets/original_refs.py` in
  `Resources/GoF2Content/original_refs.json` (field paths -> the original's project path; 4,314 in StoryAssets, the combat,
  event, star map, menu, Supernova and weapon tables, the language table, the Station / MainMenu scenes' components), filled
  when a table loads (`OriginalRefs.Load` in place of Resources.Load) or a scene opens (sceneLoaded, by class and GameObject
  name); only empty fields, so a build with the originals is unchanged. Lists of more than 64 entries (the story's voices,
  the Mod Builder's audio index) are filled entry by entry when asked (`OriginalRefs.Entry`, StoryAssets.Voice,
  GameAudioIndex.Clip): all at once took ~20 s. Not yet: the derived images some tables hold (SkyLayerAssets,
  ShipShadows, ModAssets' materials, the story's portrait parts) and the build profiles' app icons.

## Plan

1. Inventory and this note (done 2026-11-15); the importers, the converter, the packs (done 2026-11-15).
2. **Content layer:** one API serving the game's own content (textures, meshes, materials, clips, text, data) from the
   converted cache in `GamePaths.Data`, with the `Resources` path behind it until the cache path is complete; the
   assembled objects built at run time from `assemblies.json` the way mod ships are (`ModShips.Template`); the sound
   tables become name lookups.
3. **Importers in C#** (GoF2.Game, plain C#, testable): AEI (RGBA8, ETC1, PVRTC 2 / 4 bpp, regions, cubemap strips), AEM
   (meshes, the .gof2mesh.json animation data), FSB5 (MPEG, IMA ADPCM, PCM), `.lang`, `.bin`. Each checked against the
   current project's converted files (the reference output) in edit-mode tests that skip without a source copy.
4. **First start:** "Show the game your Galaxy on Fire 2" with a file picker (desktop), Android's document picker, iOS's
   document picker; the conversion with progress, a check of what came out, then the derived assets.
5. **Derived assets on the player's machine:** assembled objects, 3D planets, sky layers, reflections; the optional
   desktop sky upscale.
6. **Builds without the originals:** the build strips every original and derived folder; a clean install, given only the
   player's copy, runs end to end. CI builds then need none of the LFS assets.
