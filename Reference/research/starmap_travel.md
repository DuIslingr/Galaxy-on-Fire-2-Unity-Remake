# Star map (galaxy / system map), jump rules, jumpgate and Khador-drive travel

How the original shows the galaxy map, which systems and stations can be picked, what picking one does, and how the jumpgate and the Khador Drive move the player to another system. Decoded from `libgof2hdaa.so` (Android HD). Game units and milliseconds unless noted (Unity: 1 unit = 0.05 m). Addresses use the Ghidra image base 0x10000. 2D values are **HD screen pixels** (`retinaDisplay = iPadLarge = 1`, `iPadHD = 0`; see `shop.md` §1.2), i.e. a 1920×1080 canvas.

Not repeated here (read them first):
- `space_level_setup.md`: §3.2 gate placement, §4 arrival positions (landmark 2 / 4× planet billboard / (0, 0, 100000)), §8 dock/stream triggers.
- `autopilot_travel.md`: locks, autopilot, `setAutoPilotToProgrammedStation` routing, menu entry "574 Destination: X", planet jump, fast-forward, `drawOrbitInformation` texts.
- `station_interior.md`: §3.2 station menu (Map button), §3.4 launch sequence and 7 s arrival fly-in camera.
- `assemblies_scenes_notes.md` ("Galaxy map" block): mesh placement rules, re-verified here.

Helper: `Reference/tools/starmap/starmap_tables.py`:
- no arguments: image rects, every system's map position, routes, and energy-cell tables;
- `crops DIR`: cuts the 2D images (all rects below were checked visually this way);
- `path A B`: gate path from system A to B;
- `sysmap S`: system-map planet layout of system S (java.util.Random, exact).

---

## 0. TL;DR for Unity

1. **One class, `StarMap`, used everywhere.** It is opened by:
   - the station's **Map** button (station mode);
   - the **jumpgate** when no destination is programmed (gate mode);
   - the in-flight **Khador Drive** menu entry (jump mode);
   - read-only **mission maps** (MissionsWindow, Space Lounge, Wanted list).
   
   It is a fullscreen **3D scene with its own camera**; the level is not drawn behind it and the game is paused.
2. **Two zoom levels.**
   - **Galaxy view**: one additive sun sprite per *visible* system in a 3D box, perspective camera looking +Z, panned in x/y by dragging.
   - **System view**: a small solar system (lit 3D planets on orbit rings around a sun sprite) placed at that system's sun. You rotate it by dragging.
   
   Tap a system once to select it; the camera then glides until it is centred. Tap it again to zoom in: a 2.18 s sine ease plus `Map_Zoom_In`. The footer back button zooms out (`Map_Zoom_Out`), or closes the map from the galaxy view.
3. **Which systems.** The galaxy view shows the systems in `Status::getSystemVisibilities()`:
   - starts from `initiallyVisible`;
   - buying system info in the lounge sets one;
   - campaign steps set 27, 28 and 29;
   - DLC starts set 6 and 25.
   
   Routes (`jumpRoutesTo`) are drawn as faint lines between visible systems. Animated white "pulse" lines run from the current system to its gate neighbours.
