![Galaxy on Fire 2 Remake main menu](.github/header.webp)

# Galaxy on Fire 2 Remake (Unity)

A remake of the 2010 space game *Galaxy on Fire 2* by FISHLABS in Unity 6, for Windows (also as a UWP app), Linux and
Android. It aims to be a faithful port of the original gameplay, including flight, combat, trading, mining, stations,
the bar and the whole story. It is built on the original assets and on game logic ported from the decompiled game code.
Downloads are on the [releases page](https://github.com/JoppieToppie/Galaxy-on-Fire-2-Unity-Remake/releases); each
release says how to install it.

**Status:** the main campaign, the Valkyrie add-on and the Supernova add-on can be played from start to end. The
Supernova opening and final battle have been rebuilt from the original scripts, but the add-on has not been fully played
through yet. Multiplayer is experimental. A build's version is the date and time of its release (for example
`2026.10.01.1200`), the same on every platform, shown in the main menu.

## Features

- **Story:** the full main campaign with the prologue, the Void and the ending, plus the Valkyrie and Supernova add-ons.
  Dialogue is voiced (English or German), with portraits, radio chatter and cutscenes.
- **Flight:** the original flight model and chase camera. The station orbits are rebuilt exactly like the original,
  with their skies, planets, suns, lens flare and asteroid fields. Travel covers the autopilot, planet jumps,
  fast-forward, the star map, jumpgates, the Khador Drive and the Void's wormhole.
- **Combat:** every weapon, including missiles, beams, EMP, mines, turrets, sentry guns, the Liberator and the other
  special weapons. NPC traffic and AI, capital ships, pirate bases, Specters and the Most Wanted criminals. Combat
  equipment: cloak, emergency system, time extender, repair beams and gamma shields.
- **Economy and stations:** hangars, shops and ship dealers, and the space lounge with bar agents and every
  freelance mission type. Also blueprints, wingmen, medals, the Kaamo Club and save games.
- **Mining:** asteroid mining with the drilling minigame, plus gas clouds, hacking and docking at objects.
- **Multiplayer (experimental):** a shared universe, online through a server browser or a join code, or over a local
  network. Players can host from the game or run a dedicated server. Players see each other in space and in the
  hangars, and can fight each other. Squads share bar missions and their rewards. Everyone shares the NPC traffic, the
  crates, the asteroids and the shop stock. Local and global chat.
- **Remake extras:**
  - Arrival and take-off flights in the hangar, animated dialogue text, and the original-style bloom as an option.
  - Four difficulties (Easy, Normal, Hard, Extreme) that can be changed during a game, and a choice between the PC
    and Android economies for a new game.
  - Other ships' engines like the player's (an option), upscaling (FSR 1, STP), photo mode and screenshots.
  - Discord Rich Presence on Windows: your Discord status shows what you are doing in the game.
  - A Dutch translation, and a choice between German and English voices.
  - Debug tools (Options > Gameplay): jump to any story step, cheats, give items, spawn ships and objects.
  - Export and import of all save games as one file (Options > Gameplay in the main menu), to move your games to
    another PC or phone. Importing checks the file first and replaces every existing save.
- **Controls and screens:** touch, tilt, keyboard and mouse, and controllers (shown with Xbox buttons), all rebindable.
  Gyro steering with a DualSense, DualShock 4 or Switch Pro Controller on Windows. Haptic feedback on controllers and
  Android phones (hits, collisions, explosions, weapons, boost, jumps and mining) with an intensity setting. Landscape
  screens from 4:3 up to 32:9, phones included.

## Getting started

1. Install **Unity 6000.7.0b2** (Unity 6.7) with Unity Hub. Add Android Build Support if you want phone builds.
2. Clone the repository with Git LFS installed. The assets are about 2.1 GB in LFS.
3. Open the project in Unity and open `Assets/Scenes/MainMenu.unity`, then press Play.

The scenes are `MainMenu` (build index 0), `Space` (the flight level) and `Station` (docked). The **GoF2** menu in the
Editor holds the asset build tools. The generated assets are already in the repository.

