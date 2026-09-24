# Asteroid mining: drill, lock, approach, MiningGame minigame, ore and cores

How the original lets the player mine asteroids, decoded from the native code (`libgof2hdaa.so`, Android HD). Game units and milliseconds unless noted (Unity: 1 unit = 0.05 m). Addresses use the Ghidra image base 0x10000. 2D values are **screen pixels of the Android HD build** (`retinaDisplay = iPad = iPadLarge = 1`, `iPadHD = n9 = 0`, see `shop.md` §1.2), i.e. roughly a 1920×1080 canvas.

Related research (not repeated here): asteroid field generation, ore choice per system, asteroid quality, spin, death, crate drops → `space_props.md` §1; asteroid hits, explosions, sound 21 → `weapons.md` §7; shop, prices, cargo rules, item attributes → `shop.md`; FMOD ids → `fmod_event_ids.txt`.

Helper: `Reference/tools/mining/mining_tables.py` dumps `LAYER_SPEEDS` / `LAYER_DIAMETERS` from the binary, prints the drill factors and the perfect-run ore per drill and class, and (`crops DIR`) cuts every image used below.

---

## 0. TL;DR for Unity

1. **Needs a drill** (item category/sort 19 "Mining laser", items 86–90). Without one, an asteroid can never be locked ("No drill installed."); shooting asteroids only drops the 4 %/20 % crates of `space_props.md`.
2. **Lock**: keep an asteroid (on screen, nothing else targeted) inside the crosshair box (±w/16 px) for `lockTime − 200` ms: 7800 ms without scanner, 3800 / 2800 / 1600 / 1600 ms with Telta Quickscan / Ecoscan / Hiroto Proscan / Ultrascan (attr 29). Lock sound 26 `Target_Lock`, a 24-frame ring fills around the crosshair, the top plate shows the ore name + class letter A–D, and an **arrow appears on the fire button**.
3. **Press fire** → "Target: Asteroid" + sound 28; player input is locked, throttle forced to full, the ship autopilots to the asteroid (needs ≥ 1 t free cargo, else "Cargo hold is full."). Fire again or the menu button cancels ("Autopilot Off" + sound 29).
4. Last `2000` units before `dockDist = asteroidScale·2500`: exhaust off, sound 2 `Mining_Landing`, the chase camera **freezes in place**, the ship model pitches ~80° (probably nose up, belly to the rock; sign unverified) with an accelerating rotation. At `dockDist` the ship stops, the asteroid stops spinning, and the minigame starts (drill loop sound 1, engine sound paused).
5. **MiningGame** (2D overlay, the 3D scene keeps rendering): concentric discs = rock layers; the number of layers = asteroid quality (A 7, B 6, C 5, D 4), 6 s each. Keep the drill cursor inside the current (shrinking) disc with the stick/tilt while it drifts randomly. Inside: ore accumulates (`yield·((layer+1)/7·2.35+0.15)` t/s) and the layer timer runs. Outside: nothing accrues and a **2.5 s energy budget for the whole session** drains (never refills) → 0 = "Mining failed.", no ore.
6. **Result**: all layers done (win; class A also gives 1 core) or fire pressed (stop early, keeps the ore) → ore (capped to free cargo, halved in hardcore when not won) goes to the cargo, HUD "Nt <ore>", then the asteroid **explodes** like a destroyed one (no crate), camera and controls return.
7. Ores are normal commodities (shop.md). The mining plant in station 103's orbit converts 30 t ore → 1 core (100 in hardcore).

---

## 1. Prerequisites: drills and scanners

### 1.1 Drill items (sort 19 "Mining laser")

Only the **first** mounted item of sort 0x13 counts (`Ship::getFirstEquipmentOfSort(ship, 0x13)`), read in `MiningGame::MiningGame` 0x143994 and `Radar::Radar` 0x1545e0.

| Item | Name | attr 32 (text 164 "Handling") | attr 33 (text 144 "Yield") | steadiness `+0x2c` = a32/100·1.5+0.3 | yield `+0x28` = a33/100 |
|---|---|---|---|---|---|
| 86 | IMT Extract 1.3 | 30 | 60 | 0.75 | 0.60 |
| 87 | IMT Extract 2.7 | 40 | 60 | 0.90 | 0.60 |
| 88 | K'yuul (attr 60 = 1, Vossk only) | 50 | 75 | 1.05 | 0.75 |
| 89 | IMT Extract 4.0X | 60 | 80 | 1.20 | 0.80 |
| 90 | Gunant's Drill (blueprint) | 100 | 100 | 1.80 | 1.00 |

- **attr 32 (0x20)** divides the random drift of the drill cursor (§4.4): higher = steadier drill.
- **attr 33 (0x21)** multiplies the ore rate (§4.5).
- attr 61 = 8 on items 86–89 is the icon/"home" attribute handled in `shop.md`; no other drill attributes are read.

### 1.2 Without a drill

- `Radar+0x1a8 = (drill != 0)` (Radar ctor). When an asteroid lock would complete without it, `Hud::hudEvent(0x14)` → text 541 **"No drill installed."** and no lock (`Radar::draw` 0x1554fc, lock block ≈ 0x157b00). So the approach/minigame can't start.
- Campaign mission 0x87 (135) refuses its planet target without a drill: ChoiceWindow 3213 "You must have a mining drill installed in order to start the mission." (`MGame::OnTouchBegin` 0x1a838c). That mission also sets every asteroid's ore to Titanium 0x9b (`Level::createCampaignMission` case 0x87, `PlayerAsteroid::setAsteroidIndex`).
- If a MiningGame were ever created without a drill, `+0x28` (yield) is 0 and `+0x2c` is uninitialised (unreachable in practice).

### 1.3 Scanners (sort 17) — lock time and class-A marker

`Radar::Radar`: `Radar+0x1b4` = attr 29 of the first sort-0x11 item, else **8000**. `Radar+0x1a6` = attr 30 == 1, `Radar+0x1a5` = attr 31 == 1.

| Item | Name | attr 29 lock time | effective asteroid lock (timer > value − 200) | attr 30 |
|---|---|---|---|---|
| – | no scanner | 8000 | 7800 ms | – |
| 81 | Telta Quickscan | 4000 | 3800 ms | 0 |
| 82 | Telta Ecoscan | 3000 | 2800 ms | 0 |
| 83 | Hiroto Proscan | 1800 | 1600 ms | 0 |
| 84 | Hiroto Ultrascan | 1800 | 1600 ms | **1** |

