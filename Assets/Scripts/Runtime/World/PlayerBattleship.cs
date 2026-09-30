// PlayerBattleship.cs
// Remake-only debug toy (the Debug page's "Fly the Terran battleship", Cheats.ToggleBattleship): the player flies ship 14, the
// Terran battleship the original only ever has as a stationary NPC (TrafficPlan: 30 % of the Terran orbits with freighters),
// with its 7 turrets (TrafficPlan.BattleshipTurrets, Level::createStaticObject 0x1a74: turret_002_static, scale 6) riding on the
// hull as the player's own auto turrets: they shoot whatever is hostile to the player and never hit the player
// (NpcShip.MakePlayerTurret). The chase camera and the hangar's turntable are scaled to the hull's size. The ship keeps
// ships.json's stats (100 hull, handling 50). Nothing here is in the original.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    public static class PlayerBattleship
    {
        public const int Ship = 14;
        const float M = 0.05f;

        public static bool Active => Session.ShipIndex == Ship;

        static float Radius(Transform model)
        {
            if (model == null) return 0f;
            var b = new Bounds(model.position, Vector3.zero);
            foreach (var r in model.GetComponentsInChildren<Renderer>()) b.Encapsulate(r.bounds);
            return b.extents.magnitude;
        }

        /// <summary>The model's bounds in its parent's (the player root's) space, from every renderer's local bounds.</summary>
        static Bounds LocalBounds(Transform root, Transform model)
        {
            bool any = false;
            var b = new Bounds();
            var toRoot = root.worldToLocalMatrix;
            foreach (var r in model.GetComponentsInChildren<Renderer>())
            {
                var lb = r.localBounds;
                var m = toRoot * r.transform.localToWorldMatrix;
                for (int i = 0; i < 8; i++)
                {
                    var corner = lb.center + Vector3.Scale(lb.extents, new Vector3((i & 1) == 0 ? -1 : 1, (i & 2) == 0 ? -1 : 1, (i & 4) == 0 ? -1 : 1));
                    var p = m.MultiplyPoint3x4(corner);
                    if (!any) { b = new Bounds(p, Vector3.zero); any = true; } else b.Encapsulate(p);
                }
            }
            return b;
        }

        /// <summary>The player's model and chase camera for the ship flown: the battleship's model (its pivot is at the bow) is
        /// shifted so the ship turns around its middle, and the camera sits just behind the stern and above the deck; any
        /// other ship gets the original's offsets (TargetFollowCamera: (0, 600, -1338) / (0, 600, -650) units).</summary>
        public static void FitCamera(Transform root, Transform model, ChaseCamera chase)
        {
            if (!Active || model == null)
            {
                if (chase != null) { chase.offset = new Vector3(0f, 600f, -1338f) * M; chase.lookOffset = new Vector3(0f, 600f, -650f) * M; }
                return;
            }
            var b = LocalBounds(root, model);
            model.localPosition -= b.center;   // the hull's middle on the pivot
            if (chase == null) return;
            float halfLength = b.extents.z, halfHeight = b.extents.y;
            chase.offset = new Vector3(0f, halfHeight * 1.6f, -halfLength * 1.25f);
            chase.lookOffset = new Vector3(0f, halfHeight * 1.1f, halfLength * 0.1f);
        }

        /// <summary>The hangar's turntable: the hull shrunk to a large ship's size so the hangar camera sees it.</summary>
        public static void FitHangar(Transform ship)
        {
            float r = Radius(ship);
            if (r > 60f) ship.localScale *= 60f / r;
        }

        /// <summary>The player's battleship turrets gone (swapped back to another ship): they vanish without an explosion.</summary>
        public static void RemoveTurrets(SpaceLevel level)
        {
            if (level == null || level.Player == null) return;
            foreach (var t in level.Player.GetComponentsInChildren<NpcShip>(true))
            {
                if (!t.PlayerOwned) continue;
                t.Vanish();
                t.transform.SetParent(null, true);
                t.gameObject.SetActive(false);
            }
        }

        /// <summary>The Debug page's toggle in flight: the battleship at the player's place (the old hull gone, the player
        /// flying it at once), or back to the ship flown before; docked it only changes the ship (the hangar shows it).</summary>
        public static string Toggle(SpaceLevel level)
        {
            bool toBattleship = !Active;
            int ship = toBattleship ? Ship : PlayerPrefs.GetInt("cheat_previousShip", 10);
            if (toBattleship) PlayerPrefs.SetInt("cheat_previousShip", Session.ShipIndex);
            if (level != null) level.SwapPlayerShip(ship);
            else Session.ShipIndex = ship;
            return toBattleship ? Localization.Extra("cheatBattleshipOn", "You fly the Terran battleship.")
                                : Localization.Extra("cheatBattleshipOff", "Back in your own ship.");
        }

        /// <summary>The 7 turrets on the player's hull, after the level's traffic exists (they are traffic turrets).</summary>
        public static void AttachTurrets(SpaceLevel level)
        {
            if (level == null || level.Traffic == null || level.Player == null) return;
            var root = level.Player.transform;
            // The NPC battleship's root faces game +z (NpcShip.GameForward, Euler(0, 180, 0)); the player's faces Unity +z with
            // the same model inside: the turrets' world offsets turn by the inverse of that.
            var toPlayer = Quaternion.Inverse(Quaternion.Euler(0f, 180f, 0f));
            foreach (var (pos, rot) in TrafficPlan.BattleshipTurrets)
            {
                var spec = new SpawnSpec
                {
                    group = NpcGroup.Turret, race = 0, ship = -1, turretAssembly = "turret_002_static", scale = 6f, hitpoints = 1000,
                    noLoot = true, nameText = 1666, stationary = true, alwaysFriend = true, rotation = rot, radarHidden = true,
                    position = new Vector3(root.position.x, root.position.y, -root.position.z) / M,
                };
                var t = level.Traffic.SpawnShip(spec);
                if (t == null) continue;
                // On the model, not the root: ShipController banks and pitches the model when turning (and Mining / the death
                // tumble turn it), so the turrets ride with the hull. The offsets are from the model's own origin (the bow),
                // in its unscaled space (the prefab is x2).
                var model = level.Player.visualModel;
                var offset = toPlayer * (new Vector3(pos.x, pos.y, -pos.z) * M);
                var turn = toPlayer * OrbitLayout.RotationToUnity(rot);
                if (model != null)
                {
                    float scale = Mathf.Max(0.0001f, model.localScale.x);
                    t.transform.SetParent(model, false);
                    t.transform.localPosition = offset / scale;
                    t.transform.localRotation = turn;
                    t.transform.localScale = Vector3.one / scale;
                }
                else
                {
                    t.transform.SetParent(root, false);
                    t.transform.localPosition = offset;
                    t.transform.localRotation = turn;
                }
                t.Target.invulnerable = true;
                t.Target.radius = 0f;
                t.Target.untargetable = true;
                t.MakePlayerTurret();
            }
            level.Traffic.ConnectPlayers();   // the turrets' target lists (every other race's ship)
        }
    }
}
