"""Parser for the legacy FMOD Designer event data (RIFF chunk LGCY) of Assets/Audio/_FMOD_GOF2.fev.bytes.

    python fev_lgcy.py --json out.json        everything as JSON
    python fev_lgcy.py --event Map_Whoosh     one event (name or system id): group, properties, parameters,
                                              layers -> sound instances -> sound definitions -> waves, envelopes
    python fev_lgcy.py --ids                  system id <tab> event name <tab> wave files (the corrected id table)
    python fev_lgcy.py --sounddef /Jumpgate   one sound definition (name, STRR index or definition index)
    python fev_lgcy.py --check                parse, then compare with tools/dialogue/fev_events.py + research ids

Private project tool; the data is Deep Silver's. Never publish the file or its output.

FORMAT (version 0x450000, from the FMOD Ex 4.x event loader in Reference/decompiled/fmodevent/_all.c)
All values little endian. u32/i32/f32 = 4 bytes, u16 = 2. "str" = u32 length (incl. NUL) + bytes.
"sidx" = u32 index into the STRR string table (versions >= 0x410000 store names that way, older ones as str).

RIFF 'FEV ' (FUN_0004e8b8): FMT (u32 version, FUN_0004d97c), LIST 'PROJ' { OBCT, PROP, LGCY, EPRP, STRR, LANG }.
  OBCT (FUN_0004d9ac): u32 n, n x (u32 id < 0x21, u32 count)  object counts used to size the memory pools.
  PROP: str project name.  LANG: u32 n, n x str, u32 (current language index).
  EPRP (FUN_00051794): u32 n, n x envelope point { f32 position, f32 value, u32 curve shape }. The envelopes in
       LGCY only hold indices into this table (version >= 0x410000).
  STRR: u32 n, n x u32 offset, NUL-terminated strings (read by tools/dialogue/fev_events.py strr()).
LGCY (handler FUN_000537ac): u32 memory pool size (-> FUN_00051a30 param_6, SimpleMemPool), u32 skipped
  (FUN_00060c64(4)), then the project body FUN_00051a30:
  project   str name (>= 0x190000); u32 bank count; u32 language count (> 0x40ffff)
  bank x N  (0x2e0 each) u32 flags (+0x14 FMOD_MODE-ish load flags); u32 max streams (+0x144, >= 0x140000);
            per language (>= 0x3d0000): 8 bytes (hash / bank GUID half, +0x158) + u32 (> 0x40ffff, +0x258);
            str bank name
  categories FUN_00033f0c, recursive from "master": str name; f32 volume; f32 pitch;
            (> 0x28ffff) u32 max playbacks (+0x28), u32 max-playbacks behaviour (1..4 -> flags);
            u32 child count; children
  u32 top-level event group count, groups FUN_00037414 (recursive):
    group   sidx name (+0x14); (>= 0x170000) u32 user property count + user properties (FUN_00056620);
            u32 subgroup count; u32 event count; subgroups (recursive, FIRST), then the events
    event   u32 flags (> 0x33ffff; 0x10 = simple event, 0x08 = complex); sidx name (+0xb8 info +0x18);
            16 bytes GUID (u32, u16, u16, 8 bytes); then the properties (offsets and names from
            EventI::getPropertyByIndex, FMOD_EVENTPROPERTY order): f32 volume (+0x30); f32 pitch (+0x38, raw:
            x4 = octaves, x48 = semitones); f32 pitch randomization (+0x90, >= 0x1b0000); f32 volume
            randomization (+0x94, >= 0x200000); u32 priority (+0x40); u32 max playbacks (instance pool,
            FUN_00030c54); u32 steal priority (+0x98, >= 0x380000); u32 FMOD_MODE (+0x44: 8 = 2D, 0x10 = 3D,
            0xc0000 3D position (head / world relative), 0x4700000 rolloff, bit 30 ignore geometry);
            f32 3D min distance (+0xe4); f32 3D max distance (+0xe8); (>= 0x450000) u32 auto distance
            filtering (+0x12c), f32 auto distance centre freq (+0x130); u32 event flags (+0x70 |=, > 0xeffff;
            0x80000 = oneshot); 8 x f32 speaker levels L R C LFE LR RR LS RS (+0x134..+0x150);
            f32 cone inside angle (+0x10c); f32 cone outside angle (+0x110); f32 cone outside volume (+0x114);
            u32 max-playbacks behaviour (>= 0xb0000; 1 steal oldest, 2 steal newest, 3 steal quietest,
            4 just fail, 5 just fail if quietest); f32 doppler scale (+0x118, clamped 0..5); f32 reverb dry
            level (+0x9c, >= 0x1c0000); f32 reverb wet level (+0xa0); f32 3D speaker spread (+0x124,
            > 0x11ffff); u32 fade in ms (+0xb4, > 0x12ffff); u32 fade out ms (+0xb6); (> 0x15ffff:)
            f32 spawn intensity (+0xa8, > 0x2affff); f32 spawn intensity randomization (+0xac, > 0x2cffff);
            f32 3D pan level (+0x128); u32 3D position randomization min (+0x104, >= 0x440000); u32 ... max
            (+0x108, >= 0x280000);
            body = vtable +0x84 of the event implementation (simple / complex, below);
            u32 category count, per category str (category path, e.g. "sfx")
    simple event body  FUN_0004a544: u32 (+0xc, 1 here); one sound instance (FUN_0005494c) on an implicit layer
    complex event body FUN_00046e3c:
      u32 layer count; per layer (0x58): u16 flags (+0x18), i16 priority (+0x1c, -1 = none),
          u16 control parameter index (+0x24, 0xffff = none), u16 sound instance count, u16 envelope count,
          sound instances (FUN_0005494c), envelopes (FUN_00046178)
      u32 parameter count; per parameter (0x30, FUN_0003b388): sidx name (+0xc); f32 velocity (+0x10,
          units/s, EventParameterI::getVelocity); f32 range min (+0x14); f32 range max (+0x18)
          (EventParameterI::getRange); u32 flags (+0x28: 1 = primary parameter (event +0x2c), bits 1..3 =
          loop behaviour: 2 oneshot, 4 oneshot and stop event, 8 loop); f32 seek speed (+0x1c, >= 0x120000,
          getSeekSpeed); u32 number of envelopes driven by it (+0x2c, sizes the array of FUN_0003c240);
          u32 sustain point count (>= 0xc0000) + that many f32 (+0x20, clamped 0..1)
      u32 user property count, user properties (FUN_00056620)
    sound instance FUN_0005494c (0x94): u16 sound definition index (>= 0x270000); f32 start (+0x14);
          f32 length (+0x18) [both normalized: 0..1 = the control parameter's range min..max];
          u32 (> 0x1dffff, flag 0x20; start mode?); u32 loop mode (bit 1 -> flag 0x10 "loop and play to end":
          leaving the region only turns the channel's loop off; else bit 0 -> 4 "oneshot": started with
          FMOD_LOOP_OFF; else 2 "loop and cutoff": stopped on leaving the region; bit 0x200 kept, >= 0x310000);
          i32 loop count (+0x34, >= 0x1f0000, -1 = forever); u32 autopitch enabled (flag 0x100);
          f32 autopitch reference (+0x28); f32 autopitch at min (+0x2c, >= 0x240000); f32 fine tune (+0x30);
          f32 volume (+0x1c); f32 crossfade in (+0x20); f32 crossfade out (+0x24); (>= 0x180000) u32 crossfade
          in type, u32 crossfade out type (+0x38 |= in | out << 4)
    envelope FUN_00046178 (0x3c): i32 parent envelope index (+0x24, -1 = none; >= 0x270000);
          str effect name (+0x1c: a DSP effect, empty for the built-in ones); u32 DSP parameter index (+0x20);
          u32 flags (+0x10, & ~0x4000, > 0x25ffff: 8 Volume, 0x10 Pitch, 0x20 Pan, 0x40 Time offset,
          0x80 Surround pan, 0x100 3D speaker spread, 0x200 Reverb level, 0x400 3D pan level, 0x800 Reverb
          balance, 0x1000 Spawn intensity; none of these = a DSP effect envelope); u32 flags2 (+0x14,
          & ~1, > 0x38ffff); u32 point count; (>= 0x410000) point count x u32 index into EPRP;
          u32 controlling parameter index (+0x2c, matched against the parameters in FUN_00046e3c);
          u32 bool (+0x38, >= 0x1a0000)
          Evaluation FUN_00034790: point positions are normalized like the sound regions; between two
          points the END point's shape applies: 1 smooth (bezier), 2 linear, 4 log (2^(10t) curve), 8 flat
          middle (cubic S); a single point = constant. Application FUN_00042cec: Volume multiplies the gain
          by the value (linear); Pitch multiplies the frequency by 2^(8 * value - 4) (0.5 = unchanged,
          +-4 octaves; constants 8.0 / 4.0 at 0x42f40 in libfmodevent.so).
    user property FUN_00056620: str name; u32 type (0 int, 1 float: 4 bytes; 2 string: str; other: none)
  (> 0x2dffff) u32 sound definition template count; per template (0x44) FUN_0004fd3c (vtable +0x30):
          u32 play mode (-> bits 4..7 of word 0; mode >> 2: 0 random, weighted by the wave weights (bit 0 =
          repeats allowed, bit 1 = silences may repeat), 1 shuffle (bit 0 = one permutation per definition),
          2 sequential (3 = one counter per definition, else per instance), 3 programmer selected;
          FUN_000605d4 / FUN_000554b8 / FUN_00055a7c; old enum -> raw in FUN_0005fdb4 / FUN_0005fd44);
          u32 spawn time min ms (w2); u32 spawn time max ms (w3) (FUN_0005ff10: max >= 0, min <= max);
          u32 maximum spawned sounds (w1); f32 volume (w4); u32 bool word0 bit 3 (>= 0x1b0000);
          f32 w5, f32 w6 (legacy volume randomization range); f32 w7 (>= 0x1b0000: volume randomization,
          minimum gain; FUN_0006002c uses it when bit 3 is set: gain = w4 * (w7 + (1 - w7) * rand));
          f32 w8 (pitch); u32 bool word0 bit 2 (>= 0x1b0000); f32 w9, f32 w10 (legacy pitch randomization
          range); f32 w11 (>= 0x1b0000: pitch randomization, raw pitch units; FUN_00060944 uses it when bit 2
          is set); u32 2-bit value word0 bits 0..1 (>= 0x3c0000; 1 sets sound flag 0x400, probably the
          randomization behaviour); f32 w12 (>= 0x440000) / f32 w13 (> 0x29ffff): 3D position randomization
          min / max radius (FUN_000601e8); (> 0x3dffff) u16 / u16 trigger delay min / max ms (+0x38 / +0x3a,
          FUN_0006052c); (> 0x3effff) u16 +0x3c (not identified)
  u32 sound definition count; per definition (0x2c): sidx name (+0x10); u32 template index (+0xc);
          u32 wave count; per wave (0x18): u32 type (0 wavetable, 1 oscillator, 2 don't play (silence),
          3 programmer sound); u32 weight (>= 0xe0000, default 100);
          type 0: str file name, u32 bank index, u32 index in bank, u32 length ms (> 0x7ffff);
          type 1: u32 oscillator type, f32/u32 frequency; types 2, 3: nothing
  (> 0x14ffff) u32 reverb count; per reverb (0x6c): str name; then FMOD_REVERB_PROPERTIES fields in this
          order: Room, RoomHF, (skipped), DecayTime, DecayHFRatio, Reflections, ReflectionsDelay, Reverb,
          ReverbDelay, Diffusion, Density, HFReference, (> 0x1bffff) RoomLF, LFReference, then Instance,
          Environment, (skipped), EnvDiffusion, RoomLF, DecayLFRatio, 3 x (skipped), 3 x (skipped),
          (skipped), (skipped), ModulationTime, ModulationDepth, (skipped), LFReference, Flags. The skipped
          slots match the old FMOD 4.0 struct (RoomRolloffFactor, EnvSize, ReflectionsPan[3],
          ReverbPan[3], EchoTime, EchoDepth, AirAbsorptionHF); kept here under those names.
  (> 0x2effff) music data: RIFF-like sub chunks (u32 size incl. the 8-byte header, 4cc) read until the end of
          the 'comp' chunk: sett, thms, scns, prms, tlns, cues, lnks, sgms (FMOD music system). This file
          has an empty 'comp' (size 8), i.e. no music system data.

System ids (FModSound::play(id) -> EventSystem::getEventBySystemID; the project's event array +0x68 is built by
FUN_0003ce60 and indexed by EventProjectI::getEventByProjectID): per top-level group, first the group's own
events, then its subgroups (recursively). The file stores a group's subgroups before its events, but no group in
this project has both, so system id == file order here (checked by --check). The EventSystemI implementation of
getEventBySystemID (vtable +0x98) was not located; the id = project index mapping is confirmed by the voice
anchors of tools/dialogue/fev_events.py (text -> sound table 0x255210).
"""
import sys, os, struct, json

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
DEFAULT = os.path.join(ROOT, 'Assets', 'Audio', '_FMOD_GOF2.fev.bytes')

