// GoF2StationLevel.cs
// The docked-station scene (ModStation, module 5): builds the hangar (the main station view) and the bar
// (Space Lounge) of the current station and switches between them instantly, like the original.
// Research and all constants: Reference/research/station_interior.md, tables in GoF2StationTables.
//   Hangar (CutScene 0x17 / Level::createScene 0xc2910): room per hangar index at identity, the player's ship on a
//     turntable at (0, Y[ship], 0) (NPC engine meshes, exhaust off), 0..N parked ships on fixed slots; camera from the
//     phone table relative to the ship pivot with a slow random position drift (ModStation::OnUpdate 0xed2a8);
//     one fixed light from the camera side plus a per-race ambient (ModStation::resetLight 0xe9f1c); Vossk fog.
//   Bar (SpaceLounge 0x197890): room per race (no rotation = Unity yaw 180), 3..4 visitors on random slots as
//     camera-facing billboards with a glow behind and a floor shadow (updateScreenPositions 0x19ec30); camera eases
//     from A to B in 3 s on the first visit, then sways around the room origin (SpaceLounge::update 0x19ef20); lit by
//     the system's sun (StarSystem::initLight); Terran service bot loops, the Midorian prop replays now and then.
// Both show the current system's sky behind the room (Level::createSpace builds the StarSystem for these levels).
// Music per station/race, ambience per screen (Station_Atmo_Mainview / _Lounge).
// Arrival also rolls or refreshes the station's shop stock (GoF2Shop.EnterStation); the shop itself is GoF2HangarWindow.
// Not yet: agents and chat, map, missions, status, turret on the player ship (CutScene::checkForTurret),
// home-base stored ships.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Visuals;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;
using Object = UnityEngine.Object;
using Random = UnityEngine.Random;

namespace GoF2Remake.World
{
    public enum GoF2StationView { Hangar, Lounge }

    [DefaultExecutionOrder(-100)]
    public class GoF2StationLevel : MonoBehaviour
    {
        const float M = GoF2OrbitLayout.MetersPerUnit;
        const float TwoPi = Mathf.PI * 2f;

        [Header("Scene")]
        public Camera mainCamera;
        [Tooltip("LIGHT0: the fixed hangar light, the system's sun in the bar.")]
        public Light keyLight;
        public string spaceScene = "Space";

        [Header("Station (-1 = GoF2Session)")]
        public int stationOverride = -1;
        public int shipOverride = -1;

        [Header("Bar visitors (single-mesh prefabs, set by the scene builder)")]
        public GameObject visitorTerranMale;
        public GameObject visitorTerranFemale;
        public GameObject visitorVossk;
        public GameObject visitorNivelian;
        public GameObject visitorMultipod;
        public GameObject visitorBobolan;
        public GameObject visitorGrey;
        public GameObject visitorGlow;
        public GameObject visitorShadow;
        [Tooltip("Glow material per bar race (materials 34800..34803).")]
        public Material[] glowMaterials = new Material[4];

        [Header("Audio")]
        public AudioSource musicSource;
        public AudioSource ambienceSource;
        public AudioSource ambienceAddSource;
        [Tooltip("Indexed by GoF2StationTables.Music.")]
        public AudioClip[] music = new AudioClip[7];
        public AudioClip mainViewAmbience;
        public AudioClip[] mainViewAdds;
        public AudioClip loungeAmbience;
        public AudioClip[] loungeAdds;

        [Header("Tuning (not recovered constants)")]
        [Tooltip("URP intensity of the hangar light (original: diffuse 1.0, half the space sun's 2.0).")]
        public float hangarLightIntensity = 1.1f;
        [Tooltip("Scales the hangar ambient ((race ambient + GL global 0.2) * material ambient 0.7).")]
        public float hangarAmbientScale = 1f;
        public float sunIntensityAt2 = 1.6f;
        [Tooltip("Seconds between random ambience one-shots (the FMOD events add them; timing not recovered).")]
        public Vector2 ambienceAddInterval = new Vector2(6f, 16f);

