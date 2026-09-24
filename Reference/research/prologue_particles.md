# Prologue ship smoke / fire and ship damage particles

Research for rebuilding the sprite particle effects of the original as Unity `ParticleSystem`s: the smoke and fire on
Keith's broken ship in the prologue, and (section B) the damage / death / EMP particles of NPC ships and the player.

Addresses use the Ghidra image base 0x10000. Particle times are in **ms**; particle and emitter **velocities are in
game units per second** (not per ms). Game → Unity: world `(x, y, z) → (x, y, -z) * 0.05`; ship-local offsets
`(x, y, z) → (-x, y, z) * 0.05` (see CLAUDE.md). In ship-local game space **+Z is the nose** (gun mounts in
`weapons_hd.json` have z > 0, engine exhausts z < 0).

Record values below come from `ParticleSettings::init` and were cross-checked against the disassembly of the two
prologue records (0x1b59b2..0x1b5b64, including the `vld1` literal at 0x1b6360 = (0, 0, 0.25, 0.25)).

## Functions

| Function | Address | Role |
|---|---|---|
| `ParticleSettings::init` | 0x1b4d80 | fills 0x30 records of 0x9c bytes; run on both globals `ParticleSettingsRef::cur` (read by the particle code) and `ParticleSettingsRef::init` |
| `ParticleSettings::multiplyAll` / `Interpolate` | 0x1b4b7c / 0x1b4ca0 | quality scaling / blending of records; `multiplyAll` has **no caller** |
| `ParticleSystemManager::ParticleSystemManager` | 0x1b4240 | `(canvas, cameraSet, spriteMaterial, spriteAdditiveFade, meshMaterial, meshFlag)` |
| `ParticleSystemManager::addSystem` | 0x1b4630 | `(matrix*, set, mirror)`: record = `cur + set * 0x9c`; flag 1 → sprite system, flag 2 → mesh system |
| `ParticleSystemManager::update` | 0x1b4538 | per system: `IParticleSystem::update(dt)`, emitter velocity, `emit(dt)` (vtable +4) |
| `ParticleSystemManager::render3d` / `renderSprites` | 0x1b4976 / 0x1b49c8 | sprites drawn only while manager byte 0 is set |
| `ParticleSystemManager::enableSystemEmit` | 0x1b4850 | → `IParticleSystem::enableEmit` 0x1b2760 (byte +0xc; re-enabling clears the emission carry) |
| `IParticleSystem::IParticleSystem` | 0x1b2370 | pool size = max `+0x0c` of its sets, all particles dead |
| `IParticleSystem::resetEmitterVelocity` / `calcEmitterVelocity` | 0x1b24e0 / 0x1b253c | emitter velocity = matrix position delta × 1000 / accumulated ms (units/s) |
| `IParticleSystem::interpolateColor` | 0x1b25c8 | start → end colour, fade-in |
| `IParticleSystem::emit` | 0x1b2790 | spawning (count, position, velocity, size, colour, UV) |
| `IParticleSystem::emitManual` | 0x1b3174 | scripted bursts at a given position |
| `ParticleSystemSprite::setParticle` | 0x1b3758 | writes position, size, UV rect, colour of one sprite |
| `ParticleSystemSprite::updateSingle` | 0x1b3cf0 | age, death, size growth, colour, sprite-sheet frame, motion |
| `ParticleSystemSprite::updateAreaExitParticle` | 0x1b3844 | flag 0x80 "area" mode (stars, fog), not used here |
| `AbyssEngine::SpriteSystemDraw` | 0x91da4 | camera-facing quads, half size = `size >> 1` |
| `AbyssEngine::SpriteSystemSetUv` | 0x91c9c | UV corners (u0, v0) (u1, v0) (u1, v1) (u0, v1) |
| `PaintCanvas::SetBlendMode` | 0x86df4 | 1 = SRC_ALPHA / ONE_MINUS_SRC_ALPHA, 2 = ONE / ONE; depth write off for both |
| `Level::init` | 0xbb49c | creates the managers (+0x74 ... +0x9c) |
| `Level::initParticleSystems` | 0xcc990 | Level-owned systems, `init()` of the managers |
| `Level::update` / `Level::render` | 0xd5fcc / 0xd4950 | manager update(dt) / render3d order |
| `Level::enableParticleEffects` | 0xcc920 | options particle slider → smoke / fire managers visible |
| `PlayerEgo::setLevel` | 0xa6f90 | creates the player's systems (types 9, 0xf, 0x2a) |
| `PlayerEgo::startSmokeEmission` | 0xadc20 | enables 0xf and 0x2a |
| `PlayerEgo::explode` / `revive` | 0xada6c / 0xadb2c | death burn (type 9) on / off |
| `PlayerFighter::setLevel` | 0xf0740 | NPC systems (types 9, 0xf, 0x2a, 0x11, 0x12) |
| `PlayerFighter::update` | 0xf0d90 | damage smoke threshold at 0xf1b0e..0xf1bc0, death, docking, EMP |