ENV_FLAGS = [(0x8, 'Volume'), (0x10, 'Pitch'), (0x20, 'Pan'), (0x40, 'Time offset'), (0x80, 'Surround pan'),
             (0x100, '3D speaker spread'), (0x200, 'Reverb level'), (0x400, '3D pan level'),
             (0x800, 'Reverb balance'), (0x1000, 'Spawn intensity')]
# FUN_0005fd44 / FUN_0005fdb4 (old enum -> raw), behaviour from FUN_000605d4 / FUN_000554b8
# (old Designer enum in brackets; what bit 0 changes for the per-instance sequential modes 8 / 9 is not visible
# in FUN_000605d4)
PLAY_MODES = {0: 'random no repeat [2]', 1: 'random no repeat, silences may repeat',
              2: 'random, silences not repeated', 3: 'random [1]', 4: 'shuffle [4]', 5: 'shuffle global [6]',
              8: 'sequential per instance [3]', 9: 'sequential per instance [0]', 10: 'sequential (10)',
              11: 'sequential global [7]', 12: 'programmer selected [5]'}
WAVE_TYPES = {0: 'wavetable', 1: 'oscillator', 2: "don't play", 3: 'programmer'}
LOOP_MODES = {0: 'loop and cutoff', 1: 'oneshot', 2: 'loop and play to end'}
# parameter +0x28 bits 1..3; 8 on the self-moving 'Loop' parameters (velocity > 0), so 8 = loop
LOOP_BEHAVIOR = {2: 'oneshot', 4: 'oneshot and stop event', 8: 'loop'}
# envelope point curve shape of the segment's END point, FUN_00034790
SHAPES = {0: 'none (0)', 1: 'smooth', 2: 'linear', 4: 'log', 8: 'flat middle'}
SPEAKERS = ['L', 'R', 'C', 'LFE', 'LR', 'RR', 'LS', 'RS']   # +0x134.. (EventI::getPropertyByIndex 0x1a..0x21)


