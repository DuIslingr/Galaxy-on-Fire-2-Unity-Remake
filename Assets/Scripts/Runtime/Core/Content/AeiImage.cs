// AeiImage.cs
// Feature: docs/notes/player-assets.md "Formats in the player's copy": Galaxy on Fire 2's own image files (.aei, the ABYSS
// engine's "AEimage"), read from the player's copy of the game (Android OBB, iOS .ipa) into RGBA8 pixels. Plain C#, no
// Unity types: the conversion runs on every platform and is tested outside the Editor.
//
// Layout (Reference/tools/asset_conversion/aei.py, and the iOS 1.1.19 / Android 2.0.16 files, 2026-11-15):
//   "AEimage" [7], a byte, type [1], width, height, region count [u16 each], regions [x, y, w, h: u16 each], then
//   - types 0x01 / 0x03 / 0x81: width x height x 4 bytes RGBA8, rows top first (0x81: a cubemap strip, 6 faces stacked)
//   - every other type: a u32 byte count, then that many bytes of compressed data (level 0 first, then its mipmaps)
// Types (bit 1 = mipmaps follow; the decoders read level 0 only, Unity makes its own mipmaps):
//   0x40 / 0x42 (and 0x14 / 0x16 / 0x17, aei.py's): ETC1 (Android)
//   0x10 / 0x12: PVRTC 4 bpp (iOS), 0x0d: PVRTC 2 bpp (iOS)
//   0x24: 8 bpp in 16-byte blocks (iOS' cloak map only, which the remake doesn't use): not read

using System;
using System.Collections.Generic;

namespace GoF2Remake.Data
{
    public sealed class AeiImage
    {
        public struct Region { public int x, y, width, height; }

        public int Type;
        public int Width, Height;
        public readonly List<Region> Regions = new List<Region>();
        /// <summary>Level 0 as RGBA8, rows top first (as the original's files and the converted PNGs have them).</summary>
        public byte[] Rgba;

        /// <summary>Whether the type is a cubemap strip (six faces stacked).</summary>
        public bool IsCubemapStrip => Type == 0x81;
        public bool HasMipmaps => (Type & 0x02) != 0 && Type != 0x03 && Type != 0x81;
        public string Format => FormatOf(Type);

        public static string FormatOf(int type)
        {
            switch (type)
            {
                case 0x01: case 0x03: return "RGBA8";
                case 0x81: return "RGBA8 cubemap strip";
                case 0x14: case 0x16: case 0x17: case 0x40: case 0x42: return "ETC1";
                case 0x10: case 0x12: return "PVRTC 4bpp";
                case 0x0d: return "PVRTC 2bpp";
                default: return $"unknown (0x{type:x2})";
            }
        }

        /// <summary>Whether Read can decode this type.</summary>
        public static bool CanRead(int type) => !FormatOf(type).StartsWith("unknown");

        /// <summary>The header alone (type, size, regions), without decoding the pixels.</summary>
        public static AeiImage ReadHeader(byte[] file) => Parse(file, false);

        /// <summary>The image with its level 0 decoded. Throws FormatException on a file that isn't an AEimage or a type
        /// it can't decode.</summary>
        public static AeiImage Read(byte[] file) => Parse(file, true);

