// Class: Layout
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Layout::Layout  @0x000e2a00  (8140 bytes)
/* Layout::Layout() */

void __thiscall Layout::Layout(Layout *this)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  char cVar9;
  byte bVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  char cVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float *pfVar17;
  undefined4 *puVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  uint uVar24;
  byte bVar25;
  bool bVar26;
  bool bVar27;
  uint in_fpscr;
  float fVar28;
  float fVar29;
  undefined4 uVar30;
  undefined4 uVar32;
  undefined1 auVar31 [16];
  ulonglong uVar33;
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  
  cVar9 = Globals::iPadHD;
  if (Globals::iPadHD == '\0') {
    if (Globals::n9 == 0) {
      fVar28 = 15.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 30.0;
      }
    }
    else {
      fVar28 = 22.5;
    }
    *(int *)(this + 4) = (int)fVar28;
    if (Globals::n9 == 0) {
      fVar28 = 30.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 60.0;
      }
    }
    else {
      fVar28 = 45.0;
    }
    *(int *)(this + 8) = (int)fVar28;
    if (Globals::n9 == 0) {
      uVar11 = 0x1d;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x3a;
      }
      *(undefined4 *)(this + 0xc) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0xc) = 0x33;
    }
    if (Globals::n9 == 0) {
      uVar11 = 0x25;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x4a;
      }
      *(undefined4 *)(this + 0x10) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x10) = 0x3a;
    }
    if (Globals::n9 == 0) {
      fVar28 = 22.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 50.0;
      }
    }
    else {
      fVar28 = 37.0;
    }
    *(int *)(this + 0x14) = (int)fVar28;
    if (Globals::n9 == 0) {
      uVar11 = 9;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xe;
      }
      *(undefined4 *)(this + 0x18) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x18) = 0xb;
    }
    if (Globals::n9 == 0) {
      fVar28 = 20.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 40.0;
      }
    }
    else {
      fVar28 = 30.0;
    }
    fVar29 = 7.5;
    *(int *)(this + 0x1c) = (int)fVar28;
    fVar28 = 7.5;
    if ((Globals::n9 == 0) && (fVar28 = 5.0, Globals::retinaDisplay != 0)) {
      fVar28 = 10.0;
    }
    *(int *)(this + 0x20) = (int)fVar28;
    if ((Globals::n9 == 0) && (fVar29 = 5.0, Globals::retinaDisplay != 0)) {
      fVar29 = 10.0;
    }
    *(int *)(this + 0x24) = (int)fVar29;
    if (Globals::n9 == 0) {
      fVar28 = 5.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 10.0;
      }
    }
    else {
      fVar28 = 9.0;
    }
    *(int *)(this + 0x28) = (int)fVar28;
    if (Globals::n9 == 0) {
      uVar11 = 3;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 6;
      }
      *(undefined4 *)(this + 0x2c) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x2c) = 6;
    }
    if (Globals::n9 == 0) {
      uVar11 = 0x1e;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x3c;
      }
      *(undefined4 *)(this + 0x30) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x30) = 0x33;
    }
    if (Globals::n9 == 0) {
      uVar11 = 6;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xc;
      }
      *(undefined4 *)(this + 0x34) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x34) = 4;
    }
    if (Globals::n9 == 0) {
      fVar28 = 7.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 14.0;
      }
    }
    else {
      fVar28 = 12.599999;
    }
    *(int *)(this + 0x38) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e38cc;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e38d0;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 106.2;
    }
    *(int *)(this + 0x3c) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e38dc;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e38e0;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 180.0;
    }
    *(int *)(this + 0x40) = (int)fVar28;
    if (Globals::n9 == 0) {
      fVar28 = 5.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 10.0;
      }
    }
    else {
      fVar28 = 9.0;
    }
    *(int *)(this + 0x44) = (int)fVar28;
    if (Globals::n9 == 0) {
      uVar11 = 0xb;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x16;
      }
      *(undefined4 *)(this + 0x48) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x48) = 0x10;
    }
    if (Globals::n9 == 0) {
      uVar11 = 5;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 10;
      }
      *(undefined4 *)(this + 0x4c) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x4c) = 10;
    }
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3904;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3908;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 160.2;
    }
    *(int *)(this + 0x50) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3914;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3918;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 520.5;
    }
    *(int *)(this + 0x54) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3924;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3928;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 364.5;
    }
    *(int *)(this + 0x58) = (int)fVar28;
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0x5a;
        goto LAB_000e2f72;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x3c;
        goto LAB_000e2f72;
      }
      uVar11 = 0x1e;
      if (Globals::iPad != '\0') {
        uVar11 = 0x2d;
      }
      *(undefined4 *)(this + 0x5c) = uVar11;
    }
    else {
      uVar11 = 0x33;
LAB_000e2f72:
      *(undefined4 *)(this + 0x5c) = uVar11;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0x80;
        goto LAB_000e2fa6;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x58;
        goto LAB_000e2fa6;
      }
      uVar11 = 0x2c;
      if (Globals::iPad != '\0') {
        uVar11 = 0x40;
      }
      *(undefined4 *)(this + 0x60) = uVar11;
    }
    else {
      uVar11 = 0x4f;
LAB_000e2fa6:
      *(undefined4 *)(this + 0x60) = uVar11;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0xa0;
        goto LAB_000e2fda;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x78;
        goto LAB_000e2fda;
      }
      uVar11 = 0x3c;
      if (Globals::iPad != '\0') {
        uVar11 = 0x50;
      }
      *(undefined4 *)(this + 100) = uVar11;
    }
    else {
      uVar11 = 0x6c;
LAB_000e2fda:
      *(undefined4 *)(this + 100) = uVar11;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0x326;
        goto LAB_000e3014;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x25e;
        goto LAB_000e3014;
      }
      uVar11 = 0x12f;
      if (Globals::iPad != '\0') {
        uVar11 = 0x193;
      }
      *(undefined4 *)(this + 0x68) = uVar11;
    }
    else {
      uVar11 = 0x221;
LAB_000e3014:
      *(undefined4 *)(this + 0x68) = uVar11;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0x110;
        goto LAB_000e304c;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x106;
        goto LAB_000e304c;
      }
      uVar11 = 0x83;
      if (Globals::iPad != '\0') {
        uVar11 = 0x88;
      }
      *(undefined4 *)(this + 0x6c) = uVar11;
    }
    else {
      uVar11 = 0xaa;
LAB_000e304c:
      *(undefined4 *)(this + 0x6c) = uVar11;
    }
    if (Globals::n9 == 0) {
      uVar11 = 0xfffffffe;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xfffffffc;
      }
      *(undefined4 *)(this + 0x2c0) = uVar11;
    }
    else {
      *(undefined4 *)(this + 0x2c0) = 0xfffffffd;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0x5a;
        goto LAB_000e30b0;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x3c;
        goto LAB_000e30b0;
      }
      uVar11 = 0x1e;
      if (Globals::iPad != '\0') {
        uVar11 = 0x2d;
      }
      *(undefined4 *)(this + 0x70) = uVar11;
    }
    else {
      uVar11 = 0x33;
LAB_000e30b0:
      *(undefined4 *)(this + 0x70) = uVar11;
    }
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3984;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3988;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 207.0;
    }
    *(int *)(this + 0x74) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3994;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3998;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 473.4;
    }
    *(int *)(this + 0x78) = (int)fVar28;
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0xb4;
        goto LAB_000e3148;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x78;
        goto LAB_000e3148;
      }
      uVar11 = 0x3c;
      if (Globals::iPad != '\0') {
        uVar11 = 0x5a;
      }
      *(undefined4 *)(this + 0x2c4) = uVar11;
    }
    else {
      uVar11 = 0x6c;
LAB_000e3148:
      *(undefined4 *)(this + 0x2c4) = uVar11;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0x5a;
        goto LAB_000e317e;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x3c;
        goto LAB_000e317e;
      }
      uVar11 = 0x1e;
      if (Globals::iPad != '\0') {
        uVar11 = 0x2d;
      }
      *(undefined4 *)(this + 0x2c8) = uVar11;
    }
    else {
      uVar11 = 0x2d;
LAB_000e317e:
      *(undefined4 *)(this + 0x2c8) = uVar11;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0xb4;
        goto LAB_000e31b4;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x78;
        goto LAB_000e31b4;
      }
      uVar11 = 0x3c;
      if (Globals::iPad != '\0') {
        uVar11 = 0x5a;
      }
      *(undefined4 *)(this + 0x2cc) = uVar11;
    }
    else {
      uVar11 = 0x6a;
LAB_000e31b4:
      *(undefined4 *)(this + 0x2cc) = uVar11;
    }
    if (Globals::n9 == 0) {
      if (Globals::iPadLarge != '\0') {
        uVar11 = 0x5a;
        goto LAB_000e31ea;
      }
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x3c;
        goto LAB_000e31ea;
      }
      uVar11 = 0x1e;
      if (Globals::iPad != '\0') {
        uVar11 = 0x2d;
      }
      *(undefined4 *)(this + 0x2d0) = uVar11;
    }
    else {
      uVar11 = 0x35;
LAB_000e31ea:
      *(undefined4 *)(this + 0x2d0) = uVar11;
    }
    uVar11 = 0x3c;
    uVar16 = 100;
    if (Globals::iPad != '\0') {
      uVar11 = 100;
      uVar16 = 0xa0;
    }
    if (Globals::n9 == 0 && Globals::retinaDisplay == 0) {
      uVar16 = uVar11;
    }
    *(undefined4 *)(this + 0x2d4) = uVar16;
    uVar11 = 0x4b;
    uVar16 = 0x7d;
    if (Globals::iPad != '\0') {
      uVar11 = 0x7d;
      uVar16 = 200;
    }
    if (Globals::retinaDisplay == 0 && Globals::n9 == 0) {
      uVar16 = uVar11;
    }
    *(undefined4 *)(this + 0x2d8) = uVar16;
    if (Globals::n9 == 0) {
      fVar28 = 9.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 18.0;
      }
    }
    else {
      fVar28 = 13.5;
    }
    *(int *)(this + 0x7c) = (int)fVar28;
    if (Globals::n9 == 0) {
      fVar28 = 10.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 20.0;
      }
    }
    else {
      fVar28 = 15.0;
    }
    *(int *)(this + 0x80) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e39ec;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e39f0;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 120.0;
    }
    *(int *)(this + 0x84) = (int)fVar28;
    if (Globals::n9 == 0) {
      fVar28 = 30.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 60.0;
      }
    }
    else {
      fVar28 = 45.0;
    }
    *(int *)(this + 0x88) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3a04;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3a08;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 57.6;
    }
    *(int *)(this + 0x8c) = (int)fVar28;
    puVar18 = &DAT_000e3a18;
    if ((Globals::iPad != '\0' || Globals::n9 != 0) || Globals::retinaDisplay != 0) {
      puVar18 = &DAT_000e3a1c;
    }
    *(undefined4 *)(this + 0x90) = *puVar18;
    if (Globals::n9 == 0) {
      fVar28 = 10.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 20.0;
      }
    }
    else {
      fVar28 = 15.0;
    }
    *(int *)(this + 0x94) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3a2c;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3a30;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 630.0;
    }
    *(int *)(this + 0x98) = (int)fVar28;
    if (Globals::n9 == 0) {
      pfVar17 = (float *)&DAT_000e3a3c;
      if (Globals::retinaDisplay != 0) {
        pfVar17 = (float *)&DAT_000e3a40;
      }
      fVar28 = *pfVar17;
    }
    else {
      fVar28 = 75.0;
    }
    *(int *)(this + 0x9c) = (int)fVar28;
    if (Globals::iPadLarge == '\0') {
      if (Globals::iPad != '\0' || Globals::n9 != 0) {
        uVar11 = 0x3d;
        goto LAB_000e343c;
      }
      uVar11 = 0x29;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x52;
      }
      *(undefined4 *)(this + 0xac) = uVar11;
    }
    else {
      uVar11 = 0x7a;
LAB_000e343c:
      *(undefined4 *)(this + 0xac) = uVar11;
    }
    if (Globals::iPadLarge == '\0') {
      if (Globals::iPad != '\0' || Globals::n9 != 0) {
        uVar11 = 0x3d;
        goto LAB_000e3470;
      }
      uVar11 = 0x29;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x52;
      }
      *(undefined4 *)(this + 0xa8) = uVar11;
    }
    else {
      uVar11 = 0x7a;
LAB_000e3470:
      *(undefined4 *)(this + 0xa8) = uVar11;
    }
    if (Globals::n9 == 0) {
      fVar28 = 25.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 50.0;
      }
    }
    else {
      fVar28 = 45.0;
    }
    *(int *)(this + 0xa0) = (int)fVar28;
    if (Globals::n9 == 0) {
      fVar28 = 5.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 10.0;
      }
    }
    else {
      fVar28 = 9.0;
    }
    *(int *)(this + 0xa4) = (int)fVar28;
    if (Globals::n9 == 0) {
      fVar28 = 3.0;
      bVar25 = 0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 6.0;
      }
    }
    else {
      fVar28 = 4.5;
      bVar25 = 1;
    }
  }
  else {
    *(undefined4 *)(this + 4) = 0x15;
    *(undefined4 *)(this + 8) = 0x2a;
    *(undefined4 *)(this + 0xc) = 0x28;
    *(undefined4 *)(this + 0x10) = 0x34;
    *(undefined8 *)(this + 0x14) = 0xc0000001e;
    *(undefined8 *)(this + 0x1c) = 0x70000001c;
    *(undefined8 *)(this + 0x24) = 0x700000007;
    *(undefined8 *)(this + 0x2c) = 0x2a00000004;
    *(undefined8 *)(this + 0x34) = 0x900000008;
    *(undefined8 *)(this + 0x3c) = 0x8c00000052;
    *(undefined8 *)(this + 0x44) = 0xf00000007;
    *(undefined8 *)(this + 0x4c) = 0x7d00000007;
    *(undefined8 *)(this + 0x54) = 0x155000001e7;
    *(undefined8 *)(this + 0x5c) = 0x5a0000003f;
    *(undefined4 *)(this + 0x2c0) = 0xfffffffe;
    *(undefined8 *)(this + 100) = 0x23600000070;
    *(undefined8 *)(this + 0x6c) = 0x3f000000bf;
    *(undefined4 *)(this + 0x74) = 0xa1;
    *(undefined4 *)(this + 0x78) = 0x171;
    *(undefined4 *)(this + 0x2c4) = 0x7e;
    *(undefined8 *)(this + 0x2c8) = 0x7e0000003f;
    *(undefined8 *)(this + 0x2d0) = 0x700000003f;
    *(undefined4 *)(this + 0x2d8) = 0x8d;
    *(undefined8 *)(this + 0x7c) = 0xe0000000c;
    *(undefined8 *)(this + 0x84) = 0x2a00000070;
    *(undefined4 *)(this + 0x8c) = 0x2d;
    *(undefined4 *)(this + 0x90) = 0x3eeca864;
    *(undefined4 *)(this + 0x94) = 0xe;
    *(undefined4 *)(this + 0x98) = 0x24e;
    *(undefined4 *)(this + 0x9c) = 0x46;
    *(undefined4 *)(this + 0xac) = 0x55;
    *(undefined4 *)(this + 0xa8) = 0x55;
    *(undefined4 *)(this + 0xa0) = 0x23;
    *(undefined4 *)(this + 0xa4) = 7;
    fVar28 = 4.21875;
    bVar25 = Globals::n9;
  }
  *(int *)(this + 0xb0) = (int)fVar28;
  if (bVar25 == 0 && cVar9 == '\0') {
    uVar11 = 0x12;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x24;
    }
  }
  else {
    uVar11 = 0x19;
  }
  *(undefined4 *)(this + 0xb8) = uVar11;
  if (cVar9 != '\0') {
    *(undefined4 *)(this + 0xb4) = 0x14;
    *(undefined8 *)(this + 0xbc) = 0x90000000b;
    *(undefined8 *)(this + 0xc4) = 0x50000000b;
    *(undefined8 *)(this + 0xcc) = 0x15000000fd;
    *(undefined8 *)(this + 0xd4) = 0x340000001c;
    *(undefined8 *)(this + 0xdc) = 0x3fb4000041610000;
    *(undefined8 *)(this + 0xe4) = 0x3fb4000041e10000;
    *(undefined4 *)(this + 0xec) = 0x38;
    *(undefined4 *)(this + 0xf0) = 0x70;
    *(undefined4 *)(this + 0xf4) = 0x119;
    *(undefined8 *)(this + 0xf8) = 0x700000232;
    *(undefined8 *)(this + 0x100) = 0x500000002;
    *(undefined8 *)(this + 0x294) = 0x7600000119;
    *(undefined8 *)(this + 0x29c) = 0x1000000010;
    *(undefined8 *)(this + 0x2a4) = 0x8c0000009a;
    *(undefined8 *)(this + 0x2ac) = 0x2a00000093;
    *(undefined4 *)(this + 0x2b4) = 0x23;
    *(undefined4 *)(this + 0x2b8) = 9;
    *(undefined4 *)(this + 0x108) = 0xfffffffe;
    *(undefined4 *)(this + 0x10c) = 1;
    *(undefined8 *)(this + 0x110) = 0x100000002;
    *(undefined8 *)(this + 0x118) = 0x2300000009;
    *(undefined8 *)(this + 0x120) = 0x100000015;
    *(undefined8 *)(this + 0x128) = 0x1500000001;
    *(undefined8 *)(this + 0x130) = 0x970000004e;
    *(undefined8 *)(this + 0x138) = 0x1700000042;
    *(undefined8 *)(this + 0x140) = 0x120000000f;
    *(undefined8 *)(this + 0x148) = 0xbd00000002;
    *(undefined8 *)(this + 0x150) = 0x4600000005;
    *(undefined8 *)(this + 0x158) = 0xce00000046;
    *(undefined8 *)(this + 0x160) = 0x44;
    *(undefined8 *)(this + 0x168) = 0xb800000023;
    *(undefined4 *)(this + 0x170) = 0xae;
    *(undefined4 *)(this + 0x174) = 0x54;
    *(undefined4 *)(this + 0x178) = 0x54;
    *(undefined4 *)(this + 0x17c) = 0xd9;
    *(undefined4 *)(this + 0x180) = 0x17;
    *(undefined4 *)(this + 0x184) = 0xa3;
    *(undefined4 *)(this + 0x188) = 0x17;
    *(undefined4 *)(this + 0x18c) = 0xf4;
    *(undefined8 *)(this + 400) = 0x8fffffffa;
    *(undefined8 *)(this + 0x198) = 0x5a00000010;
    fVar28 = 5.625;
    *(undefined8 *)(this + 0x1a0) = 0x1600000012;
    *(undefined8 *)(this + 0x1a8) = 0xf300000016;
    *(undefined8 *)(this + 0x1b0) = 0x2a00000012;
    *(undefined8 *)(this + 0x1b8) = 0x10000002e;
    *(undefined8 *)(this + 0x1c0) = 0x1a0000005c;
    *(undefined8 *)(this + 0x1c8) = 0x3200000028;
    *(undefined8 *)(this + 0x1d0) = 0x1100000007;
    *(undefined8 *)(this + 0x1d8) = 0xe00000005;
    *(undefined4 *)(this + 0x1e0) = 0x3fb40000;
    goto LAB_000e4818;
  }
  if (bVar25 == 0) {
    uVar21 = 8;
    uVar15 = 6;
    uVar30 = 0x41a00000;
    uVar20 = 0x19;
    uVar16 = 7;
    uVar23 = 0xf;
    uVar11 = 0x41200000;
    bVar26 = Globals::retinaDisplay != 0;
    uVar22 = 0xf;
    if (bVar26) {
      uVar22 = 0x1d;
    }
    uVar32 = 0x3f800000;
    *(undefined4 *)(this + 0xb4) = uVar22;
    if (bVar26) {
      uVar21 = 0x10;
    }
    *(undefined4 *)(this + 0xbc) = uVar21;
    uVar22 = 8;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar15 = 0xd;
    }
    *(undefined4 *)(this + 0xc0) = uVar15;
    if (bVar26) {
      uVar22 = 0xe;
    }
    *(undefined4 *)(this + 0xc4) = uVar22;
    uVar22 = 4;
    uVar21 = 400;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar22 = 10;
    }
    uVar15 = 0xb4;
    *(undefined4 *)(this + 200) = uVar22;
    if (bVar26) {
      uVar15 = 0x168;
    }
    uVar19 = 0x50;
    *(undefined4 *)(this + 0xcc) = uVar15;
    bVar26 = Globals::retinaDisplay != 0;
    uVar22 = 0xf;
    if (bVar26) {
      uVar22 = 0x1e;
    }
    *(undefined4 *)(this + 0xd0) = uVar22;
    uVar22 = 0x14;
    if (bVar26) {
      uVar22 = 0x28;
    }
    *(undefined4 *)(this + 0xd4) = uVar22;
    uVar22 = 0x25;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x41a00000;
      uVar22 = 0x4a;
    }
    *(undefined4 *)(this + 0xd8) = uVar22;
    *(undefined4 *)(this + 0xdc) = uVar11;
    uVar11 = 0x3f800000;
    if (Globals::retinaDisplay != 0) {
      uVar32 = 0x40000000;
      uVar30 = 0x41200000;
    }
    *(undefined4 *)(this + 0xe0) = uVar32;
    *(undefined4 *)(this + 0xe4) = uVar30;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar11 = 0x40000000;
    }
    uVar22 = 0x28;
    *(undefined4 *)(this + 0xe8) = uVar11;
    if (bVar26) {
      uVar22 = 0x50;
    }
    *(undefined4 *)(this + 0xec) = uVar22;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar19 = 0xa0;
    }
    uVar11 = 200;
    *(undefined4 *)(this + 0xf0) = uVar19;
    if (bVar26) {
      uVar11 = 400;
    }
    uVar22 = 200;
    *(undefined4 *)(this + 0xf4) = uVar11;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar21 = 800;
    }
    uVar11 = 5;
    *(undefined4 *)(this + 0xf8) = uVar21;
    if (bVar26) {
      uVar11 = 10;
    }
    *(undefined4 *)(this + 0xfc) = uVar11;
    uVar11 = 2;
    bVar26 = Globals::retinaDisplay != 0;
    uVar21 = 2;
    if (bVar26) {
      uVar21 = 4;
    }
    *(undefined4 *)(this + 0x100) = uVar21;
    uVar21 = 3;
    if (bVar26) {
      uVar21 = 5;
    }
    *(undefined4 *)(this + 0x104) = uVar21;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar22 = 400;
    }
    *(undefined4 *)(this + 0x294) = uVar22;
    uVar22 = 0x54;
    if (bVar26) {
      uVar22 = 0xa8;
    }
    uVar21 = 0xc;
    *(undefined4 *)(this + 0x298) = uVar22;
    if (Globals::retinaDisplay != 0) {
      uVar21 = 0x18;
    }
    *(undefined4 *)(this + 0x29c) = uVar21;
    *(undefined4 *)(this + 0x2a0) = uVar21;
    uVar22 = 0x6e;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar22 = 0xdc;
    }
    uVar21 = 100;
    *(undefined4 *)(this + 0x2a4) = uVar22;
    if (bVar26) {
      uVar21 = 200;
    }
    uVar22 = 0x69;
    *(undefined4 *)(this + 0x2a8) = uVar21;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar22 = 0xd2;
    }
    uVar21 = 0x1e;
    *(undefined4 *)(this + 0x2ac) = uVar22;
    if (bVar26) {
      uVar21 = 0x3c;
    }
    uVar15 = 7;
    *(undefined4 *)(this + 0x2b0) = uVar21;
    uVar22 = 0x19;
    if (Globals::retinaDisplay != 0) {
      uVar22 = 0x32;
      uVar16 = 0x10;
    }
    *(undefined4 *)(this + 0x2b4) = uVar22;
    *(undefined4 *)(this + 0x2b8) = uVar16;
    uVar22 = 1;
    bVar26 = Globals::retinaDisplay != 0;
    uVar16 = 0;
    if (bVar26) {
      uVar16 = 0xfffffffe;
    }
    *(undefined4 *)(this + 0x108) = uVar16;
    uVar16 = 1;
    if (bVar26) {
      uVar16 = 2;
    }
    *(undefined4 *)(this + 0x10c) = uVar16;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar11 = 1;
    }
    uVar16 = 1;
    *(undefined4 *)(this + 0x110) = uVar11;
    if (bVar26) {
      uVar16 = 0xffffffff;
    }
    *(undefined4 *)(this + 0x114) = uVar16;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar15 = 0xe;
    }
    *(undefined4 *)(this + 0x118) = uVar15;
    if (bVar26) {
      uVar20 = 0x32;
    }
    *(undefined4 *)(this + 0x11c) = uVar20;
    bVar26 = Globals::retinaDisplay != 0;
    uVar11 = 0xf;
    if (bVar26) {
      uVar11 = 0x1c;
    }
    *(undefined4 *)(this + 0x120) = uVar11;
    uVar11 = 1;
    if (bVar26) {
      uVar11 = 2;
    }
    *(undefined4 *)(this + 0x124) = uVar11;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar22 = 2;
    }
    *(undefined4 *)(this + 0x128) = uVar22;
    if (bVar26) {
      uVar23 = 0x1e;
    }
    *(undefined4 *)(this + 300) = uVar23;
    if (Globals::iPadLarge == '\0') {
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x50;
        goto LAB_000e3eea;
      }
      uVar11 = 0x28;
      if (Globals::iPad != '\0') {
        uVar11 = 0x38;
      }
      *(undefined4 *)(this + 0x130) = uVar11;
    }
    else {
      uVar11 = 0x70;
LAB_000e3eea:
      *(undefined4 *)(this + 0x130) = uVar11;
    }
    if (Globals::iPadLarge == '\0') {
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xa0;
        goto LAB_000e3f10;
      }
      uVar11 = 0x50;
      if (Globals::iPad != '\0') {
        uVar11 = 0x6c;
      }
      *(undefined4 *)(this + 0x134) = uVar11;
    }
    else {
      uVar11 = 0xd8;
LAB_000e3f10:
      *(undefined4 *)(this + 0x134) = uVar11;
    }
    if (Globals::iPadLarge == '\0') {
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x46;
        goto LAB_000e3f36;
      }
      uVar11 = 0x23;
      if (Globals::iPad != '\0') {
        uVar11 = 0x2f;
      }
      *(undefined4 *)(this + 0x138) = uVar11;
    }
    else {
      uVar11 = 0x5e;
LAB_000e3f36:
      *(undefined4 *)(this + 0x138) = uVar11;
    }
    uVar11 = 0x11;
    fVar28 = 4.0;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar11 = 0x22;
    }
    uVar16 = 0xb;
    *(undefined4 *)(this + 0x13c) = uVar11;
    if (bVar26) {
      uVar16 = 0x16;
    }
    uVar11 = 0xd;
    *(undefined4 *)(this + 0x140) = uVar16;
    bVar26 = Globals::retinaDisplay != 0;
    if (bVar26) {
      uVar11 = 0x1a;
    }
    uVar16 = 2;
    *(undefined4 *)(this + 0x144) = uVar11;
    if (bVar26) {
      uVar16 = 4;
    }
    *(undefined4 *)(this + 0x148) = uVar16;
    uVar11 = 0x87;
    if (Globals::retinaDisplay != 0) {
      fVar28 = 8.0;
      uVar11 = 0x10e;
    }
    *(undefined4 *)(this + 0x14c) = uVar11;
  }
  else {
    fVar28 = 6.0;
    *(undefined4 *)(this + 0xb4) = 0x16;
    *(undefined8 *)(this + 0xbc) = 0xb0000000c;
    *(undefined8 *)(this + 0xc4) = 0xa0000000b;
    *(undefined8 *)(this + 0xcc) = 0x160000010e;
    *(undefined8 *)(this + 0xd4) = 0x3700000024;
    *(undefined8 *)(this + 0xdc) = 0x3fc0000041700000;
    *(undefined8 *)(this + 0xe4) = 0x3fc0000041400000;
    *(undefined4 *)(this + 0xec) = 0x3c;
    *(undefined4 *)(this + 0xf0) = 0x78;
    *(undefined4 *)(this + 0xf4) = 300;
    *(undefined8 *)(this + 0xf8) = 600;
    *(undefined8 *)(this + 0x100) = 0x400000005;
    *(undefined8 *)(this + 0x294) = 0x9200000168;
    *(undefined8 *)(this + 0x29c) = 0x600000008;
    *(undefined8 *)(this + 0x2a4) = 0xb4000000c6;
    *(undefined8 *)(this + 0x2ac) = 0x36000000bd;
    *(undefined4 *)(this + 0x2b4) = 0x25;
    *(undefined4 *)(this + 0x2b8) = 0xe;
    *(undefined4 *)(this + 0x108) = 0xffffffff;
    *(undefined4 *)(this + 0x10c) = 2;
    *(undefined8 *)(this + 0x110) = 0xffffffff00000001;
    *(undefined8 *)(this + 0x118) = 0x250000000d;
    *(undefined8 *)(this + 0x120) = 0x200000016;
    *(undefined8 *)(this + 0x128) = 0x1600000002;
    *(undefined8 *)(this + 0x130) = 0x780000003c;
    *(undefined8 *)(this + 0x138) = 0x1900000034;
    *(undefined8 *)(this + 0x140) = 0x1300000013;
    *(undefined8 *)(this + 0x148) = 0xf300000013;
  }
  *(int *)(this + 0x150) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x32;
      goto LAB_000e3fc8;
    }
    if (bVar25 != 0) {
      uVar11 = 0xe;
      goto LAB_000e3fc8;
    }
    uVar11 = 0xf;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x1e;
    }
    *(undefined4 *)(this + 0x154) = uVar11;
  }
  else {
    uVar11 = 100;
LAB_000e3fc8:
    *(undefined4 *)(this + 0x154) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x32;
      goto LAB_000e3ff6;
    }
    if (bVar25 != 0) {
      uVar11 = 0xd;
      goto LAB_000e3ff6;
    }
    uVar11 = 0xe;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x1c;
    }
    *(undefined4 *)(this + 0x158) = uVar11;
  }
  else {
    uVar11 = 100;
LAB_000e3ff6:
    *(undefined4 *)(this + 0x158) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x93;
      goto LAB_000e4026;
    }
    if (bVar25 != 0) {
      uVar11 = 0x88;
      goto LAB_000e4026;
    }
    uVar11 = 0x4f;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x9e;
    }
    *(undefined4 *)(this + 0x15c) = uVar11;
  }
  else {
    uVar11 = 0x126;
LAB_000e4026:
    *(undefined4 *)(this + 0x15c) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad == '\0') {
      uVar11 = 0xd;
      if ((bVar25 == 0) && (Globals::retinaDisplay != 0)) {
        uVar11 = 0x1a;
      }
    }
    else {
      uVar11 = 0x31;
    }
  }
  else {
    uVar11 = 0x62;
  }
  *(undefined4 *)(this + 0x160) = uVar11;
  if (Globals::iPadLarge == '\0' && Globals::iPad == '\0') {
    if (bVar25 == 0) {
      uVar11 = 0xd;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0x19;
      }
      *(undefined4 *)(this + 0x164) = uVar11;
      goto LAB_000e40bc;
    }
    fVar28 = 37.5;
    *(undefined4 *)(this + 0x164) = 0x17;
  }
  else {
    *(undefined4 *)(this + 0x164) = 0;
    if (bVar25 == 0) {
LAB_000e40bc:
      fVar28 = 25.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 50.0;
      }
    }
    else {
      fVar28 = 37.5;
    }
  }
  *(int *)(this + 0x168) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x83;
      goto LAB_000e410a;
    }
    if (bVar25 != 0) {
      uVar11 = 0x73;
      goto LAB_000e410a;
    }
    uVar11 = 0x45;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x8a;
    }
    *(undefined4 *)(this + 0x16c) = uVar11;
  }
  else {
    uVar11 = 0x106;
LAB_000e410a:
    *(undefined4 *)(this + 0x16c) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x7c;
      goto LAB_000e4138;
    }
    if (bVar25 != 0) {
      uVar11 = 0x6a;
      goto LAB_000e4138;
    }
    uVar11 = 0x40;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x80;
    }
    *(undefined4 *)(this + 0x170) = uVar11;
  }
  else {
    uVar11 = 0xf8;
LAB_000e4138:
    *(undefined4 *)(this + 0x170) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad == '\0') {
      if (bVar25 == 0) {
        fVar28 = 30.0;
        if (Globals::retinaDisplay != 0) {
          fVar28 = 60.0;
        }
      }
      else {
        fVar28 = 45.0;
      }
    }
    else {
      fVar28 = 42.0;
    }
  }
  else {
    fVar28 = 84.0;
  }
  *(int *)(this + 0x174) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x3c;
      goto LAB_000e4384;
    }
    if (bVar25 != 0) {
      uVar11 = 0x1b;
      goto LAB_000e4384;
    }
    uVar11 = 0x16;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x2c;
    }
    *(undefined4 *)(this + 0x178) = uVar11;
  }
  else {
    uVar11 = 0x78;
LAB_000e4384:
    *(undefined4 *)(this + 0x178) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x9b;
      goto LAB_000e43a8;
    }
    if (bVar25 == 0) {
      uVar11 = 0x55;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xaa;
      }
      *(undefined4 *)(this + 0x17c) = uVar11;
      goto LAB_000e443a;
    }
    fVar28 = 30.599998;
    *(undefined4 *)(this + 0x17c) = 0x92;
  }
  else {
    uVar11 = 0x136;
LAB_000e43a8:
    *(undefined4 *)(this + 0x17c) = uVar11;
    if (bVar25 == 0) {
LAB_000e443a:
      fVar28 = 17.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 34.0;
      }
    }
    else {
      fVar28 = 30.599998;
    }
  }
  *(int *)(this + 0x180) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0xad;
      goto LAB_000e447c;
    }
    if (bVar25 == 0) {
      uVar11 = 0x74;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xe8;
      }
      *(undefined4 *)(this + 0x184) = uVar11;
      goto LAB_000e44bc;
    }
    fVar28 = 30.599998;
    *(undefined4 *)(this + 0x184) = 0xd2;
  }
  else {
    uVar11 = 0x15a;
LAB_000e447c:
    *(undefined4 *)(this + 0x184) = uVar11;
    if (bVar25 == 0) {
LAB_000e44bc:
      fVar28 = 17.0;
      if (Globals::retinaDisplay != 0) {
        fVar28 = 34.0;
      }
    }
    else {
      fVar28 = 30.599998;
    }
  }
  *(int *)(this + 0x188) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0xdf;
      goto LAB_000e450a;
    }
    if (bVar25 != 0) {
      uVar11 = 0x140;
      goto LAB_000e450a;
    }
    uVar11 = 0xae;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x15c;
    }
    *(undefined4 *)(this + 0x18c) = uVar11;
  }
  else {
    uVar11 = 0x1be;
LAB_000e450a:
    *(undefined4 *)(this + 0x18c) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad == '\0' && bVar25 == 0) {
      uVar11 = 0xffffffff;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xfffffffe;
      }
    }
    else {
      uVar11 = 0xfffffffc;
    }
  }
  else {
    uVar11 = 0xfffffff8;
  }
  *(undefined4 *)(this + 400) = uVar11;
  if (bVar25 == 0) {
    fVar28 = 6.0;
    if (Globals::retinaDisplay != 0) {
      fVar28 = 12.0;
    }
  }
  else {
    fVar28 = 10.799999;
  }
  *(int *)(this + 0x194) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad == '\0') {
      if (bVar25 == 0) {
        fVar28 = 6.0;
        if (Globals::retinaDisplay != 0) {
          fVar28 = 12.0;
        }
      }
      else {
        fVar28 = 9.0;
      }
    }
    else {
      fVar28 = 12.0;
    }
  }
  else {
    fVar28 = 24.0;
  }
  *(int *)(this + 0x198) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0x40;
      goto LAB_000e461e;
    }
    if (bVar25 != 0) {
      uVar11 = 0x36;
      goto LAB_000e461e;
    }
    uVar11 = 0x2d;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x5a;
    }
    *(undefined4 *)(this + 0x19c) = uVar11;
  }
  else {
    uVar11 = 0x80;
LAB_000e461e:
    *(undefined4 *)(this + 0x19c) = uVar11;
  }
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0xd;
      goto LAB_000e4640;
    }
    if (bVar25 == 0) {
      uVar11 = 7;
      if (Globals::retinaDisplay != 0) {
        uVar11 = 0xe;
      }
      *(undefined4 *)(this + 0x1a0) = uVar11;
      goto LAB_000e4696;
    }
    *(undefined4 *)(this + 0x1a0) = 10;
