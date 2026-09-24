# Wingmen and the Most Wanted board

Research for the remake: hired wingmen (spawn, AI, command menu, contract, death, save) and the Most Wanted bounty
boards (data, activation, movement between orbits, board UI, the encounter in orbit, rewards, the storyline wanteds,
the Quineros ship unlocks). Source: `libgof2hdaa.so` (Android HD), Ghidra image base 0x10000. Text ids index
`Assets/Localization/text_en.json`. Game time in ms, distances in game units. PRIVATE: game data and texts stay local.

Builds on (not repeated here): `freelance_missions.md` §1.4 (wingman offer generation), §3.2-3.3 (the bar chat and
the hire), §6 (a first Wanted summary); `npc_traffic_ai.md` §2.3 (the ship array), §3 (NPC guns), §4 (relations), §5
(the fighter AI); `ship_combat.md` §2.1 (damage), §4.1 (wanted guns), §7 (HUD).
Tool: `Reference/tools/wingmen/wingmen_wanted.py` (`wingman NAME RACE`, `formation`, `wanted [LEVEL] [extreme]`,
`simulate IDX [STEPS] [SEED]`, `medals`, `texts`).

Confidence: **verified** = read in the decompile and checked in the disassembly; unmarked = read in the decompile;
*(inferred)* / *(uncertain)* = interpretation.

---

## 0. Summary

- **Wingmen** (base game, bar offer 6 from campaign 16, never from Vossk agents): the agent + 0-2 friends, one race,
  a 600 000 ms contract. In every normal flight orbit they spawn around the player (max 3), fly a ship picked from
  the race's fighter pool **seeded by the length of their name**, have 600 HP, the race's NPC gun plus a Dia EMP Mk III
  as secondary, and follow a V formation. Commands (HUD action menu → Wingmen, or the "Wingmen" key): Fire at will,
  Attack my target, Secure next waypoint, Use laser / Use EMP blaster. They attack any ship hostile to the player,
  anywhere in the orbit. A dead wingman leaves the contract for good. The contract clock runs only in flight
  (unpaused, ×5 under fast-forward); when it has run out the wingmen **keep flying until the next docking**, where
  they say goodbye (313) and are dismissed. In Challenge missions they are disarmed. Saved with the game.
- **Fans**: with all 36 base medals every wingman agent offers to *pay you* (782-784); hiring adds the costs to your
  credits.
- **Most Wanted** (Supernova add-on content, reached only through campaign index ≥ 128): 25 criminals on 4 race
  boards (Terran from 128, the others from 161/162). On docking at a station of a board's race, entries whose
  campaign step and bounty count are reached become active somewhere along a random gate route; every orbit change
  moves each active wanted one system along its route (it appears at the gate station of each system). The board
  shows only "Departed from" / "Travelling to". In orbit the wanted replaces a local fighter (disguised in the police
  group, speed 4.5, 4× damage gun, big HP) with 0-4 same-race wingmen; locking it with the scanner (or shooting it)
  uncovers it: radio lines, its wingmen turn hostile, music 151. Killing it pays the bounty (50 000-140 000),
  marks it terminated, counts one bounty on its board (unlocking the next entries) and gives no standing penalty.
  Wanted 0/1 (storyline) surrender at 1/3 hull instead, which completes campaign 128 / 130. Killing wanted 6, 12, 18,
  24 puts their ships 45-48 on sale at Quineros (station 107, Loma).

---

## 1. Wingmen

### 1.1 State