4. **What can be entered.** Without a Khador Drive you can only zoom into the current system or a system directly linked to it by a gate route (`SolarSystem::systemIsInSystemRoutes`). Anything else shows 420 "You cannot reach this location from the current system's jumpgate." With a Khador Drive, any visible system can be entered.
5. **Picking a station** (system view) takes two taps:
   - Tap 1 selects the planet (`Map_Select_Planet_Push`). On release, `Map_Select_Planet_Release` plays and the system turns so the planet comes to the front.
   - Tap 2 opens a ChoiceWindow: **"Destination: <station>\nTravel to this station?"** (574 + 421). The current station instead gives 419 "This is where you are right now."
   
   **Yes** then does:
   - **station mode**: leave the station at once (`StarMap::depart` → `Status::departStation(current)`, module 2). `Level::programmedStation` = target. The normal launch sequence runs, then the autopilot flies to it (`setAutoPilotToProgrammedStation`: own-system planet → planet jump; another system → gate station's planet → gate). With a Khador Drive and the target in another system, the drive charges 5 s after launch instead.
   - **gate mode**: `programmedStation` = target and the map closes. If the ship is inside the gate sphere, the **gate jump scene starts immediately**.
   - **Khador mode**: `programmedStation` = target, `doInstantJump` = (other system). The map closes and the drive starts charging next frame.
6. **Jumpgate.** Autopilot to the gate (landmark 1). Inside its sphere (`Level::collideStream`) `PlayerEgo::dockToStream(true)` runs, then:
   - **programmed station**: ChoiceWindow 574 + 421, default Yes. Yes → gate jump scene; No → StarMap in gate mode.
   - **no programmed station**: StarMap in gate mode.
7. **Gate jump scene** (`MGame::startJumpScene` / `updateJumpScene`), about 6.3 s:
   - The HUD is hidden and the ship is invulnerable, collision off.
   - The ship is teleported to **gate − (0, 0, 10000)** facing +Z and flies on at 2 u/ms.
   - A fixed look-at camera starts at **gate + (−2000, 300, −6000)** and drifts by (5, 2, −3)·dt (ship space).
   - When the camera passes **gateZ − 10000** (~1.33 s), the gate's idle `_anim_add` is swapped for its one-shot **`_jump_anim_add` (5000 ms)** and **sound 31 `Jumpgate`** plays.
   - 1000 ms into that animation the ship is hidden (speed 90).
   - When the animation ends: `departStation(target)`, stream-out arrival, `jumpgateUsed`, `programmedStation = null`, reload **directly in the target station's orbit**. No autopilot leg follows.
8. **Energy cells** (Khador Drive, item 85; cells = commodity 122):
   - cost = number of gate jumps on the shortest route through visible systems (BFS);
   - 4 if the target can't be reached by gates;
   - ×2 in hardcore mode;
   - removed when charging starts; charge time = item attr 37 = **5000 ms**, sound 33 `Jumpgate_Charge`.
   
   Then the `khador_jump` fx (15026) plays. The ship vanishes 1700 ms in, and the jump happens when the fx animation ends (~4 s). The integrated drive of ships 37 Cronus, 38 Typhon and 40 Nemesis counts as a fitted drive.

---

## 1. Instances, modes and flags

`StarMap::StarMap(bool missionMode, Mission*, bool reveal, int revealSystem)` 0xd6880 builds the galaxy geometry, then calls `init(...)` 0xd6d20. `init` is re-run when an existing map is reopened.

| Field | Meaning |
|---|---|
| `+4` | view: **0 = galaxy**, **3 = system** ("planet mode", `isInPlanetMode`) |
| `+0xf4` | galaxy view allowed = **campaign mission > 15**. Otherwise the map opens directly in the system view of the current system, and back closes it. |
| `+0xa8` | **missionMode**: read-only map centred on a mission target. No zoom-in; a yellow route to the target is drawn. |
| `+0xa9` | ChoiceWindow open |
| `+0xaa` / `+0xab` | `setJumpMapMode(gate, jumpDrive)` 0xd8418: **gate mode** / **jump-drive mode** |
| `+0x118` / `+0x114` / `+0x11c` | reveal mode: system `+0x114` is hidden, then grows in over 4000 ms (§4.4) |
| `+0x60` | selected system (−1 none); `+0x19c` = selected **and centred** (a second tap zooms in) |
| `+0x64` | selected station (index in the system's station list); `+0x1a0` = selected **and rotated to the front** (a second tap confirms) |
| `+0x13a` / `+0x13b` | auto-centre on the selected system (galaxy) / auto-rotate to the selected planet (system) |
| `+0x138` / `+0x139` | zooming in / zooming out |
| `+0x1d0` | energy cells needed for the selected system; `+0x1d8` = cells in cargo (item 0x7a); `+0x1d4` = "the target has no gate" |
| `+0x108` | key (legend) box visible |
| `+0x1e4` | the ChoiceWindow is an info box (campaign requirement): OK only closes it |
| byte `+0` | **"destination chosen"**, set when a gate / Khador selection closes the map |

Owners and the mode they use:

| Opened from | Code | Mode |
|---|---|---|
| Station menu **Map** (button 2) | `ModStation::OnKeyPress` 0xec6f8 case 2 | station mode. `setJumpMapMode(false, true)` if item 85 is fitted or the drive is integrated. |
| Jumpgate, no programmed station | `MGame::dockEvent` 0x1afebc | `setJumpMapMode(true, false)`, autopilot off, `MGame+0xc3 = 1` (map open), `+0x5d = 1` (paused), sounds paused |
| Jumpgate ChoiceWindow answered **No** | `MGame::OnTouchEnd` ~0x1aa7xx (`+0xc1` branch) | same as above |
| HUD menu entry 1359 "Khador Drive" (key 0x1000) | `MGame::UseKhadorDrive` 0x1a9480 | `setJumpMapMode(true, true)`, plus `askForJumpIntoAlienWorld` (§9.1) |
| Missions window, Space Lounge (agent missions / bought system info), Wanted window | `StarMap(true, mission, ...)` / `StarMap(false, 0, true, sys)`; `setStart(a, b)` for a wanted person's route | mission / reveal mode |

While the map is open in flight, `MGame::OnRender3D` renders only `StarMap::render` and `OnRender2D` only `StarMap::draw`; `OnUpdate` calls `StarMap::update` and still counts playing time. In the station, `ModStation+0x63` switches the render and update to the map. When the map closes, the space level's `StarSystem::initLight` (or `ModStation::resetLight`) restores the lights. `StarMap::initLights` 0xd8130 sets material ambient and disables fog when the map opens.

---

## 2. 3D scene

### 2.1 Camera (`init`, disassembly 0xd6ec4..0xd6fa2)

- Its own camera (`+0x70`); the previous one is saved in `+0x74` and restored when the map closes.
- `CameraSetPerspective(fov = 1.1504 rad (65.9°, 0x3f93404f), near = 200, far = 64000)`.
- Rotation (0, π, 0), so it **looks along game +Z**, and screen-right is game −X.
- **Galaxy view**: position = `((+8 + pan.x)·20, (+0xc + pan.y)·20, 0)`.
  - `+8 / +0xc` = the start target / 20. The start target is the current system's sun, or in mission mode the target station's system (or `Status+0x7c` if there is none).
  - `pan = (+0x13c, +0x140)` (ints, in 1/20 units).
- **System view**: position = the selected system's sun − (0, 0, 500), i.e. 500 units in front of it; x/y unchanged.
- The zoom animates the camera position between those two points (§5.3).

### 2.2 Galaxy view geometry (`StarMap::StarMap`, verified in the disassembly 0xd6a0a..0xd6b6a)

- **Background** (`init`, rendered first every frame):
  - `map_bg_plane` 16850 (unlit `galaxymap_bg.png`);
  - `map_fog_layer_0` 16851 and `map_fog_layer_1` 16852 (additive fog layers);
  - all at (−3000, −2500, 0), rotation (0, π, 0). Assembled: `Resources/Assembled/main/galaxymap/galaxymap_background`.
- **One sun sprite per system** (all 34 are created; only visible ones get labels, and invisible ones are still rendered, see Uncertainty 3):
  - mesh `18070 + system.textureIndex` = `plane.fbx` with `Textures/main/suns/sun_0XX.png`, material shading *additive*. System 27 after campaign mission 0x9d uses 18075.
  - scale **0.012**; texture index 15 before mission 0x9e: 0.018 (mission ≤ 0x69) or 0.025.
  - position (integer-truncated), `X, Y, Z = system.mapPosition`:
    - `x = int((100 − X)/100·14000) − 10000`
    - `y = int((100 − Y)/100·13000) − 9000`
    - `z = int((100 − Z)/100·6000) + 1000`
  - Seen through the camera, screen x grows with X, screen y grows **downward** with Y (like image coordinates), and **larger Z = closer = bigger**. The helper prints all 34 positions (e.g. Mido (−60, 2700, 1600), Augmenta (−2160, −1980, 4000)). Assembled: `galaxymap_sun`.
- **Wormhole** (campaign mission > 0x1f and `Status+0x7c ≥ 0`, the wormhole system):
  - `wormhole_anim_add` 16994, looping animation (state 2), at that system's sun, rotation (0, π, 0);
  - every frame it is turned to face the camera;
  - scale `0.02 − 0.014·t` (t = zoom progress);
  - in the system view it moves to the planet of station `Status+0x80`.
  - Assembled: `galaxymap_wormhole`.
- The galaxy suns are drawn every frame, also in the system view; `setVisible(false)` on the selected sun has no effect (see Uncertainty 4). Then `End3d`/`Begin3d` runs, and the system container is drawn on top.

### 2.3 System view geometry (`StarMap::initStarSystem` 0xd7810, verified in the disassembly)

`FileRead::loadStationsBinary(system)` gives the station list, in `systems.json` `stations` order. RNG: `setSeed(systemIndex · 1000)` (java.util.Random), so the layout is **the same on every visit**; `starmap_tables.py sysmap S` reproduces it. After building, the RNG is reseeded with the playing time.

- **Container** `+0xa4`:
  - an empty `AEGeometry` at the system's galaxy sun position;
  - scale **1/128**;
  - rotation (x, y, z) = (**−π/8, π/8, −π/32**), stored as `+0x18c` = −4096 (pitch) and `+0x188` = +4096 (yaw), in 1/65536 turns.
- **Planets** (one per station k = 0..n−1, geometry index k+1):
  - **Slot**: `slot = nextInt(n+1)` until the slot is free; angle = `slot · (65536 / (n+1))` (integer), stored in `+0x98[k]`. The planet's position is `rotY(angle) · (0, 0, radius)`.
  - **Radius**: `r_0 = 6400 + nextInt(5600) + 1600`, then `r_k = r_{k−1} + nextInt(5600) + 1600`. The RNG order per planet is slot draws, then the radius draw.
  - **Mesh**: `18180 + station.textureIndex` (`map_planet_0XX`, lit, `galaxymap_planets_diffuse.png`; 20–22 Valkyrie, 24–26 Supernova).
  - **Scale**: `DAT_00254484[tex] · 16 / 65536` (320 → 0.078, 256 → 0.0625, 192 → 0.047).
  - **Ring** `map_planet_ring` 16853, on the same matrix: texture index 9, 16 or 21, or stations 120, 126, 130, 132 (`Status::orbitHasPlanetRing`).
  - Each planet spins about its own axis: `rotate(dt·0.0002, 0, 0)` every frame (the rotate argument is taken to be yaw).
- **Orbits**:
  - one `map_orbit` 6779 (additive `galaxymap_orbit.png`) per station, drawn after all planets;
  - rotation (0, `nextInt(3141)/1000`, 0);
  - uniform scale `2·r_k/65536`.
- **Sun**:
  - `plane` 6768, at the system's sun position, rotation 0;
  - scale **0.004** (texture index 15: 0.007 if mission ≤ 0x69, else 0.01);
  - texture `DAT_00254420[system tex]` = the flight-level sun texture (10031 + tex-table, index 15 = `sn_supernova`; system 27: 0x2734);
  - blend mode 2.
- **Lights**:
  - one light (`Engine+0x31c = 1`), direction (0, −1, −1), **positioned at the sun**;
  - ambient 0.2, diffuse 2.0;
  - material ambient 1, diffuse 1, specular 0, shininess 10.
- **Race logo** `DAT_002544f4[race]` for the header: 0 → 1190 (0x4a6), 1 → 1187, 2 → 1189, 3 → 1188.

Example, Mido (15), in station order 75..79:

| Station | Slot | Radius |
|---|---|---|
| 75 Deuter IV | 1 | 8715 |
| 76 Yrdal Gedal | 0 | 15832 |
| 77 Heinsten | 3 | 22820 |
| 78 Var Hastra | 2 | 26235 |
| 79 Kernstal | 4 | 31495 |

At 1/128 the outer orbit is ~250 units from the sun; the camera is 500 in front, so the whole system fills the screen.

Screen positions are recomputed every frame (`update`) with `PaintCanvas::GetScreenPosition` for:
- all galaxy suns (`+0x194[i]`, z = +1 on screen / −1 behind);
- in the system view, the planets (`+0x198[k]`, from container × planet matrix).

---

## 3. What is known / visible

| Data | Source | Used for |
|---|---|---|
| **System visible** | `Status+0x38` bool[34] (`getSystemVisibilities` 0xb6128, `setSystemVisibility` 0xb612c) | whether the system and its route lines are drawn and tappable; also the **path finder only walks into visible systems** |
| Initial value | `Status::resetGame`: copies `SolarSystem::isVisible` (= `systems.json initiallyVisible`) | – |
| Set later | Space Lounge agent offer type 4 "sell system" (`SpaceLounge::onKeyPress` case 4, then the map reveal animation) | – |
| | `Status::nextCampaignMission`: case 0x58 → systems 27 and 28; case 0x61 → 29 | – |
| | DLC starts (`MenuTouchWindow::startValkyrie` / `startSupernova`): 6 and 25 | – |
| | `options[0x35]` / IAP: 25 | – |
| **Station visited** | `Galaxy::getVisited()[stationIndex]` (`Station::isDiscovered` 0xb3a50) | "Already visited" tick on a planet |
| **System fully visited** | `SolarSystem::isFullyDiscovered` 0x180c30: all its stations visited | tick on a system |
| **No owner** | `SolarSystem::hasNoOwner`: systems 23 Herjaza, 24 Skavac, 26 Shima, 32 Skor Terpa, 33 Alda | no race icon, race line or header logo |

---

## 4. 2D overlay (`StarMap::draw` 0xd970c, `drawOnScreenInfo` 0xd8710, `drawKey` 0xd84b0)

Colours are RGBA. `fade` = `+0x1a4`: 255 in the galaxy view, 0 in the system view; during the zoom it follows the ease (`255·(1−t)` zooming in, `255·t` zooming out). The galaxy overlay therefore fades out while zooming in, and the system overlay uses `255 − fade`.

### 4.1 Galaxy view lines

1. **Route network**:
   - for every visible system with routes, a line to every visible route target;
   - drawn in both directions and only if one end is in front of the camera;
   - colour (255, 255, 255, **min(fade, 34)**): faint.
2. **Reachable pulse** (only when *not* in jump-drive mode):
   - for every route of the current system, a line from the current system toward the neighbour;
   - endpoint = `target + t·(current − target)`, `t = (101 − (playingTime/10) mod 99)/100`, repeating every 0.99 s;
   - alpha `min(255·t, fade)`.
   - So a bright short dash leaves the current system and fades as it reaches the neighbour. Help 628 calls it "An animated line indicates systems that can be reached from your local jumpgate".
3. **Mission route** (mission mode, galaxy view, path `+0xa0` from `SystemPathFinder::getSystemPath`):
   - drawn segment by segment, animated with the same `t`;
   - segment index `+0xe8` advances whenever `t` wraps;
   - finished segments are opaque yellow `0xFFFF00FF`;
   - the segment being drawn is yellow with alpha `255·t`.
   - Help 634: "the yellow line will show you the route".

### 4.2 System / planet labels (`drawOnScreenInfo(i, isPlanet)`)

- **Culling**: skipped if the screen position is outside [−50, w+50] × [−50, h+50].
- **Text anchor**: `ty = sy + 143/2 − 3` (143 = width of 0x48c). The name is centred on `sx`, top-left anchored at `ty`, default font. Line height = layout+4 = **30**.
- **Pulse** (the current system / current station): image **0x4fd** centred on (sx, sy), white, alpha = `Layout::getPulseValue(0.005)` × fade.

**Galaxy** (per visible system):

| State | Name | Next lines | Ring |
|---|---|---|---|
| selected | orange (255, 128, 0, fade) | race name (406 + race, if owned) at `ty + 30`; security `402 + sec` in the security colour at the next line (`ty + 30` or `ty + 60`) | **0x48c** (143×143) centred |
| another system selected | white, alpha **min(fade, 64)** (dimmed) | – | **0x48a** (99×99), alpha 64 |
| nothing selected | white, alpha fade | – | 0x48a, alpha fade |

- Race icon (36×36, 0x4a1 Terran / 0x49c Vossk / 0x49f Nivelian / 0x49e Midorian; unowned: none) at `(nameLeft, ty − 3)`, anchor 0x12 (right-top): **left of the name**.
- Shima (26) with `Status+0x114 == 3`: extra icon **0x545** at `(nameLeft, ty + 3)`, anchor 0x12. Shima's security shows as 3 "Secure" when `Status+0x114 > 1`.

Security colours (`DAT_0025451c` = `DAT_00259ea0` of the HUD), from security level (`systems.json securityLevel`) to text:

| Level | Text | Colour |
|---|---|---|
| 0 | 402 Dangerous | (255, 42, 0) |
| 1 | 403 Risky | (255, 108, 0) |
| 2 | 404 Average | (237, 237, 0) |
| 3 | 405 Secure | (0, 237, 0) |

**System view** (per planet; the selected one is drawn last):

| State | Name | Line 2 | Ring |
|---|---|---|---|
| selected | orange (255, 128, 0, 255 − fade) | "133 Tech level: N" (white, only if N > 0) | 0x48c |
| another planet selected | white, alpha min(255 − fade, 64) | – | 0x48a, alpha 64 |
| nothing selected | white | – | 0x48a |

**Icon slots** (`+0xfc`, 5 entries, −1 = none). Anchor: `x0 = sx + 143/2 − 7`, `y0 = sy − 143/2 + 10`.

| Slot | Image | Condition (galaxy: any station of the system; system view: this station) | Position |
|---|---|---|---|
| 0 | **0x4a2** green tick "Already visited" | fully visited system / visited station | `(x0 − 18, y0 − 35 + 143)`, lower-right of the ring |
| 1 | **0x454** gold ship "Story" | campaign mission target (plus special cases 0x34 / 0x74 / 0x78 / 0x7d, type 0xa3 lists `Status+0x90`, and `Status+0x80` after mission 0x20) | slots 1–4 stack from `(x0, y0)` downward in 26 px steps |
| 2 | **0x455** white ship "Freelance" | freelance mission target (type 0xe: the agent's station, galaxy only while item 0x73 is in cargo) | as above |
| 3 | **0x453** gate icon "Jumpgate" | system view only: the system's jumpgate station | as above |
| 4 | **0x452** "Products finished" | a pending product (`Status::getPendingProducts`) waits at that station | as above |

### 4.3 Header, footer and buttons

- `Layout::drawHeader(177 "Map")` and `Layout::drawEmptyFooter(true)`: the standard footer with the **back button**. Footer back is `Layout::OnTouchEnd == 1` (§5.4).
- **System-view header block** (when the system has an owner):
  - big race logo at **(6, 64)** (layout+0x2c = 6, layout+0xc = 58);
  - text x = logoWidth + 12;
  - system name orange (255, 128, 0, 255 − fade) at y = 66;
  - race name (406 + race) white at y = 96;
  - security text in its colour at y = 126.
- **Key button**: `TouchButton(400 "Key")` at (w − 6, h − 6), anchor 0x22 (bottom-right). It toggles `+0x108`. When on, `drawKey` shows:
  - a `Layout::drawBox` style 7;
  - width = widest of texts {400, 401, 547, 556, 555, 274} + 64 (layout+0x8c);
  - height = 30·5 + 6·2 = 162;
  - right-aligned, bottom = h − footer (74) − 60;
  - rows bottom-up: 0x452 "274 Products finished", 0x4a2 "401 Already visited", 0x453 "547 Jumpgate", 0x455 "556 Freelance", 0x454 "555 Story";
  - icons at x + 6, text right of the icon.
- **Energy line** (jump-drive mode or a fitted / integrated drive; a system other than the current one selected; cells needed > 0):
  - "578 Energy cells needed: **N** / **M**" (N = needed `+0x1d0`, M = in cargo `+0x1d8`);
  - centred on the window centre x, at y = window bottom − 50 (layout+0x14);
  - drawn in another colour when M < N (the value was lost in the decompile; probably red).
- **Help** (Layout help button): 628 (galaxy) / 631 (system); PC/pad variants 629/630 and 632/633. The first opening from the station also shows 628 once (`hints[0xe]`, campaign mission > 15).
- The ChoiceWindow (`+0x5c`) is drawn last when `+0xa9` is set.

### 4.4 Reveal animation (`StarMap(false, 0, true, sys)`, from the lounge "sell system" offer)

System `sys` stays hidden (no lines, no label) for 4000 ms while its sun scales `t/4000 · 0.002`. At 4000 ms `OnTouchBegin(w/2, h/2)` is simulated, which selects the system at the screen centre (the camera was centred on it).

---

## 5. Input (`OnTouchBegin` 0xdaf80, `OnTouchMove` 0xdb300, `OnTouchEnd` 0xdb69c, `update` 0xda2e0)

No input goes through while a ChoiceWindow is open, while zooming, during the reveal, or while auto-rotating. Taps are ignored above the header (y ≤ 58) and below the footer (y ≥ h − 74).

### 5.1 Galaxy view

- **Touch begin**:
  - plays `Map_Whoosh` (102; restarted on every touch);
  - `+0x60 = −1`, then the **first visible system in front of the camera whose screen position is within ±60 px** (layout+0x88) becomes selected;
  - it loads its station list, plays **103 `Select_System`** if it changed, and computes the energy cells (§7.2).
- **Move**:
  - `pan += Δpx · 0.325` (layout+0x90), so the camera moves 6.5 units per pixel and the content follows the finger;
  - velocity (`+0x16c/+0x170`) = the last Δ·0.325;
  - moving more than 3 px from the touch-down point in x or y **deselects** (`+0x60 = +0x19c = −1`, cells 0).
- **Release**:
  - inertia: velocity kept only if |v| > 3, then ×0.9 per frame (frame-based) and applied while |v| > 0.5;
  - if a system is selected: when it is already the centred selection (`+0x19c == +0x60`), not mission mode and not reveal → try to zoom in (§5.3). Otherwise start **auto-centre** (`+0x13a = 1`, `+0x19c = −1`).
- **Auto-centre** (`update`): per frame `v = −(screenPos − screenCentre)/30`, halved if it would overshoot; stops when |v| ≤ 2 px on both axes, then `+0x19c = +0x60`. So: tap once, the camera glides the system to the centre, tap again to enter it.
- **Pan limits**: `+8 + pan.x ∈ [−500, 120]` and `+0xc + pan.y ∈ [−400, 140]` (camera x ∈ [−10000, 2400], y ∈ [−8000, 2800]). Outside, the velocity becomes `0.1 · (limit − value)` (a spring).

### 5.2 System view

- **Touch begin**: the first planet within ±60 px of its screen position → `+0x64 = k`, sound **104 `Map_Select_Planet_Push`**.
- **Move**:
  - yaw `+0x188 += Δx · 0.325 · 50`, wrapped mod 65536;
  - pitch `+0x18c += −Δy · 0.325 · 50`, clamped to **±8192 (±45°)**;
  - so 1 px ≈ 16 / 65536 turn ≈ 0.09°;
  - container rotation = (pitch, yaw, −π/32);
  - moving more than 3 px deselects.
- **Release**:
  - inertia only if |v| > 150 (per event), ×0.9 per frame;
  - if `+0x64 == +0x1a0` (already selected and in front) → confirm (§6);
  - else sound **105 `Map_Select_Planet_Release`** and auto-rotate (`+0x13b = 1`).
- **Auto-rotate** (per frame):
  - yaw += (target − yaw)·0.25, target yaw = `0x8000 − angle[k]`, which brings the planet to the front;
  - pitch += (−3096 − pitch)·0.25 (−3096 ≈ −17°);
  - done when |Δyaw| ≤ 4·dt and |Δpitch| ≤ 4·dt → `+0x1a0 = k` (it also stops early when |Δyaw| < 11).

### 5.3 Zoom in / out

- **In** (galaxy, second tap on the centred system, allowed per §7.1):
  - sound **106 `Map_Zoom_In`**, `initStarSystem`, `+0x138 = 1`;
  - three `EaseInOut`s (x, y, z) from the current camera position to `sun − (0, 0, 500)`;
  - each frame `Increase(dt·15)` with value = `min + range·(sin(φ)·0.5 + 0.5)` and φ going 3π/2 → 5π/2 by `x/65536·2π`, so the zoom **lasts 32768/15 = 2184.5 ms, sine ease-in-out**;
  - when all three are within 1 unit: `+4 = 3`.
- **Out** (footer back in the system view when `+0xf4`):
  - sound **107 `Map_Zoom_Out`**, inertia cleared, the eases reversed (`SetRange(max, min)`), `+0x139 = 1`;
  - at the end the system geometry is freed and `+4 = 0`.
- During the zoom `fade` cross-fades the overlays and the wormhole scales and moves (§2.2).

### 5.4 Back

The footer back button (`Layout::OnTouchEnd == 1`):
- in the system view with the galaxy allowed → zoom out;
- otherwise **close**: camera restored, `Map_Whoosh` stopped, `OnTouchEnd` returns **1**. The owner closes the map, and `byte+0 == 0` means "no destination".

`OnTouchEnd` also returns 1 after a gate / Khador selection (byte+0 = 1). `StarMap::depart` switches module itself.

---

## 6. Confirming a station (`OnTouchEnd` mode 3, second tap)

**Not in mission mode** (in mission mode the second tap does nothing). Checks, in this order:

1. The planet is the **current station** → ChoiceWindow info **419 "This is where you are right now."** (OK closes it).
2. **Campaign requirement boxes** (info only, `+0x1e4`): mission 0x18 without scanner + tractor beam (532), 0x87 without a drill (3213), 0x5b / 0x5e passenger cabins (3214), 0x69 Gamma Shield II (3217), 0x8b Vossk ship + signature (3215), 0x8e spectral filter / plasma collector / 15 missiles (3216) or no free cargo (3218). Free play can skip these.
3. **Jump-drive checks** (only `+0xab`):
   - cells < needed, no volatile goods, needed ≠ 1 → info **579** "Unable to jump! You don't have enough energy cells left to use the Khador Drive." (nothing happens);
   - cells < needed, needed == 1 → yes/no **582** "You don't have enough energy cells left to use the Khador Drive. Use this systems jumpgate instead?";
   - target has no gate (`+0x1d4`) and cells < 2·needed → yes/no **581** "You won't have enough energy cells to leave this system again. Are you sure you want to make the jump?"
4. Otherwise yes/no **"574 Destination: <station>\n421 Travel to this station?"** (title 390 "Info", buttons 134 "Yes" / 135 "No").

Answer handling (ChoiceWindow result **0 = Yes (left), 1 = No**; No just closes the box and the map stays):

| Mode | Yes with enough cells, or no drive | Yes with cells < needed and needed == 1 (582) |
|---|---|---|
| **station** (`+0xaa = 0`) | `depart(true)`: see below | `depart(false)`: the same, but never an instant jump (gate route) |
| **gate / Khador** (`+0xaa = 1`) | `Level::programmedStation = station`; if jump drive: `doInstantJump = (other system)`, `energyCellsForNextJump = needed`; byte+0 = 1; restore the camera; return 1 | `programmedStation = station`, `doInstantJump = 0`, byte+0 = 1, return 1 |

**`StarMap::depart(bool)` 0xd81ac, station mode:**
- `Status+0x5c/0x60/0x64/0x68 = −1` (full shield / armor / hull / gamma on spawn);
- `Status::departStation(currentStation)` (launch into the current orbit, `initStreamOut` stays 0 = undock spawn);
- `programmedStation = target` unless it is the current station;
- instant jump if the argument is true, no volatile goods, a fitted / integrated drive or `+0xab`, and the target is in another system; then `energyCellsForNextJump = +0x1d0`;
- `Achievements::resetNewMedals`, stop sound 102, `switch_to_target_setting = 1` (space music), module 2;
- campaign mission 3: departs without changing anything.

In gate mode (`+0xaa`) `depart` would do `departStation(target)` + `setInitStreamOut` + `jumpgateUsed` directly. That path isn't reached from `OnTouchEnd` in this binary: gate selections go through byte+0.

Then in space:
- **no instant jump**: the launch sequence runs (`station_interior.md` §3.4). At its end `LevelScript` calls `setAutoPilotToProgrammedStation` with "571 Autopilot 38 On" + sound 28. Routing (`autopilot_travel.md` §3.2):
  - same system → that station's planet → automatic **planet jump** when the planet lock completes;
  - other system → the planet of the current system's gate station (planet jump), arriving at the hidden gate;
  - the autopilot then continues to landmark 1 → **gate** (§8).
- **instant jump**: `MGame::OnUpdate` starts charging (`startChargingJumpDrive`, §9) once `LevelScript` time > 5000 ms, i.e. during the launch camera.

**Gate map closing** (`MGame::OnTouchEnd` ~0x1abb00, `StarMap::OnTouchEnd == 1`):
- `StarSystem::initLight`, unpause, resume sounds, then:
  - **byte+0 == 0** (back, nothing chosen) and inside the gate sphere: `dockToStream(false)` (speed 2, input back), autopilot off, the ship gets the **gate's direction** and is placed at **gate position + (0, 0, 8000)**;
  - **byte+0 == 1**, inside the gate sphere → **gate jump scene** (`+0xd9 = 0`, `startJumpScene`);
  - **byte+0 == 1**, not in the sphere (Khador menu), no instant jump → `setAutoPilotToProgrammedStation`;
  - **byte+0 == 1**, instant jump → nothing here; `OnUpdate` starts the charge.
- Finally the map is deleted.

---

## 7. Jump rules

### 7.1 Which systems can be entered / reached

| Means | Allowed targets |
|---|---|
| Station map / gate map, no drive | current system and systems in `current.jumpRoutesTo` (`systemIsInSystemRoutes` 0x180c86: index equal or listed). Others: info **420**. The gate itself jumps **one route** at a time, but the target may be **any station** of that system; the arrival is directly in that station's orbit. |
| Jump drive (`+0xab` = map opened with a drive) | any **visible** system. With volatile goods (`Ship::hasVolatileGoods`), non-adjacent targets give **612** "You can't use the Khador Drive when transporting volatile goods..." |
| Campaign | map locked before mission 9 and in 0x30/0x31 (`station_interior.md`); no galaxy view up to mission 15; fire-planet jump from mission 10 |

Gate routes aren't checked against visibility in `systemIsInSystemRoutes`. The route lines and path finder only use visible systems, but invisible systems aren't drawn or tappable, so in practice only visible neighbours can be picked.

### 7.2 Energy cells (`OnTouchBegin`, `SystemPathFinder` 0x14062e..0x140ad4)

- `getSystemPath(systems, a, b)`: **BFS** (FIFO queue) over `jumpRoutesTo`, edges only into visible systems. It returns `[a, ..., b]`, or null if unreachable or a == b.
- `getJumpDistance` = path length − 1 = **number of gate jumps**.
- `+0x1d0` = that number. If 0 and the target ≠ current → **4**, and `+0x1d4 = 1` if the target system has no routes at all (Y'mirr, Beidan, Herjaza, Skavac, Skor Terpa, Alda, Mido).
- **Hardcore** (`options[0x2c] == 1.5`): ×2.
- Examples: from Augmenta (19), Buntta / V'ikka / Weymire / Magnetar = 1, Talidor = 5. From Mido (no gate) every other system = 4.

### 7.3 Khador Drive requirements

- `Ship::hasJumpDrive` 0x1a39a4: the equipment flag `Ship+0x50` (item 85 fitted, category 18), or `hasJumpDriveIntegrated` = ship 37 Cronus, 38 Typhon, 40 Nemesis.
- Charge time = the fitted drive's attr 37, or item 85's attr 37 for integrated drives = **5000 ms**. Item 85 attr 38 = 1 is "energyConsumption" and is not used by the code paths above.
- Cells: `startChargingJumpDrive` 0x1a9710:
  - normal: need `energyCellsForNextJump`;
  - Void (alien orbit) jumps: 1, or 2 in hardcore;
  - to the Void station (`Status+0x78`): 2× that.
  
  No cells at all → 579. Not enough → 580 "you need two energy cells ... only have one" (579 in hardcore). The cells are **removed when charging starts**, message **"-N t 1396 Energy Cells"** (HUD event 0x1e).
- Blocked on missions (HUD event 0x15 "525 Not possible on a mission.", same types as docking) and with volatile goods (612).

---

## 8. Jumpgate travel

### 8.1 Reaching the gate (`MGame::dockEvent` 0x1afebc, every frame)

- `Level::collideStream`: sphere around landmark 1 with radius `Player::setRadius` = **7500** (Vossk system: **11250**); `collidesStream` is `MGame+199`.
- `goingToStream` (autopilot target = landmark 1) and not yet docking → `PlayerEgo::dockToStream(true)` (`+0x1ed = 1`: input locked, the ship keeps moving forward at its speed, `PlayerEgo::update`). `MGame+0x109 = 1` hides the HUD.
- Next frame (still inside, HP etc. saved to Status):
  - **programmed station set** (with or without the autopilot) and no box open (`+0xc1`) → ChoiceWindow **"574 Destination: <name>\n421 Travel to this station?"**, `ChoiceWindow::left()` (Yes preselected), game paused, autopilot off.
  - **no programmed station**, map not open, `goingToStream` → StarMap gate mode (§1).
- Blocking missions give event 0x15 instead.
- ChoiceWindow answer (`MGame::OnTouchEnd`, `+0xc1` branch):
  - **Yes** → turret mode off, `+0xd9 = 0` (gate, not Khador), `startJumpScene`, `resetGunDelay`;
  - **No** → StarMap gate mode, to pick another destination.

### 8.2 `MGame::startJumpScene` 0x1abf10 (common part)

- `setVulnerable(false)`, fog off, docking point released, turret mode off, stop sound 35;
- `switchCamera(0)`;
- `MGame+0x6c = 1.22`, `CameraSetPerspective(1.22, near 20, far 300000)` (450000 in the Void before mission 0x50);
- `Hud::releaseAllKeys`, autopilot off, menus closed;
- **`+0xd8 = 1` (jump scene running), `+0x5f = 1` (cinematic: no HUD, radar or input)**;
- collision off, **camera in look-at mode** (position fixed, looks at the ship), `stopBoost` (speed 2);
- boost radial blur (post effect 0x1400002) off.

**Gate** (`+0xd9 == 0`):
- gate position G = landmark 1;
- player position **G + (0, 0, −10000)**, computer-controlled, rotation **(0, 0, 0)** (facing world +Z, toward the gate);
- camera position **G + (−2000, 300, −6000)**.

### 8.3 `MGame::updateJumpScene` 0x1afad4 (every frame while `+0xd8`)

```
hide = (gate: jump anim time > 1000 ms  (PlayerJumpgate::timeToJump 0xb1c4c) or no gate)
       (Khador: fx anim time > 1700 ms)
if not hide:
    camera.translate(R_ship · (5·dt, 2·dt, (gate ? −3 : −5)·dt))   // slow drift right / up / back
    G = gate position (Khador: fx position)
if gate and camera.z < G.z − 10000:
    PlayerJumpgate::activate()        // once: idle _anim_add replaced by _jump_anim_add, play once
    if ship.z >= G.z − 16500 and not yet played: stop engine/35/0x8d4/0x8d5, play 31 "Jumpgate"
if hide: ship speed 90, ship invisible, exhaust invisible
if (gate: PlayerJumpgate::animationEnded 0xb1c78) (Khador: fx transform not playing):
    campaign 0x2a in the Void: scripted event instead (not needed)
    else: Status::departStation(programmedStation); Level::setInitStreamOut();
          gate: Status::jumpgateUsed() (statistic +0x1dc)
          target == Void station: initStreamOutPosition = 1, comingFromAlienWorld = 1
          programmedStation = null; save HP / shield / armor / gamma / secondary weapon;
          switch_to_target_setting = 1; module 2 (reload in the target station's orbit)
```

Timeline at the normal speed of 2 u/ms:

| t | Event |
|---|---|
| 0 | ship at G.z − 10000, camera at G.z − 6000 (off to the left and above) |
| ≈ 1333 ms | the camera, drifting back 3 u/ms, passes G.z − 10000 → **gate activation + sound 31** (the ship at G.z − 7333, so the second condition is already true) |
| ≈ 2333 ms | jump animation > 1000 ms → **ship hidden**, speed 90; the camera stops drifting but keeps looking at the (invisible) ship, so it swings along its path through the gate |
| ≈ 6333 ms | `_jump_anim_add` ends (all four races' jump anims last **5000 ms**) → load |

**Gate animation assets** (`Level::createSpace`, table `DAT_00254360[race][4]` = main, emissive, idle anim_add, jump anim_add):

| Race | Main | Emissive | Idle anim_add | Jump anim |
|---|---|---|---|---|
| Terran | 15000 | 15002 | 15001 | **15003** `jumpgate_terran_jump_anim_add` |
| Vossk | 15004 `_anim` | 15006 | 15005 | **15007** |
| Nivelian | 15008 | 15010 | 15009 | **15011** |
| Midorian | 15012 | 15014 | 15013 | **15015** |

- The idle anim_add loops (2500–2550 ms) and is the last child (`AEGeometry+0x14`).
- `activate` 0xb1c00 removes it and adds the jump animation with state 1 (play once).
- The jump meshes have 5–14 parts with `extra` (opacity) channels: three long parts (5000 ms) and short ones (2500 ms).
- The prefabs `Resources/Assembled/main/jumpgates/jumpgate_*` hold the gate. The jump anim mesh exists as a single prefab (`Prefabs/main/jumpgates/jumpgate_<race>_jump_anim_add`) and has to be swapped in.

There is **no warp tunnel, flash, fade or FOV effect** in this code. The loading screen follows the module switch.

### 8.4 Arrival

`departStation(target)` pushes the station stack, and `setInitStreamOut` means "arrived by travel". `Level::init` (`space_level_setup.md` §4):
- target is the system's **gate station** → spawn at **landmark 2** (hidden gate), facing the station;
- any other station → `4 × planet billboard of the previous station`, but the previous station is in another system → **(0, 0, 100000)**, facing the station.

Then comes the 7000 ms look-at fly-in: camera at ship + R·(±(500..999), ±(500..999), 7000), invulnerable, no collision (`station_interior.md` §3.4). `programmedStation` was cleared, so **no autopilot follows** a gate jump.

**Orbit information** (`Hud::drawOrbitInformation` 0x193a3c) is drawn during that cinematic when campaign mission > 7, no LevelScript event, not a planet jump, not the jump scene. HD layout (Layout +0x21c..0x228 = 12, 10, 40, 70, retina branch of the NEON select at `Layout::Layout` ~0xe4290):

| Element | Position | Text / colour |
|---|---|---|
| race logo | (3, 3) | `DAT_00259e78[race]` = the same logos 1190 / 1187 / 1189 / 1188; none if unowned |
| station name | x = logoWidth + 12, y = 10 | white |
| system line | same x, y = 40 | "<System> 137 System" (campaign mission > 15 only) |
| security | same x, y = 70 | 402..405 in the security colour (Shima: 3 when `Status+0x114 > 1`) |

Not drawn in the Void.

---

## 9. Khador Drive travel

### 9.1 In flight (`MGame::UseKhadorDrive` 0x1a9480)

- HUD menu 0 entry "1359 Khador Drive" (key 0x1000; half-transparent while charging). The same menu shows the cell count (`Hud+0x21c`).
- Refused while already charging; blocking missions → event 0x15.
- **In the Void**: `programmedStation = station Status+0x84` (100 in mission 0x50) → charge immediately.
- Volatile goods → ChoiceWindow 612.
- Otherwise the StarMap opens in jump mode (`setJumpMapMode(true, true)`, radial blur off).
- Outside the Void, `askForJumpIntoAlienWorld` first asks **422 "Jump to the Void's system?"**:
  - Yes (galaxy view, not mission / reveal mode): `programmedStation = Status+0x78` (Void station), `doInstantJump = 1`, `energyCellsForNextJump = +0x1d0`;
  - No: the normal map.
  - See Uncertainty 6.

### 9.2 Charging and jumping

- `MGame::OnUpdate` 0x1ac778: `doInstantJump` and `LevelScript` time > 5000 → `doInstantJump = 0`, `+0xd9 = 1`, `startChargingJumpDrive`.
- `startChargingJumpDrive`: the cell checks and removal of §7.3, then `PlayerEgo::startJumpDrive` 0xa6560:
  - sound **33 `Jumpgate_Charge`** (`Jumpgate_Charge_02.ogg`, exactly 5.0 s);
  - HUD event 0x19 (`Hud+0x217 = 1`: charge indicator, driven by `PlayerEgo::getDriveChargeRate` = elapsed / charge time; drawing not decoded);
  - timer `+0x1fc`.
- At `+0x1fc ≥ +0x200` (5000 ms): HUD event 0x1a (indicator off). In `OnUpdate`, `isChargingDrive && driveReady` → `startJumpScene`. The ship flies normally while charging.
- `startJumpScene` with `+0xd9 = 1`:
  - ship `resetMovement`, computer-controlled (keeps flying straight at 2 u/ms);
  - fx **`khador_jump` 15026** (`Models/main/fx/khador_jump.fbx`, 35 animated parts, longest 4000 ms, state 1 = once) at **ship + dir·3000**, scale 2, facing the ship's direction (up (0, 1, 0));
  - camera at ship + dir·3000 + R_ship·(−2000, 300, −2000) (1000 ahead, 2000 left, 300 up);
  - stop engine / 35 / 0x8d4 / 0x8d5 sounds, play **32 `KhadorDrive`**.
- `updateJumpScene`: camera drift (5, 2, −5)·dt; at fx time > 1700 ms the ship is hidden. At the fx end (~4000 ms) the level loads as in §8.3, without `jumpgateUsed`.
- Arrival as in §8.4. The previous station is usually in another system → (0, 0, 100000), or landmark 2 for gate stations.

`hyper_drive` 15027 is the campaign intro mesh (mission 0), not this jump.

---

## 10. Station Map button flow (summary)

1. Station menu button 2 **"177 Map"** (`ModStation::OnKeyPress` case 2):
   - locked before campaign mission 9 and in 0x30/0x31;
   - overloaded cargo → **204**;
   - mission 0x4d not in ship 37 → 326.
2. Create or re-init `StarMap(false, 0, false, −1)`. `setJumpMapMode(false, true)` if item 85 is fitted or integrated. `ModStation+0x63 = 1`, stop station ambience 122, first-time help 628.
3. Browse:
   - galaxy (tap = select + centre; tap again = enter, only current / neighbour systems without a drive);
   - system view (tap = select + rotate; tap again = confirm);
   - Key and Help buttons; energy line with a drive.
4. Confirm → "Destination: X / Travel to this station?" → **Yes = leave the station immediately** (`depart(true)`, module 2, launch sequence, then the autopilot or the Khador charge). Help 631: "Once you've done so, you'll leave the station (after a security check) and your auto pilot will take course for the planet you've selected."
5. Back (footer) → zoom out / close (`OnTouchEnd` returns 1 → `ModStation+0x63 = 0`, `resetLight`). Picking the current station only shows 419.

Nothing is saved for "set destination without leaving": the station map always departs.

---

## 11. Reference tables

### 11.1 Sounds (FMOD ids, `fmod_event_ids.txt`)

| Id | Event | File | When |
|---|---|---|---|
| 102 | `Map_Whoosh` | (no ogg by name; `Map_Click_01.ogg` is the only unmapped map file, unverified) | every map touch-down (restarted); stopped on close / depart. `update` sets FMOD parameter 0 (probably drag speed). |
| 103 | `Select_System` | `SFX_STATION_MAINVIEW/Select_System_04.ogg` | galaxy tap selects a different system |
| 104 | `Map_Select_Planet_Push` | `Map_Select_Planet_Push_01.ogg` | system-view tap on a planet |
| 105 | `Map_Select_Planet_Release` | `Map_Select_Planet_Release_01.ogg` | release on a planet that isn't selected yet (starts auto-rotate) |
| 106 / 107 | `Map_Zoom_In` / `Map_Zoom_Out` | `Map_Zoom_In.ogg` (2.68 s) / `Map_Zoom_Out.ogg` (2.32 s) | zoom |
| 124 / 123 / 126 | button push / release / message box | – | TouchButtons, ChoiceWindows (generic) |
| 31 | `Jumpgate` | `SFX_SPACE/Jumpgate_1b/2b/3b.ogg` (5.74 s; the event presumably picks one) | gate activation |
| 32 | `KhadorDrive` | (no ogg by name; `Jumpgate_4c.ogg` 5.74 s / `Jumpgate_5c.ogg` 4.67 s are the unmapped candidates) | Khador jump fx |
| 33 | `Jumpgate_Charge` | `Jumpgate_Charge_02.ogg` (5.0 s) | Khador charge start |
| 28 / 29 | Autopilot on / off | – | autopilot to the programmed station after launch |

### 11.2 Texts

| Id | English | Use |
|---|---|---|
| 177 | Map | header, station button |
| 400 | Key | legend button |
| 401 / 547 / 556 / 555 / 274 | Already visited / Jumpgate / Freelance / Story / Products finished | legend rows |
| 133 | Tech level | "Tech level: N" under the selected planet |
| 137 | System | orbit info "<name> System" |
| 402–405 | Dangerous / Risky / Average / Secure | security (colours §4.2) |
| 406–409 | Terran / Vossk / Nivelian / Midorian | race line (406 + race) |
| 419 | This is where you are right now. | confirm on the current station |
| 420 | You cannot reach this location from the current system's jumpgate. | entering a non-adjacent system without a drive |
| 421 | Travel to this station? | confirmation (station map, gate map, gate arrival) |
| 422 | Jump to the Void's system? | Khador map in normal space |
| 574 | Destination | "Destination: <station>" |
| 578 | Energy cells needed: | "N / M" line |
| 579 | Unable to jump! You don't have enough energy cells left to use the Khador Drive. | |
| 580 | Unable to jump! You need two energy cells for this jump but you only have one left. | Void jump |
| 581 | You won't have enough energy cells to leave this system again. Are you sure you want to make the jump? | target without a gate |
| 582 | You don't have enough energy cells left to use the Khador Drive. Use this systems jumpgate instead? | Yes = gate route |
| 612 | You can't use the Khador Drive when transporting volatile goods... | |
| 628 / 631 (629, 630 / 632, 633) | Map help / System map help | help button |
| 634 | ...the yellow line will show you the route. | mission map hint |
| 1359 | Khador Drive | HUD menu entry |
| 1396 | Energy Cells | "-N t Energy Cells" |
| 390 / 134 / 135 / 524 | Info / Yes / No / OK | ChoiceWindow |
| 204 / 326 | cargo full / board Khador's ship | Map button refusals |
| 525 | Not possible on a mission. | HUD event 0x15 |

### 11.3 Images

All rects are verified by cropping. Unless noted they come from `gof2_interface_iphone4.png` (the HD re-binding of `gof2_interface.png`).

| Id | Rect [x, y, w, h] | What |
|---|---|---|
| 0x48a | [269, 47, 99, 99] | faint rounded-square ring, not selected |
| 0x48c | [317, 739, 143, 143] | glowing orange rounded-square ring, selected |
| 0x4fd | [1, 1607, 99, 99] | soft gold rounded square, pulsing "you are here" |
| 0x4a2 | [326, 148, 21, 18] | green tick "Already visited" |
| 0x454 | [475, 147, 26, 23] | gold ship "Story" |
| 0x455 | [547, 124, 26, 23] | white ship "Freelance" |
| 0x453 | `gof2_interface2_ipad_large.png` [1776, 17, 26, 26] | cyan four-arrow gate icon |
| 0x452 | [370, 47, 20, 18] | small blue icon "Products finished" |
| 0x545 | [249, 487, 18, 18] | orange house icon (Shima special state) |
| 0x4a1 / 0x49c / 0x49f / 0x49e | [226, 90] / [273, 1889] / [272, 1650] / [2002, 222], 36×36 | race icons Terran (gold phoenix) / Vossk (green) / Nivelian (blue hexagon) / Midorian (grey X) |
| 0x4a6 / 0x4a3 / 0x4a5 / 0x4a4 | [337, 1464, 93, 103] / [1875, 1137, 98, 89] / [1659, 35, 90, 90] / [825, 1425, 88, 97] | big race logos (system header, orbit info) |

### 11.4 3D assets

| Asset | Id | Unity |
|---|---|---|
| Galaxy background + 2 fog layers | 16850 / 16851 / 16852 | `Resources/Assembled/main/galaxymap/galaxymap_background` |
| System sun sprites (galaxy) | 18070..18088 (`plane` + `Textures/main/suns/sun_0XX.png`, additive) | `galaxymap_sun` (texture per system at runtime) |
| System-view sun | 6768 `plane` + `DAT_00254420` texture | `galaxymap_system_sun` |
| Planets | 18180 + station tex | `galaxymap_planet_000..026` |
| Planet ring | 16853 | child in the planet prefabs 009 / 016 / 021 (add for stations 120, 126, 130, 132) |
| Orbit ring | 6779 | `galaxymap_orbit` (scale 2r/65536) |
| Wormhole | 16994 | `galaxymap_wormhole` |
| Gate jump animations | 15003 / 15007 / 15011 / 15015 | single-mesh prefabs under `Prefabs/main/jumpgates` |
| Khador jump fx | 15026 | `Prefabs/main/fx/khador_jump` (`Resources/Assembled/main/fx` has none) |
| Unused | `Models/main/galaxymap/map_sun_000..010` have no resource id; the code uses `plane` + sun textures | – |

---

## 12. Unity build recipe

1. **Data**:
   - `Session`: `SystemVisible[34]` (init from `initiallyVisible`), `VisitedStations` (set on docking), `ProgrammedStation` (−1 = none), `DoInstantJump`, `EnergyCellsForNextJump`, `JumpgatesUsed`;
   - plain C# `GalaxyMap`: sun positions §2.2, BFS path + cells §7.2, `IsInRoutes`, system-map layout §2.3 with `JavaRandom(system·1000)`;
   - unit-test it against `starmap_tables.py` (Mido layout, Augmenta cells).
2. **Map scene / overlay**:
   - an own camera and root (additive scene or a disabled root in Space / Station), with the game paused (`Time.timeScale = 0`, the map on unscaled time);
   - Unity placement: suns at `(x, y, −z)·0.05` of the game positions, camera at `(camX, camY, 0)·0.05` with **yaw 180°** (looks −Z Unity = game +Z; screen-right = −X), vertical FOV 65.9°, near 10 m, far 3200 m;
   - background prefab at game (−3000, −2500, 0) with the gate-style (0, π, 0) → Unity identity rule.
3. **Galaxy view**:
   - suns scale 0.012 (additive), only visible systems get UI;
   - faint route lines (white α 34), pulse lines from the current system (period 990 ms), labels / rings / icons per §4.2 in UI Toolkit, positioned from `Camera.WorldToScreenPoint` on the 1920×1080 reference;
   - tap radius 60 px, drag 0.325 px → 6.5 units, inertia 0.9 per frame at 60 fps (use `0.9^(dt/16.7)`), pan limits and spring §5.1;
   - auto-centre divisor 30;
   - selection: tap → select + centre; tap again → zoom.
4. **System view**:
   - container at the sun, scale 1/128, rotation (pitch −π/8, yaw π/8, roll −π/32) with the game order Rx·Ry·Rz (mirror via `OrbitLayout.RotationToUnity`);
   - planets / orbits / rings per §2.3, planet self-spin 0.0002 rad/ms, one point light at the sun (ambient 0.2, diffuse 2), sun sprite scale 0.004;
   - drag: 16.25 / 65536 turn per px, pitch clamp ±45°, auto-rotate factor 0.25 to yaw `0x8000 − angle`, pitch −3096.
5. **Zoom**: lerp the camera `pos → sun − (0, 0, 500)` (game) with `0.5 − 0.5·cos(π·t)` over 2184.5 ms, cross-fade the overlays with the same t, sounds 106 / 107.
6. **Confirm dialog** and outcomes per §6:
   - station: set `ProgrammedStation`, launch (existing launch sequence), and at its end the autopilot (the routing already exists in `Navigation`: planet jump / gate station planet / gate);
   - gate: jump scene;
   - Khador: charge.
   - Replace the current "Reaching the gate: Not available." with §8.1.
7. **Gate jump scene** (`GoF2JumpScene` MonoBehaviour):
   - HUD off, invulnerable, autopilot off;
   - ship to G + (0, 0, −10000) game (Unity: G + (0, 0, +500 m) behind the gate along Unity −Z), facing game +Z (Unity −Z), 2 u/ms;
   - fixed camera at G + (−2000, 300, −6000) game, look at the ship, drift (5, 2, −3) u/ms in ship space;
   - at camera z < G.z − 10000: swap the gate's idle anim part for `jumpgate_<race>_jump_anim_add` (`GoF2KeyframePlayer`, once), play `Jumpgate_1b..3b`;
   - after 1000 ms of it: hide the ship;
   - at 5000 ms: `StationIndex = target`, `ArrivedByTravel = true`, `JumpgatesUsed++`, `ProgrammedStation = −1`, reload `Space`.
8. **Khador**:
   - HUD menu entry when a drive is fitted or integrated;
   - map in jump mode;
   - charge 5000 ms (sound 33, cells removed at the start, "-N t Energy Cells" message, charge bar);
   - fx `khador_jump` at ship + dir·3000, scale 2; camera per §9.2; hide the ship at 1700 ms, load at the fx end (~4000 ms), sound 32 (pick `Jumpgate_4c` or `_5c` until verified).
9. **Arrival**: already implemented (`ArrivedByTravel`, landmark 2 / (0, 0, 100000), fly-in). Add the orbit information (§8.4) during the fly-in.

---

## 13. Functions

| Function | Address |
|---|---|
| `StarMap::StarMap` / `init` / `~StarMap` | 0xd6880 / 0xd6d20 / 0xd7720 |
| `StarMap::initStarSystem` / `initLights` / `setStart` / `depart` | 0xd7810 / 0xd8130 / 0xd816c / 0xd81ac |
| `StarMap::isInPlanetMode` / `setJumpMapMode` / `render` / `drawKey` / `drawOnScreenInfo` / `draw` | 0xd840c / 0xd8418 / 0xd8424 / 0xd84b0 / 0xd8710 / 0xd970c |
| `StarMap::askForJumpIntoAlienWorld` / `update` / `OnTouchBegin` / `OnTouchMove` / `OnTouchEnd` | 0xda2a8 / 0xda2e0 / 0xdaf80 / 0xdb300 / 0xdb69c |
| `SystemPathFinder::getJumpDistance` / `getSystemPath` / `search` / `constructPath` | 0x140632 / 0x14065c / 0x140820 / 0x1409c8 |
| `SolarSystem::isFullyDiscovered` / `getRoutes` / `systemIsInSystemRoutes` / `hasNoOwner` / `getX` / `getY` / `getZ` | 0x180c30 / 0x180c82 / 0x180c86 / 0x180cc0 / 0x180b74.. |
| `Station::isDiscovered` | 0xb3a50 |
| `Status::getSystemVisibilities` / `setSystemVisibility` / `departStation` / `jumpgateUsed` / `hardCoreMode` / `inAlienOrbit` / `orbitHasPlanetRing` | 0xb6128 / 0xb612c / 0xb63e0 / 0xb9836 / 0xb9148 / 0xb6810 / 0xb8fac |
| `Ship::hasJumpDrive` / `hasJumpDriveIntegrated` | 0x1a39a4 / 0x1a39ca |
| `MGame::UseKhadorDrive` / `startChargingJumpDrive` / `startJumpScene` / `updateJumpScene` / `dockEvent` | 0x1a9480 / 0x1a9710 / 0x1abf10 / 0x1afad4 / 0x1afebc |
| `MGame::OnTouchEnd` (gate ChoiceWindow, map close) / `OnUpdate` (instant jump, drive ready) / `OnRender3D` | 0x1a98d8 / 0x1ac778 / 0x1b164c |
| `PlayerEgo::startJumpDrive` / `driveReady` / `isChargingDrive` / `getDriveChargeRate` / `dockToStream` / `isDockedToStream` / `stopBoost` | 0xa6560 / 0xa6f18 / 0xa6f26 / 0xa6eec / 0xaddcc / 0xadd18 / 0xa6d18 |
| `PlayerJumpgate::PlayerJumpgate` / `addJumpAnimationHandle` / `activate` / `timeToJump` / `animationEnded` | 0xb1a8c / 0xb1bf8 / 0xb1c00 / 0xb1c4c / 0xb1c78 |
| `ModStation::OnKeyPress` (Map button) / `OnTouchEnd` / `OnRender3D` | 0xec6f8 / 0xea4ec / 0xefac4 |
| `Hud::drawOrbitInformation` / `hudEvent` (0x19, 0x1a, 0x1e) / `initHudMenu` (menu 0 Khador entry) | 0x193a3c / 0x18f5a0 / 0x18e080 |
| `AbyssEngine::EaseInOut::SetRange` / `Increase` | 0x7aafc / 0x7ab20 |
| `ChoiceWindow::set(text)` (info) / `set(text, bool)` (yes/no) | 0x1700f0 / 0x1705b4 |

Tables and constants:

| Name | Address | Content |
|---|---|---|
| Key texts | `DAT_0025446c` | {400, 401, 547, 556, 555, 274} |
| Planet scale | `DAT_00254484` | 28 × int |
| Header logo | `DAT_002544f4` | race → image |
| System-view sun texture | `DAT_00254420` | per system tex |
| Security colours | `DAT_0025451c` / `DAT_00259ea0` | 4 × RGB int |
| Jumpgate meshes | `DAT_00254360` | 4 × 4 u16 |
| Gate LODs | `DAT_00251fa0` | – |
| Orbit-info logos | `DAT_00259e78` | – |
| Layout (HD) | – | +4 = 30, +8 = 60, +0xc = 58, +0x10 = 74, +0x14 = 50, +0x2c = 6, +0x88 = 60, +0x8c = 64, +0x90 = 0.325, +0x21c.. = 12 / 10 / 40 / 70 |

---

## Uncertainties

1. **ChoiceWindow result mapping** (0 = left / Yes, 1 = right / No) is inferred from the two call sites: MGame opens the map on 1 and jumps on 0; StarMap closes on 1 and acts on 0. Both are consistent.
2. **Draw anchors**: `DrawImage2D(..., 0x11, a)` is read as "a = anchor: low nibble 1 left / 2 right / 4 centre, high nibble 1 top / 2 bottom / 4 centre". This fits 'D' = centred rings, 0x22 = the bottom-right Key button, and 0x12 = the race icon drawn left of the name, right edge on the name. Not checked in the engine.
3. **Invisible systems' suns**: the loop in `StarMap::StarMap` creates all 34 sun sprites as children of the galaxy root, and `render` draws the whole root. Only labels, lines and taps check visibility, so hidden systems' suns would still show. I found no per-system `setVisible`. Verify against gameplay footage; a faithful but sensible remake hides them.
4. **`AEGeometry::setVisible` on children** (selected galaxy sun in the system view; planet index 1 in `initStarSystem`) only sets a flag read by `AEGeometry::render`. These geometries are drawn through their parent's transform, so the calls look like no-ops. The planet-1 call is probably a leftover. Both are treated as visible here.
5. **Rotation axes** of `rotate(dt·0.0002, 0, 0)` (planet spin) and of the orbit ring `setRotation(nextInt(3141)/1000, ...)` were taken from the scenes notes (yaw). The container order is pitch x, yaw y, roll z (verified from the argument registers in `update` 0xdace0..).
6. **`askForJumpIntoAlienWorld`** is called whenever the Khador map opens outside the Void (the condition is `inAlienOrbit() == 0`; that function decompiles as void and its return was assumed). If the retail game doesn't ask every time, a campaign condition was lost. The remake can skip the Void.
7. **Gate approach axis**: the ship is placed at G − (0, 0, 10000) with rotation 0 regardless of the gate's yaw (`space_level_setup.md` §3.2 gives gates yaws up to ±30°). The scene may not fly exactly through the ring axis; check visually.
8. **Back from the gate map without a destination** puts the ship at gate + (0, 0, 8000) world with the gate's direction. That is decoded literally, not checked in play.
9. **Map_Whoosh (102) and KhadorDrive (32)** have no ogg with a matching name; the candidates in §11.1 are guesses.
10. **Reveal sun scale** `t/4000 · 0.002` (a double literal at 0xda798) is smaller than the normal 0.012, and nothing restores it afterwards in `update`. It looks odd but is what the code does.
11. **Energy line colour** when cells < needed (a `SetColor` whose value was lost) and the Khador **charge indicator** drawing (`Hud+0x217`) weren't decoded.
12. **Auto-centre and inertia are frame-based** (per `update` call, ×0.9, /30, ×0.25). At other frame rates, scale by dt/16.7 ms. The original ran capped at 30 or 60 fps (not determined).
13. **Security index for Shima**: `drawOnScreenInfo` forces 3 when `Status+0x114 > 1`; the meaning of that state (supernova DLC progress) wasn't traced.
14. Layout values are the retina branch of `Layout::Layout`. The iPadLarge path may re-run `Layout::reload` 0xe52b8, which wasn't checked for these offsets.
