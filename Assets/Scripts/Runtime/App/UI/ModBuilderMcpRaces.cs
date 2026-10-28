// ModBuilderMcpRaces.cs
// Remake: the Mod Builder MCP server's tools for the mod's own races (part of ModBuilderMcp; races.json, ModRaces, the
// builder's Races kind, ModBuilderViewRaces):
//   list_races   the game's races (their words and numbers), the project's own (with their relations, the systems they own
//                and the ships they build) and the other installed mods' (using one makes that mod a dependency)
//   put_race     a race added or changed (a races.json entry), its fields checked before it is written
//   delete_race  a race removed with every reference to it in the project (ModProject.RemoveRace: its systems and ships
//                go back to its look race); asks like delete_entry
//   set_race     a system's owner / locals / raiders or a ship's race / traffic races, as the Systems and Ships pages set
//                them: each value checked against the game's and the mods' races
// The races are an entry kind too ("races": list_entries / get_entries / put_entry / patch_entry / delete_entry), and
// search_content's kind "race". Each change is one undo step through ExternalEdit, made by the project's own methods
// (EditProject) and answered once the game has read the project again (its errors and warnings).

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using GoF2Remake.Modding;
using Newtonsoft.Json.Linq;

namespace GoF2Remake.UI
{
    public static partial class ModBuilderMcp
    {
        static readonly string[] SystemRaceFields = { "owner", "locals", "raiders" }, ShipRaceFields = { "race", "trafficRaces" };

        static List<Tool> RaceTools() => new List<Tool>
        {
            new Tool
            {
                name = "list_races", title = "List the races", readOnly = true,
                description = "Every race a mod file may name: the game's (by word: terran, vossk, nivelian, midorian, pirates, void, specters; and number), this project's own races (races.json: id, key, look, standing, hostile, relations, the systems they own and the ships they build) and the other installed mods' races (by key; using one makes that mod a dependency).",
                input = Input(), run = ListRaces,
            },
            new Tool
            {
                name = "put_race", title = "Add or change a race",
                description = "Writes one races.json entry (the Modding guide's \"Races\"): \"id\" (a-z, 0-9, _, -) and \"name\" required; \"description\", \"look\" (terran, vossk, nivelian, midorian, pirates or void: whose hangars, bars, music, NPC guns and gate it borrows), \"icon\" (a PNG in the project, e.g. icons/race_guild.png from write_file), \"color\" [r, g, b] 0..1, \"standing\" (-100..100, the player's start), \"hostile\", \"diplomats\", \"relations\" { \"<race>\": \"friend\" | \"neutral\" | \"enemy\" } (game races by word, mod races by id or key), \"gun\" (an item). An entry with the id of an existing race replaces it. Then set_race gives it systems and ships. One undo step; the answer lists the problems the game finds.",
                input = Input(("race", new JObject { ["type"] = "object" }, "the races.json entry", true)),
                run = PutRace, timeoutSeconds = 60f,
                ask = a => $"write the race \"{(a["race"] as JObject)?["id"]}\" into the project",
            },
            new Tool
            {
                name = "delete_race", title = "Remove a race", destructive = true,
                description = "Removes one of the project's races and every reference to it in the project: a system it owns or a ship it builds goes back to its look race, locals / raiders / traffic races and other races' relations naming it go. Asks the player in the builder first; one undo step.",
                input = Input(("id", "string", "the race's id", true)),
                run = DeleteRace, timeoutSeconds = 30f, permitsItself = true,
            },
            new Tool
            {
                name = "set_race", title = "Set a system's or ship's race",
                description = "Names races on a system or a ship, as the builder's Systems and Ships pages do. target \"system\": field \"owner\" (one value: terran, vossk, nivelian, midorian or a mod race), \"locals\" (the races whose patrols fly there) or \"raiders\" (the races that raid it); target \"ship\": field \"race\" (who builds it: a game race 0-3, pirates, void, or a mod race) or \"trafficRaces\" (the races whose NPC fighters fly it). 'value' is a race (list_races: a game race's word or number, a mod race's id or \"mod_id:id\") or, for the lists, a list of them; an empty list clears it (the default). Another mod's race makes that mod a dependency. One undo step; the answer lists the problems the game finds.",
                input = Input(("target", Enum("system", "ship"), "what to change", true), ("id", "string", "the system's or ship's id, or \"override:<n>\"", true),
                              ("field", Enum(SystemRaceFields.Concat(ShipRaceFields).ToArray()), "which race field", true),
                              ("value", new JObject { ["type"] = new JArray("string", "array"), ["items"] = new JObject { ["type"] = "string" } }, "a race, or a list of races", true)),
                run = SetRace, timeoutSeconds = 60f,
                ask = a => $"set the {Str(a, "field")} of the {Str(a, "target")} \"{Str(a, "id")}\"",
            },
        };

