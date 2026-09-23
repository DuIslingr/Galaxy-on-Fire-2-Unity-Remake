// Class: MineGun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MineGun::MineGun  @0x00181a28  (274 bytes)
/* MineGun::MineGun(Gun*, int, int, int, Level*) */

MineGun * __thiscall
MineGun::MineGun(MineGun *this,Gun *param_1,int param_2,int param_3,int param_4,Level *param_5)

{
  Array *pAVar1;
  undefined4 *puVar2;
  void *pvVar3;
  Explosion *this_00;
  AEGeometry *this_01;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  
  ObjectGun::ObjectGun((ObjectGun *)this,param_3,param_1,param_2,0,param_5);
  *(undefined ***)this = &PTR__MineGun_00264580;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 200) = 0;
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  *(Array **)(this + 0xb4) = pAVar1;
  ArraySetLength<Explosion*>(*(uint *)(param_1 + 8),pAVar1);
  puVar6 = *(uint **)(this + 0xb4);
  pvVar3 = operator_new__(*puVar6);
  *(void **)(this + 0xb8) = pvVar3;
  if (*puVar6 != 0) {
    uVar7 = 0;
    do {
      this_00 = operator_new(0x68);
      iVar5 = 0;
      if (*(int *)(param_1 + 0x60) == 0) {
        iVar5 = 7;
      }
      Explosion::Explosion(this_00,iVar5);
      *(Explosion **)(*(int *)(*(int *)(this + 0xb4) + 4) + uVar7 * 4) = this_00;
      Explosion::setWeaponIndex
                (*(Explosion **)(*(int *)(*(int *)(this + 0xb4) + 4) + uVar7 * 4),
                 *(int *)(param_1 + 0x58));
      *(undefined1 *)(*(int *)(this + 0xb8) + uVar7) = 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < **(uint **)(this + 0xb4));
  }
  this_01 = operator_new(0xc0);
  AEGeometry::AEGeometry(this_01,(short)param_2 + 1,Globals::Canvas,false);
  *(AEGeometry **)(this + 0xbc) = this_01;
  AbyssEngine::PaintCanvas::TransformAddChild
            (Globals::Canvas,*(uint *)(this + 0x10),*(uint *)(this_01 + 0xc));
  uVar4 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar4,2,0);
  return this;
}

// ===== MineGun::~MineGun  @0x00181b9c  (96 bytes)
/* MineGun::~MineGun() */

void __thiscall MineGun::~MineGun(MineGun *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__MineGun_00264580;
  if (*(Array **)(this + 0xb4) != (Array *)0x0) {
    ArrayReleaseClasses<Explosion*>(*(Array **)(this + 0xb4));
    pvVar1 = *(void **)(this + 0xb4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0xb4) = 0;
  }
  if (*(void **)(this + 0xb8) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xb8));
  }
  *(undefined4 *)(this + 0xb8) = 0;
  if (*(AEGeometry **)(this + 0xbc) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xbc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xbc) = 0;
  ObjectGun::~ObjectGun((ObjectGun *)this);
  return;
}

// ===== MineGun::~MineGun  @0x00181c42  (16 bytes)
/* MineGun::~MineGun() */

void __thiscall MineGun::~MineGun(MineGun *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~MineGun(this);
  operator_delete(pvVar1);
  return;
}

// ===== MineGun::setPlayer  @0x00181c52  (6 bytes)
/* MineGun::setPlayer(PlayerEgo*) */

void __thiscall MineGun::setPlayer(MineGun *this,PlayerEgo *param_1)

{
  *(PlayerEgo **)(this + 0xb0) = param_1;
  return;
}

// ===== MineGun::render  @0x00181c58  (50 bytes)
/* MineGun::render() */

void __thiscall MineGun::render(MineGun *this)

