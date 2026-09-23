// Class: Explosion
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Explosion::Explosion  @0x000b4a90  (888 bytes)
/* Explosion::Explosion(int) */

Explosion * __thiscall Explosion::Explosion(Explosion *this,int param_1)

{
  void *pvVar1;
  AEGeometry *pAVar2;
  Transform *this_00;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  float fVar10;
  float extraout_s0;
  
  *(undefined4 *)(this + 0x2c) = 0x3f800000;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x40) = 0x3f800000;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined8 *)(this + 0x54) = 0x3f800000;
  *(undefined8 *)(this + 0x5c) = 0x3f8000003f800000;
  *(undefined4 *)(this + 100) = 0x3f800000;
  *(undefined4 *)(this + 0x24) = 0x3f800000;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(int *)this = param_1;
  *(undefined4 *)(this + 4) = 0;
  switch(param_1) {
  case 0:
  case 6:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x41b5,Globals::Canvas,false);
    *(AEGeometry **)(this + 4) = pAVar2;
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x41b4,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 4),*(uint *)(pAVar2 + 0xc));
    pvVar1 = (void *)AEGeometry::~AEGeometry(pAVar2);
    operator_delete(pvVar1);
    goto LAB_000b4d46;
  default:
    pAVar2 = operator_new(0xc0);
    if (param_1 != 0xd) {
      AEGeometry::AEGeometry(pAVar2,0x4213,Globals::Canvas,false);
      *(AEGeometry **)(this + 4) = pAVar2;
      pAVar2 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar2,0x4211,Globals::Canvas,false);
      goto LAB_000b4d44;
    }
    fVar10 = (float)AEGeometry::AEGeometry(pAVar2,0x41a9,Globals::Canvas,false);
    *(AEGeometry **)(this + 4) = pAVar2;
    setScaling(fVar10);
    this_00 = (Transform *)
              AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
    AbyssEngine::Transform::SetAnimationSpeed(this_00,extraout_s0);
    goto LAB_000b4d46;
  case 3:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4213,Globals::Canvas,false);
    *(AEGeometry **)(this + 4) = pAVar2;
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x421d,Globals::Canvas,false);
    goto LAB_000b4d44;
  case 4:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x420d,Globals::Canvas,false);
    *(AEGeometry **)(this + 4) = pAVar2;
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x420c,Globals::Canvas,false);
    goto LAB_000b4d44;
  case 5:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4999,Globals::Canvas,false);
    *(AEGeometry **)(this + 4) = pAVar2;
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4998,Globals::Canvas,false);
    goto LAB_000b4d44;
  case 7:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x41a5,Globals::Canvas,false);
    break;
  case 8:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x41a6,Globals::Canvas,false);
    break;
  case 9:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x41a7,Globals::Canvas,false);
    break;
  case 10:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x41a8,Globals::Canvas,false);
    break;
  case 0xb:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4a34,Globals::Canvas,false);
    *(AEGeometry **)(this + 4) = pAVar2;
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4a33,Globals::Canvas,false);
LAB_000b4d44:
    *(AEGeometry **)(this + 8) = pAVar2;
    goto LAB_000b4d46;
  case 0xc:
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x4a7e,Globals::Canvas,false);
  }
  *(AEGeometry **)(this + 4) = pAVar2;
LAB_000b4d46:
  uVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar3,1,0);
  if (*(int *)(this + 8) != 0) {
    uVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar3,1,0);
    iVar4 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    *(undefined4 *)(iVar4 + 0xe0) = 0x469c4000;
  }
  iVar4 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  uVar8 = *(uint *)(iVar4 + 0xf8);
  iVar4 = *(int *)(iVar4 + 0xfc);
  if (*(int *)(this + 8) == 0) {
    uVar6 = 0;
    iVar5 = 0;
  }
  else {
    iVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    uVar6 = *(uint *)(iVar5 + 0xf8);
    iVar5 = *(int *)(iVar5 + 0xfc);
  }
  bVar9 = uVar6 < uVar8;
  if ((int)((iVar5 - iVar4) - (uint)bVar9) < 0 ==
      (SBORROW4(iVar5,iVar4) != SBORROW4(iVar5 - iVar4,(uint)bVar9))) {
    if (*(int *)(this + 8) == 0) {
      uVar3 = 0;
      uVar7 = 0;
      goto LAB_000b4dea;
    }
    uVar8 = *(uint *)(*(int *)(this + 8) + 0xc);
  }
  else {
    uVar8 = *(uint *)(*(int *)(this + 4) + 0xc);
  }
  iVar4 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar8);
  uVar3 = *(undefined4 *)(iVar4 + 0xf8);
  uVar7 = *(undefined4 *)(iVar4 + 0xfc);