LAB_000e4658:
    fVar28 = 24.0;
    uVar11 = 0x1c;
  }
  else {
    uVar11 = 0x1a;
LAB_000e4640:
    *(undefined4 *)(this + 0x1a0) = uVar11;
    if (bVar25 != 0) goto LAB_000e4658;
LAB_000e4696:
    uVar11 = 0x10;
    fVar28 = 16.0;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0x20;
      fVar28 = 32.0;
    }
  }
  *(undefined4 *)(this + 0x1a4) = uVar11;
  *(int *)(this + 0x1a8) = (int)fVar28;
  if (Globals::iPadLarge == '\0') {
    if (Globals::iPad != '\0') {
      uVar11 = 0xad;
      goto LAB_000e46e4;
    }
    if (bVar25 != 0) {
      *(undefined4 *)(this + 0x1ac) = 0xd0;
      goto LAB_000e46fc;
    }
    uVar11 = 0x74;
    if (Globals::retinaDisplay != 0) {
      uVar11 = 0xe8;
    }
    *(undefined4 *)(this + 0x1ac) = uVar11;
  }
  else {
    uVar11 = 0x15a;
LAB_000e46e4:
    *(undefined4 *)(this + 0x1ac) = uVar11;
    if (bVar25 != 0) {
LAB_000e46fc:
      fVar28 = 6.0;
      *(undefined8 *)(this + 0x1b0) = 0x2d00000013;
      *(undefined8 *)(this + 0x1b8) = 0x200000028;
      *(undefined8 *)(this + 0x1c0) = 0x2200000050;
      *(undefined8 *)(this + 0x1c8) = 0x360000002b;
      *(undefined8 *)(this + 0x1d0) = 0x1200000007;
      *(undefined8 *)(this + 0x1d8) = 0xe00000006;
      *(undefined4 *)(this + 0x1e0) = 0x40000000;
      goto LAB_000e4818;
    }
  }
  uVar16 = 0xd;
  uVar11 = 0x3f800000;
  fVar28 = 4.0;
  bVar26 = Globals::retinaDisplay != 0;
  if (bVar26) {
    uVar16 = 0x1a;
  }
  uVar22 = 0x1e;
  *(undefined4 *)(this + 0x1b0) = uVar16;
  if (bVar26) {
    uVar22 = 0x3c;
  }
  uVar16 = 0x21;
  *(undefined4 *)(this + 0x1b4) = uVar22;
  bVar26 = Globals::retinaDisplay != 0;
  if (bVar26) {
    uVar16 = 0x42;
  }
  uVar22 = 1;
  *(undefined4 *)(this + 0x1b8) = uVar16;
  if (bVar26) {
    uVar22 = 2;
  }
  uVar16 = 0x42;
  *(undefined4 *)(this + 0x1bc) = uVar22;
  bVar26 = Globals::retinaDisplay != 0;
  if (bVar26) {
    uVar16 = 0x84;
  }
  uVar22 = 0x13;
  *(undefined4 *)(this + 0x1c0) = uVar16;
  if (bVar26) {
    uVar22 = 0x26;
  }
  uVar16 = 0x1d;
  *(undefined4 *)(this + 0x1c4) = uVar22;
  bVar26 = Globals::retinaDisplay != 0;
  if (bVar26) {
    uVar16 = 0x3a;
  }
  uVar22 = 0x24;
  *(undefined4 *)(this + 0x1c8) = uVar16;
  if (bVar26) {
    uVar22 = 0x48;
  }
  uVar16 = 5;
  *(undefined4 *)(this + 0x1cc) = uVar22;
  bVar26 = Globals::retinaDisplay != 0;
  if (bVar26) {
    uVar16 = 10;
  }
  uVar22 = 0xc;
  *(undefined4 *)(this + 0x1d0) = uVar16;
  if (bVar26) {
    uVar22 = 0x18;
  }
  uVar16 = 4;
  *(undefined4 *)(this + 0x1d4) = uVar22;
  bVar26 = Globals::retinaDisplay != 0;
  if (bVar26) {
    uVar16 = 8;
  }
  uVar22 = 10;
  *(undefined4 *)(this + 0x1d8) = uVar16;
  if (bVar26) {
    uVar22 = 0x14;
  }
  *(undefined4 *)(this + 0x1dc) = uVar22;
  if (Globals::retinaDisplay != 0) {
    uVar11 = 0x40000000;
    fVar28 = 8.0;
  }
  *(undefined4 *)(this + 0x1e0) = uVar11;
