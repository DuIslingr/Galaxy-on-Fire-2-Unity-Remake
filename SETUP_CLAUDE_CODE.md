# Moving the GoF2 remake to Claude Code

Everything Claude Code needs is already in this folder:

- `CLAUDE.md`: project briefing. Claude Code reads it automatically at the start of every session.
- `Reference/`: the decompiled game and conversion tools.
- `.gitignore` and `.gitattributes`: ready for git with Git LFS.

The steps below take about 15 minutes.

## 1. Install the tools (once)

Open **PowerShell** (not as administrator):

```powershell
# Git for Windows (includes Git LFS). Claude Code uses its Bash shell.
winget install --id Git.Git -e

# Claude Code
irm https://claude.ai/install.ps1 | iex

# Unity CLI (lets Claude Code drive your open Unity Editor)
$env:UNITY_CLI_CHANNEL='beta'; irm https://public-cdn.cloud.unity3d.com/hub/prod/cli/install.ps1 | iex
```

**Close PowerShell and open a new window**, then check that all three work:

```powershell
git --version
claude --version
unity --version
```

## 2. Connect Claude Code to Unity (once)

1. Open the project in Unity and wait until it has finished importing.
2. In PowerShell, run:

```powershell
cd "C:\Projects\Unity\Galaxy on Fire 2"
unity status                                   # should list this project with state "ready"
unity mcp configure claude-code --project-path "C:\Projects\Unity\Galaxy on Fire 2"
unity skill install claude-code --local        # adds the Unity CLI + Pipeline skills to this project
```

`unity status` finds the Editor through the `com.unity.pipeline` package, which your project already has. If it shows nothing, check the Unity Console for compile errors first. Unity's Safe Mode blocks the connection.

## 3. Start Claude Code

```powershell
cd "C:\Projects\Unity\Galaxy on Fire 2"
claude
```

Sign in in the browser when asked. Then paste this as your first message:

> Read CLAUDE.md and Reference/README.md. Then:
>
> 1. Check that you can reach the Unity Editor (`unity status`) and read the Console. Fix any errors you find.
> 2. Set up git: initialise the repo on `main`, run `git lfs install`, check that `.gitignore` keeps Library/, Temp/ and GoF2_ImportParts/ out, and make the first commit. Don't add a remote yet.
> 3. Enter Play mode in the flight test scene and confirm the Betty flies forward with keyboard input.
>
> Report back before starting on combat (roadmap item 1 in CLAUDE.md).

## 4. Optional: back up to a private remote

If you want an online backup, create a **private** repository (GitHub, GitLab, or Unity Version Control) and ask Claude Code to add it as a remote and push. The repo is about 2 GB with LFS. Never make it public: it contains Deep Silver's assets and the decompiled code.

## 5. Tidy up

- Delete the `GoF2_ImportParts` folder if you kept it after installing. It's 1.9 GB and no longer needed.- Everything important from the Cowork session is now in this project. The heavy tools used there (Ghidra, Blender, the ARM emulator) aren't needed day to day. If you ever need to re-run an asset conversion, the scripts are in `Reference/tools/asset_conversion/`.