        public GoF2StationView View { get; private set; } = GoF2StationView.Hangar;
        public event Action ViewChanged;
        public StationData Station { get; private set; }
        public GoF2OrbitLayout Layout { get; private set; }
        public int HangarIndex { get; private set; }
        public int BarRace { get; private set; }
        public int VisitorCount { get; private set; }
        public GoF2Database Database => db;
        /// <summary>This station's shop stock and ships for sale (kept while it is among the last 3 visited).</summary>
        public GoF2StationStock Stock { get; private set; }
        public bool IntroPlaying => introT < 1.25f && View == GoF2StationView.Lounge;

        GoF2Database db;
        Transform hangarRoot, barRoot, playerShip;
        int shipIndex;
        Vector3 shipPivot;                    // Unity, the camera parent (0, Y[ship at entry], 0)

        // Turntable (ModStation +0xe0 / 120 px per rad), game yaw in radians.
        float shipYaw, flingVelocity;         // rad/s

        // Hangar camera drift: three EaseInOuts around the table position (game units).
        readonly EaseInOut[] drift = { new EaseInOut(), new EaseInOut(), new EaseInOut() };
        readonly bool[] driftSign = new bool[3];
        Vector3 hangarCamBase;

        // Bar camera: intro A -> B (EaseInOutMatrix, t 0.75 -> 1.25), then sway.
        Vector3 barPosA, barPosB;
        Quaternion barRotA, barRotB;
        float introT = 0.75f;
        bool loungeVisited;
        readonly EaseInOut swayYaw = new EaseInOut();
        float swaySpeed = 2f, bobPhase;

        readonly List<Visitor> visitors = new List<Visitor>();
        GoF2PartAnimation midorianProp;
        float midorianTimer;
        float nextAmbienceAdd;

        class Visitor { public Transform body, glow; public Vector3 feet; }

        /// <summary>AEEngine EaseInOut (0x7aa34): a + (b - a) * (sin(phi) * 0.5 + 0.5), phi 3pi/2 -> 5pi/2, Increase(d) adds
        /// d / 65536 * 2pi, so a whole leg takes 32768 units of d.</summary>
        class EaseInOut
        {
            float from, to, phi = 2.5f * Mathf.PI;
            public float Target => to;
            public float Value => from + (to - from) * (Mathf.Sin(phi) * 0.5f + 0.5f);
            public void Start(float a, float b) { from = a; to = b; phi = 1.5f * Mathf.PI; }
            public void Increase(float d) => phi = Mathf.Min(phi + d / 65536f * TwoPi, 2.5f * Mathf.PI);
        }

        // ---- build -------------------------------------------------------------------------------------------

        void Awake()
        {
            db = GoF2Database.Load();
            int station = stationOverride >= 0 ? stationOverride : GoF2Session.StationIndex;
            shipIndex = shipOverride >= 0 ? shipOverride : GoF2Session.ShipIndex;
            Station = db.Stations.Find(s => s.index == station);
            Layout = GoF2OrbitLayout.Build(db, station);
            HangarIndex = GoF2StationTables.HangarIndex(station, Layout.raceId);
            Stock = GoF2Shop.EnterStation(db, station);
            BarRace = GoF2StationTables.BarRace(Layout.raceId);
            if (mainCamera == null) mainCamera = Camera.main;

            GoF2OrbitBuilder.SetupSky(Layout);   // the system's sky shows through the openings of both rooms
            GoF2OrbitBuilder.SpawnBackdrop(Layout, mainCamera);
            BuildHangar();
            BuildBar();
            Debug.Log($"GoF2StationLevel: station {station} {Station?.name} ({Station?.systemName}), hangar {HangarIndex}, " +
                      $"bar {BarRace}, ship {shipIndex}, {VisitorCount} visitors");

            if (musicSource != null)
            {
                var clip = music != null && music.Length > 0 ? music[(int)GoF2StationTables.MusicFor(station, Layout.raceId)] : null;
                if (clip == null && music != null && music.Length > 0) clip = music[0];
                musicSource.clip = clip;
                musicSource.loop = true;
                musicSource.volume = GoF2Settings.MusicVolume;
                if (clip != null) musicSource.Play();
            }
            SetView(GoF2StationView.Hangar, true);
        }

