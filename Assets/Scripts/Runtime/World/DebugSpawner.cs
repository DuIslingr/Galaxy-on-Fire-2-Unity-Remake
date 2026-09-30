// DebugSpawner.cs
// Remake-only testing tools for the pause menu's Debug page (CheatsCatalog.Spawns): put any ship (race, model, behaviour) or any
// assembled object (assemblies.json: ships, stations, level props, effects...) in front of the player. Spawned ships are ordinary
// traffic (Traffic.SpawnShip: they fight, drop loot, count for the music); objects are plain scenery (no collision, no lock)
// that stays until the level is left. Nothing here is in the original.

using GoF2Remake.Data;
using GoF2Remake.Flight;
using GoF2Remake.Visuals;
using UnityEngine;

namespace GoF2Remake.World
{
    public static class DebugSpawner
    {
        const float M = 0.05f;

        public enum Behaviour { Hostile, Normal, Friendly }

        static Vector3 ToGame(Vector3 unity) => new Vector3(unity.x, unity.y, -unity.z) / M;

        /// <summary>Ship 'ship' of 'race' 400 m ahead of the player (hostile / by the standings / friendly); the result text.</summary>
        public static string SpawnShip(SpaceLevel level, int race, int ship, Behaviour behaviour)
        {
            if (level == null || level.Traffic == null || level.Player == null) return Localization.Extra("debugNoFlight", "Only in flight.");
            var p = level.Player.transform;
            var spec = new SpawnSpec
            {
                group = NpcGroup.Raider,
                race = race,
                ship = ship,
                freighter = ship == 15,
                position = ToGame(p.position + p.forward * 400f + p.up * 40f),
                alwaysEnemy = behaviour == Behaviour.Hostile,
                alwaysFriend = behaviour == Behaviour.Friendly,
            };
            var s = level.Traffic.SpawnShip(spec);
            level.Traffic.ConnectPlayers();   // the new ship and the others see each other (targets, hit lists)
            string name = ShipName(level.Database, ship);
            return s != null ? string.Format(Localization.Extra("debugShipSpawned", "{0} spawned."), name)
                             : string.Format(Localization.Extra("debugSpawnFailed", "{0} couldn't be spawned."), name);
        }

        /// <summary>An assembled object ahead of the player, far enough out for its size, facing the player; the result text.</summary>
        public static string SpawnObject(SpaceLevel level, string assembly)
        {
            if (level == null || level.Player == null) return Localization.Extra("debugNoFlight", "Only in flight.");
            var prefab = AssembledObject.LoadPrefab(level.Database.AssemblyByName(assembly));
            if (prefab == null) return string.Format(Localization.Extra("debugSpawnFailed", "{0} couldn't be spawned."), assembly);
            var p = level.Player.transform;
            var go = Object.Instantiate(prefab, p.position, Quaternion.LookRotation(-p.forward, p.up));
            go.name = "Debug " + assembly;
            var bounds = new Bounds(go.transform.position, Vector3.zero);
            foreach (var r in go.GetComponentsInChildren<Renderer>()) bounds.Encapsulate(r.bounds);
            float radius = Mathf.Max(bounds.extents.magnitude, 5f);
            go.transform.position += p.forward * (radius + 150f) + (go.transform.position - bounds.center);
            return string.Format(Localization.Extra("debugObjectSpawned", "{0} spawned ({1:0} m across)."), assembly, radius * 2f);
        }

        public static string ShipName(Database db, int ship)
        {
            string name = Localization.Get(913 + ship);
            return string.IsNullOrEmpty(name) ? db.Ship(ship)?.name ?? ("#" + ship) : name;
        }
    }
}
