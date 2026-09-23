# NPC ships: traffic, relations and AI (free flight)

Everything needed to put NPC ships (police/civil fighters, freighters, raiders, jumpers, wingmen) into a normal
station orbit, decoded from the native code. Units: **game units** (Unity: × 0.05 m, z mirrored, see `CLAUDE.md`)
and **milliseconds**. Addresses: Ghidra image base 0x10000. Freelance/campaign branches are only summarised.

Builds on (not repeated here): `space_props.md` §5 (first traffic summary), `space_level_setup.md` (level build
order), `weapons.md` (guns, bullets, hit test, lock-on, `Player::damage` basics), `autopilot_travel.md` (radar,
hostile counter), `mining.md`, `starmap_travel.md`.

Helper scripts, `Reference/tools/npc/`:

| script | what |
|---|---|
| `disasm.py <start> <end>` / `--func Name` | Thumb disassembly with **PLT symbol names** (demangled), local function names and literal-pool floats |
| `vtable.py <addr> [n]` | a C++ vtable resolved through the dynamic relocations (e.g. `2640c8` = PlayerFighter) |
| `freighter_boxes.py` | the bounding boxes `Level::createShip` gives to freighters / the battleship (floats lost by the decompiler) |
| `npc_tables.py` | reference implementation: HP / EMP / gun per level, fighter pools, raider odds, standings, a Monte-Carlo of an orbit's traffic (`orbit <station> <level>`) |

---

## 0. TL;DR for the Unity implementation

