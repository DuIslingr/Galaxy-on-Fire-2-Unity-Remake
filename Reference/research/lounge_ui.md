# Space Lounge UI, agent portraits and voices, news ticker, Missions and Status windows

Research for the remake: how the original **presents** the bar (Space Lounge) and the two remaining station windows
(Missions, Status). Source: `libgof2hdaa.so` (Android HD 2.0.16), Ghidra image base 0x10000. Text ids index
`Assets/Localization/text_en.json`, image ids resolve with `Reference/tools/shop/atlas.py rect(id)`. 2D values are
**Android-HD screen pixels (1920×1080)**: `retinaDisplay = iPad = iPadLarge = 1`, `iPadHD = 0` (shop.md §1.2), which
matters because most of these windows have a separate `Globals::iPad` layout. PRIVATE: all game data stays local.

What this builds on (not repeated here): `freelance_missions.md` (agents, offers, text composition of an offer, the
deal logic, missions), `station_interior.md` §2 (bar 3D scene, visitor billboards, bar camera), `dialogue_cutscenes.md`
(DialogueWindow, portrait composition, voice table), `shop.md` (ListItemWindow, icons), `starmap_travel.md` §4.4 (the
reveal animation used by bought system coordinates).

Helpers (`Reference/tools/lounge/`, read-only on binary and assets):

| script | what |
|---|---|
| `agent_portraits.py` | `createChar` port; coverage of every generic portrait set / part / variant against the part textures; `--races`, `--sheet out.png`, `--random N out.png` |
| `lounge_voices.py` | `getSoundId` categories × race voice sets → FMOD event id → name → `LOUNGE_eng` / `LOUNGE_deu` file; `--check`, `--json` |

Confidence: **verified** = read in the decompile and checked in the disassembly or by running the data; unmarked =
read in the decompile; *(assumed)* / *(uncertain)* = inference.

---------------------------------------------------------------------------------------------------

## 0. Summary

- **Selecting a visitor = tapping its 3D billboard.** There is no visitor list and nothing is drawn over the visitors
  while you look around. Only while a finger/mouse is **held** on a visitor a small name plate appears above it
  (race name for strangers, "Name  Offer" for agents you have talked to). Releasing on the visitor opens the chat.
