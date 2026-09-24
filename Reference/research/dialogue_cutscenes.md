# Story presentation: dialogue windows, radio messages, cutscenes, voice acting

How the original presents the story, decoded from `libgof2hdaa.so` (Android HD 2.0.16). Ghidra addresses, image base
0x10000. 2D values are **Android-HD screen pixels** (1920×1080, `retinaDisplay = iPad = iPadLarge = 1`, see
`shop.md` §1.2): `Layout::Layout` 0xe2a00 takes its retina branch for everything used here (the iPadLarge flag only
overrides a few HUD fields). Text ids → `Assets/Localization/text_en.json`; image ids → `tools/shop/atlas.py`.

Scripts (read-only on the binary / assets, all in `Reference/tools/dialogue/`):

| script | what |
|---|---|
| `binary.py` | shared ELF reader (`ints`, `ptr` for R_ARM_RELATIVE pointers, `text`) |
| `dialogue_tables.py [--text] [--mission N] [--json f]` | DialogueWindow pages: campaign mission → briefing / success pages (speaker, text id); home-base broker pages |
| `radio_tables.py [--text] [--json f]` | `Level::createRadioMessages` traced from the Thumb code: mission → radio messages (text, speaker, trigger type, param, count); trigger type table |
| `portrait.py --table / --speaker N out.png / --parts r a b c d out.png / --sheet out.png` | composes portraits exactly like `ImageFactory::loadChar`/`drawChar` (HD 160×200 or `--lowres` 60×75) |
| `fev_events.py [--check] [--voice-table] [--json f]` | FMOD event id → event name → .ogg (rebuilt from the FEV string table), validated against the text→voice table |
| `story_table.py --json f` | everything above in one JSON (ids only, no text): speakers + portrait descriptors, per-mission pages/radio with voice event + eng/deu file, trigger names, portrait part tables |

Keep generated images/JSON out of `Assets/` unless they are meant to be imported (copyrighted material either way).

---------------------------------------------------------------------------------------------------

## 0. TL;DR for the remake

- The story is told by **three widgets** and in-engine scenes; there are no videos, comics or still-image screens:
  1. **DialogueWindow** (modal, game paused): speaker portrait left, speaker name in the window header, scrolling text,
     buttons Back / Next(Close) / Skip. Used for campaign **briefings** (at the start of a flight level), **success**
     conversations (at mission completion, in flight or when docking) and **failure** notes; also one-page messages.
  2. **Radio** (non-modal, in flight): a box at the top centre with portrait + name + text, shown for
     `lines·2000 + 1500` ms after a 2000 ms delay; campaign radio messages are scripted per mission with trigger
     conditions (time, chained, kills, script step…).
  3. **LevelScript** cutscenes: the flight level itself with scripted cameras/objects (section 3).
- **Speakers**: 63 story speakers (id 0 Keith … 62), name = text `1597 + id`, portrait = a 5-int descriptor
  `{bodyType, part0..part3}` composed from per-part PNGs (`<body>_<part>_<variant>_ipad_large.png`). Keith's
  portrait is mirrored in the dialogue window.
- **Voice**: every story line is looked up by **text id** in a 1504-entry table (0x255210) → FMOD event id
  (163…2237) → event name = .ogg file name (`MISSION_<m>_<page>`, `MISSION_END_<m>_<page>`, `RADIO_<m>_<index>`, …) in
  `Audio/VOICE_eng|deu`, `DLC_VOICE_*`, `DLC2_VOICE_*`. 1489 of the 1504 lines have a file. Generic agents
  (freelance missions, radio chatter) pick race/gender voice sets by text id (§5.3).
- Dialogue pages auto-advance only when voice is enabled (`options[0xe]`): voice ends → wait the event's FMOD
  "pause" property → next page (never past the last page).
- The **new game** goes straight from the menu into flight level "campaign mission 0" (the prologue in the Dareius
  asteroid belt) with music 143 `IntroAtmo`; the **ending** is a station sequence after mission 43's success
  conversation: four radio lines, `OutroSong` (144) and a credits scroll (§3.4).
- The campaign is **linear**: no story choices. `ChoiceWindow` only confirms "Skip the dialogue?" (396) or shows
  requirement messages.

---------------------------------------------------------------------------------------------------

## 1. DialogueWindow (`game/DialogueWindow.c`)

### 1.1 Object and modes

| Field | Meaning |
|---|---|
| +0x00 / +0x04 / +0x08 | TouchButtons Back / Next / Skip |
| +0x0c | portrait (`Array<ImagePart*>` from `ImageFactory::loadChar`) |
| +0x10 | campaign mission index the tables are read with (`set` param 3, −1 → `Status::getCurrentCampaignMission`) |
| +0x14..+0x20 | window x, y, w, h |
| +0x24 | portrait descriptor (int[5]) |
| +0x28 / +0x30 | page text / speaker name |
| +0x38 | ScrollTouchWindow (text) |
| +0x3c | **mode**: 0 briefing, 1 success, 2 failure (`getMode` 0x195bec) |
| +0x40 | page index |
| +0x44 | Mission* |
| +0x48 / +0x4c | ChoiceWindow (skip confirmation) / its visible flag |
| +0x50 | Level* (`hasLevel` 0x195d18 / `setLevel` 0x195d22; only stored, the class never reads it) |
| +0x54 / +0x58 | per-mission start offsets into the briefing / success page tables (built in `init`) |
| +0x5c | playing voice event id (−1 none) |
| +0x60 / +0x64 | auto-advance timer / FMOD "pause" length of the current voice event |
| +0x68 | mirror-portrait flag |

Constructors: `DialogueWindow(Mission*, Level*, mode)` 0x1946de (→ `init`, `set(mission, mode, −1)`),
`DialogueWindow()` 0x194a54 (then `set` later), `DialogueWindow(String text, String name, int* portrait)` 0x194a94
(one-page message, §1.7).

`set(mission, mode, missionIndex)` 0x1949dc: mode 1 → `Mission::setWon(true)`; mode 2 → `Mission::setFailed(true)` and
(non-generic agent) `Agent::setOfferAccepted(false)`; page = 0; `loadContent`.

### 1.2 Layout (Android HD)

`init` 0x194734, `draw` 0x195e04. Layout fields: header `layout+8` = 60, margin `+0x4c` = 10, button width `+0x50` =
178, window `+0x54`×`+0x58` = **694×486**, portrait `+0x2d4`×`+0x2d8` = 160×200, footer `+0x30` = 60.

