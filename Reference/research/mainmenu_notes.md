# GoF2 main menu: research notes (decompiled libgof2hdaa.so, Android 2.0.16 "FHD" mod)

Addresses are Ghidra addresses (image base 0x10000). Text IDs resolve through `Assets/Localization/text_en.json` (a plain array, index = ID; `GameText::getText` has no remap table in use; only IDs 5000/5001 are special: hardcoded "Privacy Policy"/"Terms of Service").
Image IDs are `images2D` in `resources.json`. **Sub-rect rule (verified visually):** an image's region = `regions[rank]` in `Textures/_texture_manifest.json`, where rank = position of the ID in the *sorted* list of all images2D IDs sharing the same `textureId`. (Not id - base: gof2_interface IDs have gaps.) Helper: `scratchpad/img.py <id>`.
FMOD event IDs: see section 4 and `scratchpad/fmod_event_ids.txt` (new, full list of 162 SFX/music IDs).

Helper scripts written to the scratchpad: `fn.py` (line in _ALL_FUNCTIONS.c -> function), `tx.py` (text IDs), `img.py` (image ID -> texture + rect), `plt.py` (PLT stub address -> imported symbol; lets you name the `blx #0x6xxxx` calls in capstone output), `fevmap.py` / `fev_strings.txt` / `fmod_event_ids.txt`.

---------------------------------------------------------------------------------------------------

## 0. Application modules (OnCreateApplication @0x000e1ed0)

| module id | class | role |
|---|---|---|
| 0 | `MTitle` | splash logos (first module, `SetCurrentApplicationModule(0)`) |
| 1 | `ModMainMenu` | main menu (3D background + title logo + `MenuTouchWindow(0)`) |
| 2 | `MGame` | in space (flight) |
| 5 | `ModStation` | docked station |

Also: `SetLoadingCallback(loadingScreen)`, `Status::resetGame`, `AERandom::reset` (time-seeded Java LCG), language from device country code, `Globals::loadFont`. `Globals::init` @0x000f7a90 sets option defaults (see 2.6) and `recordSlots = 6` (phone) / `12` (iPad).
Hidden cheat codes registered: "754753835", "448366639", "373352623".

## 1. Startup flow before the menu

1. **MTitle** (`MTitle::OnInitialize` @0x000a33c0, `OnRender2D` @0x000a348c)
   - Loads image 7000 and 7001 (`Textures/textures/gof2_logos_ipad2.png`):
     - 7001 = rect [0,163,188,216] = **FISHLABS** angler-fish logo -> shown **first**
     - 7000 = rect [189,163,257,138] = **ABYSS ENGINE** logo -> shown second
     - (1024 version `gof2_logos_1440.png` has the same order of regions: [269,280,359,197] Abyss, [1,71,266,303] Fishlabs, [269,71,670,207] GoF2 logo without "FULL HD")
   - Starts music immediately: `FModSound::play(0x91)` = event 145 `Space_NoCombat_Void` -> `Audio/MUSIC/Space_NoCombat_Void.ogg`. That track continues into the main menu (it is the menu theme).
   - Each logo: 4000 ms cycle, dt clamped to 50 ms. 0-1000 ms fade in, 1000-3000 hold, 3000-4000 fade out (alpha from `t` and `t-3000`), drawn centered (anchor 'D','D').
   - Behind the logo it draws the normal UI frame: `Layout::drawBG` (tiled 0x47e), `drawHeader()` (empty), `drawEmptyFooter(false)`. Not a black screen.
   - Any tap: `timer = 5000` -> skips to the next logo. After the 2nd logo -> module 1.
   - **No Deep Silver logo, no intro movie** in this build. `MTitle::ShowLoadingScreen` returns 0.
2. **Loading screen** (`loadingScreen` @0x000e1b58, used because `ModMainMenu::ShowLoadingScreen` returns 1)
   - BG pattern + empty header + empty footer; text 393 "Loading..." (394 "Saving..." when `gameSaving`) centered above a progress bar: frame 0x504 = gof2_interface [285,561,285,38], fill 0x505 = [1,879,263,20] clipped to progress (right-to-left for Arabic).
   - `ModMainMenu::OnInitialize` @0x001a46dc is a staged loader; its return value is "remaining %": 100 -> 80 -> 60 -> 30 -> 1 -> 0 (done).
   - Loading tips (texts 340-352, `Layout::initTip`/`drawTip`) exist but `drawTip` has **no callers** (dead).
