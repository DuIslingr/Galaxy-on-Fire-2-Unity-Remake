# Campaign mission levels, part A (campaign indices 0–50)

What the in-space campaign levels of the first third of the story spawn and script, decoded from the native code.
Units: **game units** (Unity: `(x, y, −z) · 0.05`, see `CLAUDE.md`) and **milliseconds**. Addresses: Ghidra image
base 0x10000. Other agents cover indices 51–110 and 111+; §1 (mechanisms) is shared and written to be reused.

Builds on (not repeated): `npc_traffic_ai.md` (createShip, KIPlayer/PlayerFighter fields and AI, routes, free-flight
traffic), `ship_combat.md` (Player fields, damage, relations), `space_level_setup.md` (level build, landmarks),
`autopilot_travel.md`, `starmap_travel.md`, `weapons.md`.

Sources: `Level::createCampaignMission` 0xc3370, `Level::createRadioMessages` 0xd0574,
`Level::init` 0xbb49c, `Status::nextCampaignMission` 0xb6c98, `Status::departStation` 0xb63e0,
`Status::missionCompleted` 0xb924c, `Objective::achieved` 0xa36fc, `RadioMessage::triggered` 0x17c5d8,
`Radio::update/draw` 0x180380/0x1806b8, `LevelScript::LevelScript` 0x15e650, `LevelScript::process` 0x160d50,
`MGame::successCheck` 0x1b0620, `MGame::gameOverCheck` 0x1b0d04, `MGame::OnUpdate` 0x1ac778 (wormhole),
`MGame::OnTouchEnd` 0x1a98d8 (dialogue close), `MGame::dialogueEvent` 0x1b0498, `DialogueWindow::hasBriefingDialogue /
hasSuccessDialogue` (tables 0x259ed0 / 0x25a158), `Level::connectPlayers` 0xcc330, `Level::assignGuns` 0xcb638.
Lost float constants were recovered from the Thumb disassembly (`Reference/tools/npc/disasm.py`) and the data arrays
the code copies routes from (0x253888 …).

---

## 0. TL;DR

- The campaign is a single counter, **`Status+0x1e8`** (`getCurrentCampaignMission`), plus one `Mission` object
  (campaign slot 0 of `Status+0x194`). `nextCampaignMission` increments the counter and builds the next Mission
  `(type, reward, targetStation)` (§1.1, table §2). The main story is indices 0–44; index 45 = game won
  (`Status::gameWon` = index > 44); 46+ is the Valkyrie add-on (47–50 fall into this document).
- A Mission becomes the **active mission** (`Status+0x190`) in `Status::departStation` when the player enters the
  orbit of its target station (rules per type §1.1). **While a campaign mission is active in an orbit,
  `Level::init` calls `createCampaignMission` instead of `createMission`: no normal traffic spawns, only the
  scripted ships** (none at all for "go there" indices without a case), and `updateMissionOrbit` replaces the
  45 s respawn logic.
- A level = `createCampaignMission` (ships, routes, objectives) + `createRadioMessages` (triggered radio lines) +
  per-index code in `LevelScript` (cutscenes, state machine in `LevelScript+0x1c`). **Win** = `Level+0x28`
  objective or `Status::missionCompleted` (per type) → success dialogue → `nextCampaignMission`. **Fail** =
  `Level+0x2c` objective → failure dialogue → module 1. Some levels end by script instead (direct
  `nextCampaignMission`, wormhole, module switch).
- **The level spawned for index N often keeps running into index N+1**: after a success dialogue the objectives are
  removed, the index increments and `LevelScript` runs the code of N+1 on N's ships and radio list (4→5 pirate
  ambush, 25→26 wormhole reopens, 41→42 the freighter sacrifice and escape, 49→50→51 Vossk turn hostile).
- In-space campaign content in 0–50: **0** prologue battle (Dareius), **1** rescue cutscene, **4/5** mining + pirate
  ambush, **7** pirate trap with Gunant Breh, **14** EMP arrest by the Terran navy, **16** Void raid on Terran
  freighters, **21** EMP the hijacker, **24** Void samples at Sahi → swallowed by the wormhole, **25/26** Void home
  orbit and pursuers, **28/29** wormhole at Dima → probe mission (survive 3 min), **36** pirate-kill contest with
  Errkt, **38** defend Nivelian freighters, **40/41/42** escort Errkt's freighter through the wormhole → destroy the
  Void home world, **48–50** Valkyrie infiltration start. Everything else in 0–50 is a dock/talk/buy step.

---

## 1. Mechanisms (shared)

### 1.1 Campaign index, Mission objects, activation

`Status` fields: `+0x1e8` campaign index; `+0x194` mission list (`[0]` campaign mission, `[1]` freelance mission);
`+0x190` **active mission** (`getMission`, `Mission::empty` when none); `+0x198` current station; `+0x78` the
alien-orbit station (a default `Station`, index −1); `+0x7c` / `+0x80` system / station **"attacked by aliens"**
(= where the wormhole and Void attackers are, `Station::isAttackedByAliens` 0xb3a2c compares `+0x80`); `+0x84`
the station to return to from the alien orbit; `+0x88` departure counter for re-rolling `+0x80`.

`Mission::Mission(type, reward, target)` 0x187cc0: `+0x08` type, `+0x24` reward, `+0x30` target station index
(−1 = none / the alien orbit), `+0x34` target name, `+0x50` campaign flag (`isCampaignMission`), `+0x60` visible.
`isEmpty` = type −1. Status value (`setStatusValue`, `+0x2c`), production goods (`+0x54/+0x58`), won/failed bytes
`+0x00/+0x01`.

`Status::nextCampaignMission` 0xb6c98: `switch(oldIndex)`; each case sets `+0x1e8 = old + 1` and builds the Mission
for the **new** index (so "case k" defines mission k+1). Case 0 additionally makes it the active mission at once
(the prologue → rescue hand-over). `resetGame` creates mission 0 = `(4, 0, 78)` and makes it active.

**Activation** (`Status::departStation(station)`, loop over the mission list; first match becomes `+0x190`):

1. type 0xad (campaign) and the player carries its production good;
2. index < 45, campaign type **0xa1**, `station == Status+0x80` (the attacked station), not the alien orbit;
3. non-empty, `target == station`, type not in {0x96, 0x97, 0x99, 0x9b, 0xa1, 0xa2, 0xa3, 0xa4, 0xa6, 0xa7, 0xa9,
   0xad} (bitmask 0x8b782b over type − 0x96), type ≠ 8 and ≠ 0xe, and (campaign or type ∉ {0xb, 0xd});
4. campaign type **0xa0** and `target != station` (so 0xa0 is active in every orbit).

Also in `departStation`: from index 32 to 44, when the player departs to a station that is neither the campaign
target nor `+0x80`, `+0x88` counts up; at 10 the attacked system/station is re-rolled (random visible system, not
10 or 15, then a random station of it). Index ≥ 45: `+0x7c = +0x80 = −10` (no attack).

**Completion by `Status::missionCompleted(inStation, time)`** (used by ModStation with `inStation = 1` and by
`MGame::successCheck` with 0; `time` = level time):

