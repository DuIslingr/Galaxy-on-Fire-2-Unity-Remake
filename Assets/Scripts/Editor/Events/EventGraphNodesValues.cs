// EventGraphNodesValues.cs
// The EventGraph's nodes: players and values (on the data wires). The base classes, flow and triggers are in EventGraphNodes.cs.

using System;
using System.Collections.Generic;
using GoF2Remake.Multiplayer;
using Unity.GraphToolkit.Editor;
using UnityEngine;
using GoF2Remake.Events;

namespace GoF2Remake.EditorTools
{
    // ---- players -----------------------------------------------------------------------------------------------------

    [Serializable]
    [Node("Players", null, "Get Orbit")]
    public class EventGetOrbitNode : EventValueNode
    {
        public const string Station = "Station", OrbitOut = "Orbit";

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            TextIn(context, Station, "78", "The station whose orbit: its number, its name (\"Var Hastra\") or \"void\"; or wire a number in.");
            context.AddOutputPort<Orbit>(OrbitOut).Build();
        }
    }

    [Serializable]
    [Node("Players", null, "Get Players")]
    public class EventGetPlayersNode : EventValueNode
    {
        public const string Who = "Who", OrbitIn = "Orbit", PlayersOut = "Players";

        protected override void OnDefineOptions(IOptionDefinitionContext context) =>
            context.AddOption<EventPlayersWho>(Who).WithTooltip("Everyone, alive in space, in space, docked, destroyed in space, the event's survivors (never " +
                "destroyed since its fight began), or one random player.").Build();

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            context.AddInputPort<Orbit>(OrbitIn).WithTooltip("Optional: only the players in this orbit (or docked at its station).").Build();
            context.AddOutputPort<Players>(PlayersOut).WithTooltip("Wire into a command's Players.").Build();
        }
    }

    [Serializable]
    [Node("Players", null, "Count Players")]
    public class EventCountPlayersNode : EventValueNode
    {
        public const string PlayersIn = "Players";

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            TextIn(context, PlayersIn, "@alive", "Whom to count: wire Get Players (or an On node's Player) in, or type a selector.");
            context.AddOutputPort<float>(Value).Build();
        }
    }

    // ---- values ------------------------------------------------------------------------------------------------------

    [Serializable]
    [Node("Values", null, "Game State")]
    public class EventStateNode : EventValueNode
    {
        public const string State = "State";

        protected override void OnDefineOptions(IOptionDefinitionContext context) =>
            context.AddOption<EventGameValue>(State).WithTooltip("Enemies / Ships: this event's living spawned ships (enemies only / all); Players: in the session; " +
                "In Space: alive in space; Docked; Dead: destroyed in space; Time: seconds since the event started; Top Points; Mission Station: " +
                "where a bar mission was taken (-1 in an /event; wire it into Get Orbit). This game's own: Campaign (the story step, -1 in free play), " +
                "Credits, Rank, Station (where the player is), System, Ship, Kills.").Build();

        protected override void OnDefinePorts(IPortDefinitionContext context) => context.AddOutputPort<float>(Value).Build();
    }

    [Serializable]
    [Node("Values", null, "Math")]
    public class EventMathNode : EventValueNode
    {
        public const string A = "A", B = "B", Op = "Op";

        protected override void OnDefineOptions(IOptionDefinitionContext context) =>
            context.AddOption<EventMathOp>(Op).WithTooltip("Divide / Modulo by 0 give 0.").Build();

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            context.AddInputPort<float>(A).Build();
            context.AddInputPort<float>(B).Build();
            context.AddOutputPort<float>(Value).Build();
        }
    }

    [Serializable]
    [Node("Values", null, "Random")]
    public class EventRandomNode : EventValueNode
    {
        public const string Min = "Min", Max = "Max";

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            NumberIn(context, Min, 1f, "Whole numbers from Min to Max, both included.");
            NumberIn(context, Max, 6f, "");
            context.AddOutputPort<float>(Value).Build();
        }
    }

    [Serializable]
    [Node("Values", null, "Floor")]
    public class EventFloorNode : EventValueNode
    {
        public const string Input = "Input";

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            context.AddInputPort<float>(Input).Build();
            context.AddOutputPort<float>(Value).Build();
        }
    }

    [Serializable]
    [Node("Values", null, "Compare")]
    public class EventCompareNode : EventValueNode
    {
        public const string A = "A", B = "B", Op = "Op";

        protected override void OnDefineOptions(IOptionDefinitionContext context) => context.AddOption<EventCompareOp>(Op).Build();

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            context.AddInputPort<float>(A).Build();
            context.AddInputPort<float>(B).Build();
            context.AddOutputPort<bool>(Result).Build();
        }
    }

    [Serializable]
    [Node("Values", null, "Logic")]
    public class EventLogicNode : EventValueNode
    {
        public const string A = "A", B = "B", Op = "Op";

        protected override void OnDefineOptions(IOptionDefinitionContext context) => context.AddOption<EventLogicOp>(Op).Build();

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            context.AddInputPort<bool>(A).Build();
            context.AddInputPort<bool>(B).Build();
            context.AddOutputPort<bool>(Result).Build();
        }
    }

    [Serializable]
    [Node("Values", null, "Not")]
    public class EventNotNode : EventValueNode
    {
        public const string Input = "Input";

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            context.AddInputPort<bool>(Input).Build();
            context.AddOutputPort<bool>(Result).Build();
        }
    }

    [Serializable]
    [Node("Values", null, "Expression")]
    public class EventExpressionNode : EventValueNode
    {
        public const string Text = "Text", Number = "Number", Condition = "Condition";

        protected override void OnDefineOptions(IOptionDefinitionContext context) =>
            context.AddOption<string>(Text).WithTooltip("Any script expression: numbers, variables, game values, + - * / %, comparisons, and / or / not, random(a, b), min, max, floor.")
                .WithDefaultValue("0").Delayed().Build();

        protected override void OnDefinePorts(IPortDefinitionContext context)
        {
            context.AddOutputPort<float>(Number).Build();
            context.AddOutputPort<bool>(Condition).Build();
        }
    }
}
