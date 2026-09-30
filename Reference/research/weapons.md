# Player weapons: guns, projectiles, secondaries, hits, fx, sounds, HUD

How the original fires the player's weapons, decoded from the native code. Everything is in **game units** and **milliseconds** unless noted (Unity: 1 unit = 0.05 m). Addresses use the Ghidra image base 0x10000.

Helper scripts used (scratchpad, not in the repo): table dumps via pyelftools on `libgof2hdaa.so`, capstone for lost floats, `img.py` for Image2D rects (rule from `mainmenu_notes.md`).

---

## 0. TL;DR for the Unity implementation

- One `Gun` object per **equipped weapon item**, sitting on **one mount** (`weapons_hd.json`). A gun owns a fixed **pool of N bullets** (20 lasers/blasters/thermo, 25 auto-cannon/scatter, 15 turret, 5 rockets/missiles, 1 bomb, 10 mines).
- **Primary fire**: while the fire input is held, *every* primary gun fires independently as soon as its own reload timer passes `loadingTime` (attr 11 × fireRateFactor). All guns fire together on the first frame, then each at its own rate. One bullet per shot per gun.
- Bullet: spawned at `shipPos + R·(mount + (0,0,100))`, velocity = `R·forward · speed` (attr 13, **units per ms**), no inheritance of ship velocity, no convergence, no aim assist (except beams / homing thermo & missiles).
- **"Range" (attr 12) is the bullet lifetime in ms**, not a distance. Travel distance = attr12 × attr13 units (Nirai EX1: 2000 ms × 20 u/ms = 40 000 u = 2 km).
- Hit test each frame: **axis-aligned cube** `|target − bullet + vel|` < target radius on all three axes (`Player+0x40`). No ray/segment test (fast bullets can tunnel through small targets, like the original).
- Direct hit: `damage = int(attr9 × damageFactor)` → shield, overflow to armor, overflow to hull; plus EMP damage attr 10. Bullet disappears, **impact mesh** (`impact_*_lookat`) plays at the hit point, camera-facing. Crosshair turns orange for 200 ms.
- Visual: projectile mesh oriented along velocity (lasers, auto-cannons, scatter) or camera-facing billboard (blasters, thermo, turrets); **shrinks linearly over its last 1000 ms** (`scale = timer/1000`). Muzzle flash mesh at the mount, restarted each shot.
- Rockets (cat 4) fly straight; missiles (cat 5), cluster missiles (40) and **thermo guns (cat 3)** home on the **radar-locked target** (steer 1/6 of the error per frame). Locking = keep the target inside the crosshair box for `timeToLock` ms (scanner attr 29, 8000 ms without scanner).
- Asteroids: primary hits subtract damage from HP (`scale·100 + 30`); **any direct rocket/missile/bomb hit kills an asteroid instantly** (damage 9999).

---

## 1. Classes and functions

Class tree (`CLASS_HIERARCHY.txt`): `AbstractGun` ← `ObjectGun` ← `RocketGun` ← `BombGun`; `ObjectGun` ← `MineGun`, `SentryGun`; `AbstractGun` ← `BeamGun`, `SpriteGun` (empty stub). The `*Gun` classes are **renderers/controllers**; the simulation lives in a separate plain class **`Gun`** (0x114 bytes) that each of them owns at `+0x08`.

| Function | Address | Role |
|---|---|---|
| `Level::createPlayer` | 0xbca00 | builds the player's guns from the equipped items (see §2) |
| `Level::createGun` | 0xcd220 | item → `Gun` + renderer class, per item category ("sort") |
| `Level::assignGuns` | 0xcb638 | NPC guns (not the player; see §11) |
| `Level::connectPlayers` | 0xcc330 | fills the player's enemy list (= what player bullets can hit) |
| `FileRead::loadWeaponPositions` | 0x1467b0 | reads `weapons_hd.bin` → `weaponPos[type][]` |
| `Ship::getSlotPos` | 0x1a3f8c | index of an item within its slot type → mount index |
| `Gun::Gun` | 0x17cf18 | pool arrays, fields (layout below) |
| `Gun::setIndex` | 0x17d258 | item index, EMP attr 10, impact meshes (table 0x259220) |
| `Gun::setOffset(Vector*)` | 0x17d398 | mount = weaponPos + (0,0,**100**) |
| `Gun::shootAt` / `Gun::shoot` | 0x17d518 / 0x17dcb4 | spawn one bullet (or beam hit) |
| `Gun::update` | 0x17e940 | reload timers, bullet motion, lifetime, collision |
| `Gun::calcCharacterCollision` | 0x17e154 | hit test + damage + impact fx |
| `Gun::ignite` | 0x17dd08 | area damage (bombs, mines, scatter bursts, ionizing missile) |
| `Gun::render` | 0x17eb9c | draws impact meshes |
| `Gun::calcLevelCollision` | 0x17e93c | **empty** (no collision with level geometry) |
| `ObjectGun::ObjectGun / update / render` | 0x18c020 / 0x18c2ec / 0x18c770 | projectile mesh, muzzle flash (table 0x259ab8) |
| `RocketGun::RocketGun / setRadar / update / seekEnemy` | 0x18b150 / 0x18b2b0 / 0x18b600 / 0x18bd70 | trails, homing |
| `BeamGun::BeamGun / update / render` | 0x1a69a8 / 0x1a6b04 / 0x1a6adc | M6 beam lasers |
| `BombGun::BombGun / update` | 0x170e74 / 0x17116c | EMP bombs, nukes, Liberator, shock blast |
| `MineGun::MineGun / update` | 0x181a28 / 0x181c8c | mines |
| `Player::shoot(int slot, …, Matrix)` | 0xb04b4 | fires every ready gun of a slot type (primary/turret) |
| `Player::shoot(int slot, int itemIdx, …)` | 0xb06f0 | fires ONE ready secondary of the selected item |
| `Player::playShootSound / stopShootSound` | 0xb03f0 / 0xb03a0 | shot sounds (table 0x252310) |
| `Player::damage` / `Player::damageEmp` | 0xafa70 / 0xaf834 | shield → armor → hull; EMP points |
| `PlayerEgo::shoot(dt, slot)` | 0xa7070 | entry point from the input code |
| `PlayerEgo::update` (crosshair part) | 0xa8ed0 | crosshair screen position |
| `PlayerEgo::draw` | 0xae3a0 | crosshair drawing |
| `Radar::draw` | 0x1554fc | target markers, under-crosshair flags, lock-on |
| `MGame::OnUpdate` / `OnTouchBegin` / `OnTouchEnd` | 0x1ac778 / 0x1a838c / 0x1a98d8 | fire input |
| `Explosion::Explosion / start / playSound` | 0xb4a90 / 0xb5478 / 0xb5368 | explosion meshes and sounds |
| `PlayerAsteroid::update / collide` | 0xf7060 / 0xf7498 | asteroid death, hit box |
| `TargetFollowCamera::hitSmall` | 0x187b6c | small camera kick on every player shot |

### `Gun` field layout (the parts that matter)