        void BuildHangar()
        {
            hangarRoot = new GameObject("Hangar").transform;
            string room = GoF2StationTables.HangarRoom[HangarIndex];
            // Level::createScene: PlayerStatic + setRotation(0, pi, 0) = Unity identity.
            Spawn(room, Vector3.zero, GoF2OrbitLayout.RotationToUnity(new Vector3(0f, Mathf.PI, 0f)), hangarRoot, "Room");

            float y = GoF2StationTables.ShipY(shipIndex);
            shipPivot = GoF2OrbitLayout.ToUnity(new Vector3(0f, y, 0f));
            var ship = SpawnShip(shipIndex, new Vector3(0f, y, 0f), 0f, hangarRoot, "Player ship");
            playerShip = ship != null ? ship.transform : null;
            shipYaw = GoF2StationTables.StartYaw(HangarIndex);
            ApplyShipYaw();
            SpawnParkedShips();

            // Camera: ModStation::OnInitialize state 0x14 (phone table), rotation order 2 with roll -0.03.
            hangarCamBase = GoF2StationTables.HangarCameraPos[HangarIndex];
            for (int i = 0; i < 3; i++) { driftSign[i] = Random.Range(0, 20) < 10; NextDriftLeg(i, Base(i)); }
        }

        /// <summary>CutScene::replacePlayerShip 0xa53b4: after buying a ship, the new one on the turntable at its own height
        /// (the camera keeps the pivot of the ship the hangar was entered with).</summary>
        public void ReplacePlayerShip(int index)
        {
            if (playerShip != null) Destroy(playerShip.gameObject);
            shipIndex = index;
            var ship = SpawnShip(index, new Vector3(0f, GoF2StationTables.ShipY(index), 0f), 0f, hangarRoot, "Player ship");
            playerShip = ship != null ? ship.transform : null;
            ApplyShipYaw();
        }

        /// <summary>Level::createScene 0x17: count = nextInt(max + 1), 70 % a fighter of the hangar's race, 30 % a random race
        /// (of those 30 % pirates); random free slot, yaw nextInt(300) / 100 rad.</summary>
        void SpawnParkedShips()
        {
            var slots = GoF2StationTables.ParkedSlots[HangarIndex];
            int max = GoF2StationTables.ParkedMax[HangarIndex];
            if (slots == null || max <= 0) return;
            int count = Mathf.Min(Random.Range(0, max + 1), slots.Length);
            var taken = new bool[slots.Length];
            for (int n = 0; n < count; n++)
            {
                int ship = Layout.stationIndex == 100 ? GoF2StationTables.DeepScienceShips[Random.Range(0, 3)] : RandomParkedShip();
                int slot = Random.Range(0, slots.Length), tries = 0;
                while (taken[slot] && ++tries < 100) slot = Random.Range(0, slots.Length);
                if (taken[slot]) break;
                taken[slot] = true;
                var pos = slots[slot] + new Vector3(0f, GoF2StationTables.ShipY(ship), 0f);
                SpawnShip(ship, pos, Random.Range(0, 300) / 100f, hangarRoot, $"Parked ship {n}");
            }
        }

        int RandomParkedShip()
        {
            int race = HangarIndex;
            if (Random.value >= 0.7f) race = Random.value < 0.3f ? 8 : Random.Range(0, 4);
            var list = race == 8 ? GoF2StationTables.PirateFighters : GoF2StationTables.RaceFighters[Mathf.Clamp(race, 0, 3)];
            return list[Random.Range(0, list.Length)];
        }

