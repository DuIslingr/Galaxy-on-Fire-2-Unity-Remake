// Class: BoundingAAB
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== BoundingAAB::BoundingAAB  @0x000a3b1c  (146 bytes)
/* BoundingAAB::BoundingAAB(float, float, float, float, float, float, float, float, float) */

void __thiscall
BoundingAAB::BoundingAAB
          (BoundingAAB *this,float param_1,float param_2,float param_3,float param_4,float param_5,
          float param_6,float param_7,float param_8,float param_9)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float in_stack_00000000;
  float in_stack_00000004;
  float in_stack_00000008;
  float in_stack_0000000c;
  float in_stack_00000010;
  float in_stack_00000014;
  
  puVar1 = (undefined4 *)
           BoundingVolume::BoundingVolume
                     ((BoundingVolume *)this,in_stack_00000000,param_2,in_stack_00000004,param_4,
                      in_stack_00000008,param_6);
  fVar3 = in_stack_0000000c * -0.5;
  if (0.0 < in_stack_0000000c * 0.5) {
    fVar3 = in_stack_0000000c * 0.5;
  }
  fVar4 = in_stack_00000010 * -0.5;
  if (0.0 < in_stack_00000010 * 0.5) {
    fVar4 = in_stack_00000010 * 0.5;
  }
  fVar2 = in_stack_00000014 * -0.5;
  if (0.0 < in_stack_00000014 * 0.5) {
    fVar2 = in_stack_00000014 * 0.5;
  }
  *puVar1 = &PTR_getCollisionNormal_00263df0;
  puVar1[8] = fVar3;
  puVar1[9] = fVar4;
  puVar1[10] = fVar2;
  return;
}

// ===== BoundingAAB::~BoundingAAB  @0x000a3bb4  (4 bytes)
/* BoundingAAB::~BoundingAAB() */

void __thiscall BoundingAAB::~BoundingAAB(BoundingAAB *this)

{
  BoundingVolume::~BoundingVolume((BoundingVolume *)this);
  return;
}

// ===== BoundingAAB::collide  @0x000a3bb8  (50 bytes)
/* BoundingAAB::collide(float, float, float) */

undefined4 BoundingAAB::collide(float param_1,float param_2,float param_3)

