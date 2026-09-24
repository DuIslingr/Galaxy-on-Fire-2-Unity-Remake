# NPC combat specials: turrets, Terran / Vossk capital ships, pirate bases

What free flight adds on top of the fighters / freighters / raiders the remake already has (`npc_traffic_ai.md`,
`ship_combat.md`, `kaamo_club.md`). Decoded from `libgof2hdaa.so` (Android HD). Game units and milliseconds; Unity =
`(x, y, -z) * 0.05`. Addresses: Ghidra image base 0x10000. **(v)** = read from the code / data (decompiler or
disassembly), **(a)** = assumption or inference.

Read first (not repeated): `npc_traffic_ai.md` §2 (spawn counts, ship array order, `createShip`), §4 (relations,
enemy lists, friendly fire), §6 (freighters); `ship_combat.md` §2.9 (collision), §5.2 (`PlayerFixedObject` death),
§7 (HUD markers, lock plate, hostile counter); `kaamo_club.md` §3.2 (outpost object 0x37a3: HP formula, collision 1002,
wreck 14246, x8 explosion).

---

## 0. TL;DR

- **Turrets (`PlayerTurret`) exist only as satellites of capital ships** in free flight: 7 around the Terran battleship
  (ship 14), 8 around the Terran carrier (Supernova era), 5 around the Vossk battleship (Supernova era). Pirate
  outposts, freighters, stations and Void ships have **no** turrets. (Story-only: 2 battlestation turrets on the
  campaign-59 convoy freighter, 12 turrets / shield generators on the Valkyrie battlestation, turrets hosted on ships
  45 / 51.) (v)
- A turret: static object (`turret_002_static` Terran / `turret_003_static` Vossk, **scale 6**), **1000 HP**, own race
  (0 / 1), bullet cube ±1000, no collision volume. Every **3000 ms** it picks the **nearest** valid enemy within
  **50 000** units (Euclidean), yaws / pitches at **2π/4096 rad per ms (88°/s)** toward `target + target.forward·1500`,
  pitch limited to about **+52.7° up / −8.8° down**, fires the NPC gun (item 20 Ridil look, Vossk item 15 H'nookk;
  the fighters' damage / 4 bullets / 16 u/ms / 3000 ms / reload) when the aim point is within **±0.05** on both local
  axes. Death: sound **22** `Garbage_Explosion`, explosion type 0, smoke, gone after **4500 ms**, no loot. (v)
- **Terran special** (`Level::createMission`, system race Terran, ≥ 1 freighter rolled, **30 %**): the first freighter
  slot becomes the **battleship** (ship 14, `createShip` kind 1, hull ×25, not moving) or, 30 % of those and only after
  campaign index 103, the **carrier** `sn_carrier_terran_1` (indestructible decor). **Vossk special** (Vossk system,
  ≥ 1 freighter, 30 %, campaign index > 140): the **Vossk battleship** `sn_battleship_vossk` (indestructible decor,
  name 1667 "Battleship"). No fighter launches, no own guns, no special weapons: the specials' firepower is the
  turrets. Killing the Terran battleship destroys all turrets (+ stat "Battleships destroyed", medal 39). (v)
- **Pirate bases**: stations **1 Mahasa (Suteo), 33 Néh Suhnu (Behén), 47 Bosmáh (Weymire), 86 Hamina (Nesla)** — all
  Nivelian systems — each has a base from the new game until destroyed (`Status+0x4c` bool[4], saved). Whole system:
  no raiders, instead **2** awake pirates near the player (hardcore 4..6). Base station's orbit: one sleeping
  **Pirate Outpost** (0x37a3) ~200-240 km out (fixed table ±10 000 jitter), **5** sleeping hidden guard pirates around
  it (hardcore 10), a **red static fog** around the outpost, and the station itself is **unmanned** (docking shows 434
  and relaunches at once). First guard waking: radio 435-437; outpost destroyed: radio 438-440, base flag set, the
  outpost's crate holds a fixed item (station 1: 5× AMR Oppressor; 33: Thermic o5; 47: Sh'koom; 86: Sol EMP Mk II);
  at the **next docking anywhere**: message 442 ("… 20,000 Credits …", from "Nivelian") and **+20 000 credits**. (v)

---

## 1. NPC turrets (`PlayerTurret`)

### 1.1 Functions

| Function | Address | Role |
|---|---|---|
| `PlayerTurret::PlayerTurret(type, Player*, AEGeometry* root, x, y, z)` | 0x182640 | meshes, pivot, barrel, explosion, defaults |
| `PlayerTurret::update(dt)` | 0x182ab0 | host follow, death, relations, dispatch |
| `PlayerTurret::handleTurret` / `handleSentryGun` | 0x182e5a / 0x182e24 | timer + `pickEnemy` + `handleRotation` |
| `PlayerTurret::pickEnemy` | 0x182e90 | nearest valid enemy every 3000 ms |
| `PlayerTurret::handleRotation(dt, yawGeom, pitchGeom)` | 0x182fe4 | aim, limits, fire |
| `PlayerTurret::render` / `collide` / `outerCollide` / `revive` / `reset` | 0x1832ac / 0x1832e0 / 0x1832e4 / 0x1832e8 / 0x182a92 | not drawn in states 3/4; **no collision** (both return 0) |
| `PlayerTurret::setHost(KIPlayer*, offset)` / `setTurretRange(int)` / `setScaling(f)` | 0x182a7e / 0x182a78 / 0x182a50 | hosted turrets; range (default 50 000); uniform scale of the pivot |
| `Level::createStaticObject` (branches 0x1a74 / 0x1a76 / 0x381b / 0x381d / 0x49c0-0x49c2) | 0xcda54 | `Player(radius 1000, hp 100)`, name 1666 "Turret" (0x381d: 1665 "Generator", unarmed), loot none |
| `Level::createFighterTurrets` | 0xcb200 | turrets hosted on ships 45 / 51 |
| `Level::assignGuns` (turret branch) | 0xcb638 | turret guns |

### 1.2 Which objects carry turrets