3. **Title screen** (inside ModMainMenu, flag `this+0x28`, `Globals::logoIsShown`)
   - Stage 0x50 loads 7002 = gof2_logos_ipad2 [0,0,452,156] = **"GALAXY ON FIRE 2 / FULL HD"** logo.
   - `OnRender2D` @0x001a4acc: 3D scene rendered behind; logo centered, alpha fades in over 3900 ms (0xf3c). After 3900 ms, text **199 "Tap to continue"** drawn centered at `y = h/2 + logoH/2 + 10`, white, alpha pulsing with `sin(systemTimeMs * 0.003)` (period ~2.1 s).
   - First tap anywhere (`OnTouchEnd` @0x001a4964) hides the logo -> menu becomes interactive. Menu input is ignored while the logo is up.

## 2. Main menu (class `MenuTouchWindow`, ctor @0x0014816c with param 0)

`MenuTouchWindow(int mode)`: mode 0 = main menu, 1 = in-flight pause menu, 2 = station menu. State = `this+0x16c` (also `Globals::topMenuIndex`).

### 2.1 Main entries (mode 0), vertical list, top to bottom (`addButton` @0x0014b0fc)

| # | button id | text ID | English | condition | action (OnTouchEnd @0x0015179c, jump table @0x1534d8 decoded by hand) |
|---|---|---|---|---|---|
| 0 | 0 | 28 | Start new game | always | state 0x11 (Select Campaign) |
| 1 | 0xb | 41 | Resume | only if `Globals::lastRecordWritten >= 0` and a preview record exists in that slot | `loadGame(lastRecordWritten)` directly (no confirm) |
| 2 | 1 | 29 | Load game | always | `loadPreviewRecords`, `createRecordButtons(false)`, state 1 |
| 3 | 3 | 31 | Options | always | state 3 |
| 4 | 0x19 | 0 | Language | iPad only (phones reach it via Options) | state 0xe |
| 5 | 4 | 43 | About | always | state 4 |

Extra buttons in list `this+0xc0`:
- 0x11 "Exit" (33), bottom-right, only if `layout+0x285` (Android back/exit support) -> ChoiceWindow text 53 "Are you sure you want to quit?" -> Yes = `ApplicationManager::Quit`.
- 0x35 "Add-ons" (97): DLC shop (state 0xf), hidden if IAP unsupported; draws a spinning ring (0xbc2, `rot = timeMs*0.004`) as a "new" badge until the shop was opened once (`options[0x3b]`). DLC texts 77-96. Not needed in the remake (DLC are included).
- "Leaderboards"/"Achievements" buttons are created with id 0xff (inert) in this build; Google Play ids 0x17/0x18 show "No link with Google+". Game-center-style achievements are not reachable from this menu. Medals live in the station StatusWindow.
- 0x16 "Rate this game" (62), 0x6d "Privacy Policy", 0x6e "Terms of Service": only drawn on the About page.

Layout (iPad-class values from `Layout::Layout`, @0x000e2a00, one branch): buttons are 3-slice, width `layout+0x294` = 281 px (phone retina 400 / 200), centered at `x = w/2`, `y = h/2 - layout+0x298 (118) + layout+0x2b0 (42) + i*(buttonHeight + 16)`. The whole menu is centered vertically; there is no header or footer bar on the main page (the 3D scene is visible), only the logo.
Logo on the main page (`draw` @0x0014c50c case 0): 7002 at top center: phone = half size at `y = headerHeight/4`; iPad = full size at `y = 80`. The title logo simply jumps from screen center to the top when you tap (no tween).

### 2.2 Submenus / states

