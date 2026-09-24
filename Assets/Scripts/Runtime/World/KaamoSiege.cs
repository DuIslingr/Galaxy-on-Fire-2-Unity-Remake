// KaamoSiege.cs
// The Kaamo Club's orbit before it has been freed (station 108, Status+0x114 == 0; Reference/research/kaamo_club.md 3):
//   Level::createMission 0xbda70    4 Pirate Outposts (static object 0x37a3 "station_pirates", name 441) at fixed points,
//                                   passive targets (no guns, no loot) with a +-7500 hit cube and the collision.json 1002
//                                   volumes; 6 pirate fighters (8 hardcore) within +-20000 of the club, awake, no route;
//                                   win = every outpost and every pirate dead; a mission (type 4, client 1601 Mkkt Bkkt)
//   Level::updateMissionOrbit 0xd4bd4  every 22 500 ms, while an outpost stands, dead pirates come back at
//                                   player + (+-(40000..79999), +-(5000..9999), +-(40000..79999))
//   MGame::OnUpdate 0x1ac778        level time >= 5 s: Mkkt Bkkt's call (457, voice MSG_PLAYER_STATION_ENTER_ORBIT) and
//                                   Status+0x114 = 1
//   MGame::successCheck 0x1b0620    the win: 458 (voice ..._ENEMIES_DEAD), missions completed +1, no reward
//   MGame::dockEvent / UseKhadorDrive  while the siege runs: docking, the gate and the Khador Drive give 525
// Remake: the siege keeps the player's freelance mission (the original overwrites the freelance slot with it).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    public class KaamoSiege : MonoBehaviour
    {
        const float M = 0.05f;
        const float RespawnMs = 22500f;
        const float OutpostHitRadius = 7500f;
        const int OutpostCollision = 1002;
        const float OutpostExplosionScale = 8f;

        /// <summary>The four outposts' game positions (no rotation, scale 1).</summary>
        static readonly Vector3[] OutpostPositions =
        {
            new Vector3(45000, 5000, 55000), new Vector3(80000, -30000, -12000),
            new Vector3(-15000, 45000, 55000), new Vector3(-65000, -20000, -45000),
        };

        SpaceLevel level;
        Traffic traffic;
        readonly List<NpcShip> outposts = new List<NpcShip>();
        readonly List<NpcShip> pirates = new List<NpcShip>();
        float levelMs, respawnMs;
        bool called, won;

        /// <summary>The siege still runs: docking, the gate and the Khador Drive are refused (525).</summary>
        public bool Active => !won;

        public void Setup(SpaceLevel spaceLevel, Traffic orbitTraffic)
        {
            level = spaceLevel;
            traffic = orbitTraffic;
            var assets = CombatAssets.Load();
            int hull = KaamoClub.OutpostHull();
            foreach (var p in OutpostPositions)
            {
                outposts.Add(traffic.SpawnShip(new SpawnSpec
                {
                    group = NpcGroup.Raider, race = Standing.Pirate, ship = -1, position = p,
                    fixedObject = "station_pirates", collisionId = OutpostCollision, hitRadius = OutpostHitRadius,
                    wreckPrefab = assets != null ? assets.outpostWreck : null, explosionScale = OutpostExplosionScale,
                    stationary = true, alwaysEnemy = true, noLoot = true, hitpoints = hull, nameText = 441,
                }));
            }
            int count = Session.IsExtreme ? 8 : 6;
            for (int i = 0; i < count; i++)
            {
                // createShip(race 8, kind 0, Globals::getRandomEnemyFighter(8)): pirate models, the standard NPC stats.
                var ships = StationTables.PirateFighters;
                pirates.Add(traffic.SpawnShip(new SpawnSpec
                {
                    group = NpcGroup.Raider, race = Standing.Pirate, ship = ships[Random.Range(0, ships.Length)],
                    position = new Vector3(Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000, Random.Range(0, 40000) - 20000),
                    alwaysEnemy = true,
                }));
            }
            traffic.ConnectPlayers();
        }

        void Update()
        {
            if (won || level == null || traffic == null) return;
            if (level.Health != null && level.Health.Dead) return;
            float dtMs = Time.deltaTime * 1000f;
            levelMs += dtMs;
            if (!called && levelMs >= 5000f && level.StartSequenceOver && level.StorySpace != null && !level.StorySpace.DialogueOpen)
            {
                called = true;
                Session.KaamoState = 1;   // set on the call, not on the win (the siege must be won before docking anyway)
                level.StorySpace.ShowPages(KaamoClub.SiegeCall(), null);
            }
            UpdateRespawn(dtMs);
            if (levelMs >= 5000f && AllDead()) Win();
        }

        bool Dead(NpcShip s) => s == null || s.Gone || s.Current == NpcShip.State.Dying || s.Current == NpcShip.State.Dead;
        bool AllDead() => outposts.TrueForAll(Dead) && pirates.TrueForAll(Dead);

        void UpdateRespawn(float dtMs)
        {
            respawnMs += dtMs;
            if (respawnMs <= RespawnMs) return;
            respawnMs = 0f;
            if (outposts.TrueForAll(Dead) || level.Player == null) return;
            float Sign() => Random.value < 0.5f ? -1f : 1f;
            foreach (var p in pirates)
            {
                if (p == null || !p.Gone) continue;
                var off = new Vector3(Sign() * (40000 + Random.Range(0, 40000)), Sign() * (5000 + Random.Range(0, 5000)),
                                      Sign() * (40000 + Random.Range(0, 40000))) * M;
                p.Revive(level.Player.transform.position + off);
            }
        }

        void Win()
        {
            if (level.StorySpace == null || level.StorySpace.DialogueOpen) return;
            won = true;
            Session.FreelanceCompleted++;   // Status::incMissionCount
            var assets = CombatAssets.Load();
            if (level.Player != null) Sfx.PlayAt(assets != null ? assets.missionAccomplished : null, level.Player.transform.position);
            level.StorySpace.ShowPages(KaamoClub.SiegeWon(), null);
        }
    }
}
