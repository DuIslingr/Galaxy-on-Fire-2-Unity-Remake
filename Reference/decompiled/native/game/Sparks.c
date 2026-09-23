// Class: Sparks
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Sparks::Sparks  @0x0018ab98  (212 bytes)
/* Sparks::Sparks(int) */

Sparks * __thiscall Sparks::Sparks(Sparks *this,int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  float extraout_s3;
  
  uVar6 = 5;
  *(int *)(this + 0x14) = param_1;
  if (param_1 == 0) {
    uVar6 = 1;
  }
  uVar2 = 0x514;
  *(undefined4 *)(this + 0x18) = uVar6;
  if (param_1 == 0) {
    uVar2 = 500;
  }
  *(undefined4 *)(this + 0x1c) = uVar2;
  AbyssEngine::PaintCanvas::SpriteSystemCreate
            (Globals::Canvas,(ushort)uVar6,false,(uint *)(this + 4));
  AbyssEngine::PaintCanvas::SpriteSystemSetAllUv
            ((uint)Globals::Canvas,extraout_s0,extraout_s1,extraout_s2,extraout_s3);
  this[0x10] = (Sparks)0x0;
  uVar7 = *(uint *)(this + 0x18);
  lVar1 = (ulonglong)uVar7 * 4;
  uVar3 = (uint)lVar1;
  if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
    uVar3 = 0xffffffff;
  }
  puVar4 = operator_new__(uVar3);
  *(undefined4 **)this = puVar4;
  *(undefined4 *)(this + 0x20) = 0;
  if (*(int *)(this + 0x14) == 1) {
    if (uVar7 != 0) {
      uVar3 = 0;
      do {
        AbyssEngine::PaintCanvas::SpriteSystemSetSize
                  (Globals::Canvas,*(uint *)(this + 4),(ushort)uVar3,1);
        iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,500);
        *(int *)(*(int *)this + uVar3 * 4) = iVar5;
        uVar3 = uVar3 + 1;
        *(int *)(this + 0x20) = iVar5 + *(int *)(this + 0x20);
      } while (uVar3 < *(uint *)(this + 0x18));
    }
  }
  else {
    *puVar4 = 0;
    *(undefined4 *)(this + 0x20) = 0;
  }
  *(undefined4 *)(this + 0xc) = 0;
  return this;
}

// ===== Sparks::isRocket  @0x0018ac78  (10 bytes)
/* Sparks::isRocket() */

bool __thiscall Sparks::isRocket(Sparks *this)

{
  return *(int *)(this + 0x14) == 1;
}

// ===== Sparks::~Sparks  @0x0018ac82  (22 bytes)
/* Sparks::~Sparks() */

Sparks * __thiscall Sparks::~Sparks(Sparks *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  return this;
}

// ===== Sparks::explode  @0x0018ac98  (258 bytes)
/* Sparks::explode(int, int, int) */

void Sparks::explode(int param_1,int param_2,int param_3)

{
  PaintCanvas *this;
  int iVar1;
  int in_r3;
  uint uVar2;
  uint uVar3;
  uint in_fpscr;
  float fVar4;
  float in_s1;
  float extraout_s1;
  float extraout_s2;
  float fVar5;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(int *)(param_1 + 0x14) == 1) {
      if (*(int *)(param_1 + 0x18) != 0) {
        uVar3 = 0;
        do {
          this = Globals::Canvas;
          uVar2 = *(uint *)(param_1 + 4);
          iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,400);
          VectorSignedToFloat(iVar1 + param_2,(byte)(in_fpscr >> 0x16) & 3);
          iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,400);
          VectorSignedToFloat(param_3 + iVar1,(byte)(in_fpscr >> 0x16) & 3);
          iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,400);
          fVar4 = (float)VectorSignedToFloat(iVar1 + in_r3,(byte)(in_fpscr >> 0x16) & 3);
          AbyssEngine::PaintCanvas::SpriteSystemSetPosition
                    (this,uVar2,(ushort)uVar3,fVar4,extraout_s1,extraout_s2);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(param_1 + 0x18));
      }
    }
    else {
      VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
      fVar4 = (float)VectorSignedToFloat(in_r3,(byte)(in_fpscr >> 0x16) & 3);
      fVar5 = (float)VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::PaintCanvas::SpriteSystemSetPosition
                (Globals::Canvas,*(uint *)(param_1 + 4),0,fVar4,in_s1,fVar5);
    }
    *(undefined1 *)(param_1 + 0x10) = 1;
  }
  return;
}

