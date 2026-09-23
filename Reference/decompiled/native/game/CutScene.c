// Class: CutScene
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== CutScene::CutScene  @0x000a3e1c  (62 bytes)
/* CutScene::CutScene(int) */

void __thiscall CutScene::CutScene(CutScene *this,int param_1)

{
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(int *)(this + 0x88) = param_1;
  *(undefined4 *)(this + 0x6c) = 0xffffffff;
  *(undefined4 *)(this + 0x70) = 0xffffffff;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  this[0x5c] = (CutScene)0x0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x24) = 0x3851b717;
  return;
}

// ===== CutScene::~CutScene  @0x000a3e5c  (162 bytes)
/* CutScene::~CutScene() */

CutScene * __thiscall CutScene::~CutScene(CutScene *this)

{
  void *pvVar1;
  
  if (*(AEGeometry **)(this + 0x20) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x20));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x20) = 0;
  if (*(AEGeometry **)(this + 100) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 100));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 100) = 0;
  if (*(Level **)this != (Level *)0x0) {
    pvVar1 = (void *)Level::~Level(*(Level **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,0,1);
  if (*(AEGeometry **)(this + 0x28) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x28));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(AEGeometry **)(this + 0x2c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x2c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  if (*(AEGeometry **)(this + 0x30) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x30));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x30) = 0;
  if (*(AEGeometry **)(this + 0x34) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x34));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x34) = 0;
  if (*(Array **)(this + 0x38) != (Array *)0x0) {
    ArrayReleaseClasses<AEGeometry*>(*(Array **)(this + 0x38));
    pvVar1 = *(void **)(this + 0x38);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x38) = 0;
  return this;
}

// ===== CutScene::resetCamera  @0x000a3f4c  (274 bytes)
/* CutScene::resetCamera() */

void __thiscall CutScene::resetCamera(CutScene *this)

{
  SolarSystem *pSVar1;
  int iVar2;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s2_00;
  
  if (*(int *)(this + 0x88) == 0x17) {
    pSVar1 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar2 = SolarSystem::getRace(pSVar1);
    if (iVar2 == 1) {
      AbyssEngine::PaintCanvas::FogSetParameter
                (Globals::Canvas,0x2601,0,0x46ea6000,0x3f800000,0x11e0cff);
      AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,1,1);
    }
    AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::CameraSetPerspective
              ((uint)Globals::Canvas,extraout_s0_00,extraout_s1_00,extraout_s2_00);
    iVar2 = Level::getEnemies(*(Level **)this);
    KIPlayer::getType((KIPlayer *)**(undefined4 **)(iVar2 + 4));
    return;
  }
  if (*(int *)(this + 0x88) == 4) {
    pSVar1 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar2 = SolarSystem::getRace(pSVar1);
    if (iVar2 == 1) {
      AbyssEngine::PaintCanvas::FogSetParameter
                (Globals::Canvas,0x2601,0,0x459c4000,0x3f800000,0x11e0cff);
      AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,1,1);
    }
    AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::CameraSetPerspective
              ((uint)Globals::Canvas,extraout_s0,extraout_s1,extraout_s2);
  }
  return;
}

// ===== CutScene::initialize  @0x000a4074  (1220 bytes)
/* CutScene::initialize() */

void __thiscall CutScene::initialize(CutScene *this)