| Field | Meaning | Written by |
|---|---|---|
| `Status+0x24` | `Array<String*>` wingman names (agent first, then friends); null = no wingmen (`Status::getWingmen` 0xb9b08 / `setWingmen` 0xb9b0c) | hire, `wingmanDied`, expiry |
| `Status+0x28` | `int[5]` portrait parts of the hiring agent (for the goodbye dialogue) | hire |
| `Status+0x2c` | wingman race (the agent's race: 0, 2, 3 or 4-7; Vossk agents never offer wingmen) | hire |
| `Status+0x30` | contract time left, ms (600 000 at hire) | hire; −dt in `MGame::OnUpdate`; 0 by `setWingmen(null)` and at `nextCampaignMission` case 47 |
| `Status+0xd4` | statistic "Wingmen hired" (567): += friends + 1 per hire; medal 27 | hire |
| `Status+0xf8` | wingman weapon label toggle for the menu (1 = show "Use EMP blaster"); reset to 1 by `resetGame` and in `ModStation::OnInitialize` (station init path) | menu |
| `KIPlayer+0xd8 / +0xdc / +0xe0 / +0xe4` | is wingman / formation slot 0-2 / command / command target | `KIPlayer::setWingman` 0xb2d26 (sets command 1 **without** the side effects of `PlayerFighter::setWingmanCommand`) |

`setWingmen(null)` clears +0x24, +0x28 and +0x30 together.

### 1.2 Hiring (summary; details in freelance_missions.md)

- Offer 6 (`Generator::createAgent` 0xa26c0): friends = `nextInt(3)`, costs `(nextInt(1300)+700)·(friends+1)` (×7
  hardcore). Only the first wingman offer of a bar survives; offer 5/6 turn into missions before campaign 16.
- Offer text (`Globals::getAgentMissionText` 0xfa7d4): `779 + friends` (#C costs, #W first friend); with all medals
  `782 + friends` ("…we'd pay #C for the privilege").
- Accept (`SpaceLounge::onKeyPress` 0x19c6fc): already hired → 785 "You already hired some wingmen."; without all medals
  and credits < costs → 203 "You need an additional #C."; confirm 866 "Hire #Qx backup for #C?" (#Q = friends + 1) or
  867 "Take the fans with you for #C?" (all medals).
- On Yes (verified, 0x19c6fc tail): `Status+0xd4 += friends+1`; `setWingmen(agent names)`; `+0x2c = agent race`;
  `+0x30 = 600000`; `+0x28 = copy of the agent's 5 portrait parts`; credits `+costs` with all medals, else `−costs`.
- Later chats with that agent: 859. The bar visitor stays in the lounge.

### 1.3 The medal condition ("fans")

`Achievements::gotAllMedals` 0x1824c6 = `Achievements+0x20`, computed by `countMedals` 0x182444: the medal array has 45
grades (0 = none, 1 = gold, 2 = silver, 3 = bronze); **all of medals 0-35 non-zero** (any grade) → all medals;
all 36 gold → `gotAllGoldMedals`; + medals 36-44 (Supernova medals) → `gotAllSupernovaMedals`.
Grades come from `Achievements::checkForNewMedal` 0x181ec0 with the threshold table `DAT_00259860[45][3]`
(gold, silver, bronze; `wingmen_wanted.py medals`). Medal 27 "Commanded more than # wingmen." (hint text 1552 + 27):
`Status+0xd4` **>** 20 gold, > 10 silver, > 3 bronze.
Hint 649 ("You have won all the medals! … some will even pay you …") shows once at a station when it happens
(`ModStation::checkHints`, `hints[0x1a]`).

### 1.4 Spawn (`Level::createWingmen` 0xcb338, verified)

Called from `Level::init` 0xbb49c in the flight level (level type 3; not in the cutscene level types 4 and 0x17, not
in type 2 at campaign 0x2b), **after** `createMission` / `createCampaignMission`, `createSentryGuns`,
`createFighterTurrets`; then `assignGuns` and `connectPlayers`. Conditions: not `Status::inSupernovaSystem`, campaign
index ≠ 0x9e (158), wingmen list non-null, a player ship exists. **The contract time is not checked** (expired wingmen
still spawn until docking, §1.8). So they also appear in freelance and story orbits.

Per name i (the list has 1-3 entries):

```
rnd.setSeed(5 * names[i].length)              // AERandom::setSeed(long): String+4 = length in UTF-16 units
ship = Globals::getRandomEnemyFighter(Status+0x2c)   // races 4-7 use the pirate pool (npc_traffic_ai.md §2.5)
k = Level::createShip(race 5, kind 0, ship, waypoint null, true, false)   // race 5 only for the constructor
pos = player.pos + player.right * (-1000, 2000, 0)[i] - player.forward * 2000;  pos.y += (0, 0, 1000)[i]
k.setPosition(pos); k.setDirection(player.forward, up = (0, 1, 0))
k.setWingman(true, slot i)          // command 1
k.alwaysFriend = true
k.setHitpoints(600)                 // raises max to 600 only if the createShip max was lower (Extreme late game: 600 of more)
k.name = names[i];  k.race (+0x24) = Status+0x2c
if level mission type == 0x0c (Challenge): k.armed (+0x21) = false        // no guns at all
append to the level ship array (Level+0xf8), after all other ships
rnd.reset()                          // back to time(NULL)
```

- **Ship model is deterministic**: the seed depends only on the name length, so a wingman flies the same model in
  every orbit (`wingmen_wanted.py wingman "Name" race`). The hull colour/group follows the ship index.
- Spawn offsets (verified constants 0xcb61c..0xcb62c): right −1000 / +2000 / 0, forward −2000 for all, up +1000 for
  the third. (Corrects the uncertainty in npc_traffic_ai.md.)
- **Guns** (`Level::assignGuns` 0xcb638, verified): slot 0 = the normal NPC gun of the wingman race (race item and
  projectile of npc_traffic_ai.md §3, damage by player level, count 4, lifetime 3000, reload `600 − 2·cm`, speed 16);
  slot 1 = `Gun(item 18 Dia EMP Mk III, damage 0, count 4, ammo −1, lifetime 3000, reload 400, speed 16)`, EMP per hit
  = item 18 attr 10 (= 8), friend gun, projectile mesh 0x1a8a (6794 `projectile_018_anim_add`), shot sound 0x4a (74
  `Blaster_EMP_Dia`). Wingmen count double in the gun array size (two guns).
- Engine loop: the `PlayerFighter` constructor picks 46 (48 only if `+0xd8` were already set, which it never is at
  that point) *(inferred: sound 48 `Spaceship_Engine_Wingmen` is effectively unused)*.
- Enemy list (`connectPlayers`): the player first, then **every** other ship including same-race ones.
- Wingmen are left out of the level's enemies-left counter (`Level+0x118`) and of the raider/police respawn
  (`updateOrbit`).

### 1.5 AI (`PlayerFighter::update` 0xf0d90)

Relations every frame: hostile (`Player+0x5c`) = 0, friend (`+0x5d`) = 1 (a wingman ignores the standing). The NPC
friendly-fire rules (npc_traffic_ai.md §4.5) skip wingmen: the player can shoot them without any reaction.

**Formation route** (command 1, verified 0xf1040..0xf11c6): each frame the route (`KIPlayer+0x68`) is replaced by a
one-point looping route at

| slot | point |
|---|---|
| 0 | player − right·4000 − forward·3000 |
| 1 | player + right·4000 − forward·3000 |
| 2 | player + up·2000 − forward·2000 |

(player's own right / up / normalised forward). The normal waypoint rule (reached within ±2000 per axis) applies, so a
wingman at its slot keeps turning around it.

**Targeting** (the §5.3 code of npc_traffic_ai.md with the wingman branches):

```
first part as for any NPC (in-box scan, 5 s re-roll); since hostile == false, idx 0 (player) -> idx 1, attacking = false
command 3: idx = index of the command target if active and not always-friend; dead target -> setWingmanCommand(1)
... the chosen target must be inside the +-50 000 box, else idx = -1
if not command 3 and idx > 0:            // normally true: the player is always in the box
    idx = first ship i >= 1 (active, alive) with Player+0x5c (hostile to the player) or i == command target
          -> attacking                   // no distance limit
if command 1 and not attacking: idx = -1 // back to the formation point
```

So with command 1 ("Fire at will") a wingman attacks **the first hostile ship of the orbit in array order, at any
distance**, and returns to its slot when none is left. Firing, break-off (±8000), steering and bank are the normal
fighter code (turn rate `dt·48/65536`, fire cone ±0.0076, range ±35 000).

**Speed**: base 2.0 u/ms (the player's cruise speed); boost/evasion (`+0x139`) is on after spawn (5 % per 5 s, panic
after losing 40 %) and **switched off for good by the first "Fire at will"** (`setWingmanCommand(1)` clears +0x139 and
the panic flag). Commands 2/3 re-arm the boost timer (5001) but not +0x139. They do not match the player's speed: a
boosting player leaves them behind.

**Launch / arrival camera** (`LevelScript::process`, 7 s): while it runs every wingman is in drift mode (+0x129 = 1, no
steering); cleared when the chase camera takes over.

### 1.6 The wingman menu and commands

**Opening** (all pause the game: `MGame+0x5d`, sounds paused, `Hud::initHudMenu(2)`):
- HUD action menu (`initHudMenu(0)` 0x18e080): entries in this order, each only when available: 266 "Secondary
  weapons" (button 0x200 → submenu 1), **306 "Wingmen"** (0x400 → submenu 2; shown when wingmen exist, not in a
  supernova system, campaign ≠ 158), the cloak item name (0x800), 1359 "Khador Drive" (0x1000). The action menu is
  "empty" (hidden) without secondaries, drive, wingmen and cloak (`Hud::checkIfQuickMenuIsEmpty` 0x18de64).
- Direct key: key table entry 19 **"Wingmen"** (`keys` 0x259008; `keyPressed` 0x725d8 → `Globals::showWingmanMenu`),
  handled in `MGame::OnUpdate`: toggles menu 2 open/closed, ignored while mining or without wingmen. Hints 638 / 639
  name the keys `#KEY_ACTION_MENU` / `#KEY_WINGMEN`; 3358 "Wingmen menu" is the binding label *(inferred)*.

**Menu 2** (`initHudMenu(2)`, title image 0x4f3; verified button ids from the 64-bit constants):

| # | Text | Button | Command sent to every living wingman (`vtable+0x10` = `PlayerFighter::setWingmanCommand` 0xf096c) |
|---|---|---|---|
| 0 | 307 "Fire at will" | 0x20000 | 1: formation + attack hostiles; clears panic and boost/evasion |
| 1 | 308 "Attack my target" | 0x40000 | 3 with `Radar::getLockedEnemy()`; **no lock → ignored** (the old command stays) |
| 2 | 309 "Secure next waypoint" | 0x80000 | 2: needs a player route (else ignored); clones it (`Route::getExactClone`), remembers its current index |
| 3 | 310 "Use laser" / 311 "Use EMP blaster" (311 while `Status+0xf8` = 1) | 0x100000 | toggles `Status+0xf8`, then 0: every wingman toggles its fired slot `+0x13c` (primary ↔ EMP); the command itself stays |

After a command: menu closed, game resumed (`MGame::OnTouchEnd` 0x1a98d8). `setWingmanCommand` also resets the
current speed to the base speed. Commands 2/3 set the target re-roll timer to 5001 (re-target at once) and, if not
boosting at 5.5, the boost timer to 5001.

- **Command 2** each frame: `Route::update` on the clone; while its current index ≤ the remembered start index the
  wingman flies to that waypoint (following-waypoint = no firing); once it is passed the clone is deleted and the
  wingman switches to command 1. So it scouts exactly the next waypoint of the player's route.
- **Command 3**: sticks to the locked ship until it dies (→ command 1). If the target leaves the ±50 000 box the
  wingman holds its last formation point (the route is only refreshed under command 1).
- Label quirk: `Status+0xf8` is reset to 1 on every station visit but wingmen spawn with slot 0 (laser) in every
  orbit, so after toggling in one orbit and jumping to the next without docking the label is inverted.
- Menus are blocked while mining (mining.md).

### 1.7 Death

Normal fighter death (npc_traffic_ai.md §5.10). Because a wingman is not hostile: `Level::friendDied` (friends-left
counter) and **`Level::wingmanDied(name)`** 0xd4278: removes that name from `Status+0x24`; if it was the last one
(count < 2) `setWingmen(null)` (contract gone). No radio, no HUD message, no standing change. A dead wingman does not
come back in later orbits. Kills made by wingmen count as NPC kills (`Player+0x44`): `Level+0x20` "killed by others",
no player kill statistic, no standing penalty, no rank.

### 1.8 Contract and expiry

- `MGame::OnUpdate` 0x1ac778 (verified): `Status+0x30 −= dt` every unpaused flight frame, with the **fast-forward
  scaled** dt (`MGame+0x40`, raw frame time clamped to 150 ms ×5 under fast-forward). Not in the station, not while
  a menu/dialogue pauses the game. 600 000 ms = 10 minutes of flying.
- Nothing happens in space when it reaches 0: the wingmen keep spawning and following (§1.4 does not check it). Text
  312 "Wingmen's remaining time" has no caller in this binary (no HUD timer).
- **At the next station** (`ModStation::checkHints`, once per visit `+0xd7`, no other window up): wingmen non-null and
  `Status+0x30 < 1` → `DialogueWindow(313 "Our contract has expired, Mr. Maxwell. We'll go our separate ways now. See
  you in space!", speaker = names[0], portrait = Status+0x28)`, voice `getDialogueSoundId(313, Agent(race +0x2c))`,
  then `setWingmen(null)`.
- `nextCampaignMission` case 47 (Valkyrie start, loaner Vossk ship) sets `+0x30 = 0`: dismissed at the next dock.

### 1.9 Missions

- Challenge (freelance type **0x0c**, "kill more pirates than the rival"; npc_traffic_ai.md §2.9 lists it as escort):
  wingmen spawn **unarmed** (§1.4), so they can neither help nor steal kills (`Level+0x24` player kills vs
  `Level+0x20` others).
- Other freelance and story orbits: wingmen spawn normally (except campaign 158 and supernova systems) and help; they
  are not counted by "all enemies dead" objectives. Several campaign scripts exclude wingmen explicitly (`isWingMan`
  checks in `LevelScript::process`, e.g. campaign_levels_b.md 0x33/0x46 "every non-wingman enemy").
- The escort objects of other missions are separate always-friend ships, not wingmen.

### 1.10 Save (`RecordHandler::recordStoreWrite` 0xdf760, write order)

`Status+0xd4` (hired count) early in the record; later: names count (−1 = none) + each name, race `+0x2c`, contract
`+0x30`, the constant 5 and the 5 portrait parts. Wingmen and their remaining time **persist across saves**;
`Status+0xf8` is not saved.

### 1.11 Texts and sounds

306 Wingmen, 307-311 commands, 312 (unused), 313 goodbye, 567 statistic label, 637-639 help hint, 649 all medals,
779-784 offers, 785 already hired, 866 / 867 confirm, 1579 medal 27, 3358 key label. Shot sounds: race sound for the
laser, 74 for the EMP blaster. Goodbye voice via `Globals::getDialogueSoundId(0x139, agent)` (voice events unmapped).

### 1.12 DLC

Base game (no add-on flag involved). Only `inSupernovaSystem` switches them off.

---

## 2. Most Wanted board

### 2.1 Data

`wanted.json` = `FileRead::loadWanted`: 25 entries. `Wanted` object (game/Wanted.c, ctor 0x14805c, 0x50 bytes):

| Offset | Field (JSON) | Use |
|---|---|---|
| +0x00 | name | lock plate, radio, board, hint 3232 |
| +0x08 | index | description text **3174 + index**, radio speaker 10000 + index |
| +0x0c | board 0-3 | race whose stations show it (0 Terran, 1 Vossk, 2 Nivelian, 3 Midorian) |
| +0x10 / +0x14 | race / male | spawn race `race < 4 ? race : 8` (Multipod → pirate) |
| +0x18 / +0x1c | ship / weapon | ship index; weapon item (`assignGuns`, ×4 damage, ship_combat.md §4.1) |
| +0x20 | hitpoints | HP base |
| +0x24 / +0x28 | loot / lootAmount | its crate |
| +0x2c | reward | bounty credits |
| +0x30 | requiredBounties | kills on its board needed before it activates |
| +0x34 | requiredMission | campaign index needed (storyline 0/1: exactly that index) |
| +0x38 | numWingmen | 0-4 escorts |
| +0x3c | image parts [5] (portraitParts) | board portrait, radio portrait |
| +0x40 / +0x44 / +0x48 | current location / travels to / last seen (station indices, −1) | |
| +0x4c / +0x4d | active / terminated | |

Status: `Status+0x00` = the `Array<Wanted*>`; `Status+0x04 + 4·board` = collected bounties per board
(`getCollectedBounties` 0xba0a4 / `incCollectedBounties` 0xba0b2). `Status::isStorylineWanted(i)` 0xba1ea = i ∈ {0, 1}.

`wingmen_wanted.py wanted [level]` prints the table with derived HP, jump bounds and unlocks.

### 2.2 Board access (`Status::wantedBoardAccessible` 0xba1f8)

True when some entry has `board == current system race` and `requiredMission ≤ campaign`, and the player is not in
the alien orbit (`Status+0x78`) and not at station 108 Kaamo. Then `MissionsWindow::init` adds the tab 3219 "Most
Wanted", which opens `WantedWindow` (0xf4a58). Effectively: Terran stations from campaign 128, the other races from 161.

### 2.3 Activation (`Status::activateNewWanted` 0xba2ac)

Called (a) in `ModStation::OnInitialize` on every docking (message 3230 "New info on 1 more Most Wanted criminal
available." / 3231 "…#N more…" when ≥ 1 activated and no other window is up), (b) when step 128 is reached
(`ModStation::OnTouchEnd`, then hint 601 once, `hints[0x2a]`). For each entry i:

```
if board == system race of the current station and requiredMission <= campaign
   and (i >= 2 or campaign <= requiredMission)          // storyline 0/1 only at their exact index (128 / 130)
   and not in the alien orbit, station != 108, not active, not terminated
   and requiredBounties <= collectedBounties[board]:
    active = true
    (lo, hi) = i < 2 ? (2, 4) : ((i-1)%6/3 + 2, (i-1)%6/2 + 4)     // path node counts incl. start = jumps + 1
    repeat:
        S1 = random station (nextInt(135)) whose system has gate routes, is visible, not in {6, 25, 26, 27, 28}
        S2 = same rules, another system
        path = SystemPathFinder::getSystemPath(sys S1, sys S2)      // BFS over gate routes into visible systems
    until path and lo <= len(path) <= hi
    lastSeen = S1; travelsTo = S2
    current = a random station of a random system of the path (nextInt(len), then nextInt(stations))
return number activated
```

Excluded systems: 6 Wolf-Reiser, 25 Loma, 26 Shima, 27 Ginoya, 28 Talidor. Bounties count per board, so the Terran
board unlocks 2 → 3 → 4 → 5 → 6 one kill at a time (the storyline 0/1 never count: they surrender, §2.8); each other
board needs 0-5 of its own kills.

### 2.4 Movement (`Status::moveWanted` 0xb6858)

Called from `Status::departStation` 0xb63e0 on a real orbit change (not from/to the alien orbit, not when the target
index equals the current one, i.e. **not** when launching from the station you are docked at). By then the current
station is already the one being entered (`addStationToStack` → `setStation`). For every active, not terminated
entry:

```
if current == the orbit being entered or current == Level::programmedStation: stays      // you find it there
elif current == travelsTo:                        // arrived last time: pick a new trip
    lastSeen = current
    repeat S = random station until path(sys current, sys S) exists, lo <= len <= hi, sys S has routes, visible,
           not excluded, sys S != sys current
    travelsTo = S                                 // current unchanged this step
elif sys current == sys travelsTo: current = travelsTo
else: current = jumpgateStation of path[1]        // one system per orbit change, at the gate station
```

So a wanted walks its gate route one system per player orbit change, showing up at the jumpgate orbit of each system
on the way, pauses one step at its destination, then leaves for a new destination 1-5 jumps away. The board only
shows `lastSeen` and `travelsTo`; hint 601: "…try to scan every ship in jumpgate orbits along the route they're
taking." `wingmen_wanted.py simulate IDX` walks this. Movement is driven by the player's orbit changes only (nothing
moves while docked).

### 2.5 The board (`WantedWindow` 0xf4a58: `init` 0xf4b4c, `draw` 0xf5910, `selectWanted` 0xf5090, `OnTouchEnd` 0xf6518)

- List: every entry with `board == system race`, shown for Terran boards from campaign 0x80 and for the others from
  0xa2 (162) (so non-Terran boards are empty between 161 and 162). Rows: name; colour by active; the storyline row
  (entry 0 at campaign 128, entry 1 at 130) gets the story icon. Initial selection: the first active entry.
- Tabs 129 "Missions" / 3219 "Most Wanted" (pressed), header 3219, boxes 3221 "LIST" / 3222 "DETAILS", help 635.
- Details: portrait (`ImageFactory::loadChar(imageParts)`), name, "3226 Status: 3228 Alive / 3227 Deceased",
  "3225 Bounty: <reward>$"; scroll text "3223 Departed from:\n<lastSeen station (system)>\n\n3224 Travelling to:\n
  <travelsTo (system)>\n\n<description 3174+index>". Inactive, not terminated: both places 3229 "N/A" (bounty still
  shown); terminated: " --" everywhere. The current location is computed but never displayed.
- Button 424 "Show on map" (only for an active entry): the star map with a dummy `Mission(0, 0, travelsTo)` as
  target and `setStart(system of lastSeen, lastSeen)`.
- Texts 3220 "Wanted Board" appears unused.

### 2.6 In orbit

**Spawn** (`Level::createMission` 0xbda70, free-flight branch only, i.e. never in freelance/story mission orbits):
`w = Status::getWantedInCurrentOrbit()` 0xb916c = active, not terminated, `current == this station` (several: the one
with the lowest `requiredBounties`). Then local fighters are capped at 2 and increased by `numWingmen + 1`
(still applies in a supernova system, where the others are zeroed). Array slots:

```
[0] wanted: createShip(race < 4 ? race : 8, 0, w.ship, local waypoint)       // same spot as the police (+-20000 jitter)
    h = 15*min(level, 20) + w.hitpoints + 4*cm   (cm = 45 when the game is won: always, campaign >= 128)
    maxHP = HP = int(h + h*(difficulty - 0.5))   (x1 normal, x2 Extreme)
    name = w.name; loot = [w.loot, w.lootAmount]; KIPlayer+0x3e = 1; +0x44 = w.index; setSpeed(4.5)
[1..numWingmen] getRandomEnemyFighter(same race), same waypoint, maxHP = HP = h/2
[..] the remaining local fighters of the system race
```

`setSpeed(4.5)` disables its boost/evasion; it patrols the police box like the local fighters. Guns: the wanted's own
weapon ×4 (rockets: RocketGun speed 8, lifetime 10 000, reload 3000); ships 45-48 add a G'liissk rocket gun; every
20 s it toggles primary/secondary if it has a secondary (`+0x2e0`) (ship_combat.md §4.1, npc_traffic_ai.md §4.6).
The escorts are ordinary fighters of that race. Ship 45 also gets its turret (`createFighterTurrets`).

**Disguise**: nothing marks it until it is locked: its marker is the normal race colour. Its hostility is the normal
race rule: a pirate / Multipod wanted (spawned as race 8) and its escorts are hostile from the start; the others are
neutral/friendly unless their race is an enemy by standing.

**Uncover** (`PlayerFighter::update` ~0xf0f00): while not always-enemy, if the player's radar lock (`PlayerEgo+0x14`
→ `Radar+4`) is this ship and it has not surrendered: `setAlwaysEnemy(true)` + `Level::uncoverWanted` 0xd63ac. Needs a
scanner (ship locks need one, ship_combat.md §7.1). The lock plate then shows "<name> NN%" (damage rate) instead of the
race (`Radar::drawCurrentLock`).

**Attack** (`Player::damage` 0xafa70 / `damageEmp` 0xaf834): any player damage > 0 to a `+0x3e` ship (not race 9/10)
→ `Level::attackWanted` 0xd642c (instead of the friendly-fire rules; no standing hit).

Both events (once per level: `Level+0x29c` set by attack; uncover checks it but does not set it) make every escort
(`ships[1..numWingmen]`) always-enemy + `turnEnemy`, and queue radio (`Level::createRadioMessage` 0xd5568, only when
the level mission is empty; speaker 0 = Keith, 10000+i = the wanted's portrait; first line time-triggered 5000 ms,
the rest chained):

| Event | Generic wanted (index ≥ 2) | Pal Tyyrt (0) | Kehnor (1) |
|---|---|---|---|
| uncover (type 0x12) | Keith: `nextInt(5)` of 3141-3145 ("He's on the wanted list. Time to cash in!") | Keith 3134, Pal 3135 | Keith 3139, Kehnor 3140 |
| attack (type 0x10) | only wanted **2 and 6**: the wanted, `nextInt(5)` of 3146-3150 (verified `(i | 4) == 6`; others silent) | Pal 3132, Keith 3133 | Kehnor 3136, Keith 3137, Kehnor 3138 |
| kill (type 0x11) | Keith: `nextInt(5)` of 3151-3155 ("A job well done."), ~6000 ms after the kill | same | same |

Tables: counts `DAT_00254270` = [2, 3], pairs `0x2542d4`; uncover counts `0x2542fc` = [2, 2], pairs `0x2543c0`.
`Radio` resolves speaker ≥ 10000 to `Wanted[speaker − 10000]` image parts (Radio.c ~l.208).

**Music**: while an always-enemy (uncovered) wanted is among the hostile ships, `Radar::draw` plays **151
`SN_WantedBoardCriminals`** instead of the combat tracks.

**Surrender at 1/3** (`Player::damage`: `+0x3e` ship and hull < max/3 → `Level::almostKillWanted` 0xd64b0, once via
`Level+0x29e`): only storyline wanteds (§2.8); nothing for the others.

**Kill** (`PlayerFighter::update` death, ~0xf1cf0, verified): at HP < 1, **whoever killed it** (player, wingman,
police):

```
Wanted.terminated = true; active = false
Layout::showMissionRewardMessage(reward, bounty = true)   // box "3206 Bounty collected" + "+ <credits>", sound 36
credits += reward
collectedBounties[board] += 1
Level::killWanted -> radio 0x11 (once, Level+0x29d)
```

No `Standing::applyKill` for the wanted itself (its escorts are normal kills: −5 standing with their race). The
normal death/crate code follows (its loot crate). The police respawn skips it (`updateOrbit`).

### 2.7 Storyline wanteds 0 / 1 (Supernova campaign 128 / 130)

`almostKillWanted` for index 0/1: `Mission(4, 0, current station)` as won campaign + level mission, a new objective
(type 3), the wanted is no longer always-enemy, damage-by-player reset, hostile flag off, surrendered (`+0x3f`), and
`Wanted.active = false` (**not terminated**, no bounty, no bounty count). `MGame::successCheck` then shows the success
dialogue (0xb1e-0xb21 / 0xb22-0xb2a) and advances 128 → 130 / 130 → 131 (campaign_flow.md). A surrendered wanted turns
hostile again if the player keeps shooting it above 5 % of its max hull (`+0x6c > max/20`). If one shot takes it from
above 1/3 to 0, the surrender still runs first and then the kill pays the bounty too *(inferred from the order in
`Player::damage`)*.

### 2.8 Ships 45-48 at Quineros

`Generator::getShipBuyList` 0xa0eb8 for station 107 (Quineros, Loma black market): all pirate-race ships
(`DAT_00251d5c[i] == 8`) plus, each as race-8 ship with `Ship::adjustPrice`: ship 45 Bloodstar when wanted 6 (Qyrr
Myfft) is terminated, 46 Blue Fyre (12 Urr Sakant), 47 Gator Custom (18 Malon Sentendar), 48 Amboss (24 Heinrich
Wickel) – the last of each board. `ModStation::checkHints` shows 3232 "#WANTED_NAME's ship "#SHIP_NAME" is now available
on Quineros station in the Loma system." once per ship (`hints[0x33..0x36]`, ship name text 913 + ship).

### 2.9 Save

Per wanted (`RecordHandler::writeWanted` 0xe1294 / `readWanted` 0xdf578): active, terminated, current, travelsTo,
lastSeen, then the full static record (name, index, board, race, male, ship, weapon, hitpoints, loot, lootAmount,
reward, requiredBounties, requiredMission, numWingmen, 5 image parts). Then the 4 collected-bounty counters,
`options[0x37]`, and hints 0x28, 0x29, 0x2c, 0x2a (Terran boards hint), 0x2b (all boards hint), 0x2e-0x30. Hints
0x33-0x36 are in the global hint block.

### 2.10 DLC gating

The code and data are in the base binary, but everything is keyed to campaign indices ≥ 128, which only the
**Supernova** campaign reaches (options[0x37] owns Supernova; `startSupernova` jumps to 84+). Without Supernova the
board never appears, nothing activates, no wanted spawns. Music 151 is an `SN_` track. Quineros/Loma (Valkyrie's black
market system, visible with options[0x35]) sells the unlock ships. Boards 1-3 are the Supernova end reward (hint 613 at
162). No separate option flag is tested by the wanted code itself.

---

## 3. Function index

| Function | Address |
|---|---|
| Level::createWingmen / assignGuns / connectPlayers / init | 0xcb338 / 0xcb638 / 0xcc330 / 0xbb49c |
| KIPlayer::setWingman / setWingmanCommand / isWingMan | 0xb2d26 / 0xb2d32 / 0xb2d20 |
| PlayerFighter::setWingmanCommand / update (formation ~0xf1040, targeting ~0xf13c0, command 2 ~0xf1920) | 0xf096c / 0xf0d90 |
| Level::wingmanDied / friendDied / enemyDied | 0xd4278 / 0xd426c / 0xd3f98 |
| Status::getWingmen / setWingmen | 0xb9b08 / 0xb9b0c |
| Hud::initHudMenu / checkIfQuickMenuIsEmpty | 0x18e080 / 0x18de64 |
| MGame::OnTouchEnd (menu dispatch) / OnUpdate (contract, Wingmen key) | 0x1a98d8 / 0x1ac778 |
| keyPressed (key 19 "Wingmen" → Globals::showWingmanMenu 0x25ccf4) | 0x725d8 |
| ModStation::checkHints (goodbye 313, hints 649 / 3232) / OnInitialize (activateNewWanted, 0xf8 reset) | 0xee500 / 0xe8080 |
| SpaceLounge::onKeyPress (hire) | 0x19c6fc |
| Achievements::countMedals / gotAllMedals / checkForNewMedal | 0x182444 / 0x1824c6 / 0x181ec0 |
| Status::wantedBoardAccessible / activateNewWanted / moveWanted / getWantedInCurrentOrbit / isStorylineWanted | 0xba1f8 / 0xba2ac / 0xb6858 / 0xb916c / 0xba1ea |
| Status::getCollectedBounties / incCollectedBounties / departStation / addStationToStack | 0xba0a4 / 0xba0b2 / 0xb63e0 / 0xb6140 |
| Level::uncoverWanted / attackWanted / almostKillWanted / killWanted / createRadioMessage | 0xd63ac / 0xd642c / 0xd64b0 / 0xd65c8 / 0xd5568 |
| WantedWindow::init / selectWanted / draw / OnTouchEnd / getWantedAtPosition | 0xf4b4c / 0xf5090 / 0xf5910 / 0xf6518 / 0xf6228 |
| Wanted::Wanted / RecordHandler::readWanted / writeWanted | 0x14805c / 0xdf578 / 0xe1294 |
| Globals::getRandomEnemyFighter / getRandomStation / SystemPathFinder::getSystemPath | 0xf9034 / 0xf9148 / 0x14065c |
| Layout::showMissionRewardMessage | 0xe7648 |

## 4. Uncertainties

- Level types 4 / 0x17 (no wingmen) are cutscene/scripted level kinds; which scenes use them was not traced.
- Sound 48 (wingman engine) looks unused (constructor order); not verified at runtime.
- The attack taunt only for wanted 2 and 6 is what the code does (`(i | 4) == 6`, disassembly 0xd5b02); it may be a
  bug of the original (probably meant for all generic wanteds).
- Hint texts 637-639 go through the hint table; the trigger (first launch with wingmen?) was not traced.
- The HUD marker/radar colour of wingmen is the normal friend colour (green) *(inferred from `+0x5d = 1`)*.
- Whether `getSystemPath` can fail in `moveWanted` after systems become hidden (the code would dereference null) –
  visibility only grows in practice.

---

## Remake implementation notes

Current state in the project (read-only survey): `Session.Wingmen / WingmanRace / WingmanContractMs` and
`Wingmen.Hire/Dismiss` exist (hire from `LoungeChat`), saved by `SaveGame`. Missing: the portrait parts
(`Status+0x28`), the hired counter (`Status+0xd4`), anything in flight. Note that `Wingmen.Hired` requires
`WingmanContractMs > 0`; the original spawns wingmen as long as the list is non-empty and dismisses them only at the
next docking (§1.8), so the spawn check should use `Wingmen.Count > 0`.

**Plain C#**

- `Wingmen` (extend): `HiredTotal` (+0xd4, medal 27), `PortraitParts[5]`, `TickContract(dtMs)` (called by the
  flight level with the fast-forward-scaled dt while not paused), `OnDocked()` → returns the goodbye dialogue data
  (313, names[0], portrait, race) when `Count > 0 && ContractMs < 1` and dismisses, `OnWingmanDied(name)`
  (`wingmanDied`: remove the name, dismiss when it was the last), `ShipFor(name, race)` = `JavaRandom(5 *
  name.Length)` + the `getRandomEnemyFighter` loop (port `wingmen_wanted.py wingman`; `NpcTables.RandomFighter`
  uses UnityEngine.Random, so add an overload taking a `JavaRandom`), `SpawnOffset(slot)`, `FormationOffset(slot)`,
  `enum GoF2WingmanCommand { ToggleWeapon = 0, FireAtWill = 1, SecureWaypoint = 2, AttackTarget = 3 }`,
  `WeaponLabelEmp` (Status+0xf8, reset on docking).
- `GoF2WantedBoard` (new, state in `Session`: per entry active / terminated / current / travelsTo / lastSeen,
  `CollectedBounties[4]`, hint flags): `Accessible(station, campaign)`, `ActivateNew(station)` → count (docking),
  `Move(enteringStation, programmedStation)` (every orbit change except relaunching from the docked station),
  `InOrbit(station)` → entry or null, `OnKilled(index)` → reward, `OnSurrender(index)`, `ListFor(systemRace, campaign)`,
  `UnlockedDealerShips()` for station 107. Route picking uses `GalaxyMap`'s gate path (BFS over visible
  systems; check it counts nodes incl. the start) and UnityEngine.Random (the original RNG is time-seeded). Save it in
  `SaveData` (bump the version); the static fields come from `wanted.json` (add a `WantedData` class to
  `Database`).
