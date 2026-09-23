// Class: PlayerStation
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerStation::PlayerStation  @0x00146cf0  (3646 bytes)
/* PlayerStation::PlayerStation(Station*) */

void __thiscall PlayerStation::PlayerStation(PlayerStation *this,Station *param_1)

{
  int iVar1;
  FileRead *pFVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  AEGeometry *pAVar6;
  undefined4 uVar7;
  SolarSystem *this_00;
  uint uVar8;
  Station *this_01;
  AEGeometry *pAVar9;
  AEGeometry *pAVar10;
  Array *pAVar11;
  undefined4 *puVar12;
  int iVar13;
  BoundingSphere *this_02;
  BoundingAAB *this_03;
  AEGeometry *this_04;
  ushort uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint in_fpscr;
  float in_s0;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
  float extraout_s0_07;
  float extraout_s0_08;
  float extraout_s0_09;
  float extraout_s0_10;
  float fVar19;
  float extraout_s0_11;
  float extraout_s0_12;
  float extraout_s0_13;
  float extraout_s0_14;
  float in_s1;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s1_07;
  float extraout_s1_08;
  float extraout_s1_09;
  float extraout_s1_10;
  float fVar20;
  float extraout_s1_11;
  float extraout_s1_12;
  float extraout_s1_13;
  float extraout_s1_14;
  float extraout_s1_15;
  float extraout_s1_16;
  float in_s2;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  float extraout_s2_07;
  float extraout_s2_08;
  float extraout_s2_09;
  float extraout_s2_10;
  float fVar21;
  float extraout_s2_11;
  float extraout_s2_12;
  float extraout_s2_13;
  float extraout_s2_14;
  float extraout_s2_15;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s4;
  float extraout_s5;
  float extraout_s5_00;
  float extraout_s6;
  float extraout_s6_00;
  float extraout_s7;
  float extraout_s8;
  undefined8 uVar22;
  float local_64;
  float local_60;
  float local_5c;
  uint local_58;
  uint local_54;
  ushort uStack_4e;
  uint local_4c;
  uint local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  PlayerStaticFar::PlayerStaticFar((PlayerStaticFar *)this,-1,(AEGeometry *)0x0,in_s0,in_s1,in_s2);
  *(undefined ***)this = &PTR__PlayerStation_00264330;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x15c) = 0;
  Player::setRadius(*(Player **)(this + 4),15000);
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  this[0x21] = (PlayerStation)0x0;
  Player::setMaxHitpoints(*(Player **)(this + 4),9999999);
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  iVar1 = Station::getIndex(param_1);
  *(int *)(this + 0x144) = iVar1;
  pFVar2 = operator_new(1);
  FileRead::FileRead(pFVar2);
  pvVar3 = (void *)FileRead::loadStationCollision(pFVar2,iVar1);
  pvVar4 = (void *)FileRead::~FileRead(pFVar2);
  operator_delete(pvVar4);
  iVar5 = Status::inAlienOrbit(Globals::status);
  fVar19 = extraout_s0;
  fVar20 = extraout_s1;
  fVar21 = extraout_s2;
  if ((1 < iVar1 - 0x6dU) && (pvVar3 == (void *)0x0)) {
    if (iVar5 == 1) {
      iVar1 = Status::dlc1Won(Globals::status);
      if (iVar1 == 1) {
        pAVar6 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar6,0x4220,Globals::Canvas,false);
        *(AEGeometry **)(this + 0x13c) = pAVar6;
        local_64 = -NAN;
        AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)&local_64);
        AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,(uint)local_64,0x4221,false);
        AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),(uint)local_64);
        local_54 = 0xffffffff;
        AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_54);
        AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_54,0x4222,false);
        AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),local_54);
        pFVar2 = operator_new(1);
        FileRead::FileRead(pFVar2);
        pvVar3 = (void *)FileRead::loadStationCollision(pFVar2,0x3eb);
        pvVar4 = (void *)FileRead::~FileRead(pFVar2);
        operator_delete(pvVar4);
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
        uVar22 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
        AbyssEngine::Transform::Update
                  (CONCAT44((int)((ulonglong)uVar22 >> 0x20),uVar7),
                   SUB41(*(undefined4 *)((int)uVar22 + 0xf8),0));
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0x14));
        uVar22 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0x14));
        AbyssEngine::Transform::Update
                  (CONCAT44((int)((ulonglong)uVar22 >> 0x20),uVar7),
                   SUB41(*(undefined4 *)((int)uVar22 + 0xf8),0));
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0x10));
        uVar22 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0x10));
        AbyssEngine::Transform::Update
                  (CONCAT44((int)((ulonglong)uVar22 >> 0x20),uVar7),
                   SUB41(*(undefined4 *)((int)uVar22 + 0xf8),0));
        fVar19 = extraout_s0_00;
        fVar20 = extraout_s1_00;
        fVar21 = extraout_s2_00;
        goto LAB_00147086;
      }
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x403b,Globals::Canvas,false);
      *(AEGeometry **)(this + 0x13c) = pAVar6;
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x403e,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar6 + 0xc));
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x4041,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar6);
      operator_delete(pvVar4);
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar9);
      operator_delete(pvVar4);
      pFVar2 = operator_new(1);
      FileRead::FileRead(pFVar2);
      pvVar3 = (void *)FileRead::loadStationCollision(pFVar2,0x3e9);
    }
    else {
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x4034,Globals::Canvas,false);
      *(AEGeometry **)(this + 0x13c) = pAVar6;
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x4037,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar6 + 0xc));
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x403a,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar6);
      operator_delete(pvVar4);
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar9);
      operator_delete(pvVar4);
      pFVar2 = operator_new(1);
      FileRead::FileRead(pFVar2);
      pvVar3 = (void *)FileRead::loadStationCollision(pFVar2,1000);
    }
    pvVar4 = (void *)FileRead::~FileRead(pFVar2);
    operator_delete(pvVar4);
    fVar19 = extraout_s0_01;
    fVar20 = extraout_s1_01;
    fVar21 = extraout_s2_01;
  }