| Offset | Meaning |
|---|---|
| +0x04 | owner `Player*` (set on each shot) |
| +0x08 / +0x0c | bullet count N / positions[N] (inactive = (50000, 50000, 50000)) |
| +0x18 | velocities[N] (units/ms; beams: unit direction) |
| +0x24 | up vectors[N] (ship up at fire time, for orienting the mesh) |
| +0x30 / +0x40 | explosion positions[N] / "exploded" flags[N] (area weapons) |
| +0x3c | per-bullet **timer** (ms). Set to `+0x44` on fire, −dt per frame. Initial / "dead" value −1 000 000 (0xfff0bdc0) |
| +0x44 | **lifetime** = item attr 12 ("range") |
| +0x48 | **reload** = attr 11 × fireRateFactor |
| +0x4c / +0x4d | "any bullet active" / "just fired" |
| +0x50 | **speed** = float(attr 13), units per ms |
| +0x58 / +0x5c | item index / item sort (category id) |
| +0x60 / +0x64 | damage (attr 9 × damageFactor) / EMP damage (attr 10) |
| +0x6c | reload accumulator (+= dt; gun may fire when `> +0x48`; starts full, so the first shot is instant) |
| +0x70, +0xa9 | ms since last shot; "recently fired" flag, cleared when +0x70 ≥ reload (drives muzzle flash) |
| +0x74 | ammo (secondary item amount; −1 for primaries) |
| +0x7c | mount offset (ship-local) |
| +0x8c / +0x90 | beam length / beam direction |
| +0xa4/+0xa5/+0xa6/+0xa7 | alternate-barrel flags (mirror X / Y on every other shot; only turrets 48, 181, 224) |
| +0xb0 | shot sound pitch (`pitchAllPrimaryGuns`) |
| +0xb4 | enemy list (`Array<Player*>`) = everything the bullets can hit |
| +0xf0 / +0xf9 | player gun / friend (NPC) gun |
| +0xf4 | equipment slot index of the item (ammo bookkeeping) |
| +0xfc | error magnitude (spread), percent-ish (§3.3) |
| +0x100 | magnitude = attr 14 (blast radius for area weapons) |
| +0x108 | beam flag (items 9, 10, 11, 228) |
| +0x10c/+0x110 | impact mesh transforms[N] / random bool per bullet |

---

## 2. Building the player's guns (`Level::createPlayer` 0xbca00)

For every equipped item with `Item::isWeapon`:

```
ammo   = (item.type == 1 /*secondary*/) ? item.amount : -1
damage = attr9;  reload = attr11
if item.type == 0 /*primary*/:
    damage = int(attr9 * Ship::getDamageFactor)        // Ship+0x58 = 1 + attr40/100 of a Weapon Mod (sort 28), else 1
    reload = int(attr11 * Ship::getFireRateFactor)     // Ship+0x54 = 1 - attr39/100, else 1
    (dead branch: if damage <= 9 and damageFactor < 0 -> reload*factor*0.7, damage unscaled)
gun = createGun(itemIndex, equipSlot, sort, ammo, damage, reload, range=attr12, speed=attr13)
gun.magnitude = attr14
type 2 (turret): PlayerEgo::setTurretPosition(weaponPos[2][0])
type 0/1:        gun.setOffset(weaponPos[type][Ship::getSlotPos(item)])     // + (0,0,100)
```

Weapon mods: Nirai Overdrive (186) attr39 = 20, attr40 = −10 → reload ×0.8, damage ×0.9. Nirai Overcharge (187) attr39 = −10, attr40 = 20 → reload ×1.1, damage ×1.2. Only primaries are affected.

`Ship::getSlotPos(item)` = position of the item in the equipment list minus the slot counts of the lower types, i.e. the n-th primary uses the n-th primary mount.

`weapons_hd.bin` (`FileRead::loadWeaponPositions`): per entry `type, x, y, z` as int16 → engine vector `(x, z, −y)` (= `position_engine` in `weapons_hd.json`). Types: **0 primary, 1 secondary, 2 turret**, and **type 3 is not a turret**: type-3 entries carry 3 extra floats and are stored as (position, scale) pairs; `createPlayer` turns each pair into an empty `AEGeometry` (`Level+0xa4`). On Betty they sit at the tail (engine z −256/−282, the engine mesh is at z ≈ −466), so they are probably engine exhaust / trail anchors. The JSON field name `turretAngles` is misleading (it is a scale).

Engine space: ship nose = **+Z** (Betty: primary mount (219, −22, 26), engine_add bounding sphere at z ≈ −466). The muzzle offset `+100` is along +Z (forward).

### `Level::createGun` 0xcd220: sort → classes

`count` = bullet pool size N; offset = default mount (overwritten by `setOffset` for the player); error = `setErrorMagnitudePercentage`.

| Sort (category) | Gun ctor | Renderer | Notes |
|---|---|---|---|
| 0 Laser, 1 Blaster | N 20 | `ObjectGun(mesh, 1000)` | items 9, 10, 11, 228 (projectile table = −1): N 1 + **`BeamGun`** |
| 3 Thermo | N 20, offset (0,0,300), **error 20** | **`RocketGun`**, homing = **true**, type 0 | thermo projectiles home (§6) and get particle trails |
| 2 Auto-cannon, 25 Scatter gun | N 25, offset (0,0,400), **error 2** | `ObjectGun` | scatter: one burst `Explosion` per bullet (§3.6) |
| 4 Rocket, 5 Missile | N 5 | `RocketGun`, homing = (sort == 5) | preload shot sound |
| 40 Cluster missile | N = item − 211 (3/4/5) | `RocketGun`, homing = true | all ready bullets fired at once, corkscrew |
| 6 EMP bomb, 7 Nuke, 34 Ionizing missile | N 1, offset (0,0,400) | `BombGun`, guided = (attr15 == 1) | Liberator (179) is the guided one |
| 42 Shock Blast | N 1 | `BombGun` type 0x2a | |
| 8 Turret, 35 Plasma collector | N 15, offset (0/80, 0, ±300) | `ObjectGun` | alternating barrels: items 48, 181, 224 |
| 11 Mine | N 10, speed 2.0 | `MineGun` | |
| 39 Sentry gun | N 3, speed 2.0 | `SentryGun` | max 3 deployed (`Level+0x6c`) |

`PlayerEgo::addGun(array, slotType)` → `Player::addGun` stores guns in `Player+0[slotType]` (0 primary, 1 secondary, 2 turret).

---

## 3. Primary guns

### 3.1 Input → shot

- `MGame::OnUpdate` 0x1ac778: while `Hud::firePressed()` (Hud key bit 0x10) or `MGame+0x108` (finger held on the free screen area, set in `OnTouchBegin`) or `MGame+0x5c` (double tap within 250 ms, `OnTouchBegin`), call `PlayerEgo::shoot(dt, 0)`. On release: `PlayerEgo::stopShooting(0)` (stops looping sounds).
- `PlayerEgo::shoot` 0xa7070: only if alive and not in turret mode (turret mode fires slot 2 with the turret matrix instead). → `Player::shoot(slot 0, ship matrix)`.
- `Player::shoot` 0xb04b4 (needs `Player+0xc3` shooting enabled): **for every gun of the slot**: if `gun.reloadAcc(+0x6c) > gun.reload(+0x48)` → `Gun::shootAt`; on success reset `+0x6c = 0`, play the shot sound, `Player+0x60 += 0.008` (combat-intensity value that decays 0.025/s; probably drives combat music).
- So **all primaries fire simultaneously on the first frame and then each at its own rate**. There is no alternation between mounts (except the alternating-barrel turrets). A shot can only happen on a frame, so the real interval is `reload` rounded up to the frame time.

### 3.2 `Gun::shootAt` 0x17d518 (non-beam)