attr 30 (Ultrascan only): while the player is inside the asteroid field's bounding sphere (`Level::isInAsteroidCenterRange`, radius 100000 around the field centre, `space_props.md` §1), `Radar::draw` draws the class sprite frame 0 ("A", image 0x44e) at the screen position of every **class-A** asteroid (`getQualityFrameIndex() == 0`). Matches the Ultrascan description ("displays asteroids with a core directly in the radar").

---

## 2. Which asteroids, which ore

Everything about the field (count, positions, ore choice per system, scale, quality) is in `space_props.md` §1. Mining-relevant fields of `PlayerAsteroid` (ctor 0xf68e4):

| Field | Meaning |
|---|---|
| `+0x124` asteroid index = **ore item** (154–164, or 217 Novanium) | chosen per asteroid by `Galaxy::getAsteroidProbabilities`; alien orbit always 164 Void Crystals; campaign 0x87 → 155 Titanium |
| `+0x14c` quality 4..7 | 7 = A, 6 = B, 5 = C, 4 = D (`getQualityString` 0xf6cfc; "E" unreachable). `getQualityFrameIndex` = 7 − quality (frame in image 0x44e) |
| `+0x138` minable = quality > 3 | **always true**: every asteroid can be mined |
| `+0x134` scale | docking distance = `scale·2500` |
| `+0x48` loot flag | 1 at spawn; `stopMining` clears it so a mined asteroid drops no crate |
| `+0x148` rotation enabled | cleared on arrival, set again by `dockToAsteroid(null)` |
| `Player+0x40` radius | set to **0** when the minigame starts (asteroid can no longer be hit / collided) |

Quality from scale (`space_props.md`): scale < 0.4 → D, < 0.7 → C, < 0.92 → B, else 50 % A / 50 % D–B; the 2–9 big asteroids (scale 1.2–2.19) always take the last branch. The ore amount is **not stored per asteroid**: it comes only from the minigame (layers = quality, §4). The core item = ore + 11 (Novanium 217 → 218).

Ore / core items (`items.json`, all tech 1 / 3, sold as commodities):

| Ore | idx | Core | idx |
|---|---|---|---|
| Gold | 154 | Golden Core | 165 |
| Titanium | 155 | Titanium Core | 166 |
| Iron | 156 | Iron Core | 167 |
| Orichalzine | 157 | Orichalzin Core | 168 |
| Pyresium | 158 | Pyresium Core | 169 |
| Sodil | 159 | Sodil Core | 170 |
| Doxtrite | 160 | Doxtrit Core | 171 |
| Cesogen | 161 | Cesogen Core | 172 |
| Perrius | 162 | Perrius Core | 173 |
| Hypanium | 163 | Hypanium Core | 174 |
| Void Crystals | 164 | Void Essence | 175 |
| Novanium (Supernova) | 217 | Novanium Core | 218 |

Category 23 "Ore" / 24 "Ore core". Text: item name = 1274 + idx.

**No respawn** within a visit: a mined or destroyed asteroid is gone (state 4, inactive). The field is rebuilt on every level load (`Level::createAsteroids`), so leaving and re-entering the orbit gives a fresh field (count seeded per station, everything else random). `Level::asteroidDied` / `getAsteroidsLeft` (`Level+0x128`) count down but nothing reads the counter.

---

## 3. Starting to mine in flight

### 3.1 Radar lock (`Radar::draw` 0x1554fc, asteroid loop ≈ 0x1576xx–0x157c6c)

Per frame, only when not in autopilot, turret mode or a docking procedure (`PlayerEgo::isInDockingProcedure` = asteroid docking or docking point) and **no other target** (enemy candidate/lock, landmark, planet) exists:

1. For every live asteroid: project to the screen (`Radar::update(pos)`); skip if off screen. Candidate if its screen position is inside the **lock box** around `PlayerEgo::crosshairPos`: `|sx − cx| < R`, `|sy − cy| < R` with `R = Radar+0x124 = w/16` (120 px at 1920). Up to 4 candidates.
2. The candidate **nearest in 3D** to the player becomes `Radar+0x10`. A new candidate resets the lock timer `Radar+0x198`.
3. Timer `+= dt`. From 501 ms the lock ring sprite (image 0x456, 24 frames 80×80, centred on the crosshair) shows frame `23·(t−500)/(lockTime−500)`.
4. When `t > lockTime − 200`: no drill → HUD event 0x14 (1.2); else **lock**: `Radar+0xc` (locked asteroid) = candidate, sound **26 `Target_Lock`** (only if FMOD slot 0 isn't playing and it wasn't locked the previous frame, `Radar+0x214`). The ring shows its last frame (full gold ring).
5. The lock is re-evaluated each frame: if the asteroid leaves the box (or something else becomes the target) the timer and the lock reset.

While locked, `Radar::drawCurrentLock` 0x158548 draws the target plate **0x4c4** (408×57) at `(w/2 − 204, layout+0xb0 = 6)`, the ore name (text 1274 + ore) centred at `y = 6 + layout+0xc4 (14)`, and left of it the class letter: sprite **0x44e** (5 frames 36×29: A gold, B, C, D, E blue), frame `7 − quality`, at `x = textX − layout+0x2c − 36`, `y = 6 + layout+0xc0 (13)`.

`Hud::draw` 0x190d08 draws the **arrow icon 0x536** (134×128) centred on the fire button when not docking/mining/in turret mode and a planet, landmark, docking point or **locked asteroid** exists (`Radar+0x14 / +0x24 / +0xc`). Hint 1725: "Aim at an asteroid until the target is locked. Once you see an arrow on your fire button, tap it to approach the asteroid and start the docking process. To abort the docking process, tap the fire button once again." Campaign mission 2 also shows 618 "Aim at an asteroid and press Fire when locked." on the HUD (`Hud::draw`, blinking 2000 ms).

### 3.2 Fire button = action (`MGame::OnTouchBegin` 0x1a838c, key bit 0x10 → 0x1a85e6)

On Android the HUD fire button is the action button. When pressed and no landmark/planet target applies:

| State | Action |
|---|---|
| mining (`isMining`) | **stop mining**: `Status+0x124 = 0`, `PlayerEgo::stopMining` (§5) |
| asteroid locked, not docking | free cargo < 1 → HUD event 0x1b = 322 **"Cargo hold is full."**, nothing else. Else HUD event 0xb = 546 "Target" + ": " + 550 "Asteroid" + sound **28 `Autopilot_Activate`**, `PlayerEgo::dockToAsteroid(lockedAsteroid)`, `Hud::releaseAllKeys` |
| docking to an asteroid | HUD event 6 = 571 "Autopilot" + " " + 39 "Off" + sound **29 `Autopilot_Deactivate`**, `dockToAsteroid(…)` (toggles off) |

The HUD menu button also cancels an asteroid approach (`MGame::OnTouchEnd` 0x1a98d8 → `dockToAsteroid`, event 6). Boost, secondary weapons, the HUD menu and the wingman menu are blocked while mining. OnTouchEnd also has an alien-orbit branch that cancels an asteroid approach (`inAlienOrbit && isDockingToAsteroid → dockToAsteroid(null)`; which button leads there was not traced).

### 3.3 `PlayerEgo::dockToAsteroid(asteroid, radar)` 0xab9b4

- **Start** (not docking, asteroid given): `+0x1dc = 0` (pitch accumulator), `+0x1c0 = 1` (docking flag), `+0x1bc = asteroid`, `+0x1d8 = (int)(scale·2500)` (dock distance), `+0x145 = 1` (**player steering disabled**), `+0x1c4 = 0` (state: approaching).
- **Stop** (already docking; the argument is ignored): asteroid rotation on, flags cleared, `+0x1c8 = 0`, **chase camera active again**, gun delay reset, MiningGame deleted, `Radar::unlockAsteroid`, state 0, exhaust visible.
- `PlayerEgo::update` 0xa8ed0: while `+0x1c0`, input stays locked; if the asteroid is null/dying/dead → `dockToAsteroid(null)` (cancel), else `approachAsteroid` every frame.

### 3.4 Approach state machine (`PlayerEgo::approachAsteroid` 0xaba90)

Nothing happens while the asteroid is dying. `d` = distance ship → asteroid centre, `D` = `+0x1d8`.

**State 0 (approaching)**
- Leaves turret mode.
- `d ≥ D`: `moveToPosition(asteroidPos, true, turn)` 0xa8720 with `turn = min(handling + 2.7, 4.0)` (`Ship::getHandling` = handling/100 + 0.2 per handling mod): `dir = normalize(dir + (toTarget − dir)·(dt·turn)/4096)`, up (0,1,0), `moveForward(dt · throttle · speed)`. `MGame::OnUpdate` forces the throttle to 1.0 (full) every frame while docking/docked. If `d < 20000`: `+0x330` ("about to reach target") → the fast-forward key (Hud key 0x100, `MGame+0x160 = 5`) is refused from here on.
- `d < D + 2000` (final approach):
  - first frame: exhaust particles off, sound **2 `Mining_Landing`**, boost timer `+0x138 = +0xcc − +0xcc/6` (probably ends a running boost; unverified), **`TargetFollowCamera::setActive(false)`** (the camera stops updating and stays where it is, looking at the scene from there), captures the model node's up vector (`+0x1c8`), `+0x2f5 = 1`.
  - every frame: if the angle between the ship model's forward (`PlayerEgo+4` node) and the captured up vector is > 0.2 rad and `+0x1dc > −1024`: `+0x1dc −= 0.35·dt`, and the model node's local matrix is post-multiplied by `Rx(+0x1dc/65536·2π)`. The rotation is **cumulative** (a new, growing angle every frame), so the nose pitches up ever faster until it points within 0.2 rad of the old up direction (~78.5° pitch). Then `+0x1d4 = 1` (ready).
- `d < D` and ready → asteroid spin off (`setRotationEnabled(false)`), **state 1 (docked)**. The ship no longer moves (moveToPosition only runs while `d ≥ D`).

**State 1 (docked)**
- While `+0x1dc > −1024`: `+0x1dc −= dt/2` (a short settle delay, ≤ ~2 s).
- Then, if no MiningGame yet: `+0x39b = 0`, `+0x2f5 = 0`, `hints[0x37] = 0`, `new MiningGame(quality, oreIndex, hud)`, asteroid `Player radius = 0`, sound **1 `Mining_Drill`** (loop), **engine sound paused** (`FModSound::pause(PlayerEgo+0x1c)`).
- Else `MiningGame::update(dt)`; when it returns 0 (game over):
  - not lost and ore > 0 → `stopMining` (normal win).
  - lost → `+0x39b = 1` (`lostMiningGame`), `Status+0x124 = 0`, `stopMining`, HUD event 8 = 539 **"Mining failed."**
- While running, if the asteroid starts dying / dies → `Status+0x124 = 0`, `stopMining` (keeps the ore so far), "Mining failed.".

`MGame::OnUpdate`: while docked, a non-standard camera mode is switched back to the standard chase camera (`switchCamera(0)`); mouse/free-look deltas are zeroed while docking. `PlayerEgo::setDockingCamera` 0xa68c0 (offsets (0, 150, 500)) has **no callers** and is not part of mining.

Note: `+0x1d4` is only reset in the PlayerEgo constructor, so from the second asteroid on the ship can reach state 1 before the pitch-up finishes (the rotation then just stops where it is). The model node is reset by `PlayerEgo::update` as soon as `+0x1c0` is cleared.

---

## 4. The MiningGame minigame (`MiningGame`, 0xd4 bytes)

### 4.1 Fields

