// GoF2Target.cs
// Something guns can hit: the original's Player objects (KIPlayers: ships, asteroids, gas clouds; never stations; and the
// player's own ship for NPC guns). Registered in GoF2Target.All while enabled. The hit test uses 'radius' as the
// half-size of an axis-aligned cube (Gun::calcCharacterCollision), or the local 'boxes' for big ships (KIPlayer+0x3c
// custom collide: freighters, battleship).
//   Asteroids: radius = meshRadius * scale * 0.7, HP = scale * 100 + 30 (PlayerAsteroid ctor); at 0 HP the asteroid
//     explosion plays (about 10 s) with sound 21. They also carry what mining needs (PlayerAsteroid +0x124 ore item,
//     +0x14c quality 4..7 = D..A, +0x134 scale).
//   Ships and the player: a GoF2Hitpoints (shield -> armor -> hull, Player::damage 0xafa70), a race, the hostile /
//     friend flags (Player+0x5c / +0x5d, marker colours) and 'customDeath' (the owner plays its own death sequence).

using System;
using System.Collections.Generic;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class GoF2Target : MonoBehaviour
    {
        public static readonly List<GoF2Target> All = new List<GoF2Target>();

        [Tooltip("Half-size of the hit cube in metres.")]
        public float radius = 10f;
        public float maxHp = 100f;
        public float hp = 100f;
        public bool isAsteroid;
        public GameObject explosionPrefab;
        public float explosionScale = 1f;
        public AudioClip destroyedSound;

        [Header("Asteroid (mining)")]
        [Tooltip("Ore item index (154-164, 217), -1 = not an asteroid.")]
        public int oreItem = -1;
        [Tooltip("4 D, 5 C, 6 B, 7 A: the minigame's layer count; class A also yields a core (ore + 11).")]
        public int quality = 4;
        public float scale = 1f;

        [Header("Ships")]
        [Tooltip("KIPlayer+0x24: 0 Terran, 1 Vossk, 2 Nivelian, 3 Midorian, 8 Pirate, 9 Void, 10 Specter; -1 not a ship.")]
        public int race = -1;
        public bool isPlayer;
        public bool isShip;
        [Tooltip("Player+0x5c / +0x5d: hostile to / friend of the player (recomputed every frame by the ship).")]
        public bool hostileToPlayer, friendToPlayer;
        [Tooltip("Player+0x5e: NPCs don't attack it.")]
        public bool untargetable;
        [Tooltip("The owner handles the death (ships): no automatic explosion, renderers stay on.")]
        public bool customDeath;
        [Tooltip("Local-space hit boxes (metres) instead of the cube (big ships).")]
        public Bounds[] boxes;

        /// <summary>Shield / armor / hull pools; null = plain 'hp' (asteroids).</summary>
        [NonSerialized] public GoF2Hitpoints hitpoints;
        /// <summary>Player+0x44: the killing hit came from an NPC gun (no kill credit, no standing change).</summary>
        [NonSerialized] public bool killedByNpc;
        /// <summary>Player+0xc4: the last hit's vector (the bullet velocity).</summary>
        [NonSerialized] public Vector3 lastHitVector;
        /// <summary>A crate is waiting to be salvaged from this (dead) ship: the radar may lock it.</summary>
        [NonSerialized] public GoF2Crate crate;

        /// <summary>PlayerAsteroid::getQualityString: A (7) .. D (4).</summary>
        public string QualityLetter => ((char)('A' + Mathf.Clamp(7 - quality, 0, 4))).ToString();
        public int CoreItem => oreItem == 217 ? 218 : oreItem + 11;

        public bool Alive => hitpoints != null ? hitpoints.Alive : hp > 0f;
        public float HullFraction => hitpoints != null ? hitpoints.HullFraction : maxHp > 0f ? hp / maxHp : 0f;
        /// <summary>Active and alive (a valid target for NPCs).</summary>
        public bool Targetable => Alive && isActiveAndEnabled && !untargetable;

        /// <summary>(target, damage, byNpc) after every hit, before the death check.</summary>
        public event Action<GoF2Target, int, bool> Damaged;
        public event Action<GoF2Target> Died;

        void OnEnable() { if (!All.Contains(this)) All.Add(this); }
        void OnDisable() => All.Remove(this);

        /// <summary>Player::damage: 'byNpc' = an NPC gun fired it (friendGun); 'hitVector' = the bullet velocity.</summary>
        public void Damage(float amount, bool byNpc = false, Vector3 hitVector = default)
        {
            if (!Alive) return;
            int dmg = Mathf.Max(0, (int)amount);
            lastHitVector = hitVector;
            bool dead;
            if (hitpoints != null)
            {
                dead = hitpoints.Damage(dmg);
                hp = hitpoints.hull;
                maxHp = hitpoints.maxHull;
            }
            else
            {
                hp -= amount;
                dead = hp <= 0f;
            }
            Damaged?.Invoke(this, dmg, byNpc);
            if (dead) { killedByNpc = byNpc; Die(); }
        }

        /// <summary>Destroys it with its explosion and sound (a mined asteroid: PlayerEgo::stopMining sets HP to -1).</summary>
        public void Explode()
        {
            if (!Alive) return;
            if (hitpoints != null) hitpoints.hull = 0;
            Die();
        }

        /// <summary>Gun::calcCharacterCollision: 'point' (metres) inside the cube, or inside a local box.</summary>
        public bool Contains(Vector3 point)
        {
            if (boxes != null && boxes.Length > 0)
            {
                var local = transform.InverseTransformPoint(point);
                foreach (var b in boxes) if (b.Contains(local)) return true;
                return false;
            }
            var d = transform.position - point;
            return Mathf.Abs(d.x) < radius && Mathf.Abs(d.y) < radius && Mathf.Abs(d.z) < radius;
        }

        void Die()
        {
            hp = 0f;
            if (!customDeath)
            {
                foreach (var r in GetComponentsInChildren<Renderer>()) r.enabled = false;
                var spin = GetComponent<GoF2Spin>();
                if (spin != null) spin.enabled = false;
                if (explosionPrefab != null)
                {
                    var fx = Instantiate(explosionPrefab, transform.position, transform.rotation);
                    fx.transform.localScale = explosionPrefab.transform.localScale * explosionScale;
                    float length = GoF2PartAnimation.PlayOnce(fx);
                    Destroy(fx, Mathf.Max(1f, length / 1000f + 0.2f));
                }
                GoF2Sfx.PlayAt(destroyedSound, transform.position);
            }
            Died?.Invoke(this);
            if (!customDeath) All.Remove(this);
        }

        /// <summary>A dead ship relaunched (KIPlayer::revive): full pools.</summary>
        public void Revive()
        {
            if (hitpoints != null)
            {
                hitpoints.hull = hitpoints.maxHull;
                hitpoints.shield = hitpoints.maxShield;
                hitpoints.armor = hitpoints.maxArmor;
                hitpoints.emp = hitpoints.maxEmp;
                hitpoints.empDisabled = false;
                hp = maxHp = hitpoints.maxHull;
            }
            else hp = maxHp;
            killedByNpc = false;
            crate = null;
            if (isActiveAndEnabled && !All.Contains(this)) All.Add(this);
        }
    }
}
