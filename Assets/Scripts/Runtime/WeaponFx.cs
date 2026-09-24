// WeaponFx.cs
// Visuals and sound of one weapon item, from the original's per-item tables (weapons.md section 4:
// projectile DAT_00252d1c, muzzle flash DAT_00259ab8, impact DAT_00259220, shot sound DAT_00252310).
// One asset per item in Resources/GoF2Weapons/item_XXX (made by GoF2 > Build Weapon Fx from
// Resources/GoF2Data/weapon_fx.json), loaded only for the equipped weapons.

using UnityEngine;

namespace GoF2Remake.Flight
{
    public class WeaponFx : ScriptableObject
    {
        public const string ResourcesFolder = "GoF2Weapons";

        public int item;
        public GameObject projectile;
        public GameObject muzzleFlash;
        public GameObject impact;
        public AudioClip shot;
        [Tooltip("Auto-cannons, thermo guns and turrets loop their sound while firing (Player::playShootSound).")]
        public bool shotLoops;

        public static WeaponFx Load(int item) => Resources.Load<WeaponFx>($"{ResourcesFolder}/item_{item:000}");
    }
}