| Offset | Meaning |
|---|---|
| `+0x00 / +0x04` | player input velocity x / y (`left/right/up/down(v)`: `3·v`) |
| `+0x08 / +0x0c` | drift velocity x / y |
| `+0x10 / +0x14` | drill position (float px), starts at the centre |
| `+0x18` | quality (layer count), `+0x7c` same |
| `+0x1c` | ore item index (`getAsteroidType` 0x143dda returns it) |
| `+0x20` | **time outside the ring, whole session** (ms, lose at > 2500) |
| `+0x24` | ore (float t); `getOreAmount` 0x143dc6 = `(int)` |
| `+0x28 / +0x2c` | drill yield / steadiness (§1.1) |
| `+0x34` | height of 0x4e4; `+0x40` = width(0x4e7)/2 + 5 = 45; `+0x44` = width(0x4e5)/2 = 54 |
| `+0x48 / +0x4c` | energy bar image 0x4e8 width/height (388 / 14) |
| `+0x50 / +0x54` | bar x = w/2 − 194, bar y = `layout+0xd8` = 74 |
| `+0x58 / +0x5c` | centre = (w/2, h/2 + `layout+0xd0` (30)) |
| `+0x60` | core image (quality 7 only): 0x522 for Void Crystals (ore 0xa4), else 0x523 |
| `+0x64` | ore-text alpha 0..1 |
| `+0x68` | drill sprite frame accumulator |
| `+0x6c` | drift re-roll timer |
| `+0x70` | 2500 (written, never read) |
| `+0x74` | time in the current layer (only while inside) |
| `+0x78` | current layer 0..quality−1 |
| `+0x80` | quality == 7 (has core) |
| `+0x81 / +0x82 / +0x83` | won / lost / got core |
| `+0x84` | campaign mission > 4 (no tutorial assist) |
| `+0x88 / +0x8c / +0x90` | MarqueeImages: depth strip 0x4e4, data strips 0x4eb / 0x4ec |
| `+0x94` | drill Sprite 0x4e6 (10 frames 66×66, ref pixel centre) |
| `+0x98…+0xc4` | images (§4.7) |
| `+0xc8` | `layout+0xd4` = 40 (data-strip window width) |
| `+0xcc` | 0..2000 ms blink timer for text 616 |
| `+0xd0` | Hud* |

### 4.2 Constructor `MiningGame(quality, oreIndex, hud)` 0x143994

Centre and drill at `(w/2, h/2 + 30)`; drift, input, ore, timers 0; layer 0; loads all images (§4.7); marquee speeds 20 px/s (0x4eb), 32 px/s (0x4ec), depth strip `layout+0xe0 (2) · LAYER_SPEEDS[0]` = 10 px/s; `+0x64 = 1`.

### 4.3 Tables (`mining_tables.py`)

`LAYER_SPEEDS` 0x26ad2c (float[7]) = **5, 8, 12, 17, 23, 30, 38** (per layer: drill animation speed, depth-strip speed, FMOD parameter).

`LAYER_DIAMETERS` 0x26ad48 (int[7][7], row = 7 − quality; the decompiler also shows it as `LISTITEMWINDOW_UNITS − 0x1c·quality`). The value × `layout+0xe8` (2.0) is the drawn disc diameter, so on HD **the value is the disc radius in px**:

| Class | Layers | Radius per layer (px, HD) |
|---|---|---|
| A (7) | 7 | 250, 210, 170, 140, 110, 80, 50 |
| B (6) | 6 | 250, 210, 170, 140, 110, 80 |
| C (5) | 5 | 250, 200, 150, 100, 70 |
| D (4) | 4 | 250, 170, 120, 80 |

(Rows 4–6 for qualities 3–1 are unused.) Hint 621 only mentions classes A, B and C, but D exists and is common (all small asteroids with scale < 0.4).

### 4.4 `MiningGame::update(dt)` 0x143e28 — returns 1 while running, 0 when over

```
blink = (blink + dt); if blink >= 2000: blink = 0
wasInside = isInCurrentLayer()
driftTimer += dt
if driftTimer > 2500:                          // first re-roll after 2.5 s, then every 1..2000 ms (avg 1 s)
    driftTimer = rnd(2000) + 500
    driftX = ±(rnd(7) + 5) / 10 / steadiness   // sign: rnd(2) == 0 -> +; each axis rolled separately
    driftY = ±(rnd(7) + 5) / 10 / steadiness
    if hasCore and layer == quality - 1: driftX *= 0.3; driftY *= 0.3     // the core layer is calmer
if campaignMission <= 4 and not isInCurrentLayer():                         // tutorial assist
    driftX = (centreX - x) * 0.03; driftY = (centreY - y) * 0.03           // spring back to the centre
x += dt * (inputX + driftX) / layout+0xe4       // layout+0xe4 = 10 on HD (20 on non-retina)
y += dt * (inputY + driftY) / layout+0xe4
update data marquees
FMOD event 1 parameter 0 = (LAYER_SPEEDS[layer] - 5) / 33 * 3           // 0, 0.27, 0.64, 1.09, 1.64, 2.27, 3.0
if not isInCurrentLayer():
    if wasInside: stop sound 1, play sound 3 Mining_Drill_Broken
    outside += dt
    if outside > 2500: outside = 2500; ore = 0; lost = true; Status+0x124 = 0; return 0
    textAlpha = 1
else:
    if not wasInside: play sound 1, stop sound 3
    frameAcc += dt/1000 * layout+0xe0 (2) * LAYER_SPEEDS[layer] * 3
    if frameAcc >= 1: drillSprite.nextFrame(); frameAcc = 0            // max one frame per update
    depthMarquee.update(dt)
    old = ore
    ore += dt * yield * ((layer + 1) / 7 * 2.35 + 0.15) / 1000
    textAlpha = (int)ore > (int)old ? dt/500 : min(textAlpha + dt/500, 1)   // flashes in at every new ton
    layerTime += dt
    if layerTime > 6000:
        layerTime = 0; layer += 1
        if layer >= quality:
            won = true; gotCore = (quality == 7)
            if not Achievements::hasMedal(0x26, 1):
                Status+0x124 += 1                                          // consecutive full minings
                p = (int)(Status+0x124 / 10 * 100)
                if p % 10 == 0 and p >= 30: Hud::hudEventMedal(0x26)       // progress message
                if Status+0x124 >= 10: Status+0x128 = 1                    // medal earned
            return 0
        depthMarquee.speed = layout+0xe0 * LAYER_SPEEDS[layer]
return 1
```

`isInCurrentLayer` 0x144364: `|drill − centre| < LAYER_DIAMETERS[7−quality][layer] / 2 · layout+0xe8`.