- Free play note: the remake's free play runs at campaign 20, so the board would never open. Either keep it for the
  Supernova campaign or add a remake-only switch (e.g. treat free play as campaign ≥ 162, or unlock boards after
  the main game) – a design decision, flag it in CLAUDE.md like the other remake-only rules.

**Spawning: `TrafficPlan` / `Traffic` / `NpcShip`**

- Extend `SpawnSpec` with `wingmanSlot = -1` (≥ 0 = wingman), `wantedIndex = -1`, `speedOverride` (4.5 for the
  wanted), `name` (string; the existing `nameText` is a text id), `extraGuns` / a gun-profile enum (wanted weapon ×4,
  wingman EMP secondary), and `unarmed`.
- Wanted: in `TrafficPlan.Build` after computing `local`: `if (wanted != null) { local = min(local, 2); }`, then emit
  the wanted spec first (`group = Local`, race `race < 4 ? race : 8`, ship, position `wpLocal + Jitter()`,
  `hitpoints = h`, loot, `wantedIndex`), its `numWingmen` escorts (`hitpoints = h/2`, `RandomFighter(race)`), then the
  `local` police as now. Only for free-flight orbits (the plan is only used there already).
- Wingmen: not part of the plan (they are appended after campaign/freelance spawns too). Add
  `Traffic.SpawnWingmen(Target player)` called by `SpaceLevel` after `Setup` (and by `CampaignLevel`
  / the freelance orbit builder) when `Wingmen.Count > 0`, not in a supernova system, campaign ≠ 158; specs with
  `alwaysFriend = true`, `hitpoints = max(600, …)` semantics of `setHitpoints` (HP 600, max = max(600, formula)),
  `unarmed` when the freelance mission type is Challenge; place with `NpcShip.Place(ToUnity(pos), forward)`.
  `ConnectPlayers`: a wingman's enemy list is the player + every other ship (also its own race).
