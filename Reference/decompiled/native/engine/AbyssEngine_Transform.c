// Class: AbyssEngine::Transform
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::Transform::Transform  @0x0007dc90  (514 bytes)
/* AbyssEngine::Transform::Transform() */

void __thiscall AbyssEngine::Transform::Transform(Transform *this)

{
  undefined4 *puVar1;
  Quaternion *this_00;
  Vector *pVVar2;
  Matrix *pMVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  int local_4c;
  
  uVar4 = 0;
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_4c = __stack_chk_guard;
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = uVar5;
  *(undefined4 *)(this + 0xc) = uVar6;
  *(undefined4 *)(this + 0x10) = uVar7;
  *(undefined4 *)(this + 0x14) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = uVar5;
  *(undefined4 *)(this + 0x20) = uVar6;
  *(undefined4 *)(this + 0x24) = uVar7;
  *(undefined8 *)(this + 0x28) = 0x3f800000;
  *(undefined8 *)(this + 0x30) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x40) = puVar1;
  *(undefined4 *)(this + 0x44) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x50) = puVar1;
  *(undefined4 *)(this + 0x54) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x5c) = 0x3f800000;
  *(undefined4 *)(this + 0x60) = uVar4;
  *(undefined4 *)(this + 100) = uVar5;
  *(undefined4 *)(this + 0x68) = uVar6;
  *(undefined4 *)(this + 0x6c) = uVar7;
  *(undefined4 *)(this + 0x70) = 0x3f800000;
  *(undefined4 *)(this + 0x74) = uVar4;
  *(undefined4 *)(this + 0x78) = uVar5;
  *(undefined4 *)(this + 0x7c) = uVar6;
  *(undefined4 *)(this + 0x80) = uVar7;
  *(undefined8 *)(this + 0x84) = 0x3f800000;
  *(undefined8 *)(this + 0x8c) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x94) = 0x3f800000;
  *(undefined4 *)(this + 0x98) = 0x3f800000;
  *(undefined4 *)(this + 0x9c) = uVar4;
  *(undefined4 *)(this + 0xa0) = uVar5;
  *(undefined4 *)(this + 0xa4) = uVar6;
  *(undefined4 *)(this + 0xa8) = uVar7;
  *(undefined4 *)(this + 0xac) = 0x3f800000;
  *(undefined4 *)(this + 0xb0) = uVar4;
  *(undefined4 *)(this + 0xb4) = uVar5;
  *(undefined4 *)(this + 0xb8) = uVar6;
  *(undefined4 *)(this + 0xbc) = uVar7;
  *(undefined8 *)(this + 0xc0) = 0x3f800000;
  *(undefined8 *)(this + 200) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xd0) = 0x3f800000;
  *(undefined4 *)(this + 0xd4) = uVar4;
  *(undefined4 *)(this + 0xd8) = uVar5;
  *(undefined4 *)(this + 0xdc) = uVar6;
  *(undefined4 *)(this + 0xe0) = uVar7;
  *(undefined4 *)(this + 0xe4) = 0x3f800000;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x120) = puVar1;
  *(undefined4 *)(this + 0x124) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  Quaternion::Quaternion((Quaternion *)(this + 0x128));
  uVar4 = 0;
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x13c) = uVar5;
  *(undefined4 *)(this + 0x140) = uVar6;
  *(undefined4 *)(this + 0x144) = uVar7;
  Quaternion::Quaternion((Quaternion *)(this + 0x150));
  *(undefined4 *)(this + 0x170) = 0;
  *(undefined4 *)(this + 0x174) = 0;
  *(undefined4 *)(this + 0x160) = uVar4;
  *(undefined4 *)(this + 0x164) = uVar5;
  *(undefined4 *)(this + 0x168) = uVar6;
  *(undefined4 *)(this + 0x16c) = uVar7;
  *(undefined4 *)(this + 0x48) = 0xffffffff;
  *(undefined4 *)(this + 0x100) = uVar4;
  *(undefined4 *)(this + 0x104) = uVar5;
  *(undefined4 *)(this + 0x108) = uVar6;
  *(undefined4 *)(this + 0x10c) = uVar7;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x114) = 0;
  this[0xed] = (Transform)0x1;
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined4 *)(this + 0xfc) = 0;
  *(undefined4 *)(this + 0xf0) = 0x3f800000;
  *(undefined4 *)(this + 0x118) = 0;
  this_00 = (Quaternion *)Quaternion::Quaternion((Quaternion *)&local_88);
  uVar4 = *(undefined4 *)(this_00 + 4);
  uVar5 = *(undefined4 *)(this_00 + 8);
  uVar6 = *(undefined4 *)(this_00 + 0xc);
  *(undefined4 *)(this + 0x150) = *(undefined4 *)this_00;
  *(undefined4 *)(this + 0x154) = uVar4;
  *(undefined4 *)(this + 0x158) = uVar5;
  *(undefined4 *)(this + 0x15c) = uVar6;
  uVar4 = *(undefined4 *)(this_00 + 4);
  uVar5 = *(undefined4 *)(this_00 + 8);
  uVar6 = *(undefined4 *)(this_00 + 0xc);
  *(undefined4 *)(this + 0x128) = *(undefined4 *)this_00;
  *(undefined4 *)(this + 300) = uVar4;
  *(undefined4 *)(this + 0x130) = uVar5;
  *(undefined4 *)(this + 0x134) = uVar6;
  Quaternion::~Quaternion(this_00);
  local_88 = 0;
  uStack_84 = 0;
  local_80 = 0;
  pVVar2 = (Vector *)AEMath::Vector::operator=((Vector *)(this + 0x160),(Vector *)&local_88);
  AEMath::Vector::operator=((Vector *)(this + 0x138),pVVar2);
  local_88 = 0x3f800000;
  uStack_84 = 0x3f800000;
  local_80 = 0x3f800000;
  pVVar2 = (Vector *)AEMath::Vector::operator=((Vector *)(this + 0x16c),(Vector *)&local_88);
  AEMath::Vector::operator=((Vector *)(this + 0x144),pVVar2);
  uStack_6c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_68 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_64 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar1 = (undefined4 *)((uint)&local_88 | 4);
  local_88 = 0x3f800000;
  *puVar1 = 0;
  puVar1[1] = uStack_6c;
  puVar1[2] = uStack_68;
  puVar1[3] = uStack_64;
  local_74 = 0x3f800000;
  local_70 = 0;
  local_60 = 0x3f800000;
  uStack_58 = 0x3f8000003f800000;
  local_50 = 0x3f800000;
  pMVar3 = (Matrix *)AEMath::Matrix::operator=((Matrix *)(this + 0x98),(Vector *)&local_88);
  AEMath::Matrix::operator=((Matrix *)(this + 0x5c),pMVar3);
  *(undefined4 *)(this + 0xac) = 0xbf800000;
  *(undefined4 *)(this + 0x58) = 2;
  this[0x17c] = (Transform)0x1;
  this[0x17d] = (Transform)0x0;
  this[0xec] = (Transform)0x1;
  *(undefined4 *)(this + 0xe8) = 0;
  if (__stack_chk_guard - local_4c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_4c);
  }
  return;
}

// ===== AbyssEngine::Transform::Transform  @0x0007df20  (670 bytes)
/* AbyssEngine::Transform::Transform(AbyssEngine::Transform*) */

void __thiscall AbyssEngine::Transform::Transform(Transform *this,Transform *param_1)

{
  undefined4 *puVar1;
  Mesh *this_00;
  void *pvVar2;
  Transform *this_01;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  Transform aTStack_1d0 [388];
  int local_4c;
  
  uVar4 = 0;
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_4c = __stack_chk_guard;
  *(undefined4 *)this = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = uVar5;
  *(undefined4 *)(this + 0xc) = uVar6;
  *(undefined4 *)(this + 0x10) = uVar7;
  *(undefined4 *)(this + 0x14) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = uVar5;
  *(undefined4 *)(this + 0x20) = uVar6;
  *(undefined4 *)(this + 0x24) = uVar7;
  *(undefined8 *)(this + 0x28) = 0x3f800000;
  *(undefined8 *)(this + 0x30) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x40) = puVar1;
  *(undefined4 *)(this + 0x44) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x50) = puVar1;
  *(undefined4 *)(this + 0x54) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x5c) = 0x3f800000;
  *(undefined4 *)(this + 0x60) = uVar4;
  *(undefined4 *)(this + 100) = uVar5;
  *(undefined4 *)(this + 0x68) = uVar6;
  *(undefined4 *)(this + 0x6c) = uVar7;
  *(undefined4 *)(this + 0x70) = 0x3f800000;
  *(undefined4 *)(this + 0x74) = uVar4;
  *(undefined4 *)(this + 0x78) = uVar5;
  *(undefined4 *)(this + 0x7c) = uVar6;
  *(undefined4 *)(this + 0x80) = uVar7;
  *(undefined8 *)(this + 0x84) = 0x3f800000;
  *(undefined8 *)(this + 0x8c) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x94) = 0x3f800000;
  *(undefined4 *)(this + 0x98) = 0x3f800000;
  *(undefined4 *)(this + 0x9c) = uVar4;
  *(undefined4 *)(this + 0xa0) = uVar5;
  *(undefined4 *)(this + 0xa4) = uVar6;
  *(undefined4 *)(this + 0xa8) = uVar7;
  *(undefined4 *)(this + 0xac) = 0x3f800000;
  *(undefined4 *)(this + 0xb0) = uVar4;
  *(undefined4 *)(this + 0xb4) = uVar5;
  *(undefined4 *)(this + 0xb8) = uVar6;
  *(undefined4 *)(this + 0xbc) = uVar7;
  *(undefined8 *)(this + 0xc0) = 0x3f800000;
  *(undefined8 *)(this + 200) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xd0) = 0x3f800000;
  *(undefined4 *)(this + 0xd4) = uVar4;
  *(undefined4 *)(this + 0xd8) = uVar5;
  *(undefined4 *)(this + 0xdc) = uVar6;
  *(undefined4 *)(this + 0xe0) = uVar7;
  *(undefined4 *)(this + 0xe4) = 0x3f800000;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x120) = puVar1;
  *(undefined4 *)(this + 0x124) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  Quaternion::Quaternion((Quaternion *)(this + 0x128));
  uVar4 = 0;
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x13c) = uVar5;
  *(undefined4 *)(this + 0x140) = uVar6;
  *(undefined4 *)(this + 0x144) = uVar7;
  Quaternion::Quaternion((Quaternion *)(this + 0x150));
  *(undefined4 *)(this + 0x170) = 0;
  *(undefined4 *)(this + 0x174) = 0;
  *(undefined4 *)(this + 0x160) = uVar4;
  *(undefined4 *)(this + 0x164) = uVar5;
  *(undefined4 *)(this + 0x168) = uVar6;
  *(undefined4 *)(this + 0x16c) = uVar7;
  if (param_1 == (Transform *)0x0) {
    Transform(aTStack_1d0);
    ~Transform(aTStack_1d0);
  }
  else {
    *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
    this[0xed] = (Transform)0x1;
    *(undefined4 *)(this + 0xf0) = 0x3f800000;
    uVar8 = *(undefined8 *)(param_1 + 0x100);
    *(undefined8 *)(this + 0xf8) = *(undefined8 *)(param_1 + 0xf8);
    *(undefined8 *)(this + 0x100) = uVar8;
    *(undefined4 *)(this + 0x48) = 0xffffffff;
    uVar8 = *(undefined8 *)(param_1 + 0x110);
    *(undefined8 *)(this + 0x108) = *(undefined8 *)(param_1 + 0x108);
    *(undefined8 *)(this + 0x110) = uVar8;
    *(undefined4 *)(this + 0x118) = *(undefined4 *)(param_1 + 0x118);
    uVar8 = *(undefined8 *)(param_1 + 0x130);
    *(undefined8 *)(this + 0x128) = *(undefined8 *)(param_1 + 0x128);
    *(undefined8 *)(this + 0x130) = uVar8;
    AEMath::Vector::operator=((Vector *)(this + 0x138),(Vector *)(param_1 + 0x138));
    AEMath::Vector::operator=((Vector *)(this + 0x144),(Vector *)(param_1 + 0x144));
    AEMath::Matrix::operator=((Matrix *)(this + 0x5c),param_1 + 0x5c);
    uVar8 = *(undefined8 *)(param_1 + 0x158);
    *(undefined8 *)(this + 0x150) = *(undefined8 *)(param_1 + 0x150);
    *(undefined8 *)(this + 0x158) = uVar8;
    AEMath::Vector::operator=((Vector *)(this + 0x160),(Vector *)(param_1 + 0x160));
    AEMath::Vector::operator=((Vector *)(this + 0x16c),(Vector *)(param_1 + 0x16c));
    AEMath::Matrix::operator=((Matrix *)(this + 0x98),param_1 + 0x98);
    *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
    if (*(int *)(param_1 + 0x3c) != 0) {
      uVar3 = 0;
      do {
        this_00 = operator_new(0x88);
        Mesh::Mesh(this_00,*(Mesh **)(*(int *)(param_1 + 0x40) + uVar3 * 4));
        *(int *)(this + 0x44) = *(int *)(this + 0x3c) + 1;
        pvVar2 = realloc(*(void **)(this + 0x40),(*(int *)(this + 0x3c) + 1) * 4);
        *(void **)(this + 0x40) = pvVar2;
        uVar3 = uVar3 + 1;
        *(Mesh **)((int)pvVar2 + *(int *)(this + 0x3c) * 4) = this_00;
        *(undefined4 *)(this + 0x3c) = *(undefined4 *)(this + 0x44);
      } while (uVar3 < *(uint *)(param_1 + 0x3c));
    }
    ArraySet<AbyssEngine::KeyFrame*>
              (*(KeyFrame ***)(param_1 + 0x120),*(uint *)(param_1 + 0x11c),(Array *)(this + 0x11c));
    if (*(int *)(param_1 + 0x4c) != 0) {
      uVar3 = 0;
      do {
        this_01 = operator_new(0x180);
        Transform(this_01,*(Transform **)(*(int *)(param_1 + 0x50) + uVar3 * 4));
        *(int *)(this + 0x54) = *(int *)(this + 0x4c) + 1;
        pvVar2 = realloc(*(void **)(this + 0x50),(*(int *)(this + 0x4c) + 1) * 4);
        *(void **)(this + 0x50) = pvVar2;
        uVar3 = uVar3 + 1;
        *(Transform **)((int)pvVar2 + *(int *)(this + 0x4c) * 4) = this_01;
        *(undefined4 *)(this + 0x4c) = *(undefined4 *)(this + 0x54);
      } while (uVar3 < *(uint *)(param_1 + 0x4c));
    }
    AEMath::BSphere::operator=((BSphere *)(this + 0xd4),(BSphere *)(param_1 + 0xd4));
    this[0x17c] = (Transform)0x1;
    this[0x17d] = (Transform)0x1;
    this[0xec] = (Transform)0x1;
  }
  if (__stack_chk_guard - local_4c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_4c);
  }
  return;
}

// ===== AbyssEngine::Transform::CollectAnimationData  @0x0007e250  (166 bytes)
/* AbyssEngine::Transform::CollectAnimationData() */

void __thiscall AbyssEngine::Transform::CollectAnimationData(Transform *this)

