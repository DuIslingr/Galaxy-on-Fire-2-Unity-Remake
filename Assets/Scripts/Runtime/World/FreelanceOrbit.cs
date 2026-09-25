// FreelanceOrbit.cs
// A freelance mission's orbit (Level::createMission 0xbda70 with a non-empty level mission, MGame::dialogueEvent /
// successCheck / gameOverCheck; Reference/research/freelance_missions.md 4). Created by SpaceLevel when the orbit is
// the freelance mission's target (Freelance.IsMissionOrbit); the free-flight traffic is off then. hc = 1 + (difficulty
// - 0.5) (x1 normal, x2 Extreme), d = the mission's difficulty, A = 75 % pirates else the system's enemy race, E = the
// client race's enemy (pirates for other races):
//   1 Defense        int((int(d/10*5)+3)*hc) race-A fighters around the station (always enemy) + nextInt(5)+3 system-race
//                    friends on a route; win: the attackers dead (objective 7)
//   2 Protection     int(d/10*4)+2 race-A attackers from (-20000-rnd, 0, -20000-rnd) (+2000 apart) heading for the origin;
//                    'amount' system-race fighters parked 2000 above the asteroids, x3 hull, always friend; win: attackers
//                    dead / fail: all miners dead (0x12)
//   3 / 5 Recovery / Salvage  'amount' pirates asleep at (+-(40000+rnd 80000), 0, +-(...)); the last, "Hijacker" (1611),
//                    carries the container (117 / 116, swapped against the offer like the original); win: the container
//                    aboard (EMP + tractor beam) -> bring it to the client / fail: the carrier destroyed first (0xb / 0xc)
//   4 Pirate hunting int((int(d/10*5)+2)*hc) pirates asleep at the asteroid field (or a createRoute point); win: all dead
//   6 Wanted         one pirate asleep at (+-(60000+rnd 80000), 0, +-(...)), x3 hull, speed 3.0, named; win: it's dead
//   7 Junk removal   int(d/10*20)+15 space junk (hull 1, always enemy) around a point 40-70 km ahead + int(0.2d) pirates;
//                    121 000 ms (Level+0x130, checked every 5 s); win: all junk destroyed
//   9 Escort         int((int(d/10*5)+3)*hc) race-E attackers asleep on a route ahead; 5 client-race freighters at fixed
//                    points flying +Z, hull (2*min(level,20) + 150 + 2*campaign) (x1.4 Extreme), always friend; win:
//                    attackers dead / fail: all freighters dead
//   10 Intercept     race E (pirates -> Terran): nextInt(2)+2 convoy freighters asleep and parked around a route point,
//                    hull x0.7 (x1.4 Extreme) + int((int(d/10*5)+3)*hc) escorts asleep; win: the convoy dead
//   12 Challenge     the agent's ship (its race, 9 999 999 hull, speed 3.0, named, friend) flies a createRoute(3..4) past
//                    an odd number of sleeping pirates (i = int(d/10*4): i+3 if odd else i+4); win: all dead with more
//                    kills than the rival (0x14) / fail: all dead, the rival as good or better (0x15)
// Briefing (after the launch / arrival camera, not for 0 / 8 / 11): Challenge 372, Junk 378, else 379-383; the game pauses.
// Checks from 5000 ms of level time. Success: 3 / 5 turn into the return trip (389), the others pay (reward message +
// sound 36, standing +5). Failure: 384-388 + 392 (Challenge 371 with the score). The remake marks the pirates' location
// with a waypoint for the hunting-type missions (the original's HUD shows no freelance marker).

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;
using Random = UnityEngine.Random;

namespace GoF2Remake.World
{
    public class FreelanceOrbit : MonoBehaviour
    {
        const float M = 0.05f;
        public const float JunkTimeMs = 121000f;

        /// <summary>Show a bar agent's one-page message (text, name, portrait) and call the action when it closes.</summary>
        /// <summary>(text, client name, portrait, voice line, closed).</summary>
        public event Action<string, string, int[], string, Action> MessageRequested;
        public event Action<string> RewardMessage;
        public bool DialogueOpen { get; private set; }
        public Route PlayerRoute { get; private set; }
        public int Type => mission.type;
        /// <summary>Junk removal: time left (ms), -1 = no limit.</summary>
        public float TimeLeftMs => mission.type == MissionType.JunkRemoval ? Mathf.Max(0f, JunkTimeMs - missionMs) : -1f;

