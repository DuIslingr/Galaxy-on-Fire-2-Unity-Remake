# Campaign mission levels, part B: missions 51-110 (in space)

Research for the remake's campaign: what the original builds and scripts in space for campaign mission indices
51..110 (`Status::getCurrentCampaignMission()`, `Status+0x1e8`). Missions 0-50 are in `campaign_levels_a.md` (which also
documents the shared mechanisms in detail), 111+ in `campaign_levels_c.md`.

Sources (Ghidra pseudocode, image base 0x10000; line numbers refer to `Reference/decompiled/native/game/<Class>.c`):

| Function | Address | Use |
|---|---|---|
| `Status::nextCampaignMission` | 0xb6c98 | builds the next campaign `Mission` (type, reward, target station), gives/takes items and ships |
| `Status::departStation` | 0xb63e0 | decides which mission is active in the orbit being entered (`Status+0x190`) |
| `Level::init` (calls `createCampaignMission`, line 616) | 0xbb49c | only for a normal orbit (`Level+0xc0 == 3`) with an active campaign mission |
| `Level::createCampaignMission` | 0xc3370 | spawns per mission; sets the win / fail objectives |
| `Level::createRadioMessages` | 0xd0574 | the scripted radio messages per mission |
| `Level::createStaticObject` / `createShip` | 0xcda54 / 0xcf83c | mission objects / ships (see `npc_traffic_ai.md` 2.4 for createShip) |
| `Level::createStaticObjects` | 0xcadb0 | campaign-state scenery (mining plant, plasma array) |
| `LevelScript::LevelScript` / `process` | 0x15e650 / 0x160d50 | per-mission start set-up and per-frame script |
| `Objective::achieved` | 0xa36fc | objective types |
| `RadioMessage::triggered` | 0x17c5d8 | radio trigger types |
| `MGame::successCheck` / `gameOverCheck` | 0x1b0620 / 0x1b0d04 | win / fail handling |
| `DialogueWindow::hasSuccessDialogue` | 0x194cb0 | table `DAT_0025a158` |

Conventions: positions are game units (Unity = `(x, y, -z) * 0.05`), times in ms, text IDs as `0xNNN (dec)` with
only a short gist (the text is in `Assets/Localization/text_en.json`). "enemy[i]" = index i of the level's object
array `Level+0xf8`, which holds every mission ship and mission object, friend or foe (objectives and radio
triggers address objects by that index). Ship names from `ships.json`, station names from `stations.json`.

## 1. Mechanisms (short; details in campaign_levels_a.md)

### 1.1 Which mission is active where

- `nextCampaignMission` increments `Status+0x1e8` and creates the mission for the NEW index:
  `Mission(type, reward, targetStation)` (`Mission+8` type, `+0x24` reward credits, `+0x30` target station,
  `+0x50` campaign flag). Types below 16 are the freelance enum (text `0x162 + type`: 1 Defense, 4 Pirate hunting,
  6 Wanted, 8 Purchase, 10 Intercept, 11 Passenger...); in the campaign 0xb is used for "go to / dock at station X".
  Types >= 0x96 are campaign-only pseudo types.
- **Mission 53 does not exist**: `case 0x34` (current 52) jumps back to the switch head, so 52 advances straight to 54.
- `Status::departStation(station)` (entering an orbit) sets the level's mission `Status+0x190` to the campaign
  mission when `station == targetStation` and the type is not a station-side type (0x96, 0x97, 0x99, 0x9b, 0xa1-0xa4,
  0xa6, 0xa7, 0xa9, 0xad, 8, 0xe). Type **0xa0** is active in every orbit EXCEPT the target station (mission 52);
  0xad only while carrying the production good.
- `Level::init`: if the level is a normal orbit (`Level+0xc0 == 3`) and `Status+0x190` is a non-empty campaign mission
  (and the game is not won with the post-game options), `createCampaignMission()` replaces the ambient traffic
  (`createMission`). Then `createStaticObjects`, sentry guns / fighter turrets / wingmen.
- **Alien orbit**: `Status::inAlienOrbit()` = the current station object equals `Status+0x78`, a special off-map orbit
  the story jumps the player to (Khador jump with `Level::programmedStation = Status+0x78`, see mission 79).
  `Status::inSupernovaOrbit()` = station 109 Naneroh and not the alien orbit.
- Many mission indices have **no in-space content** (plain `break` in `createCampaignMission`, no radio, no script):
  they are completed in a station (bar agent dialogue, delivery, production, docking). They are listed in section 3.

### 1.2 Level fields used by the mission code

| Field | Meaning |
|---|---|
| `Level+0xf0` | player (`PlayerEgo`) |
| `Level+0xf8` | object array ("enemies"): every mission ship and object |
| `Level+0xfc` / `+0x100` | asteroids / landmarks |
| `Level+0x108` | player route (HUD waypoint markers, objective type 2) |
| `Level+0x10c` / `+0x110` | friend route / enemy route |
| `Level+0x114` | radio message array |
| `Level+0x118` / `+0x11c` | enemies left / friends left |
| `Level+0x20` / `+0x24` | counters bumped by `enemyDied(i, true / false)` (objective types 0x14 / 0x15) |
| `Level+0x28` / `+0x2c` | WIN objective / FAIL objective |
| `Level+0x130` | time limit (never set by `createCampaignMission`: campaign levels have no time limit) |

### 1.3 Objectives (`Objective(type, a[, b], level)`, `Objective::achieved` 0xa36fc)

| Type | Achieved when |
|---|---|
| 0 | enemies left == 0 |
| 1 | enemy[a] dead |
| 2 | the last waypoint of the player route reached |
| 3 | survival: level time > a ms (the only "survival" type) |
| 4 | radio message #a is over |
| 5 | friends left == 0 |
| 7 | enemy[0..a-1] all dead |
| 8 | more than a asteroids destroyed |
| 0xb / 0xc | enemy[a] byte +0x65 / +0x64 set |
| 0xf | enemy[a] active |
| 0x10 / 0x11 | all enemies +0x65 / any enemy +0x64 |
| 0x12 | enemy[a..b-1] all dead |
| 0x13 | friend cargo stolen (`Level+0x13c`) |
| 0x14 / 0x15 | enemy[a..b-1] all dead in state 8 and `Level+0x20 < Level+0x24` / `>=` |
| 0x16 | the LAST radio message is over |
| 0x17 | enemy[a] disabled (EMP, byte +0x20) |
| 0x19 | enemy[a] float +0x60 == 0 |
| 0x1a | any of enemy[a..b-1] dead |
| 0x1b | enemies left < a |
| 0x1c / 0x1d | delivered ore / passengers >= a |
| 0x1e | enemy[a] dying |

### 1.4 Win and fail (`MGame`)

- `successCheck`: every 5000 ms (at once for campaign type 0xaa) `Level::checkObjective` evaluates `Level+0x28`.
  On success of a campaign mission: when `DialogueWindow::hasSuccessDialogue(mission)` (`DAT_0025a158[mission] > 0`)
  the success dialogue opens and the campaign advances from it; otherwise (and mission > 45) `nextCampaignMission()`,
  `Level::removeObjectives`, `Status::setMission(empty)` at once. After opening the dialogue it applies fix-ups:
  mission 56 (0x38) sends every kind-1 ship along a new route to a planet, 63 (0x3f) removes all guns from pirate
  (race 8) ships, 73 (0x49) makes the living always-friend ships 9 999 999 hull and moving again.
- `DAT_0025a158` values for 51..110 (0 = no success dialogue):
  51-53: 0, 54: 16, 55: 28, 56: 4, 57: 20, 58: 24, 59: 2, 60: 16, 61: 16, 62: 26, 63: 4, 64: 10, 65: 34, 66: 24, 67: 16,
  68: 20, 69: 0, 70: 2, 71: 14, 72: 30, 73: 18, 74: 4, 75: 26, 76: 20, 77: 40, 78: 0, 79: 0, 80: 12, 81: 0, 82: 16,
  83: 18, 84: 0, 85: 4, 86: 8, 87: 0, 88: 16, 89: 0, 90: 18, 91: 0, 92: 14, 93: 22, 94: 14, 95: 32, 96: 20, 97: 6,
  98: 24, 99: 24, 100: 0, 101: 20, 102: 12, 103: 20, 104: 14, 105-107: 0, 108: 30, 109: 8, 110: 6.
  (The value looks like a line / page count of the dialogue; only "> 0" is tested here.)
- `gameOverCheck`: player hull <= 0 -> emergency system, else explosion and "Game over" (0x13f), reload of the last
  save (fail counters `Globals::lastCampaignMissionFailed / FailCount` are kept per mission). `Level+0x2c` achieved
  -> failure dialogue (`DialogueWindow::set(mission, 2)`). The time-limit failure never applies (no limit is set).
- Many scripts advance the campaign themselves (`Status::nextCampaignMission` from `LevelScript::process`), usually
  at the end of a cutscene; entering a wormhole during a campaign mission also calls `nextCampaignMission`
  (`MGame::OnUpdate`, with exceptions for missions 29 and 40-42).

### 1.5 Radio messages

`RadioMessage(textId, portraitId, triggerType, param[, count])`; with a count the message watches the enemy
indices `param .. param+count-1`. Messages play one at a time through `Radio`; "after #n" chains are the normal way
to write a conversation. Trigger types used below (`RadioMessage::triggered` 0x17c5d8):

| Trigger | Fires when |
|---|---|
| 0 | the player's route passes waypoint `param` |
| 1 / 2 | any listed enemy dead / any listed important (+0x5d) enemy dead |
| 3 / 4 | enemies left < 1 / friends left < 1 |
| 5 | level time >= `param` ms |
| 6 | radio message #`param` is over |
| 8 / 10 | any listed enemy active / any listed important enemy active |
| 9 | all listed enemies dead |
| 0xb | an Objective is achieved (constructor with an `Objective*`) |
| 0xc / 0x13 / 0x1f | any listed enemy below 50 % / 25 % / 75 % hull |
| 0xe / 0x12 / 0x15 | enemy[`param`] flag +0x65 / +0x65 or +0x66 / disabled (+0x20) |
| 0xf / 0x11 / 0x14 | any enemy dead / an enemy other than #`param` dead / >= `param` enemies dead |
| 0x10 | any active non-always-friend enemy |
| 0x16 | `Level+0x1c >= param` |
| 0x17 | the station is locked on the radar |
| 0x18 | enemy[`param`] inactive, not dead, level time > 60 000 |
| 0x19 | route left waypoint 0 with >= `param` enemies alive |
| 0x1a | enemy[0] within 5000 units of `param` on an axis (unverified) |
| 0x1b | **LevelScript event** (`LevelScript+0x1c`) == `param` (how scripts cue lines) |
| 0x1c | player armor < 1 |
| 0x1e | number of dead among enemy[2..5] == `param` |

**Portraits** (`Radio` 0x180380): the speaker's name is text `0x63d + portrait` (1597 + p); the face comes from
`PTR_DAT_0026447c[p]` (5 face-part indices) for p < 63 except 21, a generic race character otherwise (64 / 65 / 21
/ 0x41 map to character types 0 / 1 / 3 / 2), and p >= 10000 is a Wanted person. Names of the ids that occur below:
0 Keith T. Maxwell (the player), 1 Brent Snocom, 2 Gunant Breh, 3 Norris Bernard, 4 Mkkt Bkkt, 5 Tommy, 6 Carla,
7 Errkt Uggut, 8 Jean Baffour, 9 Pirate Boss, 10/11/28-30 Pirate, 12/13 Security, 14 Hijacker, 15 Computer,
16 Info, 17 Story, 18 Terran Officer, 19 Void, 20 Khador, 21 Midorian, 22 Nivelian, 23 Agent, 24 Taret Orskk,
25 Mekant Orskk, 26 Alice, 27 Escort, 31 Cornelius Tenner, 32 Netor, 33 Convoy Captain, 34 Trot Lykkt,
35 Smuggler, 36/56 Corny, 37 Bargand Surr, 44 Dr. Gum'Skratch, 45 Pal Tyyrt, 46 Kehnor, 47 Hongar Meton,
50/63 Vossk, 59 Freighter Captain, 60 Gunant IV, 61 Deep Science Escort, 64 Terran, 65 Nivelian, 69 Turret,
70 Battleship.

**Milestone nag messages** (not mission-bound): `nextCampaignMission` sets `Status+0x178` when the new index is 93,
111 or 143. The next time the player is in a normal orbit and 12 s of playing time have passed, `MGame::OnUpdate`
adds `Level::createRadioMessage(0x1b, k)`: texts `0xc60 + 2k` (portrait 6, at 1500 ms) and `0xc61 + 2k` (after it),
k = 0 for missions 93-110, 1 for 111-142, 2 from 143 (`DAT_0025d4d4` = {111, 143}): a friend hailing the player and
the player's grumbled reply.

