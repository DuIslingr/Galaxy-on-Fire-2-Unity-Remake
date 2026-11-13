// RiteEnergy.cs
// Remake (2026-11-13, Chorus's Rites): the Rite energy pool a ship's Rites (Flight.Device with riteCost > 0, PlayerDevices) pay
// from, after Chorus's UEnergyComponent (decompiled: AddRegularEnergy, AddBonusEnergy, RemoveEnergy, CanPayEnergy) with
// BP_Player_Ship_Base's numbers (MaxRegularEnergy 3, RegenRate 0.22, RegenDelay 0):
//   regular pips  0..MaxRegular, the next one growing at RegenPerS pips a second while short of the maximum (4.5 s a pip)
//   bonus pips    on top of the maximum (AddBonusEnergy: Blink's upgrade A overcharging the capacity), each with its own time
//   paying        the bonus pips first, the oldest first (RemoveEnergy's memmove from the front), then the regular ones; a
//                 cost above the total is refused (the Rite doesn't fire)
// Chorus's debug "InfiniteVoidEnergy" is the remake's Cheats.NoEquipmentCooldown (PlayerDevices). The pool starts full.

using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public sealed class RiteEnergy
    {
        /// <summary>BP_Player_Ship_Base's EnergyComponent: MaxRegularEnergy 3, RegenRate 0.22 pips a second, RegenDelay 0.</summary>
        public const int ChorusMax = 3;
        public const float ChorusRegenPerS = 0.22f, ChorusRegenDelayS = 0f;

        public readonly int maxRegular;
        public readonly float regenPerS, regenDelayS;
        public int Regular { get; private set; }
        /// <summary>The next regular pip's growth, 0..1 (0 while full).</summary>
        public float Progress { get; private set; }
        /// <summary>Seconds before the regeneration resumes after a payment (RegenDelay).</summary>
        public float DelayLeft { get; private set; }
        // the bonus pips' seconds left, the oldest first; float.PositiveInfinity = no limit
        readonly List<float> bonus = new List<float>();

        public RiteEnergy(int maxRegular = ChorusMax, float regenPerS = ChorusRegenPerS, float regenDelayS = ChorusRegenDelayS)
        {
            this.maxRegular = Mathf.Max(0, maxRegular);
            this.regenPerS = Mathf.Max(0f, regenPerS);
            this.regenDelayS = Mathf.Max(0f, regenDelayS);
            Regular = this.maxRegular;
        }

        public int Bonus => bonus.Count;
        public int Total => Regular + bonus.Count;
        public bool Full => Regular >= maxRegular;

        public bool CanPay(int cost) => cost <= 0 || Total >= cost;

        /// <summary>'cost' pips paid, the bonus ones first; false (nothing paid) when there aren't enough.</summary>
        public bool TryPay(int cost)
        {
            if (cost <= 0) return true;
            if (Total < cost) return false;
            int fromBonus = Mathf.Min(cost, bonus.Count);
            bonus.RemoveRange(0, fromBonus);
            Regular -= cost - fromBonus;
            if (cost - fromBonus > 0) DelayLeft = regenDelayS;
            return true;
        }

        /// <summary>'n' regular pips back, up to the maximum (AddRegularEnergy).</summary>
        public void AddRegular(int n)
        {
            if (n <= 0) return;
            Regular = Mathf.Min(maxRegular, Regular + n);
            if (Full) Progress = 0f;
        }

        /// <summary>'n' bonus pips past the maximum for 'seconds' each (no limit by default; AddBonusEnergy).</summary>
        public void AddBonus(int n, float seconds = float.PositiveInfinity)
        {
            for (int i = 0; i < n; i++) bonus.Add(seconds > 0f ? seconds : float.PositiveInfinity);
        }

        /// <summary>'dt' seconds on: the regular pips grow back, the bonus ones run out.</summary>
        public void Step(float dt)
        {
            if (dt <= 0f) return;
            for (int i = bonus.Count - 1; i >= 0; i--)
            {
                bonus[i] -= dt;
                if (bonus[i] <= 0f) bonus.RemoveAt(i);
            }
            if (Full) { Progress = 0f; return; }
            if (DelayLeft > 0f)
            {
                DelayLeft -= dt;
                if (DelayLeft > 0f) return;
                dt = -DelayLeft;
                DelayLeft = 0f;
            }
            Progress += regenPerS * dt;
            while (Progress >= 1f && !Full) { Regular++; Progress -= 1f; }
            if (Full) Progress = 0f;
        }

        /// <summary>How far toward 'cost' the pool is, 0..1 (1 = it can be paid): the HUD's sweep.</summary>
        public float ChargeToward(int cost) => cost <= 0 || Total >= cost ? 1f : Mathf.Clamp01((Total + Progress) / cost);

        /// <summary>Every pip back and the bonus ones gone (a new ship, a respawn).</summary>
        public void Refill()
        {
            Regular = maxRegular;
            Progress = DelayLeft = 0f;
            bonus.Clear();
        }
    }
}
