// GoF2CombatAudio.cs
// Combat sounds that aren't tied to one weapon (weapons.md section 5): asteroid destroyed (event 21),
// target lock acquired (event 26). Resources/GoF2Weapons/CombatAudio, made by GoF2 > Build Weapon Fx.

using UnityEngine;

namespace GoF2Remake.Flight
{
    public class GoF2CombatAudio : ScriptableObject
    {
        public AudioClip asteroidDestroyed;
        public AudioClip targetLock;

        public static GoF2CombatAudio Load() => Resources.Load<GoF2CombatAudio>($"{GoF2WeaponFx.ResourcesFolder}/CombatAudio");
    }
}
