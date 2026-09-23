# Station interior: hangar, bar (Space Lounge), menu flow, docking and launch

Scope: how the original builds and presents the docked-station screens, for a Unity "Station" scene.
Read together with (not repeated here):
- `tools/asset_conversion/assemblies/rules/assemblies_scenes_notes.md`: mesh ids of rooms/props/visitors, turret-on-ship rules.
- `research/space_level_setup.md` §6 (StarSystem lights), §7 (camera), §8 (docking triggers).
- `research/fmod_event_ids.txt`, `research/mainmenu_notes.md`.

Conventions: positions are GAME units, Unity = `(x, y, -z) * 0.05` m. Angles in radians unless noted. Time in ms.
Engine facts used below (verified in this pass):
- Matrices are row-major, column vectors, translation in m[3]/m[7]/m[11]. `Matrix::operator*=` (0x8a78c) is `this = this * other`.
- `MatrixSetRotation(M, x, y, z)` (3 args, 0x8b09c) = Rx·Ry·Rz. `MatrixSetRotation(M, x, y, z, order)` (0x8b17c) with **order 2 = Ry(y)·Rx(x)·Rz(z)** (yaw, then pitch, then roll; decoded from the case-2 matrix terms). Unity's `Quaternion.Euler` uses the same Ry·Rx·Rz composition.
- **Cameras look along their local −Z** (OpenGL). Verified: every hangar/bar camera below points at its room contents only with −Z.
- `MatrixGetLookAt(eye, target, up)` (0x8b73c): position = eye, local +Z = normalize(eye − target) (points back at the eye).
- `CameraSetPerspective(cam, fov, near, far)`: engine stores tan(fov/2) and aspect·tan(fov/2) (0x7a594), so fov is the full **vertical** angle (most likely; landscape).
- `FogSetParameter(mode, start, end, density, rgba)`: colour is 0xRRGGBBAA (0x871f8).
- `EaseInOut(a, b)` (0x7aa34…): value = a + (b−a)·(sin(φ)·0.5+0.5), φ starts at 3π/2, `Increase(d)` adds d/65536·2π (capped at 5π/2). A full a→b transit therefore takes **32768 units of d** (= 32.8 s when d = dt in ms).
- `EaseInOutMatrix(A, B, dur)` (0x77910): t runs 0.75→1.25, `Increase(dt)` adds dt·0.5/dur, blend = sin(2πt)·0.5+0.5; rotation by quaternion blend, translation lerp. So a `dur` = 3000 ms sine ease-in/out.

**Converting camera rotations to Unity:** mirroring z turns a game rotation Ry(a)·Rx(b)·Rz(c) into Ry(−a)·Rx(−b)·Rz(c), and the game's −Z view becomes Unity's +Z view. So a game camera with order-2 rotation (rx, ry, rz) = **Unity `Quaternion.Euler(−rx°, −ry°, rz°)`**; position via the usual rule.
**Meshes** keep the project rule (CLAUDE.md / space_level_setup §0): game yaw θ → Unity yaw π − θ, so game (0, π, 0) = Unity identity.

---

## 1. Hangar (`CutScene(0x17)` → `Level(0x17)`)

### 1.1 Build (Level::createScene 0xc2910, branch 0x17)
Hangar index `h` (used for every hangar table): station 101 → 8 (battlestation), station 100 → 7 (deep science), else system race 0..3. (`CutScene::process` uses 10 for station 101; harmless.)

Objects, in the Level's enemies list in this order:
1. **Player ship** `createShip(shipRace, 0, shipIdx, null, isPlayer=false)` → NPC mesh group (`_engine_add`, not the player engine glow), `setPosition(0, Y[shipIdx], 0)`, `removeTrail`, `setExhaustVisible(false)`, `setToSleep`, `setAlwaysFriend`. `CutScene::replacePlayerShip` 0xa53b4 swaps the group (`getShipGroup(idx, race, false)`) and re-applies y from the identical table `DAT_002520f0`.
2. **Room statics** `UNK_00253e48[h][0..3]` (−1 = none), `PlayerStatic(-1, geom, 0,0,0)` + `setRotation(0, π, 0)` → **Unity identity**. Races 0/2/3 add child props `DAT_00251fd0[h] + k`, k < `UNK_00251fc0[h]` (11/–/10/12) to each static (see scenes notes).
3. **Parked ships** (below).

Room mesh ids (resources.json):

| h | room | slot 0 | slot 1 | slot 2 | slot 3 |
|---|---|---|---|---|---|
| 0 Terran | hangar_terran | 14376 hull | 14302 `_add` | 14301 `_alpha` | – |
| 1 Vossk | hangar_vossk | 14377 hull | 14304 `_anim_add` | – | – |
| 2 Nivelian | hangar_nivelian | 14378 | 14308 `_add` | 14307 `_alpha` | – |
| 3 Midorian | hangar_midorian | 14379 | 14310 `_add` | 14264 `_alpha` | – |
| 7 Deep Science | v_hangar_deep_science | 14362 | 14358 `_emissive` | 14360 `_anim_add` | 14359 `_alpha` |
| 8 Battlestation | v_hangar_battlestation | 14354 | 14355 `_emissive` | 14357 `_add` | 14356 `_alpha` |

### 1.2 Ship y offset `DAT_00253d48[shipIdx]` (= `DAT_002520f0`), game units (Unity m = ×0.05)
Ship pivots are centred, so this lifts each ship onto the hangar floor. It is also added to the parked-ship slot y.

