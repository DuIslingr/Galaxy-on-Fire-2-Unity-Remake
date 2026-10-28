# Mods: models and textures

Notes moved from `CLAUDE.md` (its index lists every notes file). Code comments citing `CLAUDE.md "<section>"` mean the section or bullet of that name here.

## Mods (remake-only)

- **Ship models** (`ModShips`, `ModShipBuilder`, `ModMaterials`, `ModGltfMaterials`; glTFast 6.20, `com.unity.cloud.gltfast`):
  each new ship's GLB loads with glTFast (asynchronous: `Preload` from the main menu, the menu's Leave and `NetGame.EnterWorld`
  wait for `Ready` / `WhenReady`, at most 30 s) into an AssembledObject template under a hidden DontDestroyOnLoad holder
  (the run-time port of PR #34's CustomShipBuilder: hull turned by modelYaw and scaled to modelLength (a skinned mesh
  baked into a plain one in its drawn pose first,
  `ModShipBuilder.FlattenSkinned`: the sizing, collision, shadows and the Mod Builder read the bind-pose mesh, which the
  bones drew elsewhere and at another size, so bone animations don't play; the GLB's node animations, parts moving on
  their own, loop: `ModGltf.LoopAnimations`, glTFast's legacy Animation at the default wrap mode played its clip once),
  engine glow discs at the
  slot-3 mounts on mat_34813 (a mount's `glowSize` [half width, half height, flame length] makes an ellipse; a `glowColor`
  or the ship's `engineGlowColor` switches the glow to `ModAssets.engineGlowTint`, the sprite in white
  (`Resources/GoF2Mods/ModEngineGlowWhite.png`, Build Mod Assets; the glow sprite there made round and soft, its ring of
  dashes averaged away) tinted by vertex colour, white-hot at the centre, and
  `ShipExhaust` tints the exhaust particles with it, on the particles.png cell whose product comes closest and
  brightest), throttle glows from their masks (`ThrottleGlow` with its trails), one LOD culled at 80000);
  `AssembledObject.LoadPrefab` hands it out for pack "mod" (while loading the game's own model of that ship stands in,
  else the Phantom's, always the original prefab: `Database.ShipAssembly(..., original: true)`; a project replacing the
  Phantom's model looped Template / LoadPrefab into a stack overflow on the builder's Exit), `NetProxy` for an
  "Assembled/mod/..." path. Materials are always copies of the URP Lit templates in `Resources/GoF2Mods/ModAssets`
  (**GoF2 > Build > Mod Assets**, `ModAssetsBuilder`: opaque / cutout / transparent, with and without detail maps; the
  templates hold placeholder textures and a faint emission so URP keeps their keywords and a build keeps the variants;
  a platform switch can drop their `_EMISSION` (seen switching to Android), so `ModAssetsGuard` (Editor) puts it back before
  every build: without it Linux / Android shipped without the emission variants, mod ships' glowing parts dark): the
  GLB's own glTF materials (`ModGltfMaterials`; metallic-roughness converted by `Hidden/GoF2/MetallicRoughnessToGloss`,
  the material's `metallicFactor` / `roughnessFactor` baked in, also on the CPU path, per factor pair
  (`ModGlbImages.Image.mrFactors`, `ModMaterials.RoleKey`): they were taken as 1, and the GoF3 Ships mod's maps are all
  metal in B with metallicFactor 0, so its hulls were mirrors, black against space) or
  the entry's `materials` (`ModMaterials.FromSpec`: the PR's fields plus `doubleSided`). Textures load from the mod's PNGs,
  compressed with mipmaps. Normal maps (ships / stations / rooms `normal` / `detailNormal`, glTF normal textures, `*_normal`
  texture replacements) are loaded with `normal: true`: Android's normal map encoding is "DXT5nm-style" (Player settings),
  so URP there reads X from alpha and Y from green (`UNITY_ASTC_NORMALMAP_ENCODING`); the game's Normal Map imports are
  re-encoded by Unity, a mod's RGB PNG wasn't, and every mod hull came out nearly black on Android (and in the Editor with
  the Android target). On Android `ModMaterials.NormalToAlpha` copies red into alpha before compressing (the glTF ones by
  `Hidden/GoF2/NormalToAlpha`, `Resources/GoF2Mods`); desktop reads either layout and is unchanged. **A GLB's embedded
  images** (`ModGltf.Load`, used by ships, stations, rooms and weapon fx) don't go through glTFast: `ModGlbImages.Strip` takes
  them out on a worker thread (each pointed at one shared 1 x 1 PNG, the indices kept, the other bufferViews packed into a
  new BIN; not for several / external buffers or meshopt) and `ModMaterials.PreloadImage` makes each different image once per
  mod by its MD5 (`ModInfo.LocalImage` writes it out for the decoder and it is deleted afterwards; `ModTextureCache.FileForContent`),
  compressed like the PNGs, the role's conversion on the CPU before compression (metallic-roughness to metallic / smoothness,
  Android's normal layout), and `ModGltfMaterials` / `FromGltf` take those (glTFast's own texture and the GPU conversions only
  for an image not taken out). glTFast kept every model's images uncompressed, one copy per model, plus an uncompressed
  render texture per metallic map (and per normal map on Android): the GoF3 Ships mod (79 GLBs, 1452 images, 251 different)
  crashed phones (2026-10; measured in the Editor: driver memory 4.9 GB -> 1.3 GB, its textures ~195 MB of DXT, 84 ships
  10 s from the cache). Textures load once per key however many ask at once (`ModMaterials.Once`), at most 6 decodes at once
  (2 on phones, `DecodeSlots`), phones compress in Texture2D.Compress's fast mode; at most 8 ships load at once (3 on phones,
  `ModShips.ShipSlots`), each holding its GLB until glTFast has read it. Shop icon: the entry's PNG
  (`ItemInfo.ShipIcon`), else the Phantom's; the dialogue tints mod
  ship names (no sprite). Code that sizes a ship by its renderers must skip trails (empty at the origin): the item window and
  `NetPlayer` use mesh renderers only. Another player's ship built before the session's mods were on (they join before
  NetState applies them) is built again on `ModShips.ModelsChanged`.
