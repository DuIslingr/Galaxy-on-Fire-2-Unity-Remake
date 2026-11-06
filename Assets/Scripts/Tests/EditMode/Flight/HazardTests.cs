// HazardTests.cs
// Feature: Modding/README.md orbit "hazards", docs/notes/navigation.md "Hazard volumes": Flight.Hazards, after EVERSPACE 2's
// BP_HeatDamageVolume (200 dps x (1 - d / r)^2 each 0.25 s) and the radiated condition (the hull's maximum x 0.85 a token,
// at most 10, cleared by docking). Expected values: those sums by hand.

using GoF2Remake.Flight;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class HazardTests
    {
        [TearDown] public void Clear() => Hazards.ClearRadiation();

        [Test]
        public void HeatFallsOffWithTheSquareOfTheDistance()
        {
            Assert.AreEqual(50f, Hazards.HeatDamage(200f, 0f, 1000f), 1e-3f, "the centre: 200 a second over a quarter second");
            Assert.AreEqual(12.5f, Hazards.HeatDamage(200f, 500f, 1000f), 1e-3f, "halfway: a quarter of it");
            Assert.AreEqual(0f, Hazards.HeatDamage(200f, 1000f, 1000f), "the edge");
            Assert.AreEqual(0f, Hazards.HeatDamage(200f, 1500f, 1000f), "outside");
        }

        [Test]
        public void RadiationLowersTheHullsLimitUntilDocking()
        {
            Assert.AreEqual(1f, Hazards.RadiationFactor(0));
            Assert.IsTrue(Hazards.AddRadiation());
            Assert.AreEqual(0.85f, Hazards.RadiationFactor(Hazards.RadiationTokens), 1e-5f);
            for (int i = 0; i < 20; i++) Hazards.AddRadiation();
            Assert.AreEqual(Hazards.MaxRadiationTokens, Hazards.RadiationTokens, "at most 10");
            Assert.IsFalse(Hazards.AddRadiation());
            Assert.AreEqual(UnityEngine.Mathf.Pow(0.85f, 10), Hazards.RadiationFactor(Hazards.RadiationTokens), 1e-5f);
            Hazards.ClearRadiation();
            Assert.AreEqual(0, Hazards.RadiationTokens, "docked");
        }

        [Test]
        public void FrostBuildsForFiveSecondsAndDrainsOverSixty()
        {
            float b = Hazards.FrostStep(0f, 4000f, true, out bool frozen);
            Assert.IsFalse(frozen);
            Assert.AreEqual(4000f, b);
            b = Hazards.FrostStep(b, 12000f, false, out frozen);
            Assert.AreEqual(3000f, b, 1e-3f, "12 s outside drain a fifth of the 5 s (60 s for all)");
            b = Hazards.FrostStep(b, 2000f, true, out frozen);
            Assert.IsTrue(frozen, "5 s built: frozen");
            Assert.AreEqual(0f, b, "and it builds again");
            Assert.AreEqual(0f, Hazards.FrostStep(100f, 60000f, false, out frozen), "never below none");
        }

        [Test]
        public void TheHeatsBloomFollowsTheDepthInside()
        {
            var heat = new[] { new GoF2Remake.Modding.ModWorld.HazardSpec { kind = GoF2Remake.Modding.ModWorld.HazardKind.Heat, centre = UnityEngine.Vector3.zero, radius = 10000f } };
            float r = 10000f * 0.05f;   // 500 m
            Assert.AreEqual(1f, GoF2Remake.World.HazardLooks.HeatDepth(heat, UnityEngine.Vector3.zero), "the centre");
            Assert.AreEqual(1f, GoF2Remake.World.HazardLooks.HeatDepth(heat, new UnityEngine.Vector3(r * 0.85f, 0f, 0f)), 1e-4f, "85 % in");
            Assert.AreEqual(0.5f, GoF2Remake.World.HazardLooks.HeatDepth(heat, new UnityEngine.Vector3(r * 0.925f, 0f, 0f)), 1e-3f, "half way through the edge");
            Assert.AreEqual(0f, GoF2Remake.World.HazardLooks.HeatDepth(heat, new UnityEngine.Vector3(r * 1.2f, 0f, 0f)), "outside");
        }

        [Test]
        public void StormFlashesLieOnTheCylinder()
        {
            var o = GoF2Remake.World.OrbitStorm.FlashOffset(4000f, 4000f, 0.25f, 1f);
            Assert.AreEqual(4000f, new UnityEngine.Vector2(o.x, o.z).magnitude, 1e-2f, "on the cylinder's surface (ES2's VolumeSurfaceOnly)");
            Assert.AreEqual(2000f, o.y, 1e-3f, "at the top: half the height up");
            float total = 0f;
            UnityEngine.Random.InitState(7);
            for (int i = 0; i < 2000; i++) total += GoF2Remake.World.OrbitStorm.NextFlashMs(1f);
            Assert.AreEqual(1000f, total / 2000f, 100f, "a flash a second on average at frequency 1");
        }

        [Test]
        public void ShotTriggersUnlockOnceAllAreLit()
        {
            var c = new ShotTriggerChain(3, false, 0f);
            Assert.IsFalse(c.Hit(2));
            Assert.IsFalse(c.Hit(0));
            Assert.IsTrue(c.Hit(1), "any order: the last one unlocks it");
            Assert.IsTrue(c.Unlocked);
            Assert.IsFalse(c.Hit(1), "once only");
        }

        [Test]
        public void OrderedShotTriggersResetOnAWrongHit()
        {
            var c = new ShotTriggerChain(3, true, 0f);
            Assert.IsFalse(c.Hit(0));
            Assert.IsFalse(c.Hit(2), "the one before is dark");
            Assert.IsFalse(c.IsLit(0), "OnReset walks the chain back");
            c.Hit(0); c.Hit(1);
            Assert.IsTrue(c.Hit(2));
        }

        [Test]
        public void RetriggerableShotTriggersGoDarkAgain()
        {
            var c = new ShotTriggerChain(2, false, ShotTriggerChain.DefaultRetriggerS);
            c.Hit(0);
            c.Update(2999f);
            Assert.IsTrue(c.IsLit(0));
            c.Update(2f);
            Assert.IsFalse(c.IsLit(0), "BP_ShotTrigger's RegtriggerDelay 3 s");
            c.Hit(0); c.Update(1000f);
            Assert.IsTrue(c.Hit(1), "both lit within the 3 s");
            c.Update(10000f);
            Assert.IsTrue(c.IsLit(0), "unlocked for good");
        }

        [Test]
        public void ACloakedContainerShowsItselfOnlyUpClose()
        {
            Assert.AreEqual(2, GoF2Remake.World.CloakedContainers.Stage(100f), "within ES2's InteractRadius 40 m x 3.6: the marker comes on");
            Assert.AreEqual(1, GoF2Remake.World.CloakedContainers.Stage(1500f), "within the activity's 2 km: CONTAINER NEARBY");
            Assert.AreEqual(0, GoF2Remake.World.CloakedContainers.Stage(2500f));
            Assert.Less(GoF2Remake.World.CloakedContainers.RevealM, GoF2Remake.World.LootContainer.OpenRangeM, "revealed before it can be opened");
        }

        [Test]
        public void MinefieldsAreLaidOnlyWhereTheirSpecAllows()
        {
            var spec = new GoF2Remake.Modding.ModWorld.MinefieldSpec();   // defaults: security 1 or lower, rank 4 or more, half the visits
            Assert.IsTrue(GoF2Remake.World.OrbitMinefield.Laid(spec, 1, 4, 0.49f));
            Assert.IsFalse(GoF2Remake.World.OrbitMinefield.Laid(spec, 2, 4, 0f), "an average system");
            Assert.IsFalse(GoF2Remake.World.OrbitMinefield.Laid(spec, 0, 3, 0f), "a low rank");
            Assert.IsFalse(GoF2Remake.World.OrbitMinefield.Laid(spec, 0, 10, 0.5f), "the roll");
        }

        [Test]
        public void AMinesBlastFollowsEverspace2sBaseDamage()
        {
            var spec = new GoF2Remake.Modding.ModWorld.MinefieldSpec();
            Assert.AreEqual(120f / 55f, GoF2Remake.World.OrbitMinefield.RaiderSeconds(spec), 1e-5f, "BP_Minefield 60 + 60 over a raider's 55");
            spec.kind = GoF2Remake.Modding.ModWorld.MinefieldSpec.Kind.Web;
            Assert.AreEqual(15f / 55f, GoF2Remake.World.OrbitMinefield.RaiderSeconds(spec), 1e-5f, "_Web 10 + 5");
            spec.raiderSeconds = 3f;
            Assert.AreEqual(3f, GoF2Remake.World.OrbitMinefield.RaiderSeconds(spec), "the mod's own");
            Assert.AreEqual(RiftRun.MineBlastM * 1.5f, GoF2Remake.World.OrbitMine.BlastM(GoF2Remake.Modding.ModWorld.MinefieldSpec.Kind.Thermal), 1e-3f);
        }

        [Test]
        public void MinesLieInTheFieldSpreadOut()
        {
            var c = new UnityEngine.Vector3(10f, 20f, 30f);
            var list = GoF2Remake.World.OrbitMinefield.Places(c, 1000f, 20, 300f, new System.Random(3));
            Assert.AreEqual(20, list.Count);
            float closest = float.MaxValue;
            for (int i = 0; i < list.Count; i++)
            {
                Assert.LessOrEqual((list[i] - c).magnitude, 1000.01f, "inside the sphere");
                for (int j = 0; j < i; j++) closest = UnityEngine.Mathf.Min(closest, (list[i] - list[j]).magnitude);
            }
            Assert.Greater(closest, 100f, "kept apart (the best of a few tries each)");
        }

        [Test]
        public void TheFieldsTakeEverspace2sColours()
        {
            Assert.AreEqual(new UnityEngine.Color(0.84f, 1f, 0.09f), GoF2Remake.World.HazardLooks.KindColor(GoF2Remake.Modding.ModWorld.HazardKind.Corrosion), "P_CorrosionField's StartColor");
            Assert.AreEqual(new UnityEngine.Color(0.19f, 0.77f, 1f), GoF2Remake.World.HazardLooks.KindColor(GoF2Remake.Modding.ModWorld.HazardKind.Frost), "NS_FrostField's Initial.Color");
            Assert.AreEqual(new UnityEngine.Color(1f, 1f, 0.39f), GoF2Remake.World.HazardLooks.KindColor(GoF2Remake.Modding.ModWorld.HazardKind.Radiation), "RadiationColor");
        }
    }
}
