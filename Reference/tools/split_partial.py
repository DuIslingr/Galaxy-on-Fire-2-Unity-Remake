"""Splits a big C# class into partial files by feature (CLAUDE.md "Conventions": Big classes are partial, split by
feature into <Class><Area>.cs beside the main file; the fields and Unity messages stay in the main file).

  python -I Reference/tools/split_partial.py sections <File.cs>          # the class's sections and their sizes
  python -I Reference/tools/split_partial.py split <File.cs> <plan.json> [--write]

The sections are the class body's "// ---- title ----" comment lines (the project's own separators); members before the
first one are section 0. plan.json: { "parts": [ { "area": "Docking", "sections": [3, 4], "what": "one line for the new
file's header" }, ... ] }: those sections' movable members go to <Class><Area>.cs. Movable: methods, operators and
properties with a body or an expression body (not auto-properties, fields, events, constructors, nested types, Unity
messages). A member keeps the comments and attributes right above it. The new files repeat the original's usings and
namespace and declare the class as partial (no attributes, no base list); the main file's declaration gains "partial".
Every run checks that the original's lines all come back exactly once across the files (nothing lost, nothing doubled),
not that each line landed in the right file: compile after --write. Seen once: an expression-bodied property whose
expression holds a block lambda (d => { ...; return ...; }) and goes on over a second line lost that line to the main
file. A part appended to an existing file keeps that file's usings: add the ones the moved members need."""

import io, json, os, re, sys
from collections import Counter

UNITY_MESSAGES = {
    "Awake", "Start", "Update", "LateUpdate", "FixedUpdate", "OnEnable", "OnDisable", "OnDestroy", "OnValidate", "Reset",
    "OnApplicationFocus", "OnApplicationPause", "OnApplicationQuit", "OnGUI", "OnDrawGizmos", "OnDrawGizmosSelected",
    "OnTriggerEnter", "OnTriggerExit", "OnTriggerStay", "OnCollisionEnter", "OnCollisionExit", "OnCollisionStay",
    "OnBecameVisible", "OnBecameInvisible", "OnRenderObject", "OnPreRender", "OnPostRender", "OnTransformParentChanged",
    "OnRectTransformDimensionsChange", "OnAnimatorMove", "OnAnimatorIK", "OnBeforeTransformParentChanged",
    "OnNetworkSpawn", "OnNetworkDespawn", "OnGainedOwnership", "OnLostOwnership", "OnDestroyed",
}
SECTION = re.compile(r"^\s*//\s*-{3,}\s*(.*?)\s*-*\s*$")


def scan(text):
    """Per character: brace depth before it, and whether it is code (not in a comment / string / char)."""
    n = len(text)
    depth = [0] * (n + 1)
    code = [True] * n
    d, i = 0, 0
    interp = []   # stack of brace depths at which an interpolated string's hole ends
    while i < n:
        c = text[i]
        depth[i] = d
        nxt = text[i + 1] if i + 1 < n else ""
        if c == "/" and nxt == "/":
            j = text.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j): code[k] = False; depth[k] = d
            i = j
            continue
        if c == "/" and nxt == "*":
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j): code[k] = False; depth[k] = d
            i = j
            continue
        if c == "'" :
            j = i + 1
            while j < n and text[j] != "'":
                j += 2 if text[j] == "\\" else 1
            for k in range(i, min(j + 1, n)): code[k] = False; depth[k] = d
            i = j + 1
            continue
        if c == '"' or (c in "@$" and nxt in '"@$'):
            # a string: "...", @"...", $"...", $@"...", @$"...", and raw """...""" (only as plain or $)
            j = i
            verbatim = interp_s = False
            while j < n and text[j] in "@$":
                verbatim |= text[j] == "@"; interp_s |= text[j] == "$"; j += 1
            if text.startswith('"""', j):
                end = text.find('"""', j + 3)
                end = n if end < 0 else end + 3
                for k in range(i, end): code[k] = False; depth[k] = d
                i = end
                continue
            j += 1
            hole = 0
            while j < n:
                ch = text[j]
                if interp_s and ch == "{":
                    if j + 1 < n and text[j + 1] == "{": j += 2; continue
                    hole += 1
                elif interp_s and ch == "}" and hole > 0:
                    hole -= 1
                elif hole > 0 and ch == '"':
                    # a nested string inside a hole: skip it simply
                    j += 1
                    while j < n and text[j] != '"':
                        j += 2 if text[j] == "\\" else 1
                elif hole == 0 and not verbatim and ch == "\\":
                    j += 2; continue
                elif hole == 0 and ch == '"':
                    if verbatim and j + 1 < n and text[j + 1] == '"': j += 2; continue
                    break
                elif hole == 0 and not verbatim and ch == "\n":
                    break
                j += 1
            for k in range(i, min(j + 1, n)): code[k] = False; depth[k] = d
            i = j + 1
            continue
        if c == "{": d += 1
        elif c == "}": d -= 1
        i += 1
    depth[n] = d
    return depth, code


