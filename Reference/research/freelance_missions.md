# Freelance missions and the bar (Space Lounge) conversation

Research for the remake: bar agents, their offers, freelance (side) mission generation, the chat flow, the missions
in space, completion/failure/payment, and how Wanted targets relate. Source: `libgof2hdaa.so` (Android HD), Ghidra
image base 0x10000. Text IDs index `Assets/Localization/text_en.json`. Game time in ms, distances in game units.
Tool: `Reference/tools/missions/mission_tables.py` (Python port of `createAgents` / `createAgent` / `createMission`;
`offers <station>`, `stats <station>`, `reward ...`). PRIVATE: all game data and texts stay local.

Related docs: `station_interior.md` §2.5 (bar visitors, agent count, visitor meshes), `shop.md` §4.2 (the 3-station
stack that also caches agents), `npc_traffic_ai.md` (free-flight traffic, `createShip`, standing), `mining.md`.

Confidence: **verified** = read in the decompile and checked in the disassembly; unmarked = read in the decompile;
*(assumed)* / *(uncertain)* = inference.

---

## 0. Summary

- Every bar has 3-5 agents (story agents from `agents.json` + generic ones). Generic agents offer: a freelance mission
  (46 %), small talk, an item for sale, a purchase request (a "Purchase" mission), or wingmen; a diplomat appears when a
  race hates you. Agents are generated **once per station while it stays in the 3-station stack** (`Status::departStation`).
- A mission is fixed when the bar is generated: type, target station, difficulty 1-9, cargo/ship/passenger counts,
  reward = `(int(d/10·5500)+1500)·(dist/1200+1)`·type factor `+ 10·level³`, plus a standing bonus of up to 100 %.
- **One freelance mission at a time** (`Status` missions array: [0] campaign, [1] freelance). Accepting a new one
  discards the old (confirm text 864). It can be discarded in the Missions window (station only).
- Missions without a timer except Junk removal (121 s). Space missions are resolved by level **objectives**
  (`Objective::achieved`); delivery missions on **docking** (`Status::missionCompleted`). Success: dialog, credits,
  +5 standing with the client's race, sound 36. Failure: dialog "Mission failed!", mission removed, the Challenge wager
  is taken from you. Leaving the orbit does not fail a mission *(inference: the orbit is rebuilt on return)*.

---

## 1. Agents

### 1.1 `Agent` class (game/Agent.c, ctor 0x1a65b4, 0x88 bytes)

| Offset | Field | Notes |
|---|---|---|
| +0x00 | name (String) | `Globals::getRandomName(race, male)` for generic agents |
| +0x08 / +0x0c | wingman friend names 1/2 (String*) | `setWingmanFriendNames` 0x1a675c |
| +0x10 | wingman friend count (0-2) | |
| +0x14 | system name (String) | set at every chat |
| +0x1c / +0x1d | "asked risk" / "asked map" flags | chat statistics (see §3.5) |
| +0x20 / +0x24 | chosen text IDs (greeting/offer variants) | reused when the text is rebuilt |
| +0x28 | -1 | |
| +0x2c / +0x30 / +0x34 | sell item index / quantity / price | `setSellItemData` |
| +0x38 | index | -1 = generic agent, else `agents.json` index |
| +0x3c / +0x40 / +0x44 | station / system / race | |
| +0x48 | male | |
| +0x4c | event (0 = never talked to; `isKnown` = event > 0) | set to 1 after the first chat |
| +0x50 | type: 0 story (`isStoryAgent`), 1 generic (`isGenericAgent`) | = `index >> 31` |
| +0x54 | **offer** (see 1.2) | |
| +0x58 | costs (wingmen / diplomat) | |
| +0x5c / +0x60 / +0x84 | sell system / sell blueprint / sell mod | from `agents.json` |
| +0x64 | mission string (the offer text shown on later chats) | |
| +0x6c | station name | |
| +0x74 | offer accepted | |
| +0x75 | "give reward at next chat" | not used by freelance code |
| +0x78 | image parts int[5] (portrait) | `ImageFactory::createChar` |
| +0x7c | Mission* | |
| +0x80 | Array of wingman names (agent + friends) | |

### 1.2 Offer codes (`Agent+0x54`)

| Offer | Meaning | Source |
|---|---|---|
| 0 | freelance mission (`Agent::getMission`) | generic |
| 1 | small talk (texts 820-840) | generic, or a 2nd wingman offer |
| 2 | sells an item | generic (and one campaign agent) |
| 3 | sells a blueprint | story (`sellBlueprint` ≥ 0) |
| 4 | sells system coordinates | story (`sellItemSystem` ≥ 0) |
| 5 | wants to buy goods = Purchase mission (type 8), created at the first chat | generic |
| 6 | wingmen for hire | generic |
| 7 | diplomat (rehabilitation for a hostile race) | generic replacement |
| 8 | sells a ship mod | story (`sellMod` ≥ 0) |
| 9 | Kaamo Club special item seller (agent index 25) | story |
| 10 | ship dealer (agent index 26) | story |

### 1.3 `Generator::createAgents` 0xa1fd0 (per station, from `Status::departStation` 0xb63e0)

Not in supernova systems. Called only when the arriving station is **not on the recent-station stack** (last 3
stations, `Status+0x19c`), together with the shop/ship lists (shop.md §4.2); agents, their offers and missions then
persist until the station drops off the stack.

