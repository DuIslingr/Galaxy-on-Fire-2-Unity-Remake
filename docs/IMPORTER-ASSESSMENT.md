# ES2 and GoF3 importer assessment

Assessed 2026-10-26 against the local importer sources, research, Unity integration, and installed mods. This is a static assessment, not a new play-mode or visual verification. No importer, generated mod, or gameplay code was changed.

Subsequent performance work and its output comparisons are recorded in [IMPORTER-PERFORMANCE-AUDIT.md](IMPORTER-PERFORMANCE-AUDIT.md).

## Follow-up: rebuild caching implemented

On 2026-10-26, recommendation 1 was implemented in `/home/duislingr/GOF2UnityRemakeMods/gof3_ships_importer` (`import.py`, new `tools/build_cache.py`, documentation, and `tests/test_import_cache.py`). The findings below describe the original assessment.

The importer now uses source SHA-256 hashes and stage fingerprints covering converter dependencies, conversion tables, runtime versions, and relevant options. Changed inputs invalidate downstream stages; legacy timestamp markers rebuild once. Same-size archive/APK replacements are detected, incomplete hulls are cleaned up, failed hulls/variants/loadouts retry, and skipped-weapon diagnostics survive cache reuse.

Successful builds write provenance beside the mod as `<output-folder>.build-manifest.json` and in the work folder. Keeping this metadata outside the mod preserves the game's file-based save/multiplayer signatures. The record includes importer revision and file hashes, source identity, stage fingerprints, runtime versions, options, remake input hashes, and conversion diagnostics.

Validation: 24 regression tests with deterministic conversion fixtures, including clean/resumed output equivalence and selective invalidation; Python 3.9 syntax checks and CLI help. These tests substitute the asset converters and Blender, so a full game-asset conversion and visual verification remain outstanding. Installed mods were not rebuilt or replaced.

## Follow-up: ES2 caching and provenance implemented

On 2026-10-26, the same approach was added to `/home/duislingr/GOF2UnityRemakeMods/es2_ships_importer`. ES2 previously rebuilt every run. It now caches content conversion, ship icons, preview, mobile conversion, and zip packaging. Content conversion stays one stage because `build.main` shares kits, material rules, and world data across its selected parts.

Input inventories detect same-size edits and added/removed files or directories. Stage fingerprints cover converter dependencies, runtime versions, external tool identities and relevant options. Cached outputs are verified and copied from separate snapshots; editing a built mod cannot poison the cache. Missing requested content and reported rendering failures retry. Packaging uses stable ordering and timestamps.

The default cache is `<out>_work`; `--work` selects another location and `--fresh` rebuilds its stages. Work folders require an importer ownership marker and an exclusive process lock. Snapshot copies need additional disk space. Build records live beside desktop/phone mods and in the work folder, outside game mod hashes and archives.

Validation: 30 regression tests; Python 3.9 syntax, CLI help/part listing, configuration-example and whitespace checks; an actual devices-only CLI build producing 31 devices/consumables. Clean, resumed and forced-fresh CLI builds produced identical files and ZIP bytes; the resumed run reused every enabled stage. Full ship/sector conversion and real Blender rendering remain unverified. Installed mods and user exports were left intact.

## Where the work lives

| Component | Local location |
| --- | --- |
| Unity implementation and integration history | `/home/duislingr/Github/Galaxy-on-Fire-2-Unity-Remake/CLAUDE.md`, especially “Mods” |
| ES2 importer | `/home/duislingr/GOF2UnityRemakeMods/es2_ships_importer` |
| ES2 research notes | `es2_ships_importer/research/{engine_exhaust,floater_emissive,engine_trails}.md` |
| ES2 decompilation and exports | `/home/duislingr/GOF2UnityRemakeMods/es2_re`: `bp/` Kismet exports, `ghidra/` native functions, `out/` shader disassembly, `trails/`, `stations/` |
| ES2 research tooling | `es2_ships_importer/tools/shaders/README.md` and its CUE4Parse-based shader/blueprint exporter and Niagara disassembler |
| GoF3 importer | `/home/duislingr/GOF2UnityRemakeMods/gof3_ships_importer` |
| GoF3 decompilation | `/home/duislingr/GOF2UnityRemakeMods/gof3_re`: `eng.c`, `fork*.c`, `libgofm.so`, Ghidra projects, `sys/` galaxy research |
| Claude's relevant saved follow-up | `/home/duislingr/.claude/projects/-home-duislingr-Github-Galaxy-on-Fire-2-Unity-Remake/memory/gof3-secondary-slots-todo.md` |
| Installed output | `/home/duislingr/.config/unity3d/JoppieToppie/Galaxy on Fire 2/Mods/{es2_ships,gof3_ships,gof3_systems}` |

The importers are separate Git repositories; both were clean when inspected. Latest inspected commits: ES2 `ac68a5b`, GoF3 `bb9eaa0`, both dated October 25. Some older notes point to conversion scripts under Downloads; the maintained importer repositories above contain the current code.

## Existing capability

ES2 already goes beyond player hulls: modular customization, material conversion, engines, liveries, decals, thirteen customization trails, weapons, devices, NPC fighters, capital ships, the Dreadnought encounter, factions, sectors, stations, the Mobile Homebase, and docking in the live orbit. The importer supports selecting content with `--parts` and making a lighter mobile build.

GoF3 has customizable hulls and skins, weapon models, source-derived stats, race-specific engine meshes and Fork particle effects, capital traffic, and the roaming Manticore with its hangar. `tools/build_gof3_systems.py` separately builds the galaxy mod. GoF3 stations are deliberately non-dockable; docking is through the Manticore.

Installed records inspected:

