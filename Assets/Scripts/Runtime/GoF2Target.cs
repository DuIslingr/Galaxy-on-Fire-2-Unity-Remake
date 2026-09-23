// GoF2Target.cs
// Something the player's guns can hit (the original's Player objects in Gun+0xb4: KIPlayers, asteroids, gas
// clouds; never stations). Registered in GoF2Target.All while enabled. The hit test uses 'radius' as the half-size
// of an axis-aligned cube (Gun::calcCharacterCollision). Asteroids: radius = meshRadius * scale * 0.7, HP =
// scale * 100 + 30 (PlayerAsteroid ctor); at 0 HP the asteroid-type explosion plays (about 10 s) with sound 21.
// Asteroids also carry what mining needs (PlayerAsteroid +0x124 ore item, +0x14c quality 4..7 = D..A, +0x134 scale).

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

        /// <summary>PlayerAsteroid::getQualityString: A (7) .. D (4).</summary>
        public string QualityLetter => ((char)('A' + Mathf.Clamp(7 - quality, 0, 4))).ToString();
        public int CoreItem => oreItem == 217 ? 218 : oreItem + 11;

        public bool Alive => hp > 0f;
        public event Action<GoF2Target> Died;

        void OnEnable() { if (!All.Contains(this)) All.Add(this); }
        void OnDisable() => All.Remove(this);

        public void Damage(float amount)
        {
            if (!Alive) return;
            hp -= amount;
            if (hp <= 0f) Die();
        }

        /// <summary>Destroys it with its explosion and sound (a mined asteroid: PlayerEgo::stopMining sets HP to -1).</summary>
        public void Explode()
        {
            if (Alive) Die();
        }

        void Die()
        {
            hp = 0f;
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
            Died?.Invoke(this);
            All.Remove(this);
        }
    }
}
