# Blueprints, ship mods, Kaamo Club storage

Research for the Hangar window's **Blueprints** tab (production), the Kaamo **ship mods** and the Kaamo Club **storage**
(stored ships and goods), plus the "system coordinates" offer. Builds on `shop.md` (Hangar window, prices, ship trade),
`freelance_missions.md` (lounge agents, offer codes, chat flow) and `campaign_flow.md` (story steps). Those docs are not
repeated here; where they had only a summary (`shop.md` §7) this document is the detailed version.

Helper: `python Reference/tools/blueprints/blueprint_table.py` prints the whole blueprint table (ingredients, base
quantity, autocomplete price, unlock source), the hidden-wreck table, the mod table and the Kaamo tables, reading the
constants from `libgof2hdaa.so`; `... json OUT` writes the same as JSON (the data file a remake would ship).

Marks: **(v)** verified in the decompiled code / disassembly, **(a)** assumed or inferred.
Addresses use Ghidra base 0x10000. Text ids index `Assets/Localization/text_en.json` (array index).

---

## 1. Blueprints

### 1.1 Where the table lives (v)

There is no separate blueprint file. `data/bin/items.bin` stores for every one of the 233 items three int arrays:
**ingredients, quantities, attributes** (`FileRead::loadItemsBinary` 0x145f48 → `Item::Item(ingredients, quantities,
attributes)` 0xf3f1c; `Item+0x28` ingredients, `+0x2c` quantities, `+0x30` attributes). An item is a **blueprint
product** when its ingredient array is non-null. `parse_bins.py` already decoded these into `items.json` → `blueprint`
(list of `{item, name, amount}` in file order). There are **25** such items.

`Status::resetGame` 0xba78c creates **one `BluePrint` per product**, in item-index order, into `Status+0x18`
(`Array<BluePrint*>`), **all locked**, and deletes the pending-product list (`Status+0x1c` = null).

### 1.2 The table (v, from items.bin; unlock sources §1.4)

