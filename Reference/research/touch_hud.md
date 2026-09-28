# Touch flight controls (the original's on-screen HUD buttons, stick and throttle)

How the Android HD build draws and handles its touchscreen flight controls: the fixed analog stick, the right-hand button cluster (fire, secondary, menu, camera), the left column (fast-forward / time extender, autopilot, boost), the pause button, the auto-turret toggle, the hidden throttle drag with its gauge, and the swipe dodge. Decoded from `libgof2hdaa.so`, Ghidra image base 0x10000. 2D values are **canvas pixels** with the HD flags `retinaDisplay = iPad = iPadLarge = 1`, `iPadHD = 0`, `n9 = 0` (`shop.md` §1.2); the examples use a 1920×1080 canvas. Images are drawn 1:1 in pixels (no scaling): a larger or wider device only moves them (the right cluster follows the right edge).

Read first: `autopilot_travel.md` §1.7, §2, §4 (the fire = action rules, the fast-forward slot), `mining.md` §3.2 (fire during the approach and the minigame), `combat_equipment.md` §3.1 (the time extender, the cloak entry and the menu-button flash), `weapons.md` §9-10 (fire input). The flight controls are **not TouchButtons**: `Hud` draws them itself with `DrawImage2D` and hit-tests them in `Hud::touchedElement`. Only the HUD menus (§10) use `TouchButton`.

Helper: `Reference/tools/shop/atlas.py` (`atlas.rect(id)` gives the atlas and rect below). Every rect was verified by cropping, and the whole default layout was rebuilt from the formulas and composited: the cluster slots line up with its background image (menu, camera and secondary sockets).

---

## 0. TL;DR for Unity

1. **Fixed layout, two vertical groups.** The left group (FF / time-extender pill, autopilot, stick, boost) hangs from one y value `S` (option `options+0x54`), the right cluster (background ring, fire, menu, camera, secondary, and the auto-turret toggle above it) from one y value `F` (option `options+0x58`). **First-run defaults on Android: S = 415, F = 365.** Both clamp to `[300, h − 425]` and `[300, h − 311]`. The player can drag both groups up and down in Options > Controls > Configure (494 / 495).
2. **Stick**: base 0x4c1 (291²) at (20, S + 132), centre **(165, S + 277)**; knob 0x4b6 (181²), 0x4b7 while held; knob travel **radius 94 px**; `analog = offset / 94` per axis, **no dead zone**, squared per axis afterwards (`left(x²)` etc.). The hit box is **±112 px × ±216 px around the centre**. It is a *fixed* stick, not a floating one. A finger stays captured by the stick until it lifts. **Double tap on the stick (≤ 500 ms) = level out** (`alignToHorizon`). There is no Level button.
3. **Fire** 0x4b4 / 0x4b5 (198²) is drawn **centred** at (w − 121, F + 200). It is held to fire, and it is also the **action button**: autopilot to a locked station or gate, planet jump, start or abort the asteroid approach, stop mining, dock at a docking point. The arrow 0x536 on it marks an available action. **Double tap (the second press ≤ 249 ms after the first) latches autofire**; the next single press releases it.
4. **Secondary** 0x4bc (109², pressed 0x4bd) sits in the cluster's small socket. It fires **on release** and is hidden when there is no secondary or its amount is 0. Its name and amount show as `"<name> (<n>)"` on the plate 0x4c2 at the **bottom centre** of the screen, not on the button.
5. **Boost** 0x4b2 / 0x4b3 (109²) at (40, S + 446) under the stick; it slides right when pushed off the bottom. It fires **on release**. Its **alpha shows the charge**: 55 while boosting, 55 + 75·rate while recharging, 255 when ready, then a 2 s blink when it is ready again.
6. **Pause** 0x4b8 / 0x4b9 (109²) at (w − 121, 24), top right. The **quick menu button** 0x4ba / 0x4bb (125×78) is the top segment of the cluster (Secondary weapons / Wingmen / Cloak / Khador Drive). The **camera button** (109×122 segment) shows the icon of the **next** camera mode. The **auto-turret toggle** 0x547 / 0x546 floats above the cluster when the ship has an auto turret.
7. **Throttle: no slider.** A vertical drag on empty screen, after 160 px of travel, sets the throttle at 400 px per 100 % (up = faster). While it changes, the gauge **0x548** (162×83, a half-ring under the crosshair filling from the bottom) and the number `thrust·100` fade in for 2 s.
8. **Hidden or dimmed**: nothing is drawn during dialogues, cutscenes (the pause button stays), the star map, the pause menu or death. Everything except the stick is invisible (alpha 0) while a HUD menu is open. Most buttons drop to alpha 47 while mining, hacking, docked at a point, or landing. The stick drops to alpha 50 in tilt mode and during the autopilot, approaches and hacking.

---

## 1. Images (atlas rects on Android HD)

`P` = `gof2_interface2_ipad_large.png` (the iPad-large re-binding, `shop.md` §1.2), `M` = `gof2_interface_iphone4.png`, `P3` = `gof2_interface3_ipad_large.png`. Rect = [x, y, w, h], top-left origin. "Hud+" is the field that holds the image (`Hud::init` 0x18cf20).

