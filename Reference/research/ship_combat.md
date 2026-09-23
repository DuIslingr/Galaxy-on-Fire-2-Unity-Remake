# Ship combat: damage model, NPC death and loot, player death, combat HUD, NPC weapons, sounds

How the original resolves ship-vs-ship combat and how it presents it, decoded from `libgof2hdaa.so` (Android HD). Game units and milliseconds unless noted (Unity: 1 unit = 0.05 m). Addresses use the Ghidra image base 0x10000. 2D values are **HD screen pixels** (1920×1080 canvas, `retinaDisplay = iPadLarge = 1`, see `shop.md` §1.2); image rects are the HD atlases actually loaded on Android HD (`gof2_interface_iphone4.png`, `gof2_interface2_ipad_large.png`, `gof2_interface3_ipad_large.png`), verified by cropping.

Not repeated here (read them first): player guns, bullet pool, hit test, beams, rockets, missile homing, the enemy lock box and lock time, crosshair → `weapons.md`; landmark/planet locks, radar ellipse, top plate layout, distance format → `autopilot_travel.md` §1; asteroid HP/death/loot → `weapons.md` §7 and `mining.md`; launch/arrival sequence → `station_interior.md` §3.4. NPC spawning, routes and AI decisions → `npc_traffic_ai.md` (parallel research).

Helper: `Reference/tools/combat/combat_tables.py` prints every image rect used below, the NPC hull / gun-damage / EMP table per player level, the loot type odds, and (`crops DIR`) cuts the images.

Corrections to earlier docs found on the way:
- `Player+0x60` is **not** a combat-intensity/music value (`weapons.md` §3.1/§3.4, Uncertainty 12). It is the **volatile-cargo instability meter**: it is forced to 0 every frame unless the ship carries volatile goods (`PlayerEgo+0x398`); then shots (+0.008), damage (+0.065), asteroid collisions (+0.2) and manoeuvring raise it, it decays 0.025/s, the loop 35 `Selfdestruct_Warning` plays with it as parameter, and at ≥ 1.0 the ship dies (explosion type 12). Combat music is driven by the radar's hostile counter (§7.5).
- The HUD rects in `weapons.md` §9 are from the low-res `gof2_interface.png`. The HD rects are in §7.9 below.

---

## 0. TL;DR for Unity

1. **Three HP pools, no damage reduction.** Every hittable object is a `Player` with shield (float), armor and hull (ints). `Player::damage` subtracts the hit from the shield, the overflow from the armor, the rest from the hull. **Armor (attr 20) is just a second HP pool** (no percentage/flat reduction anywhere). Hull ≤ 0 = dead. NPCs have **hull only** (no shield, no armor).
2. **Player pools**: hull = `ships.json armor` (+40 per hull ship-mod), shield = attr 18, armor = attr 20. Shield regen: every ≥ 101 ms tick +`maxShield·100/attr19` (attr 19 = ms for a full recharge), **no delay after a hit**. Repair bots: hull +1 per 600 ms (Ketar) / 420 ms (Ketar II), armor +2 per 1000/700 ms only once the hull is full. The player has **no EMP points → immune to EMP**.
3. **NPC pools** (`Level::createShip` 0xcf83c): `hull = (4·campaignMission + 14·min(level,20) + 20) × difficulty`, ×5 for freighters, ×25 for the battleship; hit-cube half-size 1000 (650 hardcore); EMP points `5·min(level,20) + 40` (×3 fixed objects), recovering over 15 s (45 s). `level` = the player's rank (0..20, from XP). Difficulty factor = `1 + (options[0x2c] − 0.5)` = **1 normal, 2 hardcore**.
4. **NPC guns** (`Level::assignGuns` 0xcb638): one gun, 4-bullet pool, lifetime 3000 ms, speed 16 u/ms, reload `600 − 2·campaignMission` ms, damage `clamp(int(0.9·(level−2)),0,20)` ×difficulty, +2 (min 3); projectile/impact by race. NPC bullets hit the player (cube ±1200) and ships of **other** races; same-race ships never hit each other. Friendly/neutral NPC bullets do **20 %** to the player. NPCs fire only with the target within ~0.44° of their nose and 35000 units per axis.
5. **NPC death**: hull ≤ 0 → state "dying": sound 20, smoke, tumble and drift for 1500–2999 ms → `Explosion` type 0 (`explosion_anim_lookat_alpha` + `_add`, 4500 ms, camera-facing, +3..9 `explosion_debris` streaks), sound 18/19, camera rumble within 30000 units; the hull stays visible 300 ms more; a **cargo crate** (race container mesh) spawns if the ship had cargo (2/3 of ships). Freighters/battleship play their `*_explosion_anim` wreck (10 s / 15 s) then a ×6 (×8) explosion.
6. **Loot needs a tractor beam**: crates are collected only by locking them (tractor attr 24 lock time) and letting the beam pull them in at 10 u/ms until < 400 units; message `"<n>t <item>"` (green), "Cargo hold is full." (322), "No tractor beam." (540) without one. Crates live 60 s. Kills give **no credits** (only wanted bounties), +1 kill stat / XP, −5 standing (×2 hardcore) with the victim's race.
7. **Player hit feedback**: camera shake 1000 ms (±6 units/frame), sound 25/23/24 (shield/armor/hull layer hit), shield icon flickers 500 ms, a **directional arc** (blue with shield, red without) flashes 300 ms on the radar ellipse toward the hit. No red screen flash, no vibration, no low-hull alarm in this build.
8. **Player death**: emergency system (item 185) first (hull 1, invulnerable 10 s, consumed); else the camera freezes, smoke, ship spins, explosion at 3 s, "Game Over" state at 8 s + sound 37, overlay after 3 s more, "Tap to load last savegame." after 4 s → reload the last save (station).
9. **HUD**: ship markers need a **scanner**; on screen near (≤ 24000 per axis) = hull bar under the ship (+ faction bracket when locked); far = faction dot (ring when locked) + distance for the lock; off screen = dot/ring on the radar ellipse. Colours: red enemy, green friend, yellow neutral. Lock plate: `"<name or race> NN%"` + race icon. Player status: shield bar and hull/armor bar top-left.

---

## 1. Classes and fields

| Class / function | Address | Role |
|---|---|---|
| `Player::Player(radius, hp, nPrim, nSec, nTur)` | 0xaed60 | the hittable/stat object of every ship, asteroid, turret, the player |
| `Player::damage(dmg, friendGun, itemIdx)` | 0xafa70 | shield → armor → hull, standing/friendly-fire logic, kill bookkeeping |
| `Player::damageEmp(emp, friendGun)` | 0xaf834 | EMP points, disable, standing |
| `Player::update(dt, soundOn)` | 0xb0a9c | "damaged" flag, EMP recovery, instability decay |
| `Player::regenerateShield(f)` / `regenerateArmor` / `regenerateHull` / `heal(f)` | 0xaf678 / 0xaf6cc / 0xaf6e0 / 0xb0c88 | regen steps |
| `Player::updateDamageRate` | 0xaefc0 | % values for the HUD |
| `PlayerEgo::update` (regen / hit feedback part) | 0xa8ed0 (≈0xaa850–0xaae5e) | shield regen, repair bot, emergency bubble, hit sounds, hit direction |
| `PlayerEgo::calcCollision(Array<KIPlayer*>*)` | 0xab550 | player vs landmarks / ships / asteroids |
| `PlayerEgo::tryToStartEmergencySystem` / `explode` / `explosionEnded` | 0xad6f0 / 0xada6c / 0xadc5c | player death |
| `MGame::gameOverCheck` | 0x1b0d04 | death → game over |
| `Level::createShip` | 0xcf83c | NPC hull, radius, EMP |
| `Level::assignGuns` | 0xcb638 | NPC guns |
| `Level::connectPlayers` | 0xcc330 | who each gun can hit |
| `Level::enemyDied / friendDied / alarmAllFriends / friendTurnedEnemy / attackWanted / killWanted / almostKillWanted` | 0xd3f98 / 0xd426c / 0xd54cc / 0xd65de / 0xd642c / 0xd65c8 / 0xd64b0 | kill counters, hostility, radio |
| `PlayerFighter::update` (death branch) | 0xf0d90 (≈0xf1c50–0xf2ae0) | dying / exploded / crate |
| `PlayerFixedObject::update` (death branch) | 0x17f480 | freighters, battleship, stations |
| `KIPlayer::createCrate / captureCrate / cargoAvailable` | 0xb2e2c / 0xb2a00 / 0xb2f00 | crate mesh, loot transfer |
| `Generator::getLootList(item, amount)` | 0xa1b78 | NPC cargo roll |
| `TractorBeam::TractorBeam / update / render` | 0x17c0f8 / 0x17c16c / 0x17c4c4 | salvage |
| `Explosion::Explosion(type) / setScaling / start / update / render / playSound / addFireStreaks` | 0xb4a90 / 0xb4ee0 / 0xb5478 / 0xb5768 / 0xb5a60 / 0xb5368 / 0xb51b8 | explosion fx, rumble, sound |
| `Radar::Radar / draw / drawCurrentLock` | 0x1545e0 / 0x1554fc / 0x158548 | ship markers, locks, plate, combat music |
| `Hud::init / draw / hudEvent / catchCargo / playerHit / drawEventQueue / updateQueue` | 0x18cf20 / 0x190d08 / 0x18f5a0 / 0x19027c / 0x19026e / 0x18f098 / 0x18f2a0 | status bars, hit arcs, messages |
| `TargetFollowCamera::hit / hitSmall / setRumblePercentage` | 0x187b4c / 0x187b6c / 0x187782 | camera shake |
| `Standing::applyKill / applyDelict / isEnemy / isFriend` | 0x142a3c / 0x142aa4 / 0x1428ee / 0x142964 | reputation |
| `Status::checkForLevelUp / incKills / incPirateKills / crateCaptured / incCollectedBounties / hardCoreMode` | 0xb9978 / 0xb9a18 / 0xb9a40 / 0xb9848 / 0xba0b2 / 0xb9148 | stats, rank, difficulty |