| Object | Turrets | Where | |
|---|---|---|---|
| Terran battleship (ship 14) | 7 × 0x1a74 | free flight Terran special (§2) | v |
| Terran carrier 0x4974 | 8 × 0x1a74 | free flight Terran special, campaign index > 103 | v |
| Vossk battleship 0x4a6b | 5 × 0x1a76 | free flight Vossk special, campaign index > 140; campaign 139 (two battleships, 5 turrets each, `campaign_levels_c.md` 3.10) | v |
| Campaign-59 convoy freighter ("Arms delivery" 1664) | 2 × 0x381b battlestation turret, scale 0.3, table 0x253464 by race | `createMission` branch for campaign type 0xa3 at a `Status+0x90` station | v |
| Valkyrie battlestation (campaign 78 / 80) | 0x381b turrets + 0x381d shield generators | `campaign_levels_b.md` (table 0x2539d4) | v |
| Ship 45 (Supernova Most Wanted) / 51 (Terran Rhino dropship) | 1 × 0x1a74 hosted, invulnerable, cloaked for the radar, HP = host max HP, gun item 22 ×0.5 damage | `createFighterTurrets`, offsets (0, 172.25, −460.7) / (0, 470, −83) | v |
| Player sentry guns 0x49c0-0x49c2 | — | player-deployed items 211-213 (`handleSentryGun`), not NPCs | v |
| Pirate outposts, freighters, stations, Void / Specter ships | **none** | | v |

`weapons_hd.json` slotType 2 entries are the **player's** turret mounts per ship (`PlayerEgo::setTurretPosition`);
they are not used for NPCs. NPC turrets are separate world objects at table offsets from their host (§2.4).

### 1.3 Object and meshes (v)

- Root geometry `+8` is an empty `AEGeometry` (types 0x1a74 / 0x1a76 / 0x381b); a pivot `+0x144` (empty) holds the base
  mesh `+0x13c` (= type id) and the barrel `+0x140`; the pivot is the child of the root. `setScaling` scales the pivot.

| Type | Base | Barrel (pitch part) | Barrel offset in pivot space | Assembly | Scale (free flight) |
|---|---|---|---|---|---|
| 0x1a74 (6772) | `Models/main/turrets/turret_002` | 6773 `turret_002_gun` | (0, 60, 0) | `turret_002_static` | **6.0** (0x40c00000) |
| 0x1a76 (6774) | `turret_003` | 6775 `turret_003_gun` | (0, 60, 0) | `turret_003_static` | **6.0** |
| 0x381b (14363) | `v_station_battlestation_turret` | 14364 `_gun` | (0, 565, −528), base and barrel `rotate(0, π, 0)` | `v_station_battlestation_turret` | 0.3 (convoy) |

  So in free flight the barrel pivot sits 360 units above the turret origin (18 m in Unity).
- `Player(radius 1000, hp 100)`, then `createMission` calls `Player::setMaxHitpoints(1000)` (sets max and current):
  **1000 HP**, no shield / armor, not scaled by rank or difficulty. Bullet hit test = the normal cube **±1000** around
  the turret origin (the custom-box flag `KIPlayer+0x3c` is not set). `collide` / `outerCollide` return 0: the player
  and fighters fly through turrets. (v)
- `KIPlayer+0x21` armed = 1, `+0x3a` turret = 1, race `+0x24` set by the spawner (Terran 0 / Vossk 1), loot list
  `+0x4c` = null, name `+0x18` = 1666 "Turret". Range `+0x160` = 50 000. (v)
- The root gets `setRotation(tableRot)` (game Euler, order Rx·Ry·Rz, see §2.4) and `setPosition(host + tableOffset)`;
  unhosted turrets never move. (v)

### 1.4 Relations (every frame, `update`) (v)

Same rule as fighters / fixed objects: race 8/9 → hostile; else `Standing::isEnemy(race)` / `isFriend(race)`;
`turnedEnemy` → hostile; `alwaysFriend` → friend. Turrets take part in the friendly-fire bookkeeping of
`Player::damage` like any system-race ship (33 % / 50 % / 66 % of 1000 HP → radio 0, turns, `alarmAllFriends`).

### 1.5 Target choice (`pickEnemy` 0x182e90) (v)

```
reselectMs (+0x12c) += dt each frame; starts at 0 (first pick after 3 s)
if reselectMs > 3000:
    target (+0x148) = null; reselectMs = 0; best = range (50000)
    for e in the turret's enemy list (Level::connectPlayers: player first, then every ship of another race):
        skip dead or inactive
        candidate =  (e is the player and the turret is hostile to the player)
                  or (e is an NPC (has a KIPlayer) and racesHostile(e.race, turret.race))   // same table as fighters:
                                                   //  8<->others, 9<->others, 10<->others, 0<->1, 2<->3
        d = int(|e.pos - turret.pos|)              // Euclidean, not a box
        if candidate and d < best and (target == null or target != ignored (+0x14c)): target = e; best = d
```

