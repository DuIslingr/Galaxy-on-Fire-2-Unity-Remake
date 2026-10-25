// CapitalRetreat.cs
// Remake mods: a mod capital ship that jumps away instead of being destroyed (ships.json "retreat": true; EVERSPACE 2's
// Dreadnought: BP_Encounter_Dreadnought_Base's OnHealthDepleted -> StartEnemyJumpOut, BeforeDreadnoughtJumpsOut,
// BP_Dreadnought's SpawnJumpEffect). Added by Traffic.Create next to its NpcShip. When a hit would take its hull to 0 it keeps
// 1 (Target.SaveFromDeath) and from then on:
//   - it is invulnerable and holds its fire, its subsystems too (CapitalSubsystems.Halt: no more launches, the fighters its
//     hangars launched jump out, ES2's StartEnemyJumpOut);
//   - its jump drive charges ChargeMs (the Khador Drive's charge sound 33 at it, "<name> is jumping away!");
//   - the khador_jump fx (SystemJump.SpawnKhadorFx) grows to its size ahead of its bow, sound 32, and the ship pushes forward
//     into it, gone (NpcShip.Vanish, its parts with it) at the fx's HideMs like the player's ship (SystemJump: 1700 ms).
// Nobody's kill (an event's ships count it as gone; a mission's alive("<name>") falls to 0 once it has jumped): no explosion,
// wreck or crate. Only the game running the orbit's NPCs runs it; another player sees its copy vanish (no fx there yet).

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.UI;
using UnityEngine;

namespace GoF2Remake.World
{
    public class CapitalRetreat : MonoBehaviour
    {
        const float ChargeMs = 4000f;
        const float HideMs = 1700f;          // SystemJump: the ship vanishes 1700 ms into the khador_jump fx
        const float FighterMeters = 60f;     // SystemJump.SpawnKhadorFx's size is a fighter's: grown by the ship's size over this

        NpcShip host;
        Traffic traffic;
        float ms = -1f, speed;
        bool jumped;
        GameObject fx;
        float fxLengthMs;

        /// <summary>Retreating (hull depleted, charging or jumping).</summary>
        public bool Retreating => ms >= 0f;

        public static CapitalRetreat Attach(NpcShip host, Traffic traffic)
        {
            var c = host.gameObject.AddComponent<CapitalRetreat>();
            c.host = host; c.traffic = traffic;
            host.Target.SaveFromDeath = c.Save;
            return c;
        }

        bool Save()
        {
            if (jumped || host == null) return false;
            if (host.Hp != null) host.Hp.hull = Mathf.Max(1, host.Hp.hull);
            host.Target.hp = Mathf.Max(1f, host.Target.hp);
            if (Retreating) return true;
            ms = 0f;
            host.Target.invulnerable = true;
            host.shootingEnabled = false;
            GetComponent<CapitalSubsystems>()?.Halt();
            var assets = StarMapAssets.Load();
            if (assets != null) Sfx.PlayAt(assets.jumpgateCharge, host.transform.position);
            traffic.Warn(string.Format(Localization.Extra("capitalRetreats", "{0} is jumping away!"), host.Target.displayName ?? GameNames.Ship(host.Spec.ship)));
            return true;
        }

        void Update()
        {
            if (!Retreating || jumped || host == null || host.Gone) return;
            float dtMs = Time.deltaTime * 1000f;
            ms += dtMs;
            if (ms < ChargeMs) return;
            if (fxLengthMs <= 0f) StartJump();
            float into = ms - ChargeMs;
            // into the flash, faster and faster
            speed *= Mathf.Pow(1.1f, dtMs / 33.3f);
            host.transform.position += host.transform.forward * speed * Time.deltaTime;
            if (into >= HideMs)
            {
                jumped = true;
                GetComponent<CapitalSubsystems>()?.LeaveWithHost();
                host.Target.killedByNpc = true;
                host.Vanish();
            }
        }

        void StartJump()
        {
            float size = Size();
            speed = size * 0.05f;   // metres a second at first
            var assets = StarMapAssets.Load();
            var t = host.transform;
            var at = t.position + t.forward * size * 0.6f;
            fx = SystemJump.SpawnKhadorFx(assets, at, Quaternion.LookRotation(-t.forward, t.up), out fxLengthMs);
            if (fx != null)
            {
                fx.transform.localScale *= Mathf.Max(1f, size / FighterMeters);
                Destroy(fx, fxLengthMs / 1000f + 0.5f);
            }
            if (assets != null) Sfx.PlayAt(assets.khadorDrive, at);
            if (fxLengthMs <= 0f) fxLengthMs = 1f;
        }

        /// <summary>The ship's largest extent in metres (its renderers, not the glow layers).</summary>
        float Size()
        {
            var b = new Bounds(host.transform.position, Vector3.zero);
            foreach (var r in host.GetComponentsInChildren<MeshRenderer>())
                if (!r.name.Contains("engine") && !r.name.EndsWith("_add")) b.Encapsulate(r.bounds);
            return Mathf.Max(FighterMeters, Mathf.Max(b.size.x, Mathf.Max(b.size.y, b.size.z)));
        }
    }
}