| idx | y | idx | y | idx | y | idx | y |
|---|---|---|---|---|---|---|---|
| 0 Betty | 160 | 16 Kinzer | 170 | 32 Wasp | 140 | 48 Amboss | 440 |
| 1 Teneta | 150 | 17 Ward | 170 | 33 Furious | 160 | 49 Scimitar | 340 |
| 2 Hiro | 220 | 18 Hatsuyuki | 190 | 34 Razor 6 | 180 | 50 – | 170 |
| 3 Badger | 310 | 19 Nuyang II | 460 | 35 Night Owl | 150 | 51 Rhino | 470 |
| 4 Dace | 160 | 20 Cicero | 170 | 36 Cormorant | 310 | 52 Gryphon | 170 |
| 5 Inflict | 180 | 21 Aegir | 210 | 37 Cronus | 390 | 53 – | 170 |
| 6 Hector | 140 | 22 Groza | 140 | 38 Typhon | 480 | 54 Na'srrk | 170 |
| 7 Anaan | 170 | 23 Azov | 170 | 39 S'Kanarr | 200 | 55 Groza Mk II | 170 |
| 8 VoidX | 170 | 24 Velasco | 160 | 40 Nemesis | 300 | 56 Berger Cross Special | 200 |
| 9 H'Soc | 110 | 25 Tyrion | 190 | 41 K'Suukk | 300 | 57 Kinzer RS | 170 |
| 10 Phantom | 250 | 26 Hera | 170 | 42 Vol Noor | 170 | 58 Phantom XT | 250 |
| 11 Hernstein | 205 | 27 Taipan | 240 | 43 Wraith | 200 | 59 Teneta R.E.D. | 150 |
| 12 Type 43 | 240 | 28 Veteran | 220 | 44 Specter | 170 | 60 Darkzov | 170 |
| 13 – | 250 | 29 Mantis | 280 | 45 Bloodstar | 370 | 61 Ghost | 250 |
| 14 – (battleship) | 250 | 30 Berger CrossXT | 200 | 46 Blue Fyre | 370 | 62 Dark Angel | 270 |
| 15 – (freighter) | 250 | 31 Salvähn | 200 | 47 Gator Custom | 300 | 63 N'Tirrk | 170 |

### 1.3 Player-ship turntable (ModStation)
- Ship rotation = `(0, CutScene+4, 0)` rewritten every frame by `CutScene::process` 0xa49f4 (3-arg MatrixSetRotation, translation kept).
- `CutScene+4 = ModStation+0xe0 / 120` (**1 rad per 120 px** of horizontal drag). Initial `+0xe0` (ModStation::OnInitialize state 0x3c): **270 → yaw 2.25 rad**, Nivelian **−200 → −1.667 rad**. Unity yaw = π − yaw: **51.1°** (Nivelian **275.5°**).
- Drag (OnTouchMove 0xea340): only for x > menu-panel width (`+0xa4`) and between header and footer; `+0xe0 += dx`.
- Fling (OnTouchEnd): release velocity v = last dx if |dx| > 3 px; each frame `v *= 0.9 · min(dt·0.05, 1)`, `+0xe0 = int(+0xe0 + v)` while |v| ≥ 1 (OnUpdate ~0xee… , frame-rate dependent: ×0.9 per 20 ms frame).

### 1.4 Parked ships
- Count = `nextInt(UNK_00253ee8[h] + 1)` → Terran 0..2, Vossk 0..9, Nivelian 0..2, Midorian 0..3, Deep Science 0..3, Battlestation 0 (never any).
- Ship choice per slot: 70 % `Globals::getRandomEnemyFighter(h)` (0xf9034); 30 % race = `nextInt(4)`, and of those 30 % race 8 (pirate). Station 100 overrides: `nextInt(3)` → 37 Cronus / 38 Typhon / 40 Nemesis. Station 108 (home base) with `Status+0x114 == 3`: its own stored ships (`Status+0x14c` station ship list), count = min(stored, max).
- `getRandomEnemyFighter(race)`: race 1 (Vossk) → 9 H'Soc (after DLC1 won: 60 % 9, 25 % 41 K'Suukk, 15 % 39 S'Kanarr); 9 → 8 VoidX; 10 → 44 Specter; races 4..8 map to 8; otherwise random index < 37 whose race `DAT_00254990[i]` matches, excluding 0, 8, 9, 10, 13, 14, 15:
  - Terran: 1 Teneta, 5 Inflict, 7 Anaan, 17 Ward, 22 Groza, 26 Hera, 27 Taipan, 28 Veteran, 33 Furious, 34 Razor 6, 36 Cormorant
  - Nivelian: 4 Dace, 12 Type 43, 16 Kinzer, 18 Hatsuyuki, 21 Aegir, 31 Salvähn, 35 Night Owl
  - Midorian: 3 Badger, 6 Hector, 19 Nuyang II, 20 Cicero, 30 Berger CrossXT
  - Pirate (8): 2 Hiro, 11 Hernstein, 23 Azov, 24 Velasco, 25 Tyrion, 29 Mantis, 32 Wasp
- Created with `createShip(race 0, …, isPlayer=false)`, `setAlwaysFriend`, `setToSleep`, `setExhaustVisible(false)`.
- Slot = `nextInt(count)`, re-rolled (max 100 tries) while taken. Position = `(sx, sy + Y[ship], sz)`. Rotation = `setRotation(0, nextInt(300)/100, 0)` (yaw 0..2.99 rad, verified at 0xc31f0) → Unity yaw 180° − θ°.

Slot tables (12-byte int triples):