- A non-hostile turret never picks the player (the player's `Player` has no KIPlayer).
- `+0x14c` "ignored" = a target the turret gave up on because it was outside the pitch limits (§1.6). Quirk: the
  check tests the *current best*, so once the ignored target becomes the best, later closer candidates cannot replace
  it. Remake: skip the ignored target while any other candidate exists (the evident intent).
- Between picks the target is not re-validated: a turret keeps tracking (and shooting at) a target that died until the
  next 3 s pick.
- A cloaked target (`Player+0x5e`, race-10 Specters) is kept but not aimed at / fired on.

### 1.6 Aiming and firing (`handleRotation` 0x182fe4, disassembly verified) (v)

```
aim   = target.position + normalize(target.forward) * 1500        // 0x44bb8000; fixed lead along the target's heading
M     = root.matrix * pivot.matrix * barrel.matrix                // current barrel frame (includes scale 6)
local = normalize(inverse(M) * aim)                               // aim point in barrel space

// yaw (pivot, about its local Y): rotate(pivot, 0, ±dt*2π/4096, 0)
if local.x >  0.05: pivot.rotateY(+dt * 2π/4096)
elif local.x < -0.05: pivot.rotateY(-dt * 2π/4096)
else yawAligned = true

// pitch (barrel, about its local X); counter pitch (+0x130) in "ms", starts 0
if local.y > 0.05:                                               // aim point above
    if pitch < -599: giveUp()                                    // at the upper limit
    else: pitch -= dt; barrel.rotateX(-dt * 2π/4096)             // Rx(-θ) lifts +Z toward +Y
elif local.y < -0.05:                                            // aim point below
    if pitch > 99: giveUp()                                      // at the lower limit
    else: pitch += dt; barrel.rotateX(+dt * 2π/4096)
elif yawAligned:
    Player::shoot(slot 0, dt, M)                                 // fires when reloaded (NPC gun, §1.7)
    barrel animation Transform::Update(dt)                       // the barrel mesh's keyframes advance only while firing

giveUp(): ignored = target; reselectMs += dt                     // the 3 s timer runs twice as fast meanwhile
```

- Rate **2π/4096 rad per ms = 1.534 rad/s ≈ 88°/s** on both axes; no easing, no overshoot handling other than the ±0.05
  dead zone (≈ ±2.9°). The dead zone is also the fire cone.
- Pitch range: counter −600 … +100 → **≈ 52.7° above and ≈ 8.8° below the pivot plane** (the check happens before the
  step, so the limit is overshot by one frame). The yaw is unlimited.
- The control loop is closed on the barrel frame itself (local.x / local.y of the pitched barrel), so yaw and pitch
  converge together.
- The 1500-unit lead matches the player at base speed (2 u/ms) and bullet speed 16 u/ms at ~12 000 units distance
  (a); closer or boosting targets are mostly missed.

### 1.7 Gun (`Level::assignGuns` turret branch) (v)

Built exactly like a fighter's gun: `Gun(slot 0, damage v, count 4, ammo −1, lifetime 3000, reload 600 − 2·cm, speed
16.0)`, `setFriendGun(true)`, damage `v` from the player's rank / difficulty (`npc_traffic_ai.md` §3: 3 at rank ≤ 4 …
22), campaign 0x50: ×1.7. Only the look differs:

| Turret | sort `Gun+0x5c` | `setIndex` (look) | projectile mesh | shot sound (`Player::playShootSound` by the owner's race, `DAT_002526c0`) |
|---|---|---|---|---|
| race 1 (Vossk) | 1 (blaster, camera-facing billboard) | 15 H'nookk | 0x1a87 = 6791 `projectile_015_anim_add` | 55 `Laser_Shkoom` |
| other races | 1 | 20 Ridil Blaster | 0x1a8c = 6796 `projectile_020_anim_add` | 52 `Laser_Nirai_Impulse_EX1` (Terran) |
| hosted on 45 / 51 | 2 (auto-cannon) | 22 Micro Gun MK I | 0x1a8e | by race (45: pirate 61, 51: Terran 52) |

- Bullets start at the barrel frame `M` (mount (0, 0, 0) + the usual 100 forward in the scaled frame ≈ 600 units ahead
  of the barrel pivot, (a)) and fly straight along the barrel. They hit what the turret's enemy list holds (player +
  other races) with the normal cube test; a non-hostile turret's stray hit on the player does 20 % (like fighters).
- Range: 16 u/ms × 3000 ms = 48 000 units (slightly shorter than the 50 000 pick range).

### 1.8 Death (`update` state machine) (v)

```
hull < 1 and state not 3/4:
    state 3; deathMs = 0
    play 22 (Garbage_Explosion, not 3D); particle burst (Level+0x3c system) at the turret
    smoke system (set 9, added in setLevel) on; Explosion type 0 with fire streaks at the turret (default scale)
    loot: `nextInt(100) < 0` → never (dead code for a crate of 1..10 × item 99 Space Waste)
    if the player's radar lock (Radar+0x1c) is this turret: cleared