def find_class(text, depth, code, want=None, any_depth=False):
    """The top-level type named 'want' (the file's name), else the first one (namespace depth 0 or 1; any depth for a
    nested class): (header start, '{' index, '}' index, name)."""
    found = [m for m in re.finditer(r"\b(class|struct)\s+([A-Za-z_][A-Za-z0-9_]*)", text)
             if code[m.start()] and (depth[m.start()] <= 1 or any_depth) and (not any_depth or m.group(2) == want)]
    for m in sorted(found, key=lambda m: m.group(2) != want):
        i = m.start()
        brace = i
        while brace < len(text) and not (text[brace] == "{" and code[brace]): brace += 1
        if text[m.end():brace].strip().startswith(("where", ":")) or text[m.end():brace].strip() == "" or "<" in text[m.end():brace]:
            pass
        body_depth = depth[brace] + 1
        k = brace + 1
        while k < len(text) and not (text[k] == "}" and code[k] and depth[k] == body_depth): k += 1
        line_start = text.rfind("\n", 0, i) + 1
        return line_start, brace, k, m.group(2)
    raise SystemExit("no class found")


def members(text, depth, code, open_b, close_b):
    """The class body's members: list of dicts (start, end, kind, name, header, section)."""
    body_depth = depth[open_b] + 1
    out = []
    i = open_b + 1
    section = 0
    titles = ["(before the first section)"]
    pending_start = None
    while i < close_b:
        # whole lines: blank, comments and attributes gather above the next member
        line_end = text.find("\n", i)
        line_end = close_b if line_end < 0 or line_end > close_b else line_end
        line = text[i:line_end]
        stripped = line.strip()
        if stripped == "":
            if pending_start is not None and all(not code[k] for k in range(i, line_end) if not text[k].isspace()):
                pass
            i = line_end + 1
            continue
        sm = SECTION.match(line)
        if sm and depth[i] == body_depth:
            section += 1
            titles.append(sm.group(1).strip(" -"))
            pending_start = None
            out.append({"start": i, "end": line_end + 1, "kind": "section", "name": "", "header": line, "section": section})
            i = line_end + 1
            continue
        first = next((k for k in range(i, line_end) if not text[k].isspace()), i)
        if not code[first] or stripped.startswith("["):
            # a comment line or an attribute: part of the member below
            if pending_start is None: pending_start = i
            if stripped.startswith("[") and code[first]:
                # an attribute may span lines: to its closing ]
                k = first; dd = 0
                while k < close_b:
                    if code[k] and text[k] == "[": dd += 1
                    elif code[k] and text[k] == "]":
                        dd -= 1
                        if dd == 0: break
                    k += 1
                rest = text[k + 1:text.find("\n", k) if text.find("\n", k) >= 0 else close_b].strip()
                if rest:
                    # an attribute on the member's own line: the member starts here
                    pass
                else:
                    i = text.find("\n", k) + 1
                    continue
            else:
                i = line_end + 1
                continue
        # a member begins at 'first': find its end (a ';' at body depth, or the '}' closing its block at body depth)
        start = pending_start if pending_start is not None else i
        pending_start = None
        k = first
        header_end = None
        kind_end = None
        parens = 0   # a default parameter's "=" (F(int a = 0)) ends no header
        while k < close_b:
            if code[k] and depth[k] == body_depth and header_end is None and text[k] in "()":
                parens += 1 if text[k] == "(" else -1
            if code[k] and depth[k] == body_depth and parens > 0 and header_end is None:
                k += 1
                continue
            if code[k] and depth[k] == body_depth:
                if text[k] == ";":
                    kind_end = k + 1; header_end = header_end or k; break
                if text[k] == "{":
                    header_end = header_end or k
                    # to its matching brace
                    m = k + 1
                    while m < close_b and not (text[m] == "}" and code[m] and depth[m] == body_depth + 1): m += 1
                    after = m + 1
                    # "{ get; } = value;" or a trailing ';' (an initialized auto-property / array field)
                    rest = text[after:text.find("\n", after) if text.find("\n", after) >= 0 else close_b]
                    if re.match(r"\s*=", rest) or re.match(r"\s*;", rest):
                        k = after
                        continue
                    kind_end = after; break
                if text[k] == "=" and text[k + 1:k + 2] == ">" and header_end is None:
                    header_end = k
                if text[k] == "=" and text[k + 1:k + 2] not in (">", "=") and text[k - 1:k] not in ("=", "!", "<", ">") and header_end is None:
                    header_end = k
            k += 1
        end = text.find("\n", kind_end)
        end = close_b if end < 0 else end + 1
        header = re.sub(r"\s+", " ", "".join(ch if code[first + j] else " " for j, ch in enumerate(text[first:header_end]))).strip()
        out.append({"start": start, "end": end, "header": header, "section": section, **classify(header, text[first:kind_end], text[header_end:header_end + 2])})
        i = end
    return out, titles