## A. The prologue smoke and fire

### A.1 Setup and trigger

- `Level::init` 0xbb49c creates the managers (only the relevant ones):
  - `+0x78` = `ParticleSystemManager(Canvas, 1, 0x4e85, false, 0xffff, false)`: sprites with material **20101**
    (shader 1 = **alpha blend**, `Textures/main/fx/sprite_smoke.png`), fade on alpha.
  - `+0x84` = `ParticleSystemManager(Canvas, 1, 0x6a72, false, 0xffff, false)`: sprites with material **27250**
    (shader 2 = **additive ONE/ONE**, `Textures/main/fx/sprite_fire.png`), fade on alpha (flag false).
  - `+0x74` = `ParticleSystemManager(Canvas, 1, 0x4e83, true, 0xffff, false)`: material 20099 (additive,
    `sprite_explosion.png`), fade on RGB. See B.3.
  - 4th ctor argument = "additive fade" bool, stored at manager +0x38 and copied to each system's byte +0x45: when
    set, fade-in multiplies RGB instead of alpha (`interpolateColor`).
- `PlayerEgo::setLevel` 0xa6f90, when `Status::getCurrentCampaignMission() < 2`:
  - `+0x300 = addSystem(Level+0x78, shipMatrix, 0xf, false)` → record 15 **SET_SMOKE_ENEMY**.
  - `+0x304 = addSystem(Level+0x84, shipMatrix, 0x2a, false)` → record 42 **SET_SMOKE_FIRE_ENEMY**.
  - both with emission off. `shipMatrix = AEGeometry::getMatrix(PlayerEgo+8)`, a pointer to the live ship matrix, so
    the emitter follows the ship (position and axes) every frame.
- `LevelScript::process` 0x160d50, campaign mission 0, step 11 (game/LevelScript.c ~3030): once the 2500 ms rumble
  timer passes (≥ 0x9c5 ms), the ship becomes visible, engine sound 0x9c (156, broken engine), **`startSmokeEmission`**,
  exhaust off, `setSpeed` (2.0 per `levelscript_cutscenes.md`; the float argument is lost in the decompile).
- Nothing ever turns them off again: no other code reads `+0x300 / +0x304`. They run until the level is destroyed. In
  mission 1 they are created but never enabled.
- `addSystem`'s type is simply the record index: `record = ParticleSettingsRef::cur + type * 0x9c`. The 4th argument
  (`mirror`, false here) negates the emitter's right axis.

### A.2 The two records

