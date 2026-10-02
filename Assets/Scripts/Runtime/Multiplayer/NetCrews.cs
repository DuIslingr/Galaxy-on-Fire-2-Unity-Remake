// NetCrews.cs
// Remake-only: crews, the lasting player groups of a dedicated server with profiles (NetProfiles). A squad (NetSquad)
// stays the session's quick group for flying together (shared missions, no friendly fire); a crew is kept between
// sessions by profile and is what will hold territory (home station, claims, bank: later phases).
//   A crew: a name (MaxNameLength), a tag of 2-4 letters / digits shown before its members' names ("[TAG] Name": the
//     lock plate, chat), a leader, officers and members (profile ids), a bank (credits, for the later phases) and a home
//     station (-1 = none yet).
//   Chat commands (answered to the sender only): /crew create TAG Name, /crew invite <pilot>, /crew join TAG,
//     /crew leave, /crew kick <pilot>, /crew promote / demote <pilot>, /crew leader <pilot>, /crew disband,
//     /crew info [TAG], /crew list; "/c <text>" talks to the crew members online.
//   Ranks: the leader does everything; officers invite and kick members; members talk. The leader leaves only by
//     handing over (/crew leader) or as the last member (the crew ends).
//   Storage: crews.json beside the profiles (NetProfiles.Folder), written like them (through .tmp, the old one as .bak).
//   A profile deleted (the console, a /link that replaces it) leaves its crew; a leaderless crew passes to its first
//   officer, else its first member.

using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using GoF2Remake.Data;
using UnityEngine;

