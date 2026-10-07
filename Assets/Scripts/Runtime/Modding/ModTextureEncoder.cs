// ModTextureEncoder.cs
// Remake mods: compresses a mod's texture to DXT1 (BC1, opaque) or DXT5 (BC3, with alpha) with its mipmaps in a Burst job
// on Unity's worker threads, so a ship's 2048 px textures don't stall the main thread (Texture2D.Compress takes ~110-145 ms
// each there, and the main menu stuttered while the mods loaded) and make no garbage (a managed encoder's ~25 MB per
// texture brought a 2 s garbage collection). The encoder is the classic real-time one (J.M.P. van Waveren, "Real-Time DXT
// Compression", 2006): per 4 x 4 block the colour bounding box inset by a sixteenth, the end points in 565, each pixel the
// nearest of the four palette colours; DXT5's alpha the same with its eight levels. Mipmaps by 2 x 2 box filtering, made
// level by level in two scratch buffers. Unity's raw row order (bottom row first) in and out, so LoadRawTextureData takes
// the result. ModMaterials.PreloadTexture uses it where the GPU reads DXT (desktop); elsewhere Texture2D.Compress stays.

using System;
using Unity.Burst;
using Unity.Collections;
using Unity.Jobs;
using UnityEngine;

namespace GoF2Remake.Modding
{
    public static class ModTextureEncoder
    {
        /// <summary>A running encode: Done once the job finished; then Take makes the texture (main thread).</summary>
        public sealed class Work
        {
            internal JobHandle handle;
            internal NativeArray<byte> source, scratchA, scratchB, output;
            internal NativeArray<int> result;   // [0] the bytes used, [1] 1 = DXT5, [2] the mip count
            internal int width, height;
            internal bool linear;

            public bool Done => handle.IsCompleted;

            /// <summary>A copy of the compressed data with its mipmaps, as Take uploads it (for ModTextureCache; before Take).</summary>
            public byte[] Raw()
            {
                handle.Complete();
                return output.GetSubArray(0, result[0]).ToArray();
            }

            /// <summary>The compressed texture (frees the buffers).</summary>
            public Texture2D Take(string name)
            {
                handle.Complete();
                bool alpha = result[1] == 1;
                var t = new Texture2D(width, height, alpha ? TextureFormat.DXT5 : TextureFormat.DXT1, result[2], linear) { name = name };
                t.LoadRawTextureData(output.GetSubArray(0, result[0]));
                t.Apply(false, true);
                Dispose();
                return t;
            }

            public void Dispose()
            {
                handle.Complete();
                if (source.IsCreated) source.Dispose();
                if (scratchA.IsCreated) scratchA.Dispose();
                if (scratchB.IsCreated) scratchB.Dispose();
                if (output.IsCreated) output.Dispose();
                if (result.IsCreated) result.Dispose();
            }
        }

        /// <summary>Starts compressing the decoded texture's top level (its width and height multiples of 4, RGBA32 / ARGB32 /
        /// RGB24); null for another format. The texture can go once this returns (its pixels are copied).</summary>
        public static Work Start(Texture2D t, bool linear)
        {
            int format = t.format == TextureFormat.RGBA32 ? 0 : t.format == TextureFormat.ARGB32 ? 1 : t.format == TextureFormat.RGB24 ? 2 : -1;
            int w = t.width, h = t.height;
            if (format < 0 || w % 4 != 0 || h % 4 != 0) return null;
            var pixels = t.GetPixelData<byte>(0);
            int bytes = w * h * (format == 2 ? 3 : 4);
            if (pixels.Length < bytes) return null;
            int mips = 1, blocks = 0;
            for (int lw = w, lh = h; ; lw = Math.Max(1, lw / 2), lh = Math.Max(1, lh / 2))
            {
                blocks += Math.Max(1, (lw + 3) / 4) * Math.Max(1, (lh + 3) / 4);
                if (lw == 1 && lh == 1) break;
                mips++;
            }
            int scratch = Math.Max(4, (w / 2) * (h / 2) * 4);
            var work = new Work
            {
                width = w, height = h, linear = linear,
                source = new NativeArray<byte>(pixels.GetSubArray(0, bytes), Allocator.Persistent),
                scratchA = new NativeArray<byte>(scratch, Allocator.Persistent, NativeArrayOptions.UninitializedMemory),
                scratchB = new NativeArray<byte>(scratch, Allocator.Persistent, NativeArrayOptions.UninitializedMemory),
                output = new NativeArray<byte>(blocks * 16, Allocator.Persistent, NativeArrayOptions.UninitializedMemory),
                result = new NativeArray<int>(3, Allocator.Persistent),
            };
            work.handle = new EncodeJob
            {
                source = work.source, format = format, width = w, height = h, mips = mips,
                scratchA = work.scratchA, scratchB = work.scratchB, output = work.output, result = work.result,
            }.Schedule();
            JobHandle.ScheduleBatchedJobs();
            return work;
        }