Consequences:
- Duration: `quality × 6 s` of **in-ring** time (24–42 s); time outside pauses the layer timer and the ore.
- The energy budget (2500 ms outside, total) never refills. The drill position is not clamped to the screen.
- Drift speed (HD): `(0.5..1.1)/steadiness · 100` px/s → IMT 1.3: 67–147 px/s, Gunant: 28–61 px/s. Max player speed 300 px/s (`3·1²/10` px/ms).
- **Input persists**: `+0x00/+0x04` are only written when `left/right/up/down` are called. The input code (4.6) only calls them for a non-zero axis, so releasing the virtual stick (axis exactly 0) leaves the drill moving at the last input velocity. That's how the original behaves (probably unintended).

### 4.5 Ore amount

Rate while inside layer `L` (0-based): `yield · ((L+1)/7 · 2.35 + 0.15)` t/s = yield × 0.486, 0.821, 1.157, 1.493, 1.829, 2.164, 2.500. Per full 6-s layer: yield × 2.91, 4.93, 6.94, 8.96, 10.97, 12.99, 15.0. Perfect run (never outside) = yield × 23.74 (D), 34.71 (C), 47.70 (B), 62.70 (A):

| Drill | D | C | B | A (+1 core) |
|---|---|---|---|---|
| IMT Extract 1.3 / 2.7 (0.60) | 14 | 20 | 28 | 37 |
| K'yuul (0.75) | 17 | 26 | 35 | 47 |
| IMT Extract 4.0X (0.80) | 19 | 27 | 38 | 50 |
| Gunant's Drill (1.00) | 23 | 34 | 47 | 62 |

(simulated at 16 ms frames; frame length changes it by ±1). Stopping early keeps `(int)ore`. The core needs the whole run.

### 4.6 Controls (touch phone/tablet; no keyboard in the Android build)

`MGame::OnUpdate` 0x1ac778 calls every frame (except campaign mission 0x30), and `PlayerEgo::left/right/up/down(dt, v)` 0xacf98 / 0xacd48 / 0xad468 / 0xad1e4 forward to the MiningGame while it exists:

- **Virtual stick** (`options[0x11]` set): `ax = Hud::getAnalogX()` = (knob − centre)/radius ∈ [−1, 1]. `ax < 0` → `left(ax²)` → `+0x00 = −3·ax²`; `ax > 0` → `right(ax²)` → `+3·ax²`. Same for Y with screen-down positive (stick up → drill up). The **invert-Y option is applied twice** (MGame swaps up/down, PlayerEgo negates again), so it has no effect on the drill.
- **Accelerometer** (`options[0x11]` clear, `MGame::handleAccelerometer` 0x1a7c1c, summarised): X = accel.y·2.5 clamped to ±1, squared, left/right by sign; Y uses the two calibrated tilt values (accel.x − `options+0x1c`, folded when accel.z > 0, and accel.z − `options+0x20`), takes the one with the larger magnitude ×3, clamps to ±1, squares it, up/down by sign. Invert also cancels out.
- **Stop**: tap the fire button (3.2). Text 616 "Press the fire button to stop mining and receive ore." is drawn during the first campaign missions.

Suggested remake mapping: stick/WASD/mouse delta → `v` (signed, squared like the original), fire key → stop. Decide whether to keep the "input persists at 0" quirk (4.4).

### 4.7 Rendering (`MiningGame::render2D` 0x14440c, called from `PlayerEgo::draw` 0xae3a0 instead of the crosshair)

All positions HD px; `C` = centre (w/2, h/2 + 30), `P` = drill. Atlas = `gof2_interface_iphone4.png` (the iPad-large variant of `gof2_interface.png`, see `shop.md` §1.2); rects verified by cropping.

| Image | Rect [x, y, w, h] | Use |
|---|---|---|
| 0x4e2 | [1, 1900, 40, 40] | disc quadrant, even layers, small (drawn size ≤ 80) |
| 0x4dd | [1, 379, 140, 140] | disc quadrant, even layers, medium (80 < size < 400) |
| 0x4de | [639, 934, 250, 250] | disc quadrant, even layers, large (size ≥ 400) |
| 0x4e1 | [543, 884, 40, 40] | disc quadrant, odd layers, small |
| 0x4df | [337, 1720, 140, 140] | disc quadrant, odd layers, medium |
| 0x4e0 | [893, 935, 250, 250] | disc quadrant, odd layers, large |
| 0x522 | [181, 1607, 89, 66] | core, Void Crystals (crystal cluster) |
| 0x523 | [545, 739, 80, 79] | core, other ores (glowing orb in rock) |
| 0x4e7 | [1934, 660, 81, 81] | drill cursor ring |
| 0x4e6 | [639, 855, 660, 66] | drill bit animation, 10 frames 66×66 |
| 0x4e3 | [651, 261, 408, 34] | energy bar frame |
| 0x4e8 | [614, 1634, 388, 14] | energy bar fill (orange) |
| 0x4ed | [375, 160, 27, 8] | "Energy" label |
| 0x4eb | [1452, 1, 194, 11] | scrolling red fake-data strip |
| 0x4ec | [162, 1, 194, 12] | scrolling orange fake-data strip |
| 0x4e4 | [1706, 147, 103, 18] | scrolling blue data strip next to the drill |
| 0x4e5 | [337, 2002, 108, 45] | box behind the ore amount |

The disc quadrants are the **top-left quarter of a filled disc** (dark navy for even layers, lighter blue for odd ones, thin light rim).