| h | table | slot | game (x, y, z) | Unity m (before + Y[ship]·0.05) |
|---|---|---|---|---|
| 0 Terran | UNK_00253f10 | 0 | (0, 0, 2891) | (0, 0, −144.55) |
| | | 1 | (0, 0, 5781) | (0, 0, −289.05) |
| 1 Vossk | DAT_00253f28 | 0 | (−3715, 0, 661) | (−185.75, 0, −33.05) |
| | | 1 | (−6983, 36, 2548) | (−349.15, 1.80, −127.40) |
| | | 2 | (−9408, 36, 5438) | (−470.40, 1.80, −271.90) |
| | | 3 | (−9408, 36, 16301) | (−470.40, 1.80, −815.05) |
| | | 4 | (−6983, 36, 19191) | (−349.15, 1.80, −959.55) |
| | | 5 | (−3715, 36, 21078) | (−185.75, 1.80, −1053.90) |
| | | 6 | (−9408, 5359, 16301) | (−470.40, 267.95, −815.05) |
| | | 7 | (−6983, 5359, 19191) | (−349.15, 267.95, −959.55) |
| | | 8 | (−3715, 5359, 21078) | (−185.75, 267.95, −1053.90) |
| 2 Nivelian | DAT_00253fe8 | 0 | (4096, 0, 0) | (204.80, 0, 0) |
| | | 1 | (4096, 0, 4096) | (204.80, 0, −204.80) |
| 3 Midorian | DAT_00253f94 | 0 | (−4096, 0, 0) | (−204.80, 0, 0) |
| | | 1 | (0, 0, 4096) | (0, 0, −204.80) |
| | | 2 | (−4096, 0, 4096) | (−204.80, 0, −204.80) |
| 7 Deep Science | UNK_00253fc4 | 0 | (−1961, 0, 8512) | (−98.05, 0, −425.60) |
| | | 1 | (−1961, 0, 5562) | (−98.05, 0, −278.10) |
| | | 2 | (−1961, 0, 2610) | (−98.05, 0, −130.50) |
| 8 Battlestation | DAT_00253fb8 | 0 | (4096, 0, 0) | (204.80, 0, 0) (unused, count 0) |

### 1.5 Hangar camera
Creation (`CutScene::initialize` 0xa4074, branch 0x17):
- Camera `+0x70`, **fov 0.8 rad (45.8° vertical), near 200 (10 m), far 100000 (5000 m)**. `CutScene::resetCamera` 0xa3f4c re-applies the same values.
- A transform `+0x78` is created at the player-ship position **(0, Y[ship], 0)** and the camera is made its child. So every camera position below is **relative to (0, Y[shipAtEntry], 0)**. (The parent is not moved by `replacePlayerShip`.)
- The initial local matrix set here, rot (0, π/8, 0) + pos (300, 700, 3000), is immediately replaced by ModStation.

Placement (`ModStation::ModStation` 0xe7bf0 and `OnInitialize` 0xe8080, state 0x14):
- position = `DAT_002546c4[h]` (iPad: `DAT_0025464c[h]`), int (x, y, z);
- rotation = order 2, (x = `UNK_0025473c[h]`, y = `UNK_0025478c[h]` (iPad `UNK_00254764[h]`), z = **−0.03** (0xbcf5c28f)). `ModStation::resetIdleCamForHangar` 0xec06c (on return from the Lounge / Hangar window) sets the same but z = 0 and always the phone yaw table.

Phone table (use this one):

| h | game pos (rel. ship pivot) | rot (x, y, z) | Unity pos m (rel.) | Unity Euler ° | Unity view dir |
|---|---|---|---|---|---|
| 0 Terran | (1076, 900, −2273) | (−0.27, −3.36, −0.03) | (53.80, 45.00, 113.65) | (15.47, 192.51, −1.72) | (−0.209, −0.267, −0.941) |
| 1 Vossk | (1787, 1086, −1632) | (−0.30, −3.75, −0.03) | (89.35, 54.30, 81.60) | (17.19, 214.86, −1.72) | (−0.546, −0.296, −0.784) |
| 2 Nivelian | (−2247, 1010, −1845) | (−0.18, −2.05, −0.03) | (−112.35, 50.50, 92.25) | (10.31, 117.46, −1.72) | (0.873, −0.179, −0.454) |
| 3 Midorian | (1800, 800, −1778) | (−0.20, 2.57, −0.03) | (90.00, 40.00, 88.90) | (11.46, −147.25, −1.72) | (−0.530, −0.199, −0.824) |
| 7 Deep Science | (1200, 800, −2678) | (−0.20, 3.00, −0.03) | (60.00, 40.00, 133.90) | (11.46, −171.89, −1.72) | (−0.138, −0.199, −0.970) |
| 8 Battlestation | (2200, 800, −1678) | (−0.20, 2.50, −0.03) | (110.00, 40.00, 83.90) | (11.46, −143.24, −1.72) | (−0.587, −0.199, −0.785) |

iPad table (same rotations except h 8 yaw 2.35): h0 (725, 899, −2271), h1 (1630, 1199, −1933), h2 (−2934, 1027, −1890), h3 (1759, 909, −2232), h7 (1200, 800, −2978), h8 (1759, 909, −2232). Rows 4..6 and 9 are zero. The cameras frame the ship off-centre (to the right of the left-hand menu panel), looking slightly down.

**Idle drift** (`ModStation::OnUpdate` 0xed2a8 @0xed4e8..0xed742, runs only on the main station view: no sub-window, no system menu, no ending sequence): three `EaseInOut`s (`+0x138/+0x13c/+0x140`) hold camera x/y/z; base = table position (`+0x12c/+0x130/+0x134`). Every frame each is `Increase(±dt)`; when it is within **5 units** of its target it flips its direction flag and eases from its current value to a new target on the other side of the base:
- x: base ± (18 + nextInt(131)) → ±18..148
- y: base ± (30 + nextInt(120)) → ±30..149
- z: base ± (50 + nextInt(100)) → ±50..149

Sign alternates (flag was 0 → negative offset). Initial flags random (`nextInt(20)` tests). Each leg is a sine ease of ~32.8 s. Only the translation drifts; rotation is fixed. (OnInitialize also adds a random ±0..149 jitter to `CutScene+8..0x10`; those fields only feed a leftover debug camera mover, `ModStation+0x114`.)