class Reader:
    def __init__(self, b, pos, end):
        self.b, self.pos, self.end = b, pos, end

    def take(self, n):
        if self.pos + n > self.end:
            raise EOFError('read of %d bytes at %d runs past %d' % (n, self.pos, self.end))
        d = self.b[self.pos:self.pos + n]
        self.pos += n
        return d

    def u32(self): return struct.unpack('<I', self.take(4))[0]
    def i32(self): return struct.unpack('<i', self.take(4))[0]
    def u16(self): return struct.unpack('<H', self.take(2))[0]
    def i16(self): return struct.unpack('<h', self.take(2))[0]
    def f32(self): return round(struct.unpack('<f', self.take(4))[0], 6)

    def s(self):
        n = self.u32()
        d = self.take(n)
        return d.split(b'\0', 1)[0].decode('latin1')


def chunks(b, o, end):
    while o + 8 <= end:
        cid = b[o:o + 4].decode('latin1'); sz = struct.unpack('<I', b[o + 4:o + 8])[0]
        yield cid, o + 8, sz
        o += 8 + sz + (sz & 1)


def read_strr(d):
    """same as tools/dialogue/fev_events.py strr(), on a chunk payload"""
    n = struct.unpack('<I', d[:4])[0]
    offs = struct.unpack('<%dI' % n, d[4:4 + 4 * n])
    base = 4 + 4 * n
    return [d[base + x:d.index(b'\0', base + x)].decode('latin1') for x in offs]