        static AeiImage Parse(byte[] b, bool pixels)
        {
            if (b == null || b.Length < 15 || b[0] != (byte)'A' || b[1] != (byte)'E' || b[2] != (byte)'i' || b[3] != (byte)'m'
                || b[4] != (byte)'a' || b[5] != (byte)'g' || b[6] != (byte)'e')
                throw new FormatException("not an AEimage file");
            var img = new AeiImage { Type = b[8], Width = U16(b, 9), Height = U16(b, 11) };
            int n = U16(b, 13), o = 15;
            if (o + 8 * n > b.Length) throw new FormatException("regions run past the end");
            for (int i = 0; i < n; i++, o += 8)
                img.Regions.Add(new Region { x = U16(b, o), y = U16(b, o + 2), width = U16(b, o + 4), height = U16(b, o + 6) });
            if (!pixels) return img;
            int w = img.Width, h = img.Height;
            switch (img.Type)
            {
                case 0x01: case 0x03: case 0x81:
                {
                    long size = (long)w * h * 4;
                    if (o + size > b.Length) throw new FormatException("pixels run past the end");
                    img.Rgba = new byte[size];
                    Buffer.BlockCopy(b, o, img.Rgba, 0, (int)size);
                    return img;
                }
            }
            if (!CanRead(img.Type)) throw new FormatException($"AEimage type 0x{img.Type:x2} isn't supported");
            if (o + 4 > b.Length) throw new FormatException("no data size");
            int count = (int)U32(b, o); o += 4;
            if (count < 0 || o + count > b.Length) throw new FormatException("data runs past the end");
            var data = new ReadOnlySpan<byte>(b, o, count);
            switch (img.Type)
            {
                case 0x10: case 0x12: img.Rgba = Pvrtc.Decode(data, w, h, false); break;
                case 0x0d: img.Rgba = Pvrtc.Decode(data, w, h, true); break;
                default: img.Rgba = Etc1.Decode(data, w, h); break;
            }
            return img;
        }

        /// <summary>A region's pixels (rows top first) cut out of Rgba.</summary>
        public byte[] Crop(Region r)
        {
            var o = new byte[r.width * r.height * 4];
            for (int y = 0; y < r.height; y++)
                Buffer.BlockCopy(Rgba, ((r.y + y) * Width + r.x) * 4, o, y * r.width * 4, r.width * 4);
            return o;
        }

        static int U16(byte[] b, int o) => b[o] | (b[o + 1] << 8);
        static uint U32(byte[] b, int o) => (uint)(b[o] | (b[o + 1] << 8) | (b[o + 2] << 16) | (b[o + 3] << 24));
    }

    /// <summary>ETC1 (Ericsson Texture Compression 1, OES_compressed_ETC1_RGB8_texture): 4x4 blocks of 8 bytes, big-endian,
    /// row-major; individual or differential base colours per 2x4 / 4x2 half, an 8-row intensity table.</summary>
#if UNITY_5_3_OR_NEWER
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]   // (only constant tables: nothing to reset)
#endif
    public static class Etc1
    {
        static readonly int[,] Table =
        {
            { 2, 8, -2, -8 }, { 5, 17, -5, -17 }, { 9, 29, -9, -29 }, { 13, 42, -13, -42 },
            { 18, 60, -18, -60 }, { 24, 80, -24, -80 }, { 33, 106, -33, -106 }, { 47, 183, -47, -183 },
        };

        public static byte[] Decode(ReadOnlySpan<byte> data, int width, int height)
        {
            var o = new byte[width * height * 4];
            int bw = (width + 3) / 4, bh = (height + 3) / 4;
            if (data.Length < bw * bh * 8) throw new FormatException("ETC1 data too short");
            for (int by = 0; by < bh; by++)
            for (int bx = 0; bx < bw; bx++)
            {
                int p = (by * bw + bx) * 8;
                uint hi = (uint)(data[p] << 24 | data[p + 1] << 16 | data[p + 2] << 8 | data[p + 3]);
                uint lo = (uint)(data[p + 4] << 24 | data[p + 5] << 16 | data[p + 6] << 8 | data[p + 7]);
                bool diff = (hi & 2) != 0, flip = (hi & 1) != 0;
                int r1, g1, b1, r2, g2, b2;
                if (diff)
                {
                    int r = (int)(hi >> 27) & 31, g = (int)(hi >> 19) & 31, b = (int)(hi >> 11) & 31;
                    int dr = Signed3((int)(hi >> 24) & 7), dg = Signed3((int)(hi >> 16) & 7), db = Signed3((int)(hi >> 8) & 7);
                    r1 = Ext5(r); g1 = Ext5(g); b1 = Ext5(b);
                    r2 = Ext5((r + dr) & 31); g2 = Ext5((g + dg) & 31); b2 = Ext5((b + db) & 31);
                }
                else
                {
                    r1 = Ext4((int)(hi >> 28) & 15); r2 = Ext4((int)(hi >> 24) & 15);
                    g1 = Ext4((int)(hi >> 20) & 15); g2 = Ext4((int)(hi >> 16) & 15);
                    b1 = Ext4((int)(hi >> 12) & 15); b2 = Ext4((int)(hi >> 8) & 15);
                }
                int t1 = (int)(hi >> 5) & 7, t2 = (int)(hi >> 2) & 7;
                for (int x = 0; x < 4; x++)
                for (int y = 0; y < 4; y++)
                {
                    int px = bx * 4 + x, py = by * 4 + y;
                    if (px >= width || py >= height) continue;
                    int i = x * 4 + y;
                    int idx = (int)((lo >> (i + 15)) & 2) | (int)((lo >> i) & 1);
                    bool second = flip ? y >= 2 : x >= 2;
                    int m = Table[second ? t2 : t1, idx];
                    int q = (py * width + px) * 4;
                    o[q] = Clamp((second ? r2 : r1) + m); o[q + 1] = Clamp((second ? g2 : g1) + m);
                    o[q + 2] = Clamp((second ? b2 : b1) + m); o[q + 3] = 255;
                }
            }
            return o;
        }

        static int Signed3(int v) => v >= 4 ? v - 8 : v;
        static int Ext4(int v) => v << 4 | v;
        static int Ext5(int v) => v << 3 | v >> 2;
        static byte Clamp(int v) => (byte)(v < 0 ? 0 : v > 255 ? 255 : v);
    }

    /// <summary>PVRTC 4 bpp / 2 bpp (PowerVR, iOS): 64-bit words (modulation, then colours A and B) of 4x4 / 8x4 pixels in
    /// Morton order, each pixel blended between two bilinearly upscaled low-resolution images; after the PowerVR SDK's
    /// reference decompressor (PVRTDecompress).</summary>
