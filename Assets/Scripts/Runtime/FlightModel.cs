// FlightModel.cs
// Clean re-implementation of the Galaxy on Fire 2 (Android 2.0.16) player flight behaviour,
// written from notes on the decompiled PlayerEgo / Ship / TargetFollowCamera code.
// Pure C# (only uses UnityEngine math types), so it can be unit-tested outside a scene.
//
// Units: the original works in milliseconds and "GoF units". This class keeps those units
// internally so every constant matches the original; the MonoBehaviour converts to Unity.

using System;
using UnityEngine;

namespace GoF2Remake.Flight
{
    /// <summary>Per-ship inputs to the flight model. Values map 1:1 to data/ships.json + items.json.</summary>
    [Serializable]
    public class FlightStats
    {
        [Tooltip("ships.json 'handling' (e.g. Betty = 120). The game divides it by 100.")]
        public float handling = 120f;

        [Tooltip("Number of installed handling upgrades (bar-agent mods). Each adds +0.2 to base handling.")]
        public int handlingUpgrades = 0;

        [Tooltip("Agility bonus from an installed Steering Nozzle (items.json stats.agility, attribute 28). 0 = none.")]
        public float agility = 0f;

        [Tooltip("Booster items.json stats.boostSpeed (attribute 25). 0 = no booster.")]
        public int boostSpeed = 0;

        [Tooltip("Booster items.json stats.boostDurationMs (attribute 27).")]
        public int boostDurationMs = 0;

        [Tooltip("Booster items.json stats.boostRechargeMs (attribute 26). Booster is usable only if > 0.")]
        public int boostRechargeMs = 0;

        [Header("Hardcore mode: cargo weight reduces handling")]
        public bool cargoAffectsHandling = false;
        public float cargoLoad = 0f;
        public float cargoCapacity = 1f;
    }

    public class FlightModel
    {
        // ---- constants recovered from the binary -------------------------------------------
        public const float BaseSpeed = 2.0f;                  // units per ms, identical for every ship
        const float RateToRadiansPerMs = 2f * Mathf.PI / 65536f * 0.033f; // turn-rate units -> rad/ms
        const float TargetRateScale = 750f;                   // target rate = trunc(input*750*H)/63
        const int TargetRateDivisor = 63;
        const float RampBase = 3.3f;                          // ramp step = dt*H / ((3.3 - sens)*20)
        const float PitchUpSensitivityScale = 1.25f;
        const float PitchDownSensitivityScale = 1.45f;
        const float DecayDivisor = 126f;                      // no input: rate -> 0 by dt*H/126
        const float CollisionPushDecay = 0.7f;                // per frame
        const float CollisionPushCutoff = 0.01f;

        // Auto-level ("align to horizon", triggered by a double tap in the original HUD)
        const float LevelDoneThreshold = 0.015f;              // |up.x| below this and up.y > 0 -> done
        const float LevelRateUpsideDown = 0.00075f;           // rad per ms
        const float LevelRateFar = 0.00035f;                  // |up.x| > 0.3
        const float LevelRateNear = 0.00025f;
        const int LevelMaxDtMs = 60;
        const float LevelRateOvershoot = 0.00035f, LevelRateFine = 0.0002f;   // PlayerEgo::roll's fine phase (+0x324)
        int levelSide;        // PlayerEgo+0x2a9: the sign of up.x last frame (1 negative, 2 positive, 0 none)
        bool levelFine;       // PlayerEgo+0x324: the lean changed sides once, the last part goes slow

        // ---- configuration ------------------------------------------------------------------
        /// <summary>Options-menu steering sensitivity. Must stay well below 3.3/1.45 (~2.27). Default is a guess.</summary>
        public float Sensitivity = 1.0f;
        /// <summary>Tilt steering (options[0x11] = 0): PlayerEgo::down / up ramp the pitch with 1.45 / 1.25 x the tilt
        /// sensitivity; the touch stick, keys and pads use the sensitivity as it is.</summary>
        public bool TiltMode;