### 1.6 Hangar lights and fog
`ModStation::resetLight` 0xe9f1c (called at state 0x14 and whenever you come back from the Lounge/Hangar window):
- material ambient (0.7, 0.7, 0.7); material shininess 96;
- LIGHT0 direction (vector toward the light) = −(camDir + (−0.2, −0.3, 0)), with camDir = local +Z column of the camera at OnInitialize state 0x14. At that moment the current camera still has the CutScene init rotation (0, π/8, 0), so camDir = (0.383, 0, 0.924) and **toward-light = normalize(−0.183, 0.300, −0.924)**: from the camera side (−Z), above. Unity: toward-light (−0.18, 0.30, 0.94) normalised; a Unity directional light forward = −that.
- LIGHT0 diffuse (1, 1, 1), specular (0.5, 0.5, 0.5);
- LIGHT0 ambient by **system** race: Terran/default (0.25, 0.25, 0.25), Vossk (0.25, 0.55, 0.25), Nivelian (0.15, 0.15, 0.35), Midorian (0.45, 0.25, 0.25), race 8 (0.83, 0.28, 0.12).
- Fog: **Vossk only**, linear, start 0, end **30000** (1500 m), colour 0x011e0cff = RGB (1, 30, 12)/255 (dark green). Set in resetCamera and every frame in process. Other races: fog off (ModStation::OnRelease / CutScene dtor disable it).
- Background: `Level::createSpace` still builds the system `StarSystem` (sky, sun, planets) for types 4 and 0x17 (no station/landmarks, 0xbc738), and `CutScene::renderBG` → `Level::renderBG` draws it behind the room. So the current system's sky shows through any openings.

### 1.7 Animation in the hangar
- `CutScene::process`: every enemy geometry gets `Transform::Update(dt)` each frame → `*_anim_add` room layers (Vossk, Deep Science) loop, parked ships idle.
- Unused: `CutScene+0x38` (a list meant for `hangar_*_bot_*_anim` bots) is never filled; process would restart each non-running one with 20 % chance every 3000 ms (Terran/Nivelian hangars only). Not needed.
- Turret on the player ship: `CutScene::checkForTurret` 0xa4594 (see scenes notes); re-run after every equipment change.

### 1.8 What is 3D on each screen (`ModStation::OnRender3D` 0xefac4)
ModStation flags: `+0x60` Missions, `+0x61` Lounge, `+0x62` Hangar window, `+0x63` Map, `+0x64` Status, `+0x5e` system menu.
- Main station view and Status: hangar CutScene (BG + 3D).
- **Hangar window (shop / ship / equipment tabs): no hangar 3D at all**; full-screen 2D UI, plus `ListItemWindow` 3D item/ship preview (`HangarWindow::render3D`).
- Space Lounge: bar CutScene (`SpaceLounge::OnRenderBG/OnRender3D`).
- Map: StarMap. Missions: `MissionsWindow::render3D`.
- System menu (`MenuTouchWindow(2)`): 2D only over the cleared BG.

---

## 2. Bar / Space Lounge (`SpaceLounge` → `CutScene(4)` → `Level(4)`)

`SpaceLounge` (0x197890) is created on the first Lounge visit of a docking (`ModStation+0x70`), later `SpaceLounge::init` 0x197da0 is reused. `Level::createScene` runs once per creation, so visitor placement is re-rolled each docking.

### 2.1 Build (createScene branch 4)
Bar race `b` = system race (0..3). Enemies list order: [0..n−1] visitors, [n..2n−1] glows, [2n..3n−1] shadows, then the rooms (3, or 2 for Vossk). n = number of Station agents.
- Rooms `DAT_00254150[b][k]`, `PlayerStatic(-1, geom, 0,0,0)`, **no rotation** → by the mesh rule **Unity yaw 180°** (unlike the hangar):

| b | rooms |
|---|---|
| 0 Terran | 14025 bar_terran, 14026 `_add`, 14027 `_alpha` |
| 1 Vossk | 14028 bar_vossk, 14029 `_anim_add` |
| 2 Nivelian | 14031 bar_nivelian, 14032 `_anim_add`, 14033 `_alpha` |
| 3 Midorian | 14034 bar_midorian_anim, 14035 `_add`, 14036 `_alpha` |

- Per agent i: slot = `nextInt(7)` re-rolled until free; visitor mesh, glow and shadow statics:
  - visitor mesh = `DAT_00254380[agentRace]`: 0 Terran 14725 `bar_visitor_terran_m` (**female Terran: 14724 `_terran_f`**), 1 Vossk 14726, 2 Nivelian 14723, 3 Midorian 14725 (terran_m) **unless** `imageParts[0] == 2` → index 2 (Nivelian mesh), 4 Multipod 14722, 5 Cyborg 14725, 6 Bobolian 14720, 7 Grey 14721 (verified at 0xc2b3e..0xc2b8e);
  - glow = `0x37c9 + b` (14281..14284, all `bar_visitor_glow.fbx`, one material per bar race) at the slot;
  - shadow = 14348 `bar_visitor_shadow` (6-vertex floor quad, r 212) at **(x, y + 20, z)** (20 units above the slot floor, i.e. an anti-z-fight offset, verified `vmov s16, #20`).
- Visitor meshes are 12-vertex billboards (~515 units tall = 25.7 m, pivot at the feet).

Visitor slots `UNK_00254000[b][7]` (stride 0x54 per race):

| b | slot | game (x, y, z) | Unity m |
|---|---|---|---|
| 0 Terran | 0 | (−2325, 0, −964) | (−116.25, 0, 48.20) |
| | 1 | (−1023, 212, 745) | (−51.15, 10.60, −37.25) |
| | 2 | (−1098, 212, 427) | (−54.90, 10.60, −21.35) |
| | 3 | (−1164, 212, −227) | (−58.20, 10.60, 11.35) |
| | 4 | (−1979, 0, −108) | (−98.95, 0, 5.40) |
| | 5 | (−2556, 0, 646) | (−127.80, 0, −32.30) |
| | 6 | (−1439, 212, −860) | (−71.95, 10.60, 43.00) |
| 1 Vossk | 0 | (−694, 102, −271) | (−34.70, 5.10, 13.55) |
| | 1 | (914, 102, 453) | (45.70, 5.10, −22.65) |
| | 2 | (−680, 102, 1734) | (−34.00, 5.10, −86.70) |
| | 3 | (−417, 102, 1454) | (−20.85, 5.10, −72.70) |
| | 4 | (462, 102, −101) | (23.10, 5.10, 5.05) |
| | 5 | (285, 102, 913) | (14.25, 5.10, −45.65) |
| | 6 | (−680, 102, 155) | (−34.00, 5.10, −7.75) |
| 2 Nivelian | 0 | (−1279, 0, 264) | (−63.95, 0, −13.20) |
| | 1 | (−1220, 0, −192) | (−61.00, 0, 9.60) |
| | 2 | (−1849, 0, −1214) | (−92.45, 0, 60.70) |
| | 3 | (−875, 0, −686) | (−43.75, 0, 34.30) |
| | 4 | (48, 0, −911) | (2.40, 0, 45.55) |
| | 5 | (−457, 0, −2195) | (−22.85, 0, 109.75) |
| | 6 | (−794, 0, −1788) | (−39.70, 0, 89.40) |
| 3 Midorian | 0 | (1542, −10, −642) | (77.10, −0.50, 32.10) |
| | 1 | (1357, −10, −1986) | (67.85, −0.50, 99.30) |
| | 2 | (1924, −10, −1377) | (96.20, −0.50, 68.85) |
| | 3 | (−194, −10, −2542) | (−9.70, −0.50, 127.10) |
| | 4 | (979, −10, −202) | (48.95, −0.50, 10.10) |
| | 5 | (1047, −10, 220) | (52.35, −0.50, −11.00) |
| | 6 | (2319, −10, −498) | (115.95, −0.50, 24.90) |

