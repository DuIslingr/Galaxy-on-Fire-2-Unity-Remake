// ModProjectRaces.cs
// Remake-only (part of ModProject): the mod's own races (races.json, ProjectRace; ModRaces, Modding/README.md "Races"): a
// new one, finding one, what in the project names it (its systems' owner / locals / raiders, its ships' race and traffic
// races, the other races' relations) and removing it with those references, so nothing is left naming a race that is
// gone: an owner or a ship's race goes back to the race's look, list entries and relations go. A mod race is named by its
// id or by the project's key for it ("my_mod:guild"). Plain C#.

using System;
using System.Linq;
using Newtonsoft.Json.Linq;

namespace GoF2Remake.Modding
{
    public partial class ModProject
    {
        public string RaceIdFor(string name) => UniqueId(name, "race", id => Races.Any(r => r.Id == id));

        /// <summary>A new race of the mod (Terran's look, a standing of 0, neutral to everyone it doesn't name).</summary>
        public ProjectRace AddRace(string name)
        {
            var r = new ProjectRace(new JObject { ["id"] = RaceIdFor(name), ["name"] = name, ["look"] = "terran" });
            Races.Add(r);
            return r;
        }

        public ProjectRace FindRace(string id) => Races.Find(r => string.Equals(r.Id, id, StringComparison.Ordinal));

        /// <summary>The project's own race a reference names (its id, or this project's key for it), else null.</summary>
        public ProjectRace OwnRace(string reference)
        {
            if (string.IsNullOrEmpty(reference)) return null;
            string prefix = Id + ":";
            string id = reference.StartsWith(prefix, StringComparison.Ordinal) ? reference.Substring(prefix.Length) : reference;
            return id.IndexOf(':') >= 0 ? null : FindRace(id);
        }

        bool Names(string reference, ProjectRace r) => r != null && OwnRace(reference) == r;

        /// <summary>How many places in the project name 'r': systems' owners, locals and raiders, ships' race and traffic races,
        /// the other races' relations.</summary>
        public int RaceUses(ProjectRace r)
        {
            int n = 0;
            foreach (var s in Systems)
            {
                if (Names(s.ModRace, r)) n++;
                n += s.Locals.Count(x => Names(x, r)) + s.Raiders.Count(x => Names(x, r));
            }
            foreach (var s in Ships)
            {
                if (Names(s.ModRace, r)) n++;
                n += s.TrafficRaces.Count(x => Names(x, r));
            }
            foreach (var o in Races) if (o != r) n += o.Relations.Count(x => Names(x.other, r));
            return n;
        }

        /// <summary>Removes a mod race and every reference to it in the project: a system it owned or a ship it built goes back
        /// to its look race (a system to Terran when that is the pirates' or the Void's), list entries and relations naming it
        /// go. Other mods' references to it are theirs (the game warns of them).</summary>
        public void RemoveRace(ProjectRace r)
        {
            if (r == null || !Races.Contains(r)) return;
            int look = r.LookRace;
            foreach (var s in Systems)
            {
                if (Names(s.ModRace, r)) s.Race = look <= 3 ? look : 0;
                if (s.Locals.Any(x => Names(x, r))) s.Locals = s.Locals.Where(x => !Names(x, r)).ToList();
                if (s.Raiders.Any(x => Names(x, r))) s.Raiders = s.Raiders.Where(x => !Names(x, r)).ToList();
            }
            foreach (var s in Ships)
            {
                if (Names(s.ModRace, r)) s.Race = look;
                var traffic = s.TrafficRaces;
                if (traffic.Any(x => Names(x, r))) s.TrafficRaces = traffic.Where(x => !Names(x, r)).ToList();
            }
            foreach (var o in Races)
                if (o != r)
                    foreach (var (other, _) in o.Relations.Where(x => Names(x.other, r)).ToList()) o.SetRelation(other, null);
            Races.Remove(r);
        }
    }
}
