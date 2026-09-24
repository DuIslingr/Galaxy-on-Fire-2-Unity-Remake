# Special weapons: beams, scatter guns, bombs, mines, cluster missiles, sentries, shock blast, turrets, mods

Follow-up to `weapons.md` (read that first: `Gun` layout, pool, hit test, per-item table, sounds). Everything is in **game units** and **ms** (Unity = (x, y, −z) · 0.05). Addresses use the Ghidra image base 0x10000. **(v)** = read from the decompiled code or the disassembly, **(a)** = assumed or inferred.

The decompiler dropped many float arguments. The values marked "disasm" were read from the ARM code with capstone. The scratch scripts `gdis.py` (function disassembler) and `vt2.py` (vtable resolver through relocations) are not in the repo.

---

## 0. TL;DR

| Weapon | What a shot is | Damage | Detonation |
|---|---|---|---|
| Beam 9/10/11/228 | hitscan on the nearest **auto-aim** target (in the crosshair box, < 60 000 u); no target → a "bullet" parked 30 000 u ahead | direct, attr 9 × damage factor | – |
| Scatter 176–178 | normal bullet (spread 2) with a **distance-scaled hit cube** (×1.5 / 2 / 3) | direct hit **plus** area within attr 14 (linear falloff) to every target, the hit one included | on hit only (no timed burst) |
| EMP bomb 41–43 | 1 slow bomb | **EMP only** (attr 10 · f), ships only (asteroids skipped) | end of life, contact, or **secondary pressed again** |
| Nuke 44–46, Fireworks 232 | 1 slow bomb | attr 9 · f + push; asteroids ×0.6 | same |
| Liberator 179 | 1 **remote-steered** nuke, the camera follows it | 850 · f, radius 25 000 | same (20 s life) |
| Ionizing 197/221 | 1 slow bomb | 5 · f (+ push); **explodes gas clouds into plasma sparks** | same |
| Shock Blast 226 | instant sphere around the ship | 140 · f + EMP 80 · f + NPC push, radius **80 000** | immediately |
| Mines 60–62 | dropped (fwd + up), stop within 500 ms, live 40–60 s | f = (10000 − d)/10000 inside attr 14 | a hostile ship inside 1× its radius (pulled in from 5×) |
| Cluster 214–216 | 3/4/5 homing rockets at once, corkscrewing | direct, each | – |
| Sentry 211–213 | deploys a friendly turret object (max 3) | its own gun (item stats) | destroyed at 0 HP (100) |
| Turrets (cat 8) | a turret on the ship; 180–182 **aim and fire by themselves**, the others only in **turret view** | direct | – |
| Plasma collector 198–200 | turret, turret view only: pulls plasma sparks in and adds them to the cargo | none | – |
| Mods 186/187 | primary reload ×(1 − attr39/100), damage ×(1 + attr40/100) | – | – |

---

## 1. Beam lasers (items 9, 10, 11, 228)

Functions: `Level::createGun` 0xcd220 (projectile table entry −1 → `Gun` N 1 + `BeamGun`), `Gun::shootAt` 0x17d518 (beam branch, `Gun+0x108`), `Gun::update` 0x17e940, `Gun::calcCharacterCollision` 0x17e154, `BeamGun::BeamGun / update / render` 0x1a69a8 / 0x1a6b04 / 0x1a6adc, `Radar::draw` 0x1554fc (the `KIPlayer+0x6f` flag).

### 1.1 Firing (v)

- Gated by the normal reload (`Player::shoot`: `reloadAcc > reload`) **and** by `timer[0] <= 0`. The shot fails while the previous beam's timer runs (the reload accumulator is not reset then).
- Target = the enemy-list entry (`Gun+0xb4` = every KIPlayer of the level, friends included) with `KIPlayer+0x6f` set, active and alive, that is **nearest to the player**.
  - `Radar::draw` sets `+0x6f` each frame for ships **on screen, < 60 000 units away, with the screen position inside ±`Radar+0x124` (= screenWidth/16) of the crosshair**.
  - A second branch sets it for other objects inside a ±24 000 unit cube and inside the crosshair box (probably asteroids and junk) (a).
- With a target: `beamDir = normalize(target − playerPos)`, `bullet.pos = target.pos`, `beamLen = int(|target − playerPos|)`.
- Without a target: `beamDir = ship forward`, `bullet.pos = playerPos + forward·30000` (0x46ea6000), `beamLen = 30000`.
- In both cases: `bullet.vel = ship forward` as a **unit** vector (1 u/ms, not × speed), `timer[0] = lifetime` (attr 12), `+0x4c = +0x4d = 1`, `+0xa9 = 1` (muzzle flash).
- Effective fire interval:
  - Target hit: the hit sets `timer = −1 000 000`, so the interval is **reload** (attr 11 × fire-rate factor).
  - No target: the interval is **max(reload, lifetime)** (M6 A1 2400 ms instead of 1200).

### 1.2 Hit (v)

- The next collision pass tests `|target − bullet + vel| < r` with `|vel| = 1`, so the target is hit **at its centre** on the next frame. Targets with custom collision (`KIPlayer+0x3c`, freighters) test their boxes against the centre instead.
- The hit is a normal direct hit (sort 0 is not an explosive):
  - `damageEmp` if attr 10 exists (the beams have none), `Player::damage(attr9 × damageFactor)`, crosshair "hit" flag;
  - impact mesh `impact_00X_lookat` (weapons.md table) restarted at the target centre and billboarded.
- No-target case: the parked bullet drifts forward at 1 u/ms for `lifetime` ms and hits anything whose cube contains it.
- Asteroids: a direct beam hit does damage (no instant kill).

### 1.3 Visual (v, disasm)

- Mesh: `projectile_009/010/011_anim_add` (14229 + item − 9) or `sn_projectile_228_anim_add` (19090).
  - The mesh is a crossed quad strip **1 unit long along +Z** (sidecar bsphere (0, −0.5, 0) r 353.55 = 250·√2, i.e. ±250 wide, 228: ±125).
  - `AEGeometry::setScaling(1, 1, beamLen)` (disasm 0x1a6ba0: r1 = r2 = 1.0, r3 = beamLen), `setDirection(beamDir, up (0,1,0))`.
- Position every frame: `playerPos + R_ship · mount`. The mount is `Gun+0x7c − (0,0,100)`, i.e. the raw `weapons_hd` primary mount. The beam **follows the mount** but keeps the world direction chosen at fire time.
- Animation: 1033 ms, with position / rotation / scale / `extra` (opacity) channels, restarted on each shot (state 3 → 1), then updated with dt while `Gun+0x4c` is set.
  - Nothing ever clears `+0x4c` for beams, so the mesh stays "visible" and relies on its animation ending at opacity 0 (a). Unity: hide it at the end of the animation.
- Beam muzzle flash: table `DAT_0025d020[item]` (same values as the muzzle table). It sits at the mount, faces the ship's forward with up (0,1,0), and is rewound whenever `+0xa9` is clear (restarts per shot).
- Sound: one-shot per shot (sort 0 does not loop): 9 → 50, 10 → 49, 11 → 50, 228 → 2275 (`DLC2_SFX/M6_A4_RACOON_02.ogg`). The ids 49/50 → `Beam_M6_Coug_v*` / `Beam_M6_Wolv_v*` (51 `Beam_M6_Wulf` is unused, see weapons.md).

