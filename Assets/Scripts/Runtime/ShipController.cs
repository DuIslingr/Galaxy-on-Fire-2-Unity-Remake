// ShipController.cs
// Drives a ship transform with FlightModel. Put it on the ship root; put the visible mesh in a
// child object and assign it to 'visualModel' to get the original's cosmetic banking.
//
// Input: Input System package only (no legacy Input Manager). The four actions below are serialized
// on the component, so bindings can be edited/rebound in the Inspector. Defaults:
//   Steer         WASD / arrow keys / gamepad left stick
//   Throttle      E = up, Q = down / gamepad right bumper = up, left bumper = down (the triggers fire,
//                 WeaponSystem)
//   Boost         Space / gamepad south button (A / Cross)
//   AlignHorizon  R / gamepad north button (Y / Triangle)
// Touch or your own UI: call SetSteer()/SetThrottle()/Boost(); the stronger of the external steer and the
// built-in actions wins, so both can be used at the same time (FlightHud's touch stick does this).

using UnityEngine;
using UnityEngine.InputSystem;

namespace GoF2Remake.Flight
{
    [DisallowMultipleComponent]
    public class ShipController : MonoBehaviour
    {
        [Header("Ship")]
        public FlightStats stats = new FlightStats();

        [Tooltip("Meters per GoF unit. Base speed is 2000 GoF units/s, weapon ranges are ~2000-4000 units.")]
        public float metersPerUnit = 0.05f;

        [Range(0f, 2.2f)] public float sensitivity = 1.0f;

        [Header("Input")]
        [UnityEngine.Serialization.FormerlySerializedAs("useLegacyInput")]
        public bool useBuiltInInput = true;
        public bool invertPitch = false;
        public float throttleChangePerSecond = 0.8f;

        public InputAction steerAction = new InputAction("Steer", InputActionType.Value, expectedControlType: "Vector2");
        public InputAction throttleAction = new InputAction("Throttle", InputActionType.Value, expectedControlType: "Axis");
        public InputAction boostAction = new InputAction("Boost", InputActionType.Button);
        public InputAction alignAction = new InputAction("AlignHorizon", InputActionType.Button);

        [Header("Visual banking (cosmetic only)")]
        public Transform visualModel;
        [Tooltip("Degrees of model roll per unit of H while yawing. Tune by eye; not a recovered constant.")]
        public float bankDegreesPerH = 1.2f;
        public float pitchTiltDegreesPerH = 0.4f;
        public float bankSmoothing = 6f;

        public FlightModel Model { get; private set; } = new FlightModel();

        /// <summary>An autopilot moves the ship (asteroid docking, PlayerEgo+0x145): no input, no flight model step and
        /// no cosmetic banking; it reports its speed through ExternalSpeedMetersPerSecond.</summary>
        [System.NonSerialized] public bool externalControl;
        [System.NonSerialized] public float ExternalSpeedMetersPerSecond;

        /// <summary>Autopilot (PlayerEgo::setAutoPilot): the world position to fly to, re-read every frame; null = off.
        /// The stick is ignored; throttle, boost and the flight model's speed still apply (autopilot_travel.md 3.3).</summary>
        [System.NonSerialized] public System.Func<Vector3> autopilotTarget;

        /// <summary>Speed this frame in m/s (after world scaling).</summary>
        public float SpeedMetersPerSecond { get; private set; }

        Vector2 externalSteer;
        float bankAngle, tiltAngle;

        void Awake()
        {
            AddDefaultBindings();
            ApplyStats();
        }

        void OnEnable()
        {
            steerAction.Enable(); throttleAction.Enable(); boostAction.Enable(); alignAction.Enable();
        }

        void OnDisable()
        {
            steerAction.Disable(); throttleAction.Disable(); boostAction.Disable(); alignAction.Disable();
        }

        /// <summary>Fills in the default keyboard + gamepad bindings for any action that has none.</summary>
        void AddDefaultBindings()
        {
            if (steerAction.bindings.Count == 0)
            {
                steerAction.AddCompositeBinding("2DVector")
                    .With("Up", "<Keyboard>/w").With("Down", "<Keyboard>/s")
                    .With("Left", "<Keyboard>/a").With("Right", "<Keyboard>/d");
                steerAction.AddCompositeBinding("2DVector")
                    .With("Up", "<Keyboard>/upArrow").With("Down", "<Keyboard>/downArrow")
                    .With("Left", "<Keyboard>/leftArrow").With("Right", "<Keyboard>/rightArrow");
                steerAction.AddBinding("<Gamepad>/leftStick");
            }
            if (throttleAction.bindings.Count == 0)
            {
                throttleAction.AddCompositeBinding("1DAxis")
                    .With("Positive", "<Keyboard>/e").With("Negative", "<Keyboard>/q");
                throttleAction.AddCompositeBinding("1DAxis")
                    .With("Positive", "<Gamepad>/rightShoulder").With("Negative", "<Gamepad>/leftShoulder");
            }
            if (boostAction.bindings.Count == 0)
            {
                boostAction.AddBinding("<Keyboard>/space");
                boostAction.AddBinding("<Gamepad>/buttonSouth");
            }
            if (alignAction.bindings.Count == 0)
            {
                alignAction.AddBinding("<Keyboard>/r");
                alignAction.AddBinding("<Gamepad>/buttonNorth");
            }
        }

