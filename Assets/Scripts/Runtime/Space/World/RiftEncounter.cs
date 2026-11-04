// RiftEncounter.cs
// Remake (2026-11-04, for mods): a rift run in the orbit (Flight.RiftRun's rules; the cruise drive's "rift" encounter,
// CruiseEncounterSpawner), after EVERSPACE 2's Ancient Rifts (decompiled BP_Encounter_Rift). ES2 sends the pilot through
// portals into a new location each stage; here the stages follow each other where the rift opened, what is left of a stage's
// enemies gone with it. A fight stage keeps RiftRun.MinAlive raiders alive (a fifth of them the stronger fighters) until its
// kill points are reached; the last stage is the boss's (the pirate boss's hull and guns, a mod's boss hull now and then),
// and beating it ends the run: a crate of ES2's rift boss drops (loot_types.CSV "RiftBoss": 14-18) x RiftRun.LootFactor and
// BattlePay. The HUD shows the run (HudLine: stage, points, resolve). Flying off past LeaveM ends it, unpaid.
// The mutators, as BP_Encounter_Rift does them (their values ES2's Signal Decoders'):
//   Enemy Regen       each enemy repairs RegenShare of its hull a second (GetScaledHitpoints(5) against a raider's 200)
//   Evasive           +50 % speed (ShipMovement.AddSpeedModifier); Strength in Death: the others +5 % speed and hull per
//                     kill, at most 10 times
//   No EMP            EMP can't touch them (BP_ConditionModifier_Resistance_EMP)
//   Jarred Sensors    the lock plate gives their race, not their type; Hidden Health: no hull percent
//   Explosive Death   a dying enemy's blast: ExplodeSeconds of its gun's fire (ES2's 50 kinetic + 70 energy against a raider's
//                     31 + 24 DPS) to every ship within its size (20-50 m, clamped) x 15 (DamageRadiusFactor) x 3.6, falling
//                     off to the edge
//   Repair On Kill    the others repair 20 % of their hull
//   Nearsighted       half the damage beyond 1080 m (ES2's 300 m x 3.6); Farsighted: within 1800 m
//   No Lock           they can't be locked (HUDMarker bLockable)
//   Vengeance         every kill sends a detonator drone at the pilot (BP_Outlaw_DetonatorDrone: the remake's detonator role),
//                     invulnerable with Explosive Death
// The boss: one of the entry's "bosses" (EVERSPACE 2's rift bosses: GetBossClassAndLevel picks one of its destroyer, drone
// carriers, Okkar corvette and Redeemer battleship), a mod's capital ship parked as one (ModCapitalShips.Spawn) or else a
// fighter hull with its entry's "weapon" / "secondary" (else the pirate boss's gun), its hull "raiders" x a pirate raider's
// (NpcTables.Hull); without them the pirate boss's hull and guns.
//   the boss's        Quantum Mend: every 15-30 s it teleports and repairs until hit; Evasive Drift: as often it boosts away;
//                     Guardians: two guards, and while one lives it can't be hurt (again 15-30 s after they fall)
// Who fights (2026-11-04, the user: the mods' enemy fighters and races, and the Void): each stage its own side, as ES2's
// portals lead to another place each stage: the pirates, the Void, or a hostile mod race with fighters of its own (Sides),
// at random. A mod race flies its mods' ships; the pirates and the Void fly the game's, now and then a mod's of theirs (the
// "Mod ships in traffic" chance, ModTraffic). The boss's stage is its boss's "race" when its entry names one, its guards too.

using System.Collections.Generic;
using GoF2Remake.Data;
using GoF2Remake.Flight;
using UnityEngine;

