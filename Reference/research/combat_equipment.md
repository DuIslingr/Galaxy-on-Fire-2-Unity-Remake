# Combat equipment: cloak, emergency system, time extender, signatures, beams, gamma shield, EMP effects, NPC missiles, radio portraits, docking fine

Implementation spec for the player equipment and combat presentation that the remake doesn't have yet, decoded from
`libgof2hdaa.so` (Android HD). Game units and milliseconds (Unity: 1 unit = 0.05 m). Addresses use the Ghidra image base
0x10000. Image rects are HD atlases (`atlas.rect`, `Reference/tools/shop/atlas.py`). **(v)** = read in the code / disassembly,
**(a)** = assumed or inferred. Item "sort" = `items.json categoryId`.

Read first: `ship_combat.md` (damage model, §2.4 EMP, §2.5 emergency system, §4 NPC weapons, §7 HUD),
`weapons.md` (guns, rockets, EMP weapons table), `npc_traffic_ai.md` (§4 standing / signatures / friendly fire, §5.3
targeting, §8 radio chatter), `dialogue_cutscenes.md` (§1.3 portraits, §2 radio), `autopilot_travel.md` (HUD menu,
fast-forward button), `lounge_ui.md` §6 (medals).

What exists in the remake (Sept 2026): `PlayerHealth` (pools, regen, repair bots, hit feedback, death; *no emergency
system*), `Hitpoints` (pools, EMP points, `vulnerable`), `Target.untargetable` (= `Player+0x5e`), `CombatRadar`,
`CombatView` (markers, hull bars; *no EMP bar*), `Radio` + the flight HUD radio box (campaign lines **with** portrait via
`Portrait.ShowSpeaker`; generic chatter goes to HUD messages), `NpcShip` (AI, EMP disable stops movement; *no sparks*),
`Standing` (*no signatures*), `Gun` (*no weapon-mod factors*), `FlightModel` (boosters, steering nozzles done).

---

## 0. TL;DR

