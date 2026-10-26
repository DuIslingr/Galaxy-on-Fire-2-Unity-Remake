# Importer performance audit

Audited and improved on 2026-10-26. Changes are in the separate `gof3_ships_importer` and `es2_ships_importer` repositories under `/home/duislingr/GOF2UnityRemakeMods`. Existing cache/provenance changes were retained. Installed mods and source exports were not replaced.

## Implemented changes

| Importer | Avoidable work | Change and accuracy protection |
| --- | --- | --- |
| GoF3 | Each of the four primary ship textures was pixel-decoded to determine the largest input, then decoded again for conversion. | Read dimensions from the 32-byte header. Legacy-packed files still use the existing decompressor. Pixel decoding, resampling and shader calculations are unchanged. |
| GoF3 | APK/bundle members were rewritten on every invocation and then reread for SHA-256. | Compare the complete member against the existing extracted file. Reuse identical files, atomically replace differing ones, and reuse the SHA-256 computed during comparison/copy within that invocation. Size, timestamps and ZIP CRC never establish equality. |
| GoF3 | Nested APKs were loaded as one large byte string. | Use a spooled stream, retaining at most 64 MiB before spilling to disk. Member contents and validation remain the same. |
| ES2 | A changed stage recipe still caused every byte of its old snapshot to be hashed before that snapshot was deleted. | Reject mismatched recipes before reading obsolete payloads. Matching recipes still verify the complete snapshot. |
| ES2 | Desktop zip and mobile stages independently hashed the same unchanged desktop output. | Compute that inventory once and share it between those read-only consumers. |
| ES2 | Different material instances repeatedly parsed their shared parent JSON. | Cache up to 256 parsed materials, using canonical names. Clear parsed and resolved material caches whenever a source is configured. This also fixes previously resolved material values surviving a source change. |

## Measurements and output comparisons

These are focused local checks, not full-mod performance claims.

| Check | Result |
| --- | --- |
| Real GoF3 Terran 000 texture conversion, including its paint schemes | All **47 PNG files matched byte for byte** before/after. One illustrative run took 9.254 s before and 8.937 s after; the dominant PNG/conversion work remains. This single pair is not a reliable whole-build speedup estimate. |
| Header dimensions versus actual decoding | Matched for **16 real textures** across the original and merged asset trees, plus synthetic raw/legacy-packed header regression cases. |
| Unchanged 128 MiB synthetic GoF3 XAPK member, including source hashing | Median of three runs: **0.0799 s → 0.0636 s**, about 20% faster for this isolated operation on tmpfs. Source-member SHA-256 values matched. Performance on game archives and other storage will differ. |
| Resolve 200 real ES2 materials | **602 → 240 JSON parses**, with every resolved value identical. The measured samples took 0.0421 s and 0.0062 s; parse counts are the stronger evidence because filesystem cache state affects these short timings. |
| Real ES2 devices-only CLI | Before/after clean, resumed and forced-fresh builds produced identical mod files and ZIP bytes, including all 31 devices/consumables. |
| Regression suites | **31 GoF3 tests + 34 ES2 tests = 65 tests passed.** Coverage includes same-size changes, corrupted/shorter/longer cached bundle members, unchanged-member reuse, nested APK spilling, snapshot integrity, retained full verification, parent material reuse, and source reconfiguration. |
| Compatibility and source checks | Modified sources pass Python 3.9 syntax checks and Git whitespace checks. |

## Audited paths left unchanged

- Copy-on-write snapshot copying: a local 128 MiB Btrfs check showed the existing Python copy routine was already very fast. An explicit Linux clone wrapper offered no meaningful gain and was not retained.
- Shader math, color spaces, mesh precision, texture resolution, filtering, PNG encoding settings and Blender rendering quality were not reduced or changed.
- Full source hashing remains enabled. In particular, large ES2 exports and GoF3 archives are not accepted as unchanged based only on timestamps or sizes.
- More aggressive material/image caching, Blender batching and conversion parallelism need profiling with representative full builds before changes. They can increase peak memory or alter state between conversions.

## Remaining verification limits

The audit did not perform complete imports of both games or visual comparisons of all ships, sectors and effects. The real asset checks above supplement deterministic regression fixtures; they do not establish the total speedup of a full import. No Windows/macOS runtime checks were performed. Future code changes may invalidate existing stage fingerprints once, after which matching stages resume normally.

Run either repository's tests with `python3 -B -m unittest discover -s tests -q` from that importer directory.