- **Engine effect** (`EngineFx`, ships.json `engineFx`, `CustomEngineFx`; the GoF3 Ships mod): Galaxy on Fire 3's engine at every
  exhaust mount in place of the glow discs (`BuildEngineGlow` without discs: the empty part marks the engines on / off) and the
  exhaust particles (`ShipExhaust` skips the ship): GoF3's NivelianEngine / TerranEngine / VosskEngine scenes
  (`assets/vfx/engines/<race>`: the flare `glow_mesh`, two camera-facing quads, a 9 x 9 unit square and a 27 x 2.7 streak at half
  brightness with the texture turned a quarter; the exhaust, four crossed cards 12.1 x 1.62 units with the texture's middle band
  u 0.39 -> 0.69 along and vertex brightness 0 / 0.77 / 0.2 / 0 at 0 / 1.73 / 6.91 / 12.09) and its VfxList trail (TrailNivelian =
  `particles/ship_engine_nivelian.psb`, Fork Particle Studio, unreadable: `beam_001.bmp` streaks drifting apart), the trail rebuilt
  as camera-facing ribbons of points that keep the ship's velocity plus their own backward speed (they bend when the ship turns,
  as in GoF3's ship viewer) and sway in smooth waves (each trail eases toward random sideways speeds, `SwayEase`; independent
  points made a zigzag), the streak's middle row across them (whole copies per segment read as beads) and a random brightness
  per point. EngineDrive levels (thrust 0.3..1 length, boost longer; a third of the glow at idle, unlike the ES2
  flames); in the station capped; materials copies of
  `ModAssets.fxAdditive` (`ModMaterials.CopyOf`) at `_Glow` 0.75 / 0.5 / 1 / 0.45 (flare, cone, trail, helix). A mount's
  `fxScale` sizes it (GoF3's helper scale:
  the Retro 0.5 / 1.62) and its `rotation` turns it (`ModHardpoints.MountTurn`; five Vossk hulls' engines 8.5-10 deg inward;
  an engine on the centreline keeps no sideways turn, the builder's `centreline_turn`: the K'ssshar Ka's centre helper
  carried its right engine's 8.5 deg, so its plume crossed toward that engine).
  The helix (`spiral*`, only the Nivelian engine has one: `_spiral.ae4meshgroup`, two ribbon strands, radius 0.5 -> 0.1 over
  10.5 units, spun by its animation): camera-facing strands rebuilt each frame round the exhaust's axis, the texture (GoF3's
  `vfx_generic_electricity_000`, a guess: the spiral's material names its flow textures by GUID only) along them, scrolled, faded
  by (1 - s)^2 (in flight GoF3's crackle is gone well before the strands' end). Part colours (`flareColor` / `coneColor` / `trailColor` /
  `spiralColor`, over the exhaust's; the flare's until then was always the exhaust's): the builder reads them from
  GoF3's materials for the helix engine (Colorize_Color1 = the
  EngineAttachment colour, unless Colorize_Custom; times DiffuseColor when DiffuseColorMultiply: cone 0.08 / 0.51 / 1, helix and
  trails 0.22 / 0.56 / 1) with the flare 0.75, cone 0.4 and trails 0.35 dimmer under it; the Terran / Vossk engines keep the hull's
  nozzle colour (their hulls light the nozzles orange / yellow-green while their effect materials colour blue / green; nothing
  shows which GoF3 draws; corrected for the Terran engine below). The Terran engine (checked against a clip of the Argus rotating in
  GoF3's ship viewer): its materials' Colorize_Options 1 draw the textures in their own colour, so every part takes the decoded
  textures' brightness-weighted colour (amber: flare 1 / 0.65 / 0.28, cone and trail 1 / 0.54 / 0.27; `texture_colour`), not the
  EngineAttachment's blue or the hull's pale nozzle colour; no wavering streams but one thin straight streak (`RACE_TRAIL`: 1 per
  exhaust, 0.45 units wide, wander 0.6, x2 the cards' length, intensity 0.35) behind a cone 2.5 x brighter, the spike GoF3
  shows. A Terran engine on a hull whose nozzles glow yellower than that amber takes its parts halfway to the
  nozzles' colour (the builder's `nozzle_tinted`: GoF3 draws the flare additively over the lit nozzle; the Retro / Groza
  Gr'Gath's gold nozzles, checked against a GoF3 video: (1, 0.75, 0.35) measured, (1, 0.80, 0.35) the blend; also the
  Acheron and Cronus). Matched by eye against two clips of the Moornta (GoF3's ship viewer, and in flight from the side and
  behind; Play mode: behind, below, above, the side, a hard turn; the Terran, Vossk and Retro hulls; the hangar hides it).
  The cone's own shape and edge-on fade (2026-10-17): `coneProfile` ([share of the length, brightness, u] per ring, the engine's
  own exhaust mesh: the Terran's peak at 0.93 and run the whole texture, the Vossk's a short spike, nothing past 0.84; default
  the Nivelian rings above) and `coneFade` ([from, to], the exhaust material's AngleBlend: each card's vertex colours x
  smoothstep(from, to, |N.V|) every frame, `EngineFx.FadeCards`, a cone mesh per nozzle), so from straight behind only the
  flares show, as in GoF3's ship viewer; the builder had written both since 2026-10-12 but nothing read them. Checked against
  GoF3 ship-viewer clips of the Atauno Rheep, Nestaar, K'ssshar Ka, Na'takath and Shaan'ra-Grth (one horizontal, one vertical
  turn each; the flares on the nozzles, the directions): the Vossk engine's streak is the Terran's, as long (1121 units: the
  builder's `trailSpan`, 2 x the Terran cards; 2 x its own longer cards ran past those hulls) and straight (wander 0); its
  flares take the hull's nozzle colour (`NOZZLE_FLARE`: the clips' flares sample at hue 80-90, lime, the plume around them
  teal at 130-160; the style's flare the Vossk hulls' mean 0.65 / 1 / 0.11); the Nivelian streams 1.5 x the cards (970 units,
  wander 3: GoF3's viewer shows short wisps a fifth of the hull, 4.33 x ran 1.5 hulls behind). The Inouac engine (no exhaust
  material of its own) takes the Nivelian exhaust's rings and fade, whose textures it borrows.
