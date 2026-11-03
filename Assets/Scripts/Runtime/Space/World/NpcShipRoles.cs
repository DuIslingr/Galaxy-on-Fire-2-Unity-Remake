// NpcShipRoles.cs
// NpcShip, part: a mod ship's role in a fight (Flight.NpcRoles; ships.json "traffic": { "role" }, EVERSPACE 2's drone types).
// The steering reads RoleFires / RoleRangeFactor / RoleBreaksOff, GunHit the webber's slow; UpdateRole runs the rest each
// frame of flight: the detonator's blast, the shield charger's repairs, the armour link's damage share, the anti-missile
// drone's shots at the player's missiles. JumpSuppressed is the Khador Drive's check (SystemJump).

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    public partial class NpcShip
    {
        public NpcRoles.Role Role { get; private set; }
        float roleTickMs;
        readonly List<Target> linked = new List<Target>();
        static readonly List<NpcShip> suppressors = new List<NpcShip>();

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetRoleStatics() => suppressors.Clear();

        /// <summary>A jump suppressor flies, hostile to the player, in this orbit: the Khador Drive won't charge.</summary>
        public static bool JumpSuppressed
        {
            get
            {
                for (int i = suppressors.Count - 1; i >= 0; i--)
                {
                    var s = suppressors[i];
                    if (s == null) { suppressors.RemoveAt(i); continue; }
                    if (s.isActiveAndEnabled && s.Current == State.Fly && s.Target != null && s.Target.Alive && s.Target.hostileToPlayer) return true;
                }
                return false;
            }
        }

        bool RoleFires => NpcRoles.Fires(Role);
        float RoleRangeFactor => Role == NpcRoles.Role.Sniper ? NpcRoles.FireRangeFactor : 1f;
        /// <summary>The detonator flies into its target instead of circling away at the break-off range.</summary>
        bool RoleBreaksOff => Role != NpcRoles.Role.Detonator;

        void SetupRole(SpawnSpec spec)
        {
            Role = NpcRoles.Parse((db?.Ship(spec.ship) as CustomShipData)?.traffic?.role);
            if (Role == NpcRoles.Role.JumpSuppressor && !suppressors.Contains(this)) suppressors.Add(this);
        }

        void TeardownRole()
        {
            Unlink();
            suppressors.Remove(this);
        }

        void OnDisable() => Unlink();

        void Unlink()
        {
            foreach (var t in linked) if (t != null) t.damageFactor = 1f;
            linked.Clear();
        }

        /// <summary>A ship of the same race (its wing), alive and in flight.</summary>
        bool Ally(Target t, out NpcShip ship)
        {
            ship = null;
            if (t == null || t == Target || t.isPlayer || !t.isShip || !t.Alive) return false;
            ship = t.GetComponent<NpcShip>();
            return ship != null && ship.Race == Race && ship.Current == State.Fly;
        }

        void UpdateRole(float dtMs)
        {
            if (Role == NpcRoles.Role.None || !Target.Alive || Hp.empDisabled) { Unlink(); return; }
            if (Role == NpcRoles.Role.Detonator) { UpdateDetonator(); return; }
            roleTickMs += dtMs;
            if (Role == NpcRoles.Role.AntiMissile)
            {
                if (roleTickMs < NpcRoles.AntiMissileReloadMs) return;
                roleTickMs = 0f;
                if (!Target.hostileToPlayer) return;
                foreach (var t in Target.All)
                    if (t != null && t.isPlayer && t.isActiveAndEnabled)
                        t.GetComponent<WeaponSystem>()?.ShootDownMissile(transform.position, NpcRoles.AntiMissileM);
                return;
            }
            if (roleTickMs < 250f) return;
            float step = roleTickMs;
            roleTickMs = 0f;
            float r2 = NpcRoles.SupportM * NpcRoles.SupportM;
            if (Role == NpcRoles.Role.ShieldCharger)
            {
                foreach (var t in Target.All)
                {
                    if (!Ally(t, out _) || (t.transform.position - transform.position).sqrMagnitude > r2) continue;
                    var hp = t.hitpoints;
                    if (hp == null || hp.hull >= hp.maxHull) continue;
                    hp.hull = Mathf.Min(hp.maxHull, hp.hull + Mathf.Max(1, Mathf.RoundToInt(NpcRoles.Repair(hp.maxHull, step))));
                    t.hp = hp.hull;
                }
            }
            else if (Role == NpcRoles.Role.ArmorLink)
            {
                Unlink();
                foreach (var t in Target.All)
                {
                    if (!Ally(t, out _) || (t.transform.position - transform.position).sqrMagnitude > r2) continue;
                    if (t.damageFactor != 1f) continue;   // (another rule's factor, a capital ship's shield, stays)
                    t.damageFactor = NpcRoles.LinkDamageFactor;
                    linked.Add(t);
                }
            }
        }

        /// <summary>Within the trigger of its target: the blast on every ship around, then itself.</summary>
        void UpdateDetonator()
        {
            var t = target;
            if (t == null || !t.Alive || !attacking) return;
            if ((t.transform.position - transform.position).sqrMagnitude > NpcRoles.TriggerM * NpcRoles.TriggerM) return;
            float dmg = NpcRoles.BlastDamage(gun != null ? gun.damage : 10f);
            float b2 = NpcRoles.BlastM * NpcRoles.BlastM;
            var pos = transform.position;
            var all = Target.All;
            for (int i = all.Count - 1; i >= 0; i--)
            {
                var o = all[i];
                if (o == null || o == Target || !o.Alive || !(o.isShip || o.isPlayer)) continue;
                var d = o.transform.position - pos;
                if (d.sqrMagnitude > b2) continue;
                o.Damage(dmg, true, d.normalized);
            }
            Target.lastPlayerWeapon = -1;   // its own blast: nobody's kill
            Target.Damage(Hp.Combined + 1f, true, transform.forward, 0f);
        }
    }
}