| Type | Completes when |
|---|---|
| 0 / 0xb | in a station, at the target station (dock there) |
| 4, 0xc, 9, 10, 0x9f, 0xa1, 0xad, 0xaf–0xb7, 0xb9–0xbc | never here (win objective or script only) |
| 8 | in the target station with the production good × amount in cargo |
| 0xd | in station and `Status+0xf0` |
| 0xe | in the agent's station with item 0x73 in cargo |
| 0x96 / 0x97 / 0x99 / 0x9b | a Status counter (`+0x1c4` / `+0x1c0` / `+0x1d0` / `+0x1d4`) ≥ status value |
| 0x98 | an equipped item has index == status value |
| 0x9a | current cargo load ≥ status value (anywhere) |
| 0x9c | **in space**, in the target orbit, level time ≥ 10 001 ms |
| 0x9d | an equipped item has type == status value |
| 0x9e | equipment contains a type-0 item (a weapon) and a sort-10 item |
| 0xa0 | in any station, or in space ≥ 10 001 ms at a station ≠ target |
| 0xbd | in station, an equipped item has sort == status value |
| 0xa2–0xac, 0xb8 | other rules (blueprints, time, production goods…; not needed for 0–50) |

### 1.2 Level build for a campaign orbit

`Level::init` 0xbb49c (level type `+0xc0` = 3, orbit): `createSpace`, `createPlayer`, player position, then
asteroids/gas clouds, then **if the active mission is a non-empty campaign mission → `createCampaignMission`**,
else `createMission` (traffic; see npc_traffic_ai). Then `createStaticObjects`, sentry guns / fighter turrets /
wingmen (skipped for level type 2 at index 0x2b), `assignGuns`, `connectPlayers`, `PlayerEgo::setRoute(Level+0x108)`,
enemies-left counter. Index 1 overrides the player position here (§3.2).

`createCampaignMission` 0xc3370: `switch(index)` for < 0x78 (case table at 0xc340a for 0x24–0x72, inner table at
0xc35a2 for 0–0x1d), separate code for ≥ 0x78. Every path ends with `Level+0x114 = createRadioMessages(index)`.
Indices without a case spawn **nothing** (empty orbit, `Level+0xf8` stays null).

Level fields used by campaign code:

| Offset | Meaning |
|---|---|
| +0x1c | cargo units captured from crates this level (radio trigger 0x16) |
| +0x20 / +0x24 | enemies killed by NPCs / by the player (`enemyDied`, `Player+0x44`) |
| **+0x28** | **win objective** (`checkObjective`) |
| **+0x2c** | **fail objective** (`checkGameOver`) |
| +0xc0 | level type (3 orbit, 2 menu background, 4/0x17 scenes) |
| +0xf0 | PlayerEgo |
| **+0xf8** | ships (`Array<KIPlayer*>`, "enemies" incl. friends); objectives/radio refer to **indices in this array** |
| +0xfc / +0x100 | asteroids / landmarks: [0] station, [1] jumpgate, [2] hidden gate, **[3] wormhole** (`PlayerWormHole`, mesh 0x4262, exists while the game is not won) |
| +0x108 / +0x10c / +0x110 | **player route** (HUD waypoints, `getPlayerRoute`) / friend route / enemy route |
| +0x114 | radio messages (`Array<RadioMessage*>`) |
| +0x118 / +0x11c | enemies left / friends left |
| +0x130 | time limit (only freelance; campaign uses `LevelScript+0`) |
| +0x18c | mission vector (e.g. wormhole position) |

Helpers: `createShip(race, kind, ship, waypoint, …)` (kind 0 fighter, 1 fixed object/freighter; position =
waypoint ± 20 000 per axis; HP `4·campaign + 14·min(level,20) + 20`, kind 1 ×5 (ship 14 ×25), campaign 49–52/56:
270; see npc_traffic_ai §2.4). `Route(int* xyz, nInts)` = nInts/3 waypoints. Vtable calls on ships: +0x0c awake,
+0x18 revive, +0x1c setSpeed, +0x20 translate, +0x28 getPosition, +0x44/+0x48 setPosition(vec / x,y,z), +0x5c
setState. Frequent modifiers: `setToSleep` (state 5, wakes when the player is within ±25 000 per axis or a target
within ±50 000), `setInitActive(false)` (inactive until woken/scripted), `setAlwaysEnemy/Friend`,
`Player::setHitpoints / setMaxHitpoints`, `PlayerFixedObject::setMoving`, loot list `KIPlayer+0x4c = 0` (no loot)
and `+0x48 = 0` (no crate), name `KIPlayer+0x18` (text ID).

`connectPlayers` special cases: in campaign **16, 24, 28 every race-9 (Void) ship gets an enemy list without the
player** (they attack the other NPCs, i.e. the freighters, and ignore the player); in 36 ship 0 (Errkt) does not
list wingmen. `assignGuns`: when the same campaign index has failed 3+ times in a row
(`Globals::lastCampaignMissionFailed/FailCount`, counted in `gameOverCheck`), hostile NPC guns do ×0.7 damage.

### 1.3 Objectives, win and fail

`Objective(type, a[, b], Level*)` 0xa3600/0xa3612: `+0` type, `+4` a, `+8` b, `+0xc` level. `achieved(t)` 0xa36fc
(`t` = `LevelScript+8`, the mission time):

| Type | Achieved when |
|---|---|
| 0 | enemies left == 0 |
| 1 | ship[a] dead |
| 2 | last waypoint of the player route reached (`Waypoint+300`) |
| **3** | **survival: a < t** (`isSurvivalObjective`) |
| 4 | radio message[a] over |
| 5 | friends left == 0 |
| **7** | ships 0 … a−1 all dead |
| 8 | more than a asteroids dead (9, 10: asteroid variants, garbled) |
| 0xb / 0xc | ship[a] mission crate captured (`KIPlayer+0x65`) / lost (`+0x64`) |
| 0xf | ship[a] active |
| 0x10 / 0x11 | all ships have +0x65 / any ship has +0x64 |
| **0x12** | ships a … b−1 all dead |
| 0x13 | friend cargo stolen (`Level+0x13c`) |
| **0x14 / 0x15** | race-8 ships a … b−1 all dead **and** NPC kills < player kills / NPC kills ≥ player kills |
| **0x16** | the **last** radio message is over |
| 0x17 | ship[a] EMP-disabled (`KIPlayer+0x20`) |
| **0x19** | `KIPlayer[a]+0x60` (float) == 0 (set by script) |
| 0x1a | any of ships a … b−1 dead |
| 0x1b | enemies left < a |
| 0x1c / 0x1d | delivered ore / passengers ≥ a |
| 0x1e | ship[a] dying |
| other (0x1f …) | never (placeholder; such levels end by script) |