LAB_00147086:
  if (*(int *)(this + 0x13c) != 0) goto LAB_00147526;
  iVar1 = *(int *)(this + 0x144);
  if (iVar1 - 0x6dU < 3) {
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,0x5254,Globals::Canvas,false);
  }
  else {
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,(short)iVar1 + 21000,Globals::Canvas,false);
  }
  *(AEGeometry **)(this + 0x13c) = pAVar6;
  iVar1 = Status::getSystem(Globals::status);
  if (iVar1 == 0) {
    uVar8 = 9;
    fVar19 = extraout_s0_02;
    fVar20 = extraout_s1_02;
    fVar21 = extraout_s2_02;
  }
  else {
    this_00 = (SolarSystem *)Status::getSystem(Globals::status);
    uVar8 = SolarSystem::getRace(this_00);
    fVar19 = extraout_s0_03;
    fVar20 = extraout_s1_03;
    fVar21 = extraout_s2_03;
  }
  iVar1 = *(int *)(this + 0x144);
  if (iVar1 == 0x6f) {
    iVar1 = Status::getCurrentCampaignMission(Globals::status);
    if (0x5d < iVar1) {
      iVar1 = *(int *)(this + 0x144);
      fVar19 = extraout_s0_05;
      fVar20 = extraout_s1_05;
      fVar21 = extraout_s2_05;
      goto LAB_0014740c;
    }
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,0x5254,Globals::Canvas,false);
    *(AEGeometry **)(this + 0x13c) = pAVar6;
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,0x5574,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar6 + 0xc));
    pAVar9 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar9,0x563c,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
    pAVar10 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar10,0x495d,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar10 + 0xc));
    this_04 = operator_new(0xc0);
    AEGeometry::AEGeometry(this_04,0x495e,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(this_04 + 0xc));
    pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar6);
    operator_delete(pvVar4);
    pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar9);
    operator_delete(pvVar4);
    pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar10);
    operator_delete(pvVar4);
  }
  else {
    if (iVar1 == 0x65) {
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x4220,Globals::Canvas,false);
      *(AEGeometry **)(this + 0x13c) = pAVar6;
      local_64 = -NAN;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)&local_64);
      AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,(uint)local_64,0x4221,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),(uint)local_64);
      local_54 = 0xffffffff;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_54);
      AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_54,0x4222,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),local_54);
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar1 == 0x9d) {
        this_01 = (Station *)Status::getStation(Globals::status);
        iVar1 = Station::getIndex(this_01);
        if (iVar1 == 0x70) {
          local_58 = 0xffffffff;
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_58);
          AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_58,0x4950,false);
          AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),local_58);
          local_48 = 0xffffffff;
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_48);
          AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_48,0x4952,false);
          AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),local_48);
          local_4c = 0xffffffff;
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_4c);
          AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_4c,0x4951,false);
          AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),local_4c);
          uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                            (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
          uVar22 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
          AbyssEngine::Transform::Update
                    (CONCAT44((int)((ulonglong)uVar22 >> 0x20),uVar7),
                     SUB41(*(undefined4 *)((int)uVar22 + 0xf8),0));
          fVar19 = extraout_s0_04;
          fVar20 = extraout_s1_04;
          fVar21 = extraout_s2_04;
          goto LAB_00147526;
        }
      }
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      fVar19 = extraout_s0_07;
      fVar20 = extraout_s1_07;
      fVar21 = extraout_s2_07;
      if (0x4f < iVar1) {
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
        uVar22 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
        AbyssEngine::Transform::Update
                  (CONCAT44((int)((ulonglong)uVar22 >> 0x20),uVar7),
                   SUB41(*(undefined4 *)((int)uVar22 + 0xf8),0));
        fVar19 = extraout_s0_08;
        fVar20 = extraout_s1_08;
        fVar21 = extraout_s2_08;
      }
      goto LAB_00147526;
    }