| Control | Normal (id, Hud+) | Rect | Pressed / lit (id, Hud+) | Rect |
|---|---|---|---|---|
| Stick base (dark concentric rings) | 0x4c1, +0x2bc | P [1097, 489, 291, 291] | — | |
| Stick knob (four-arrow cap) | 0x4b6, +0x2a8 | P [112, 1470, 181, 181] | 0x4b7, +0x2a4 (bright) | P [1122, 1080, 181, 181] |
| Fire button (plain round) | 0x4b4, +0x284 | P [1440, 211, 198, 198] | 0x4b5, +0x280 | P [1316, 1169, 198, 198] |
| Action arrow on fire | 0x536, +0x288 | P [112, 1890, 134, 128] | — | |
| Cluster background, secondary socket **left** (`F > h − 401`) | 0x4c6, +4 | P [1501, 489, 401, 396] | — | |
| Cluster background, secondary socket **bottom** (`F ≤ h − 401`, the default) | 0x6aa, +8 | P [1636, 1033, 397, 406] | — | |
| Autopilot (arrow into a circle) | 0x4b0, +0x2b0 | P [1, 515, 109, 109] | 0x4b1, +0x2ac | P [1097, 782, 109, 109] |
| Boost (double chevron) | 0x4b2, +0x2a0 | P [1390, 600, 109, 109] | 0x4b3, +0x29c | P [893, 1547, 109, 109] |
| Pause | 0x4b8, +0x298 | P [248, 1890, 109, 109] | 0x4b9, +0x294 | P [1, 1325, 109, 109] |
| Secondary (missile icon) | 0x4bc, +0x290 | P [1, 236, 109, 109] | **0x4bd**, +0x28c | **M [1, 887, 77, 77]** (see §12.1) |
| Quick menu (list icon, arc segment) | 0x4ba, +0x2f0 | P [239, 1214, 125, 78] | 0x4bb, +0x2ec | P [112, 1214, 125, 78] |
| Camera, next mode 0 Standard (ship) | 0x528, +0x490 | P [1, 1923, 109, 122] | 0x527, +0x4a0 | P [1904, 819, 109, 122] |
| Camera, next mode 1 Turret | 0x4e9, +0x494 | P [1, 928, 109, 122] | 0x4ea, +0x4a4 | P [1, 1624, 109, 122] |
| Camera, next mode 2 Cockpit (eye; never shown, §6.6) | 0x4be, +0x498 | P [1, 112, 109, 122] | 0x4bf, +0x4a8 | P [1390, 807, 109, 122] |
| Camera, next mode 3 Free look (ship + arrows) | 0x52a, +0x49c | P [888, 1382, 109, 122] | 0x529, +0x4ac | P [1, 1160, 109, 122] |
| Auto-turret toggle (twin guns) | 0x547, +0x2b8 (off) | P [1, 1, 109, 109] | 0x546, +0x2b4 (on / pressed) | P [1904, 708, 109, 109] |
| Fast-forward | 0x541, +0x334 (idle) | P [1120, 1295, 109, 109] | 0x540, +0x330 (held) | P [1208, 782, 109, 109] |
| Time extender (clock) | 0x543, +0x340 (idle) | P [1904, 489, 109, 109] | 0x542, +0x33c (on / flash) | P [1390, 489, 109, 109] |
| FF / TE pill behind FF + autopilot | 0x53f, +0x338 | P [1740, 112, 126, 293] | — | |
| Secondary name plate (bottom centre) | 0x4c2, +0x2f8 | M [1253, 533, 374, 37] | — | |
| Camera-mode name plate | 0x4c3, +0x2f4 | M [1601, 746, 392, 44] | — | |
| Hacking rotate left / right | 0x1f58, +0x344 (pressed) | P3 [531, 463, 109, 109] | 0x1f57, +0x348 (idle) | P3 [573, 679, 109, 109] |
| Throttle gauge (half ring, `PlayerEgo+0x238`) | 0x548 | M [1337, 1105, 162, 83] | — | |

Normal = the dim, blue version; pressed = the brighter version. The low-resolution `gof2_interface.png` rects (`atlas.rect(id, False)`) exist for every id except 0x6aa.

---

## 2. Layout (`Globals::setCoordsSteer` 0xfcd6c, `Globals::setCoordsFire` 0xfd0b8)

`Hud::init` computes phone positions from Layout values first. On iPad (always, on HD) it then calls the two `setCoords*` functions, which overwrite every touch-control position. `Hud::draw` calls them again whenever `options+0x54 / +0x58` changed (the Configure screen). The constants below are the iPadLarge ones (`DAT_000fd05c…fd5b4`).

### 2.1 Left group, from S = `options+0x54`

```
S = clamp(S, 300, h - 25 - 291 - 109)            // 291 = stick base width, 109 = autopilot width -> h - 425
autopilot   0x394 = (40, S)                        // top-left
FF / TE     0x3a0 = (40, max(0, S - 180));  pill 0x53f drawn at (40 + layout+0x190 (-8), S - 180) = (32, S - 180)
stick base  0x3c8 = (20, S + 132);  centre 0x3c0 = (20 + 145, S + 132 + 145) = (165, S + 277)
boost       0x3ac = (40, S + 446); if S + 446 > h - 109 - 4:
                over = S + 446 - (h - 113);  x = 266 + 80 * min(over / 54, 1);  y = h - 113   // slides right beside the stick
```

### 2.2 Right cluster, from F = `options+0x58`

```
W = 401 (width of 0x4c6)
F = clamp(F, 300, h - W + 90)                      // h - 311
bg  0xc  = (w - W + 80, F)  = (w - 321, F)         // 0x4c6 or 0x6aa; its right 80 px are off screen
fire 0x380 = bg + (200, 200)                       // CENTRE of the 198-px button (drawn with anchor 0x11 / pivot 0x44)
menu   0x3b2 = bg + (152, 8)                        // 125 x 78
camera 0x38e = bg + (28, 27)                        // 109 x 122
turret toggle 0x39a = bg + (160, -134)              // above the cluster
secondary 0x388: if h - W < F (cluster low):  image 0x4c6, secondary = bg + (-2, 189)      // left socket
                 else:                        image 0x6aa, secondary = bg + (144, 298)     // bottom socket
pause (Hud::init, Globals::pause_x/y) = (w - 109 - layout+0x194 (12), layout+0x198 (24)) = (w - 121, 24)
```