        /// <summary>An edit made by the open project's own methods inside ExternalEdit: 'edit' changes the project (or returns why
        /// not, changing nothing), and the state ExternalEdit restores becomes the project as it then is.</summary>
        static string EditProject(JObject state, Func<string> edit)
        {
            string error = edit();
            if (error != null) return error;
            foreach (var p in Project.CaptureState().Properties()) state[p.Name] = p.Value;
            return null;
        }

        static JObject RaceJson(RefEntry e) => new JObject { ["value"] = e.value, ["name"] = e.name };

        static void ListRaces(JObject a, Call c)
        {
            var p = Project;
            if (p == null) { c.Fail("The Mod Builder isn't open."); return; }
            var game = new JArray(ModRefs.RaceWords.Select(r => new JObject { ["value"] = r.word, ["race"] = r.race, ["name"] = r.name }));
            var own = new JArray();
            foreach (var r in p.Races.Where(r => r.Id != null))
            {
                own.Add(new JObject
                {
                    ["id"] = r.Id, ["key"] = p.Key(r.Id), ["name"] = r.Name, ["look"] = ProjectRace.Looks[r.Look], ["standing"] = r.Standing,
                    ["hostile"] = r.Hostile, ["diplomats"] = r.Diplomats,
                    ["relations"] = new JObject(r.Relations.Select(x => new JProperty(x.other, x.relation))),
                    ["systems"] = new JArray(p.Systems.Where(s => p.OwnRace(s.ModRace) == r).Select(s => s.IsOverride ? "override:" + s.OverrideRef : s.LocalId)),
                    ["ships"] = new JArray(p.Ships.Where(s => p.OwnRace(s.ModRace) == r).Select(s => s.IsOverride ? "override:" + s.OverrideIndex : s.LocalId)),
                });
            }
            var others = new JArray(ModRefs.List(RefKind.Race, p).Where(e => e.group != ModRefs.GameGroup && !e.own)
                                           .Select(e => { var o = RaceJson(e); o["mod"] = e.modId; o["about"] = e.sub; return o; }));
            c.Json(new JObject { ["game"] = game, ["project"] = own, ["otherMods"] = others }, $"races: {own.Count} of the project's, {others.Count} of other mods");
        }

        /// <summary>A race reference resolved against the game's, the project's and the other mods' races (null: none).</summary>
        static RefEntry FindRace(string value) => string.IsNullOrWhiteSpace(value) ? null : ModRefs.Find(RefKind.Race, value.Trim(), Project);

