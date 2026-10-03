// NetEvents.cs
// Remake multiplayer: event scripts (game modes like waves of enemies), run on the server by an admin's /event <name> or the
// dedicated server's console ("event <name>"); one event at a time, "/event stop" ends it, "/event list" lists them.
// A script is a text file: <name>.txt in an Events folder (the game's data folder, Application.persistentDataPath/Events,
// or next to the game / dedicated server's executable), else a built-in one (Resources/GoF2Events: waves, survival).
// Line by line, "#" starts a comment:
//   <command> [args]              any server command without the "/" (spawn, title, timer, heal, give, tp, g...), run as the
//                                 server (every right, named "Server"); {expression} parts are filled in first ("{wave*2}")
//   wait <seconds>                pauses the script (an expression)
//   wait until <condition> [timeout <seconds>]   pauses until the condition holds (checked 4 times a second)
//   if <condition> / else / end   runs a block or the other
//   while <condition> / end       repeats a block while the condition holds
//   repeat <count> [as <var>] / end   repeats a block; the variable counts 1, 2, 3...
//   set <var> [=] <expression>    a variable of the script
//   stop                          ends the event
//   score <kills | time>          how the event's winner is decided (default time): the most event ships destroyed, or the
//                                 longest alive in space since the fight began (the first spawn; a death ends a player's time)
//   winner [kills | time]         "The winner is X" on everyone's screen (with the kills or the time) and in the chat
// Expressions: numbers, variables, + - * / %, ( ), == != < <= > >=, and, or, not, random(a, b) (whole numbers a..b),
// min(a, b), max(a, b), and the state:
//   enemies   this event's living ships spawned as enemies (a just-sent spawn counts until its ships show up, 6 s at most)
//   ships     all this event's living spawned ships
//   players   the players in the session; inspace / docked / dead: in space alive, docked, destroyed in space
//   time      seconds since the event started
// Ending by itself: once it has spawned ships, an event ends when no player has been alive in space in its ships' orbits
// for 3 s (all destroyed, docked or gone): "Event over" with the winner on everyone's screen. "set autostop = 0" turns
// that off.
// The ships an event spawns carry its batch tag (SpawnSpec.eventTag, written on their NetProxy): the server sees every
// NPC of every player's game as a NetProxy, so it can count them. Ticked by NetState.Update on the server.

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetEvents
    {
        const float CheckSeconds = 0.25f, PendingSeconds = 6f, EmptySeconds = 3f;
        const int MaxOpsPerTick = 500, MaxLines = 2000;

        enum Op { Command, Wait, WaitUntil, Set, JumpIfFalse, Jump, Stop, Score, Winner }

        sealed class Step
        {
            public Op op;
            public string a, b;     // command line / expression / variable; second expression (timeout, value)
            public int target;      // jumps
            public int line;
        }

        sealed class Batch
        {
            public int expected;
            public bool enemy;
            public float start;
            public readonly HashSet<long> seen = new HashSet<long>();
        }

        static List<Step> program;
        static string running;
        static int pc;
        static float startTime, waitUntil = -1f, checkTimer, untilDeadline = -1f, emptySince = -1f, emptyCheck;
        static ulong starter = ulong.MaxValue;
        static readonly Dictionary<string, double> vars = new Dictionary<string, double>();
        static readonly Dictionary<int, Batch> batches = new Dictionary<int, Batch>();
        // The players' results: event ships destroyed, seconds alive in space since the fight began, out (destroyed once).
        static readonly Dictionary<ulong, int> kills = new Dictionary<ulong, int>();
        static readonly Dictionary<ulong, float> alive = new Dictionary<ulong, float>();
        static readonly HashSet<ulong> outOfFight = new HashSet<ulong>();
        static readonly HashSet<long> countedKills = new HashSet<long>();
        static bool scoreKills;
        static float statsTimer;
        static int nextTag = 1;
        static bool executing;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => Reset();

        /// <summary>A new session, or the server going: nothing runs.</summary>
        internal static void Reset()
        {
            program = null;
            running = null;
            vars.Clear();
            batches.Clear();
            ClearStats();
            executing = false;
        }

        static string X(string key, string english) => Localization.Extra(key, english);

        public static bool Running => program != null;

        // ---- files --------------------------------------------------------------------------------------------

        static IEnumerable<string> Folders()
        {
            yield return Path.Combine(Application.persistentDataPath, "Events");
            string exeDir = Path.GetDirectoryName(Application.dataPath);
            if (!string.IsNullOrEmpty(exeDir)) yield return Path.Combine(exeDir, "Events");
        }

        static string Load(string name, out string from)
        {
            from = null;
            if (name.IndexOfAny(Path.GetInvalidFileNameChars()) >= 0 || name.Contains("..")) return null;
            foreach (var dir in Folders())
            {
                string path = Path.Combine(dir, name + ".txt");
                try { if (File.Exists(path)) { from = path; return File.ReadAllText(path); } }
                catch (Exception e) { Debug.LogWarning($"NetEvents: {path}: {e.Message}"); }
            }
            var asset = Resources.Load<TextAsset>("GoF2Events/" + name);
            if (asset != null) { from = X("mpEventBuiltIn", "built in"); return asset.text; }
            return null;
        }

        static List<string> List()
        {
            var names = new SortedSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var dir in Folders())
            {
                try { if (Directory.Exists(dir)) foreach (var f in Directory.GetFiles(dir, "*.txt")) names.Add(Path.GetFileNameWithoutExtension(f)); }
                catch (Exception) { }
            }
            foreach (var a in Resources.LoadAll<TextAsset>("GoF2Events")) names.Add(a.name);
            return new List<string>(names);
        }

        // ---- the command (server) ----------------------------------------------------------------------------

        /// <summary>/event &lt;name | stop | list&gt;: the issuer's answer.</summary>
        public static string Command(string args, NetPlayer by)
        {
            args = (args ?? "").Trim();
            if (args.Length == 0 || args.Equals("list", StringComparison.OrdinalIgnoreCase))
            {
                var names = List();
                string list = names.Count == 0 ? X("mpEventNone", "No event scripts found.") : string.Join(", ", names);
                string folder = Path.Combine(Application.persistentDataPath, "Events");
                return string.Format(X("mpEventList", "Events: {0}{1}Scripts go in {2} (or an Events folder next to the game)."), list,
                    Running ? string.Format(X("mpEventRunningNow", " (running: {0})"), running) + " " : " ", folder);
            }
            if (args.Equals("stop", StringComparison.OrdinalIgnoreCase))
            {
                if (!Running) return X("mpEventNotRunning", "No event is running.");
                string was = running;
                Reset();
                Debug.Log($"Server: {NetCommands.IssuerName(by)} stopped the event {was}");
                NetState.Instance?.NoticeAll(string.Format(X("mpEventStopped", "The event {0} was stopped."), was));
                return "";
            }
            if (Running) return string.Format(X("mpEventBusy", "The event {0} is running: /event stop first."), running);
            string name = args.Split(' ')[0];
            string text = Load(name, out string from);
            if (text == null) return string.Format(X("mpEventMissing", "No event \"{0}\". /event list shows them."), name);
            var compiled = Compile(text, out string error);
            if (compiled == null) return string.Format(X("mpEventError", "{0}: {1}"), name, error);
            program = compiled;
            running = name;
            pc = 0;
            startTime = Time.unscaledTime;
            waitUntil = untilDeadline = emptySince = -1f;
            vars.Clear();
            batches.Clear();
            ClearStats();
            starter = by != null ? by.OwnerClientId : ulong.MaxValue;
            Debug.Log($"Server: {NetCommands.IssuerName(by)} started the event {name} ({from}, {compiled.Count} steps)");
            return string.Format(X("mpEventStarted", "Event {0} started."), name);
        }

        // ---- compiling ---------------------------------------------------------------------------------------

        static List<Step> Compile(string text, out string error)
        {
            error = null;
            var steps = new List<Step>();
            var open = new Stack<(string kind, int at, int line, string var)>();
            var lines = text.Replace("\r", "").Split('\n');
            if (lines.Length > MaxLines) { error = X("mpEventTooLong", "the script is too long."); return null; }
            int hidden = 0;
            for (int n = 0; n < lines.Length; n++)
            {
                string raw = lines[n];
                int hash = raw.IndexOf('#');
                string line = (hash >= 0 ? raw.Substring(0, hash) : raw).Trim();
                if (line.Length == 0) continue;
                if (line.StartsWith("/")) line = line.Substring(1);
                int sp = line.IndexOf(' ');
                string word = (sp < 0 ? line : line.Substring(0, sp)).ToLowerInvariant();
                string rest = sp < 0 ? "" : line.Substring(sp + 1).Trim();
                int ln = n + 1;
                string Err(string what) => string.Format(X("mpEventLine", "line {0}: {1}"), ln, what);
                switch (word)
                {
                    case "wait":
                        if (rest.StartsWith("until ", StringComparison.OrdinalIgnoreCase))
                        {
                            string cond = rest.Substring(6).Trim(), timeout = null;
                            int t = cond.LastIndexOf(" timeout ", StringComparison.OrdinalIgnoreCase);
                            if (t >= 0) { timeout = cond.Substring(t + 9).Trim(); cond = cond.Substring(0, t).Trim(); }
                            if (cond.Length == 0) { error = Err(X("mpEventNoCondition", "a condition is missing.")); return null; }
                            steps.Add(new Step { op = Op.WaitUntil, a = cond, b = timeout, line = ln });
                        }
                        else
                        {
                            if (rest.Length == 0) { error = Err(X("mpEventNoSeconds", "wait needs seconds.")); return null; }
                            steps.Add(new Step { op = Op.Wait, a = rest, line = ln });
                        }
                        break;
                    case "set":
                    {
                        int eq = rest.IndexOf('=');
                        string name, value;
                        if (eq > 0 && (eq + 1 >= rest.Length || rest[eq + 1] != '=')) { name = rest.Substring(0, eq).Trim(); value = rest.Substring(eq + 1).Trim(); }
                        else { int s2 = rest.IndexOf(' '); name = s2 < 0 ? rest : rest.Substring(0, s2); value = s2 < 0 ? "" : rest.Substring(s2 + 1).Trim(); }
                        if (!IsName(name) || value.Length == 0) { error = Err(X("mpEventBadSet", "set <variable> = <expression>.")); return null; }
                        steps.Add(new Step { op = Op.Set, a = name.ToLowerInvariant(), b = value, line = ln });
                        break;
                    }
                    case "if":
                        if (rest.Length == 0) { error = Err(X("mpEventNoCondition", "a condition is missing.")); return null; }
                        open.Push(("if", steps.Count, ln, null));
                        steps.Add(new Step { op = Op.JumpIfFalse, a = rest, line = ln });
                        break;
                    case "else":
                    {
                        if (open.Count == 0 || open.Peek().kind != "if") { error = Err(X("mpEventElse", "else without if.")); return null; }
                        var o = open.Pop();
                        open.Push(("else", steps.Count, o.line, null));
                        steps.Add(new Step { op = Op.Jump, line = ln });
                        steps[o.at].target = steps.Count;
                        break;
                    }
                    case "while":
                        if (rest.Length == 0) { error = Err(X("mpEventNoCondition", "a condition is missing.")); return null; }
                        open.Push(("while", steps.Count, ln, null));
                        steps.Add(new Step { op = Op.JumpIfFalse, a = rest, line = ln });
                        break;
                    case "repeat":
                    {
                        string count = rest, var = "_r" + hidden;
                        int asAt = rest.LastIndexOf(" as ", StringComparison.OrdinalIgnoreCase);
                        if (asAt >= 0) { count = rest.Substring(0, asAt).Trim(); var = rest.Substring(asAt + 4).Trim().ToLowerInvariant(); }
                        if (count.Length == 0 || !IsName(var)) { error = Err(X("mpEventBadRepeat", "repeat <count> [as <variable>].")); return null; }
                        string limit = "_n" + hidden++;
                        steps.Add(new Step { op = Op.Set, a = limit, b = count, line = ln });
                        steps.Add(new Step { op = Op.Set, a = var, b = "0", line = ln });
                        open.Push(("repeat", steps.Count, ln, var));
                        steps.Add(new Step { op = Op.JumpIfFalse, a = $"{var} < {limit}", line = ln });
                        steps.Add(new Step { op = Op.Set, a = var, b = $"{var} + 1", line = ln });
                        break;
                    }
                    case "end":
                    {
                        if (open.Count == 0) { error = Err(X("mpEventEnd", "end without if, while or repeat.")); return null; }
                        var o = open.Pop();
                        if (o.kind == "while" || o.kind == "repeat")
                        {
                            steps.Add(new Step { op = Op.Jump, target = o.at, line = ln });
                            steps[o.at].target = steps.Count;
                        }
                        else steps[o.at].target = steps.Count;   // if: past the block; else: the jump over it
                        break;
                    }
                    case "stop":
                        steps.Add(new Step { op = Op.Stop, line = ln });
                        break;
                    case "score":
                    case "winner":
                    {
                        string how = rest.ToLowerInvariant();
                        if (how.Length == 0 && word == "winner") how = "-";
                        if (how != "kills" && how != "time" && how != "-") { error = Err(X("mpEventScore", "score / winner take kills or time.")); return null; }
                        steps.Add(new Step { op = word == "score" ? Op.Score : Op.Winner, a = how, line = ln });
                        break;
                    }
                    case "event":
                        error = Err(X("mpEventNested", "an event can't start another one."));
                        return null;
                    default:
                        steps.Add(new Step { op = Op.Command, a = line, line = ln });
                        break;
                }
            }
            if (open.Count > 0) { error = string.Format(X("mpEventLine", "line {0}: {1}"), open.Peek().line, X("mpEventOpen", "this block has no end.")); return null; }
            return steps;
        }

        static bool IsName(string s)
        {
            if (string.IsNullOrEmpty(s) || !(char.IsLetter(s[0]) || s[0] == '_')) return false;
            foreach (char c in s) if (!char.IsLetterOrDigit(c) && c != '_') return false;
            return true;
        }

        // ---- running (server, NetState.Update) -----------------------------------------------------------------

        internal static void Tick()
        {
            if (!Running) return;
            if (!NetGame.Active || NetState.Instance == null || !NetState.Instance.IsServer) { Reset(); return; }
            float now = Time.unscaledTime;
            UpdateStats();
            if (CheckEmpty(now)) return;
            if (waitUntil >= 0f)
            {
                if (now < waitUntil) return;
                waitUntil = -1f;
            }
            for (int ops = 0; ops < MaxOpsPerTick && Running; ops++)
            {
                if (pc >= program.Count) { Finish(); return; }
                var s = program[pc];
                try
                {
                    switch (s.op)
                    {
                        case Op.Command:
                            pc++;
                            RunCommand(Fill(s.a));
                            break;
                        case Op.Wait:
                            pc++;
                            waitUntil = now + Mathf.Max(0f, (float)Eval(s.a));
                            return;
                        case Op.WaitUntil:
                            if (untilDeadline < 0f) untilDeadline = s.b != null ? now + Mathf.Max(0f, (float)Eval(s.b)) : float.PositiveInfinity;
                            if ((checkTimer -= Time.unscaledDeltaTime) > 0f && now < untilDeadline) return;
                            checkTimer = CheckSeconds;
                            if (Eval(s.a) != 0 || now >= untilDeadline) { pc++; untilDeadline = -1f; checkTimer = 0f; break; }
                            return;
                        case Op.Set:
                            vars[s.a] = Eval(s.b);
                            pc++;
                            break;
                        case Op.JumpIfFalse:
                            pc = Eval(s.a) != 0 ? pc + 1 : s.target;
                            break;
                        case Op.Jump:
                            pc = s.target;
                            break;
                        case Op.Stop:
                            Finish();
                            return;
                        case Op.Score:
                            scoreKills = s.a == "kills";
                            pc++;
                            break;
                        case Op.Winner:
                            pc++;
                            AnnounceWinner(s.a == "-" ? scoreKills : s.a == "kills", null);
                            break;
                    }
                }
                catch (Exception e)
                {
                    Fail(string.Format(X("mpEventLine", "line {0}: {1}"), s.line, e.Message));
                    return;
                }
            }
        }

        static void RunCommand(string line)
        {
            int sp = line.IndexOf(' ');
            string name = (sp < 0 ? line : line.Substring(0, sp)).ToLowerInvariant();
            string args = sp < 0 ? "" : line.Substring(sp + 1).Trim();
            executing = true;
            string answer;
            try { answer = NetCommands.RunOnServer(name, args, null); }
            finally { executing = false; }
            if (answer == null) throw new Exception(string.Format(X("mpEventUnknownCmd", "unknown command \"{0}\"."), name));
            if (answer.Length > 0) Debug.Log($"Server: event {running}: {name}: {answer.Replace('\n', ' ')}");
        }

        static void Finish()
        {
            Debug.Log($"Server: the event {running} ended");
            Notify(string.Format(X("mpEventEnded", "The event {0} ended."), running));
            Reset();
        }

        static void Fail(string why)
        {
            Debug.LogWarning($"Server: the event {running} stopped: {why}");
            Notify(string.Format(X("mpEventFailed", "The event {0} stopped: {1}"), running, why));
            Reset();
        }

        /// <summary>The admin who started it (when still here), else the server log only.</summary>
        static void Notify(string text)
        {
            var p = starter != ulong.MaxValue ? NetSquad.Find(starter) : null;
            if (p != null) NetState.Instance?.NoticeTo(p, text);
        }

        /// <summary>The automatic end: this event's ships exist, and nobody has been alive in space in their orbits for 3 s.</summary>
        static bool CheckEmpty(float now)
        {
            if (batches.Count == 0 || (vars.TryGetValue("autostop", out double auto) && auto == 0)) { emptySince = -1f; return false; }
            if ((emptyCheck -= Time.unscaledDeltaTime) > 0f) return false;
            emptyCheck = CheckSeconds;
            var stations = new HashSet<int>();
            foreach (var proxy in UnityEngine.Object.FindObjectsByType<NetProxy>())
                if (proxy != null && proxy.IsSpawned && proxy.EventTag != 0 && batches.ContainsKey(proxy.EventTag)) stations.Add(proxy.Station);
            if (stations.Count == 0) { emptySince = -1f; return false; }   // nothing of the event's in space (yet)
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && p.InSpace && p.Hull > 0f && stations.Contains(p.Station)) { emptySince = -1f; return false; }
            if (emptySince < 0f) { emptySince = now; return false; }
            if (now - emptySince < EmptySeconds) return false;
            string name = running;
            Debug.Log($"Server: the event {name} ended: no players left in its orbits");
            executing = true;
            try { AnnounceWinner(scoreKills, X("mpEventOverTitle", "Event over")); }
            finally { executing = false; }
            NetState.Instance?.NoticeAll(string.Format(X("mpEventOverNotice", "The event {0} ended: no players left in its orbit."), name));
            Reset();
            return true;
        }

        // ---- results and the winner -----------------------------------------------------------------------------

        /// <summary>One NPC whatever proxy shows it: its owner and its index in the owner's traffic (a ship's proxy can be made
        /// again, and Netcode reuses network ids).</summary>
        static long ShipKey(NetProxy p) => (long)p.OwnerClientId << 32 | (uint)p.LocalId;

        static void ClearStats()
        {
            kills.Clear();
            alive.Clear();
            outOfFight.Clear();
            countedKills.Clear();
            scoreKills = false;
        }

        /// <summary>Every 0.25 s: the event ships destroyed since (each once, to its killer), and the time alive in space of
        /// every player still in the fight (from the event's first spawn; destroyed = out for good).</summary>
        static void UpdateStats()
        {
            statsTimer += Time.unscaledDeltaTime;
            if (statsTimer < CheckSeconds) return;
            float dt = statsTimer;
            statsTimer = 0f;
            if (batches.Count == 0) return;   // the fight hasn't begun
            foreach (var proxy in UnityEngine.Object.FindObjectsByType<NetProxy>())
            {
                if (proxy == null || !proxy.IsSpawned || proxy.EventTag == 0 || !batches.ContainsKey(proxy.EventTag)) continue;
                if (proxy.Killer == ulong.MaxValue || !countedKills.Add(ShipKey(proxy))) continue;
                kills.TryGetValue(proxy.Killer, out int k);
                kills[proxy.Killer] = k + 1;
            }
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned || outOfFight.Contains(p.OwnerClientId) || !p.InSpace) continue;
                if (p.Hull <= 0f) { if (alive.ContainsKey(p.OwnerClientId)) outOfFight.Add(p.OwnerClientId); continue; }
                alive.TryGetValue(p.OwnerClientId, out float a);
                alive[p.OwnerClientId] = a + dt;
            }
        }

        /// <summary>@survivors: a player alive in space who has been in this event's fight and never destroyed in it.</summary>
        public static bool Survived(NetPlayer p) =>
            Running && p != null && p.InSpace && p.Hull > 0f && alive.ContainsKey(p.OwnerClientId) && !outOfFight.Contains(p.OwnerClientId);

        static string Clock(float seconds)
        {
            int s = Mathf.FloorToInt(seconds);
            return $"{s / 60}:{s % 60:00}";
        }

        /// <summary>"The winner is X" (the most kills, or the longest alive) on everyone's screen and in the chat; 'title'
        /// above it instead (the automatic end's "Event over").</summary>
        static void AnnounceWinner(bool byKills, string title)
        {
            var best = new List<ulong>();
            float top = 0f;
            if (byKills) { foreach (var kv in kills) Consider(kv.Key, kv.Value); }
            else { foreach (var kv in alive) Consider(kv.Key, kv.Value); }
            void Consider(ulong id, float v)
            {
                if (v <= 0f || NetSquad.Find(id) == null) return;
                if (v > top + 0.001f) { best.Clear(); top = v; }
                if (Mathf.Abs(v - top) <= 0.001f) best.Add(id);
            }
            string line;
            if (best.Count == 0) line = X("mpEventNoWinner", "No winner");
            else
            {
                var names = new List<string>();
                foreach (var id in best) names.Add(NetSquad.Find(id).DisplayName);
                string who = string.Join(" & ", names);
                line = byKills
                    ? string.Format(X("mpEventWinnerKills", "The winner is {0} with {1} kills"), who, (int)top)
                    : string.Format(X("mpEventWinnerTime", "The winner is {0}, alive for {1}"), who, Clock(top));
            }
            NetCommands.RunOnServer("title", "@a " + (title != null ? title + " | " + line : line) + " for 8", null);
            NetState.Instance?.NoticeAll(line + ".");
            Debug.Log($"Server: event {running}: {line}");
        }

        // ---- spawned ships ------------------------------------------------------------------------------------

        /// <summary>NetAdmin.Spawn, while a script's spawn line runs: a new batch tag for 'count' ships to one player (0 when
        /// no event is running the command).</summary>
        internal static int NewBatch(int count, bool enemy)
        {
            if (!executing) return 0;
            int tag = nextTag++;
            if (nextTag > 0x7ffff) nextTag = 1;
            batches[tag] = new Batch { expected = count, enemy = enemy, start = Time.unscaledTime };
            return tag;
        }

        /// <summary>This event's living spawned ships (only the enemies), the ones on their way included.</summary>
        static int CountShips(bool enemiesOnly)
        {
            if (batches.Count == 0) return 0;
            int living = 0;
            foreach (var proxy in UnityEngine.Object.FindObjectsByType<NetProxy>())
            {
                if (proxy == null || !proxy.IsSpawned || proxy.EventTag == 0 || !batches.TryGetValue(proxy.EventTag, out var b)) continue;
                b.seen.Add(ShipKey(proxy));
                if (enemiesOnly && !b.enemy) continue;
                if (proxy.FlyingNow) living++;
            }
            float now = Time.unscaledTime;
            foreach (var b in batches.Values)
                if ((!enemiesOnly || b.enemy) && now - b.start < PendingSeconds) living += Math.Max(0, b.expected - b.seen.Count);
            return living;
        }

        // ---- expressions -----------------------------------------------------------------------------------------

        /// <summary>A command line with its {expression} parts filled in.</summary>
        static string Fill(string line)
        {
            if (line.IndexOf('{') < 0) return line;
            var sb = new System.Text.StringBuilder();
            int i = 0;
            while (i < line.Length)
            {
                int open = line.IndexOf('{', i);
                if (open < 0) { sb.Append(line, i, line.Length - i); break; }
                int close = line.IndexOf('}', open + 1);
                if (close < 0) throw new Exception(X("mpEventBrace", "a { without its }."));
                sb.Append(line, i, open - i);
                sb.Append(Format(Eval(line.Substring(open + 1, close - open - 1))));
                i = close + 1;
            }
            return sb.ToString();
        }

        static string Format(double v) =>
            Math.Abs(v - Math.Round(v)) < 1e-9 ? ((long)Math.Round(v)).ToString(CultureInfo.InvariantCulture) : v.ToString("0.##", CultureInfo.InvariantCulture);

        static double Eval(string text)
        {
            var p = new Parser(text);
            double v = p.Or();
            p.SkipSpace();
            if (!p.AtEnd) throw new Exception(string.Format(X("mpEventExpr", "can't read \"{0}\"."), text));
            return v;
        }

        static double Value(string name)
        {
            switch (name)
            {
                case "enemies": return CountShips(true);
                case "ships": return CountShips(false);
                case "time": return Time.unscaledTime - startTime;
                case "players": case "inspace": case "docked": case "dead":
                {
                    int n = 0;
                    foreach (var p in NetPlayer.All)
                    {
                        if (p == null || !p.IsSpawned) continue;
                        bool count = name == "players" || (name == "inspace" && p.InSpace && p.Hull > 0f)
                                     || (name == "docked" && p.InHangar) || (name == "dead" && p.InSpace && p.Hull <= 0f);
                        if (count) n++;
                    }
                    return n;
                }
            }
            if (vars.TryGetValue(name, out double v)) return v;
            throw new Exception(string.Format(X("mpEventNoVar", "no variable \"{0}\" (set it first)."), name));
        }

        /// <summary>A small recursive-descent evaluator: or / and / not, comparisons, + -, * / %, unary -, ( ), numbers,
        /// names and the functions random, min, max.</summary>
        sealed class Parser
        {
            readonly string s;
            int i;
            public Parser(string text) { s = text ?? ""; }
            public bool AtEnd => i >= s.Length;
            public void SkipSpace() { while (i < s.Length && char.IsWhiteSpace(s[i])) i++; }

            bool Word(string w)
            {
                SkipSpace();
                if (string.Compare(s, i, w, 0, w.Length, StringComparison.OrdinalIgnoreCase) != 0) return false;
                int end = i + w.Length;
                if (end < s.Length && (char.IsLetterOrDigit(s[end]) || s[end] == '_')) return false;
                i = end;
                return true;
            }

            bool Sym(string sym)
            {
                SkipSpace();
                if (string.CompareOrdinal(s, i, sym, 0, sym.Length) != 0) return false;
                i += sym.Length;
                return true;
            }

            public double Or()
            {
                double v = And();
                while (Word("or") || Sym("||")) { double r = And(); v = v != 0 || r != 0 ? 1 : 0; }
                return v;
            }

            double And()
            {
                double v = Not();
                while (Word("and") || Sym("&&")) { double r = Not(); v = v != 0 && r != 0 ? 1 : 0; }
                return v;
            }

            double Not()
            {
                if (Word("not")) return Not() == 0 ? 1 : 0;
                if (Peek('!') && !PeekAt(1, '=')) { i++; return Not() == 0 ? 1 : 0; }
                return Compare();
            }

            bool Peek(char c) { SkipSpace(); return i < s.Length && s[i] == c; }
            bool PeekAt(int k, char c) => i + k < s.Length && s[i + k] == c;

            double Compare()
            {
                double v = Sum();
                if (Sym("==")) return v == Sum() ? 1 : 0;
                if (Sym("!=")) return v != Sum() ? 1 : 0;
                if (Sym("<=")) return v <= Sum() ? 1 : 0;
                if (Sym(">=")) return v >= Sum() ? 1 : 0;
                if (Sym("<")) return v < Sum() ? 1 : 0;
                if (Sym(">")) return v > Sum() ? 1 : 0;
                if (Sym("=")) return v == Sum() ? 1 : 0;
                return v;
            }

            double Sum()
            {
                double v = Product();
                while (true)
                {
                    if (Sym("+")) v += Product();
                    else if (Sym("-")) v -= Product();
                    else return v;
                }
            }

            double Product()
            {
                double v = Unary();
                while (true)
                {
                    if (Sym("*")) v *= Unary();
                    else if (Sym("/")) { double d = Unary(); v = d == 0 ? 0 : v / d; }
                    else if (Sym("%")) { double d = Unary(); v = d == 0 ? 0 : v % d; }
                    else return v;
                }
            }

            double Unary()
            {
                if (Sym("-")) return -Unary();
                if (Sym("+")) return Unary();
                return Atom();
            }

            double Atom()
            {
                SkipSpace();
                if (Sym("(")) { double v = Or(); if (!Sym(")")) throw new Exception("\")\" missing."); return v; }
                int start = i;
                if (i < s.Length && (char.IsDigit(s[i]) || s[i] == '.'))
                {
                    while (i < s.Length && (char.IsDigit(s[i]) || s[i] == '.')) i++;
                    return double.Parse(s.Substring(start, i - start), CultureInfo.InvariantCulture);
                }
                if (i < s.Length && (char.IsLetter(s[i]) || s[i] == '_'))
                {
                    while (i < s.Length && (char.IsLetterOrDigit(s[i]) || s[i] == '_')) i++;
                    string name = s.Substring(start, i - start).ToLowerInvariant();
                    if (Sym("("))
                    {
                        var args = new List<double>();
                        if (!Sym(")"))
                        {
                            do args.Add(Or()); while (Sym(","));
                            if (!Sym(")")) throw new Exception("\")\" missing.");
                        }
                        return Call(name, args);
                    }
                    return Value(name);
                }
                throw new Exception(string.Format("can't read \"{0}\".", s));
            }

            static double Call(string name, List<double> a)
            {
                switch (name)
                {
                    case "random" when a.Count == 2:
                        int lo = (int)Math.Floor(Math.Min(a[0], a[1])), hi = (int)Math.Floor(Math.Max(a[0], a[1]));
                        return UnityEngine.Random.Range(lo, hi + 1);
                    case "min" when a.Count == 2: return Math.Min(a[0], a[1]);
                    case "max" when a.Count == 2: return Math.Max(a[0], a[1]);
                    case "floor" when a.Count == 1: return Math.Floor(a[0]);
                }
                throw new Exception(string.Format("no function {0} with {1} value(s).", name, a.Count));
            }
        }
    }
}