### 2.3 Defaults and the Configure screen

- `Globals::Globals` 0xf7580 sets S and F from the graphics quality `options+0x44`: 415 / 365 (≤ 0), 583 / 513 (medium), 830 / 730 (≥ 1). That runs at startup, when `options+0x44` is still 0 (bss). On Android the quality choice never writes it (`MenuTouchWindow::OnTouchEnd` writes `+0x44` only when `iPadLargePossible`, which this binary never sets). So the Android defaults are **S = 415, F = 365**. `RecordHandler::loadOptions` 0xde120 reads saved values (`+0x54`, `+0x58`).
- **Configure** (Options > Controls, `MenuTouchWindow` case 0xb, `OnTouchBegin` 0x150704, `OnTouchEnd` 0x15179c): text 495 ("You can change the vertical position of the control buttons by dragging them up and down. Press Apply when done."), buttons 496 Apply and 497 Default settings (the reset uses the same quality rule). A touch with x ≤ 209 and y in (S − 20, S + 300) drags the left group; one with x > w − 220 and y in (F − 20, F + 230) drags the right cluster. The screen previews the groups with the same images (0x4c1, 0x4b2, 0x4b0, 0x4b6; 0x4c6 / 0x6aa, 0x4ba, 0x4b4, 0x4be, 0x4bc).

### 2.4 Positions at 1920×1080

| Element | Default (S 415, F 365) | Lowest (S 655 clamped, F 730) |
|---|---|---|
| FF / TE icon (pill at x − 8) | (40, 235) | (40, 475) |
| Autopilot | (40, 415) | (40, 655) |
| Stick base / centre | (20, 547) / (165, 692) | (20, 787) / (165, 932) |
| Boost | (40, 861) | (346, 967) (slid right) |
| Cluster bg | 0x6aa at (1599, 365) | 0x4c6 at (1599, 730) |
| Fire centre | (1799, 565) | (1799, 930) |
| Menu | (1751, 373) | (1751, 738) |
| Camera | (1627, 392) | (1627, 757) |
| Secondary | (1743, 663) | (1597, 919) |
| Auto-turret toggle | (1759, 231) | (1759, 596) |
| Pause | (1799, 24) | (1799, 24) |
| Secondary plate / text | plate bottom-centred at (960, 1080); text centred, top at h − 32 | same |

(Correction to `autopilot_travel.md` §4.1, which put the autopilot button at (40, 300): 300 is only the lower clamp.)

---

## 3. Hit areas (`Hud::touchedElement` 0x194054, iPad branch; returns one key bit)

`Hud+0x474` = layout+0x130 = **112**, `Hud+0x478` = layout+0x134 = **216**. Rectangles are [x0, x1] × [y0, y1], inclusive, from the positions of §2. Tested in this order; the first hit wins.

| Bit | Control | Hit area | Condition |
|---|---|---|---|
| 0x1 | Pause | [px, px+112] × [py, py+112] | |
| 0x2 | Boost | [x, x+112] × [y, y+112] | ship has a booster (`Hud+0x1c2` = boostDelay > 0 at HUD init) |
| 0x40 | Autopilot | [x, x+112] × [y, y+112] | |
| 0x100 | FF / time extender | [x, x+112] × [y, y+112] | |
| 0x20 | Stick | [cx−112, cx+112] × [cy−216, cy+216] | |
| 0x80 | Camera | [x, x+112] × [y, y+112] | sets `Hud+0x40c = 1000` |
| 0x8 | Secondary | [x−56, x+112] × [y, y+112] | (reaches 56 px left of the image) |
| 0x10 | Fire | [cx−108, cx+108] × [cy−108, cy+108] | |
| 0x4 | Quick menu | [x, x+125] × [y, y+84] | quick menu not empty (`Hud+0x223 == 0`, §6.5) |
| 0x20000000 | Auto-turret toggle | [x, x+112] × [y, y+112] | |
| 0x200 / 0x400 / 0x800 | Hacking rotate L / R / (unused) | [x, x+112] × [y, y+112] | hacking game running (`Hud+0x4c0`) |

While a HUD menu is open (`Hud+0x222`), only its `TouchButton`s are tested (`TouchButton::OnTouchBegin`), and they return their own ids (0x200000…). Hit tests don't check visibility. For example, the autopilot area still reacts where the button isn't drawn; `MGame` then applies its own conditions.

### 3.1 Multi-touch bookkeeping (`Hud::touchBegin` 0x1944f0 / `touchMove` 0x1945a8 / `touchEnd` 0x194668)

- 25 pointer slots (`Hud+0x22c` pointer, `+0x230` element). `Hud+0x224` = the OR of the elements of all held pointers; the draw code uses it for the pressed images.
- **touchBegin**: finds the element under the finger and stores it in the pointer's slot, replacing that pointer's previous element. No element clears the slot.
- **touchMove**: if the pointer's slot is the stick (0x20), the knob follows the finger (§4) whatever the position: the stick keeps the finger. Otherwise it runs `touchBegin` again, so **a finger slides between buttons**: moving onto another button re-targets the slot, and moving onto empty space clears it.
- **touchEnd** clears the pointer's slot and returns its element. `MGame::OnTouchEnd` acts on that element, so releasing after sliding off a button does nothing, and releasing on another button triggers that one.
- `Hud::releaseAllKeys` 0x18deec clears everything (after mining starts, docking starts, level changes).