LAB_000e4818:
  *(int *)(this + 0x1e4) = (int)fVar28;
  bVar10 = Globals::retinaDisplay;
  uVar24 = (uint)Globals::retinaDisplay;
  uVar12 = 1;
  if (bVar25 == 0 && cVar9 == '\0') {
    uVar12 = uVar24;
  }
  *(uint *)(this + 0x1e8) = uVar12;
  if (cVar9 == '\0') {
    if (bVar25 == 0) {
      uVar33 = (ulonglong)bVar10 | (ulonglong)bVar10 << 0x10;
      auVar34._8_8_ = SUB128(SUB1612((undefined1  [16])0x0,4),4);
      auVar34._0_8_ = 0x1f0000001f;
      uVar33 = VectorCompareEqual(uVar33 | uVar33 << 0x20,0,2);
      auVar37 = FloatVectorNeg(*(undefined1 (*) [16])(auVar34 << 0x40 | auVar34),1,4);
      uVar11 = 0x13;
      auVar34 = VectorCopyLong(~uVar33,2,1);
      if (uVar24 != 0) {
        uVar11 = 0x26;
      }
      auVar31._8_8_ = 0x500000006;
      auVar31._0_8_ = 0x500000001;
      *(undefined4 *)(this + 0x1ec) = uVar11;
      auVar34 = VectorShiftLeft(auVar34,0x1f,0x20,0);
      uVar16 = 2;
      auVar35 = VectorShiftLeft(auVar34,auVar37,4,0);
      auVar36._8_8_ = 0x80000000a;
      auVar36._0_8_ = 0x800000012;
      auVar37._8_4_ = 5;
      auVar37._0_8_ = 0x400000009;
      auVar37._12_4_ = 4;
      auVar34 = VectorBitwiseSelect(auVar35,auVar36,auVar37);
      auVar38._8_8_ = 0x4600000042;
      auVar38._0_8_ = 0x80000012c;
      uVar11 = 0x10;
      if (uVar24 != 0) {
        uVar11 = 0x20;
        uVar16 = 4;
      }
      auVar1._8_4_ = 0x84;
      auVar1._0_8_ = 0x1000000258;
      auVar1._12_4_ = 0x8c;
      auVar37 = VectorBitwiseSelect(auVar35,auVar1,auVar38);
      *(undefined4 *)(this + 0x1fc) = uVar16;
      uVar16 = 0x32;
      *(longlong *)(this + 0x204) = auVar34._0_8_;
      *(longlong *)(this + 0x20c) = auVar34._8_8_;
      auVar5._8_8_ = 0x200000004;
      auVar5._0_8_ = 0x100000000;
      auVar7._8_8_ = 0x400000008;
      auVar7._0_8_ = 0x2fffffffe;
      auVar34 = VectorBitwiseSelect(auVar35,auVar7,auVar5);
      if (uVar24 != 0) {
        uVar16 = 100;
      }
      auVar2._8_4_ = 0xc;
      auVar2._0_8_ = 0xafffffffe;
      auVar2._12_4_ = 10;
      auVar31 = VectorBitwiseSelect(auVar35,auVar2,auVar31);
      uVar22 = 1;
      if (uVar24 != 0) {
        uVar22 = 2;
      }
      auVar3._8_8_ = 0xaa00000003;
      auVar3._0_8_ = 0x50000000f;
      auVar6._8_8_ = 0x15400000006;
      auVar6._0_8_ = 0xa0000001e;
      auVar36 = VectorBitwiseSelect(auVar35,auVar6,auVar3);
      *(longlong *)(this + 0x214) = auVar31._0_8_;
      *(longlong *)(this + 0x21c) = auVar31._8_8_;
      auVar4._8_8_ = 0x200000004;
      auVar4._0_8_ = 0x4600000028;
      auVar8._8_8_ = 0x100000002;
      auVar8._0_8_ = 0x2300000014;
      auVar31 = VectorBitwiseSelect(auVar35,auVar4,auVar8);
      *(longlong *)(this + 0x224) = auVar31._0_8_;
      *(longlong *)(this + 0x22c) = auVar31._8_8_;
      uVar21 = 300;
      *(undefined4 *)(this + 0x234) = uVar22;
      *(undefined4 *)(this + 0x238) = uVar16;
      uVar16 = 0x14;
      *(longlong *)(this + 0x23c) = auVar36._0_8_;
      *(longlong *)(this + 0x244) = auVar36._8_8_;
      *(longlong *)(this + 0x24c) = auVar34._0_8_;
      *(longlong *)(this + 0x254) = auVar34._8_8_;
      *(undefined4 *)(this + 0x25c) = uVar11;
      *(uint *)(this + 0x260) = uVar24 ^ 1;
      *(longlong *)(this + 0x264) = auVar37._0_8_;
      *(longlong *)(this + 0x26c) = auVar37._8_8_;
      uVar11 = 0x61;
      uVar15 = 0;
      if (uVar24 != 0) {
        uVar11 = 0xc2;
        uVar21 = 600;
        uVar16 = 0x28;
        uVar15 = 5;
      }
      *(undefined4 *)(this + 0x274) = uVar11;
      *(undefined4 *)(this + 0x278) = uVar21;
      *(undefined4 *)(this + 0x27c) = uVar16;
      *(undefined4 *)(this + 0x280) = uVar15;
    }
    else {
      *(undefined4 *)(this + 0x1ec) = 0x22;
      *(undefined4 *)(this + 0x1fc) = 4;
      *(undefined8 *)(this + 0x204) = 0x700000010;
      *(undefined8 *)(this + 0x20c) = 0x600000007;
      *(undefined8 *)(this + 0x214) = 0x7fffffffe;
      *(undefined8 *)(this + 0x21c) = 0x70000000a;
      *(undefined8 *)(this + 0x224) = 0x340000001e;
      *(undefined8 *)(this + 0x22c) = 0x200000004;
      uVar22 = 2;
      *(undefined4 *)(this + 0x234) = 2;
      *(undefined4 *)(this + 0x238) = 0x5a;
      *(undefined8 *)(this + 0x23c) = 0x90000001b;
      *(undefined8 *)(this + 0x244) = 0x13200000005;
      *(undefined8 *)(this + 0x24c) = 0x2ffffffff;
      *(undefined8 *)(this + 0x254) = 0x400000007;
      *(undefined8 *)(this + 0x25c) = 0x1c;
      *(undefined8 *)(this + 0x264) = 0xc000001c2;
      *(undefined8 *)(this + 0x26c) = 0x6900000063;
      *(undefined8 *)(this + 0x274) = 0x1c200000091;
      *(undefined4 *)(this + 0x27c) = 0x1e;
      *(undefined4 *)(this + 0x280) = 4;
    }
    fVar28 = (float)VectorSignedToFloat(uVar22,(byte)(in_fpscr >> 0x16) & 3);
    *(int *)(this + 0x3e0) = (int)fVar28;
    uVar12 = uVar24;
    if (bVar25 != 0) {
      uVar12 = 1;
    }
    *(uint *)(this + 0x3e4) = uVar12;
    if (bVar25 == 0) {
      if (Globals::iPadLarge == '\0') {
        if (Globals::iPad == '\0') {
          uVar11 = 0x4b;
          if (uVar24 != 0) {
            uVar11 = 0x96;
          }
        }
        else {
          uVar11 = 100;
        }
      }
      else {
        uVar11 = 200;
      }
      *(undefined4 *)(this + 1000) = uVar11;
      if (Globals::iPadLarge == '\0') {
        if (Globals::iPad == '\0') {
          iVar13 = 0x26;
          if (uVar24 != 0) {
            iVar13 = 0x4c;
          }
        }
        else {
          iVar13 = 0x37;
        }
      }
      else {
        iVar13 = 0x6e;
      }
      *(int *)(this + 0x3f4) = iVar13;
      uVar16 = 0x13;
      bVar26 = true;
      uVar11 = 0xc4;
      fVar28 = (float)VectorSignedToFloat(iVar13 + 0x11 << uVar24,(byte)(in_fpscr >> 0x16) & 3);
      *(int *)(this + 0x3f8) = (int)fVar28;
      if (uVar24 != 0) {
        uVar11 = 0x188;
      }
      *(undefined4 *)(this + 0x3ec) = uVar11;
      uVar11 = 0x32;
      if (uVar24 != 0) {
        uVar11 = 100;
      }
      *(undefined4 *)(this + 0x3f0) = uVar11;
      uVar11 = 3;
      if (uVar24 != 0) {
        uVar11 = 6;
      }
      *(undefined4 *)(this + 0x3fc) = uVar11;
      *(undefined4 *)(this + 700) = 2;
      if (uVar24 != 0) {
        uVar16 = 0x26;
      }
    }
    else {
      uVar16 = 0x22;
      bVar26 = false;
      *(undefined4 *)(this + 0x3f8) = 0x6f;
      *(undefined8 *)(this + 1000) = 0x16000000070;
      *(undefined8 *)(this + 0x3f0) = 0x390000004b;
      *(undefined4 *)(this + 0x3fc) = 5;
      *(undefined4 *)(this + 700) = 3;
    }
    *(undefined4 *)(this + 0x1f0) = uVar16;
    uVar11 = 0x10;
    if (uVar24 != 0) {
      uVar11 = 0x20;
    }
    uVar16 = 2;
    if (uVar24 != 0) {
      uVar16 = 4;
    }
    if (Globals::iPad != '\0') {
      uVar16 = uVar11;
    }
    fVar28 = (float)VectorSignedToFloat(uVar16,(byte)(in_fpscr >> 0x16) & 3);
    *(int *)(this + 500) = (int)fVar28;
    if (bVar26) {
      uVar11 = 0xfffffff3;
      if (uVar24 != 0) {
        uVar11 = 0xffffffe6;
      }
    }
    else {
      uVar11 = 0xffffffe6;
    }
    *(undefined4 *)(this + 0x200) = uVar11;
    uVar11 = 2;
    if (uVar24 != 0) {
      uVar11 = 4;
    }
    if (Globals::iPad == '\0') {
      uVar11 = 2;
    }
  }
  else {
    *(undefined4 *)(this + 0x1ec) = 0x1a;
    *(undefined4 *)(this + 0x1fc) = 2;
    *(undefined8 *)(this + 0x204) = 0x50000000c;
    *(undefined8 *)(this + 0x20c) = 0x500000007;
    *(undefined8 *)(this + 0x214) = 0x700000001;
    *(undefined8 *)(this + 0x21c) = 0x700000008;
    *(undefined8 *)(this + 0x224) = 0x310000001c;
    *(undefined8 *)(this + 0x22c) = 0x100000002;
    *(undefined4 *)(this + 0x234) = 1;
    *(undefined4 *)(this + 0x238) = 0x46;
    *(undefined8 *)(this + 0x23c) = 0x700000015;
    *(undefined8 *)(this + 0x244) = 0xef00000004;
    *(undefined8 *)(this + 0x24c) = 0x1fffffffe;
    *(undefined8 *)(this + 0x254) = 0x200000005;
    *(undefined8 *)(this + 0x25c) = 0x100000016;
    *(undefined8 *)(this + 0x264) = 0xb000001a5;
    *(undefined8 *)(this + 0x26c) = 0x620000005c;
    *(undefined8 *)(this + 0x274) = 0x1a500000088;
    *(undefined4 *)(this + 0x27c) = 0x1c;
    *(undefined4 *)(this + 0x280) = 0;
    *(undefined4 *)(this + 0x3e0) = 1;
    *(undefined4 *)(this + 0x3e4) = 0;
    *(undefined4 *)(this + 1000) = 0x8c;
    *(undefined4 *)(this + 0x3f4) = 0x4d;
    *(undefined4 *)(this + 0x3f8) = 0x84;
    if (bVar25 == 0) {
      uVar11 = 0xc4;
      uVar16 = 0x32;
      if (uVar24 != 0) {
        uVar11 = 0x188;
        uVar16 = 100;
      }
      bVar26 = true;
      *(undefined4 *)(this + 0x3ec) = uVar11;
      *(undefined4 *)(this + 0x3f0) = uVar16;
    }
    else {
      *(undefined4 *)(this + 0x3ec) = 0x160;
      *(undefined4 *)(this + 0x3f0) = 0x4b;
      bVar26 = false;
    }
    *(undefined4 *)(this + 0x3fc) = 4;
    uVar11 = 2;
    *(undefined4 *)(this + 700) = 2;
    *(undefined4 *)(this + 0x1f0) = 0x1a;
    *(undefined4 *)(this + 500) = 0x16;
    *(undefined4 *)(this + 0x200) = 0xffffffee;
  }
  *(undefined4 *)(this + 0x1f8) = uVar11;
  this[0x284] = (Layout)(bVar25 ^ 1);
  this[0x285] = (Layout)0x1;
  this[0x286] = (Layout)(bVar25 ^ 1);
  uVar22 = 3;
  uVar16 = 0;
  uVar11 = 0;
  if (bVar25 != 0) {
    uVar11 = 0x14;
    uVar16 = 0xffffffed;
  }
  if (uVar24 != 0) {
    uVar22 = 7;
  }
  if (!bVar26) {
    uVar22 = 4;
  }
  *(undefined4 *)(this + 0x288) = uVar11;
  *(undefined4 *)(this + 0x28c) = uVar16;
  *(undefined4 *)(this + 0x290) = uVar22;
  if (cVar9 == '\0') {
    if (Globals::iPadLarge == '\0') {
      pfVar17 = (float *)&DAT_000e5230;
      if (Globals::iPad != '\0') {
        pfVar17 = (float *)&DAT_000e5234;
      }
      bVar27 = false;
      if (Globals::iPad == '\0') {
        bVar27 = bVar26;
      }
      fVar28 = *pfVar17;
      if (bVar27) {
        fVar28 = 30.0;
        if (uVar24 != 0) {
          fVar28 = 60.0;
        }
      }
    }
    else {
      fVar28 = 160.0;
    }
    *(int *)(this + 0x2f4) = (int)fVar28;
    if (Globals::iPadLarge == '\0') {
      puVar18 = &DAT_000e5240;
      if (Globals::iPad != '\0') {
        puVar18 = &DAT_000e5244;
      }
      uVar11 = *puVar18;
      bVar27 = false;
      if (Globals::iPad == '\0') {
        bVar27 = bVar26;
      }
      if (bVar27) {
        puVar18 = &DAT_000e5160;
        if (uVar24 != 0) {
          puVar18 = &DAT_000e5164;
        }
        uVar11 = *puVar18;
      }
    }
    else {
      uVar11 = 0x43c80000;
    }
    uVar16 = 0x24;
    *(undefined4 *)(this + 0x2f8) = uVar11;
    uVar11 = 0xfa;
    bVar27 = Globals::iPadLarge != '\0';
    if (bVar27) {
      uVar16 = 0x48;
    }
    uVar22 = 200;
    *(undefined4 *)(this + 0x2fc) = uVar16;
    if (bVar27) {
      uVar22 = 400;
    }
    *(undefined4 *)(this + 0x300) = uVar22;
    cVar14 = Globals::iPadLarge;
    uVar16 = 0x15e;
    bVar27 = Globals::iPadLarge != '\0';
    if (bVar27) {
      uVar16 = 700;
    }
    *(undefined4 *)(this + 0x304) = uVar16;
    if (bVar27) {
      uVar11 = 500;
    }
  }
  else {
    *(undefined4 *)(this + 0x2f4) = 0x70;
    *(undefined4 *)(this + 0x2f8) = 0x438ca000;
    *(undefined4 *)(this + 0x2fc) = 0x32;
    uVar11 = 0x15f;
    *(undefined4 *)(this + 0x300) = 0x119;
    *(undefined4 *)(this + 0x304) = 0x1ec;
    cVar14 = Globals::iPadLarge;
  }
  *(undefined4 *)(this + 0x308) = uVar11;
  if (cVar14 == '\0') {
    uVar22 = 4;
    uVar21 = 0xfffffff8;
    uVar16 = 0xfffffff8;
    uVar11 = 3;
    if (uVar24 != 0) {
      uVar11 = 7;
    }
    if (Globals::iPad != '\0') {
      uVar22 = 3;
    }
    bVar27 = (bool)(bVar26 ^ 1);
    if (bVar27) {
      uVar11 = uVar22;
    }
    if (Globals::iPad != '\0') {
      uVar11 = uVar22;
    }
    *(undefined4 *)(this + 0x30c) = uVar11;
    uVar11 = 0xfffffffb;
    if (uVar24 != 0) {
      uVar11 = 0xfffffff7;
    }
    uVar22 = 0xfffffffb;
    if (Globals::iPad != '\0') {
      uVar21 = 0xfffffff4;
    }
    if (bVar27) {
      uVar11 = uVar21;
    }
    if (Globals::iPad != '\0') {
      uVar11 = uVar21;
    }
    *(undefined4 *)(this + 0x310) = uVar11;
    if (uVar24 != 0) {
      uVar22 = 0xfffffff8;
    }
    if (Globals::iPad != '\0') {
      uVar16 = 0xfffffffb;
    }
    if (bVar27) {
      uVar22 = uVar16;
    }
    if (Globals::iPad != '\0') {
      uVar22 = uVar16;
    }
    *(undefined4 *)(this + 0x314) = uVar22;
    uVar11 = 0;
    if (Globals::iPad != '\0') {
      uVar11 = 4;
    }
  }
  else {
    uVar11 = 8;
    *(undefined4 *)(this + 0x30c) = 6;
    *(undefined4 *)(this + 0x310) = 0xffffffe8;
    *(undefined4 *)(this + 0x314) = 0xfffffff6;
  }
  *(undefined4 *)(this + 0x318) = uVar11;
  if (cVar9 == '\0') {
    if (cVar14 == '\0') {
      uVar11 = 0x76;
      if (uVar24 != 0) {
        uVar11 = 0xec;
      }
      if (Globals::iPad != '\0' || bVar25 != 0) {
        uVar11 = 0xec;
      }
      *(undefined4 *)(this + 0x31c) = uVar11;
      uVar11 = 0x96;
      if (Globals::iPad != '\0') {
        uVar11 = 0x90;
      }
      if ((Globals::iPad == '\0' && !(bool)(bVar26 ^ 1)) && (uVar11 = 0x4c, uVar24 != 0)) {
        uVar11 = 0x96;
      }
    }
    else {
      uVar11 = 0x120;
      *(undefined4 *)(this + 0x31c) = 0x1d8;
    }
  }
  else {
    uVar11 = 0xca;
    *(undefined4 *)(this + 0x31c) = 0x14b;
  }
  *(undefined4 *)(this + 800) = uVar11;
  return;
}