        /// <summary>Why a races.json entry can't be written (null: it can): the guide's rules for each field.</summary>
        static string CheckRace(JObject e, List<RefEntry> used)
        {
            string id = e["id"] is JValue iv && iv.Type == JTokenType.String ? (string)iv : null;
            if (id == null || !ModManifest.ValidId(id)) return "race: \"id\" (a-z, 0-9, _ and -) is needed.";
            if (!(e["name"] is JValue nv && nv.Type == JTokenType.String && ((string)nv).Trim().Length > 0) && !(e["name"] is JObject))
                return "race: \"name\" is needed (a string, or one per language).";
            if (e["look"] != null && Array.IndexOf(ProjectRace.LookRaces, ModRaces.GameRace(e["look"])) < 0)
                return "look: terran, vossk, nivelian, midorian, pirates or void.";
            if (e["color"] != null && !(e["color"] is JArray col && col.Count == 3 && col.All(x => x.Type == JTokenType.Integer || x.Type == JTokenType.Float)))
                return "color: [r, g, b], each 0 to 1.";
            if (e["standing"] != null && !(e["standing"].Type == JTokenType.Integer && (int)e["standing"] >= -100 && (int)e["standing"] <= 100))
                return "standing: a whole number from -100 to 100.";
            foreach (var k in new[] { "hostile", "diplomats" })
                if (e[k] != null && e[k].Type != JTokenType.Boolean) return $"{k}: true or false.";
            if (e["icon"] != null)
            {
                string icon = e["icon"].Type == JTokenType.String ? (string)e["icon"] : null;
                if (icon == null || ProjectPath(icon, false, out _) is not string full || !File.Exists(full))
                    return $"icon: {e["icon"]} isn't in the project (write_file it first, e.g. icons/race_{id}.png).";
            }
            if (e["gun"] != null)
            {
                var gun = ModRefs.Find(RefKind.Item, ProjectEntry.RefText(e["gun"]), Project);
                if (gun == null) return $"gun: no item \"{e["gun"]}\" (search_content kind item).";
                used.Add(gun);
            }
            if (e["relations"] != null)
            {
                if (!(e["relations"] is JObject rel)) return "relations: { \"<race>\": \"friend\" | \"neutral\" | \"enemy\" }.";
                foreach (var p in rel.Properties())
                {
                    if (!(p.Value is JValue v && Array.IndexOf(ProjectRace.RelationWords, v.ToString().Trim().ToLowerInvariant()) >= 0))
                        return $"relations: \"{p.Name}\" must be \"friend\", \"neutral\" or \"enemy\".";
                    if (p.Name == id || p.Name == Project.Key(id)) return "relations: a race has no relation to itself.";
                    var other = FindRace(p.Name);
                    if (other == null) return $"relations: no race \"{p.Name}\" (list_races; put_race the other race first).";
                    used.Add(other);
                }
            }
            return null;
        }

        static void PutRace(JObject a, Call c)
        {
            var screen = Screen(out string why);
            if (screen == null) { c.Fail(why); return; }
            if (!(a["race"] is JObject entry)) throw new ArgumentException("race: the races.json entry object.");
            entry = (JObject)entry.DeepClone();
            string id = entry["id"]?.ToString(), label = null;
            string error = screen.ExternalEdit(state => EditProject(state, () =>
            {
                var used = new List<RefEntry>();
                string bad = CheckRace(entry, used);
                if (bad != null) return bad;
                foreach (var u in used) ModRefs.Use(Project, u);
                var old = Project.FindRace(id);
                if (old != null) { old.Json.RemoveAll(); foreach (var p in entry.Properties()) old.Json.Add(p.Name, p.Value.DeepClone()); }
                else Project.Races.Add(new ProjectRace(entry));
                label = $"race {id}{(old != null ? " changed" : " added")}";
                return null;
            }), $"race {id}");
            if (error != null) { c.Fail(error); return; }
            AnswerAfterReload(c, screen, label, null, null, new JObject { ["key"] = Project.Key(id) });
        }