LAB_000b4dea:
  *(undefined4 *)(this + 0x10) = uVar3;
  *(undefined4 *)(this + 0x14) = uVar7;
  iVar4 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  *(undefined4 *)(iVar4 + 0xe0) = 0x469c4000;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  reset(this);
  return this;
}

// ===== Explosion::setScaling  @0x000b4ee0  (290 bytes)
/* Explosion::setScaling(float) */

void Explosion::setScaling(float param_1)

{
  int *in_r0;
  undefined4 uVar1;
  Transform *pTVar2;
  uint *puVar3;
  float fVar4;
  float in_r1;
  uint uVar5;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float in_s1;
  float extraout_s1;
  float in_s2;
  float extraout_s2;
  float fVar6;
  undefined8 uVar7;
  
  in_r0[9] = (int)in_r1;
  AEGeometry::setScaling((AEGeometry *)in_r0[1],param_1,in_s1,in_s2);
  if ((AEGeometry *)in_r0[2] != (AEGeometry *)0x0) {
    AEGeometry::setScaling((AEGeometry *)in_r0[2],extraout_s0,extraout_s1,extraout_s2);
  }
  fVar6 = 1.0;
  in_fpscr = in_fpscr & 0xfffffff;
  if (in_r1 < 1.0) {
    fVar6 = (1.0 - in_r1) * 3.0 + 1.0;
  }
  if (*in_r0 == 0xb) {
    fVar6 = fVar6 * 0.5;
  }
  if (*in_r0 - 8U < 3) {
    uVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x3c);
    fVar6 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    fVar6 = fVar6 * 0.01 + 0.7;
  }
  pTVar2 = (Transform *)
           AbyssEngine::PaintCanvas::TransformGetTransform
                     (Globals::Canvas,*(uint *)(in_r0[1] + 0xc));
  AbyssEngine::Transform::SetAnimationSpeed(pTVar2,extraout_s0_00);
  if (in_r0[2] != 0) {
    pTVar2 = (Transform *)
             AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(in_r0[2] + 0xc));
    AbyssEngine::Transform::SetAnimationSpeed(pTVar2,extraout_s0_01);
  }
  puVar3 = (uint *)in_r0[3];
  if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
    uVar5 = 0;
    do {
      pTVar2 = (Transform *)
               AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(puVar3[1] + uVar5 * 4) + 0xc));
      AbyssEngine::Transform::SetAnimationSpeed(pTVar2,extraout_s0_02);
      puVar3 = (uint *)in_r0[3];
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar3);
  }
  fVar4 = (float)__aeabi_l2f(in_r0[4],in_r0[5]);
  uVar7 = __aeabi_f2lz(fVar4 / fVar6);
  *(undefined8 *)(in_r0 + 4) = uVar7;
  return;
}

// ===== Explosion::reset  @0x000b501c  (318 bytes)
/* Explosion::reset() */