// ===== Layout::~Layout  @0x000e5260  (86 bytes)
/* Layout::~Layout() */

Layout * __thiscall Layout::~Layout(Layout *this)

{
  void *pvVar1;
  
  if (*(TouchButton **)(this + 0x3b4) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x3b4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x3b4) = 0;
  if (*(TouchButton **)(this + 0x3b8) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x3b8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x3b8) = 0;
  if (*(TouchButton **)(this + 0x3bc) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x3bc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x3bc) = 0;
  if (*(ChoiceWindow **)(this + 0x3c4) != (ChoiceWindow *)0x0) {
    pvVar1 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0x3c4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x3c4) = 0;
  return this;
}

// ===== Layout::reload  @0x000e52b8  (1044 bytes)
/* Layout::reload() */

void __thiscall Layout::reload(Layout *this)

{
  uint uVar1;
  TouchButton *pTVar2;
  String *pSVar3;
  undefined4 uVar4;
  int iVar5;
  ushort uVar6;
  uint local_30;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  *(undefined4 *)(this + 0x3a8) = 0xffffffff;
  *(undefined4 *)(this + 0x324) = 0xffffffff;
  *(undefined4 *)(this + 0x328) = 0xffffffff;
  *(undefined4 *)(this + 0x32c) = 0xffffffff;
  __aeabi_memset4(this + 0x334,0x70,0xff);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x503,(uint *)(this + 0x398));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x47e,(uint *)(this + 0x324));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ff,(uint *)(this + 0x328));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x500,(uint *)(this + 0x330));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x474,(uint *)(this + 0x32c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x502,(uint *)(this + 0x334));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x506,(uint *)(this + 0x340));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x501,(uint *)(this + 0x338));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x507,(uint *)(this + 0x344));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4fe,(uint *)(this + 0x33c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x482,(uint *)(this + 0x348));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x481,(uint *)(this + 0x34c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x486,(uint *)(this + 0x378));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x487,(uint *)(this + 0x374));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x48b,(uint *)(this + 0x37c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x52d,(uint *)(this + 0x3a4));
  if (Globals::iPad == '\0') {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x480,(uint *)(this + 0x350));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x47f,(uint *)(this + 0x354));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x479,(uint *)(this + 0x358));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x478,(uint *)(this + 0x35c));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x489,(uint *)(this + 0x36c));
    uVar6 = 0x488;
  }
  else {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6bb,(uint *)(this + 0x350));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6ba,(uint *)(this + 0x354));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6b9,(uint *)(this + 0x358));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6b8,(uint *)(this + 0x35c));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6b7,(uint *)(this + 0x36c));
    uVar6 = 0x6bc;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar6,(uint *)(this + 0x370));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x530,(uint *)(this + 0x360));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x531,(uint *)(this + 0x364));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x52f,(uint *)(this + 0x368));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x47c,(uint *)(this + 900));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x47d,(uint *)(this + 0x380));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x47b,(uint *)(this + 0x388));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x47a,(uint *)(this + 0x38c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x484,(uint *)(this + 0x390));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x483,(uint *)(this + 0x394));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x50c,(uint *)(this + 0x3a0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x50d,(uint *)(this + 0x39c));
  pTVar2 = operator_new(0xc0);
  pSVar3 = (String *)GameText::getText(Globals::gameText,0xaa);
  TouchButton::TouchButton(pTVar2,pSVar3,2,*(int *)(this + 0x28),Globals::h + -3,'!');
  *(TouchButton **)(this + 0x3b4) = pTVar2;
  uVar4 = TouchButton::getWidth(pTVar2);
  *(undefined4 *)(this + 0x2f0) = uVar4;
  local_2c = 0xffffffff;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x535,&local_2c);
  uVar1 = local_2c;
  pTVar2 = operator_new(0xc0);
  if (uVar1 == 0xffffffff) {
    pSVar3 = (String *)GameText::getText(Globals::gameText,0xab);
    TouchButton::TouchButton
              (pTVar2,pSVar3,2,*(int *)(this + 0x28),Globals::h - *(int *)(this + 0x3fc),'!');
  }
  else {
    TouchButton::TouchButton
              (pTVar2,uVar1,2,*(int *)(this + 0x28),Globals::h - *(int *)(this + 0x3fc),'!');
  }
  *(TouchButton **)(this + 0x3b8) = pTVar2;
  local_30 = 0xffffffff;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x471,&local_30);
  pTVar2 = operator_new(0xc0);
  TouchButton::TouchButton(pTVar2,local_30,1,Globals::w,0,*(int *)(this + 0x3c),'\x12','\x04');
  *(TouchButton **)(this + 0x3bc) = pTVar2;
  iVar5 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
  *(int *)(this + 0x3ac) = iVar5 / 2 + -1;
  *this = (Layout)0x0;
  *(undefined4 *)(this + 0x3c4) = 0;
  *(undefined4 *)(this + 0x3c8) = 0;
  *(undefined4 *)(this + 0x3b0) = 0xffffffff;
  resetWindowDimensions(this);
  this[0x3cc] = (Layout)0x0;
  *(undefined4 *)(this + 0x3d0) = 0;
  *(undefined4 *)(this + 0x3d8) = 0;
  this[0x400] = (Layout)0x0;
  this[0x401] = (Layout)0x0;
  this[0x3dc] = (Layout)0x0;
  *(undefined2 *)(this + 0x2ec) = 0;
  *(undefined4 *)(this + 0x404) = 0;
  *(undefined4 *)(this + 0x408) = 0;
  *(undefined4 *)(this + 0x40d) = 0;
  *(undefined4 *)(this + 0x409) = 0;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::resetWindowDimensions  @0x000e5724  (216 bytes)
