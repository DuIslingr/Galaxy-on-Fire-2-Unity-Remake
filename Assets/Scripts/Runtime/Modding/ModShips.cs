// ModShips.cs
// The models of the active mods' ships: each ships.json entry's glTF / GLB file loaded with glTFast (materials through
// ModGltfMaterials) and built into an AssembledObject template (ModShipBuilder), kept under a hidden DontDestroyOnLoad
// holder for the whole run; AssembledObject.LoadPrefab hands the template out for the ship's assembly ("ship_NNN_mod",
// pack "mod"), so every place that shows a ship (hangar, flight, NPCs, the item window, other players) instantiates it
// like a prefab. glTF loading is asynchronous: Preload starts it (the main menu and Bootstrap, again whenever the
// active mods change) and the menu waits for Ready before a game scene loads. A ship whose model isn't there (still
// loading, or broken) shows the Phantom's. Also each ship's shop icon (the entry's "icon" PNG, 180 x 88 like the
// originals; none = the Phantom's).
// The ships load side by side (at most ShipSlots at once: each holds its whole GLB file until glTFast has read it, and the
// GoF3 Ships mod's 79 came to 430 MB): its files are read on worker threads, its textures decoded in the background
// (ModMaterials.PreloadTexture; a GLB's embedded images the same way, ModGltf), its glTF parsed by glTFast's jobs, and the
// main-thread work of all of them shares one time budget per frame (glTFast's TimeBudgetPerFrameDeferAgent), so the game
// keeps running (the main menu's loading screen shows Progress / Current, ModLoading).
// Customizable ships (ModShipKits): a kit's part models load once each (partTemplates), and only those a build uses: the
// kit ships' default builds and the player's saved builds at the start (LoadAll), any other when a build first needs it
// (EnsureBuild / Template start the load; KitPartsLoaded and ModelsChanged follow, and the hangar / flight rebuild the
// player's ship). A kit ship's template is its default build assembled from them; a player's build ("ship_NNN_mod#<build>",
// PlayerHull.Assembly) is assembled the first time Template asks for it (variants, the most recent VariantCap kept).
// A kit's hardpoint models (ModHardpoints: weapons, turret) load with the start's parts, as part templates too.