| Element | Position on 1920×1080 |
|---|---|
| screen mask | `Layout::drawMask()` full screen (colour set by a lost `SetColor` argument; dims the scene) |
| window box | centred: (613, 297, 694, 486), `Layout::drawBox(7, …, speakerName)` 0xe6ba8 |
| portrait | (x+10, y+60+10) = (623, 367), 160×200 |
| text | `ScrollTouchWindow(x+180, y+60, 514, 346)` → text box inset 10: (803, 367, 494×326) |
| Back (179) | TouchButton id 5, (x+10, y+476), width 178, anchor 0x21 (bottom-left), style 4; visible when page > 0 |
| Next (180) / Close (181 on the last page) | id 6, (x+684, y+476), width 178, anchor 0x22 (bottom-right) |
| Skip (395) | id 0, (x+347, y+476), width 298, anchor 0x24 (bottom-centre); visible when the dialogue has > 1 page |

Box style 7 (`drawBox` case 7): tiled background `0x47e` (gof2_interface_iphone4 [317,417,320,320]) below the header,
border `drawBGBorder(0x484 corner [1737,1309,93,93], 0x483 edge [649,1724,960,45])`, header plate `0x474`
([317,1340,274,60]) at (x, y), speaker name at x + `layout+0x28` (10), vertically centred in the 60 px header.
Button style 4 = the 3-slice bar of style 0: caps 1116/1117, middle 1115 (pressed 1122/1121/1123), 70 px high
(gof2_interface_iphone4 [491,884,50,70] / [96,661,200,70] / [1992,451,54,70]). The text scrolls by drag with a
scroll bar when it overflows (`ScrollTouchWindow::draw` 0x1a310c); pages are table entries, not text pagination.
Font: `Globals::font`, **alien font** (`Globals::fontAlien`, magenta glyphs) when the speaker is 19 (Void) or 56
(Corny, robot) — same rule in the radio.

While drawn, the Skip / Next button positions are published in `Globals::other_buttons_x/y[2..3]` and
`is_dialogue_window_visible = 1`: the desktop/controller key layer (`keyReleased` 0x729fc) simulates taps on those
positions. There is no keyboard path to Back.

### 1.3 Portrait composition (`ImageFactory`, `ImagePart`)

- `ImageFactory::reload` 0x1415fc: portrait background **0x485** (gof2_interface2_ipad_large [1459,955,160,200]) and
  frame **0x511** ([1879,249,160,200]).
- Descriptor `int[5] = {bodyType, v0, v1, v2, v3}` (variant per part, −1 = none). `loadChar` 0x1417bc creates one
  `ImagePart` per part with `loadImage(body, part, variant)` 0x141870: image id = `0x2583f0[body][part] + variant`
  (base −1 = part not used), offset = `IMAGE_OFFSETS_IPAD_LARGE` (0x26a84c, `{anchor, y}` per body/part;
  phone `IMAGE_OFFSETS` 0x26ab8c, `_IPAD` 0x26a9ec, `_IPAD_HD` 0x26a6ac). It then swaps slots 0 and 2, so the draw
  order is **part2, part1, part0, part3**.
- `drawChar(parts, x, y, mirror)` 0x1419a0: background at (x, y), each part `ImagePart::draw` 0xb4a48 at
  (x, y + offY) anchored left + top (anchor 16) or left + **bottom** (anchor 32), mirrored in its own width when the
  flag is set, then the frame.
- Part images are separate textures `Textures/textures/<body>_<part>_<variant>[_ipad_large].png` (image ids
  5000–5151; HD parts 160 px wide, heights vary). Race 0 HD offsets: part0 top y 120 (mouth/chin), part1 top y 68
  (eyes), part2 bottom y 200 (body/shoulders), part3 top y 0 (hair).
- Body types (counts 0x258320 = variants per part): 0 Terran male (11/11/11/11), 1 Vossk (4/5/6/9), 2 green
  "Nivelian" body (5/5/5/5; also used by 75 % of Midorian agents), 3 Midorian (no images: `createChar` 0x14173c maps
  it to 0 or 2), 4 Multipod, 5 → 0, 6 Bobolian, 7 Grey, 9 Void, 10 Terran female, 11 computer screen (Computer / Info /
  Story), 12 Corny (cyborg). Verified visually with `portrait.py --sheet`.
- Random agents: `ImageFactory::createChar(male, race)` 0x14173c: Midorian → 1/4 body 0, 3/4 body 2; body 0 and not male
  → 10; 5 → 0; each variant `nextInt(count)`. Stored in `Agent+0x78` (`Agent::setImageParts` 0x1a673c).

**Story speakers** (`PTR 0x2647ec[speaker]`; a duplicate table at 0x26447c is used by the radio; speaker 0 points at
an all-zero .bss array = `{0,0,0,0,0}`), name text `1597 + speaker` (`portrait.py --table`):