        /// <summary>
        /// True: turn rates and the cosmetic model tilt follow partial stick input (needed for analog sticks and
        /// touch). False: the original's rules (rates only grow toward the target while a direction is held; the tilt
        /// uses the input's sign). Identical for full-deflection (keyboard) input.
        /// </summary>
        public bool TrackAnalogInput = true;

        /// <summary>Reproduce the original's integer truncation of boost speed (see Configure).</summary>
        public bool TruncateBoostSpeed = true;

        public float Handling { get; private set; }            // "H" in the notes (0x154)
        float boostSpeedValue = 5f;
        int boostDurationMs = 5000, boostRechargeMs = 20000;
        bool hasBooster;
        FlightStats stats;

        // ---- state ----------------------------------------------------------------------------
        public float Throttle { get; private set; } = 1f;      // 0xbc, 0..1
        public float CurrentSpeed { get; private set; } = BaseSpeed; // 0xb8, units per ms
        public float YawRate { get; private set; }             // 0x27c
        public float PitchRate { get; private set; }           // 0x278
        public bool IsBoosting { get; private set; }
        public bool IsLeveling { get; private set; }
        int boostTimerMs;                                       // 0x138: counts up; negative while recharging
        float collisionPush;                                    // 0x37c

        /// <summary>Visual banking amount: +/-H while steering, 0 otherwise (0x25c / 0x258).</summary>
        public float VisualYawBank { get; private set; }
        public float VisualPitchBank { get; private set; }

        public void Configure(FlightStats s)
        {
            stats = s;
            // Ship::getHandling() = handling/100 + 0.2 per handling upgrade
            float baseH = s.handling / 100f + 0.2f * s.handlingUpgrades;
            // PlayerEgo ctor: H = (h + h*agility/100) * 20
            Handling = (baseH + baseH * (s.agility / 100f)) * 20f;

            // PlayerEgo ctor: boost speed = int(2*boostSpeed/100) + 2. The original stores this as an int,
            // so e.g. Linear Boost (60) gives 3.0 (1.5x) although the shop UI implies 1.6x, and
            // Cyclotron (80) ends up equal to Linear. Set TruncateBoostSpeed = false for the "intended" values.
            float boost = 2f * s.boostSpeed / 100f + 2f;
            boostSpeedValue = TruncateBoostSpeed ? (int)(2f * s.boostSpeed / 100f) + 2 : boost;
            boostDurationMs = s.boostDurationMs;
            boostRechargeMs = s.boostRechargeMs;
            hasBooster = boostRechargeMs > 0;

            CurrentSpeed = BaseSpeed;
            Throttle = 1f;
            boostTimerMs = 0;
            IsBoosting = false;
        }

        /// <summary>Handling after the hardcore-mode cargo penalty: H*(0.6 + 0.4*(1 - load/max)).</summary>
        public float EffectiveHandling
        {
            get
            {
                if (stats == null || !stats.cargoAffectsHandling || stats.cargoCapacity <= 0f) return Handling;
                float free = 1f - Mathf.Clamp01(stats.cargoLoad / stats.cargoCapacity);
                return Handling * 0.6f + Handling * free * 0.4f;
            }
        }

        /// <summary>Maximum turn rate in degrees per second, handy for tuning/UI.</summary>
        public float MaxTurnRateDegPerSec =>
            (int)(TargetRateScale * EffectiveHandling) / TargetRateDivisor * RateToRadiansPerMs * 1000f * Mathf.Rad2Deg;

        public void ChangeThrottle(float delta) => Throttle = Mathf.Clamp01(Throttle + delta);
        public void SetThrottle(float value) => Throttle = Mathf.Clamp01(value);

        public bool BoostReady => !IsBoosting && hasBooster && boostTimerMs >= 0;

        /// <summary>0 at recharge start, 1 when ready.</summary>
        public float BoostRechargePercent =>
            boostTimerMs >= 0 || boostRechargeMs <= 0 ? 1f : 1f + (float)boostTimerMs / boostRechargeMs;

        public void Boost()
        {
            if (!BoostReady) return;
            Throttle = 1f;   // MGame::OnTouchEnd HUD element 2: full throttle first, then the boost
            boostTimerMs = 0;
            CurrentSpeed = boostSpeedValue;
            IsBoosting = true;
        }