- **Chat = two stacked panels, no speaker header**: the agent panel (portrait + scrolling offer text) and below it
  the player panel (Keith's portrait, mirrored, + 1–4 answer buttons). On HD both float next to the tapped visitor.
- **Touch answer set (HD)**: 860 "Okay." (green) / 861 "No thanks." (red), plus 776 "Let me see it." for item /
  blueprint / Kaamo / ship sellers, or 804 "Show it on the map." + 807 "What's the risk?" for missions. **862 "What was
  that?" and the keyboard choice list are dead code in this build** (§1.6). "No thanks." closes the chat at once.
- Confirmations ("Accept … mission?", prices, refusals) use the shared `ChoiceWindow`; accepting shows one of 850–852
  (+ 853–856) with a single "Okay." that closes the chat.
- **Voice**: every chat start plays one line from the race's `LOUNGE` bank (48 events per voice set, 7 sets), picked by
  offer (delivery / fight / special / challenge / purchase / wingman / diplomat / seller / coordinates), 30 % a generic
  greeting instead, the rude small-talk lines their own "NEG" greetings (§3). All 252 used events have English and
  German files.
- **Portraits**: generic agents use exactly the story-portrait composition; every part texture of every generic set
  exists and the remake's `GoF2StoryAssets` already imports them (§2).
- **News ticker**: a scrolling "+++"-separated line at the bottom of the **station main view** (not the lounge),
  59 items from `ticker.json`, campaign-window items always, 2 random others (§4). The lounge "system-info reveal" is
  the **coordinates seller** (offer 4): after buying, "Okay." opens the star map reveal (§1.8).
- **Missions window**: one screen, two side-by-side panels "Story" (555) and "Freelance" (556) (not tabs), Show on map
  / Discard buttons; tabs 129 / 3219 only when the Most Wanted board is available (§5).
- **Status window** (HD): left half = pilot (Keith, credits, level, play time), ship (icon, name, fire power,
  defense), reputation bars for the two standing axes, 11 statistics; right half = the 45 medals in a scrolling 3-column
  grid; tapping an earned medal explains it (§6).

---------------------------------------------------------------------------------------------------

## 1. SpaceLounge UI (`game/SpaceLounge.c`)

### 1.1 Object

| Offset | Meaning |
|---|---|
| +0x04 | StarMap* (map mode: the mission map or the coordinates reveal) |
| +0x08 | ChoiceWindow* (confirmations and refusals) |
| +0x0c | ListItemWindow* ("Let me see it.") |
| +0x14 | **chat state** 0 browse, 1 offer shown (transient), 2 answers, 3 closing line (single "Okay.") |
| +0x18 | "coordinates bought": open the reveal map when the chat closes |
| +0x19 / +0x1b | ChoiceWindow open as confirmation / as a plain refusal message |
| +0x1c | ListItemWindow open |
| +0x20 | selected agent index (−1 none) |
| +0x24 | `Station::getAgents()` (the bar's agents, `freelance_missions.md` §1) |
| +0x2c / +0x30 | text scroll / legacy keyboard choice index |
| +0x34 | star map open |
| +0x35 | "hangar needs update" (cargo/credits changed; ModStation rebuilds the HangarWindow) |
| +0x36 | "asked the risk" in this chat (answer panel collapses to one "Okay.") |
| +0x38 | Array of agent portraits (`ImageFactory::loadChar(Agent::getImageParts)`, built once per lounge object) |
| +0x3c | Keith's portrait: `loadChar(DAT_0026d3d0)`, a zeroed .bss array = descriptor {0,0,0,0,0} (only read, never written) |
| +0x40 | Array of 2·n screen points: [2i] = projection of P − 150·camRight (bottom-left), [2i+1] = P + 150·camRight + (0, 450, 0) (top-right); refreshed every frame by `updateScreenPositions` 0x19ec30 (station_interior §2.2) |
| +0x44 | CutScene(4) (the bar 3D scene) |
| +0x58 | 21 small-talk "used" flags (reset per `init`, i.e. per lounge entry) |
| +0x5c | the 5 answer TouchButtons |
| +0x60 | ScrollTouchWindow (offer text) |
| +0x68 | number of visible answer buttons (computed in `drawLounge`) |
| +0x6c | text width; +0x70 / +0x74 agent panel x / y; +0x78 player panel y |
| +0x7c / +0x80 | answer button y: single/centred row / top row; +0x84 answer column x |
| +0x88 | visitor under the finger (hover label, −1 none) |
| +0x8c / +0x98 | copies of the selected visitor's two screen points (chat placement) |
| +0xa4 | "(includes #P% standing bonus)" suffix of the current offer (767) |
| +0xac | ready; +0xae/+0xb0/+0xb4 touch down / x / y (dead edge-scroll code, station_interior §2.3) |
| +0xb8 / +0xb9 | idle-sway started / **intro finished** (`introFinished` 0x1987b2, read by ModStation) |

### 1.2 Life cycle and entry

- Created on the first "Space Lounge" press of a docking (`ModStation+0x70`); later presses call `init` 0x197da0
  (camera straight to the rest position B, no intro; station_interior §2.3). Campaign scripts can open it directly on
  docking (`Globals::enterSpaceLounge`, e.g. campaign index 0x6e).
- `SpaceLounge()` 0x197890: after `init`, an agent whose **Challenge** mission (type 12) was accepted is removed from
  the bar (he is waiting outside), then the CutScene(4) is built and the 3000 ms camera intro starts.
- `init`: portraits for all agents (first time only), fresh ChoiceWindow, small-talk flags cleared, layout (§1.3),
  answer buttons, sun light. Campaign index 24 at station 10: the unknown "AB-1 Retractor" seller (offer 2, item 68)
  starts talking by himself (`startChat`).
- Leaving: the footer back button while browsing (state 0) → `OnTouchEnd` returns 1 **(verified, 0x1a053c
  `movs r5,#1`)** → `ModStation::OnTouchEnd` 0xea4ec (lounge branch): `resetIdleCamForHangar`, `resetLight`, music parameter 0, stop
  0x6c `Station_Atmo_Lounge`, play 0x7a `Station_Atmo_Mainview`, `checkForTurret`, and if +0x35 the HangarWindow is
  discarded (rebuilt on next use).
- Header 398 "Space Lounge" (`Layout::drawHeader`); footer with back button in states 0/1, **without** back button in
  states 2/3 (`drawFooterNoBackButton`). Help button → 627 (lounge), 643 (ListItemWindow).
- `ModStation::OnUpdate` 0xed2a8 passes `introFinished` to `Status::missionCompleted(docked, inLounge)`: campaign
  "lounge" objectives (0xab/0xac, `campaign_flow.md`) complete only once the intro has finished; the Supernova lounge
  visits (index 116 in system 18, 148–151) hook in there too.

### 1.3 Layout (Android HD)

Layout fields used (retina/iPadLarge branch of `Layout::Layout` 0xe2a00): +0x0c header 58, +0x10 footer 74, +0x1c 40,
+0x20 10, +0x24 10, +0x28 10, +0x2c 6, +0x30 **button height 60**, +0x34 button gap 12, +0x4c margin 10, +0x68 **806**,
+0x6c **272**, +0x94 20, +0x2c0 −4, +0x2d4/+0x2d8 portrait 160×200.

**Agent panel** (`init`, re-placed by `startChat` on iPad):

| element | rule | HD value |
|---|---|---|
| panel | `drawBox(2, x, y, 806, 272)` + `DrawRectangle` outline (colour lost) | 806×272 |
| x | iPad: `visitorLeft − 20 − 806`; if that is < 10: `min(visitorRight + 20, w − 10)` | beside the visitor |
| y | iPad: `clamp(visitorTop − 272/3, 58 + 10, h − 74 − 10 − 272)` | 68..724 |
| x, y (non-iPad) | `(w − 806)/2`, `58 + 10` | (557, 68) |
| portrait | `drawChar(agentParts, x + 10, y + 10)`, not mirrored | 160×200 |
| text | `ScrollTouchWindow(x + 20 + 160, y, 616, 272, noTitle)` → text box inset 10: `(x + 190, y + 10, 596, 252)`, drag to scroll + scroll bar | |

The agent's **name is not drawn**: `ScrollTouchWindow::setText(name, text)` stores the name, but the window was built
without a title bar (`param_5 = false`), so only the text shows (the text itself usually contains "My name is #N").

**Player panel** (`drawLounge` 0x19f53c, states 2 and 3): `drawBox(2, x, y2 = y + 272 + 6, 806, h2)` + outline, with
`h2 = 2·10 + max(200, 60·(n − 1) + 12·(n − 2))` for n answer buttons (n ≤ 2: 220); Keith's portrait
`drawChar(keith, x + 10, y2 + 10, mirrored = true)`.

**Answer buttons** (TouchButton style 4 = the 3-slice bar, 60 px; anchors: 0x11 top-left, 0x12 top-right):

| # | text | position (HD, iPad branch of `startChat`) | width | colour |
|---|---|---|---|---|
| 0 | 860 "Okay." | top row `(x + 190, y2 + 10)`; alone: `(x + 190, y2 + 10 − 30 + 100)` (centred in the 200 px portrait height) | 303 | 0x00ed00ff (RGBA green); white when it only closes / returns |
| 1 | 861 "No thanks." | top-right `(x + 796, same row)` | 298 | 0xff2a00ff (red) |
| 2 | 776 "Let me see it." | `(x + 190, y2 + 10 + 60 + 12)` | 616 | default |
| 3 | 804 "Show it on the map." | same place as 2 | 616 | default |
| 4 | 807 "What's the risk?" | `(x + 190, y2 + 10 + 144)` | 616 | default |

(`init`'s non-iPad variant adds 22 px between the rows; `startChat` uses 0 on iPadLarge.)

Which buttons are visible (`drawLounge`, n = +0x68):

| situation | buttons |
|---|---|
| state 3 (closing line), small talk (offer 1), or after "What's the risk?" (+0x36) | 0 only, centred, white |
| offers 2 item, 3 blueprint, 9 Kaamo special, 10 ship dealer (mask 0x60c) | 0, 1, 2 |
| offer 0 with a mission, type ≠ 12 (`Mission::isOutsideMission` 0x188054 always returns 1) | 0, 1, 3, 4 |
| everything else: Challenge (12), purchase (5), wingmen (6), diplomat (7), coordinates (4), mods (8) | 0, 1 (centred row) |

**Hover label** (state 0, `drawLounge`): for the visitor under the finger (+0x88): `cx` = middle of its two screen
x, `ty` = top screen y − 40; box `drawBox(2, cx − 20, ty − 20, textW + 40, 60)` + outline, clamped to 10 px from the
screen edges; the text starts at `(cx, ty − 4)` (left-aligned from the visitor's centre, not centred).
Text: a generic agent never talked to (`Agent::isKnown` = event > 0) → race name `406 + race` ("Terran", "Vossk", …,
"Multipod", "Cyborg", "Bobolian", "Grey"); otherwise the agent's name, and for known agents + "  " + a role in a second
colour: mission type name `354 + type` if the agent has a Mission, else 306 "Wingmen" (offer 6), 305 "Merchant"
(offer 2), 884 "Diplomat" (offer 7), else nothing. Story agents show their name even before the first chat.

### 1.4 Input (touch)

- `OnTouchBegin` 0x1a0108 / `OnTouchMove` 0x1a0238, state 0 and intro finished: +0x88 = the visitor whose screen
  rectangle contains the finger (x between the two points, y between top and bottom), else −1 → the hover label.
- `OnTouchEnd` 0x1a0360:
  - ChoiceWindow open: "Yes" → `onKeyPress(0x10000)` (the deal, §1.7), "No" → close it (back to the answers).
  - star map open: its close → back to the lounge.
  - footer back: chat open → close the chat (a generic agent becomes known); ListItemWindow open → close it;
    browsing → leave the lounge (§1.2).
  - state 0, **intro still running → the tap skips the intro** (camera set to B); otherwise the visitor under the
    finger becomes +0x20 and `onKeyPress(0x10000)` → `startChat` 0x198974.
  - state 1 → `onKeyPress(0x10000)`; state 3 → button 0 → `onKeyPress(0x10000)` (§1.6).
  - state 2 → the answer buttons (§1.6). Any answer marks a generic agent as known (`Agent::setEvent(1)`).
- The camera does not move toward the selected visitor (station_interior §2.3).

### 1.5 Opening a chat (`startChat` 0x198974)

1. iPad: place the panels next to the visitor (§1.3), rebuild the text window, move the answer buttons, remember the
   visitor's screen points.
2. Build the text (`freelance_missions.md` §3.1: greeting/intro/body/question for new agents; 857/858/859 or the
   stored offer again for known ones; story sellers 874/875 + 886 + index …), store it (`Agent::setMissionString`),
   set the agent's station and system names.
3. State: normally **1, then immediately `onKeyPress(0x10000)` → 2** (answers visible at once). Directly **3**
   (single "Okay.") for: an accepted offer of a known agent (857/858/859), a story agent whose offer was accepted or
   who has nothing left (858), a mod seller whose mod is already installed (858), the Kaamo Club ship dealer (offer 10)
   while the club is not yet owned (`Status+0x114 < 3`: a greeting 750–755 only, no offer), a diplomat whose race is no longer hostile (883).
4. Voice: `getSoundId(agent)` → `FModSound::play` 2D (§3). Story agents' first chat and the ship dealer adjust
   `Status+0xd0` (agents talked to: +1 on the first chat of each agent, −1 for the dealer's greeting-only case).

### 1.6 Answers (state 2, `OnTouchEnd` case 2)

| button | action |
|---|---|
| 0 "Okay." | after "What's the risk?" (+0x36): back to the offer text (bonus re-evaluated), all answers again. Small talk: close. Otherwise the checks and the confirmation `ChoiceWindow` (`freelance_missions.md` §3.2: 337 / 338 cargo/cabins, 203 money, 785 wingmen already hired, 865 (+ 864) / 863 / 866 / 867 / 868–873 / 885); a failed check opens the ChoiceWindow as a message (+0x1b). |
| 1 "No thanks." | text `845 + nextInt(5)` is set **but the state goes to 0 in the same step, so the chat simply closes** (the line is never visible). `Status+0xe0` += 1 (Naysayer medal, §6.4). |
| 2 "Let me see it." | `ListItemWindow::set(item)` full screen: item details for offers 2/9, the ship (3D, post-processing switched off while open) for offer 10, the blueprint's product item for offer 3. Back closes it. |
| 3 "Show it on the map." | `Agent+0x1d` = 1 (Tracker medal); target = this station → 805, same system → 806 (text replaced, state stays 2); otherwise `StarMap(true, mission, false, −1)` over the lounge (mission mode, starmap_travel.md). |
| 4 "What's the risk?" | `Agent+0x1c` = 1 (Daredevil medal); text `808 + int(d/10·5)`; state 2 with +0x36 → only a white "Okay." |

**Dead code on HD (verified by callers):** `SpaceLounge::onKeyPress(int)` 0x19c6fc is only ever called with 0x10000
(from `startChat` and `OnTouchEnd`); ModStation never forwards keys to it. Its arrow-key branches (cycling +0x20
through the visitors in state 0, cycling the choice index +0x30 over 3–5 entries in state 2) and its choice list with
**index 2 = "What was that?" (repeat the offer, `Status+0xe4` += 1)** are the phone/J2ME path and cannot be reached;
text 862 is not referenced by the lounge at all. In that path "No thanks." shows the 845–849 line with state 3. For
the remake: the HD behaviour is the reference; a repeat button is a harmless remake-only addition if wanted.

### 1.7 After "Yes" (`onKeyPress(0x10000)` with the confirmation open)

As `freelance_missions.md` §3.3 (text `850 + nextInt(3)` + 853–856; payments, cargo, wingmen, diplomat, blueprint,
coordinates, mod, ship). Then `setOfferAccepted` (not for mods), the text window shows the line, **state 3** (single
white "Okay."), +0x35 = 1 (hangar refresh). Accepting a mission also calls `init` (fresh ChoiceWindow, small-talk
flags reset). No voice or jingle plays for the deal itself *(no FModSound call in the tail)*.

### 1.8 Closing line (state 3) and the coordinates reveal

"Okay." (or a tap in state 1) → `onKeyPress(0x10000)` case 1/3: small talk → state 2 (the one-button panel), else
state 0 (chat closed). If +0x18 is set (**system coordinates bought**, offer 4: `Status::setSystemVisibility(sys,
true)`) the lounge opens `StarMap(false, 0, true, sys)` = the reveal animation of the newly visible system
(`starmap_travel.md` §4.4); closing the map returns to the lounge. This is the only "system info reveal" in the
lounge: no other lounge visit marks stations or systems on the map (visited stations are set on docking).

### 1.9 Other lounge content

- **No news ticker, no statistics, no system-info panel in the lounge.** The ticker belongs to the station main view
  (§4); statistics are in the Status window (§6).
- Sounds: the lounge ambience (0x6c `Station_Atmo_Lounge`, station_interior §3.2), the music parameter 2.0, the agent
  voices (§3), the generic TouchButton sounds. No open/close sound of its own.
- Lounge unlock / refusals are ModStation's (station_interior §3.2: locked before campaign 13, pirate base 88 → 433).

---------------------------------------------------------------------------------------------------

## 2. Generic agent portraits

`ImageFactory::createChar(bool male, int race)` 0x14173c **(verified)** returns `int[5] = {set, v0, v1, v2, v3}`:
race 3 (Midorian) → set 0 (1/4) or 2 (3/4); set 0 and not male → 10; race 5 (Cyborg) → 0; `v_k = nextInt(COUNTS[set][k])`
(0x258320). `ImageFactory::createChar(int race)` 0x141714 = random gender (only reachable from the radio). The parts
are stored in `Agent+0x78` and drawn with **exactly the story-portrait code**: `loadChar` 0x1417bc → image id
`0x2583f0[set][k] + v` (−1 base = part unused), order part2, part1, part0, part3 over background 0x485 and under
frame 0x511, offsets `IMAGE_OFFSETS_IPAD_LARGE` 0x26a84c (`dialogue_cutscenes.md` §1.3). The same parts feed the chat
panel, the Missions window (client portrait), the radio (`Mission::getClientImage`) and wingmen.

Race → portrait set (`agent_portraits.py --races`): Terran ♂ 0, Terran ♀ 10, Vossk 1, Nivelian 2, Midorian 0 (25 %)
/ 2 (75 %), Multipod 4, Cyborg 0, Bobolian 6, Grey 7. (Sets 3, 5, 8 have no images; 9 Void, 11 computer, 12 Corny are
story-only.)

Coverage (`agent_portraits.py`, **verified: every variant of every generic set has its `_ipad_large` texture**):

| set | parts 0 / 1 / 2 / 3 variants | image ids | anchors (y) part0, part1, part2, part3 |
|---|---|---|---|
| 0 Terran ♂ (also Cyborg, ¼ Midorian) | 11 / 11 / 11 / 11 | 5000–5043 | top 120, top 68, bottom 200, top 0 |
| 1 Vossk | 4 / 5 / 6 / 9 | 5044–5067 | top 137, top 65, bottom 200, top 0 |
| 2 Nivelian (¾ Midorian) | 5 / 5 / 5 / 5 | 5068–5087 | top 118, top 64, bottom 200, top 0 |
| 4 Multipod | 3 / 3 / 5 / 4 | 5088–5102 | bottom 200, top 44, bottom 200, top 0 |
| 6 Bobolian | 2 / 3 / 5 / – (count 0, base −1) | 5103–5112 | bottom 200, top 115, top 0, – |
| 7 Grey | 2 / 2 / 3 / 2 | 5113–5121 | top 104, top 56, bottom 200, top 0 |
| 10 Terran ♀ | 4 / 4 / 5 / 7 | 5126–5145 | top 121, top 68, bottom 200, top 0 |

Files: `Assets/Textures/textures/<set>_<part>_<variant>_ipad_large.png` (160 px wide, image in the top-left of a
power-of-two canvas; the image height is the manifest region height). For all generic sets the file name equals
`set_part_variant` of the descriptor, so **the remake's `GoF2Portrait.Show(box, descriptor, mirrored)` + the part
textures `GoF2StoryAssetsBuilder` already imports (regex `^(\d+)_(\d)_(\d+)_ipad_large$`) cover every generic agent**.
The only set where file name ≠ descriptor is 11 (computer screens: descriptor part 0 variant 1 → id 5147 → file
`11_3_3`), which is why story speakers go through `ShowSpeaker` (image ids); agents never use set 11. `portrait.py
--parts` / `BASE_IDS` handle all sets. Bobolian part 3: `nextInt(0)` is called for it (count 0); its base is −1 so
the value is ignored — the remake should just skip parts with count 0.

---------------------------------------------------------------------------------------------------

## 3. Voice lines in the bar (`SpaceLounge::getSoundId` 0x19fdb4, `getSpecificSoundForRace` 0x1a0080, verified)

```
type = agent has a non-empty Mission ? Mission::getType : −1
switch offer:
  0: type 0 Courier or 11 Passenger → DELIVERY_01..04        base 0x301 + nextInt(4)
     type 12 Challenge             → CHALLENGE_01..04       base 0x2fa + nextInt(4)
     else 50/50                    → SPECIAL_01..04 (799 + nextInt(4)) or FIGHT_01..04 (0x309 + nextInt(4))
  1 small talk                     → GENERIC_01/02          base 0x30d + nextInt(2)          (skips the 30 % roll)
  2, 3, 8, 9, 10 sellers           → BLUEPRINT_01/02        base 0x2f7 + nextInt(2)
  4 coordinates                    → COORDINATES_01/02      base 0x2fe + nextInt(2)
  5 purchase                       → PRODUCTION_01..04      base 0x31b + nextInt(4)
  6 wingmen                        → WINGMAN_01..04         base 0x323 + nextInt(4)
  7 diplomat                       → DIPLOMAT_01..04        base 0x305 + nextInt(4)
  else                             → −1
if not small talk and nextInt(100) < 30: → GENERIC_01/02 instead
if the offer was accepted:              → GENERIC_01/02
small talk whose stored text is exactly 820 / 824 / 827 / 833 ("What are you looking at?", "Leave me alone.",
  "…buy me a drink…buzz off!", the depressed Octopod line) → GENERIC_NEG_01/02 (base 0x314 + nextInt(2))
voice set: race 0/5 → TERRAN_MALE / TERRAN_FEMALE by gender; 1 VOSSK; 2 NIVELIAN; 3 Midorian → NIVELIAN when
  imageParts[0] == 2 (or no parts), else TERRAN_MALE; 4 MULTIPOD; 6 BOBOLAN; 7 GREY; 8 (pirates) and others silent
event id = base + offset[set], offset = BOBOLAN 0, GREY 0x30, MULTIPOD 0x60, NIVELIAN 0x90, TERRAN_FEMALE 0xc0,
  TERRAN_MALE 0xf0, VOSSK 0x120 (applied when base − 759 < 48; Bobolan returns the base unchecked)
```

Each voice set is one contiguous block of 48 FMOD events (system ids 759–806 Bobolan, 807–854 Grey, 855–902 Multipod,
903–950 Nivelian, 951–998 Terran female, 999–1046 Terran male, 1047–1094 Vossk; names via `fev_events.py` with the
656–659 gap), in this order: BLUEPRINT_01–03, CHALLENGE_01–04, COORDINATES_01–03, DELIVERY_01–04, DIPLOMAT_01–04,
FIGHT_01–04, GENERIC_01–07, GENERIC_NEG_01–04, NURMALSO_01–03, PRODUCTION_01–04, SPECIAL_01–04, WINGMAN_01–04
(`lounge_voices.py --check`: all 7 blocks aligned, **verified**).

Files: `Assets/Audio/LOUNGE_eng/<SET>_GREETING_LOUNGE_<KIND>_NN.ogg` and `LOUNGE_deu/de_<same>.ogg`. All 252 events
the code can pick exist in both languages. Never picked: BLUEPRINT_03, COORDINATES_03, GENERIC_03–07 (06/07 live in
`VOICE_eng`), GENERIC_NEG_03/04, NURMALSO_01–03; VOSSK_WINGMAN_* can't occur (Vossk never offer wingmen).

When: once at every chat start (new or known agent, after the text is set), including the closing-line cases of §1.5
step 3; the Kaamo dealer's greeting-only case plays GENERIC_01/02 directly. Played 2D, no subtitles beyond the chat
text (the lines are generic greetings, not readings of the offer text). German UI → the German file, else English.

---------------------------------------------------------------------------------------------------

## 4. News ticker (`NewsTicker`, station main view)

- Created in `ModStation::OnInitialize` state 0x3c: `NewsTicker(x = leftPanelWidth (layout+0xcc = 360), y = h − 74
  − fontHeight, w = w − 360, race = system race, campaign = current campaign index)`; drawn by `ModStation::OnRender2D`
  0xef208 on the main view only (not in the lounge or any window), **not at stations 101, 108 or in system 25 (Loma)**.
- Items: `FileRead::loadTicker` 0x146634 reads `data/bin/ticker.bin` = `GoF2Data/ticker.json` (59 entries: `index`,
  `flag`, `conditions[4]` = allowed system races T/V/N/M, `param1` / `param2` = campaign window). Text = **3262 +
  index** (0xcbe).
- Selection (`NewsTicker::NewsTicker` 0x1889d4):
  1. every item with `param1 > 0`, `param1 ≤ campaign ≤ param2` and `conditions[race]` (story news: e.g. 34 Gunant's
     Phantom sale at 30–45, 48–51 the Void defeated at 45, 54–58 the Supernova at 90–163);
  2. then **2 random items** (100 tries): `param2 ≥ 161` (the always-items, param2 = 1000), `param1 ≤ campaign`,
     50 % chance, `conditions[race]`, not picked yet; item 13 (the lounge drink) not in systems > 21; `flag` items
     (17, 27, 29, 32) at most once per 10 minutes of playing time (`Status+0x160` time, `+0x170` index) and their
     token-filled text is cached in `Status+0x168` so a repeat reads the same.
  3. joined with `"    +++    "` after each item; doubled when shorter than the width.
- Tokens (`replaceTokens` 0x188ea0): #PLANET_NAME / #SYSTEM_NAME (random station), #DRINK_NAME (text 1406 + system,
  else a random drink system), #CHILD_NAME, #SHIP_NAME (913 + random enemy fighter), #PLATFORM_NUMBER (A–F + 0–9),
  #CATASTROPHE (3237 + nextInt(5)), #VICTIMS, #BERGER_LASER (1279 + nextInt(4)), #VOSSK_SHIP_OR_ITEM / #VOSSK_REVENUE,
  #PROFESSION / #NAME / #ACTIVITY (3243/3247), #RACE_NAME / #CRIME (406 + nextInt(4), 3251), #NIVELIAN_PLANET /
  #DEMONSTRATORS, #POLL_PERCENTAGE / #POLL_TOPIC (3256), #CASUALTIES.
- Motion: scrolls left at **50 px/s** (`update` 0x18a8bc: `x −= dt/1000·50`, wraps at −textWidth; Arabic, language 9,
  scrolls right); drag scrolls it by hand (`OnTouchBegin/Move/End`, pauses the auto-scroll while held). `draw`
  0x18a950: a filled strip `(x, y − 2, w, h − y + 2 − 74)` (colour lost), clipped text drawn twice for the wrap.

---------------------------------------------------------------------------------------------------

## 5. Missions window (`game/MissionsWindow.c`)

Opened by the station menu button 3 (129 "Missions", locked before campaign 9, station_interior §3.2) and from the
flight HUD menu. `MissionsWindow::init` 0x17a604, `draw` 0x17b240, `update` 0x17b7a4, `OnTouchEnd` 0x17bbc0.

### 5.1 Layout (HD)

Window `1300 × 1000` centred → **(310, 40)** (`Layout::setWindowDimensions`; non-iPad: full screen). Screen header
129 "Missions", normal footer (back closes), help 635.

| element | position (HD) |
|---|---|
| tabs (only if `Status::wantedBoardAccessible` 0xba1f8) | TouchButton style 3, top-right of the window, right-aligned left of the help button: 3219 "Most Wanted" (right), 129 "Missions" (left, pressed = current) → `WantedWindow` (freelance_missions.md §6) |
| left panel title | `drawBox(1, 320, 108, …)` 90 px section plate, title **555 "Story"** |
| left panel body | `drawBox(5, 320, 204, …)`; text `ScrollTouchWindow(320, 204, 634, 680)` (h 740 when the game is won: no button) |
| left button | 424 "Show on map", style 4, bottom-left anchor at (320, 950), width 315 → `StarMap(true, campaignMission)`; not shown when the game is won |
| right panel title | `drawBox(1, 966, 108, …)` title **556 "Freelance"** |
| right panel, no mission | text 174 "-BLANK-" in `(966, 204, 634, 740)` |
| right panel, mission | client portrait `drawChar(parts, 966, 204)`; name (1138, 204), client station name (1138, 234), mission type `354 + type` (1138, 264); text `(966, 410, 634, 486)` = the agent's stored offer text with #C = reward + bonus |
| right buttons | 424 "Show on map" (966, 950, w 315) → `StarMap(true, freelanceMission)`; **423 "Discard"** (red text 0xff2a00ff) at (1287, 950, w 315), **only in the station** (module 5) → ChoiceWindow 418 "Are you sure?" → the discard clean-up (freelance_missions.md §3.3), window rebuilt |
| alien orbit | no buttons at all |

Box styles: 1 = section plate (caps 0x6bb 35×90 + tiled 0x6ba 1000×90, `gof2_interface2_ipad_large`), 5 = bordered
panel (corner 0x47d 35×35 + edges), 2 = plain tiled panel (0x47e 320×320), 0 = title plate (caps 0x482 34×40 +
tiled 0x481 960×40); all in `gof2_interface_iphone4` unless noted.

### 5.2 Story text

`text(DAT_00258f68[campaignIndex])` for index < 164 (the objective text; `story.json objectiveText`), `#` → the target
station name; campaign types 0xa7 / 0xae (counters) use `#Q` = a number built from the goods amount and the mission
status value (expression lost in the decompile) and are refreshed every frame in `update`. Game won and no add-on
installed (`options[0x35]`, `[0x37]` off): 650 (all gold medals, not flying ship 8: the Void fighter offer) else 670.

---------------------------------------------------------------------------------------------------

## 6. Status window (`game/StatusWindow.c`, station menu button 4, 169 "Status")

`StatusWindow` 0x18345c, `reInit` 0x183784, `draw` 0x183a64, `getMedalHintText` 0x185da4, `OnTouchEnd` 0x186484.
Full screen over `Layout::drawBG`; header 169 "Status"; footer back closes (returns 1). Help 640 (status column) /
647 (medals). On phones two tabs switch between the columns: TouchButtons style 3 at the top right, tab 0 = 577
"Statistics" (left button), tab 1 = 168 "Medals" (right button). **On iPad/HD both columns are shown side by side and
the tabs are neither drawn nor touchable** (`Globals::iPad` checks in `draw` / `OnTouch*`; the initial tab =
`Globals::iPad` = 1 so the medal buttons react).

### 6.1 Left column (HD, fixed; W = column width = w/2 − 20 = 940, or 912 when the scroll bar shows)

| block | content (x from 10, y from 68) |
|---|---|
| title plate (style 0, 40 px) | 1597 "Keith T. Maxwell" |
| pilot box (style 5, W/2 − 6 × 200) | Keith's portrait `loadChar(DAT_0026d398)` (zeroed .bss = {0,0,0,0,0}); right-aligned lines: credits (`formatCredits`), "321 Level N" (`Status::getLevel`, npc_traffic_ai.md §2.2), playing time "hh:mm" (`longToTimeStringNoSeconds`, hours not wrapped) |
| ship box (style 5, right half) | ship icon `drawShip(ship)` (178×86 on its blue frame, shop.md §1), ship name 913 + ship, "569 Fire power:" `Ship::getFirePower` with one decimal, "570 Defense:" `Ship::getCombinedHP` (right-aligned values) |
| title plate | 576 "Reputation" |
| two boxes (style 5) | left: Terran emblem left, Vossk emblem right, bar between, labels 406 "Terran" / 407 "Vossk"; right: Nivelian / Midorian (408 / 409) |
| title plate | 577 "Statistics" |
| two boxes (style 5, 6 + 6·30 px) | rows "label:" left, value right-aligned (below) |

Statistics rows (label text id → value; the lost decompile arguments recovered from the disassembly, **verified**):

| left column | value | right column | value |
|---|---|---|---|
| 568 Missions completed | `Status::getMissionCount` (+0x1c4) | 564 Jumpgates used | `getJumpgateUsed` |
| 176 Kills | `getKills` | 558 Goods produced | `getGoodsProduced` |
| 552 Asteroids destroyed | `Status+0xd8` | 560 Ore mined | `Status+0xa0` |
| 559 Cargo salvaged | `getCapturedCrates` | 561 Cores mined | `Status+0xa4` |
| 557 Stations visited | `getStationsVisited` | 567 Wingmen hired | `Status+0xd4` |
| 3235 Battleships destroyed | `Status+0x118` | | |

Reputation bars (`reInit` picks the emblem images by `Standing::isEnemy`; `draw`):

| emblem | normal | when | alternative |
|---|---|---|---|
| Terran (left of bar 1) | 0x493 | Vossk hostile → 0x494 (Terran-friendly look); Terran hostile → 0x495 | |
| Vossk (right of bar 1) | 0x492 | Terran hostile → 0x496; Vossk hostile → 0x497 | |
| Nivelian (left of bar 2) | 0x490 | Midorian hostile → 0x498; Nivelian hostile → 0x499 | |
| Midorian (right of bar 2) | 0x491 | Nivelian hostile → 0x49a; Midorian hostile → 0x49b | |

Bar: track 0x48e (164×28) centred at x = 10 + W/4 (resp. the right box's centre), fill 0x48f drawn from the centre
over `rate · 82` px toward the favoured side, marker 0x48d (26×62) at `centre − 82·rate`; `rate =
Standing::getStandingRate(axis)` = standing / 100 (axis 0 Terran(+)/Vossk(−), axis 1 Nivelian(+)/Midorian(−)), so the
marker moves toward the race you are liked by. Emblems ~82–93 × 86–88 px (`gof2_interface_iphone4`, ids
0x490–0x49b, rects via `atlas.rect`).

### 6.2 Right column: medals (HD, scrolls vertically; left column stays)

- Title plate 168 "Medals" at (960, 68 + scroll); 45 medal buttons (`TouchButton(index, level, name 1507 + i, …)`,
  anchor centre) in **3 columns** (pitch W/3 = 313, first centre x = W + 156 + 10) and 15 rows of **160 px**
  (layout+0x84), row centre y = 190 + 160·row + scroll (190 = 58 + 80 + 6 + 40 + 6). Drag scrolls with inertia (×0.9 per frame, spring
  back at the ends), scroll bar at the right screen edge; content height 15·160 + 56, visible 928.
- Button look (`TouchButton::init` style 4): plate by level `DAT_00252040[level]` = 0 none 2416, 1 gold 2414,
  2 silver 2415, 3 bronze 2413 (elite medals 36–44: 0 → 8045, 1 → 8035), all 228×84; the medal symbol
  `DAT_0025c7dc[i]` (54×54: ids 2376–2411 for 0–35, 8036–8044 for 36–44); a highlight overlay 2412 when earned or
  elite; the name below the plate, colour by level (RGBA: none 0x2198ff2f translucent blue, gold 0xfad10eff, silver
  white, bronze 0xce8258ff; elite unearned 0xfa792160, elite gold 0xfa7921ff).
- Only earned (or elite) medals react. Tap → a hint box at the bottom left (`drawBox(2)+(5)` at x 10, width W,
  height 20 + 30·lines, bottom at h − 74 − 10) with text `1552 + i` where `#` = the threshold of the earned level
  (`Achievements::getValue(i, level)` = table 0x259860[i][level − 1]); silver Geologist / Adv. Geologist / Barkeeper /
  Handyman / Engineer (2, 3, 9, 13, 14) append "\n\n276 Still missing:" and the missing ore (1428 + j), core
  (1439 + j), drink (1406 + j) or blueprint product names.

### 6.3 Medals (`Achievements`, 45 entries: value 0 none, 1 gold, 2 silver, 3 bronze)

`checkForNewMedal` 0x181ec0 (on docking) compares a counter with the thresholds `[gold, silver, bronze]` at 0x259860
(first met wins; −1 = level not used; counter ≥ threshold, a few strictly >; Survivor: hull % ≤ threshold), `applyNewMedals` keeps the best level; `countMedals`:
36 base medals (0–35) + 9 elite/Supernova medals (36–44, `isEliteMedal` = index > 35); all 36 → `gotAllMedals`
(wingmen then pay *you*, freelance_missions.md §3.1), 35 earned → medal 35 "Champion" awarded automatically.

| # | name (1507+) | counter | gold / silver / bronze |
|---|---|---|---|
| 0 | Veteran | preset gold by `Achievements::init` | – |
| 1 | Survivor | hull % on arrival (≤) | 5 / 15 / 30 |
| 2 / 3 | Geologist / Adv. Geologist | ore / core types owned (`Status+0x94` / `+0x98` flags) | 11/8/5 |
| 4 | Killer | kills | 250 / 100 / 50 |
| 5 | Carrier | containers delivered `+0x9c` | 200 / 100 / 25 |
| 6 / 7 | Miner / Adv. Miner | ore `+0xa0` / cores `+0xa4` t | 1000/500/100, 25/10/3 |
| 8 / 9 | Personal Need / Barkeeper | booze bought `+0xa8` / types `+0xac` | 1000/100/25, 22/16/5 |
| 10 | Garbage Man | junk `+0xb0` | 150 / 100 / 30 |
| 11 / 12 | Space Tourist / Explorer | stations visited / systems (`+0xb4` 22 flags) | 100/50/25, 22/10/5 |
| 13 / 14 | Handyman / Engineer | blueprints owned / finished | 13/6/3 |
| 15 | Addict | playing hours | 20 / 10 / 5 |
| 16 | Workaholic | missions completed | 50 / 25 / 5 |
| 17 | Globetrotter | jumpgates used | 100 / 50 / 10 |
| 18 | Tour Operator | passengers `+0xb8` | 50 / 20 / 5 |
| 19 | Ninja | cloak minutes (`+0xc0` ms) | 5 / 3 / 2 |
| 20 / 21 | Nuclear Armament / Alien Hunter | bombs `+0xc8` / alien remains `+0xcc` | 50/20/5, 25/10/5 |
| 22 | Harum-Scarum | launched without weapons/equipment | 0 |
| 23 | Weapon Fanatic | primaries mounted | 4 / 3 / 2 |
| 24 | Looter | crates salvaged | 500 / 200 / 50 |
| 25 | Moneybags | highest credits | 1 000 000 / 500 000 / 125 000 |
| **26** | **Chatterbox** | **agents talked to `+0xd0`** | 100 / 50 / 20 |
| **27** | **Commander** | **wingmen hired `+0xd4`** | 20 / 10 / 3 |
| 28 | Renegade | hostile to any faction | 1 |
| 29 | Mason | asteroids destroyed `+0xd8` | 250 / 150 / 50 |
| 30 | Void Terror | game won | 0 |
| 31 | Space Saver | free cargo `+0xdc` | 500 / 250 / 100 |
| **32** | **Naysayer** | **offers declined `+0xe0`** | 50 |
| **33** | **Daredevil** | **missions accepted without asking the risk `+0xe8`** | 10 |
| **34** | **Tracker** | **missions accepted without asking the location `+0xec`** | 12 |
| 35 | Champion | all other base medals | 0 |
| 36–44 | Space Saver Pro, Ship Collector, Ore Athlete, Destroyer Destroyer, Blindfolded Killer, Asteroid Hazard, Jammer, Grave Riser, Hot Shot | max load, Kaamo ships, special flags `Status+0x118..0x148` | 3000, 50, 10, 20, 100, 3, 15, 5, 8 (gold only) |

This resolves `freelance_missions.md` §3.5 / §7: the lounge counters `+0xd0`, `+0xe0`, `+0xe8`, `+0xec` feed the
Chatterbox, Naysayer, Daredevil and Tracker medals (`+0xe4` "repeats" feeds nothing and is unreachable on HD).

---------------------------------------------------------------------------------------------------

## 7. Text ids used here (English)

Lounge: 398 Space Lounge, 627 help, 406–413 race names (hover label), 305 Merchant, 306 Wingmen, 884 Diplomat, 354+
mission types, 860 Okay., 861 No thanks., 776 Let me see it., 804 Show it on the map., 807 What's the risk?, 805/806
map answers, 808–812 risk, 845–849 decline, 850–856 accepted, 857–859 known agent, 643 ListItemWindow help.
Ticker: 3262–3320 items, 3237–3260 token words, 1406+ drinks. Missions: 129, 555, 556, 3219, 424, 423, 418, 174, 635,
650, 670. Status: 169, 168, 577, 576, 1597, 321, 569, 570, 568, 176, 552, 559, 557, 3235, 564, 558, 560, 561, 567,
406–409, 640, 647, 1507–1551 medal names, 1552–1596 medal hints, 276 Still missing:.

## 8. Function index

| Function | Address |
|---|---|
| SpaceLounge::SpaceLounge / init / introFinished / startChat / onKeyPress | 0x197890 / 0x197da0 / 0x1987b2 / 0x198974 / 0x19c6fc |
| SpaceLounge::updateScreenPositions / update / draw / drawLounge | 0x19ec30 / 0x19ef20 / 0x19f3dc / 0x19f53c |
| SpaceLounge::getSoundId / getSpecificSoundForRace | 0x19fdb4 / 0x1a0080 |
| SpaceLounge::OnTouchBegin / OnTouchMove / OnTouchEnd | 0x1a0108 / 0x1a0238 / 0x1a0360 |
| ImageFactory::createChar(int) / createChar(bool,int) / loadChar / drawChar | 0x141714 / 0x14173c / 0x1417bc / 0x1419a0 |
| NewsTicker::NewsTicker / replaceTokens / update / draw; FileRead::loadTicker; NewsItem::NewsItem | 0x1889d4 / 0x188ea0 / 0x18a8bc / 0x18a950; 0x146634; 0xf49d4 |
| MissionsWindow::init / draw / update / OnTouchEnd | 0x17a604 / 0x17b240 / 0x17b7a4 / 0x17bbc0 |
| StatusWindow::StatusWindow / reInit / draw / getMedalHintText / OnTouchEnd | 0x18345c / 0x183784 / 0x183a64 / 0x185da4 / 0x186484 |
| Achievements::checkForNewMedal / countMedals / applyNewMedals / getValue | 0x181ec0 / 0x182444 / 0x1825aa / 0x182610 |
| TouchButton::init (medal style 4) | 0x1961f8 |
| Layout::Layout / drawBox | 0xe2a00 / 0xe6ba8 |
| ModStation::OnInitialize (ticker, state 0x3c) / OnTouchEnd (lounge exit) / OnRender2D (ticker draw) | 0xe8080 / 0xea4ec / 0xef208 |

Tables: medal thresholds 0x259860 [45][3]; medal plates 0x252040 / elite 0x252030, name colours 0x252060 / 0x252050,
medal symbols 0x25c7dc; story objective texts 0x258f68; portrait bases 0x2583f0, counts 0x258320, offsets 0x26a84c.

---------------------------------------------------------------------------------------------------

## 9. Remake implementation notes (UI Toolkit)

The remake already has plain-C# agents / chat / freelance code (`GoF2Agent`, `GoF2AgentGenerator`, `GoF2LoungeChat`,
`GoF2Freelance`) and `UI/Station/Lounge.uss`; these notes are about presentation and the two new windows.

**Lounge selection (world → UI).**
- Keep the visitors as the only selectors. Each frame project the two points of `updateScreenPositions`
  (P ∓ 150·camRight, top + 450 units, i.e. ±7.5 m wide, 22.5 m tall in Unity) with the bar camera and convert to panel
  coordinates (`RuntimePanelUtils.CameraTransformWorldToPanel`); hit-test pointer positions against those rects (last
  match wins, like the original loop).
- Hover label: an absolutely positioned `Label` element (`.lounge-plate`, panel style 2 background) shown for the
  visitor under the pointer: touch = while pressed, mouse = while hovering (remake nicety), controller = the focused
  visitor. Text per §1.3 (race name for strangers; name + role for known agents; the role in the accent colour).
- Controller / keyboard (remake-only, the HD build has none): LB/RB or ←/→ cycle the focused visitor (ordered by
  screen x), A / Enter opens the chat; B / Esc closes chat or leaves; the answer buttons are normal focusable
  `Button`s (A activates, D-pad moves). Show the focus with the same plate as the hover label.
- A tap during the first 3 s intro skips it (camera jumps to B) instead of selecting.

**Chat panels.** One `VisualElement` root (`.lounge-chat`, absolute) with two children stacked vertically at the
reference sizes (806×272 and 806×220–224, 6 px apart, 10 px padding): agent panel = `GoF2Portrait.Show(box,
agent.portraitParts, false)` + a `ScrollView` text area (596×252 content); player panel = `GoF2Portrait.Show(box,
{0,0,0,0,0}, true)` + the answer column (616 px wide; row 1: Okay | No thanks as two half buttons, green/red text;
rows 2–3: full-width buttons). Place the root beside the visitor like §1.3 (left of it, else right, vertical clamp
68..h−84−272, then clamp into the safe area); on narrow/phone layouts centre it instead (the non-iPad rule: x centred,
y 68). No title/name bar (the original has none), but showing the name above the text is a harmless readability
improvement if wanted.
- Answer visibility per the §1.3 table; after "What's the risk?" collapse to a single white "Okay." that returns to the
  offer; "No thanks." closes immediately (optionally show the 845–849 line briefly — remake choice; the original never
  shows it on HD). Keep `GoF2LoungeChat.Choice.Repeat` out of the touch UI to match HD, or keep it as an extra
  row — either way it must not count for any medal.
- Confirmations and refusals: the existing modal dialog (ChoiceWindow equivalent) above the chat; "Yes" → the deal →
  closing line with one "Okay.".
- "Let me see it." → the existing item details window (HangarWindow's details view) full screen; for the ship dealer
  the 3D ship view. "Show it on the map." → `GoF2StarMap.Open` in mission mode with the target marker; the coordinates
  seller's closing "Okay." → the star map reveal of the new system.
- Hide the footer back button in states 2/3 (the player must answer), show it in state 0 (leave) — same as the
  original; Esc/B in state 2 = "No thanks." is a reasonable controller mapping.

**Voice.** Build a `LOUNGE` clip table in an editor step (like `GoF2StoryAssetsBuilder`: `Audio/LOUNGE_eng` +
`LOUNGE_deu` with the `de_` prefix), keyed by name; `GoF2LoungeVoice.Pick(agent, text)` ports §3 (plain C#, returns
the clip name). Play on a 2D UI AudioSource when a chat opens; stop it when the chat closes.

**Portraits.** Nothing new to import: `GoF2Portrait.Show` with the agent's descriptor works for all generic sets
(§2). Skip parts whose count is 0 (Bobolian part 3) when generating.

**News ticker.** A `VisualElement` strip at the bottom of the station main view right of the left panel (x = 360 at
1920 px reference, height = one text line, above the footer), `overflow: hidden`, containing a `Label` with the
joined string (duplicated once for a seamless wrap) moved by `style.translate` at 50 px/s (unscaled time); drag
scrolls it. Selection and tokens per §4 in plain C# (`GoF2NewsTicker.Build(race, campaign, rnd)`), items from
`ticker.json`. Hidden at stations 101, 108 and in system 25. Keep the 10-minute cooldown/cache for flag items in
`GoF2Session` (not saved by the original? `Status+0x160/0x168/0x170` are Status fields — save them with the session
*(assumed)*).

**Station menu.** Add buttons 3 "Missions" (129, locked before campaign 9, help 635) and 4 "Status" (169, help 640);
keyboard 3 / 4 (the menu already uses 1 / 2 / M / L), controller: next free face/shoulder button or the menu list
focus. Both open full windows over the hangar view (the hangar stays rendered behind the Status window's own
background, the Missions window is a centred 1300×1000 panel).

**Missions window (`UI/Station/MissionsWindow.uxml`).** Two columns in a 1300×1000 panel: each a section header
(90 px plate style) "Story" / "Freelance", a bordered body with a `ScrollView` text, and a bottom button row.
Story: `GoF2Story` objective text (`story.json objectiveText`, `#` → target station, counters refreshed), "Show on
map" → star map with the campaign target (hidden when the game is won; text 650/670 then). Freelance: empty → 174
"-BLANK-"; else the client portrait (`GoF2Portrait.Show`), name, station, mission type name, the stored offer text with
#C = reward + bonus, "Show on map", and in the station only a red "Discard" with a 418 confirmation → the existing
freelance discard. Tabs "Missions" / "Most Wanted" only once Wanted targets exist.

**Status window (`UI/Station/StatusWindow.uxml`).** Two halves on wide screens (phones: tabs 577 Statistics / 168
Medals, like the original phone layout):
- left: title plate with "Keith T. Maxwell"; a pilot card (portrait {0,0,0,0,0}, credits, "Level N" from the session's
  level/rank, play time hh:mm — needs a play-time counter in `GoF2Session`); a ship card (`Resources/GoF2Icons` ship
  icon, name, fire power = sum of mounted primary DPS as in `Ship::getFirePower` *(formula not traced, uncertain)*,
  defense = hull + shield + armor); reputation: two bars built from `GoF2Session.Standing` (−100..100 → marker offset
  ±82 px of a 164 px track), emblem images 0x490–0x49b cut like the HUD images (add them to "Build HUD Images");
  statistics: the 11 rows of §6.1 (add the missing counters to `GoF2Session`: asteroids destroyed, crates salvaged,
  stations visited = `VisitedStations.Count`, battleships, goods produced, ore/cores mined, wingmen hired, missions
  completed; `JumpgatesUsed` and `Kills` exist).
- right: a `ScrollView` with a 3-column grid of 45 medal tiles (228×84 plate by level + 54×54 symbol + name below,
  colours per §6.2; cut plates 2413–2416, 8035, 8045, overlay 2412 and symbols 2376–2411 / 8036–8044 with
  `atlas.rect`); tapping an earned tile shows the hint text (1552 + i, `#` = threshold) in a box at the bottom.
- Medals themselves need `GoF2Achievements` (plain C#, §6.3 thresholds, checked on docking, best level kept, saved).
  The lounge already has the counters for Chatterbox / Naysayer / Daredevil / Tracker (`GoF2Session.AgentsTalkedTo`,
  `OffersDeclined`, `AcceptedBlindRisk`, `AcceptedBlindMap`).

---------------------------------------------------------------------------------------------------

## 10. Uncertainties

- Colours passed to `SetColor` before the panels, outlines, the ticker strip and the hover label's role text were
  lost in the decompile (only the button text colours are literal).
- `Ship::getFirePower` / `getCombinedHP`, `Status::getLevel` formulas were not re-traced here.
- The `#Q` expression of the counter-type story objectives (0xa7/0xae) in the Missions window.
- Whether `Status+0x160/0x168/0x170` (ticker cooldown/cache) are saved (not checked in `RecordHandler`).
- Medal 0 "Veteran" is set to gold by `Achievements::init` (a new game) — it looks like a gift medal; its hint text
  ("from Admiral Smith…") supports that.
- The HD key/controller layer (`Globals::other_buttons_x/y`, `sub_menu_buttons_*`) was not checked for the lounge; the
  lounge publishes no button positions, so it is assumed touch/mouse only.