{
  int iVar1;
  PlayerEgo *this_00;
  void *pvVar2;
  SolarSystem *pSVar3;
  AEGeometry *pAVar4;
  undefined4 uVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  Matrix *pMVar10;
  uint uVar11;
  int iVar12;
  Level *this_01;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float fVar13;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  ulonglong in_d16;
  ulonglong in_d17;
  undefined8 uVar14;
  float local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  this_01 = *(Level **)this;
  if (this_01 == (Level *)0x0) {
    this_01 = operator_new(0x2a0);
    Level::Level(this_01,*(int *)(this + 0x88));
    *(Level **)this = this_01;
  }
  do {
    iVar1 = Level::init(this_01);
    this_01 = *(Level **)this;
  } while (iVar1 != 1);
  this_00 = (PlayerEgo *)Level::getPlayer(this_01);
  *(PlayerEgo **)(this + 0x60) = this_00;
  if (this_00 != (PlayerEgo *)0x0) {
    PlayerEgo::setActive(this_00,false);
  }
  Level::initParticleSystems(*(Level **)this);
  iVar1 = *(int *)(this + 0x88);
  if (iVar1 == 2) {
    AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0x74));
    AbyssEngine::PaintCanvas::CameraSetPerspective
              ((uint)Globals::Canvas,extraout_s0_00,extraout_s1_00,extraout_s2_00);
    AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
    puVar9 = (undefined4 *)
             AbyssEngine::PaintCanvas::CameraGetLocal(Globals::Canvas,*(uint *)(this + 0x74));
    local_68 = *puVar9;
    uStack_64 = puVar9[1];
    uStack_60 = puVar9[2];
    uStack_5c = puVar9[3];
    uStack_58 = puVar9[4];
    local_54 = puVar9[5];
    uStack_50 = puVar9[6];
    uStack_4c = puVar9[7];
    uStack_48 = puVar9[8];
    uStack_44 = puVar9[9];
    local_40 = puVar9[10];
    uStack_3c = puVar9[0xb];
    uStack_38 = puVar9[0xc];
    uStack_34 = puVar9[0xd];
    uStack_30 = puVar9[0xe];
    iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,60000);
    VectorSignedToFloat(iVar1 + -20000,(byte)(in_fpscr >> 0x16) & 3);
    fVar13 = (float)VectorSignedToFloat(iVar6 + 40000,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_a4,(Matrix *)&local_68,fVar13,extraout_s1_01,extraout_s2_01);
    *(undefined4 *)(this + 4) = 0xbf490fdb;
    AbyssEngine::AEMath::MatrixSetRotation
              ((Matrix *)&local_a4,extraout_s0_01,extraout_s1_02,extraout_s2_02);
    AbyssEngine::PaintCanvas::CameraSetLocal
              (Globals::Canvas,*(uint *)(this + 0x74),(Matrix *)&local_68);
    uVar14 = Status::getPlayingTime(Globals::status);
    if ((((int)(uint)((int)uVar14 == 0) <= (int)((ulonglong)uVar14 >> 0x20)) &&
        (puVar7 = (uint *)Level::getEnemies(*(Level **)this), puVar7 != (uint *)0x0)) &&
       (1 < *puVar7)) {
      iVar12 = puVar7[1] + *puVar7 * 4;
      piVar8 = *(int **)(iVar12 + -8);
      if ((piVar8 != (int *)0x0) && (*(int *)(iVar12 + -4) != 0)) {
        local_a4 = VectorSignedToFloat(iVar1 + -24000,(byte)(in_fpscr >> 0x16) & 3);
        local_9c = VectorSignedToFloat(iVar6 + 0x9a4c,(byte)(in_fpscr >> 0x16) & 3);
        local_a0 = 0xc1f00000;
        (**(code **)(*piVar8 + 0x44))(piVar8,&local_a4);
        piVar8 = *(int **)(puVar7[1] + *puVar7 * 4 + -4);
        local_a4 = VectorSignedToFloat(iVar1 + -0x5b68,(byte)(in_fpscr >> 0x16) & 3);
        local_9c = VectorSignedToFloat(iVar6 + 0x96c8,(byte)(in_fpscr >> 0x16) & 3);
        local_a0 = 0x42480000;
        (**(code **)(*piVar8 + 0x44))(piVar8,&local_a4);
      }
    }
  }
  else if (iVar1 == 0x17) {
    *(undefined4 *)(this + 100) = 0;
    AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0x70));
    AbyssEngine::PaintCanvas::CameraSetPerspective
              ((uint)Globals::Canvas,extraout_s0_02,extraout_s1_03,extraout_s2_03);
    AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
    puVar9 = (undefined4 *)
             AbyssEngine::PaintCanvas::CameraGetLocal(Globals::Canvas,*(uint *)(this + 0x70));
    local_68 = *puVar9;
    uStack_64 = puVar9[1];
    uStack_60 = puVar9[2];
    uStack_5c = puVar9[3];
    uStack_58 = puVar9[4];
    local_54 = puVar9[5];
    uStack_50 = puVar9[6];
    uStack_4c = puVar9[7];
    uStack_48 = puVar9[8];
    uStack_44 = puVar9[9];
    local_40 = puVar9[10];
    uStack_3c = puVar9[0xb];
    uStack_38 = puVar9[0xc];
    uStack_34 = puVar9[0xd];
    uStack_30 = puVar9[0xe];
    AbyssEngine::AEMath::MatrixSetRotation
              ((Matrix *)&local_a4,extraout_s0_03,extraout_s1_04,extraout_s2_04);
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_a4,(Matrix *)&local_68,extraout_s0_04,extraout_s1_05,extraout_s2_05)
    ;
    AbyssEngine::PaintCanvas::CameraSetLocal
              (Globals::Canvas,*(uint *)(this + 0x70),(Matrix *)&local_68);
    AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x78));
    Level::getEnemies(*(Level **)this);
    AEGeometry::getPosition();
    pMVar10 = (Matrix *)
              AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(this + 0x78));
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_a4,pMVar10,local_a8,extraout_s1_06,extraout_s2_06);
    AbyssEngine::PaintCanvas::TransformAddChild
              (Globals::Canvas,*(uint *)(this + 0x78),*(uint *)(this + 0x70));
    resetCamera(this);
    checkForTurret(this);
  }
  else if (iVar1 == 4) {
    AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0x6c));
    AbyssEngine::PaintCanvas::CameraSetPerspective
              ((uint)Globals::Canvas,extraout_s0,extraout_s1,extraout_s2);
    if (*(TargetFollowCamera **)(this + 0x68) != (TargetFollowCamera *)0x0) {
      pvVar2 = (void *)TargetFollowCamera::~TargetFollowCamera
                                 (*(TargetFollowCamera **)(this + 0x68));
      operator_delete(pvVar2);
      *(undefined4 *)(this + 0x68) = 0;
    }
    AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
    resetCamera(this);
    pSVar3 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar1 = SolarSystem::getRace(pSVar3);
    if (iVar1 == 3) {
      pAVar4 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar4,0x36d6,Globals::Canvas,false);
      *(AEGeometry **)(this + 0x2c) = pAVar4;
      uVar5 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(pAVar4 + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar5,0,0);
    }
    else {
      pSVar3 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar1 = SolarSystem::getRace(pSVar3);
      if (iVar1 == 0) {
        pAVar4 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar4,0x37c8,Globals::Canvas,false);
        *(AEGeometry **)(this + 0x30) = pAVar4;
        pAVar4 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar4,0x37c7,Globals::Canvas,false);
        *(AEGeometry **)(this + 0x34) = pAVar4;
        AEGeometry::addChild(*(AEGeometry **)(this + 0x30),*(uint *)(pAVar4 + 0xc));
        if (*(AEGeometry **)(this + 0x34) != (AEGeometry *)0x0) {
          pvVar2 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x34));
          operator_delete(pvVar2);
        }
        *(undefined4 *)(this + 0x34) = 0;
      }
      else {
        pSVar3 = (SolarSystem *)Status::getSystem(Globals::status);
        SolarSystem::getRace(pSVar3);
      }
    }
  }
  pAVar4 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar4,Globals::Canvas);
  *(AEGeometry **)(this + 0x20) = pAVar4;
  AEGeometry::setRotationOrder(pAVar4,2);
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  uVar11 = AbyssEngine::ApplicationManager::GetCurrentTimeMillis(Globals::appManager);
  *(ulonglong *)(this + 0x40) = in_d16 & 0xffff0000ffff0000 | (ulonglong)uVar11 & 0xffff;
  *(ulonglong *)(this + 0x48) = in_d17 & 0xffff0000ffff0000 | (ulonglong)uVar11 & 0xffff;
  this[0x5c] = (CutScene)0x1;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== CutScene::checkForTurret  @0x000a4594  (988 bytes)