        static void DeleteRace(JObject a, Call c)
        {
            var screen = Screen(out string why);
            if (screen == null) { c.Fail(why); return; }
            string id = Str(a, "id");
            var race = Project.OwnRace(id);
            if (race == null) { c.Fail($"No race \"{id}\" in the project (list_races)."); return; }
            int uses = Project.RaceUses(race);
            string what = $"the race \"{race.Id}\"" + (uses > 0 ? $" and the {uses} references to it in the project" : "");
            ModBuilderMcp.Permit(c, "remove " + what + " (Undo brings it back)", true, () =>
            {
                string rid = race.Id;
                string error = screen.ExternalEdit(st => EditProject(st, () =>
                {
                    var r = Project.FindRace(rid);
                    if (r == null) return $"No race \"{rid}\" in the project.";
                    Project.RemoveRace(r);
                    return null;
                }), "removed " + what);
                if (error != null) { c.Fail(error); return; }
                AnswerAfterReload(c, screen, "removed " + what, null, null, new JObject { ["referencesChanged"] = uses });
            });
        }

        static void SetRace(JObject a, Call c)
        {
            var screen = Screen(out string why);
            if (screen == null) { c.Fail(why); return; }
            string target = Str(a, "target"), id = Str(a, "id"), field = Str(a, "field");
            bool system = target == "system";
            if (!system && target != "ship") throw new ArgumentException("target: system or ship.");
            if (Array.IndexOf(system ? SystemRaceFields : ShipRaceFields, field) < 0)
                throw new ArgumentException($"field: for a {target} one of {string.Join(", ", system ? SystemRaceFields : ShipRaceFields)}.");
            var values = a["value"] is JArray arr ? arr.Select(t => t.ToString()).Where(t => t.Trim().Length > 0).ToList()
                       : Str(a, "value") is string one && one.Trim().Length > 0 ? new List<string> { one } : new List<string>();
            bool single = field == "owner" || field == "race";
            if (single && values.Count != 1) { c.Fail($"value: one race for the {field}."); return; }
            string r = id == null ? null : id.StartsWith("override:") || id.StartsWith("id:") ? id : "id:" + id;
            string label = null;
            string error = screen.ExternalEdit(state => EditProject(state, () =>
            {
                var sys = system ? Project.Systems.FirstOrDefault(x => x.Ref == r) : null;
                var shp = system ? null : Project.Ships.FirstOrDefault(x => x.Ref == r);
                if (sys == null && shp == null) return $"No {target} \"{id}\" in the project (list_entries kind {target}s).";
                // Each value resolved: a game race (its word, or its number where the field takes numbers) or a mod race's key.
                var resolved = new List<(RefEntry e, int game)>();
                foreach (var v in values)
                {
                    var e = FindRace(v);
                    if (e == null) return $"value: no race \"{v}\" (list_races).";
                    int game = e.group == ModRefs.GameGroup ? ModRaces.GameRaceWord(e.value) : -1;
                    if (field == "owner" && e.group == ModRefs.GameGroup && (game < 0 || game > 3)) return "owner: terran, vossk, nivelian, midorian or a mod race.";
                    if (field == "race" && e.group == ModRefs.GameGroup && (game < 0 || game == 10)) return "race: terran, vossk, nivelian, midorian, pirates, void or a mod race.";
                    if (field == "trafficRaces" && game == 10) return "trafficRaces: the Specters fly no mod ships.";
                    resolved.Add((e, game));
                }
                foreach (var (e, _) in resolved) ModRefs.Use(Project, e);
                var list = resolved.Select(x => field == "trafficRaces" && x.game >= 0 ? x.game.ToString() : x.e.value).Distinct().ToList();
                switch (field)
                {
                    case "owner": if (resolved[0].game >= 0) sys.Race = resolved[0].game; else sys.ModRace = resolved[0].e.value; break;
                    case "locals": sys.Locals = list; break;
                    case "raiders": sys.Raiders = list; break;
                    case "race": if (resolved[0].game >= 0) shp.Race = resolved[0].game; else shp.ModRace = resolved[0].e.value; break;
                    case "trafficRaces": shp.TrafficRaces = list; break;
                }
                label = $"{target} {id}: {field} = {(list.Count > 0 ? string.Join(", ", list) : "default")}";
                return null;
            }), $"{target} {id} {field}");
            if (error != null) { c.Fail(error); return; }
            AnswerAfterReload(c, screen, label, null, null);
        }
    }
}
