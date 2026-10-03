# Medal sound candidates: pure-Python synthesis (no samples), 48 kHz stereo WAV.
import math, random, struct, sys, wave

SR = 48000

def note(name):
    names = {'C': -9, 'C#': -8, 'D': -7, 'D#': -6, 'E': -5, 'F': -4, 'F#': -3, 'G': -2, 'G#': -1, 'A': 0, 'A#': 1, 'B': 2}
    pitch, octave = name[:-1], int(name[-1])
    return 440.0 * 2 ** ((names[pitch] + (octave - 4) * 12) / 12)

def buffer(seconds):
    return [0.0] * int(SR * seconds)

def add(buf, start, samples, gain=1.0):
    i0 = int(start * SR)
    for i, s in enumerate(samples):
        if i0 + i < len(buf): buf[i0 + i] += s * gain

def fm_bell(freq, dur, ratio=3.5, index=2.2, decay=4.0):
    """A bell: sine carrier frequency-modulated by a sine at ratio x, the modulation fading faster than the tone."""
    out = []
    for i in range(int(SR * dur)):
        t = i / SR
        env = math.exp(-decay * t) * min(1.0, t / 0.003)
        mod = index * math.exp(-decay * 2.2 * t) * math.sin(2 * math.pi * freq * ratio * t)
        out.append(env * math.sin(2 * math.pi * freq * t + mod))
    return out

def synth_stab(freq, dur, rise=0.03, decay=5.0):
    """A filtered saw stab with a small upward pitch glide (one-pole lowpass opening and closing)."""
    out, phase, y = [], 0.0, 0.0
    for i in range(int(SR * dur)):
        t = i / SR
        f = freq * (1 - rise * math.exp(-t * 40))
        phase = (phase + f / SR) % 1.0
        saw = 2 * phase - 1
        cutoff = 800 + 5000 * math.exp(-t * 6)
        a = 1 - math.exp(-2 * math.pi * cutoff / SR)
        y += a * (saw - y)
        env = math.exp(-decay * t) * min(1.0, t / 0.004)
        out.append(y * env)
    return out

def chime(freq, dur, decay=2.2):
    """A soft terminal chime: a sine with a quiet octave and twelfth, slightly detuned pairs for a slow shimmer."""
    out = []
    for i in range(int(SR * dur)):
        t = i / SR
        env = math.exp(-decay * t) * min(1.0, t / 0.008)
        s = (math.sin(2 * math.pi * freq * t) + math.sin(2 * math.pi * freq * 1.003 * t)) * 0.5
        s += 0.25 * math.sin(2 * math.pi * freq * 2 * t) * math.exp(-3 * t)
        s += 0.1 * math.sin(2 * math.pi * freq * 3 * t) * math.exp(-6 * t)
        out.append(env * s)
    return out

def sparkle(dur, start_hz=3000, end_hz=9000, density=0.004, seed=1):
    """Tiny high sine grains rising in pitch: the shimmer on top."""
    rng = random.Random(seed)
    out = [0.0] * int(SR * dur)
    n = int(len(out) * density / 10)
    for _ in range(n):
        p = rng.random()
        f = start_hz + (end_hz - start_hz) * p
        i0 = int(p * len(out) * 0.8)
        g = 0.15 * (1 - p)
        for k in range(int(SR * 0.04)):
            if i0 + k >= len(out): break
            t = k / SR
            out[i0 + k] += g * math.sin(2 * math.pi * f * t) * math.exp(-60 * t)
    return out

def reverb(buf, mix=0.25, room=0.82):
    """Schroeder: four parallel combs, two allpasses."""
    combs = [1557, 1617, 1491, 1422]
    out = [0.0] * len(buf)
    for d in combs:
        line, idx = [0.0] * d, 0
        for i, x in enumerate(buf):
            y = line[idx]
            line[idx] = x + y * room
            idx = (idx + 1) % d
            out[i] += y * 0.25
    for d, g in ((225, 0.5), (556, 0.5)):
        line, idx = [0.0] * d, 0
        for i in range(len(out)):
            b = line[idx]
            x = out[i]
            y = -g * x + b
            line[idx] = x + g * y
            idx = (idx + 1) % d
            out[i] = y
    return [d * (1 - mix) + w * mix for d, w in zip(buf, out)]

def write(path, buf, peak=0.8):
    m = max(1e-9, max(abs(s) for s in buf))
    k = peak / m
    with wave.open(path, 'wb') as w:
        w.setnchannels(2)
        w.setsampwidth(2)
        w.setframerate(SR)
        frames = bytearray()
        for i, s in enumerate(buf):
            # A slight stereo spread: the right channel a few samples late.
            r = buf[i - 12] if i >= 12 else 0.0
            frames += struct.pack('<hh', int(max(-1, min(1, s * k)) * 32767), int(max(-1, min(1, r * k)) * 32767))
        w.writeframes(bytes(frames))

def style_crystal(notes, gap=0.085, tail=1.6, shimmer=True, low=None):
    buf = buffer(gap * len(notes) + tail)
    for i, n in enumerate(notes):
        add(buf, i * gap, fm_bell(note(n), tail), 0.6)
    if low: add(buf, 0, fm_bell(note(low), tail + 0.4, ratio=2.0, index=1.2, decay=2.0), 0.45)
    if shimmer: add(buf, gap * (len(notes) - 1), sparkle(1.0), 1.0)
    return reverb(buf, 0.3)

def style_synth(notes, gap=0.09, tail=1.1, shimmer=True, low=None):
    buf = buffer(gap * len(notes) + tail)
    for i, n in enumerate(notes):
        add(buf, i * gap, synth_stab(note(n), tail), 0.5)
        add(buf, i * gap, synth_stab(note(n) * 2.003, tail, decay=7), 0.15)
    if low: add(buf, 0, synth_stab(note(low), tail + 0.3, decay=3), 0.35)
    if shimmer: add(buf, gap * (len(notes) - 1), sparkle(0.9, 4000, 10000), 0.8)
    return reverb(buf, 0.22)

def style_chime(notes, gap=0.14, tail=2.0, shimmer=False, low=None):
    buf = buffer(gap * len(notes) + tail)
    for i, n in enumerate(notes):
        add(buf, i * gap, chime(note(n), tail), 0.6)
    if low: add(buf, 0, chime(note(low), tail + 0.5, decay=1.5), 0.4)
    if shimmer: add(buf, gap * (len(notes) - 1), sparkle(1.2, 2500, 7000), 0.6)
    return reverb(buf, 0.35, 0.85)

if __name__ == '__main__':
    out = sys.argv[1]
    gold = ['E5', 'G#5', 'B5', 'E6']
    write(out + '/medal_A_crystal_gold.wav', style_crystal(gold))
    write(out + '/medal_B_synth_gold.wav', style_synth(gold))
    write(out + '/medal_C_chime_gold.wav', style_chime(['C5', 'E5', 'G5', 'C6'], shimmer=True))
    print('ok')
