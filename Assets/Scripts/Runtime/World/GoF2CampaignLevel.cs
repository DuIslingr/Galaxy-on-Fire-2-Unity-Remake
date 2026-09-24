// GoF2CampaignLevel.cs
// The content of an orbit built around a campaign mission (Level::createCampaignMission 0xc3370, LevelScript::process
// 0x160d50; Reference/research/campaign_levels_a.md, levelscript_cutscenes.md): the step's ships in the original's
// order (Level+0xf8, which the radio triggers and objectives index), its radio messages (GoF2Radio), the player route
// (HUD waypoints, Level+0x108), the level-script event and mission clock, and the win / fail objectives. Created by
// GoF2SpaceLevel when GoF2Story.IsLevelMission holds for the orbit; normal traffic is off then (GoF2Traffic). Indices
// without a case spawn nothing (an empty orbit) but still play their radio lines. The level keeps running after its
// success dialogue with the next index (e.g. 4 -> 5 on the same ships).
// Built so far: 4 / 5 (mining, the pirate ambush), 7 (the pirate trap with Gunant Breh).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    public class GoF2CampaignLevel : MonoBehaviour, IGoF2RadioWorld
    {
        const float M = 0.05f;

        public readonly List<GoF2NpcShip> Ships = new List<GoF2NpcShip>();
        public GoF2Radio Radio { get; private set; }
        /// <summary>Level+0x108: the player route (game units), shown as HUD waypoints; null = none.</summary>
        public GoF2Route PlayerRoute { get; private set; }
        public int BuiltIndex { get; private set; }
        public int Event { get; set; }
        public float MissionMs { get; private set; }
        /// <summary>Level::checkObjective (Level+0x28) / checkGameOver (+0x2c).</summary>
        public bool Won => win != null && win();
        public bool Failed => fail != null && fail();

        GoF2SpaceLevel level;
        GoF2Traffic traffic;
        System.Func<bool> win, fail;

        static Vector3 ToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z) * M;
        static Vector3 ToGame(Vector3 unity) => new Vector3(unity.x, unity.y, -unity.z) / M;
        static Vector3 Jitter() => new Vector3(Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000);

        public void Setup(GoF2SpaceLevel spaceLevel, GoF2Traffic npcTraffic)
        {
            level = spaceLevel;
            traffic = npcTraffic;
            BuiltIndex = GoF2Story.Index;
            Build(BuiltIndex);
            traffic.ConnectPlayers();
            Radio = new GoF2Radio(GoF2Story.Step?.radio);
            Debug.Log($"GoF2CampaignLevel: index {BuiltIndex}, {Ships.Count} ships, {Radio.Count} radio lines");
        }

        /// <summary>MGame::dialogueEvent: the briefing restarts the mission clock.</summary>
        public void ResetClock() => MissionMs = 0f;

        /// <summary>Level::createShip(race, kind, ship, waypoint ...): at the waypoint +- 20 000 per axis.</summary>
        GoF2NpcShip Ship(int race, int ship, Vector3 waypoint, bool jitter = true, System.Action<GoF2SpawnSpec> setup = null)
        {
            var spec = new GoF2SpawnSpec { group = GoF2NpcGroup.Raider, race = race, ship = ship, position = waypoint + (jitter ? Jitter() : Vector3.zero) };
            setup?.Invoke(spec);
            var s = traffic.SpawnShip(spec);
            Ships.Add(s);
            return s;
        }

        void Build(int index)
        {
            var player = level.Player.transform;
            switch (index)
            {
                case 4:
                    // One pirate (ship 2 Hiro) far out, inactive, always-enemy, asleep; index 5's script brings it in.
                    Ship(GoF2Standing.Pirate, 2, new Vector3(0, 0, -200000), true, s => { s.inactive = true; s.alwaysEnemy = true; });
                    break;
                case 7:
                {
                    // Player route (-4000, -3000, 80 000) -> (10 000, 7000, 160 000); 3 pirates asleep at waypoint 1; Gunant
                    // Breh (Midorian ship 30) beside the player, flying the route, unkillable, always-friend.
                    var route = new GoF2Route(false);
                    route.points.Add(new Vector3(-4000, -3000, 80000));
                    route.points.Add(new Vector3(10000, 7000, 160000));
                    PlayerRoute = route;
                    for (int i = 0; i < 3; i++) Ship(GoF2Standing.Pirate, 2, route.points[1], true, s => { s.asleep = true; });
                    var gunantPos = ToGame(player.TransformPoint(new Vector3(-700, 50, 6000) * M));
                    Ship(3, 30, gunantPos, false, s => { s.alwaysFriend = true; s.hitpoints = 9999999; s.route = route.Clone(); s.nameText = 1599; });
                    win = () => DeadRange(0, 3);   // Objective 0x12 (0, 3)
                    break;
                }
            }
        }

        bool DeadRange(int a, int b)
        {
            for (int i = a; i < b; i++) if (!ShipDead(i)) return false;
            return true;
        }

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            if (dtMs <= 0f) return;
            MissionMs += dtMs;
            if (PlayerRoute != null && level.Player != null) PlayerRoute.Update(ToGame(level.Player.transform.position));
            Script(GoF2Story.Index);
            if (!level.Dialogue && level.StartSequenceOver) Radio?.Update(dtMs, this);   // not during the launch / arrival camera
        }

        /// <summary>LevelScript::process per index (campaign_levels_a.md 3).</summary>
        void Script(int index)
        {
            switch (index)
            {
                case 5:
                    // On index 4's level: ship 0 comes at the player from player + (5000, 0, 30 000) (world axes) and wakes.
                    if (Event == 0 && BuiltIndex == 4 && Ships.Count > 0)
                    {
                        Event = 1;
                        var p = ToGame(level.Player.transform.position) + new Vector3(5000, 0, 30000);
                        Ships[0].Place(ToUnity(p), level.Player.transform.position - ToUnity(p));
                        Ships[0].Wake();
                    }
                    break;
            }
        }

        // ---- IGoF2RadioWorld -------------------------------------------------------------------------------

        public int ScriptEvent => Event;
        public int ShipCount => Ships.Count;
        public bool ShipDead(int i) => i >= 0 && i < Ships.Count && (Ships[i] == null || !Ships[i].Target.Alive);
        public bool ShipActive(int i) => i >= 0 && i < Ships.Count && Ships[i] != null && !Ships[i].Gone && !Ships[i].Asleep && Ships[i].Target.Alive;
        public float ShipHullFraction(int i) => i >= 0 && i < Ships.Count && Ships[i] != null ? Ships[i].Target.HullFraction : 0f;
        public bool ShipHostile(int i) => i >= 0 && i < Ships.Count && Ships[i] != null && Ships[i].Target.hostileToPlayer && !Ships[i].alwaysFriend;
        public int RouteIndex => PlayerRoute != null ? PlayerRoute.index : 0;
        public int CrateCargoCaptured => 0;
        public bool StationLocked => level.Navigation != null && level.Navigation.Locked != null && level.Navigation.Locked.kind == GoF2Navigation.Kind.Station;
        public bool PlayerArmorGone => level.Health != null && level.Health.HasArmor && level.Health.Hp.armor < 1;
        public int EnemiesLeft { get { int n = 0; for (int i = 0; i < Ships.Count; i++) if (!ShipDead(i) && ShipHostile(i)) n++; return n; } }
        public int FriendsLeft { get { int n = 0; for (int i = 0; i < Ships.Count; i++) if (!ShipDead(i) && !ShipHostile(i)) n++; return n; } }
    }
}