```
if player gun: item = equipment[slot]; if item == null or item.amount == 0: fail
free = first bullet i with timer[i] <= (sort in {4,5,40} ? -2000 : 0)      // else no shot
pos[i] = shipPos + R * offset            // offset = mount + (0,0,100); alt-barrel mirroring for turrets
if sort == 11 (mine): dir = fwd + up; random spin vector (rnd(200)-100)/50 per axis
else:                 dir = R * (0,0,1)                              // ship forward (MatrixGetDir)
dir += R * gun.deviation(+0xe4)          // 0 for player guns
up[i] = R * up
if err > 0: dir.xyz += rnd(int(err)) * 0.01 - err * 0.005      // each axis, uniform in [-err/200, +err/200)
vel[i] = normalize(dir) * speed          // units per ms
timer[i] = lifetime (+0x44)              // sentry guns: 0
flags: +0x4c = +0x4d = +0xa9 = 1; +0x6c = +0x70 = 0
player gun: TargetFollowCamera::hitSmall()   // tiny camera kick (flag, 50, 2)
secondary: ammo--, Item::changeAmount(-1); at 0 -> Ship::freeSlot(item)
```

Spread in degrees: auto-cannon / scatter (err 2) ±0.01 per axis ≈ ±0.6°; thermo (err 20) ±0.1 per axis ≈ ±5.7°. Lasers and blasters have no spread.

There is **no aim assist and no lead**: bullets fly parallel to the ship's nose from their mounts. The crosshair is the screen projection of `shipPos + forward · 22000` (0x46abe000), i.e. where the bullets are after 22 000 units.

### 3.3 `Gun::update` 0x17e940 (per frame, dt ms)

```
reloadAcc += dt
if recentlyFired: sinceShot += dt; if sinceShot >= reload: recentlyFired = 0
update impact-mesh animations
if any bullet active and sort != 39:
    calcCharacterCollision()
    for each bullet i:
        limit = (sort in {4,5,40}) ? -2000 : 0
        if timer[i] > limit:
            timer[i] -= dt
            if sort == 11: pos += vel*dt * max(1 - (lifetime - timer)/500, 0)   // mines stop within 0.5 s
            else:          pos += vel*dt
            if timer[i] < 1:
                if sort in {6, 7, 34}: ignite()                  // bombs explode at end of life
                if timer <= -2000 and sort in {4,5,40}: Status+300 = 0   // "rockets missed" medal counter
            if sort == 42: ignite()                                // shock blast every frame
        else:
            pos[i] = (50000, 50000, 50000); vel[i] = 0            // inactive
```

- **Lifetime = attr 12 ms**; distance = attr12 × attr13.
- Rockets/missiles keep moving (and can still hit) for **2000 ms after their lifetime**; their pool slot is reusable only then. The render scale `timer/1000` goes negative in that window (see §3.5); the RocketGun trail fades over the same 2000 ms.
- Bullets are in world space; `Gun::translate` shifts them when the level recentres (floating origin).

### 3.4 Hit test and damage (`Gun::calcCharacterCollision` 0x17e154)

Targets = `Gun+0xb4`. For the player this is **all KIPlayers of the level (`Level+0xf8`, including friends/neutrals), asteroids (`Level+0xfc`) and gas clouds (`Level+0xf4`)** (`Level::connectPlayers` 0xcc330 → `Player::setEnemies/addEnemies` → every gun). Stations/static geometry are not hit (`calcLevelCollision` is empty).

For each active, alive target (`Player::isActive`, HP > 0) and each bullet:

```
r = target.radius (Player+0x40)                 // asteroid: meshRadius * scale * 0.7
if mine: r *= 5, and only enemies (Player+0x5c) that are not KIPlayer+0x3d
if scatter gun (sort 25) and target not KIPlayer+0x6d:   // proximity fuse, by distance player->target
    r *= 1.5 (d <= 10000) / 2 (10000 < d <= 20000) / 3 (d > 20000)
    (targets with KIPlayer+0x6d: r *= 0.5)
d = targetPos - bulletPos + bulletVel
hit = |d.x| < r and |d.y| < r and |d.z| < r                // axis-aligned cube, no ray test
KIPlayers with KIPlayer+0x3c set use their own virtual collide(bulletPos) instead (mesh/complex hulls)
```

On a hit:

| Target / weapon | Effect |
|---|---|
| Asteroid, rocket/missile/cluster/bomb/ionizing (sorts 4, 5, 6, 7, 34, 40, 42) | `setBombForce`, **`damage(9999)`** → instant kill (medal 0x29 counter for rockets) |
| Asteroid, mine | ignored |
| Bomb-type (6, 7, 34, 42) or mine on a non-asteroid | `ignite()` (area damage, §7) |
| Anything else (all primary guns, rockets on ships) | direct hit, below |

Direct hit:

```
if gun.emp != missing: Player::damageEmp(target, emp)          // attr 10
dmg = gun.damage                                               // attr9 * damageFactor
    (x0.75 if the target is the player docked to a docking point; x0.2 for some NPC-vs-player cases)
Player::damage(target, dmg, friendGun=false, itemIndex)
target+0x54 = 1 (was hit);  Level+0x30 = 1 if player gun (crosshair "hit" image, §9)
setHitVector; timer[i] = -1000000 (bullet gone); owner-last-hit = target
rockets/missiles/cluster: ParticleSystemManager::emitManual(Level+0x74, system Level+0x3c = set 11
    SET_EXPLOSION_MANUALLY_BIG, pos, dir)                        // rocket impact burst
others: impact mesh i: SetAnimationState(3) then (1) (restart), placed at the bullet with the
    camera's rotation (billboard, the meshes are "_lookat")
scatter gun: explosion at the bullet + area damage to every target within magnitude (attr 14),
    falloff (mag - d)/mag, damage and EMP
```

`Player::damage` 0xafa70: `shield(+0x88, float) -= dmg`; the overflow goes to armor (`+0x8c`), then to hull HP (`+0x78`). Flags `+0x64/+0x65/+0x66` = shield/armor/hull was hit. `Player+0x60 += 0.065`. Hitting non-hostile ships adds to `Player+0x6c` "damage done by player": at 33 % of max HP (10 % hardcore) the ship turns hostile, at 50 % (25 %) standing/signature penalty, at 66 % (40 %) all friends of that race are alarmed. `Player::damageEmp` 0xaf834 lowers EMP points (`+0x7c`); at 0 the ship is disabled (`Player+0x68`).

### 3.5 Projectile rendering (`ObjectGun` 0x18c020 / 0x18c770)

- One transform with the projectile mesh (table 0x252d1c), drawn once per active bullet (position ≠ 50000).
- **Orientation**:
  - Lasers (0), auto-cannons (2), scatter (25), rockets: forward = velocity, up = the bullet's stored up vector (player) or (0,1,0) (NPC).
  - **Blasters (1), thermo (3), turrets (8)** (`ObjectGun+0x4c = (0x85 >> (sort−1)) & 1`): camera-facing billboard (camera right/up, facing the camera). Turret items 180–182 face along −velocity instead of the camera.
- **Scale**: `timer < 1000` → uniform scale `timer / 1000` (projectiles shrink to nothing during their last second). On "iPad" builds, blaster/thermo/turret projectiles are ×0.6; mines always ×0.7.
- Mesh sizes (bounding-sphere radius from the `.gof2mesh.json` sidecars, units): laser streaks ~1500–2300 (the streak runs ~2600 u along the axis, offset ~1300 from the origin), blasters ~500–1300, auto-cannon ~400–560, thermo ~330–860, `rocket_explosive` 175, `rocket_emp` 185.

### 3.6 Muzzle flash, impact, scatter burst

