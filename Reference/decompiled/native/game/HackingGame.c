// Class: HackingGame
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== HackingGame::HackingGame  @0x00179638  (220 bytes)
/* HackingGame::HackingGame(int, int, int, int, int) */

HackingGame * __thiscall
HackingGame::HackingGame
          (HackingGame *this,int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  
  *(int *)(this + 0x124) = param_1;
  iVar2 = -0x18;
  uVar3 = 0x1f50;
  do {
    iVar1 = iVar2 + param_1 * 0x30;
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar3 - 6,(uint *)(this + iVar1 + 100));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar3,(uint *)(this + iVar1 + 0x7c));
    uVar3 = uVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar2 != 0);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f48,(uint *)(this + 0x114));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f49,(uint *)(this + 0x10c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f47,(uint *)(this + 0x110));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f46,(uint *)(this + 0x118));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f44,(uint *)(this + 0x11c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f45,(uint *)(this + 0x120));
  *(int *)this = param_2;
  *(int *)(this + 0x134) = param_3;
  *(int *)(this + 0x138) = param_4;
  *(int *)(this + 0x13c) = param_5;
  reInit(this);
  return this;
}

// ===== HackingGame::reInit  @0x00179720  (444 bytes)
/* HackingGame::reInit() */

void __thiscall HackingGame::reInit(HackingGame *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x130) = 0;
  iVar1 = *(int *)this;
  if (iVar1 == 1) {
    iVar1 = 0;
    do {
      *(int *)(this + iVar1 * 4 + 4) = iVar1 / 2;
      iVar1 = iVar1 + 1;
    } while (iVar1 != 6);
  }
  else {
    if (iVar1 == 2) {
      iVar1 = 0;
      do {
        *(int *)(this + iVar1 * 4 + 4) = iVar1;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 4);
      uVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
      *(undefined4 *)(this + 0x14) = uVar2;
      iVar1 = 4;
    }
    else {
      if (iVar1 != 3) {
        iVar1 = 0;
        do {
          *(int *)(this + iVar1 * 4 + 4) = iVar1;
          iVar1 = iVar1 + 1;
        } while (iVar1 != 6);
        goto LAB_001797b0;
      }
      iVar1 = 0;
      do {
        *(int *)(this + iVar1 * 4 + 4) = iVar1;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 5);
      iVar1 = 5;
    }
    uVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar1);
    *(undefined4 *)(this + 0x18) = uVar2;
  }