state 3: explosion update; deathMs += dt; > 4500 → smoke off, state 4, Player inactive (sentry guns: Level+0x6c−1)
render: nothing but the explosion in state 3, nothing in state 4 → the turret vanishes at once
```

Standing: a player kill goes through `Player::damage` → `Standing::applyKill(race)` → −5 with Terran / Vossk (not in
the black market), kills +1 (`Level::enemyDied`) if the turret was hostile. No respawn in free flight.

### 1.9 HUD (v, by absence of any turret test in `Radar::draw`)

Turrets are ordinary entries of the level's ship array: faction marker / hull bar / bracket (`ship_combat.md` §7.2),
ship lock, lock plate text = the name **"Turret"** (1666, named ships show no %), counted by the hostile counter when
hostile (battle music, fast-forward block). Hosted turrets (45 / 51) are flagged cloaked (`+0x70`) → no marker, no lock.

---

## 2. Terran and Vossk capital-ship specials

### 2.1 Spawn rules (`Level::createMission` 0xbda70, empty-mission branch, after the counts of `npc_traffic_ai.md` §2.2) (v)

```
sysRace = system race; F = freighters (Level+0x168, nextInt(5), 0 at Var Hastra)
terran  = sysRace == 0 and F > 0 and nextInt(100) < 30
vossk   = sysRace == 1 and F > 0 and nextInt(100) < 30 and currentCampaignMission > 0x8c (140)
carrier = terran and nextInt(100) < 30 and currentCampaignMission > 0x67 (103)
supernova system: terran = false (all counters 0)
turrets = terran ? (carrier ? 8 : 7) : 0;  vossk: 5 more slots
```

- The special **replaces the first freighter** (array index `local + jumpers`); the remaining F−1 freighters spawn as
  usual. Draw order: the two/three `nextInt(100)`s happen right after the pirate-base / convoy decisions, before the
  Supernova reset.
- The turrets are appended after the freighters (before raiders / escorts / outpost / Specters). They all get
  `race = sysRace` (0 or 1) and no loot.
- Free-play probability in a Terran system (not Var Hastra): 4/5 × 30 % = **24 % per visit** for the battleship. The
  carrier and the Vossk battleship need the Valkyrie / Supernova campaign progress.
- Nothing excludes a special from a pirate-base system, but all four bases are in Nivelian systems, so the two never
  meet. (v)

### 2.2 Terran battleship (ship 14)

| | Value | |
|---|---|---|
| Creation | `createShip(race 0, kind 1, ship 14, no waypoint)` → `PlayerFixedObject(14, 0)`; the `createShip` jitter is overwritten by `setPosition` | v |
| Position (game) | `(nextInt(80000) − 40000, nextInt(10000) − 5000, nextInt(80000) + 40000)`, identity rotation (faces game +Z), `setMoving(false)` | v |
| Model | assembly `battleship_terran` (14311 + lights 14315/14316, LOD 14312/14313 at 35 000 / 60 000), **scale 2** (`Globals::getShipGroup` idx 14) | v |
| Hull | `createShip` kind 1 ×25: `25 · (4·cm + 14·min(rank,20) + 20)`, ×2 hardcore; EMP ×3, 45 s recovery | v |
| Bullet hits / collision | custom boxes (`KIPlayer+0x3c` = 1), 11 axis-aligned boxes (below) | v |
| Engine sound | none (`+0xf4 = −1` for type 14); no exhaust | v |
| Guns | none (`+0x21` not set); firepower = its 7 turrets | v |
| Loot | `getLootList(-1,-1)` with every amount × `nextInt(8) + 5` | v |
| AI | none: `PlayerFixedObject::update` only recomputes relations, EMP, death; never moves, never turns, never launches ships | v |
| Name / lock plate | none → "Terran NN%" | v |

Boxes (`Level::createShip` race-0 ship-14 branch, BoundingAAB centre offset / **full** size in game units, ship space =
world axes; the last three recovered from the disassembly at 0xcfd70-0xcfe4e):

| # | offset (x, y, z) | size (x, y, z) |
|---|---|---|
| 0 | (0, −2240, 21608) | (760, 640, 2890) |
| 1 | (0, −2342, 18392) | (1260, 3560, 3670) |
| 2 | (0, −786, 8926) | (7410, 7740, 15540) |
| 3 | (0, −4950, 9656) | (820, 1040, 7150) |
| 4 | (0, 3420, −452) | (1310, 940, 4880) |
| 5 | (0, −270, −9018) | (7520, 6870, 20470) |
| 6 | (0, −5088, −7962) | (1300, 2900, 13210) |
| 7 | (0, 3526, −11604) | (3260, 880, 10640) |
| 8 | (0, 5212, −12332) | (3260, 2640, 8410) |
| 9 | (0, 2004, −15852) | (15860, 2510, 10910) |
| 10 | (0, −2610, −15852) | (15860, 2510, 10910) |

Death (`PlayerFixedObject::update` 0x17f480, type 14): `enemyDied`/`friendDied`, crate if cargo, wreck
`battleship_terran_explosion_anim` 18304 (wreck id 0x4780) plays once (`ship_combat.md`: ~15 s), sound 20, the big smoke
system (`Level+0x54`, shared with the outpost), Explosion type 0; **every level entry with `+0x3a` (all turrets) gets
`Player::damage(9 999 999)`** (the killer flag of that call is a register leftover, (a) not credited to the player);
killed by the player → `Status+0x118` "Battleships destroyed" +1 and medal 0x27 (39) progress. Animation over → state 4,
explosion **×6** (the ×8 test is for type 0x37e7 = mesh 14311 used as a static object, not for ship 14; the remake
currently uses 8), rumble, wreck stays with `wreck_collisions.json` entry 0 ×2.

### 2.3 Terran carrier 0x4974 and Vossk battleship 0x4a6b (static objects) (v)

| | Carrier 0x4974 | Vossk battleship 0x4a6b |
|---|---|---|
| Assembly | `sn_carrier_terran_1` (18804 + 18805 / 18807 sections, 18808-18810 emissive, 18806 lights) | `sn_battleship_vossk` (19051 + 19052 add + 19053 lights) |
| Race | 0 | 1 |
| Position | first drawn around (±40000, ±20000, 100000..180000) (RNG only), then **overwritten** by the battleship formula: `(nextInt(80000) − 40000, nextInt(10000) − 5000, nextInt(80000) + 40000)` | `(nextInt(80000) − 40000, nextInt(40000) − 20000, nextInt(80000) + 60000)` (exact, jitter overwritten) |
| Rotation | identity (faces game +Z) | identity |
| HP | ctor `5·((gameWon?180:4cm) + (rank<21 ? 15·rank+100 : 400))` × difficulty as max, then **`setHitpoints(9 999 999)`** | `Player(radius 0, 9 999 999)` |
| Hittable | **no**: `Player` radius 0 and no custom-box flag → the bullet cube is empty (a: follows from `Gun::calcCharacterCollision` using `Player+0x40` unless `+0x3c`) | no (same) |
| Collision (player push-out, fighter avoidance) | `getBoundingVolume(…, 0x7d5 = 2005)` → `static_collisions.json` 2005 (18 volumes), static rule (centre (a, c, −b), box ×1.2, sphere ×0.6) | 2006 (38 volumes) |
| Docking points | space points 5 loaded, then `setSpacePoints(null)` → none | 8 loaded, then removed |
| Wreck id | 0x494e | 0x477c |
| Name | none | 1667 "Battleship" |
| Loot | removed (`+0x4c = 0`), `+0x6c = 0` | removed, `+0x6c = 0` |
| Engine sound | 47 (fixed-object default, `+0xf4 = 0x2f`) (a: audible freighter loop) | 47 |

Both are therefore indestructible, passive landmarks whose turrets do the fighting. They still get markers / hull bars
(hull fraction > 1 for the carrier; clamp it) and count as hostile ships when their race is hostile.

### 2.4 Turret layouts (world offsets from the host's position; host at identity rotation) (v)

Rotation = game `setRotation(x, y, z)` (Rx·Ry·Rz) of the turret root; convert with `OrbitLayout.RotationToUnity`.
Unity offset = `(x, y, −z) · 0.05` m.

**Terran battleship (ship 14), 7 × 0x1a74, table 0x253604** (stride 0x18: pos xyz, rot xyz):

| # | game offset | Unity m | rotation (rad) |
|---|---|---|---|
| 0 | (5322, 1893, −15571) | (266.1, 94.7, 778.5) | (0, 0, −π/2) |
| 1 | (2356, 1115, 7324) | (117.8, 55.8, −366.2) | (0, 0, −π/2) |
| 2 | (0, −4261, 4876) | (0.0, −213.1, −243.8) | (0, 0, π) |
| 3 | (−5322, 1893, −15571) | (−266.1, 94.7, 778.5) | (0, 0, π/2) |
| 4 | (0, 5669, −13872) | (0.0, 283.4, 693.6) | (0, 0, 0) |
| 5 | (−2356, 1115, 7324) | (−117.8, 55.8, −366.2) | (0, 0, π/2) |
| 6 | (0, 2855, 4161) | (0.0, 142.8, −208.1) | (0, 0, 0) |

**Terran carrier, 8 × 0x1a74, table 0x253544:**

| # | game offset | Unity m | rotation (rad) |
|---|---|---|---|
| 0 | (−6726, 2458, −66) | (−336.3, 122.9, 3.3) | (0, π/2, 0) |
| 1 | (5824, 2458, 10243) | (291.2, 122.9, −512.2) | (0, −π/2, 0) |
| 2 | (−6726, 2458, 2100) | (−336.3, 122.9, −105.0) | (0, π/2, 0) |
| 3 | (5824, 2458, 8437) | (291.2, 122.9, −421.8) | (0, −π/2, 0) |
| 4 | (−5549, −2743, 11954) | (−277.4, −137.2, −597.7) | (−π, π/2, 0) |
| 5 | (−5549, −2743, −3711) | (−277.4, −137.2, 185.5) | (−π, π/2, 0) |
| 6 | (4981, −2743, 14659) | (249.1, −137.2, −733.0) | (π, −2.1817, 0) |
| 7 | (0, 2458, −32811) | (0.0, 122.9, 1640.6) | (0, 0, 0) |

**Vossk battleship, 5 × 0x1a76, table 0x2536ac** (rotation 0 for all):

| # | game offset | Unity m |
|---|---|---|
| 0 | (10283, −1123, 26039) | (514.2, −56.1, −1302.0) |
| 1 | (−10171, −1083, 25907) | (−508.6, −54.1, −1295.3) |
| 2 | (−15624, −787, −7569) | (−781.2, −39.4, 378.5) |
| 3 | (15624, −787, −7569) | (781.2, −39.4, 378.5) |
| 4 | (0, 4901, 3084) | (0.0, 245.1, −154.2) |

Turret scale 6 in all three. Rotation (0, 0, ±π/2) = turret lying on the hull side, (0, 0, π) = hanging under it.

### 2.5 Behaviour in practice

- Terran turrets are neutral while `s0` is between −70 and +70 (new game 30), so they shoot pirates and Vossk raiders
  within 50 000 units of themselves; they turn on the player after friendly fire (every system-race ship and turret
  becomes always-enemy at 66 % on one ship) or when Terrans become hostile by standing. Vossk turrets likewise.
- Pirates/raiders treat the battleship and every turret as race-hostile targets (they attack the first race-hostile
  ship of the array when the player is out of their box, `npc_traffic_ai.md` §5.3), so a battleship orbit turns into a
  turret-vs-raider fight.
- There is no Vossk *carrier*; nothing in free flight launches fighters from a capital ship (the carrier's dropships
  are campaign-102 script, `campaign_levels_b.md`).

---

## 3. Pirate bases

### 3.1 State and conditions (v)

- `DAT_00251f90` = [1, 33, 47, 86] (pirate station index 0..3); `Status+0x4c` = `Array<bool>[4]` "destroyed",
  `Status::resetGame` 0 (all four bases active from the new game, no campaign condition), saved by
  `RecordHandler::recordStoreWrite` (after `Status+0x44`, before the agents).
- `Station::stationHasPirateBase` 0xb3e64: station is one of the four and not destroyed.
  `SolarSystem::hasPirateBase` 0x180aa4: the system contains such a station.
- All four are in Nivelian systems: 1 Mahasa in 0 Suteo (security 1), 33 Néh Suhnu in 2 Behén (1), 47 Bosmáh in
  9 Weymire (2), 86 Hamina in 17 Nesla (1). Texts 432 / 433 (shop / lounge closed) are wired only to stations 4 and 88
  (`ModStation::OnKeyPress` 0xec6f8), which are not in the table → dead code (J2ME leftovers).

### 3.2 Orbit setup (`Level::createMission` 0xbda70) (v)

In **every orbit of a pirate-base system**:

```
escorts (local_194) = nextInt(1) + 2 = 2;  hardcore: nextInt(3) + 4  (4..6)
raidersOn = false; raiders = 0                           // no raider group, so no raider waves either
escort i: createShip(8, 0, getRandomEnemyFighter(8)) at player + (nextInt(160000) − 80000, nextInt(100000) − 50000,
          nextInt(160000) − 80000), awake, default patrol (station box)