| item | name | dmg | reload | life | speed (unused) | mesh | width (u) | muzzle | impact | sound |
|---|---|---|---|---|---|---|---|---|---|---|
| 9 | M6 A1 "Wolf" | 27 | 1200 | 2400 | 20 | projectile_009_anim_add | 500 | muzzle_flash_000 | impact_000 | 50 |
| 10 | M6 A2 "Cougar" | 34 | 1400 | 2600 | 20 | projectile_010_anim_add | 500 | muzzle_flash_003 | impact_003 | 49 |
| 11 | M6 A3 "Wolverine" | 51 | 1500 | 2600 | 20 | projectile_011_anim_add | 500 | muzzle_flash_002 | impact_002 | 50 |
| 228 | M6 A4 "Raccoon" | 120 | 1300 | 2600 | 22 | sn_projectile_228_anim_add | 250 | muzzle_flash_001 | impact_001 | 2275 |

---

## 2. Scatter guns (items 176, 177, 178; sort 25)

Functions: `Level::createGun` (N 25, offset (0,0,400), spread 2), `ObjectGun::ObjectGun` 0x18c020 (one `Explosion` per bullet slot), `ObjectGun::update` 0x18c2ec, `Gun::calcCharacterCollision`, `Explosion::setScaling / start / playSound` 0xb4ee0 / 0xb5478 / 0xb5368.

- **A shot is one ordinary projectile** (`v_projectile_17X_anim_add`, oriented along velocity), spread ±err/200 per axis (err 2 ≈ ±0.6°), speed attr 13, lifetime attr 12. No pellets, no timed burst, no burst at the end of life (v).
- **Proximity fuse** = an enlarged hit cube (v). The half size is the target radius ×
  - 1.5 when the **player→target** distance is ≤ 10 000;
  - 2 when it is 10 001–20 000;
  - 3 beyond 20 000;
  - ×0.5 instead for targets with `KIPlayer+0x6d` (unknown class of object, maybe big / static ones) (a).
- **On a hit** (v):
  1. Direct hit as for any primary: `Player::damage(attr9 × damageFactor)`.
  2. Then `+0x40[i] = 1`, `+0x30[i] = hit point`, and **every target** of the gun (all KIPlayers, asteroids, gas clouds; the directly hit one again) within `d < magnitude` (attr 14) takes `damage·f` and (if attr 10 > 0) `emp·f`, with `f = clamp((mag − d)/mag, 0, 1)`. The directly hit target therefore takes up to about 2× damage. There is no asteroid factor here and no push.
  3. The bullet is removed. No impact mesh (the table entry is −1); the burst explosion replaces it.
- Burst fx (v):
  - `Explosion` type **8** (item 176), **9** (177), **10** (178). All three are the same mesh, `v_scattergun_000_explosion_lookat_anim_add` (16806 / 16807 / 16808), 2 parts, camera-facing, 1033 ms.
  - `start`: random roll `rnd(3141)/1000` rad, scale `0.6 + rnd(40)/100`. `setScaling` for types 8–10 also sets a random animation speed `0.7 + rnd(60)/100` (length ÷ speed).
  - Sound **22** `Garbage_Explosion` (`setWeaponIndex(176..178)` → 22; `DLC_SFX/Flak_Explosion_02.ogg` is not used by the code). No camera rumble (updated without a camera).
  - One explosion object per bullet slot (25), so up to 25 bursts at once.
- Weapon mods apply (primary).

| item | name | dmg | reload | life | speed | range (u) | blast r (attr 14) | burst type | projectile | muzzle | shot sound |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 176 | Nirai .50AS | 13 | 700 | 2000 | 22 | 44 000 | 2800 | 8 | v_projectile_176_anim_add | muzzle_flash_006 | 1111 `DLC_SFX/Nirai50_02` |
| 177 | Berger FlaK 9-9 | 19 | 750 | 2100 | 25 | 52 500 | 4400 | 9 | v_projectile_177_anim_add | muzzle_flash_003 | 1113 `DLC_SFX/Berger_Flak_01` |
| 178 | Icarus Heavy AS | 30 | 900 | 2600 | 28 | 72 800 | 6300 | 10 | v_projectile_178_anim_add | muzzle_flash_002 | 1112 `DLC_SFX/Icarus_Heavy_01` |

---

## 3. Bombs: EMP bombs, nukes, Liberator, Fireworks, Ionizing (sorts 6, 7, 34)

Functions: `Level::createGun` (N 1, offset (0,0,400), `BombGun(…, guided = attr15 == 1)`), `BombGun::BombGun / update / render` 0x170e74 / 0x17116c / 0x171600, `Gun::ignite` 0x17dd08, `Player::shoot(slot, item, …)` 0xb06f0, `PlayerEgo::setRocketControl` 0xae0be, `PlayerEgo::left/right/up/down` 0xacf98 / 0xacd48 / 0xad468 / 0xad1e4, `PlayerEgo::killLiberator` 0xae120, `PlayerEgo::addNukeVolatileForce` 0xa689c, `Explosion::*`.

### 3.1 Firing and "explode when pressed again" (v)

- `Player::shoot` (secondary) loops over **all** secondary guns:
  - Any gun of sort 6 / 7 / 34 whose bomb is out (`timer[0] ≥ 0`) is **ignited** (`Gun::ignite`), **whatever secondary is selected**.
  - Otherwise the first gun of the selected item whose reload has passed fires. For bomb sorts this sets `Level+0x69 = 1` (bomb in flight; cleared by `ignite` for sorts 6/7).
  - So one press of the secondary button either detonates the flying bomb(s) or launches.
- Ammo: −1 per bomb; detonation doesn't cost ammo. The reload (attr 11) equals the lifetime (attr 12) for every bomb, so a new bomb is ready about when the old one would have gone off.
- Flight: straight along the ship's nose at attr 13 u/ms from `mount + (0,0,100)` (the Gun offset (0,0,400) is replaced by `setOffset`), no spread, no homing (the `RocketGun` homing flag is false for `BombGun`).
- Detonation (all call `Gun::ignite`):
  - **end of life**: `timer < 1` (`Gun::update`, sorts 6 / 7 / 34);
  - **contact**: any non-asteroid target in the hit cube (sorts 6 / 7 / 34 / 42 → `ignite`, no direct damage);
  - **second press**.
- **Asteroid contact**: `damage(9999)` (instant kill, sorts 4 / 5 / 6 / 7 / 34 / 40 / 42) and `return` from the collision pass. The bomb (or rocket) is **not consumed** and keeps flying (v; the same holds for rockets and missiles, a correction to weapons.md §3.4).

### 3.2 `Gun::ignite` (v)

```
sort 7: Status+200++ (bombs detonated stat, medal text 1572); sort 6/7: Level+0x69 = 0
Gun+0x88 = 1                                     // "ignited": BombGun starts the explosion
for each target t in the gun's enemy list (sort 6: asteroids skipped):
  if !t.active: continue
  for each bullet i:
    d = |t.pos - bullet[i].pos|
    if d < magnitude (attr 14):
      exploded[i] = 1; explodePos[i] = bullet pos
      f = clamp((mag - d)/mag, 0, 1)            // mines (sort 11): (10000 - d)/10000
      emp = item attr 10
      if sort in {7, 11, 34, 42}:               // nukes, mines, ionizing, shock blast
        if emp present: setEmpForce(f*emp); setBombForce(...)      // push, see 3.6
        if t is asteroid: f *= 0.6
        if damage > 0: Player::damage(t, int(f*damage), friendGun, item)
           ionizing on a gas cloud: PlayerGasCloud::explode(item, pos, magnitude)
           Liberator on an asteroid that dies: Status+0x144++ (medal 0x2c "asteroids in a row with one Liberator", 1596)
        if emp > 0: damageEmp(t, int(f*emp))
        shock blast on a KIPlayer: vtable+0x2c = initPush(pos, magnitude)        // 5.3
      else (sort 6, EMP bombs): damageEmp(t, int(f*emp)) ONLY      // attr 9 (2/2/4) is never applied
      t.hitVector = normalize(t - bullet); bullet timer = -1 (mines: only the one that exploded)
    other sorts: timer[i] = -1
```