using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Modding
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class ModShips
    {
        public const string Pack = "mod";
        const int FallbackShip = 10;   // the Phantom

        static readonly Dictionary<int, GameObject> templates = new Dictionary<int, GameObject>();
        static readonly Dictionary<int, Texture2D> icons = new Dictionary<int, Texture2D>();
        static readonly Dictionary<int, string> names = new Dictionary<int, string>();
        static readonly List<GLTFast.GltfImport> imports = new List<GLTFast.GltfImport>();
        static GameObject holder;
        static GLTFast.TimeBudgetPerFrameDeferAgent agent;
        static int loadingRevision = -1, loadedRevision = -1;
        static Task loading;
        static int steps, stepsDone;
        static readonly List<string> current = new List<string>();
        static System.Threading.SemaphoreSlim shipSlots;
        // Kits: the parts' models by "kit key|path", the kit ships, the players' builds made so far.
        static readonly Dictionary<string, GameObject> partTemplates = new Dictionary<string, GameObject>();
        static readonly Dictionary<int, (ModInfo mod, CustomShipData ship, ModShipKits.Kit kit)> kitShips = new Dictionary<int, (ModInfo, CustomShipData, ModShipKits.Kit)>();
        static readonly Dictionary<string, GameObject> variants = new Dictionary<string, GameObject>();
        static readonly Queue<string> variantOrder = new Queue<string>();
        static readonly HashSet<string> partsLoading = new HashSet<string>();   // "kit key|file" being loaded on demand

        /// <summary>Parts a build needed have loaded (the hangar's Customize screen shows the build then).</summary>
        public static event System.Action KitPartsLoaded;
        const int VariantCap = 48;

        /// <summary>Ships loading at once.</summary>
        static System.Threading.SemaphoreSlim ShipSlots => shipSlots ??= new System.Threading.SemaphoreSlim(Application.isMobilePlatform ? 3 : 8);

        /// <summary>How far the models are (0..1; 1 with nothing to load).</summary>
        public static float Progress => steps == 0 ? 1f : Mathf.Clamp01((float)stepsDone / steps);

        /// <summary>A ship being loaded now (its name; null: none).</summary>
        public static string Current => current.Count > 0 ? current[current.Count - 1] : null;

        /// <summary>The ships to load and those done.</summary>
        public static int Count { get; private set; }
        public static int Done { get; private set; }

        /// <summary>The mods' ship models were (re)built: anything that showed a mod ship before (another player's ship built
        /// when they joined, before the session's mods were on) builds it again (NetPlayer).</summary>
        public static event System.Action ModelsChanged;

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics()
        {
            templates.Clear(); icons.Clear(); imports.Clear(); names.Clear();
            partTemplates.Clear(); kitShips.Clear(); variants.Clear(); variantOrder.Clear(); partsLoading.Clear(); KitPartsLoaded = null;
            holder = null; agent = null; loading = null; ModelsChanged = null;
            loadingRevision = loadedRevision = -1;
            steps = stepsDone = 0; current.Clear(); Count = Done = 0;
        }

        /// <summary>The active mods' ship models are built (or there are none).</summary>
        public static bool Ready
        {
            get
            {
                if (loadedRevision == ModManager.Revision) return true;
                if (ModContent.ActiveShips().Count == 0 && ModContent.ModelOverrides().Count == 0 && templates.Count == 0) return true;
                Preload();
                return false;
            }
        }

        /// <summary>Starts building the active mods' ship models when the mods changed since the last time.</summary>
        public static void Preload()
        {
            int rev = ModManager.Revision;
            if (loadingRevision == rev) return;
            loadingRevision = rev;
            loading = LoadAll(rev);
        }

        const int StepsPerShip = 4;   // textures, file, glTF, built

        static async Task LoadAll(int rev)
        {
            Release();
            if (holder == null)
            {
                holder = new GameObject("Mod ship models");
                holder.SetActive(false);
                Object.DontDestroyOnLoad(holder);
            }
            if (agent == null)
            {
                // Active (the holder isn't): the agent measures the frame in its Update.
                var go = new GameObject("Mod ship loader") { hideFlags = HideFlags.HideInHierarchy };
                Object.DontDestroyOnLoad(go);
                agent = go.AddComponent<GLTFast.TimeBudgetPerFrameDeferAgent>();
            }
            agent.SetFrameBudget(0.6f);   // of a frame: the loading screen only animates a bar meanwhile
            var ships = ModContent.ActiveShips();
            ships.AddRange(ModContent.ModelOverrides());   // the originals whose model a mod replaces
            // Customizable ships: their kits' parts load instead of a model of their own.
            var kitted = ships.Where(x => !string.IsNullOrEmpty(x.ship.kit)).ToList();
            ships.RemoveAll(x => !string.IsNullOrEmpty(x.ship.kit));
            var kits = new List<ModShipKits.Kit>();
            foreach (var (mod, c) in kitted)
            {
                var kit = ModShipKits.KitOf(c);
                if (kit == null) { Warn(mod, $"ships.json: \"{c.name}\": no kit \"{c.kit}\" (shipkits.json of a mod that is on)"); continue; }
                kitShips[c.index] = (mod, c, kit);
                if (!kits.Contains(kit)) kits.Add(kit);
            }
            Count = ships.Count + kitted.Count;
            Done = 0;
            // Only the parts the default builds and the player's saved builds use (the rest on demand: EnsureBuild).
            var needed = new Dictionary<ModShipKits.Kit, HashSet<string>>();
            foreach (var kv in kitShips)
            {
                var (_, c, kit) = kv.Value;
                if (!needed.TryGetValue(kit, out var set)) needed[kit] = set = new HashSet<string>();
                set.UnionWith(BuildFiles(kit, ModShipKits.DefaultBuild(c, kit)));
                string key = ModContent.ShipKey(kv.Key);
                if (key != null && Session.ShipBuilds.TryGetValue(key, out var text))
                    set.UnionWith(BuildFiles(kit, ModShipKits.Normalize(kit, c.kitType, ModShipKits.Build.Parse(text), ModShipKits.DefaultBuild(c, kit))));
                set.UnionWith(ModHardpoints.Files(kit));   // the weapon / turret models: few, all at the start
            }
            steps = ships.Count * StepsPerShip + needed.Values.Sum(v => v.Count) + kitted.Count;
            stepsDone = 0;
            current.Clear();
            var watch = System.Diagnostics.Stopwatch.StartNew();
            var tasks = new List<Task>();
            foreach (var (mod, c) in ships) tasks.Add(LoadShip(rev, mod, c));
            foreach (var kit in kits) tasks.Add(LoadKit(rev, kit, needed.TryGetValue(kit, out var files) ? files : new HashSet<string>()));
            await Task.WhenAll(tasks);
            if (rev != ModManager.Revision) return;   // the mods changed meanwhile: a newer load runs
            // The kit ships' default builds (what dealers sell and NPCs fly), their icons and textures.
            foreach (var (mod, c) in kitted)
            {
                try
                {
                    await Task.WhenAll(TexturesOf(c).Select(t => ModMaterials.PreloadTexture(mod, t.path, t.linear, t.readable, t.normal)));
                    if (rev != ModManager.Revision || holder == null) return;
                    var icon = ModMaterials.Texture(mod, c.icon, false);
                    if (icon != null) icons[c.index] = icon;
                    if (!kitShips.TryGetValue(c.index, out var info)) continue;
                    templates[c.index] = Assemble(info.mod, info.ship, info.kit, ModShipKits.DefaultBuild(c, info.kit), c.assembly);
                    names[c.index] = c.name;
                }
                catch (System.Exception e) { Warn(mod, $"ships.json: \"{c.name}\": {e.Message}"); Debug.LogException(e); }
                finally { stepsDone++; Done++; }
            }
            loadedRevision = rev;
            if (ships.Count > 0) Debug.Log($"Mods: {ships.Count} ship model(s) loaded in {watch.ElapsedMilliseconds} ms");
            ModelsChanged?.Invoke();
        }

        /// <summary>The PNGs a ship's entry uses, with how they are read (ModMaterials.FromSpec, the throttle glow masks).</summary>
        static IEnumerable<(string path, bool linear, bool readable, bool normal)> TexturesOf(CustomShipData c)
        {
            if (!string.IsNullOrEmpty(c.icon)) yield return (c.icon, false, false, false);
            if (c.materials != null)
                foreach (var m in c.materials)
                {
                    if (m == null) continue;
                    if (!string.IsNullOrEmpty(m.diffuse)) yield return (m.diffuse, false, false, false);
                    if (!string.IsNullOrEmpty(m.normal)) yield return (m.normal, true, false, true);
                    if (!string.IsNullOrEmpty(m.metallicSmoothness)) yield return (m.metallicSmoothness, true, false, false);
                    if (!string.IsNullOrEmpty(m.emission)) yield return (m.emission, false, false, false);
                    if (!string.IsNullOrEmpty(m.detailAlbedo)) yield return (m.detailAlbedo, true, false, false);
                    if (!string.IsNullOrEmpty(m.detailNormal)) yield return (m.detailNormal, true, false, true);
                }
            if (c.throttleGlow != null && !string.IsNullOrEmpty(c.throttleGlow.mask)) yield return (c.throttleGlow.mask, false, true, false);
            if (c.extraGlows != null)
                foreach (var g in c.extraGlows) if (g != null && !string.IsNullOrEmpty(g.mask)) yield return (g.mask, false, true, false);
        }

        /// <summary>One ship: its textures and model file at once, then glTFast, then the template.</summary>
        static async Task LoadShip(int rev, ModInfo mod, CustomShipData c)
        {
            var slots = ShipSlots;
            await slots.WaitAsync();
            string label = c.name;
            current.Add(label);
            int counted = 0;
            void Step() { counted++; stepsDone++; }
            try
            {
                if (rev != ModManager.Revision) return;
                var textures = new List<Task>();
                foreach (var (path, linear, readable, normal) in TexturesOf(c)) textures.Add(ModMaterials.PreloadTexture(mod, path, linear, readable, normal));
                var file = string.IsNullOrEmpty(c.model) ? Task.FromResult<byte[]>(null) : Task.Run(() => mod.Source.ReadBytes(c.model));
                await Task.WhenAll(textures);
                Step();
                var bytes = await file;
                Step();
                if (rev != ModManager.Revision) return;
                var icon = ModMaterials.Texture(mod, c.icon, false);
                if (icon != null) icons[c.index] = icon;
                if (bytes == null) { Warn(mod, $"ships.json: \"{c.name}\": model {c.model} not found"); return; }
                var import = await ModGltf.Load(mod, bytes, agent);
                bytes = null;
                if (import == null) { Warn(mod, $"{c.model}: not a glTF model glTFast can read"); return; }
                imports.Add(import);
                Step();
                if (rev != ModManager.Revision || holder == null) return;
                var scene = new GameObject("scene");
                scene.transform.SetParent(holder.transform, false);
                if (!await import.InstantiateMainSceneAsync(scene.transform)) { Object.Destroy(scene); Warn(mod, $"{c.model}: no scene to show"); return; }
                if (rev != ModManager.Revision || holder == null) return;
                var template = ModShipBuilder.Build(c, mod, scene);
                template.transform.SetParent(holder.transform, false);
                templates[c.index] = template;
                names[c.index] = c.name;
                Debug.Log($"Mods: {mod.Id}: ship {c.index} \"{c.name}\" built from {c.model}");
            }
            catch (System.Exception e) { Warn(mod, $"{c.model}: {e.Message}"); Debug.LogException(e); }
            finally
            {
                if (rev == ModManager.Revision)
                {
                    stepsDone += StepsPerShip - counted;   // the steps a failed ship skipped
                    Done++;
                }
                current.Remove(label);
                slots.Release();
            }
        }

        /// <summary>A kit's model files: every part's and its tier extensions'.</summary>
        static IEnumerable<string> KitFiles(ModShipKits.Kit kit) =>
            kit.parts.SelectMany(p => new[] { p.model }.Concat(p.tiers)).Where(f => !string.IsNullOrEmpty(f)).Distinct();

        /// <summary>A kit's parts: each model file loaded once (ShipSlots of them at once) into a part template under the
        /// holder, the kit's materials applied.</summary>
        static async Task LoadKit(int rev, ModShipKits.Kit kit, ICollection<string> files)
        {
            await Task.WhenAll(kit.materials.SelectMany(m => new[] { (m.diffuse, false, false), (m.normal, true, true), (m.metallicSmoothness, true, false),
                                                                     (m.emission, false, false), (m.detailAlbedo, true, false), (m.detailNormal, true, true) })
                                            .Where(t => !string.IsNullOrEmpty(t.Item1))
                                            .Select(t => ModMaterials.PreloadTexture(kit.mod, t.Item1, t.Item2, false, t.Item3)));
            string label = kit.Name;
            current.Add(label);
            try
            {
                await Task.WhenAll(files.Select(f => LoadPart(rev, kit, f)));
            }
            finally { current.Remove(label); }
        }

        static async Task LoadPart(int rev, ModShipKits.Kit kit, string file)
        {
            var slots = ShipSlots;
            await slots.WaitAsync();
            try
            {
                if (rev != ModManager.Revision) return;
                var bytes = await Task.Run(() => kit.mod.Source.ReadBytes(file));
                if (bytes == null) { Warn(kit.mod, $"{ModShipKits.File}: {kit.localId}: {file} not found"); return; }
                var import = await ModGltf.Load(kit.mod, bytes, agent);
                bytes = null;
                if (import == null) { Warn(kit.mod, $"{file}: not a glTF model glTFast can read"); return; }
                imports.Add(import);
                if (rev != ModManager.Revision || holder == null) return;
                var part = new GameObject(file);
                part.transform.SetParent(holder.transform, false);
                if (!await import.InstantiateMainSceneAsync(part.transform)) { Object.Destroy(part); Warn(kit.mod, $"{file}: no scene to show"); return; }
                if (rev != ModManager.Revision || holder == null) return;
                ModShipBuilder.ApplyMaterials(kit.mod, kit.materials, part.GetComponentsInChildren<Renderer>(true), kit.Key);
                partTemplates[kit.Key + "|" + file] = part;
            }
            catch (System.Exception e) { Warn(kit.mod, $"{file}: {e.Message}"); Debug.LogException(e); }
            finally
            {
                if (rev == ModManager.Revision) stepsDone++;
                slots.Release();
            }
        }

        /// <summary>The model files a build shows: each slot's part and, at a tier, its extension.</summary>
        static IEnumerable<string> BuildFiles(ModShipKits.Kit kit, ModShipKits.Build build)
        {
            foreach (string slot in kit.slots)
            {
                if (!build.parts.TryGetValue(slot, out var id)) continue;
                var part = kit.Find(id);
                if (part == null) continue;
                yield return part.model;
                if (build.tier > 0 && build.tier <= part.tiers.Count) yield return part.tiers[build.tier - 1];
            }
        }

        /// <summary>A kit's loaded model file (a part, an extension or a hardpoint model; ModHardpoints), null = not loaded.</summary>
        internal static GameObject PartTemplate(ModShipKits.Kit kit, string file) =>
            kit != null && !string.IsNullOrEmpty(file) && partTemplates.TryGetValue(kit.Key + "|" + file, out var t) ? t : null;

        static bool PartsReady(ModShipKits.Kit kit, ModShipKits.Build build) => BuildFiles(kit, build).All(f => partTemplates.ContainsKey(kit.Key + "|" + f));

        /// <summary>The parts a kit ship's build shows are loaded (true; also for a ship that is no kit ship), or start loading
        /// (false: KitPartsLoaded and ModelsChanged follow once they are).</summary>
        public static bool EnsureBuild(int ship, ModShipKits.Build build)
        {
            if (build == null || !kitShips.TryGetValue(ship, out var info)) return true;
            if (PartsReady(info.kit, build)) return true;
            LoadOnDemand(info.kit, BuildFiles(info.kit, build).ToList());
            return false;
        }

        static async void LoadOnDemand(ModShipKits.Kit kit, List<string> files)
        {
            if (holder == null || agent == null) return;
            int rev = ModManager.Revision;
            var missing = files.Where(f => !partTemplates.ContainsKey(kit.Key + "|" + f) && partsLoading.Add(kit.Key + "|" + f)).ToList();
            if (missing.Count == 0) return;
            try { await Task.WhenAll(missing.Select(f => LoadPart(rev, kit, f))); }
            finally { foreach (var f in missing) partsLoading.Remove(kit.Key + "|" + f); }
            if (rev != ModManager.Revision) return;
            KitPartsLoaded?.Invoke();
            ModelsChanged?.Invoke();
        }

        /// <summary>A kit ship's template for 'build': its parts (and the tier's extensions) copied from the part templates into
        /// one scene, built like any mod ship at the kit's scale (ModShipBuilder).</summary>
        static GameObject Assemble(ModInfo mod, CustomShipData c, ModShipKits.Kit kit, ModShipKits.Build build, string name)
        {
            var scene = new GameObject("scene");
            scene.transform.SetParent(holder.transform, false);
            void Add(string file)
            {
                if (!string.IsNullOrEmpty(file) && partTemplates.TryGetValue(kit.Key + "|" + file, out var t) && t != null)
                    Object.Instantiate(t, scene.transform, false).name = file;
            }
            foreach (string slot in kit.slots)
            {
                if (!build.parts.TryGetValue(slot, out var id)) continue;
                var part = kit.Find(id);
                if (part == null) continue;
                Add(part.model);
                if (build.tier > 0 && build.tier <= part.tiers.Count) Add(part.tiers[build.tier - 1]);
            }
            // The build's mounts (its parts' exhausts carry the engine glow) and colours (ModShipKits colour slots: the engine
            // glow through the ship data, the rest on the materials).
            var data = JsonUtility.FromJson<CustomShipData>(JsonUtility.ToJson(c));
            data.mounts = ModShipKits.MountsFor(c, kit, build);
            foreach (var cs in kit.colorSlots)
                if (cs.targets.Exists(t => t.property == "engine") && build.colors.TryGetValue(cs.id, out var ev)
                    && ModShipKits.Resolve(kit, cs, ev, out var engine, out _, out _))
                    data.engineGlowColor = new[] { engine.r, engine.g, engine.b };
            var template = ModShipBuilder.Build(data, mod, scene, kit.scale, kit.yaw);
            template.name = name;
            template.transform.SetParent(holder.transform, false);
            ApplyColors(template, kit, build);
            return template;
        }

        /// <summary>A build's colours onto its renderers: each slot's targets recolour copies of the materials whose name
        /// contains the target's 'material' (base: _BaseColor x intensity and the value's metallic / smoothness; emission:
        /// _EmissionColor x intensity).</summary>
        static void ApplyColors(GameObject root, ModShipKits.Kit kit, ModShipKits.Build build)
        {
            if (kit.colorSlots.Count == 0) return;
            var copies = new Dictionary<Material, Material>();
            foreach (var r in root.GetComponentsInChildren<Renderer>(true))
            {
                var mats = r.sharedMaterials;
                bool changed = false;
                for (int i = 0; i < mats.Length; i++)
                {
                    var m = mats[i];
                    if (m == null) continue;
                    if (copies.TryGetValue(m, out var done)) { mats[i] = done; changed = true; continue; }
                    Material copy = null;
                    string n = m.name.ToLowerInvariant();
                    foreach (var cs in kit.colorSlots)
                    {
                        if (!build.colors.TryGetValue(cs.id, out var v) || !ModShipKits.Resolve(kit, cs, v, out var col, out float metal, out float smooth)) continue;
                        foreach (var t in cs.targets)
                        {
                            if (t.property == "engine" || string.IsNullOrEmpty(t.material) || !n.Contains(t.material.ToLowerInvariant())) continue;
                            copy ??= new Material(m) { name = m.name };
                            if (t.property == "emission")
                            {
                                copy.SetColor("_EmissionColor", col.linear * t.intensity);
                                copy.EnableKeyword("_EMISSION");
                            }
                            else
                            {
                                var c = col * t.intensity; c.a = copy.HasProperty("_BaseColor") ? copy.GetColor("_BaseColor").a : 1f;
                                if (copy.HasProperty("_BaseColor")) copy.SetColor("_BaseColor", c);
                                if (metal >= 0f && copy.HasProperty("_Metallic")) copy.SetFloat("_Metallic", metal);
                                if (smooth >= 0f && copy.HasProperty("_Smoothness")) copy.SetFloat("_Smoothness", smooth);
                            }
                        }
                    }
                    if (copy == null) continue;
                    copies[m] = copy;
                    mats[i] = copy;
                    changed = true;
                }
                if (changed) r.sharedMaterials = mats;
            }
        }

        static void Warn(ModInfo mod, string message)
        {
            if (!mod.Warnings.Contains(message)) mod.Warnings.Add(message);
            Debug.LogWarning($"Mods: {mod.Id}: {message}");
        }

        /// <summary>The old templates and their resources go (the mods changed).</summary>
        static void Release()
        {
            foreach (var t in templates.Values) if (t != null) Object.Destroy(t);
            templates.Clear();
            partTemplates.Clear(); kitShips.Clear(); variants.Clear(); variantOrder.Clear();   // under the holder: destroyed below
            icons.Clear();
            names.Clear();
            foreach (var i in imports) i.Dispose();
            imports.Clear();
            if (holder != null) foreach (Transform child in holder.transform) Object.Destroy(child.gameObject);
            loadedRevision = -1;
        }

        /// <summary>The ship number in a "ship_NNN_mod" assembly name, -1 = not one.</summary>
        static int ShipOf(string assembly) =>
            assembly != null && assembly.StartsWith("ship_") && assembly.Length > 8 && int.TryParse(assembly.Substring(5, 3), out int n) ? n : -1;

        /// <summary>The template for a mod ship's assembly; the Phantom's prefab while the model isn't built.</summary>
        public static GameObject Template(string assembly)
        {
            int hash = assembly?.IndexOf(ModShipKits.VariantSeparator) ?? -1;
            if (hash > 0)
            {
                // A player's build of a kit ship: assembled the first time, then kept (the most recent VariantCap).
                if (variants.TryGetValue(assembly, out var v) && v != null) return v;
                int s = ShipOf(assembly);
                if (loadedRevision == ModManager.Revision && holder != null && kitShips.TryGetValue(s, out var info)
                    && EnsureBuild(s, ModShipKits.Normalize(info.kit, info.ship.kitType, ModShipKits.Build.Parse(assembly.Substring(hash + 1)),
                                                            ModShipKits.DefaultBuild(info.ship, info.kit))))
                {
                    var build = ModShipKits.Normalize(info.kit, info.ship.kitType, ModShipKits.Build.Parse(assembly.Substring(hash + 1)),
                                                      ModShipKits.DefaultBuild(info.ship, info.kit));
                    var made = Assemble(info.mod, info.ship, info.kit, build, assembly);
                    variants[assembly] = made;
                    variantOrder.Enqueue(assembly);
                    while (variantOrder.Count > VariantCap)
                    {
                        string old = variantOrder.Dequeue();
                        if (variants.TryGetValue(old, out var go) && go != null) Object.Destroy(go);
                        variants.Remove(old);
                    }
                    return made;
                }
                assembly = assembly.Substring(0, hash);   // its parts loading (or not built yet): the default build meanwhile
            }
            int ship = ShipOf(assembly);
            if (ship >= 0 && templates.TryGetValue(ship, out var t) && t != null) return t;
            if (!Ready) Debug.LogWarning($"Mods: ship {ship}'s model is still loading: the Phantom stands in");
            var db = Database.Load();
            return Visuals.AssembledObject.LoadPrefab(db.ShipAssembly(FallbackShip));
        }

        /// <summary>Runs the action once the models are built (at most 'timeoutSeconds' later).</summary>
        public static void WhenReady(System.Action action, float timeoutSeconds = 30f) => ModShipsWaiter.Run(action, timeoutSeconds);

        /// <summary>The built templates (ship number, name, template), for the loading screen's hangar shadows
        /// (World.ShipShadowBaker); only complete once Ready.</summary>
        public static IEnumerable<(int ship, string name, GameObject template)> Built
        {
            get
            {
                foreach (var kv in templates)
                    if (kv.Value != null) yield return (kv.Key, names.TryGetValue(kv.Key, out var n) ? n : kv.Value.name, kv.Value);
            }
        }

        /// <summary>A mod ship's shop icon, null = none.</summary>
        public static Texture2D Icon(int ship) => icons.TryGetValue(ship, out var t) ? t : null;
    }
}