namespace GoF2Remake.Multiplayer
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public static class NetCrews
    {
        public const int MaxNameLength = 24, MaxMembers = 50;
        const float InviteSeconds = 300f;

        [Serializable]
        public class Crew
        {
            public string id, name, tag, leader, created;
            public List<string> officers = new List<string>(), members = new List<string>();   // members include everyone
            public long bank;
            public int home = -1;
        }

        [Serializable] class CrewList { public List<Crew> crews = new List<Crew>(); }

        static CrewList list;
        static readonly Dictionary<string, (string crew, float until)> invites = new Dictionary<string, (string, float)>();   // by profile id

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() { list = null; invites.Clear(); }

        static string PathOf => Path.Combine(NetProfiles.Folder, "crews.json");

        /// <summary>NetProfiles.Start: the crews loaded.</summary>
        public static void Load()
        {
            invites.Clear();
            try { list = File.Exists(PathOf) ? JsonUtility.FromJson<CrewList>(File.ReadAllText(PathOf)) : null; }
            catch (Exception e) { Debug.LogError($"NetCrews: crews.json unreadable ({e.Message}); starting a new list (the old file stays as .bak on the next write)."); list = null; }
            if (list == null) list = new CrewList();
            if (list.crews == null) list.crews = new List<Crew>();
            foreach (var c in list.crews) { c.officers ??= new List<string>(); c.members ??= new List<string>(); }
        }

        static void Save() { if (list != null) NetProfiles.Write(PathOf, JsonUtility.ToJson(list, true)); }

        /// <summary>The crew a profile belongs to, null = none.</summary>
        public static Crew Of(string account) => account == null || list == null ? null : list.crews.Find(c => c.members.Contains(account));

        /// <summary>The crew of a connected player, null = none (or a guest).</summary>
        public static Crew OfClient(ulong client) => Of(NetProfiles.AccountOf(client));

        static Crew ByTag(string tag) => list?.crews.Find(c => string.Equals(c.tag, tag, StringComparison.OrdinalIgnoreCase));

        static bool IsOfficer(Crew c, string account) => c.leader == account || c.officers.Contains(account);

        // ---- names --------------------------------------------------------------------------------------------

        /// <summary>NetProfiles: a player signed in (or linked): their crew's tag on their name.</summary>
        public static void OnLogin(ulong client) => RefreshTag(client);

        static void RefreshTag(ulong client)
        {
            var p = NetSquad.Find(client);
            if (p != null) p.SetCrewTag(OfClient(client)?.tag ?? "");
        }

        static void RefreshTags(string account) { foreach (ulong c in NetProfiles.ClientsOf(account)) RefreshTag(c); }

        static void Tell(string account, string text) { foreach (ulong c in NetProfiles.ClientsOf(account)) NetState.Instance?.Notify(c, text); }

        static void TellCrew(Crew crew, string text) { foreach (var m in crew.members) Tell(m, text); }

        static string NameOf(string account) => NetProfiles.AccountName(account) ?? account;

        /// <summary>A crew member by the pilot name (online or not; the profile's last name).</summary>
        static string MemberByName(Crew crew, string name)
        {
            foreach (var m in crew.members) if (string.Equals(NameOf(m), name, StringComparison.OrdinalIgnoreCase)) return m;
            return null;
        }

        // ---- chat commands ----------------------------------------------------------------------------------

        /// <summary>NetState.SendChatRpc: a /crew or /c command's answer to its sender; null = not one of them.</summary>
        public static string Command(ulong client, string text)
        {
            var words = text.Trim().Split(new[] { ' ' }, 3, StringSplitOptions.RemoveEmptyEntries);
            string cmd = words.Length > 0 ? words[0].ToLowerInvariant() : "";
            if (cmd != "/crew" && cmd != "/c") return null;
            string me = NetProfiles.AccountOf(client);
            if (me == null) return Localization.Extra("mpCrewGuest", "Crews need a profile on this server (you play as a guest).");
            if (cmd == "/c") return Talk(me, text.Trim().Length > 2 ? text.Trim().Substring(2).Trim() : "");
            string sub = words.Length > 1 ? words[1].ToLowerInvariant() : "info";
            string arg = words.Length > 2 ? words[2].Trim() : "";
            switch (sub)
            {
                case "create": return Create(me, arg);
                case "invite": return Invite(me, arg);
                case "join": return Join(me, arg);
                case "leave": return Leave(me);
                case "kick": return Kick(me, arg);
                case "promote": return SetOfficer(me, arg, true);
                case "demote": return SetOfficer(me, arg, false);
                case "leader": return HandOver(me, arg);
                case "disband": return Disband(me);
                case "info": return Info(arg.Length > 0 ? ByTag(arg) : Of(me), arg);
                case "list": return ListText();
                default:
                    return Localization.Extra("mpCrewHelp", "Crew commands: /crew create TAG Name, invite <pilot>, join TAG, leave, kick <pilot>, " +
                                                            "promote / demote <pilot>, leader <pilot>, disband, info [TAG], list; /c <text> talks to your crew.");
            }
        }

        static string Create(string me, string arg)
        {
            if (Of(me) != null) return Localization.Extra("mpCrewAlready", "You are in a crew already: /crew leave first.");
            int space = arg.IndexOf(' ');
            string tag = (space < 0 ? arg : arg.Substring(0, space)).ToUpperInvariant();
            string name = space < 0 ? "" : NetGame.Clean(arg.Substring(space + 1));
            if (name.Length > MaxNameLength) name = name.Substring(0, MaxNameLength);
            if (tag.Length < 2 || tag.Length > 4 || !IsTag(tag) || name.Length == 0)
                return Localization.Extra("mpCrewCreateUsage", "/crew create TAG Name: a tag of 2-4 letters or digits, then the crew's name.");
            if (ByTag(tag) != null) return string.Format(Localization.Extra("mpCrewTagTaken", "The tag {0} is taken."), tag);
            if (list.crews.Exists(c => string.Equals(c.name, name, StringComparison.OrdinalIgnoreCase)))
                return string.Format(Localization.Extra("mpCrewNameTaken", "A crew called {0} exists already."), name);
            var crew = new Crew { id = Guid.NewGuid().ToString("N").Substring(0, 8), name = name, tag = tag, leader = me, created = DateTime.UtcNow.ToString("o") };
            crew.members.Add(me);
            list.crews.Add(crew);
            Save();
            RefreshTags(me);
            Debug.Log($"Server: crew [{tag}] {name} created by {NameOf(me)}.");
            return string.Format(Localization.Extra("mpCrewCreated", "Crew [{0}] {1} created. /crew invite <pilot> to bring others in."), tag, name);
        }

        static bool IsTag(string tag)
        {
            foreach (char c in tag) if (!(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9')) return false;
            return true;
        }

        static string Invite(string me, string who)
        {
            var crew = Of(me);
            if (crew == null || !IsOfficer(crew, me)) return Localization.Extra("mpCrewNotOfficer", "Only a crew's leader and officers can do that.");
            if (crew.members.Count >= MaxMembers) return string.Format(Localization.Extra("mpCrewFull", "The crew is full ({0})."), MaxMembers);
            NetPlayer target = null;
            foreach (var p in NetPlayer.All)
                if (p != null && p.IsSpawned && string.Equals(p.DisplayName, who, StringComparison.OrdinalIgnoreCase)) { target = p; break; }
            string account = target != null ? NetProfiles.AccountOf(target.OwnerClientId) : null;
            if (account == null) return string.Format(Localization.Extra("mpCrewNoPilot", "No pilot with a profile called \"{0}\" online."), who);
            if (Of(account) != null) return string.Format(Localization.Extra("mpCrewTheyHaveOne", "{0} is in a crew already."), target.DisplayName);
            invites[account] = (crew.id, Time.realtimeSinceStartup + InviteSeconds);
            Tell(account, string.Format(Localization.Extra("mpCrewInvited", "{0} invites you to the crew [{1}] {2}: type /crew join {1}."), NameOf(me), crew.tag, crew.name));
            return string.Format(Localization.Extra("mpCrewInviteSent", "Invitation sent to {0} (5 minutes)."), target.DisplayName);
        }

        static string Join(string me, string tag)
        {
            if (Of(me) != null) return Localization.Extra("mpCrewAlready", "You are in a crew already: /crew leave first.");
            var crew = ByTag(tag);
            if (crew == null || !invites.TryGetValue(me, out var inv) || inv.crew != crew.id || inv.until < Time.realtimeSinceStartup)
                return Localization.Extra("mpCrewNoInvite", "You have no invitation from that crew.");
            if (crew.members.Count >= MaxMembers) return string.Format(Localization.Extra("mpCrewFull", "The crew is full ({0})."), MaxMembers);
            invites.Remove(me);
            crew.members.Add(me);
            Save();
            RefreshTags(me);
            TellCrew(crew, string.Format(Localization.Extra("mpCrewJoined", "{0} joined the crew."), NameOf(me)));
            return "";
        }

        static string Leave(string me)
        {
            var crew = Of(me);
            if (crew == null) return Localization.Extra("mpCrewNone", "You aren't in a crew.");
            if (crew.leader == me && crew.members.Count > 1)
                return Localization.Extra("mpCrewLeaderLeave", "Hand the crew over first (/crew leader <pilot>), or /crew disband.");
            Remove(crew, me);
            return Localization.Extra("mpCrewYouLeft", "You left the crew.");
        }

        static string Kick(string me, string who)
        {
            var crew = Of(me);
            if (crew == null || !IsOfficer(crew, me)) return Localization.Extra("mpCrewNotOfficer", "Only a crew's leader and officers can do that.");
            string target = MemberByName(crew, who);
            if (target == null) return string.Format(Localization.Extra("mpCrewNoMember", "No crew member called \"{0}\"."), who);
            if (target == me) return Localization.Extra("mpCrewKickSelf", "Use /crew leave.");
            if (target == crew.leader || (crew.officers.Contains(target) && crew.leader != me))
                return Localization.Extra("mpCrewKickRank", "Only the leader can remove an officer, and nobody the leader.");
            Tell(target, string.Format(Localization.Extra("mpCrewKicked", "You were removed from the crew [{0}]."), crew.tag));
            Remove(crew, target);
            return "";
        }

        static string SetOfficer(string me, string who, bool on)
        {
            var crew = Of(me);
            if (crew == null || crew.leader != me) return Localization.Extra("mpCrewNotLeader", "Only the crew's leader can do that.");
            string target = MemberByName(crew, who);
            if (target == null || target == me) return string.Format(Localization.Extra("mpCrewNoMember", "No crew member called \"{0}\"."), who);
            if (on && !crew.officers.Contains(target)) crew.officers.Add(target);
            if (!on) crew.officers.Remove(target);
            Save();
            TellCrew(crew, string.Format(on ? Localization.Extra("mpCrewPromoted", "{0} is an officer now.") : Localization.Extra("mpCrewDemoted", "{0} is no officer any more."), NameOf(target)));
            return "";
        }

        static string HandOver(string me, string who)
        {
            var crew = Of(me);
            if (crew == null || crew.leader != me) return Localization.Extra("mpCrewNotLeader", "Only the crew's leader can do that.");
            string target = MemberByName(crew, who);
            if (target == null || target == me) return string.Format(Localization.Extra("mpCrewNoMember", "No crew member called \"{0}\"."), who);
            crew.leader = target;
            crew.officers.Remove(target);
            if (!crew.officers.Contains(me)) crew.officers.Add(me);   // the old leader stays an officer
            Save();
            TellCrew(crew, string.Format(Localization.Extra("mpCrewNewLeader", "{0} leads the crew now."), NameOf(target)));
            return "";
        }

        static string Disband(string me)
        {
            var crew = Of(me);
            if (crew == null || crew.leader != me) return Localization.Extra("mpCrewNotLeader", "Only the crew's leader can do that.");
            TellCrew(crew, string.Format(Localization.Extra("mpCrewDisbanded", "The crew [{0}] {1} was disbanded."), crew.tag, crew.name));
            var members = new List<string>(crew.members);
            list.crews.Remove(crew);
            Save();
            foreach (var m in members) RefreshTags(m);
            Debug.Log($"Server: crew [{crew.tag}] {crew.name} disbanded.");
            return "";
        }

        static string Talk(string me, string text)
        {
            var crew = Of(me);
            if (crew == null) return Localization.Extra("mpCrewNone", "You aren't in a crew.");
            text = NetChat.Clean(text);
            if (text.Length == 0) return "/c <text>";
            TellCrew(crew, $"[{crew.tag}] {NameOf(me)}: {text}");
            Debug.Log($"[Crew {crew.tag}] {NameOf(me)}: {text}");
            return "";
        }

        static string Info(Crew crew, string asked)
        {
            if (crew == null)
                return asked.Length > 0 ? string.Format(Localization.Extra("mpCrewNoTag", "No crew with the tag {0}."), asked.ToUpperInvariant())
                                        : Localization.Extra("mpCrewNoneHelp", "You aren't in a crew. /crew create TAG Name, or ask a crew for an invitation; /crew list shows them.");
            var sb = new StringBuilder($"[{crew.tag}] {crew.name}: {crew.members.Count} member(s), leader {NameOf(crew.leader)}");
            if (crew.officers.Count > 0) sb.Append(", officers ").Append(string.Join(", ", crew.officers.ConvertAll(NameOf)));
            var online = crew.members.FindAll(m => NetProfiles.IsOnline(m));
            sb.Append(online.Count > 0 ? ". Online: " + string.Join(", ", online.ConvertAll(NameOf)) : ". Nobody online");
            sb.Append($". Bank {crew.bank:N0}.");
            return sb.ToString();
        }

        static string ListText()
        {
            if (list == null || list.crews.Count == 0) return Localization.Extra("mpCrewNoCrews", "No crews yet. /crew create TAG Name starts one.");
            var sb = new StringBuilder(Localization.Extra("mpCrewListTitle", "Crews:"));
            foreach (var c in list.crews) sb.Append($"\n[{c.tag}] {c.name}: {c.members.Count}");
            return sb.ToString();
        }

        /// <summary>A member out of the crew (left, kicked, profile deleted); an emptied crew ends, a leaderless one passes on.</summary>
        static void Remove(Crew crew, string account)
        {
            crew.members.Remove(account);
            crew.officers.Remove(account);
            invites.Remove(account);
            if (crew.members.Count == 0) { list.crews.Remove(crew); Debug.Log($"Server: crew [{crew.tag}] {crew.name} ended (no members)."); }
            else
            {
                if (crew.leader == account)
                {
                    crew.leader = crew.officers.Count > 0 ? crew.officers[0] : crew.members[0];
                    crew.officers.Remove(crew.leader);
                    TellCrew(crew, string.Format(Localization.Extra("mpCrewNewLeader", "{0} leads the crew now."), NameOf(crew.leader)));
                }
                TellCrew(crew, string.Format(Localization.Extra("mpCrewMemberLeft", "{0} left the crew."), NameOf(account)));
            }
            Save();
            RefreshTags(account);
        }

        /// <summary>NetProfiles: a profile was deleted.</summary>
        public static void OnAccountDeleted(string account)
        {
            var crew = Of(account);
            if (crew != null) Remove(crew, account);
        }

        // ---- the server console -----------------------------------------------------------------------------

        /// <summary>DedicatedServer's "crews" command.</summary>
        public static string ConsoleList()
        {
            if (list == null) return "Crews need player profiles (-noprofiles is set).";
            if (list.crews.Count == 0) return "No crews.";
            var sb = new StringBuilder($"{list.crews.Count} crew(s):");
            foreach (var c in list.crews)
                sb.Append($"\n  [{c.tag}] {c.name}: {c.members.Count} member(s), leader {NameOf(c.leader)}, bank {c.bank:N0}");
            return sb.ToString();
        }

        /// <summary>DedicatedServer's "crew disband TAG".</summary>
        public static string ConsoleDisband(string tag)
        {
            var crew = ByTag(tag);
            if (crew == null) return $"No crew with the tag {tag}.";
            return Disband(crew.leader) == "" ? $"Disbanded [{crew.tag}] {crew.name}." : "Could not disband it.";
        }
    }
}