LAB_0014740c:
    if (iVar1 - 0x6dU < 2) {
LAB_00147430:
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x4953,Globals::Canvas,false);
      *(AEGeometry **)(this + 0x13c) = pAVar6;
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x4954,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar6 + 0xc));
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x4955,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      pAVar10 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar10,0x4956,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar10 + 0xc));
      if (pvVar3 != (void *)0x0) {
        if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar3 + 4));
        }
        operator_delete(pvVar3);
      }
      pFVar2 = operator_new(1);
      FileRead::FileRead(pFVar2);
      pvVar3 = (void *)FileRead::loadStaticCollision(pFVar2,0x7d2);
      pvVar4 = (void *)FileRead::~FileRead(pFVar2);
      operator_delete(pvVar4);
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar6);
      operator_delete(pvVar4);
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar9);
      operator_delete(pvVar4);
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar10);
      operator_delete(pvVar4);
      fVar19 = extraout_s0_10;
      fVar20 = extraout_s1_10;
      fVar21 = extraout_s2_10;
      goto LAB_00147526;
    }
    if (iVar1 == 0x6f) {
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      if (0x5e < iVar1) goto LAB_00147430;
      iVar1 = *(int *)(this + 0x144);
      fVar19 = extraout_s0_09;
      fVar20 = extraout_s1_09;
      fVar21 = extraout_s2_09;
    }
    if (iVar1 == 100) {
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      uVar8 = Status::dlc1Won(Globals::status);
      pAVar6 = operator_new(0xc0);
      uVar14 = 0x4223;
      if (uVar8 != 0) {
        uVar14 = 0x3823;
      }
      if (iVar1 == 0x50) {
        uVar14 = 0x381f;
      }
      AEGeometry::AEGeometry(pAVar6,uVar14,Globals::Canvas,false);
      *(AEGeometry **)(this + 0x13c) = pAVar6;
      local_64 = -NAN;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)&local_64);
      uVar17 = iVar1 == 0x50 | uVar8;
      uVar14 = 0x4228;
      if (uVar17 != 0) {
        uVar14 = 0x422a;
      }
      AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,(uint)local_64,uVar14,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),(uint)local_64);
      *(float *)(this + 0x140) = local_64;
      local_54 = 0xffffffff;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_54);
      uVar14 = 0x4224;
      if (uVar8 != 0) {
        uVar14 = 0x3824;
      }
      if (iVar1 == 0x50) {
        uVar14 = 0x3820;
      }
      AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_54,uVar14,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),local_54);
      local_58 = 0xffffffff;
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,&local_58);
      uVar14 = 0x4225;
      if (uVar8 != 0) {
        uVar14 = 0x3825;
      }
      if (iVar1 == 0x50) {
        uVar14 = 0x3821;
      }
      AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_58,uVar14,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),local_58);
      if (uVar17 == 1) {
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar7,0,0);
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,local_54);
        AbyssEngine::Transform::SetAnimationState(uVar7,0,0);
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,local_58);
        AbyssEngine::Transform::SetAnimationState(uVar7,0,0);
        if (pvVar3 != (void *)0x0) {
          if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar3 + 4));
          }
          operator_delete(pvVar3);
        }
        pFVar2 = operator_new(1);
        FileRead::FileRead(pFVar2);
        pvVar3 = (void *)FileRead::loadStationCollision(pFVar2,0x3ed);
        pvVar4 = (void *)FileRead::~FileRead(pFVar2);
        operator_delete(pvVar4);
        fVar19 = extraout_s0_12;
        fVar20 = extraout_s1_14;
        fVar21 = extraout_s2_13;
      }
      else {
        local_4c = CONCAT22(local_4c._2_2_,0x4226);
        local_48 = 70000;
        AEGeometry::setLodMeshes
                  (*(AEGeometry **)(this + 0x13c),(ushort *)&local_4c,(int *)&local_48,1);
        uStack_4e = 0x4227;
        AEGeometry::setLodChildMeshes(*(AEGeometry **)(this + 0x13c),&uStack_4e);
        fVar19 = extraout_s0_14;
        fVar20 = extraout_s1_16;
        fVar21 = extraout_s2_15;
      }
      goto LAB_00147526;
    }
    if ((uVar8 | 2) == 2) {
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,(short)iVar1 + 0x5528,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar6 + 0xc));
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry
                (pAVar9,(short)*(undefined4 *)(this + 0x144) + 22000,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar6);
      operator_delete(pvVar4);
      pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar9);
      operator_delete(pvVar4);
      fVar19 = extraout_s0_13;
      fVar20 = extraout_s1_15;
      fVar21 = extraout_s2_14;
      goto LAB_00147526;
    }
    if (uVar8 != 3) goto LAB_00147526;
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,(short)iVar1 + 0x5528,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar6 + 0xc));
    this_04 = operator_new(0xc0);
    AEGeometry::AEGeometry
              (this_04,(short)*(undefined4 *)(this + 0x144) + 22000,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(this_04 + 0xc));
    if (*(int *)(this + 0x144) == 0x6c) {
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x5974,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      *(undefined4 *)(this + 0x160) = *(undefined4 *)(pAVar9 + 0xc);
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x5975,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      *(undefined4 *)(this + 0x164) = *(undefined4 *)(pAVar9 + 0xc);
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x5976,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      *(undefined4 *)(this + 0x168) = *(undefined4 *)(pAVar9 + 0xc);
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x5977,Globals::Canvas,false);
      AEGeometry::addChild(*(AEGeometry **)(this + 0x13c),*(uint *)(pAVar9 + 0xc));
      *(undefined4 *)(this + 0x16c) = *(undefined4 *)(pAVar9 + 0xc);
    }
    pvVar4 = (void *)AEGeometry::~AEGeometry(pAVar6);
    operator_delete(pvVar4);
  }
  pvVar4 = (void *)AEGeometry::~AEGeometry(this_04);
  operator_delete(pvVar4);
  fVar19 = extraout_s0_06;
  fVar20 = extraout_s1_06;
  fVar21 = extraout_s2_06;