### 2.2 Billboarding and glow (`SpaceLounge::updateScreenPositions` 0x19ec30, every frame)
For each visitor at slot position P:
- L = `MatrixGetLookAt(camPos, P, camUp)` (local +Z points at the camera, full billboard incl. vertical tilt).
- Glow: matrix L, position = P − 100·(L.z.x, 0, L.z.z) (100 units **behind** the visitor, away from the camera, y unchanged).
- Visitor: matrix L, **Terran bars (b = 0) additionally × RotY(π)** (0x19ee6a, `0x40490fdb`), position P.
- Tap rectangle: screen projections of P − 150·camRight and P + 150·camRight + (0, 450, 0).
(The ctor does the same once right after creating the bar camera, whose matrix is still identity; it is overwritten on the first update.)

### 2.3 Bar camera
- Camera `CutScene+0x6c`, **fov 1.2 rad (68.75° vertical), near 200 (10 m), far 48000 (2400 m)** (initialize + resetCamera).
- **Intro move** (SpaceLounge ctor): camera set to A, then `EaseInOutMatrix(A → B, 3000 ms)` stored at `+0x48`; `SpaceLounge::update` 0x19ef20 calls `Increase(min(dt, 50))` until the value equals B. Tapping during the intro jumps to B (OnTouchEnd case 0, `+0xb9`). Later visits (`init`) start directly at B.
  - A = pos `DAT_0025ce84[b]`, rot (0, `DAT_00252070[b]`, 0); B = pos `DAT_0025ceb4[b]`, rot (0, `DAT_00252080[b]`, 0). No pitch or roll.

| b | cam | game pos | yaw | Unity pos m | Unity Euler ° | Unity view dir |
|---|---|---|---|---|---|---|
| 0 Terran | A start | (−1315, 1160, −2728) | 0.03 | (−65.75, 58.00, 136.40) | (0, −1.72, 0) | (−0.030, 0, 1.000) |
| | B rest | (−1800, 620, 1805) | 0.04 | (−90.00, 31.00, −90.25) | (0, −2.29, 0) | (−0.040, 0, 0.999) |
| 1 Vossk | A | (1484, 2980, −1626) | 0.03 | (74.20, 149.00, 81.30) | (0, −1.72, 0) | (−0.030, 0, 1.000) |
| | B | (607, 610, 2362) | 0.43 | (30.35, 30.50, −118.10) | (0, −24.64, 0) | (−0.417, 0, 0.909) |
| 2 Nivelian | A | (−2472, 734, −3000) | 0.21 | (−123.60, 36.70, 150.00) | (0, −12.03, 0) | (−0.208, 0, 0.978) |
| | B | (136, 444, 1122) | 0.60 | (6.80, 22.20, −56.10) | (0, −34.38, 0) | (−0.565, 0, 0.825) |
| 3 Midorian | A | (−2598, 400, 1813) | 1.87 | (−129.90, 20.00, −90.65) | (0, −107.14, 0) | (−0.956, 0, −0.295) |
| | B | (2222, 450, 1227) | 0.46 | (111.10, 22.50, −61.35) | (0, −26.36, 0) | (−0.444, 0, 0.896) |

  B always looks at the visitors; A looks past/away from them (the intro swings/dollies into the room).
- **Idle sway at B** (update, after the intro): base = B (saved at `+0xc4`).
  - phase `+0x100` += clamp(dt·0.0025, 0.05, 0.12) **per frame**; bob = sin(phase) · min(speed·0.85, 3.5) (≤ 3.5 units ≈ 0.17 m).
  - yaw value v (`EaseInOut +0xbc`, starts 0→5, speed 2): when |v − target| < 0.25 → new target 5 − nextInt(10) (−4..5), speed 1 + nextInt(4), `Increase(±dt·speed)` (≈32.8 s / speed per leg).
  - camera = [RotY(v/35) with translation (0, bob, 0)] · B, i.e. the camera **orbits the room origin** about world Y by −0.114..+0.143 rad (−6.5°..+8.2°) and bobs vertically in world space.
- Selecting an agent (tap on a visitor or the side list) opens the chat UI (`SpaceLounge::startChat` 0x198974); **the camera does not move**. There is no per-visitor camera.
- `SpaceLounge+0xae` edge-touch camera nudging edits `CutScene+4..0x10`, which mode 4 never reads: dev leftover.

