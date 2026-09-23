// Class: TractorBeam
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== TractorBeam::TractorBeam  @0x0017c0f8  (68 bytes)
/* TractorBeam::TractorBeam(AEGeometry*, int) */

TractorBeam * __thiscall TractorBeam::TractorBeam(TractorBeam *this,AEGeometry *param_1,int param_2)

{
  AEGeometry *this_00;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined2 *)(this + 0x10) = 0;
  this_00 = operator_new(0xc0);
  AEGeometry::AEGeometry(this_00,(short)param_2 + 0x3798,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x14) = this_00;
  *(undefined4 *)(this + 0x18) = 0;
  return this;
}

// ===== TractorBeam::~TractorBeam  @0x0017c150  (26 bytes)
/* TractorBeam::~TractorBeam() */

TractorBeam * __thiscall TractorBeam::~TractorBeam(TractorBeam *this)

{
  void *pvVar1;
  
  if (*(AEGeometry **)(this + 0x14) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x14));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x14) = 0;
  return this;
}

// ===== TractorBeam::update  @0x0017c16c  (818 bytes)
/* TractorBeam::update(int, Radar*, Level*, Hud*) */

void __thiscall
TractorBeam::update(TractorBeam *this,int param_1,Radar *param_2,Level *param_3,Hud *param_4)