        /// <summary>Call after changing 'stats' at runtime (new ship, new equipment, cargo change).</summary>
        public void ApplyStats()
        {
            Model.Configure(stats);
            Model.Sensitivity = sensitivity;
        }

        public void SetSteer(Vector2 steer) => externalSteer = Vector2.ClampMagnitude(steer, 1f);
        public void SetThrottle(float t) => Model.SetThrottle(t);
        public void Boost() => Model.Boost();
        public void AlignToHorizon() => Model.AlignToHorizon();

        void Update()
        {
            Model.Sensitivity = sensitivity;
            float dtMs = Time.deltaTime * 1000f;
            if (externalControl) { SpeedMetersPerSecond = ExternalSpeedMetersPerSecond; return; }

            Vector2 steer = useBuiltInInput ? ReadInput() : Vector2.zero;
            if (externalSteer.sqrMagnitude > steer.sqrMagnitude) steer = externalSteer;
            if (autopilotTarget != null) steer = Vector2.zero;

            // Model convention: +x = yaw left, +y = pitch down. Map "stick right = turn right".
            var model = new Vector2(-steer.x, invertPitch ? steer.y : -steer.y);

            var r = Model.Step(model, dtMs, transform.up, transform.right);

            if (autopilotTarget != null)
            {
                // PlayerEgo::moveToPosition 0xa8720: turn = min(handling + 2.7, 4), dir += (to - dir) * (int)(dt * turn) / 4096,
                // world up (the ship levels out, no roll).
                float turn = Mathf.Min(stats.handling / 100f + 0.2f * stats.handlingUpgrades + 2.7f, 4f);
                var to = (autopilotTarget() - transform.position).normalized;
                var dir = (transform.forward + (to - transform.forward) * ((int)(dtMs * turn) / 4096f)).normalized;
                if (dir.sqrMagnitude > 0f) transform.rotation = Quaternion.LookRotation(dir, Vector3.up);
            }
            // Original: yaw positive = left. Unity yaw positive = right, so negate.
            else transform.Rotate(r.pitchDeg, -r.yawDeg, r.rollDeg, Space.Self);
            transform.position += transform.forward * (r.forwardUnits * metersPerUnit)
                                + transform.right * (r.sidePushUnits * metersPerUnit);

            SpeedMetersPerSecond = Time.deltaTime > 0f ? r.forwardUnits * metersPerUnit / Time.deltaTime : 0f;

            UpdateVisualBank();
        }

        Vector2 ReadInput()
        {
            float throttle = throttleAction.ReadValue<float>();
            if (Mathf.Abs(throttle) > 0.01f) Model.ChangeThrottle(throttle * throttleChangePerSecond * Time.deltaTime);
            if (boostAction.WasPressedThisFrame()) Model.Boost();
            if (alignAction.WasPressedThisFrame()) Model.AlignToHorizon();
            return Vector2.ClampMagnitude(steerAction.ReadValue<Vector2>(), 1f);
        }

        void UpdateVisualBank()
        {
            if (visualModel == null) return;
            float targetBank = Model.VisualYawBank * bankDegreesPerH;
            float targetTilt = Model.VisualPitchBank * pitchTiltDegreesPerH;
            float k = 1f - Mathf.Exp(-bankSmoothing * Time.deltaTime);
            bankAngle = Mathf.Lerp(bankAngle, targetBank, k);
            tiltAngle = Mathf.Lerp(tiltAngle, targetTilt, k);
            visualModel.localRotation = Quaternion.Euler(tiltAngle, 0f, bankAngle);
        }

        /// <summary>Push the ship sideways after a collision (decays to 70% per frame like the original).</summary>
        public void OnHitPush(float amount) => Model.AddCollisionPush(amount);

#if UNITY_EDITOR
        void OnValidate()
        {
            if (Application.isPlaying) ApplyStats();
        }
#endif
    }
}