| state | header text | content |
|---|---|---|
| 0x11 Select Campaign | 103 "Select Campaign" | 3 cards side by side, centered: GoF2 (9500 normal / 9501 pressed), Valkyrie (9504/9505), Supernova (9502/9503), `gof2_campaign_select.png`, 156x241 each. A "FREE" badge 0x233f (gof2_credits [1,1,61,63]) sits on the GoF2 card. Valkyrie needs `options[0x35]`, Supernova `options[0x37]`, else IAP. Pick -> state 0xc. |
| 0xc Difficulty | 517 "Select your difficulty level" | 0x10 "Normal" (519) -> difficulty 0.5; 0x32 "Extreme" (25) -> 1.5 after warning ChoiceWindow text 26 (long list of Extreme rules). If a game is running (playingTime > 0) confirm text 52 "Do you want to start a new game and quit the current one?". Then `startGOF2`/`startValkyrie`/`startSupernova` by the chosen card. Back -> 0x11. |
| 1 Load game / 2 Save game | 29 / 30 | slot list (`drawLoadSaveMenu` @0x0014bfbc): 6 slots phone / 12 iPad, slot 0 = "Auto-save" (486). Empty slot: "-BLANK-" (174). Filled: playing time (h:mm), location string (record+400), credits, "Level: n" (321), difficulty Normal/Extreme, ship icon (`ImageFactory::drawShip`). Selected slot uses box style 4, others 3; a "Load" (505) / "Save" (506) button appears on the selected row. Inertial scrolling (damping 0.9, spring-back 0.5). |
| 3 Options (phone) | 31 "Options" | 8 "Sound & Graphics" (489) -> state 7; 9 "Controls" (498) -> state 8; 0x19 "Language" (0) -> state 0xe. (iPad shows everything on one page with header 498.) |
| 7 Sound & Graphics | 489 | "Volume" (501) box: "Music" (34), "FX" (35), "Voice" (36) sliders + on/off checkbox each (checkbox 0x517 off / 0x518 on). Releasing the FX slider plays event 0x7e as a preview. "Graphics" (502): "Brightness" (503) 3-step slider "Dark/Medium/Bright" (513-515); "Quality" (504) 3-step "Low/Medium/High" (507-509), each change pops the description 510-512. |
| 8 Controls | 498 | "Touch" (490) vs "Accelerometer" (491) (two device pictures 0x515/0x516), "Steering Calibration" (492, prompt 493), "Sensitivity" (499) slider shown as "Sensitivity [x]", "Invert controls" (500) checkbox. iPad also: "Configure" (494/495), "Default settings" (497), "Apply" (496). |
| 0xe Language | 0 "Language" | 10 buttons (ids 27-39 from table @0x258580, texts from @0x2585a8): English(2), Deutsch(1), Français(4), Español(3), Italiano(5), Polski(7), Русский(8), Português (Brasil)(14), 한국어(12), 日本語(13) (last two use `fontLangSelect`). Language code table @0x2585f0. Switching to/from German re-creates FModSound (voice bank), then reloads the whole module. |
| 4 About | 43 "About" | centered scroll text: `"Galaxy on Fire 2 FHD" + " v<engine version>" + "\n\n" + text45 + text48`. Text 45 is the modder credit ("FULL HD version and modifications made by KiritoJPK...", then "© 2011 ... FISHLABS"); text 48 = staff credits. Plus the Rate/Privacy/Terms buttons. |
| 0xf Add-ons | 97 | DLC list (IAP). Skip in the remake. |

Every submenu (except 0, 0xb, 0xd, 0xf) draws `Layout::drawEmptyFooter(true)` with the **Back** button (text 170, bottom-left). Back goes: 0xc -> 0x11, 6/7/8/0xe -> 3 (phone), otherwise -> 0; leaving Options saves options (`RecordHandler::saveOptions`).

### 2.3 Dialogs (`ChoiceWindow`, message flag `this+0x170`)
- Title "Info" (390) for one-button messages; buttons "Yes" (134) / "No" (135) / "OK" (524). Every dialog opening plays event 0x7e.
- Main menu dialogs: quit (53), load while playing (51), overwrite save (49), "Game saved." (50), load errors (100, 101 needs Valkyrie, 102 needs Supernova), first-run popups: 74 (Valkyrie HD unlock), 123 (retina hint), "Update Info" 614/615 (Supernova notice when an old save exists; shown once via `options[0x48]`).

