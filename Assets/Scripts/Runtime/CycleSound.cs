// CycleSound.cs
// An FMOD complex event driven by a self-running looping parameter (velocity v/s, "loop behaviour loop": a 1 / v s cycle),
// as the FEV's LGCY data describes it (Reference/tools/audio/fev_lgcy.py): looped layers that play all the time, and
// oneshot sound instances at fixed points of the cycle, each a random wave of its sound definition. Gains are the sound
// instance's volume x its layer's volume envelope at the event's (fixed) parameters; the event volume x Sfx.EventGain on top.
// Plain C#: the owner hands in a host GameObject and calls Update every frame. The events built here:
//   153 Mothership_Xplosion_Loop (0.1/s; "time" = 0.5, LevelScript::process state 6), 122 Station_Atmo_Mainview (0.1/s),
//   95 Station_Atmo_Hangar and 108 Station_Atmo_Lounge (0.05/s).

using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    public class CycleSound
    {
        public struct Loop { public AudioClip clip; public float gain; }
        public struct Add { public float at; public AudioClip[] clips; public float gain; }

        readonly AudioSource[] loopSources;
        readonly float[] loopGains;
        readonly AudioSource adds;
        readonly Add[] addList;
        readonly float cyclePerMs, eventVolume;
        float cycle;
        bool playing;

        public CycleSound(GameObject host, float cyclesPerSecond, float eventVolume, Loop[] loops, Add[] addList)
        {
            cyclePerMs = cyclesPerSecond / 1000f;
            this.eventVolume = eventVolume;
            this.addList = addList ?? new Add[0];
            loops = loops ?? new Loop[0];
            loopSources = new AudioSource[loops.Length];
            loopGains = new float[loops.Length];
            for (int i = 0; i < loops.Length; i++)
            {
                var s = host.AddComponent<AudioSource>();
                s.playOnAwake = false; s.loop = true; s.spatialBlend = 0f; s.clip = loops[i].clip;
                loopSources[i] = s;
                loopGains[i] = loops[i].gain;
            }
            adds = host.AddComponent<AudioSource>();
            adds.playOnAwake = false; adds.spatialBlend = 0f;
        }

        public bool IsPlaying => playing;

        float Volume => eventVolume * Sfx.EventGain * Settings.SfxVolume;

        public void Play()
        {
            playing = true;
            cycle = 0f;
            for (int i = 0; i < loopSources.Length; i++)
                if (loopSources[i].clip != null) { loopSources[i].volume = loopGains[i] * Volume; loopSources[i].Play(); }
        }

        public void Stop()
        {
            playing = false;
            foreach (var s in loopSources) s.Stop();
            adds.Stop();
        }

        public void Update(float dtMs)
        {
            if (!playing) return;
            float before = cycle;
            cycle += dtMs * cyclePerMs;
            bool wrapped = cycle >= 1f;
            if (wrapped) cycle -= Mathf.Floor(cycle);
            foreach (var a in addList)
                if (wrapped ? a.at > before || a.at <= cycle : a.at > before && a.at <= cycle) PlayAdd(a);
            for (int i = 0; i < loopSources.Length; i++) loopSources[i].volume = loopGains[i] * Volume;
        }

        void PlayAdd(Add a)
        {
            if (a.clips == null || a.clips.Length == 0) return;
            var clip = a.clips[Random.Range(0, a.clips.Length)];
            if (clip != null) adds.PlayOneShot(clip, a.gain * Volume);
        }

        static Add[] At(AudioClip[] clips, float gain, params float[] at) =>
            System.Array.ConvertAll(at, t => new Add { at = t, clips = clips, gain = gain });

        static Add[] Join(params Add[][] parts)
        {
            var list = new System.Collections.Generic.List<Add>();
            foreach (var p in parts) list.AddRange(p);
            return list.ToArray();
        }

        /// <summary>153: three loops at their "time" 0.5 gains, Add_01 at 0.047 / 0.436 / 0.826 (0.259), Add_02 at 0.117 /
        /// 0.581 (0.137); event volume 0.672.</summary>
        public static CycleSound Mothership(GameObject host, AudioClip[] loops, AudioClip[] add1, AudioClip[] add2)
        {
            float[] gains = { 0.635f, 0.26f, 0.198f };
            var l = new Loop[loops != null ? Mathf.Min(loops.Length, 3) : 0];
            for (int i = 0; i < l.Length; i++) l[i] = new Loop { clip = loops[i], gain = gains[i] };
            return new CycleSound(host, 0.1f, 0.672f, l, Join(At(add1, 0.259f, 0.047f, 0.4362f, 0.8255f), At(add2, 0.137f, 0.1174f, 0.5805f)));
        }

        /// <summary>156 Spaceship_Engine_05_Broken (the prologue's wreck): the broken engine looped, a random Add wave at
        /// 0.0495 / 0.389 / 0.815 (0.57 / 0.59 / 0.56) of a 3.3 s cycle (0.3/s); event volume 0.268.</summary>
        public static CycleSound BrokenEngine(GameObject host, AudioClip loop, AudioClip[] adds) =>
            new CycleSound(host, 0.3f, 0.268f, new[] { new Loop { clip = loop, gain = 1f } },
                           Join(At(adds, 0.57f, 0.049505f), At(adds, 0.59f, 0.389439f), At(adds, 0.56f, 0.815181f)));

        /// <summary>122: Mainview_1 looped, Add_1 at 0.068 / 0.172 / 0.525 / 0.736 / 0.9 (instance 0.09 x layer 0.5195);
        /// event volume 0.569.</summary>
        public static CycleSound MainView(GameObject host, AudioClip loop, AudioClip[] add) =>
            new CycleSound(host, 0.1f, 0.569f, new[] { new Loop { clip = loop, gain = 1f } },
                           At(add, 0.09f * 0.5195f, 0.06762f, 0.171651f, 0.525358f, 0.736021f, 0.89987f));

        /// <summary>95: Hangar3 looped, the Add_1 / Add_2 definitions (both Add_1..7) at 0.144 / 0.722 and 0.384 / 0.9 (1.0),
        /// 0.251 (0.52) and 0.6 (0.58); event volume 0.331.</summary>
        public static CycleSound Hangar(GameObject host, AudioClip loop, AudioClip[] adds) =>
            new CycleSound(host, 0.05f, 0.331f, new[] { new Loop { clip = loop, gain = 1f } },
                           Join(At(adds, 1f, 0.144118f, 0.383824f, 0.722059f, 0.9f), At(adds, 0.52f, 0.251471f), At(adds, 0.58f, 0.6f)));

        /// <summary>108: Lounge_1 looped; Add_1 (template volume 0.501) at 0.144 / 0.722 (0.47) and 0.251 (0.43), Add_2 at
        /// 0.384 (0.32), 0.9 and 0.6 (0.38); event volume 0.365.</summary>
        public static CycleSound Lounge(GameObject host, AudioClip loop, AudioClip[] add1, AudioClip[] add2) =>
            new CycleSound(host, 0.05f, 0.365f, new[] { new Loop { clip = loop, gain = 1f } },
                           Join(At(add1, 0.47f * 0.501f, 0.144118f, 0.722059f), At(add1, 0.43f * 0.501f, 0.251471f),
                                At(add2, 0.32f, 0.383824f), At(add2, 0.38f, 0.9f, 0.6f)));
    }
}