`x10` = base quantity 10 (secondaries, `BluePrint::BluePrint`: `Item::getType == 1 → 10`, else 1): one production run
yields 10 missiles/rockets. Autocomplete = §1.6. "(bp)" = the ingredient is itself a blueprint product, "(vol)" =
volatile (can't be shipped, §1.5).

| # | Product | Qty | Ingredients (amount × item) | Autocomplete $ | Unlock |
|---|---|---|---|---|---|
| 11 | M6 A3 "Wolverine" (laser) | 1 | 1 × 9 M6 A1 "Wolf", 50 × 155 Titanium, 75 × 120 Plastics, 20 × 126 Noble Gas, 20 × 122 Energy Cells, 20 × 129 Optics | 134 973 | agent 0 Geryan Zhamoum, st. 3 Gählon, 49 999 $ |
| 15 | H'nookk (blaster) | 1 | 1 × 12 N'saan, 15 × 130 Hydraulics, 10 × 129 Optics, 10 × 122 Energy Cells, 1 × 166 Titanium Core, 10 × 125 Mech. Supplies | 65 501 | agent 1 Tulant Kheont, st. 32 Duhnu, 36 998 $ |
| 25 | 128MJ Railgun | 1 | 1 × 24 64MJ Railgun, 4 × 125, 2 × 121 Nanotech, 2 × 122, 5 × 120, 5 × 127 Microchips | 33 358 | agent 2 Leskar, st. 20 Kallsta Omba, 19 999 $ |
| 27 | Mass Driver MD 10 | 1 | 1 × 26 Scram Cannon, 55 × 154 Gold, 14 × 122, 16 × 125, 20 × 127, 27 × 130 | 150 578 | agent 3 Per Magnusson, st. 54 K'mirkk, 59 999 $ |
| 33 | Amour Rocket | 10 | 1 × 118 Electronics, 1 × 120 | 1 262 | agent 4 Pete "Big P" Bizon, st. 43 Arpalys, 1 999 $ |
| 37 | Intelli Jet | 10 | 2 × 128 Com. Devices, 1 × 129, 2 × 127, 1 × 125 | 3 412 | agent 5 Obb Porff, st. 10 Thynome, 2 999 $ |
| 46 | AMR Extinctor (nuke) | 10 | 40 × 124 Radioactive Goods, 20 × 114 Explosives, 7 × 128, 5 × 127, 10 × 125, 10 × 118 | 62 100 | agent 6 Mykkba Numkk, st. 5 Decimus, 5 999 $ |
| 54 | Fluxed Matter Shield | 1 | 80 × 163 Hypanium, 100 × 118, 75 × 125, 90 × 121, 80 × 127 | 349 946 | agent 7 Fabio Neroni, st. 14 K'ane, 59 998 $ |
| 59 | T'yol (armor) | 1 | 40 × 157 Orichalzine, 20 × 168 Orichalzin Core, 80 × 156 Iron, 45 × 125, 30 × 120, 100 × 122 | 229 222 | agent 8 Tennox Ykkt, st. 51 Rr'ostam, 79 999 $ |
| 67 | Rhoda Blackhole (compression) | 1 | 50 × 118, 10 × 122, 50 × 125, 50 × 130 | 138 375 | agent 9 Alan P. Tahoe, st. 90 Festus, 39 999 $ |
| 85 | Khador Drive | 1 | 50 × 164 Void Crystals, 200 × 158 Pyresium, 200 × 160 Doxtrite, 30 × 163, 100 × 118, 150 × 125, 150 × 127, 120 × 129, 125 × 122 | 828 653 | campaign step 34 |
| 90 | Gunant's Drill | 1 | 90 × 121, 80 × 125, 90 × 130, 10 × 166 Titanium Core, 40 × 155 | 295 142 | agent 11 Gunant Breh, st. 78 Var Hastra, 129 999 $ |
| 96 | Yin Co. Shadow Ninja (cloak) | 1 | 100 × 126, 80 × 119 Chemicals, 80 × 130, 100 × 129, 80 × 127, 125 × 124 | 361 176 | agent 10 Dr. Muktin Kobus, st. 59 E'kkide, 39 999 $ |
| 178 | Icarus Heavy AS (scatter) | 1 | 1 × 27 Mass Driver MD 10 (bp), 90 × 125, 70 × 121, 50 × 122, 5 × 171 Doxtrit Core, 1 × 186 Nirai Overdrive, 5 × 166 | 548 746 | agent 16 Samuel Ballam, st. 105 Var Destro, 200 000 $ |
| 179 | Liberator (nuke) | 10 | 10 × 44 AMR Tormentor, 100 × 124, 250 × 114, 150 × 127, 125 × 118, 175 × 129, 215 × 157, 25 × 166, 160 × 122 | 1 066 412 | agent 18 Miguel Parham, st. 106 Sao Perula, 1 000 000 $; campaign step 58 |
| 182 | HH-AT "Archimedes" (turret) | 1 | 1 × 47 Hammerhead D1, 2 × 15 H'nookk (bp), 100 × 118, 120 × 125, 100 × 127, 100 × 128, 100 × 129, 40 × 168, 40 × 166 | 665 578 | agent 17 John Bowens, st. 107 Quineros, 700 000 $ |
| 183 | Disruptor Laser | 1 | 30 × 118, 25 × 121, 10 × 155, 8 × 168, 10 × 172 Cesogen Core, 30 × 120, 28 × 126, 50 × 122, 1 × 175 Void Essence | 233 192 | campaign step 72 |
| 206 | Gamma Shield II | 1 | 1 × 205 Gamma Shield I, 200 × 119, 150 × 121, 100 × 163, 25 × 172, 250 × 122 | 733 227 | campaign step 104 |
| 210 | Chromo Plasma (commodity) | 1 | 930 × 201 Green Plasma, 930 × 202 Blue Plasma, 930 × 203 Purple Plasma, 930 × 204 Red Plasma (vol) | 2 000 000 + remaining value (§1.6) | campaign step 141 |
| 221 | Ion Lambda Mk2 | 10 | 10 × 197 Ion Lambda Mk1, 2 × 173 Perrius Core, 40 × 114, 20 × 124 | 109 512 | hidden wreck, st. 133 Merxde |
| 223 | Pandora Leech (transfusion beam) | 1 | 200 × 122, 90 × 129, 1 × 222 Crimson Drain, 300 × 204 Red Plasma (vol), 10 × 218 Novanium Core | 681 371 | hidden wreck, st. 134 Selbah |
| 225 | Particle Shield | 1 | 80 × 163, 55 × 118, 12 × 120, 45 × 121, 100 × 122, 50 × 127, 250 × 201, 250 × 202, 5 × 218, 1 × 54 Fluxed Matter Shield (bp) | 976 043 | hidden wreck, st. 129 Va'lerrm |
| 226 | Shock Blast | 10 | 25 × 114, 25 × 122, 10 × 118, 8 × 126, 30 × 203 Purple Plasma | 98 812 | hidden wreck, st. 132 Bervegor |
| 227 | Phoenix SIS (shield injector) | 1 | 5 × 118, 5 × 119, 50 × 122, 1 × 210 Chromo Plasma (bp) | 1 125 757 | hidden wreck, st. 123 Shelán |
| 232 | Fireworks (nuke) | 10 | 10 × 114, 1 × 210 Chromo Plasma (bp) | 19 665 625 | all gold + all Supernova medals |

Notes:
- Ingredients are ordinary commodities, ores/cores, plasma and **items** (weapons, shields, a turret, Ion Lambda Mk1
  missiles...). Item ingredients must be in the **cargo hold** (demount them first); mounted items never count. (v)
- Products never appear anywhere else (v): `Generator::getItemBuyList` 0xa05c4 skips items with ingredients (none has an
  exclusive-station attr 61), `Generator::getLootList` 0xa1b78 and `Generator::createAgent` 0xa26c0 (offer 2) and
  `Generator::createMission` 0xa2a7c re-roll them. The only sources are production and the campaign/story gifts.
- Economics (tool output, ingredients at their base price `(min+max)/2`): most products cost ~60–80 % of their max price
  in ingredients; T'yol costs more in ingredients (192 590) than it sells for (183 378); Fireworks sells for 15.7 M per
  10 against 0.78 M of ingredients.

### 1.3 `BluePrint` object (0x28 bytes, verified field use)

| Off | Field | Set by |
|---|---|---|
| +0x00 | `Array<int>` **remaining** amount per ingredient (same order as items.bin) | ctor copies the quantities; `addItem` subtracts; `complete` zeros; `reset` restores |
| +0x04 | **money spent** (Σ units × the added item's single price); `isEmpty()` = money spent == 0 = "not started" | `addItem`, `setMoneySpent`, `reset` → 0 |
| +0x08 | unlocked (bool) | `unlock` 0x1a6536; **`lock` 0x1a653c also writes 1** (disassembly: `movs r1,#1; strb r1,[r0,#8]`) — a bug, nothing can re-lock |
| +0x0c | times produced | `reset` +1 |
| +0x10 | **production station** index, −1 = none | `addItem` on the first add, autocomplete of an empty blueprint |
| +0x14 | production station name (String) | same |
| +0x1c | product item index | ctor |
| +0x20 | base quantity (10 secondaries, else 1) | ctor |
| +0x24 | quantity of the current run (= base) | ctor, `reset` |

Functions (all v): ctor 0x1a6044, `addItem(item, n, station)` 0x1a6154, `getIngredientList` 0x1a62a4 /
`getQuantityList` 0x1a6304 (the product's items.bin arrays), `complete` 0x1a62bc (remaining = 0), `isCompleted` 0x1a62d8
(no remaining > 0), `getTotalAmount(item)` 0x1a631c, `getRemainingAmount(item)` 0x1a6398, `getCurrentAmount(item)` =
total − remaining 0x1a6378, `getCompletionRate` 0x1a63dc, `getIngredientsValue` 0x1a6454, `getAutoCompletionPrice`
0x1a64c8, `isEmpty` 0x1a6542, `reset` 0x1a6550.

- `addItem(item, n, station)`: if n ≠ 0: `item.blueprintAmount = 0`; find the ingredient slot with this item index:
  `remaining[k] -= n`, `moneySpent += item.singlePrice × n`; if `station ≥ 0` and the blueprint has no station yet, it
  becomes the **production station** (name from the current station or `Galaxy::getStation`). Only the first matching
  slot is used.
- `getCompletionRate` = **mean over ingredients of (total − remaining) / total** (0..1; each ingredient weighs the same,
  regardless of amounts). The list shows it as a bar plus "N%  (station)" (the percent conversion is lost in the
  decompile, (a) `int(rate·100)`).
- `reset` (after a production run): times produced +1, **`Status::incGoodsProduced(1)`** (`Status+0x1d4`), remaining =
  quantities, money spent 0, station −1, quantity = base. The blueprint stays unlocked and can be produced again any
  number of times.

### 1.4 Unlocking (v)

All 25 start locked (`resetGame`). Sources:

1. **Story agents in the Space Lounge** (offer 3, `agents.json sellBlueprint` ≥ 0; 15 agents, table §1.2). They are
   created with the station's agents only when the campaign index is **> 16** (and station 106 Sao Perula only after the
   Valkyrie add-on is won), see `freelance_missions.md` §1.3. Offer text: 874/875 "Psst... Hey!" / "Oh, a potential
   customer!" + the agent's line **886 + agent index** + **876** "The blueprint for #N costs #C." (#N = 1274 + product),
   "Let me see it" (776) opens the item details window for the **product** (`ListItemWindow::set`, not the recipe).
   Accept → 203 if credits < price, else confirm **869** "Buy #P blueprint for #C?" → pay `sellItemPrice`
   (agents.json price, **no VIP doubling**, offers 8–10 only), `BluePrint::unlock`, offer accepted (later chats 858
   "I don't have anything left, sorry.") (`SpaceLounge::onKeyPress` 0x19c6fc).
2. **Campaign** (`Status::nextCampaignMission` 0xb6c98; the case is the old index, the step reached is old + 1). Some
   unlocks come with ingredients **pre-invested** by `addItem` (so the blueprint is already started, with a fixed
   production station):

   | Step reached | Blueprint | Pre-invested | Production station |
   |---|---|---|---|
   | 34 (case 0x21) | 85 Khador Drive | the 50 Void Crystals delivered at step 33 (removed from cargo) | 10 Thynome |
   | 58 (case 0x39) | 179 Liberator | 5 × 127 Microchips; mission 0xa6 "bring 10 × 179 to 101"; own ship given back | 101 Valkyrie |
   | 59 (case 0x3a) | 179 | `BluePrint::lock` — no effect (bug above), the Liberator stays unlocked | – |
   | 72 (case 0x47) | 183 Disruptor Laser | none; +1 × 175 Void Essence into cargo (the recipe needs exactly 1) | – |
   | 104 (case 0x67) | 206 Gamma Shield II | 10 × 163 Hypanium; mission 0xa6 "bring 1 × 206 to 10" | 10 Thynome |
   | 141 (case 0x8c) | 210 Chromo Plasma | 847 Green, 834 Blue, 861 Purple, 892 Red plasma (remaining 83 / 96 / 69 / 38) | 112 Var Lupra |

3. **Hidden blueprints in Supernova wrecks** (`Station::stationHasHiddenBlueprint` 0xb3ec8, `getHiddenBlueprintIndex`
   0xb3f08; tables `DAT_0025273c` stations, `DAT_002521f0` blueprints, `DAT_00253754` wreck race, `DAT_00253768`
   positions; found flags `Status+0x58` bool[5], saved):

   | k | Station (system) | Blueprint | Wreck `createShip(race, kind 1, ship)` | Position (game units) | Radio text (a) |
   |---|---|---|---|---|---|
   | 0 | 132 Bervegor (32 Skor Terpa) | 226 Shock Blast | race 1 Vossk, ship 13 (Vossk freighter) | (−20000, 30000, 80000) | 3156 |
   | 1 | 133 Merxde (33 Alda) | 221 Ion Lambda Mk2 | race 3 Midorian, ship 15 (freighter) | (40000, −30000, 100000) | 3157 |
   | 2 | 134 Selbah (33 Alda) | 223 Pandora Leech | race 2 Nivelian, ship 15 | (−80000, 80000, −90000) | 3158 |
   | 3 | 129 Va'lerrm (31 Wah'norr) | 225 Particle Shield | race 0 Terran, ship 15 | (40000, 20000, 140000) | 3159 |
   | 4 | 123 Shelán (29 Paráah) | 227 Phoenix SIS | race 2 Nivelian, ship 15 | (40000, 20000, 140000) | 3160 |

   - `Level::createMission` 0xbda70 always spawns the wreck in these orbits: a dead-but-selectable
     `PlayerFixedObject` with **docking type 3** (hackable); while not yet found its flag `+0x6c` is set and it carries
     loot `Generator::getLootList(115, 1)` = 1 × item 115 Documents. `Level::connectPlayers` 0xcc330 keeps it among the
     dock targets while the station has one.
   - Docking with it (`PlayerEgo::update` 0xa8ed0) starts a **HackingGame(0, 4, −1, −1, target)** (2nd argument 4, 1 at
     campaign 91; (a) a difficulty/size) and `Hud::setHackingGameActive(true)`. Won → `Status::unlockBluePrint(DAT_002521f0[k])`, the wreck's
     flag and loot are cleared, docking type 0, `Level::createRadioMessage(level, k + 0x15, 0)`, `Status+0x58[k] = 1`.
     The radio texts 3156–3160 match the five blueprints by content (Shock Blast, Ion Lambda, Pandora, Particle Shield,
     shield injector) (a: the id mapping of message k + 0x15 was not traced).
   - Skor Terpa and Alda have no gate routes: their coordinates are sold by agents 19 (system 32, 5 000 000 $) and 20
     (system 33, 8 000 000 $), and a Khador Drive is needed to get there (see §3.4).
   - `SolarSystem::hasHiddenBlueprint` 0x180b20 (system still holds an unfound one) has **no callers** (v).
4. **Fireworks (232)**: `ModStation::checkHints` 0xee500: not unlocked and `gotAllGoldMedals` and
   `gotAllSupernovaMedals` → text **651** "…As reward you received a new blueprint for fireworks.", unlock, autosave.

### 1.5 Hangar window: Blueprints tab and ingredients list (v)

Tabs (`shop.md` §2): 0 Ship, 1 Shop, **2 Blueprints (272)**, 3 unused, **4 ingredients** (no tab button; opened from 2).
There is **no gate by station, tech level or race**: the tab works in every station hangar (only the Hangar button's own
locks apply: campaign < 5, 48, 49, 56; station 4 with the pirate base). The only station rules are the production
station (below) and: blueprints **210 and 223 can't be started in a system without gate routes** (`SolarSystem::getRoutes`
null → text **528** "Not available.", `HangarWindow::setSellMode`). (`GameRecord::load` 0x180dc4 moves a started 210 / 223
whose station lies in such a system to station 10 Thynome — a save fix-up.)