        [BurstCompile]
        struct EncodeJob : IJob
        {
            [ReadOnly] public NativeArray<byte> source;
            public int format, width, height, mips;   // format: 0 RGBA, 1 ARGB, 2 RGB
            public NativeArray<byte> scratchA, scratchB, output;
            public NativeArray<int> result;

            public void Execute()
            {
                // DXT5 when some pixel isn't opaque.
                bool alpha = false;
                if (format != 2)
                {
                    int stride = 4, offset = format == 0 ? 3 : 0;
                    for (int i = offset; i < source.Length; i += stride) if (source[i] < 250) { alpha = true; break; }
                }
                var block = new NativeArray<byte>(64, Allocator.Temp);
                int o = 0, lw = width, lh = height;
                // Level 0 straight from the source (its own layout), the others RGBA in the scratch buffers.
                for (int level = 0; level < mips; level++)
                {
                    NativeArray<byte> px = level == 0 ? source : (level % 2 == 1 ? scratchA : scratchB);
                    int fmt = level == 0 ? format : 0;
                    int bw = Math.Max(1, (lw + 3) / 4), bh = Math.Max(1, (lh + 3) / 4);
                    for (int by = 0; by < bh; by++)
                        for (int bx = 0; bx < bw; bx++)
                        {
                            for (int y = 0; y < 4; y++)
                            {
                                int sy = Math.Min(by * 4 + y, lh - 1);
                                for (int x = 0; x < 4; x++)
                                {
                                    int sx = Math.Min(bx * 4 + x, lw - 1);
                                    Pixel(px, fmt, sy * lw + sx, out byte r, out byte g, out byte b, out byte a);
                                    int d = (y * 4 + x) * 4;
                                    block[d] = r; block[d + 1] = g; block[d + 2] = b; block[d + 3] = a;
                                }
                            }
                            if (alpha) { AlphaBlock(block, output, o); o += 8; }
                            ColorBlock(block, output, o);
                            o += 8;
                        }
                    if (level + 1 < mips)
                    {
                        // The next level from this one.
                        var dst = level % 2 == 0 ? scratchA : scratchB;
                        int nw = Math.Max(1, lw / 2), nh = Math.Max(1, lh / 2);
                        for (int y = 0; y < nh; y++)
                        {
                            int y0 = Math.Min(y * 2, lh - 1), y1 = Math.Min(y * 2 + 1, lh - 1);
                            for (int x = 0; x < nw; x++)
                            {
                                int x0 = Math.Min(x * 2, lw - 1), x1 = Math.Min(x * 2 + 1, lw - 1);
                                Pixel(px, fmt, y0 * lw + x0, out byte r0, out byte g0, out byte b0, out byte a0);
                                Pixel(px, fmt, y0 * lw + x1, out byte r1, out byte g1, out byte b1, out byte a1);
                                Pixel(px, fmt, y1 * lw + x0, out byte r2, out byte g2, out byte b2, out byte a2);
                                Pixel(px, fmt, y1 * lw + x1, out byte r3, out byte g3, out byte b3, out byte a3);
                                int d = (y * nw + x) * 4;
                                dst[d] = (byte)((r0 + r1 + r2 + r3 + 2) >> 2);
                                dst[d + 1] = (byte)((g0 + g1 + g2 + g3 + 2) >> 2);
                                dst[d + 2] = (byte)((b0 + b1 + b2 + b3 + 2) >> 2);
                                dst[d + 3] = (byte)((a0 + a1 + a2 + a3 + 2) >> 2);
                            }
                        }
                        lw = nw;
                        lh = nh;
                    }
                }
                block.Dispose();
                result[0] = o;
                result[1] = alpha ? 1 : 0;
                result[2] = mips;
            }

            static void Pixel(NativeArray<byte> px, int fmt, int i, out byte r, out byte g, out byte b, out byte a)
            {
                if (fmt == 0) { int s = i * 4; r = px[s]; g = px[s + 1]; b = px[s + 2]; a = px[s + 3]; }
                else if (fmt == 1) { int s = i * 4; a = px[s]; r = px[s + 1]; g = px[s + 2]; b = px[s + 3]; }
                else { int s = i * 3; r = px[s]; g = px[s + 1]; b = px[s + 2]; a = 255; }
            }

