// Radio.cs
// A campaign level's radio messages (Radio / RadioMessage, Reference/research/dialogue_cutscenes.md 2): the lines of
// Level::createRadioMessages for the index (StoryStep.radio), each shown once when its trigger holds.
//   RadioMessage::triggered 0x17c5d8    tested in array order while no line is showing; the first newly true one shows
//   Radio::update / draw 0x180380       nothing for 2000 ms, then the box for lines * 2000 + 1500 ms; the voice plays when
//                                       it appears; "over" when the display time has passed
// Trigger types implemented (the rest never fire yet): 0 route waypoint passed, 1 any listed ship dead, 3 / 4 no
// enemies / friends left, 5 time, 6 chained on a line, 8 any listed ship active, 9 all listed dead, 0xc / 0x13 / 0x1f
// listed ship below 1/2, 1/4, 3/4 hull, 0xf any ship dead, 0x10 a hostile ship active, 0x14 >= n ships dead, 0x16 crate
// cargo captured, 0x17 station locked, 0x1b level-script event, 0x1c player armor gone, 0x1e dead count among ships 2-5.
// Lines are counted for the duration from the text length (the original counts wrapped lines of 670 px).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    /// <summary>What the radio triggers read from the level (Level / LevelScript / Radar state).</summary>
    public interface IRadioWorld
    {
        float MissionMs { get; }           // LevelScript+8: the mission clock (reset by the briefing)
        int ScriptEvent { get; }           // LevelScript+0x1c
        int ShipCount { get; }
        bool ShipDead(int i);
        bool ShipActive(int i);            // awake, alive
        float ShipHullFraction(int i);
        bool ShipHostile(int i);
        int RouteIndex { get; }            // the player route's current waypoint
        int CrateCargoCaptured { get; }    // Level+0x1c
        bool StationLocked { get; }
        bool PlayerArmorGone { get; }
        int EnemiesLeft { get; }
        int FriendsLeft { get; }
    }

    public class Radio
    {
        const float DelayMs = 2000f, LineMs = 2000f, ExtraMs = 1500f, CharsPerLine = 55f;

        readonly List<RadioLine> lines;
        readonly bool[] triggered, over;
        int showing = -1;
        float showMs, durationMs;

        public Radio(List<RadioLine> radioLines)
        {
            lines = radioLines ?? new List<RadioLine>();
            triggered = new bool[lines.Count];
            over = new bool[lines.Count];
        }

        public int Count => lines.Count;
        public bool Triggered(int i) => i >= 0 && i < triggered.Length && triggered[i];
        public bool Over(int i) => i >= 0 && i < over.Length && over[i];
        /// <summary>Radio::lastMessageShown: the array's last line is over.</summary>
        public bool LastOver => lines.Count > 0 && over[lines.Count - 1];
        /// <summary>The line on screen now (after the 2 s delay), null = none. Fast-forward is blocked while it shows.</summary>
        public RadioLine Visible => showing >= 0 && showMs >= DelayMs ? lines[showing] : null;
        public int VisibleIndex => Visible != null ? showing : -1;
        public bool Busy => showing >= 0;

        /// <summary>LevelScript::skipCutscene: the first 'n' lines count as shown.</summary>
        public void MarkShown(int n)
        {
            for (int i = 0; i < n && i < lines.Count; i++) triggered[i] = over[i] = true;
            if (showing >= 0 && showing < n) showing = -1;
        }

        public void Update(float dtMs, IRadioWorld w)
        {
            if (showing >= 0)
            {
                showMs += dtMs;
                if (showMs >= DelayMs + durationMs) { over[showing] = true; showing = -1; }
                return;
            }
            for (int i = 0; i < lines.Count; i++)
            {
                if (triggered[i] || !Test(lines[i], w)) continue;
                triggered[i] = true;
                showing = i;
                showMs = 0f;
                int n = Mathf.Max(1, Mathf.CeilToInt(Localization.Get(lines[i].text).Length / CharsPerLine));
                durationMs = n * LineMs + ExtraMs;
                return;
            }
        }

        bool Test(RadioLine m, IRadioWorld w)
        {
            int p = m.param, count = Mathf.Max(1, m.count);
            bool Any(Func<int, bool> f) { for (int k = p; k < p + count; k++) if (k < w.ShipCount && f(k)) return true; return false; }
            bool All(Func<int, bool> f) { for (int k = p; k < p + count; k++) if (k >= w.ShipCount || !f(k)) return false; return true; }
            int DeadShips() { int d = 0; for (int k = 0; k < w.ShipCount; k++) if (w.ShipDead(k)) d++; return d; }
            switch (m.trigger)
            {
                case 0: return w.RouteIndex > p;
                case 1: return Any(w.ShipDead);
                case 3: return w.EnemiesLeft < 1;
                case 4: return w.FriendsLeft < 1;
                case 5: return w.MissionMs >= p;
                case 6: return Triggered(p) && Over(p);   // shows right after that line
                case 8: return Any(w.ShipActive);
                case 9: return All(w.ShipDead);
                case 0xc: return Any(k => !w.ShipDead(k) && w.ShipHullFraction(k) < 0.5f);
                case 0x13: return Any(k => !w.ShipDead(k) && w.ShipHullFraction(k) < 0.25f);
                case 0x1f: return Any(k => !w.ShipDead(k) && w.ShipHullFraction(k) < 0.75f);
                case 0xf: return DeadShips() > 0;
                case 0x10: for (int k = 0; k < w.ShipCount; k++) if (w.ShipActive(k) && w.ShipHostile(k)) return true; return false;
                case 0x14: return DeadShips() >= p;
                case 0x16: return w.CrateCargoCaptured >= p;
                case 0x17: return w.StationLocked;
                case 0x1b: return w.ScriptEvent == p;
                case 0x1c: return w.PlayerArmorGone;
                case 0x1e: { int d = 0; for (int k = 2; k <= 5 && k < w.ShipCount; k++) if (w.ShipDead(k)) d++; return d == p; }
                default: return false;
            }
        }
    }
}