/* Layout::resetWindowDimensions() */

void __thiscall Layout::resetWindowDimensions(Layout *this)

{
  int iVar1;
  int iVar2;
  float local_2c;
  float local_24;
  
  iVar2 = __stack_chk_guard;
  *(undefined4 *)(this + 0x2dc) = 0;
  *(undefined4 *)(this + 0x2e0) = 0;
  iVar1 = Globals::w;
  *(int *)(this + 0x2e4) = Globals::w;
  *(undefined4 *)(this + 0x2e8) = Globals::h;
  TouchButton::setPosition(*(TouchButton **)(this + 0x3bc),iVar1,0,'\x12');
  TouchButton::setPosition
            (*(TouchButton **)(this + 0x3b4),
             *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x2dc),
             (*(int *)(this + 0x2e0) + *(int *)(this + 0x2e8)) - *(int *)(this + 0x3fc),'!');
  TouchButton::setPosition
            (*(TouchButton **)(this + 0x3b8),
             *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x2dc),
             (*(int *)(this + 0x2e0) + *(int *)(this + 0x2e8)) - *(int *)(this + 0x3fc),'!');
  if (*(int *)(this + 0x3b4) != 0) {
    TouchButton::getPosition();
    Globals::other_buttons_x._0_4_ = (undefined4)local_24;
    TouchButton::getPosition();
    Globals::other_buttons_y._0_4_ = (undefined4)local_2c;
  }
  if (__stack_chk_guard != iVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::setDrawColor  @0x000e5818  (6 bytes)
/* Layout::setDrawColor(int) */

void __thiscall Layout::setDrawColor(Layout *this,int param_1)

{
  *(int *)(this + 0x3b0) = param_1;
  return;
}

// ===== Layout::drawMask  @0x000e5820  (36 bytes)
/* Layout::drawMask() */

void Layout::drawMask(void)

{
  drawMask(Globals::h,0,0,Globals::w,(int)Globals::h);
  return;
}

// ===== Layout::drawMask  @0x000e584c  (66 bytes)
/* Layout::drawMask(int, int, int, int) */

void __thiscall Layout::drawMask(Layout *this,int param_1,int param_2,int param_3,int param_4)

{
  AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::FillRectangle(Globals::Canvas,param_1,param_2,param_3,param_4);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  return;
}

// ===== Layout::tagString  @0x000e5894  (180 bytes)
/* Layout::tagString(AbyssEngine::String) */

void Layout::tagString(AbyssEngine *param_1,undefined4 param_2,String *param_3)

{
  undefined4 extraout_r1;
  String aSStack_50 [8];
  String aSStack_48 [8];
  undefined4 local_40 [2];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  AbyssEngine aAStack_28 [8];
  AbyssEngine aAStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_38,"<c:",false);
  local_40[0] = 0;
  AbyssEngine::String::Set(CONCAT44(extraout_r1,local_40));
  AbyssEngine::operator+(aAStack_30,aSStack_38,(String *)local_40);
  AbyssEngine::String::String(aSStack_48,">",false);
  AbyssEngine::operator+(aAStack_28,aAStack_30,aSStack_48);
  AbyssEngine::operator+(aAStack_20,aAStack_28,param_3);
  AbyssEngine::String::String(aSStack_50,"<c:>",false);
  AbyssEngine::operator+(param_1,aAStack_20,aSStack_50);
  AbyssEngine::String::~String(aSStack_50);
  AbyssEngine::String::~String((String *)aAStack_20);
  AbyssEngine::String::~String((String *)aAStack_28);
  AbyssEngine::String::~String(aSStack_48);
  AbyssEngine::String::~String((String *)aAStack_30);
  AbyssEngine::String::~String((String *)local_40);
  AbyssEngine::String::~String(aSStack_38);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::formatNumber  @0x000e59a8  (396 bytes)
/* Layout::formatNumber(int) */

void Layout::formatNumber(int param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined4 in_r1;
  uint in_r2;
  int iVar3;
  String aSStack_58 [8];
  String aSStack_50 [8];
  AbyssEngine aAStack_48 [8];
  AbyssEngine aAStack_40 [4];
  int local_3c;
  String aSStack_38 [8];
  undefined4 local_30;
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_30 = 0;
  AbyssEngine::String::Set(CONCAT44(in_r1,&local_30));
  AbyssEngine::String::String((String *)param_1,"",false);
  uVar1 = GameText::getLanguage();
  if ((uVar1 < 0xc) && ((1 << (uVar1 & 0xff) & 0xc01U) != 0)) {
    AbyssEngine::String::String(aSStack_38,",",false);
  }
  else {
    AbyssEngine::String::String(aSStack_38,".",false);
  }
  if (local_2c < 4) {
    AbyssEngine::String::operator=((String *)param_1,(String *)&local_30);
  }
  else {
    if (-1 < local_2c + -3) {
      iVar3 = local_2c;
      do {
        AbyssEngine::String::SubString((uint)aSStack_50,(uint)&local_30);
        if (*(uint *)(param_1 + 4) < 2) {
          AbyssEngine::String::String(aSStack_58);
        }
        else {
          AbyssEngine::String::String(aSStack_58,aSStack_38,false);
        }
        AbyssEngine::operator+(aAStack_48,aSStack_50,aSStack_58);
        AbyssEngine::operator+(aAStack_40,aAStack_48,(String *)param_1);
        AbyssEngine::String::operator=((String *)param_1,aAStack_40);
        AbyssEngine::String::~String((String *)aAStack_40);
        AbyssEngine::String::~String((String *)aAStack_48);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String(aSStack_50);
        uVar2 = iVar3 - 6;
        iVar3 = iVar3 + -3;
      } while (uVar2 < 0x80000000);
    }
    AbyssEngine::String::SubString((uint)aAStack_40,(uint)&local_30);
    if (local_3c != 0) {
      AbyssEngine::operator+((AbyssEngine *)aSStack_50,aAStack_40,aSStack_38);
      AbyssEngine::operator+(aAStack_48,aSStack_50,(String *)param_1);
      AbyssEngine::String::operator=((String *)param_1,aAStack_48);
      AbyssEngine::String::~String((String *)aAStack_48);
      AbyssEngine::String::~String(aSStack_50);
    }
    AbyssEngine::String::~String((String *)aAStack_40);
  }
  if (0x7fffffff < in_r2) {
    AbyssEngine::String::String((String *)aAStack_48,"-",false);
    AbyssEngine::operator+(aAStack_40,aAStack_48,(String *)param_1);
    AbyssEngine::String::operator=((String *)param_1,aAStack_40);
    AbyssEngine::String::~String((String *)aAStack_40);
    AbyssEngine::String::~String((String *)aAStack_48);
  }
  AbyssEngine::String::~String(aSStack_38);
  AbyssEngine::String::~String((String *)&local_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::formatCredits  @0x000e5bd4  (80 bytes)
/* Layout::formatCredits(int) */

void Layout::formatCredits(int param_1)

{
  String aSStack_24 [8];
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  formatNumber((int)aSStack_1c);
  AbyssEngine::String::String(aSStack_24,"$",false);
  AbyssEngine::operator+((AbyssEngine *)param_1,aSStack_1c,aSStack_24);
  AbyssEngine::String::~String(aSStack_24);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::drawBG  @0x000e5c48  (42 bytes)
/* Layout::drawBG() */

void __thiscall Layout::drawBG(Layout *this)

{
  drawBGPattern(this,*(uint *)(this + 0x324),0,0,Globals::w,Globals::h);
  return;
}

// ===== Layout::drawBGPattern  @0x000e5c7c  (444 bytes)
/* Layout::drawBGPattern(unsigned int, int, int, int, int) */

void __thiscall
Layout::drawBGPattern(Layout *this,uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float extraout_s0;
  float fVar11;
  
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,param_1);
  iVar2 = __aeabi_idiv(param_4,iVar1);
  iVar5 = iVar2 * iVar1;
  iVar8 = param_4 - iVar2 * iVar1;
  iVar3 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,param_1);
  iVar4 = __aeabi_idiv(param_5,iVar3);
  iVar7 = param_5 - iVar4 * iVar3;
  fVar11 = extraout_s0;
  if (0 < iVar4) {
    iVar10 = 0;
    do {
      if (0 < iVar2) {
        iVar6 = iVar2;
        iVar9 = param_2;
        do {
          fVar11 = (float)AbyssEngine::PaintCanvas::DrawImage2D
                                    (Globals::Canvas,param_1,iVar9,iVar10 * iVar3 + param_3);
          iVar9 = iVar9 + iVar1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 != iVar4);
    iVar10 = iVar8;
    if (0 < iVar8) {
      iVar10 = iVar4;
    }
    if (0 < iVar10) {
      do {
        fVar11 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                                  (Globals::Canvas,param_1,0,0,iVar8,iVar3,fVar11,0,0,0,
                                   param_2 + iVar5);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  iVar3 = iVar7;
  if (0 < iVar7) {
    iVar3 = iVar2;
  }
  iVar4 = param_2;
  if (0 < iVar3) {
    do {
      fVar11 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                                (Globals::Canvas,param_1,0,0,iVar1,iVar7,fVar11,0,0,0,iVar4);
      iVar2 = iVar2 + -1;
      iVar4 = iVar4 + iVar1;
    } while (iVar2 != 0);
  }
  if (0 < iVar7 || 0 < iVar8) {
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,param_1,0,0,iVar8,iVar7,fVar11,0,0,0,param_2 + iVar5);
  }
  return;
}

// ===== Layout::drawWindow  @0x000e5e4c  (104 bytes)
/* Layout::drawWindow(AbyssEngine::String, bool) */

void __thiscall Layout::drawWindow(Layout *this,String *param_2,undefined4 param_3)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_20,param_2,false);
  drawWindow(this,aSStack_20,0,0,Globals::w,Globals::h - *(int *)(Globals::layout + 8),param_3);
  AbyssEngine::String::~String(aSStack_20);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::drawWindow  @0x000e5ed8  (254 bytes)
/* Layout::drawWindow(AbyssEngine::String, int, int, int, int, bool) */

void __thiscall
Layout::drawWindow(Layout *this,String *param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7)

{
  char cVar1;
  
  AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  if (param_7 == 1) {
    drawBGPattern(this,*(uint *)(this + 0x324),param_3,*(int *)(Globals::layout + 8) + param_4,
                  param_5,param_6 - *(int *)(Globals::layout + 8));
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawRectangle
            (Globals::Canvas,param_3,*(int *)(Globals::layout + 8) + param_4,param_5,
             param_6 - *(int *)(Globals::layout + 8));
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x32c),param_3,param_4);
  if ((*(int *)(param_2 + 4) != 0) &&
     (cVar1 = AbyssEngine::String::Compare(param_2,""), cVar1 == '\0')) {
    AbyssEngine::PaintCanvas::DrawString
              (Globals::Canvas,Globals::font,param_2,*(int *)(Globals::layout + 0x28) + param_3,
               (param_4 + *(int *)(Globals::layout + 8) / 2 + 1) - *(int *)(this + 0x3ac),false);
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  return;
}

// ===== Layout::drawWindow  @0x000e5ffc  (66 bytes)
/* Layout::drawWindow(AbyssEngine::String) */

void __thiscall Layout::drawWindow(Layout *this,String *param_2)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_1c,param_2,false);
  drawWindow(this,aSStack_1c,0);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::drawWindow  @0x000e6054  (88 bytes)
/* Layout::drawWindow(AbyssEngine::String, int, int, int, int) */

void __thiscall
Layout::drawWindow(Layout *this,String *param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_24,param_2,false);
  drawWindow(this,aSStack_24,param_3,param_4,param_5,param_6,1);
  AbyssEngine::String::~String(aSStack_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::drawBGBorder  @0x000e60c4  (32 bytes)
/* Layout::drawBGBorder(unsigned int, unsigned int, int, int, int, int) */

void __thiscall
Layout::drawBGBorder
          (Layout *this,uint param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  drawBGBorder((Layout *)param_4,param_1,param_2,param_3,param_4,param_5,param_6,0,0);
  return;
}

// ===== Layout::drawBGBorder  @0x000e60e4  (744 bytes)
/* Layout::drawBGBorder(unsigned int, unsigned int, int, int, int, int, int, int) */

void __thiscall
Layout::drawBGBorder
          (Layout *this,uint param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
          int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float extraout_s0;
  float fVar11;
  float extraout_s0_00;
  
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,param_1);
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,param_1);
  iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,param_2);
  iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,param_2);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,param_1,param_7 + param_3,param_7 + param_4)
  ;
  iVar5 = param_5 + param_3;
  iVar6 = (iVar5 - iVar1) - param_7;
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,param_1,iVar6,param_7 + param_4,'\x01');
  iVar7 = ((param_6 + param_4) - iVar2) - param_7;
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,param_1,param_7 + param_3,iVar7,'\x02');
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,param_1,iVar6,iVar7,'\x03');
  iVar8 = param_5 + iVar1 * -2 + param_7 * -2;
  iVar6 = __aeabi_idiv(iVar8,iVar3);
  iVar7 = iVar8 - iVar6 * iVar3;
  fVar11 = extraout_s0;
  if (0 < iVar6) {
    iVar10 = iVar1 + param_8 + param_3;
    iVar9 = iVar6;
    do {
      AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,param_2,iVar10,param_8 + param_4);
      fVar11 = (float)AbyssEngine::PaintCanvas::DrawImage2D
                                (Globals::Canvas,param_2,iVar10,
                                 (param_6 - param_7) + param_8 + param_4,'\x02');
      iVar10 = iVar10 + iVar3;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (0 < iVar7) {
    iVar1 = param_3 + param_8 + iVar1;
    fVar11 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                              (Globals::Canvas,param_2,0,0,iVar7,iVar4,fVar11,0,0,0,
                               iVar6 * iVar3 + iVar1);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,param_2,0,0,iVar7,iVar4,fVar11,0x40490fdb,0,0,iVar8 + iVar1);
  }
  iVar2 = param_6 + iVar2 * -2 + param_7 * -2;
  iVar1 = __aeabi_idiv(iVar2,iVar3);
  iVar2 = iVar2 - iVar1 * iVar3;
  fVar11 = extraout_s0_00;
  if (0 < iVar1) {
    do {
      fVar11 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                                (Globals::Canvas,param_2,0,0,iVar3,iVar4,fVar11,-0x4036f025,0,0,
                                 param_3 + param_8);
      fVar11 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                                (Globals::Canvas,param_2,0,0,iVar3,iVar4,fVar11,0x3fc90fdb,0,0,
                                 iVar5 + param_8);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (0 < iVar2) {
    fVar11 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                              (Globals::Canvas,param_2,0,0,iVar2,iVar4,fVar11,-0x4036f025,0,0,
                               param_3 + param_8);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,param_2,0,0,iVar2,iVar4,fVar11,0x3fc90fdb,0,0,
               iVar5 + param_8 + param_7 * -2);
  }
  return;
}