class Parser:
    def __init__(self, b, version, strings):
        self.b, self.v, self.S = b, version, strings

    def name(self, r):
        if self.v >= 0x410000:
            i = r.u32()
            return i, (self.S[i] if 0 <= i < len(self.S) else None)
        return None, r.s()

    # ---- FUN_00056620
    def user_property(self, r):
        p = {'name': r.s(), 'type': r.u32()}
        if p['type'] == 0:
            p['value'] = r.i32()
        elif p['type'] == 1:
            p['value'] = r.f32()
        elif p['type'] == 2:
            p['value'] = r.s()
        return p

    # ---- FUN_00033f0c
    def category(self, r):
        c = {'name': r.s(), 'volume': r.f32(), 'pitch': r.f32()}
        if self.v > 0x28ffff:
            c['max_playbacks'] = r.u32()
            c['max_playbacks_behavior'] = r.u32()
        n = r.u32()
        c['children'] = [self.category(r) for _ in range(n)]
        return c

    # ---- FUN_0005494c
    def sound_instance(self, r):
        v = self.v
        if v < 0x270000:
            raise NotImplementedError('sound instance with a string sound-definition name (< 0x270000)')
        si = {'sounddef': r.u16(), 'start': r.f32(), 'length': r.f32()}
        if v > 0x1dffff:
            si['start_mode'] = r.u32()               # flag 0x20 (wait for previous?)
        lm = r.u32()
        si['loop_mode_raw'] = lm
        # bit 1 -> 0x10: on leaving the region the channel is set to loop off and plays out (FUN_000555e8);
        # bit 0 -> 4: the channel is started with FMOD_LOOP_OFF (FUN_0002a... setMode & ~6 | 1); else 2: looped,
        # stopped when the parameter leaves the region
        si['loop_mode'] = 'loop and play to end' if lm & 2 else ('oneshot' if lm & 1 else 'loop and cutoff')
        if v >= 0x1f0000:
            si['loop_count'] = r.i32()
        si['autopitch_enabled'] = r.u32()
        si['autopitch_reference'] = r.f32()          # +0x28
        if v >= 0x240000:
            si['autopitch_at_min'] = r.f32()         # +0x2c
        si['fine_tune'] = r.f32()                    # +0x30
        if v < 0x340000:
            r.u32(); r.u32()
        si['volume'] = r.f32()                       # +0x1c
        si['crossfade_in'] = r.f32()                 # +0x20
        si['crossfade_out'] = r.f32()                # +0x24
        if v >= 0x180000:
            si['crossfade_in_type'] = r.u32()
            si['crossfade_out_type'] = r.u32()
        return si

    # ---- FUN_00046178 (one envelope)
    def envelope(self, r):
        v = self.v
        if v < 0x270000:
            raise NotImplementedError('envelope with string names (< 0x270000)')
        e = {'parent': r.i32(), 'effect': r.s(), 'dsp_param': r.u32()}
        if v > 0x25ffff:
            e['flags'] = r.u32() & 0xffffbfff
            if v > 0x38ffff:
                e['flags2'] = r.u32() & 0xfffffffe
        n = r.u32()
        if v < 0x410000:
            raise NotImplementedError('inline envelope points (< 0x410000)')
        e['point_index'] = [r.u32() for _ in range(n)]
        e['parameter'] = r.u32()                     # +0x2c: index of the event parameter driving it
        e['u38'] = r.u32() if v >= 0x1a0000 else 0   # +0x38 bool
        f = e.get('flags', 0)
        ctl = [nm for bit, nm in ENV_FLAGS if f & bit]
        e['controls'] = ctl if ctl else ['DSP ' + (e['effect'] or '?') + ' param %d' % e['dsp_param']]
        return e

    # ---- FUN_00046e3c
    def complex_body(self, r):
        body = {'layers': [], 'parameters': [], 'user_properties': []}
        for _ in range(r.u32()):
            if self.v < 0x270000:
                raise NotImplementedError('layer header < 0x270000')
            L = {'flags': r.u16(), 'priority': r.i16(), 'parameter': r.u16()}
            ns, ne = r.u16(), r.u16()
            L['sounds'] = [self.sound_instance(r) for _ in range(ns)]
            L['envelopes'] = [self.envelope(r) for _ in range(ne)]
            for en in L['envelopes']:       # DSP parameter envelopes without a name belong to their parent's DSP
                if en['controls'][0].startswith('DSP ?') and 0 <= en['parent'] < len(L['envelopes']):
                    en['controls'] = ['DSP %s param %d' % (L['envelopes'][en['parent']]['effect'], en['dsp_param'])]
            if L['parameter'] == 0xffff:
                L['parameter'] = None
            body['layers'].append(L)
        for _ in range(r.u32()):
            p = {}
            p['name_index'], p['name'] = self.name(r)
            if self.v < 0x410000 and self.v < 0x120000:
                r.u32(); r.u32()
            p['velocity'] = r.f32()                  # +0x10 (EventParameterI::getVelocity)
            p['min'] = r.f32(); p['max'] = r.f32()   # +0x14 / +0x18 (EventParameterI::getRange)
            if self.v < 0x100000:
                raise NotImplementedError('parameter flags < 0x100000')
            fl = r.u32()
            p['flags'] = fl
            p['primary'] = bool(fl & 1)
            p['loop_behavior'] = LOOP_BEHAVIOR.get(fl & 0xe)
            p['seek_speed'] = r.f32() if self.v >= 0x120000 else 0    # +0x1c (getSeekSpeed)
            p['envelope_count'] = r.u32()            # +0x2c: envelopes driven by it (FUN_0003c240 array)
            p['sustain_points'] = [r.f32() for _ in range(r.u32())] if self.v >= 0xc0000 else []
            body['parameters'].append(p)
        body['user_properties'] = [self.user_property(r) for _ in range(r.u32())]
        return body

    # ---- FUN_0004a544
    def simple_body(self, r):
        return {'u0c': r.u32(), 'sound': self.sound_instance(r)}

    # ---- FUN_00037414, event part
    def event(self, r, path):
        v = self.v
        at = r.pos
        e = {'offset': at, 'group': path}
        e['flags'] = r.u32() if v > 0x33ffff else 8
        e['name_index'], e['name'] = self.name(r)
        g = r.take(16)
        e['guid'] = '%08x-%04x-%04x-%s-%s' % (struct.unpack('<I', g[:4])[0], struct.unpack('<H', g[4:6])[0],
                                              struct.unpack('<H', g[6:8])[0], g[8:10].hex(), g[10:].hex())
        P = e['properties'] = {}
        P['volume'] = r.f32(); P['pitch'] = r.f32()
        if v >= 0x1b0000:
            P['pitch_randomization'] = r.f32()
            if v > 0x1fffff:
                P['volume_randomization'] = r.f32()
        P['priority'] = r.u32()
        P['max_playbacks'] = r.u32()
        P['steal_priority'] = r.u32() if v >= 0x380000 else 10000
        P['mode'] = r.u32()
        P['min_distance'] = r.f32(); P['max_distance'] = r.f32()
        if v >= 0x450000:
            P['auto_distance_filtering'] = r.u32()
            P['auto_distance_center_freq'] = r.f32()
        P['event_flags'] = r.u32()
        P['speaker_levels'] = dict(zip(SPEAKERS, [r.f32() for _ in range(8)]))
        P['cone_inside_angle'] = r.f32(); P['cone_outside_angle'] = r.f32(); P['cone_outside_volume'] = r.f32()
        P['max_playbacks_behavior'] = r.u32()
        P['doppler_scale'] = r.f32()
        P['reverb_dry_level'] = r.f32() if v >= 0x1c0000 else 0
        P['reverb_wet_level'] = r.f32()
        if v > 0x11ffff:
            P['speaker_spread'] = r.f32()
        if v > 0x12ffff:
            P['fade_in'] = r.u32(); P['fade_out'] = r.u32()
            if v > 0x15ffff:
                if v > 0x2affff:
                    P['spawn_intensity'] = r.f32()
                    if v > 0x2cffff:
                        P['spawn_intensity_randomization'] = r.f32()
                P['pan_level_3d'] = r.f32()
                if v >= 0x440000:
                    P['position_randomization_min'] = r.u32()   # +0x104 (property 0x2b)
                if v >= 0x280000:
                    P['position_randomization_max'] = r.u32()   # +0x108 (property 0x2c)
        # the implementation's vtable +0x84 (FUN_0004a544 / FUN_00046e3c)
        if e['flags'] & 0x10:
            e['type'] = 'simple'
            e.update(self.simple_body(r))
        else:
            e['type'] = 'complex'
            e.update(self.complex_body(r))
        e['categories'] = [r.s() for _ in range(r.u32())]
        e['end'] = r.pos
        return e

    def group(self, r, path, events):
        g = {'offset': r.pos}
        g['name_index'], g['name'] = self.name(r)
        g['user_properties'] = [self.user_property(r) for _ in range(r.u32())] if self.v >= 0x170000 else []
        nsub, nev = r.u32(), r.u32()
        p = path + [g['name']]
        g['groups'] = [self.group(r, p, events) for _ in range(nsub)]
        g['events'] = []
        for _ in range(nev):
            e = self.event(r, '/'.join(p))
            e['file_index'] = len(events)
            events.append(e)
            g['events'].append(e['file_index'])
        return g

    # ---- FUN_0004fd3c
    def template(self, r):
        v = self.v
        t = {}
        pm = r.u32()
        t['play_mode_raw'] = pm
        t['play_mode'] = PLAY_MODES.get(pm, '?%d' % pm)
        t['spawn_time_min'] = r.u32(); t['spawn_time_max'] = r.u32()      # w2 / w3, ms
        t['max_spawned_sounds'] = r.u32()                                   # w1
        t['volume'] = r.f32()                                               # w4
        # FUN_0006002c: bit 3 set -> gain = volume * (w7 + (1 - w7) * rand), else the legacy w5..w6 range
        t['volume_rand_new'] = r.u32() if v >= 0x1b0000 else 0            # word0 bit 3
        t['volume_rand_legacy_min'] = r.f32(); t['volume_rand_legacy_max'] = r.f32()   # w5 / w6
        t['volume_randomization'] = r.f32() if v >= 0x1b0000 else 0       # w7, minimum gain (1 = none)
        t['pitch'] = r.f32()                                                # w8, raw pitch units (x4 = octaves)
        # FUN_00060944: bit 2 set -> pitch randomization w11, else the legacy w9..w10 range
        t['pitch_rand_new'] = r.u32() if v >= 0x1b0000 else 0             # word0 bit 2
        t['pitch_rand_legacy_min'] = r.f32(); t['pitch_rand_legacy_max'] = r.f32()     # w9 / w10
        if v >= 0x1b0000:
            t['pitch_randomization'] = r.f32()                              # w11, raw (x48 = semitones)
            if v >= 0x3c0000:
                t['randomization_behavior'] = r.u32()                       # word0 bits 0..1 (1 -> sound flag 0x400)
                if v >= 0x440000:
                    t['position_randomization_min'] = r.f32()               # w12 (FUN_000601e8)
            if v > 0x29ffff:
                t['position_randomization_max'] = r.f32()                   # w13
                if v > 0x3dffff:
                    t['trigger_delay_min'] = r.u16(); t['trigger_delay_max'] = r.u16()  # ms (FUN_0006052c)
                    if v > 0x3effff:
                        t['u3c'] = r.u16()                                  # +0x3c, not identified
        return t

    def sounddef(self, r, i):
        d = {'index': i, 'offset': r.pos}
        if self.v < 0x410000:
            raise NotImplementedError('sound definitions with string names (< 0x410000)')
        d['name_index'] = r.u32(); d['name'] = self.S[d['name_index']]
        d['template'] = r.u32()
        d['waves'] = []
        for _ in range(r.u32()):
            w = {'type': r.u32()}
            w['weight'] = r.u32() if self.v >= 0xe0000 else 100
            if w['type'] == 0:
                w['file'] = r.s(); w['bank'] = r.u32(); w['bank_index'] = r.u32()
                w['length_ms'] = r.u32() if self.v > 0x7ffff else 0
            elif w['type'] == 1:
                w['oscillator_type'] = r.u32(); w['frequency'] = r.f32()
            d['waves'].append(w)
        return d

    REVERB = ['Room', 'RoomHF', 'RoomRolloffFactor?', 'DecayTime', 'DecayHFRatio', 'Reflections',
              'ReflectionsDelay', 'Reverb', 'ReverbDelay', 'Diffusion', 'Density', 'HFReference']
    REVERB2 = ['RoomLF', 'LFReference']
    REVERB3 = ['Instance', 'Environment', 'EnvSize?', 'EnvDiffusion', 'RoomLF', 'DecayLFRatio',
               'ReflectionsPan0?', 'ReflectionsPan1?', 'ReflectionsPan2?', 'ReverbPan0?', 'ReverbPan1?',
               'ReverbPan2?', 'EchoTime?', 'EchoDepth?', 'ModulationTime', 'ModulationDepth',
               'AirAbsorptionHF?', 'LFReference', 'Flags']
    REVERB_INT = {'Room', 'RoomHF', 'RoomLF', 'Reflections', 'Reverb', 'Instance', 'Environment', 'Flags'}

    def reverb(self, r):
        rv = {'name': r.s()}
        names = self.REVERB + (self.REVERB2 if self.v > 0x1bffff else []) + self.REVERB3
        for n in names:
            rv[n] = r.i32() if n in self.REVERB_INT else r.f32()
        return rv

    def music(self, r):
        """FUN_00051a30 tail: sub chunks until the end of 'comp'"""
        out, end = [], 0
        while True:
            size, cid = r.u32(), r.take(4)
            if self.v < 0x300000:
                cid = cid[::-1]
            cid = cid.decode('latin1')
            out.append({'id': cid, 'size': size, 'offset': r.pos - 8})
            if cid == 'comp':
                end = r.pos + size - 8
            else:
                # sett / thms / scns / prms / tlns / cues / lnks / sgms: the music-system readers
                # (FUN_00023d34 and the vtables of FUN_000235b4..FUN_0002398c); not decoded, kept raw
                out[-1]['data'] = r.take(size - 8).hex()
            if r.pos >= end:
                return out

    def project(self, r):
        v = self.v
        pj = {'lgcy_mempool_size': r.u32(), 'lgcy_skipped': r.u32()}
        pj['name'] = r.s() if v >= 0x190000 else None
        nb = r.u32()
        nl = r.u32() if v > 0x40ffff else 1
        banks = []
        for _ in range(nb):
            bk = {'flags': r.u32()}
            if v >= 0x140000:
                bk['max_streams'] = r.u32()
                if v >= 0x3d0000:
                    bk['languages'] = []
                    for _ in range(nl):
                        h = r.take(8).hex()
                        bk['languages'].append({'hash': h, 'value': r.u32() if v > 0x40ffff else None})
            bk['name'] = r.s()
            banks.append(bk)
        pj['language_count'] = nl
        pj['banks'] = banks
        pj['categories'] = self.category(r)
        events = []
        pj['groups'] = [self.group(r, [], events) for _ in range(r.u32())]
        pj['events'] = events
        if v > 0x2dffff:
            pj['templates'] = [self.template(r) for _ in range(r.u32())]
        pj['sounddefs'] = [self.sounddef(r, i) for i in range(r.u32())]
        pj['reverbs'] = [self.reverb(r) for _ in range(r.u32())] if v > 0x14ffff else []
        pj['music'] = self.music(r) if v > 0x2effff else []
        return pj