/* CutScene::checkForTurret() */

void __thiscall CutScene::checkForTurret(CutScene *this)

{
  PaintCanvas *this_00;
  int iVar1;
  Ship *pSVar2;
  int *piVar3;
  AEGeometry *this_01;
  AEGeometry *this_02;
  AEGeometry *pAVar4;
  void *pvVar5;
  FileRead *this_03;
  Array *pAVar6;
  Array *pAVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float fVar13;
  float extraout_s0_02;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar14;
  float extraout_s1_02;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar15;
  float extraout_s2_02;
  int local_44;
  
  this_00 = Globals::Canvas;
  if (*(int *)(this + 100) != 0) {
    iVar1 = Level::getEnemies(*(Level **)this);
    AbyssEngine::PaintCanvas::TransformRemoveChild
              (this_00,*(uint *)(*(int *)(**(int **)(iVar1 + 4) + 8) + 0xc),
               *(uint *)(*(int *)(this + 100) + 0xc));
  }
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  piVar3 = (int *)Ship::getEquipment(pSVar2,2);
  iVar1 = 0;
  if (piVar3 != (int *)0x0) {
    iVar1 = *piVar3;
  }
  if (piVar3 == (int *)0x0 || iVar1 == 0) {
    return;
  }
  if (*(Item **)piVar3[1] == (Item *)0x0) {
    return;
  }
  iVar1 = Item::getIndex(*(Item **)piVar3[1]);
  iVar10 = -1;
  uVar9 = 0xffff;
  if (iVar1 < 0xb6) {
    if (iVar1 < 0x31) {
      if (iVar1 == 0x2f) {
        uVar12 = 0x1a72;
        uVar9 = 0x1a73;
      }
      else {
        if (iVar1 != 0x30) goto LAB_000a4958;
        uVar12 = 0x1a74;
        uVar9 = 0x1a75;
      }
    }
    else if (iVar1 == 0x31) {
      uVar12 = 0x1a76;
      uVar9 = 0x1a77;
    }
    else if (iVar1 == 0xb4) {
      uVar12 = 0x1a95;
      uVar9 = 0x1a96;
    }
    else {
      if (iVar1 != 0xb5) goto LAB_000a4958;
      uVar12 = 0x1a97;
      uVar9 = 0x1a98;
    }
LAB_000a4726:
    iVar10 = -1;
    iVar1 = -1;
    local_44 = -1;
  }
  else {
    if (iVar1 < 199) {
      if (iVar1 == 0xb6) {
        uVar12 = 0x1a99;
        uVar9 = 0x1a9a;
        goto LAB_000a4726;
      }
      if (iVar1 == 0xc6) {
        uVar12 = 0x4963;
        uVar9 = 0x4967;
        local_44 = -1;
        iVar1 = 0x4964;
        iVar10 = 0x4966;
        goto LAB_000a4730;
      }
    }
    else {
      if (iVar1 == 199) {
        uVar12 = 0x4968;
        uVar9 = 0x496b;
        local_44 = -1;
        iVar1 = 0x4969;
        iVar10 = 0x496a;
        goto LAB_000a4730;
      }
      if (iVar1 == 200) {
        uVar12 = 0x496c;
        uVar9 = 0x496f;
        local_44 = 0x4970;
        iVar1 = 0x496d;
        iVar10 = 0x496e;
        goto LAB_000a4730;
      }
      if (iVar1 == 0xe0) {
        uVar12 = 0x499a;
        uVar9 = 0x499b;
        iVar1 = 0x499c;
        iVar10 = 0x499d;
        local_44 = -1;
        goto LAB_000a4730;
      }
    }
LAB_000a4958:
    iVar1 = -1;
    local_44 = -1;
    uVar12 = 0xffff;
  }
LAB_000a4730:
  this_01 = operator_new(0xc0);
  AEGeometry::AEGeometry(this_01,uVar12,Globals::Canvas,false);
  this_02 = operator_new(0xc0);
  AEGeometry::AEGeometry(this_02,uVar9,Globals::Canvas,false);
  AEGeometry::setRotationOrder(this_02,2);
  if (iVar1 != -1) {
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,(ushort)iVar1,Globals::Canvas,false);
    AEGeometry::addChild(this_01,*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
  }
  if (iVar10 != -1) {
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,(ushort)iVar10,Globals::Canvas,false);
    AEGeometry::addChild(this_02,*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
  }
  if (local_44 != -1) {
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,(ushort)local_44,Globals::Canvas,false);
    AEGeometry::addChild(this_02,*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
  }
  if (*(AEGeometry **)(this + 100) != (AEGeometry *)0x0) {
    pvVar5 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 100));
    operator_delete(pvVar5);
  }
  *(undefined4 *)(this + 100) = 0;
  pAVar4 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar4,Globals::Canvas);
  *(AEGeometry **)(this + 100) = pAVar4;
  this_03 = operator_new(1);
  FileRead::FileRead(this_03);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  iVar1 = Ship::getIndex(pSVar2);
  pAVar6 = (Array *)FileRead::loadWeaponPositions(this_03,iVar1);
  pvVar5 = (void *)FileRead::~FileRead(this_03);
  operator_delete(pvVar5);
  AEGeometry::setPosition((Vector *)this_01);
  AEGeometry::setPosition((Vector *)this_02);
  AEGeometry::translate(this_02,extraout_s0,extraout_s1,extraout_s2);
  iVar1 = Item::getIndex(*(Item **)piVar3[1]);
  fVar13 = extraout_s0_00;
  fVar14 = extraout_s1_00;
  fVar15 = extraout_s2_00;
  if ((iVar1 < 0xc6) ||
     (iVar1 = Item::getIndex(*(Item **)piVar3[1]), fVar13 = extraout_s0_01, fVar14 = extraout_s1_01,
     fVar15 = extraout_s2_01, 200 < iVar1)) {
    AEGeometry::rotate(this_01,fVar13,fVar14,fVar15);
    AEGeometry::rotate(this_02,extraout_s0_02,extraout_s1_02,extraout_s2_02);
  }
  AEGeometry::addChild(*(AEGeometry **)(this + 100),*(uint *)(this_01 + 0xc));
  AEGeometry::addChild(*(AEGeometry **)(this + 100),*(uint *)(this_02 + 0xc));
  iVar1 = Level::getEnemies(*(Level **)this);
  AEGeometry::addChild
            (*(AEGeometry **)(**(int **)(iVar1 + 4) + 8),*(uint *)(*(int *)(this + 100) + 0xc));
  if (pAVar6 == (Array *)0x0) {
    return;
  }
  uVar8 = *(uint *)pAVar6;
  if (uVar8 != 0) {
    uVar11 = 0;
    do {
      pAVar7 = *(Array **)(*(int *)(pAVar6 + 4) + uVar11 * 4);
      if (pAVar7 != (Array *)0x0) {
        ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(pAVar7);
        iVar1 = *(int *)(pAVar6 + 4);
        pvVar5 = *(void **)(iVar1 + uVar11 * 4);
        if (pvVar5 != (void *)0x0) {
          if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar5 + 4));
          }
          operator_delete(pvVar5);
          iVar1 = *(int *)(pAVar6 + 4);
        }
        *(undefined4 *)(iVar1 + uVar11 * 4) = 0;
        uVar8 = *(uint *)pAVar6;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar8);
  }
  ArrayReleaseClasses<Array<AbyssEngine::AEMath::Vector*>*>(pAVar6);
  if (*(void **)(pAVar6 + 4) != (void *)0x0) {
    operator_delete__(*(void **)(pAVar6 + 4));
  }
  operator_delete(pAVar6);
  return;
}

