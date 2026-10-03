// NetCommands.cs
// Chat commands: a line typed in the chat that starts with "/" runs here on this game instead of being sent (NetChat.Send).
// Each command says who may use it (`available`); /help lists the ones this player can run. Their answers are chat
// notices only this player sees. Typing "/" lists the matching commands over the chat line and Tab completes / cycles
// them, and a player name after the commands that take one (ChatView, Completions).
//   /help                      the commands this player can use
//   /players                   everyone in the session: where they are, their ship, squad, admin
//   /g <text>, /l <text>       one line to Global / Local without switching the channel
//   /w <player> <text>         a private message (the host passes it on to that player only, NetState.WhisperRpc)
//   /invite <player>           a squad invitation (docked at the same station, like the pilot list's Invite)
//   /leave                     leaves the squad
//   /netstats                  shows / hides the network stats over the HUD (NetStats)
//   /kick <player> [reason]    admins: drops a player (the host checks the rights again, NetState.KickRpc)
//   /admin, /unadmin <player>  the host: makes a player an admin for the session / takes it back (a dedicated server:
//                              its console's admin / unadmin)
// Admins: the host's own player always, else the players the host or the server console made admins (NetPlayer.IsAdmin,
// for the session only: names aren't verified, so nothing is remembered by name).
// Player names are matched whole and case-insensitively, the longest name the arguments start with ("Player 2 hi").

