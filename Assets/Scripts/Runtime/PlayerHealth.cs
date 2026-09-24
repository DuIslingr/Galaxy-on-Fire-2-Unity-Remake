// PlayerHealth.cs
// The player ship's Player object (Reference/research/ship_combat.md 2, 6), on the player next to ShipController:
//   Level::createPlayer 0xbca00     hull = ships.json armor, shield = attr 18 of the mounted shield (sort 9), armor = attr
//                                   20 of the mounted armor (sort 10); hit cube half-size 1200; no EMP points (immune)
//   PlayerEgo::update               shield regen (>= 101 ms ticks, + max * 100 / attr 19, no delay after hits), repair bot
//                                   (Ketar 600 / 1000 ms, Ketar II 420 / 700 ms); invulnerable during the launch / arrival
//                                   camera and the jump scenes (LevelScript, startJumpScene)
//                                   hit feedback when shield + armor + hull dropped: camera shake 1000 ms (+-6 units),
//                                   sound 25 / 23 / 24 by the layer hit, the shield icon turns red for 500 ms (while
//                                   shield >= 2), a directional arc (left / right / top / bottom) for 300 ms
//   PlayerEgo::calcCollision 0xab550  collisions: PlayerCollision (asteroids cost 20, stations / ships none)
//   MGame::gameOverCheck / PlayerEgo::explode  hull < 1: the camera freezes, the ship tumbles, explodes at 3 s, "Game Over"
//                                   and sound 37 at 8 s; then FlightHud offers "Tap to load last savegame." (196)
// Hull / shield / armor are kept in Session between levels (-1 = full; docking repairs, see StationLevel).
// Not yet: the emergency system (item 185), EMP immunity is implicit (no points), volatile cargo.