// ===== CutScene::isInitialized  @0x000a49e8  (6 bytes)
/* CutScene::isInitialized() */

CutScene __thiscall CutScene::isInitialized(CutScene *this)

{
  return this[0x5c];
}

// ===== CutScene::update  @0x000a49ee  (4 bytes)
/* CutScene::update(int) */

void CutScene::update(int param_1)

{
  process(param_1);
  return;
}

// ===== CutScene::process  @0x000a49f4  (2302 bytes)
/* CutScene::process(int) */

void CutScene::process(int param_1)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  SolarSystem *pSVar7;
  undefined4 uVar8;
  AEGeometry *pAVar9;
  Station *pSVar10;
  Transform *this;
  undefined4 *puVar11;
  int iVar12;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s2;
  float fVar13;
  float extraout_s2_00;
  float fVar14;
  ulonglong in_d16;
  ulonglong in_d17;
  longlong lVar15;
  undefined8 uVar16;
  Matrix aMStack_a4 [60];
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(char *)(param_1 + 0x5c) != '\0') {
    uVar2 = AbyssEngine::ApplicationManager::GetCurrentTimeMillis(Globals::appManager);
    uVar3 = uVar2 - *(int *)(param_1 + 0x48);
    *(uint *)(param_1 + 0x58) = uVar3;
    *(ulonglong *)(param_1 + 0x40) = in_d16 & 0xffff0000ffff0000 | (ulonglong)uVar2 & 0xffff;
    *(ulonglong *)(param_1 + 0x48) = in_d17 & 0xffff0000ffff0000 | (ulonglong)uVar2 & 0xffff;
    uVar2 = *(uint *)(param_1 + 0x50);
    *(uint *)(param_1 + 0x50) = uVar2 + uVar3;
    *(uint *)(param_1 + 0x54) =
         *(int *)(param_1 + 0x54) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar2,uVar3);
    if (*(TargetFollowCamera **)(param_1 + 0x68) != (TargetFollowCamera *)0x0) {
      TargetFollowCamera::update(*(TargetFollowCamera **)(param_1 + 0x68),0x1e);
    }
    iVar4 = *(int *)(param_1 + 0x88);
    if (iVar4 == 2) {
      fVar14 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x58),
                                          (byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 4) = *(float *)(param_1 + 4) + fVar14 * *(float *)(param_1 + 0x24);
      puVar11 = (undefined4 *)
                AbyssEngine::PaintCanvas::CameraGetLocal(Globals::Canvas,*(uint *)(param_1 + 0x74));
      local_68 = *puVar11;
      uStack_64 = puVar11[1];
      uStack_60 = puVar11[2];
      uStack_5c = puVar11[3];
      uStack_58 = puVar11[4];
      local_54 = puVar11[5];
      uStack_50 = puVar11[6];
      uStack_4c = puVar11[7];
      uStack_48 = puVar11[8];
      uStack_44 = puVar11[9];
      local_40 = puVar11[10];
      uStack_3c = puVar11[0xb];
      uStack_38 = puVar11[0xc];
      uStack_34 = puVar11[0xd];
      uStack_30 = puVar11[0xe];
      AbyssEngine::AEMath::MatrixSetRotation(aMStack_a4,extraout_s0,extraout_s1,extraout_s2);
      AbyssEngine::PaintCanvas::CameraSetLocal
                (Globals::Canvas,*(uint *)(param_1 + 0x74),(Matrix *)&local_68);
      uVar16 = Status::getPlayingTime(Globals::status);
      if ((((int)(uint)((int)uVar16 == 0) <= (int)((ulonglong)uVar16 >> 0x20)) &&
          (puVar6 = (uint *)Level::getEnemies(*(Level **)param_1), puVar6 != (uint *)0x0)) &&
         (uVar2 = *puVar6, 1 < uVar2)) {
        uVar3 = puVar6[1];
        iVar4 = *(int *)(uVar3 + uVar2 * 4 + -8);
        fVar14 = extraout_s1_00;
        if ((iVar4 != 0) && (pAVar9 = *(AEGeometry **)(iVar4 + 8), pAVar9 != (AEGeometry *)0x0)) {
          fVar14 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x58),
                                              (byte)(in_fpscr >> 0x16) & 3);
          AEGeometry::translate(pAVar9,fVar14 * 0.001,extraout_s1_00,fVar14 * 0.1);
          fVar14 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x58),(byte)(in_fpscr >> 0x16) & 3)
          ;
          fVar13 = (float)VectorSignedToFloat(-*(int *)(param_1 + 0x58),(byte)(in_fpscr >> 0x16) & 3
                                             );
          AEGeometry::rotate(*(AEGeometry **)(*(int *)(puVar6[1] + *puVar6 * 4 + -8) + 8),
                             fVar14 * 0.0002,extraout_s1_01,fVar13 * 0.00018);
          uVar2 = *puVar6;
          uVar3 = puVar6[1];
          fVar14 = extraout_s1_02;
        }
        iVar4 = *(int *)(uVar3 + uVar2 * 4 + -4);
        if ((iVar4 != 0) && (pAVar9 = *(AEGeometry **)(iVar4 + 8), pAVar9 != (AEGeometry *)0x0)) {
          fVar13 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x58),
                                              (byte)(in_fpscr >> 0x16) & 3);
          AEGeometry::translate(pAVar9,fVar13 * 0.1,fVar14,0.1);
          fVar14 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x58),(byte)(in_fpscr >> 0x16) & 3)
          ;
          fVar13 = (float)VectorSignedToFloat(-*(int *)(param_1 + 0x58),(byte)(in_fpscr >> 0x16) & 3
                                             );
          AEGeometry::rotate(*(AEGeometry **)(*(int *)(puVar6[1] + *puVar6 * 4 + -4) + 8),
                             fVar14 * 0.0002,extraout_s1_03,fVar13 * 0.0003);
        }
      }
    }
    else if (iVar4 == 0x17) {
      pSVar10 = (Station *)Status::getStation(Globals::status);
      iVar4 = Station::getIndex(pSVar10);
      if (iVar4 == 0x65) {
        uVar2 = 10;
      }
      else {
        pSVar10 = (Station *)Status::getStation(Globals::status);
        iVar4 = Station::getIndex(pSVar10);
        if (iVar4 == 100) {
          uVar2 = 7;
        }
        else {
          pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
          uVar2 = SolarSystem::getRace(pSVar7);
          uVar2 = uVar2 | 2;
        }
      }
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x84);
      pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar4 = SolarSystem::getRace(pSVar7);
      if (iVar4 == 1) {
        AbyssEngine::PaintCanvas::FogSetParameter(Globals::Canvas,0x2601,0,0x46ea6000);
      }
      else if ((uVar2 == 2) && (puVar6 = *(uint **)(param_1 + 0x38), puVar6 != (uint *)0x0)) {
        uVar2 = 0;
        if (*puVar6 != 0) {
          uVar3 = 0;
          do {
            lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (Globals::Canvas,*(uint *)(*(int *)(puVar6[1] + uVar3 * 4) + 0xc));
            AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
            puVar6 = *(uint **)(param_1 + 0x38);
            uVar3 = uVar3 + 1;
            uVar2 = *puVar6;
          } while (uVar3 < uVar2);
        }
        if ((3000 < *(int *)(param_1 + 0x84)) && (*(undefined4 *)(param_1 + 0x84) = 0, uVar2 != 0))
        {
          uVar2 = 0;
          do {
            iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
            if (iVar4 < 0x14) {
              this = (Transform *)
                     AbyssEngine::PaintCanvas::TransformGetTransform
                               (Globals::Canvas,
                                *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x38) + 4) +
                                                  uVar2 * 4) + 0xc));
              iVar4 = AbyssEngine::Transform::IsRunning(this);
              if (iVar4 == 0) {
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,
                                   *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x38) + 4) +
                                                     uVar2 * 4) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar8,3,0);
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,
                                   *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x38) + 4) +
                                                     uVar2 * 4) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,
                                   *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x38) + 4) +
                                                     uVar2 * 4) + 0x14));
                AbyssEngine::Transform::SetAnimationState(uVar8,3,0);
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,
                                   *(uint *)(*(int *)(*(int *)(*(int *)(param_1 + 0x38) + 4) +
                                                     uVar2 * 4) + 0x14));
                AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
              }
            }
            uVar2 = uVar2 + 1;
          } while (uVar2 < **(uint **)(param_1 + 0x38));
        }
      }
      pPVar1 = Globals::Canvas;
      iVar4 = Level::getEnemies(*(Level **)param_1);
      puVar11 = (undefined4 *)
                AbyssEngine::PaintCanvas::TransformGetLocal
                          (pPVar1,*(uint *)(*(int *)(**(int **)(iVar4 + 4) + 8) + 0xc));
      local_68 = *puVar11;
      uStack_64 = puVar11[1];
      uStack_60 = puVar11[2];
      uStack_5c = puVar11[3];
      uStack_58 = puVar11[4];
      local_54 = puVar11[5];
      uStack_50 = puVar11[6];
      uStack_4c = puVar11[7];
      uStack_48 = puVar11[8];
      uStack_44 = puVar11[9];
      local_40 = puVar11[10];
      uStack_3c = puVar11[0xb];
      uStack_38 = puVar11[0xc];
      uStack_34 = puVar11[0xd];
      uStack_30 = puVar11[0xe];
      AbyssEngine::AEMath::MatrixSetRotation
                (aMStack_a4,extraout_s0_00,extraout_s1_04,extraout_s2_00);
      pPVar1 = Globals::Canvas;
      iVar4 = Level::getEnemies(*(Level **)param_1);
      AbyssEngine::PaintCanvas::TransformSetLocal
                (pPVar1,*(uint *)(*(int *)(**(int **)(iVar4 + 4) + 8) + 0xc),(Matrix *)&local_68);
      piVar5 = (int *)Level::getEnemies(*(Level **)param_1);
      if (*piVar5 != 0) {
        uVar2 = 0;
        do {
          iVar4 = Level::getEnemies(*(Level **)param_1);
          pPVar1 = Globals::Canvas;
          if (*(int *)(*(int *)(iVar4 + 4) + uVar2 * 4) != 0) {
            iVar4 = Level::getEnemies(*(Level **)param_1);
            lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (pPVar1,*(uint *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + uVar2 * 4)
                                                         + 8) + 0xc));
            AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
          }
          puVar6 = (uint *)Level::getEnemies(*(Level **)param_1);
          uVar2 = uVar2 + 1;
        } while (uVar2 < *puVar6);
      }
    }
    else if (iVar4 == 4) {
      piVar5 = (int *)Level::getEnemies(*(Level **)param_1);
      if (*piVar5 != 0) {
        uVar2 = 0;
        do {
          iVar4 = Level::getEnemies(*(Level **)param_1);
          pPVar1 = Globals::Canvas;
          if (*(int *)(*(int *)(iVar4 + 4) + uVar2 * 4) != 0) {
            iVar4 = Level::getEnemies(*(Level **)param_1);
            lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (pPVar1,*(uint *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + uVar2 * 4)
                                                         + 8) + 0xc));
            AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
          }
          puVar6 = (uint *)Level::getEnemies(*(Level **)param_1);
          uVar2 = uVar2 + 1;
        } while (uVar2 < *puVar6);
      }
      pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar4 = SolarSystem::getRace(pSVar7);
      if (iVar4 == 0) {
        uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x30) + 0xc));
        AbyssEngine::Transform::Update((ulonglong)uVar2,SUB41(*(undefined4 *)(param_1 + 0x58),0));
      }
      else {
        pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar4 = SolarSystem::getRace(pSVar7);
        if (iVar4 == 1) {
          AbyssEngine::PaintCanvas::FogSetParameter(Globals::Canvas,0x2601,0,0x459c4000);
          AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,1,1);
          pPVar1 = Globals::Canvas;
          iVar4 = Level::getEnemies(*(Level **)param_1);
          piVar5 = (int *)Level::getEnemies(*(Level **)param_1);
          lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (pPVar1,*(uint *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + *piVar5 * 4 +
                                                                -0xc) + 8) + 0xc));
          AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
          if (*(int *)(param_1 + 0x30) != 0) {
            lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x30) + 0xc));
            AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
            iVar4 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x7c);
            *(int *)(param_1 + 0x7c) = iVar4;
            if (20000 < iVar4) {
              *(undefined4 *)(param_1 + 0x7c) = 0;
              iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
              if (iVar4 < 100) {
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x30) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar8,3,0);
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x30) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
              }
            }
          }
          if (*(int *)(param_1 + 0x34) != 0) {
            lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x34) + 0xc));
            AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
            iVar4 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x80);
            *(int *)(param_1 + 0x80) = iVar4;
            if (22000 < iVar4) {
              *(undefined4 *)(param_1 + 0x80) = 0;
              iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
              if (iVar4 < 100) {
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x34) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar8,3,0);
                iVar4 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x34) + 0xc));