---

## 4. Analog stick

| | |
|---|---|
| Drawn | base 0x4c1 at its top-left 0x3c8; knob centred (anchor 0x11, pivot 0x44 'D') at 0x3ba/0x3bc |
| Knob | if touch steering (`options[0x11] = 1`) and the stick is held (`0x224 & 0x20`): 0x4b7 at the finger position; else 0x4b6 and the knob position is **reset to the centre** every frame (so it springs back on release; `Hud::resetAnalogStick` 0x193a24 does the same on level events) |
| Move (`touchMove`) | `d = finger − centre`; if `|d| > 94` (`Hud+0x47c` = layout+0x138) the knob is put at `centre + d·94/|d|`, else at the finger |
| Value (`getAnalogX/Y` 0x194002 / 0x19402a) | `(knob − centre) / 94`, x right +, y **down +**; no dead zone |
| Use (`MGame::OnUpdate` ≈ 0x1af5a0) | only if `options[0x11]` (touch; else `handleAccelerometer`) and campaign ≠ 0x30: x < 0 → `PlayerEgo::left(x²)`, x > 0 → `right(x²)`; y < 0 (finger above) → `up(y²)`, y > 0 → `down(y²)`; `options[0x10]` (invert) swaps up and down |
| Double tap (`MGame::OnTouchBegin` 0x1a8558) | a stick press ≤ 499 ms after the previous stick press → `PlayerEgo::alignToHorizon` (auto-level); `MGame+0x100` holds the last press time |
| Alpha | 50 (`SetColor(255,255,255,50)`) when tilt steering is on, or when autopilot / asteroid approach / docking-point approach / hacking / (docked at a point and not in turret mode), unless the turret view is up with touch steering; else opaque. The knob uses the same alpha. |
| Tilt mode | the stick is still drawn (dim, knob centred) and still hit-tested: its double tap still levels out; steering comes from the accelerometer |

The knob can poke out of the base: travel 94 + knob radius 90 > base radius 145. That is intended; the base has soft rings.

---

## 5. Draw order and visibility

### 5.1 Frame order (`MGame::OnRender2D` 0x1b10bc)

`Level::render2D` → **`Hud::drawPauseButton`** 0x190874 (unless `mouseCursorActivated`; drawn **first, under everything**, and also during cutscenes) → (cutscene: orbit info + radio only; dead: game-over screen) → `PlayerEgo::draw` (crosshair, **throttle gauge**, or the mining / hacking game) → `Radar::draw` (not while mining) → **`Hud::draw`** 0x190d08 (skipped while a dialogue is open) → `Radio::draw` → `Radar::drawCurrentLock` (top plate) → the mission reward message → `ChoiceWindow` → `Hud::drawMenu` (the HUD menu).

`Hud::draw` is **not called** when a dialogue is open (`MGame+0x5e`), during a LevelScript cutscene or planet jump (`+0x5f` / `+0xd8`), while the star map is open (`+0xc3`), when the pause menu is up (`+0x5d && +0xc5`: `MenuTouchWindow` instead), or when the player is dead (`+0x60`).

### 5.2 Inside `Hud::draw` (touch-relevant steps, in order)

| # | Step | Colour |
|---|---|---|
| 1 | HUD message queue, shield / hull / armor / gamma bars (top-left) | — |
| 2 | **Liberator steering** (`isInRocketControl`): only the secondary button (0x4bc / 0x4bd) and the stick, then return | stick as §4 |
| 3 | hit arcs 0x525-0x52c | white |
| 4 | **stick** base + knob | §4 |
| 5 | top-right readout (timer / cargo / passengers …) | white |
| 6 | if `mouseCursorActivated` or a HUD menu is open (`+0x222`): **alpha 0** (0xffffff00) for the following steps. It is set again before steps 13, 16 and 19 and after step 17. Exceptions: the lit autopilot overlay (step 12) is always opaque, the boost (step 18) sets its own alpha, and a not-ready time extender (step 11) is drawn at 55 | |
| 7 | **cluster background** 0x2e8 (0x4c6 / 0x6aa) at 0xc | |
| 8 | hacking rotate buttons (0x1f58 while held, else 0x1f57) at 0x3f0 / 0x3f4 | |
| 9 | if mining / hacking / docked at a point / landing or taking off: **alpha 47** (0xffffff2f) for steps 10-11 | |
| 10 | **autopilot** button (0x4b1 while held, else 0x4b0), only outside the alien orbit (except campaign 0x9a with docking targets), campaign > 1, and mission type ≠ 0xb7 | |
| 11 | **FF / TE slot** (not while a radio message shows): normal flight (or hostiles, or `aboutToReachAutoTarget`) with a time extender → pill + clock (alpha 55 while not ready, `Hud+0x220 == 0`); 0x542 while held, running (`+0x221`) or flashing (2 s after it becomes ready: one lit frame every 80 ms), else 0x543. During autopilot / approaches → pill + 0x540 while held, else 0x541 | |
| 12 | autopilot on or docking procedure (not docked, not landing): 0x4b1 over the autopilot button, opaque | white |
| 13 | **camera** button: image [next camera id], pressed while held | white / 0 |
| 14 | camera mode changed: text 217 + mode ("Standard", "Turret", "Cockpit", "Free look") for 4000 ms | |
| 15 | **auto-turret toggle** if the ship has an auto turret: 0x546 when enabled or held, else 0x547. Otherwise, while step 14's timer runs, the camera-mode plate 0x4c3 at (secondary x, menuY − 44 − 10) with the mode name centred between the secondary x and w, at y = plateY + 8; alpha is a triangle 0 → 255 → 0 over 4 s | |
| 16 | **quick menu** button if the menu isn't empty: 0x4bb while held or flashing (2000 ms after the cloak is ready again, one frame every 80 ms), else 0x4ba | |
| 17 | **secondary**, if a secondary is selected, not in turret mode, and its amount > 0 (or `Level+0x69`): 0x4bd while held, else 0x4bc; then the plate 0x4c2 bottom-centred at (w/2, h) and `"<name 1274+item> (<amount>)"` centred at y = h − 30 − 2. With a mouse cursor the plate and text are drawn opaque. | |
| 18 | **boost** (if the ship has a booster): alpha = 55 while boosting, 55 + (int)(75·rate) while recharging (rate < 1), 255 when ready. When mining / hacking / docked at a point / mouse: alpha 0 if ready, else 47. 0x4b3 while held or flashing (2000 ms after it becomes ready, one lit frame per 80 ms), else 0x4b2 | |
| 19 | **fire** (always): 0x4b5 while held or while autofire is latched (`Hud+0x441`), else 0x4b4, centred | white / 0 |
| 20 | **action arrow** 0x536 centred on the fire button (`+0x386` = layout+0x164 = 0 on HD) when not docking to an asteroid / mining / docking to the stream / docking procedure / docking to a point / turret mode, and a planet, asteroid or landmark is locked (`Radar+0x14 / +0xc / +0x24`) or a dockable object is locked (`Radar+4`, `+0x6c` and `+0x71`) | |
| 21 | transfer / cloak charge / Khador charge bars, the tutorial line 618 at campaign 2 | |