// ===== Layout::getFooterTransitionWidth  @0x000e63e0  (42 bytes)
/* Layout::getFooterTransitionWidth() */

int __thiscall Layout::getFooterTransitionWidth(Layout *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x33c));
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x334));
  return iVar2 + iVar1;
}

// ===== Layout::drawFooter  @0x000e6410  (816 bytes)
/* Layout::drawFooter(bool, bool) */

void __thiscall Layout::drawFooter(Layout *this,bool param_1,bool param_2)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  TouchButton *this_00;
  Ship *pSVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  String aSStack_60 [8];
  undefined4 local_58 [2];
  String aSStack_50 [8];
  undefined4 local_48 [2];
  AbyssEngine aAStack_40 [8];
  AbyssEngine aAStack_38 [8];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x33c));
  iVar4 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x334));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x334),*(int *)(this + 0x2dc),
             *(int *)(this + 0x2e8) + *(int *)(this + 0x2e0),'\x11','!');
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x33c),*(int *)(this + 0x2dc) + iVar4,
             (*(int *)(this + 0x2e8) + *(int *)(this + 0x2e0)) - *(int *)(Globals::layout + 0x10));
  iVar3 = iVar4 + iVar3;
  drawBGPattern(this,*(uint *)(this + 0x338),iVar3 + *(int *)(this + 0x2dc),
                (*(int *)(this + 0x2e8) + *(int *)(this + 0x2e0)) - *(int *)(Globals::layout + 0x10)
                ,*(int *)(this + 0x2e4) + iVar3 * -2,*(int *)(Globals::layout + 0x10));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x33c),
             (*(int *)(this + 0x2dc) - iVar3) + *(int *)(this + 0x2e4),
             (*(int *)(this + 0x2e8) + *(int *)(this + 0x2e0)) - *(int *)(Globals::layout + 0x10),
             '\x01');
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x334),
             *(int *)(this + 0x2e4) + (*(int *)(this + 0x2dc) - iVar4),
             (*(int *)(this + 0x2e8) + *(int *)(this + 0x2e0)) - *(int *)(Globals::layout + 0x10),
             '\x01');
  TouchButton::setVisible(*(TouchButton **)(this + 0x3b4),!param_1 && param_2);
  if (!param_1) {
    if (!param_2) goto LAB_000e6546;
    this_00 = *(TouchButton **)(this + 0x3b4);
  }
  else {
    this_00 = *(TouchButton **)(this + 0x3b8);
  }
  TouchButton::draw(this_00);
LAB_000e6546:
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  iVar3 = Ship::getCurrentLoad(pSVar5);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  iVar4 = Ship::getMaxLoad(pSVar5);
  if (iVar4 < iVar3) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  uVar6 = Ship::getCurrentLoad(pSVar5);
  local_48[0] = 0;
  AbyssEngine::String::Set(CONCAT44(uVar6,local_48));
  AbyssEngine::String::String(aSStack_50," / ",false);
  AbyssEngine::operator+(aAStack_40,(String *)local_48,aSStack_50);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  uVar6 = Ship::getMaxLoad(pSVar5);
  local_58[0] = 0;
  AbyssEngine::String::Set(CONCAT44(uVar6,local_58));
  AbyssEngine::operator+(aAStack_38,aAStack_40,(String *)local_58);
  AbyssEngine::String::String(aSStack_60,"t",false);
  AbyssEngine::operator+(aAStack_30,aAStack_38,aSStack_60);
  AbyssEngine::String::~String(aSStack_60);
  AbyssEngine::String::~String((String *)aAStack_38);
  AbyssEngine::String::~String((String *)local_58);
  AbyssEngine::String::~String((String *)aAStack_40);
  AbyssEngine::String::~String(aSStack_50);
  AbyssEngine::String::~String((String *)local_48);
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  iVar4 = *(int *)(this + 0x2dc);
  iVar8 = *(int *)(this + 0x2e4);
  iVar3 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_30);
  AbyssEngine::PaintCanvas::DrawString
            (pPVar1,uVar2,aAStack_30,(iVar4 + iVar8 / 2) - iVar3 / 2,
             (*(int *)(this + 0x2e8) + *(int *)(this + 0x2e0)) - *(int *)(this + 0x14),false);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  Status::getCredits(Globals::status);
  formatCredits((int)aAStack_38);
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  iVar3 = *(int *)(this + 0x2dc);
  iVar4 = *(int *)(this + 0x2e4);
  if (param_1) {
    iVar7 = *(int *)(Globals::layout + 0x74);
    iVar8 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_38);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar2,aAStack_38,((iVar4 + iVar3) - iVar7) - iVar8 / 2,
               (*(int *)(this + 0x2e8) + *(int *)(this + 0x2e0)) - *(int *)(this + 0x14),false);
  }
  else {
    iVar8 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_38);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar2,aAStack_38,(iVar4 + iVar3 + -10) - iVar8,
               (*(int *)(this + 0x2e8) + *(int *)(this + 0x2e0)) - *(int *)(this + 0x14),false);
  }
  AbyssEngine::String::~String((String *)aAStack_38);
  AbyssEngine::String::~String((String *)aAStack_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::drawFooter  @0x000e67d4  (8 bytes)
/* Layout::drawFooter() */

void __thiscall Layout::drawFooter(Layout *this)

{
  drawFooter(this,false,true);
  return;
}

// ===== Layout::drawEmptyFooter  @0x000e67dc  (194 bytes)
/* Layout::drawEmptyFooter(bool) */

void __thiscall Layout::drawEmptyFooter(Layout *this,bool param_1)

{
  int iVar1;
  
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x340));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x334),0,Globals::h,'\x11','!');
  drawBGPattern(this,*(uint *)(this + 0x344),iVar1,Globals::h - *(int *)(Globals::layout + 0x10),
                Globals::w + iVar1 * -2,*(int *)(Globals::layout + 0x10));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x334),Globals::w - iVar1,
             Globals::h - *(int *)(Globals::layout + 0x10),'\x01');
  if (!param_1) {
    return;
  }
  TouchButton::setVisible(*(TouchButton **)(this + 0x3b4),true);
  TouchButton::draw(*(TouchButton **)(this + 0x3b4));
  return;
}