namespace GoF2Remake.World
{
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]
    public class RiftEncounter : MonoBehaviour
    {
        const float M = 0.05f;
        public const float LeaveM = 15000f;
        public const float ExplodeSeconds = 120f / 55f, RegenShare = 5f / 200f;
        public const int BossRollsMin = 14, BossRollsMax = 18;
        const float SpawnSpread = 6000f;

        /// <summary>The run in the orbit now, null = none.</summary>
        public static RiftEncounter Current { get; private set; }

        [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.SubsystemRegistration)]
        static void ResetStatics() => Current = null;

        SpaceLevel level;
        RiftRun run;
        Vector3 centreGame;
        int es2Level;
        List<CruiseEncounters.RiftBoss> bosses;
        readonly List<NpcShip> enemies = new List<NpcShip>();
        readonly Dictionary<NpcShip, RiftRun.Kind> kinds = new Dictionary<NpcShip, RiftRun.Kind>();
        readonly List<NpcShip> guards = new List<NpcShip>(), dead = new List<NpcShip>();
        NpcShip boss;
        CruiseEncounters.RiftBoss bossPick;
        /// <summary>The stage's side (Sides).</summary>
        int race = Standing.Pirate;
        float bossTimerS;
        bool bossMending;
        int buffs;

        public RiftRun Run => run;

        public static RiftEncounter Start(SpaceLevel level, Vector3 centreGame, int stages, List<CruiseEncounters.RiftBoss> bosses = null)
        {
            if (level == null || level.Traffic == null || Current != null) return null;
            var r = new GameObject("Rift").AddComponent<RiftEncounter>();
            r.level = level;
            r.centreGame = centreGame;
            r.run = new RiftRun(stages > 0 ? stages : RiftRun.DefaultStages);
            r.es2Level = CruiseEncounterSpawner.Es2Level(level);
            r.bosses = bosses;
            Current = r;
            r.BeginStage();
            return r;
        }

        /// <summary>The HUD's line for the run (null without one): its stage, its points and resolve, or the boss.</summary>
        public static string HudLine
        {
            get
            {
                var r = Current;
                if (r == null || r.run == null || r.run.Finished) return null;
                string head = $"{Localization.Extra("riftHud", "Rift")} {r.run.Stage + 1}/{r.run.Stages}";
                if (r.run.IsBossStage) return $"{head}  {Localization.Extra("riftBoss", "Boss")}";
                return $"{head}  {Mathf.FloorToInt(r.run.Points)}/{Mathf.CeilToInt(r.run.Target)}  {Localization.Extra("riftResolve", "Resolve")} {Mathf.RoundToInt(r.run.Resolve * 100f)}%";
            }
        }

        Vector3 Centre => new Vector3(centreGame.x, centreGame.y, -centreGame.z) * M;
        Vector3 Around(float units) => centreGame + new Vector3(Random.Range(-units, units), Random.Range(-units, units) * 0.5f, Random.Range(-units, units));

        void OnDestroy() { if (Current == this) Current = null; }

        void Post(string text) => level?.Navigation?.Post(text);

        /// <summary>The sides a rift stage may be: the pirates, the Void and the active mods' hostile races that have fighters.</summary>
        public static List<int> Sides()
        {
            var l = new List<int> { Standing.Pirate, Standing.Void };
            foreach (var d in Modding.ModRaces.All)
                if (d.hostile && d.race >= 0 && Modding.ModTraffic.Candidates(d.race).Count > 0) l.Add(d.race);
            return l;
        }

        void BeginStage()
        {
            run.BeginStage(Random.value, Random.value);
            var sides = Sides();
            race = sides[Random.Range(0, sides.Count)];
            bossPick = run.IsBossStage && bosses != null && bosses.Count > 0 ? bosses[Random.Range(0, bosses.Count)] : null;
            if (bossPick?.race != null)
            {
                int r = Standing.RaceWord(bossPick.race);
                if (r >= 0) race = r;
            }
            foreach (var e in enemies) if (e != null && !e.Gone && e.Target.Alive) e.Vanish();   // (ES2: the next location)
            enemies.Clear(); kinds.Clear(); guards.Clear();
            boss = null;
            bossMending = false;
            string mutator = run.active.Count > 0 ? MutatorName(run.active[run.active.Count - 1]) : null;
            if (run.IsBossStage)
            {
                SpawnBoss();
                Post(mutator != null ? $"{Localization.Extra("riftBossStage", "The rift's guardian")}: {mutator}" : Localization.Extra("riftBossStage", "The rift's guardian"));
            }
            else
            {
                string stage = string.Format(Localization.Extra("riftStage", "Rift stage {0}"), run.Stage + 1);
                Post(mutator != null ? $"{stage}: {mutator}" : stage);
            }
            level.Traffic.ConnectPlayers();
        }

        void Update()
        {
            if (level == null || level.Player == null) { Destroy(gameObject); return; }
            if ((level.Player.transform.position - Centre).sqrMagnitude > LeaveM * LeaveM)
            {
                Post(Localization.Extra("riftLeft", "Rift left"));
                Destroy(gameObject);
                return;
            }
            float dt = Time.deltaTime;
            run.Tick(dt);
            var player = level.Player.transform.position;
            // the dead (any death counts, as ES2's OnEnemyDestroyed does); a kill may end the stage, which clears the list
            dead.Clear();
            foreach (var e in enemies) if (e == null || e.Gone || !e.Target.Alive) dead.Add(e);
            foreach (var e in dead)
            {
                if (!enemies.Remove(e) || e == null) continue;
                Killed(e);
                if (Current != this) return;
            }
            foreach (var e in enemies)
            {
                var t = e.Target;
                if (run.HasMutator(RiftRun.HullRepair) && e.Hp.hull < e.Hp.maxHull)
                    Repair(e, RegenShare * dt);
                if (run.HasMutator(RiftRun.Nearsighted) || run.HasMutator(RiftRun.Farsighted))
                {
                    float d = (e.transform.position - player).magnitude;
                    bool half = (run.HasMutator(RiftRun.Nearsighted) && d > RiftRun.NearsightedM) || (run.HasMutator(RiftRun.Farsighted) && d < RiftRun.FarsightedM);
                    t.damageFactor = half ? RiftRun.SightedDamageFactor : 1f;
                }
            }
            if (run.IsBossStage) UpdateBoss(dt);
            else
                for (int n = enemies.Count; n < run.MinAlive; n++) Spawn(Random.value < 0.2f ? RiftRun.Kind.Cruiser : RiftRun.Kind.Fighter, Around(SpawnSpread));
        }

        void Repair(NpcShip e, float share)
        {
            var hp = e.Hp;
            hp.hull = Mathf.Min(hp.maxHull, hp.hull + Mathf.Max(1, Mathf.RoundToInt(hp.maxHull * share)));
            e.Target.hp = hp.hull;
        }

        NpcShip Spawn(RiftRun.Kind kind, Vector3 gameAt, string role = null)
        {
            var db = level.Database ?? Database.Shared;
            int ship = kind == RiftRun.Kind.Cruiser ? NpcTables.StrongFighter(db, race) : NpcTables.RandomFighter(race);
            var spec = new SpawnSpec { group = NpcGroup.Special, race = race, ship = ship, alwaysEnemy = true, position = gameAt, role = role };
            if (run.HasMutator(RiftRun.EmpResistance)) spec.empPoints = 1000000;
            var s = level.Traffic.SpawnShip(spec);
            if (s == null) return null;
            Dress(s);
            enemies.Add(s);
            kinds[s] = kind;
            level.Traffic.ConnectPlayers();
            return s;
        }

        /// <summary>The mutators on a new enemy (its speed, its plate, its lock).</summary>
        void Dress(NpcShip s)
        {
            var t = s.Target;
            if (run.HasMutator(RiftRun.SpeedBonus)) s.roleSpeedFactor *= 1f + RiftRun.SpeedBonusShare;
            for (int i = 0; i < buffs; i++) { s.roleSpeedFactor *= 1f + RiftRun.BuffOnKillShare; }
            if (run.HasMutator(RiftRun.NamesHidden)) t.displayName = null;   // (the plate then gives its race)
            if (run.HasMutator(RiftRun.HpHidden)) { t.displayName = string.IsNullOrEmpty(t.displayName) ? Standing.RaceName(t.race) : t.displayName; t.plateNameOnly = true; }
            if (run.HasMutator(RiftRun.NoLock)) t.untargetable = true;
        }

        void Killed(NpcShip e)
        {
            var kind = kinds.TryGetValue(e, out var k) ? k : RiftRun.Kind.Fighter;
            kinds.Remove(e);
            var at = e.transform.position;
            if (run.HasMutator(RiftRun.ExplodeOnKill)) Blast(e, at);
            if (run.HasMutator(RiftRun.HealOnKill)) foreach (var o in enemies) if (o != null && o.Target.Alive) Repair(o, RiftRun.HealOnKillShare);
            if (run.HasMutator(RiftRun.BuffOnKill) && buffs < RiftRun.BuffOnKillMax)
            {
                buffs++;
                foreach (var o in enemies)
                {
                    if (o == null || !o.Target.Alive) continue;
                    o.roleSpeedFactor *= 1f + RiftRun.BuffOnKillShare;
                    o.Hp.maxHull = Mathf.RoundToInt(o.Hp.maxHull * (1f + RiftRun.BuffOnKillShare));
                    Repair(o, RiftRun.BuffOnKillShare);
                }
            }
            if (run.HasMutator(RiftRun.Vengeance) && e.Role != NpcRoles.Role.Detonator)
            {
                var d = Spawn(RiftRun.Kind.Drone, new Vector3(at.x, at.y, -at.z) / M, "detonator");
                if (d != null && run.HasMutator(RiftRun.ExplodeOnKill)) d.Target.invulnerable = true;
            }
            if (run.IsBossStage)
            {
                guards.Remove(e);
                if (e == boss) { Finish(); return; }
                if (boss != null && guards.Count == 0 && run.HasMutator(RiftRun.BossBodyguards)) { boss.Target.invulnerable = false; bossTimerS = Random.Range(RiftRun.BossTimerMinS, RiftRun.BossTimerMaxS); }
                return;
            }
            if (run.Kill(kind))
            {
                bool mastered = run.Resolve > 0f;
                run.EndStage();
                Post(mastered ? Localization.Extra("riftMastered", "Stage mastered") : Localization.Extra("riftCleared", "Stage cleared"));
                BeginStage();
            }
        }

        /// <summary>Explosive Death: the blast on every ship (and the pilot) within its reach, falling off to the edge.</summary>
        void Blast(NpcShip from, Vector3 at)
        {
            float size = Mathf.Clamp(from.Target.radius / 3.6f, 20f, 50f) * 15f * 3.6f;
            float damage = ExplodeSeconds * from.GunDps;
            if (damage <= 0f) return;
            Explosion.Spawn(at, 1.2f);
            var all = Target.All;
            for (int i = all.Count - 1; i >= 0; i--)
            {
                var o = all[i];
                if (o == null || o == from.Target || !o.Alive || !(o.isShip || o.isPlayer)) continue;
                var d = o.transform.position - at;
                float r = d.magnitude;
                if (r > size) continue;
                o.Damage(damage * (1f - r / size), true, d.normalized);
            }
        }

        void SpawnBoss()
        {
            var db = level.Database ?? Database.Shared;
            int rank = Session.Rank;
            int hull = Mathf.Max(1, (int)((15 * rank + 1500 + 4 * 45) * Session.DifficultyFactor));   // (the pirate boss's)
            int gun = rank < 5 ? 23 : rank < 10 ? 15 : rank < 15 ? 26 : 21;
            var spec = new SpawnSpec
            {
                group = NpcGroup.Special, race = race, ship = Modding.ModTraffic.PickBoss(NpcTables.StrongFighter(db, race)),
                position = Around(2000f), hitpoints = hull, speed = 3.5f, gunItem = gun, gunFactor = 2f, alwaysEnemy = true, noLoot = true,
            };
            var pick = bossPick;
            if (pick != null && Modding.ModContent.TryResolveShip(pick.ship, out int bossShip) && db.Ship(bossShip) != null)
            {
                int bossHull = Mathf.Max(1, Mathf.RoundToInt(NpcTables.Hull(0, 0) * pick.raiders));
                if (Modding.ModCapitalShips.KindOf(bossShip) != null)
                {
                    spec = Modding.ModCapitalShips.Spawn(bossShip, race, spec.position);
                    spec.alwaysEnemy = true;
                    spec.noLoot = true;
                }
                else
                {
                    spec.ship = bossShip;
                    // its own gun and missiles (a capital ship fires its turrets), at the pirate boss's gunFactor
                    if (pick.weapon != null && Modding.ModContent.TryResolveItem(pick.weapon, out int w) && db.Item(w) != null) spec.gunItem = w;
                    if (pick.secondary != null && Modding.ModContent.TryResolveItem(pick.secondary, out int m) && db.Item(m) != null)
                    { spec.secondaryItem = m; spec.secondaryFactor = spec.gunFactor; }
                }
                spec.hitpoints = bossHull;
            }
            if (run.HasMutator(RiftRun.EmpResistance)) spec.empPoints = 1000000;
            boss = level.Traffic.SpawnShip(spec);
            if (boss == null) { Finish(); return; }
            Dress(boss);
            enemies.Add(boss);
            kinds[boss] = RiftRun.Kind.Capital;
            boss.Target.Damaged += (t, dmg, byNpc) => { if (bossMending && !byNpc) bossMending = false; };
            bossTimerS = Random.Range(RiftRun.BossTimerMinS, RiftRun.BossTimerMaxS);
            if (run.HasMutator(RiftRun.BossBodyguards)) SpawnGuards();
        }

        void SpawnGuards()
        {
            boss.Target.invulnerable = true;
            for (int i = 0; i < 2; i++)
            {
                var g = Spawn(RiftRun.Kind.Cruiser, new Vector3(boss.transform.position.x, boss.transform.position.y, -boss.transform.position.z) / M + new Vector3(Random.Range(-3000f, 3000f), 0f, Random.Range(-3000f, 3000f)));
                if (g != null) guards.Add(g);
            }
            if (guards.Count == 0) boss.Target.invulnerable = false;
        }

        void UpdateBoss(float dt)
        {
            if (boss == null || !boss.Target.Alive) return;
            if (bossMending) Repair(boss, RegenShare * dt);
            if ((bossTimerS -= dt) > 0f) return;
            bossTimerS = Random.Range(RiftRun.BossTimerMinS, RiftRun.BossTimerMaxS);
            if (run.HasMutator(RiftRun.BossTeleportRepairs))
            {
                boss.transform.position = OrbitLayout.ToUnity(Around(SpawnSpread));
                bossMending = true;   // (repairing until the pilot hits it)
                Explosion.Spawn(boss.transform.position, 0.6f, false);
            }
            if (run.HasMutator(RiftRun.BossBoost)) boss.BoostAway();
            if (run.HasMutator(RiftRun.BossBodyguards) && guards.Count == 0) SpawnGuards();
        }

        void Finish()
        {
            run.EndStage();
            var db = level.Database ?? Database.Shared;
            var cargo = new List<ItemStack>();
            int rolls = Mathf.Max(1, Mathf.RoundToInt(Random.Range(BossRollsMin, BossRollsMax + 1) * run.LootFactor));
            for (int k = 0; k < rolls; k++)
                foreach (var s in NpcTables.RollLoot(db, true))
                {
                    var have = cargo.Find(x => x.item == s.item);
                    if (have != null) have.amount += s.amount; else cargo.Add(new ItemStack(s.item, s.amount));
                }
            if (cargo.Count > 0) Crate.Spawn(boss != null ? boss.transform.position : Centre, cargo, race, Crate.LookJunk).keep = true;
            int pay = CruiseEncounterSpawner.BattlePay(es2Level);
            Session.Credits += pay;
            Post(string.Format(Localization.Extra("riftWon", "Rift closed: +{0} cr"), pay));
            foreach (var e in enemies) if (e != null && !e.Gone && e.Target.Alive) e.Vanish();
            Destroy(gameObject);
        }

        /// <summary>A mutator's name on the HUD (EVERSPACE 2's, attributes.CSV).</summary>
        public static string MutatorName(string id) => id switch
        {
            RiftRun.HullRepair => Localization.Extra("mutatorHullRepair", "Enemy Regen"),
            RiftRun.SpeedBonus => Localization.Extra("mutatorSpeedBonus", "Evasive"),
            RiftRun.EmpResistance => Localization.Extra("mutatorEmpResistance", "No EMP"),
            RiftRun.NamesHidden => Localization.Extra("mutatorNamesHidden", "Jarred Sensors"),
            RiftRun.HpHidden => Localization.Extra("mutatorHpHidden", "Hidden Health"),
            RiftRun.ExplodeOnKill => Localization.Extra("mutatorExplodeOnKill", "Explosive Death"),
            RiftRun.HealOnKill => Localization.Extra("mutatorHealOnKill", "Repair On Kill"),
            RiftRun.BuffOnKill => Localization.Extra("mutatorBuffOnKill", "Strength in Death"),
            RiftRun.Nearsighted => Localization.Extra("mutatorNearsighted", "Nearsighted"),
            RiftRun.Farsighted => Localization.Extra("mutatorFarsighted", "Farsighted"),
            RiftRun.NoLock => Localization.Extra("mutatorNoLock", "No Lock"),
            RiftRun.Vengeance => Localization.Extra("mutatorVengeance", "Vengeance"),
            RiftRun.BossTeleportRepairs => Localization.Extra("mutatorQuantumMend", "Quantum Mend"),
            RiftRun.BossBoost => Localization.Extra("mutatorEvasiveDrift", "Evasive Drift"),
            RiftRun.BossBodyguards => Localization.Extra("mutatorGuardians", "Guardians"),
            _ => id,
        };
    }
}