Draw order:
1. **Rock layers**, from the current layer to the last (big to small, so smaller discs on top; finished layers vanish): `S = LAYER_DIAMETERS·2`, image by parity and `S` (thresholds `layout+0xec` = 80, `layout+0xf4` = 400; on HD only medium/large occur). Four `DrawImage2D(img, C, S/2, S/2, anchor 0x11, pivot, flip)` calls: pivot 0x22 flip 0 (top-left quarter), 0x21 flip 1 (top-right, mirrored X), 0x12 flip 2 (bottom-left, mirrored Y), 0x11 flip 3 (bottom-right). (Anchor bits: low nibble 1 left / 4 centre / 2 right, high 0x10 top / 0x40 centre / 0x20 bottom.)
2. Core image centred at `C` (quality 7 only, native size).
3. Drill ring 0x4e7 centred at `P`, then the drill sprite frame centred at `P`.
4. Energy bar: frame 0x4e3 at `(barX − 10, barY − 10)` (`layout+0xfc` = 10); fill 0x4e8 region `(0, 0, 388·(2500 − outside)/2500, 14)` at `(barX, barY)` = (w/2 − 194, 74). When `outside ≥ 834` ms the fill is tinted `(255, 255·p, 255·p)` with `p = |sin(playingTime_ms · 10)|` (`Layout::getPulseValue(10)` 0xe74fc) — a fast red/white flicker.
5. "Energy" label 0x4ed, horizontally centred on `C.x`, bottom at `barY − 3` (pivot 0x24).
6. Data strips (MarqueeImage 0x18bec4: texture offset += speed·dt, wraps, shown through a window): 0x4eb at `(barX, barY + 14 + 5)` and 0x4ec at `(barX + 388 − 40, barY + 19)`, window 40 px.
7. Depth strip 0x4e4 at `(P.x + 45, P.y − 18)`, window 100 px (width(0x4e5) − 8), speed `2·LAYER_SPEEDS[layer]` px/s, advancing only while inside. Box 0x4e5 at `(P.x + 45 − 10, P.y − layout+0x100 (4))`.
8. Ore text `"<(int)ore>t"` (e.g. "12t") centred on the box: `x = P.x + 45 + 54 − 10 − textWidth/2`, `y = P.y + layout+0x104 (5)`. Colour **(255, 42, 0)** when `(int)ore > free cargo`, else white; alpha `255·textAlpha` (fades in over 500 ms after every new ton).
9. Campaign mission < 5: text 616 in white, centred at `y = barY + layout+0x70 (90)`, alpha triangle wave `a = blink/1000·255`, `255 − a` in the second second (the byte wrap makes it ≈ 510 − a).

HUD while mining: `Radar::draw` (markers, lock box) and the HUD message queue are skipped; the crosshair isn't drawn; the rest of `Hud::draw` (touch stick, fire button) stays, so the fire button remains tappable.

### 4.8 Sounds

| When | FMOD id | Event / file |
|---|---|---|
| final approach begins | 2 | `Mining_Landing` → SFX_SPACE/Mining_Landing_01.ogg |
| minigame starts; re-entering the ring | 1 (loop) | `Mining_Drill` → Mining_Drill_Add_1/Add_2 (+ Slow_1, Switch in the folder); parameter 0 = 0…3 by layer (4.4) |
| leaving the ring | 3 (stops 1) | `Mining_Drill_Broken` → Mining_Drill_Broken.ogg |
| end (any) | stop 1 and 3, resume engine sound | |
| lock | 26 | `Target_Lock` |
| approach on / off | 28 / 29 | `Autopilot_Activate` / `Autopilot_Deactivate` |
| asteroid explodes afterwards | 21 | `Destruction_Asteroid` (weapons.md) |

### 4.9 Texts

| Id | English | Where |
|---|---|---|
| 541 | No drill installed. | lock without drill (HUD event 0x14) |
| 322 | Cargo hold is full. | fire with full cargo (event 0x1b); end of mining when full (`catchCargo`) |
| 546 + 550 | Target: Asteroid | approach starts (event 0xb) |
| 571 + 39 | Autopilot Off | approach cancelled (event 6) |
| 539 | Mining failed. | lost / asteroid died (event 8) |
| 616 | Press the fire button to stop mining and receive ore. | minigame, campaign mission < 5 |
| 617 | Ore mining failed due to drill being off-target for too long. … | ChoiceWindow after a lost game in campaign mission 2 (`hints[0x37]`) |
| 618 | Aim at an asteroid and press Fire when locked. | HUD, campaign mission 2 |
| 620 | Ore Mining — Try to keep the drill within the rock layers … | ChoiceWindow the first time mining runs (`hints[0x11]`) |
| 621 | Asteroids — three classes A, B, C … only class A contain cores … | first mining after campaign mission 3 (`hints[0x12]`) |
| 636 | Your cargo hold is full. Return to a station and sell some items. | hint when `Hud::cargoFull` after mission 6 (`hints[0x14]`) |
| 1725 | Aim at an asteroid until the target is locked. … | campaign mission 2 when damaged or after 40 s (`MGame+0x1dd`) |
| 1274 + idx | ore / core names | lock plate, HUD cargo messages |
| 560 / 561 | Ore mined / Cores mined | status window stats (`StatusWindow::draw`) |

The ChoiceWindow hints pause the game (`MGame+0x5d`).

---

## 5. Result (`PlayerEgo::stopMining` 0xade94)

```
ore  = asteroid.oreIndex; core = ore + 11 (217 -> 218)
free = ship.freeSpace; n = mining.getOreAmount()
if hardcore and not won: n = (int)(n * 0.5)
n = min(n, free)
if free < 1:
    catchCargo(ore, 0, full=true)                                    // "Cargo hold is full."
else:
    if gotCore:                                                       // 1 t, before the ore
        cargo += Item(core, 1); catchCargo(core, 1)                   // "1t Golden Core"
        Status+0xa4 += 1; if core != 218: coreFlags[core - 165] = 1   // Status+0x98
        n = min(n, ship.freeSpace)
    if n > 0:
        cargo += Item(ore, n); catchCargo(ore, n, mined=true)         // "12t Gold"
        Status+0xa0 += n; if ore != 217: oreFlags[ore - 154] = 1      // Status+0x94
    if ship.freeSpace <= 0: catchCargo(ore, n, full=true)             // "Cargo hold is full."
exhaust visible
asteroid+0x48 = 0 (no crate); asteroid HP = -1; Status+0xd8 -= 1   // cancels the "asteroids destroyed" +1 of its death
delete MiningGame; dockToAsteroid(null)                             // spin on, camera active, radar unlock, input back
stop sounds 1 and 3; resume engine sound
```

- Next `PlayerAsteroid::update`: HP ≤ 0 → death as in `space_props.md` (explosion type = asteroid type + 2, scaled, sound 21, `Level::asteroidDied`, `Status+0xd8 += 1`) but **no crate** (loot flag cleared). The asteroid mesh is hidden during the explosion and the asteroid becomes inactive.
- `Hud::catchCargo(item, n, full, …)` 0x19027c: `full` → text 322 (and `Hud+0x1d5` = cargo full, which triggers hint 636); else, n > 0 → queue message `"<n>t <name(1274+item)>"` with the item icon (same messages as tractor-beamed crates).
- Returning to flight: the camera resumes chasing (damped catch-up from where it froze), the ship's model node snaps back to normal, the throttle stays at full, the player has control again. No station/level change.
- A lost game goes through the same path with `n = 0` (only the "full" message is possible) and adds "Mining failed.".

