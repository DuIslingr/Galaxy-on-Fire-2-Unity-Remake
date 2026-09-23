// GoF2Sfx.cs
// One-shot sound effects in space. Distances are kilometres, so instead of Unity's 3D rolloff the volume falls off
// linearly with the distance to the camera (the original plays FMOD events at the ship position when 3D sound is on).

using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Flight
{
    public static class GoF2Sfx
    {
        public const float AudibleMeters = 3000f;   // silent beyond (60000 game units)

        public static void PlayAt(AudioClip clip, Vector3 position, float volume = 1f)
        {
            if (clip == null) return;
            var cam = Camera.main;
            float d = cam != null ? Vector3.Distance(cam.transform.position, position) : 0f;
            float v = volume * Mathf.Clamp01(1f - d / AudibleMeters) * GoF2Settings.SfxVolume;
            if (v <= 0.01f) return;
            var go = new GameObject("Sfx " + clip.name);
            go.transform.position = position;
            var src = go.AddComponent<AudioSource>();
            src.clip = clip;
            src.volume = v;
            src.spatialBlend = 0f;
            src.Play();
            Object.Destroy(go, clip.length + 0.1f);
        }
    }
}