def classify(header, whole, term):
    """What a member is, from its header (the code before the first top-level "=>", "=", "{" or ";") and that
    terminator."""
    h = re.sub(r"\[[^\]]*\]", " ", header).strip()
    # generic arguments out first: a tuple type's "(" (List<(Renderer a, Renderer b)>) is no parameter list
    while True:
        g = re.sub(r"<[^<>]*>", "", h)
        if g == h: break
        h = g
    if re.search(r"\b(class|struct|enum|interface|record)\s+\w", h) or re.match(r"((public|internal|private|protected|new)\s+)*delegate\b", h):
        return {"kind": "type", "name": ""}
    if re.search(r"\bevent\b", h): return {"kind": "event", "name": ""}
    if term.startswith("=") and not term.startswith("=>"):
        return {"kind": "field", "name": ""}   # an initializer: a field (or an initialized auto-property)
    paren = h.find("(")
    if paren >= 0:
        before = h[:paren].strip()
        name = re.findall(r"([A-Za-z_][A-Za-z0-9_]*)$", before)
        name = name[0] if name else ""
        if re.search(r"\boperator\b", before): return {"kind": "method", "name": "operator"}
        mods = ("public", "private", "internal", "protected", "static", "unsafe", "extern")
        if len([t for t in before.split() if t not in mods]) == 1:
            return {"kind": "ctor", "name": name}   # a constructor (or a destructor, "~Name")
        return {"kind": "method", "name": name}
    name = h.split()[-1] if h.split() else ""
    if term.startswith("=>"): return {"kind": "prop", "name": name}
    if term.startswith("{"):
        w = whole[whole.find("{"):]
        if re.search(r"\b(get|set|init)\s*;", w): return {"kind": "autoprop", "name": ""}
        return {"kind": "prop", "name": name}
    return {"kind": "field", "name": ""}


def movable(m):
    if m["kind"] == "method": return m["name"] not in UNITY_MESSAGES
    return m["kind"] == "prop"


def load(path):
    raw = io.open(path, encoding="utf-8-sig", newline="").read()
    nl = "\r\n" if "\r\n" in raw else "\n"
    return raw.replace("\r\n", "\n"), nl, raw.startswith("﻿")


def cmd_sections(path):
    path, _, nested = path.partition(".cs:")
    path += ".cs" if not path.endswith(".cs") else ""
    text, _, _ = load(path)
    depth, code = scan(text)
    hs, ob, cb, name = find_class(text, depth, code, nested, any_depth=True) if nested else \
        find_class(text, depth, code, os.path.splitext(os.path.basename(path))[0])
    ms, titles = members(text, depth, code, ob, cb)
    sizes = Counter(); moves = Counter()
    for m in ms:
        sizes[m["section"]] += m["end"] - m["start"]
        if movable(m): moves[m["section"]] += m["end"] - m["start"]
    print(f"{name}: {len(text) / 1024:.1f} KB, {len(ms)} members")
    for s, t in enumerate(titles):
        print(f"  [{s:2}] {sizes[s] / 1024:5.1f} KB ({moves[s] / 1024:5.1f} movable)  {t[:110]}")


def cmd_members(path, section):
    """One section's members: kind, name, size (to pick "match" groups in a big section)."""
    path, _, nested = path.partition(".cs:")
    path += ".cs" if not path.endswith(".cs") else ""
    text, _, _ = load(path)
    depth, code = scan(text)
    hs, ob, cb, name = find_class(text, depth, code, nested, any_depth=True) if nested else \
        find_class(text, depth, code, os.path.splitext(os.path.basename(path))[0])
    ms, titles = members(text, depth, code, ob, cb)
    for m in ms:
        if m["section"] == section and m["kind"] != "section":
            print(f"  {m['kind']:8} {(m['end'] - m['start']) / 1024:5.1f} KB  {m['name'] or m['header'][:70]}")