| Field | 15 SET_SMOKE_ENEMY (this+0x924) | 42 SET_SMOKE_FIRE_ENEMY (this+0x1998) |
|---|---|---|
| +0x08 flags | 0x02000021 (sprite, per-time emission, random UV mirror) | 0x02000021 |
| +0x0c pool size | 30 | 12 |
| +0x10 start size | 666.0 | 400.0 |
| +0x14 random size | 222 → size 666..887 | 200 → size 400..599 |
| +0x18 / +0x1c / +0x20 | 0 / 0 / 0 (mesh-only) | 0 / 0 / 0 |
| +0x24 lifetime | 1500 ms | 600 ms |
| +0x28 rate | 20.0 particles/s | 20.0 particles/s |
| +0x2c even spacing | 1 | 1 |
| +0x30 start colour | 0xFFFFFFFF (white, alpha 255) | 0xFFFFFFB2 (white, alpha 178 = 0.698) |
| +0x34 end colour | 0xFFFFFF00 (white, alpha 0) | 0xFFFFFF00 |
| +0x38 fade-in | 200 ms | 100 ms |
| +0x3c | 0 | 0 |
| +0x40 size growth | 2222 units/s | 222 units/s |
| +0x44 jitter X/Z (world) | ±200 | ±100 |
| +0x48 jitter Y (world) | ±200 | ±100 |
| +0x4c random velocity | 0 | 0 |
| +0x50 | 0 | 0 |
| +0x54/58/5c base velocity | 0, 0, 0 | 0, 0, 0 |
| +0x60 emitter velocity factor | **−2.0** | **−1.0** |
| +0x64/68/6c local velocity | 0, 0, 0 | 0, 0, 0 |
| +0x70 | 0 | 0 |
| +0x74/78 offset right/up | 0, 0 | 0, 0 |
| +0x7c offset along dir | −250.0 | +200.0 |
| +0x80 random along dir | 500.0 → along dir −250..+249 | 200.0 → along dir +200..+399 |
| +0x84/88 UV u0, v0 | 0, 0 | 0, 0 |
| +0x8c/90 UV u1, v1 | 0.25, 0.25 | 0.25, 0.25 |
| +0x94 min emitter speed² | 0 | 0 |
| +0x98 sprite-sheet frames | 16 | 16 |

Nothing modifies these two records at run time (`multiplyAll` is never called; the only run-time writes to `cur` touch
records 4, 7, 8 and the engine-exhaust copies 29..38).

### A.3 Record layout (0x9c bytes)

Meanings from `IParticleSystem::emit`, `ParticleSystemSprite::setParticle / updateSingle`, `interpolateColor` and
`ParticleSystemManager::addSystem`. Defaults are the "not initialized" values written for every record first.

| Offset | Type | Meaning |
|---|---|---|
| +0x00 | String (8 bytes) | preset name |
| +0x08 | flags | 0x1 sprite system, 0x2 mesh system, 0x10 emit by distance, 0x20 emit by time, 0x40 one burst then emission off, 0x80 "area" mode (particles fill and wrap a box around the emitter: stars, fog), 0x100 manual only (`emitManual`), 0x1000000 system update off at creation, 0x2000000 random per-particle UV mirror. Other bits (0x1000, 0x2000, 0x4000, 0x8000, 0x80000, 0x100000) appear only on mesh records: not analysed |
| +0x0c | int | pool size (the system allocates max +0x0c of its sets); with neither 0x10 nor 0x20: particles emitted per frame (per burst with 0x40) |
| +0x10 | float | start size = **full edge length** of the square, game units (`SpriteSystemDraw` uses `size >> 1` as half extent; stored as a 16-bit int) |
| +0x14 | int | random extra size `[0, n)`; the same random range is added to +0x18 and +0x1c |
| +0x18, +0x1c | float | extra per-particle parameters passed to `setParticle`; ignored by sprites (mesh systems) |
| +0x20 | float | passed to `setParticle` as `+0x20 × particle velocity`; ignored by sprites |
| +0x24 | int | lifetime, ms (particle dies when its age > lifetime) |
| +0x28 | float | flag 0x20: particles per second (count per frame = `int(rate × (dt + carry) / 1000)`, the remainder carried); flag 0x10: distance between particles, units |
| +0x2c | int | 1 = spawn points evenly spaced along the path travelled this frame; otherwise `i + rnd(0..1)` jitter |
| +0x30 | 0xRRGGBBAA | colour at age 0 |
| +0x34 | 0xRRGGBBAA | colour at age = lifetime (linear by `min(age / lifetime, 1)`) |
| +0x38 | int ms | fade-in: colour × `age / fadeIn` while `age < fadeIn` (alpha, or RGB for "additive fade" managers). > 0 → the sprite spawns with alpha 0 |
| +0x3c | float | area mode: fade distance; > 0 also spawns with alpha 0 |
| +0x40 | int | size growth, units per second (per frame `int(growth × dt / 1000)`) |
| +0x44 | int | spawn jitter `[-n, n)` on **world** X and Z |
| +0x48 | int | spawn jitter `[-n, n)` on **world** Y |
| +0x4c | int | random start velocity `[-n, n)` per world axis, units/s |
| +0x50 | - | not read by the sprite path |
| +0x54/58/5c | float | base start velocity, world axes, units/s |
| +0x60 | float | emitter velocity factor k: particle velocity += k × emitter velocity (see A.4) |
| +0x64/68/6c | float | start velocity along the emitter's right / up / dir, units/s |
| +0x70 | - | not read |
| +0x74/78/7c | float | spawn offset along the emitter's right / up / dir, units (area mode: box half size and fade radii) |
| +0x80 | float | random extra spawn offset along dir, `[0, n)` (integer random) |
| +0x84, +0x88 | float | UV u0, v0 of frame 0 (v from the image top) |
| +0x8c, +0x90 | float | UV u1, v1 of frame 0 |
| +0x94 | int | minimum emitter speed² (units²/s²) for emission |
| +0x98 | int | sprite-sheet frame count (0 = static rect) |