1. `s` = story agents (`Status::getAgents`, = `agents.json`) whose station is this one, counted only if campaign
   mission > 16 and (DLC1 won or station ≠ 106). Count `n = s + 3 + nextInt(2)` if `nextInt(2) + s + 3 < 5`, else 5;
   station 108 (Shima pirate stronghold): only story agents. So 3-5 (station_interior.md §2.5).
2. Story agents first. Offer 9 (index 25): item `DAT_00251d10[k]` = [200, 220, 208, 213, 216, 228, 229, 230, 231],
   `k = nextInt(7)+2` (campaign < 0x8e) else `nextInt(9)`; quantity 10 for k = 3, 4 else 1; price = single price ×
   quantity; not accepted. Offer 10 (index 26): a random ship of [55..60] the player neither flies nor has in the Kaamo
   Club; price = ship price; if none is left the offer counts as accepted ("nothing left").
3. Campaign mission 23 at station 10: an extra agent (random Terran name, male) selling item 68 "AB-1 Retractor" for
   100 000 (offer 2; at campaign 24 its texts become 193/194).
4. The rest: `createAgent`. Only the first wingman offer (6) of a bar stays; later ones become small talk (1). Offer 0
   gets `createMission` immediately.
5. 35 %: for each race of `DAT_00251f80` = [2, 3, 0, 1] that is an enemy (`Standing::isEnemy`), the first generic agent
   whose offer ≠ 7 is replaced by a new male agent of that race with offer 7 (diplomat).
6. Campaign 23 at station 10, or 1 % otherwise: the first generic offer-0 mission with reward < 50 000 gets
   `reward = min(10·reward, 50 000)`.

### 1.4 `Generator::createAgent` 0xa26c0 (verified)

```
race = system race;  if nextInt(100) < 20: race = nextInt(8)            // 0 T, 1 V, 2 N, 3 M, 4 Multipod, 5 Cyborg, 6 Bobolian, 7 Grey
do offer = nextInt(7) while (race == 1 and offer == 6) or offer in {3, 4}   // Vossk never offer wingmen
if nextInt(100) < 33: offer = 0
elif offer in {5, 6} and campaign < 16: offer = 0
male = (race == 0 and offer != 6) ? nextInt(100) < 60 : true              // only Terrans can be female
name = getRandomName(race, male);  imageParts = ImageFactory::createChar(male, race)
offer 6: friends = nextInt(3); friend names = getRandomName(race); costs = (nextInt(1300)+700)·(friends+1) (hardcore ·7)
offer 2: item = nextInt(itemCount) re-rolled while index ∈ {131, 164, 175, 217, 218} or it has ingredients, price 0 or
         occurrence 0;  qty = type ∈ {primary, turret, equipment} ? 1 : nextInt(15)+5;
         price = int((nextInt(120)+40)/100 · singlePrice) · qty                // 40-159 % of the base price
```

Offer distribution (non-Vossk): 0 46.4 %, 1/2/5/6 13.4 % each (Vossk: 0 49.8 %, 1/2/5 16.8 %).

**Names** (`Globals::getRandomName` 0xf85a0, `FileRead::loadNamesBinary` 0x146290; `names.json`): first name from
`<race>_0` (Terran `terran_0_m` / `terran_0_w`), last name from `<race>_1`; Cyborg and Grey have first names only;
Midorians (3) pick Terran or Nivelian lists (two independent 50 % picks). "first last".

**Portrait** (`ImageFactory::createChar(male, race)` 0x14173c): `parts[0]` = set: race; Midorian → 75 % Nivelian (2),
25 % Terran (0); Cyborg → 0; female Terran → 10. `parts[1..4] = nextInt(count[set][k])`, counts at 0x258320:
0 [11,11,11,11], 1 [4,5,6,9], 2 [5,5,5,5], 4 [3,3,5,4], 6 [2,3,5,0], 7 [2,2,3,2], 8/9 [1,1,1,1], 10 [4,4,5,7]. Story
agents and Wanted targets store fixed parts (`portraitParts` in the JSON). Bar visitor meshes: station_interior.md.

**`agents.json`** = the 27 story agents: blueprint sellers (0-11, 16-18), coordinate sellers (12-15, 19, 20), mod sellers
at Shima (21-24; price = `ship price × DAT_00252090[mod]` % = 20/30/40/20, `Agent::getModPricePercentage`), the two
Zoboon brothers (25, 26). They give no freelance missions.

---

## 2. Mission generation (`Generator::createMission` 0xa2a7c, verified)

### 2.1 `Mission` class (game/Mission.c, 100 bytes; ctor 0x187ba8)

| Offset | Field |
|---|---|
| +0x00 / +0x01 | failed / won |
| +0x04 | Agent* (client) |
| +0x08 | type (-1 = `Mission::empty`) |
| +0x0c | client name; +0x1c image parts; +0x20 client race |
| +0x14 | target name (Wanted type) |
| +0x24 | reward |
| +0x28 | costs (**never read**: `Mission::getCosts` 0x188076 returns +0x24, the reward; only saved) |
| +0x2c | bonus (standing) |
| +0x30 / +0x34 / +0x3c | target station / its name / target system name |
| +0x44 | difficulty |
| +0x48 | instant-action mission |
| +0x4c | distance (`calcDistance`) |
| +0x50 | campaign flag |
| +0x54 / +0x58 | "production good" index / amount (cargo, ships, passengers, tons, item) |
| +0x5c | status value |
| +0x60 | visible |

Name = text `354 + type` (`Mission::getName`): 0 Courier, 1 Defense, 2 Protection, 3 Recovery, 4 Pirate hunting,
5 Salvage, 6 Wanted, 7 Junk removal, 8 Purchase, 9 Escort, 10 Intercept, 11 Passenger, 12 Challenge, 13 Informer,
14 Stolen goods, 15 Ore Mining. Types ≥ 0x96 are campaign types.