- EMP bombs do **no hull damage** and don't affect asteroids. The player is immune to EMP anyway (0 EMP points, ship_combat.md 2.4).
- The player's own ship is not in the gun's enemy list. Self-damage is handled in `BombGun::update` (below).
- Mines: every deployed mine that has any target within its magnitude explodes in the same call (chain).

### 3.3 `BombGun::update` (v)

- Every frame until ignited, it records the bomb position (`+0xf8`; shock blast: the player position).
- After `Gun+0x88` becomes set, once:
  - guided: `LevelScript::resetCamera`, `setRocketControl(null)`, stop sound 1116;
  - `d = |bombPos − playerPos|`;
  - **self-damage, hardcore only**: `f = clamp((mag/2 − d)/(mag/2) · 0.5, 0, 1)` (shock blast ×0.2), `Player::damage(player, int(f · attr9))`;
  - `PlayerEgo::addNukeVolatileForce(x)`: `Player+0x60 += 3x`. `Player+0x60` is the **volatile-cargo instability** (`PlayerEgo::getVolatileForce`, volatile goods), not a combat intensity as weapons.md §3.1 guessed. x is lost in the decompile; probably the same f (a);
  - camera rumble `r0 = 1 − min(d, 30000)/30000`;
  - `Explosion::start(bombPos, dir)` (dir = player forward for the shock blast, else 0).
