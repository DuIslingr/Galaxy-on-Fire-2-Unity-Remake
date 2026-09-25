// SupernovaLevels.cs
// The Supernova add-on's in-space levels (campaign indices 87-158; Level::createCampaignMission 0xc3370 + LevelScript::
// LevelScript / process; Reference/research/campaign_levels_b.md parts 2-3, campaign_levels_c.md 3). Plain C#, run by
// CampaignLevel like ValkyrieLevels. Ships are Level+0xf8 slots in the original's order; the script step is the
// level-script event (radio trigger 27).
//   87 Thynome      the flight with Carla: radio only, from (0, 0, 210000)
//   89 Naneroh      "Meanwhile in Midorian space": the supernova destroys Luur (cutscene), then docked at Thynome
//   91 Valpatro     10 miners from the damaged freighter (dock, the cabins load them), it explodes, on to Tadram
//   92 Tadram       the miners onto the freighter (unloading), the first Specter attack, the freighter jumps away
//   94 Luur         83 evacuees from the burning platform to the freighter, with two shuttles; Specter waves
//   95 / 99 / 109 / 119 / 126 / 133 / 160 / 161   "Meanwhile..." cutscenes: the camera drifting past the station
//   97 Genoh        12 pirates against the Nivelians
//   100 Alioth      two Specters ambush (the radio is the objective)
//   102 Tadram      the carrier evacuation: four Rhino dropships shuttle 1700 evacuees, Specter waves, the carrier jumps
//   105 Naneroh     Khador's reverse-matter bomb fired into the supernova (a 650 000-unit flight), then Luur
//   106 Luur        the supernova grew; a damaged Specter explodes; on to Thynome (106 -> 108)
//   114 Marktesh    six loan-shark pirates hiding in the asteroid field
//   120 Valadon     two Specters (the radio is the objective)
//   123 Navan       the security check (radio)
//   125 Kappa       the freighter's black box: three secure containers to dock at and hack, pirates
//   131 Var Lupra   the plasma array fly-by (cutscene start)
//   135 Coromesk    140 t of titanium into the mining plant under pirate waves
//   137 B'akrram    the Vossk hail (radio)
//   139 Bra'Murr    two Vossk battleships: hack them, the second's cargo bots bring the prism aboard
//   142 Kernstal    the plasma tutorial with Gunant (the gas clouds, the ionizing missiles, the collector)
//   144 Var Lupra   Harval's ultimatum (cutscene), 145 the attack: the plasma array destroyed
//   147 the Void    hail Alice (radio)
//   154 the Void    Alice's betrayal: Hans' freighter, 20 Void fighters, hack Valkyrie within 91 s
//   157 Var Lupra   the final battle: Harval's fleet, Alice takes Valkyrie and fires the plasma array into the sun
//   158 Luur        the duel with Trunt Harval (his sentry guns)
// Remake picks where the decompile lost floats or the cutscene is only described (listed in campaign_levels_b/c.md's
// "uncertain"): the cutscene cameras' middle drift axis (0), the camera paths of 157 (qualitative), the helper shots of
// 145 and 157 (a rocket mesh flying at 8 / 35 u/ms), the Rhinos' and shuttles' docking (a stop of the route's docking time
// at each end, unloading while at the drop-off), the hidden-blueprint-wreck-like freighter route of 154 (straight to
// Valkyrie, "docked" within 3000 units).
// Harval in 157 / 158 (Level::assignGuns, campaign 0x9d / 0x9e): item 7 Berger Retribution x3 and the Shesha cluster
// missiles (item 0xd6) x4 in the second slot, toggled every 20 s like a Wanted pilot's.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.World
{
    public class SupernovaLevels
    {
        const float M = 0.05f;

        readonly CampaignLevel c;
        readonly SpaceLevel level;
        readonly CutsceneCamera cam;
        readonly StoryAssets assets;
        readonly SupernovaAssets sn;
        readonly CombatAssets combat;
        int built;
        float stepMs, timerMs;
        bool loading;
        float playerSpeed;
        GameObject helper, bomb, explosionAnim, beam;
        readonly List<GameObject> scenery = new List<GameObject>();

        public SupernovaLevels(CampaignLevel campaignLevel, SpaceLevel spaceLevel)
        {
            c = campaignLevel;
            level = spaceLevel;
            assets = StoryAssets.Load();
            sn = SupernovaAssets.Load();
            combat = CombatAssets.Load();
            cam = new CutsceneCamera(level.mainCamera);
        }

        Transform Player => level.Player.transform;
        ShipController Ship => level.Player;
        int Step { get => c.Event; set { c.Event = value; stepMs = 0f; } }
        NpcShip S(int i) => i >= 0 && i < c.Ships.Count ? c.Ships[i] : null;
        bool Over(int line) => c.Radio != null && c.Radio.Over(line);
        bool Triggered(int line) => c.Radio != null && c.Radio.Triggered(line);
        float T => c.MissionMs;

        static Vector3 ToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z) * M;
        static Vector3 ToGame(Vector3 unity) => new Vector3(unity.x, unity.y, -unity.z) / M;
        static Vector3 Dir(Vector3 game) => new Vector3(game.x, game.y, -game.z).normalized;
        static Vector3 GameDir(Transform t) => new Vector3(t.forward.x, t.forward.y, -t.forward.z);
        static Vector3 GameRight(Transform t) => new Vector3(t.right.x, t.right.y, -t.right.z);
        static Vector3 GameUp(Transform t) => new Vector3(t.up.x, t.up.y, -t.up.z);
        Vector3 PlayerGame => ToGame(Player.position);
        Vector3 PlayerDirGame => GameDir(Player);
        Vector3 LightGame => level.Layout.lightDirection.normalized;
        static int R(int n) => Random.Range(0, n);
        static float Sign() => R(2) == 0 ? 1f : -1f;

        /// <summary>Game-space position of a ship / object.</summary>
        static Vector3 G(NpcShip s) => s != null ? ToGame(s.transform.position) : Vector3.zero;

        /// <summary>The asteroid field's centre when a level moves it (Level::createAsteroids), else null.</summary>
        public static Vector3? AsteroidCentre(int index, int station, bool alien)
        {
            if (Session.FreePlay) return null;
            if (index == 89) return new Vector3(-100000, 0, -50000);
            if (index == 114 && station == 83) return new Vector3(30000, 0, 80000);
            if (index == 145 && station == 112) return new Vector3(50000, 0, 70000);
            if (index == 154 && alien) return new Vector3(-70000, 0, 30000);
            return null;
        }

        // ---- spawn helpers ---------------------------------------------------------------------------------------

        NpcShip Fighter(int race, int ship, Vector3 at, bool jitter, System.Action<SpawnSpec> setup = null) => c.SpawnShip(race, ship, at, jitter, setup);

        NpcShip Specter(Vector3 at, bool jitter, System.Action<SpawnSpec> setup = null) =>
            c.SpawnShip(Standing.Specter, 44, at, jitter, s => { s.alwaysEnemy = true; setup?.Invoke(s); });

        /// <summary>Level::createStaticObject: a dockable (or plain) story object, friendly, unkillable, never moving; its
        /// getBoundingVolume id (the player is pushed out of it, fighters steer around it).</summary>
        NpcShip Static(string assembly, Vector3 at, Vector3 rotation, int nameText, int dockingType, int points, System.Action<SpawnSpec> setup = null) =>
            c.SpawnShip(3, -1, at, false, s =>
            {
                s.group = NpcGroup.Special; s.fixedObject = assembly; s.rotation = rotation; s.nameText = nameText; s.dockingType = dockingType;
                s.spacePoints = points; s.alwaysFriend = true; s.hitpoints = 9999999; s.noLoot = true; s.stationary = true; s.hitRadius = 6000f;
                s.collisionId = StaticVolume(assembly);
                setup?.Invoke(s);
            });

        /// <summary>Level::createStaticObject's getBoundingVolume ids by object: 0x495d the burning Luur platform -> collision.json
        /// 111, 0x4220 Valkyrie 1003, 0x4961 the secure containers 2003, 0x4974 the carrier 2005, 0x4a6b the Vossk battleship
        /// 2006; the wrecks (0x4299), the junk field (0x4962) and the freighters' own cargo_001 have none.</summary>
        static int StaticVolume(string assembly) => assembly switch
        {
            "sn_burning_station_mission_object" => 111,
            "v_station_battlestation_anim_mission_object" => 1003,
            "sn_secure_container_nivelian" => 2003,
            "sn_carrier_terran_1" => 2005,
            "sn_battleship_vossk" => 2006,
            _ => -1,
        };

        GameObject Scenery(string assembly, Vector3 gamePos, Quaternion rot, string label)
        {
            var go = OrbitBuilder.Spawn(level.Database, assembly, gamePos, rot, label, null);
            if (go != null) { GunRig.StripForFx(go); scenery.Add(go); }
            return go;
        }

        static void Remove(NpcShip s)
        {
            if (s == null) return;
            s.SetVisible(false);
            s.Deactivate();
            s.Place(new Vector3(-1e5f, -1e5f, -1e5f), Vector3.forward);
        }

        /// <summary>A hidden, inactive ship put somewhere (KIPlayer setPosition + setActive + setVisible).</summary>
        static void Show(NpcShip s, Vector3 gamePos, Vector3 gameFacing)
        {
            if (s == null) return;
            s.Place(ToUnity(gamePos), Dir(gameFacing));
            s.Wake();
            s.SetVisible(true);
        }

        void MovePlayer(Vector3 gamePos, Vector3 gameFacing) => level.MovePlayer(ToUnity(gamePos), Quaternion.LookRotation(Dir(gameFacing), Vector3.up));

        // ---- building (Level::createCampaignMission + the LevelScript constructor) ------------------------------------

        public bool Build(int index)
        {
            built = index;
            switch (index)
            {
                case 87: Build87(); return true;
                case 89: Build89(); return true;
                case 91: Build91(); return true;
                case 92: Build92(); return true;
                case 94: Build94(); return true;
                case 95: case 99: case 109: case 119: case 126: case 133: case 160: case 161: BuildMeanwhile(); return true;
                case 97: Build97(); return true;
                case 100: Build100(); return true;
                case 102: Build102(); return true;
                case 105: Build105(); return true;
                case 106: Build106(); return true;
                case 114: Build114(); return true;
                case 120: Build120(); return true;
                case 123: MovePlayer(new Vector3(0, 0, 180000), -new Vector3(0, 0, 180000)); c.WinObjective = () => Over(3); return true;
                case 125: Build125(); return true;
                case 131: Build131(); return true;
                case 135: Build135(); return true;
                case 137: MovePlayer(new Vector3(20000, 0, 150000), -new Vector3(20000, 0, 150000)); c.WinObjective = () => Over(4); return true;
                case 139: Build139(); return true;
                case 142: Build142(); return true;
                case 144: Build144(); return true;
                case 145: Build145(); return true;
                case 147: c.WinObjective = () => Over(1); return true;
                case 154: Build154(); return true;
                case 157: Build157(); return true;
                case 158: Build158(); return true;
                default: return false;
            }
        }

        void Build87()
        {
            // LevelScript ctor: the player at (0, 0, 210000) facing the station; the chat is the objective (0x16).
            MovePlayer(new Vector3(0, 0, 210000), new Vector3(0, 0, -1));
            c.WinObjective = () => c.Radio != null && c.Radio.LastOver;
        }

        // 89: "Meanwhile in Midorian space..." (campaign_levels_b.md mission 89).
        void Build89()
        {
            if (sn != null && sn.supernovaIntroSky != null) { RenderSettings.skybox = sn.supernovaIntroSky; DynamicGI.UpdateEnvironment(); }
            var friend = new Route(true); friend.points.Add(new Vector3(-63000, 0, 75000)); friend.points.Add(new Vector3(-60000, 0, 110000));
            var enemy = new Route(true); enemy.points.Add(new Vector3(-63000, -5000, 75000)); enemy.points.Add(new Vector3(-60000, -5000, 110000));
            // [0] the container that becomes the "beam" target, [1] intact Luur, [2] burning Luur (hidden).
            Static("container_003_terran", new Vector3(-25000, 800, 120000), Vector3.zero, -1, 0, -1);
            var luurRot = new Vector3(0, Mathf.PI / 2f, 0);
            Static("station_111_luur_intact_mission_89", new Vector3(-77000, -3000, 90000), luurRot, -1, 0, -1);
            var burning = Static("sn_burning_station_fire_intro", new Vector3(-77000, -3000, 90000), luurRot, -1, 0, -1);
            burning.SetVisible(false);
            // [3-10] Midorian fighters on the two loops (no hostility), [11] a freighter flying on.
            for (int i = 0; i < 8; i++)
            {
                var r = i < 4 ? friend : enemy;
                var at = r.points[i % 2 == 0 ? 0 : 1];
                c.SpawnShip(3, NpcTables.RandomFighter(3), at, true, s => { s.alwaysFriend = true; s.route = friend.Clone(); s.noLoot = true; });
            }
            var f = c.SpawnShip(3, 15, new Vector3(-63000, -3000, 65000), false, s => { s.freighter = true; s.group = NpcGroup.Special; s.alwaysFriend = true; s.noLoot = true; });
            // LevelScript ctor: HUD / radar off, the player hidden and invulnerable; the camera by Luur, looking past it.
            level.EndStartSequence();
            EnterCutscene(false);
            SetPlayerVisible(false);
            var luur = S(1);
            var luurPos = G(luur);
            helper = new GameObject("Cutscene helper");
            helper.transform.position = ToUnity(luurPos - LightGame * 100000f + GameRight(Player) * 200000f);
            cam.LookAt(luurPos + new Vector3(10000, 1500, -20000), helper.transform);
            c.MusicOwned = true;
            c.PlayMusic(sn?.supernovaIntro, false);
            Step = 1;
        }

        // 91: Valpatro, the damaged freighter.
        void Build91()
        {
            MovePlayer(new Vector3(0, 0, -130000), new Vector3(0, 0, 1));
            var wreck = Static("sn_cargo_001_midorian_wrecked", new Vector3(-20000, 0, 60000), new Vector3(0, 5.4978f, 0), -1, 0, 3,
                               s => { s.hitpoints = Mathf.Max(1, NpcTables.Hull(1, 15) / 20); s.inactive = true; });
            wreck.RadarHidden = true;
            c.FailObjective = () => c.ShipDead(0);   // Objective(1, 0): the wreck destroyed
        }

        // 92: Tadram, the first Specter attack.
        void Build92()
        {
            for (int i = 0; i < 3; i++)
            {
                var at = new Vector3(R(140000) - 70000, 0, -70000 - 35000 * R(3));
                Specter(at, true, s => { s.asleep = true; }).CloakingPossible = false;
            }
            var freighter = Static("cargo_001_midorian", new Vector3(80000, 0, 110000), Vector3.zero, 3209, ObjectDocking.DropOff, 4);
            MovePlayer(new Vector3(0, 0, 200000), G(freighter) - new Vector3(0, 0, 200000));
            c.WinObjective = () => c.Radio != null && c.Radio.LastOver;   // 0x16
            c.FailObjective = () => c.ShipDead(3);                          // 1 (3): the freighter destroyed
        }

        // 94: Luur, the burning station's evacuation.
        void Build94()
        {
            for (int i = 0; i < 6; i++) Specter(new Vector3(-700000, 0, -700000), true, s => s.asleep = true).CloakingPossible = false;
            Static("sn_burning_station_mission_object", Vector3.zero, new Vector3(0, -2.356f, 0), 3208, ObjectDocking.Pickup, 6);
            Static("cargo_001_midorian", new Vector3(30000, -5000, 40000), Vector3.zero, 3209, ObjectDocking.DropOff, 4);
            // [8, 9] Midorian shuttles looping station -> (20000, -3000, 30000) -> freighter, 12 s at each end.
            for (int i = 0; i < 2; i++)
            {
                var s = c.SpawnShip(3, NpcTables.RandomFighter(3), new Vector3(0, 2000 * i, 3000), false,
                                    sp => { sp.alwaysFriend = true; sp.noLoot = true; });
                s.SetOnlyEnemy(null);
                shuttles.Add(new Shuttle { ship = s, points = new[] { Vector3.zero, new Vector3(20000, -3000, 30000), new Vector3(30000, -5000, 40000) },
                                           dockMs = new[] { 12000f, 0f, 12000f }, dropOff = 2, perUnitMs = 1500f, leg = i });
            }
            c.FailObjective = () => c.ShipDead(7);   // Objective(1, 7): the freighter destroyed
        }

        // "Meanwhile, back on Thynome station..." (95, 99, 109, 119, 126, 133, 160, 161): the ctor block 0x15f852.
        void BuildMeanwhile()
        {
            level.EndStartSequence();
            level.MovePlayer(Vector3.zero, Quaternion.identity);
            EnterCutscene(false);
            SetPlayerVisible(false);
            cam.LookAt(new Vector3(-15000, 800, 75000), null, Vector3.zero);
            cam.SetDolly(new Vector3(1f, 0f, -2f));
            if ((built == 126 || built == 133) && sn != null && sn.katashunMusic != null) { c.MusicOwned = true; c.PlayMusic(sn.katashunMusic, true); }
        }

        void Build97()
        {
            var wp = new Vector3(0, 0, 50000);
            const int n = 12;
            for (int i = 0; i < n; i++) c.SpawnShip(Standing.Pirate, NpcTables.RandomFighter(Standing.Pirate), wp, true, s => s.alwaysEnemy = true);
            for (int i = 0; i < 4; i++) c.SpawnShip(2, NpcTables.RandomFighter(2), wp, true, s => s.alwaysFriend = true);
            for (int i = 0; i < 3; i++)
                c.SpawnShip(2, 15, wp, true, s => { s.freighter = true; s.group = NpcGroup.Special; s.stationary = true; s.alwaysFriend = true; });
            c.WinObjective = () => c.DeadRange(0, n);   // 0x12 (0, N)
        }

        void Build100()
        {
            var p = PlayerGame + new Vector3(Sign() * R(50000) + 20000, Sign() * R(50000) + 10000, Sign() * R(50000) + 20000);
            for (int i = 0; i < 2; i++) Specter(p, true);
            c.WinObjective = () => Over(1);   // Objective(4, 1)
        }

        // 102: Tadram, the carrier evacuation.
        void Build102()
        {
            MovePlayer(new Vector3(90000, 6000, 150000), -new Vector3(90000, 6000, 150000));
            var carrierPos = new Vector3(-50000, 1000, 70000);
            Static("sn_carrier_terran_1", carrierPos, Vector3.zero, -1, ObjectDocking.DropOff, 5);
            c.AddPlaceholder();   // [1] the damaged Tadram (the orbit's own station stands in)
            var stops = new[] { carrierPos, new Vector3(-30000, 1000, 40000), Vector3.zero };
            var starts = new[] { carrierPos + new Vector3(10000, 6000, -20000), new Vector3(30000, 8000, -35000), new Vector3(35000, 8000, -40000), new Vector3(40000, 8000, -45000) };
            for (int i = 0; i < 4; i++)
            {
                var s = c.SpawnShip(0, 51, starts[i], false, sp => { sp.alwaysFriend = true; sp.noLoot = true; });
                s.SetOnlyEnemy(null);
                shuttles.Add(new Shuttle { ship = s, points = stops, dockMs = new[] { 20000f, 0f, 20000f }, dropOff = 0, perUnitMs = 200f, leg = i % 3, rhino = true });
            }
            for (int i = 0; i < 4; i++) Specter(new Vector3(1e6f, 1e6f, 1e6f), false, s => s.asleep = true).CloakingPossible = false;
            c.WinObjective = () => Over(8);                   // Objective(4, 8)
            c.FailObjective = () => c.DeadRange(2, 6);        // 0x12 (2, 6): every dropship lost
        }

        // 105: Naneroh, the reverse-matter bomb.
        void Build105()
        {
            var light = LightGame;
            Player.rotation = Quaternion.LookRotation(Dir(light), Vector3.up);
            var route = new Route(false);
            route.points.Add(new Vector3(650000f * light.x, 0, 650000f * light.z));
            c.SetPlayerRoute(route);
            var p = PlayerGame;
            var right = GameRight(Player);
            for (int k = 0; k < 2; k++)
            {
                var at = p + right * (k == 0 ? 2100f : -2100f) + PlayerDirGame * 2000f;
                var s = c.SpawnShip(0, 37, at, false, sp => { sp.alwaysFriend = true; sp.noLoot = true; sp.hitpoints = 9999999; });
                s.Place(ToUnity(at), Dir(light));
                s.SetOnlyEnemy(null);
                s.scriptedSpeed = FormationSpeed;
            }
            for (int i = 0; i < 3; i++) Specter(new Vector3(7000000, 7000000, 7000000), true, s => s.asleep = true).CloakingPossible = false;
            // The ctor: a cutscene camera behind the player; its autopilot (setAutoPilotToProgrammedStation) isn't needed.
            level.EndStartSequence();
            EnterCutscene(true);
            // The original flies the player on the autopilot here; the camera's dolly (2.43 u/ms, ev1) would overtake a
            // player at the launch speed and slide the escorts (2 u/ms) back at it tail first. Remake: the player and the
            // escorts keep just ahead of the camera until they break away.
            playerSpeed = FormationSpeed;
            cam.LookAt(p - PlayerDirGame * 2400f + GameUp(Player) * 500f, Player);
            Step = 1;
        }

        /// <summary>105's formation speed (u/ms), a little faster than the camera's dolly (remake pick, see Build105).</summary>
        const float FormationSpeed = 2.5f;

        // 106: Luur's aftermath.
        void Build106()
        {
            var route = new Route(false);
            route.points.Add(new Vector3(-500000, 0, -1700000));
            route.points.Add(new Vector3(-500000, 0, -3700000));
            var s = c.SpawnShip(Standing.Specter, 44, route.points[0], false, sp => { sp.alwaysFriend = true; sp.hitpoints = 1; sp.route = route; sp.inactive = true; sp.noLoot = true; });
            s.Place(ToUnity(route.points[0]), Dir(new Vector3(-1, 0, 0)));
            s.CloakingPossible = false;
            s.SetVisible(false);
            level.EndStartSequence();
            var p = new Vector3(300000, 0, 300000);
            MovePlayer(p, LightGame);
            EnterCutscene(false);
            cam.LookAt(p + new Vector3(2200, 1300, -4000), Player);
            c.Fade(true, Color.black, 8000f);
            Step = 1;
        }

        // 114: Marktesh, the loan sharks in the asteroid field.
        void Build114()
        {
            MovePlayer(new Vector3(0, 0, -120000), new Vector3(0, 0, 1));
            var rocks = AsteroidPositions();
            for (int i = 0; i < 6; i++)
            {
                var at = rocks.Count > 0 ? rocks[(i + rocks.Count / 2) % rocks.Count] + new Vector3(0, 2000, 0) : new Vector3(30000, 2000, 80000);
                var s = c.SpawnShip(Standing.Pirate, NpcTables.RandomFighter(Standing.Pirate), at, false, sp => sp.asleep = true);
                s.detectRange = 7000f;
                s.SetHull(s.Hp.maxHull * 2);
            }
            c.WinObjective = () => c.DeadRange(0, 6);   // 0x12 (0, 6)
        }

        List<Vector3> AsteroidPositions()
        {
            var list = new List<Vector3>();
            if (level.Asteroids != null) foreach (Transform t in level.Asteroids) list.Add(ToGame(t.position));
            return list;
        }

        void Build120()
        {
            var right = GameRight(Player);
            for (int k = 0; k < 2; k++)
            {
                var at = PlayerGame + right * 50000f + PlayerDirGame * (k == 0 ? 4000f : -4000f);
                var s = Specter(at, false);
                var r = new Route(false); r.points.Add(new Vector3(0, 0, -80000)); s.SetRoute(r);
            }
            c.WinObjective = () => Over(0);   // Objective(4, 0); no success conversation: on at once
        }

        // 125: Kappa, the black box and the secure containers.
        void Build125()
        {
            for (int i = 0; i < 2; i++) c.SpawnShip(Standing.Pirate, NpcTables.RandomFighter(Standing.Pirate), Vector3.zero, true, s => s.alwaysEnemy = true);
            for (int i = 2; i < 8; i++) c.SpawnShip(Standing.Pirate, NpcTables.RandomFighter(Standing.Pirate), new Vector3(7000000, 7000000, 7000000), true, s => { s.alwaysEnemy = true; s.asleep = true; });
            var boxes = new[] { new Vector3(-80000, 0, -160000), new Vector3(-72000, 0, -190000), new Vector3(-66000, 53000, -170000) };
            foreach (var b in boxes)
            {
                var s = Static("sn_secure_container_nivelian", b, Vector3.zero, -1, 0, 2);
                s.RadarHidden = true;
            }
            for (int k = 0; k < 4; k++)
            {
                var junk = Static("sn_junk_field", new Vector3(-72000 + 4000 * k, R(1500) - 200 * k, -145000 - 4000 * k), new Vector3(k + 11 - 5.7596f, 0, k + 11 - 4.3197f), -1, 0, -1);
                junk.RadarHidden = true;
            }
            c.WinObjective = () => Over(7);   // Objective(4, 7)
        }

        // 131: Var Lupra, the plasma array fly-by.
        void Build131()
        {
            level.EndStartSequence();
            var p = new Vector3(-65000, 0, 95000);
            MovePlayer(p, -p);
            EnterCutscene(true);
            playerSpeed = 2f;   // the autopilot's full throttle (the camera drifts at 2.01 u/ms)
            cam.LookAt(p - PlayerDirGame * 2400f + GameUp(Player) * 500f - GameRight(Player) * 600f, Player);
            cam.SetDolly(PlayerDirGame * 2.01f + GameRight(Player) * 0.03f + new Vector3(0, 0.01f, 0));
            Step = 1;
            c.WinObjective = () => Over(0);   // Objective(4, 0)
        }

        // 135: Coromesk, the titanium for the mining plant.
        void Build135()
        {
            MovePlayer(new Vector3(70000, 0, 100000), -new Vector3(70000, 0, 100000));
            c.SpawnShip(3, -1, Vector3.zero, false, s =>
            {
                var plant = Traffic.MiningPlant();
                s.group = plant.group; s.fixedObject = plant.fixedObject; s.stationary = true; s.alwaysFriend = true; s.hitpoints = 9999999;
                s.noLoot = true; s.nameText = plant.nameText; s.dockingType = plant.dockingType; s.spacePoints = plant.spacePoints; s.hitRadius = plant.hitRadius;
                s.collisionId = plant.collisionId;
            });
            for (int i = 0; i < 2; i++) c.SpawnShip(Standing.Pirate, NpcTables.RandomFighter(Standing.Pirate), new Vector3(7000000, 7000000, 7000000), false, s => { s.alwaysEnemy = true; s.asleep = true; });
            // Every asteroid of the orbit is titanium (ore 155).
            if (level.Asteroids != null)
                foreach (Transform t in level.Asteroids) { var tg = t.GetComponent<Target>(); if (tg != null) tg.oreItem = 155; }
        }

        /// <summary>Turret offsets around a Vossk battleship (table 0x2536ac).</summary>
        static readonly Vector3[] BattleshipTurrets =
            { new Vector3(10283, -1123, 26039), new Vector3(-10171, -1083, 25907), new Vector3(-15624, -787, -7569), new Vector3(15624, -787, -7569), new Vector3(0, 4901, 3084) };

        // 139: Bra'Murr, the two Vossk battleships.
        void Build139()
        {
            var b0 = new Vector3(-50000, -1500, 70000);
            var b1 = new Vector3(-200000, -1500, 30000);
            Static("sn_battleship_vossk", b0, Vector3.zero, 1667, ObjectDocking.Hackable, 8, s => s.race = 1);
            Static("sn_battleship_vossk", b1, Vector3.zero, 1667, ObjectDocking.Hackable, 8, s => { s.race = 1; s.name = Localization.Get(1667) + " 2"; });
            foreach (var host in new[] { b0, b1 })
                foreach (var off in BattleshipTurrets)
                    c.SpawnShip(1, -1, host + off, false, s =>
                    {
                        s.group = NpcGroup.Turret; s.turretAssembly = "turret_003_static"; s.scale = 6f; s.hitpoints = 1000; s.noLoot = true; s.stationary = true;
                    });
            var loop0 = new Route(true); loop0.points.Add(new Vector3(-70000, 0, 80000)); loop0.points.Add(new Vector3(-30000, 0, 60000));
            var loop1 = new Route(true); loop1.points.Add(new Vector3(-220000, 0, 40000)); loop1.points.Add(new Vector3(-180000, 0, 20000));
            for (int i = 0; i < 5; i++) c.SpawnShip(1, NpcTables.RandomFighter(1), b0, true, s => { s.route = loop0; s.alwaysFriend = true; });
            for (int i = 0; i < 5; i++) c.SpawnShip(1, NpcTables.RandomFighter(1), b1, true, s => { s.route = loop1; s.alwaysFriend = true; });
            MovePlayer(new Vector3(20000, 0, 190000), b1 - new Vector3(20000, 0, 190000));
            Session.StoryCounter = 0;
        }

        // 142: Kernstal, plasma with Gunant.
        void Build142()
        {
            var wp = new Vector3(90000, 0, 42000);
            var start = new Vector3(60000, 0, 120000);
            MovePlayer(start, wp - start);
            var route = new Route(false);
            route.points.Add(wp);
            c.SetPlayerRoute(route);
            var at = start + GameRight(Player) * 2100f + PlayerDirGame * 2000f;
            var g = c.SpawnShip(3, 30, at, false, s => { s.alwaysFriend = true; s.hitpoints = 9999999; s.nameText = 1599; s.route = route.Clone(); s.noLoot = true; });
            g.Place(ToUnity(at), Player.forward);
            g.SetOnlyEnemy(null);
            c.WinObjective = () => Over(4);   // Objective(4, 4)
        }

        /// <summary>Harval's twelve Specters around him (offsets in his frame, +-30).</summary>
        static readonly Vector3[] Formation =
        {
            new Vector3(-5000, 300, 200), new Vector3(-3500, 300, 200), new Vector3(5000, 300, 200), new Vector3(3500, 300, 200),
            new Vector3(-6500, 500, -5000), new Vector3(-3250, 500, -5000), new Vector3(0, -300, -5000), new Vector3(3250, 500, -5000),
            new Vector3(6500, 500, -5000), new Vector3(-6500, -400, -5000), new Vector3(0, -400, -5000), new Vector3(6500, -400, -5000),
        };

        // 144: Var Lupra, Harval's ultimatum (cutscene).
        void Build144()
        {
            var a = new Vector3(60000, 10000, 100000);
            var b = new Vector3(-50000, 0, 50000);
            var facing = new Vector3(b.x - a.x, 0, b.z - a.z);
            var harval = c.SpawnShip(2, 49, a, false, s => { s.alwaysEnemy = true; s.nameText = 1636; s.noLoot = true; });
            harval.Place(ToUnity(a), Dir(facing));
            harval.CloakingPossible = false;
            harval.scriptedSpeed = 0f;
            foreach (var off in Formation)
            {
                var s = Specter(a, false);
                var p = a + Quaternion.LookRotation(facing.normalized) * (off + new Vector3(R(60) - 30, R(60) - 30, R(60) - 30));
                s.Place(ToUnity(p), Dir(facing));
                s.CloakingPossible = false;
                s.scriptedSpeed = 0f;
            }
            level.EndStartSequence();
            EnterCutscene(false);
            SetPlayerVisible(false);
            helper = new GameObject("Cutscene helper");
            helper.transform.position = ToUnity(new Vector3(30000, 10000, 160000));
            cam.LookAt(a + new Vector3(-4600, 1000, -4300), helper.transform);
            Step = 1;
        }

        // 145: Var Lupra, the plasma array destroyed.
        void Build145()
        {
            var harval = c.SpawnShip(2, 49, new Vector3(30000, 0, 80000), false, s => { s.alwaysEnemy = true; s.nameText = 1636; s.noLoot = true; });
            harval.Place(ToUnity(new Vector3(30000, 0, 80000)), Dir(new Vector3(-50000, 0, 50000) - new Vector3(30000, 0, 80000)));
            harval.CloakingPossible = false;
            for (int i = 1; i <= 12; i++)
            {
                var p = new Vector3(23000 + 3000 * (i - 1), (R(1000) - 500) * i + R(1000), 70000 + 2000 * i + R(2500));
                var s = Specter(p, false);
                s.Place(ToUnity(p), Dir(new Vector3(-50000, 0, 50000) - p));
                s.CloakingPossible = false;
            }
            // [13] the array's explosion (hidden until it goes), [14] the array (Level::createStaticObjects, stage 5 + glow).
            c.AddPlaceholder();
            explosionAnim = Scenery("sn_plasma_array_midorian_explosion_anim", new Vector3(-50000, 0, 50000), OrbitLayout.RotationToUnity(Vector3.zero), "Array explosion");
            if (explosionAnim != null) explosionAnim.SetActive(false);
            var array = level.Traffic.Ships.Find(s => s.Spec.fixedObject != null && s.Spec.fixedObject.StartsWith("sn_plasma_array"));
            c.Ships.Add(array);
            foreach (var s in c.Ships) if (s != null && s.Race == Standing.Specter || s == S(0)) { if (s != null) s.scriptedSpeed = 2f; }
            c.WinObjective = () => Over(2);   // Objective(4, 2)
        }

        // 154: the Void, Alice's betrayal.
        void Build154()
        {
            var p = new Vector3(0, 0, 140000);
            MovePlayer(p, -p);
            var at = p + GameRight(Player) * 2600f + PlayerDirGame * 4000f;
            var hans = c.SpawnShip(0, 51, at, false, s => { s.alwaysFriend = true; s.hitpoints = 9999999; s.noLoot = true; s.nameText = 1652; });
            hans.Place(ToUnity(at), Player.forward);
            hans.SetOnlyEnemy(null);
            hans.frozen = true;
            var valkyrie = Static("v_station_battlestation_anim_mission_object", Vector3.zero, Vector3.zero, 77, ObjectDocking.Hackable, 7);
            PartAnimation.HoldAll(valkyrie.gameObject);   // PlayerFixedObject::update never advances an idle animation
            valkyrie.RadarHidden = true;
            valkyrie.DockingType = 0;   // hackable once Alice turns on the player
            for (int i = 2; i < 22; i++)
            {
                float sx = i % 2 == 0 ? 1f : -1f;
                var off = i <= 10 ? new Vector3(sx * (900 + R(100)), -(R(200) + 1), R(400) - 200) : new Vector3(sx * (1600 + R(100)), -(101 + R(100)), 1000 + R(500));
                var q = new Vector3(0, 0, 40000) + off * i;
                var s = c.SpawnShip(Standing.Void, NpcTables.RandomFighter(Standing.Void), q, false, sp => { sp.alwaysEnemy = true; sp.inactive = true; });
                s.Place(ToUnity(q), Dir(p - q));
                s.SetHull(s.Hp.maxHull * 2);
                s.SetOnlyEnemy(null);
            }
            c.WinObjective = () => Over(11);   // Objective(4, 11)
        }

        // 157: Var Lupra, the final battle.
        void Build157()
        {
            var fr = new Route(false); fr.points.Add(new Vector3(70000, 0, 20000)); fr.points.Add(new Vector3(30000, 10000, 60000));
            for (int i = 0; i < 10; i++) c.SpawnShip(0, NpcTables.RandomFighter(0), fr.points[0], true, s => { s.alwaysFriend = true; s.route = fr; });
            Static("sn_carrier_terran_1", new Vector3(30000, -15000, -50000), Vector3.zero, -1, 0, -1, s => s.race = 0);
            var start = new Vector3(-110000, 10000, 170000);
            var er = new Route(false); er.points.Add(start); er.points.Add(new Vector3(-110000, 0, 20000));
            for (int k = 0; k < 10; k++)
            {
                var off = k < 2 ? new Vector3(-1000 + 2000 * k, 0, 5000) : k < 5 ? new Vector3(3000 * k - 9000, 0, 7000) : k < 9 ? new Vector3(3000 * k - 20000, 0, 9000) : new Vector3(0, 0, 11000);
                var s = Specter(start + off, false, sp => { sp.inactive = true; sp.route = er; });
                s.SetVisible(false);
                s.CloakingPossible = false;
            }
            var harval = c.SpawnShip(2, 49, start, false, s => { s.alwaysEnemy = true; s.nameText = 1636; s.inactive = true; s.route = er; s.speed = 5f; s.noLoot = true; });
            harval.SetVisible(false);
            harval.CloakingPossible = false;
            ArmHarval(harval);
            var alice = c.SpawnShip(3, 20, new Vector3(50000, 50000, 50000), false, s => { s.alwaysFriend = true; s.nameText = 1623; s.inactive = true; s.noLoot = true; s.hitpoints = 9999999; });
            alice.SetVisible(false);
            // [23] Valkyrie with the plasma gun at (-120000, 0, 20000).
            c.AddPlaceholder();
            var vp = new Vector3(-120000, 0, 20000);
            var vrot = OrbitLayout.RotationToUnity(new Vector3(0, Mathf.PI, 0));
            var valkyrie = Scenery("v_station_battlestation_anim_mission_object", vp, vrot, "Valkyrie");
            Scenery("sn_plasma_gun_valkyrie", vp, vrot, "Valkyrie plasma gun");
            PartAnimation.HoldAll(valkyrie);
            MovePlayer(new Vector3(100000, 0, 20000), new Vector3(-1, -0.2f, -0.5f));
        }

        // 158: Luur, the duel with Trunt Harval.
        void Build158()
        {
            var hp = new Vector3(9000, 0, -13000);
            var harval = c.SpawnShip(Standing.Specter, 49, hp, false, s => { s.alwaysEnemy = true; s.nameText = 1636; s.speed = 5.3f; s.noLoot = true; });
            harval.Place(ToUnity(hp), Dir(new Vector3(-1, 0, 3)));
            harval.CloakingPossible = false;
            harval.scriptedSpeed = 0f;
            harval.SetVisible(false);
            ArmHarval(harval);
            for (int i = 0; i < 3; i++)
                c.SpawnShip(Standing.Specter, -1, new Vector3(50000, 50000, 50000), false, s =>
                {
                    s.group = NpcGroup.Turret; s.turretAssembly = "sn_sentry_gun_003"; s.hitpoints = 100; s.noLoot = true; s.inactive = true; s.alwaysEnemy = true; s.stationary = true;
                });
            level.EndStartSequence();
            var p = new Vector3(-50000, 0, 15000);
            MovePlayer(p, LightGame);
            EnterCutscene(false);
            cam.LookAt(p + new Vector3(-28000, 500, 8500), Player);
            c.Fade(true, Color.black, 8000f);
            playerSpeed = 0.1f;
            Step = 1;
        }

        /// <summary>Level::assignGuns at 0x9d / 0x9e: Harval's Scimitar fires item 7 x3, and the Shesha (0xd6) x4 in slot 1.</summary>
        static void ArmHarval(NpcShip harval)
        {
            harval.SetGun(7, 3f);
            harval.SetSecondaryGun(214, 4f);
        }

        // ---- cutscene helpers (LevelScript "cutscene on" / "off") ------------------------------------------------------

        void EnterCutscene(bool keepSpeed = true)
        {
            c.Cutscene = true;
            c.PlayerInvulnerable = true;
            playerSpeed = keepSpeed ? Ship.SpeedMetersPerSecond / (1000f * M) : 0f;
            Ship.externalControl = true;
            if (level.Weapons != null) level.Weapons.Blocked = true;
            level.Navigation?.SetAutopilot(null);
        }

        void LeaveCutscene()
        {
            c.Cutscene = false;
            c.PlayerInvulnerable = false;
            Ship.externalControl = false;
            if (level.Weapons != null) level.Weapons.Blocked = false;
            SetPlayerVisible(true);
            cam.Release();
        }

        void SetPlayerVisible(bool on)
        {
            if (Ship.visualModel != null) Ship.visualModel.gameObject.SetActive(on);
        }

        // ---- per frame (LevelScript::process) ------------------------------------------------------------------------

        public void Tick(int index, float dtMs)
        {
            stepMs += dtMs;
            timerMs += dtMs;
            if (Ship.externalControl && !level.Health.Dead && playerSpeed > 0f)
            {
                Player.position += Player.forward * playerSpeed * dtMs * M;
                Ship.ExternalSpeedMetersPerSecond = playerSpeed * 1000f * M;
            }
            if (loading) return;
            UpdateShuttles(dtMs);
            if (index != built && c.Cutscene && !ScriptOwnsAdvance) LeaveCutscene();
            switch (built)
            {
                case 89: Tick89(dtMs); break;
                case 91: if (index == 91) Tick91(dtMs); break;
                case 92: if (index == 92) Tick92(dtMs); break;
                case 94: if (index == 94) Tick94(); break;
                case 95: case 99: case 109: case 119: case 126: case 133: case 160: case 161: if (index == built) TickMeanwhile(); break;
                case 102: if (index == 102) Tick102(dtMs); break;
                case 105: Tick105(dtMs); break;
                case 106: Tick106(); break;
                case 114: if (index == 114) Tick114(); break;
                case 125: if (index == 125) Tick125(); break;
                case 131: if (index == 131) Tick131(); break;
                case 135: if (index == 135) Tick135(); break;
                case 139: if (index == 139) Tick139(); break;
                case 142: if (index == 142) Tick142(); break;
                case 144: Tick144(dtMs); break;
                case 145: if (index == 145) Tick145(dtMs); break;
                case 154: if (index == 154) Tick154(); break;
                case 157: Tick157(dtMs); break;
                case 158: if (index == 158) Tick158(dtMs); break;
            }
        }

        /// <summary>Levels whose own script advances the index while their cutscene still runs.</summary>
        bool ScriptOwnsAdvance => built == 89 || built == 105 || built == 106 || built == 144 || built == 157;

        public void LateTick(float dtMs)
        {
            cam.LateTick(dtMs);
            var camT = Camera.main;
            if (camT != null && beam != null) beam.transform.rotation = camT.transform.rotation;
        }

        /// <summary>A save of hull / shield / armour / gamma, nextCampaignMission, and the next orbit (the scripts' jumps).</summary>
        void AdvanceAndTravel(int times, int station)
        {
            loading = true;
            for (int i = 0; i < times; i++) Story.Advance(level.Database);
            if (station == Session.StationIndex) level.TravelTo(station); else level.TravelTo(station);
        }

        void AdvanceAndDock(int station)
        {
            loading = true;
            Story.Advance(level.Database);
            Session.StationIndex = station;
            level.Dock();
        }

        // 89 (LevelScript.c 2473-2647).
        void Tick89(float dtMs)
        {
            var luur = S(1);
            if (Step < 3 && helper != null)
            {
                float k = Mathf.Max(0f, 1f - T / 35000f);
                cam.SetDolly(new Vector3(k, 0, 2f * k));
                helper.transform.position -= Player.right * 7f * dtMs * Mathf.Max(0f, 1f - T / 50000f) * M;
            }
            var freighter = S(11);
            if (freighter != null) freighter.transform.position += freighter.transform.forward * dtMs * M;
            switch (Step)
            {
                case 1:
                    if (T >= 30001f)
                    {
                        // The container rushes past as the blast front (the "beam", projectile_009 stretched).
                        var box = S(0);
                        if (box != null && cam.Camera != null) { box.transform.position = cam.Camera.position + Vector3.up * 500f * M; box.transform.position -= box.transform.forward * 10000f * M; }
                        beam = Scenery("projectile_009_anim_add", ToGame(box != null ? box.transform.position : Player.position), Quaternion.identity, "Supernova front");
                        if (beam != null) beam.transform.localScale = new Vector3(1f, 1f, 5000f);
                        Step = 2;
                    }
                    break;
                case 2:
                {
                    var box = S(0);
                    if (box != null && cam.Camera != null)
                    {
                        float d = (cam.Camera.position - box.transform.position).magnitude / M;
                        cam.Rumble = 1f - Mathf.Min(d / 7000f, 1f);
                        if (d < 200000f) box.transform.position += box.transform.forward * (10f * dtMs + 0.1f * d) * M;
                        if (beam != null) beam.transform.position = box.transform.position;
                    }
                    if (T >= 38000f && T - dtMs < 38000f && sn != null) Sfx.PlayAt(sn.explosion, Player.position);   // 0x8c8
                    if (T >= 38001f && level.Backdrop != null) level.Backdrop.sunScaleFactor *= Mathf.Pow(0.95f, dtMs / 33f);
                    if (T >= 39001f) { c.Fade(false, Color.white, 500f); Step = 3; }
                    break;
                }
                case 3:
                    if (level.Backdrop != null && level.Backdrop.sunScaleFactor < 10f) level.Backdrop.sunScaleFactor *= Mathf.Pow(4f, dtMs / 33f);
                    cam.Rumble = 0.6f;
                    if (c.FadeDone)
                    {
                        level.Backdrop?.SwitchSun("sn_supernova");
                        c.Fade(true, Color.white, 10000f);
                        if (beam != null) { Object.Destroy(beam); beam = null; }
                        if (S(2) != null) S(2).SetVisible(true);
                        if (luur != null) luur.SetVisible(false);
                        for (int i = 3; i < c.Ships.Count; i++) if (S(i) != null && S(i).Target.Alive) S(i).Target.Damage(9999999, true, Vector3.zero);
                        Step = 4;
                    }
                    break;
                case 4:
                    cam.Rumble = Mathf.Clamp01(1f - stepMs / 7000f) * 0.5f;
                    if (stepMs >= 7000f && stepMs - dtMs < 7000f) c.Fade(false, Color.black, 1000f);
                    if (stepMs >= 8000f && c.FadeDone) { AdvanceAndDock(10); Step = 5; }
                    break;
            }
        }

        // 91 (process 9556-9762).
        void Tick91(float dtMs)
        {
            var wreck = S(0);
            var dock = level.Docking;
            switch (Step)
            {
                case 0:
                    if (Triggered(3) && wreck != null) { wreck.Wake(); wreck.RadarHidden = false; wreck.DockingType = 0; wreck.Target.displayName = Localization.Get(3211); Step = 1; }
                    // Remake: the damaged freighter is a docking target from the start of its call (dock type 0 can't dock):
                    break;
                case 1:
                    // The docking target shows now; docking at it with no transfer yet (the radio line calls everyone aboard).
                    if (wreck != null && wreck.DockingType == 0) wreck.DockingType = ObjectDocking.DropOff;   // lockable, no transfer
                    if (dock != null && dock.IsDocked && dock.Target == wreck) Step = 2;
                    break;
                case 2:
                    if (Over(5) && wreck != null) { wreck.DockingType = ObjectDocking.Pickup; Step = 3; }
                    break;
                case 3:
                    if (Session.StoryCounter >= 10) { c.FailObjective = null; Step = 4; }
                    break;
                case 4:
                    if (Over(6) && dock != null && !dock.Busy) Step = 5;
                    break;
                case 5:
                    if (stepMs < 3000f) break;
                    level.Navigation?.SetAutopilot(null);
                    EnterCutscene(true);
                    if (wreck != null) Player.rotation = Quaternion.LookRotation((Player.position - wreck.transform.position).normalized, Vector3.up);
                    cam.LookAt(PlayerGame + PlayerDirGame * 10000f + GameRight(Player) * 700f, Player);
                    if (wreck != null) wreck.Target.Damage(9999999, true, Vector3.zero);
                    Step = 6;
                    break;
                case 6:
                    if (stepMs >= 2000f && playerSpeed < 100f) playerSpeed = Mathf.Max(playerSpeed, 1f) * Mathf.Pow(1.05f, dtMs / 33f);
                    if (stepMs >= 8000f) AdvanceAndTravel(1, 113);
                    break;
            }
        }

        // 92 (process 5640-6166).
        void Tick92(float dtMs)
        {
            var freighter = S(3);
            float[] slow = { 2.0f, 2.08f, 2.05f }, mid = { 2.0f, 2.3f, 2.2f }, fast = { 6.0f, 4.6f, 4.4f };
            void Fly(float[] v) { for (int i = 0; i < 3; i++) if (S(i) != null) S(i).scriptedSpeed = v[i]; }
            switch (Step)
            {
                case 0: if (Triggered(2)) Step = 1; break;
                case 1:
                    if (Session.StoryCounter != 0 || freighter == null) break;
                    Story.Mission.type = StoryType.Level;   // the unloading is done: the radio decides from here
                    var f = G(freighter);
                    var offs = new[] { new Vector3(-76000, 5000, 5000), new Vector3(-79000, 4900, 7500), new Vector3(-79000, 4900, 2500) };
                    for (int i = 0; i < 3; i++) { Show(S(i), f + offs[i], new Vector3(1, 0, 0)); S(i).scriptedSpeed = slow[i]; }
                    EnterCutscene(true);
                    var s0 = S(0);
                    cam.LookAt(G(s0) + GameDir(s0.transform) * 7000f + GameRight(s0.transform) * 700f + GameUp(s0.transform) * 300f, s0.transform);
                    freighter.DockingType = 0;
                    freighter.Target.displayName = "";
                    Step = 2;
                    break;
                case 2:
                    Fly(slow);
                    if (Triggered(5)) { var s = S(0); cam.LookAt(G(s) + GameDir(s.transform) * 3900f + GameRight(s.transform) * 500f + GameUp(s.transform) * 400f, s.transform); Step = 3; }
                    break;
                case 3:
                    Fly(mid);
                    if (Over(5)) { for (int i = 0; i < 3; i++) { S(i).CloakingPossible = true; S(i).Cloak(18000f); } Step = 4; }
                    break;
                case 4: Fly(mid); if (stepMs >= 2000f) Step = 5; break;
                case 5:
                    Fly(fast);
                    if (stepMs < 2000f) break;
                    for (int i = 0; i < 3; i++) if (S(i) != null) S(i).scriptedSpeed = -1f;
                    LeaveCutscene();
                    Step = 6;
                    break;
                case 6: if (stepMs >= 3000f) Step = 7; break;
                case 7:
                    if (!Triggered(8)) break;
                    level.Docking?.Undock();
                    EnterCutscene(false);
                    cam.LookAt(PlayerGame + PlayerDirGame * 7000f + GameRight(Player) * 700f, Player);
                    Step = 8;
                    break;
                case 8:
                    if (freighter != null) freighter.transform.position += freighter.transform.forward * 2f * dtMs * M;
                    if (stepMs >= 8000f && freighter != null)
                    {
                        cam.LookAt(G(freighter) + GameDir(freighter.transform) * 10000f + GameRight(freighter.transform) * 4800f, freighter.transform);
                        timerMs = 0f;
                        freighterSpeed = 2f;
                        if (sn != null) Sfx.PlayAt(sn.carrierJump, freighter.transform.position);   // 0x8c9 CS_92_FreighterJump
                        Step = 9;
                    }
                    break;
                case 9:
                case 10:
                    freighterSpeed += 0.006f * dtMs;
                    if (freighter != null) freighter.transform.position += freighter.transform.forward * freighterSpeed * dtMs * M;
                    if (Step == 9 && stepMs >= 2000f) Step = 10;
                    if (timerMs >= 7000f) { LeaveCutscene(); if (freighter != null) { freighter.SetVisible(false); freighter.Deactivate(); } Step = 11; }
                    break;
            }
        }
        float freighterSpeed;

        // 94 (process 6167-6348).
        void Tick94()
        {
            switch (Step)
            {
                case 0:
                    if (Session.StoryCounter <= 6 && T <= 60000f) break;
                    Show(S(0), new Vector3(50000, 1000, 140000), new Vector3(0, 0, -1));
                    Show(S(1), new Vector3(53000, 1000, 140000), new Vector3(0, 0, -1));
                    S(0).scriptedSpeed = S(1).scriptedSpeed = 3f;
                    EnterCutscene(true);
                    cam.LookAt(G(S(0)) + GameDir(S(0).transform) * 8000f + GameRight(S(0).transform) * 1200f - GameUp(S(0).transform) * 300f, S(0).transform);
                    Step = 1;
                    break;
                case 1:
                    if (stepMs < 6000f) break;
                    S(0).scriptedSpeed = S(1).scriptedSpeed = -1f;
                    S(0).CloakingPossible = S(1).CloakingPossible = true;
                    LeaveCutscene();
                    Step = 2;
                    break;
                case 2:
                case 3:
                    if (stepMs < 100000f) break;
                    int a = Step == 2 ? 2 : 4;
                    Show(S(a), PlayerGame + new Vector3(-40000, 3000, 20000), PlayerGame - (PlayerGame + new Vector3(-40000, 3000, 20000)));
                    Show(S(a + 1), PlayerGame + new Vector3(-43000, 3000, 20000), PlayerGame - (PlayerGame + new Vector3(-43000, 3000, 20000)));
                    S(a).CloakingPossible = S(a + 1).CloakingPossible = true;
                    Step++;
                    break;
            }
        }

        // The "Meanwhile..." cutscenes: 2000 ms -> the caption (event 1), over -> 2000 ms -> statusValue 1.
        void TickMeanwhile()
        {
            switch (Step)
            {
                case 0: if (stepMs >= 2000f) Step = 1; break;
                case 1: if (Over(0)) Step = 2; break;
                case 2: if (stepMs >= 2000f) { Story.Mission.value = 1; Step = 3; } break;
            }
        }

        // 102 (process 6349-6903).
        void Tick102(float dtMs)
        {
            var carrier = S(0);
            switch (Step)
            {
                case 0:
                    if (!Triggered(0) || carrier == null) break;
                    EnterCutscene(false);
                    SetPlayerVisible(false);
                    cam.LookAt(G(carrier) + new Vector3(9000, -7000, 40000), carrier.transform);
                    c.MusicOwned = true;
                    level.Traffic.MusicMuted = true;
                    c.PlayMusic(sn?.mission102, false);
                    Step = 1;
                    break;
                case 1:
                    cam.SetDolly(new Vector3(0.6f, 0.8f, -2.5f));
                    if (Over(2)) { if (timerMs < 0f || specterWake == 0f) specterWake = T; }
                    if (specterWake > 0f && T - specterWake >= 2000f)
                    {
                        LeaveCutscene();
                        c.PlayMusic(sn?.mission102Loop, true);
                        Step = 2;
                    }
                    break;
                case 2:
                    if (stepMs < 30000f) break;
                    WakeSpecters102(true);
                    var lead = S(6);
                    EnterCutscene(false);
                    SetPlayerVisible(false);
                    cam.LookAt(G(lead) + GameDir(lead.transform) * 4500f + GameRight(lead.transform) * 600f + GameUp(lead.transform) * 400f, lead.transform);
                    Step = 3;
                    break;
                case 3:
                    for (int i = 6; i <= 9; i++) if (S(i) != null) S(i).scriptedSpeed = i == 6 ? 2.3f : 2.2f;
                    if (S(6) != null) cam.SetDolly(GameDir(S(6).transform) * 2.04f + GameRight(S(6).transform) * 0.04f);
                    if (stepMs < 10000f) break;
                    for (int i = 6; i <= 9; i++) if (S(i) != null) { S(i).scriptedSpeed = -1f; S(i).CloakingPossible = true; }
                    LeaveCutscene();
                    timerMs = 0f;
                    Step = 4;
                    break;
                case 4:
                    if (timerMs >= 60000f) { timerMs = 0f; WakeSpecters102(false); }
                    if (Story.Mission.value >= 10 || carrier == null) break;
                    Story.Mission.type = StoryType.Level;
                    EnterCutscene(false);
                    SetPlayerVisible(false);
                    cam.LookAt(G(carrier) + new Vector3(9000, -7000, 40000), carrier.transform);
                    for (int i = 2; i <= 9; i++) Remove(S(i));
                    if (sn != null) Sfx.PlayAt(sn.carrierJump, carrier.transform.position);
                    Step = 5;
                    break;
                case 5:
                    carrier.transform.position += carrier.transform.forward * 6f * dtMs * M;
                    cam.SetDolly(new Vector3(0.4f, 0.1f, -1.8f));
                    if (stepMs >= 8000f) Step = 6;
                    break;
                case 6:
                    carrier.transform.position += carrier.transform.forward * 200f * dtMs * M;
                    if (stepMs >= 4000f) { carrier.SetVisible(false); LeaveCutscene(); Step = 7; }
                    break;
            }
        }
        float specterWake;

        /// <summary>102's Specters: the first wave by the carrier and around the player; later the dead ones come back.</summary>
        void WakeSpecters102(bool first)
        {
            var carrierPos = G(S(0));
            for (int i = 6; i <= 9; i++)
            {
                var s = S(i);
                if (s == null) continue;
                if (!first && s.Target.Alive && !s.Gone) continue;
                Vector3 at = first && i == 6 ? carrierPos + new Vector3(-82000, 2000, 0)
                           : first && i == 7 ? carrierPos + new Vector3(-84000, 1200, -2000)
                           : PlayerGame + new Vector3(Sign() * (35000 + R(10000)), R(10000) - 5000, Sign() * (35000 + R(10000)));
                if (!first) s.Revive(ToUnity(at));
                Show(s, at, new Vector3(1, 0, 0));
                if (i <= 7) s.Cloak(1000f);
                var drop = S(2 + R(4));
                s.SetOnlyEnemy(R(5) == 0 || drop == null || !drop.Target.Alive ? level.Health.Target : drop.Target);
                if (first) s.scriptedSpeed = 2.2f;
            }
        }

        // 105 (process 7180-7865).
        void Tick105(float dtMs)
        {
            var light = LightGame;
            var dir = PlayerDirGame;
            var right = GameRight(Player);
            var step = (6.08f * dir + 0.2f * right) * 0.4f;
            switch (Step)
            {
                case 1:
                    cam.SetDolly(step);
                    if (stepMs >= 13000f) Step = 2;
                    break;
                case 2:
                    cam.SetDolly(step * 0.9f / 0.4f * 0.4f);
                    if (!Over(1)) break;
                    for (int k = 0; k < 2; k++)
                    {
                        var s = S(k);
                        if (s == null) continue;
                        var r = new Route(false);
                        r.points.Add(k == 0 ? 900000f * (right - dir) : -900000f * dir - 900000f * right);
                        s.scriptedSpeed = -1f;
                        s.SetRoute(r);
                    }
                    Step = 3;
                    break;
                case 3: cam.SetDolly(step); if (stepMs >= 3000f) Step = 4; break;
                case 4: cam.SetDolly(step * 0.25f); if (stepMs >= 3000f) { playerSpeed = 0f; LeaveCutscene(); Step = 5; } break;
                case 5: if (stepMs >= 10000f) { Remove(S(0)); Remove(S(1)); Step = 6; } break;
                case 6:
                {
                    if (stepMs < 24000f) break;
                    var s2 = new Vector3(PlayerGame.x + light.x * 100000f, 0, PlayerGame.z + light.z * 100000f) - right * 30000f;
                    var up = GameUp(Player);
                    Show(S(2), s2, -light);
                    Show(S(3), s2 + right * 2200f - up * 200f - dir * 2200f, -light);
                    Show(S(4), s2 - right * 2200f + up * 200f - dir * 2200f, -light);
                    for (int i = 2; i <= 4; i++) { S(i).Cloak(1000f); S(i).scriptedSpeed = 2.5f - 0.1f * (i - 2); }
                    EnterCutscene(true);
                    cam.LookAt(G(S(2)) + GameDir(S(2).transform) * 6800f + GameRight(S(2).transform) * 1200f + GameUp(S(2).transform) * 400f, S(2).transform);
                    Step = 7;
                    break;
                }
                case 7:
                    if (S(2) != null) cam.SetDolly(GameDir(S(2).transform) * 1.96f + GameRight(S(2).transform) * 0.03f);
                    if (stepMs < 10000f) break;
                    for (int i = 2; i <= 4; i++) { S(i).scriptedSpeed = -1f; S(i).CloakingPossible = true; }
                    playerSpeed = 0f;
                    LeaveCutscene();
                    Step = 8;
                    break;
                case 8: if (stepMs >= 60000f) { timerMs = 0f; Step = 9; } break;
                case 9:
                    if (timerMs >= 110000f)
                    {
                        timerMs = 0f;
                        for (int i = 2; i <= 4; i++)
                        {
                            var s = S(i);
                            if (s == null || (s.Target.Alive && !s.Gone)) continue;
                            var at = PlayerGame + light * 100000f + new Vector3(10000 + 5000 * i + R(1000), R(1000), R(1000));
                            s.Revive(ToUnity(at));
                            Show(s, at, -light);
                        }
                    }
                    if (c.PlayerRoute != null && c.PlayerRoute.Waypoint == null && !level.Health.Dead)
                    {
                        c.PlayerInvulnerable = true;
                        Step = 10;
                    }
                    break;
                case 10:
                    if (!Over(7)) break;
                    EnterCutscene(false);
                    Player.rotation = Quaternion.LookRotation(Dir(light), Vector3.up);
                    cam.LookAt(PlayerGame + PlayerDirGame * 8000f + GameRight(Player) * 1000f + GameUp(Player) * 1000f, Player);
                    Step = 11;
                    break;
                case 11:
                    if (bomb == null && stepMs >= 2500f)
                    {
                        bomb = Scenery("rocket_explosive", PlayerGame, Player.rotation, "Reverse-matter bomb");
                        if (bomb != null) cam.SetTarget(bomb.transform);
                        Sfx.PlayAt(StoryAssets.Load()?.probeLaunch, Player.position);   // 14 Explosion_Bomb_AMR_Tormentor
                        bombMs = 0f;
                    }
                    if (bomb == null) break;
                    bombMs += dtMs;
                    bomb.transform.position += bomb.transform.forward * 13f * dtMs * M;
                    if (bombMs >= 9000f && bombMs - dtMs < 9000f && sn != null) Sfx.PlayAt(sn.explosion, Player.position);
                    if (bombMs >= 9000f && level.Backdrop != null) level.Backdrop.sunScaleFactor *= Mathf.Pow(0.95f, dtMs / 33f);
                    if (bombMs >= 10000f) { c.Fade(false, Color.white, 500f); Step = 12; }
                    break;
                case 12:
                    if (level.Backdrop != null && level.Backdrop.sunScaleFactor < 10f) level.Backdrop.sunScaleFactor *= Mathf.Pow(4f, dtMs / 33f);
                    cam.Rumble = 0.5f;
                    foreach (var s in c.Ships) if (s != null && s.Race == Standing.Specter && s.Target.Alive) s.InitPush(Player.position, 100000f * M);
                    if (!c.FadeDone) break;
                    c.Fade(true, Color.white, 2000f);
                    cam.SetTarget(Player);
                    Player.rotation = Quaternion.LookRotation(-Player.forward, Vector3.up);
                    if (bomb != null) { Object.Destroy(bomb); bomb = null; }
                    level.Backdrop?.SwitchSun("sn_supernova");
                    playerSpeed = 12f;
                    Step = 13;
                    break;
                case 13:
                    Player.Rotate(Vector3.one, dtMs / 800f * Mathf.Rad2Deg, Space.Self);
                    cam.Rumble = 0.5f;
                    if (stepMs >= 6000f) AdvanceAndTravel(1, 111);
                    break;
            }
        }
        float bombMs;

        // 106 (process ~2317-2470).
        void Tick106()
        {
            var sp = S(0);
            if (Step >= 2 && Step <= 4 && sp != null) sp.scriptedSpeed = 1f;
            switch (Step)
            {
                case 1:
                    cam.SetDolly(new Vector3(-0.3f, -0.05f, 0.1f));
                    if (Over(2) && sp != null) { sp.Wake(); sp.SetVisible(true); sp.scriptedSpeed = 1f; Step = 2; }
                    break;
                case 2:
                    cam.SetDolly(new Vector3(-0.1f, -0.1f, 0.4f));
                    if (stepMs >= 3000f && sp != null) { cam.LookAt(G(sp) + GameDir(sp.transform) * 8000f + GameUp(sp.transform) * 500f + GameRight(sp.transform) * 1000f, sp.transform); Step = 3; }
                    break;
                case 3: if (Triggered(4)) Step = 4; break;
                case 4:
                    if (!Over(4)) break;
                    cam.SetDolly(Vector3.zero);
                    if (sp != null) { sp.scriptedSpeed = -1f; sp.Target.Damage(9999999, true, Vector3.zero); }
                    Step = 5;
                    break;
                case 5: if (stepMs >= 3000f) Step = 6; break;
                case 6: if (Over(5)) AdvanceAndTravel(2, 10); break;   // 106 -> 107 -> 108, then Thynome
            }
        }

        // 114: one pirate woken wakes them all.
        void Tick114()
        {
            if (Step != 0) return;
            bool any = false;
            for (int i = 0; i < 6; i++) if (S(i) != null && !S(i).Asleep) any = true;
            if (!any) return;
            for (int i = 0; i < 6; i++) if (S(i) != null) { S(i).detectRange = 50000f; S(i).Wake(); }
            Step = 1;
        }

        // 125 (campaign_levels_c.md 3.5).
        void Tick125()
        {
            var dock = level.Docking;
            switch (Step)
            {
                case 0:
                    if (!Triggered(1)) break;
                    var r = new Route(false); r.points.Add(new Vector3(-70000, 0, -130000));
                    c.SetPlayerRoute(r);
                    level.Navigation?.SetRoute(r);
                    Step = 1;
                    break;
                case 1:
                    if (c.PlayerRoute == null || c.PlayerRoute.Waypoint != null) break;
                    for (int k = 0; k < 3; k++)
                    {
                        var box = S(8 + k);
                        if (box == null) continue;
                        box.Target.displayName = $"{Localization.Get(3212)} {k + 1}";
                        box.DockingType = ObjectDocking.Hackable;
                        box.RadarHidden = false;
                    }
                    Step = 2;
                    break;
                case 2:
                {
                    if (!Over(2)) break;
                    var p = PlayerGame;
                    for (int k = 0; k < 4; k++)
                    {
                        float s = k % 2 == 0 ? 1f : -1f;
                        var at = p + new Vector3(s * (2000 * k + 2000), 2000 + R(1000), -57000 - s * R(2000));
                        Show(S(2 + k), at, p - at);
                        S(2 + k).scriptedSpeed = 0f;
                        S(2 + k).SetOnlyEnemy(level.Health.Target);
                    }
                    EnterCutscene(false);
                    SetPlayerVisible(false);
                    var s4 = S(4);
                    cam.LookAt(G(s4) + GameDir(s4.transform) * 4000f - GameUp(s4.transform) * 500f, s4.transform);
                    Step = 3;
                    break;
                }
                case 3:
                    for (int k = 2; k <= 5; k++) if (S(k) != null) S(k).scriptedSpeed = 2f;
                    if (stepMs < 7000f) break;
                    for (int k = 2; k <= 5; k++) if (S(k) != null) S(k).scriptedSpeed = -1f;
                    LeaveCutscene();
                    Step = 4;
                    break;
                case 4:
                case 5:
                case 6:
                    if (dock == null || !dock.HackingWon || dock.Target == null || dock.Target.DockingType != ObjectDocking.Hackable) break;
                    dock.Target.DockingType = 0;
                    dock.Target.Target.displayName = "";
                    dock.Target.RadarHidden = true;
                    dock.Undock();
                    if (Step == 5)
                    {
                        for (int k = 0; k < 2; k++)
                        {
                            var at = PlayerGame + new Vector3(25000 + 1000 * k, 2300 + 50 * k, 25000);
                            Show(S(6 + k), at, PlayerGame - at);
                        }
                    }
                    Step++;
                    break;
            }
        }

        // 131: the fly-by, then the controls back.
        void Tick131()
        {
            if (Step == 1 && stepMs >= 3000f) Step = 2;
            else if (Step == 2 && Over(0)) { playerSpeed = 0f; LeaveCutscene(); Step = 3; }
        }

        // 135 (campaign_levels_c.md 3.8).
        void Tick135()
        {
            var dock = level.Docking;
            void Bring()
            {
                for (int k = 1; k <= 2; k++)
                {
                    var s = S(k);
                    if (s == null) continue;
                    var at = PlayerGame + new Vector3(25000 + 1000 * k, 5000, 25000);
                    if (!s.Target.Alive || s.Gone) s.Revive(ToUnity(at));
                    Show(s, at, PlayerGame - at);
                    s.SetOnlyEnemy(level.Health.Target);
                }
            }
            switch (Step)
            {
                case 0:
                    if ((dock != null && dock.IsDocked) || T > 60000f) { Bring(); timerMs = 0f; Step = 1; }
                    break;
                case 1:
                case 2:
                    if (Step == 1 && Story.Mission.value >= 70) Step = 2;
                    if (timerMs >= 75000f)
                    {
                        timerMs = 0f;
                        bool dead = (S(1) == null || !S(1).Target.Alive) || (S(2) == null || !S(2).Target.Alive);
                        if (dead) { Bring(); if (Step == 2) Step = 3; }
                    }
                    break;
                case 3:
                    if (timerMs >= 75000f) { timerMs = 0f; Bring(); }
                    break;
            }
        }

        // 139 (campaign_levels_c.md 3.10).
        void Tick139()
        {
            var dock = level.Docking;
            switch (Step)
            {
                case 0:
                    if (dock == null || !dock.HackingWon || dock.Target == null || dock.Target.DockingType != ObjectDocking.Hackable) break;
                    dock.Target.Target.displayName = "";
                    dock.Target.DockingType = 0;
                    dock.Undock();
                    Step = 1;
                    break;
                case 1:
                    if (Triggered(1) && !turned)
                    {
                        turned = true;
                        foreach (var s in c.Ships) if (s != null && s.Race == 1 && !s.IsFixed) { s.alwaysFriend = false; s.alwaysEnemy = true; s.turnedEnemy = true; }
                    }
                    if (dock == null || !dock.HackingWon || dock.Target == null || dock.Target.DockingType != ObjectDocking.Hackable) break;
                    // The other one carries the prism: its cargo bots (docking type 2, the counter from 0).
                    dock.Target.DockingType = ObjectDocking.Pickup;
                    Session.StoryCounter = 0;
                    Step = 2;
                    break;
            }
        }
        bool turned;

        // 142 (campaign_levels_c.md 3.11).
        void Tick142()
        {
            var g = S(0);
            if (g != null && Step < 2 && c.PlayerRoute != null && c.PlayerRoute.points.Count > 0
                && (G(g) - c.PlayerRoute.points[0]).magnitude < 3000f) g.SetSpeed(0f);
            switch (Step)
            {
                case 0: if (c.PlayerRoute != null && c.PlayerRoute.Waypoint == null) Step = 1; break;
                case 1: if (level.GasClouds != null && level.GasClouds.AnyExploded) Step = 2; break;
                case 2:
                    for (int item = 201; item <= 205; item++)
                        if (Story.CargoOf(item) > 0) { if (g != null) g.SetSpeed(2.1f); Step = 3; break; }
                    break;
            }
        }

        // 144 (process case 0x90).
        void Tick144(float dtMs)
        {
            if (helper != null) helper.transform.position += ToUnity(new Vector3(1, 0, -1).normalized * 5f * dtMs) - ToUnity(Vector3.zero);
            switch (Step)
            {
                case 1: Step = 2; break;
                case 2: if (Over(3)) Step = 3; break;
                case 3:
                    for (int i = 1; i < c.Ships.Count; i++)
                    {
                        var s = S(i);
                        if (s == null) continue;
                        if (!s.Cloaked && R(100) < 10) { s.CloakingPossible = true; s.Cloak(20000f); }
                        s.scriptedSpeed = stepMs * 0.05f / 33f;
                    }
                    if (stepMs >= 4000f && S(0) != null) S(0).scriptedSpeed = (stepMs - 4000f) * 0.05f / 33f;
                    if (stepMs >= 7001f) AdvanceAndTravel(1, 112);
                    break;
            }
        }

        // 145 (campaign_levels_c.md 3.13).
        void Tick145(float dtMs)
        {
            var harval = S(0);
            var arrayPos = new Vector3(-50000, 0, 50000);
            switch (Step)
            {
                case 0: Step = 1; break;
                case 1:
                    if (!Over(0) || harval == null) break;
                    EnterCutscene(false);
                    SetPlayerVisible(false);
                    cam.LookAt(G(harval) + GameDir(harval.transform) * 18000f + GameRight(harval.transform) * 3000f, harval.transform);
                    Step = 2;
                    break;
                case 2:
                    if (stepMs < 1000f) break;
                    helper = Scenery("rocket_explosive", G(harval), harval.transform.rotation, "Harval's shot");
                    if (helper != null) { helper.transform.rotation = Quaternion.LookRotation((ToUnity(arrayPos) - helper.transform.position).normalized); cam.SetTarget(helper.transform); }
                    Step = 3;
                    break;
                case 3:
                    if (helper != null) helper.transform.position += helper.transform.forward * 8f * dtMs * M;
                    if (stepMs < 5000f) break;
                    Explosion.Spawn(0, ToUnity(arrayPos), Vector3.forward, 6f, CombatAssets.Pick(combat?.explosionBig), true);
                    Step = 4;
                    break;
                case 4:
                    if (stepMs < 324f) break;
                    var array = S(14);
                    if (array != null) array.SetVisible(false);
                    if (explosionAnim != null)
                    {
                        explosionAnim.SetActive(true);
                        foreach (var a in explosionAnim.GetComponentsInChildren<PartAnimation>(true)) { a.speed = 0.3f; a.loop = false; a.Restart(); }
                    }
                    if (helper != null) { Object.Destroy(helper); helper = null; }
                    Step = 6;   // event 5 is radio 2's trigger: only once the aftermath is over
                    break;
                case 6:
                    for (int i = 0; i <= 12; i++)
                    {
                        var s = S(i);
                        if (s == null) continue;
                        if (stepMs >= 2000f && stepMs <= 5000f) s.transform.Rotate(Vector3.up, 0.02f * dtMs, Space.World);
                        s.scriptedSpeed = 2f + stepMs * 0.001f;
                    }
                    if (stepMs < 10000f) break;
                    for (int i = 0; i <= 12; i++) Remove(S(i));
                    LeaveCutscene();
                    c.Event = 5;   // radio 2, then the win (Objective(4, 2))
                    break;
            }
        }

        // 154 (campaign_levels_c.md 3.15).
        void Tick154()
        {
            var hans = S(0);
            var valkyrie = S(1);
            var dock = level.Docking;
            switch (Step)
            {
                case 0:
                    if (!Triggered(0)) break;
                    EnterCutscene(false);
                    var f2 = S(2);
                    if (f2 != null) { Show(f2, G(f2), PlayerGame - G(f2)); cam.LookAt(G(f2) + new Vector3(300, 300, 5800), f2.transform); }
                    for (int i = 2; i < 22; i++) if (S(i) != null) { Show(S(i), G(S(i)), PlayerGame - G(S(i))); S(i).scriptedSpeed = 0f; }
                    Step = 1;
                    break;
                case 1: if (Over(1) && stepMs >= 1500f) { for (int i = 2; i < 22; i++) S(i)?.SetVisible(false); cam.LookAt(PlayerGame + new Vector3(-350, 400, -1500), Player); Step = 2; } break;
                case 2: if (Over(2) && stepMs >= 1000f && valkyrie != null) { cam.LookAt(G(valkyrie) + new Vector3(0, 4000, 26000), valkyrie.transform); Step = 3; } break;
                case 3: if (Over(3) && stepMs >= 1000f) { cam.LookAt(PlayerGame + new Vector3(-350, 400, -1500), Player); Step = 4; } break;
                case 4: if (Over(4) && stepMs >= 1000f && valkyrie != null) { cam.LookAt(G(valkyrie) + new Vector3(0, 4000, 42000), valkyrie.transform); Step = 5; } break;
                case 5:
                    if (!Over(5) || stepMs < 1000f) break;
                    cam.LookAt(PlayerGame + new Vector3(150, 400, -1500), Player);
                    if (hans != null) { hans.Place(ToUnity(new Vector3(-10000, 0, 22000)), Dir(-new Vector3(-10000, 0, 22000))); hans.frozen = false; hans.scriptedSpeed = 2f; }
                    for (int i = 2; i < 22; i++) if (S(i) != null) S(i).scriptedSpeed = 0f;
                    Step = 6;
                    break;
                case 6: if (Over(6) && stepMs >= 1000f && hans != null) { cam.LookAt(G(hans) + new Vector3(200, 300, 1800), hans.transform); Step = 7; } break;
                case 7:
                    if (hans != null && valkyrie != null)
                    {
                        var to = valkyrie.transform.position - hans.transform.position;
                        if (to.sqrMagnitude > 1e-6f) hans.transform.rotation = Quaternion.LookRotation(to.normalized, Vector3.up);
                        if (to.magnitude / M < 3000f) { hans.scriptedSpeed = 0f; Step = 8; }
                    }
                    break;
                case 8: if (stepMs >= 2000f) Step = 9; break;
                case 9:
                    if (!Over(7) || stepMs < 2000f) break;
                    for (int i = 2; i < 22; i++)
                    {
                        var s = S(i);
                        if (s == null) continue;
                        s.SetVisible(true);
                        s.Wake();
                        s.scriptedSpeed = -1f;
                        s.SetOnlyEnemy(i % 3 == 0 && hans != null ? hans.Target : level.Health.Target);
                    }
                    if (valkyrie != null)
                    {
                        valkyrie.SetRace(Standing.Pirate);
                        valkyrie.alwaysFriend = false;
                        valkyrie.alwaysEnemy = true;
                        valkyrie.RadarHidden = false;
                        valkyrie.DockingType = ObjectDocking.Hackable;
                    }
                    LeaveCutscene();
                    Step = 10;
                    break;
                case 10:
                    if (Over(8) && c.TimeLimitMs <= 0f && !hacked)
                    {
                        c.TimeLimitMs = c.MissionMs + 91000f;
                        c.FailObjective = () => c.TimeLeftMs == 0f;   // Objective(3, 91000) counted from here
                    }
                    if (dock != null && dock.HackingWon && dock.Target == valkyrie && !hacked)
                    {
                        hacked = true;
                        c.FailObjective = null;
                        c.TimeLimitMs = 0f;
                        for (int i = 2; i < 22; i++) S(i)?.SetOnlyEnemy(null);
                        c.Event = 11;
                        Step = 11;
                    }
                    break;
            }
        }
        bool hacked;

        // 157 (campaign_levels_c.md 3.17): the fight, then the ending of the add-on's story.
        void Tick157(float dtMs)
        {
            var harval = S(21);
            var alice = S(22);
            var vp = new Vector3(-120000, 0, 20000);
            switch (Step)
            {
                case 0:
                    helper = new GameObject("Cutscene helper");
                    helper.transform.position = ToUnity(new Vector3(-120000, 0, 5000));
                    Step = 1;
                    break;
                case 1:
                    if (!Over(0)) break;
                    EnterCutscene(false);
                    cam.LookAt(new Vector3(-120000, 3000, -20000), helper.transform);
                    Step = 2;
                    break;
                case 2:
                    helper.transform.position += ToUnity(new Vector3(0, 0, 3f * dtMs)) - ToUnity(Vector3.zero);
                    cam.SetDolly(new Vector3(0, 0, 1f));
                    if (stepMs < 16000f) break;
                    for (int i = 11; i <= 21; i++) { var s = S(i); if (s == null) continue; s.Wake(); s.SetVisible(true); s.scriptedSpeed = 0f; }
                    if (harval != null) cam.LookAt(G(harval) + new Vector3(-1500, -5000, 2500), harval.transform);
                    Step = 3;
                    break;
                case 3: if (stepMs >= 8000f) Step = 4; break;
                case 4:
                    for (int i = 11; i <= 21; i++) if (S(i) != null) S(i).scriptedSpeed = stepMs * 0.02f / 33f;
                    if (!Over(3) || stepMs < 18000f) break;
                    for (int i = 11; i <= 21; i++)
                    {
                        var s = S(i);
                        if (s == null) continue;
                        s.scriptedSpeed = -1f;
                        s.CloakingPossible = i < 21;
                        var r = new Route(false);
                        r.points.Add(i < 21 ? new Vector3(120000, R(12000) - 6000, R(30000) - 87000) : new Vector3(20000, R(6000) - 3000, R(6000) - 7000));
                        s.SetRoute(r);
                    }
                    LeaveCutscene();
                    c.Event = 5;
                    Step = 5;
                    break;
                case 5:
                {
                    if (harval != null && timerMs >= 25000f) { timerMs = 0f; harval.CloakingPossible = !harval.CloakingPossible; }
                    int dead = 0;
                    for (int i = 11; i <= 21; i++) if (c.ShipDead(i)) dead++;
                    bool done = (dead >= 9 && T > 200000f) || (harval != null && harval.Target.HullFraction < 0.25f);
                    if (!done) break;
                    EnterCutscene(false);
                    if (harval != null) harval.Target.invulnerable = true;
                    cam.LookAt(vp + new Vector3(45000, 2000, 11000), null, ToUnity(vp));
                    if (alice != null) { var at = vp + new Vector3(60000, 1800, 12000); Show(alice, at, vp - at); alice.scriptedSpeed = 3f; }
                    c.Event = 6;
                    Step = 6;
                    break;
                }
                case 6:
                    if (!Triggered(10)) break;
                    Remove(alice);
                    c.Event = 7;
                    Step = 7;
                    break;
                case 7:
                    if (!Over(10)) break;
                    if (harval != null) { var at = vp + new Vector3(4000, -600, 38000); harval.Place(ToUnity(at), Dir(vp - at)); harval.scriptedSpeed = 4f; }
                    cam.LookAt(vp + new Vector3(35000, 0, 70000), null, ToUnity(vp));
                    c.Event = 8;
                    Step = 8;
                    break;
                case 8:
                    if (stepMs < 12000f || !Over(12)) break;
                    Remove(harval);
                    c.Event = 9;
                    Step = 9;
                    break;
                case 9:
                    if (stepMs >= 6000f && (int)(stepMs / 6000f) != (int)((stepMs - dtMs) / 6000f))
                        Explosion.Spawn(0, ToUnity(vp + new Vector3(-6000, 2000, -10000)), Vector3.forward, 4f, CombatAssets.Pick(combat?.explosionMid), true);   // 2244 Explosion_Med_2D
                    if (!Over(14)) break;
                    Scenery("sn_burning_valkyrie_stage_2", vp, OrbitLayout.RotationToUnity(new Vector3(0, Mathf.PI, 0)), "Valkyrie burning");
                    cam.LookAt(vp + new Vector3(50000, 0, 70000), null, ToUnity(vp));
                    Step = 10;
                    break;
                case 10:
                    if (!Over(15) || stepMs < 3000f) break;
                    cam.Rumble = 0.4f;
                    beam = Scenery("sn_plasma_gun_fx_valkyrie_beam_anim_add", vp, Quaternion.LookRotation(Dir(LightGame), Vector3.up), "Plasma beam");
                    if (sn != null) Sfx.PlayAt(sn.valkyrieBeam, cam.Camera != null ? cam.Camera.position : Player.position);
                    Step = 11;
                    break;
                case 11:
                    if (beam != null) beam.transform.rotation = Quaternion.LookRotation(Dir(LightGame), Vector3.up);
                    if (stepMs < 10000f) break;
                    helper.transform.position = ToUnity(vp);
                    cam.SetTarget(helper.transform);
                    Step = 12;
                    break;
                case 12:
                    if (stepMs >= 5000f) helper.transform.position += ToUnity(LightGame * 35f * dtMs) - ToUnity(Vector3.zero);
                    if (stepMs >= 5000f && stepMs - dtMs < 5000f)
                    {
                        // Level::switchSkyboxForSupernovaReversal: the system's normal sky, no more flares.
                        if (level.Backdrop != null) level.Backdrop.sunScaleFactor = 0.6f;
                        foreach (var r in Object.FindObjectsByType<SkyLayers>(FindObjectsInactive.Exclude)) r.gameObject.SetActive(false);
                    }
                    if (stepMs >= 5700f && stepMs - dtMs < 5700f)
                    {
                        if (beam != null) beam.SetActive(false);
                        c.Fade(false, Color.white, 800f);
                        if (sn != null) Sfx.PlayAt(sn.explosion, Player.position);
                    }
                    if (stepMs >= 6500f) AdvanceAndTravel(1, 111);
                    break;
            }
        }

        // 158 (campaign_levels_c.md 3.18).
        void Tick158(float dtMs)
        {
            var harval = S(0);
            switch (Step)
            {
                case 1:
                    cam.SetDolly(new Vector3(0.2f, 0f, 0.1f));
                    if (harval != null && T >= 25000f && !harval.gameObject.activeSelf == false && T - dtMs < 25000f)
                    {
                        harval.SetVisible(true);
                        cam.SetTarget(harval.transform);
                        harval.scriptedSpeed = 2.5f;
                    }
                    if (T >= 30000f) { if (harval != null) harval.scriptedSpeed = 1f; Step = 2; }
                    break;
                case 2:
                    if (stepMs < 12000f || !Over(2)) break;
                    playerSpeed = 0f;
                    LeaveCutscene();
                    if (harval != null) { harval.scriptedSpeed = -1f; harval.CloakingPossible = true; harval.SetOnlyEnemy(level.Health.Target); }
                    timerMs = 0f;
                    cloakMs = 0f;
                    Step = 3;
                    break;
                case 3:
                    cloakMs += dtMs;
                    if (harval != null && cloakMs >= 25000f) { cloakMs = 0f; harval.CloakingPossible = !harval.CloakingPossible; }
                    if (timerMs < 4000f || harval == null || !harval.Target.Alive) break;
                    timerMs = 0f;
                    if ((harval.transform.position - Player.position).magnitude / M < 25000f && R(100) > 60)
                        for (int i = 1; i <= 3; i++)
                        {
                            var s = S(i);
                            if (s == null || !(s.Inactive || s.Gone)) continue;
                            s.Revive(harval.transform.position);
                            s.Wake();
                            s.SetVisible(true);
                            break;
                        }
                    break;
            }
        }
        float cloakMs;

        // ---- the shuttles of 94 / 102 (Route docking targets and times, PlayerFighter case 9) ------------------------

        class Shuttle
        {
            public NpcShip ship;
            public Vector3[] points;   // game units
            public float[] dockMs;
            public int dropOff, leg;
            public float perUnitMs, waitMs, tickMs;
            public bool rhino, waiting;
        }
        readonly List<Shuttle> shuttles = new List<Shuttle>();

        /// <summary>The loops station -> waypoint -> drop-off with their docking times; at the drop-off the evacuees go aboard
        /// the freighter / carrier (1 per 1500 ms, the Rhinos 1 per 200 ms). At 94 they stop unloading once the rest fits
        /// the player's cabins (the player brings the last load).</summary>
        void UpdateShuttles(float dtMs)
        {
            foreach (var sh in shuttles)
            {
                var s = sh.ship;
                if (s == null || !s.Target.Alive || s.Gone) continue;
                var target = sh.points[sh.leg];
                if (sh.waiting)
                {
                    s.scriptedSpeed = 0f;
                    sh.waitMs += dtMs;
                    if (sh.leg == sh.dropOff && Story.Mission.type == StoryType.Passengers)
                    {
                        sh.tickMs += dtMs;
                        int cabins = Freelance.MaxPassengers(level.Database);
                        bool stop = !sh.rhino && Story.Mission.value <= cabins;
                        while (sh.tickMs >= sh.perUnitMs) { sh.tickMs -= sh.perUnitMs; if (!stop && Story.Mission.value > 0) Story.Mission.value--; }
                    }
                    if (sh.waitMs < sh.dockMs[sh.leg]) continue;
                    sh.waiting = false;
                    sh.leg = (sh.leg + 1) % sh.points.Length;
                    continue;
                }
                var to = ToUnity(target) - s.transform.position;
                if (to.magnitude / M < 2500f)
                {
                    sh.waiting = sh.dockMs[sh.leg] > 0f;
                    sh.waitMs = sh.tickMs = 0f;
                    if (!sh.waiting) sh.leg = (sh.leg + 1) % sh.points.Length;
                    continue;
                }
                s.scriptedSpeed = 2f;
                var want = Quaternion.LookRotation(to.normalized, Vector3.up);
                s.transform.rotation = Quaternion.RotateTowards(s.transform.rotation, want, 0.05f * dtMs);
            }
        }
    }
}