- **Muzzle flash** (table 0x259ab8, player guns only; not for mines): an `AEGeometry` at `shipPos + R·(mount)` (the mount itself, i.e. offset minus the 100), facing the ship's forward with the camera's up (turrets: turret matrix + per-item barrel offsets). It is drawn while `Gun+0xa9` ("fired within the last reload period") is set and its animation is rewound whenever it is not, so the flash animation restarts with each shot. Animation lengths: muzzle_flash_000 100–466 ms, _001 566, _002/_003 533–966, _004 366–966, _005 266, _006–_008 133 ms (two parts each, `extra` channel = opacity).
- **Impact** (table 0x259220): one `impact_*_lookat` instance per bullet, restarted at the hit point, billboarded to the camera. Animation 466 ms (impact_000/002–005), 600 ms (001), 733 ms (006).
- **Scatter burst**: `Explosion` type 10 (Icarus 178), 9 (FlaK 177), 8 (Nirai .50 176) = `v_scattergun_000_explosion_lookat_anim_add` (16806–16808, same model), 1033 ms, random roll 0..3.14 rad, random scale 0.6–0.99, sound 0x16.
- Rockets have no muzzle flash or impact mesh; they use the particle burst above.

### 3.7 Beam lasers (M6 A1–A3 = items 9, 10, 11; M6 A4 "Raccoon" = 228)

`Gun::shootAt` beam branch (flag `+0x108`), gated by the normal reload and by `timer[0] <= 0`:

```
target = nearest (distance to the player) enemy with KIPlayer+0x6f set, active and alive
        // +0x6f is set by Radar::draw: target on screen, < 60000 units away and inside the
        // crosshair box (+-Radar+0x124 = screenWidth/16 px)
if target: beamDir = normalize(target - playerPos); bullet pos = target pos; beamLen = distance
else:      beamDir = forward; bullet pos = playerPos + forward*30000; beamLen = 30000
timer[0] = lifetime; bullet vel = forward (unit)
```

So beams are **hitscan with auto-aim**: anything under the crosshair box within 60 000 units is hit on the next collision pass. `BeamGun::update`: beam mesh `projectile_009/010/011_anim_add` (14229+idx−9) or `sn_projectile_228_anim_add` (19090), scaled by `beamLen`, direction `beamDir`, positioned at the mount; animation restarted on each shot (1033 ms, with an opacity channel). Beam muzzle flash from table 0x25d020 (same values as the muzzle table).

### 3.8 Sounds

`Player::playShootSound(itemIndex, sort, pos, pitch)` plays FMOD event `DAT_00252310[itemIndex]` (3D at the ship position when the 3D-sound option is on). Sorts **2 (auto-cannon), 3 (thermo), 8 (turret)** are **looping** events: if already playing only the position is updated, and `stopShooting` stops them. All others are one-shots per shot. NPC guns use `DAT_002526c0[race]` = 52, 55, 54, 53, 61, 61, 61, 61, 61, 62 (Void), 2276.

---

## 4. Tables per item

`dist` = attr12 × attr13 (units); `dps` = damage × 1000 / loadingTime (per gun, before factors). Meshes are `Assets/Prefabs/<pack>/fx/<name>.prefab` (single-mesh prefabs; `Models/<pack>/fx/<name>.fbx`); rockets/bombs are in `…/misc/` and have assembled prefabs (`rocket_explosive`, `rocket_emp`, `bomb_*`, `v_mine_*`, `v_guided_missile_anim`). Sound = FMOD event id and name from `fmod_event_ids.txt` (ids ≥ 1000 are DLC events, see §5).