{
  int iVar1;
  uint uVar2;
  
  ObjectGun::render((ObjectGun *)this);
  iVar1 = *(int *)(this + 8);
  if (*(int *)(iVar1 + 8) != 0) {
    uVar2 = 0;
    do {
      if (*(char *)(*(int *)(iVar1 + 0x40) + uVar2) != '\0') {
        Explosion::render(*(Explosion **)(*(int *)(*(int *)(this + 0xb4) + 4) + uVar2 * 4));
        iVar1 = *(int *)(this + 8);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(iVar1 + 8));
  }
  return;
}

// ===== MineGun::update  @0x00181c8c  (462 bytes)
/* MineGun::update(int) */

void __thiscall MineGun::update(MineGun *this,int param_1)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  TargetFollowCamera *pTVar4;
  int iVar5;
  uint in_fpscr;
  float extraout_s0;
  float fVar6;
  float extraout_s0_00;
  Vector aVStack_5c [12];
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  ObjectGun::update((ObjectGun *)this,param_1);
  iVar1 = *(int *)(this + 8);
  if (*(char *)(iVar1 + 0x4c) != '\0') {
    uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
    AbyssEngine::Transform::Update((ulonglong)uVar2,SUB41(param_1,0));
    iVar1 = *(int *)(this + 8);
  }
  if (*(int *)(iVar1 + 8) != 0) {
    iVar5 = 0;
    uVar2 = 0;
    do {
      if (*(char *)(*(int *)(iVar1 + 0x40) + uVar2) != '\0') {
        if (*(char *)(*(int *)(this + 0xb8) + uVar2) != '\0') {
          *(undefined4 *)(this + 0xcc) = 0;
          iVar1 = *(int *)(iVar1 + 0x30);
          PlayerEgo::getPosition();
          AbyssEngine::AEMath::operator-((AEMath *)&local_50,(Vector *)(iVar1 + iVar5),aVStack_5c);
          fVar3 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_50);
          in_fpscr = in_fpscr & 0xfffffff;
          fVar6 = 30000.0;
          if (fVar3 < 30000.0) {
            fVar6 = fVar3;
          }
          *(float *)(this + 0xd0) = 1.0 - fVar6 / 30000.0;
          pTVar4 = (TargetFollowCamera *)
                   PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xb0));
          TargetFollowCamera::setRumblePercentage(pTVar4,extraout_s0,*(int *)(this + 0xd0));
          local_50 = 0;
          uStack_4c = 0;
          local_48 = 0;
          Explosion::start(*(Explosion **)(*(int *)(*(int *)(this + 0xb4) + 4) + uVar2 * 4),
                           (Vector *)(*(int *)(*(int *)(this + 8) + 0x30) + iVar5),
                           (Vector *)&local_50);
          *(undefined1 *)(*(int *)(this + 0xb8) + uVar2) = 0;
        }
        Explosion::update(*(Explosion **)(*(int *)(*(int *)(this + 0xb4) + 4) + uVar2 * 4),param_1,
                          (TargetFollowCamera *)0x0);
        iVar1 = *(int *)(this + 0xcc) + param_1;
        if (2000 < iVar1) {
          iVar1 = 2000;
        }
        *(int *)(this + 0xcc) = iVar1;
        pTVar4 = (TargetFollowCamera *)
                 PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xb0));
        fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xcc),(byte)(in_fpscr >> 0x16) & 3
                                          );
        fVar6 = *(float *)(this + 0xd0) * (fVar6 / -2000.0 + 1.0);
        TargetFollowCamera::setRumblePercentage(pTVar4,fVar6,(int)fVar6);
        iVar1 = Explosion::isPlaying
                          (*(Explosion **)(*(int *)(*(int *)(this + 0xb4) + 4) + uVar2 * 4));
        if (iVar1 == 0) {
          pTVar4 = (TargetFollowCamera *)
                   PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xb0));
          TargetFollowCamera::setRumblePercentage(pTVar4,extraout_s0_00,0);
          *(undefined4 *)(this + 0xcc) = 0;
          iVar1 = *(int *)(this + 8);
          *(undefined1 *)(*(int *)(iVar1 + 0x40) + uVar2) = 0;
          *(undefined1 *)(iVar1 + 0x88) = 0;
          *(undefined1 *)(*(int *)(this + 0xb8) + uVar2) = 1;
          Explosion::reset(*(Explosion **)(*(int *)(*(int *)(this + 0xb4) + 4) + uVar2 * 4));
        }
      }
      iVar1 = *(int *)(this + 8);
      iVar5 = iVar5 + 0xc;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(iVar1 + 8));
  }
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MineGun::isMineGun  @0x00181e78  (4 bytes)
/* MineGun::isMineGun() */

undefined4 MineGun::isMineGun(void)

{
  return 1;
}