So with a HUD menu open, practically every control except the stick (and the pause button, drawn earlier) is invisible, and only the menu's buttons react.

---

## 6. Behaviour per control

Press = `MGame::OnTouchBegin` 0x1a838c, release = `MGame::OnTouchEnd` 0x1a98d8 (on the element returned by `Hud::touchEnd`).

| Control | When | What |
|---|---|---|
| Pause (0x1) | press: sound **124** (0x7c); release | `MenuTouchWindow(1)` (the pause menu, 40 Pause …) with the Skip entry when `LevelScript::canSkipCutsceneNow`, the game paused, sounds paused, sound **123** (0x7b); works during cutscenes too |
| Fire (0x10) | press / hold | action first (§6.1); else firing: primary guns every frame while held (`Hud::firePressed` = `0x224 & 0x10`), plus a one-frame pulse `MGame+0x108` so a quick tap fires once; autofire latch §6.2 |
| Secondary (0x8) | release | `PlayerEgo::shoot(dt, 1)` if `gunAvailable(1)`, not mining / turret / docked / landing; then `Hud::checkIfQuickMenuIsEmpty`. A bomb's second release detonates it (`weapons.md`) |
| Boost (0x2) | release | if `isBoostRefreshed`, not boosting, not mining, not docked at a point: throttle 100 % (`MGame+0x1ac = 100`), `PlayerEgo::boost` |
| Autopilot (0x40) | release | outside the menu: nothing at campaign ≤ 1, at 0x30, docked at a point, or while landing; autopilot on → off (`hudEvent 6` "Autopilot Off" + 29); asteroid approach → abort; docking-point approach → abort; otherwise open the **autopilot menu** (`initHudMenu(3)`, game paused; not for mission type 0xb7, and not in the alien orbit except at campaign 0x9a). With the menu open, the button closes it |
| FF / TE (0x100) | press | autopilot or approach, no hostiles (`Radar+0x54`), not about to reach → **fast-forward ×5 while held** (`MGame+0x160 = 5`); **any** touch end resets it to 1. Otherwise with a time extender (`MGame+0x16c` > 0) it toggles bullet time: on = `setTimeExtender(1,0,1,1)`, pitch down, sound **1120** (0x460); off = sound **1119** (0x45f) |
| Camera (0x80) | release | not mining: `switchCamera(mode + 1)` (§6.6) |
| Quick menu (0x4) | release | not mining: toggle `initHudMenu(0)` and pause (§10) |
| Auto-turret toggle (0x20000000) | release | `setAutoTurret(!enabled)`, HUD event 0x20 / 0x21 |
| Hacking L / R | release | `hackingRotateLCW` / `hackingRotateRCW` |
| Stick (0x20) | press / move | §4; the double tap levels out |
| Empty screen | press / move / release | camera 0 / 1: the swipe dodge and the throttle drag (§7); camera 3: free-look orbit (`freeCamTouchBegin/Move/End` 0x1a7f20 / 0x1a7ff4 / 0x1a8250) |

No HUD element plays a click sound except pause. The actions play their own (autopilot 28 / 29 through the HUD events, the boost sound, the shots).

### 6.1 Fire = action (press, in order; details in `autopilot_travel.md` §2 and `mining.md` §3.2)

1. Landmark locked (`Radar+0x24`), not in the alien orbit: autopilot to it (events 0xa / 0xc / 0xf), and the press is consumed (`Hud::touchEnd`). If the autopilot already runs: off (event 6).
2. Planet locked: planet jump (or event 0x15 "525" at campaign < 10 / 0x30, and the story requirement dialogs).
3. Not mining, not docked at a point: asteroid locked and no approach running → approach (event 0xb; event 0x1b with a full hold); approach running → abort (event 6). Then `releaseAllKeys`.
4. Mining (state ≠ 1): stop mining with the ore so far; still held, the guns fire.
5. Dockable object locked (`Radar+4`): `dockToDockingPoint` (event 0x22); docked at a point: undock.
6. Otherwise: shoot (§6.2).