### A.4 Behaviour in detail

**Update order** (`ParticleSystemManager::update` 0x1b4538, called from `Level::update` with the frame dt in ms): for
each system, existing particles are updated first (`updateSingle`), then the emitter velocity is recomputed (from the
matrix position delta, only once ≥ 10 ms have accumulated), then `emit(dt)` spawns the new ones.

**Emission** (`emit` 0x1b2790, flag 0x20): runs only while the system's emit and render bytes are set.
- `count = int(20 × (dt + carry) / 1000)`, carry keeps the remainder: exactly **20 particles/s** for both effects.
- `disp = emitterVelocity × (dt + carry) / 1000` = the ship's movement this frame; particle `i` (0-based) of `count`
  spawns at `previousPosition + disp × (i + 1) / count` (+0x2c = 1), and is pre-aged by
  `(count - i - 1) / count × (dt + carry)` (clamped to dt) with a normal `updateSingle`. This is plain sub-frame
  emission along the path. If the ship moved less than 1 unit this frame, only one particle is spawned, at the
  current position.
- then `+ right × 0 + up × 0 + dir × (+0x7c + rnd[0, +0x80))`, then world jitter
  `(rnd[-j, j), rnd[-jy, jy), rnd[-j, j))`. `dir` = the ship matrix's Z axis (nose). Smoke: along the ship axis
  uniformly from 250 behind to 250 ahead of the ship origin, ±200 on each world axis. Fire: **200..400 units ahead
  of the origin** (toward the nose), ±100.
- **Velocity**: `v = rnd(+0x4c) + base − k × ve + local axes`, and after `setParticle` `v += 2k × ve` (the PLT symbols
  are `Vector::operator-=` 0x6b12c and `operator+=` 0x67f40), so in total **`v = k × emitterVelocity`**: smoke
  `−2 ×` the ship's world velocity, fire `−1 ×`. They are fixed at spawn (no drag, no gravity). A stationary ship gives
  motionless smoke; at the prologue speed of 2 units/ms (2000 units/s) the smoke moves backward at 4000 units/s in
  world space (6000 units/s relative to the ship), the fire at 2000 units/s (4000 relative).
- The pool is a ring buffer: a new particle overwrites the slot after the last one, alive or not. 20/s × 1.5 s = 30
  and 20/s × 0.6 s = 12, so the pools are exactly full.

**Per particle** (`updateSingle` 0x1b3cf0): `age = int(age + dt)`; dead when `age > lifetime`. Otherwise:
- size `+= int(growth × dt / 1000)` (integer truncation per frame: at 30 fps the smoke grows 2212 units/s, the fire
  212; at 60 fps 2187 and 187.5).
- colour = lerp(start, end, `min(age / life, 1)`) per channel; while `age < fadeIn` × `age / fadeIn` on alpha (both
  managers here have the additive-fade flag off).
- sprite-sheet frame `f = (age - 1) × 16 / lifetime` (integer): `u = u0 + f × 0.25`, wrapped into [0, 1) with the wrap
  count added to v in steps of 0.25: **4 × 4 atlas, row-major from the top-left, played once over the lifetime**.
- `position += v × dt / 1000`.
- flag 0x2000000: every frame's UV rect is mirrored horizontally and/or vertically by `AERandom(slotIndex).nextInt(40000)`
  bits 0 and 1 (a fixed random choice per pool slot): 4 random orientations, no rotation.

