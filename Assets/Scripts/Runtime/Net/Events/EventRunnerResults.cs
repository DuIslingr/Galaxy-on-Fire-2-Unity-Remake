// EventRunnerResults.cs
// Part of EventRunner: EventRun's points and scoreboard, the results and the winner, and the ships it spawned
// (batches, counting them).

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using GoF2Remake.Data;
using UnityEngine;
using GoF2Remake.Multiplayer;

namespace GoF2Remake.Events
{
    public static partial class EventRunner
    {
        sealed partial class EventRun
        {
            // ---- points and the scoreboard -------------------------------------------------------------------------

            /// <summary>"points &lt;players&gt; &lt;amount&gt;": the amount added to each player the selector finds (none found: nothing).</summary>
            void AddPoints(string selector, double amount)
            {
                var list = NetCommands.FindTargets(selector, null, out _, out string error);
                if (list.Count == 0 && error != null && error != NetCommands.NobodyMatches) throw new Exception(error);
                foreach (var p in list)
                {
                    points.TryGetValue(p.OwnerClientId, out double v);
                    points[p.OwnerClientId] = v + amount;
                }
            }

            /// <summary>A player's score in a mode (points, kills, seconds alive).</summary>
            double ScoreOf(ulong id, ScoreMode mode)
            {
                switch (mode)
                {
                    case ScoreMode.Points: return points.TryGetValue(id, out double p) ? p : 0;
                    case ScoreMode.Kills: return kills.TryGetValue(id, out int k) ? k : 0;
                    default: return alive.TryGetValue(id, out float a) ? a : 0;
                }
            }

            static string ScoreText(double v, ScoreMode mode) => mode == ScoreMode.Time ? Clock((float)v) : Format(v);

            /// <summary>While on: every second the scoreboard (its title, then "name TAB score" rows, the best first) to every
            /// player when it changed, and every 5 s anyway (players who just joined).</summary>
            void UpdateScoreboard()
            {
                if (!scoreboardOn) return;
                if ((scoreboardTimer -= EventHost.DeltaTime) > 0f) return;
                scoreboardTimer = 1f;
                var rows = new List<(string name, double score)>();
                foreach (var p in EventHost.Pilots)
                    if (p != null && p.IsSpawned && InScope(p)) rows.Add((p.DisplayName, ScoreOf(p.OwnerClientId, scoreMode)));
                rows.Sort((x, y) => y.score.CompareTo(x.score));
                var sb = new System.Text.StringBuilder(scoreboardTitle.Length > 0 ? scoreboardTitle : X("mpEventScoreboard", "Scoreboard"));
                for (int i = 0; i < rows.Count && i < ScoreboardRows; i++) sb.Append('\n').Append(rows[i].name).Append('\t').Append(ScoreText(rows[i].score, scoreMode));
                string text = sb.ToString();
                if (text == scoreboardSent && (scoreboardResend -= 1f) > 0f) return;
                scoreboardResend = 5f;
                SendScoreboard(text);
            }

            /// <summary>The scoreboard to every player ("" hides it).</summary>
            void SendScoreboard(string text)
            {
                scoreboardSent = text.Length > 0 ? text : null;
                if (!EventHost.ServerReady) return;
                foreach (var p in EventHost.Pilots)
                    if (p != null && p.IsSpawned && InScope(p)) EventHost.Send(p.OwnerClientId, NetAdmin.Order.Scoreboard, 0, 0, 0, text, "Server");
            }

            // ---- results and the winner -----------------------------------------------------------------------------

            /// <summary>One NPC whatever proxy shows it: its owner and its index in the owner's traffic (a ship's proxy can be made
            /// again, and Netcode reuses network ids).</summary>

            void ClearStats()
            {
                kills.Clear();
                alive.Clear();
                outOfFight.Clear();
                countedKills.Clear();
                points.Clear();
                scoreMode = ScoreMode.Time;
            }

            /// <summary>Every 0.25 s: the event ships destroyed since (each once, to its killer), and the time alive in space of
            /// every player still in the fight (from the event's first spawn; destroyed = out for good).</summary>
            void UpdateStats()
            {
                statsTimer += EventHost.DeltaTime;
                if (statsTimer < CheckSeconds) return;
                float dt = statsTimer;
                statsTimer = 0f;
                if (batches.Count == 0) return;   // the fight hasn't begun
                foreach (var ship in EventHost.EventShips())
                {
                    if (!batches.TryGetValue(ship.tag, out var batch)) continue;
                    Observe(batch, ship);
                    if (ship.killer == ulong.MaxValue || !countedKills.Add(ship.key)) continue;
                    kills.TryGetValue(ship.killer, out int k);
                    kills[ship.killer] = k + 1;
                    var killer = EventHost.Find(ship.killer);
                    Fire("kill", ship.killer, killer != null ? killer.DisplayName : "", ship.station);
                }
                foreach (var p in EventHost.Pilots)
                {
                    if (p == null || !p.IsSpawned || !InScope(p) || outOfFight.Contains(p.OwnerClientId) || !p.InSpace) continue;
                    if (p.Hull <= 0f) { if (alive.ContainsKey(p.OwnerClientId)) outOfFight.Add(p.OwnerClientId); continue; }
                    alive.TryGetValue(p.OwnerClientId, out float a);
                    alive[p.OwnerClientId] = a + dt;
                }
            }