        SpaceLevel level;
        Traffic traffic;
        FreelanceMission mission;
        readonly List<NpcShip> enemies = new List<NpcShip>(), friends = new List<NpcShip>();
        readonly List<Target> junk = new List<Target>();
        NpcShip carrier, rival;
        int playerKills, otherKills;
        float levelMs, missionMs, timeCheckMs;
        bool briefed, done;

        static Vector3 ToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z) * M;
        static Vector3 ToGame(Vector3 unity) => new Vector3(unity.x, unity.y, -unity.z) / M;
        static Vector3 Jitter() => new Vector3(Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000);
        static float Sign() => Random.Range(0, 2) == 0 ? 1f : -1f;

        public void Setup(SpaceLevel spaceLevel, Traffic npcTraffic)
        {
            level = spaceLevel;
            traffic = npcTraffic;
            mission = Freelance.Mission;
            Build();
            traffic.ConnectPlayers();
            Debug.Log($"FreelanceOrbit: {mission.Name} (type {mission.type}, difficulty {mission.difficulty}), {enemies.Count} enemies, " +
                      $"{friends.Count} friends, {junk.Count} junk");
        }

        // ---- building (Level::createMission) ------------------------------------------------------------

        NpcShip Spawn(int race, Vector3 gamePos, Action<SpawnSpec> setup = null, bool enemy = true)
        {
            var spec = new SpawnSpec { group = NpcGroup.Raider, race = race, ship = NpcTables.RandomFighter(race), position = gamePos };
            setup?.Invoke(spec);
            var s = traffic.SpawnShip(spec);
            (enemy ? enemies : friends).Add(s);
            s.Target.Died += OnEnemyDied;
            return s;
        }

        void OnEnemyDied(Target t)
        {
            if (!enemies.Exists(e => e.Target == t)) return;
            if (t.killedByNpc) otherKills++; else playerKills++;   // Level+0x24 player kills / +0x20 kills by others
        }

        /// <summary>Level::createRoute(n) 0xd0464: x +-(50000 + rnd 30000), y +-10000, z advancing 50000 + rnd 30000.</summary>
        static Route CreateRoute(int n)
        {
            var r = new Route(false);
            float z = 0f;
            for (int i = 0; i < n; i++)
            {
                z += Random.Range(0, 30000) + 50000;
                r.points.Add(new Vector3(Sign() * (Random.Range(0, 30000) + 50000), Random.Range(0, 20000) - 10000, z));
            }
            return r;
        }