### Building

Always **switch the active build profile** (File > Build Profiles > Switch Profile) before building another platform.
URP chooses which shader variants to keep from the active platform. An Android build made while Windows was active
renders black, so the editor script `BuildTargetGuard` refuses such builds. `BuildVersionStamp` gives every build its
date and time as its version; for a release, set the Editor process's `GOF2_BUILD_VERSION` environment variable so all
platforms get the same one.

### Multiplayer

Multiplayer is experimental. Everyone in a session shares one universe: you see each other in space and in the hangars,
form squads, and fly bar missions together. Every player starts a fresh free-play game docked at Var Hastra, and
sessions don't touch your single-player saves. Only the **exact same game version** can play together, so everyone
needs the same release.

#### Joining a game

1. In the main menu, open **Multiplayer** and type your **pilot name** at the top.
2. The **server browser** lists the public games with their name, host, players (for example `4 / 16`) and version.
   It refreshes every 5 seconds. Click a game to join it.
   - A game tagged **PASSWORD** needs its password: type it in the **Password** field under the list first.
   - A game on another version shows "needs <version>" and can't be joined.
3. To join a game that isn't listed, type its **join code** (six letters or digits, like `QKJH9N`) in the field under
   the list and press **Join**. On a local network you can type the host's address instead (`192.168.1.20`, or
   `192.168.1.20:7778` for another port).

#### Hosting from the game

On the **Host a game** card, pick a mode:

- **Public:** online, and listed in the server browser under the **Game name** you choose.
- **Invite only:** online, but not listed. Friends join with your join code.
- **Local network:** for players on the same network (or a VPN like Hamachi or ZeroTier). The card lists your
  addresses (tap one to copy it) and the port, 7777 by default.

Every mode can have a **password** and a **Max players** limit (2 to 100, you included). **Debug menu** (Off by
default) decides whether the players may use the Debug menu (cheats, items, spawns) in your session. Press **Host**. In an online
game the join code is copied to your clipboard and shown under the station's system information, with a Copy button.
Online play goes through Unity Relay: no port forwarding, but it needs an internet connection. With a player host,
all traffic goes through the host's connection, so for big sessions a dedicated server is better.

#### Running a dedicated server

A dedicated server hosts a session without anyone playing on that machine. It uses the normal Windows or Linux
download; no extra files are needed.

**Windows**

1. Open `Start Dedicated Server.bat` in the game folder with a text editor (Notepad), and set:
   - `NAME`: the game's name in the server browser.
   - `PASSWORD`: leave it empty for none.
   - `MAXPLAYERS`: the player limit, at most 100.
   - `ALLOWDEBUG`: `1` lets the players use the Debug menu (cheats, items, spawns); `0` (the default) turns it off.
2. Save the file and double-click it. A console window opens; the game itself runs without a window and without sound.
3. The console shows the **join code**, and the game appears in everyone's server browser.

**Linux**

1. Edit `NAME`, `PASSWORD`, `MAXPLAYERS` and `ALLOWDEBUG` at the top of `start-server.sh` in the game folder.
2. Run it in a terminal: `sh start-server.sh`. The terminal shows the join code and the log.

**The console**

The console shows who joins and leaves, where each player is, and the chat. Only the server can run commands; players
can't. Type one and press Enter:

| Command | What it does |
|---|---|
| `help` | Lists the commands. |
| `status` | The join code (or port), uptime, players, world seed, whether the Debug menu is allowed. |
| `list` | The players: client id, name, where they are, ship, squad. |
| `say <text>` | A chat line to everyone, from "Server". |
| `kick <id or name> [reason]` | Drops a player; they see the reason. |
| `arenas` | The arena matches and queues. |
| `crews`, `crew disband <TAG>` | The crews; end one. |
| `profiles` | The player profiles: id, name, devices, worth, who is online. |
| `profile delete <id>` | Deletes a profile (not while it is online; its file is kept as `.bak`). |
| `stop` | Tells the players and shuts the server down. Ctrl+C or closing the window does the same. |

