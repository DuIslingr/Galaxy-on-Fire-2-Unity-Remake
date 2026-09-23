# Reference: the original game

Source material for the remake. Nothing in here is used by Unity; it's for reading and searching.

**Private.** This folder contains decompiled Fishlabs/Deep Silver code and the original binaries. Never publish it.

| Path | What |
|---|---|
| `decompiled/native/game/*.c` | Game logic, one file per C++ class (`Level`, `PlayerEgo`, `PlayerFighter`, `Status`, `Generator`, `Ship`, `Item`, …). This is the part to port. |
| `decompiled/native/engine/*.c` | AbyssEngine (rendering, files, sound). Unity replaces it; reference only. |
| `decompiled/native/INDEX.md` | Every class with its function count and code size. |
| `decompiled/native/CLASS_HIERARCHY.txt` | Inheritance tree recovered from the C++ type info (e.g. `PlayerFighter <- KIPlayer`). |
| `decompiled/native/_ALL_FUNCTIONS.c` | All 4,028 functions in one file. Grep it, or use `tools/show.py`. |
| `decompiled/native/_FUNCTIONS.tsv` | Function name, address and size. |
| `decompiled/native/game/BuildResourceList_DISASSEMBLY.txt` | The one function too large to decompile (resource table). |
| `decompiled/native/BuildResourceList_EMULATED_OUTPUT.json` | Its result, obtained by emulation. The cleaned version is `Assets/GoF2/Resources/GoF2Data/resources.json`. |
| `decompiled/java/` | The Android Java wrapper (activity, input, JNI bridge). |
| `binaries/libgof2hdaa.so` | The original 32-bit ARM game library (for Ghidra or constant lookups). |
| `binaries/GOF2_2.0.16_Android_Price.apk` | The modded APK the code came from. The 1.5 GB OBB is not included; it's on the GitHub release page. |
| `tools/show.py` | `python Reference/tools/show.py "^PlayerFighter::update$"` prints matching decompiled functions. |
| `tools/rf.py` | `python Reference/tools/rf.py 000a8178` reads a `DAT_` constant as float/hex (needs `pip install pyelftools`). |
| `tools/asset_conversion/` | The scripts that produced `Assets/GoF2`: `aem.py` (meshes), `aei.py` (textures), `parse_bins.py` (data), `emu_resources.py` (resource table), `aem2fbx.py` (Blender FBX export), `run_audio.sh` (FMOD banks). |
| `tools/*.java` | Ghidra headless scripts used for the decompile. |

## Reading the pseudocode

- Addresses use Ghidra's image base **0x10000**.
- Fields show up as offsets like `*(float *)(this + 0x27c)`. See `CLAUDE.md` at the project root for the offsets identified so far.
- `DAT_xxxxxxxx` values are constants in the binary; read them with `tools/rf.py`.
- Floating-point arguments are sometimes lost (`extraout_s1`, `in_r1`). Check call sites when something looks missing.
- Game time is in milliseconds (`update(int dt)`).
