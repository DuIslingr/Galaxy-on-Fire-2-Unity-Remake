# Autopilot, target locks on station / jumpgate / planets, planet jump, fast-forward

How the original lets the player lock the station, the jumpgate and the other stations' planets, engage the autopilot, jump to another station of the same system, and speed the flight up. Decoded from `libgof2hdaa.so` (Android HD). Game units and milliseconds unless noted (Unity: 1 unit = 0.05 m). Addresses use the Ghidra image base 0x10000. 2D values are **HD screen pixels** (`retinaDisplay = iPad = iPadLarge = 1`, see `shop.md` §1.2), i.e. a 1920×1080 canvas.

Not repeated here (read them first): spawn/arrival positions → `space_level_setup.md` §4; dock/jump triggers and the gate → `space_level_setup.md` §8 and `station_interior.md` §3.4/3.5 (launch/arrival look-at camera, 7000 ms sequence); asteroid lock, fire action, `moveToPosition` → `mining.md` §3; planet billboards (where each planet is) → `space_backdrop.md` "StarSystem layout".

Helper: `Reference/tools/autopilot/autopilot_tables.py` prints every image rect used below, the distance formatter (`calc_distance`), and (`crops DIR`) cuts the images.

---

## 0. TL;DR for Unity

1. **Three kinds of "landmark-like" targets**, all found by `Radar::draw` (0x1554fc) each frame by keeping them near the crosshair: **landmark 0 = station**, **landmark 1 = jumpgate**, and **planet targets** (one per station of the system, drawn as the planet billboards; the current station's own planet is never lockable). Lock time = scanner attr 29 (8000 ms without a scanner; Telta Ecoscan of the new game = 3000 ms). Lock sound 26 `Target_Lock`, a 24-frame ring fills around the crosshair, a top plate shows the name, an **arrow appears on the fire button**.
2. **Station / jumpgate locked + fire** → autopilot on, HUD "Target: Var Hastra Station" / "Target: Jumpgate" + sound 28. The ship turns and flies to the landmark centre at the normal speed (throttle set to 100 % once). Reaching the station (|pos| < 16000 or its collision volume) docks (loading screen → station). Reaching the gate sphere starts the gate/star-map flow.
3. **Planet locked + fire** (or the autopilot heading to a programmed station's planet completes the lock by itself) → **planet jump** (`PlayerEgo::dockToPlanet` 0xadd20): no dialog; sound 5 `Jump_to_planets`; the chase camera **freezes in place and keeps looking at the ship** while the ship flies **straight on at 8 u/ms** (4× base speed, boost exhaust, no radial blur/FOV change) for **3000 ms**; then `Status::departStation(thatStation)`, stream-out arrival, reload the level in the new orbit (arrival: `space_level_setup.md` §4 + the 7 s look-at fly-in of `station_interior.md` §3.4). Manual fire hides the whole HUD during the 3 s.
4. **Autopilot off**: the left-side **autopilot button** (image 0x4b0/0x4b1) when the autopilot runs; HUD "Autopilot Off" + sound 29. The same button, when no autopilot runs, opens the **autopilot menu** (Asteroid field / <Station> Station / Jumpgate / Waypoint / Destination: X / docking targets). During the autopilot the stick is ignored, the throttle slider, boost and guns still work, enemy/asteroid locking is suspended.
5. **Fast-forward**: the double-arrow button (0x541/0x540) above the autopilot button, shown only while the autopilot (or an asteroid/docking-point approach) runs, **no hostile ships** are in the orbit, **the target is ≥ 20000 units away** and no radio message plays. **Hold** it: the whole game update runs with **dt × 5** (camera in 5 sub-steps); releasing any touch, enemies appearing, a radio message, or coming within 20000 units of the target ends it. No sound, no screen effect, no message.
6. **Distance label** (`Radar::calcDistance` 0x15827c): `M = 8·floor(d/128)`; `M < 1000` → "624m", else "6.2km" (one truncated decimal). Shown next to the station/jumpgate bracket when the landmark is near the screen centre. Planets show only their name, no distance.

---

## 1. Radar: what is drawn and how locks work

`Radar::draw(Player*, Hud*, dt)` 0x1554fc, called from `MGame::OnRender2D` 0x1b10bc only when not mining and the HUD is visible (`MGame+0x5f == 0`, i.e. not during a cinematic / manual planet jump); dt = the (fast-forward scaled) frame time. The lock timers therefore also run 5× under fast-forward.

### 1.1 Screen geometry (Radar ctor 0x1545e0, HD values)

| Field | Value | Use |
|---|---|---|
| `+0x104/+0x108` | (w/2, h/2) = (960, 540) | screen centre |
| `+0x124` | w/16 = **120** | landmark/asteroid/enemy lock box half-size around `PlayerEgo::crosshairPos` (box ±120 px) |
| `+0x124 >> 1` | **60** | **planet lock box half-size (±60 px = ±w/32)**, verified in the disassembly at 0x155d5e (`asrs r2, r1, #1`) |
| `+0x128` | w/6 = **320** | half-size of the "near the screen centre" square in which landmark brackets + labels are drawn |
| `+0x1c0` image 0x4c7 | quarter ellipse 657×491 | drawn 4× mirrored around the centre (the faint radar ellipse); `Radar::update`/`elipsoidIntersect` 0x1553dc clamps markers of objects that are **not on screen** onto this ellipse: `p' = c − (c − p)/√(dx²/657² + dy²/491²)` |
| `+0x228` | layout+0xa0 = 50 | x offset of the station label |
| `+0x22c` | layout+0xa4 = 10 | x offset of other landmark labels |
| `+0x21c/+0x224` | 61 / 61 (layout+0xac/0xa8 = 122, halved) | waypoint/enemy distance text offset (x − 61, y + 61) |
| layout+0x4 | 30 | text line height used for the label lines |
| `+0x1b4` | scanner attr 29 (0x1d), else **8000** | lock time for landmarks, planets, asteroids (asteroids use −200), enemies |

`Radar::update(pos)` 0x1552f8: camera-space transform, `PaintCanvas::GetScreenPosition`; `+0x11c` = on screen, `+0xfc/+0x100` = screen x/y (clamped to the ellipse when off screen).

### 1.2 Lock state fields

| Field | Meaning |
|---|---|
| `+0x28` / `+0x24` / `+0x1a0` | landmark candidate / **landmark locked** / landmark lock timer |
| `+0x18` / `+0x14` / `+0x19c` / `+0x40` | planet candidate / **planet locked** / planet timer / **planet index** (= index in the system's station list; `getPlanetDockIndex` 0x158524 returns `system.stations[+0x40]`) |
| `+0x10` / `+0xc` / `+0x198` | asteroid candidate / locked / timer (`mining.md`) |
| `+8` / `+4` / `+0x194` | enemy candidate / locked / timer |
| `+0x214` | "the same target was locked last frame" (suppresses the repeated lock sound) |
| `+0x1a4` | **the autopilot is heading for the planet currently in the box** (computed at the start of `draw`: `goingToPlanet && !isDockingToPlanet && autoPilotTarget == planetTargets[stationEnumIndex(stations[+0x40])]`) |
| `+0x54` | **hostile ships present** (set at the end of `draw` when the hostile counter `+0x1b8` ≥ 1: active, not dying ships with `Player+0x5c` (enemy flag, set by `Player::setAlwaysEnemy`)); the same counter picks the combat music. Blocks fast-forward (§4) |

All locks are **re-evaluated every frame**: the locked field is cleared at the start of its block and set again only if the candidate is still in the box and its timer is past the lock time. Leaving the box resets the timer to 0.

### 1.3 Landmarks (station, jumpgate, wormhole)

`Level::getLandmarks()`: [0] station (null in empty orbits), [1] visible jumpgate (gate orbit only), [2] hidden gate (arrival point; **skipped**, byte offset 8), [3] wormhole. Landmarks with `KIPlayer::isVisible` (+0xf1) only. The whole landmark block is skipped at stations 109, 110 and at 111 when campaign mission > 0x5d.

Per landmark, after `update(pos)`:

- **On screen and inside the ±320 px centre square** (`|sx − 960| < 320 && |sy − 540| < 320`):
  - Lock candidate if it is also inside the **±120 px box around the crosshair**, no candidate was taken this frame, nothing else is locked (asteroid `+0xc`, gas cloud `+0x38`, salvage `+0x1c`, planet `+0x14`), it is not the wormhole (index 3) and not in turret mode. The first landmark (in array order) wins.
  - Bracket **0x4f2** (81×81, white corner brackets) centred on it (not for the wormhole).
  - Name at `(sx + 10, sy)` (station: `(sx + 50, sy)`), from the Radar name table `+0x188`:
    - [0] = `<station name> + " " + 136 "Station"` (station 101: name only; alien orbit: 415 "Void", or the landmark's own name after DLC1),
    - [1] = 547 "Jumpgate", [3] = 545 "Wormhole".
  - Station (not alien orbit): second line **"133 Tech level: N"** at `(sx + 50, sy + 30)`, third line **distance** at `(sx + 50, sy + 60)`.
  - Jumpgate (and the station in the alien orbit): distance at `(sx + 10, sy + 30)`. Wormhole: name only.
  - Texts are drawn with the default font, top-left anchored (`DrawString(..., false)`).
- **Otherwise** (outside the centre square or off screen, position clamped to the ellipse): jumpgate → icon **0x453** (26×26, four arrows) centred; wormhole → icon **0x450** (58×58); **the station gets no marker** (none drawn in `Radar::draw`).

Lock timing (only when not in turret mode, not docking to an asteroid or a docking point, and **not in autopilot**; the autopilot clears the landmark lock every frame):

```
timer(+0x1a0) += dt                       // reset to 0 when the candidate changes or leaves the box
if timer > lockTime (+0x1b4):             // strict >, no -200 here
    if not locked last frame: play 26 Target_Lock
    locked(+0x24) = candidate
ring 0x456 (24 frames 80x80, ref pixel = centre) drawn at crosshairPos while timer > 0:
    frame = locked ? 23 : (int)(23 * timer / lockTime)     // no 500 ms delay (asteroids/enemies have one)
```

### 1.4 Planets (the other stations of the system)

`StarSystem::getPlanetTargets()` (`StarSystem+0x18`): one `PlayerStatic` per station of the system, **index k = station k of `system.stations`**, wrapping planet geometry k+1 (index 0 of the geometry list is the sun). Their position is the planet billboard's world position, i.e. **camera + base offset (−20000·dir)**, re-set every frame by `StarSystem::render` (`space_backdrop.md`). `StarSystem::orbitPlanetIndex` = the index of the current station (its planet is the big one straight ahead of the undocking direction).

Block runs only if **campaign mission > 1**, not in the alien orbit, and not already docking to a planet. For each planet target that is **on screen** (no off-screen markers, no distance limit):

1. Gate planet: if this planet's station is the system's jumpgate station (`uVar37 == getWarpGateEnumIndex`) and not the current station: icon **0x453** at `(sx + 10, sy − 10)` (top-left anchored); next icon offset x = 24, else 10.
2. Mission markers at `(sx + off, sy − 10)`: **0x454** (gold ship, 26×23) = campaign mission target station (plus campaign special cases 0x74/0x78/0x7d), **0x455** (white ship) = freelance mission target (type 0xe: the agent's station).
3. Lock test, only if nothing else is locked or in box this frame (asteroid/gas/salvage/landmark lock, landmark candidate) and not turret mode: box half-size **60 px** (`w/32`; for the orbit planet the box would be `w/12`, but the orbit planet is never a candidate). The first planet in the box becomes candidate: `+0x40 = index`, `+0x18 = target` (timer reset on change).
4. If the planet is in the box and belongs to another station: **its name** (`Status::getPlanetNames()[k]` = the station's name, built in `Status::setStation` 0xb6300 from `stations.json`) at `(sx + off (+14 if a mission marker was drawn), sy − 10)`. The name appears **only while the planet is inside the lock box**.

Lock timing (no autopilot check: this lock also completes during the autopilot):

```
if planet candidate in box and not docking to an asteroid / docking point:
    timer(+0x19c) += dt
    if timer > lockTime:
        if missionBlocks: Hud::hudEvent(0x15) -> 525 "Not possible on a mission."   (no lock)
        else:
            if not locked last frame: play 26
            locked(+0x14) = candidate
            if +0x1a4 (autopilot is heading to this planet): PlayerEgo::dockToPlanet()   // automatic jump, §3
    ring as in 1.3 (only when not missionBlocks; hidden once docking to the planet)
missionBlocks = Status::getMission() not empty and its type not in {0x0, 0xb, 0xd, 0xab, 0xac}
```

### 1.5 Priority between target kinds

Order inside `Radar::draw`: waypoint marker → landmarks → planets → enemies → gas clouds → asteroids.

- Landmark candidates need: no asteroid/gas/salvage/planet lock.
- Planet candidates need: no asteroid/gas/salvage/landmark lock and no landmark in the box this frame.
- Enemies need: not autopilot, not docked to a docking point, no landmark/asteroid/gas/salvage lock, and not `+0x1a4`.
- Asteroids need: not autopilot, no enemy/landmark/planet/salvage lock or candidate (`mining.md` §3.1).

So the station/jumpgate win over planets, which win over enemies and asteroids.

### 1.6 Top plate (`Radar::drawCurrentLock` 0x158548, from `MGame::OnRender2D` after `Hud::draw`)

Nothing locked → nothing drawn (verified 0x1589a6). Otherwise plate **0x4c4** (408×57) at `(w/2 − 204, layout+0xb0 = 6)`:

| Locked | Text (centred at y = 6 + layout+…) | Icon left of the text |
|---|---|---|
| planet (`+0x14`, checked first) | station name, y = 6 + layout+0xbc (16) | none |
| asteroid | ore name + class letter (`mining.md` §3.1) | class sprite 0x44e |
| gas cloud | 3236 "Gas cloud" | none |
| enemy | ship name + " NN%" hull | race icon |
| landmark (`+0x24`) | Radar name [0]/[1]/[3] ("Var Hastra Station", "Jumpgate", "Wormhole"), y = 6 + layout+0xc4 (14) | **race icon of the system** (Radar+0xf0 sprite, frame = `SolarSystem::getRace`; alien orbit frame 8/9) at `x = textX − layout+0x2c (6) − 36`, `y = 6 + layout+0xc8 (10)` |

Race icon frames (36×36, `gof2_interface_iphone4.png`, verified by cropping): 0 Terran 0x4a1 [226, 90] gold phoenix, 1 Vossk 0x49c [273, 1889] green, 2 Nivelian 0x49f [272, 1650] blue hexagon, 3 Midorian 0x49e [2002, 222] grey X, 8 0x4a0 [250, 1010] skull, 9 0x49d [83, 1900] purple (frames 4–7 unset).

### 1.7 Arrow on the fire button (`Hud::draw` 0x190d08, ≈ line 3530 of `Hud.c`)

Image **0x536** (134×128, `gof2_interface2_ipad_large.png` [112, 1890], "up arrow over steps") drawn **centred on the fire button** (`Hud+0x380` + layout+0x164 = 0 on HD, anchor 0x11/pivot 0x44) when: not docking to an asteroid, not mining, not docking to the stream, not in a docking procedure, not docking to a docking point, not turret mode, and **a planet (`Radar+0x14`), an asteroid (`+0xc`) or a landmark (`+0x24`) is locked**, or a dockable enemy object is locked. Fire button images: 0x4b4 (198×198) normal, 0x4b5 pressed.

---

## 2. Fire = action (`MGame::OnTouchBegin` 0x1a838c, HUD key 0x10)

Evaluated on the press, in this order:

1. **Landmark locked** (`Radar+0x24`) and not in the alien orbit (and not docked to a docking point):
   - no autopilot and not turret mode → `PlayerEgo::setAutoPilot(landmark)`; HUD event **0xa** "546 Target: <station name> 136 Station" (station), **0xf** "Target: 545 Wormhole" (landmark 3), else **0xc** "Target: 547 Jumpgate"; every one plays sound **28 `Autopilot_Activate`**. Then `Hud::touchEnd` (the fire press is consumed, no shot).
   - autopilot running (practically unreachable, the landmark lock is cleared during the autopilot) → event 6 "Autopilot Off" + 29, autopilot off, locks cleared.
2. **Planet locked** (`Radar+0x14`), not docking to a planet, not docked to a docking point:
   - campaign mission < 10 or == 0x30 → event 0x15 "525 Not possible on a mission.", nothing else.
   - campaign-specific requirement dialogs when the planet is the mission target: 0x18 (scanner + tractor beam, DialogueWindow 532), 0x87 (drill, 3213), 0x5b/0x5e (passenger cabins, 3214), 0x69 (Gamma Shield II, 3217), 0x8b (Vossk ship + signature, 3215), 0x8e (spectral filter/plasma collector/15 missiles 3216; free cargo 3218). Not needed for free play.
   - else **planet jump, immediately, no confirmation dialog**: `TargetFollowCamera::setLookAtCam(true)`, `PlayerEgo::dockToPlanet()`, fire-tutorial off, `LevelScript+0x11 = 1`, **`MGame+0x5f = 1` (cinematic: the HUD, radar, crosshair and fire input are hidden/ignored until the level reloads)**.
3. Otherwise the asteroid/mining/docking-point/shooting logic of `mining.md` §3.2.

Hint 584 (first time, campaign mission > 9, no mission, not in autopilot; ChoiceWindow): "To quickly travel to a planet inside the current solar system, target it and tap Fire when locked." Hint 1730 describes the autopilot button, the station lock and the fast-forward button (§4).

---

## 3. Autopilot

### 3.1 State (`PlayerEgo`)

| Field | Meaning |
|---|---|
| `+0x158` | autopilot on (`isAutoPilot`) |
| `+0x15c` | target (`getAutoPilotTarget`): a landmark, a planet target, the asteroid-field waypoint, a route waypoint |
| `+0x160` | target is a route waypoint (`goingToWaypoint`; set when the target has `+0x6e`) |
| `+0x330` | **about to reach**: target < 20000 units (recomputed every frame) |
| `+0x145` | player input locked this frame (docking to a planet/stream, asteroid docking…) |

Queries: `goingToStation` 0xa7822 = target == landmark 0; `goingToStream` 0xa7804 = target == landmark 1; `goingToWormhole` = landmark 3; `goingToPlanet` 0xa77c4 = autopilot on, target ≠ landmark 1, not the station, not a waypoint.

`setAutoPilot(target)` 0xa7754: stores the target, `+0x158 = (target != 0)`, **throttle `+0xbc = 1.0`** and the keyboard throttle axis (`Engine+0x350`) = 0 when turning on; turning off clears `Radar+0x2c` and the banking history.

### 3.2 How it is engaged / cancelled

| Source | Target | HUD event (text) + sound |
|---|---|---|
| Fire with the station locked | landmark 0 | 0xa "Target: Var Hastra Station" + 28 |
| Fire with the jumpgate locked | landmark 1 | 0xc "Target: Jumpgate" + 28 |
| Autopilot menu: "<Name> Station" (key 0x800000) | landmark 0 | 0xa + 28 |
| Autopilot menu: 547 "Jumpgate" (0x400000, only if `currentOrbitHasWarpGate`) | landmark 1 | 0xc + 28 |
| Autopilot menu: 549 "Asteroid field" (0x1000000, always outside the alien orbit) | `Level::getAsteroidWaypoint` | 0xe "Target: Asteroid field" + 28 |
| Autopilot menu: 573 "Waypoint" (0x2000000, if the player route's last waypoint isn't reached) | route waypoint | 0xd "Target: Waypoint" + 28 |
| Autopilot menu: "574 Destination: <station>" (0x200000, if `Level::programmedStation`) | `LevelScript::setAutoPilotToProgrammedStation` 0x160b50 | none |
| Star map closed with a programmed station (not a jump-drive jump) | same | none |
| End of the 7 s arrival sequence with a programmed station ≠ current | same | event 5 "571 Autopilot 38 On" + 28 |
| **Autopilot button while the autopilot (or an asteroid / docking-point / stream approach) runs** | off | **event 6 "571 Autopilot 39 Off" + 29 `Autopilot_Deactivate`** |

`setAutoPilotToProgrammedStation`: programmed station == current → clears it; in this system → **its planet target**; else, in the gate orbit → landmark 1; else → the planet of the system's gate station (none → nothing).

**Autopilot button** (HUD key 0x40, `MGame::OnTouchEnd` 0x1a98d8): only when campaign mission > 1 and ≠ 0x30, not docked to a docking point, not landing/taking off, not mining. With the menu closed: autopilot on → off (event 6); asteroid / docking-point / stream approach → cancel (event 6); else (and mission type ≠ 0xb7) → open the autopilot menu (`Hud::initHudMenu(3)` 0x18e080: the game pauses, `MGame+0x5d/+0xd2/+0xc4 = 1`, title icon 0x4f4, one TouchButton per entry in the order Asteroid field, Station, Jumpgate, Waypoint, Destination, then docking targets). A menu entry or pressing the button again closes the menu and resumes.

Button images (`gof2_interface2_ipad_large.png`, verified): **0x4b0** [1, 515, 109, 109] autopilot off (arrow toward a dot), **0x4b1** [1097, 782, 109, 109] bright = pressed / autopilot on. HD position (`Globals::setCoordsSteer` 0xfcd6c): **(40, 300)** top-left by default (y = `options[0x54]`, the user's HUD-height setting, ≥ 300); it sits in the pill background 0x53f together with the fast-forward button (§4). While the autopilot or a docking procedure runs, `Hud::draw` draws 0x4b1 (lit) there.

Nothing else cancels it: the stick is ignored (not "take over"), fire shoots normally (the landmark lock is gone), reaching the station docks, reaching the gate sphere starts the gate flow, a null/finished waypoint target turns it off (`PlayerEgo::update`).

### 3.3 Flight while the autopilot runs (`PlayerEgo::update` 0xa8ed0, ≈ line 1014 of the dump)

```
if autopilot and target and not inputLocked(+0x145) and no maneuver:
    if waypoint mode: target = route.getWaypoint()
    if target == null or dockedToStream: autopilot off
    else:
        p = target.getPosition()                       // planet targets: camera + billboard offset
        if |p - shipPos| < 20000: aboutToReach(+0x330) = 1
        turn = min(Ship::getHandling() + 2.7, 4.0)     // getHandling = handling/100 + 0.2 per handling mod
        moveToPosition(p, true, turn)                  // 0xa8720
```

`moveToPosition` (same as the asteroid approach, `mining.md` §3.4):

```
to  = normalize(p - pos);  dir = normalize(currentDir)
dir = normalize(dir + (to - dir) * (int)(dt * turn) / 4096)      // time constant ~ 4096/turn ms (1.0-1.5 s)
setDirection(dir, up = (0, 1, 0))                                 // no roll: the ship levels to world up
moveForward(dt * throttle(+0xbc) * speed(+0xb8))                  // speed 2 u/ms, boost if boosting
```

It also stores the signed angle between the old and new direction in a 5-entry history (`+0x290`, `+0x2a4/+0x2a8`) that drives a **visual bank of the model node** (`+0x27c`/`+0x280`, approached at `dt·H/81`, applied as a roll of `−bank·2π/4096`); units not fully resolved, tune visually.

- **Steering input**: ignored (`handleShip`/`roll` are not called). The virtual stick is drawn with a different colour while the autopilot runs (`Hud::draw`, `options[0x11]` branch; the exact tint was not decoded).
- **Throttle**: set to 100 % when engaged; the throttle drag (`MGame::OnTouchMove`) and keys are **not** blocked, so the player can slow down.
- **Boost** (key 2) and **guns** (fire) are **not** blocked.
- **Radar during the autopilot**: landmark, enemy, gas cloud and asteroid locks are suspended; the planet lock keeps running (needed for the automatic planet jump). Brackets, names and distances are still drawn.
- **No "Autopilot" label** and no dedicated distance readout: the only distance is the landmark label of §1.3 (the target is usually near the screen centre, so its bracket/distance is visible), plus the HUD messages.

### 3.4 Arrival at the target

- **Station**: `MGame::dockEvent` 0x1afebc (every frame): `goingToStation` and (station collision volume, or target == landmark 0 and `collidesWithStation` = |pos| < 16000, `PlayerEgo::calcCollision`). Not in alien/empty orbits; campaign missions 0x31–0x36 except at station 74 → event 0x15; a blocking freelance mission (type ∉ {0, 0xb, 0xbd, 0xab, 0xac}) → event 0x15 "Not possible on a mission." instead of docking. Docking = save HP/shield/armor/gamma, `switch_to_target_setting = 0`, module 5 (station). No docking animation (`station_interior.md` §3.5). Note: collision (and thus `collidesWithStation`) is off during the 7 s launch sequence; after it, engaging the autopilot within 16000 units docks immediately.
- **Jumpgate**: inside `Level::collideStream` and `goingToStream` → `dockToStream(true)`; with no programmed station the star map opens in jump mode (autopilot off); with one, ChoiceWindow **"574 Destination: <station>\n421 Travel to this station?"** (default left button), autopilot off; confirming runs the gate jump scene (`space_level_setup.md` §8). Only needed later (inter-system travel).
- **Planet**: the automatic jump of §1.4 when the lock completes (`+0x1a4`). The ship keeps flying toward the billboard until it is in the ±60 px box for the lock time. The planet billboard is always 20000 units from the camera, so once the ship (≈ 1400 units in front of the camera) points at it the target distance drops below 20000 → `aboutToReach` → fast-forward ends (derived, not seen in play).

---

## 3.5 The planet jump (`PlayerEgo::dockToPlanet` 0xadd20)

```
TargetFollowCamera::setLookAtCam(true)       // camera position frozen, keeps looking at the ship
boost timer(+0x138) = 0, boosting(+0x13c) = 1, boost duration(+0xcc) = 10000, boost delay(+0xd0) = 0
speed(+0xb8) = 8.0                           // 4x the base 2 u/ms, independent of the throttle
collision(+0x144) = 0, gun delay reset, +0x38 = 0
dockingToPlanet(+0x1ee) = 1, timer(+0x1f0) = 0
play 5 Jump_to_planets                       // SFX_SPACE/Jump_to_planets_01.ogg
```

Every frame (`PlayerEgo::update`): input locked, `timer += dt`, `moveForward(dt · 8)` along the **current heading, no steering** (24000 units = 1200 Unity m in 3 s). The boost state enlarges the engine particles (boost-driven particle scale); **the boost post effect 0x1400002 (radial blur) and the boost FOV change are explicitly skipped while docking to a planet** (`MGame::OnUpdate`). Gamma/volatile-cargo deaths are skipped. The planet billboards keep following the (frozen) camera, so the planet does not grow. No fade, no streaks, no warp effect.

`TargetFollowCamera::update` in look-at mode (`+0x45`): the position (`+8`) is not updated, target (`+0x14`) = ship position, up = ship up.

`isDockedToPlanet` 0xaddb8 = **timer > 3000**. Then `MGame::OnUpdate` (≈ 0x1ad30e): `Status::departStation(Galaxy::getStation(Radar::getPlanetDockIndex()))`, `Level::setInitStreamOut()` (arrival = travel), save HP/shield/armor/gamma and the secondary weapon index, `switch_to_target_setting = 1` (space music), `SetCurrentApplicationModule(2)` → the level is rebuilt in the target station's orbit behind the loading screen.

Arrival (existing research): position `4 × planet billboard of the previous station` ≈ 80000 units out facing the station (gate orbit: landmark 2) — `space_level_setup.md` §4; 7000 ms look-at fly-in camera at ±(500..999), ±(500..999), 7000 relative to the ship, invulnerable, no collision, speed 2 — `station_interior.md` §3.4; then, if a programmed station remains, "Autopilot On" + the autopilot continues. During that sequence `Hud::drawOrbitInformation` shows the race logo, station name, "<System> 137 System" and the security level (402 Dangerous (255,42,0), 403 Risky (255,108,0), 404 Average (237,237,0), 405 Secure (0,237,0); colours from 0x259ea0) top-left (offsets not decoded).

`PlayerEgo::stopPlanetDock` 0xadd8c (only campaign mission 0x18 without scanner/tractor beam): look-at off, collision on, flag off, `stopBoost`, speed 2.

---

## 4. Fast-forward (HUD key 0x100, `MGame+0x160`)

### 4.1 Button

Same slot as the time extender (equipment sort 0x1a, attr 42/43, clock icons 0x543/0x542). `Hud::draw` ≈ line 3228 of `Hud.c`:

```
if not radio message:
    if (not autopilot and not asteroid approach and not docking-point approach (or landing) and not Hud+0x4c0)
       or Radar+0x54 (hostiles) or aboutToReachAutoTarget:
        if time extender available: draw pill 0x53f + clock 0x543 (0x542 when active)       // normal flight
    else:
        draw pill 0x53f at (x - 8, y); icon 0x541, or 0x540 while key 0x100 is held         // fast-forward
```

Images (`gof2_interface2_ipad_large.png`, verified by cropping): **0x541** [1120, 1295, 109, 109] double arrow, dark = idle; **0x540** [1208, 782, 109, 109] bright = held; **0x53f** [1740, 112, 126, 293] rounded pill background drawn at `(x + layout+0x190 (−8), y)`, covering the fast-forward button (top) and the autopilot button (bottom). Position (`setCoordsSteer`, HD): **x = 40, y = max(0, autopilotY − 180) = 120** by default (autopilot button at (40, 300)); both are top-left positions, touch area = the button size (`Hud+0x474`). Left side of the screen, upper half.

### 4.2 Behaviour

- **Press** (`MGame::OnTouchBegin`, key 0x100): if (autopilot or asteroid approach or docking-point approach) and **no hostiles** (`Radar+0x54 == 0`) and **not `aboutToReachAutoTarget`** → `MGame+0x160 = 5.0`, `TargetFollowCamera::setFastForwardMode(true)`. Otherwise the same key goes to the time extender (or does nothing). Refusals are **silent** (and the button isn't even drawn then).
- **Release**: `MGame::OnTouchEnd` sets `+0x160 = 1.0` and fast-forward mode off on **every** touch end (hold-to-use; lifting any finger ends it), and `PlayerEgo+0x84 = 1` (re-apply the ship's camera handling next frame).
- **Every frame** (`MGame::OnUpdate` 0x1ac778): frame dt = engine elapsed ms clamped to 0..**150**; then if no hostiles, not about to reach and no radio message: **`dt = (int)(dt × +0x160)`**, else `+0x160 = 1`, fast-forward mode off. This scaled dt (`MGame+0x40`) feeds `PlayerEgo::update`, `Level::update` (all ships, asteroids, projectiles), `Radar::draw` (lock timers), the HUD, the LevelScript clock and the mission timers: **the whole game runs 5×**, not just the player.
- **Camera**: when `+0x160 > 1`, `TargetFollowCamera::update` is called **5 times with dt/5** (the unscaled dt) instead of once. `setFastForwardMode` recomputes the camera damping coefficients from `TargetFollowCamera+0x134` (identical code on and off; the flag `+0x4d` only stops `PlayerEgo::update` from re-applying the ship-handling damping while it is set).
- **Ends automatically** when the target comes within 20000 units, when a hostile ship appears, when a radio message starts, or when the autopilot ends. It never starts inside 20000 units.
- **No sound, no screen effect, no speed lines, no HUD text**; only the lit button shows it.

Hint 1730 (English): "...You can accelerate the docking process by tapping the fast forward button in the shape of a double-arrow. This option is only valid if there are no hostile ships (red dots) in the orbit."

---

## 5. HUD during autopilot / travel (summary)

| Element | Autopilot | Manual planet jump (3 s) | Autopilot-triggered planet jump |
|---|---|---|---|
| Crosshair, radar markers, brackets, labels | yes | hidden (`MGame+0x5f`) | yes (planet loop and ring off while docking to the planet) |
| Autopilot button | lit (0x4b1) | hidden | lit |
| Fast-forward button | when allowed (§4) | hidden | not drawn (docking to a planet is not a condition) |
| Top plate | only while something is locked (the landmark lock is cleared in autopilot) | hidden | planet name |
| Messages | "Target: …" / "Autopilot On/Off" (+28/29) | none | none |
| Distance | station/jumpgate label when near the centre: `calcDistance` | none | none |

**`Radar::calcDistance(a, b)`** 0x15827c (verified in the disassembly): `r = (int)sqrt(((a−b)/2)² · (1/4096)) = floor(d/128)`, `M = r·8` (int). `M < 1000` → `"<M>m"`; else `whole = M/1000`, `frac = M % 1000`, digit = first character of `frac` if `frac ≥ 100` else "0" → `"<whole>.<digit>km"`. Examples: 10000 u → "624m", 16000 u → "1.0km", 100000 u → "6.2km". Measured from the **camera** (`Radar+0x238..0x240` = camera matrix translation) to the object. (Correction to `mining.md` Uncertainty 6: the "m" value is also `d/16` in steps of 8, not `d/128`; units are consistent.)

---

## 6. Sounds and texts

| FMOD id | Event / file | When |
|---|---|---|
| 26 | `Target_Lock` | landmark / planet lock completes (not repeated while held) |
| 28 | `Autopilot_Activate` → `Autopilot_Activate_01.ogg` | HUD events 5, 0xa–0xf |
| 29 | `Autopilot_Deactivate` → `Autopilot_Deactivate_01.ogg` | HUD event 6 |
| 5 | `Jump_to_planets` → `Jump_to_planets_01.ogg` | `dockToPlanet` |
| 0x45f / 0x460 | (time extender, not mapped) | not fast-forward |

| Text id | English | Use |
|---|---|---|
| 136 | Station | station label suffix |
| 133 | Tech level | station label line 2 ("Tech level: 5") |
| 547 / 545 / 415 | Jumpgate / Wormhole / Void | landmark names |
| 546 | Target | "Target: X" (events 0xa–0xf) |
| 549 / 573 | Asteroid field / Waypoint | menu entries, events 0xe / 0xd |
| 571 + 38 / 39 | Autopilot On / Off | events 5 / 6 |
| 553 | Autopilot activated | event 7 (not used in these paths) |
| 525 | Not possible on a mission. | event 0x15 |
| 574 + 421 | Destination: X / Travel to this station? | gate ChoiceWindow, menu "Destination: X" |
| 584 | To quickly travel to a planet inside the current solar system, target it and tap Fire when locked. | hint |
| 1730 | Tap the autopilot button … fast forward button … no hostile ships (red dots) … | hint (campaign) |
| 137, 402–405 | System; Dangerous/Risky/Average/Secure | orbit information during the arrival |

---

## 7. Unity build recipe

1. **Targets**: give the orbit builder a list of lockables: station (landmark 0, at the origin), visible jumpgate (landmark 1), and one planet target per *other* station of the system whose world position is `camera + billboard offset` (the Backdrop quads: 1000 m from the camera in Unity).
2. **Lock** (plain C#, `GoF2LandmarkLock`): every frame, project to the screen in the 1920×1080 reference space. Station/gate: on screen, inside ±320 px of the centre and ±120 px of the crosshair, nothing else locked, not in autopilot → timer; planets: on screen, ±60 px of the crosshair, not the current station's planet → timer (also during autopilot). Lock time = scanner attr 29 or 8000 ms, strict `>`. Sound 26 on the transition. Priority: landmark > planet > enemy > asteroid (and the asteroid lock of `GoF2Mining` must yield).
3. **Draw** (flight HUD): ring 0x456 frame `23·t/lockTime` at the crosshair; bracket 0x4f2 + name + "Tech level: N" + distance for the station, bracket + name + distance for the gate (only near the centre; gate icon 0x453 elsewhere, clamped to the 657×491 ellipse when off screen; no station marker); planets: name only while in the box, gate icon / mission markers next to them; top plate 0x4c4 with name (+ race icon for landmarks); arrow 0x536 on the fire button (and a "Autopilot" / "Travel" action prompt for keyboard/controller).
4. **Action** (fire / action key): station or gate locked → autopilot on + "Target: …" + sound 28; planet locked → planet jump (skip the campaign checks; keep "Not possible on a mission." for blocking missions once missions exist).
5. **Autopilot** (plain C#): `dir = normalize(dir + (to − dir)·(int)(dt·min(H+2.7, 4))/4096)`, up = world up, speed 2 u/ms × throttle (throttle reset to 1 on engage, still adjustable), stick ignored, boost/guns allowed, `aboutToReach = d < 20000`. Station: dock when |pos| < 16000 (or inside its collision volume) → station scene. Autopilot button / key toggles it off ("Autopilot Off" + 29) or opens a small destination menu (Asteroid field, Station, Jumpgate, Destination).
6. **Planet jump**: freeze the chase camera position and make it look at the ship; ship straight ahead at 8 u/ms, boosted exhaust, no radial blur/FOV change; sound 5; hide the HUD (manual path); after 3000 ms set `GoF2Session.StationIndex = target`, mark arrival-by-travel, save hull/shield/armor, reload `Space` (arrival per `space_level_setup.md` §4 + the 7 s look-at fly-in).
7. **Fast-forward**: a hold button (touch), a held key/controller button, visible only when allowed; multiply the simulation dt by 5 (clamp the raw dt to 150 ms first), i.e. `Time.timeScale = 5` or a game-dt multiplier that also covers AI/projectiles/asteroids; step the chase camera in 5 sub-steps; stop at < 20000 units, hostiles, radio, autopilot end, or release. No sound/effect.

---

## 8. Functions

| Function | Address | Role |
|---|---|---|
| `Radar::Radar` | 0x1545e0 | images, name table, lock boxes, scanner lock time |
| `Radar::update(Vector)` / `elipsoidIntersect` | 0x1552f8 / 0x1553dc | projection, off-screen clamp |
| `Radar::draw` | 0x1554fc | landmark / planet / enemy / asteroid markers and locks, hostile counter |
| `Radar::calcDistance` | 0x15827c | distance string |
| `Radar::getPlanetDockIndex` | 0x158524 | station index of the planet in the box |
| `Radar::drawCurrentLock` | 0x158548 | top plate |
| `Radar::stationLocked` | 0x158d2a | landmark lock with `+0x6d` |
| `StarSystem::getPlanetTargets` / `orbitPlanetIndex` | 0x15db34 / static | planet targets (built in `StarSystem::StarSystem` 0x15c200) |
| `Status::getPlanetNames` / `setStation` | 0xb9924 / 0xb6300 | planet names = station names |
| `PlayerEgo::setAutoPilot` / `getAutoPilotTarget` / `isAutoPilot` | 0xa7754 / 0xa77be / 0xa77fe | autopilot state |
| `PlayerEgo::goingToPlanet` / `goingToStream` / `goingToStation` / `goingToWaypoint` / `goingToWormhole` | 0xa77c4 / 0xa7804 / 0xa7822 / 0xa784e / 0xa7854 | target kind |
| `PlayerEgo::aboutToReachAutoTarget` | 0xadc76 | `+0x330` (< 20000) |
| `PlayerEgo::moveToPosition` | 0xa8720 | autopilot steering |
| `PlayerEgo::update` | 0xa8ed0 | autopilot, planet-dock movement, timers |
| `PlayerEgo::dockToPlanet` / `stopPlanetDock` / `isDockingToPlanet` / `isDockedToPlanet` | 0xadd20 / 0xadd8c / 0xab9a8 / 0xaddb8 | planet jump |
| `PlayerEgo::dockToStream` / `isDockingToStream` / `isDockedToStream` | 0xaddcc / 0xab9ae / 0xadd18 | jumpgate |
| `PlayerEgo::forceBoost` / `boost` / `stopBoost` | 0xa6de2 / 0xa6d84 / 0xa6d18 | boost state (dockToPlanet sets the same fields as `forceBoost`) |
| `MGame::OnTouchBegin` | 0x1a838c | fire action, fast-forward press |
| `MGame::OnTouchEnd` | 0x1a98d8 | fast-forward release, autopilot button, autopilot menu, star-map close |
| `MGame::OnUpdate` | 0x1ac778 | dt clamp + ×5, planet-jump completion, camera sub-steps, boost post effect |
| `MGame::OnRender2D` | 0x1b10bc | HUD / radar / plate draw order, cinematic mode |
| `MGame::dockEvent` | 0x1afebc | station / gate arrival |
| `LevelScript::setAutoPilotToProgrammedStation` | 0x160b50 | programmed-station routing |
| `LevelScript::process` (end of launch sequence) | 0x160d50 | "Autopilot On", continue to the programmed station |
| `Hud::hudEvent` | 0x18f5a0 | messages + sounds 28/29 |
| `Hud::initHudMenu` | 0x18e080 | autopilot menu (type 3) |
| `Hud::draw` | 0x190d08 | autopilot / fast-forward buttons, fire arrow |
| `Hud::touchedElement` / `touchBegin` | 0x194054 / 0x1944f0 | key bits (0x40 autopilot, 0x100 fast-forward, 0x10 fire) |
| `Hud::init` | 0x18cf20 | image ids, button positions |
| `Hud::drawOrbitInformation` | 0x193a3c | arrival orbit info |
| `Globals::setCoordsSteer` / `setCoordsFire` | 0xfcd6c / 0xfd0b8 | HD button positions |
| `TargetFollowCamera::setLookAtCam` / `setFastForwardMode` / `update` | 0x187906 / 0x187978 / – | camera modes |
| `StarMap::OnTouchEnd` | 0xdb69c | sets `Level::programmedStation` (in-flight star map, mode 3) |

---

## Uncertainties

1. **Screen metrics**: all 2D numbers are the HD/iPadLarge branch; button y positions depend on the user's HUD-height option (`options[0x54]`, default 300). A remake should keep the layout relations, not the absolute pixels.
2. **Station marker**: `Radar::draw` draws nothing for the station outside the ±320 px centre square (only the gate and the wormhole get off-centre icons). If the original shows a station marker elsewhere (the HUD's own radar/minimap in `Hud::draw` was not read), it isn't in this function.
3. **Visual bank during the autopilot** (`+0x27c/+0x280`, 5-sample history): the units and the exact filter were not resolved.
4. **Stick tint during the autopilot**: `Hud::draw` switches the colour (`SetColor`) for the stick image 0x4c1 when autopilot/docking; the colour value (probably half transparent) was not decoded.
5. **Fast-forward camera damping**: `setFastForwardMode` runs identical code for on/off; the only effect found is that `PlayerEgo::update` doesn't re-apply the ship-handling damping while the flag is set. Net visual difference unverified.
6. **`aboutToReach` during planet autopilot**: derived from the billboard geometry (always 20000 units from the camera); not observed in play.
7. **Hostile counter** (`Radar+0x1b8`): counts active, non-dying ships with `KIPlayer+0x38 == 0` and `Player+0x5c` set (plus a kind-10 special case); `+0x38`'s meaning (probably "not a wingman / not hidden") is assumed.
8. **Arrow on the fire button for a planet lock** is drawn from `Radar+0x14`; during the autopilot-triggered jump the lock completes and `dockToPlanet` runs in the same frame, so the arrow appears at most for that frame.
9. **Campaign gates** (planets only after campaign mission 1, fire-jump only from mission 10, autopilot menu from mission 2): the remake has no campaign; treat as unlocked.
10. `Status::getPlanetNames` returns empty strings when `Status+0x1e8 == 0` (flag not traced); normally the station names.
11. `drawOrbitInformation` layout offsets (`layout+0x21c..0x228`) come from a vector-select block that wasn't evaluated.