LAB_001797b0:
  iVar1 = 0x28;
  do {
    iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
    iVar1 = iVar1 + -1;
    uVar2 = *(undefined4 *)(this + iVar3 * 4 + 4);
    *(undefined4 *)(this + iVar3 * 4 + 4) = *(undefined4 *)(this + iVar4 * 4 + 4);
    *(undefined4 *)(this + iVar4 * 4 + 4) = uVar2;
  } while (iVar1 != 0);
  iVar1 = 0;
  do {
    iVar3 = iVar1 + 1;
    *(undefined4 *)(this + iVar1 * 4 + 0x1c) = *(undefined4 *)(this + iVar1 * 4 + 4);
    *(undefined4 *)(this + iVar1 * 4 + 0x34) = *(undefined4 *)(this + iVar1 * 4 + 4);
    iVar1 = iVar3;
  } while (iVar3 != 6);
  if (0 < *(int *)this) {
    uVar6 = 0;
    do {
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      if (-1 < iVar1) {
        iVar1 = iVar1 + 1;
        do {
          if ((uVar6 & 1) == 0) {
            if (*(int *)(this + 0x130) == 0) {
              uVar2 = *(undefined4 *)(this + 0x44);
              *(undefined4 *)(this + 0x44) = *(undefined4 *)(this + 0x48);
              *(undefined4 *)(this + 0x48) = *(undefined4 *)(this + 0x3c);
              uVar5 = *(undefined4 *)(this + 0x38);
              *(undefined4 *)(this + 0x38) = uVar2;
              *(undefined4 *)(this + 0x3c) = uVar5;
              this[0x129] = (HackingGame)0x1;
LAB_00179862:
              *(undefined4 *)(this + 300) = 0;
            }
          }
          else if (*(int *)(this + 0x130) == 0) {
            uVar2 = *(undefined4 *)(this + 0x40);
            *(undefined4 *)(this + 0x40) = *(undefined4 *)(this + 0x44);
            *(undefined4 *)(this + 0x44) = *(undefined4 *)(this + 0x38);
            uVar5 = *(undefined4 *)(this + 0x34);
            *(undefined4 *)(this + 0x34) = uVar2;
            *(undefined4 *)(this + 0x38) = uVar5;
            this[0x128] = (HackingGame)0x1;
            goto LAB_00179862;
          }
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      iVar1 = *(int *)this;
      if (uVar6 == iVar1 * 2 - 1U) {
        local_40 = *(undefined8 *)(this + 0x34);
        uStack_38 = *(undefined8 *)(this + 0x3c);
        local_30 = *(undefined8 *)(this + 0x44);
        iVar3 = solvableInNSteps(this,iVar1,0,0,0,(int *)&local_40);
        iVar1 = *(int *)this;
        if (iVar3 != 0) {
          uVar6 = 0;
        }
      }
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < iVar1 * 2);
  }
  iVar1 = 0;
  do {
    iVar3 = iVar1 + 1;
    *(undefined4 *)(this + iVar1 * 4 + 0x1c) = *(undefined4 *)(this + iVar1 * 4 + 0x34);
    iVar1 = iVar3;
  } while (iVar3 != 6);
  *(undefined2 *)(this + 0x128) = 0;
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== HackingGame::~HackingGame  @0x001798f4  (2 bytes)
/* HackingGame::~HackingGame() */

HackingGame * __thiscall HackingGame::~HackingGame(HackingGame *this)

{
  return this;
}

// ===== HackingGame::getRewardItem  @0x001798f6  (6 bytes)
/* HackingGame::getRewardItem() */

undefined4 __thiscall HackingGame::getRewardItem(HackingGame *this)

{
  return *(undefined4 *)(this + 0x134);
}

// ===== HackingGame::getRewardAmount  @0x001798fc  (6 bytes)
/* HackingGame::getRewardAmount() */

undefined4 __thiscall HackingGame::getRewardAmount(HackingGame *this)

{
  return *(undefined4 *)(this + 0x138);
}

// ===== HackingGame::rotateRightCW  @0x00179904  (74 bytes)
/* HackingGame::rotateRightCW(bool) */

void HackingGame::rotateRightCW(bool param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_r1;
  undefined4 uVar3;
  float in_s0;
  
  uVar1 = (uint)param_1;
  if (*(int *)(uVar1 + 0x130) == 0) {
    if (in_r1 == 1) {
      FModSound::play(Globals::sound,0x8e2,(Vector *)0x0,(Vector *)0x0,in_s0);
    }
    uVar2 = *(undefined4 *)(uVar1 + 0x44);
    *(undefined4 *)(uVar1 + 0x44) = *(undefined4 *)(uVar1 + 0x48);
    *(undefined4 *)(uVar1 + 0x48) = *(undefined4 *)(uVar1 + 0x3c);
    uVar3 = *(undefined4 *)(uVar1 + 0x38);
    *(undefined4 *)(uVar1 + 0x38) = uVar2;
    *(undefined4 *)(uVar1 + 0x3c) = uVar3;
    *(undefined1 *)(uVar1 + 0x129) = 1;
    *(undefined4 *)(uVar1 + 300) = 0;
  }
  return;
}

// ===== HackingGame::rotateLeftCW  @0x00179954  (74 bytes)
/* HackingGame::rotateLeftCW(bool) */

void HackingGame::rotateLeftCW(bool param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_r1;
  undefined4 uVar3;
  float in_s0;
  
  uVar1 = (uint)param_1;
  if (*(int *)(uVar1 + 0x130) == 0) {
    if (in_r1 == 1) {
      FModSound::play(Globals::sound,0x8e2,(Vector *)0x0,(Vector *)0x0,in_s0);
    }
    uVar2 = *(undefined4 *)(uVar1 + 0x40);
    *(undefined4 *)(uVar1 + 0x40) = *(undefined4 *)(uVar1 + 0x44);
    *(undefined4 *)(uVar1 + 0x44) = *(undefined4 *)(uVar1 + 0x38);
    uVar3 = *(undefined4 *)(uVar1 + 0x34);
    *(undefined4 *)(uVar1 + 0x34) = uVar2;
    *(undefined4 *)(uVar1 + 0x38) = uVar3;
    *(undefined1 *)(uVar1 + 0x128) = 1;
    *(undefined4 *)(uVar1 + 300) = 0;
  }
  return;
}

// ===== HackingGame::solvableInNSteps  @0x001799a4  (232 bytes)
/* HackingGame::solvableInNSteps(int, int, int, int, int*) */

void __thiscall
HackingGame::solvableInNSteps
          (HackingGame *this,int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int *piVar9;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  int local_20;
  
  piVar9 = (int *)&local_38;
  local_20 = __stack_chk_guard;
  uVar6 = *(undefined8 *)param_5;
  uVar8 = *(undefined8 *)(param_5 + 2);
  local_28 = *(undefined8 *)(param_5 + 4);
  uVar7 = *(undefined8 *)param_5;
  local_48 = *(undefined8 *)(param_5 + 2);
  local_40 = *(undefined8 *)(param_5 + 4);
  iVar5 = 0;
  do {
    local_50 = uVar7;
    local_38 = uVar6;
    uStack_30 = uVar8;
    if (param_5[iVar5] != *(int *)(this + iVar5 * 4 + 4)) {
      if (param_1 <= param_2) goto LAB_00179a1e;
      iVar5 = 0;
      goto LAB_00179a0c;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  uVar3 = 1;
  goto LAB_00179a74;
  while( true ) {
    if (param_4 < 3) {
      uVar2 = (undefined4)local_40;
      local_40._4_4_ = (undefined4)((ulonglong)local_40 >> 0x20);
      local_40 = CONCAT44((undefined4)local_48,local_40._4_4_);
      local_50._4_4_ = (undefined4)((ulonglong)uVar7 >> 0x20);
      uVar3 = local_50._4_4_;
      local_50 = CONCAT44(uVar2,(int)uVar7);
      uVar1 = (ulonglong)local_48 >> 0x20;
      local_48 = CONCAT44((int)uVar1,uVar3);
      this[0x129] = (HackingGame)0x1;
      *(undefined4 *)(this + 300) = 0;
      iVar5 = param_4 + 1;
      iVar4 = 0;
      piVar9 = (int *)&local_50;
      goto LAB_00179a70;
    }
    iVar5 = iVar5 + 1;
    if (1 < iVar5) break;
LAB_00179a0c:
    if ((param_3 < 3) && (iVar5 == 0)) {
      uStack_30._4_4_ = (undefined4)((ulonglong)uVar8 >> 0x20);
      uVar3 = uStack_30._4_4_;
      iVar4 = param_3 + 1;
      uStack_30 = CONCAT44((undefined4)local_28,(int)uVar8);
      local_38._4_4_ = (undefined4)((ulonglong)uVar6 >> 0x20);
      uVar1 = (ulonglong)local_28 >> 0x20;
      local_28 = CONCAT44((int)uVar1,local_38._4_4_);
      local_38._0_4_ = (int)uVar6;
      local_38 = CONCAT44((int)local_38,uVar3);
      this[0x128] = (HackingGame)0x1;
      *(undefined4 *)(this + 300) = 0;
      iVar5 = 0;
LAB_00179a70:
      uVar3 = solvableInNSteps(this,param_1,param_2 + 1,iVar4,iVar5,piVar9);
      goto LAB_00179a74;
    }
  }
LAB_00179a1e:
  uVar3 = 0;
LAB_00179a74:
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

// ===== HackingGame::gameWon  @0x00179a94  (34 bytes)
/* HackingGame::gameWon(int*) */

undefined4 __thiscall HackingGame::gameWon(HackingGame *this,int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (param_1[iVar1] != *(int *)(this + iVar1 * 4 + 4)) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return 1;
}

// ===== HackingGame::rotateLeftCW  @0x00179ab6  (30 bytes)
/* HackingGame::rotateLeftCW(int*) */

void __thiscall HackingGame::rotateLeftCW(HackingGame *this,int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[3];
  param_1[3] = param_1[4];
  param_1[4] = param_1[1];
  iVar2 = *param_1;
  *param_1 = iVar1;
  param_1[1] = iVar2;
  this[0x128] = (HackingGame)0x1;
  *(undefined4 *)(this + 300) = 0;
  return;
}

// ===== HackingGame::rotateRightCW  @0x00179ad4  (30 bytes)
/* HackingGame::rotateRightCW(int*) */

void __thiscall HackingGame::rotateRightCW(HackingGame *this,int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[4];
  param_1[4] = param_1[5];
  param_1[5] = param_1[2];
  iVar2 = param_1[1];
  param_1[1] = iVar1;
  param_1[2] = iVar2;
  this[0x129] = (HackingGame)0x1;
  *(undefined4 *)(this + 300) = 0;
  return;
}

// ===== HackingGame::getDockingIndex  @0x00179af2  (6 bytes)
/* HackingGame::getDockingIndex() */

undefined4 __thiscall HackingGame::getDockingIndex(HackingGame *this)

{
  return *(undefined4 *)(this + 0x13c);
}

// ===== HackingGame::gameWon  @0x00179af8  (42 bytes)
/* HackingGame::gameWon() */

undefined4 __thiscall HackingGame::gameWon(HackingGame *this)

{
  int iVar1;
  
  if (0x5dc < *(int *)(this + 0x130)) {
    iVar1 = 0;
    while (*(int *)(this + iVar1 * 4 + 0x1c) == *(int *)(this + iVar1 * 4 + 4)) {
      iVar1 = iVar1 + 1;
      if (5 < iVar1) {
        return 1;
      }
    }
  }
  return 0;
}

// ===== HackingGame::update  @0x00179b24  (142 bytes)
/* HackingGame::update(int) */

undefined4 HackingGame::update(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_r1;
  int iVar3;
  float in_s0;
  
  if (((0xff < *(ushort *)(param_1 + 0x128)) || ((*(ushort *)(param_1 + 0x128) & 0xff) != 0)) &&
     (iVar1 = *(int *)(param_1 + 300) + in_r1, *(int *)(param_1 + 300) = iVar1, 300 < iVar1)) {
    iVar1 = 0;
    *(undefined4 *)(param_1 + 300) = 0;
    *(undefined2 *)(param_1 + 0x128) = 0;
    do {
      iVar3 = param_1 + iVar1 * 4;
      iVar1 = iVar1 + 1;
      *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar3 + 0x34);
    } while (iVar1 != 6);
  }
  iVar1 = 0;
  do {
    iVar3 = param_1 + iVar1 * 4;
    if (*(int *)(iVar3 + 0x1c) != *(int *)(iVar3 + 4)) goto LAB_00179bac;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  iVar1 = *(int *)(param_1 + 0x130);
  if (iVar1 == 0) {
    FModSound::play(Globals::sound,0x8e1,(Vector *)0x0,(Vector *)0x0,in_s0);
    iVar1 = *(int *)(param_1 + 0x130);
  }
  *(int *)(param_1 + 0x130) = iVar1 + in_r1;
  if (iVar1 + in_r1 < 0x5dd) {
LAB_00179bac:
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// ===== HackingGame::isRotating  @0x00179bb8  (24 bytes)
/* HackingGame::isRotating() */

bool __thiscall HackingGame::isRotating(HackingGame *this)

{
  return (char)*(ushort *)(this + 0x128) != '\0' || 0xff < *(ushort *)(this + 0x128);
}

// ===== HackingGame::render2D  @0x00179bd0  (2320 bytes)
/* HackingGame::render2D() */

void __thiscall HackingGame::render2D(HackingGame *this)

{
  ushort uVar1;
  bool bVar2;
  PaintCanvas *pPVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  uint local_8c;
  uint local_88;
  int local_78 [13];
  int local_44;
  
  local_44 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar4 = 0;
  do {
    if (*(int *)(this + iVar4 * 4 + 0x1c) != *(int *)(this + iVar4 * 4 + 4)) {
      bVar2 = false;
      goto LAB_00179c18;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  bVar2 = true;
LAB_00179c18:
  iVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth
                    (Globals::Canvas,*(uint *)(this + *(int *)(this + 0x124) * 0x30 + 0x4c));
  iVar6 = AbyssEngine::PaintCanvas::GetImage2DHeight
                    (Globals::Canvas,*(uint *)(this + *(int *)(this + 0x124) * 0x30 + 0x4c));
  iVar4 = Globals::w;
  pPVar3 = Globals::Canvas;
  local_78[1] = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_78[6] = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  local_78[0xb] = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_78[8] = 0;
  local_78[0] = 0;
  local_78[4] = 0;
  uVar1 = *(ushort *)(this + 0x128);
  local_78[2] = local_78[6];
  local_78[3] = local_78[0xb];
  local_78[5] = local_78[1];
  local_78[7] = local_78[0xb];
  local_78[9] = local_78[1];
  local_78[10] = local_78[6];
  if ((0xff < uVar1) || ((uVar1 & 0xff) != 0)) {
    fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(this + 300),(byte)(in_fpscr >> 0x16) & 3);
    in_fpscr = in_fpscr & 0xfffffff;
    fVar13 = 1.0;
    if (fVar12 / 300.0 < 1.0) {
      fVar13 = fVar12 / 300.0;
    }
    if ((uVar1 & 0xff) == 0) {
      if (this[0x129] != (HackingGame)0x0) {
        fVar12 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
        fVar15 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
        local_78[2] = (int)(fVar12 * fVar13);
        local_78[5] = (int)(fVar15 * fVar13);
        local_78[9] = (int)-(fVar13 * fVar15);
        local_78[10] = (int)-(fVar13 * fVar12);
      }
    }
    else {
      fVar12 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
      fVar15 = (float)VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
      local_78[0] = (int)(fVar12 * fVar13);
      local_78[8] = (int)-(fVar13 * fVar12);
      local_78[3] = (int)(fVar15 * fVar13);
      local_78[7] = (int)-(fVar13 * fVar15);
    }
  }
  if (bVar2) {
    if (0x5dc < *(int *)(this + 0x130)) goto LAB_0017a4c8;
  }
  else {
    uVar11 = *(uint *)(this + 0x110);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar11);
    iVar10 = Globals::h;
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar3,uVar11,iVar4 / 2 - iVar7 / 2,iVar10 / 2 - iVar8 / 2);
  }
  iVar10 = Globals::w;
  pPVar3 = Globals::Canvas;
  uVar11 = *(uint *)(this + 0x10c);
  iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar11);
  iVar4 = Globals::h;
  iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
  iVar9 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x10c));
  AbyssEngine::PaintCanvas::DrawImage2D
            (pPVar3,uVar11,iVar10 / 2 - iVar7,
             ((iVar4 / 2 - iVar8 / 2) - iVar9) + *(int *)(Globals::layout + 0x30c));
  iVar10 = Globals::w;
  iVar4 = Globals::h;
  pPVar3 = Globals::Canvas;
  uVar11 = *(uint *)(this + 0x10c);
  iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
  iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x10c));
  AbyssEngine::PaintCanvas::DrawImage2D
            (pPVar3,uVar11,iVar10 / 2,
             ((iVar4 / 2 - iVar7 / 2) - iVar8) + *(int *)(Globals::layout + 0x30c),'\x01');
  iVar4 = Globals::w;
  pPVar3 = Globals::Canvas;
  if (!bVar2) {
    uVar11 = *(uint *)(this + 0x114);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar11);
    iVar10 = Globals::h;
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar3,uVar11,iVar4 / 2 - iVar7,
               iVar8 / 2 + iVar10 / 2 + *(int *)(Globals::layout + 0x314));
    iVar10 = Globals::w;
    iVar4 = Globals::h;
    pPVar3 = Globals::Canvas;
    uVar11 = *(uint *)(this + 0x114);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar3,uVar11,iVar10 / 2,iVar7 / 2 + iVar4 / 2 + *(int *)(Globals::layout + 0x314),
               '\x01');
  }
  iVar4 = 0;
  fVar13 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
  fVar13 = fVar13 * 1.5;
  do {
    iVar10 = Globals::h;
    pPVar3 = Globals::Canvas;
    if ((bVar2) &&
       (((uint)((ulonglong)((longlong)*(int *)(this + 0x130) * 0x51eb851f) >> 0x26) -
         (*(int *)(this + 0x130) >> 0x1f) & 1) == 0)) {
      fVar12 = (float)VectorSignedToFloat(Globals::w / 2,(byte)(in_fpscr >> 0x16) & 3);
      fVar14 = (float)VectorSignedToFloat(iVar5 * (iVar4 % 3),(byte)(in_fpscr >> 0x16) & 3);
      fVar15 = (float)VectorSignedToFloat(local_78[iVar4 * 2],(byte)(in_fpscr >> 0x16) & 3);
      uVar11 = *(uint *)(this + *(int *)(this + iVar4 * 4 + 0x1c) * 4 +
                                *(int *)(this + 0x124) * 0x30 + 100);
      iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
      fVar15 = fVar15 + fVar14 + (fVar12 - fVar13);
      iVar9 = local_78[iVar4 * 2 + 1];
      iVar8 = *(int *)(Globals::layout + 0x310);
      iVar10 = (iVar6 * (iVar4 / 3 + -2) + iVar10 / 2) - iVar7 / 2;
    }
    else {
      fVar12 = (float)VectorSignedToFloat(Globals::w / 2,(byte)(in_fpscr >> 0x16) & 3);
      fVar14 = (float)VectorSignedToFloat(iVar5 * (iVar4 % 3),(byte)(in_fpscr >> 0x16) & 3);
      fVar15 = (float)VectorSignedToFloat(local_78[iVar4 * 2],(byte)(in_fpscr >> 0x16) & 3);
      uVar11 = *(uint *)(this + *(int *)(this + iVar4 * 4 + 0x1c) * 4 +
                                *(int *)(this + 0x124) * 0x30 + 0x4c);
      iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
      fVar15 = fVar15 + fVar14 + (fVar12 - fVar13);
      iVar9 = local_78[iVar4 * 2 + 1];
      iVar8 = *(int *)(Globals::layout + 0x310);
      iVar10 = (iVar6 * (iVar4 / 3 + -2) + iVar10 / 2) - iVar7 / 2;
    }
    AbyssEngine::PaintCanvas::DrawImage2D(pPVar3,uVar11,(int)fVar15,iVar9 + iVar10 + iVar8);
    iVar10 = Globals::w;
    pPVar3 = Globals::Canvas;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 6);
  if (this[0x128] == (HackingGame)0x0) {
    local_88 = *(uint *)(this + 0x11c);
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,local_88);
    iVar4 = Globals::h;
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    iVar8 = (iVar10 / 2 - iVar5 / 2) - iVar8 / 2;
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x11c));
  }
  else {
    local_88 = *(uint *)(this + 0x118);
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,local_88);
    iVar4 = Globals::h;
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    iVar8 = (iVar10 / 2 - iVar5 / 2) - iVar8 / 2;
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x118));
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (pPVar3,local_88,iVar8,
             (((iVar4 / 2 - iVar6) - iVar7 / 2) - iVar10 / 2) + *(int *)(Globals::layout + 0x310));
  iVar4 = Globals::w;
  pPVar3 = Globals::Canvas;
  if (this[0x129] == (HackingGame)0x0) {
    local_8c = *(uint *)(this + 0x11c);
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,local_8c);
    iVar10 = Globals::h;
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    iVar8 = (iVar4 / 2 + iVar5 / 2) - iVar8 / 2;
    iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x11c));
  }
  else {
    local_8c = *(uint *)(this + 0x118);
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,local_8c);
    iVar10 = Globals::h;
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    iVar8 = (iVar4 / 2 + iVar5 / 2) - iVar8 / 2;
    iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x118));
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (pPVar3,local_8c,iVar8,
             (((iVar10 / 2 - iVar6) - iVar7 / 2) - iVar4 / 2) + *(int *)(Globals::layout + 0x310));
  if (!bVar2) {
    iVar4 = 0;
    do {
      iVar10 = Globals::h;
      pPVar3 = Globals::Canvas;
      fVar12 = (float)VectorSignedToFloat(Globals::w / 2,(byte)(in_fpscr >> 0x16) & 3);
      fVar15 = (float)VectorSignedToFloat((iVar4 % 3) * iVar5,(byte)(in_fpscr >> 0x16) & 3);
      uVar11 = *(uint *)(this + *(int *)(this + iVar4 * 4 + 4) * 4 + *(int *)(this + 0x124) * 0x30 +
                                0x4c);
      iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
      AbyssEngine::PaintCanvas::DrawImage2D
                (pPVar3,uVar11,(int)(fVar15 + (fVar12 - fVar13)),
                 (iVar4 / 3) * iVar6 + iVar10 / 2 + iVar7 / 2 + *(int *)(Globals::layout + 0x318));
      pPVar3 = Globals::Canvas;
      iVar4 = iVar4 + 1;
    } while (iVar4 != 6);
    uVar11 = *(uint *)(this + 0x120);
    iVar10 = Globals::w / 2;
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar11);
    iVar4 = Globals::h;
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    iVar9 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x120));
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar3,uVar11,(iVar10 - iVar5 / 2) - iVar7 / 2,
               ((iVar6 + iVar4 / 2 + iVar8 / 2) - iVar9 / 2) + *(int *)(Globals::layout + 0x318));
    pPVar3 = Globals::Canvas;
    uVar11 = *(uint *)(this + 0x120);
    iVar10 = Globals::w / 2;
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar11);
    iVar4 = Globals::h;
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x110));
    iVar9 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x120));
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar3,uVar11,(iVar10 + iVar5 / 2) - iVar7 / 2,
               ((iVar6 + iVar4 / 2 + iVar8 / 2) - iVar9 / 2) + *(int *)(Globals::layout + 0x318));
  }
LAB_0017a4c8:
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