| id | name | descriptor | id | name | descriptor |
|---|---|---|---|---|---|
| 0 | Keith T. Maxwell | 0,0,0,0,0 | 32 | Netor | 7,0,0,2,1 |
| 1 | Brent Snocom | 0,8,8,1,8 | 33 | Convoy Captain | 0,5,4,8,3 |
| 2 | Gunant Breh | 2,1,1,1,1 | 34 | Trot Lykkt | 4,1,1,1,1 |
| 3 | Norris Bernard | 0,9,9,8,9 | 35 | Smuggler | 0,4,8,8,4 |
| 4 | Mkkt Bkkt | 4,2,0,2,2 | 36 | Corny | 0,2,10,9,2 |
| 5 | Tommy | 0,2,3,3,10 | 37 | Bargand Surr | 2,4,1,4,1 |
| 6 | Carla | 10,0,0,1,0 | 38 | Moonsprocket | 0,8,3,8,3 |
| 7 | Errkt Uggut | 1,1,0,4,0 | 39 | Trunt Harval | 2,2,1,3,2 |
| 8 | Jean Baffour | 0,6,8,8,7 | 40 | Brillo Lampeter | 6,0,0,2,0 |
| 9 | Pirate Boss | 0,4,8,8,10 | 41 | Drunk Lady | 10,3,3,1,4 |
| 10 | Pirate | 0,3,5,8,6 | 42 | Barkeeper | 0,0,5,4,6 |
| 11 | Pirate | 0,7,7,8,5 | 43 | Dealer | 1,0,3,1,2 |
| 12 | Security | 0,5,4,2,7 | 44 | Dr. Gum'Skratch | 2,4,1,2,3 |
| 13 | Security | 10,1,1,2,4 | 45 | Pal Tyyrt | 1,0,1,1,3 |
| 14 | Hijacker | 2,2,2,4,2 | 46 | Kehnor | 7,0,0,0,0 |
| 15 | Computer | 11,1,0,0,1 | 47 | Hongar Meton | 2,4,2,0,0 |
| 16 | Info | 11,1,0,0,2 | 48 | Industrialist | 2,0,1,1,2 |
| 17 | Story | 11,1,0,0,3 | 49 | Miner | 2,1,0,4,0 |
| 18 | Terran Officer | 0,8,10,10,4 | 50 | Vossk | 1,0,0,3,5 |
| 19 | Void | 9,0,0,0,0 | 51 | Real Estate Broker | 0,3,3,0,5 |
| 20 | Khador | 7,1,1,0,0 | 52 | Real Estate Broker | 10,0,3,3,5 |
| 21 | Midorian | 2,0,0,1,2 | 53 | Real Estate Broker | 0,3,6,0,8 |
| 22 | Nivelian | 2,0,0,0,0 | 54 | Real Estate Broker | 10,3,0,3,3 |
| 23 | Agent | 0,2,10,9,2 | 55 | Hans | 0,10,7,2,1 |
| 24 | Taret Orskk | 1,2,4,3,1 | 56 | Corny | 12,0,0,0,0 |
| 25 | Mekant Orskk | 1,3,1,5,0 | 57 | Barkeeper | 0,0,10,0,7 |
| 26 | Alice | 10,3,3,4,6 | 58 | Barkeeper | 0,6,0,7,4 |
| 27 | Escort | 0,0,5,8,6 | 59 | Freighter Captain | 2,3,1,1,4 |
| 28 | Pirate | 0,8,8,8,0 | 60 | Gunant IV | 2,1,4,2,0 |
| 29 | Pirate | 0,4,8,8,4 | 61 | Deep Science Escort | 0,0,4,3,5 |
| 30 | Pirate | 0,0,5,8,10 | 62 | Barkeeper | 0,10,2,9,4 |
| 31 | Cornelius Tenner | 0,2,10,9,2 | | | |

Body 11 and 12 use only part 0 (the other bases are −1): Computer, Info and Story all show the same data-screen image
(`11_3_3`); the "i" icon (`11_3_2`, variant 0) is unused by story speakers. Names 1660–1667 (Vossk, Terran, Nivelian,
Informer, Arms delivery, Generator, Turret, Battleship) have no descriptor (radio ids ≥ 63 get a random face, §2.3).

### 1.4 Campaign page tables (`loadContent` 0x194cd0, `length` 0x195ca4)

- `0x259ed0 int[162]` briefing word counts, `0x25a158 int[162]` success word counts (pages = count / 2;
  `hasBriefingDialogue` 0x194c90 / `hasSuccessDialogue` 0x194cb0 test count > 0).
- `0x25a3e0` briefing pages and `0x25a5c0` success pages: `(speaker, textId)` pairs concatenated in mission order;
  `init` precomputes each mission's start offset.
- Page k of mission m: speaker → portrait `PTR 0x2647ec[speaker]` and name `text(0x63d + speaker)`; mirror flag =
  (speaker == 0). Totals: 60 briefing pages, 1028 success pages. **Full table: `dialogue_tables.py`**; base-game
  missions 0–44 are in the appendix.
