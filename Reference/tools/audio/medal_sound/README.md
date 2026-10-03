# Medal toast sound

`Assets/Resources/GoF2Sfx/MedalToast.ogg` (the station's new-medal toast, `StationMenu.ShowNextMedal`) is the remake's own
sound, synthesized in plain Python (no samples, no third-party audio): variant C1 of `medal_scifi.py`, a rising C-major
chime (C5 E5 G5 C6, 0.14 s apart) whose notes glide up into pitch, with a Schroeder reverb and stereo ping-pong echoes.

```
python medal_scifi.py <out folder>        # writes medal_C1_glide_echo.wav (and the C2 / C3 variants)
ffmpeg -i <out folder>/medal_C1_glide_echo.wav -af "volume=-6dB" -c:a libvorbis -q:a 6 MedalToast.ogg
```

The -6 dB puts it near the game's other interface sounds (peak about -8 dB). `medal_synth.py` holds the shared helpers and
the first candidates (A crystal bells, B synth stabs, C station chime).