        void BuildBar()
        {
            barRoot = new GameObject("Space Lounge").transform;
            // createScene branch 4: rooms with no rotation (game identity = Unity yaw 180).
            var room = Spawn(GoF2StationTables.BarRoom[BarRace], Vector3.zero, GoF2OrbitLayout.RotationToUnity(Vector3.zero), barRoot, "Room");
            if (room != null && BarRace == 3)
            {
                // CutScene::initialize (mode 4): bar_midorian_alpha_anim is a one-shot, restarted with 30 % every 2 s.
                foreach (var a in room.GetComponentsInChildren<GoF2PartAnimation>(true))
                    if (a.gameObject.name.Contains("alpha_anim")) { midorianProp = a; a.loop = false; a.play = false; }
            }

            // Generator::createAgents: 3 + nextInt(2) generic agents (no story agents yet), race = system race, 20 % any
            // of the 8 races; Terrans 40 % female.
            VisitorCount = 3 + Random.Range(0, 2);
            var slots = GoF2StationTables.VisitorSlots[BarRace];
            var taken = new bool[slots.Length];
            for (int i = 0; i < VisitorCount; i++)
            {
                int slot;
                do slot = Random.Range(0, slots.Length); while (taken[slot]);
                taken[slot] = true;
                int race = Random.value < 0.2f ? Random.Range(0, 8) : BarRace;
                bool female = race == 0 && Random.value < 0.4f;
                var prefab = VisitorPrefab(GoF2StationTables.VisitorFor(race, female));
                if (prefab == null) continue;
                var feet = GoF2OrbitLayout.ToUnity(slots[slot]);
                var v = new Visitor { feet = feet };
                v.body = Instantiate(prefab, feet, Quaternion.identity, barRoot).transform;
                v.body.name = $"Visitor {i} ({prefab.name})";
                if (visitorGlow != null)
                {
                    v.glow = Instantiate(visitorGlow, feet, Quaternion.identity, barRoot).transform;
                    v.glow.name = $"Visitor {i} glow";
                    var mat = glowMaterials != null && BarRace < glowMaterials.Length ? glowMaterials[BarRace] : null;
                    if (mat != null) foreach (var r in v.glow.GetComponentsInChildren<Renderer>()) r.sharedMaterial = mat;
                }
                if (visitorShadow != null)
                    Instantiate(visitorShadow, feet + new Vector3(0f, 20f * M, 0f), GoF2OrbitLayout.RotationToUnity(Vector3.zero), barRoot).name = $"Visitor {i} shadow";
                visitors.Add(v);
            }

            barPosA = GoF2OrbitLayout.ToUnity(GoF2StationTables.BarCameraStart[BarRace]);
            barPosB = GoF2OrbitLayout.ToUnity(GoF2StationTables.BarCameraRest[BarRace]);
            barRotA = CameraRotation(0f, GoF2StationTables.BarCameraStartYaw[BarRace], 0f);
            barRotB = CameraRotation(0f, GoF2StationTables.BarCameraRestYaw[BarRace], 0f);
            swayYaw.Start(0f, 5f);
        }

        GameObject VisitorPrefab(GoF2StationTables.Visitor v) => v switch
        {
            GoF2StationTables.Visitor.TerranFemale => visitorTerranFemale != null ? visitorTerranFemale : visitorTerranMale,
            GoF2StationTables.Visitor.Vossk => visitorVossk,
            GoF2StationTables.Visitor.Nivelian => visitorNivelian,
            GoF2StationTables.Visitor.Multipod => visitorMultipod,
            GoF2StationTables.Visitor.Bobolan => visitorBobolan,
            GoF2StationTables.Visitor.Grey => visitorGrey,
            _ => visitorTerranMale,
        };

        GameObject Spawn(string assembly, Vector3 unityPos, Quaternion rot, Transform parent, string label)
        {
            var prefab = GoF2AssembledObject.LoadPrefab(db.AssemblyByName(assembly));
            if (prefab == null) { Debug.LogWarning($"GoF2StationLevel: no assembled prefab '{assembly}'"); return null; }
            var go = Instantiate(prefab, unityPos, rot, parent);
            go.name = label;
            foreach (var lod in go.GetComponentsInChildren<LODGroup>()) lod.ForceLOD(0);   // close-up room: full detail
            return go;
        }