- **Exhaust styles** (`ModExhausts`, a mod's `exhausts.json`; the guide's "Exhaust styles"): engine effects any ship can wear,
  picked in the hangar's Customize screen (`ShipCustomizePanel`'s Exhaust row and the style's two colour rows; with styles in
  the mods that are on every ship has the screen: `ModShipKits.CustomizationOf` gives a ship without other customizations a
  kit of its own with nothing else, `Kit.weaponColorRow` false). A style is a GoF3 `engineFx` (`EngineFx.Create`; its colours:
  flare + cone, trails + helix) or a flame `model` with flame `materials` (an ES2 thruster: loaded with the mod ships as the one
  part of the style's own kit, `ModShips.LoadAll` / `EnsureExhaust`; per exhaust an instance named `exhaust_nozzle_N` at the
  mount, `MountTurn` x the style's `yaw`, scaled by its nozzle's size (below) against the style's `nozzle`, driven by an `EngineFlame` on
  the holder that blows each along its nozzle's -Z; colours: copies of the flame materials with `_EmissionColor` / `_BoostColor`
  at their own intensity; a flame style's boost cards are its own mod's ships' boost jets (`OwnShip`: the ship's key in the
  style's mod): on any other ship the holder's `EngineFlame.boostOverride` sets GoF2/ModEngineFlame's `_BoostOverride`, the boost
  cards stay hidden and the boost turns the main cards to the boost colour). The player's Exhaust size row (`exhaustsize=`,
  `ModExhausts.ParseSize`: 0.5..2 in 0.1 steps) multiplies each exhaust's fitted scale. Each exhaust takes its nozzle's outline
  (`ModExhausts.ShapesOf`, `NozzleShape`: the convex hull of the nozzle's geometry in the mount's plane, its area centroid as the
  centre, kept as `profile`, its radius at 32 angles; `FromPoints`): the mount's `outline` (game units, position_engine's axes:
  the GoF3 builder writes it from the nozzle's glowing surface, `engine_glows.engines`), else a mod ship's readable meshes with
  "nozzle" materials measured on the instance (`Measure`: vertices to the nearest mount; an ES2 hexagonal rear), else the mount's
  `glowSize` as an oval, else the game ship's measured glow (`nozzle_shapes.json`, x1.1: the glow sits inside the nozzle, median
  0.91 of the round size), else round (`NozzleRadius`). Sized by its mean radius; the shape itself: a flame model's meshes are
  copied per nozzle and bent to the outline (`Warp`: each vertex's distance from the axis x the profile's factor at its angle;
  freed with the holder's `EngineFlame.ownedMeshes`), an engineFx's cone cards reach the outline (a cone mesh per shaped
  nozzle), its helix runs along it and its trails spread along the long side (`EngineFx.profiles`, `Trail.start`), centred on
  the nozzle. Checked in Play mode: ship 7's wide nozzle blocks (both styles fill them), an ES2 Sentinel's hexagon (measured
  from its nozzle meshes) with a GoF3 drive, the Moornta's GoF3 outlines with an ES2 thruster. `NozzleRadius`: a mount's
  `glowSize`, a mod ship's `engineGlowRadius`, else 55 game units x the game
  ship's exhaust anchor scale (`turretAngles`). An `outline` is used only when plausible against the mount's `glowSize` (mean
  at least half of it, centre within 1.5 x it; `ModExhausts.Plausible`; the builder writes no others, `outline_plausible`):
  the Vossk hulls' outlines were slivers of a few lit texels of their nozzle rings (the Shaan'ra-Grth's 1 unit wide, 18 off
  its mount), which shrank any style on them to nothing. Sizes (2026-10-17): every source but one measures the whole nozzle
  (the game ships, ES2's nozzle meshes); the GoF3 builder's `glowSize` / `outline` are the hottest core of the nozzle's glow,
  1 to 5 x smaller (the Atauno Rheep's 16 units in its ~90-unit hexagon). An `engineFx` now says which nozzle it is drawn
  for (`nozzle`, game units, default `coneWidth`; `CustomEngineFx.NozzleRadius`), measured by the builder on the hulls from
  behind (`ENGINE_NOZZLE`: Nivelian 87, the cone fills its nozzles; Terran 100, the Argus' 75-110 under a 138 cone; Vossk
  45, the K'ssshar Ka's ~46 and the Shaan'ra-Grth's ~34 under a 138 cone); on a ship with an `engineFx` of its own that gives a `nozzle` the shapes
  are scaled to it (`FitToOwnEffect`: the median of mean / fxScale becomes `nozzle`; without one, a mod written before
  the field, the shapes are kept, each keeping its shape and its
  size against the others), and an `engineFx` style's default `nozzle` is its `NozzleRadius`: a GoF3 hull wearing its own
  race's style shows it exactly as its own effect, and the styles fit game, GoF3 and ES2 hulls alike (on GoF3 hulls they
  were a fifth of the size, on the Vossk ones next to nothing; with the cone as every engine's nozzle the Vossk hulls' were
  three times too big). Offered (`ModExhausts.For`,
  `Offered`, `Find(key, ship)`; the Customize panel takes the ship, `Apply` ignores a style the ship isn't offered): every
  style but a flame style on its own mod's ships (ES2's thrusters are cut from the ES2 ships' own rear parts, which choose
  their exhaust there). Checked in Play mode (2026-10-17): the Phantom (Nivelian drive, ES2 thruster), the Cronus (Terran),
  the Argus (Vossk), the K'ssshar Ka (ES2 heavy thruster), the Shaan'ra-Grth (Nivelian), the ES2 Sentinel (Terran; its own
  thruster refused), the Customize screen's Exhaust row on the Sentinel, a Vossk hull and the Phantom. Groups (exhausts.json
  `group` / `groupName` / `scale`, `Style.lead` / `members` / `ForNozzle`): flame styles of one mod with the same group are
  one choice, its first (`For` lists only leads, `Find(key, ship)` turns a member's key, an older build, into its group);
  each nozzle wears the member whose `nozzle` x `scale` is nearest its size on a log scale (the player's Exhaust size
  counted; the instance is named `exhaust_nozzle_<i>_<member>`). The ES2 importer groups its three thrusters as "EVERSPACE
  2 thruster" (`scale` 3.6, the kit scale: nozzles of 1.38 / 1.53 / 2.21 m): the game's ships take the light thruster
  (the Phantom, the Inflict), larger nozzles the heavy one (ship 7, the GoF3 hulls; the Cronus both). The build carries
  it (`exhaust=mod_id:id;exhaustcolor=;exhaustcolor2=;exhaustsize=`,
  `ModShipKits.Build`, kept out of `VariantAssembly`'s name like the weapon colour) and `ModExhausts.Apply` puts it on each model
  instance (the player's in `SpaceLevel` spawn / swap, the turntable and hangar guests in `StationLevel.SpawnShip`, other players'
  ships in `NetPlayer.BuildModel`): a holder `exhaust_style` under the engine glow part aligned with the ship's root (it goes with
  the engines), the model's own exhaust hidden (the glow part's renderers `forceRenderingOff`: `ShipController.UpdateEngineParts`
  only toggles `enabled`; a built-in `EngineFx` disabled; the model's `EngineFlame` `suppressed`, its own flames dark; no
  particles: `ShipExhaust` finds the holder's effect), the manoeuvring jets kept. The Customize screen runs the turntable's
  engines (`StationLevel.PreviewEngines` / `PreviewEngineDrive`, `Visuals.EnginePreview` read by `EngineDrive`, past the
  station's full-throttle cap: boosting while a boost colour row is selected, `ShipCustomizePanel.BoostRowSelected`). The GoF3
  Ships mod's builder writes GoF3's Nivelian (helix), Terran and Vossk drives (`exhaust_styles`, GoF3's engine colours as the
  palette); the ES2 importer three thrusters cut from one-nozzle rear parts (`exhaust_module`: the flame cards with their UV1,
  the main cards' nozzle ring at the origin, ES2's +X nose turned to +Z; ES2's exhaust palette). Verified in Play mode: the
  Nivelian helix and an ES2 thruster on the Phantom, a GoF3 Terran drive on an ES2 Sentinel (its flames dark), an ES2 ring
  thruster in custom colours on the GoF3 Moornta (its engine effect off, the boost cards in the second colour), the Customize
  screen's rows and the turntable preview. Not tested in multiplayer.
- **Textures / skins** (`ModTextures`, a mod's `textures/<game texture name>.png | .jpg`, e.g. `ship_028_terran_diffuse` for
  the Veteran's hull; `textures/<assembly>/<name>` for one model only, e.g. `textures/ship_028_terran/glow_terran.png`: the
  shared lights / engine glow on the Veteran alone, before the every-object file; the scope is `AssembledObject.ModScope`,
  its prefab's name taken in Awake, and such objects get their own material copies, keyed (scope, material); the builder's
  Skins tab offers "This ship..." / "All ships..." on a shared texture): replaces that texture on every assembled object
  using it (`AssembledObject.Awake` -> `Apply`: the
  object's renderers get cached copies of their materials with the mod's texture in `_BaseMap` / `_MainTex` / `_BumpMap` /
  `_MetallicGlossMap` / `_EmissionMap`; the game's material assets are never touched; when the mods change in a scene, the
  Mod Builder's skins, the objects there get the game's materials back before the copies go and the new textures once
  loaded, `ModTextures.Revert` / `ReapplyAll`: a cleared skin drew the hangar's other ships of that model magenta); `_normal` / `_metallic` names load
  linear; loaded with the rest (`ModMaterials.PreloadTexture`, `ModLoading`). **Per ship** (a mod's new ship on a game model,
  `"model": "gof2:<model>"`): `textures/ships/<ship id>/<name>` replaces the texture on that ship alone, the game's ship of
  that model and the others on it keep theirs (2026-10-17). `ModContent.ApplyShips` marks such ships
  (`Database.ShipOwnTextures`, `ModContent.HasShipTextures`), `Database.ShipAssembly` then hands out a copy of the model of
  their own, "<model>#ship=N" (`KitRules.ShipToken`; `ModShipKits.ParseShipCopy`, ParseSkinned = one with a skin;
  `ModShips.SkinnedTemplate` makes a plain copy under the holder; `VariantAssembly`'s skins of such a ship go on the model's
  name), whose instances' `ModScope` leads `ModTextures` to the ship's key (`ShipScope`: "<mod id>:<ship id>", keys
  "<key>/<name>"), then the scope's own, its model's (`ModelScope`, so `textures/<model>/` still reaches the copies), then
  every object's; `HangarShipShadow.Attach` takes the model's map for "#" names. Builder: the Skins kind lists the project's
  new ships on a game model (`ModProject.OwnsSkinOf` / `OwnSkinShip` / `ShipSkinScope` "ships/<id>"; builder.json "skins"
  keeps them by id, their number being this run's), each texture has one Replace into the ship's folder and its ✕ leaves
  the project's every-ship file alone; the Ship tab's **Its own textures…** opens it. Tests: `GameModelsTests`
  (`ANewShipOnAGameModelWithTexturesOfItsOwn`, `TheBuilderGivesAShipOnAGameModelTexturesOfItsOwn`). Not run in
  Unity yet. The rest verified in Play mode: a BountyBot
  (/make_skin_texture) Veteran skin on the hangar turntable (`Mods/veteran_skin`, git-ignored). The backdrop's planets, suns
  and rings too (#66, `Backdrop.Load` -> `ModTextures.Replace(material)`: their Resources/GoF2Backdrop materials aren't on
  assembled objects; the copy's texture clamped). A mod's `backdrop.json` (`ModBackdrop.StarPlanets`, the last mod in the load
  order with one wins) `{ "planets": "star", "planetGlow": 2, "planetFlare": 0.35 }` draws the retextured planets as stars:
  facing the camera with its roll, not mirrored, no ring, their core at `_CoreGlow` planetGlow under the remake's bloom, and
  looked at, the sun's flare at planetFlare of its strength (a slight swell, an additive horizontal streak of their own
  texture, `Body.starStreak`).
- **Loading** (startup lag, `ModLoading`, `UI.ModLoadingView`): everything the mods bring loads at once in the background
  from the main menu's start (and again when the mods change): every ship together (`ModShips.LoadShip`: the files read on
  worker threads, the textures decoded by UnityWebRequestTexture off the main thread (`ModMaterials.PreloadTexture`, into
  the cache `ModMaterials.Texture` reads; zip files copied out once by `ModInfo.LocalFile`, cache folder by the zip's date and
  size), glTFast's main-thread work for all of them in one `TimeBudgetPerFrameDeferAgent` (0.6 of a frame; the old
  `UninterruptedDeferAgent` built each model in one go), the stations and rooms (`ModStations`), the weapon fx
  (`ModWeapons`), the music tracks and sound effects (`ModAudio`, `ModMusic`, `ModSounds`), the texture replacements
  (`ModTextures`), then the ships' hangar shadows
  (`World.ShipShadowBaker.ModShipsBaked`, see "Station scene"). Textures are compressed to DXT1 /
  DXT5 with their mipmaps by a Burst job (`ModTextureEncoder`, van Waveren's real-time encoder, native buffers: Texture2D.Compress
  took 110-145 ms per 2048 px texture on the main thread, a managed encoder's garbage a 2 s collection) where the GPU reads
  DXT; elsewhere (phones) Texture2D.Compress, one texture per frame. The result is kept on disk (`ModTextureCache`,
  `persistentDataPath/ModCache/Textures/<mod id>/<hash>.tex`, the hash of the file's path, size, change time, linear and the
  kind of compression): a later start reads it back on a worker thread instead of decoding and compressing (five PR ships
  2.3 s -> 1.3 s; the first start writes it, 126 MB for their 65 textures); an uninstalled mod's folder goes on `Scan`.
  The startup splash shows "Loading mods" with a progress
  bar and the ship / track in progress until it is done (`MainMenu.WaitForMods`, then the title; not shown when
  the mods that are on bring nothing to load, `ModLoading.HasWork`: no mods or only quests), so does the fade before a
  game scene when the mods changed in the menu (Leave). Measured in the Editor with the five PR ships: 5.3 s with frames of
  100-180 ms before, 0.9-1.9 s after with smooth frames (two of 83 / 164 ms right after the menu scene's load).
  Faster loading (2026-10-11, measured with the GoF3 Ships mod: 79 GLBs, 329 textures, 24-thread CPU, Editor, from the
  ships' start): cold 5.25 -> 2.92 s, warm 1.2 -> 1.0-1.1 s with the hangar shadows done 0.1 s after the ships (were up to a
  second, one hull per frame; now hull reads until 3 ms of the frame, `ShipShadowBaker.PrebakeReadMs`), GCs 25 -> 12 cold.
  The encoder spreads a texture over the job workers (`IJobParallelFor`: the role's conversion per pixel row, each mip level
  per row, every block row of every level at once; one serial job per texture before) and does the metallic-roughness /
  normal conversion itself (`ModTextureEncoder.Remap`; `ModMaterials.Convert` on the main thread is now only the fallback);
  output byte-identical to the old encoder (all 329 cached files compared). Cached textures don't wait for a decode slot
  (`CacheSlots` 16 / phones 4; `DecodeSlots` now processorCount / 2, 4..12, phones 2), their data and the encoder's output
  stay native (`ModTextureCache.Entry.data` is a NativeArray read straight from the file; the cache file written from
  `Work.Data` on a worker thread: the 1-5 MB managed copies drove the collections), and uploads share a 4 ms budget per
  frame (`ModMaterials.UploadTurn`). `ModShips.Ready` asks `ModContent.AnyShipModels` (ActiveShips rebuilt every entry: ~200
  KB and 2 ms per call for 79 ships, three calls a frame from the loading screen). Left: the GLBs are read whole into
  managed arrays for glTFast (~430 MB for this mod, most of the warm load's GCs).
  Phones (no DXT): the same jobs encode ETC2 (`ModTextureEncoder.Target.Etc2`, ETC2_RGB / ETC2_RGBA8, cache kind "etc2";
  every OpenGL ES 3 / Vulkan device reads it) instead of Texture2D.Compress on the main thread, one texture a frame: the colour
  in ETC1's individual / differential modes, never T / H / planar, the table and indices chosen by each pixel's brightness
  offset, the alpha as EAC. Checked in the Editor with Unity's own ETC2 decoder (2048 px ship maps): RGB 33.1 dB (Unity's
  fast ETC2 32.9, normal 36.6), a normal map with X in alpha 30.3 / 53.9 dB (Unity fast 30.1 / 54.1); with 4 job workers
  and Burst safety checks off 34-41 ms per opaque texture with its mipmaps, 104-135 ms with alpha, off the main thread (Unity
  fast: 31-51 / 363-418 ms on it, the top level only); the whole loader forced through it built all 79 GoF3 ships. On a
  phone (S24 Ultra): the 79 GoF3 ships cold in 9.5 s, nothing compressed on the main thread, the hulls
  checked up close. Texture2D.Compress stays for a GPU that reads neither; a phone's old "gpu" cache files are no longer read
  (nothing deletes them).
- **Image formats** (`ImageImport`): every mod image (ModMaterials' `Texture` and background `PreloadTexture`, so skins,
  portraits, icons, hull textures, planets / suns / skies; ModInfo's preview; ModTextures' file list) and the Mod Builder's
  pickers (which store a picked image as PNG) read PNG / JPG by Unity's decoders and TGA (plain / RLE), BMP (8 / 24 / 32-bit),
  DDS (DXT1 / 3 / 5, ATC "ATC " / "ATCA" / "ATCI", uncompressed; not DX10) and the game's `.aei` by its type byte, as the
  engine's loader maps it (the function before `TextureCreateFromFile`): raw RGBA 1 / 3 / 0x81, ETC1 0x14 / 0x16 / 0x17 /
  0x40 / 0x42 (Android), PVRTC 2bpp 0x0d / 0x0f and 4bpp 0x10 / 0x12 (iOS), ATC with explicit alpha 0x11 / 0x13, DXT1 0x20 /
  0x22, DXT3 0x21 / 0x23, DXT5 0x24 / 0x26 (PC); bit 1 = mipmaps, only the top level read; the engine has no ATC RGB (4bpp)
  kind. They are decoded by its own decoders (`DecodePixels`, worker-thread safe, by magic; TGA by extension). Until
  2026-10-23 the .aei types past ETC1 were guessed by the data's size, so an iOS PVRTC texture (a player's
  `tex_mido_ships.aei`) came out as DXT1 noise. Verified: each format against a reference image (size, orientation,
  colours, alpha), a PC `.aei` skin identical to an independent decode and shown on the turntable through the background
  loader; PVRTC 4bpp on that iOS file (the Midorian ships' atlas, identical to an independent Python decode); PVRTC 2bpp
  and ATC only against hand-built blocks (`ImageImportTests`), no real file.