- "Success" of mission N is the conversation that plays when mission N is completed, and usually sets up mission N+1
  (e.g. mission 1's 19 pages are Keith waking up on Var Hastra). Base game = missions 0–44 (voices in `VOICE_*`),
  Valkyrie add-on ≈ 46–84 (`DLC_VOICE_*`), Supernova add-on ≈ 85–161 (`DLC2_VOICE_*`).
- Special cases in `loadContent`:
  - Success text 0x6b6 (1718) / 0x6c2 (1730) and briefing global pages in bitmask 0xa0200a / 0x23: pass through
    `Globals::replaceKeyBindingTokens` (control-hint texts).
  - Success text 0x729 (1833, the Alioth alarm, mission 15): stop the music, play **136** `Space_Combat_Void` and **162**
    `Alert`. Skipping mission 15's dialogue plays the same two (OnTouchEnd).
  - Text 0xade (2782) in German: speaker shown as Keith.
  - Texts 0x891/0x892 (2193/2194) are replaced by 2191/2192 when the mission status value is 1 (the `…_NO_LIB`
    voice variants).
  - Failure (mode 2) of a campaign mission: speaker 16 (Info), text = 392 "Mission failed!" + (missions 38, 40, 41:
    527) + 319 "Game Over"; one page.
- Non-campaign missions (freelance/agents): one page (except the home-base broker). Portrait/name = mission client
  (`Mission::getClientImage` / `getClientName`). Briefing: type 0xc → 372, type 7 → 378, else random of
  `0x25c6b0` (379–383). Success: type 5/3 → 389 "Return to #S…"; type 0xc → 370 + (story agent: 389); type 0xb7 →
  random `0x25c6c4` (373–377) + "Kills: n"; else random 373–377 + 389 (story agent) or 216 "Mission accomplished!";
  target station 108 → 458. Failure: type 0xc → 371 (`#Q1/#Q2` = times), else random `0x25c6d8` (384–388) + 392.
  German picks the text per race/gender from `0x25c6ec/0x25c73c/0x25c78c`
  (`pickGermanGenericTextBecauseWeSaved100EurosWithThat` 0x195d40) so it matches the few recorded German lines.
  Success also calls `Standing::applyMissionCompleted(clientRace)`.
- Home base (Kaamo Club, station 108) broker: a non-campaign mission targeting station 108 uses `0x25c5f0`
  (18 pages, first visit, when `Status+0x114 == 2`) or `0x25c680` (6 pages, purchase); speakers 4 (Mkkt Bkkt) and 0.

### 1.5 Input, sounds, auto-advance

- `OnTouchEnd` 0x196020: Back → stop voice, page−1; Next → stop voice, `nextPage` (0x195c7e); **Next on the last page
  closes** (returns 1). Skip → `ChoiceWindow::set(396 "Skip the dialogue?")` (header 390 "Info", buttons Yes 134 /
  No 135); Yes (result 0) closes the dialogue (stop voice; mission 15 plays 162 + music 136), No returns.
  While the ChoiceWindow is open it takes all touches.
- Voice: `loadContent` stops the previous voice, `Globals::getDialogueSoundId(textId, agent)` 0xfa110 (§5.3),
  plays it (2D) and reads `FModSound::getEventPauseLength` (FMOD event property "pause").
- `update(dt)` 0x195bf0: if voice is enabled (`options[0xe]`) and the event stopped and this is not the last page:
  count `+0x60` up by dt; when it reaches the pause length → `nextPage`. No auto-close.
- No dedicated open/close sound in the window (the TouchButtons play the generic button sounds, 124/123).

### 1.6 Who opens it and what happens after

| When | Code | Mode |
|---|---|---|
| Flight level start: after the start sequence (`LevelScript::startSequenceOver`), if the campaign mission has a briefing, or for a visible non-campaign mission (not types 0, 8, 0xa6, 0xb7, and not 0xb) | `MGame::dialogueEvent` 0x1b0498 | 0 |
| Mission completed in flight (`Status::missionCompleted`) and the campaign mission has success pages (campaign missions > 45 without pages advance silently) | `MGame::successCheck` 0x1b0620 | 1 |
| Docking/in the station with a completed mission (`Status::missionCompleted(true, loungeIntroFinished)`) | `ModStation::OnUpdate` 0xed2a8 | 1 |
| Mission failed in the station / game-over check in flight | `ModStation::OnUpdate`, `MGame::gameOverCheck` 0x1b0d04 | 2 |
| Valkyrie add-on start (option 0x35 owned, base game won, free flight) / Supernova start (option 0x37, add-on 1 won) | `MGame::OnUpdate` 0x1ac778 | 1 with mission index 46 / 85 (dummy mission type 0xa0), then campaign += 2 |
| Supernova station visits 0x94–0x97 | `ModStation::OnUpdate` | 1 with index 0x94–0x97 |

Opening in flight pauses the game (`MGame+0x5d`, `pauseSounds`), resets the chase camera, leaves turret/free-look/
first-person views, and **resets the level-script clock** (`LevelScript+8/+0xc = 0`, which drives radio timers).
Closing (`MGame::OnTouchEnd` 0x1a98d8): resume sounds; failed campaign mission → music 2, back to the main menu
module; failed freelance mission → penalties (type 0xc: −reward; types 3/5/0xb: remove the delivery item) and clear
the mission; won → `Status::nextCampaignMission` or the reward message; neither (briefing) →
`LevelScript::resetStartSequenceOver`. In the station, closing mission 43's success conversation starts the ending
(§3.4), other campaign missions advance with `nextCampaignMission` (not for 0x94).

### 1.7 One-page message variant

`DialogueWindow(text, name, portrait)` 0x194a94: text only, Back and Skip hidden, Next replaced by **OK** (524) centred,
portrait from the descriptor, no voice (callers play it). Uses: pirate outpost station unmanned (434, "Security"
1609, descriptor 0x26a1c4 = {2,0,0,0,0}), wingmen contract expired (313, wingman portrait), pirate outpost destroyed
reward (442, "Nivelian", sound 0x24d), Sahi requirement (532, "Carla", 0x26b8e0), Supernova station greetings
(texts 2716+, sound 0x619+).

---------------------------------------------------------------------------------------------------

## 2. Radio messages (`game/Radio.c`, `game/RadioMessage.c`)

### 2.1 Data

`RadioMessage` (0x28 bytes): +0 Radio*, +4 Objective*, +8 **text id**, +0xc **image id** (= speaker), +0x10
**trigger type**, +0x14 param, +0x18 count, +0x1c int[count] enemy indices (param, param+1, …), +0x20 triggered,
+0x21 over, +0x24 last route waypoint. Constructors: `(text, image, type, param)` 0x17c4d0 (list = [param]),
`(text, image, type, param, count)` 0x17c512, `(text, image, Objective*)` 0x17c574 (type 0xb).

Sources of messages (a Level holds one array, `Level+0x114`, handed to `Radio::setMessages` 0x180340):
- `Level::createRadioMessages(campaignMission)` 0xd0574 — the campaign script: 66 missions, 309 messages
  (**full table: `radio_tables.py`**, validated: every case's message count equals its `ArraySetLength`).
- `Level::createRadioMessage(kind, race)` 0xd5568 — generic chatter (only with no active mission; replaces the
  array with one message): friendly fire, alarm, "He's back", pirate outposts, black market, Wanted (see
  `npc_traffic_ai.md` §8). Speaker by race: 0 → 0x40, 2 → 0x41, 3 → 0x15, 8 → 9, else 0x3f.
- `ModStation` builds its own Radio for the ending (§3.4).

### 2.2 Triggers (`RadioMessage::triggered` 0x17c5d8)

Evaluated only while no message is showing, in array order; the first newly-true message is shown; a triggered
message never shows again. "time" = the caller's clock: in flight the level-script clock `LevelScript+8`
(reset when the briefing opens), in the station ending `ModStation+0xb0`.

| type | condition | uses |
|---|---|---|
| 0 | player route's current waypoint moved past `param` | 0 |
| 1 | any listed enemy dead | 2 |
| 2 | any listed enemy with `Player+0x5d` dead | — |
| 3 / 4 | no enemies / no friends left | — |
| **5** | time ≥ param ms | 55 |
| **6** | message #param has triggered (chain: shows right after it) | 167 |
| 8 | any listed non-asteroid enemy active | 1 |
| 9 | all listed enemies dead | 4 |
| 10 | any listed enemy with +0x5d active | — |
| 0xb | Objective achieved | — |
| 0xc / 0x13 / 0x1f | any listed enemy below 1/2 / 1/4 / 3/4 hit points | 3 / 1 / 1 |
| 0xe / 0x15 | `KIPlayer(enemy[param])` flag +0x65 / +0x20 set | — / 1 |
| 0xf | any non-asteroid enemy dead | — |
| 0x10 | any active non-asteroid enemy that is not always-friend | 5 |
| 0x11 | fires (decompiled loop always ends in "trigger"; uncertain) | — |
| 0x12 | enemy[param] +0x65, else +0x66 | — |
| 0x14 | ≥ param non-asteroid enemies dead | 5 |
| 0x16 | `Level+0x1c` ≥ param | 1 |
| 0x17 | `Radar::stationLocked()` | 1 |
| 0x18 | enemy[param] inactive, alive, time > 60 000 | 1 |
| 0x19 | route advanced from waypoint 0 and ≥ param enemies alive | 1 |
| 0x1a | enemy 0 active, alive, within 5000 units of param on one axis | 1 |
| **0x1b** | `LevelScript::getEvent() == param` (cutscene step) | 55 |
| 0x1c | player armor HP < 1 | 1 |
| 0x1e | dead enemies among indices 2..5 == param | 3 |

### 2.3 Display (`Radio::update` 0x180380, `Radio::draw` 0x1806b8)

- When a message triggers: portrait = speaker descriptor (`PTR 0x26447c[image]`) for image < 63 except 21;
  image 21 (Midorian), 63 (Vossk), 64 (Terran), 65 (Nivelian) and higher → a **random** face
  (`createChar(true, race)`, race 3/1/0/2/1…); image ≥ 10000 → Wanted person `image − 10000` (their parts and name).
  Text wrapped with `Globals::getLineArray` to `840 − 10 − 160` = 670 px; alien font for speakers 19/56.
  Duration `+0x28 = lines·2000 + 1500` ms; voice id from `getDialogueSoundId(text, tempAgent(race, male))`.
- `draw(time)`: nothing until `time > start + 2000`; on the first visible frame play the voice once; box
  `drawBox(7, x, y, 840, max(lines·30, 200) + 60 + 10, name)` with draw colour 0xffffff2f (translucent),
  x = (1920 − 840) / 2 = **540**, y = `layout+0x9c` = **100**; portrait at (x+5, y+60+5), unmirrored; text lines at
  (x+160+7, y+60+7), line height 30. After `start + duration + 2000` → `finish`, clear; if it was the array's last
  message `lastMessageShown` = true.
- Not modal. Fast-forward is blocked while a message shows (`MGame::OnUpdate` 0x1ac778). `Hud::draw` hides some
  prompts while a message shows (0x1926f6). In flight the radio is drawn from `MGame::OnRender2D` 0x1b10bc, but not while the start sequence (launch /
  arrival camera) runs (`startSequenceOver || !startSequence`).
- Skipping a cutscene marks its radio lines triggered + finished (`LevelScript::skipCutscene`, §3.2).

---------------------------------------------------------------------------------------------------

## 3. Cutscenes

### 3.0 `CutScene` is not the story player

`game/CutScene.c` (`CutScene(int levelType)` 0xa3e1c, `initialize` 0xa4074, `process` 0xa49f4, `resetCamera` 0xa3f4c,
`replacePlayerShip` 0xa53b4, `checkForTurret` 0xa4594) renders the **3D backgrounds of non-flight screens**:
type 2 = the space backdrop of the main menu (`ModMainMenu::OnInitialize` 0x1a46dc) and of the ending credits
(`ModStation::OnUpdate`), 0x17 = the station hangar with the player's ship (`ModStation::OnInitialize` 0xe8080;
`checkForTurret` mounts the turret model: item 47/48/49/180/181/182/198/199/200/224 → meshes 0x1a72…/0x4963…;
`replacePlayerShip` swaps the model after a ship purchase; Vossk hangars get fog), 4 = the space lounge
(`SpaceLounge::SpaceLounge` 0x197890; race props 0x36d6 / 0x37c8+0x37c7). These are covered by `station_interior.md`
and `mainmenu_notes.md`.

The story cutscenes are scripted in **`LevelScript::process`** (0x160d50) inside normal flight levels.

Details (per-step tables, camera positions, sounds, constructor setup): **`levelscript_cutscenes.md`**. Summary:

### 3.1 LevelScript cutscenes

- `LevelScript::process` returns the **cutscene-active flag** `this[0x11]` (stored in `MGame+0x5f`): HUD, radar and
  lock plate are not drawn, the player is computer-controlled (often invulnerable/hidden), the camera is a fixed
  look-at camera (`TargetFollowCamera::setLookAtCam`) repositioned per step and dollied per frame; giving control
  back calls `resetCamera` (chase offsets). Step counter `+0x1c` (= radio trigger 0x1b), step timer `+0x90`, level
  clock `+8`.
- Every level starts with the generic 7 s fly-in (`+0x20` startSequence, `+0x24` timer); the campaign scripts are
  mostly driven by their own radio messages (step advances when msg[n] fires/ends), so the radio table (§2) and the
  script are one unit.
- Decoded scenes: **M0** prologue (pirate ambush, hyperdrive accident with fx mesh 15027, time-space jump with
  sounds 157/158/160/159, planet/skybox swap, fade to black → M1), **M1** Var Hastra salvage (fixed camera, fade in/out
  → station), **M14** Terran arrest (EMP, flash, cruiser), **M16** first Void contact (wormhole), **M24** the wormhole
  takes Keith, **M29** probe launch, **M40/M41** Errkt's freighter and death (sound 155 `Errkt_CutSeq_01`), **M42**
  mothership explosion and wormhole escape (153/154). Partly decoded: add-on scenes (M78, 80, 81, the Supernova intro
  M89 with its white flash and sun growth, "Meanwhile…" interludes, M105/106, M144/145, M154/157/158).

### 3.2 Skip rules

- Fly-in: a tap during the start sequence → `LevelScript::skipSequence` 0x16f57c (timer to 7001, player vulnerable;
  not in mission 0).
- Story cutscenes are **not skippable** in the base game. The pause menu offers Skip (395) only for missions 154, 157,
  158 while `canSkipCutsceneNow` 0x16f5b8 allows; `skipCutscene` 0x16f61c marks their first 8/4/3 radio messages
  triggered + finished and jumps the step/timers. (MGame's skip branches for M0/M1 have no button in this build.)
- Dialogue pages have their own Skip (§1.5).

### 3.3 Presentation

- No letterbox bars, no text overlays other than the radio box: captions ("3598 A.D. …", "Meanwhile…") are radio
  messages from speaker 17 "Story". The dialogue window and radio are still drawn during cutscenes (the radio not
  during the generic fly-in).
- Fades: `Layout::startFade(out, colour, ms)` / `drawFade` 0xe7978 (black or white full-screen alpha ramp), opaque
  black fill over level switches, `Level::flashScreen`, camera rumble `setRumblePercentage`.
- `Globals::isCinematicModeActive` / `MGame::setCinematicMode` / `MenuTouchWindow::inCinematicMode` are the "Action
  Freeze" photo mode, not story cutscenes.
- Sound id note: `levelscript_cutscenes.md` calls id 161 disputed; §5.2 resolves it (161 = `Engine_09_Broken`, matching
  its use as a stopped engine loop in M0; 162 = `Alert`).

### 3.4 Intro (new game) and ending

- **New game**: main menu → `MenuTouchWindow::startGOF2` 0x1540f0: `Status::resetGame`, stop music, play **143
  `IntroAtmo`**, switch to module 2 (MGame) = campaign mission 0, the prologue flight. There is no video and no
  still-image intro; the "intro" is that level's script (§3.1) and radio 0, which opens with the caption 1668 as a
  radio message from speaker 17 "Story" at 1500 ms. Mission 0's briefing (two Info pages 1677/1680, control
  tutorial) opens after the start sequence. `MTitle` (module 0) only shows the splash logos.
- **Ending** (`ModStation::OnTouchEnd` 0xea4ec, when mission 43's success conversation closes, i.e. after Carla's
  "drink" pages): remove the mission, stop music, play **144 `OutroSong`**, station Radio with 4 messages from speaker 1
  (Brent): 2071 at 4000 ms, then 2072, 2073, 2074 chained. `ModStation+0xb0` is the clock, starting at −12 000 ms.
  `ModStation::OnUpdate` 0xed2a8 / `OnRender2D` 0xef208:
  - −12 000…−6000 ms: fade (colour ramp over 6 s); at −6000 the space backdrop `CutScene(2)` is created (camera speed
    `+0x24` = 3e-5) and faded in until 0.
  - After the last radio line: the logo image **0x1b5a** (`gof2_logos_ipad2` [0,0,452,156]) rises from below the
    screen at 0.03 px/ms (30 px/s) to the screen centre, holds **4000 ms**, then rises again together with the
    credits text **48** (centred `ScrollTouchBox`, width w − 100) under it.
  - From 130 001 ms a fade out; at > 136 000 ms (0x21340) → `nextCampaignMission` (44) and reload the station
    module. A tap after the last radio line ends the sequence at once (`ModStation::OnTouchBegin` 0xea154).
  - Mission 44's success pages (Keith alone the next morning, 2075–2078) then play in the station: the base story's
    epilogue; free play continues.

---------------------------------------------------------------------------------------------------

## 4. ChoiceWindow and story choices

`ChoiceWindow` (0x170014…) is a generic modal box: header (default 390 "Info"), text, buttons Yes (134) / No (135) /
OK (524) or custom; `OnTouchEnd` 0x170e10 returns 0 / 1 / 2 for the first/second/third button, −1 otherwise. In the
story it is used only to confirm "Skip the dialogue?" (396) and for blocking notes in flight (e.g. 3217 Gamma Shield
required, 579/583/612 Khador Drive/cloak energy, 290–292 ore conversion) — **no branching choices** exist: every
campaign mission has one briefing, one success and one failure path. No comic / still-image story screens exist
(no such textures; the only story image is the ending logo 0x1b5a).

---------------------------------------------------------------------------------------------------

## 5. Voice acting

### 5.1 Files

FMOD banks → `Assets/Audio/<bank>_<lang>/` (`FModSound::init` 0x9d78c loads `FMOD_GOF2.fev`,
`EventSystem::setLanguage` chooses `_eng` / `_deu`; switching to/from German re-creates FModSound):

| folder (.ogg count per language) | content |
|---|---|
| `VOICE_eng/deu` (403) | base story: `MISSION_<m>_<page>` (briefing), `MISSION_END_<m>_<page>` (success), `RADIO_<m>_<index>`, a few `MSG_MISSION_2x_…` reminders |
| `GENERIC_eng/deu` (204) | generic agent radio per race: `<RACE>_MISSION_RADIO_{START,WON,LOST}_n / _CHALLENGE / BACK_FOR_REWARD / JUNK_START`, `<RACE>_MSG_{ENTER_HOSTILE_ORBIT,FRIEND_TURNED_ENEMY,FRIENDS_ALARMED,WINGMEN_TIMEUP}_n`, pirate outpost `MSG_RADIO_PIRATE_STATION_*` |
| `LOUNGE_eng/deu` (321) | bar greetings `<RACE>_GREETING_LOUNGE_<kind>_nn` |
| `DLC_VOICE_eng/deu` (425) | Valkyrie add-on (`MISSION_48_0` …, `MISSION_58_SUB_n` …) |
| `DLC2_VOICE_eng/deu` (690) | Supernova add-on (`MISSION_*`, `RADIO_*`, `CARLA_ANNOYING_CALL_*`, `BLUEPRINT_RECOVERED_*`, `WANTED_*` …) |
| `CUTSCENES` (28) | cutscene SFX (mothership explosion loops, `Alert_03`, …) |

Races in generic names: TERRANMALE, TERRANFEMALE, VOSSK, NIVELIAN, MULTIPOD, BOBOLAN, GREY.

### 5.2 FMOD event ids (`fev_events.py`)

`FModSound::play(id)` 0x9dea8 → `EventSystem::getEventBySystemID(id)` (ids < 0x8f5 = 2293). The FEV's `STRR` chunk
lists event, group and parameter names in project order (then sound-definition names from `/Atmo_…` on). Event id =
index among event names, where groups (all-caps, no digits, not an .ogg name) and parameters (lower-case, plus
`SpawnIntensity`, `Vertical`, `Horizontal`, `Loop`, `Whoosh_Loop_Speed_Param`; `game_over` is an event) are skipped,
**and ids 656–659 are four events whose names are missing from STRR (duplicates stored once), so every id ≥ 660 is
shifted by 4**. Validation: 1343 of the voice table's text→event pairs whose event name can be derived from the
dialogue/radio tables land exactly on that name; the 24 others are naming variants (`MISSION_END_60_0_NO_LIB`,
`MISSION_START_135_n`, `MISSION_WRONG_148_x_y`, `RADIO_125_0a/1f`, skipped index in mission 125's radio names);
generic-voice anchors in `getDialogueSoundId` confirm offset 0 up to 655 (Nivelian set) and +4 from 660 (Terran
female, Terran male, Vossk, Bobolan).

Consequences for `fmod_event_ids.txt` (ids 0–161, heuristic): it misses the event `TimeSpaceJumpEnd`, so its entries
159–161 are one too low: **159 TimeSpaceJumpEnd, 160 SpaceTimeJump, 161 Engine_09_Broken, 162 Alert** (confirmed:
`DialogueWindow` plays 162 with the "Alert!" line 1833). 0–158 agree (e.g. 136 `Space_Combat_Void`, 143 `IntroAtmo`,
144 `OutroSong`, 145 `Space_NoCombat_Void`). Voice events start at 163 (`MISSION_11_0`).

### 5.3 Which line plays which event (`Globals::getDialogueSoundId(textId, agent)` 0xfa110)

1. Look the text id up in `0x255210` (1504 `(textId, eventId)` pairs, events 163–2237). Story dialogue pages, story
   radio and many named messages resolve here (`fev_events.py --voice-table`: 1489 have an .ogg; missing:
   `MISSION_END_44_2`, `58_9`, `83_3`, `95_8`, `95_14`, `116_4`, `121_5`, `140_1`, `140_10`, `143_1`, `159_1`,
   `159_6`, `159_10`, `161_5`, `MOONSPROCKET_PASSENGER_TALK_0_1`). Info/Story/computer caption pages have no entry
   (silent) except where recorded (Computer lines are voiced).
2. Otherwise (generic agents), by agent race (+ gender) and text id: texts 370–389 (freelance briefing/success/
   failure/"return for reward"), 426–431 (friend turned enemy / alarmed), 445–447 ("He's back"), 313 (wingmen time
   up), pirates 435–440 → id `text + 0x9b`. Race 0/5 male → TERRANMALE set, female → table `0x258110`; 1 Vossk;
   2 Nivelian; 3 Midorian → Nivelian set if `imageParts[0] == 2` else Terran; 4 Multipod; 6 Bobolan; 7 Grey; 8 pirates.
   No match → −1 (silent).
- The DialogueWindow passes the mission's agent (campaign: usually none → table only); the radio passes a temporary
  `Agent(race, male)` derived from the portrait (body 10 → female Terran, image 9 → race 8).

---------------------------------------------------------------------------------------------------

## 6. Remake implementation notes

**Data.** Generate `story.json` with `story_table.py` (ids only) into `Assets/Resources/GoF2Data/` when implementing;
load with JsonUtility (flatten the nested voice objects if needed). Text via `Localization.Get(id)`. Voice clip
path = `Audio/VOICE_<lang>/…` from the table (`eng`/`deu` fields), German when the UI language is German, English
otherwise (like FMOD's two language banks).

**Portraits (`Portrait`, plain C# + a VisualElement).** Descriptor → up to 4 layers + background + frame, in the
order bg, part2, part1, part0, part3, frame; each layer at (0, y) top- or bottom-anchored per `offsetsHD`, width 160,
native height; mirrored with `scale: -1 1` for Keith in the dialogue window. Build the textures with an editor step
(like "Build HUD Images") that crops the `_ipad_large` part PNGs and the two atlas rects into `Resources/GoF2Portraits`,
or pre-compose the 63 story portraits (`portrait.py --speaker`) plus a runtime compositor for random agents
(`createChar` rules) — the bar visitors already need the same data.

**DialogueWindow (UI Toolkit, `UI/Dialogue/`).** Modal overlay: full-screen dim, a 694×486 panel (scale with the
panel settings; reference 1920×1080) with a 60 px header showing the speaker name, the portrait at (10, 70), a
ScrollView text area (inset 10) right of it, footer buttons Back (left, only page > 0), Skip (centre, only when > 1
page), Next/Close (right). Controller: A = Next, B = Back, Y/Menu = Skip (confirmation dialog 396 with Yes/No);
keyboard Enter/Space = Next, Backspace = Back, Esc = Skip. `GoF2DialogueController` (plain C#) holds mode, pages,
index; events `Closed(result)` → the caller advances the campaign / clears the mission as in §1.6. Pause the flight
game (`Time.timeScale = 0`, audio paused except the voice/UI sources) while open; reset the level-script clock when a
briefing opens. Auto-advance when the voice setting is on: clip end + pause (FMOD "pause" property unknown → use
~500 ms, tweakable; uncertain). Alien-font speakers (19, 56): a separate font asset (the magenta glyph font 1310 is in
`gof2_interface`).

**Radio widget (flight HUD).** `Radio` (plain C#: message list, trigger evaluation per §2.2 against a context
interface for enemies/route/time/script step) + `GoF2RadioView` in `UI/Flight`: an 840 px wide panel at y = 100,
centred, header 60 with the name, portrait 160×200, text 670 px wide (30 px lines), translucent; appears 2 s after the
trigger, stays `lines·2000 + 1500` ms (count lines after layout), voice at appearance. Do not pause the game; block
fast-forward while visible (already a rule in the remake's navigation). The existing NPC chatter (combat HUD
messages "Hold your fire!" etc.) should move into this widget with the race portrait rules.

**Cutscene player.** Keep cutscenes as per-mission scripts on top of the flight level (a `GoF2LevelScript` step machine
with `event` counter, timers and camera modes — fixed look-at, drifting look-at, chase offsets; see §3.1), exposing
`Event` for radio trigger 0x1b and `CanSkip`/`Skip` per §3.2. HUD hidden and input disabled while a script step owns
the camera; a Skip prompt (tap / Esc / B). The ending is a small station-scene state (radio + music 144 + logo +
credits scroll + fades) and the new game simply loads the Space scene with campaign mission 0 and music 143.

**Order.** Portrait compositor → DialogueWindow + voice → radio → campaign mission 0/1 scripts (prologue and Var Hastra
arrival) → the rest with the missions system.

---------------------------------------------------------------------------------------------------

## 7. Uncertainties

- `drawMask` colour and the radio's `setDrawColor(-0xd1)` meaning (alpha vs tint) were not traced to pixels.
- FMOD "pause" property values per event are inside the FEV's legacy (`LGCY`) data; not parsed.
- The 4 unnamed event ids 656–659 (duplicate-named events between the Nivelian and Terran-female generic sets).
- `Status::missionCompleted(bool, bool)` second argument (passed "lounge intro finished") semantics; `Status+0x114`
  (home-base state) meaning.
- Radio trigger 0x11's decompiled loop looks like it always triggers; check the disassembly before using it.
- Mission ranges of the add-ons (46–84 / 85–161) are inferred from the voice folders.
- Body type labels (2 = "Nivelian" green body) follow the portraits and `createChar`; the lore names may differ.

---------------------------------------------------------------------------------------------------

## Appendix: base-game pages and radio (missions 0–44)

`speaker:text` (runs of consecutive text ids from one speaker compressed as `first-last`); radio
`speaker:text/trigger:param` (`param+count` for lists). Speaker ids in §1.3; trigger types in §2.2.
Voice: look the text id up with `fev_events.py --voice-table`.

| # | briefing (speaker:text) | success (speaker:text) | radio (speaker:text/trigger:param) |
|---|---|---|---|
| 0 | 16:1677 16:1680 | - | 17:1668/5:1500 0:1669/6:0 0:1670/6:1 10:1671/6:2 11:1672/6:3 9:1673/6:4 9:1674/6:5 9:1675/6:6 0:1676/6:7 0:1683/9:0+3 0:1684/6:9 0:1685/6:10 15:1686/6:11 0:1687/6:12 0:1688/6:13 0:1689/6:14 0:1690/27:12 15:1691/6:16 0:1692/6:17 15:1693/6:18 0:1694/6:19 0:1695/6:20 15:1696/6:21 |
| 1 | - | 0:1700 2:1701 0:1702 2:1703 0:1704 2:1705 0:1706 2:1707-1708 0:1709 2:1710-1711 0:1712 2:1713 0:1714 2:1715-1716 0:1717 16:1718 | 2:1697/5:10000 2:1698/6:0 2:1699/6:1 |
| 2 | 0:1721 2:1722 0:1723 2:1724 16:1725 | 2:1728 0:1729 16:1730 | - |
| 3 | - | 2:1733 0:1734 2:1735 0:1736 2:1737 | - |
| 4 | 2:1738 | 0:1739 2:1740 | - |
| 5 | - | 2:1741 0:1742 2:1743 0:1744 2:1745 16:1746 | - |
| 6 | - | 2:1747 | - |
| 7 | 2:1748 16:1749-1750 16:1753 | 2:1758 0:1759 2:1760 0:1761 2:1762 | 2:1756/16:0 0:1757/6:0 |
| 8 | - | 2:1763 0:1764 2:1765 0:1766 2:1767 0:1768 2:1769 0:1770 2:1771 | - |
| 9 | - | 17:1772-1774 2:1775 0:1776 2:1777 0:1778 2:1779 0:1780 2:1781 16:1782 | - |
| 10 | - | 3:1783 0:1784 3:1785 0:1786 3:1787 0:1788 3:1789 0:1790 3:1791 0:1792 3:1793 0:1794 | - |
| 11 | 0:1795 | 0:1796-1797 4:1798 0:1799 4:1800 0:1801 4:1802 0:1803 4:1804 0:1805-1806 4:1807 0:1808 | - |
| 12 | - | 3:1809 0:1810 3:1811 0:1812 3:1813 0:1814 3:1815 16:1816 | - |
| 13 | - | 3:1817 0:1818 | - |
| 14 | 0:1819 | - | 18:1820/5:10000 18:1821/20:1 0:1822/6:1 18:1823/6:2 17:1824/6:3 |
| 15 | - | 17:1825 1:1826 0:1827 1:1828 0:1829 1:1830 0:1831 1:1832 12:1833 0:1834 1:1835 | - |
| 16 | 1:1836 0:1837 | 1:1843 0:1844 1:1845 | 19:1838/5:10000 0:1839/6:0 0:1840/9:0+3 1:1841/6:2 0:1842/6:3 |
| 17 | - | 1:1846 0:1847 1:1848 0:1849 1:1850 0:1851 1:1852-1853 0:1854 1:1855 0:1856 1:1857 0:1858 1:1859 0:1860 1:1861 16:1862 | - |
| 18 | - | 0:1863 13:1864 0:1865 13:1866 0:1867 1:1868 0:1869 1:1870 | - |
| 19 | - | 1:1871 0:1872 1:1873 0:1874 1:1875 | - |
| 20 | - | 0:1876 | - |
| 21 | 1:1877 16:1878 | 1:1886 | 10:1881/16:0 0:1882/6:0 10:1883/25:2 14:1884/8:0 14:1885/21:0 |
| 22 | - | 5:1887 0:1888 5:1889-1890 0:1891 5:1892 0:1893-1894 5:1895 16:1896 | - |
| 23 | 5:1897 | 6:1898 0:1899 6:1900 0:1901 6:1902 0:1903 6:1904 0:1905 6:1906 0:1907 6:1908 0:1909 16:191-192 | - |
| 24 | 6:1913 0:1914 6:1915 0:1916 | - | 19:1917/5:12000 6:1918/6:0 0:1919/6:1 6:1920/22:3 6:1921/6:3 |
| 25 | - | 6:1922 0:1923 6:1924 | 0:1925/5:20000 6:1926/6:0 0:1927/6:1 |
| 26 | 6:1928 0:1929 6:1930 | 6:1931 0:1932 | - |
| 27 | - | 6:1933 0:1934 17:1935 6:1936 0:1937 6:1938 0:1939 6:1940 0:1941 6:1942 0:1943 | - |
| 28 | - | - | 0:1944/5:20000 19:1945/6:0 0:1946/6:1 |
| 29 | 0:1947 | 0:1954 | 0:1948/23:0 0:1949/6:0 0:1950/6:1 0:1951/6:2 19:1952/5:120000 0:1953/6:4 |
| 30 | - | 0:1955 6:1956 0:1957 6:1958 0:1959 | - |
| 31 | - | 1:1960 0:1961 1:1962 0:1963 1:1964 0:1965 1:1966 0:1967 1:1968 0:1969 | - |
| 32 | 0:1970 | 20:1971 0:1972 20:1973 0:1974 20:1975 0:1976 20:1977 0:1978 20:1979-1980 0:1981 | - |
| 33 | - | 20:1982 0:1983-1984 6:1985 0:1986 6:1987 0:1988 6:1989 0:1990 | - |
| 34 | - | 1:1991 0:1992 1:1993 0:1994 1:1995 0:1996 1:1997 0:1998 1:1999 0:2000 1:2001 0:2002 1:2003 0:2004 1:2005 | - |
| 35 | - | 7:2006 0:2007 7:2008 0:2009 7:2010 0:2011 7:2012 0:2013 7:2014 0:2015 | - |
| 36 | 7:2016 0:2017 | 7:2018 0:2019 | - |
| 37 | - | 1:2020 0:2021 1:2022 0:2023 1:2024 0:2025 1:2026 0:2027 | - |
| 38 | 0:2028 | 0:2030 1:2031 | 21:2029/5:15000 |
| 39 | - | 1:2032 0:2033 1:2034 0:2035 1:2036 0:2037 1:2038-2040 0:2041 | - |
| 40 | - | - | 0:2042/5:10000 8:2043/6:0 0:2044/6:1 7:2045/5:40000 0:2046/6:3 7:2047/12:0 0:2048/24:0 |
| 41 | 0:2049 7:2050 0:2051 | 0:2058 7:2059 0:2060 7:2061 0:2062 | 0:2052/5:80000 7:2053/6:0 0:2054/6:1 7:2055/6:2 7:2056/26:-100000 7:2057/6:4 0:2063/1:0 0:2064/6:6 |
| 42 | - | 0:2065-2066 6:2067 0:2068 | - |
| 43 | - | 0:2069 6:2070 | - |
| 44 | - | 0:2075-2078 | - |