{
  int iVar1;
  Transform *this_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if (*(int *)(this + 0x3c) != 0) {
    iVar3 = *(int *)(this + 0x40);
    uVar5 = 0;
    do {
      iVar1 = *(int *)(iVar3 + uVar5 * 4);
      if ((iVar1 != 0) && (this_00 = *(Transform **)(iVar1 + 0x34), this_00 != (Transform *)0x0)) {
        CollectAnimationData(this_00);
        iVar3 = *(int *)(this + 0x40);
        iVar4 = *(int *)(this + 0xfc);
        iVar1 = *(int *)(*(int *)(iVar3 + uVar5 * 4) + 0x34);
        uVar2 = *(uint *)(iVar1 + 0xf8);
        iVar1 = *(int *)(iVar1 + 0xfc);
        bVar6 = *(uint *)(this + 0xf8) < uVar2;
        if ((int)((iVar4 - iVar1) - (uint)bVar6) < 0 !=
            (SBORROW4(iVar4,iVar1) != SBORROW4(iVar4 - iVar1,(uint)bVar6))) {
          *(uint *)(this + 0xf8) = uVar2;
          *(int *)(this + 0xfc) = iVar1;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(this + 0x3c));
  }
  if (*(int *)(this + 0x4c) != 0) {
    iVar3 = *(int *)(this + 0x50);
    uVar5 = 0;
    do {
      CollectAnimationData(*(Transform **)(iVar3 + uVar5 * 4));
      iVar3 = *(int *)(this + 0x50);
      iVar4 = *(int *)(this + 0xfc);
      iVar1 = *(int *)(iVar3 + uVar5 * 4);
      uVar5 = uVar5 + 1;
      uVar2 = *(uint *)(iVar1 + 0xf8);
      iVar1 = *(int *)(iVar1 + 0xfc);
      bVar6 = *(uint *)(this + 0xf8) < uVar2;
      if ((int)((iVar4 - iVar1) - (uint)bVar6) < 0 !=
          (SBORROW4(iVar4,iVar1) != SBORROW4(iVar4 - iVar1,(uint)bVar6))) {
        *(uint *)(this + 0xf8) = uVar2;
        *(int *)(this + 0xfc) = iVar1;
      }
    } while (uVar5 < *(uint *)(this + 0x4c));
  }
  if (*(int *)(this + 0x11c) != 0) {
    iVar1 = *(int *)(this + 0xfc);
    iVar3 = *(int *)(*(int *)(this + 0x120) + *(int *)(this + 0x11c) * 4 + -4);
    uVar5 = *(uint *)(iVar3 + 0x50);
    iVar3 = *(int *)(iVar3 + 0x54);
    bVar6 = *(uint *)(this + 0xf8) < uVar5;
    if ((int)((iVar1 - iVar3) - (uint)bVar6) < 0 !=
        (SBORROW4(iVar1,iVar3) != SBORROW4(iVar1 - iVar3,(uint)bVar6))) {
      *(uint *)(this + 0xf8) = uVar5;
      *(int *)(this + 0xfc) = iVar3;
    }
  }
  return;
}

// ===== AbyssEngine::Transform::SetAnimationState  @0x0007e2f6  (32 bytes)
/* AbyssEngine::Transform::SetAnimationState(AbyssEngine::AnimationMode, void*) */

void AbyssEngine::Transform::SetAnimationState(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0xed) = 0;
  }
  else if (param_2 == 3) {
    *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_1 + 0x100);
    *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_1 + 0x104);
    *(undefined1 *)(param_1 + 0xed) = 1;
    return;
  }
  *(int *)(param_1 + 0x58) = param_2;
  return;
}

// ===== AbyssEngine::Transform::SetAnimationSpeed  @0x0007e316  (6 bytes)
/* AbyssEngine::Transform::SetAnimationSpeed(float) */

void __thiscall AbyssEngine::Transform::SetAnimationSpeed(Transform *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xf0) = in_r1;
  return;
}

// ===== AbyssEngine::Transform::InitAnimationRangeInTime  @0x0007e31c  (108 bytes)
/* AbyssEngine::Transform::InitAnimationRangeInTime() */

void __thiscall AbyssEngine::Transform::InitAnimationRangeInTime(Transform *this)

{
  Transform *this_00;
  uint uVar1;
  uint extraout_r1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(this + 0xf8) != 0 || *(int *)(this + 0xfc) != 0) {
    iVar2 = *(int *)(this + 0xe8);
    *(int *)(this + 0x100) = iVar2;
    *(int *)(this + 0x104) = iVar2 >> 0x1f;
    *(int *)(this + 0x108) = *(int *)(this + 0xf8);
    *(int *)(this + 0x10c) = *(int *)(this + 0xfc);
    *(int *)(this + 0x110) = iVar2;
    *(int *)(this + 0x114) = iVar2 >> 0x1f;
    uVar1 = *(uint *)(this + 0x3c);
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        iVar2 = *(int *)(*(int *)(this + 0x40) + uVar3 * 4);
        if ((iVar2 != 0) && (this_00 = *(Transform **)(iVar2 + 0x34), this_00 != (Transform *)0x0))
        {
          InitAnimationRangeInTime(this_00);
          uVar1 = *(uint *)(this + 0x3c);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    if (*(int *)(this + 0x4c) != 0) {
      uVar3 = 0;
      do {
        InitAnimationRangeInTime(*(Transform **)(*(int *)(this + 0x50) + uVar3 * 4));
        uVar3 = uVar3 + 1;
        uVar1 = extraout_r1;
      } while (uVar3 < *(uint *)(this + 0x4c));
    }
    Update(CONCAT44(uVar1,this),false);
  }
  return;
}

// ===== AbyssEngine::Transform::Update  @0x0007e388  (464 bytes)
/* AbyssEngine::Transform::Update(long long, bool) */

void AbyssEngine::Transform::Update(longlong param_1,bool param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int extraout_r1;
  uint uVar4;
  uint extraout_r2;
  int iVar5;
  int extraout_r3;
  int iVar6;
  uint uVar7;
  BSphere *this;
  bool bVar8;
  longlong lVar9;
  int in_stack_00000000;
  AEMath aAStack_4c [12];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  int local_28;
  
  iVar1 = (int)param_1;
  local_28 = __stack_chk_guard;
  if ((*(char *)(iVar1 + 0xed) != '\0') &&
     ((int)(uint)(*(int *)(iVar1 + 0xf8) == 0) <= *(int *)(iVar1 + 0xfc))) {
    fVar2 = (float)__aeabi_l2f(param_2);
    lVar9 = __aeabi_f2lz(fVar2 * *(float *)(iVar1 + 0xf0));
    lVar9 = lVar9 + *(longlong *)(iVar1 + 0x110);
    iVar3 = (int)((ulonglong)lVar9 >> 0x20);
    *(longlong *)(iVar1 + 0x110) = lVar9;
    uVar4 = *(uint *)(iVar1 + 0x108);
    iVar5 = *(int *)(iVar1 + 0x10c);
    bVar8 = uVar4 < (uint)lVar9;
    if ((int)((iVar5 - iVar3) - (uint)bVar8) < 0 !=
        (SBORROW4(iVar5,iVar3) != SBORROW4(iVar5 - iVar3,(uint)bVar8))) {
      if (*(int *)(iVar1 + 0x58) == 2) {
        uVar7 = *(uint *)(iVar1 + 0x100);
        iVar6 = *(int *)(iVar1 + 0x104);
        if (uVar4 != 0 || iVar5 != 0) {
          __aeabi_ldivmod();
          bVar8 = CARRY4(uVar7,extraout_r2);
          uVar7 = uVar7 + extraout_r2;
          iVar6 = iVar6 + extraout_r3 + (uint)bVar8;
          iVar3 = extraout_r1;
        }
        *(uint *)(iVar1 + 0x110) = uVar7;
        *(int *)(iVar1 + 0x114) = iVar6;
        lVar9 = CONCAT44(iVar3,uVar7);
      }
      else {
        *(undefined1 *)(iVar1 + 0xed) = 0;
        *(uint *)(iVar1 + 0x110) = uVar4;
        *(int *)(iVar1 + 0x114) = iVar5;
        lVar9 = CONCAT44(iVar3,uVar4);
      }
    }
    InternUpdate(CONCAT44((int)((ulonglong)lVar9 >> 0x20),iVar1),SUB81(lVar9,0));
  }
  if (in_stack_00000000 == 1) {
    uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_38 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    this = (BSphere *)(iVar1 + 0xd4);
    local_40 = 0;
    local_30 = 0x3f800000;
    AEMath::BSphere::operator=(this,(BSphere *)&local_40);
    if (*(int *)(iVar1 + 0x3c) != 0) {
      uVar4 = 0;
      do {
        iVar3 = *(int *)(*(int *)(iVar1 + 0x40) + uVar4 * 4);
        if ((iVar3 == 0) || (*(uint *)(iVar3 + 0x34) == 0)) {
          local_40 = *(undefined4 *)(iVar3 + 0x3c);
          uStack_3c = *(undefined4 *)(iVar3 + 0x40);
          uStack_38 = *(undefined4 *)(iVar3 + 0x44);
          uStack_34 = *(undefined4 *)(iVar3 + 0x48);
          local_30 = *(undefined4 *)(iVar3 + 0x4c);
        }
        else {
          Update((ulonglong)*(uint *)(iVar3 + 0x34),param_2);
          iVar3 = *(int *)(*(int *)(iVar1 + 0x40) + uVar4 * 4);
          local_40 = *(undefined4 *)(iVar3 + 0x3c);
          uStack_3c = *(undefined4 *)(iVar3 + 0x40);
          uStack_38 = *(undefined4 *)(iVar3 + 0x44);
          uStack_34 = *(undefined4 *)(iVar3 + 0x48);
          local_30 = *(undefined4 *)(iVar3 + 0x4c);
          AEMath::MatrixTransformVector
                    (aAStack_4c,
                     (Matrix *)
                     (*(int *)(*(int *)(*(int *)(iVar1 + 0x40) + uVar4 * 4) + 0x34) + 0x5c),
                     (Vector *)&local_40);
          AEMath::Vector::operator=((Vector *)&local_40,(Vector *)aAStack_4c);
        }
        AEMath::BSphere::Merge(this,(BSphere *)&local_40);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar1 + 0x3c));
    }
    if (*(int *)(iVar1 + 0x4c) != 0) {
      uVar4 = 0;
      do {
        Update((ulonglong)*(uint *)(*(int *)(iVar1 + 0x50) + uVar4 * 4),param_2);
        iVar3 = *(int *)(*(int *)(iVar1 + 0x50) + uVar4 * 4);
        local_40 = *(undefined4 *)(iVar3 + 0xd4);
        uStack_3c = *(undefined4 *)(iVar3 + 0xd8);
        uStack_38 = *(undefined4 *)(iVar3 + 0xdc);
        uStack_34 = *(undefined4 *)(iVar3 + 0xe0);
        local_30 = *(undefined4 *)(iVar3 + 0xe4);
        AEMath::MatrixTransformVector
                  (aAStack_4c,(Matrix *)(*(int *)(*(int *)(iVar1 + 0x50) + uVar4 * 4) + 0x5c),
                   (Vector *)&local_40);
        AEMath::Vector::operator=((Vector *)&local_40,(Vector *)aAStack_4c);
        AEMath::BSphere::Merge(this,(BSphere *)&local_40);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar1 + 0x4c));
    }
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Transform::SetAnimationRangeInTime  @0x0007e560  (290 bytes)
/* AbyssEngine::Transform::SetAnimationRangeInTime(long long, long long) */

void AbyssEngine::Transform::SetAnimationRangeInTime(longlong param_1,longlong param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint extraout_r1;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint in_stack_00000000;
  uint in_stack_00000004;
  
  iVar3 = (int)param_1;
  uVar8 = (uint)((ulonglong)param_2 >> 0x20);
  uVar6 = (uint)param_2;
  uVar5 = *(uint *)(iVar3 + 0xf8);
  uVar7 = *(uint *)(iVar3 + 0xfc);
  if (uVar5 != 0 || uVar7 != 0) {
    bVar1 = (int)((uVar7 - uVar8) - (uint)(uVar5 < uVar6)) < 0 ==
            (SBORROW4(uVar7,uVar8) != SBORROW4(uVar7 - uVar8,(uint)(uVar5 < uVar6))) &&
            uVar8 < 0x80000000;
    uVar9 = 0;
    if (bVar1) {
      uVar9 = uVar8;
    }
    *(uint *)(iVar3 + 0x104) = uVar9;
    uVar9 = 0;
    if (bVar1) {
      uVar9 = uVar6;
    }
    *(uint *)(iVar3 + 0x100) = uVar9;
    bVar1 = (int)((uVar7 - in_stack_00000004) - (uint)(uVar5 < in_stack_00000000)) < 0 ==
            (SBORROW4(uVar7,in_stack_00000004) !=
            SBORROW4(uVar7 - in_stack_00000004,(uint)(uVar5 < in_stack_00000000)));
    if (-1 < (int)in_stack_00000004 && bVar1) {
      uVar7 = in_stack_00000004;
    }
    *(uint *)(iVar3 + 0x10c) = uVar7;
    if (-1 < (int)in_stack_00000004 && bVar1) {
      uVar5 = in_stack_00000000;
    }
    *(uint *)(iVar3 + 0x108) = uVar5;
    uVar7 = *(uint *)(iVar3 + 0x110);
    uVar9 = *(uint *)(iVar3 + 0x114);
    bVar1 = (int)((in_stack_00000004 - uVar9) - (uint)(in_stack_00000000 < uVar7)) < 0 !=
            (SBORROW4(in_stack_00000004,uVar9) !=
            SBORROW4(in_stack_00000004 - uVar9,(uint)(in_stack_00000000 < uVar7)));
    uVar5 = uVar9;
    if (bVar1) {
      uVar5 = in_stack_00000004;
    }
    bVar2 = (int)((uVar9 - uVar8) - (uint)(uVar7 < uVar6)) < 0 !=
            (SBORROW4(uVar9,uVar8) != SBORROW4(uVar9 - uVar8,(uint)(uVar7 < uVar6)));
    if (bVar2) {
      uVar5 = uVar8;
    }
    *(uint *)(iVar3 + 0x114) = uVar5;
    if (bVar1) {
      uVar7 = in_stack_00000000;
    }
    if (bVar2) {
      uVar7 = uVar6;
    }
    *(uint *)(iVar3 + 0x110) = uVar7;
    uVar5 = *(uint *)(iVar3 + 0x3c);
    if (uVar5 != 0) {
      uVar7 = 0;
      do {
        iVar4 = *(int *)(*(int *)(iVar3 + 0x40) + uVar7 * 4);
        if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x34), iVar4 != 0)) {
          SetAnimationRangeInTime(CONCAT44(uVar5,iVar4),param_2);
          uVar5 = *(uint *)(iVar3 + 0x3c);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar5);
    }
    if (*(int *)(iVar3 + 0x4c) != 0) {
      uVar7 = 0;
      do {
        SetAnimationRangeInTime
                  (CONCAT44(uVar5,*(undefined4 *)(*(int *)(iVar3 + 0x50) + uVar7 * 4)),param_2);
        uVar7 = uVar7 + 1;
        uVar5 = extraout_r1;
      } while (uVar7 < *(uint *)(iVar3 + 0x4c));
    }
    Update(CONCAT44(uVar5,iVar3),false);
  }
  return;
}

// ===== AbyssEngine::Transform::SetAnimationRangeInKeyFrames  @0x0007e682  (82 bytes)
/* AbyssEngine::Transform::SetAnimationRangeInKeyFrames(int, int) */

void __thiscall
AbyssEngine::Transform::SetAnimationRangeInKeyFrames(Transform *this,int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_1 < 0) || (*(int *)(this + 0x11c) <= param_1)) {
    uVar2 = 0;
    uVar3 = 0;
  }
  else {
    param_1 = *(int *)(*(int *)(this + 0x120) + param_1 * 4);
    uVar2 = *(undefined4 *)(param_1 + 0x50);
    uVar3 = *(undefined4 *)(param_1 + 0x54);
  }
  if (-1 < param_2) {
    param_1 = *(int *)(this + 0x11c);
  }
  if (-1 < param_2 && param_2 <= param_1) {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(this + 0x120) + param_2 * 4) + 0x54);
  }
  else {
    uVar1 = 0;
  }
  SetAnimationRangeInTime(CONCAT44(uVar1,this),CONCAT44(uVar3,uVar2));
  return;
}