// ===== Sparks::explode  @0x0018ada8  (42 bytes)
/* Sparks::explode(AbyssEngine::AEMath::Vector const&) */

void __thiscall Sparks::explode(Sparks *this,Vector *param_1)

{
  explode((int)this,(int)*(float *)param_1,(int)*(float *)(param_1 + 4));
  return;
}

// ===== Sparks::render  @0x0018add0  (130 bytes)
/* Sparks::render() */

void __thiscall Sparks::render(Sparks *this)

{
  undefined4 *puVar1;
  undefined4 local_50 [5];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (this[0x10] != (Sparks)0x0) {
    AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 8),0xffffffff);
    AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,2);
    uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar1 = (undefined4 *)((uint)local_50 | 4);
    local_50[0] = 0x3f800000;
    *puVar1 = 0;
    puVar1[1] = uStack_34;
    puVar1[2] = uStack_30;
    puVar1[3] = uStack_2c;
    local_3c = 0x3f800000;
    local_38 = 0;
    local_28 = 0x3f800000;
    uStack_20 = 0x3f8000003f800000;
    local_18 = 0x3f800000;
    AbyssEngine::PaintCanvas::SetWorldViewMatrix(Globals::Canvas);
    AbyssEngine::PaintCanvas::DrawSpriteSystem(Globals::Canvas,*(uint *)(this + 4));
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Sparks::update  @0x0018ae80  (106 bytes)
/* Sparks::update(int) */

void __thiscall Sparks::update(Sparks *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (this[0x10] != (Sparks)0x0) {
    iVar1 = *(int *)(this + 0xc) + param_1;
    *(int *)(this + 0xc) = iVar1;
    uVar2 = *(uint *)(this + 0x18);
    if (uVar2 != 0) {
      uVar3 = 0;
      do {
        if (*(int *)(*(int *)this + uVar3 * 4) < iVar1) {
          AbyssEngine::PaintCanvas::SpriteSystemSetSize
                    (Globals::Canvas,*(uint *)(this + 4),(ushort)uVar3,
                     (short)*(undefined4 *)(this + 0x1c) - (short)(iVar1 << 1));
          uVar2 = *(uint *)(this + 0x18);
        }
        iVar1 = *(int *)(this + 0xc);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    if (*(int *)(this + 0x14) == 1) {
      if ((iVar1 < 0x1f5) &&
         (iVar1 * 2 - *(int *)(this + 0x1c) == 0 || iVar1 * 2 < *(int *)(this + 0x1c))) {
        return;
      }
    }
    else if (iVar1 < 0x1f5) {
      return;
    }
    *(undefined4 *)(this + 0xc) = 0;
    this[0x10] = (Sparks)0x0;
  }
  return;
}

// ===== Sparks::translate  @0x0018aef0  (70 bytes)
/* Sparks::translate(AbyssEngine::AEMath::Vector const&) */

void Sparks::translate(Vector *param_1)

{
  int in_r1;
  uint uVar1;
  float in_s1;
  float extraout_s1;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    uVar1 = 0;
    do {
      AbyssEngine::PaintCanvas::SpriteSystemAddPosition
                (Globals::Canvas,*(uint *)(param_1 + 4),(ushort)uVar1,*(float *)(in_r1 + 4),in_s1,
                 *(float *)(in_r1 + 8));
      uVar1 = uVar1 + 1;
      in_s1 = extraout_s1;
    } while (uVar1 < *(uint *)(param_1 + 0x18));
  }
  return;
}

