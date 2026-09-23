// Class: BoundingSphere
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== BoundingSphere::BoundingSphere  @0x0017cd1c  (56 bytes)
/* BoundingSphere::BoundingSphere(float, float, float, float, float, float, float) */

void __thiscall
BoundingSphere::BoundingSphere
          (BoundingSphere *this,float param_1,float param_2,float param_3,float param_4,
          float param_5,float param_6,float param_7)

{
  undefined4 *puVar1;
  float in_stack_00000000;
  float in_stack_00000004;
  float in_stack_00000008;
  undefined4 in_stack_0000000c;
  
  puVar1 = (undefined4 *)
           BoundingVolume::BoundingVolume
                     ((BoundingVolume *)this,in_stack_00000000,param_2,in_stack_00000004,param_4,
                      in_stack_00000008,param_6);
  *puVar1 = &PTR_getCollisionNormal_002643e8;
  puVar1[0xe] = in_stack_0000000c;
  return;
}

// ===== BoundingSphere::~BoundingSphere  @0x0017cd58  (4 bytes)
/* BoundingSphere::~BoundingSphere() */

void __thiscall BoundingSphere::~BoundingSphere(BoundingSphere *this)

{
  BoundingVolume::~BoundingVolume((BoundingVolume *)this);
  return;
}

// ===== BoundingSphere::collide  @0x0017cd5c  (48 bytes)
/* BoundingSphere::collide(float, float, float) */

undefined4 BoundingSphere::collide(float param_1,float param_2,float param_3)

{
  int *in_r0;
  int iVar1;
  undefined4 uVar2;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  iVar1 = (**(code **)(*in_r0 + 0xc))();
  if (iVar1 == 0) {
    uVar2 = BoundingVolume::collide(extraout_s0,extraout_s1,extraout_s2);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

// ===== BoundingSphere::outerCollide  @0x0017cd8c  (106 bytes)
/* BoundingSphere::outerCollide(float, float, float) */

void __thiscall
BoundingSphere::outerCollide(BoundingSphere *this,float param_1,float param_2,float param_3)

{
  float fVar1;
  AEMath aAStack_3c [12];
  Vector local_30 [12];
  AEMath aAStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::AEMath::operator+(aAStack_3c,(Vector *)(this + 8),(Vector *)(this + 0x14));
  AbyssEngine::AEMath::operator-(aAStack_24,local_30,(Vector *)aAStack_3c);
  fVar1 = (float)AbyssEngine::AEMath::VectorDot((Vector *)aAStack_24,(Vector *)aAStack_24);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail((int)((uint)(fVar1 < *(float *)(this + 0x38) * *(float *)(this + 0x38)) << 0x1f
                          ) < 0);
  }
  return;
}

// ===== BoundingSphere::getCollisionNormal  @0x0017ce00  (88 bytes)
/* BoundingSphere::getCollisionNormal(AbyssEngine::AEMath::Vector const&) */

void BoundingSphere::getCollisionNormal(Vector *param_1)

{
  int in_r1;
  Vector *in_r2;
  AEMath aAStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::AEMath::operator+(aAStack_24,(Vector *)(in_r1 + 8),(Vector *)(in_r1 + 0x14));
  AbyssEngine::AEMath::operator-((AEMath *)param_1,(Vector *)aAStack_24,in_r2);
  AbyssEngine::AEMath::VectorNormalize(aAStack_24,param_1);
  AbyssEngine::AEMath::Vector::operator=(param_1,(Vector *)aAStack_24);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== BoundingSphere::update  @0x0017ce60  (4 bytes)
/* BoundingSphere::update(float, float, float) */

void __thiscall
BoundingSphere::update(BoundingSphere *this,float param_1,float param_2,float param_3)

{
  BoundingVolume::update((BoundingVolume *)this,param_1,param_2,param_3);
  return;
}

// ===== BoundingSphere::projectCollisionOnSurface  @0x0017ce64  (170 bytes)
/* BoundingSphere::projectCollisionOnSurface(AbyssEngine::AEMath::Vector const&) */

void BoundingSphere::projectCollisionOnSurface(Vector *param_1)

{
  float fVar1;
  int in_r1;
  Vector *in_r2;
  float fVar2;
  AEMath aAStack_60 [12];
  AEMath aAStack_54 [12];
  AEMath aAStack_48 [12];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  AbyssEngine::AEMath::operator+(aAStack_54,(Vector *)(in_r1 + 8),(Vector *)(in_r1 + 0x14));
  AbyssEngine::AEMath::operator-(aAStack_48,(Vector *)aAStack_54,in_r2);
  fVar1 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_48);
  fVar2 = *(float *)(in_r1 + 0x38);
  if (fVar2 <= fVar1) {
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    AbyssEngine::AEMath::operator+(aAStack_54,(Vector *)(in_r1 + 8),(Vector *)(in_r1 + 0x14));
    fVar2 = fVar2 / fVar1;
    AbyssEngine::AEMath::operator*(aAStack_60,fVar2,(Vector *)fVar2);
    AbyssEngine::AEMath::operator-((AEMath *)param_1,(Vector *)aAStack_54,(Vector *)aAStack_60);
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

