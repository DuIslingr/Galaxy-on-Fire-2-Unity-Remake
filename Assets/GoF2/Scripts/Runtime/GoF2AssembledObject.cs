// GoF2AssembledObject.cs
// Root component of an assembled prefab (Prefabs/Assembled/...): one game object (ship, station, jumpgate,
// asteroid, hangar...) put together from its separate game meshes the way the original code does it
// (AEGeometry root mesh + addChild meshes + setLodMeshes). Built by "GoF2 > Build Assembled Prefabs"
// from Resources/GoF2Data/assemblies.json.

using UnityEngine;

namespace GoF2Remake.Visuals
{
    public class GoF2AssembledObject : MonoBehaviour
    {
        [Tooltip("Resource id of the root (LOD 0) mesh.")]
        public int rootMeshId;

        [Tooltip("Where the composition rule comes from in the decompiled code.")]
        public string origin;

        [Tooltip("Original LOD switch distances in game units (the LODGroup approximates these for the reference FOV).")]
        public float[] lodDistancesGameUnits;

        [Tooltip("Original last-visible distance in game units (0 = always visible).")]
        public float lastVisibleDistanceGameUnits;

        [Tooltip("Separate object the game spawns when this one is destroyed (e.g. *_explosion_anim).")]
        public GameObject explosionPrefab;

        [Tooltip("Parts only used when this is the player's own ship (Globals::getShipGroup param_3 = true).")]
        public GameObject[] playerVariantParts;

        [Tooltip("Parts only used for NPC ships (Globals::getShipGroup param_3 = false).")]
        public GameObject[] npcVariantParts;

        [Tooltip("Parts the game only shows under a condition (mission state, race, random, graphics option).")]
        public GameObject[] conditionalParts;

        [Tooltip("The condition for each entry of conditionalParts, as recovered from the code.")]
        public string[] conditions;

        [Tooltip("Rotation the game applies to the whole object when it places it (engine-space euler degrees). " +
                 "Not baked into the prefab, which stays in model space.")]
        public Vector3 spawnRotationEngine;

        /// <summary>Switches between the player and NPC parts (engine meshes etc.).</summary>
        public void SetPlayerVariant(bool player)
        {
            if (playerVariantParts != null) foreach (var g in playerVariantParts) if (g != null) g.SetActive(player);
            if (npcVariantParts != null) foreach (var g in npcVariantParts) if (g != null) g.SetActive(!player);
        }
    }
}