{
  int *in_r0;
  int iVar1;
  undefined4 uVar2;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  iVar1 = (**(code **)(*in_r0 + 0xc))();
  if (iVar1 == 1) {
    uVar2 = BoundingVolume::collide(extraout_s0,extraout_s1,extraout_s2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// ===== BoundingAAB::outerCollide  @0x000a3bea  (158 bytes)
/* BoundingAAB::outerCollide(float, float, float) */

undefined4 __thiscall
BoundingAAB::outerCollide(BoundingAAB *this,float param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  float in_r1;
  float in_r2;
  float in_r3;
  
  uVar1 = 0;
  if ((int)((uint)((*(float *)(this + 8) + *(float *)(this + 0x14)) - *(float *)(this + 0x20) <
                  in_r1) << 0x1f) < 0) {
    if (in_r1 < *(float *)(this + 8) + *(float *)(this + 0x14) + *(float *)(this + 0x20)) {
      uVar1 = 0;
      if ((int)((uint)((*(float *)(this + 0xc) + *(float *)(this + 0x18)) - *(float *)(this + 0x24)
                      < in_r2) << 0x1f) < 0) {
        if (in_r2 < *(float *)(this + 0xc) + *(float *)(this + 0x18) + *(float *)(this + 0x24)) {
          uVar1 = 0;
          if (-1 < (int)((uint)((*(float *)(this + 0x10) + *(float *)(this + 0x1c)) -
                                *(float *)(this + 0x28) < in_r3) << 0x1f)) {
            return 0;
          }
          if (in_r3 < *(float *)(this + 0x10) + *(float *)(this + 0x1c) + *(float *)(this + 0x28)) {
            uVar1 = 1;
          }
        }
      }
    }
  }
  return uVar1;
}

// ===== BoundingAAB::getCollisionNormal  @0x000a3c88  (10 bytes)
/* BoundingAAB::getCollisionNormal(AbyssEngine::AEMath::Vector const&) */

void BoundingAAB::getCollisionNormal(Vector *param_1)

{
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

// ===== BoundingAAB::update  @0x000a3c92  (4 bytes)
/* BoundingAAB::update(float, float, float) */

void __thiscall BoundingAAB::update(BoundingAAB *this,float param_1,float param_2,float param_3)

{
  BoundingVolume::update((BoundingVolume *)this,param_1,param_2,param_3);
  return;
}

// ===== BoundingAAB::projectCollisionOnSurface  @0x000a3c98  (378 bytes)
/* BoundingAAB::projectCollisionOnSurface(AbyssEngine::AEMath::Vector const&) */

void BoundingAAB::projectCollisionOnSurface(Vector *param_1)

{
  int iVar1;
  float *pfVar2;
  int in_r1;
  uint uVar3;
  Vector *in_r2;
  uint uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float local_ac [4];
  float local_9c [4];
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  float local_80;
  undefined4 local_7c;
  undefined4 uStack_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  float local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  float local_58;
  int local_54;
  
  local_54 = __stack_chk_guard;
  fVar6 = *(float *)(in_r1 + 8) + *(float *)(in_r1 + 0x14);
  local_9c[0] = *(float *)in_r2 - (fVar6 + *(float *)(in_r1 + 0x20));
  local_9c[3] = *(float *)in_r2 - (fVar6 - *(float *)(in_r1 + 0x20));
  local_9c[1] = 0.0;
  local_9c[2] = 0.0;
  local_8c = 0;
  uStack_88 = 0;
  fVar6 = *(float *)(in_r1 + 0xc) + *(float *)(in_r1 + 0x18);
  local_84 = 0;
  local_80 = *(float *)(in_r2 + 4) - (fVar6 + *(float *)(in_r1 + 0x24));
  local_74 = *(float *)(in_r2 + 4) - (fVar6 - *(float *)(in_r1 + 0x24));
  local_7c = 0;
  uStack_78 = 0;
  local_70 = 0;
  fVar6 = *(float *)(in_r1 + 0x10) + *(float *)(in_r1 + 0x1c);
  local_6c = 0;
  uStack_68 = 0;
  fVar7 = fVar6 - *(float *)(in_r1 + 0x28);
  local_64 = *(float *)(in_r2 + 8) - (fVar6 + *(float *)(in_r1 + 0x28));
  local_58 = *(float *)(in_r2 + 8) - fVar7;
  local_60 = 0;
  uStack_5c = 0;
  fVar6 = (float)AbyssEngine::AEMath::Absf(fVar7);
  fVar7 = (float)AbyssEngine::AEMath::Absf(extraout_s0);
  local_ac[0] = (float)AbyssEngine::AEMath::Absf(extraout_s0_00);
  local_ac[1] = (float)AbyssEngine::AEMath::Absf(extraout_s0_01);
  local_ac[2] = (float)AbyssEngine::AEMath::Absf(extraout_s0_02);
  local_ac[3] = (float)AbyssEngine::AEMath::Absf(extraout_s0_03);
  pfVar2 = local_ac;
  uVar3 = 2;
  uVar4 = (uint)((int)((uint)(fVar7 < fVar6) << 0x1f) < 0);
  uVar5 = uVar4;
  do {
    if (uVar4 != 0) {
      fVar6 = fVar7;
    }
    fVar7 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    iVar1 = (uint)(fVar7 < fVar6) << 0x1f;
    if (iVar1 < 0) {
      uVar5 = uVar3;
    }
    uVar3 = uVar3 + 1;
    uVar4 = (uint)(iVar1 < 0);
  } while (uVar3 != 6);
  AbyssEngine::AEMath::operator-((AEMath *)param_1,in_r2,(Vector *)(local_9c + uVar5 * 3));
  if (__stack_chk_guard != local_54) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