        /// <summary>createShip(race, 0, idx, null, false): NPC mesh group, setExhaustVisible(false), asleep.</summary>
        GameObject SpawnShip(int index, Vector3 gamePos, float gameYaw, Transform parent, string label)
        {
            string prefix = $"ship_{index:000}_";
            var entry = db.Assemblies.Find(a => a.category == "ships" && a.name.StartsWith(prefix));
            if (entry == null) return null;
            var go = Spawn(entry.name, GoF2OrbitLayout.ToUnity(gamePos), GoF2OrbitLayout.RotationToUnity(new Vector3(0f, gameYaw, 0f)), parent, label);
            var asm = go != null ? go.GetComponent<GoF2AssembledObject>() : null;
            if (asm != null)
            {
                asm.SetPlayerVariant(false);
                if (asm.npcVariantParts != null) foreach (var p in asm.npcVariantParts) if (p != null) p.SetActive(false);   // exhaust off
            }
            return go;
        }

        /// <summary>Game camera rotation, order 2 (Ry * Rx * Rz, looking down local -Z) -> Unity (looking down +Z).</summary>
        static Quaternion CameraRotation(float x, float y, float z) =>
            Quaternion.Euler(-x * Mathf.Rad2Deg, -y * Mathf.Rad2Deg, z * Mathf.Rad2Deg);

        // ---- view switching ----------------------------------------------------------------------------------

        /// <summary>Instant switch, like ModStation (no fades). The lounge plays its camera intro on the first visit only.</summary>
        public void SetView(GoF2StationView view, bool force = false)
        {
            if (view == View && !force) return;
            View = view;
            hangarRoot.gameObject.SetActive(view == GoF2StationView.Hangar);
            barRoot.gameObject.SetActive(view == GoF2StationView.Lounge);
            if (view == GoF2StationView.Lounge)
            {
                introT = loungeVisited ? 1.25f : 0.75f;   // SpaceLounge::init starts at B
                loungeVisited = true;
                ApplyLoungeLighting();
            }
            else
            {
                flingVelocity = 0f;
                ApplyHangarLighting();
            }
            PlayAmbience(view == GoF2StationView.Hangar ? mainViewAmbience : loungeAmbience);
            UpdateCamera(0f);
            ViewChanged?.Invoke();
        }

        void ApplyHangarLighting()
        {
            if (keyLight != null)
            {
                keyLight.transform.rotation = Quaternion.LookRotation(-GoF2OrbitLayout.DirToUnity(GoF2StationTables.HangarTowardLight).normalized);
                keyLight.color = Color.white;
                keyLight.intensity = hangarLightIntensity;
            }
            var amb = (GoF2StationTables.HangarAmbient(Layout.raceId) + new Color(0.2f, 0.2f, 0.2f)) * 0.7f * hangarAmbientScale;
            RenderSettings.ambientMode = AmbientMode.Flat;
            RenderSettings.ambientLight = new Color(amb.r, amb.g, amb.b);
            SetFog(HangarIndex == 1, GoF2StationTables.HangarFogEnd);
        }

        void ApplyLoungeLighting()
        {
            GoF2OrbitBuilder.SetupLights(Layout, keyLight, null, sunIntensityAt2);
            RenderSettings.ambientMode = AmbientMode.Skybox;
            DynamicGI.UpdateEnvironment();
            SetFog(BarRace == 1, GoF2StationTables.BarFogEnd);
        }

        static void SetFog(bool on, float end)
        {
            RenderSettings.fog = on;
            if (!on) return;
            RenderSettings.fogMode = FogMode.Linear;
            RenderSettings.fogStartDistance = 0f;
            RenderSettings.fogEndDistance = end * M;
            RenderSettings.fogColor = GoF2StationTables.VosskFog;
        }

        // ---- turntable (ModStation::OnTouchMove 0xea340 / OnTouchEnd / OnUpdate) ----------------------------