| idx | name | dmg | emp | reload ms | life ms | speed u/ms | dist | dps | projectile | muzzle | impact | sound |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | Nirai Impulse EX 1 | 3 |  | 400 | 2000 | 20 | 40000 | 7.5 | projectile_000_anim_add | muzzle_flash_000_anim_add | impact_000_lookat_anim_add | 52 Laser_Nirai_Impulse_EX1 |
| 1 | Nirai Impulse EX 2 | 5 |  | 400 | 2000 | 22 | 44000 | 12.5 | projectile_001_anim_add | muzzle_flash_000_anim_add | impact_000_lookat_anim_add | 53 Laser_Nirai_Impulse_EX2 |
| 2 | Nirai Charged Pulse | 6 |  | 380 | 2000 | 20 | 40000 | 15.8 | projectile_002_anim_add | muzzle_flash_000_anim_add | impact_000_lookat_anim_add | 54 Laser_Nirai_Charged_Impulse |
| 3 | V'skorr | 7 |  | 500 | 2000 | 20 | 40000 | 14.0 | projectile_003_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 56 Laser_Vskorr |
| 4 | Sh'koom | 10 |  | 600 | 2000 | 20 | 40000 | 16.7 | projectile_004_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 55 Laser_Shkoom |
| 5 | Berger Focus I | 16 |  | 900 | 2200 | 22 | 48400 | 17.8 | projectile_005_anim_add | muzzle_flash_002_anim_add | impact_002_lookat_anim_add | 57 Laser_Berger_Focus_I |
| 6 | Berger Focus II A1 | 17 |  | 850 | 2200 | 24 | 52800 | 20.0 | projectile_006_anim_add | muzzle_flash_002_anim_add | impact_002_lookat_anim_add | 58 Laser_Berger_Focus_2 |
| 7 | Berger Retribution | 18 |  | 750 | 2200 | 23 | 50600 | 24.0 | projectile_007_anim_add | muzzle_flash_003_anim_add | impact_003_lookat_anim_add | 59 Laser_Berger_Focus_Retribution |
| 8 | Berger Converge IV | 28 |  | 850 | 2000 | 22 | 44000 | 32.9 | projectile_008_anim_add | muzzle_flash_003_anim_add | impact_003_lookat_anim_add | 60 Laser_Berger_Focus_Converge |
| 9 | M6 A1 "Wolf" | 27 |  | 1200 | 2400 | 20 | beam | 22.5 | beam projectile_009_anim_add | muzzle_flash_000_anim_add | impact_000_lookat_anim_add | 50 Beam_M6_Wolv (?) |
| 10 | M6 A2 "Cougar" | 34 |  | 1400 | 2600 | 20 | beam | 24.3 | beam projectile_010_anim_add | muzzle_flash_003_anim_add | impact_003_lookat_anim_add | 49 Beam_M6_Coug |
| 11 | M6 A3 "Wolverine" | 51 |  | 1500 | 2600 | 20 | beam | 34.0 | beam projectile_011_anim_add | muzzle_flash_002_anim_add | impact_002_lookat_anim_add | 50 Beam_M6_Wolv |
| 12 | N'saan | 8 |  | 600 | 1500 | 14 | 21000 | 13.3 | projectile_012_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 78 Blaster_Nsaan |
| 13 | K'booskk | 8 |  | 530 | 1500 | 14 | 21000 | 15.1 | projectile_013_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 75 Blaster_Kbooskk |
| 14 | Sh'gaal | 9 |  | 430 | 1000 | 17 | 17000 | 20.9 | projectile_014_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 79 Blaster_Shgaal |
| 15 | H'nookk | 9 |  | 330 | 1500 | 16 | 24000 | 27.3 | projectile_015_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 77 Blaster_Hnookk |
| 16 | Luna EMP Mk I | 0 | 3 | 350 | 1200 | 17 | 20400 | 0 | projectile_016_anim_add | muzzle_flash_004_anim_add | impact_004_lookat_anim_add | 72 Blaster_EMP_Luna |
| 17 | Sol EMP Mk II | 0 | 5 | 450 | 2000 | 15 | 30000 | 0 | projectile_017_anim_add | muzzle_flash_004_anim_add | impact_004_lookat_anim_add | 73 Blaster_EMP_Sol |
| 18 | Dia EMP Mk III | 0 | 8 | 450 | 2000 | 17 | 34000 | 0 | projectile_018_anim_add | muzzle_flash_004_anim_add | impact_004_lookat_anim_add | 74 Blaster_EMP_Dia |
| 19 | Gram Blaster | 12 |  | 300 | 1400 | 17 | 23800 | 40.0 | projectile_019_anim_add | muzzle_flash_005_anim_add | impact_005_lookat_anim_add | 76 Blaster_Gram |
| 20 | Ridil Blaster | 12 |  | 250 | 1000 | 18 | 18000 | 48.0 | projectile_020_anim_add | muzzle_flash_005_anim_add | impact_005_lookat_anim_add | 80 Blaster_Ridil |
| 21 | Tyrfing Blaster | 13 |  | 220 | 1000 | 19 | 19000 | 59.1 | projectile_021_anim_add | muzzle_flash_005_anim_add | impact_005_lookat_anim_add | 81 Blaster_Tyrfing |
| 22 | Micro Gun MK I | 2 |  | 220 | 1000 | 18 | 18000 | 9.1 | projectile_022_anim_add | muzzle_flash_006_anim_add | impact_006_lookat_anim_add | 66 Canon_Microgun_MK1 (loop) |
| 23 | Micro Gun MKII | 2 |  | 170 | 1000 | 20 | 20000 | 11.8 | projectile_023_anim_add | muzzle_flash_006_anim_add | impact_006_lookat_anim_add | 67 Canon_Microgun_MK2 (loop) |
| 24 | 64MJ Railgun | 2 |  | 140 | 1200 | 22 | 26400 | 14.3 | projectile_024_anim_add | muzzle_flash_007_anim_add | impact_006_lookat_anim_add | 63 Canon_64MJ_Multirail → Canon_Microgun_64MJ_02.ogg (loop) |
| 25 | 128MJ Railgun | 3 |  | 120 | 1400 | 26 | 36400 | 25.0 | projectile_025_anim_add | muzzle_flash_007_anim_add | impact_006_lookat_anim_add | 64 Canon_128MJ_Multirail → Canon_Microgun_128MJ_02b.ogg (loop) |
| 26 | Scram Cannon | 2 |  | 100 | 1400 | 28 | 39200 | 20.0 | projectile_026_anim_add | muzzle_flash_008_anim_add | impact_006_lookat_anim_add | 68 Canon_Scram (loop) |
| 27 | Mass Driver MD 10 | 4 |  | 90 | 1400 | 30 | 42000 | 44.4 | projectile_027_anim_add | muzzle_flash_008_anim_add | impact_006_lookat_anim_add | 65 Canon_MassDriver (loop) |
| 28 | Thermic o5 | 3 |  | 300 | 2000 | 12 | 24000 | 10.0 | projectile_028_anim_add | muzzle_flash_006_anim_add | impact_006_lookat_anim_add | 69 Thermalfusion_Thermic_o5 (loop) |
| 29 | ReHeat o10 | 4 |  | 170 | 2000 | 14 | 28000 | 23.5 | projectile_029_anim_add | muzzle_flash_005_anim_add | impact_005_lookat_anim_add | 70 Thermalfusion_Thermic_ReHeat (loop) |
| 30 | MaxHeat o20 | 5 |  | 150 | 2000 | 16 | 32000 | 33.3 | projectile_030_anim_add | muzzle_flash_002_anim_add | impact_002_lookat_anim_add | 71 Thermalfusion_Thermic_MaxHeat (loop) |
| 31 | G'liissk | 60 |  | 1200 | 1200 | 12 | 14400 | | rocket_explosive | - | - | 82 Launch_Missile_Gliissk |
| 32 | Jet Rocket | 70 |  | 900 | 1200 | 14 | 16800 | | rocket_explosive | - | - | 83 Launch_Missle_JetRocket |
| 33 | Amour Rocket | 72 | 34 | 2000 | 1000 | 16 | 16000 | | rocket_explosive | - | - | 84 Launch_Missile_Amour |
| 34 | EMP Rocket Mk I | 10 | 45 | 1000 | 1000 | 18 | 18000 | | rocket_explosive | - | - | 85 Launch_Missile_EMP_MK1 |
| 35 | EMP Rocket Mk II | 30 | 60 | 1000 | 1000 | 20 | 20000 | | rocket_explosive | - | - | 86 Launch_Missile_EMP_MK2 |
| 36 | Edo | 70 |  | 2000 | 6000 | 8 | 48000 | | rocket_emp | - | - | 87 Launch_Missile_Edo |
| 37 | Intelli Jet | 100 | 50 | 3000 | 8000 | 18 | 144000 | | rocket_emp | - | - | 88 Launch_Missile_IntelliJet |
| 38 | S'koonn | 140 |  | 3000 | 8000 | 10 | 80000 | | rocket_emp | - | - | 89 Launch_Missile_Skoonn |
| 39 | Mamba EMP | 0 | 100 | 3000 | 10000 | 15 | 150000 | | rocket_emp | - | - | 90 Launch_Missile_Mamba |
| 40 | Dephase EMP | 120 | 100 | 3000 | 10000 | 17 | 170000 | | rocket_emp | - | - | 91 Launch_Missile_Dephase |
| 41 | EMP GL I | 2 | 80 | 6000 | 6000 | 7 | 42000 | | bomb_emp_a (+_add) | - | - | 6 Launch_Missile_EMP_GL1 / expl 15 |
| 42 | EMP GL II | 2 | 150 | 6500 | 6500 | 8 | 52000 | | bomb_emp_a | - | - | 7 / expl 16 |
| 43 | EMP GL DX | 4 | 300 | 5200 | 5200 | 10 | 52000 | | bomb_emp_a | - | - | 8 / expl 17 |
| 44 | AMR Tormentor | 150 |  | 6000 | 6000 | 6 | 36000 | | bomb_explosive_a (+_add) | - | - | 9 Rocket_Launch_AMR_Tormentor / expl 14 |
| 45 | AMR Oppressor | 400 |  | 6500 | 6500 | 7 | 45500 | | bomb_explosive_a | - | - | 10 / expl 13 |
| 46 | AMR Extinctor | 700 |  | 7000 | 7000 | 9 | 63000 | | bomb_explosive_b (+_add) | - | - | 11 / expl 12 |
| 47 | Hammerhead D1 | 6 |  | 300 | 2000 | 28 | 56000 | 20.0 | projectile_016_anim_add | muzzle_flash_003_anim_add | impact_003_lookat_anim_add | 92 Turret_Hammerhead_MK1 (loop) |
| 48 | Hammerhead D2A2 | 10 |  | 280 | 2500 | 32 | 80000 | 35.7 | projectile_021_anim_add | muzzle_flash_005_anim_add | impact_005_lookat_anim_add | 93 Turret_Hammerhead_MK2 (loop) |
| 49 | L'ksaar | 12 |  | 250 | 3000 | 32 | 96000 | 48.0 | projectile_013_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 94 Turret_Hammerhead_Lksaar (loop) |
| 60 | AMR Saber (mine) | 350 |  | 1000 | 40000 | 2 | | | v_mine_001 | - | - | 1098 (DLC) / expl 0x16 |
| 61 | Neétha EMP (mine) |  | 500 | 3000 | 50000 | 2 | | | v_mine_003 | - | - | 1100 (DLC) / expl 0x16 |
| 62 | Ksann'k (mine) | 700 |  | 4000 | 60000 | 2 | | | v_mine_002 | - | - | 1099 (DLC) / expl 0x16 |
| 176 | Nirai .50AS | 13 |  | 700 | 2000 | 22 | 44000 | 18.6 | v_projectile_176_anim_add | muzzle_flash_006_anim_add | - (burst type 8) | 1111 (DLC) |
| 177 | Berger FlaK 9-9 | 19 |  | 750 | 2100 | 25 | 52500 | 25.3 | v_projectile_177_anim_add | muzzle_flash_003_anim_add | - (burst type 9) | 1113 (DLC) |
| 178 | Icarus Heavy AS | 30 |  | 900 | 2600 | 28 | 72800 | 33.3 | v_projectile_178_anim_add | muzzle_flash_002_anim_add | - (burst type 10) | 1112 (DLC) |
| 179 | Liberator (guided nuke) | 850 |  | 10000 | 20000 | 10 | 200000 | | v_guided_missile_anim (+_add) | - | - | 1117 (DLC), engine loop 1116 |
| 180 | Berger AGT 20mm | 4 |  | 100 | 2000 | 32 | 64000 | 40.0 | v_projectile_180_anim_add | v_muzzle_flash_009_anim_add | impact_000_lookat_anim_add | 1095 (DLC, loop) |
| 181 | Skuld AT XR | 9 |  | 190 | 2500 | 32 | 80000 | 47.4 | v_projectile_181_anim_add | v_muzzle_flash_010_anim_add | impact_000_lookat_anim_add | 1096 (DLC, loop) |
| 182 | HH-AT "Archimedes" | 8 |  | 150 | 3000 | 32 | 96000 | 53.3 | projectile_023_anim_add | muzzle_flash_006_anim_add | impact_000_lookat_anim_add | 1097 (DLC, loop) |
| 183 | Disruptor Laser | 18 |  | 300 | 2000 | 28 | 56000 | 60.0 | v_projectile_183_anim_add | muzzle_flash_003_anim_add | impact_003_lookat_anim_add | 1101 (DLC) |
| 193 | SunFire o50 (thermo) | 5 |  | 120 | 2200 | 17 | 37400 | 41.7 | v_projectile_193_anim_add | muzzle_flash_000_anim_add | impact_000_lookat_anim_add | 1118 (DLC, loop) |
| 197 | Ion Lambda Mk1 | 5 | 0 | 6000 | 6000 | 6 | 36000 | | rocket_explosive | - | impact_000_lookat_anim_add | 2254 (DLC) / expl 2253 |
| 211–213 | Berger SG-100 / SG-400 / T'Suum (sentry) | 9/11/14 |  | 430/300/250 | 1000 | 22/25/28 | | | projectile_012_anim_add | - | - | 2263 (DLC) |
| 214 | Shesha (cluster) | 60 |  | 3000 | 8000 | 8 | 64000 | | rocket_explosive ×3 | - | - | 2265 (DLC) |
| 215 | Garuda-IV (cluster) | 75 |  | 3000 | 10000 | 9 | 90000 | | rocket_explosive ×4 | - | - | 2265 |
| 216 | Patala (cluster) | 90 |  | 3000 | 10000 | 10 | 100000 | | rocket_explosive ×5 | - | - | 2265 |
| 221 | Ion Lambda Mk2 | 5 | 0 | 6000 | 6000 | 6 | 36000 | | rocket_explosive | - | impact_000_lookat_anim_add | 2254 / expl 2253 |
| 224 | Matador TS (turret) | 18 |  | 200 | 3000 | 32 | 96000 | 90.0 | projectile_020_anim_add | muzzle_flash_005_anim_add | impact_000_lookat_anim_add | 2252 (DLC, loop) |
| 226 | Shock Blast | 140 | 80 | 7000 | 7000 | 0 | | | (none, `Explosion` type 11) | - | - | 2269 (DLC) |
| 228 | M6 A4 "Raccoon" | 120 |  | 1300 | 2600 | 22 | beam | 92.3 | beam sn_projectile_228_anim_add | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 2275 (DLC) |
| 229 | Dark Matter Laser | 60 |  | 680 | 2000 | 24 | 48000 | 88.2 | sn_projectile_229_anim_alpha | muzzle_flash_001_anim_add | impact_001_lookat_anim_add | 2276 (DLC) |
| 230 | Mass Driver MD 12 | 7 |  | 100 | 1500 | 30 | 45000 | 70.0 | projectile_027_anim_add | muzzle_flash_008_anim_add | impact_006_lookat_anim_add | 2278 (DLC, loop) |
| 231 | Mimung Blaster | 16 |  | 230 | 1000 | 20 | 20000 | 69.6 | sn_projectile_231_anim_add | muzzle_flash_002_anim_add | impact_002_lookat_anim_add | 2277 (DLC) |
| 232 | Fireworks (nuke sort) | 1 |  | 8000 | 8000 | 12 | 96000 | | sn_fireworks_rocket | - | - | 2280 (DLC) / expl 2279 |