void __thiscall Explosion::reset(Explosion *this)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  
  uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar1,3,0);
  uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
  if (*(uint *)(*(int *)(this + 4) + 0x14) != 0xffffffff) {
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0x14));
    AbyssEngine::Transform::SetAnimationState(uVar1,3,0);
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0x14));
    AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
  }
  if (*(int *)(this + 8) != 0) {
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar1,3,0);
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
  }
  if (*(int *)this == 6) {
    lVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
    AbyssEngine::Transform::SetAnimationRangeInTime(lVar5,0x8fc);
    lVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    AbyssEngine::Transform::SetAnimationRangeInTime(lVar5,0x8fc);
  }
  puVar2 = *(uint **)(this + 0xc);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar4 = 0;
    do {
      iVar3 = *(int *)(puVar2[1] + uVar4 * 4);
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(iVar3 + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar1,3,0);
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(iVar3 + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
      puVar2 = *(uint **)(this + 0xc);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  this[0x20] = (Explosion)0x0;
  return;
}

// ===== Explosion::~Explosion  @0x000b5170  (70 bytes)
/* Explosion::~Explosion() */

Explosion * __thiscall Explosion::~Explosion(Explosion *this)

{
  void *pvVar1;
  
  if (*(AEGeometry **)(this + 4) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(AEGeometry **)(this + 8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(Array **)(this + 0xc) != (Array *)0x0) {
    ArrayReleaseClasses<AEGeometry*>(*(Array **)(this + 0xc));
    pvVar1 = *(void **)(this + 0xc);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  return this;
}

// ===== Explosion::addFireStreaks  @0x000b51b8  (382 bytes)
/* Explosion::addFireStreaks() */

void __thiscall Explosion::addFireStreaks(Explosion *this)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  AEGeometry *pAVar4;
  undefined4 uVar5;
  uint uVar6;
  uint in_fpscr;
  float fVar7;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float fVar8;
  
  if (*(int *)(this + 0xc) == 0) {
    puVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    puVar1[1] = puVar2;
    puVar1[2] = 1;
    *puVar2 = 0;
    *puVar1 = 0;
    *(undefined4 **)(this + 0xc) = puVar1;
    iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
    ArraySetLength<AEGeometry*>(iVar3 + 3,*(Array **)(this + 0xc));
    if (**(int **)(this + 0xc) != 0) {
      uVar6 = 0;
      do {
        pAVar4 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar4,0x37d4,Globals::Canvas,false);
        *(AEGeometry **)(*(int *)(*(int *)(this + 0xc) + 4) + uVar6 * 4) = pAVar4;
        uVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,
                           *(uint *)(*(int *)(*(int *)(*(int *)(this + 0xc) + 4) + uVar6 * 4) + 0xc)
                          );
        AbyssEngine::Transform::SetAnimationState(uVar5,1,0);
        iVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,
                           *(uint *)(*(int *)(*(int *)(*(int *)(this + 0xc) + 4) + uVar6 * 4) + 0xc)
                          );
        *(undefined4 *)(iVar3 + 0xe0) = 0x461c4000;
        pAVar4 = *(AEGeometry **)(*(int *)(*(int *)(this + 0xc) + 4) + uVar6 * 4);
        uVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x168);
        fVar8 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
        uVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x168);
        VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
        uVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x168);
        fVar7 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
        AEGeometry::setRotation
                  (pAVar4,(fVar7 / 180.0) * 3.1415927,extraout_s1,(fVar8 / 180.0) * 3.1415927);
        iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x32);
        fVar7 = (float)VectorSignedToFloat(iVar3 + 0x32,(byte)(in_fpscr >> 0x16) & 3);
        AEGeometry::setScaling
                  (*(AEGeometry **)(*(int *)(*(int *)(this + 0xc) + 4) + uVar6 * 4),fVar7 / 100.0,
                   extraout_s1_00,extraout_s2);
        uVar6 = uVar6 + 1;
      } while (uVar6 < **(uint **)(this + 0xc));
    }
  }
  return;
}

// ===== Explosion::setWeaponIndex  @0x000b5364  (4 bytes)
/* Explosion::setWeaponIndex(int) */

void __thiscall Explosion::setWeaponIndex(Explosion *this,int param_1)

{
  *(int *)(this + 0x28) = param_1;
  return;
}

// ===== Explosion::playSound  @0x000b5368  (222 bytes)
/* Explosion::playSound(AbyssEngine::AEMath::Vector*) */

void Explosion::playSound(Vector *param_1)