### 2.4 Text IDs used (English)
28 Start new game, 29 Load game, 30 Save game, 31 Options, 33 Exit, 34 Music, 35 FX, 36 Voice, 41 Resume, 43 About, 0 Language, 97 Add-ons, 103 Select Campaign, 170 Back, 199 Tap to continue, 25 Extreme, 519 Normal, 517 Select your difficulty level, 26 Extreme warning, 486 Auto-save, 174 -BLANK-, 321 Level, 505 Load, 506 Save, 489 Sound & Graphics, 490 Touch, 491 Accelerometer, 492 Steering Calibration, 493 calibration prompt, 494 Configure, 496 Apply, 497 Default settings, 498 Controls, 499 Sensitivity, 500 Invert controls, 501 Volume, 502 Graphics, 503 Brightness, 504 Quality, 507-509 Low/Medium/High, 510-512 quality descriptions, 513-515 Dark/Medium/Bright, 49-54 confirmations, 390 Info, 134 Yes, 135 No, 524 OK, 393 Loading..., 394 Saving..., 614/615 Update Info. (516 "Difficulty", 518 "Easy", 520 "Hard" exist in the text table but are unused: only Normal/Extreme.)
In-flight pause menu (mode 1, for reference): header 40 "Pause", Options, 129 Missions, 166 Cargo hold, 522 Back to Main Menu (confirm 523), 59 Action Freeze, 395 Skip, 60/61 screenshot share.

### 2.5 New game / continue / saves
- `startGOF2` @0x001540f0: `Status::resetGame`, store difficulty (`options+0x2c`), stop music, **play event 0x8f = `IntroAtmo` (`Audio/MUSIC/IntroAtmo_02.ogg`)**, switch to module 2 (MGame -> campaign start in space).
- `startValkyrie` @0x00153ba4: resetGame, 45x `nextCampaignMission`, ship index 5 (race 0) + fixed loadout, station 91, systems 6 and 25 visible, kills 197, credits 0, module 5 (station).
- `startSupernova` @0x00153e14: resetGame, 84x `nextCampaignMission`, ship 30 (race 3) + loadout, station 70, kills 386, module 5.
- **Resume** = `loadGame(Globals::lastRecordWritten)` @0x0014bde8: `RecordHandler::readRecord`, refuses DLC saves without the DLC, `Status::resetGame` + `GameRecord::load`, `ModStation::setGameLoaded`, `switch_to_target_setting = 0` (station music), module 5. A loaded game always resumes docked.
- Save detection: `RecordHandler::readAllPreviewRecords` (per slot `GameRecord` preview); `lastRecordWritten` is set in `RecordHandler::recordStoreWrite` and persisted with the options file (`saveOptions`/`loadOptions`). Slot 0 = autosave.
- Difficulty is only Normal (0.5) / Extreme (1.5). No separate hardcore/permadeath option.

### 2.6 Option defaults (`Globals::init`)
Music/FX/Voice volume `options+0/4/8` = 0.5; `+0x24` brightness 0.5; `+0x28` quality 1.0 (High); `+0x14/+0x18` sensitivity 1.0; `+0x1c/+0x20` 0.6 (tilt calibration); flags `0x10` (invert) = 1, `0x11` (touch mode) = 1, `0xf` = 1, `0x30` = 1. Enable flags: `0xd` music, `0xc` FX, `0xe` voice. Difficulty `+0x2c`.

## 3. Background scene