### 1.6 LevelScript fields

| Field | Meaning |
|---|---|
| `+0` | time limit (copy of `Level+0x130`) |
| `+8/+0xc` | elapsed level time (64-bit ms) |
| `+0x11` | cutscene running (skippable via `LevelScript::skipCutscene`) |
| `+0x14` / `+0x18` | `TargetFollowCamera` / `Level` |
| `+0x1c` | **event / script step** (`getEvent` / `setEvent`, radio trigger 0x1b) |
| `+0x20` | start-sequence (launch / arrival camera) flag |
| `+0x28` | camera position work vector |
| `+0x90/+0x94` | step timer (64-bit ms, reset on each step change) |
| `+0xbc`, `+0xcc`, `+0xd8`, `+0xdc` | helper `AEGeometry` objects (look-at dummies, fx meshes) |
| `+0xd0` / `+0xd4` | `Hud` (byte +1 = HUD visible) / `Radar` (byte +0x48 = radar visible) |

The constructor hides HUD and radar, makes the player computer-controlled and invulnerable for cutscene starts;
`Level::programmedStation` and `Level::doInstantJump` (statics) drive scripted autopilot and Khador jumps.


---

# Campaign missions 51..69 (0x33..0x45): in-space content

Sources: `Level::createCampaignMission` (Level.c, jump table at 0xc340e, case addresses below), `Level::createRadioMessages`
(Level.c 13120-13342), `LevelScript::process` (tbh at 0x161b94 for 0x40..0x49, missions 0x39..0x3f fall to the 0x38 test at
0x162918), `LevelScript::LevelScript` (0x41 block 0x160044), `MGame::successCheck`, `MGame::dockEvent`, `MGame::UseKhadorDrive`,
`MGame::OnTouchEnd` (dialogue-closed path), `Level::connectPlayers`, `Level::createMission`, `StarMap::drawOnScreenInfo`.
Floats verified with disasm.py where marked. All positions are game units, engine space.

General notes for this range:
- `createShip(race, kind, ship, wp, true, false)`: hull `4*mission + 14*min(level,20) + 20`, **forced to 270 for missions
  0x31, 0x32, 0x33, 0x34, 0x38** (bitmask 0x8f at createShip 0xcf8xx), then kind 1 x5, then difficulty scaling.
- Campaign levels replace the normal traffic (`Level::createMission` line 616: campaign branch only calls createCampaignMission).
- `hasSuccessDialogue` table DAT_0025a158 (index = mission): 0x33 0, 0x34 0, 0x35 0, 0x36 16, 0x37 28, 0x38 4, 0x39 20, 0x3a 24,
  0x3b 2, 0x3c 16, 0x3d 16, 0x3e 26, 0x3f 4, 0x40 10, 0x41 34, 0x42 24, 0x43 16, 0x44 20, 0x45 0. With 0 the win directly calls
  `nextCampaignMission()` (successCheck, missions > 0x2d).
- The dialogue-closed path in `MGame::OnTouchEnd` calls `nextCampaignMission()` **before** its per-mission checks, so a check
  `== 0x41` there means "mission 0x40 was just won".
- No mission in this range sets a time limit (Level+0x130).
- Portrait ids seen: 0 = player; 0x3f (generic/Vossk portrait per npc_traffic_ai.md: "others 0x3f"), 0x1b, 0x1c, 0x1d, 0x1e,
  0x1f, 0x14 (character mapping unverified; 0x14 speaks as Khador, 0x1f as Corny, 0x1e/0x1d as pirates).
- Docking restriction (`MGame::dockEvent` line 6397): while the campaign index is 0x31..0x36, docking (autopilot to station /
  station collision) is refused with `hudEvent(0x15)` unless the current station is 74 (Kanado).

---

### Mission 51 (0x33) - Vossk freighter at the S'inokk jumpgate

- **Orbit:** type 0x9c, target station 25 S'inokk (S'kolptorr, the system's gate station). Content when Status+0x190 is this
  mission (departStation(25)). Case at 0xc63d4 -> shared code 0xca84a.