{
  FModSound *this;
  Vector *in_r1;
  int iVar1;
  int iVar2;
  float in_s0;
  float extraout_s0;
  
  this = Globals::sound;
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 < 0) {
    if (3 < *(int *)param_1 - 2U) {
      if (*(int *)param_1 != 0) {
        return;
      }
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar2 = 0x13;
      in_s0 = extraout_s0;
      if (iVar1 == 0) {
        iVar2 = 0x12;
      }
      goto LAB_000b544a;
    }
    if (Globals::options[0xf] == '\0') {
      in_r1 = (Vector *)0x0;
    }
    iVar2 = 0x15;
  }
  else {
    if (iVar1 < 0xb0) {
      iVar2 = 0xf;
      switch(iVar1) {
      case 0x29:
        break;
      case 0x2a:
        iVar2 = 0x10;
        break;
      case 0x2b:
        iVar2 = 0x11;
        break;
      case 0x2c:
        iVar2 = 0xe;
        break;
      case 0x2d:
        iVar2 = 0xd;
        break;
      case 0x2e:
switchD_000b5386_caseD_2e:
        iVar2 = 0xc;
        break;
      default:
        goto switchD_000b5386_caseD_2f;
      case 0x3c:
      case 0x3d:
      case 0x3e:
switchD_000b5386_caseD_3c:
        iVar2 = 0x16;
      }
    }
    else {
      if (iVar1 < 0xb3) goto switchD_000b5386_caseD_3c;
      if (iVar1 < 0xdd) {
        if (iVar1 == 0xb3) goto switchD_000b5386_caseD_2e;
        if (iVar1 != 0xc5) {
          return;
        }
      }
      else if (iVar1 != 0xdd) {
        if (iVar1 != 0xe8) {
          return;
        }
        iVar2 = 0x8e7;
        goto switchD_000b5386_caseD_29;
      }
      iVar2 = 0x8cd;
    }
switchD_000b5386_caseD_29:
LAB_000b544a:
    if (Globals::options[0xf] == '\0') {
      in_r1 = (Vector *)0x0;
    }
  }
  FModSound::play(this,iVar2,in_r1,(Vector *)0x0,in_s0);
switchD_000b5386_caseD_2f:
  return;
}

// ===== Explosion::start  @0x000b5478  (384 bytes)
/* Explosion::start(AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&) */

void __thiscall Explosion::start(Explosion *this,Vector *param_1,Vector *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  Vector *pVVar5;
  uint in_fpscr;
  float fVar6;
  float extraout_s1;
  undefined8 local_60;
  undefined4 local_58;
  int local_24;
  
  local_24 = __stack_chk_guard;
  AEGeometry::setPosition(*(Vector **)(this + 4));
  iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  *(undefined1 *)(iVar1 + 0xed) = 1;
  if (*(uint *)(*(int *)(this + 4) + 0x14) != 0xffffffff) {
    iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0x14));
    *(undefined1 *)(iVar1 + 0xed) = 1;
  }
  if (*(Vector **)(this + 8) != (Vector *)0x0) {
    AEGeometry::setPosition(*(Vector **)(this + 8));
    iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    *(undefined1 *)(iVar1 + 0xed) = 1;
  }
  if (*(int *)this - 8U < 3) {
    uVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xc45);
    fVar6 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::MatrixSetRotation((Matrix *)&local_60,fVar6 / 1000.0,extraout_s1,1000.0);
    uVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x28);
    fVar6 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
    setScaling(fVar6 * 0.01 + 0.6);
  }
  else if (*(int *)this == 0xb) {
    local_60 = 0x3f80000000000000;
    local_58 = 0;
    AEGeometry::setDirection(*(AEGeometry **)(this + 4),param_2,(Vector *)&local_60);
    local_60 = 0x3f80000000000000;
    local_58 = 0;
    AEGeometry::setDirection(*(AEGeometry **)(this + 8),param_2,(Vector *)&local_60);
  }
  puVar3 = *(uint **)(this + 0xc);
  if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
    uVar4 = 0;
    do {
      pVVar5 = *(Vector **)(puVar3[1] + uVar4 * 4);
      AEGeometry::setPosition(pVVar5);
      iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(pVVar5 + 0xc));
      *(undefined1 *)(iVar1 + 0xed) = 1;
      uVar4 = uVar4 + 1;
      puVar3 = *(uint **)(this + 0xc);
    } while (uVar4 < *puVar3);
  }
  this[0x20] = (Explosion)0x1;
  local_60 = *(undefined8 *)param_1;
  local_58 = *(undefined4 *)(param_1 + 8);
  playSound((Vector *)this);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Explosion::start  @0x000b5620  (304 bytes)