        /// <summary>
        /// Boost strength for visuals (engine flame, FOV, camera): ramps 0->1 over the first sixth of the
        /// boost, holds at 1, ramps back to 0 over the last sixth. Original flame scale = 1 + 0.5*this.
        /// </summary>
        public float BoostVisualPercent
        {
            get
            {
                if (!IsBoosting || boostDurationMs <= 0) return 0f;
                float p = boostTimerMs / (boostDurationMs / 6f);
                if (p < 1f) return p;
                if (p > 5f) return Mathf.Max(0f, 6f - p);
                return 1f;
            }
        }

        public void AlignToHorizon() { IsLeveling = true; levelSide = 0; levelFine = false; }

        public void AddCollisionPush(float amount) => collisionPush += amount;

        /// <summary>
        /// Advances one frame.
        /// </summary>
        /// <param name="steer">x = yaw (-1 right .. +1 left, as in the original), y = pitch (+1 down .. -1 up).
        /// Use the controller's invert options to change feel.</param>
        /// <param name="dtMs">Frame time in milliseconds.</param>
        /// <param name="shipUp">Ship's current up vector expressed in world space (for auto-level).</param>
        /// <param name="shipRight">Ship's current right vector in world space (for auto-level).</param>
        /// <returns>Rotation to apply this frame in local space (pitch around X, yaw around Y, roll around Z),
        /// in degrees, plus forward distance in GoF units and sideways collision push.</returns>
        public FrameResult Step(Vector2 steer, float dtMs, Vector3 shipUp, Vector3 shipRight)
        {
            float he = EffectiveHandling;

            // ---- steering input: ramp turn rates toward the stick target ----------------------
            bool yawInput = Mathf.Abs(steer.x) > 1e-4f;
            bool pitchInput = Mathf.Abs(steer.y) > 1e-4f;
            // Cosmetic model tilt. The original uses the input's sign (digital keys); for analog input scale it
            // with the deflection, or a slight push past the centre flips the model to the full tilt.
            VisualYawBank = !yawInput ? 0f : (TrackAnalogInput ? Mathf.Clamp(steer.x, -1f, 1f) : Mathf.Sign(steer.x)) * he;
            VisualPitchBank = !pitchInput ? 0f : (TrackAnalogInput ? Mathf.Clamp(steer.y, -1f, 1f) : Mathf.Sign(steer.y)) * he;

            if (yawInput) YawRate = RampToward(YawRate, steer.x, he, dtMs, 1f);
            if (pitchInput)
                PitchRate = RampToward(PitchRate, steer.y, he, dtMs,
                    !TiltMode ? 1f : steer.y > 0 ? PitchDownSensitivityScale : PitchUpSensitivityScale);

            // ---- rotation for this frame --------------------------------------------------------
            float pitchRad = dtMs * PitchRate * RateToRadiansPerMs;
            float yawRad = dtMs * YawRate * RateToRadiansPerMs;
            float rollRad = IsLeveling ? AutoLevelRoll(dtMs, shipUp, shipRight) : 0f;

            // ---- no input: rates drain linearly back to zero (uses base H, not the cargo-reduced one)
            if (!yawInput) YawRate = Mathf.MoveTowards(YawRate, 0f, dtMs * Handling / DecayDivisor);
            if (!pitchInput) PitchRate = Mathf.MoveTowards(PitchRate, 0f, dtMs * Handling / DecayDivisor);

            // ---- movement -------------------------------------------------------------------------
            float forward = dtMs * Throttle * CurrentSpeed;

            float push = 0f;
            if (Mathf.Abs(collisionPush) > CollisionPushCutoff)
            {
                push = collisionPush * dtMs;
                collisionPush *= CollisionPushDecay;
            }
            else collisionPush = 0f;

            UpdateBoost(dtMs);

            return new FrameResult
            {
                pitchDeg = pitchRad * Mathf.Rad2Deg,
                yawDeg = yawRad * Mathf.Rad2Deg,
                rollDeg = rollRad * Mathf.Rad2Deg,
                forwardUnits = forward,
                sidePushUnits = push
            };
        }

