// Class: BombGun
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== BombGun::BombGun  @0x00170e74  (584 bytes)
/* BombGun::BombGun(Gun*, unsigned int, int, int, bool, Level*) */

void __thiscall
BombGun::BombGun(BombGun *this,Gun *param_1,uint param_2,int param_3,int param_4,bool param_5,
                Level *param_6)

{
  Explosion *this_00;
  undefined4 uVar1;
  AEGeometry *pAVar2;
  void *pvVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  BombGun *pBVar7;
  bool bVar8;
  float fVar9;
  undefined3 in_stack_00000005;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  RocketGun::RocketGun((RocketGun *)this,param_3,param_1,param_2,0,0,param_4,false,param_6);
  *(undefined ***)this = &PTR__BombGun_002643a4;
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined4 *)(this + 0xfc) = 0;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x114) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x118) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x11c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  this_00 = operator_new(0x68);
  if (param_4 == 6) {
    iVar5 = 7;
  }
  else if (param_4 == 0x2a) {
    iVar5 = 0xb;
  }
  else {
    iVar5 = 0;
    if (*(int *)(param_1 + 0x58) == 0xe8) {
      iVar5 = 0xd;
    }
  }
  Explosion::Explosion(this_00,iVar5);
  *(Explosion **)(this + 0xf0) = this_00;
  fVar9 = (float)Explosion::setWeaponIndex(this_00,*(int *)(param_1 + 0x58));
  this[0x104] = (BombGun)0x1;
  this[0x24] = (BombGun)param_5;
  *(int *)(this + 0x128) = param_4;
  *(undefined4 *)(this + 0xf4) = 0xffffffff;
  if (param_4 == 0x2a) {
    Explosion::setScaling(fVar9);
  }
  if (_param_5 == 1) {
    pBVar7 = this + 0x14;
    AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)pBVar7);
    AbyssEngine::PaintCanvas::TransformAddMesh
              (Globals::Canvas,*(uint *)(this + 0x14),*(ushort *)(this + 0x28),false);
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)pBVar7);
    AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
    pAVar2 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar2,0x37d6,Globals::Canvas,false);
    AbyssEngine::PaintCanvas::TransformAddChild
              (Globals::Canvas,*(uint *)pBVar7,*(uint *)(pAVar2 + 0xc));
    AbyssEngine::PaintCanvas::TransformRemoveMesh
              (Globals::Canvas,*(uint *)(this + 0x10),*(ushort *)(this + 0x28));
    AbyssEngine::PaintCanvas::TransformAddChild
              (Globals::Canvas,*(uint *)(this + 0x10),*(uint *)(this + 0x14));
  }
  else {
    iVar5 = *(int *)(param_1 + 0x58);
    bVar8 = iVar5 == 0xe8;
    if (!bVar8) {
      iVar5 = *(int *)(param_1 + 0x5c);
    }
    if (bVar8 || iVar5 == 0x22) goto LAB_0017104e;
    pAVar2 = operator_new(0xc0);
    uVar4 = 0x395d;
    if (param_2 == 0x395a) {
      uVar4 = 0x395b;
    }
    if (param_2 == 0x3958) {
      uVar4 = 0x3959;
    }
    AEGeometry::AEGeometry(pAVar2,uVar4,Globals::Canvas,false);
    uVar6 = *(uint *)(pAVar2 + 0xc);
    *(uint *)(this + 0xf4) = uVar6;
    AbyssEngine::PaintCanvas::TransformAddChild(Globals::Canvas,*(uint *)(this + 0x10),uVar6);
    if (param_2 == 0x395c) {
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0xf4));
      AbyssEngine::Transform::SetAnimationState(uVar1,2,0);
    }
    else {
      uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x10));
      AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
    }
  }
  pvVar3 = (void *)AEGeometry::~AEGeometry(pAVar2);
  operator_delete(pvVar3);
LAB_0017104e:
  local_30 = 0;
  local_2c = 0x43e10000;
  local_28 = 0xc4af0000;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x110),(Vector *)&local_30);
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x44d48000;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x11c),(Vector *)&local_30);
  *(undefined4 *)(this + 0xec) = 0;
  pAVar2 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar2,Globals::Canvas);
  *(AEGeometry **)(this + 0xe8) = pAVar2;
  if (__stack_chk_guard - local_24 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_24);
}

// ===== BombGun::~BombGun  @0x00171120  (48 bytes)
/* BombGun::~BombGun() */

void __thiscall BombGun::~BombGun(BombGun *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__BombGun_002643a4;
  if (*(Explosion **)(this + 0xf0) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0xf0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xf0) = 0;
  RocketGun::~RocketGun((RocketGun *)this);
  return;
}

// ===== BombGun::~BombGun  @0x00171154  (16 bytes)
/* BombGun::~BombGun() */

void __thiscall BombGun::~BombGun(BombGun *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~BombGun(this);
  operator_delete(pvVar1);
  return;
}