**Drawing**: world-space positions (`SpriteSystemDraw` transforms them by the view matrix only), camera-facing
squares aligned to the camera axes (`pos ± size/2` in view x and y), no rotation, drawn in pool-slot order (unsorted),
depth test on, depth write off. Colour = vertex colour × texture (`gl_FragColor = v_VertexColor * textureColor`).
- Smoke: blend mode 1 (SRC_ALPHA, ONE_MINUS_SRC_ALPHA). `sprite_smoke.png` is 2048 × 2048 RGBA, RGB dark grey
  (max 49/255) with the puff in alpha, so it reads as dark smoke; frames go from a dense puff to a thin one.
- Fire: blend mode 2 (**ONE, ONE**). `sprite_fire.png` is 2048 × 2048 RGB (no alpha); the frames darken from bright
  yellow flames to a few orange licks. With ONE/ONE **the vertex alpha has no effect**, so the start alpha 178, the
  fade-in and the fade to alpha 0 are invisible; only the atlas itself fades the fire out (high confidence: holds for
  both the shader path and the fixed-function GL_MODULATE path).
- Draw order (`Level::render` 0xd4950): +0x80, +0x74, **+0x78 smoke**, +0x7c, +0x88, **+0x84 fire**, +0x8c, +0x98,
  +0x94, +0x9c. Smoke is drawn before the fire.
- The two managers only draw while the options particle slider (`Globals::options + 0x28`, default 1.0) is **> 0.7**
  (`Level::enableParticleEffects` 0xcc920 sets their byte 0; called from `MGame::OnInitialize` and the options menu).

**Uncertain**: if the ship geometry's matrix carries a scale, the spawn offsets along `dir` are scaled with it (the
axes are taken straight from the matrix). The player ship is unscaled as far as known.

### A.5 Unity ParticleSystem settings

Put each system on a child of the ship at local position (0, 0, 0), rotation identity, scale 1. Unity values are
game values × 0.05.