```

Local fighters, jumpers and freighters stay as usual (Nivelian police vs the escorts).

**Additionally in the base station's own orbit** (`stationHasPirateBase`):

| # | Object | Creation | Position (game) |
|---|---|---|---|
| 1 | **Pirate Outpost** | `createStaticObject(route waypoint, 0x37a3, jitter = true)`, `setToSleep`, name 441 | `DAT_00253724[i]` **± 10 000 per axis** (the jitter is *not* overwritten, unlike Kaamo) |
| 2..6 | **guards** ×`int((difficulty − 0.5)·5 + 5)` = **5** (hardcore 10) | `createShip(8, 0, getRandomEnemyFighter(8))` (model rolled per guard), `setToSleep`, guard flag `PlayerFighter+0x12b` = 1 | table position (without the jitter) + `(sx·nextInt(20000) + 10000, sy·nextInt(20000) + 10000, sz·nextInt(20000) + 10000)`, s = ±1 each, i.e. −10 000 … +29 999 per axis |

| i | Station | table position (game) | Unity m | distance from the station |
|---|---|---|---|---|
| 0 | 1 Mahasa | (−200000, −100000, 50000) | (−10000, −5000, −2500) | 229 km |
| 1 | 33 Néh Suhnu | (50000, 200000, −100000) | (2500, 10000, 5000) | 229 km |
| 2 | 47 Bosmáh | (140000, −150000, 7000) | (7000, −7500, −350) | 205 km |
| 3 | 86 Hamina | (170000, −170000, 10000) | (8500, −8500, −500) | 241 km |

(RNG order in the array fill: outposts come after local, jumpers, freighters, turrets, raiders and the system-wide
escorts; guards right after the outpost.)

### 3.3 The outpost (v unless noted)

Same object as at Kaamo (`kaamo_club.md` §3.2): `PlayerFixedObject(0x37a3, race 8, Player(radius 7500, hp))`,
`hp = 5·((gameWon ? 180 : 4·cm) + (rank < 21 ? 15·rank + 20 : 320))` × difficulty, bullet cube ±7500, collision
`collision.json` 1002 (static rule), assembly `station_pirates`, no rotation, **no guns, no turrets**, never moves, no
engine sound, `KIPlayer+0x3d` (mines ignore it).

- **Asleep** (state 5, `Player` inactive): not hittable, no marker, no lock, not counted (a: the radar and the bullet
  test skip inactive players). It wakes (state 1, active) when **any** entry of its enemy list (the player or a
  non-pirate ship) is active inside **±50 000 per axis**. Fixed objects are not hidden while asleep (only fighters
  are), so the model is visible from afar. (v for the wake rule)
- **Loot** (ctor, only at the four base stations): `Generator::getLootList(item, amount)` returns exactly
  `[item, amount]` from `DAT_002543e0`:

| i | Station | Item | Amount |
|---|---|---|---|
| 0 | 1 | 45 AMR Oppressor | 5 |
| 1 | 33 | 28 Thermic o5 | 1 |
| 2 | 47 | 4 Sh'koom | 1 |
| 3 | 86 | 17 Sol EMP Mk II | 1 |

  The crate (`createCrate(0)`, pirate race → `container_002_nivelian`) appears at death, 60 s lifetime, tractor beam as
  usual.
- **Death**: `enemyDied`, **`Level::pirateStationAction(false)`**, crate, wreck 14246 (`station_pirates_explosion_anim`,
  once, ~20 s), sound 20, big smoke (`Level+0x54`), Explosion; then ×8 explosion + rumble, wreck stays (state 4).
  Standing: `applyKill(8)` → +1 toward the Nivelians (`applyDelict(enemyRace(2) = 3, 1)`), kills +1, pirate kills +1.

### 3.4 Guards (v)

Ordinary pirate fighters (standard hull / gun, `npc_traffic_ai.md` §2.4, §3), asleep: hidden (hostile sleepers after
the tutorial), wake when the player is within **±25 000 per axis** or their target within ±50 000. On waking
(`PlayerFighter::update` state 5, 0xf2xxx) a guard with `+0x12b` calls **`pirateStationAction(true)`**. No route → the
default patrol box in front of the *station* (≈ 200 km away), so after the fight they head back toward the station
area (a). **No respawn**: `updateOrbit` only revives local fighters (index < local) and the last `raiders` entries
(0 here); the escorts do not come back either.

### 3.5 `Level::pirateStationAction(bool)` 0xd6338 and radio (v)

```
pirateStationAction(true):  if !Level+0x1b0: createRadioMessage(3, race 8)            // guard woke
pirateStationAction(false): if !Level+0x68 and getPirateStationIndex() >= 0:
                                Status+0x4c[i] = 1 (destroyed); Status+0xf9 = 1 (reward pending)
                                createRadioMessage(4, race 8)
