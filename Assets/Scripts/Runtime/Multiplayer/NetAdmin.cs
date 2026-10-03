// NetAdmin.cs
// Remake multiplayer: the admin commands that act on players' games (NetCommands' table; the chat and the dedicated
// server's console alike). The server checks the rights and the arguments, then sends the order to each target's own game
// (NetState.SendAdmin, server-only), which applies it to its own ship and Session: the server holds no game state.
//   /kill [players]                         destroys their ships (in space; also through god mode)
//   /heal [players]                         hull, shield, armor and the gamma pool full
//   /give [players] <item> [amount] [mount] items into the hold (an item index or name; 1..1000, default 1); "mount" docked:
//                                           mounted like the hangar does (Cheats.GiveAndMount)
//   /credits [players] <amount>             credits added (negative: taken, never below 0)
//   /spawn [players] <ship | object> [race] [count] [enemy | friendly | neutral | standing] [at x y z]
//                                           NPC ships 400 m ahead of each player as their orbit's traffic (DebugSpawner):
//                                           a ship index or name, a race (terran, vossk, nivelian, midorian, pirate, void,
//                                           specter; default the ship's maker, else pirates), 1..10 of them, enemy by
//                                           default; neutral = neither side whatever the standings, until shot; standing =
//                                           by the race's standing; "at x y z": there in that player's orbit (game
//                                           coordinates, what /pos shows), else 400 m ahead of them; a name that is no
//                                           ship is an assembled object (assemblies.json: station_083_terran, ...) placed
//                                           as scenery, ahead of them (far enough out for its size) or there
//   /mute <players> [minutes], /unmute <players>   their chat and whispers dropped on the server (default: the session)
// The debug panel's tools (Cheats, PlayerHull, DebugSpawner), for one player:
//   /ship [players] <ship | own>            fly any hull of the Ships tab (a ship's number or name, the capital ships by
//                                           name; docked only the ownable ones), "own" back to the ship flown before
//   /ammo [players]                         every mounted secondary to 50
//   /reveal [players], /peace [players]     every system on the map; both standing axes neutral, no station grudges
//   /cheat [players] <flag> [on | off]      a debug toggle for the session (god, ammo, cooldown, boost, onehit, locks,
//                                           shopping, jumps; no on / off: toggled), whatever the session allows
//   /title [players] <text> [| subtitle] [for <seconds>]   a big title on their screens (NetScreen; 4 s by default;
//                                           "clear" takes it away)
//   /timer [players] <seconds | m:ss> [label]   a countdown at the top of their screens ("stop" takes it away)
// The players: names, client ids or selectors (@a @s @p @r, NetCommands.FindTargets); in the chat the issuer when none is
// named. Every order is logged on the server and the target gets a notice naming the admin.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.World;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetAdmin
    {
        public enum Order : byte { Kill = 1, Heal = 2, Give = 3, Credits = 4, Spawn = 5, Ship = 6, Ammo = 7, Reveal = 8, Peace = 9, Cheat = 10, Object = 11, Title = 12, Timer = 13 }

        const int MaxGive = 1000, MaxSpawn = 10, MaxCredits = 999999999;

        static string X(string key, string english) => Localization.Extra(key, english);

        // ---- mutes (server) ----------------------------------------------------------------------------------

        /// <summary>Server: muted client -> until when (unscaled time; infinity = the session).</summary>
        static readonly Dictionary<ulong, float> muted = new Dictionary<ulong, float>();

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => muted.Clear();

        /// <summary>Server: a new session (NetState spawned).</summary>
        internal static void Reset() => muted.Clear();

        /// <summary>Server: 'client' may not chat now; 'answer' tells them why.</summary>
        internal static bool IsMuted(ulong client, out string answer)
        {
            answer = null;
            if (!muted.TryGetValue(client, out float until)) return false;
            if (Time.unscaledTime >= until) { muted.Remove(client); return false; }
            answer = float.IsPositiveInfinity(until) ? X("mpMutedYou", "You are muted.")
                : string.Format(X("mpMutedYouFor", "You are muted for {0} more minute(s)."), Mathf.CeilToInt((until - Time.unscaledTime) / 60f));
            return true;
        }

        // ---- the commands (server) --------------------------------------------------------------------------

        /// <summary>The players the arguments start with, else (a chat issuer, 'playersOptional') the issuer and the whole
        /// line; runs 'each' and joins the answers. No arguments at all: the issuer.</summary>
        static string ForTargets(string args, NetPlayer by, bool playersOptional, Func<NetPlayer, string, string> each)
        {
            args = (args ?? "").Trim();
            List<NetPlayer> targets;
            string rest;
            if (args.Length == 0)
            {
                if (by == null) return X("mpAdmNamePlayers", "Name the players (a name, a client id, @a or @r).");
                targets = new List<NetPlayer> { by };
                rest = "";
            }
            else
            {
                targets = NetCommands.FindTargets(args, by, out rest, out string error);
                if (targets.Count == 0)
                {
                    if (!playersOptional || by == null || args.StartsWith("@")) return error;
                    targets = new List<NetPlayer> { by };   // "/give 85 3": the issuer
                    rest = args;
                }
            }
            var answers = new List<string>();
            foreach (var t in targets)
            {
                string a = each(t, rest);
                if (!string.IsNullOrEmpty(a)) answers.Add(a);
            }
            return string.Join("\n", answers);
        }

        static void Send(NetPlayer to, Order order, int a, int b, int c, NetPlayer by, string log, string text = null)
        {
            NetState.Instance.SendAdmin(to.OwnerClientId, order, a, b, c, text, NetCommands.IssuerName(by));
            Debug.Log($"Server: {NetCommands.IssuerName(by)} {log} ({to.DisplayName}, {to.OwnerClientId})");
        }

        static string NotInSpace(NetPlayer t) => string.Format(X("mpAdmNotInSpace", "{0} isn't in space."), t.DisplayName);

        public static string Kill(string args, NetPlayer by) => ForTargets(args, by, false, (t, _) =>
        {
            if (!t.InSpace) return NotInSpace(t);
            if (t.Hull <= 0f) return string.Format(X("mpAdmAlreadyDead", "{0} is already destroyed."), t.DisplayName);
            Send(t, Order.Kill, 0, 0, 0, by, "destroyed a ship");
            NetState.Instance.NoticeAll(string.Format(X("mpAdmKilledAll", "{0} was destroyed by {1}."), t.DisplayName, NetCommands.IssuerName(by)));
            return "";
        });

        public static string Heal(string args, NetPlayer by) => ForTargets(args, by, false, (t, _) =>
        {
            Send(t, Order.Heal, 0, 0, 0, by, "repaired a ship");
            return string.Format(X("mpAdmHealed", "Repaired {0}'s ship."), t.DisplayName);
        });

        /// <summary>/ammo, /reveal, /peace: one order without arguments.</summary>
        public static string Simple(string args, NetPlayer by, Order order) => ForTargets(args, by, false, (t, _) =>
        {
            Send(t, order, 0, 0, 0, by, order.ToString().ToLowerInvariant());
            switch (order)
            {
                case Order.Ammo: return string.Format(X("mpAdmAmmo", "{0}'s secondaries refilled."), t.DisplayName);
                case Order.Reveal: return string.Format(X("mpAdmReveal", "Every system revealed for {0}."), t.DisplayName);
                default: return string.Format(X("mpAdmPeace", "{0} is at peace with every race."), t.DisplayName);
            }
        });

        public static string Give(string args, NetPlayer by) => ForTargets(args, by, true, (t, rest) =>
        {
            rest = rest.Trim();
            bool mount = rest.EndsWith(" mount", StringComparison.OrdinalIgnoreCase);
            if (mount) rest = rest.Substring(0, rest.Length - 6).Trim();
            if (mount && !t.InHangar) return string.Format(X("mpAdmMountDocked", "{0} isn't docked: mounting works in a hangar."), t.DisplayName);
            if (!ParseAmount(ref rest, 1, MaxGive, out int amount)) return Usage("give");
            int item = FindItem(rest, out string error);
            if (item < 0) return error;
            Send(t, Order.Give, item, amount, mount ? 1 : 0, by, $"gave {amount} x item {item}{(mount ? " (mounted)" : "")}");
            return string.Format(X("mpAdmGave", "Gave {0} {1} x {2}."), t.DisplayName, amount, UI.ItemInfo.ItemName(item));
        });

        public static string Credits(string args, NetPlayer by) => ForTargets(args, by, true, (t, rest) =>
        {
            if (!int.TryParse(rest.Trim(), out int amount) || amount == 0) return Usage("credits");
            amount = Mathf.Clamp(amount, -MaxCredits, MaxCredits);
            Send(t, Order.Credits, amount, 0, 0, by, $"gave {amount} credits");
            return string.Format(amount > 0 ? X("mpAdmCreditsGiven", "Gave {0} {1} credits.") : X("mpAdmCreditsTaken", "Took {1} credits from {0}."),
                t.DisplayName, Math.Abs(amount));
        });

        public static string Spawn(string args, NetPlayer by) => ForTargets(args, by, true, (t, rest) =>
        {
            if (!t.InSpace) return NotInSpace(t);
            if (!TakeAt(ref rest, out string at)) return Usage("spawn");
            // From the end: the behaviour, the count and the race, in any order; the rest is the ship.
            var words = new List<string>(rest.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
            if (words.Count == 0) return Usage("spawn");
            var behaviour = DebugSpawner.Behaviour.Hostile;
            int count = 1, race = -1;
            while (words.Count > 1)
            {
                string w = words[words.Count - 1];
                var b = BehaviourWord(w);
                if (b.HasValue) behaviour = b.Value;
                else if (int.TryParse(w, out int n)) count = Mathf.Clamp(n, 1, MaxSpawn);
                else if (RaceWord(w) >= 0) race = RaceWord(w);
                else break;
                words.RemoveAt(words.Count - 1);
            }
            string spec = string.Join(" ", words);
            int ship = FindShip(spec, out string error);
            if (ship < 0)
            {
                // Not a ship: an assembled object (the whole name, before any words were taken as a race or a count).
                var asm = FindAssembly(rest.Trim(), out string objectError);
                if (asm == null) return ship == -2 ? error : objectError ?? error;
                Send(t, Order.Object, 0, 0, 0, by, $"spawned object {asm.name}{(at != null ? " at " + at : "")}", at != null ? asm.name + "@" + at : asm.name);
                return string.Format(X("mpAdmObject", "Spawning {0} at {1}."), asm.name, t.DisplayName);
            }
            if (race < 0)
            {
                race = Shop.ShipMakerRace(ship);
                if (race < 0 || (race > 3 && race != Standing.Pirate && race != Standing.Void && race != Standing.Specter)) race = Standing.Pirate;
            }
            Send(t, Order.Spawn, ship, race, count << 8 | (int)behaviour, by, $"spawned {count} x ship {ship} (race {race}, {behaviour}{(at != null ? ", at " + at : "")})", at);
            return string.Format(X("mpAdmSpawned", "Spawning {0} x {1} at {2}."), count, DebugSpawner.ShipName(NetGame.Db, ship), t.DisplayName);
        });

        public static string Ship(string args, NetPlayer by) => ForTargets(args, by, true, (t, rest) =>
        {
            rest = rest.Trim();
            if (rest.Length == 0) return Usage("ship");
            if (string.Equals(rest, "own", StringComparison.OrdinalIgnoreCase))
            {
                Send(t, Order.Ship, -1, 0, 0, by, "sent back to their own ship");
                return string.Format(X("mpAdmShipOwn", "{0} goes back to their own ship."), t.DisplayName);
            }
            var hull = FindHull(rest, out string error);
            if (hull == null) return error;
            if (!t.InSpace && !hull.playerShip)
                return string.Format(X("mpAdmShipHangar", "{0} is docked: that ship doesn't fit in a hangar."), t.DisplayName);
            Send(t, Order.Ship, 0, 0, 0, by, $"swapped the ship to {hull.key}", hull.key);
            return string.Format(X("mpAdmShip", "{0} flies the {1}."), t.DisplayName, HullName(hull));
        });

        public static string Cheat(string args, NetPlayer by) => ForTargets(args, by, true, (t, rest) =>
        {
            var words = rest.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            if (words.Length == 0) return Usage("cheat") + "  " + FlagList();
            int flag = Array.FindIndex(Cheats.Flags, f => string.Equals(f.word, words[0], StringComparison.OrdinalIgnoreCase));
            if (flag < 0) return string.Format(X("mpAdmNoCheat", "No cheat \"{0}\": {1}"), words[0], FlagList());
            int state = 2;   // toggle
            if (words.Length > 1)
            {
                string w = words[1].ToLowerInvariant();
                if (w == "on" || w == "true" || w == "1") state = 1;
                else if (w == "off" || w == "false" || w == "0") state = 0;
                else return Usage("cheat");
            }
            Send(t, Order.Cheat, flag, state, 0, by, $"cheat {Cheats.Flags[flag].word} {(state == 2 ? "toggled" : state == 1 ? "on" : "off")}");
            return string.Format(X("mpAdmCheat", "{0}: {1} {2}."), t.DisplayName, Cheats.Flags[flag].word,
                state == 2 ? X("mpAdmToggled", "toggled") : state == 1 ? X("mpAdmOn", "on") : X("mpAdmOff", "off"));
        });

        public static string Title(string args, NetPlayer by) => ForTargets(args, by, true, (t, rest) =>
        {
            rest = rest.Trim();
            if (rest.Length == 0) return Usage("title");
            if (string.Equals(rest, "clear", StringComparison.OrdinalIgnoreCase))
            {
                Send(t, Order.Title, 0, 0, 0, by, "cleared the title", "");
                return "";
            }
            int seconds = 4;
            var words = new List<string>(rest.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
            if (words.Count >= 3 && string.Equals(words[words.Count - 2], "for", StringComparison.OrdinalIgnoreCase)
                && int.TryParse(words[words.Count - 1], out int s) && s > 0)
            {
                seconds = Mathf.Min(s, 3600);
                rest = string.Join(" ", words.GetRange(0, words.Count - 2));
            }
            int bar = rest.IndexOf('|');
            string main = NetChat.Clean(bar < 0 ? rest : rest.Substring(0, bar)), sub = bar < 0 ? "" : NetChat.Clean(rest.Substring(bar + 1));
            if (main.Length + sub.Length == 0) return Usage("title");
            Send(t, Order.Title, seconds * 1000, 0, 0, by, $"title \"{main}\" / \"{sub}\" for {seconds} s", main + "\n" + sub);
            return "";
        });

        public static string Timer(string args, NetPlayer by) => ForTargets(args, by, true, (t, rest) =>
        {
            rest = rest.Trim();
            int space = rest.IndexOf(' ');
            string first = space < 0 ? rest : rest.Substring(0, space), label = space < 0 ? "" : NetChat.Clean(rest.Substring(space + 1));
            if (string.Equals(first, "stop", StringComparison.OrdinalIgnoreCase))
            {
                Send(t, Order.Timer, -1, 0, 0, by, "stopped the timer", "");
                return "";
            }
            int seconds;
            int colon = first.IndexOf(':');
            if (colon > 0 && int.TryParse(first.Substring(0, colon), out int m) && int.TryParse(first.Substring(colon + 1), out int sec)) seconds = m * 60 + sec;
            else if (!int.TryParse(first, out seconds)) return Usage("timer");
            if (seconds <= 0) return Usage("timer");
            seconds = Mathf.Min(seconds, 24 * 3600);
            Send(t, Order.Timer, seconds, 0, 0, by, $"timer {seconds} s \"{label}\"", label);
            return "";
        });

        public static string Mute(string args, NetPlayer by, bool on) => ForTargets(args, by, false, (t, rest) =>
        {
            if (!on)
            {
                if (!muted.Remove(t.OwnerClientId)) return string.Format(X("mpAdmNotMuted", "{0} isn't muted."), t.DisplayName);
                NetState.Instance.NoticeTo(t, X("mpUnmutedYou", "You can chat again."));
                Debug.Log($"Server: {NetCommands.IssuerName(by)} unmuted {t.DisplayName} ({t.OwnerClientId})");
                return string.Format(X("mpAdmUnmuted", "{0} can chat again."), t.DisplayName);
            }
            if (t == by) return X("mpCmdNotYourself", "Not on yourself.");
            if (NetCommands.IsHostPlayer(t) || (NetCommands.IsAdmin(t) && by != null && !NetCommands.IsHostPlayer(by)))
                return string.Format(X("mpAdmCantMute", "{0} can't be muted."), t.DisplayName);
            float minutes = float.TryParse(rest.Trim(), System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out float m) && m > 0f ? m : 0f;
            muted[t.OwnerClientId] = minutes > 0f ? Time.unscaledTime + minutes * 60f : float.PositiveInfinity;
            IsMuted(t.OwnerClientId, out string text);
            NetState.Instance.NoticeTo(t, text);
            Debug.Log($"Server: {NetCommands.IssuerName(by)} muted {t.DisplayName} ({t.OwnerClientId}){(minutes > 0f ? $" for {minutes} min" : "")}");
            return minutes > 0f ? string.Format(X("mpAdmMutedFor", "{0} is muted for {1} minute(s)."), t.DisplayName, minutes)
                                : string.Format(X("mpAdmMuted", "{0} is muted for this session."), t.DisplayName);
        });

        // ---- argument parsing --------------------------------------------------------------------------------

        static string Usage(string command) => NetCommands.UsageOf(command);

        /// <summary>Takes a trailing "at x y z" (game coordinates) off 'rest': 'at' = "x y z" (invariant), null without one;
        /// false = an "at" without three finite numbers.</summary>
        static bool TakeAt(ref string rest, out string at)
        {
            at = null;
            var words = new List<string>(rest.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
            int i = words.FindLastIndex(w => string.Equals(w, "at", StringComparison.OrdinalIgnoreCase));
            if (i < 0) return true;
            if (i != words.Count - 4) return false;
            var v = new float[3];
            for (int k = 0; k < 3; k++)
                if (!float.TryParse(words[i + 1 + k], System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out v[k])
                    || !NetGuard.Finite(v[k]) || Mathf.Abs(v[k]) > 2e7f) return false;
            at = string.Format(System.Globalization.CultureInfo.InvariantCulture, "{0} {1} {2}", v[0], v[1], v[2]);
            rest = string.Join(" ", words.GetRange(0, i));
            return true;
        }

        /// <summary>"x y z" game coordinates (TakeAt) as a Unity position; null when empty or broken.</summary>
        static Vector3? ParseAt(string text)
        {
            if (string.IsNullOrEmpty(text)) return null;
            var w = text.Split(' ');
            if (w.Length != 3) return null;
            var v = new float[3];
            for (int k = 0; k < 3; k++)
                if (!float.TryParse(w[k], System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture, out v[k]) || !NetGuard.Finite(v[k]))
                    return null;
            return OrbitLayout.ToUnity(new Vector3(v[0], v[1], v[2]));
        }

        /// <summary>A trailing whole number (with more before it) is the amount, else 'fallback'; false = nothing left or a
        /// number below 1.</summary>
        static bool ParseAmount(ref string rest, int fallback, int max, out int amount)
        {
            amount = fallback;
            rest = rest.Trim();
            int space = rest.LastIndexOf(' ');
            if (space > 0 && int.TryParse(rest.Substring(space + 1), out int n))
            {
                if (n < 1) return false;
                amount = Mathf.Min(n, max);
                rest = rest.Substring(0, space).Trim();
            }
            return rest.Length > 0;
        }

        /// <summary>An item by its index, its whole name or the one name it starts (any case); -1 with the reason.</summary>
        static int FindItem(string spec, out string error)
        {
            error = null;
            var db = NetGame.Db;
            if (int.TryParse(spec, out int index) && NetGuard.Item(index)) return index;
            int found = -1, matches = 0;
            foreach (var it in db.Items)
            {
                string n = UI.ItemInfo.ItemName(it.index);
                if (string.IsNullOrEmpty(n)) n = it.name ?? "";
                if (string.Equals(n, spec, StringComparison.OrdinalIgnoreCase)) return it.index;
                if (n.StartsWith(spec, StringComparison.OrdinalIgnoreCase)) { found = it.index; matches++; }
            }
            if (matches == 1) return found;
            error = matches > 1 ? string.Format(X("mpAdmItemAmbiguous", "\"{0}\" fits {1} items: write more of the name, or its number."), spec, matches)
                                : string.Format(X("mpAdmNoItem", "No item \"{0}\"."), spec);
            return -1;
        }

        /// <summary>An assembled object (assemblies.json) by its whole name or the one name it starts (any case); null with
        /// the reason.</summary>
        static AssemblyData FindAssembly(string spec, out string error)
        {
            error = null;
            var all = NetGame.Db.Assemblies;
            var asm = all.Find(a => string.Equals(a.name, spec, StringComparison.OrdinalIgnoreCase));
            if (asm != null) return asm;
            var starts = all.FindAll(a => a.name.StartsWith(spec, StringComparison.OrdinalIgnoreCase));
            if (starts.Count == 1) return starts[0];
            error = starts.Count > 1
                ? string.Format(X("mpAdmObjectAmbiguous", "\"{0}\" fits {1} objects (e.g. {2}): write more of the name."), spec, starts.Count, starts[0].name)
                : string.Format(X("mpAdmNoShipOrObject", "No ship or object \"{0}\" (a ship's number or name, or an assemblies.json name like station_083_terran)."), spec);
            return null;
        }

        /// <summary>A ship of ships.json by its index, its whole name or the one name it starts; -1 with the reason (-2: the
        /// name fits several ships).</summary>
        static int FindShip(string spec, out string error)
        {
            error = null;
            var db = NetGame.Db;
            if (int.TryParse(spec, out int index) && db.Ship(index) != null) return index;
            int found = -1, matches = 0;
            foreach (var s in db.Ships)
            {
                string n = DebugSpawner.ShipName(db, s.index);
                if (string.Equals(n, spec, StringComparison.OrdinalIgnoreCase)) return s.index;
                if (spec.Length > 0 && n.StartsWith(spec, StringComparison.OrdinalIgnoreCase)) { found = s.index; matches++; }
            }
            if (matches == 1) return found;
            error = matches > 1 ? string.Format(X("mpAdmShipAmbiguous", "\"{0}\" fits {1} ships: write more of the name, or its number."), spec, matches)
                                : string.Format(X("mpAdmNoShip", "No ship \"{0}\"."), spec);
            return matches > 1 ? -2 : -1;
        }

        static string HullName(PlayerHull.Hull h)
        {
            int i = h.label.IndexOf(" · ");
            return i >= 0 ? h.label.Substring(i + 3) : h.label;
        }

        /// <summary>A hull of the debug Ships tab by its ship number, its key, its whole name or the one name it starts; null
        /// with the reason.</summary>
        static PlayerHull.Hull FindHull(string spec, out string error)
        {
            error = null;
            var all = PlayerHull.All(NetGame.Db);
            if (int.TryParse(spec, out int index))
            {
                var byIndex = all.Find(h => h.key == "ship_" + index) ?? all.Find(h => h.stats == index);
                if (byIndex != null) return byIndex;
            }
            PlayerHull.Hull found = null;
            int matches = 0;
            foreach (var h in all)
            {
                string n = HullName(h);
                if (string.Equals(n, spec, StringComparison.OrdinalIgnoreCase) || string.Equals(h.key, spec, StringComparison.OrdinalIgnoreCase)) return h;
                if (n.StartsWith(spec, StringComparison.OrdinalIgnoreCase)) { found = h; matches++; }
            }
            if (matches == 1) return found;
            error = matches > 1 ? string.Format(X("mpAdmShipAmbiguous", "\"{0}\" fits {1} ships: write more of the name, or its number."), spec, matches)
                                : string.Format(X("mpAdmNoShip", "No ship \"{0}\"."), spec);
            return null;
        }

        static string FlagList()
        {
            var words = new List<string>();
            foreach (var f in Cheats.Flags) words.Add(f.word);
            return string.Join(", ", words);
        }

        static DebugSpawner.Behaviour? BehaviourWord(string w)
        {
            switch (w.ToLowerInvariant())
            {
                case "enemy": case "hostile": return DebugSpawner.Behaviour.Hostile;
                case "friendly": case "friend": return DebugSpawner.Behaviour.Friendly;
                case "neutral": return DebugSpawner.Behaviour.Neutral;
                case "standing": return DebugSpawner.Behaviour.Normal;
            }
            return null;
        }

        static int RaceWord(string w)
        {
            switch (w.ToLowerInvariant())
            {
                case "terran": case "terrans": return 0;
                case "vossk": return 1;
                case "nivelian": case "nivelians": return 2;
                case "midorian": case "midorians": return 3;
                case "pirate": case "pirates": return Standing.Pirate;
                case "void": return Standing.Void;
                case "specter": case "specters": return Standing.Specter;
            }
            foreach (int r in new[] { 0, 1, 2, 3, Standing.Pirate, Standing.Void, Standing.Specter })
                if (string.Equals(Localization.Get(406 + r), w, StringComparison.OrdinalIgnoreCase)) return r;
            return -1;
        }

        // ---- the target's game ------------------------------------------------------------------------------

        static void Notice(string by, string text) => NetChat.Notice(string.Format(X("mpAdmByYou", "{0}: {1}"), by, text));

        /// <summary>An admin's order on this game's own ship and Session (NetState.AdminRpc, sent only by the server).</summary>
        internal static void Apply(Order order, int a, int b, int c, string text, string by)
        {
            var level = UnityEngine.Object.FindAnyObjectByType<SpaceLevel>();
            var docked = level == null ? UnityEngine.Object.FindAnyObjectByType<StationLevel>() : null;
            switch (order)
            {
                case Order.Kill:
                    if (level == null || level.Health == null || level.Health.Dead) return;
                    level.Health.Kill(true);
                    break;
                case Order.Heal:
                    Cheats.Repair();
                    NetChat.Notice(string.Format(X("mpAdmHealedYou", "{0} repaired your ship."), by));
                    break;
                case Order.Give:
                    if (!NetGuard.Item(a) || b < 1) return;
                    b = Mathf.Min(b, MaxGive);
                    if (c == 1 && docked != null && docked.Stock != null)
                        Notice(by, $"{UI.ItemInfo.ItemName(a)}: {Cheats.GiveAndMount(NetGame.Db, docked.Stock, a, b)}");
                    else
                    {
                        Cheats.GiveItem(a, b);
                        NetChat.Notice(string.Format(X("mpAdmGaveYou", "{0} gave you {1} x {2}."), by, b, UI.ItemInfo.ItemName(a)));
                    }
                    break;
                case Order.Credits:
                    Session.Credits = (int)Mathf.Clamp((long)Session.Credits + a, 0L, MaxCredits);
                    NetChat.Notice(string.Format(a > 0 ? X("mpAdmCreditsYou", "{0} gave you {1} credits.") : X("mpAdmCreditsTakenYou", "{0} took {1} credits."),
                        by, Math.Abs(a)));
                    break;
                case Order.Spawn:
                    if (level == null || NetGame.Db.Ship(a) == null) return;
                    Notice(by, DebugSpawner.SpawnShip(level, b, a, (DebugSpawner.Behaviour)Mathf.Clamp(c & 0xff, 0, 3), Mathf.Clamp(c >> 8, 1, MaxSpawn), ParseAt(text)));
                    break;
                case Order.Ship:
                    if (a < 0) { Notice(by, PlayerHull.Restore(level, docked)); break; }
                    var hull = PlayerHull.All(NetGame.Db).Find(h => h.key == text);
                    if (hull != null) Notice(by, PlayerHull.Fly(hull, level, docked));
                    break;
                case Order.Ammo:
                    Cheats.RefillAmmo(NetGame.Db);
                    NetChat.Notice(string.Format(X("mpAdmAmmoYou", "{0} refilled your secondaries."), by));
                    break;
                case Order.Reveal:
                    Cheats.RevealAllSystems();
                    NetChat.Notice(string.Format(X("mpAdmRevealYou", "{0} revealed every system on your map."), by));
                    break;
                case Order.Peace:
                    Cheats.MakePeace();
                    NetChat.Notice(string.Format(X("mpAdmPeaceYou", "{0} made peace for you with every race."), by));
                    break;
                case Order.Cheat:
                    if (a < 0 || a >= Cheats.Flags.Length) return;
                    bool now = Cheats.Grant(Cheats.Flags[a].key, b == 2 ? (bool?)null : b == 1);
                    NetChat.Notice(string.Format(now ? X("mpAdmCheatOnYou", "{0} turned {1} on for you.") : X("mpAdmCheatOffYou", "{0} turned {1} off for you."),
                        by, Cheats.Flags[a].word));
                    break;
                case Order.Title:
                {
                    int nl = (text ?? "").IndexOf('\n');
                    NetScreen.ShowTitle(nl < 0 ? text : text.Substring(0, nl), nl < 0 ? "" : text.Substring(nl + 1), a / 1000f);
                    break;
                }
                case Order.Timer:
                    NetScreen.ShowTimer(a, text);
                    break;
                case Order.Object:
                    if (level == null || string.IsNullOrEmpty(text)) return;
                    int sep = text.IndexOf('@');
                    Notice(by, DebugSpawner.SpawnObject(level, sep < 0 ? text : text.Substring(0, sep), sep < 0 ? null : ParseAt(text.Substring(sep + 1))));
                    break;
            }
        }
    }
}