- `NpcShip` additions (keep them in a plain `GoF2FighterBrain`-style helper if the MonoBehaviour grows):
  - `UpdateRelations`: wingman → hostile false, friend true regardless of standing (today `alwaysFriend` does this).
  - `UpdateTargeting`: the wingman branches of §1.5 (hostile-to-player scan with no distance limit, command 3 target
    with fallback to 1, command 1 idle → formation); `route` replaced every frame by a one-point looping `Route`
    at the formation point (command 1); command 2 = `Route` clone of the player route (`Navigation` /
    `Story` waypoint route) limited to the current waypoint.
  - `SetWingmanCommand(cmd, target)` with the side effects of 0xf096c (boost off for 1, re-target timers for 2/3,
    ignore 2 without a route and 3 without a lock, 0 toggles the fired slot and keeps the command).
  - Second gun (EMP): `Gun` with EMP damage 8 per hit; needs NPC EMP handling (`Hitpoints.empDisabled` exists
    for the player's EMP weapons; NPC-fired EMP against NPCs is still on the to-do list).
  - Drift during the launch/arrival camera (the level already knows `LaunchedFromStation` / `ArrivedByTravel`).
  - Death: `traffic.OnShipDied` → if wingman `Wingmen.OnWingmanDied(name)`; kills by wingmen are NPC kills
    (`byPlayer = false`, which the damage source already distinguishes).
  - Wanted: speed 4.5 and no boost; uncover when `CombatRadar.Locked == Target` (set `alwaysEnemy`, escorts
    `alwaysEnemy + turnedEnemy`, radio); `attackWanted` on the first player hit (in `Target.Damage` before the
    friendly-fire bookkeeping, and no standing penalty); surrender at `hull < max/3` for index 0/1 (story hook:
    mark the campaign mission won through `Story`); on death pay via `GoF2WantedBoard.OnKilled` whoever killed it,
    show "Bounty collected" + credits (3206, sound 36) and queue the kill line; exclude it from the 45 s police
    relaunch in `Traffic.UpdateOrbit`.
- Radio: the free-flight radio is a HUD message today (`Traffic.Radio`). The wanted lines need speakers (Keith,
  the wanted's portrait from `portraitParts`) and chaining; reuse `Radio` (trigger 5 time / 6 chain) with a small
  world adapter, or queue `RadioLine`s directly.
- Music: in `Traffic.UpdateMusic`, an uncovered (always-enemy) living wanted → 151 (`SN_WantedBoardCriminals`,
  check the .ogg exists in the audio banks) before the 140/141/142 choice.
- HUD / UI: a Wingmen entry in the flight menu (the remake's autopilot menu is the only in-flight menu so far: add an
  action menu or put "Wingmen" there as a remake placement), the 4 command buttons with the 310/311 label, a keyboard
  / controller binding for the direct "Wingmen" key (remake choice, e.g. G / D-pad), pause while open
  (`Navigation.Paused`, `Time.timeScale` 0 like the autopilot menu); lock plate "<name> NN%" for a locked wanted
  in `CombatView`. Station: a Most Wanted tab in `MissionsWindow` (list, portrait via `Portrait`, the
  3223/3224 text, Show on map → `StarMap.Open` with a target marker at `travelsTo`), messages 3230/3231 and hint
  601/613/3232 on docking, the goodbye dialogue 313 through `DialogueView`.
- Shop: `Shop` dealer list for station 107 adds ships 45-48 (race 8, `adjustPrice`) per terminated entry 6/12/18/24.