using System;
using System.Collections.Generic;
using System.Text;
using GoF2Remake.Data;
using Unity.Netcode;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetCommands
    {
        enum Arg { None, Text, Player, PlayerText }

        sealed class Command
        {
            public string name, usage = "";
            public Arg arg;
            public bool self;   // the player argument may be the player themselves
            public Func<string> description;
            public Func<bool> available;
            public Action<string> run;
        }

        /// <summary>One Tab completion: the whole line it writes, and the suggestion row's name and description.</summary>
        public struct Completion
        {
            public string line, label, description;
        }

        static bool Everyone() => true;

        static readonly Command[] Commands =
        {
            new Command { name = "help", available = Everyone, run = _ => Help(),
                description = () => X("mpCmdHelp", "lists the commands you can use") },
            new Command { name = "players", available = Everyone, run = _ => Players(),
                description = () => X("mpCmdPlayers", "everyone in the session: where they are, ship, squad") },
            new Command { name = "g", usage = "<text>", arg = Arg.Text, available = Everyone, run = a => Say(a, true),
                description = () => X("mpCmdGlobal", "sends one line to Global") },
            new Command { name = "l", usage = "<text>", arg = Arg.Text, available = Everyone, run = a => Say(a, false),
                description = () => X("mpCmdLocal", "sends one line to Local") },
            new Command { name = "w", usage = "<player> <text>", arg = Arg.PlayerText, available = Everyone, run = Whisper,
                description = () => X("mpCmdWhisper", "a private message to one player") },
            new Command { name = "invite", usage = "<player>", arg = Arg.Player, available = Everyone, run = Invite,
                description = () => X("mpCmdInvite", "invites a player docked here to your squad") },
            new Command { name = "leave", available = Everyone, run = _ => Leave(),
                description = () => X("mpCmdLeave", "leaves your squad") },
            new Command { name = "netstats", available = Everyone, run = _ => ToggleStats(),
                description = () => X("mpCmdNetstats", "shows or hides the network stats (ping, packet loss, data in / out)") },
            new Command { name = "kick", usage = "<player> [reason]", arg = Arg.PlayerText, available = () => LocalIsAdmin, run = Kick,
                description = () => X("mpCmdKick", "admins: removes a player from the session") },
            new Command { name = "admin", usage = "<player>", arg = Arg.Player, available = () => LocalIsHost, run = a => SetAdmin(a, true),
                description = () => X("mpCmdAdmin", "host: makes a player an admin for this session") },
            new Command { name = "unadmin", usage = "<player>", arg = Arg.Player, available = () => LocalIsHost, run = a => SetAdmin(a, false),
                description = () => X("mpCmdUnadmin", "host: takes a player's admin rights away") },
        };

        static string X(string key, string english) => Localization.Extra(key, english);

        static bool LocalIsHost => NetworkManager.Singleton != null && NetworkManager.Singleton.IsHost;

        /// <summary>This player may use the admin commands: the host, or made an admin by the host / the server console.</summary>
        public static bool LocalIsAdmin => LocalIsHost || (NetPlayer.Local != null && NetPlayer.Local.IsAdmin);

        /// <summary>Server: 'p' has admin rights (the host's own player, or made an admin).</summary>
        public static bool IsAdmin(NetPlayer p) =>
            p != null && (p.IsAdmin || (NetworkManager.Singleton != null && NetworkManager.Singleton.IsHost && p.OwnerClientId == NetworkManager.ServerClientId));

        static bool Ready => NetState.Instance != null && NetState.Instance.IsSpawned;

        // ---- running ----------------------------------------------------------------------------------------

        /// <summary>A chat line starting with "/": runs it (true = it was a command, nothing is sent).</summary>
        public static bool TryRun(string line)
        {
            if (string.IsNullOrEmpty(line) || line[0] != '/') return false;
            string body = line.Substring(1).Trim();
            int space = body.IndexOf(' ');
            string name = (space < 0 ? body : body.Substring(0, space)).ToLowerInvariant();
            string args = space < 0 ? "" : body.Substring(space + 1).Trim();
            var command = Array.Find(Commands, c => c.name == name && c.available());
            if (command == null)
                NetChat.Notice(string.Format(X("mpCmdUnknown", "Unknown command /{0}. Type /help for the commands you can use."), name));
            else if (command.arg != Arg.None && args.Length == 0)
                NetChat.Notice(Usage(command));
            else command.run(args);
            return true;
        }

        static string Usage(Command c) => $"/{c.name}{(c.usage.Length > 0 ? " " + c.usage : "")}";

        /// <summary>The player whose name 'args' starts with (whole name, any case, the longest one), the rest after it.</summary>
        static NetPlayer MatchPlayer(string args, out string rest)
        {
            NetPlayer best = null;
            rest = "";
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned) continue;
                string n = p.DisplayName;
                if (n.Length == 0 || !args.StartsWith(n, StringComparison.OrdinalIgnoreCase)) continue;
                if (args.Length > n.Length && args[n.Length] != ' ') continue;
                if (best == null || n.Length > best.DisplayName.Length) best = p;
            }
            if (best != null) rest = args.Substring(best.DisplayName.Length).Trim();
            return best;
        }

        /// <summary>The command's player argument, with a notice when there is none (or it is the player themselves).</summary>
        static NetPlayer TargetOf(Command c, string args, out string rest)
        {
            var p = MatchPlayer(args, out rest);
            if (p == null) { NetChat.Notice(string.Format(X("mpCmdNoPlayer", "No player \"{0}\". /players lists them."), args)); return null; }
            if (!c.self && p.IsOwner) { NetChat.Notice(X("mpCmdNotYourself", "Not on yourself.")); return null; }
            return p;
        }

        static Command Get(string name) => Array.Find(Commands, c => c.name == name);

        static void Help()
        {
            NetChat.Notice(X("mpCmdList", "Commands:"));
            foreach (var c in Commands)
                if (c.available()) NetChat.Notice($"{Usage(c)}: {c.description()}");
        }

        static void Players()
        {
            var sb = new StringBuilder();
            int n = 0;
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned) continue;
                n++;
                sb.Append('\n').Append(p.DisplayName);
                if (p.IsOwner) sb.Append(' ').Append(X("mpCmdYou", "(you)"));
                sb.Append(": ").Append(WhereText(p)).Append(", ").Append(UI.ItemInfo.ShipName(p.ShipIndex));
                if (p.SquadId != 0) sb.Append(", ").Append(NetSquad.Same(p, NetPlayer.Local) && !p.IsOwner ? X("mpCmdYourSquad", "your squad") : X("mpCmdInSquad", "in a squad"));
                if (IsAdminShown(p)) sb.Append(", ").Append(X("mpCmdAdminTag", "admin"));
            }
            NetChat.Notice(string.Format(X("mpCmdPlayerCount", "{0} player(s):"), n) + sb);
        }

        /// <summary>Admin as the other games see it: made an admin, or the host's player (client id 0 with a player host).</summary>
        static bool IsAdminShown(NetPlayer p) =>
            p.IsAdmin || (p.OwnerClientId == NetworkManager.ServerClientId && (NetState.Instance == null || !NetState.Instance.Dedicated));

        /// <summary>Where a player is, for /players (and the suggestions).</summary>
        public static string WhereText(NetPlayer p)
        {
            string station = DedicatedServer.StationName(p.Station);
            switch (p.Where)
            {
                case NetPlayer.Place.Space: return string.Format(X("mpWhereSpace", "in space at {0}"), station);
                case NetPlayer.Place.Hangar: return string.Format(X("mpWhereDocked", "docked at {0}"), station);
                case NetPlayer.Place.Departing: return string.Format(X("mpWhereDeparting", "taking off from {0}"), station);
                default: return X("mpWhereLoading", "loading");
            }
        }

        static void Say(string text, bool global)
        {
            text = NetChat.Clean(text);
            if (text.Length > 0 && Ready) NetState.Instance.SendChatRpc(text, global);
        }

        static void Whisper(string args)
        {
            var p = TargetOf(Get("w"), args, out string text);
            if (p == null) return;
            text = NetChat.Clean(text);
            if (text.Length == 0) { NetChat.Notice(Usage(Get("w"))); return; }
            if (Ready) NetState.Instance.WhisperRpc(p.OwnerClientId, text);
        }

        static void Invite(string args)
        {
            var p = TargetOf(Get("invite"), args, out _);
            var me = NetPlayer.Local;
            if (p == null || me == null) return;
            if (NetSquad.Same(p, me)) { NetChat.Notice(string.Format(X("mpCmdAlreadySquad", "{0} is already in your squad."), p.DisplayName)); return; }
            if (!me.InHangar || !p.InHangar || p.Station != me.Station)
            {
                NetChat.Notice(Localization.Extra("mpSquadHangarOnly", "Squads can only be formed while docked in the same hangar."));
                return;
            }
            NetSquad.InviteTo(p);
            NetChat.Notice(string.Format(X("mpCmdInvited", "Invitation sent to {0}."), p.DisplayName));
        }

        static void Leave()
        {
            if (!NetSquad.InSquad) { NetChat.Notice(X("mpCmdNoSquad", "You're not in a squad.")); return; }
            NetSquad.Leave();
        }

        static void Kick(string args)
        {
            var p = TargetOf(Get("kick"), args, out string reason);
            if (p != null && Ready) NetState.Instance.KickRpc(p.OwnerClientId, NetChat.Clean(reason));
        }

        static void SetAdmin(string args, bool on)
        {
            var p = TargetOf(Get(on ? "admin" : "unadmin"), args, out _);
            if (p != null && Ready) NetState.Instance.SetAdminRpc(p.OwnerClientId, on);
        }

        static void ToggleStats()
        {
            NetStats.Shown = !NetStats.Shown;
            NetChat.Notice(NetStats.Shown ? X("mpStatsOn", "Network stats on (/netstats hides them).") : X("mpStatsOff", "Network stats off."));
        }

        // ---- completion (ChatView) --------------------------------------------------------------------------

        /// <summary>What Tab can write for the line typed so far: the commands its name starts with ("/" alone: all), or after a
        /// command that takes a player, the players whose name starts with what follows it. Empty = nothing to complete.</summary>
        public static List<Completion> Completions(string line)
        {
            var list = new List<Completion>();
            if (string.IsNullOrEmpty(line) || line[0] != '/') return list;
            int space = line.IndexOf(' ');
            if (space < 0)
            {
                string prefix = line.Substring(1).ToLowerInvariant();
                foreach (var c in Commands)
                    if (c.available() && c.name.StartsWith(prefix, StringComparison.Ordinal))
                        list.Add(new Completion { line = "/" + c.name + (c.arg != Arg.None ? " " : ""), label = Usage(c), description = c.description() });
                return list;
            }
            var command = Get(line.Substring(1, space - 1).ToLowerInvariant());
            if (command == null || !command.available() || (command.arg != Arg.Player && command.arg != Arg.PlayerText)) return list;
            string typed = line.Substring(space + 1);
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned || (p.IsOwner && !command.self)) continue;
                string n = p.DisplayName;
                if (!n.StartsWith(typed, StringComparison.OrdinalIgnoreCase)) continue;
                list.Add(new Completion
                {
                    line = $"/{command.name} {n}{(command.arg == Arg.PlayerText ? " " : "")}",
                    label = n, description = WhereText(p),
                });
            }
            return list;
        }
    }
}