#if UNITY_5_3_OR_NEWER
    [Unity.Scripting.LifecycleManagement.NoAutoStaticsCleanup]   // (only constant tables: nothing to reset)
#endif
    public static class Pvrtc
    {
        struct Word { public uint mod, col; }

        public static byte[] Decode(ReadOnlySpan<byte> data, int width, int height, bool twoBpp)
        {
            int ww = twoBpp ? 8 : 4, wh = 4;
            int xw = Math.Max(width / ww, 2), yw = Math.Max(height / wh, 2);
            int pw = xw * ww, ph = yw * wh;   // the padded size the words cover
            if (data.Length < xw * yw * 8) throw new FormatException("PVRTC data too short");
            var words = new uint[xw * yw * 2];
            for (int i = 0; i < words.Length; i++)
                words[i] = (uint)(data[i * 4] | data[i * 4 + 1] << 8 | data[i * 4 + 2] << 16 | data[i * 4 + 3] << 24);
            var full = new byte[pw * ph * 4];
            var modV = new int[16, 8]; var modM = new int[16, 8];
            var ua = new int[32 * 4]; var ub = new int[32 * 4];
            for (int wy = -1; wy < yw - 1; wy++)
            for (int wx = -1; wx < xw - 1; wx++)
            {
                int px = Wrap(xw, wx), py = Wrap(yw, wy), qx = Wrap(xw, wx + 1), ry = Wrap(yw, wy + 1);
                Word P = Get(words, xw, yw, px, py), Q = Get(words, xw, yw, qx, py),
                     R = Get(words, xw, yw, px, ry), S = Get(words, xw, yw, qx, ry);
                Unpack(P, 0, 0, modV, modM, twoBpp); Unpack(Q, ww, 0, modV, modM, twoBpp);
                Unpack(R, 0, wh, modV, modM, twoBpp); Unpack(S, ww, wh, modV, modM, twoBpp);
                Interpolate(ColorA(P.col), ColorA(Q.col), ColorA(R.col), ColorA(S.col), ua, twoBpp);
                Interpolate(ColorB(P.col), ColorB(Q.col), ColorB(R.col), ColorB(S.col), ub, twoBpp);
                for (int y = 0; y < wh; y++)
                for (int x = 0; x < ww; x++)
                {
                    int mod = Modulation(modV, modM, x + ww / 2, y + wh / 2, twoBpp);
                    bool punch = false;
                    if (mod > 10) { punch = true; mod -= 10; }
                    int k = (y * ww + x) * 4;
                    // the pixel's place: P's lower right quarter, Q's lower left, R's upper right, S's upper left
                    int ox, oy;
                    if (y < wh / 2) { oy = py * wh + y + wh / 2; ox = x < ww / 2 ? px * ww + x + ww / 2 : qx * ww + x - ww / 2; }
                    else { oy = ry * wh + y - wh / 2; ox = x < ww / 2 ? px * ww + x + ww / 2 : qx * ww + x - ww / 2; }
                    int q = (oy * pw + ox) * 4;
                    for (int c = 0; c < 4; c++)
                        full[q + c] = (byte)Math.Clamp((ua[k + c] * (8 - mod) + ub[k + c] * mod) / 8, 0, 255);
                    if (punch) full[q + 3] = 0;
                }
            }
            if (pw == width && ph == height) return full;
            var o = new byte[width * height * 4];
            for (int y = 0; y < height; y++) Buffer.BlockCopy(full, y * pw * 4, o, y * width * 4, width * 4);
            return o;
        }

        static int Wrap(int n, int i) => ((i % n) + n) % n;

        static Word Get(uint[] words, int xw, int yw, int x, int y)
        {
            int i = (int)Twiddle(xw, yw, x, y) * 2;
            return new Word { mod = words[i], col = words[i + 1] };
        }

        /// <summary>Morton order of word (x, y): y in the even bits, x in the odd ones over the smaller dimension, the
        /// larger dimension's remaining bits above (x in the even bits put each word at its transposed place: the iOS
        /// files decoded as their Android counterparts mirrored about the diagonal, 2026-11-15).</summary>
        static uint Twiddle(int xw, int yw, int x, int y)
        {
            int min = Math.Min(xw, yw);
            uint t = 0; int src = 1, dst = 1, shift = 0;
            while (src < min)
            {
                if ((y & src) != 0) t |= (uint)dst;
                if ((x & src) != 0) t |= (uint)(dst << 1);
                src <<= 1; dst <<= 2; shift++;
            }
            int max = (xw >= yw ? x : y) >> shift;
            return t | (uint)(max << (2 * shift));
        }

        // colours: 5-bit RGB (4-bit alpha, 15 = opaque); A from bits 0..15, B from 16..31
        static (int r, int g, int b, int a) ColorA(uint c)
        {
            if ((c & 0x8000) != 0)
                return ((int)((c & 0x7c00) >> 10), (int)((c & 0x3e0) >> 5), (int)((c & 0x1e) | ((c & 0x1e) >> 4)), 0xf);
            return ((int)(((c & 0xf00) >> 7) | ((c & 0xf00) >> 11)), (int)(((c & 0xf0) >> 3) | ((c & 0xf0) >> 7)),
                    (int)(((c & 0xe) << 1) | ((c & 0xe) >> 2)), (int)((c & 0x7000) >> 11));
        }

        static (int r, int g, int b, int a) ColorB(uint c)
        {
            if ((c & 0x80000000) != 0)
                return ((int)((c & 0x7c000000) >> 26), (int)((c & 0x3e00000) >> 21), (int)((c & 0x1f0000) >> 16), 0xf);
            return ((int)(((c & 0xf000000) >> 23) | ((c & 0xf000000) >> 27)), (int)(((c & 0xf00000) >> 19) | ((c & 0xf00000) >> 23)),
                    (int)(((c & 0xf0000) >> 15) | ((c & 0xf0000) >> 19)), (int)((c & 0x70000000) >> 27));
        }

        /// <summary>The four words' colours bilinearly upscaled over the word grid between their centres, as 8-bit channels.</summary>
        static void Interpolate((int r, int g, int b, int a) P, (int r, int g, int b, int a) Q, (int r, int g, int b, int a) R,
                                (int r, int g, int b, int a) S, int[] o, bool twoBpp)
        {
            int ww = twoBpp ? 8 : 4, wh = 4;
            int[] hp = { P.r * ww, P.g * ww, P.b * ww, P.a * ww }, hr = { R.r * ww, R.g * ww, R.b * ww, R.a * ww };
            int[] qp = { Q.r - P.r, Q.g - P.g, Q.b - P.b, Q.a - P.a }, sr = { S.r - R.r, S.g - R.g, S.b - R.b, S.a - R.a };
            var res = new int[4]; var dy = new int[4];
            for (int x = 0; x < ww; x++)
            {
                for (int c = 0; c < 4; c++) { res[c] = 4 * hp[c]; dy[c] = hr[c] - hp[c]; }
                for (int y = 0; y < wh; y++)
                {
                    int k = (y * ww + x) * 4;
                    if (twoBpp)
                    {
                        for (int c = 0; c < 3; c++) o[k + c] = (res[c] >> 7) + (res[c] >> 2);
                        o[k + 3] = (res[3] >> 5) + (res[3] >> 1);
                    }
                    else
                    {
                        for (int c = 0; c < 3; c++) o[k + c] = (res[c] >> 6) + (res[c] >> 1);
                        o[k + 3] = (res[3] >> 4) + res[3];
                    }
                    for (int c = 0; c < 4; c++) res[c] += dy[c];
                }
                for (int c = 0; c < 4; c++) { hp[c] += qp[c]; hr[c] += sr[c]; }
            }
        }

        /// <summary>A word's modulation values into the 2x2-word grid at (ox, oy): 4 bpp, 0..8 weights (+10: punch-through
        /// alpha); 2 bpp, the stored 2-bit values and the word's mode (0 one bit a pixel, 1 H+V, 2 H, 3 V interpolated).</summary>
        static void Unpack(Word w, int ox, int oy, int[,] v, int[,] m, bool twoBpp)
        {
            uint mode = w.col & 1, bits = w.mod;
            if (twoBpp)
            {
                if (mode != 0)
                {
                    if ((bits & 1) != 0)
                    {
                        mode = (bits & (1u << 20)) != 0 ? 3u : 2u;
                        if ((bits & (1u << 21)) != 0) bits |= 1u << 20; else bits &= ~(1u << 20);
                    }
                    if ((bits & 2) != 0) bits |= 1; else bits &= ~1u;
                    for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 8; x++)
                    {
                        m[x + ox, y + oy] = (int)mode;
                        if (((x ^ y) & 1) == 0) { v[x + ox, y + oy] = (int)(bits & 3); bits >>= 2; }
                    }
                }
                else
                {
                    for (int y = 0; y < 4; y++)
                    for (int x = 0; x < 8; x++)
                    {
                        m[x + ox, y + oy] = 0;
                        v[x + ox, y + oy] = (bits & 1) != 0 ? 3 : 0;
                        bits >>= 1;
                    }
                }
                return;
            }
            for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
            {
                int b = (int)(bits & 3); bits >>= 2;
                if (mode != 0) b = b == 0 ? 0 : b == 1 ? 4 : b == 2 ? 14 : 8;   // punch-through: 2 = half weight, alpha 0
                else { b *= 3; if (b > 3) b -= 1; }                               // 0, 3, 5, 8
                v[x + ox, y + oy] = b;
            }
        }

        static readonly int[] Rep = { 0, 3, 5, 8 };

        static int Modulation(int[,] v, int[,] m, int x, int y, bool twoBpp)
        {
            if (!twoBpp) return v[x, y];
            if (m[x, y] == 0 || ((x ^ y) & 1) == 0) return Rep[v[x, y]];
            if (m[x, y] == 1) return (Rep[v[x, y - 1]] + Rep[v[x, y + 1]] + Rep[v[x - 1, y]] + Rep[v[x + 1, y]] + 2) / 4;
            if (m[x, y] == 2) return (Rep[v[x - 1, y]] + Rep[v[x + 1, y]] + 1) / 2;
            return (Rep[v[x, y - 1]] + Rep[v[x, y + 1]] + 1) / 2;
        }
    }
}
