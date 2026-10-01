// CutsceneCamera.cs
// The LevelScript cutscene camera (Reference/research/levelscript_cutscenes.md 1): TargetFollowCamera in look-at mode
// (setLookAtCam(true) + setTarget + setPosition): a fixed position looking at a target, moved every frame by
// TargetFollowCamera::translate(dx, dy, dz) (a world-space dolly, game units per ms) and shaken by
// setRumblePercentage (the look-at point jitters by p * (rnd(100) - 50) units per axis). Release = resetCamera: the chase
// camera takes over again. Plain C#, driven by CampaignLevel's LateUpdate.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.World
{
    public class CutsceneCamera
    {
        const float M = 0.05f;

        readonly Camera cam;
        readonly ChaseCamera chase;
        Transform target;
        Vector3 lookPoint, dolly;

        public bool Active { get; private set; }
        /// <summary>setRumblePercentage: 0..1.</summary>
        public float Rumble { get; set; }
        public Transform Camera => cam != null ? cam.transform : null;

        public CutsceneCamera(Camera camera)
        {
            cam = camera;
            chase = camera != null ? camera.GetComponent<ChaseCamera>() : null;
        }

        static Vector3 ToUnity(Vector3 game) => new Vector3(game.x, game.y, -game.z) * M;

        /// <summary>Look-at mode from a game-space position at a target (or a fixed point when 'follow' is null).</summary>
        public void LookAt(Vector3 gamePosition, Transform follow, Vector3 unityPoint = default) => LookAtUnity(ToUnity(gamePosition), follow, unityPoint);

        public void LookAtUnity(Vector3 unityPosition, Transform follow, Vector3 unityPoint = default)
        {
            if (cam == null) return;
            Active = true;
            if (chase != null) { chase.enabled = false; chase.scriptCamera = true; }
            cam.transform.position = unityPosition;
            target = follow;
            lookPoint = unityPoint;
            dolly = Vector3.zero;
            cam.fieldOfView = Aspect.VerticalFov(1.22f * Mathf.Rad2Deg, cam.aspect);
            Aim(0f);
        }

        /// <summary>Only the target changes (the camera stays where it is).</summary>
        public void SetTarget(Transform follow) => target = follow;

        /// <summary>TargetFollowCamera::translate per ms (game units).</summary>
        public void SetDolly(Vector3 gamePerMs) => dolly = gamePerMs;

        /// <summary>resetCamera: back to the chase camera.</summary>
        public void Release()
        {
            Active = false;
            Rumble = 0f;
            dolly = Vector3.zero;
            if (chase != null) { chase.scriptCamera = false; chase.enabled = true; chase.Snap(); }
        }

        public void LateTick(float dtMs)
        {
            if (!Active || cam == null) return;
            cam.transform.position += ToUnity(dolly) * dtMs;
            Aim(dtMs);
        }

        void Aim(float dtMs)
        {
            var look = target != null ? target.position : lookPoint;
            if (Rumble > 0f && dtMs > 0f)   // paused (dt 0): no jitter, like TargetFollowCamera::update
                look += new Vector3(Random.Range(0, 100) - 50, Random.Range(0, 100) - 50, Random.Range(0, 100) - 50) * (Rumble * M * Settings.CameraShake);
            var d = look - cam.transform.position;
            if (d.sqrMagnitude > 1e-6f) cam.transform.rotation = Quaternion.LookRotation(d, Vector3.up);
        }
    }
}
