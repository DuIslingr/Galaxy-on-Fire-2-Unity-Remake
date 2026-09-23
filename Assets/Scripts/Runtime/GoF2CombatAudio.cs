// GoF2CombatAudio.cs
// Combat sounds that aren't tied to one weapon (weapons.md section 5): asteroid destroyed (event 21),
// target lock acquired (event 26); and the mining ones (mining.md 4.8): drill loop (1), landing (2), drill off target (3),
// autopilot on / off (28 / 29). Resources/GoF2Weapons/CombatAudio, made by GoF2 > Build Weapon Fx.

using UnityEngine;

namespace GoF2Remake.Flight
{
    public class GoF2CombatAudio : ScriptableObject
    {
        public AudioClip asteroidDestroyed;
        public AudioClip targetLock;
        public AudioClip miningDrill;
        public AudioClip miningLanding;
        public AudioClip miningDrillBroken;
        public AudioClip autopilotOn;
        public AudioClip autopilotOff;
        public AudioClip jumpToPlanet;   // 5 Jump_to_planets (autopilot_travel.md 3.5)

        public static GoF2CombatAudio Load() => Resources.Load<GoF2CombatAudio>($"{GoF2WeaponFx.ResourcesFolder}/CombatAudio");
    }
}