### 2.2 Target station (`Generator::generateStationIndex` 0xa1e2c)

```
loop:
    r = nextInt(100) < 20 ? agentStation
      : nextInt(100) < 40 ? random station of the current system
      : nextInt(135)
    if current system == 15 (Mido): r = random station of Mido
    accept if r ∉ DAT_00251e70 (52 stations: 1, 10, 11, 15, 22, 27, 29, 30, 33, 38, 40, 47, 48, 55, 56, 58, 60, 65, 66,
             70, 74, 76, 79, 80-83, 85, 86, 90-95, 98, 100-110, 113, 121, 126, 131)
          and the station's system is visible (Status::getSystemVisibilities)
          and r ∉ 109..113
          and (the system has jump routes or it is the current system)
```

In `createMission`: in Mido the target is `firstStation(Mido) + nextInt(4)` (75..78); Courier, Passenger, Stolen goods
(mask 0x4801) re-roll until the target ≠ the current station; Challenge and offer 5 use the agent's own station;
Informer (agent race < 4): if the agent's system has jump routes, re-roll until the target lies in a system of the
agent's race, otherwise the type becomes Defense or Pirate hunting (50/50).

### 2.3 Type

```
repeat up to 1000×: t = nextInt(15)                   // 0..14 — type 15 (Ore Mining) is never rolled in this binary
    t == 8 → re-roll (purchase only via offer 5); t == 10 and agent race > 3 → re-roll
    if !used[t]: used[t] = 1; accept                   // Status+0x50: 15 flags, cleared when 14 are set
campaign < 16: t = [11, 0, 7, 4, 12][nextInt(5)]       // Passenger, Courier, Junk, Pirate hunting, Challenge
offer 5: t = 8, target = agent station
```

So a player sees every type once before repeats (per game, not per bar). The `t == 15 && !options[0x37]` fallback in
the code is dead: Ore Mining (a Supernova-DLC type, fully supported by `Level::createMission`, §4.1) is unreachable
*(verified: `movs r1,#0xf` before `nextInt` at 0xa2b18)*.

### 2.4 Parameters

`d` = difficulty = `nextInt(9)+1` (campaign < 16: `nextInt(2)+1`); Purchase: the item's tech level; capped at 10.

| Type | good (+0x54) | amount (+0x58) |
|---|---|---|
| 0 Courier | `nextInt(7)` → description text 813+good (weapons, endangered animals, metals, radioactive waste, antique paintings, scrubs, fresh meat) | `int(d/10·95)+5` containers (14..90) |
| 2 Protection | – | `nextInt(4)+2` mining ships |
| 3 Recovery | 116 Secure Container | `int(d/10·8)+2` ships (2..9) |
| 5 Salvage | 117 Secure Cabin | `int(d/10·8)+2` ships |
| 6 Wanted | – | – ; target name = `getRandomName` (args lost in the decompile) |
| 8 Purchase | item `97+nextInt(itemCount−97)` with occurrence > 0, price > 0, no ingredients, ∉ {115, 116, 117, 131, 164, 175, 217, 218} | `nextInt(15)+5` |
| 11 Passenger | – | `int(d/10·18)+2` passengers (3..18) |
| 15 Ore Mining | one of the current station's 3 asteroid ores (`Galaxy::getAsteroidProbabilities`, `nextInt(3)`) | `nextInt(90)+30` t |
| others | – | – |

### 2.5 Reward, bonus, costs (verified constants)

```
dist  = Galaxy::distance(current system, target system)      // sqrt(dx² + dy² + (z/10)²) on systems.json mapPosition; max ≈ 109
base  = float(int(d/10·5500) + 1500) · (dist/1200 + 1)       // the distance adds at most ~9 %
type 9 Escort: ·1.2 | 7 Junk: ·0.7 | 3, 5: ·2 | 11 Passenger: 0.6·base + amount·(0.6·base/5)
type 8 Purchase: base = amount · item.maxPrice · 1.7
r = base + 10 · level³                                        // level = Status::getLevel 0..20 (npc_traffic_ai.md §2.2)
bonus  = types 8, 12: 0; else round50(r · Standing::getMissionBonus(agentRace))
reward = round50(r)
costs  = round50(int(reward/10 + nextInt(reward/10)))  (Purchase: ·0.5)      // unused (see 2.1)
round50(x) = x%50 ∈ {0, 25} ? x + x%50 : x − x%50              // i.e. down to 50, except a remainder of 25 rounds up
```

`Standing::getMissionBonus(race)` 0x142b34 = `max(0, s/100)` with s = s0 (Terran), −s0 (Vossk), s1 (Nivelian),
−s1 (Midorian), 0 for other races; so +0..100 %. The bonus is **recomputed with the current standing** every time the
offer text is built (`SpaceLounge::startChat`), shown as `#C` = reward+bonus followed by text 767
"(includes #P% standing bonus)". The level term dominates late: level 20 adds 80 000 to every mission.
Purchase rewards can be huge (tool: max ≈ 780 000 for 19 expensive items).

Finally: `Mission(type, agent name, agent image parts, agent race, reward, target, d)`, `setCosts`,
`setProductionGoods(good, amount)`, `setBonus`, `setTargetSystemName`.

---

## 3. The bar chat (`SpaceLounge::startChat` 0x198974, `onKeyPress` 0x19c6fc, `OnTouchEnd` 0x1a0360)