LAB_00147526:
  if (pvVar3 != (void *)0x0) {
    uVar8 = **(uint **)((int)pvVar3 + 4);
    local_64 = 0.0;
    local_60 = 0.0;
    local_5c = 0.0;
    pAVar11 = operator_new(0xc);
    puVar12 = operator_new__(4);
    *(undefined4 **)(pAVar11 + 4) = puVar12;
    *(undefined4 *)(pAVar11 + 8) = 1;
    *puVar12 = 0;
    *(undefined4 *)pAVar11 = 0;
    *(Array **)(this + 300) = pAVar11;
    ArraySetLength<BoundingVolume*>(uVar8,pAVar11);
    if (0 < (int)uVar8) {
      iVar18 = 0;
      iVar1 = 1;
      do {
        iVar13 = *(int *)((int)pvVar3 + 4);
        iVar15 = iVar1 + 1;
        iVar16 = *(int *)(iVar13 + iVar1 * 4);
        if (iVar16 == 1) {
          iVar16 = iVar13 + iVar1 * 4;
          local_64 = (float)VectorSignedToFloat(*(undefined4 *)(iVar16 + 0x10),
                                                (byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(*(undefined4 *)(iVar16 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(*(undefined4 *)(iVar16 + 8),(byte)(in_fpscr >> 0x16) & 3);
          local_5c = (float)VectorSignedToFloat(*(undefined4 *)(iVar16 + 0x14),
                                                (byte)(in_fpscr >> 0x16) & 3);
          local_60 = (float)VectorSignedToFloat(*(undefined4 *)(iVar16 + 0x18),
                                                (byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(-*(int *)(iVar13 + iVar15 * 4),(byte)(in_fpscr >> 0x16) & 3);
          if (iVar5 == 1) {
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_64,local_60);
          }
          else {
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_64,local_60);
          }
          this_03 = operator_new(0x2c);
          BoundingAAB::BoundingAAB
                    (this_03,local_64 + local_64,extraout_s1_12,local_60 + local_60,extraout_s3_00,
                     local_5c + local_5c,extraout_s5_00,extraout_s6_00,extraout_s7,extraout_s8);
          iVar15 = iVar1 + 7;
          *(BoundingAAB **)(*(int *)(*(int *)(this + 300) + 4) + iVar18 * 4) = this_03;
        }
        else if (iVar16 == 0) {
          iVar16 = iVar13 + iVar1 * 4;
          fVar19 = *(float *)(iVar16 + 8);
          local_64 = (float)VectorSignedToFloat(*(undefined4 *)(iVar16 + 0x10),
                                                (byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(-*(int *)(iVar13 + iVar15 * 4),(byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(*(undefined4 *)(iVar16 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
          VectorSignedToFloat(fVar19,(byte)(in_fpscr >> 0x16) & 3);
          if (iVar5 == 1) {
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_64,fVar19);
          }
          else {
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_64,fVar19);
          }
          in_fpscr = in_fpscr & 0xfffffff;
          if (local_64 < 0.0) {
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_64,local_64);
          }
          this_02 = operator_new(0x48);
          BoundingSphere::BoundingSphere
                    (this_02,local_64,extraout_s1_11,extraout_s2_11,extraout_s3,extraout_s4,
                     extraout_s5,extraout_s6);
          iVar15 = iVar1 + 5;
          *(BoundingSphere **)(*(int *)(*(int *)(this + 300) + 4) + iVar18 * 4) = this_02;
        }
        iVar18 = iVar18 + 1;
        iVar1 = iVar15;
      } while (iVar18 < (int)uVar8);
    }
    if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar3 + 4));
    }
    *(undefined4 *)((int)pvVar3 + 4) = 0;
    if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar3 + 4));
    }
    operator_delete(pvVar3);
    fVar19 = extraout_s0_11;
    fVar20 = extraout_s1_13;
    fVar21 = extraout_s2_12;
  }
  this[0x6d] = (PlayerStation)0x1;
  AEGeometry::setRotation(*(AEGeometry **)(this + 0x13c),fVar19,fVar20,fVar21);
  iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0xc));
  *(int *)(this + 0x150) = (int)(*(float *)(iVar1 + 0xe0) + 5000.0);
  if (__stack_chk_guard - local_44 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_44);
  }
  return;
}