| Mod | ships.json records | systems | stations | items |
| --- | ---: | ---: | ---: | ---: |
| es2_ships | 137 | 10 | 71 | 152 |
| gof3_ships | 46 | — | 1 | 30 |
| gof3_systems | — | 24 | 68 | — |

These are JSON record counts, not counts of unique purchasable hulls. GoF3's 46 ship records contain 37 hulls with one secondary slot and nine capital ships with zero. Its build log reports 142 skins and 27 guns.

## Findings and recommended order

### 1. Make conversion rebuilds trustworthy

GoF3 resumes converted hulls by testing for a `.done` file (`import.py:172`, `:359`). Its input signature consists of source names and file sizes (`:423`); weapon and loadout stages also use completion markers. It does not fingerprint converter source changes for those cached stages.

Consequently, changing mesh/material conversion code and rerunning the same command can reuse an older conversion. Same-name, same-size replacement inputs can also evade the signature. This is a confirmed limitation of the cache design; this assessment did not establish that an installed asset is currently stale.

Next change: stage-specific fingerprints covering relevant inputs, converter code, and options, with downstream invalidation. Write a build manifest recording importer revision, source identity, options, and failed/skipped content. Check a clean build against a resumed build. Until then, use a separate fresh work directory when validating converter changes; preserve the existing output for comparison.

### 2. Validate visual fidelity before adding more effects

The research is substantial and reusable. ES2's shader math, blueprint inputs, Niagara parameters, and curves have been recovered; GoF3's engine scene/material variants and Fork emitter fields have implementations. Further blanket decompilation is unlikely to be the best first investment.

However, recovered equations do not establish an exact rendered match across engines. Current code retains exposure/brightness adjustments: `ModMaterials.Es2FlameGain = 300`, `Es2EngineVfx.LightGain = 0.08`, `Es2Dock.LightScale = 0.005`, and GoF3's per-part `INTENSITY` table in `engine_meshes.py:162`. ES2's trail research also permits noise textures whose bytes differ from Unreal's. `CLAUDE.md:3847` explicitly says the customization trails have not been checked side by side against ES2.

Next session: capture matched original/remake views with fixed camera, colors, lighting, and engine state. Cover idle, forward thrust, strafe, boost, and hangar preview; prioritize the thirteen ES2 trails and one fighter per GoF3 race plus a capital engine. Change one discrepancy at a time. Inspect assembly or shader disassembly where a hypothesis needs stronger evidence: `gof3_re/eng.c` itself contains decompiler warnings about bad instruction data.

### 3. Close the docking multiplayer gap

`CLAUDE.md:3356–3398` describes single-player checks at Union Bridge and the Mobile Homebase, including additive Station loading, launch without reloading the orbit, sounds, lights, and dust. The same notes explicitly mark other players' view of docked ships (`NetHangar`) as unfinished.

Next integration work: define and replicate approach/docked/departing states, station identity, and moving-station-relative position. Verify with two clients: approach visibility, docking, changing a ship/loadout while docked, takeoff, late join, disconnect, and station movement. Keep this separate from shader calibration so failures are attributable.

### 4. Verify the new galaxies as playable spaces

Both installed system tables have resolvable internal gate references in the static check. That does not prove cross-mod travel, save/load, progression, docking access, or visual placement.

GoF3's conversion deliberately invents jumpgate routes and adapts scale/progression to GoF2 (`build_gof3_systems.py` header). Three Trim star placements—Neo Vegas, Porros Port, and Lazuline—are explicitly guesses (`gof3_galaxy.py:24–27`). Its generated manifest description still says stations use GoF2 hangars (`build_gof3_systems.py:258–259`), although the station records correctly use `orbit.station = nodock`.

Next checks: enable each galaxy independently and both together; travel through every connected cluster, save/reload inside each, check Manticore access and its roaming route, and compare the uncertain map positions with the original. Correct the manifest description. Treat invented routes and progression as documented adaptation choices.

### 5. Expand gameplay only after choosing the intended adaptation

ES2's `tools/devices.py:126–135` explicitly excludes eighteen devices/consumables because supporting mechanics are absent. These include teleports, Fusion Hook, linked damage, damage-over-time/infection effects, and a sensor cloud. Adding their item records alone will not implement them; select a mechanic and implement its runtime behavior first.

Claude's saved GoF3 follow-up proposes increasing secondaries to two for fighters and three for gunships. The current builder retains that as an undecided TODO (`build_gof3_mod.py:1296`). It requires mount/pylon changes as well as slot counts. Preserve the source-authentic default until this gameplay decision is made; an optional adaptation setting would support both preferences.

## Verification performed and limits

- Parsed all 59 Python source files across the two importer repositories with Python's AST parser: no syntax failures. This does not exercise dependencies or conversion paths.
- Parsed all 29 JSON files in the three installed mod folders: no parse failures.
- Checked 11,179 file-like relative references found recursively in their top-level JSON files: all existed. This check is extension-based; it does not validate GLB internals, shader compatibility, resource identifiers, or semantic correctness.
- Checked same-mod string gate references in both system tables: no unresolved targets. Cross-mod/base-game connectivity was not evaluated by this check.
- Inspected relevant runtime implementations and existing edit-mode tests, including engine trails, engine models, capital ships, and ES2 docking. Did not run Unity tests or claim their current results.
- `unity status` listed no connected Editor. The project requests Unity `7000.0.0a12`.
- Existing Unity-project changes were left intact. Reading normal Git status triggered a Git LFS temporary-file write failure under the read-only `.git` mount; status was inspected with the LFS filter disabled.

Recommended first implementation: fix GoF3 cache invalidation and add build provenance, then establish a repeatable original/remake visual comparison session. If multiplayer is the immediate priority, move docking synchronization ahead of visual calibration.
