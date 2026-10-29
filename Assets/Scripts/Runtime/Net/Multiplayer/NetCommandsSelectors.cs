// NetCommandsSelectors.cs
// NetCommands: player arguments: names, client ids and selectors (part of the partial NetCommands; its fields are in NetCommands.cs).

using System;
using System.Collections.Generic;
using System.Text;
using GoF2Remake.Data;
using Unity.Netcode;
using UnityEngine;
using GoF2Remake.Events;

namespace GoF2Remake.Multiplayer
{
    public static partial class NetCommands
    {
        /// <summary>The players the arguments start with (Minecraft-style): a selector, @a everyone, @s the issuer, @p the
        /// nearest other player (the same orbit by distance, else the same station, else anyone), @r a random other
        /// player; else a whole name (MatchPlayer) or a client id. A selector may carry a filter in brackets:
        /// [orbit=&lt;station&gt;] (a number, a name or "void") keeps the players in that orbit or docked at its station
        /// ("@alive[orbit=78]", "@r[orbit=Var Hastra]"). 'error' says why none.</summary>
        public static List<IPilot> FindTargets(string args, IPilot issuer, out string rest, out string error)
        {
            var list = new List<IPilot>();
            error = null;
            args = (args ?? "").Trim();
            int space = args.IndexOf(' ');
            string first = space < 0 ? args : args.Substring(0, space);
            rest = space < 0 ? "" : args.Substring(space + 1).Trim();
            Func<IPilot, bool> where = p => true;
            int open = args.StartsWith("@") ? args.IndexOf('[') : -1;
            if (open > 0 && (space < 0 || open < space))
            {
                int close = args.IndexOf(']', open);
                if (close < 0) { error = X("mpSelBracket", "A selector's [ needs its ]."); return list; }
                if (!SelectorFilter(args.Substring(open + 1, close - open - 1), out where, out error)) return list;
                first = args.Substring(0, open);
                rest = args.Substring(close + 1).Trim();
            }
            if (Scope != null && first.StartsWith("@"))
            {
                // A bar mission's event (EventRunner): its selectors only find its own players.
                var filter = where;
                var scope = Scope;
                where = p => filter(p) && scope(p);
            }
            if (first.Length > 2 && first[0] == '@')
            {
                // By state: everyone it holds for.
                Func<IPilot, bool> holds;
                switch (first.ToLowerInvariant())
                {
                    case "@alive": holds = p => p.InSpace && p.Hull > 0f; break;
                    case "@space": holds = p => p.InSpace; break;
                    case "@docked": holds = p => p.InHangar; break;
                    case "@dead": holds = p => p.InSpace && p.Hull <= 0f; break;
                    case "@survivors": holds = EventRunner.Survived; break;
                    case "@team": holds = p => true; break;   // the event's players (a mission's team: Scope)
                    default:
                        error = string.Format(X("mpSelUnknownMore", "Unknown selector {0}: @a, @s, @p, @r, @alive, @survivors, @team, @space, @docked, @dead."), first);
                        return list;
                }
                foreach (var p in EventHost.Pilots) if (p != null && p.IsSpawned && holds(p) && where(p)) list.Add(p);
                if (list.Count == 0) error = NobodyMatches;
                return list;
            }
            if (first.Length == 2 && first[0] == '@')
            {
                char k = char.ToLowerInvariant(first[1]);
                var others = new List<IPilot>();
                foreach (var p in EventHost.Pilots) if (p != null && p.IsSpawned && p != issuer && where(p)) others.Add(p);
                switch (k)
                {
                    case 'a':
                        foreach (var p in EventHost.Pilots) if (p != null && p.IsSpawned && where(p)) list.Add(p);
                        break;
                    case 's':
                        if (issuer == null) { error = X("mpSelNoSelf", "@s is the player typing the command: not for the console."); return list; }
                        if (where(issuer)) list.Add(issuer);
                        break;
                    case 'p':
                        if (issuer == null) { error = X("mpSelNoNearest", "@p is nearest to the player typing the command: not for the console."); return list; }
                        var near = Nearest(issuer, others);
                        if (near != null) list.Add(near);
                        break;
                    case 'r':
                        if (others.Count > 0) list.Add(others[UnityEngine.Random.Range(0, others.Count)]);
                        break;
                    default:
                        error = string.Format(X("mpSelUnknown", "Unknown selector {0}: @a everyone, @s yourself, @p the nearest player, @r a random player."), first);
                        return list;
                }
                if (list.Count == 0) error = NobodyMatches;
                return list;
            }
            var named = MatchPlayer(args, out rest);
            if (named == null && ulong.TryParse(first.TrimStart('#'), out ulong id) && (named = EventHost.Find(id)) != null)   // "5" or "#5"
                rest = space < 0 ? "" : args.Substring(space + 1).Trim();
            if (named != null) list.Add(named);
            else { rest = ""; error = NoPlayer(first.Length > 0 ? first : args); }
            return list;
        }
        /// <summary>FindTargets' error when the selector is fine but nobody matches (count() and points take it as none).</summary>
        public static string NobodyMatches => X("mpSelNobody", "No player matches that.");
        /// <summary>A selector's bracket filter: "orbit=&lt;station&gt;" (comma-separated, all must hold).</summary>
        static bool SelectorFilter(string text, out Func<IPilot, bool> where, out string error)
        {
            where = p => true;
            error = null;
            foreach (string part in text.Split(','))
            {
                int eq = part.IndexOf('=');
                string key = (eq < 0 ? part : part.Substring(0, eq)).Trim().ToLowerInvariant(), value = eq < 0 ? "" : part.Substring(eq + 1).Trim();
                if (key.Length == 0) continue;
                if (key == "orbit")
                {
                    if (!NetTeleport.ParseStation(value, out int station, out string left) || left.Length > 0)
                    {
                        error = string.Format(X("mpSelNoStation", "No station \"{0}\" (a number, a name or void)."), value);
                        return false;
                    }
                    var before = where;
                    where = p => before(p) && p.Station == station;
                    continue;
                }
                error = string.Format(X("mpSelFilter", "Unknown selector filter \"{0}\": [orbit=<station>]."), key);
                return false;
            }
            return true;
        }
        /// <summary>The one player the arguments start with (a selector that picks one, a name or a client id).</summary>
        public static IPilot FindTarget(string args, IPilot issuer, out string rest, out string error)
        {
            var list = FindTargets(args, issuer, out rest, out error);
            if (list.Count > 1) { error = X("mpSelOne", "Only one player here (not @a)."); return null; }
            return list.Count == 1 ? list[0] : null;
        }
        /// <summary>The other player nearest to 'from': in the same orbit by distance, else docked at the same station, else
        /// the first one.</summary>
        static IPilot Nearest(IPilot from, List<IPilot> others)
        {
            IPilot best = null;
            float bestD = float.MaxValue;
            foreach (var p in others)
            {
                float d = from.InSpace && p.InSpace && p.Station == from.Station ? (p.Position - from.Position).sqrMagnitude
                    : p.Station == from.Station ? 1e20f : 1e30f;
                if (d < bestD) { bestD = d; best = p; }
            }
            return best;
        }
        static string NoPlayer(string args) => string.Format(X("mpCmdNoPlayer", "No player \"{0}\". /players lists them."), args);
        /// <summary>Runs 'each' for every player the arguments name (the rest of the line passed on) and joins the answers.
        /// The issuer is left out of a selector's list; named alone, "Not on yourself." unless 'self'.</summary>
        static string ForEachTarget(string args, IPilot by, bool self, Func<IPilot, string, string> each)
        {
            var targets = FindTargets(args, by, out string rest, out string error);
            if (targets.Count == 0) return error;
            bool selector = args.TrimStart().StartsWith("@");
            var answers = new List<string>();
            foreach (var t in targets)
            {
                if (t == by && !self)
                {
                    if (!selector || targets.Count == 1) answers.Add(X("mpCmdNotYourself", "Not on yourself."));
                    continue;
                }
                string a = each(t, rest);
                if (!string.IsNullOrEmpty(a)) answers.Add(a);
            }
            return string.Join("\n", answers);
        }
        static string Players(IPilot by)
        {
            bool ids = by == null || IsAdmin(by);
            var sb = new StringBuilder();
            int n = 0;
            foreach (var p in EventHost.Pilots)
            {
                if (p == null || !p.IsSpawned) continue;
                n++;
                sb.Append('\n');
                if (ids) sb.Append('#').Append(p.OwnerClientId).Append(' ');
                sb.Append(p.DisplayName);
                if (p == by) sb.Append(' ').Append(X("mpCmdYou", "(you)"));
                sb.Append(": ").Append(WhereText(p)).Append(", ").Append(UI.ItemInfo.ShipName(p.ShipIndex));
                if (p.SquadId != 0) sb.Append(", ").Append(p != by && NetSquad.Same(p as NetPlayer, by as NetPlayer) ? X("mpCmdYourSquad", "your squad") : X("mpCmdInSquad", "in a squad"));
                if (IsAdmin(p)) sb.Append(", ").Append(X("mpCmdAdminTag", "admin"));
            }
            return n == 0 ? X("mpCmdNoPlayers", "No players online.") : string.Format(X("mpCmdPlayerCount", "{0} player(s):"), n) + sb;
        }
        /// <summary>Where a player is, for /players (and the suggestions).</summary>
        public static string WhereText(IPilot p)
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
        static string Say(string text, IPilot by, bool global)
        {
            text = NetChat.Clean(text);
            if (text.Length == 0) return Usage(Get(global ? "g" : "l"));
            NetState.Instance.Chat(by as NetPlayer, text, global);
            return "";
        }
        static string Whisper(string args, IPilot by) => ForEachTarget(args, by, false, (to, text) =>
        {
            text = NetChat.Clean(text);
            if (text.Length == 0) return Usage(Get("w"));
            NetState.Instance.Whisper(by as NetPlayer, to as NetPlayer, text);
            return "";
        });
        static string SquadSay(string text, IPilot by)
        {
            if (by.SquadId == 0) return X("mpCmdNoSquad", "You're not in a squad.");
            text = NetChat.Clean(text);
            if (text.Length == 0) return Usage(Get("s"));
            NetState.Instance.SquadChat(by as NetPlayer, text);
            return "";
        }
        static string Invite(string args, IPilot by) => ForEachTarget(args, by, false, (to, _) =>
        {
            if (NetSquad.Same(to as NetPlayer, by as NetPlayer)) return string.Format(X("mpCmdAlreadySquad", "{0} is already in your squad."), to.DisplayName);
            if (!by.InHangar || !to.InHangar || to.Station != by.Station)
                return string.Format(X("mpCmdInviteHangar", "{0}: squads can only be formed while docked in the same hangar."), to.DisplayName);
            NetState.Instance.Invite(by as NetPlayer, to as NetPlayer);
            return string.Format(X("mpCmdInvited", "Invitation sent to {0}."), to.DisplayName);
        });
        static string Leave(IPilot by)
        {
            if (by.SquadId == 0) return X("mpCmdNoSquad", "You're not in a squad.");
            NetState.Instance.LeaveSquad(by as NetPlayer);
            return "";
        }
        static string Kick(string args, IPilot by) => ForEachTarget(args, by, false, (to, reason) =>
        {
            string name = to.DisplayName;
            if (IsHostPlayer(to) || (to.IsAdmin && by != null && !IsHostPlayer(by)))
                return string.Format(X("mpKickRefusedName", "{0} can't be kicked."), name);
            reason = NetChat.Clean(reason);
            string message = by == null && reason.Length == 0 ? X("mpKicked", "The server removed you from the session.")
                : reason.Length > 0 ? string.Format(X("mpKickedBy", "{0} removed you from the session: {1}"), IssuerName(by), reason)
                : string.Format(X("mpKickedByNoReason", "{0} removed you from the session."), IssuerName(by));
            if (!NetGame.Kick(to.OwnerClientId, message)) return string.Format(X("mpKickRefusedName", "{0} can't be kicked."), name);
            Debug.Log($"Server: {IssuerName(by)} kicked {name} ({to.OwnerClientId}){(reason.Length > 0 ? ": " + reason : "")}");
            NetState.Instance.NoticeAll(string.Format(X("mpKickedNotice", "{0} was removed from the session by {1}."), name, IssuerName(by)));
            return "";
        });
        static string SetAdmin(string args, IPilot by, bool on) => ForEachTarget(args, by, false, (to, _) =>
        {
            NetState.Instance.SetAdmin(to as NetPlayer, on);   // logged there
            return string.Format(on ? X("mpAdminGranted", "{0} is now an admin.") : X("mpAdminRevoked", "{0} is no longer an admin."), to.DisplayName);
        });
    }
}