**Tab 2 list** (`HangarList::initBlueprintTab` 0x143208):
- header **273** "Available blueprints", then one row per **unlocked** blueprint (item-index order): product icon
  (`ImageFactory::drawItem`), name 1274 + idx, and when the completion rate > 0 a progress bar (images 0x475 frame,
  0x476 fill clipped to `rate × width`, 0x477 end cap) + "N%  (production station)".
- The name is drawn in a highlight colour ("green", help 625) when **any ingredient still needed is in the cargo hold**
  (`HangarWindow::refreshCargoAvailabilityForBlueprints` 0x172c28, row flag `+0x45`; colour constant not recovered).
- if there are pending products: header **274** "Products finished", then one row per product: "N× " (only if N ≥ 2)
  + name + " " + **275** "at" + " " + station name. They can't be selected for editing.
- Row buttons on the selected row: **info** (details window of the product item, also for pending products) and
  **Edit** (button 7, text **283**).
- Help button: **625** (tab 2), **626** (tab 4).

**Edit → tab 4** (`HangarWindow::selectItem` 0x178e20 → `HangarList::fillIngredientsList` 0x14378c, `setCurrentTab(4)`):
- header row = product name; one row per ingredient: the **cargo stack** if the ship carries that item, else the item
  template (amount 0); every row's pending `blueprintAmount` (`Item+0x3c`) = 0; a last empty row carries the
  **"Autocomplete"** button (button 23, style 7; the label is a hard-coded English string, not a text id).