Magnitude (attr 14, blast radius in units): EMP GL 22000/30000/37000, AMR 20000/30000/40000, Liberator 25000, Fireworks 20000, Ionizing 10000/15000, Shock Blast 80000, scatter 2800/4400/6300, mines 1000/2200/5000.

Table addresses: projectile mesh `DAT_00252d1c[item]`, muzzle `DAT_00259ab8[item]`, impact `DAT_00259220[item]`, shot sound `DAT_00252310[item]` (preload copy `DAT_002530c0`, same values), beam muzzle `DAT_0025d020[item]`. Plasma collectors (198–200) have −1 everywhere.

---

## 5. Sounds (FMOD event ids)

| Event | id | .ogg (via `fmod_event_ids.txt`, or name-matched for DLC) |
|---|---|---|
| Shot, per item | table above | |
| Target lock acquired | 26 (0x1a) | SFX_SPACE/Target_Lock_v08.ogg (name-matched; the id file lists no file) |
| EMP GL explosions | 15/16/17 | Explosion_EMP_GL1_01 / GL2 / GLDX_01 |
| AMR nuke explosions | 14 Tormentor, 13 Oppressor, 12 Extinctor (and Liberator 179) | Explosion_Bomb_AMR_* |
| Mines, scatter bursts, junk | 22 (0x16) Garbage_Explosion | Garbage_Explosion_01/02 |
| Ship destroyed | 18/19 (random) Destruction_Ship_Big/Mid, 20 Small | |
| Asteroid destroyed (explosion types 2–5) | 21 Destruction_Asteroid | SFX_SPACE/Destruction_Asteroid.ogg |
| Player hit (from `PlayerEgo::update`) | 25 shield, 23 armor, 24 hull | Incoming_Fire_* |

DLC event ids (not in `fmod_event_ids.txt`; name-matched guesses, verify by ear): 1095 → DLC_SFX/Berger_AGT_01_Loop, 1096 → Skuld_AT_XR_01_Loop, 1097 → Turret_HH_AT_Archimedes_03_Loop, 1098 → AMR_Claymor_02, 1099 → Ksannk_04, 1100 → Neetha_01, 1101 → Laser_Disruptor_03, 1111 → Nirai50_02, 1112 → Icarus_Heavy_01, 1113 → Berger_Flak_01, 1116 (0x45c, Liberator flight loop) → AMR_Liberator_Engine_02, 1117 → Liberator_Launch, 1118 → Sunfire_01; 2252 → DLC2_SFX/Turret_Matador_TS_01, 2253 (ionizing explosion) → Plasma_Rocket_Explosion or Explosion, 2254 (ionizing launch) → Launch / Launch_02, 2263 → Berger_SG100 / SentryGun_SG400_02 / TSuum, 2265 (cluster) → Launch_02 (+ Cluster_Explosion_01), 2269 → Shockblast_01, 2275 → M6_A4_RACOON_02, 2276 → DarkMatterLaser_04, 2277 → Blaster_Mimung_2, 2278 → Canon_Massdriver_MD12, 2279 (fireworks burst) / 2280 (launch) → Fireworks. DLC_SFX/Flak_Explosion_02 exists but the scatter burst plays 0x16.

