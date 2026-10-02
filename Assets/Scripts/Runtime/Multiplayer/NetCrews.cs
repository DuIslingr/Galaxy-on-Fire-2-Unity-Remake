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
// Phase 2, territory:
//   Bank: "/crew deposit N" takes N credits from the player (ChargeRpc: their game pays if it can and answers) into the
//     bank; "/crew withdraw N" (officers) pays N out to the player (GrantRpc). Both move the profile's worth with them
//     (NetProfiles.AdjustWorth), so the upload check neither trips on a withdrawal nor lets a deposit that wasn't paid
//     go unnoticed for long (the client still runs its credits: a modified game can lie about paying).
//   Claims: "/crew claim" (officers, docked at the station) claims it for ClaimCost from the bank, at most MaxClaims per
//     crew; not the Kaamo Club (108) or Loma (system 25). The first claim is the home; "/crew home" (officers, docked at
//     another claim) moves it; "/crew unclaim" (officers, docked there) gives it up. A claim no member has docked at for
//     LapseDays lapses. The claims reach every player (NetState.Claims: "station|TAG|Name" lines; NetCrewsClient), who
//     see the owner on the star map, the station's header and the orbit information.
//   Home: a member signing in starts docked at the crew's home, and a destroyed member respawns there.

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
        const float InviteSeconds = 300f, ClaimTickSeconds = 60f, ChargeSeconds = 30f;
        public const int DefaultClaimCost = 500_000, DefaultMaxClaims = 3, DefaultLapseDays = 14;
        const int KaamoStation = 108, LomaSystem = 25;

        /// <summary>A claim's price from the bank (-claimcost), the claims per crew (-maxclaims), the days without a member
        /// docking before a claim lapses (-claimdays).</summary>
        public static int ClaimCost { get; private set; } = DefaultClaimCost;
        public static int MaxClaims { get; private set; } = DefaultMaxClaims;
        public static int LapseDays { get; private set; } = DefaultLapseDays;

        /// <summary>DedicatedServer.Boot: the command line's choices.</summary>
        public static void Configure(int claimCost, int maxClaims, int lapseDays)
        {
            ClaimCost = Mathf.Max(0, claimCost);
            MaxClaims = Mathf.Clamp(maxClaims, 0, 100);
            LapseDays = Mathf.Max(1, lapseDays);
        }

        [Serializable]
        public class Crew
        {
            public string id, name, tag, leader, created;
            public List<string> officers = new List<string>(), members = new List<string>();   // members include everyone
            public long bank;
            public int home = -1;
        }

        [Serializable] public class Claim { public int station; public string crew, claimed, lastDock; }

        [Serializable] class CrewList { public List<Crew> crews = new List<Crew>(); public List<Claim> claims = new List<Claim>(); }

        // Deposits waiting for the player's game to pay: by a token the server made (the amount is the server's own).
        static readonly Dictionary<int, (string account, string crew, int amount, float until)> charges = new Dictionary<int, (string, string, int, float)>();
        static int nextCharge = 1;
        static float claimTimer;

        static CrewList list;
        static readonly Dictionary<string, (string crew, float until)> invites = new Dictionary<string, (string, float)>();   // by profile id

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics()
        {
            list = null; invites.Clear(); charges.Clear(); claimTimer = 0f;
            ClaimCost = DefaultClaimCost; MaxClaims = DefaultMaxClaims; LapseDays = DefaultLapseDays;
        }

        static string PathOf => Path.Combine(NetProfiles.Folder, "crews.json");

        /// <summary>NetProfiles.Start: the crews loaded.</summary>
        public static void Load()
        {
            invites.Clear();
            try { list = File.Exists(PathOf) ? JsonUtility.FromJson<CrewList>(File.ReadAllText(PathOf)) : null; }
            catch (Exception e) { Debug.LogError($"NetCrews: crews.json unreadable ({e.Message}); starting a new list (the old file stays as .bak on the next write)."); list = null; }
            if (list == null) list = new CrewList();
            if (list.crews == null) list.crews = new List<Crew>();
            if (list.claims == null) list.claims = new List<Claim>();
            foreach (var c in list.crews) { c.officers ??= new List<string>(); c.members ??= new List<string>(); }
            charges.Clear();
            PublishClaims();
        }

        static void Save() { if (list != null) NetProfiles.Write(PathOf, JsonUtility.ToJson(list, true)); }

        /// <summary>The crew a profile belongs to, null = none.</summary>
        public static Crew Of(string account) => account == null || list == null ? null : list.crews.Find(c => c.members.Contains(account));

        /// <summary>The crew of a connected player, null = none (or a guest).</summary>
        public static Crew OfClient(ulong client) => Of(NetProfiles.AccountOf(client));

        static Crew ByTag(string tag) => list?.crews.Find(c => string.Equals(c.tag, tag, StringComparison.OrdinalIgnoreCase));

        static bool IsOfficer(Crew c, string account) => c.leader == account || c.officers.Contains(account);

        // ---- names --------------------------------------------------------------------------------------------

        /// <summary>NetProfiles: a player signed in (or linked): their crew's tag on their name, its home.</summary>
        public static void OnLogin(ulong client) => RefreshTag(client);

        static void RefreshTag(ulong client)
        {
            var p = NetSquad.Find(client);
            if (p == null) return;
            p.SetCrewTag(OfClient(client)?.tag ?? "");
            p.SetCrewHome(HomeOf(NetProfiles.AccountOf(client)));
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
                case "deposit": return Deposit(client, me, arg);
                case "withdraw": return Withdraw(client, me, arg);
                case "claim": return ClaimHere(client, me);
                case "unclaim": return Unclaim(client, me);
                case "home": return SetHome(client, me);
                case "claims": return ClaimsText(arg.Length > 0 ? ByTag(arg) : Of(me));
                default:
                    return Localization.Extra("mpCrewHelp", "Crew commands: /crew create TAG Name, invite <pilot>, join TAG, leave, kick <pilot>, " +
                                                            "promote / demote <pilot>, leader <pilot>, disband, info [TAG], list; deposit N, withdraw N; " +
                                                            "claim, unclaim, home, claims [TAG] (docked at the station); /c <text> talks to your crew.");
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
            list.claims.RemoveAll(c => c.crew == crew.id);   // its territory is free again (the bank goes with it)
            PublishClaims();
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
            sb.Append($". Bank {crew.bank:N0}");
            var claims = list.claims.FindAll(c => c.crew == crew.id);
            if (claims.Count > 0) sb.Append(". Territory: ").Append(string.Join(", ", claims.ConvertAll(c => StationName(c.station) + (c.station == crew.home ? " (home)" : ""))));
            sb.Append('.');
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
            if (crew.members.Count == 0)
            {
                list.crews.Remove(crew);
                list.claims.RemoveAll(c => c.crew == crew.id);
                PublishClaims();
                Debug.Log($"Server: crew [{crew.tag}] {crew.name} ended (no members).");
            }
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

        // ---- the bank ---------------------------------------------------------------------------------------

        static bool TryAmount(string arg, out int amount) => int.TryParse(arg.Replace(",", "").Replace(".", "").Replace(" ", ""), out amount) && amount > 0;

        static string Deposit(ulong client, string me, string arg)
        {
            var crew = Of(me);
            if (crew == null) return Localization.Extra("mpCrewNone", "You aren't in a crew.");
            if (!TryAmount(arg, out int amount)) return "/crew deposit N";
            if (!NetProfiles.Controls(client)) return Localization.Extra("mpCrewController", "Do that on the device that controls your profile.");
            int token = nextCharge++;
            charges[token] = (me, crew.id, amount, Time.realtimeSinceStartup + ChargeSeconds);
            NetState.Instance?.Charge(client, token, amount);
            return "";
        }

        /// <summary>NetState.ChargedRpc: the player's game paid a deposit (or couldn't: not enough credits).</summary>
        public static void OnCharged(ulong client, int token, bool paid)
        {
            if (!charges.TryGetValue(token, out var c) || c.account != NetProfiles.AccountOf(client)) return;
            charges.Remove(token);
            var crew = list?.crews.Find(x => x.id == c.crew);
            if (!paid) { NetState.Instance?.Notify(client, Localization.Extra("mpCrewNoCredits", "You don't have that many credits.")); return; }
            NetProfiles.AdjustWorth(c.account, -c.amount);
            if (crew == null) { Grant(client, c.account, c.amount); return; }   // the crew went meanwhile: back to the player
            crew.bank += c.amount;
            Save();
            TellCrew(crew, string.Format(Localization.Extra("mpCrewDeposited", "{0} put {1:N0} credits into the bank ({2:N0})."), NameOf(c.account), c.amount, crew.bank));
        }

        static string Withdraw(ulong client, string me, string arg)
        {
            var crew = Of(me);
            if (crew == null || !IsOfficer(crew, me)) return Localization.Extra("mpCrewNotOfficer", "Only a crew's leader and officers can do that.");
            if (!TryAmount(arg, out int amount)) return "/crew withdraw N";
            if (!NetProfiles.Controls(client)) return Localization.Extra("mpCrewController", "Do that on the device that controls your profile.");
            if (crew.bank < amount) return string.Format(Localization.Extra("mpCrewBankShort", "The bank has {0:N0} credits."), crew.bank);
            crew.bank -= amount;
            Save();
            Grant(client, me, amount);
            TellCrew(crew, string.Format(Localization.Extra("mpCrewWithdrew", "{0} took {1:N0} credits from the bank ({2:N0})."), NameOf(me), amount, crew.bank));
            return "";
        }

        /// <summary>Credits to the player's game; their profile's worth moves with it (the upload check).</summary>
        static void Grant(ulong client, string account, int amount)
        {
            NetProfiles.AdjustWorth(account, amount);
            NetState.Instance?.Grant(client, amount);
        }

        // ---- territory --------------------------------------------------------------------------------------

        static string StationName(int station)
        {
            var st = NetGame.Db.Stations.Find(s => s.index == station);
            return st != null ? st.name : $"station {station}";
        }

        static Claim ClaimAt(int station) => list?.claims.Find(c => c.station == station);

        /// <summary>The player's station while docked there (-1 = not docked).</summary>
        static int DockedAt(ulong client)
        {
            var p = NetSquad.Find(client);
            return p != null && p.InHangar ? p.Station : -1;
        }

        static string ClaimHere(ulong client, string me)
        {
            var crew = Of(me);
            if (crew == null || !IsOfficer(crew, me)) return Localization.Extra("mpCrewNotOfficer", "Only a crew's leader and officers can do that.");
            int station = DockedAt(client);
            var st = NetGame.Db.Stations.Find(s => s.index == station);
            if (st == null) return Localization.Extra("mpCrewDockFirst", "Dock at the station first.");
            if (station == KaamoStation || st.system == LomaSystem) return Localization.Extra("mpCrewNotClaimable", "This station can't be claimed.");
            var held = ClaimAt(station);
            if (held != null)
            {
                var owner = list.crews.Find(c => c.id == held.crew);
                return held.crew == crew.id ? Localization.Extra("mpCrewOwnClaim", "Your crew holds this station already.")
                                            : string.Format(Localization.Extra("mpCrewClaimedBy", "[{0}] {1} holds this station."), owner?.tag, owner?.name);
            }
            int count = list.claims.FindAll(c => c.crew == crew.id).Count;
            if (count >= MaxClaims) return string.Format(Localization.Extra("mpCrewMaxClaims", "A crew holds at most {0} stations."), MaxClaims);
            if (crew.bank < ClaimCost)
                return string.Format(Localization.Extra("mpCrewClaimCost", "A claim costs {0:N0} credits from the bank (it has {1:N0}): /crew deposit N."), ClaimCost, crew.bank);
            crew.bank -= ClaimCost;
            string now = DateTime.UtcNow.ToString("o");
            list.claims.Add(new Claim { station = station, crew = crew.id, claimed = now, lastDock = now });
            if (crew.home < 0 || ClaimAt(crew.home)?.crew != crew.id) crew.home = station;
            Save();
            PublishClaims();
            RefreshHomes(crew);
            Debug.Log($"Server: [{crew.tag}] claimed {st.name}.");
            NetState.Instance?.Announce(string.Format(Localization.Extra("mpCrewClaimedNews", "[{0}] {1} claimed {2}."), crew.tag, crew.name, st.name));
            return "";
        }

        static string Unclaim(ulong client, string me)
        {
            var crew = Of(me);
            if (crew == null || !IsOfficer(crew, me)) return Localization.Extra("mpCrewNotOfficer", "Only a crew's leader and officers can do that.");
            var held = ClaimAt(DockedAt(client));
            if (held == null || held.crew != crew.id) return Localization.Extra("mpCrewNotYours", "Dock at one of your crew's stations first.");
            list.claims.Remove(held);
            if (crew.home == held.station) crew.home = list.claims.Find(c => c.crew == crew.id)?.station ?? -1;
            Save();
            PublishClaims();
            RefreshHomes(crew);
            TellCrew(crew, string.Format(Localization.Extra("mpCrewUnclaimed", "Your crew gave up {0}."), StationName(held.station)));
            return "";
        }

        static string SetHome(ulong client, string me)
        {
            var crew = Of(me);
            if (crew == null || !IsOfficer(crew, me)) return Localization.Extra("mpCrewNotOfficer", "Only a crew's leader and officers can do that.");
            var held = ClaimAt(DockedAt(client));
            if (held == null || held.crew != crew.id) return Localization.Extra("mpCrewNotYours", "Dock at one of your crew's stations first.");
            crew.home = held.station;
            Save();
            RefreshHomes(crew);
            TellCrew(crew, string.Format(Localization.Extra("mpCrewHome", "{0} is your crew's home now."), StationName(held.station)));
            return "";
        }

        static double DaysSince(string utc) =>
            DateTime.TryParse(utc, null, System.Globalization.DateTimeStyles.RoundtripKind, out var t) ? (DateTime.UtcNow - t.ToUniversalTime()).TotalDays : 0;

        static string ClaimsText(Crew crew)
        {
            if (crew == null) return Localization.Extra("mpCrewNone", "You aren't in a crew.");
            var claims = list.claims.FindAll(c => c.crew == crew.id);
            if (claims.Count == 0) return string.Format(Localization.Extra("mpCrewNoClaims", "[{0}] holds no stations."), crew.tag);
            var sb = new StringBuilder($"[{crew.tag}] {crew.name}:");
            foreach (var c in claims)
                sb.Append($"\n{StationName(c.station)}{(c.station == crew.home ? " (home)" : "")}: lapses in {Math.Max(0, LapseDays - DaysSince(c.lastDock)):0.#} days without a member docking");
            return sb.ToString();
        }

        /// <summary>A profile's crew home station, -1 = none (NetProfiles: where a member's game starts).</summary>
        public static int HomeOf(string account)
        {
            var crew = Of(account);
            return crew != null && ClaimAt(crew.home)?.crew == crew.id ? crew.home : -1;
        }

        static void RefreshHomes(Crew crew)
        {
            foreach (var m in crew.members)
                foreach (ulong c in NetProfiles.ClientsOf(m)) NetSquad.Find(c)?.SetCrewHome(HomeOf(m));
        }

        /// <summary>Every claim to the players (NetState.Claims): "station|TAG|Name" per line.</summary>
        static void PublishClaims()
        {
            if (list == null || NetState.Instance == null) return;
            var sb = new StringBuilder();
            foreach (var c in list.claims)
            {
                var crew = list.crews.Find(x => x.id == c.crew);
                if (crew != null) sb.Append(c.station).Append('|').Append(crew.tag).Append('|').Append(crew.name.Replace("|", " ")).Append('\n');
            }
            NetState.Instance.SetClaims(sb.ToString());
        }

        /// <summary>NetState: spawned on the server (the claims go out once it exists).</summary>
        public static void OnStateSpawned() => PublishClaims();

        /// <summary>NetState.Update (server): members docked at a claim keep it; claims nobody kept lapse; old deposits drop.</summary>
        public static void Tick()
        {
            if (list == null) return;
            if (charges.Count > 0)
                foreach (var key in new List<int>(charges.Keys)) if (charges[key].until < Time.realtimeSinceStartup) charges.Remove(key);
            if ((claimTimer -= Time.unscaledDeltaTime) > 0f) return;
            claimTimer = ClaimTickSeconds;
            if (list.claims.Count == 0) return;
            bool changed = false;
            string now = DateTime.UtcNow.ToString("o");
            foreach (var p in NetPlayer.All)
            {
                if (p == null || !p.IsSpawned || !p.InHangar) continue;
                var held = ClaimAt(p.Station);
                var crew = held != null ? OfClient(p.OwnerClientId) : null;
                if (crew != null && crew.id == held.crew) { held.lastDock = now; changed = true; }
            }
            foreach (var c in new List<Claim>(list.claims))
            {
                if (DaysSince(c.lastDock) < LapseDays) continue;
                list.claims.Remove(c);
                var crew = list.crews.Find(x => x.id == c.crew);
                if (crew != null)
                {
                    if (crew.home == c.station) crew.home = list.claims.Find(x => x.crew == crew.id)?.station ?? -1;
                    TellCrew(crew, string.Format(Localization.Extra("mpCrewLapsed", "Nobody of your crew docked at {0} for {1} days: the claim lapsed."), StationName(c.station), LapseDays));
                    RefreshHomes(crew);
                }
                Debug.Log($"Server: the claim on {StationName(c.station)} lapsed.");
                changed = true;
            }
            if (changed) { Save(); PublishClaims(); }
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
