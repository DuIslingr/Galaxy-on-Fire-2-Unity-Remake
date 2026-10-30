// SlipstreamDriveModTests.cs
// Feature: the example mod Modding/Examples/slipstream_drive (Modding/README.md "Cruise drives"): its two items load as
// cruise drives made from the Khador Drive (its look, its category 18, their own numbers after the originals), with the
// numbers of their stats, and a mounted one sits beside a Khador Drive (Shop.FirstMounted(18) stays the Khador Drive,
// Shop.MountedCruiseDrive finds the Slipstream; Hangar: no swap between the two kinds).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Modding;
using NUnit.Framework;

namespace GoF2Remake.Tests
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class SlipstreamDriveModTests : SavesModsTest
    {
        const string Mod = "slipstream_drive";
        List<ItemStack> savedEquipment;

        [SetUp]
        public void Prepare() { savedEquipment = Session.Equipment; Session.Equipment = new List<ItemStack>(); }

        [TearDown]
        public void Restore() { Session.Equipment = savedEquipment; }

        Database ModOn()
        {
            CopyExample(Mod);
            ScanAndEnable(Mod);
            Assert.IsFalse(Installed(Mod).Broken, AllMessages(Installed(Mod)));
            Assert.IsEmpty(Installed(Mod).Warnings, AllMessages(Installed(Mod)));
            return Database.Load();
        }

        [Test]
        public void TheExampleItemsAreCruiseDrives()
        {
            var db = ModOn();
            int i = ModContent.ItemIndexOf(Mod + ":slipstream"), ii = ModContent.ItemIndexOf(Mod + ":slipstream_ii");
            Assert.GreaterOrEqual(i, OriginalItems);
            Assert.GreaterOrEqual(ii, OriginalItems);
            var it = db.Item(i);
            Assert.IsNotNull(it);
            Assert.AreEqual("Khador Slipstream", it.name);
            Assert.AreEqual("equipment", it.type);
            Assert.AreEqual(18, it.categoryId, "the Khador Drive's category");
            Assert.AreEqual(85, it.Look, "the Khador Drive's icon");
            Assert.IsTrue(Shop.IsCruiseDrive(it));
            Assert.AreEqual(CruiseDrive.Kind, Shop.KindOf(it));
            Assert.AreEqual(400, it.Attr(CruiseDrive.SpeedAttr));
            Assert.AreEqual(60000, it.Attr(CruiseDrive.RangeAttr));
            Assert.AreEqual(2000, it.Attr(CruiseDrive.ChargeAttr));
            Assert.AreEqual(1, it.Attr(CruiseDrive.CellsAttr));
            Assert.AreEqual(7, it.techLevel);
            Assert.AreEqual(25, it.occurrence);
            Assert.AreEqual(148000, it.minPrice);
            Assert.AreEqual(162800, it.maxPrice);
            var two = db.Item(ii);
            Assert.AreEqual(600, two.Attr(CruiseDrive.SpeedAttr));
            Assert.AreEqual(90000, two.Attr(CruiseDrive.RangeAttr));
            Assert.AreEqual(1500, two.Attr(CruiseDrive.ChargeAttr));
            Assert.AreEqual(9, two.techLevel);
        }

        [Test]
        public void AMountedDriveSitsBesideTheKhadorDrive()
        {
            var db = ModOn();
            int i = ModContent.ItemIndexOf(Mod + ":slipstream");
            Session.Equipment = new List<ItemStack> { new ItemStack(GalaxyMap.KhadorDriveItem, 1), new ItemStack(i, 1) };
            Assert.AreEqual(GalaxyMap.KhadorDriveItem, Shop.FirstMounted(db, 18).index, "the jump drive's kind is the Khador Drive's");
            Assert.AreEqual(i, Shop.MountedCruiseDrive(db).index);
            Assert.IsTrue(GalaxyMap.HasJumpDrive(db));
            Session.Equipment = new List<ItemStack> { new ItemStack(i, 1) };
            Assert.IsNull(Shop.FirstMounted(db, 18), "a cruise drive is no jump drive");
            Assert.IsFalse(Session.Equipment.Exists(e => e.item == GalaxyMap.KhadorDriveItem), "Ship::hasJumpDrive asks for the item itself");
            Assert.IsFalse(Hangar.InBuiltInPlace(db, new ItemStack(i, 1)));
        }

        [Test]
        public void TheRulesComeFromTheItem()
        {
            var db = ModOn();
            var it = Shop.MountedCruiseDrive(db);
            Assert.IsNull(it, "nothing mounted");
            int i = ModContent.ItemIndexOf(Mod + ":slipstream_ii");
            Session.Equipment = new List<ItemStack> { new ItemStack(i, 1) };
            it = Shop.MountedCruiseDrive(db);
            var d = new CruiseDrive(it.index, it.Attr(CruiseDrive.SpeedAttr), it.Attr(CruiseDrive.RangeAttr, 60000),
                                    it.Attr(CruiseDrive.ChargeAttr, 2000), it.Attr(CruiseDrive.CellsAttr, 1), Session.IsExtreme);
            Assert.AreEqual(6f, d.speedFactor);
            Assert.AreEqual(90000, d.legUnits);
            Assert.AreEqual(1500, d.chargeMs);
            Assert.AreEqual(1, d.cellsPerLeg);
        }
    }
}
