# Star map and system travel

Notes moved from `CLAUDE.md` (its index lists every notes file). Code comments citing `CLAUDE.md "<section>"` mean the section or bullet of that name here.

## Star map and system travel

Research: `Reference/research/starmap_travel.md` (+ `Reference/tools/starmap/starmap_tables.py`: sun positions, gate
paths, energy cells, exact system layouts). Rules in `GalaxyMap` (plain C#), the map in `StarMap` (UI, created at
runtime by `Open()`), the flight side in `SystemJump` (on the player ship).

- **Star map** (`StarMap`): one fullscreen map for the station's Map button, the jumpgate and the Khador Drive. Its own
  3D scene on layer 31 with its own camera (the level's cameras and lights are switched off while open, flat ambient, no
  fog) plus the `UI/StarMap` overlay on a higher panel sort order; the owner pauses its game.
  - Galaxy view: additive sun sprites of the visible systems (`Session.SystemVisible`, from `initiallyVisible`; hidden
    systems aren't drawn), faint route lines and the pulse toward the gate neighbours (not with a drive); tap selects
    (sound 103), the camera glides it to the centre, a second tap zooms in (2184.5 ms sine ease, 106): the current
    system or a gate neighbour, any visible system with a Khador Drive, else 420. Drag pans with inertia and spring
    limits (not while a system is being centred: `StarMap::update`'s centring overwrites the spring, so Skor Terpa past
    the limit can be reached; remake: the limits take in every visible sun, `StarMap.PanMin` / `PanMax`: Loma, Talidor,
    Ginoya, Skor Terpa, Skavac and Me'enkk lie past the original's box, and once centred the spring dragged them back
    off the centre, up to ~280 px, so a second tap missed them). Remake: the full-map overview, one zoom level further
    out fitting every visible sun (the Full map / Close up button, Q, the controller's X, the mouse wheel, a pinch; Esc
    leaves it first): no panning there, a tap or Enter on a system zooms back in centred on it; the zoom in / out of it
    takes the galaxy <-> system zoom's 2184.5 ms with its sine ease (`StarMap.OverviewMs`; it was 650 ms, over long
    before its Map_Zoom_In / Out sound, 2.68 / 2.32 s).
  - System view: the planets on their orbits (`java.util.Random(system * 1000)`, same layout every visit), lit from the
    sun's position like `StarMap::initStarSystem`'s light (`LightSetLightPosition`, a fixed-function point light without
    falloff: `Resources/GoF2StarMap/MapPlanet.shader`, ambient 0.2 + diffuse toward the global `_StarMapSunPos`; the
    remake had a directional light that lit every planet from one side), drag turns it (pitch +-45 deg), tap selects a
    planet (104), release turns it to the front (105), a second tap confirms: 419 on the current station, 579 / 582 /
    581 on energy cells with a drive, else "Destination: X / Travel to this station?" (574 + 421). Before those,
    `StarMap::OnTouchEnd`'s campaign checks on the step's target: `Story.RequirementRefusal` (Supernova notes "Story
    rules") and step 24's scanner + tractor beam (532; #186).
  - Overlay: rings, names (selected orange), race and security lines, "Tech level", visited tick
    (`Session.VisitedStations`, set on docking, and in space for the orbits without docking: `SpaceLevel.VisitedInSpace`,
    MGame::OnInitialize's Station::visit for 109, 110, 132-134, 102-104 and 111 from step 0x5e; #188), gate icon, "you
    are here" pulse, system block with the race logo,
    "Energy cells needed: N / M" (578), Key legend (400).
  - Header (#175, remake): as tall as the station's top bar through an invisible copy of its Menu button
    (`StarMap.uss .map-header-spacer`, added by `StarMap`), so the title sits at the station name's height whatever the
    interface font; shown where the station shows Menu (touch, keys and mouse; with a controller neither shows), and
    on phones at the Menu button's 64-unit touch height (`.layout-phone .map-header-spacer`). The footer's key hints are
    the small ones (UI "Small key hints").
  - Input: touch / mouse drag and tap; keyboard arrows select, WASD move / turn, Enter zoom in / confirm, K key, Esc
    back; controller D-pad, left stick, A, Y key, B back.
- **Station Map button** (177; keyboard M, controller Y; refused with an overloaded hold, 204): station mode (jump mode
  with a drive). Picking a station leaves at once (`StarMap::depart`): the launch sequence, then the autopilot to the
  programmed station, or for another system with a drive the Khador charge.
- **Jumpgate** (`MGame::dockEvent`): the autopilot to the gate entering its sphere (7500, Vossk 11250) hides the HUD and
  pauses; with a programmed station "Destination: X / Travel to this station?" (Yes preselected), No or no destination
  opens the map in gate mode (only the current system and its gate neighbours, any station there). Backing out puts the
  ship past the gate with the controls back. Remake (#37): a destroyed ship takes no gate and its Khador charge stops
  (shot down entering the gate it still jumped, repaired).
- **Gate jump scene** (`MGame::startJumpScene` / `updateJumpScene`, ~6.3 s): ship at gate - (0, 0, 10000) facing game +Z
  at 2 u/ms, fixed look-at camera at gate + (-2000, 300, -6000) drifting (5, 2, -3) u/ms; when it passes gate z - 10000
  the gate's idle `_anim_add` is swapped for the `_jump_anim_add` child (5000 ms, once) and sound 31 (Jumpgate_3b / 4c /
  1b / 2b at random) plays; 1000 ms in the ship vanishes; at the end `Space` reloads in the target station's orbit.
  Every gate layer opens with a one-off key (t 0, the loop from 50 ms; the Midorian ring lights at the centre there):
  looped from 0 the ring parts jumped 17.8 m on every 2.5 s wrap; now skipped like every animation's (see "Known open
  items", `PartAnimation`). The gate is held at LOD 0 while it jumps (`SystemJump.PlayGateJump`,
  `LODGroup.ForceLOD`; `ResetGate` lets go; #167): its made levels keep the idle layers but not the jump layer, so on a
  phone's lower LOD bias (Medium detail, 0.6) the gate fell to level 1 0.4 s into the flash and the jump played unseen.
- **Khador Drive** (item 85, or ships 37 / 38 / 40): the autopilot menu entry opens the map in jump mode; a jump to
  another system (instant jump) charges 5000 ms (sound 33, cells removed at the start, "-N t Energy Cells", the charge
  bar in the HUD: `Hud::draw` 0x1933f6's frame 0x53a with the striped fill 0x539 revealed from the centre outward,
  half-width min(1, rate · 1.05) · 194, and 318 "Drive charging" (the cloak's 317) in its lower panel;
  `GoF2Hud/charge_frame` / `charge_fill`, #48) once the level is 5 s old, then the `khador_jump` fx (15026, scale 2)
  3000 units ahead, camera at fx + R(-2000, 300, -2000) drifting (5, 2, -5), ship hidden at 1700 ms, reload at the fx
  end (~4 s). Cells = gate jumps on the shortest route through visible systems, 4 without one, x2 on Extreme.
- **Arrival** from another system: the hidden gate in the gate orbit, else (0, 0, 100000), facing the station, with the
  7 s fly-in camera; the orbit information (race logo, station, "<System> System", security level in its colour) shows
  during it. The programmed station is cleared: no autopilot leg follows a system jump.
- **Loma** (system 25, the Valkyrie add-on's black market; gates to Aquila, Union and Shima): on the map from a new game's
  start and after every load (`Status::resetGame` / `GameRecord::load` show it whenever the Valkyrie add-on is owned, and
  the remake owns both; `GalaxyMap.Visibility`, `SaveGame`), not only in the add-on campaigns. In the orbit: 6-9 pirates
  (+ the raider waves, security 0), disarmed until the toll 448 is answered (see "Radio chatter"), maximum prices at all
  three stations (`calcCargoPrices`: Status+0x78 is a placeholder Station, so every real one), no seen-price records
  (`HangarWindow::initialize`), signatures (sort 29) only rolled into Loma stock, kills count but change no standing
  (`Player::damage`), no ticker, no docking fine; arriving by travel 40000 further out (`Level::init`).
- **Remake-only (free play, no campaign):** the campaign takes the player out of gateless Mido; without it, a ship in a
  system without a jumpgate counts as having a Khador Drive (it still needs energy cells), and Var Hastra always stocks
  energy cells.
- **Mission maps** (`StarMapMode.Mission`, Missions window / lounge offers / Most Wanted): view only in the original
  (remake, players' suggestion: the Missions window's map travels, `StarMap.Open`'s allowTravel,
  `StationMenu.CanTravelFromMap` / `TravelFromMap`: confirming a station is the Map button's departure with the station
  programmed, the Khador rules with a drive; without one a target past the gate neighbours is reached along the gate
  route: each gate's prompt names the destination and jumps to the next system's gate orbit (`SystemJump.NextHop`;
  `Arrive` keeps the programmed station on a hop, so the autopilot flies on to the next gate; the original's gate jumped
  straight to a far programmed station, which the Distress Help used); the lounge's offer maps stay view only), centred
  on the target, the yellow route along the gate path (finished segments opaque, the current one grows with alpha 255·t
  on the 0.99 s pulse, the next when t wraps); the Wanted map starts it at the criminal's last-seen system (`setStart`).
  A gateless start system (Mido) has no route, like the original.
- **Reveal** (the lounge's bought coordinates, `revealSystem`): the camera on the new system, hidden (no label, lines or
  input) for 4000 ms while its sun grows (remake: to the normal size), then selected; view only.
- **Volatile goods** (`GalaxyMap.HasVolatileGoods`: 209 / 204 in the hold): the Khador menu entry and a map target
  outside the gate routes give 612; a gate neighbour picked on the Khador map goes by the jumpgate. Mission blocks: 525
  at the gate and on the Khador entry.
- **Sounds** (the FEV's LGCY data): 31 Jumpgate = one of Jumpgate_3b / 4c / 1b / 2b at random, 32 KhadorDrive =
  Jumpgate_5c. 102 Map_Whoosh is a drag odometer (`StarMap.AddWhoosh`, StarMap+0x1c0: + min(|dx + dy|, 10) per galaxy
  drag move, + min(|yaw + pitch velocity| · 0.01, 10) per frame in the system view, 0 past 100): entering the parameter
  regions 0 / 25 / 49.8 / 75 plays Map_Click_01 (event volume 0.439); a touch-down restarts it, the back button stops
  it.