// ===== PlayerStation::~PlayerStation  @0x00147d44  (100 bytes)
/* PlayerStation::~PlayerStation() */

void __thiscall PlayerStation::~PlayerStation(PlayerStation *this)

{
  void *pvVar1;
  
  *(undefined ***)this = &PTR__PlayerStation_00264330;
  if (*(AEGeometry **)(this + 0x13c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x13c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x13c) = 0;
  if (*(AEGeometry **)(this + 0x148) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x148));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x148) = 0;
  if (*(Array **)(this + 300) != (Array *)0x0) {
    ArrayReleaseClasses<BoundingVolume*>(*(Array **)(this + 300));
    pvVar1 = *(void **)(this + 300);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 300) = 0;
  PlayerStaticFar::~PlayerStaticFar((PlayerStaticFar *)this);
  return;
}

// ===== PlayerStation::~PlayerStation  @0x00147dac  (16 bytes)
/* PlayerStation::~PlayerStation() */

void __thiscall PlayerStation::~PlayerStation(PlayerStation *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~PlayerStation(this);
  operator_delete(pvVar1);
  return;
}

// ===== PlayerStation::update  @0x00147dbc  (232 bytes)
/* PlayerStation::update(int) */

void __thiscall PlayerStation::update(PlayerStation *this,int param_1)

