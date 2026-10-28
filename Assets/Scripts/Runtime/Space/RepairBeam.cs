// RepairBeam.cs
// The automatic repair and transfusion beams (Reference/research/combat_equipment.md 3.4): RepairBeam(item, sort)
// 0xb3fb8 / update 0xb41c4 / render 0xb49dc, one per mounted sort (both can coexist). No button, no HUD element.
//   repair (sort 37: 207 Nirai SPP-C1, 208 SPP-M50)       heals damaged friendly NPCs (hull only): dt * 0.03 * attr54 / 100
//   transfusion (sort 41: 222 Crimson Drain, 223 Pandora Leech)  drains hostile ships dt * 0.01 * attr54 / 100 (whole points
//                     through Player::damage, so kill credit like a gun) and gives the player's shield the same (only
//                     while it isn't full and a shield is mounted)
// Every 2500 ms the attr 55 slots are refilled from the ships within attr 53 units, keeping the most damaged ones (the
// transfusion skips cloaked ones). Beam meshes 19092 / 19093 from the player to each target, scaled to the distance;
// loop sounds 2271 / 2272 / 2267 / 2268 while any slot is filled.
// Remake, multiplayer: the other games' ships here (Target.NetShips) are picked too, after this game's: a hostile one is
// drained through its owner (Target.RemoteDamage, this player's hit), a friendly one (a squadmate, a friendly NPC another
// player's game runs) healed through its owner (Target.RemoteHeal), whole points batched every 250 ms.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Visuals;
using GoF2Remake.World;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public class RepairBeam : MonoBehaviour
    {
        const float M = 0.05f, RetargetMs = 2500f;

        /// <summary>Multiplayer: how often the hull points owed to another game's ship are sent (whole points, batched).</summary>
        const float RemoteSendMs = 250f;

        bool transfusion;
        float rangeUnits, rate;
        Target[] slots;
        NpcShip[] ships;   // the slot's ship when this game runs it, null for another game's (Target.NetShips)
        Transform[] beams;
        float[] acc, sendMs;
        float retargetMs;
        Target player;
        Hitpoints playerHp;
        Traffic traffic;
        AudioSource loop;

        /// <summary>PlayerEgo::setShip: a beam object per mounted sort 37 / 41.</summary>
        public static void AttachAll(GameObject player, Database db, Target target, Traffic traffic)
        {
            foreach (int sort in new[] { 37, 41 })
            {
                var item = Shop.FirstMounted(db, sort);
                if (item == null) continue;
                var b = player.AddComponent<RepairBeam>();
                b.Setup(item, sort == 41, target, traffic);
            }
        }

        void Setup(ItemData item, bool drain, Target target, Traffic level)
        {
            transfusion = drain;
            rangeUnits = item.Attr(53, 15000);
            rate = item.Attr(54, 60) / 100f;
            int n = Mathf.Max(1, item.Attr(55, 1));
            slots = new Target[n];
            ships = new NpcShip[n];
            beams = new Transform[n];
            acc = new float[n];
            sendMs = new float[n];
            player = target;
            playerHp = target.hitpoints;
            traffic = level;
            var assets = CombatAssets.Load();
            var prefab = assets == null ? null : drain ? assets.transfusionBeam : assets.repairBeam;
            if (prefab != null)
                for (int i = 0; i < n; i++)
                {
                    var go = Instantiate(prefab);
                    go.name = drain ? "Transfusion beam" : "Repair beam";
                    GunRig.StripForFx(go);
                    go.SetActive(false);
                    beams[i] = go.transform;
                }
            AudioClip clip = null;
            if (assets != null)
                clip = item.index switch { 207 => assets.repairLoop1, 208 => assets.repairLoop2, 222 => assets.drainLoop1, _ => assets.drainLoop2 };
            if (clip != null)
            {
                loop = gameObject.AddComponent<AudioSource>();
                loop.clip = GoF2Remake.Modding.ModSounds.Get(clip);
                loop.loop = true;
                loop.playOnAwake = false;
                loop.spatialBlend = 0f;
            }
        }

        void OnDestroy()
        {
            if (beams != null) foreach (var b in beams) if (b != null) Destroy(b.gameObject);
        }

        bool Candidate(NpcShip s)
        {
            if (s == null || s.Gone || s.Current != NpcShip.State.Fly || s.Asleep || !s.Target.Alive) return false;
            if ((s.transform.position - transform.position).magnitude / M >= rangeUnits) return false;
            if (transfusion)
                return s.Target.hostileToPlayer && !s.Target.untargetable && playerHp != null && playerHp.maxShield > 0
                       && playerHp.shield < playerHp.maxShield;
            return s.Target.friendToPlayer && s.Hp.hull < s.Hp.maxHull;
        }

        /// <summary>Remake, multiplayer: another game's ship here (Target.NetShips: the other players, the NPCs another
        /// player's game runs). The transfusion drains a hostile one through its owner (Target.RemoteDamage, as this player's
        /// hit: where players may fight, a player too); the repair beam heals a friendly one (a squadmate, a friendly NPC)
        /// through its owner (Target.RemoteHeal). Before, both only saw this game's own ships, so in an orbit another player
        /// runs they did nothing.</summary>
        bool RemoteCandidate(Target t)
        {
            if (t == null || !t.isActiveAndEnabled || t.isPlayer || !t.Alive || t.untargetable) return false;
            if ((t.transform.position - transform.position).magnitude / M >= rangeUnits) return false;
            if (transfusion)
                return t.hostileToPlayer && !t.playerProof && !t.phased && t.RemoteDamage != null && playerHp != null
                       && playerHp.maxShield > 0 && playerHp.shield < playerHp.maxShield;
            return t.friendToPlayer && t.RemoteHeal != null && t.hp < t.maxHp;
        }

        /// <summary>The hull points the pick compares: this game's ship's own, another game's from its fraction and real
        /// maximum (Target.netMaxHull).</summary>
        static float Hull(Target t, NpcShip s) =>
            s != null ? s.Hp.hull : t.maxHp > 0f ? t.hp / t.maxHp * (t.netMaxHull > 0f ? t.netMaxHull : t.maxHp) : t.hp;

        /// <summary>The slot rule: a free slot, else replace the healthiest ship that is healthier than this one.</summary>
        void Offer(Target t, NpcShip s)
        {
            float hull = Hull(t, s);
            int free = System.Array.IndexOf(slots, null);
            if (free >= 0) { slots[free] = t; ships[free] = s; return; }
            int worst = -1;
            for (int i = 0; i < slots.Length; i++)
                if (Hull(slots[i], ships[i]) > hull && (worst < 0 || Hull(slots[i], ships[i]) > Hull(slots[worst], ships[worst]))) worst = i;
            if (worst >= 0) { slots[worst] = t; ships[worst] = s; }
        }

        void Retarget()
        {
            for (int i = 0; i < slots.Length; i++)
            {
                // points still owed to another game's ship that leaves the slot go now
                if (slots[i] != null && ships[i] == null) Send(i, true);
                slots[i] = null;
                ships[i] = null;
            }
            if (traffic == null || !player.Alive) return;
            foreach (var s in traffic.Ships) if (Candidate(s)) Offer(s.Target, s);
            foreach (var t in Target.NetShips) if (RemoteCandidate(t)) Offer(t, null);   // empty in single player
        }

        /// <summary>Another game's ship: the whole points gathered go to its owner, batched every RemoteSendMs ('now': at
        /// once).</summary>
        void Send(int i, bool now)
        {
            var t = slots[i];
            if (t == null || acc[i] < 1f || (!now && sendMs[i] > 0f)) return;
            int whole = (int)acc[i];
            acc[i] -= whole;
            sendMs[i] = RemoteSendMs;
            if (!t.Alive) return;
            if (transfusion) t.Damage(whole, false);   // Target.RemoteDamage: the owner takes it as this player's hit
            else t.RemoteHeal?.Invoke(whole);
        }

        void Update()
        {
            float dtMs = Time.deltaTime * 1000f * TimeExtender.PlayerFactor;
            if (dtMs <= 0f) return;
            retargetMs -= dtMs;
            if (retargetMs < 0f) { retargetMs = RetargetMs; Retarget(); }
            bool any = false;
            for (int i = 0; i < slots.Length; i++)
            {
                var t = slots[i];
                var s = ships[i];
                if (t != null && (!player.Alive || !t.Alive || (s != null ? s.Gone || s.Current != NpcShip.State.Fly : !t.isActiveAndEnabled)))
                {
                    slots[i] = t = null;
                    ships[i] = s = null;
                }
                var beam = beams[i];
                if (t == null) { if (beam != null && beam.gameObject.activeSelf) beam.gameObject.SetActive(false); continue; }
                any = true;
                float amount = dtMs * (transfusion ? 0.01f : 0.03f) * rate;
                if (s == null) sendMs[i] -= dtMs;
                if (transfusion)
                {
                    // RepairBeam::update 0xb41c4: it drains and refills only while the shield isn't full (getShieldDamageRate
                    // < 100); with a full shield the beam stays drawn on its target until the next pick but does nothing (it
                    // kept draining the target's hull).
                    if (playerHp != null && playerHp.shield < playerHp.maxShield)
                    {
                        acc[i] += amount;
                        if (s == null) Send(i, false);
                        else while (acc[i] >= 1f && s.Target.Alive) { acc[i] -= 1f; s.Target.Damage(1f, false); }
                        playerHp.shield = Mathf.Min(playerHp.maxShield, playerHp.shield + amount);
                    }
                }
                else
                {
                    acc[i] += amount;   // Player::heal: a fractional accumulator, hull only
                    if (s == null) Send(i, false);
                    else
                    {
                        int whole = (int)acc[i];
                        if (whole > 0) { acc[i] -= whole; s.Hp.hull = Mathf.Min(s.Hp.maxHull, s.Hp.hull + whole); s.Target.hp = s.Hp.hull; }
                    }
                }
                if (beam == null || slots[i] == null) continue;
                if (!beam.gameObject.activeSelf) beam.gameObject.SetActive(true);
                var d = t.transform.position - transform.position;
                if (d.sqrMagnitude < 1e-6f) continue;
                beam.SetPositionAndRotation(transform.position, Quaternion.LookRotation(d, transform.up));
                beam.localScale = new Vector3(1f, 1f, d.magnitude / M);
            }
            if (loop == null) return;
            if (any && !loop.isPlaying) { loop.volume = 0.7f * Settings.SfxVolume; loop.Play(); }
            else if (!any && loop.isPlaying) loop.Stop();
        }
    }
}