        void Build()
        {
            float hc = 1f + (Session.Difficulty - 0.5f);
            int d = mission.difficulty;
            float df = d / 10f;
            int systemRace = traffic.SystemRace;
            int attackRace = Random.Range(0, 100) < 75 ? Standing.Pirate : Standing.EnemyRaceOf(systemRace);
            int clientEnemy = Standing.EnemyRaceOf(mission.clientRace);
            switch (mission.type)
            {
                case MissionType.Defense:
                {
                    int n = (int)(((int)(df * 5f) + 3) * hc);
                    for (int i = 0; i < n; i++) Spawn(attackRace, Jitter(), s => s.alwaysEnemy = true);
                    float x = Sign() * 50000f;
                    var route = new Route(false);
                    route.points.Add(new Vector3(x, 0, 50000)); route.points.Add(new Vector3(x, 0, 75000)); route.points.Add(new Vector3(x, 0, 100000));
                    int f = Random.Range(0, 5) + 3;
                    for (int i = 0; i < f; i++) Spawn(systemRace, route.points[0] + Jitter(), s => { s.alwaysFriend = true; s.route = route.Clone(); }, false);
                    break;
                }
                case MissionType.Protection:
                {
                    int n = (int)(df * 4f) + 2;
                    var wp = new Vector3(-20000 - Random.Range(0, 20000), 0, -20000 - Random.Range(0, 20000));
                    for (int i = 0; i < n; i++)
                    {
                        var route = new Route(false);
                        route.points.Add(Vector3.zero);
                        Spawn(attackRace, wp + new Vector3(2000f * i, 0, 0), s => { s.alwaysEnemy = true; s.route = route; });
                    }
                    var rocks = level.Asteroids != null ? level.Asteroids.GetComponentsInChildren<Target>() : new Target[0];
                    for (int i = 0; i < mission.amount; i++)
                    {
                        Vector3 at = rocks.Length > 0 ? ToGame(rocks[Mathf.Min(rocks.Length - 1, i + rocks.Length / 2)].transform.position) + new Vector3(0, 2000, 0)
                                                      : Jitter();
                        var miner = Spawn(systemRace, at, s => { s.alwaysFriend = true; s.stationary = true; s.noLoot = true; }, false);
                        miner.Target.hitpoints.hull *= 3;   // Player::setHitpoints(max * 3)
                    }
                    break;
                }
                case MissionType.Recovery:
                case MissionType.Salvage:
                {
                    var at = new Vector3(Sign() * (40000 + Random.Range(0, 80000)), 0, Sign() * (40000 + Random.Range(0, 80000)));
                    int crateItem = mission.type == MissionType.Recovery ? Freelance.SecureCabin : Freelance.SecureContainer;
                    for (int i = 0; i < mission.amount; i++)
                    {
                        bool last = i == mission.amount - 1;
                        var s = Spawn(Standing.Pirate, at + Jitter(), spec =>
                        {
                            spec.asleep = true;
                            if (last) { spec.missionCrate = crateItem; spec.nameText = 1611; }
                        });
                        if (last) carrier = s;
                    }
                    MarkRoute(at);
                    break;
                }
                case MissionType.PirateHunting:
                {
                    var at = level.Asteroids != null ? ToGame(level.Asteroids.position) : CreateRoute(Random.Range(2, 4)).points[0];
                    int n = (int)(((int)(df * 5f) + 2) * hc);
                    for (int i = 0; i < n; i++) Spawn(Standing.Pirate, at + Jitter(), s => s.asleep = true);
                    MarkRoute(at);
                    break;
                }
                case MissionType.Wanted:
                {
                    var at = new Vector3(Sign() * (60000 + Random.Range(0, 80000)), 0, Sign() * (60000 + Random.Range(0, 80000)));
                    var w = Spawn(Standing.Pirate, at, s => { s.asleep = true; s.speed = 3f; s.name = mission.targetName; });
                    w.Target.hitpoints.hull = w.Target.hitpoints.maxHull *= 3;
                    w.Target.hp = w.Target.maxHp = w.Target.hitpoints.maxHull;
                    MarkRoute(at);
                    break;
                }
                case MissionType.JunkRemoval:
                {
                    var wp = new Vector3(Random.Range(0, 40000) - 20000, Random.Range(0, 20000) - 10000, Random.Range(0, 30000) + 40000);
                    int pirates = (int)(df + df);
                    int total = (int)(df * 20f) + pirates + 15;
                    for (int i = 0; i < total - pirates; i++) SpawnJunk(wp + new Vector3(Random.Range(0, 20000) - 10000, Random.Range(0, 20000) - 10000, Random.Range(0, 20000) - 10000));
                    for (int i = 0; i < pirates; i++) Spawn(Standing.Pirate, Jitter());
                    MarkRoute(wp);
                    break;
                }
                case MissionType.Escort:
                {
                    int n = (int)(((int)(df * 5f) + 3) * hc);
                    var route = new Route(false);
                    route.points.Add(new Vector3(10000, 0, 100000)); route.points.Add(new Vector3(10000, 0, 150000)); route.points.Add(new Vector3(10000, 0, 200000));
                    for (int i = 0; i < n; i++) Spawn(clientEnemy, route.points[0] + Jitter(), s => { s.asleep = true; s.route = route.Clone(); });
                    Vector3[] points = { new Vector3(-2500, -300, 27000), new Vector3(6500, 3000, 24000), new Vector3(-4000, -2000, 19000), new Vector3(9000, -6000, 17000), new Vector3(3000, 7000, 15000) };
                    int race = Mathf.Clamp(mission.clientRace, 0, 3);
                    int hull = (int)((2 * Mathf.Min(Session.Rank, 20) + 150 + 2 * Session.CampaignMission) * (Session.IsExtreme ? 1.4f : 1f));
                    foreach (var p in points)
                        Spawn(race, p, s => { s.freighter = true; s.ship = race == 1 ? 13 : 15; s.alwaysFriend = true; s.hitpoints = hull; s.noLoot = true; }, false);
                    break;
                }
                case MissionType.Intercept:
                {
                    int race = clientEnemy == Standing.Pirate ? 0 : clientEnemy;
                    var x = Sign() * 2500f; var y = Sign() * 2500f;
                    var route = new Route(false);
                    route.points.Add(new Vector3(x, y, 80000 + Random.Range(0, 30000)));
                    route.points.Add(new Vector3(x, y, 120000 + Random.Range(0, 30000)));
                    int convoy = Random.Range(0, 2) + 2;
                    for (int i = 0; i < convoy; i++)
                    {
                        var at = route.points[0] + new Vector3(Random.Range(0, 20000) - 10000, Random.Range(0, 20000) - 10000, Random.Range(0, 20000) - 10000);
                        var f = Spawn(race, at, s => { s.freighter = true; s.ship = race == 1 ? 13 : 15; s.stationary = true; s.alwaysEnemy = true; });
                        f.Target.hitpoints.hull = f.Target.hitpoints.maxHull = (int)(f.Target.hitpoints.maxHull * (Session.IsExtreme ? 1.4f : 0.7f));
                        f.Target.hp = f.Target.maxHp = f.Target.hitpoints.maxHull;
                    }
                    int escorts = (int)(((int)(df * 5f) + 3) * hc);
                    for (int i = 0; i < escorts; i++) Spawn(race, route.points[0] + Jitter(), s => { s.asleep = true; s.route = route.Clone(); s.alwaysEnemy = true; });
                    convoyCount = convoy;
                    MarkRoute(route.points[0]);
                    break;
                }
                case MissionType.Challenge:
                {
                    var route = CreateRoute(Random.Range(3, 5));
                    int i4 = (int)(df * 4f);
                    int pirates = i4 % 2 == 1 ? i4 + 3 : i4 + 4;
                    rival = Spawn(Mathf.Clamp(mission.clientRace, 0, 7) > 3 ? 0 : mission.clientRace, ToGame(level.Player.transform.position) + new Vector3(1500, 0, 3000),
                                  s => { s.alwaysFriend = true; s.hitpoints = 9999999; s.speed = 3f; s.route = route.Clone(); s.name = mission.clientName; s.noLoot = true; }, false);
                    for (int i = 0; i < pirates; i++)
                    {
                        var wp = route.points[Random.Range(0, route.points.Count)];
                        Spawn(Standing.Pirate, wp + Jitter(), s => s.asleep = true);
                    }
                    var player = route.Clone();
                    PlayerRoute = player;
                    break;
                }
            }
        }