{
  byte bVar1;
  int iVar2;
  PlayerEgo *this_00;
  uint uVar3;
  float fVar4;
  Ship *pSVar5;
  undefined4 uVar6;
  int *piVar7;
  KIPlayer *this_01;
  code *pcVar8;
  Vector *pVVar9;
  AEGeometry *this_02;
  uint in_fpscr;
  float fVar10;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar11;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar12;
  Vector aVStack_70 [12];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  Vector aVStack_58 [12];
  Vector aVStack_4c [12];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar2 = *(int *)(this + 0xc);
  this_01 = *(KIPlayer **)(param_2 + 0x1c);
  if (this_01 != (KIPlayer *)0x0 || iVar2 != 0) {
    if (iVar2 == 0) {
      this_00 = (PlayerEgo *)Level::getPlayer(param_3);
      iVar2 = PlayerEgo::isInTurretMode(this_00);
      if (iVar2 != 0) {
        iVar2 = *(int *)(this + 0xc);
        if (iVar2 != 0) goto LAB_0017c1b4;
        goto LAB_0017c256;
      }
      iVar2 = KIPlayer::cargoAvailable(this_01);
      if (iVar2 == 0) {
        this[0x10] = (TractorBeam)0x0;
        *(undefined4 *)(param_2 + 0x1c) = 0;
      }
      else {
        if (*(int *)(this_01 + 0x74) == 0) {
          KIPlayer::createCrate(this_01,0);
        }
        *(KIPlayer **)(this + 0xc) = this_01;
        uVar6 = Player::getHitpoints(*(Player **)(this_01 + 4));
        *(undefined4 *)(this + 0x18) = uVar6;
        this[0x10] = (TractorBeam)0x1;
      }
    }
    else {
LAB_0017c1b4:
      if ((*(int *)(iVar2 + 0x74) == 0) ||
         ((*(char *)(iVar2 + 0x38) == '\0' &&
          (iVar2 = Player::isActive(*(Player **)(iVar2 + 4)), iVar2 == 0)))) {
LAB_0017c256:
        *(undefined4 *)(param_2 + 0x1c) = 0;
        *(undefined4 *)(param_2 + 8) = 0;
        this[0x11] = (TractorBeam)0x0;
        *(undefined4 *)(this + 0xc) = 0;
        this[0x10] = (TractorBeam)0x0;
        if (__stack_chk_guard == local_34) {
          FModSound::stop(Globals::sound,0);
          return;
        }
        goto LAB_0017c498;
      }
      uVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 0x14) + 0xc));
      AbyssEngine::Transform::Update((ulonglong)uVar3,SUB41(param_1,0));
      AEGeometry::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)this,(Vector *)&local_40);
      Level::getPlayer(param_3);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::Vector::operator-=((Vector *)this,(Vector *)&local_40);
      fVar4 = (float)AbyssEngine::AEMath::VectorLength((Vector *)this);
      pSVar5 = (Ship *)Status::getShip(Globals::status);
      iVar2 = Ship::getIndex(pSVar5);
      if (iVar2 == 0x2c) {
        Level::getPlayer(param_3);
        fVar10 = (float)PlayerEgo::GetDirVector();
        AbyssEngine::AEMath::operator*((AEMath *)&local_40,aVStack_4c,fVar10);
        fVar10 = extraout_s0;
        fVar11 = extraout_s1;
        fVar12 = extraout_s2;
      }
      else {
        pSVar5 = (Ship *)Status::getShip(Globals::status);
        iVar2 = Ship::getIndex(pSVar5);
        if (iVar2 == 0x31) {
          Level::getPlayer(param_3);
          fVar10 = (float)PlayerEgo::GetDirVector();
          AbyssEngine::AEMath::operator*((AEMath *)aVStack_4c,aVStack_58,fVar10);
          Level::getPlayer(param_3);
          fVar10 = (float)PlayerEgo::GetUpVector();
          AbyssEngine::AEMath::operator*((AEMath *)&local_64,aVStack_70,fVar10);
          AbyssEngine::AEMath::operator+((AEMath *)&local_40,aVStack_4c,(Vector *)&local_64);
          fVar10 = extraout_s0_01;
          fVar11 = extraout_s1_01;
          fVar12 = extraout_s2_01;
        }
        else {
          local_40 = 0;
          uStack_3c = 0;
          local_38 = 0;
          fVar10 = extraout_s0_00;
          fVar11 = extraout_s1_00;
          fVar12 = extraout_s2_00;
        }
      }
      AEGeometry::setScaling(*(AEGeometry **)(this + 0x14),fVar10,fVar11,fVar12);
      this_02 = *(AEGeometry **)(this + 0x14);
      AbyssEngine::AEMath::operator-((AEMath *)aVStack_58,(Vector *)this,(Vector *)&local_40);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)aVStack_4c,aVStack_58);
      local_64 = 0;
      local_60 = 0x3f800000;
      uStack_5c = 0;
      AEGeometry::setDirection(this_02,aVStack_4c,(Vector *)&local_64);
      pVVar9 = *(Vector **)(this + 0x14);
      Level::getPlayer(param_3);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::operator+((AEMath *)aVStack_4c,aVStack_58,(Vector *)&local_40);
      AEGeometry::setPosition(pVVar9);
      uVar3 = in_fpscr & 0xfffffff | (uint)(fVar4 == 400.0) << 0x1e | (uint)(400.0 <= fVar4) << 0x1d
      ;
      bVar1 = (byte)(uVar3 >> 0x18);
      if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
        KIPlayer::captureCrate(*(KIPlayer **)(this + 0xc),param_4);
        this[0x10] = (TractorBeam)0x0;
        *(undefined4 *)(this + 0xc) = 0;
        *(undefined4 *)(param_2 + 0x1c) = 0;
        *(undefined4 *)(param_2 + 8) = 0;
        this[0x11] = (TractorBeam)0x0;
        fVar4 = (float)FModSound::stop(Globals::sound,0);
        FModSound::play(Globals::sound,4,(Vector *)0x0,(Vector *)0x0,fVar4);
      }
      else {
        *(undefined4 *)(param_2 + 0x1c) = 0;
        AbyssEngine::AEMath::VectorNormalize((AEMath *)aVStack_4c,(Vector *)this);
        AbyssEngine::AEMath::Vector::operator=((Vector *)this,aVStack_4c);
        fVar4 = (float)VectorSignedToFloat(param_1 * 10,(byte)(uVar3 >> 0x16) & 3);
        AbyssEngine::AEMath::Vector::operator*=((Vector *)this,fVar4);
        pVVar9 = *(Vector **)(*(int *)(this + 0xc) + 0x74);
        AbyssEngine::AEMath::operator-((AEMath *)aVStack_4c,(Vector *)this);
        AEGeometry::translate(pVVar9);
        iVar2 = KIPlayer::isDead(*(KIPlayer **)(this + 0xc));
        fVar4 = extraout_s0_02;
        if ((iVar2 != 0) ||
           (iVar2 = KIPlayer::isDying(*(KIPlayer **)(this + 0xc)), fVar4 = extraout_s0_03,
           iVar2 == 1)) {
          piVar7 = *(int **)(this + 0xc);
          if (((*(ushort *)(piVar7 + 0xf) & 0xff) == 0) && (*(ushort *)(piVar7 + 0xf) < 0x100)) {
            pcVar8 = *(code **)(*piVar7 + 0x20);
            AbyssEngine::AEMath::operator-((AEMath *)aVStack_4c,(Vector *)this);
            fVar4 = (float)(*pcVar8)(piVar7,(AEMath *)aVStack_4c);
          }
        }
        if (this[0x11] == (TractorBeam)0x0) {
          FModSound::play(Globals::sound,0,(Vector *)0x0,(Vector *)0x0,fVar4);
          this[0x11] = (TractorBeam)0x1;
        }
      }
    }
  }
  if (__stack_chk_guard == local_34) {
    return;
  }
LAB_0017c498:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== TractorBeam::render  @0x0017c4c4  (12 bytes)
/* TractorBeam::render() */

void __thiscall TractorBeam::render(TractorBeam *this)

{
  if (this[0x10] == (TractorBeam)0x0) {
    return;
  }
  AEGeometry::render(*(AEGeometry **)(this + 0x14));
  return;
}

