# Known open items and roadmap

Notes moved from `CLAUDE.md` (its index lists every notes file). Code comments citing `CLAUDE.md "<section>"` mean the section or bullet of that name here.

## Known open items

- The FMOD event file (`Audio/_FMOD_GOF2.fev.bytes`) is parsed by `Reference/tools/audio/fev_lgcy.py` (the whole LGCY
  chunk from the decompiled loader `Reference/decompiled/fmodevent/`, libfmodevent.so via Ghidra: events, layers, sound
  instances, parameters, envelopes (their points are in EPRP), sound definitions with waves and banks; `--event <id|name>`,
  `--sounddef`, `--ids`, `--json`). `build_event_table.py` writes `Reference/research/fmod_event_ids.txt` (all 2293
  system ids -> name, group, .ogg files); `fev_events.name_of` uses it. Envelope values: pitch ×2^(8v − 4), volume
  linear.
- Data conversion lost some non-ASCII characters (U+FFFD in `stations.json` names like "Neh?bru" and a few texts).
- `PartAnimation`: Scale keys are in the mesh's own (engine) axis order, not the Z-up swap of the position keys (the
  explosion debris streaks stretch sclZ 45x lengthwise; swapped they were km-long lines); every other animated mesh with
  uneven scale follows this too, only the explosion was checked in Play mode. The UV scrolls `v5_0` (u) / `v5_1` (v),
  100 = one texture, run on every mesh (`_UVOffset` on GoF2/SkyLayer, else `_MainTex_ST`, which the Shader Graphs add:
  the remake subtracts the original's offsets, its textures are flipped; the burning stations' fire and smoke, plasma
  beams / streams, projectiles, gas clouds, the clamped fx atlases too: their scrolling cells stay inside the texture,
  the beam strips of sn_projectiles repeat every scroll period) and count toward the animation's length. The `extra`
  channel (0 to 100, opacity; `_Fade`, else the Shader Graphs' `_Color`) is only applied where `applyMaterialChannels`
  is on (the stations in their orbits, `OrbitBuilder.SpawnStation`: the blinking lights of the Nivelian / Midorian /
  pirate / Loma / Supernova-era stations and the Kaamo Club's flickering signs, frozen until 2026-10 (a player's
  report); an animation of only `extra` keys turns it on by itself and runs for their length (the Kaamo Club's lit
  panels, the plasma array stages' lights: they had no length and stayed off); on an opaque material it scales the
  colour, `_BaseColor` on URP Lit; the sky layers, explosions, gun projectiles / muzzle flashes / impacts via
  `GunRig.EnableFades`: an impact's 3600-unit glow is meant at 20 % for 267 ms; the hyper_drive, khador_jump, the gates'
  `_jump_anim_add` and the Void station explosion, which all fade to 0 by it); `v5_2`..`v5_6` aren't applied.
- `PartAnimation` starts every animation, and wraps every loop, at the original's range start: the file's smallest positive
  key (`LoadPoseMs`; `MeshCreateFromFile` 0x75c60 timeBetweenFrames, `Transform::InitAnimationRangeInTime` 0x7e31c,
  `SetAnimationState(3)`, `Transform::Update` 0x7e388), set in `Awake` as `loopStartMs` (an absolute time: code may set
  another after Awake, which never stacks on it; `SkyLayers.Add` only sets one it is given). 226 of the 243 animated files
  open with a one-off t 0 key (the animation from 33 / 50 / 100 ms), 125 with a different pose there; played from 0 they
  jumped on every wrap. Before this only the station rooms, the Void station and the sky layers skipped it; the other 94
  (weapon fx, explosions, the gates, the Kaamo Club / mining plant / plasma array effects, the deep science ships, the
  wrecked freighter, the Khador jump, the wormhole) now do too. Odd starts kept as the original has them: the Vossk bar's
  streaks 500 ms, the EMP rocket's flame 400 ms, the supernova flares 1000 ms; a range that starts at its end (one key:
  the magma asteroid) holds that pose. Not built: the original's explosion type 6 starting at 2300 ms (`Explosion::reset`).
- The default steering sensitivity is a guess (1.0); the original's touch / tilt sliders run 0..1 with 1.0 the maximum, the remake's touch slider 0.2-2.2.
- 13 resources referenced by the code aren't in the OBB (dev leftovers).
- Unity 7000.0.0a7 hands `ModelOrientationPostprocessor` part11 of `sn_cargo_001_midorian_wrecked` unreadable, so that
  60-vertex piece isn't turned 180 deg (a warning names it on import).

## Roadmap (suggested order)

0. Story: data, rules, dialogue, radio, docked / in-flight flow and the first levels done (see "Story"); freelance
   missions, the Missions window done (see "Bar and freelance"). The main story (0-45) with its levels, cutscenes, the
   Void and the ending done; the Valkyrie add-on (45-84) done; the Supernova add-on (84-162) built (see "Supernova
   add-on"), still to be played through.
1. Combat: guns, missiles, special weapons, turrets, sentries, ship damage, lock-on, NPC ships, capital ships, pirate
   bases and the combat equipment done (see "Weapons", "NPCs and combat", "Combat equipment"). Cargo stealing and the
   tractor auto modes done.
2. NPCs: free-flight traffic, fighter AI, wingmen, freelance mission orbits, capital-ship turrets, Wanted criminals, Specter cloaking done.
3. A star system scene: done (see "Space scene"), with the lens flare and the extra sky layers, autopilot, planet jumps,
   the star map and jumpgate / Khador travel. The Void's wormhole and home orbit done.
4. Stations and economy: station interior, shop, bar agents, blueprints, Status window done (see "Station scene",
   "Shop", "Bar and freelance"). Kaamo Club and the Most Wanted board done.
5. HUD and radar (`Hud`, `Radar`), then missions (`Mission`, `Objective`, `LevelScript`).
