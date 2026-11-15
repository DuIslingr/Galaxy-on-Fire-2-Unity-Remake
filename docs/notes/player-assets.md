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
  - iOS' `v_galaxymap_planets` has no alpha (Android's ring quadrant is translucent): a real difference between the
  copies, so that texture is in the iOS gap pack.

## Plan

1. Inventory and this note (done 2026-11-15).
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
