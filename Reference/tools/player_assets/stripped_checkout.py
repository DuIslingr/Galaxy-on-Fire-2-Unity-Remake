# stripped_checkout.py: a checkout of the remake without the original game's assets and what's derived from them
# (docs/notes/player-assets.md "Builds without the originals"): exactly what a build that ships without them contains, for
# building releases and for testing the content layer (the test bed). Every tracked file inventory.py classifies as original
# or derived is left out by a non-cone sparse checkout (with its .meta; a folder with nothing else in it, and the folder's
# .meta, as a whole), and git-lfs fetches only the files kept.
#   python3 Reference/tools/player_assets/stripped_checkout.py patterns            the sparse-checkout rules (stdout)
#   python3 Reference/tools/player_assets/stripped_checkout.py create <dir> [rev]  a new worktree (rev: default HEAD, detached)
#   python3 Reference/tools/player_assets/stripped_checkout.py apply [<dir>]       an existing checkout's rules rewritten
# Run from a checkout of the repository. Never `git lfs pull` in such a checkout without --include: git-lfs writes every
# LFS file, the left-out ones too (apply removes them again).
import collections, os, subprocess, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import inventory

KEEP = ("own",)


def left_out(files):
    """The tracked files to leave out (assets and their .meta) and the folders left out whole."""
    out = set()
    assets = [f for f in files if not f.endswith(".meta")]
    for f in assets:
        if inventory.classify(f)[0] not in KEEP: out.add(f)
    for f in files:
        if f.endswith(".meta") and f[:-5] in out: out.add(f)
    # folders whose every tracked file is left out go as a whole (with their own .meta)
    under = collections.defaultdict(list)
    for f in files:
        parts = f.split("/")
        for i in range(1, len(parts)): under["/".join(parts[:i])].append(f)
    # (to a fixed point: a left-out folder's own .meta, inside its parent, is left out too)
    whole = set()
    while True:
        more = {d for d, fs in under.items() if d not in whole and d.startswith("Assets/") and all(x in out for x in fs)}
        if not more: break
        whole |= more
        out |= {d + ".meta" for d in more}
    top = {d for d in whole if not any(d.startswith(p + "/") for p in whole)}
    return out, top


def patterns(files):
    out, top = left_out(files)
    esc = lambda p: p.replace(" ", "\\ ")   # (gitignore rules: spaces escaped)
    lines = ["/*"]
    lines += [f"!/{esc(d)}/" for d in sorted(top)]
    lines += [f"!/{esc(f)}" for f in sorted(out) if not any(f.startswith(d + "/") for d in top)]
    return lines


def git(*args, cwd=None, env=None):
    return subprocess.run(["git", *args], cwd=cwd, env=env, check=True, capture_output=True, text=True).stdout


def lfs_pull_kept(cwd, files):
    out, top = left_out(files)
    lfs = [p for p in git("lfs", "ls-files", "-n", cwd=cwd).split("\n") if p]
    kept = [p for p in lfs if p not in out and not any(p.startswith(d + "/") for d in top)]
    for i in range(0, len(kept), 200):
        git("lfs", "pull", "--include=" + ",".join(kept[i:i + 200]), cwd=cwd)
    # (a stray full pull's files: gone again)
    git("sparse-checkout", "reapply", cwd=cwd, env={**os.environ, "GIT_LFS_SKIP_SMUDGE": "1"})
    return len(kept)


def apply(cwd):
    files = [f for f in git("ls-files", "Assets", cwd=cwd).split("\n") if f]
    rules = patterns(files)
    path = git("rev-parse", "--git-path", "info/sparse-checkout", cwd=cwd).strip()
    path = path if os.path.isabs(path) else os.path.join(cwd, path)
    git("config", "core.sparseCheckout", "true", cwd=cwd)
    git("config", "core.sparseCheckoutCone", "false", cwd=cwd)
    open(path, "w").write("\n".join(rules) + "\n")
    git("sparse-checkout", "reapply", cwd=cwd, env={**os.environ, "GIT_LFS_SKIP_SMUDGE": "1"})
    n = lfs_pull_kept(cwd, files)
    print(f"{cwd}: {len(rules) - 1} rules, {n} LFS files kept")


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "patterns"
    if cmd == "patterns":
        files = [f for f in git("ls-files", "Assets").split("\n") if f]
        print("\n".join(patterns(files)))
    elif cmd == "create":
        d, rev = os.path.abspath(sys.argv[2]), sys.argv[3] if len(sys.argv) > 3 else "HEAD"
        env = {**os.environ, "GIT_LFS_SKIP_SMUDGE": "1"}
        subprocess.run(["git", "worktree", "add", "--no-checkout", "--detach", d, rev], check=True, env=env)
        git("config", "core.sparseCheckout", "true", cwd=d)
        git("config", "core.sparseCheckoutCone", "false", cwd=d)
        files = [f for f in git("ls-tree", "-r", "--name-only", rev, "Assets", cwd=d).split("\n") if f]
        path = git("rev-parse", "--git-path", "info/sparse-checkout", cwd=d).strip()
        path = path if os.path.isabs(path) else os.path.join(d, path)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, "w").write("\n".join(patterns(files)) + "\n")
        subprocess.run(["git", "checkout", "--detach", rev], cwd=d, check=True, env=env)
        apply(d)
    elif cmd == "apply":
        apply(os.path.abspath(sys.argv[2]) if len(sys.argv) > 2 else os.getcwd())
    else:
        raise SystemExit(__doc__ if __doc__ else "patterns | create <dir> [rev] | apply [<dir>]")


if __name__ == "__main__":
    main()