1. **Cloak** (94-96, integrated on Specter 44 / Scimitar 49 = U'tool stats): a **HUD-menu entry** (no button/key). Costs
   attr 38 energy cells (item 122) → charge attr 36 ms ("Cloak charging" bar) → cloaked attr 35 ms (2 s fade in/out,
   sound 30 `Cloak_02` both ways) → cooldown 7000 ms (12000 hardcore) → "Cloak ready". Effect = `Player+0x5e`: NPCs and
   turrets **don't fire** at the player (they still chase), sleepers don't wake; bullets in flight still hit. **Nothing
   breaks it early** (firing, damage, boost). Visual: dissolve + screen-refraction shader, engine glow hidden, exhaust
   darkened. Stat `Status+0xc0` ms → medal 19 "Ninja" (5/3/2 min).
2. **Emergency system** (185): at hull < 1 → hull 1, invulnerable attr 41 = 10 s, `v_shield` bubble grows/shrinks 5 %,
   sound 1115 `Invincibility_01`, item consumed. Khador entry disabled meanwhile; 5 kills during it → medal 43.
3. **Time Extender** (184): the fast-forward button's slot shows a clock outside autopilot; tap = bullet time: world dt
   ×0.3, player + camera dt ×0.7, sound pitch down, for attr 42 = 15 s (tap again to stop), cooldown attr 43 = 30 s.
   Mission clocks run on world dt, so time limits stretch.
4. **Signatures** (189-192): `Standing` override: signature race = friend, its rival = enemy, **every other race
   neutral**; lost (with −100 standing) by friendly fire past 33 % / 50 % of a ship of that race ("Signature invalid").
5. **Repair beam** (207/208) auto-heals up to attr 55 friendly damaged ships within attr 53 units at `attr54·0.03/100`
   HP/ms; **Transfusion beam** (222/223) auto-drains hostile ships within attr 53 (`attr54·0.01/100` HP/ms) into the
   player's shield while it's below 100 %. Retarget every 2500 ms; no controls.
6. **Gamma shield** (205/206): supernova stations 109-113 drain a 0..100 gamma pool (0.2-3 /s), attr 52 = % reduction;
   gamma 0 = instant death; "Warning: Gamma shield low" below 15.
7. **EMP**: disabled NPCs stop moving (still turn, target and fire), EMP spark particles (records 17/18) on, EMP bar under
   the ship; the player has no EMP pool and no NPC fires EMP at it.
8. **NPC missiles**: only Wanted ships 45-48 (extra straight G'liissk rocket gun, ×4 damage) and campaign Scimitar
   clusters in this build; no warning, no countermeasures.
9. **Radio portraits**: the generic chatter (Hold your fire / He's crazy / He's back / pirates / black market / Wanted)
   uses the same radio box as campaign lines, with a random race face (or Pirate Boss / the Wanted pilot).
10. **Docking fine**: on entering a station whose race is hostile (standing) → `|axis|/100·2800 ± 100` (text 205), else
    after attacking its forces → `150·rank + 1000` (text 206); ×10 hardcore; Yes pays (clears the flag), No launches.

---

## 1. Cloak (items 94-96, sort 21 = 0x15; integrated on ships 44 Specter / 49 Scimitar)

### 1.1 Functions and fields

| Function | Address | Role |
|---|---|---|
| `PlayerEgo::PlayerEgo` (cloak part) | 0xa5a76 | reads the cloak item (or item 95 for an integrated cloak), preloads sound 30 |
| `PlayerEgo::setShip` (end) | 0xa6100 | `MeshCloneMaterial(hull mesh) → +0x388` (own material to switch shaders on) |
| `PlayerEgo::toggleCloaking` | 0xa65a4 | start charging (pay cells) / engage the cloak |
| `PlayerEgo::update` (cloak part) | 0xa913a (cooldown), 0xa941a-0xa98e0 | charge timer, fade in/out, end, cooldown, "Cloak ready" |
| `PlayerEgo::getCloakRate / isChargingCloak / isRechargingCloak / getCloakRechargeRate / readyForCloak / isCloaked / hasCloak / getCloakingPercentage` | 0xa6eb0 / 0xa6f34 / 0xa6f3a / 0xa6f48 / 0xa6f6a / 0xa6f84 / 0xa6854 / 0xa81a0 | state getters for the HUD |
| `MGame::useCloak` | 0x1a930c | the HUD-menu entry's action; "not enough cells" window |
| `Hud::initHudMenu(0)` (cloak entry) | 0x18e734 | the entry, disabled while cloaked / charging / recharging |
| `Hud::draw` (charge bar, ready flash) | 0x1933f6 / 0x190f96 | "Cloak charging" bar, menu-button flash |
| `Ship::hasCloak / hasCloakIntegrated` | 0x1a39e6 / 0x1a3a08 | `Ship+0x51` (set by `refreshValue` for a sort-21 item) or ship 0x2c / 0x31 |
| `AbyssEngine::BumpShaderCloak` (shader type 0xe) | engine | the dissolve/refraction shader |

`PlayerEgo` fields: `+0x1ac` cloaked (byte), `+0x1ad` charging (byte), `+0x1b0` cloak `Item*`, `+0x208` phase timer (ms; −1 before the first use), `+0x20c` cooldown left (ms), `+0x210` cloak duration = attr 35, `+0x214` charge time = attr 36, `+0x368` cooldown length (difficulty), `+0x325` engine child hidden, `+0x388/+0x38c/+0x390` cloned hull / turret materials, `+0x394` the hull material's original shader type. `Player+0x5e` = **untargetable** (the flag the AI reads). (v)

### 1.2 Attributes

| Item | attr 35 duration | attr 36 charge | attr 38 energy cells | notes |
|---|---|---|---|---|
| 94 Sight Suppressor II | 20000 ms | 6500 ms | 2 | |
| 95 U'tool | 10000 ms | 2000 ms | 1 | attr 60 = 1 (Vossk-only stock); also the stats of the **integrated** cloak of ships 44 Specter and 49 Scimitar (`items[95]`) |
| 96 Yin Co. Shadow Ninja | 40000 ms | 3500 ms | 5 | |

Energy cells = cargo item 122 (0x7a), the Khador Drive's fuel. Cooldown after the cloak ends (`PlayerEgo+0x368`, set in the constructor from `options[0x2c]`): ≤ 0 → 5000, ≤ 0.6 → **7000 (normal, 0.5)**, ≤ 1.1 → 9000, else **12000 (hardcore, 1.5)** ms (v). Every level starts uncloaked with no cooldown (constructor zeroes the fields) (v): docking, jumping and planet jumps end a cloak.

### 1.3 Activation (v)

- **Control: an entry in the HUD's main flight menu** (`Hud::initHudMenu(0)`, opened by the HUD menu button; the game pauses while it is open). Menu 0 lists, in order: 266 "Secondary weapons" (button 0x200, only with several secondaries), 306 "Wingmen" (0x400), **the cloak (button 0x800, label = the cloak item's name `1274 + item`, for an integrated cloak the U'tool's name)** when `Ship::hasCloak`, 1359 "Khador Drive" (0x1000). The menu header shows the energy-cell icon 0x4f5 (`gof2_interface_iphone4.png` [1301, 855, 76, 61]) and the cell count (`Hud+0x21c`). There is **no dedicated HUD button or key** in this build.
- The entry is drawn **half-transparent and ignores taps** (`TouchButton+0xa7`; `OnTouchBegin/End` require visible && !halfTransparent) while cloaked, charging or recharging; while recharging it shows the press-progress fill = `getCloakRechargeRate` = `1 − cooldownLeft / cooldownLength`.
- Tap → menu closes, sounds resume, `MGame::useCloak` → `toggleCloaking`:

```
toggleCloaking():                                    // returns 0 only for "not enough cells"
  if !charging:
      if !cloaked and cooldownLeft <= 0:
          n = cloakItem.attr38
          if cargo(122) < n: return 0
          removeCargo(122, n); charging = 1
          hudEvent(0x1e, n)   -> "-<n>t Energy Cells" (1396), clears the message queue
          hudEvent(0x1c)      -> Hud+0x216 = 1: charge bar on, bar timer reset
          return 1
  else if phaseTimer >= chargeTime:                  // called by update when the charge completes
      play 30 (Cloak_02); Player+0x5e = 1 (untargetable); cloaked = 1; phaseTimer = 0
      hull material (+0x388) shader type = 0xe (BumpShaderCloak); anim values 0; same for the turret meshes
      (turret: resource material switched to the cloak variant: 0x4e8e, Matador 224 → 0x5e17,
       plasma collectors 198/199/200 → 0x7161/0x7167/0x716d)
  return cloaked
useCloak: result 0 -> ChoiceWindow (pauses) "583 You don't have enough energy cells left to use the cloak. Energy
          cells needed:" + " " + attr38 + "."   (the number comes from the mounted sort-21 item; 0 for an integrated cloak)
```

### 1.4 Timeline (`PlayerEgo::update`, v)

```
charging (not cloaked):  phaseTimer += dt
    phaseTimer > chargeTime: hudEvent(0x1d) (bar off); toggleCloaking() (engages); charging = 0
cloaked:                 phaseTimer += dt; Status+0xc0 (64-bit) += dt           // "Ninja" medal counter
    t < 2000 (fade in):  u_AnimValue = t/2000; alpha of the ship group's last two children
                         (AEGeometry+0x10 / +0x14 = the lights / engine-glow meshes) = max(50, 255 − t/2000·255)
                         cloak% >= 25 (t >= 500): engine-glow child (+0x14) hidden
    always:              u_CloakRate = t·0.001 (the refraction wobble phase)
    t > dur − 2000:      u_AnimValue = 1 − (t − (dur−2000))/2000; alpha = max(50, (t − (dur−2000))/2000·255)
                         cloak% < 25 (last 500 ms): engine-glow child visible again
    t > dur (end):       phaseTimer = 0; cooldownLeft = cooldownLength; cloaked = 0; Player+0x5e = 0; play 30;
                         engine child visible; hull shader type restored (+0x394); turret materials restored
                         (0x4e86 / 0x5e15 / 0x715f / 0x7165 / 0x716b)
    exhaust particles:   Level::setPlayerEngineColor(grey = clamp(221 − 2.01·cloak%, 0, 221)) each frame
                         (colour of every player trail emitter, 221 → 20 fully cloaked)
cooldown:                cooldownLeft > 0: −= dt; reaching ≤ 0 -> hudEvent(0x2e) "316 Cloak ready"
```

`getCloakingPercentage` = 0 when not cloaked; `t·100/2000` in the first 2000 ms; `(1 − (t − (dur − 2000))/2000)·100` in the last 2000; else 100. The engine sound is not changed. Nothing ends the cloak early: **firing, boosting, being hit, locking, mining, docking approach do not break it** (the only writes of `+0x1ac` are the engage and the timer end; `PlayerEgo::shoot` has no check) (v).

### 1.5 What the cloak does to the world (v)

`Player+0x5e` ("untargetable") is the only gameplay effect:

- **NPC fighters don't fire at a cloaked target** (`PlayerFighter::update` fire block: `target.untargetable → attacking = false, stopShooting`). Target *selection* does not look at the flag, so a hostile fighter re-acquires the player the next frame and **keeps chasing / circling it without firing** (the ±8000 break-off still applies).
- **Turrets and sentry guns don't rotate toward it** (`PlayerTurret::handleTurret / handleSentryGun` 0x182e5a / 0x182e24) and so don't fire.
- **Sleeping NPCs (state 5) don't wake** for a cloaked target (the ±50000 wake test requires `!target.untargetable`).
- A campaign `LevelScript` ambush trigger (0x16d2a2) waits while the player is cloaked or farther than 49999.
- **Bullets already in flight still hit** (`Gun::calcCharacterCollision` ignores the flag), collisions still happen, and friendly/neutral NPCs' stray fire still lands (×0.2).
- The player can lock, fire and use missiles normally while cloaked; the radar and HUD are unchanged.

### 1.6 Visuals (v shader, a look)

- Shader type 0xe = `BumpShaderCloak` (engine): the normal lit bump shading plus `s_texture[2]` = a dissolve map (**`Textures/main/fx/cloak_map.png`**, a), `s_texture_base` = the refraction FBO (screen copy). Pixels whose `cloakMap.r − 0.025 < u_AnimValue` show the screen behind, offset by the normal map (`gl_FragCoord.x + n.x·100·sin(u_CloakRate)`, `y + n.y·75·cos(u_CloakRate)`) with a light-blue edge `(0.6, 0.8, 1.0)·step(u_AnimValue − 0.05, cloakMap.r)`. `u_AnimValue` 0 → 0.5 blends the opaque hull into the dissolving one (×4), 0.5 → 0.75 blends into pure refraction: at full cloak the ship is an **invisible, wobbling glass silhouette** (heat-haze look). Fade in / out 2000 ms each.
- The lights / engine-glow meshes fade to alpha 50/255 and the engine glow is hidden between 25 % and 100 %; the exhaust trail particles turn dark grey.
- Sound 30 `Cloak_02` (`SFX_SPACE/Cloak_02.ogg`) on engage and on disengage (2D).

### 1.7 HUD (v)

- **Charge bar** (while charging, `Hud+0x216`): the same bar as the Khador Drive charge (`Hud::draw` 0x1933f6): frame 0x53a (`gof2_interface_iphone4.png` [705, 1259, 408, 69]) centred at `(w/2, layout+0x1e8 + 2·layout(+0x37e))`, fill 0x539 ([605, 1610, 388, 14]) drawn from the centre outward with half-width `min(1, rate·1.05)·194`, `rate = phaseTimer / chargeTime`; text **317 "Cloak charging"** centred under it (y + 2.5·fill height). (Drive: 318 "Drive charging".)
- **Messages**: "-N t Energy Cells" (event 0x1e, white) on paying, **316 "Cloak ready"** (event 0x2e) when the cooldown ends; the cooldown and the cloaked state have no bar.
- **Ready flash**: when the cloak becomes available again (not cloaked, not recharging, `Hud+0x412` flips), the HUD menu button (0x4ba normal / 0x4bb highlighted, `gof2_interface2_ipad_large.png` [239, 1214, 125, 78] / [112, 1214, 125, 78]) flashes for 2000 ms (highlighted one frame every 80 ms). Not at level start.

### 1.8 Statistic and medal (v)

`Status+0xc0` (int64 ms cloaked, saved) → medal 19 **"Ninja"** = `+0xc0 / 60000` minutes, gold 5 / silver 3 / bronze 2 (`Achievements::checkForNewMedal`, lounge_ui.md §6). The remake's `Achievements.cs` keeps this counter at 0.

### 1.9 NPC cloak (race 10, for reference)

`PlayerFighter::cloak(ms, fade)` 0xf0aa4 / `handleCloaking` 0xf0b00 (npc_traffic_ai.md §5.5): Specters cloak for `9000 + nextInt(5000)` ms (50 % when panicking, else 30 % every 8 s), 2000 ms fades, exhaust hidden, `KIPlayer+0x70` set so the radar draws no marker and the player can't lock them; campaign scripts call `cloak(20000 / 18000 / 1000)`. Same shader.

---

## 2. Emergency system (item 185, sort 27 = 0x1b, attr 41 = 10000)

Extends ship_combat.md §2.5; all (v) unless marked.

| Function | Address |
|---|---|
| `PlayerEgo::setShip` (bubble setup) | 0xa6100 |
| `PlayerEgo::tryToStartEmergencySystem` | 0xad6f0 |
| `PlayerEgo::emergencySystemActive` (`+0x30c > 0`) | 0xad774 |
| `PlayerEgo::update` (bubble) | 0xaa996-0xaaab0 |
| `MGame::gameOverCheck` | 0x1b0d04 |
| `Ship::hasEmergencySystem` (`Ship+0x5c`, set by `refreshValue` case 0x1b) | 0x1a3a20 |

- **Setup** (each level, `setShip`): with a sort-27 item mounted: bubble geometry = mesh **14374 `v_shield`** (`Models/valkyrie/fx/v_shield.fbx`, material 27150 lit, `v_shield_noise` + `v_shield_normal`), duration `+0x310` = attr 41, offset `+0x314` = the ship model's bounding centre (transform +0xd4), base scale `+0x320` = bounding radius (transform +0xe0) / 500 + 0.1.
- **Trigger**: `MGame::gameOverCheck` every frame while not game over: `hull < 1 → tryToStartEmergencySystem()`; returns early (no death) when it fires:

```
if bubble exists and timer(+0x30c) == 0 and hull < 2:
    hull = 1; timer = attr41; Player::setVulnerable(false)
    Ship::removeEquipment(the sort-27 item)          // consumed for good (the saved ship loses it at the next dock)
    play 1115 (0x45b, DLC_SFX/Invincibility_01, name-matched)
```

  Shield and armor stay at 0; only the hull is set to 1. It fires once per item (the timer is never reset to 0 while the bubble object lives, and the item is gone).
- **While active** (`update`, timer > 0): `setVulnerable(false)` every frame (no damage from guns, collisions, bombs; EMP n/a), timer −= dt; bubble matrix = ship matrix, translated by R·offset; UV/anim value `mesh+0x24 += dt·0.001`; scale = base · f with `f = (dur − t)/(0.05·dur)` in the first 5 % (grow in), `t/(0.05·dur)` in the last 5 % (shrink), else 1. The player keeps full control and can fire; shield regen and repair bots keep running (so the hull can climb back).
- **End** (timer < 1): bubble deleted, `setVulnerable(true)`, stop 1115, `Status+0x13c = 0`.
- **HUD**: no bar, no text. The Khador Drive entry of the HUD menu is disabled (half-transparent) while it runs (`Hud::initHudMenu(0)`).
- **Medal 43 "Grave Riser"**: `Level::enemyDied` 0xd3f98: every kill while `emergencySystemActive` increments `Status+0x13c`; ≥ 5 (gold only, threshold table 0x259a64) → medal event (`Hud::hudEventMedal(0x2b)`). The counter resets when the bubble ends, so 5 kills within one 10 s bubble.
- Not re-armed by docking: buy a new item 185.

---

## 3. Other equipment

### 3.1 Time Extender (item 184 Rhoda Vortex, sort 26 = 0x1a; attr 42 = 15000, attr 43 = 30000) (v)

| Function | Address | Role |
|---|---|---|
| `MGame::OnInitialize` | 0x1a6ebc (0x1a7300) | `MGame+0x16c` = attr 42 (duration), `+0x168` = attr 43 (cooldown), `Hud::setTimeExtender(true, false, true, false)` |
| `MGame::OnTouchBegin` | 0x1a838c (0x1a8660-0x1a8780) | the button (HUD key 0x100) toggles it |
| `MGame::OnUpdate` | 0x1ac778 (0x1acb60-0x1acc20) | timers, dt split |
| `Hud::setTimeExtender(show, flash, ready, active)` | 0x18f278 | `Hud+0` show, `+0x220` ready, `+0x221` active, flash 2000 ms / 80 ms |

- **Control**: the **fast-forward button's slot** (top-left pill 0x53f, `autopilot_travel.md` §4): outside autopilot /
  asteroid / docking approaches, and with no radio message showing, it draws the clock icon **0x543** (idle,
  `gof2_interface2_ipad_large.png` [1904, 489, 109, 109]) or **0x542** (active / pressed / flashing, [1390, 489, 109, 109])
  instead of the double arrow; tinted while not ready. In autopilot the same key is fast-forward.
- **State** `MGame+0x164`: 0 = ready; > 0 = running (ms left); < 0 = cooldown (counts down to −attr43).
- **Tap while ready**: `+0x164 = attr42`, `FModSound::setDownPitch(true)` (all sounds pitched down), sound **1120 (0x460)**
  (DLC, name-match `DLC_SFX/TimeShift_01b.ogg`, a), HUD active icon.
- **Tap while running**: `+0x164 = −1` (cooldown starts), pitch normal, sound **1119 (0x45f)** (end, unmapped).
- **Running** (`OnUpdate`, not while paused): `+0x164 −= dt`; each frame **world dt (`MGame+0x40`) = int(0.3·dt), player dt
  (`MGame+0x44`) = int(0.7·dt)**. `PlayerEgo::update` and `TargetFollowCamera::update` get the player dt; `Level::update`
  (NPCs, bullets, particles), the `LevelScript` mission clock and radio get the world dt, so **mission time limits are
  extended** (the item's name) and enemies move at 30 % while the player flies at 70 %. At 0: pitch normal, sound 1119,
  cooldown starts.
- **Cooldown**: `+0x164` decreases by dt until below −attr43 → 0, `setTimeExtender(true, flash = true, ready = true, false)`:
  the icon flashes for 2000 ms. A LevelScript cinematic (`MGame::OnUpdate` 0x1af162) cancels a running extender.
- Per level: `MGame+0x164 = 0` at every level start (ready).

### 3.2 Weapon Mods (186 Nirai Overdrive, 187 Nirai Overcharge; sort 28 = 0x1c) (v)

`Ship::refreshValue` 0x1a33f4 case 0x1c: `Ship+0x54` fire-rate factor = `1 − attr39/100`, `Ship+0x58` damage factor =
`1 + attr40/100`; used by `Level::createPlayer` 0xbca00 (0xbcd40) for every player gun: reload × fire-rate factor, damage ×
damage factor (`weapons.md` §3). Overdrive: reload ×0.8, damage ×0.9. Overcharge: reload ×1.1, damage ×1.2. The remake's
`Gun` ignores both (add to the player's `WeaponSystem` gun setup).

### 3.3 Signatures (189-192, sort 29 = 0x1d) (v)

- `Ship::refreshValue` case 0x1d: `Ship+0x60` = item − 189 (0 Terran, 1 Vossk, 2 Nivelian, 3 Midorian; −1 none) →
  `Standing::setPlayerSignatureRace` 0x142898 (`Standing+4`).
- `Standing::isEnemy / isFriend` 0x1428ee / 0x142964 with signature S ≥ 0: **only** the rival of S (`[1,0,3,2][S]`) is an
  enemy, only S is a friend, the other two races are **neutral whatever the standing** (the axes aren't read at all).
  Pirates (8) / Void (9) stay hostile (their flags don't use `Standing`). NPC hostility, radar colours, combat music and
  the docking fine (§7) all follow automatically, since they call `isEnemy/isFriend`.
- **Loss** (`Player::damage` 0xafa70, friendly fire on a system-race / attack-race ship, `npc_traffic_ai.md` §4.5): past
  33 % (10 % hc) of that ship's hull when the ship's race is S, and again at 50 % (25 % hc) for races < 4 and not Wanted:
  the signature item is removed from the ship, `setPlayerSignatureRace(−1)`, `applyDelict(S, 100)` (doubled hc), HUD
  event 0x1f **324 "Signature invalid"** (red). No other way to lose it (no scans), no effect on stations' menus.
- Standing's `getStandingRate` is unaffected (the Status window still shows the real axes).
- Pirate kills with a signature don't give the +1 toward the system race (`npc_traffic_ai.md` §4.1).

### 3.4 Repair beam (207 Nirai SPP-C1, 208 Nirai SPP-M50; sort 37 = 0x25) and Transfusion beam (222 Crimson Drain, 223 Pandora Leech; sort 41 = 0x29) (v)

`RepairBeam(item, sort)` 0xb3fb8 / `update(dt, radar, level, hud)` 0xb41c4 / `render` 0xb49dc; built in
`PlayerEgo::setShip` 0xa6100 (one object per mounted sort, both may coexist, `PlayerEgo+0x1b8`); fully **automatic**, no
button, no HUD element.

| Item | attr 53 range (units) | attr 54 rate | attr 55 beams | per-beam effect |
|---|---|---|---|---|
| 207 Nirai SPP-C1 | 15000 | 60 | 1 | heal 0.018 HP/ms (18 HP/s) |
| 208 Nirai SPP-M50 | 60000 | 100 | 3 | heal 0.03 HP/ms (30 HP/s) |
| 222 Crimson Drain | 20000 | 50 | 1 | drain 0.005 HP/ms (5/s) + player shield +0.005/ms |
| 223 Pandora Leech | 10000 | 100 | 3 | drain 0.01 HP/ms (10/s) + shield +0.01/ms |

```
update: retarget timer -= dt; when < 0 (every 2500 ms): clear all slots; for each live, not dying KIPlayer of the level:
    repair:      friend (Player+0x5d) and hull < max and |ship - player| < attr53  -> free slot, else replace the slot
                 holding the healthiest ship that is healthier than this one (keeps the most damaged)
    transfusion: KIPlayer+0x70 == 0 (not cloaked), hostile (Player+0x5c), player's shield < 100 % and a shield (sort 9)
                 mounted, within attr53 -> same slot rule
per frame, per filled slot: beam mesh (repair 19092 sn_projectile_207_anim_add, transfusion 19093
    sn_projectile_222_anim_add) placed at the player, pointed at the target, scaled to the distance (origin offset along
    dir/up for ships 44 / 49)
    repair:      target.heal(dt * 0.03 * attr54 / 100)                        // Player::heal: fractional accumulator, hull only
    transfusion: acc += dt * 0.01 * attr54 / 100; per whole point target.damage(1, byNpc=false)   // counts as player damage
                 player.regenerateShield(dt * 0.01 * attr54 / 100)            // only while shield < 100 %
loop sound DAT_00252750[item]: 207 -> 2271 (0x8df), 208 -> 2272 (0x8e0), 222 -> 2267 (0x8db), 223 -> 2268 (0x8dc)
    (DLC2, name-match: Nirai_SPP_C1_2 / Nirai_SPP_M50_2 / Crimso_Drain / Pandorra_Leech_01, a), 3D at the player,
    playing while any slot is filled, stopped when none or the player is dead
```

Repair targets = friendly NPCs (wingmen, friendly-standing police, always-friend mission ships); never the player. The
transfusion's damage goes through `Player::damage(1, false)`: kill credit and standing like a gun kill (targets are
hostile, so no friendly-fire effects).

### 3.5 Shield Injector (227 Phoenix SIS, sort 43 = 0x2b; attr 59 = 30) (v, completes ship_combat.md §2.2)

`PlayerEgo+0x39a` = injector mounted (constructor), `+0x399` = injecting. `PlayerEgo::update` 0xa8f4e-0xa9136:
`!injecting and shield < 1 and cargo holds ≥ attr59 of item 202 Blue Plasma` → remove them, injecting = 1, play **2258**
(0x8d2, name-match `DLC2_SFX/PlasmaInjector_Init_02`, a) + **2257** (0x8d1, loop `PlasmaInjector_Loop_03`, 3D at
the ship, FMOD parameter 0 = shield/max), HUD event 0x2f "-30t Blue Plasma" (red; clears the queue). While injecting:
`shield = int(shield + max(dt·0.15, 1))` per frame (≈150 shield/s) until full → play **2259** (0x8d3, `PlasmaInjector_End_01`),
stop 2257, injecting = 0. Retriggers every time the shield hits 0 while plasma lasts.

### 3.6 Gamma shield (205 Gamma Shield I attr 52 = 40, 206 Gamma Shield II attr 52 = 60; sort 38 = 0x26) (v)

- **Gamma pool** `Player+0xb8` (float 0..100; `setGammaHP` clamps to 100 unless 9999999). Saved in `Status+0x68` by
  docking / jumping (`MGame::dockEvent`), restored by `MGame::OnInitialize`; set to 100 in any orbit with no gamma damage.
- **Drain** (`Level::update` 0xd6124): `rate = Status::getGammaRayDamagePerSecond(station, campaign)` 0xba160: stations
  109-113 (the supernova system) only: campaign < 106: 0.7 / 0.4 / 0.4 / 0.3 / 0.2 per s; until `Status+0x1e8` ≥ 158:
  3 / 2 / 1 / 0.5 / 0.3; afterwards 1.0 at 109 only. With a gamma shield: `rate · (100 − attr52)/100` (Particle Shield 225
  has attr 52 = 0: no effect). `Player::damageGamma(dt · rate / 1000)` (only while vulnerable and active; sets `+0x67`).
- **Crossing below 15** → HUD event 0x2c **3201 "Warning: Gamma shield low"** (red).
- **At 0**: `PlayerEgo::update` 0xa9fa6: `hull = 0` (instant death) unless docking / jumping flags `+0x1ee` / `+0x1ec`.
- **HUD**: third status row (ship_combat.md §7.6: icon 0x1f59, frame 0x1f5a, fill 0x1f5b `gamma/100·248`) in supernova
  systems.
- **Visual/sound with a gamma shield in the supernova system/orbit** (`PlayerEgo::PlayerEgo` 0xa5d8c): child geometry
  of meshes **18802 `sn_ship_blaze_glow_anim_add`** + **18803 `sn_ship_blaze_flames_anim_add`** around the ship (`+0x34`,
  shown `+0x38`); loop **2260 (0x8d4)** for item 205 / **2261 (0x8d5)** for 206 (name-match `DLC2_SFX/Gamma_Shield_01 / _03`,
  a), 3D at the ship; stopped on death. `PlayerEgo+0x3c` (collision radius?) = model radius ×1.75 in supernova systems.

### 3.7 Spectral filters (196 SA-1, 219 ST-X, 220 Omega; sort 33 = 0x21; attrs 57 / 58) (brief, a)

Only read in `Radar::draw` 0x1554fc (0x1570ec) for `PlayerGasCloud`s (the supernova plasma clouds harvested by the plasma
collector turrets 198-200, `PlayerGasCloud::explode` reads their attr 56): with a filter mounted the clouds' sparks are
tracked; attr 57 = 1 (ST-X, Omega) makes live clouds radar targets (`Radar::update`, lock flags), attr 58 = 1 (Omega)
also draws their marker image (`Radar+0xc0`) when not locked. No combat effect. Part of the unbuilt Supernova content.

---

## 4. EMP effects

### 4.1 EMP-disabled NPC (v)

- `Player::damageEmp` → at 0 points `Player+0x68 = 1` (ship_combat.md §2.4): recovery linear over 15000 ms (45000 fixed
  objects), standing −2 (`applyDisable`), medal 42 "Jammer" counter (gold 15).
- `PlayerFighter::update` (0xf3138): `KIPlayer+0x20` mirrors the flag. While disabled: **no forward movement** (the move
  step is skipped), but targeting, turning and **firing continue** (nothing gates `Player::shoot`; `npc_traffic_ai.md`
  uncertainty) (v for the code, a for the in-game result); the three spark systems **`+0x12c`, `+0x130` (record 17
  `SET_EMP_1`), `+0x134` (record 18 `SET_EMP_2`)** of the particle manager `Level+0x8c` emit (material 27260, additive,
  `Textures/main/fx/khador_jump.png` sprite region) and stop when recovered. Records live at `ParticleSettingsRef::cur +
  type·0x9c` (record 16 `SET_EMP` precedes them; their field values are set in the `ParticleSettingsRef` constructor next to
  the `"SET_EMP_1"` / `"SET_EMP_2"` strings, not decoded here). Engine sound and exhaust are not changed. Freighters (`PlayerFixedObject`) stop moving too.
- **HUD** (ship_combat.md §7.2): near ships show the **EMP bar** 8 px under the hull bar while EMP < max (frame 0x4d8
  `gof2_interface2_ipad_large.png` [112, 2020, 114, 10], white fill 0x4d7 [1581, 89, 110, 6], width `EMP%·110`); no other
  marker change. A disabled ship can be tractor-locked like a crate to steal its cargo (§5.4 of ship_combat, standing −2).
- The remake's `NpcShip` already stops disabled ships; missing: the sparks, the EMP bar, cargo stealing.

### 4.2 EMP hits (v, weapons.md)

EMP weapons use the normal `Gun` path; `Gun::calcCharacterCollision` calls `Player::damageEmp(target, attr10)` next to
`damage(attr9)`. Impacts: the EMP blasters (16-18) use `impact_004_lookat_anim_add`, EMP rockets the rocket explosion;
EMP bombs (41-43) / Shock Blast (226: damage 140, EMP 80, radius attr 14 = 80000) are `BombGun` area hits with falloff
(`weapons.md` §6). No separate "EMP hit" flash on the target beyond the impact mesh.

### 4.3 The player and EMP (v)

The player's `Player` never gets `setEmpData` → 0 EMP points → `damageEmp` returns at once: **immune**. No NPC gun
targets the player with EMP anyway: the only NPC EMP gun is the wingmen's item-18 blaster (`Level::assignGuns`, reload
400, EMP 8), and wingmen never target the player; no Wanted pilot weapon carries attr 10 (`wanted.json`). No player
EMP HUD exists.

---

## 5. NPC missiles (v unless marked)

`Level::assignGuns` 0xcb638 gives NPCs a `RocketGun` only in these cases (free play: **only the Wanted ships**):

| Who | Gun | Homing | Damage | Speed / life / reload | Mesh |
|---|---|---|---|---|---|
| Wanted pilot flying ship 45-48 (Qyrr Myfft 45, Urr Sakant 46, Malon Sentendar 47, Heinrich Wickel 48; Supernova board) | extra secondary: item 31 G'liissk stats, sort 4 | no (straight) | `4 · base NPC damage` | 8 u/ms / 10000 / 3000 ms | 14240 (the G'liissk `rocket_explosive`, a) |
| Wanted pilot whose weapon's sort is 5 / 0x28 | replaces the primary | sort 5 yes, 0x28 cluster | base ×4 (Wanted) ×4 (rocket) = ×16 | 8 / 10000 / 3000 | `DAT_00252d1c[item]` |
| Campaign 0x91, ship 49 Scimitar | item 214 Shesha, sort 0x28 cluster | yes (0x28) | ×2 ×4 | 8 / 10000 / 3000 | 14240 |
| Campaign 0x9d / 0x9e, ship 49 | extra cluster gun item 214 next to its ×3 Berger laser | yes | ×4 | 8 / 10000 / 3000 | 14240 |

No Wanted pilot in `wanted.json` has a sort-5 / 0x28 weapon, so the second row never happens with the shipped data.
Launch sound: 84 (0x54) `Launch_Missile_Amour` is preloaded for the extra rocket guns (the item's own sound, 82 G'liissk,
per `weapons.md`, a); explosion = the rocket's impact (a).

- **When**: the secondary slot fires only through the Wanted slot toggle (`PlayerFighter+0x13c` switches 0/1 every
  20000 ms when a secondary exists, ship_combat.md §4.3), under the normal NPC fire gate (target within ±0.0076 of the nose
  and 35000 units per axis), one rocket per 3000 ms reload.
- **Homing** (`RocketGun::seekEnemy` 0x18bd70): target = the shooter's current AI enemy; from 1000 ms after launch,
  `vel = normalize(cur + (desired − cur)/(0.3·20))·speed` per frame (≈ 1/6 of the error per frame). Sort 4 flies straight.
- **Hit**: the normal cube test against the shooter's enemy list; damage through `Player::damage` like bullets (×0.2 from a
  non-hostile shooter); rockets coast past their lifetime like the player's (`weapons.md` §6, a for NPCs).
- **No warning** (no sound, no HUD, no lock alarm), **no countermeasures** (no flares / chaff items exist), and bullets
  can't shoot rockets down (gun target lists hold only ships, asteroids, gas clouds).

Remake: give `NpcShip` an optional second `Gun` (rocket profile) for the Wanted ships 45-48 when the Wanted board is
built; homing only if a campaign level needs clusters. Nothing needed for free-flight traffic.

---

## 6. Radio window with portraits

### 6.1 What gets a portrait (v)

Every `RadioMessage` draws the same window with a portrait; there is no text-only radio. Text-only HUD messages
(`Hud::hudEvent`, ship_combat.md §7.7) are a separate channel: cargo, locks, warnings, "Signature invalid", "Cloak
ready", "-N t Energy Cells" etc.

| Source | Speaker image id (`RadioMessage+0xc`) | Portrait | Name line (`1597 + image`) |
|---|---|---|---|
| Campaign scripts (`Level::createRadioMessages` 0xd0574) | the story speaker | descriptor `PTR 0x26447c[image]` (the remake: `Portrait.ShowSpeaker`, already done) | the speaker's name |
| Generic chatter (`Level::createRadioMessage(kind, race)` 0xd5568, only with no active mission; `npc_traffic_ai.md` §8): friendly fire 0 (426-428), alarm 1 (429-431), "He's back" 2 (445-447), pirate outpost 3 / 4 (435-440), pirate hints 5 / 6 (443 / 444), black market 9-0xd (449-455) | by race: 0 → **64**, 2 → **65**, 3 → **21**, 8 → **9**, else (1 Vossk, …) → **63** | 64 / 65 / 21 / 63 = a **random face** of that race (`ImageFactory::createChar(true, race)`: Terran 0 / Nivelian 2 / Midorian 3 / Vossk 1), new each message; 9 = fixed "Pirate Boss" descriptor | 1661 "Terran", 1662 "Nivelian", 1618 "Midorian", 1660 "Vossk", 1606 "Pirate Boss" |
| Wanted (0x10 attacked / 0x11 killed / 0x12 uncovered; tables 0x254270, 3151-3155, 0x2542fc + 3141-3146) | 10000 + wanted index | the Wanted pilot's portrait parts (`wanted.json portraitParts`) | `Wanted::getName()` |
| Alien speakers 19 / 56 | — | fixed | alien font for the text |

Voice: `Globals::getDialogueSoundId(text, tempAgent(race, male))` (voice events unmapped in the remake; generic chatter
has English/German lines in `GENERIC_eng/deu`, a).

### 6.2 Layout and timing (HD, v; dialogue_cutscenes.md §2.3)

- Box `Layout::drawBox(7, x = 540, y = layout+0x9c = 100, w = 840, h = max(lines·30, 200) + header + 10, name)`
  (0xe6ba8, case 7): tiled background **0x47e** (`gof2_interface_iphone4.png` [317, 417, 320, 320]) below the header,
  border corners **0x484** ([1737, 1309, 93, 93]) + edges **0x483** ([649, 1724, 960, 45]), drawn with colour
  `0xffffff2f` (alpha 47: translucent); header plate **0x474** ([317, 1340, 274, 60]) at (x, y) with the name at
  x + layout+0x28, vertically centred in the header (header height `layout+8`, ≈60 HD).
- Portrait: `ImageFactory::drawChar(parts, x + 5, y + header + 5, mirrored = false)` at native size (the same composition
  as the dialogue window, `dialogue_cutscenes.md` §1.3), full opacity.
- Text: wrapped to 670 px (`840 − 10 − 160`), at (x + layout+0x2d4 (= 160 HD) + 7, y + header + 7), line height 30, white.
- Timing: triggers only while no message shows; hidden for 2000 ms, then shown for `lines·2000 + 1500` ms, then 2000 ms
  gap; the voice plays on the first visible frame. Not modal, no tap interaction, no animation (appears / disappears).
  Blocks fast-forward; `Hud::draw` hides the fast-forward / time-extender button while it shows; not drawn during the
  launch / arrival camera.

### 6.3 Remake

Route `Traffic`'s generic chatter (now `ShowMessage`) into the existing radio box: a `Radio`-like queue for one-off lines
(speaker kind: race face / Pirate Boss / Wanted), portrait from `AgentGenerator`'s random face for the race
(`createChar`, the lounge's generic sets) shown with `Portrait.Show(descriptor)`, name from 1597 + image, duration
`lines·2000 + 1500` after a 2000 ms delay. Keep the HUD message channel for `hudEvent` texts.

---

## 7. Docking fine (v)

`ModStation::OnInitialize` 0xe8080 (0xe8c12-0xe8e00) when the station scene opens after docking; payment in
`ModStation::OnTouchEnd` 0xea4ec (0xeb0aa).

- **Skipped** when: station 101 / 100 / 108, the black-market system (Loma), campaign mission 0x30, stations with an active
  pirate base (they show the pirate dialogue 434 / 1609 instead; station 4 and 88 never count as pirate bases),
  `ModStation+0xd4` set (campaign landing exceptions: 120 at 98/100, 58 at 138, 126 at 120, 78 at 141, any supernova
  station, entering straight into the lounge), `+0x66`, `+0x5f` (another window open), `Status+0x108`.
- **Charged** when `Station::hasAttackedFriends()` (set by `alarmAllFriends` on the system race, `npc_traffic_ai.md` §4.5)
  **or** `Standing::isEnemy(systemRace)` (so a signature can cause or avoid it):

```
if isEnemy(systemRace):                                  // checked first
    axis = (race | 1) != 1 ? 1 : 0                       // 0 Terran/Vossk, 1 Nivelian/Midorian
    fine = int(|standing[axis]| / 100 * 2800) + nextInt(200) - 100       // ~1860..2900 at |70..100|
    text = 205 "Because of your bad reputation, the station's security inspector demands a bribe before you are
                allowed to dock.\r\n\r\nPay #C?"
else:                                                    // attacked friends only
    fine = Status::getLevel() * 150 + 1000               // rank 0..20: 1000..4000
    text = 206 "Your assault on local security forces has not been forgotten. The station's security inspector
                demands a bribe before you can dock.\r\n\r\nPay #C?"
hardcore: fine *= 10;  #C = formatted credits
ChoiceWindow(text) yes / no; ModStation+0x67 = fine pending (station menu blocked)
```

- **Yes** with credits ≥ fine: `changeCredits(−fine)`, `Station::setAttackedFriends(false)`, `enterStation()`, autosave.
  The standing is **not** changed, so an enemy-race station fines again on every docking.
- **Yes** without enough credits: "203 You need an additional #C." note (#C filled with the player's credits, as in the
  shop's version, a: the original passes `getCredits`), the fine stays pending: the player can only refuse.
- **No**: `Status::departStation` → straight back to space (launch), no penalty, the flag stays.
- Sounds: the ChoiceWindow's own (dialog 126). No fine for cargo (no illegal goods exist), none for docking without
  permission; the black-market toll (Loma, `Status+0x110/0x111`, radio 9-0xd) is a separate in-space mechanic
  (`npc_traffic_ai.md` §8).

Remake: `StationMenu` on scene start: compute as above (`Standing.IsEnemy(system race)`, `Session` attacked-friend
stations, `Session.Rank`), show a yes/no dialog (205/206), pay → clear the station's attacked flag and continue, no →
`Launch` without the 397 confirmation.

---

## 8. Other combat-relevant equipment not in the remake yet (brief)

Already implemented in the remake: steering nozzles (attr 28 agility in `FlightModel` H), boosters (attrs 25/26/27), repair bots, shields/armor, scanners' lock time (attr 29), tractor lock time (attr 24), drills, cabins, compression.

| Item / attr | Behaviour | Where |
|---|---|---|
| Tractor beam mode attr 23 (70 Kingfisher = 1, 194 Octopus = 2) | 1: any on-screen crate becomes the salvage target without the crosshair box; 2: any crate/disabled ship, even off screen (ship_combat.md §5.4) | `CombatRadar` |
| Scanner attr 31 (Ecoscan and better) | cargo readout of the locked ship (its loot) under the lock plate | `CombatView` |
| Scanner attr 30 (84 Ultrascan) | class-A asteroid markers (mining.md) | `Mining` / `MiningView` |
| EMP-disabled ships: steal cargo | tractor-lock a disabled ship (attr 24, ring after 500 ms), its cargo transfers, `applyStealCargo` −2 standing (ship_combat.md §2.4 / §5.4) | `CombatRadar`, `Standing` |
| Volatile cargo meter (`Player+0x60`) | shots +0.008, damage +0.065, asteroid hits +0.2, decays; loop 35 with the meter as parameter; ≥ 1 = explosion type 12 (ship_combat.md corrections) | `PlayerHealth` |
| Weapon mods 186 / 187 | reload / damage factors (§3.2) | `WeaponSystem` / `Gun` |
| Player turrets (sort 8 / 35), auto-turret, plasma collectors | not researched here | — |


---

## 9. Remake plan

| Class | Change |
|---|---|
| `Cloak` (new, plain C#) + `CloakController` (new MonoBehaviour on the player) | §1: states Idle / Charging / Cloaked / Cooldown with attrs 35 / 36 / 38 (item 95 stats for ships 44 / 49), cooldown 7000 / 12000 by `Settings` hardcore, energy-cell payment via `Session.Cargo` (item 122), `Session` stat `CloakMs` (int64) for `Achievements` medal 19. Sets `PlayerHealth.Target.untargetable` while cloaked. Visual: a URP cloak shader (dissolve by `cloak_map.png` + screen-colour refraction from the opaque texture, blue edge) swapped onto the hull renderers, engine-glow child hidden 25-100 %, lights alpha → 50/255, exhaust trail colour grey `221 − 2.01·pct`; sound 30. |
| `Navigation` / `FlightHud` menu | a "Cloak" entry (item name, `Navigation.Kind.Cloak`) next to Khador Drive / Wingmen, disabled (with recharge fill) while cloaked / charging / recharging; "not enough cells" (583 + N) note; optional remake key (e.g. C / controller) as a shortcut. Reuse the Khador charge bar with text 317; messages "-N t Energy Cells", 316; menu-button flash 2 s. |
| `NpcShip` | fire gate: `untargetable` → stop firing but keep the target (the original keeps chasing); today `Valid()` drops untargetable targets from selection: change to the original's behaviour; sleepers: don't wake for an untargetable target; EMP-disabled: spark particles (`CombatAssets`: `SET_EMP_1/2` look, additive), keep firing. |
| `PlayerHealth` | emergency system (§2): mesh 14374 bubble prefab, 10 s invulnerable, consume item 185 from `Session.Equipment`, sound 1115, `Session` counter for medal 43; shield-injector (§3.5); gamma pool + death (§3.6) when the Supernova system exists. |
| `WeaponSystem` / `Gun` | weapon-mod factors (§3.2). |
| `TimeExtender` (new) + `FlightHud` | §3.1: the fast-forward slot shows the clock outside autopilot; two time scales: world ×0.3 / player ×0.7 (the remake uses global `Time.timeScale`: scale the world 0.3 and give the player's `ShipController` / `ChaseCamera` / `WeaponSystem` a 0.7/0.3 multiplier), audio pitch down (mixer or `AudioSource.pitch`), sounds 1120 / 1119, cooldown flash. |
| `Standing` | signature override (§3.3) from the mounted sort-29 item; loss on friendly fire (`NpcShip` friendly-fire path) with −100 and message 324. |
| `RepairBeam` (new MonoBehaviour on the player) | §3.4 for sorts 37 / 41: 2500 ms retarget, beam prefabs 19092 / 19093 stretched to the target, heal via `Hitpoints` hull (fractional accumulator), drain = `Target.Damage(1, byNpc: false)` per point + player shield regen, loop sounds 2271 / 2272 / 2267 / 2268. |
| `CombatView` | EMP bar under near ships' hull bars (0x4d8 / 0x4d7). |
| `CombatRadar` | tractor auto modes (attr 23), stealing cargo from EMP-disabled ships (−2 standing). |
| `Traffic` + `FlightHud` radio box | generic chatter → radio box with a random race face / Pirate Boss / Wanted portrait (§6.3). |
| `StationMenu` / `StationLevel` | docking fine on scene start (§7). |

---

## Uncertainties

1. **Cloak look**: `s_texture[2]` (texture unit 6) of `BumpShaderCloak` is assumed to be `Textures/main/fx/cloak_map.png`
   (the only cloak texture in the pack; the binding call wasn't traced). Which shader-anim channel (1 / 2) receives
   `t/2000` vs `t·0.001` was read from the call order (the float arguments are lost): assumed `u_AnimValue` = fade,
   `u_CloakRate` = time.
2. **Cloak "not enough cells" number**: the appended number comes from the mounted sort-21 item's attr 38; for an
   integrated cloak (no item) the decompile shows no value (0 or garbage).
3. The meaning of `AEGeometry+0x10` (tinted) and `+0x14` (tinted + hidden) in the ship group is inferred from `addChild`
   (the last two added children: lights / engine glow per the assembly rules).
4. `options[0x2c]` values other than 0.5 / 1.5 (cooldown 5000 / 9000) look unused.
5. **Time extender**: which of the two touch branches the Android keyboard / controller map to wasn't traced (the button
   is HUD key 0x100, the same key as fast-forward); the end sound 1119 and the "not ready" tint colour are unknown.
6. **Emergency system**: whether it also re-arms after a level reload with the item still mounted is moot (the item is
   removed at trigger); the bubble's UV-scroll field (`mesh+0x24`) is assumed to be a texture offset / anim time.
7. **Repair-beam slot replacement** logic is a best reading of the decompile (replace the slot whose ship has the lowest
   hull that is still above the candidate's).
8. **Spectral filter** attrs 57 / 58 were only skimmed (Supernova gas clouds).
9. **Gamma**: `Status+0x1e8` (the second threshold, 158) is a campaign-progress field not identified here; the gamma-shield
   loop sound mapping to `Gamma_Shield_01 / _03` is by name.
10. **Docking fine without enough credits**: the flow after the 203 note (whether the prompt reappears or only departing
    is possible) and the `#C` value (player credits vs the missing amount) are unclear.
11. **NPC rockets**: the Wanted extra rocket gun uses mesh 14240 and preloads sound 84; that 14240 is `rocket_explosive`
    and that the launch plays the item's sound (82) rather than 84 are assumptions.
12. **EMP-disabled fighters firing**: nothing in `PlayerFighter::update` or `Player::shoot` blocks it; not verified in play.
13. DLC sound ids (1115, 1119, 1120, 2257-2261, 2267-2272) are mapped by file name only; `fmod_event_ids.txt` covers 0-213.