- Selecting an ingredient ("trade mode", like the Shop tab): left column label **183** "Ship" with the cargo amount
  "Nt", right column label **271** "Blueprint" with "(invested + pending)t/total t". Button 9 (right arrow) is shown
  when cargo > 0, button 8 (left arrow) when something is invested.
- **Right arrow** = `HangarWindow::transaction(true)` 0x172820 on tab 4: if `blueprintAmount < remaining` →
  `Item::transactionBlueprint(item, 0)` 0xf40cc: cargo amount −1, `blueprintAmount` +1, ship load −1, pending counter
  `+0x94` +1; the cargo stack is kept in sync. Holding repeats exactly like buying (200 ms, then 30 ms after 1.5 s,
  5 per repeat after 4 s; `shop.md` §2.1). No money changes hands for the transfer itself.
- **Left arrow** = `transaction(false)`: on tab 4 it does nothing (only the sync) — invested goods **can't be taken
  back**, neither committed nor pending (v; `transactionBlueprint` mode 1 exists but is never called).
- **Starting**: when an ingredient is selected while the blueprint is empty (`isEmpty`) and the ship has some of it:
  ChoiceWindow **212** "Start production at this station?" (210 / 223 without routes: 528 instead and the selection is
  dropped). No → the ingredient is deselected. Yes → trade mode; the station becomes the production station at the
  first commit (`addItem(..., currentStation)`).
- **Commit** (`setSellMode(false)` 0x176594, when the selection leaves the ingredient or the list is closed):
  `BluePrint::addItem(item, blueprintAmount, currentStation)`. Partial investing is normal: every commit is stored in
  the blueprint (remaining, money spent) and **persists** across stations and saves until the run completes.
- **Shipping cost** (`HangarWindow::OnTouchBegin` 0x175c74, checked before the commit): pending units > 0, blueprint
  not empty, current station ≠ production station →
  - ingredient **209 K'mirkk Toad Mutagen or 204 Red Plasma** (volatile): **289** "Volatile goods can't be shipped and
    must be delivered directly to the station." — the transfer is always reverted;
  - otherwise **288** "Shipping these items to #S will cost you #C." (#S = production station, **#C = 200 $ × pending
    units**) → Yes and enough credits: pay and commit; No: revert (cargo amount, pending amount, credits, load restored);
    Yes without the money: revert + 203 "You need an additional #C.".
  (Help tip 346: "Add components to a blueprint at the same station where construction began to save on transportation
  costs.")
- **Autocomplete** (button 23, `OnTouchEnd` 0x176d94): confirm **195** "Autocomplete blueprint for #C?" → credits <
  price: 203 (+124 IAP question); else: an empty blueprint takes the current station as production station, `complete()`
  (remaining = 0), credits −price, then the normal completion below. The price does **not** depend on progress (§1.6).
- **Completion** (in `setSellMode(false)`, when `isCompleted()`):
  - production station == current station → **211** "#N constructed and moved to cargo hold." → `Item::makeItem(product,
    quantity)` added to the cargo (no cargo-space check, like buying), the window switches to the **Shop tab (1)**;
    secondaries already mounted are merged into the mounted stack (`autoEquipSecondaryWeapons`).
  - else → **210** "#N constructed. Fetch it at #S." → `Status::addPendingProduct(bp)` 0xb606a (merges into an existing
    pending entry with the same product and station: quantity added) and back to tab 2.
  - then `BluePrint::reset` (times produced +1, goods produced +1, ready for another run).
- **Back** from tab 4 → commit (`setSellMode(false)`) and return to tab 2; `readyToClose` 0x178da0 refuses to close the
  window while an uncommitted shipment to another station is pending (the shipping question comes first).
- Messages 207–213 are the Hangar's shared message texts (`shop.md` §9); 213 below.

**Collecting pending products** (`ModStation::checkPendingProducts` 0xee258, once per docking from `ModStation::OnUpdate`
0xed2a8 when no window is open): every pending product whose station is this one is added to the cargo (no space check)
and removed; one ChoiceWindow **213** "The following items have been moved to your cargo hold:" + "\nN× name" per
product. Special case: at campaign index 146 a pending Chromo Plasma (210) here is deleted instead — and the function
returns immediately, skipping the rest of the list and the message (v; looks like a bug). The star map marks stations
holding pending products with icon 0x452 ("products finished", `StarMap::drawOnScreenInfo`, `starmap_travel.md`).

### 1.6 Prices (v)

- Autocomplete (`BluePrint::getAutoCompletionPrice` 0x1a64c8): **`(int)((float)(baseQuantity × maxPrice) × 1.25f)`**
  (maxPrice = items.json `maxPrice`, attr 8), a constant per blueprint regardless of how much is invested. Chromo
  Plasma (210) instead: **2 000 000 + Σ remaining × single price** of each ingredient item (`getIngredientsValue`; the
  global item templates keep `(min+max)/2`, (a) they are not repriced), i.e. 2 199 950 $ untouched, **2 013 883 $**
  after the step-141 pre-investment.
- "Money spent" is only used as the started flag; it is not refunded or shown. Shipping: 200 $ per unit.

### 1.7 Save data (v, `RecordHandler::recordStoreWrite` 0xdf760 / `recordStoreRead` 0xdc6e4, `GameRecord::load`)

After the two standing ints: `count`, then per blueprint (in `Status+0x18` order): remaining[ingredientCount] (ints),
moneySpent (int), unlocked (bool), timesProduced (int), stationIndex (int), stationName (String). The read side creates
the BluePrints from the current table's indices, so the order must match. Then the pending products: `count` (−1 when
the list is null; null entries skipped), per product: item index, quantity, station index, station name. Hidden-blueprint
found flags: `count` + bool[5] (`Status+0x58`), written among the hint flags. `Status+0x1d4` goods produced is in the
statistics header (`GameRecord+0x28`).

