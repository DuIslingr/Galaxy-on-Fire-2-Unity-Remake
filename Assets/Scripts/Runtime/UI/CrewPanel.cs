// CrewPanel.cs
// Remake-only: the station's Crew / Arena / Profile (/ Admin) window in a multiplayer session, the buttons for everything the chat
// commands do (NetCrews, NetArena, NetProfiles). A "CREW · ARENA" plate under the station's information opens it (a
// dot on it when a crew invitation or a duel challenge waits). Three tabs:
//   Crew: invitations (Join), without a crew a Create form and the crews; in one: the bank (Deposit / Withdraw), the
//     members (Promote / Demote / Make leader / Kick by rank), the pilots online to Invite, the territory (the claims,
//     and for the station docked at: Claim / Make home / Unclaim / Siege), the sieges, Leave / Disband (asked twice);
//   Arena: a challenge waiting (Accept / Decline), the Void fighters option, the pilots to Challenge, the free-for-all
//     queue (Join / Leave), the matches, the leaderboard;
//   Profile: the profile, Take control (another device controls it), Get a link code, Link with a code (+ force);
//   Admin (only for the server's ops, admins and masters, NetAdmin): a reason and minutes field, every pilot online
//     with Kick (the minutes as the cooldown), Ban for the minutes, Ban for good and the roles (admins: op; masters:
//     admin), the bans with Unban; for admins also the server's status and an announcement, the staff, every profile
//     (a filter; Ban / Unban, roles, Delete for masters, asked twice) and the crews (Disband, asked twice).
// The Profile tab also has "Claim this server" (the server's admin token, /claimadmin) for its owner.
// Every button sends the chat command (NetPanel.Command) and the window shows the server's answer (the next chat notice)
// at its foot. The content comes from the server's snapshot (NetPanel.Latest, asked for every 2 s while open) and is
// rebuilt only when it changed, so a text field keeps its focus. Esc / B closes it (StationMenu.Back); while it is open
// the station menu's own keys wait. Built in code; the buttons use Squad.uss.

using System;
using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Multiplayer;
using UnityEngine;
using UnityEngine.UIElements;

