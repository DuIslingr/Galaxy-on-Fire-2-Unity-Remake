// Class: LevelScript
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== LevelScript::LevelScript  @0x0015e650  (8862 bytes)
/* LevelScript::LevelScript(Level*, Hud*, Radar*, TargetFollowCamera*) */

void __thiscall
LevelScript::LevelScript
          (LevelScript *this,Level *param_1,Hud *param_2,Radar *param_3,TargetFollowCamera *param_4)

{
  PaintCanvas *pPVar1;
  FModSound *pFVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  PlayerEgo *pPVar6;
  AEGeometry *pAVar7;
  undefined4 uVar8;
  Explosion *this_00;
  AEGeometry *this_01;
  AEGeometry *pAVar9;
  AEGeometry *this_02;
  Transform *this_03;
  void *pvVar10;
  Mission *pMVar11;
  Station *pSVar12;
  float *pfVar13;
  Vector *pVVar14;
  int *piVar15;
  Route *this_04;
  code *pcVar16;
  uint *puVar17;
  int iVar18;
  Vector *pVVar19;
  LevelScript *pLVar20;
  ParticleSystemManager *pPVar21;
  uint uVar22;
  int iVar23;
  Player *pPVar24;
  Vector *pVVar25;
  uint in_fpscr;
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
  float extraout_s0_11;
  float fVar26;
  float extraout_s0_12;
  float extraout_s0_13;
  float extraout_s0_14;
  float extraout_s0_15;
  float fVar27;
  float extraout_s0_16;
  float extraout_s0_17;
  float extraout_s0_18;
  float extraout_s0_19;
  float extraout_s0_20;
  float extraout_s0_21;
  float extraout_s0_22;
  float extraout_s0_23;
  float extraout_s0_24;
  float extraout_s0_25;
  float extraout_s0_26;
  float extraout_s0_27;
  float extraout_s0_28;
  float extraout_s0_29;
  float extraout_s0_30;
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
  float extraout_s1_11;
  float extraout_s1_12;
  float extraout_s1_13;
  float extraout_s1_14;
  float extraout_s1_15;
  float extraout_s1_16;
  float extraout_s1_17;
  float extraout_s1_18;
  float extraout_s1_19;
  float extraout_s1_20;
  float extraout_s1_21;
  float extraout_s1_22;
  float extraout_s1_23;
  float extraout_s1_24;
  float extraout_s1_25;
  float extraout_s1_26;
  float extraout_s1_27;
  float extraout_s1_28;
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
  float extraout_s2_11;
  float extraout_s2_12;
  float extraout_s2_13;
  float extraout_s2_14;
  float extraout_s2_15;
  undefined4 uVar28;
  float extraout_s2_16;
  float extraout_s2_17;
  float extraout_s2_18;
  float extraout_s2_19;
  float extraout_s2_20;
  float extraout_s2_21;
  float extraout_s2_22;
  float extraout_s2_23;
  float extraout_s2_24;
  float fVar29;
  float extraout_s2_25;
  float extraout_s2_26;
  float extraout_s2_27;
  float extraout_s2_28;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float fStack_c8;
  float local_c4;
  float fStack_c0;
  float fStack_bc;
  float local_b8;
  float fStack_b4;
  float local_b0;
  float fStack_ac;
  float local_a8;
  float fStack_a4;
  float fStack_a0;
  Vector aVStack_9c [12];
  AEMath aAStack_90 [12];
  Vector aVStack_84 [12];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  int local_3c;
  
  uVar8 = 0;
  uVar28 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar31 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  pVVar25 = (Vector *)(this + 0x28);
  local_3c = __stack_chk_guard;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = uVar28;
  *(undefined4 *)(this + 0x40) = uVar30;
  *(undefined4 *)(this + 0x44) = uVar31;
  *(undefined4 *)pVVar25 = 0;
  *(undefined4 *)(this + 0x2c) = uVar28;
  *(undefined4 *)(this + 0x30) = uVar30;
  *(undefined4 *)(this + 0x34) = uVar31;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0x3f800000;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = uVar28;
  *(undefined4 *)(this + 0x58) = uVar30;
  *(undefined4 *)(this + 0x5c) = uVar31;
  *(undefined4 *)(this + 0x60) = 0x3f800000;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = uVar28;
  *(undefined4 *)(this + 0x6c) = uVar30;
  *(undefined4 *)(this + 0x70) = uVar31;
  *(undefined8 *)(this + 0x74) = 0x3f800000;
  *(undefined8 *)(this + 0x7c) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x84) = 0x3f800000;
  *(Hud **)(this + 0xd0) = param_2;
  *(Radar **)(this + 0xd4) = param_3;
  *(TargetFollowCamera **)(this + 0x14) = param_4;
  *(Level **)(this + 0x18) = param_1;
  Hud::drawTitleImage(SUB41(param_2,0));
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined2 *)(this + 0x20) = 1;
  *(undefined2 *)(this + 0x10) = 0x100;
  uVar3 = Level::getTimeLimit(param_1);
  *(undefined4 *)this = uVar3;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined2 *)(this + 0x12) = 0;
  *(undefined4 *)(this + 0x9a) = uVar8;
  *(undefined4 *)(this + 0x9e) = uVar28;
  *(undefined4 *)(this + 0xa2) = uVar30;
  *(undefined4 *)(this + 0xa6) = uVar31;
  *(undefined4 *)(this + 0x8c) = uVar8;
  *(undefined4 *)(this + 0x90) = uVar28;
  *(undefined4 *)(this + 0x94) = uVar30;
  *(undefined4 *)(this + 0x98) = uVar31;
  *(undefined4 *)(this + 0xbc) = uVar8;
  *(undefined4 *)(this + 0xc0) = uVar28;
  *(undefined4 *)(this + 0xc4) = uVar30;
  *(undefined4 *)(this + 200) = uVar31;
  *(undefined4 *)(this + 0xac) = uVar8;
  *(undefined4 *)(this + 0xb0) = uVar28;
  *(undefined4 *)(this + 0xb4) = uVar30;
  *(undefined4 *)(this + 0xb8) = uVar31;
  *(undefined4 *)(this + 0xcc) = 0;
  TargetFollowCamera::setLookAtCam(param_4,true);
  pLVar20 = this + 0x90;
  iVar4 = Level::getPlayer(param_1);
  if (iVar4 == 0) {
    this[0x20] = (LevelScript)0x0;
  }
  else {
    puVar5 = (undefined4 *)Level::getPlayer(param_1);
    Player::setVulnerable((Player *)*puVar5,false);
  }
  pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
  PlayerEgo::setCollide(pPVar6,false);
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0) {
    *(undefined4 *)pLVar20 = 0;
    *(undefined4 *)(this + 0x94) = 0;
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    puVar5 = (undefined4 *)Level::getPlayer(param_1);
    Player::setVulnerable((Player *)*puVar5,true);
    this[0x21] = (LevelScript)0x1;
    TargetFollowCamera::setLookAtCam(param_4,true);
    local_d8 = -1000.0;
    local_d4 = -500.0;
    local_d0 = -40000.0;
    TargetFollowCamera::setPosition(param_4,(Vector *)&local_d8);
    Level::getPlayer(param_1);
    PlayerEgo::setPosition(extraout_s0_02,extraout_s1_02,extraout_s2_02);
    iVar4 = Level::getPlayer(param_1);
    local_d8 = 0.0;
    local_d4 = 0.0;
    local_d0 = 1.0;
    local_114 = 0;
    local_110 = 0x3f800000;
    local_10c = 0;
    AEGeometry::setDirection(*(AEGeometry **)(iVar4 + 8),(Vector *)&local_d8,(Vector *)&local_114);
    iVar4 = 0;
    do {
      iVar23 = Level::getEnemies(param_1);
      KIPlayer::setToSleep(*(KIPlayer **)(*(int *)(iVar23 + 4) + iVar4 * 4));
      iVar23 = Level::getEnemies(param_1);
      AEGeometry::setVisible(*(AEGeometry **)(*(int *)(*(int *)(iVar23 + 4) + iVar4 * 4) + 8),false)
      ;
      iVar23 = Level::getEnemies(param_1);
      *(undefined4 *)(*(int *)(*(int *)(iVar23 + 4) + iVar4 * 4) + 0x124) = 0;
      iVar18 = Level::getEnemies(param_1);
      iVar23 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *(undefined1 *)(*(int *)(*(int *)(*(int *)(iVar18 + 4) + iVar23) + 4) + 0x5c) = 0;
    } while (iVar4 != 3);
    LODManager::forceUpdate(*(LODManager **)param_1,0x1e,false);
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x3ab3,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xd8) = pAVar7;
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 1) {
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setRotation(pPVar6,extraout_s0,extraout_s1,extraout_s2);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setFreeze(pPVar6,true);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    Level::getPlayer(param_1);
    PlayerEgo::setPosition(extraout_s0_00,extraout_s1_00,extraout_s2_00);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setExhaustVisible(pPVar6,false);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::StopEngineSound(pPVar6);
    iVar4 = Level::getEnemies(param_1);
    KIPlayer::StopEngineSound((KIPlayer *)**(undefined4 **)(iVar4 + 4));
    TargetFollowCamera::setPosition(param_4,extraout_s0_01,extraout_s1_01,extraout_s2_01);
    this[0x21] = (LevelScript)0x1;
    TargetFollowCamera::setLookAtCam(param_4,true);
    iVar4 = Level::getPlayer(param_1);
    TargetFollowCamera::setTarget(param_4,*(AEGeometry **)(iVar4 + 8));
    Layout::startFade(Globals::layout,false,0xff,5000);
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar4 == 0x51) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 1)) {
    *(undefined4 *)pLVar20 = 0;
    *(undefined4 *)(this + 0x94) = 0;
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    iVar4 = Level::getPlayer(param_1);
    *(undefined1 *)(iVar4 + 0x24) = 1;
    puVar5 = (undefined4 *)Level::getPlayer(param_1);
    Player::setVulnerable((Player *)*puVar5,false);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setVisible(pPVar6,false);
    pFVar2 = Globals::sound;
    iVar4 = Level::getPlayer(param_1);
    FModSound::stop(pFVar2,*(int *)(iVar4 + 0x1c));
    this[0x21] = (LevelScript)0x1;
    TargetFollowCamera::setLookAtCam(param_4,true);
    local_d8 = -20000.0;
    local_d4 = 800.0;
    local_d0 = 120000.0;
    TargetFollowCamera::setPosition(param_4,(Vector *)&local_d8);
    Level::getPlayer(param_1);
    PlayerEgo::setPosition(extraout_s0_03,extraout_s1_03,extraout_s2_03);
    iVar4 = Level::getEnemies(param_1);
    AEGeometry::setVisible(*(AEGeometry **)(**(int **)(iVar4 + 4) + 0x13c),false);
    LODManager::forceUpdate(*(LODManager **)param_1,0x1e,false);
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x3ab3,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xd8) = pAVar7;
    AEGeometry::setScaling(pAVar7,extraout_s0_04,extraout_s1_04,extraout_s2_04);
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x4e) {
    TargetFollowCamera::setPosition(param_4,extraout_s0_05,extraout_s1_05,extraout_s2_05);
    *(undefined4 *)(this + 0x24) = 0;
    *(undefined2 *)(this + 0x20) = 0x100;
    iVar4 = Level::getPlayer(param_1);
    local_d8 = 0.0;
    local_d4 = 0.0;
    local_d0 = 1.0;
    local_114 = 0;
    local_110 = 0x3f800000;
    local_10c = 0;
    AEGeometry::setDirection(*(AEGeometry **)(iVar4 + 8),(Vector *)&local_d8,(Vector *)&local_114);
    *(undefined4 *)(this + 0x1c) = 1;
    this[0x11] = (LevelScript)0x1;
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x3ab3,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xd8) = pAVar7;
    AEGeometry::setScaling(pAVar7,extraout_s0_06,extraout_s1_06,extraout_s2_06);
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x59) {
    *(undefined4 *)pLVar20 = 0;
    *(undefined4 *)(this + 0x94) = 0;
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    iVar4 = Level::getPlayer(param_1);
    *(undefined1 *)(iVar4 + 0x24) = 1;
    puVar5 = (undefined4 *)Level::getPlayer(param_1);
    Player::setVulnerable((Player *)*puVar5,false);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setVisible(pPVar6,false);
    pFVar2 = Globals::sound;
    iVar4 = Level::getPlayer(param_1);
    FModSound::stop(pFVar2,*(int *)(iVar4 + 0x1c));
    this[0x21] = (LevelScript)0x1;
    TargetFollowCamera::setLookAtCam(param_4,true);
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,Globals::Canvas);
    *(AEGeometry **)(this + 0xcc) = pAVar7;
    iVar4 = Level::getEnemies(param_1);
    (**(code **)(**(int **)(*(int *)(iVar4 + 4) + 4) + 0x28))(&local_d8);
    AEGeometry::setPosition((Vector *)pAVar7);
    pAVar7 = *(AEGeometry **)(this + 0xcc);
    Level::getStarSystem(param_1);
    StarSystem::getLightDirection();
    AbyssEngine::AEMath::operator-((AEMath *)&local_d8,(Vector *)&local_114);
    local_48 = 0;
    local_44 = 0x3f800000;
    uStack_40 = 0;
    fVar26 = (float)AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,(Vector *)&local_48);
    AEGeometry::moveForward(*(AEGeometry **)(this + 0xcc),fVar26);
    pVVar25 = *(Vector **)(this + 0xcc);
    fVar26 = (float)AEGeometry::getRightVector();
    AbyssEngine::AEMath::operator*((AEMath *)&local_d8,(Vector *)&local_114,fVar26);
    AEGeometry::translate(pVVar25);
    TargetFollowCamera::setTarget(param_4,*(AEGeometry **)(this + 0xcc));
    iVar4 = Level::getEnemies(param_1);
    (**(code **)(**(int **)(*(int *)(iVar4 + 4) + 4) + 0x28))((Vector *)&local_d8);
    TargetFollowCamera::setPosition(param_4,(Vector *)&local_d8);
    TargetFollowCamera::translate(param_4,extraout_s0_07,extraout_s1_07,extraout_s2_07);
    iVar4 = Level::getEnemies(param_1);
    pVVar25 = *(Vector **)(**(int **)(iVar4 + 4) + 8);
    local_114 = 0xc6c35000;
    local_110 = 0x44480000;
    local_10c = 0x47ea6000;
    Level::getStarSystem(param_1);
    fVar26 = (float)StarSystem::getLightDirection();
    AbyssEngine::AEMath::operator*((AEMath *)&local_48,fVar26,(Vector *)0x447a0000);
    AbyssEngine::AEMath::operator+((AEMath *)&local_d8,(Vector *)&local_114,(Vector *)&local_48);
    AEGeometry::setPosition(pVVar25);
    iVar4 = Level::getEnemies(param_1);
    pAVar7 = *(AEGeometry **)(**(int **)(iVar4 + 4) + 8);
    Level::getStarSystem(param_1);
    StarSystem::getLightDirection();
    local_114 = 0;
    local_110 = 0x3f800000;
    local_10c = 0;
    AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,(Vector *)&local_114);
    iVar4 = Level::getEnemies(param_1);
    local_d8 = 3000.0;
    local_d4 = 0.0;
    local_d0 = 3000.0;
    AEGeometry::translate(*(Vector **)(**(int **)(iVar4 + 4) + 8));
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x3795,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xdc) = pAVar7;
    AEGeometry::setScaling(pAVar7,extraout_s0_08,extraout_s1_08,extraout_s2_08);
    *(undefined4 *)(this + 0x1c) = 1;
    LODManager::forceUpdate(*(LODManager **)param_1,0x1e,false);
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar4 == 0x69) && (iVar4 = Status::inSupernovaOrbit(Globals::status), iVar4 == 1)) {
    this[0x11] = (LevelScript)0x1;
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setCollide(pPVar6,false);
    *(undefined2 *)(this + 0x20) = 0x100;
    TargetFollowCamera::setLookAtCam(param_4,true);
    iVar4 = Level::getPlayer(param_1);
    TargetFollowCamera::setTarget(param_4,*(AEGeometry **)(iVar4 + 8));
    iVar4 = Level::getEnemies(param_1);
    (**(code **)(**(int **)(*(int *)(iVar4 + 4) + 4) + 0x28))((Vector *)&local_d8);
    TargetFollowCamera::setPosition(param_4,(Vector *)&local_d8);
    TargetFollowCamera::translate(param_4,extraout_s0_09,extraout_s1_09,extraout_s2_09);
    Level::getPlayer(param_1);
    PlayerEgo::getPosition();
    Level::getPlayer(param_1);
    fVar26 = (float)PlayerEgo::GetDirVector();
    AbyssEngine::AEMath::operator*((AEMath *)&local_54,(Vector *)&local_60,fVar26);
    AbyssEngine::AEMath::operator+((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
    Level::getPlayer(param_1);
    fVar26 = (float)PlayerEgo::GetUpVector();
    AbyssEngine::AEMath::operator*((AEMath *)&local_6c,(Vector *)&local_78,fVar26);
    AbyssEngine::AEMath::operator+((AEMath *)&local_d8,(Vector *)&local_114,(Vector *)&local_6c);
    TargetFollowCamera::setPosition(param_4,(Vector *)&local_d8);
    puVar5 = (undefined4 *)Level::getPlayer(param_1);
    Player::setVulnerable((Player *)*puVar5,true);
    if (Level::doInstantJump == '\0') {
      setAutoPilotToProgrammedStation(this);
    }
    *(undefined4 *)(this + 0x1c) = 1;
LAB_0015eed2:
    *(undefined4 *)pLVar20 = 0;
    *(undefined4 *)(this + 0x94) = 0;
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x6a) {
    Level::getPlayer(param_1);
    PlayerEgo::setPosition(extraout_s0_10,extraout_s1_10,extraout_s2_10);
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    iVar4 = Level::getPlayer(param_1);
    *(undefined1 *)(iVar4 + 0x24) = 1;
    puVar5 = (undefined4 *)Level::getPlayer(param_1);
    Player::setVulnerable((Player *)*puVar5,false);
    Level::getStarSystem(param_1);
    StarSystem::getLightDirection();
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
    iVar4 = Level::getPlayer(param_1);
    local_114 = 0;
    local_110 = 0x3f800000;
    local_10c = 0;
    AEGeometry::setDirection(*(AEGeometry **)(iVar4 + 8),(Vector *)&local_d8,(Vector *)&local_114);
    pFVar2 = Globals::sound;
    iVar4 = Level::getPlayer(param_1);
    FModSound::stop(pFVar2,*(int *)(iVar4 + 0x1c));
    this[0x21] = (LevelScript)0x1;
    TargetFollowCamera::setLookAtCam(param_4,true);
    Level::getPlayer(param_1);
    PlayerEgo::getPosition();
    local_54 = 0x45098000;
    local_50 = 0x44a28000;
    local_4c = 0xc57a0000;
    AbyssEngine::AEMath::operator+((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
    TargetFollowCamera::setPosition(param_4,(Vector *)&local_114);
    this[0x11] = (LevelScript)0x1;
    Layout::startFade(Globals::layout,false,-1,8000);
    *(undefined4 *)(this + 0x1c) = 1;
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x90) {
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,Globals::Canvas);
    *(AEGeometry **)(this + 0xcc) = pAVar7;
    AEGeometry::setPosition(extraout_s0_11,extraout_s1_11,extraout_s2_11);
    local_d8 = 1.0;
    local_d4 = 0.0;
    local_d0 = -1.0;
    local_114 = 0;
    local_110 = 0x3f800000;
    local_10c = 0;
    AEGeometry::setDirection(*(AEGeometry **)(this + 0xcc),(Vector *)&local_d8,(Vector *)&local_114)
    ;
    this[0x11] = (LevelScript)0x1;
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setCollide(pPVar6,false);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setActive(pPVar6,false);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setVisible(pPVar6,false);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setFreeze(pPVar6,true);
    *(undefined2 *)(this + 0x20) = 0x100;
    pFVar2 = Globals::sound;
    iVar4 = Level::getPlayer(param_1);
    FModSound::stop(pFVar2,*(int *)(iVar4 + 0x1c));
    TargetFollowCamera::setLookAtCam(param_4,true);
    TargetFollowCamera::setTarget(param_4,*(AEGeometry **)(this + 0xcc));
    iVar4 = Level::getEnemies(param_1);
    (**(code **)(*(int *)**(undefined4 **)(iVar4 + 4) + 0x28))((Vector *)&local_d8);
    AbyssEngine::AEMath::Vector::operator=(pVVar25,(Vector *)&local_d8);
    local_d8 = -4600.0;
    local_d4 = 1000.0;
    local_d0 = -4300.0;
    AbyssEngine::AEMath::Vector::operator+=(pVVar25,(Vector *)&local_d8);
    TargetFollowCamera::setPosition(param_4,pVVar25);
    if (Level::doInstantJump == '\0') {
      setAutoPilotToProgrammedStation(this);
    }
    *(undefined4 *)(this + 0x1c) = 1;
    *(undefined4 *)pLVar20 = 0;
    *(undefined4 *)(this + 0x94) = 0;
    goto LAB_0015f174;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar4 == 0x83) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
    pSVar12 = (Station *)Status::getStation(Globals::status);
    iVar4 = Station::getIndex(pSVar12);
    if (iVar4 == 0x70) {
      this[0x11] = (LevelScript)0x1;
      param_2[1] = (Hud)0x0;
      param_3[0x48] = (Radar)0x0;
      pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
      PlayerEgo::setComputerControlled(pPVar6,true);
      pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
      PlayerEgo::setCollide(pPVar6,false);
      Level::getPlayer(param_1);
      PlayerEgo::setPosition(extraout_s0_14,extraout_s1_14,extraout_s2_14);
      iVar4 = Level::getPlayer(param_1);
      pAVar7 = *(AEGeometry **)(iVar4 + 8);
      Level::getPlayer(param_1);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::operator-((AEMath *)&local_114,(Vector *)&local_48);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
      local_54 = 0;
      local_50 = 0x3f800000;
      local_4c = 0;
      AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,(Vector *)&local_54);
      *(undefined2 *)(this + 0x20) = 0x100;
      TargetFollowCamera::setLookAtCam(param_4,true);
      iVar4 = Level::getPlayer(param_1);
      TargetFollowCamera::setTarget(param_4,*(AEGeometry **)(iVar4 + 8));
      Level::getPlayer(param_1);
      PlayerEgo::getPosition();
      Level::getPlayer(param_1);
      fVar26 = (float)PlayerEgo::GetDirVector();
      AbyssEngine::AEMath::operator*((AEMath *)&local_60,(Vector *)&local_6c,fVar26);
      AbyssEngine::AEMath::operator-((AEMath *)&local_48,(Vector *)&local_54,(Vector *)&local_60);
      Level::getPlayer(param_1);
      fVar26 = (float)PlayerEgo::GetUpVector();
      AbyssEngine::AEMath::operator*((AEMath *)&local_78,aVStack_84,fVar26);
      AbyssEngine::AEMath::operator+((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_78);
      Level::getPlayer(param_1);
      fVar26 = (float)AEGeometry::getRightVector();
      AbyssEngine::AEMath::operator*(aAStack_90,aVStack_9c,fVar26);
      AbyssEngine::AEMath::operator-((AEMath *)&local_d8,(Vector *)&local_114,(Vector *)aAStack_90);
      TargetFollowCamera::setPosition(param_4,(Vector *)&local_d8);
      TargetFollowCamera::update(param_4,10);
      pPVar1 = Globals::Canvas;
      uVar22 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      pfVar13 = (float *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar22);
      local_d8 = *pfVar13;
      local_d4 = pfVar13[1];
      local_d0 = pfVar13[2];
      local_cc = pfVar13[3];
      fStack_c8 = pfVar13[4];
      local_c4 = pfVar13[5];
      fStack_c0 = pfVar13[6];
      fStack_bc = pfVar13[7];
      local_b8 = pfVar13[8];
      fStack_b4 = pfVar13[9];
      local_b0 = pfVar13[10];
      fStack_ac = pfVar13[0xb];
      local_a8 = pfVar13[0xc];
      fStack_a4 = pfVar13[0xd];
      fStack_a0 = pfVar13[0xe];
      AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_114,(AEMath *)&local_d8);
      AbyssEngine::AEMath::Vector::operator=(pVVar25,(Vector *)&local_114);
      TargetFollowCamera::setFixed(param_4,true);
      AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_114,(AEMath *)&local_d8,pVVar25);
      TargetFollowCamera::setLocal
                (param_4,local_d8,local_d4,local_d0,local_cc,fStack_c8,local_c4,fStack_c0,fStack_bc,
                 local_b8,fStack_b4,local_b0,fStack_ac,local_a8,fStack_a4,fStack_a0);
      if (Level::doInstantJump == '\0') {
        setAutoPilotToProgrammedStation(this);
      }
      *(undefined4 *)(this + 0x1c) = 1;
      goto LAB_0015eed2;
    }
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar4 == 0x9e) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
    pSVar12 = (Station *)Status::getStation(Globals::status);
    iVar4 = Station::getIndex(pSVar12);
    if (iVar4 == 0x6f) {
      pAVar7 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar7,Globals::Canvas);
      *(AEGeometry **)(this + 0xcc) = pAVar7;
      local_d8 = 1.0;
      local_d4 = 0.0;
      local_d0 = -1.0;
      local_114 = 0;
      local_110 = 0x3f800000;
      local_10c = 0;
      AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,(Vector *)&local_114);
      *(undefined2 *)(this + 0x20) = 0x100;
      Level::getPlayer(param_1);
      PlayerEgo::setPosition(extraout_s0_15,extraout_s1_15,extraout_s2_15);
      param_2[1] = (Hud)0x0;
      param_3[0x48] = (Radar)0x0;
      pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
      iVar23 = 1;
      PlayerEgo::setFreeze(pPVar6,true);
      puVar5 = (undefined4 *)Level::getPlayer(param_1);
      Player::setVulnerable((Player *)*puVar5,false);
      Level::getStarSystem(param_1);
      StarSystem::getLightDirection();
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
      iVar4 = Level::getPlayer(param_1);
      local_114 = 0;
      local_110 = 0x3f800000;
      local_10c = 0;
      AEGeometry::setDirection(*(AEGeometry **)(iVar4 + 8),(Vector *)&local_d8,(Vector *)&local_114)
      ;
      pFVar2 = Globals::sound;
      iVar4 = Level::getPlayer(param_1);
      FModSound::stop(pFVar2,*(int *)(iVar4 + 0x1c));
      this[0x21] = (LevelScript)0x1;
      TargetFollowCamera::setLookAtCam(param_4,true);
      Level::getPlayer(param_1);
      PlayerEgo::getPosition();
      local_54 = 0xc6dac000;
      local_50 = 0x43fa0000;
      local_4c = 0x4604d000;
      AbyssEngine::AEMath::operator+((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
      TargetFollowCamera::setPosition(param_4,(Vector *)&local_114);
      pVVar25 = *(Vector **)(this + 0xcc);
      TargetFollowCamera::getPosition(param_4);
      AEGeometry::setPosition(pVVar25);
      pAVar7 = *(AEGeometry **)(this + 0xcc);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_114,(Vector *)&local_d8);
      local_48 = 0;
      local_44 = 0x3f800000;
      uStack_40 = 0;
      fVar26 = (float)AEGeometry::setDirection(pAVar7,(Vector *)&local_114,(Vector *)&local_48);
      AEGeometry::moveForward(*(AEGeometry **)(this + 0xcc),fVar26);
      TargetFollowCamera::setTarget(param_4,*(AEGeometry **)(this + 0xcc));
      this[0x11] = (LevelScript)0x1;
      Layout::startFade(Globals::layout,false,-1,8000);
      iVar4 = Level::getEnemies(param_1);
      Player::setEnemies(*(Player **)(**(int **)(iVar4 + 4) + 4),(Array *)0x0);
      pPVar24 = *(Player **)(**(int **)(iVar4 + 4) + 4);
      puVar5 = (undefined4 *)Level::getPlayer(param_1);
      Player::addEnemy(pPVar24,(Player *)*puVar5);
      puVar5 = *(undefined4 **)(iVar4 + 4);
      fVar26 = 0.3;
      do {
        Player::setEnemies(*(Player **)(puVar5[iVar23] + 4),(Array *)0x0);
        pPVar24 = *(Player **)(*(int *)(*(int *)(iVar4 + 4) + iVar23 * 4) + 4);
        puVar5 = (undefined4 *)Level::getPlayer(param_1);
        Player::setEnemy(pPVar24,(Player *)*puVar5);
        puVar5 = *(undefined4 **)(iVar4 + 4);
        pPVar24 = *(Player **)(puVar5[iVar23] + 4);
        iVar18 = **(int **)(**(int **)(*(int *)pPVar24 + 4) + 4);
        fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(iVar18 + 0x60),
                                            (byte)(in_fpscr >> 0x16) & 3);
        *(int *)(iVar18 + 0x60) = (int)(fVar27 * fVar26);
        puVar17 = *(uint **)(param_1 + 0xb0);
        if ((puVar17 != (uint *)0x0) && (*puVar17 != 0)) {
          uVar22 = 0;
          while( true ) {
            Player::addEnemy(pPVar24,*(Player **)(*(int *)(puVar17[1] + uVar22 * 4) + 4));
            Player::addEnemy(*(Player **)
                              (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 4) + uVar22 * 4) + 4),
                             *(Player **)(*(int *)(*(int *)(iVar4 + 4) + iVar23 * 4) + 4));
            puVar17 = *(uint **)(param_1 + 0xb0);
            uVar22 = uVar22 + 1;
            puVar5 = *(undefined4 **)(iVar4 + 4);
            if (*puVar17 <= uVar22) break;
            pPVar24 = *(Player **)(puVar5[iVar23] + 4);
          }
        }
        iVar23 = iVar23 + 1;
      } while (iVar23 != 4);
      KIPlayer::setActive(SUB41(*puVar5,0));
      KIPlayer::setVisible((KIPlayer *)**(undefined4 **)(iVar4 + 4),false);
      uVar8 = Level::getPlayer(param_1);
      AEGeometry::getPosition();
      PlayerEgo::setPosition(uVar8,local_120,uStack_11c,uStack_118);
      iVar4 = Level::getPlayer(param_1);
      pAVar7 = *(AEGeometry **)(iVar4 + 8);
      pVVar25 = (Vector *)TargetFollowCamera::getPosition(param_4);
      AEGeometry::getPosition();
      AbyssEngine::AEMath::operator-((AEMath *)&local_54,pVVar25,(Vector *)&local_60);
      local_6c = 0x469c4000;
      uStack_68 = 0;
      local_64 = 0;
      AbyssEngine::AEMath::operator+((AEMath *)&local_48,(Vector *)&local_54,(Vector *)&local_6c);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_114,(Vector *)&local_48);
      local_78 = 0;
      local_74 = 0x3f800000;
      uStack_70 = 0;
      AEGeometry::setDirection(pAVar7,(Vector *)&local_114,(Vector *)&local_78);
      iVar4 = Level::getPlayer(param_1);
      AEGeometry::moveForward(*(AEGeometry **)(iVar4 + 8),extraout_s0_16);
      pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
      PlayerEgo::setSpeed(pPVar6,extraout_s0_17);
      *(undefined4 *)(this + 0x1c) = 1;
      goto LAB_0015f174;
    }
  }
  if (Level::initStreamOutPosition == '\0') {
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2000);
    uVar8 = VectorSignedToFloat(iVar4 + 500,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)pVVar25 = uVar8;
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2000);
    uVar8 = 0x460ca000;
  }
  else {
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,500);
    uVar8 = VectorSignedToFloat(iVar4 + 500,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)pVVar25 = uVar8;
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,500);
    uVar8 = 0x45dac000;
  }
  uVar28 = VectorSignedToFloat(iVar4 + 500,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0x2c) = uVar28;
  *(undefined4 *)(this + 0x30) = uVar8;
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
  if (iVar4 == 0) {
    *(float *)pVVar25 = -*(float *)pVVar25;
  }
  pVVar14 = (Vector *)(this + 0x34);
  iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
  if (iVar4 == 0) {
    *(float *)(this + 0x2c) = -*(float *)(this + 0x2c);
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x30) {
    Level::getPlayer(param_1);
    PlayerEgo::setPosition(extraout_s0_18,extraout_s1_16,extraout_s2_16);
    Level::getPlayer(param_1);
    AEGeometry::getDirection();
    local_d8 = local_d8 + 1e-05;
    iVar4 = Level::getPlayer(param_1);
    local_114 = 0;
    local_110 = 0x3f800000;
    local_10c = 0;
    AEGeometry::setDirection(*(AEGeometry **)(iVar4 + 8),(Vector *)&local_d8,(Vector *)&local_114);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    iVar4 = Level::getLandmarks(param_1);
    PlayerEgo::setAutoPilot(pPVar6,(KIPlayer *)**(undefined4 **)(iVar4 + 4));
  }
  else {
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar4 == 0x41) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
      pSVar12 = (Station *)Status::getStation(Globals::status);
      iVar4 = Station::getIndex(pSVar12);
      pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar23 = Mission::getTargetStation(pMVar11);
      if (iVar4 == iVar23) {
        Level::getPlayer(param_1);
        PlayerEgo::setPosition(extraout_s0_19,extraout_s1_17,extraout_s2_17);
        iVar4 = Level::getPlayer(param_1);
        pAVar7 = *(AEGeometry **)(iVar4 + 8);
        Level::getPlayer(param_1);
        PlayerEgo::getPosition();
        AbyssEngine::AEMath::operator-((AEMath *)&local_114,(Vector *)&local_48);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
        local_54 = 0;
        local_50 = 0x3f800000;
        local_4c = 0;
        AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,(Vector *)&local_54);
        Level::getPlayer(param_1);
        PlayerEgo::getPosition();
        local_d8 = local_d8 + -3000.0;
        iVar4 = Level::getEnemies(param_1);
        (**(code **)(*(int *)**(undefined4 **)(iVar4 + 4) + 0x48))
                  ((int *)**(undefined4 **)(iVar4 + 4),local_d8,local_d4,local_d0);
        iVar4 = Level::getEnemies(param_1);
        local_114 = 0;
        local_110 = 0x40490fdb;
        local_10c = 0;
        AEGeometry::setRotation(*(Vector **)(**(int **)(iVar4 + 4) + 8));
        goto LAB_001604c4;
      }
    }
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar4 == 0x57) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
      pSVar12 = (Station *)Status::getStation(Globals::status);
      iVar4 = Station::getIndex(pSVar12);
      pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar23 = Mission::getTargetStation(pMVar11);
      if (iVar4 != iVar23) goto LAB_001601a0;
      Level::getPlayer(param_1);
      fVar26 = extraout_s0_20;
      fVar27 = extraout_s1_18;
      fVar29 = extraout_s2_18;
LAB_00160470:
      PlayerEgo::setPosition(fVar26,fVar27,fVar29);
      iVar4 = Level::getPlayer(param_1);
      pAVar7 = *(AEGeometry **)(iVar4 + 8);
      Level::getPlayer(param_1);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::operator-((AEMath *)&local_114,(Vector *)&local_48);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
LAB_001604b8:
      local_4c = 0;
      local_50 = 0x3f800000;
      local_54 = 0;
      pVVar19 = (Vector *)&local_54;
    }
    else {
LAB_001601a0:
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar4 == 0x5b) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
        pSVar12 = (Station *)Status::getStation(Globals::status);
        iVar4 = Station::getIndex(pSVar12);
        pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar23 = Mission::getTargetStation(pMVar11);
        if (iVar4 == iVar23) {
          Level::getPlayer(param_1);
          fVar26 = extraout_s0_21;
          fVar27 = extraout_s1_19;
          fVar29 = extraout_s2_19;
          goto LAB_00160470;
        }
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar4 != 0x5c) || (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 != 0)) {
LAB_001602b2:
        iVar4 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar4 == 0x66) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
          pSVar12 = (Station *)Status::getStation(Globals::status);
          iVar4 = Station::getIndex(pSVar12);
          pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar23 = Mission::getTargetStation(pMVar11);
          if (iVar4 != iVar23) goto LAB_0016035e;
          Level::getPlayer(param_1);
          PlayerEgo::setPosition(extraout_s0_23,extraout_s1_21,extraout_s2_21);
          iVar4 = Level::getPlayer(param_1);
          pAVar7 = *(AEGeometry **)(iVar4 + 8);
          Level::getPlayer(param_1);
          PlayerEgo::getPosition();
          AbyssEngine::AEMath::operator-((AEMath *)&local_114,(Vector *)&local_48);
          AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
          goto LAB_001604b8;
        }
LAB_0016035e:
        iVar4 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar4 == 0x7b) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
          pSVar12 = (Station *)Status::getStation(Globals::status);
          iVar4 = Station::getIndex(pSVar12);
          pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar23 = Mission::getTargetStation(pMVar11);
          if (iVar4 == iVar23) {
            Level::getPlayer(param_1);
            fVar26 = extraout_s0_24;
            fVar27 = extraout_s1_22;
            fVar29 = extraout_s2_22;
            goto LAB_00160470;
          }
        }
        iVar4 = Status::getCurrentCampaignMission(Globals::status);
        if (((0x54 < iVar4) ||
            (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x87)) &&
           (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
          pSVar12 = (Station *)Status::getStation(Globals::status);
          iVar4 = Station::getIndex(pSVar12);
          if (iVar4 == 0x67) {
            Level::getPlayer(param_1);
            fVar26 = extraout_s0_25;
            fVar27 = extraout_s1_23;
            fVar29 = extraout_s2_23;
            goto LAB_00160470;
          }
        }
        iVar4 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar4 == 0x72) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
          pSVar12 = (Station *)Status::getStation(Globals::status);
          iVar4 = Station::getIndex(pSVar12);
          pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar23 = Mission::getTargetStation(pMVar11);
          if (iVar4 == iVar23) {
            Level::getPlayer(param_1);
            fVar26 = extraout_s0_26;
            fVar27 = extraout_s1_24;
            fVar29 = extraout_s2_24;
            goto LAB_00160470;
          }
        }
        iVar4 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar4 == 0x89) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
          pSVar12 = (Station *)Status::getStation(Globals::status);
          iVar4 = Station::getIndex(pSVar12);
          pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar23 = Mission::getTargetStation(pMVar11);
          if (iVar4 == iVar23) {
            Level::getPlayer(param_1);
            fVar26 = extraout_s0_27;
            fVar27 = extraout_s1_25;
            fVar29 = extraout_s2_25;
            goto LAB_00160470;
          }
        }
        iVar4 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar4 == 0x8b) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
          pSVar12 = (Station *)Status::getStation(Globals::status);
          iVar4 = Station::getIndex(pSVar12);
          pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar23 = Mission::getTargetStation(pMVar11);
          if (iVar4 != iVar23) goto LAB_0016070a;
          Level::getPlayer(param_1);
          PlayerEgo::setPosition(extraout_s0_28,extraout_s1_26,extraout_s2_26);
          iVar4 = Level::getPlayer(param_1);
          pAVar7 = *(AEGeometry **)(iVar4 + 8);
          iVar4 = Level::getEnemies(param_1);
          (**(code **)(**(int **)(*(int *)(iVar4 + 4) + 4) + 0x28))((Vector *)&local_48);
          Level::getPlayer(param_1);
          PlayerEgo::getPosition();
          AbyssEngine::AEMath::operator-
                    ((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
          AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
          local_60 = 0;
          local_5c = 0x3f800000;
          uStack_58 = 0;
          pVVar19 = (Vector *)&local_60;
LAB_00160890:
          AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,pVVar19);
        }
        else {
LAB_0016070a:
          iVar4 = Status::getCurrentCampaignMission(Globals::status);
          if ((iVar4 == 0x8e) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
            pSVar12 = (Station *)Status::getStation(Globals::status);
            iVar4 = Station::getIndex(pSVar12);
            pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
            iVar23 = Mission::getTargetStation(pMVar11);
            if (iVar4 == iVar23) {
              Level::getPlayer(param_1);
              PlayerEgo::setPosition(extraout_s0_29,extraout_s1_27,extraout_s2_27);
              iVar4 = Level::getPlayer(param_1);
              pAVar7 = *(AEGeometry **)(iVar4 + 8);
              pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
              this_04 = (Route *)PlayerEgo::getRoute(pPVar6);
              piVar15 = (int *)Route::getWaypoint(this_04,0);
              (**(code **)(*piVar15 + 0x28))((Vector *)&local_48);
              Level::getPlayer(param_1);
              PlayerEgo::getPosition();
              AbyssEngine::AEMath::operator-
                        ((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
              AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
              local_60 = 0;
              local_5c = 0x3f800000;
              uStack_58 = 0;
              AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,(Vector *)&local_60);
              iVar4 = Level::getEnemies(param_1);
              piVar15 = (int *)**(undefined4 **)(iVar4 + 4);
              pcVar16 = *(code **)(*piVar15 + 0x44);
              Level::getPlayer(param_1);
              PlayerEgo::getPosition();
              Level::getPlayer(param_1);
              fVar26 = (float)AEGeometry::getRightVector();
              AbyssEngine::AEMath::operator*((AEMath *)&local_54,(Vector *)&local_60,fVar26);
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
              Level::getPlayer(param_1);
              fVar26 = (float)AEGeometry::getDirection();
              AbyssEngine::AEMath::operator*((AEMath *)&local_6c,(Vector *)&local_78,fVar26);
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_d8,(Vector *)&local_114,(Vector *)&local_6c);
              (*pcVar16)(piVar15,(AEMath *)&local_d8);
              iVar4 = Level::getEnemies(param_1);
              pAVar7 = *(AEGeometry **)(**(int **)(iVar4 + 4) + 8);
              Level::getPlayer(param_1);
              PlayerEgo::GetDirVector();
              local_114 = 0;
              pVVar19 = (Vector *)&local_114;
              local_110 = 0x3f800000;
              local_10c = 0;
              goto LAB_00160890;
            }
          }
          iVar4 = Status::inAlienOrbit(Globals::status);
          if ((iVar4 == 1) &&
             (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x9a)) {
            Level::getPlayer(param_1);
            PlayerEgo::setPosition(extraout_s0_30,extraout_s1_28,extraout_s2_28);
            iVar4 = Level::getEnemies(param_1);
            piVar15 = (int *)**(undefined4 **)(iVar4 + 4);
            pcVar16 = *(code **)(*piVar15 + 0x44);
            Level::getPlayer(param_1);
            PlayerEgo::getPosition();
            Level::getPlayer(param_1);
            fVar26 = (float)AEGeometry::getRightVector();
            AbyssEngine::AEMath::operator*((AEMath *)&local_54,(Vector *)&local_60,fVar26);
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
            Level::getPlayer(param_1);
            fVar26 = (float)AEGeometry::getDirection();
            AbyssEngine::AEMath::operator*((AEMath *)&local_6c,(Vector *)&local_78,fVar26);
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_d8,(Vector *)&local_114,(Vector *)&local_6c);
            (*pcVar16)(piVar15,(AEMath *)&local_d8);
            iVar4 = Level::getEnemies(param_1);
            pAVar7 = *(AEGeometry **)(**(int **)(iVar4 + 4) + 8);
            Level::getPlayer(param_1);
            PlayerEgo::GetDirVector();
            local_114 = 0;
            local_110 = 0x3f800000;
            local_10c = 0;
            AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,(Vector *)&local_114);
            iVar4 = Level::getEnemies(param_1);
            pPVar24 = *(Player **)(**(int **)(iVar4 + 4) + 4);
            iVar4 = Level::getEnemies(param_1);
            Player::setEnemy(pPVar24,*(Player **)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4));
            piVar15 = (int *)Level::getEnemies(param_1);
            if (*piVar15 != 0) {
              uVar22 = 0;
              do {
                iVar4 = Level::getEnemies(param_1);
                if (*(char *)(*(int *)(*(int *)(iVar4 + 4) + uVar22 * 4) + 0x3a) != '\0') {
                  iVar4 = Level::getEnemies(param_1);
                  Player::setEnemies(*(Player **)(*(int *)(*(int *)(iVar4 + 4) + uVar22 * 4) + 4),
                                     (Array *)0x0);
                }
                iVar4 = Level::getEnemies(param_1);
                if (*(int *)(*(int *)(*(int *)(iVar4 + 4) + uVar22 * 4) + 0x24) == 9) {
                  iVar4 = Level::getEnemies(param_1);
                  *(undefined1 *)(*(int *)(*(int *)(iVar4 + 4) + uVar22 * 4) + 0x21) = 0;
                }
                puVar17 = (uint *)Level::getEnemies(param_1);
                uVar22 = uVar22 + 1;
              } while (uVar22 < *puVar17);
            }
          }
        }
        goto LAB_001604c4;
      }
      pSVar12 = (Station *)Status::getStation(Globals::status);
      iVar4 = Station::getIndex(pSVar12);
      pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar23 = Mission::getTargetStation(pMVar11);
      if (iVar4 != iVar23) goto LAB_001602b2;
      Level::getPlayer(param_1);
      PlayerEgo::setPosition(extraout_s0_22,extraout_s1_20,extraout_s2_20);
      iVar4 = Level::getPlayer(param_1);
      pAVar7 = *(AEGeometry **)(iVar4 + 8);
      iVar4 = Level::getEnemies(param_1);
      (**(code **)(**(int **)(*(int *)(iVar4 + 4) + 0xc) + 0x28))((Vector *)&local_48);
      Level::getPlayer(param_1);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::operator-((AEMath *)&local_114,(Vector *)&local_48,(Vector *)&local_54);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_d8,(Vector *)&local_114);
      local_60 = 0;
      pVVar19 = (Vector *)&local_60;
      local_5c = 0x3f800000;
      uStack_58 = 0;
    }
    AEGeometry::setDirection(pAVar7,(Vector *)&local_d8,pVVar19);
  }
LAB_001604c4:
  iVar4 = Level::getPlayer(param_1);
  pfVar13 = (float *)AEGeometry::getMatrix(*(AEGeometry **)(iVar4 + 8));
  local_d8 = *pfVar13;
  local_d4 = pfVar13[1];
  local_d0 = pfVar13[2];
  local_cc = pfVar13[3];
  fStack_c8 = pfVar13[4];
  local_c4 = pfVar13[5];
  fStack_c0 = pfVar13[6];
  fStack_bc = pfVar13[7];
  local_b8 = pfVar13[8];
  fStack_b4 = pfVar13[9];
  local_b0 = pfVar13[10];
  fStack_ac = pfVar13[0xb];
  local_a8 = pfVar13[0xc];
  fStack_a4 = pfVar13[0xd];
  fStack_a0 = pfVar13[0xe];
  AbyssEngine::AEMath::MatrixRotateVector((AEMath *)&local_114,(Matrix *)&local_d8,pVVar25);
  AbyssEngine::AEMath::Vector::operator=(pVVar14,(Vector *)&local_114);
  Level::getPlayer(param_1);
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator+=(pVVar14,(Vector *)&local_114);
  TargetFollowCamera::setPosition(param_4,pVVar14);
  iVar4 = Status::inAlienOrbit(Globals::status);
  if ((Level::comingFromAlienWorld != '\0') || (iVar4 == 1)) {
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar4 < 0x2b) {
      pVVar14 = (Vector *)(this + 0x40);
      Level::getPlayer(param_1);
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::Vector::operator=(pVVar25,(Vector *)&local_114);
      Level::getPlayer(param_1);
      AEGeometry::getDirection();
      fVar26 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar14,(Vector *)&local_114);
      AbyssEngine::AEMath::Vector::operator*=(pVVar14,fVar26);
      AbyssEngine::AEMath::Vector::operator-=(pVVar25,pVVar14);
      iVar4 = Level::getLandmarks(param_1);
      PlayerWormHole::reset(*(PlayerWormHole **)(*(int *)(iVar4 + 4) + 0xc),true);
      iVar4 = Level::getLandmarks(param_1);
      piVar15 = *(int **)(*(int *)(iVar4 + 4) + 0xc);
      (**(code **)(*piVar15 + 0x48))
                (piVar15,*(undefined4 *)(this + 0x28),*(undefined4 *)(this + 0x2c),
                 *(undefined4 *)(this + 0x30));
      iVar4 = Level::getLandmarks(param_1);
      KIPlayer::setVisible(*(KIPlayer **)(*(int *)(iVar4 + 4) + 0xc),true);
    }
    Level::comingFromAlienWorld = '\0';
  }
LAB_0015f174:
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x50) {
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x3822,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xb8) = pAVar7;
    iVar4 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(pAVar7 + 0xc))
    ;
    *(undefined4 *)(iVar4 + 0xe0) = 0x49742400;
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xb8) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
    AEGeometry::setVisible(*(AEGeometry **)(this + 0xb8),false);
    local_d8 = 0.0;
    local_d4 = 3.1415927;
    local_d0 = 0.0;
    AEGeometry::setRotation(*(Vector **)(this + 0xb8));
    iVar4 = Level::getLandmarks(param_1);
    iVar4 = *(int *)(**(int **)(iVar4 + 4) + 0x13c);
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(iVar4 + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(iVar4 + 0x14))
    ;
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,*(uint *)(iVar4 + 0x10))
    ;
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
    pPVar1 = Globals::Canvas;
    iVar4 = Level::getLandmarks(param_1);
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (pPVar1,*(uint *)(**(int **)(iVar4 + 4) + 0x140));
    AbyssEngine::Transform::SetAnimationState(uVar8,2,0);
    this_00 = operator_new(0x68);
    Explosion::Explosion(this_00,0);
    *(Explosion **)(this + 200) = this_00;
    fVar26 = (float)Explosion::addFireStreaks(this_00);
    Explosion::setScaling(fVar26);
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,Globals::Canvas);
    *(AEGeometry **)(this + 0xdc) = pAVar7;
    AEGeometry::setVisible(pAVar7,false);
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x381e,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xbc) = pAVar7;
    Level::getEnemies(param_1);
    AEGeometry::getPosition();
    AEGeometry::setPosition((Vector *)pAVar7);
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x3ab3,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xd8) = pAVar7;
    AEGeometry::setScaling(pAVar7,extraout_s0_12,extraout_s1_12,extraout_s2_12);
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if ((iVar4 == 0x29) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 1)) {
    pPVar21 = *(ParticleSystemManager **)(param_1 + 0x74);
    iVar4 = Level::getEnemies(param_1);
    uVar8 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(**(int **)(iVar4 + 4) + 8));
    iVar4 = ParticleSystemManager::addSystem(pPVar21,uVar8,0x28,0);
    *(int *)(this + 0xe0) = iVar4;
    ParticleSystemManager::enableSystemEmit(*(ParticleSystemManager **)(param_1 + 0x74),iVar4,false)
    ;
    pPVar21 = *(ParticleSystemManager **)(param_1 + 0x74);
    iVar4 = Level::getEnemies(param_1);
    uVar8 = AEGeometry::getReferenceMatrix(*(AEGeometry **)(**(int **)(iVar4 + 4) + 8));
    iVar4 = ParticleSystemManager::addSystem(pPVar21,uVar8,0x29,0);
    *(int *)(this + 0xe4) = iVar4;
    ParticleSystemManager::enableSystemEmit(*(ParticleSystemManager **)(param_1 + 0x74),iVar4,false)
    ;
    LODManager::forceUpdate(*(LODManager **)param_1,0x1e,false);
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x37cd,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xac) = pAVar7;
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x37ce,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xb0) = pAVar7;
    pAVar7 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar7,0x37cf,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xb4) = pAVar7;
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xac) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xb0) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
    uVar8 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xb4) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar8,1,0);
  }
  else {
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar4 == 0x9d) && (iVar4 = Status::inAlienOrbit(Globals::status), iVar4 == 0)) {
      pSVar12 = (Station *)Status::getStation(Globals::status);
      iVar4 = Station::getIndex(pSVar12);
      pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar23 = Mission::getTargetStation(pMVar11);
      if (iVar4 == iVar23) {
        pAVar7 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar7,0x4a75,Globals::Canvas,false);
        *(AEGeometry **)(this + 0xbc) = pAVar7;
        pAVar7 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar7,0x4a76,Globals::Canvas,false);
        this_01 = operator_new(0xc0);
        AEGeometry::AEGeometry(this_01,0x4a77,Globals::Canvas,false);
        AEGeometry::addChild(*(AEGeometry **)(this + 0xbc),*(uint *)(pAVar7 + 0xc));
        AEGeometry::addChild(*(AEGeometry **)(this + 0xbc),*(uint *)(this_01 + 0xc));
        pAVar9 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar9,0x4a97,Globals::Canvas,false);
        *(AEGeometry **)(this + 0xc0) = pAVar9;
        pAVar9 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar9,0x4a99,Globals::Canvas,false);
        *(AEGeometry **)(this + 0xc4) = pAVar9;
        pAVar9 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar9,0x4a98,Globals::Canvas,false);
        this_02 = operator_new(0xc0);
        AEGeometry::AEGeometry(this_02,0x4a9a,Globals::Canvas,false);
        AEGeometry::addChild(*(AEGeometry **)(this + 0xc0),*(uint *)(pAVar9 + 0xc));
        AEGeometry::addChild(*(AEGeometry **)(this + 0xc4),*(uint *)(this_02 + 0xc));
        this_03 = (Transform *)
                  AbyssEngine::PaintCanvas::TransformGetTransform
                            (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
        AbyssEngine::Transform::SetVisible(this_03,false);
        AEGeometry::setVisible(*(AEGeometry **)(this + 0xc0),false);
        AEGeometry::setVisible(*(AEGeometry **)(this + 0xc4),false);
        pvVar10 = (void *)AEGeometry::~AEGeometry(pAVar7);
        operator_delete(pvVar10);
        pvVar10 = (void *)AEGeometry::~AEGeometry(this_01);
        operator_delete(pvVar10);
        pvVar10 = (void *)AEGeometry::~AEGeometry(pAVar9);
        operator_delete(pvVar10);
        pvVar10 = (void *)AEGeometry::~AEGeometry(this_02);
        operator_delete(pvVar10);
      }
    }
  }
  Layout::enableFillScreen(Globals::layout,false);
  iVar4 = Status::inAlienOrbit(Globals::status);
  if ((iVar4 == 0) && (iVar4 = Status::getCampaignMission(Globals::status), iVar4 != 0)) {
    pMVar11 = (Mission *)Status::getCampaignMission(Globals::status);
    iVar4 = Mission::getType(pMVar11);
    if ((iVar4 == 0xa3) &&
       ((puVar17 = *(uint **)(Globals::status + 0x90), puVar17 != (uint *)0x0 && (*puVar17 != 0))))
    {
      uVar22 = 0;
      do {
        iVar23 = *(int *)(puVar17[1] + uVar22 * 4);
        pSVar12 = (Station *)Status::getStation(Globals::status);
        iVar4 = Station::getIndex(pSVar12);
        if (iVar23 == iVar4) {
          this[0xa9] = (LevelScript)0x1;
          break;
        }
        uVar22 = uVar22 + 1;
        puVar17 = *(uint **)(Globals::status + 0x90);
      } while (uVar22 < *puVar17);
    }
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (((((iVar4 == 0x5f) ||
        (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 99)) ||
       (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x6d)) ||
      ((iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x77 ||
       (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x7e)))) ||
     ((iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0x85 ||
      ((iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0xa0 ||
       (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 == 0xa1)))))) {
    param_2[1] = (Hud)0x0;
    param_3[0x48] = (Radar)0x0;
    this[0x11] = (LevelScript)0x1;
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setComputerControlled(pPVar6,true);
    iVar4 = Level::getPlayer(param_1);
    *(undefined1 *)(iVar4 + 0x24) = 1;
    puVar5 = (undefined4 *)Level::getPlayer(param_1);
    Player::setVulnerable((Player *)*puVar5,false);
    pPVar6 = (PlayerEgo *)Level::getPlayer(param_1);
    PlayerEgo::setVisible(pPVar6,false);
    pFVar2 = Globals::sound;
    iVar4 = Level::getPlayer(param_1);
    FModSound::stop(pFVar2,*(int *)(iVar4 + 0x1c));
    this[0x21] = (LevelScript)0x1;
    TargetFollowCamera::setLookAtCam(param_4,true);
    local_d8 = -15000.0;
    local_d4 = 800.0;
    local_d0 = 75000.0;
    TargetFollowCamera::setPosition(param_4,(Vector *)&local_d8);
    Level::getPlayer(param_1);
    PlayerEgo::setPosition(extraout_s0_13,extraout_s1_13,extraout_s2_13);
    LODManager::forceUpdate(*(LODManager **)param_1,0x1e,false);
    *(undefined4 *)pLVar20 = 0;
    *(undefined4 *)(this + 0x94) = 0;
  }
  if (__stack_chk_guard - local_3c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_3c);
}

// ===== LevelScript::setAutoPilotToProgrammedStation  @0x00160b50  (252 bytes)
/* LevelScript::setAutoPilotToProgrammedStation() */

void __thiscall LevelScript::setAutoPilotToProgrammedStation(LevelScript *this)

{
  Station *this_00;
  int iVar1;
  SolarSystem *pSVar2;
  PlayerEgo *this_01;
  StarSystem *pSVar3;
  int iVar4;
  KIPlayer *pKVar5;
  
  if (Level::programmedStation != (Station *)0x0) {
    this_00 = (Station *)Status::getStation(Globals::status);
    iVar1 = Station::equals(this_00,Level::programmedStation);
    if (iVar1 != 1) {
      pSVar2 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar1 = SolarSystem::stationIsInSystem(pSVar2,Level::programmedStation);
      if (iVar1 == 1) {
        this_01 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
        pSVar3 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
        iVar1 = StarSystem::getPlanetTargets(pSVar3);
        pSVar2 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar4 = Station::getIndex(Level::programmedStation);
        iVar4 = SolarSystem::getStationEnumIndex(pSVar2,iVar4);
        pKVar5 = *(KIPlayer **)(*(int *)(iVar1 + 4) + iVar4 * 4);
      }
      else {
        pSVar2 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar1 = SolarSystem::currentOrbitHasWarpGate(pSVar2);
        if (iVar1 == 1) {
          this_01 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
          iVar1 = Level::getLandmarks(*(Level **)(this + 0x18));
          pKVar5 = *(KIPlayer **)(*(int *)(iVar1 + 4) + 4);
        }
        else {
          pSVar2 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar1 = SolarSystem::getWarpGateEnumIndex(pSVar2);
          if (iVar1 < 0) {
            return;
          }
          this_01 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
          pSVar3 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
          iVar4 = StarSystem::getPlanetTargets(pSVar3);
          pKVar5 = *(KIPlayer **)(*(int *)(iVar4 + 4) + iVar1 * 4);
        }
      }
      PlayerEgo::setAutoPilot(this_01,pKVar5);
      return;
    }
    Level::programmedStation = (Station *)0x0;
  }
  return;
}

// ===== LevelScript::~LevelScript  @0x00160c74  (220 bytes)
/* LevelScript::~LevelScript() */

LevelScript * __thiscall LevelScript::~LevelScript(LevelScript *this)

{
  void *pvVar1;
  
  if (*(AEGeometry **)(this + 0xdc) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xdc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xdc) = 0;
  if (*(AEGeometry **)(this + 0xd8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xd8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xd8) = 0;
  if (*(AEGeometry **)(this + 0xb8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xb8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xb8) = 0;
  if (*(AEGeometry **)(this + 0xbc) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xbc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xbc) = 0;
  if (*(AEGeometry **)(this + 0xc0) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xc0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc0) = 0;
  if (*(AEGeometry **)(this + 0xc4) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xc4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc4) = 0;
  if (*(AEGeometry **)(this + 0xac) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xac));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xac) = 0;
  if (*(AEGeometry **)(this + 0xb0) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xb0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xb0) = 0;
  if (*(AEGeometry **)(this + 0xb4) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xb4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xb4) = 0;
  if (*(Explosion **)(this + 200) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 200));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 200) = 0;
  if (*(AEGeometry **)(this + 0xcc) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xcc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xcc) = 0;
  return this;
}

// ===== LevelScript::process  @0x00160d50  (57020 bytes)
/* LevelScript::process(int) */

void __thiscall LevelScript::process(LevelScript *this,int param_1)

{
  LevelScript *pLVar1;
  byte bVar2;
  PaintCanvas *pPVar3;
  LevelScript LVar4;
  uint *puVar5;
  PlayerEgo *this_00;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  PlayerEgo *pPVar10;
  Station *pSVar11;
  Mission *pMVar12;
  int iVar13;
  String *pSVar14;
  ulonglong *puVar15;
  Standing *this_01;
  void *pvVar16;
  Objective *pOVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined8 *puVar21;
  PlayerFighter *pPVar22;
  LevelScript *pLVar23;
  Ship *pSVar24;
  float *pfVar25;
  Array *pAVar26;
  Route *pRVar27;
  int *piVar28;
  undefined4 uVar29;
  Route *pRVar30;
  StarSystem *pSVar31;
  Station *pSVar32;
  Status *pSVar33;
  SolarSystem *pSVar34;
  Transform *pTVar35;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int extraout_r1_01;
  undefined4 extraout_r1_02;
  int iVar36;
  int iVar37;
  TargetFollowCamera *pTVar38;
  ParticleSystemManager *pPVar39;
  PlayerFixedObject *pPVar40;
  Player *pPVar41;
  Explosion *pEVar42;
  Level *pLVar43;
  KIPlayer *pKVar44;
  Matrix *pMVar45;
  uint uVar46;
  uint uVar47;
  Vector *pVVar48;
  Vector *pVVar49;
  int iVar50;
  code *pcVar51;
  AEGeometry *pAVar52;
  uint uVar53;
  bool bVar54;
  bool bVar55;
  uint in_fpscr;
  float fVar56;
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
  float extraout_s0_11;
  float extraout_s0_12;
  float extraout_s0_13;
  float extraout_s0_14;
  float extraout_s0_15;
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
  float extraout_s1_11;
  float extraout_s1_12;
  float extraout_s1_13;
  float extraout_s1_14;
  float extraout_s1_15;
  float extraout_s1_16;
  float extraout_s1_17;
  float extraout_s1_18;
  float extraout_s1_19;
  float extraout_s1_20;
  float extraout_s1_21;
  float extraout_s1_22;
  float extraout_s1_23;
  float extraout_s1_24;
  float extraout_s1_25;
  float extraout_s1_26;
  float extraout_s1_27;
  float extraout_s1_28;
  float extraout_s1_29;
  float extraout_s1_30;
  float extraout_s1_31;
  float extraout_s1_32;
  float extraout_s1_33;
  float extraout_s1_34;
  float extraout_s1_35;
  float extraout_s1_36;
  float extraout_s1_37;
  float extraout_s1_38;
  float extraout_s1_39;
  float extraout_s1_40;
  float extraout_s1_41;
  float extraout_s1_42;
  float extraout_s1_43;
  float extraout_s1_44;
  float extraout_s1_45;
  float extraout_s1_46;
  float extraout_s1_47;
  float extraout_s1_48;
  float extraout_s1_49;
  float extraout_s1_50;
  float extraout_s1_51;
  float extraout_s1_52;
  float extraout_s1_53;
  float extraout_s1_54;
  float extraout_s1_55;
  float extraout_s1_56;
  float extraout_s1_57;
  float extraout_s1_58;
  float extraout_s1_59;
  float extraout_s1_60;
  float extraout_s1_61;
  float extraout_s1_62;
  float extraout_s1_63;
  float extraout_s1_64;
  float extraout_s1_65;
  float extraout_s1_66;
  float extraout_s1_67;
  float extraout_s1_68;
  float extraout_s1_69;
  float extraout_s1_70;
  float extraout_s1_71;
  float extraout_s1_72;
  float extraout_s1_73;
  float extraout_s1_74;
  float extraout_s1_75;
  float extraout_s1_76;
  float extraout_s1_77;
  float extraout_s1_78;
  float extraout_s1_79;
  float extraout_s1_80;
  float extraout_s1_81;
  undefined4 extraout_s1_82;
  float extraout_s1_83;
  float extraout_s1_84;
  float extraout_s1_85;
  undefined4 extraout_s1_86;
  float extraout_s1_87;
  float extraout_s1_88;
  float extraout_s1_89;
  float extraout_s1_90;
  float extraout_s1_91;
  float extraout_s1_92;
  float extraout_s1_93;
  float extraout_s1_94;
  float extraout_s1_95;
  float extraout_s1_96;
  float extraout_s1_97;
  float extraout_s1_98;
  float extraout_s1_99;
  float extraout_s1_x00100;
  float extraout_s1_x00101;
  undefined4 extraout_s1_x00102;
  undefined4 extraout_s1_x00103;
  float extraout_s1_x00104;
  float extraout_s1_x00105;
  float extraout_s1_x00106;
  float extraout_s1_x00107;
  float extraout_s1_x00108;
  float extraout_s1_x00109;
  float extraout_s1_x00110;
  float extraout_s1_x00111;
  float extraout_s1_x00112;
  float extraout_s1_x00113;
  float extraout_s1_x00114;
  float extraout_s1_x00115;
  float extraout_s1_x00116;
  float extraout_s1_x00117;
  float extraout_s1_x00118;
  float extraout_s1_x00119;
  float extraout_s1_x00120;
  float extraout_s1_x00121;
  float extraout_s1_x00122;
  float extraout_s1_x00123;
  float extraout_s1_x00124;
  float fVar57;
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
  float extraout_s2_11;
  float extraout_s2_12;
  float extraout_s2_13;
  float extraout_s2_14;
  float extraout_s2_15;
  float extraout_s2_16;
  float extraout_s2_17;
  float extraout_s2_18;
  float extraout_s2_19;
  float extraout_s2_20;
  float extraout_s2_21;
  float extraout_s2_22;
  float extraout_s2_23;
  float extraout_s2_24;
  float extraout_s2_25;
  float extraout_s2_26;
  float extraout_s2_27;
  float extraout_s2_28;
  float extraout_s2_29;
  float extraout_s2_30;
  float extraout_s2_31;
  float extraout_s2_32;
  float extraout_s2_33;
  float extraout_s2_34;
  float extraout_s2_35;
  float extraout_s2_36;
  float extraout_s2_37;
  float extraout_s2_38;
  float extraout_s2_39;
  float extraout_s2_40;
  float extraout_s2_41;
  float extraout_s2_42;
  float extraout_s2_43;
  float extraout_s2_44;
  float extraout_s2_45;
  uint extraout_s5;
  uint extraout_s5_00;
  uint extraout_s7;
  uint extraout_s7_00;
  undefined4 uVar58;
  undefined4 uVar59;
  float fVar60;
  float fVar61;
  float fVar62;
  float fVar63;
  float fVar64;
  double dVar65;
  undefined1 in_q8 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  longlong lVar68;
  undefined8 uVar69;
  undefined4 local_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  float local_218;
  float local_214 [3];
  float local_208 [3];
  String aSStack_1fc [8];
  String aSStack_1f4 [8];
  AbyssEngine aAStack_1ec [8];
  Vector aVStack_1e4 [12];
  Vector aVStack_1d8 [12];
  AEMath aAStack_1cc [12];
  Vector aVStack_1c0 [12];
  AEMath aAStack_1b4 [12];
  Vector aVStack_1a8 [12];
  String aSStack_19c [8];
  String aSStack_194 [8];
  undefined1 auStack_18c [8];
  float local_184;
  undefined1 auStack_180 [8];
  float local_178;
  undefined1 auStack_174 [8];
  float local_16c;
  undefined1 auStack_168 [8];
  float local_160;
  undefined1 auStack_15c [8];
  float local_154;
  undefined1 auStack_150 [4];
  float local_14c;
  float local_144 [3];
  undefined1 auStack_138 [8];
  float local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  float local_114;
  undefined1 auStack_108 [8];
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  undefined8 local_f0;
  float local_e8;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  undefined8 local_98;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  puVar5 = (uint *)Level::getMessages(*(Level **)(this + 0x18));
  this_00 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
  puVar6 = (uint *)Level::getEnemies(*(Level **)(this + 0x18));
  iVar7 = Status::getCurrentCampaignMission(Globals::status);
  iVar13 = param_1 >> 0x1f;
  bVar55 = SUB41(param_1,0);
  if (iVar7 != 0) {
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar7 == 1) {
      LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,true);
      fVar56 = (float)VectorSignedToFloat((param_1 & 0x7ffffff8U) << 1,(byte)(in_fpscr >> 0x16) & 3)
      ;
      PlayerEgo::rotate(this_00,fVar56 * 1.5258789e-05 * 6.2831855,extraout_s1,6.2831855);
      (**(code **)(**(int **)puVar6[1] + 0x28))(auStack_108);
      KIPlayer::setToSleep(*(KIPlayer **)puVar6[1]);
      in_fpscr = in_fpscr & 0xfffffff;
      fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar56 = 1.0;
      if (local_100 / -5000.0 < 1.0) {
        fVar56 = local_100 / -5000.0;
      }
      AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),fVar57 * 0.2 * fVar56);
      iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
      bVar54 = iVar7 == 1;
      if (bVar54) {
        iVar7 = *(int *)(this + 0x1c);
      }
      fVar56 = extraout_s2;
      fVar57 = extraout_s1_00;
      if (bVar54 && iVar7 == 0) {
        *(undefined4 *)(this + 0x1c) = 1;
        Layout::startFade(Globals::layout,true,0xff,5000);
        fVar56 = extraout_s2_00;
        fVar57 = extraout_s1_01;
      }
      if ((*(int *)(this + 0x1c) == 1) &&
         (iVar7 = Layout::isFading(Globals::layout), fVar56 = extraout_s2_01,
         fVar57 = extraout_s1_02, iVar7 == 0)) {
        Layout::enableFillScreen(Globals::layout,true);
        Globals::switch_to_target_setting = 0;
        AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
        goto switchD_001616e0_default;
      }
      dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      in_q8._0_8_ = dVar65 * 0.1;
      in_q8._8_8_ = 0x3fb999999999999a;
      TargetFollowCamera::translate
                (*(TargetFollowCamera **)(this + 0x14),(float)in_q8._0_8_,fVar57,fVar56);
      goto LAB_0016101c;
    }
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar7 == 0x51) && (iVar7 = Status::inAlienOrbit(Globals::status), iVar7 == 1)) {
      LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,true);
      fVar56 = (float)VectorSignedToFloat(param_1 * -4,(byte)(in_fpscr >> 0x16) & 3);
      fVar57 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
      TargetFollowCamera::translate
                (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_07,fVar57);
      this[0x11] = (LevelScript)0x1;
      iVar7 = *(int *)(this + 0x1c);
      if (iVar7 == 1) {
        iVar7 = *(uint *)(this + 0x90) + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
        fVar57 = (float)__aeabi_l2f(iVar7,iVar13);
        fVar56 = 1.0;
        if ((int)((uint)(fVar57 / 4000.0 < 1.0) << 0x1f) < 0) {
          fVar56 = fVar57 / 4000.0;
        }
        *(int *)(this + 0x90) = iVar7;
        *(int *)(this + 0x94) = iVar13;
        TargetFollowCamera::setRumblePercentage
                  (*(TargetFollowCamera **)(this + 0x14),1.0 - fVar56,(int)(1.0 - fVar56));
        pPVar3 = Globals::Canvas;
        pAVar52 = *(AEGeometry **)(this + 0xd8);
        uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
        pMVar45 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
        AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_98,pMVar45);
        local_f0 = 0x3f80000000000000;
        local_e8 = 0.0;
        AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
        uVar47 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
        fVar56 = (float)AbyssEngine::Transform::Update((ulonglong)uVar47,bVar55);
        if (*(int *)(this + 0xc) < (int)(uint)(*(uint *)(this + 8) < 0x36b1)) {
          if ((int)(uint)(*(uint *)(this + 8) < 0x2ee1) <= *(int *)(this + 0xc)) {
            AEGeometry::setVisible(*(AEGeometry **)(*(int *)puVar6[1] + 0x13c),true);
          }
        }
        else {
          *(undefined4 *)(this + 0x1c) = 2;
          TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
        }
LAB_0016284e:
        iVar7 = *(int *)(this + 0x1c);
      }
      else if (iVar7 == 0) {
        pLVar23 = this + 0x90;
        iVar7 = *(uint *)pLVar23 + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
        fVar57 = (float)__aeabi_l2f(iVar7,iVar13);
        fVar57 = fVar57 / 10000.0;
        fVar56 = 1.0;
        if ((int)((uint)(fVar57 < 1.0) << 0x1f) < 0) {
          fVar56 = fVar57;
        }
        *(int *)pLVar23 = iVar7;
        *(int *)(this + 0x94) = iVar13;
        TargetFollowCamera::setRumblePercentage
                  (*(TargetFollowCamera **)(this + 0x14),fVar57,(int)fVar56);
        if ((int)(uint)(*(uint *)(this + 8) < 0x2711) <= *(int *)(this + 0xc)) {
          local_98 = 0;
          local_90 = 10000.0;
          AEGeometry::setPosition(*(Vector **)(this + 0xd8));
          uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
          AbyssEngine::Transform::SetAnimationState(uVar29,3,0);
          uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
          fVar56 = (float)AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
          FModSound::play(Globals::sound,0xa0,(Vector *)0x0,(Vector *)0x0,fVar56);
          *(undefined4 *)(this + 0x1c) = 1;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
        goto LAB_0016284e;
      }
      if (iVar7 == 2) {
        iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0xc));
        if (iVar13 != 0) {
          iVar13 = 0xff;
          iVar7 = 5000;
LAB_00162872:
          Layout::startFade(Globals::layout,true,iVar13,iVar7);
          *(undefined4 *)(this + 0x1c) = 3;
          goto switchD_001616e0_default;
        }
        iVar7 = *(int *)(this + 0x1c);
      }
      if ((iVar7 != 3) || (iVar13 = Layout::isFading(Globals::layout), iVar13 != 0))
      goto switchD_001616e0_default;
      Layout::enableFillScreen(Globals::layout,true);
      Status::nextCampaignMission(SUB41(Globals::status,0));
      pSVar33 = Globals::status;
      Globals::switch_to_target_setting = 0;
      pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,100);
      Status::departStation(pSVar33,pSVar32);
      pSVar32 = (Station *)Status::getStation(Globals::status);
      Station::setAttackedFriends(pSVar32,false);
      Level::comingFromAlienWorld = 0;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
      goto LAB_00164462;
    }
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    pPVar3 = Globals::Canvas;
    if (iVar7 == 0x4e) {
      pLVar23 = this + 8;
      fVar56 = extraout_s2_06;
      fVar60 = extraout_s0_01;
      fVar57 = extraout_s1_08;
      if ((int)(uint)(*(uint *)pLVar23 < 0x1edd) <= *(int *)(this + 0xc)) {
        iVar7 = Level::getLandmarks(*(Level **)(this + 0x18));
        uVar47 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (pPVar3,*(uint *)(*(int *)(**(int **)(iVar7 + 4) + 0x13c) + 0xc));
        fVar60 = (float)AbyssEngine::Transform::Update((ulonglong)uVar47,bVar55);
        fVar56 = extraout_s2_07;
        fVar57 = extraout_s1_09;
      }
      switch(*(undefined4 *)(this + 0x1c)) {
      case 1:
        pTVar38 = *(TargetFollowCamera **)(this + 0x14);
        iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
        TargetFollowCamera::setTarget(pTVar38,*(AEGeometry **)(**(int **)(iVar13 + 4) + 0x13c));
        pPVar3 = Globals::Canvas;
        iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
        uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (pPVar3,*(uint *)(*(int *)(**(int **)(iVar13 + 4) + 0x13c) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
        uVar29 = 2;
        fVar57 = extraout_s1_10;
LAB_00164fbe:
        *(undefined4 *)(this + 0x1c) = uVar29;
        break;
      case 2:
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar60 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar60 = (float)TargetFollowCamera::translate
                                  (*(TargetFollowCamera **)(this + 0x14),fVar60 * 0.5,fVar57,fVar56)
        ;
        fVar57 = extraout_s1_56;
        if ((int)(uint)(*(uint *)pLVar23 < 0x1b59) <= *(int *)(this + 0xc)) {
          *(undefined4 *)(this + 0x1c) = 3;
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          fVar56 = extraout_s2_24;
LAB_001655aa:
          TargetFollowCamera::setPosition(pTVar38,fVar60,fVar57,fVar56);
          fVar57 = extraout_s1_70;
        }
        break;
      case 3:
        if ((int)(uint)(*(uint *)pLVar23 < 0x1edd) <= *(int *)(this + 0xc)) {
          iVar13 = FModSound::isPlaying(Globals::sound,0x462);
          fVar57 = extraout_s1_57;
          if (iVar13 == 0) {
            FModSound::play(Globals::sound,0x462,(Vector *)0x0,(Vector *)0x0,extraout_s0_09);
            fVar57 = extraout_s1_58;
          }
          if ((int)(uint)(*(uint *)pLVar23 < 0x2329) <= *(int *)(this + 0xc)) {
            uVar29 = 4;
            goto LAB_00164fbe;
          }
        }
        break;
      case 4:
        if ((int)(uint)(*(uint *)pLVar23 < 0x4651) <= *(int *)(this + 0xc)) {
          *(undefined4 *)(this + 0x1c) = 5;
          TargetFollowCamera::setPosition
                    (*(TargetFollowCamera **)(this + 0x14),fVar60,fVar57,fVar56);
          this_00[0x24] = (PlayerEgo)0x1;
          PlayerEgo::setVisible(this_00,false);
          fVar57 = extraout_s1_59;
        }
        break;
      case 5:
        if ((int)(uint)(*(uint *)pLVar23 < 0x4651) <= *(int *)(this + 0xc)) {
          *(undefined4 *)(this + 0x1c) = 6;
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
        break;
      case 6:
        fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        pLVar23 = this + 0x90;
        fVar56 = (float)__aeabi_l2f(*(undefined4 *)pLVar23,*(undefined4 *)(this + 0x94));
        uVar69 = __aeabi_f2lz(fVar57 * 0.3 + fVar56);
        *(undefined8 *)pLVar23 = uVar69;
        local_98 = (ulonglong)(uint)(fVar57 * 0.3);
        local_90 = 0.0;
        AEGeometry::translate(*(Vector **)(*(int *)(puVar6[1] + 4) + 8));
        fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        local_98 = (ulonglong)(uint)(fVar56 * 0.0009);
        local_90 = 0.0;
        AEGeometry::rotate(*(Vector **)(*(int *)(puVar6[1] + 4) + 8));
        iVar7 = *(int *)(this + 0x94);
        uVar47 = 0x44c - param_1;
        iVar13 = (int)uVar47 >> 0x1f;
        fVar57 = extraout_s1_62;
        if ((int)((iVar7 - iVar13) - (uint)(*(uint *)pLVar23 < uVar47)) < 0 ==
            (SBORROW4(iVar7,iVar13) != SBORROW4(iVar7 - iVar13,(uint)(*(uint *)pLVar23 < uVar47))))
        {
          *(undefined4 *)(this + 0x1c) = 7;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
        break;
      case 7:
        if ((int)(uint)(*(uint *)pLVar23 < 0x6979) <= *(int *)(this + 0xc)) {
          uVar29 = 8;
          goto LAB_00164fbe;
        }
        break;
      case 8:
        fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        pLVar23 = this + 0x90;
        fVar56 = (float)__aeabi_l2f(*(undefined4 *)pLVar23,*(undefined4 *)(this + 0x94));
        uVar47 = __aeabi_f2lz(fVar57 * 0.3 + fVar56);
        *(uint *)pLVar23 = uVar47;
        *(int *)(this + 0x94) = extraout_r1_01;
        uVar46 = 0x44c - param_1;
        iVar13 = (int)uVar46 >> 0x1f;
        if ((int)((extraout_r1_01 - iVar13) - (uint)(uVar47 < uVar46)) < 0 ==
            (SBORROW4(extraout_r1_01,iVar13) !=
            SBORROW4(extraout_r1_01 - iVar13,(uint)(uVar47 < uVar46)))) {
          fVar57 = extraout_s1_60;
          if ((int)(uint)(uVar47 < 0x7d1) <= extraout_r1_01) {
            *(undefined4 *)(this + 0x1c) = 9;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            fVar56 = extraout_s2_25;
            fVar60 = extraout_s0_10;
            goto LAB_001655aa;
          }
        }
        else {
          local_98 = (ulonglong)(uint)-(fVar57 * 0.3);
          local_90 = 0.0;
          AEGeometry::translate(*(Vector **)(*(int *)puVar6[1] + 8));
          fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
          local_98 = (ulonglong)(uint)(fVar56 * 0.0009);
          local_90 = 0.0;
          AEGeometry::rotate(*(Vector **)(*(int *)puVar6[1] + 8));
          fVar57 = extraout_s1_61;
        }
        break;
      case 9:
        fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(param_1 * 3,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.7,fVar57,0.7)
        ;
        pLVar23 = this + 0x90;
        iVar7 = *(uint *)pLVar23 + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
        fVar57 = (float)__aeabi_l2f(iVar7,iVar13);
        fVar57 = fVar57 / 10000.0;
        in_fpscr = in_fpscr & 0xfffffff;
        fVar56 = 1.0;
        if (fVar57 < 1.0) {
          fVar56 = fVar57;
        }
        *(int *)pLVar23 = iVar7;
        *(int *)(this + 0x94) = iVar13;
        TargetFollowCamera::setRumblePercentage
                  (*(TargetFollowCamera **)(this + 0x14),fVar57,(int)fVar56);
        fVar57 = extraout_s1_63;
        if ((int)(uint)(*(uint *)pLVar23 < 0x1771) <= *(int *)(this + 0x94)) {
          local_98 = 0;
          local_90 = 14000.0;
          AEGeometry::setPosition(*(Vector **)(this + 0xd8));
          uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
          AbyssEngine::Transform::SetAnimationState(uVar29,3,0);
          uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
          fVar56 = (float)AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
          FModSound::play(Globals::sound,0xa0,(Vector *)0x0,(Vector *)0x0,fVar56);
          *(undefined4 *)(this + 0x1c) = 10;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
          fVar57 = extraout_s1_64;
        }
        break;
      case 10:
        fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(param_1 << 2,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.7,fVar57,0.7)
        ;
        pLVar23 = this + 0x90;
        iVar7 = *(uint *)pLVar23 + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
        fVar57 = (float)__aeabi_l2f(iVar7,iVar13);
        in_fpscr = in_fpscr & 0xfffffff;
        fVar56 = 1.0;
        if (fVar57 / 4000.0 < 1.0) {
          fVar56 = fVar57 / 4000.0;
        }
        *(int *)pLVar23 = iVar7;
        *(int *)(this + 0x94) = iVar13;
        TargetFollowCamera::setRumblePercentage
                  (*(TargetFollowCamera **)(this + 0x14),1.0 - fVar56,(int)(1.0 - fVar56));
        pPVar3 = Globals::Canvas;
        pAVar52 = *(AEGeometry **)(this + 0xd8);
        uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
        pMVar45 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
        AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_98,pMVar45);
        local_f0 = 0x3f80000000000000;
        local_e8 = 0.0;
        AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
        lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
        fVar56 = (float)AbyssEngine::Transform::Update(lVar68,bVar55);
        if (*(int *)(this + 0x94) < (int)(uint)(*(uint *)pLVar23 < 0xfa1)) {
          fVar57 = extraout_s1_54;
          if ((int)(uint)(*(uint *)pLVar23 < 0x867) <= *(int *)(this + 0x94)) {
            KIPlayer::setVisible(*(KIPlayer **)puVar6[1],false);
            KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 4),false);
            iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
            KIPlayer::setVisible((KIPlayer *)**(undefined4 **)(iVar13 + 4),false);
            fVar57 = extraout_s1_69;
          }
        }
        else {
          *(undefined4 *)(this + 0x1c) = 0xb;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
          TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
          fVar57 = extraout_s1_55;
        }
        break;
      case 0xb:
        fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(param_1 * 3,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.7,fVar57,0.7)
        ;
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23 + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
        *(uint *)pLVar23 = uVar47;
        *(int *)(this + 0x94) = iVar13;
        fVar57 = extraout_s1_65;
        if ((int)(uint)(uVar47 < 0xbb9) <= iVar13) {
          uVar47 = *puVar6;
          if (2 < uVar47) {
            uVar46 = 2;
            do {
              piVar28 = *(int **)(puVar6[1] + uVar46 * 4);
              local_98 = 0;
              local_90 = -50000.0;
              (**(code **)(*piVar28 + 0x20))(piVar28,&local_98);
              (**(code **)(**(int **)(puVar6[1] + uVar46 * 4) + 0xc))();
              uVar47 = *puVar6;
              uVar46 = uVar46 + 1;
            } while (uVar46 < uVar47);
          }
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),
                     *(AEGeometry **)(*(int *)(puVar6[1] + uVar47 * 4 + -0x28) + 8));
          AEGeometry::getPosition();
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_98);
          *(float *)(this + 0x28) = *(float *)(this + 0x28) + 2000.0;
          *(float *)(this + 0x2c) = *(float *)(this + 0x2c) + 500.0;
          *(float *)(this + 0x30) = *(float *)(this + 0x30) + -20000.0;
          TargetFollowCamera::setPosition
                    (*(TargetFollowCamera **)(this + 0x14),(Vector *)(this + 0x28));
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),0x1e,false);
          *(undefined4 *)(this + 0x1c) = 0xc;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
          fVar57 = extraout_s1_66;
        }
        break;
      case 0xc:
        uVar47 = *(uint *)(this + 0x90);
        *(uint *)(this + 0x90) = uVar47 + param_1;
        *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),0x1e,false);
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar57 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.5,extraout_s1_52,fVar57 * 0.3);
        fVar57 = extraout_s1_53;
        if ((int)(uint)(*(uint *)(this + 0x90) < 0x1389) <= *(int *)(this + 0x94)) {
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
          this[0x11] = (LevelScript)0x0;
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
          PlayerEgo::setComputerControlled(this_00,false);
          Player::setVulnerable(*(Player **)this_00,true);
          this_00[0x24] = (PlayerEgo)0x0;
          PlayerEgo::setVisible(this_00,true);
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          *(undefined4 *)(this + 0x1c) = 0xd;
          goto switchD_001616e0_default;
        }
      }
      if (*(int *)(this + 0x1c) - 5U < 4) {
        fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.8,fVar57,0.8)
        ;
      }
      goto switchD_001616e0_default;
    }
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar7 != 0x59) {
      iVar7 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar7 != 0x6a) {
        iVar7 = Status::getCurrentCampaignMission(Globals::status);
        fVar56 = extraout_s1_24;
        if ((((((iVar7 == 0x5f) ||
               (iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar56 = extraout_s1_25,
               iVar7 == 99)) ||
              (iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar56 = extraout_s1_26,
              iVar7 == 0x6d)) ||
             ((iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar56 = extraout_s1_27,
              iVar7 == 0x77 ||
              (iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar56 = extraout_s1_28,
              iVar7 == 0x7e)))) ||
            (iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar56 = extraout_s1_29,
            iVar7 == 0x85)) ||
           ((iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar56 = extraout_s1_30,
            iVar7 == 0xa0 ||
            (iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar56 = extraout_s1_31,
            iVar7 == 0xa1)))) {
          fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar60 = (float)VectorSignedToFloat(param_1 * -2,(byte)(in_fpscr >> 0x16) & 3);
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar57,fVar56,fVar60);
          iVar13 = *(int *)(this + 0x1c);
          if (iVar13 == 1) {
            iVar13 = RadioMessage::isOver(*(RadioMessage **)puVar5[1]);
            if (iVar13 != 0) {
              *(undefined4 *)(this + 0x1c) = 2;
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x94) = 0;
              goto switchD_001616e0_default;
            }
            iVar13 = *(int *)(this + 0x1c);
          }
          else if (iVar13 == 0) {
            if ((int)(uint)(*(uint *)pLVar23 < 2000) <= *(int *)(this + 0x94)) {
              *(undefined4 *)(this + 0x1c) = 1;
            }
            goto switchD_001616e0_default;
          }
          if ((iVar13 == 2) && ((int)(uint)(*(uint *)pLVar23 < 2000) <= *(int *)(this + 0x94))) {
            pMVar12 = (Mission *)Status::getCampaignMission(Globals::status);
            Mission::setStatusValue(pMVar12,1);
          }
          goto switchD_001616e0_default;
        }
        goto LAB_0016101c;
      }
      iVar7 = *(int *)(this + 0x1c);
      if (iVar7 == 3) {
        iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x10));
        if (iVar7 == 1) {
          *(undefined4 *)(this + 0x1c) = 4;
        }
        else {
          iVar7 = *(int *)(this + 0x1c);
LAB_00165ef0:
          if (iVar7 == 4) {
            iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x10));
            if (iVar7 != 0) {
              TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
              PlayerFighter::setAIDisabled(*(PlayerFighter **)puVar6[1],false);
              Player::setHitpoints(*(Player **)(*(int *)puVar6[1] + 4),0);
              *(undefined4 *)(this + 0x1c) = 5;
              *(undefined4 *)(this + 0x90) = 0;
              *(undefined4 *)(this + 0x94) = 0;
              goto LAB_00166f0e;
            }
            iVar7 = *(int *)(this + 0x1c);
          }
          if (iVar7 == 6) {
            iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x14));
            if (iVar13 == 1) {
              uVar29 = Player::getHitpoints(*(Player **)this_00);
              *(undefined4 *)(Globals::status + 100) = uVar29;
              uVar29 = Player::getShieldHP(*(Player **)this_00);
              *(undefined4 *)(Globals::status + 0x5c) = uVar29;
              uVar29 = Player::getArmorHP(*(Player **)this_00);
              *(undefined4 *)(Globals::status + 0x60) = uVar29;
              uVar29 = Player::getGammaHP(*(Player **)this_00);
              pSVar33 = Globals::status;
              *(undefined4 *)(Globals::status + 0x68) = uVar29;
              Status::nextCampaignMission(SUB41(pSVar33,0));
              Status::nextCampaignMission(SUB41(Globals::status,0));
              pSVar33 = Globals::status;
              pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,10);
              Status::setStation(pSVar33,pSVar32);
              pSVar33 = Globals::status;
              pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,10);
              Status::departStation(pSVar33,pSVar32);
              Level::initStreamOutPosition = 1;
              Globals::switch_to_target_setting = 1;
              AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
            }
          }
          else if (iVar7 == 5) {
            uVar47 = *(uint *)(this + 0x90) + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
            if ((int)(uint)(uVar47 < 0xbb9) <= iVar13) {
              *(undefined4 *)(this + 0x1c) = 6;
            }
          }
        }
      }
      else if (iVar7 == 2) {
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23;
        *(uint *)pLVar23 = uVar47 + param_1;
        *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),0,false);
        if (*(int *)(this + 0x94) < (int)(uint)(*(uint *)pLVar23 < 0xbb9)) {
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar57 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.4,extraout_s1_68,fVar57 * 0.1)
          ;
        }
        else {
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8));
          AEGeometry::getPosition();
          pVVar48 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
          fVar56 = (float)AEGeometry::getDirection();
          AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
          fVar56 = (float)AEGeometry::getUpVector();
          AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
          fVar56 = (float)AEGeometry::getRightVector();
          AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
          TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
          *(undefined4 *)(this + 0x1c) = 3;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
      }
      else {
        if (iVar7 != 1) goto LAB_00165ef0;
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar57 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.1,extraout_s1_20,fVar57 * 0.05);
        iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
        if (iVar13 == 1) {
          *(undefined4 *)(this + 0x1c) = 2;
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
          (**(code **)(**(int **)puVar6[1] + 0xc))();
          KIPlayer::setVisible(*(KIPlayer **)puVar6[1],true);
          PlayerFighter::setCloakingPossible(*(PlayerFighter **)puVar6[1],false);
          PlayerFighter::setAIDisabled(*(PlayerFighter **)puVar6[1],true);
        }
      }
LAB_00166f0e:
      if (*(int *)(this + 0x1c) - 2U < 3) {
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),fVar56);
      }
      this[0x11] = (LevelScript)0x1;
      goto switchD_001616e0_default;
    }
    LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,true);
    TargetFollowCamera::setTarget
              (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xcc));
    this[0x11] = (LevelScript)0x1;
    if (*(int *)(this + 0x1c) < 3) {
      pTVar38 = *(TargetFollowCamera **)(this + 0x14);
      fVar56 = (float)__aeabi_l2f(*(undefined4 *)(this + 8),*(undefined4 *)(this + 0xc));
      fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      TargetFollowCamera::translate
                (pTVar38,(fVar57 + fVar57) * (fVar56 / -35000.0 + 1.0),extraout_s1_16,
                 fVar57 + fVar57);
      pVVar48 = *(Vector **)(this + 0xcc);
      AEGeometry::getRightVector();
      fVar56 = (float)AbyssEngine::AEMath::operator-((AEMath *)&local_a4,(Vector *)&local_b0);
      fVar56 = (float)AbyssEngine::AEMath::operator*((AEMath *)&local_fc,(Vector *)&local_a4,fVar56)
      ;
      AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
      fVar56 = (float)__aeabi_l2f(*(undefined4 *)(this + 8),*(undefined4 *)(this + 0xc));
      AbyssEngine::AEMath::operator*
                ((AEMath *)&local_98,(Vector *)&local_f0,fVar56 / -50000.0 + 1.0);
      AEGeometry::translate(pVVar48);
    }
    PlayerFixedObject::moveForward(*(PlayerFixedObject **)(puVar6[1] + 0x2c),param_1);
    switch(*(undefined4 *)(this + 0x1c)) {
    case 1:
      if ((int)(uint)(*(uint *)(this + 8) < 0x7531) <= *(int *)(this + 0xc)) {
        *(undefined4 *)(this + 0x1c) = 2;
        pVVar48 = (Vector *)TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),pVVar48);
        *(float *)(this + 0x2c) = *(float *)(this + 0x2c) + 500.0;
        iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
        (**(code **)(*(int *)**(undefined4 **)(iVar13 + 4) + 0x44))
                  ((int *)**(undefined4 **)(iVar13 + 4),(Vector *)(this + 0x28));
        iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
        AEGeometry::moveForward(*(AEGeometry **)(**(int **)(iVar13 + 4) + 8),extraout_s0_02);
        uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar29,3,0);
        uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
        pAVar52 = *(AEGeometry **)(this + 0xdc);
        Level::getEnemies(*(Level **)(this + 0x18));
        AEGeometry::getDirection();
        AbyssEngine::AEMath::operator-((AEMath *)&local_98,(Vector *)&local_f0);
        local_fc = 0.0;
        local_f8 = 1.0;
        local_f4 = 0.0;
        AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_fc);
        pVVar48 = *(Vector **)(this + 0xdc);
        Level::getEnemies(*(Level **)(this + 0x18));
        AEGeometry::getPosition();
        AEGeometry::setPosition(pVVar48);
      }
      goto switchD_001616e0_default;
    case 2:
      pVVar48 = (Vector *)TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
      Level::getEnemies(*(Level **)(this + 0x18));
      AEGeometry::getPosition();
      AbyssEngine::AEMath::operator-((AEMath *)&local_98,pVVar48,(Vector *)&local_f0);
      fVar57 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_98);
      in_fpscr = in_fpscr & 0xfffffff;
      fVar56 = 1.0;
      if (fVar57 / 7000.0 < 1.0) {
        fVar56 = fVar57 / 7000.0;
      }
      fVar56 = (1.0 - fVar56) * 100.0;
      TargetFollowCamera::setRumblePercentage
                (*(TargetFollowCamera **)(this + 0x14),fVar56,(int)fVar56);
      in_fpscr = in_fpscr & 0xfffffff;
      if (fVar57 < 200000.0) {
        VectorSignedToFloat(param_1 * 10,(byte)(in_fpscr >> 0x16) & 3);
        iVar7 = Level::getEnemies(*(Level **)(this + 0x18));
        AEGeometry::moveForward(*(AEGeometry **)(**(int **)(iVar7 + 4) + 8),extraout_s0_08);
      }
      pVVar48 = *(Vector **)(this + 0xdc);
      Level::getEnemies(*(Level **)(this + 0x18));
      AEGeometry::getPosition();
      AEGeometry::setPosition(pVVar48);
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0xc));
      fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      bVar55 = (bool)__aeabi_f2lz(fVar56 * 0.5);
      fVar56 = (float)AbyssEngine::Transform::Update(CONCAT44(extraout_r1,uVar29),bVar55);
      uVar47 = *(uint *)(this + 8);
      if (*(int *)(this + 0xc) < (int)(uint)(uVar47 < 0x9471)) goto switchD_001616e0_default;
      iVar13 = (*(int *)(this + 0xc) - iVar13) - (uint)(uVar47 < (uint)param_1);
      bVar55 = 38000 < uVar47 - param_1;
      if ((int)(-(uint)bVar55 - iVar13) < 0 ==
          (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)bVar55))) {
        FModSound::play(Globals::sound,0x8c8,(Vector *)0x0,(Vector *)0x0,fVar56);
      }
      pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
      iVar13 = StarSystem::getPlanets(pSVar31);
      pVVar48 = (Vector *)**(undefined4 **)(iVar13 + 4);
      fVar56 = (float)AEGeometry::getScaling();
      AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
      AEGeometry::setScaling(pVVar48);
      if (*(int *)(this + 0xc) < (int)(uint)(*(uint *)(this + 8) < 0x9859))
      goto switchD_001616e0_default;
      iVar13 = -1;
      iVar7 = 500;
      goto LAB_00162872;
    case 3:
      iVar13 = Layout::isFading(Globals::layout);
      pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
      if (iVar13 != 0) {
        iVar13 = StarSystem::getPlanets(pSVar31);
        pVVar48 = (Vector *)**(undefined4 **)(iVar13 + 4);
        AEGeometry::getScaling();
        fVar56 = 10.0;
        if ((int)((uint)(local_114 < 10.0) << 0x1f) < 0) {
          fVar56 = (float)AEGeometry::getScaling();
          AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
          fVar56 = (float)AEGeometry::setScaling(pVVar48);
        }
        TargetFollowCamera::setRumblePercentage
                  (*(TargetFollowCamera **)(this + 0x14),fVar56,0x3f800000);
        goto switchD_001616e0_default;
      }
      StarSystem::switchSunForSupernovaIntro(pSVar31);
      Layout::startFade(Globals::layout,false,-1,10000);
      KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 8),true);
      if (3 < *puVar6) {
        uVar47 = 3;
        do {
          Player::setHitpoints(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4),0);
          uVar47 = uVar47 + 1;
        } while (uVar47 < *puVar6);
      }
      *(undefined4 *)(this + 0x90) = 0;
      *(undefined4 *)(this + 0x94) = 0;
      uVar29 = 4;
      break;
    case 4:
      pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
      StarSystem::scaleSunDuringSupernovaIntro(pSVar31,param_1);
      pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
      StarSystem::updateSupernova(pSVar31,param_1);
      pLVar23 = this + 0x90;
      uVar47 = *(uint *)pLVar23;
      iVar7 = *(int *)(this + 0x94);
      if (((int)(-(uint)(7000 < uVar47) - iVar7) < 0 ==
           (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(7000 < uVar47)))) &&
         ((int)(uint)(uVar47 + param_1 < 0x1b59) <=
          (int)(iVar7 + iVar13 + (uint)CARRY4(uVar47,param_1)))) {
        Layout::startFade(Globals::layout,true,0xff,param_1 + 1000);
        uVar47 = *(uint *)pLVar23;
        iVar7 = *(int *)(this + 0x94);
      }
      iVar7 = iVar7 + iVar13 + (uint)CARRY4(uVar47,param_1);
      *(uint *)pLVar23 = uVar47 + param_1;
      *(int *)(this + 0x94) = iVar7;
      if (iVar7 < (int)(uint)(uVar47 + param_1 < 8000)) goto switchD_001616e0_default;
      uVar29 = 5;
      break;
    case 5:
      iVar13 = Layout::isFading(Globals::layout);
      if (iVar13 != 0) goto switchD_001616e0_default;
      Layout::enableFillScreen(Globals::layout,true);
      Status::nextCampaignMission(SUB41(Globals::status,0));
      pSVar33 = Globals::status;
      Globals::switch_to_target_setting = 0;
      pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,10);
      Status::departStation(pSVar33,pSVar32);
      pSVar32 = (Station *)Status::getStation(Globals::status);
      Station::setAttackedFriends(pSVar32,false);
      Level::comingFromAlienWorld = 0;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
      goto LAB_00164462;
    default:
      goto switchD_001616e0_default;
    }
    *(undefined4 *)(this + 0x1c) = uVar29;
    goto switchD_001616e0_default;
  }
  iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
  iVar37 = *(int *)(this + 0x1c);
  if (iVar7 == 1 && iVar37 == 0) {
    *(undefined4 *)(this + 0x1c) = 1;
    fVar56 = (float)PlayerEgo::setPosition(extraout_s0,extraout_s1_03,extraout_s2_02);
    TargetFollowCamera::setPosition
              (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_04,extraout_s2_03);
    pPVar3 = Globals::Canvas;
    uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar45 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
    uVar29 = 0xc3fa0000;
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_98,pMVar45,extraout_s0_00,extraout_s1_05,extraout_s2_04);
    (**(code **)(**(int **)puVar6[1] + 0x48))(*(int **)puVar6[1],0xc61c4000,0x43fa0000,0,uVar29);
    (**(code **)(**(int **)(puVar6[1] + 4) + 0x48))
              (*(int **)(puVar6[1] + 4),0xc61c4000,0xc3960000,0xc4d48000);
    (**(code **)(**(int **)(puVar6[1] + 8) + 0x48))
              (*(int **)(puVar6[1] + 8),0xc61c4000,0xc3480000,0x44fa0000);
    iVar7 = 0;
    do {
      local_98 = 0x3f800000;
      local_90 = 0.0;
      local_f0 = 0x3f80000000000000;
      local_e8 = 0.0;
      AEGeometry::setDirection
                (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),(Vector *)&local_98,
                 (Vector *)&local_f0);
      AEGeometry::setVisible(*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),true);
      iVar7 = iVar7 + 1;
    } while (iVar7 != 3);
    LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),0x1e,false);
    goto LAB_0016101c;
  }
  if (iVar37 < 3) {
    fVar56 = (float)Layout::getPulseValue(Globals::layout,extraout_s0);
    iVar7 = 0;
    fVar60 = fVar56 + -0.5;
    fVar57 = extraout_s1_11;
    do {
      fVar60 = (float)AEGeometry::translate
                                (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),fVar60,fVar57
                                 ,fVar56);
      iVar7 = iVar7 + 1;
      fVar56 = extraout_s2_08;
      fVar57 = extraout_s1_12;
    } while (iVar7 != 3);
    iVar7 = *(int *)(this + 0x1c);
    if (iVar7 == 1) {
      iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x18));
      if (iVar7 == 1) {
        *(undefined4 *)(this + 0x1c) = 2;
        fVar56 = (float)TargetFollowCamera::setTarget
                                  (*(TargetFollowCamera **)(this + 0x14),
                                   *(AEGeometry **)(*(int *)puVar6[1] + 8));
        TargetFollowCamera::setPosition
                  (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_13,extraout_s2_09);
      }
      iVar7 = *(int *)(this + 0x1c);
    }
    if (iVar7 == 2) {
      iVar7 = FModSound::isPlaying(Globals::sound,0x8e);
      fVar56 = extraout_s1_14;
      if (iVar7 == 0) {
        fVar56 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
        FModSound::play(Globals::sound,0x8e,(Vector *)0x0,(Vector *)0x0,fVar56);
        fVar56 = extraout_s1_15;
      }
      fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      TargetFollowCamera::translate
                (*(TargetFollowCamera **)(this + 0x14),fVar57 * 2.2,fVar56,fVar57 * 0.2);
      iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x1c));
      if (iVar7 == 1) {
        iVar7 = 0;
        *(undefined4 *)(this + 0x1c) = 3;
        uVar47 = puVar6[1];
        do {
          PlayerFighter::setExhaustVisible(*(PlayerFighter **)(uVar47 + iVar7 * 4),true);
          AEGeometry::setVisible(*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),true);
          (**(code **)(**(int **)(puVar6[1] + iVar7 * 4) + 0xc))();
          uVar47 = puVar6[1];
          iVar37 = *(int *)(uVar47 + iVar7 * 4);
          iVar7 = iVar7 + 1;
          *(undefined4 *)(iVar37 + 0x124) = 50000;
          *(undefined1 *)(*(int *)(iVar37 + 4) + 0x5c) = 1;
        } while (iVar7 != 3);
      }
    }
    goto LAB_0016101c;
  }
  if (iVar37 == 4) {
    iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x28));
    if (iVar7 == 0) {
      iVar37 = *(int *)(this + 0x1c);
      fVar56 = extraout_s1_33;
      goto LAB_001640ea;
    }
    fVar56 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
    FModSound::play(Globals::sound,0x8f,(Vector *)0x0,(Vector *)0x0,fVar56);
    PlayerEgo::setTurretMode(this_00,false);
    resetCamera(this,*(Level **)(this + 0x18));
    PlayerEgo::setFreeLookMode(this_00,false);
    TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
    PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
    this[0x11] = (LevelScript)0x1;
    pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
    PlayerEgo::setCollide(pPVar10,false);
    *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
    PlayerEgo::setComputerControlled(this_00,true);
    Player::removeAllGuns(*(Player **)this_00);
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
    fVar56 = (float)TargetFollowCamera::setTarget
                              (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
    AEGeometry::setRotation(*(AEGeometry **)(this_00 + 8),fVar56,extraout_s1_34,extraout_s2_13);
    pTVar38 = *(TargetFollowCamera **)(this + 0x14);
    AEGeometry::getPosition();
    fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_35,extraout_s2_14);
    uVar29 = 5;
LAB_001627c2:
    *(undefined4 *)(this + 0x1c) = uVar29;
    goto LAB_0016101c;
  }
  fVar56 = extraout_s1_03;
  if (iVar37 == 3) {
    fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0x14),fVar56 * 2.2,extraout_s1_03,fVar56 * 0.2);
    iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x20));
    if (iVar7 == 1) {
      *(undefined4 *)(this + 0x90) = 0;
      *(undefined4 *)(this + 0x94) = 0;
      *(undefined4 *)(this + 0x1c) = 4;
      PlayerEgo::setComputerControlled(this_00,false);
      *(undefined1 *)(*(int *)this_00 + 0x5e) = 0;
      *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
      pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
      PlayerEgo::setCollide(pPVar10,true);
      this[0x11] = (LevelScript)0x0;
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
      TargetFollowCamera::setTarget
                (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
      this[0x12] = (LevelScript)0x1;
      this[0x20] = (LevelScript)0x0;
    }
    goto LAB_0016101c;
  }
LAB_001640ea:
  if (iVar37 == 5) {
    iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x30));
    if (iVar7 == 1) {
      PlayerEgo::getPosition();
      fVar56 = (float)PlayerEgo::getSpeed(this_00);
      in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar56 == 2.0) << 0x1e;
      if ((byte)(in_fpscr >> 0x1e) != 0) {
        FModSound::play(Globals::sound,0x9d,(Vector *)0x0,(Vector *)0x0,2.0);
        local_f0 = 0;
        local_e8 = 0.0;
        fVar56 = (float)FModSound::updateEvent3DAttributes
                                  (Globals::sound,0x9d,(Vector *)&local_98,(Vector *)&local_f0,false
                                  );
        FModSound::play(Globals::sound,0x9e,(Vector *)0x0,(Vector *)0x0,fVar56);
        local_fc = 0.0;
        local_f8 = 0.0;
        local_f4 = 0.0;
        FModSound::updateEvent3DAttributes
                  (Globals::sound,0x9e,(Vector *)&local_98,(Vector *)&local_fc,false);
        fVar56 = (float)FModSound::stop(Globals::sound,*(int *)(this_00 + 0x1c));
        FModSound::play(Globals::sound,0xa1,(Vector *)0x0,(Vector *)0x0,fVar56);
      }
      local_f0 = 0;
      local_e8 = 0.0;
      FModSound::updateEvent3DAttributes
                (Globals::sound,0xa1,(Vector *)&local_98,(Vector *)&local_f0,false);
      fVar56 = (float)PlayerEgo::getSpeed(this_00);
      PlayerEgo::setSpeed(this_00,fVar56 * 0.98);
      iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x34));
      if (iVar7 == 1) {
        dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        in_q8._0_8_ = dVar65 * 0.3;
        in_q8._8_8_ = 0x3fd3333333333333;
        fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.2,extraout_s1_49,
                   (float)in_q8._0_8_);
      }
      iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x38));
      if (iVar7 == 1) {
        *(undefined4 *)(this + 0x1c) = 6;
        *(undefined4 *)(this + 0x90) = 0;
        *(undefined4 *)(this + 0x94) = 0;
      }
      goto LAB_0016101c;
    }
    iVar37 = *(int *)(this + 0x1c);
    fVar56 = extraout_s1_48;
  }
  switch(iVar37) {
  case 6:
    local_98 = 0;
    local_90 = 0.0;
    PlayerEgo::getPosition();
    FModSound::updateEvent3DAttributes
              (Globals::sound,0xa1,(Vector *)&local_f0,(Vector *)&local_98,false);
    dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    in_q8._0_8_ = dVar65 * 0.3;
    in_q8._8_8_ = 0x3fd3333333333333;
    fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.2,extraout_s1_67,(float)in_q8._0_8_)
    ;
    uVar47 = *(uint *)(this + 0x90);
    iVar7 = uVar47 + param_1;
    iVar37 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
    fVar57 = (float)__aeabi_l2f(iVar7,iVar37);
    fVar57 = fVar57 / 4000.0;
    in_fpscr = in_fpscr & 0xfffffff;
    fVar56 = 1.0;
    if (fVar57 < 1.0) {
      fVar56 = fVar57;
    }
    *(int *)(this + 0x90) = iVar7;
    *(int *)(this + 0x94) = iVar37;
    TargetFollowCamera::setRumblePercentage
              (*(TargetFollowCamera **)(this + 0x14),fVar57,(int)fVar56);
    iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x3c));
    if (iVar7 == 1) {
      *(undefined4 *)(this + 0x1c) = 7;
      pVVar48 = *(Vector **)(this + 0xd8);
      PlayerEgo::getPosition();
      AEGeometry::setPosition(pVVar48);
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar29,3,0);
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
      fVar56 = (float)AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
      FModSound::play(Globals::sound,0xa0,(Vector *)0x0,(Vector *)0x0,fVar56);
      FModSound::stop(Globals::sound,0xa1);
LAB_00167f02:
      *(undefined4 *)(this + 0x90) = 0;
      *(undefined4 *)(this + 0x94) = 0;
    }
    break;
  case 7:
    dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    in_q8._0_8_ = dVar65 * 0.3;
    in_q8._8_8_ = 0x3fd3333333333333;
    fVar57 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
    pLVar23 = this + 0x90;
    uVar47 = *(uint *)pLVar23;
    *(uint *)pLVar23 = uVar47 + param_1;
    *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0x14),fVar57 * 0.2,fVar56,(float)in_q8._0_8_);
    pPVar3 = Globals::Canvas;
    pAVar52 = *(AEGeometry **)(this + 0xd8);
    uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar45 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
    AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_98,pMVar45);
    local_f0 = 0x3f80000000000000;
    local_e8 = 0.0;
    AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
    lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
    AbyssEngine::Transform::Update(lVar68,bVar55);
    if ((int)(uint)(*(uint *)pLVar23 < 0x7d1) <= *(int *)(this + 0x94)) {
      FModSound::stop(Globals::sound,0x9e);
      fVar56 = (float)PlayerEgo::setVisible(this_00,false);
      TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
    }
    iVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
    if (*(char *)(iVar7 + 0xed) == '\0') {
      fVar56 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
      FModSound::play(Globals::sound,0x8d,(Vector *)0x0,(Vector *)0x0,fVar56);
      uVar29 = 8;
LAB_00167e44:
      *(undefined4 *)(this + 0x1c) = uVar29;
      *(undefined4 *)(this + 0x90) = 0;
      *(undefined4 *)(this + 0x94) = 0;
    }
    break;
  case 8:
    pLVar23 = this + 0x90;
    iVar7 = *(uint *)pLVar23 + param_1;
    iVar37 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
    fVar56 = (float)__aeabi_l2f(iVar7,iVar37);
    *(int *)pLVar23 = iVar7;
    *(int *)(this + 0x94) = iVar37;
    uVar69 = FloatVectorMax(CONCAT44(extraout_s1_82,fVar56 / -3000.0 + 1.0),
                            (ulonglong)extraout_s5 << 0x20,2,0x20);
    fVar56 = (float)TargetFollowCamera::setRumblePercentage
                              (*(TargetFollowCamera **)(this + 0x14),(float)uVar69,
                               (int)(float)uVar69);
    if ((int)(uint)(*(uint *)pLVar23 < 0xfa1) <= *(int *)(this + 0x94)) {
      *(undefined4 *)(this + 0x1c) = 9;
      *(undefined4 *)pLVar23 = 0;
      *(undefined4 *)(this + 0x94) = 0;
      TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar29,0,0);
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar29,3,0);
    }
    break;
  case 9:
    *(undefined4 *)(this + 0x1c) = 10;
    pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
    StarSystem::switchPlanetForIntro(pSVar31);
    fVar56 = (float)Level::switchSkyboxForIntro(*(Level **)(this + 0x18));
    PlayerEgo::setPosition(fVar56,extraout_s1_83,extraout_s2_35);
    ParticleSystemManager::reset(*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x84));
    ParticleSystemManager::reset(*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x78));
    local_98 = 0;
    local_90 = -1.0;
    local_f0 = 0x3f80000000000000;
    local_e8 = 0.0;
    fVar56 = (float)AEGeometry::setDirection
                              (*(AEGeometry **)(this_00 + 8),(Vector *)&local_98,(Vector *)&local_f0
                              );
    PlayerEgo::rotate(this_00,fVar56,extraout_s1_84,extraout_s2_36);
    pVVar48 = *(Vector **)(this + 0xd8);
    PlayerEgo::getPosition();
    fVar56 = (float)AEGeometry::setPosition(pVVar48);
    TargetFollowCamera::setPosition
              (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_85,extraout_s2_37);
LAB_00167db4:
    *(undefined4 *)(this + 0x90) = 0;
    *(undefined4 *)(this + 0x94) = 0;
    break;
  case 10:
    pLVar23 = this + 0x90;
    iVar7 = *(uint *)pLVar23 + param_1;
    iVar37 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
    fVar57 = (float)__aeabi_l2f(iVar7,iVar37);
    fVar57 = fVar57 / 2000.0;
    in_fpscr = in_fpscr & 0xfffffff;
    fVar56 = 1.0;
    if (fVar57 < 1.0) {
      fVar56 = fVar57;
    }
    *(int *)pLVar23 = iVar7;
    *(int *)(this + 0x94) = iVar37;
    fVar56 = (float)TargetFollowCamera::setRumblePercentage
                              (*(TargetFollowCamera **)(this + 0x14),fVar57,(int)fVar56);
    if ((int)(uint)(*(uint *)pLVar23 < 0x7d1) <= *(int *)(this + 0x94)) {
      FModSound::play(Globals::sound,0x9f,(Vector *)0x0,(Vector *)0x0,fVar56);
      *(undefined4 *)(this + 0x1c) = 0xb;
      pVVar48 = *(Vector **)(this + 0xd8);
      PlayerEgo::getPosition();
      AEGeometry::setPosition(pVVar48);
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
      AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
      goto LAB_00167f02;
    }
    break;
  case 0xb:
    iVar7 = *(uint *)(this + 0x90) + param_1;
    iVar37 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
    fVar56 = (float)__aeabi_l2f(iVar7,iVar37);
    *(int *)(this + 0x90) = iVar7;
    *(int *)(this + 0x94) = iVar37;
    uVar69 = FloatVectorMax(CONCAT44(extraout_s1_86,fVar56 / -2500.0 + 1.0),
                            (ulonglong)extraout_s5_00 << 0x20,2,0x20);
    TargetFollowCamera::setRumblePercentage
              (*(TargetFollowCamera **)(this + 0x14),(float)uVar69,(int)(float)uVar69);
    pPVar3 = Globals::Canvas;
    pAVar52 = *(AEGeometry **)(this + 0xd8);
    uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar45 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
    AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_98,pMVar45);
    local_f0 = 0x3f80000000000000;
    local_e8 = 0.0;
    AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
    lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
    AbyssEngine::Transform::Update(lVar68,bVar55);
    if ((int)(uint)(*(uint *)(this + 0x90) < 0x9c5) <= *(int *)(this + 0x94)) {
      *(undefined4 *)(this + 0x1c) = 0xc;
      PlayerEgo::StopEngineSound(this_00);
      *(undefined4 *)(this_00 + 0x1c) = 0x9c;
      PlayerEgo::PlayEngineSound(this_00);
      PlayerEgo::startSmokeEmission(this_00);
      PlayerEgo::setVisible(this_00,true);
      fVar56 = (float)PlayerEgo::setExhaustVisible(this_00,false);
      PlayerEgo::setSpeed(this_00,fVar56);
    }
    break;
  case 0xc:
    lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
    AbyssEngine::Transform::Update(lVar68,bVar55);
    fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    PlayerEgo::rotate(this_00,fVar56 / 3000.0,extraout_s1_87,3000.0);
    iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x44));
    if (iVar7 == 1) {
      PlayerEgo::getPosition();
      pVVar48 = (Vector *)(this + 0x28);
      AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
      local_98 = 0xc4fa0000c4fa0000;
      local_90 = -5000.0;
      AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
      TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
      *(undefined4 *)(this + 0x1c) = 0xd;
      goto LAB_00167db4;
    }
    break;
  case 0xd:
    fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    pLVar23 = this + 0x90;
    uVar47 = *(uint *)pLVar23;
    *(uint *)pLVar23 = uVar47 + param_1;
    *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
    PlayerEgo::rotate(this_00,fVar57 / 4000.0,fVar56,4000.0);
    if ((int)(uint)(*(uint *)pLVar23 < 0x1771) <= *(int *)(this + 0x94)) {
      PlayerEgo::getPosition();
      pVVar48 = (Vector *)(this + 0x28);
      AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
      local_98 = 0x442f0000;
      local_90 = -1700.0;
      AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
      TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
      uVar29 = 0xe;
      goto LAB_00167e44;
    }
    break;
  case 0xe:
    fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    pLVar23 = this + 0x90;
    uVar47 = *(uint *)pLVar23;
    *(uint *)pLVar23 = uVar47 + param_1;
    *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
    PlayerEgo::rotate(this_00,fVar57 / 5000.0,fVar56,5000.0);
    fVar56 = (float)VectorSignedToFloat(param_1 * -2,(byte)(in_fpscr >> 0x16) & 3);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_88,extraout_s2_38);
    if ((int)(uint)(*(uint *)pLVar23 < 0x2ee1) <= *(int *)(this + 0x94)) {
      PlayerEgo::getPosition();
      pVVar48 = (Vector *)(this + 0x28);
      AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
      local_98 = 0x455ac000c53b8000;
      local_90 = -6700.0;
      AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
      TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
      *(undefined4 *)(this + 0x1c) = 0xf;
      goto LAB_00167f02;
    }
    break;
  case 0xf:
    iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x58));
    if (iVar7 != 0) {
      Layout::startFade(Globals::layout,true,0xff,5000);
      uVar29 = 0x10;
      goto LAB_001627c2;
    }
    iVar37 = *(int *)(this + 0x1c);
  default:
    if ((iVar37 == 0x10) && (iVar7 = Layout::isFading(Globals::layout), iVar7 == 0)) {
      Layout::enableFillScreen(Globals::layout,true);
      Status::nextCampaignMission(SUB41(Globals::status,0));
      Globals::switch_to_target_setting = 1;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
LAB_00164462:
      Level::initStreamOutPosition = 0;
      goto switchD_001616e0_default;
    }
  }
LAB_0016101c:
  if (this[0x20] != (LevelScript)0x0) {
    LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),0x1e,false);
    iVar7 = Status::getWingmen(Globals::status);
    if ((iVar7 != 0) && (puVar8 = (uint *)Level::getEnemies(*(Level **)(this + 0x18)), *puVar8 != 0)
       ) {
      uVar47 = 0;
      do {
        pKVar44 = *(KIPlayer **)(puVar8[1] + uVar47 * 4);
        iVar7 = KIPlayer::isWingMan(pKVar44);
        if (iVar7 == 1) {
          pKVar44[0x129] = (KIPlayer)0x1;
        }
        uVar47 = uVar47 + 1;
      } while (uVar47 < *puVar8);
    }
    *(int *)(this + 0x24) = *(int *)(this + 0x24) + param_1;
    iVar7 = Level::getPlayer(*(Level **)(this + 0x18));
    if (((iVar7 != 0) && (iVar7 = Status::getCurrentCampaignMission(Globals::status), 1 < iVar7)) &&
       (7000 < *(int *)(this + 0x24))) {
      *(undefined4 *)(this + 0x24) = 0;
      *(undefined2 *)(this + 0x20) = 0x100;
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
      puVar9 = (undefined4 *)Level::getPlayer(*(Level **)(this + 0x18));
      Player::setVulnerable((Player *)*puVar9,true);
      this[0x11] = (LevelScript)0x0;
      pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
      PlayerEgo::setCollide(pPVar10,true);
      pSVar32 = Level::programmedStation;
      if (Level::programmedStation != (Station *)0x0) {
        pSVar11 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::equals(pSVar32,pSVar11);
        if (iVar7 == 0) {
          iVar37 = *(int *)(this + 0xd0);
          iVar7 = Level::getPlayer(*(Level **)(this + 0x18));
          Hud::hudEvent(iVar37,(PlayerEgo *)0x5,iVar7);
        }
      }
      Level::initStreamOutPosition = 0;
      if (Level::doInstantJump == '\0') {
        setAutoPilotToProgrammedStation(this);
      }
      iVar7 = Status::getWingmen(Globals::status);
      if ((iVar7 != 0) &&
         (puVar8 = (uint *)Level::getEnemies(*(Level **)(this + 0x18)), *puVar8 != 0)) {
        uVar47 = 0;
        do {
          pKVar44 = *(KIPlayer **)(puVar8[1] + uVar47 * 4);
          iVar7 = KIPlayer::isWingMan(pKVar44);
          if (iVar7 == 1) {
            pKVar44[0x129] = (KIPlayer)0x0;
          }
          uVar47 = uVar47 + 1;
        } while (uVar47 < *puVar8);
      }
    }
  }
  iVar7 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar7 == 5) {
    if (*(int *)(this + 0x1c) == 0) {
      PlayerEgo::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_98);
      fVar56 = (float)(**(code **)(**(int **)puVar6[1] + 0x48))
                                (*(int **)puVar6[1],*(float *)(this + 0x28) + 5000.0,
                                 *(undefined4 *)(this + 0x2c),*(float *)(this + 0x30) + 30000.0);
      AEGeometry::rotate(*(AEGeometry **)(*(int *)puVar6[1] + 8),fVar56,extraout_s1_06,
                         extraout_s2_05);
      (**(code **)(**(int **)puVar6[1] + 0xc))();
LAB_00161204:
      *(undefined4 *)(this + 0x1c) = 1;
    }
  }
  else {
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar7 == 0x1a) && (iVar7 = Status::inAlienOrbit(Globals::status), iVar7 == 1)) {
      iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 4));
      bVar54 = iVar7 == 1;
      if (bVar54) {
        iVar7 = *(int *)(this + 0x1c);
      }
      if (bVar54 && iVar7 == 0) {
        *(undefined4 *)(this + 0x1c) = 1;
        iVar7 = Level::getLandmarks(*(Level **)(this + 0x18));
        PlayerWormHole::reset(*(PlayerWormHole **)(*(int *)(iVar7 + 4) + 0xc),true);
      }
    }
    else {
      iVar7 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar7 == 0x32) {
        if (puVar5 != (uint *)0x0) {
LAB_0016181c:
          if (2 < *puVar5) {
            iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
            bVar54 = iVar7 == 1;
            if (bVar54) {
              iVar7 = *(int *)(this + 0x1c);
            }
            if (bVar54 && iVar7 == 0) {
              if (*puVar6 != 0) {
                uVar47 = 0;
                do {
                  iVar7 = KIPlayer::isWingMan(*(KIPlayer **)(puVar6[1] + uVar47 * 4));
                  if (iVar7 == 0) {
                    Player::setAlwaysFriend
                              (*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4),false);
                    Player::setAlwaysEnemy(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4),true);
                    Player::turnEnemy(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4));
                  }
                  uVar47 = uVar47 + 1;
                } while (uVar47 < *puVar6);
              }
              this_01 = (Standing *)Status::getStanding(Globals::status);
              Standing::setStanding(this_01,0,100);
              goto LAB_00161204;
            }
          }
        }
      }
      else {
        iVar7 = Status::getCurrentCampaignMission(Globals::status);
        if ((puVar5 != (uint *)0x0) && (iVar7 == 0x33)) goto LAB_0016181c;
      }
    }
  }
  pMVar12 = (Mission *)Status::getMission(Globals::status);
  iVar7 = Mission::isCampaignMission(pMVar12);
  if (iVar7 != 1) {
LAB_00161874:
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar7 == 0x2a) goto LAB_00161888;
    goto switchD_00161b94_caseD_1;
  }
  pMVar12 = (Mission *)Status::getMission(Globals::status);
  iVar7 = Mission::isEmpty(pMVar12);
  if (iVar7 == 1) goto LAB_00161874;
LAB_00161888:
  iVar7 = Status::getCurrentCampaignMission(Globals::status);
  pPVar3 = Globals::Canvas;
  if (0x5b < iVar7) {
    if (0x82 < iVar7) {
      if (iVar7 < 0x9a) {
        switch(iVar7) {
        case 0x83:
          if (*(int *)(this + 0x1c) == 2) {
            uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
            puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
            local_98 = *puVar15;
            local_90 = *(float *)(puVar15 + 1);
            local_8c = *(undefined4 *)((int)puVar15 + 0xc);
            local_88 = (undefined4)puVar15[2];
            local_84 = *(undefined4 *)((int)puVar15 + 0x14);
            local_80 = (undefined4)puVar15[3];
            uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
            local_78 = (undefined4)puVar15[4];
            local_74 = *(undefined4 *)((int)puVar15 + 0x24);
            local_70 = (undefined4)puVar15[5];
            local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
            local_68 = (undefined4)puVar15[6];
            local_64 = *(undefined4 *)((int)puVar15 + 0x34);
            uStack_60 = (undefined4)puVar15[7];
            AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
            pVVar49 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
            PlayerEgo::GetDirVector();
            pVVar48 = (Vector *)(this + 0x40);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 2.01);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            AEGeometry::getRightVector();
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.03);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            PlayerEgo::GetUpVector();
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.01);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
            AbyssEngine::AEMath::MatrixSetTranslation
                      ((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49);
            TargetFollowCamera::setLocal
                      (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c
                       ,local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                       local_68,local_64,uStack_60);
            iVar13 = RadioMessage::isOver(*(RadioMessage **)puVar5[1]);
            if (iVar13 == 1) {
              Player::setVulnerable(*(Player **)this_00,true);
              PlayerEgo::setCollide(this_00,true);
              PlayerEgo::setComputerControlled(this_00,false);
              PlayerEgo::setTurretMode(this_00,false);
              PlayerEgo::setFreeLookMode(this_00,false);
              TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
              TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
              resetCamera(this,*(Level **)(this + 0x18));
              LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
              this[0x11] = (LevelScript)0x0;
              *(undefined4 *)(this + 0x90) = 0;
              *(undefined4 *)(this + 0x94) = 0;
              *(undefined4 *)(this + 0x1c) = 3;
            }
          }
          else if (*(int *)(this + 0x1c) == 1) {
            uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
            puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
            local_98 = *puVar15;
            local_90 = *(float *)(puVar15 + 1);
            local_8c = *(undefined4 *)((int)puVar15 + 0xc);
            local_88 = (undefined4)puVar15[2];
            local_84 = *(undefined4 *)((int)puVar15 + 0x14);
            local_80 = (undefined4)puVar15[3];
            uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
            local_78 = (undefined4)puVar15[4];
            local_74 = *(undefined4 *)((int)puVar15 + 0x24);
            local_70 = (undefined4)puVar15[5];
            local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
            local_68 = (undefined4)puVar15[6];
            local_64 = *(undefined4 *)((int)puVar15 + 0x34);
            uStack_60 = (undefined4)puVar15[7];
            AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
            pVVar49 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
            PlayerEgo::GetDirVector();
            pVVar48 = (Vector *)(this + 0x40);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 2.01);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            AEGeometry::getRightVector();
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.03);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            PlayerEgo::GetUpVector();
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.01);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
            AbyssEngine::AEMath::MatrixSetTranslation
                      ((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49);
            TargetFollowCamera::setLocal
                      (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c
                       ,local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                       local_68,local_64,uStack_60);
            pLVar23 = this + 0x90;
            uVar47 = *(uint *)pLVar23 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
            *(uint *)pLVar23 = uVar47;
            *(int *)(this + 0x94) = iVar13;
            if ((int)(uint)(uVar47 < 0xbb9) <= iVar13) {
              *(undefined4 *)(this + 0x1c) = 2;
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x94) = 0;
            }
          }
          break;
        case 0x87:
          iVar7 = *(int *)(this + 0x1c);
          if (iVar7 == 0) {
            iVar7 = PlayerEgo::isDockedToDockingPoint(this_00);
            if ((iVar7 != 0) || ((int)(uint)(*(uint *)(this + 8) < 0xea61) <= *(int *)(this + 0xc)))
            {
              *(undefined4 *)(this + 0x1c) = 1;
              uVar47 = *puVar6;
              if (uVar47 != 0) {
                iVar13 = 25000;
                uVar53 = 0;
                uVar46 = puVar6[1];
                do {
                  piVar28 = *(int **)(uVar46 + uVar53 * 4);
                  if (piVar28[9] == 8) {
                    pcVar51 = *(code **)(*piVar28 + 0x44);
                    PlayerEgo::getPosition();
                    local_fc = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x16) & 3);
                    local_f8 = 5000.0;
                    local_f4 = 25000.0;
                    AbyssEngine::AEMath::operator+
                              ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
                    (*pcVar51)(piVar28,(AEMath *)&local_98);
                    (**(code **)(**(int **)(puVar6[1] + uVar53 * 4) + 0xc))();
                    KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + uVar53 * 4),true);
                    Player::setEnemy(*(Player **)(*(int *)(puVar6[1] + uVar53 * 4) + 4),
                                     *(Player **)this_00);
                    uVar46 = puVar6[1];
                    iVar7 = *(int *)(uVar46 + uVar53 * 4);
                    pvVar16 = *(void **)(iVar7 + 0x4c);
                    if (pvVar16 != (void *)0x0) {
                      if (*(void **)((int)pvVar16 + 4) != (void *)0x0) {
                        operator_delete__(*(void **)((int)pvVar16 + 4));
                      }
                      operator_delete(pvVar16);
                      uVar46 = puVar6[1];
                      iVar7 = *(int *)(uVar46 + uVar53 * 4);
                    }
                    *(undefined4 *)(iVar7 + 0x4c) = 0;
                    uVar47 = *puVar6;
                  }
                  uVar53 = uVar53 + 1;
                  iVar13 = iVar13 + 1000;
                } while (uVar53 < uVar47);
              }
              *(undefined4 *)(this + 0x90) = 0;
              *(undefined4 *)(this + 0x94) = 0;
              break;
            }
            iVar7 = *(int *)(this + 0x1c);
          }
          if (0 < iVar7) {
            pLVar23 = this + 0x90;
            uVar47 = *(uint *)pLVar23 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
            *(uint *)pLVar23 = uVar47;
            *(int *)(this + 0x94) = iVar13;
            if (iVar7 == 1) {
              pMVar12 = (Mission *)Status::getCampaignMission(Globals::status);
              iVar13 = Mission::getStatusValue(pMVar12);
              pMVar12 = (Mission *)Status::getCampaignMission(Globals::status);
              iVar7 = Mission::getProductionGoodAmount(pMVar12);
              if (iVar7 / 2 <= iVar13) {
                *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
              }
              uVar47 = *(uint *)pLVar23;
              iVar13 = *(int *)(this + 0x94);
            }
            if ((int)(uint)(uVar47 < 0x124f9) <= iVar13) {
              if (*(int *)(this + 0x1c) == 2) {
                *(undefined4 *)(this + 0x1c) = 3;
              }
              if (*puVar6 != 0) {
                iVar13 = 25000;
                uVar47 = 0;
                do {
                  pKVar44 = *(KIPlayer **)(puVar6[1] + uVar47 * 4);
                  if ((*(int *)(pKVar44 + 0x24) == 8) &&
                     (iVar7 = KIPlayer::isDead(pKVar44), iVar7 == 1)) {
                    (**(code **)(**(int **)(puVar6[1] + uVar47 * 4) + 0x18))();
                    piVar28 = *(int **)(puVar6[1] + uVar47 * 4);
                    pcVar51 = *(code **)(*piVar28 + 0x44);
                    PlayerEgo::getPosition();
                    local_fc = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x16) & 3);
                    local_f8 = 5000.0;
                    local_f4 = 25000.0;
                    AbyssEngine::AEMath::operator+
                              ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
                    (*pcVar51)(piVar28,(AEMath *)&local_98);
                    Player::setEnemy(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4),
                                     *(Player **)this_00);
                    iVar7 = *(int *)(puVar6[1] + uVar47 * 4);
                    pvVar16 = *(void **)(iVar7 + 0x4c);
                    if (pvVar16 != (void *)0x0) {
                      if (*(void **)((int)pvVar16 + 4) != (void *)0x0) {
                        operator_delete__(*(void **)((int)pvVar16 + 4));
                      }
                      operator_delete(pvVar16);
                      iVar7 = *(int *)(puVar6[1] + uVar47 * 4);
                    }
                    *(undefined4 *)(iVar7 + 0x4c) = 0;
                  }
                  iVar13 = iVar13 + 1000;
                  uVar47 = uVar47 + 1;
                } while (uVar47 < *puVar6);
              }
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x94) = 0;
            }
          }
          break;
        case 0x8b:
          iVar13 = 0;
          iVar7 = 0;
          do {
            iVar37 = PlayerFixedObject::getDockingType
                               (*(PlayerFixedObject **)(puVar6[1] + iVar13 * 4));
            iVar13 = iVar13 + 1;
            if (iVar37 != 3) {
              iVar7 = iVar7 + 1;
            }
          } while (iVar13 != 2);
          iVar13 = *(int *)(this + 0x1c);
          if (iVar13 == 0) {
            iVar13 = PlayerEgo::isDockedToDockingPoint(this_00);
            if (((iVar13 == 1) && (iVar13 = PlayerEgo::hackingWon(this_00), iVar13 == 1)) &&
               (iVar13 = PlayerEgo::getHackingGameDockIndex(this_00), -1 < iVar13)) {
              pLVar43 = *(Level **)(this + 0x18);
              iVar13 = PlayerEgo::getHackingGameDockIndex(this_00);
              pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(pLVar43,iVar13);
              AbyssEngine::String::String(aSStack_1fc,"",false);
              PlayerFixedObject::setName(pPVar40,aSStack_1fc);
              AbyssEngine::String::~String(aSStack_1fc);
              pLVar43 = *(Level **)(this + 0x18);
              iVar13 = PlayerEgo::getHackingGameDockIndex(this_00);
              pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(pLVar43,iVar13);
              PlayerFixedObject::setDockingType(pPVar40,0);
              iVar13 = *(int *)(this + 0x1c) + 1;
              *(int *)(this + 0x1c) = iVar13;
            }
            else {
              iVar13 = *(int *)(this + 0x1c);
            }
          }
          if (iVar13 == 1) {
            iVar13 = Player::isAlwaysEnemy(*(Player **)(*(int *)puVar6[1] + 4));
            if (((iVar13 == 0) &&
                (iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 4)), iVar13 == 1)
                ) && (piVar28 = (int *)Level::getEnemies(*(Level **)(this + 0x18)), *piVar28 != 0))
            {
              uVar47 = 0;
              do {
                iVar13 = KIPlayer::isWingMan(*(KIPlayer **)(puVar6[1] + uVar47 * 4));
                if ((iVar13 == 0) &&
                   (iVar13 = *(int *)(puVar6[1] + uVar47 * 4), *(char *)(iVar13 + 0x3b) == '\0')) {
                  Player::turnEnemy(*(Player **)(iVar13 + 4));
                }
                puVar5 = (uint *)Level::getEnemies(*(Level **)(this + 0x18));
                uVar47 = uVar47 + 1;
              } while (uVar47 < *puVar5);
            }
            iVar13 = PlayerEgo::isDockedToDockingPoint(this_00);
            if (((iVar13 == 1) && (iVar13 = PlayerEgo::hackingWon(this_00), iVar13 == 1)) &&
               (iVar13 = PlayerEgo::getHackingGameDockIndex(this_00), -1 < iVar13)) {
              pLVar43 = *(Level **)(this + 0x18);
              iVar13 = PlayerEgo::getHackingGameDockIndex(this_00);
              pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(pLVar43,iVar13);
              iVar13 = PlayerFixedObject::getDockingType(pPVar40);
              if (iVar7 == 1 && iVar13 == 3) {
                pLVar43 = *(Level **)(this + 0x18);
                iVar13 = PlayerEgo::getHackingGameDockIndex(this_00);
                pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(pLVar43,iVar13);
                PlayerFixedObject::setDockingType(pPVar40,2);
                PlayerEgo::setDockingState(this_00,2);
                *(undefined4 *)(Globals::status + 0x174) = 0;
                goto LAB_0016e2bc;
              }
            }
          }
          break;
        case 0x8e:
          if (*(int *)(this + 0x1c) < 2) {
            (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_f0);
            pRVar27 = (Route *)KIPlayer::getRoute(*(KIPlayer **)puVar6[1]);
            piVar28 = (int *)Route::getWaypoint(pRVar27,0);
            (**(code **)(*piVar28 + 0x28))((Vector *)&local_fc);
            AbyssEngine::AEMath::operator-
                      ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
            fVar56 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_98);
            if ((int)((uint)(fVar56 < 3000.0) << 0x1f) < 0) {
              (**(code **)(**(int **)puVar6[1] + 0x1c))(*(int **)puVar6[1],0);
            }
            iVar13 = *(int *)(this + 0x1c);
            if (iVar13 == 0) {
              iVar13 = PlayerEgo::getRoute(this_00);
              if (iVar13 != 0) {
                pRVar27 = (Route *)PlayerEgo::getRoute(this_00);
                iVar13 = Route::getWaypoint(pRVar27,0);
                if (*(char *)(iVar13 + 300) != '\0') {
                  *(undefined4 *)(this + 0x1c) = 1;
                  break;
                }
              }
              goto LAB_00165352;
            }
          }
          else {
LAB_00165352:
            iVar13 = *(int *)(this + 0x1c);
          }
          if (iVar13 == 1) {
            iVar13 = Level::getGasClouds(*(Level **)(this + 0x18));
            if (iVar13 != 0) {
              piVar28 = (int *)Level::getGasClouds(*(Level **)(this + 0x18));
              if (*piVar28 != 0) {
                uVar47 = 0;
                do {
                  iVar13 = Level::getGasClouds(*(Level **)(this + 0x18));
                  iVar13 = PlayerGasCloud::getSparks
                                     (*(PlayerGasCloud **)(*(int *)(iVar13 + 4) + uVar47 * 4));
                  if (iVar13 != 0) {
                    *(undefined4 *)(this + 0x1c) = 2;
                  }
                  puVar5 = (uint *)Level::getGasClouds(*(Level **)(this + 0x18));
                  uVar47 = uVar47 + 1;
                } while (uVar47 < *puVar5);
              }
              break;
            }
            iVar13 = *(int *)(this + 0x1c);
          }
          if (iVar13 == 2) {
            pSVar24 = (Ship *)Status::getShip(Globals::status);
            iVar13 = Ship::hasCargo(pSVar24,0xc9,1);
            if (iVar13 == 0) {
              pSVar24 = (Ship *)Status::getShip(Globals::status);
              iVar13 = Ship::hasCargo(pSVar24,0xca,1);
              if (iVar13 == 0) {
                pSVar24 = (Ship *)Status::getShip(Globals::status);
                iVar13 = Ship::hasCargo(pSVar24,0xcb,1);
                if (iVar13 == 0) {
                  pSVar24 = (Ship *)Status::getShip(Globals::status);
                  iVar13 = Ship::hasCargo(pSVar24,0xcc,1);
                  if (iVar13 == 0) {
                    pSVar24 = (Ship *)Status::getShip(Globals::status);
                    iVar13 = Ship::hasCargo(pSVar24,0xcd,1);
                    if (iVar13 != 1) break;
                  }
                }
              }
            }
            (**(code **)(**(int **)puVar6[1] + 0x1c))(*(int **)puVar6[1],0x40066666);
LAB_00167f9c:
            uVar29 = 3;
LAB_0016c2dc:
            *(undefined4 *)(this + 0x1c) = uVar29;
          }
          break;
        case 0x90:
          fVar56 = (float)VectorSignedToFloat(param_1 * 5,(byte)(in_fpscr >> 0x16) & 3);
          this[0x11] = (LevelScript)0x1;
          AEGeometry::moveForward(*(AEGeometry **)(this + 0xcc),fVar56);
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.28,extraout_s1_36,0.28);
          iVar7 = *(int *)(this + 0x1c);
          if (iVar7 == 3) {
            pLVar23 = this + 0x90;
            uVar46 = *(uint *)pLVar23 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
            *(uint *)pLVar23 = uVar46;
            *(int *)(this + 0x94) = iVar13;
            uVar47 = *puVar6;
            if (1 < uVar47) {
              uVar46 = 1;
              do {
                if (*(int *)(*(int *)(puVar6[1] + uVar46 * 4) + 0x78) == 0x2c) {
                  iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
                  if ((iVar13 < 10) &&
                     (pPVar22 = *(PlayerFighter **)(puVar6[1] + uVar46 * 4),
                     pPVar22[0x138] == (PlayerFighter)0x0)) {
                    PlayerFighter::setCloakingPossible(pPVar22,true);
                    PlayerFighter::cloak(*(PlayerFighter **)(puVar6[1] + uVar46 * 4),20000,true);
                  }
                  fVar56 = (float)__aeabi_l2f(*(undefined4 *)pLVar23,*(undefined4 *)(this + 0x94));
                  AEGeometry::moveForward
                            (*(AEGeometry **)(*(int *)(puVar6[1] + uVar46 * 4) + 8),fVar56 * 0.05);
                  uVar47 = *puVar6;
                }
                uVar46 = uVar46 + 1;
              } while (uVar46 < uVar47);
              uVar46 = *(uint *)pLVar23;
              iVar13 = *(int *)(this + 0x94);
            }
            if ((int)(-(uint)(4000 < uVar46) - iVar13) < 0 !=
                (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(4000 < uVar46)))) {
              fVar56 = (float)__aeabi_l2f(uVar46 - 4000,iVar13 - (uint)(uVar46 < 4000),iVar13,
                                          4000 - uVar46);
              AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),fVar56 * 0.05);
              if ((int)(uint)(*(uint *)pLVar23 < 0x1b59) <= *(int *)(this + 0x94)) {
                *(undefined4 *)(this + 0x1c) = 4;
                Status::nextCampaignMission(SUB41(Globals::status,0));
                pSVar33 = Globals::status;
                pSVar32 = (Station *)Status::getStation(Globals::status);
                Status::setStation(pSVar33,pSVar32);
                pSVar33 = Globals::status;
                pSVar32 = (Station *)Status::getStation(Globals::status);
                Status::departStation(pSVar33,pSVar32);
                if (Level::initStreamOutPositionAfterCutscene != '\0') {
                  Level::initStreamOutPosition = 1;
                  Level::initStreamOutPositionAfterCutscene = '\0';
                }
LAB_001667b4:
                AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
              }
            }
          }
          else if (iVar7 == 2) {
            iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0xc));
            if (iVar13 == 1) {
              iVar13 = 3;
              goto LAB_0016bf10;
            }
          }
          else if (iVar7 == 1) {
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xcc));
            *(undefined4 *)(this + 0x1c) = 2;
          }
          break;
        case 0x91:
          iVar7 = 0;
          fVar56 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
          pLVar23 = this + 0x90;
          do {
            iVar50 = AEGeometry::moveForward
                               (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),fVar56);
            bVar55 = SBORROW4(iVar7,1);
            iVar37 = iVar7 + -1;
            if (0 < iVar7) {
              iVar50 = *(int *)(this + 0x1c);
              bVar55 = SBORROW4(iVar50,2);
              iVar37 = iVar50 + -2;
            }
            fVar56 = extraout_s0_05;
            if ((iVar37 < 0 == bVar55) &&
               ((iVar50 != 4 ||
                (iVar37 = *(int *)(this + 0x94),
                (int)(-(uint)(1000 < *(uint *)pLVar23) - iVar37) < 0 ==
                (SBORROW4(0,iVar37) != SBORROW4(-iVar37,(uint)(1000 < *(uint *)pLVar23))))))) {
              fVar56 = (float)Player::shoot(*(int *)(*(int *)(puVar6[1] + iVar7 * 4) + 4),
                                            (longlong)param_1,false);
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0xd);
          iVar7 = *(int *)(this + 0x1c);
          if (iVar7 == 1) {
LAB_00163102:
            iVar7 = RadioMessage::isOver(*(RadioMessage **)puVar5[1]);
            if (iVar7 == 0) {
              iVar7 = *(int *)(this + 0x1c);
              goto LAB_00165ae4;
            }
            PlayerEgo::setTurretMode(this_00,false);
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            resetCamera(this,*(Level **)(this + 0x18));
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            Player::setVulnerable(*(Player **)this_00,false);
            PlayerEgo::setVisible(this_00,false);
            PlayerEgo::setFreeze(this_00,true);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            TargetFollowCamera::setTarget(pTVar38,*(AEGeometry **)(**(int **)(iVar13 + 4) + 8));
            AEGeometry::getPosition();
            pVVar48 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            fVar56 = (float)AEGeometry::getDirection();
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
            fVar56 = (float)AEGeometry::getRightVector();
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
            KIPlayer::setVisible(*(KIPlayer **)puVar6[1],true);
            KIPlayer::setActive(SUB41(*(undefined4 *)puVar6[1],0));
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
LAB_0016324e:
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          }
          else {
            if (iVar7 == 0) {
              iVar7 = 0;
              do {
                KIPlayer::setEnemies(*(Array **)(puVar6[1] + iVar7 * 4));
                Player::setEnemy(*(Player **)(*(int *)(puVar6[1] + iVar7 * 4) + 4),
                                 *(Player **)(*(int *)(puVar6[1] + 0x38) + 4));
                iVar7 = iVar7 + 1;
              } while (iVar7 != 0xd);
              pEVar42 = operator_new(0x68);
              Explosion::Explosion(pEVar42,0);
              *(Explosion **)(this + 200) = pEVar42;
              fVar56 = (float)Explosion::addFireStreaks(pEVar42);
              Explosion::setScaling(fVar56);
              *(undefined4 *)(this + 0x1c) = 1;
              goto LAB_00163102;
            }
LAB_00165ae4:
            switch(iVar7) {
            case 2:
              uVar47 = *(uint *)pLVar23 + param_1;
              iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
              *(uint *)pLVar23 = uVar47;
              *(int *)(this + 0x94) = iVar13;
              if ((int)(uint)(uVar47 < 0x3e9) <= iVar13) {
                Player::shoot(*(int *)(*(int *)puVar6[1] + 4),(longlong)param_1,false);
                pAVar52 = operator_new(0xc0);
                AEGeometry::AEGeometry(pAVar52,Globals::Canvas);
                *(AEGeometry **)(this + 0xcc) = pAVar52;
                (**(code **)(**(int **)puVar6[1] + 0x28))(&local_98);
                AEGeometry::setPosition((Vector *)pAVar52);
                AbyssEngine::AEMath::Vector::operator=
                          ((Vector *)(this + 0x28),
                           *(Vector **)
                            (**(int **)(**(int **)(**(int **)(*(int *)puVar6[1] + 4) + 4) + 4) +
                            0x18));
                local_98 = 0x3f80000000000000;
                local_90 = 0.0;
                AEGeometry::setDirection
                          (*(AEGeometry **)(this + 0xcc),(Vector *)(this + 0x28),(Vector *)&local_98
                          );
                AEGeometry::setVisible(*(AEGeometry **)(this + 0xcc),false);
                TargetFollowCamera::setTarget
                          (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xcc));
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) = 0;
LAB_0016de2c:
                *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
              }
              break;
            case 3:
              fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
              AEGeometry::moveForward
                        (*(AEGeometry **)(this + 0xcc),
                         fVar56 * *(float *)(**(int **)(**(int **)(**(int **)(*(int *)puVar6[1] + 4)
                                                                  + 4) + 4) + 0x50));
              uVar47 = *(uint *)pLVar23 + param_1;
              iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
              *(uint *)pLVar23 = uVar47;
              *(int *)(this + 0x94) = iVar13;
              if ((int)(uint)(uVar47 < 0x1389) <= iVar13) {
                pMVar45 = (Matrix *)
                          AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(puVar6[1] + 0x38) + 8));
                AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x4c),pMVar45);
                ParticleSystemManager::systemSetMatrix
                          (*(int *)(*(int *)(this + 0x18) + 0x74),
                           *(Matrix **)(*(int *)(this + 0x18) + 0x54));
                ParticleSystemManager::enableSystemEmit
                          (*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x74),
                           *(int *)(*(int *)(this + 0x18) + 0x54),true);
                pEVar42 = *(Explosion **)(this + 200);
                AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_98,(Matrix *)(this + 0x4c));
                local_f0 = 0;
                local_e8 = 0.0;
                Explosion::start(pEVar42,(Vector *)&local_98,(Vector *)&local_f0);
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) = 0;
                goto LAB_0016de2c;
              }
              break;
            case 4:
              fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
              uVar47 = *(uint *)pLVar23;
              *(uint *)pLVar23 = uVar47 + param_1;
              *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1)
              ;
              Explosion::update(*(Explosion **)(this + 200),(int)(fVar56 * 0.5),
                                (TargetFollowCamera *)0x0);
              if ((int)(uint)(*(uint *)pLVar23 < 0x144) <= *(int *)(this + 0x94)) {
                pMVar45 = *(Matrix **)(*(int *)(puVar6[1] + 0x34) + 8);
                AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(puVar6[1] + 0x38) + 8));
                AEGeometry::setMatrix(pMVar45);
                KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 0x34),true);
                KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + 0x34),0));
                KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 0x38),false);
                KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + 0x38),0));
                uVar47 = puVar6[1];
                *(undefined1 *)(*(int *)(uVar47 + 0x38) + 0x70) = 1;
                uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                                   (Globals::Canvas,
                                    *(uint *)(*(int *)(*(int *)(uVar47 + 0x34) + 8) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) = 0;
                *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
              }
              break;
            case 5:
              uVar47 = *(uint *)pLVar23;
              *(uint *)pLVar23 = uVar47 + param_1;
              *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1)
              ;
              uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                                 (Globals::Canvas,
                                  *(uint *)(*(int *)(*(int *)(puVar6[1] + 0x34) + 8) + 0xc));
              fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
              bVar55 = (bool)__aeabi_f2lz(fVar56 * 0.3);
              AbyssEngine::Transform::Update(CONCAT44(extraout_r1_02,uVar29),bVar55);
              iVar7 = 0;
              pVVar48 = (Vector *)(this + 0x28);
              do {
                AEGeometry::getDirection();
                AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
                if (-(*(int *)(this + 0x94) + -1 + (uint)(2000 < *(uint *)pLVar23)) <
                    (uint)(*(uint *)pLVar23 - 0x7d1 < 2999)) {
                  AEGeometry::getRightVector();
                  fVar57 = (float)__aeabi_l2f(*(undefined4 *)pLVar23,*(undefined4 *)(this + 0x94));
                  AbyssEngine::AEMath::operator*
                            ((AEMath *)&local_98,(Vector *)&local_f0,fVar57 / 100000.0);
                  AbyssEngine::AEMath::Vector::operator-=(pVVar48,(Vector *)&local_98);
                }
                pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8);
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,pVVar48);
                local_f0 = 0x3f80000000000000;
                local_e8 = 0.0;
                AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
                lVar68 = (ulonglong)*(uint *)pLVar23 * (ulonglong)(uint)param_1;
                fVar57 = (float)__aeabi_l2f((int)lVar68,
                                            *(int *)(this + 0x94) * param_1 +
                                            *(uint *)pLVar23 * iVar13 +
                                            (int)((ulonglong)lVar68 >> 0x20));
                AEGeometry::moveForward
                          (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),fVar57 * 0.001);
                iVar7 = iVar7 + 1;
              } while (iVar7 != 0xd);
              Explosion::update(*(Explosion **)(this + 200),(int)(fVar56 * 0.5),
                                (TargetFollowCamera *)0x0);
              iVar13 = *(int *)(this + 0x94);
              if ((int)(-(uint)(10000 < *(uint *)pLVar23) - iVar13) < 0 !=
                  (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(10000 < *(uint *)pLVar23)))) {
                iVar13 = 0;
                ParticleSystemManager::enableSystemEmit
                          (*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x74),
                           *(int *)(*(int *)(this + 0x18) + 0x54),false);
                do {
                  KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + iVar13 * 4),0));
                  KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar13 * 4),false);
                  piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
                  (**(code **)(*piVar28 + 0x48))(piVar28,0x47435000,0x47435000,0x47435000);
                  iVar13 = iVar13 + 1;
                } while (iVar13 != 0xd);
                pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
                PlayerEgo::resetGunDelay(pPVar10);
                TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
                TargetFollowCamera::setTarget
                          (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
                PlayerEgo::setComputerControlled(this_00,false);
                Player::setVulnerable(*(Player **)this_00,true);
                PlayerEgo::setFreeze(this_00,false);
                PlayerEgo::setVisible(this_00,true);
                *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
                *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
                resetCamera(this,*(Level **)(this + 0x18));
                LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
                iVar13 = *(int *)(this + 0xd4);
                *(undefined4 *)(iVar13 + 4) = 0;
                *(undefined4 *)(iVar13 + 8) = 0;
                this[0x11] = (LevelScript)0x0;
                goto LAB_0016324e;
              }
            }
          }
        }
      }
      else if (iVar7 == 0x9a) {
        iVar7 = *(int *)(this + 0x1c);
        fVar56 = extraout_s0_03;
        fVar57 = extraout_s1_17;
        if (iVar7 == 0) {
          iVar7 = RadioMessage::isTriggered(*(RadioMessage **)puVar5[1]);
          if (iVar7 == 1) {
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              resetCamera(this,*(Level **)(this + 0x18));
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            PlayerEgo::setTurretMode(this_00,false);
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            PlayerEgo::setComputerControlled(this_00,true);
            fVar56 = (float)Player::setVulnerable(*(Player **)this_00,false);
            PlayerEgo::setSpeed(this_00,fVar56);
            iVar13 = PlayerEgo::autoTurretIsEnabled(this_00);
            this[0xaa] = SUB41(iVar13,0);
            if (iVar13 != 0) {
              PlayerEgo::setAutoTurret(this_00,false);
            }
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            TargetFollowCamera::setTarget
                      (pTVar38,*(AEGeometry **)(*(int *)(*(int *)(iVar13 + 4) + 8) + 8));
            Level::getEnemies(*(Level **)(this + 0x18));
            AEGeometry::getPosition();
            pVVar48 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            local_98 = 0x4396000043960000;
            local_90 = 5800.0;
            AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
            PlayerFighter::setAIDisabled(*(PlayerFighter **)puVar6[1],true);
            uVar46 = *puVar6;
            uVar47 = puVar6[1];
            if (uVar46 != 0) {
              uVar53 = 0;
              do {
                iVar13 = *(int *)(uVar47 + uVar53 * 4);
                if (*(int *)(iVar13 + 0x24) == 9) {
                  pAVar52 = *(AEGeometry **)(iVar13 + 8);
                  Level::getPlayer(*(Level **)(this + 0x18));
                  PlayerEgo::getPosition();
                  (**(code **)(**(int **)(puVar6[1] + uVar53 * 4) + 0x28))((Vector *)&local_a4);
                  AbyssEngine::AEMath::operator-
                            ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
                  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
                  local_b0 = 0;
                  local_ac = 0x3f800000;
                  local_a8 = 0;
                  AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_b0);
                  PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + uVar53 * 4),true);
                  uVar46 = *puVar6;
                  uVar47 = puVar6[1];
                }
                uVar53 = uVar53 + 1;
              } while (uVar53 < uVar46);
            }
            *(undefined1 *)(*(int *)(uVar47 + 4) + 0x6c) = 1;
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            pLVar43 = *(Level **)(this + 0x18);
LAB_00169ef0:
            LODManager::forceUpdate(*(LODManager **)pLVar43,param_1,false);
            goto switchD_00161b94_caseD_1;
          }
          iVar7 = *(int *)(this + 0x1c);
          fVar56 = extraout_s0_06;
          fVar57 = extraout_s1_43;
        }
        switch(iVar7) {
        case 1:
          PlayerEgo::setSpeed(this_00,fVar56);
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          uVar47 = *puVar6;
          if (uVar47 != 0) {
            uVar46 = 0;
            fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            fVar56 = fVar56 * 0.5;
            do {
              iVar7 = *(int *)(puVar6[1] + uVar46 * 4);
              if (*(int *)(iVar7 + 0x24) == 9) {
                fVar56 = (float)AEGeometry::moveForward(*(AEGeometry **)(iVar7 + 8),fVar56);
                uVar47 = *puVar6;
              }
              uVar46 = uVar46 + 1;
            } while (uVar46 < uVar47);
          }
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 4));
          if (iVar7 == 0) {
            uVar47 = *(uint *)(this + 0x90);
            iVar13 = *(int *)(this + 0x94);
          }
          else {
            uVar46 = *(uint *)(this + 0x90);
            uVar47 = uVar46 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar46,param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
          }
          if ((int)(uint)(uVar47 < 0x5dd) <= iVar13) {
            uVar47 = *puVar6;
            if (uVar47 != 0) {
              uVar46 = 0;
              do {
                iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
                if (*(int *)(iVar13 + 0x24) == 9) {
                  KIPlayer::setActive(SUB41(iVar13,0));
                  KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + uVar46 * 4),false);
                  uVar47 = *puVar6;
                }
                uVar46 = uVar46 + 1;
              } while (uVar46 < uVar47);
            }
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            PlayerEgo::getPosition();
            pVVar48 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            local_98 = 0x43c80000c3af0000;
            local_90 = -1500.0;
            AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          break;
        case 2:
          PlayerEgo::setSpeed(this_00,fVar56);
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar56 = fVar56 * 0.25;
          AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),0.25);
          pPVar3 = Globals::Canvas;
          uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
          local_98 = *puVar15;
          local_90 = *(float *)(puVar15 + 1);
          local_8c = *(undefined4 *)((int)puVar15 + 0xc);
          local_88 = (undefined4)puVar15[2];
          local_84 = *(undefined4 *)((int)puVar15 + 0x14);
          local_80 = (undefined4)puVar15[3];
          uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
          local_78 = (undefined4)puVar15[4];
          local_74 = *(undefined4 *)((int)puVar15 + 0x24);
          local_70 = (undefined4)puVar15[5];
          local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
          local_68 = (undefined4)puVar15[6];
          local_64 = *(undefined4 *)((int)puVar15 + 0x34);
          uStack_60 = (undefined4)puVar15[7];
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
          pVVar49 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          PlayerEgo::GetDirVector();
          pVVar48 = (Vector *)(this + 0x40);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.008);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getRightVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * -0.05);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          PlayerEgo::GetUpVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.0051);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
          AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49)
          ;
          TargetFollowCamera::setLocal
                    (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c,
                     local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                     local_68,local_64,uStack_60);
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
          if (iVar7 == 0) {
            uVar47 = *(uint *)(this + 0x90);
            iVar13 = *(int *)(this + 0x94);
          }
          else {
            uVar46 = *(uint *)(this + 0x90);
            uVar47 = uVar46 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar46,param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
          }
          if ((int)(uint)(uVar47 < 0x3e9) <= iVar13) {
            PlayerEgo::setSpeed(this_00,extraout_s0_12);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            TargetFollowCamera::setTarget
                      (pTVar38,*(AEGeometry **)(*(int *)(*(int *)(iVar13 + 4) + 4) + 8));
            Level::getEnemies(*(Level **)(this + 0x18));
            AEGeometry::getPosition();
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
            local_f0 = 0x457a000000000000;
            local_e8 = 26000.0;
LAB_0016dc7e:
            AbyssEngine::AEMath::Vector::operator+=((Vector *)(this + 0x28),(Vector *)&local_f0);
            TargetFollowCamera::setPosition
                      (*(TargetFollowCamera **)(this + 0x14),(Vector *)(this + 0x28));
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            goto LAB_0016de2c;
          }
          break;
        case 3:
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0xc));
          if (iVar7 != 0) {
            uVar47 = *(uint *)(this + 0x90);
            *(uint *)(this + 0x90) = uVar47 + param_1;
            *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          }
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar56 = (float)TargetFollowCamera::translate
                                    (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.5,
                                     extraout_s1_x00110,0.5);
          if ((int)(uint)(*(uint *)(this + 0x90) < 0x3e9) <= *(int *)(this + 0x94)) {
            PlayerEgo::setSpeed(this_00,fVar56);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            PlayerEgo::getPosition();
            pVVar48 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            local_98 = 0x43c80000c3af0000;
            local_90 = -1500.0;
            AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
LAB_0016dbee:
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          break;
        case 4:
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar56 = fVar56 * 0.25;
          AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),0.25);
          pPVar3 = Globals::Canvas;
          uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
          local_98 = *puVar15;
          local_90 = *(float *)(puVar15 + 1);
          local_8c = *(undefined4 *)((int)puVar15 + 0xc);
          local_88 = (undefined4)puVar15[2];
          local_84 = *(undefined4 *)((int)puVar15 + 0x14);
          local_80 = (undefined4)puVar15[3];
          uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
          local_78 = (undefined4)puVar15[4];
          local_74 = *(undefined4 *)((int)puVar15 + 0x24);
          local_70 = (undefined4)puVar15[5];
          local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
          local_68 = (undefined4)puVar15[6];
          local_64 = *(undefined4 *)((int)puVar15 + 0x34);
          uStack_60 = (undefined4)puVar15[7];
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
          pVVar49 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          PlayerEgo::GetDirVector();
          pVVar48 = (Vector *)(this + 0x40);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.008);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getRightVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * -0.05);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          PlayerEgo::GetUpVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.005);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
          AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49)
          ;
          TargetFollowCamera::setLocal
                    (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c,
                     local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                     local_68,local_64,uStack_60);
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x10));
          if (iVar7 == 0) {
            uVar47 = *(uint *)(this + 0x90);
            iVar13 = *(int *)(this + 0x94);
          }
          else {
            uVar46 = *(uint *)(this + 0x90);
            uVar47 = uVar46 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar46,param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
          }
          if ((int)(uint)(uVar47 < 0x3e9) <= iVar13) {
            PlayerEgo::setSpeed(this_00,extraout_s0_13);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            TargetFollowCamera::setTarget
                      (pTVar38,*(AEGeometry **)(*(int *)(*(int *)(iVar13 + 4) + 4) + 8));
            Level::getEnemies(*(Level **)(this + 0x18));
            AEGeometry::getPosition();
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
            local_f0 = 0x457a000000000000;
            local_e8 = 42000.0;
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            goto LAB_0016de2c;
          }
          break;
        case 5:
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,fVar57,fVar56 * 0.1);
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x14));
          if (iVar7 == 0) {
            uVar47 = *(uint *)(this + 0x90);
            iVar13 = *(int *)(this + 0x94);
          }
          else {
            uVar46 = *(uint *)(this + 0x90);
            uVar47 = uVar46 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar46,param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
          }
          if ((int)(uint)(uVar47 < 0x3e9) <= iVar13) {
            PlayerEgo::setSpeed(this_00,extraout_s0_14);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            PlayerEgo::getPosition();
            pVVar48 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            local_98 = 0x43c8000043160000;
            local_90 = -1500.0;
            AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            local_98 = 0xc61c4000;
            local_90 = 22000.0;
            (**(code **)(**(int **)puVar6[1] + 0x44))(*(int **)puVar6[1],&local_98);
            pPVar22 = *(PlayerFighter **)puVar6[1];
            pPVar22[0x13a] = (PlayerFighter)0x0;
            PlayerFighter::setAIDisabled(pPVar22,false);
            uVar47 = *puVar6;
            if (uVar47 != 0) {
              uVar46 = 0;
              do {
                iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
                if (*(int *)(iVar13 + 0x24) == 9) {
                  KIPlayer::setActive(SUB41(iVar13,0));
                  Player::setVulnerable(*(Player **)(*(int *)(puVar6[1] + uVar46 * 4) + 4),true);
                  uVar47 = *puVar6;
                }
                uVar46 = uVar46 + 1;
              } while (uVar46 < uVar47);
            }
            goto LAB_0016dbee;
          }
          break;
        case 6:
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar56 = fVar56 * 0.25;
          AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),0.25);
          pPVar3 = Globals::Canvas;
          uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
          local_98 = *puVar15;
          local_90 = *(float *)(puVar15 + 1);
          local_8c = *(undefined4 *)((int)puVar15 + 0xc);
          local_88 = (undefined4)puVar15[2];
          local_84 = *(undefined4 *)((int)puVar15 + 0x14);
          local_80 = (undefined4)puVar15[3];
          uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
          local_78 = (undefined4)puVar15[4];
          local_74 = *(undefined4 *)((int)puVar15 + 0x24);
          local_70 = (undefined4)puVar15[5];
          local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
          local_68 = (undefined4)puVar15[6];
          local_64 = *(undefined4 *)((int)puVar15 + 0x34);
          uStack_60 = (undefined4)puVar15[7];
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
          pVVar49 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          PlayerEgo::GetDirVector();
          pVVar48 = (Vector *)(this + 0x40);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.008);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getRightVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.05);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          PlayerEgo::GetUpVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.005);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
          AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49)
          ;
          TargetFollowCamera::setLocal
                    (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c,
                     local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                     local_68,local_64,uStack_60);
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x18));
          if (iVar7 == 0) {
            uVar47 = *(uint *)(this + 0x90);
            iVar13 = *(int *)(this + 0x94);
          }
          else {
            uVar46 = *(uint *)(this + 0x90);
            uVar47 = uVar46 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar46,param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
          }
          if ((int)(uint)(uVar47 < 0x3e9) <= iVar13) {
            PlayerEgo::setSpeed(this_00,extraout_s0_15);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            TargetFollowCamera::setTarget(pTVar38,*(AEGeometry **)(**(int **)(iVar13 + 4) + 8));
            Level::getEnemies(*(Level **)(this + 0x18));
            AEGeometry::getPosition();
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
            local_f0 = 0x4396000043480000;
            local_e8 = 1800.0;
            goto LAB_0016dc7e;
          }
          break;
        case 7:
          iVar13 = KIPlayer::isDocked(*(KIPlayer **)puVar6[1]);
          if (iVar13 == 1) {
            iVar13 = *(int *)(this + 0x1c) + 1;
LAB_0016bf10:
            *(int *)(this + 0x1c) = iVar13;
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          break;
        case 8:
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(uint)(uVar47 < 0x7d1) <= iVar13) {
            *(undefined4 *)(this + 0x1c) = 9;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          break;
        case 9:
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x1c));
          if (iVar7 == 0) {
            uVar47 = *(uint *)(this + 0x90);
            iVar13 = *(int *)(this + 0x94);
          }
          else {
            uVar46 = *(uint *)(this + 0x90);
            uVar47 = uVar46 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar46,param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
          }
          if ((int)(uint)(uVar47 < 0x7d1) <= iVar13) {
            if (*puVar6 != 0) {
              uVar47 = 0;
              do {
                iVar13 = *(int *)(puVar6[1] + uVar47 * 4);
                if (*(int *)(iVar13 + 0x24) == 9) {
                  *(undefined1 *)(iVar13 + 0x21) = 1;
                  KIPlayer::setActive(SUB41(iVar13,0));
                  KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + uVar47 * 4),true);
                  PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + uVar47 * 4),false);
                  if ((int)uVar47 % 3 == 0) {
                    pPVar41 = *(Player **)(*(int *)puVar6[1] + 4);
                  }
                  else {
                    pPVar41 = *(Player **)this_00;
                  }
                  Player::setEnemy(*(Player **)(((int *)puVar6[1])[uVar47] + 4),pPVar41);
                }
                uVar47 = uVar47 + 1;
              } while (uVar47 < *puVar6);
            }
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            *(undefined4 *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 0x24) = 8;
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            *(undefined1 *)(*(int *)(*(int *)(iVar13 + 4) + 4) + 0x70) = 0;
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            Player::setAlwaysFriend(*(Player **)(*(int *)(*(int *)(iVar13 + 4) + 4) + 4),false);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            Player::setAlwaysEnemy(*(Player **)(*(int *)(*(int *)(iVar13 + 4) + 4) + 4),true);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            Player::setEnemies(*(Player **)(**(int **)(iVar13 + 4) + 4),(Array *)0x0);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            Player::setVulnerable(*(Player **)(**(int **)(iVar13 + 4) + 4),true);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::resetGunDelay(pPVar10);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            fVar56 = (float)PlayerEgo::setFreeze(this_00,false);
            PlayerEgo::setSpeed(this_00,fVar56);
            PlayerEgo::setComputerControlled(this_00,false);
            fVar56 = (float)Player::setVulnerable(*(Player **)this_00,true);
            PlayerEgo::setPosition(fVar56,extraout_s1_x00123,extraout_s2_45);
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            resetCamera(this,*(Level **)(this + 0x18));
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            this[0x11] = (LevelScript)0x0;
            if (this[0xaa] != (LevelScript)0x0) {
              PlayerEgo::setAutoTurret(this_00,true);
            }
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            goto LAB_0016de2c;
          }
          break;
        case 10:
          iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x20));
          if ((iVar13 == 1) && (*(int *)this < 1)) {
            *(undefined4 *)this = 91000;
            *(undefined4 *)(this + 8) = 0;
            *(undefined4 *)(this + 0xc) = 0;
            pOVar17 = operator_new(0x1c);
            Objective::Objective(pOVar17,3,91000,*(Level **)(this + 0x18));
            *(Objective **)(*(int *)(this + 0x18) + 0x2c) = pOVar17;
          }
          iVar13 = PlayerEgo::isDockedToDockingPoint(this_00);
          if ((iVar13 == 1) && (iVar13 = PlayerEgo::hackingWon(this_00), iVar13 == 1)) {
            *(undefined4 *)(this + 0x1c) = 0xb;
            iVar13 = *(int *)(this + 0x18);
            if (*(Objective **)(iVar13 + 0x2c) != (Objective *)0x0) {
              pvVar16 = (void *)Objective::~Objective(*(Objective **)(iVar13 + 0x2c));
              operator_delete(pvVar16);
              iVar13 = *(int *)(this + 0x18);
            }
            *(undefined4 *)(iVar13 + 0x2c) = 0;
            uVar47 = *puVar6;
            if (uVar47 != 0) {
              uVar46 = 0;
              do {
                iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
                if (*(int *)(iVar13 + 0x24) == 9) {
                  Player::setEnemies(*(Player **)(iVar13 + 4),(Array *)0x0);
                  uVar47 = *puVar6;
                }
                uVar46 = uVar46 + 1;
              } while (uVar46 < uVar47);
            }
            *(undefined4 *)this = 0;
          }
        }
      }
      else {
        if (iVar7 != 0x9d) {
          if (iVar7 == 0x9e) {
            iVar7 = *(int *)(this + 0x1c);
            if (iVar7 == 3) {
              auVar66._8_8_ = in_q8._8_8_ & 0xffff0000ffff0000 | (ulonglong)(uint)param_1 & 0xffff;
              auVar66._0_8_ = in_q8._0_8_ & 0xffff0000ffff0000 | (ulonglong)(uint)param_1 & 0xffff;
              pLVar23 = this + 0x90;
              auVar66 = VectorAdd(*(undefined1 (*) [16])pLVar23,auVar66,8);
              *(longlong *)pLVar23 = auVar66._0_8_;
              *(longlong *)(this + 0x98) = auVar66._8_8_;
              if (auVar66._4_4_ < (int)(uint)(auVar66._0_4_ < 0xfa1)) {
                iVar13 = auVar66._12_4_;
                uVar47 = auVar66._8_4_;
              }
              else {
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) = 0;
                (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_f0);
                PlayerEgo::getPosition();
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
                fVar56 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_98);
                if (((int)((uint)(fVar56 < 25000.0) << 0x1f) < 0) &&
                   (iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,100), 0x3c < iVar13)) {
                  iVar13 = 1;
                  do {
                    iVar7 = Player::isActive(*(Player **)(*(int *)(puVar6[1] + iVar13 * 4) + 4));
                    if (iVar7 == 0) {
                      (**(code **)(**(int **)(puVar6[1] + iVar13 * 4) + 0x18))();
                      KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + iVar13 * 4),0));
                      piVar28 = (int *)((undefined4 *)puVar6[1])[iVar13];
                      pcVar51 = *(code **)(*piVar28 + 0x44);
                      (**(code **)(**(int **)puVar6[1] + 0x28))(&local_98);
                      (*pcVar51)(piVar28,&local_98);
                      Player::turnEnemy(*(Player **)(*(int *)(puVar6[1] + iVar13 * 4) + 4));
                      break;
                    }
                    iVar13 = iVar13 + 1;
                  } while (iVar13 < 4);
                }
                uVar47 = *(uint *)(this + 0x98);
                iVar13 = *(int *)(this + 0x9c);
              }
              if ((int)(uint)(uVar47 < 0x61a9) <= iVar13) {
                *(undefined4 *)(this + 0x98) = 0;
                *(undefined4 *)(this + 0x9c) = 0;
                *(uint *)(*(int *)puVar6[1] + 0x13c) =
                     (uint)(*(int *)(*(int *)puVar6[1] + 0x13c) == 0);
              }
            }
            else if (iVar7 == 2) {
              pLVar23 = this + 0x90;
              uVar47 = *(uint *)pLVar23;
              iVar7 = *(int *)(this + 0x94);
              if ((int)(-(uint)(2999 < uVar47) - iVar7) < 0 ==
                  (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(2999 < uVar47)))) {
                *(uint *)pLVar23 = uVar47 + param_1;
                *(uint *)(this + 0x94) = iVar7 + iVar13 + (uint)CARRY4(uVar47,param_1);
              }
              fVar56 = (float)__aeabi_l2f();
              uVar47 = *(uint *)(this + 0x98);
              *(uint *)(this + 0x98) = uVar47 + param_1;
              *(uint *)(this + 0x9c) = *(int *)(this + 0x9c) + iVar13 + (uint)CARRY4(uVar47,param_1)
              ;
              AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),fVar56 * 0.1);
              if (((int)(uint)(*(uint *)(this + 0x98) < 0x2ee1) <= *(int *)(this + 0x9c)) &&
                 (iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8)), iVar13 == 1)) {
                *(undefined4 *)(this + 0x24) = 0;
                pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
                PlayerEgo::resetGunDelay(pPVar10);
                TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
                TargetFollowCamera::setTarget
                          (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
                PlayerEgo::setComputerControlled(this_00,false);
                PlayerEgo::setFreeze(this_00,false);
                fVar56 = (float)PlayerEgo::setVisible(this_00,true);
                PlayerEgo::setSpeed(this_00,fVar56);
                *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
                *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
                Player::setVulnerable(*(Player **)this_00,true);
                resetCamera(this,*(Level **)(this + 0x18));
                LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
                this[0x11] = (LevelScript)0x0;
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
                *(undefined4 *)(this + 0x98) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
                *(undefined4 *)(this + 0x9c) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
                PlayerFighter::setCloakingPossible(*(PlayerFighter **)puVar6[1],true);
                Player::setAlwaysEnemy(*(Player **)(*(int *)puVar6[1] + 4),true);
                PlayerFighter::setAIDisabled(*(PlayerFighter **)puVar6[1],false);
                pAVar52 = *(AEGeometry **)(this_00 + 8);
                PlayerEgo::getPosition();
                (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_b0);
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_b0);
                AbyssEngine::AEMath::operator-((AEMath *)&local_f0,(Vector *)&local_fc);
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
                local_120 = 0;
                local_11c = 0x3f800000;
                local_118 = 0;
                AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_120);
                goto LAB_0016974a;
              }
            }
            else if (iVar7 == 1) {
              pLVar23 = this + 0x90;
              iVar7 = *(uint *)pLVar23 + param_1;
              iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
              fVar56 = (float)__aeabi_l2f(iVar7,iVar13);
              fVar60 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
              fVar57 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
              *(int *)pLVar23 = iVar7;
              *(int *)(this + 0x94) = iVar13;
              TargetFollowCamera::translate
                        (*(TargetFollowCamera **)(this + 0x14),
                         fVar57 * 0.7 * (fVar56 / -34000.0 + 1.0),extraout_s1_23,fVar57 * 0.7);
              pAVar52 = *(AEGeometry **)(this + 0xcc);
              local_fc = 9000.0;
              local_f8 = 0.0;
              local_f4 = -13000.0;
              AEGeometry::getPosition();
              AbyssEngine::AEMath::operator-
                        ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
              AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
              local_b0 = 0;
              local_ac = 0x3f800000;
              local_a8 = 0;
              AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_b0);
              iVar13 = *(int *)(this + 0x94);
              if ((int)(-(uint)(29999 < *(uint *)pLVar23) - iVar13) < 0 ==
                  (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(29999 < *(uint *)pLVar23)))) {
                AEGeometry::moveForward(*(AEGeometry **)(this + 0xcc),fVar60 * 2.5);
                iVar13 = *(int *)(this + 0x94);
                if ((int)(-(uint)(25000 < *(uint *)pLVar23) - iVar13) < 0 !=
                    (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(25000 < *(uint *)pLVar23))))
                goto LAB_00162266;
              }
              else {
LAB_00162266:
                puVar5 = puVar6 + 1;
                iVar13 = KIPlayer::isVisible(*(KIPlayer **)*puVar5);
                if (iVar13 == 0) {
                  KIPlayer::setVisible(*(KIPlayer **)*puVar5,true);
                  KIPlayer::setActive(SUB41(*(undefined4 *)*puVar5,0));
                }
              }
              puVar5 = puVar6 + 1;
              pVVar48 = *(Vector **)(*(int *)*puVar5 + 8);
              AEGeometry::getPosition();
              AEGeometry::setPosition(pVVar48);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)*puVar5 + 8)
                        );
              AEGeometry::rotate(*(AEGeometry **)(this_00 + 8),fVar60 / 2000.0,extraout_s1_x00111,
                                 extraout_s2_42);
              if (((int)(uint)(*(uint *)pLVar23 < 20000) <= *(int *)(this + 0x94)) &&
                 (PlayerFighter::setExhaustVisible(*(PlayerFighter **)*puVar5,false),
                 (int)(uint)(*(uint *)pLVar23 < 34000) <= *(int *)(this + 0x94))) {
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
                *(undefined4 *)(this + 0x98) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
                *(undefined4 *)(this + 0x9c) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
                PlayerFighter::setExhaustVisible(*(PlayerFighter **)*puVar5,true);
LAB_0016c2da:
                uVar29 = 2;
                goto LAB_0016c2dc;
              }
            }
          }
          goto switchD_00161b94_caseD_1;
        }
        iVar37 = 0xc;
        iVar7 = 0xb;
        iVar50 = 10;
        if (Globals::isRunningHDonWeakDevice == '\0') {
          iVar37 = 0x17;
          iVar7 = 0x16;
          iVar50 = 0x15;
        }
        iVar18 = AEGeometry::isVisible(*(AEGeometry **)(this + 0xc0));
        if (iVar18 == 1) {
          pVVar48 = *(Vector **)(this + 0xc0);
          AEGeometry::getPosition();
          AEGeometry::setPosition(pVVar48);
          uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xc0) + 0xc));
          AbyssEngine::Transform::Update(CONCAT44(1,uVar29),bVar55);
        }
        iVar18 = AEGeometry::isVisible(*(AEGeometry **)(this + 0xc4));
        fVar56 = extraout_s2_18;
        fVar57 = extraout_s1_44;
        if (iVar18 == 1) {
          pVVar48 = *(Vector **)(this + 0xc4);
          AEGeometry::getPosition();
          AEGeometry::setPosition(pVVar48);
          uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xc4) + 0xc));
          AbyssEngine::Transform::Update(CONCAT44(1,uVar29),bVar55);
          fVar56 = extraout_s2_19;
          fVar57 = extraout_s1_45;
        }
        iVar18 = *(int *)(this + 0x1c);
        if (iVar18 == 1) {
LAB_0016402e:
          iVar18 = RadioMessage::isOver(*(RadioMessage **)puVar5[1]);
          if (iVar18 == 0) {
            iVar18 = *(int *)(this + 0x1c);
            fVar56 = extraout_s2_20;
            fVar57 = extraout_s1_46;
            goto LAB_00165c5a;
          }
          iVar13 = PlayerEgo::isInRocketControl(this_00);
          if (iVar13 != 0) {
            resetCamera(this,*(Level **)(this + 0x18));
            PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
            fVar56 = (float)PlayerEgo::killLiberator(this_00);
            TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
          }
          this[0x11] = (LevelScript)0x1;
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xcc));
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          AEGeometry::getPosition();
          fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_47,extraout_s2_21);
          Player::setVulnerable(*(Player **)this_00,false);
          PlayerEgo::setFreeze(this_00,true);
          uVar29 = 2;
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
LAB_001640e0:
          *(undefined4 *)(this + 0x1c) = uVar29;
        }
        else {
          if (iVar18 == 0) {
            pAVar52 = operator_new(0xc0);
            AEGeometry::AEGeometry(pAVar52,Globals::Canvas);
            *(AEGeometry **)(this + 0xcc) = pAVar52;
            local_98 = 0xc7ea6000;
            local_90 = 5000.0;
            AEGeometry::setPosition((Vector *)pAVar52);
            local_98 = 0;
            local_90 = 1.0;
            local_f0 = 0x3f80000000000000;
            local_e8 = 0.0;
            AEGeometry::setDirection
                      (*(AEGeometry **)(this + 0xcc),(Vector *)&local_98,(Vector *)&local_f0);
            *(undefined4 *)(this + 0x1c) = 1;
            goto LAB_0016402e;
          }
LAB_00165c5a:
          switch(iVar18) {
          case 2:
            fVar60 = (float)VectorSignedToFloat(param_1 * 3,(byte)(in_fpscr >> 0x16) & 3);
            pLVar23 = this + 0x90;
            uVar47 = *(uint *)pLVar23;
            *(uint *)pLVar23 = uVar47 + param_1;
            *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
            AEGeometry::translate(*(AEGeometry **)(this + 0xcc),fVar60,fVar57,fVar56);
            fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            TargetFollowCamera::translate
                      (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_71,extraout_s2_26);
            if ((int)(uint)(*(uint *)pLVar23 < 0x3e81) <= *(int *)(this + 0x94)) {
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x94) = 0;
              uVar47 = *puVar6;
              if (uVar47 != 0) {
                uVar46 = 0;
                do {
                  pKVar44 = *(KIPlayer **)(puVar6[1] + uVar46 * 4);
                  if (*(int *)(pKVar44 + 0x78) == 0x31 || *(int *)(pKVar44 + 0x78) == 0x2c) {
                    KIPlayer::setVisible(pKVar44,true);
                    KIPlayer::setActive(SUB41(pKVar44,0));
                    uVar47 = *puVar6;
                  }
                  uVar46 = uVar46 + 1;
                } while (uVar46 < uVar47);
              }
              pVVar48 = *(Vector **)(this + 0xcc);
              (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))(&local_98);
              AEGeometry::setPosition(pVVar48);
              (**(code **)(**(int **)(puVar6[1] + iVar50 * 4) + 0x28))((Vector *)&local_98);
              pVVar48 = (Vector *)(this + 0x28);
              AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
              local_98 = 0xc59c4000c4bb8000;
              local_90 = 2500.0;
              AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
              TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
              *(undefined4 *)(this + 0x1c) = 3;
            }
            break;
          case 3:
            iVar7 = *(uint *)(this + 0x90) + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
            fVar56 = (float)__aeabi_l2f(iVar7,iVar13);
            fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            *(int *)(this + 0x90) = iVar7;
            *(int *)(this + 0x94) = iVar13;
            uVar69 = FloatVectorMax(CONCAT44(extraout_s1_x00102,fVar56 / -15000.0 + 1.0),
                                    (ulonglong)extraout_s7 << 0x20,2,0x20);
            TargetFollowCamera::translate
                      (*(TargetFollowCamera **)(this + 0x14),fVar57 * (float)uVar69,
                       (float)((ulonglong)uVar69 >> 0x20),1.0);
            if ((int)(uint)(*(uint *)(this + 0x90) < 0x1f41) <= *(int *)(this + 0x94)) {
              *(undefined4 *)(this + 0x98) = 0;
              *(undefined4 *)(this + 0x9c) = 0;
              *(undefined4 *)(this + 0x1c) = 4;
            }
            break;
          case 4:
            pLVar23 = this + 0x98;
            uVar47 = *(uint *)pLVar23;
            iVar37 = *(int *)(this + 0x9c);
            iVar7 = -(uint)(6999 < uVar47) - iVar37;
            if (iVar7 < 0 == (SBORROW4(0,iVar37) != SBORROW4(-iVar37,(uint)(6999 < uVar47)))) {
              *(uint *)pLVar23 = uVar47 + param_1;
              *(uint *)(this + 0x9c) = iVar37 + iVar13 + (uint)CARRY4(uVar47,param_1);
              iVar7 = param_1;
            }
            pLVar1 = this + 0x90;
            iVar37 = *(uint *)pLVar1 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar1,param_1);
            fVar56 = (float)__aeabi_l2f(iVar37,iVar13,iVar7,6999 - uVar47);
            fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            *(int *)pLVar1 = iVar37;
            *(int *)(this + 0x94) = iVar13;
            uVar69 = FloatVectorMax(CONCAT44(extraout_s1_x00103,fVar56 / -15000.0 + 1.0),
                                    (ulonglong)extraout_s7_00 << 0x20,2,0x20);
            TargetFollowCamera::translate
                      (*(TargetFollowCamera **)(this + 0x14),fVar57 * (float)uVar69,
                       (float)((ulonglong)uVar69 >> 0x20),1.0);
            uVar47 = *puVar6;
            if (uVar47 != 0) {
              uVar46 = 0;
              do {
                iVar7 = *(int *)(puVar6[1] + uVar46 * 4);
                iVar13 = *(int *)(iVar7 + 0x78);
                if (iVar13 == 0x31 || iVar13 == 0x2c) {
                  fVar56 = (float)__aeabi_l2f(*(undefined4 *)pLVar23,*(undefined4 *)(this + 0x9c));
                  AEGeometry::moveForward(*(AEGeometry **)(iVar7 + 8),fVar56 * 0.02);
                  uVar47 = *puVar6;
                }
                uVar46 = uVar46 + 1;
              } while (uVar46 < uVar47);
            }
            iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0xc));
            if ((iVar13 != 0) && ((int)(uint)(*(uint *)pLVar1 < 0x4651) <= *(int *)(this + 0x94))) {
              pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
              PlayerEgo::resetGunDelay(pPVar10);
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
              PlayerEgo::setComputerControlled(this_00,false);
              PlayerEgo::setFreeze(this_00,false);
              PlayerEgo::setVisible(this_00,true);
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
              Player::setVulnerable(*(Player **)this_00,true);
              resetCamera(this,*(Level **)(this + 0x18));
              LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
              this[0x11] = (LevelScript)0x0;
              if (*puVar6 != 0) {
                uVar47 = 0;
                do {
                  pKVar44 = *(KIPlayer **)(puVar6[1] + uVar47 * 4);
                  if (*(int *)(pKVar44 + 0x78) == 0x31 || *(int *)(pKVar44 + 0x78) == 0x2c) {
                    KIPlayer::setVisible(pKVar44,true);
                    KIPlayer::setActive(SUB41(pKVar44,0));
                    PlayerFighter::setAIDisabled((PlayerFighter *)pKVar44,false);
                    if (*(int *)(pKVar44 + 0x78) == 0x2c) {
                      PlayerFighter::setCloakingPossible((PlayerFighter *)pKVar44,true);
                      pcVar51 = *(code **)(*(int *)pKVar44 + 0x20);
                      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,12000);
                      uVar58 = VectorSignedToFloat(iVar13 + -6000,(byte)(in_fpscr >> 0x16) & 3);
                      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,30000);
                      iVar13 = iVar13 + -87000;
                      uVar29 = 0x47ea6000;
                    }
                    else {
                      pcVar51 = *(code **)(*(int *)pKVar44 + 0x20);
                      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,6000);
                      uVar58 = VectorSignedToFloat(iVar13 + -3000,(byte)(in_fpscr >> 0x16) & 3);
                      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,6000);
                      iVar13 = iVar13 + -7000;
                      uVar29 = 0x469c4000;
                    }
                    local_90 = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x16) & 3);
                    local_98 = CONCAT44(uVar58,uVar29);
                    (*pcVar51)(pKVar44,&local_98);
                  }
                  uVar47 = uVar47 + 1;
                } while (uVar47 < *puVar6);
              }
              iVar13 = 5;
              goto LAB_0016d238;
            }
            break;
          case 5:
            if (Globals::isRunningHDonWeakDevice == '\0') {
              iVar18 = 0;
              iVar19 = 0xb;
              do {
                iVar20 = KIPlayer::isDead(*(KIPlayer **)(puVar6[1] + iVar19 * 4));
                iVar19 = iVar19 + 1;
                if (iVar20 != 0) {
                  iVar18 = iVar18 + 1;
                }
              } while (iVar19 != 0x16);
            }
            else {
              iVar18 = 5;
              iVar19 = 6;
              do {
                iVar20 = KIPlayer::isDead(*(KIPlayer **)(puVar6[1] + iVar19 * 4));
                iVar19 = iVar19 + 1;
                if (iVar20 != 0) {
                  iVar18 = iVar18 + 1;
                }
              } while (iVar19 != 0xc);
            }
            pLVar23 = this + 0x98;
            uVar47 = *(uint *)pLVar23 + param_1;
            iVar13 = *(int *)(this + 0x9c) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
            *(uint *)pLVar23 = uVar47;
            *(int *)(this + 0x9c) = iVar13;
            if ((int)(uint)(uVar47 < 0x61a9) <= iVar13) {
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x9c) = 0;
              iVar13 = *(int *)(puVar6[1] + iVar50 * 4);
              *(uint *)(iVar13 + 0x13c) = (uint)(*(int *)(iVar13 + 0x13c) == 0);
            }
            if ((iVar18 < 9) ||
               (iVar13 = *(int *)(this + 0xc),
               (int)(-(uint)("ppEPFvPS0_E" < *(char **)(this + 8)) - iVar13) < 0 ==
               (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)("ppEPFvPS0_E" < *(char **)(this + 8)))
               ))) {
              iVar13 = Player::getHitpoints(*(Player **)(*(int *)(puVar6[1] + iVar50 * 4) + 4));
              iVar18 = Player::getMaxHitpoints(*(Player **)(*(int *)(puVar6[1] + iVar50 * 4) + 4));
              if ((int)(iVar18 + ((uint)(iVar18 >> 0x1f) >> 0x1e)) >> 2 <= iVar13) break;
            }
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            Player::setVulnerable(*(Player **)this_00,false);
            PlayerEgo::setFreeze(this_00,true);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            pKVar44 = *(KIPlayer **)(puVar6[1] + iVar7 * 4);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(pKVar44 + 8));
            (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_98);
            pVVar48 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            local_98 = 0x44fa0000472fc800;
            local_90 = 11000.0;
            AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
            pcVar51 = *(code **)(*(int *)pKVar44 + 0x44);
            local_f0 = 0xc3480000466a6000;
            local_e8 = 1000.0;
            AbyssEngine::AEMath::operator+((AEMath *)&local_98,pVVar48,(Vector *)&local_f0);
            (*pcVar51)(pKVar44,(AEMath *)&local_98);
            pAVar52 = *(AEGeometry **)(pKVar44 + 8);
            (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_fc);
            (**(code **)(*(int *)pKVar44 + 0x28))((Vector *)&local_a4,pKVar44);
            AbyssEngine::AEMath::operator-
                      ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
            AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
            local_b0 = 0;
            local_ac = 0x3f800000;
            local_a8 = 0;
            AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_b0);
            KIPlayer::setVisible(pKVar44,true);
            KIPlayer::setActive(SUB41(pKVar44,0));
            Player::setVulnerable(*(Player **)(*(int *)(puVar6[1] + iVar50 * 4) + 4),false);
            *(undefined4 *)(*(int *)(puVar6[1] + iVar50 * 4) + 0x13c) = 0;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            uVar29 = 6;
            goto LAB_001640e0;
          case 6:
            pLVar23 = this + 0x90;
            uVar47 = *(uint *)pLVar23;
            *(uint *)pLVar23 = uVar47 + param_1;
            *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
            pKVar44 = *(KIPlayer **)(puVar6[1] + iVar7 * 4);
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            (**(code **)(*(int *)pKVar44 + 0x28))(local_208,pKVar44);
            (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))(local_214);
            uVar47 = in_fpscr & 0xfffffff | (uint)(local_208[0] < local_214[0]) << 0x1f |
                     (uint)(local_208[0] == local_214[0]) << 0x1e;
            bVar2 = (byte)(uVar47 >> 0x18);
            if (!(bool)(bVar2 >> 6 & 1) &&
                (bool)(bVar2 >> 7) == (NAN(local_208[0]) || NAN(local_214[0]))) {
              fVar56 = (float)VectorSignedToFloat(param_1 * 3,(byte)(uVar47 >> 0x16) & 3);
              AEGeometry::moveForward(*(AEGeometry **)(pKVar44 + 8),fVar56);
            }
            iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x28));
            if (iVar13 == 1) {
              KIPlayer::setVisible(pKVar44,false);
              KIPlayer::setActive(SUB41(pKVar44,0));
              (**(code **)(*(int *)pKVar44 + 0x48))(pKVar44,0x47435000,0x47435000,0x47435000);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),
                         *(AEGeometry **)(*(int *)(puVar6[1] + iVar37 * 4) + 0x13c));
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x94) = 0;
              *(undefined4 *)(this + 0x1c) = 7;
            }
            break;
          case 7:
            iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x28));
            if (iVar7 != 1) {
              iVar18 = *(int *)(this + 0x1c);
              fVar56 = extraout_s2_40;
              fVar57 = extraout_s1_x00104;
              goto switchD_00165c62_default;
            }
            piVar28 = *(int **)(puVar6[1] + iVar37 * 4);
            local_98 = 0;
            local_90 = 0.0;
            (**(code **)(*piVar28 + 0x28))((Vector *)&local_f0,piVar28);
            FModSound::updateEvent3DAttributes
                      (Globals::sound,0x8cb,(Vector *)&local_f0,(Vector *)&local_98,false);
            pLVar23 = this + 0x90;
            uVar47 = *(uint *)pLVar23;
            iVar7 = *(int *)(this + 0x94);
            if ((int)(-(uint)(9999 < uVar47) - iVar7) < 0 ==
                (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(9999 < uVar47)))) {
              *(uint *)pLVar23 = uVar47 + param_1;
              *(uint *)(this + 0x94) = iVar7 + iVar13 + (uint)CARRY4(uVar47,param_1);
            }
            fVar56 = (float)__aeabi_l2f();
            fVar57 = (float)VectorSignedToFloat(param_1 * -10,(byte)(in_fpscr >> 0x16) & 3);
            AEGeometry::moveForward((AEGeometry *)piVar28[0x4f],fVar57 * (fVar56 / 10000.0));
            AEGeometry::getPosition();
            if (100000.0 < local_218) {
              pPVar22 = *(PlayerFighter **)(puVar6[1] + iVar50 * 4);
              pcVar51 = *(code **)(*(int *)pPVar22 + 0x44);
              pVVar48 = (Vector *)
                        TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
              local_a4 = 0x457a0000;
              local_a0 = -0x3bea0000;
              local_9c = -0x3b060000;
              AbyssEngine::AEMath::operator+((AEMath *)&local_fc,pVVar48,(Vector *)&local_a4);
              (*pcVar51)(pPVar22,(AEMath *)&local_fc);
              (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_120);
              local_12c = 0;
              local_128 = 0;
              local_124 = 0x471c4000;
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_b0,(Vector *)&local_120,(Vector *)&local_12c);
              (**(code **)(*(int *)pPVar22 + 0x28))(aVStack_1a8,pPVar22);
              AbyssEngine::AEMath::operator-((AEMath *)&local_a4,(Vector *)&local_b0,aVStack_1a8);
              AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_fc,(Vector *)&local_a4);
              pVVar48 = (Vector *)(this + 0x28);
              AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_fc);
              local_fc = 0.0;
              local_f8 = 1.0;
              local_f4 = 0.0;
              AEGeometry::setDirection(*(AEGeometry **)(pPVar22 + 8),pVVar48,(Vector *)&local_fc);
              PlayerFighter::setAIDisabled(pPVar22,true);
              KIPlayer::setVisible((KIPlayer *)pPVar22,true);
              KIPlayer::setActive(SUB41(pPVar22,0));
              PlayerEgo::setComputerControlled(this_00,true);
              local_fc = 0.0;
              local_f8 = 1.0;
              local_f4 = 0.0;
              fVar56 = (float)AEGeometry::setDirection
                                        (*(AEGeometry **)(this_00 + 8),pVVar48,(Vector *)&local_fc);
              PlayerEgo::setSpeed(this_00,fVar56);
              PlayerEgo::setFreeze(this_00,false);
              pVVar48 = (Vector *)
                        TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
              local_fc = 5000.0;
              local_f8 = 300.0;
              local_f4 = -14000.0;
              AbyssEngine::AEMath::operator+((AEMath *)&local_22c,pVVar48,(Vector *)&local_fc);
              PlayerEgo::setPosition(this_00,local_22c,uStack_228,uStack_224);
              LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),(AEGeometry *)piVar28[0x4f]);
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x94) = 0;
              *(undefined4 *)(this + 0x1c) = 8;
            }
            break;
          default:
switchD_00165c62_default:
            switch(iVar18) {
            case 8:
              local_98 = 0;
              local_90 = 0.0;
              (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_f0);
              FModSound::updateEvent3DAttributes
                        (Globals::sound,0x8cb,(Vector *)&local_f0,(Vector *)&local_98,false);
              fVar56 = (float)VectorSignedToFloat(param_1 * -10,(byte)(in_fpscr >> 0x16) & 3);
              AEGeometry::moveForward
                        (*(AEGeometry **)(*(int *)(puVar6[1] + iVar37 * 4) + 0x13c),fVar56);
              fVar56 = (float)VectorSignedToFloat(param_1 << 2,(byte)(in_fpscr >> 0x16) & 3);
              pKVar44 = *(KIPlayer **)(puVar6[1] + iVar50 * 4);
              AEGeometry::moveForward(*(AEGeometry **)(pKVar44 + 8),fVar56);
              Player::shoot(*(int *)(pKVar44 + 4),(longlong)param_1,false);
              pLVar23 = this + 0x90;
              uVar47 = *(uint *)pLVar23 + param_1;
              iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
              *(uint *)pLVar23 = uVar47;
              *(int *)(this + 0x94) = iVar13;
              if (((int)(uint)(uVar47 < 0x2ee1) <= iVar13) &&
                 (iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x30)), iVar13 == 1))
              {
                (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_fc);
                AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_fc);
                pTVar38 = *(TargetFollowCamera **)(this + 0x14);
                local_a4 = 0x4708b800;
                local_a0 = 0;
                local_9c = 0x4788b800;
                AbyssEngine::AEMath::operator+
                          ((AEMath *)&local_fc,(Vector *)(this + 0x28),(Vector *)&local_a4);
                TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_fc);
                LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
                local_fc = 0.0;
                local_f8 = 0.0;
                local_f4 = 1.0;
                local_a4 = 0;
                local_a0 = 0x3f800000;
                local_9c = 0;
                AEGeometry::setDirection
                          (*(AEGeometry **)(pKVar44 + 8),(Vector *)&local_fc,(Vector *)&local_a4);
                local_fc = 0.0;
                local_f8 = 0.0;
                local_f4 = 1.0;
                local_a4 = 0;
                local_a0 = 0x3f800000;
                local_9c = 0;
                AEGeometry::setDirection
                          (*(AEGeometry **)(this_00 + 8),(Vector *)&local_fc,(Vector *)&local_a4);
                KIPlayer::setVisible(pKVar44,false);
                fVar56 = (float)KIPlayer::setActive(SUB41(pKVar44,0));
                PlayerEgo::setSpeed(this_00,fVar56);
                uVar29 = 9;
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
                *(undefined4 *)(this + 0x98) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
                *(undefined4 *)(this + 0x9c) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
                goto LAB_0016c2dc;
              }
              break;
            case 9:
              local_98 = 0;
              local_90 = 0.0;
              (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_f0);
              FModSound::updateEvent3DAttributes
                        (Globals::sound,0x8cb,(Vector *)&local_f0,(Vector *)&local_98,false);
              fVar56 = (float)VectorSignedToFloat(param_1 * -10,(byte)(in_fpscr >> 0x16) & 3);
              pKVar44 = *(KIPlayer **)(puVar6[1] + iVar50 * 4);
              AEGeometry::moveForward
                        (*(AEGeometry **)(*(int *)(puVar6[1] + iVar37 * 4) + 0x13c),fVar56);
              fVar56 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
              AEGeometry::moveForward(*(AEGeometry **)(pKVar44 + 8),fVar56);
              Player::shoot(*(int *)(pKVar44 + 4),(longlong)param_1,false);
              pLVar23 = this + 0x90;
              auVar67._8_8_ = in_q8._8_8_ & 0xffff0000ffff0000 | (ulonglong)(uint)param_1 & 0xffff;
              auVar67._0_8_ = in_q8._0_8_ & 0xffff0000ffff0000 | (ulonglong)(uint)param_1 & 0xffff;
              auVar66 = VectorAdd(*(undefined1 (*) [16])pLVar23,auVar67,8);
              uVar47 = auVar66._8_4_;
              iVar7 = auVar66._12_4_;
              *(longlong *)pLVar23 = auVar66._0_8_;
              *(longlong *)(this + 0x98) = auVar66._8_8_;
              if (((int)(-(uint)(8999 < uVar47) - iVar7) < 0 ==
                   (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(8999 < uVar47)))) &&
                 ((int)(uint)(uVar47 + param_1 < 9000) <=
                  (int)(iVar7 + iVar13 + (uint)CARRY4(uVar47,param_1)))) {
                pcVar51 = *(code **)(*(int *)pKVar44 + 0x44);
                pVVar48 = (Vector *)
                          TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
                local_a4 = 0x457a0000;
                local_a0 = -0x3bea0000;
                local_9c = -0x3b060000;
                AbyssEngine::AEMath::operator+((AEMath *)&local_fc,pVVar48,(Vector *)&local_a4);
                (*pcVar51)(pKVar44,(AEMath *)&local_fc);
                KIPlayer::setVisible(pKVar44,true);
                KIPlayer::setActive(SUB41(pKVar44,0));
              }
              (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_b0);
              (**(code **)(*(int *)pKVar44 + 0x28))((Vector *)&local_120,pKVar44);
              AbyssEngine::AEMath::operator-
                        ((AEMath *)&local_a4,(Vector *)&local_b0,(Vector *)&local_120);
              AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_fc,(Vector *)&local_a4);
              pVVar48 = (Vector *)(this + 0x28);
              AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_fc);
              local_fc = 0.0;
              local_f8 = 1.0;
              local_f4 = 0.0;
              AEGeometry::setDirection(*(AEGeometry **)(pKVar44 + 8),pVVar48,(Vector *)&local_fc);
              iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x34));
              bVar55 = iVar7 == 1;
              if (bVar55) {
                iVar7 = *(int *)(this + 200);
              }
              if (bVar55 && iVar7 == 0) {
                pEVar42 = operator_new(0x68);
                Explosion::Explosion(pEVar42,0);
                *(Explosion **)(this + 200) = pEVar42;
                fVar56 = (float)Explosion::addFireStreaks(pEVar42);
                Explosion::setScaling(fVar56);
                pEVar42 = *(Explosion **)(this + 200);
                (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_a4);
                local_b0 = -0x3b060000;
                local_ac = 0x447a0000;
                local_a8 = -0x3a060000;
                AbyssEngine::AEMath::operator+
                          ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_b0);
                local_120 = 0;
                local_11c = 0;
                local_118 = 0;
                fVar56 = (float)Explosion::start(pEVar42,(Vector *)&local_fc,(Vector *)&local_120);
                FModSound::play(Globals::sound,0x8c4,(Vector *)0x0,(Vector *)0x0,fVar56);
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) = 0;
                *(undefined4 *)(this + 0xa0) = 300;
                *(undefined4 *)(this + 0xa4) = 0;
              }
              pLVar1 = this + 0xa0;
              uVar47 = *(uint *)pLVar1;
              if ((int)(uint)(uVar47 == 0) <= *(int *)(this + 0xa4)) {
                iVar7 = uVar47 - param_1;
                iVar50 = (*(int *)(this + 0xa4) - iVar13) - (uint)(uVar47 < (uint)param_1);
                *(int *)pLVar1 = iVar7;
                *(int *)(this + 0xa4) = iVar50;
                if ((int)(-(uint)(iVar7 != 0) - iVar50) < 0 ==
                    (SBORROW4(0,iVar50) != SBORROW4(-iVar50,(uint)(iVar7 != 0)))) {
                  *(undefined4 *)pLVar1 = 0;
                  *(undefined4 *)(this + 0xa4) = 0;
                  pVVar49 = *(Vector **)(this + 0xc0);
                  AEGeometry::getPosition();
                  AEGeometry::setPosition(pVVar49);
                  local_fc = 0.0;
                  local_f8 = 0.0;
                  local_f4 = -1.0;
                  local_a4 = 0;
                  local_a0 = 0x3f800000;
                  local_9c = 0;
                  AEGeometry::setDirection
                            (*(AEGeometry **)(this + 0xc0),(Vector *)&local_fc,(Vector *)&local_a4);
                  AEGeometry::setVisible(*(AEGeometry **)(this + 0xc0),true);
                  uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                                     (Globals::Canvas,*(uint *)(*(int *)(this + 0xc0) + 0xc));
                  AbyssEngine::Transform::SetAnimationState(uVar29,2,0);
                }
              }
              if (*(Explosion **)(this + 200) != (Explosion *)0x0) {
                fVar56 = (float)Explosion::update(*(Explosion **)(this + 200),param_1,
                                                  (TargetFollowCamera *)0x0);
                uVar47 = *(uint *)pLVar23 + param_1;
                iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
                *(uint *)pLVar23 = uVar47;
                *(int *)(this + 0x94) = iVar13;
                if ((int)(uint)(uVar47 < 0x1771) <= iVar13) {
                  *(undefined4 *)pLVar23 = 0xfffff830;
                  *(undefined4 *)(this + 0x94) = 0xffffffff;
                  FModSound::play(Globals::sound,0x8c4,(Vector *)0x0,(Vector *)0x0,fVar56);
                  pEVar42 = *(Explosion **)(this + 200);
                  (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_a4);
                  local_b0 = -0x3a448000;
                  local_ac = 0x44fa0000;
                  local_a8 = -0x39e3c000;
                  AbyssEngine::AEMath::operator+
                            ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_b0);
                  local_120 = 0;
                  local_11c = 0;
                  local_118 = 0;
                  Explosion::start(pEVar42,(Vector *)&local_fc,(Vector *)&local_120);
                }
              }
              iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x38));
              if (iVar13 == 1) {
                (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_fc);
                AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_fc);
                pTVar38 = *(TargetFollowCamera **)(this + 0x14);
                local_a4 = 0x47435000;
                local_a0 = 0;
                local_9c = 0x4788b800;
                AbyssEngine::AEMath::operator+((AEMath *)&local_fc,pVVar48,(Vector *)&local_a4);
                TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_fc);
                *(undefined4 *)pLVar23 = 0;
                *(undefined4 *)(this + 0x94) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
                *(undefined4 *)(this + 0x98) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
                *(undefined4 *)(this + 0x9c) =
                     *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
                KIPlayer::setVisible(pKVar44,false);
                PlayerEgo::setVisible(this_00,false);
                pVVar48 = *(Vector **)(this + 0xc4);
                AEGeometry::getPosition();
                AEGeometry::setPosition(pVVar48);
                local_fc = 0.0;
                local_f8 = 0.0;
                local_f4 = -1.0;
                local_a4 = 0;
                local_a0 = 0x3f800000;
                local_9c = 0;
                AEGeometry::setDirection
                          (*(AEGeometry **)(this + 0xc4),(Vector *)&local_fc,(Vector *)&local_a4);
                AEGeometry::setVisible(*(AEGeometry **)(this + 0xc4),true);
                AEGeometry::setVisible(*(AEGeometry **)(this + 0xc0),false);
                uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 0xc4) + 0xc));
                AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
                *(undefined4 *)(this + 0x1c) = 10;
              }
              break;
            case 10:
              local_98 = 0;
              local_90 = 0.0;
              (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_f0);
              fVar56 = (float)FModSound::updateEvent3DAttributes
                                        (Globals::sound,0x8cb,(Vector *)&local_f0,
                                         (Vector *)&local_98,false);
              uVar47 = *(uint *)(this + 0x98);
              *(uint *)(this + 0x98) = uVar47 + param_1;
              *(uint *)(this + 0x9c) = *(int *)(this + 0x9c) + iVar13 + (uint)CARRY4(uVar47,param_1)
              ;
              fVar56 = (float)TargetFollowCamera::setRumblePercentage
                                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
              uVar47 = *(uint *)(this + 0x98);
              if ((-(*(int *)(this + 0x9c) + -1 + (uint)(2000 < uVar47)) <
                   (uint)(uVar47 - 0x7d1 < 6999)) &&
                 ((int)(uint)(uVar47 + param_1 < 9000) <=
                  (int)(*(int *)(this + 0x9c) + iVar13 + (uint)CARRY4(uVar47,param_1)))) {
                Explosion::setScaling(fVar56);
                pEVar42 = *(Explosion **)(this + 200);
                (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_a4);
                Level::getStarSystem(*(Level **)(this + 0x18));
                fVar56 = (float)StarSystem::getLightDirection();
                AbyssEngine::AEMath::operator*((AEMath *)&local_b0,(Vector *)&local_120,fVar56);
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_b0);
                local_12c = 0;
                local_128 = 0;
                local_124 = 0;
                fVar56 = (float)Explosion::start(pEVar42,(Vector *)&local_fc,(Vector *)&local_12c);
                fVar56 = (float)FModSound::play(Globals::sound,0x8c3,(Vector *)0x0,(Vector *)0x0,
                                                fVar56);
                TargetFollowCamera::setRumblePercentage
                          (*(TargetFollowCamera **)(this + 0x14),fVar56,0x42c80000);
              }
              Explosion::update(*(Explosion **)(this + 200),param_1,(TargetFollowCamera *)0x0);
              fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
              VectorSignedToFloat(param_1 * -2,(byte)(in_fpscr >> 0x16) & 3);
              TargetFollowCamera::translate
                        (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.33,extraout_s1_x00124,0.33
                        );
              iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x3c));
              if (iVar7 == 1) {
                pLVar23 = this + 0x90;
                uVar47 = *(uint *)pLVar23 + param_1;
                iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
                *(uint *)pLVar23 = uVar47;
                *(int *)(this + 0x94) = iVar13;
                if ((int)(uint)(uVar47 < 0xbb9) <= iVar13) {
                  pVVar48 = *(Vector **)(this + 0xbc);
                  AEGeometry::getPosition();
                  AEGeometry::setPosition(pVVar48);
                  local_fc = 0.0;
                  local_f8 = 0.0;
                  local_f4 = -1.0;
                  local_a4 = 0;
                  local_a0 = 0x3f800000;
                  local_9c = 0;
                  AEGeometry::setDirection
                            (*(AEGeometry **)(this + 0xbc),(Vector *)&local_fc,(Vector *)&local_a4);
                  pTVar35 = (Transform *)
                            AbyssEngine::PaintCanvas::TransformGetTransform
                                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
                  AbyssEngine::Transform::SetVisible(pTVar35,false);
                  uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                                     (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
                  AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
                  *(undefined4 *)pLVar23 = 0;
                  *(undefined4 *)(this + 0x94) = 0;
                  goto LAB_00169a0c;
                }
              }
              break;
            case 0xb:
              fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
              VectorSignedToFloat(param_1 * -3,(byte)(in_fpscr >> 0x16) & 3);
              pLVar23 = this + 0x90;
              uVar47 = *(uint *)pLVar23;
              *(uint *)pLVar23 = uVar47 + param_1;
              *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1)
              ;
              fVar56 = (float)TargetFollowCamera::translate
                                        (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.33,fVar57,
                                         0.33);
              uVar47 = *(uint *)pLVar23;
              if ((int)(uint)(uVar47 < 0x1771) <= *(int *)(this + 0x94)) {
                iVar13 = (*(int *)(this + 0x94) - iVar13) - (uint)(uVar47 < (uint)param_1);
                bVar54 = 6000 < uVar47 - param_1;
                if ((int)(-(uint)bVar54 - iVar13) < 0 ==
                    (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)bVar54))) {
                  FModSound::play(Globals::sound,0x8c7,(Vector *)0x0,(Vector *)0x0,fVar56);
                }
                pTVar35 = (Transform *)
                          AbyssEngine::PaintCanvas::TransformGetTransform
                                    (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
                AbyssEngine::Transform::SetVisible(pTVar35,true);
                lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
                AbyssEngine::Transform::Update(lVar68,bVar55);
                if ((int)(uint)(*(uint *)pLVar23 < 0x2711) <= *(int *)(this + 0x94)) {
                  pVVar48 = *(Vector **)(this + 0xcc);
                  (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))(&local_98);
                  AEGeometry::setPosition(pVVar48);
                  pAVar52 = *(AEGeometry **)(this + 0xcc);
                  Level::getStarSystem(*(Level **)(this + 0x18));
                  StarSystem::getLightDirection();
                  local_f0 = 0x3f80000000000000;
                  local_e8 = 0.0;
                  AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
                  TargetFollowCamera::setTarget
                            (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xcc));
                  *(undefined4 *)pLVar23 = 0;
                  *(undefined4 *)(this + 0x94) = 0;
                  KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar50 * 4),false);
                  KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + iVar50 * 4),0));
                  *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
                }
              }
              break;
            case 0xc:
              pLVar23 = this + 0x90;
              uVar47 = *(uint *)pLVar23 + param_1;
              iVar7 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
              *(uint *)pLVar23 = uVar47;
              *(int *)(this + 0x94) = iVar7;
              if ((int)(-(uint)(2999 < uVar47) - iVar7) < 0 ==
                  (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(2999 < uVar47)))) {
                fVar60 = (float)VectorSignedToFloat(param_1 * -0x14,(byte)(in_fpscr >> 0x16) & 3);
                pTVar38 = *(TargetFollowCamera **)(this + 0x14);
LAB_0016f008:
                TargetFollowCamera::translate(pTVar38,fVar60,fVar57,fVar56);
              }
              else if ((int)(-(uint)(6999 < uVar47) - iVar7) < 0 ==
                       (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(6999 < uVar47)))) {
                fVar60 = (float)VectorSignedToFloat(param_1 * -3,(byte)(in_fpscr >> 0x16) & 3);
                fVar56 = (float)VectorSignedToFloat(param_1 * -10,(byte)(in_fpscr >> 0x16) & 3);
                pTVar38 = *(TargetFollowCamera **)(this + 0x14);
                goto LAB_0016f008;
              }
              uVar47 = *(uint *)pLVar23;
              iVar7 = *(int *)(this + 0x94);
              if ((int)(-(uint)(4999 < uVar47) - iVar7) < 0 ==
                  (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(4999 < uVar47)))) {
                fVar56 = (float)VectorSignedToFloat(param_1 * 0x23,(byte)(in_fpscr >> 0x16) & 3);
                AEGeometry::moveForward(*(AEGeometry **)(this + 0xcc),fVar56);
                uVar47 = *(uint *)pLVar23;
                iVar7 = *(int *)(this + 0x94);
              }
              if ((int)(-(uint)(5999 < uVar47) - iVar7) < 0 ==
                  (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(5999 < uVar47)))) {
                uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
                AbyssEngine::Transform::Update(CONCAT44(1,uVar29),bVar55);
                uVar47 = *(uint *)pLVar23;
                iVar7 = *(int *)(this + 0x94);
              }
              fVar56 = (float)__aeabi_l2f(uVar47,iVar7);
              fVar56 = (float)TargetFollowCamera::setRumblePercentage
                                        (*(TargetFollowCamera **)(this + 0x14),
                                         (float)(int)((fVar56 / 6500.0) * 30.0),0x42c80000);
              uVar47 = *(uint *)pLVar23;
              iVar7 = *(int *)(this + 0x94);
              iVar50 = (iVar7 - iVar13) - (uint)(uVar47 < (uint)param_1);
              if (((int)(uint)(uVar47 < 5000) <= iVar7) &&
                 (bVar55 = 4999 < uVar47 - param_1,
                 (int)(-(uint)bVar55 - iVar50) < 0 ==
                 (SBORROW4(0,iVar50) != SBORROW4(-iVar50,(uint)bVar55)))) {
                fVar56 = (float)Level::switchSkyboxForSupernovaReversal(*(Level **)(this + 0x18));
                uVar47 = *(uint *)pLVar23;
                iVar7 = *(int *)(this + 0x94);
              }
              iVar50 = (iVar7 - iVar13) - (uint)(uVar47 < (uint)param_1);
              if (((int)(uint)(uVar47 < 0x157c) <= iVar7) &&
                 (bVar55 = 0x157b < uVar47 - param_1,
                 (int)(-(uint)bVar55 - iVar50) < 0 ==
                 (SBORROW4(0,iVar50) != SBORROW4(-iVar50,(uint)bVar55)))) {
                Explosion::setScaling(fVar56);
                pEVar42 = *(Explosion **)(this + 200);
                (**(code **)(**(int **)(puVar6[1] + iVar37 * 4) + 0x28))((Vector *)&local_fc);
                local_a4 = 0;
                local_a0 = 0;
                local_9c = -0x39c48000;
                AbyssEngine::AEMath::operator+
                          ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
                Level::getStarSystem(*(Level **)(this + 0x18));
                fVar56 = (float)StarSystem::getLightDirection();
                AbyssEngine::AEMath::operator*((AEMath *)&local_b0,(Vector *)&local_120,fVar56);
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_b0);
                local_12c = 0;
                local_128 = 0;
                local_124 = 0;
                Explosion::start(pEVar42,(Vector *)&local_98,(Vector *)&local_12c);
                uVar47 = *(uint *)pLVar23;
                iVar7 = *(int *)(this + 0x94);
              }
              iVar13 = (iVar7 - iVar13) - (uint)(uVar47 < (uint)param_1);
              if (((int)(uint)(uVar47 < 0x1644) <= iVar7) &&
                 (bVar55 = 0x1643 < uVar47 - param_1,
                 (int)(-(uint)bVar55 - iVar13) < 0 ==
                 (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)bVar55)))) {
                AEGeometry::setVisible(*(AEGeometry **)(this + 0xbc),false);
                KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar37 * 4),false);
                fVar56 = (float)Layout::startFade(Globals::layout,true,-1,0x19c8 - *(int *)pLVar23);
                FModSound::play(Globals::sound,0x8c8,(Vector *)0x0,(Vector *)0x0,fVar56);
                uVar47 = *(uint *)pLVar23;
                iVar7 = *(int *)(this + 0x94);
              }
              if ((int)(uint)(uVar47 < 0x157c) <= iVar7) {
                Explosion::update(*(Explosion **)(this + 200),param_1,(TargetFollowCamera *)0x0);
                uVar47 = *(uint *)pLVar23;
                iVar7 = *(int *)(this + 0x94);
              }
              if (-(iVar7 - (uint)(uVar47 < 0x1389)) < (uint)(uVar47 - 0x1389 < 999)) {
                pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
                iVar13 = StarSystem::getPlanets(pSVar31);
                iVar7 = *(int *)(this + 0x94);
                pVVar48 = (Vector *)**(undefined4 **)(iVar13 + 4);
                if ((int)(-(uint)(0x157b < *(uint *)pLVar23) - iVar7) < 0 ==
                    (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(0x157b < *(uint *)pLVar23)))) {
                  fVar56 = (float)AEGeometry::getScaling();
                }
                else {
                  fVar56 = (float)AEGeometry::getScaling();
                }
                AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
                AEGeometry::setScaling(pVVar48);
                uVar47 = *(uint *)pLVar23;
                iVar7 = *(int *)(this + 0x94);
              }
              if ((int)(uint)(uVar47 < 0x1964) <= iVar7) {
                *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
                Status::nextCampaignMission(SUB41(Globals::status,0));
                pSVar33 = Globals::status;
                pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,0x6f);
                Status::setStation(pSVar33,pSVar32);
                pSVar33 = Globals::status;
                pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,0x6f);
                Status::departStation(pSVar33,pSVar32);
                uVar29 = Player::getHitpoints(*(Player **)this_00);
                *(undefined4 *)(Globals::status + 100) = uVar29;
                uVar29 = Player::getShieldHP(*(Player **)this_00);
                *(undefined4 *)(Globals::status + 0x5c) = uVar29;
                uVar29 = Player::getArmorHP(*(Player **)this_00);
                *(undefined4 *)(Globals::status + 0x60) = uVar29;
                uVar29 = Player::getGammaHP(*(Player **)this_00);
                *(undefined4 *)(Globals::status + 0x68) = uVar29;
                uVar29 = PlayerEgo::getCurrentSecondaryWeaponIndex(this_00);
                *(undefined4 *)(Globals::status + 0xf4) = uVar29;
                Player::setGammaHP(*(Player **)this_00,100);
                Level::initStreamOutPosition = 1;
                Globals::switch_to_target_setting = 1;
                goto LAB_001667b4;
              }
            }
          }
        }
      }
      goto switchD_00161b94_caseD_1;
    }
    if (iVar7 < 0x69) {
      if (iVar7 == 0x5c) {
        iVar7 = *(int *)(this + 0x1c);
        if (iVar7 == 0) {
          iVar37 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 8));
          iVar7 = *(int *)(this + 0x1c);
          if (iVar37 == 1) {
            iVar7 = iVar7 + 1;
            *(int *)(this + 0x1c) = iVar7;
          }
        }
        switch(iVar7) {
        case 1:
          if (*(int *)(Globals::status + 0x174) == 0) {
            pMVar12 = (Mission *)Status::getCampaignMission(Globals::status);
            Mission::setType(pMVar12,4);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            piVar28 = *(int **)puVar6[1];
            pcVar51 = *(code **)(*piVar28 + 0x44);
            (**(code **)(*(int *)((undefined4 *)puVar6[1])[3] + 0x28))((Vector *)&local_f0);
            local_fc = -76000.0;
            local_f8 = 5000.0;
            local_f4 = 5000.0;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
            (*pcVar51)(piVar28,(AEMath *)&local_98);
            piVar28 = *(int **)(puVar6[1] + 4);
            pcVar51 = *(code **)(*piVar28 + 0x44);
            (**(code **)(**(int **)(puVar6[1] + 0xc) + 0x28))(&local_f0);
            local_fc = -79000.0;
            local_f8 = 4900.0;
            local_f4 = 7500.0;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
            (*pcVar51)(piVar28,(AEMath *)&local_98);
            piVar28 = *(int **)(puVar6[1] + 8);
            pcVar51 = *(code **)(*piVar28 + 0x44);
            (**(code **)(**(int **)(puVar6[1] + 0xc) + 0x28))(&local_f0);
            local_fc = -79000.0;
            local_f8 = 4900.0;
            local_f4 = 2500.0;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
            (*pcVar51)(piVar28,(AEMath *)&local_98);
            iVar13 = 0;
            do {
              local_98 = 0x3f800000;
              local_90 = 0.0;
              local_f0 = 0x3f80000000000000;
              local_e8 = 0.0;
              AEGeometry::setDirection
                        (*(AEGeometry **)(*(int *)(puVar6[1] + iVar13 * 4) + 8),(Vector *)&local_98,
                         (Vector *)&local_f0);
              piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
              piVar28[0xd] = 3;
              piVar28[0x49] = 0;
              (**(code **)(*piVar28 + 0xc))();
              KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar13 * 4),true);
              iVar13 = iVar13 + 1;
            } while (iVar13 != 3);
            LVar4 = (LevelScript)PlayerEgo::isInTurretMode(this_00);
            this[0xab] = LVar4;
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8)
                      );
            AEGeometry::getPosition();
            pVVar49 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
            AEGeometry::getDirection();
            pVVar48 = (Vector *)(this + 0x40);
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            AEGeometry::getRightVector();
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            AEGeometry::getUpVector();
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
            pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(*(Level **)(this + 0x18),0);
            PlayerFixedObject::setDockingType(pPVar40,0);
            pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(*(Level **)(this + 0x18),0);
            AbyssEngine::String::String(aSStack_19c,"",false);
            PlayerFixedObject::setName(pPVar40,aSStack_19c);
            AbyssEngine::String::~String(aSStack_19c);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
LAB_0016e2bc:
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          }
          break;
        case 2:
          iVar13 = 0;
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          do {
            pfVar25 = (float *)&DAT_001689a4;
            if (iVar13 == 1) {
              pfVar25 = (float *)&DAT_001689a8;
            }
            fVar57 = *pfVar25;
            if (iVar13 == 0) {
              fVar57 = 2.0;
            }
            AEGeometry::moveForward
                      (*(AEGeometry **)(*(int *)(puVar6[1] + iVar13 * 4) + 8),fVar56 * fVar57);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 3);
          iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x14));
          if (iVar13 != 0) {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) =
                 *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
            *(undefined4 *)(this + 0x98) =
                 *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
            *(undefined4 *)(this + 0x9c) =
                 *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8)
                      );
            AEGeometry::getPosition();
            pVVar49 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
            AEGeometry::getDirection();
            pVVar48 = (Vector *)(this + 0x40);
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            fVar56 = (float)__aeabi_l2f(*(uint *)(this + 0x98) + 0xf3c,
                                        *(int *)(this + 0x9c) +
                                        (uint)(0xfffff0c3 < *(uint *)(this + 0x98)));
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            AEGeometry::getRightVector();
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            fVar56 = (float)__aeabi_l2f(*(uint *)(this + 0x98) + 500,
                                        *(int *)(this + 0x9c) +
                                        (uint)(0xfffffe0b < *(uint *)(this + 0x98)));
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            AEGeometry::getUpVector();
            AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            fVar56 = (float)__aeabi_l2f(*(undefined4 *)(this + 0x98),*(undefined4 *)(this + 0x9c));
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56 * 0.004 + 400.0);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
          }
          break;
        case 3:
          fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar56 = (float)__aeabi_l2f(*(undefined4 *)(this + 0x98),*(undefined4 *)(this + 0x9c));
          uVar69 = __aeabi_f2lz(fVar57 * 0.05 + fVar56);
          *(undefined8 *)(this + 0x98) = uVar69;
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8));
          pPVar3 = Globals::Canvas;
          uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
          local_98 = *puVar15;
          local_90 = *(float *)(puVar15 + 1);
          local_8c = *(undefined4 *)((int)puVar15 + 0xc);
          local_88 = (undefined4)puVar15[2];
          local_84 = *(undefined4 *)((int)puVar15 + 0x14);
          local_80 = (undefined4)puVar15[3];
          uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
          local_78 = (undefined4)puVar15[4];
          local_74 = *(undefined4 *)((int)puVar15 + 0x24);
          local_70 = (undefined4)puVar15[5];
          local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
          local_68 = (undefined4)puVar15[6];
          local_64 = *(undefined4 *)((int)puVar15 + 0x34);
          uStack_60 = (undefined4)puVar15[7];
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
          pVVar48 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AEGeometry::getDirection();
          pVVar49 = (Vector *)(this + 0x40);
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar49,fVar57 * 1.7);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_f0);
          AEGeometry::getRightVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar49,fVar56 * 0.03);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_f0);
          AEGeometry::getUpVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar49,fVar57 * 0.05 * 0.004);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_f0);
          TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
          AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_f0,(Matrix *)&local_98,pVVar48)
          ;
          TargetFollowCamera::setLocal
                    (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c,
                     local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                     local_68,local_64,uStack_60);
          iVar13 = 0;
          do {
            pfVar25 = (float *)&DAT_001689c4;
            if (iVar13 == 1) {
              pfVar25 = (float *)&DAT_001689c8;
            }
            fVar56 = *pfVar25;
            if (iVar13 == 0) {
              fVar56 = 2.0;
            }
            AEGeometry::moveForward
                      (*(AEGeometry **)(*(int *)(puVar6[1] + iVar13 * 4) + 8),fVar57 * fVar56);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 3);
          iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x14));
          if (iVar13 == 1) {
            iVar13 = 0;
            do {
              PlayerFighter::setCloakingPossible(*(PlayerFighter **)(puVar6[1] + iVar13 * 4),true);
              PlayerFighter::cloak(*(PlayerFighter **)(puVar6[1] + iVar13 * 4),18000,false);
              iVar13 = iVar13 + 1;
            } while (iVar13 != 3);
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          break;
        case 4:
          fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar56 = (float)__aeabi_l2f(*(undefined4 *)(this + 0x98),*(undefined4 *)(this + 0x9c));
          uVar69 = __aeabi_f2lz(fVar57 * 0.05 + fVar56);
          *(undefined8 *)(this + 0x98) = uVar69;
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          pPVar3 = Globals::Canvas;
          uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
          local_98 = *puVar15;
          local_90 = *(float *)(puVar15 + 1);
          local_8c = *(undefined4 *)((int)puVar15 + 0xc);
          local_88 = (undefined4)puVar15[2];
          local_84 = *(undefined4 *)((int)puVar15 + 0x14);
          local_80 = (undefined4)puVar15[3];
          uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
          local_78 = (undefined4)puVar15[4];
          local_74 = *(undefined4 *)((int)puVar15 + 0x24);
          local_70 = (undefined4)puVar15[5];
          local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
          local_68 = (undefined4)puVar15[6];
          local_64 = *(undefined4 *)((int)puVar15 + 0x34);
          uStack_60 = (undefined4)puVar15[7];
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
          pVVar49 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getDirection();
          pVVar48 = (Vector *)(this + 0x40);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 1.7);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getRightVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56 * 0.03);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getUpVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 0.05 * 0.004);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
          AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49)
          ;
          TargetFollowCamera::setLocal
                    (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c,
                     local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                     local_68,local_64,uStack_60);
          iVar13 = 0;
          do {
            pfVar25 = (float *)&DAT_001689c4;
            if (iVar13 == 1) {
              pfVar25 = (float *)&DAT_001689c8;
            }
            fVar56 = *pfVar25;
            if (iVar13 == 0) {
              fVar56 = 2.0;
            }
            AEGeometry::moveForward
                      (*(AEGeometry **)(*(int *)(puVar6[1] + iVar13 * 4) + 8),fVar57 * fVar56);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 3);
          iVar13 = *(int *)(this + 0x94);
          if ((int)(-(uint)(2000 < *(uint *)pLVar23) - iVar13) < 0 !=
              (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(2000 < *(uint *)pLVar23)))) {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          break;
        case 5:
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          iVar7 = 0;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          do {
            pfVar25 = (float *)&DAT_0016899c;
            if (iVar7 == 1) {
              pfVar25 = (float *)&DAT_001689a0;
            }
            fVar57 = *pfVar25;
            if (iVar7 == 0) {
              fVar57 = 6.0;
            }
            AEGeometry::moveForward
                      (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),fVar56 * fVar57);
            iVar7 = iVar7 + 1;
          } while (iVar7 != 3);
          if ((int)(uint)(*(uint *)pLVar23 < 0x7d1) <= *(int *)(this + 0x94)) {
            iVar13 = 0;
            uVar47 = puVar6[1];
            do {
              PlayerFighter::setAIDisabled(*(PlayerFighter **)(uVar47 + iVar13 * 4),false);
              uVar47 = puVar6[1];
              iVar7 = *(int *)(uVar47 + iVar13 * 4);
              iVar13 = iVar13 + 1;
              *(undefined4 *)(iVar7 + 0x34) = 4;
              *(undefined4 *)(iVar7 + 0x124) = 50000;
            } while (iVar13 != 3);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            iVar13 = PlayerEgo::isDockedToDockingPoint(this_00);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            if (iVar13 == 0) {
              TargetFollowCamera::setPosition
                        (*(TargetFollowCamera **)(this + 0x14),(Vector *)(this + 0x40));
            }
            else {
              lookBehind(this);
              TargetFollowCamera::setRotationAroundTarget
                        (*(TargetFollowCamera **)(this + 0x14),true);
              PlayerEgo::setFreeLookMode(this_00,true);
              if (this[0xab] != (LevelScript)0x0) {
                PlayerEgo::setTurretMode(this_00,true);
              }
            }
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            this[0x11] = (LevelScript)0x0;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            goto LAB_0016e2bc;
          }
          break;
        case 6:
          uVar47 = *(uint *)(this + 0x90) + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
          *(uint *)(this + 0x90) = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(uint)(uVar47 < 0xbb9) <= iVar13) {
LAB_001692f2:
            uVar29 = 7;
            goto LAB_0016c2dc;
          }
          break;
        case 7:
          iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x20));
          if (iVar7 != 1) {
            iVar7 = *(int *)(this + 0x1c);
            goto switchD_00163754_default;
          }
          iVar13 = PlayerEgo::isDockedToDockingPoint(this_00);
          if (iVar13 == 1) {
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::setAutoPilot(pPVar10,(KIPlayer *)0x0);
            iVar13 = *(int *)(this + 0xd4);
            *(undefined4 *)(iVar13 + 4) = 0;
            *(undefined4 *)(iVar13 + 8) = 0;
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::resetGunDelay(pPVar10);
            pKVar44 = (KIPlayer *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::dockToDockingPoint(pKVar44,(Radar *)0x0);
            PlayerEgo::setDockingState(this_00,3);
            TargetFollowCamera::setRotationAroundTarget(*(TargetFollowCamera **)(this + 0x14),false)
            ;
          }
          PlayerEgo::setTurretMode(this_00,false);
          resetCamera(this,*(Level **)(this + 0x18));
          iVar13 = PlayerEgo::isInRocketControl(this_00);
          if (iVar13 != 0) {
            PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
            fVar56 = (float)PlayerEgo::killLiberator(this_00);
            TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
          }
          PlayerEgo::setFreeLookMode(this_00,false);
          TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
          PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
          PlayerEgo::stopShooting(this_00,0);
          this[0x11] = (LevelScript)0x1;
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
          Player::setVulnerable(*(Player **)this_00,false);
          PlayerEgo::setComputerControlled(this_00,true);
          PlayerEgo::setCollide(this_00,false);
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
          AEGeometry::getPosition();
          pVVar48 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
          AEGeometry::getDirection();
          pVVar49 = (Vector *)(this + 0x40);
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
          AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar49,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
          AEGeometry::getRightVector();
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
          AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar49,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
          TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          break;
        default:
switchD_00163754_default:
          if (iVar7 - 9U < 2) {
            AEGeometry::getPosition();
            local_f0 = 0;
            local_e8 = 0.0;
            FModSound::updateEvent3DAttributes
                      (Globals::sound,0x8c9,(Vector *)&local_98,(Vector *)&local_f0,false);
            fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            uVar47 = *(uint *)(this + 0x90);
            *(uint *)(this + 0x90) = uVar47 + param_1;
            *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
            fVar57 = fVar56 * 0.006 + *(float *)(this + 0x28);
            *(float *)(this + 0x28) = fVar57;
            AEGeometry::moveForward(*(AEGeometry **)(*(int *)(puVar6[1] + 0xc) + 8),fVar56 * fVar57)
            ;
            if ((int)(uint)(*(uint *)(this + 0x90) < 0x7d1) <= *(int *)(this + 0x94)) {
              if (*(int *)(this + 0x1c) == 9) {
                *(undefined4 *)(this + 0x1c) = 10;
              }
              if ((int)(uint)(*(uint *)(this + 0x90) < 0x1b59) <= *(int *)(this + 0x94)) {
                TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
                TargetFollowCamera::setTarget
                          (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
                TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
                pTVar38 = *(TargetFollowCamera **)(this + 0x14);
                PlayerEgo::getPosition();
                fVar56 = (float)PlayerEgo::GetDirVector();
                AbyssEngine::AEMath::operator*((AEMath *)&local_b0,(Vector *)&local_120,fVar56);
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_b0);
                TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_fc);
                *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
                *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
                resetCamera(this,*(Level **)(this + 0x18));
                LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
                PlayerEgo::setComputerControlled(this_00,false);
                this[0x11] = (LevelScript)0x0;
                Player::setVulnerable(*(Player **)this_00,true);
                KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + 0xc),0));
                KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 0xc),false);
                *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
              }
            }
          }
          else if (iVar7 == 0xb) {
            fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            fVar57 = fVar56 * 0.02 + *(float *)(this + 0x28);
            *(float *)(this + 0x28) = fVar57;
            AEGeometry::moveForward(*(AEGeometry **)(*(int *)(puVar6[1] + 0xc) + 8),fVar56 * fVar57)
            ;
          }
          else if (iVar7 == 8) {
            fVar56 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
            pLVar23 = this + 0x90;
            uVar47 = *(uint *)pLVar23;
            *(uint *)pLVar23 = uVar47 + param_1;
            *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
            AEGeometry::moveForward(*(AEGeometry **)(*(int *)(puVar6[1] + 0xc) + 8),fVar56);
            if ((int)(uint)(*(uint *)pLVar23 < 0x1f41) <= *(int *)(this + 0x94)) {
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),
                         *(AEGeometry **)(*(int *)(puVar6[1] + 0xc) + 8));
              (**(code **)(**(int **)(puVar6[1] + 0xc) + 0x28))((Vector *)&local_98);
              pVVar49 = (Vector *)(this + 0x28);
              AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
              AEGeometry::getDirection();
              pVVar48 = (Vector *)(this + 0x40);
              fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
              AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
              AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
              AEGeometry::getRightVector();
              fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
              AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
              AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
              TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
              *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
              *(undefined4 *)pLVar23 = 0;
              *(undefined4 *)(this + 0x94) = 0;
              local_98 = 0x3f8000003f800000;
              local_90 = 1.0;
              AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
            }
          }
        }
      }
      else if (iVar7 == 0x5e) {
        iVar7 = -40000;
        switch(*(undefined4 *)(this + 0x1c)) {
        case 0:
          if ((6 < *(int *)(Globals::status + 0x174)) ||
             ((int)(uint)(*(uint *)(this + 8) < 0xea61) <= *(int *)(this + 0xc))) {
            iVar13 = 50000;
            iVar7 = 0;
            do {
              uVar29 = VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x16) & 3);
              piVar28 = *(int **)(puVar6[1] + iVar7 * 4);
              (**(code **)(*piVar28 + 0x48))(piVar28,uVar29,0x447a0000,0x4808b800);
              (**(code **)(**(int **)(puVar6[1] + iVar7 * 4) + 0xc))();
              KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar7 * 4),true);
              local_98 = 0;
              local_90 = -1.0;
              local_f0 = 0x3f80000000000000;
              local_e8 = 0.0;
              AEGeometry::setDirection
                        (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),(Vector *)&local_98,
                         (Vector *)&local_f0);
              PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + iVar7 * 4),true);
              iVar7 = iVar7 + 1;
              iVar13 = iVar13 + 3000;
            } while (iVar7 != 2);
            LVar4 = (LevelScript)PlayerEgo::isInTurretMode(this_00);
            this[0xab] = LVar4;
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8)
                      );
            AEGeometry::getPosition();
            pVVar49 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
            AEGeometry::getDirection();
            pVVar48 = (Vector *)(this + 0x40);
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            AEGeometry::getRightVector();
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            AEGeometry::getUpVector();
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
LAB_00164aba:
            iVar13 = *(int *)(this + 0x1c) + 1;
LAB_00164abe:
            *(int *)(this + 0x1c) = iVar13;
          }
          break;
        case 1:
          iVar7 = 0;
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          fVar56 = (float)VectorSignedToFloat(param_1 * 3,(byte)(in_fpscr >> 0x16) & 3);
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          do {
            fVar56 = (float)AEGeometry::moveForward
                                      (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),fVar56)
            ;
            iVar7 = iVar7 + 1;
          } while (iVar7 != 2);
          if ((int)(uint)(*(uint *)pLVar23 < 0x1771) <= *(int *)(this + 0x94)) {
            iVar13 = 0;
            do {
              PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + iVar13 * 4),false);
              iVar13 = iVar13 + 1;
            } while (iVar13 != 2);
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::resetGunDelay(pPVar10);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            iVar13 = PlayerEgo::isDockedToDockingPoint(this_00);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            if (iVar13 == 0) {
              TargetFollowCamera::setPosition
                        (*(TargetFollowCamera **)(this + 0x14),(Vector *)(this + 0x40));
            }
            else {
              lookBehind(this);
              TargetFollowCamera::setRotationAroundTarget
                        (*(TargetFollowCamera **)(this + 0x14),true);
              PlayerEgo::setFreeLookMode(this_00,true);
              if (this[0xab] != (LevelScript)0x0) {
                PlayerEgo::setTurretMode(this_00,true);
              }
            }
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            this[0x11] = (LevelScript)0x0;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            FModSound::stop(Globals::sound,*(int *)Globals::sound);
            goto LAB_0016de2c;
          }
          break;
        case 2:
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(-(uint)(100000 < uVar47) - iVar13) < 0 !=
              (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(100000 < uVar47)))) {
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            iVar13 = 2;
            do {
              piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
              pcVar51 = *(code **)(*piVar28 + 0x44);
              PlayerEgo::getPosition();
              local_fc = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
              local_f8 = 3000.0;
              local_f4 = 20000.0;
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
              (*pcVar51)(piVar28,(AEMath *)&local_98);
              (**(code **)(**(int **)(puVar6[1] + iVar13 * 4) + 0xc))();
              KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar13 * 4),true);
              iVar13 = iVar13 + 1;
              iVar7 = iVar7 + -3000;
            } while (iVar13 != 4);
LAB_00167344:
            iVar13 = *(int *)(this + 0x1c) + 1;
            goto LAB_0016d238;
          }
          break;
        case 3:
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(-(uint)(100000 < uVar47) - iVar13) < 0 !=
              (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(100000 < uVar47)))) {
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            iVar13 = 4;
            do {
              piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
              pcVar51 = *(code **)(*piVar28 + 0x44);
              PlayerEgo::getPosition();
              local_fc = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
              local_f8 = 3000.0;
              local_f4 = 20000.0;
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
              (*pcVar51)(piVar28,(AEMath *)&local_98);
              (**(code **)(**(int **)(puVar6[1] + iVar13 * 4) + 0xc))();
              KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar13 * 4),true);
              iVar13 = iVar13 + 1;
              iVar7 = iVar7 + -3000;
            } while (iVar13 != 6);
            goto LAB_00167344;
          }
        }
      }
      else if (iVar7 == 0x66) {
        iVar7 = *(int *)(this + 0x1c);
        fVar56 = extraout_s1_17;
        if (iVar7 == 0) {
          iVar7 = RadioMessage::isTriggered(*(RadioMessage **)puVar5[1]);
          if (iVar7 == 1) {
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            PlayerEgo::setFreeze(this_00,true);
            PlayerEgo::setVisible(this_00,false);
            Player::setVulnerable(*(Player **)this_00,false);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8)
                      );
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_f0);
            local_fc = 9000.0;
            local_f8 = -7000.0;
            local_f4 = 40000.0;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
            TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
            fVar56 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
            FModSound::play(Globals::sound,0x8c0,(Vector *)0x0,(Vector *)0x0,fVar56);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            goto LAB_0016e2bc;
          }
          iVar7 = *(int *)(this + 0x1c);
          fVar56 = extraout_s1_19;
        }
        switch(iVar7) {
        case 1:
          fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar60 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar57 * 0.8,fVar56,fVar60 * 2.5);
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
          if (iVar7 == 0) {
            uVar47 = *(uint *)(this + 0x90);
            iVar13 = *(int *)(this + 0x94);
          }
          else {
            uVar46 = *(uint *)(this + 0x90);
            uVar47 = uVar46 + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar46,param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
          }
          if ((int)(uint)(uVar47 < 0x7d1) <= iVar13) {
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::resetGunDelay(pPVar10);
            PlayerEgo::setFreeze(this_00,false);
            PlayerEgo::setVisible(this_00,true);
            Player::setVulnerable(*(Player **)this_00,true);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            PlayerEgo::getPosition();
            fVar56 = (float)PlayerEgo::GetDirVector();
            AbyssEngine::AEMath::operator*((AEMath *)&local_fc,(Vector *)&local_a4,fVar56);
            AbyssEngine::AEMath::operator-
                      ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
            TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            resetCamera(this,*(Level **)(this + 0x18));
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            this[0x11] = (LevelScript)0x0;
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            fVar56 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
            FModSound::play(Globals::sound,0x8c1,(Vector *)0x0,(Vector *)0x0,fVar56);
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          }
          break;
        case 2:
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(uint)(uVar47 < 0x7531) <= iVar13) {
            PlayerEgo::getPosition();
            uVar47 = 0xffffffff;
            if (*puVar6 != 0) {
              uVar46 = 0;
              do {
                piVar28 = *(int **)(puVar6[1] + uVar46 * 4);
                if (piVar28[9] == 10) {
                  (**(code **)(*piVar28 + 0xc))();
                  if (uVar47 == 0xffffffff) {
                    uVar47 = uVar46;
                  }
                  if (uVar46 == uVar47) {
                    piVar28 = (int *)((undefined4 *)puVar6[1])[uVar46];
                    pcVar51 = *(code **)(*piVar28 + 0x44);
                    (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_fc);
                    local_a4 = -0x385fd800;
                    local_a0 = 0x44fa0000;
                    local_9c = 0;
                    AbyssEngine::AEMath::operator+
                              ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
                    (*pcVar51)(piVar28,(AEMath *)&local_f0);
                    PlayerFighter::cloak(*(PlayerFighter **)(puVar6[1] + uVar46 * 4),1000,true);
                  }
                  else {
                    piVar28 = *(int **)(puVar6[1] + uVar46 * 4);
                    pcVar51 = *(code **)(*piVar28 + 0x44);
                    if (uVar46 == uVar47 + 1) {
                      (**(code **)(**(int **)(puVar6[1] + uVar47 * 4) + 0x28))((Vector *)&local_fc);
                      local_a4 = -0x3b060000;
                      local_a0 = -0x3bb80000;
                      local_9c = -0x3b060000;
                      AbyssEngine::AEMath::operator+
                                ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
                      (*pcVar51)(piVar28,(AEMath *)&local_f0);
                      PlayerFighter::cloak(*(PlayerFighter **)(puVar6[1] + uVar46 * 4),1000,true);
                    }
                    else {
                      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
                      iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
                      iVar37 = -1;
                      if (iVar7 == 0) {
                        iVar37 = 1;
                      }
                      iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
                      fVar56 = (float)VectorSignedToFloat(iVar37 * (iVar13 + 35000),
                                                          (byte)(in_fpscr >> 0x16) & 3);
                      iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
                      iVar37 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
                      iVar50 = -1;
                      if (iVar37 == 0) {
                        iVar50 = 1;
                      }
                      local_f8 = (float)VectorSignedToFloat(iVar7 + -5000,
                                                            (byte)(in_fpscr >> 0x16) & 3);
                      local_f4 = (float)VectorSignedToFloat((iVar13 + 35000) * iVar50,
                                                            (byte)(in_fpscr >> 0x16) & 3);
                      local_fc = fVar56;
                      AbyssEngine::AEMath::operator+
                                ((AEMath *)&local_f0,(Vector *)&local_98,(Vector *)&local_fc);
                      (*pcVar51)(piVar28,(AEMath *)&local_f0);
                    }
                  }
                  Player::setEnemies(*(Player **)(*(int *)(puVar6[1] + uVar46 * 4) + 4),(Array *)0x0
                                    );
                  iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
                  if (iVar13 == 4) {
                    pPVar41 = *(Player **)this_00;
                  }
                  else {
                    pPVar41 = *(Player **)(*(int *)(puVar6[1] + iVar13 * 4 + 8) + 4);
                  }
                  Player::setEnemy(*(Player **)(*(int *)(puVar6[1] + uVar46 * 4) + 4),pPVar41);
                  (**(code **)(**(int **)(puVar6[1] + uVar46 * 4) + 0xc))();
                  local_f0 = 0x3f800000;
                  local_e8 = 0.0;
                  local_fc = 0.0;
                  local_f8 = 1.0;
                  local_f4 = 0.0;
                  AEGeometry::setDirection
                            (*(AEGeometry **)(*(int *)(puVar6[1] + uVar46 * 4) + 8),
                             (Vector *)&local_f0,(Vector *)&local_fc);
                  PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + uVar46 * 4),true);
                }
                else if (piVar28[0x1e] == 0x33) {
                  pAVar26 = operator_new(0xc);
                  puVar9 = operator_new__(4);
                  *(undefined4 **)(pAVar26 + 4) = puVar9;
                  *puVar9 = 0;
                  *(undefined4 *)pAVar26 = 0;
                  uVar29 = *(undefined4 *)(*(int *)puVar6[1] + 4);
                  *(undefined4 *)(pAVar26 + 8) = 1;
                  pvVar16 = realloc(puVar9,4);
                  *(void **)(pAVar26 + 4) = pvVar16;
                  *(undefined4 *)((int)pvVar16 + *(int *)pAVar26 * 4) = uVar29;
                  *(int *)pAVar26 = *(int *)(pAVar26 + 8);
                  iVar13 = *(int *)(pAVar26 + 8) + 1;
                  uVar29 = *(undefined4 *)(*(int *)(puVar6[1] + 4) + 4);
                  *(int *)(pAVar26 + 8) = iVar13;
                  pvVar16 = realloc(pvVar16,iVar13 * 4);
                  *(void **)(pAVar26 + 4) = pvVar16;
                  *(undefined4 *)((int)pvVar16 + *(int *)pAVar26 * 4) = uVar29;
                  *(undefined4 *)pAVar26 = *(undefined4 *)(pAVar26 + 8);
                  Player::setEnemies(*(Player **)(*(int *)(puVar6[1] + uVar46 * 4) + 4),pAVar26);
                }
                uVar46 = uVar46 + 1;
              } while (uVar46 < *puVar6);
            }
            PlayerEgo::setTurretMode(this_00,false);
            PlayerEgo::setFreeze(this_00,true);
            PlayerEgo::setVisible(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),
                       *(AEGeometry **)(*(int *)(puVar6[1] + uVar47 * 4) + 8));
            AEGeometry::getPosition();
            pVVar49 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
            AEGeometry::getDirection();
            pVVar48 = (Vector *)(this + 0x40);
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            AEGeometry::getRightVector();
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            AEGeometry::getUpVector();
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
            AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
LAB_0016974a:
            *(undefined4 *)(this + 0x1c) = 3;
          }
          break;
        case 3:
          fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          fVar56 = (float)__aeabi_l2f(*(undefined4 *)(this + 0x98),*(undefined4 *)(this + 0x9c));
          uVar69 = __aeabi_f2lz(fVar57 * 0.05 + fVar56);
          *(undefined8 *)(this + 0x98) = uVar69;
          uVar47 = puVar6[1];
          if (*puVar6 != 0) {
            uVar53 = 0;
            dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            uVar46 = 0xffffffff;
            fVar56 = (float)(dVar65 * 2.2);
            do {
              iVar13 = *(int *)(uVar47 + uVar53 * 4);
              if (*(int *)(iVar13 + 0x24) == 10) {
                pAVar52 = *(AEGeometry **)(iVar13 + 8);
                if (uVar46 == 0xffffffff) {
                  uVar46 = uVar53;
                }
                if (uVar53 == uVar46) {
                  fVar56 = (float)AEGeometry::moveForward(pAVar52,fVar56);
                  uVar46 = uVar53;
                }
                else {
                  fVar56 = (float)AEGeometry::moveForward(pAVar52,fVar56);
                }
              }
              uVar47 = puVar6[1];
              uVar53 = uVar53 + 1;
            } while (uVar53 < *puVar6);
          }
          pPVar3 = Globals::Canvas;
          uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
          local_98 = *puVar15;
          local_90 = *(float *)(puVar15 + 1);
          local_8c = *(undefined4 *)((int)puVar15 + 0xc);
          local_88 = (undefined4)puVar15[2];
          local_84 = *(undefined4 *)((int)puVar15 + 0x14);
          local_80 = (undefined4)puVar15[3];
          uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
          local_78 = (undefined4)puVar15[4];
          local_74 = *(undefined4 *)((int)puVar15 + 0x24);
          local_70 = (undefined4)puVar15[5];
          local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
          local_68 = (undefined4)puVar15[6];
          local_64 = *(undefined4 *)((int)puVar15 + 0x34);
          uStack_60 = (undefined4)puVar15[7];
          AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
          pVVar49 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getDirection();
          pVVar48 = (Vector *)(this + 0x40);
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 2.04);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getRightVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 0.04);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          AEGeometry::getUpVector();
          AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 0.05 * 0.004);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
          TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
          AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49)
          ;
          TargetFollowCamera::setLocal
                    (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c,
                     local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,
                     local_68,local_64,uStack_60);
          if ((int)(uint)(*(uint *)pLVar23 < 0x2711) <= *(int *)(this + 0x94)) {
            uVar47 = *puVar6;
            if (uVar47 != 0) {
              uVar46 = 0;
              do {
                pPVar22 = *(PlayerFighter **)(puVar6[1] + uVar46 * 4);
                if (*(int *)(pPVar22 + 0x24) == 10) {
                  PlayerFighter::setAIDisabled(pPVar22,false);
                  uVar47 = *puVar6;
                }
                uVar46 = uVar46 + 1;
              } while (uVar46 < uVar47);
            }
            PlayerEgo::setFreeze(this_00,false);
            PlayerEgo::setVisible(this_00,true);
            TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            PlayerEgo::getPosition();
            fVar56 = (float)PlayerEgo::GetDirVector();
            AbyssEngine::AEMath::operator*((AEMath *)&local_a4,(Vector *)&local_b0,fVar56);
            AbyssEngine::AEMath::operator-
                      ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
            TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_f0);
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            resetCamera(this,*(Level **)(this + 0x18));
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            this[0x11] = (LevelScript)0x0;
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          break;
        case 4:
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(-(uint)(60000 < uVar47) - iVar13) < 0 !=
              (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(60000 < uVar47)))) {
            PlayerEgo::getPosition();
            if (*puVar6 != 0) {
              uVar47 = 0;
              do {
                pKVar44 = *(KIPlayer **)(puVar6[1] + uVar47 * 4);
                if ((*(int *)(pKVar44 + 0x24) == 10) &&
                   (iVar13 = KIPlayer::isDead(pKVar44), iVar13 == 1)) {
                  (**(code **)(**(int **)(puVar6[1] + uVar47 * 4) + 0x18))();
                  (**(code **)(**(int **)(puVar6[1] + uVar47 * 4) + 0xc))();
                  piVar28 = *(int **)(puVar6[1] + uVar47 * 4);
                  pcVar51 = *(code **)(*piVar28 + 0x44);
                  iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
                  iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
                  iVar37 = -1;
                  if (iVar7 == 0) {
                    iVar37 = 1;
                  }
                  iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
                  fVar56 = (float)VectorSignedToFloat(iVar37 * (iVar13 + 35000),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
                  iVar37 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
                  iVar50 = -1;
                  if (iVar37 == 0) {
                    iVar50 = 1;
                  }
                  local_f8 = (float)VectorSignedToFloat(iVar7 + -5000,(byte)(in_fpscr >> 0x16) & 3);
                  local_f4 = (float)VectorSignedToFloat((iVar13 + 35000) * iVar50,
                                                        (byte)(in_fpscr >> 0x16) & 3);
                  local_fc = fVar56;
                  AbyssEngine::AEMath::operator+
                            ((AEMath *)&local_f0,(Vector *)&local_98,(Vector *)&local_fc);
                  (*pcVar51)(piVar28,(AEMath *)&local_f0);
                }
                uVar47 = uVar47 + 1;
              } while (uVar47 < *puVar6);
            }
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          if (*puVar6 != 0) {
            uVar47 = 0;
            do {
              iVar13 = *(int *)(puVar6[1] + uVar47 * 4);
              if (*(int *)(iVar13 + 0x24) == 10) {
                pPVar41 = (Player *)Player::getEnemy(*(Player **)(iVar13 + 4),0);
                iVar13 = Player::isDead(pPVar41);
                if (iVar13 == 1) {
                  uVar46 = puVar6[1];
                  iVar13 = 2;
                  do {
                    iVar37 = iVar13;
                    iVar7 = KIPlayer::isDead(*(KIPlayer **)(uVar46 + iVar37 * 4));
                    uVar46 = puVar6[1];
                    iVar13 = iVar37 + 1;
                    if (iVar7 != 0) {
                      iVar37 = -1;
                    }
                  } while ((iVar13 < 6) && (iVar37 == -1));
                  if (iVar37 == -1) {
                    pPVar41 = *(Player **)this_00;
                  }
                  else {
                    pPVar41 = *(Player **)(*(int *)(uVar46 + iVar37 * 4) + 4);
                  }
                  Player::setEnemy(*(Player **)(*(int *)(uVar46 + uVar47 * 4) + 4),pPVar41);
                }
              }
              uVar47 = uVar47 + 1;
            } while (uVar47 < *puVar6);
          }
          pMVar12 = (Mission *)Status::getCampaignMission(Globals::status);
          iVar13 = Mission::getStatusValue(pMVar12);
          if (iVar13 < 10) {
            pMVar12 = (Mission *)Status::getCampaignMission(Globals::status);
            Mission::setType(pMVar12,4);
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            PlayerEgo::setFreeze(this_00,true);
            PlayerEgo::setVisible(this_00,false);
            Player::setVulnerable(*(Player **)this_00,false);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8)
                      );
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_f0);
            local_fc = 9000.0;
            local_f8 = -7000.0;
            local_f4 = 40000.0;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
            TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
            iVar13 = 2;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            do {
              piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
              (**(code **)(*piVar28 + 0x48))(piVar28,0x49742400,0x49742400,0x49742400);
              KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + iVar13 * 4),0));
              KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + iVar13 * 4),false);
              iVar13 = iVar13 + 1;
            } while (iVar13 != 10);
          }
          break;
        case 5:
          fVar56 = (float)VectorSignedToFloat(param_1 * 6,(byte)(in_fpscr >> 0x16) & 3);
          AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),fVar56);
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar57 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.1,extraout_s1_90,fVar57 * 1.8)
          ;
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          AEGeometry::getPosition();
          local_f0 = 0;
          local_e8 = 0.0;
          FModSound::updateEvent3DAttributes
                    (Globals::sound,0x8ca,(Vector *)&local_98,(Vector *)&local_f0,false);
          if (*(int *)(this + 0x94) < (int)(uint)(*(uint *)pLVar23 < 0x1f41)) break;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
LAB_00169a0c:
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          break;
        case 6:
          AEGeometry::getPosition();
          local_f0 = 0;
          local_e8 = 0.0;
          FModSound::updateEvent3DAttributes
                    (Globals::sound,0x8ca,(Vector *)&local_98,(Vector *)&local_f0,false);
          fVar56 = (float)VectorSignedToFloat(param_1 * 200,(byte)(in_fpscr >> 0x16) & 3);
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          AEGeometry::moveForward(*(AEGeometry **)(*(int *)puVar6[1] + 8),fVar56);
          if ((int)(uint)(*(uint *)pLVar23 < 0xfa1) <= *(int *)(this + 0x94)) {
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::resetGunDelay(pPVar10);
            PlayerEgo::setFreeze(this_00,false);
            PlayerEgo::setVisible(this_00,true);
            Player::setVulnerable(*(Player **)this_00,true);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            TargetFollowCamera::setPosition
                      (*(TargetFollowCamera **)(this + 0x14),(Vector *)(this + 0x40));
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            PlayerEgo::getPosition();
            fVar56 = (float)PlayerEgo::GetDirVector();
            AbyssEngine::AEMath::operator*((AEMath *)&local_b0,(Vector *)&local_120,fVar56);
            AbyssEngine::AEMath::operator-
                      ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_b0);
            TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_fc);
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            resetCamera(this,*(Level **)(this + 0x18));
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            this[0x11] = (LevelScript)0x0;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            goto LAB_0016e2bc;
          }
        }
      }
    }
    else {
      if (iVar7 != 0x69) {
        if (iVar7 == 0x72) {
          if ((*(int *)(this + 0x1c) == 0) && (uVar47 = *puVar6, uVar47 != 0)) {
            uVar46 = 0;
            do {
              iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
              if (*(int *)(iVar13 + 0x24) == 8) {
                iVar13 = Player::isActive(*(Player **)(iVar13 + 4));
                uVar47 = *puVar6;
                if (iVar13 == 1) {
                  if (uVar47 != 0) {
                    uVar46 = 0;
                    do {
                      piVar28 = *(int **)(puVar6[1] + uVar46 * 4);
                      if (piVar28[9] == 8) {
                        piVar28[0x49] = 50000;
                        (**(code **)(*piVar28 + 0xc))();
                        uVar47 = *puVar6;
                      }
                      uVar46 = uVar46 + 1;
                    } while (uVar46 < uVar47);
                  }
                  goto LAB_0016324e;
                }
              }
              uVar46 = uVar46 + 1;
            } while (uVar46 < uVar47);
          }
        }
        else if (iVar7 == 0x7d) {
          iVar7 = *(int *)(this + 0x1c);
          if (iVar7 == 0) {
            iVar37 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 4));
            iVar7 = *(int *)(this + 0x1c);
            if (iVar37 != 1) goto LAB_00164744;
            *(int *)(this + 0x1c) = iVar7 + 1;
            local_90 = -NAN;
            local_98 = 0xfffeee90;
            pRVar27 = operator_new(0x18);
            Route::Route(pRVar27,(int *)&local_98,3);
            Level::setPlayerRoute(*(Level **)(this + 0x18),pRVar27);
            PlayerEgo::setRoute(this_00,pRVar27);
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          else {
LAB_00164744:
            if ((iVar7 == 1) && (iVar7 = PlayerEgo::getRoute(this_00), iVar7 != 0)) {
              pRVar27 = (Route *)PlayerEgo::getRoute(this_00);
              iVar7 = Route::getWaypoint(pRVar27,0);
              if (*(char *)(iVar7 + 300) != '\0') {
                iVar7 = 8;
                *(undefined4 *)(this + 0x1c) = 2;
                uVar47 = puVar6[1];
                do {
                  pPVar40 = *(PlayerFixedObject **)(uVar47 + iVar7 * 4);
                  pSVar14 = (String *)GameText::getText(Globals::gameText,0xc8c);
                  AbyssEngine::String::String((String *)&local_f0," ",false);
                  AbyssEngine::operator+((AbyssEngine *)&local_98,pSVar14,(String *)&local_f0);
                  local_fc = 0.0;
                  AbyssEngine::String::Set(CONCAT44(extraout_r1_00,(String *)&local_fc));
                  AbyssEngine::operator+(aAStack_1ec,(AbyssEngine *)&local_98,(String *)&local_fc);
                  PlayerFixedObject::setName(pPVar40,aAStack_1ec);
                  AbyssEngine::String::~String((String *)aAStack_1ec);
                  AbyssEngine::String::~String((String *)&local_fc);
                  AbyssEngine::String::~String((String *)&local_98);
                  AbyssEngine::String::~String((String *)&local_f0);
                  KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + iVar7 * 4),0));
                  uVar47 = puVar6[1];
                  iVar37 = iVar7 * 4;
                  iVar7 = iVar7 + 1;
                  *(undefined1 *)(*(int *)(uVar47 + iVar37) + 0x70) = 0;
                } while (iVar7 < 0xb);
              }
            }
          }
          iVar7 = *(int *)(this + 0x1c);
          if (iVar7 == 2) {
            iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
            if (iVar7 == 1) {
              iVar7 = 8;
              iVar13 = 0;
              do {
                (**(code **)(**(int **)(puVar6[1] + iVar7) + 0xc))();
                piVar28 = *(int **)(puVar6[1] + iVar7);
                pcVar51 = *(code **)(*piVar28 + 0x44);
                PlayerEgo::getPosition();
                iVar37 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
                iVar50 = AbyssEngine::AERandom::nextInt(Globals::rnd,1000);
                iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,2000);
                iVar19 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
                iVar20 = -1;
                iVar36 = -1;
                if (iVar19 < 0x32) {
                  iVar20 = 1;
                }
                if (iVar37 < 0x32) {
                  iVar36 = 1;
                }
                local_fc = (float)VectorSignedToFloat(iVar13 * iVar36 + 2000,
                                                      (byte)(in_fpscr >> 0x16) & 3);
                local_f8 = (float)VectorSignedToFloat(iVar50 + 2000,(byte)(in_fpscr >> 0x16) & 3);
                local_f4 = (float)VectorSignedToFloat(-57000 - iVar20 * iVar18,
                                                      (byte)(in_fpscr >> 0x16) & 3);
                AbyssEngine::AEMath::operator+
                          ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
                (*pcVar51)(piVar28,(AEMath *)&local_98);
                pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + iVar7) + 8);
                PlayerEgo::getPosition();
                (**(code **)(**(int **)(puVar6[1] + iVar7) + 0x28))((Vector *)&local_a4);
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
                local_b0 = 0;
                local_ac = 0x3f800000;
                local_a8 = 0;
                AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_b0);
                PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + iVar7),true);
                Player::setEnemy(*(Player **)(*(int *)(puVar6[1] + iVar7) + 4),*(Player **)this_00);
                iVar7 = iVar7 + 4;
                iVar13 = iVar13 + 2000;
              } while (iVar7 != 0x18);
              PlayerEgo::setTurretMode(this_00,false);
              resetCamera(this,*(Level **)(this + 0x18));
              iVar13 = PlayerEgo::isInRocketControl(this_00);
              if (iVar13 != 0) {
                PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
                fVar56 = (float)PlayerEgo::killLiberator(this_00);
                TargetFollowCamera::setRumblePercentage
                          (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
              }
              PlayerEgo::setFreeLookMode(this_00,false);
              TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
              PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
              PlayerEgo::stopShooting(this_00,0);
              this[0x11] = (LevelScript)0x1;
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
              PlayerEgo::setVisible(this_00,false);
              PlayerEgo::setFreeze(this_00,true);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),
                         *(AEGeometry **)(*(int *)(puVar6[1] + 0x10) + 8));
              AEGeometry::getPosition();
              pVVar48 = (Vector *)(this + 0x28);
              AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
              fVar56 = (float)AEGeometry::getDirection();
              AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
              AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
              fVar56 = (float)AEGeometry::getUpVector();
              AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
              AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
              fVar56 = (float)AEGeometry::getRightVector();
              AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
              fVar56 = (float)AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
              TargetFollowCamera::setPosition
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_51,extraout_s2_23)
              ;
              *(undefined4 *)(this + 0x90) = 0;
              *(undefined4 *)(this + 0x94) = 0;
              goto LAB_00164aba;
            }
            iVar7 = *(int *)(this + 0x1c);
          }
          if (iVar7 == 3) {
            iVar7 = 2;
            fVar56 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
            do {
              fVar56 = (float)AEGeometry::moveForward
                                        (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),
                                         fVar56);
              iVar7 = iVar7 + 1;
            } while (iVar7 != 6);
            uVar47 = *(uint *)(this + 0x90) + param_1;
            iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
            *(uint *)(this + 0x90) = uVar47;
            *(int *)(this + 0x94) = iVar13;
            if ((int)(uint)(uVar47 < 0x1b59) <= iVar13) {
              iVar13 = 2;
              do {
                PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + iVar13 * 4),false);
                iVar13 = iVar13 + 1;
              } while (iVar13 != 6);
              *(undefined4 *)(this + 0x1c) = 4;
              PlayerEgo::setVisible(this_00,true);
              PlayerEgo::setFreeze(this_00,false);
              pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
              PlayerEgo::setAutoPilot(pPVar10,(KIPlayer *)0x0);
              pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
              iVar13 = PlayerEgo::isDockedToDockingPoint(pPVar10);
              if (iVar13 == 0) {
                iVar13 = *(int *)(this + 0xd4);
                *(undefined4 *)(iVar13 + 4) = 0;
                *(undefined4 *)(iVar13 + 8) = 0;
              }
              pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
              PlayerEgo::resetGunDelay(pPVar10);
              pKVar44 = (KIPlayer *)Level::getPlayer(*(Level **)(this + 0x18));
              PlayerEgo::dockToDockingPoint(pKVar44,*(Radar **)(*(int *)(this + 0xd4) + 4));
              pAVar52 = *(AEGeometry **)(this_00 + 8);
              (**(code **)(**(int **)(puVar6[1] + 0x10) + 0x28))((Vector *)&local_fc);
              PlayerEgo::getPosition();
              AbyssEngine::AEMath::operator-
                        ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
              AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
              local_b0 = 0;
              local_ac = 0x3f800000;
              local_a8 = 0;
              AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_b0);
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
              pTVar38 = *(TargetFollowCamera **)(this + 0x14);
              PlayerEgo::getPosition();
              fVar56 = (float)PlayerEgo::GetDirVector();
              AbyssEngine::AEMath::operator*((AEMath *)&local_fc,(Vector *)&local_a4,fVar56);
              AbyssEngine::AEMath::operator-
                        ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
              TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
              PlayerEgo::setComputerControlled(this_00,false);
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
              resetCamera(this,*(Level **)(this + 0x18));
              LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
              this[0x11] = (LevelScript)0x0;
            }
          }
          else if ((((iVar7 - 4U < 3) &&
                    (iVar13 = PlayerEgo::isDockedToDockingPoint(this_00), iVar13 == 1)) &&
                   (iVar13 = PlayerEgo::hackingWon(this_00), iVar13 == 1)) &&
                  (iVar13 = PlayerEgo::getHackingGameDockIndex(this_00), -1 < iVar13)) {
            pLVar43 = *(Level **)(this + 0x18);
            iVar13 = PlayerEgo::getHackingGameDockIndex(this_00);
            pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(pLVar43,iVar13);
            PlayerFixedObject::setDockingType(pPVar40,0);
            pLVar43 = *(Level **)(this + 0x18);
            iVar13 = PlayerEgo::getHackingGameDockIndex(this_00);
            pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(pLVar43,iVar13);
            AbyssEngine::String::String(aSStack_1f4,"",false);
            PlayerFixedObject::setName(pPVar40,aSStack_1f4);
            AbyssEngine::String::~String(aSStack_1f4);
            pLVar43 = *(Level **)(this + 0x18);
            iVar13 = PlayerEgo::getHackingGameDockIndex(this_00);
            iVar13 = Level::getDockingTarget(pLVar43,iVar13);
            *(undefined1 *)(iVar13 + 0x70) = 1;
            PlayerEgo::deleteHackingGame(this_00);
            iVar13 = *(int *)(this + 0x1c);
            *(int *)(this + 0x1c) = iVar13 + 1;
            if (iVar13 + 1 == 6) {
              iVar13 = 0x8fc;
              iVar37 = 25000;
              iVar7 = 0x18;
              do {
                (**(code **)(**(int **)(puVar6[1] + iVar7) + 0xc))();
                piVar28 = *(int **)(puVar6[1] + iVar7);
                pcVar51 = *(code **)(*piVar28 + 0x44);
                PlayerEgo::getPosition();
                local_fc = (float)VectorSignedToFloat(iVar37,(byte)(in_fpscr >> 0x16) & 3);
                local_f8 = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x16) & 3);
                local_f4 = 25000.0;
                AbyssEngine::AEMath::operator+
                          ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
                (*pcVar51)(piVar28,(AEMath *)&local_98);
                iVar13 = iVar13 + 0x32;
                iVar7 = iVar7 + 4;
                iVar37 = iVar37 + 1000;
              } while (iVar13 != 0x960);
            }
          }
        }
        goto switchD_00161b94_caseD_1;
      }
      iVar7 = *(int *)(this + 0x1c);
      fVar56 = extraout_s0_03;
      fVar57 = extraout_s1_17;
      if (iVar7 < 3) {
        iVar7 = 0;
        fVar56 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
        do {
          fVar56 = (float)AEGeometry::moveForward
                                    (*(AEGeometry **)(*(int *)(puVar6[1] + iVar7 * 4) + 8),fVar56);
          iVar7 = iVar7 + 1;
        } while (iVar7 != 2);
        iVar7 = *(int *)(this + 0x1c);
        fVar57 = extraout_s1_40;
      }
      if (iVar7 < 5) {
        this[0x11] = (LevelScript)0x1;
      }
      switch(iVar7) {
      case 1:
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23;
        *(uint *)pLVar23 = uVar47 + param_1;
        *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
        fVar56 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_a4,(Vector *)&local_b0,fVar56);
        fVar56 = (float)AEGeometry::getRightVector();
        AbyssEngine::AEMath::operator*((AEMath *)&local_120,(Vector *)&local_12c,fVar56);
        fVar56 = (float)AbyssEngine::AEMath::operator+
                                  ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_120);
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar56 = (float)AbyssEngine::AEMath::operator*
                                  ((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_41,extraout_s2_16);
        if ((int)(uint)(*(uint *)pLVar23 < 0x32c9) <= *(int *)(this + 0x94)) {
          iVar13 = 2;
LAB_00163bf6:
          *(int *)(this + 0x1c) = iVar13;
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
        break;
      case 2:
        fVar56 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_a4,(Vector *)&local_b0,fVar56);
        fVar56 = (float)AEGeometry::getRightVector();
        AbyssEngine::AEMath::operator*((AEMath *)&local_120,(Vector *)&local_12c,fVar56);
        fVar56 = (float)AbyssEngine::AEMath::operator+
                                  ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_120);
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),local_90 * 0.9,extraout_s1_x00105,
                   (float)local_98 * 0.9);
        iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 4));
        if (iVar13 == 1) {
          AEGeometry::getRightVector();
          AEGeometry::getDirection();
          local_a4 = (int)((float)local_f0 * 900000.0 - local_fc * 900000.0);
          local_a0 = (int)(local_f0._4_4_ * 900000.0 - local_f8 * 900000.0);
          local_9c = (int)(local_e8 * 900000.0 - local_f4 * 900000.0);
          local_b0 = (int)(local_fc * -900000.0 - (float)local_f0 * 900000.0);
          local_ac = (int)(local_f8 * -900000.0 - local_f0._4_4_ * 900000.0);
          local_a8 = (int)(local_f4 * -90000.0 - local_e8 * 900000.0);
          pRVar27 = operator_new(0x18);
          Route::Route(pRVar27,&local_a4,3);
          pRVar30 = operator_new(0x18);
          Route::Route(pRVar30,&local_b0,3);
          KIPlayer::setRoute(*(KIPlayer **)puVar6[1],pRVar27);
          KIPlayer::setRoute(*(KIPlayer **)(puVar6[1] + 4),pRVar30);
          uVar47 = puVar6[1];
          iVar13 = 0;
          do {
            PlayerFighter::setAIDisabled(*(PlayerFighter **)(uVar47 + iVar13 * 4),false);
            uVar47 = puVar6[1];
            iVar7 = iVar13 * 4;
            iVar13 = iVar13 + 1;
            *(undefined1 *)(*(int *)(uVar47 + iVar7) + 0x128) = 1;
          } while (iVar13 != 2);
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
        break;
      case 3:
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23;
        *(uint *)pLVar23 = uVar47 + param_1;
        *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
        fVar56 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_a4,(Vector *)&local_b0,fVar56);
        fVar56 = (float)AEGeometry::getRightVector();
        AbyssEngine::AEMath::operator*((AEMath *)&local_120,(Vector *)&local_12c,fVar56);
        fVar56 = (float)AbyssEngine::AEMath::operator+
                                  ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_120);
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),local_90 * 0.4,extraout_s1_x00106,
                   (float)local_98 * 0.4);
        uVar47 = puVar6[1];
        iVar13 = 0;
        do {
          iVar7 = iVar13 * 4;
          iVar13 = iVar13 + 1;
          *(undefined1 *)(*(int *)(uVar47 + iVar7) + 0x128) = 1;
        } while (iVar13 != 2);
        iVar13 = *(int *)(this + 0x94);
        if ((int)(-(uint)(3000 < *(uint *)pLVar23) - iVar13) < 0 !=
            (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(3000 < *(uint *)pLVar23)))) {
LAB_0016ad7e:
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
LAB_0016e254:
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
        }
        break;
      case 4:
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23;
        *(uint *)pLVar23 = uVar47 + param_1;
        *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
        fVar56 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_a4,(Vector *)&local_b0,fVar56);
        fVar56 = (float)AEGeometry::getRightVector();
        AbyssEngine::AEMath::operator*((AEMath *)&local_120,(Vector *)&local_12c,fVar56);
        fVar56 = (float)AbyssEngine::AEMath::operator+
                                  ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_120);
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),local_90 * 0.1,extraout_s1_x00107,
                   (float)local_98 * 0.1);
        uVar47 = puVar6[1];
        iVar13 = 0;
        do {
          iVar7 = iVar13 * 4;
          iVar13 = iVar13 + 1;
          *(undefined1 *)(*(int *)(uVar47 + iVar7) + 0x128) = 1;
        } while (iVar13 != 2);
        iVar13 = *(int *)(this + 0x94);
        iVar7 = 0;
        if ((int)(-(uint)(3000 < *(uint *)pLVar23) - iVar13) < 0 !=
            (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)(3000 < *(uint *)pLVar23)))) {
          pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
          PlayerEgo::resetGunDelay(pPVar10);
          PlayerEgo::setComputerControlled(this_00,false);
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
          resetCamera(this,*(Level **)(this + 0x18));
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          this[0x11] = (LevelScript)0x0;
          uVar47 = puVar6[1];
          do {
            iVar13 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(undefined1 *)(*(int *)(uVar47 + iVar13) + 0x70) = 1;
          } while (iVar7 != 2);
          goto LAB_0016ad7e;
        }
        break;
      case 5:
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23 + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
        *(uint *)pLVar23 = uVar47;
        *(int *)(this + 0x94) = iVar13;
        if ((int)(uint)(uVar47 < 0x2711) <= iVar13) {
          iVar13 = 0;
          do {
            KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + iVar13 * 4),0));
            piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
            (**(code **)(*piVar28 + 0x1c))(piVar28,0);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 2);
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
        break;
      case 6:
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23 + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
        *(uint *)pLVar23 = uVar47;
        *(int *)(this + 0x94) = iVar13;
        if ((int)(uint)(uVar47 < 0x5dc1) <= iVar13) {
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
          Level::getStarSystem(*(Level **)(this + 0x18));
          StarSystem::getLightDirection();
          AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
          AEGeometry::getPosition();
          uVar47 = puVar6[1];
          iVar13 = 2;
          do {
            (**(code **)(**(int **)(uVar47 + iVar13 * 4) + 0xc))();
            PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + iVar13 * 4),true);
            PlayerFighter::cloak(*(PlayerFighter **)(puVar6[1] + iVar13 * 4),1000,true);
            uVar47 = puVar6[1];
            iVar13 = iVar13 + 1;
          } while (iVar13 != 5);
          (**(code **)(**(int **)(uVar47 + 8) + 0x48))
                    (*(int **)(uVar47 + 8),(float)local_f0 + (float)local_98 * 100000.0,0,
                     local_e8 + local_90 * 100000.0);
          pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + 8) + 8);
          AbyssEngine::AEMath::operator-((AEMath *)&local_fc,(Vector *)&local_98);
          local_a4 = 0;
          local_a0 = 0x3f800000;
          local_9c = 0;
          AEGeometry::setDirection(pAVar52,(Vector *)&local_fc,(Vector *)&local_a4);
          piVar28 = *(int **)(puVar6[1] + 0xc);
          pcVar51 = *(code **)(*piVar28 + 0x44);
          (**(code **)(**(int **)(puVar6[1] + 8) + 0x28))((Vector *)&local_120);
          fVar56 = (float)AEGeometry::getRightVector();
          AbyssEngine::AEMath::operator*((AEMath *)&local_12c,aVStack_1a8,fVar56);
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_b0,(Vector *)&local_120,(Vector *)&local_12c);
          fVar56 = (float)AEGeometry::getUpVector();
          AbyssEngine::AEMath::operator*(aAStack_1b4,aVStack_1c0,fVar56);
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_a4,(Vector *)&local_b0,(Vector *)aAStack_1b4);
          fVar56 = (float)AEGeometry::getDirection();
          AbyssEngine::AEMath::operator*(aAStack_1cc,aVStack_1d8,fVar56);
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)aAStack_1cc);
          (*pcVar51)(piVar28,(AEMath *)&local_fc);
          pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + 0xc) + 8);
          AbyssEngine::AEMath::operator-((AEMath *)&local_fc,(Vector *)&local_98);
          local_a4 = 0;
          local_a0 = 0x3f800000;
          local_9c = 0;
          AEGeometry::setDirection(pAVar52,(Vector *)&local_fc,(Vector *)&local_a4);
          piVar28 = *(int **)(puVar6[1] + 0x10);
          pcVar51 = *(code **)(*piVar28 + 0x44);
          (**(code **)(**(int **)(puVar6[1] + 8) + 0x28))((Vector *)&local_120);
          fVar56 = (float)AEGeometry::getRightVector();
          AbyssEngine::AEMath::operator*((AEMath *)&local_12c,aVStack_1a8,fVar56);
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_b0,(Vector *)&local_120,(Vector *)&local_12c);
          AEGeometry::getUpVector();
          fVar56 = (float)AbyssEngine::AEMath::operator+
                                    ((AEMath *)aVStack_1c0,(Vector *)aAStack_1cc);
          AbyssEngine::AEMath::operator*(aAStack_1b4,aVStack_1c0,fVar56);
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_a4,(Vector *)&local_b0,(Vector *)aAStack_1b4);
          fVar56 = (float)AEGeometry::getDirection();
          AbyssEngine::AEMath::operator*((AEMath *)aVStack_1d8,aVStack_1e4,fVar56);
          AbyssEngine::AEMath::operator+((AEMath *)&local_fc,(Vector *)&local_a4,aVStack_1d8);
          (*pcVar51)(piVar28,(AEMath *)&local_fc);
          pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + 0x10) + 8);
          AbyssEngine::AEMath::operator-((AEMath *)&local_fc,(Vector *)&local_98);
          local_a4 = 0;
          local_a0 = 0x3f800000;
          local_9c = 0;
          AEGeometry::setDirection(pAVar52,(Vector *)&local_fc,(Vector *)&local_a4);
          iVar13 = 2;
          do {
            pVVar48 = *(Vector **)(*(int *)(puVar6[1] + iVar13 * 4) + 8);
            fVar56 = (float)AEGeometry::getRightVector();
            AbyssEngine::AEMath::operator*((AEMath *)&local_fc,(Vector *)&local_a4,fVar56);
            AEGeometry::translate(pVVar48);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 5);
          PlayerEgo::setTurretMode(this_00,false);
          PlayerEgo::setFreeze(this_00,true);
          PlayerEgo::setVisible(this_00,false);
          resetCamera(this,*(Level **)(this + 0x18));
          iVar13 = PlayerEgo::isInRocketControl(this_00);
          if (iVar13 != 0) {
            PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
            fVar56 = (float)PlayerEgo::killLiberator(this_00);
            TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
          }
          PlayerEgo::setFreeLookMode(this_00,false);
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
          TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
          PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
          PlayerEgo::stopShooting(this_00,0);
          this[0x11] = (LevelScript)0x1;
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),
                     *(AEGeometry **)(*(int *)(puVar6[1] + 8) + 8));
          AEGeometry::getPosition();
          pVVar49 = (Vector *)(this + 0x28);
          AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_fc);
          AEGeometry::getDirection();
          pVVar48 = (Vector *)(this + 0x40);
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_fc);
          AbyssEngine::AEMath::operator*((AEMath *)&local_fc,pVVar48,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_fc);
          AEGeometry::getRightVector();
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_fc);
          AbyssEngine::AEMath::operator*((AEMath *)&local_fc,pVVar48,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_fc);
          AEGeometry::getUpVector();
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_fc);
          AbyssEngine::AEMath::operator*((AEMath *)&local_fc,pVVar48,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_fc);
          TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) =
               *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
          *(undefined4 *)(this + 0x98) =
               *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
          *(undefined4 *)(this + 0x9c) =
               *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
          goto LAB_0016e254;
        }
        break;
      case 7:
        fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23;
        *(uint *)pLVar23 = uVar47 + param_1;
        *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
        fVar56 = (float)__aeabi_l2f(*(undefined4 *)(this + 0x98),*(undefined4 *)(this + 0x9c));
        uVar69 = __aeabi_f2lz(fVar57 * 0.05 + fVar56);
        dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        iVar13 = 2;
        *(undefined8 *)(this + 0x98) = uVar69;
        fVar56 = (float)(dVar65 * 2.4);
        do {
          for (; iVar13 == 2; iVar13 = iVar13 + 1) {
            iVar7 = *(int *)(puVar6[1] + 8);
LAB_0016b29e:
            fVar56 = (float)AEGeometry::moveForward(*(AEGeometry **)(iVar7 + 8),fVar56);
          }
          if (iVar13 == 3) {
            iVar7 = *(int *)(puVar6[1] + 0xc);
            goto LAB_0016b29e;
          }
          if (iVar13 == 4) {
            AEGeometry::moveForward(*(AEGeometry **)(*(int *)(puVar6[1] + 0x10) + 8),fVar56);
            break;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 != 5);
        pPVar3 = Globals::Canvas;
        uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
        puVar15 = (ulonglong *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
        local_98 = *puVar15;
        local_90 = *(float *)(puVar15 + 1);
        local_8c = *(undefined4 *)((int)puVar15 + 0xc);
        local_88 = (undefined4)puVar15[2];
        local_84 = *(undefined4 *)((int)puVar15 + 0x14);
        local_80 = (undefined4)puVar15[3];
        uStack_7c = *(undefined4 *)((int)puVar15 + 0x1c);
        local_78 = (undefined4)puVar15[4];
        local_74 = *(undefined4 *)((int)puVar15 + 0x24);
        local_70 = (undefined4)puVar15[5];
        local_6c = *(undefined4 *)((int)puVar15 + 0x2c);
        local_68 = (undefined4)puVar15[6];
        local_64 = *(undefined4 *)((int)puVar15 + 0x34);
        uStack_60 = (undefined4)puVar15[7];
        AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(Matrix *)&local_98);
        pVVar49 = (Vector *)(this + 0x28);
        AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_f0);
        AEGeometry::getDirection();
        pVVar48 = (Vector *)(this + 0x40);
        AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 1.96);
        AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
        AEGeometry::getRightVector();
        AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 0.03);
        AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
        AEGeometry::getUpVector();
        AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_f0);
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,pVVar48,fVar57 * 0.05 * 0.004);
        AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_f0);
        TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),true);
        AbyssEngine::AEMath::MatrixSetTranslation((AEMath *)&local_f0,(Matrix *)&local_98,pVVar49);
        TargetFollowCamera::setLocal
                  (*(undefined4 *)(this + 0x14),(float)local_98,local_98._4_4_,local_90,local_8c,
                   local_88,local_84,local_80,uStack_7c,local_78,local_74,local_70,local_6c,local_68
                   ,local_64,uStack_60);
        if ((int)(uint)(*(uint *)pLVar23 < 0x2711) <= *(int *)(this + 0x94)) {
          iVar13 = 2;
          do {
            PlayerFighter::setAIDisabled(*(PlayerFighter **)(puVar6[1] + iVar13 * 4),false);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 5);
          PlayerEgo::setFreeze(this_00,false);
          PlayerEgo::setVisible(this_00,true);
          TargetFollowCamera::setFixed(*(TargetFollowCamera **)(this + 0x14),false);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          PlayerEgo::getPosition();
          fVar56 = (float)PlayerEgo::GetDirVector();
          AbyssEngine::AEMath::operator*((AEMath *)&local_a4,(Vector *)&local_b0,fVar56);
          AbyssEngine::AEMath::operator-
                    ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
          TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_f0);
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
          resetCamera(this,*(Level **)(this + 0x18));
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          this[0x11] = (LevelScript)0x0;
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
        }
        break;
      case 8:
        uVar47 = *(uint *)(this + 0x90) + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
        *(uint *)(this + 0x90) = uVar47;
        *(int *)(this + 0x94) = iVar13;
        if ((int)(uint)(uVar47 < 0xea61) <= iVar13) {
          *(undefined4 *)(this + 0x1c) = 9;
        }
        break;
      case 9:
        pLVar23 = this + 0x90;
        uVar47 = *(uint *)pLVar23 + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
        *(uint *)pLVar23 = uVar47;
        *(int *)(this + 0x94) = iVar13;
        if ((int)(uint)(uVar47 < 0x1adb1) <= iVar13) {
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
          Level::getStarSystem(*(Level **)(this + 0x18));
          StarSystem::getLightDirection();
          AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
          AEGeometry::getPosition();
          iVar13 = 2;
          iVar7 = 10000;
          do {
            iVar37 = KIPlayer::isDead(*(KIPlayer **)(puVar6[1] + iVar13 * 4));
            if (iVar37 == 1) {
              (**(code **)(**(int **)(puVar6[1] + iVar13 * 4) + 0x18))();
              piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
              fVar61 = (float)local_98 * 100000.0;
              fVar56 = (float)local_f0;
              pcVar51 = *(code **)(*piVar28 + 0x48);
              uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,1000);
              fVar64 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
              uVar58 = AbyssEngine::AERandom::nextInt(Globals::rnd,1000);
              fVar57 = local_e8;
              fVar62 = local_90 * 100000.0;
              fVar63 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
              uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,1000);
              fVar60 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
              uVar29 = VectorSignedToFloat(uVar58,(byte)(in_fpscr >> 0x16) & 3);
              (*pcVar51)(piVar28,fVar64 + fVar56 + fVar61 + fVar63,uVar29,fVar57 + fVar62 + fVar60);
              pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + iVar13 * 4) + 8);
              AbyssEngine::AEMath::operator-((AEMath *)&local_fc,(Vector *)&local_98);
              local_a4 = 0;
              local_a0 = 0x3f800000;
              local_9c = 0;
              AEGeometry::setDirection(pAVar52,(Vector *)&local_fc,(Vector *)&local_a4);
              pVVar48 = *(Vector **)(*(int *)(puVar6[1] + iVar13 * 4) + 8);
              fVar56 = (float)AEGeometry::getRightVector();
              AbyssEngine::AEMath::operator*((AEMath *)&local_fc,(Vector *)&local_a4,fVar56);
              AEGeometry::translate(pVVar48);
            }
            iVar13 = iVar13 + 1;
            iVar7 = iVar7 + 5000;
          } while (iVar13 != 5);
        }
        iVar13 = PlayerEgo::getHitpoints();
        if ((0 < iVar13) && (iVar13 = PlayerEgo::getRoute(this_00), iVar13 != 0)) {
          pRVar27 = (Route *)PlayerEgo::getRoute(this_00);
          iVar13 = Route::getWaypoint(pRVar27,0);
          if (*(char *)(iVar13 + 300) != '\0') {
            Player::setVulnerable(*(Player **)this_00,false);
            PlayerEgo::stopBoost(this_00);
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
        }
        break;
      case 10:
        iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x1c));
        if (iVar7 != 1) {
          iVar7 = *(int *)(this + 0x1c);
          fVar56 = extraout_s0_11;
          fVar57 = extraout_s1_x00108;
          goto switchD_00163b3c_default;
        }
        PlayerEgo::setTurretMode(this_00,false);
        resetCamera(this,*(Level **)(this + 0x18));
        iVar13 = PlayerEgo::isInRocketControl(this_00);
        if (iVar13 != 0) {
          PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
          fVar56 = (float)PlayerEgo::killLiberator(this_00);
          TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar56,0);
        }
        PlayerEgo::setFreeLookMode(this_00,false);
        TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
        PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
        Player::setVulnerable(*(Player **)this_00,false);
        *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
        *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
        PlayerEgo::stopShooting(this_00,0);
        this[0x11] = (LevelScript)0x1;
        TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
        PlayerEgo::setComputerControlled(this_00,true);
        pTVar38 = *(TargetFollowCamera **)(this + 0x14);
        AEGeometry::getPosition();
        TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
        pAVar52 = *(AEGeometry **)(this_00 + 8);
        Level::getStarSystem(*(Level **)(this + 0x18));
        StarSystem::getLightDirection();
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
        local_fc = 0.0;
        local_f8 = 1.0;
        local_f4 = 0.0;
        AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_fc);
        AEGeometry::getDirection();
        pVVar48 = (Vector *)(this + 0x28);
        fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
        AbyssEngine::AEMath::Vector::operator*=(pVVar48,fVar56);
        local_98 = 0;
        local_90 = 0.0;
        AEGeometry::getRightVector();
        fVar56 = (float)AbyssEngine::AEMath::Vector::operator=
                                  ((Vector *)&local_98,(Vector *)&local_f0);
        AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_98,fVar56);
        AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
        AEGeometry::getUpVector();
        fVar56 = (float)AbyssEngine::AEMath::Vector::operator=
                                  ((Vector *)&local_98,(Vector *)&local_f0);
        AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_98,fVar56);
        AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
        AEGeometry::getPosition();
        fVar56 = (float)AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_f0);
        TargetFollowCamera::setPosition
                  (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_x00109,extraout_s2_41);
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        *(undefined4 *)(this + 0x90) = 0;
        *(undefined4 *)(this + 0x94) = 0;
        *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
        break;
      default:
switchD_00163b3c_default:
        if (iVar7 == 0xd) {
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          uVar47 = *(uint *)(this + 0x90);
          *(uint *)(this + 0x90) = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          PlayerEgo::rotate(this_00,fVar56 / 800.0,fVar57,800.0);
          fVar56 = (float)VectorSignedToFloat(param_1 * 0xc,(byte)(in_fpscr >> 0x16) & 3);
          fVar56 = (float)AEGeometry::moveForward(*(AEGeometry **)(this_00 + 8),fVar56);
          TargetFollowCamera::setRumblePercentage
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,0x42480000);
          if ((int)(uint)(*(uint *)(this + 0x90) < 0x1771) <= *(int *)(this + 0x94)) {
            uVar29 = Player::getHitpoints(*(Player **)this_00);
            *(undefined4 *)(Globals::status + 100) = uVar29;
            uVar29 = Player::getShieldHP(*(Player **)this_00);
            *(undefined4 *)(Globals::status + 0x5c) = uVar29;
            uVar29 = Player::getArmorHP(*(Player **)this_00);
            *(undefined4 *)(Globals::status + 0x60) = uVar29;
            uVar29 = Player::getGammaHP(*(Player **)this_00);
            pSVar33 = Globals::status;
            *(undefined4 *)(Globals::status + 0x68) = uVar29;
            Status::nextCampaignMission(SUB41(pSVar33,0));
            pSVar33 = Globals::status;
            pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,0x6f);
            Status::setStation(pSVar33,pSVar32);
            pSVar33 = Globals::status;
            pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,0x6f);
            Status::departStation(pSVar33,pSVar32);
            Level::initStreamOutPosition = 1;
            Globals::switch_to_target_setting = 1;
            AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
          }
        }
        else if (iVar7 == 0xc) {
          pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
          iVar13 = StarSystem::getPlanets(pSVar31);
          pVVar48 = (Vector *)**(undefined4 **)(iVar13 + 4);
          fVar56 = (float)AEGeometry::getScaling();
          AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
          fVar56 = (float)AEGeometry::setScaling(pVVar48);
          TargetFollowCamera::setRumblePercentage
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,0x42480000);
          uVar47 = *puVar6;
          if (uVar47 != 0) {
            uVar46 = 0;
            do {
              piVar28 = *(int **)(puVar6[1] + uVar46 * 4);
              if ((piVar28 != (int *)0x0) && (piVar28[9] == 10)) {
                pcVar51 = *(code **)(*piVar28 + 0x2c);
                PlayerEgo::getPosition();
                (*pcVar51)(piVar28,&local_98,100000);
                uVar47 = *puVar6;
              }
              uVar46 = uVar46 + 1;
            } while (uVar46 < uVar47);
          }
          iVar13 = Layout::isFading(Globals::layout);
          if (iVar13 == 0) {
            Layout::startFade(Globals::layout,false,-1,2000);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            pAVar52 = *(AEGeometry **)(this_00 + 8);
            AEGeometry::getDirection();
            AbyssEngine::AEMath::operator-((AEMath *)&local_98,(Vector *)&local_f0);
            local_fc = 0.0;
            local_f8 = 1.0;
            local_f4 = 0.0;
            AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_fc);
            if (*(AEGeometry **)(this + 0xdc) != (AEGeometry *)0x0) {
              pvVar16 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xdc));
              operator_delete(pvVar16);
            }
            *(undefined4 *)(this + 0xdc) = 0;
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
            StarSystem::switchSunForSupernovaExpansion(pSVar31);
            goto LAB_0016e254;
          }
        }
        else if (iVar7 == 0xb) {
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar7 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar7;
          if ((int)(uint)(uVar47 < 0x9c5) <= iVar7) {
            if (*(int *)(this + 0xdc) == 0) {
              pAVar52 = operator_new(0xc0);
              AEGeometry::AEGeometry(pAVar52,0x37a7,Globals::Canvas,false);
              *(AEGeometry **)(this + 0xdc) = pAVar52;
              AEGeometry::getPosition();
              AEGeometry::setPosition((Vector *)pAVar52);
              pAVar52 = *(AEGeometry **)(this + 0xdc);
              AEGeometry::getDirection();
              local_f0 = 0x3f80000000000000;
              local_e8 = 0.0;
              AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
              fVar56 = (float)TargetFollowCamera::setTarget
                                        (*(TargetFollowCamera **)(this + 0x14),
                                         *(AEGeometry **)(this + 0xdc));
              FModSound::play(Globals::sound,0xe,(Vector *)0x0,(Vector *)0x0,fVar56);
              puVar15 = (ulonglong *)
                        TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
              local_98 = *puVar15;
              local_90 = *(float *)(puVar15 + 1);
              local_f0 = 0;
              local_e8 = 0.0;
              fVar56 = (float)FModSound::updateEvent3DAttributes
                                        (Globals::sound,0xe,(Vector *)&local_98,(Vector *)&local_f0,
                                         false);
              uVar47 = *(uint *)pLVar23;
              iVar7 = *(int *)(this + 0x94);
            }
            if ((int)(uint)(uVar47 < 0x2329) <= iVar7) {
              iVar13 = (iVar7 - iVar13) - (uint)(uVar47 < (uint)param_1);
              bVar55 = 9000 < uVar47 - param_1;
              if ((int)(-(uint)bVar55 - iVar13) < 0 ==
                  (SBORROW4(0,iVar13) != SBORROW4(-iVar13,(uint)bVar55))) {
                FModSound::play(Globals::sound,0x8c8,(Vector *)0x0,(Vector *)0x0,fVar56);
              }
              pSVar31 = (StarSystem *)Level::getStarSystem(*(Level **)(this + 0x18));
              iVar13 = StarSystem::getPlanets(pSVar31);
              pVVar48 = (Vector *)**(undefined4 **)(iVar13 + 4);
              fVar56 = (float)AEGeometry::getScaling();
              AbyssEngine::AEMath::operator*((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
              AEGeometry::setScaling(pVVar48);
              if ((int)(uint)(*(uint *)pLVar23 < 0x2711) <= *(int *)(this + 0x94)) {
                Layout::startFade(Globals::layout,true,-1,500);
                iVar13 = *(int *)(this + 0x1c) + 1;
                goto LAB_00163bf6;
              }
            }
          }
        }
      }
      if (*(AEGeometry **)(this + 0xdc) != (AEGeometry *)0x0) {
        fVar56 = (float)VectorSignedToFloat(param_1 * 0xd,(byte)(in_fpscr >> 0x16) & 3);
        AEGeometry::moveForward(*(AEGeometry **)(this + 0xdc),fVar56);
      }
    }
    goto switchD_00161b94_caseD_1;
  }
  if (iVar7 < 0x38) {
    if (iVar7 < 0x1d) {
      if (iVar7 < 0x15) {
        if (iVar7 == 0xe) {
          iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 4));
          bVar55 = iVar13 == 1;
          if (bVar55) {
            iVar13 = *(int *)(this + 0x1c);
          }
          if (bVar55 && iVar13 == 0) {
            *(undefined4 *)(this + 0x1c) = 1;
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            Player::setHitpoints(*(Player **)(**(int **)(iVar13 + 4) + 4),0);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            KIPlayer::setDead((KIPlayer *)**(undefined4 **)(iVar13 + 4));
            iVar7 = *(int *)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            pMVar45 = *(Matrix **)(**(int **)(iVar13 + 4) + 300);
            AEGeometry::getReferenceMatrix(*(AEGeometry **)(this_00 + 8));
            ParticleSystemManager::systemSetMatrix(iVar7,pMVar45);
            pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            ParticleSystemManager::enableSystemEmit
                      (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 300),true);
            pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            ParticleSystemManager::enableSystemRender
                      (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 300),true);
            iVar7 = *(int *)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            pMVar45 = *(Matrix **)(**(int **)(iVar13 + 4) + 0x130);
            AEGeometry::getReferenceMatrix(*(AEGeometry **)(this_00 + 8));
            ParticleSystemManager::systemSetMatrix(iVar7,pMVar45);
            pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            ParticleSystemManager::enableSystemEmit
                      (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 0x130),true);
            pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            ParticleSystemManager::enableSystemRender
                      (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 0x130),true);
            iVar7 = *(int *)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            pMVar45 = *(Matrix **)(**(int **)(iVar13 + 4) + 0x134);
            AEGeometry::getReferenceMatrix(*(AEGeometry **)(this_00 + 8));
            ParticleSystemManager::systemSetMatrix(iVar7,pMVar45);
            pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            ParticleSystemManager::enableSystemEmit
                      (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 0x134),true);
            pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x8c);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            fVar56 = (float)ParticleSystemManager::enableSystemRender
                                      (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 0x134),true);
            FModSound::play(Globals::sound,0xf,(Vector *)0x0,(Vector *)0x0,fVar56);
          }
          else {
            iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 4));
            if (iVar13 == 1 && *(int *)(this + 0x1c) == 1) {
              local_98 = 0;
              local_90 = 0.0;
              PlayerEgo::getPosition();
              FModSound::updateEvent3DAttributes
                        (Globals::sound,0xf,(Vector *)&local_f0,(Vector *)&local_98,false);
              PlayerEgo::setTurretMode(this_00,false);
              resetCamera(this,*(Level **)(this + 0x18));
              PlayerEgo::setFreeLookMode(this_00,false);
              TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
              PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
              this[0x11] = (LevelScript)0x1;
              PlayerEgo::stopShooting(this_00,0);
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
              Level::flashScreen(*(Level **)(this + 0x18),3);
              fVar56 = (float)PlayerEgo::setComputerControlled(this_00,true);
              PlayerEgo::setSpeed(this_00,fVar56);
              Player::removeAllGuns(*(Player **)this_00);
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
              pTVar38 = *(TargetFollowCamera **)(this + 0x14);
              PlayerEgo::getPosition();
              fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_fc);
              TargetFollowCamera::translate
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_39,extraout_s2_15)
              ;
              piVar28 = (int *)Level::getEnemies(*(Level **)(this + 0x18));
              pLVar43 = *(Level **)(this + 0x18);
              if (*piVar28 != 0) {
                uVar47 = 0;
                do {
                  iVar13 = Level::getEnemies(pLVar43);
                  if (*(int *)(*(int *)(*(int *)(iVar13 + 4) + uVar47 * 4) + 0x24) == 8) {
                    iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
                    Player::setHitpoints
                              (*(Player **)(*(int *)(*(int *)(iVar13 + 4) + uVar47 * 4) + 4),0);
                    iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
                    KIPlayer::setDead(*(KIPlayer **)(*(int *)(iVar13 + 4) + uVar47 * 4));
                  }
                  puVar5 = (uint *)Level::getEnemies(*(Level **)(this + 0x18));
                  pLVar43 = *(Level **)(this + 0x18);
                  uVar47 = uVar47 + 1;
                } while (uVar47 < *puVar5);
              }
              LODManager::forceUpdate(*(LODManager **)pLVar43,param_1,false);
              *(undefined4 *)(this + 0x1c) = 2;
            }
            else if (*(int *)(this + 0x1c) == 2) {
              PlayerEgo::setTurretMode(this_00,false);
              resetCamera(this,*(Level **)(this + 0x18));
              PlayerEgo::setFreeLookMode(this_00,false);
              TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
              PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
              this[0x11] = (LevelScript)0x1;
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
              AEGeometry::updateReferenceMatrix(*(AEGeometry **)(this_00 + 8));
              fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
              fVar56 = (float)AEGeometry::rotate(*(AEGeometry **)(this_00 + 8),fVar56 / 10000.0,
                                                 extraout_s1_76,extraout_s2_31);
              TargetFollowCamera::translate
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_77,extraout_s2_32)
              ;
              iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0xc));
              if (iVar13 == 1) {
                PlayerEgo::setVisible(this_00,false);
                pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x80);
                iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
                ParticleSystemManager::enableSystemEmit
                          (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 300),false);
                pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x80);
                iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
                ParticleSystemManager::enableSystemEmit
                          (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 0x130),false);
                pPVar39 = *(ParticleSystemManager **)(*(Level **)(this + 0x18) + 0x80);
                iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
                ParticleSystemManager::enableSystemEmit
                          (pPVar39,*(int *)(**(int **)(iVar13 + 4) + 0x134),false);
                iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
                piVar28 = (int *)Level::getEnemies(*(Level **)(this + 0x18));
                pPVar40 = *(PlayerFixedObject **)(*(int *)(iVar13 + 4) + *piVar28 * 4 + -4);
                PlayerFixedObject::setMoving(pPVar40,true);
                TargetFollowCamera::setTarget
                          (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(pPVar40 + 8));
                pTVar38 = *(TargetFollowCamera **)(this + 0x14);
                (**(code **)(*(int *)pPVar40 + 0x28))((Vector *)&local_98,pPVar40);
                fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
                TargetFollowCamera::translate
                          (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_78,
                           extraout_s2_33);
                *(undefined4 *)(this + 0x1c) = 3;
                puVar9 = *(undefined4 **)(this + 0x18);
                goto LAB_0016c62e;
              }
            }
            else {
              iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x10));
              if (iVar13 == 1 && *(int *)(this + 0x1c) == 3) {
                LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
                *(undefined4 *)(this + 0x90) = *(undefined4 *)(this + 8);
                *(undefined4 *)(this + 0x94) = *(undefined4 *)(this + 0xc);
LAB_00169322:
                *(undefined4 *)(this + 0x1c) = 4;
              }
              else if (*(int *)(this + 0x1c) == 4) {
                iVar13 = *(int *)(this + 0xc);
                iVar7 = *(int *)(this + 0x94) + (uint)(0xfffff05f < *(uint *)(this + 0x90));
                bVar55 = *(uint *)(this + 8) < *(uint *)(this + 0x90) + 4000;
                if ((int)((iVar13 - iVar7) - (uint)bVar55) < 0 ==
                    (SBORROW4(iVar13,iVar7) != SBORROW4(iVar13 - iVar7,(uint)bVar55))) {
                  Status::nextCampaignMission(SUB41(Globals::status,0));
                  pSVar33 = Globals::status;
                  pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,0x62);
                  Status::departStation(pSVar33,pSVar32);
                  Globals::switch_to_target_setting = 0;
                  AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                            (Globals::appManager,5);
                  Level::initStreamOutPosition = 0;
                  *(undefined4 *)(this + 0x1c) = 5;
                }
              }
            }
          }
        }
        else if (iVar7 == 0x10) {
          iVar13 = RadioMessage::isTriggered(*(RadioMessage **)puVar5[1]);
          iVar7 = *(int *)(this + 0x1c);
          if (iVar13 == 1 && iVar7 == 0) {
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            PlayerEgo::setComputerControlled(this_00,true);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x14),true);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            TargetFollowCamera::setTarget(pTVar38,*(AEGeometry **)(**(int **)(iVar13 + 4) + 8));
            iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
            (**(code **)(*(int *)**(undefined4 **)(iVar13 + 4) + 0x28))((Vector *)&local_98);
            local_f0 = 0x457a000045bb8000;
            local_e8 = 47500.0;
            AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_98,(Vector *)&local_f0);
            TargetFollowCamera::setPosition
                      (*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_98);
LAB_001620b4:
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            *(undefined4 *)(this + 0x1c) = 1;
          }
          else if (iVar7 == 2) {
            if (*(int *)(this + 0xc) < (int)(uint)(*(uint *)(this + 8) < 0x4e21)) goto LAB_00169c80;
            *(undefined4 *)(this + 0x1c) = 3;
LAB_00169c6c:
            iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
            PlayerWormHole::reset(*(PlayerWormHole **)(*(int *)(iVar13 + 4) + 0xc),true);
          }
          else if (iVar7 == 1) {
            fVar56 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
            fVar57 = (float)VectorSignedToFloat(param_1 * -3,(byte)(in_fpscr >> 0x16) & 3);
            TargetFollowCamera::translate
                      (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_18,fVar57);
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 4));
            if (iVar13 == 1) {
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
              PlayerEgo::setComputerControlled(this_00,false);
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
              resetCamera(this,*(Level **)(this + 0x18));
              LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
              *(undefined4 *)(this + 0x1c) = 2;
              this[0x11] = (LevelScript)0x0;
            }
          }
          else {
LAB_00169c80:
            iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 8));
            if (iVar13 == 1 && *(int *)(this + 0x1c) == 3) {
              *(undefined4 *)(this + 0x1c) = 4;
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              PlayerWormHole::open(*(PlayerWormHole **)(*(int *)(iVar13 + 4) + 0xc));
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              KIPlayer::setVisible(*(KIPlayer **)(*(int *)(iVar13 + 4) + 0xc),true);
              PlayerEgo::setTurretMode(this_00,false);
              resetCamera(this,*(Level **)(this + 0x18));
              PlayerEgo::setFreeLookMode(this_00,false);
              TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
              PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
              PlayerEgo::stopShooting(this_00,0);
              this[0x11] = (LevelScript)0x1;
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
              PlayerEgo::setComputerControlled(this_00,true);
              this_00[0x24] = (PlayerEgo)0x1;
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
              TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x14),true);
              pTVar38 = *(TargetFollowCamera **)(this + 0x14);
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              TargetFollowCamera::setTarget
                        (pTVar38,*(AEGeometry **)(*(int *)(*(int *)(iVar13 + 4) + 0xc) + 8));
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              (**(code **)(**(int **)(*(int *)(iVar13 + 4) + 0xc) + 0x28))((Vector *)&local_98);
              local_f0 = 0xc57a0000c60ca000;
              local_e8 = -30000.0;
              AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_98,(Vector *)&local_f0);
              TargetFollowCamera::setPosition
                        (*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_98);
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              (**(code **)(**(int **)(*(int *)(iVar13 + 4) + 0xc) + 0x28))((Vector *)&local_f0);
              AbyssEngine::AEMath::Vector::operator=((Vector *)&local_98,(Vector *)&local_f0);
              local_f0 = CONCAT44((int)local_98._4_4_,(int)(float)local_98);
              local_e8 = (float)(int)(local_90 + 30000.0);
              pRVar27 = operator_new(0x18);
              Route::Route(pRVar27,(int *)&local_f0,3);
              local_90 = local_90 + -15000.0;
              piVar28 = (int *)Level::getEnemies(*(Level **)(this + 0x18));
              pLVar43 = *(Level **)(this + 0x18);
              if (*piVar28 != 0) {
                uVar47 = 0;
                do {
                  iVar13 = Level::getEnemies(pLVar43);
                  pKVar44 = *(KIPlayer **)(*(int *)(iVar13 + 4) + uVar47 * 4);
                  if ((pKVar44 != (KIPlayer *)0x0) && (*(int *)(pKVar44 + 0x24) == 9)) {
                    iVar13 = (int)(float)local_98;
                    pcVar51 = *(code **)(*(int *)pKVar44 + 0x48);
                    fVar56 = local_98._4_4_;
                    uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,4000);
                    fVar60 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
                    fVar61 = local_90 + -2000.0;
                    uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,4000);
                    fVar57 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
                    (*pcVar51)(pKVar44,iVar13,fVar56 + -2000.0 + fVar60,fVar61 + fVar57);
                    pAVar52 = *(AEGeometry **)(pKVar44 + 8);
                    iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
                    (**(code **)(**(int **)(*(int *)(iVar13 + 4) + 0xc) + 0x28))
                              ((Vector *)&local_b0);
                    (**(code **)(*(int *)pKVar44 + 0x28))((Vector *)&local_120,pKVar44);
                    AbyssEngine::AEMath::operator-
                              ((AEMath *)&local_a4,(Vector *)&local_b0,(Vector *)&local_120);
                    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_fc,(Vector *)&local_a4);
                    local_12c = 0;
                    local_128 = 0x3f800000;
                    local_124 = 0;
                    AEGeometry::setDirection(pAVar52,(Vector *)&local_fc,(Vector *)&local_12c);
                    pRVar30 = (Route *)Route::clone(pRVar27);
                    KIPlayer::setRoute(pKVar44,pRVar30);
                    Player::setEnemies(*(Player **)(pKVar44 + 4),(Array *)0x0);
                  }
                  puVar5 = (uint *)Level::getEnemies(*(Level **)(this + 0x18));
                  pLVar43 = *(Level **)(this + 0x18);
                  uVar47 = uVar47 + 1;
                } while (uVar47 < *puVar5);
              }
              goto LAB_00169ef0;
            }
            if (*(int *)(this + 0x1c) == 4) {
              dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
              TargetFollowCamera::translate
                        (*(TargetFollowCamera **)(this + 0x14),(float)(dVar65 * 0.5),extraout_s1_91,
                         (float)(dVar65 * 0.2));
              iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0xc));
              if (iVar13 == 1) {
                *(undefined4 *)(this + 0x1c) = 5;
                piVar28 = (int *)Level::getEnemies(*(Level **)(this + 0x18));
                pLVar43 = *(Level **)(this + 0x18);
                if (*piVar28 != 0) {
                  uVar47 = 0;
                  do {
                    iVar13 = Level::getEnemies(pLVar43);
                    pKVar44 = *(KIPlayer **)(*(int *)(iVar13 + 4) + uVar47 * 4);
                    if ((pKVar44 != (KIPlayer *)0x0) && (*(int *)(pKVar44 + 0x24) == 9)) {
                      KIPlayer::setVisible(pKVar44,false);
                      KIPlayer::setDead(pKVar44);
                    }
                    puVar5 = (uint *)Level::getEnemies(*(Level **)(this + 0x18));
                    pLVar43 = *(Level **)(this + 0x18);
                    uVar47 = uVar47 + 1;
                  } while (uVar47 < *puVar5);
                }
                LODManager::forceUpdate(*(LODManager **)pLVar43,param_1,false);
                goto LAB_00169c6c;
              }
            }
            else {
              iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x10));
              if ((iVar13 == 1) && (*(int *)(this + 0x1c) == 5)) {
                *(undefined4 *)(this + 0x1c) = 6;
                this_00[0x24] = (PlayerEgo)0x0;
                TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
                TargetFollowCamera::setTarget
                          (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
                PlayerEgo::setComputerControlled(this_00,false);
                *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
                *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
                resetCamera(this,*(Level **)(this + 0x18));
                this[0x11] = (LevelScript)0x0;
                goto LAB_0016c62c;
              }
            }
          }
        }
      }
      else if (iVar7 == 0x15) {
        if (*(int *)(this + 0x1c) == 0) {
          iVar13 = 1;
LAB_00163c10:
          iVar7 = Level::getEnemies(*(Level **)(this + 0x18));
          if (*(char *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + iVar13 * 4) + 4) + 0x5c) == '\0')
          goto code_r0x00163c28;
          iVar13 = 1;
          do {
            iVar7 = Level::getEnemies(*(Level **)(this + 0x18));
            Player::setAlwaysEnemy
                      (*(Player **)(*(int *)(*(int *)(iVar7 + 4) + iVar13 * 4) + 4),true);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 4);
        }
LAB_00167438:
        iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 8));
        if ((iVar13 == 1) && (*(int *)(this + 0x1c) == 0)) {
          iVar13 = 1;
          do {
            iVar7 = Level::getEnemies(*(Level **)(this + 0x18));
            Player::setAlwaysEnemy
                      (*(Player **)(*(int *)(*(int *)(iVar7 + 4) + iVar13 * 4) + 4),true);
            iVar13 = iVar13 + 1;
          } while (iVar13 != 4);
LAB_00167470:
          *(undefined4 *)(this + 0x1c) = 1;
        }
      }
      else if (iVar7 == 0x18) {
        iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0xc));
        bVar55 = iVar7 == 1;
        if (bVar55) {
          iVar7 = *(int *)(this + 0x1c);
        }
        if (bVar55 && iVar7 == 0) {
          PlayerEgo::stopShooting(this_00,0);
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
          fVar56 = (float)Player::setVulnerable(*(Player **)this_00,false);
          AEGeometry::setRotation
                    (*(AEGeometry **)(this_00 + 8),fVar56,extraout_s1_72,extraout_s2_27);
          PlayerEgo::setComputerControlled(this_00,true);
          Player::removeAllGuns(*(Player **)this_00);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          AEGeometry::getPosition();
          fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_73,extraout_s2_28);
          AEGeometry::getPosition();
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_98);
          AEGeometry::getDirection();
          pVVar48 = (Vector *)(this + 0x40);
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
          AbyssEngine::AEMath::Vector::operator*=(pVVar48,fVar56);
          AbyssEngine::AEMath::Vector::operator+=((Vector *)(this + 0x28),pVVar48);
          iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
          piVar28 = *(int **)(*(int *)(iVar13 + 4) + 0xc);
          (**(code **)(*piVar28 + 0x48))
                    (piVar28,*(undefined4 *)(this + 0x28),*(undefined4 *)(this + 0x2c),
                     *(undefined4 *)(this + 0x30));
          piVar28 = (int *)Level::getEnemies(*(Level **)(this + 0x18));
          pLVar43 = *(Level **)(this + 0x18);
          if (*piVar28 != 0) {
            uVar47 = 0;
            do {
              iVar13 = Level::getEnemies(pLVar43);
              Player::setEnemies(*(Player **)(*(int *)(*(int *)(iVar13 + 4) + uVar47 * 4) + 4),
                                 (Array *)0x0);
              puVar5 = (uint *)Level::getEnemies(*(Level **)(this + 0x18));
              pLVar43 = *(Level **)(this + 0x18);
              uVar47 = uVar47 + 1;
            } while (uVar47 < *puVar5);
          }
          LODManager::forceUpdate(*(LODManager **)pLVar43,param_1,false);
          *(undefined4 *)(this + 0x1c) = 1;
          this[0x11] = (LevelScript)0x1;
        }
        else {
          iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x10));
          if (iVar7 == 1 && *(int *)(this + 0x1c) == 1) {
            iVar7 = Level::getLandmarks(*(Level **)(this + 0x18));
            KIPlayer::setVisible(*(KIPlayer **)(*(int *)(iVar7 + 4) + 0xc),true);
            iVar7 = Level::getLandmarks(*(Level **)(this + 0x18));
            PlayerWormHole::reset(*(PlayerWormHole **)(*(int *)(iVar7 + 4) + 0xc),false);
            iVar7 = Level::getLandmarks(*(Level **)(this + 0x18));
            fVar56 = (float)PlayerWormHole::open(*(PlayerWormHole **)(*(int *)(iVar7 + 4) + 0xc));
            FModSound::play(Globals::sound,0x22,(Vector *)0x0,(Vector *)0x0,fVar56);
            *(undefined4 *)(this + 0x1c) = 2;
            *(undefined4 *)(this + 0x90) = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
          else if (*(int *)(this + 0x1c) != 2) goto switchD_00161b94_caseD_1;
          puVar15 = (ulonglong *)
                    TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
          local_98 = *puVar15;
          local_90 = *(float *)(puVar15 + 1);
          local_f0 = 0;
          local_e8 = 0.0;
          fVar56 = (float)FModSound::updateEvent3DAttributes
                                    (Globals::sound,0x22,(Vector *)&local_98,(Vector *)&local_f0,
                                     false);
          TargetFollowCamera::setRumblePercentage
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,0x42480000);
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          uVar47 = *(uint *)(this + 0x90);
          *(uint *)(this + 0x90) = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          PlayerEgo::rotate(this_00,fVar56 / 5000.0,extraout_s1_32,5000.0);
        }
      }
    }
    else if (iVar7 < 0x29) {
      if (iVar7 == 0x1d) {
        iVar13 = RadioMessage::isTriggered(*(RadioMessage **)puVar5[1]);
        bVar55 = iVar13 == 1;
        if (bVar55) {
          iVar13 = *(int *)(this + 0x1c);
        }
        if (bVar55 && iVar13 == 0) {
          *(undefined4 *)(this + 0x1c) = 1;
          PlayerEgo::setTurretMode(this_00,false);
          resetCamera(this,*(Level **)(this + 0x18));
          PlayerEgo::setFreeLookMode(this_00,false);
          TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
          PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
          Player::setVulnerable(*(Player **)this_00,false);
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
          PlayerEgo::stopShooting(this_00,0);
          this[0x11] = (LevelScript)0x1;
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
          PlayerEgo::setComputerControlled(this_00,true);
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          AEGeometry::getPosition();
          TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
          AEGeometry::getDirection();
          pVVar48 = (Vector *)(this + 0x28);
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
          AbyssEngine::AEMath::Vector::operator*=(pVVar48,fVar56);
          local_98 = 0;
          local_90 = 0.0;
          AEGeometry::getRightVector();
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=
                                    ((Vector *)&local_98,(Vector *)&local_f0);
          AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_98,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
          AEGeometry::getUpVector();
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=
                                    ((Vector *)&local_98,(Vector *)&local_f0);
          AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_98,fVar56);
          AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
          AEGeometry::getPosition();
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_f0);
          TargetFollowCamera::setPosition
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_74,extraout_s2_29);
          pAVar52 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar52,0x37d2,Globals::Canvas,false);
          *(AEGeometry **)(this + 0xdc) = pAVar52;
          AEGeometry::getPosition();
          AEGeometry::setPosition((Vector *)pAVar52);
          pAVar52 = *(AEGeometry **)(this + 0xdc);
          AEGeometry::getDirection();
          local_fc = 0.0;
          local_f8 = 1.0;
          local_f4 = 0.0;
          AEGeometry::setDirection(pAVar52,(Vector *)&local_f0,(Vector *)&local_fc);
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          fVar56 = (float)TargetFollowCamera::setTarget
                                    (*(TargetFollowCamera **)(this + 0x14),
                                     *(AEGeometry **)(this + 0xdc));
          FModSound::play(Globals::sound,0xe,(Vector *)0x0,(Vector *)0x0,fVar56);
          puVar21 = (undefined8 *)
                    TargetFollowCamera::getPosition(*(TargetFollowCamera **)(this + 0x14));
          local_f0 = *puVar21;
          local_e8 = *(float *)(puVar21 + 1);
          local_fc = 0.0;
          local_f8 = 0.0;
          local_f4 = 0.0;
          FModSound::updateEvent3DAttributes
                    (Globals::sound,0xe,(Vector *)&local_f0,(Vector *)&local_fc,false);
        }
        else {
          iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
          bVar55 = iVar13 == 1;
          if (bVar55) {
            iVar13 = *(int *)(this + 0x1c);
          }
          if (bVar55 && iVar13 == 1) {
            *(undefined4 *)(this + 0x1c) = 2;
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            this[0x11] = (LevelScript)0x0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::setComputerControlled(this_00,false);
            Player::setVulnerable(*(Player **)this_00,true);
            if (*(AEGeometry **)(this + 0xdc) != (AEGeometry *)0x0) {
              pvVar16 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xdc));
              operator_delete(pvVar16);
            }
            *(undefined4 *)(this + 0xdc) = 0;
            *(char **)this = "11AbyssEngine11PaintCanvas11DrawImage2DEjiih";
            *(undefined4 *)(this + 8) = 0;
            *(undefined4 *)(this + 0xc) = 0;
            pOVar17 = operator_new(0x1c);
            Objective::Objective(pOVar17,3,180000,*(Level **)(this + 0x18));
            puVar9 = *(undefined4 **)(this + 0x18);
            puVar9[10] = pOVar17;
            LODManager::forceUpdate((LODManager *)*puVar9,param_1,false);
          }
        }
        if (*(AEGeometry **)(this + 0xdc) != (AEGeometry *)0x0) {
          fVar56 = (float)VectorSignedToFloat(param_1 * 3,(byte)(in_fpscr >> 0x16) & 3);
          AEGeometry::moveForward(*(AEGeometry **)(this + 0xdc),fVar56);
        }
      }
      else if (iVar7 == 0x28) {
        iVar13 = *(int *)(this + 0x1c);
        fVar56 = extraout_s2_10;
        fVar57 = extraout_s1_17;
        if (iVar13 == 0) {
          iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0xc));
          if (iVar13 == 1) {
            PlayerFixedObject::setMoving(*(PlayerFixedObject **)puVar6[1],true);
            piVar28 = *(int **)puVar6[1];
            pcVar51 = *(code **)(*piVar28 + 0x48);
            pRVar27 = (Route *)Level::getFriendRoute(*(Level **)(this + 0x18));
            iVar13 = Route::getWaypoint(pRVar27,0);
            uVar58 = VectorSignedToFloat(*(undefined4 *)(iVar13 + 0x120),
                                         (byte)(in_fpscr >> 0x16) & 3);
            pRVar27 = (Route *)Level::getFriendRoute(*(Level **)(this + 0x18));
            iVar13 = Route::getWaypoint(pRVar27,0);
            uVar59 = VectorSignedToFloat(*(undefined4 *)(iVar13 + 0x124),
                                         (byte)(in_fpscr >> 0x16) & 3);
            pRVar27 = (Route *)Level::getFriendRoute(*(Level **)(this + 0x18));
            iVar13 = Route::getWaypoint(pRVar27,0);
            uVar29 = VectorSignedToFloat(*(undefined4 *)(iVar13 + 0x128),
                                         (byte)(in_fpscr >> 0x16) & 3);
            (*pcVar51)(piVar28,uVar58,uVar59,uVar29);
            (**(code **)(**(int **)puVar6[1] + 0xc))();
            KIPlayer::setVisible(*(KIPlayer **)puVar6[1],true);
            *(undefined4 *)(*(int *)puVar6[1] + 0x24) = 1;
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            Player::setVulnerable(*(Player **)this_00,false);
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            PlayerEgo::stopShooting(this_00,0);
            this[0x11] = (LevelScript)0x1;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_98);
            fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
            TargetFollowCamera::translate
                      (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_22,extraout_s2_12);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8)
                      );
            goto LAB_001620b4;
          }
          iVar13 = *(int *)(this + 0x1c);
          fVar56 = extraout_s2_11;
          fVar57 = extraout_s1_21;
        }
        if (iVar13 == 2) {
          (**(code **)(**(int **)puVar6[1] + 0x28))(auStack_138);
          uVar47 = in_fpscr & 0xfffffff | (uint)(local_130 < 90000.0) << 0x1f;
          in_fpscr = uVar47 | (uint)NAN(local_130) << 0x1c;
          if ((byte)(uVar47 >> 0x1f) != ((byte)(in_fpscr >> 0x1c) & 1)) {
            iVar13 = *(int *)(this + 0x1c);
            goto LAB_001676aa;
          }
          *(undefined4 *)(this + 0x1c) = 3;
          if (3 < *puVar6) {
            uVar47 = *puVar6 - 4;
            do {
              piVar28 = *(int **)(puVar6[1] + uVar47 * 4);
              pcVar51 = *(code **)(*piVar28 + 0x48);
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              (**(code **)(**(int **)(*(int *)(iVar13 + 4) + 0xc) + 0x28))(local_144);
              fVar57 = local_144[0];
              uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              (**(code **)(**(int **)(*(int *)(iVar13 + 4) + 0xc) + 0x28))(auStack_150);
              fVar56 = local_14c;
              uVar58 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
              iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
              (**(code **)(**(int **)(*(int *)(iVar13 + 4) + 0xc) + 0x28))(auStack_15c);
              fVar61 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
              fVar62 = (float)VectorSignedToFloat(uVar58,(byte)(in_fpscr >> 0x16) & 3);
              fVar64 = local_154 + -10000.0;
              uVar29 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
              fVar60 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
              (*pcVar51)(piVar28,fVar57 + -10000.0 + fVar61,fVar56 + -10000.0 + fVar62,
                         fVar64 + fVar60);
              (**(code **)(**(int **)(puVar6[1] + uVar47 * 4) + 0xc))();
              (**(code **)(**(int **)(puVar6[1] + uVar47 * 4) + 0xc))();
              uVar47 = uVar47 + 1;
            } while (uVar47 < *puVar6);
          }
        }
        else if (iVar13 == 1) {
          fVar60 = (float)VectorSignedToFloat(param_1 * -2,(byte)(in_fpscr >> 0x16) & 3);
          TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar60,fVar57,fVar56);
          iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x10));
          if (iVar13 == 1) {
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            this[0x11] = (LevelScript)0x0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::setComputerControlled(this_00,false);
            Player::setVulnerable(*(Player **)this_00,true);
            goto LAB_00168058;
          }
        }
        else {
LAB_001676aa:
          if (iVar13 == 3) {
            (**(code **)(**(int **)puVar6[1] + 0x28))(auStack_168);
            iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
            (**(code **)(**(int **)(*(int *)(iVar13 + 4) + 0xc) + 0x28))(auStack_174);
            uVar47 = in_fpscr & 0xfffffff | (uint)(local_160 < local_16c) << 0x1f;
            in_fpscr = uVar47 | (uint)(NAN(local_160) || NAN(local_16c)) << 0x1c;
            if ((byte)(uVar47 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) goto LAB_00169322;
            iVar13 = *(int *)(this + 0x1c);
          }
          if (iVar13 == 4) {
            pPVar40 = *(PlayerFixedObject **)puVar6[1];
            (**(code **)(*(int *)pPVar40 + 0x28))(auStack_180,pPVar40);
            fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            PlayerFixedObject::moveForward(pPVar40,(int)((local_178 + -200000.0) - fVar56));
            (**(code **)(**(int **)puVar6[1] + 0x28))(auStack_18c);
            if (500000.0 < local_184) {
              (**(code **)(**(int **)puVar6[1] + 0x48))(*(int **)puVar6[1],0,0,0xc8435000);
              KIPlayer::setActive(SUB41(*(undefined4 *)puVar6[1],0));
              uVar29 = 5;
              goto LAB_0016c2dc;
            }
          }
        }
      }
    }
    else if (iVar7 == 0x29) {
      iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x10));
      bVar55 = iVar7 == 1;
      if (bVar55) {
        iVar7 = *(int *)(this + 0x1c);
      }
      if (!bVar55 || iVar7 != 0) {
        iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x14));
        iVar37 = *(int *)(this + 0x1c);
        if (iVar7 == 1 && iVar37 == 1) {
          *(undefined4 *)(this + 0x1c) = 2;
          TargetFollowCamera::setRotationAroundTarget(*(TargetFollowCamera **)(this + 0x14),false);
          AEGeometry::updateReferenceMatrix(*(AEGeometry **)(*(int *)puVar6[1] + 8));
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x74),*(int *)(this + 0xe0)
                     ,true);
          ParticleSystemManager::enableSystemEmit
                    (*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x74),*(int *)(this + 0xe4)
                     ,true);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          pPVar40 = (PlayerFixedObject *)**(undefined4 **)(iVar13 + 4);
          Player::setHitpoints(*(Player **)(pPVar40 + 4),9999999);
          PlayerFixedObject::setMoving(pPVar40,false);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(pPVar40 + 8));
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          (**(code **)(*(int *)pPVar40 + 0x28))((Vector *)&local_98,pPVar40);
          fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
          fVar56 = (float)TargetFollowCamera::translate
                                    (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_42,
                                     extraout_s2_17);
          FModSound::play(Globals::sound,0x9b,(Vector *)0x0,(Vector *)0x0,fVar56);
          Player::StopEngineSound(*(Player **)(*(int *)puVar6[1] + 4));
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
          goto switchD_00161b94_caseD_1;
        }
        if (iVar37 == 4) {
          AEGeometry::updateReferenceMatrix(*(AEGeometry **)(*(int *)puVar6[1] + 8));
          fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar57 = (float)VectorSignedToFloat(param_1 * -2,(byte)(in_fpscr >> 0x16) & 3);
          uVar47 = *(uint *)(this + 0x90);
          *(uint *)(this + 0x90) = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_x00112,fVar57);
          if ((int)(uint)(*(uint *)(this + 0x90) < 0x3a99) <= *(int *)(this + 0x94)) {
            FModSound::stop(Globals::sound,0x9c);
            *(undefined4 *)(this + 0x1c) = 5;
            Player::setHitpoints(*(Player **)(*(int *)puVar6[1] + 4),100);
            *(undefined4 *)(*(int *)puVar6[1] + 0x60) = 0;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            this[0x11] = (LevelScript)0x0;
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::useTargetsUpVector(*(TargetFollowCamera **)(this + 0x14),true);
            PlayerEgo::setComputerControlled(this_00,false);
            Player::setVulnerable(*(Player **)this_00,true);
            this_00[0x24] = (PlayerEgo)0x0;
LAB_0016c62c:
            puVar9 = *(undefined4 **)(this + 0x18);
LAB_0016c62e:
            LODManager::forceUpdate((LODManager *)*puVar9,param_1,false);
          }
          goto switchD_00161b94_caseD_1;
        }
        if (iVar37 == 3) {
          AEGeometry::updateReferenceMatrix(*(AEGeometry **)(*(int *)puVar6[1] + 8));
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          pPVar40 = (PlayerFixedObject *)**(undefined4 **)(iVar13 + 4);
          fVar56 = (float)(**(code **)(*(int *)pPVar40 + 0x48))
                                    (pPVar40,0x44fac000,0xc6f61800,0xc7a96000);
          AEGeometry::setRotation
                    (*(AEGeometry **)(pPVar40 + 8),fVar56,extraout_s1_x00113,extraout_s2_43);
          PlayerFixedObject::setExhaustVisible(pPVar40,false);
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          (**(code **)(*(int *)pPVar40 + 0x28))((Vector *)&local_98,pPVar40);
          fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_x00114,extraout_s2_44)
          ;
          TargetFollowCamera::useTargetsUpVector(*(TargetFollowCamera **)(this + 0x14),false);
          uVar47 = *puVar6;
          if (1 < uVar47) {
            uVar46 = 1;
            do {
              iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
              if ((iVar13 != 0) && (*(int *)(iVar13 + 0x24) == 9)) {
                Player::setEnemy(*(Player **)(iVar13 + 4),*(Player **)this_00);
                uVar47 = *puVar6;
              }
              uVar46 = uVar46 + 1;
            } while (uVar46 < uVar47);
          }
          *(undefined4 *)(this + 0x90) = 0;
          *(undefined4 *)(this + 0x94) = 0;
          *(undefined4 *)(this + 0x1c) = 4;
          goto switchD_00161b94_caseD_1;
        }
        if (iVar37 != 2) goto switchD_00161b94_caseD_1;
        AEGeometry::updateReferenceMatrix(*(AEGeometry **)(*(int *)puVar6[1] + 8));
        iVar7 = Level::getEnemies(*(Level **)(this + 0x18));
        piVar28 = (int *)**(undefined4 **)(iVar7 + 4);
        uVar47 = VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
        local_90 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
        local_98 = (ulonglong)uVar47 << 0x20;
        (**(code **)(*piVar28 + 0x20))(piVar28,&local_98);
        fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        AEGeometry::rotate((AEGeometry *)piVar28[2],fVar56 * 3e-05,extraout_s1_79,3e-05);
        uVar47 = *(uint *)(this + 0x90) + param_1;
        iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
        *(uint *)(this + 0x90) = uVar47;
        *(int *)(this + 0x94) = iVar13;
        if (iVar13 < (int)(uint)(uVar47 < 0x3a99)) goto switchD_00161b94_caseD_1;
        goto LAB_00167f9c;
      }
      PlayerEgo::setTurretMode(this_00,false);
      resetCamera(this,*(Level **)(this + 0x18));
      PlayerEgo::setFreeLookMode(this_00,false);
      TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
      PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
      PlayerEgo::stopShooting(this_00,0);
      iVar13 = 1;
      this_00[0x24] = (PlayerEgo)0x1;
      *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
      *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
      this[0x11] = (LevelScript)0x1;
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
      PlayerEgo::setComputerControlled(this_00,true);
      Player::setVulnerable(*(Player **)this_00,false);
      do {
        (**(code **)(**(int **)(puVar6[1] + iVar13 * 4) + 0x18))();
        piVar28 = (int *)((undefined4 *)puVar6[1])[iVar13];
        pcVar51 = *(code **)(*piVar28 + 0x44);
        (**(code **)(**(int **)puVar6[1] + 0x28))(&local_98);
        (*pcVar51)(piVar28,&local_98);
        Player::setEnemy(*(Player **)(((int *)puVar6[1])[iVar13] + 4),
                         *(Player **)(*(int *)puVar6[1] + 4));
        piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
        piVar28[0xd] = 0;
        (**(code **)(*piVar28 + 0x5c))(piVar28,1);
        iVar13 = iVar13 + 1;
      } while (iVar13 != 4);
      pVVar48 = (Vector *)(this + 0x28);
      local_98 = 0x43fa0000c71c4000;
      local_90 = -30000.0;
      AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
      (**(code **)(**(int **)(puVar6[1] + 4) + 0x20))(*(int **)(puVar6[1] + 4),pVVar48);
      pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + 4) + 8);
      AbyssEngine::AEMath::operator-((AEMath *)&local_f0,pVVar48);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
      local_fc = 0.0;
      local_f8 = 1.0;
      local_f4 = 0.0;
      AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_fc);
      local_98 = 0xc3480000c7202800;
      local_90 = -31000.0;
      AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
      (**(code **)(**(int **)(puVar6[1] + 8) + 0x20))(*(int **)(puVar6[1] + 8),pVVar48);
      pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + 8) + 8);
      AbyssEngine::AEMath::operator-((AEMath *)&local_f0,pVVar48);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
      local_fc = 0.0;
      local_f8 = 1.0;
      local_f4 = 0.0;
      AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_fc);
      local_98 = 0x42c80000c7241000;
      local_90 = -32000.0;
      AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
      (**(code **)(**(int **)(puVar6[1] + 0xc) + 0x20))(*(int **)(puVar6[1] + 0xc),pVVar48);
      pAVar52 = *(AEGeometry **)(*(int *)(puVar6[1] + 0xc) + 8);
      AbyssEngine::AEMath::operator-((AEMath *)&local_f0,pVVar48);
      AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
      local_fc = 0.0;
      local_f8 = 1.0;
      local_f4 = 0.0;
      AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_fc);
      TargetFollowCamera::setTarget
                (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8));
      pTVar38 = *(TargetFollowCamera **)(this + 0x14);
      (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_98);
      fVar56 = (float)TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
      TargetFollowCamera::translate
                (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_75,extraout_s2_30);
      LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
      *(undefined4 *)(this + 0x1c) = 1;
    }
    else if (iVar7 == 0x2a) {
      fVar56 = extraout_s0_03;
      if (((puVar5 == (uint *)0x0) || (*(int *)(this + 0x1c) != 5)) ||
         (iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x1c)),
         fVar56 = extraout_s0_04, iVar7 != 1)) {
        iVar7 = *(int *)(this + 0x1c);
        if (iVar7 == 0) {
          iVar7 = Status::inAlienOrbit(Globals::status);
          if (iVar7 == 0) {
            iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
            PlayerWormHole::reset(*(PlayerWormHole **)(*(int *)(iVar13 + 4) + 0xc),true);
            *(undefined4 *)(this + 0x1c) = 1;
            goto switchD_00161b94_caseD_1;
          }
          iVar7 = *(int *)(this + 0x1c);
          fVar56 = extraout_s0_07;
        }
        if (iVar7 != 7) {
          if (iVar7 != 6) goto switchD_00161b94_caseD_1;
          PlayerEgo::getPosition();
          local_f0 = 0;
          local_e8 = 0.0;
          fVar56 = (float)FModSound::updateEvent3DAttributes
                                    (Globals::sound,0x99,(Vector *)&local_98,(Vector *)&local_f0,
                                     false);
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          fVar56 = (float)TargetFollowCamera::setRumblePercentage
                                    (*(TargetFollowCamera **)(this + 0x14),fVar56,0x3f000000);
          FModSound::setParamValue((int)Globals::sound,1,fVar56);
          iVar13 = PlayerEgo::isInWormhole(this_00);
          if (iVar13 != 1) goto switchD_00161b94_caseD_1;
          PlayerEgo::setTurretMode(this_00,false);
          resetCamera(this,*(Level **)(this + 0x18));
          PlayerEgo::setFreeLookMode(this_00,false);
          TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
          PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
          this[0x11] = (LevelScript)0x1;
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
          PlayerEgo::setComputerControlled(this_00,true);
          PlayerEgo::setVisible(this_00,false);
          Player::setVulnerable(*(Player **)this_00,false);
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          PlayerEgo::getPosition();
          TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_fc);
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
          TargetFollowCamera::setTarget(pTVar38,*(AEGeometry **)(**(int **)(iVar13 + 4) + 0x13c));
          PlayerEgo::getPosition();
          fVar56 = (float)AbyssEngine::AEMath::VectorNormalize
                                    ((AEMath *)&local_a4,(Vector *)&local_b0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_fc,fVar56,(Vector *)0x459c4000);
          fVar56 = (float)AbyssEngine::AEMath::Vector::operator=
                                    ((Vector *)(this + 0x28),(Vector *)&local_fc);
          TargetFollowCamera::translate
                    (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_50,extraout_s2_22);
          iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
          PlayerWormHole::freeMissionLock(*(PlayerWormHole **)(*(int *)(iVar13 + 4) + 0xc));
          iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
          fVar56 = (float)PlayerWormHole::reset
                                    (*(PlayerWormHole **)(*(int *)(iVar13 + 4) + 0xc),true);
          this[0xa8] = (LevelScript)0x1;
          FModSound::play(Globals::sound,0x9a,(Vector *)0x0,(Vector *)0x0,fVar56);
          iVar13 = 7;
          *(undefined4 *)pLVar23 = 0;
          *(undefined4 *)(this + 0x94) = 0;
          goto LAB_00164abe;
        }
        TargetFollowCamera::setRumblePercentage
                  (*(TargetFollowCamera **)(this + 0x14),fVar56,0x42c80000);
        fVar56 = (float)VectorSignedToFloat(param_1 * -0x12,(byte)(in_fpscr >> 0x16) & 3);
        TargetFollowCamera::translate
                  (*(TargetFollowCamera **)(this + 0x14),fVar56,extraout_s1_80,extraout_s2_34);
        if (this[0xa8] == (LevelScript)0x0) {
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23;
          *(uint *)pLVar23 = uVar47 + param_1;
          *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
          iVar13 = Layout::isFading(Globals::layout);
          if ((iVar13 != 1) || ((int)(uint)(*(uint *)pLVar23 < 0x2711) <= *(int *)(this + 0x94))) {
            uVar29 = Player::getHitpoints(*(Player **)this_00);
            *(undefined4 *)(Globals::status + 100) = uVar29;
            uVar29 = Player::getShieldHP(*(Player **)this_00);
            *(undefined4 *)(Globals::status + 0x5c) = uVar29;
            uVar29 = Player::getArmorHP(*(Player **)this_00);
            *(undefined4 *)(Globals::status + 0x60) = uVar29;
            uVar29 = Player::getGammaHP(*(Player **)this_00);
            *(undefined4 *)(Globals::status + 0x68) = uVar29;
            uVar29 = PlayerEgo::getCurrentSecondaryWeaponIndex(this_00);
            pSVar33 = Globals::status;
            *(undefined4 *)(Globals::status + 0xf4) = uVar29;
            pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,*(int *)(pSVar33 + 0x84));
            Status::setStation(pSVar33,pSVar32);
            pSVar33 = Globals::status;
            pSVar32 = (Station *)Status::getStation(Globals::status);
            Status::departStation(pSVar33,pSVar32);
            Level::programmedStation = (Station *)0x0;
            Globals::switch_to_target_setting = 1;
            Level::initStreamOutPosition = 1;
            Level::comingFromAlienWorld = 1;
            AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
            *(undefined2 *)(this + 0x12) = 0x101;
            goto switchD_001616e0_default;
          }
        }
        else {
          lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xac) + 0xc));
          AbyssEngine::Transform::Update(lVar68,bVar55);
          lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xb0) + 0xc));
          AbyssEngine::Transform::Update(lVar68,bVar55);
          lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                             (Globals::Canvas,*(uint *)(*(int *)(this + 0xb4) + 0xc));
          AbyssEngine::Transform::Update(lVar68,bVar55);
          pPVar3 = Globals::Canvas;
          uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          pMVar45 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
          AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_98,pMVar45);
          local_f0 = 0x3f80000000000000;
          local_e8 = 0.0;
          AEGeometry::setDirection
                    (*(AEGeometry **)(this + 0xb0),(Vector *)&local_98,(Vector *)&local_f0);
          local_f0 = 0x3f80000000000000;
          local_e8 = 0.0;
          fVar56 = (float)AEGeometry::setDirection
                                    (*(AEGeometry **)(this + 0xb4),(Vector *)&local_98,
                                     (Vector *)&local_f0);
          pVVar48 = *(Vector **)(this + 0xb0);
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_98,fVar56);
          AEGeometry::setPosition(pVVar48);
          iVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                            (Globals::Canvas,*(uint *)(*(int *)(this + 0xac) + 0xc));
          if ((int)(uint)(*(uint *)(iVar7 + 0x110) < 0xfa1) <= *(int *)(iVar7 + 0x114)) {
            iVar7 = Level::getLandmarks(*(Level **)(this + 0x18));
            PlayerStation::setVisible((PlayerStation *)**(undefined4 **)(iVar7 + 4),false);
          }
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(uint)(uVar47 < 0x3a99) <= iVar13) {
            this[0xa8] = (LevelScript)0x0;
            Layout::startFade(Globals::layout,true,0xff,4000);
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
          }
        }
      }
      else {
        uVar29 = 0;
        FModSound::play(Globals::sound,0x99,(Vector *)0x0,(Vector *)0x0,extraout_s0_04);
        *(undefined4 *)(this + 8) = 0;
        *(undefined4 *)(this + 0xc) = 0;
        pLVar43 = *(Level **)(this + 0x18);
        if (*(Objective **)(pLVar43 + 0x2c) != (Objective *)0x0) {
          pvVar16 = (void *)Objective::~Objective(*(Objective **)(pLVar43 + 0x2c));
          operator_delete(pvVar16);
          pLVar43 = *(Level **)(this + 0x18);
        }
        *(undefined4 *)(pLVar43 + 0x2c) = 0;
        if (*(Objective **)(pLVar43 + 0x28) != (Objective *)0x0) {
          pvVar16 = (void *)Objective::~Objective(*(Objective **)(pLVar43 + 0x28));
          operator_delete(pvVar16);
          pLVar43 = *(Level **)(this + 0x18);
        }
        *(undefined4 *)(pLVar43 + 0x28) = 0;
        iVar13 = Level::getLandmarks(pLVar43);
        piVar28 = *(int **)(*(int *)(iVar13 + 4) + 0xc);
        (**(code **)(*piVar28 + 0x48))(piVar28,0x46c35000,0x469c4000,0xc756d800,uVar29);
        iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
        PlayerWormHole::open(*(PlayerWormHole **)(*(int *)(iVar13 + 4) + 0xc));
        *(undefined4 *)(this + 0x1c) = 6;
        *(undefined4 *)(this + 0x90) = 0;
        *(undefined4 *)(this + 0x94) = 0;
      }
    }
    goto switchD_00161b94_caseD_1;
  }
  if (iVar7 < 0x50) {
    switch(iVar7) {
    case 0x40:
      iVar13 = *(int *)(this + 0x1c);
      if (iVar13 == 0) {
        iVar13 = RadioMessage::isTriggered(*(RadioMessage **)puVar5[1]);
        if (iVar13 == 0) {
          iVar13 = *(int *)(this + 0x1c);
          goto LAB_00167fa6;
        }
        this_00[0x24] = (PlayerEgo)0x1;
        PlayerEgo::setTurretMode(this_00,false);
        resetCamera(this,*(Level **)(this + 0x18));
        PlayerEgo::setFreeLookMode(this_00,false);
        TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
        PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
        PlayerEgo::stopShooting(this_00,0);
        this[0x11] = (LevelScript)0x1;
        *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
        *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
        PlayerEgo::setComputerControlled(this_00,true);
        TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
        TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x14),true);
        TargetFollowCamera::setTarget
                  (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(*(int *)puVar6[1] + 8));
        (**(code **)(**(int **)puVar6[1] + 0x28))((Vector *)&local_98);
        fVar56 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
        AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_98,(Vector *)&local_f0);
        local_90 = local_90 + 3000.0;
        local_98 = CONCAT44(local_98._4_4_ + 300.0,(float)local_98);
        TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_98);
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        *(undefined4 *)(this + 0x1c) = 1;
      }
      else {
        if (iVar13 == 2) {
          *(undefined1 *)(*(int *)puVar6[1] + 0x20) = 1;
LAB_00168060:
          iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x14));
          if (iVar13 == 1) {
            *(undefined1 *)(*(int *)puVar6[1] + 0x20) = 0;
            local_90 = 7.00649e-40;
            local_98 = 0x7a1200007a120;
            pRVar27 = operator_new(0x18);
            Route::Route(pRVar27,(int *)&local_98,3);
            if (1 < *puVar6) {
              uVar47 = 1;
              do {
                iVar13 = KIPlayer::isWingMan(*(KIPlayer **)(puVar6[1] + uVar47 * 4));
                if (iVar13 == 0) {
                  piVar28 = *(int **)(puVar6[1] + uVar47 * 4);
                  (**(code **)(*piVar28 + 0x1c))(piVar28,0x41840000);
                  Player::setEnemies(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4),(Array *)0x0
                                    );
                  pKVar44 = *(KIPlayer **)(puVar6[1] + uVar47 * 4);
                  pRVar30 = (Route *)Route::clone(pRVar27);
                  KIPlayer::setRoute(pKVar44,pRVar30);
                }
                uVar47 = uVar47 + 1;
              } while (uVar47 < *puVar6);
            }
            *(undefined4 *)(this + 0x1c) = 3;
            break;
          }
          iVar13 = *(int *)(this + 0x1c);
        }
        else {
LAB_00167fa6:
          if (iVar13 == 2) goto LAB_00168060;
          if (iVar13 == 1) {
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            dVar65 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            TargetFollowCamera::translate
                      (*(TargetFollowCamera **)(this + 0x14),(float)(dVar65 * 0.2),extraout_s1_89,
                       extraout_s2_39);
            iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 8));
            if (iVar13 == 1) {
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
              PlayerEgo::setComputerControlled(this_00,false);
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
              resetCamera(this,*(Level **)(this + 0x18));
              LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
              this[0x11] = (LevelScript)0x0;
              this_00[0x24] = (PlayerEgo)0x0;
              if (*puVar6 != 0) {
                uVar47 = 0;
                do {
                  KIPlayer::setRoute(*(KIPlayer **)(puVar6[1] + uVar47 * 4),(Route *)0x0);
                  uVar47 = uVar47 + 1;
                } while (uVar47 < *puVar6);
              }
              goto LAB_00168058;
            }
            break;
          }
        }
        if (((iVar13 == 3) &&
            (iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x18)), iVar13 == 1)) &&
           (1 < *puVar6)) {
          uVar47 = 1;
          do {
            KIPlayer::setDead(*(KIPlayer **)(puVar6[1] + uVar47 * 4));
            uVar47 = uVar47 + 1;
          } while (uVar47 < *puVar6);
        }
      }
      break;
    case 0x41:
    case 0x42:
    case 0x44:
    case 0x47:
    case 0x48:
      break;
    case 0x43:
      iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 4));
      bVar55 = iVar13 == 1;
      if (bVar55) {
        iVar13 = *(int *)(this + 0x1c);
      }
      if (bVar55 && iVar13 == 0) {
        *(undefined4 *)(this + 0x1c) = 1;
        (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x1c))(*(int **)(puVar6[1] + 0x28),0);
        KIPlayer::setEnemies(*(Array **)(puVar6[1] + 0x28));
        PlayerFighter::setExhaustVisible(*(PlayerFighter **)(puVar6[1] + 0x28),false);
      }
      else {
        iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0xc));
        if (iVar13 == 1 && *(int *)(this + 0x1c) == 1) {
          (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x1c))(*(int **)(puVar6[1] + 0x28),0x40400000)
          ;
          PlayerFighter::setExhaustVisible(*(PlayerFighter **)(puVar6[1] + 0x28),true);
          PlayerEgo::setTurretMode(this_00,false);
          resetCamera(this,*(Level **)(this + 0x18));
          PlayerEgo::setFreeLookMode(this_00,false);
          TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
          PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
          PlayerEgo::stopShooting(this_00,0);
          this[0x11] = (LevelScript)0x1;
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
          PlayerEgo::setComputerControlled(this_00,true);
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
          TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x14),true);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),
                     *(AEGeometry **)(*(int *)(puVar6[1] + 0x28) + 8));
          pTVar38 = *(TargetFollowCamera **)(this + 0x14);
          (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x28))((Vector *)&local_f0);
          local_fc = 6000.0;
          local_f8 = -200.0;
          local_f4 = 1000.0;
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
          TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_98);
          Player::setVulnerable(*(Player **)this_00,false);
          this_00[0x24] = (PlayerEgo)0x1;
          *(undefined4 *)(this + 0x1c) = 2;
        }
        else if (*(int *)(this + 0x1c) == 2) {
          iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x10));
          if (iVar13 == 1) {
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            Player::setVulnerable(*(Player **)this_00,true);
            this_00[0x24] = (PlayerEgo)0x0;
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            PlayerEgo::setComputerControlled(this_00,false);
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
            resetCamera(this,*(Level **)(this + 0x18));
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x48))
                      (*(int **)(puVar6[1] + 0x28),0x48f42400,0x48f42400,0x48f42400);
            KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + 0x28),0));
            KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 0x28),false);
            this[0x11] = (LevelScript)0x0;
LAB_0016eede:
            *(undefined4 *)(this + 0x1c) = 3;
          }
        }
        else {
          iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x14));
          bVar55 = iVar13 == 1;
          if (bVar55) {
            iVar13 = *(int *)(this + 0x1c);
          }
          if (bVar55 && iVar13 == 3) {
            (**(code **)(**(int **)puVar6[1] + 0x28))(&local_98);
            iVar13 = 5;
            do {
              piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
              pcVar51 = *(code **)(*piVar28 + 0x44);
              iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
              iVar37 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar50 = -1;
              if (iVar37 == 0) {
                iVar50 = 1;
              }
              iVar37 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
              iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
              fVar56 = (float)VectorSignedToFloat(iVar50 * (iVar7 + 15000),
                                                  (byte)(in_fpscr >> 0x16) & 3);
              iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar50 = -1;
              if (iVar7 == 0) {
                iVar50 = 1;
              }
              local_f8 = (float)VectorSignedToFloat(iVar37 + -5000,(byte)(in_fpscr >> 0x16) & 3);
              local_f4 = (float)VectorSignedToFloat((iVar18 + 15000) * iVar50,
                                                    (byte)(in_fpscr >> 0x16) & 3);
              local_fc = fVar56;
              AbyssEngine::AEMath::operator+
                        ((AEMath *)&local_f0,(Vector *)&local_98,(Vector *)&local_fc);
              (*pcVar51)(piVar28,(AEMath *)&local_f0);
              iVar13 = iVar13 + 1;
            } while (iVar13 != 9);
            goto LAB_0016d234;
          }
          iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x1c));
          bVar55 = iVar13 == 1;
          if (bVar55) {
            iVar13 = *(int *)(this + 0x1c);
          }
          if (bVar55 && iVar13 == 4) {
            (**(code **)(**(int **)puVar6[1] + 0x28))(&local_98);
            (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x48))
                      (*(int **)(puVar6[1] + 0x28),(float)local_98,local_98._4_4_,local_90 + 12000.0
                      );
            local_f0 = 0;
            local_e8 = 1.0;
            local_fc = 0.0;
            local_f8 = 1.0;
            local_f4 = 0.0;
            AEGeometry::setDirection
                      (*(AEGeometry **)(*(int *)(puVar6[1] + 0x28) + 8),(Vector *)&local_f0,
                       (Vector *)&local_fc);
            KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + 0x28),0));
            KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 0x28),true);
            (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x1c))
                      (*(int **)(puVar6[1] + 0x28),0x40000000);
            iVar13 = *(int *)(this + 0x18);
            if (*(Objective **)(iVar13 + 0x2c) != (Objective *)0x0) {
              pvVar16 = (void *)Objective::~Objective(*(Objective **)(iVar13 + 0x2c));
              operator_delete(pvVar16);
              iVar13 = *(int *)(this + 0x18);
            }
            *(undefined4 *)(iVar13 + 0x2c) = 0;
            local_e8 = 1.121039e-39;
            local_f0 = 0;
            pRVar27 = operator_new(0x18);
            Route::Route(pRVar27,(int *)&local_f0,3);
            KIPlayer::setRoute(*(KIPlayer **)(puVar6[1] + 0x28),pRVar27);
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            PlayerEgo::setComputerControlled(this_00,true);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),
                       *(AEGeometry **)(*(int *)(puVar6[1] + 0x28) + 8));
            pTVar38 = *(TargetFollowCamera **)(this + 0x14);
            (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x28))((Vector *)&local_a4);
            local_b0 = 0x45bb8000;
            local_ac = -0x3cb80000;
            local_a8 = 0x461c4000;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_fc,(Vector *)&local_a4,(Vector *)&local_b0);
            TargetFollowCamera::setPosition(pTVar38,(Vector *)&local_fc);
            Player::setVulnerable(*(Player **)this_00,false);
            this_00[0x24] = (PlayerEgo)0x1;
            LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
            *(undefined4 *)(this + 0x1c) = 5;
          }
          else {
            iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x24));
            bVar55 = iVar13 == 1;
            if (bVar55) {
              iVar13 = *(int *)(this + 0x1c);
            }
            if (bVar55 && iVar13 == 5) {
              Player::setVulnerable(*(Player **)this_00,true);
              this_00[0x24] = (PlayerEgo)0x0;
              (**(code **)(**(int **)(puVar6[1] + 0x28) + 0x1c))
                        (*(int **)(puVar6[1] + 0x28),0x41000000);
              TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
              TargetFollowCamera::setTarget
                        (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
              PlayerEgo::setComputerControlled(this_00,false);
              *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
              *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
              resetCamera(this,*(Level **)(this + 0x18));
              LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
              this[0x11] = (LevelScript)0x0;
              *(undefined4 *)(this + 0x1c) = 6;
            }
            else {
              iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x2c));
              if ((iVar13 == 1) && (*(int *)(this + 0x1c) == 6)) {
                KIPlayer::setActive(SUB41(*(undefined4 *)(puVar6[1] + 0x28),0));
                KIPlayer::setVisible(*(KIPlayer **)(puVar6[1] + 0x28),false);
                goto LAB_001692f2;
              }
            }
          }
        }
      }
      break;
    case 0x45:
      iVar13 = RadioMessage::isTriggered(*(RadioMessage **)puVar5[1]);
      if (iVar13 == 1 && *(int *)(this + 0x1c) == 0) {
        PlayerEgo::setTurretMode(this_00,false);
        resetCamera(this,*(Level **)(this + 0x18));
        PlayerEgo::setFreeLookMode(this_00,false);
        TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
        PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
        PlayerEgo::stopShooting(this_00,0);
        this[0x11] = (LevelScript)0x1;
        *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
        *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
        PlayerEgo::setComputerControlled(this_00,true);
        TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
        TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x14),true);
        pTVar38 = *(TargetFollowCamera **)(this + 0x14);
        iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
        TargetFollowCamera::setTarget(pTVar38,*(AEGeometry **)(**(int **)(iVar13 + 4) + 8));
        iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
        (**(code **)(*(int *)**(undefined4 **)(iVar13 + 4) + 0x28))((Vector *)&local_98);
        Level::getEnemies(*(Level **)(this + 0x18));
        fVar56 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
        AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_98,(Vector *)&local_f0);
        local_98 = CONCAT44(local_98._4_4_ + 300.0,(float)local_98 + 600.0);
        local_90 = local_90 + 1000.0;
        TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_98);
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        *(undefined4 *)(this + 0x1c) = 1;
      }
      else if (*(int *)(this + 0x1c) == 1) {
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 4));
        if (iVar13 == 1) {
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
          PlayerEgo::setComputerControlled(this_00,false);
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
          resetCamera(this,*(Level **)(this + 0x18));
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          *(undefined4 *)(this + 0x1c) = 2;
          this[0x11] = (LevelScript)0x0;
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          KIPlayer::setActive(SUB41(**(undefined4 **)(iVar13 + 4),0));
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          KIPlayer::setToSleep((KIPlayer *)**(undefined4 **)(iVar13 + 4));
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          (**(code **)(*(int *)**(undefined4 **)(iVar13 + 4) + 0x48))
                    ((int *)**(undefined4 **)(iVar13 + 4),0,0,0xca989680);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          KIPlayer::setVisible((KIPlayer *)**(undefined4 **)(iVar13 + 4),false);
        }
      }
      break;
    case 0x46:
      iVar13 = RadioMessage::isTriggered(*(RadioMessage **)puVar5[1]);
      iVar7 = *(int *)(this + 0x1c);
      if (iVar13 == 1 && iVar7 == 0) {
        PlayerEgo::setTurretMode(this_00,false);
        resetCamera(this,*(Level **)(this + 0x18));
        PlayerEgo::setFreeLookMode(this_00,false);
        TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
        PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
        PlayerEgo::stopShooting(this_00,0);
        this[0x11] = (LevelScript)0x1;
        *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
        *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
        PlayerEgo::setComputerControlled(this_00,true);
        TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
        TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x14),true);
        pTVar38 = *(TargetFollowCamera **)(this + 0x14);
        iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
        TargetFollowCamera::setTarget(pTVar38,*(AEGeometry **)(**(int **)(iVar13 + 4) + 8));
        iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
        (**(code **)(*(int *)**(undefined4 **)(iVar13 + 4) + 0x28))((Vector *)&local_98);
        Level::getEnemies(*(Level **)(this + 0x18));
        fVar56 = (float)AEGeometry::getDirection();
        AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
        AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_98,(Vector *)&local_f0);
        local_98 = CONCAT44(local_98._4_4_ + -300.0,(float)local_98 + -600.0);
        local_90 = local_90 + -1000.0;
        TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_98);
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        this_00[0x24] = (PlayerEgo)0x1;
        *(undefined4 *)(this + 0x1c) = 1;
      }
      else if (iVar7 == 2) {
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 8));
        if (iVar13 == 1) {
          TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
          TargetFollowCamera::setTarget
                    (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
          PlayerEgo::setComputerControlled(this_00,false);
          *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
          *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
          resetCamera(this,*(Level **)(this + 0x18));
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          *(undefined4 *)(this + 0x1c) = 3;
          this[0x11] = (LevelScript)0x0;
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          pPVar41 = *(Player **)(**(int **)(iVar13 + 4) + 4);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          iVar13 = Player::getMaxHitpoints(*(Player **)(**(int **)(iVar13 + 4) + 4));
          Player::setMaxHitpoints(pPVar41,iVar13 * 3);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          (**(code **)(*(int *)**(undefined4 **)(iVar13 + 4) + 0x1c))
                    ((int *)**(undefined4 **)(iVar13 + 4),0x41200000);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          PlayerFighter::setRotate((PlayerFighter *)**(undefined4 **)(iVar13 + 4),5);
        }
      }
      else if (iVar7 == 1) {
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        iVar13 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 4));
        if (iVar13 == 1) {
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          Player::setAlwaysFriend(*(Player **)(**(int **)(iVar13 + 4) + 4),false);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          Player::setAlwaysEnemy(*(Player **)(**(int **)(iVar13 + 4) + 4),true);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          *(undefined4 *)(**(int **)(iVar13 + 4) + 0x124) = 100000;
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          *(undefined4 *)(**(int **)(iVar13 + 4) + 0x34) = 0;
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          *(undefined1 *)(**(int **)(iVar13 + 4) + 0x129) = 0;
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          *(undefined1 *)(**(int **)(iVar13 + 4) + 0x128) = 0;
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          KIPlayer::setRoute((KIPlayer *)**(undefined4 **)(iVar13 + 4),(Route *)0x0);
          iVar13 = Level::getEnemies(*(Level **)(this + 0x18));
          (**(code **)(*(int *)**(undefined4 **)(iVar13 + 4) + 0x28))((Vector *)&local_98);
          Level::getEnemies(*(Level **)(this + 0x18));
          fVar56 = (float)AEGeometry::getDirection();
          AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_fc,fVar56);
          AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_98,(Vector *)&local_f0);
          local_98 = CONCAT44(local_98._4_4_ + 800.0,(float)local_98 + -600.0);
          local_90 = local_90 + -1000.0;
          TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_98)
          ;
          LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
          *(undefined4 *)(this + 0x1c) = 2;
          this_00[0x24] = (PlayerEgo)0x0;
        }
      }
      break;
    case 0x49:
      switch(*(undefined4 *)(this + 0x1c)) {
      case 0:
        PlayerEgo::getPosition();
        (**(code **)(**(int **)(puVar6[1] + 0x20) + 0x28))((Vector *)&local_fc);
        AbyssEngine::AEMath::operator-((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
        fVar56 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_98);
        if ((int)fVar56 < 50000) {
          uVar29 = 1;
          goto LAB_0016c2dc;
        }
        break;
      case 1:
        uVar47 = *puVar6;
        if (8 < uVar47) {
          uVar46 = 8;
          do {
            iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
            if (*(char *)(iVar13 + 0x3c) != '\0') {
              iVar13 = Player::getEmpPoints(*(Player **)(iVar13 + 4));
              iVar7 = Player::getMaxEmpPoints(*(Player **)(*(int *)(puVar6[1] + uVar46 * 4) + 4));
              if (iVar13 < iVar7) goto LAB_0016c2da;
              uVar47 = *puVar6;
            }
            uVar46 = uVar46 + 1;
          } while (uVar46 < uVar47);
        }
        break;
      case 2:
        uVar47 = *puVar6;
        if (8 < uVar47) {
          uVar46 = 8;
          do {
            iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
            if ((*(char *)(iVar13 + 0x3c) != '\0') &&
               (*(char *)(*(int *)(iVar13 + 4) + 0x68) != '\0')) {
              uVar46 = 8;
              goto LAB_0016d46e;
            }
            uVar46 = uVar46 + 1;
          } while (uVar46 < uVar47);
        }
        break;
      case 3:
        iVar13 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0x1c));
        if (iVar13 == 1) {
          PlayerEgo::getPosition();
          iVar13 = 4;
          do {
            piVar28 = *(int **)(puVar6[1] + iVar13 * 4);
            pcVar51 = *(code **)(*piVar28 + 0x44);
            iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
            iVar37 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar50 = -1;
            if (iVar37 == 0) {
              iVar50 = 1;
            }
            iVar37 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
            iVar18 = AbyssEngine::AERandom::nextInt(Globals::rnd,10000);
            fVar56 = (float)VectorSignedToFloat(iVar50 * (iVar7 + 35000),
                                                (byte)(in_fpscr >> 0x16) & 3);
            iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar50 = -1;
            if (iVar7 == 0) {
              iVar50 = 1;
            }
            local_f8 = (float)VectorSignedToFloat(iVar37 + -5000,(byte)(in_fpscr >> 0x16) & 3);
            local_f4 = (float)VectorSignedToFloat((iVar18 + 35000) * iVar50,
                                                  (byte)(in_fpscr >> 0x16) & 3);
            local_fc = fVar56;
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_f0,(Vector *)&local_98,(Vector *)&local_fc);
            (*pcVar51)(piVar28,(AEMath *)&local_f0);
            (**(code **)(**(int **)(puVar6[1] + iVar13 * 4) + 0xc))();
            iVar13 = iVar13 + 1;
          } while (iVar13 != 8);
LAB_0016d234:
          iVar13 = 4;
LAB_0016d238:
          *(int *)(this + 0x1c) = iVar13;
        }
      }
      break;
    default:
      if (iVar7 == 0x38) {
        if (*(int *)(this + 0x1c) == 1) {
          uVar47 = Player::getArmorHP(*(Player **)this_00);
          if ((int)uVar47 < 1) {
            if (puVar6 != (uint *)0x0) {
              uVar47 = *puVar6;
            }
            if (puVar6 != (uint *)0x0 && uVar47 != 0) {
              uVar47 = 0;
              do {
                iVar13 = Player::isAlwaysFriend(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4));
                if (iVar13 == 1) {
                  Player::setShootingEnabled
                            (*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4),true);
                }
                uVar47 = uVar47 + 1;
              } while (uVar47 < *puVar6);
            }
LAB_00168058:
            *(undefined4 *)(this + 0x1c) = 2;
          }
        }
        else if (*(int *)(this + 0x1c) == 0) {
          uVar47 = 0;
          if (puVar6 != (uint *)0x0) {
            uVar47 = *puVar6;
          }
          if (puVar6 != (uint *)0x0 && uVar47 != 0) {
            uVar47 = 0;
            do {
              iVar13 = Player::isAlwaysFriend(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4));
              if (iVar13 == 1) {
                Player::setShootingEnabled(*(Player **)(*(int *)(puVar6[1] + uVar47 * 4) + 4),false)
                ;
              }
              uVar47 = uVar47 + 1;
            } while (uVar47 < *puVar6);
          }
          goto LAB_00167470;
        }
      }
    }
    goto switchD_00161b94_caseD_1;
  }
  if (iVar7 != 0x50) {
    if (iVar7 != 0x5b) goto switchD_00161b94_caseD_1;
    iVar7 = *(int *)(this + 0x1c);
    if (iVar7 == 0) {
      iVar7 = RadioMessage::isTriggered(*(RadioMessage **)(puVar5[1] + 0xc));
      if (iVar7 != 1) {
        iVar7 = *(int *)(this + 0x1c);
        goto LAB_0016747a;
      }
      *(undefined4 *)(this + 0x98) = 0;
      *(undefined4 *)(this + 0x9c) = 0;
      *(undefined4 *)(this + 0x1c) = 1;
      KIPlayer::setActive(SUB41(*(undefined4 *)puVar6[1],0));
      pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(*(Level **)(this + 0x18),0);
      pSVar14 = (String *)GameText::getText(Globals::gameText,0xc8b);
      AbyssEngine::String::String(aSStack_194,pSVar14,false);
      PlayerFixedObject::setName(pPVar40,aSStack_194);
      AbyssEngine::String::~String(aSStack_194);
    }
    else {
LAB_0016747a:
      if (iVar7 == 1) {
        iVar7 = PlayerEgo::isDockedToDockingPoint(this_00);
        if (iVar7 == 0) {
          iVar7 = *(int *)(this + 0x1c);
          goto LAB_00167490;
        }
        uVar29 = 2;
LAB_001674c8:
        *(undefined4 *)(this + 0x1c) = uVar29;
      }
      else {
LAB_00167490:
        if (iVar7 == 2) {
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x14));
          if (iVar7 == 1) {
            pPVar40 = (PlayerFixedObject *)Level::getDockingTarget(*(Level **)(this + 0x18),0);
            PlayerFixedObject::setDockingType(pPVar40,2);
            iVar13 = PlayerEgo::isDockedToDockingPoint(this_00);
            if (iVar13 == 1) {
              PlayerEgo::setDockingState(this_00,2);
            }
            uVar29 = 3;
            goto LAB_001674c8;
          }
          iVar7 = *(int *)(this + 0x1c);
        }
        if (iVar7 == 4) {
          iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x18));
          if (iVar7 == 1) {
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            iVar7 = PlayerEgo::isDockedToDockingPoint(pPVar10);
            if (iVar7 == 0) {
              *(undefined4 *)(this + 0x90) = 0;
              *(undefined4 *)(this + 0x94) = 0;
              uVar29 = 5;
              goto LAB_001674c8;
            }
          }
          iVar7 = *(int *)(this + 0x1c);
        }
        else if (iVar7 == 3) {
          if (9 < *(int *)(Globals::status + 0x174)) {
            *(undefined4 *)(this + 0x1c) = 4;
            iVar13 = *(int *)(this + 0x18);
            if (*(Objective **)(iVar13 + 0x2c) != (Objective *)0x0) {
              pvVar16 = (void *)Objective::~Objective(*(Objective **)(iVar13 + 0x2c));
              operator_delete(pvVar16);
              iVar13 = *(int *)(this + 0x18);
            }
            *(undefined4 *)(iVar13 + 0x2c) = 0;
          }
          goto LAB_001674ca;
        }
        if (iVar7 == 6) {
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(uint)(uVar47 < 0x7d1) <= iVar13) {
            fVar56 = (float)PlayerEgo::getSpeed(this_00);
            if ((int)((uint)(fVar56 < 100.0) << 0x1f) < 0) {
              fVar56 = (float)PlayerEgo::getSpeed(this_00);
              PlayerEgo::setSpeed(this_00,fVar56 * 1.05);
            }
            if ((int)(uint)(*(uint *)pLVar23 < 0x1f41) <= *(int *)(this + 0x94)) {
              Status::nextCampaignMission(SUB41(Globals::status,0));
              pSVar33 = Globals::status;
              pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,0x71);
              Status::setStation(pSVar33,pSVar32);
              pSVar33 = Globals::status;
              pSVar32 = (Station *)Galaxy::getStation(Globals::galaxy,0x71);
              Status::departStation(pSVar33,pSVar32);
              Level::initStreamOutPosition = 1;
              uVar29 = Player::getHitpoints(*(Player **)this_00);
              *(undefined4 *)(Globals::status + 100) = uVar29;
              uVar29 = Player::getShieldHP(*(Player **)this_00);
              *(undefined4 *)(Globals::status + 0x5c) = uVar29;
              uVar29 = Player::getArmorHP(*(Player **)this_00);
              *(undefined4 *)(Globals::status + 0x60) = uVar29;
              uVar29 = Player::getGammaHP(*(Player **)this_00);
              *(undefined4 *)(Globals::status + 0x68) = uVar29;
              AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
            }
          }
        }
        else if (iVar7 == 5) {
          pLVar23 = this + 0x90;
          uVar47 = *(uint *)pLVar23 + param_1;
          iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
          *(uint *)pLVar23 = uVar47;
          *(int *)(this + 0x94) = iVar13;
          if ((int)(uint)(uVar47 < 0xbb9) <= iVar13) {
            *(undefined4 *)pLVar23 = 0;
            *(undefined4 *)(this + 0x94) = 0;
            pPVar10 = (PlayerEgo *)Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::setAutoPilot(pPVar10,(KIPlayer *)0x0);
            iVar13 = *(int *)(this + 0xd4);
            *(undefined4 *)(iVar13 + 4) = 0;
            *(undefined4 *)(iVar13 + 8) = 0;
            iVar13 = PlayerEgo::isInRocketControl(this_00);
            if (iVar13 != 0) {
              resetCamera(this,*(Level **)(this + 0x18));
              PlayerEgo::setRocketControl(this_00,(Gun *)0x0,(AEGeometry *)0x0);
              fVar56 = (float)PlayerEgo::killLiberator(this_00);
              TargetFollowCamera::setRumblePercentage
                        (*(TargetFollowCamera **)(this + 0x14),fVar56,0);
            }
            PlayerEgo::setTurretMode(this_00,false);
            resetCamera(this,*(Level **)(this + 0x18));
            PlayerEgo::setFreeLookMode(this_00,false);
            TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
            PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
            PlayerEgo::stopShooting(this_00,0);
            this[0x11] = (LevelScript)0x1;
            *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
            *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
            PlayerEgo::setComputerControlled(this_00,true);
            PlayerEgo::setCollide(this_00,false);
            TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
            TargetFollowCamera::setTarget
                      (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
            AEGeometry::getPosition();
            pVVar49 = (Vector *)(this + 0x28);
            AbyssEngine::AEMath::Vector::operator=(pVVar49,(Vector *)&local_98);
            pAVar52 = *(AEGeometry **)(this_00 + 8);
            Level::getPlayer(*(Level **)(this + 0x18));
            PlayerEgo::getPosition();
            Level::getDockingTarget(*(Level **)(this + 0x18),0);
            AEGeometry::getPosition();
            AbyssEngine::AEMath::operator-
                      ((AEMath *)&local_f0,(Vector *)&local_fc,(Vector *)&local_a4);
            AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_98,(Vector *)&local_f0);
            local_b0 = 0;
            local_ac = 0x3f800000;
            local_a8 = 0;
            AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_b0);
            AEGeometry::getDirection();
            pVVar48 = (Vector *)(this + 0x40);
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            AEGeometry::getRightVector();
            fVar56 = (float)AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
            AbyssEngine::AEMath::operator*((AEMath *)&local_98,pVVar48,fVar56);
            AbyssEngine::AEMath::Vector::operator+=(pVVar49,(Vector *)&local_98);
            TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar49);
            Player::setHitpoints(*(Player **)(*(int *)puVar6[1] + 4),0);
            *(undefined4 *)(this + 0x1c) = 6;
          }
        }
      }
    }
LAB_001674ca:
    AEGeometry::getPosition();
    local_f0 = 0;
    local_e8 = 0.0;
    fVar56 = (float)FModSound::updateEvent3DAttributes
                              (Globals::sound,0x8e9,(Vector *)&local_98,(Vector *)&local_f0,false);
    if (*(int *)(Globals::status + 0x174) < 8) {
      piVar28 = (int *)puVar6[1];
LAB_00167578:
      uVar47 = *(uint *)(*(int *)(*piVar28 + 8) + 0x14);
    }
    else {
      iVar13 = *(int *)(this + 0xc);
      if ((int)(-(uint)("N11AbyssEngine11PaintCanvas11DrawImage2DEjiih" < *(char **)(this + 8)) -
               iVar13) < 0 !=
          (SBORROW4(0,iVar13) !=
          SBORROW4(-iVar13,(uint)("N11AbyssEngine11PaintCanvas11DrawImage2DEjiih" <
                                 *(char **)(this + 8))))) {
        piVar28 = (int *)puVar6[1];
        goto LAB_00167578;
      }
      if (*(int *)(this + 0x98) == 0 && *(int *)(this + 0x9c) == 0) {
        FModSound::play(Globals::sound,0x8ea,(Vector *)0x0,(Vector *)0x0,fVar56);
        *(undefined4 *)(this + 0x98) = 1;
        *(undefined4 *)(this + 0x9c) = 0;
      }
      uVar47 = *(uint *)(*(int *)(*(int *)puVar6[1] + 8) + 0xc);
    }
    uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar47);
    AbyssEngine::Transform::Update(CONCAT44(1,uVar29),bVar55);
    goto switchD_00161b94_caseD_1;
  }
  iVar7 = *(int *)(this + 0x1c);
  fVar56 = extraout_s1_17;
  if (iVar7 == 0) {
    iVar7 = RadioMessage::isOver(*(RadioMessage **)puVar5[1]);
    if (iVar7 != 1) {
      iVar7 = *(int *)(this + 0x1c);
      fVar56 = extraout_s1_37;
      goto LAB_00167770;
    }
    PlayerEgo::setTurretMode(this_00,false);
    resetCamera(this,*(Level **)(this + 0x18));
    PlayerEgo::setFreeLookMode(this_00,false);
    TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
    PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
    PlayerEgo::stopShooting(this_00,0);
    this[0x11] = (LevelScript)0x1;
    *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
    *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
    PlayerEgo::setComputerControlled(this_00,true);
    this_00[0x24] = (PlayerEgo)0x1;
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
    TargetFollowCamera::setTarget
              (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xbc));
    AEGeometry::getPosition();
    pVVar48 = (Vector *)(this + 0x28);
    AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
    local_98 = 0x459c4000c69c4000;
    local_90 = -35000.0;
    AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
    fVar56 = (float)TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
    *(undefined4 *)(this + 0x90) = 0;
    *(undefined4 *)(this + 0x94) = 0;
    *(undefined4 *)(this + 0x1c) = 1;
    FModSound::play(Globals::sound,0x461,(Vector *)0x0,(Vector *)0x0,fVar56);
    fVar56 = extraout_s1_38;
    goto LAB_0016d740;
  }
LAB_00167770:
  switch(iVar7) {
  case 1:
    fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar60 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(param_1 * -0xc,(byte)(in_fpscr >> 0x16) & 3);
    TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar57,fVar56,fVar60);
    pLVar23 = this + 0x90;
    uVar47 = *(uint *)pLVar23 + param_1;
    iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
    *(uint *)pLVar23 = uVar47;
    *(int *)(this + 0x94) = iVar13;
    fVar56 = extraout_s1_81;
    if (iVar13 < (int)(uint)(uVar47 < 0xbb9)) break;
    *(undefined4 *)pLVar23 = 0;
    *(undefined4 *)(this + 0x94) = 0;
    uVar29 = 2;
    goto LAB_0016d73c;
  case 2:
    fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar60 = (float)VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(param_1 * -0xc,(byte)(in_fpscr >> 0x16) & 3);
    pLVar23 = this + 0x90;
    uVar47 = *(uint *)pLVar23;
    *(uint *)pLVar23 = uVar47 + param_1;
    *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
    TargetFollowCamera::translate(*(TargetFollowCamera **)(this + 0x14),fVar57,fVar56,fVar60);
    uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(this + 0xbc) + 0xc));
    AbyssEngine::Transform::Update(CONCAT44(1,uVar29),bVar55);
    fVar56 = extraout_s1_92;
    if ((int)(uint)(*(uint *)pLVar23 < 0x7d1) <= *(int *)(this + 0x94)) {
      *(undefined4 *)pLVar23 = 0;
      *(undefined4 *)(this + 0x94) = 0;
      *(undefined4 *)(this + 0x1c) = 6;
      AEGeometry::setVisible(*(AEGeometry **)(this + 0xbc),false);
      fVar56 = extraout_s1_93;
    }
    break;
  default:
    goto switchD_00167778_caseD_2;
  case 6:
    local_98 = 0xc632ec0046431c00;
    local_90 = 5958.0;
    AEGeometry::setPosition(*(Vector **)(this + 0xdc));
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
    fVar56 = (float)TargetFollowCamera::setTarget
                              (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xdc));
    local_f0 = 0xc6eaf600c6e16e00;
    local_e8 = 63820.0;
    AbyssEngine::AEMath::operator/((AEMath *)&local_98,(Vector *)&local_f0,fVar56);
    pVVar48 = (Vector *)(this + 0x28);
    AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
    TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
    AEGeometry::getPosition();
    AbyssEngine::AEMath::operator-((AEMath *)&local_98,(Vector *)&local_f0,pVVar48);
    pAVar52 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar52,Globals::Canvas);
    local_f0 = 0x3f80000000000000;
    local_e8 = 0.0;
    AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
    AEGeometry::setPosition((Vector *)pAVar52);
    pPVar3 = Globals::Canvas;
    uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar45 = (Matrix *)AEGeometry::getMatrix(pAVar52);
    AbyssEngine::PaintCanvas::CameraSetLocal(pPVar3,uVar47,pMVar45);
    pvVar16 = (void *)AEGeometry::~AEGeometry(pAVar52);
    operator_delete(pvVar16);
    LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
    AEGeometry::setVisible(*(AEGeometry **)(this + 0xb8),true);
    *(undefined4 *)(this + 0x1c) = 7;
    *(undefined4 *)(this + 0x90) = 0;
    *(undefined4 *)(this + 0x94) = 0;
    fVar56 = extraout_s1_94;
    break;
  case 7:
    pLVar23 = this + 0x90;
    uVar47 = *(uint *)pLVar23 + param_1;
    iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
    *(uint *)pLVar23 = uVar47;
    *(int *)(this + 0x94) = iVar13;
    if ((int)(uint)(uVar47 < 0x321) <= iVar13) {
      *(undefined4 *)pLVar23 = 0;
      *(undefined4 *)(this + 0x94) = 0;
      uVar29 = 8;
      goto LAB_0016d73c;
    }
    break;
  case 8:
    pLVar23 = this + 0x90;
    uVar47 = *(uint *)pLVar23 + param_1;
    iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)pLVar23,param_1);
    *(uint *)pLVar23 = uVar47;
    *(int *)(this + 0x94) = iVar13;
    if ((int)(uint)(uVar47 < 0x321) <= iVar13) {
      pEVar42 = *(Explosion **)(this + 200);
      AEGeometry::getPosition();
      local_f0 = 0;
      local_e8 = 0.0;
      fVar56 = (float)Explosion::start(pEVar42,(Vector *)&local_98,(Vector *)&local_f0);
      FModSound::play(Globals::sound,0x12,(Vector *)0x0,(Vector *)0x0,fVar56);
      pMVar45 = *(Matrix **)(*(int *)(this + 0x18) + 0x58);
      iVar13 = *(int *)(*(int *)(this + 0x18) + 0x74);
      AEGeometry::getMatrix(*(AEGeometry **)(this + 0xdc));
      ParticleSystemManager::systemSetMatrix(iVar13,pMVar45);
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x74),
                 *(int *)(*(int *)(this + 0x18) + 0x58),true);
      AEGeometry::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_98);
      *(float *)(this + 0x28) = *(float *)(this + 0x28) + 4500.0;
      fVar56 = *(float *)(this + 0x30);
      *(float *)(this + 0x30) = fVar56 + 1000.0;
      AbyssEngine::AEMath::MatrixSetTranslation
                ((AEMath *)&local_98,this + 0x4c,fVar56 + 1000.0,extraout_s1_95,1000.0);
      ParticleSystemManager::systemSetMatrix
                (*(int *)(*(int *)(this + 0x18) + 0x74),*(Matrix **)(*(int *)(this + 0x18) + 0x5c));
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(*(int *)(this + 0x18) + 0x74),
                 *(int *)(*(int *)(this + 0x18) + 0x5c),true);
      *(undefined4 *)pLVar23 = 0;
      *(undefined4 *)(this + 0x94) = 0;
      uVar29 = 9;
      fVar56 = extraout_s1_96;
      goto LAB_0016d73c;
    }
    break;
  case 9:
    Explosion::update(*(Explosion **)(this + 200),param_1,(TargetFollowCamera *)0x0);
    fVar56 = (float)VectorSignedToFloat(param_1 << 1,(byte)(in_fpscr >> 0x16) & 3);
    fVar57 = *(float *)(this + 0x28);
    *(float *)(this + 0x28) = fVar56 + fVar57;
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_98,this + 0x4c,*(float *)(this + 0x30),extraout_s1_97,fVar57);
    uVar47 = *(uint *)(this + 0x90) + param_1;
    iVar13 = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(*(uint *)(this + 0x90),param_1);
    *(uint *)(this + 0x90) = uVar47;
    *(int *)(this + 0x94) = iVar13;
    fVar56 = extraout_s1_98;
    if ((int)(uint)(uVar47 < 0x1f41) <= iVar13) {
      iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
      iVar13 = *(int *)(**(int **)(iVar13 + 4) + 0x13c);
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0xc));
      uVar69 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0xc));
      AbyssEngine::Transform::Update
                (CONCAT44((int)((ulonglong)uVar69 >> 0x20),uVar29),
                 SUB41(*(undefined4 *)((int)uVar69 + 0xf8),0));
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0x14));
      uVar69 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0x14));
      AbyssEngine::Transform::Update
                (CONCAT44((int)((ulonglong)uVar69 >> 0x20),uVar29),
                 SUB41(*(undefined4 *)((int)uVar69 + 0xf8),0));
      uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0x10));
      uVar69 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0x10));
      AbyssEngine::Transform::Update
                (CONCAT44((int)((ulonglong)uVar69 >> 0x20),uVar29),
                 SUB41(*(undefined4 *)((int)uVar69 + 0xf8),0));
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
      TargetFollowCamera::setTarget
                (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
      PlayerEgo::setComputerControlled(this_00,false);
      this_00[0x24] = (PlayerEgo)0x0;
      *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
      *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
      resetCamera(this,*(Level **)(this + 0x18));
      LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
      AEGeometry::setVisible(*(AEGeometry **)(this + 0xb8),false);
      this[0x11] = (LevelScript)0x0;
      uVar29 = 10;
      fVar56 = extraout_s1_99;
      goto LAB_0016d73c;
    }
    break;
  case 10:
    iVar7 = RadioMessage::isOver(*(RadioMessage **)(puVar5[1] + 0x24));
    if (iVar7 != 0) {
      PlayerEgo::setTurretMode(this_00,false);
      resetCamera(this,*(Level **)(this + 0x18));
      PlayerEgo::setFreeLookMode(this_00,false);
      TargetFollowCamera::enableFirstPersonCam(*(TargetFollowCamera **)(this + 0x14),false);
      PlayerEgo::hideShipForFirstPersonCameraView(this_00,false);
      PlayerEgo::stopShooting(this_00,0);
      this[0x11] = (LevelScript)0x1;
      *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 0;
      *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 0;
      PlayerEgo::setComputerControlled(this_00,true);
      this_00[0x24] = (PlayerEgo)0x1;
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),true);
      TargetFollowCamera::setTarget
                (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this + 0xbc));
      AEGeometry::getPosition();
      pVVar48 = (Vector *)(this + 0x28);
      AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
      local_98 = 0x459c4000469c4000;
      local_90 = -20000.0;
      AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
      TargetFollowCamera::setPosition(*(TargetFollowCamera **)(this + 0x14),pVVar48);
      *(undefined4 *)(this + 0x90) = 0;
      *(undefined4 *)(this + 0x94) = 0;
      uVar29 = 0xb;
      fVar56 = extraout_s1_x00101;
      goto LAB_0016d73c;
    }
    iVar7 = *(int *)(this + 0x1c);
    fVar56 = extraout_s1_x00100;
switchD_00167778_caseD_2:
    if (iVar7 == 0xd) {
      fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
      TargetFollowCamera::translate
                (*(TargetFollowCamera **)(this + 0x14),fVar57 * 0.5,fVar56,fVar57 * 0.2);
      pLVar23 = this + 0x90;
      uVar47 = *(uint *)pLVar23;
      *(uint *)pLVar23 = uVar47 + param_1;
      *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
      pPVar3 = Globals::Canvas;
      pAVar52 = *(AEGeometry **)(this + 0xd8);
      uVar47 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      pMVar45 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar3,uVar47);
      AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_98,pMVar45);
      local_f0 = 0x3f80000000000000;
      local_e8 = 0.0;
      AEGeometry::setDirection(pAVar52,(Vector *)&local_98,(Vector *)&local_f0);
      lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
      AbyssEngine::Transform::Update(lVar68,bVar55);
      fVar57 = (float)__aeabi_l2f(*(undefined4 *)pLVar23,*(undefined4 *)(this + 0x94));
      in_fpscr = in_fpscr & 0xfffffff;
      fVar56 = 1.0;
      if (fVar57 / 10000.0 < 1.0) {
        fVar56 = fVar57 / 10000.0;
      }
      TargetFollowCamera::setRumblePercentage
                (*(TargetFollowCamera **)(this + 0x14),1.0 - fVar56,(int)(1.0 - fVar56));
      fVar56 = extraout_s1_x00117;
      if (((int)(uint)(*(uint *)pLVar23 < 0x867) <= *(int *)(this + 0x94)) &&
         (fVar57 = (float)AEGeometry::setVisible(*(AEGeometry **)(*(int *)puVar6[1] + 0x13c),false),
         fVar56 = extraout_s1_x00118,
         (int)(uint)(*(uint *)pLVar23 < 0x2711) <= *(int *)(this + 0x94))) {
        TargetFollowCamera::setRumblePercentage(*(TargetFollowCamera **)(this + 0x14),fVar57,0);
        TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x14),false);
        TargetFollowCamera::setTarget
                  (*(TargetFollowCamera **)(this + 0x14),*(AEGeometry **)(this_00 + 8));
        PlayerEgo::setComputerControlled(this_00,false);
        this_00[0x24] = (PlayerEgo)0x0;
        *(undefined1 *)(*(int *)(this + 0xd0) + 1) = 1;
        *(undefined1 *)(*(int *)(this + 0xd4) + 0x48) = 1;
        resetCamera(this,*(Level **)(this + 0x18));
        LODManager::forceUpdate((LODManager *)**(undefined4 **)(this + 0x18),param_1,false);
        uVar29 = 0xe;
        this[0x11] = (LevelScript)0x0;
        *(undefined4 *)pLVar23 = 0;
        *(undefined4 *)(this + 0x94) = 0;
        fVar56 = extraout_s1_x00119;
LAB_0016d73c:
        *(undefined4 *)(this + 0x1c) = uVar29;
      }
    }
    else if (iVar7 == 0xc) {
      pLVar23 = this + 0x90;
      uVar47 = *(uint *)pLVar23;
      *(uint *)pLVar23 = uVar47 + param_1;
      *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
      Explosion::update(*(Explosion **)(this + 200),param_1,(TargetFollowCamera *)0x0);
      fVar56 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
      TargetFollowCamera::translate
                (*(TargetFollowCamera **)(this + 0x14),fVar56 * 0.5,extraout_s1_x00120,fVar56 * 0.2)
      ;
      fVar57 = (float)__aeabi_l2f(*(undefined4 *)pLVar23,*(undefined4 *)(this + 0x94));
      fVar57 = fVar57 / 8000.0;
      in_fpscr = in_fpscr & 0xfffffff;
      fVar56 = 1.0;
      if (fVar57 < 1.0) {
        fVar56 = fVar57;
      }
      TargetFollowCamera::setRumblePercentage
                (*(TargetFollowCamera **)(this + 0x14),fVar57,(int)fVar56);
      fVar56 = extraout_s1_x00121;
      if ((int)(uint)(*(uint *)pLVar23 < 0x1f41) <= *(int *)(this + 0x94)) {
        pVVar48 = *(Vector **)(this + 0xd8);
        AEGeometry::getPosition();
        local_fc = 0.0;
        local_f8 = 0.0;
        local_f4 = -10000.0;
        AbyssEngine::AEMath::operator+((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
        AEGeometry::setPosition(pVVar48);
        uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
        AbyssEngine::Transform::SetAnimationState(uVar29,3,0);
        uVar29 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0xd8) + 0xc));
        fVar56 = (float)AbyssEngine::Transform::SetAnimationState(uVar29,1,0);
        FModSound::play(Globals::sound,0xa0,(Vector *)0x0,(Vector *)0x0,fVar56);
        *(undefined4 *)pLVar23 = 0;
        *(undefined4 *)(this + 0x94) = 0;
        uVar29 = 0xd;
        fVar56 = extraout_s1_x00122;
        goto LAB_0016d73c;
      }
    }
    else if (iVar7 == 0xb) {
      fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
      pLVar23 = this + 0x90;
      uVar47 = *(uint *)pLVar23;
      *(uint *)pLVar23 = uVar47 + param_1;
      *(uint *)(this + 0x94) = *(int *)(this + 0x94) + iVar13 + (uint)CARRY4(uVar47,param_1);
      TargetFollowCamera::translate
                (*(TargetFollowCamera **)(this + 0x14),fVar57 * 0.5,fVar56,fVar57 * 0.2);
      fVar56 = extraout_s1_x00115;
      if ((int)(uint)(*(uint *)pLVar23 < 0xfa1) <= *(int *)(this + 0x94)) {
        AEGeometry::getPosition();
        pVVar48 = (Vector *)(this + 0x28);
        AbyssEngine::AEMath::Vector::operator=(pVVar48,(Vector *)&local_98);
        local_98 = 0x459c4000c57a0000;
        local_90 = -6000.0;
        AbyssEngine::AEMath::Vector::operator+=(pVVar48,(Vector *)&local_98);
        local_98 = 0;
        local_90 = 0.0;
        Explosion::start(*(Explosion **)(this + 200),pVVar48,(Vector *)&local_98);
        *(undefined4 *)pLVar23 = 0;
        *(undefined4 *)(this + 0x94) = 0;
        uVar29 = 0xc;
        fVar56 = extraout_s1_x00116;
        goto LAB_0016d73c;
      }
    }
  }
LAB_0016d740:
  if (*(int *)(this + 0x1c) - 7U < 3) {
    fVar57 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(-param_1,(byte)(in_fpscr >> 0x16) & 3);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0x14),fVar57 * 0.5,fVar56,fVar57 * 0.2);
    if (7 < *(int *)(this + 0x1c)) {
      uVar47 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0xb8) + 0xc));
      AbyssEngine::Transform::Update((ulonglong)uVar47,bVar55);
      iVar13 = Level::getLandmarks(*(Level **)(this + 0x18));
      iVar13 = *(int *)(**(int **)(iVar13 + 4) + 0x13c);
      lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0xc));
      AbyssEngine::Transform::Update(lVar68,bVar55);
      lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0x14));
      AbyssEngine::Transform::Update(lVar68,bVar55);
      lVar68 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(iVar13 + 0x10));
      AbyssEngine::Transform::Update(lVar68,bVar55);
    }
  }
switchD_00161b94_caseD_1:
  if (this[0xa9] == (LevelScript)0x0) goto switchD_001616e0_default;
  iVar13 = *(int *)(this + 0x1c);
  if (iVar13 == 0) {
    PlayerEgo::getPosition();
    puVar5 = puVar6 + 1;
    (**(code **)(**(int **)*puVar5 + 0x28))((Vector *)&local_fc);
    AbyssEngine::AEMath::operator-((AEMath *)&local_98,(Vector *)&local_f0,(Vector *)&local_fc);
    fVar56 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_98);
    if ((49999 < (int)fVar56) || (*(char *)(*(int *)this_00 + 0x5e) != '\0')) {
      iVar13 = *(int *)(this + 0x1c);
      goto LAB_0016d2ae;
    }
    if (*puVar6 != 0) {
      uVar47 = 0;
      do {
        Player::setAlwaysEnemy(*(Player **)(*(int *)(*puVar5 + uVar47 * 4) + 4),true);
        if ((0 < (int)uVar47) && (*(char *)(*(int *)(*puVar5 + uVar47 * 4 + -4) + 0x3a) != '\0'))
        break;
        uVar47 = uVar47 + 1;
      } while (uVar47 < *puVar6);
    }
    pLVar43 = *(Level **)(this + 0x18);
    pSVar34 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar13 = SolarSystem::getRace(pSVar34);
    Level::createRadioMessage(pLVar43,0xe,iVar13);
    *(undefined4 *)(this + 0x1c) = 1;
  }
  else {
LAB_0016d2ae:
    if (1 < iVar13) goto switchD_001616e0_default;
  }
  iVar13 = Player::getHitpoints(*(Player **)(*(int *)puVar6[1] + 4));
  if (iVar13 < 1) {
    uVar47 = *puVar6;
    if (1 < uVar47) {
      uVar46 = 1;
      do {
        iVar13 = *(int *)(puVar6[1] + uVar46 * 4);
        if (*(char *)(iVar13 + 0x3a) != '\0') {
          Player::damage(*(Player **)(iVar13 + 4),9999999);
          uVar47 = *puVar6;
        }
        uVar46 = uVar46 + 1;
      } while (uVar46 < uVar47);
    }
    puVar5 = *(uint **)(Globals::status + 0x90);
    pSVar33 = Globals::status;
    if (*puVar5 != 0) {
      uVar47 = 0;
      do {
        iVar7 = *(int *)(puVar5[1] + uVar47 * 4);
        pSVar32 = (Station *)Status::getStation(pSVar33);
        iVar13 = Station::getIndex(pSVar32);
        pSVar33 = Globals::status;
        puVar5 = *(uint **)(Globals::status + 0x90);
        if (iVar7 == iVar13) {
          *(undefined4 *)(puVar5[1] + uVar47 * 4) = 0xffffffff;
        }
        uVar47 = uVar47 + 1;
      } while (uVar47 < *puVar5);
    }
    pLVar43 = *(Level **)(this + 0x18);
    pSVar34 = (SolarSystem *)Status::getSystem(pSVar33);
    iVar13 = SolarSystem::getRace(pSVar34);
    Level::createRadioMessage(pLVar43,0xf,iVar13);
    PlayerEgo::setAutoPilot(this_00,(KIPlayer *)0x0);
    PlayerEgo::setRoute(this_00,(Route *)0x0);
    Level::setPlayerRoute(*(Level **)(this + 0x18),(Route *)0x0);
    *(undefined4 *)(this + 0x1c) = 2;
  }
switchD_001616e0_default:
  if (__stack_chk_guard - local_5c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_5c);
  }
  return;
code_r0x00163c28:
  iVar13 = iVar13 + 1;
  if (3 < iVar13) goto LAB_00167438;
  goto LAB_00163c10;
  while (uVar46 = uVar46 + 1, uVar46 < uVar47) {
LAB_0016d46e:
    pPVar40 = *(PlayerFixedObject **)(puVar6[1] + uVar46 * 4);
    if (pPVar40[0x3c] != (PlayerFixedObject)0x0) {
      pPVar40[0x20] = (PlayerFixedObject)0x1;
      PlayerFixedObject::setMoving(pPVar40,false);
      break;
    }
  }
  goto LAB_0016eede;
}

// ===== LevelScript::resetCamera  @0x0016f418  (118 bytes)
/* LevelScript::resetCamera(Level*) */

void __thiscall LevelScript::resetCamera(LevelScript *this,Level *param_1)

{
  int iVar1;
  TargetFollowCamera *this_00;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  iVar1 = Level::getPlayer(param_1);
  if (iVar1 != 0) {
    this_00 = *(TargetFollowCamera **)(this + 0x14);
    iVar1 = Level::getPlayer(param_1);
    TargetFollowCamera::setTarget(this_00,*(AEGeometry **)(iVar1 + 8));
    local_24 = 0;
    local_20 = 0x44160000;
    local_1c = 0xc4228000;
    TargetFollowCamera::setTargetOffset(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_24);
    local_24 = 0;
    local_20 = 0x44160000;
    local_1c = 0xc4a74000;
    TargetFollowCamera::setCamOffset(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_24);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== LevelScript::lookBehind  @0x0016f498  (92 bytes)
/* LevelScript::lookBehind() */

void __thiscall LevelScript::lookBehind(LevelScript *this)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0xc46d8000;
  TargetFollowCamera::setTargetOffset(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_20);
  local_20 = 0;
  local_1c = 0x44160000;
  local_18 = 0x450b6000;
  TargetFollowCamera::setCamOffset(*(TargetFollowCamera **)(this + 0x14),(Vector *)&local_20);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== LevelScript::render3D  @0x0016f4fc  (126 bytes)
/* LevelScript::render3D() */

void __thiscall LevelScript::render3D(LevelScript *this)

{
  int iVar1;
  
  if (*(AEGeometry **)(this + 0xdc) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0xdc));
  }
  if (*(AEGeometry **)(this + 0xd8) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0xd8));
  }
  if (*(AEGeometry **)(this + 0xb8) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0xb8));
  }
  if (*(AEGeometry **)(this + 0xbc) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0xbc));
  }
  if (*(AEGeometry **)(this + 0xc0) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0xc0));
  }
  if (*(AEGeometry **)(this + 0xc4) != (AEGeometry *)0x0) {
    AEGeometry::render(*(AEGeometry **)(this + 0xc4));
  }
  if ((*(Explosion **)(this + 200) != (Explosion *)0x0) &&
     (iVar1 = Explosion::isPlaying(*(Explosion **)(this + 200)), iVar1 == 1)) {
    Explosion::render(*(Explosion **)(this + 200));
  }
  if ((this[0xa8] != (LevelScript)0x0) && (*(AEGeometry **)(this + 0xac) != (AEGeometry *)0x0)) {
    AEGeometry::render(*(AEGeometry **)(this + 0xac));
    AEGeometry::render(*(AEGeometry **)(this + 0xb0));
    AEGeometry::render(*(AEGeometry **)(this + 0xb4));
    return;
  }
  return;
}

// ===== LevelScript::skipSequence  @0x0016f57c  (58 bytes)
/* LevelScript::skipSequence() */

void __thiscall LevelScript::skipSequence(LevelScript *this)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(this + 0x24) < 1) {
    return;
  }
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar1 < 1) {
    return;
  }
  *(undefined4 *)(this + 0x24) = 0x1b59;
  puVar2 = (undefined4 *)Level::getPlayer(*(Level **)(this + 0x18));
  Player::setVulnerable((Player *)*puVar2,true);
  return;
}

// ===== LevelScript::canSkipCutsceneNow  @0x0016f5b8  (88 bytes)
/* LevelScript::canSkipCutsceneNow() */

undefined4 __thiscall LevelScript::canSkipCutsceneNow(LevelScript *this)

{
  int iVar1;
  
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar1 == 0x9a) {
    if (8 < *(int *)(this + 0x1c) - 1U) {
      return 0;
    }
  }
  else {
    iVar1 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar1 == 0x9d) {
      if (2 < *(int *)(this + 0x1c) - 2U) {
        return 0;
      }
    }
    else {
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar1 == 0x9e) && (1 < *(int *)(this + 0x1c))) {
        return 0;
      }
    }
  }
  return 1;
}

// ===== LevelScript::skipCutscene  @0x0016f61c  (402 bytes)
/* LevelScript::skipCutscene() */

void __thiscall LevelScript::skipCutscene(LevelScript *this)

{
  int iVar1;
  int iVar2;
  Route *this_00;
  int *piVar3;
  Level *this_01;
  int *piVar4;
  code *pcVar5;
  undefined1 auStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar1 == 0x9a) {
    if (*(int *)(this + 0x1c) - 1U < 9) {
      iVar1 = 0;
      *(undefined4 *)(this + 0x1c) = 9;
      do {
        iVar2 = Level::getMessages(*(Level **)(this + 0x18));
        RadioMessage::trigger(*(RadioMessage **)(*(int *)(iVar2 + 4) + iVar1 * 4));
        iVar2 = Level::getMessages(*(Level **)(this + 0x18));
        RadioMessage::finish(*(RadioMessage **)(*(int *)(iVar2 + 4) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 != 8);
      *(undefined4 *)(this + 0x90) = 0x7d1;
      *(undefined4 *)(this + 0x94) = 0;
      iVar1 = Level::getEnemies(*(Level **)(this + 0x18));
      PlayerFighter::setAIDisabled((PlayerFighter *)**(undefined4 **)(iVar1 + 4),false);
      iVar1 = Level::getEnemies(*(Level **)(this + 0x18));
      piVar4 = (int *)**(undefined4 **)(iVar1 + 4);
      pcVar5 = *(code **)(*piVar4 + 0x44);
      iVar1 = Level::getEnemies(*(Level **)(this + 0x18));
      this_00 = (Route *)KIPlayer::getRoute((KIPlayer *)**(undefined4 **)(iVar1 + 4));
      piVar3 = (int *)Route::getWaypoint(this_00,0);
      (**(code **)(*piVar3 + 0x28))(auStack_24);
      (*pcVar5)(piVar4,auStack_24);
    }
  }
  else {
    iVar1 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar1 == 0x9d) {
      if (*(int *)(this + 0x1c) < 5) {
        iVar1 = 0;
        do {
          iVar2 = Level::getMessages(*(Level **)(this + 0x18));
          RadioMessage::trigger(*(RadioMessage **)(*(int *)(iVar2 + 4) + iVar1 * 4));
          iVar2 = Level::getMessages(*(Level **)(this + 0x18));
          RadioMessage::finish(*(RadioMessage **)(*(int *)(iVar2 + 4) + iVar1 * 4));
          iVar1 = iVar1 + 1;
        } while (iVar1 != 4);
        *(undefined4 *)(this + 0x1c) = 4;
        *(undefined4 *)(this + 0x90) = 0x4651;
        *(undefined4 *)(this + 0x94) = 0;
      }
    }
    else {
      iVar1 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar1 == 0x9e) {
        iVar1 = 0;
        *(undefined4 *)(this + 0x98) = 0x2ee1;
        *(undefined4 *)(this + 0x9c) = 0;
        this_01 = *(Level **)(this + 0x18);
        do {
          iVar2 = Level::getMessages(this_01);
          RadioMessage::trigger(*(RadioMessage **)(*(int *)(iVar2 + 4) + iVar1 * 4));
          iVar2 = Level::getMessages(*(Level **)(this + 0x18));
          RadioMessage::finish(*(RadioMessage **)(*(int *)(iVar2 + 4) + iVar1 * 4));
          this_01 = *(Level **)(this + 0x18);
          iVar1 = iVar1 + 1;
        } while (iVar1 != 3);
        iVar1 = Level::getEnemies(this_01);
        (**(code **)(*(int *)**(undefined4 **)(iVar1 + 4) + 0x48))
                  ((int *)**(undefined4 **)(iVar1 + 4),0xc501d000,0,0x469e1200);
        iVar1 = Level::getEnemies(*(Level **)(this + 0x18));
        KIPlayer::setVisible((KIPlayer *)**(undefined4 **)(iVar1 + 4),true);
        iVar1 = Level::getEnemies(*(Level **)(this + 0x18));
        KIPlayer::setActive(SUB41(**(undefined4 **)(iVar1 + 4),0));
        *(undefined4 *)(this + 0x1c) = 2;
      }
    }
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== LevelScript::resetStartSequenceOver  @0x0016f7c4  (10 bytes)
/* LevelScript::resetStartSequenceOver() */

void __thiscall LevelScript::resetStartSequenceOver(LevelScript *this)

{
  this[0x21] = (LevelScript)0x0;
  *(undefined4 *)(this + 0x24) = 0;
  return;
}

// ===== LevelScript::startSequenceOver  @0x0016f7ce  (6 bytes)
/* LevelScript::startSequenceOver() */

LevelScript __thiscall LevelScript::startSequenceOver(LevelScript *this)

{
  return this[0x21];
}

// ===== LevelScript::startSequence  @0x0016f7d4  (6 bytes)
/* LevelScript::startSequence() */

LevelScript __thiscall LevelScript::startSequence(LevelScript *this)

{
  return this[0x20];
}

// ===== LevelScript::getEvent  @0x0016f7da  (4 bytes)
/* LevelScript::getEvent() */

undefined4 __thiscall LevelScript::getEvent(LevelScript *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== LevelScript::setEvent  @0x0016f7de  (4 bytes)
/* LevelScript::setEvent(int) */

void __thiscall LevelScript::setEvent(LevelScript *this,int param_1)

{
  *(int *)(this + 0x1c) = param_1;
  return;
}