        int convoyCount;

        void MarkRoute(Vector3 gamePoint)
        {
            var r = new Route(false);
            r.points.Add(gamePoint);
            PlayerRoute = r;
        }

        void SpawnJunk(Vector3 gamePos)
        {
            var assets = CombatAssets.Load();
            var prefab = assets != null && assets.junk != null && assets.junk.Length > 0 ? assets.junk[Random.Range(0, assets.junk.Length)] : null;
            var go = prefab != null ? Instantiate(prefab, ToUnity(gamePos), Random.rotation, transform) : new GameObject("Junk");
            go.name = "Space junk";
            var t = go.AddComponent<Target>();
            t.hp = t.maxHp = 1f;                 // Player(1000, 1, ...): one hit
            t.radius = 600f * M;
            t.race = Standing.Pirate;
            t.hostileToPlayer = true;
            var ex = assets != null ? assets.explosion : null;
            t.explosionPrefab = ex;
            t.explosionScale = 0.5f;
            t.Died += _ => Session.JunkDestroyed++;   // Status+0xb0
            junk.Add(t);
        }

        // ---- per frame (MGame::dialogueEvent / successCheck / gameOverCheck) ----------------------------

        void Update()
        {
            if (done || level == null || DialogueOpen || MessageRequested == null) return;
            float dt = Time.deltaTime * 1000f;
            levelMs += dt;
            missionMs += dt;
            if (level.Health != null && level.Health.Dead) return;
            if (!level.StartSequenceOver) return;
            if (!briefed)
            {
                briefed = true;
                int t = mission.type;
                if (t != MissionType.Courier && t != MissionType.Purchase && t != MissionType.Passenger)
                {
                    int text = t == MissionType.Challenge ? 372 : t == MissionType.JunkRemoval ? 378 : 379 + Random.Range(0, 5);
                    Open(Localization.Get(text), text, () => missionMs = 0f);
                    return;
                }
            }
            if (Failed()) { Fail(); return; }
            // Level+0x130: the time limit, checked every 5000 ms.
            if (mission.type == MissionType.JunkRemoval && (timeCheckMs += dt) >= 5000f)
            {
                timeCheckMs = 0f;
                if (missionMs >= JunkTimeMs && !Won()) { Fail(); return; }
            }
            if (levelMs >= 5000f && Won()) Succeed();
        }