### 2.4 Bar lights, fog and animated props
- Lights: `SpaceLounge::init` calls `StarSystem::initLight` → the **same sun light as in space** for this system (space_level_setup §6), then LIGHT0 specular (0.5, 0.5, 0.5). The bar is lit by the system's sun colour/direction. Sky behind = the system StarSystem (renderBG).
- Fog: **Vossk bar only**, linear 0..**5000** (250 m), colour (1, 30, 12)/255, re-set each frame.
- `CutScene::initialize` (mode 4) extras, rendered by `CutScene::render3D`:
  - Terran: `bar_terran_bot_anim` 14280 (+ child 14279 `_add`) at the origin, `Transform::Update(dt)` every frame → a flying service bot on a **continuous loop** (its keyframes move it ~±1400 units).
  - Midorian: `bar_midorian_alpha_anim` 14038, initial `SetAnimationState(0,0)`; timer `+0x80` > 2000 ms → reset, 30 % chance → restart one-shot (`SetAnimationState(3,0)` then `(1,0)`). (A second one-shot slot `+0x28`, 40 %/1000 ms, is never created.)
  - Vossk branch has timers for `+0x30` (20000 ms) / `+0x34` (22000 ms), but those geometries are only created for Terran, so nothing plays (the `bar_vossk_bot_*` / `bar_vossk_alpha` FBXs have no resource ids).
- Every enemy (rooms, visitors, glows) also gets `Transform::Update(dt)` → `*_anim` room layers and the animated glow loop.

### 2.5 Which agents are present
- Agents belong to the station: `Generator::createAgents` 0xa1fd0, called from `Status::departStation` 0xb63e0 on arrival (with shop/ship lists).
- Count (not in supernova systems): story agents assigned to this station (only counted when campaign mission > 16, and not station 106 before DLC1 is won) = s; if station ≠ 108: r = nextInt(2); if r + s + 3 < 5 → count = s + 3 + nextInt(2) else 5. Station 108: only story agents. So normally **3–5 visitors** (max slots 7).
- Generic agent (`Generator::createAgent` 0xa26c0): race = system race (20 %: `nextInt(8)`), offer type random, gender male except Terran race (60 % male / 40 % female, wingmen always male), portrait parts `ImageFactory::createChar`.
- 35 % chance: one generic agent replaced by an enemy-faction agent (offer 7) for each hostile race in `DAT_00251f80`.
- `agents.json` in GoF2Data = the story agents (bar characters with fixed stations).

### 2.6 Lounge UI texts (for reference)
Header 398 "Space Lounge"; list roles 306 "Wingmen", 305 "Merchant", 884 "Diplomat"; chat buttons 860 "Okay.", 861 "No thanks.", 776 "Let me see it.", 804 "Show it on the map.", 807 "What's the risk?". Help 627 (first visit). Agent voices: `SpaceLounge::getSoundId` 0x19fdb4 / `getSpecificSoundForRace` 0x1a0080 (LOUNGE_eng/deu banks, not mapped here).

---

## 3. Station menu flow (ModStation, module 5)

### 3.1 OnInitialize state machine (0xe8080; one step per call, loading screen shown meanwhile)
- state 100: sound preload list (0x5f, 0x7a, 0x6c, 0x60..0x6b, 0x7e), station name cached, `computerTradeGoods` if > 30 s since last visit → 0x50.
- 0x50: builds the 5 menu buttons, the launch button and the credits button → 0x3c.
- 0x3c: ship yaw (270 or −200 px), news ticker, ChoiceWindow, race emblem image `DAT_002547b4[race]` (image ids 1190 Terran, 1187 Vossk, 1189 Nivelian, 1188 Midorian, all in gof2_interface.png) → 0x28.
- 0x28: campaign/story checks → 0x14.
- 0x14: autosave (if entering), campaign fixes, **hangar camera + lights** (§1.5/1.6), `enterStation` 0xea0a0 (departStation, visit, medals), wanted/hint popups → 1.
- final: play 0x7a `Station_Atmo_Mainview` (reverb off), start music `playMusicAndFadeOutCurrent(switch_to_target_setting)`, state 100, done.
(The CutScene(0x17) itself is created on the first call.)

### 3.2 Main view layout (`ModStation::OnRender2D` 0xef208)
- Footer: `Layout::drawFooterStation`. Header: "<Station name> " + 136 "Station" (no suffix for station 101).
- Left panel (`Layout::drawBox(2, 0, header, +0xa4 = layout+0xcc, h − header − footer)`):
  - race emblem (only if the system has an owner);
  - "<System name> " + 137 "System" (falls back to the bare name if too wide);
  - 133 "Tech level" + ": " + `Station::getTecLevel`;
  - race name 406 + race (only when `layout+0x286`).
- Five buttons (left column, x = layout+0x28, stacked from y = h − footer − layout+0x24 − 5·btnH − 4·gap):

| idx | text id | English | action (OnKeyPress 0xec6f8, key 0x10000) | 3D | ambience | music param |
|---|---|---|---|---|---|---|
| 0 | 167 | Hangar | HangarWindow (shop / ship / blueprints…), help 622; locked before campaign mission 5 | none (2D + item preview) | stop 0x7a, play 0x5f `Station_Atmo_Hangar` | 1.0 |
| 1 | 398 | Space Lounge | SpaceLounge (new or `init`), help 627; locked < mission 13 or = 49; pirate-base station 88 shows a "lounge closed" dialogue (433) | bar | stop 0x7a, play 0x6c `Station_Atmo_Lounge` | 2.0 |
| 2 | 177 | Map | StarMap (jump mode if a jump drive is fitted), help 628/631; locked < mission 9 or = 48/49; blocked if cargo overloaded (204) | StarMap | stop 0x7a | 0.6 |
| 3 | 129 | Missions | MissionsWindow, help 635; locked < mission 9 | MissionsWindow | – | 0.6 |
| 4 | 169 | Status | StatusWindow (medals etc.), help 640 | hangar | – | 0.6 |

  "Music param" = `FModSound::setParamValue(currentMusicEvent, param 0, value)`: the station music events have an FMOD parameter that switches mix/variation per screen; back to the main view sets **0**. On the way back: `resetLight`, `resetIdleCamForHangar`, stop the screen ambience, play 0x7a again, `checkForTurret`.