// ===== BombGun::setPlayer  @0x00171164  (6 bytes)
/* BombGun::setPlayer(PlayerEgo*) */

void __thiscall BombGun::setPlayer(BombGun *this,PlayerEgo *param_1)

{
  *(PlayerEgo **)(this + 0xec) = param_1;
  return;
}

// ===== BombGun::update  @0x0017116c  (1110 bytes)
/* BombGun::update(int) */

void __thiscall BombGun::update(BombGun *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  undefined8 *puVar3;
  int iVar4;
  TargetFollowCamera *pTVar5;
  float fVar6;
  undefined4 uVar7;
  bool bVar8;
  Matrix *pMVar9;
  Vector *pVVar10;
  Explosion *this_00;
  Vector *pVVar11;
  uint in_fpscr;
  uint uVar12;
  float fVar13;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float fVar14;
  longlong lVar15;
  AEMath aAStack_5c [12];
  undefined8 local_50;
  undefined4 local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  if (*(int *)(this + 0xec) == 0) goto LAB_001715a4;
  if (*(char *)(*(int *)(this + 8) + 0x88) == '\0') {
    if (*(int *)(this + 0x128) == 0x2a) {
      PlayerEgo::getPosition();
    }
    else {
      puVar3 = *(undefined8 **)(*(int *)(this + 8) + 0xc);
      local_50 = *puVar3;
      local_48 = *(undefined4 *)(puVar3 + 1);
    }
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xf8),(Vector *)&local_50);
  }
  iVar4 = *(int *)(this + 8);
  bVar8 = SUB41(param_1,0);
  if (this[0x24] == (BombGun)0x0) {
    if (*(char *)(iVar4 + 0x4c) != '\0') {
LAB_001711f4:
      lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(this + 0x10));
      AbyssEngine::Transform::Update(lVar15,bVar8);
      if (*(uint *)(this + 0xf4) != 0xffffffff) {
        lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(this + 0xf4));
        AbyssEngine::Transform::Update(lVar15,bVar8);
      }
    }
  }
  else if ((*(ushort *)(iVar4 + 0x4c) & 0xff) != 0) {
    if (*(char *)(iVar4 + 0x88) != '\0') goto LAB_001711f4;
    if (0xff < *(ushort *)(iVar4 + 0x4c)) {
      *(undefined1 *)(iVar4 + 0x4d) = 0;
      uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x10));
      AbyssEngine::Transform::SetAnimationState(uVar7,3,0);
      uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x10));
      AbyssEngine::Transform::SetAnimationState(uVar7,1,0);
      fVar13 = (float)AbyssEngine::AEMath::Matrix::operator=
                                ((Matrix *)(*(int **)(this + 0xec) + 0x10),
                                 (Matrix *)(**(int **)(this + 0xec) + 4));
      FModSound::play(Globals::sound,0x45c,(Vector *)0x0,(Vector *)0x0,fVar13);
    }
    pMVar9 = *(Matrix **)(this + 0xe8);
    AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(this + 0x10));
    fVar13 = (float)AEGeometry::setMatrix(pMVar9);
    pVVar11 = *(Vector **)(this + 0xe8);
    pVVar10 = *(Vector **)(*(int *)(this + 8) + 0xc);
    AbyssEngine::AEMath::operator*(aAStack_5c,fVar13,(Vector *)0x43af0000);
    AbyssEngine::AEMath::operator+((AEMath *)&local_50,pVVar10,(Vector *)aAStack_5c);
    AEGeometry::setPosition(pVVar11);
    AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this + 0xe8));
    pTVar5 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xec));
    TargetFollowCamera::setTarget(pTVar5,*(AEGeometry **)(this + 0xe8));
    pTVar5 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xec));
    TargetFollowCamera::setCamOffset(pTVar5,(Vector *)(this + 0x110));
    pTVar5 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xec));
    TargetFollowCamera::setTargetOffset(pTVar5,(Vector *)(this + 0x11c));
    pTVar5 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xec));
    TargetFollowCamera::useTargetsUpVector(pTVar5,false);
    PlayerEgo::setRocketControl
              (*(PlayerEgo **)(this + 0xec),*(Gun **)(this + 8),*(AEGeometry **)(this + 0xe8));
    if (**(int **)(*(int *)(this + 8) + 0x3c) < *(int *)(*(int *)(this + 8) + 0x44) + -500) {
      lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(this + 0x10));
      AbyssEngine::Transform::Update(lVar15,bVar8);
    }
    fVar13 = (float)PlayerEgo::getRocketBanking(*(PlayerEgo **)(this + 0xec));
    *(float *)(this + 0x20) = fVar13 * 0.2;
    FModSound::setParamValue((int)Globals::sound,0,fVar13 * 0.2);
  }
  RocketGun::update((RocketGun *)this,param_1);
  if (*(char *)(*(int *)(this + 8) + 0x88) != '\0') {
    if (this[0x104] != (BombGun)0x0) {
      if (this[0x24] != (BombGun)0x0) {
        LevelScript::resetCamera
                  (*(LevelScript **)(*(int *)(this + 0xec) + 0x10),
                   *(Level **)(*(int *)(this + 0xec) + 0xc));
        PlayerEgo::setRocketControl
                  (*(PlayerEgo **)(this + 0xec),(Gun *)0x0,*(AEGeometry **)(this + 0xe8));
        FModSound::stop(Globals::sound,0x45c);
      }
      *(undefined4 *)(this + 0x108) = 0;
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::operator-
                ((AEMath *)&local_50,(Vector *)(this + 0xf8),(Vector *)aAStack_5c);
      fVar6 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_50);
      uVar7 = Gun::getMagnitude(*(Gun **)(this + 8));
      fVar14 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      uVar7 = Gun::getMagnitude(*(Gun **)(this + 8));
      fVar13 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      fVar14 = ((fVar14 * 0.5 - fVar6) / (fVar13 * 0.5)) * 0.5;
      in_fpscr = in_fpscr & 0xfffffff;
      uVar1 = in_fpscr | (uint)(fVar14 < 1.0) << 0x1f | (uint)(fVar14 == 1.0) << 0x1e;
      uVar12 = uVar1 | (uint)NAN(fVar14) << 0x1c;
      bVar2 = (byte)(uVar1 >> 0x18);
      fVar13 = 1.0;
      if (((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar12 >> 0x1c) & 1)) &&
         (uVar12 = in_fpscr, fVar13 = fVar14, fVar14 < 0.0)) {
        fVar13 = 0.0;
      }
      if (*(int *)(this + 0x128) == 0x2a) {
        fVar13 = fVar13 * 0.2;
      }
      iVar4 = Status::hardCoreMode();
      fVar14 = extraout_s0;
      if (iVar4 == 1) {
        fVar14 = (float)VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 8) + 0x60),
                                            (byte)(uVar12 >> 0x16) & 3);
        fVar14 = (float)Player::damage((Player *)**(undefined4 **)(this + 0xec),
                                       (int)(fVar13 * fVar14),false,-1);
      }
      PlayerEgo::addNukeVolatileForce(*(PlayerEgo **)(this + 0xec),fVar14);
      in_fpscr = uVar12 & 0xfffffff;
      fVar13 = 30000.0;
      if (fVar6 < 30000.0) {
        fVar13 = fVar6;
      }
      *(float *)(this + 0x10c) = 1.0 - fVar13 / 30000.0;
      pTVar5 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xec));
      TargetFollowCamera::setRumblePercentage(pTVar5,extraout_s0_00,*(int *)(this + 0x10c));
      this_00 = *(Explosion **)(this + 0xf0);
      if (*(int *)(this + 0x128) == 0x2a) {
        PlayerEgo::GetDirVector();
      }
      else {
        local_50 = 0;
        local_48 = 0;
      }
      Explosion::start(this_00,(Vector *)(this + 0xf8),(Vector *)&local_50);
      this[0x104] = (BombGun)0x0;
    }
    Explosion::update(*(Explosion **)(this + 0xf0),param_1,(TargetFollowCamera *)0x0);
    iVar4 = *(int *)(this + 0x108) + param_1;
    if (2000 < iVar4) {
      iVar4 = 2000;
    }
    *(int *)(this + 0x108) = iVar4;
    pTVar5 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xec));
    fVar13 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x108),(byte)(in_fpscr >> 0x16) & 3);
    fVar13 = *(float *)(this + 0x10c) * (fVar13 / -2000.0 + 1.0);
    TargetFollowCamera::setRumblePercentage(pTVar5,fVar13,(int)fVar13);
    iVar4 = Explosion::isPlaying(*(Explosion **)(this + 0xf0));
    if (iVar4 == 0) {
      pTVar5 = (TargetFollowCamera *)PlayerEgo::getTargetFollowCamera(*(PlayerEgo **)(this + 0xec));
      TargetFollowCamera::setRumblePercentage(pTVar5,extraout_s0_01,0);
      *(undefined4 *)(this + 0x108) = 0;
      *(undefined1 *)(*(int *)(this + 8) + 0x88) = 0;
      this[0x104] = (BombGun)0x1;
      Explosion::reset(*(Explosion **)(this + 0xf0));
    }
  }
LAB_001715a4:
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== BombGun::render  @0x00171600  (32 bytes)
/* BombGun::render() */

void __thiscall BombGun::render(BombGun *this)

{
  RocketGun::render();
  if (*(char *)(*(int *)(this + 8) + 0x88) == '\0') {
    return;
  }
  Explosion::render(*(Explosion **)(this + 0xf0));
  return;
}

// ===== BombGun::isBombGun  @0x00171624  (4 bytes)
/* BombGun::isBombGun() */

undefined4 BombGun::isBombGun(void)

{
  return 1;
}

