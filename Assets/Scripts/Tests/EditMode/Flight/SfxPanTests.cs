// SfxPanTests.cs
// The stereo pan of world sounds (Flight.Sfx.PanLocal, the rule behind Sfx.Pan): a sound's side of the camera, never fully
// one-sided, centred ahead, behind and at the camera.

using GoF2Remake.Flight;
using NUnit.Framework;
using UnityEngine;

namespace GoF2Remake.Tests
{
    public class SfxPanTests
    {
        [Test]
        public void FullyToOneSideIsPannedByPanAmount()
        {
            Assert.That(Sfx.PanLocal(new Vector3(500f, 0f, 0f)), Is.EqualTo(Sfx.PanAmount).Within(1e-5f));
            Assert.That(Sfx.PanLocal(new Vector3(-500f, 0f, 0f)), Is.EqualTo(-Sfx.PanAmount).Within(1e-5f));
            Assert.That(Sfx.PanAmount, Is.LessThan(1f), "never fully one-sided");
        }

        [Test]
        public void AheadBehindAndAboveAreCentred()
        {
            Assert.That(Sfx.PanLocal(new Vector3(0f, 0f, 800f)), Is.EqualTo(0f).Within(1e-5f));
            Assert.That(Sfx.PanLocal(new Vector3(0f, 0f, -800f)), Is.EqualTo(0f).Within(1e-5f));
            Assert.That(Sfx.PanLocal(new Vector3(0f, 300f, 0f)), Is.EqualTo(0f).Within(1e-5f));
        }

        [Test]
        public void AtTheCameraIsCentred()
        {
            Assert.That(Sfx.PanLocal(Vector3.zero), Is.EqualTo(0f));
            Assert.That(Sfx.PanLocal(new Vector3(0.5f, 0f, 0f)), Is.EqualTo(0f), "under a metre away: no side");
        }

        [Test]
        public void PanFollowsTheSideOfTheDirectionNotTheDistance()
        {
            // 45 degrees to the right: sin 45 of the full pan, near or far.
            float near = Sfx.PanLocal(new Vector3(10f, 0f, 10f)), far = Sfx.PanLocal(new Vector3(1000f, 0f, 1000f));
            Assert.That(near, Is.EqualTo(Sfx.PanAmount * Mathf.Sqrt(0.5f)).Within(1e-4f));
            Assert.That(far, Is.EqualTo(near).Within(1e-5f));
            Assert.That(Sfx.PanLocal(new Vector3(-10f, 0f, 10f)), Is.EqualTo(-near).Within(1e-5f));
        }
    }
}
