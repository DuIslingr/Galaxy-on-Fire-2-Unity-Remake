// ModDeathFxTests.cs
// Feature: docs/notes/mods-models.md "Death effects": ships.json "deathFx" names a JSON file (CustomFxFile) of particle
// emitters; World.ModDeathFx builds each as a Unity particle system (bursts, life, size, speed, drag, a flipbook, the fade).

using GoF2Remake.Data;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class ModDeathFxTests
    {
        const string File = "{ \"main\": { \"emitters\": [ { \"image\": \"fx/fireball.png\", \"sheet\": [16, 8], \"frames\": [0, 0.6, 1], " +
            "\"bursts\": [0, 1, 0.05, 1, 0.1, 1], \"duration\": 4, \"life\": [4, 4], \"size\": [1980, 1980], \"sizeOverLife\": [0.39, 1.1, 1.35], " +
            "\"speed\": [1150, 1420], \"forward\": true, \"sphere\": 900, \"drag\": 2, \"color\": [8, 4, 4], \"colorOverLife\": [1, 1, 1, 0, 0, 0], " +
            "\"alphaOverLife\": [1, 0] }, { \"image\": \"fx/spark.png\", \"bursts\": [0, 500], \"life\": [0.1, 1], \"size\": [22, 36], " +
            "\"speed\": [1800, 18000], \"stretch\": 4, \"color\": [7, 0.7, 0.7] } ] }, " +
            "\"dying\": { \"emitters\": [ { \"image\": \"fx/fireball.png\", \"bursts\": [0, 1], \"life\": [2, 2], \"size\": [900, 900] } ] }, \"dyingCount\": [3, 12] }";

        [Test]
        public void TheFileIsRead()
        {
            var f = JsonUtility.FromJson<CustomFxFile>(File);
            Assert.AreEqual(2, f.main.emitters.Length);
            Assert.AreEqual(new[] { 16, 8 }, f.main.emitters[0].sheet);
            Assert.IsTrue(f.main.emitters[0].forward);
            Assert.AreEqual(4f, f.main.emitters[1].stretch);
            Assert.AreEqual(1f, f.main.emitters[1].inherit, "the ship's motion by default");
            Assert.AreEqual(new[] { 3, 12 }, f.dyingCount);
            Assert.IsNull(JsonUtility.FromJson<CustomShipData>("{ \"id\": \"x\" }").deathFx, "none: the game's explosion");
        }

        [Test]
        public void AnEmitterBecomesAParticleSystem()
        {
            var f = JsonUtility.FromJson<CustomFxFile>(File);
            var root = new GameObject("fx");
            try
            {
                var fire = GoF2Remake.World.ModDeathFx.Build(null, f.main.emitters[0], root.transform, new Vector3(0f, 0f, 10f), 1f, out float lasts);
                Assert.AreEqual(3, fire.emission.burstCount);
                Assert.AreEqual(8f, lasts, 1e-4f, "its duration and the longest life");
                Assert.AreEqual(1980f * 0.05f, fire.main.startSize.constantMax, 1e-3f);
                Assert.AreEqual(ParticleSystemShapeType.Cone, fire.shape.shapeType, "along the effect's forward");
                Assert.IsTrue(fire.limitVelocityOverLifetime.enabled);
                Assert.AreEqual(16, fire.textureSheetAnimation.numTilesX);
                Assert.AreEqual(new Vector3(0f, 0f, 10f), fire.main.emitterVelocity, "the ship's motion");
                var sparks = GoF2Remake.World.ModDeathFx.Build(null, f.main.emitters[1], root.transform, Vector3.zero, 1f, out _);
                Assert.AreEqual(ParticleSystemRenderMode.Stretch, sparks.GetComponent<ParticleSystemRenderer>().renderMode);
                Assert.AreEqual(ParticleSystemShapeType.Sphere, sparks.shape.shapeType, "outward");
                Assert.GreaterOrEqual(sparks.main.maxParticles, 500);
            }
            finally { Object.DestroyImmediate(root); }
        }
    }
}