// ===== AbyssEngine::Transform::SetAnimationLength  @0x0007e6d4  (10 bytes)
/* AbyssEngine::Transform::SetAnimationLength(long long) */

void AbyssEngine::Transform::SetAnimationLength(longlong param_1)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 0xf8) = in_r2;
  *(undefined4 *)(iVar1 + 0xfc) = in_r3;
  *(undefined4 *)(iVar1 + 0x108) = in_r2;
  *(undefined4 *)(iVar1 + 0x10c) = in_r3;
  return;
}

// ===== AbyssEngine::Transform::PauseAnimationWithKeyFrame  @0x0007e6de  (56 bytes)
/* AbyssEngine::Transform::PauseAnimationWithKeyFrame(int) */

void __thiscall AbyssEngine::Transform::PauseAnimationWithKeyFrame(Transform *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((-1 < param_1) && (param_1 < *(int *)(this + 0x11c))) {
    iVar1 = *(int *)(*(int *)(this + 0x120) + param_1 * 4);
    uVar2 = *(undefined4 *)(iVar1 + 0x50);
    uVar3 = *(undefined4 *)(iVar1 + 0x54);
    *(undefined4 *)(this + 0x110) = uVar2;
    *(undefined4 *)(this + 0x114) = uVar3;
    InternUpdate(CONCAT44(param_1,this),SUB41(uVar2,0));
  }
  this[0xed] = (Transform)0x0;
  return;
}

// ===== AbyssEngine::Transform::InternUpdate  @0x0007e720  (2062 bytes)
/* AbyssEngine::Transform::InternUpdate(long long, bool) */

void AbyssEngine::Transform::InternUpdate(longlong param_1,bool param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  float fVar9;
  float fVar10;
  Quaternion *this;
  undefined4 *puVar11;
  int iVar12;
  uint uVar13;
  AEMath *pAVar14;
  int in_r3;
  uint uVar15;
  int iVar16;
  AEMath *this_00;
  int iVar17;
  int iVar18;
  uint uVar19;
  BSphere *this_01;
  float fVar20;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s2_00;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined4 uVar24;
  float fVar25;
  undefined4 uVar26;
  float fVar27;
  int in_stack_00000000;
  AEMath aAStack_2f8 [60];
  AEMath aAStack_2bc [60];
  AEMath aAStack_280 [60];
  AEMath aAStack_244 [60];
  undefined4 local_208 [5];
  undefined4 local_1f4;
  undefined4 local_1f0;
  float fStack_1ec;
  undefined4 uStack_1e8;
  float fStack_1e4;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined4 local_1d0;
  undefined4 local_1c8 [5];
  undefined4 local_1b4;
  undefined4 local_1b0;
  float fStack_1ac;
  undefined4 uStack_1a8;
  float fStack_1a4;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined4 local_190;
  undefined4 local_188 [5];
  undefined4 local_174;
  undefined4 local_170;
  float fStack_16c;
  undefined4 uStack_168;
  float fStack_164;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined4 local_150;
  undefined4 local_148 [3];
  float local_13c;
  undefined4 local_134;
  undefined4 local_130;
  float fStack_12c;
  undefined4 uStack_128;
  float fStack_124;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined4 local_110;
  undefined4 local_108 [3];
  undefined4 local_fc;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  float fStack_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  undefined4 local_c8 [3];
  undefined4 local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  float fStack_a4;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined4 local_88;
  float fStack_84;
  undefined4 local_80;
  undefined4 local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float fStack_6c;
  undefined4 local_68;
  float local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  int local_4c;
  
  iVar7 = (int)param_1;
  uVar15 = (uint)param_2;
  local_4c = __stack_chk_guard;
  if (*(int *)(iVar7 + 0x11c) != 0) {
    uVar19 = *(uint *)(iVar7 + 0x100);
    iVar17 = *(int *)(iVar7 + 0x104);
    iVar12 = (*(int **)(iVar7 + 0x120))[*(int *)(iVar7 + 0x11c) + -1];
    uVar13 = *(uint *)(iVar12 + 0x50);
    iVar12 = *(int *)(iVar12 + 0x54);
    if ((int)((iVar17 - in_r3) - (uint)(uVar19 < uVar15)) < 0 !=
        (SBORROW4(iVar17,in_r3) != SBORROW4(iVar17 - in_r3,(uint)(uVar19 < uVar15)))) {
      uVar19 = uVar15;
      iVar17 = in_r3;
    }
    if ((int)((iVar12 - iVar17) - (uint)(uVar13 < uVar19)) < 0 !=
        (SBORROW4(iVar12,iVar17) != SBORROW4(iVar12 - iVar17,(uint)(uVar13 < uVar19)))) {
      uVar19 = uVar13;
      iVar17 = iVar12;
    }
    iVar12 = -1;
    piVar6 = *(int **)(iVar7 + 0x120);
    do {
      piVar8 = piVar6;
      iVar16 = *piVar8;
      iVar12 = iVar12 + 1;
      uVar15 = *(uint *)(iVar16 + 0x50);
      iVar18 = *(int *)(iVar16 + 0x54);
      piVar6 = piVar8 + 1;
    } while ((int)((iVar18 - iVar17) - (uint)(uVar15 < uVar19)) < 0 !=
             (SBORROW4(iVar18,iVar17) != SBORROW4(iVar18 - iVar17,(uint)(uVar15 < uVar19))));
    *(int *)(iVar7 + 0x118) = iVar12;
    if (iVar12 == 0) {
      fStack_6c = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      local_68 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      local_64 = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar11 = (undefined4 *)((uint)&local_88 | 4);
      local_88 = 0x3f800000;
      *puVar11 = 0;
      puVar11[1] = fStack_6c;
      puVar11[2] = local_68;
      puVar11[3] = local_64;
      local_74 = 0x3f800000;
      local_70 = 0.0;
      local_60 = 0x3f800000;
      uStack_58 = 0x3f8000003f800000;
      local_50 = 0x3f800000;
      AEMath::Matrix::operator=((Matrix *)(iVar7 + 0x98),(Matrix *)&local_88);
      if (Engine::enableShader == '\0') {
        *(undefined4 *)(iVar7 + 0xac) = 0xbf800000;
      }
      goto LAB_0007ef12;
    }
    if (uVar19 == 0 && iVar17 == 0) {
      this = (Quaternion *)
             Quaternion::Quaternion
                       ((Quaternion *)&local_88,*(undefined4 *)(iVar16 + 0x18),
                        *(undefined4 *)(iVar16 + 0x1c),*(undefined4 *)(iVar16 + 0x20));
      *(undefined4 *)(iVar7 + 0x128) = local_88;
      *(float *)(iVar7 + 300) = fStack_84;
      *(undefined4 *)(iVar7 + 0x130) = local_80;
      *(undefined4 *)(iVar7 + 0x134) = local_7c;
      Quaternion::~Quaternion(this);
      AEMath::Vector::operator=
                ((Vector *)(iVar7 + 0x138),
                 *(Vector **)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4));
      AEMath::Vector::operator=
                ((Vector *)(iVar7 + 0x144),
                 (Vector *)(*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4) + 0xc));
      iVar17 = *(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4);
      *(undefined4 *)(iVar7 + 0x178) = *(undefined4 *)(iVar17 + 0x48);
      Quaternion::Quaternion
                ((Quaternion *)&local_88,*(undefined4 *)(iVar17 + 0x3c),
                 *(undefined4 *)(iVar17 + 0x40),*(undefined4 *)(iVar17 + 0x44));
      *(undefined4 *)(iVar7 + 0x150) = local_88;
      *(float *)(iVar7 + 0x154) = fStack_84;
      *(undefined4 *)(iVar7 + 0x158) = local_80;
      *(undefined4 *)(iVar7 + 0x15c) = local_7c;
      Quaternion::~Quaternion((Quaternion *)&local_88);
      AEMath::Vector::operator=
                ((Vector *)(iVar7 + 0x160),
                 (Vector *)(*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4) + 0x24))
      ;
      pAVar14 = (AEMath *)(*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4) + 0x30);
    }
    else {
      iVar12 = piVar8[-1];
      uVar13 = *(uint *)(iVar12 + 0x50);
      iVar16 = *(int *)(iVar12 + 0x54);
      Quaternion::Quaternion
                ((Quaternion *)local_c8,*(undefined4 *)(iVar12 + 0x18),
                 *(undefined4 *)(iVar12 + 0x1c),*(undefined4 *)(iVar12 + 0x20));
      fVar9 = (float)__aeabi_l2f(uVar19 - uVar13,(iVar17 - iVar16) - (uint)(uVar19 < uVar13));
      fVar10 = (float)__aeabi_l2f(uVar15 - uVar13,(iVar18 - iVar16) - (uint)(uVar15 < uVar13));
      iVar17 = *(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4);
      Quaternion::Quaternion
                ((Quaternion *)local_108,*(undefined4 *)(iVar17 + 0x18),
                 *(undefined4 *)(iVar17 + 0x1c),*(undefined4 *)(iVar17 + 0x20));
      fVar9 = fVar9 / fVar10;
      Quaternion::Lerp((Quaternion *)&local_88,(Quaternion *)local_c8,fVar10);
      *(undefined4 *)(iVar7 + 0x128) = local_88;
      *(float *)(iVar7 + 300) = fStack_84;
      *(undefined4 *)(iVar7 + 0x130) = local_80;
      *(undefined4 *)(iVar7 + 0x134) = local_7c;
      Quaternion::~Quaternion((Quaternion *)&local_88);
      Quaternion::~Quaternion((Quaternion *)local_108);
      fVar10 = (float)Quaternion::~Quaternion((Quaternion *)local_c8);
      AEMath::VectorLerp((AEMath *)&local_88,
                         *(Vector **)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4 + -4),
                         *(Vector **)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4),fVar10)
      ;
      fVar10 = (float)AEMath::Vector::operator=((Vector *)(iVar7 + 0x138),(Vector *)&local_88);
      AEMath::VectorLerp((AEMath *)&local_88,
                         (Vector *)
                         (*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4 + -4) + 0xc
                         ),(Vector *)
                           (*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4) + 0xc),
                         fVar10);
      AEMath::Vector::operator=((Vector *)(iVar7 + 0x144),(Vector *)&local_88);
      iVar17 = *(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4 + -4);
      *(float *)(iVar7 + 0x178) =
           *(float *)(iVar17 + 0x48) +
           fVar9 * (*(float *)(*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4) +
                              0x48) - *(float *)(iVar17 + 0x48));
      Quaternion::Quaternion
                ((Quaternion *)local_c8,*(undefined4 *)(iVar17 + 0x3c),
                 *(undefined4 *)(iVar17 + 0x40),*(undefined4 *)(iVar17 + 0x44));
      iVar17 = *(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4);
      fVar9 = (float)Quaternion::Quaternion
                               ((Quaternion *)local_108,*(undefined4 *)(iVar17 + 0x3c),
                                *(undefined4 *)(iVar17 + 0x40),*(undefined4 *)(iVar17 + 0x44));
      Quaternion::Lerp((Quaternion *)&local_88,(Quaternion *)local_c8,fVar9);
      *(undefined4 *)(iVar7 + 0x150) = local_88;
      *(float *)(iVar7 + 0x154) = fStack_84;
      *(undefined4 *)(iVar7 + 0x158) = local_80;
      *(undefined4 *)(iVar7 + 0x15c) = local_7c;
      Quaternion::~Quaternion((Quaternion *)&local_88);
      Quaternion::~Quaternion((Quaternion *)local_108);
      fVar9 = (float)Quaternion::~Quaternion((Quaternion *)local_c8);
      AEMath::VectorLerp((AEMath *)&local_88,
                         (Vector *)
                         (*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4 + -4) +
                         0x24),(Vector *)
                               (*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4) +
                               0x24),fVar9);
      fVar9 = (float)AEMath::Vector::operator=((Vector *)(iVar7 + 0x160),(Vector *)&local_88);
      pAVar14 = (AEMath *)&local_88;
      AEMath::VectorLerp(pAVar14,(Vector *)
                                 (*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4 +
                                          -4) + 0x30),
                         (Vector *)
                         (*(int *)(*(int *)(iVar7 + 0x120) + *(int *)(iVar7 + 0x118) * 4) + 0x30),
                         fVar9);
    }
    AEMath::Vector::operator=((Vector *)(iVar7 + 0x16c),(Vector *)pAVar14);
    uVar24 = 0;
    fVar25 = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar26 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    fVar27 = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    *(int *)(iVar7 + 0x48) = (int)(*(float *)(iVar7 + 0x178) * 255.0) * 0x1010101;
    puVar11 = (undefined4 *)((uint)&local_88 | 4);
    local_88 = 0x3f800000;
    *puVar11 = 0;
    puVar11[1] = fVar25;
    puVar11[2] = uVar26;
    puVar11[3] = fVar27;
    local_74 = 0x3f800000;
    local_70 = 0.0;
    local_60 = 0x3f800000;
    uStack_58 = 0x3f8000003f800000;
    local_50 = 0x3f800000;
    fStack_6c = fVar25;
    local_68 = uVar26;
    local_64 = fVar27;
    Quaternion::Convert((Quaternion *)(iVar7 + 0x128),(Matrix *)&local_88);
    *(undefined4 *)(iVar7 + 0x5c) = local_88;
    *(undefined4 *)(iVar7 + 0x60) = local_80;
    *(float *)(iVar7 + 100) = -fStack_84;
    *(undefined4 *)(iVar7 + 0x68) = local_7c;
    *(undefined4 *)(iVar7 + 0x6c) = local_68;
    *(undefined4 *)(iVar7 + 0x70) = (undefined4)local_60;
    *(float *)(iVar7 + 0x74) = -local_64;
    *(undefined4 *)(iVar7 + 0x78) = local_60._4_4_;
    *(float *)(iVar7 + 0x7c) = -local_78;
    *(float *)(iVar7 + 0x80) = -local_70;
    *(undefined4 *)(iVar7 + 0x84) = local_74;
    *(float *)(iVar7 + 0x88) = -fStack_6c;
    AEMath::MatrixSetScaling
              ((AEMath *)local_c8,(Matrix *)(iVar7 + 0x5c),*(float *)(iVar7 + 0x14c),extraout_s1,
               extraout_s2);
    AEMath::MatrixSetTranslation
              ((AEMath *)local_c8,(Matrix *)(iVar7 + 0x5c),*(float *)(iVar7 + 0x140),extraout_s1_00,
               extraout_s2_00);
    fVar21 = *(float *)(iVar7 + 0x154);
    fVar22 = *(float *)(iVar7 + 0x158);
    fVar20 = *(float *)(iVar7 + 0x150);
    fVar23 = *(float *)(iVar7 + 0x15c);
    fVar4 = fVar20 * fVar20 + fVar22 * fVar22;
    fVar5 = fVar20 * fVar20 + fVar21 * fVar21;
    fVar9 = fVar20 * fVar21 - fVar22 * fVar23;
    fVar10 = fVar20 * fVar21 + fVar22 * fVar23;
    fVar3 = fVar21 * fVar22 - fVar20 * fVar23;
    fVar1 = fVar20 * fVar22 + fVar21 * fVar23;
    fVar2 = fVar20 * fVar22 - fVar21 * fVar23;
    fVar20 = fVar21 * fVar22 + fVar20 * fVar23;
    fVar5 = 1.0 - (fVar5 + fVar5);
    *(float *)(iVar7 + 0x98) = (fVar21 * fVar21 + fVar22 * fVar22) * -2.0 + 1.0;
    *(float *)(iVar7 + 0x9c) = fVar9 + fVar9;
    *(float *)(iVar7 + 0xa0) = fVar1 + fVar1;
    *(float *)(iVar7 + 0xa8) = fVar10 + fVar10;
    *(float *)(iVar7 + 0xac) = 1.0 - (fVar4 + fVar4);
    *(float *)(iVar7 + 0xb0) = fVar3 + fVar3;
    *(undefined4 *)(iVar7 + 0xc4) = 0;
    *(float *)(iVar7 + 0xb8) = fVar2 + fVar2;
    *(float *)(iVar7 + 0xbc) = fVar20 + fVar20;
    *(float *)(iVar7 + 0xc0) = fVar5;
    *(undefined4 *)(iVar7 + 0xb4) = 0;
    *(undefined4 *)(iVar7 + 0xa4) = 0;
    puVar11 = (undefined4 *)((uint)local_c8 | 4);
    local_c8[0] = 0x3f800000;
    *puVar11 = uVar24;
    puVar11[1] = fVar25;
    puVar11[2] = uVar26;
    puVar11[3] = fVar27;
    local_b4 = 0x3f800000;
    local_a0 = 0x3f800000;
    uStack_98 = 0x3f8000003f800000;
    puVar11 = (undefined4 *)((uint)local_108 | 4);
    local_108[0] = 0x3f800000;
    *puVar11 = uVar24;
    puVar11[1] = fVar25;
    puVar11[2] = uVar26;
    puVar11[3] = fVar27;
    local_f4 = 0x3f800000;
    local_e0 = 0x3f800000;
    uStack_d8 = 0x3f8000003f800000;
    puVar11 = (undefined4 *)((uint)local_148 | 4);
    local_148[0] = 0x3f800000;
    *puVar11 = uVar24;
    puVar11[1] = fVar25;
    puVar11[2] = uVar26;
    puVar11[3] = fVar27;
    local_134 = 0x3f800000;
    local_120 = 0x3f800000;
    uStack_118 = 0x3f8000003f800000;
    puVar11 = (undefined4 *)((uint)local_188 | 4);
    local_188[0] = 0x3f800000;
    *puVar11 = uVar24;
    puVar11[1] = fVar25;
    puVar11[2] = uVar26;
    puVar11[3] = fVar27;
    local_174 = 0x3f800000;
    local_160 = 0x3f800000;
    uStack_158 = 0x3f8000003f800000;
    puVar11 = (undefined4 *)((uint)local_1c8 | 4);
    local_1c8[0] = 0x3f800000;
    *puVar11 = uVar24;
    puVar11[1] = fVar25;
    puVar11[2] = uVar26;
    puVar11[3] = fVar27;
    local_1b4 = 0x3f800000;
    local_1a0 = 0x3f800000;
    uStack_198 = 0x3f8000003f800000;
    local_90 = 0x3f800000;
    local_bc = 0xbf000000;
    uStack_ac = 0xbf000000;
    local_d0 = 0x3f800000;
    local_110 = 0x3f800000;
    local_150 = 0x3f800000;
    local_190 = 0x3f800000;
    local_13c = *(float *)(iVar7 + 0x16c) * *(float *)(iVar7 + 0x160) + 0.5;
    local_fc = 0x3f000000;
    uStack_ec = 0x3f000000;
    fStack_12c = *(float *)(iVar7 + 0x170) * *(float *)(iVar7 + 0x164) + 0.5;
    local_1b0 = uVar24;
    fStack_1ac = fVar25;
    uStack_1a8 = uVar26;
    fStack_1a4 = fVar27;
    local_170 = uVar24;
    fStack_16c = fVar25;
    uStack_168 = uVar26;
    fStack_164 = fVar27;
    local_130 = uVar24;
    uStack_128 = uVar26;
    fStack_124 = fVar27;
    local_f0 = uVar24;
    uStack_e8 = uVar26;
    fStack_e4 = fVar27;
    local_b0 = uVar24;
    uStack_a8 = uVar26;
    fStack_a4 = fVar27;
    AEMath::MatrixSetScaling
              ((AEMath *)local_208,(Matrix *)local_188,fStack_12c,fVar5,*(float *)(iVar7 + 0x16c));
    AEMath::operator*(aAStack_244,(Matrix *)local_108,(Matrix *)(iVar7 + 0x98));
    AEMath::operator*((AEMath *)local_208,aAStack_244,(Matrix *)local_c8);
    AEMath::Matrix::operator=((Matrix *)local_1c8,(AEMath *)local_208);
    if (Engine::enableShader == '\0') {
      puVar11 = (undefined4 *)((uint)local_208 | 4);
      local_208[0] = 0x3f800000;
      *puVar11 = uVar24;
      puVar11[1] = fVar25;
      puVar11[2] = uVar26;
      puVar11[3] = fVar27;
      local_1e0 = 0x3f800000;
      uStack_1d8 = 0x3f8000003f800000;
      local_1d0 = 0x3f800000;
      local_1f4 = 0xbf800000;
      local_1f0 = uVar24;
      fStack_1ec = fVar25;
      uStack_1e8 = uVar26;
      fStack_1e4 = fVar27;
      AEMath::operator*(aAStack_2f8,(Matrix *)local_1c8,(Matrix *)local_148);
      AEMath::operator*(aAStack_2bc,aAStack_2f8,(Matrix *)local_188);
      pAVar14 = aAStack_280;
      AEMath::operator*(pAVar14,aAStack_2bc,(AEMath *)local_208);
      this_00 = aAStack_244;
    }
    else {
      AEMath::operator*(aAStack_280,(Matrix *)local_1c8,(Matrix *)local_148);
      pAVar14 = aAStack_244;
      AEMath::operator*(pAVar14,aAStack_280,(Matrix *)local_188);
      this_00 = (AEMath *)local_208;
    }
    AEMath::operator*(this_00,pAVar14,(Matrix *)local_c8);
    AEMath::Matrix::operator=((Matrix *)(iVar7 + 0x98),this_00);
  }
  if (in_stack_00000000 == 0) {
    fStack_84 = *(float *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_80 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    local_7c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    this_01 = (BSphere *)(iVar7 + 0xd4);
    local_88 = 0;
    local_78 = 1.0;
    AEMath::BSphere::operator=(this_01,(BSphere *)&local_88);
    if (*(int *)(iVar7 + 0x3c) != 0) {
      uVar15 = 0;
      do {
        iVar17 = *(int *)(*(int *)(iVar7 + 0x40) + uVar15 * 4);
        if ((iVar17 == 0) || (*(uint *)(iVar17 + 0x34) == 0)) {
          local_88 = *(undefined4 *)(iVar17 + 0x3c);
          fStack_84 = *(float *)(iVar17 + 0x40);
          local_80 = *(undefined4 *)(iVar17 + 0x44);
          local_7c = *(undefined4 *)(iVar17 + 0x48);
          local_78 = *(float *)(iVar17 + 0x4c);
        }
        else {
          InternUpdate((ulonglong)*(uint *)(iVar17 + 0x34),param_2);
          iVar17 = *(int *)(*(int *)(iVar7 + 0x40) + uVar15 * 4);
          local_88 = *(undefined4 *)(iVar17 + 0x3c);
          fStack_84 = *(float *)(iVar17 + 0x40);
          local_80 = *(undefined4 *)(iVar17 + 0x44);
          local_7c = *(undefined4 *)(iVar17 + 0x48);
          local_78 = *(float *)(iVar17 + 0x4c);
          AEMath::MatrixTransformVector
                    ((AEMath *)local_c8,
                     (Matrix *)
                     (*(int *)(*(int *)(*(int *)(iVar7 + 0x40) + uVar15 * 4) + 0x34) + 0x5c),
                     (Vector *)&local_88);
          AEMath::Vector::operator=((Vector *)&local_88,(Vector *)local_c8);
        }
        AEMath::BSphere::Merge(this_01,(BSphere *)&local_88);
        uVar15 = uVar15 + 1;
      } while (uVar15 < *(uint *)(iVar7 + 0x3c));
    }
    if (*(int *)(iVar7 + 0x4c) != 0) {
      uVar15 = 0;
      do {
        InternUpdate((ulonglong)*(uint *)(*(int *)(iVar7 + 0x50) + uVar15 * 4),param_2);
        iVar17 = *(int *)(*(int *)(iVar7 + 0x50) + uVar15 * 4);
        local_88 = *(undefined4 *)(iVar17 + 0xd4);
        fStack_84 = *(float *)(iVar17 + 0xd8);
        local_80 = *(undefined4 *)(iVar17 + 0xdc);
        local_7c = *(undefined4 *)(iVar17 + 0xe0);
        local_78 = *(float *)(iVar17 + 0xe4);
        AEMath::MatrixTransformVector
                  ((AEMath *)local_c8,
                   (Matrix *)(*(int *)(*(int *)(iVar7 + 0x50) + uVar15 * 4) + 0x5c),
                   (Vector *)&local_88);
        AEMath::Vector::operator=((Vector *)&local_88,(Vector *)local_c8);
        AEMath::BSphere::Merge(this_01,(BSphere *)&local_88);
        uVar15 = uVar15 + 1;
      } while (uVar15 < *(uint *)(iVar7 + 0x4c));
    }
  }
LAB_0007ef12:
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Transform::PauseAnimationWithTimeStamp  @0x0007ef70  (28 bytes)
/* AbyssEngine::Transform::PauseAnimationWithTimeStamp(long long) */

void AbyssEngine::Transform::PauseAnimationWithTimeStamp(longlong param_1)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 0x110) = in_r2;
  *(undefined4 *)(iVar1 + 0x114) = in_r3;
  InternUpdate(param_1,SUB41(in_r2,0));
  *(undefined1 *)(iVar1 + 0xed) = 0;
  return;
}