        /// <summary>PlayerEgo::updateManeuver: handleShip is skipped (no steering ramp, no turn from the rates); the yaw rate
        /// is the maneuver's (it banks the model and decays normally afterwards); the ship flies on at its speed.</summary>
        public FrameResult StepManeuver(float dtMs, float yawRate)
        {
            YawRate = yawRate;
            // The bank follows the rate: a full-stick rate (750 H / 63) banks like a full stick.
            VisualYawBank = yawRate / (TargetRateScale / TargetRateDivisor);
            VisualPitchBank = 0f;
            float forward = dtMs * Throttle * CurrentSpeed;
            UpdateBoost(dtMs);
            return new FrameResult { forwardUnits = forward };
        }

        float RampToward(float rate, float input, float he, float dtMs, float sensitivityScale)
        {
            // target = trunc(input * 750 * H) / 63 (integer division, like the original)
            int raw = (int)(input * TargetRateScale * he);
            float target = raw / TargetRateDivisor;
            float denom = (RampBase - Sensitivity * sensitivityScale) * 20f;
            if (denom < 1f) denom = 1f; // guard against extreme sensitivity values
            float step = dtMs * he / denom;

            // The original only accelerates toward the target in the input's direction and never slows an
            // over-target rate while the direction is held. That was fine for its digital input (the target is
            // always full deflection), but with an analog stick the rates stay saturated while the thumb moves
            // around, so steering snaps between 4 directions. Analog: track the target both ways at the same ramp.
            if (!TrackAnalogInput)
            {
                if (target > 0f && rate < target) return Mathf.Min(rate + step, target);
                if (target < 0f && rate > target) return Mathf.Max(rate - step, target);
                return rate;
            }
            return Mathf.MoveTowards(rate, target, step);
        }

        float AutoLevelRoll(float dtMs, Vector3 up, Vector3 right)
        {
            // "up.x" in the original = how much the ship's up vector leans sideways relative to the horizon;
            // here: component of ship-up along the world-horizontal part of ship-right.
            Vector3 horizRight = Vector3.ProjectOnPlane(right, Vector3.up).normalized;
            float lean = Vector3.Dot(up, horizRight);
            float upY = up.y;

            if (Mathf.Abs(lean) < LevelDoneThreshold && upY > 0f)
            {
                IsLeveling = false;
                levelSide = 0;
                levelFine = false;
                return 0f;
            }

            // PlayerEgo::roll 0xa7c04: once the lean crosses zero (an overshoot) one step of 0.00035, then 0.0002 rad/ms until
            // level; before that 0.00075 upside down, else 0.00035 beyond 0.3, 0.00025 closer.
            int side = lean < 0f ? 1 : lean > 0f ? 2 : levelSide;
            float rate;
            if (levelFine) rate = LevelRateFine;
            else if ((side == 2 && levelSide == 1) || (side == 1 && levelSide == 2)) { rate = LevelRateOvershoot; levelFine = true; }
            else if (upY < 0f) rate = LevelRateUpsideDown;
            else rate = Mathf.Abs(lean) > 0.3f ? LevelRateFar : LevelRateNear;
            levelSide = side;

            float dir = lean > 0f ? 1f : -1f; // roll so that the lean shrinks
            return dir * rate * Mathf.Min(dtMs, LevelMaxDtMs);
        }

        void UpdateBoost(float dtMs)
        {
            // Timer counts up every frame; negative values mean "recharging" (PlayerEgo::update).
            int dt = Mathf.RoundToInt(dtMs);
            if (boostTimerMs < 0 && boostTimerMs + dt * 3 > 0) boostTimerMs = 0;
            boostTimerMs += dt;

            if (IsBoosting && boostTimerMs > boostDurationMs)
            {
                IsBoosting = false;
                CurrentSpeed = BaseSpeed;
                boostTimerMs = -boostRechargeMs;
            }
        }

        public struct FrameResult
        {
            public float pitchDeg, yawDeg, rollDeg;
            public float forwardUnits;
            public float sidePushUnits;
        }
    }
}
