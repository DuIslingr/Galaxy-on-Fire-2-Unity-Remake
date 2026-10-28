// EventGraphScriptValues.cs
// EventGraphScript.Writer: values (part of the partial EventGraphScript.Writer; its fields are in EventGraphScript.cs).

using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using GoF2Remake.Multiplayer;

namespace GoF2Remake.Events
{
    public static partial class EventGraphScript
    {
        partial class Writer
        {
            /// <summary>Random Branch: one of its wired options by weight: set _rbN = random(1, total), then nested ifs on the
            /// running sums.</summary>
            void RandomBranch(EventGraphData.Node n)
            {
                var options = new List<(string exit, string weight)>();
                for (int k = 1; k <= 4; k++)
                    if (Wired(n, "Option " + k)) options.Add(("Option " + k, Operand(n, "Weight " + k, Sum)));
                if (options.Count == 0) { Warning(n, "No option is wired."); return; }
                if (options.Count == 1) { Chain(n, options[0].exit); return; }
                string v = "_rb" + ++randomBranches;
                Line($"set {v} = random(1, {string.Join(" + ", options.ConvertAll(o => o.weight))})");
                string sum = "";
                int opened = 0;
                for (int k = 0; k < options.Count; k++)
                {
                    sum = sum.Length == 0 ? options[k].weight : sum + " + " + options[k].weight;
                    if (k < options.Count - 1)
                    {
                        Line($"if {v} <= {sum}");
                        Block(n, options[k].exit);
                        Line("else");
                        indent++;
                        opened++;
                    }
                    else Chain(n, options[k].exit);
                }
                for (int k = 0; k < opened; k++)
                {
                    indent--;
                    Line("end");
                }
            }
            /// <summary>A typed name the server wouldn't know: a warning on the node (not for {expressions} or %trigger%).</summary>
            void CheckName(EventGraphData.Node n, string value, Func<string, string> check)
            {
                if (string.IsNullOrWhiteSpace(value) || value.IndexOf('{') >= 0 || value.IndexOf('%') >= 0) return;
                string why;
                try { why = check(value.Trim()); }
                catch (Exception) { return; }   // no game data here
                if (why != null && checkedNames.Add((n.id, value))) Warning(n, why);
            }
            /// <summary>A port's or option's stored value; a missing one is a name the Editor's nodes don't have (a bug).</summary>
            string Get(EventGraphData.Node n, string name, bool required = true)
            {
                if (n.values.TryGetValue(name, out string v)) return v ?? "";
                if (required) Error(n, $"No value \"{name}\" in the file.");
                return "";
            }
            double Num(EventGraphData.Node n, string name) =>
                double.TryParse(Get(n, name), NumberStyles.Float, CultureInfo.InvariantCulture, out double d) ? d : 0;
            int Int(EventGraphData.Node n, string name) => (int)Num(n, name);
            bool Bool(EventGraphData.Node n, string name)
            {
                string v = Get(n, name).Trim();
                return v == "1" || v.Equals("true", StringComparison.OrdinalIgnoreCase);
            }
            bool IsWired(EventGraphData.Node n, string port) => inputs.ContainsKey((n.id, port));
            /// <summary>An input's expression: the wired node's, else the port's own value (a condition port's as 1 / 0).</summary>
            string Expr(EventGraphData.Node n, string port) => Expr(n, port, out _);
            string Expr(EventGraphData.Node n, string port, out int precedence)
            {
                precedence = Atom;
                if (!inputs.TryGetValue((n.id, port), out var source))
                {
                    if (IsCondition(n, port)) return Bool(n, port) ? "1" : "0";
                    double v = Num(n, port);
                    if (v < 0) precedence = Unary;
                    return Number(v);
                }
                var from = source.node;
                if (from.kind == EventGraphData.VariableKind)
                {
                    // A sub-graph's input: what is wired into (or typed on) the sub-graph's node, read where that node is.
                    string vid = Get(from, EventGraphData.VariableId, false);
                    if (variablesById.TryGetValue(vid, out var v) && v.kind == 1 && !v.setting && callers.Count > 0)
                    {
                        var caller = callers.Pop();
                        string e = inputs.ContainsKey((caller.id, vid)) || caller.values.ContainsKey(vid) ? Expr(caller, vid, out precedence) : Number(v.value);
                        callers.Push(caller);
                        return e;
                    }
                    if (variablesById.TryGetValue(vid, out v) && v.kind == 2 && !v.flow) Warning(from, "A sub-graph's number output isn't supported: use a variable.");
                    return VariableName(Get(from, EventGraphData.VariableName), n);
                }
                if (!ValueKinds.Contains(from.kind)) { Error(n, $"{port}: can't use what is wired into it."); return "0"; }
                if (!evaluating.Add(from)) { Error(from, "A loop of value nodes."); return "0"; }
                string text = Value(from, out precedence);
                evaluating.Remove(from);
                return text;
            }
            /// <summary>The bool inputs: the steps' Condition ports and the Logic / Not nodes' inputs.</summary>
            static bool IsCondition(EventGraphData.Node n, string port) =>
                ConditionPorts.Contains(port) || n.kind == "EventLogicNode" || n.kind == "EventNotNode";
            string Operand(EventGraphData.Node n, string port, int need)
            {
                string e = Expr(n, port, out int p);
                return p < need ? "(" + e + ")" : e;
            }
            string Value(EventGraphData.Node n, out int precedence)
            {
                switch (n.kind)
                {
                    case "EventStateNode":
                        precedence = Atom;
                        return ((EventGameValue)Int(n, "State")).ToString().ToLowerInvariant();
                    case "EventMathNode":
                    {
                        var op = (EventMathOp)Int(n, "Op");
                        if (op == EventMathOp.Min || op == EventMathOp.Max)
                        {
                            precedence = Atom;
                            return $"{op.ToString().ToLowerInvariant()}({Expr(n, "A")}, {Expr(n, "B")})";
                        }
                        precedence = op == EventMathOp.Add || op == EventMathOp.Subtract ? Sum : Product;
                        string symbol = op switch { EventMathOp.Add => "+", EventMathOp.Subtract => "-", EventMathOp.Multiply => "*", EventMathOp.Divide => "/", _ => "%" };
                        return $"{Operand(n, "A", precedence)} {symbol} {Operand(n, "B", precedence + 1)}";
                    }
                    case "EventRandomNode":
                        precedence = Atom;
                        return $"random({Expr(n, "Min")}, {Expr(n, "Max")})";
                    case "EventFloorNode":
                        precedence = Atom;
                        return $"floor({Expr(n, "Input")})";
                    case "EventCompareNode":
                    {
                        precedence = Compare;
                        string symbol = (EventCompareOp)Int(n, "Op") switch
                        {
                            EventCompareOp.Equal => "==", EventCompareOp.NotEqual => "!=", EventCompareOp.Less => "<",
                            EventCompareOp.LessOrEqual => "<=", EventCompareOp.Greater => ">", _ => ">=",
                        };
                        return $"{Operand(n, "A", Sum)} {symbol} {Operand(n, "B", Sum)}";
                    }
                    case "EventLogicNode":
                    {
                        bool and = (EventLogicOp)Int(n, "Op") == EventLogicOp.And;
                        precedence = and ? And : Or;
                        return $"{Operand(n, "A", precedence)} {(and ? "and" : "or")} {Operand(n, "B", precedence + 1)}";
                    }
                    case "EventNotNode":
                        precedence = Not;
                        return "not " + Operand(n, "Input", Not);
                    case "EventCountPlayersNode":
                        precedence = Atom;
                        return $"count({Text(n, "Players")})";
                    case "EventOnNode":
                    case "EventGetOrbitNode":
                    case "EventGetPlayersNode":
                        precedence = Atom;
                        Error(n, "An orbit or players aren't a number: wire them into a command's Players (or Teleport's Destination).");
                        return "0";
                    case "EventExpressionNode":
                    {
                        precedence = Or;
                        string text = Clean(n, Get(n, "Text"));
                        if (text.Length == 0) { Error(n, "An empty expression."); return "0"; }
                        return text;
                    }
                }
                precedence = Atom;
                Error(n, $"Unknown value node \"{n.kind}\".");
                return "0";
            }
            /// <summary>A camera place (EventCutscene): the port's text, a ship's name of several words quoted ("ship
            /// Pirate Boss 0 500 0" -> ship "Pirate Boss" 0 500 0).</summary>
            string Place(EventGraphData.Node n, string port)
            {
                string t = Text(n, port, false).Trim();
                if (!t.StartsWith("ship ", StringComparison.OrdinalIgnoreCase) || t.Contains("\"")) return t;
                var w = t.Substring(5).Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
                var offset = new List<string>();
                if (w.Count >= 4 && w.Skip(w.Count - 3).All(x => double.TryParse(x, NumberStyles.Float, CultureInfo.InvariantCulture, out _)))
                {
                    offset = w.Skip(w.Count - 3).ToList();
                    w = w.Take(w.Count - 3).ToList();
                }
                string name = string.Join(" ", w);
                if (name.Length == 0) { Error(n, port + ": ship needs the ship's name (as Spawn named it)."); return t; }
                return Join("ship", name.Contains(" ") ? "\"" + name + "\"" : name, string.Join(" ", offset));
            }
            /// <summary>The ship a ship node orders (the name Spawn gave it).</summary>
            string ShipName(EventGraphData.Node n)
            {
                string ship = Text(n, "Ship", false).Trim();
                if (ship.Length == 0) Error(n, "Ship: the name its Spawn node gave it.");
                return ship;
            }
            /// <summary>A place typed in a list (a route's): a ship's name of several words quoted, as Place does.</summary>
            string QuotePlace(EventGraphData.Node n, string t)
            {
                if (!t.StartsWith("ship ", StringComparison.OrdinalIgnoreCase) || t.Contains("\"")) return t;
                var w = t.Substring(5).Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
                var offset = new List<string>();
                if (w.Count >= 4 && w.Skip(w.Count - 3).All(x => double.TryParse(x, NumberStyles.Float, CultureInfo.InvariantCulture, out _)))
                {
                    offset = w.Skip(w.Count - 3).ToList();
                    w = w.Take(w.Count - 3).ToList();
                }
                string name = string.Join(" ", w);
                return Join("ship", name.Contains(" ") ? "\"" + name + "\"" : name, string.Join(" ", offset));
            }
            /// <summary>An order the game wouldn't understand is an error on its node (expressions aside).</summary>
            void CheckOrder(EventGraphData.Node n, string line)
            {
                if (line.Contains("{") || line.Contains("%") || Text(n, "Ship", false).Trim().Length == 0) return;   // no ship: ShipName said so
                if (!EventShipOrders.TryParse(line, out _, out string why)) Error(n, "The order: " + why + ".");
            }
            /// <summary>A number argument of a command: the port's number, or "{expression}" when wired.</summary>
            string Arg(EventGraphData.Node n, string port) => IsWired(n, port) ? "{" + Expr(n, port) + "}" : Number(Num(n, port));
            /// <summary>A text input on one line; wired: Get Players' selector, Get Orbit's station, a number "{expression}".</summary>
            string Text(EventGraphData.Node n, string port, bool required = true)
            {
                if (!inputs.TryGetValue((n.id, port), out var source)) return Clean(n, Get(n, port, required));
                switch (source.node.kind)
                {
                    case "EventGetPlayersNode": return Players(source.node);
                    case "EventGetOrbitNode": return Orbit(source.node);
                    case "EventOnNode": return source.port == "Name" ? "%trigger%" : source.port == "Victim" ? "%victim%" : "@trigger";
                    case "EventAskNode": return source.port == "Name" ? "%trigger%" : "@trigger";   // the answering player
                }
                return "{" + Expr(n, port) + "}";
            }
            /// <summary>Get Orbit: its station (a number, a name, "void", or a wired number as "{expression}").</summary>
            string Orbit(EventGraphData.Node n)
            {
                string station = Text(n, "Station");
                if (station.Length == 0) Error(n, "Which station's orbit? (a number or a name)");
                else CheckName(n, station, EventNames.CheckStation);
                if (station.IndexOfAny(new[] { ']', ',' }) >= 0) Error(n, "A station can't hold ] or ,.");
                return station;
            }
            /// <summary>Get Players: a selector (NetCommands.FindTargets), narrowed to a wired orbit by [orbit=...].</summary>
            string Players(EventGraphData.Node n)
            {
                string selector = (EventPlayersWho)Int(n, "Who") switch
                {
                    EventPlayersWho.AliveInSpace => "@alive", EventPlayersWho.InSpace => "@space", EventPlayersWho.Docked => "@docked",
                    EventPlayersWho.Destroyed => "@dead", EventPlayersWho.Survivors => "@survivors", EventPlayersWho.RandomOne => "@r", _ => "@a",
                };
                if (inputs.TryGetValue((n.id, "Orbit"), out var orbit))
                {
                    if (orbit.node.kind == "EventGetOrbitNode") selector += "[orbit=" + Orbit(orbit.node) + "]";
                    else Error(n, "Orbit: only a Get Orbit node goes here.");
                }
                return selector;
            }
            string Clean(EventGraphData.Node n, string s)
            {
                s = (s ?? "").Replace("\r", " ").Replace("\n", " ").Trim();
                if (s.IndexOf('#') >= 0) Warning(n, "\"#\" starts a comment in the script: the rest of the line is dropped.");
                return s;
            }
            /// <summary>A script variable's name from a blackboard name: lower case, letters, digits and _.</summary>
            string VariableName(string name, EventGraphData.Node n)
            {
                var b = new StringBuilder();
                foreach (char c in (name ?? "").Trim().ToLowerInvariant()) b.Append(char.IsLetterOrDigit(c) || c == '_' ? c : '_');
                if (b.Length == 0) { Error(n, "A variable without a name."); return "_"; }
                if (char.IsDigit(b[0])) b.Insert(0, '_');
                string v = b.ToString();
                if (StateNames.Contains(v)) Warning(n, $"\"{v}\" is a game value (Game State): the variable can't be read.");
                if (v == "and" || v == "or" || v == "not") Error(n, $"\"{v}\" can't be a variable name.");
                return v;
            }
        }
    }
}