def cmd_split(path, plan_path, write):
    text, nl, bom = load(path)
    depth, code = scan(text)
    plan = json.load(io.open(plan_path, encoding="utf-8"))
    base = os.path.splitext(os.path.basename(path))[0]
    outer = None
    if plan.get("class"):
        # a nested class ("class": its name) inside the file's class: both become partial, the parts nest it again
        outer = find_class(text, depth, code, base)
        hs, ob, cb, cls = find_class(text, depth, code, plan["class"], any_depth=True)
        assert outer[1] < hs < outer[2], "the nested class isn't inside the file's class"
    else:
        hs, ob, cb, cls = find_class(text, depth, code, base)
    ms, titles = members(text, depth, code, ob, cb)
    head = text[:outer[0] if outer else hs]
    usings = "".join(l + "\n" for l in head.split("\n") if l.startswith("using "))
    ns = re.search(r"^namespace\s+([\w.]+)\s*(;|\{)?", head, re.M)
    file_scoped = ns and ns.group(2) == ";"
    decl_line = text[hs:ob]
    kind = "struct" if re.search(r"\bstruct\b", decl_line) else "class"
    mods = [w for w in ("public", "internal", "static", "sealed", "abstract", "unsafe") if re.search(r"\b" + w + r"\b", decl_line.split(kind)[0])]
    mods = [w for w in mods if w not in ("sealed", "abstract")]   # said once is enough
    gen = re.search(r"\b" + kind + r"\s+" + cls + r"\s*(<[^>]*>)?", decl_line).group(1) or ""
    indent = "    " if ns and not file_scoped else ""
    moved = set()
    parts = []
    for p in plan["parts"]:
        # "sections": all their movable members; "match": only those whose name matches (within "sections" when given);
        # a member goes to the first part that takes it
        secs = p.get("sections", [])
        chunk = [m for m in ms if movable(m) and m["start"] not in moved
                 and ((m["section"] in secs) if "match" not in p else (re.search(p["match"], m["name"]) and (not secs or m["section"] in secs)))]
        if not chunk: continue
        for m in chunk: moved.add(m["start"])
        # keep the section separator lines for these sections with their part
        p["sections"] = sorted({m["section"] for m in chunk})
        seps = [m for m in ms if m["kind"] == "section" and m["section"] in p["sections"]]
        body = []
        for s in p["sections"]:
            sep = next((m for m in seps if m["section"] == s), None)
            if sep is not None and any(m["section"] == s for m in chunk):
                body.append(text[sep["start"]:sep["end"]])
            for m in chunk:
                if m["section"] == s:
                    body.append(text[m["start"]:m["end"]])
        parts.append((p, body, seps))
    keep_seps = {m["start"] for m in ms if m["kind"] == "section"}
    moved_seps = set()
    for p, body, seps in parts:
        for sep in seps:
            # the separator moves when nothing of its section stays behind
            stays = [m for m in ms if m["section"] == sep["section"] and m["kind"] != "section" and m["start"] not in moved]
            if not stays: moved_seps.add(sep["start"])
            else:
                # it stays (some fields / messages remain): don't put a copy in the part as well
                for i, b in enumerate(body):
                    if b == text[sep["start"]:sep["end"]]: body[i] = None
    # the main file: the moved members (and separators) cut out
    cut = sorted([(m["start"], m["end"]) for m in ms if m["start"] in moved or m["start"] in moved_seps])
    out, pos = [], 0
    for a, b in cut:
        out.append(text[pos:a]); pos = b
    out.append(text[pos:])
    main = "".join(out)
    main = re.sub(r"\n{3,}", "\n\n", main)
    main = re.sub(r"\{\n\n+(\s*)", r"{\n\1", main, count=0) if False else main
    if not re.search(r"\bpartial\b", decl_line):
        new_decl = re.sub(r"\b" + kind + r"\b", "partial " + kind, decl_line, count=1)
        main = main.replace(decl_line, new_decl, 1)
    outer_decl = None
    if outer:
        # the file's class becomes partial too; the parts declare it around the nested one
        o_line = text[outer[0]:outer[1]]
        o_kind = "struct" if re.search(r"\bstruct\b", o_line.split("{")[0]) else "class"
        o_mods = [w for w in ("public", "internal", "static", "unsafe") if re.search(r"\b" + w + r"\b", o_line.split(o_kind)[0])]
        o_gen = re.search(r"\b" + o_kind + r"\s+" + outer[3] + r"\s*(<[^>]*>)?", o_line).group(1) or ""
        outer_decl = " ".join(o_mods + ["partial", o_kind, outer[3] + o_gen])
        if not re.search(r"\bpartial\b", o_line):
            main = main.replace(o_line, re.sub(r"\b" + o_kind + r"\b", "partial " + o_kind, o_line, count=1), 1)
        mods = [w for w in ("public", "internal", "private", "protected", "static", "unsafe") if re.search(r"\b" + w + r"\b", decl_line.split(kind)[0])]
    folder = os.path.dirname(path)
    files = {path: main}
    appended = set()
    for p, body, _ in parts:
        body = [b for b in body if b is not None]
        owner = outer[3] if outer else cls
        name = owner + p["area"]
        fn = os.path.join(folder, name + ".cs")
        who = f"{owner}.{cls}" if outer else cls
        if os.path.exists(fn):
            # an existing part of the same partial class: the members go in at its end
            ex, ex_nl, ex_bom = load(fn)
            ed, ec = scan(ex)
            try:
                _, eob, ecb, ecls = find_class(ex, ed, ec, cls, any_depth=True)
            except SystemExit:
                raise SystemExit(f"{fn} exists and has no class {cls}")
            if not re.search(r"\bpartial\b", ex[ex.rfind("\n", 0, eob) - 200 if eob > 200 else 0:eob]):
                raise SystemExit(f"{fn} exists and isn't a partial {cls}")
            line_start = ex.rfind("\n", 0, ecb) + 1
            src = ex[:line_start].rstrip("\n") + "\n\n" + "".join(body).rstrip("\n") + "\n" + ex[line_start:]
            files[fn] = src
            appended.add(fn)
            continue
        src = f"// {name}.cs\n// {who}: {p['what']} (part of the partial {who}; its fields are in {base}.cs).\n\n"
        src += usings + ("\n" if usings else "")
        decl = " ".join(mods + ["partial", kind, cls + gen])
        if outer and ns and not file_scoped:
            src += (f"namespace {ns.group(1)}\n{{\n    {outer_decl}\n    {{\n        {decl}\n        {{\n" + "".join(body).rstrip("\n")
                    + "\n        }\n    }\n}\n")
        elif outer:
            raise SystemExit("a nested class is only split in a block namespace")
        elif ns and file_scoped:
            src += f"namespace {ns.group(1)};\n\n{decl}\n{{\n" + "".join(body).rstrip("\n") + "\n}\n"
        elif ns:
            src += f"namespace {ns.group(1)}\n{{\n{indent}{decl}\n{indent}{{\n" + "".join(body).rstrip("\n") + f"\n{indent}}}\n}}\n"
        else:
            src += f"{decl}\n{{\n" + "".join(body).rstrip("\n") + "\n}\n"
        src = re.sub(r"\n{3,}", "\n\n", src)
        files[fn] = src
    # check: every original line comes back exactly once, in the main file or in a part's moved text (the class
    # declaration aside: it gains "partial")
    names = cls + ("|" + outer[3] if outer else "")
    def lines(t): return Counter(l.rstrip() for l in t.split("\n") if l.strip() and not re.search(r"\b(class|struct)\s+(" + names + r")\b", l))
    after = lines(main)
    for p, body, _ in parts: after += lines("".join(b for b in body if b is not None))
    before = lines(text)
    lost, extra = before - after, after - before
    sizes = ", ".join(f"{os.path.basename(f)}{' (+)' if f in appended else ''} {len(s.encode('utf-8')) / 1024:.1f} KB" for f, s in files.items())
    print(f"{cls}: {sizes}")
    if lost or extra:
        print("  !! line check failed:", "lost", list(lost.items())[:5], "extra", list(extra.items())[:5])
        return False
    if write:
        for fn, s in files.items():
            data = s.replace("\n", nl)
            io.open(fn, "w", encoding="utf-8-sig" if bom else "utf-8", newline="").write(data)
    return True


if __name__ == "__main__":
    if len(sys.argv) >= 3 and sys.argv[1] == "sections":
        for p in sys.argv[2:]: cmd_sections(p)
    elif len(sys.argv) == 4 and sys.argv[1] == "members":
        cmd_members(sys.argv[2], int(sys.argv[3]))
    elif len(sys.argv) >= 4 and sys.argv[1] == "split":
        ok = cmd_split(sys.argv[2], sys.argv[3], "--write" in sys.argv)
        sys.exit(0 if ok else 1)
    else:
        print(__doc__)