        /// <summary>Turns the player's ship by 'gameRadians' (the original: +0xe0 += dx px, yaw = +0xe0 / 120).</summary>
        public void RotateShip(float gameRadians)
        {
            flingVelocity = 0f;
            shipYaw += gameRadians;
            ApplyShipYaw();
        }

        /// <summary>Lets the ship keep turning after a drag; slows by x0.9 per 20 ms frame (normalised).</summary>
        public void FlingShip(float gameRadiansPerSecond) => flingVelocity = gameRadiansPerSecond;

        void ApplyShipYaw()
        {
            if (playerShip != null) playerShip.rotation = GoF2OrbitLayout.RotationToUnity(new Vector3(0f, shipYaw, 0f));
        }

        public void SkipIntro()
        {
            if (IntroPlaying) introT = 1.25f;
        }

        /// <summary>ModStation::leaveStation 0xec1ec after the "Depart the station?" confirmation: straight into space.</summary>
        public void Launch()
        {
            GoF2Session.LastDepartureTime = Time.realtimeSinceStartup;   // Status+0x70, for computerTradeGoods
            GoF2Session.ArrivedByTravel = false;
            GoF2Session.LaunchedFromStation = true;
            if (Application.CanStreamedLevelBeLoaded(spaceScene)) SceneManager.LoadScene(spaceScene);
        }

        // ---- per frame ---------------------------------------------------------------------------------------

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f;
            if (View == GoF2StationView.Hangar && flingVelocity != 0f)
            {
                shipYaw += flingVelocity * Time.deltaTime;
                flingVelocity *= Mathf.Pow(0.9f, dtMs / 20f);
                // Stops below 1 px per frame (1/120 rad per 20 ms).
                if (Mathf.Abs(flingVelocity) < 1f / GoF2StationTables.TurntablePixelsPerRadian / 0.02f) flingVelocity = 0f;
                ApplyShipYaw();
            }

            if (View == GoF2StationView.Lounge && midorianProp != null && (midorianTimer += dtMs) > 2000f)
            {
                midorianTimer = 0f;
                if (Random.value < 0.3f) midorianProp.Restart();
            }

            if (musicSource != null) musicSource.volume = GoF2Settings.MusicVolume;
            UpdateAmbienceAdds();
        }

        void LateUpdate()
        {
            UpdateCamera(Time.deltaTime * 1000f);
            if (View == GoF2StationView.Lounge) UpdateBillboards();
        }

        void UpdateCamera(float dtMs)
        {
            if (mainCamera == null) return;
            var cam = mainCamera.transform;
            if (View == GoF2StationView.Hangar)
            {
                // ModStation::OnUpdate: each axis eases to a new target on the other side of the base when within 5 units.
                var p = Vector3.zero;
                for (int i = 0; i < 3; i++)
                {
                    drift[i].Increase(dtMs);
                    if (Mathf.Abs(drift[i].Value - drift[i].Target) < 5f) NextDriftLeg(i, drift[i].Value);
                    p[i] = drift[i].Value;
                }
                var r = GoF2StationTables.HangarCameraRot[HangarIndex];
                cam.SetPositionAndRotation(shipPivot + GoF2OrbitLayout.ToUnity(p), CameraRotation(r.x, r.y, GoF2StationTables.HangarCameraRoll));
                SetLens(GoF2StationTables.HangarFov, GoF2StationTables.HangarNear, GoF2StationTables.HangarFar);
            }
            else
            {
                Vector3 pos;
                Quaternion rot;
                if (introT < 1.25f)
                {
                    // EaseInOutMatrix(A, B, 3000): t 0.75 -> 1.25, blend sin(2 pi t) * 0.5 + 0.5; Increase(min(dt, 50)).
                    introT = Mathf.Min(1.25f, introT + Mathf.Min(dtMs, 50f) * 0.5f / GoF2StationTables.BarIntroMs);
                    float b = Mathf.Sin(TwoPi * introT) * 0.5f + 0.5f;
                    pos = Vector3.Lerp(barPosA, barPosB, b);
                    rot = Quaternion.Slerp(barRotA, barRotB, b);
                }
                else
                {
                    // Sway: [RotY(v / 35), translation (0, bob, 0)] * B, v easing between -4..5 at speed 1..4.
                    swayYaw.Increase(dtMs * swaySpeed);
                    if (Mathf.Abs(swayYaw.Value - swayYaw.Target) < 0.25f)
                    {
                        swayYaw.Start(swayYaw.Value, 5 - Random.Range(0, 10));
                        swaySpeed = 1 + Random.Range(0, 4);
                    }
                    // Phase step 0.05..0.12 per 20 ms frame in the original (normalised); bob at most 3.5 units.
                    bobPhase += Mathf.Clamp(dtMs * 0.0025f, 0f, 0.12f);
                    var yaw = Quaternion.Euler(0f, -swayYaw.Value / 35f * Mathf.Rad2Deg, 0f);
                    pos = yaw * barPosB + new Vector3(0f, Mathf.Sin(bobPhase) * 3.5f * M, 0f);
                    rot = yaw * barRotB;
                }
                cam.SetPositionAndRotation(pos, rot);
                SetLens(GoF2StationTables.BarFov, GoF2StationTables.BarNear, GoF2StationTables.BarFar);
            }
        }