using System;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class PlayerHealth : MonoBehaviour
    {
        const float M = 0.05f;
        public const float HitRadiusUnits = 1200f;

        public Target Target { get; private set; }
        public Hitpoints Hp => Target.hitpoints;
        public bool HasShield { get; private set; }
        public bool HasArmor { get; private set; }
        /// <summary>ms left of the red shield icon (Hud::playerHit).</summary>
        public float ShieldHitMs { get; private set; }
        /// <summary>ms left per hit arc: 0 left, 1 right, 2 top, 3 bottom (Hud::draw, 300 ms).</summary>
        public readonly float[] ArcMs = new float[4];
        public bool Dead { get; private set; }
        public bool GameOver { get; private set; }
        /// <summary>Set by the level each frame: the launch camera / jump scenes (Player::setVulnerable(false)).</summary>
        [NonSerialized] public bool invulnerable;
        public event Action GameOverStarted;

        ShipController ship;
        ChaseCamera chase;
        WeaponSystem weapons;
        CombatAssets assets;
        AudioSource sfx;
        int shieldRechargeMs;
        float repairHullMs, repairArmorMs;
        bool hasRepair, exploded;
        float lastCombined, deathMs;
        Vector3 deathSpin;

        public void Setup(Database db, ShipController controller, ChaseCamera chaseCamera, WeaponSystem weaponSystem)
        {
            ship = controller;
            chase = chaseCamera;
            weapons = weaponSystem;
            assets = CombatAssets.Load();
            sfx = gameObject.AddComponent<AudioSource>();
            sfx.playOnAwake = false;
            sfx.spatialBlend = 0f;

            int hull = (db.Ship(Session.ShipIndex)?.armor ?? 100) + (Session.HasMod(0) ? 40 : 0);   // Ship::getMaxHP: +40 with mod 0
            var shieldItem = Shop.FirstMounted(db, 9);
            var armorItem = Shop.FirstMounted(db, 10);
            var repair = Shop.FirstMounted(db, 15);
            int shield = shieldItem != null ? shieldItem.Attr(18) : 0;
            shieldRechargeMs = shieldItem != null ? shieldItem.Attr(19) : 0;
            int armor = armorItem != null ? armorItem.Attr(20) : 0;
            HasShield = shield > 0;
            HasArmor = armor > 0;
            if (repair != null) { hasRepair = true; bool mk2 = repair.index != 75; repairHullMs = mk2 ? 420f : 600f; repairArmorMs = mk2 ? 700f : 1000f; }

            Target = gameObject.AddComponent<Target>();
            Target.isPlayer = true;
            Target.isShip = true;
            Target.race = 0;   // the player's ship counts as Terran in NPC race checks
            Target.customDeath = true;
            Target.radius = HitRadiusUnits * M;
            Target.hitpoints = new Hitpoints(hull, shield, armor);
            if (Session.PlayerHull >= 0) Hp.hull = Mathf.Clamp(Session.PlayerHull, 1, hull);
            if (Session.PlayerArmor >= 0) Hp.armor = Mathf.Clamp(Session.PlayerArmor, 0, armor);
            if (Session.PlayerShield >= 0f) Hp.shield = Mathf.Clamp(Session.PlayerShield, 0f, shield);
            Target.hp = Hp.hull;
            Target.maxHp = hull;
            lastCombined = Hp.Combined;
            if (weapons != null) weapons.Owner = Target;
        }

        void OnDestroy()
        {
            // Docking / jumping saves the ship state to Status (MGame::dockEvent, departStation).
            if (Target != null && Hp != null && !Dead)
            {
                Session.PlayerHull = Hp.hull;
                Session.PlayerArmor = Hp.armor;
                Session.PlayerShield = Hp.shield;
            }
        }

        void Update()
        {
            if (Target == null) return;
            float dtMs = Time.deltaTime * 1000f;
            ShieldHitMs = Mathf.Max(0f, ShieldHitMs - dtMs);
            for (int i = 0; i < 4; i++) ArcMs[i] = Mathf.Max(0f, ArcMs[i] - dtMs);
            if (Dead) { UpdateDeath(dtMs); return; }

            Hp.vulnerable = !invulnerable;
            Hp.RegenerateShield(dtMs, shieldRechargeMs);
            if (hasRepair) Hp.Repair(dtMs, repairHullMs, repairArmorMs);
            Target.hp = Hp.hull;

            float combined = Hp.Combined;
            if (combined < lastCombined) OnHit();
            lastCombined = combined;

            if (!Hp.Alive) StartDeath();
        }

        /// <summary>PlayerEgo::update hit feedback.</summary>
        void OnHit()
        {
            if (chase != null && chase.enabled) chase.Shake(1000f, 6f);
            if (Hp.shield >= 2f) ShieldHitMs = 500f;
            AudioClip clip = null;
            if (Hp.hullHit) clip = CombatAssets.Pick(assets?.hitHull);
            else if (Hp.armorHit) clip = CombatAssets.Pick(assets?.hitArmor);
            else if (Hp.shieldHit) clip = CombatAssets.Pick(assets?.hitShield);
            Hp.shieldHit = Hp.armorHit = Hp.hullHit = false;
            if (clip != null) sfx.PlayOneShot(clip, Settings.SfxVolume);

            // Hit direction: where the shot came from, seen from the camera (left / right off screen, else top / bottom).
            var cam = Camera.main;
            var v = Target.lastHitVector;
            if (cam == null || v.sqrMagnitude < 1e-10f) return;
            var from = cam.transform.InverseTransformDirection(-v.normalized);
            float halfW = Mathf.Tan(Camera.VerticalToHorizontalFieldOfView(cam.fieldOfView, cam.aspect) * 0.5f * Mathf.Deg2Rad);
            if (from.z <= 0f || from.x / from.z < -halfW) { if (from.x < 0f) ArcMs[0] = 300f; }
            if (from.z <= 0f || from.x / from.z > halfW) { if (from.x > 0f) ArcMs[1] = 300f; }
            if (from.z > 0f) ArcMs[3] = 300f; else ArcMs[2] = 300f;
        }

        // ---- death (PlayerEgo::explode 0xada6c, MGame::gameOverCheck 0x1b0d04) ---------------------------------

        void StartDeath()
        {
            Dead = true;
            deathMs = 0f;
            ship.ExternalSpeedMetersPerSecond = ship.SpeedMetersPerSecond;
            ship.externalControl = true;
            ship.autopilotTarget = null;
            if (weapons != null) weapons.Blocked = true;
            if (chase != null) chase.enabled = false;   // TargetFollowCamera::setActive(false): the camera stays where it is
            deathSpin = UnityEngine.Random.onUnitSphere;
        }

        void UpdateDeath(float dtMs)
        {
            deathMs += dtMs;
            if (!exploded)
            {
                transform.position += transform.forward * ship.ExternalSpeedMetersPerSecond * dtMs / 1000f;
                if (ship.visualModel != null) ship.visualModel.Rotate(deathSpin, 0.09f * dtMs, Space.World);   // spin rate lost; tuned by eye
            }
            if (!exploded && deathMs >= 3000f)
            {
                exploded = true;
                Explosion.Spawn(transform.position);
                if (ship.visualModel != null) ship.visualModel.gameObject.SetActive(false);
                ship.ExternalSpeedMetersPerSecond = 0f;
            }
            if (!GameOver && deathMs >= 8000f)
            {
                GameOver = true;
                if (assets != null && assets.gameOver != null) sfx.PlayOneShot(assets.gameOver, Settings.SfxVolume);
                GameOverStarted?.Invoke();
            }
        }
    }
}