LAB_000a4fe8:
                iVar12 = __stack_chk_guard - local_28;
                if (iVar12 == 0) {
                  AbyssEngine::Transform::SetAnimationState(iVar4,1,0);
                  return;
                }
                goto LAB_000a5270;
              }
            }
          }
        }
        else {
          pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar4 = SolarSystem::getRace(pSVar7);
          pPVar1 = Globals::Canvas;
          if (iVar4 == 3) {
            iVar4 = Level::getEnemies(*(Level **)param_1);
            piVar5 = (int *)Level::getEnemies(*(Level **)param_1);
            lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (pPVar1,*(uint *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + *piVar5 * 4
                                                                  + -0xc) + 8) + 0xc));
            AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
            if (*(int *)(param_1 + 0x28) != 0) {
              lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                                 (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x28) + 0xc));
              AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
            }
            lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                               (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x2c) + 0xc));
            AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
            iVar4 = *(int *)(param_1 + 0x7c) + *(int *)(param_1 + 0x58);
            *(int *)(param_1 + 0x7c) = iVar4;
            iVar12 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x80);
            *(int *)(param_1 + 0x80) = iVar12;
            if (*(int *)(param_1 + 0x28) != 0) {
              if (1000 < iVar4) {
                *(undefined4 *)(param_1 + 0x7c) = 0;
                iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
                if (iVar4 < 0x28) {
                  uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                    (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x28) + 0xc));
                  AbyssEngine::Transform::SetAnimationState(uVar8,3,0);
                  uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                    (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x28) + 0xc));
                  AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
                }
              }
              iVar12 = *(int *)(param_1 + 0x80);
            }
            if (2000 < iVar12) {
              *(undefined4 *)(param_1 + 0x80) = 0;
              iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
              if (iVar4 < 0x1e) {
                uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x2c) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar8,3,0);
                iVar4 = AbyssEngine::PaintCanvas::TransformGetTransform
                                  (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0x2c) + 0xc));
                goto LAB_000a4fe8;
              }
            }
          }
          else {
            pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
            iVar4 = SolarSystem::getRace(pSVar7);
            pPVar1 = Globals::Canvas;
            if (iVar4 == 2) {
              iVar4 = Level::getEnemies(*(Level **)param_1);
              piVar5 = (int *)Level::getEnemies(*(Level **)param_1);
              lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                                 (pPVar1,*(uint *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) +
                                                                     *piVar5 * 4 + -8) + 8) + 0xc));
              AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
              pPVar1 = Globals::Canvas;
              iVar4 = Level::getEnemies(*(Level **)param_1);
              piVar5 = (int *)Level::getEnemies(*(Level **)param_1);
              lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                                 (pPVar1,*(uint *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) +
                                                                     *piVar5 * 4 + -4) + 8) + 0xc));
              AbyssEngine::Transform::Update(lVar15,SUB41(*(undefined4 *)(param_1 + 0x58),0));
            }
          }
        }
      }
    }
  }
  iVar4 = __stack_chk_guard - local_28;
  iVar12 = local_28;
  if (iVar4 == 0) {
    return;
  }