// ===== AbyssEngine::Transform::AddKeyFrame  @0x0007ef8c  (168 bytes)
/* AbyssEngine::Transform::AddKeyFrame(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector const&, int) */

void __thiscall
AbyssEngine::Transform::AddKeyFrame
          (Transform *this,Vector *param_1,Vector *param_2,Vector *param_3,Vector *param_4,
          Vector *param_5,Vector *param_6,int param_7)

{
  int iVar1;
  KeyFrame *this_00;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  
  this_00 = operator_new(0x60);
  KeyFrame::KeyFrame(this_00);
  AEMath::Vector::operator=((Vector *)(this_00 + 0x18),param_2);
  AEMath::Vector::operator=((Vector *)this_00,param_3);
  AEMath::Vector::operator=((Vector *)(this_00 + 0xc),param_1);
  AEMath::Vector::operator=((Vector *)(this_00 + 0x3c),param_5);
  AEMath::Vector::operator=((Vector *)(this_00 + 0x24),param_6);
  AEMath::Vector::operator=((Vector *)(this_00 + 0x30),param_4);
  iVar1 = param_7 >> 0x1f;
  *(int *)(this_00 + 0x50) = param_7;
  *(int *)(this_00 + 0x54) = iVar1;
  *(int *)(this + 0x124) = *(int *)(this + 0x11c) + 1;
  pvVar2 = realloc(*(void **)(this + 0x120),(*(int *)(this + 0x11c) + 1) * 4);
  *(void **)(this + 0x120) = pvVar2;
  *(KeyFrame **)((int)pvVar2 + *(int *)(this + 0x11c) * 4) = this_00;
  *(undefined4 *)(this + 0x11c) = *(undefined4 *)(this + 0x124);
  iVar3 = *(int *)(this + 0xfc);
  bVar4 = *(uint *)(this + 0xf8) < (uint)param_7;
  if ((int)((iVar3 - iVar1) - (uint)bVar4) < 0 !=
      (SBORROW4(iVar3,iVar1) != SBORROW4(iVar3 - iVar1,(uint)bVar4))) {
    *(int *)(this + 0xf8) = param_7;
    *(int *)(this + 0xfc) = iVar1;
  }
  return;
}

// ===== AbyssEngine::Transform::InsertKeyFrame  @0x0007f0b0  (94 bytes)
/* AbyssEngine::Transform::InsertKeyFrame(AbyssEngine::KeyFrame*, int) */

void __thiscall
AbyssEngine::Transform::InsertKeyFrame(Transform *this,KeyFrame *param_1,int param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  *(int *)(this + 0x124) = *(int *)(this + 0x11c) + 1;
  pvVar2 = realloc(*(void **)(this + 0x120),(*(int *)(this + 0x11c) + 1) * 4);
  *(void **)(this + 0x120) = pvVar2;
  *(undefined4 *)((int)pvVar2 + *(int *)(this + 0x11c) * 4) = 0;
  iVar4 = *(int *)(this + 0x124);
  *(int *)(this + 0x11c) = iVar4;
  iVar3 = iVar4 + -1;
  if (param_2 < iVar3) {
    iVar4 = iVar4 * 4 + -8;
    do {
      puVar1 = (undefined4 *)((int)pvVar2 + iVar4);
      iVar4 = iVar4 + -4;
      *(undefined4 *)((int)pvVar2 + iVar3 * 4) = *puVar1;
      iVar3 = iVar3 + -1;
      pvVar2 = *(void **)(this + 0x120);
    } while (param_2 < iVar3);
  }
  *(KeyFrame **)((int)pvVar2 + param_2 * 4) = param_1;
  return;
}

// ===== AbyssEngine::Transform::UpdateKeyFrames  @0x0007f10e  (1814 bytes)
/* AbyssEngine::Transform::UpdateKeyFrames(AbyssEngine::KeyFrame*, int) */