// ===== Layout::drawFooterNoBackButton  @0x000e68b0  (8 bytes)
/* Layout::drawFooterNoBackButton() */

void __thiscall Layout::drawFooterNoBackButton(Layout *this)

{
  drawFooter(this,false,false);
  return;
}

// ===== Layout::drawFooterStation  @0x000e68b8  (10 bytes)
/* Layout::drawFooterStation() */

void __thiscall Layout::drawFooterStation(Layout *this)

{
  drawFooter(this,true,false);
  return;
}

// ===== Layout::drawHeader  @0x000e68c0  (70 bytes)
/* Layout::drawHeader() */

void __thiscall Layout::drawHeader(Layout *this)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_1c,"",false);
  drawHeader(this,aSStack_1c,0);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::drawHeader  @0x000e6920  (246 bytes)
/* Layout::drawHeader(AbyssEngine::String, bool) */

void __thiscall Layout::drawHeader(Layout *this,String *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x330));
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x330));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x330),*(int *)(this + 0x2dc),*(int *)(this + 0x2e0));
  drawBGPattern(this,*(uint *)(this + 0x328),*(int *)(this + 0x2dc) + iVar1,*(int *)(this + 0x2e0),
                *(int *)(this + 0x2e4) + iVar1 * -2,iVar2);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x330),*(int *)(this + 0x2dc) + *(int *)(this + 0x2e4)
             ,*(int *)(this + 0x2e0),iVar1,iVar2,'\x11','\x12','\x01');
  if (*(int *)(param_2 + 4) != 0) {
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x32c),*(int *)(this + 0x2dc),*(int *)(this + 0x2e0)
              );
    AbyssEngine::PaintCanvas::DrawString
              (Globals::Canvas,Globals::font,param_2,
               *(int *)(Globals::layout + 0x28) +
               *(int *)(Globals::layout + 0x44) + *(int *)(this + 0x2dc),
               *(int *)(this + 0x18) + *(int *)(this + 0x2e0),false);
  }
  this[0x3cc] = SUB41(param_3,0);
  if ((param_3 != 0) && (*this == (Layout)0x0)) {
    TouchButton::draw(*(TouchButton **)(this + 0x3bc));
    return;
  }
  return;
}

// ===== Layout::drawHeader  @0x000e6a24  (66 bytes)
/* Layout::drawHeader(AbyssEngine::String) */

void __thiscall Layout::drawHeader(Layout *this,String *param_2)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_1c,param_2,false);
  drawHeader(this,aSStack_1c,1);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::drawScrollBar  @0x000e6a7c  (286 bytes)
/* Layout::drawScrollBar(int, int, int, int, int) */

void __thiscall
Layout::drawScrollBar(Layout *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x374));
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x374));
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawRectangle
            (Globals::Canvas,param_1,*(int *)(this + 0x3e0) + param_2,
             *(int *)(Globals::layout + 0x48),param_3 + *(int *)(this + 0x3e0) * -2);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar5 = param_5 + -1;
  if (param_5 + -1 <= iVar2 * 2) {
    iVar5 = iVar2 * 2;
  }
  iVar4 = param_4 + 1;
  if (param_3 <= iVar5 + iVar4) {
    iVar4 = (param_3 - iVar5) - *(int *)(this + 0x3e0);
  }
  iVar3 = *(int *)(this + 0x3e4);
  iVar5 = iVar5 + iVar3 * -4;
  iVar4 = iVar4 + iVar3 * 2;
  if (iVar2 * 2 < iVar5) {
    drawBGPattern(this,*(uint *)(this + 0x378),param_1 + 1 + iVar3,iVar2 + param_2 + iVar4,iVar1,
                  iVar5 + iVar2 * -2);
    iVar3 = *(int *)(this + 0x3e4);
  }
  else {
    iVar1 = param_3 + iVar2 * -2;
    if (iVar1 <= iVar4) {
      iVar4 = iVar1;
    }
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x374),iVar3 + param_1 + 1,param_2 + iVar4);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x374),*(int *)(this + 0x3e4) + param_1 + 1,
             (iVar5 - iVar2) + param_2 + iVar4,'\x02');
  return;
}

// ===== Layout::drawBox  @0x000e6ba8  (1400 bytes)
/* Layout::drawBox(int, int, int, int, int, AbyssEngine::String, unsigned char) */

void __thiscall
Layout::drawBox(Layout *this,undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
               String *param_7,uint param_8)

{
  Layout *this_00;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  switch(param_1) {
  case 0:
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x348));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x348),param_2,param_3);
    drawBGPattern(this,*(uint *)(this + 0x34c),iVar1 + param_2,param_3,param_4 + iVar1 * -2,param_5)
    ;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x348),(param_4 + param_2) - iVar1,param_3,'\x01');
    if (*(int *)(param_7 + 4) == 0) goto switchD_000e6be0_default;
    iVar1 = *(int *)(Globals::layout + 0x44);
    if ((param_8 & 2) == 0) {
      if ((param_8 & 4) != 0) {
        iVar1 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_7);
        iVar1 = param_4 / 2 - iVar1 / 2;
      }
    }
    else {
      iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_7);
      iVar1 = (param_4 - iVar1) - iVar4;
    }
    iVar4 = (param_3 + (*(int *)(Globals::layout + 0x1c) >> 1) + 1) - *(int *)(this + 0x3ac);
    break;
  case 1:
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x350));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x350),param_2,param_3);
    drawBGPattern(this,*(uint *)(this + 0x354),iVar1 + param_2,param_3,param_4 + iVar1 * -2,param_5)
    ;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x350),(param_4 + param_2) - iVar1,param_3,'\x01');
    if (*(int *)(param_7 + 4) == 0) goto switchD_000e6be0_default;
    iVar1 = *(int *)(Globals::layout + 0x44);
    if ((param_8 & 2) == 0) {
      if ((param_8 & 4) != 0) {
        iVar1 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_7);
        iVar1 = param_4 / 2 - iVar1 / 2;
      }
    }
    else {
      iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_7);
      iVar1 = (param_4 - iVar1) - iVar4;
    }
    iVar4 = (param_3 + (*(int *)(Globals::layout + 0x5c) >> 1) + 1) - *(int *)(this + 0x3ac);
    break;
  case 2:
    drawBGPattern(this,*(uint *)(this + 0x324),param_2,param_3,param_4,param_5);
    goto switchD_000e6be0_default;
  case 3:
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x358));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x358),param_2,param_3);
    drawBGPattern(this,*(uint *)(this + 0x35c),iVar1 + param_2,param_3,param_4 + iVar1 * -2,param_5)
    ;
    uVar2 = *(uint *)(this + 0x358);
    goto LAB_000e7020;
  case 4:
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x36c));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x36c),param_2,param_3);
    drawBGPattern(this,*(uint *)(this + 0x370),iVar1 + param_2,param_3,param_4 + iVar1 * -2,param_5)
    ;
    uVar2 = *(uint *)(this + 0x36c);
    goto LAB_000e7020;
  case 5:
    uVar2 = *(uint *)(this + 0x380);
    uVar3 = *(uint *)(this + 900);
    goto LAB_000e6f82;
  case 6:
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x388));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x388),param_2,param_3);
    drawBGPattern(this,*(uint *)(this + 0x38c),iVar1 + param_2,param_3,param_4 + iVar1 * -2,param_5)
    ;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x388),(param_4 + param_2) - iVar1,param_3,'\x01');
    if (*(int *)(param_7 + 4) == 0) goto switchD_000e6be0_default;
    iVar1 = *(int *)(Globals::layout + 0x44);
    if ((param_8 & 2) == 0) {
      if ((param_8 & 4) != 0) {
        iVar1 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_7);
        iVar1 = param_4 / 2 - iVar1 / 2;
      }
    }
    else {
      iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_7);
      iVar1 = (param_4 - iVar1) - iVar4;
    }
    iVar4 = (param_3 + (param_5 >> 1) + 1) - *(int *)(this + 0x3ac);
    break;
  case 7:
    drawBGPattern(this,*(uint *)(this + 0x324),param_2,*(int *)(Globals::layout + 8) + param_3,
                  param_4,param_5 - *(int *)(Globals::layout + 8));
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x394));
    this_00 = (Layout *)-iVar1;
    drawBGBorder(this_00,*(uint *)(this + 0x390),*(uint *)(this + 0x394),param_2,
                 *(int *)(Globals::layout + 8) + param_3,param_4,
                 param_5 - *(int *)(Globals::layout + 8),(int)this_00,(int)this_00);
    if (*(int *)(param_7 + 4) == 0) goto switchD_000e6be0_default;
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x32c),param_2,param_3);
    iVar1 = *(int *)(Globals::layout + 0x28);
    iVar4 = (param_3 + *(int *)(Globals::layout + 8) / 2 + 1) - *(int *)(this + 0x3ac);
    break;
  case 8:
    uVar2 = *(uint *)(this + 0x39c);
    uVar3 = *(uint *)(this + 0x3a0);
LAB_000e6f82:
    drawBGBorder((Layout *)0x0,uVar2,uVar3,param_2,param_3,param_4,param_5,0,0);
    goto switchD_000e6be0_default;
  case 9:
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x360));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x360),param_2,param_3);
    drawBGPattern(this,*(uint *)(this + 0x364),iVar1 + param_2,param_3,param_4 + iVar1 * -2,param_5)
    ;
    uVar2 = *(uint *)(this + 0x360);
    goto LAB_000e7020;
  case 10:
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x368));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x368),param_2,param_3);
    drawBGPattern(this,*(uint *)(this + 0x370),iVar1 + param_2,param_3,param_4 + iVar1 * -2,param_5)
    ;
    uVar2 = *(uint *)(this + 0x368);
LAB_000e7020:
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,uVar2,(param_4 + param_2) - iVar1,param_3,'\x01');
  default:
    goto switchD_000e6be0_default;
  }
  AbyssEngine::PaintCanvas::DrawString
            (Globals::Canvas,Globals::font,param_7,iVar1 + param_2,iVar4,false);
switchD_000e6be0_default:
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  return;
}

// ===== Layout::drawBox  @0x000e71cc  (92 bytes)
/* Layout::drawBox(int, int, int, int, int, AbyssEngine::String) */

void __thiscall
Layout::drawBox(Layout *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,
               undefined4 param_4,undefined4 param_5,String *param_7)

{
  undefined4 uVar1;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar1 = AbyssEngine::String::String(aSStack_24,param_7,false);
  drawBox(this,param_1,param_2,param_3,param_4,param_5,uVar1,1);
  AbyssEngine::String::~String(aSStack_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::initTip  @0x000e7240  (168 bytes)
/* Layout::initTip() */

void __thiscall Layout::initTip(Layout *this)

{
  PaintCanvas *this_00;
  GameText *this_01;
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  String *pSVar5;
  void *pvVar6;
  
  if (*(Array **)(this + 0x3c8) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x3c8));
    pvVar6 = *(void **)(this + 0x3c8);
    if (pvVar6 != (void *)0x0) {
      if (*(void **)((int)pvVar6 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar6 + 4));
      }
      operator_delete(pvVar6);
    }
    *(undefined4 *)(this + 0x3c8) = 0;
  }
  puVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  puVar2[1] = puVar3;
  puVar2[2] = 1;
  *puVar3 = 0;
  *puVar2 = 0;
  *(undefined4 **)(this + 0x3c8) = puVar2;
  uVar1 = Globals::font;
  this_01 = Globals::gameText;
  this_00 = Globals::Canvas;
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xd);
  pSVar5 = (String *)GameText::getText(this_01,iVar4 + 0x154);
  AbyssEngine::PaintCanvas::GetLineArray
            (this_00,uVar1,pSVar5,
             *(int *)(Globals::layout + 0x78) + *(int *)(Globals::layout + 0x4c) * -2,
             *(Array **)(this + 0x3c8));
  return;
}

// ===== Layout::drawTip  @0x000e730c  (256 bytes)
/* Layout::drawTip() */

void __thiscall Layout::drawTip(Layout *this)

{
  Layout *pLVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (*(int *)(this + 0x3c8) != 0) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    iVar3 = Globals::w;
    iVar2 = Globals::h;
    pLVar1 = Globals::layout;
    iVar5 = *(int *)(Globals::layout + 0x78);
    uVar4 = AbyssEngine::String::String(aSStack_2c,"",false);
    drawBox(pLVar1,5,(iVar3 >> 1) - (iVar5 >> 1),(iVar2 >> 1) + 0xd,iVar5,100,uVar4);
    AbyssEngine::String::~String(aSStack_2c);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x398),Globals::w >> 1,(Globals::h >> 1) + 0x3f,
               '\x11','D');
    Globals::drawLines(Globals::globals,Globals::font,*(Array **)(this + 0x3c8),Globals::w >> 1,
                       ((Globals::h >> 1) + 0x3f) -
                       ((uint)(*(int *)(Globals::layout + 4) * *(int *)*(Array **)(this + 0x3c8)) >>
                       1),true);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::initHelpWindow  @0x000e7450  (102 bytes)