- **Spawning** happens once, when the orbit is built (`Level::createMission` 0xbda70, empty-mission branch). The
  RNG (`Globals::rnd`, a `java.util.Random`) is **re-seeded with `time(NULL)`** first, so traffic is random per visit:
  use `UnityEngine.Random` (or `GoF2JavaRandom` with a time seed). Groups, in array order: **local fighters**
  (system race), **jumpers** (system race, launch from the station later), **freighters**, optional carrier/battleship
  with turrets, **raiders** (75 % pirates, 25 % the system's enemy race; all of one ship model), pirate-base guards,
  late-game Specters, a Wanted target with wingmen. Counts depend on security level, player level and difficulty (§2).
- **NPC fighters are simple kinematic ships**: speed 2.0 u/ms (boost 5.5), heading turned toward the target by a
  fixed step of `dt·48/65536` per ms (≈ 0.73 rad/s, the same as a handling-100 player ship at full stick), visual bank
  up to 33°, roll auto-levelled. No lead, no velocity, no inertia (§5).
- **Target selection** (every frame while idle, re-roll every 5 s): anything within a **±50 000 u box** (±100 000 in
  the alien orbit) triggers an attack. Hostile-to-player NPCs attack the player first; neutral/friendly NPCs attack
  ships of hostile races (pirates ↔ everyone, Void ↔ everyone, Terran ↔ Vossk, Nivelian ↔ Midorian, race 10 ↔ everyone).
- **Firing**: when the target is inside a **±0.0076 cone** (unit-vector x/y in ship space) and within a **±35 000 u
  box**. NPC gun: 4 bullets, speed 16 u/ms, lifetime 3000 ms (48 000 u), reload `600 − 2·campaignMission` ms, damage
  3..18 (player level), straight from the ship centre (§3).
- **Break-off**: inside ±8000 u of the target the NPC steers along its own right vector (it keeps circling right);
  every 5 s a 20 % chance to fly straight for 5 s; 5 % chance per 5 s (100 % after losing 40 % HP) to boost for 5–8 s.
- **HP**: hull only (no shield/armor): `20 + 14·min(level,20) + 4·campaignMission` (×5 freighters, ×25 battleship,
  ×2 hardcore). EMP points `40 + 5·level`, disabled 15 s at 0.
- **Relations** (§4): pirates and Void always hostile; races 0–3 by the two-axis standing (hostile beyond ±70);
  shooting system-race (or attack-race) ships: 33 % of their max HP in damage → radio "Hold your fire!", 50 % → that
  ship turns hostile, 66 % → **all ships of that race turn hostile**, radio, the station remembers it (next visit ≥ 7
  hostile fighters + docking fine).
- **Level timers** (`Level::updateOrbit` 0xd50b0): every **10 s** one dead jumper relaunches from the station
  (0,0,0); every **45 s** all dead local fighters relaunch from the station, and dead raiders can come back as up to
  2 waves near the player (security 0 unlimited, security 1 max 3 ships).
- **Freighters** (`PlayerFixedObject`) never turn: they fly along their +Z at **1 u/ms**, unarmed, 5× HP, break into
  an animated wreck.
- **Sounds**: engine loop 46 (fighters) / 47 (freighters) / 48 (wingmen); shots by race 52/55/54/53/61/62/2276; death
  20 `Destruction_Ship_Small`; combat music 140/141/142 by hostile count; radio texts 426–447 (§8).

---

## 1. Classes, functions, fields

Class tree: `KIPlayer` ← `PlayerFighter` (fighters, wingmen), `PlayerFixedObject` (freighters, battleship, pirate
outpost, carriers), `PlayerTurret` (turrets, sentry guns), `Waypoint`, `PlayerAsteroid`, `PlayerStatic*`…
Every KIPlayer owns a `Player` (+4: HP, guns, enemy list, relation flags). All ships of the level are in
**`Level+0xf8`** (`Level::getEnemies` 0xd3e06, despite the name friends too).

**Update order**: ships are updated from **`Level::render(dt)`** 0xd4950 (per object: vtable +0x34 `update(dt)`,
then +0x24 `render`), for `Level+0xf8` ships, `+0xfc` asteroids, `+0xf4` gas clouds, `+0x100` landmarks.
`Level::update` 0xd5fcc (from `MGame::OnUpdate`) updates the bullet guns (`+0xe4` player guns, `+0xe8` NPC guns) and
runs `updateOrbit` (§7).

### 1.1 Functions

| Function | Address | Role |
|---|---|---|
| `Level::createMission` | 0xbda70 | spawns the orbit's traffic (empty mission) or a freelance mission |
| `Level::createShip(race, kind, ship, waypoint, b, isPlayer)` | 0xcf83c | one NPC: HP, EMP, position jitter, class |
| `Level::createRoute(n)` | 0xd0464 | random n-point route (freelance) |
| `Level::assignGuns` | 0xcb638 | NPC guns |
| `Level::connectPlayers` | 0xcc330 | enemy lists (what each gun can hit / each NPC may target) |
| `Level::createWingmen` / `createFighterTurrets` / `createSentryGuns` | 0xcb338 / 0xcb200 / 0xcb0d8 | hired wingmen, turrets on ships 45/51, player sentry guns |
| `Level::update` / `updateOrbit` / `updateAlienAttackers` | 0xd5fcc / 0xd50b0 / 0xd5ce0 | per-frame level logic, respawns |
| `Level::alarmAllFriends(race, radio)` / `friendTurnedEnemy(race)` | 0xd54cc / 0xd65de | police reaction |
| `Level::createRadioMessage(type, race)` | 0xd5568 | radio messages |
| `Level::enemyDied` / `friendDied` / `wingmanDied` | 0xd3f98 / 0xd426c / 0xd4278 | counters, stats |
| `Level::uncoverWanted` / `attackWanted` / `almostKillWanted` / `killWanted` | 0xd63ac / 0xd642c / 0xd64b0 / 0xd65c8 | Wanted events |
| `Level::pirateStationAction(bool)` | 0xd6338 | outpost guards woken / outpost destroyed |
| `Globals::getRandomEnemyFighter(race)` | 0xf9034 | ship model per race |
| `Globals::getShipGroup(ship, race, isPlayer)` | 0xf94a4 | meshes (already assembled in the remake) |
| `KIPlayer::KIPlayer` / `reset` / `setToSleep` / `awake` / `setDead` | 0xb2328 / 0xb2976 / 0xb29c8 / 0xb2e16 / 0xb2e08 | base state |
| `KIPlayer::setRoute` / `setJumper` / `jump` / `setWingman` | 0xb2d48 / 0xb2968 / 0xb2f4c / 0xb2d26 | |
| `KIPlayer::createCrate` / `captureCrate` / `cargoAvailable` | 0xb2e2c / 0xb2a00 / 0xb2f00 | loot container |
| `PlayerFighter::PlayerFighter` | 0xefec0 | default patrol route, detection range, loot, engine sound |
| `PlayerFighter::update` | 0xf0d90 | **the AI** (10 204 bytes) |
| `PlayerFighter::roll` | 0xf36b0 | roll auto-level |
| `PlayerFighter::setWingmanCommand` / `setSpeed` / `setRotate` / `setShootError` / `setBoostProb` | 0xf096c / 0xf0a06 / 0xf0a16 / 0xf0a2e / 0xf0a3c | |
| `PlayerFighter::cloak` / `handleCloaking` / `setAIDisabled` | 0xf0aa4 / 0xf0b00 / 0xf0d80 | race-10 cloak, scripts |
| `PlayerFighter::initPush` / `push` / `revive` / `reset` | 0xf3b00 / 0xf3c50 / 0xf3de0 / 0xf0644 | bump, respawn |
| `PlayerFixedObject::PlayerFixedObject` / `update` / `moveForward` / `setWreckedMeshId` | 0x17ece0 / 0x17f480 / 0x17f3d8 / 0x17f318 | freighters |
| `PlayerTurret::update` / `pickEnemy` / `handleRotation` | 0x182ab0 / 0x182e90 / 0x182fe4 | turrets |
| `Route::Route(int*, n)` / `Route(int*, KIPlayer**, int*, n)` | 0x140af8 / 0x140bf4 | waypoints (+ docking targets/times) |
| `Route::update(x,y,z)` / `reachWaypoint` / `getWaypoint` / `clone` / `setNewCoords` | 0x140f80 / 0x140f06 / 0x140e48 / 0x1410c8 / 0x140db6 | |
| `Waypoint::Waypoint(x,y,z,route)` | 0x183330 | a KIPlayer with a 2000-radius Player |
| `Player::Player(radius, hp, nPrim, nSec, nTurret)` | 0xaed60 | |
| `Player::damage(dmg, byNpc, item)` / `damageEmp(emp, byNpc)` / `update` | 0xafa70 / 0xaf834 / 0xb0a9c | friendly fire, EMP |
| `Player::shoot(slot, dt, …)` / `playShootSound` | 0xb08bc / 0xb03f0 | |
| `Standing::isEnemy` / `isFriend` / `getEnemyRace` / `applyKill` / `applyDelict` | 0x1428ee / 0x142964 / 0x1429fc / 0x142a3c / 0x142aa4 | |
| `Generator::getLootList(item, amount)` | 0xa1b78 | NPC loot |
| `Gun::Gun` / `Gun::calcCharacterCollision` | 0x17cf18 / 0x17e154 | NPC guns / hits |
| `Radar::draw` | 0x1554fc | hostile count → combat music |
| `Radio::update` / `RadioMessage::RadioMessage` / `triggered` | 0x180380 / 0x17c512 / 0x17c5d8 | radio display |
| `Status::checkForLevelUp` / `getWantedInCurrentOrbit` | 0xb9978 / 0xb916c | player level, wanted |
| `AERandom::reset` / `nextInt(n)` | 0x7ad32 / 0x7add2 | `time(NULL)` reseed; java.util.Random |

`PlayerFighter` vtable (0x2640c8, `vtable.py`): +0x08 setShipGroup, +0x0c awake, +0x10 setWingmanCommand,
+0x14 setLevel, **+0x18 revive**, +0x1c setSpeed, +0x20 translate, +0x24 render, +0x28 getPosition, +0x2c initPush,
+0x30 push, **+0x34 update**, +0x38 collide, +0x3c outerCollide(x,y,z), +0x40 outerCollide(v), +0x44/+0x48 setPosition,
+0x50 getProjectionVector, +0x58 projectCollisionOnSurface, +0x5c setState.

### 1.2 KIPlayer fields (all NPC kinds)

| Offset | Meaning |
|---|---|
| +0x04 | `Player*` |
| +0x08 / +0x0c | root geometry / ship group geometry (visual bank is applied to +0x0c) |
| +0x10 | turret hosted on this ship |
| +0x18 | name (String; Wanted name, "Informer" 1663, "Arms delivery" 1664, "Pirate Outpost" 441…) |
| +0x20 | copy of `Player+0x68` (EMP-disabled) |
| +0x21 | **armed** (gets a gun in `assignGuns`; 1 for fighters, 0 for ship 51 and freighters) |
| +0x24 | **race** (0 Terran, 1 Vossk, 2 Nivelian, 3 Midorian, 4–7 other, 8 Pirate, 9 Void, 10 "???" = Specter) |
| +0x28 | position (copied each frame) |
| +0x34 | current target index in the enemy list (−1 none) |
| +0x38 / +0x39 | asteroid / other non-ship flag (`Player::isAsteroid`); ships have both 0 |
| +0x3a / +0x3b | turret / sentry gun |
| +0x3c | custom collide (bounding boxes) |
| +0x3d | pirate outpost (mines ignore it) |
| +0x3e / +0x3f / +0x44 | **Wanted** target / Wanted surrendered / Wanted index |
| +0x48 | has a loot crate to drop |
| +0x4c | loot list (item, amount pairs) |
| +0x50 | Level |
| +0x54 | initial position |
| +0x68 / +0xb0 | route / original route (restored by `reset`) |
| +0x6f / +0x70 / +0x71 / +0x72 | beam-aimable / **cloaked** / lock candidate / on screen (Radar) |
| +0x74 | crate geometry |
| +0x78 | ship index used for the mesh group |
| +0x84 | **state**: 0 init, 1 fly, 3 dying, 4 dead, 5 sleeping, 6 jumping out, 7 docking approach, 8 docking, 9 docked |
| +0x88 | collidable |
| +0xa8 | type = ship index (fighters/freighters) or object id |
| +0xad / +0xae | put to sleep / "init active" (controls what `reset` does) |
| +0xcc | mission crate carrier |
| +0xd4 | ms since death (crate lifetime 60 000) |
| +0xd8 / +0xdc / +0xe0 / +0xe4 | **wingman** / formation slot 0..2 / command 0..3 / command target |
| +0xe8 / +0xec | **jumper** / ms following a waypoint (jumps at 20 000) |
| +0xf1 | visible |
| +0xf4 | engine sound event (46 fighter, 47 freighter, 48 wingman, −1 none) |
| +0xf8 / +0xfc | roll-level timer (750 ms) / levelling active |

Unused: +0x60 (speed 2.1) and +0xa4 (rotation speed 5.0) are set in the constructor but never read by the fighter
code.

### 1.3 PlayerFighter fields

| Offset | Meaning (default) |
|---|---|
| +0x124 | **detection box half-size** 50 000 (100 000 in the alien orbit) |
| +0x128 | following a waypoint this frame |
| +0x129 | **drift** mode (no steering) |
| +0x12a | **attacking** |
| +0x12b | pirate-outpost guard (waking it calls `pirateStationAction(true)`) |
| +0x138 | cloaked (race 10) |
| +0x139 | evasion/boost logic enabled (1; cleared by `setSpeed`, `setRotate`, wingman command 1) |
| +0x13a | collision avoidance enabled (1; cleared when dying) |
| +0x13c | weapon slot fired (0 primary, 1 secondary) |
| +0x140 | default patrol route (looping), cloned into +0x68 |
| +0x144 | target `Player*` |
| +0x148 / +0x1dc | wingman copy of the player route / its start index |
| +0x14c | bounding volumes (none for normal fighters) |
| +0x160 | **target position** |
| +0x16c | delta to the target, then the unit direction in ship space |
| +0x178 / +0x184 / +0x190 | crate drift direction / death spin (rad per frame) / death drift direction |
| +0x19c | smoke particle system (set 9) |
| +0x1a0 / +0x1e8 | "rotate" 2.0 / current copy: **written, never read** |
| +0x1a4 | **fire cone** 0.0076294 (0x3bf9fff6) |
| +0x1a8 | **base speed** 2.0 u/ms |
| +0x1b0 | boost probability 5 (%) |
| +0x1b4 | target re-roll timer (5001 ms) |
| +0x1bc / +0x1c0 | boost timer / boost duration |
| +0x1c8 | this frame's dt |
| +0x1d0 / +0x1d4 / +0x1d8 | last HP / damage since last panic / **panic** |
| +0x1e0 / +0x1e4 / +0x1ec | **current speed** / boost target speed / boosting |
| +0x1f0 | dying timer (1500 + rnd 1500) |
| +0x1f4 | smoking (HP < 33 %) |
| +0x204 / +0x208 | bank target / current bank (units of π/4096 rad) |
| +0x250 / +0x24c | roll-level matrix / phase |
| +0x28c / +0x290 | bank limit 750 / bank gain 15.139 |
| +0x294 / +0x2a8 / +0x2ac | ring buffer of 5 signed turn angles / index / filled |
| +0x2ad | shooting |
| +0x2b0 / +0x2b4 / +0x2bc | docking ease matrix / docked time / reserved `SpacePoint` |
| +0x2c0..+0x2d4 | cloak timers (race 10) |
| +0x2dc | AI disabled (scripts) |
| +0x2e0 | Wanted weapon toggle timer (20 000) |

### 1.4 Player fields used by the AI (see also weapons.md §1)

| Offset | Meaning |
|---|---|
| +0x40 | radius = bullet hit cube half-size (NPC 1000, 650 hardcore) |
| +0x44 | killed by an NPC (not the player) |
| +0x5c / +0x5d | **hostile to the player** / friendly to the player (recomputed every frame) |
| +0x5e | **cloaked** (NPCs do not attack cloaked targets) |
| +0x68 | EMP-disabled; +0xd8/+0xe4/+0xe8 EMP recovery |
| +0x69 | is the player's ship (PlayerEgo); counts as race 0 in NPC race checks |
| +0x6c | damage done by the player (friendly fire) |
| +0x74 | enemy list (`Array<Player*>`) |
| +0x78 / +0x84 | HP / max HP (hull; NPCs have no shield/armor: +0x88..+0x94 stay 0) |
| +0x7c / +0x80 | EMP points / max |
| +0xc3 | shooting enabled |
| +0xdc | EMP damage done by the player |
| +0xe0 | **turned enemy** |
| +0xec / +0xed | **always enemy** / **always friend** |
| +0xee | never attack |

---

## 2. Spawning (`Level::createMission` 0xbda70, empty mission)

`createMission` runs in pass 2 of `Level::init` after asteroids and gas clouds (space_level_setup.md §1). Afterwards
`createStaticObjects`, `createSentryGuns`, `createFighterTurrets`, `createWingmen`, then **`assignGuns`** and
**`connectPlayers`**.

### 2.1 Branch selection

1. No mission object → nothing.
2. **Alien orbit** (`Status::inAlienOrbit`): `n = 2`; if `level/2 − 1 + nextInt(2) ≥ 2`: `n = int(level/2 − 1 + nextInt(2))`
   (campaign 0x21/0x44: 2). Each: race 9 ship `getRandomEnemyFighter(9)` = 8 (VoidX) at
   `(nextInt(120000)−60000, nextInt(80000)−40000, nextInt(120000)−60000)`, always enemy. Nothing else.
3. **Empty mission (free flight)** → §2.2.
4. Freelance mission → §2.9 (summary).

### 2.2 Free flight: counts

`AERandom::reset(Globals::rnd)` (seed = `time(NULL)`), `createScene` (clears `Level+0xf8`), then:

```
tutorial   = system == 15 (Mido) and campaignMission < 16
r100       = nextInt(100)
escorts    = int(freelance.difficulty / 10 * 5) for freelance types 0, 0xb, 0xf, else 0      // local_194
sec        = system.securityLevel;  secEff = (sec >= 1 and hardcore) ? sec − 1 : sec
raidersOn  = (tutorial and !hardcore) ? false : r100 < {0: 90, 1: 65, 2: 35, ≥3: 10}[secEff]
raiderSpawn (Level+0x180) = Route([nextInt(100000) − 50000, 0, nextInt(50000) + 50000])
raiderRace = nextInt(100) < 75 ? 8 : enemyRace(systemRace)          // enemyRace = [1, 0, 3, 2][race], else 8
raiders (0x16c) = raidersOn ? nextInt(4) : 0
if raiders > 0:
    if hardcore: raiders = nextInt(6) + 2
    raiders = int(raiders · (1 + difficulty − 0.5))                   // ×1 normal, ×2 hardcore
    raiders += level / 4                                               // player level 0..20
if secEff == 3 and raidersOn and difficulty < 1.0: raiders = nextInt(2) + 1
if station == 78 (Var Hastra): jumpers = freighters = 0; x = 0
else: jumpers (0x164) = nextInt(2); freighters (0x168) = nextInt(5); x = nextInt(2)
local (0x160) = (tutorial ? nextInt(2) : secEff) + x + freighters / 4
if raidersOn and campaignMission > 0x1f and nextInt(100) < 8: raiders = local = 9        // "big battle"
pirateGuards = station.stationHasPirateBase() ? int((difficulty − 0.5)·5 + 5) : 0       // 5 (10 hardcore)
if system.hasPirateBase(): escorts = 2 (hardcore: nextInt(3) + 4); raidersOn = false; raiders = 0
if comingFromAlienWorld or station.isAttackedByAliens() (and campaign ≠ 0x2a):
    freighters = max(freighters, 2); raiders = nextInt(4) + 2; raidersOn = true; raiderRace = 9
    raiderSpawn = wormhole position (landmark 3) if present
wanted = Status::getWantedInCurrentOrbit(); if wanted: local = min(local, 2)
specters = 0; if 100 < campaignMission < 0x91:
    p = int(cm/144·15 + 5) << hardcore;  if nextInt(100) < p: specters = (nextInt(3) + 2) << hardcore
if station.hasAttackedFriends(): local = max(local, 7); Level+0x189 = Level+0x18a = 1    // §4.5
if jumpers + local + freighters + raiders + escorts == 0: local = 4
```

`difficulty` = `Globals::options+0x44`: **0.5 normal, 1.5 hardcore** (`Status::hardCoreMode` tests == 1.5), so every
`x·(difficulty − 0.5)` term is 0 in normal mode and doubles in hardcore. `level` = `Status+0x1c8`, 0..20, from
`Status::checkForLevelUp` 0xb9978: `xp = Status+0xa0/50 + kills + Status+0xd4/3 + Status+0xa4 + 2·missions +
campaignMission + stationsVisited`, thresholds `[0, 7, 21, 42, 70, 105, 147, 196, 252, 315, 385, 462, 546, 637, 735,
840, 952, 1071, 1197, 1330, 1650]`.

**Special orbits** (applied after the above):

| Condition | Effect |
|---|---|
| stations 100, 101, 108 and 10 | no traffic at all |
| stations 102, 103, 104 | local = jumpers = freighters = 0; raiders = nextInt(5) + 3 pirates |
| campaign 0x24/0x25 in system 5 | local = 0, no raiders |
| campaign 0x2a/0x2b (not alien orbit) | escorts = 0, no raiders |
| **black market** (system 25 Loma, `inBlackMarketSystem`) | only raiders: nextInt(4) + 6 pirates (hardcore `nextInt(3) + 2·n`) |
| **pirate loot orbit** (systems 32, 33) | only raiders: nextInt(4) + 10 pirates; they get 2× HP, speed 3.5, spawn around the player |
| station 108 (0x6c) with `Status+0x114 == 0` | pirate stronghold: 4 pirate outposts (0x37a3) at fixed positions + 6 (8) pirates, freelance mission type 4 "Mkkt Bkkt" (text 1601) |
| supernova system | no local/jumpers/freighters/raiders |
| freelance type 0xd at its target station | only 7 (6) local fighters; the first is named "Informer" |
| campaign type 0xa3 convoy stations | a special escorted freighter convoy (not traced further) |

`npc_tables.py orbit <station> <level>` prints the resulting distribution. Examples (normal difficulty):
Var Hastra (78, Mido, security 0): 68 % a raider group of 0–3 (+level/4) ships, otherwise 4 local fighters; no
freighters or jumpers. Union (55, security 2): 1–4 local, 0–1 jumper, 0–4 freighters, 26 % raiders.

### 2.3 Free flight: the ship array

`ArraySetLength(hiddenBlueprint + pirateGuards + stationHasPirateBase + specters + escorts + miningPlant +
vossk5 + terran7/8 + local + jumpers + freighters + raiders)`, filled in this order:

| # | Group | Creation | Position (game units) | Route / flags |
|---|---|---|---|---|
| 1 | **local fighters** (0x160) | `createShip(sysRace, 0, getRandomEnemyFighter(sysRace), wpLocal)` | around `wpLocal = (nextInt(20000)−10000, nextInt(20000)−10000, nextInt(30000)+20000)` ±20 000 | default patrol (§5.8) |
| 1a | Wanted (index 0 when a wanted is in this orbit) | race `wanted.race < 4 ? race : 8`, ship `wanted.getShip()` | as local | §4.6 |
| 2 | **jumpers** (0x164) | `createShip(sysRace, 0, rnd fighter, null)`, `setDead` (state 4, inactive) | (relaunched at 0,0,0 later) | own route `[nextInt(400000)−200000, nextInt(200000)−100000, nextInt(100000)+50000]`, not looping; `setJumper(true)` |
| 3 | **freighters** (0x168) | see §2.5 | `(s·(nextInt(60000)−80000), nextInt(40000)−20000, nextInt(160000)−80000)`, s = ±1 | `setMoving(true)`, fly +Z |
| 3a | Terran special (30 % if sysRace 0 and freighters > 0) replaces the first freighter | battleship `createShip(0, 1, 14)` or (30 % more, campaign > 0x67) the carrier static object 0x4974 `sn_carrier_terran_1` (HP 9 999 999) | `(nextInt(80000)−40000, nextInt(10000)−5000, nextInt(80000)+40000)`, not moving | + 7 (carrier: 8) turrets 0x1a74 around it (tables 0x253604 / 0x253544) |
| 3b | Vossk special (30 %, sysRace 1, campaign > 0x8c) | static 0x4a6b `sn_battleship_vossk` "Battleship" (1667), HP 9 999 999 | `(±40000, ±20000, 60000..140000)` | + 5 turrets 0x1a76 (table 0x2536c0) |
| 4 | **raiders** (0x16c) | `createShip(raiderRace, 0, S, raiderSpawn.waypoint)` with **one S = getRandomEnemyFighter(raiderRace) for the whole group** | around raiderSpawn `(±50000, 0, 50000..100000)` ±20 000 | default patrol |
| 5 | pirate escorts / pirate-base-system pirates (escorts) | `createShip(8, 0, rnd pirate, null)` | playerPos + `(nextInt(160000)−80000, nextInt(100000)−50000, nextInt(160000)−80000)` | default patrol |
| 6 | pirate outpost (station with an active pirate base) | static 0x37a3 `station_pirates`, "Pirate Outpost" (441), asleep | table 0x253724[pirateStationIndex] | + pirateGuards pirates at outpost + `(±nextInt(20000)+10000)` per axis, asleep, guard flag +0x12b |
| 7 | Specters (late campaign) | `createShip(10, 0, 44)`, always enemy | playerPos + `(±nextInt(50000)+20000, ±nextInt(50000)+10000, ±nextInt(50000)+20000)` | |
| 8 | mining plant / hidden-blueprint wreck | campaign/blueprint objects | | |

After `createMission`: **wingmen** are appended (`createWingmen`), then turrets for ships 45/51. NB: the raider
respawn in §7 assumes the raiders are the **last** `0x16c` entries, which is only true when no escorts/outpost/
Specters/wingmen follow them.

Pirate ambush at stream exits: if raiderRace == 8, the player arrives through a stream (`initStreamOutPosition`) and
`nextInt(100) < level + 20` (40 hardcore), the raider spawn point is moved to a point derived from the player's
position (`playerPos / k`, the divisor is a lost float).

### 2.4 `Level::createShip` 0xcf83c

```
wp = waypoint ? waypoint.pos : (0, 0, 0)
jitter = (nextInt(40000) − 20000, nextInt(40000) − 20000, nextInt(40000) − 20000)     // always drawn
L = min(level, 20)
hp = (gameWon ? 180 : 4·campaignMission) + 14·L + 20
ship 51 (0x33): hp ·= 1.7;  ship 49: ·17;  ship 44 (Specter): ·2.25
campaign 49, 50, 51, 52, 56: hp = 270
emp = 5·L + 40;  empRecoverMs = 15000
kind 1 (fixed object): hp ·= (ship 14 ? 25 : 5);  emp ·= 3;  empRecoverMs = 45000
hp = int(hp + hp·(difficulty − 0.5));  campaign 0x9a in the alien orbit and race 9: hp ·= 2
player = Player(radius = hardcore ? 650 : 1000, hp, 1 primary, 1 secondary, 0 turret slots);  setEmpData(emp, empRecoverMs)
kind 0: PlayerFighter(type = ship, race, pos = wp + jitter), setShipGroup(getShipGroup(ship, race, isPlayer)),
        LOD registration; ship 51: +0x21 (armed) = 0; ships 44/49/51: no loot
kind 1: PlayerFixedObject(ship, race, pos), bounding boxes and wreck mesh by race (§6), custom collide +0x3c = 1
setLevel(level)
```

HP table (campaign mission 20 = the remake's free play, normal difficulty; `npc_tables.py`):

| player level | 0 | 4 | 8 | 12 | 16 | 20 |
|---|---|---|---|---|---|---|
| fighter HP | 100 | 156 | 212 | 268 | 324 | 380 |
| freighter HP | 500 | 780 | 1060 | 1340 | 1620 | 1900 |
| battleship HP | 2500 | 3900 | 5300 | 6700 | 8100 | 9500 |
| EMP points (fighter) | 40 | 60 | 80 | 100 | 120 | 140 |

Initial orientation: identity (game +Z). The fighters turn toward their first waypoint at once.

### 2.5 Ship models

`Globals::getRandomEnemyFighter(race)` 0xf9034: races 4–8 and ≥ 11 use race 8.

| Race | Ships (uniform) |
|---|---|
| 0 Terran | 1 Teneta, 5 Inflict, 7 Anaan, 17 Ward, 22 Groza, 26 Hera, 27 Taipan, 28 Veteran, 33 Furious, 34 Razor 6, 36 Cormorant |
| 1 Vossk | 9 H'Soc (after DLC 1 won: 60 % 9, 25 % 41 K'Suukk, 15 % 39 S'Kanarr) |
| 2 Nivelian | 4 Dace, 12 Type 43, 16 Kinzer, 18 Hatsuyuki, 21 Aegir, 31 Salvéhn, 35 Night Owl |
| 3 Midorian | 3 Badger, 6 Hector, 19 Nuyang II, 20 Cicero, 30 Berger CrossXT |
| 8 Pirate | 2 Hiro, 11 Hernstein, 23 Azov, 24 Velasco, 25 Tyrion, 29 Mantis, 32 Wasp |
| 9 Void | 8 VoidX |
| 10 "???" | 44 Specter |

(rule: random index < 37 with race table `DAT_00254990[i] == race`, excluding 0, 8, 9, 10, 13, 14, 15.)

**Freighters**: `r = nextInt(100)`; race = system race, except 30 % (`r < 30`): Terran systems → Nivelian (2),
Nivelian systems → Terran (0); Vossk and Midorian systems always their own race. Ship **13** for Vossk, **15** for the
others (the assembled `cargo_*` prefab by race: 0 → `cargo_003_terran`, 1 → `cargo_004_vossk`, 2 → `cargo_002_nivelian`,
3 → `cargo_001_midorian` with 0–3 random container segments).

**Names**: generic NPCs have no name (empty string); names only come from Wanted (`Wanted::getName`), wingmen
(`Status::getWingmen`) and mission objects.

### 2.6 Loot (`Generator::getLootList(-1, -1)` 0xa1b78, in the PlayerFighter/PlayerFixedObject constructor)

```
n = nextInt(3);  if nextInt(3) == 0: no loot
entries = max(1, n)
each entry: up to 100 tries: item = nextInt(itemCount)
            accept if no blueprint ingredients, nextInt(100) < typeChance[item.type] (10, 40, 2, 10, 100 for
            types 0..4), nextInt(100) < item.occurrence, price > 0, item ∉ {164, 175, 217, 218};
            commodity (type 4): amount nextInt(9)+1; equipment with tech level < 8: amount nextInt(3)+1
            fallback after 100 tries: item 154 + nextInt(10) (ores), amount nextInt(9)+1
if the player has a jump drive and no Energy Cells: 10 %: first entry = 122 (Energy Cells)
```

Freighters multiply each amount by `nextInt(4)+2` with a minimum of `nextInt(5)+8` (battleship: ×`nextInt(8)+5`).
Race 9 ships get `[131 Alien Remains, nextInt(3)+1]` when they die. The crate container mesh: race 1
`container_004_vossk`, 9 `container_005_void`, 3 `container_001_midorian`, 0 `container_003_terran`, others
`container_002_nivelian`. A crate lives 60 s after the explosion.

### 2.7 Wingmen (`Level::createWingmen` 0xcb338, only if the player hired some)

Not in supernova systems or campaign 0x9e. Per hired wingman i (max 3): `getRandomEnemyFighter(Status+0x2c)` with the
RNG seeded from the wingman list, `createShip(5, 0, ship)`, placed relative to the player: right·(−1000 / 2000 / 0)
− forward·k + (0, 0 or 1000, 0), facing the player's direction; `setWingman(true, i)`, always friend, **600 HP**, name
from the list, race = `Status+0x2c`. Extra gun: item 18 (Dia EMP Mk III) EMP blaster. Then `AERandom::reset`.

Formation (command 1, recomputed each frame into a one-point looping route): slot 0 = player − right·4000 −
forward·3000, slot 1 = player + right·4000 − forward·3000, slot 2 = player + up·2000 − forward·2000. Commands:
0 toggle weapon slot, 1 follow, 2 follow the player's route, 3 attack the player's target (text 308 "Attack my target").

### 2.8 RNG

One global `java.util.Random` (`Globals::rnd`) for everything (spawning, AI decisions, loot, radio text choice),
reseeded with `time(NULL)` at the start of the free-flight branch and after `createWingmen`. Nothing about traffic is
reproducible between visits, so the remake can use `UnityEngine.Random`. (Keep `GoF2JavaRandom` only for the seeded
orbit layout.)

### 2.9 Freelance missions (summary only)

| Type | NPCs (count uses `difficulty/10`) |
|---|---|
| 1 | `int(d/10·5)+3` hostile ships of the system's enemy race + nextInt(5)+3 friends on a 3-point route |
| 2 | `int(d/10·4)+2` hostiles at a route start, friends with 3× HP |
| 3, 5 | N sleeping pirates, the last carries the mission crate ("Hijacker" 1611) |
| 4 | `int(d/10·5)+2` sleeping pirates on a route |
| 6 | one sleeping pirate with 3× HP, speed 3.0 |
| 7 | space junk + pirates (space_props.md §3) |
| 9 | 5 fixed-position freighters of the client race + sleeping attackers |
| 10 | enemy freighters (0.7× HP) with sleeping escorts |
| 0xc | escort an agent's ship (HP 9 999 999, speed 3.0) against sleeping pirates |
| 0xf, 0xb8, 0xb7 | docking/production routes with `Route` docking targets (states 7–9) |

---

## 3. NPC equipment (`Level::assignGuns` 0xcb638)

One `Gun` per armed ship (`KIPlayer+0x21`), created as
`Gun(slot 0, damage, count 4, ammo −1, lifetime 3000, reload 600 − 2·cm, speed 16.0)` (cm = campaign mission,
45 when the game is won), `setFriendGun(true)`, mount offset **(0, 0, 0)** (bullets start at the ship centre), no
spread, no lead. Renderer `ObjectGun(projectile mesh, 10001)`; rocket types use `RocketGun`.

```
v = clamp(int(0.9·(level − 2)), 0, 20);  v = int(v + v·(difficulty − 0.5));  if v > 21: v = 22
damage = (v == 0) ? 3 : v + 2                          // campaign mission 4: 1
race 9 (not wingman, not always-friend): damage ·= 0.8 (campaign 16: ·2)
campaign 49..52, 56: damage = 5;  campaign 0x50 turrets ·1.7;  campaign 0x46: ·2.5
```

| Race | item used for visuals (`Gun::setIndex`) | projectile mesh | shot sound (`DAT_002526c0`) |
|---|---|---|---|
| 0 Terran | 0 Nirai Impulse EX 1 (laser) | 6754 `projectile_000_anim_add` | 52 |
| 1 Vossk | 3 V'skorr | 6760 `projectile_003_anim_add` | 55 |
| 2 Nivelian | 7 Berger Retribution | 6764 `projectile_007_anim_add` | 54 |
| 3 Midorian | 25 128MJ Railgun | 6802 `projectile_026_anim_add` | 53 |
| 9 Void | 5 Berger Focus I | 6762 `projectile_005_anim_add` | 62 Laser_Void |
| 10 "???" | 229 Dark Matter Laser, damage ×0.7 | 19091 `sn_projectile_229_anim_alpha` | 2276 |
| others (pirates) | 19 Gram Blaster (sort 1, billboard) | 6795 `projectile_019_anim_add` | 61 Laser_Enemy |

Only the damage, speed, lifetime and reload above are used (not the item's own stats). NPC fire: `Player::shoot(slot
= +0x13c, dt)`, i.e. the gun fires whenever its reload has passed while the fire condition (§5.4) holds.

DPS per NPC (normal, cm 20): level 0–4: 3 dmg / 0.56 s ≈ 5.4; level 10: 9 → 16; level 20: 18 → 32.

Special guns:
- **Wanted** target: `Wanted::getWeapon()` item (its sort), damage ×4; rocket sorts become a `RocketGun` with speed 8,
  lifetime 10 000, reload 3000, damage ×4. Wanted ships 45–48 also get a G'liissk rocket gun (item 31, damage ×4
  of the base, count 4, lifetime 10 000, reload 3000, speed 8).
- Turrets without host: sort 1, item 15 (Vossk) or 20 Ridil; sentry guns copy items 211–213 (attr 9/11/12/13);
  turrets hosted on ships 45/51: item 22, damage ×0.5.
- Wingmen: additionally item 18 (Dia EMP Mk III) EMP blaster: Gun(count 4, lifetime 3000, reload 400, speed 16),
  EMP = item attr 10.

NPC bullets hit the targets in the **owner's enemy list** (§4.4) with the normal cube test (weapons.md §3.4), damage
via `Player::damage(target, dmg, byNpc = true)`. Modifiers in `Gun::calcCharacterCollision`: a **non-hostile NPC's
bullet hitting the player does 20 %** of its damage; a hostile NPC's bullet on the player docked at a docking point
75 %.

Shields/armor: none. EMP points (`Player+0x7c`) `40 + 5·level` (freighters ×3); at 0 the ship is **disabled**
(`Player+0x68`): it stops moving and turning (the fighter still runs its targeting), EMP sparks particles on, and the
points refill linearly over 15 000 ms (45 000 freighters) (`Player::update` 0xb0a9c).

---

## 4. Relations

### 4.1 Standing (`Standing`, `Status::getStanding`)

Two axes, clamped to ±100: **s0 = Terran(+)/Vossk(−)**, **s1 = Nivelian(+)/Midorian(−)**. New game: s0 = 30, s1 = 0.
A **signature** item (sort 29, items 189–192 "Signature: Terran/Vossk/Nivelian/Midorian") overrides everything:
that race is friend, its rival enemy.

| | no signature | signature race S |
|---|---|---|
| `isEnemy(0)` / `(1)` | s0 ≤ −71 / s0 > 70 | S == 1 / S == 0 |
| `isEnemy(2)` / `(3)` | s1 ≤ −71 / s1 > 70 | S == 3 / S == 2 |
| `isFriend(0)` / `(1)` | s0 ≥ 71 / s0 < −70 | S == 0 / S == 1 |
| `isFriend(2)` / `(3)` | s1 ≥ 71 / s1 < −70 | S == 2 / S == 3 |
| other races | never enemy/friend by standing | |

`applyDelict(race, p)` (p doubled in hardcore): race 0: s0 −= p; 1: s0 += p; 2: s1 −= p; 3: s1 += p.
Callers: kill a ship of race r (not Wanted, killed by the player, not black market) → `applyDelict(r, 5)`; kill a
pirate → `applyDelict(enemyRace(systemRace), 1)` (i.e. +1 toward the system race; not with a signature); steal cargo
(collect a crate of a non-asteroid) → 2; EMP-disable a ship → 2; mission completed → −5; losing a signature → 100.
`getEnemyRace(r)` / `SolarSystem::getAttackRace` = `[1, 0, 3, 2][r]` (else 8).

### 4.2 Hostility to the player (every frame, `PlayerFighter::update`, same in `PlayerFixedObject::update`, `PlayerTurret::update`)

```
if !surrendered (+0x3f):
    hostile = race ∈ {8, 9}           ? true  : wingman ? false : Standing.isEnemy(race)
    friend  = race ∈ {8, 9}           ? false : wingman ? true  : Standing.isFriend(race)
else if damageByPlayer (Player+0x6c) > maxHP / 20: hostile = true
black market with toll paid (Status+0x110) and race 8: hostile = friend = false
turnedEnemy (Player+0xe0):  hostile = true, friend = false
alwaysFriend (Player+0xed): hostile = false, friend = true
```

`setAlwaysEnemy` sets +0xec, +0x5c = 1 and turned-enemy +0xe0 = 1; `setAlwaysFriend` sets +0xed and friend.
Radar colours (weapons.md §9): hostile red, friend green, otherwise neutral yellow.

### 4.3 NPC vs NPC

No standing between NPCs. A (non-wingman) NPC of race a treats b as hostile when
`(a==8) != (b==8)`, `(a==9) != (b==9)`, `(a==10) != (b==10)`, `{a,b} == {0,1}` or `{a,b} == {2,3}`
(`PlayerFighter::update`, `PlayerTurret::pickEnemy` 0x182e90). The player's ship counts as race 0 here. Wingmen
treat anything hostile to the player (or their command target) as hostile.

### 4.4 Enemy lists (`Level::connectPlayers` 0xcc330)

- Player: every ship, asteroid and gas cloud (weapons.md §3.4).
- NPC (normal case): **index 0 = the player**, then every other ship of the level whose **race differs** from its own
  (wingmen: all other ships). Same-race ships are never targets and never hit by each other's bullets. Race-10 ships
  in free flight get only the player.

### 4.5 Friendly fire and police reaction (`Player::damage` 0xafa70, `damageEmp` 0xaf834)

Only for player damage (`byNpc == false`) to a ship that is not always-enemy, not Void/race 10, not a wingman, and not
already hostile unless turned (`!hostile || turned`), **and whose race is the system race or the system's attack
race** (others never react):

```
dmgByPlayer += damage
if dmgByPlayer > 0.33·maxHP (hardcore 0.10):  friendTurnedEnemy(race)      → radio 0 once per level ("Hold your fire!")
     and if the player's signature is this race: lose the signature item, applyDelict(sig, 100), HUD event 0x1f
if dmgByPlayer ≥ 0.50·maxHP (0.25): same signature check (race < 4, not Wanted); **this ship turns enemy** (+0xe0)
if dmgByPlayer ≥ 0.66·maxHP (0.40): alarmAllFriends(race, true)
```

`alarmAllFriends(race, radio)` 0xd54cc: **every ship of that race becomes always-enemy**; the first time with radio:
radio 1 ("He's crazy! Blow him away!" etc.; black market: type 0xc), and if race == system race
`Station::setAttackedFriends(true)`.

EMP: player EMP damage to a system-race ship adds to `Player+0xdc`; above `maxEmp/3` it turns enemy +
`friendTurnedEnemy`. Disabling a system-race ship (EMP 0) → `alarmAllFriends(race, false)` (no radio) and
`applyDisable` (standing 2).

Pirates in the black market: any player damage to a pirate there → the pirate turns enemy, all pirates alarmed
(radio 0xc), toll revoked (`Status+0x111 = 1`, `+0x110 = 0`).

**Consequences on later visits**: `createMission` sees `Station::hasAttackedFriends()` → at least 7 local fighters and
flag `Level+0x18a`; `updateOrbit` then calls `alarmAllFriends(systemRace, false)` (all hostile immediately) and radio 2
("He's back!"). Docking at such a station (or any station of a race you are enemy with) costs a fine
(`ModStation::OnTouchEnd` 0xea4ec): attacked friends `level·150 + 1000` credits, enemy race `|standing|/100·2800 ±100`
(×10 hardcore); paying clears the flag.

### 4.6 Wanted targets (basics)

`Status::getWantedInCurrentOrbit` 0xb916c: an active, not terminated Wanted whose current location is this station
(if several, the one with the lowest required bounties). It becomes ship 0 of the local group:
HP `int(h + h·(difficulty − 0.5))` with `h = 15·min(level,20) + wanted.hitpoints + 4·cm`, name, loot
`[wanted.loot, wanted.lootAmount]`, `+0x3e = 1`, speed **4.5** (`setSpeed`, disables boost/evasion), its own weapon
(§3); `wanted.numWingmen` wingmen of the same race with half its HP.

- It is **neutral** until the player **locks it on the radar** (`Radar+4 == this`): always-enemy +
  `uncoverWanted` (radio type 0x12, its wingmen turn hostile), or damages it: `attackWanted` (radio 0x10, wingmen
  hostile).
- Below 1/3 HP: `almostKillWanted` (storyline wanteds surrender: become friendly, mission won).
- Killed: `killWanted` (radio 0x11 "A job well done." 3151–3155), `Wanted::setTerminated`, reward credits
  (`Wanted::getReward`), `Status::incCollectedBounties`.
- Every 20 s it toggles its fired slot if it has a secondary gun.

---

## 5. AI behaviour (`PlayerFighter::update` 0xf0d90)

### 5.1 States

| State | Name | Behaviour |
|---|---|---|
| 0 | init | → 1 next frame |
| 1 | **fly** | targeting, steering, firing, boost (§5.3–5.8) |
| 3 | dying | spin and drift, then explode (§5.10) |
| 4 | dead | explosion, crate; inactive after it (§5.10) |
| 5 | **sleeping** | invisible when hostile (campaign > 1); wakes when its target is inside the ±50 000 box, or when hostile and the player is inside ±25 000 per axis |
| 6 | **jumping out** | speed ×1.1 per frame, moves `int(dt·speed)`; above 100 u/ms → `setDead` (vanishes) |
| 7 / 8 / 9 | docking approach / docking / docked | only on `Route`s with docking targets (missions) |

### 5.2 Per-frame pseudo-code

```
update(dt):
  if state == 4 and !explosion.playing and (!hasCrate or deadMs > 60000): active = false; return
  boostTimer += dt; reselectTimer += dt
  pos = geometry.position
  recompute hostile / friend (§4.2); Wanted lock/weapon rules (§4.6)
  if !wingman and route == null: route = clone(defaultPatrol)
  if wingman and command == 1: one-point looping route at the formation slot (§2.7)
  if state ∈ {3, 4}: stop the engine sound
  else:
      Player.update(dt)                               // EMP recovery, 3D engine sound (46 / 47 / 48)
      if !aiDisabled: TARGETING (§5.3)
      if jumper and followingWaypoint: jumpMs += dt; if jumpMs ≥ 20000: jumpMs = 0; state = 6   else jumpMs = 0
  delta = targetPos − pos
  if hostile and (state == 5 or wingman command 1) and detectRange > 0 and |player − pos| < 25000 on all axes:
      state = 1; visible; active                      // sleepers wake near the player
  smoke/fire particles while HP < 33 % of max (not when docked)
  if HP < 1 and state ∉ {3, 4}: DEATH (§5.10)
  if aiDisabled: return
  switch state: 0 → 1;  1, 7 → FLY (§5.4–5.9);  3, 4 → §5.10;  5 → wake check;  6 → jump;  8, 9 → docking
```

### 5.3 Target selection

`enemies` = the NPC's enemy list (index 0 = player). "In the box" = |Δx|, |Δy|, |Δz| < detectRange (50 000;
100 000 in the alien orbit).

```
idx = targetIndex (+0x34);  if idx ≥ n: idx = −1
if !attacking: idx = −1
else if idx ≥ 0 and !enemies[idx].active: attacking = false
target = null
if reselectTimer < 5001:
    if !attacking:
        for i in 0..n−1 (active, alive): if (race ≠ 8 and turnedEnemy) or inBox(enemies[i]): idx = i; attacking = true; break
else:                                                  // every 5 s
    drift = !drift and nextInt(100) < 20                // start flying straight 20 %, always stop after 5 s
    reselectTimer = 0
    if nextInt(100) < 30 and n > 1:
        attacking = false
        5 tries: i = nextInt(n); if enemies[i].active and ((race ≠ 8 and turnedEnemy) or inBox): idx = i; attacking = true; break
        if !attacking: idx = 0
    else: idx = 0
    wingman command 3: idx = index of the command target (if alive, not always-friend); dead → setWingmanCommand(1)
    if enemies[idx].active and alive: if !inBox(enemies[idx]): idx = −1
    else: idx = −1; attacking = false
if !hostile and idx == 0: idx = 1; attacking = false      // neutral/friendly NPCs never keep the player
if !(wingman and command == 3) and idx > 0:
    idx = −1
    for i in 1..n−1 (active, alive; player ship = race 0; objects without KIPlayer skipped):
        if (!wingman and racesHostile(race, raceOf(i))) or (wingman and (enemies[i].hostileToPlayer or i == commandTarget)):
            idx = i; attacking = true; break              // no distance check here
if wingman and !attacking and command == 1: idx = −1
followingWaypoint = false
if idx == −1 and route:
    if route.waypoint == null (route finished) or !active: idx = 0; target = player; targetPos = player position
    else: route.update(pos); wp = route.waypoint
          if wp: docking target? (states 7/8) : targetPos = wp.pos; followingWaypoint = true
else if idx ≥ 0:
    if neverAttack: (route as above)
    else: target = enemies[idx]; targetPos = target.position
```

Effective behaviour:
- **Hostile NPCs** (pirates, Void, enemies by standing, turned ships) patrol until the player (index 0) is inside
  the ±50 000 box, then attack the player. If the player is out of the box but another ship is in it, they attack the
  first race-hostile ship of the level (pirates: any non-pirate) regardless of distance.
- **Neutral/friendly NPCs** (police, civilians): whenever the player or any other listed ship is in their box, they
  attack the first race-hostile ship anywhere in the level (e.g. Terran police vs pirates or Vossk raiders).
- A turned (attacked) NPC (`Player+0xe0`, race ≠ 8) attacks the player at any distance.
- Every 5 s the target may be re-rolled (30 %) or reset to the player (70 %), then dropped if out of the box.
- A ship whose non-looping route is finished steers toward the player without firing (until the next scan finds it).

### 5.4 Steering, fire and bank (state 1/7), verified in the disassembly

```
dir = targetPos − pos
if target and !followingWaypoint:
    r = 8000 (12000 if the target is the player docked at a docking point)
    if |dir| < r on all axes: dir = own right vector            // break off: keeps turning right
dirN  = normalize(dir)
local = inverse(R)·dirN;  local.y = −local.y                     // ship-space unit direction
disabledCopy = Player+0x68

// FIRE
if attacking and !followingWaypoint and target and !neverAttack:
    if target.cloaked (Player+0x5e): attacking = false; if shooting: stopShooting(slot); shooting = false
    else if |local.x| < 0.0076294 and |local.y| < 0.0076294 and |targetPos − pos| < 35000 on all axes:
        if !armed (+0x21) or !target.active or target.dead: attacking = false
        else if target is the player docked at a docking point and target.y > own.y: attacking = false   // 0xf2cfa: shoots only down/level
        else: Player.shoot(slot +0x13c, dt); shooting = true

// TURN (skipped while drifting: bank target 0, averages reset)
fwd = R.forward
h   = normalize(fwd + normalize(dirN − fwd) · dt·48/65536)      // 0x37800000 = 1/65536, dt·3·16
if |h − dirN|₁ < 0.0625: h = dirN                                 // snap
a = acos(dot(fwd, h)); if acos(dot(R.right, h)) < π/2: a = −a    // signed turn this frame
ring[5] ← a; avg = mean of the filled samples (all 5 once filled)
bankTarget = clamp(avg · 750 · 15.139, −750, 750)
R = basis(right = normalize(cross(R.up, h)), up = normalize(cross(h, right)), forward = h)

// BANK / LEVEL
if levelling: roll(dt)                                             // §5.6
bank → bankTarget at dt·1.25/3.9 per ms
if bank == bankTarget: after 750 ms without change: levelling = true   else levelTimer = 750
child (mesh group) rotation = rotation about forward by bank·π/4096   (±0.575 rad = 33° max)

// MOVE
if !disabled: pos += R.forward · int(dt · speed); if levelling: R ·= rollMatrix
collision avoidance (§5.7); push(dt) (bump after a collision)
```

Turn rate: the heading moves by `k = 0.000732·dt` per frame toward the target direction, so the angular rate is
`0.732·cos(α/2)` rad/s for an angle α to the target: **42°/s** when nearly aligned, slower when the target is behind
(0 exactly behind). The player's flight model (`GoF2FlightModel`, `angle = dt·rate·2π/65536·0.033` with
`rate = 750·H/63`) gives 0.000753 rad/ms for H = 20 (handling 100, no agility) at full stick, i.e. **NPCs turn like a
handling-100 ship**, but without ramp-up, inertia or speed loss. Unlike the player's `moveToPosition` autopilot
(autopilot_travel.md) there is no world-up constraint; the up vector is carried along and only the auto-level roll
restores it.

Because the break-off replaces the target direction by the ship's right vector before the cone test, an NPC **never
fires at a target inside its ±8000 box**: attack runs happen between 8000 and 35 000 units (per axis), then the ship
turns away to the right until it is out of the box and comes around again.

The fire cone is tight (±0.0076 of a unit vector ≈ ±0.44°): combined with the snap (L1 < 0.0625) an NPC fires as soon
as its heading snaps onto the target, i.e. from about 3° off. At 20 000 u the cone is ±150 u wide, much smaller than
the ±1000 hit cube, so NPC shots at a non-moving target nearly always hit; moving targets escape because there is no
lead.

The `setRotate` / `+0x1a0` value and `setShootError` exist but the rotation value is never read (§1.3).

### 5.5 Speed, boost, evasion (`+0x139` enabled)

```
if HP < lastHP: dmg += lastHP − HP; lastHP = HP
    if dmg / maxHP ≥ 40 %: dmg = 0; boostTimer = 10000; panic = true
if boostTimer > 5000 and !boosting:
    boostTimer = 0
    if panic or nextInt(100) < boostProb (5):
        boostDuration = 5000 + nextInt(3000); boosting = true; targetSpeed = 5.5
if boosting:
    if boostTimer > boostDuration: boostTimer = 0; panic = false; targetSpeed = baseSpeed (2.0)
    if targetSpeed > 0:
        speed ·= (speed < targetSpeed) ? 1.05 : 0.95                  // per FRAME
        if speed ≥ 5.5 or speed < baseSpeed: speed = targetSpeed; if targetSpeed == baseSpeed: boosting = false; targetSpeed = 0
```

At 30 fps the ship reaches 5.5 u/ms in ~0.7 s and slows back in ~0.7 s. Race 10 (Specter) also **cloaks**
(`handleCloaking`): when panicking 50 % chance, otherwise every 8 s a 30 % chance; cloaked for `9000 + nextInt(5000)`
ms with 2000 ms fade in/out (exhaust hidden, `+0x70` set so the radar/lock ignore it).

Evasion summary: circle right within 8000 u; 20 %/5 s fly straight for 5 s; boost 5 %/5 s or after losing 40 % HP.
There is no fleeing and no retreat to the station.

### 5.6 Roll auto-level (`PlayerFighter::roll` 0xf36b0)

Starts after the bank target has stayed equal to the bank for 750 ms. With `rx = R.right.y`, `uy = R.up.y` and
`dt' = min(dt, 60)`: stop when `|rx| < 0.015` and `uy > 0` (identity roll matrix). Otherwise rotate about forward by
`dt'·rate` with rate −0.00075 (rx ≥ 0, uy < 0), +0.00075 (rx < 0, uy < 0), ±0.00035 (flip phase), ∓0.00025 or ∓0.0002
near level (|rx| ≤ 0.3), i.e. the same scheme as the player's auto-level (0.00025–0.00075 rad/ms).

### 5.7 Collision avoidance (`+0x13a`)

After moving, for the first landmark (station, gate…) and then the first other ship whose **outer bounding volume**
contains the NPC (`outerCollide`, vtable +0x40): `p = getProjectionVector(pos)`; if p ≠ 0:
`dir = normalize(fwd + (p − fwd)·speed·0.03)`, `setDirection(dir, up = (0,1,0))`, and an extra `moveForward(dt·speed)`.
Only objects with bounding volumes take part (station parts, freighters, battleship); fighters ignore each other and
**fly through asteroids**. The player collides only with bounding-volume objects too (`PlayerEgo::calcCollision`
0xab550: slides along them); **the player flies through NPC fighters**; touching an asteroid destroys it (20 damage to
the player).

### 5.8 Routes and waypoints

- `Route`: list of `Waypoint`s (KIPlayer with a 2000-radius Player, positions stored as ints), current index, loop
  flag, optional docking targets (KIPlayer) and docking times. `Route::update(pos)`: the current waypoint is reached
  when **|pos − wp| < 2000 on all three axes** (and it has no docking target) → next; after the last: back to 0 if
  looping, else the route ends (`getWaypoint` returns null).
- **Default patrol** (`PlayerFighter` constructor, every fighter): 4 corner points
  P0 = (nextInt(25000)−30000, nextInt(10000)−10000, nextInt(25000)+20000),
  P1 = (nextInt(25000)+5000, nextInt(10000)−10000, nextInt(25000)+20000),
  P2 = (nextInt(25000)+5000, nextInt(10000)−10000, nextInt(25000)+55000),
  P3 = (nextInt(25000)−30000, nextInt(10000)−10000, nextInt(25000)+55000);
  `nextInt(3)·3+6` coordinates = **2, 3 or 4 of them in random order, without repeats, looping**. So all fighters
  (police, raiders, escorts) patrol a box x ∈ [−30 000, 30 000] (excluding ±5000), y ∈ [−10 000, 0], z ∈ [20 000,
  80 000] in front of the station (the player's undock spawn is at z ≈ 10 000). Race 9 uses the shared looping square
  (±40 000, 0, ±40 000) instead. Campaign mission 0x29: no default route.
- Raiders spawn 50–100 km away but patrol the same box, so they **fly toward the station area** and attack the
  player when they get within 50 000.
- Wingman command 2: an exact clone of the player's route (`Route::getExactClone`); at its end → command 1.
- Docking routes (missions): waypoint with a docking target → state 7: approach the nearest free navigation
  `SpacePoint` of the target; within 2000 → state 8: ease into the nearest docking point (`EaseInOutMatrix`), docked
  (state 9, exhaust off) when closer than `DAT_00254820[type]` (110–480 u); leave after the route's docking time.

### 5.9 Jumpers (arrival and departure)

Jumpers are system-race fighters created dead with a far, non-looping one-point route. `updateOrbit` relaunches one
every 10 s at **(0, 0, 0)** (the station: they appear to launch from it) via `revive` (full HP, speed 2.0, new loot).
They fly toward their route point; after **20 s of waypoint following** (reset while they fight) they switch to state 6
and accelerate away (×1.1 per frame to 100 u/ms, ~1–2 s) and vanish (`setDead`); 10 s later they may relaunch. No
jump effect is drawn by this code. NPCs never dock at the station or use the jumpgate in free flight.

### 5.10 Death

```
on HP < 1:
    Wanted: reward (§4.6)
    if !hostile: Level::friendDied (+ wingmanDied: removed from the hired list)
    else: race 9 → loot [131, nextInt(3)+1]; race 8 killed by the player → Status::incPirateKills
          Level::enemyDied(type, killedByNpc): enemies left −1, kills +1, player kill → Status::incKills (+ medals)
    state = 3; dyingMs = 1500 + nextInt(1500); deathDir = forward
    particle burst (set Level+0x3c), sound 20 Destruction_Ship_Small (3D)
    spin = normalize(rnd(200)−100 ×3) · 0.05   (rad per frame, Euler)
    smoke on, EMP sparks off, hasCrate = cargoAvailable, exhaust off
state 3: R ·= rotation(spin) each frame; pos += deathDir · dt · speed; dyingMs −= dt;
         at < 0: Explosion(type 0, with fire streaks) at pos, smoke off, bombForce = 50 + nextInt(50)·0.01,
         crateDir random, state 4, crate (createCrate: container by race, void type 4) if cargo
state 4: explosion; the crate drifts along crateDir·bombForce (×0.98 per frame, 0 below 0.05) and spins
         (dt/2 /65536·2π per frame); after 60 s (or when there is no crate and the explosion ended): inactive
```

Killed-by-NPC ships (`Player+0x44`) give no player kill/standing. Respawn: §7.

---

## 6. Freighters and big ships (`PlayerFixedObject`)

- **Movement** (`update` 0x17f480): if not EMP-disabled and `setMoving(true)`: `moveForward(dt)`: **1 unit per ms
  along the object's forward** (identity rotation → game +Z; the stored integer z is simply incremented). They never
  turn, never despawn and ignore everything (no avoidance). Carriers/battleships/the outpost are not moving.
- Relations recomputed per frame like fighters (§4.2). **Unarmed** (never `+0x21`).
- Sleeping (state 5): wakes when any enemy-list entry is within ±50 000.
- HP ×5 (battleship ×25), EMP ×3 with 45 s recovery. Engine sound 47 (battleship none).
- **Death**: `friendDied`/`enemyDied`, crate if cargo, the hull is replaced by its **wreck** mesh with an animation
  (`cargo_001_midorian_explosion_anim` 18300, `cargo_002_nivelian_…` 18301, `cargo_003_terran_…` 18302,
  `cargo_004_vossk_…` 18303, `battleship_terran_explosion_anim` 18304), which keeps flying at 1 u/ms while
  animating; sound 20; explosion scaled ×6 (×8 battleship 0x37e7 and pirate outpost) with camera rumble
  `1 − min(d, 30000)/30000` fading over 2000 ms; after the animation state 4, wreck material swapped (0x8248..0x824d)
  and wreck collision boxes (`Globals::getWreckCollision`). The battleship's death destroys all its turrets.
- **Collision boxes** (`freighter_boxes.py`, centre offset / full size in ship space): Terran freighter (0,−73,123)/
  (3000,2860,10430), (0,−280,−4257)/(3470,1815,2200), (0,−770,−4279)/(5220,680,2270); Nivelian (0,−85,24)/
  (4335,1245,10880), (0,710,292)/(2990,935,11450), (0,1510,−2886)/(2750,1010,2750); Midorian (0,−199,4708)/
  (980,1530,1240), (0,−14,−98)/(4500,1405,8860); Vossk 5 boxes; battleship 11 boxes (3 partly lost). These are
  what player bullets hit (custom collide) and what the player/fighters collide with.
- **Turrets** (`PlayerTurret`, around the Terran carrier/battleship or Vossk battleship specials): pick the nearest
  race-hostile enemy (or the player if the turret is hostile) within **50 000** every 3000 ms, yaw/pitch at
  `dt/4096·2π` rad per ms, fire when the target is within ±0.05 (normalized local x/y), HP 1000, death sound 22.

---

## 7. Level-side timing (`Level::update` 0xd5fcc → `updateOrbit` 0xd50b0)

`Level::update` itself only updates bullets, particles, gamma rays and LOD; with an empty mission it calls
`updateOrbit(dt)`, and `updateAlienAttackers` when the station is under alien attack / in the alien orbit.

```
updateOrbit(dt):
  respawnMs (+0x174) += dt; jumperMs (+0x178) += dt
  if Level+0x18a (station remembers the attack) and the player's radio exists:
      alarmAllFriends(systemRace, false); radio 2 ("He's back!"…); Level+0x18a = 0
  if jumperMs > 10000: jumperMs = 0
      first ship that is a jumper, dead, inactive, not Wanted: revive(); setPosition(0, 0, 0)        // (10000, 0, −70000) if outside local+jumpers
  if respawnMs ≥ 45001: respawnMs = 0
      deadRaiders = dead & inactive non-wingmen among the last `raiders` entries
      for each ship i:
          if i < local and dead & inactive & not Wanted: revive(); setPosition(0, 0, 0)              // police relaunch from the station
          if deadRaiders > 1 and waves (+0x184) < 2 and raiders > 0 and i is one of the last `raiders`
             and dead & inactive & not Wanted
             and (race == 9 or security == 0 or (security == 1 and respawned (+0x17c) ≤ 2)):     // not in the alien orbit
                respawned++; revive(); position = player + (±(60000 + nextInt(60000)), ±(5000 + nextInt(5000)), ±(60000 + nextInt(60000)))
      if any raider came back: waves++
```

So: dead police/civil fighters come back every 45 s from the station; a destroyed raider group comes back at most
twice (only in security-0 systems, 3 ships total in security 1, never in 2–3), 60–120 km from the player, and flies in.
"Dead & inactive" means after the explosion and after the crate was taken or expired (60 s).

`updateAlienAttackers` 0xd5ce0 (Void attacks, campaign-driven): every 45 000 ms (10 000 in campaign 0x29) dead race-9
ships revive at the wormhole ±10 000 or at the player + (±40 000, ±30 000, fixed z offset).

There is **no other spawning over time** in free flight: no timed pirate arrivals, no despawning of far ships.

---

## 8. Sounds, music, radio

| What | Id | Notes |
|---|---|---|
| NPC engine loop | 46 `Spaceship_Engine_Enemy`, 47 `…_Freighter`, 48 `…_Wingmen` | 3D, velocity from position delta (`Player::update`); off while sleeping/dying; campaign mission 1: none |
| NPC shots | `DAT_002526c0[race]`: 52, 55, 54, 53, 61 (races 4–8, ≥ 11), 62 (Void), 2276 (race 10) | one-shot per shot; menu levels mute NPC shots |
| NPC destroyed | 20 `Destruction_Ship_Small` at death start (+ the explosion's own sound) | freighters too; turrets 22 |
| Combat music (`Radar::draw`) | hostiles = active, alive, `Player+0x5c` ships (anywhere) and race-10 ships: 0 → system music `DAT_00252010[race]` = 134 Terran, 139 Vossk, 138 Nivelian, 137 Midorian (145 Void orbit, 146 home base 108, 147 station 101, 148 supernova, 152 deep science); 1–2 → **140 `Space_Combat_Low`**, 3–4 → **141 `Mid`**, 5+ → **142 `Full`**; Wanted always-enemy present → 151; race 10 → 149/150; alien attack → 136 | music switches with fade |

Radio messages (`Level::createRadioMessage` 0xd5568; only with an empty mission; shown by `Radio::update` for
`lines·2000 + 1500` ms with a portrait by race: 0 → image 0x40, 2 → 0x41, 3 → 0x15, 8 → 9, others 0x3f; voice via
`Globals::getDialogueSoundId`, voice events unmapped):

| Type | Trigger | Text ids (random) |
|---|---|---|
| 0 | `friendTurnedEnemy` (33 % friendly fire), once per level (`Level+0x188`) | 426–428 "Hold your fire! What's gotten into you?!" / "Hey! What are you doing? Stop it!" / "Help! I'm being attacked!" |
| 1 | `alarmAllFriends(race, true)`, once (`Level+0x189`) | 429–431 "He's crazy! Blow him away!" / "Unauthorized use of weapons! Eliminate the target!" / "This is going too far. We need backup!" |
| 2 | returning to a station you attacked (`Level+0x18a`) | 445–447 "He's back! …" |
| 3 | pirate outpost guard wakes (`pirateStationAction(true)`) | 435–437 "Somebody's coming. Finish them off!" … |
| 4 | pirate outpost destroyed | 438–440 "Nooooo!" … (and 442 reward text elsewhere) |
| 5 / 6 | pirate activity hints | 443 / 444 |
| 9–0xd | black market (Loma) arrival, toll paid/refused | 449–455 |
| 0x10 / 0x11 / 0x12 | Wanted attacked / killed / uncovered | tables 0x254270 / 3151–3155 / 0x2542fc (+3141–3146) |

Stations in the campaign list `Status+0x90` suppress types 0 and 1. No "enemy approaching" HUD message exists in free
flight (those texts are campaign radio).

---

## 9. Unity build recipe

Consistent with the remake: `GoF2SpaceLevel` builds the orbit; ships are `Resources/Assembled/main/ships/ship_XXX_*`
prefabs (`db.Assemblies.Find(a => a.category == "ships" && a.name.StartsWith($"ship_{idx:000}_"))`), NPC variant via
`GoF2AssembledObject.SetPlayerVariant(false)`; hittable objects are `GoF2Target`; bullets are `GoF2Gun`. Game → Unity:
positions `(x, y, −z)·0.05`, directions `(x, y, −z)`; speeds u/ms × 50 = m/s (2 u/ms = 100 m/s).

1. **Plain C# tables** `GoF2NpcTables` (namespace `GoF2Remake.Flight`): fighter pools (§2.5), `NpcHp`, `NpcGun`,
   `EnemyRace`, `RaiderChance`, shot sounds, level thresholds. Unit-test against `npc_tables.py`.
2. **Standing** `GoF2Standing` (plain C#, state in `GoF2Session`: s0 = 30, s1 = 0, signature from the equipped sort-29
   item, per-station "attacked friends" set, player level/XP counters): `IsEnemy/IsFriend/ApplyDelict/ApplyKill`,
   `RacesHostile` (§4.1–4.3). Save with the session.
3. **Routes** `GoF2Route` (plain C#): waypoints in game units, index, loop, `Update(pos)` with the ±2000 box,
   `Clone`, default patrol factory (§5.8).
4. **Traffic plan** `GoF2TrafficPlan` (plain C#): §2.2–2.3 → a list of spawn specs (group, race, ship, kind,
   game position, route, flags, HP, EMP, gun) using `UnityEngine.Random`. Start with local fighters, jumpers,
   freighters, raiders and pirate-base escorts; add Wanted, outposts, Terran/Vossk specials, black market later.
5. **Brain** `GoF2FighterBrain` (plain C#): §5.2–5.6 on a small pose struct (position, rotation basis in game space,
   speed) plus an `IList<INpcTargetInfo>` enemy list (position, active, alive, hostileToPlayer, race, cloaked,
   isPlayer). Returns fire requests. Keep the per-frame quirks (×1.05/×0.95 per frame) behind `dt`-scaled helpers
   (e.g. `speed *= Mathf.Pow(1.05f, dt/33.3f)`), like weapons.md does for missile homing.
6. **`GoF2NpcShip`** (MonoBehaviour, one per fighter): instantiates the prefab, adds `GoF2Target` (radius
   1000 u → 50 m, 650 u hardcore; `maxHp = hp`), owns the brain and an NPC `GoF2Gun` (new constructor from `NpcGun`:
   4 bullets, 16 u/ms, 3000 ms, reload, damage, projectile/sound of the race item, mount at the centre), 3D engine
   loop 46, bank on the model child, death sequence (§5.10) with the ship explosion prefab and sound 20, crates later.
   `GoF2Target.Damage` needs a source (player / NPC) for §4.5.
7. **`GoF2Freighter`** (MonoBehaviour): +Z mover at 1 u/ms (50 m/s), 5× HP, `GoF2Target` with the boxes of
   `freighter_boxes.py` (or the prefab bounds), wreck prefab `cargo_*_explosion_anim` on death, engine loop 47.
8. **`GoF2Traffic`** (MonoBehaviour on the level, created by `GoF2SpaceLevel` after the asteroids): spawns the plan,
   builds enemy lists (§4.4), updates ships in array order, runs `updateOrbit` (§7: 10 s jumper relaunch at the
   station, 45 s police relaunch and raider waves), radio messages (a HUD line with portrait, 426–447), the hostile
   count for combat music 140/141/142 vs the system music, and exposes the ship list to `GoF2Navigation`/radar
   (hostile count also blocks fast-forward, autopilot_travel.md).
9. **Player side**: the player's guns already hit every `GoF2Target`; add a player damage model (`Player::damage`:
   shield → armor → hull from the ship/equipment, `Incoming_Fire_*` 25/23/24, weapons.md §5) as a `GoF2Target`-like
   receiver for NPC bullets (×0.2 from non-hostile shooters), friendly-fire bookkeeping (§4.5) and kill/standing
   updates; radar colours by hostile/friend/neutral; locking a Wanted uncovers it.
10. Later: wingmen (hire in the bar, formation/commands), Wanted boards, turrets, freelance missions, the black-market
    toll, the docking fine, race-10 cloak.

---

## Uncertainties

- **Pirate ambush point** at stream exits: `Level+0x18c = playerPos / k` with a lost float divisor; only "near the
  player's arrival" is certain.
- **Wingman spawn offsets**: `DAT_000cb61c..` gave (0, 2000, −1000, 0, 1000); the mapping of these values to slots and
  the forward factor were not fully decoded (the formation offsets in §2.7 are certain).
- **Freighter bounding boxes**: three battleship boxes and part of one are missing (values come from registers the
  script does not track). Offsets are relative to the ship origin in engine space; their exact use in
  `BoundingVolume` (centre vs corner) was inferred from `BoundingAAB`'s constructor storing `|size|/2`.
- **Visual bank axis/sign**: `MatrixSetRotation(bank·π/4096, ?, π)` on the mesh group; the middle argument was lost;
  banking about forward, negative when turning right, is assumed.
- **Freighter heading**: `PlayerFixedObject::moveForward` increments the stored integer z by dt and moves the
  geometry forward; freighters are never rotated in free flight, so both agree (+Z). A rotated fixed object would
  desync its stored position.
- **EMP-disabled fighters** still run targeting and `Player::shoot`; whether they can actually fire while disabled
  (nothing gates it in `PlayerFighter::update`) was not verified in `Gun`.
- The meaning of `Status+0xa0`, `+0xd4`, `+0xa4` in the player level XP formula was not identified (kills, missions,
  campaign mission and stations visited are).
- The raider respawn assumes the raiders are the last array entries (true only without escorts/outposts/Specters/
  wingmen after them); reproduce the intent (respawn raiders) rather than the index arithmetic.
- `Player+0x60` (combat intensity) is raised by shots/damage; its consumer (music?) was not traced; combat music in
  §8 comes from `Radar::draw`'s hostile count.
- Frame-rate dependence: boost (×1.05/×0.95), jump-out (×1.1), death spin (0.05 rad) and crate drift are per frame in
  the original (tuned for ~30 fps); the bank target also depends on the frame's turn angle.
- Freelance types (§2.9) were read once for their spawn counts only; objectives, docking routes and mission logic are
  not covered.