def system_order(groups, events):
    """FUN_0003ce60: a group's own events, then its subgroups (recursive), top-level groups in file order"""
    out = []
    def walk(g):
        out.extend(g['events'])
        for s in g['groups']:
            walk(s)
    for g in groups:
        walk(g)
    return out


def parse(path=DEFAULT):
    b = open(path, 'rb').read()
    assert b[:4] == b'RIFF' and b[8:12] == b'FEV ', 'not a RIFF FEV file'
    res = {'file': os.path.basename(path)}
    lgcy = eprp = strr = None
    for cid, o, sz in chunks(b, 12, len(b)):
        if cid == 'FMT ':
            res['version'] = struct.unpack('<I', b[o:o + 4])[0]
        elif cid == 'LIST':
            for c2, o2, s2 in chunks(b, o + 4, o + sz):
                if c2 == 'LGCY':
                    lgcy = (o2, s2)
                elif c2 == 'EPRP':
                    eprp = (o2, s2)
                elif c2 == 'STRR':
                    strr = read_strr(b[o2:o2 + s2])
                elif c2 == 'OBCT':
                    r = Reader(b, o2, o2 + s2)
                    res['object_counts'] = {}
                    for _ in range(r.u32()):
                        k = r.u32(); res['object_counts'][k] = r.u32()
                elif c2 == 'PROP':
                    res['prop_name'] = Reader(b, o2, o2 + s2).s()
                elif c2 == 'LANG':
                    r = Reader(b, o2, o2 + s2)
                    res['languages'] = [r.s() for _ in range(r.u32())]
                    res['language_current'] = r.u32() if r.pos < r.end else None
    v = res['version']
    assert 0x70000 <= v <= 0x450000, 'unsupported version %x' % v
    res['strings'] = len(strr)
    # EPRP points (FUN_00051794)
    pts = []
    if eprp:
        r = Reader(b, eprp[0], eprp[0] + eprp[1])
        for _ in range(r.u32()):
            pts.append({'position': r.f32(), 'value': r.f32(), 'shape': r.u32()})
        res['eprp_consumed'] = r.pos == r.end
    res['points'] = pts
    o, sz = lgcy
    r = Reader(b, o, o + sz)
    p = Parser(b, v, strr)
    pj = p.project(r)
    res['lgcy'] = {'offset': o, 'size': sz, 'end': o + sz, 'stopped_at': r.pos, 'complete': r.pos == o + sz}
    res.update(pj)
    order = system_order(pj['groups'], pj['events'])
    for sid, fi in enumerate(order):
        pj['events'][fi]['system_id'] = sid
    res['system_order'] = order
    return res


