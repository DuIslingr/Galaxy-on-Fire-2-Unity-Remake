// VrRig.cs
// Remake VR: one per scene (VrMode attaches it on sceneLoaded). The scene's own camera stays the game's logical camera:
// every system keeps using Camera.main for its projections, cutscenes and the chase camera, but it renders nothing to the
// headset (an empty desktop-only pass under everything). A separate stereo camera, the VR eye, sits on a rig that follows
// the logical camera every frame (after all camera scripts), with the headset's pose on top (Input System
// TrackedPoseDriver, seated: the tracking origin is the head's start). Outside flight the rig keeps only the camera's yaw
// (a level horizon). The simulation (-vrsim) has no headset: right mouse drag looks around.
// The floating screen (VrPanels: every UI panel on a quad): with a headset 1.9 m wide, 2 m ahead (in flight it fills the
// scene camera's view at 2 m, so the HUD's markers sit on what they mark); in the simulation it fills the view, so the
// desktop mouse lines up with it. The right controller's laser points at it (VrPad's virtual mouse, the trigger clicks).
// The star map draws into a texture on the screen too (its own 3D scene switches the level's cameras off).

using GoF2Remake.UI;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.XR;
using UnityEngine.Rendering.Universal;
using UnityEngine.SceneManagement;

namespace GoF2Remake.Vr
{
    [DefaultExecutionOrder(10000)]
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class VrRig : MonoBehaviour
    {
        public const int UiLayer = 29;
        const float ScreenDistance = 2f, ScreenWidth = 1.9f, LaserLength = 8f;

        /// <summary>This scene's rig, null outside VR.</summary>
        public static VrRig Current { get; private set; }

        Camera logical, eye;
        Transform head, leftHand, rightHand, screen, mapScreen;
        VrPanels panels;
        LineRenderer laser;
        RenderTexture mapTexture;
        Material mapMaterial;
        Camera mapCamera;
        int eyeMask;
        CameraClearFlags eyeClear;
        Color eyeBackground;
        bool flight;
        Vector2 simLook;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { Current = null; DebugLook = null; }

        /// <summary>Testing (the simulation): a fixed look (degrees: x yaw, y pitch up) instead of the mouse's; null = the mouse.</summary>
        public static Vector2? DebugLook;

        /// <summary>The headset's camera (null outside VR).</summary>
        public Camera Eye => eye;
        /// <summary>The controllers' poses (null without a headset): VrControls grabs the stick and the throttle.</summary>
        public Transform LeftHand => leftHand;
        public Transform RightHand => rightHand;

        /// <summary>The right controller's position (VrStation: grabbing the ship).</summary>
        public Vector3 RightHandPosition => rightHand != null ? rightHand.position : head.position;

        /// <summary>The floating screen (the UI quads' frame).</summary>
        public Transform Screen => screen;

        public static void Attach(Scene scene)
        {
            var cam = Camera.main;
            if (cam == null || cam.gameObject.scene != scene)
                foreach (var root in scene.GetRootGameObjects()) { cam = root.GetComponentInChildren<Camera>(); if (cam != null) break; }
            if (cam == null) { Debug.LogWarning($"VrRig: no camera in {scene.name}"); return; }
            var go = new GameObject("VR Rig");
            SceneManager.MoveGameObjectToScene(go, scene);
            go.AddComponent<VrRig>().Init(cam, scene.name == "Space");
        }

        void Init(Camera cam, bool inFlight)
        {
            Current = this;
            logical = cam;
            flight = inFlight;

            head = new GameObject("VR Head").transform;
            head.SetParent(transform, false);
            eye = head.gameObject.AddComponent<Camera>();
            eye.CopyFrom(cam);
            head.localPosition = Vector3.zero;   // CopyFrom moves the eye onto the camera's pose too
            head.localRotation = Quaternion.identity;
            eye.tag = "Untagged";
            eye.depth = cam.depth + 100f;
            eye.nearClipPlane = 0.02f;
            eyeMask = cam.cullingMask | (1 << UiLayer);
            eye.cullingMask = eyeMask;
            eyeClear = cam.clearFlags;
            eyeBackground = cam.backgroundColor;
            eye.stereoTargetEye = VrMode.Headset ? StereoTargetEyeMask.Both : StereoTargetEyeMask.None;
            var src = cam.GetUniversalAdditionalCameraData();
            var dst = eye.GetUniversalAdditionalCameraData();
            dst.renderPostProcessing = src.renderPostProcessing;
            dst.antialiasing = src.antialiasing;
            dst.antialiasingQuality = src.antialiasingQuality;
            dst.volumeLayerMask = src.volumeLayerMask;
            dst.volumeTrigger = head;
            dst.renderShadows = src.renderShadows;
            dst.requiresColorOption = src.requiresColorOption;
            dst.requiresDepthOption = src.requiresDepthOption;

            // The logical camera: nothing to see, under everything, never in the headset.
            cam.cullingMask = 0;
            cam.clearFlags = CameraClearFlags.SolidColor;
            cam.backgroundColor = Color.black;
            cam.stereoTargetEye = StereoTargetEyeMask.None;
            src.renderPostProcessing = false;
            src.renderShadows = false;
            cam.depth = eye.depth - 200f;
            var listener = cam.GetComponent<AudioListener>();
            if (listener != null) { listener.enabled = false; head.gameObject.AddComponent<AudioListener>(); }

            if (VrMode.Headset)
            {
                var tpd = head.gameObject.AddComponent<TrackedPoseDriver>();
                tpd.positionInput = new InputActionProperty(new InputAction("head position", binding: "<XRHMD>/centerEyePosition", expectedControlType: "Vector3"));
                tpd.rotationInput = new InputActionProperty(new InputAction("head rotation", binding: "<XRHMD>/centerEyeRotation", expectedControlType: "Quaternion"));
                leftHand = Hand("VR Left Hand", "LeftHand");
                rightHand = Hand("VR Right Hand", "RightHand");
                laser = rightHand.gameObject.AddComponent<LineRenderer>();
                laser.useWorldSpace = true;
                laser.positionCount = 2;
                laser.widthMultiplier = 0.004f;
                laser.material = VrPanels.ScreenMaterial(3300);
                laser.material.SetColor("_BaseColor", new Color(0.4f, 0.85f, 1f, 0.8f));
                laser.gameObject.layer = UiLayer;
                laser.enabled = false;
            }

            screen = new GameObject("VR Screen").transform;
            screen.SetParent(transform, false);
            panels = new VrPanels(screen, UiLayer);
            mapScreen = GameObject.CreatePrimitive(PrimitiveType.Quad).transform;
            mapScreen.name = "VR Star Map";
            Destroy(mapScreen.GetComponent<Collider>());
            mapScreen.gameObject.layer = UiLayer;
            mapScreen.SetParent(screen, false);
            mapScreen.localPosition = new Vector3(0f, 0f, 0.002f);
            mapMaterial = VrPanels.ScreenMaterial(3050);
            mapScreen.GetComponent<MeshRenderer>().sharedMaterial = mapMaterial;
            mapScreen.gameObject.SetActive(false);
            if (!flight && FindAnyObjectByType<World.StationLevel>() != null) gameObject.AddComponent<VrStation>().Init(this);
            if (flight)
            {
                var cockpit = new GameObject("VR Cockpit");
                cockpit.transform.SetParent(transform, false);
                cockpit.AddComponent<VrCockpit>().Init(this, panels);
            }
            Follow();
        }

        Transform Hand(string name, string usage)
        {
            var t = new GameObject(name).transform;
            t.SetParent(transform, false);
            var tpd = t.gameObject.AddComponent<TrackedPoseDriver>();
            var pos = new InputAction(name + " position", expectedControlType: "Vector3");
            pos.AddBinding($"<XRController>{{{usage}}}/pointerPosition");
            pos.AddBinding($"<XRController>{{{usage}}}/devicePosition");
            var rot = new InputAction(name + " rotation", expectedControlType: "Quaternion");
            rot.AddBinding($"<XRController>{{{usage}}}/pointerRotation");
            rot.AddBinding($"<XRController>{{{usage}}}/deviceRotation");
            tpd.positionInput = new InputActionProperty(pos);
            tpd.rotationInput = new InputActionProperty(rot);
            // A small handle so the hands are visible.
            var model = GameObject.CreatePrimitive(PrimitiveType.Cube);
            Destroy(model.GetComponent<Collider>());
            model.layer = UiLayer;
            model.transform.SetParent(t, false);
            model.transform.localScale = new Vector3(0.035f, 0.035f, 0.12f);
            model.transform.localPosition = new Vector3(0f, 0f, -0.05f);
            return t;
        }

        void OnDestroy()
        {
            panels?.Release();
            if (mapTexture != null) { mapTexture.Release(); Destroy(mapTexture); }
            if (mapMaterial != null) Destroy(mapMaterial);
            if (Current == this) Current = null;
        }

        void LateUpdate()
        {
            if (logical == null) return;
            Follow();
            panels.Update();
            PlaceScreen();
            UpdateMap();
            UpdatePointer();
        }

        /// <summary>The rig on the logical camera: its whole pose in flight, else its position and yaw.</summary>
        void Follow()
        {
            var t = logical.transform;
            if (flight) transform.SetPositionAndRotation(t.position, t.rotation);
            else transform.SetPositionAndRotation(t.position, Quaternion.Euler(0f, t.eulerAngles.y, 0f));
            if (!VrMode.Headset)
            {
                // The simulation: the eye matches the logical camera (+ the right-drag look).
                var mouse = Mouse.current;
                if (mouse != null && mouse.rightButton.isPressed)
                {
                    simLook += mouse.delta.ReadValue() * 0.15f;
                    simLook.y = Mathf.Clamp(simLook.y, -80f, 80f);
                }
                else simLook = Vector2.Lerp(simLook, Vector2.zero, Time.unscaledDeltaTime * 4f);
                if (DebugLook.HasValue) simLook = DebugLook.Value;
                var baseRot = flight ? Quaternion.identity : Quaternion.Inverse(transform.rotation) * t.rotation;
                head.localRotation = baseRot * Quaternion.Euler(-simLook.y, simLook.x, 0f);
                eye.fieldOfView = logical.fieldOfView;
            }
        }

        /// <summary>The floating screen 2 m ahead: in flight and in the simulation as big as the logical camera's view at that
        /// distance (the HUD's markers line up), else 1.9 m wide.</summary>
        void PlaceScreen()
        {
            float aspect = panels.Aspect;
            float height, width;
            if (flight || !VrMode.Headset)
            {
                height = 2f * ScreenDistance * Mathf.Tan(logical.fieldOfView * 0.5f * Mathf.Deg2Rad);
                width = height * aspect;
            }
            else
            {
                width = ScreenWidth;
                height = width / aspect;
            }
            // The simulation outside flight: the eye looks along the logical camera (its pitch too), the screen in front of it.
            screen.localRotation = !VrMode.Headset && !flight ? Quaternion.Inverse(transform.rotation) * logical.transform.rotation : Quaternion.identity;
            screen.localPosition = screen.localRotation * new Vector3(0f, 0f, ScreenDistance);
            screen.localScale = new Vector3(width, height, 1f);
        }

        /// <summary>The star map's own camera into a texture on the screen; the eye sees only the VR layer meanwhile.</summary>
        void UpdateMap()
        {
            var map = StarMap.Current;
            var cam = map != null ? map.MapCamera : null;
            if (cam != mapCamera)
            {
                mapCamera = cam;
                if (cam != null)
                {
                    if (mapTexture == null || mapTexture.width != UnityEngine.Screen.width || mapTexture.height != UnityEngine.Screen.height)
                    {
                        if (mapTexture != null) { mapTexture.Release(); Destroy(mapTexture); }
                        mapTexture = new RenderTexture(Mathf.Max(64, UnityEngine.Screen.width), Mathf.Max(64, UnityEngine.Screen.height), 24, RenderTextureFormat.ARGB32);
                        mapTexture.Create();
                    }
                    cam.targetTexture = mapTexture;
                    cam.stereoTargetEye = StereoTargetEyeMask.None;
                    mapMaterial.SetTexture("_BaseMap", mapTexture);
                }
            }
            bool open = mapCamera != null;
            mapScreen.gameObject.SetActive(open);
            // StarMap switches every camera off while open: the eye comes back, seeing only the screens.
            if (open && !eye.enabled) eye.enabled = true;
            eye.cullingMask = open ? 1 << UiLayer : eyeMask;
            eye.clearFlags = open ? CameraClearFlags.SolidColor : eyeClear;
            eye.backgroundColor = open ? Color.black : eyeBackground;
        }

        /// <summary>The pointer's ray past the UI into the world this frame (VrStation: the ship, the visitors), null = on the
        /// UI or nothing to point at.</summary>
        public Ray? WorldPointer { get; private set; }
        /// <summary>The pointer's select this frame: the right trigger (a headset) or the left mouse button (the simulation).</summary>
        public bool SelectPressed { get; private set; }
        bool selectWasDown;

        /// <summary>The laser to 'point' (VrStation, after the rig: a visitor or the ship under it).</summary>
        public void ShowLaserTo(Vector3 point)
        {
            if (laser == null || rightHand == null) return;
            laser.enabled = true;
            laser.SetPosition(0, rightHand.position);
            laser.SetPosition(1, point);
        }

        /// <summary>The pointer: a headset's right controller (its laser), or the simulation's mouse through the eye. Over a UI
        /// element on the screen it is the UI's (VrPad's virtual mouse, the trigger clicks); elsewhere it points into the world.
        /// In flight only while a menu, conversation or map halts the flight controls (else the trigger fires).</summary>
        void UpdatePointer()
        {
            WorldPointer = null;
            bool down;
            Ray ray;
            if (VrMode.Headset)
            {
                if (rightHand == null) return;
                ray = new Ray(rightHand.position, rightHand.forward);
                down = VrPad.RightTrigger > 0.6f;
            }
            else
            {
                var mouse = Mouse.current;
                if (mouse == null) return;
                ray = eye.ScreenPointToRay(mouse.position.ReadValue());
                down = mouse.leftButton.isPressed;
            }
            SelectPressed = down && !selectWasDown;
            selectWasDown = down;
            if (laser != null) laser.enabled = false;
            if (flight && !Flight.Navigation.InputHalted) { VrPad.SetPointer(false, default, false, 0f); return; }
            bool onScreen = HitScreen(ray, out Vector2 uv, out float distance);
            bool ui = onScreen && panels.UiAt(uv);
            if (ui && laser != null)
            {
                laser.enabled = true;
                laser.SetPosition(0, ray.origin);
                laser.SetPosition(1, ray.GetPoint(Mathf.Min(distance, LaserLength)));
            }
            if (!ui) WorldPointer = ray;
            if (VrMode.Headset)
            {
                var pixel = new Vector2(uv.x * UnityEngine.Screen.width, uv.y * UnityEngine.Screen.height);
                VrPad.SetPointer(onScreen, pixel, ui && down, 0f);
            }
        }

        /// <summary>Where 'ray' hits the floating screen: (u, v) from its bottom-left corner.</summary>
        public bool HitScreen(Ray ray, out Vector2 uv, out float distance)
        {
            uv = default;
            distance = 0f;
            var plane = new Plane(-screen.forward, screen.position);
            if (!plane.Raycast(ray, out distance) || distance <= 0f) return false;
            var local = screen.InverseTransformPoint(ray.GetPoint(distance));
            if (Mathf.Abs(local.x) > 0.5f || Mathf.Abs(local.y) > 0.5f) return false;
            uv = new Vector2(local.x + 0.5f, local.y + 0.5f);
            return true;
        }
    }
}