namespace GoF2Remake.UI
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public sealed class CrewPanel : MonoBehaviour
    {
        enum Tab { Crew, Arena, Profile, Admin }

        static CrewPanel current;

        /// <summary>The window is open (StationMenu: Esc closes it, its keys wait).</summary>
        public static bool IsOpenAny => current != null && current.isOpen;

        public static void CloseAny() { if (current != null) current.Close(); }

        VisualElement plate, window, tabs, body;
        ScrollView scroll;
        Button plateButton;
        Label status;
        Tab tab;
        bool isOpen, voids, force, confirmLeave;
        string tagText = "", nameText = "", amountText = "", linkText = "", reasonText = "", minutesText = "5";
        string sayText = "", filterText = "", tokenText = "", confirmKey = "";
        int shownRole = -1;
        float refresh, answerUntil;
        StyleSheet sheet;

        static readonly Color Panel = new Color(0.02f, 0.04f, 0.07f, 0.93f), Accent = new Color(0.56f, 0.85f, 1f),
                              Dim = new Color(0.85f, 0.92f, 0.97f, 0.65f), Good = new Color(0.47f, 0.9f, 0.55f), Bad = new Color(1f, 0.55f, 0.47f);

        /// <summary>The window's plate and window on 'parent' (the station menu's safe area).</summary>
        public static void Attach(GameObject host, VisualElement parent)
        {
            if (parent == null) return;
            var view = host.GetComponent<CrewPanel>();
            if (view == null) view = host.AddComponent<CrewPanel>();
            view.Build(parent);
        }

        void OnEnable()
        {
            current = this;
            NetPanel.Changed += OnChanged;
            NetChat.Added += OnChat;
        }

        void OnDisable()
        {
            if (current == this) current = null;
            NetPanel.Changed -= OnChanged;
            NetChat.Added -= OnChat;
        }

        void OnDestroy()
        {
            plate?.RemoveFromHierarchy();
            window?.RemoveFromHierarchy();
        }

        // ---- building -------------------------------------------------------------------------------------

        void Build(VisualElement parent)
        {
            plate?.RemoveFromHierarchy();
            window?.RemoveFromHierarchy();
            sheet = Resources.Load<StyleSheet>("GoF2Net/Squad");

            // The plate: under the station's information (like the join code), else top left.
            plate = new VisualElement { name = "crewPlate" };
            if (sheet != null) plate.styleSheets.Add(sheet);
            plateButton = Btn(Localization.Extra("mpCrewArena", "Crew · Arena"), Open, null);
            plateButton.style.marginTop = 8;
            plate.Add(plateButton);
            var info = parent.Q(className: "station-info");
            if (info != null && info.parent != null)
            {
                int at = info.parent.IndexOf(info) + 1;
                var code = info.parent.Q("joinCodePlate");
                if (code != null && code.parent == info.parent) at = info.parent.IndexOf(code) + 1;
                info.parent.Insert(at, plate);
            }
            else
            {
                plate.style.position = Position.Absolute;
                plate.style.left = 24; plate.style.top = 140;
                parent.Add(plate);
            }

            window = new VisualElement { name = "crewWindow" };
            if (sheet != null) window.styleSheets.Add(sheet);
            var w = window.style;
            w.position = Position.Absolute;
            w.left = new Length(50, LengthUnit.Percent); w.top = new Length(50, LengthUnit.Percent);
            w.translate = new Translate(new Length(-50, LengthUnit.Percent), new Length(-50, LengthUnit.Percent));
            w.width = new Length(64, LengthUnit.Percent); w.height = new Length(78, LengthUnit.Percent);
            w.minWidth = 560;
            w.backgroundColor = Panel;
            w.borderTopWidth = w.borderBottomWidth = w.borderLeftWidth = w.borderRightWidth = 1;
            w.borderTopColor = w.borderBottomColor = w.borderLeftColor = w.borderRightColor = new Color(Accent.r, Accent.g, Accent.b, 0.45f);
            w.paddingTop = w.paddingBottom = 12; w.paddingLeft = w.paddingRight = 18;
            w.display = DisplayStyle.None;

            var head = Row();
            head.style.justifyContent = Justify.SpaceBetween;
            tabs = Row();
            head.Add(tabs);
            head.Add(Btn("×", Close, "squad-button--leave"));
            window.Add(head);
            scroll = new ScrollView(ScrollViewMode.Vertical);
            scroll.style.flexGrow = 1;
            scroll.style.marginTop = 10;
            body = scroll.contentContainer;
            window.Add(scroll);
            status = Text("", 15, Accent);
            status.style.marginTop = 8;
            status.style.whiteSpace = WhiteSpace.Normal;
            window.Add(status);
            parent.Add(window);
            BuildTabs();
        }

        void BuildTabs()
        {
            tabs.Clear();
            int role = NetPanel.Latest != null ? NetPanel.Latest.role : 0;
            shownRole = role;
            if (tab == Tab.Admin && role < NetAdmin.Op) tab = Tab.Crew;
            foreach (Tab t in Enum.GetValues(typeof(Tab)))
            {
                if (t == Tab.Admin && role < NetAdmin.Op) continue;   // the moderation tab: ops and admins only
                var name = t == Tab.Crew ? Localization.Extra("mpTabCrew", "Crew") : t == Tab.Arena ? Localization.Extra("mpTabArena", "Arena")
                         : t == Tab.Profile ? Localization.Extra("mpTabProfile", "Profile") : Localization.Extra("mpTabAdmin", "Admin");
                var b = Btn(name, () => { tab = t; confirmLeave = false; BuildTabs(); Rebuild(); }, t == tab ? "squad-button--accept" : null);
                b.style.marginRight = 8;
                tabs.Add(b);
            }
        }

        // ---- open / close / refresh -----------------------------------------------------------------------

        void Open()
        {
            if (!NetGame.Active) return;
            isOpen = true;
            confirmLeave = false;
            window.style.display = DisplayStyle.Flex;
            window.BringToFront();
            status.text = "";
            refresh = 0f;
            Rebuild();
        }

        void Close()
        {
            isOpen = false;
            if (window != null) window.style.display = DisplayStyle.None;
            if (window?.focusController?.focusedElement is VisualElement f) f.Blur();
        }

        void Update()
        {
            if (plate == null) return;
            bool session = NetGame.Active;
            plate.style.display = session ? DisplayStyle.Flex : DisplayStyle.None;
            if (!session) { if (isOpen) Close(); return; }
            var s = NetPanel.Latest;
            bool waiting = s != null && (s.crewInvites.Count > 0 || s.duelFrom.Length > 0);
            plateButton.text = (Localization.Extra("mpCrewArena", "Crew · Arena") + (waiting ? "  •" : "")).ToUpperInvariant();
            // The plate's dot needs a snapshot now and then even while the window is closed.
            if ((refresh -= Time.unscaledDeltaTime) <= 0f) { refresh = isOpen ? NetPanel.RefreshSeconds : NetPanel.RefreshSeconds * 3f; NetPanel.Request(); }
        }

        void OnChanged()
        {
            if (NetPanel.Latest != null && NetPanel.Latest.role != shownRole && tabs != null) BuildTabs();   // made an op / admin, or no longer
            if (isOpen) Rebuild();
        }

        /// <summary>The server's answer to a button (the next notice), and invitations / challenges as they come.</summary>
        void OnChat(NetChat.Message m)
        {
            if (!isOpen || m == null || m.channel != NetChat.Channel.Notice) return;
            if (Time.unscaledTime < answerUntil) status.text = m.text;
            NetPanel.Request();
        }

        void Send(string command)
        {
            answerUntil = Time.unscaledTime + 4f;
            status.text = "…";
            confirmLeave = false;
            NetPanel.Command(command);
        }

        // ---- the tabs ---------------------------------------------------------------------------------------

        void Rebuild()
        {
            if (body == null) return;
            float y = scroll.scrollOffset.y;
            body.Clear();
            var s = NetPanel.Latest;
            if (s == null) { body.Add(Text(Localization.Extra("mpPanelLoading", "Asking the server..."), 16, Dim)); return; }
            switch (tab)
            {
                case Tab.Crew: BuildCrew(s); break;
                case Tab.Arena: BuildArena(s); break;
                case Tab.Admin: BuildAdmin(s); break;
                default: BuildProfile(s); break;
            }
            scroll.scrollOffset = new Vector2(0f, y);
        }

        void BuildCrew(NetPanel.State s)
        {
            if (!s.profiles) { body.Add(Text(Localization.Extra("mpPanelNoProfiles", "Crews need a server that keeps player profiles (a dedicated server)."), 16, Dim)); return; }
            if (s.guest) { body.Add(Text(Localization.Extra("mpPanelGuest", "You play as a guest here: crews need a profile (see the Profile tab)."), 16, Dim)); return; }
            foreach (var inv in s.crewInvites)
            {
                var parts = inv.Split('|');
                string tag = parts[0], name = parts.Length > 1 ? parts[1] : "";
                var row = Line($"[{tag}] {name} " + Localization.Extra("mpPanelInvites", "invites you to their crew."), Good);
                if (!s.inCrew) row.Add(Btn(Localization.Extra("mpPanelJoin", "Join"), () => Send($"/crew join {tag}"), "squad-button--accept"));
                body.Add(row);
            }
            if (!s.inCrew)
            {
                Section(Localization.Extra("mpPanelCreate", "Start a crew"));
                var row = Row();
                row.Add(Field(Localization.Extra("mpPanelTag", "Tag"), tagText, 4, 90, v => tagText = v));
                row.Add(Field(Localization.Extra("mpPanelName", "Name"), nameText, NetCrews.MaxNameLength, 260, v => nameText = v));
                row.Add(Btn(Localization.Extra("mpPanelCreateButton", "Create"), () => Send($"/crew create {tagText.Trim()} {nameText.Trim()}"), "squad-button--accept"));
                body.Add(row);
                body.Add(Text(Localization.Extra("mpPanelCreateHint", "A tag of 2-4 letters or digits shows before your members' names. Or ask a crew to invite you."), 14, Dim));
                CrewList(s);
                return;
            }
            bool officer = s.rank >= 1, leader = s.rank >= 2;
            var title = Text($"[{s.crewTag}] {s.crewName}", 24, Accent);
            title.style.unityFontStyleAndWeight = FontStyle.Bold;
            body.Add(title);
            body.Add(Text(s.rank == 2 ? Localization.Extra("mpRankLeader", "You lead this crew.") : s.rank == 1 ? Localization.Extra("mpRankOfficer", "You are an officer.")
                                                                                                                   : Localization.Extra("mpRankMember", "You are a member."), 14, Dim));

            Section(Localization.Extra("mpPanelBank", "Bank"));
            var bank = Row();
            bank.Add(Text($"{s.bank:N0} " + Localization.Extra("mpCredits", "credits"), 18, Color.white));
            bank.Add(Field(Localization.Extra("mpPanelAmount", "Amount"), amountText, 12, 150, v => amountText = v));
            bank.Add(Btn(Localization.Extra("mpPanelDeposit", "Deposit"), () => Send($"/crew deposit {amountText.Trim()}"), "squad-button--accept"));
            if (officer) bank.Add(Btn(Localization.Extra("mpPanelWithdraw", "Withdraw"), () => Send($"/crew withdraw {amountText.Trim()}"), null));
            body.Add(bank);

            Section(string.Format(Localization.Extra("mpPanelMembers", "Members ({0})"), s.members.Count));
            foreach (var m in s.members)
            {
                string rank = m.rank == 2 ? Localization.Extra("mpRankLeaderShort", "leader") : m.rank == 1 ? Localization.Extra("mpRankOfficerShort", "officer") : "";
                var row = Line($"{(m.online ? "●" : "○")} {m.name}{(rank.Length > 0 ? $"  ({rank})" : "")}", m.online ? Good : Dim);
                bool self = m.name == SelfName(s);
                if (!self && leader)
                {
                    if (m.rank == 0) row.Add(Btn(Localization.Extra("mpPanelPromote", "Promote"), () => Send($"/crew promote {m.name}"), null));
                    if (m.rank == 1) row.Add(Btn(Localization.Extra("mpPanelDemote", "Demote"), () => Send($"/crew demote {m.name}"), null));
                    row.Add(Btn(Localization.Extra("mpPanelMakeLeader", "Make leader"), () => Send($"/crew leader {m.name}"), null));
                }
                if (!self && officer && (leader || m.rank == 0)) row.Add(Btn(Localization.Extra("mpPanelKick", "Kick"), () => Send($"/crew kick {m.name}"), "squad-button--leave"));
                body.Add(row);
            }
            if (officer)
            {
                var free = s.pilots.FindAll(p => !p.self && string.IsNullOrEmpty(p.tag));
                if (free.Count > 0)
                {
                    Section(Localization.Extra("mpPanelInvite", "Invite a pilot"));
                    foreach (var p in free)
                    {
                        var row = Line(p.name, Color.white);
                        row.Add(Btn(Localization.Extra("mpPanelInviteButton", "Invite"), () => Send($"/crew invite {p.name}"), "squad-button--accept"));
                        body.Add(row);
                    }
                }
            }

            Section(string.Format(Localization.Extra("mpPanelTerritory", "Territory ({0} / {1})"), s.claims.Count, s.maxClaims));
            foreach (var c in s.claims)
                body.Add(Line($"{c.name}{(c.home ? "  ⌂ " + Localization.Extra("mpPanelHome", "home") : "")}{(c.sieged ? "  ⚔ " + Localization.Extra("mpPanelSieged", "under siege") : "")}  ·  " +
                              string.Format(Localization.Extra("mpPanelLapses", "lapses in {0:0.#} days without a member docking"), c.daysLeft), c.sieged ? Bad : Color.white));
            if (s.dockedStation >= 0)
            {
                string here = StationName(s.dockedStation);
                bool mine = s.stationHolder == s.crewTag, held = s.stationHolder.Length > 0;
                var row = Line(string.Format(Localization.Extra("mpPanelDockedAt", "Docked at {0}: {1}"), here,
                    !held ? Localization.Extra("mpPanelFree", "free") : mine ? Localization.Extra("mpPanelOurs", "yours") : $"[{s.stationHolder}]"), Accent);
                if (officer)
                {
                    if (!held && s.stationClaimable && s.claims.Count < s.maxClaims)
                        row.Add(Btn(string.Format(Localization.Extra("mpPanelClaim", "Claim ({0:N0})"), s.claimCost), () => Send("/crew claim"), "squad-button--accept"));
                    if (mine && s.home != s.dockedStation) row.Add(Btn(Localization.Extra("mpPanelMakeHome", "Make home"), () => Send("/crew home"), null));
                    if (mine) row.Add(Btn(Localization.Extra("mpPanelUnclaim", "Give up"), () => Send("/crew unclaim"), "squad-button--leave"));
                    if (held && !mine) row.Add(Btn(string.Format(Localization.Extra("mpPanelSiege", "Siege ({0:N0})"), s.siegeCost), () => Send("/crew siege"), "squad-button--leave"));
                }
                body.Add(row);
            }
            if (s.sieges.Length > 0) body.Add(Text(s.sieges, 14, Dim));

            Section(Localization.Extra("mpPanelCrews", "Crews"));
            CrewList(s);

            var end = Row();
            end.style.marginTop = 16;
            if (leader && s.members.Count <= 1 || !leader)
                end.Add(Btn(confirmLeave ? Localization.Extra("mpPanelConfirmLeave", "Really leave?") : Localization.Extra("mpPanelLeave", "Leave the crew"),
                            () => { if (confirmLeave) Send("/crew leave"); else { confirmLeave = true; Rebuild(); } }, "squad-button--leave"));
            if (leader)
                end.Add(Btn(confirmLeave ? Localization.Extra("mpPanelConfirmDisband", "Really disband? The bank is lost") : Localization.Extra("mpPanelDisband", "Disband"),
                            () => { if (confirmLeave) Send("/crew disband"); else { confirmLeave = true; Rebuild(); } }, "squad-button--leave"));
            body.Add(end);
        }

        void CrewList(NetPanel.State s)
        {
            if (s.crews.Count == 0) { body.Add(Text(Localization.Extra("mpPanelNoCrews", "No crews yet."), 14, Dim)); return; }
            foreach (var c in s.crews)
                body.Add(Text($"[{c.tag}] {c.name}  ·  {string.Format(Localization.Extra("mpPanelCrewRow", "{0} members, {1} stations"), c.members, c.claims)}", 15, Color.white));
        }

        void BuildArena(NetPanel.State s)
        {
            if (s.inMatch) { body.Add(Text(Localization.Extra("mpPanelInMatch", "You are in a match."), 16, Accent)); return; }
            if (s.duelFrom.Length > 0)
            {
                var row = Line(string.Format(Localization.Extra("mpPanelChallenged", "{0} challenges you to a duel{1}."), s.duelFrom,
                                             s.duelVoids ? Localization.Extra("mpArenaWithVoids", " with the Void fighters") : ""), Good);
                row.Add(Btn(Localization.Extra("mpAccept", "Accept"), () => Send("/accept"), "squad-button--accept"));
                row.Add(Btn(Localization.Extra("mpDecline", "Decline"), () => Send("/decline"), null));
                body.Add(row);
            }
            var opt = new Toggle(Localization.Extra("mpPanelVoids", "With the Void fighters (they attack everyone)")) { value = voids };
            opt.RegisterValueChangedCallback(e => voids = e.newValue);
            opt.style.marginTop = 6;
            body.Add(opt);
            string suffix = voids ? " voids" : "";

            Section(Localization.Extra("mpPanelDuel", "Duel (1v1)"));
            body.Add(Text(string.Format(Localization.Extra("mpPanelDuelHint", "First to {0} kills or the most after {1} minutes. Both pilots must be docked."),
                                        NetArena.DuelKills, Mathf.RoundToInt(NetArena.DuelSeconds / 60f)), 14, Dim));
            foreach (var p in s.pilots)
            {
                if (p.self) continue;
                string state = p.inMatch ? Localization.Extra("mpPanelBusy", "in a match") : !p.docked ? Localization.Extra("mpPanelInSpace", "in space") : "";
                var row = Line((p.tag.Length > 0 ? $"[{p.tag}] " : "") + p.name + (state.Length > 0 ? $"  ({state})" : ""), state.Length > 0 ? Dim : Color.white);
                if (state.Length == 0 && s.dockedStation >= 0) row.Add(Btn(Localization.Extra("mpPanelChallenge", "Challenge"), () => Send($"/duel {p.name}{suffix}"), "squad-button--accept"));
                body.Add(row);
            }
            if (s.pilots.Count <= 1) body.Add(Text(Localization.Extra("mpPanelNobody", "Nobody else is online."), 14, Dim));

            Section(Localization.Extra("mpPanelFfa", "Free-for-all"));
            body.Add(Text(string.Format(Localization.Extra("mpPanelFfaHint", "First to {0} kills or the most after {1} minutes; up to {2} pilots. It starts 30 s after a second pilot joins."),
                                        NetArena.FfaKills, Mathf.RoundToInt(NetArena.FfaSeconds / 60f), NetArena.FfaMaxPlayers), 14, Dim));
            var ffa = Row();
            if (s.queue > 0)
            {
                ffa.Add(Text(string.Format(Localization.Extra("mpPanelQueued", "In the queue{0}: {1} / {2}"), s.queue == 2 ? Localization.Extra("mpArenaWithVoids", " with the Void fighters") : "",
                                           s.queueCount, NetArena.FfaMaxPlayers) + (s.queueStartsIn >= 0f ? "  ·  " + string.Format(Localization.Extra("mpPanelStartsIn", "starts in {0:0} s"), s.queueStartsIn) : ""), 16, Good));
                ffa.Add(Btn(Localization.Extra("mpPanelLeaveQueue", "Leave the queue"), () => Send("/leave"), "squad-button--leave"));
            }
            else if (s.dockedStation >= 0) ffa.Add(Btn(Localization.Extra("mpPanelJoinFfa", "Join"), () => Send("/ffa" + suffix), "squad-button--accept"));
            body.Add(ffa);

            Section(Localization.Extra("mpPanelMatches", "Matches"));
            if (s.matches.Count == 0) body.Add(Text(Localization.Extra("mpArenaNoMatchesShort", "None running."), 14, Dim));
            foreach (var m in s.matches) body.Add(Text(m, 15, Color.white));
            if (s.profiles && s.top.Length > 0)
            {
                Section(Localization.Extra("mpPanelTop", "Leaderboard"));
                body.Add(Text(s.top, 15, Color.white));
            }
        }

        void BuildProfile(NetPanel.State s)
        {
            if (!s.profiles) { body.Add(Text(Localization.Extra("mpPanelNoProfilesHere", "This server doesn't keep player profiles: nothing is saved."), 16, Dim)); return; }
            if (s.guest) body.Add(Text(Localization.Extra("mpPanelGuestLong", "You play as a guest: the server has no room for another profile, so nothing is saved. With a link code from another device you can use its profile."), 16, Bad));
            else
            {
                body.Add(Text(string.Format(Localization.Extra("mpPanelProfile", "Profile {0}  ·  {1} device(s)"), s.profileId, s.devices), 18, Color.white));
                body.Add(Text(s.controller ? Localization.Extra("mpPanelControls", "This device plays the profile. Progress is saved on docking, every minute and when leaving.")
                                           : Localization.Extra("mpPanelWatches", "Another device of yours plays the profile: this one only watches from the station."), 15, s.controller ? Dim : Bad));
                if (!s.controller) body.Add(Btn(Localization.Extra("mpPanelTakeControl", "Take control (the other device must be docked)"), () => Send("/control"), "squad-button--accept"));
                Section(Localization.Extra("mpPanelOtherDevice", "Use this profile on another device"));
                body.Add(Text(Localization.Extra("mpPanelLinkHint", "Get a code here, then join this server on the other device and enter it there (5 minutes)."), 14, Dim));
                if (s.controller) body.Add(Btn(Localization.Extra("mpPanelGetCode", "Get a link code"), () => Send("/link"), "squad-button--accept"));
            }
            Section(Localization.Extra("mpPanelLinkHere", "Use another device's profile here"));
            var row = Row();
            row.Add(Field(Localization.Extra("mpPanelCode", "Code"), linkText, 6, 140, v => linkText = v.ToUpperInvariant()));
            var f = new Toggle(Localization.Extra("mpPanelForce", "Replace this device's own progress")) { value = force };
            f.RegisterValueChangedCallback(e => force = e.newValue);
            row.Add(f);
            row.Add(Btn(Localization.Extra("mpPanelLink", "Link"), () => Send($"/link {linkText.Trim()}{(force ? " force" : "")}"), "squad-button--accept"));
            body.Add(row);
            if (!s.guest && s.role < NetAdmin.Master)
            {
                Section(Localization.Extra("mpPanelClaimServer", "Claim this server"));
                body.Add(Text(Localization.Extra("mpPanelClaimHint", "For the server's owner: its admin token is in the server's log (and admin_token.txt beside its profiles)."), 14, Dim));
                var claim = Row();
                claim.Add(Field(Localization.Extra("mpPanelToken", "Admin token"), tokenText, 64, 260, v => tokenText = v));
                claim.Add(Btn(Localization.Extra("mpPanelClaimButton", "Claim"), () => { Send($"/claimadmin {tokenText.Trim()}"); tokenText = ""; }, "squad-button--accept"));
                body.Add(claim);
            }
        }

        /// <summary>A dangerous button: the first press arms it ("Really?"), the second acts.</summary>
        Button Confirm(string label, string key, string command)
        {
            bool armed = confirmKey == key;
            return Btn(armed ? Localization.Extra("mpPanelReally", "Really?") + " " + label : label, () =>
            {
                if (confirmKey == key) { confirmKey = ""; Send(command); }
                else { confirmKey = key; Rebuild(); }
            }, "squad-button--leave");
        }

        static string RoleLabel(int role) => role >= NetAdmin.Master ? "  (master)" : role == NetAdmin.Admin ? "  (admin)" : role == NetAdmin.Op ? "  (op)" : "";

        void BuildAdmin(NetPanel.State s)
        {
            if (s.role < NetAdmin.Op) return;
            bool admin = s.role >= NetAdmin.Admin, master = s.role >= NetAdmin.Master;
            body.Add(Text(master ? Localization.Extra("mpPanelYouMaster", "You are this server's master admin.") : admin ? Localization.Extra("mpPanelYouAdmin", "You are an admin of this server.")
                                                                                                              : Localization.Extra("mpPanelYouOp", "You are an op of this server."), 15, Accent));
            if (admin)
            {
                Section(Localization.Extra("mpPanelServer", "Server"));
                if (s.serverStatus.Length > 0) body.Add(Text(s.serverStatus, 14, Color.white));
                var say = Row();
                say.Add(Field(Localization.Extra("mpPanelAnnounce", "Announcement to everyone"), sayText, 200, 480, v => sayText = v));
                say.Add(Btn(Localization.Extra("mpPanelSend", "Send"), () => { Send($"/say {sayText.Trim()}"); sayText = ""; }, "squad-button--accept"));
                body.Add(say);
            }
            var opts = Row();
            opts.Add(Field(Localization.Extra("mpPanelReason", "Reason"), reasonText, 80, 320, v => reasonText = v));
            opts.Add(Field(Localization.Extra("mpPanelMinutes", "Minutes"), minutesText, 6, 110, v => minutesText = v));
            body.Add(opts);
            body.Add(Text(string.Format(Localization.Extra("mpPanelAdminHint", "Kick: the pilot can't come back for the minutes (0 = at once). Ban: for the minutes{0}."),
                                        admin ? Localization.Extra("mpPanelAdminHintAdmin", ", or for good") : string.Format(Localization.Extra("mpPanelAdminHintOp", " (ops: at most {0} hours)"), NetAdmin.MaxOpBanMinutes / 60)), 14, Dim));

            Section(Localization.Extra("mpPanelPilotsOnline", "Pilots online"));
            string minutes = int.TryParse(minutesText.Trim(), out int m) && m >= 0 ? m.ToString() : NetAdmin.KickMinutes.ToString();
            string reason = reasonText.Trim();
            foreach (var p in s.pilots)
            {
                string rank = RoleLabel(p.role);
                var row = Line((p.tag.Length > 0 ? $"[{p.tag}] " : "") + p.name + rank + (p.self ? "  (" + Localization.Extra("mpPanelYou", "you") + ")" : ""), p.self ? Dim : Color.white);
                if (!p.self && s.role > p.role)
                {
                    string target = "#" + p.client;
                    row.Add(Btn(Localization.Extra("mpPanelKick", "Kick"), () => Send($"/kick {target} {minutes} {reason}"), "squad-button--leave"));
                    row.Add(Btn(Localization.Extra("mpPanelTempBan", "Ban (minutes)"), () => Send($"/tempban {target} {Mathf.Max(1, int.Parse(minutes))} {reason}"), "squad-button--leave"));
                    if (admin)
                    {
                        row.Add(Confirm(Localization.Extra("mpPanelBanForGood", "Ban for good"), "ban" + target, $"/ban {target} {reason}"));
                        if (p.role == NetAdmin.Player) row.Add(Btn(Localization.Extra("mpPanelOp", "Make op"), () => Send($"/op {target}"), "squad-button--accept"));
                        if (p.role == NetAdmin.Op) row.Add(Btn(Localization.Extra("mpPanelDeop", "Remove op"), () => Send($"/deop {target}"), null));
                        if (master && p.role < NetAdmin.Admin) row.Add(Btn(Localization.Extra("mpPanelMakeAdmin", "Make admin"), () => Send($"/admin {target}"), "squad-button--accept"));
                    }
                }
                body.Add(row);
            }

            Section(string.Format(Localization.Extra("mpPanelBans", "Bans ({0})"), s.bans.Count));
            if (s.bans.Count == 0) body.Add(Text(Localization.Extra("mpAdminNoBans", "Nobody is banned."), 14, Dim));
            foreach (var b in s.bans)
            {
                var row = Line($"{b.name}  ·  {b.left}  ·  {b.by}{(b.reason.Length > 0 ? ": " + b.reason : "")}", Color.white);
                string key = b.account.Length > 0 ? b.account : b.name;
                row.Add(Btn(Localization.Extra("mpPanelUnban", "Unban"), () => Send($"/unban {key}"), "squad-button--accept"));
                body.Add(row);
            }
            if (!admin) return;

            Section(Localization.Extra("mpPanelStaff", "Staff"));
            if (s.staff.Count == 0) body.Add(Text(Localization.Extra("mpPanelNoStaff", "Nobody yet."), 14, Dim));
            foreach (var st in s.staff)
            {
                var row = Line($"{(st.online ? "●" : "○")} {st.name}{RoleLabel(st.role)}", st.online ? Good : Dim);
                if (s.role > st.role)
                {
                    if (st.role == NetAdmin.Op) row.Add(Btn(Localization.Extra("mpPanelDeop", "Remove op"), () => Send($"/deop {st.name}"), null));
                    if (st.role == NetAdmin.Admin && master) row.Add(Btn(Localization.Extra("mpPanelUnadmin", "Remove admin"), () => Send($"/unadmin {st.name}"), null));
                }
                body.Add(row);
            }

            Section(string.Format(Localization.Extra("mpPanelProfiles", "Profiles ({0})"), s.profiles.Count));
            var find = Row();
            find.Add(Field(Localization.Extra("mpPanelFilter", "Filter by name or id"), filterText, 24, 300, v => filterText = v));
            find.Add(Btn(Localization.Extra("mpPanelFilterButton", "Filter"), Rebuild, null));   // a rebuild per letter would lose the field's focus
            body.Add(find);
            string filter = filterText.Trim();
            int shown = 0;
            foreach (var pr in s.profiles)
            {
                if (filter.Length > 0 && pr.name.IndexOf(filter, StringComparison.OrdinalIgnoreCase) < 0 && pr.id.IndexOf(filter, StringComparison.OrdinalIgnoreCase) < 0) continue;
                if (++shown > 60) { body.Add(Text(Localization.Extra("mpPanelMore", "More: narrow the filter."), 14, Dim)); break; }
                var row = Line($"{(pr.online ? "●" : "○")} {(pr.name.Length > 0 ? pr.name : "?")}  ·  {pr.id}{RoleLabel(pr.role)}  ·  {pr.devices} dev.  ·  {pr.lastSeen}{(pr.banned ? "  ·  BANNED" : "")}",
                               pr.banned ? Bad : pr.online ? Good : Color.white);
                if (s.role > pr.role)
                {
                    string id = pr.id;
                    if (pr.banned) row.Add(Btn(Localization.Extra("mpPanelUnban", "Unban"), () => Send($"/unban {id}"), "squad-button--accept"));
                    else row.Add(Confirm(Localization.Extra("mpPanelBanForGood", "Ban for good"), "banp" + id, $"/ban {id} {reasonText.Trim()}"));
                    if (pr.role == NetAdmin.Player) row.Add(Btn(Localization.Extra("mpPanelOp", "Make op"), () => Send($"/op {id}"), null));
                    if (pr.role == NetAdmin.Op) row.Add(Btn(Localization.Extra("mpPanelDeop", "Remove op"), () => Send($"/deop {id}"), null));
                    if (master && pr.role < NetAdmin.Admin) row.Add(Btn(Localization.Extra("mpPanelMakeAdmin", "Make admin"), () => Send($"/admin {id}"), null));
                    if (master && pr.role == NetAdmin.Admin) row.Add(Btn(Localization.Extra("mpPanelUnadmin", "Remove admin"), () => Send($"/unadmin {id}"), null));
                    if (master && !pr.online) row.Add(Confirm(Localization.Extra("mpPanelDelete", "Delete"), "del" + id, $"/deleteprofile {id}"));
                }
                body.Add(row);
            }

            Section(Localization.Extra("mpPanelCrews", "Crews"));
            if (s.crews.Count == 0) body.Add(Text(Localization.Extra("mpPanelNoCrews", "No crews yet."), 14, Dim));
            foreach (var c in s.crews)
            {
                var row = Line($"[{c.tag}] {c.name}  ·  {string.Format(Localization.Extra("mpPanelCrewRow", "{0} members, {1} stations"), c.members, c.claims)}", Color.white);
                row.Add(Confirm(Localization.Extra("mpPanelDisband", "Disband"), "crew" + c.tag, $"/disband {c.tag}"));
                body.Add(row);
            }
        }

        // ---- small builders ---------------------------------------------------------------------------------

        static string SelfName(NetPanel.State s) => s.pilots.Find(p => p.self)?.name ?? "";

        static string StationName(int station) => NetGame.Db.Stations.Find(x => x.index == station)?.name ?? station.ToString();

        void Section(string title)
        {
            var l = Text(title.ToUpperInvariant(), 15, Accent);
            l.style.marginTop = 16;
            l.style.marginBottom = 4;
            l.style.letterSpacing = 1;
            l.style.borderBottomWidth = 1;
            l.style.borderBottomColor = new Color(Accent.r, Accent.g, Accent.b, 0.3f);
            body.Add(l);
        }

        static VisualElement Row()
        {
            var r = new VisualElement();
            r.style.flexDirection = FlexDirection.Row;
            r.style.alignItems = Align.Center;
            r.style.flexWrap = Wrap.Wrap;
            return r;
        }

        /// <summary>A line of text with room for buttons after it.</summary>
        static VisualElement Line(string text, Color colour)
        {
            var r = Row();
            r.style.marginBottom = 4;
            var l = Text(text, 16, colour);
            l.style.flexGrow = 1;
            l.style.flexShrink = 1;
            r.Add(l);
            return r;
        }

        static Label Text(string text, int size, Color colour)
        {
            var l = new Label(text) { pickingMode = PickingMode.Ignore };
            l.style.fontSize = size;
            l.style.color = colour;
            l.style.whiteSpace = WhiteSpace.Normal;
            return l;
        }

        static Button Btn(string text, Action onClick, string cls)
        {
            var b = new Button(onClick) { text = text.ToUpperInvariant() };
            b.AddToClassList("squad-button");
            if (cls != null) b.AddToClassList(cls);
            b.style.marginLeft = 6;
            b.style.marginTop = 2; b.style.marginBottom = 2;
            return b;
        }

        static TextField Field(string label, string value, int max, int width, Action<string> changed)
        {
            var f = new TextField { value = value, maxLength = max };
            f.textEdition.placeholder = label;
            f.style.width = width;
            f.style.marginLeft = 6;
            f.RegisterValueChangedCallback(e => changed(e.newValue));
            return f;
        }
    }
}
