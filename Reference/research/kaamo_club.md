# Kaamo Club (station 108, Shima system 26)

Everything about the player-owned station that the other research docs don't already pin down. Decoded from
`libgof2hdaa.so` (Android HD). Game units and milliseconds; Unity = `(x, y, -z) * 0.05`. Addresses use the Ghidra image
base 0x10000. **(v)** = read from the code / data, **(a)** = assumption or inference.

Already documented elsewhere (read first, not repeated): `blueprints_mods.md` §2 (ship mods, VIP card ×2), §3 (state
values, storage model `Status+0x14c`, `departStation` copying, dealers 25/26, coordinate sellers, save order);
`shop.md` §2.1 / §5 (storage-mode tabs and row buttons, trade-in maths); `station_interior.md` §1.4 (parked-ship
slots); `dialogue_cutscenes.md` §1.3 (speaker descriptors), §1.4; `freelance_missions.md` §1.3 (agent generation);
`ship_combat.md` §2.9, §5.2 (collision, `PlayerFixedObject` death); `starmap_travel.md` §4.2 (Shima icon/security).

---

## 1. Quick facts

| | Value | |
|---|---|---|
| Station | 108 "Kaamo", tech level 1, system 26 Shima, the system's only station and its `jumpgateStation` (gate orbit = the club's orbit) | v (stations/systems.json) |
| Shima | `initiallyVisible: true`, security 0 (Dangerous), `raceId` 3 Midorian but `SolarSystem::hasNoOwner` 0x180cc0 (23, 24, 26, 32, 33) → no race icon/line on the map; gate routes to 9 Weymire, 17 Nesla, 25 Loma | v |
| Station model | assembly `station_kaamo_club` (21108 + emissive 21908 + fx 22900-22903, animated every frame). **No state-dependent parts**: `PlayerStation` never reads `Status+0x114` (same model in every state) | v |
| Station collision | `collision.json` id 108 (4 volumes) | v |
| Orbit traffic | none in any state (`Level::createMission` stations 100/101/108 → all counters 0), except the state-0 siege (§3) | v |
| Space music | **146 `HomeBase_NoCombat`** whenever no hostile is counted, all states (`Radar::draw` 0x1554fc, `Globals::playMusicAndFadeOutCurrent`); battle tracks 140-142 with hostiles | v |
| Docked | music 132 `HomeBase_Station`; hangar and bar = the **Midorian** set (hangar index = system race 3, `Level::createScene` 0xc2910); no ticker, no Wanted board | v |
| Shop / dealer | `Generator::getItemBuyList` / `getShipBuyList` give 108 nothing; `computerTradeGoods` skips it; freelance generator never targets it (108 is in `DAT_00251e70`, the 52 excluded target stations, `Generator::generateStationIndex` 0xa1e2c) | v |

---

## 2. State machine (`Status+0x114`)

```
0 not owned ──(orbit 108, level ≥ 5 s: dialogue 457)──────────────► 1   MGame::OnUpdate 0x1ac778
1 ──(dock at 108: 18-page conversation, ModStation::OnInitialize 0xe8080)──► 2
2 ──(dock with ≥ 50 t Buskat and ≥ 30 000 001 $, 477 → Yes, ModStation::OnTouchEnd 0xea4ec)──► 3 owned
IAP (options[0x36], texts 78/88/93): ndk_iapBoughtPremium 0x9f2e8 / MenuTouchWindow::update 0x14ffec → 3;
resetGame and GameRecord::load force 3 while the option is owned, else 0 / the saved value.
```

Note the order: 457 ("help an old friend…") is shown when you **arrive** in the orbit, not after winning, and sets
state 1 immediately (v). The siege has to be won before docking is possible at all (§3.5), so in practice state 1
always means "siege won".

---

## 3. Orbit 108 while not owned (state 0)

### 3.1 Setup (`Level::createMission` 0xbda70, empty-mission branch, v)

Only when the orbit's own mission (`Status+400`, set by `departStation`) is empty — always true at 108 because no
campaign or freelance mission can target it. Then:

- `Level+0x288 = 1` (enables respawns, §3.4), counters `+0x160/+0x164/+0x168 = 0`, `+0x16c = 6` (**8 in hardcore**).
- Enemy array `Level+0xf8` length `+0x16c + 4`: slots 0-3 the outposts, slots 4.. the pirates.
- Mission `Mission(type 4, client name 1601 "Mkkt Bkkt", image [4,2,0,2,2] (DAT_0026a1b0), client race 4 Multipod,
  reward 0, target station 108, difficulty 0)`, visible (+0x60 = 1), no agent. **`Status::setFreelanceMission(it)` and
  `Status::setMission(it)`**: it overwrites the player's current freelance slot (any active freelance mission is lost
  unless the player dies and reloads) (v).