# ------------------------------------------------------------------ presentation
def event_files(res, e):
    defs = []
    if e['type'] == 'simple':
        defs = [e['sound']['sounddef']]
    else:
        for L in e['layers']:
            defs += [s['sounddef'] for s in L['sounds']]
    files = []
    for d in defs:
        for w in res['sounddefs'][d]['waves']:
            if w['type'] == 0 and w['file'] not in files:
                files.append(w['file'])
    return files


def find_event(res, key):
    evs = res['events']
    if key.isdigit():
        return next((e for e in evs if e['system_id'] == int(key)), None)
    return next((e for e in evs if e['name'] == key), None)


def fmt_sounddef(res, i, ind='      '):
    d = res['sounddefs'][i]
    t = res['templates'][d['template']] if res.get('templates') else {}
    out = ['%ssounddef %d "%s" (STRR %d), template %d: %s' % (ind, i, d['name'], d['name_index'], d['template'],
                                                             ', '.join('%s=%s' % kv for kv in t.items()))]
    for w in d['waves']:
        if w['type'] == 0:
            out.append('%s  wave %s weight %d bank %d "%s" #%d %d ms' % (
                ind, w['file'], w['weight'], w['bank'], res['banks'][w['bank']]['name'], w['bank_index'],
                w['length_ms']))
        else:
            out.append('%s  %s weight %d %s' % (ind, WAVE_TYPES.get(w['type'], w['type']), w['weight'],
                                               {k: v for k, v in w.items() if k not in ('type', 'weight')}))
    return out