- Launch button `+0x8c`: `TouchButton("", style 0xc)` bottom-right; credits button `+0x90` (style 0xb, left of it) opens the credit shop.
- Top-bar "menu" (`Layout::OnTouchEnd`) opens `MenuTouchWindow(2)`: 28 "Start new game", 29 "Load game", 30 "Save game", 31 "Options", 0 "Language" (condition on the iPad flag), 43 "About", 33 "Exit" (Android). Help button text 644.
- 50 "Game saved." / 54 "Game loaded" shown for 3 s top-left.
- No fades between hangar and bar: the switch is immediate (the Lounge has its own 3 s camera intro).

### 3.3 Station music (`Globals::playMusicAndFadeOutCurrent(0)` 0xf9dc0)
Stops the current music, then plays:

| condition | id | event | file |
|---|---|---|---|
| station 108 (home base) | 132 | HomeBase_Station | MUSIC/HomeBase_Station.ogg |
| station 101 | 131 | Station_Valkyrie | MUSIC/Station_Valkyrie.ogg |
| station 10 in mission 0x9f | 144 | OutroSong | MUSIC/OutroSong_02b.ogg |
| station 10 or 100 | 133 | Deep_Science_Station | (DLC bank) |
| else `DAT_00252000[race]` Terran | 128 | Station_Terraner | MUSIC/Station_Terraner.ogg |
| Vossk | 127 | Station_Vossk | MUSIC/Station_Vossk.ogg |
| Nivelian | 129 | Station_Nivelianer_LO | MUSIC/Station_Nivelianer.ogg |
| Midorian | 130 | Station_Midorianer_LO | MUSIC/Station_Midorianer.ogg |

Other station SFX: 0x60 Button_Dismount, 0x61 Button_Info, 0x62 Button_Mount, 0x63 Button_Sell, 0x64 Button_to_station, 0x65 Button_to_ship (SFX_STATION_HANGAR), 0x66..0x6b map sounds (SFX_STATION_MAINVIEW), 0x7c Button_Push, 0x7e Message_Info_Screen. Ambience files: `SFX_STATION_MAINVIEW/Station_Atmo_Mainview_1.ogg` (+ `_Add_1`), `SFX_STATION_HANGAR/Station_Atmo_Hangar3.ogg` (+ `_Add_1..7`), `SFX_STATION_LOUNGE/Station_Atmo_Lounge_1.ogg` (+ `_Add_*`).

### 3.4 Launch / undock
1. Launch button → `ModStation::leaveStation` 0xec1ec: blocks with a message if cargo > max load (204), campaign missions 6/7 without weapon+armour (529/530), mission 0x14/0x15 special cases (531), mission 0x4d not in ship 37 (326). Otherwise ChoiceWindow **397 "Depart the station?"** (default = left button), `+0xae` = 1.
2. Confirm (OnTouchEnd ~0xeaf18): `Status::departStation(currentStation)` (mission 0x30: station 58 instead + `initStreamOutPosition = 1`), saved HP `Status+0x5c/0x60/0x64/0x68 = −1` (full HP), `resetNewMedals`, `switch_to_target_setting = 1` (space music), `SetCurrentApplicationModule(2)` → MGame. No fade/animation in the station; the loading screen covers it.
3. In space (`initStreamOutPosition == 0`): player at **(10, 10, 10000)**, yaw ±0.1534 rad, speed 2 (space_level_setup §4); space music `DAT_00252010[race]` (134 Terran, 139 Vossk, 138 Nivelian, 137 Midorian).
4. **Launch camera** (`LevelScript::LevelScript` 0x15e650 + `process` 0x160d50): `TargetFollowCamera` in look-at mode. Camera position = playerPos + playerRotation · (±(500..2499), ±(500..2499), **9000**) (arrival by travel: ±(500..999), 7000), looking at the ship; the ship flies toward/past it at 2 u/ms. Player invulnerable, no collision. After **7000 ms** (campaign mission > 1): look-at off (normal chase cam), vulnerable, collision on, `initStreamOutPosition = 0`, autopilot to the programmed station if any.

### 3.5 Docking (MGame::dockEvent 0x1afebc, checked every frame from MGame::OnUpdate)
- Requires the autopilot target to be the station (`PlayerEgo::goingToStation`) and either `Level::collideStation` (station collision volume) or target == landmark 0 and `PlayerEgo::collidesWithStation` (|pos| < 16000, `calcCollision` 0xab550). Not in alien or empty orbits; missions 0x31..0x36 refuse unless station 74 (HUD event 0x15).
- Then: `Achievements::checkForNewMedal`, `switch_to_target_setting = 0` (station music), save HP/shield/armor/gamma to Status, `SetCurrentApplicationModule(5)`.
- **No docking animation or camera**: the autopilot flies into the station and the module switches (loading screen). `PlayerEgo::setDockingCamera` 0xa68c0 has no direct callers (its offsets (0, 150, 500) belong to asteroid/mining docking points).
- Jumpgate "stream" docking with a programmed station shows ChoiceWindow 574 (0x23e) + ": " + station name + "\n" + 421 (0x1a5) instead (space_level_setup §8).

---

## 4. Unity build recipe (summary)
1. Hangar root at origin. Room prefab `hangar_<race>` with **identity** rotation. Player ship prefab (NPC engine variant, exhaust off) at (0, Y[ship]·0.05, 0), yaw π − 2.25 (Nivelian π + 1.667), drag = 1 rad / 120 px.
2. Parked ships: count/slot/ship rules §1.4, y += Y[ship], Unity yaw 180° − θ°.
3. Camera: parent at (0, Y[shipAtEntry]·0.05, 0), local pos = phone table, `Quaternion.Euler(−rx°, −ry°, −1.72°)`, vertical FOV 45.8°, near 10 m, far 5000 m; drift per §1.5.
4. Lights §1.6, Vossk fog 0..1500 m (1, 30, 12). Skybox = current system.
5. Bar: separate root (own scene or toggled root). Rooms `bar_<race>` with **yaw 180°**. Visitors/glow/shadow per §2.1–2.2 (face the camera every frame). Camera intro A→B 3 s sine ease, then sway §2.3, vertical FOV 68.75°, near 10 m, far 2400 m. Sun light of the system + specular 0.5. Vossk fog 0..250 m.
6. Menu: 5 buttons + launch; ambience/music per §3.2–3.3; switching is instant.