        static bool AllDead(List<NpcShip> ships) => ships.TrueForAll(s => !s.Target.Alive || s.Current == NpcShip.State.Dying || s.Current == NpcShip.State.Dead);

        bool Won()
        {
            switch (mission.type)
            {
                case MissionType.Recovery:
                case MissionType.Salvage:
                {
                    int item = mission.type == MissionType.Recovery ? Freelance.SecureCabin : Freelance.SecureContainer;
                    return Session.Cargo.Exists(c => c.item == item && c.amount > 0);
                }
                case MissionType.JunkRemoval: return junk.TrueForAll(j => j == null || !j.Alive);
                case MissionType.Protection:
                case MissionType.Escort:
                case MissionType.Defense:
                case MissionType.PirateHunting:
                case MissionType.Wanted: return enemies.Count > 0 && AllDead(enemies);
                case MissionType.Intercept: return AllDead(enemies.GetRange(0, Mathf.Min(convoyCount, enemies.Count)));
                case MissionType.Challenge: return AllDead(enemies) && playerKills > otherKills;
            }
            return false;
        }

        bool Failed()
        {
            switch (mission.type)
            {
                case MissionType.Recovery:
                case MissionType.Salvage: return carrier != null && !carrier.MissionCrateTaken && (!carrier.Target.Alive || carrier.Current != NpcShip.State.Fly);
                case MissionType.Protection:
                case MissionType.Escort: return friends.Count > 0 && AllDead(friends);
                case MissionType.Challenge: return AllDead(enemies) && playerKills <= otherKills;
            }
            return false;
        }

        void Succeed()
        {
            done = true;
            var m = mission;
            if (m.type == MissionType.Recovery || m.type == MissionType.Salvage)
            {
                // MGame::successCheck: the orbit becomes a plain one; deliver the container to the client.
                Open(Freelance.ReturnText(level.Database), 389, () =>
                {
                    Freelance.ToReturnTrip();
                    level.Navigation?.SetRoute(null);
                });
                return;
            }
            Open(Freelance.SuccessText(out int successText, playerKills, otherKills), successText, () =>
            {
                int paid = Freelance.Succeed(false);
                RewardMessage?.Invoke($"{Localization.Get(216)} +{UI.ItemInfo.Credits(paid)}");
                var assets = CombatAssets.Load();
                Sfx.PlayAt(assets != null ? assets.missionAccomplished : null, level.Player.transform.position);
                level.Navigation?.SetRoute(null);
            });
        }

        void Fail()
        {
            done = true;
            int textId = 371;
            string text = mission.type == MissionType.Challenge
                ? Localization.Get(371).Replace("#Q1", playerKills.ToString()).Replace("#Q2", otherKills.ToString())
                : Freelance.FailureText(out textId);
            Open(text, textId, () => { Freelance.Fail(); level.Navigation?.SetRoute(null); });
        }

        void Open(string text, int textId, Action after)
        {
            DialogueOpen = true;
            if (level.Navigation != null) level.Navigation.Paused = true;
            MessageRequested?.Invoke(text, mission.clientName, mission.clientPortrait, Freelance.Voice(textId), () =>
            {
                DialogueOpen = false;
                if (level.Navigation != null) level.Navigation.Paused = false;
                after?.Invoke();
            });
        }
    }
}