`ModMainMenu::OnInitialize` first call:
- sound preload list: always 0x7c/0x7b (from `startNewSoundResourceList`) + 0x7e, 0x15, 0x12, 0x13, 0x14 (Button_Push/Release, Message_Info_Screen, Destruction_Asteroid, Destruction_Ship_Big/Mid/Small: the NPC ships can blow up).
- `Status::resetGame`, `AERandom::reset` (seeded with `time()`), **station = `Galaxy::getStation(rnd.nextInt(100))`**, i.e. a random main-game station 0-99 (DLC/special stations are >= 100). Its system decides the skybox.
- `CutScene(2)` -> `Level(2)`: `createSpace` (star system: sun, planets, station etc.), `createAsteroids`, `createGasClouds`, `createScene` mode 2 = `createPlayer` + `createMission` with `Mission::empty` (this spawns the normal ambient traffic: freighters, patrols, sometimes pirates, which fly their AI routes because `CutScene::render3D` calls `Level::update` every frame), `createStaticObjects`, sentry guns/turrets/wingmen. The player ship exists but is `setActive(false)`.
- Skybox cubemap: `0x2efe + SolarSystem::getTextureIndex()` = `Textures/main/cubemaps/cubemap_skybox_000..009.png`; alien orbit -> 0x2f08 = `cubemap_skybox_010.png`.
- **Camera** (`CutScene::initialize` @0x000a4074, `process` @0x000a49f4, both verified in the disassembly):
  - Own camera, `CameraSetPerspective(cam, 0.92, 200, 200000)` (0.92 is probably the vertical FOV in radians, about 53°; near 200, far 200000 game units).
  - Position fixed at game `(x, 0, z)` with `x = rand(20000) - 20000` (-20000..0), `z = rand(60000) + 40000` (40000..100000). In Unity: `(x, 0, -z) * 0.05` -> x -1000..0 m, z -2000..-5000 m.
  - Rotation: `MatrixSetRotation(0, yaw, 0)`; yaw starts at **-π/4** and increases by **5e-5 rad per ms** (0.05 rad/s, about 2.9°/s, one full turn every ~126 s). The camera stands still and pans slowly around the horizon; the station/planets drift through the view. No path, no orbiting, no roll/pitch.
  - Mode 2 also has a "departing ships" animation (last two enemies placed 4000 units ahead of the camera, translated `dt*0.1`, rotated), but only when `Status::getPlayingTime() > 0`. The menu calls `setPlayingTime(0)`, so it is **off in the main menu** (it is used for the undock scene).
- Overlays: only the title logo 7002 (and "Tap to continue"). No vignette or fade. `Layout::startFade/drawFade` exist but aren't used by the menu.

## 4. Music and UI sounds

Event IDs: sequential index over the name table in `_FMOD_GOF2.fev.bytes` (the `\0`-separated block starting "_eng\0_deu\0SFX_MENU\0..." at file offset ~0xd288f), skipping group names (ALLCAPS) and parameter names. Verified by 12 anchors: the per-race station/space music tables @0x252000/@0x252010 (station 127 Vossk, 128 Terran, 129 Nivelian, 130 Midorian; space 134 Terran, 139 Vossk, 138 Nivelian, 137 Midorian), special music ids in `Globals::playMusicAndFadeOutCurrent` @0x000f9dc0 (136 Void combat, 143 intro, 145 menu, 148 Supernova, 152 Deep Science) and the UI sounds. **Confidence: high** for IDs 0-213 (SFX + music). Voice events after that aren't mapped (voice folders use ALLCAPS event names).

| use | event id | FMOD event | file |
|---|---|---|---|
| **menu music** (MTitle start, `playMusicAndFadeOutCurrent(2)` when returning to the menu) | 0x91 = 145 | `Space_NoCombat_Void` | `Audio/MUSIC/Space_NoCombat_Void.ogg` |
| new game (startGOF2) | 0x8f = 143 | `IntroAtmo` | `Audio/MUSIC/IntroAtmo_02.ogg` |
| button press (`TouchButton::OnTouchBegin`) | 0x7c = 124 | `Button_Push` | `Audio/SFX_GENERAL/Button_Push_v06.ogg` |
| button release / confirm / load / save / checkbox (`TouchButton::OnTouchEnd`, MenuTouchWindow) | 0x7b = 123 | `Button_Release` | `Audio/SFX_GENERAL/Button_Release_V06.ogg` |
| dialog opens (ChoiceWindow::set), FX-volume preview, FX toggle | 0x7e = 126 | `Message_Info_Screen` | `Audio/SFX_GENERAL/Message_Info_Screen_v04.ogg` |
| (message incoming, not in the menu) | 0x7d = 125 | `Message_Inc` | `Audio/SFX_GENERAL/Message_Inc_V01.ogg` |