**Stats and medals** (`Achievements`, thresholds at 0x259860 = int[medal][3], `getValue(m, level)` = entry `level − 1`, levels 1/2/3):

| Medal | Name (text 0x5e3 + id) | Rule, thresholds for level 1 / 2 / 3 |
|---|---|---|
| 2 | 1509 "Geologist" | different ores mined (`Status+0x94` flags, 11 incl. Void Crystals, not Novanium): 11 / 8 / 5 |
| 3 | 1510 "Adv. Geologist" | different cores mined (`Status+0x98` flags): 11 / 8 / 5 |
| 6 | 1513 "Miner" | tons of ore mined (`Status+0xa0`): 1000 / 500 / 100 |
| 7 | 1514 "Adv. Miner" | cores mined (`Status+0xa4`): 25 / 10 / 3 |
| 0x26 | 1545 "Ore Athlete" | 10 **consecutive full** minings (`Status+0x124`, reset by a stop, a loss or the asteroid dying); single level |

---

## 6. Ore economy

- Ores (cat 23) and cores (cat 24) are ordinary commodities: bought and sold at the same price, priced by `Status::calcCargoPrices` from `minPrice/maxPrice/lowestPriceSystem/highestPriceSystem` (`shop.md` §4.1), sellable at every station. Nothing mining-specific in the shop code.
- Stock generation (`shop.md` §4.3): Void Crystals 164, Void Essence 175, Novanium 217/218 are never stocked; **hardcore mode stocks no ore or cores**; ores near their cheapest system are stocked ×(up to 20).
- **Mining plant** (station 103's orbit, `sn_station_mining_plant`, campaign mission > 0x54, `space_props.md`): docked to its docking point (`PlayerEgo::isDockedToMiningPlant` 0xadcb8: docking point docked, state 1, no side mission, not alien orbit, station 103) → ChoiceWindow 290 "Do you want to convert all your ore to cores? #t of ore will be transformed into 1t of cores. You currently have:" + list of cargo ores ("Nt <name>") or 286 "Nothing" (`MGame::OnUpdate`). Yes (`MGame::OnTouchEnd`): for each ore 154–164 and 217, while the cargo has ≥ **30 t** (**100 t** in hardcore): remove them, add 1 core (ore + 11; 217 → 218). Result 291 "The following cores have been transferred to your cargo hold:" + list, or 292 "You do not have enough ore in your cargo hold.".
- Crates from shot asteroids: `space_props.md` §1 (4 % class A → 1 core, 20 % others → 1–3 t ore).
- Side missions such as 801 "I need help with mining #P in #S. I am at least #Q tons short. A mining drill is required for this mission." exist (Generator/Mission, not decoded here).

---

## 7. Unity build recipe

1. **Data**: drill = first equipped item with `categoryId == 19`; `steadiness = a32/100·1.5 + 0.3`, `yield = a33/100`. Scanner lock time = attr 29 of the first cat-17 item, else 8000; Ultrascan attr 30 → class-A markers. Asteroid (`Target`-like component) needs `oreIndex`, `quality`, `scale`, `lootable`, `spinEnabled`.
2. **Lock** (`GoF2AsteroidLock`, plain C#): only when no other target and not docking; screen-space box ±w/16 around the crosshair, nearest in 3D, timer ≥ lockTime − 200 → locked (sound 26), no drill → "No drill installed.". Show the 24-frame ring (0x456) from 500 ms, the top plate (0x4c4) with ore name + class letter (0x44e), and the arrow (0x536) on the fire button / a "Mine" prompt for keyboard/controller.
3. **Approach** (`GoF2AsteroidDocking`): fire → cargo check → lock input, full throttle, steer with `dir = normalize(dir + (to − dir)·dt·min(H+2.7, 4)/4096)` at `speed · throttle`; at `d < scale·2500 + 2000` hide the exhaust, play sound 2, freeze the chase camera, pitch the ship model up (cumulative `Rx(a)`, `a −= 0.35·dt/65536·2π` per ms) until its nose is within 0.2 rad of its old up vector; at `d < scale·2500` stop, stop the asteroid spin, wait until the accumulator reaches −1024 (−dt/2 per ms), start the minigame, pause the engine sound, set the asteroid's hit radius to 0. Fire / menu cancels.
4. **Minigame** (`MiningGame`, plain C#, unit-testable): fields and `update(dt)` exactly as 4.4 with `UnityEngine.Random` for `rnd(n)`; work in a 1920×1080 reference space (radius values = px) and scale to the panel. Returns ore (int), won, lost, gotCore.
5. **View** (UI Toolkit overlay or a Canvas with the atlas crops): 4.7 layout and draw order; discs as 4 mirrored quarter images (or one generated full-disc sprite per image), core, drill ring + 10-frame bit animation, energy bar with flicker, marquee strips, ore label with red-when-overflow and fade-in. Hide radar markers/crosshair/HUD messages while mining.
6. **Input**: `v` from stick/tilt/keys → `left/right/up/down` semantics (±3·v², screen-down = +y); fire = stop. Optionally reproduce "input persists when the axis is 0".
7. **Audio**: event 1 loop (crossfade/pitch by parameter 0…3, mapping unknown), 3 on leaving the ring, 2 on landing; stop both at the end.
8. **Result**: 5 — cargo add with free-space cap, core first, hardcore halving, HUD messages, stats/medal counters, then kill the asteroid without loot (explosion + sound 21), unfreeze the camera, restore the model, give control back.
9. **Mining plant** conversion dialog (6) when docking points exist.

---

## 8. Functions

| Function | Address | Role |
|---|---|---|
| `MiningGame::MiningGame(int quality, int ore, Hud*)` | 0x143994 | drill factors, images, marquees |
| `MiningGame::update(int dt)` | 0x143e28 | drift, movement, ore, layers, win/lose, medal 0x26 |
| `MiningGame::isInCurrentLayer` | 0x144364 | ring hit test |
| `MiningGame::render2D` | 0x14440c | overlay |
| `MiningGame::up/down/left/right(float)` | 0x143dde / 0x143df0 / 0x143e02 / 0x143e14 | input velocity = 3·v |
| `MiningGame::gameWon/gameLost/getOreAmount/gotCore/getAsteroidType` | 0x143dba / 0x143dc0 / 0x143dc6 / 0x143dd4 / 0x143dda | getters |
| `PlayerEgo::dockToAsteroid(KIPlayer*, Radar*)` | 0xab9b4 | start / cancel approach |
| `PlayerEgo::approachAsteroid(Hud*, Radar*)` | 0xaba90 | approach + docked state machine, minigame driver |
| `PlayerEgo::stopMining` | 0xade94 | cargo, messages, asteroid kill, undock |
| `PlayerEgo::isMining / getCurrentMiningAmount / lostMiningGame` | 0xa6cbc / 0xa6e00 / 0xae0b8 | queries |
| `PlayerEgo::isDockedToAsteroid / isDockingToAsteroid / isInDockingProcedure` | 0xadc8c / 0xadca2 / 0xad7d4 | state queries |
| `PlayerEgo::moveToPosition(Vector, bool, float)` | 0xa8720 | autopilot steering |
| `PlayerEgo::setExhaustVisible` | 0xa637c | engine particles |
| `PlayerEgo::left/right/up/down(int, float)` | 0xacf98 / 0xacd48 / 0xad468 / 0xad1e4 | input → MiningGame |
| `PlayerEgo::isDockedToMiningPlant` | 0xadcb8 | ore → core plant |
| `PlayerEgo::setDockingCamera` | 0xa68c0 | unused (no callers) |
| `MGame::OnTouchBegin / OnTouchEnd / OnUpdate / OnRender2D` | 0x1a838c / 0x1a98d8 / 0x1ac778 / 0x1b10bc | fire action, cancel, input, mining-plant dialog, hints |
| `MGame::handleAccelerometer` | 0x1a7c1c | tilt input |
| `Radar::Radar / draw / drawCurrentLock / getLockedAsteroid / unlockAsteroid` | 0x1545e0 / 0x1554fc / 0x158548 / 0x158d1c / 0x158d20 | lock, plate |
| `Radar::calcDistance` | 0x15827c | distance string (shown at the crosshair while docking) |
| `Hud::hudEvent / catchCargo / getAnalogX / getAnalogY` | 0x18f5a0 / 0x19027c / 0x194002 / 0x19402a | messages, stick |
| `Layout::getPulseValue` | 0xe74fc | `|sin(playingTime·k)|` |
| `MarqueeImage::MarqueeImage / update / draw` | 0x18bec4 / 0x18bf1c / 0x18bf78 | scrolling strips |
| `PlayerAsteroid::getQuality / getQualityFrameIndex / getQualityString / isMinable / getScaling / setRotationEnabled / setAsteroidIndex` | 0xf6ce4 / 0xf6cf0 / 0xf6cfc / 0xf6cde / 0xf6cea / 0xf6db0 / 0xf6cc0 | asteroid data |
| `Achievements::getValue / hasMedal` | 0x182610 / 0x182600 | medal thresholds (table 0x259860) |
| `Level::createCampaignMission` (case 0x87) | 0xc3370 | Titanium override |

Data: `LAYER_SPEEDS` 0x26ad2c, `LAYER_DIAMETERS` 0x26ad48, asteroid meshes 0x251fb0, medal table 0x259860. Layout (HD retina branch of `Layout::Layout` 0xe2a00): `+0xd0` 30, `+0xd4` 40, `+0xd8` 74, `+0xdc` 20.0, `+0xe0` 2.0, `+0xe4` 10.0, `+0xe8` 2.0, `+0xec` 80, `+0xf0` 160, `+0xf4` 400, `+0xf8` 800, `+0xfc` 10, `+0x100` 4, `+0x104` 5, `+0x70` 90 (iPadLarge), `+0xb0` 6, `+0xb4` 29, `+0xb8` 36, `+0xc0` 13, `+0xc4` 14.

---

## Uncertainties

1. **Screen metrics**: all 2D numbers are from the HD retina `Layout` branch and the iPad-large atlas; a real device may have a different `w/h` (the layout is not scaled to it: rings are fixed-size pixels around the screen centre). Non-retina values: `+0xe4` = 20, `+0xe8` = 1, `+0xd0` = 15, `+0xd8` = 37.
2. **Pitch-up direction/look**: the rotation is `Rx(+0x1dc·2π/65536)` post-multiplied onto the model node (`PlayerEgo+4`) each frame, stopping at 0.2 rad from the captured up vector; the sign (nose up vs. down) and whether `getDirection/getUpVector` on that node are world-space were not verified visually. Frame-rate dependent in the original.
3. **`+0x138 = +0xcc − +0xcc/6`** on final approach: assumed to cut an active boost short.
4. **Fast-forward** during the approach (`MGame+0x160 = 5`, key 0x100, refused within 20000 units) was only read from OnTouchBegin, not traced into the time step.
5. **FMOD parameter 0** of `Mining_Drill` (0…3 by layer): how the FEV maps it to Add_1/Add_2/Slow_1/Switch is unknown (FEV not parsed). Suggest pitch/crossfade.
6. **Lock persistence during the approach**: the asteroid loop in `Radar::draw` is skipped while docking; whether `Radar+0xc` and the lock plate stay visible during the approach was not fully traced (the approach itself only uses `PlayerEgo+0x1bc`). The docking-time distance string (`Radar::calcDistance`) shows `|Δ|/128` "m" and switches to "km" at 125 "m" using `m·8/1000` (inconsistent units in the original).
7. `getPulseValue(10)` uses `Status::getPlayingTime()` (ms, the same clock as the 250 ms double-tap test) × 10 as radians → effectively random per-frame flicker; if playing time were in another unit it would be a slower pulse.
8. The "input persists when the stick axis is exactly 0" behaviour is decoded (no reset anywhere in `MiningGame`), but it may be masked on devices where the analog value rarely hits exactly 0.
9. Medal names assume `text 0x5e3 + medal id`; progress messages (`Hud::hudEventMedal`) not decoded.
10. Mining side missions (text 801) and the Generator side of ore missions were not decoded.