**Starting it by hand**

The launchers only start the game with these options, which you can also use yourself:

```
GoF2Remake.exe -batchmode -nographics -server -relay -name "My universe" -password secret -maxplayers 32
./GoF2Remake.x86_64 -batchmode -nographics -server -relay -name "My universe" -logFile -
```

| Option | Meaning |
|---|---|
| `-batchmode -nographics` | No window, no rendering, no sound. |
| `-server` | Run as a dedicated server. |
| `-relay` | Host online with a join code (Unity Relay). Without it, players join on the server machine's address. |
| `-name "..."` | The name in the server browser (online). |
| `-unlisted` | Keep the game out of the server browser; players join with the join code. |
| `-password X` | Players need this password to join. |
| `-maxplayers N` | The player limit, 2 to 100 (default 16). |
| `-allowdebug` | The players may use the Debug menu (cheats, items, spawns). Off without it. |
| `-port N` | The port for local network play (default 7777, UDP). |
| `-fps N` | The server's frame rate (default 60). |
| `-freepvp` | Players may fight each other anywhere, not only in arena matches. |
| `-claimcost N` | What a crew pays from its bank to claim a station (default 500 000). |
| `-maxclaims N` | Stations per crew (default 3). |
| `-claimdays N` | Days without a member docking before a claim is lost (default 14). |
| `-noprofiles` | Don't keep player profiles (every session starts fresh, like before). |
| `-maxprofiles N` | How many player profiles the server keeps (default 50). New devices past it play as guests. |
| `-maxearn N` | Without `-allowdebug`: how much a profile's worth may grow per minute online (default 1 000 000). |
| `-profiledir PATH` | Where the profiles are stored (default `ServerProfiles` in the game's data folder). |

Good to know:

- A local network server (without `-relay`) needs UDP port 7777 open in the firewall for the other players.
- The server keeps the shared world: the shop stock, squads, missions and chat. Each orbit's NPCs are run by the first
  player who arrives there, so the server itself needs very little CPU.
- Players on a different game version are turned away with a message saying which version the server runs.
- When the internet connection drops (a router restart), the server starts its game again by itself once it is back
  (tries after 5, 10, 20, 40 s, then every minute). Online it gets a new join code and is listed again; the players
  join again. An online server started without internet keeps trying the same way.

**Player profiles**

A dedicated server keeps each player's progress: credits, ship and its mods, equipment, cargo, the Kaamo Club and its
storage, and their squad. A player's game gets a secret key from the server on its first visit and signs in with it
every time after; the progress is saved when docking, every minute and when leaving. Players type these in the chat:

| Command | Meaning |
|---|---|
| `/link` | A 6-letter code for 5 minutes, to use the profile on another device. |
| `/link CODE` | On the other device: use the profile the code belongs to. `/link CODE force` if this device has progress of its own (it is deleted). |
| `/control` | Two devices of one profile online: the first one plays, the other watches from the station. This takes over once the playing one is docked. |
| `/profile` | The profile's id and devices. |

**Crews**

A crew is a lasting group of players on a server with profiles (squads stay the quick groups for flying together).
Its tag shows before its members' names.

| Command | Meaning |
|---|---|
| `/crew create TAG Name` | Start a crew: a tag of 2-4 letters or digits, then its name. |
| `/crew invite <pilot>` | Invite a pilot (leader and officers). They type `/crew join TAG` within 5 minutes. |
| `/crew leave`, `/crew kick <pilot>` | Leave, or remove a member (officers remove members, the leader anyone). |
| `/crew promote <pilot>`, `/crew demote <pilot>`, `/crew leader <pilot>` | Ranks (leader only). |
| `/crew info [TAG]`, `/crew list`, `/crew disband` | About a crew, all crews, end yours (leader). |
| `/crew deposit N`, `/crew withdraw N` | Put credits into the crew bank; take them out (leader and officers). |
| `/crew claim`, `/crew unclaim`, `/crew home` | Docked at a station: claim it for the crew (paid from the bank), give it up, or make it the crew's home (leader and officers). Members start and respawn at the home. |
| `/crew claims [TAG]` | A crew's stations. A station no member docks at for 14 days is lost. |
| `/c <text>` | Talk to your crew. |

**Arena matches**

Players can only fight each other in arena matches (unless the server runs with `-freepvp`). A match takes its players
from their station into a private copy of the Void's home system (empty, or with its Void fighters attacking everyone),
and back when it ends. Nothing is at stake: ships, equipment and ammo come back
as they were, and only the match's statistics are kept.

| Command | Meaning |
|---|---|
| `/duel <name> [voids]` | Challenge a pilot to a duel: first to 3 kills, or the most kills after 5 minutes. Both must be docked. Add `voids` to fight among the Void's own fighters. |
| `/accept`, `/decline` | Answer a challenge (within 60 seconds). |
| `/ffa [voids]` | Join the free-for-all queue (docked): it starts 30 seconds after a second pilot joins, or at once with 8. First to 15 kills, or the most after 10 minutes. `voids` joins the queue for matches with the Void fighters. |
| `/leave` | Leave the queue or the match (leaving a duel loses it). |
| `/arena` | The matches running and their scores. |
| `/top` | The arena leaderboard (needs player profiles). |

Without `-allowdebug` the server turns away progress that can't be right (worth growing faster than `-maxearn`, ships
nobody can own). The players' games still run the economy, so this isn't proof against a modified game.