- Every frame after that: `rumble = r0 · (1 − min(t, 2000)/2000)`. When the explosion stops playing: rumble 0, `+0x88 = 0`, explosion reset (the gun is ready for the next bomb's explosion).

### 3.4 Explosion types and sounds (v)

`BombGun` picks type **7** for sort 6, **11** for sort 42, **13** for item 232, else **0**. `Explosion::playSound` uses the weapon index (`setWeaponIndex`).

| type | meshes | length | scale / speed | sound |
|---|---|---|---|---|
| 0 (nukes, Liberator, ionizing, mines) | `explosion_anim_lookat_alpha` (16821) + child `explosion_anim_lookat_add` (16820), camera-facing | 4500 ms | 1 (no size scaling with the blast radius); **no** fire streaks (`addFireStreaks` isn't called by BombGun / MineGun) | per item, below |
| 7 (EMP bombs; mines with damage 0) | `explosion_emp_anim_lookat_add` (16805), 2 parts | 2000 ms | 1 | per item |
| 8/9/10 (scatter) | see §2 | 1033 ms | random | 22 |
| 11 (shock blast) | `sn_shock_blast_glow_anim_lookat_add` (18996) + `sn_shock_blast_sphere_anim_add` (18995), both `setDirection(playerDir, up (0,1,0))` | 1033 ms at speed ×0.5 = **~2067 ms** | `setScaling(50000)` (disasm 0x170f26). The sphere mesh bsphere is 0.866 (unit cube), so the sphere is ~43 000 u across at full scale (a); the anim scales it | none (the shot sound 2269 is the effect sound) |
| 12 (gas-cloud plasma explosion) | `sn_plasma_explosion_anim_lookat_add` (19070) | 2000 ms | – | – |
| 13 (Fireworks) | `sn_fireworks_lookat_anim_add` (16809), 2 parts | 11 100 ms | `setScaling(0.25)` (disasm 0xb4b6e), anim speed 1.0 | 2279 |

Explosion sounds by item (`playSound`): 41 → 15, 42 → 16, 43 → 17, 44 → 14, 45 → 13, 46 → 12, 60–62 → 22, 176–178 → 22, **179 → 12**, 197 / 221 → 2253, 232 → 2279, 226 → none.

### 3.5 Per-item table (attributes from `item_attributes.json`)

| item | name | sort | dmg (9) | emp (10) | reload (11) | life (12) | speed (13) | range (u) | radius (14) | guided (15) | mesh (+child) | expl. type | launch sound | expl. sound |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 41 | EMP GL I | 6 | (2, unused) | 80 | 6000 | 6000 | 7 | 42 000 | 22 000 | 0 | bomb_emp_a (+_add 14685, anim state 2 = loop) | 7 | 6 | 15 |
| 42 | EMP GL II | 6 | (2) | 150 | 6500 | 6500 | 8 | 52 000 | 30 000 | 0 | bomb_emp_a | 7 | 7 | 16 |
| 43 | EMP GL DX | 6 | (4) | 300 | 5200 | 5200 | 10 | 52 000 | 37 000 | 0 | bomb_emp_a | 7 | 8 | 17 |
| 44 | AMR Tormentor | 7 | 150 | – | 6000 | 6000 | 6 | 36 000 | 20 000 | 0 | bomb_explosive_a (+_add 14681) | 0 | 9 | 14 |
| 45 | AMR Oppressor | 7 | 400 | – | 6500 | 6500 | 7 | 45 500 | 30 000 | 0 | bomb_explosive_a | 0 | 10 | 13 |
| 46 | AMR Extinctor | 7 | 700 | – | 7000 | 7000 | 9 | 63 000 | 40 000 | 0 | bomb_explosive_b (+_add 14683) | 0 | 11 | 12 |
| 179 | Liberator | 7 | 850 | – | 10 000 | 20 000 | 10 | 200 000 | 25 000 | **1** | v_guided_missile_anim (+ `v_guided_missile_add` 14294) | 0 | 1117 | 12 |
| 232 | Fireworks | 7 | 1 | – | 8000 | 8000 | 12 | 96 000 | 20 000 | 0 | sn_fireworks_rocket (no child) | 13 | 2280 | 2279 |
| 197 | Ion Lambda Mk1 | 34 | 5 | 0 | 6000 | 6000 | 6 | 36 000 | 10 000 | 0 | rocket_explosive (+_add, RocketGun) | 0 | 2254 | 2253 |
| 221 | Ion Lambda Mk2 | 34 | 5 | 0 | 6000 | 6000 | 6 | 36 000 | 15 000 | 0 | rocket_explosive | 0 | 2254 | 2253 |

- Launch sound = the shot-sound table (weapons.md): 6–11 `Launch_Missile_EMP_GL*` / `Rocket_Launch_AMR_*`; 12–17 `Explosion_Bomb_AMR_*` / `Explosion_EMP_GL*` (`fmod_event_ids.txt`).
- DLC (name-matched):
  - 1117 `DLC_SFX/Liberator_Launch`, 1116 `DLC_SFX/AMR_Liberator_Engine_02` (loop);
  - 2279 / 2280 `DLC2_SFX/Fireworks`;
  - 2253 `DLC2_SFX/Plasma_Rocket_Explosion`, 2254 `DLC2_SFX/Launch` (a).
- Bomb animation: `bomb_emp_a`'s child plays anim state 2 (loop); for the other bombs the parent plays state 1.
- Particle trails (`RocketGun::update`):
  - sorts 4 / 5 / 40 use the rocket trail system (`Level+0x80`);
  - item 232 uses `Level+0x9c` (fireworks sparks);
  - all others use `Level+0x84`, whose emit is **disabled for the Liberator** (179).
- Ionizing on a gas cloud (`PlayerGasCloud::explode` 0x1a55f0): the cloud bursts into `N = int(((1.5 − d/mag)·130/1.5 + 10) · attr56/100)` plasma sparks (attr 56 = 50 / 100) living 8000–22 000 ms, collected by the plasma collector (§6.5).
- **Outside gas clouds the ionizing missile is just a weak bomb**: 5·f damage + push within 10 000 / 15 000, type-0 explosion, sound 2253.

### 3.6 Push (v, partly a)

- `Player::setBombForce(x)` stores `Player+0xd4`. `PlayerAsteroid::update` translates the asteroid along its hit vector × force and decays the force ×0.98 per frame (0 below 0.05). The x passed by `ignite` is lost in the decompile (a: ≈ f).
- `setEmpForce(f·emp)` → `Player+0xd8`. Fixed objects (`PlayerFixedObject::update`, e.g. freighters) are frozen (don't move forward) while it counts down by dt (> 0.05) (v).
- Fighters are pushed only by the shock blast (§5.3).

### 3.7 Liberator (179): remote steering and camera (v except where noted)

- Attr 15 = 1 makes the `BombGun` guided. On launch (`Gun+0x4d`):
  - restart the missile animation;
  - `PlayerEgo+0x10 = ship matrix` (saved);
  - play **1116** (engine loop).
- Every frame while it flies:
  - A helper `AEGeometry` (`BombGun+0xe8`) takes the missile's matrix at `missilePos + missileDir · 350`.
  - The `TargetFollowCamera` targets it with **camOffset (0, 450, −1400)**, **targetOffset (0, 0, 1700)** and `useTargetsUpVector(false)`.
  - `PlayerEgo::setRocketControl(gun, helper)`: sets `PlayerEgo+0x194` (rocket control) and clears the autopilot / docking fields `+0x15c`, `+0x158`, `+0x160`.
  - The missile animation advances only after the first 500 ms.
  - `banking = PlayerEgo+0x198`; `BombGun+0x20 = banking·0.2` and FMOD parameter 0 of the engine loop = banking·0.2.
  - The camera rumbles at a constant 0.2 while in rocket control (`PlayerEgo::update` 0xaa81c).
- Steering input: while `PlayerEgo+0x194` is set, the ship's turn functions feed the missile instead of the ship.
  - `left/right` → `PlayerEgo+0x80 = ∓input · 0.003 · missileSpeed` and `banking += ±dt · input · 0.01`.
  - `up/down` → `PlayerEgo+0x7c = ±input · 0.003 · missileSpeed`.
  - The ship keeps flying straight on its throttle.
  - **Where +0x7c / +0x80 turn the missile velocity was not found** (no reader in PlayerEgo, Gun, RocketGun, BombGun, MGame or Level; checked through the disassembly) (a). With speed 10 the value is 0.03·input. Implement it as yaw / pitch rates of the missile heading and tune them (suggestion: ≈ 1.5 rad/s at full stick, roll the mesh by the banking).
- Detonation: press the secondary again, contact, or 20 s. Then camera reset, rocket control off, loop stopped, then the type-0 explosion with sound 12.
- `PlayerEgo::killLiberator` (cutscenes): the missile is removed silently (timer −1, position far away, `+0x4c = 0`).
- `Status+0x144` (asteroids killed by this Liberator) is reset on every Liberator launch (`shootAt`).

---

## 4. Mines (items 60, 61, 62; sort 11)

Functions: `Level::createGun` (N 10, speed **2.0** fixed), `MineGun::MineGun / update / render` 0x181a28 / 0x181c8c / 0x181c58, `Gun::shootAt`, `Gun::update`, `Gun::calcCharacterCollision` (mine branch, disasm 0x17e7b2), `Gun::ignite`.

- **Drop** (v):
  - Starts at `mount + (0,0,100)` (secondary mount); direction `normalize(shipFwd + shipUp)` × 2 u/ms.
  - Each mine gets a random spin vector `(rnd(200) − 100)/50` per axis (units not traced: probably rad/s for the mesh tumble) (a).
  - Motion: `pos += vel · dt · max(1 − age/500, 0)`, so it stops after 500 ms, about 500 units from the drop point.
- **Lifetime** attr 12 = 40 / 50 / 60 s. At the end it just disappears (sort 11 doesn't ignite on expiry). Up to 10 alive per gun. Ammo −1 per mine.
- **No arming delay** (v): the mine test runs from the first frame.
- **Targets that trigger** (v): only `Player+0x5c` ships (hostile to the player) that are not `KIPlayer+0x3d`. Asteroids are ignored.
- **Trigger** (v, disasm): each collision pass, for each mine and each such target:
  - Inside the cube `|t − mine + vel| < 5·t.radius`:
    - also inside `1·t.radius` → `ignite`;
    - else **pull**: `vel = normalize(t − mine)`, `mine.pos += vel · 2.0 · 100` (**200 units per frame**, frame-dependent; ≈ 6 u/ms at 30 fps), then the pass returns.
- **Damage** (`ignite`, v):
  - Every target of the gun (all KIPlayers incl. friends, asteroids ×0.6, gas clouds) with `d < attr14` (1000 / 2200 / 5000) takes `int(f·dmg)` and `int(f·emp)`, with **`f = (10000 − d)/10000`** (not radius-based, so f ≥ 0.5 inside the radius) + push.
  - The player is never hit (not in the list).
- **Fx** (v):
  - Mesh = projectile table (`v_mine_001` Saber, `v_mine_003` Neétha, `v_mine_002` Ksann'k) + child mesh id+1 (`_add`, anim state 2 = loop), render scale ×0.7.
  - One `Explosion` per mine: type 0, or type 7 when `Gun damage == 0`. The Neétha has **no attr 9** (missing-attribute sentinel, not 0), so it probably gets type 0 in practice (a).
  - Sound 22 (`Garbage_Explosion`).
  - Camera rumble `1 − min(d,30000)/30000`, fading over 2000 ms.
- Drop sounds (shot table): 60 → 1098 `DLC_SFX/AMR_Claymor_02`, 61 → 1100 `DLC_SFX/Neetha_01`, 62 → 1099 `DLC_SFX/Ksannk_04` (name-matched).

| item | name | dmg | emp | reload | life | radius (14) | mesh |
|---|---|---|---|---|---|---|---|
| 60 | AMR Saber | 350 | – | 1000 | 40 000 | 1000 | v_mine_001 (+_add) |
| 61 | Neétha EMP | – | 500 | 3000 | 50 000 | 2200 | v_mine_003 (+_add) |
| 62 | Ksann'k | 700 | – | 4000 | 60 000 | 5000 | v_mine_002 (+_add) |

---

## 5. Cluster missiles, sentry guns, shock blast, ionizing

### 5.1 Cluster missiles (214, 215, 216; sort 40) (v)

- `Gun` N = item − 211 (3 / 4 / 5); `RocketGun`, homing = true.
- `Gun::shootAt` (sort 40) fires **every free bullet** (timer ≤ −2000) in the same call: same mount, same direction, no spread. Then **one** ammo for the whole salvo.
- `RocketGun::update` sets up the per-bullet matrices / trails of each fired bullet (`Gun+0xa0` counts down).
- Homing: same as missiles (`RocketGun::seekEnemy` 0x18bd70). The **radar-locked** target, if on screen and not in free-look; steer 1/6 of the error per frame. Player rockets have trails, so they home from launch.
- Corkscrew per bullet i: `pos += side·2·sin((age + phase)·0.003)·k + up·2·cos((age + phase)·0.003)·k`, with `age = life − timer`, `phase = life·i/N`, `side = normalize(cross(vel, up_i))`. k was lost; most likely dt (a), which gives a helix radius ≈ 2/0.003 ≈ 670 units.
- Hit: direct damage attr 9 per rocket + particle burst (set 11), no area. Asteroids: 9999 (the rocket continues, §3.1). After their lifetime they coast 2000 ms.

| item | name | rockets | dmg each | reload | life | speed | mesh | sound |
|---|---|---|---|---|---|---|---|---|
| 214 | Shesha | 3 | 60 | 3000 | 8000 | 8 | rocket_explosive (+_add) | 2265 |
| 215 | Garuda-IV | 4 | 75 | 3000 | 10 000 | 9 | rocket_explosive | 2265 |
| 216 | Patala | 5 | 90 | 3000 | 10 000 | 10 | rocket_explosive | 2265 |

2265 → `DLC2_SFX/Launch_02` (a). `Cluster_Explosion_01` exists but no code path plays an explosion for cluster rockets (a).

### 5.2 Sentry guns (211, 212, 213; sort 39)

Functions: `Level::createGun` (Gun N 3, damage 0, speed 2.0; `SentryGun`), `Level::createSentryGuns` 0xcb0d8, `Level::createStaticObject` 0xcda54, `Level::assignGuns` 0xcb638, `SentryGun::update` 0x188942, `PlayerTurret::*` 0x182640…0x1832e8.

- **Level setup** (v): if the ship has any sort-39 item, the level pre-creates **9** `PlayerTurret` static objects (3 per sentry type), stored in `Level+0xb0`.
  - Type = mesh `0x49c0 + i/3` (18880 `sn_sentry_gun_001` / 18881 `_002` / 18882 `_003`, child `_add` 18886–18888, scale 0.5).
  - `Player(radius 1000, HP 100)`, then `setRadius(800)`, `setAlwaysFriend`, max HP **100**, parked at (50000, 50000, 50000), inactive. Name text 1666 "Turret".
- **Deploy** (v):
  - Firing the item (`Gun::shootAt`) is refused while `Level+0x6c` (active sentries, all types together) **> 2**, so **max 3**.
  - The "bullet" is spawned at `shipPos + R·(mount + (0,0,100))` with timer 0. It is not rendered (`SentryGun::render` is empty), and the table's `projectile_012` is irrelevant.
  - `SentryGun::update`: on `+0x4d` it picks the first of its 3 objects (index `3·(item − 211)`) that isn't dying and is inactive or dead, does `Level+0x6c++`, reset, `setPosition(bullet pos)` and activates it.
  - Ammo −1 per deploy.
- **Sentry behaviour** (`PlayerTurret::update` with the sentry flag `+0x3b`) (v):
  - Invulnerable for the first **3000 ms**. No lifetime: it stays until destroyed (0 HP).
  - On death: sound 22, particle burst, type-0 explosion with fire streaks; after **4500 ms** it goes inactive and `Level+0x6c--`. No loot.
  - It doesn't move (no host).
  - **Target**: every 3000 ms (the first pick after 3 s) the nearest target of its enemy list within **50 000** (`+0x160` default, never changed) that is **hostile to the player** (`Player+0x5c`). A target that failed the pitch limits is skipped once (sentries have none).
  - **Aim** (`handleRotation`): the target point is its position + its forward·(lost scalar) (probably a small lead, a). The direction is transformed into the sentry's local frame.
    - If `|x| > 0.05`: yaw by `±dt · 2π/4096` rad (**87.9°/s**).
    - If `|y| > 0.05`: pitch by the same rate, no limit for sentries.
    - When both are within ±0.05: `Player::shoot(slot 0)` with the sentry's matrix.
- **Sentry gun** (`Level::assignGuns`, v):
  - An NPC gun (`setFriendGun`): N 4, projectile look and item index per type, stats from the sentry item (attr 9 / 11 / 12 / 13), muzzle offset (0,0,250) (213: (0,0,300)), `Gun+0xa8 = 1` (always has a muzzle flash).
  - Kills are "by NPC" (a).

| item | name | object mesh | gun look | projectile | sort | dmg | reload | life | speed | range (u) |
|---|---|---|---|---|---|---|---|---|---|---|
| 211 | Berger SG-100 | sn_sentry_gun_001 | item 2 | projectile_002_anim_add (6756) | 0 laser | 9 | 430 | 1000 | 22 | 22 000 |
| 212 | Berger SG-400 | sn_sentry_gun_002 | item 20 | projectile_021_anim_add (6797) | 1 blaster | 11 | 300 | 1000 | 25 | 25 000 |
| 213 | T'Suum | sn_sentry_gun_003 | item 14 | projectile_014_anim_add (6790) | 1 blaster | 14 | 250 | 1000 | 28 | 28 000 |

- Deploy sound 2263 (all three). Name-matched files: `DLC2_SFX/Berger_SG100`, `SentryGun_SG400_02`, `TSuum` (a: these look like per-type sounds, deploy or fire).
- The sentries' own shots go through `Player::shoot`, i.e. the look item's shot sound (54 / 80 / 79) (a).
- Assembled prefabs: `Resources/Assembled/supernova/turrets/sn_sentry_gun_00X`.

### 5.3 Shock Blast (226; sort 42) (v)

- `Gun::Gun(…, lifetime = 1, …)`, speed 0, N 1. `shootAt` does not add the mount offset for sort 42, so the "bullet" sits at the ship centre.
- The next `Gun::update` ignites it: every target within **80 000** takes `int(f·140)` hull damage and `int(f·80)` EMP, with `f = (80000 − d)/80000`, asteroids ×0.6. Every KIPlayer also gets `initPush(center, 80000)`.
- `PlayerFighter::initPush` 0xf3b00: push duration `(1 − min(d/80000, 1))·5000` ms, direction away from the centre, plus a random tumble axis ×0.2. `PlayerFighter::push` 0xf3c50 translates the ship along it with a speed that fades over the duration, and tumbles it.
- `BombGun::update`: explosion type 11 at the **player position**, facing the player's direction. Rumble with d ≈ 0 → full rumble fading over 2 s. Hardcore self-damage `f = 0.5·0.2 = 0.1` → 14.
- Sound: shot sound 2269 → `DLC2_SFX/Shockblast_01` (the explosion itself is silent). Reload 7000, ammo −1.
- Not in the "press again to detonate" mask (it detonates at once anyway).

### 5.4 Ionizing missile (197, 221; sort 34)

See §3: a `BombGun` without guidance, `rocket_explosive` mesh, 6 s life. It explodes at end of life, on contact or on the second press. Area 5·f + push within 10 000 / 15 000; asteroid contact kills (9999). On a **gas cloud** within the radius it calls `PlayerGasCloud::explode` → plasma sparks (§6.5). Gas clouds exist only in Supernova systems.

---

## 6. Player turrets (category 8: 47, 48, 49, 180, 181, 182, 224; plasma collectors 198–200)

Functions:

| Function | Address | Role |
|---|---|---|
| `Level::createPlayer` | 0xbca00 | the turret gun; `setTurretPosition(weaponPos[2][0])` |
| `Level::createGun` | 0xcd220 | turret `Gun` N 15, offsets |
| `PlayerEgo::checkForTurret` | 0xa722c | turret model, speed, auto flag |
| `PlayerEgo::setTurretMode` | 0xa6a48 | enter / leave the turret view |
| `PlayerEgo::handleTurretView` | 0xa791c | the turret camera each frame |
| `PlayerEgo::handleAutoTurret` | 0xa8ae0 | automatic aiming and firing |
| `PlayerEgo::left/right/up/down` | 0xacf98… | turret-view aiming |
| `PlayerEgo::shoot` | 0xa7070 | the fire input in turret view |
| `ObjectGun::update` | 0x18c2ec | turret muzzle flash |
| `MGame::switchCamera` | 0x1ac34c | camera button cycle |
| `MGame::OnTouchEnd` | 0x1a98d8 | auto-turret toggle |
| `PlayerEgo::draw` | 0xae3a0 | crosshair |

### 6.1 Model and mount (v)

- `checkForTurret` (called on `addGun`) runs if the ship has a slot-2 gun. It builds pivot `+0x2c` → {base `+0xdc` (yaw), gun `+0x28` (yaw + pitch, rotation order 2)} at the turret mount `weaponPos[2][0]` (`weapons_hd.json` slotType 2), with `rotate(0, π, 0)` except on the plasma collectors.
- The Unity side already has the assembled prefabs `Resources/Assembled/<pack>/turrets/*_ship_mounted` (pivot → base + gun with the gun offset).

| item | name | auto (attr 16) | turn speed (attr 17) | yaw rate | base / gun meshes | muzzle z | alt. barrels | dmg | reload | life | speed | sound (loop) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 47 | Hammerhead D1 | 0 | 40 | 26°/s | turret_001 / _gun (6770/6771) | 260 | – | 6 | 300 | 2000 | 28 | 92 Turret_Hammerhead_MK1 |
| 48 | Hammerhead D2A2 | 0 | 60 | 40°/s | turret_002 / _gun (6772/6773) | 170 | x ±60 (bullet x ±80) | 10 | 280 | 2500 | 32 | 93 |
| 49 | L'ksaar | 0 | 100 | 66°/s | turret_003 / _gun (6774/6775) | 200 | – | 12 | 250 | 3000 | 32 | 94 |
| 180 | Berger AGT 20mm | **1** | 100 | 66°/s | v_autoturret_001_anim / _gun_anim (6805/6806) | 172 | – | 4 | 100 | 2000 | 32 | 1095 Berger_AGT_01_Loop |
| 181 | Skuld AT XR | **1** | 125 | 82°/s | v_autoturret_002 / _gun (6807/6808) | 190 | x ±35, y ±16.5 (bullet offset z −300!) | 9 | 190 | 2500 | 32 | 1096 Skuld_AT_XR_01_Loop |
| 182 | HH-AT "Archimedes" | **1** | 150 | 99°/s | v_autoturret_003 / _gun (6809/6810) | 150 | – | 8 | 150 | 3000 | 32 | 1097 Turret_HH_AT_Archimedes_03_Loop |
| 224 | Matador TS | 0 | 130 | 86°/s | sn_turret_004 / _gun (+_add, +_gun_add) (18842–18845) | 147 | x ±45, y ±13 | 18 | 200 | 3000 | 32 | 2252 Turret_Matador_TS_01 |
| 198 | PE Proton (collector) | 0 | 100 | 66°/s | sn_plasma_collector_001 (+_add, gun_anim +_add, stream 19071) | 205 | – | 0 | – | – | – | 2255 in turret view |
| 199 | PE Ambipolar-5 | 0 | 150 | 99°/s | sn_plasma_collector_002 (…) | 205 | – | 0 | – | – | – | 2255 |
| 200 | PE Fusion H2 | 0 | 200 | 132°/s | sn_plasma_collector_003 (… + gun_emissive 18800) | 205 | – | 0 | – | – | – | 2255 |

- Turn speed: `PlayerEgo+0x1f8 = int(attr17 · 1.5)`. Yaw per ms = `(dt·input)/(200/speed) · 2π/4096` rad, i.e. `attr17·1.5/200 · 87.9°/s`.
- Muzzle offsets are from `ObjectGun::update` (turret branch; plasma collectors `DAT_0018c748` = 205).
- The muzzle flash sits in the turret gun's frame at `(x, y, z)`. With alternating barrels the x (and for 224 / 181 the y) sign flips on every shot: 48 uses `20 − 80` / `80 − 20`.
- **Bullets** spawn at `turretGunPos + R_turret·offset`. Offsets: `(0,0,300)`, 48 `(80,0,300)`, 181 `(0,0,−300)`. No +100: `setOffset` isn't called for turrets.
  - Alternate barrels (`Gun+0xa4`, items 48 / 181 / 224) mirror the offset's x each shot (a5 for 224 also y). That only changes the position for 48.
- Turret projectiles are camera-facing billboards; 180–182 face along −velocity (weapons.md).
- The sound loops while the turret fires (sort 8) and stops on `stopShooting(2)`.
- Weapon mods don't apply to turrets (only type-0 items are scaled).

### 6.2 Auto turret (180, 181, 182) (v)

- `checkForTurret` sets `PlayerEgo+0x180` (has auto turret). `+0x355` (enabled) starts **on**.
  - The HUD auto-turret button (`MGame` key bit `0xf7 & 0x20`) toggles it with HUD event 0x20 / 0x21 (on / off message; text 37 "Auto fire" is the likely label (a)).
  - `setAutoTurret(false)` also `stopShooting(2)`.
- Runs every frame in `PlayerEgo::update` while enabled and hull > 0. In black-market systems (`+0x354`) only after a 10 000 ms condition (a: 10 s after the level start). At hull 0 it switches itself off.
- **Target**: every 3000 ms the nearest (to the player) level enemy that is `KIPlayer::isEnemy` (hostile), not dead / dying, active and without `KIPlayer+0x70`, within **60 000**. The one that last failed the pitch limits (`+0x190`) is skipped.
- **Aim**: aim point = the target's position + its forward·(lost scalar) (probably a lead, a). Transform it into the turret frame (ship matrix · gun matrix).
  - `|x| > 0.05` → yaw base + gun by `±dt/(200/speed)·2π/4096`.
  - `|y| > 0.05` → pitch the gun by `dt·2π/4096` per ms (87.9°/s, not speed-scaled), accumulator `+0x1a8` limited to **[−500, +70]** (≈ −44° … +6°, a: sign convention).
  - Hitting a limit marks the target "unreachable" and forces a re-pick.
- **Fire**: when both are within ±0.05 → `Player::shoot(slot 2, turret matrix)` (all turret guns on their own reload) and the turret animations advance. After 500 ms without firing → `stopShooting(2)` (stops the loop sound).
- **The auto turret fires independently of the player's primaries**, which keep working normally.

### 6.3 Turret view (manual; every turret incl. auto and collectors) (v)

- **Entering**: the camera button (`MGame` key bit `0xf4 & 0x80` → `switchCamera(cur + 1)`) cycles **0 chase → 1 turret view** (only if the ship has a turret and isn't docking to an asteroid; otherwise skipped) → **3 free look** → 0.
- `setTurretMode(true)`:
  - creates a turret camera: perspective far 300 000 (450 000 in alien orbits), hierarchy pivot `+0x17c` (ship matrix) → `+0x178` (yaw, rotation order 2, translated to the turret, value lost) → `+0x19c` (pitch, offset lost);
  - `stopShooting(0)`;
  - collectors: the plasma stream mesh (19071) becomes visible and sound 2255 loops.
- Refused (`+0x170 == 0 || +0x1e4 != 0 || +0x180 != 0`, or `+0x194` set): no turret, mining minigame running, **auto turret mounted**, or Liberator control. So **auto turrets (180–182) can't enter the turret view**; the view is for the manual turrets (47–49, 224) and the collectors (v).
- In turret view:
  - The ship flies straight: `moveForward(dt · throttle · speed)`, auto-level roll continues, no steering.
  - Stick / keys **aim the turret**:
    - left / right yaw the camera pivot, base and gun by `(dt·input)/(200/speed)·2π/4096` rad (**unlimited 360°**);
    - up / down pitch the gun by `dt·input·2π/4096`, accumulator limited to [−500, +70], and the camera pitch at half that rate, limited to [−250, +70].
  - The camera shakes on hits (1000 ms, ±0.006) and during boost.
  - **Fire** = `PlayerEgo::shoot`: in turret mode it always fires **slot 2** with the turret matrix. Primaries and secondaries can't fire in turret view (`OnTouchEnd` blocks the secondary in turret mode).
  - HUD: crosshair image 0x4c0 / 0x4ce, or for collectors 0x1f5d (plasma in range) / 0x1f5e (not), at `crosshairPos`.
- `Radar::getTurretScopeWidth` (`Radar+0x12c`) is the crosshair box used for spark sighting.

### 6.4 Remake-relevant consequences

- Turrets need: a turret component that places the `_ship_mounted` prefab at the slot-2 mount, yaw / pitch parts, a Gun fed with the turret gun's world matrix, auto-aim (180–182) and a turret camera mode (47–49, 224, 198–200).
- Without a turret view, the manual turrets (47–49, 224) are useless in the remake. The minimum port is the turret view. A remake-only option could let manual turrets auto-aim like 180–182.

### 6.5 Plasma collectors (198, 199, 200; sort 35) (v, brief)

- A turret-slot `Gun` (N 15, damage 0, no projectile, no muzzle) that shows the `sn_plasma_stream_anim_add` child in turret view.
- `Radar::draw` (with a collector mounted):
  - A gas cloud's plasma **spark** is "in sight" when it is on screen, inside the turret scope box around the crosshair, alive and within **attr 51** of the player (27 500 / 50 000 / 60 000).
  - `Radar+0x130` (plasma in range) → crosshair 0x1f5d.
- `PlayerGasCloud::update`: in sight + turret view → the spark moves toward the turret at **attr 49 · dt** (16 / 28 / 32 u/ms).
  - Within **800 units** of the turret (cloud age ≥ 2000 ms): +1 unit of the cloud's plasma item (`PlayerGasCloud+0x15c`) into the cargo, sound 2256, `Hud::catchCargo`; cargo full → the "no space" catch message.
  - The first red plasma after campaign 142 plays radio hint 0x1a (`RED_PLASMA_COLLECTED` voice).
- No firing is needed: aiming in turret view collects. Attr 50 (40 / 80 / 100) was not traced.
- Sparks exist only after an ionizing missile (§3.5) bursts a cloud.
- Sounds 2255 / 2256 → `DLC2_SFX/PlasmaInjector_Loop_03` / `_Init_02` / `_End_01`, `Container_01` (a).

---

## 7. Weapon mods (186, 187; category 28) (v)

- `Ship::refreshValue` 0x1a33f4, case sort 0x1c:
  - `Ship+0x54 = 1 − attr39/100` (fire-rate factor);
  - `Ship+0x58 = 1 + attr40/100` (damage factor);
  - both are reset to 1 first; a later mod overwrites an earlier one (**no stacking**).
- `Level::createPlayer` applies them to **type-0 items only** (all primaries incl. beams and scatter guns): `damage = int(attr9 · 0x58)`, `reload = int(attr11 · 0x54)`.
- Secondaries, turrets and sentry guns are unaffected.
- 186 Nirai Overdrive: attr39 20 / attr40 −10 → reload ×0.8, damage ×0.9. 187 Nirai Overcharge: −10 / 20 → reload ×1.1, damage ×1.2.
- Note the `int()` truncation: damage 3 × 0.9 = 2.

---

## 8. Secondary selection and ammo (v)

- `PlayerEgo+0x10c` = the selected secondary **item index**, persisted in `Status+0xf4`.
- On level start (`MGame::OnInitialize`): keep `Status+0xf4` if that item is still mounted, else select the first secondary slot. `Hud::setCurrentSecondaryWeapon(item)`.
- HUD label (`Hud::updateSecondaryWeaponString`): "<item name> (<amount>)", centred.
- **Switching**:
  - Only through the **HUD quick menu**: menu 0 has "Secondary weapons" (text 266, key 0x200); it opens menu 1, which lists every mounted secondary as "<name> (<amount>)" (keys 0x2000 / 0x4000 / 0x8000 / 0x10000 = slots 0–3).
  - Picking one sets `setCurrentSecondaryWeaponIndex`, closes the menu and resumes the game (the menu pauses sounds).
  - No cycle key.
- **Firing** (`MGame::OnTouchEnd`, secondary key 0x08, on release): not while mining, in turret view, docked to a docking point or landing / taking off.
  - `PlayerEgo::shoot(1)` → `Player::shoot(1, selectedItem)`. The first gun of that item that is off reload fires.
  - If the call reports the selected item empty (`ammo < 1`), the selection becomes −1. There is **no automatic switch to another secondary**; the player must pick one in the menu.
  - `Hud::checkIfQuickMenuIsEmpty` refreshes the menu list and the label after every secondary press.
- **Ammo per type** (`Gun+0x74` = item amount, `Item::changeAmount(−1)` per shot, `Ship::freeSlot(item)` at 0):

| type | cost |
|---|---|
| rockets, missiles | 1 per shot (weapons.md) |
| cluster | 1 per salvo of N |
| bombs (EMP, nukes, Liberator, Fireworks, ionizing) | 1 per launch; the detonation press is free |
| mines | 1 per mine (10 alive per gun) |
| sentry gun | 1 per deploy; refused (no cost) while 3 sentries are active |
| shock blast | 1 per use |
| beams, scatter, turrets, collectors | no ammo (−1) |

- Several mounted stacks of the same item: the first ready gun fires; each gun decrements its own stack (`Gun+0xf4` = equipment slot).

---

## 9. Remake plan

| File / class | Change |
|---|---|
| `Gun.cs` | <ul><li>New kinds: EmpBomb 6, Nuke 7, Turret 8, Mine 11, Ionizing 34, PlasmaCollector 35, Sentry 39, ShockBlast 42, plus an `isBeam` flag (items 9, 10, 11, 228).</li><li>Pool / offset per sort (bomb 1, mine 10, sentry 3, turret 15, cluster item − 211).</li><li>`magnitude` = attr 14.</li><li>Beam branch in `TryFire`: an auto-aim target delegate, the target / 30000 cases, the unit velocity, the timer gate, `BeamLength` / `BeamDir`.</li><li>Cluster salvo (fire all free bullets, one ammo) + corkscrew.</li><li>Mine motion (500 ms deceleration), mine 5× pull (200 u per 33 ms) / 1× trigger on hostile ships only.</li><li>`Ignite()` implementing §3.2 (f formulas, EMP-only for sort 6, ×0.6 asteroids, mine falloff, chain) with an `Ignited(bullet, pos)` event.</li><li>Bombs ignite at end of life and on ship contact.</li><li>Asteroid contact = 9999 **without consuming** rockets / bombs.</li><li>Scatter: distance-scaled cube + direct + area damage.</li><li>A turret fire overload that takes a spawn matrix instead of the ship transform.</li><li>Keep it plain C#.</li></ul> |
| `WeaponSystem.cs` | <ul><li>List of secondary guns grouped by item, `SelectedSecondary` (saved like `Status+0xf4`), `CycleSecondary()` (remake input: e.g. Q / controller D-pad up), the menu API for the HUD.</li><li>`FireSecondary` = ignite every bomb in flight, else fire the selected item.</li><li>Weapon-mod factors on primaries (`Ship` refresh: last mod wins).</li><li>Sentry deploy (max 3, via a `SentryGun` spawner).</li><li>Shock blast.</li><li>Liberator control state (disable ship steering, feed the stick to the missile, restore on detonation).</li><li>Hardcore self-damage and rumble per §3.3.</li><li>Turret setup (hand the slot-2 item to `PlayerTurret`).</li><li>Store ammo for all secondary stacks, not just the first.</li></ul> |
| `GunRig.cs` | <ul><li>Beam renderer: prefab at the mount, `LookRotation(beamDir)`, localScale (1, 1, beamLen · 0.05 / meshLength), anim restart, hide at the end.</li><li>Bomb / mine / guided-missile assembled prefabs (like the rockets).</li><li>Mine scale 0.7 + spin.</li><li>Per-bullet burst explosions for scatter (type 8–10 params).</li><li>Turret muzzle flash in the turret gun's frame with alternating offsets.</li></ul> |
| `Explosion.cs` | Generalize from type 0 to a table: type → prefab(s), camera-facing parts, length, scale, anim speed, sound, debris on/off, rumble on/off (types 0, 7, 8–10, 11, 12, 13; §3.4). Bombs and mines use type 0 **without** debris. |
| `WeaponFx.cs`, `Editor/WeaponBuilder.cs`, `tools/weapons/build_weapon_fx.py` | <ul><li>Explicit DLC sound-name map (§3.5, §4, §5, §6.1) instead of name parsing.</li><li>Per-item explosion type + explosion sound, drop / deploy sounds, beam prefab flag, engine loop (1116) for 179.</li><li>Turret base / gun prefab names; sentry prefab.</li><li>Scatter / bomb explosion prefabs into `CombatAssets`.</li></ul> |
| new `TurretAim.cs` (plain C#) | Yaw / pitch toward a local direction with the ±0.05 dead zone, rates (yaw speed-scaled, pitch 2π/4096 per ms), pitch limits [−500, +70] (none for sentries), fire-when-aligned. Shared by `PlayerTurret` and `SentryGun`; unit-testable. |
| new `PlayerTurret.cs` | On the player ship: instantiate `*_ship_mounted` at the slot-2 mount. Auto mode (180–182): 3 s target pick within 60 000, hostile only; toggle; 500 ms idle stops the loop sound. Turret-view mode (camera button cycle: chase → turret → free look). Stick aims, fire fires slot 2, the ship flies straight. Plasma collectors: spark sighting and pull (once gas clouds exist). |
| new `SentryGun.cs` | Deployed sentry: `Target` (radius 800 × 0.05, HP 100, friendly, invulnerable 3 s), `TurretAim` (no pitch limit), NPC-style `Gun` with the item stats and look (§5.2), 3 s target pick within 50 000 (hostile to the player), death explosion, 4500 ms, slot freed. |
| `ChaseCamera.cs` | Follow an arbitrary target with offsets (Liberator: cam (0, 450, −1400), target (0, 0, 1700), world up, constant rumble 0.2); turret camera mode. |
| `CombatRadar.cs` | Expose beam auto-aim candidates (on screen, < 60 000 u, inside the ±w/16 crosshair box; maybe asteroids within a ±24 000 cube). Plasma-in-range flag. |
| `NpcShip.cs`, `Target.cs` | Shock-blast push (`initPush`: duration, away direction, tumble). Asteroid push from bombs (hit vector × force, ×0.98 per frame). EMP freeze for fixed objects (already partly in `Hitpoints`). |
| `UI/FlightHud.cs` (+ UXML) | <ul><li>Secondary label "<name> (N)" and a secondary picker (touch: the quick menu; keyboard / controller: the cycle key).</li><li>Auto-turret toggle button.</li><li>Camera / turret-view button.</li><li>Turret and plasma crosshairs (0x1f5d / 0x1f5e in `gof2_interface3.png`, rects not in the manifest).</li><li>Liberator HUD (hide the ship HUD parts while steering, a).</li></ul> |
| `Session` / `SaveGame` | The selected secondary item (`Status+0xf4`). Bombs-detonated stat (`Status+200`), Liberator asteroid streak (`Status+0x144`) for medals. |

---

## 10. Corrections to weapons.md found here

- Sentry guns: the projectile table's `projectile_012` is only the invisible deploy bullet. The sentries fire `projectile_002` / `_021` / `_014` (§5.2).
- `Player+0x60` is the volatile-cargo instability (`PlayerEgo::getVolatileForce`), not a combat intensity. Shots add 0.008, damage 0.065, a nearby nuke 3·f.
- EMP bombs apply EMP only (no attr-9 damage, no asteroid effect, no push).
- Rockets, missiles and bombs that kill an asteroid by contact are **not** consumed (the collision pass returns without clearing the bullet).
- Beam mesh scaling is (1, 1, length); the mesh is 1 unit long.
- The EMP-mine explosion type 7 depends on `damage == 0`; the Neétha has no attr 9 (sentinel), so it is probably type 0.

---

## 11. Uncertainties

1. **Liberator steering**: the rates `PlayerEgo+0x7c/+0x80 = ±input·0.003·speed` are stored, but the code that turns the missile was not found. The turn model, units and the missile's banking visuals are assumptions.
2. `setBombForce` argument (push strength) and `addNukeVolatileForce` argument were lost (assumed ≈ f).
3. Cluster corkscrew factor k (assumed dt → helix radius ≈ 670 u).
4. Turret / sentry aim point = target position + forward · (lost scalar): probably a lead distance.
5. Pitch accumulator units and sign for turrets: `[−500, +70]` × 2π/4096 rad; which side is "up" was not checked visually.
6. Black-market auto-turret delay: the 64-bit comparison is read as "≥ 10 000 ms since the level start".
7. `KIPlayer+0x6d` (scatter radius ×0.5), `+0x3d` (mine-immune), `+0x70` (auto-turret-immune): named by use only.
8. Beam auto-aim on non-ship objects (the ±24 000 cube branch of `Radar::draw`).
9. Beam visibility after the animation (`Gun+0x4c` is never cleared for beams).
10. Shock-blast sphere world size (scale 50 000 × a unit mesh + its own scale keys) and the exact `initPush` translation speed (partly lost floats).
11. Mine spin units; the Neétha explosion type.
12. All DLC sound ids (1095–1118, 2252–2280) are name-matched guesses. In particular 2263 (sentry) vs the three sentry files, 2265 (cluster), 2253 / 2254 (ionizing), 2255 / 2256 (plasma collector), and whether sentry shots use 54 / 80 / 79.
13. Plasma collector attr 50 and the spark → item mapping per cloud colour (`PlayerGasCloud+0x15c`) were not traced.
14. The turret-view camera offsets (`+0x178` / `+0x19c` translations) were lost in the decompile. Read them from the disassembly of `setTurretMode` before building the turret camera.