### `Player` fields (0x114 bytes)

| Offset | Meaning |
|---|---|
| +0x04 | world matrix |
| +0x40 | **radius** = half-size of the axis-aligned hit cube (player 1200, NPC 1000 / 650 hardcore, asteroid meshRadius·scale·0.7) |
| +0x44 | "killed by a non-player gun" (set when the killing hit had `friendGun`) → no kill credit |
| +0x54 / +0x55 | was hit this frame (AI reads it) / hit by a rocket |
| +0x5c / +0x5d | **enemy flag / friend flag** (marker colour, AI; recomputed every frame by `PlayerFighter::update` from the standing, §2.8) |
| +0x5e | untargetable (NPCs stop shooting at it) |
| +0x60 | volatile-cargo instability (see the correction above) |
| +0x64 / +0x65 / +0x66 | shield / armor / hull took the last hit (consumed by the player's hit sound) |
| +0x68 | EMP-disabled |
| +0x69 | this is the player ship |
| +0x6c | damage done by the player (friendly-fire thresholds) |
| +0x78 / +0x84 | hull / max hull (int) |
| +0x7c / +0x80 | EMP points / max |
| +0x88 / +0x94 | shield (float) / max shield (int) |
| +0x8c / +0x90 | armor / max armor (int) |
| +0x98 / +0xa8 / +0xac / +0xb0 | hull / shield / armor / EMP percent (int) |
| +0xb8 | gamma shield (supernova) |
| +0xc0 | active |
| +0xc1 | "damaged" (cleared on the next 3000 ms boundary of `+0xb4`) |
| +0xc2 | **vulnerable** (false → every damage call returns) |
| +0xc4 | hit vector (last `setHitVector`) |
| +0xd0 | owning `KIPlayer*` (null for the player) |
| +0xd4 / +0xd8 | bomb push force / EMP force |
| +0xdc | EMP done by the player |
| +0xe0 | turned hostile because of the player |
| +0xe4 / +0xe8 | EMP recovery duration / timer |
| +0xec / +0xed | always enemy / always friend (`setAlwaysEnemy` also sets +0x5c = 1, +0x5d = 0, +0xe0 = 1) |

---

## 2. Damage model

### 2.1 `Player::damage(dmg, friendGun, itemIdx)` 0xafa70

```
if !vulnerable(+0xc2) or !active(+0xc0) or hull <= 0: return
if !friendGun: friendly-fire / standing logic (2.7)          // only hits by the player's guns and collisions
s = int(shield) - dmg                                         // shield fraction is truncated on every hit
if s >= 0:          shield = s;                 shieldHit(+0x64) = 1
else: shield = 0;   a = s + armor
      if a >= 0:    armor = a;                  armorHit(+0x65) = 1
      else:         armor = 0; hull += a;       hullHit(+0x66)  = 1
wanted ship and hull < maxHull/3: Level::almostKillWanted (storyline wanted surrender)
if hull < 1:
    hull = 0
    if friendGun: killedByNpc(+0x44) = 1                      // no kill credit, no standing change
    else if KIPlayer is a ship and not in the black-market system:
        if not wanted: Standing::applyKill(race)              // 2.7
        campaign counter (item 0xb3 on text 1664 "Arms delivery" ships)
        wanted: Level::killWanted (radio 0x11)
damaged(+0xc1) = 1; instability(+0x60) += 0.065
if KIPlayer+0x10 (parent object): parent.damage(dmg, false) with its vulnerability forced on
```

- No per-hit cap, no minimum damage, no armor/shield type modifiers. EMP damage is a separate call (2.4).
- NPCs have `maxShield = maxArmor = 0` (never set), so every hit goes to the hull.
- `Player::damage(int)` 0xaffd0 = `damage(dmg, false, -1)` (collisions, bombs).

Damage values reaching `Player::damage` (from `Gun::calcCharacterCollision` 0x17e154, `weapons.md` §3.4):

| Case | Damage |
|---|---|
| Player gun → anything | `gun.damage` = attr 9 × weapon-mod damage factor; `friendGun = false` |
| NPC gun → NPC | `gun.damage`, `friendGun = true` (gun+0xf9) |
| NPC gun → player, gun owner **not** an enemy (friend/neutral stray fire) | `int(damage · 0.2)` |
| NPC gun (enemy or ownerless) → player docked to a docking point (turret seat) | `int(damage · 0.75)` |
| NPC gun (enemy) → player otherwise | `damage` |
| Area weapons (bombs, mines, scatter bursts) | `damage · clamp((mag − d)/mag, 0, 1)` (`weapons.md` §6) |
| Rocket / missile / bomb direct hit on an asteroid | 9999 |

### 2.2 Player pools and regeneration

- Created in `Level::createPlayer` 0xbca00: `Player(radius 1200 (0x4b0), hull = Ship::getMaxHP, …)`, `setMaxShieldHP(Ship+0x1c)`, `setMaxArmorHP(Ship+0x20)`, `+0x69 = 1`.
- `Ship::refreshValue` 0x1a33f4: `Ship+0x1c` = attr 18 of the shield (sort 9), `+0x24` = attr 19, `+0x20` = attr 20 of the armor (sort 10), `+0x4c` repair type = `(item != 75)` for a repair bot (sort 15), else −1. `Ship::getMaxHP` = `Ship+4` (**`ships.json armor`**, e.g. Phantom 200) + 40 per ship-mod entry of type 0.
- Values persist between levels: docking/jumping saves hull/shield/armor/gamma into `Status+0x64/+0x5c/+0x60/+0x68`; `MGame::OnInitialize` 0x1a6ebc restores them (−1 = full), then `PlayerEgo::resetLastHP`.

**Shield regen** (`PlayerEgo::update`, disassembly 0xaa854–0xaa896):

```
per-tick amount (PlayerEgo+0x218) = maxShield / (attr19 / 100)        // set in PlayerEgo::PlayerEgo 0xa5610
if attr19 > 0 and hull > 0:
    acc(+0x118, 64 bit) += dt
    if acc >= 101: acc = 0; shield = min(shield + amount, maxShield)
```

attr 19 is the time for a full recharge **in 100 ms ticks** (Targe 50 / 20000 → 0.25 per tick → 200 ticks). Because the accumulator is reset (not decremented), a tick lasts the first frame boundary ≥ 101 ms: ~117 ms at 60 fps, ~132 ms at 30 fps, so the real recharge is 17–32 % slower than attr 19 ms. **No regen delay after being hit** and no regen while dead.

| Shield | attr 18 | attr 19 (ms, full) | per tick |
|---|---|---|---|
| 50 Targe | 50 | 20000 | 0.25 |
| 51 Riot | 80 | 46000 | 0.174 |
| 52 H'Belam | 120 | 58000 | 0.207 |
| 53 Beamshield II | 150 | 45000 | 0.333 |
| 54 Fluxed Matter | 220 | 60000 | 0.367 |
| 225 Particle | 380 | 55000 | 0.691 |

Armors (attr 20): 55 E2 Exoclad 40, 56 E4 Ultra Lamina 80, 57 E6 D-X Plating 110, 58 D'iol 160, 59 T'yol 250.

**Repair bot** (same function, 0xaa89a–0xaa98c; constants `DAT_000ab4a8..b4` = 420, 600, 700, 1000): two accumulators both += dt.

| Item | Hull +1 every | Armor +2 every (only when hull is full) |
|---|---|---|
| 75 Ketar Repair Bot (type 0) | 600 ms | 1000 ms |
| 188 Ketar Repair Bot II (type 1) | 420 ms | 700 ms |

**Shield injector** (DLC, sort 43, item 227 Phoenix SIS, 0xaa3xx): when the shield reaches 0 and the cargo holds attr 59 (30) units of item 202 (Blue Plasma), they are removed, HUD event 0x2f "-30t Blue Plasma", sounds 2258 + 2257, and the shield is refilled by `max(dt·0.15, 1)` per frame until full.

### 2.3 Invulnerability windows

`Player::setVulnerable(false)` (`+0xc2`) is used only for: the launch / arrival look-at sequence (7000 ms, `LevelScript::LevelScript` 0x15e650 → `process`), the emergency-system bubble (2.5), mission objects (`Level::createStaticObject`, campaign scripts). There is **no invulnerability after a hit**, no respawn protection. During the dying state an NPC is still active but `Gun::calcCharacterCollision` skips targets with hull ≤ 0.

### 2.4 EMP (`Player::damageEmp` 0xaf834, `Player::update`)

```
if !vulnerable or !active: return
if empPoints <= 0 or hull <= 0: return                       // the player has 0 EMP points -> immune
if !friendGun (player's EMP): friend of the system race -> empDoneByPlayer += emp;
                               > maxEmp/3 -> turnedEnemy(+0xe0) = 1, Level::friendTurnedEnemy (radio, once)
empPoints -= emp
if empPoints < 1:
    player's EMP and system race -> Level::alarmAllFriends(race, false)
    ship, not wanted -> Standing::applyDisable(race) (2 points)
    medal 0x2a counter; empForce = recovery; disabled(+0x68) = 1; empPoints = 0; timer = 0
Player::update: while disabled: timer += dt; empPoints = int(timer/recovery · maxEmp);
                when > maxEmp: empPoints = maxEmp, disabled = 0
```

NPC EMP data (`Player::setEmpData(points, recoveryMs)` in `createShip`): points `5·min(level,20) + 40`, recovery **15000 ms**; fixed objects (freighters, battleship) ×3 points, 45000 ms. While disabled, `KIPlayer+0x20` mirrors `Player+0x68` (set every frame in `PlayerFighter::update`); the radar then treats the ship like a crate: it can be tractor-beam-locked (lock time attr 24, 500 ms ring delay) and its cargo stolen (§5.4). The AI side of "disabled" is in `npc_traffic_ai.md`.

### 2.5 Emergency system (item 185, sort 27, attr 41 = 10000)

Built in `PlayerEgo::PlayerEgo` (≈0xa6180): bubble mesh 14374 `v_shield`, duration `+0x310` = attr 41, bubble scale = ship radius/500 + 0.1. `MGame::gameOverCheck` calls `PlayerEgo::tryToStartEmergencySystem` 0xad6f0 when hull < 1:

```
if bubble exists and not already running and hull < 2:
    hull = 1; timer(+0x30c) = attr41; vulnerable = false; remove the item; play 1115 (DLC_SFX/Invincibility_01, name-matched)
update: timer -= dt; bubble follows the ship, UV scroll dt/1000, scale ramps in over the first 5 % and out over the last 5 %
        at 0: bubble deleted, vulnerable = true, stop 1115
```

### 2.6 Difficulty and hardcore

`Globals::options[0x2c]` (float) = **0.5 normal, 1.5 hardcore** (the options menu writes only these two; `Status::hardCoreMode` 0xb9148 = `== 1.5`). Wherever the code scales by difficulty it uses `x + x·(d − 0.5)` = ×1 / ×2.

| Effect | Normal | Hardcore |
|---|---|---|
| NPC hull (createShip) | ×1 | ×2 |
| NPC gun damage (assignGuns) | ×1 | ×2 (cap 22 before +2) |
| NPC hit-cube radius | 1000 | **650** |
| Standing penalties (`applyDelict`) | ×1 | ×2 (`<< hardcore`) |
| Friendly-fire thresholds (2.7) | 33 / 50 / 66 % | 10 / 25 / 40 % |
| Player hurt by own bombs | no | yes (`weapons.md` §6) |
| Spawn counts, pirate bases | — | see `npc_traffic_ai.md` |

### 2.7 Friendly fire, standing, hostility

Player's damage to a ship that is not hostile (`+0x5c == 0` or it already turned, `+0xe0`) whose race is 0..8 (not 9 Void / 10), inside a system (`Player::damage` 0xafb00–0xafd7a):

- **Wanted target** (`KIPlayer+0x3e`): damageDone += dmg; `Level::attackWanted` (radio 0x10 once, its wingmen become always-enemy).
- Else, not a wingman, and race == system race **or** system attack race: `damageDone(+0x6c) += dmg`, compared with max hull (strictly greater):
  - \> 33 % (10 % hc): `Level::friendTurnedEnemy` (radio message 0 once per level); if the player wears that race's **signature** (sort 29) → signature removed, `applyDelict(sigRace, 100)`, HUD event 0x1f "Signature invalid" (324).
  - \> 50 % (25 % hc): same signature check for races < 4; `turnedEnemy(+0xe0) = 1` (the ship fights back).
  - \> 66 % (40 % hc): `Level::alarmAllFriends(race, true)` → every ship of that race `setAlwaysEnemy`, radio 1 (0xc in the black-market system), `Station::setAttackedFriends`.
- Black-market system, pirate hit: all pirates alarmed, `Status+0x111 = 1`.
- Other races (neutral outsiders): no standing effect until the kill.

`PlayerFighter::update` also sets `+0x5c = 1` for flagged ships (`KIPlayer+0x3f`) once damageDone > maxHull/20.

**Standing** (`Standing` 0x14282a…): two axes in −100..100: `[0]` Terran(−)/Vossk(+), `[1]` Nivelian(−)/Midorian(+). `applyDelict(race, n)` moves the axis **away** from that race by `n << hardcore` (Terran/Nivelian: −n, Vossk/Midorian: +n). Enemy of a race when its axis is past ±70 against it (`isEnemy(Terran)` ⇔ `[0] ≤ −71`), friend when past ±70 toward it. A worn signature overrides: 100 for its race, 70 for the neutral axis, −100 for its rival.

| Event | Call | Points |
|---|---|---|
| Kill a ship of race r (0–3) | `applyKill(r)` → `applyDelict(r, 5)` | 5 (10 hc) |
| Kill a pirate (no signature) | `applyDelict(enemyRace(systemRace), 1)` | +1 toward the system race (enemy-race table `DAT_00252020` = 1, 0, 3, 2) |
| Steal cargo (tractor a live/disabled ship) | `applyStealCargo(r)` | 2 |
| Disable with EMP | `applyDisable(r)` | 2 |
| Mission completed | `applyMissionCompleted(r)` | −5 (i.e. toward r) |

Kills inside the black-market system change nothing. Kills by NPC guns never count.

### 2.8 Faction flags (marker colour)

Recomputed every frame in `PlayerFighter::update` (0xf0e20) for normal ships: `enemy(+0x5c) = race ∈ {8 pirate, 9 Void} or (not wingman and Standing::isEnemy(race))`; `friend(+0x5d) = wingman or (race ∉ {8,9} and Standing::isFriend(race))`. `setAlwaysEnemy/Friend` and mission scripts override. The radar colours follow these two bytes (§7). Details of hostility decisions → `npc_traffic_ai.md`.

### 2.9 Collision damage (`PlayerEgo::calcCollision` 0xab550)

Called each frame (when collision is on and the player is active) with the landmark list, the NPC list and the asteroid list; the object's virtual `collide(pos)` decides contact.

| Contact | Effect |
|---|---|
| Station, jumpgate (landmarks, `KIPlayer+0x38 == 0`) | pushed out (`projectCollisionOnSurface`), camera `hit()` shake. **No damage** |
| NPC ship (`+0x38 == 0`) | same (fighters without bounding volumes never report contact; big ships use their BV list). **No damage** either side |
| **Asteroid** (`PlayerAsteroid` sets `+0x38 = 1`) | asteroid `setBombForce` + `damage(9999)` (destroyed, normal asteroid death/loot), **player `damage(20)`** (shield → armor → hull), instability +0.2 with volatile cargo, camera `hit()` |
| Wormhole | pulled in, sound 34 |

No speed-dependent damage, no ship-ship damage, no station damage.

---

## 3. NPC stats

### 3.1 Hull (`Level::createShip(race, kind, shipIdx, waypoint, …)` 0xcf83c)

```
lv   = min(Status::getLevel(), 20)                 // player rank 0..20 (3.3)
base = (gameWon ? 180 : 4*campaignMission) + 14*lv + 20
ship 51 Rhino x1.7, 49 Scimitar x17, 44 Specter x2.25          (special/boss ships)
campaign missions 0x31..0x38 (mask 0x8f): base = 270
kind 1 (PlayerFixedObject: freighter, battleship): base *= (shipIdx == 14 ? 25 : 5)
hull = int(base + base*(difficulty - 0.5))          // x1 / x2
campaign 0x9a in the alien orbit, race 9: hull << 1
Player(radius = hardcore ? 650 : 1000, hull, 1 primary, 1 secondary, 0 turrets)
```

`ships.json armor` is **not** used for NPCs. Mission scripts overwrite hull for special targets (`Level::createMission` / `createCampaignMission`: 9999999 for invulnerable escorts, ×2/×3/`/20` variants); wingmen get 600 (`Level::createWingmen`).

`combat_tables.py` output (free play, campaign 0): hull 20 at rank 0, 160 at rank 10, 300 at rank 20 (×2 hardcore); the remake's free-play campaign value 20 adds +80.

### 3.2 No shields, no armor, no regen

NPC `Player`s never get `setMaxShieldHP/ArmorHP`, and nothing regenerates NPC hull (except the DLC `RepairBeam` on friendly targets). The lock plate and the bar under the ship show the hull percentage only.

### 3.3 Player rank (drives NPC hull and damage)

`Status::checkForLevelUp` 0xb9978: `XP = Status+0xa0/50 + kills(+0x1c0) + (+0xd4)/3 + (+0xa4) + 2·missions(+0x1c4) + (+0x1e8) + (+0x1d0)`; level = highest i with `XP ≥ DAT_00252b0c[i]` = 0, 7, 21, 42, 70, 105, 147, 196, 252, 315, 385, 462, 546, 637, 735, 840, 952, 1071, 1197, 1330, 1650. Each player kill is +1 XP.

---

## 4. NPC weapons

### 4.1 Guns (`Level::assignGuns` 0xcb638)

For every KIPlayer with `+0x21` (armed):

```
f = 0.9*(level - 2);  base = f >= 20 ? 20 : f < 0 ? 0 : int(f)
d = int(base + base*(difficulty - 0.5)); if d > 21: d = 22
dmg = (d == 0) ? 3 : d + 2;   campaign mission 4: dmg = 1
mission type 6 enemies / type 0xc friends: dmg = level + (d+2), speed 30 (else 16)
Void (race 9, not wingman/friend): dmg *= 0.8 (x2 in campaign 0x10); campaign 0x31..0x38: dmg = 5
gun = Gun(item, dmg, pool 4, ammo -1, lifetime 3000, reload 600 - 2*campaignMission (game won: 510), speed)
gun.friendGun = true
```

Race → item (impact mesh, sort) and projectile mesh:

| Race | Item (impacts) | Sort | Projectile |
|---|---|---|---|
| 0 Terran | 0 Nirai Impulse EX 1 | 0 laser | `projectile_000_anim_add` (6754) |
| 1 Vossk | 3 V'skorr | 0 | `projectile_003_anim_add` (6760) |
| 2 Nivelian | 7 Berger Retribution | 0 | `projectile_007_anim_add` (6764) |
| 3 Midorian | 25 128MJ Railgun | 0 | `projectile_026_anim_add` (6802) |
| 9 Void | 5 Berger Focus I | 0 | `projectile_005_anim_add` (6762) |
| 10 | 229 Dark Matter Laser, dmg ×0.7 | 0 | `sn_projectile_229_anim_alpha` (19091) |
| others (8 pirates, 4–7) | 19 Gram Blaster | **1** (billboard) | `projectile_019_anim_add` (6795) |

So every NPC of a race fires the same gun: 16 u/ms × 3000 ms = **48000 units** reach, 4 bullets in flight max, one shot per `reload`.

Variants:

| Case | Gun |
|---|---|
| Turret (`KIPlayer+0x3a`) on a station/object | item 15 (Vossk) / 20 (others), sort 1, projectile 015/020 |
| Turret on the battleship (host ship 45/51) | item 22, sort 2 (auto-cannon), `projectile_022`, damage ×0.5 |
| Sentry guns 18880/18881/18882 (`sn_sentry_gun_00x`) | items 211/212/213 stats (attr 9/11/12/13), mesh offset (0,0,250/300) |
| Wanted pilot (`+0x3e`) | `Wanted::getWeapon()` item, its sort and projectile table, damage ×4 |
| Wanted flying ship 45–48 | extra rocket gun: item 31 G'liissk, damage 4·dmg, lifetime 10000, reload 3000, speed 8 |
| Rocket/missile guns (sort 5 or 0x28) | `RocketGun`, speed 8, lifetime 10000, reload 3000, damage ×4 |
| Wingmen | extra EMP gun: pool 4, lifetime 3000, reload 400, speed 16, EMP 8 (item 18 attr 10), `projectile_018` |
| Campaign-specific | 0x46: item 183 Disruptor; 0x91: cluster; 0x9d/0x9e: item 7 ×3; last-failed-campaign-mission ×3 retry: enemy damage ×0.7 |

Shot sound per race: `DAT_002526c0[race]` = 52, 55, 54, 53, 61, 61, 61, 61, 61, 62, 2276 (`weapons.md` §3.8); preloaded ids 0x3d/0x3e.

### 4.2 Who can hit whom (`Level::connectPlayers` 0xcc330)

- **Player guns**: every KIPlayer (friends and neutrals included), asteroids, gas clouds.
- **NPC guns**: the player + every other KIPlayer whose race differs from the shooter's (wingmen: all except themselves). **Same-race ships are never in each other's list** → no intra-race friendly fire. Asteroids are not in NPC lists. Mission types 2, 9 (and every second ship in type 0xc) and some campaign missions build special lists (only non-static ships; always-friend ships get the player slot only); not needed for free play.
- Race-10 ships in empty missions get the player as their only enemy.

### 4.3 When NPCs fire (`PlayerFighter::update` ≈0xf2b90–0xf3674)

The AI sets "wants to shoot" (`+0x12a`, see `npc_traffic_ai.md`); the shot happens when all hold:

- a target (`+0x144`), not `doesNeverAttack`, target not untargetable (`Player+0x5e`), armed (`+0x21`), target active and alive;
- the target direction, normalized and rotated into ship space, has |x| and |y| < `+0x1a4` = **0.00763** (≈0.44° from the nose; `setShootError` exists but is never called);
- the target within **35000 units on each axis**;
- player docked to a docking point: only if the NPC isn't above it (y test).

Then `Player::shoot(slot = PlayerFighter+0x13c, dt)` fires every ready gun of that slot (wanted pilots toggle slot 0/1 every 20000 ms when they have a secondary). NPC bullets use the same `Gun` code as the player's: spawn at ship + R·(0,0,offset), straight along the nose (no lead, no spread for lasers), cube hit test, impact mesh of the item.

### 4.4 NPC missiles

`RocketGun::seekEnemy` 0x18bd70 for NPC guns: target = the shooter's current AI enemy (`Player::getEnemy(KIPlayer+0x34)`), steering `vel = normalize(cur + (desired − cur)/(0.3·20))·speed` per frame, starting 1000 ms after launch (NPC rockets have no per-bullet trails, `weapons.md` §6). Only sort 5 (missile) and 0x28 (cluster) guns home; the standard NPC rocket gun (sort 4) flies straight. **No missile warning** (no sound, no HUD) exists.

---

## 5. NPC death

### 5.1 Fighters (`PlayerFighter::update` 0xf0d90)

```
every frame: hull < 33 % of max and options[0x28] > 0 -> damage smoke/fire emitters (+0x7c/+0x80) on (off when docked / healed)
hull < 1 and state not 3/4 (dying/dead):
    freelance type 0xd bookkeeping; wanted: reward credits + Layout::showMissionRewardMessage
        ("Bounty collected" 3206, "+ N" credits, 7000 ms, sound 36) + Status::incCollectedBounties(board)
    not enemy -> Level::friendDied (+ wingmanDied)
    enemy     -> Void: cargo = [131 Alien Remains x 1..3]; pirate killed by the player: Status::incPirateKills;
                 Level::enemyDied(type, killedByNpc)          // kills stat, medals (5.5)
    state = 3 (dying), lock flag off
    timer(+0x1f0) = 1500 + rnd(1500)
    particle burst: Level particle set (Level+0x3c) at the ship
    play 20 Destruction_Ship_Small (3D at the ship if 3D sound is on)
    tumble axis (+0x184) = normalize(rnd(200)-100 per axis) * lost scalar; smoke emitter (+0x19c) on; trails off
    hasLoot(+0x48) = cargoAvailable(); exhaust off
state 3: rotate by +0x18c about the tumble axis, drift along the death direction (+0x190) * dt; timer -= dt
    timer < 0: Explosion::start(pos); smoke off; damage emitters off
               bombForce = 50 + rnd(50)*0.01; crate drift dir (+0x178) = normalize(rnd(200)-100 per axis)
               state = 4, timer = 0; free its space point
               hasLoot: createCrate(race 9 ? 4 : 0)   (mission crates: flagged instead)
state 4: hull mesh still drawn while timer < 300 ms, then only the explosion and the crate
    crate: moves along +0x178 * bombForce (bombForce *= 0.98 per frame until < 0.05), spins dt/2 * 2pi/65536 rad
    removed (setActive false) once the explosion finished and (no crate or > 60000 ms)
```

Signature drop: a branch would give race+189 (Signature) as loot for races < 3 with `options[0x35]`, but its probability test `rnd(100) <= −1` is never true (0xf1e62) → **dead code**.

### 5.2 Freighters, battleship, stations (`PlayerFixedObject::update` 0x17f480)

```
hull < 1: friendDied / enemyDied; pirate station (14243): Level::pirateStationAction
    state 3; crate immediately if cargo
    wreck mesh (setWreckedMeshId in createShip): cargo_001_midorian (18300), cargo_002_nivelian (18301),
        cargo_003_terran (18302), cargo_004_vossk (18303), battleship_terran_explosion_anim (18304); plays once
    play 20; smoke particle system (Level+0x50, +0x54 for the battleship / pirate station)
    Explosion type 0 + fire streaks at the object
    battleship (14): all its turrets damage(9999999); player kill -> Status+0x118 "Battleships destroyed", medal 0x27
state 3: wreck keeps moving forward (moving freighters), animation runs (10000 ms freighters, 15000 ms battleship)
    animation over: state 4, smoke off, Explosion reset + setScaling(6) (8 for the battleship mesh 14311 and the
        pirate station) + start; camera rumble (1 - min(d, 30000)/30000)
state 4: crate 60 s rule as fighters
```

`assemblies.json` `explosionModel` of these five objects = the same wreck meshes.

### 5.3 `Explosion` (0xb4a90)

| Type | Meshes (alpha / add or single) | Use | Sound (`playSound` 0xb5368, when no weapon index) |
|---|---|---|---|
| 0, 6 | 16821 `explosion_anim_lookat_alpha` + child 16820 `explosion_anim_lookat_add` | ships, player, stations, AMR bombs | **18 Destruction_Ship_Big or 19 Destruction_Ship_Mid** (random) |
| 1 | 16915 + 16913 (default branch) | — | none |
| 2 | 16915 `asteroid_explosion_anim_alpha` + 16913 `asteroid_01_explosion_anim` | asteroid | 21 |
| 3 | 16915 + 16925 `asteroid_void_explosion_anim` | void asteroid | 21 |
| 4 | 16909 / 16908 ice asteroid | | 21 |
| 5 | 18841 / 18840 magma asteroid | | 21 |
| 7 | 16805 `explosion_emp_anim_lookat_add` | EMP bombs | by weapon |
| 8, 9, 10 | 16806–16808 `v_scattergun_000_explosion_lookat_anim_add` | scatter bursts | by weapon |
| 11 | 18996 glow + 18995 sphere | shock blast | by weapon |
| 12 | 19070 `sn_plasma_explosion_anim_lookat_add` | volatile cargo death | none |
| 13 | 16809 `sn_fireworks_lookat_anim_add` | fireworks | by weapon |

- Duration = the longer animation of its meshes (4500 ms for type 0), divided by the speed from `setScaling(s)`: speed `1` for s ≥ 1, `(1 − s)·3 + 1` below (types 8–10 random 0.7–1.29; type 11 halved). The fx transform far distance is set to 20000.
- Rendered camera-facing (look-at the camera, except types 2, 11, 12 which keep their matrix), scaled by `+0x24` (default 1).
- `addFireStreaks` 0xb51b8: 3 + rnd(7) extra meshes 14292 `explosion_debris_anim_add` (4500 ms), random rotation (0..359° on two axes), scale 0.5–0.99, same position.
- **Camera rumble** (`Explosion::update` 0xb5768, types 0/1 with a camera): during the first 2000 ms of the animation `setRumblePercentage(p = (1 − min(d,30000)/30000)·(1 − t/2000), amplitude 50)` with d = explosion–camera distance; reset to 0 at the end. `TargetFollowCamera::update` then jitters the look-at point by `p · (rnd(2·50) − 50)` units per axis each frame.

### 5.4 Loot and crates

**Cargo roll** (`Generator::getLootList(-1,-1)` 0xa1b78, in the `PlayerFighter` ctor; Void ships get none, see 5.1):

```
if rnd(3) == 0: no cargo                                  // 1/3 of ships carry nothing
n = rnd(3), 0 -> 1 entry(ies) of (item, amount)
each entry: up to 99 tries: item = rnd(itemCount); accept if no blueprint ingredients,
            rnd(100) < typePct[item.type] (DAT_00251e5c: primary 10, secondary 40, turret 2, equipment 10,
            commodity 100, 5: 10), rnd(100) < item.occurrence, price > 0, not 217/218/164/175:
              commodity -> amount 1..9;  other types need tech < 8 -> amount 1..3
            fallback: ore 154..163, amount 1..9
player has a jump drive and no Energy Cells: 10 % -> first entry item = 122 Energy Cells
```

**Crate mesh** (`KIPlayer::createCrate(kind)` 0xb2e2c), placed at the ship position:

| kind / race | Mesh |
|---|---|
| kind 1 | 16926 `asteroid_01_junk` |
| kind 2 | 16927 `asteroid_void_junk` |
| kind 3 | 16920 `space_junk_004` |
| race 0 Terran | 16992 `container_003_terran` |
| race 1 Vossk | 16991 `container_004_vossk` |
| race 3 Midorian | 16990 `container_001_midorian` |
| race 9 Void (kind 4) | 16916 `container_005_void` |
| others (Nivelian, pirates…) | 16993 `container_002_nivelian` |

Crates are not hittable (hull 0), drift (5.1) and vanish after 60 s.

**Collection = tractor beam only** (`TractorBeam::update` 0x17c16c; created in `PlayerEgo::PlayerEgo` when a sort-13 item is mounted):

| Item | attr 23 (mode) | attr 24 lock ms | Beam mesh |
|---|---|---|---|
| 68 AB-1 "Retractor" | 0 manual | 4000 | 14232 `projectile_068_anim_add` |
| 69 AB-2 "Glue Gun" | 0 | 1800 | 14233 |
| 70 AB-3 "Kingfisher" | 1 auto: any on-screen crate becomes the salvage target without the box | 0 | 14234 |
| 194 AB-4 "Octopus" (DLC) | 2 auto: any dead crate, even off screen | 0 | 14235 `v_projectile_194_anim_add` |

- **Lock** (`Radar::draw` ship loop): a dead ship with loot (or an EMP-disabled ship, `KIPlayer+0x20`) inside the ±120 px crosshair box becomes the candidate; timer ≥ attr 24 → salvage lock `Radar+0x1c`. The lock ring appears after **500 ms** and fills `23·(t − 500)/(lockTime − 500)`. Without a tractor beam the completed lock gives HUD event 9 **"No tractor beam."** (540) and is dropped.
- **Pull**: while locked the beam mesh (scaled to the distance) points from the player to the crate; the crate moves toward the player at **10 units/ms**; sound 0 `Tractor_Beam` (loop, once). A dying/dead ship's own model follows.
- **Capture** at distance **< 400 units**: `KIPlayer::captureCrate`, stop 0, play **4** `Tractor_Beam_Close_Door`. Turret mode or the crate vanishing cancels.
- `captureCrate` 0xb2a00 transfers **the first non-empty entry** only: amount = full (dead ship) or `rnd(amount)` (live/disabled ship), capped to free cargo (at least 1). Live targets: `applyStealCargo` (2) unless `+0x38`, friends: `Level::stealFriendCargo`. Secondary ammo of a mounted type is added to the mounted stack, else cargo. Stats: `Status::crateCaptured` (+amount, "Cargo salvaged"), Void cargo `Status+0xcc`, items 132–153 mark `Status+0xac` flags. HUD: `Hud::catchCargo`. Remaining entries → a new crate appears when the beam re-locks (`TractorBeam` calls `createCrate(0)` if cargo is left).

**HUD messages** (`Hud::catchCargo` 0x19027c): `"<n>t <text 1274+item>"` with the item icon, green; repeated pickups of the same item within the message time are aggregated; hold full → "Cargo hold is full." (322, red). Scanner with attr 31 = 1 (Ecoscan/Proscan/Ultrascan, `Radar+0x1a5`): locking a ship within 24000 units shows its first cargo entry the same way (or HUD event 0x16 "Nothing to salvage." (542) if it carries nothing).

### 5.5 Credits, stats, reputation

- **No credits for kills.** Only wanted targets pay (`Wanted::getReward`, message box + sound 36).
- `Level::enemyDied(type, killedByNpc)` 0xd3f98: `Level+0x118` enemy count −1, `+0x12c` kills this level +1; player kill: **`Status::incKills`** ("Kills" 176 on the status screen) + achievement counter, medal 0x28 progress (kills without a scanner), medal 0x2b (kills while the emergency bubble is active); NPC kill: `Level+0x20` +1.
- Pirate kills: `Status::incPirateKills` (+0x1d8). Battleships: `Status+0x118`. Asteroids: `Status+0xd8` ("Asteroids destroyed").
- Standing: §2.7. Rank/XP: §3.3.

---

## 6. The player being hit, and dying

### 6.1 Hit feedback (`PlayerEgo::update` ≈0xaacf0–0xaae5e)

Detection: `combinedHP (shield+armor+hull) < lastCombinedHP(+0x130)` while the state flags `PlayerEgo+0x1f4` and `+0x24` are clear (meaning not traced; probably special sequences):

```
Hud::playerHit()                                 // shield icon -> 0x4ad for 500 ms (only while shield >= 2)
lastCombinedHP = combinedHP
TargetFollowCamera::hit()                        // 1000 ms: camera position += rnd(12)-6 units per axis per frame
                                                 //   (x0.001 in first-person); turret view: same jitter on the seat
sound, one per frame by the layer hit: shield(+0x64) -> 25 Incoming_Fire_Shield
                                       armor(+0x65)  -> 23 Incoming_Fire_Armor
                                       hull(+0x66)   -> 24 Incoming_Fire_Hull     (flag cleared)
hit direction: hitVector (Player+0xc4) normalized, projected from the camera (+0x148):
    screen x < 0 -> 1 (left), x >= w -> 2 (right)
    projected point in front (z >= 0) -> |0x20 (bottom arc), with extra left/right bits for x beyond +-15000/50000
    else -> |0x10 (top arc)
    PlayerEgo+0x20 = bits (read by Hud::draw the same frame)
```

`Hud::draw` 0x190d08 turns the bits into 300 ms timers: bit 1 → left arc, 2 → right arc, 0x18 → top arc, 0x24 → bottom arc. Arc image: shield > 0 → blue (0x52c side, 0x52b top/bottom), shield empty → red (0x526 side, 0x525 top/bottom). They sit on the radar ellipse: sides at `(w/2 ∓ 657, h/2)` (the left one mirrored), top/bottom at `(w/2, h/2 ∓ 491)` (the bottom one flipped vertically); drawn white-tinted (full colour).

Not present in this build: red screen flash / vignette, vibration (`PaintCanvas::Vibrate` has no callers), shield bubble on hit (`PlayerEgo+0x30a` is set but never read), **low-hull alarm** (event 27 `Low_Life` is only stopped in `explode`, never started), "hull damaged" text.

Player shots themselves: `TargetFollowCamera::hitSmall` (50 ms, ±2 units) per shot (`weapons.md` §3.2).

### 6.2 Player death

```
hull < 1 (MGame::gameOverCheck 0x1b0d04, each frame while not game over):
    tryToStartEmergencySystem -> survives (2.5)
    in a wormhole -> game over directly
    else: turret mode off, camera reset, free-look off, first-person off
          PlayerEgo::explode 0xada6c (once): smoke emitter (+0x2fc) on; TargetFollowCamera::setActive(false)
              (the camera stops following: frozen where it was); Explosion type 0 created; Player inactive;
              stop engine / music-less loops (27, 35, 0x8d4/0x8d5/0x8cc, 0x447-0x449); exhaust off
          PlayerEgo::update while dead: guns stop, tractor/repair sounds stop, the ship model rotates (rate lost)
              at 3000 ms: Explosion::start at the ship, smoke off, particle burst (sound 18/19)
          explosionEnded = timer > 8000 ms -> MGame+0x60 game over, text 319 "Game Over", MGame+0x109
    game over: campaign fail counters; remember the last save record; timers reset; play 37 game_over
MGame (game over state): after 3000 ms a full-screen overlay (MGame+0x10) fades in over 4000 ms;
    then blinking text 196 "Tap to load last savegame.\nIf the mission was too hard, you can improve your ship's
    weapons and equipment in the hangar!" (or 199 "Tap to continue" with no save)
    tap after that -> GameRecord::load(last save) -> station module 5 (no save: main menu module 1)
```

No respawn in space and no death penalty beyond losing progress since the last save (`ModStation::autosave` 0xe9eb4 writes save slot 0 in the station).

---

## 7. HUD for ships

All from `Radar::draw` 0x1554fc (ship loop 0x155ee8–0x1567c0), `Radar::drawCurrentLock` 0x158548 and `Hud::draw` 0x190d08. HD positions; `sx, sy` = the object's screen position (`Radar::update`, clamped to the radar ellipse when off screen, `autopilot_travel.md` §1.1).

### 7.1 Gate: a scanner is required

The whole ship loop runs only if a scanner (sort 17) is mounted (`Radar+0x1a7`, verified 0x155ee8 `ldrb r0,[r8,#0x1a7]; beq skip`). **Without a scanner: no ship markers, no ship or crate locks, no hostile counter** (so no combat music and no fast-forward block). The new game has one (Telta Ecoscan).

### 7.2 Markers per ship (active, not "dying without loot", not `KIPlayer+0x70`)

| Situation | Drawn (centred at sx, sy unless noted) |
|---|---|
| **Off screen** (clamped to the ellipse) | faction **dot** 0x4cc/0x4cd/0x4cb (36×36), or faction **ring** 0x4c8/0x4ca/0x4c9 (58×58) if it is the locked target; crate: 0x451 (0x44d for Void, 0x44f for `KIPlayer+0x39` objects) |
| **On screen, far** (any axis > 24000 units, or object type 16917 `space_junk_001`) | faction dot, or faction ring if locked; crate: small white dot 0x4f1; **locked target: distance** (`Radar::calcDistance` from the camera) at `(sx − 61, sy + 61)` |
| **On screen, near** (all axes ≤ 24000) | **hull bar**: frame at `(sx − 59, sy + 63)` (114×10), fill at `(sx − 58, …)` width `hull% · 110` (110×6); **EMP bar** 8 px lower while EMP < max (0x4d8 frame, 0x4d7 white fill, width `EMP% · 110`); if locked: faction **bracket** 0x4db/0x4d2/0x4dc (81×81); crate: white bracket 0x4f2 |

Faction = `Player+0x5c` enemy → red; else `+0x5d` friend → green; else neutral → yellow (bars: red 0x4da/0x4d9, green 0x4d3/0x4d4, yellow 0x4d5/0x4d6). Near ships show **only the bar** (no dot) until locked.

Flags set here for the weapons: `+0x72` on screen, `+0x6f` within 60000 units and inside the ±120 px crosshair box (beam auto-aim), `+0x71` inside the box.

### 7.3 Ship lock (`weapons.md` §8 covers the box and lock time)

- Candidate: on screen, inside the ±`w/16` = ±120 px box around `PlayerEgo::crosshairPos`; not in autopilot, not docked to a docking point, `KIPlayer+0x39 == 0`, no landmark/asteroid/gas/salvage lock, `Radar+0x1ac` (always 1) and not `+0x1a4`.
- Timer += dt (reset when the candidate changes or no candidate); lock when > scanner attr 29 (Quickscan 4000, Ecoscan 3000, Proscan/Ultrascan 1800; 8000 without, but then there is no loop at all). Ring 0x456 (24 frames 80×80) at the crosshair from t = 0 (no delay for ships), frame `23·t/lockTime`.
- On lock: sound **26** `Target_Lock` (only when the lock target changes), `Radar+4 = target`; scanner attr 31 cargo readout (5.4).
- **The ship lock is sticky**: it is kept after the ship leaves the box and is dropped only when the target starts dying/dies or another lock completes (unlike landmark locks). Missiles/thermo home on it (`weapons.md` §6).

### 7.4 Lock plate (`Radar::drawCurrentLock`)

Plate 0x4c4 (408×57) at `(w/2 − 204, 6)`; text centred at y = 6 + 14 (layout+0xc4); race icon (36×36, frame = race; none for race 10) left of the text at `textX − 6 − 36`, y = 6 + 10.

| Target | Text |
|---|---|
| ship with no name | text `406 + race` ("Terran", "Vossk", "Nivelian", "Midorian", "Pirate" 414, "Void" 415) + `" NN%"` (hull %) |
| named ship (`KIPlayer+0x18`) | its name; wanted pilots and ships named 1611 "Hijacker" / 1663 "Informer" are drawn in a special colour (value lost), wanted ones with `" NN%"` |
| crate / dead ship | same (race name) |

Race icons: 0 `0x4a1` [226, 90], 1 `0x49c` [273, 1889], 2 `0x49f` [272, 1650], 3 `0x49e` [2002, 222], 8 `0x4a0` [250, 1010] skull, 9 `0x49d` [83, 1900] (all `gof2_interface_iphone4.png`, 36×36); frames 4–7 unset.

### 7.5 Hostile counter and combat music (end of `Radar::draw`, 0x157c6c)

`Radar+0x1b8` counts ships in the loop that are enemies (`+0x5c`), not crates, `KIPlayer+0x38 == 0` (plus active race-10 ships). `Radar+0x54 = count ≥ 1` (blocks fast-forward). **There is no on-screen enemy counter** (`RADAR_WIDTH/HEIGHT` are unused J2ME leftovers; there is no minimap). The counter picks the music each frame (only switching when the current track isn't already a matching combat track):

| Hostiles | Track |
|---|---|
| 0 | per system race `DAT_00252010` = 134 Space_Nocombat_Terraner, 139 Vossk, 138 Nivelianer, 137 Midorianer (`MUSIC/Space_Terraner.ogg` …); special stations 146/147, supernova 148, deep science 152, Void 145 |
| 1–2 | 140 Space_Combat_Low (`MUSIC/Space_Battle_Low.ogg`) |
| 3–4 | 141 Space_Combat_Mid (`Space_Battle_Medium.ogg`) |
| ≥ 5 | 142 Space_Combat_Full (`Space_Battle_Full.ogg`) |
| race-10 ships present | 149 / 150 SN_Battle_StealthFighter Low/High (≥5) |
| a hostile wanted pilot | 151 SN_WantedBoardCriminals |
| alien orbit / station attacked by aliens | 136 Space_Combat_Void (`Space_Battle_Void.ogg`) |

### 7.6 Player status (`Hud::draw` ≈0x1911xx; layout values of the HD branch of `Layout::Layout` 0xe2a00)

Top-left, two (three in supernova systems) rows. x0 = 38, icon 41×42, bar x = x0 + 41 = 79, bars 248×14, row plate 0x4a9 (247×39) at (79, iconY + 1).

| Row | Icon at (38, y) | Bar (frame + fill) at (79, y) | Fill width |
|---|---|---|---|
| Shield (only if a shield is mounted) | 0x4ac, or 0x4ad for 500 ms after a hit (while shield ≥ 2), y = 10 | 0x4ae + 0x4af (cyan), y = 24 | `shield% · 248` |
| Hull + armor | 0x4aa (armor > 0) / 0x4ab (armor gone, red), y = 58 (10 without shield) | 0x4a7 + 0x524 (red, hull) + 0x4a8 (yellow, armor, drawn over the hull fill if an armor is mounted), y = 72 (24) | hull%·248, armor%·248 |
| Gamma shield (supernova systems with gamma damage) | 0x1f59, y = 106 | 0x1f5a + 0x1f5b, y = 120 | `gamma/100 · 248` |

### 7.7 HUD messages (`Hud::hudEvent`, `drawEventQueue` 0x18f098, `updateQueue` 0x18f2a0)

One message at a time, 4000 ms each (queue of 20); background 0x4c3 (392×44) centred at the top (y = −8, or 42 when the lock plate is shown), text centred at y = 4 (56 with the plate). Colour by type: 2 = (0, 237, 0) green (cargo), 1 = (255, 42, 0) red (events 0x1b, 0x1e, 0x1f, 0x2f, cargo full), 3 = (255, 128, 0), else white. Combat-related texts:

| Event | Text |
|---|---|
| 9 | 540 "No tractor beam." |
| 0x16 | 542 "Nothing to salvage." |
| 0x1b | 322 "Cargo hold is full." |
| 0x1f | 324 "Signature invalid" |
| 0x2d | 3202 "Warning: Volatile cargo" |
| 0x2c | 3201 "Warning: Gamma shield low" |
| 0x2f | "-30t Blue Plasma" (shield injector) |
| cargo | "`<n>`t `<item>`" (1274 + item), 537 "#Qx #N collected." for mission crates |

Wanted kill: the separate reward box (`Layout::drawMissionRewardMessage`): 3206 "Bounty collected" + "+ `<credits>`", fade in 2 s, hold to 5 s, fade out to 7 s, sound 36.

### 7.8 Crosshair hit

Player bullet hit → crosshair 0x4ce (orange) for 200 ms (`weapons.md` §9).

### 7.9 Image table (HD, verified by cropping with `combat_tables.py crops`)

| Id | Atlas | Rect (x, y, w, h) | Use |
|---|---|---|---|
| 0x4cc / 0x4cd / 0x4cb | interface2_ipad_large | 66,1284 / 1761,61 / 292,58, 36×36 | ship dot red / green / yellow |
| 0x4c8 / 0x4ca / 0x4c9 | interface2_ipad_large | 232,17 / 292,1382 / 38,1748, 58×58 | locked ring red / green / yellow (4 arcs around a dot) |
| 0x4db / 0x4d2 / 0x4dc | interface2_ipad_large | 292,1294 / 1,1840 / 149,17, 81×81 | locked bracket red / green / yellow (near) |
| 0x4f2 | interface2_ipad_large | 292,1653, 81×81 | white bracket (crate near) |
| 0x4f1 | interface2_ipad_large | 61,455, 39×39 | white diamond dot (crate far) |
| 0x451 / 0x44d / 0x44f | interface2_ipad_large | 366,1214 / 295,1578 / 375,1653, 58×58 | off-screen crate (box) / Void / other object |
| 0x4da / 0x4d3 / 0x4d5 | interface2_ipad_large | 399,89 / 1821,89 / 1329,93, 114×10 | hull bar frame red / green / yellow |
| 0x4d9 / 0x4d4 / 0x4d6 | interface2_ipad_large | 1445,93 / 399,101 / 1445,101, 110×6 | hull bar fill red / green / yellow |
| 0x4d8 / 0x4d7 | interface2_ipad_large | 112,2020 114×10 / 1581,89 110×6 | EMP bar frame / white fill |
| 0x456 | interface_iphone4 | 1,179, 1920×80 (24 frames 80×80) | lock ring |
| 0x4c4 | interface_iphone4 | 1601,793, 408×57 | lock plate |
| 0x4ac / 0x4ad | interface_iphone4 | 511,78 / 503,122, 41×42 | shield icon blue / red (hit) |
| 0x4aa / 0x4ab | interface_iphone4 | 272,749 / 250,966, 41×42 | hull icon blue / red (no armor) |
| 0x4a9 | interface2_ipad_large | 112,1741, 247×39 | status row plate |
| 0x4ae / 0x4af | interface2_ipad_large | 829,93 / 149,1, 248×14 | shield frame / cyan fill |
| 0x4a7 / 0x524 / 0x4a8 | interface2_ipad_large | 579,93 / 1440,195 / 1079,93, 248×14 | hull frame / red hull fill / yellow armor fill |
| 0x1f59 / 0x1f5a / 0x1f5b | interface3_ipad_large | 1,267 42×42 / 57,956 / 1087,17 248×14 | gamma icon / frame / fill |
| 0x52c / 0x52b | interface2_ipad_large | 112,112 324×1000 / 1012,1670 1000×374 | blue hit arc side (")" = right) / top ("⌒") |
| 0x526 / 0x525 | interface2_ipad_large | 438,1074 325×892 / 438,112 1000×375 | red hit arc side / top |
| 0x4c3 | interface_iphone4 | 1601,746, 392×44 | HUD message background |
| 0x4c0 / 0x4ce | interface_iphone4 | 392,78 / 1835,1231, 81×81 | crosshair / hit crosshair |

---

## 8. Sounds

| FMOD id | Event → .ogg (`fmod_event_ids.txt`) | When |
|---|---|---|
| 25 | Incoming_Fire_Shield → `SFX_SPACE/Incoming_Fire_Shield_v01/v02` | player hit, shield layer |
| 23 | Incoming_Fire_Armor → `Incoming_Fire_Armor_v02a/V02 b/V02c` | player hit, armor layer |
| 24 | Incoming_Fire_Hull → `Incoming_Fire_Hull_v01/v02` | player hit, hull layer |
| 20 | Destruction_Ship_Small → `Destruction_Ship_Small_1/1b` | NPC starts dying (3D) |
| 18 / 19 | Destruction_Ship_Big (`_4/_4b/_5/_5b`) / Destruction_Ship_Mid (`Destruction_Ship_Med_1..3`, name-matched) | type-0 explosion (NPC final blast, player death at 3 s), random |
| 21 | Destruction_Asteroid | asteroid (incl. rammed) |
| 22 | Garbage_Explosion | space junk, turrets, scatter, mines |
| 26 | Target_Lock → `SFX_SPACE/Target_Lock_v08` (name-matched) | ship / crate lock |
| 0 | Tractor_Beam → `Tractor_Beam_v1` (loop) | tractor pulling |
| 4 | Tractor_Beam_Close_Door → `Tractor_Beam_Close_Door_01c` | crate captured |
| 37 | game_over → `game_over_v02` | game over |
| 36 | Mission_accomplished → `Mission_Accomplished_v05` | bounty collected |
| 35 | Selfdestruct_Warning → `DLC2_SFX/Selfdestruct_Warning` (loop, parameter = instability) | volatile cargo aboard |
| 27 | Low_Life → `Low_Life_v03` | **never started** in this build (only stopped on death) |
| 1115 (0x45b) | DLC, name-matched `DLC_SFX/Invincibility_01` | emergency system |
| 2257 / 2258 | DLC2, not mapped | shield injector |
| 52–62, 2276 | NPC gun shots per race | §4.1 |
| 140/141/142, 136, 149–151 | combat music | §7.5 |

No shield-hit vs hull-hit sound for NPC targets, no missile-incoming alarm, no lock-on warning when an NPC targets the player.

---

## 9. Unity build recipe

Consistent with the existing remake classes (`GoF2Target`, `GoF2Gun`, `GoF2WeaponSystem`, `GoF2FlightHud`, `GoF2NavigationView`, `GoF2MiningView`).

1. **`GoF2Hitpoints` (plain C#)** — shield (float), armor, hull (ints), maxima, EMP points/max/recovery, `vulnerable`, flags `shieldHit/armorHit/hullHit`, `damagedByPlayer`, `killedByNpc`. `Damage(int dmg, bool fromNpcGun)` = §2.1 exactly (truncate the shield, overflow to armor, then hull); `DamageEmp`; percentages for the HUD. Asteroids already have HP in `GoF2Target`: move them onto this class (radius, no shield/armor, EMP 0).
2. **`GoF2Target`** gets a `GoF2Hitpoints`, a faction (`Enemy/Friend/Neutral` from the standing, pirates and Void always enemy), a race, a `hitRadius` (player 1200, NPC 1000 / 650 hardcore → Unity ×0.05) for the existing axis-aligned cube test, a loot list and a death state machine: alive → dying (1500–2999 ms tumble + drift, sound 20, smoke) → exploded (`Explosion` type 0 prefab: `explosion_anim_lookat_alpha/_add` camera-facing 4500 ms + 3–9 `explosion_debris_anim_add`, sound 18/19, hull visible 300 ms) → crate (60 s) → removed. Freighters/battleship: wreck prefab from `assemblies.json explosionModel`, then a ×6/×8 explosion.
3. **`GoF2Gun`** already fires the player's guns; use it for NPCs with the §4.1 parameters (`damage`, pool 4, lifetime 3000, reload 600 − 2·campaign, speed 16 u/ms, race item for the projectile/impact prefab from `GoF2WeaponFx`). Give each gun a target list per §4.2 (player + other races; player guns: everyone). Apply the NPC→player modifiers (×0.2 non-hostile owner, ×0.75 turret seat). NPC fire gate: target within 0.44° of the nose and 35000 units per axis (the AI side in `npc_traffic_ai.md`).
4. **Player (`GoF2WeaponSystem` / ship controller)**: create `GoF2Hitpoints` from `ships.json armor`, attr 18/20; shield regen tick (≥ 101 ms, +max·100/attr19), repair bot timers, emergency system, no EMP. Persist hull/shield/armor in `GoF2Session` across `Space`/`Station` loads (the original restores them; −1 = full).
5. **Collisions**: asteroid contact = asteroid `Damage(9999)` + player `Damage(20)` + camera shake; station/gate/ships = push-out + shake, no damage.
6. **Difficulty**: a `GoF2Settings.Hardcore` bool → factor 2 on NPC hull and damage, radius 650, delict ×2, friendly-fire thresholds 10/25/40 %.
7. **Standing (`GoF2Standing`, plain C#)**: the two axes, `ApplyDelict`, kill (5), steal/disable (2), pirate kill (+1 to the system race), signature override; friendly-fire accumulation and thresholds of §2.7 (radio messages can be HUD texts until radio exists). Save in `GoF2Session`.
8. **Loot**: roll `Generator::getLootList` with `UnityEngine.Random` (§5.4) when an NPC spawns; crate prefab by race; tractor beam item → salvage lock (attr 24, ring after 500 ms), beam prefab 14232–14235 stretched to the crate, pull 10 u/ms, capture < 400 units, first entry only, `GoF2Session.Cargo` add with the free-space cap, message "`<n>t <name>`" (green) or 322. No tractor beam → 540. Kills: +1 kill/XP stat, no credits.
9. **HUD (`GoF2FlightHud` / a new `GoF2CombatView` beside `GoF2NavigationView`)**, only with a scanner mounted: per target the §7.2 rule (off screen: dot/ring on the 657×491 ellipse like the jumpgate icon; far: dot/ring + distance for the lock; near: 110 px hull bar at (−59, +63), EMP bar, bracket when locked); ship lock via the existing lock-ring code of `GoF2MiningView` (24 frames, no delay, scanner attr 29, sound 26, sticky); the top plate reuses the navigation plate with `"<race> NN%"` + race icon. Status bars top-left (§7.6) from the cut images; hit arcs (§6.1, 300 ms, blue/red by shield). Messages through the existing HUD message queue (4000 ms, colours of §7.7).
10. **Feedback**: camera shake component on the chase camera (hit: 1000 ms ±6 units = ±0.3 m per axis per frame; shot: 50 ms ±2; explosion rumble on the look-at point `p·(±50 units)`, p = (1 − min(d,30000)/30000)(1 − t/2000)); sounds 25/23/24 by layer.
11. **Player death**: emergency system check; freeze the chase camera, smoke, spin, explosion at 3 s, sound 37 at 8 s, overlay/"Tap to load last savegame." (196) → reload the station with the last `GoF2Session` save (or the main menu when none).
12. **Music**: count hostile, living targets each frame; 0 → race no-combat track, 1–2 / 3–4 / ≥ 5 → Space_Battle_Low / Medium / Full; switch only when the category changes.

---

## Uncertainties

1. **Hit-direction bits**: the hit vector is set by `setHitVector` with arguments the decompiler lost (probably the bullet velocity), and the ±15000/±50000 screen-x thresholds of the "in front" branch are odd. Which arc lights for which real direction (and whether left/right are swapped) should be checked in play; the images/timers are certain.
2. **Hit-arc anchors**: `DrawImage2D` anchor bytes (0x11/'A', 0x12/'B', '!'/'$' + flip) aren't fully decoded; the arcs are placed on the ellipse extremes, left mirrored and bottom flipped by the flip argument (the image shapes confirm the orientation).
3. **Near-bar fill y offset** and exact inset: the `DrawRegion2D` destination y was lost; assumed frame y + 2.
4. **Fighter tumble rate / drift speed** (`+0x18c`, the scalar on `+0x184`/`+0x190`) and the player's death spin are lost floats; tune visually. The drift during dying uses the ship's direction at death.
5. **Named-target colour** on the lock plate (`SetColor` value lost) for wanted / "Hijacker" / "Informer" ships.
6. **KIPlayer+0x10** "parent" damage forwarding: set outside the functions read (probably station modules / hosts); semantics assumed.
7. **Game-over overlay image** `MGame+0x10` is never assigned in `MGame` (−1); probably a black/grey fade or a screenshot set elsewhere.
8. **Scanner cargo readout** distance test: the decompiled compare chain looks always-true; assumed "within 24000 units per axis" like the near test.
9. **Shield regen tick** is frame-rate dependent in the original (≥ 101 ms, remainder dropped); the remake may prefer a continuous `max/attr19` per ms (≈ original at high frame rates is 17 % faster than the original at 60 fps). Decide by feel.
10. **Sound names** for 19 (no file listed; `Destruction_Ship_Med_*` by name), 26, 1115, 2257/2258 are name-matched guesses.
11. **NPC fire cone** 0.00763 applies to the normalized target direction in ship space; with the AI's own aiming this means NPCs shoot only when almost perfectly aligned. The AI's turn logic (`npc_traffic_ai.md`) decides how often that happens.
12. **Mission / campaign overrides** of NPC hull, damage and target lists are only sampled (dozens of cases in `Level::createMission` / `createCampaignMission`); free play uses the generic formulas above.
13. **Radar+0x1ac** ("ship locking enabled", always 1 here) and `KIPlayer+0x38/+0x39/+0x70` meanings are inferred from use (0x38: static/non-combat object, 0x39: excluded from locks, 0x70: hidden from the radar).