- Win objective `Level+0x28 = Objective(0x12, 0, count = array length)` = **every** enemy [0, 10) (or [0, 12)) dead.
  No fail objective (only the player's death).

### 3.2 The four "Pirate Outposts" (object 0x37a3)

`createStaticObject(null, 0x37a3, jitter=true)` 0xcda54 ×4, then `setPosition` (vtable +0x48) to fixed points (the
±10000 jitter is overwritten), name (`KIPlayer+0x18`) = **441 "Pirate Outpost"**. No rotation is ever set (game
identity; in Unity that is yaw 180° under the project's `RotationToUnity` convention, a). Scale 1.

| # | game (x, y, z) | Unity m (x, y, z) | distance from the club (units) |
|---|---|---|---|
| 0 | (45000, 5000, 55000) | (2250, 250, −2750) | 71 200 |
| 1 | (80000, −30000, −12000) | (4000, −1500, 600) | 86 300 |
| 2 | (−15000, 45000, 55000) | (−750, 2250, −2750) | 72 600 |
| 3 | (−65000, −20000, −45000) | (−3250, −1000, 2250) | 81 600 |

- **Meshes** (v, `resources.json` / `assemblies.json` entry `station_pirates`, pack main, category stations): 14243
  `station_pirates` (hull, bsphere r ≈ 28 200) + children 14244 `_emissive`, 14245 `_lights_add`; wreck mesh 14246
  `station_pirates_explosion_anim` (`setWreckedMeshId(0x37a6)`, 12 parts, animation 20 000 ms). The assembled prefab
  has no `explosionModel`; use 14246.
- **Object**: `PlayerFixedObject(0x37a3, race 8 pirate, Player(radius 7500, hp))`, never moves (`moveForward` skipped for
  0x37a3), `KIPlayer+0x3d = 1` (mines, gun sort 11, ignore it: `Gun::calcCharacterCollision`), no engine sound, **no
  guns and no turrets** (not armed, no `PlayerTurret` created) — they are passive targets (v).
- **Hit points** (v): `f = 5 · ((gameWon ? 180 : 4·campaign) + (rank < 21 ? 15·rank + 20 : 320))`,
  `hp = int(f + f·(difficulty − 0.5))` (×1 normal, ×2 hardcore). Free play campaign 20: rank 0 → 500, rank 10 → 1250,
  rank 20 → 2000.
- **Damage**: any player weapon; bullet hit test is the axis-aligned **cube ±7500** around the outpost origin
  (`Player+0x40` = radius; the custom-collide flag `KIPlayer+0x3c` is not set for 0x37a3, so the bounding volumes below
  are not used for bullets) (v). No shield/armor.
- **Collision volumes** (player push-out, `PlayerEgo::calcCollision`): `getBoundingVolume(…, 1002)` 0xd3b78 → id 1002
  < 2000 → `FileRead::loadStationCollision` = `collision.json` id **1002**, 12 volumes. Decoded from the disassembly:
  sphere `0 a b c d` → centre offset (a, c, −b), r = |d|·0.6; box `1 a b c d e f` → centre (a, c, −b), half extents
  1.2·(|d|, |f|, |e|). Axis-aligned, offsets relative to the outpost position (v):

| # | kind | centre game | size game | Unity centre m | Unity size m |
|---|---|---|---|---|---|
| 0 | sphere | (0, −3287, 0) | r 12457 | (0, −164.35, 0) | r 622.9 |
| 1 | sphere | (0, 5807, 0) | r 5830 | (0, 290.35, 0) | r 291.5 |
| 2 | sphere | (0, −11176, 0) | r 4253 | (0, −558.80, 0) | r 212.6 |
| 3 | sphere | (−3976, −6773, 14128) | r 4253 | (−198.80, −338.65, −706.40) | r 212.6 |
| 4 | sphere | (−10347, −6773, −10428) | r 4253 | (−517.35, −338.65, 521.40) | r 212.6 |
| 5 | box | (−3844, −5265, 13590) | half (794, 15682, 956) | (−192.20, −263.25, −679.50) | half (39.7, 784.1, 47.8) |
| 6 | sphere | (−7513, −6773, −7759) | r 1889 | (−375.65, −338.65, 387.95) | r 94.4 |
| 7 | sphere | (10769, −6773, −2686) | r 1889 | (538.45, −338.65, 134.30) | r 94.4 |
| 8 | box | (−10168, −5420, −10323) | half (1927, 6346, 1951) | (−508.40, −271.00, 516.15) | half (96.4, 317.3, 97.6) |
| 9 | box | (14186, −5420, −3515) | half (1927, 6346, 1483) | (709.30, −271.00, 175.75) | half (96.4, 317.3, 74.2) |
| 10 | sphere | (14008, −6773, −3619) | r 4253 | (700.40, −338.65, 180.95) | r 212.6 |
| 11 | sphere | (−3108, −6773, 10445) | r 1889 | (−155.40, −338.65, −522.25) | r 94.4 |

  (These ×0.6 / ×1.2 factors are the static-object rule; the club's own station volumes use the station rule.)
- **Destruction** (`PlayerFixedObject::update` 0x17f480, v): hull < 1 → `enemyDied`, `Level::pirateStationAction(false)`
  (does nothing at 108: 108 is not one of the 4 pirate-base stations `DAT_00251f90` = 1, 33, 47, 86, and radio needs an
  empty mission anyway), state 3: hull swapped for the wreck animation (14246, plays once, 20 000 ms), sound 20,
  smoke particle system `Level+0x54`, `Explosion` type 0 + fire streaks; animation over → state 4, smoke off,
  explosion reset, **`setScaling(8)`**, restarted, camera rumble (30 000 units). The wreck then stays (state 4).
- **Loot: none.** The ctor only builds a loot list for 0x37a3 at the four pirate-base stations; at 108 `+0x4c` stays 0 (v).
- **No red fog** (`SET_FOG_STATIC` only in systems with a live pirate base, `SolarSystem::hasPirateBase`) (v).
- **HUD** (a): they are ordinary entries of the enemy list (race 8, always hostile), so they get the red ship markers,
  hull bar, radar ship lock and count as hostiles for the combat music like fighters; the lock plate shows name 441.

### 3.3 Pirate fighters (v)

`count = 6` (8 hardcore) × `createShip(race 8, kind 0, Globals::getRandomEnemyFighter(8), no waypoint, true, false)`:
model rolled per ship from the pirate list (2 Hiro, 11 Hernstein, 23 Azov, 24 Velasco, 25 Tyrion, 29 Mantis, 32 Wasp),
standard NPC hull/radius/gun (`ship_combat.md` §3.1), spawn `(rnd(40000) − 20000)` per axis around the origin (the
club), **awake, no route** (default patrol), always hostile. They are not guards (`+0x12b` is not set).

### 3.4 Respawn (`Level::updateMissionOrbit` 0xd4bd4, v)

While `Level+0x288` and the mission is not empty: timer `Level+0x174 += dt`; when > 22 500 ms: reset; if **at least one
outpost is alive**, every pirate slot that is dead and inactive is revived (vtable +0x18) and placed at
player + (±(40000..79999), ±(5000..9999), ±(40000..79999)). So pirates keep coming back until all four outposts are
gone; the objective then needs the remaining pirates killed.

### 3.5 Lock-outs while the siege mission runs (v)

The mission is non-empty and its type (4) is not in the exempt set {0, 0xb, 0xd, 0xab, 0xac, 0xbd}:
- docking at the club and flying into the gate: `MGame::dockEvent` 0x1afebc → `hudEvent(0x15)` **525 "Not possible on a
  mission."**; planet locks likewise (`Radar::draw`, no other planets in Shima anyway);
- Khador Drive: `MGame::UseKhadorDrive` 0x1a9480 → 525.
So arriving in Shima before owning the club is a trap: win the siege or die (death → reload the last save).

### 3.6 Dialogues in flight (v)

1. **Orbit entry** (`MGame::OnUpdate` chain; level time `MGame+0x48` ≥ 5001 and mission clock `LevelScript+8` ≥ 5001, no
   dialogue open, not in the alien orbit, state 0, station 108): one-page `DialogueWindow(text 457, name 1601, portrait
   [4,2,0,2,2])`, game paused, voice event **1468 `MSG_PLAYER_STATION_ENTER_ORBIT`** (DLC_VOICE), **state = 1**.
   457: "Maxwell, is that really you? … under siege from these pirates … Could you help an old friend…?"
2. **Success** (`MGame::successCheck` 0x1b0620 → objective met): `Status::incMissionCount` (missions completed +1, XP),
   `DialogueWindow::set(mission, success)`: the generic success page is replaced by **458** "Bravo! … I'll open the
   hangar so you can dock, okay?" (target station 108 rule, `DialogueWindow::loadContent` 0x194cd0), portrait/name =
   client, voice **1467 `MSG_PLAYER_STATION_ENEMIES_DEAD`**; `Standing::applyMissionCompleted(4)` (Multipod: no standing
   axis, a: no effect). Closing (`MGame::OnTouchEnd` 0x1a98d8): freelance slot and level mission emptied, reward
   message + credits of reward 0, docking/gate unlocked. No radio messages in this orbit.
3. The briefing path `MGame::dialogueEvent` 0x1b0498 would show the siege mission's briefing (a visible non-campaign
   mission) as the 6-page purchase table (§4.3) — but closing 457 calls `LevelScript::resetStartSequenceOver`, which
   disarms it (a: 457 wins the same-frame race because it is earlier in `OnUpdate`). Don't port this path.

### 3.7 Once owned (or after state 0)

State ≥ 1: `createMission` sets `+0x16c = 0`: the orbit is empty (station + gate only), music 146. (v)

---

## 4. Docking at 108 (`ModStation::OnInitialize` 0xe8080, docking state 0x14, v)

Autosave runs first (state is saved as it was on arrival), then:

### 4.1 State 1 → first visit conversation

`Mission(type −1, name 1601, image [4,2,0,2,2] (DAT_0026a214), race 4, reward 0, station 108)`, `setWon(true)`,
**state = 2**, then `DialogueWindow(mission, no level, mode 0 = briefing)`: target 108 and state 2 → table
`DAT_0025c5f0`, **18 pages** (`DialogueWindow::length` 0x195ca4). Speaker 4 = Mkkt Bkkt (descriptor 4,2,0,2,2), speaker 0
= Keith (mirrored), speaker 16 = Info (computer screen `11_3_3`). Names = text 1597 + speaker. Voices from the text→voice
table (`DLC_VOICE_*/MSG_PLAYER_STATION_DLG_0_n`):

| p | speaker | text | voice | gist |
|---|---|---|---|---|
| 0 | 4 | 459 | 1444 `DLG_0_0` | "Ahh, Maxwell! Nice to see you." |
| 1 | 0 | 460 | 1445 `_0_1` | what kind of place is this? |
| 2 | 4 | 461 | 1453 `_0_2` | welcome to the Kaamo Club… nothing left, pirates |
| 3 | 0 | 462 | 1454 `_0_3` | sounds like an opportunity |
| 4 | 4 | 463 | 1455 `_0_4` | I urgently need buskat |
| 5 | 0 | 464 | 1456 `_0_5` | anything else? |
| 6 | 4 | 465 | 1457 `_0_6` | buskat + credits and I give you this station |
| 7 | 0 | 466 | 1458 `_0_7` | practical for storing goods and ships; how much buskat? |
| 8 | 4 | 467 | 1459 `_0_8` | 50 tons |
| 9 | 0 | 468 | 1460 `_0_9` | a swimming pool? |
| 10 | 4 | 469 | 1446 `_0_10` | Bobolans, squid-forms… |
| 11 | 0 | 470 | 1447 `_0_11` | and how many credits? |
| 12 | 4 | 471 | 1448 `_0_12` | a mere 30 million |
| 13 | 0 | 472 | 1449 `_0_13` | 30 million? |
| 14 | 4 | 473 | 1450 `_0_14` | special price for a friend |
| 15 | 0 | 474 | 1451 `_0_15` | I'll think about it |
| 16 | 4 | 475 | 1452 `_0_16` | look in the space lounge, the dealers have offers |
| 17 | 16 | 476 | — (silent) | "Dock with 50 tons of buskat … and 30 million credits … to buy the station from Mkkt Bkkt." |

Closing it does nothing else (no reward, no standing). The purchase check (§4.2) does **not** run on this visit.

### 4.2 State 2 → purchase offer (every later docking)

- `credits < 30 000 001` (`< 0x1c9c381`) **or** cargo lacks 50 × item **109 Buskat** (`Ship::hasCargo(109, 50)`, cargo only,
  not the station stock) → OK-only ChoiceWindow **476** (same text as page 17).
- else Yes/No ChoiceWindow **477** "You have enough buskat and credits … Pay 50 tons of buskat and 30 million credits
  now?", flag `ModStation+0x68`.
  - **Yes** (`OnTouchEnd`, result 0 with +0x68): `changeCredits(−30 000 000)`, `removeCargo(109, 50)`, **state = 3**,
    `RecordHandler::saveOptions` (the options file only; the game itself is saved at the next save/docking), OK message
    **485** "You are now the proud owner of a space station. … whenever you buy a new ship you will be asked whether you
    would like to sell the old ship or store it at this location.", then `Station::setItems(station 108, null)` and
    `setItems(storage, null)` (anything sold to Kaamo before is wiped; ships untouched — 108 had none).
  - **No**: closes; `+0x68` is not cleared (a latent bug: a later Yes on the same ChoiceWindow during this visit would
    buy). Remake: clear it.
- Buskat: commodity 109, 9000-9900 $, "occurrence" 6 (cheapest in system 20, dearest in system 4) (items.json).

### 4.3 Texts that exist but are not wired (v)

- **478** ("buy the station immediately by selecting Expansions…?") is never referenced (no `0x1de` text id in the code).
- **479-484** (table `DAT_0025c680`, 6 pages 4/0 alternating, voices 1461-1466 `MSG_PLAYER_STATION_DLG_1_0..5`: "So,
  Maxwell, it appears you're really serious…" … "Take care old chum!") are only reachable through a mode-0
  `DialogueWindow` for a mission targeting 108 while state ≠ 2 — no live path in ModStation (§3.6.3). Remake decision:
  play them after 477 → Yes, before 485 (clearly the intent).
- 3162 "come and see me on Kaamo…" (voice 1559 `KAAMO_CLUB_MSG_0`) and **3163** "I've sent a few mechanics to Kaamo…"
  (1560 `KAAMO_CLUB_MSG_1`) have voice entries but **no code sends them** (not in any campaign radio array, not in
  `createRadioMessage`) — this corrects `blueprints_mods.md` §2.2. Remake option: send 3162 once when the player first
  has 30 M and 50 Buskat, 3163 after owning (remake-only).

### 4.4 State 3

No dialogue. Hangar = storage mode (`shop.md` §2.1, §6 below), stored ships parked (§6.6). No medal, ticker or story
hook on purchase.

---

## 5. How the player finds Kaamo (v)

- Shima is visible from the start and linked by gates to Weymire (9), Nesla (17) and Loma (25); a normal gate jump
  lands at the club's orbit (it is the gate orbit). The map shows Shima with no race; once state > 1 its security reads
  3 "Secure", and state 3 adds the orange house icon 0x545 (`StarMap::drawOnScreenInfo`).
- Nothing in the base game points to it: no agent, ticker item, campaign step or radio call references station 108 or
  Shima (the coordinate sellers 12-15, 19, 20 are elsewhere; freelance targets exclude 108; 3162/3163 unused). The IAP
  store text 88 is the only advert; in the hangar, buying a ship without the club shows advert **189** (`shop.md` §5).
- The Kaamo agents 21-26 (mechanics + dealers) are in its lounge once campaign > 16, regardless of ownership (dealer 26
  only greets until state 3).

---

## 6. Storage mode details (new facts only; `HangarWindow` `+0x11d` = station 108 && state 3)

### 6.1 Lists
- Store tab = `Item::mixItems(ship cargo, station-108 items)` + header 173 "Ships" and one row per stored ship
  (`Station::getShips(108)`); Ship tab and Blueprints tab unchanged. Labels in trade mode stay 136 "Station" / 183
  "Ship". Item rows draw **no price**; stored-ship rows draw `Ship::getPrice` (the sell value) instead of the trade-in
  delta. (v)
- **Mounted items are not in the list** (cargo only) → demount first on the Ship tab. (v)
- **Unsaleable items can't be stored**: `HangarWindow::transaction` 0x172820 refuses them with 323 before
  `Item::transaction` — story gear, Secure Containers (116, unsaleable), quest goods. (v)
- Transfers are free (`transaction(..., free = true)`, credits untouched), no capacity limit either way; the
  "not enough credits" branch is skipped. Moving a specialty (132-153) *from* storage sets its "bought" flag
  (`Status+0xac`) like a purchase (v, quirk).
- Blueprint ingredients are invested from cargo only (tab 4), so stored goods must be moved to cargo first. (v)
- Stored item fields: index, amount, single price (kept from when it was stored), unsaleable. (v)

### 6.2 One ship per type (v)
`Station::addShip` 0xb3dd8 silently ignores a ship whose index is already in the list (`Ship::equals` compares the index).
Hence 328 and the medal "different ships".

### 6.3 "Use" (row button 1, text 332) (v, `selectItem` 0x178e20 + `OnTouchEnd` 0x176d94)
Checks in order: passengers on board (`Status+0x34 ≥ 1`) → **336**; same index as the current ship → **329**; else
**333** "Do you want to switch ships?" (the credit check is skipped in storage mode). Yes:
1. new ship = `makeShip(stored index)`, race = the stored row's race, `adjustPrice`;
2. cargo: every cargo item cloned into the new ship (no capacity check);
3. equipment: the old ship's equipment array in slot order (primaries, secondaries, turrets, equipment), each item
   cloned and `addEquipment` (first free slot of its type) else `addCargo`; secondaries keep their ammo amount;
4. mods: the stored ship's mods;
5. the used row is replaced **in place** by `makeShip(old index)` with the old ship's race and mods (station 108 list),
   then the storage is re-synced from the station list (`setShips(storage, list, copy)`);
6. no 303 message in storage mode; ship tab and store tab rebuilt. No sound other than the buttons.
Overload is allowed; launching is refused with 204 as usual.

### 6.4 "Sell" (row button 10, text 330) (v)
Confirm **334**; Yes: `credits += row price` (`ListItem::getPrice` = the stored ship's adjusted `Ship::getPrice`; **mods
add nothing**), `Station::removeShip(108, ship)`; storage updated on departure. No restriction (the flown ship is never
in the list, so you can't sell your last ship).

### 6.5 Buying at other stations while owning the club (327 flow) (v)
`selectItem`: new.price > credits + current.price → 203 (+ "\n\n" + 124); passengers → 336; same type → 329; else 304.
Yes → ChoiceWindow 327 with **330 "Sell"** (result 0) / **331 "Keep"** (result 1):
- Sell = normal trade-in (`shop.md` §5): credits += old − new, the dealer row replaced by the old ship.
- Keep: **`Station::hasShip(storage, current ship index)`** → **328** "There is already a ship of this type at your
  station. The sale was cancelled." (the test is on the *old* ship's type); `credits < new.price` → 203 (+124); else
  credits −= **new.price** (full), the new ship is built as in §6.3 steps 1-4 (cargo and every mounted item move over),
  the bought row is **removed** from the dealer list, and `makeShip(old index)` + old mods is added to the storage
  (`Status+0x14c`) — a bare hull. Message 303.
- Race quirk: `Ship::clone` 0x1a4284 resets race to 0, and every storage copy (`setShips(…, copy)`, `makeShip`) clones,
  so stored ships effectively come back with race 0 (only matters for the race-dependent freighter model).
- Keep can leave the storage holding the type you now fly (e.g. keep A, buy B, later buy A back and keep B); "Use" on it
  then gives 329.

### 6.6 Hangar scene at 108 (`Level::createScene` 0xc2910, v)
Hangar = Midorian (system race 3). Parked count = `min(stored ships, UNK_00253ee8[3] = 3)` instead of `rnd(4)`; the
ships are the **first N entries of the storage list** (`Status+0x14c`) in list order, each on a random free slot of the
Midorian slot table, created as race 0, sleeping, exhaust off, random yaw 0..2.99 rad (same as random parking). The
player's current ship is on the turntable and is never in the list.

---

## 7. Kaamo lounge (v)

- Visitors = only the story agents assigned to 108 (`Generator::createAgents`: count s when station 108, no generic
  filler), i.e. **agents 21-26** once campaign > 16; none before (empty bar). Midorian bar.
- 21 Jelka Lithgow (Terran f, mod 0 +40 hull), 22 Nemor Kalant (Midorian, mod 1 +30 t), 23 Tedanor (Grey, mod 2 +1
  slot), 24 Longwei Zhou (Terran, mod 3 +0.2 handling), 25 Jakk Zoboon (Bobolian, offer 9, 911 "special item"),
  26 Umnar Zoboon (Bobolian, offer 10, 912 "very unique ship"). Mods work in any state.
- **Offer 10 ship**: candidates = [55 Groza Mk II, 56 Berger Cross Special, 57 Kinzer RS, 58 Phantom XT, 59 Teneta R.E.D.,
  60 Darkzov] minus stored types (storage list) minus the current ship; price = the prototype's base price (not
  race-adjusted), ×2 without the VIP card. Purchase (`SpaceLounge::onKeyPress` 0x19c6fc): pay, then
  `makeShip(index)` added to the **storage and to station 108's list** — a **bare hull**: no equipment, no mods, race 0
  (clone), unadjusted price. `setOfferAccepted(true)` → the agent has "nothing left" (858) until the bar is regenerated
  (108 drops off the 3-station stack).
- Greeting-only below state 3: 750-755 at random.

---

## 8. Save / load (v, `RecordHandler::recordStoreWrite` 0xdf760, `GameRecord::load`)

Order after `Status+0x10c`, `+0x110`: **`Status+0x114`** (int), `Status+0x111` (bool), storage items (`count`; per item
index, amount, single price, unsaleable bool), storage ships (`count`; per ship index, race), then hints[0x27],
options[0x35], options[0x36], …, later (after the marker 0x6e6a78) the storage ships' mods per ship. Load: state =
options[0x36] ? 3 : saved; when the saved station is 108, station 108's own ship list (from the recent-station stack
record) gets the storage mods re-applied. `resetGame`: state 0 (3 with the IAP), a fresh empty storage `Station`.
The siege itself is never saved (flight only; you can't dock mid-siege).

---

## 9. Other hooks (v)

| Where | What |
|---|---|
| `Status::departStation` 0xb63e0 | storage ↔ station 108 copies (`blueprints_mods.md` §3.2); also generates agents for 108 when it's not on the stack |
| `Achievements::checkForNewMedal` case 0x25 (medal 37 "Ship Collector", 1589) | `storage ship count ≥ threshold` (gold only, 50): **count of stored ships = distinct types** (§6.2); the current ship doesn't count |
| `ModStation::OnRender2D` 0xef208 | no news ticker at 108 |
| `Status::activateNewWanted` / `wantedBoardAccessible` | no Wanted board / wanted activation at 108 |
| `StarMap::drawOnScreenInfo` | Shima: security 3 when state > 1, icon 0x545 when state 3 |
| `ModStation::OnInitialize` state 100 | `computerTradeGoods` skipped at 108 |
| `Globals::playMusicAndFadeOutCurrent`, `Radar::draw` | music 146 in the 108 orbit |

No Status-window line for the club (the Status window reads nothing Kaamo-specific).

---

## 10. Implementation checklist (remake)

1. **Data/state** (`Session`): `KaamoState` (0-3, new game 0), `KaamoItems` (index, amount, price, unsaleable),
   `KaamoShips` (index, race, mods). `SaveGame` version bump; old saves → 0 / empty.
2. **Orbit** (`TrafficPlan`/`Traffic`, new `KaamoSiege` plain C# + a builder like `FreelanceOrbit`): at station 108 with
   state 0: 4 outposts (assembled `station_pirates`, positions §3.2, `Target` with hull §3.2 formula, hit cube ±7500
   units, `Obstacle` with the 12 volumes of `collision.json` 1002 using the static-object rule, no guns, no loot,
   name 441, race pirate), 6/8 pirate fighters in ±20000, respawn every 22.5 s while an outpost lives, win = all dead.
   Outpost death: wreck animation mesh 14246 20 s, then `Explosion` ×8, smoke, sound 20, wreck stays.
3. **Mission lock**: register the siege as the active mission (freelance slot overwrite optional — remake may keep the
   player's freelance mission and use a separate flag) so dock / gate / Khador / planet jumps give 525.
4. **Dialogues** (`StorySpace`/`DialogueView`): 457 at level ≥ 5 s → state 1 (voice 1468); success 458 (voice 1467),
   missions-completed +1, no reward. `StationMenu`: state 1 → 18-page table (§4.1, voices), state 2; state 2 → 476 /
   477 → pay 30 000 000 (check ≥ 30 000 001) + 50 Buskat → (479-484, remake) → 485 → state 3, clear 108 stock; autosave.
5. **Storage** (`Hangar`/`HangarWindow`): Store tab label 186, free transfers, no prices on items, ship rows with sell
   price and Use (332/333) / Sell (330/334) buttons, refuse unsaleable (323), one ship per type, rules §6.3-6.5
   including 327/328 at other stations (and skip or neutralise advert 189 — no IAP). Keep 108's stock and the storage
   as one list (simpler than the original's copy on arrival/departure).
6. **Hangar scene** (`StationLevel`): at 108 & state 3 park the first ≤ 3 stored ships (Midorian slots).
7. **Lounge** (`LoungeChat`): dealer 26 bare-hull ship into storage (state 3 only), candidate filter §7.
8. **Medal 37** (`Achievements`): stored ship count ≥ 50. **Star map**: icon 0x545 + "Secure" for Shima.
9. Music 146 in the orbit (already), 132 docked (already); no ticker (already).

---

## 11. Uncertainties

1. HUD treatment of the outposts (markers, lock plate text, whether the radar lock accepts a `PlayerFixedObject`) was
   not traced in `Radar::draw`; assumed like hostile ships.
2. Bullet hits use the ±7500 cube because `KIPlayer+0x3c` isn't set for 0x37a3 (the mesh is ~28 000 units across, so
   only shots near the core register) — worth a Play-mode sanity check; a remake may prefer the 12 volumes.
3. Player-vs-outpost push-out assumed to use the BV list like freighters (`ship_combat.md` §2.9); the ×0.6 / ×1.2 factors
   and the (a, c, −b) mapping come from the disassembly of `getBoundingVolume` and need a visual check against 14243.
4. The same-frame ordering that keeps `dialogueEvent` from showing 479-484 at the siege start (§3.6.3).
5. Whether closing the 18-page conversation has side effects via `ModStation+0x98` (assumed none: it isn't set).
6. Pirate fighters' behaviour without a route (assumed the default station-box patrol of `PlayerFighter::update`).
7. `Standing::applyMissionCompleted(4)` for the Multipod client assumed to be a no-op.
8. 3162/3163 may be sent by code outside the decompiled set (no literal found anywhere; voice table only).

---

## 12. Functions

| Function | Address | Use |
|---|---|---|
| `Level::createMission` | 0xbda70 | siege setup (station 108, state 0) |
| `Level::createStaticObject` | 0xcda54 | outpost object (0x37a3: radius 7500, hp, wreck 0x37a6, BV 1002) |
| `Level::getBoundingVolume` | 0xd3b78 | BV records → spheres ×0.6 / boxes ×1.2 |
| `Level::updateMissionOrbit` | 0xd4bd4 | pirate respawn every 22 500 ms |
| `Level::pirateStationAction` | 0xd6338 | outpost woken/destroyed (no-op at 108) |
| `Level::createScene` | 0xc2910 | parked stored ships |
| `PlayerFixedObject::PlayerFixedObject` / `update` | 0x17ece0 / 0x17f480 | loot (none at 108), death, ×8 explosion |
| `Gun::calcCharacterCollision` | 0x17e154 | cube hit test, mines skip `+0x3d` |
| `MGame::OnUpdate` | 0x1ac778 | 457 + state 1 |
| `MGame::successCheck` / `OnTouchEnd` / `dialogueEvent` | 0x1b0620 / 0x1a98d8 / 0x1b0498 | success 458, clean-up, briefing path |
| `MGame::dockEvent` / `UseKhadorDrive` | 0x1afebc / 0x1a9480 | 525 lock-outs |
| `DialogueWindow::loadContent` / `length` | 0x194cd0 / 0x195ca4 | 458 override, tables 0x25c5f0 / 0x25c680 |
| `ModStation::OnInitialize` / `OnTouchEnd` | 0xe8080 / 0xea4ec | states 1-3, purchase |
| `HangarWindow::initialize` / `transaction` / `OnTouchEnd` / `selectItem` | 0x171740 / 0x172820 / 0x176d94 / 0x178e20 | storage mode |
| `Station::addShip` / `hasShip` / `setShips` / `setItems` | 0xb3dd8 / 0xb3d02 / 0xb3b3a / 0xb3bce | one per type, cloning copies |
| `Ship::clone` / `makeShip` / `adjustPrice` | 0x1a4284 / 0x1a4270 / 0x1a433c | race reset, price |
| `SpaceLounge::onKeyPress` (offer 10) | 0x19c6fc | dealer ship into storage |
| `Generator::createAgents` / `generateStationIndex` | 0xa1fd0 / 0xa1e2c | 108 agents; 108 never a freelance target |
| `Status::departStation` / `resetGame` | 0xb63e0 / 0xba78c | storage copies; defaults |
| `RecordHandler::recordStoreWrite` / `GameRecord::load` | 0xdf760 / 0x180dc4 | save fields |
| `Achievements::checkForNewMedal` | 0x181ec0 | medal 37 |

Constants: `DAT_00251f90` pirate-base stations [1, 33, 47, 86]; `DAT_002543e0` their loot (item, count) pairs;
`DAT_00251e70` 52 stations never targeted by freelance missions (incl. 100-110); `DAT_00251f40` Kaamo dealer ships
[55..60]; `DAT_0026a1b0` / `DAT_0026a214` / `DAT_0026b8b8` = Mkkt Bkkt portrait [4, 2, 0, 2, 2].