### 3.1 Offer text (first chat with a generic agent)

`Status+0xd0` (agents talked to) +1. Parts, joined with spaces, the question on a new line:

1. Greeting (not for offers 1, 7): `nextInt(6)` of 750-755, then `nextInt(2)` of 756/757 ("My name is #N" /
   "You're talking to #N").
2. Intro for offers 0 and 5: `nextInt(6)` of 758-763.
3. Body:
   - **0 mission**: text `786 + type` (#P, #Q, #S, #N), types 3/5 + 802 (needs EMP, scanner, tractor beam). #P = 813+good
     (Courier) or the item name 1274+good (Ore); #S = target station name, for Stolen goods the target **system** name;
     then "\n" + `nextInt(3)` of 764-766 with #C = reward+bonus (+ 767 bonus note when the bonus > 0).
     Challenge (12): only 798 (#C) — no greeting.
   - **1 small talk**: `nextInt(21)` of 820-840 without repeats within one lounge visit (`SpaceLounge+0x58` flags);
     line 16 (836) only from Terrans (others say 824), line 13 (833) only from men (women say 824); #S = random planet
     name, #N = agent name, #ORE = `nextInt(10)` of 1428-1437 (ore names). No question, no choices.
   - **2 item**: `nextInt(5)` of 768-772 + "\n" + 773/774 (#Q, #P = 1274+item, #C) (+ 775 "(#C per item)" if qty > 1).
   - **5 purchase**: creates the Purchase mission now; 777/778 (#Q, #P, #C = reward).
   - **6 wingmen**: 779 + friends (#C costs, #W = friend name); with all medals 782 + friends (they pay you #C).
   - **7 diplomat**: not an enemy (any more) → 883, no deal; else by race 878 (Nivelian), 880 (Midorian), 881 (Terran),
     882 (Vossk), #C = `int(|standing axis| / 100 · 16000)` (s0 for Terran/Vossk, s1 for Nivelian/Midorian).
4. Question: "\n" + `nextInt(3)` of 841-843 ("OK?" / "What do you say?" / "Interested?").

The text is stored in `Agent+0x64` (`setMissionString`); `Globals::getAgentMissionText` 0xfa7d4 rebuilds it from the
stored text IDs (used by "What was that?" and the Missions window). The voice line: `SpaceLounge::getSoundId` 0x19fdb4.

**Story agents** (event 0): offers 3/4/8/9/10 start with 874/875 + the agent's line `886 + index`, then e.g. 876
(blueprint #N #C), 877 (coordinates #S #C), 879 (upgrade #SHIP_NAME #N #C) + question. Accepted → 858.

**Later chats** (known agent, offer ≠ 7): accepted → 857 (purchase), 859 (wingmen or Challenge), else 858 "I don't
have anything left, sorry."; not accepted → the stored offer text again (mission offers re-evaluate the bonus).

### 3.2 Choices (state 2)

| # | Label | Shown |
|---|---|---|
| 0 | 860 "Okay." | always |
| 1 | 861 "No thanks." | always |
| 2 | 862 "What was that?" | always |
| 3 | 804 "Show it on the map." (missions) / 776 "Let me see it." (offers 2, 3, 8, 9, 10) | missions and sellers |
| 4 | 807 "What's the risk?" | missions (5 entries), sellers have 4, others 3 |

- **Decline**: `nextInt(5)` of 845-849; `Status+0xe0` +1. The offer stays open.
- **Repeat**: the stored text; `Status+0xe4` +1.
- **Map**: target = this station → 805 "right here in orbit"; in this system → 806; else the star map with the mission
  (`StarMap(true, mission, …)`). Sets `Agent+0x1d`.
- **Risk**: text `808 + int(d/10·5)` (808 child's play … 812 very difficult). Sets `Agent+0x1c`.
- **Accept** → confirmation (`ChoiceWindow`):
  - Courier: needs free cargo ≥ amount (`Ship::spaceAvailable`), else 337 "You need at least #Qt of free cargo space.".
  - Passenger: needs `Ship::getMaxPassengers` ≥ amount (cabins), else 338.
  - generic: 865 "Accept #M mission? Reward: #C." (#M = type name, #C = reward+bonus); story: 863; with an active
    freelance mission + " " + 864 "Your current mission will be discarded."
  - sellers: price check (203 "You need an additional #C."), offers 8-10 at **double price when `options[0x38]` is
    off** *(uncertain: probably the "premium"/unlocked flag)*; confirm 868 item, 869 blueprint, 870 coordinates,
    871 upgrade, 873 ship. Wingmen: 866 / 867 (fans), already hired → 785. Diplomat: 885 "Rehabilitate for #C?".

### 3.3 After "Yes" (`onKeyPress` tail)

Text `nextInt(3)` of 850-852, then per offer:

- **0 / 5 mission**: hardcore: pay `(reward+bonus)/10` up front (203 if short). An active freelance mission is
  discarded: containers item 116 removed for Courier/Recovery/Salvage (the unsaleable stack), passengers = 0 for
  Passenger, a story client's offer re-opened. Courier: **item 116 "Secure Container" × amount, unsaleable**, added to
  the cargo; Passenger: `Status::setPassengers(amount)` (`Status+0x34`). Text: Challenge 856 (see you outside), else +
  `nextInt(3)` of 853-855. Statistics: accepted without asking the risk → `Status+0xe8` +1, without the map →
  `+0xec` +1 *(uncertain: medal counters)*. `Status::setFreelanceMission(mission)`, `mission.setAgent(agent)`.
- 2 item / 9 special: pay, add the item (secondaries merge into a mounted stack); items 132-153 mark a specialty flag.
- 3 blueprint: pay, `BluePrint::unlock`. 4 coordinates: pay, `setSystemVisibility`, star map opens. 8 mod: pay,
  `Ship::addMod`. 10 ship: pay, the ship goes to the Kaamo Club storage and the station.
- 6 wingmen: `Status+0xd4` += friends+1 (hired count), `setWingmen(names)`, wingman race `Status+0x2c`, contract
  `Status+0x30` = 600 000 ms, portrait; pay `costs` (or receive it with all medals).
- 7 diplomat: `Standing::rehabilitate(race)` 0x14289c: s0 = −35 (Terran) / +35 (Vossk), s1 = −35 (Nivelian) /
  +35 (Midorian) — just inside the neutral band; pay `costs`.
- `setOfferAccepted(true)` (not for mods). The visitor stays in the bar.

### 3.4 Missions window (`MissionsWindow::init` 0x17a604, `OnTouchEnd` 0x17bbc0)

Title 129 "Missions", tabs 555 "Story" / 556 "Freelance" (+ 3219 "Most Wanted" when `Status::wantedBoardAccessible`).
Freelance pane: the agent's stored offer text with #C = reward+bonus and the agent's portrait, or 174 "-BLANK-".
Buttons 424 "Show on map" (star map with the mission) and, only in a station (module 5), 423 "Discard" (red) →
418 "Are you sure?" → same clean-up as a discard in 3.3, freelance = empty. Help 635. `Status::getMaxMissions` = 2.

### 3.5 Statistics touched

`Status+0xd0` agents talked to, `+0xe0` declines, `+0xe4` repeats, `+0xe8` / `+0xec` accepts without risk / map
question, `+0x9c` containers delivered, `+0xb8` passengers delivered, `+0x1c4` missions completed
(`incMissionCount`, part of the level XP: `2·missions`).

---

## 4. In space

### 4.1 Which orbit becomes a mission orbit (`Status::departStation` 0xb63e0)

On every orbit change the level mission (`Status+400`, `Status::getMission`) is reset to empty and then set to the
freelance mission when **its target station is the new orbit's station** and its type is not 8, 14 (dock-only),
11 or 13. So Courier (0) also makes the target orbit a mission orbit (with no enemies, see below). Returning to the
orbit later rebuilds the mission from scratch.

`Level::createMission` 0xbda70: an empty level mission → free-flight traffic (npc_traffic_ai.md §2). In **every**
free-flight orbit a freelance Courier, Passenger or Ore mission adds `int(d/10·5)` pirate "escorts" that spawn around
the player (npc_traffic_ai.md §2.3 group 5) — carrying cargo or passengers attracts pirates. An active Informer (13)
at its target station: only 7 local fighters (6 once the informer is dead), the first named 1663 "Informer", no
jumpers/freighters/raiders.

A non-empty freelance level mission **replaces** the free-flight traffic (verified: the type switch at 0xbddd6 is
reached instead). `hc = 1 + (difficulty − 0.5)` = ×1 normal, ×2 hardcore. Attack race `A` = 75 % pirates (8), else
`getEnemyRace(system race)`; client-race enemy `E = getEnemyRace(clientRace)` = [1, 0, 3, 2][race], else 8. Routes are
int triples; `Route(p, 3)` = one waypoint. Level `+0x28` = success objective, `+0x2c` = failure objective.

| Type | Spawns | Success / failure objective |
|---|---|---|
| 1 Defense | `n = int((int(d/10·5)+3)·hc)` race-A fighters, always enemy, around the station (no waypoint, ±20 000 jitter); `nextInt(5)+3` system-race friends on route (x±50 000, 0, 50 000) → (…, 75 000) → (…, 100 000), always friend | 7: the n attackers dead |
| 2 Protection | `n = int(d/10·4)+2` race-A attackers at `wp0 = (−20000−nextInt(20000), 0, −20000−nextInt(20000))`, spaced +2000 per ship, heading to (0,0,0); `amount` system-race mining ships parked 2000 above asteroids (half-way into the asteroid list), not moving, 3× HP, always friend | 0x12 attackers [0,n) dead / 0x12 miners [n, n+amount) all dead |
| 3 Recovery, 5 Salvage | `amount` pirates asleep at (±(40000+nextInt(80000)), 0, ±(40000+nextInt(80000))); the last is the crate carrier named 1611 "Hijacker" (`PlayerFighter::setMissionCrate`: loot = 1× item **117 for type 3, 116 for type 5** — swapped against the offer, verified 0xf0872) | 0xb carrier's cargo taken (EMP + tractor) / 0xc carrier destroyed before |
| 4 Pirate hunting | 1-waypoint route at `Level+0xc8` (the asteroid-field point) or `createRoute(2..3)`; `int((int(d/10·5)+2)·hc)` pirates asleep on it | 0x12 all dead |
| 6 Wanted | one pirate asleep at (±(60000+nextInt(80000)), 0, ±(…)), max HP ×3, speed 3.0, `setRotate(3)` | 1: enemy 0 dead |
| 7 Junk removal | `int(d/10·20)+15` space junk statics (0x4215), always enemy, at (nextInt(40000)−20000, nextInt(20000)−10000, 40000+nextInt(30000)); + `int(0.2·d)` pirates; **time limit 121 000 ms** (`Level+0x130`); sound 22 loaded | 7: all junk destroyed |
| 9 Escort | `n = int((int(d/10·5)+3)·hc)` race-E attackers asleep on route (10000,0,100000) → (10000,0,150000) → (10000,0,200000); 5 client-race freighters (ship 15, Vossk 13) as fixed objects at fixed points ((−2500,−300,27000), (6500,3000,24000), (−4000,−2000,19000), (9000,−6000,17000), (3000,7000,15000)), moving +Z, HP `(2·min(level,20) + 150 + 2·campaign(45 once won)) · (1.4 hardcore)`, always friend | 0x12 attackers dead / 0x12 all 5 freighters dead |
| 10 Intercept | race E (pirates → Terran): `nextInt(2)+2` convoy freighters (ship 15/13) asleep, not moving, around wp1 ±10000 of route (±2500, ±2500, 80000+nextInt(30000)) → (…, 120000+nextInt(30000)), HP ×0.7 (×1.4 hardcore); `int((int(d/10·5)+3)·hc)` escorts asleep on the route | 7: the convoy freighters dead |
| 12 Challenge | route `createRoute(3..4)`; the agent's own ship (agent race, invulnerable 9 999 999 HP, speed 3.0, named after the agent, follows the route, friend) + an odd number of pirates asleep: `i = int(d/10·4)`, pirates = `i+3` if odd else `i+4` | 0x14: all pirates dead and player kills > rival kills / 0x15: all dead and player kills ≤ rival kills (`Level+0x24` player kills, `+0x20` kills by others — wingmen count as others) |
| 15 Ore Mining | `int((int(0.2d)+1)·hc)` race-E enemies on a 1-waypoint route (±70 000, 0, 70 000); mining plant static 0x4a88 at the asteroid waypoint (`Level+0xd8`), docking type 1; 2 client-race haulers looping plant ↔ plant−30 000 z, never attack | 0x1c: delivered ore ≥ amount |
| 0, 8, 11, 13, 14 | nothing | – |

`Objective::achieved` 0xa36fc types used: 1 enemy[i] dead, 3 time ≥ value (survival), 7 first N enemies dead,
0xb / 0xc enemy[i] flag +0x65 / +100, 0x12 enemies [a,b) all dead, 0x14 / 0x15 Challenge, 0x1c / 0x1d delivered
ore / passengers ≥ N. Others (0 all dead, 5 all friends dead, 8-10 asteroids, 0x13 friend cargo stolen, 0x16 last
radio message over, 0x1a any of [a,b) dead, 0x1b fewer than N left, 0x1e enemy dying) serve campaign missions.

### 4.2 Briefing (`MGame::dialogueEvent` 0x1b0498, `DialogueWindow(mission, level, 0)`)

After the launch/arrival sequence, if the level mission is visible and its type is not 0, 8, 11 (freelance) or
0xa6/0xb7: a dialog from the client (portrait + name): Challenge 372, Junk removal 378, else `nextInt(5)` of
379-383. The game pauses while it is open.

### 4.3 Success (`MGame::successCheck` 0x1b0620)

Checked while the player lives and the mission has not failed, once the level is older than 5000 ms:
`Status::missionCompleted(docked = false)` or the success objective (`Level::checkObjective`).

- **Recovery / Salvage** (3/5): the dialog shows 389 "Return to #S to collect your reward." with the client's
  station; the mission turns into type **11** with target = the agent's station, status −1, not won; the agent's
  stored text becomes 803 "Now get the valuable container back to #S"; the orbit reverts to a plain orbit (level
  mission empty, objectives and player route removed). Delivery then works like a Passenger mission (§5).
- Others: `incMissionCount`, success dialog (mode 1) → after closing (`MGame::OnTouchEnd` ~0x1ab3xx):
  `setFreelanceMission(empty)`, `Layout::showMissionRewardMessage(reward+bonus)` (sound 36 Mission_accomplished),
  `Status::changeCredits(reward + bonus)` (no cap here), level mission empty.

Success dialog text (`DialogueWindow::loadContent` 0x194cd0, mode 1): Challenge 370 (#Q1 : #Q2 = kill score; + 389
for story clients); types 3/5 389; otherwise `nextInt(5)` of 373-377 + "\n\n" + 216 "Mission accomplished!" (story
client: + 389 with its station). Target station 108: 458. **Standing**: `Standing::applyMissionCompleted(clientRace)`
0x142b26 = `applyDelict(race, −5)` → **+5 toward the client's race** (hardcore +10), applied when the dialog content
loads *(uncertain whether a multi-page dialog applies it more than once; freelance success dialogs are one page)*.

### 4.4 Failure (`MGame::gameOverCheck` 0x1b0d04)

- The failure objective (`Level+0x2c`) achieved → failure dialog (mode 2).
- Time limit: `LevelScript[0]` (= `Level+0x130`, only Junk removal among freelance) checked every 5000 ms: elapsed ≥
  limit and the success objective is not a survival objective → failure dialog.
- Dialog: `nextInt(5)` of 384-388 + "\n\n" + 392 "Mission failed!". After closing: **Challenge: `changeCredits(−reward)`
  (the lost wager)**; types 3/5/11: the unsaleable container 116/117 removed; freelance mission = empty; objectives,
  level mission, player route cleared. No standing change.
- Player death: the normal game over (sound 37), reload of the last save — the mission is restored with it.

### 4.5 HUD / radar

No dedicated freelance HUD was found beyond the normal enemy/friend markers and object names ("Hijacker",
"Informer", the agent's name); `Radar::draw` 0x1554fc draws a mission icon at the planet lock of the campaign
mission's target station (the freelance mission is read in the same block; *(uncertain whether it also gets the
icon)*). The star map marks the target (`StarMap(true, mission, …)`).

---

## 5. Docking: delivery and payment (`ModStation::OnUpdate` 0xed2a8, `OnTouchEnd` 0xea4ec)

Every frame while docked with no dialog open: `Status::missionCompleted(docked = true, loungeIntroFinished)` 0xb924c:

| Type | Completed when docked at … |
|---|---|
| 0 Courier, 11 Passenger (and 3/5 after conversion) | the target station (the cargo itself is **not** checked) |
| 8 Purchase | the target (= the agent's) station with `amount` × item in the cargo (`Item::isInList`) |
| 13 Informer | any station, once the informer died (`Status+0xf0`) |
| 14 Stolen goods | the agent's station with item 115 "Documents" in the cargo |

→ success dialog (mode 1, standing +5) → on closing: Purchase removes `amount` × item; Passenger: passengers = 0,
`Status+0xb8` += amount, the container 116/117 (3/5) removed; Courier: the container 116 removed, `Status+0x9c` +=
amount; Stolen goods: item 115 removed. Then `incMissionCount`, reward message (sound 36),
`changeCredits(reward + bonus)` — **if reward+bonus ≥ 1 000 001 only 6 666 is paid** (a guard at 0xeaaee; campaign
0x37/0x3a/0x3d pay 200 000/100 000/50 000 instead), `Status::removeMission` (also clears `Agent::setMission`), the
lounge refreshes. Informer: `Status+0xf0/0xf1` cleared and an autosave.

`Status::missionFailed(docked = true)` 0xb91f4: an Informer whose flag `Status+0xf1` is set (another ship was killed
in the target orbit, `PlayerFighter::update` ~0xf1cb0) → failure dialog on docking, mission removed.

Stolen goods: docking at the **target station** puts 1× item 115 "Documents" into its stock if missing
(`ModStation::OnInitialize` ~0xe99e0); the player buys it at the normal price and brings it to the client.

---

## 6. Wanted (bounty) targets

Separate from the agents and from freelance type 6 (a random pirate). Data: `wanted.json` (25 entries: name, `board`
0-3 = race of the board, race, ship, weapon, hit points, loot/lootAmount, reward 50 000-140 000, `requiredBounties`,
`requiredMission` (campaign), `numWingmen`, portrait). `Wanted` (game/Wanted.c): + active, terminated, current
location, travels-to, last seen.

- **Board** (`MissionsWindow` tab 3219 "Most Wanted", `WantedWindow` 0xf4a58): accessible when some entry's board =
  the system race, campaign ≥ its `requiredMission`, not in the Kaamo/108 special case (`Status::wantedBoardAccessible`
  0xba1f8). Details: 3223 departed from / 3224 travelling to / 3225 bounty / 3226 status 3227 deceased / 3228 alive.
- **Activation** (`Status::activateNewWanted` 0xba2ac, on docking): entries of this board with the campaign
  requirement met and `requiredBounties` ≤ kills on that board become active at a random reachable station (not in
  systems 6, 25-28, visible, with routes); 3230/3231 "New info on N Most Wanted criminals".
- **Movement** (`Status::moveWanted` 0xb6858, on each orbit change): toward `travelsTo` one gate per jump; on arrival a
  new destination 2..4+ jumps away (`SystemPathFinder`).
- **In orbit** (`Status::getWantedInCurrentOrbit` 0xb916c): the wanted replaces local fighter 0 (local fighters ≤ 2,
  npc_traffic_ai.md §2.3 1a) with `numWingmen` wingmen; radio messages on `Level::uncoverWanted` 0xd63ac (scanned)
  and `attackWanted` 0xd642c (wingmen turn hostile), `killWanted` 0xd65c8. Kill (`PlayerFighter::update`):
  terminated, reward message + `reward` credits. Storyline wanteds 0/1 surrender at 1/3 HP (`almostKillWanted`).
- Killing Most Wanted 6, 12, 18, 24 unlocks ships 45-48 at station 107 (`Generator::getShipBuyList`).

---

## 7. Uncertainties / not traced

- `Globals::getRandomName` argument decoding for the Wanted target name and wingman friends (the decompile lost them;
  assumed agent race for friends, Terran for the Wanted name).
- The exact meaning of `options[0x38]` (doubles story-offer prices when off) and of the chat statistic counters.
- Where the tractored crate of types 3/5 enters the cargo (the carrier's loot list is `[item, 1]`; the normal crate
  pickup is assumed).
- `Level+0xc8` (Pirate hunting route point) = the asteroid-field waypoint *(assumed from its use for the mining plant)*.
- Whether the success-dialog standing change repeats per page; the radar icon for the freelance target.
- `Globals::getDialogueSoundId` (voice lines for the dialogs) not mapped.

## 8. Function index

| Function | Address |
|---|---|
| Generator::createAgents / createAgent / createMission / generateStationIndex | 0xa1fd0 / 0xa26c0 / 0xa2a7c / 0xa1e2c |
| Agent::Agent / setWingmanFriendNames / getModPricePercentage | 0x1a65b4 / 0x1a675c / 0x1a698c |
| Mission::Mission (full) / getName / getCosts (bug) / calcDistance | 0x187ba8 / 0x188000 / 0x188076 / 0x188140 |
| SpaceLounge::startChat / onKeyPress / OnTouchEnd / getSoundId | 0x198974 / 0x19c6fc / 0x1a0360 / 0x19fdb4 |
| Globals::getAgentMissionText / getRandomName | 0xfa7d4 / 0xf85a0 |
| FileRead::loadNamesBinary / ImageFactory::createChar | 0x146290 / 0x14173c |
| Standing::getMissionBonus / applyMissionCompleted / rehabilitate | 0x142b34 / 0x142b26 / 0x14289c |
| Status::departStation / missionCompleted / missionFailed / removeMission | 0xb63e0 / 0xb924c / 0xb91f4 / 0xb9878 |
| Status::getFreelanceMission / setFreelanceMission / getMaxMissions / incMissionCount | 0xb6bf6 / 0xb6c00 / 0xb6c80 / 0xb6c84 |
| Level::createMission / checkObjective / checkGameOver / enemyDied | 0xbda70 / 0xd62f0 / 0xd6324 / 0xd3f98 |
| Objective::Objective / achieved | 0xa3600, 0xa3612 / 0xa36fc |
| PlayerFighter::setMissionCrate | 0xf0818 |
| MGame::successCheck / gameOverCheck / dialogueEvent / dockEvent | 0x1b0620 / 0x1b0d04 / 0x1b0498 / 0x1afebc |
| DialogueWindow::loadContent | 0x194cd0 |
| ModStation::OnUpdate / OnTouchEnd / OnInitialize | 0xed2a8 / 0xea4ec / 0xe8080 |
| Layout::showMissionRewardMessage | 0xe7648 |
| MissionsWindow::init / OnTouchEnd | 0x17a604 / 0x17bbc0 |
| Status::wantedBoardAccessible / activateNewWanted / moveWanted / getWantedInCurrentOrbit | 0xba1f8 / 0xba2ac / 0xb6858 / 0xb916c |
| Level::uncoverWanted / attackWanted / almostKillWanted / killWanted | 0xd63ac / 0xd642c / 0xd64b0 / 0xd65c8 |

---

## Remake implementation notes

Plain C# (unit-testable), MonoBehaviours only for the scene side. `UnityEngine.Random` (or an injected `System.Random`)
is fine: the original's RNG is time-seeded, nothing here is reproducible.

- **`GoF2Agent`** (data): name, race, male, station, offer (enum `AgentOffer`), portrait parts[5], known, accepted,
  sell item/qty/price, costs, wingman names, `GoF2Mission Mission`, chosen text IDs, stored offer text.
- **`GoF2Mission`** (data): type (enum `FreelanceType` 0..15), client name/race/portrait, agent ref, target station,
  difficulty, good, amount, reward, bonus, targetName, failed/won. Serialise with the save (the original saves the
  freelance mission with its agent, `RecordHandler::writeMission`).
- **`GoF2AgentGenerator`**: `CreateAgents(station, session)` / `CreateAgent` / `CreateMission` /
  `GenerateStationIndex` exactly as §1.3-2.5 (port `mission_tables.py`); keep the 15-flag "types used" array and the
  purchase-offer-creates-mission-at-first-chat rule. Store the result on the station entry of the existing 3-station
  cache in `GoF2Session` (the shop already keeps the last 3 stations' stock there) so agents persist with the stock.
  Free play is campaign 20, so the early-type table and the offer-5/6 lock do not apply; story agents from
  `agents.json` count because campaign > 16.
- **`GoF2LoungeChat`** (plain C#): builds the offer text from text IDs (§3.1, `GoF2Localization.Get` + `#`
  replacements), the choice list (§3.2) and applies an accepted offer (§3.3) against `GoF2Session` (credits, cargo
  with an "unsaleable" flag for items 115-117, passengers, standing, wingmen). The Station menu gets a Space Lounge
  visitor list/tap → chat panel (UI Toolkit) with the portrait (`ImageFactory` parts → the character atlas; not yet
  cut) and the 3-5 choice buttons.
- **`GoF2FreelanceMissions`** (plain C#, in `GoF2Session`): one active mission; `OnDepart(station)` decides whether the
  new orbit is a mission orbit (§4.1); `OnDocked(station)` = `missionCompleted/missionFailed(docked)` (§5) returning
  a result for the station UI (dialog text IDs, payout with the 1 000 001 guard, standing +5, cargo clean-up,
  Documents into the target station's stock for type 14).
- **`GoF2MissionOrbit`** (MonoBehaviour, next to `GoF2Traffic` in the Space scene): when the level mission is set,
  spawn §4.1 instead of the free-flight traffic using the existing `GoF2NpcShip` / `GoF2Target` (asleep = the
  "sleeping" state, always-enemy/friend flags, HP multipliers), and evaluate the success/failure objectives
  (`GoF2Objective` plain C# with the §4.1 kinds, polled once the level is 5 s old); junk removal needs the space-junk
  prop and a 121 s timer (HUD countdown). Recovery/Salvage need EMP + salvage lock on the carrier (not implemented in
  combat yet: "EMP weapons against NPCs" is on the NPC to-do list), Challenge needs per-killer kill counters, Escort
  and Intercept need NPC freighters as fixed objects (the traffic freighters can be reused).
- Carrying Courier/Passenger/Ore missions adds `int(d/10·5)` pirates around the player in free-flight orbits — hook
  into `GoF2TrafficPlan`.
- Briefing / success / failure dialogs: a `DialogueWindow`-like overlay in the flight HUD (pauses the game), texts per
  §4.2-4.4, reward message + sound 36 (`Mission_accomplished`).
- Missions window: a Freelance pane in the station menu (offer text, reward, portrait, Show on map → `GoF2StarMap`
  with a target marker, Discard with 418 confirmation).
- Type 15 (Ore Mining) is unreachable in the original generator; keep it out of the remake's roll (or enable it
  deliberately as a remake-only option, since `Level::createMission` supports it).