- **Player start:** normal arrival/launch; no special setup.
- **Spawns** (enemies array size 6):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createShip(1 Vossk, kind 1, ship 13 = Vossk freighter `cargo_004_vossk`) | `G + (P - G) / 3` (one third of the way from the gate to the player; divisor 3.0 at 0xca916) | setAlwaysEnemy; no route (a PlayerFixedObject flies its +Z at 1 u/ms); hull 270*5 |
| 1-5 | createShip(1, 0, ship 9 H'Soc) | waypoint G (+ createShip jitter +-20000/axis) | setAlwaysEnemy; enemy route = loop on G (Level+0x110); hull 270 |

  G = landmark[1] (visible jumpgate) position, or (0, 0, 40000) if there is none; P = player position at creation.
  Level+0x18c ends up holding the freighter position.
- **Radio:**

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0x84d (2125) "target sighted, intercept" | 0x3f | 5: 8000 ms |
| 1 | 0x84e (2126) "keeps getting better" | 0 | 6: after #0 |

- **Script:** `LevelScript::process` 0x161818 routes 0x33 into the mission-0x32 block ("if radio[2] is over and event 0: all
  non-wingman enemies turn hostile, Standing(0) = 100"), but that block requires >= 3 radio messages; 0x33 has 2, so it is
  **dead code** for this mission (verified in disasm: `cmp r0,#3 / blo`).
- **Objectives:** none set (Level+0x28/+0x2c stay empty). Completion comes from `Status::missionCompleted` (called by
  successCheck with LevelScript elapsed ms): type 0x9c returns the mission when **level time >= 10001 ms and the current
  station == target (25)**. No success dialogue (table 0) -> immediate `nextCampaignMission()` -> 52. The spawned ships stay in
  the level. (So the fight is optional as decompiled; unverified in play.)

### Mission 52 (0x34) - Pursued by two Vossk freighters (flee to the gate)

- **Orbit:** type 0xa0, target 25; the level content is active in any orbit **other than** station 25 (departStation rule).
  Case 0xc63f8 -> 0xca9b8. Docking elsewhere than Kanado is refused (see general notes). `StarMap::drawOnScreenInfo` (line 1585)
  marks station 74 Kanado as the target on the star map during 0x34.
- **Spawns** (size 8):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createShip(1, 1, ship 13 Vossk freighter) | `F = G + (P - G) / 2` (halfway gate -> player, 2.0 at 0xcaa84) | setAlwaysEnemy, hull 1350 |
| 1 | createShip(1, 1, ship 13) | `F + (16000, 13000, 16000)` (vldr 13000/16000 at 0xcaae2) | setAlwaysEnemy |
| 2-7 | createShip(1, 0, ship 9 H'Soc) | waypoint G + jitter | setAlwaysEnemy, loop route on G, hull 270 |

  G = visible jumpgate, else (0, 0, 40000) (most non-gate orbits have no gate -> (0,0,40000)).
- **Radio:** #0 0x84f (2127) "stop him, the K'Suukk" portrait 0x3f, 5: 8000 ms; #1 0x850 (2128) "reach the jump gate" portrait 0,
  6: after #0.
- **Script:** none.
- **Objectives:** none. `Status::missionCompleted` type 0xa0: completes when **level time >= 10001 ms and current station != 25**.
  Table 0 -> immediate `nextCampaignMission()` (53 is skipped -> 54).

### Mission 54 (0x36) - Arrival at Kanado (radio only)

- **Orbit:** type 0xb, target 74 Kanado (Magnetar). createCampaignMission case is a plain `break` (no spawns).
- **Radio:** #0 0x851 (2129) "safe here for now" portrait 0, 5: 8000 ms (shared case 0x35/0x36; 0x35 = mission 53 is skipped).
- Docking allowed only at station 74 during 0x31..0x36 (dockEvent). Ends station-side (type 0xb, presumably docking at the
  target; success dialogue table 16).

### Mission 55 (0x37) - Arrival at Valkyrie (radio only)

- **Orbit:** type 0xb, target 101 Valkyrie (Herjaza). No spawns.
- **Radio:** #0 0x85a (2138) "right place" portrait 0, 5: 8000 ms; #1 0x85b (2139) "strange station" portrait 0, 6: after #0.

### Mission 56 (0x38) - Turret test with pirate escort (player in Vossk ship 39)

- **Orbit:** type 4, target 102 Scion (Herjaza; an empty orbit, no station object). The player flies the forced Vossk ship 39
  S'Kanarr with items 181, 52, 58, 83 (set by nextCampaignMission, station-side). Case 0xc641c.
- **Routes:** player route Level+0x108 and friend route Level+0x10c (clone), 3 waypoints (literal 0x253960):
  (0, 0, -60000) -> (-12000, -7000, -110000) -> (15000, 3000, -160000). The player gets HUD waypoints.
- **Spawns** (size 9):

| idx | what | position | notes |
|---|---|---|---|
| 0-2 | createShip(8 pirate, 0, ship 24 Velasco) | `0.8 * P + (rnd(7000) - 3500)` per axis (0.8 = 0x3f4ccccd) | setAlwaysFriend, setAlwaysEnemy(false), setToSleep, friend route clone, setHitpoints 9 999 999 |
| 3-4 | createShip(8, 0, random pirate fighter) | waypoint 0 (0,0,-60000) + jitter | setToSleep; hull 270 |
| 5-8 | same | waypoint 1 (-12000,-7000,-110000) + jitter | setToSleep; hull 270 |

  (Index >= 10 would use waypoint 2; the array is only 9 long.)
- **Radio:**

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0x86a (2154) "targets at next waypoint, turret test" | 0x1b | 5: 8000 ms |
| 1 | 0x86b (2155) "thank you" | 0 | 6: after #0 |
| 2 | 0x86c (2156) "under attack" | 0x1c | 0x10: any active non-always-friend enemy |
| 3 | 0x86d (2157) "not bad" | 0 | 0x14: >= 3 enemies dead |
| 4 | 0x86e (2158) "nice firing rate" | 0 | 6: after #3 |
| 5 | 0x86f (2159) "all units, fire at will" | 0x1b | 0x1c: player armor HP < 1 |

- **Script** (LevelScript 0x162918 / Ghidra 9511):
  - event 0 (first frame): every always-friend enemy `setShootingEnabled(false)` -> event 1.
  - event 1: when `Player::getArmorHP(player) < 1`: every always-friend enemy `setShootingEnabled(true)` -> event 2 (the
    escort only helps once the player's armor is gone; matches radio #5).
- **Objectives:** win Objective(0x12, 3, 9) = enemies 3..8 all dead. No fail objective. Success dialogue (table 4).
  successCheck fix-up for 0x38 (when the success dialogue opens, MGame.c 6639, disasm 0x1b0a98): a one-waypoint route to
  **`StarSystem::getPlanets()[2].position * 100`** (`ldr r0,[r0,#4]; ldr r1,[r0,#8]` = element 2; x100 = 0x42c80000; ints) is
  given to every enemy with **+0x24 == 1 (race Vossk)**. This level spawns only race-8 ships, so the fix-up appears to be a
  **no-op** here (unverified; maybe a leftover from a Vossk-escort version).

### Mission 62 (0x3e) - Arrival at Kothar (radio only)

- **Orbit:** type 0xb, target 100 Kothar (Beidan, deep science station). No spawns.
- **Radio:** #0 0x8a1 (2209) "where Carla has been hiding" portrait 0, 5: 8000 ms.

### Mission 63 (0x3f) - Pirate nest at Coromesk

- **Orbit:** type 4, target 103 Coromesk (Skavac; empty orbit, no station object). Case 0xc665e.
- **Spawns** (size 7):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createStaticObject(mesh 0x37a3 = 14243 `stations/station_pirates`) | waypoint (0, 0, 0) | setToSleep; name 0x1b9 (441) "Pirate Outpost" |
| 1-6 | createShip(8, 0, random pirate fighter, no waypoint) | outpost + per axis `(+-1) * rnd(20000) + 10000` (range -10000..+29999; verified `mla r, sign, rnd, #10000` at 0xc6770), truncated to int | setToSleep; normal pirate hostility |

- **Radio:** #0 0x8af (2223) "nest of pirates" portrait 0, 5: 8000 ms; #1 0x8b0 (2224) "where is Khador" portrait 0, 6: after #0;
  #2 0x8b1 (2225) "take him out, boys" portrait 0x1d, 6: after #1.
- **Script:** none.
- **Objectives:** win Objective(0x1b, 4) = enemiesLeft < 4 (whether the outpost counts in enemiesLeft is unverified). No fail.
  Success dialogue (table 4); successCheck fix-up: `Player::removeAllGuns` on every enemy with +0x24 == 8 (the pirates stop
  shooting / surrender).

### Mission 64 (0x40) - Rescue Khador from his pirate escort (Nosdron)

- **Orbit:** type 4, target 104 Nosdron (Skavac; empty orbit). Case 0xc684a.
- **Player start:** after the normal arrival, `PlayerEgo::setPosition(P - dir * 40000)` (player moved 40000 back along its own
  direction; 0x471c4000 verified at 0xc686c).
- **Route:** enemy route Level+0x110 = one waypoint (100000, 0, 0).
- **Spawns** (size 9):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createShip(0 Terran, 0, ship 38 Typhon) | setPosition(0, 0, 0), direction (1,0,0), up (0,1,0) | setAlwaysFriend; name 0x651 (1617) "Khador"; route clone (100000,0,0); loot list +0x4c = 0 |
| 1-8 | createShip(8, 0, random pirate fighter) | per axis `+-(1000 + rnd(1500))`, direction (1,0,0) | route clone (100000,0,0) (flying as Khador's escort) |

  `Level::connectPlayers` special case 0x40: no ship of the array gets enemy[0] as an enemy and enemy[0] gets none of the array
  (only the player is added), so Khador and the pirates never fight each other.
- **Radio:**

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0x8b4 (2228) "that must be Khador" | 0 | 5: 8000 ms |
| 1 | 0x8b5 (2229) "coming to rescue me" | 0x14 | 6: after #0 |
| 2 | 0x8b6 (2230) "first your escort" | 0 | 6: after #1 |
| 3 | 0x8b7 (2231) "we've been spotted" | 0x1e | 6: after #2 |
| 4 | 0x8b8 (2232) "don't destroy Khador's ship" | 0 | 6: after #3 |
| 5 | 0x8b9 (2233) "fall back" | 0x1e | 0x14: >= 5 enemies dead |
| 6 | 0x8ba (2234) "cowards" | 0 | 6: after #5 |

- **Script** (LevelScript case 0x40, 0x161bac):
  - event 0, when radio #0 triggered: cutscene - PlayerEgo+0x24 = 1, turret/free-look/first-person off, stop shooting,
    LevelScript+0x11 = 1, HUD and radar hidden, player computer-controlled; look-at camera on Khador at
    **Khador pos + Khador dir * 10000 + (0, 300, 3000)** (10000 = 0x461c4000, 300, 3000 verified at 0x1657c0) -> with dir (1,0,0)
    = (10000, 300, 3000) from Khador. -> event 1.
  - event 1: camera `translate(0, dt * 0.2, 0)` each frame (drifts up 0.2 u/ms, verified 0x167fc6); when radio #2 triggered:
    camera back to the player, control/HUD/radar back, cutscene flags cleared, **all enemies' routes set to null** -> event 2.
  - event 2: Khador byte +0x20 = 1 every frame (the "disabled" flag: Khador sits still). When radio #5 triggered: Khador +0x20 = 0;
    every non-wingman enemy 1..8: setSpeed(16.5), setEnemies(null), route (500000, 500000, 500000) (flee) -> event 3.
  - event 3: when radio #6 is over: `setDead` on enemies 1..8 (removed).
- **Objectives:** win Objective(0x16) = last radio message over; fail Objective(1, 0) = Khador dead. Success dialogue (table 10).
  **After the dialogue closes** (`MGame::OnTouchEnd` 3246, check `== 0x41` after the increment): `switch_to_target_setting = 1`,
  hull/shield/armor/gamma saved to Status, `Level::initStreamOutPosition = 1`, `Status::departStation(loadStation(100))` -> the
  game continues directly in **Kothar (100) orbit** with mission 0x41 (no docking in between).

### Mission 65 (0x41) - Escort Khador to Kothar

- **Orbit:** type 0xb, target 100 Kothar; entered straight from mission 0x40 (above). All special handling requires
  `!inAlienOrbit` and current station == campaign target.
- **Player start** (LevelScript ctor 0x160044): player at **(0, 0, 170000)** (0x48260400), facing the origin (direction =
  normalize(-pos), up (0,1,0)); Khador (enemy 0) at **player + (-3000, 0, 0) = (-3000, 0, 170000)**, rotation (0, pi, 0); then the
  generic arrival camera (skips the other arrival cases).
- **Spawns** (size 1): 0 = createShip(0, 0, ship 38 Typhon), setAlwaysFriend, name "Khador", enemy route Level+0x110 = one
  waypoint (0, 0, 0) (the station), setHitpoints 9 999 999.
- **Radio:** #0 0x8cb (2251) "Khador?" portrait 0, 5: 12000 ms; #1 0x8cc (2252) "loud and clear" portrait 0x14, 6: after #0;
  #2 0x8cd (2253) "let's dock" portrait 0, 6: after #1.
- **Script:** LevelScript::process case 0x41 is an explicit `break` (none).
- **Khador Drive:** `MGame::UseKhadorDrive` refuses it (`hudEvent(0x15)`) during 0x41 in the target orbit (not alien orbit).
- **Objectives:** none in the Level; type 0xb ends station-side (presumably docking at Kothar; unverified). Success dialogue
  table 34.

### Mission 67 (0x43) - Corny's break-in at the Nosdron pirate outpost

- **Orbit:** type 4, target 104 Nosdron (empty orbit). Case 0xc6bda. Route literal 0x253998.
- **Routes:** enemy route Level+0x110 and player route Level+0x108 (clone) = one waypoint **(220000, -20000, -10000)** (HUD marker).
- **Spawns** (size 11):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createStaticObject(0x37a3 `station_pirates`) | (220000, -20000, -10000) | name 441 "Pirate Outpost"; setAlwaysEnemy(false), **setAlwaysFriend(true)**, setToSleep |
| 1 | createShip(8, 0, random pirate) | overridden to **(250000, -20000, -10000)** (route point + 30000 x; verified 0xc6d66, it is enemy[1], not the outpost) | setToSleep, detection box +0x124 = 150000 |
| 2-4 | same | route waypoint + jitter +-20000 | setToSleep, detection 150000 |
| 5-9 | same | parked at (800000, 800000, 800000) (0x49435000) | setToSleep, detection 150000; 5-8 are brought in later, 9 never |
| 10 | createShip(0 Terran, 0, ship 27 Taipan) | player pos + (2000, 500, -7000) (verified 0xc6df0) | setAlwaysFriend; name 0x661 (1633) "Corny"; setMaxHitpoints 9 999 999; route = player route clone |

- **Radio** (12):

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0x8ef (2287) "wait while I create a disturbance" | 0 | 0x10: any active non-always-friend enemy (pirates wake) |
| 1 | 0x8f0 (2288) "wait for your signal" | 0x1f | 6: after #0 |
| 2 | 0x8f1 (2289) "scramble all ships" | 0x1e | 6: after #1 |
| 3 | 0x8f2 (2290) "Cornelius, move in" | 0 | 0x14: >= 2 enemies dead |
| 4 | 0x8f3 (2291) "don't blow up the station" | 0x1f | 6: after #3 |
| 5 | 0x8f4 (2292) "have some faith" | 0 | 6: after #4 |
| 6 | 0x8f5 (2293) "where's Cornelius" | 0 | 0x14: >= 8 enemies dead |
| 7 | 0x8f6 (2294) "didn't find anything" | 0x1f | 6: after #6 |
| 8 | 0x8f7 (2295) "all that work for nothing" | 0 | 6: after #7 |
| 9 | 0x8f8 (2296) "boss will go berserk" | 0x1f | 6: after #8 |
| 10 | 0x8f9 (2297) "you give her the news" | 0 | 6: after #9 |
| 11 | 0x8fa (2298) "over and out" | 0x1f | 6: after #10 |

- **Script** (LevelScript case 0x43, 0x162a8e; transitions verified in disasm):
  - event 0 + radio #1 triggered: Corny setSpeed(0), setEnemies(null), exhaust hidden (waits) -> event 1.
  - event 1 + radio #3 over: Corny setSpeed(3.0), exhaust on; cutscene (HUD/radar off, player computer-controlled and
    invulnerable, PlayerEgo+0x24 = 1), look-at camera on Corny at **Corny + (6000, -200, 1000)** -> event 2.
  - event 2 + radio #4 over: cutscene ends; Corny moved to (500000, 500000, 500000), setActive(false), invisible (he is "inside")
    -> event 3.
  - event 3 + radio #5 triggered: enemies 5..8 teleported to **outpost + (+-(15000 + rnd 10000), rnd(10000) - 5000,
    +-(15000 + rnd 10000))** (still sleeping, no awake call) -> event 4.
  - event 4 + radio #7 triggered: Corny at **outpost + (0, 0, 12000)**, direction (0,0,1) up (0,1,0), active, visible, setSpeed(2.0),
    route (0, 0, 800000) (literal 0x258e70); **fail objective removed** (Level+0x2c = 0); cutscene camera **Corny + (6000, -200,
    10000)**, player invulnerable -> event 5.
  - event 5 + radio #9 triggered: player vulnerable, Corny setSpeed(8.0), camera/control back -> event 6.
  - event 6 + radio #11 over: Corny setActive(false), invisible -> event 7.
- **Objectives:** win Objective(0x16) = last radio over; fail Objective(1, 0) = the outpost (enemy 0) destroyed (until event 4
  removes it). Success dialogue (table 16).

### Mission 69 (0x45) - Trot Lykkt leaves Inari Onu

- **Orbit:** type 6, target 66 Inari Onu (Vulpes). Case 0xc6ec4.
- **Route:** `Q = 4 * StarSystem::getPlanets()[1].position` (element 1: `ldr r1,[data,#4]` at 0xc6ed0; x4.0 = 0x40800000); enemy route Level+0x110 = 2 waypoints
  **Q -> 10*Q** (ints). Friend route Level+0x10c = (0, 0, 20000) (literal 0x2539a8).
- **Spawns** (size 5):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createShip(0 Terran, 0, ship 12 Type 43) | setPosition(Q), direction normalize(Q), up (0,1,0) | setAlwaysFriend; name 0x65f (1631) "Trot Lykkt"; route Q -> 10Q; setSpeed(5.5) |
| 1-4 | createShip(0, 0, random Terran fighter) | waypoint (0, 0, 20000) + jitter | no hostility flags (normal Terran standing) |

- **Radio:** #0 0x90e (2318) "he's leaving the orbit" portrait 0, 5: 8000 ms; #1 0x90f (2319) "flying to Lopat, after him" portrait 0,
  6: after #0.
- **Script** (LevelScript case 0x45, 0x162bb8):
  - event 0 + radio #0 triggered: cutscene, look-at camera on Trot at **Trot pos + Trot dir * 10000 + (600, 300, 1000)**
    (verified 0x162c76..) -> event 1.
  - event 1 + radio #1 over: cutscene ends -> event 2; Trot setActive(false), setToSleep, position (0, 0, -5 000 000), invisible.
- **Objectives:** win Objective(0x16) = last radio over. Table 0 -> immediate `nextCampaignMission()` (-> 70, Lopat).

---

### Other references in this range

- `Level::createMission` alien-orbit branch (line 2042, verified 0xbdb68): the number of Void fighters is forced to 2 when the
  campaign index is 0x44 (also 0x21).
- `StarMap::drawOnScreenInfo` 1696: during 0x3b the star map marks station 101 / system 23 as the campaign target.

### Missions without in-space content (station-side only)

- 53 (0x35): skipped by nextCampaignMission (its shared radio case 0x35/0x36 is never used for it).
- 57 (0x39), 58 (0x3a), 59 (0x3b, star-map target marker only), 60 (0x3c), 61 (0x3d), 66 (0x42): no Level case, no radio, no
  script.
- 68 (0x44): no Level case, radio or script (only the alien-orbit Void count above).

### Unresolved / uncertain

- 0x33/0x34 completion: as decompiled, `missionCompleted` types 0x9c/0xa0 finish the mission 10 s into the level (orbit ==
  / != station 25), so the Vossk ships don't have to be destroyed. Plausible (a "get away" sequence) but unverified in play.
- 0x38 fix-up routes race-1 ships to planets[2] * 100 but the level has only race-8 ships.
- Whether sleeping escorts in 0x38 (friends) follow their route before being woken is unverified.
- Portrait id -> character mapping.

---

# Part 2: campaign missions 70..89 (0x46..0x59), in-space content

All positions are in game units (Unity = (x, y, -z) * 0.05). Times are in ms. "enemies[i]" = Level+0xf8 array index.
Portrait ids are raw; the speaker is inferred from the text: 0 = Keith, 6 = Carla, 0x1a = Alice, 0xb = pirate,
0x22 = Trot Lykkt (?), 0x21 = convoy crew (?), 0x1f = Alice's crew (?), 0x11 = caption (no speaker, ?).
Float positions marked "disasm" were recovered from movw/movt/vldr in the disassembly
(`disasm.py --func "Level::createCampaignMission"` / `"LevelScript::LevelScript"` / `"LevelScript::process"`).
Success dialogue table DAT_0025a158 (DialogueWindow::hasSuccessDialogue, >0 = dialogue):
70:2 71:14 72:30 73:18 74:4 75:26 76:20 77:40 **78:0 79:0** 80:12 **81:0** 82:16 83:18 **84:0** 85:4 86:8 **87:0** 88:16 **89:0**.

Shared helpers used below:
- "Cutscene on" (LevelScript::process pattern): setTurretMode(false), resetCamera, freelook/first-person off,
  stopShooting, +0x11 = 1, HUD (Hud+1) = 0, radar (Radar+0x48) = 0, player computer-controlled, look-at camera.
- "Cutscene off": look-at off, camera target = player, player controlled, HUD + radar on, resetCamera
  (target offset (0, 600, -650), cam offset (0, 600, -1338)), +0x11 = 0, PlayerEgo+0x24 = 0.
- PlayerTurret objects: `createStaticObject(0, 0x381b, true)` = battlestation turret (name text 0x682 "Turret",
  has a gun, Player(1000, 100 HP)); mesh 0x381d = battlestation shield generator (name 0x681 "Generator", no gun,
  KIPlayer+0x21 = 0). Level.c 11394-11417.
- KIPlayer vtable: +0x08 setShipGroup (replace visual), +0x0c awake, +0x1c setSpeed, +0x20 translate,
  +0x28 getPosition, +0x44/+0x48 setPosition (npc_traffic_ai.md 1.1).

---

### Mission 70 (0x46) - stop Trot Lykkt before the jump gate

- **Orbit:** mission 70 = type 6, target 65 Lopat (Vulpes). Normal orbit, no LevelScript ctor special case.
- **Player start:** Level case 0x46 (Level.c 6081): player position = arrival position - direction * 120000
  (0x47ea6000, disasm c70ca), i.e. pushed 120 km back along its heading. No forced ship.
- **Spawns:**

| idx | what | position / route | flags |
|---|---|---|---|
| 0 | createShip(race 0 Terran, kind 0, ship 12 "Type 43"), named text 0x65f "Trot Lykkt" | pos = player + (gate - player) / 4 (gate = landmarks[0] position, Level+0x100 [0]); faces the gate, up (0,1,0); enemy route Level+0x110 = 1 waypoint at the gate (ints), its KIPlayer route = clone | setAlwaysFriend(true) at start; hitpoints = maxHP * 2.5 |

  Level::assignGuns (Level.c 9724/9892): in mission 0x46 every non-wingman gets gun damage x2.5 and gun index
  0xb7 (item 183 "Disruptor Laser", projectile mesh 0x37d9 v_projectile_183_anim_add).
- **Radio (Level.c 13343):**

| # | text | gist | portrait | trigger |
|---|---|---|---|---|
| 0 | 0x910 (2320) | stop him before the gate | 0 | 5: 8000 ms |
| 1 | 0x911 (2321) | "Trot Lykkt, surrender" | 0 | 6: after #0 |
| 2 | 0x912 (2322) | will test the Disruptor Laser | 0x22 | 6: after #1 |
| 3 | 0x913 (2323) | "He means business!" | 0 | 6: after #2 |

- **Script (LevelScript.c 9335-9426):**
  - step 0, radio #0 triggered: cutscene on, camera target enemy[0], camera = enemy pos + enemy dir * 3000
    (disasm 162a26) + (-600, -300, -1000); PlayerEgo+0x24 = 1; -> 1.
  - step 1, radio #1 over: enemy[0] alwaysFriend false / alwaysEnemy true, +0x124 (detection box) = 100000,
    +0x34 (target) = 0, drift/waypoint flags +0x128/+0x129 = 0, route = null (stops flying to the gate);
    camera = enemy pos + dir * 2000 (disasm 1656ae) + (-600, 800, -1000); +0x24 = 0; -> 2.
  - step 2, radio #2 over: cutscene off; enemy[0] maxHP x3, setSpeed(10.0), PlayerFighter::setRotate(5); -> 3.
- **Objectives:** win = Objective(1, 0) enemy[0] dead. No fail objective, no time limit (reaching the gate has no
  scripted consequence found). Ends with the success dialogue (2 entries).

### Mission 73 (0x49) - EMP the weapons convoy (at Teres)

- **Orbit:** mission 73 = type 10, target 81 Teres (Prospero).
- **Player start:** Level.c 6135: position (-30000, 0, 150000) (disasm c72c8), facing (170000, 0, -50000)
  (= route wp1 + 20000 x), up (0,1,0).
- **Routes:** enemy route Level+0x110 (data 0x2539b8): wp0 (80000, 0, 60000), wp1 (150000, 0, -50000).
- **Spawns:**

| idx | what | position | flags |
|---|---|---|---|
| 0-3 | createShip(8 pirate, 0, random pirate fighter) | wp0 + createShip jitter | alwaysEnemy, asleep |
| 4-7 | same | moved to (-800000, -800000, -800000) (0xc9435000) = parked out of the level | alwaysEnemy, asleep |
| 8-11 | createShip(0 Terran, kind 1, ship 15 freighter) | wp1 + rnd(20000)-10000 per axis | alwaysFriend, loot list +0x4c = 0, setMoving(true) |

- **Radio (Level.c 13364):**

| # | text | gist | portrait | trigger |
|---|---|---|---|---|
| 0 | 0x92b (2347) | that must be the convoy | 0 | 5: 8000 ms |
| 1 | 0x92c (2348) | pirates, worst moment | 0 | 0x10: any active non-friend enemy |
| 2 | 0x92d (2349) | "we've got a customer" | 0xb | 6: after #1 |
| 3 | 0x92e (2350) | can't let the convoy get away | 0 | 6: after #2 |
| 4 | 0x92f (2351) | time to use the EMP | 0 | 0x1b: event 1 |
| 5 | 0x930 (2352) | "We're under attack!" | 0x21 | 0x1b: event 2 |
| 6 | 0x931 (2353) | "That should do it!" | 0 | 0x1b: event 3 |
| 7 | 0x932 (2354) | even more of them | 0 | 6: after #6 |

- **Script (LevelScript.c 9427-9509):**
  - step 0: |player - enemies[8]| < 50000 -> 1.
  - step 1: any freighter (idx >= 8 with +0x3c custom-collide) has EmpPoints < MaxEmpPoints (first EMP hit) -> 2.
  - step 2: any freighter's Player+0x68 (EMP-disabled) set -> enemies[8] (the first freighter with +0x3c from 8)
    gets +0x20 = 1 (disabled) and setMoving(false) -> 3 (disasm 16eed2).
  - step 3: radio #7 triggered -> pirates 4..7 placed at player + (+-(35000+rnd 10000), rnd(10000)-5000,
    +-(35000+rnd 10000)) and awakened (vtable +0x0c) -> 4.
- **Objectives:** win = Objective(0x12, 0, 8) all 8 pirates dead; fail = Objective(0x12, 8, 12) all 4 freighters
  dead. successCheck fix-up (MGame.c 6689): living +0x3c objects (freighters) -> 9 999 999 HP, setMoving(true).
  Success dialogue (18). After it, nextCampaignMission -> 0x4a, and MGame::OnTouchEnd (MGame.c 3290) loads station
  100 (FileRead::loadStation) + setStation: the player is put straight into Kothar (docked).

### Mission 78 (0x4e) - escape from the Valkyrie battlestation

- **Orbit:** mission 78 = type 4, target 101 Valkyrie (Herjaza); the orbit station (landmarks[0]) is the
  battlestation.
- **Player start:** LevelScript ctor (LevelScript.c 363, disasm 15ea7e): camera setPosition (2000, -1500, 16000),
  +0x20 = 0 / +0x21 = 1, +0x24 = 0, player direction (0,0,1) up (0,1,0), event = 1, cutscene flag +0x11 = 1,
  fx +0xd8 = AEGeometry(0x3ab3 hyper_drive) scaling 20. Player position: not set (default arrival, unverified).
- **Spawns (Level.c 6216):**

| idx | what | position | flags |
|---|---|---|---|
| 0 | PlayerTurret 0x381b | table DAT_002539d4 entry 0 (-3994.97, 23359, -7378.1) with x + 1200 -> (-2794.97, 23359, -7378.1); rotation (0, 0, 1.5708) | no hostility set |
| 1 | PlayerTurret 0x381b | entry 1 (3994.96, 23359, -7378.1) with x - 1200 -> (2794.96, 23359, -7378.1); rotation (0, 0, -1.5708) | no hostility set |
| 2-21 | createShip(8 pirate, 0, random fighter), 20 ships | x = -17000 + 2000*(i-2) + rnd(2000), y = rnd(10000)-5000, z = 155000 + rnd(10000) (disasm c7732); facing (0,0,-1) | alwaysEnemy, asleep |

  (Turret offsets are relative to the station at the origin with identity matrix; the ±1200 constants are at
  0xc8034/0xc8038. See mission 80 for the full table.)
- **Radio (Level.c 13397):** 0 = 0x969 (2409) "underestimated Alice" p0, 5: 2000 ms; 1 = 0x96a (2410) "didn't know it
  could do that" p0, 0x1b: event 9; 2 = 0x96b (2411) get to Carla, integrated Khador drive p0, 0x1b: event 0xb;
  3 = 0x96c (2412) "Kill him!" p0xb, 6: after #2.
- **Script (LevelScript.c 2001-2302; `t` = level time LevelScript+8):** every frame once t >= 7901 the station's
  transform (landmarks[0]+0x13c) animation is updated.
  - 1: camera target = station geometry, station transform SetAnimationState(1,0) -> 2.
  - 2: camera translate (-0.5dt, 0.3dt, dt) per frame; t >= 7001 -> camera (20000, 5000, 30000) (disasm 164d12) -> 3.
  - 3: t >= 7901 play sound 0x462 once; t >= 9001 -> 4.
  - 4: t >= 18001 -> camera (8000, 31000, -9000) (disasm 164d9a), PlayerEgo+0x24 = 1, player invisible -> 5.
  - 5: -> 6 (same threshold), step timer reset.  Steps 5-8: camera translate (-0.8dt, 0, 0).
  - 6: enemies[1] translate (0.3dt, 0, 0) and rotate (-0.0009dt, 0, 0) per frame until 1100 units moved
    (~3.7 s, ~3.3 rad) -> 7 (turret slides out and swings round).
  - 7: t >= 27001 -> 8.
  - 8: enemies[0] does the same with -0.3dt; when moved and step timer >= 2001 -> camera (-12000, 5000, 15000)
    (disasm 165584) -> 9.
  - 9: camera translate (-0.7dt, dt, 3dt), rumble ramps timer/10000; after 6000 ms: hyper_drive fx at
    (0, 0, 14000), anim state 3 then 1, sound 0xa0 -> 10.
  - 10: camera translate (-0.7dt, dt, 4dt); fx faces the camera; rumble 1 - timer/4000; timer >= 2151: hide
    enemies[0], enemies[1] and the station (landmarks[0]) = the battlestation jumps away; timer >= 4001 -> 11.
  - 11: camera translate (-0.7dt, dt, 3dt); after 3000 ms: all enemies idx >= 2 translate (0, 0, -50000) and awake;
    camera target = enemies[count-10] (= idx 12), camera = its pos + (2000, 500, -20000) -> 12.
  - 12: camera translate (-0.3dt, 0.3dt, 0.5dt) for 5000 ms, then cutscene off (player visible, vulnerable,
    controlled, HUD + radar on) -> 13.
- **Objectives / end:** no win or fail objective. MGame::UseKhadorDrive (MGame.c 1944): in mission 0x4e the drive
  is always allowed; programmedStation = Status+0x78 (the alien orbit), startChargingJumpDrive,
  **nextCampaignMission** (-> 0x4f). No success dialogue.

### Mission 79 (0x4f) - misjump into the alien orbit

- **Orbit:** mission 79 = type 0xa5, target -1. Reached by the 0x4e Khador jump into the alien orbit (Status+0x78;
  its station index is presumably -1, so departStation makes the mission active, unverified).
- **Spawns (Level.c 6308):** idx 0-6 = createShip(9 Void, 0, random Void fighter), alwaysEnemy, no waypoint
  (createShip default spawn).
- **Radio:** 0 = 0x96d (2413) "What did Khador build here? try again" p0, 5: 6000 ms.
- **Script:** none (no LevelScript block). Alien-orbit camera far plane: 450000 while mission < 0x50, else 300000
  (MGame::reset / OnUpdate / startJumpScene, DAT_001a7bf8/bfc).
- **Objectives / end:** none set. Status::missionCompleted case 0xa5 (Status.c 3280) completes when the current
  station index equals the target (-1 = alien orbit), so the first successCheck (5 s) finishes it; no success
  dialogue -> nextCampaignMission (-> 0x50: Mission(type 1, target 100)). Probable, not traced end to end.
  Then MGame::UseKhadorDrive in the alien orbit with mission 0x50 forces Status+0x84 = 100 -> jump to Kothar.

### Mission 80 (0x50) - defend Kothar (deep science) against Alice's battlestation

- **Orbit:** target 100 Kothar (Beidan), the deep science station (landmarks[0]). PlayerStation ctor (PlayerStation.c
  398) uses the explosion variant in this mission: 0x381f v_station_deep_science_explosion_anim + 0x422a child
  (+0x140) + 0x3820 emissive + 0x3821 anim_add (assemblies_stations_notes.md).
- **Player start:** Level.c 6471 (disasm ca726): position (-70000, 0, -30000), direction (1, 0, 1), up (0,1,0).
- **Spawns (Level.c 6330, disasm c7834 / ca50c):**

| idx | what | position | flags |
|---|---|---|---|
| 0 | PlayerStation(Galaxy::getStation(101) Valkyrie battlestation), name = station name, race +0x24 = 8 | (0, 0, 160000) (0x481c4000), geometry rotation (0,0,0) | station object |
| 1-12 | PlayerTurret: bit (i-1) of 0x9f3 set -> 0x381b turret, else 0x381d shield generator | station pos + R(0,pi,0) * table offset, i.e. (-x, y, 160000 - z); rotation R * table rot = (0, 0, -rz) | race 8, alwaysEnemy, maxHP = level*15+220 (level <= 20) else 520 |
| 13-18 | createShip(8 pirate, 0, random fighter) | route Level+0x110 = 1 waypoint (0, 0, 80000) + jitter | alwaysEnemy |
| 19-21 | createShip(0 Terran, 0, ship 17 "Ward") | same waypoint | alwaysFriend |

  Turret/shield table DAT_002539d4 (stride 0x1c: type, pos xyz, rot xyz; type 0 turret / 1 shield, matches 0x9f3):

| e | type | pos (x, y, z) | rot z |
|---|---|---|---|
| 0 | turret | (-3994.97, 23359, -7378.1) | 1.5708 |
| 1 | turret | (3994.96, 23359, -7378.1) | -1.5708 |
| 2 | shield | (1988.03, -37327.1, -4511.46) | -1.5708 |
| 3 | shield | (-1995.02, -37327.1, -4511.46) | 1.5708 |
| 4 | turret | (-3264.75, -22848.6, 791.524) | 1.5708 |
| 5 | turret | (3273.29, -22848.6, 791.524) | -1.5708 |
| 6 | turret | (-29726.7, -10994.8, -3765.53) | 3.14159 |
| 7 | turret | (29716.2, -10994.8, -3765.53) | 3.14159 |
| 8 | turret | (29716.2, 4854.22, -3758.77) | 0 |
| 9 | shield | (17013, -764.391, -1690.65) | 0 |
| 10 | shield | (-17013.3, -764.512, -1690.65) | 0 |
| 11 | turret | (-29726.7, 4854.22, -3758.77) | 0 |

  (rot x = rot y = 0 for all.) In the station's own frame both missions 78 and 80 put the turrets at (-x, y, -z)
  of the table (78: station yawed pi, identity table matrix; 80: station unrotated, table rotated pi).
  Level::assignGuns: in mission 0x50 turrets (KIPlayer+0x3a) get gun damage x1.7.
  Level::initParticleSystems: two extra particle systems (Level+0x58 type 0x18, +0x5c) exist only in mission 0x50.
- **LevelScript ctor (LevelScript.c 1180, disasm 15f180):** +0xb8 = AEGeometry(0x3822
  v_station_deep_science_explosion_laser_anim_add), transform +0xe0 = 1000000.0, anim state 1, hidden, rotation
  (0, pi, 0); deep science transforms (+0xc, +0x14, +0x10) anim state 1, +0x140 anim state 2; +0xc8 = Explosion
  with fire streaks, scale 3.0; +0xdc empty geometry (hidden); +0xbc = AEGeometry(0x381e
  v_station_battlestation_laser_anim_add) at enemies[0] position, anim state 1; +0xd8 = hyper_drive 0x3ab3 scale 20.
- **Radio (Level.c 13430):**

| # | text | gist | portrait | trigger |
|---|---|---|---|---|
| 0 | 0x96e (2414) | hope I'm not too late | 0 | 5: 8000 ms |
| 1 | 0x96f (2415) | Alice, have you gone insane? | 6 | 5: 25000 ms |
| 2 | 0x970 (2416) | "sister dear" | 0x1a | 6: after #1 |
| 3 | 0x971 (2417) | the station must have weak points | 0 | 6: after #2 |
| 4 | 0x972 (2418) | what is wrong with you | 6 | 6: after #3 |
| 5 | 0x973 (2419) | "Prepare to fire... Maxwell?" | 0x1a | 6: after #4 |
| 6 | 0x974 (2420) | "Keith!" | 6 | 6: after #5 |
| 7 | 0x975 (2421) | why are you still alive | 0x1a | 6: after #6 |
| 8 | 0x976 (2422) | too many questions | 0 | 6: after #7 |
| 9 | 0x977 (2423) | "Retreat! Activate the Alice drive!" | 0x1a | 9: all of enemies[1..18] dead (turrets, shields, pirates) |
| 10 | 0x978 (2424) | initiate that drive now | 0x1a | 0x1b: event 0xc |
| 11 | 0x979 (2425) | "not done with you yet" | 0x1a | 6: after #10 |

- **Script (LevelScript.c 9761-10155):**
  - 0: radio #0 over: cutscene on (+0x24 = 1), camera target +0xbc (battlestation laser), camera = laser pos +
    (-20000, 5000, -35000); sound 0x461 -> 1.
  - 1: camera translate (dt, y lost, -dt); after 3000 ms -> 2.
  - 2: same translate + laser anim update; after 2000 ms: laser hidden -> 6.
  - 6: +0xdc placed at (12487, -11451, 5958) (disasm 169f8e); look-at target +0xdc; camera =
    (-28855, -30075, 63820) / 1.7 = (-16974, -17691, 37541) (disasm 169fcc), camera matrix set to look at +0xdc;
    +0xb8 (deep science laser hit) visible -> 7.
  - 7: after 800 ms -> 8.  Steps 7-9: camera translate (0.5dt, y lost, 0.2dt); from step 8 the +0xb8 anim and the
    deep science station's three animated transforms are updated (the station explosion animation plays).
  - 8: after 800 ms: Explosion::start at +0xdc, sound 0x12 (18); particle system Level+0x58 at +0xdc and emitting;
    point this+0x28 = +0xdc pos + (4500, 0, 1000), particle system Level+0x5c emitting there -> 9.
  - 9: explosion update, this+0x28.x += 2dt (particle point drifts); after 8000 ms: deep science transforms updated
    once more, cutscene off, +0xb8 hidden -> 10.
  - 10: radio #9 over: cutscene on, camera target +0xbc, camera = +0xbc pos + (20000, 5000, -20000) -> 11.
  - 11: camera translate (0.5dt, ?, 0.2dt); after 4000 ms: Explosion::start at (object pos, lost) + (-4000, 5000,
    -6000) -> 12.
  - 12: explosion update, translate, rumble timer/8000; after 8000 ms: hyper_drive fx at (position lost) +
    (0, 0, -10000), anim 3 then 1, sound 0xa0 -> 13 (radio #10 fires on event 0xc during step 12).
  - 13: translate, fx faces the camera, rumble 1 - timer/10000; timer >= 2151: enemies[0] (battlestation) geometry
    hidden (it jumps away); timer >= 10001: cutscene off -> 14.
- **Objectives / end:** win = Objective(0x16) last radio (#11) over. Success dialogue (12 entries; texts
  0x97a.. "she got away"). After it nextCampaignMission -> 0x51 and MGame::OnTouchEnd (MGame.c 3270) sets
  station = alien orbit (Status+0x78) + departStation(alien), switch_to_target_setting = 1: reload into the alien
  orbit for mission 81.

### Mission 81 (0x51) - Alice stranded in the alien orbit (cutscene)

- **Orbit:** alien orbit (Status::inAlienOrbit == 1); mission 81 = type 4, target -1.
- **Player start (LevelScript ctor 329, disasm 15e97c):** step timer 0, HUD + radar off, player computer-controlled,
  +0x24 = 1, invulnerable, invisible, engine sound stopped; look-at camera at (-20000, 800, 120000); player at
  (0, 0, 0); enemies[0] geometry (+0x13c) hidden; LOD force 30; +0xd8 = hyper_drive 0x3ab3 scale 30.
- **Spawns (Level.c 6484):** idx 0 = PlayerStation(station 101 Valkyrie battlestation), race 8, default position;
  idx 1-8 = createShip(9 Void, 0, ship 8 "VoidX"), no hostility flags, default spawn.
- **Radio (Level.c 13475):** 0 = 0x980 (2432) where are we, charge the Alice drive p0x1a, 5: 16000 ms;
  1 = 0x981 (2433) no more energy cells p0x1f, after #0; 2 = 0x982 (2434) buffoons p0x1a, after #1;
  3 = 0x983 (2435) stuck out here p0x1a, after #2.
- **Script (LevelScript.c 1899-1998):** every frame camera translate (2dt, 0, -4dt) (disasm 161246), +0x11 = 1.
  - 0: rumble timer/10000; t >= 10001: fx at (0, 0, 10000), anim 3 then 1, sound 0xa0 -> 1.
  - 1: rumble 1 - timer/4000, fx faces the camera; t >= 12001: battlestation geometry visible (arrives);
    t >= 14001 -> 2, rumble off.
  - 2: radio #3 over -> fade out (0xff, 5000) -> 3.
  - 3: fade done: fill screen, **nextCampaignMission** (-> 0x52), departStation(station 100), station
    setAttackedFriends(false), comingFromAlienWorld = 0, module 5 (docked at Kothar).
- **Objectives:** none; no success dialogue.

### Mission 87 (0x57) - flight to Thynome with Carla (radio chat)

- **Orbit:** mission 87 = type 4, target 10 Thynome (Wolf-Reiser); only when not in the alien orbit and the
  station == target.
- **Player start (LevelScript ctor 856, disasm 160190):** position (0, 0, 210000) (0x484d1400), facing the origin
  (the station), up (0,1,0).
- **Spawns:** none (Level case 0x57 only sets the objective).
- **Radio (Level.c 13496):** 0 = 0x9b0 (2480) "I've been thinking" p6, 5: 1500 ms; 1 = 0x9b1 p0; 2 = 0x9b2 move in
  with me p6; 3 = 0x9b3 p0; 4 = 0x9b4 curtains p6; 5 = 0x9b5 p0; each 6: after the previous one.
- **Objectives / end:** win = Objective(0x16) last radio over. No success dialogue -> successCheck calls
  nextCampaignMission directly.

### Mission 89 (0x59) - Ginoya supernova intro (cutscene, "Meanwhile in Midorian space")

- **Orbit:** mission 89 = type 4, target 109 Naneroh (Ginoya, the supernova system; inSupernovaOrbit). Special cases:
  Level::createSpace uses skybox_005 (mesh 0x458d + texture 0x2756) instead of the supernova sky (Level.c 816);
  Level::createAsteroids field centre (-100000, 0, -50000) (Level.c 1577); initParticleSystems skips the supernova
  particle direction (10688); Globals::playMusicAndFadeOutCurrent plays music 0x8be (Globals.c 1902).
- **Routes:** friend route Level+0x10c (loop): (-63000, 0, 75000), (-60000, 0, 110000); enemy route Level+0x110
  (loop, data 0x253b38): (-63000, -5000, 75000), (-60000, -5000, 110000).
- **Spawns (Level.c 6526, disasm c7afc):**

| idx | what | position | flags |
|---|---|---|---|
| 0 | createStaticObject(0x4260 container_003_terran) | moved by the script | setMoving(false) |
| 1 | PlayerFixedObject(0x495d sn_burning_station, Player(7500, 9 999 999)), visual replaced (setShipGroup) by station_076_midorian (0x5254) + emissive 0x5574 + lights_add 0x563c | (-77000, -3000, 90000), rotation (0, pi/2, 0) | intact Luur |
| 2 | same, visual = 0x5254 + 0x5574 + sn_burning_station_fire_intro_anim_add 0x4990 + _alpha 0x4991 | same position/rotation | invisible (burning Luur) |
| 3-10 | createShip(3 Midorian, 0, random Midorian fighter) at route waypoint: i 0,1 friend wp0; 2,3 friend wp1; 4-6 enemy wp1; 7 enemy wp0; all get a clone of the friend route | if -4000 < y < 2000 then y doubled; +0x13a (collision avoidance) = 0 | no hostility |
| 11 | createShip(3, kind 1, ship 15 freighter) | (-63000, -3000, 65000) | moveForward(dt) every frame |

- **LevelScript ctor (384, disasm 15eb1c):** HUD/radar off, player computer-controlled, +0x24 = 1, invulnerable,
  invisible, look-at camera. Target helper +0xcc at enemies[1] position, direction -lightDir, moveForward(-100000),
  translate right * 200000; camera at enemies[1] position translated (10000, 1500, -20000). enemies[0] at
  (-25000, 800, 120000) + lightDir * 1000, facing lightDir, translated (3000, 0, 3000). +0xdc = AEGeometry(0x3795
  projectile_009_anim_add) scaling (1, 1, 500000) (a long beam). Event = 1.
- **Radio:** 0 = 0x9be (2494) "Meanwhile in Midorian space..." p0x11, 5: 2000 ms.
- **Script (LevelScript.c 2473-2647):** every frame camera target +0xcc; while step < 3: camera translate
  (dt*k, 0, 2dt*k), k = 1 - t/35000; +0xcc drifts along -right * 7dt * (1 - t/50000); enemies[11] moveForward(dt).
  - 1: t >= 30001: enemies[0] set to camera position + (0, 500, 0), moveForward(-10000); beam +0xdc anim 3 then 1,
    faces -enemies[0] dir, at enemies[0] -> 2.
  - 2: d = |camera - enemies[0]|; rumble (1 - min(d/7000, 1)) * 100; if d < 200000 enemies[0] moveForward(10dt +
    0.1d); beam follows, anim at half speed. t crossing 38000: sound 0x8c8; from t >= 38001 planets[0] scale x0.95
    per frame; t >= 39001: white fade (-1, 500 ms) -> 3.
  - 3: while fading: planets[0] scale x4 per frame until >= 10, rumble; then StarSystem::switchSunForSupernovaIntro,
    fade in (10000 ms), enemies[2] (burning Luur) visible, all enemies idx >= 3 hitpoints 0 -> 4.
    (enemies[1] is not hidden in the code.)
  - 4: scaleSunDuringSupernovaIntro(dt) + updateSupernova(dt); timer crossing 7000: fade out (0xff, dt+1000);
    timer >= 8000 -> 5.
  - 5: fade done: fill screen, **nextCampaignMission** (-> 0x5a), departStation(station 10 Thynome),
    setAttackedFriends(false), comingFromAlienWorld = 0, module 5 (docked).
- **Objectives:** none; no success dialogue.

---

### Other facts in range

- LevelScript ctor (LevelScript.c 932, disasm 1603c0): for any campaign mission > 0x54 (84) (or 0x87), outside the
  alien orbit, in the orbit of station 103 Coromesk: player position (70000, 0, 100000) (disasm 160402), facing the
  station. Applies to missions 85-89 and later.
- Status::nextCampaignMission for index 0x4f builds Mission(1, 0, 100) (Status.c 1926), confirming the "new index"
  reading of the brief's table.
- ModStation.c has station-side checks for 0x4d, 0x4e, 0x50-0x54, 0x58, 0x59 (not analysed, station side).

### Missions without in-space content (station-side only)

- 71 (0x47), 72 (0x48): no Level case, no radio, LevelScript `case 0x47/0x48: break`.
- 74 (0x4a), 75 (0x4b), 76 (0x4c), 77 (0x4d): no Level case, no radio, no script.
- 82 (0x52) - 86 (0x56): none (82-86 only appear in ModStation checks).
- 88 (0x58): none.

### Not analysed / uncertain

- 0x46: no fail condition found for Trot Lykkt reaching the gate.
- 0x4e player position (not set by Level/LevelScript, assumed default arrival).
- 0x4f end: via Status::missionCompleted case 0xa5 (inferred, not traced through departStation for the alien
  station index).
- 0x50: camera translate y in steps 1/2/7-13, the reference object of the step-11 explosion and the step-12
  hyper_drive position (floats lost, not recovered).
- Level::createShip with a null waypoint (0x4f, 0x51 Void ships): spawn position not checked.

---

# Part 3: campaign missions 90..110 (0x5a..0x6e), in-space content

Sources: Level.c `Level::createCampaignMission` (lines 6653-7317), `Level::createRadioMessages` (13535-13803),
LevelScript.c constructor (0x15e650) and `process` (0x160d50), MGame.c, Status.c, PlayerEgo.c, PlayerFighter.c.
Lost floats were recovered from the Thumb disassembly (addresses given). In `TargetFollowCamera::translate(x,y,z)`
Ghidra often shows the wrong arguments (softfp r1/r2/r3). The values below come from the disassembly.
Game units, ms. "Standard chase reset" = camera at player pos - 2400*playerDir, HUD+radar on, cutscene off
(0x45160000 = 2400, checked at several sites).

## Common mechanisms in this range

- **Mission type 0xb8 = evacuation** (PlayerEgo.c ~4200-4330, dockToDockingPoint ~5935-6025, PlayerFighter.c case 9
  ~2840). Mission statusValue = evacuees still to rescue (the "production goods" amount set in nextCampaignMission),
  Status+0x174 = evacuees on board the player's ship.
  - Docking at an object with **docking type 2** loads evacuees: 1 per 1500 ms while docked, up to
    min(Ship::getMaxPassengers - aboard, statusValue - aboard). No passenger cabins -> hudEvent 0x2b.
  - Docking type **1** unloads: 1 per 1500 ms, aboard--, statusValue--.
  - AI ships on a route unload at a type-1 docking target too: Rhino (ship 0x33 = 51) 1 per 200 ms, other ships
    1 per 1500 ms, while docked for Route::getDockingTime. In mission 0x5e AI unloading stops once statusValue <=
    the player's max passengers, so the player has to bring the last load.
  - `Status::missionCompleted` case 0xb8: done when statusValue == 0. Exception: mission 0x5c never completes
    this way in the normal orbit of station 0x71 (113).
- **Mission type 0xaa** (95, 99, 109): `successCheck` checks it at once, not every 5000 ms. missionCompleted case 0xaa
  means statusValue == 1. The LevelScript "Meanwhile..." drift cutscene sets that value (see mission 95).
- **Gates on planet jumps** (MGame.c ~1410-1450, via Radar::getPlanetDockIndex == target station):
  - mission 0x5e without passenger cabins -> choice window text 0xc8e (3214 "must have sufficient passenger cabins").
  - mission 0x69 without item 0xce (206, Gamma Shield II) -> text 0xc91 (3217).
- **hasSuccessDialogue** (DAT_0025a158[i] > 0) for 90..110:
  90 y, 91 **n**, 92 y, 93 y, 94 y, 95 y, 96 y, 97 y, 98 y, 99 y, 100 **n**, 101 y, 102 y, 103 y, 104 y, 105 **n**,
  106 **n**, 107 n, 108 y, 109 y, 110 y. Missions 91, 105 and 106 advance from the LevelScript. Mission 100
  advances directly in successCheck.
- **Forced travel after a success dialogue closes**. The current index is already advanced when these run.
  - MGame.c ~3315, index 0x5f (after 94): departStation(10 Thynome), switch_to_target 1 -> space level at Thynome
    (mission 95 cutscene).
  - Index 0x60 (after 95): departStation(98 Alioth) in space.
  - Index 100 (after 99): departStation(120 Katashan), module 5 (docked).
  - Index 0x6e (after 109): departStation(10), module 5 + enterSpaceLounge.
  - ModStation::OnTouchEnd ~2538-2556, after a station-side success: index 99 -> depart to 10 (Thynome orbit,
    mission 99 cutscene); index 0x6d -> depart to 0x72 (114 Midantha orbit, mission 109 cutscene).
- Races: 0 Terran, 2 Nivelian, 3 Midorian, 8 pirate, 10 = "???" stealth fighters. Ship 44 is the Specter; race 10
  ships cloak and use combat music 149/150.

---

### Mission 91 (0x5b) - Valpatro: rescue 10 survivors from the damaged freighter

- **Orbit:** station 110 Valpatro (Ginoya, supernova system). Type 0xb8 with 10 evacuees (nextCampaignMission case
  0x5a).
- **Player start** (LevelScript ctor 0x1601ae, not the alien orbit, station == target): setPosition(0, 0, -130000)
  (0xc7fde800), facing the origin (normalize(-pos)), up (0,1,0). Generic arrival camera.
- **Spawns** (Level 6653):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createStaticObject mesh 0x494e (sn_cargo_001_midorian_wrecked; geometry root 0x4a80 `_wrecked_anim` + 0x4a81..0x4a84 glow/lights) | Waypoint (-20000, 0, 60000), jitter off, then set exactly to the waypoint | not moving; docking type 0; setAlwaysFriend; hitpoints = default/20 (default = 5*(4*campaign + min(15*level+100, 400)) +- difficulty, race 3); setRotation(0, 5.4978 (7pi/4), 0); **setActive(false)**; route removed |

- **Radio** (13535):

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0x9c8 (2504) "this is bad, tanning salon" | 0 | time 1500 |
| 1 | 0x9c9 (2505) gamma rays off the scale | 0 | after #0 |
| 2 | 0x9ca (2506) station obliterated, anyone read me? | 0 | after #1 |
| 3 | 0x9cb (2507) "we're here, dock fast" | 0x3c | after #2 |
| 4 | 0x9cc (2508) "on my way" | 0 | after #3 |
| 5 | 0x9cd (2509) "everyone get on board" | 0 | script event 2 |
| 6 | 0x9ce (2510) last one, injured to Tadram | 0x3c | script event 4 |

- **Script** (process 9556-9762):
  - ev0: radio #3 triggered -> wreck setActive(true), docking target 0 renamed 0xc8b (3211 "Damaged Freighter")
    -> ev1.
  - ev1: player docked (isDockedToDockingPoint) -> ev2.
  - ev2: radio #5 over -> wreck docking type 2 (pickup); if already docked setDockingState(2) -> ev3.
  - ev3: Status+0x174 (aboard) >= 10 -> ev4, the fail objective is deleted.
  - ev4: radio #6 over and player undocked -> ev5.
  - ev5 (after 3000 ms): autopilot off, cutscene (HUD/radar off, computer controlled, no collision). The player faces
    away from the wreck (normalize(playerPos - wreckPos)). Look-at camera at player + dir*10000 + right*700
    (0x168354). **Wreck hitpoints set to 0 (it explodes)** -> ev6.
  - ev6: after 2000 ms the speed is multiplied by 1.05 every frame while < 100. After 8000 ms: save
    hull/shield/armor/gamma, nextCampaignMission, setStation + departStation(0x71 = 113 Tadram),
    initStreamOutPosition = 1, module 2 (new space level, mission 92).
  - Every frame: FMOD 3D event 0x8e9 (2281, unmapped) is kept at the wreck position. When aboard >= 8 and level time
    > 179999 ms: sound 0x8ea (2282) plays once and the wreck animates its second transform (AEGeometry+0xc
    instead of +0x14). Probably the break-up animation (unverified).
- **Objectives:** fail = Objective(1, 0) enemy 0 (wreck) dead, removed at ev3. No win objective and no success
  dialogue: the script advances.

### Mission 92 (0x5c) - Tadram: hand the evacuees to the freighter, first stealth fighter attack

- **Orbit:** station 113 Tadram, type 0xb8 with 10 (set when the script turns it into type 4). Arrives from 91's
  script jump.
- **Player start** (ctor 0x160202): setPosition(0, 0, 200000) (0x48435000), facing enemy[3] (the freighter).
- **Spawns** (Level 6697). Enemy route: 3 waypoints (r-70000, 0, -70000), (r-70000, 0, -100000),
  (r-70000, 0, -140000) with r = nextInt(140000) per waypoint.

| idx | what | position | notes |
|---|---|---|---|
| 0-2 | createShip(race 10, kind 0, ship 44 Specter) | random enemy-route waypoint (+ createShip jitter) | setToSleep, always enemy, AI disabled, cloaking disabled |
| 3 | createStaticObject 0x4299 cargo_001_midorian | (80000, 0, 110000) | not moving, always friend, docking type 1 (drop-off), name 0xc89 (3209 "Freighter"), route removed |

- **Radio** (13567):

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0x9d1 (2513) Tadram unstable, no docking | 0x3b | time 1500 |
| 1 | 0x9d2 (2514) 10 Midorians on board, leave them on freighter? | 0 | after #0 |
| 2 | 0x9d3 (2515) yes, be quick, departing to Talidor | 0x3b | after #1 |
| 3 | 0x9d4 (2516) radiation, must dock | 0 | after #2 |
| 4 | 0x9d5 (2517) we've got company | 0 | event 2 |
| 5 | 0x9d6 (2518) never seen ships like these | 0 | after #4 |
| 6 | 0x9d7 (2519) where did they go, cloaking? | 0 | event 6 |
| 7 | 0x9d8 (2520) handle them so the freighter escapes | 0 | after #6 |
| 8 | 0x9d9 (2521) last of them, safe journey | 0 | all of enemies 0..2 dead (type 9, count 3) |
| 9 | 0x9da (2522) well done, over and out | 0x3b | event 10 |

- **Script** (process 5640-6166):
  - ev0: radio #2 triggered -> ev1.
  - ev1: Status+0x174 == 0 (all unloaded) -> mission type set to 4. Specters teleported relative to the freighter:
    0 at (-76000, 5000, 5000), 1 at (-79000, 4900, 7500), 2 at (-79000, 4900, 2500). All face (1,0,0), state 3,
    +0x124 = 0, activated, visible. Cutscene: look-at camera on Specter 0 at its pos + dir*7000 + right*700 + up*300
    (0x163986). The freighter gets docking type 0 and an empty name -> ev2.
  - ev2: Specters fly forward at 2.0 / 2.08 / 2.05 u/ms until radio #5 triggered. Then the camera is placed at
    Specter0 + dir*3900 + right*500 + up*400 -> ev3.
  - ev3: speeds 2.0 / 2.3 / 2.2. Fixed camera drifting dir*1.7dt, right*-0.03dt, up tiny. Radio #5 over -> all three
    setCloakingPossible + cloak(18000 ms) -> ev4.
  - ev4: same motion for 2000 ms -> ev5.
  - ev5: speeds 6.0 / 4.6 / 4.4 for 2000 ms. Then AI on, state 4, +0x124 = 50000. Camera back (look-behind if
    docked), HUD on -> ev6.
  - ev6: 3000 ms -> ev7.
  - ev7: radio #8 triggered -> player undocked if docked, cutscene, player invulnerable and computer controlled.
    Camera at player + dir*7000 + right*700 (0x1690aa) -> ev8.
  - ev8: freighter moves forward 2 u/ms for 8000 ms. Then the camera goes to the freighter: pos + dir*10000 +
    right*4800 (0x16c394) -> ev9.
  - ev9/10: 3D sound 0x8c9 (2249) on the freighter. Its speed grows by 0.006*dt per frame. After 2000 ms ev9 -> ev10.
    After 7000 ms: standard chase reset, controls and vulnerability back, freighter inactive and invisible -> ev11.
  - ev11: freighter keeps accelerating (0.02/ms), invisible.
- **Objectives:** win = Objective(0x16) last radio (#9) over. Fail = Objective(1, 3), freighter dead. Ends with a
  success dialogue (92 -> 14).

### Mission 93 (0x5d) - station-side only
Type 0xb, target 114 Midantha. No Level case, no radio, no script.

### Mission 94 (0x5e) - Luur: evacuate the burning station

- **Orbit:** station 111 Luur (Ginoya). Type 0xb8 with **83 evacuees** (0x53). The player also gets cargo item 205.
  A planet jump there needs passenger cabins (0xc8e).
- **Player start:** generic arrival (no special ctor block).
- **Spawns** (Level 6769). Enemy route: 1 waypoint (-700000, 0, -700000).

| idx | what | position | notes |
|---|---|---|---|
| 0-5 | Specter (race 10, ship 44) | enemy waypoint + jitter (far away) | setToSleep, always enemy |
| 6 | createStaticObject 0x495d sn_burning_station (children 0x5254, 0x5574, 0x563c, 0x495d x2, 0x495e emissive, 0x495f fire anim, 0x4960) | Waypoint null -> (0, 0, 0) | not moving, docking type 2 (pickup), name 0xc88 (3208 "Station Platform"), always friend, rotate(0, -2.356 (-3pi/4), 0), 9999999 hp |
| 7 | 0x4299 cargo_001_midorian | (30000, -5000, 40000) | not moving, docking type 1 (drop-off), name 0xc89 "Freighter", always friend |
| 8, 9 | createShip(race 3, kind 0, getRandomEnemyFighter(3)) = Midorian shuttles | route wp0 | looping route: station(obj) -> (20000, -3000, 30000) -> freighter(obj), docking time 12000 ms at each end; always friend, never attack; second ship on a clone of the route |

- **Radio** (13607):

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0x9ed (2541) Maxwell hailing, sent by Bargand Surr | 0 | 1500 ms |
| 1 | 0x9ee (2542) Captain Squand, get crew onto freighter | 0x3b | after #0 |
| 2 | 0x9ef (2543) on the task | 0 | after #1 |
| 3 | 0x9f0 (2544) these guys again | 0 | event 1 |
| 4 | 0x9f1 (2545) rescue operation, turn around | 0 | after #3 |
| 5 | 0x9f2 (2546) no answer, they asked for it | 0 | after #4 |

- **Script** (process 6167-6348):
  - ev0: aboard > 6 or level time > 60000 ms -> Specters 0 and 1 set to (50000, 1000, 140000) and
    (53000, 1000, 140000), facing (0,0,-1), activated, visible, AI off. Cutscene: look-at camera on Specter 0 from
    pos + dir*8000 + right*1200 + up*-300 (0x163412) -> ev1.
  - ev1: both fly 3 u/ms for 6000 ms. Then AI on, camera back (look-behind if docked), HUD on, FModSound::stop ->
    ev2.
  - ev2: after 100000 ms Specters 2 and 3 appear at player + (-40000, 3000, 20000) and (-43000, 3000, 20000),
    active and visible -> ev3.
  - ev3: after another 100000 ms Specters 4 and 5 appear at the same offsets -> ev4 (nothing more).
- **Objectives:** fail = Objective(1, 7) freighter dead. There is no Level win objective: the mission completes via
  missionCompleted 0xb8 when all 83 are delivered. The shuttles deliver 1 per 1500 ms of docking but stop while
  statusValue <= the player's cabin count. Success dialogue (94 -> 14). Afterwards MGame sends the player to
  Thynome's orbit for mission 95.

### Mission 95 (0x5f) - "Meanwhile, back on Thynome station..." (cinematic, type 0xaa)

- **Orbit:** Thynome (station 10). Reached by the forced depart after 94's dialogue. The ctor block does not check
  the station.
- **Player start** (ctor ~0x15f852, shared by 0x5f / 99 / 0x6d, also 0x77 / 0x7e / 0x85 / 0xa0 / 0xa1): HUD and
  radar hidden, cutscene, computer controlled, player+0x24 = 1, invulnerable, **invisible**, engine sound stopped,
  +0x21 = 1. Look-at camera at (-15000, 800, 75000) (0x15f8b6). Player setPosition(0, 0, 0), so the camera looks at
  the station. LOD forceUpdate.
- **Spawns:** none.
- **Radio:** #0 0x9fb (2555) "Meanwhile, back on Thynome station...", portrait 0x11, trigger = script event 1.
- **Script** (process ~2309-2352, disasm 0x162316): every frame translate(x = +dt, 0, z = -2dt).
  - ev0: 2000 ms -> ev1.
  - ev1: radio #0 over -> ev2.
  - ev2: after 2000 ms -> Mission::setStatusValue(1).
- **Objectives:** type 0xaa completes on statusValue 1 at once. Success dialogue (95 -> 32). Afterwards MGame
  departs to 98 Alioth in space (index 0x60).

### Mission 96 (0x60) - station-side only
Type 0xb, target 98 Alioth. No Level case or script.

### Mission 97 (0x61) - Genoh: pirate attack on the Nivelians

- **Orbit:** station 85 Genoh (Nesla). Type 4. Generic arrival.
- **Spawns** (Level 6901). Route: 1 waypoint (0, 0, 50000); all ships spawn there with createShip jitter.
  N = 8 on `Globals::isRunningHDonWeakDevice`, else 12.

| idx | what | notes |
|---|---|---|
| 0..N-1 | createShip(8, 0, getRandomEnemyFighter(8)) pirates | always enemy |
| N..10 (weak) / N..15 | createShip(2, 0, getRandomEnemyFighter(2)) Nivelian fighters (3 or 4) | always friend |
| 16..18 (not weak only) | createShip(2, kind 1, ship 15 freighter) | not moving, always friend |

- **Radio:** #0 0xa16 (2582) Maxwell here to meet Trunt Harval, 1500 ms, portrait 0. #1 0xa17 (2583) "indisposed,
  pirate attacks", portrait 0x16, after #0. #2 0xa18 (2584) "should lend a hand", after #1.
- **Script:** none.
- **Objectives:** win = Objective(0x12, 0, N), all pirates dead. Success dialogue (97 -> 6).

### Mission 98 (0x62) - station-side only
Type 0xb, target 120 Katashan. ModStation sets its space-lounge flag at station 0x78 for 98/100. After its success
dialogue, index 99 departs to Thynome's orbit.

### Mission 99 (0x63) - "Meanwhile back on Thynome station..." (cinematic, type 0xaa)
Same as 95: same ctor block, camera drift and statusValue = 1. Radio #0 0xa28 (2600), portrait 0x11, event 1.
Success dialogue (99 -> 24). Then MGame docks the player at 120 Katashan (module 5).

### Mission 100 (0x64) - Alioth: stealth fighters ambush

- **Orbit:** 98 Alioth, type 4, generic arrival.
- **Spawns** (Level 6969). Level+0x18c = player pos + (s1*r1 + 20000, s2*r2 + 10000, s3*r3 + 20000), with
  r = nextInt(50000) and s = +-1 each. One-waypoint route there.

| idx | what | notes |
|---|---|---|
| 0, 1 | Specter (race 10, ship 44) at that waypoint + createShip jitter | always enemy, awake |

- **Radio:** #0 0xa35 (2613) stealth fighters gunning for me, 1500 ms. #1 0xa36 (2614) "thought they only loot
  evacuation ships", after #0.
- **Objectives:** win = Objective(4, 1): radio #1 over. The fight is not required. No success dialogue, so
  successCheck calls nextCampaignMission directly (within 5000 ms) and clears the mission. The Specters stay.

### Mission 101 (0x65) - station-side only
Type 0xb, target 98.

### Mission 102 (0x66) - Tadram: protect the dropships during the carrier evacuation

- **Orbit:** 113 Tadram, type 0xb8 with **1700 evacuees** (0x6a4). The player also gets cargo item 207.
- **Player start** (ctor 0x1602c0): setPosition(90000, 6000, 150000), facing the origin.
- **Routes:**
  - enemy route (Level+0x110): (r-70000, 0, -70000), (r-70000, 0, -100000), (r-70000, 0, -140000).
  - friend route (Level+0x10c): (r-70000, 0, -20000), (r-70000, 0, -500000), (r-70000, 0, -70000). Decoded from
    the packed locals; apparently unused by the ships.
- **Spawns** (Level 7024):

| idx | what | position | notes |
|---|---|---|---|
| 0 | createStaticObject 0x4974 sn_carrier_terran_1 (+0x4975..0x497a) | (-50000, 1000, 70000), set exactly after jitter | not moving, +0x6c = 0, docking type 1 (drop-off), always friend, 9999999 hp, +0x70 = 1, route removed |
| 1 | createStaticObject 0x5279 sn_station_113_midorian (damaged Tadram) | setPosition(0, 0, 0) (0xc8bac) | not moving, docking type 0, always friend, 9999999 hp, rotate(0, pi, 0), **setActive(false)** |
| 2-5 | createShip(0, 0, ship 51 Rhino) dropships | carrier + (10000, 6000, -20000), then (30000, 8000, -35000), (35000, 8000, -40000), (40000, 8000, -45000) | always friend, +0x139 = 0. Looping route: carrier(obj) -> (-30000, 1000, 40000) -> station(obj); docking times 20000 / 0 / 20000 ms (table 0x253ba8 / 0x253bd0); ships 3-5 on clones |
| 6-9 | Specter (race 10, ship 44) | spawned at the friend waypoint, moved to (1e6, 1e6, 1e6) | setToSleep, always enemy |

- **Radio** (13691):

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0xa41 (2625) evacuations have begun | 0x12 | 8000 ms |
| 1 | 0xa42 (2626) dropships carry evacuees to the carrier | 0x12 | after #0 |
| 2 | 0xa43 (2627) repair beam hint | 0x12 | after #1 |
| 3 | 0xa44 (2628) here they come, protect dropships | 0x12 | event 3 |
| 4 | 0xa45 (2629) lost the first dropship | 0 | 1 dead among enemies 2..5 (0x1e) |
| 5 | 0xa46 (2630) there goes another | 0 | 2 dead |
| 6 | 0xa47 (2631) only one left | 0 | 3 dead |
| 7 | 0xa48 (2632) everyone on board, carrier prepare to jump | 0x12 | event 5 |
| 8 | 0xa49 (2633) safe now, time to jump | 0 | event 7 |

- **Script** (process 6349-6903):
  - ev0: radio #0 triggered -> cutscene. Player frozen, invisible and invulnerable. Look-at camera on the carrier
    from carrier + (9000, -7000, 40000). FModSound::stop, then play 0x8c0 (2240) -> ev1.
  - ev1: translate(0.6dt, 0.8dt, -2.5dt) (0x1675b4). Once radio #2 is over: 2000 ms, then player back, standard
    chase reset, play 0x8c1 (2241) -> ev2.
  - ev2: after 30000 ms the Specters wake up:
    - first at carrier + (-82000, 2000, 0), cloak(1000, true); second at the first + (-2000, -800, -2000), cloak;
      the others at player + (+-(35000+rnd10000), rnd10000-5000, +-(35000+rnd10000)).
    - Each: setEnemies(null), setEnemy = a random dropship (2..5) or the player (1 in 5), activated, facing (1,0,0),
      AI off.
    - The Rhinos get setEnemies([carrier, station]) (purpose unclear).
    - Cutscene: player frozen/invisible, camera on the first Specter from pos + dir*4500 + right*600 + up*400
      (0x1696ca) -> ev3.
  - ev3: lead Specter flies 2.3 u/ms, the others 2.2 (0x1697a4). Fixed camera drifting dir*2.04dt, right*0.04dt.
    After 10000 ms: AI on, player back, standard chase reset -> ev4.
  - ev4: every 60000 ms dead Specters are revived (vtable 0x18) and re-placed at player + (+-35000..45000,
    -5000..5000, +-35000..45000). A Specter whose target died retargets the first living dropship, else the
    player. When statusValue < 10: type set to 4, cutscene on the carrier from carrier + (9000, -7000, 40000);
    enemies 2..9 moved to (1e6, 1e6, 1e6), inactive and invisible -> ev5.
  - ev5: carrier forward 6 u/ms; camera translate(0.4dt, 0.1dt, -1.8dt) (0x169998); 3D sound 0x8ca (2250) on the
    carrier; 8000 ms -> ev6.
  - ev6: carrier forward 200 u/ms (jump out). After 4000 ms: player back, standard chase reset -> ev7.
- **Objectives:** win = Objective(4, 8) radio #8 over. Fail = Objective(0x12, 2, 6), all dropships dead. Success
  dialogue (102 -> 12). Each Rhino trip delivers ~100 evacuees (20000 ms docked at 1 per 200 ms), so about 17
  trips.

### Missions 103 (0x67), 104 (0x68) - station-side only
103: type 0xb target 10. 104: 0xa6 target 10.

### Mission 105 (0x69) - Naneroh supernova orbit: fire the reverse-matter bomb into the supernova

- **Orbit:** station 109 Naneroh, `Status::inSupernovaOrbit`. Type 4. The planet jump needs a Gamma Shield II
  (item 206).
- **Player start** (ctor 0x15ed8a, mission 0x69 and supernova orbit):
  - HUD and radar hidden, cutscene, computer controlled, no collision, +0x20 = 0x100.
  - Look-at camera on the player: first placed at enemy[1] + (5000, 1500, -20000) (0x15ee0e), then overwritten
    with player pos - 2400*dir + 500*up (0x15ee56 / 0x15ee84).
  - setVulnerable(true); setAutoPilotToProgrammedStation unless instant jump. Event = 1.
- **Spawns** (Level 7201). Enemy route: 1 waypoint (7000000, 7000000, 7000000).

| idx | what | position | notes |
|---|---|---|---|
| 0, 1 | createShip(0, 0, ship 37 Cronus) escorts | player + right*(+2100 / -2100) + dir*2000 (0xc935c/0xc9360) | always friend, face lightDir, route = clone of the player route, setEnemies(null), +0x139 = 0, AI disabled |
| 2-4 | Specter (race 10, ship 44) | enemy waypoint + jitter (far) | setToSleep, always enemy |

  Player: faces normalize(StarSystem::getLightDirection) with up (0,1,0). Player route (HUD marker) = one waypoint
  (650000*light.x, 0, 650000*light.z) (0xc8f80).
- **Radio** (13727):

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0xa61 (2657) exciting spectacle | 0x14 | time 0 |
| 1 | 0xa62 (2658) as far as the gamma rays allow us | 0x3d | event 2 |
| 2 | 0xa63 (2659) just need to get near enough | 0 | event 5 |
| 3 | 0xa64 (2660) controlled supernova implosion | 0x14 | event 6 |
| 4 | 0xa65 (2661) let's see what happens first | 0 | after #3 |
| 5 | 0xa66 (2662) stealth fighters this close | 0 | event 7 |
| 6 | 0xa67 (2663) the bullies, have at them | 0x14 | after #5 |
| 7 | 0xa68 (2664) eyes hurting | 0 | event 9 |
| 8 | 0xa69 (2665) bombs away | 0 | event 10 |

- **Script** (process 7180-7865):
  - ev < 3: both escorts move forward 2 u/ms per frame. ev < 5: cutscene flag held.
  - ev1: camera translate = (6.08*playerDir + 0.2*playerRight) * 0.4 * dt (0x163b78) for 13000 ms -> ev2.
  - ev2: the same vector * 0.9. Radio #1 over -> escorts get routes to absolute points 900000*(right - dir) and
    (-900000*dir - 900000*right). The second point's z uses -90000 (typo in the original, 0x16aac2). Escort AI on,
    +0x128 = 1 -> ev3.
  - ev3: vector * 0.4 for 3000 ms -> ev4.
  - ev4: vector * 0.1 for 3000 ms, then player control back, HUD on, escorts +0x70 = 1 -> ev5.
  - ev5: after 10000 ms escorts deactivated and hidden (setActive + vtable 0x1c(0); bool not checked) -> ev6.
  - ev6: after 24000 ms the Specters wake up:
    - activated, AI off, cloak(1000, true).
    - S2 at (player.x + light.x*100000, **0**, player.z + light.z*100000), facing -lightDir.
    - S3 = S2 + right*2200 - up*200 - dir*2200; S4 = S2 - right*2200 + up*200 - dir*2200.
    - All three then translated by right*-30000.
    - Cutscene: player frozen/invisible, camera on S2 from pos + dir*6800 + right*1200 + up*400 (0x16b1a2) -> ev7.
  - ev7: S2 2.5, S3 2.4, S4 2.3 u/ms. Fixed camera drifting dir*1.96dt, right*0.03dt. After 10000 ms: AI on, player
    back, standard chase reset -> ev8.
  - ev8: 60000 ms -> ev9.
  - ev9: every 110000 ms dead Specters are revived at player + light*100000 + (10000 + 5000k + rnd1000, rnd1000,
    rnd1000), facing -light, then shifted along right. When the player (alive) reaches route waypoint 0 (650000
    toward the light): invulnerable, stopBoost -> ev10.
  - ev10: radio #7 over -> cutscene, computer controlled, player faces lightDir. Camera at player + dir*8000 +
    right*1000 + up*1000 (0x16b652) -> ev11.
  - ev11: after 2500 ms the bomb is spawned: AEGeometry mesh 0x37a7 (14247) at the player position, player
    direction. It flies 13 u/ms and the camera targets it. Sound 0xe (14) plays with 3D attributes.
    - At 9000 ms: sound 0x8c8 (2248) once.
    - From 9000 ms: planet[0] (the sun) scale *= 0.95 per frame (implosion).
    - At 10000 ms: fade out 500 ms -> ev12.
  - ev12: planet[0] scale *= 4 per frame, rumble 50. All race-10 ships get initPush(playerPos, 100000) (vtable
    0x2c). Once the fade ends: fade in 2000 ms, camera targets the player, player turned around (dir = -dir), bomb
    deleted, `StarSystem::switchSunForSupernovaExpansion` -> ev13.
  - ev13: PlayerEgo::rotate(dt/800 on all axes), forward 12 u/ms, rumble 50. After 6000 ms: save
    hull/shield/armor/gamma, nextCampaignMission, setStation + departStation(0x6f = 111 Luur), switch_to_target 1,
    module 2 -> mission 106 in Luur's orbit.
- **Objectives:** none in the Level. Only player death fails it. The script advances (no success dialogue).

### Mission 106 (0x6a) - Luur aftermath: the supernova grew; a damaged stealth fighter

- **Orbit:** 111 Luur. Type 4. Arrives from 105's script jump.
- **Player start** (ctor 0x15eeea):
  - setPosition(300000, 0, 300000) (0x48927c00).
  - HUD and radar hidden, computer controlled, player+0x24 = 1, invulnerable.
  - Faces normalize(lightDir), up (0,1,0); engine sound stopped; +0x21 = 1.
  - Look-at camera at player + (2200, 1300, -4000) (0x15efb0). Cutscene, fade in 8000 ms. Event = 1.
- **Spawns** (Level 7278). Route: (-500000, 0, -1700000) -> (-500000, 0, -3700000) (table 0x253bf8).

| idx | what | notes |
|---|---|---|
| 0 | Specter (race 10, ship 44), placed exactly on wp0 | faces (-1,0,0); route = clone; **always friend, not enemy**, hitpoints 1, cloaking disabled |

- **Radio** (13765):

| # | text | portrait | trigger |
|---|---|---|---|
| 0 | 0xa6a (2666) supernova got even bigger | 0 | 1500 ms |
| 1 | 0xa6b (2667) adverse effect, absorbed | 0x14 | after #0 |
| 2 | 0xa6c (2668) obvious error, back to Thynome | 0x14 | after #1 |
| 3 | 0xa6d (2669) stealth fighter, radar damaged | 0 | after #2 |
| 4 | 0xa6e (2670) opportunity to follow him | 0 | after #3 |
| 5 | 0xa6f (2671) on second thoughts, maybe not; back to Thynome | 0 | event 6 |

- **Script** (process ~2317-2470, disasm 0x161eb2): cutscene throughout.
  - ev1: translate(-0.3dt, -0.05dt, 0.1dt) (0x161ece). Radio #2 over -> Specter activated, visible, cloak off, AI
    off -> ev2.
  - ev2: translate(-0.1dt, -0.1dt, 0.4dt) (0x165eac) for 3000 ms. Then the camera targets the Specter from pos +
    dir*8000 + up*500 + right*1000 (0x16541c) -> ev3.
  - ev2-4: the Specter moves forward 1 u/ms per frame.
  - ev3: radio #4 triggered -> ev4.
  - ev4: radio #4 over -> camera fixed, Specter AI on, **Specter hitpoints set to 0 (destroyed)** -> ev5.
  - ev5: 3000 ms -> ev6.
  - ev6: radio #5 over -> save hull/shield/armor/gamma, **nextCampaignMission twice** (106 -> 107 -> 108; 107 has no
    Mission object), setStation + departStation(10 Thynome), initStreamOutPosition = 1, switch_to_target 1,
    module 2.
- **Objectives:** none. The script advances. So index 107 is skipped in practice. The "follow the stealth fighter"
  step from campaign_flow is cancelled here, because the fighter explodes.

### Mission 107 (0x6b) - no content
nextCampaignMission has no Mission for 107, and it is skipped by 106's double advance (see above).

### Mission 108 (0x6c) - station-side only
Type 0xb, target 10. After its station success, ModStation index 0x6d departs to 114 Midantha in space.

### Mission 109 (0x6d) - "Meanwhile in the Midorian sector..." (cinematic, type 0xaa)
Orbit 114 Midantha (after the forced depart). Same ctor block, camera drift and statusValue = 1 as 95. Radio #0
0xa7f (2687), portrait 0x11, event 1. Success dialogue (109 -> 8). Then MGame docks the player at Thynome (module 5,
space lounge).

### Mission 110 (0x6e) - station-side only
Type 0xab target 10. No Level case.

### Mission 90 (0x5a) - station-side only
Type 0xb target 10 (Thynome). No Level case, radio or script.

## Unresolved / uncertain

- AEGeometry+0xc vs +0x14 transform on the 0x5b wreck: probably the break-up animation versus idle (unverified).
- The mission 102 friend route (Level+0x10c) is set, but no ship in the case uses it. Its purpose is unknown.
- The mission 105 escorts' deactivation bool (ev5) and the purpose of the flags +0x128 / +0x70 were not checked.
- Sound ids > 213 (0x8c0, 0x8c1, 0x8c8, 0x8c9, 0x8ca, 0x8e9, 0x8ea) are unmapped. Sound 0xe = 14 (see
  fmod_event_ids.txt).
- The 0x69 ctor translate (5000, 1500, -20000) from enemy[1] is overwritten by the next setPosition (dead code).