        float Base(int axis) => hangarCamBase[axis];

        void NextDriftLeg(int axis, float from)
        {
            driftSign[axis] = !driftSign[axis];
            int min = axis == 0 ? 18 : axis == 1 ? 30 : 50, range = axis == 0 ? 131 : axis == 1 ? 120 : 100;
            float offset = (min + Random.Range(0, range)) * (driftSign[axis] ? 1f : -1f);
            drift[axis].Start(from, Base(axis) + offset);
        }

        void SetLens(float fovRad, float near, float far)
        {
            mainCamera.fieldOfView = GoF2Aspect.VerticalFov(fovRad * Mathf.Rad2Deg, mainCamera.aspect);
            mainCamera.nearClipPlane = near * M;
            mainCamera.farClipPlane = far * M;
        }

        /// <summary>SpaceLounge::updateScreenPositions: visitors and glows face the camera (MatrixGetLookAt, local +Z toward
        /// the camera, with the camera's up); the glow sits 100 units behind; Terran bars turn visitors a further 180 deg.</summary>
        void UpdateBillboards()
        {
            var cam = mainCamera.transform;
            foreach (var v in visitors)
            {
                var toCam = cam.position - v.feet;
                if (toCam.sqrMagnitude < 1e-6f) continue;
                var look = Quaternion.LookRotation(toCam.normalized, cam.up);
                if (v.body != null) v.body.rotation = BarRace == 0 ? look * Quaternion.Euler(0f, 180f, 0f) : look;
                if (v.glow != null)
                {
                    var z = look * Vector3.forward;
                    v.glow.SetPositionAndRotation(v.feet - new Vector3(z.x, 0f, z.z) * (100f * M), look);
                }
            }
        }

        // ---- audio -------------------------------------------------------------------------------------------

        void PlayAmbience(AudioClip clip)
        {
            if (ambienceSource == null) return;
            ambienceSource.Stop();
            ambienceSource.clip = clip;
            ambienceSource.loop = true;
            ambienceSource.volume = GoF2Settings.SfxVolume;
            if (clip != null) ambienceSource.Play();
            nextAmbienceAdd = Time.time + Random.Range(ambienceAddInterval.x, ambienceAddInterval.y);
        }

        void UpdateAmbienceAdds()
        {
            if (ambienceAddSource == null || Time.time < nextAmbienceAdd) return;
            nextAmbienceAdd = Time.time + Random.Range(ambienceAddInterval.x, ambienceAddInterval.y);
            var adds = View == GoF2StationView.Hangar ? mainViewAdds : loungeAdds;
            if (adds == null || adds.Length == 0) return;
            var clip = adds[Random.Range(0, adds.Length)];
            if (clip != null) ambienceAddSource.PlayOneShot(clip, GoF2Settings.SfxVolume);
        }
    }
}