def fmt_sound(res, s, prange, shown, ind='    '):
    lo, hi = prange if prange else (0.0, 1.0)
    sc = lambda x: lo + x * (hi - lo)
    extra = ', '.join('%s=%s' % (k, v) for k, v in s.items() if k not in ('sounddef', 'start', 'length'))
    out = ['%ssound instance: sounddef %d "%s", start %.6g length %.6g (normalized; parameter %.4g .. %.4g), %s' % (
        ind, s['sounddef'], res['sounddefs'][s['sounddef']]['name'], s['start'], s['length'], sc(s['start']),
        sc(s['start'] + s['length']), extra)]
    if s['sounddef'] not in shown:
        shown.add(s['sounddef'])
        out += fmt_sounddef(res, s['sounddef'], ind + '  ')
    return out


def env_value(en, v):
    """what an envelope value means (FUN_00042cec): volume = linear gain, pitch = 2^(8v - 4)"""
    import math
    c = en['controls']
    if c == ['Volume']:
        return 'gain %.3f (%.1f dB)' % (v, 20 * math.log10(v)) if v > 0 else 'gain 0'
    if c == ['Pitch']:
        return 'x%.3f (%+.2f semitones)' % (2 ** (8 * v - 4), (8 * v - 4) * 12)
    return '%.4g' % v