No dedicated "bullet hits hull" sound exists in the gun code for NPC targets; only the explosion/destruction sounds above and the player's own incoming-fire sounds.

---

## 6. Secondary weapons: rockets and missiles

### Firing

- Secondary button (Hud key bit 0x08) fires on **touch end** (`MGame::OnTouchEnd` 0x1a98d8), only if `Player::gunAvailable(1)`, not mining/turret mode/docking/landing. → `PlayerEgo::shoot(dt, 1)` → `Player::shoot(1, selectedItemIndex = PlayerEgo+0x10c, …)`.
- `Player::shoot` 0xb06f0 walks the secondary guns: bombs (sorts 6, 7, 34) that already have a bomb out (`timer ≥ 0`) are **detonated** (`Gun::ignite`) instead; otherwise the **first** gun whose item index matches and whose reload has passed fires one shot, and the loop stops. One missile per press.
- **Ammo = item amount**: each shot `ammo--` and `Item::changeAmount(−1)`; at 0 the item is removed (`Ship::freeSlot`). Cluster missiles consume one ammo for the whole salvo.
- Reload gate = attr 11 (not scaled by weapon mods). Bullet pool: 5 rockets alive at once per gun.
- Start position/direction as primaries (mount + (0,0,100), ship forward, no spread).

### Flight (`RocketGun::update` 0x18b600, `Gun::update`)

- Speed attr 13 (units/ms), lifetime attr 12 ms, then 2000 ms "coast" (still moving and colliding) before the slot is freed.
- **Rockets (sort 4)**: straight line, no homing.
- **Missiles (sort 5), cluster missiles (40), thermo guns (sort 3, SunFire 193)**: homing. Condition each frame: `homing && (perBulletTrailsExist || timer < lifetime − 1000)`. The player's rockets/thermo always have per-bullet trails, so they **home from launch** (the 1 s straight phase only applies to NPC types without trails).
- `RocketGun::seekEnemy` 0x18bd70 (player): target = **radar-locked enemy** (`Radar+4`), only if it is on screen (`KIPlayer+0x72`), not flagged `+0x70`, and the player is not in free-look. No lock → flies straight.
  ```
  desired = normalize(targetPos - bulletPos)
  cur     = normalize(vel)
  vel     = normalize(cur + (desired - cur) / (0.3 * 20)) * speed     // 1/6 of the error per FRAME
  ```
  This is per frame, not dt-scaled (the original ran at ~30 fps). For Unity use `t = 1 − (5/6)^(dt/33.3)` to stay frame-rate independent.