**Win** (`MGame::successCheck`, only after 5000 ms of level time and not while `MGame+0xd8`): if
`missionCompleted(false, time)` or the win objective → for campaign missions: if
`hasSuccessDialogue(index)` → `DialogueWindow(mission, 1)` (game paused); index > 45 without one →
`nextCampaignMission`, `removeObjectives`, active mission = empty, no dialogue. Index ≤ 45 without a success
dialogue: nothing here (such missions end elsewhere). Special on success: 0x26 → remaining custom-collide ships
(the freighters) get 9 999 999 HP. When the success dialogue closes (`MGame::OnTouchEnd`): reward + bonus credited,
`nextCampaignMission`, then normally `removeObjectives`, active mission = empty, player route removed — **the level
keeps running** with the new index. Hooks there on the new index: 0xf → load station 98 and switch to it; 0x16 →
store hull/shield/armor, `switch_to_target_setting = 0` and switch module (assumed: back to the station; the target
module was not traced); 0x2a → delete both objectives.

**Fail**: `MGame::gameOverCheck` → fail objective achieved → `DialogueWindow(mission, 2)`; closing it for a failed
campaign mission (or index 0x2a) → music 2 and application module 1 (game over / reload flow, not traced further).
Player death: emergency system, else explosion → "Game Over" (text 319), fail counter, reload of the last record.
A `LevelScript+0` time limit > 0 also fails the mission when exceeded, except when the win objective is a survival
objective (index 0x2a always checks it). The HUD shows the remaining time (not for index 0x2a).

Dialogue tables (`DialogueWindow`, pages per index, 0 = none), indices 0–50:

```
briefing: 4 0 10 0 2 0 0 8 0 0 | 0 2 0 0 2 0 4 0 0 0 | 0 4 0 2 8 0 6 0 0 2 | 0 0 2 0 0 0 4 0 2 0 | 0 6 0 0 0 0 0 0 14 0 | 0
success : 0 38 6 10 4 12 2 10 18 22 | 24 26 16 4 0 22 6 34 16 10 | 2 2 20 28 0 6 4 22 0 2 | 10 20 22 18 30 20 4 16 4 20 | 0 10 8 4 8 0 20 32 16 0 | 0
```

The briefing shows in space when the start sequence ends (`MGame::dialogueEvent`, which also resets the mission time
`LevelScript+8`).

### 1.4 Radio messages

`RadioMessage(text, image, trigger, param[, count])` 0x17c4d0 / 0x17c512: `+0` Radio, `+4` Objective (trigger 0xb),
`+8` text ID, `+0xc` **image ID**, `+0x10` trigger, `+0x14` param, `+0x18/+0x1c` ship index list (`param …
param+count−1`), `+0x20` triggered, `+0x21` over, `+0x24` last route index. The 4-argument form is a one-element list
`[param]`.

`Radio::draw(radio, player, t)` (MGame render, only when not paused and the start sequence is over): when no line
is showing, `Radio::update` tests the messages **in array order** and shows the first that triggers. Display:
speaker name = **text 1597 + image** (table below), portrait from `PTR_DAT_0026447c[image]` (image ≥ 10000 =
a Wanted character), alien font for image 0x13 (and 0x38), duration `lines · 2000 + 1500` ms, voice via
`Globals::getDialogueSoundId(text, agent)`. "Over" is set when the display time ends.

Triggers (`RadioMessage::triggered`; `t` = mission time `LevelScript+8`):

| Trigger | Condition |
|---|---|
| 0 | player route current index passed param |
| 1 | any listed ship dead |
| 2 | any listed friendly (`Player+0x5d`) ship dead |
| 3 / 4 | enemies left < 1 / friends left < 1 |
| **5** | **t ≥ param** |
| **6** | radio message[param] triggered (chains lines; each shows after the previous one) |
| 8 | any listed ship (not asteroid) active |
| **9** | all listed ships dead |
| 10 | any listed friendly ship active |
| 0xb | objective achieved |
| 0xc / 0x13 / 0x1f | any listed ship below 1/2 / 1/4 / 3/4 of max HP |
| 0xe / 0x12 | ship[param] mission crate captured / (captured or lost) |
| 0xf | any non-asteroid ship dead |
| **0x10** | any active, non-asteroid ship that is not always-friend |
| 0x11 | (garbled: some ship other than [param] dead) |
| 0x14 | ≥ param non-asteroid ships dead |
| 0x15 | ship[param] EMP-disabled |
| 0x16 | crate cargo captured this level (`Level+0x1c`) ≥ param |
| 0x17 | radar has the station locked |
| 0x18 | ship[param] inactive, not dead, t > 59 999 |
| 0x19 | player route advanced from waypoint 0 and ≥ param live ships |
| 0x1a | ship 0 active and alive and within 5000 of param in z (or x) |
| **0x1b** | **`LevelScript` event (+0x1c) == param** |
| 0x1c | player armor HP < 1 |
| 0x1e | number of dead among ships 2–5 == param |

Speaker names (image → text 1597 + image) used in 0–50: 0 Keith T. Maxwell, 1 Brent Snocom, 2 Gunant Breh,
5 Tommy, 6 Carla, 7 Errkt Uggut, 8 Jean Baffour, 9 Pirate Boss, 10/11 Pirate, 0xe Hijacker, 0xf Computer,
0x11 Story (caption), 0x12 Terran Officer, 0x13 Void (alien font), 0x15 Midorian, 0x3f Vossk.

### 1.5 LevelScript

`LevelScript` fields: `+0` time limit (ms, from `Level::getTimeLimit`; scripts may set it), **`+8/+0xc` mission time**
(64-bit ms, reset by `dialogueEvent` and some scripts), `+0x11` cinematic flag (HUD/controls hidden), `+0x14`
TargetFollowCamera, `+0x18` Level, **`+0x1c` event/state** (`getEvent/setEvent`, radio trigger 0x1b), `+0x20` start
sequence running, `+0x21` start sequence over / cutscene start, `+0x24` start-sequence timer, `+0x28/+0x40` scratch
vectors, `+0x90/+0x94` 64-bit sub-timer, `+0xa8` flag, `+0xac/+0xb0/+0xb4/+0xd8/+0xdc` extra geometries,
`+0xd0` Hud (`Hud+1` = HUD visible), `+0xd4` Radar (`Radar+0x48` = radar on), `+0xe0/+0xe4` particle systems.

Constructor 0x15e650: player invulnerable, no collision, look-at camera; special setups for indices 0 and 1 (§3);
generic 7 s launch/arrival camera otherwise; index 0x30 player position + autopilot (§3.19);
`comingFromAlienWorld` or alien orbit with index < 0x2b → the wormhole (landmark 3) is reset and placed behind the
player and made visible (the portal they came through); index 0x29 in the alien orbit → two particle systems
(0x28, 0x29) on ship 0 and geometries 0x37cd/0x37ce/0x37cf (the destruction animation).

`process(dt)` 0x160d50: index 1 and index 0 first (full cutscene state machines), then the generic start sequence
(for index > 1: after 7000 ms HUD on, vulnerable, collision, programmed-station autopilot), then index 5 / 0x1a
(alien orbit) / 0x32 / 0x33 hooks, then — only while the active mission is a campaign mission (or index 0x2a) — a
per-index block (`< 0x1d`: 0xe, 0x10, 0x15, 0x18; `0x1d–0x28`: 0x1d, 0x28; `== 0x29`; `== 0x2a`; indices
0x2b–0x37 have none).