void __thiscall
AbyssEngine::Transform::UpdateKeyFrames(Transform *this,KeyFrame *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  float *pfVar13;
  float *pfVar14;
  uint uVar15;
  
  if (1 < param_2) {
    pfVar13 = (float *)**(int **)(this + 0x120);
    fVar3 = *(float *)(param_1 + 0x50);
    iVar7 = *(int *)(param_1 + 0x54);
    iVar4 = param_2 + -1;
    fVar2 = pfVar13[0x15];
    fVar9 = pfVar13[0x14];
    piVar12 = *(int **)(this + 0x120);
    do {
      pfVar14 = (float *)piVar12[1];
      fVar5 = pfVar14[0x14];
      fVar8 = pfVar14[0x15];
      fVar1 = (float)__aeabi_l2f((int)fVar3 - (int)fVar5,
                                 (iVar7 - (int)fVar8) - (uint)((uint)fVar3 < (uint)fVar5));
      fVar2 = (float)__aeabi_l2f((int)fVar3 - (int)fVar9,
                                 (iVar7 - (int)fVar2) - (uint)((uint)fVar3 < (uint)fVar9));
      uVar6 = *(uint *)(param_1 + 0x58);
      uVar15 = *(uint *)(param_1 + 0x5c);
      fVar2 = 1.0 - fVar1 / fVar2;
      if (((uVar6 & 0x40) != 0) && (((uint)pfVar14[0x16] & 0x40) == 0)) {
        pfVar14[6] = pfVar13[6] + fVar2 * (*(float *)(param_1 + 0x18) - pfVar13[6]);
      }
      if (((uVar6 & 0x80) != 0) && (-1 < *(char *)(pfVar14 + 0x16))) {
        pfVar14[7] = *(float *)(*piVar12 + 0x1c) +
                     fVar2 * (*(float *)(param_1 + 0x1c) - *(float *)(*piVar12 + 0x1c));
      }
      if (((uVar6 & 0x100) != 0) && ((*(byte *)((int)pfVar14 + 0x59) & 1) == 0)) {
        pfVar14[8] = *(float *)(*piVar12 + 0x20) +
                     fVar2 * (*(float *)(param_1 + 0x20) - *(float *)(*piVar12 + 0x20));
      }
      if (((uVar6 & 1) != 0) && (((uint)pfVar14[0x16] & 1) == 0)) {
        *pfVar14 = *(float *)*piVar12 + fVar2 * (*(float *)param_1 - *(float *)*piVar12);
      }
      if (((uVar6 & 2) != 0) && (((uint)pfVar14[0x16] & 2) == 0)) {
        pfVar14[1] = *(float *)(*piVar12 + 4) +
                     fVar2 * (*(float *)(param_1 + 4) - *(float *)(*piVar12 + 4));
      }
      if (((uVar6 & 4) != 0) && (((uint)pfVar14[0x16] & 4) == 0)) {
        pfVar14[2] = *(float *)(*piVar12 + 8) +
                     fVar2 * (*(float *)(param_1 + 8) - *(float *)(*piVar12 + 8));
      }
      if (((uVar6 & 8) != 0) && (((uint)pfVar14[0x16] & 8) == 0)) {
        pfVar14[3] = *(float *)(*piVar12 + 0xc) +
                     fVar2 * (*(float *)(param_1 + 0xc) - *(float *)(*piVar12 + 0xc));
      }
      if (((uVar6 & 0x10) != 0) && (((uint)pfVar14[0x16] & 0x10) == 0)) {
        pfVar14[4] = *(float *)(*piVar12 + 0x10) +
                     fVar2 * (*(float *)(param_1 + 0x10) - *(float *)(*piVar12 + 0x10));
      }
      if (((uVar6 & 0x20) != 0) && (((uint)pfVar14[0x16] & 0x20) == 0)) {
        pfVar14[5] = *(float *)(*piVar12 + 0x14) +
                     fVar2 * (*(float *)(param_1 + 0x14) - *(float *)(*piVar12 + 0x14));
      }
      if (((uVar6 & 0x200) != 0) && ((*(byte *)((int)pfVar14 + 0x59) & 2) == 0)) {
        pfVar14[0x12] =
             *(float *)(*piVar12 + 0x48) +
             fVar2 * (*(float *)(param_1 + 0x48) - *(float *)(*piVar12 + 0x48));
      }
      if (((uVar6 & 0x10000) != 0) && ((*(byte *)((int)pfVar14 + 0x5a) & 1) == 0)) {
        pfVar14[0xf] = *(float *)(*piVar12 + 0x3c) +
                       fVar2 * (*(float *)(param_1 + 0x3c) - *(float *)(*piVar12 + 0x3c));
      }
      if (((uVar6 & 0x20000) != 0) && ((*(byte *)((int)pfVar14 + 0x5a) & 2) == 0)) {
        pfVar14[0x10] =
             *(float *)(*piVar12 + 0x40) +
             fVar2 * (*(float *)(param_1 + 0x40) - *(float *)(*piVar12 + 0x40));
      }
      if (((uVar6 & 0x40000) != 0) && ((*(byte *)((int)pfVar14 + 0x5a) & 4) == 0)) {
        pfVar14[0x11] =
             *(float *)(*piVar12 + 0x44) +
             fVar2 * (*(float *)(param_1 + 0x44) - *(float *)(*piVar12 + 0x44));
      }
      if (((uVar6 & 0x400) != 0) && ((*(byte *)((int)pfVar14 + 0x59) & 4) == 0)) {
        pfVar14[9] = *(float *)(*piVar12 + 0x24) +
                     fVar2 * (*(float *)(param_1 + 0x24) - *(float *)(*piVar12 + 0x24));
      }
      if (((uVar6 & 0x800) != 0) && ((*(byte *)((int)pfVar14 + 0x59) & 8) == 0)) {
        pfVar14[10] = *(float *)(*piVar12 + 0x28) +
                      fVar2 * (*(float *)(param_1 + 0x28) - *(float *)(*piVar12 + 0x28));
      }
      if (((uVar6 & 0x1000) != 0) && ((*(byte *)((int)pfVar14 + 0x59) & 0x10) == 0)) {
        pfVar14[0xb] = *(float *)(*piVar12 + 0x2c) +
                       fVar2 * (*(float *)(param_1 + 0x2c) - *(float *)(*piVar12 + 0x2c));
      }
      if (((uVar6 & 0x2000) != 0) && ((*(byte *)((int)pfVar14 + 0x59) & 0x20) == 0)) {
        pfVar14[0xc] = *(float *)(*piVar12 + 0x30) +
                       fVar2 * (*(float *)(param_1 + 0x30) - *(float *)(*piVar12 + 0x30));
      }
      if (((uVar6 & 0x4000) != 0) && ((*(byte *)((int)pfVar14 + 0x59) & 0x40) == 0)) {
        pfVar14[0xd] = *(float *)(*piVar12 + 0x34) +
                       fVar2 * (*(float *)(param_1 + 0x34) - *(float *)(*piVar12 + 0x34));
      }
      fVar9 = pfVar14[0x16];
      if (((uVar6 & 0x8000) != 0) && (((uint)fVar9 & 0x8000) == 0)) {
        pfVar14[0xe] = *(float *)(*piVar12 + 0x38) +
                       fVar2 * (*(float *)(param_1 + 0x38) - *(float *)(*piVar12 + 0x38));
      }
      pfVar14[0x16] = (float)(uVar6 | (uint)fVar9);
      pfVar14[0x17] = (float)((uint)pfVar14[0x17] | uVar15);
      iVar4 = iVar4 + -1;
      fVar2 = fVar8;
      fVar9 = fVar5;
      pfVar13 = pfVar14;
      piVar12 = piVar12 + 1;
    } while (iVar4 != 0);
  }
  uVar6 = *(uint *)(this + 0x11c);
  if (param_2 + 1U < uVar6) {
    uVar15 = *(uint *)(param_1 + 0x58);
    do {
      if (((uVar15 & 0x40) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x58) & 0x40) == 0)) {
        *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(param_1 + 0x18);
      }
      if (((uVar15 & 0x80) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4), -1 < *(char *)(iVar4 + 0x58)))
      {
        *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
      }
      if (((uVar15 & 0x100) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x59) & 1) == 0)) {
        *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(param_1 + 0x20);
      }
      if (((uVar15 & 1) != 0) &&
         (puVar10 = *(undefined4 **)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(puVar10 + 0x16) & 1) == 0)) {
        *puVar10 = *(undefined4 *)param_1;
      }
      if (((uVar15 & 2) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x58) & 2) == 0)) {
        *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(param_1 + 4);
      }
      if (((uVar15 & 4) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x58) & 4) == 0)) {
        *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(param_1 + 8);
      }
      if (((uVar15 & 8) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x58) & 8) == 0)) {
        *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(param_1 + 0xc);
      }
      if (((uVar15 & 0x10) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x58) & 0x10) == 0)) {
        *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      }
      if (((uVar15 & 0x20) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x58) & 0x20) == 0)) {
        *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(param_1 + 0x14);
      }
      if (((uVar15 & 0x200) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x59) & 2) == 0)) {
        *(undefined4 *)(iVar4 + 0x48) = *(undefined4 *)(param_1 + 0x48);
      }
      if (((uVar15 & 0x10000) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x5a) & 1) == 0)) {
        *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
      }
      if (((uVar15 & 0x20000) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x5a) & 2) == 0)) {
        *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(param_1 + 0x40);
      }
      if (((uVar15 & 0x40000) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x5a) & 4) == 0)) {
        *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(param_1 + 0x44);
      }
      if (((uVar15 & 0x400) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x59) & 4) == 0)) {
        *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(param_1 + 0x24);
      }
      if (((uVar15 & 0x800) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x59) & 8) == 0)) {
        *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(param_1 + 0x28);
      }
      if (((uVar15 & 0x1000) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x59) & 0x10) == 0)) {
        *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
      }
      if (((uVar15 & 0x2000) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x59) & 0x20) == 0)) {
        *(undefined4 *)(iVar4 + 0x30) = *(undefined4 *)(param_1 + 0x30);
      }
      if (((uVar15 & 0x4000) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4),
         (*(byte *)(iVar4 + 0x59) & 0x40) == 0)) {
        *(undefined4 *)(iVar4 + 0x34) = *(undefined4 *)(param_1 + 0x34);
      }
      if (((uVar15 & 0x8000) != 0) &&
         (iVar4 = *(int *)(*(int *)(this + 0x120) + param_2 * 4 + 4), -1 < *(char *)(iVar4 + 0x59)))
      {
        *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(param_1 + 0x38);
      }
      uVar11 = param_2 + 2;
      param_2 = param_2 + 1;
    } while (uVar11 < uVar6);
  }
  return;
}

// ===== AbyssEngine::Transform::InsertKeyFrame  @0x0007f824  (1354 bytes)
/* AbyssEngine::Transform::InsertKeyFrame(float const*, long long, int) */

void AbyssEngine::Transform::InsertKeyFrame(float *param_1,longlong param_2,int param_3)