- **Cluster missiles**: fire N (3/4/5) at once; each gets a corkscrew offset `pos += side * 2·sin((age + phase)·0.003)·k + up * 2·cos((age + phase)·0.003)·k` with `age = lifetime − timer`, `phase = lifetime·i/N`, `side = normalize(cross(dir, up))` (the scalar `k` was lost by the decompiler, probably dt).
- Mesh: `rocket_explosive` (14247) for rockets/cluster/ionizing, `rocket_emp` (14249) for missiles, each with its `_add` flame child (14248 / 14250). Oriented along velocity.
- Trails: particle set **39** per rocket (flags 0x12b012, 29 particles, size 100 + 125·?, lifetime 3000 ms, white → transparent, sprite UV (0.752, 0.498)–(0.998, 0.002)); thermo per-bullet sets **25–28** (items 28, 29, 30, 193; 25 particles, size 50/100/150/70, lifetime 1000 ms, white → transparent, different sprite cells). Trail rendering stops 2000 ms after the rocket dies.
  Decoded further (remake `RocketTrail`): flag 2 = a **mesh** system (`ParticleSystemManager::addSystem`), 0x10 = one
  new section per +0x28 units flown (125 for set 39, 50 for 25-28), the sections a ring of +0xc (29 / 25), flags
  0x1000 | 0x2000 two quad strips, 0x20000 turned 45 deg (edges at ±size·0.707·(up ± right) = ±size), 0x100000 UV
  scrolling (set 39 only; record 2's flags, which 25-28 copy, are 0x2b012). The UV rects are particles.png's vertical
  strips (white smoke, gold / red / purple), so the trail is a ribbon along the flight. Cluster missiles (sort 40) take
  set 25 (`setRadar`), SunFire 193 set 28 on Level+0x98; other RocketGun sorts one set-12 SET_MISSILE_TRAIL system.

### Impact

- Ships: direct damage attr 9 (+ EMP attr 10), `emitManual` of particle set 11 `SET_EXPLOSION_MANUALLY_BIG` (10 sprites, size 2000 + rnd(1000), lifetime 1500 ms, white) at the hit point. No area damage for rockets/missiles.
- Asteroids: instant kill (9999 damage).
- No explosion on timeout (a missed rocket just disappears).

### Other secondaries (brief)

- **Bombs** (EMP GL 41–43 → `Explosion` type 7 `explosion_emp_anim_lookat_add`, 2000 ms; AMR 44–46 and Liberator → type 0 ship explosion `explosion_anim_lookat_alpha/_add`, 4500 ms; Fireworks → type 13; Shock Blast → type 11 `sn_shock_blast_sphere/glow`): fly straight, explode at end of lifetime or when the button is pressed again. `Gun::ignite`: every target within `magnitude` takes `damage·f` and `emp·f` with `f = clamp((mag − d)/mag, 0, 1)` (×0.6 on asteroids), plus a push (`setBombForce`). The player's own ship takes `damage·clamp((mag/2 − d)/(mag/2)·0.5, 0, 1)` in hardcore mode; camera rumble `1 − min(d, 30000)/30000` fading over 2000 ms. Liberator (attr 15 = 1) is remote-steered with the camera following it (`PlayerEgo::setRocketControl`).
- **Mines** (60–62): dropped with `fwd + up` direction at speed 2, stop within 500 ms, live 40–60 s. Inside 5 × target radius (enemies only) the mine is pulled toward the target (its velocity is re-aimed at the target each frame); inside 1 × radius it ignites: area damage within magnitude with falloff `(10000 − d)/10000`; `Explosion` type 0 (type 7 for the EMP mine).
- **Ionizing missile** (197, 221): `BombGun`; explodes at end of life; on gas clouds it calls `PlayerGasCloud::explode` with the magnitude.

---

## 7. Asteroid hits (for testing without NPCs)

From this file plus `space_props.md`:

- `PlayerAsteroid` = `Player(1500, 30)`, max HP = `scale·100 + 30`, no shield/armor, radius = `meshRadius·scale·0.7` (asteroid_01 mesh radius 3547). Hit box = the same axis-aligned cube (`PlayerAsteroid::collide` 0xf7498 uses the same test).
- Primary hits: `HP −= damage` (EMP damage is also applied but asteroids have no EMP points). The asteroid records a "hit wobble" (`+0x158 = 0.1`, `+0x15c = 0.001`) whenever its HP drops (use not found in this class).
- Rockets/missiles/bombs (direct hit): `damage(9999)` → dead. Area weapons: `damage·f·0.6` and a push along the hit vector.
- **HP ≤ 0** (`PlayerAsteroid::update` 0xf7060): state 3, `Level::asteroidDied`, stat `Status+0xd8`++, loot crate chance (4 % for class-A, 20 % otherwise; ore or ore core, amount 1 for A else 1–3), then `Explosion(type = asteroidType + 2)` starts at the asteroid's matrix, scaled by the asteroid scale. The asteroid mesh is hidden while the explosion renders; when it finishes, state 4 (inactive).
- Explosion meshes: type 2 `asteroid_explosion_anim_alpha` (16915) + `asteroid_01_explosion_anim` (16913, 17 debris parts); type 3 void: 16915 + `asteroid_void_explosion_anim` (16925); type 4 ice: `v_asteroid_ice_explosion_anim_alpha` + `_anim` (16909/16908); type 5 magma: `sn_asteroid_magma_explosion_anim_alpha` + `_anim` (18841/18840). Animations ≈ 10 000–10 050 ms. Assembled prefabs: `asteroid_01_explosion_anim`, `asteroid_void_explosion_anim`, `v_asteroid_ice_explosion_anim`, `sn_asteroid_magma_explosion_anim` (`Prefabs/Assembled/<pack>/fx/`). Sound 21 `Destruction_Asteroid`.

---

## 8. Lock-on (`Radar::Radar` 0x1545e0, `Radar::draw` 0x1554fc)

- Crosshair box half-size `Radar+0x124 = screenWidth / 16` px.
- Each frame, for every on-screen, alive KIPlayer: `+0x72` = on screen; `+0x6f` = within 60 000 units and its screen position inside the box (beam auto-aim); `+0x71` = inside the box (lock candidate).
- Candidate `Radar+8` = a target inside the box (switching candidate resets the timer). `Radar+0x194 += dt` while a candidate exists, else 0. When it exceeds `timeToLock` (`Radar+0x1b4` = scanner attr 29: Quickscan 4000, Ecoscan 3000, Proscan/Ultrascan 1800; **8000 ms without a scanner**; tractor-beam targets use `Radar+0x1b0` = attr 24): `Radar+4 = candidate` (locked), sound 26 Target_Lock. The lock is dropped when the target dies.
- `Radar::drawCurrentLock` 0x158548 draws the locked target's info panel (image 0x4c4, name/race texts).

---

## 9. HUD images (`Textures/textures/gof2_interface.png`, rect = x, y, w, h in px)

| Image id | Rect | Use |
|---|---|---|
| 0x4c0 (1216) | 339, 814, 40, 40 | **crosshair**, blue ring (`PlayerEgo+0x23c`), drawn centred at `crosshairPos` |
| 0x4ce (1230) | 339, 856, 40, 40 | crosshair **hit**, orange ring (`+0x240`), shown when `Level+0x30` (player bullet hit) for 200 ms |
| 0x1f5e / 0x1f5d | gof2_interface3.png (rank 55/54, not in the manifest region list) | plasma-collector turret crosshair out of / in range |
| 0x4cc / 0x4cd / 0x4cb | 1011,91 / 1011,104 / 1011,78, 11×11 | target dot: enemy red / friend green / neutral yellow |
| 0x4c8 / 0x4ca / 0x4c9 | 137,957 / 233,1002 / 933,632, 21×21 | ring marker for the locked target: enemy red / friend green / neutral yellow |
| 0x4db / 0x4d2 / 0x4dc | 425,768 / 382,768 / 468,768, 41×41 | lock brackets around the locked target: enemy / friend / neutral |
| 0x4f2 | 511, 768, 41, 41 | white brackets (other object types) |
| 0x4f1 / 0x4f0 / 0x4ef | 146,1008 13×13 / 256,1002 21×21 / 137,980 15×12 | small white dot / cyan ring / cyan arrow (waypoints, off-screen) |
| 0x4d4 (fill) / 0x4d3 (frame) | 953,152 34×2 / 581,247 36×4 | target hull bar, green (`Player::getDamageRate` % of 34 px) |
| 0x4d9 / 0x4da | 953,156 / 505,247 | same, red variant |
| 0x4d6 / 0x4d5 | 959,244 / 619,247 | same, yellow variant |
| 0x4d7 / 0x4d8 | 959,240 / 543,247 | EMP bar (white fill, blue frame), shown when EMP < max |
| 0x4c4 | 1, 850, 204, 28 | lock info panel |
| 0x548 | 505, 199, 82, 43 | throttle/speed gauge (`PlayerEgo+0x238`) |

Crosshair position: touch mode = screen projection of `shipPos + shipForward·22000`; mouse mode = mouse position clamped to ±70 % of the half screen, which also steers the ship.

---

## 10. Touch controls (brief)

- Primary: hold a finger on the free screen area (`MGame+0x108`), or the Hud fire button (key bit 0x10) where the layout has one; a double tap within 250 ms also latches fire (`MGame+0x5c`). Firing stops on release, when docking to a planet, or when dead.
- Secondary: tap the secondary-weapon button (key bit 0x08); it fires on release. The Hud quick menu selects the active secondary (`Hud::setCurrentSecondaryWeapon`, `PlayerEgo+0x10c`).
- `Hud::setAutofireEnabled` exists (`Hud+0x43c`) but has no callers in this binary.

---

## 11. NPC guns (for later)

`Level::assignGuns` 0xcb638: every enemy ship gets `Gun(count 4, lifetime 3000, reload 600 − 2·campaignMission, speed 16, or 28 for some mission types)`, damage from player level/difficulty; projectile mesh by race (0 → projectile_000, 1 → 003, 2 → 007, 3 → 026, 9 → 005, 10 → sn_229, others → 019). Rocket-armed NPCs: speed 8, lifetime 10000, reload 3000, damage ×4. Wanted targets use their `Wanted::getWeapon()` item with damage ×4. Turret/boss variants copy item 211–213 stats.

---

## Uncertainties

- **Coordinate mapping of mount points.** Engine space has the nose at +Z (Betty engine mesh at z ≈ −466, primaries at z = +26). The project maps world positions as `(x, y, −z)` and rotates every model 180° at import so ships face Unity +Z. For ship-local points (mounts, the +100 muzzle offset) that would put the mounts at the tail; the vertices effectively go through `(−x, y, z)`. Verify on the assembled Betty prefab before relying on either (the primary mount should sit near the nose).
- **Beam visibility end**: nothing resets `Gun+0x4c` for beams; the beam mesh is probably faded by its own animation (1033 ms, `extra` = opacity). Beam scaling: only one scale component (length) is certain.
- **Rockets after lifetime**: they keep moving and colliding for 2000 ms; the projectile scale `timer/1000` becomes negative then (mirrored mesh). Probably invisible in practice; recommend hiding the mesh at `timer ≤ 0` but keeping collision until −2000.
- The `Gun::Gun` direction-deviation vector (`+0xe4`) is scaled by a float the decompiler lost (0 for player guns anyway).
- The cluster-missile corkscrew amplitude factor `k` was lost by the decompiler.
- M6 beam sounds: items 9 and 11 both map to event 50 (Beam_M6_Wolv) and 10 to 49 (Coug); event 51 (Wulf) is unused by the table, so the Wolf/Wolverine names may be shifted by one in the heuristic id file.
- DLC sound ids (≥ 1095) are name-matched guesses; `fmod_event_ids.txt` only covers ids 0–161.
- `Player+0x60` (+0.008 per shot, +0.065 per damage, −0.025/s) is assumed to be a combat-intensity value (music); not verified.
- Particle trail sizes: `+0x28` extra-size field semantics (125 for set 39) not verified against `ParticleSystemSprite`.
- Mesh bounding radii are from the sidecars (file space); the streak direction of laser projectiles relative to the bullet origin needs a visual check.
- KIPlayer `+0x3c` (custom collide) and `+0x6d`, `+0x3d` flags are named by use only.
