// StepSummaries.cs
// The Debug mission list's texts (remake-only): per story step a short title (the level's name where the step has an
// in-space level) and a one-line summary, from Resources/GoF2Data/step_summaries.json, which
// Reference/tools/campaign/build_step_summaries.py writes from the research notes (campaign_flow.md's step table and
// the campaign_levels_a/b/c.md headings).

using System;
using System.Collections.Generic;
using UnityEngine;

namespace GoF2Remake.Data
{
    public static class StepSummaries
    {
        [Serializable]
        public class Entry
        {
            public int index;
            public string title;
            public string summary;
        }

        [Serializable]
        class File
        {
            public List<Entry> steps;
        }

        static Dictionary<int, Entry> byIndex;

        public static Entry Get(int index)
        {
            if (byIndex == null)
            {
                byIndex = new Dictionary<int, Entry>();
                var asset = Resources.Load<TextAsset>("GoF2Data/step_summaries");
                var file = asset != null ? JsonUtility.FromJson<File>(asset.text) : null;
                if (file?.steps != null) foreach (var e in file.steps) byIndex[e.index] = e;
            }
            return byIndex.TryGetValue(index, out var entry) ? entry : null;
        }
    }
}
