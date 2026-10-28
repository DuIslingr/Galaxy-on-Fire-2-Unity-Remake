# Multiplayer: shared world

Notes moved from `CLAUDE.md` (its index lists every notes file). Code comments citing `CLAUDE.md "<section>"` mean the section or bullet of that name here.

## Multiplayer (remake-only)

- **NPCs and the players** (the authority's `NpcShip` hooks, set by NetOrbit): every other player in the orbit is in an
  NPC's hit list (their ships block its shots; a non-hostile NPC's stray hit does 20 % like the local player's). An NPC
  is hostile to another player when its race always is (pirates, the Void, Specters), when a player of their squad shot it
  (`NpcShip.aggressors`, by client id; a remote player's hit is taken as an NPC's hit, so the authority's standing and
  kill count don't change), or when it is hostile to the authority's player and they are in its squad; a ship a squadmate
  shot is hostile to the authority's player too (`HostileToLocalBySquad`). It then attacks them (`UpdateTargeting`: after
  the local targets, kept while valid, hostile and in the box). The proxies share the aggressors and the always-hostile
  flag, so each player's markers show the hostility toward them; a takeover keeps the aggressors.
- **Orbits** (`NetOrbit` on each player's Space level): asteroids from the world seed per station (`NetGame.OrbitSeed`,
  `SpaceLevel.SpawnNetworkAsteroids`: `OrbitBuilder.SpawnAsteroids` only draws from `UnityEngine.Random`), the same field for
  everyone; destroyed ones are kept per station (NetState) and removed for a player arriving later, until nobody has flown
  in that orbit for 2 minutes (`NetState.AsteroidRespawnSeconds`, `RespawnEmptyAsteroidFields`, PR #118): then the whole
  field comes back (not at once, so docking to sell ore and launching again doesn't refill it). **Only
  the first player in an empty orbit builds its traffic** (`NetState.OrbitEmpty`, `SpaceLevel.NetAuthority`), so nobody
  sees ships appear out of nowhere; that player (the orbit authority) shows its ships and crates to the others as NetProxy /
  NetCrate objects it owns (spawned by the host on request, by index in `Traffic.Ships`). **The server says who runs each
  orbit** (2026-10-27, the user's request: no more election among the players; `NetState.UpdateOrbitRunners` every 0.25 s,
  written into the server-owned `NetPlayer.RunsOrbit`, read with `NetState.RunnerOf`): the runner stays while they fly
  there; else the next is a player whose game claims it (`NetPlayer.OrbitAuthority`: it built the traffic), the lowest
  client id first, else the lowest client id there. Each game follows it (`NetOrbit.FollowRunner`): of two that built the
  traffic at once the one not picked stands down (`SpaceLevel.DropNetAuthority`: its traffic vanishes, the other's is
  shown; the old 15 s window and lowest-id rule in the games are gone), the one picked takes over
  (`SpaceLevel.TakeOverNetAuthority`: relaunches and raider waves, `Traffic.SetPassive`). When the runner leaves (docks,
  jumps, disconnects: proxies survive their owner, `DontDestroyWithOwner`) the server hands its flying traffic ships to
  the new runner by ownership (`NetState.HandOver`: `NetworkObject.ChangeOwnership`, `NetProxy.MarkHandedOver`; only
  `NetProxy.HandOverable` ones: not junk, mission, fixed, turret, convoy, Most Wanted ships or wingmen, which the sweep
  removes after 5 s as before); the new runner rebuilds each where it flies (`NetOrbit.AdoptHandedOver`, `Traffic.Adopt`:
  model, race, group, hull, aggressors) and drives the same proxy on (`NetProxy.Bind`: its copy there torn down), so the
  others see no change; the old owner keeps it as a copy (`NetProxy.OnLostOwnership`). The server's checks of an orbit
  authority (`DefenseReportRpc`, `NetFactions.OnGarrisonKill`) read `RunsOrbit`. A player's own proxies of
  the orbit they are in, left from an earlier visit or spawned after their ship went, are dropped by their owner
  (`NetOrbit.DropOwnStale`; not those handed to them); those of the orbit they just left are not (the user's report
  2026-10-27: the leaving authority's next orbit despawned them all at its first scan, before the players still there
  could take them over, so every ship there vanished). Not tested with two games yet. The Kaamo siege: one per orbit
  (`KaamoSiege.Running`, `NetPlayer.SiegeRun`): another player with the siege to fight gets the follower view (the call,
  docking refused, the win with the runner's, `NetState.SiegeWonRpc`), builds it anew when alone there; two runners at
  once: the higher client id stands down. The other players' hostile ships count for the battle music and block
  fast-forward (`Traffic.HostileCount`).
- **Mining** (the asteroids are the shared seeded field, destruction synced): several players may drill the same asteroid
  at once; each drills their own minigame, and the ore is split between them (`NetPlayer.MiningAsteroid`, the field index;
  `Mining` divides the payout by the most players drilling it at once during the session, at least 1 t for some ore).
  The first to finish (or anyone shooting it) destroys it for all (`NetState.AsteroidGoneRpc` with the pilot's name): the
  others' drilling ends with "Mined out by X." (drilled out: `Mining.MiningOut` during its explosion) or "X destroyed the
  asteroid." (shot, rammed, a blast) and pays their share of what they drilled (`NetOrbit.DestroyedBy`); one still
  approaching or landing gets the same message and undocks. An asteroid a player lands on, sits on or drills stops
  spinning for everyone there (`NetPlayer.LandedAsteroid`, `NetOrbit.UpdateHeldAsteroids`), and spins on once nobody is
  on it (a miner's own undock leaves it still while another player is on it, `NetOrbit.OthersOn`).
- **NetProxy**: the ship's model by its Resources path (`NpcShip.ModelPath`), pose, race, standing, hull, hit cube, hidden,
  life (dying: no marker / lock; dead: the explosion at the ship's scale, the model hidden unless it leaves a wreck;
  flying again after a relaunch), marked and locked like traffic ships (`Target.NetShips`, `CombatRadar`, `CombatView`);
  another player's hit is applied to the owner's ship (`Target.RemoteDamage`, an RPC to the owner) as its player's hit.
  Dying / dead copies are not alive (shots pass them, like on the owner's side); junk is known from its id
  (`NetOrbit.JunkBase`); a jump (the spawn's default pose, a respawn) is no velocity (`NetSmoothing`). The host holding a
  disconnected player's proxies shows them like any other (viewer mode, `OnGainedOwnership`). Other players' wingmen are
  proxies too: the authority's NPCs attack them like their player (`NetOrbit.HostileToRemote`), and a player's wingmen
  attack the other games' hostile ships (their hits applied by that game).
- **Shots** (every gun, the turret, rockets / missiles / bombs / mines / beams): `Gun.Fired` / `Gun.Ignited` ->
  `NetShotSender` (a NetProxy's owner, the owner's NetPlayer) -> an RPC to the others (shots unreliable, blasts reliable)
  -> `NetShotMirror` (only where the shooter is shown): a Gun per weapon item with its GunRig and shot sound, the bullet
  injected at the sender's pose and life left (`Gun.Inject`), beams through the gun's beam path at the same target,
  homing toward the sender's lock (ids: `NetShots`), blasts as the fx's explosion. The mirrors stop on what they hit here
  and show the impact, but deal no damage (no handler on their Hit): the shooter's own game applies the hits. Their pools
  live in the scene: after a scene change the mirrors start over (`NetShotMirror.Refresh`). Deployed sentry guns' shots
  are mirrored too; a beam's auto-aim never picks a squadmate.
- **Equipment** (`NetPlayerEquipment`, part of `NetPlayer`): the sentry guns as copies in the others' games (a list every
  0.2 s: id, item, position, aim, hull, destroyed), attacked by the NPCs any game runs, their hits sent to the owner's
  sentry; the emergency system's bubble on the others' copy (invulnerable meanwhile); the max hull (`Target.netMaxHull`)
  and a squadmate's repair beam healing the ship (`HealUpRpc`; NPC copies: `NetProxy.HealUpRpc`). The repair and
  transfusion beams pick the other games' ships too (`RepairBeam`).
- **Crates** (`NetCrate`): the authority's crates are real `Crate`s for the others in that orbit (`remote`: no drift or
  expiry of their own; the race's model, the same loot), so their radar, markers and tractor work. One player gets it:
  the host keeps the claim (the first beam to start pulling, `Crate.PullStarted`), the others' copies are
  `claimedByOther` (the radar leaves them, a beam on one lets go), the claimant's capture waits for the confirmation
  (`captureBlocked`; the owner's own capture only waits for another player's claim); another player's capture
  (`Crate.CapturedHere`) has the owner remove its crate; the claim goes back when the claimant's beam lets go or they
  leave the orbit (`ReleaseRpc`, the host's check); an owner's beam that grabbed it before the spawn claims it then.
  Mission loot (`Crate.missionLoot`: dropped by mission ships and junk, the Hijacker's container) is out of reach for
  players outside the mission's team (the host refuses their claims). Cargo-steal crates aren't shared. The Hijacker's
  container never expires (also single player: Recovery / Salvage were stuck after 60 s).
- **Hangars** (`NetHangar`, HangarTraffic's guests by client id): the other players docked at the local player's station
  park on the NPC slots. Docking here from this orbit flies in (only when that player flew in themselves,
  `NetPlayer.ArrivedFlying`; a session start or a respawn at the station just appears on a pad),
  their take-off flies out (queued with the other flights: one in the air at a time, the local player's included); one
  already docked on arrival, or with the flights off, is simply parked; gone another way = gone at once; a new ship is
  swapped in place; the mounted turret shows on it (`NetPlayer.TurretItem`, `PlayerTurret.BuildStatic`, also on the ship
  in space). The hangar's NPC ships are the same for everyone docked there: the first player there runs them
  (`HangarTraffic.RunsNpcs`, `NetPlayer.HangarRun`) and sends each landing / take-off (`NetState.HangarNpcRpc`, NPC ids
  `Parked.key`: the slot, or (client id + 1) * 1000 + n for new ones); a player docking later starts with none and takes
  the runner's (a snapshot, `HangarTraffic.ApplyNpcSnapshot`); when the runner leaves, the lowest client id there runs them
  on (the others take a new snapshot); two runners at once: the higher id stops. The NPC ships keep one pad free
  (`KeepOneFree`: they never land on the last one, and when a docking player takes it one takes off; a guest's landing
  waits for a pad instead of an NPC ship vanishing). With only players on the pads a new guest waits for a free one
  (still in the pilot list). In multiplayer the hangar keeps a HangarTraffic for the guests even without the NPC traffic.
- **Event ships that vanish** (`EventRunner.CountShips`): a batch counts its ships until each is seen dying or dead
  (`Batch.down`), not just the ones present: a player leaving the orbit right after the spawn unloads their traffic, and
  Pirate Hideout paid out in 13 s (a log of 2026-10-12). The batch keeps the orbits it was seen in, so the players leaving
  them still ends the event (`CheckEmpty`; a mission fails). A completion logs its time and the players' kills.
- **Shared shop stock** (`NetStock`): every station's items and dealer ships are one list for all players, kept by the
  host: made with the single-player rules (`Shop.GenerateItems` / `GenerateShips`) the first time anyone docks there and
  made again every 15 minutes (`NetStock.ResetSeconds`; no 3-station re-roll or re-docking nibble in sessions); rare
  goods (commodities with a max price of 5000+: Buskat, Vossk Organs, Implants...; a report: Buskat back at Sao Perula
  after one system) don't come back with it: each roll sets their target amount (0 if the roll has none), what is left
  is kept, and every 10 minutes a short row gets a third of its target back, empty to full in 30 minutes
  (`NetStock.Make` / `UpdateRare`); the clocks run per station from its first docking, and the list carries the seconds
  to the next re-roll and rare step (`"|reset|rare"`), shown in the hangar footer on the Shop tab as an estimate
  (`NetStock.RestockLeft`, `HangarWindow.UpdateRestock`: "Next shipment ~N min", "soon" in the last 90 s, "any moment"
  once due; PR #128); shipments, not a clock (the user's request): the list really changes after a delay drawn anew each
  time, 0.85..1.2 x the nominal 15 / 10 minutes (`NetStock.Shipment`, `Entry.due` / `rareDue`), while the list sends the
  nominal schedule, so a shipment comes a little early or late; a docking
  player's own list is replaced by it (items and ships in place, the bar's agents stay theirs); a trade (a unit bought /
  sold, several at once from Buy all / Sell all, a dealer row swapped, `Hangar`) goes to the host, which sends the list
  to everyone docked there (the open hangar
  window rebuilds, `HangarWindow.StockChanged`; during the blueprint view it waits, and an item new to the window gets its
  price on demand, `Hangar.PriceOf`). The host decides: a bought unit it no longer has is taken back and paid back
  (`NetStock.ItemRefused`), a dealer ship is reserved first (`NetStock.ReserveShip`); the docked list is empty until the
  host's arrives; lists are applied between frames (`NetStock.Flush`). The host's lists carry the stations' docking extras
  that aren't one player's (`NetStock.HostExtras`: Kappa's EMP GL I at free play, energy cells at 10 / 100 / 101). Not
  shared: the owned Kaamo Club's storage.
