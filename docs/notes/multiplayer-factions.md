# Multiplayer: factions

Notes moved from `CLAUDE.md` (its index lists every notes file). Code comments citing `CLAUDE.md "<section>"` mean the section or bullet of that name here.

## Multiplayer (remake-only)

- **Factions** (`NetFactions`, a dedicated server with profiles; phase 1 of home systems / territory): the lasting player
  groups, kept by profile in `factions.json` beside the profiles (squads stay the session's quick fly-together groups).
  A faction: name (24), tag (2-4 letters / digits, unique; `NetPlayer.FactionTag`, server-written, `TaggedName` "[TAG] Name"
  on the lock plate and in chat), leader, officers, members (profile ids, at most 50), bank and home station (for the
  next phases). Chat commands (private answers): `/faction create TAG Name`, `invite <pilot>` (officers; 5 min),
  `join TAG`, `leave` (the leader only by handing over or as the last member), `kick <pilot>` (officers: members;
  the leader: officers too), `promote` / `demote <pilot>`, `leader <pilot>`, `disband` (leader), `info [TAG]`, `list`;
  `/f <text>` to the faction's online members. A deleted profile leaves its faction; a leaderless faction passes to its first
  officer, else first member; an empty one ends. Console: `factions`, `faction disband <TAG>`.
  Phase 2, territory (`NetFactionsClient` on the player's side): the **bank** (`/faction deposit N`: the server asks the
  player's game to pay, `ChargeRpc` / `ChargedRpc` with a server token; `/faction withdraw N`, officers: `GrantRpc`; both
  move the profile's recorded worth, `NetProfiles.AdjustWorth`, so the upload check fits them; and the credits in its
  saved game, `NetProfiles.MoveCredits`: a deposit, a toll or a trade's credits must be in the profile's last accepted upload,
  `SpendableCredits`, else refused and given back to the game (a game claiming credits it never had fed a faction bank 36
  billion while its own uploads were refused; closing the game before the next upload no longer gets a deposit back));
  **claims** (`/faction claim`, officers, docked there: `-claimcost` (500 000) from the
  bank, `-maxclaims` (3) per faction, not 108 or system 25; `/faction unclaim`, `/faction home`, `/faction claims [TAG]`; the first
  claim is the home; a claim no member docked at for `-claimdays` (14) lapses, `NetFactions.Tick` once a minute; a claim
  is announced to everyone); `NetState.Claims` ("station|TAG|Name|VAT" lines, a 4 KB FixedString) shows the holder on the
  star map (planet "[TAG] Name", system "Name [TAG]"), the station header's system line and the orbit information.
  **Home**: no longer a start or respawn point: signing out and in, or dying, was a free trip home (energy cells and time
  saved). Every pilot signs in docked at the station they last docked at (`SaveGame.ApplyProfile`: `lastDockedStation`
  beats the profile's `station`, which an upload in flight sets to the orbit) and respawns there (`FlightHud.LoadLastSave`;
  a siege defender still respawns at the besieged station). `ProfileHeaderRpc` still carries the home, unused.
  Disbanding frees the faction's claims (the bank is
  lost).
  Phase 3, contest and benefits: **sieges** (`/faction siege`, officers of another faction in the orbit or docked there:
  `-siegecost` (250 000) from the bank as the stake, one per faction, the faction needs room for a claim, not within 24 h of
  the station's last siege, not the defenders' home while they hold another station; announced, armed 10 min later). Armed,
  it waits until pilots of both factions are alive in that orbit's space at once (real players: NPCs never start it).
  Meanwhile the station defenders escalate (`NetOrbit.UpdateSiegeDefenders`, tag `SiegeDefenderTag`, in every orbit, also
  Thynome's and the others without traffic: 16 at level 3, +4 and +1 level every 6 h, at most 48 at level 5, guns x1.5 from
  level 4, the garrison's relation, back 30 s after each death, `NetFactions.DefenderCount` / `DefenderLevel`; frozen at the
  fight's start); the claim drains: a defender docking there halves its remaining lapse days, rounded up (15 -> 8 -> 4), 3 or
  fewer stay, never a reset (`HalveLapse`; the claim tick's refresh skips sieged claims; a respawn after dying in the fight
  isn't a dock), and a claim lapsing then goes to the attacker with the stake; the standoff clock: a side present while the
  other has a pilot online elsewhere adds to the absent side's standoff, 60 min = that side forfeits; no fight within 2 days
  of the arming = +1 day, at most 4 times, then the defenders keep it and the stake. The fight runs 15 min, the two factions
  may fire at each other there (`NetFactionsClient.SiegePvp` in `NetPlayer.PvpWith`): every pilot of a side destroyed in the
  orbit scores for the other side, a player's kill of the other side repairs the killer at once (`NetFactions.OnPilotKilled` from
  `NetState.DestroyedByRpc`: hull, shield, armor through the Heal order, a = 1), a destroyed defender respawns docked at
  that station (`NetFactionsClient.DefendsSiegeHere`
  in `FlightHud.LoadLastSave`), a side whose last pilot there left alive (docked, jumped, disconnected) and stays gone 60 s
  waves the white flag and loses; at the end more kills wins, a tie = held. The stake to the winner; called off with the
  stake back to the attacker: the claim given up, the defenders disbanding (`CallOff`). 24 h protection after a decided
  siege. A claim lapsing without a siege can't be claimed for 48 h (`FactionList.lapsed`). `NetState.Sieges` lines (phase 0
  announced / 1 armed / 2 fighting, seconds left, stake, garrison, station defenders and level, kills, days added),
  `/faction sieges`, console `sieges`; `TerritoryView`'s banner);
  **defence** (in a held orbit the fighters of the system's race treat the holder's members as friends and other factions'
  pilots as enemies unless they paid the toll this visit: `NpcShip.TerritoryToLocal`, `NetOrbit.HostileToRemote`,
  `NetFactionsClient.Relation`; pilots without a faction as always); **toll** (`-toll`, 10 000 credits, or `N%` = N % of
  the pilot's credits (`NetFactions.ParseToll` / `TollFor`, stored as -N; the pilot's game sends the amount, the server
  caps it at that share of the profile's worth); `TerritoryView` asks on
  arrival through `Traffic.Ask`, `NetFactionsClient.PayToll` -> `TollPaidRpc` (only from that orbit), the holder's bank,
  `NetPlayer.TollStation` for the others' NPCs; a toll the profile's saved game doesn't hold is refused: `TollRefusedRpc`
  gives the game its credits back and marks it unpaid again, `NetFactionsClient.OnTollRefused`: the game marks it paid
  as it sends it, so the holder's fighters spared a refused pilot until then); **trade cut** (`Hangar.Buy` through
  `NetFactionsClient.BuyPrice`: members -10 %, no VAT; the list shows the plain
  price); **VAT** (per claim, `Claim.vat`, 0-20 %, default 5, `/faction vat <rate> [station]` or the Faction tab's claim rows,
  officers): everyone else (other factions and factionless pilots) buys items and dealer ships at the list price + a tenth of
  the rate (`NetFactions.VatMarkup`: 20 % -> +2 %; ships through `Hangar.BuyShipPrice` / `NetFactionsClient.ShipBuyPrice`),
  the rate's share of the paid price goes to the holder's bank (`NetFactions.OnPurchase` from `StockItemRpc`, the price capped
  at the item's max with the markup; `OnShipBought` from `StockShipRpc`, the server's own ship price); selling pays no VAT;
  units players sold into the stock carry none when bought back (`NetStock` resale count, reset with each roll), so a
  buy-and-sell loop mints nothing; each stock roll keeps (100 - rate) % of every row and of the dealer ships
  (`NetStock.ThinForVat`); the claims line carries the rate (`NetState.Claims`: "station|TAG|Name|VAT"). **Garrison**
  (players' request: offline holders lost a station to one attacker in 5 minutes): `/faction garrison <ships 0-12> <level 1-5> [station]`
  or the Faction tab's claim rows (officers, not during the station's siege); upkeep 300 x ships x level a day from the
  bank (`NetFactions.GarrisonCost`, the first day when set, unpaid = disbanded; reset when the station is taken). In an
  armed siege the server counts it (`Siege.garrisonAlive`, out with `NetState.Sieges`' 7th / 8th fields), a dead one
  back after 90 s; the orbit authority flies that many (`NetOrbit.UpdateGarrison`, eventTag `NetOrbit.GarrisonTag`,
  system race, level 3+ strong fighters, hull x(1 + 0.5 (L - 1)), gun x(1 + 0.25 (L - 1)), no loot, swarming in front of
  the station; `NetFactionsClient.GarrisonRelation`: the attackers' enemy, the holders' friend) and reports each death
  (`NetState.GarrisonKillRpc`: the sender runs the orbit, at most 6 per 10 s); they jump out when the siege ends; the
  banner shows the count. Not yet: shared storage at the home. Not tested in a build yet.
  UI: the **multiplayer window** (`MultiplayerWindow`, code-built, Squad.uss buttons; in the station a "MULTIPLAYER" button in
  the top bar left of Menu; in flight its own button on the right under the HUD readout and the "Multiplayer window"
  binding, N (`FlightHud`: Esc / B / the binding close it, the flight controls and the mouse-steering cursor wait
  meanwhile, `Navigation.InputHalted`); under it in flight a Distress call / End the call button (in a squad in space,
  `MultiplayerWindow.UpdateSos`; or the unbound "Distress call" binding); these buttons and the squad window's panels
  never take the focus, so Space / Enter / a controller's A can't press them (its invitation popups do, below); the Squad
  tab has Distress call / End the call in space; **its own navigation** (`MultiplayerWindow.OnNavigate`, a trickle-down
  NavigationMoveEvent on the window): the neighbour on screen among its tabs, close button and the shown pane's controls
  (`NavItems` / `SpatialNav`, the body scrolled to it, scroll bars never focusable, `UiFocus.SkipScrollBars`), since the
  station menu walks its own buttons for the whole panel and now yields to an open window (`StationMenu.OnNavigate`:
  before, the arrows moved the menu behind it and the Squad tab's Accept could never be reached with keys or a
  controller); a navigation event only travels through what has the focus, so the window takes it when it opens with keys
  or a controller (`FocusesItself`, was a controller only) and the station's first press steps into it
  (`MultiplayerWindow.FocusInside` / `FocusFirstAny`); typing in one of its fields keeps left / right for the caret while
  up / down still step out of it (`TextFieldKeys.IsTyping`, not a blanket `NetChat.Typing`: the window opens on the Chat
  tab, whose line takes the focus by itself, and the keys were dead in the whole window); its text fields
  (`TextFieldKeys.Guard`) keep their typed keys (no menu navigation or submit, Esc drops the
  focus) and turn the game's keys off while focused (`NetChat.SetTyping`); a snapshot waits while a field has the focus
  or a pointer is down on the window (a rebuild under the finger dropped the pressed button and Android's keyboard);
  both lists scroll by mouse drag too (`DragScroll`) and the chat follows new
  lines only while at its end; the Admin tab also on a session without profiles for its host (master) and session admins
  (`NetModeration.RoleOfClient`): kick, mute, session admins, settings, announcements
  (`NetCommands.ModerateWithoutProfiles`); a dot when an invitation, a challenge or an unread chat line waits; Esc / B
  closes it, the station
  menu's keys wait while it is open). Tabs Chat (the whole chat: lines, Local / Global, the line, Send; Enter sends,
  "/" commands; built once so the line keeps focus and draft; `ChatView` hides meanwhile), Squad (invitations, members
  with where / distress and Help, Leave, the pilots docked here to Invite; distress itself is called in space), Faction,
  Arena, Profile, Admin. Every chat command is listed in /help everywhere (on a session without profiles the faction /
  profile / moderation ones answer that they need a dedicated server with profiles); `/squad [invite <p> | accept |
  decline | leave]` and `/sos` say why not when they can't. The tabs give
  every chat command as buttons and fields (faction create / join / bank / members by
  rank / invite / territory with Claim, Make home, Give up, Siege at the docked station / leave and disband asked
  twice; arena challenge, accept / decline, the Voids option, the free-for-all queue, matches, leaderboard; profile,
  take control, link codes). `NetPanel`: the window asks for a snapshot (`PanelRequestRpc`, every 2 s open, 6 s closed
  for the dot), the server fills a `NetPanel.State` (`NetProfiles` / `NetFactions` / `NetArena .FillPanel`) and sends it
  gzipped in chunks (`PanelChunkRpc`); buttons send the chat commands (`NetPanel.Command`) and the window shows the
  answering notice. The chat commands still work.
- **Faction stations on the planets** (`NavigationView`): in flight a neighbouring station's planet held by the player's
  faction (`NetFactionsClient.Owner`) gets a green orb before its name, red while its siege is declared or running;
  drawn as an element (no font glyph).