/* Explosion::start(AbyssEngine::AEMath::Matrix const&) */

void __thiscall Explosion::start(Explosion *this,Matrix *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  Vector *pVVar4;
  AEMath aAStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(int *)this == 6 || *(int *)this == 0) {
    pVVar4 = *(Vector **)(this + 4);
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_34,param_1);
    AEGeometry::setPosition(pVVar4);
    pVVar4 = *(Vector **)(this + 8);
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_34,param_1);
    AEGeometry::setPosition(pVVar4);
  }
  else {
    AEGeometry::setMatrix(*(Matrix **)(this + 4));
    if (*(Matrix **)(this + 8) != (Matrix *)0x0) {
      AEGeometry::setMatrix(*(Matrix **)(this + 8));
    }
  }
  puVar1 = *(uint **)(this + 0xc);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      pVVar4 = *(Vector **)(puVar1[1] + uVar3 * 4);
      AbyssEngine::AEMath::MatrixGetPosition(aAStack_34,param_1);
      AEGeometry::setPosition(pVVar4);
      iVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(pVVar4 + 0xc));
      *(undefined1 *)(iVar2 + 0xed) = 1;
      uVar3 = uVar3 + 1;
      puVar1 = *(uint **)(this + 0xc);
    } while (uVar3 < *puVar1);
  }
  iVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  *(undefined1 *)(iVar2 + 0xed) = 1;
  if (*(uint *)(*(int *)(this + 4) + 0x14) != 0xffffffff) {
    iVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0x14));
    *(undefined1 *)(iVar2 + 0xed) = 1;
  }
  if (*(int *)(this + 8) != 0) {
    iVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    *(undefined1 *)(iVar2 + 0xed) = 1;
  }
  this[0x20] = (Explosion)0x1;
  AbyssEngine::AEMath::MatrixGetPosition(aAStack_34,param_1);
  playSound((Vector *)this);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Explosion::update  @0x000b5768  (452 bytes)
/* Explosion::update(int, TargetFollowCamera*) */

void __thiscall Explosion::update(Explosion *this,int param_1,TargetFollowCamera *param_2)