There is no separate back/navigation sound: every button uses push + release. Returning from a game to the menu: `switch_to_target_setting = 2` -> `playMusicAndFadeOutCurrent(2)` -> stop + play 145 (the name says fade, the code just stops and plays). `ModMainMenu::OnResume` restores music volume; `OnSuspend` saves options.
Other music ids for reference: 131 Station_Valkyrie, 132 HomeBase_Station, 133 Deep_Science_Station, 144 OutroSong, 146 HomeBase_NoCombat, 147 Valkyrie_NoCombat.

## 5. UI look

- **Fonts**: bitmap fonts via `PaintCanvas::FontCreate` (`Globals::loadFont` @0x000f8d20). Latin/Cyrillic font = resource 1111 (glyphs in `Textures/textures/gof2_interface.png`, top-right area ~x 505-775, y 0-195, white). Alien font 1310 (same texture, magenta glyphs ~y 780). Language-select font 11642 = `gof2_font_langselect.png`; AR/CHT/CHS/KR/JA = `gof2_font_*.png`. Letter spacing -2..-5 px depending on resolution.
  - The glyph metrics are stored in the trailer of the original `.aei` files ("leftover" 2987 bytes for gof2_interface in `_texture_manifest.json`). They were not carried over to the PNGs. To rebuild the exact bitmap font, re-extract them from the OBB .aei, or measure glyph boxes from the PNG.
  - Text colour: white by default; buttons can override (`TouchButton+0xa0`); disabled buttons dim via `Layout::setDrawColor(-0xd1)`.
- **Buttons** (`TouchButton::init` @0x001961f8, style table @0x25cb84, 9 image IDs per style): main-menu style 0 is a 3-slice bar, all in `gof2_interface.png`:
  - normal: left 1116 [572,561,22,34], middle 1115 [160,772,100,34] (tiled), right 1117 [570,602,24,34] (dark blue/steel)
  - pressed: left 1122 [657,559,22,34], middle 1121 [160,811,100,34], right 1123 [259,736,24,34] (orange/amber)
  - text centered, vertical offset `h/2 + 1.5*textHeight` (1.0 for CJK).
  - Other styles: 0xd checkbox 0x517 [899,589,32,30] / 0x518 [899,620,32,30]; 0xc 0x472/0x473; 0xe 0x53c/0x53b; 0x11 0xbc0/0xbc1 (gof2_dlc_interface "+" icons); 0x10 DLC icon buttons 0xbba.. (gof2_dlc_interface); campaign cards 9500-9505.
- **Frame pieces** (`Layout::reload` @0x000e52b8): BG tile 0x47e [776,1,160,160] (dark scanline pattern, tiled full screen); header cap 0x500 [1,902,157,30] + pattern 0x4ff [285,469,480,30]; header title plate 0x474 [767,334,137,30]; footer caps 0x502 [1,772,157,37] / 0x506 [1,811,157,37] + pattern 0x507 [285,295,480,37]; 0x501 [285,334,480,37]; info icon 0x503; options gear 0x535; help 0x471. Boxes via `Layout::drawBox` (styles 0/3/4/5).
- **Animations**: title logo fade-in 3.9 s; "Tap to continue" sine pulse (0.003 rad/ms); splash fades 1 s in / 1 s out; spinning DLC badge; inertial list scrolling. No slide-in transitions or blinking selection cursor. It's a touch UI, so there's no focus highlight: a button shows the pressed (orange) sprite while held, and toggles use "always pressed".
- **Version text**: only on the About page: "Galaxy on Fire 2 FHD v<ver>" (engine string at `Engine+0x34`, only if length >= 3).

## 6. Uncertainties
- The FEV mapping is inferred (name order), not parsed, but all 12 checks match.
- `CameraSetPerspective` argument meaning (0.92 as FOV in radians) is assumed from the engine signature `(cam, float, float, float)`.
- The Layout pixel values quoted come from one resolution branch of `Layout::Layout`; others scale them.
- MTitle alpha curve: the float math is lost in the decompile (VectorSignedToFloat calls). A linear 0->1 over 1 s / 1->0 over the last 1 s is the obvious reading.
- Phone jump-table entry for options id 9 stores register `fp` into the state; assumed 8 (Controls) from the draw code (state 8 header is 498 "Controls").