Common cutscene helper sequence ("enter"): `setTurretMode(false)`, `resetCamera`, `setFreeLookMode(false)`,
`enableFirstPersonCam(false)`, `hideShipForFirstPersonCameraView(false)`, `stopShooting`, `+0x11 = 1`,
`Hud+1 = 0`, `Radar+0x48 = 0`, `setComputerControlled(true)`, `setVulnerable(false)`, camera `setLookAtCam(true)` +
`setTarget` + `setPosition` (often `PlayerEgo+0x24 = 1`, meaning unverified). "Leave" reverses it:
`setLookAtCam(false)`, `setTarget(player)`, `setComputerControlled(false)`, HUD/radar on, `resetCamera`, `+0x11 = 0`,
vulnerable.

### 1.6 Wormhole and the Void home orbit

`MGame::OnUpdate` (end), when `PlayerEgo::isInWormhole`:

- active campaign mission, index < 0x29 and not 0x1d / 0x28 → `nextCampaignMission`, then travel;
  index 0x28 with event > 3 → `nextCampaignMission`, `Level::lastMissionFreighterHitpoints` = ship 0's HP, travel;
  index 0x1d, 0x28 with event ≤ 3, 0x29 → **the player dies** (HP 0);
  index 0x2a → no index change; travel unless in the alien orbit (the script handles it);
- travel: active mission = empty; from the alien orbit → station `Status+0x84`; else `setStation(alien station)`;
  `departStation`, store hull/shield/armor/gamma and the secondary weapon, `initStreamOutPosition = 1`,
  `comingFromAlienWorld = 1`, reload module 2.

`Status+0x80` ("attacked by aliens") is also what the free-flight code uses for Void attackers at that station
(`Level::updateAlienAttackers`, `createMission` raises local fighters to ≥ 2 and moves the Void spawn route to the
wormhole; not repeated here).

### 1.7 Other per-index hooks

- `MGame::OnInitialize` preloads sounds: index < 2 → 0x9c, 0x9d; 0 → 0x8f, 0x9d, 0x9e, 0xa1, 0xa0, 0x9f; 0xe → 0xf;
  0x18 → 0x22; 0x1d → 0xe; 0x29 → 0x9b, 0x99, 0x9a. Index > 1: the player engine sound starts at load.
- Planet jumps are refused (HUD event 0x15) for index < 10 and index 0x30. Index 0x18: jumping to the target planet
  (Sahi) needs a scanner (sort 0xd) and a tractor beam (sort 0x11), else a dialogue (text 532, speaker Carla) and
  the jump is stopped.
- Nag dialogues after 1 h of play without the mission active: index 0x17 (texts 533/534, speaker Tommy), 0x18
  (536/…, Carla).
- Tutorial hints (`Globals::hints`): index < 2 booster (596); 2 mining (1725 after 40 s or when damaged; 617);
  5 dodge (619, once); > 3 asteroid classes (621); > 6 full cargo (636); > 9 planet jump (584).
- `Radar`: no battle music in index 0x10. `PlayerFighter`: no NPC engine sound in index 1; hostile sleepers are
  invisible for index > 1; in index 0x29 Void ships do not use the alien-station patrol route.
- Steering input is ignored in index 0x30 (autopilot cutscene).
- Level type 2 (menu background) at index 0x2b adds two static objects 0x37d0 / 0x37d1 (post-Void-world backdrop).
- Traffic tweaks in `createMission` when the campaign mission is not active: system 15 and index < 16 → +rnd(2)
  local fighters; index > 31 → 8 % chance of a 9-ship Void raid; index 36/37 in system 5 → no local fighters or
  raiders; index 42/43 outside the alien orbit → no raiders or pirate escorts; alien orbit with index 33 → 2 Void
  ships (npc_traffic_ai §2.3).

---

## 2. Campaign table (indices 0–50)

Type meanings: 4 = in-space level (win objective / script); 0xb = dock at the target; 0x9a = cargo ≥ N; 0x9c = be in
the target orbit ≥ 10 s; 0x9e = buy/equip; 0xa0 = transitional (completes on the next dock or 10 s elsewhere);
0xa1 = level at the attacked station; 0xbd = equip sort N; 0x96 = counter +1; 8 = deliver goods; 0xc = level (win
objective). "Level" = `createCampaignMission` has a case (spawns); "script" = `LevelScript` code.