## Controls (keyboard)

| Key | Action |
|---|---|
| Arrow keys | Steer |
| W | Boost |
| S | Brake (the engines stop while held) |
| `]` / `/` or the mouse wheel | Throttle |
| Space / left mouse | Primary weapons |
| R / right mouse | Secondary weapon |
| G | Switch secondary weapon |
| A / D | Strafe left / right |
| 1 / 3 | Roll left / right |
| 2 | Level out |
| F / Enter | Action (dock, autopilot, mine, jump) |
| Q | Autopilot menu |
| E | Actions menu (secondary weapons, wingmen, cloak, Khador Drive) |
| Tab | Fast-forward |
| T | Camera / turret view |
| V / K / C / X | Wingmen / Khador Drive / cloak / time extender |
| M or middle mouse | Toggle mouse steering |
| B | Chat (multiplayer) |
| F12 | Screenshot |
| Esc | Pause |

Every flight control can be rebound in Options > Controls (two keyboard / mouse keys and a controller button each).
Controllers and touch are fully supported. The in-game hints show the buttons for whichever input you last used.

## Project layout

```
Assets/Scripts/Runtime/   game code (flight, world, NPCs, UI, multiplayer)
Assets/Scripts/Editor/    import settings, asset and prefab builders, menu items
Assets/Resources/         game data (JSON), assembled prefabs, sky / HUD / combat assets
Assets/UI/                UI Toolkit screens (UXML / USS)
Reference/                decompiled original code, research notes and conversion tools
```

`CLAUDE.md` is the full technical documentation. It covers every system, the original functions it is based on and
the choices the remake made.

## Credits

**Galaxy on Fire 2 Remake** by JoppieToppie.

The remake is built on the **FULL HD version and modifications made by KiritoJPK**, thanks to the Galaxy on Fire 2™ and
4PDA community: <https://github.com/KiritoJPK/Galaxy-on-Fire-2-FULL-HD-Android>

© 2011 Designed and developed by FISHLABS Entertainment GmbH, powered by ABYSS® Game Engine. Galaxy on Fire 2™ and
ABYSS® are registered trademarks of FISHLABS Entertainment GmbH. All rights reserved. This is an unofficial fan project,
not affiliated with or endorsed by FISHLABS or Deep Silver.

Fonts: Inter (SIL Open Font License). Controller gyro: [JoyShockLibrary](https://github.com/JibbSmart/JoyShockLibrary)
by Julian Smart (MIT License). Built with Unity, the Universal Render Pipeline and Netcode for GameObjects.