{
  PaintCanvas *this_00;
  uint uVar1;
  uint *puVar2;
  Matrix *pMVar3;
  float fVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  uint in_fpscr;
  float fVar8;
  float fVar9;
  longlong lVar10;
  AEMath aAStack_4c [12];
  Vector aVStack_40 [12];
  AEMath aAStack_34 [12];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (this[0x20] != (Explosion)0x0) {
    lVar10 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
    bVar6 = SUB41(param_1,0);
    AbyssEngine::Transform::Update(lVar10,bVar6);
    if (*(uint *)(*(int *)(this + 4) + 0x14) != 0xffffffff) {
      lVar10 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0x14));
      AbyssEngine::Transform::Update(lVar10,bVar6);
    }
    if (*(int *)(this + 8) != 0) {
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
      AbyssEngine::Transform::Update((ulonglong)uVar1,bVar6);
    }
    puVar2 = *(uint **)(this + 0xc);
    if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
      uVar1 = 0;
      do {
        lVar10 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(puVar2[1] + uVar1 * 4) + 0xc));
        AbyssEngine::Transform::Update(lVar10,bVar6);
        puVar2 = *(uint **)(this + 0xc);
        uVar1 = uVar1 + 1;
      } while (uVar1 < *puVar2);
    }
    if ((param_2 != (TargetFollowCamera *)0x0) && (*(uint *)this < 2)) {
      AEGeometry::getPosition();
      this_00 = Globals::Canvas;
      uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      pMVar3 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar1);
      AbyssEngine::AEMath::MatrixGetPosition(aAStack_4c,pMVar3);
      AbyssEngine::AEMath::operator-(aAStack_34,aVStack_40,(Vector *)aAStack_4c);
      fVar4 = (float)AbyssEngine::AEMath::VectorLength((Vector *)aAStack_34);
      iVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
      if (*(int *)(iVar5 + 0x110) < 0x7d1) {
        fVar8 = (float)VectorSignedToFloat(*(int *)(iVar5 + 0x110),
                                           (byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
        fVar9 = 30000.0;
        if (fVar4 < 30000.0) {
          fVar9 = fVar4;
        }
        fVar4 = (1.0 - fVar9 / 30000.0) * (fVar8 / -2000.0 + 1.0);
        TargetFollowCamera::setRumblePercentage(param_2,fVar4,(int)fVar4);
      }
    }
    uVar1 = *(uint *)(this + 0x18) + param_1;
    iVar5 = *(int *)(this + 0x1c) + (param_1 >> 0x1f) + (uint)CARRY4(*(uint *)(this + 0x18),param_1)
    ;
    *(uint *)(this + 0x18) = uVar1;
    *(int *)(this + 0x1c) = iVar5;
    iVar7 = *(int *)(this + 0x14);
    if (((int)((iVar7 - iVar5) - (uint)(*(uint *)(this + 0x10) < uVar1)) < 0 !=
         (SBORROW4(iVar7,iVar5) != SBORROW4(iVar7 - iVar5,(uint)(*(uint *)(this + 0x10) < uVar1))))
       && (fVar4 = (float)reset(this), param_2 != (TargetFollowCamera *)0x0)) {
      TargetFollowCamera::setRumblePercentage(param_2,fVar4,0);
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Explosion::update  @0x000b5950  (228 bytes)
/* Explosion::update(int, AbyssEngine::AEMath::Vector const&) */

void Explosion::update(int param_1,Vector *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  Vector *pVVar6;
  bool bVar7;
  longlong lVar8;
  
  if (*(char *)(param_1 + 0x20) != '\0') {
    lVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(param_1 + 4) + 0xc));
    bVar7 = SUB41(param_2,0);
    AbyssEngine::Transform::Update(lVar8,bVar7);
    uVar3 = *(uint *)(*(int *)(param_1 + 4) + 0x14);
    if (uVar3 != 0xffffffff) {
      lVar8 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar3);
      AbyssEngine::Transform::Update(lVar8,bVar7);
    }
    if (*(int *)(param_1 + 8) != 0) {
      uVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(param_1 + 8) + 0xc));
      AbyssEngine::Transform::Update((ulonglong)uVar3,bVar7);
    }
    puVar1 = *(uint **)(param_1 + 0xc);
    if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
      uVar3 = 0;
      do {
        pVVar6 = *(Vector **)(puVar1[1] + uVar3 * 4);
        AEGeometry::setPosition(pVVar6);
        uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(pVVar6 + 0xc));
        AbyssEngine::Transform::Update((ulonglong)uVar2,bVar7);
        puVar1 = *(uint **)(param_1 + 0xc);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *puVar1);
    }
    pVVar6 = param_2 + *(uint *)(param_1 + 0x18);
    iVar4 = *(int *)(param_1 + 0x1c) +
            ((int)param_2 >> 0x1f) + (uint)CARRY4(*(uint *)(param_1 + 0x18),(uint)param_2);
    *(Vector **)(param_1 + 0x18) = pVVar6;
    *(int *)(param_1 + 0x1c) = iVar4;
    iVar5 = *(int *)(param_1 + 0x14);
    bVar7 = *(Vector **)(param_1 + 0x10) < pVVar6;
    if ((int)((iVar5 - iVar4) - (uint)bVar7) < 0 !=
        (SBORROW4(iVar5,iVar4) != SBORROW4(iVar5 - iVar4,(uint)bVar7))) {
      reset((Explosion *)param_1);
      return;
    }
  }
  return;
}

// ===== Explosion::peakReached  @0x000b5a44  (22 bytes)
/* Explosion::peakReached() */

bool __thiscall Explosion::peakReached(Explosion *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x1c);
  return (int)(-(uint)(0x8fc < *(uint *)(this + 0x18)) - iVar1) < 0 !=
         (SBORROW4(0,iVar1) != SBORROW4(-iVar1,(uint)(0x8fc < *(uint *)(this + 0x18))));
}

// ===== Explosion::isPlaying  @0x000b5a5a  (6 bytes)
/* Explosion::isPlaying() */

Explosion __thiscall Explosion::isPlaying(Explosion *this)

{
  return this[0x20];
}

// ===== Explosion::render  @0x000b5a60  (408 bytes)
/* Explosion::render() */