/* Layout::initHelpWindow(AbyssEngine::String) */

void Layout::initHelpWindow(float param_1,undefined1 *param_2,String *param_3)

{
  ChoiceWindow *pCVar1;
  String *pSVar2;
  
  if (*(int *)(param_2 + 0x3c4) == 0) {
    pCVar1 = operator_new(0x54);
    param_1 = (float)ChoiceWindow::ChoiceWindow(pCVar1);
    *(ChoiceWindow **)(param_2 + 0x3c4) = pCVar1;
  }
  FModSound::play(Globals::sound,0x7e,(Vector *)0x0,(Vector *)0x0,param_1);
  pCVar1 = *(ChoiceWindow **)(param_2 + 0x3c4);
  pSVar2 = (String *)GameText::getText(Globals::gameText,0x187);
  ChoiceWindow::set(pCVar1,pSVar2,param_3,false);
  param_2[0x3c0] = 0;
  *param_2 = 1;
  return;
}

// ===== Layout::drawHelpWindow  @0x000e74cc  (10 bytes)
/* Layout::drawHelpWindow() */

void Layout::drawHelpWindow(void)

{
  int in_r0;
  
  ChoiceWindow::draw(*(ChoiceWindow **)(in_r0 + 0x3c4));
  return;
}

// ===== Layout::helpPressed  @0x000e74d4  (6 bytes)
/* Layout::helpPressed() */

Layout __thiscall Layout::helpPressed(Layout *this)

{
  return this[0x3c0];
}

// ===== Layout::getHelpButtonOffset  @0x000e74dc  (26 bytes)
/* Layout::getHelpButtonOffset() */

int __thiscall Layout::getHelpButtonOffset(Layout *this)

{
  int iVar1;
  
  iVar1 = TouchButton::getWidth(*(TouchButton **)(this + 0x3bc));
  return iVar1 - *(int *)(Globals::layout + 0x38);
}

// ===== Layout::getPulseValue  @0x000e74fc  (108 bytes)
/* Layout::getPulseValue(float) */

float __thiscall Layout::getPulseValue(Layout *this,float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float in_r1;
  
  Status::getPlayingTime(Globals::status);
  fVar1 = (float)__aeabi_l2f();
  fVar2 = (float)AbyssEngine::AEMath::Sinf(fVar1 * in_r1);
  Status::getPlayingTime(Globals::status);
  fVar1 = (float)__aeabi_l2f();
  fVar3 = (float)AbyssEngine::AEMath::Sinf(fVar1 * in_r1);
  fVar1 = -fVar3;
  if (0.0 < fVar2) {
    fVar1 = fVar3;
  }
  return fVar1;
}

// ===== Layout::setWindowDimensions  @0x000e756c  (198 bytes)
/* Layout::setWindowDimensions(int, int, int, int) */

void __thiscall
Layout::setWindowDimensions(Layout *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float local_2c;
  float local_24;
  
  iVar1 = __stack_chk_guard;
  *(int *)(this + 0x2dc) = param_1;
  *(int *)(this + 0x2e0) = param_2;
  *(int *)(this + 0x2e4) = param_3;
  *(int *)(this + 0x2e8) = param_4;
  TouchButton::setPosition(*(TouchButton **)(this + 0x3bc),param_1 + param_3,param_2,'\x12');
  TouchButton::setPosition
            (*(TouchButton **)(this + 0x3b4),
             *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x2dc),
             (*(int *)(this + 0x2e0) + *(int *)(this + 0x2e8)) - *(int *)(this + 0x3fc),'!');
  TouchButton::setPosition
            (*(TouchButton **)(this + 0x3b8),
             *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x2dc),
             (*(int *)(this + 0x2e0) + *(int *)(this + 0x2e8)) - *(int *)(this + 0x3fc),'!');
  if (*(int *)(this + 0x3b4) != 0) {
    TouchButton::getPosition();
    Globals::other_buttons_x._0_4_ = (undefined4)local_24;
    TouchButton::getPosition();
    Globals::other_buttons_y._0_4_ = (undefined4)local_2c;
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Layout::showMissionRewardMessage  @0x000e7648  (54 bytes)
/* Layout::showMissionRewardMessage(int, bool) */

void Layout::showMissionRewardMessage(int param_1,bool param_2)

{
  undefined1 in_r2;
  float in_s0;
  
  if (param_2 != 0) {
    *(undefined1 *)(param_1 + 0x2ec) = 1;
    *(undefined1 *)(param_1 + 0x2ed) = in_r2;
    *(undefined4 *)(param_1 + 0x3d0) = 0;
    *(uint *)(param_1 + 0x3d4) = (uint)param_2;
    FModSound::play(Globals::sound,0x24,(Vector *)0x0,(Vector *)0x0,in_s0);
    return;
  }
  return;
}

// ===== Layout::drawMissionRewardMessage  @0x000e7684  (574 bytes)
/* Layout::drawMissionRewardMessage(bool) */

void __thiscall Layout::drawMissionRewardMessage(Layout *this,bool param_1)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  String *pSVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint in_fpscr;
  String aSStack_58 [8];
  String aSStack_50 [8];
  AbyssEngine aAStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (this[0x2ec] == (Layout)0x0) goto LAB_000e78aa;
  uVar3 = AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  uVar4 = *(undefined4 *)(this + 0x3b0);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar5 = *(int *)(this + 0x3d0);
  if (iVar5 < 2000) {
LAB_000e76da:
    VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
  }
  else if (5000 < iVar5) {
    iVar5 = 7000 - iVar5;
    goto LAB_000e76da;
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  uVar6 = AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  *(undefined4 *)(this + 0x3b0) = uVar6;
  iVar5 = Globals::w;
  iVar8 = *(int *)(this + 0x3f0);
  iVar11 = *(int *)(this + 0x3f4);
  if (param_1) {
    uVar10 = *(undefined4 *)(this + 1000);
    iVar9 = *(int *)(this + 0x3ec);
    uVar6 = AbyssEngine::String::String(aSStack_30,"",false);
    drawBox(this,2,(iVar5 >> 1) - (iVar9 >> 1),iVar8,iVar9,uVar10,uVar6,uVar4,uVar3);
    AbyssEngine::String::~String(aSStack_30);
    iVar5 = Globals::w;
    uVar3 = AbyssEngine::String::String(aSStack_38,"",false);
    drawBox(this,8,(iVar5 >> 1) - (iVar9 >> 1),iVar8,iVar9,uVar10,uVar3);
    AbyssEngine::String::~String(aSStack_38);
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x3a4),Globals::w >> 1,iVar8,'\x11','\x14');
  if (this[0x2ed] == (Layout)0x0) {
    iVar5 = 0xd8;
  }
  else {
    iVar5 = 0xc86;
  }
  pSVar7 = (String *)GameText::getText(Globals::gameText,iVar5);
  AbyssEngine::String::String(aSStack_40,pSVar7,false);
  iVar5 = Globals::w;
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  iVar9 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_40);
  AbyssEngine::PaintCanvas::DrawString
            (pPVar1,uVar2,aSStack_40,(iVar5 >> 1) - (iVar9 >> 1),iVar8 + iVar11,false);
  AbyssEngine::String::String(aSStack_50,"+ ",false);
  formatCredits((int)aSStack_58);
  AbyssEngine::operator+(aAStack_48,aSStack_50,aSStack_58);
  AbyssEngine::String::operator=(aSStack_40,aAStack_48);
  AbyssEngine::String::~String((String *)aAStack_48);
  AbyssEngine::String::~String(aSStack_58);
  AbyssEngine::String::~String(aSStack_50);
  iVar5 = Globals::w;
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  iVar11 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_40);
  AbyssEngine::PaintCanvas::DrawString
            (pPVar1,uVar2,aSStack_40,(iVar5 >> 1) - (iVar11 >> 1),*(int *)(this + 0x3f8) + iVar8,
             false);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  *(undefined4 *)(this + 0x3b0) = uVar4;
  AbyssEngine::String::~String(aSStack_40);
LAB_000e78aa:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Layout::startFade  @0x000e7950  (32 bytes)
/* Layout::startFade(bool, int, int) */

void __thiscall Layout::startFade(Layout *this,bool param_1,int param_2,int param_3)

{
  this[0x400] = (Layout)0x1;
  this[0x401] = (Layout)param_1;
  *(uint *)(this + 0x404) = param_2 & 0xffffff00;
  *(undefined4 *)(this + 0x408) = 0;
  *(int *)(this + 0x40c) = param_3;
  return;
}

// ===== Layout::enableFillScreen  @0x000e7970  (6 bytes)
/* Layout::enableFillScreen(bool) */

void __thiscall Layout::enableFillScreen(Layout *this,bool param_1)

{
  this[0x410] = (Layout)param_1;
  return;
}

// ===== Layout::drawFade  @0x000e7978  (238 bytes)
/* Layout::drawFade() */

Layout __thiscall Layout::drawFade(Layout *this)

{
  uint in_fpscr;
  
  if (this[0x400] != (Layout)0x0) {
    AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
    VectorSignedToFloat(*(undefined4 *)(this + 0x40c),(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(*(undefined4 *)(this + 0x408),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::FillRectangle(Globals::Canvas,0,0,Globals::w,Globals::h);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  if (this[0x410] != (Layout)0x0) {
    AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::FillRectangle(Globals::Canvas,0,0,Globals::w,Globals::h);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  return this[0x400];
}

// ===== Layout::isFading  @0x000e7a84  (6 bytes)
/* Layout::isFading() */

Layout __thiscall Layout::isFading(Layout *this)

{
  return this[0x400];
}

// ===== Layout::update  @0x000e7a8a  (86 bytes)
/* Layout::update(int) */

void __thiscall Layout::update(Layout *this,int param_1)

{
  int iVar1;
  
  if (*(int *)(this + 0x3c4) != 0) {
    ChoiceWindow::update(*(int *)(this + 0x3c4));
  }
  if ((this[0x2ec] != (Layout)0x0) &&
     (iVar1 = *(int *)(this + 0x3d0), *(int *)(this + 0x3d0) = iVar1 + param_1,
     6999 < iVar1 + param_1)) {
    this[0x2ec] = (Layout)0x0;
  }
  if ((this[0x400] != (Layout)0x0) &&
     (iVar1 = *(int *)(this + 0x408), *(int *)(this + 0x408) = iVar1 + param_1,
     *(int *)(this + 0x40c) < iVar1 + param_1)) {
    this[0x400] = (Layout)0x0;
    *(undefined4 *)(this + 0x408) = 0;
  }
  return;
}

// ===== Layout::OnTouchBegin  @0x000e7ae0  (84 bytes)
/* Layout::OnTouchBegin(int, int) */

undefined4 __thiscall Layout::OnTouchBegin(Layout *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  TouchButton *this_00;
  
  if (this[0x3cc] != (Layout)0x0) {
    TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x3bc),param_1,param_2);
  }
  if ((*(ChoiceWindow **)(this + 0x3c4) == (ChoiceWindow *)0x0) || (*this == (Layout)0x0)) {
    iVar2 = TouchButton::isVisible(*(TouchButton **)(this + 0x3b4));
    if (iVar2 == 1) {
      this_00 = *(TouchButton **)(this + 0x3b4);
    }
    else {
      this_00 = *(TouchButton **)(this + 0x3b8);
    }
    uVar1 = TouchButton::OnTouchBegin(this_00,param_1,param_2);
  }
  else {
    ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(this + 0x3c4),param_1,param_2);
    uVar1 = 0;
  }
  return uVar1;
}

// ===== Layout::OnTouchMove  @0x000e7b34  (84 bytes)
/* Layout::OnTouchMove(int, int) */

undefined4 __thiscall Layout::OnTouchMove(Layout *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  TouchButton *this_00;
  
  if (this[0x3cc] != (Layout)0x0) {
    TouchButton::OnTouchMove(*(TouchButton **)(this + 0x3bc),param_1,param_2);
  }
  if ((*(ChoiceWindow **)(this + 0x3c4) == (ChoiceWindow *)0x0) || (*this == (Layout)0x0)) {
    iVar2 = TouchButton::isVisible(*(TouchButton **)(this + 0x3b4));
    if (iVar2 == 1) {
      this_00 = *(TouchButton **)(this + 0x3b4);
    }
    else {
      this_00 = *(TouchButton **)(this + 0x3b8);
    }
    uVar1 = TouchButton::OnTouchMove(this_00,param_1,param_2);
  }
  else {
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 0x3c4),param_1,param_2);
    uVar1 = 0;
  }
  return uVar1;
}

// ===== Layout::OnTouchEnd  @0x000e7b88  (100 bytes)
/* Layout::OnTouchEnd(int, int) */

uint __thiscall Layout::OnTouchEnd(Layout *this,int param_1,int param_2)

{
  Layout LVar1;
  int iVar2;
  TouchButton *this_00;
  uint uVar3;
  
  if ((*this == (Layout)0x0) && (this[0x3cc] != (Layout)0x0)) {
    LVar1 = (Layout)TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x3bc),param_1,param_2);
    this[0x3c0] = LVar1;
  }
  if ((*(ChoiceWindow **)(this + 0x3c4) == (ChoiceWindow *)0x0) || (*this == (Layout)0x0)) {
    iVar2 = TouchButton::isVisible(*(TouchButton **)(this + 0x3b4));
    if (iVar2 == 1) {
      this_00 = *(TouchButton **)(this + 0x3b4);
    }
    else {
      this_00 = *(TouchButton **)(this + 0x3b8);
    }
    uVar3 = TouchButton::OnTouchEnd(this_00,param_1,param_2);
  }
  else {
    iVar2 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x3c4),param_1,param_2);
    uVar3 = (uint)(iVar2 == 0);
  }
  return uVar3;
}

