// GoF2Target.cs
// Something the player's guns can hit (the original's Player objects in Gun+0xb4: KIPlayers, asteroids, gas
// clouds; never stations). Registered in GoF2Target.All while enabled. The hit test uses 'radius' as the half-size
// of an axis-aligned cube (Gun::calcCharacterCollision). Asteroids: radius = meshRadius * scale * 0.7, HP =
// scale * 100 + 30 (PlayerAsteroid ctor); at 0 HP the asteroid-type explosion plays (about 10 s) with sound 21.

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