{
  int iVar1;
  bool bVar2;
  longlong lVar3;
  
  iVar1 = *(int *)(*(int *)(this + 0x13c) + 0x14);
  bVar2 = iVar1 != -1;
  if (bVar2) {
    iVar1 = *(int *)(this + 0x144);
  }
  if ((bVar2 && iVar1 != 0x65) && (iVar1 = Status::inAlienOrbit(Globals::status), iVar1 == 0)) {
    lVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x13c) + 0x14));
    bVar2 = SUB41(param_1,0);
    AbyssEngine::Transform::Update(lVar3,bVar2);
    if (*(int *)(this + 0x144) == 100) {
      lVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x140));
    }
    else {
      if (*(int *)(this + 0x144) != 0x6c) {
        return;
      }
      lVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x160));
      AbyssEngine::Transform::Update(lVar3,bVar2);
      lVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x164));
      AbyssEngine::Transform::Update(lVar3,bVar2);
      lVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x168));
      AbyssEngine::Transform::Update(lVar3,bVar2);
      lVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(this + 0x16c));
    }
    AbyssEngine::Transform::Update(lVar3,bVar2);
  }
  return;
}

// ===== PlayerStation::render  @0x00147eb4  (16 bytes)
/* PlayerStation::render() */

void __thiscall PlayerStation::render(PlayerStation *this)

{
  if (this[0xf1] == (PlayerStation)0x0) {
    return;
  }
  AEGeometry::render(*(AEGeometry **)(this + 0x13c));
  return;
}

// ===== PlayerStation::setPosition  @0x00147ec4  (80 bytes)
/* PlayerStation::setPosition(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerStation::setPosition(PlayerStation *this,Vector *param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  
  *(undefined4 *)(this + 0x54) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 8);
  AEGeometry::setPosition(*(Vector **)(this + 0x13c));
  puVar1 = *(uint **)(this + 300);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      piVar2 = *(int **)(puVar1[1] + uVar3 * 4);
      (**(code **)(*piVar2 + 4))
                (piVar2,*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),
                 *(undefined4 *)(param_1 + 8));
      puVar1 = *(uint **)(this + 300);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return;
}

// ===== PlayerStation::getPosition  @0x00147f14  (14 bytes)
/* PlayerStation::getPosition() */

void PlayerStation::getPosition(void)

{
  AEGeometry::getPosition();
  return;
}

// ===== PlayerStation::getRoot  @0x00147f22  (6 bytes)
/* PlayerStation::getRoot() */

undefined4 __thiscall PlayerStation::getRoot(PlayerStation *this)

{
  return *(undefined4 *)(this + 0x13c);
}

