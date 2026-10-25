// Es2DockTests.cs
// Feature: CLAUDE.md "Mods (remake-only)" > EVERSPACE 2 docking (World.Es2Dock, ModInteriors): a hangar room with "dock": "es2"
// docks EVERSPACE 2's way (its markers ship / ship_ahead / takeoff / takeoff_ahead / dock_zone, "rise", "dockZone"), its
// timelines read as UE's cubic curves; a roaming mobile station keeps to its "systems".
// Expected values: BP_DockableStation's CurveFloat exports (TransformAlpha 0 -> 1 over 4 s, BankingAlpha 1 from 1 s to 0 at
// 5 s, Align 0 -> 1 over 1.5 s, Launch 0 -> 1 from 0.75 to 3 s with an arrive tangent of 1.419) and UE's InterpEaseInOut.

using GoF2Remake.Data;
using GoF2Remake.Modding;
using GoF2Remake.World;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class Es2DockTests : SavesModsTest
    {
        [Test]
        public void TheTimelinesFollowTheirKeys()
        {
            Assert.AreEqual(0f, Es2DockCurves.Eval(Es2DockCurves.TransformAlpha, -1f));
            Assert.AreEqual(0f, Es2DockCurves.Eval(Es2DockCurves.TransformAlpha, 0f));
            Assert.AreEqual(1f, Es2DockCurves.Eval(Es2DockCurves.TransformAlpha, 4f), 1e-5f, "landed at 4 s");
            Assert.AreEqual(1f, Es2DockCurves.Eval(Es2DockCurves.TransformAlpha, 4.5f));
            float prev = 0f;
            for (float t = 0.1f; t < 4f; t += 0.1f)
            {
                float a = Es2DockCurves.Eval(Es2DockCurves.TransformAlpha, t);
                Assert.Greater(a, prev, "the glide never backs off");
                prev = a;
            }
            Assert.AreEqual(1f, Es2DockCurves.Eval(Es2DockCurves.BankingAlpha, 0.5f), "the wobble at full until 1 s");
            Assert.AreEqual(0f, Es2DockCurves.Eval(Es2DockCurves.BankingAlpha, 5f), 1e-5f);
            Assert.AreEqual(1f, Es2DockCurves.Eval(Es2DockCurves.Align, 1.5f), 1e-5f);
            Assert.AreEqual(0f, Es2DockCurves.Eval(Es2DockCurves.Launch, 0.75f));
            Assert.AreEqual(1f, Es2DockCurves.Eval(Es2DockCurves.Launch, 3f), 1e-5f);
            Assert.Less(Es2DockCurves.Eval(Es2DockCurves.Launch, 1.875f), 0.5f, "the launch accelerates (its last key's tangent)");
            Assert.AreEqual(1f, Es2DockCurves.Eval(Es2DockCurves.Banking, 1.5f), 1e-5f);
            Assert.AreEqual(0f, Es2DockCurves.Eval(Es2DockCurves.Banking, 3f), 1e-5f);
            Assert.AreEqual(0.5f, Es2DockCurves.EaseInOut(0.5f, 4f), 1e-6f);
            Assert.AreEqual(0.5f * UnityEngine.Mathf.Pow(0.5f, 4f), Es2DockCurves.EaseInOut(0.25f, 4f), 1e-6f);
        }

        [Test]
        public void AHangarDocksEs2sWay()
        {
            WriteMod("d", "t_dock", "1.0", "", ("interiors.json",
                "[ { 'id': 'pad', 'type': 'hangar', 'model': 'pad.glb', 'scale': 2.8, 'dock': 'es2', 'rise': 20, 'dockZone': [100, 50, 100], 'flights': false }, " +
                "  { 'id': 'plain', 'type': 'hangar', 'model': 'pad.glb' } ]"));
            ScanAndEnable("t_dock");
            var d = ModInteriors.Find("t_dock:pad", true);
            Assert.IsNotNull(d, AllMessages(Installed("t_dock")));
            Assert.IsTrue(d.es2Dock);
            Assert.AreEqual(20f, d.rise);
            Assert.AreEqual(new UnityEngine.Vector3(100f, 50f, 100f), d.dockZone);
            Assert.IsFalse(d.flights);
            var plain = ModInteriors.Find("t_dock:plain", true);
            Assert.IsFalse(plain.es2Dock);
            Assert.AreEqual(14f, plain.rise, "ES2's TakeOffHeight 500 cm x 2.8");
        }

        [Test]
        public void ADockIsEs2sOrAHangars()
        {
            WriteMod("d", "t_dockbad", "1.0", "", ("interiors.json",
                "[ { 'id': 'x', 'type': 'hangar', 'model': 'x.glb', 'dock': 'gof3' } ]"));
            ScanAndEnable("t_dockbad");
            ModInteriors.All();
            StringAssert.Contains("\"dock\" must be \"es2\"", AllMessages(Installed("t_dockbad")));
        }

        [Test]
        public void ARoamingStationKeepsToItsSystems()
        {
            WriteMod("m", "t_roam", "1.0", "", ("stations.json",
                "[ { 'id': 'mother', 'system': 14, 'name': 'Mother', 'techLevel': 9, 'mobile': { 'route': 'any', 'stayMinutes': 10, 'systemMinutes': 30, 'systems': [14, 2] } } ]"));
            ScanAndEnable("t_roam");
            var db = Database.Load();
            int mother = ModWorld.StationIndexOf("t_roam:mother");
            var spec = ModWorld.MobileOf(mother);
            Assert.IsTrue(spec.roam);
            foreach (var (sys, _) in spec.roamSystems) Assert.IsTrue(sys == 14 || sys == 2, "only its systems: " + sys);
            for (int stay = 0; stay < 40; stay++)
            {
                int host = MobileStations.HostAt(mother, stay * 600.0 + 1.0);
                int sys = db.Stations.Find(s => s.index == host).system;
                Assert.IsTrue(sys == 14 || sys == 2, "in system " + sys);
            }
        }
    }
}