            /// <summary>@survivors: a player alive in space who has been in this event's fight and never destroyed in it.</summary>
            public bool Survived(IPilot p) =>
                !ended && p != null && InScope(p) && p.InSpace && p.Hull > 0f && alive.ContainsKey(p.OwnerClientId) && !outOfFight.Contains(p.OwnerClientId);

            static string Clock(float seconds)
            {
                int s = Mathf.FloorToInt(seconds);
                return $"{s / 60}:{s % 60:00}";
            }

            /// <summary>"The winner is X" (the most kills, points, or the longest alive) on everyone's screen and in the chat;
            /// 'title' above it instead (the automatic end's "Event over").</summary>
            void AnnounceWinner(ScoreMode mode, string title)
            {
                var best = new List<ulong>();
                double top = 0;
                var ids = new HashSet<ulong>();
                if (mode == ScoreMode.Kills) foreach (var id in kills.Keys) ids.Add(id);
                else if (mode == ScoreMode.Points) foreach (var id in points.Keys) ids.Add(id);
                else foreach (var id in alive.Keys) ids.Add(id);
                foreach (var id in ids)
                {
                    double v = ScoreOf(id, mode);
                    if (v <= 0 || EventHost.Find(id) == null) continue;
                    if (v > top + 0.001) { best.Clear(); top = v; }
                    if (Math.Abs(v - top) <= 0.001) best.Add(id);
                }
                string line;
                if (best.Count == 0) line = X("mpEventNoWinner", "No winner");
                else
                {
                    var names = new List<string>();
                    foreach (var id in best) names.Add(EventHost.Find(id).DisplayName);
                    string who = string.Join(" & ", names);
                    line = mode == ScoreMode.Kills ? string.Format(X("mpEventWinnerKills", "The winner is {0} with {1} kills"), who, (int)top)
                        : mode == ScoreMode.Points ? string.Format(X("mpEventWinnerPoints", "The winner is {0} with {1} points"), who, Format(top))
                        : string.Format(X("mpEventWinnerTime", "The winner is {0}, alive for {1}"), who, Clock((float)top));
                }
                NetCommands.RunOnServer("title", "@a " + (title != null ? title + " | " + line : line) + " for 8", null);
                NoticeScope(line + ".");
                Debug.Log($"Server: event {running}: {line}");
            }

            // ---- spawned ships ------------------------------------------------------------------------------------

            /// <summary>NetAdmin.Spawn, while a script's spawn line runs: a new batch tag for 'count' ships to one player (0 when
            /// no event is running the command).</summary>
            internal int NewBatch(int count, bool enemy)
            {
                int tag = nextTag++;
                if (nextTag > 0x7ffff) nextTag = 1;
                batches[tag] = new Batch { expected = count, enemy = enemy, start = EventHost.Now };
                return tag;
            }

            /// <summary>Notes a batch's ship: seen, its orbit, and whether it is down (dying or dead).</summary>
            static void Observe(Batch b, EventHost.Ship ship)
            {
                b.seen.Add(ship.key);
                b.stations.Add(ship.station);
                if (!ship.flying) b.down.Add(ship.key);
            }

            /// <summary>This event's living spawned ships (only the enemies), the ones on their way included.</summary>
            int CountShips(bool enemiesOnly)
            {
                if (batches.Count == 0) return 0;
                foreach (var ship in EventHost.EventShips())
                {
                    if (batches.TryGetValue(ship.tag, out var b)) Observe(b, ship);
                }
                // A batch counts its ships until each was seen dying or dead. A ship that just vanishes (its game jumped or
                // docked away, which unloads its traffic) is still alive: counting only the ships present let a player
                // clear a mission by leaving the orbit right after the spawn. A taken-over ship gets a new key, its old
                // copy despawned, so 'expected - down' (not 'seen - down') is the count. A batch nothing of was ever seen
                // counts only while its ships may still be on their way (the spawn reached nobody).
                int living = 0;
                float now = EventHost.Now;
                foreach (var b in batches.Values)
                {
                    if (enemiesOnly && !b.enemy) continue;
                    if (b.seen.Count == 0 && now - b.start >= PendingSeconds) continue;
                    living += Math.Max(0, b.expected - b.down.Count);
                }
                return living;
            }
        }
    }
}