{
  Vector *pVVar1;
  float fVar2;
  uint uVar3;
  float *in_r1;
  int iVar4;
  float fVar5;
  int iVar6;
  Vector *pVVar7;
  int iVar8;
  float fVar9;
  int iVar10;
  uint uVar11;
  KeyFrame *this;
  uint uVar12;
  bool bVar13;
  float fVar14;
  AEMath aAStack_40 [12];
  int local_34;
  
  local_34 = __stack_chk_guard;
  lauf = lauf + 1;
  fVar5 = param_1[0x3f];
  bVar13 = (uint)param_1[0x3e] < (uint)param_3;
  fVar2 = (float)(param_3 >> 0x1f);
  if ((int)(((int)fVar5 - (int)fVar2) - (uint)bVar13) < 0 !=
      (SBORROW4((int)fVar5,(int)fVar2) != SBORROW4((int)fVar5 - (int)fVar2,(uint)bVar13))) {
    param_1[0x3e] = (float)param_3;
    param_1[0x3f] = fVar2;
  }
  fVar5 = param_1[0x47];
  if (fVar5 == 0.0) {
    fVar9 = 0.0;
  }
  else {
    fVar9 = 0.0;
    do {
      iVar6 = *(int *)((int)param_1[0x48] + (int)fVar9 * 4);
      iVar8 = *(int *)(iVar6 + 0x54);
      bVar13 = *(uint *)(iVar6 + 0x50) < (uint)param_3;
      if ((int)((iVar8 - (int)fVar2) - (uint)bVar13) < 0 ==
          (SBORROW4(iVar8,(int)fVar2) != SBORROW4(iVar8 - (int)fVar2,(uint)bVar13))) break;
      fVar9 = (float)((int)fVar9 + 1);
    } while ((uint)fVar9 < (uint)fVar5);
  }
  if (((uint)fVar5 <= (uint)fVar9) ||
     (this = *(KeyFrame **)((int)param_1[0x48] + (int)fVar9 * 4),
     *(int *)(this + 0x50) != param_3 || *(float *)(this + 0x54) != fVar2)) {
    this = operator_new(0x60);
    KeyFrame::KeyFrame(this);
    *(int *)(this + 0x50) = param_3;
    *(float *)(this + 0x54) = fVar2;
    InsertKeyFrame((Transform *)param_1,this,(int)fVar9);
    if (fVar9 != 0.0) {
      if ((uint)fVar9 < (uint)((int)param_1[0x47] + -1)) {
        iVar10 = (int)fVar9 + -1;
        iVar8 = (int)fVar9 * 4 + 4;
        pVVar7 = *(Vector **)((int)param_1[0x48] + iVar10 * 4);
        pVVar1 = *(Vector **)((int)param_1[0x48] + iVar8);
        uVar12 = *(uint *)(pVVar7 + 0x50);
        iVar6 = *(int *)(pVVar7 + 0x54);
        fVar5 = (float)__aeabi_l2f(*(uint *)(pVVar1 + 0x50) - uVar12,
                                   (*(int *)(pVVar1 + 0x54) - iVar6) -
                                   (uint)(*(uint *)(pVVar1 + 0x50) < uVar12));
        fVar2 = (float)__aeabi_l2f(param_3 - uVar12,
                                   ((int)fVar2 - iVar6) - (uint)((uint)param_3 < uVar12));
        AEMath::VectorLerp(aAStack_40,pVVar7,pVVar1,fVar2);
        fVar14 = (float)AEMath::Vector::operator=((Vector *)this,(Vector *)aAStack_40);
        AEMath::VectorLerp(aAStack_40,(Vector *)(*(int *)((int)param_1[0x48] + iVar10 * 4) + 0xc),
                           (Vector *)(*(int *)((int)param_1[0x48] + iVar8) + 0xc),fVar14);
        fVar14 = (float)AEMath::Vector::operator=((Vector *)(this + 0xc),(Vector *)aAStack_40);
        AEMath::VectorLerp(aAStack_40,(Vector *)(*(int *)((int)param_1[0x48] + iVar10 * 4) + 0x18),
                           (Vector *)(*(int *)((int)param_1[0x48] + iVar8) + 0x18),fVar14);
        AEMath::Vector::operator=((Vector *)(this + 0x18),(Vector *)aAStack_40);
        iVar4 = *(int *)((int)param_1[0x48] + iVar10 * 4);
        iVar6 = *(int *)((int)param_1[0x48] + iVar8);
        fVar14 = *(float *)(iVar4 + 0x48);
        fVar14 = fVar14 + (fVar2 / fVar5) * (*(float *)(iVar6 + 0x48) - fVar14);
        *(float *)(this + 0x48) = fVar14;
        AEMath::VectorLerp(aAStack_40,(Vector *)(iVar4 + 0x24),(Vector *)(iVar6 + 0x24),fVar14);
        fVar2 = (float)AEMath::Vector::operator=((Vector *)(this + 0x24),(Vector *)aAStack_40);
        AEMath::VectorLerp(aAStack_40,(Vector *)(*(int *)((int)param_1[0x48] + iVar10 * 4) + 0x30),
                           (Vector *)(*(int *)((int)param_1[0x48] + iVar8) + 0x30),fVar2);
        fVar2 = (float)AEMath::Vector::operator=((Vector *)(this + 0x30),(Vector *)aAStack_40);
        pVVar1 = (Vector *)aAStack_40;
        AEMath::VectorLerp((AEMath *)pVVar1,
                           (Vector *)(*(int *)((int)param_1[0x48] + iVar10 * 4) + 0x3c),
                           (Vector *)(*(int *)((int)param_1[0x48] + iVar8) + 0x3c),fVar2);
      }
      else {
        iVar8 = (int)fVar9 + -1;
        AEMath::Vector::operator=((Vector *)this,*(Vector **)((int)param_1[0x48] + iVar8 * 4));
        AEMath::Vector::operator=
                  ((Vector *)(this + 0xc),(Vector *)(*(int *)((int)param_1[0x48] + iVar8 * 4) + 0xc)
                  );
        AEMath::Vector::operator=
                  ((Vector *)(this + 0x18),
                   (Vector *)(*(int *)((int)param_1[0x48] + iVar8 * 4) + 0x18));
        iVar6 = *(int *)((int)param_1[0x48] + iVar8 * 4);
        *(undefined4 *)(this + 0x48) = *(undefined4 *)(iVar6 + 0x48);
        AEMath::Vector::operator=((Vector *)(this + 0x24),(Vector *)(iVar6 + 0x24));
        AEMath::Vector::operator=
                  ((Vector *)(this + 0x30),
                   (Vector *)(*(int *)((int)param_1[0x48] + iVar8 * 4) + 0x30));
        pVVar1 = (Vector *)(*(int *)((int)param_1[0x48] + iVar8 * 4) + 0x3c);
      }
      AEMath::Vector::operator=((Vector *)(this + 0x3c),pVVar1);
      iVar6 = *(int *)((int)param_1[0x48] + ((int)fVar9 + -1) * 4);
      uVar12 = *(uint *)(iVar6 + 0x5c);
      *(uint *)(this + 0x58) = *(uint *)(iVar6 + 0x58) | *(uint *)(this + 0x58);
      *(uint *)(this + 0x5c) = *(uint *)(this + 0x5c) | uVar12;
    }
  }
  uVar12 = (uint)((ulonglong)param_2 >> 0x20);
  uVar11 = (uint)param_2;
  *(uint *)(this + 0x58) = *(uint *)(this + 0x58) | uVar11;
  *(uint *)(this + 0x5c) = *(uint *)(this + 0x5c) | uVar12;
  if ((int)(-(uint)(0x1ff < uVar11) - uVar12) < 0 ==
      (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1ff < uVar11)))) {
    if ((int)(-(uint)(0x1f < uVar11) - uVar12) < 0 ==
        (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1f < uVar11)))) {
      uVar3 = uVar11 - 1;
      iVar6 = uVar12 - (uVar11 == 0);
      if ((uint)-iVar6 < (uint)(uVar3 < 8)) {
                    /* WARNING: Could not recover jumptable at 0x0007fb3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&DAT_0007fb40 + (uint)*(ushort *)(&DAT_0007fb40 + uVar3 * 2) * 2))
                  (uVar3,-(uint)(uVar3 >= 8) - iVar6,0,7 - uVar3);
        return;
      }
      if (param_2 != 0x10) goto LAB_0007fd96;
      fVar2 = *in_r1;
      *(float *)(this + 0x10) = fVar2;
    }
    else {
      if ((int)(-(uint)(0x7f < uVar11) - uVar12) < 0 !=
          (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x7f < uVar11)))) {
        if (param_2 == 0x80) {
          *(float *)(this + 0x1c) = *in_r1;
        }
        else if (param_2 == 0x100) {
          *(float *)(this + 0x20) = *in_r1;
        }
        else if (param_2 == 0x1c0) {
          *(float *)(this + 0x18) = *in_r1;
          *(float *)(this + 0x1c) = in_r1[1];
          *(float *)(this + 0x20) = in_r1[2];
        }
        goto LAB_0007fd96;
      }
      if (param_2 == 0x20) {
        fVar2 = *in_r1;
        *(float *)(this + 0x14) = fVar2;
      }
      else {
        if (param_2 != 0x38) {
          if (param_2 == 0x40) {
            *(float *)(this + 0x18) = *in_r1;
          }
          goto LAB_0007fd96;
        }
        *(float *)(this + 0xc) = *in_r1;
        *(float *)(this + 0x10) = in_r1[1];
        *(float *)(this + 0x14) = in_r1[2];
        fVar5 = in_r1[1];
        if (in_r1[1] < *in_r1) {
          fVar5 = *in_r1;
        }
        fVar2 = in_r1[2];
        if (in_r1[2] < fVar5) {
          fVar2 = fVar5;
        }
      }
    }
    if (param_1[0x39] < fVar2) {
      param_1[0x39] = fVar2;
    }
  }
  else if ((int)(-(uint)(0x3fff < uVar11) - uVar12) < 0 ==
           (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3fff < uVar11)))) {
    if ((int)(-(uint)(0xfff < uVar11) - uVar12) < 0 ==
        (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xfff < uVar11)))) {
      if (param_2 == 0x200) {
        *(float *)(this + 0x48) = *in_r1 / 100.0;
      }
      else if (param_2 == 0x400) {
        *(float *)(this + 0x24) = -*in_r1;
      }
      else if (param_2 == 0x800) {
        *(float *)(this + 0x28) = *in_r1;
      }
    }
    else if (param_2 == 0x1000) {
      *(float *)(this + 0x2c) = *in_r1;
    }
    else if (param_2 == 0x1c00) {
      *(float *)(this + 0x24) = *in_r1;
      *(float *)(this + 0x28) = in_r1[1];
      *(float *)(this + 0x2c) = in_r1[2];
    }
    else if (param_2 == 0x2000) {
      *(float *)(this + 0x30) = *in_r1;
    }
  }
  else if ((int)(-(uint)(0xffff < uVar11) - uVar12) < 0 ==
           (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xffff < uVar11)))) {
    if (param_2 == 0x4000) {
      *(float *)(this + 0x34) = *in_r1;
    }
    else if (param_2 == 0x8000) {
      *(float *)(this + 0x38) = *in_r1;
    }
    else if (param_2 == 0xe000) {
      *(float *)(this + 0x30) = *in_r1;
      *(float *)(this + 0x34) = in_r1[1];
      *(float *)(this + 0x38) = in_r1[2];
    }
  }
  else if ((int)(-(uint)(0x3ffff < uVar11) - uVar12) < 0 ==
           (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3ffff < uVar11)))) {
    if (param_2 == 0x10000) {
      *(float *)(this + 0x3c) = *in_r1;
    }
    else if (param_2 == 0x20000) {
      *(float *)(this + 0x40) = *in_r1;
    }
  }
  else {
    if (param_2 == 0x40000) {
      fVar2 = *in_r1;
    }
    else {
      if (param_2 != 0x70000) goto LAB_0007fd96;
      *(float *)(this + 0x3c) = *in_r1;
      *(float *)(this + 0x40) = in_r1[1];
      fVar2 = in_r1[2];
    }
    *(float *)(this + 0x44) = fVar2;
  }
LAB_0007fd96:
  UpdateKeyFrames((Transform *)param_1,this,(int)fVar9);
  if (__stack_chk_guard == local_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Transform::InsertKeyFrame_old  @0x0007fddc  (4178 bytes)
/* AbyssEngine::Transform::InsertKeyFrame_old(float const*, long long, int) */

void AbyssEngine::Transform::InsertKeyFrame_old(float *param_1,longlong param_2,int param_3)

{
  KeyFrame *pKVar1;
  KeyFrame *this;
  Vector *this_00;
  Vector *this_01;
  Vector *this_02;
  KeyFrame *pKVar2;
  Vector *this_03;
  uint uVar3;
  void *pvVar4;
  float *in_r1;
  float *pfVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  int iVar9;
  float fVar10;
  KeyFrame *pKVar11;
  uint uVar12;
  int iVar13;
  Vector *this_04;
  uint uVar14;
  uint uVar15;
  float fVar16;
  KeyFrame *pKVar17;
  float fVar18;
  uint uVar19;
  int iVar20;
  bool bVar21;
  undefined8 uVar22;
  AEMath aAStack_40 [12];
  int local_34;
  
  uVar12 = (uint)((ulonglong)param_2 >> 0x20);
  uVar7 = (uint)param_2;
  local_34 = __stack_chk_guard;
  lauf = lauf + 1;
  fVar8 = param_1[0x3f];
  bVar21 = (uint)param_1[0x3e] < (uint)param_3;
  fVar6 = (float)(param_3 >> 0x1f);
  if ((int)(((int)fVar8 - (int)fVar6) - (uint)bVar21) < 0 !=
      (SBORROW4((int)fVar8,(int)fVar6) != SBORROW4((int)fVar8 - (int)fVar6,(uint)bVar21))) {
    param_1[0x3e] = (float)param_3;
    param_1[0x3f] = fVar6;
  }
  if (param_1[0x47] == 0.0) {
    fVar8 = 0.0;
  }
  else {
    fVar8 = 0.0;
    do {
      iVar9 = *(int *)((int)param_1[0x48] + (int)fVar8 * 4);
      iVar13 = *(int *)(iVar9 + 0x54);
      bVar21 = *(uint *)(iVar9 + 0x50) < (uint)param_3;
      if ((int)((iVar13 - (int)fVar6) - (uint)bVar21) < 0 ==
          (SBORROW4(iVar13,(int)fVar6) != SBORROW4(iVar13 - (int)fVar6,(uint)bVar21))) break;
      fVar8 = (float)((int)fVar8 + 1);
    } while ((uint)fVar8 < (uint)param_1[0x47]);
  }
  this = operator_new(0x60);
  KeyFrame::KeyFrame(this);
  if (fVar8 != 0.0) {
    iVar9 = (int)fVar8 * 4 + -4;
    AEMath::Vector::operator=((Vector *)this,*(Vector **)((int)param_1[0x48] + iVar9));
    AEMath::Vector::operator=
              ((Vector *)(this + 0xc),(Vector *)(*(int *)((int)param_1[0x48] + iVar9) + 0xc));
    AEMath::Vector::operator=
              ((Vector *)(this + 0x18),(Vector *)(*(int *)((int)param_1[0x48] + iVar9) + 0x18));
    uVar22 = *(undefined8 *)(*(int *)((int)param_1[0x48] + iVar9) + 0x58);
    *(undefined8 *)(this + 0x50) = *(undefined8 *)(*(int *)((int)param_1[0x48] + iVar9) + 0x50);
    *(undefined8 *)(this + 0x58) = uVar22;
  }
  if ((int)(-(uint)(0x1ff < uVar7) - uVar12) < 0 ==
      (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1ff < uVar7)))) {
    if ((int)(-(uint)(0x1f < uVar7) - uVar12) < 0 ==
        (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1f < uVar7)))) {
      uVar3 = uVar7 - 1;
      iVar9 = uVar12 - (uVar7 == 0);
      if ((uint)-iVar9 < (uint)(uVar3 < 8)) {
                    /* WARNING: Could not recover jumptable at 0x0007ff32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&DAT_0007ff36 + (uint)*(ushort *)(&DAT_0007ff36 + uVar3 * 2) * 2))
                  (uVar3,-(uint)(uVar3 >= 8) - iVar9,0,7 - uVar3);
        return;
      }
      if (param_2 == 0x10) {
        fVar8 = *in_r1;
        *(float *)(this + 0x10) = fVar8;
        goto LAB_0008012e;
      }
    }
    else if ((int)(-(uint)(0x7f < uVar7) - uVar12) < 0 ==
             (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x7f < uVar7)))) {
      if (param_2 == 0x20) {
        fVar8 = *in_r1;
        *(float *)(this + 0x14) = fVar8;
      }
      else {
        if (param_2 != 0x38) {
          if (param_2 == 0x40) {
            *(float *)(this + 0x18) = *in_r1;
          }
          goto LAB_00080190;
        }
        fVar8 = *in_r1;
        *(float *)(this + 0xc) = fVar8;
        fVar16 = in_r1[1];
        fVar10 = fVar16;
        if (fVar16 < fVar8) {
          fVar10 = fVar8;
        }
        *(float *)(this + 0x10) = fVar16;
        fVar16 = in_r1[2];
        fVar8 = fVar16;
        if (fVar16 < fVar10) {
          fVar8 = fVar10;
        }
        *(float *)(this + 0x14) = fVar16;
      }
LAB_0008012e:
      if (param_1[0x39] < fVar8) {
        param_1[0x39] = fVar8;
      }
    }
    else if (param_2 == 0x80) {
      *(float *)(this + 0x1c) = *in_r1;
    }
    else if (param_2 == 0x100) {
      *(float *)(this + 0x20) = *in_r1;
    }
    else if (param_2 == 0x1c0) {
      *(float *)(this + 0x18) = *in_r1;
      *(float *)(this + 0x1c) = in_r1[1];
      *(float *)(this + 0x20) = in_r1[2];
    }
  }
  else if ((int)(-(uint)(0x3fff < uVar7) - uVar12) < 0 ==
           (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3fff < uVar7)))) {
    if ((int)(-(uint)(0xfff < uVar7) - uVar12) < 0 ==
        (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xfff < uVar7)))) {
      if (param_2 == 0x200) {
        *(float *)(this + 0x48) = *in_r1 / 100.0;
      }
      else if (param_2 == 0x400) {
        *(float *)(this + 0x24) = -*in_r1;
      }
      else if (param_2 == 0x800) {
        *(float *)(this + 0x28) = *in_r1;
      }
    }
    else if (param_2 == 0x1000) {
      *(float *)(this + 0x2c) = *in_r1;
    }
    else if (param_2 == 0x1c00) {
      *(float *)(this + 0x24) = -*in_r1;
      *(float *)(this + 0x28) = in_r1[1];
      *(float *)(this + 0x2c) = in_r1[2];
    }
    else if (param_2 == 0x2000) {
      *(float *)(this + 0x30) = *in_r1;
    }
  }
  else {
    pfVar5 = (float *)(-(uint)(0xffff < uVar7) - uVar12);
    if ((int)pfVar5 < 0 == (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xffff < uVar7)))) {
      if (param_2 == 0x4000) {
        *(float *)(this + 0x34) = -*in_r1;
      }
      else if (param_2 == 0x8000) {
        *(float *)(this + 0x38) = *in_r1;
      }
      else {
        if (param_2 == 0xe000) {
          *(float *)(this + 0x30) = *in_r1;
          pfVar5 = in_r1;
        }
        if (param_2 == 0xe000) {
          *(float *)(this + 0x34) = -pfVar5[1];
          *(float *)(this + 0x38) = pfVar5[2];
        }
      }
    }
    else if ((int)(-(uint)(0x3ffff < uVar7) - uVar12) < 0 ==
             (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3ffff < uVar7)))) {
      if (param_2 == 0x10000) {
        *(float *)(this + 0x3c) = *in_r1;
      }
      else if (param_2 == 0x20000) {
        *(float *)(this + 0x40) = *in_r1;
      }
    }
    else {
      if (param_2 == 0x40000) {
        fVar8 = *in_r1;
      }
      else {
        if (param_2 != 0x70000) goto LAB_00080190;
        *(float *)(this + 0x3c) = *in_r1;
        *(float *)(this + 0x40) = in_r1[1];
        fVar8 = in_r1[2];
      }
      *(float *)(this + 0x44) = fVar8;
    }
  }
LAB_00080190:
  *(float *)(this + 0x54) = fVar6;
  *(int *)(this + 0x50) = param_3;
  pKVar1 = this + 0x58;
  *(uint *)pKVar1 = *(uint *)pKVar1 | uVar7;
  *(uint *)(this + 0x5c) = *(uint *)(this + 0x5c) | uVar12;
  fVar8 = param_1[0x47];
  if (fVar8 == 0.0) {
    param_1[0x49] = 1.4013e-45;
    pvVar4 = realloc((void *)param_1[0x48],4);
    param_1[0x48] = (float)pvVar4;
    *(KeyFrame **)((int)pvVar4 + (int)param_1[0x47] * 4) = this;
  }
  else {
    this_00 = (Vector *)(this + 0x3c);
    this_01 = (Vector *)(this + 0x30);
    this_02 = (Vector *)(this + 0x24);
    fVar10 = 0.0;
    this_04 = (Vector *)(this + 0x18);
    do {
      pKVar17 = *(KeyFrame **)((int)param_1[0x48] + (int)fVar10 * 4);
      uVar3 = *(uint *)(pKVar17 + 0x50);
      iVar9 = *(int *)(pKVar17 + 0x54);
      if ((int)((iVar9 - (int)fVar6) - (uint)(uVar3 < (uint)param_3)) < 0 ==
          (SBORROW4(iVar9,(int)fVar6) != SBORROW4(iVar9 - (int)fVar6,(uint)(uVar3 < (uint)param_3)))
         ) break;
      uVar15 = *(uint *)(pKVar17 + 0x58);
      if ((fVar10 != 0.0) &&
         (uVar19 = *(uint *)(pKVar17 + 0x5c), (uVar15 & uVar7) == 0 && (uVar19 & uVar12) == 0)) {
        pKVar11 = *(KeyFrame **)((int)param_1[0x48] + (int)fVar10 * 4 + -4);
        uVar14 = *(uint *)(pKVar11 + 0x50);
        iVar13 = *(int *)(pKVar11 + 0x54);
        fVar16 = (float)__aeabi_l2f(uVar3 - uVar14,(iVar9 - iVar13) - (uint)(uVar3 < uVar14));
        fVar8 = (float)__aeabi_l2f(param_3 - uVar14,
                                   ((int)fVar6 - iVar13) - (uint)((uint)param_3 < uVar14));
        fVar8 = fVar16 / fVar8;
        *(uint *)(pKVar17 + 0x58) = uVar15 | uVar7;
        *(uint *)(pKVar17 + 0x5c) = uVar19 | uVar12;
        if ((int)(-(uint)(0x1ff < uVar7) - uVar12) < 0 ==
            (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1ff < uVar7)))) {
          if ((int)(-(uint)(0x1f < uVar7) - uVar12) < 0 ==
              (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1f < uVar7)))) {
            uVar3 = uVar7 - 1;
            iVar9 = uVar12 - (uVar7 == 0);
            if ((uint)-iVar9 < (uint)(uVar3 < 8)) {
                    /* WARNING: Could not recover jumptable at 0x00080308. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(&DAT_0008030c + (uint)*(ushort *)(&DAT_0008030c + uVar3 * 2) * 2))
                        (uVar3,-(uint)(uVar3 >= 8) - iVar9);
              return;
            }
            pKVar2 = (KeyFrame *)(uVar7 ^ 0x10 | uVar12);
            bVar21 = pKVar2 == (KeyFrame *)0x0;
            if (bVar21) {
              pKVar2 = pKVar11;
            }
            if (bVar21) {
              fVar16 = *(float *)(pKVar2 + 0x10);
              pKVar2 = this;
            }
            if (bVar21) {
              fVar8 = fVar16 + fVar8 * (*(float *)(pKVar2 + 0x10) - fVar16);
              pKVar2 = pKVar17;
            }
            if (bVar21) {
              *(float *)(pKVar2 + 0x10) = fVar8;
            }
          }
          else if ((int)(-(uint)(0x7f < uVar7) - uVar12) < 0 ==
                   (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x7f < uVar7)))) {
            if (param_2 == 0x20) {
              *(float *)(pKVar17 + 0x14) =
                   *(float *)(pKVar11 + 0x14) +
                   fVar8 * (*(float *)(this + 0x14) - *(float *)(pKVar11 + 0x14));
            }
            else if (param_2 == 0x38) {
              AEMath::VectorLerp(aAStack_40,(Vector *)(pKVar11 + 0xc),(Vector *)(this + 0xc),fVar8);
              this_03 = (Vector *)(pKVar17 + 0xc);
LAB_000806a4:
              AEMath::Vector::operator=(this_03,(Vector *)aAStack_40);
            }
            else {
              pKVar2 = (KeyFrame *)(uVar7 ^ 0x40 | uVar12);
              bVar21 = pKVar2 == (KeyFrame *)0x0;
              if (bVar21) {
                pKVar2 = pKVar11;
              }
              if (bVar21) {
                fVar8 = *(float *)(pKVar2 + 0x18) +
                        fVar8 * (*(float *)this_04 - *(float *)(pKVar2 + 0x18));
                pKVar2 = pKVar17;
              }
              if (bVar21) {
                *(float *)(pKVar2 + 0x18) = fVar8;
              }
            }
          }
          else if (param_2 == 0x80) {
            *(float *)(pKVar17 + 0x1c) =
                 *(float *)(pKVar11 + 0x1c) +
                 fVar8 * (*(float *)(this + 0x1c) - *(float *)(pKVar11 + 0x1c));
          }
          else if (param_2 == 0x100) {
            *(float *)(pKVar17 + 0x20) =
                 *(float *)(pKVar11 + 0x20) +
                 fVar8 * (*(float *)(this + 0x20) - *(float *)(pKVar11 + 0x20));
          }
          else if (param_2 == 0x1c0) {
            AEMath::VectorLerp(aAStack_40,(Vector *)(pKVar11 + 0x18),this_04,fVar8);
            this_03 = (Vector *)(pKVar17 + 0x18);
            goto LAB_000806a4;
          }
        }
        else if ((int)(-(uint)(0x3fff < uVar7) - uVar12) < 0 ==
                 (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3fff < uVar7)))) {
          if ((int)(-(uint)(0xfff < uVar7) - uVar12) < 0 ==
              (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xfff < uVar7)))) {
            if (param_2 == 0x200) {
              *(float *)(pKVar17 + 0x48) =
                   *(float *)(pKVar11 + 0x48) +
                   fVar8 * (*(float *)(this + 0x48) - *(float *)(pKVar11 + 0x48));
            }
            else if (param_2 == 0x400) {
              *(float *)(pKVar17 + 0x24) =
                   *(float *)(pKVar11 + 0x24) +
                   fVar8 * (*(float *)this_02 - *(float *)(pKVar11 + 0x24));
            }
            else {
              pKVar2 = (KeyFrame *)(uVar7 ^ 0x800 | uVar12);
              bVar21 = pKVar2 == (KeyFrame *)0x0;
              if (bVar21) {
                pKVar2 = pKVar11;
              }
              if (bVar21) {
                fVar16 = *(float *)(pKVar2 + 0x28);
                pKVar2 = this;
              }
              if (bVar21) {
                fVar8 = fVar16 + fVar8 * (*(float *)(pKVar2 + 0x28) - fVar16);
                pKVar2 = pKVar17;
              }
              if (bVar21) {
                *(float *)(pKVar2 + 0x28) = fVar8;
              }
            }
          }
          else if (param_2 == 0x1000) {
            *(float *)(pKVar17 + 0x2c) =
                 *(float *)(pKVar11 + 0x2c) +
                 fVar8 * (*(float *)(this + 0x2c) - *(float *)(pKVar11 + 0x2c));
          }
          else {
            if (param_2 == 0x1c00) {
              AEMath::VectorLerp(aAStack_40,(Vector *)(pKVar11 + 0x24),this_02,fVar8);
              this_03 = (Vector *)(pKVar17 + 0x24);
              goto LAB_000806a4;
            }
            pKVar2 = (KeyFrame *)(uVar7 ^ 0x2000 | uVar12);
            bVar21 = pKVar2 == (KeyFrame *)0x0;
            if (bVar21) {
              pKVar2 = pKVar11;
            }
            if (bVar21) {
              fVar8 = *(float *)(pKVar2 + 0x30) +
                      fVar8 * (*(float *)this_01 - *(float *)(pKVar2 + 0x30));
              pKVar2 = pKVar17;
            }
            if (bVar21) {
              *(float *)(pKVar2 + 0x30) = fVar8;
            }
          }
        }
        else if ((int)(-(uint)(0xffff < uVar7) - uVar12) < 0 ==
                 (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xffff < uVar7)))) {
          if (param_2 == 0x4000) {
            *(float *)(pKVar17 + 0x34) =
                 *(float *)(pKVar11 + 0x34) +
                 fVar8 * (*(float *)(this + 0x34) - *(float *)(pKVar11 + 0x34));
          }
          else if (param_2 == 0x8000) {
            *(float *)(pKVar17 + 0x38) =
                 *(float *)(pKVar11 + 0x38) +
                 fVar8 * (*(float *)(this + 0x38) - *(float *)(pKVar11 + 0x38));
          }
          else if (param_2 == 0xe000) {
            AEMath::VectorLerp(aAStack_40,(Vector *)(pKVar11 + 0x30),this_01,fVar8);
            this_03 = (Vector *)(pKVar17 + 0x30);
            goto LAB_000806a4;
          }
        }
        else if ((int)(-(uint)(0x3ffff < uVar7) - uVar12) < 0 ==
                 (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3ffff < uVar7)))) {
          if (param_2 == 0x10000) {
            *(float *)(pKVar17 + 0x3c) =
                 *(float *)(pKVar11 + 0x3c) +
                 fVar8 * (*(float *)this_00 - *(float *)(pKVar11 + 0x3c));
          }
          else {
            pKVar2 = (KeyFrame *)(uVar7 ^ 0x20000 | uVar12);
            bVar21 = pKVar2 == (KeyFrame *)0x0;
            if (bVar21) {
              pKVar2 = pKVar11;
            }
            if (bVar21) {
              fVar16 = *(float *)(pKVar2 + 0x40);
              pKVar2 = this;
            }
            if (bVar21) {
              fVar8 = fVar16 + fVar8 * (*(float *)(pKVar2 + 0x40) - fVar16);
              pKVar2 = pKVar17;
            }
            if (bVar21) {
              *(float *)(pKVar2 + 0x40) = fVar8;
            }
          }
        }
        else if (param_2 == 0x40000) {
          *(float *)(pKVar17 + 0x44) =
               *(float *)(pKVar11 + 0x44) +
               fVar8 * (*(float *)(this + 0x44) - *(float *)(pKVar11 + 0x44));
        }
        else if (param_2 == 0x70000) {
          AEMath::VectorLerp(aAStack_40,(Vector *)(pKVar11 + 0x3c),this_00,fVar8);
          this_03 = (Vector *)(pKVar17 + 0x3c);
          goto LAB_000806a4;
        }
      }
      fVar8 = param_1[0x47];
      fVar10 = (float)((int)fVar10 + 1);
    } while ((uint)fVar10 < (uint)fVar8);
    if (fVar10 != fVar8) {
      pfVar5 = *(float **)((int)param_1[0x48] + (int)fVar10 * 4);
      fVar16 = pfVar5[0x14];
      fVar8 = pfVar5[0x15];
      if (fVar8 == fVar6 && fVar16 == (float)param_3) {
        fVar6 = pfVar5[0x16];
        fVar8 = *(float *)(this + 0x18);
        if (((uint)fVar6 & 0x40) != 0) {
          fVar8 = fVar8 + pfVar5[6];
        }
        pfVar5[6] = fVar8;
        fVar8 = *(float *)(this + 0x1c);
        if (((uint)fVar6 & 0x80) != 0) {
          fVar8 = fVar8 + pfVar5[7];
        }
        pfVar5[7] = fVar8;
        fVar8 = *(float *)(this + 0x20);
        if (((uint)fVar6 & 0x100) != 0) {
          fVar8 = fVar8 + pfVar5[8];
        }
        pfVar5[8] = fVar8;
        fVar8 = *(float *)this;
        if (((uint)fVar6 & 1) != 0) {
          fVar8 = fVar8 + *pfVar5;
        }
        *pfVar5 = fVar8;
        fVar8 = *(float *)(this + 4);
        if (((uint)fVar6 & 2) != 0) {
          fVar8 = fVar8 + pfVar5[1];
        }
        pfVar5[1] = fVar8;
        fVar8 = *(float *)(this + 8);
        if (((uint)fVar6 & 4) != 0) {
          fVar8 = fVar8 + pfVar5[2];
        }
        pfVar5[2] = fVar8;
        fVar8 = *(float *)(this + 0xc);
        if (((uint)fVar6 & 8) != 0) {
          fVar8 = fVar8 * pfVar5[3];
        }
        pfVar5[3] = fVar8;
        fVar8 = *(float *)(this + 0x10);
        if (((uint)fVar6 & 0x10) != 0) {
          fVar8 = fVar8 * pfVar5[4];
        }
        pfVar5[4] = fVar8;
        fVar8 = *(float *)(this + 0x14);
        if (((uint)fVar6 & 0x20) != 0) {
          fVar8 = fVar8 * pfVar5[5];
        }
        pfVar5[5] = fVar8;
        pfVar5[0x12] = *(float *)(this + 0x48);
        fVar8 = *(float *)(this + 0x3c);
        if (((uint)fVar6 & 0x10000) != 0) {
          fVar8 = fVar8 + pfVar5[0xf];
        }
        pfVar5[0xf] = fVar8;
        fVar8 = *(float *)(this + 0x40);
        if (((uint)fVar6 & 0x20000) != 0) {
          fVar8 = fVar8 + pfVar5[0x10];
        }
        pfVar5[0x10] = fVar8;
        fVar8 = *(float *)(this + 0x44);
        if (((uint)fVar6 & 0x40000) != 0) {
          fVar8 = fVar8 + pfVar5[0x11];
        }
        pfVar5[0x11] = fVar8;
        fVar8 = *(float *)(this + 0x24);
        if (((uint)fVar6 & 0x400) != 0) {
          fVar8 = fVar8 + pfVar5[9];
        }
        pfVar5[9] = fVar8;
        fVar8 = *(float *)(this + 0x28);
        if (((uint)fVar6 & 0x800) != 0) {
          fVar8 = fVar8 + pfVar5[10];
        }
        pfVar5[10] = fVar8;
        fVar8 = *(float *)(this + 0x2c);
        if (((uint)fVar6 & 0x1000) != 0) {
          fVar8 = fVar8 + pfVar5[0xb];
        }
        pfVar5[0xb] = fVar8;
        fVar8 = *(float *)(this + 0x30);
        if (((uint)fVar6 & 0x2000) != 0) {
          fVar8 = fVar8 * pfVar5[0xc];
        }
        pfVar5[0xc] = fVar8;
        fVar8 = *(float *)(this + 0x34);
        if (((uint)fVar6 & 0x4000) != 0) {
          fVar8 = fVar8 * pfVar5[0xd];
        }
        pfVar5[0xd] = fVar8;
        fVar8 = *(float *)(this + 0x38);
        if (((uint)fVar6 & 0x8000) != 0) {
          fVar8 = fVar8 * pfVar5[0xe];
        }
        pfVar5[0xe] = fVar8;
        pfVar5[0x16] = (float)((uint)fVar6 | uVar7);
        pfVar5[0x17] = (float)((uint)pfVar5[0x17] | uVar12);
        *(uint *)pKVar1 = *(uint *)pKVar1 | uVar7;
        *(uint *)(this + 0x5c) = *(uint *)(this + 0x5c) | uVar12;
        UpdateKeyFrames((Transform *)param_1,this,(int)fVar10);
        operator_delete(this);
        goto LAB_00080b1e;
      }
      if (fVar10 == 0.0) {
        InsertKeyFrame((Transform *)param_1,this,0);
        fVar10 = 0.0;
      }
      else {
        iVar13 = (int)fVar10 * 4 + -4;
        iVar9 = *(int *)((int)param_1[0x48] + iVar13);
        fVar18 = *(float *)(iVar9 + 0x50);
        iVar20 = *(int *)(iVar9 + 0x54);
        fVar6 = *(float *)(this + 0x50);
        fVar6 = (float)__aeabi_l2f((int)fVar6 - (int)fVar18,
                                   (*(int *)(this + 0x54) - iVar20) -
                                   (uint)((uint)fVar6 < (uint)fVar18));
        fVar8 = (float)__aeabi_l2f((int)fVar16 - (int)fVar18,
                                   ((int)fVar8 - iVar20) - (uint)((uint)fVar16 < (uint)fVar18));
        AEMath::VectorLerp(aAStack_40,(Vector *)(iVar9 + 0x18),(Vector *)(pfVar5 + 6),fVar8);
        fVar16 = (float)AEMath::Vector::operator=(this_04,(Vector *)aAStack_40);
        AEMath::VectorLerp(aAStack_40,*(Vector **)((int)param_1[0x48] + iVar13),
                           *(Vector **)((int)param_1[0x48] + (int)fVar10 * 4),fVar16);
        fVar16 = (float)AEMath::Vector::operator=((Vector *)this,(Vector *)aAStack_40);
        AEMath::VectorLerp(aAStack_40,(Vector *)(*(int *)((int)param_1[0x48] + iVar13) + 0xc),
                           (Vector *)(*(int *)((int)param_1[0x48] + (int)fVar10 * 4) + 0xc),fVar16);
        AEMath::Vector::operator=((Vector *)(this + 0xc),(Vector *)aAStack_40);
        iVar20 = *(int *)((int)param_1[0x48] + iVar13);
        iVar9 = *(int *)((int)param_1[0x48] + (int)fVar10 * 4);
        fVar16 = *(float *)(iVar20 + 0x48);
        fVar16 = fVar16 + (fVar6 / fVar8) * (*(float *)(iVar9 + 0x48) - fVar16);
        *(float *)(this + 0x48) = fVar16;
        AEMath::VectorLerp(aAStack_40,(Vector *)(iVar20 + 0x3c),(Vector *)(iVar9 + 0x3c),fVar16);
        fVar6 = (float)AEMath::Vector::operator=(this_00,(Vector *)aAStack_40);
        AEMath::VectorLerp(aAStack_40,(Vector *)(*(int *)((int)param_1[0x48] + iVar13) + 0x24),
                           (Vector *)(*(int *)((int)param_1[0x48] + (int)fVar10 * 4) + 0x24),fVar6);
        fVar6 = (float)AEMath::Vector::operator=(this_02,(Vector *)aAStack_40);
        AEMath::VectorLerp(aAStack_40,(Vector *)(*(int *)((int)param_1[0x48] + iVar13) + 0x30),
                           (Vector *)(*(int *)((int)param_1[0x48] + (int)fVar10 * 4) + 0x30),fVar6);
        AEMath::Vector::operator=(this_01,(Vector *)aAStack_40);
        uVar3 = *(uint *)(*(int *)((int)param_1[0x48] + iVar13) + 0x5c);
        *(uint *)pKVar1 = *(uint *)(*(int *)((int)param_1[0x48] + iVar13) + 0x58) | *(uint *)pKVar1;
        *(uint *)(this + 0x5c) = uVar3 | *(uint *)(this + 0x5c);
        if ((int)(-(uint)(0x1ff < uVar7) - uVar12) < 0 ==
            (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1ff < uVar7)))) {
          if ((int)(-(uint)(0x1f < uVar7) - uVar12) < 0 ==
              (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x1f < uVar7)))) {
            uVar3 = uVar7 - 1;
            iVar9 = uVar12 - (uVar7 == 0);
            if ((uint)-iVar9 < (uint)(uVar3 < 8)) {
                    /* WARNING: Could not recover jumptable at 0x00080d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(&DAT_00080d38 + (uint)*(ushort *)(&DAT_00080d38 + uVar3 * 2) * 2))
                        (uVar3,-(uint)(uVar3 >= 8) - iVar9,fVar10,7 - uVar3);
              return;
            }
            if (param_2 == 0x10) {
              *(float *)(this + 0x10) = *in_r1;
            }
          }
          else if ((int)(-(uint)(0x7f < uVar7) - uVar12) < 0 ==
                   (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x7f < uVar7)))) {
            if (param_2 == 0x20) {
              *(float *)(this + 0x14) = *in_r1;
            }
            else if (param_2 == 0x38) {
              *(float *)(this + 0xc) = *in_r1;
              *(float *)(this + 0x10) = in_r1[1];
              *(float *)(this + 0x14) = in_r1[2];
            }
            else if (param_2 == 0x40) {
              *(float *)this_04 = *in_r1;
            }
          }
          else if (param_2 == 0x80) {
            *(float *)(this + 0x1c) = *in_r1;
          }
          else if (param_2 == 0x100) {
            *(float *)(this + 0x20) = *in_r1;
          }
          else if (param_2 == 0x1c0) {
            *(float *)(this + 0x18) = *in_r1;
            *(float *)(this + 0x1c) = in_r1[1];
            *(float *)(this + 0x20) = in_r1[2];
          }
        }
        else if ((int)(-(uint)(0x3fff < uVar7) - uVar12) < 0 ==
                 (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3fff < uVar7)))) {
          if ((int)(-(uint)(0xfff < uVar7) - uVar12) < 0 ==
              (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xfff < uVar7)))) {
            if (param_2 == 0x200) {
              *(float *)(this + 0x48) = *in_r1;
            }
            else if (param_2 == 0x400) {
              *(float *)this_02 = -*in_r1;
            }
            else if (param_2 == 0x800) {
              *(float *)(this + 0x28) = *in_r1;
            }
          }
          else if (param_2 == 0x1000) {
            *(float *)(this + 0x2c) = *in_r1;
          }
          else if (param_2 == 0x1c00) {
            *(float *)(this + 0x24) = -*in_r1;
            *(float *)(this + 0x28) = in_r1[1];
            *(float *)(this + 0x2c) = in_r1[2];
          }
          else if (param_2 == 0x2000) {
            *(float *)this_01 = *in_r1;
          }
        }
        else {
          pfVar5 = (float *)(-(uint)(0xffff < uVar7) - uVar12);
          if ((int)pfVar5 < 0 == (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0xffff < uVar7)))) {
            if (param_2 == 0x4000) {
              *(float *)(this + 0x34) = -*in_r1;
            }
            else if (param_2 == 0x8000) {
              *(float *)(this + 0x38) = *in_r1;
            }
            else {
              if (param_2 == 0xe000) {
                *(float *)(this + 0x30) = *in_r1;
                pfVar5 = in_r1;
              }
              if (param_2 == 0xe000) {
                *(float *)(this + 0x34) = -pfVar5[1];
                *(float *)(this + 0x38) = pfVar5[2];
              }
            }
          }
          else if ((int)(-(uint)(0x3ffff < uVar7) - uVar12) < 0 ==
                   (SBORROW4(0,uVar12) != SBORROW4(-uVar12,(uint)(0x3ffff < uVar7)))) {
            if (param_2 == 0x10000) {
              *(float *)this_00 = *in_r1;
            }
            else if (param_2 == 0x20000) {
              *(float *)(this + 0x40) = -*in_r1;
            }
          }
          else {
            if (param_2 == 0x40000) {
              fVar6 = *in_r1;
            }
            else {
              if (param_2 != 0x70000) goto LAB_00080f4c;
              *(float *)(this + 0x3c) = *in_r1;
              *(float *)(this + 0x40) = -in_r1[1];
              fVar6 = in_r1[2];
            }
            *(float *)(this + 0x44) = fVar6;
          }
        }
LAB_00080f4c:
        InsertKeyFrame((Transform *)param_1,this,(int)fVar10);
      }
      UpdateKeyFrames((Transform *)param_1,this,(int)fVar10);
      goto LAB_00080b1e;
    }
    uVar3 = *(uint *)pKVar1;
    if ((uVar3 & 0x40) == 0) {
      *(undefined4 *)(this + 0x18) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x18);
    }
    if ((uVar3 & 0x80) == 0) {
      *(undefined4 *)(this + 0x1c) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x1c);
    }
    if ((uVar3 & 0x100) == 0) {
      *(undefined4 *)(this + 0x20) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x20);
    }
    if ((uVar3 & 1) == 0) {
      *(undefined4 *)this = **(undefined4 **)((int)param_1[0x48] + (int)fVar8 * 4 + -4);
    }
    if ((uVar3 & 2) == 0) {
      *(undefined4 *)(this + 4) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 4);
    }
    if ((uVar3 & 4) == 0) {
      *(undefined4 *)(this + 8) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 8);
    }
    if ((uVar3 & 8) == 0) {
      *(undefined4 *)(this + 0xc) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0xc);
    }
    if ((uVar3 & 0x10) == 0) {
      *(undefined4 *)(this + 0x10) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x10);
    }
    if ((uVar3 & 0x20) == 0) {
      *(undefined4 *)(this + 0x14) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x14);
    }
    if ((uVar3 & 0x200) == 0) {
      *(undefined4 *)(this + 0x48) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x48);
    }
    if ((uVar3 & 0x10000) == 0) {
      *(undefined4 *)(this + 0x3c) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x3c);
    }
    if ((uVar3 & 0x20000) == 0) {
      *(undefined4 *)(this + 0x40) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x40);
    }
    if ((uVar3 & 0x40000) == 0) {
      *(undefined4 *)(this + 0x44) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x44);
    }
    if ((uVar3 & 0x400) == 0) {
      *(undefined4 *)(this + 0x24) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x24);
    }
    if ((uVar3 & 0x800) == 0) {
      *(undefined4 *)(this + 0x28) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x28);
    }
    if ((uVar3 & 0x1000) == 0) {
      *(undefined4 *)(this + 0x2c) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x2c);
    }
    if ((uVar3 & 0x2000) == 0) {
      *(undefined4 *)(this + 0x30) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x30);
    }
    if ((uVar3 & 0x4000) == 0) {
      *(undefined4 *)(this + 0x34) =
           *(undefined4 *)(*(int *)((int)param_1[0x48] + (int)fVar8 * 4 + -4) + 0x34);
    }
    if ((uVar3 & 0x8000) == 0) {
      pvVar4 = (void *)param_1[0x48];
      *(undefined4 *)(this + 0x38) =
           *(undefined4 *)(*(int *)((int)pvVar4 + (int)fVar8 * 4 + -4) + 0x38);
    }
    else {
      pvVar4 = (void *)param_1[0x48];
    }
    *(uint *)pKVar1 = uVar3 | uVar7;
    *(uint *)(this + 0x5c) = *(uint *)(this + 0x5c) | uVar12;
    param_1[0x49] = (float)((int)fVar8 + 1);
    pvVar4 = realloc(pvVar4,((int)fVar8 + 1) * 4);
    param_1[0x48] = (float)pvVar4;
    *(KeyFrame **)((int)pvVar4 + (int)param_1[0x47] * 4) = this;
  }
  param_1[0x47] = param_1[0x49];
LAB_00080b1e:
  if (__stack_chk_guard == local_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Transform::DebugOut  @0x00080f74  (2 bytes)
/* AbyssEngine::Transform::DebugOut(int) */

int AbyssEngine::Transform::DebugOut(int param_1)

{
  return param_1;
}

// ===== AbyssEngine::Transform::IsRunning  @0x00080f76  (42 bytes)
/* AbyssEngine::Transform::IsRunning() */

undefined4 __thiscall AbyssEngine::Transform::IsRunning(Transform *this)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(this + 0x110);
  iVar1 = *(int *)(this + 0x114);
  iVar3 = *(int *)(this + 0x104);
  if ((((int)((iVar3 - iVar1) - (uint)(*(uint *)(this + 0x100) < uVar2)) < 0 !=
        (SBORROW4(iVar3,iVar1) != SBORROW4(iVar3 - iVar1,(uint)(*(uint *)(this + 0x100) < uVar2))))
      && (iVar3 = *(int *)(this + 0x10c),
         (int)((iVar1 - iVar3) - (uint)(uVar2 < *(uint *)(this + 0x108))) < 0 !=
         (SBORROW4(iVar1,iVar3) != SBORROW4(iVar1 - iVar3,(uint)(uVar2 < *(uint *)(this + 0x108)))))
      ) && (this[0xed] != (Transform)0x0)) {
    return 1;
  }
  return 0;
}

// ===== AbyssEngine::Transform::SetCurrentAnimationTime  @0x00080fa0  (6 bytes)
/* AbyssEngine::Transform::SetCurrentAnimationTime(long long) */

void AbyssEngine::Transform::SetCurrentAnimationTime(longlong param_1)

{
  undefined4 in_r2;
  undefined4 in_r3;
  
  *(undefined4 *)((int)param_1 + 0x110) = in_r2;
  *(undefined4 *)((int)param_1 + 0x114) = in_r3;
  return;
}

// ===== AbyssEngine::Transform::SetVFCFlag  @0x00080fa6  (78 bytes)
/* AbyssEngine::Transform::SetVFCFlag(bool) */

void __thiscall AbyssEngine::Transform::SetVFCFlag(Transform *this,bool param_1)

{
  int iVar1;
  Transform *pTVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(this + 0x3c);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      iVar1 = *(int *)(*(int *)(this + 0x40) + uVar4 * 4);
      if ((iVar1 != 0) && (pTVar2 = *(Transform **)(iVar1 + 0x34), pTVar2 != (Transform *)0x0)) {
        SetVFCFlag(pTVar2,param_1);
        uVar3 = *(uint *)(this + 0x3c);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  uVar3 = *(uint *)(this + 0x4c);
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      pTVar2 = *(Transform **)(*(int *)(this + 0x50) + uVar4 * 4);
      if (pTVar2 != (Transform *)0x0) {
        SetVFCFlag(pTVar2,param_1);
        uVar3 = *(uint *)(this + 0x4c);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  this[0x17c] = (Transform)param_1;
  return;
}

// ===== AbyssEngine::Transform::InCameraVF  @0x00080ff4  (302 bytes)
/* AbyssEngine::Transform::InCameraVF(AbyssEngine::AEMath::Matrix*, AbyssEngine::Camera*) */

void __thiscall AbyssEngine::Transform::InCameraVF(Transform *this,Matrix *param_1,Camera *param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  Vector *this_00;
  float fVar3;
  undefined8 uVar4;
  longlong lVar5;
  float fVar6;
  undefined8 uVar7;
  AEMath aAStack_88 [60];
  AEMath aAStack_4c [12];
  float local_40;
  float fStack_3c;
  float local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  int local_24;
  
  this_00 = (Vector *)aAStack_88;
  local_24 = __stack_chk_guard;
  if (((param_2 == (Camera *)0x0) || (this[0x17c] == (Transform)0x0)) ||
     ((*(int *)(this + 0x3c) == 1 && (*(short *)(**(int **)(this + 0x40) + 2) == 0)))) {
    uVar2 = 1;
  }
  else {
    local_30 = 0;
    uStack_2c = 0;
    local_28 = 0;
    local_40 = *(float *)(this + 0xe0);
    fStack_3c = local_40;
    local_38 = local_40;
    if (param_1 == (Matrix *)0x0) {
      AEMath::MatrixTransformVector(aAStack_88,this,(Vector *)(this + 0xd4));
      AEMath::Vector::operator=((Vector *)&local_30,(Vector *)aAStack_88);
      AEMath::MatrixRotateVector(aAStack_88,this,(Vector *)&local_40);
    }
    else {
      AEMath::operator*(aAStack_88,param_1,this);
      AEMath::MatrixTransformVector(aAStack_4c,aAStack_88,(Vector *)(this + 0xd4));
      AEMath::Vector::operator=((Vector *)&local_30,(Vector *)aAStack_4c);
      AEMath::operator*(aAStack_88,param_1,this);
      this_00 = (Vector *)aAStack_4c;
      AEMath::MatrixRotateVector((AEMath *)this_00,aAStack_88,(Vector *)&local_40);
    }
    AEMath::Vector::operator=((Vector *)&local_40,this_00);
    uVar1 = CONCAT44(fStack_3c,local_40);
    uVar7 = FloatVectorNeg(uVar1,2,2);
    uVar4 = FloatVectorCompareGreaterThan(uVar1,0,2);
    lVar5 = VectorBitwiseSelect(uVar4,uVar1,uVar7);
    if ((float)((ulonglong)lVar5 >> 0x20) < (float)lVar5) {
      lVar5 = lVar5 << 0x20;
    }
    fVar3 = -local_38;
    if (0.0 < local_38) {
      fVar3 = local_38;
    }
    fVar6 = (float)((ulonglong)lVar5 >> 0x20);
    if (fVar3 < fVar6) {
      fVar3 = fVar6;
    }
    uVar2 = CameraIsSphereinViewFrustum
                      ((Vector *)&local_30,*(float *)(this + 0xe4) * fVar3,
                       (Matrix *)(*(float *)(this + 0xe4) * fVar3),(Camera *)0x0);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

// ===== AbyssEngine::Transform::~Transform  @0x0008112c  (78 bytes)
/* AbyssEngine::Transform::~Transform() */

Transform * __thiscall AbyssEngine::Transform::~Transform(Transform *this)

{
  if (this[0x17d] == (Transform)0x0) {
    ArrayReleaseClasses<AbyssEngine::KeyFrame*>((Array *)(this + 0x11c));
  }
  Quaternion::~Quaternion((Quaternion *)(this + 0x150));
  Quaternion::~Quaternion((Quaternion *)(this + 0x128));
  if (*(void **)(this + 0x120) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x120));
  }
  *(undefined4 *)(this + 0x120) = 0;
  if (*(void **)(this + 0x50) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x50));
  }
  *(undefined4 *)(this + 0x50) = 0;
  if (*(void **)(this + 0x40) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x40));
  }
  *(undefined4 *)(this + 0x40) = 0;
  return this;
}

// ===== AbyssEngine::Transform::SetVisible  @0x000811b6  (6 bytes)
/* AbyssEngine::Transform::SetVisible(bool) */

void __thiscall AbyssEngine::Transform::SetVisible(Transform *this,bool param_1)

{
  this[0xec] = (Transform)param_1;
  return;
}