void __thiscall Explosion::render(Explosion *this)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  undefined4 *puVar3;
  Matrix *pMVar4;
  uint *puVar5;
  AEGeometry *this_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar6;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar7;
  AEMath aAStack_c0 [12];
  AEMath aAStack_b4 [12];
  AEMath aAStack_a8 [60];
  Vector local_6c [8];
  float local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (this[0x20] != (Explosion)0x0) {
    if (((0xd < *(uint *)this) || ((1 << (*(uint *)this & 0xff) & 0x2780U) == 0)) &&
       (*(AEGeometry **)(this + 8) != (AEGeometry *)0x0)) {
      AEGeometry::render(*(AEGeometry **)(this + 8));
    }
    pPVar1 = Globals::Canvas;
    uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    puVar3 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar2);
    local_60 = *puVar3;
    uStack_5c = puVar3[1];
    uStack_58 = puVar3[2];
    uStack_54 = puVar3[3];
    uStack_50 = puVar3[4];
    local_4c = puVar3[5];
    uStack_48 = puVar3[6];
    uStack_44 = puVar3[7];
    uStack_40 = puVar3[8];
    uStack_3c = puVar3[9];
    local_38 = puVar3[10];
    uStack_34 = puVar3[0xb];
    uStack_30 = puVar3[0xc];
    uStack_2c = puVar3[0xd];
    uStack_28 = puVar3[0xe];
    AEGeometry::getPosition();
    if ((*(uint *)this < 0xd) && ((1 << (*(uint *)this & 0xff) & 0x1804U) != 0)) {
      AbyssEngine::AEMath::MatrixSetTranslation
                (aAStack_a8,(Matrix *)&local_60,local_64,extraout_s1,extraout_s2);
      fVar6 = extraout_s1_00;
      fVar7 = extraout_s2_00;
    }
    else {
      AbyssEngine::AEMath::MatrixGetPosition(aAStack_b4,(Matrix *)&local_60);
      AbyssEngine::AEMath::MatrixGetUp(aAStack_c0,(Matrix *)&local_60);
      AbyssEngine::AEMath::MatrixGetLookAt
                (aAStack_a8,(Vector *)aAStack_b4,local_6c,(Vector *)aAStack_c0);
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_60,aAStack_a8);
      fVar6 = extraout_s1_01;
      fVar7 = extraout_s2_01;
    }
    AbyssEngine::AEMath::MatrixSetScaling
              (aAStack_a8,(Matrix *)&local_60,*(float *)(this + 0x24),fVar6,fVar7);
    if (*(int *)this - 8U < 3) {
      AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_60,this + 0x2c);
    }
    AEGeometry::setMatrix(*(Matrix **)(this + 4));
    AEGeometry::setPosition(*(Vector **)(this + 4));
    pPVar1 = Globals::Canvas;
    uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar2);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_60,pMVar4);
    AbyssEngine::AEMath::MatrixGetDir(aAStack_a8,(Matrix *)&local_60);
    this_00 = *(AEGeometry **)(this + 4);
    AbyssEngine::AEMath::MatrixGetUp(aAStack_b4,(Matrix *)&local_60);
    AEGeometry::setDirection(this_00,(Vector *)aAStack_a8,(Vector *)aAStack_b4);
    AEGeometry::render(*(AEGeometry **)(this + 4));
    puVar5 = *(uint **)(this + 0xc);
    if ((puVar5 != (uint *)0x0) && (*puVar5 != 0)) {
      uVar2 = 0;
      do {
        AEGeometry::render(*(AEGeometry **)(puVar5[1] + uVar2 * 4));
        puVar5 = *(uint **)(this + 0xc);
        uVar2 = uVar2 + 1;
      } while (uVar2 < *puVar5);
    }
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Explosion::translate  @0x000b5c08  (30 bytes)
/* Explosion::translate(AbyssEngine::AEMath::Vector const&) */

void Explosion::translate(Vector *param_1)

{
  AEGeometry::translate(*(Vector **)(param_1 + 4));
  if (*(Vector **)(param_1 + 8) == (Vector *)0x0) {
    return;
  }
  AEGeometry::translate(*(Vector **)(param_1 + 8));
  return;
}