createRadioMessage(kind, race) 0xd5568: only with an empty mission and a player; replaces the level's radio array
    kind 3: Level+0x1b0 = 1 (once per level); text 435 + nextInt(3): 435 "Somebody's coming. Finish them off!",
            436 "Hey, what's your problem? You looking for trouble, or what?", 437 "Somebody found us! Take him down!
            Don't let him escape."
    kind 4: Level+0x68 = 1 (once); 438 + nextInt(3): 438 "Nooooo!", 439 "Argh! You're gonna pay for this!",
            440 "Dang it! We worked so hard stealing it and he gone and done blew it to smithereens!"
    speaker image by race 8 → 9 (pirate portrait); shown lines·2000 + 1500 ms
```

Note the destroyed flag is only set when no kind-4 radio has run yet (`Level+0x68`): with one outpost per orbit
this always holds.

Hints (not tied to a base, `MGame::OnUpdate` 0x1ac778): the first time the player is in any **Nivelian** system
(outside the alien orbit), radio kind 5 → 443 "A lot of pirate activity here. Strange..." (hint 0x23), on a later
Nivelian visit kind 6 → 444 "Pirates everywhere! They must have built an outpost somewhere." (hint 0x24). They fire
even after all bases are gone.

### 3.6 Docking at a base station (`ModStation::OnInitialize` 0xe8080 / `OnTouchEnd` 0xea4ec) (v)

While `stationHasPirateBase` (and the station is not 4 / 88): after the autosave, when no docking-fine dialog applies,
a one-page `DialogueWindow(434, name 1609 "Security", portrait {2,0,0,0,0} = DAT_0026a1c4)`, voice
`getDialogueSoundId(0x1b2, Nivelian agent)`: "I'm sorry, but the station is currently unmanned. … The cowardly rats
must have built an outpost nearby. Come back when things have calmed down." Closing it: `Status::departStation`,
`Achievements::resetNewMedals`, switch to the space module → **immediate relaunch** (no shop, hangar, lounge, map).

### 3.7 Reward (`ModStation::checkHints` 0xee500) (v)

At the next docking **anywhere** with `Status+0xf9` set (and no other hint dialog this frame):
`DialogueWindow(442, name 1662 "Nivelian", portrait {2,0,0,0,0})`, sound 0x24d (589, a voice event, unmapped),
`Status+0xf9 = 0`, **`changeCredits(+20 000)`**. 442: "You found and destroyed the pirate outpost! Our system is safe
again, thank you! As a reward, I transferred 20,000 Credits to your account." `Status+0xf9` is not saved (dying before
the next docking reloads the save with the base still active).

### 3.8 What destroying the base changes (v)

`hasPirateBase` / `stationHasPirateBase` become false for good: the system gets normal raiders again (no forced
escorts), the station's orbit has no outpost / guards / fog, docking works normally. No standing bonus beyond the
kill's +1, no mission counter, no medal, no campaign hook, no news item.

### 3.9 Red fog `SET_FOG_STATIC` (`Level::initParticleSystems` 0xcc990) (v)

Only when `SolarSystem::hasPirateBase` and an object of type 0x37a3 is in the ship array (so only the base station's
orbit, not the system's other orbits): particle set 8 added on the outpost's reference matrix: 30 sprites of 32 768
units (1638 m), spread ±40 000 around the outpost, colour 0xE2282880 (red, alpha 128), infinite lifetime, not tied to
the camera (`space_props.md` §4). It stays after the outpost is destroyed (until the next level load).

### 3.10 Music (v)

Nothing special: the outpost and guards are race-8 hostiles, counted by `Radar::draw` once active → Space_Combat
Low / Mid / Full by count; asleep they do not count, so the orbit plays the Nivelian space track until they wake.

---

## 4. Other combat special cases in `createMission` / `createShip` (brief)

| Case | Where | Remake status / pointer |
|---|---|---|
| Campaign 59 (type 0xa3) convoy: freighter "Arms delivery" (1664) at (±(80000..109999), −6000..−3001, 120000..169999), not moving, loot first entry → random of {0, 1, 2, 0x24, 0x16, 0x17}; 5 escorts on a looping route; 2 battlestation turrets (scale 0.3, table 0x253464 by race); script: within 50 000 all turn always-enemy (radio 0xe), freighter killed → turrets ×9 999 999, station marked done (radio 0xf) | `createMission` 0xbe742.., `LevelScript::process` | not built (campaign_levels) |
| Void / alien orbit: `n` VoidX, always enemy, damage ×0.8, loot 131 Alien Remains, detection 100 000; station attacked by aliens / coming from the alien world: freighters ≥ 2, raiders `nextInt(4)+2` race 9 at the wormhole; `updateAlienAttackers` 0xd5ce0 revives dead Void every 45 s (10 s in campaign 0x29) at the wormhole ±10 000 or near the player | `createMission`, `npc_traffic_ai.md` §2.1, §7 | not built |
| Specters (race 10, ship 44): `100 < cm < 145`, chance `int(cm/144·15+5) << hardcore` %, `(nextInt(3)+2) << hardcore` ships near the player, always enemy, hull ×2.25, Dark Matter Laser ×0.7, cloak (`PlayerFighter::handleCloaking` 0xf0b00), music 149/150 | `npc_traffic_ai.md` §2.2, §5.5 | not built |
| Wanted target + wingmen, hosted turret on ship 45 | `wingmen_wanted.md` | not built |
| Terran dropship 51 (Rhino) with hosted turret, unarmed itself | campaign 102 | not built |
| Hidden-blueprint wrecks (Supernova): freighter wreck (ship 15, 13 for index 0) of race `DAT_00253754` = [1, 3, 2, 0, 2] at `DAT_00253768`, docking type 3 (hack), dead but selectable, loot `[115, 1]` while the blueprint is there | `createMission` 0xc1xxx | not built (non-combat) |
| Mining Plant 0x4a88 (3210): campaign type 0xa7 (unused by the story) and station 103 after campaign 0x54 (`createStaticObjects`), friendly, docking type 1, no defenders (103's pirates are the 102-104 rule, already built) | `space_props.md`, `campaign_levels_c.md` 3.8 | — |
| "Big battle": `raidersOn` and campaign > 0x1f and 8 % → raiders = local = 9 | `npc_traffic_ai.md` §2.2 | check `TrafficPlan` (missing) |
| Pirate ambush at stream exits (raider spawn near the player, `level + 20` %) | §2.3 | not built |
| No "emergency" spawns exist: the emergency system is the player's item 185 (`ship_combat.md` §2.5); the only timed spawns are `updateOrbit` (10 s / 45 s), `updateMissionOrbit` (Kaamo 22.5 s) and `updateAlienAttackers` | | — |

---

## 5. Remake plan

1. **Data (`SpawnSpec`, `TrafficPlan.cs`)**: new fields `turretType` (assembly `turret_002_static` / `turret_003_static`),
   `rotation` (game Euler, radians), `scale` (6), `guard` (wake calls `PirateStationAction(true)`), `invulnerable`
   (radius 0 objects), `lootOverride` (outpost item). New `NpcGroup.Special`, `Turret`, `Guard`, `Escort`.
   In `Build`: after the freighter count, roll the Terran / Vossk / carrier specials with the §2.1 draws; the special
   replaces the first freighter (battleship: `freighter = true, ship = 14, race 0, stationary = true`, position §2.2;
   carrier / Vossk: `fixedObject = "sn_carrier_terran_1" / "sn_battleship_vossk"`, `collisionId` 2005 / 2006,
   `hitRadius = 0`, `hitpoints = 9 999 999`, `noLoot`, Vossk `nameText = 1667`), then add the turrets with the §2.4
   tables (host position + offset). Pirate-base system (new `PirateBases.SystemHasBase(system)`): `escorts = 2`
   (Extreme `rnd(3) + 4`), raiders off; base station: outpost spec (`fixedObject = "station_pirates"`, `collisionId`
   1002, `hitRadius` 7500, hull = `KaamoClub.OutpostHull()`, asleep, `nameText` 441, loot §3.3, wreck + ×8 like
   `KaamoSiege`) at table ± 10 000, plus 5 (10) sleeping guards. Also add the missing "big battle" 8 % rule.
2. **Plain C# `TurretBrain.cs`** (`GoF2Remake.Flight`): §1.5 / §1.6 on a small state (yaw, pitch counter, reselect
   timer, target, ignored) with an interface for enemy info (position, forward, active, alive, race, isPlayer,
   cloaked); returns yaw / pitch deltas and a fire flag. Unit-test: convergence, limits (−600 / +100), give-up, 3 s
   pick, nearest-Euclidean, race table.
3. **`NpcShip.cs`**: an `IsTurret` branch (like `IsFixed`): no flight / avoidance / boost; each frame relations +
   `TurretBrain`; the pivot (yaw, scale 6) and gun transform (pitch) found in the turret prefab; a `Gun` with
   `NpcTables.TurretGunItem(race)` look (15 Vossk / 20 else), the fighter damage / reload, `GunRig`, shots via
   `gun.TryFire(barrelTransform)` (spawn ≈ 600 units ahead of the barrel pivot), shot sound by race (52 / 55); death:
   sound 22, `Explosion.Spawn(pos, 1)`, smoke 4.5 s, model hidden at once, `SetDead` after 4500 ms, no crate.
   Battleship death: damage every turret by 9 999 999 (not credited, no standing), explosion **×6**. Guards: on
   `Wake()` with `Spec.guard` → `traffic.PirateStationAction(true)`. Fixed objects asleep: keep the model visible but
   `untargetable` and off the hostile counter; wake on any enemy within ±50 000 per axis. Invulnerable objects:
   hull bar clamped.
4. **`Traffic.cs`**: `PirateStationAction(bool)` with the once-per-level radio flags (435-437 / 438-440, pirate
   portrait once the radio window exists); outpost death → `Session.PirateBaseDestroyed[i] = true`,
   `Session.PirateBaseRewardPending = true`; radio hints 443 / 444 in Nivelian systems (hint flags in `Settings` or
   `Session`); `Create` picks `battleship_terran` for ship 14. Optional fix: the original's hostile counter also counts
   hostile freighters / fixed objects (`IsFreighter` is excluded now).
5. **`NpcTables.cs`**: `TurretGunItem(race)`, `TurretHp = 1000`, `TurretRange = 50000`, `TurretTurnRate = 2π/4096`,
   `TurretCone = 0.05`, `TurretLead = 1500`, `TurretPickMs = 3000`, `TurretDeathMs = 4500`, pirate-base tables
   (stations, positions, loot).
6. **`CollisionVolume.cs`**: `ForFreighter(14, 0)` currently returns the Terran freighter boxes → add the 11 battleship
   boxes (§2.2) as kind 4; `ForStaticObject(2005 / 2006)` already works with the static rule.
7. **`Session` / `SaveGame`**: `PirateBaseDestroyed bool[4]` (saved, version bump, old saves: all false),
   `PirateBaseRewardPending` (not saved, like the original).
8. **Station (`StationMenu`)**: base station → 434 dialog (Security 1609, portrait {2,0,0,0,0}) after the autosave,
   close → launch at once (`Session.LaunchedFromStation`); any docking with the reward pending → 442 (Nivelian 1662)
   + 20 000 credits.
9. **`SpaceLevel` / `Backdrop` / `SpaceDust`**: the red static fog (§3.9) around the outpost when the orbit has one
   (additive / alpha fog sprites, 30 × 1638 m within ±2000 m, colour (0xE2, 0x28, 0x28)? alpha 0.5 — see
   Uncertainties).
10. **`CombatAssets`**: turret death sound 22 (`SFX_SPACE/Garbage_Explosion_01/02.ogg`), shot sound 55 is already in
    `shots`.

---

## 6. Uncertainties

1. **Turret rotation mapping**: the table rotations are game Euler (Rx·Ry·Rz) on the turret root; they must go through
   `OrbitLayout.RotationToUnity` and the turret prefabs' import turn. Needs a visual check on the battleship
   (turrets should sit on the hull: sides for ±π/2, below for π).
2. **Turret offsets vs the scaled hull**: the offsets are world units from the host origin; the battleship is drawn
   ×2, the carrier / Vossk battleship ×1. Positions look plausible (battleship turrets within ±16 000 in z) but were
   not checked against the meshes.
3. `MatrixGetDir` in `handleRotation` is assumed to return the target's forward (+Z) axis (the 1500 lead).
4. Bullet origin: `Player::shoot(slot 0, M)` with the scaled barrel matrix; the "+100 forward" becoming ~600 units is
   inferred from the scale, not traced through `Gun::shootAt`.
5. Carrier / Vossk battleship **unhittable** (radius 0, no custom boxes) is inferred from the hit-test rule; a
   Play-mode check in the original was not possible. HP 9 999 999 makes them indestructible either way.
6. Battleship explosion **×6** (type 14 ≠ 0x37e7) contradicts `ship_combat.md` §5.2 / the remake (×8); the turret-kill
   branch in the same function tests `+0xa8 == 14`, which supports ×6.
7. The killer flag of the battleship's `Player::damage(9 999 999)` on its turrets is an uninitialised register
   (probably non-zero → "by NPC", no player credit).
8. Asleep fixed objects (the outpost): assumed invisible to the radar / bullets because `Player` is inactive; the
   model itself is not hidden (no `setVisible(false)` in `PlayerFixedObject` state 5).
9. Fog colour 0xE2282880: byte order (ARGB vs RGBA) of the particle colour not verified; "red, alpha 128" is from
   `space_props.md`.
10. Guards without a route use the station-box default patrol (so they drift back ~200 km after losing the player);
    not observed.
11. `Level::pirateStationAction(true)` is called by every waking guard, but the radio runs once (`Level+0x1b0`); if a
    radio from another source is already shown it is replaced (`createRadioMessage` swaps the array).
12. Engine sound 47 on the carrier / Vossk battleship (`PlayerFixedObject` default `+0xf4 = 0x2f`) — whether it is
    audible at their distance depends on FMOD rolloff (not traced).
13. Docking-fine and unmanned dialogs at a base station: the exact precedence inside `ModStation::OnInitialize` (fine
    first, then 434) is read from a deeply nested branch; assumed "fine if applicable, else 434".
