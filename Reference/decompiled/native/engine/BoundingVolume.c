// Class: BoundingVolume
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== BoundingVolume::BoundingVolume  @0x00144a50  (56 bytes)
/* BoundingVolume::BoundingVolume(float, float, float, float, float, float) */

void __thiscall
BoundingVolume::BoundingVolume
          (BoundingVolume *this,float param_1,float param_2,float param_3,float param_4,
          float param_5,float param_6)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  
  *(undefined ***)this = &PTR_getCollisionNormal_0026430c;
  *(undefined4 *)(this + 8) = in_r1;
  *(undefined4 *)(this + 0xc) = in_r2;
  *(undefined4 *)(this + 0x10) = in_r3;
  *(undefined4 *)(this + 0x14) = in_stack_00000000;
  *(undefined4 *)(this + 0x18) = in_stack_00000004;
  *(undefined4 *)(this + 0x1c) = in_stack_00000008;
  *(undefined4 *)(this + 4) = 0;
  return;
}

// ===== BoundingVolume::~BoundingVolume  @0x00144a8c  (50 bytes)
/* BoundingVolume::~BoundingVolume() */

BoundingVolume * __thiscall BoundingVolume::~BoundingVolume(BoundingVolume *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR_getCollisionNormal_0026430c;
  if (*(Array **)(this + 4) != (Array *)0x0) {
    ArrayReleaseClasses<BoundingVolume*>(*(Array **)(this + 4));
    pvVar1 = *(void **)(this + 4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== BoundingVolume::setVolumes  @0x00144ac4  (4 bytes)
/* BoundingVolume::setVolumes(Array<BoundingVolume*>*) */

void __thiscall BoundingVolume::setVolumes(BoundingVolume *this,Array *param_1)

{
  *(Array **)(this + 4) = param_1;
  return;
}

// ===== BoundingVolume::setVolume  @0x00144ac8  (60 bytes)
/* BoundingVolume::setVolume(BoundingVolume*) */

void __thiscall BoundingVolume::setVolume(BoundingVolume *this,BoundingVolume *param_1)

{
  int *piVar1;
  undefined4 *__ptr;
  void *pvVar2;
  
  piVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  piVar1[1] = (int)__ptr;
  *__ptr = 0;
  *piVar1 = 0;
  *(int **)(this + 4) = piVar1;
  piVar1[2] = 1;
  pvVar2 = realloc(__ptr,4);
  piVar1[1] = (int)pvVar2;
  *(BoundingVolume **)((int)pvVar2 + *piVar1 * 4) = param_1;
  *piVar1 = piVar1[2];
  return;
}

// ===== BoundingVolume::getProjectionVector  @0x00144b14  (72 bytes)
/* BoundingVolume::getProjectionVector(AbyssEngine::AEMath::Vector const&) */

void BoundingVolume::getProjectionVector(Vector *param_1)

{
  int in_r1;
  Vector *in_r2;
  AEMath aAStack_20 [12];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::AEMath::operator-((AEMath *)param_1,in_r2,(Vector *)(in_r1 + 8));
  AbyssEngine::AEMath::VectorNormalize(aAStack_20,param_1);
  AbyssEngine::AEMath::Vector::operator=(param_1,(Vector *)aAStack_20);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== BoundingVolume::getCollisionNormal  @0x00144b64  (10 bytes)
/* BoundingVolume::getCollisionNormal(AbyssEngine::AEMath::Vector const&) */

void BoundingVolume::getCollisionNormal(Vector *param_1)

{
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

// ===== BoundingVolume::update  @0x00144b70  (130 bytes)
/* BoundingVolume::update(float, float, float) */

void __thiscall
BoundingVolume::update(BoundingVolume *this,float param_1,float param_2,float param_3)

{
  uint *puVar1;
  uint uVar2;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  Vector local_48 [12];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  puVar1 = *(uint **)(this + 4);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      (**(code **)(**(int **)(puVar1[1] + uVar2 * 4) + 4))(param_1,param_2,param_3);
      puVar1 = *(uint **)(this + 4);
      uVar2 = uVar2 + 1;
      param_1 = extraout_s0;
      param_2 = extraout_s1;
      param_3 = extraout_s2;
    } while (uVar2 < *puVar1);
  }
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 8),local_48);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== BoundingVolume::collide  @0x00144bfc  (60 bytes)
/* BoundingVolume::collide(float, float, float) */

undefined4 BoundingVolume::collide(float param_1,float param_2,float param_3)

{
  int in_r0;
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  puVar1 = *(uint **)(in_r0 + 4);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar4 = 0;
    do {
      piVar2 = *(int **)(puVar1[1] + uVar4 * 4);
      iVar3 = (**(code **)(*piVar2 + 8))
                        (param_1,param_2,param_3,piVar2,*(undefined4 *)(in_r0 + 8),
                         *(undefined4 *)(in_r0 + 0xc),*(undefined4 *)(in_r0 + 0x10));
      if (iVar3 == 1) {
        return 1;
      }
      puVar1 = *(uint **)(in_r0 + 4);
      uVar4 = uVar4 + 1;
      param_1 = extraout_s0;
      param_2 = extraout_s1;
      param_3 = extraout_s2;
    } while (uVar4 < *puVar1);
  }
  return 0;
}

// ===== BoundingVolume::outerCollide  @0x00144c38  (4 bytes)
/* BoundingVolume::outerCollide(float, float, float) */

undefined4 BoundingVolume::outerCollide(float param_1,float param_2,float param_3)

{
  return 0;
}

// ===== BoundingVolume::staticProjectCollisionOnSurface  @0x00144c3c  (150 bytes)
/* BoundingVolume::staticProjectCollisionOnSurface(AbyssEngine::AEMath::Vector const&,
   Array<BoundingVolume*>*) */

void __thiscall
BoundingVolume::staticProjectCollisionOnSurface(BoundingVolume *this,Vector *param_1,Array *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  Vector aVStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  uVar6 = *(undefined8 *)param_1;
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined8 *)this = uVar6;
  if (param_2 != (Array *)0x0) {
    uVar1 = *(uint *)param_2;
    iVar5 = 0;
    do {
      if (uVar1 == 0) {
        uVar1 = 0;
      }
      else {
        uVar4 = 0;
        do {
          piVar2 = *(int **)(*(int *)(param_2 + 4) + uVar4 * 4);
          iVar3 = (**(code **)(*piVar2 + 0xc))
                            (piVar2,*(undefined4 *)this,*(undefined4 *)(this + 4),
                             *(undefined4 *)(this + 8));
          if (iVar3 == 1) {
            piVar2 = *(int **)(*(int *)(param_2 + 4) + uVar4 * 4);
            (**(code **)(*piVar2 + 0x10))(aVStack_30,piVar2,this);
            AbyssEngine::AEMath::Vector::operator=((Vector *)this,aVStack_30);
          }
          uVar1 = *(uint *)param_2;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 2);
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