def fmt_event(res, e):
    out = ['system id %d (file order %d) "%s" [%s] type %s, flags 0x%x, offset %d..%d' % (
        e['system_id'], e['file_index'], e['name'], e['group'], e['type'], e['flags'], e['offset'], e['end'])]
    out.append('  guid ' + e['guid'] + '  categories ' + ', '.join(e['categories']))
    out.append('  properties ' + ', '.join('%s=%s' % kv for kv in e['properties'].items()))
    shown = set()
    if e['type'] == 'simple':
        out.append('  simple event, u0c=%d' % e['u0c'])
        out += fmt_sound(res, e['sound'], None, shown)
    else:
        params = e['parameters']
        for i, p in enumerate(params):
            out.append('  parameter %d "%s": range %g .. %g, velocity %g/s, seek speed %g, flags 0x%x (%sloop '
                       'behaviour %s), envelopes %d, sustain points %s' % (
                           i, p['name'], p['min'], p['max'], p['velocity'], p['seek_speed'], p['flags'],
                           'primary, ' if p['primary'] else '', p['loop_behavior'], p['envelope_count'],
                           p['sustain_points']))
        for li, L in enumerate(e['layers']):
            pr = params[L['parameter']] if L['parameter'] is not None and L['parameter'] < len(params) else None
            out.append('  layer %d: flags 0x%x priority %d parameter %s' % (
                li, L['flags'], L['priority'], '%d "%s"' % (L['parameter'], pr['name']) if pr else '-'))
            for s in L['sounds']:
                out += fmt_sound(res, s, (pr['min'], pr['max']) if pr else None, shown)
            for ei, en in enumerate(L['envelopes']):
                pts = [res['points'][k] for k in en['point_index']]
                ep = params[en['parameter']] if en['parameter'] < len(params) else None
                lo, hi = (ep['min'], ep['max']) if ep else (0.0, 1.0)
                out.append('    envelope %d: %s (effect "%s", dsp param %d, flags 0x%x, flags2 0x%x, parent %d, '
                           'parameter %s, u38 %d)' % (ei, ' + '.join(en['controls']), en['effect'], en['dsp_param'],
                                                      en.get('flags', 0), en.get('flags2', 0), en['parent'],
                                                      '%d "%s"' % (en['parameter'], ep['name']) if ep else
                                                      en['parameter'], en['u38']))
                for k, q in zip(en['point_index'], pts):
                    out.append('      point #%d: position %.6g (= %s %.4g), value %.6g = %s, shape %s' % (
                        k, q['position'], ep['name'] if ep else 'param', lo + q['position'] * (hi - lo),
                        q['value'], env_value(en, q['value']), SHAPES.get(q['shape'], q['shape'])))
        if e['user_properties']:
            out.append('  user properties %s' % e['user_properties'])
    return out


def ids_table(res):
    rows = []
    for fi in res['system_order']:
        e = res['events'][fi]
        rows.append((e['system_id'], e['name'], event_files(res, e), e['group']))
    return rows


def check(res):
    """compare with tools/dialogue/fev_events.py and Reference/research/fmod_event_ids.txt"""
    sys.path.insert(0, os.path.join(HERE, '..', 'dialogue'))
    import fev_events
    ev, _ = fev_events.events()
    rows = ids_table(res)
    names = [r[1] for r in rows]
    print('events: LGCY %d (OBCT[0x11] = %s), fev_events %d' % (len(rows), res['object_counts'].get(0x11), len(ev)))
    diffs = [(i, names[i], fev_events.name_of_by_order(i, ev)) for i in range(len(names)) if names[i] != fev_events.name_of_by_order(i, ev)]
    print('ids where fev_events.name_of differs: %d' % len(diffs))
    for d in diffs[:40]:
        print('  %d lgcy %s / fev_events %s' % d)
    fo = [res['events'][i]['name'] for i in range(len(res['events']))]
    print('file order == system order: %s' % (fo == names))
    txt = os.path.join(ROOT, 'Reference', 'research', 'fmod_event_ids.txt')
    bad = 0; n = 0
    for line in open(txt, encoding='utf-8'):
        if line.startswith('#') or not line.strip():
            continue
        f = line.rstrip('\n').split('\t')
        i = int(f[0]); n += 1
        if i < len(names) and names[i] != f[2]:
            bad += 1
            print('  fmod_event_ids.txt %d %s, LGCY %s' % (i, f[2], names[i]))
    print('fmod_event_ids.txt rows %d, mismatches %d' % (n, bad))


def main(a):
    path = DEFAULT
    if '--file' in a:
        path = a[a.index('--file') + 1]
    res = parse(path)
    L = res['lgcy']
    if not L['complete']:
        print('WARNING: LGCY parse stopped at %d, chunk ends at %d' % (L['stopped_at'], L['end']), file=sys.stderr)
    if '--json' in a:
        json.dump(res, open(a[a.index('--json') + 1], 'w', encoding='utf-8'), indent=1)
        print('LGCY %d..%d consumed to %d (%s); %d events, %d sound definitions, %d templates, %d points, %d reverbs'
              % (L['offset'], L['end'], L['stopped_at'], 'complete' if L['complete'] else 'INCOMPLETE',
                 len(res['events']), len(res['sounddefs']), len(res.get('templates', [])), len(res['points']),
                 len(res['reverbs'])))
    elif '--event' in a:
        e = find_event(res, a[a.index('--event') + 1])
        print('\n'.join(fmt_event(res, e)) if e else 'no such event')
    elif '--sounddef' in a:
        k = a[a.index('--sounddef') + 1]
        for d in res['sounddefs']:
            if d['name'] == k or str(d['name_index']) == k or (k.startswith('#') and str(d['index']) == k[1:]):
                print('\n'.join(fmt_sounddef(res, d['index'], '')))
                users = [e['system_id'] for e in res['events'] if d['index'] in (
                    [e['sound']['sounddef']] if e['type'] == 'simple' else
                    [s['sounddef'] for Ly in e['layers'] for s in Ly['sounds']])]
                print('used by events', users)
    elif '--ids' in a:
        for sid, n, files, grp in ids_table(res):
            print('%d\t%s\t%s\t%s' % (sid, n, ' | '.join(files), grp))
    elif '--check' in a:
        check(res)
    else:
        print(__doc__.split('FORMAT')[0])


if __name__ == '__main__':
    try:
        main(sys.argv[1:])
    except (BrokenPipeError, OSError) as ex:     # output piped into head etc.
        if isinstance(ex, BrokenPipeError) or getattr(ex, 'errno', None) == 22:
            os._exit(0)
        else:
            raise
