// OrbitLayout.cs
// Everything the original lays out for one station orbit (a flight level), computed exactly like the game does:
// the engine RNG is java.util.Random (JavaRandom), seeded with the station index, so the jumpgate spot, the
// sky rotation, the sun/planet layout and the asteroid field centre are the same on every visit.
// Plain C# (no scene objects); SpaceLevel turns it into a scene. All positions are GAME units.
//
// Sources (Reference/research/space_level_setup.md, space_backdrop.md, space_props.md):
//   Level::createSpace 0xbbba0      jumpgates (seed 2*station), sky rotation (seed 2*station, separate sequence)
//   StarSystem::StarSystem 0x15c200 sun + planets (seed 300*station), StarSystem::initLight 0x15d080 lights/fog
//   Level::createAsteroids 0xbcfd0  asteroid count + field centre (seed station)
//   Level::initParticleSystems 0xcc990 fog sprite tint

using System.Collections.Generic;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.World
{
    public class OrbitLayout
    {
        public class Planet
        {
            public int station;          // station whose planet this is
            public int slot;             // yaw = slot * 0xAAA / 65536 * 2pi
            public float pitch, yaw;     // radians, game convention (Rx(pitch) * Ry(yaw))
            public float scale;          // of the 65000-unit plane quad
            public bool flip;            // original's rotate(0, pi, 0): lit rim toward the sun
            public string texture;       // file name (no extension), Textures/<pack>/planets/
            public bool ring;            // draws sn_planet_ring at 4x behind/around it
            public bool isOrbitPlanet;   // the current station's own planet, straight ahead along game -Z
        }

        public int stationIndex, systemIndex;
        public int systemTexture, stationTexture;
        public int raceId;
        public bool hasStation;

        // Level::createSpace
        public bool hasJumpgate;
        public Vector3 jumpgate;         // landmark 1 (visible gate)
        public Vector3 hiddenJumpgate;   // landmark 2 (arrival point when travelling in)
        public int hiddenGateAngle;      // A2 (65536 per turn)
        public Vector3 skyEuler;         // radians, R_sky = Rx * Ry * Rz (game)
        public bool skySunAligned;       // system 27: the sky's +Y points at the sun

        // StarSystem
        public int sunSlot;
        public float sunPitch;
        public Vector3 lightDirection;   // unit vector toward the sun (game space)
        public string sunTexture;
        public float sunScale = 0.2288818359375f;   // 15000 / 65536
        public int flareColor;
        public readonly List<Planet> planets = new List<Planet>();

        // StarSystem::initLight
        public Color sunColor, planetLightColor;
        public bool fog;
        public Color fogColor;
        public float fogEnd;

        // Level::createAsteroids (stable part)
        public int asteroidCount;
        public Vector3 asteroidCentre;
        public int asteroidType;         // 0 default, 1 void, 2 ice (Beidan), 3 magma

        // Level::initParticleSystems
        public Color dustFogTint;

        public const float PlaneSize = 65000f;          // plane.fbx is +-32500 units
        public const float BackdropDistance = 20000f;   // moveForward(-20000)
        public const int GateRadius = 7500, GateRadiusVossk = 11250;
        public static readonly Vector3 UndockPosition = new Vector3(10f, 10f, 10000f);   // Level::init 0xbb7a8
        public const int UndockYaw = 1600;              // +-1600/65536 turn, random sign

        static readonly int[] RingStations = { 120, 126, 130, 132 };
        static readonly int[] EmptyOrbits = { 102, 103, 104, 109, 110, 132, 133, 134 };   // Status::inEmptyOrbit (mission-independent part)

        static readonly string[] SunTextures =
        {
            "sun_000", "sun_001", "sun_002", "sun_003", "sun_004", "sun_005", "sun_006", "sun_007", "sun_008", "sun_009",
            "sun_010", "sun_001", "sun_008", "sun_004", "sun_000", "sn_supernova", "sun_007", "sun_002", "sun_006",
        };

        static readonly int[] FlareColors = { 3, 1, 3, 2, 0, 3, 1, 4, 2, 4, 1, 3, 1, 3, 2, 3, 3, 0, 2, 1, 2, 3, 2, 0, 3, 1, 2, 5, 3, 3, 3, 3, 3, 3 };

        // DAT_00258b0c: sun colour per system textureIndex (LIGHT0 = clamp(15 * c, 0, 2), ambient 0.15 * c)
        static readonly float[] SunColors =
        {
            .21f, .32f, .25f,  .50f, .29f, .28f,  .24f, .40f, .37f,  .22f, .32f, .43f,  .18f, .23f, .27f,
            .38f, .13f, .11f,  .34f, .34f, .30f,  .24f, .26f, .25f,  .21f, .23f, .27f,  .43f, .47f, .47f,
            .43f, .21f, .34f,  .85f, .41f, .14f,  .08f, .24f, .48f,  .20f, .25f, .20f,  .30f, .35f, .15f,
            1.0f, .52f, .24f,  .39f, .48f, .44f,  .41f, .52f, .58f,  .67f, .63f, .46f,
        };

        // DAT_00258bf0: planet bounce light per station textureIndex (LIGHT1 = 1.5 * c)
        static readonly float[] PlanetLightColors =
        {
            .29f, .35f, .31f,  .25f, .22f, .14f,  .20f, .17f, .09f,  .30f, .27f, .31f,  .25f, .34f, .41f,
            .39f, .165f, .045f, .37f, .43f, .26f, .42f, .22f, .11f,  .18f, .25f, .28f,  .075f, .065f, .045f,
            .20f, .43f, .35f,  .27f, .09f, .04f,  .38f, .29f, .16f,  .06f, .05f, .03f,  .11f, .10f, .11f,
            .25f, .23f, .20f,  .25f, .19f, .135f, .17f, .35f, .48f,  .07f, .07f, .07f,  .26f, .29f, .31f,
            .13f, .10f, .06f,  .31f, .31f, .21f,  .39f, .32f, .25f,  .64f, .50f, .67f,  .45f, .38f, .34f,
            .48f, .52f, .58f,  .21f, .27f, .34f,
        };

        // DAT_00252ca0: fog sprite colour per system textureIndex (x 0.6, alpha 0xbb)
        static readonly byte[] DustFogTints =
        {
            0, 160, 32,  140, 20, 2,  0, 109, 123,  44, 155, 216,  122, 122, 122,  206, 90, 70,  105, 160, 125,
            167, 160, 126,  126, 181, 159,  206, 222, 225,  146, 116, 212,  219, 105, 35,  255, 255, 255,
            154, 228, 255,  174, 183, 125,  219, 105, 35,  71, 102, 94,  115, 141, 149,  171, 160, 117,
        };

        static readonly string[] JumpgateByRace = { "jumpgate_terran", "jumpgate_vossk_anim", "jumpgate_nivelian", "jumpgate_midorian" };

        public string JumpgateAssembly => JumpgateByRace[raceId >= 0 && raceId < 4 ? raceId : 0];
        public int JumpgateRadius => raceId == 1 ? GateRadiusVossk : GateRadius;

        static float Angle(int v) => v * 1.52587890625e-05f * 6.2831855f;   // 65536 per turn

        /// <summary>Local +Z of Rx(pitch) * Ry(yaw): the direction StarSystem places a body along (at -20000 * dir).</summary>
        public static Vector3 Direction(float pitch, float yaw) =>
            new Vector3(Mathf.Sin(yaw), -Mathf.Sin(pitch) * Mathf.Cos(yaw), Mathf.Cos(pitch) * Mathf.Cos(yaw));

        public static OrbitLayout Build(Database db, int stationIndex)
        {
            var st = db.Stations.Find(s => s.index == stationIndex);
            var sys = st != null ? db.Systems.Find(s => s.index == st.system) : null;
            var o = new OrbitLayout
            {
                stationIndex = stationIndex,
                systemIndex = sys != null ? sys.index : -1,
                systemTexture = sys != null ? sys.textureIndex : 10,
                stationTexture = st != null ? st.textureIndex : 23,
                raceId = sys != null ? sys.raceId : 0,
                hasStation = st != null && System.Array.IndexOf(EmptyOrbits, stationIndex) < 0,
            };
            o.BuildGates(sys);
            o.BuildSky();
            o.BuildStarSystem(db, sys);
            o.BuildLights();
            o.BuildAsteroidField();
            return o;
        }

        // Level::createSpace: landmark 1 only in the gate orbit, landmark 2 (hidden) always.
        void BuildGates(SystemData sys)
        {
            hasJumpgate = sys != null && sys.jumpgateStation == stationIndex;
            var rnd = new JavaRandom(2L * stationIndex);
            int a = 0;
            for (int i = hasJumpgate ? 1 : 2; i <= 2; i++)
            {
                int s = rnd.NextInt(2), k = rnd.NextInt(500);
                a += (s == 0 ? -(250 + k) : 250 + k) * 16;
                float r = (i == 1 ? 90000f : 120000f) + 3f * a;
                float ang = a / 65536f * 2f * Mathf.PI;
                var pos = new Vector3(r * Mathf.Sin(ang), 0f, r * Mathf.Cos(ang));
                if (i == 1) jumpgate = pos; else { hiddenJumpgate = pos; hiddenGateAngle = a; }
            }
        }

        // Level::createSpace: R_sky = Rx * Ry * Rz from 3 draws (seed 2*station); none in the fog skies (17, 18).
        void BuildSky()
        {
            if (systemTexture == 17 || systemTexture == 18) { skyEuler = Vector3.zero; return; }
            var rnd = new JavaRandom(2L * stationIndex);
            skyEuler = new Vector3(Angle(rnd.NextInt(65536)), Angle(rnd.NextInt(65536)), Angle(rnd.NextInt(65536)));
            skySunAligned = systemIndex == 27;
        }

        // StarSystem::StarSystem: sun at index 0, then one planet per station of the system (seed 300*station).
        void BuildStarSystem(Database db, SystemData sys)
        {
            sunTexture = SunTextures[Mathf.Clamp(systemTexture, 0, SunTextures.Length - 1)];
            flareColor = systemIndex >= 0 && systemIndex < FlareColors.Length ? FlareColors[systemIndex] : 3;
            var rnd = new JavaRandom(300L * stationIndex);
            var occupied = new bool[24];

            int r = rnd.NextInt(14);
            int k = stationTexture - 9;
            if (k >= 0 && k < 13 && ((0x1a31 >> k) & 1) != 0) sunSlot = k == 12 ? 4 : 6;
            else sunSlot = stationTexture == 22 ? 16 : r + 5;
            occupied[sunSlot] = true;
            sunPitch = Angle(rnd.NextInt(4096) - 2048);
            lightDirection = -Direction(sunPitch, Angle(sunSlot * 0xAAA));

            if (sys == null) return;
            bool ringOrbit = System.Array.IndexOf(RingStations, stationIndex) >= 0;
            foreach (int stIdx in sys.stations)
            {
                var st = db.Stations.Find(s => s.index == stIdx);
                int t = st != null ? st.textureIndex : 0;
                var p = new Planet { station = stIdx, ring = System.Array.IndexOf(RingStations, stIdx) >= 0 };
                if (stIdx == stationIndex)
                {
                    int s = rnd.NextInt(20000) + 20000;
                    if (!ringOrbit)
                    {
                        if (t < 18 && ((1 << t) & 0x21840) != 0) s = rnd.NextInt(15000) + 35000;
                        else if (t < 18 && ((1 << t) & 0x10200) != 0) s = rnd.NextInt(13000) + 32500;
                    }
                    else s = 26000;
                    occupied[0] = true;
                    p.isOrbitPlanet = true;
                    p.scale = s / 65536f;
                    p.flip = sunSlot >= 12;
                    p.texture = PlanetTexture(t, true);
                    p.ring = false;   // the ring orbit shows the ring sky layer instead
                }
                else
                {
                    int slot;
                    do slot = rnd.NextInt(11) + 7;
                    while (Mathf.Abs(slot - sunSlot) < 3 || occupied[slot]);
                    occupied[slot] = true;
                    p.slot = slot;
                    p.scale = (float)((rnd.NextInt(40) * 0.01 + 0.800000011920929) * 0.03509521484375);
                    p.flip = slot > sunSlot;
                    p.pitch = Angle(rnd.NextInt(4096) - 2048);
                    p.yaw = Angle(slot * 0xAAA);
                    p.texture = PlanetTexture(t, false);
                }
                planets.Add(p);
            }
        }

        static string PlanetTexture(int t, bool big)
        {
            string size = big ? "big" : "small";
            if (t < 20) return $"planet_{t:000}_{size}";
            if (t < 23) return $"v_planet_{t:000}_{size}";
            if (t == 23) return big ? "planet_void_big" : "v_planet_022_small";
            return $"sn_planet_{t:000}_{size}";
        }

        // StarSystem::initLight
        void BuildLights()
        {
            int s = Mathf.Clamp(systemTexture, 0, 18) * 3;
            sunColor = new Color(SunColors[s], SunColors[s + 1], SunColors[s + 2]);
            int p = Mathf.Clamp(stationTexture, 0, 26) * 3;
            planetLightColor = new Color(PlanetLightColors[p], PlanetLightColors[p + 1], PlanetLightColors[p + 2]) * 1.5f;
            dustFogTint = new Color32((byte)(DustFogTints[s] * 0.6f), (byte)(DustFogTints[s + 1] * 0.6f), (byte)(DustFogTints[s + 2] * 0.6f), 0xbb);
            switch (systemTexture)
            {
                case 11: fog = true; fogColor = new Color32(0xdb, 0x69, 0x23, 255); fogEnd = 50000f; break;
                case 12: fog = true; fogColor = new Color32(0x16, 0x3e, 0x7c, 255); fogEnd = 50000f; break;
                case 15: fog = true; fogColor = new Color32(0x82, 0x44, 0x1f, 255); fogEnd = 100000f; break;
                case 16: fog = true; fogColor = new Color32(0x47, 0x66, 0x5e, 255); fogEnd = 150000f; break;
                case 17: fog = true; fogColor = new Color32(0x73, 0x8d, 0x95, 255); fogEnd = 150000f; break;
                case 18: fog = true; fogColor = new Color32(0xab, 0xa0, 0x75, 255); fogEnd = 150000f; break;
            }
        }

        /// <summary>LIGHT0 diffuse: clamp(15 * sunColour, 0, 2) per channel (white x2 for most systems).</summary>
        public Color SunLightColor => new Color(Mathf.Min(sunColor.r * 15f, 2f), Mathf.Min(sunColor.g * 15f, 2f), Mathf.Min(sunColor.b * 15f, 2f));

        // Level::createAsteroids: count and centre are seeded (stable), the asteroids themselves are not.
        void BuildAsteroidField()
        {
            var rnd = new JavaRandom(stationIndex);
            asteroidCount = rnd.NextInt(40) + 40;
            int cx = rnd.NextInt(100000) - 50000, cy = rnd.NextInt(100000) - 50000, cz = rnd.NextInt(100000) + 20000;
            asteroidCentre = new Vector3(cx, cy, cz);
            asteroidType = systemIndex == 22 ? 2 : 0;
        }

        public string AsteroidAssembly => asteroidType switch { 1 => "asteroid_void", 2 => "v_asteroid_ice", 3 => "sn_asteroid_magma", _ => "asteroid_01" };

        /// <summary>Asteroid mesh bounding radius in game units (sidecar bsphere): hit radius = this * scale * 0.7.</summary>
        public float AsteroidMeshRadius => asteroidType switch { 1 => 6064f, 2 => 2835f, _ => 3547f };

        // ---- game -> Unity ---------------------------------------------------------------------------------------

        public const float MetersPerUnit = 0.05f;

        /// <summary>Game position to Unity: (x, y, -z) * 0.05.</summary>
        public static Vector3 ToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z) * MetersPerUnit;

        /// <summary>Game direction to Unity (unscaled).</summary>
        public static Vector3 DirToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z);

        /// <summary>
        /// Game rotation (AEGeometry::setRotation(x, y, z) = Rx * Ry * Rz, radians) to a Unity rotation for an imported
        /// model. The z mirror turns it into S*R*S = Rx(-x) Ry(-y) Rz(z), and the import rotates every FBX 180 deg about
        /// Y (ModelOrientationPostprocessor), which is undone at the end. Game (0, pi, 0) (stations, gates) = identity.
        /// </summary>
        public static Quaternion RotationToUnity(Vector3 gameEulerRadians) =>
            Quaternion.AngleAxis(-gameEulerRadians.x * Mathf.Rad2Deg, Vector3.right)
            * Quaternion.AngleAxis(-gameEulerRadians.y * Mathf.Rad2Deg, Vector3.up)
            * Quaternion.AngleAxis(gameEulerRadians.z * Mathf.Rad2Deg, Vector3.forward)
            * Quaternion.Euler(0f, 180f, 0f);
    }
}