LAB_000a5270:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar4,iVar12);
}

// ===== CutScene::update  @0x000a53b0  (4 bytes)
/* CutScene::update() */

void __thiscall CutScene::update(CutScene *this)

{
  process((int)this);
  return;
}

// ===== CutScene::replacePlayerShip  @0x000a53b4  (304 bytes)
/* CutScene::replacePlayerShip(int, int) */

void __thiscall CutScene::replacePlayerShip(CutScene *this,int param_1,int param_2)

{
  PaintCanvas *this_00;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  AEGeometry *this_01;
  uint in_fpscr;
  
  iVar1 = __stack_chk_guard;
  iVar2 = Level::getEnemies(*(Level **)this);
  if (iVar2 != 0) {
    iVar2 = Level::getEnemies(*(Level **)this);
    this_00 = Globals::Canvas;
    this_01 = *(AEGeometry **)(**(int **)(iVar2 + 4) + 8);
    if (this_01 != (AEGeometry *)0x0) {
      if (*(int *)(this + 100) != 0) {
        iVar2 = Level::getEnemies(*(Level **)this);
        AbyssEngine::PaintCanvas::TransformRemoveChild
                  (this_00,*(uint *)(*(int *)(**(int **)(iVar2 + 4) + 8) + 0xc),
                   *(uint *)(*(int *)(this + 100) + 0xc));
      }
      AEGeometry::getMatrix(this_01);
      uVar3 = Globals::getShipGroup(Globals::globals,param_1,param_2,false);
      iVar2 = Level::getEnemies(*(Level **)this);
      *(undefined4 *)(**(int **)(iVar2 + 4) + 8) = uVar3;
      iVar2 = Level::getEnemies(*(Level **)this);
      AEGeometry::setMatrix(*(Matrix **)(**(int **)(iVar2 + 4) + 8));
      uVar3 = VectorSignedToFloat(*(undefined4 *)(&DAT_002520f0 + param_1 * 4),
                                  (byte)(in_fpscr >> 0x16) & 3);
      iVar2 = Level::getEnemies(*(Level **)this);
      (**(code **)(*(int *)**(undefined4 **)(iVar2 + 4) + 0x48))
                ((int *)**(undefined4 **)(iVar2 + 4),0,uVar3,0);
      iVar2 = Level::getEnemies(*(Level **)this);
      PlayerFighter::setExhaustVisible((PlayerFighter *)**(undefined4 **)(iVar2 + 4),false);
      LODManager::removeObject((LODManager *)**(undefined4 **)this,this_01);
      pvVar4 = (void *)AEGeometry::~AEGeometry(this_01);
      operator_delete(pvVar4);
    }
    checkForTurret(this);
  }
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== CutScene::render2D  @0x000a557a  (8 bytes)
/* CutScene::render2D() */

void CutScene::render2D(void)

{
  Level::render2D();
  return;
}

// ===== CutScene::renderBG  @0x000a5580  (12 bytes)
/* CutScene::renderBG() */

void __thiscall CutScene::renderBG(CutScene *this)

{
  Level::renderBG(*(Level **)this,*(int *)(this + 0x58));
  return;
}

// ===== CutScene::render3D  @0x000a558c  (116 bytes)
/* CutScene::render3D() */

void __thiscall CutScene::render3D(CutScene *this)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  
  if (*(int *)this != 0) {
    uVar1 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis(Globals::appManager);
    *(undefined4 *)(this + 0x58) = uVar1;
    Level::update(CONCAT44(uVar1,*(undefined4 *)this),SUB41(uVar1,0));
    Level::render(*(Level **)this,*(int *)(this + 0x58));
  }
  if (*(AEGeometry **)(this + 0x28) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x28));
  }
  if (*(AEGeometry **)(this + 0x2c) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x2c));
  }
  if (*(AEGeometry **)(this + 0x30) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x30));
  }
  if (*(AEGeometry **)(this + 0x34) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0x34));
  }
  puVar2 = *(uint **)(this + 0x38);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      AEGeometry::render(*(AEGeometry **)(puVar2[1] + uVar3 * 4));
      puVar2 = *(uint **)(this + 0x38);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return;
}

