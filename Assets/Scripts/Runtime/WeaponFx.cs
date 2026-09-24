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
        [Tooltip("Bombs, mines, scatter shells, the shock blast: Explosion type (0 ship, 7 EMP, 8-10 scatter, 11 shock blast, 13 fireworks), -1 none.")]
        public int explosionType = -1;
        [Tooltip("Explosion::playSound by weapon (weapons_special.md 3.4).")]
        public AudioClip explosionSound;
        [Tooltip("The Liberator's engine loop (1116) while it is steered.")]
        public AudioClip engineLoop;
        [Tooltip("Turret items: the assembled *_ship_mounted prefab (pivot -> base + gun).")]
        public GameObject turretMounted;
        [Tooltip("Sentry guns: the deployed object (Assembled/supernova/turrets/sn_sentry_gun_00X).")]
        public GameObject sentry;

        public static WeaponFx Load(int item) => Resources.Load<WeaponFx>($"{ResourcesFolder}/item_{item:000}");
    }
}