| # | Type | Target | Setup in `nextCampaignMission` | Level / script | Brief / success pages |
|---|---|---|---|---|---|
| 0 | 4 | 78 Var Hastra | `resetGame`: ship 10, active at once | level + script (prologue, special sky) | 4 / 0 |
| 1 | 0xb | 78 | active immediately | level + script (rescue cutscene) | 0 / 38 |
| 2 | 0x9a (10 t) | 78 | | none → empty orbit, mining tutorial hints | 10 / 6 |
| 3 | 0xb | 78 | | – | 0 / 10 |
| 4 | 0x9a (25 t) | 78 | cargo cleared | level (1 sleeping pirate) | 2 / 4 |
| 5 | 0xb | 78 | | script on 4's level (ambush) | 0 / 12 |
| 6 | 0x9e | 78 | all cargo removed | – (equip a weapon + sort-10 item) | 0 / 2 |
| 7 | 4 | 78 | | level (pirate trap, Gunant Breh) | 8 / 10 |
| 8 | 0xb | 78 | equipment/cargo made saleable at list price | – | 0 / 18 |
| 9 | 0xb | 78 | | – | 0 / 22 |
| 10 | 0xb | 79 Kernstal | drill replaced by item 86 IMT Extract 1.3 | – | 0 / 24 |
| 11 | 0xb | 76 Yrdal Gedal | | – | 2 / 26 |
| 12 | 0xb | 79 | | – | 0 / 16 |
| 13 | 0x96 | – | invisible, status = `Status+0x1c4` + 1 | – | 0 / 4 |
| 14 | 4 | 79 | | level + script (EMP arrest) | 2 / 0 |
| 15 | 0xb | 98 Alioth | | – | 0 / 22 |
| 16 | 4 | 98 | | level + script (Void raid) | 4 / 6 |
| 17 | 0xb | 98 | | – | 0 / 34 |
| 18 | 0x9c | 56 Suttnar | player ship race → Terran | – (empty orbit 10 s) | 0 / 16 |
| 19 | 0x9c | 55 Kappa | | – | 0 / 10 |
| 20 | 0xbd (sort 6) | 55 | at Kappa: EMP GL I free, 10 added to stock | – | 0 / 2 |
| 21 | 4 | 55 | | level + script (hijacker; EMP bombs required to launch) | 4 / 2 |
| 22 | 0xb | 55 | | – (after 21's dialogue the game switches module, presumably to the station) | 0 / 20 |
| 23 | 0xb, reward 20 000 | 10 Thynome | system 6 made visible | – | 2 / 28 |
| 24 | 4 | 48 Sahi | attacked station := 48 (system 9) | level + script (samples, wormhole) | 8 / 0 |
| 25 | 0x9c | −1 alien orbit | Alien Remains made unsaleable | level (3 Void) | 0 / 6 |
| 26 | 4 | 48 | attacked station := none | level (2 Void pursuers) + script (alien orbit) | 6 / 4 |
| 27 | 0xb | 10 | | – | 0 / 22 |
| 28 | 4 | 91 Dima | attacked station := 91 (system 18) | level (wormhole) | 0 / 0 |
| 29 | 4 | −1 | | level + script (probe, survive 3 min) | 2 / 2 |
| 30 | 0x9c | 91 | | – | 0 / 10 |
| 31 | 0xb, reward 30 000 | 98 | | – | 0 / 20 |
| 32 | 0xb | 10 | | – | 2 / 22 |
| 33 | 8 (164 Void Crystals ×50) | 10 | | – (2 Void in the alien orbit) | 0 / 18 |
| 34 | 0xb | 30 Nähma | crystals removed, blueprint 85 unlocked | – | 0 / 30 |
| 35 | 0xb | 29 Ga'kkrr | | – | 0 / 20 |
| 36 | 0xc | 27 B'akka | | level (contest with Errkt) | 4 / 4 |
| 37 | 0xa0 (invisible) | 27 | | – | 0 / 16 |
| 38 | 4 | 22 Dekato | | level (Nivelian freighters) | 2 / 4 |
| 39 | 0xb | 30 | | – | 0 / 20 |
| 40 | 0xa1 | (attacked station) | | level + script (freighter to the wormhole) | 0 / 0 |
| 41 | 4 | −1 | | level + script (escort to the mother ship) | 6 / 10 |
| 42 | 0xa0 | −1 | attacked station := −10 (none) | script on 41's level (escape) | 0 / 8 |
| 43 | 0xb | 10 | | – | 0 / 4 |
| 44 | 0xb | 10 | | – | 0 / 8 |
| 45 | empty, invisible | – | +40 000 credits; game won | – | 0 / 0 |
| 46 | (unchanged) | – | index only | – | 0 / 20 |
| 47 | 0xb | 74 Kanado | | – | 0 / 32 |
| 48 | 0xb | 58 B'akrram | ship → 9 H'Soc (race Vossk; old ship kept in `+0x8c`), items 58 D'iol, 83 Hiroto Proscan | level + autopilot cutscene | 14 / 16 |
| 49 | 0x9c | 58 | ship → 41 K'Suukk: 3× item 177 Berger FlaK 9-9, 58, 83, 52 H'Belam | level (friendly Vossk) | 0 / 0 |
| 50 | 0x9c | 62 Makke S'ik | | level (Vossk) + script | 0 / 0 |
| (51) | 0x9c | 25 S'inokk | | its level (0x33) belongs to part B; the 0x32/0x33 script is shared (§3.20) | |

(Station names from `stations.json`; the index is the number in front.)

---

## 3. Levels

Positions are game units in world space unless marked "player +". Ship indices are `Level+0xf8` slots.

### 3.1 Index 0 — prologue "3598 A.D. – Dareius Asteroid Belt" (orbit of station 78)

Level extras: `createSpace` uses sky mesh 0x458b + texture 0x2754 for index 0 (the intro sky), the asteroid field
is centred at (0, 0, 0). `StarSystem::switchPlanetForIntro` / `Level::switchSkyboxForIntro` swap to the normal
Var Hastra backdrop in state 9.

Spawns: 3 pirates (race 8, kind 0): ships **2 Hiro, 23 Azov, 2 Hiro**, all at (50 000, 50 000, 50 000) (moved in
state 1), asleep, always-enemy, no loot/crate, **HP 150**, exhaust hidden. Player: HP 9 999 999 (also
`Status+100`), `Player+0x5e = 1` (NPCs don't shoot at him until the fight starts). No objectives.

Constructor: player at (0, 0, −60 000) facing +Z, computer-controlled, HUD and radar off, look-at camera at
(−1000, −500, −40 000); pirates asleep, invisible, detection range 0, not flagged hostile; fx geometry 0x3ab3 at
`+0xd8` (hyperdrive effect).

Radio (23): [0] 1668 Story, t ≥ 1500 · [1] 1669 · [2] 1670 · [3] 1671 Pirate(10) · [4] 1672 Pirate(11) ·
[5]–[7] 1673–1675 Pirate Boss · [8] 1676 Keith — each chained on the previous (trigger 6) · [9] 1683 when ships 0–2
are all dead · [10] 1684 · [11] 1685 · [12] 1686 Computer · [13] 1687 · [14] 1688 · [15] 1689 · [16] 1690 when
event == 12 · [17] 1691 Computer · [18] 1692 · [19] 1693 Computer · [20] 1694 · [21] 1695 · [22] 1696 Computer
("destination reached … Var Hastra").

Script (`LevelScript+0x1c`):

| State | Runs until | Actions |
|---|---|---|
| 0 | msg 2 over | → player to (18 000, −12 000, −40 000), camera (−12 000, 2000, −500); pirates to (−10 000, 500, 0), (−10 000, −300, −1700), (−10 000, −200, 2000), facing +X, visible |
| 1 | msg 6 over | pirates bob (pulse); → camera targets pirate 0 |
| 2 | msg 7 over ("attack") | music 0x8e; camera drifts (2.2·dt, …, 0.2·dt); → pirates exhaust on, awake, detection 50 000, hostile |
| 3 | msg 8 over | → **player control**, radar on, collision, `Player+0x5e = 0` |
| 4 | msg 10 over (after the kills) | → music 0x8f, cinematic, guns removed, look-at camera |
| 5 | msg 14 triggered | msg 12 over: sounds 0x9d/0x9e/0xa1 (hyperdrive), speed ×0.98 per frame |
| 6 | msg 15 over | rumble ramps over 4000 ms; → fx at the player (anim 3→1), sound 0xa0 |
| 7 | fx anim end | after 2000 ms player hidden; → music 0x8d |
| 8 | 4000 ms | rumble fades over 3000 ms |
| 9 | 1 frame | intro sky/planet switch, player to (0, 0, 0) facing −Z, particles reset |
| 10 | 2000 ms | rumble; → sound 0x9f, fx anim |
| 11 | 2500 ms | → player engine sound 0x9c, smoke, visible, exhaust off, speed 2.0 (drifting wreck) |
| 12 | msg 17 over | slow tumble (dt/3000); msg 16 fires here; → camera player + (−2000, −2000, −5000) |
| 13 | 6000 ms | tumble dt/4000; → camera player + (700, 0, −1700) |
| 14 | 12 000 ms | tumble dt/5000, camera drift; → camera player + (−3000, 3500, −6700) |
| 15 | msg 22 over | fade out 5000 ms |
| 16 | fade done | `nextCampaignMission` (→ 1), reload module 2 (orbit of 78) |

Skip button: `nextCampaignMission`, `setKills(3)`, module 2.

### 3.2 Index 1 — rescue at Var Hastra (cutscene)

Spawn: 1 Midorian **ship 30 Berger CrossXT** at (300, 50, −6000), route (0, 0, −5000) → (0, 0, 0), speed 0,
exhaust hidden, no engine sound. `Level::init` puts the player at (0, 0, −110 000), the constructor then at
(0, 0, 0), rotation (0.462, 0.462, 1.5339) rad, frozen, computer-controlled, exhaust off, no engine sound; camera
(1500, 1600, −3000) looking at the player; fade in 5000 ms; HUD/radar off.

Radio: [0] 1697 Gunant Breh, t ≥ 10 000 · [1] 1698 · [2] 1699 (chained).

Script: every frame the player rotates by ≈ dt·2·2π/65536 (axis args lost), the Midorian ship is kept asleep and
moved forward `dt · 0.2 · min(1, z / −5000)` (slows down toward z = 0), camera drifts 0.1·dt. msg 2 over → fade
out 5000 ms → fill screen, module 5 (station). Docked at 78 the type-0xb mission completes → 38-page success
dialogue. Skip → module 5.

### 3.3 Indices 4 and 5 — mining and the pirate ambush (orbit 78)

Index 4 (cargo ≥ 25 t, e.g. by mining): 1 pirate **ship 2 Hiro** (race 8) at (0, 0, −200 000) ± 20 000,
`setInitActive(false)`, always-enemy, asleep. No radio, no objectives; the type-0x9a rule completes the mission
when the hold reaches 25 t (in space or docked).

Index 5 script (runs on index 4's level after its success dialogue): once (event 0 → 1): ship 0 is moved to
player position + (5000, 0, 30 000) (world axes), rotated (values lost), and woken (vtable +0x0c). `MGame` shows
the dodge hint (619) once in index 5. Mission 5 itself completes on docking at Var Hastra. (If mission 4 is
completed while docked, index 5 completes immediately at the station and this ambush never happens.)

### 3.4 Index 7 — pirate trap with Gunant Breh (orbit 78)

Player route (`+0x108`, HUD waypoints): (−4000, −3000, 80 000) → (10 000, 7000, 160 000).
Spawns: [0]–[2] 3 pirates **ship 2** (race 8) at waypoint 1 (± 20 000 jitter), asleep (they wake when the player
comes within ±25 000). [3] **Gunant Breh** (text 1599): Midorian ship 30 at player + (700, 50, 6000), route =
clone of the player route, HP 9 999 999, always-friend, boost probability 0.
Win: Objective 0x12 (0, 3) = ships 0–2 dead. No fail objective.
Radio: [0] 1756 Gunant Breh when any hostile ship is active (trigger 0x10, i.e. the pirates wake) · [1] 1757 Keith.

### 3.5 Index 14 — ambushed and arrested by the Terran navy (orbit 79 Kernstal)

Enemy route (1 wp): (40 000, 5000, 30 000). Player at (40 000, 0, 120 000).
Spawns (all at the waypoint ± 20 000 unless noted): [0]–[2] race 8 **ship 0** (Betty model); [3]–[4] Terran
**ship 5 Inflict**; [5]–[6] Terran **battleships** (kind 1, ship 14): [5] at wp + (7000, 0, 0),
[6] at wp + (−9000, 2000, 7000). No relation overrides (pirates hostile, Terrans by standing).
Objectives: win 0x1f (never) — ends by script.
Radio: [0] 1820 Terran Officer, t ≥ 10 000 · [1] 1821 Terran Officer when ≥ 1 ship is dead · [2] 1822 Keith ·
[3] 1823 Terran Officer · [4] 1824 Story ("taken to Alioth").
Script: msg 1 triggered (event 0 → 1): ship 0 killed instantly, three particle systems (ids in ship 0
+0x12c/+0x130/+0x134) put on the player and enabled, sound 15 (the EMP hit). msg 1 over (1 → 2): cinematic, HUD/radar
off, `flashScreen(3)`, player computer-controlled, **speed 0**, guns removed, all race-8 ships killed. State 2:
player slowly rotates (dt/10 000). msg 3 over (2 → 3): player hidden, emitters off, the last ship (battleship [6])
starts moving, camera follows it. msg 4 over (3 → 4): timer. 4000 ms later: **`nextCampaignMission` (→ 15),
`departStation(98 Alioth)`, module 5 (docked)**.

### 3.6 Index 16 — Void raid on Terran freighters (orbit 98 Alioth)

Enemy route (1 wp): W = (0, 0, 170 000).
Spawns: [0]–[2] Terran freighters (kind 1, ship 15, race 0), always-friend, not moving, max HP / 3, no loot;
[0] at W with max HP / 6 more, [1] at W + (3000, 2000, −3000), [2] at W + (−9000, −8000, −7000).
[3]–[6] Void **ship 8 VoidX** (race 9), max HP × 10, at W + (rnd(20 000) − 10 000, rnd(20 000) − 10 000, 50 000).
[7]–[9] Terran **ship 5**, always-friend, HP 600, at player + (rnd 4000 − 2000, rnd 3400 − 1700, 2000 + rnd 4000 −
2000). Wormhole (landmark 3) visible at W + (0, 0, 40 000). The Void ignore the player (§1.2). No battle music.
Win: Objective 0x16 (last radio message over). No fail objective.
Radio: [0] 1838 Void (alien text), t ≥ 10 000 · [1] 1839 Keith · [2] 1840 when freighters 0–2 are all dead ·
[3] 1841 Brent Snocom · [4] 1842 Keith.
Script: msg 0 triggered (0 → 1): cinematic, camera looks at freighter 0 from freighter 0 + (6000, 4000, 47 500),
drifting (−dt, …, −3·dt). msg 1 over (1 → 2): control back. After 20 000 ms mission time (2 → 3): wormhole reset
(closed/armed). msg 2 triggered (3 → 4): wormhole opens and is visible; cinematic, camera at wormhole +
(−9000, −4000, −30 000); a route to wormhole + (0, 0, 30 000) is given to every Void ship, placed near the
wormhole (y ± 2000, z − 17 000 … −13 000), facing it, enemy lists cleared (they flee). msg 3 over (4 → 5): Void
ships hidden and removed, wormhole closed. msg 4 over (5 → 6): control back → win.

### 3.7 Index 21 — the hijacker (orbit 55 Kappa)

Launch requires an EMP bomb (items 41–43) equipped (station text 531). Player route: (40 000, −40 000, 120 000) →
(−10 000, 20 000, 190 000).
Spawns (all rotated (0, π, 0), asleep): [1]–[3] **ship 5 Inflict** (race 0 — hostile by script) on the looping
patrol route A = (40 000, −40 000, 120 000); [0] **Hijacker** (text 1611): Terran **ship 17 Ward**, always-enemy,
looping route B = (−10 000, 20 000, 190 000), placed at B + (1000, 0, 2000).
Objectives: win 0x16 (last radio message over); **fail Objective 7 (1) = the hijacker destroyed**.
Radio: [0] 1881 Pirate when a hostile ship is active · [1] 1882 Keith · [2] 1883 Pirate when the player passed
waypoint 0 with ≥ 2 ships alive (trigger 0x19) · [3] 1884 Hijacker when ship 0 is active (awake) · [4] 1885 Hijacker
when **ship 0 is EMP-disabled** (trigger 0x15).
Script (event 0): if any of ships 1–3 is flagged hostile, or when msg 2 triggers, ships 1–3 become always-enemy;
event 1. Win = disable the hijacker with EMP and let the last line play. After the success dialogue the game stores
the hull values and switches module (index 0x16 hook, §1.3; presumably back to the station).

### 3.8 Index 24 — Void samples at Sahi, swallowed by the wormhole (orbit 48)

Planet-jump to Sahi requires scanner + tractor beam (§1.7). Enemy route: (100 000, 0, 0) → (100 000, 0, −30 000).
Spawns: [0]–[2] **Void ship 8** at waypoint 0, route = clone; [3]–[4] Nivelian freighters (kind 1, ship 15,
race 2), not moving, max HP / 3, no loot. Wormhole landmark hidden. The Void ignore the player (§1.2) and attack the
freighters.
Objectives: win 0x1f (never) — the wormhole ends it.
Radio: [0] 1917 Void, t ≥ 12 000 · [1] 1918 Carla · [2] 1919 Keith · [3] 1920 Carla when **≥ 3 cargo units were
collected from crates** (trigger 0x16; Void wrecks drop Alien Remains) · [4] 1921 Carla.
Script: msg 3 triggered (0 → 1): cinematic, player invulnerable, computer-controlled, guns removed, look-at camera;
the wormhole is placed at player position + direction · k (k lost) and all ships' enemy lists are cleared.
msg 4 triggered (1 → 2): wormhole visible, reset(false), open, sound 0x22 (34). State 2: camera rumble 50 %, the
player slowly rotates (dt/5000) and is pulled in → `MGame`: `nextCampaignMission` (→ 25) and travel to the alien
orbit (§1.6).

### 3.9 Indices 25 and 26 — the Void home orbit and the pursuers

Index 25 (alien orbit, type 0x9c → completes after 10 s there): [0]–[2] Void ship 8, each at
(±(20 000 + rnd 80 000), ±(…), ±(…)) (random sign per axis). No objectives.
Radio: [0] 1925 Keith, t ≥ 20 000 · [1] 1926 Carla · [2] 1927 Keith.

Index 26 script **in the alien orbit** (on 25's level after its dialogue): when radio message 1 has triggered
(event 0 → 1) the wormhole (landmark 3) is reset (reopens). Flying into it (no active campaign mission) returns the
player to `Status+0x84`.

Index 26 level (orbit 48 Sahi, type 4): [0]–[1] Void ship 8 spawned **behind the player**: player position −
direction · k (k lost) ± 700 per axis. Win: Objective 7 (2) = both dead. No radio.

### 3.10 Index 28 — the wormhole at Dima (orbit 91)

Wormhole (landmark 3) at (100 000, −50 000, −40 000); `Level+0x18c` = its position; enemy route = that point.
Spawns: [0]–[4] Void ship 8 at the wormhole (± 20 000); [5]–[7] Terran freighters (kind 1, ship 15), not moving,
max HP / 4, no loot. The Void ignore the player (§1.2). No objectives, no script.
Radio: [0] 1944 Keith, t ≥ 20 000 · [1] 1945 Void · [2] 1946 Keith.
Entering the wormhole → `nextCampaignMission` (→ 29) and travel to the alien orbit. (The line 1944 says the
wormhole collapses; any collapse timer would be in `PlayerWormHole`, not traced.)

### 3.11 Index 29 — the probe (alien orbit), survive 3 minutes

Spawns: [0]–[2] Void ship 8 at random (as index 25). No objectives at start.
Radio: [0] 1948 Keith when **the radar has the station locked** (trigger 0x17) · [1] 1949 · [2] 1950 · [3] 1951 ·
[4] 1952 Void, t ≥ 120 000 · [5] 1953 Keith.
Script: msg 0 triggered (0 → 1): cinematic, invulnerable; probe geometry 0x37d2 created at the player, facing his
direction, moving forward 3·dt; camera at player + direction·k + right·k + up·k (k lost) targeting the probe;
sound 14. msg 2 over (1 → 2): control back, probe deleted, **time limit and win objective = 180 000 ms survival**
(Objective 3; the mission time is reset). Entering the wormhole during 29 kills the player (§1.6). Win → 2-page
dialogue → index 30 (be in orbit 91 for 10 s).

### 3.12 Index 36 — pirate-kill contest with Errkt (orbit 27 B'akka, type 0xc)

Mission agent: "Errkt Uggut" (text 1604). Player route (4 wp): (110 000, −10 000, −80 000) →
(70 000, 0, −100 000) → (−100 000, 10 000, −80 000) → (−130 000, −50 000, −150 000).
Spawns: [0] **Errkt**: Vossk **ship 9 H'Soc**, at player + (rnd 1400 − 700, rnd 1400 − 700, 1000), speed 3.0,
`setRotate(3)`, HP 9 999 999, route = clone of the player route, always-friend, name 1604, no loot.
[1]–[7] pirates (a random pirate model each, race 8) at a random waypoint of the route (± 20 000), asleep.
Objectives: **win 0x14 (1, 8)** = all pirates dead **and the player killed more than Errkt** (NPC kills
`Level+0x20` < player kills `Level+0x24`); **fail 0x15 (1, 8)** = all dead and Errkt killed as many or more.
No radio, no script.

### 3.13 Index 38 — defend the Nivelian freighters (orbit 22 Dekato)

Enemy route (1 wp): W = (90 000, 10 000, 80 000).
Spawns: [0]–[1] Nivelian freighters (kind 1, ship 15, race 2), always-friend, not moving, at W ± 10 000;
[2]–[6] Midorian fighters (random Midorian model), always-enemy, at W ± 20 000.
Objectives: **win 0x12 (2, 7)** = all fighters dead; **fail 7 (2)** = both freighters dead. On success the
surviving freighters become indestructible (9 999 999 HP).
Radio: [0] 2029 Midorian, t ≥ 15 000.

### 3.14 Index 40 — Errkt's freighter to the wormhole (the attacked station, type 0xa1)

Plays in the orbit of `Status+0x80` (the station under Void attack; random from index 32 on).
Routes: enemy (1 wp) (−20 000, −3000, 200 000); friend (2 wp) (−20 000, −3000, 35 000) → (−20 000, −3000, 200 000).
Wormhole (landmark 3) at (−20 000, −3000, 200 000). Player (only with `initStreamOutPosition`) at
(−105 000, 0, 80 000), rotation (0, π/2, 0).
Spawns: [0] **Errkt's freighter**: kind 1, **ship 13** (Vossk freighter model), always-friend, name 1604,
**max HP 5·level + 1800**, parked at (−9 999 999)³, asleep, invisible. [1]–[4] Terran fighters (random Terran model),
friend route, always-friend; [2] named **Jean Baffour** (1605). [5]–[8] Void ship 8 at the enemy waypoint,
always-enemy. [9]–[12] Void ship 8 in reserve at (−500 000)³, always-enemy, asleep.
Objectives: **fail 7 (1)** = the freighter destroyed. No win objective.
Radio: [0] 2042 Keith, t ≥ 10 000 · [1] 2043 Jean Baffour · [2] 2044 Keith · [3] 2045 Errkt, t ≥ 40 000 ·
[4] 2046 Keith · [5] 2047 Errkt when the freighter is below 50 % · [6] 2048 Keith when ship 0 is inactive, alive and
t > 60 000 (it went through).
Script: event 0: msg 3 triggered → freighter moving, placed at friend waypoint 0, woken, visible, **race set to 1**,
cinematic camera on it; event 1 (camera drift −2·dt): msg 4 over → control back; event 2: when the freighter's
z ≥ 90 000 → the 4 reserve Void ships are placed around the wormhole (± 10 000) and woken; event 3: when its z ≥ the
wormhole's z; event 4: it keeps moving forward and, once past 500 000, is parked at (0, 0, −200 000) and deactivated
(event 5). Following it into the wormhole with event > 3 → `nextCampaignMission` (→ 41), its HP is carried over,
travel to the alien orbit; entering earlier kills the player.

### 3.15 Index 41 — escort to the Void mother ship (alien orbit)

Player at (3000, 2000, −320 000), rotation 0.
Spawns: [0] Errkt's freighter: kind 1, ship 13, race 1, always-friend, name 1604, moving (+Z at 1 u/ms), at
(0, 0, −300 000), HP = the value saved in index 40 (or 0.7 · (5·level + 1800) if none). [1]–[7] Void ship 8,
always-enemy: (0, 0, −260 000), (−10 000, 10 000, −240 000), (13 000, 2000, −220 000), (−72 000, −4000, −210 000),
(60 000, −40 000, −190 000), (−18 000, 30 000, −160 000), (17 000, 40 000, −140 000). In this index Void ships use
the normal patrol, not the alien-station route.
Objectives: **win 0x19 (0)** = freighter `+0x60` == 0 (set by the script at the end); **fail 7 (1)** = freighter
destroyed.
Radio: [0] 2052 Keith, t ≥ 80 000 · [1] 2053 Errkt · [2] 2054 Keith · [3] 2055 Errkt · [4] 2056 Errkt when the
freighter is near z = −100 000 (trigger 0x1a) · [5] 2057 Errkt · [6] 2063 Keith when **the freighter is dead** ·
[7] 2064 Keith.
Script: msg 4 triggered (0 → 1): cinematic; ships 1–3 revived, targeted at the freighter, state 1, placed at
(−40 000, 500, −30 000), (−41 000, −200, −31 000), (−42 000, 100, −32 000); camera on the freighter.
msg 5 triggered (1 → 2): damage particle systems 0x28/0x29 on, freighter HP 9 999 999, stopped, sound 0x9b, its
engine sound stopped. State 2: the freighter drifts (0, −dt, 2·dt) and rolls (dt · 3e-5) for 15 000 ms (→ 3).
State 3: freighter placed at (2006, −31 500, −86 720), exhaust off, camera; Void ships target the player; → 4.
State 4: after 15 000 ms: sound 0x9c stopped, freighter HP 100, `+0x60 = 0` (→ win), HUD back; state 5.

### 3.16 Index 42 — destroy the freighter and escape (41's level, alien orbit)

After 41's success dialogue the objectives are deleted. The player is expected to destroy the freighter (100 HP):
41's message 6 ("Sorry Errkt…") then 7 play. Script (41's radio list is still loaded): event 5 and msg 7 over →
sound 0x99, mission time reset, objectives deleted, wormhole placed at (25 000, 20 000, −55 000) and opened; event 6:
rumble 50 %, sound parameter; player in the wormhole → cinematic, player hidden, camera on the station geometry,
`freeMissionLock`, wormhole reset, sound 0x9a, event 7: rumble 100 %, the destruction geometries animate (station
hidden after 4000 ms), after 15 000 ms fade out 4000 ms, then (fade done or 10 s) hull/shield/armor/gamma stored,
`setStation(Status+0x84)`, `departStation`, module 2 with `comingFromAlienWorld`. Outside the alien orbit, event 0
just resets the wormhole. Index 42 (type 0xa0) completes 10 s after arriving in a normal orbit → 8-page dialogue.

### 3.17 Index 48 — Valkyrie: arrival at B'akrram (orbit 58)

Spawns: 5 Vossk **ship 9 H'Soc** (race 1), always-friend (not always-enemy), around the origin ± 20 000.
Constructor: player at (0, 0, 55 000), direction nudged by 1e-5, **autopilot to the station** (landmark 0);
`MGame` ignores steering input in index 48 and refuses planet jumps. The type-0xb mission completes on docking.

### 3.18 Index 49 — K'Suukk launch (orbit 58)

Same spawns as 48 (5 friendly H'Soc; NPC HP 270 for campaign 49–52). Radio: [0] 2120 Keith, t ≥ 8000.
Type 0x9c at 58 → completes 10 s after launch; no success dialogue → immediate `nextCampaignMission` (→ 50) and
objectives removed; the 0x32 script does nothing here (needs ≥ 3 radio messages).

### 3.19 Index 50 — detected at Makke S'ik (orbit 62)

Spawns: 4 Vossk ship 9, always-friend, around the origin ± 20 000; `Level+0x18c` = landmark 1 (jumpgate) position,
or (0, 0, 40 000) without a gate (unused in this case; index 51 builds a route from it).
Radio: [0] 2121 Vossk (image 0x3f), t ≥ 8000 · [1] 2122 Keith · [2] 2123 Vossk · [3] 2124 Keith.
Script (shared by 0x32 and 0x33): when ≥ 3 radio messages exist, msg 2 is over and event 0: every non-wingman ship
loses always-friend, becomes always-enemy and `turnEnemy`; `Standing::setStanding(0, 100)` (Terran/Vossk axis to
+100, i.e. Vossk hostile); event 1. Type 0x9c at 62 completes after 10 s, so the index is usually already 51 when
the Vossk turn (the 0x33 branch runs the same code).

---

## 4. Uncertainties and open points

- **Floats lost in the decompile** were recovered for all spawn/route/player positions above; still unrecovered:
  index 4→5 ship rotation, index 1 rotation axes and camera drift, index 24/26/29 offsets `k` (player direction
  multiples), index 14 camera positions, index 40 event-0 camera drift, some cutscene camera translations.
- `Objective` 0x1f (index 14, 24) is not handled by `achieved` → treated as "never"; those levels end by script.
- `setMaxHitpoints` on the freighters (index 16, 24, 28, 38) — whether current HP is clamped as well was not checked.
- Radio trigger 0x11 and Objective types 9/10 are garbled in the decompile.
- Index 42: that the player must shoot Errkt's freighter is inferred from the triggers (message 6 = ship 0 dead
  after the script set its HP to 100 and removed the fail objective) and the lines; no explicit "destroy it"
  objective exists.
- Index 28: a wormhole collapse timer (line 1944) was not found in the script; `PlayerWormHole::update` not traced.
- `PlayerEgo+0x24` (set during cutscenes) and `LevelScript+0x12` meanings are unverified.
- `Status+0x84` (return station from the alien orbit) is assumed to be the station the player entered from; its
  writer was not traced. Type 0x96 counter `Status+0x1c4` (index 13) not identified (likely a freelance/ mission
  counter).
- The failure path after `DialogueWindow(…, 2)` goes to application module 1; what module 1 shows (load game
  screen) is assumed.
- Index 46/47 (Valkyrie start) and how index 46 advances are outside the level code (not traced).
- `updateMissionOrbit` (the per-frame logic replacing `updateOrbit` while a mission is active) was not read.