### 1.8 Statistics and medals (v)

- `Status+0x1d4` "Goods produced" (text **558**): +1 per completed run (not per unit), shown in the Status window
  (`StatusWindow::draw` 0x183a64); mission type 0x9b compares it (no story step uses it).
- Medal **13** "Owned at least # blueprints." (1565): number of unlocked blueprints; thresholds gold 13 / silver 6 /
  bronze 3 (`UNK_00259860[13]`, `Achievements::checkForNewMedal` 0x181ec0).
- Medal **14** "Finished at least # different blueprints." (1566): blueprints with times produced > 0; 13 / 6 / 3.
- The medal hint (`StatusWindow::getMedalHintText` 0x185da4, header 276 "Still missing:") lists the missing ones among
  the **first 13** blueprints only (items 11 … 96, the main-game set).
- Fireworks reward: §1.4.

---

## 2. Ship mods

### 2.1 What a mod does (v, `Ship` 0x1a4404 …)

`Ship+0x78` = `Array<int>` of installed mod ids; `Ship::addMod(id)` ignores an id that is already installed (each mod
at most once per ship) and calls `refreshValue`.

| Mod | Effect | Getter | Seller (Kaamo, station 108) | Price % of the current ship | Offer text (#N) |
|---|---|---|---|---|---|
| 0 | **+40 hull** | `getMaxHP` 0x1a3906 = armor + 40 per mod 0 (also `getCombinedHP`) | agent 21 Jelka Lithgow | 20 | 907 (#N 40) |
| 1 | **+30 t cargo** | `getModdedLoad` 0x1a450e; `refreshValue` adds 30 to cargoPlus before compression (`shop.md` §3.3) | agent 22 Nemor Kalant | 30 | 908 (#N 30) |
| 2 | **+1 equipment slot** | `addMod`/`setMods`: `slots[3] += 1`, `+0x7c` added-slot count +1 (only while it is 0), one empty equipment entry appended | agent 23 Tedanor | 40 | 909 |
| 3 | **handling +0.2** (handling/100 units, i.e. +20 handling) | `getHandling` 0x1a3878 / `getHandlingForShop` 0x1a382c = base + 0.2 per mod 3; so the flight model's `H = (handling/100 + 0.2·upgrades)…` (CLAUDE.md) | agent 24 Longwei Zhou | 20 | 910 (#N 20) |

(`DAT_00252090` = [20, 30, 40, 20], index > 3 → 40; `DAT_00254400` = (mod, #N) pairs (0,40) (1,30) (2,1) (3,20).)

### 2.2 Buying (v, `SpaceLounge::startChat` 0x198974, `Globals::getAgentMissionText` 0xfa7d4, `onKeyPress`)

- The Kaamo agents 21–26 exist at station 108 once the campaign index is > 16 (only story agents there). Radio 3163
  announces the mechanics and dealers.
- At every chat the price is recomputed: **`sellItemPrice = currentShip.price × pct / 100`** (`Ship::getPrice`, the
  adjusted price of the ship you fly).
- Already installed on the current ship → 858 "I don't have anything left, sorry.". Else text 874/875 + " " + **886 +
  agent index** + … + 907–910 with #SHIP_NAME = 913 + ship, #N from the table, + **879** "This upgrade costs #C.".
- Accept → price check and confirm **871** "Buy upgrade for #C?" → pay → `Ship::addMod(mod)`. The offer is **not** marked
  accepted (offer 8 is excluded), so the same mechanic sells the mod again for the next ship.
- **VIP card** (`options[0x38]`, IAP "Kaamo Club VIP Card", texts 80 / 90 / 95): offers 8, 9 and 10 (mods, special items,
  ships) **cost double without it** (credit check and payment use ×2.0) — this resolves the "premium flag" uncertainty
  in `freelance_missions.md` §3.2. (a) the displayed #C is probably doubled too (the float factor is lost in the
  decompile).

### 2.3 Mods belong to the hull (v)

- Ship purchase (`HangarWindow::OnTouchEnd` ship branch): the new ship gets **the mods of the ship being bought** (e.g. a
  stored ship's mods), not the old ship's; the old ship's mods go with it into the dealer row / the Kaamo storage.
  `Ship::clone` 0x1a4284 copies mods.
- Details window (`ListItemWindow::set` 0x159468, ship): Armor (165) shows `getMaxHP` + " (+)" when above the base,
  Cargo hold (166) `getModdedLoad` + " (+)", Equipment slots (269) base + added + " (+)", Handling (164)
  `getHandlingForShop·100` + " (+)" when modded; the comparison column uses the current ship's **base** values.

### 2.4 Save (v)

After the item-seen flags and the marker int 0x6e6a78: mods of the current ship (`count`, ids), of the parked own ship
(`Status+0x8c`, loaner steps), of every Kaamo storage ship (per ship `count`, ids) and of the ships of every station on
the recent-station stack (+ the current station). `RecordHandler::writeAgent` 0xe1034 also writes `sellModIndex` for
agents with index > 18.

---

## 3. Kaamo Club (station 108, Shima system 26)

### 3.1 Owning the club (v)

`Status+0x114`: 0 not owned, 1 intro dialogue shown, 2 purchasable, 3 owned. The Android build also sells it as an IAP
(`options[0x36]`, "Kaamo Club" text 78 / 88 / 93): `ndk_iapBoughtPremium` 0x9f2e8 and `MenuTouchWindow::update`
0x14ffec set state 3; `resetGame` starts at 3 when the option is owned, else 0.

In-game route:
1. State 0, orbit 108 (`Level::createMission`): 4 static objects `0x37a3` named 441 "Pirate Outpost" at fixed
   positions + 6 pirate fighters (8 in hardcore); a free "destroy" mission (type 4, client 1601 "Mkkt Bkkt") targets
   them. `MGame::OnUpdate` 0x1ac778: on success at station 108 → dialogue (457 …) and state **1**.
2. Docking with state 1 (`ModStation::OnInitialize` 0xe8080): a won pseudo-mission (type −1, client 1601, station 108)
   opens its success conversation and the state becomes **2**; (a) that conversation is texts 460–466 (Mkkt Bkkt
   offers the station for buskat; 479–484 are the purchase conversation).
3. Docking with state 2: credits ≤ 30 000 000 or less than 50 × item 109 **Buskat** → **476** "Dock with 50 tons of
   buskat … and 30 million credits …"; else **477** "…Pay 50 tons of buskat and 30 million credits now?" → Yes
   (`ModStation::OnTouchEnd` 0xea4ec): −30 000 000 $, −50 Buskat, state **3**, **485** "You are now the proud owner of a
   space station…", the station's and the storage's item lists are cleared. (478 offers the IAP menu instead.)
   Note the check is `credits ≥ 30 000 001` (v, `< 0x1c9c381` refuses).

### 3.2 Storage model (v)

- `Status+0x14c` = a hidden **storage `Station`** (created empty in `resetGame`) with its own item list and ship list.
- `Status::departStation` 0xb63e0: arriving at 108 while owned copies the storage's items and ships **into** station 108
  (and into its stacked copy); leaving 108 copies station 108's items and ships back into the storage. So at the club
  the storage simply *is* the station's stock and dealer list. 108 gets no generated stock or ships
  (`getItemBuyList` / `getShipBuyList`), and `computerTradeGoods` skips it (`shop.md` §4).
- The hangar scene at 108 parks the stored ships on the pads (`Level::createScene` 0xc2910; `station_interior.md`).
- Medal 37 (0x25): stored ships ≥ 50 ("Parked at least # different ships on Kaamo.", 1589).

### 3.3 UI flow (v, `HangarWindow` in storage mode `+0x11d` = station 108 and state 3)

- Tab 1 is labelled **186 "Store"** instead of 185 "Shop"; no prices are drawn and every transfer is free
  (`Item::transaction(buy, load, free = true)`): the left column is the storage, the right column the cargo. Storage has
  no capacity limit (text 88 "infinite cargo space"); the ship's cargo limit only blocks launching (204).
- Stored ships are listed as the station's ships. Row buttons: **332 "Use"** (button 1) → **333** "Do you want to switch
  ships?" → switch for free: the stored hull becomes the current ship (race kept, its own mods), cargo is cloned over and
  every mounted item is re-mounted (first free slot of its type, else cargo); the old ship takes its place in storage
  (`makeShip(old)` + old mods). **330 "Sell"** (button 10) → **334** "Do you want to sell this ship?" → credits + ship
  price, removed from storage.
- Buying a ship at any dealer while owning the club: **327** "Do you want to sell your old ship or keep it and have it
  brought to your station?" with **330 Sell / 331 Keep**. Sell = normal trade-in (`shop.md` §5). Keep: storage already has
  that type → **328** (cancelled); credits < full new price → 203; else pay the **full** price and the old hull goes to
  storage (`Station::addShip(storage, makeShip(old))` + its mods; equipment and cargo move to the new ship, so stored
  ships are bare hulls). Without the club: advert **189** → Yes opens the add-on menu (`ModStation::showDlcMenu`
  0xefd64), No = trade-in.
- Stored ships are bare hulls (index + race + mods only are saved, §3.5).

### 3.4 Kaamo lounge dealers (v; generation in `freelance_missions.md` §1.3)

- Agent 25 Jakk Zoboon (offer 9): one special item of [200 PE Fusion H2, 220 Spectral Filter Omega, 208 Nirai SPP-M50,
  213 T'Suum, 216 Patala, 228 M6 A4 "Raccoon", 229 Dark Matter Laser, 230 Mass Driver MD 12, 231 Mimung Blaster]
  (`DAT_00251d10`); confirm 872/868; pays ×2 without VIP; secondaries merge into a mounted stack, else cargo.
- Agent 26 Umnar Zoboon (offer 10): one ship of [55 Groza Mk II, 56 Berger Cross Special, 57 Kinzer RS, 58 Phantom XT,
  59 Teneta R.E.D., 60 Darkzov] (`DAT_00251f40`) that the player neither flies nor stores; price = ship price. **Only
  with the club owned** (state < 3 → a greeting 750–755 and nothing else). Confirm **873** "Buy ship for #C?" → pay (×2
  without VIP) → `makeShip` added to the **storage and to station 108's list** (use it via "Use").
- Offer 4 **system coordinates** (agents 12 Ylook Pykku → system 0 Suteo 25 000 $, 13 Dyloon Jakoon → 1 Pan 10 000 $,
  14 Cyphron → 10 Y'mirr 500 000 $, 15 In'shkkt Typpt → 21 Ni'mrrod 30 000 $, 19 Okk Lyrrt → 32 Skor Terpa
  5 000 000 $, 20 Tebar Ceroon → 33 Alda 8 000 000 $): text 877 "The coordinates for system #S will cost you #C.",
  confirm **870**, pay (no VIP factor), **`Status::setSystemVisibility(system, true)`** and the star map opens on that
  system (`StarMap(false, null, true, system)`). A visible system is drawn, selectable and reachable on the galaxy map
  (`starmap_travel.md`: hidden systems aren't drawn); Y'mirr, Skor Terpa and Alda have no gate routes, so they still need
  a Khador Drive.

### 3.5 Save (v)

`Status+0x114` (int), then the storage's items (`count`; per item index, amount, single price, unsaleable) and ships
(`count`; per ship index, race), plus the storage ships' mods (§2.4). `options[0x36]` / `[0x38]` are option flags
(saved with the options).

---

## 4. Remake implementation notes

### 4.1 Data

Generate `Resources/GoF2Data/blueprints.json` with `blueprint_table.py json` (or read `items.json → blueprint`
directly; JsonUtility can already read that list). Per entry: `item`, `baseQuantity`, `ingredients[] {item, amount}`,
`needsGateRoutes`, unlock info. Keep the constants in code (they are few):
`HiddenStations {132,133,134,129,123}`, `HiddenBlueprints {226,221,223,225,227}`, wreck race/ship/position, volatile
items {204, 209}, shipping 200 $/unit, autocomplete 1.25 / 2 000 000, mod table (§2.1), Kaamo lists (§3.4).

### 4.2 Plain C# (unit-testable, `GoF2Remake.Data`)

- `GoF2Blueprint` (one per product; mirrors `BluePrint`): `Item`, `Remaining int[]`, `MoneySpent`, `Unlocked`,
  `TimesProduced`, `StationIndex` (−1), `Quantity`; `AddItem(item, n, station, unitPrice)`, `IsEmpty`, `IsCompleted`,
  `CompletionRate`, `CurrentAmount(item)`, `AutocompletePrice()`, `Complete()`, `Reset()`.
- `GoF2BlueprintBook` (session state; `Session.Blueprints` + `PendingProducts`): `Unlock(item)`, `IsUnlocked`,
  `AddPending(item, qty, station)` (merging), `CollectAt(station) → list` (docking), `GoodsProduced`,
  `HiddenFound bool[5]`.
- `GoF2Workshop` (one opening of the ingredients list, like `Hangar`): `Select(ingredient)` → `NeedsStartConfirm`
  (empty and cargo > 0) / `Refused528`; `MoveOne()` (cargo → pending, capped by remaining); `Commit()` returns
  `NeedsShipping(cost)` / `Volatile` / `Committed` / `Completed(atThisStation)`; `Revert()`; `Autocomplete(credits)`.
  Keep the "no take-back" rule and the 200 $/unit shipping.
- `GoF2ShipMods` or fields on the ship state: `int[] Mods` per owned ship; `MaxHull = armor + 40·has(0)`,
  `Cargo = base + 30·has(1)`, equipment slots + has(2), handling/100 + 0.2·has(3) (feed `FlightModel`).
- `GoF2KaamoStorage`: `Items` (same stack type as cargo), `Ships (index, race, mods)`, `Owned` state 0–3.
- Save: extend `SaveData` (bump version) with blueprints (per product: remaining[], unlocked, timesProduced,
  station), pending products, hidden flags, goods produced, per-ship mods, storage items/ships, Kaamo state.

### 4.3 UI Toolkit (Hangar window, `UI/Station`, next to the Ship / Shop tabs)

1. **Blueprints tab**: list sections "Available blueprints" (273) and "Products finished" (274); blueprint row = icon
   (`Resources/GoF2Icons/item_XXX`), name (accent colour when an ingredient is in cargo), progress bar + "N% (station)";
   selected row shows Info and Edit (283). Pending row = "N× name at station" (+ Info).
2. **Ingredients view** (replaces the list, Back returns to the tab): header = product name + a small summary (base
   quantity, production station or "not started"); one row per ingredient: icon, name, left "Ship Nt" and right
   "Blueprint a/b t" with a → arrow (hold to repeat, same repeat curve as the shop) and no ← arrow (or a disabled
   one, to be faithful); footer button Autocomplete (price in the confirm, 195). Confirms via the existing dialog: 212,
   288 (#S, #C), 289, 195, 203; result notes 210 / 211; docking note 213.
3. Keyboard/controller: reuse the Shop tab bindings (select row, → / RB move one, hold to repeat, Back = Esc / B).
4. The star map's "products finished" icon (0x452) and the Status window's "Goods produced" line can follow later.
5. Kaamo: when docked at 108 with the club owned, rename Shop → Store (186), hide prices, make transfers free, and add
   Use / Sell buttons on stored-ship rows; the ship purchase flow gains the 327 Sell/Keep question. Mods: lounge offer
   8 flow + the "(+)" marks in the ship details panel.

### 4.4 Remake decisions to make

- Free play (`Session.FreePlay`) and the current campaign state: the 15 lounge sellers need campaign > 16 (and the
  generic lounge doesn't exist yet); campaign unlocks come from `Story.Advance` side effects (steps 34, 58, 72, 104,
  141 — add the pre-investments).
- IAP content: decide whether the Kaamo Club is only the in-game purchase (30 M + 50 Buskat after clearing the pirates)
  and whether the VIP ×2 surcharge applies (the original charges double without the card).
- Faithful bugs: `lock` = unlock (Liberator stays unlocked), the step-146 early return in `checkPendingProducts`, no
  cargo-space check when products arrive, left arrow doing nothing. Keeping all of them is harmless except the
  step-146 early return (fix it: skip only the Chromo Plasma entry).

---

## 5. Uncertainties

1. The percent value in the blueprint row (`getCompletionRate` → "N%") is assumed to be `int(rate × 100)`.
2. The radio message id `k + 0x15` for a recovered hidden blueprint → texts 3156–3160 is inferred from the text
   contents, not traced through `Level::createRadioMessage` 0xd5568.
3. The row highlight colours (green name, price colours) are not recovered.
4. Whether the VIP-less price shown in the lounge text (#C) is doubled like the payment (decompiler lost the float
   factor in `startChat`).
5. The item templates' single price used by `addItem` for campaign pre-investments and by the Chromo Plasma autocomplete
   is assumed to stay `(min + max) / 2` (templates aren't repriced by `calcCargoPrices`).
6. HackingGame rules themselves (difficulty 4) are not covered here (used for secure containers in the story too,
   `campaign_levels_c.md`).

---

## 6. Functions

| Function | Address |
|---|---|
| BluePrint::BluePrint / addItem / getIngredientList / complete / isCompleted / getTotalAmount / getCurrentAmount / getRemainingAmount / getCompletionRate / getIngredientsValue / getAutoCompletionPrice / unlock / lock / isEmpty / reset | 0x1a6044 / 0x1a6154 / 0x1a62a4 / 0x1a62bc / 0x1a62d8 / 0x1a631c / 0x1a6378 / 0x1a6398 / 0x1a63dc / 0x1a6454 / 0x1a64c8 / 0x1a6536 / 0x1a653c / 0x1a6542 / 0x1a6550 |
| PendingProduct::PendingProduct (BluePrint*) / (int, String, int, int) | 0x154520 / 0x1545a4 |
| Item::Item / setBlueprintAmount / getBlueprintAmount / getIngredients / getQuantities / transactionBlueprint | 0xf3f1c / 0xf4020 / 0xf4024 / 0xf4030 / 0xf4034 / 0xf40cc |
| FileRead::loadItemsBinary | 0x145f48 |
| Status::addPendingProduct / getPendingProducts / departStation / nextCampaignMission / missionCompleted / getGoodsProduced / incGoodsProduced / getBluePrints / unlockBluePrint / isBlueprintUnlocked / resetGame | 0xb606a / 0xb6124 / 0xb63e0 / 0xb6c98 / 0xb924c / 0xb9960 / 0xb9966 / 0xb9a78 / 0xb9a7c / 0xb9ab6 / 0xba78c |
| Station::setShips / hasShip / addShip / stationHasHiddenBlueprint / getHiddenBlueprintIndex | 0xb3b3a / 0xb3d02 / 0xb3dd8 / 0xb3ec8 / 0xb3f08 |
| SolarSystem::hasHiddenBlueprint (no callers) / getRoutes | 0x180b20 / 0x180c82 |
| HangarList::initBlueprintTab / init / fillIngredientsList / setCurrentTab | 0x143208 / 0x1433f4 / 0x14378c / 0x14396e |
| HangarWindow::initialize / update / transaction / refreshCargoAvailabilityForBlueprints / render / OnTouchBegin / setSellMode / OnTouchEnd / readyToClose / selectItem | 0x171740 / 0x172626 / 0x172820 / 0x172c28 / 0x172d00 / 0x175c74 / 0x176594 / 0x176d94 / 0x178da0 / 0x178e20 |
| ListItemWindow::set | 0x159468 |
| ModStation::OnInitialize / OnTouchEnd / OnUpdate / checkPendingProducts / checkHints / showDlcMenu | 0xe8080 / 0xea4ec / 0xed2a8 / 0xee258 / 0xee500 / 0xefd64 |
| PlayerEgo::update (hacking game, hidden blueprint) / HackingGame::HackingGame | 0xa8ed0 / 0x179638 |
| Level::createMission / createScene / connectPlayers / createShip / createRadioMessage | 0xbda70 / 0xc2910 / 0xcc330 / 0xcf83c / 0xd5568 |
| Generator::getItemBuyList / getLootList / createAgents / createAgent / createMission | 0xa05c4 / 0xa1b78 / 0xa1fd0 / 0xa26c0 / 0xa2a7c |
| SpaceLounge::startChat / onKeyPress / OnTouchEnd; Globals::getAgentMissionText | 0x198974 / 0x19c6fc / 0x1a0360; 0xfa7d4 |
| Agent::getSellBlueprintIndex / getSellModIndex / getModPricePercentage | 0x1a689a / 0x1a6986 / 0x1a698c |
| Ship::getHandlingForShop / getHandling / getCombinedHP / getMaxHP / getMaxLoad / clone / makeShip / addMod / getNumAddedDeviceSlots / getUnmoddedHandling / getModdedLoad / getMods / setMods / hasModInstalled | 0x1a382c / 0x1a3878 / 0x1a38c8 / 0x1a3906 / 0x1a3a3e / 0x1a4284 / 0x1a4270 / 0x1a4404 / 0x1a4506 / 0x1a450a / 0x1a450e / 0x1a4538 / 0x1a453c / 0x1a4602 |
| RecordHandler::recordStoreRead / recordStoreWrite / writeAgent; GameRecord::load | 0xdc6e4 / 0xdf760 / 0xe1034; 0x180dc4 |
| Achievements::checkForNewMedal; StatusWindow::draw / getMedalHintText | 0x181ec0; 0x183a64 / 0x185da4 |
| MGame::OnUpdate (Kaamo state 1); ndk_iapBoughtPremium; MenuTouchWindow::update | 0x1ac778; 0x9f2e8; 0x14ffec |

Tables: `DAT_0025273c` = `DAT_00259840` hidden-blueprint stations [132, 133, 134, 129, 123]; `DAT_002521f0` their
blueprints [226, 221, 223, 225, 227]; `DAT_00253754` wreck race [1, 3, 2, 0, 2]; `DAT_00253768` wreck positions
(3 floats each); `DAT_00252090` mod price % [20, 30, 40, 20]; `DAT_00254400` mod (id, #N) pairs; `DAT_00251f40` Kaamo
ships [55..60]; `DAT_00251d10` Kaamo special items; `UNK_00259860` medal thresholds (3 per medal, gold/silver/bronze).
