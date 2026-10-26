// Regression: ES2's station menu loads additively over its orbit. A flight model spawned before the station unloads must
// retain boost effects; only models under the hangar/lounge visual roots use station engine limits and previews.

using System;
using System.Reflection;
using GoF2Remake.Flight;
using GoF2Remake.Modding;
using GoF2Remake.Visuals;
using NUnit.Framework;
using UnityEngine;
using Object = UnityEngine.Object;

namespace GoF2Remake.Tests
{
    public class EngineStationContextTests : SandboxTest
    {
        const BindingFlags Private = BindingFlags.Instance | BindingFlags.NonPublic;

        static bool StationFlag(GameObject model, Type effect)
        {
            var component = model.AddComponent(effect);
            effect.GetMethod("OnEnable", Private).Invoke(component, null);
            return (bool)effect.GetField("inStation", Private).GetValue(component);
        }

        [TestCase(typeof(EngineFlame))]
        [TestCase(typeof(Es2EngineVfx))]
        [TestCase(typeof(LateralThrusters))]
        [TestCase(typeof(EngineFx))]
        [TestCase(typeof(ThrottleGlow))]
        public void FlightEffectsIgnoreAnUnrelatedHangar(Type effect)
        {
            var hangar = new GameObject("Additive hangar");
            var flightModel = new GameObject("Flight model spawned during launch");
            try
            {
                hangar.AddComponent<StationModelContext>();
                Assert.IsFalse(StationFlag(flightModel, effect), "the loaded hangar does not own this flight model");
            }
            finally { Object.DestroyImmediate(flightModel); Object.DestroyImmediate(hangar); }
        }

        [TestCase(typeof(EngineFlame))]
        [TestCase(typeof(Es2EngineVfx))]
        [TestCase(typeof(LateralThrusters))]
        [TestCase(typeof(EngineFx))]
        [TestCase(typeof(ThrottleGlow))]
        public void HangarEffectsFollowTheirVisualRootIntoTheOrbit(Type effect)
        {
            var orbit = new GameObject("Live orbit station hull");
            var hangar = new GameObject("Hangar");
            var model = new GameObject("Hangar ship");
            try
            {
                hangar.AddComponent<StationModelContext>();
                hangar.transform.SetParent(orbit.transform, false);
                model.transform.SetParent(hangar.transform, false);
                Assert.IsTrue(StationFlag(model, effect), "the ship remains a hangar model under the orbit's hull");
                Assert.IsFalse(EngineDrive.IsStationModel(orbit.transform), "the station hull and its traffic are outside the hangar context");
            }
            finally { Object.DestroyImmediate(model); Object.DestroyImmediate(hangar); Object.DestroyImmediate(orbit); }
        }

        [Test]
        public void AFlightFlameRetainsItsPilotAndBoostInputs()
        {
            var hangar = new GameObject("Additive hangar");
            var player = new GameObject("Player");
            try
            {
                hangar.AddComponent<StationModelContext>();
                var controller = player.AddComponent<ShipController>();
                controller.externalControl = true;
                controller.Model.SetThrottle(1f);
                var model = new GameObject("Flight model");
                model.transform.SetParent(player.transform, false);
                var flame = model.AddComponent<EngineFlame>();
                typeof(EngineFlame).GetMethod("OnEnable", Private).Invoke(flame, null);
                typeof(EngineFlame).GetMethod("Setup", Private).Invoke(flame, null);
                typeof(EngineFlame).GetMethod("UpdateInputs", Private).Invoke(flame, new object[] { 1f, 2f });
                Assert.IsFalse(flame.InStation);
                Assert.IsTrue(flame.Pilot);
                Assert.IsTrue(flame.Boosting);
                Assert.AreEqual(1f, flame.Boost, 1e-4f);
                Assert.AreEqual(1f, flame.Thrust.z, 1e-4f);
            }
            finally { Object.DestroyImmediate(player); Object.DestroyImmediate(hangar); }
        }

        [Test]
        public void TheHangarCanStillPreviewBoostEffects()
        {
            var hangar = new GameObject("Hangar");
            try
            {
                hangar.AddComponent<StationModelContext>();
                var model = new GameObject("Preview model");
                model.transform.SetParent(hangar.transform, false);
                model.AddComponent<EnginePreview>().drive = 2f;
                var flame = model.AddComponent<EngineFlame>();
                typeof(EngineFlame).GetMethod("OnEnable", Private).Invoke(flame, null);
                typeof(EngineFlame).GetMethod("LateUpdate", Private).Invoke(flame, null);
                Assert.IsTrue(flame.InStation);
                Assert.IsFalse(flame.Pilot);
                Assert.AreEqual(1f, flame.Boost);
            }
            finally { Object.DestroyImmediate(hangar); }
        }
    }
}