### 6.2 Autofire latch (0x1a898a)

On every fire press that reaches shooting: `diff = now − MGame+0xf8` (the previous fire press).
- `diff ≤ 249 ms`: **latch** (`MGame+0x5c = 1`), fire highlight on (`Hud::enableFireForTutorial(true)` → `Hud+0x441`, which draws 0x4b5).
- else: if latched, release the key at once (`Hud::touchEnd`: this press doesn't fire), and unlatch (`+0x5c = 0`).

`OnUpdate` fires while `+0x5c || +0x108 || firePressed`. The latch also clears on a cutscene start, a planet jump and a level change. Correction to `weapons.md` §10: there is no "hold on the free screen area" fire; `+0x108` is set only by a fire-button press.

### 6.3 Secondary label

`Hud::updateSecondaryWeaponString` 0x18df24: `text(1274 + item) + " (" + amount + ")"`, x = w/2 − width/2. Selecting another secondary goes through the quick menu's "Secondary weapons" submenu (`initHudMenu(1)`, buttons 0x2000… → `setCurrentSecondaryWeapon`). There is no cycling by tapping.

### 6.4 Boost-ready and cloak-ready flashes

When `getBoostRate` reaches 1: `Hud+0x420 = 2000`, `+0x424 = 80` (the boost button flashes). When the cloak becomes usable again: `+0x434 = 2000`, `+0x438 = 80` (the menu button flashes). While the long timer runs, one lit frame is drawn each time the 80-ms timer runs out, and it restarts at 80. The secondary button has the same code (`+0x428 / +0x42c`), but nothing ever sets `+0x428`: dead code.

### 6.5 Quick menu button visibility (`Hud::checkIfQuickMenuIsEmpty` 0x18de64)

The menu counts as empty (button hidden, not hit-testable) when the ship has no secondary in any slot, no jump drive, no wingmen and no cloak. It is re-checked after every secondary shot.

### 6.6 Camera button (`MGame::switchCamera` 0x1ac34c, `nextCamId` 0x1ac488)

Modes: 0 standard, 1 turret (only with a manual turret, sort 8 or 0x23, and no auto turret; `setTurretMode`), 2 cockpit (**always skipped**, 2 → 3), 3 free look. The button shows `nextCamId(current)`: 0 → 1 (or 3 without a manual turret), 1 → 3, 3 → 0 (docked at a point: 1 or 3). `Hud::draw` gets the current mode (stack arg +0x10, for the 217 + mode name) and the next id (+0x14, for the icon). Docked to an asteroid forces mode 0.

---

## 7. Throttle drag, gauge and swipe dodge (empty-screen touches)

A press that hits no HUD element (`Hud+0x224 == 0` after `touchBegin`), in camera mode 0 or 1, not during a cutscene:
- **swipe dodge** tracking starts (`maneuverTouchBegin` 0x1a7e40 fields: `+0x174` on, `+0x178/+0x17c` start, `+0x170` clock);
- **throttle drag** starts: `MGame+0x1b0 = 1`, `+0x1b4/+0x1b8` = start position.

(A second finger that lands on the stick while only the stick is held, and isn't the first finger `MGame+0xbc`, also starts the drag. This is odd; most likely meant for the stick-zone overlap.)

**Throttle** (`OnTouchMove` 0x1a9088): while `+0x1b0` is set and the finger is on no element (or on the stick but not the first finger):
- not dragging yet: once `|y − y0| > layout+0x2f4 (160)`, the anchor moves to the current y (±1), and `+0x1c8` = the current thrust;
- then `thrust = max(0, thrust0 + (anchorY − y) / layout+0x2f8 (400.0))` and `PlayerEgo::throttleChanged`. Up = more thrust; **400 px = 0 → 100 %**. `setThrust` clamps (0..1).
- It ends on touch end in camera 0 (`+0x1b0 = 0`). The PC mouse wheel uses `MGame+0x1ac` (0..100) instead.

**Gauge** (`PlayerEgo::drawThrottle` 0xae650, called from `PlayerEgo::draw` 0xae3a0 with the crosshair): shown while `PlayerEgo+0x370`, timer `+0x374` 0 → 2000 ms (`throttleChanged` 0xae874 restarts it: 0 if hidden, 500 if in the hold phase 501-1499, `2000 − t` if fading out). Alpha = `255·min(t, 2000 − t)/500`, capped at 255 (fade in 500 ms, hold, fade out 500 ms). Image 0x548 (162×83), region `(0, 83 − f, 162, f)` with `f = 83·thrust`, drawn at `(crossX − 81, crossY + 83 − f)`: the half ring below the crosshair centre fills from the bottom. Text `(int)(thrust·100)` (no %) centred at `crossX − 1`, top at `crossY + 83/1.6`. White.

**Dodge** (`maneuverTouchMove` / `maneuverTouchEnd` 0x1a7eac): cancelled when the vertical travel exceeds `h/320·90` (304 px at 1080); on release within 600 ms (`+0x170 < 601`) with a horizontal travel > `w/480·70` (280 px at 1920): `PlayerEgo::initManeuver(1 = left / 2 = right)`. Only in camera mode 0 (`OnTouchEnd`). The throttle drag and the dodge share the finger: a mostly vertical drag throttles, a quick flick sideways dodges.

---

## 8. Hiding and dimming summary

| State | Touch controls |
|---|---|
| Dialogue open, LevelScript cutscene / planet jump / jump scenes, star map, dead | `Hud::draw` not called: no controls (pause button still drawn in cutscenes, not in the star map or the pause menu) |
| Pause menu (`MenuTouchWindow`) | the menu replaces the flight 2D |
| HUD menu open (quick menu / autopilot menu) | the controls after the stick invisible (alpha 0), except the lit autopilot overlay, the boost (own alpha; only mouse / mining / hacking / docked hide it) and a not-ready time extender (55); the stick drawn; the game paused; taps outside the menu close it |
| PC mouse cursor (`mouseCursorActivated`) | pause not drawn, the rest alpha 0 except the stick, the readout and the secondary plate |
| Mining / hacking / docked at a point / landing | autopilot, FF / TE at alpha 47; camera, turret toggle, menu, secondary, fire opaque; boost alpha 0 (ready) or 47; stick dim (hacking) |
| Autopilot / approaches | stick dim (alpha 50); autopilot button lit; FF shown when allowed |
| Tilt steering | stick dim (alpha 50), knob fixed at the centre |
| Liberator steering | only the stick and the secondary button |
| Turret view | secondary hidden; the stick aims (opaque with touch steering) |
| Campaign 0 / 1 (prologue, rescue) | autopilot button hidden |
| Radio message showing | FF / TE slot hidden |

---

## 9. Texts

217 / 218 / 219 / 220 camera mode names (plate 0x4c3); 1274 + item (the secondary name on the 0x4c2 plate); 618 "Aim at an asteroid and press Fire when locked." (campaign 2); 490 / 491 / 492 / 493 steering options; 494 / 495 / 496 / 497 Configure. No label is drawn on any button.

---

## 10. HUD menus (brief, `Hud::initHudMenu` 0x18e080, `Hud::drawMenu` 0x193cf8)

A frame of the radio-box images 0x4cf / 0x4d0 / 0x4d1 (562 wide) with style-0 `TouchButton`s (x = frame + 66, width 562 − 132 = 430, anchor 0x11). Menus 0 (quick menu), 1 (secondary weapons) and 2 (wingmen) sit at the right edge: x = w − 10 − 562, y = F − 160. Menu 3 (autopilot) is moved to x = 10 (`Hud+0x468`) at y = S. The entries and ids are in `OnTouchEnd` (0x200 weapons, 0x400 wingmen, 0x800 cloak, 0x1000 Khador, 0x2000-0x10000 secondary slots, 0x10000-0x100000 wingman commands, 0x200000 programmed station, 0x400000 jumpgate, 0x800000 station, 0x1000000 asteroid field, 0x2000000 waypoint, 0x4000000 << i docking targets). See `combat_equipment.md` §3 and `autopilot_travel.md` for their contents.

---

## 11. The remake's touch HUD compared (`Assets/UI/Flight/FlightHud.uxml` / `.uss`, `Scripts/Runtime/UI/FlightHud.cs`, `TouchStick.cs`, `NavigationView.cs`)

| Control | Original | Remake now |
|---|---|---|
| Stick | **fixed** at (20, S+132), images 0x4c1 / 0x4b6 / 0x4b7, radius 94, hit ±112×±216, no dead zone, dims (alpha 50) in tilt / autopilot / hacking | **floating** anywhere on the left half (`.stick-zone` 50 %), drawn circles (220 px base, 96 px knob, ghost ring with "STEER" at left 90 / bottom 90), radius 110, dead zone 0.08, base only while touched; `.hud-tilt` opacity 0.35 |
| Level out | **double tap on the stick** (≤ 500 ms) | a **Level button** (remake-only; tap = level, slide sideways = roll) |
| Throttle | **no slider**: vertical drag on empty screen (160 px dead travel, 400 px = 100 %), gauge 0x548 under the crosshair with the number, 2 s fade | `.throttle-track` slider 78×420 on the right, always visible, no gauge |
| Fire | image button 0x4b4 / 0x4b5 centred in the cluster, always drawn; is also the action button (+ arrow 0x536); double-tap autofire latch | drawn 210 px circle "FIRE", hidden without a primary; hold only; the action is a separate "Dock / Mine" prompt (`dockPrompt`); no latch |
| Secondary | 0x4bc / 0x4bd in the cluster socket, hidden at amount 0, fires on release; name + amount on plate 0x4c2 **bottom centre**; hit 56 px wider on the left | 120 px circle "MISSILE" with the ammo count on it, shown disabled at 0; the name label `.secondary-label` top-left under the bars; tapping it cycles (remake) |
| Boost | 0x4b2 / 0x4b3 left column under the stick, **fires on release**, alpha = charge, 2 s blink when ready | 170 px circle with a fill bar, fires **on press**, `touch-button--disabled` while not ready |
| Pause | 0x4b8 / 0x4b9 at (w−121, 24); press sound 124, opens with 123 | text button "MENU" (`.hud-menu-button`, right 40 / top 62) opens the pause menu |
| Quick menu | 0x4ba / 0x4bb, the cluster's top segment (weapons / wingmen / cloak / Khador); hidden when empty; cloak-ready flash | none (its entries are in the remake's autopilot menu) |
| Camera | segment button, icon = next mode (0x528 / 0x4e9 / 0x52a) | a small "turret" button (manual turret: camera cycle; auto: toggle), hidden without a turret, so on touch there is no way into free look without a turret |
| Auto-turret toggle | 0x547 / 0x546 above the cluster | merged into the turret button |
| Autopilot / FF / TE | pill 0x53f only when the FF / TE icon shows; FF (40, S−180), AP (40, S) = (40, 235) / (40, 415) | `.nav-buttons` at left 32 / top 250 (FF top 250, AP top 430), pill always drawn; same images |
| Cluster background | 0x6aa / 0x4c6 behind the right buttons | none |
| Layout | two groups placed by S / F (configurable, §2.3) | flex rows at the bottom right (`.touch-right` padding 0 40 70 0) |
| Sliding fingers | a finger re-targets as it slides; release acts on the button under it | pointer capture per button: release anywhere triggers the pressed button |
| Menu open / mining | controls vanish (alpha 0) under a HUD menu; alpha 47 while mining | `.hud-docking` hides all but fire (and the stick while mining) |
| Hacking rotate | 0x1f58 / 0x1f57 at (w/2 − 54 ∓ 472, h/2 − 288) | `HackingView` (own layout) |

Suggested cuts for `HudImageBuilder` (not present yet): stick_base 0x4c1, stick_knob 0x4b6 / _on 0x4b7, fire 0x4b4 / _on 0x4b5, action_arrow 0x536, cluster_left 0x4c6, cluster_bottom 0x6aa, boost 0x4b2 / _on 0x4b3, pause 0x4b8 / _on 0x4b9, menu 0x4ba / _on 0x4bb, secondary 0x4bc / _on 0x4bd, cam_0/1/2/3 (+ _on), turret_auto 0x547 / _on 0x546, secondary_plate 0x4c2, mode_plate 0x4c3, throttle_gauge 0x548. (autopilot, fastforward, button_pill and time_extender exist already.) The remake's panel is 1920×1080 on desktop and tablets, so these pixel positions map 1:1 there. On phones (1600×900) the original would place the same pixel sizes relative to the real resolution.

---

## 12. Uncertainties

1. **0x4bd** (secondary pressed) is registered only in `gof2_interface.png` (region 112, `img_records.py` 0x12ccde), so on HD it comes from `gof2_interface_iphone4.png` at **77×77**. The original then draws a smaller lit icon at the 109-px button's top-left. This looks like an original asset gap; the remake could scale it to 109 or tint 0x4bc.
2. The mouse / mining alpha of the boost button is inverted-looking (ready → alpha 0, recharging → 47; `ite pl` at 0x192e7e). It is taken literally from the disassembly.
3. The throttle drag started by a non-first finger on the stick (§7) is literal but its intent is unclear.
4. `Level+0x69` (the other condition that shows the secondary button) wasn't identified.
5. layout+0x20c / +0x210 (10 / 8, camera-mode plate margins) and +0x214 (−2, secondary text) were read from the vectorised part of `Layout::Layout` 0xe2a00 (retina select); not verified in the disassembly.
6. Canvas size: the (modded) APK sets the GL surface to the display size × a mod-menu `screenscale` (`GOF2HD2012.onCreate`, `com_setting_modmenu/setting`), with touches scaled to match. On a stock device, canvas = display pixels.

---

## 13. Functions

| Function | Address | Role |
|---|---|---|
| `Hud::Hud` / `Hud::init` | 0x18ce3e / 0x18cf20 | images, phone layout, iPad `setCoords*`, pause position, radar size |
| `Globals::setCoordsSteer` | 0xfcd6c | left group layout (§2.1) |
| `Globals::setCoordsFire` | 0xfd0b8 | right cluster layout (§2.2) |
| `Globals::Globals` | 0xf7580 | default S / F |
| `Layout::Layout` | 0xe2a00 | layout+0x12c…0x1d8, +0x2f4 / +0x2f8 |
| `Hud::draw` | 0x190d08 | everything in §5.2 |
| `Hud::drawPauseButton` | 0x190874 | pause |
| `Hud::touchedElement` | 0x194054 | hit tests (§3) |
| `Hud::touchBegin` / `touchMove` / `touchEnd` | 0x1944f0 / 0x1945a8 / 0x194668 | pointer slots, stick knob |
| `Hud::getAnalogX` / `getAnalogY` / `resetAnalogStick` | 0x194002 / 0x19402a / 0x193a24 | stick value |
| `Hud::firePressed` / `enableFireForTutorial` | 0x1907be / 0x193ffc | fire held / fire highlight |
| `Hud::releaseAllKeys` / `checkIfQuickMenuIsEmpty` / `setTimeExtender` | 0x18deec / 0x18de64 / 0x18f278 | |
| `Hud::initHudMenu` / `drawMenu` / `closeHudMenu` | 0x18e080 / 0x193cf8 / 0x18de36 | HUD menus |
| `MGame::OnTouchBegin` / `OnTouchMove` / `OnTouchEnd` | 0x1a838c / 0x1a9088 / 0x1a98d8 | actions (§6, §7) |
| `MGame::maneuverTouchBegin` / `Move` / `End` | 0x1a7e40 / 0x1a7e54 / 0x1a7eac | swipe dodge |
| `MGame::freeCamTouchBegin` / `Move` / `End` | 0x1a7f20 / 0x1a7ff4 / 0x1a8250 | free-look orbit |
| `MGame::switchCamera` / `nextCamId` | 0x1ac34c / 0x1ac488 | camera button |
| `MGame::OnUpdate` | 0x1ac778 | analog → steering, fire, fast-forward dt |
| `MGame::OnRender2D` | 0x1b10bc | draw order, hiding |
| `PlayerEgo::draw` / `drawThrottle` / `throttleChanged` | 0xae3a0 / 0xae650 / 0xae874 | crosshair, throttle gauge |
| `MenuTouchWindow::OnTouchBegin` / `OnTouchEnd` (case 0xb) | 0x150704 / 0x15179c | Configure screen, steering options |
| `RecordHandler::loadOptions` | 0xde120 | saved S / F |
