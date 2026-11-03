// NpcRoleTests.cs
// Feature: Modding/README.md "traffic" role, docs/notes/npcs-and-combat.md "Drone roles": Flight.NpcRoles, after EVERSPACE 2's
// drone types (EDroneType; the drone blueprints). Expected values: the role names a mod writes, which roles fire, ES2's
// detonator trigger (20 m) and blast (100 m) at the ES2 ships' x3.6, and the repair and blast sums by hand.

using GoF2Remake.Flight;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    public class NpcRoleTests
    {
        [Test]
        public void TheRoleNamesAModWrites()
        {
            Assert.AreEqual(NpcRoles.Role.Sniper, NpcRoles.Parse("sniper"));
            Assert.AreEqual(NpcRoles.Role.Detonator, NpcRoles.Parse("Detonator"));
            Assert.AreEqual(NpcRoles.Role.Webber, NpcRoles.Parse("webber"));
            Assert.AreEqual(NpcRoles.Role.ShieldCharger, NpcRoles.Parse("shieldCharger"));
            Assert.AreEqual(NpcRoles.Role.ArmorLink, NpcRoles.Parse("armourLink"), "either spelling");
            Assert.AreEqual(NpcRoles.Role.AntiMissile, NpcRoles.Parse("antiMissile"));
            Assert.AreEqual(NpcRoles.Role.JumpSuppressor, NpcRoles.Parse(" jumpSuppressor "));
            Assert.AreEqual(NpcRoles.Role.None, NpcRoles.Parse(null));
            Assert.AreEqual(NpcRoles.Role.None, NpcRoles.Parse("bomber"));
        }

        [Test]
        public void OnlyTheFightersOfTheRolesFire()
        {
            Assert.IsTrue(NpcRoles.Fires(NpcRoles.Role.None));
            Assert.IsTrue(NpcRoles.Fires(NpcRoles.Role.Sniper));
            Assert.IsTrue(NpcRoles.Fires(NpcRoles.Role.Webber));
            foreach (var r in new[] { NpcRoles.Role.Detonator, NpcRoles.Role.ShieldCharger, NpcRoles.Role.ArmorLink, NpcRoles.Role.AntiMissile, NpcRoles.Role.JumpSuppressor })
                Assert.IsFalse(NpcRoles.Fires(r), r.ToString());
        }

        [Test]
        public void TheDetonatorsReachAndBlast()
        {
            Assert.AreEqual(72f, NpcRoles.TriggerM, 1e-3f, "ES2's 20 m trigger x 3.6");
            Assert.AreEqual(360f, NpcRoles.BlastM, 1e-3f, "ES2's 100 m blast x 3.6");
            Assert.AreEqual(120f, NpcRoles.BlastDamage(12f), 1e-3f);
        }

        [Test]
        public void TheShieldChargerRepairsAShareOfTheHullASecond()
        {
            Assert.AreEqual(10f, NpcRoles.Repair(200, 1000f), 1e-3f, "5 % a second");
            Assert.AreEqual(2.5f, NpcRoles.Repair(200, 250f), 1e-3f);
        }
    }
}