// ===== PlayerStation::setVisible  @0x00147f28  (6 bytes)
/* PlayerStation::setVisible(bool) */

void __thiscall PlayerStation::setVisible(PlayerStation *this,bool param_1)

{
  this[0xf1] = (PlayerStation)param_1;
  return;
}

// ===== PlayerStation::translate  @0x00147f2e  (10 bytes)
/* PlayerStation::translate(float, float, float) */

void PlayerStation::translate(float param_1,float param_2,float param_3)

{
  int in_r0;
  
  AEGeometry::translate(*(AEGeometry **)(in_r0 + 0x13c),param_1,param_2,param_3);
  return;
}

// ===== PlayerStation::collide  @0x00147f36  (10 bytes)
/* PlayerStation::collide(float, float, float) */

void PlayerStation::collide(float param_1,float param_2,float param_3)

{
  int *in_r0;
  
                    /* WARNING: Could not recover jumptable at 0x00147f3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_r0 + 0x3c))();
  return;
}

// ===== PlayerStation::outerCollide  @0x00147f40  (204 bytes)
/* PlayerStation::outerCollide(float, float, float) */

undefined4 __thiscall
PlayerStation::outerCollide(PlayerStation *this,float param_1,float param_2,float param_3)

{
  int iVar1;
  float in_r1;
  uint *puVar2;
  float in_r2;
  float in_r3;
  uint uVar3;
  uint in_fpscr;
  float fVar4;
  float extraout_s0;
  float extraout_s1;
  
  fVar4 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x150),(byte)(in_fpscr >> 0x16) & 3);
  if ((in_r1 < *(float *)(this + 0x54) + fVar4) &&
     ((int)((uint)(*(float *)(this + 0x54) - fVar4 < in_r1) << 0x1f) < 0)) {
    if ((in_r2 < fVar4 + *(float *)(this + 0x58)) &&
       ((int)((uint)(*(float *)(this + 0x58) - fVar4 < in_r2) << 0x1f) < 0)) {
      if ((in_r3 < fVar4 + *(float *)(this + 0x5c)) &&
         (fVar4 = *(float *)(this + 0x5c) - fVar4, (int)((uint)(fVar4 < in_r3) << 0x1f) < 0)) {
        puVar2 = *(uint **)(this + 300);
        if ((puVar2 == (uint *)0x0) || (*puVar2 == 0)) {
          return 0;
        }
        uVar3 = 0;
        do {
          iVar1 = (**(code **)(**(int **)(puVar2[1] + uVar3 * 4) + 0xc))(fVar4,param_2);
          if (iVar1 == 1) {
            *(uint *)(this + 0x14c) = uVar3;
            return 1;
          }
          puVar2 = *(uint **)(this + 300);
          uVar3 = uVar3 + 1;
          fVar4 = extraout_s0;
          param_2 = extraout_s1;
        } while (uVar3 < *puVar2);
      }
    }
  }
  return 0;
}

// ===== PlayerStation::outerCollide  @0x0014800c  (26 bytes)
/* PlayerStation::outerCollide(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerStation::outerCollide(PlayerStation *this,Vector *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00148024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x3c))
            (this,*(undefined4 *)param_1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}

// ===== PlayerStation::getProjectionVector  @0x00148026  (36 bytes)
/* PlayerStation::getProjectionVector(AbyssEngine::AEMath::Vector const&) */

void __thiscall PlayerStation::getProjectionVector(PlayerStation *this,Vector *param_1)

{
  if (*(int *)(param_1 + 300) != 0) {
    BoundingVolume::getProjectionVector((Vector *)this);
    return;
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}

// ===== PlayerStation::projectCollisionOnSurface  @0x0014804a  (18 bytes)
/* PlayerStation::projectCollisionOnSurface(AbyssEngine::AEMath::Vector const&) */

void PlayerStation::projectCollisionOnSurface(Vector *param_1)

{
  int in_r1;
  Vector *in_r2;
  
  BoundingVolume::staticProjectCollisionOnSurface
            ((BoundingVolume *)param_1,in_r2,*(Array **)(in_r1 + 300));
  return;
}

