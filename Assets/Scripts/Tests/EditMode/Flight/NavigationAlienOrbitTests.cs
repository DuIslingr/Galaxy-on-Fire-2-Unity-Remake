// NavigationAlienOrbitTests.cs
// The action in the alien orbit (CLAUDE.md "Object docking"; a Discord report, "Can't dock with Valkyrie during Supernova
// Mission"): MGame::OnTouchBegin skips only the landmark block there, so a locked docking target still docks (154's
// Valkyrie, hacked against the 91 s limit) and a planet still jumps; the Void station gets no autopilot.

using GoF2Remake.Flight;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class NavigationAlienOrbitTests
    {
        [Test]
        public void ADockingTargetDocksInTheAlienOrbit() =>
            Assert.IsTrue(Navigation.ActsInAlienOrbit(Navigation.Kind.DockingTarget));

        [Test]
        public void APlanetJumpsInTheAlienOrbit() =>
            Assert.IsTrue(Navigation.ActsInAlienOrbit(Navigation.Kind.Planet));

        [Test]
        public void TheVoidStationGetsNoAutopilot() =>
            Assert.IsFalse(Navigation.ActsInAlienOrbit(Navigation.Kind.Station));
    }
}