| Setting | Smoke (record 15) | Fire (record 42) |
|---|---|---|
| Duration / Looping | any (e.g. 1 s), looping, no prewarm, Play when `startSmokeEmission` | same |
| Start Lifetime | 1.5 s | 0.6 s |
| Start Speed | 0 | 0 |
| Start Size | random between 33.3 and 44.4 m (666..888 units) | random between 20 and 30 m (400..600 units) |
| Start Rotation | 0 | 0 |
| Start Color | white | white |
| Gravity Modifier | 0 | 0 |
| Simulation Space | **World** | World |
| Emitter Velocity Mode | Transform (or the ship's Rigidbody) | same |
| Max Particles | 30 | 12 |
| Emission | Rate over Time 20, Rate over Distance 0 | same |
| Shape | Box, emit from volume, scale (20, 20, 25) m, position (0, 0, 0) | Box, scale (10, 10, 10) m, position (0, 0, **+15 m**) (toward the nose) |
| Inherit Velocity | Mode **Initial**, multiplier **−2** | Mode Initial, multiplier **−1** |
| Color over Lifetime | RGB white; alpha keys 0 → 0.000, 0.0667 → 0.467, 0.1333 → 0.867, 1.0 → 0.000 | faithful: alpha 1 throughout (ONE/ONE ignores it). Original alpha curve if wanted: 0 → 0, 0.1667 → 0.582, 1 → 0 |
| Size over Lifetime | linear 1 → 5.3 (exact: size(age) = start + 111.1 m/s × age, i.e. ×6.0 for 33.3 m, ×4.75 for 44.4 m) | linear 1 → 1.27 (exact: start + 11.1 m/s × age) |
| Texture Sheet Animation | Grid 4 × 4, Whole Sheet, Frame over Time linear 0 → 1 over the lifetime (16 frames), start frame 0, 1 cycle | same |
| Renderer | Billboard, Render Alignment View, Flip (0.5, 0.5, 0), sort by distance (the original is unsorted), **Max Particle Size raised** (e.g. 10; the smoke gets far larger than Unity's default 0.5 screen fraction) | same, sorting order above the smoke |
| Material | `sprite_smoke.png`, alpha blended (SrcAlpha, OneMinusSrcAlpha), unlit, texture × vertex colour, no depth write | `sprite_fire.png`, additive **One One** (ignore vertex alpha), unlit, texture × vertex colour, no depth write |

Notes:
- Shape approximation: the original spawns uniformly along the ship's own Z axis (smoke −12.5..+12.5 m, fire
  +10..+20 m) plus a world-axis-aligned jitter (±10 m smoke, ±5 m fire). A ship-aligned box with those combined
  sizes is visually equivalent.
- Unity's Max Particles blocks emission instead of recycling the oldest; 30 / 12 match the steady state, use 31 / 13
  if emission ever skips.
- Unity's world-space emission already spreads spawns along the frame's path, like the original.
- If the remake's `GoF2/AlphaBlend` / `GoF2/Additive` Shader Graphs don't multiply by vertex colour, use URP
  `Particles/Unlit` (Alpha / Additive) or add vertex colour to them; for the fire the blend must be One One (URP's
  Additive mode is SrcAlpha One, so keep the colour alpha at 1).
- Frame index: Unity rounds `floor(t × 16)`, the original `floor((age − 1) × 16 / life)`: identical in practice.

Script sketch (smoke; the fire differs as in the table):

```csharp
var ps = go.AddComponent<ParticleSystem>();
var main = ps.main;
main.loop = true; main.playOnAwake = false;
main.startLifetime = 1.5f; main.startSpeed = 0f;
main.startSize = new ParticleSystem.MinMaxCurve(33.3f, 44.4f);
main.simulationSpace = ParticleSystemSimulationSpace.World;
main.emitterVelocityMode = ParticleSystemEmitterVelocityMode.Transform;
main.maxParticles = 30;
var em = ps.emission; em.rateOverTime = 20f;
var sh = ps.shape; sh.shapeType = ParticleSystemShapeType.Box; sh.scale = new Vector3(20f, 20f, 25f);
var iv = ps.inheritVelocity; iv.enabled = true; iv.mode = ParticleSystemInheritVelocityMode.Initial; iv.curveMultiplier = -2f;
var col = ps.colorOverLifetime; col.enabled = true;
var g = new Gradient();
g.SetKeys(new[] { new GradientColorKey(Color.white, 0f), new GradientColorKey(Color.white, 1f) },
          new[] { new GradientAlphaKey(0f, 0f), new GradientAlphaKey(0.467f, 0.0667f),
                  new GradientAlphaKey(0.867f, 0.1333f), new GradientAlphaKey(0f, 1f) });
col.color = g;
var sol = ps.sizeOverLifetime; sol.enabled = true;
sol.size = new ParticleSystem.MinMaxCurve(1f, AnimationCurve.Linear(0f, 1f, 1f, 5.3f));
var tsa = ps.textureSheetAnimation; tsa.enabled = true;
tsa.mode = ParticleSystemAnimationMode.Grid; tsa.numTilesX = 4; tsa.numTilesY = 4;
tsa.animation = ParticleSystemAnimationType.WholeSheet; tsa.cycleCount = 1;
var r = go.GetComponent<ParticleSystemRenderer>();
r.renderMode = ParticleSystemRenderMode.Billboard; r.alignment = ParticleSystemRenderSpace.View;
r.flip = new Vector3(0.5f, 0.5f, 0f); r.maxParticleSize = 10f;
```

## B. Ship damage, death and EMP particles

### B.1 Player (PlayerEgo)

- **No low-hull smoke.** Apart from the prologue systems (section A) the player has only `+0x2fc`, and no code in
  `PlayerEgo` checks the hull to enable anything. `SET_SMOKE_PLAYER` (record 14) exists but no `addSystem` call uses it.
- `+0x2fc = addSystem(Level+0x74, shipMatrix, 9, false)` → record 9 **SET_EXPLOSION**, the **death burn**:
  - on in `PlayerEgo::explode` 0xada6c (hull reached 0);
  - `PlayerEgo::update` (game/PlayerEgo.c ~5045): when the death timer `+0x2f8` crosses 3000 ms, `Explosion::start`,
    type 9 emission **and** rendering off, and one `emitManual` burst of Level+0x3c = record 11
    SET_EXPLOSION_MANUALLY_BIG at the ship;
  - off (emit and render) in `PlayerEgo::revive` 0xadb2c.
- Campaign index 14 (Terran arrest): the EMP systems of enemy 0 (`+0x130`, `+0x134`, see B.4; `+0x12c` is always −1
  for fighters, so that call does nothing) are moved onto the player's matrix with `systemSetMatrix`, emission and
  rendering on, sound 15 (the EMP hit); switched off when the player is hidden (game/LevelScript.c ~7880-8003).

### B.2 NPC fighters (PlayerFighter)

`PlayerFighter::setLevel` 0xf0740 creates, on `AEGeometry::getReferenceMatrix(this+8)`, all with emission off:

| Field | Manager | Type / record | Texture / blend |
|---|---|---|---|
| +0x19c | Level+0x74 | 9 SET_EXPLOSION | sprite_explosion.png, additive, RGB fade |
| +0x7c | Level+0x78 | 15 SET_SMOKE_ENEMY | sprite_smoke.png, alpha |
| +0x80 | Level+0x84 | 42 SET_SMOKE_FIRE_ENEMY | sprite_fire.png, additive (alpha fade, no visible effect) |
| +0x130 | Level+0x8c | 17 SET_EMP_1 | khador_jump.png (material 27260), additive, RGB fade |
| +0x134 | Level+0x8c | 18 SET_EMP_2 | same |

So an NPC's damage smoke and fire are **exactly the prologue effects** (same records, same managers).

**Hull threshold** (`PlayerFighter::update` 0xf0d90, code 0xf1b0e..0xf1bc0, flag byte `+0x1f4`):
- flag clear and `hull < 0.33 × maxHull` (`Player::getHitpoints` / `getMaxHitpoints`, float compare): if the particle
  slider `options + 0x28 > 0`, smoke `+0x7c` and fire `+0x80` on (both off while `KIPlayer::isDocked`); the flag is
  set either way.
- flag set and `hull ≥ 0.33 × maxHull` (repaired): flag cleared, smoke and fire off.
- The check only acts on crossings; nothing re-enables them every frame.
- Docking approach (state 9, `this+0x84 = 9`, near the dock): off if flagged. Relaunch (state 1 after the docking
  time): on again if flagged.
- Death (hull ≤ 0, state 3): `emitManual(Level+0x74, Level+0x3c)` burst (record 11) at the ship, type 9 death burn on,
  EMP systems off; the tumble lasts `1500 + rnd(1500)` ms (`+0x1f0`) with smoke and fire still running; at its end
  `Explosion::start`, type 9 off, smoke and fire off (if the slider > 0).

**EMP** (game/PlayerFighter.c ~2416-2450): while the NPC is EMP-disabled (`Player + 0x68`), `+0x12c` (−1, no-op),
`+0x130` and `+0x134` emit; off otherwise and on death.

Where on the ship: exactly as in A.4 (smoke along the ship axis ±250 units around the origin; fire 200..400 units
toward the nose; velocities `−2×` / `−1×` the ship's world velocity). Battleships (idx 14) have a 2× scaled model; if
their reference matrix carries the scale, the offsets double (uncertain).

### B.3 Freighters and battleships (PlayerFixedObject)

No hull-threshold smoke. On destruction (game/PlayerFixedObject.c ~700-770) the Level-owned system Level+0x50
(record 22 SET_EXPLOSION_CARGO) or, for model 0x37a3 / ship 14, Level+0x54 (record 23 SET_EXPLOSION_BATTLESHIP)
is moved onto the wreck (`systemSetMatrix`) and emits while the wreck animation plays; off when it ends (~869).
Scripted exception, campaign index 0x29 in the alien orbit: `LevelScript` puts records 40 SET_SMOKE_VOSSK_FREIGHTER
and 41 SET_EXPLOSION_VOSSK_CARGO (both on Level+0x74, i.e. `sprite_explosion.png` additive, not the smoke texture)
on enemy 0 and turns them on at msg 5.

### B.4 Other records used above

All are sprite records with flags 0x02000021 (per-time emission, random UV mirror) and even spacing (+0x2c = 1).
Sizes in game units, velocities as `k ×` emitter velocity.

| Record | Pool | Size | Life | Rate/s | Colour start → end | Fade-in | Growth/s | Jitter XZ / Y | k | Along dir | UV / frames |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 9 SET_EXPLOSION | 16 | 100 + rnd 1000 | 700 | 8 | FFFFFFFF → FFFFFFFF | 0 | 500 | ±300 / ±300 | +1 | −250..+249 | 4 × 4, 16 frames |
| 11 SET_EXPLOSION_MANUALLY_BIG (manual burst, flag 0x100) | 10 | 2000 + rnd 1000 | 1500 | - | FFFFFFFF → FFFFFFFF | 0 | 500 | 0 | 0 | 0 | 4 × 4, 16 frames |
| 14 SET_SMOKE_PLAYER (unused) | 30 | 666 + rnd 222 | 1500 | 20 | as record 15 | 200 | 2222 | ±200 | −2 | +100..+599 | 4 × 4, 16 |
| 17 SET_EMP_1 | 13 | 200 + rnd 1400 | 400 | 8 | FFFFFFFF → 000000FF | 300 (RGB) | 500 | ±600 / ±300 | +1 | −300..+499 | rect (0.877, 0.252)-(0.997, 0.497), static |
| 18 SET_EMP_2 | 13 | 200 + rnd 1400 | 200 | 8 | FFFFFFFF → 000000FF | 300 (RGB) | 500 | ±600 / ±300 | +1 | −300..+499 | rect (0.752, 0.502)-(0.997, 0.747), static |
| 22 SET_EXPLOSION_CARGO | 1000 | 4000 + rnd 2000 | 1000 | 9 | FFFFFFFF → FFFFFFFF | 0 | 500 | ±3000 / ±800 | +1 | −250..+249 | 4 × 4, 16 |
| 23 SET_EXPLOSION_BATTLESHIP | 16 | 4000 + rnd 1000 | 1000 | 9 | FFFFFFFF → FFFFFFFF | 0 | 500 | ±5000 / ±1500 | +1 | −250..+249 | 4 × 4, 16 |
| 40 SET_SMOKE_VOSSK_FREIGHTER | 30 | 1800 + rnd 300 | 1500 | 20 | FFFFFFFF → FFFFFF00 | 200 | 2222 | ±200 | −2 | +500..+999 | 4 × 4, 16 |
| 41 SET_EXPLOSION_VOSSK_CARGO | 1000 | 4000 + rnd 2000 | 1000 | 9 | FFFFFFFF → FFFFFFFF | 0 | 500 | ±1000 / ±800 | +1 | −4000..+3999 | 4 × 4, 16 |

- The EMP rects are single lightning sprites in `khador_jump.png` (right column); their colour goes white → black on
  RGB (additive, alpha stays 255) times a 300 ms RGB fade-in, i.e. brightness `(1 − age/life) × min(1, age/300)`:
  peak 0.33 at 200 ms for SET_EMP_1, 0.17 at 100 ms for SET_EMP_2.
- Record 9 on the additive `sprite_explosion.png`: constant white, so the atlas does all the fading; k = +1 means the
  flames travel with the ship.

**Unity settings for the damage effects**: NPC smoke / fire = the A.5 systems unchanged, toggled by the 33 % rule
above. Death burn (record 9): lifetime 0.7 s, rate 8/s, max 16, start size 5..55 m, size +25 m/s (size over
lifetime ≈ 1 → 2.2 for the mean 30 m start), Box (30, 30, 25) m, Inherit Velocity Initial ×**+1**, colour constant
white, 4 × 4 sheet over the lifetime, additive One One, `sprite_explosion.png`. EMP (records 17 / 18): lifetime 0.4 /
0.2 s, rate 8/s each, max 13, start size 10..80 m, size +25 m/s, Box (60, 30, 40) m centred 5 m toward the nose,
Inherit Velocity Initial ×+1, colour over lifetime RGB = the brightness curve above (EMP_1 keys 0 → 0, 0.5 → 0.33,
1 → 0; EMP_2 0 → 0, 0.5 → 0.17, 1 → 0; additive, so darker = more transparent), no sheet animation (UV rect of one bolt: Unity sheet with a single fixed
tile, or a material with that UV sub-rect), Flip (0.5, 0.5, 0).