---

## 5. Functions (name, address)
| Function | Address |
|---|---|
| CutScene::CutScene / resetCamera / initialize / checkForTurret / process / replacePlayerShip / renderBG / render3D | 0xa3e1c / 0xa3f4c / 0xa4074 / 0xa4594 / 0xa49f4 / 0xa53b4 / 0xa5580 / 0xa558c |
| Level::init / createSpace / createScene / renderBG | 0xbb49c / 0xbbba0 / 0xc2910 / 0xd43f0 |
| ModStation::ModStation / OnInitialize / resetLight / enterStation / OnTouchMove / OnTouchEnd / resetIdleCamForHangar / leaveStation / OnKeyPress / OnUpdate / OnRender2D / OnRender3D | 0xe7bf0 / 0xe8080 / 0xe9f1c / 0xea0a0 / 0xea340 / 0xea4ec / 0xec06c / 0xec1ec / 0xec6f8 / 0xed2a8 / 0xef208 / 0xefac4 |
| SpaceLounge::SpaceLounge / init / startChat / updateScreenPositions / update / OnTouchEnd | 0x197890 / 0x197da0 / 0x198974 / 0x19ec30 / 0x19ef20 / 0x1a0360 |
| HangarWindow::initialize / render3D | 0x171740 / 0x172cf0 |
| MenuTouchWindow::MenuTouchWindow (mode 2 branch) | 0x14816c |
| Generator::createAgents / createAgent | 0xa1fd0 / 0xa26c0 |
| Status::departStation | 0xb63e0 |
| Globals::getRandomEnemyFighter / playMusicAndFadeOutCurrent | 0xf9034 / 0xf9dc0 |
| MGame::dockEvent / OnUpdate | 0x1afebc / 0x1ac778 |
| PlayerEgo::setDockingCamera | 0xa68c0 |
| LevelScript::LevelScript / process / resetCamera | 0x15e650 / 0x160d50 / 0x16f418 |
| StarSystem::initLight | 0x15d080 |
| AEMath::MatrixSetRotation (xyz / ordered) / MatrixGetLookAt / Matrix::operator*= | 0x8b09c / 0x8b17c / 0x8b73c / 0x8a78c |
| AbyssEngine::CameraSetPerspective / PaintCanvas::FogSetParameter | 0x7a594 / 0x871f8 |
| EaseInOut::* / EaseInOutMatrix::* | 0x7aa34.. / 0x775d0.. |

Tables: hangar cam `DAT_002546c4` / iPad `DAT_0025464c` (10 × int3), pitch `UNK_0025473c` (10 f), yaw `UNK_0025478c` / iPad `UNK_00254764` (10 f), race emblem images `DAT_002547b4`, ship y `DAT_00253d48` = `DAT_002520f0` (64 i), rooms `UNK_00253e48` (10 × 4 i), parked counts `UNK_00253ee8`, slots 0x253f10..0x254000, visitor slots `UNK_00254000` (4 × 7 × int3), bar rooms `DAT_00254150` (4 × 3 i), glow ids `DAT_00251fe0`, visitor meshes `DAT_00254380`, bar cam A `DAT_0025ce84` / B `DAT_0025ceb4` (4 × int3), bar yaw A `DAT_00252070` / B `DAT_00252080` (4 f), station/space music `DAT_00252000` / `DAT_00252010`, ship races `DAT_00254990`.

The Thumb disassembler used for the lost float arguments is a 70-line capstone script (literal pool = ((pc+4)&~3)+imm); it lived in the session scratchpad, not in the repo.

---

## 6. Uncertainties
1. **Mesh yaw rule for rooms.** Hangar rooms (0, π, 0) → Unity identity and bar rooms (no rotation) → Unity 180° both follow the project rule "game yaw θ → Unity π − θ", which assumes the FBX = mirrored game-local mesh. Check once in Unity: bar visitors (slot table) must stand on the bar floor/stools, hangar parked ships inside the bays.
2. **Camera Euler conversion** (−rx, −ry, rz) is derived, not tested in Unity. Check the Terran hangar: the ship must appear right of centre, seen slightly from above, with the camera at +Z (Unity) of the ship.
3. **FOV axis:** assumed vertical (engine multiplies tan(fov/2) by the aspect for the other axis). If the picture looks too zoomed on wide screens, treat it as horizontal.
4. **Hangar light direction** depends on which camera is current at OnInitialize state 0x14. I traced it to the CutScene camera with rotation (0, π/8, 0); if the ModStation-ctor matrix were still in effect, the direction would come from the table rotation instead.
5. **Camera parent**: the hangar camera's world position = (0, Y[ship at entry], 0) + table offset. This assumes the engine composes camera world matrices through `TransformAddChild` parents.
6. **Terran bar visitors × RotY(π)**: the code does it only in Terran bars (keyed on the bar race, not the visitor race). The billboards are probably double-sided (12 vertices), so it may only mirror the texture. Faithful but odd.
7. **Midorian visitor with `imageParts[0] == 2` uses the Nivelian mesh.** That is what the code does; the meaning of image part 0 is not traced.
8. **Music parameter 0** (values 0 / 0.6 / 1 / 2): its effect inside the FMOD event (layer, filter) is unknown because the FEV isn't parsed.
9. The Vossk-bar process branch updates enemies[len − 3], which for a 2-room bar is the last visitor shadow. Probably a harmless off-by-one in the original.
10. The ModStation ctor's `EaseInOutMatrix` (A = B, 3000 ms, `ModStation+0x20`) and the random `CutScene+8..0x10` jitter feed only the leftover debug camera (`+0x114`); no visible camera transition was found between the main view and the sub-screens.
11. Frame-rate dependence: the turntable fling friction (×0.9 per frame) and the bar bob phase step (0.05..0.12 per frame) run per frame in the original; the remake should normalise them to ~50 fps (dt = 20 ms).