            static int To565(int r, int g, int b) => ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);

            static void From565(int c, out int r, out int g, out int b)
            {
                r = (c >> 11) & 31; g = (c >> 5) & 63; b = c & 31;
                r = (r << 3) | (r >> 2); g = (g << 2) | (g >> 4); b = (b << 3) | (b >> 2);
            }

            static int Sq(int v) => v * v;

            /// <summary>The colour block: 2 x 565 end points (c0 > c1: four colours, also how DXT5 reads it), 2 bits per pixel.</summary>
            static void ColorBlock(NativeArray<byte> p, NativeArray<byte> output, int o)
            {
                int minR = 255, minG = 255, minB = 255, maxR = 0, maxG = 0, maxB = 0;
                for (int i = 0; i < 64; i += 4)
                {
                    int r = p[i], g = p[i + 1], b = p[i + 2];
                    minR = Math.Min(minR, r); maxR = Math.Max(maxR, r);
                    minG = Math.Min(minG, g); maxG = Math.Max(maxG, g);
                    minB = Math.Min(minB, b); maxB = Math.Max(maxB, b);
                }
                // The box inset by a sixteenth: the palette's ends a little inside the extremes (less error overall).
                int ir = (maxR - minR) >> 4, ig = (maxG - minG) >> 4, ib = (maxB - minB) >> 4;
                minR = Math.Min(255, minR + ir); minG = Math.Min(255, minG + ig); minB = Math.Min(255, minB + ib);
                maxR = Math.Max(0, maxR - ir); maxG = Math.Max(0, maxG - ig); maxB = Math.Max(0, maxB - ib);
                int c0 = To565(maxR, maxG, maxB), c1 = To565(minR, minG, minB);
                uint indices = 0;
                if (c0 != c1)
                {
                    if (c0 < c1) { int t = c0; c0 = c1; c1 = t; }
                    From565(c0, out int r0, out int g0, out int b0);
                    From565(c1, out int r1, out int g1, out int b1);
                    int r2 = (2 * r0 + r1) / 3, g2 = (2 * g0 + g1) / 3, b2 = (2 * b0 + b1) / 3;
                    int r3 = (r0 + 2 * r1) / 3, g3 = (g0 + 2 * g1) / 3, b3 = (b0 + 2 * b1) / 3;
                    for (int i = 0; i < 16; i++)
                    {
                        int r = p[i * 4], g = p[i * 4 + 1], b = p[i * 4 + 2];
                        int d0 = Sq(r - r0) + Sq(g - g0) + Sq(b - b0);
                        int d1 = Sq(r - r1) + Sq(g - g1) + Sq(b - b1);
                        int d2 = Sq(r - r2) + Sq(g - g2) + Sq(b - b2);
                        int d3 = Sq(r - r3) + Sq(g - g3) + Sq(b - b3);
                        uint best = 0; int bd = d0;
                        if (d1 < bd) { bd = d1; best = 1; }
                        if (d2 < bd) { bd = d2; best = 2; }
                        if (d3 < bd) best = 3;
                        indices |= best << (i * 2);
                    }
                }
                output[o] = (byte)c0; output[o + 1] = (byte)(c0 >> 8);
                output[o + 2] = (byte)c1; output[o + 3] = (byte)(c1 >> 8);
                output[o + 4] = (byte)indices; output[o + 5] = (byte)(indices >> 8);
                output[o + 6] = (byte)(indices >> 16); output[o + 7] = (byte)(indices >> 24);
            }

            /// <summary>DXT5's alpha block: two end points (a0 > a1: eight levels), 3 bits per pixel.</summary>
            static void AlphaBlock(NativeArray<byte> p, NativeArray<byte> output, int o)
            {
                int min = 255, max = 0;
                for (int i = 3; i < 64; i += 4) { int a = p[i]; min = Math.Min(min, a); max = Math.Max(max, a); }
                output[o] = (byte)max;
                output[o + 1] = (byte)min;
                ulong bits = 0;
                if (max != min)
                    for (int i = 0; i < 16; i++)
                    {
                        int a = p[i * 4 + 3], best = 0, bd = int.MaxValue;
                        for (int k = 0; k < 8; k++)
                        {
                            int level = k == 0 ? max : k == 1 ? min : ((8 - k) * max + (k - 1) * min) / 7;
                            int d = Math.Abs(a - level);
                            if (d < bd) { bd = d; best = k; }
                        }
                        bits |= (ulong)best << (i * 3);
                    }
                for (int k = 0; k < 6; k++) output[o + 2 + k] = (byte)(bits >> (k * 8));
            }
        }
    }
}
