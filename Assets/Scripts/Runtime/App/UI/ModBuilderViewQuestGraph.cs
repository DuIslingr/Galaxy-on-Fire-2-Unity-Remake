// ModBuilderViewQuestGraph.cs
// ModBuilderView: the quests' graph view and the event graphs made in the Unity Editor (part of the partial ModBuilderView; its fields are in ModBuilderViewQuests.cs).

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using GoF2Remake.Data;
using GoF2Remake.Events;
using GoF2Remake.Modding;
using Newtonsoft.Json.Linq;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    public partial class ModBuilderView
    {
        // ---- the graph view -----------------------------------------------------------------------------------
        void BuildQuestGraph()
        {
            graph = new QuestGraphView
            {
                stepName = StepName,
                stepSummary = StepSummary,
                fieldText = english => T("mbField_" + english.Replace(" ", ""), english),
                selected = _ => { currentStep = graph.Selection as JObject; BuildQuestPage(); },
                edited = () => { MarkDirty(); RebuildQuests(); BuildQuestPage(); },
                pickStep = (done, cut) => PickStepFor(done, cut, false),
                pickValue = PickValueType,
            };
            graph.style.display = DisplayStyle.None;
            graphTools = new VisualElement();
            graphTools.AddToClassList("mbg-tools");
            Act(graphTools, T("mbGraphAddStep", "+ Step"), () => graph.NewStepAt(), "mbv-step");
            Act(graphTools, T("mbGraphAddValue", "+ Value"), graph.NewValue, "mbv-step");
            Act(graphTools, T("mbGraphTidy", "Tidy up"), graph.Tidy, "mbv-step");
            Act(graphTools, T("mbGraphFrame", "Find Start"), graph.Frame, "mbv-step");
            Act(graphTools, "+", () => graph.ZoomBy(1.15f), "mbv-step");
            Act(graphTools, "−", () => graph.ZoomBy(1f / 1.15f), "mbv-step");
            graphWideButton = Act(graphTools, "", () => { GraphWide = !GraphWide; UpdateQuestGraph(); }, "mbv-step");
            graph.Add(graphTools);
            var help = new Label(T("mbGraphHelp", "Drag to pan, wheel to zoom. Drag an output onto a node to wire it, or onto empty space for a new step. Delete removes."));
            help.AddToClassList("mbg-help");
            help.pickingMode = PickingMode.Ignore;
            graph.Add(help);
            graph.AddToClassList(SafeArea.EdgeClass);   // between the side panels, inside the interface band as they are
            root.Add(graph);
        }
        /// <summary>The graph is shown with the Quests kind in the Graph view (a step-list quest open); wide hides the list.</summary>
        void UpdateQuestGraph()
        {
            if (graph == null) return;
            bool show = kind == ModBuilder.Kind.Quests && GraphMode && currentQuest != null && currentGraph == null;
            graph.style.display = show ? DisplayStyle.Flex : DisplayStyle.None;
            root.EnableInClassList("mbv-root--graph", show);
            root.EnableInClassList("mbv-root--graph-wide", show && GraphWide);
            graphWideButton.text = GraphWide ? T("mbGraphNarrow", "Show the list") : T("mbGraphWide", "Wider");
            if (!show) return;
            if (graph.quest != currentQuest.Json)
            {
                graph.quest = currentQuest.Json;
                graph.Select(null, false);
                graph.Rebuild();
                graph.schedule.Execute(graph.Frame);
            }
        }
        /// <summary>The graph drawn again a moment after the last edit (typing in the inspector).</summary>
        void RedrawGraphSoon()
        {
            if (graph == null || graph.style.display == DisplayStyle.None) return;
            graphRedraw?.Pause();
            graphRedraw = graph.schedule.Execute(() => graph.Rebuild()).StartingIn(200);
        }
        void PickValueType(Action<JObject> done)
        {
            var choices = new List<(string, Texture2D, Action)>();
            foreach (var t in QuestGraph.ValueTypes)
            {
                string type = t.type;
                string what = t.output == QuestGraph.ValueKind.Players ? T("mbValueGivesPlayers", "gives players") : t.output == QuestGraph.ValueKind.Orbit ? T("mbValueGivesOrbit", "gives a station")
                            : T("mbValueGivesNumber", "gives a number");
                choices.Add(($"{T("mbValue_" + type, t.english)}\n{what}", null, () => done(QuestGraph.NewValue(currentQuest.Json, type))));
            }
            ShowPicker(T("mbGraphAddValue", "+ Value"), choices, true);
        }
        /// <summary>The inspector beside the graph: the selected step's fields, a value node's, or the quest's settings.</summary>
        void BuildGraphInspector(ProjectQuest q)
        {
            var top = Row(questPage);
            Act(top, T("mbPlayQuest", "Play it"), () => PlayQuest(q), "mbv-play");
            Act(top, T("mbShowScript", "Show the script"), () => ShowScript(q));
            Act(top, T("mbListView", "List view"), () => { GraphMode = false; UpdateQuestGraph(); BuildQuestPage(); });
            var sel = graph.Selection as JObject;
            if (sel != null && sel.Parent == q.Json["values"]) { BuildValueInspector(q, sel); return; }
            if (sel != null && sel.Parent is JArray && QuestSteps.Get((string)sel["type"] ?? "") is QuestStepType def)
            {
                Heading(questPage, StepName(def.type));
                var tools = Row(questPage);
                Act(tools, T("mbDuplicate", "Copy"), () =>
                {
                    var copy = (JObject)sel.DeepClone();
                    var (x, y) = QuestGraph.Pos(sel);
                    QuestGraph.SetPos(copy, x + 40, y + 40);
                    QuestGraph.AddLoose(q.Json, copy);
                    graph.Rebuild();
                    graph.Select(copy);
                    MarkDirty();
                }, "mbv-step");
                if (QuestGraph.Incoming(sel).port != null)
                    Act(tools, T("mbCutWireIn", "Cut its wire in"), () => { QuestGraph.Detach(q.Json, sel); graph.Rebuild(); MarkDirty(); BuildQuestPage(); }, "mbv-step");
                Act(tools, T("mbDelete", "Delete"), graph.DeleteSelected, "mbv-danger");
                Act(tools, T("mbQuestSettings", "Mission settings"), () => graph.Select(null), "mbv-step");
                JsonButton(questPage, sel, () => { graph.Rebuild(); BuildQuestPage(); }, T("mbJsonStepNote", "The step's fields (Modding/README.md, \"Missions made in the Mod Builder\")."));
                int index = QuestGraph.AllSteps(q.Json).ToList().IndexOf(sel) + 1;
                BuildStep(questPage, q, sel, def, index.ToString(CultureInfo.InvariantCulture), 0);
                Note(questPage, T("mbGraphWiredNote", "A field with a dot takes a wire from a value node (+ Value)."));
                return;
            }
            BuildQuestSettings(q);
            JsonButton(questPage, q.Json, () => { graph.Rebuild(); RebuildQuests(); BuildQuestPage(); }, T("mbJsonQuestNote", "The whole .gof2mission: settings, steps, loose chains and value nodes."));
            int loose = (q.Json["loose"] as JArray)?.Count ?? 0;
            if (loose > 0) Note(questPage, string.Format(T("mbLooseNote", "{0} chain(s) aren't wired: they don't run until wired to Start or a step."), loose));
        }
        void BuildValueInspector(ProjectQuest q, JObject v)
        {
            var t = QuestGraph.GetValueType((string)v["type"] ?? "");
            Heading(questPage, t != null ? T("mbValue_" + t.type, t.english) : (string)v["type"]);
            var tools = Row(questPage);
            Act(tools, T("mbDelete", "Delete"), graph.DeleteSelected, "mbv-danger");
            Act(tools, T("mbQuestSettings", "Mission settings"), () => graph.Select(null), "mbv-step");
            if (t == null) return;
            void Changed(bool rebuild) { MarkDirty(); RedrawGraphSoon(); if (rebuild) BuildQuestPage(); }
            foreach (var (key, label, choices, def) in t.options)
            {
                string cur = v[key]?.ToString() ?? def;
                if (choices.Length > 0)
                {
                    if (choices.Length <= 6) Segments(questPage, T("mbValueOpt_" + key, label), choices, Math.Max(0, Array.IndexOf(choices, cur)), n => { v[key] = choices[n]; Changed(true); });
                    else
                    {
                        Caption(questPage, T("mbValueOpt_" + key, label));
                        var row = Row(questPage);
                        Add(row, new Label(cur), "mbv-inline-label");
                        Act(row, T("mbChoose", "Choose…"), () => ShowPicker(label, choices.Select(c => (c, (Texture2D)null, (Action)(() => { v[key] = c; Changed(true); }))).ToList()), "mbv-step");
                    }
                }
                else if (key == "station")
                    RefField(questPage, T("mbStation", "Station"), RefKind.Station, cur, x => { v[key] = ProjectEntry.RefToken(x ?? "78"); Changed(true); }, clear: false);
                else if (key == "item")
                    RefField(questPage, T("mbItem", "Item"), RefKind.Item, cur, x => { v[key] = ProjectEntry.RefToken(x ?? "22"); Changed(true); }, clear: false);
                else if (key == "name" && t.type == "quest")
                    RefField(questPage, T("mbQuestField", "Mission"), RefKind.Quest, cur, x => { if (x != null) { v[key] = x; Changed(true); } }, clear: false);
                else Text(questPage, T("mbValueOpt_" + key, label), cur, 200, x => { v[key] = x.Trim(); Changed(false); });
            }
            foreach (var (key, kindOf, label, def) in t.inputs)
            {
                string wired = QuestGraph.WiredValue(v[key]);
                if (wired != null)
                {
                    var row = Row(questPage);
                    var src = QuestGraph.Value(q.Json, wired);
                    Add(row, new Label($"{T("mbValueIn_" + key, label)}: {T("mbWiredFrom", "wired from")} {(src != null ? T("mbValue_" + (string)src["type"], (string)src["type"]) : "?")}"), "mbv-inline-label");
                    Act(row, "×", () => { v.Remove(key); Changed(true); }, "mbv-step");
                }
                else if (kindOf == QuestGraph.ValueKind.Orbit)
                    RefField(questPage, T("mbValueIn_" + key, label), RefKind.Station, v[key]?.ToString() ?? (def.Length > 0 ? def : null), x => { if (x == null) v.Remove(key); else v[key] = ProjectEntry.RefToken(x); Changed(true); }, T("mbNone", "none"));
                else Text(questPage, T("mbValueIn_" + key, label), v[key]?.ToString() ?? def, 200, x => { v[key] = Num(x); Changed(false); });
            }
            var problems = new List<string>();
            string expr = QuestGraph.Resolve(q.Json, (string)v["id"], problems.Add);
            Note(questPage, T("mbValueGives", "It gives:") + " " + expr + (problems.Count > 0 ? "  × " + problems[0] : ""));
        }
        void RebuildQuests()
        {
            questList.Clear();
            if (Project == null) return;
            var graphs = Project.EventGraphs();
            if (currentQuest != null && !Project.Quests.Contains(currentQuest)) currentQuest = null;
            if (currentGraph != null && !graphs.Contains(currentGraph)) currentGraph = null;
            if (currentQuest == null && currentGraph == null) currentQuest = Project.Quests.FirstOrDefault();
            if (currentQuest == null && currentGraph == null) currentGraph = graphs.FirstOrDefault();
            foreach (var quest in Project.Quests)
            {
                var q = quest;
                ListRow(questList, q.Title ?? q.Name, KindName(q.Kind) + "  ·  " + q.Name + "  ·  " + string.Format(T("mbSteps", "{0} steps"), CountSteps(q.Steps)), q == currentQuest,
                        () => { currentQuest = q; currentGraph = null; currentStep = null; RebuildQuests(); BuildQuestPage(); }, null, null);
            }
            if (graphs.Count > 0)
            {
                Heading(questList, T("mbEventGraphs", "Event graphs"));
                foreach (var g in graphs)
                {
                    string name = g;
                    ListRow(questList, name, T("mbMadeInUnity", "Made in the Unity Editor"), name == currentGraph,
                            () => { currentGraph = name; currentQuest = null; currentStep = null; RebuildQuests(); BuildQuestPage(); }, null, null);
                }
            }
            if (Project.Quests.Count == 0 && graphs.Count == 0)
                Note(questList, T("mbNoQuests", "No missions yet. A story mission starts by itself; a bar mission is offered in a Space Lounge; an event runs by /event."));
        }
        static int CountSteps(JArray steps) => ProjectQuest.All(steps, Lists).Count();
        static IEnumerable<JArray> Lists(JObject st) => QuestSteps.Children(st).Select(c => c.list);
        static string KindName(string kind) => kind == "mission" ? T("mbBarMission", "Bar mission") : kind == "event" ? T("mbEvent", "Event") : T("mbQuest", "Story mission");
        void NewQuest(string kind) => AskText(kind == "mission" ? T("mbNewMission", "+ New bar mission") : kind == "event" ? T("mbNewEvent", "+ New event") : T("mbNewQuest", "+ New story mission"),
            T("mbTitleField", "Title"), "", title =>
        {
            var q = Project.AddQuest(title, kind == "mission");
            q.Kind = kind;
            if (kind == "mission") { q.Offer = T("mbOfferDefault", "I have a job for you."); q.Reward = 10000; }
            // A first conversation and the end, to build on.
            var page = new JObject { ["speaker"] = "player", ["text"] = T("mbFirstLine", "Let's get to work.") };
            q.AddStep("dialog")["pages"] = new JArray(page);
            if (kind != "event") q.AddStep("complete");
            currentQuest = q;
            currentGraph = null;
            currentStep = null;
            MarkDirty();
            RebuildQuests();
            BuildQuestPage();
        });
        void AskRemoveQuest()
        {
            if (currentGraph != null)
            {
                string g = currentGraph;
                Confirm(T("mbRemoveQuest", "Remove"), string.Format(T("mbRemoveText", "Remove \"{0}\" from the project?"), g), () =>
                {
                    Project.RemoveEventGraph(g);
                    currentGraph = null;
                    QuestFilesChanged();
                });
                return;
            }
            var q = currentQuest;
            if (q == null) return;
            Confirm(T("mbRemoveQuest", "Remove"), string.Format(T("mbRemoveText", "Remove \"{0}\" from the project?"), q.Title ?? q.Name), () =>
            {
                Project.Quests.Remove(q);
                currentQuest = null;
                currentStep = null;
                MarkDirty();
                RebuildQuests();
                BuildQuestPage();
            });
        }
        /// <summary>A graph file came or went: saved, read again, the lists redrawn.</summary>
        void QuestFilesChanged()
        {
            SaveNow();
            RequestReload(false);
            RebuildQuests();
            BuildQuestPage();
        }
        void QuestEdited(bool rebuildPage = false)
        {
            MarkDirty();
            RedrawGraphSoon();
            if (rebuildPage) BuildQuestPage();
        }
        // ---- event graphs made in the Unity Editor ---------------------------------------------------------------
        void ImportGraph() => PickRaw(T("mbImportGraph", "Import an event graph…"), T("mbGraphFilter", "Event graphs"), new[] { "gof2event", "gof2netevent" }, picked =>
        {
            string text = File.ReadAllText(picked.path);
            if (!EventGraphScript.IsGraph(text)) { Status(T("mbNotGraph", "That isn't an event graph (a .gof2event the Unity Editor saved)."), true); return; }
            string name = Path.GetFileNameWithoutExtension(picked.name ?? picked.path);
            string src = Path.Combine(Application.temporaryCachePath, "mb_graph_" + Guid.NewGuid().ToString("N") + ".gof2event");
            File.Copy(picked.path, src, true);
            var choices = new List<(string, Texture2D, Action)>
            {
                (T("mbConvertSteps", "Convert to steps") + "\n" + T("mbConvertStepsWhat", "Edit it here; the lines the builder has no step for stay Command steps"), null,
                    () => { try { ConvertGraph(name, text); } finally { try { File.Delete(src); } catch { } } }),
                (T("mbKeepGraph", "Add it as it is") + "\n" + T("mbKeepGraphWhat", "It runs as the Unity Editor made it; edit it there"), null, () =>
                {
                    try
                    {
                        string added = Project.AddEventGraph(src);
                        currentGraph = added;
                        currentQuest = null;
                        Status(string.Format(T("mbGraphAdded", "\"{0}\" added."), added), false);
                        QuestFilesChanged();
                    }
                    finally { try { File.Delete(src); } catch { } }
                }),
            };
            ShowPicker(T("mbImportGraph", "Import an event graph…"), choices);
        });
        /// <summary>A graph's script as steps (QuestFile.FromScript), a quest of the project; 'replace': the graph of that name
        /// in the project goes.</summary>
        void ConvertGraph(string name, string text, bool replace = false)
        {
            var problems = new List<EventGraphScript.Problem>();
            string script = EventGraphScript.FromFile(text, problems);
            var errors = problems.Where(p => !p.warning).ToList();
            if (errors.Count > 0 || script.Length == 0)
            {
                Status("× " + (errors.Count > 0 ? (errors[0].node != null ? errors[0].node + ": " : "") + errors[0].message : T("mbGraphEmpty", "The graph has no steps.")), true);
                return;
            }
            var notes = new List<string>();
            var json = QuestFile.FromScript(script, Pretty(name), notes);
            if (replace) Project.RemoveEventGraph(name);
            var q = Project.AddQuest(name, json);
            currentQuest = q;
            currentGraph = null;
            currentStep = null;
            MarkDirty();
            QuestFilesChanged();
            Status(string.Format(T("mbGraphConverted", "\"{0}\" is now steps."), q.Name) + (notes.Count > 0 ? " " + string.Join(" ", notes) : ""), false);
        }
        void BuildGraphPage(string name)
        {
            Heading(questPage, name);
            Note(questPage, T("mbGraphNote", "Made in Unity with Graph Toolkit: it runs as is. Edit it there, or convert it to steps here."));
            var top = Row(questPage);
            Act(top, T("mbPlayQuest", "Play it"), () =>
            {
                SaveNow();
                ModBuilder.Reload();
                afterReload.Clear();
                string why = ModBuilderPlay.StartQuest(name);
                if (why != null) Status(why, true);
            }, "mbv-play");
            Act(top, T("mbShowScript", "Show the script"), () =>
            {
                string path = Project.EventGraphPath(name);
                var problems = new List<EventGraphScript.Problem>();
                string script = path != null ? EventGraphScript.FromFile(File.ReadAllText(path), problems) : "";
                ShowScriptText(script, problems.Select(p => (p.warning ? "⚠ " : "× ") + (p.node != null ? p.node + ": " : "") + p.message).ToList());
            });
            Act(questPage, T("mbConvertSteps", "Convert to steps"), () =>
            {
                string path = Project.EventGraphPath(name);
                if (path == null) return;
                Confirm(T("mbConvertSteps", "Convert to steps"), string.Format(T("mbConvertConfirm", "\"{0}\" becomes a step list; the graph file goes (Undo brings it back)."), name),
                        () => ConvertGraph(name, File.ReadAllText(path), true));
            }, "mbv-add");
        }
    }
}
