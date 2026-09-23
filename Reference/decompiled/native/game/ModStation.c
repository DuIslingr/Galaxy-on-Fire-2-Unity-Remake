// Class: ModStation
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ModStation::ModStation  @0x000e7bf0  (930 bytes)
/* ModStation::ModStation() */

void __thiscall ModStation::ModStation(ModStation *this)

{
  Status *this_00;
  PaintCanvas *this_01;
  Station *pSVar1;
  int iVar2;
  SolarSystem *this_02;
  EaseInOutMatrix *pEVar3;
  uint uVar4;
  EaseInOut *pEVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint in_fpscr;
  float fVar10;
  float fVar11;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float fVar12;
  undefined4 uVar13;
  undefined1 auStack_16c [60];
  AEMath aAStack_130 [60];
  undefined1 auStack_f4 [60];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  *(undefined ***)this = &PTR__ModStation_00263f70;
  AbyssEngine::String::String((String *)(this + 0x38));
  uStack_5c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_58 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  local_54 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  this[0xac] = (ModStation)0x0;
  this[0xaf] = (ModStation)0x0;
  this[0xad] = (ModStation)0x0;
  *(undefined4 *)(this + 0x14) = 0;
  this[0x24] = (ModStation)0x0;
  *(undefined4 *)(this + 0xc) = 100;
  this[0x65] = (ModStation)0x0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  this[0xd8] = (ModStation)0x0;
  this[0xd9] = (ModStation)0x0;
  this[0x6a] = (ModStation)0x0;
  this[0x18] = (ModStation)0x0;
  this[0x144] = (ModStation)0x0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = uStack_5c;
  *(undefined4 *)(this + 0x94) = local_58;
  *(undefined4 *)(this + 0x98) = local_54;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = uStack_5c;
  *(undefined4 *)(this + 0x84) = local_58;
  *(undefined4 *)(this + 0x88) = local_54;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = uStack_5c;
  *(undefined4 *)(this + 0x74) = local_58;
  *(undefined4 *)(this + 0x78) = local_54;
  this_00 = Globals::status;
  puVar7 = (undefined4 *)((uint)&local_78 | 4);
  local_78 = 0x3f800000;
  *puVar7 = 0;
  puVar7[1] = uStack_5c;
  puVar7[2] = local_58;
  puVar7[3] = local_54;
  local_64 = 0x3f800000;
  local_60 = 0;
  local_50 = 0x3f800000;
  local_48 = 0x3f8000003f800000;
  local_40 = 0x3f800000;
  pSVar1 = (Station *)Status::getStation(this_00);
  iVar2 = Station::getIndex(pSVar1);
  if (iVar2 == 0x65) {
    iVar2 = 8;
    fVar11 = extraout_s1;
  }
  else {
    pSVar1 = (Station *)Status::getStation(Globals::status);
    iVar2 = Station::getIndex(pSVar1);
    if (iVar2 == 100) {
      iVar2 = 7;
      fVar11 = extraout_s1_00;
    }
    else {
      this_02 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar2 = SolarSystem::getRace(this_02);
      fVar11 = extraout_s1_01;
    }
  }
  iVar8 = iVar2 * 3 + 1;
  iVar9 = iVar2 * 3 + 2;
  puVar6 = &DAT_002546c4;
  if (Globals::iPad != '\0') {
    puVar6 = &DAT_0025464c;
  }
  fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(puVar6 + iVar2 * 0xc),
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(puVar6 + iVar8 * 4),
                                      (byte)(in_fpscr >> 0x16) & 3);
  uVar13 = VectorSignedToFloat(*(undefined4 *)(puVar6 + iVar9 * 4),(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 300) = fVar10;
  *(float *)(this + 0x130) = fVar12;
  *(undefined4 *)(this + 0x134) = uVar13;
  AbyssEngine::AEMath::MatrixSetTranslation
            ((AEMath *)&local_b8,(Matrix *)&local_78,fVar10,fVar11,fVar12);
  puVar6 = &UNK_0025478c;
  if (Globals::iPad != '\0') {
    puVar6 = &UNK_00254764;
  }
  AbyssEngine::AEMath::MatrixSetRotation
            (auStack_f4,&local_78,*(undefined4 *)(&UNK_0025473c + iVar2 * 4),
             *(undefined4 *)(puVar6 + iVar2 * 4),0,2);
  uStack_9c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_98 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_94 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar7 = (undefined4 *)((uint)&local_b8 | 4);
  local_b8 = 0x3f800000;
  *puVar7 = 0;
  puVar7[1] = uStack_9c;
  puVar7[2] = local_98;
  puVar7[3] = uStack_94;
  local_a4 = 0x3f800000;
  local_a0 = 0;
  local_90 = 0x3f800000;
  local_88 = 0x3f8000003f800000;
  local_80 = 0x3f800000;
  puVar6 = &DAT_002546c4;
  if (Globals::iPad != '\0') {
    puVar6 = &DAT_0025464c;
  }
  VectorSignedToFloat(*(undefined4 *)(puVar6 + iVar2 * 0xc),(byte)(in_fpscr >> 0x16) & 3);
  fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(puVar6 + iVar8 * 4),
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorSignedToFloat(*(undefined4 *)(puVar6 + iVar9 * 4),
                                      (byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::MatrixSetTranslation
            (aAStack_130,(AEMath *)&local_b8,fVar11,extraout_s1_02,fVar10);
  puVar6 = &UNK_0025478c;
  if (Globals::iPad != '\0') {
    puVar6 = &UNK_00254764;
  }
  AbyssEngine::AEMath::MatrixSetRotation
            (auStack_16c,&local_b8,*(undefined4 *)(&UNK_0025473c + iVar2 * 4),
             *(undefined4 *)(puVar6 + iVar2 * 4),0,2);
  pEVar3 = operator_new(0xf4);
  AbyssEngine::EaseInOutMatrix::EaseInOutMatrix
            (pEVar3,local_78,local_74,local_70,local_6c,local_68,local_64,local_60,uStack_5c,
             local_58,local_54,(undefined4)local_50,local_50._4_4_,(undefined4)local_48,
             local_48._4_4_,local_40,local_b8,local_b4,local_b0,local_ac,local_a8,local_a4,local_a0,
             uStack_9c,local_98,uStack_94,(undefined4)local_90,local_90._4_4_,(undefined4)local_88,
             local_88._4_4_,local_80,3000);
  *(EaseInOutMatrix **)(this + 0x20) = pEVar3;
  this_01 = Globals::Canvas;
  uVar4 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  AbyssEngine::PaintCanvas::CameraSetLocal(this_01,uVar4,(Matrix *)&local_78);
  pEVar5 = operator_new(0x10);
  AbyssEngine::EaseInOut::EaseInOut(pEVar5,extraout_s0,extraout_s1_03);
  *(EaseInOut **)(this + 0x138) = pEVar5;
  pEVar5 = operator_new(0x10);
  AbyssEngine::EaseInOut::EaseInOut(pEVar5,extraout_s0_00,extraout_s1_04);
  *(EaseInOut **)(this + 0x13c) = pEVar5;
  pEVar5 = operator_new(0x10);
  AbyssEngine::EaseInOut::EaseInOut(pEVar5,extraout_s0_01,extraout_s1_05);
  *(EaseInOut **)(this + 0x140) = pEVar5;
  if (__stack_chk_guard - local_3c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_3c);
  }
  return;
}

// ===== ModStation::~ModStation  @0x000e8030  (34 bytes)
/* ModStation::~ModStation() */

ModStation * __thiscall ModStation::~ModStation(ModStation *this)

{
  *(undefined ***)this = &PTR__ModStation_00263f70;
  OnRelease(this);
  AbyssEngine::String::~String((String *)(this + 0x38));
  return this;
}

// ===== ModStation::~ModStation  @0x000e8068  (16 bytes)
/* ModStation::~ModStation() */

void __thiscall ModStation::~ModStation(ModStation *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~ModStation(this);
  operator_delete(pvVar1);
  return;
}

// ===== ModStation::OnInitialize  @0x000e8080  (6708 bytes)
/* ModStation::OnInitialize() */

void ModStation::OnInitialize(void)

{
  ModStation MVar1;
  longlong lVar2;
  Status *pSVar3;
  PaintCanvas *pPVar4;
  FModSound *this;
  bool bVar5;
  ModStation *in_r0;
  CutScene *pCVar6;
  int iVar7;
  Station *pSVar8;
  Generator *pGVar9;
  undefined4 uVar10;
  DialogueWindow *pDVar11;
  String *pSVar12;
  Agent *this_00;
  void *pvVar13;
  SolarSystem *pSVar14;
  NewsTicker *this_01;
  ChoiceWindow *pCVar15;
  TouchButton *pTVar16;
  Array *pAVar17;
  undefined4 *puVar18;
  String *pSVar19;
  uint *puVar20;
  Matrix *pMVar21;
  Standing *pSVar22;
  EaseInOut *pEVar23;
  undefined *puVar24;
  EaseInOutMatrix *pEVar25;
  Mission *pMVar26;
  Item *pIVar27;
  Ship *pSVar28;
  Station *pSVar29;
  undefined4 extraout_r1;
  uint uVar30;
  uint uVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  bool bVar39;
  uint in_fpscr;
  float in_s0;
  float extraout_s0;
  float fVar40;
  float fVar41;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  undefined8 uVar42;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s1_07;
  float extraout_s2;
  float extraout_s2_00;
  float fVar43;
  undefined4 uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  longlong lVar47;
  float local_128;
  float local_120;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 uStack_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  float local_98;
  float local_94;
  String aSStack_8c [8];
  String aSStack_84 [8];
  String aSStack_7c [8];
  String aSStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  int local_4c;
  
  local_4c = __stack_chk_guard;
  *(undefined4 *)(in_r0 + 0x98) = 0;
  if (*(int *)(in_r0 + 0x14) == 0) {
    pCVar6 = operator_new(0xa0);
    CutScene::CutScene(pCVar6,0x17);
    *(CutScene **)(in_r0 + 0x14) = pCVar6;
    in_s0 = (float)CutScene::initialize(pCVar6);
  }
  iVar7 = *(int *)(in_r0 + 0xc);
  if (iVar7 < 0x3c) {
    if (iVar7 == 0x14) {
      if (((in_r0[0xad] == (ModStation)0x0) && (in_r0[0xac] == (ModStation)0x0)) &&
         (in_r0[0xfd] != (ModStation)0x0)) {
        iVar7 = Status::getCurrentCampaignMission(Globals::status);
        if (iVar7 == 0x4d) {
          pSVar8 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::getIndex(pSVar8);
          if (iVar7 == 0x65) goto LAB_000e88fc;
        }
        autosave(in_r0);
      }
LAB_000e88fc:
      iVar7 = Status::getCurrentCampaignMission(Globals::status);
      pSVar3 = Globals::status;
      if (iVar7 == 1) {
        pSVar28 = (Ship *)Ship::makeShip((Ship *)**(undefined4 **)(Globals::ships + 4),-1);
        Status::setShip(pSVar3,pSVar28);
        pSVar28 = (Ship *)Status::getShip(Globals::status);
        Ship::setRace(pSVar28,8);
        pIVar27 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x168));
        Item::setUnsaleable(pIVar27,true);
        pSVar28 = (Ship *)Status::getShip(Globals::status);
        Ship::setEquipment(pSVar28,pIVar27,0);
        pIVar27 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x144));
        pSVar28 = (Ship *)Status::getShip(Globals::status);
        Ship::setEquipment(pSVar28,pIVar27,1);
        Item::setUnsaleable(pIVar27,true);
        pCVar6 = *(CutScene **)(in_r0 + 0x14);
        pSVar28 = (Ship *)Status::getShip(Globals::status);
        iVar7 = Ship::getIndex(pSVar28);
        CutScene::replacePlayerShip(pCVar6,iVar7,3);
      }
      iVar7 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar7 < 5) {
        TouchButton::setHalfTransparent
                  ((TouchButton *)**(undefined4 **)(*(int *)(in_r0 + 0x88) + 4),true);
        bVar5 = false;
LAB_000e8ac0:
        bVar39 = bVar5;
        TouchButton::setHalfTransparent
                  (*(TouchButton **)(*(int *)(*(int *)(in_r0 + 0x88) + 4) + 8),true);
        TouchButton::setHalfTransparent
                  (*(TouchButton **)(*(int *)(*(int *)(in_r0 + 0x88) + 4) + 0xc),true);
      }
      else {
        bVar39 = false;
        bVar5 = iVar7 == 0xf;
        if ((iVar7 < 9) || (iVar7 == 0xf)) goto LAB_000e8ac0;
      }
      if ((iVar7 < 0xc) || (bVar39)) {
LAB_000e8b0c:
        TouchButton::setHalfTransparent
                  (*(TouchButton **)(*(int *)(*(int *)(in_r0 + 0x88) + 4) + 4),true);
      }
      else {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if (iVar7 == 100) goto LAB_000e8b0c;
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if (iVar7 == 0x65) goto LAB_000e8b0c;
      }
      pPVar4 = Globals::Canvas;
      uVar31 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      pMVar21 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar4,uVar31);
      AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_98,pMVar21);
      local_94 = local_94 + -0.3;
      local_98 = local_98 + -0.2;
      AbyssEngine::AEMath::Vector::operator=((Vector *)(in_r0 + 0x118),(Vector *)&local_98);
      resetLight(in_r0);
      if (in_r0[0xfd] != (ModStation)0x0) {
        enterStation();
      }
      iVar7 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar7 == 0x4d) {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if (iVar7 == 100) {
          pSVar8 = (Station *)Status::getStation(Globals::status);
          puVar20 = (uint *)Station::getShips(pSVar8);
          if ((puVar20 != (uint *)0x0) && (*puVar20 != 0)) {
            uVar31 = 0;
            do {
              iVar7 = Ship::getIndex(*(Ship **)(puVar20[1] + uVar31 * 4));
              if (iVar7 == 0x25) {
                Ship::setPrice(*(Ship **)(puVar20[1] + uVar31 * 4),0);
              }
              uVar31 = uVar31 + 1;
            } while (uVar31 < *puVar20);
          }
        }
      }
      pSVar8 = (Station *)Status::getStation(Globals::status);
      iVar7 = Station::getIndex(pSVar8);
      if (iVar7 == 0x65) {
        iVar7 = 8;
        fVar40 = extraout_s1;
      }
      else {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if (iVar7 == 100) {
          iVar7 = 7;
          fVar40 = extraout_s1_00;
        }
        else {
          pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar7 = SolarSystem::getRace(pSVar14);
          fVar40 = extraout_s1_01;
        }
      }
      uStack_bc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      local_b8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      local_b4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar18 = (undefined4 *)((uint)&local_d8 | 4);
      local_d8 = 0x3f800000;
      *puVar18 = 0;
      puVar18[1] = uStack_bc;
      puVar18[2] = local_b8;
      puVar18[3] = local_b4;
      iVar32 = iVar7 * 0xc;
      local_c4 = 0x3f800000;
      fVar41 = *(float *)(&DAT_002546c4 + iVar32);
      uVar10 = VectorSignedToFloat(fVar41,(byte)(in_fpscr >> 0x16) & 3);
      local_c0 = 0;
      uVar44 = VectorSignedToFloat(*(undefined4 *)(&DAT_002546c8 + iVar32),
                                   (byte)(in_fpscr >> 0x16) & 3);
      uVar45 = VectorSignedToFloat(*(undefined4 *)(&DAT_002546cc + iVar32),
                                   (byte)(in_fpscr >> 0x16) & 3);
      local_b0 = 0x3f800000;
      local_a8 = 0x3f8000003f800000;
      local_a0 = 0x3f800000;
      *(undefined4 *)(in_r0 + 300) = uVar10;
      *(undefined4 *)(in_r0 + 0x130) = uVar44;
      *(undefined4 *)(in_r0 + 0x134) = uVar45;
      if (*(EaseInOut **)(in_r0 + 0x138) == (EaseInOut *)0x0) {
        pEVar23 = operator_new(0x10);
        uVar42 = AbyssEngine::EaseInOut::EaseInOut(pEVar23,extraout_s0_00,extraout_s1_02);
        *(EaseInOut **)(in_r0 + 0x138) = pEVar23;
      }
      else {
        uVar42 = AbyssEngine::EaseInOut::SetRange(*(EaseInOut **)(in_r0 + 0x138),fVar41,fVar40);
      }
      if (*(EaseInOut **)(in_r0 + 0x13c) == (EaseInOut *)0x0) {
        pEVar23 = operator_new(0x10);
        uVar42 = AbyssEngine::EaseInOut::EaseInOut(pEVar23,extraout_s0_01,extraout_s1_03);
        *(EaseInOut **)(in_r0 + 0x13c) = pEVar23;
      }
      else {
        uVar42 = AbyssEngine::EaseInOut::SetRange
                           (*(EaseInOut **)(in_r0 + 0x13c),(float)uVar42,
                            (float)((ulonglong)uVar42 >> 0x20));
      }
      if (*(EaseInOut **)(in_r0 + 0x140) == (EaseInOut *)0x0) {
        pEVar23 = operator_new(0x10);
        AbyssEngine::EaseInOut::EaseInOut(pEVar23,extraout_s0_03,extraout_s1_05);
        *(EaseInOut **)(in_r0 + 0x140) = pEVar23;
        fVar40 = extraout_s0_04;
        fVar41 = extraout_s1_06;
        fVar43 = extraout_s2_00;
      }
      else {
        AbyssEngine::EaseInOut::SetRange
                  (*(EaseInOut **)(in_r0 + 0x140),(float)uVar42,(float)((ulonglong)uVar42 >> 0x20));
        fVar40 = extraout_s0_02;
        fVar41 = extraout_s1_04;
        fVar43 = extraout_s2;
      }
      if (*(int *)(in_r0 + 0x14) != 0) {
        AbyssEngine::AEMath::MatrixSetTranslation
                  ((AEMath *)&local_114,(Matrix *)&local_d8,fVar40,fVar41,fVar43);
        uVar46 = *(undefined4 *)(&UNK_0025473c + iVar7 * 4);
        puVar24 = &UNK_00254764;
        if (Globals::iPad == '\0') {
          puVar24 = &UNK_0025478c;
        }
        AbyssEngine::AEMath::MatrixSetRotation
                  (&local_114,&local_d8,uVar46,*(undefined4 *)(puVar24 + iVar7 * 4),0xbcf5c28f,2);
        pPVar4 = Globals::Canvas;
        uVar31 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
        AbyssEngine::PaintCanvas::CameraSetLocal(pPVar4,uVar31,(Matrix *)&local_d8);
        local_114 = uVar10;
        local_110 = uVar44;
        local_10c = uVar45;
        AbyssEngine::AEMath::Vector::operator=
                  ((Vector *)(*(int *)(in_r0 + 0x14) + 8),(Vector *)&local_114);
        puVar24 = &UNK_00254764;
        if (Globals::iPad == '\0') {
          puVar24 = &UNK_0025478c;
        }
        local_110 = *(undefined4 *)(puVar24 + iVar7 * 4);
        local_10c = 0xbcf5c28f;
        local_114 = uVar46;
        AbyssEngine::AEMath::Vector::operator=
                  ((Vector *)(*(int *)(in_r0 + 0x14) + 0x14),(Vector *)&local_114);
        AEGeometry::setMatrix(*(Matrix **)(*(int *)(in_r0 + 0x14) + 0x20));
        iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x14);
        in_r0[0x129] = (ModStation)(iVar7 < 10);
        iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x14);
        in_r0[0x12a] = (ModStation)(10 < iVar7);
        iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x14);
        in_r0[299] = (ModStation)(iVar7 < 10);
        MVar1 = in_r0[0x12a];
        iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x96);
        if (MVar1 != (ModStation)0x0) {
          iVar7 = -iVar7;
        }
        fVar40 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(*(int *)(in_r0 + 0x14) + 8) = *(float *)(*(int *)(in_r0 + 0x14) + 8) + fVar40;
        MVar1 = in_r0[0x129];
        iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x96);
        if (MVar1 != (ModStation)0x0) {
          iVar7 = -iVar7;
        }
        fVar40 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(*(int *)(in_r0 + 0x14) + 0xc) = *(float *)(*(int *)(in_r0 + 0x14) + 0xc) + fVar40
        ;
        MVar1 = in_r0[299];
        iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x96);
        if (MVar1 != (ModStation)0x0) {
          iVar7 = -iVar7;
        }
        fVar40 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
        fVar41 = *(float *)(*(int *)(in_r0 + 0x14) + 0x10);
        fVar40 = fVar41 + fVar40;
        *(float *)(*(int *)(in_r0 + 0x14) + 0x10) = fVar40;
        AbyssEngine::AEMath::MatrixSetTranslation
                  ((AEMath *)&local_114,(Matrix *)&local_d8,fVar40,extraout_s1_07,fVar41);
        if (*(int *)(in_r0 + 0x20) == 0) {
          pEVar25 = operator_new(0xf4);
          AbyssEngine::EaseInOutMatrix::EaseInOutMatrix
                    (pEVar25,local_d8,local_d4,local_d0,local_cc,uStack_c8,local_c4,local_c0,
                     uStack_bc,local_b8,local_b4,(undefined4)local_b0,local_b0._4_4_,
                     (undefined4)local_a8,local_a8._4_4_,local_a0,local_d8,local_d4,local_d0,
                     local_cc,uStack_c8,local_c4,local_c0,uStack_bc,local_b8,local_b4,
                     (undefined4)local_b0,local_b0._4_4_,(undefined4)local_a8,local_a8._4_4_,
                     local_a0,3000);
          *(EaseInOutMatrix **)(in_r0 + 0x20) = pEVar25;
        }
        else {
          AbyssEngine::EaseInOutMatrix::SetRange(*(int *)(in_r0 + 0x20));
        }
      }
      if ((((in_r0[0x65] == (ModStation)0x0) && (in_r0[0x66] == (ModStation)0x0)) &&
          (in_r0[0x5f] == (ModStation)0x0)) && (*(char *)(Globals::layout + 0x2ec) == '\0')) {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if (iVar7 != 0x65) {
          pSVar28 = (Ship *)Status::getShip(Globals::status);
          iVar7 = Ship::hasJumpDrive(pSVar28);
          pSVar28 = (Ship *)Status::getShip(Globals::status);
          iVar32 = Ship::hasCargo(pSVar28,0x55,1);
          pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar33 = SolarSystem::getRoutes(pSVar14);
          if (((iVar33 == 0) &&
              (iVar33 = Status::getCurrentCampaignMission(Globals::status),
              iVar7 == 0 && iVar32 == 0)) && (0x10 < iVar33)) {
            pSVar19 = *(String **)(in_r0 + 0x6c);
            bVar39 = (bool)GameText::getText(Globals::gameText,0x14f);
            ChoiceWindow::set(pSVar19,bVar39);
            in_r0[0x5f] = (ModStation)0x1;
            in_r0[0x69] = (ModStation)0x1;
          }
        }
      }
      uVar10 = 1;
      Globals::status[0xf8] = (Status)0x1;
      *(undefined4 *)(in_r0 + 0x124) = 0;
      in_r0[0x114] = (ModStation)0x0;
      in_r0[0xaf] = (ModStation)0x0;
      *(undefined4 *)(in_r0 + 0x2c) = 0;
      in_r0[0x144] = (ModStation)0x0;
    }
    else {
      if (iVar7 != 0x28) {
LAB_000e89d0:
        FModSound::play(Globals::sound,0x7a,(Vector *)0x0,(Vector *)0x0,in_s0);
        FModSound::enableReverb(Globals::sound,0);
        FModSound::setDownPitch(Globals::sound,false);
        if (Globals::switch_to_target_setting != -1) {
          Globals::playMusicAndFadeOutCurrent(Globals::globals,Globals::switch_to_target_setting);
        }
        Globals::switch_to_target_setting = -1;
        *(undefined4 *)(in_r0 + 0xc) = 100;
        in_r0[0x24] = (ModStation)0x1;
        puVar20 = *(uint **)(in_r0 + 0x88);
        uVar31 = Globals::sub_menu_button_count;
        if (puVar20 != (uint *)0x0) {
          if (*puVar20 == 0) {
            uVar31 = 0;
          }
          else {
            uVar30 = 0;
            do {
              if ((int)uVar30 < 10) {
                TouchButton::getPosition();
                *(int *)(Globals::sub_menu_buttons_x + uVar30 * 4) = (int)local_120;
                TouchButton::getPosition();
                *(int *)(Globals::sub_menu_buttons_y + uVar30 * 4) = (int)local_128;
                puVar20 = *(uint **)(in_r0 + 0x88);
              }
              uVar30 = uVar30 + 1;
              uVar31 = *puVar20;
            } while (uVar30 < *puVar20);
          }
        }
        Globals::sub_menu_button_count = uVar31;
        uVar10 = 0;
        goto LAB_000e9c42;
      }
      iVar7 = Status::inAlienOrbit(Globals::status);
      if (iVar7 == 0) {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if ((iVar7 == 0x78) &&
           ((iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x62 ||
            (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 100)))) {
          in_r0[0xd4] = (ModStation)0x1;
        }
      }
      iVar7 = Status::inAlienOrbit(Globals::status);
      if (iVar7 == 0) {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if ((iVar7 == 0x3a) &&
           (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x8a)) {
          in_r0[0xd4] = (ModStation)0x1;
        }
      }
      iVar7 = Status::inAlienOrbit(Globals::status);
      if (iVar7 == 0) {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if ((iVar7 == 0x7e) &&
           (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x78)) {
          in_r0[0xd4] = (ModStation)0x1;
        }
      }
      iVar7 = Status::inAlienOrbit(Globals::status);
      if (iVar7 == 0) {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if ((iVar7 == 0x4e) &&
           (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x8d)) {
          in_r0[0xd4] = (ModStation)0x1;
        }
      }
      iVar7 = Status::inSupernovaSystem(Globals::status);
      if (iVar7 == 1) {
        in_r0[0xd4] = (ModStation)0x1;
      }
      if (Globals::enterSpaceLounge != '\0') {
        *(undefined2 *)(in_r0 + 0xd4) = 0x101;
      }
      if (in_r0[0xac] == (ModStation)0x0) {
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        if (iVar7 == 4) {
LAB_000e8c12:
          iVar7 = Status::getCurrentCampaignMission(Globals::status);
          if ((iVar7 != 0x30) && (iVar7 = Status::inBlackMarketSystem(Globals::status), iVar7 == 0))
          {
            pSVar8 = (Station *)Status::getStation(Globals::status);
            iVar7 = Station::getIndex(pSVar8);
            if (iVar7 != 0x6c) {
              pSVar8 = (Station *)Status::getStation(Globals::status);
              iVar7 = Station::getIndex(pSVar8);
              if (iVar7 != 100) {
                pSVar8 = (Station *)Status::getStation(Globals::status);
                iVar7 = Station::getIndex(pSVar8);
                if ((((iVar7 != 0x65) && (in_r0[0x66] == (ModStation)0x0)) &&
                    (in_r0[0x5f] == (ModStation)0x0)) &&
                   ((in_r0[0xd4] == (ModStation)0x0 && (Globals::status[0x108] == (Status)0x0)))) {
                  pSVar8 = (Station *)Status::getStation(Globals::status);
                  iVar7 = Station::hasAttackedFriends(pSVar8);
                  if (iVar7 == 0) {
                    pSVar22 = (Standing *)Status::getStanding(Globals::status);
                    pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
                    iVar7 = SolarSystem::getRace(pSVar14);
                    iVar7 = Standing::isEnemy(pSVar22,iVar7);
                    if (iVar7 != 1) goto LAB_000e94bc;
                  }
                  AbyssEngine::String::String((String *)&local_d8);
                  pSVar22 = (Standing *)Status::getStanding(Globals::status);
                  pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
                  iVar7 = SolarSystem::getRace(pSVar14);
                  iVar7 = Standing::isEnemy(pSVar22,iVar7);
                  if (iVar7 == 1) {
                    pSVar22 = (Standing *)Status::getStanding(Globals::status);
                    pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
                    uVar31 = SolarSystem::getRace(pSVar14);
                    uVar31 = (uint)((uVar31 | 1) != 1);
                    iVar7 = Standing::getStanding(pSVar22,uVar31);
                    if (iVar7 < 1) {
                      iVar7 = Standing::getStanding(pSVar22,uVar31);
                      iVar7 = -iVar7;
                    }
                    else {
                      iVar7 = Standing::getStanding(pSVar22,uVar31);
                    }
                    fVar40 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
                    *(int *)(in_r0 + 0xd0) = (int)((fVar40 / 100.0) * 2800.0);
                    iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,200);
                    *(int *)(in_r0 + 0xd0) = iVar7 + *(int *)(in_r0 + 0xd0) + -100;
                    iVar7 = Status::hardCoreMode();
                    if (iVar7 == 1) {
                      *(int *)(in_r0 + 0xd0) = *(int *)(in_r0 + 0xd0) * 10;
                    }
                    pSVar19 = (String *)GameText::getText(Globals::gameText,0xcd);
                    AbyssEngine::String::operator=((String *)&local_d8,pSVar19);
                  }
                  else {
                    iVar7 = Status::getLevel(Globals::status);
                    *(int *)(in_r0 + 0xd0) = iVar7 * 0x96 + 1000;
                    iVar7 = Status::hardCoreMode();
                    if (iVar7 == 1) {
                      *(int *)(in_r0 + 0xd0) = *(int *)(in_r0 + 0xd0) * 10;
                    }
                    pSVar19 = (String *)GameText::getText(Globals::gameText,0xce);
                    AbyssEngine::String::operator=((String *)&local_d8,pSVar19);
                  }
                  pSVar3 = Globals::status;
                  AbyssEngine::String::String(aSStack_5c,(String *)&local_d8,false);
                  Layout::formatCredits((int)aSStack_64);
                  uVar10 = AbyssEngine::String::String(aSStack_6c,"#C",false);
                  Status::replaceHash(&local_114,pSVar3,aSStack_5c,aSStack_64,uVar10);
                  AbyssEngine::String::operator=((String *)&local_d8,(String *)&local_114);
                  AbyssEngine::String::~String((String *)&local_114);
                  AbyssEngine::String::~String(aSStack_6c);
                  AbyssEngine::String::~String(aSStack_64);
                  AbyssEngine::String::~String(aSStack_5c);
                  ChoiceWindow::set(*(String **)(in_r0 + 0x6c),(bool)((char)&stack0xffffffdc + 'L'))
                  ;
                  in_r0[0x67] = (ModStation)0x1;
                  in_r0[0x5f] = (ModStation)0x1;
                  in_r0[0xfd] = (ModStation)0x0;
                  AbyssEngine::String::~String((String *)&local_d8);
                }
              }
            }
          }
        }
        else {
          pSVar8 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::getIndex(pSVar8);
          if (iVar7 == 0x58) goto LAB_000e8c12;
          pSVar8 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::stationHasPirateBase(pSVar8);
          if (iVar7 != 1) goto LAB_000e8c12;
          if (*(int *)(in_r0 + 0x80) == 0) {
            pDVar11 = operator_new(0x6c);
            pSVar19 = (String *)GameText::getText(Globals::gameText,0x1b2);
            pSVar12 = (String *)GameText::getText(Globals::gameText,0x649);
            DialogueWindow::DialogueWindow(pDVar11,pSVar19,pSVar12,(int *)&DAT_0026a1c4);
            *(DialogueWindow **)(in_r0 + 0x80) = pDVar11;
            this_00 = operator_new(0x88);
            AbyssEngine::String::String(aSStack_54,"",false);
            Agent::Agent(this_00,0,aSStack_54,0,0,2,1,0,0,0,0);
            AbyssEngine::String::~String(aSStack_54);
            this = Globals::sound;
            iVar7 = Globals::getDialogueSoundId(Globals::globals,0x1b2,this_00);
            FModSound::play(this,iVar7,(Vector *)0x0,(Vector *)0x0,extraout_s0);
            pvVar13 = (void *)Agent::~Agent(this_00);
            operator_delete(pvVar13);
            in_r0[0x65] = (ModStation)0x1;
            in_r0[0xfd] = (ModStation)0x0;
          }
        }
LAB_000e94bc:
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        pMVar26 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar32 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar32 == 0x14) && (iVar32 = Mission::getTargetStation(pMVar26), iVar32 == iVar7)) {
          pSVar8 = (Station *)Status::getStation(Globals::status);
          puVar20 = (uint *)Station::getItems(pSVar8);
          if ((puVar20 != (uint *)0x0) && (*puVar20 != 0)) {
            uVar31 = 0;
            do {
              iVar32 = Item::getIndex(*(Item **)(puVar20[1] + uVar31 * 4));
              if (iVar32 == 0x29) {
                Item::setPrice(*(Item **)(puVar20[1] + uVar31 * 4),0);
              }
              uVar31 = uVar31 + 1;
            } while (uVar31 < *puVar20);
          }
          pSVar8 = (Station *)Status::getStation(Globals::status);
          pIVar27 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xa4),10,0);
          Station::addItem(pSVar8,pIVar27);
        }
        iVar32 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar32 == 0x1b) && (iVar32 = Mission::getTargetStation(pMVar26), iVar32 == iVar7)) {
          pSVar28 = (Ship *)Status::getShip(Globals::status);
          Ship::removeCargo(pSVar28,0x83);
        }
        iVar32 = Status::getCurrentCampaignMission(Globals::status);
        if (iVar32 == 0x2b) {
          if (iVar7 == 10) {
LAB_000e95bc:
            in_r0[0xd5] = (ModStation)0x1;
          }
        }
        else {
          iVar32 = Status::getCurrentCampaignMission(Globals::status);
          if ((iVar7 == 10) && (iVar32 == 0x2c)) goto LAB_000e95bc;
        }
        iVar32 = Status::gameWon(Globals::status);
        if (iVar7 == 10 && iVar32 == 1) {
          pSVar28 = (Ship *)Status::getShip(Globals::status);
          iVar32 = Ship::hasEquipment(pSVar28,0x55,1);
          if (iVar32 == 0) {
            pSVar28 = (Ship *)Status::getShip(Globals::status);
            iVar32 = Ship::hasCargo(pSVar28,0x55,1);
            if (iVar32 == 0) {
              pSVar8 = (Station *)Status::getStation(Globals::status);
              iVar32 = Station::hasItem(pSVar8,0x55);
              if (iVar32 == 0) {
                pSVar8 = (Station *)Status::getStation(Globals::status);
                iVar32 = Station::hasItem(pSVar8,0xa4);
                if (iVar32 == 0) {
                  pSVar8 = (Station *)Status::getStation(Globals::status);
                  pIVar27 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x290),
                                                   0x32);
                  Station::addItem(pSVar8,pIVar27);
                }
              }
            }
          }
        }
        if ((iVar7 - 100U < 2) || (iVar7 == 10)) {
          pSVar28 = (Ship *)Status::getShip(Globals::status);
          pIVar27 = (Item *)Ship::getCargo(pSVar28,0x7a);
          if (pIVar27 == (Item *)0x0) {
            iVar32 = 0;
          }
          else {
            iVar32 = Item::getAmount(pIVar27);
          }
          pSVar8 = (Station *)Status::getStation(Globals::status);
          iVar33 = Station::hasItem(pSVar8,0x7a);
          if ((iVar32 < 6) && (iVar33 == 0)) {
            pSVar8 = (Station *)Status::getStation(Globals::status);
            pIVar27 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x1e8),10);
            Station::addItem(pSVar8,pIVar27);
          }
        }
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar32 = Station::getIndex(pSVar8);
        if ((iVar32 == 10) &&
           (iVar32 = Achievements::gotAllGoldMedals(Globals::achievements), iVar32 == 1)) {
          pSVar8 = (Station *)Status::getStation(Globals::status);
          puVar20 = (uint *)Station::getShips(pSVar8);
          if ((puVar20 != (uint *)0x0) && (*puVar20 != 0)) {
            uVar31 = 0;
            do {
              iVar32 = Ship::getIndex(*(Ship **)(puVar20[1] + uVar31 * 4));
              if (iVar32 == 8) goto LAB_000e9780;
              uVar31 = uVar31 + 1;
            } while (uVar31 < *puVar20);
          }
          pGVar9 = operator_new(1);
          Generator::Generator(pGVar9);
          pSVar8 = (Station *)Status::getStation(Globals::status);
          pSVar29 = (Station *)Status::getStation(Globals::status);
          pAVar17 = (Array *)Generator::getShipBuyList(pGVar9,pSVar29);
          Station::setShips(pSVar8,pAVar17,false);
          pvVar13 = (void *)Generator::~Generator(pGVar9);
          operator_delete(pvVar13);
        }
LAB_000e9780:
        if ((iVar7 == 100) &&
           ((((iVar7 = Status::dlc1Won(Globals::status), iVar7 != 0 ||
              (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x50)) ||
             (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x51)) ||
            (((iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x52 ||
              (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x53)) ||
             (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x54)))))) {
          pSVar8 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::hasShip(pSVar8,0x25);
          if (iVar7 == 0) {
            pSVar28 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x94),-1);
            Station::addShip(pSVar8,pSVar28);
          }
          iVar7 = Station::hasShip(pSVar8,0x26);
          if (iVar7 == 0) {
            pSVar28 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x98),-1);
            Station::addShip(pSVar8,pSVar28);
          }
          iVar7 = Station::hasShip(pSVar8,0x28);
          if (iVar7 == 0) {
            pSVar28 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xa0),-1);
            Station::addShip(pSVar8,pSVar28);
          }
        }
        pSVar8 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar8);
        bVar39 = iVar7 == 0x6c;
        if (bVar39) {
          iVar7 = *(int *)(Globals::status + 0x114);
        }
        if (bVar39 && iVar7 == 1) {
          if (*(DialogueWindow **)(in_r0 + 0x80) != (DialogueWindow *)0x0) {
            pvVar13 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(in_r0 + 0x80));
            operator_delete(pvVar13);
          }
          *(undefined4 *)(in_r0 + 0x80) = 0;
          pMVar26 = operator_new(100);
          pSVar19 = (String *)GameText::getText(Globals::gameText,0x641);
          AbyssEngine::String::String(aSStack_74,pSVar19,false);
          Mission::Mission(pMVar26,0xffffffff,aSStack_74,&DAT_0026a214,4,0,0x6c,0);
          AbyssEngine::String::~String(aSStack_74);
          Mission::setWon(pMVar26,true);
          *(undefined4 *)(Globals::status + 0x114) = 2;
          pDVar11 = operator_new(0x6c);
          DialogueWindow::DialogueWindow(pDVar11,pMVar26,(Level *)0x0,0);
          *(DialogueWindow **)(in_r0 + 0x80) = pDVar11;
          in_r0[0x65] = (ModStation)0x1;
        }
        else {
          pSVar8 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::getIndex(pSVar8);
          if ((iVar7 == 0x6c) && (*(int *)(Globals::status + 0x114) == 2)) {
            iVar7 = Status::getCredits(Globals::status);
            if (iVar7 < 0x1c9c381) {
LAB_000e99be:
              pCVar15 = *(ChoiceWindow **)(in_r0 + 0x6c);
              pSVar19 = (String *)GameText::getText(Globals::gameText,0x1dc);
              ChoiceWindow::set(pCVar15,pSVar19);
            }
            else {
              pSVar28 = (Ship *)Status::getShip(Globals::status);
              iVar7 = Ship::hasCargo(pSVar28,0x6d,0x32);
              if (iVar7 != 1) goto LAB_000e99be;
              pSVar19 = *(String **)(in_r0 + 0x6c);
              bVar39 = (bool)GameText::getText(Globals::gameText,0x1dd);
              ChoiceWindow::set(pSVar19,bVar39);
              in_r0[0x68] = (ModStation)0x1;
            }
            in_r0[0x5f] = (ModStation)0x1;
          }
        }
        pMVar26 = (Mission *)Status::getFreelanceMission(Globals::status);
        if ((pMVar26 != (Mission *)0x0) && (iVar7 = Mission::getType(pMVar26), iVar7 == 0xe)) {
          iVar7 = Mission::getTargetStation(pMVar26);
          pSVar8 = (Station *)Status::getStation(Globals::status);
          iVar32 = Station::getIndex(pSVar8);
          if (iVar7 == iVar32) {
            pSVar8 = (Station *)Status::getStation(Globals::status);
            iVar7 = Station::hasItem(pSVar8,0x73);
            if (iVar7 == 0) {
              pIVar27 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x1cc),1);
              pSVar8 = (Station *)Status::getStation(Globals::status);
              Station::addItem(pSVar8,pIVar27);
            }
          }
        }
        iVar7 = Status::getCurrentCampaignMission(Globals::status);
        if ((iVar7 == 0xa2) && (Globals::hints[0x2b] == '\0')) {
          pCVar15 = *(ChoiceWindow **)(in_r0 + 0x6c);
          pSVar19 = (String *)GameText::getText(Globals::gameText,0x265);
          ChoiceWindow::set(pCVar15,pSVar19);
          in_r0[0x5f] = (ModStation)0x1;
          Globals::hints[0x2b] = '\x01';
        }
        iVar7 = Status::gameWon(Globals::status);
        if ((iVar7 == 1) && (Globals::options[0x35] == '\0' && Globals::hints[0x38] == '\0')) {
          pCVar15 = *(ChoiceWindow **)(in_r0 + 0x6c);
          pSVar19 = (String *)GameText::getText(Globals::gameText,0x6e);
          ChoiceWindow::set(pCVar15,pSVar19);
          in_r0[0x5f] = (ModStation)0x1;
          Globals::hints[0x38] = '\x01';
        }
        iVar7 = Status::dlc1Won(Globals::status);
        if ((iVar7 == 1) && (Globals::options[0x37] == '\0' && Globals::hints[0x39] == '\0')) {
          pCVar15 = *(ChoiceWindow **)(in_r0 + 0x6c);
          pSVar19 = (String *)GameText::getText(Globals::gameText,0x6f);
          ChoiceWindow::set(pCVar15,pSVar19);
          in_r0[0x5f] = (ModStation)0x1;
          Globals::hints[0x39] = '\x01';
        }
        iVar7 = Status::activateNewWanted();
        if ((0 < iVar7) && (in_r0[0x5f] == (ModStation)0x0)) {
          if (iVar7 == 1) {
            pCVar15 = *(ChoiceWindow **)(in_r0 + 0x6c);
            pSVar19 = (String *)GameText::getText(Globals::gameText,0xc9e);
            ChoiceWindow::set(pCVar15,pSVar19);
          }
          else {
            pSVar19 = (String *)GameText::getText(Globals::gameText,0xc9f);
            AbyssEngine::String::String((String *)&local_d8,pSVar19,false);
            pSVar3 = Globals::status;
            AbyssEngine::String::String(aSStack_7c,(String *)&local_d8,false);
            local_98 = 0.0;
            AbyssEngine::String::Set(CONCAT44(extraout_r1,&local_98));
            AbyssEngine::String::String(aSStack_84,(String *)&local_98,false);
            uVar10 = AbyssEngine::String::String(aSStack_8c,"#N",false);
            Status::replaceHash(&local_114,pSVar3,aSStack_7c,aSStack_84,uVar10);
            AbyssEngine::String::operator=((String *)&local_d8,(String *)&local_114);
            AbyssEngine::String::~String((String *)&local_114);
            AbyssEngine::String::~String(aSStack_8c);
            AbyssEngine::String::~String(aSStack_84);
            AbyssEngine::String::~String((String *)&local_98);
            AbyssEngine::String::~String(aSStack_7c);
            ChoiceWindow::set(*(ChoiceWindow **)(in_r0 + 0x6c),(String *)&local_d8);
            AbyssEngine::String::~String((String *)&local_d8);
          }
          in_r0[0x5f] = (ModStation)0x1;
        }
      }
      uVar10 = 0x14;
    }
  }
  else if (iVar7 == 0x3c) {
    *(undefined4 *)(in_r0 + 0xdc) = 0;
    *(undefined4 *)(in_r0 + 0xe4) = 0;
    *(undefined4 *)(in_r0 + 0xec) = 0;
    *(undefined4 *)(in_r0 + 0xf0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    *(undefined4 *)(in_r0 + 0xf4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    *(undefined4 *)(in_r0 + 0xf8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    in_r0[0xfc] = (ModStation)0x0;
    pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar7 = SolarSystem::getRace(pSVar14);
    uVar10 = 0x10e;
    if (iVar7 == 2) {
      uVar10 = 0xffffff38;
    }
    *(undefined4 *)(in_r0 + 0xe0) = uVar10;
    if (*(int *)(in_r0 + 0x14) != 0) {
      fVar40 = (float)VectorSignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(*(int *)(in_r0 + 0x14) + 4) = fVar40 / 120.0;
    }
    *(undefined4 *)(in_r0 + 0xe8) = 0;
    in_r0[0xac] = in_r0[0xaf];
    this_01 = operator_new(0x2c);
    iVar7 = Globals::h;
    iVar37 = *(int *)(in_r0 + 0xa4);
    iVar36 = *(int *)(Globals::layout + 0x10);
    iVar33 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
    iVar32 = Globals::w;
    iVar38 = *(int *)(in_r0 + 0xa4);
    pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar34 = SolarSystem::getRace(pSVar14);
    iVar35 = Status::getCurrentCampaignMission(Globals::status);
    NewsTicker::NewsTicker(this_01,iVar37,(iVar7 - iVar36) - iVar33,iVar32 - iVar38,iVar34,iVar35);
    *(NewsTicker **)(in_r0 + 0x1c) = this_01;
    in_r0[0xad] = (ModStation)0x0;
    in_r0[0xae] = (ModStation)0x0;
    *(undefined4 *)(in_r0 + 0x30) = 0;
    *(undefined4 *)(in_r0 + 0x34) = 0;
    *(undefined4 *)(in_r0 + 0xcc) = 0;
    *(undefined4 *)(in_r0 + 0xd0) = 0;
    *(undefined4 *)(in_r0 + 0xd4) = 0;
    pCVar15 = operator_new(0x54);
    ChoiceWindow::ChoiceWindow(pCVar15);
    *(ChoiceWindow **)(in_r0 + 0x6c) = pCVar15;
    pPVar4 = Globals::Canvas;
    pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar7 = SolarSystem::getRace(pSVar14);
    AbyssEngine::PaintCanvas::Image2DCreate
              (pPVar4,*(ushort *)(&DAT_002547b4 + iVar7 * 4),(uint *)(in_r0 + 0x48));
    uVar10 = 0x28;
  }
  else {
    if (iVar7 == 0x50) {
      *(undefined2 *)(in_r0 + 0x62) = 0;
      *(undefined4 *)(in_r0 + 0x5e) = 0;
      in_r0[0x5d] = (ModStation)0x1;
      in_r0[0x5f] = (ModStation)0x0;
      in_r0[0x5c] = (ModStation)0x0;
      in_r0[0xd8] = (ModStation)0x0;
      in_r0[0xda] = (ModStation)0x0;
      in_r0[0xdb] = (ModStation)0x0;
      in_r0[0x128] = (ModStation)0x0;
      in_r0[0x18] = (ModStation)0x0;
      in_r0[0x6a] = (ModStation)0x0;
      *(undefined2 *)(in_r0 + 0x68) = 0;
      *(undefined4 *)(in_r0 + 100) = 0;
      iVar7 = Globals::layout;
      iVar33 = *(int *)(Globals::layout + 0xcc);
      *(int *)(in_r0 + 0xa4) = iVar33;
      iVar32 = *(int *)(iVar7 + 0xc);
      iVar35 = *(int *)(iVar7 + 0x28);
      iVar37 = *(int *)(iVar7 + 0x4c);
      *(int *)(in_r0 + 0xa8) = (Globals::h - iVar32) - *(int *)(iVar7 + 0x10);
      *(undefined4 *)(in_r0 + 0x9c) = 0;
      *(int *)(in_r0 + 0xa0) = iVar32;
      pTVar16 = operator_new(0xc0);
      AbyssEngine::String::String((String *)&local_d8,"",false);
      TouchButton::TouchButton(pTVar16,(String *)&local_d8,0xc,Globals::w,Globals::h,'\"');
      *(TouchButton **)(in_r0 + 0x8c) = pTVar16;
      AbyssEngine::String::~String((String *)&local_d8);
      pTVar16 = operator_new(0xc0);
      Status::getCredits(Globals::status);
      Layout::formatCredits((int)&local_d8);
      iVar7 = Globals::w;
      iVar32 = TouchButton::getWidth(*(TouchButton **)(in_r0 + 0x8c));
      TouchButton::TouchButton(pTVar16,(String *)&local_d8,0xb,iVar7 - iVar32,Globals::h,'\"');
      *(TouchButton **)(in_r0 + 0x90) = pTVar16;
      AbyssEngine::String::~String((String *)&local_d8);
      pAVar17 = operator_new(0xc);
      puVar18 = operator_new__(4);
      *(undefined4 **)(pAVar17 + 4) = puVar18;
      *(undefined4 *)(pAVar17 + 8) = 1;
      *puVar18 = 0;
      *(undefined4 *)pAVar17 = 0;
      *(Array **)(in_r0 + 0x88) = pAVar17;
      ArraySetLength<TouchButton*>(5,pAVar17);
      iVar7 = Globals::h;
      iVar36 = *(int *)(Globals::layout + 0x10);
      iVar38 = *(int *)(Globals::layout + 0x24);
      iVar34 = *(int *)(Globals::layout + 0x30);
      iVar32 = *(int *)(Globals::layout + 0x34);
      pTVar16 = operator_new(0xc0);
      pSVar19 = (String *)GameText::getText(Globals::gameText,0xa7);
      iVar37 = (iVar33 - iVar35) - iVar37;
      iVar7 = ((iVar7 - iVar36) - iVar38) + iVar34 * -5 + iVar32 * -4;
      TouchButton::TouchButton
                (pTVar16,pSVar19,0,*(int *)(Globals::layout + 0x28),iVar7,iVar37,'\x11','\x01');
      **(undefined4 **)(*(int *)(in_r0 + 0x88) + 4) = pTVar16;
      pTVar16 = operator_new(0xc0);
      pSVar19 = (String *)GameText::getText(Globals::gameText,0x18e);
      TouchButton::TouchButton
                (pTVar16,pSVar19,0,*(int *)(Globals::layout + 0x28),
                 *(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30) + iVar7,iVar37,
                 '\x11','\x01');
      *(TouchButton **)(*(int *)(*(int *)(in_r0 + 0x88) + 4) + 4) = pTVar16;
      pTVar16 = operator_new(0xc0);
      pSVar19 = (String *)GameText::getText(Globals::gameText,0xb1);
      TouchButton::TouchButton
                (pTVar16,pSVar19,0,*(int *)(Globals::layout + 0x28),
                 iVar7 + (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30)) * 2,
                 iVar37,'\x11','\x01');
      *(TouchButton **)(*(int *)(*(int *)(in_r0 + 0x88) + 4) + 8) = pTVar16;
      pTVar16 = operator_new(0xc0);
      pSVar19 = (String *)GameText::getText(Globals::gameText,0x81);
      TouchButton::TouchButton
                (pTVar16,pSVar19,0,*(int *)(Globals::layout + 0x28),
                 (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30)) * 3 + iVar7,
                 iVar37,'\x11','\x01');
      *(TouchButton **)(*(int *)(*(int *)(in_r0 + 0x88) + 4) + 0xc) = pTVar16;
      pTVar16 = operator_new(0xc0);
      pSVar19 = (String *)GameText::getText(Globals::gameText,0xa9);
      TouchButton::TouchButton
                (pTVar16,pSVar19,0,*(int *)(Globals::layout + 0x28),
                 iVar7 + (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30)) * 4,
                 iVar37,'\x11','\x01');
      *(TouchButton **)(*(int *)(*(int *)(in_r0 + 0x88) + 4) + 0x10) = pTVar16;
      uVar10 = 0x3c;
      *(undefined4 *)(in_r0 + 0xc) = 0x3c;
      goto LAB_000e9c42;
    }
    if (iVar7 != 100) goto LAB_000e89d0;
    Globals::startNewSoundResourceList(Globals::globals);
    Globals::addSoundResourceToList(Globals::globals,0x5f);
    Globals::addSoundResourceToList(Globals::globals,0x7a);
    Globals::addSoundResourceToList(Globals::globals,0x6c);
    Globals::addSoundResourceToList(Globals::globals,0x60);
    Globals::addSoundResourceToList(Globals::globals,0x61);
    Globals::addSoundResourceToList(Globals::globals,0x62);
    Globals::addSoundResourceToList(Globals::globals,99);
    Globals::addSoundResourceToList(Globals::globals,0x65);
    Globals::addSoundResourceToList(Globals::globals,100);
    Globals::addSoundResourceToList(Globals::globals,0x66);
    Globals::addSoundResourceToList(Globals::globals,0x68);
    Globals::addSoundResourceToList(Globals::globals,0x69);
    Globals::addSoundResourceToList(Globals::globals,0x6a);
    Globals::addSoundResourceToList(Globals::globals,0x6b);
    Globals::addSoundResourceToList(Globals::globals,0x67);
    Globals::addSoundResourceToList(Globals::globals,0x7e);
    in_r0[0xfd] = (ModStation)0x1;
    *(undefined4 *)(in_r0 + 200) = 0x32;
    Status::getStation(Globals::status);
    Station::getName();
    AbyssEngine::String::operator=((String *)(in_r0 + 0x38),(String *)&local_d8);
    AbyssEngine::String::~String((String *)&local_d8);
    lVar2 = *(longlong *)(Globals::status + 0x70);
    lVar47 = Status::getPlayingTime(Globals::status);
    if ((int)(uint)((uint)(lVar47 - lVar2) < 0x7531) <= (int)((ulonglong)(lVar47 - lVar2) >> 0x20))
    {
      pSVar8 = (Station *)Status::getStation(Globals::status);
      iVar7 = Station::getIndex(pSVar8);
      if (iVar7 != 0x6c) {
        pGVar9 = operator_new(1);
        Generator::Generator(pGVar9);
        pSVar8 = (Station *)Status::getStation(Globals::status);
        Generator::computerTradeGoods(pGVar9,pSVar8);
      }
    }
    uVar10 = 0x50;
  }
  *(undefined4 *)(in_r0 + 0xc) = uVar10;
LAB_000e9c42:
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}

// ===== ModStation::autosave  @0x000e9eb4  (88 bytes)
/* ModStation::autosave() */

void __thiscall ModStation::autosave(ModStation *this)

{
  RecordHandler *this_00;
  void *pvVar1;
  undefined8 uVar2;
  
  uVar2 = Status::getPlayingTime(Globals::status);
  if ((int)((ulonglong)uVar2 >> 0x20) < (int)(uint)((int)uVar2 == 0)) {
    return;
  }
  this_00 = operator_new(0x20);
  RecordHandler::RecordHandler(this_00);
  RecordHandler::recordStoreWrite(this_00,0);
  RecordHandler::recordStoreWritePreview(this_00,0);
  pvVar1 = (void *)RecordHandler::~RecordHandler(this_00);
  operator_delete(pvVar1);
  this[0xad] = (ModStation)0x1;
  if (*(MenuTouchWindow **)(this + 0x4c) == (MenuTouchWindow *)0x0) {
    return;
  }
  MenuTouchWindow::loadPreviewRecords(*(MenuTouchWindow **)(this + 0x4c));
  return;
}

// ===== ModStation::resetLight  @0x000e9f1c  (350 bytes)
/* ModStation::resetLight() */

void __thiscall ModStation::resetLight(ModStation *this)

{
  Engine *pEVar1;
  SolarSystem *this_00;
  undefined4 uVar2;
  uint uVar3;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
  float fVar4;
  float extraout_s0_07;
  float extraout_s0_08;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float fVar5;
  float extraout_s1_07;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  float fVar6;
  float extraout_s2_07;
  
  pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorAmbient(pEVar1,extraout_s0,extraout_s1,extraout_s2);
  pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightDirection
            (pEVar1,extraout_s0_00,extraout_s1_00,extraout_s2_00,
             *(uint *)(this + 0x118) ^ 0x80000000);
  pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorDiffuse
            (pEVar1,extraout_s0_01,extraout_s1_01,extraout_s2_01,0x3f800000);
  this_00 = (SolarSystem *)Status::getSystem(Globals::status);
  uVar2 = SolarSystem::getRace(this_00);
  switch(uVar2) {
  case 1:
    pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    uVar3 = 0x3e800000;
    fVar4 = extraout_s0_02;
    fVar5 = extraout_s1_02;
    fVar6 = extraout_s2_02;
    break;
  case 2:
    pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    uVar3 = 0x3e19999a;
    fVar4 = extraout_s0_03;
    fVar5 = extraout_s1_03;
    fVar6 = extraout_s2_03;
    break;
  case 3:
    pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    uVar3 = 0x3ee66666;
    fVar4 = extraout_s0_04;
    fVar5 = extraout_s1_04;
    fVar6 = extraout_s2_04;
    break;
  default:
    pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    uVar3 = 0x3e800000;
    fVar4 = extraout_s0_05;
    fVar5 = extraout_s1_05;
    fVar6 = extraout_s2_05;
    break;
  case 8:
    pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    uVar3 = 0x3f547ae1;
    fVar4 = extraout_s0_06;
    fVar5 = extraout_s1_06;
    fVar6 = extraout_s2_06;
  }
  AbyssEngine::Engine::LightSetLightColorAmbient(pEVar1,fVar4,fVar5,fVar6,uVar3);
  pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorSpecular
            (pEVar1,extraout_s0_07,extraout_s1_07,extraout_s2_07,0x3f000000);
  pEVar1 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorShininess(pEVar1,extraout_s0_08);
  return;
}

// ===== ModStation::enterStation  @0x000ea0a0  (162 bytes)
/* ModStation::enterStation() */

void ModStation::enterStation(void)

{
  Station *pSVar1;
  Ship *pSVar2;
  Item *this;
  Item *this_00;
  undefined4 uVar3;
  Status *pSVar4;
  
  pSVar4 = Globals::status;
  pSVar1 = (Station *)Status::getStation(Globals::status);
  Status::departStation(pSVar4,pSVar1);
  pSVar1 = (Station *)Status::getStation(Globals::status);
  Station::visit(pSVar1);
  Achievements::applyNewMedals(Globals::achievements);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  this = (Item *)Ship::getFirstEquipmentOfSort(pSVar2,10);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  this_00 = (Item *)Ship::getFirstEquipmentOfSort(pSVar2,9);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  uVar3 = Ship::getIndex(pSVar2);
  pSVar4 = Globals::status;
  *(undefined4 *)(Globals::status + 0x150) = uVar3;
  if (this == (Item *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = Item::getIndex(this);
    pSVar4 = Globals::status;
  }
  *(undefined4 *)(pSVar4 + 0x154) = uVar3;
  if (this_00 == (Item *)0x0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = Item::getIndex(this_00);
    pSVar4 = Globals::status;
  }
  *(undefined4 *)(pSVar4 + 0x158) = uVar3;
  *(undefined4 *)(pSVar4 + 0x124) = 0;
  *(undefined4 *)(pSVar4 + 0x11c) = 0;
  return;
}

// ===== ModStation::OnTouchBegin  @0x000ea154  (464 bytes)
/* ModStation::OnTouchBegin(int, int, void*) */

void __thiscall ModStation::OnTouchBegin(ModStation *this,int param_1,int param_2,void *param_3)

{
  int iVar1;
  ChoiceWindow *this_00;
  uint uVar2;
  
  if (*(int *)(this + 0x124) == 0) {
    *(void **)(this + 0x124) = param_3;
    this[0x114] = (ModStation)0x1;
    *(int *)(this + 0x10c) = param_1;
    *(int *)(this + 0x110) = param_2;
    uVar2 = *(uint *)(this + 0x5c);
    if ((uVar2 & 0xff) == 0) {
      if (*Globals::layout != (Layout)0x0) {
        Layout::OnTouchBegin(Globals::layout,param_1,param_2);
        return;
      }
      if (this[0x65] != (ModStation)0x0) {
        DialogueWindow::OnTouchBegin(*(DialogueWindow **)(this + 0x80),param_1,param_2);
        return;
      }
      if (uVar2 < 0x1000000) {
        if (this[0x66] == (ModStation)0x0) {
          if ((*(ushort *)(this + 0x62) & 0xff) != 0) {
            HangarWindow::OnTouchBegin(*(HangarWindow **)(this + 0x74),param_1,param_2);
            return;
          }
          if (this[0x61] != (ModStation)0x0) {
            SpaceLounge::OnTouchBegin(*(SpaceLounge **)(this + 0x70),param_1,param_2);
            return;
          }
          if (0xff < *(ushort *)(this + 0x62)) {
            StarMap::OnTouchBegin(*(StarMap **)(this + 0x10),param_1,param_2);
            return;
          }
          if (this[100] != (ModStation)0x0) {
            (*(code *)&LAB_0006d970)(*(undefined4 *)(this + 0x78),param_1,param_2);
            return;
          }
          if (this[0x60] != (ModStation)0x0) {
            MissionsWindow::OnTouchBegin(*(MissionsWindow **)(this + 0x7c),param_1,param_2);
            return;
          }
          if ((uVar2 & 0xff0000) != 0) {
            MenuTouchWindow::OnTouchBegin(*(int *)(this + 0x4c),param_1,(void *)param_2);
            return;
          }
          if (*(ushort *)(this + 0x5c) < 0x100) {
            return;
          }
          TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x8c),param_1,param_2);
          TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x90),param_1,param_2);
          iVar1 = 0;
          do {
            TouchButton::OnTouchBegin
                      (*(TouchButton **)(*(int *)(*(int *)(this + 0x88) + 4) + iVar1 * 4),param_1,
                       param_2);
            iVar1 = iVar1 + 1;
          } while (iVar1 != 5);
          Layout::OnTouchBegin(Globals::layout,param_1,param_2);
          iVar1 = NewsTicker::OnTouchBegin(*(NewsTicker **)(this + 0x1c),param_1,param_2);
          if (iVar1 != 0) {
            return;
          }
          if (param_2 <= *(int *)(Globals::layout + 0xc)) {
            return;
          }
          if (Globals::h - *(int *)(Globals::layout + 0x10) <= param_2) {
            return;
          }
          if (param_1 <= *(int *)(this + 0xa4)) {
            return;
          }
          *(int *)(this + 0xe4) = param_1;
          *(int *)(this + 0xf8) = param_1;
          *(undefined4 *)(this + 0xec) = 0;
          this[0xfc] = (ModStation)0x1;
          return;
        }
        this_00 = *(ChoiceWindow **)(this + 0x84);
      }
      else {
        this_00 = *(ChoiceWindow **)(this + 0x6c);
      }
      ChoiceWindow::OnTouchBegin(this_00,param_1,param_2);
      return;
    }
    iVar1 = Radio::lastMessageShown(*(Radio **)(this + 0x50));
    if (iVar1 == 1) {
      this[0x24] = (ModStation)0x0;
      Status::nextCampaignMission(SUB41(Globals::status,0));
      Globals::switch_to_target_setting = 0;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
      this[0x5c] = (ModStation)0x0;
      return;
    }
  }
  return;
}

// ===== ModStation::OnTouchMove  @0x000ea340  (418 bytes)
/* ModStation::OnTouchMove(int, int, void*) */

void __thiscall ModStation::OnTouchMove(ModStation *this,int param_1,int param_2,void *param_3)

{
  ChoiceWindow *this_00;
  uint uVar1;
  int iVar2;
  
  if (*(void **)(this + 0x124) == param_3) {
    *(int *)(this + 0x10c) = param_1;
    *(int *)(this + 0x110) = param_2;
    uVar1 = *(uint *)(this + 0x5c);
    if ((uVar1 & 0xff) == 0) {
      if (*Globals::layout != (Layout)0x0) {
        Layout::OnTouchMove(Globals::layout,param_1,param_2);
        return;
      }
      if (this[0x65] != (ModStation)0x0) {
        DialogueWindow::OnTouchMove(*(DialogueWindow **)(this + 0x80),param_1,param_2);
        return;
      }
      if (uVar1 < 0x1000000) {
        if (this[0x66] == (ModStation)0x0) {
          if ((*(ushort *)(this + 0x62) & 0xff) != 0) {
            HangarWindow::OnTouchMove(*(HangarWindow **)(this + 0x74),param_1,param_2);
            return;
          }
          if (0xff < *(ushort *)(this + 0x62)) {
            StarMap::OnTouchMove(*(StarMap **)(this + 0x10),param_1,param_2);
            return;
          }
          if (this[0x61] != (ModStation)0x0) {
            SpaceLounge::OnTouchMove(*(SpaceLounge **)(this + 0x70),param_1,param_2);
            return;
          }
          if (this[100] != (ModStation)0x0) {
            StatusWindow::OnTouchMove(*(StatusWindow **)(this + 0x78),param_1,param_2);
            return;
          }
          if (this[0x60] != (ModStation)0x0) {
            MissionsWindow::OnTouchMove(*(MissionsWindow **)(this + 0x7c),param_1,param_2);
            return;
          }
          if ((uVar1 & 0xff0000) != 0) {
            MenuTouchWindow::OnTouchMove(*(MenuTouchWindow **)(this + 0x4c),param_1,param_2,param_3)
            ;
            return;
          }
          if (*(ushort *)(this + 0x5c) < 0x100) {
            return;
          }
          TouchButton::OnTouchMove(*(TouchButton **)(this + 0x8c),param_1,param_2);
          TouchButton::OnTouchMove(*(TouchButton **)(this + 0x90),param_1,param_2);
          iVar2 = 0;
          do {
            TouchButton::OnTouchMove
                      (*(TouchButton **)(*(int *)(*(int *)(this + 0x88) + 4) + iVar2 * 4),param_1,
                       param_2);
            iVar2 = iVar2 + 1;
          } while (iVar2 != 5);
          Layout::OnTouchMove(Globals::layout,param_1,param_2);
          iVar2 = NewsTicker::OnTouchMove(*(int *)(this + 0x1c),param_1);
          if (iVar2 != 0) {
            return;
          }
          if (param_2 <= *(int *)(Globals::layout + 0xc)) {
            return;
          }
          if (Globals::h - *(int *)(Globals::layout + 0x10) <= param_2) {
            return;
          }
          if (*(int *)(this + 0xa4) < param_1) {
            iVar2 = *(int *)(this + 0xe4);
            *(int *)(this + 0xec) = param_1 - iVar2;
            *(int *)(this + 0xe4) = param_1;
            *(undefined4 *)(this + 0xf0) = 0x3f800000;
            *(int *)(this + 0xe0) = (param_1 - iVar2) + *(int *)(this + 0xe0);
            return;
          }
          return;
        }
        this_00 = *(ChoiceWindow **)(this + 0x84);
      }
      else {
        this_00 = *(ChoiceWindow **)(this + 0x6c);
      }
      ChoiceWindow::OnTouchMove(this_00,param_1,param_2);
      return;
    }
  }
  return;
}

// ===== ModStation::OnTouchEnd  @0x000ea4ec  (5752 bytes)
/* ModStation::OnTouchEnd(int, int, void*) */

void __thiscall ModStation::OnTouchEnd(ModStation *this,int param_1,int param_2,void *param_3)

{
  Layout *pLVar1;
  char cVar2;
  char cVar3;
  ModStation MVar4;
  int iVar5;
  int iVar6;
  Ship *pSVar7;
  Status *pSVar8;
  Radio *this_00;
  Array *pAVar9;
  undefined4 *puVar10;
  RadioMessage *pRVar11;
  ScrollTouchBox *this_01;
  String *pSVar12;
  uint uVar13;
  Station *pSVar14;
  int *piVar15;
  uint *puVar16;
  void *pvVar17;
  Item *pIVar18;
  MenuTouchWindow *this_02;
  ApplicationManager *pAVar19;
  char *pcVar20;
  Agent *this_03;
  ChoiceWindow *this_04;
  uint uVar21;
  HangarWindow *this_05;
  CutScene *pCVar22;
  uint in_fpscr;
  float fVar23;
  float extraout_s0;
  float extraout_s0_00;
  undefined4 uVar24;
  undefined4 uVar25;
  String aSStack_c4 [12];
  float local_b8;
  float local_b0;
  float local_a0;
  float local_98;
  float local_88;
  float local_80;
  String aSStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  String aSStack_4c [8];
  String aSStack_44 [8];
  String aSStack_3c [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar13 = Globals::sub_menu_button_count;
  if (*(void **)(this + 0x124) == param_3) {
    *(undefined4 *)(this + 0x124) = 0;
    this[0x114] = (ModStation)0x0;
    uVar13 = Globals::sub_menu_button_count;
    if ((*(uint *)(this + 0x5c) & 0xff) == 0) {
      if (*Globals::layout == (Layout)0x0) {
        if (this[0x65] == (ModStation)0x0) {
          uVar13 = *(uint *)(this + 0x5c) >> 0x18;
        }
        else {
          iVar5 = DialogueWindow::OnTouchEnd(*(DialogueWindow **)(this + 0x80),param_1,param_2);
          if (iVar5 == 1) {
            if (*(Mission **)(this + 0x98) != (Mission *)0x0) {
              iVar5 = Mission::getType(*(Mission **)(this + 0x98));
              iVar6 = Mission::isCampaignMission(*(Mission **)(this + 0x98));
              if (iVar5 == 8) {
                if (iVar6 == 0) {
                  pSVar7 = (Ship *)Status::getShip(Globals::status);
                  iVar5 = Mission::getProductionGoodIndex(*(Mission **)(this + 0x98));
                  iVar6 = Mission::getProductionGoodAmount(*(Mission **)(this + 0x98));
                  Ship::removeCargo(pSVar7,iVar5,iVar6);
                  goto LAB_000ea5ba;
                }
              }
              else if ((iVar6 == 0) &&
                      (iVar5 = Mission::getType(*(Mission **)(this + 0x98)), iVar5 == 0xb)) {
                Status::setPassengers(Globals::status,0);
                iVar5 = Mission::isCampaignMission(*(Mission **)(this + 0x98));
                pSVar8 = Globals::status;
                if (iVar5 != 1) {
                  iVar5 = Mission::getProductionGoodAmount(*(Mission **)(this + 0x98));
                  pSVar8 = Globals::status;
                  *(int *)(Globals::status + 0xb8) = iVar5 + *(int *)(Globals::status + 0xb8);
                }
                pSVar7 = (Ship *)Status::getShip(pSVar8);
                puVar16 = (uint *)Ship::getCargo(pSVar7);
                uVar13 = 0;
                if (puVar16 != (uint *)0x0) {
                  uVar13 = *puVar16;
                }
                if (puVar16 != (uint *)0x0 && uVar13 != 0) {
                  uVar13 = 0;
                  do {
                    iVar5 = Item::isUnsaleable(*(Item **)(puVar16[1] + uVar13 * 4));
                    if ((iVar5 == 1) &&
                       ((iVar5 = Item::getIndex(*(Item **)(puVar16[1] + uVar13 * 4)), iVar5 == 0x74
                        || (iVar5 = Item::getIndex(*(Item **)(puVar16[1] + uVar13 * 4)),
                           iVar5 == 0x75)))) goto LAB_000ea7d2;
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < *puVar16);
                }
              }
              else {
                iVar5 = Mission::getType(*(Mission **)(this + 0x98));
                if ((iVar5 != 3) &&
                   ((iVar5 = Mission::getType(*(Mission **)(this + 0x98)), iVar5 != 5 &&
                    (iVar5 = Mission::getType(*(Mission **)(this + 0x98)), iVar5 != 0xb)))) {
                  iVar5 = Mission::getType(*(Mission **)(this + 0x98));
                  if (iVar5 == 0) {
                    pSVar7 = (Ship *)Status::getShip(Globals::status);
                    puVar16 = (uint *)Ship::getCargo(pSVar7);
                    uVar13 = 0;
                    if (puVar16 != (uint *)0x0) {
                      uVar13 = *puVar16;
                    }
                    if (puVar16 != (uint *)0x0 && uVar13 != 0) {
                      uVar13 = 0;
                      do {
                        iVar5 = Item::isUnsaleable(*(Item **)(puVar16[1] + uVar13 * 4));
                        if ((iVar5 == 1) &&
                           ((iVar5 = Item::getIndex(*(Item **)(puVar16[1] + uVar13 * 4)),
                            iVar5 == 0x74 ||
                            (iVar5 = Item::getIndex(*(Item **)(puVar16[1] + uVar13 * 4)),
                            iVar5 == 0x75)))) {
                          pSVar7 = (Ship *)Status::getShip(Globals::status);
                          Ship::removeCargo(pSVar7,*(Item **)(puVar16[1] + uVar13 * 4));
                          if (*(HangarWindow **)(this + 0x74) != (HangarWindow *)0x0) {
                            HangarWindow::initialize(*(HangarWindow **)(this + 0x74));
                          }
                          break;
                        }
                        uVar13 = uVar13 + 1;
                      } while (uVar13 < *puVar16);
                    }
                    iVar5 = Mission::getProductionGoodAmount(*(Mission **)(this + 0x98));
                    *(int *)(Globals::status + 0x9c) = iVar5 + *(int *)(Globals::status + 0x9c);
                  }
                  else {
                    iVar5 = Mission::getType(*(Mission **)(this + 0x98));
                    if (iVar5 == 0xe) {
                      pSVar7 = (Ship *)Status::getShip(Globals::status);
                      puVar16 = (uint *)Ship::getCargo(pSVar7);
                      uVar13 = 0;
                      if (puVar16 != (uint *)0x0) {
                        uVar13 = *puVar16;
                      }
                      if (puVar16 != (uint *)0x0 && uVar13 != 0) {
                        uVar13 = 0;
                        do {
                          iVar5 = Item::getIndex(*(Item **)(puVar16[1] + uVar13 * 4));
                          if (iVar5 == 0x73) goto LAB_000ea7d2;
                          uVar13 = uVar13 + 1;
                        } while (uVar13 < *puVar16);
                      }
                    }
                  }
                }
              }
              goto LAB_000ea886;
            }
            this[0x65] = (ModStation)0x0;
            if (*(DialogueWindow **)(this + 0x80) != (DialogueWindow *)0x0) {
              pvVar17 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x80));
              operator_delete(pvVar17);
            }
            *(undefined4 *)(this + 0x80) = 0;
            uVar13 = Globals::sub_menu_button_count;
            if (this[0xfd] == (ModStation)0x0) {
              pSVar14 = (Station *)Status::getStation(Globals::status);
              iVar5 = Station::getIndex(pSVar14);
              uVar13 = Globals::sub_menu_button_count;
              if (iVar5 != 4) {
                pSVar14 = (Station *)Status::getStation(Globals::status);
                iVar5 = Station::getIndex(pSVar14);
                uVar13 = Globals::sub_menu_button_count;
                if (iVar5 != 0x58) {
                  pSVar14 = (Station *)Status::getStation(Globals::status);
                  iVar5 = Station::stationHasPirateBase(pSVar14);
                  uVar13 = Globals::sub_menu_button_count;
                  if (iVar5 == 1) {
                    this[0xae] = (ModStation)0x0;
                    pSVar8 = Globals::status;
                    pSVar14 = (Station *)Status::getStation(Globals::status);
                    Status::departStation(pSVar8,pSVar14);
                    Achievements::resetNewMedals(Globals::achievements);
                    iVar5 = Status::getCurrentCampaignMission(Globals::status);
                    Globals::switch_to_target_setting = 1;
                    if (iVar5 == 0x10) {
                      Globals::switch_to_target_setting = 0xffffffff;
                    }
                    AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                              (Globals::appManager,2);
                    this[0x24] = (ModStation)0x0;
                    uVar13 = Globals::sub_menu_button_count;
                  }
                }
              }
            }
            goto LAB_000eb23a;
          }
LAB_000eabd0:
          uVar13 = Globals::sub_menu_button_count;
          if (this[0x61] != (ModStation)0x0) goto LAB_000eb23a;
          uVar13 = (uint)(byte)this[0x5f];
        }
        if (uVar13 == 0) {
          if (this[0x66] == (ModStation)0x0) {
            if ((*(ushort *)(this + 0x62) & 0xff) == 0) {
              if (*(ushort *)(this + 0x62) < 0x100) {
                if (this[0x61] == (ModStation)0x0) {
                  if (this[100] == (ModStation)0x0) {
                    if (this[0x60] == (ModStation)0x0) {
                      if (this[0x5e] == (ModStation)0x0) {
                        uVar13 = Globals::sub_menu_button_count;
                        if (this[0x5d] != (ModStation)0x0) {
                          iVar5 = TouchButton::OnTouchEnd
                                            (*(TouchButton **)(this + 0x8c),param_1,param_2);
                          if (iVar5 == 1) {
                            if (__stack_chk_guard == local_28) {
                              leaveStation(this);
                              return;
                            }
                            goto LAB_000eb24a;
                          }
                          iVar5 = TouchButton::OnTouchEnd
                                            (*(TouchButton **)(this + 0x90),param_1,param_2);
                          if (iVar5 == 1) {
                            Globals::options[0x4e] = 1;
                            RecordHandler::saveOptions(Globals::recordHandler);
                            this_05 = *(HangarWindow **)(this + 0x74);
                            if (this_05 == (HangarWindow *)0x0) {
                              this_05 = operator_new(0x134);
                              HangarWindow::HangarWindow(this_05);
                              *(HangarWindow **)(this + 0x74) = this_05;
                            }
                            HangarWindow::initialize(this_05);
                            FUN_002619a4();
                            this[0x18] = (ModStation)0x1;
                            HangarWindow::showCreditsBuyWindow(*(HangarWindow **)(this + 0x74));
                          }
                          iVar5 = 0;
                          *(undefined4 *)(this + 0x40) = 0xffffffff;
                          do {
                            iVar6 = TouchButton::OnTouchEnd
                                              (*(TouchButton **)
                                                (*(int *)(*(int *)(this + 0x88) + 4) + iVar5 * 4),
                                               param_1,param_2);
                            if (iVar6 == 1) {
                              *(int *)(this + 0x40) = iVar5;
                              (**(code **)(*(int *)this + 0x10))
                                        (this,*(code **)(*(int *)this + 0x10),0x10000,0);
                              uVar13 = Globals::sub_menu_button_count;
                              goto LAB_000eb23a;
                            }
                            iVar5 = iVar5 + 1;
                          } while (iVar5 < 5);
                          iVar5 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
                          if (iVar5 == 1) {
                            if (*(int *)(this + 0x4c) == 0) {
                              this_02 = operator_new(0x240);
                              MenuTouchWindow::MenuTouchWindow(this_02,2);
                              *(MenuTouchWindow **)(this + 0x4c) = this_02;
                            }
                            Status::checkForLevelUp(Globals::status);
                            this[0x5e] = (ModStation)0x1;
                            iVar5 = *(int *)(this + 0x4c);
                            if (**(int **)(iVar5 + 4) == 0) {
                              uVar13 = 0;
                            }
                            else {
                              uVar21 = 0;
                              do {
                                if ((int)uVar21 < 10) {
                                  TouchButton::getPosition();
                                  *(int *)(Globals::sub_menu_buttons_x + uVar21 * 4) = (int)local_b0
                                  ;
                                  TouchButton::getPosition();
                                  *(int *)(Globals::sub_menu_buttons_y + uVar21 * 4) = (int)local_b8
                                  ;
                                  iVar5 = *(int *)(this + 0x4c);
                                }
                                uVar21 = uVar21 + 1;
                                uVar13 = **(uint **)(iVar5 + 4);
                              } while (uVar21 < **(uint **)(iVar5 + 4));
                            }
                          }
                          else {
                            iVar5 = Layout::helpPressed(Globals::layout);
                            pLVar1 = Globals::layout;
                            if (iVar5 == 1) {
                              pSVar12 = (String *)GameText::getText(Globals::gameText,0x284);
                              AbyssEngine::String::String(aSStack_c4,pSVar12,false);
                              Layout::initHelpWindow(pLVar1,aSStack_c4);
                              AbyssEngine::String::~String(aSStack_c4);
                            }
                            iVar5 = NewsTicker::OnTouchEnd(*(int *)(this + 0x1c),param_1);
                            uVar13 = Globals::sub_menu_button_count;
                            if (iVar5 == 0) {
                              iVar6 = *(int *)(this + 0xec);
                              uVar25 = VectorSignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
                              iVar5 = iVar6;
                              if (iVar6 < 0) {
                                iVar5 = -iVar6;
                              }
                              uVar24 = 0;
                              if (3 < iVar5) {
                                uVar24 = uVar25;
                              }
                              *(undefined4 *)(this + 0xf4) = uVar24;
                              *(undefined4 *)(this + 0xf0) = 0x3f666666;
                              this[0xfc] = (ModStation)0x0;
                              iVar5 = *(int *)(this + 0xe0);
                              *(int *)(this + 0xe0) = iVar6 + iVar5;
                              *(int *)(this + 0xe8) = iVar6 + iVar5;
                              uVar13 = Globals::sub_menu_button_count;
                            }
                          }
                        }
                      }
                      else {
                        iVar5 = MenuTouchWindow::OnTouchEnd
                                          (*(MenuTouchWindow **)(this + 0x4c),param_1,param_2,
                                           param_3);
                        uVar13 = Globals::sub_menu_button_count;
                        if (iVar5 == 1) {
                          this[0x5e] = (ModStation)0x0;
                          puVar16 = *(uint **)(this + 0x88);
                          uVar13 = 0;
                          if (*puVar16 != 0) {
                            uVar21 = 0;
                            do {
                              if ((int)uVar21 < 10) {
                                TouchButton::getPosition();
                                *(int *)(Globals::sub_menu_buttons_x + uVar21 * 4) = (int)local_98;
                                TouchButton::getPosition();
                                *(int *)(Globals::sub_menu_buttons_y + uVar21 * 4) = (int)local_a0;
                                puVar16 = *(uint **)(this + 0x88);
                              }
                              uVar21 = uVar21 + 1;
                              uVar13 = *puVar16;
                            } while (uVar21 < *puVar16);
                          }
                        }
                      }
                    }
                    else {
                      iVar5 = MissionsWindow::OnTouchEnd
                                        (*(MissionsWindow **)(this + 0x7c),param_1,param_2);
                      uVar13 = Globals::sub_menu_button_count;
                      if (iVar5 == 1) {
                        this[0x60] = (ModStation)0x0;
                        FModSound::setParamValue((int)Globals::sound,0,extraout_s0_00);
                        if (__stack_chk_guard == local_28) {
                          resetLight(this);
                          return;
                        }
                        goto LAB_000eb24a;
                      }
                    }
                  }
                  else {
                    iVar5 = StatusWindow::OnTouchEnd
                                      (*(StatusWindow **)(this + 0x78),param_1,param_2);
                    uVar13 = Globals::sub_menu_button_count;
                    if (iVar5 == 1) {
                      this[100] = (ModStation)0x0;
                      fVar23 = extraout_s0;
                      goto LAB_000eb04a;
                    }
                  }
                }
                else {
                  iVar5 = SpaceLounge::OnTouchEnd(*(SpaceLounge **)(this + 0x70),param_1,param_2);
                  uVar13 = Globals::sub_menu_button_count;
                  if (iVar5 == 1) {
                    this[0x61] = (ModStation)0x0;
                    resetIdleCamForHangar();
                    fVar23 = (float)resetLight(this);
                    FModSound::setParamValue((int)Globals::sound,0,fVar23);
                    fVar23 = (float)FModSound::stop(Globals::sound,0x6c);
                    FModSound::play(Globals::sound,0x7a,(Vector *)0x0,(Vector *)0x0,fVar23);
                    CutScene::checkForTurret(*(CutScene **)(this + 0x14));
                    uVar13 = Globals::sub_menu_button_count;
                    if ((*(SpaceLounge **)(this + 0x70) != (SpaceLounge *)0x0) &&
                       (iVar5 = SpaceLounge::hangarNeedsUpdate(*(SpaceLounge **)(this + 0x70)),
                       uVar13 = Globals::sub_menu_button_count, iVar5 == 1)) {
                      if (*(HangarWindow **)(this + 0x74) != (HangarWindow *)0x0) {
                        pvVar17 = (void *)HangarWindow::~HangarWindow
                                                    (*(HangarWindow **)(this + 0x74));
                        operator_delete(pvVar17);
                      }
                      *(undefined4 *)(this + 0x74) = 0;
                      uVar13 = Globals::sub_menu_button_count;
                    }
                  }
                }
              }
              else {
                iVar5 = StarMap::OnTouchEnd(*(StarMap **)(this + 0x10),param_1,param_2);
                uVar13 = Globals::sub_menu_button_count;
                if (iVar5 == 1) {
                  this[99] = (ModStation)0x0;
                  fVar23 = (float)resetLight(this);
LAB_000eb04a:
                  if (__stack_chk_guard == local_28) {
                    FModSound::setParamValue((int)Globals::sound,0,fVar23);
                    return;
                  }
                  goto LAB_000eb24a;
                }
              }
            }
            else {
              iVar5 = HangarWindow::OnTouchEnd(*(HangarWindow **)(this + 0x74),param_1,param_2);
              uVar13 = Globals::sub_menu_button_count;
              if (iVar5 == 1) {
                pSVar7 = (Ship *)Status::getShip(Globals::status);
                puVar16 = (uint *)Ship::getCargo(pSVar7);
                if ((puVar16 == (uint *)0x0) || (*puVar16 == 0)) {
                  iVar5 = 0;
                }
                else {
                  uVar13 = 0;
                  iVar5 = 0;
                  do {
                    iVar6 = Item::getIndex(*(Item **)(puVar16[1] + uVar13 * 4));
                    if ((0x83 < iVar6) &&
                       (iVar6 = Item::getIndex(*(Item **)(puVar16[1] + uVar13 * 4)), iVar6 < 0x9a))
                    {
                      iVar6 = Item::getAmount(*(Item **)(puVar16[1] + uVar13 * 4));
                      iVar5 = iVar5 + iVar6;
                    }
                    uVar13 = uVar13 + 1;
                  } while (uVar13 < *puVar16);
                }
                if (*(int *)(this + 0xcc) < iVar5) {
                  *(int *)(Globals::status + 0xa8) =
                       (iVar5 - *(int *)(this + 0xcc)) + *(int *)(Globals::status + 0xa8);
                }
                HangarWindow::setSellMode(*(HangarWindow **)(this + 0x74),false);
                resetIdleCamForHangar();
                FUN_00261a24();
                if (**(char **)(this + 0x74) != '\0') {
                  **(char **)(this + 0x74) = '\0';
                  pCVar22 = *(CutScene **)(this + 0x14);
                  pSVar7 = (Ship *)Status::getShip(Globals::status);
                  iVar5 = Ship::getIndex(pSVar7);
                  pSVar7 = (Ship *)Status::getShip(Globals::status);
                  iVar6 = Ship::getRace(pSVar7);
                  CutScene::replacePlayerShip(pCVar22,iVar5,iVar6);
                }
                if (*(CutScene **)(this + 0x14) != (CutScene *)0x0) {
                  CutScene::checkForTurret(*(CutScene **)(this + 0x14));
                }
                fVar23 = (float)FModSound::stop(Globals::sound,0x5f);
                fVar23 = (float)FModSound::play(Globals::sound,0x7a,(Vector *)0x0,(Vector *)0x0,
                                                fVar23);
                FModSound::setParamValue((int)Globals::sound,0,fVar23);
                puVar16 = *(uint **)(this + 0x88);
                uVar13 = 0;
                if (*puVar16 != 0) {
                  uVar21 = 0;
                  do {
                    if ((int)uVar21 < 10) {
                      TouchButton::getPosition();
                      *(int *)(Globals::sub_menu_buttons_x + uVar21 * 4) = (int)local_80;
                      TouchButton::getPosition();
                      *(int *)(Globals::sub_menu_buttons_y + uVar21 * 4) = (int)local_88;
                      puVar16 = *(uint **)(this + 0x88);
                    }
                    uVar21 = uVar21 + 1;
                    uVar13 = *puVar16;
                  } while (uVar21 < *puVar16);
                }
              }
            }
          }
          else {
            iVar5 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x84),param_1,param_2);
            uVar13 = Globals::sub_menu_button_count;
            if (iVar5 == 0) {
              if (__stack_chk_guard == local_28) {
                checkMedals(this);
                return;
              }
              goto LAB_000eb24a;
            }
          }
        }
        else {
          iVar5 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x6c),param_1,param_2);
          if (iVar5 == 1) {
            this[0xae] = (ModStation)0x0;
            if (this[0x67] != (ModStation)0x0) {
              this[0xae] = (ModStation)0x0;
              pSVar8 = Globals::status;
              pSVar14 = (Station *)Status::getStation(Globals::status);
              Status::departStation(pSVar8,pSVar14);
              Achievements::resetNewMedals(Globals::achievements);
              Globals::switch_to_target_setting = 1;
              pAVar19 = Globals::appManager;
              goto LAB_000ead6e;
            }
            this[0xd8] = (ModStation)0x0;
            this[0x5f] = (ModStation)0x0;
            uVar13 = Globals::sub_menu_button_count;
          }
          else {
            uVar13 = Globals::sub_menu_button_count;
            if (iVar5 == 0) {
              if (this[0xae] == (ModStation)0x0) {
                if (this[0x67] == (ModStation)0x0) {
LAB_000eb0bc:
                  if (this[0xd8] != (ModStation)0x0) {
                    this[0xd8] = (ModStation)0x0;
                    this[0x5f] = (ModStation)0x0;
                    iVar5 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager)
                    ;
                    *(undefined1 *)(iVar5 + 0xd) = 1;
                    if (__stack_chk_guard == local_28) {
                      NFC::rateGame();
                      return;
                    }
                    goto LAB_000eb24a;
                  }
                  if ((*(ushort *)(this + 0x68) & 0xff) == 0) {
                    if (0xff < *(ushort *)(this + 0x68)) {
                      iVar5 = Status::getCredits(Globals::status);
                      if (iVar5 < 25000) {
                        pSVar12 = (String *)GameText::getText(Globals::gameText,0xcb);
                        AbyssEngine::String::String((String *)&local_34,pSVar12,false);
                        pSVar8 = Globals::status;
                        AbyssEngine::String::String(aSStack_64,(String *)&local_34,false);
                        Status::getCredits(Globals::status);
                        Layout::formatCredits((int)aSStack_6c);
                        AbyssEngine::String::String(aSStack_74,"#C",false);
                        Status::replaceHash(aSStack_44,pSVar8,aSStack_64,aSStack_6c);
                        AbyssEngine::String::operator=((String *)&local_34,aSStack_44);
                        AbyssEngine::String::~String(aSStack_44);
                        AbyssEngine::String::~String(aSStack_74);
                        AbyssEngine::String::~String(aSStack_6c);
                        AbyssEngine::String::~String(aSStack_64);
                        ChoiceWindow::set(*(String **)(this + 0x6c),
                                          (bool)((char)&stack0x00000078 + 'T'));
                        this[0x69] = (ModStation)0x0;
                        goto LAB_000eaebe;
                      }
                      Status::changeCredits(Globals::status,-25000);
                      this[0x69] = (ModStation)0x0;
                      this[0x5f] = (ModStation)0x0;
                      pSVar8 = Globals::status;
                      pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,0x46);
                      Status::setStation(pSVar8,pSVar14);
                      Globals::switch_to_target_setting = 0;
                      AbyssEngine::ApplicationManager::SetCurrentApplicationModule
                                (Globals::appManager,5);
                    }
                    if ((this[0x18] != (ModStation)0x0) && (this[0x62] != (ModStation)0x0)) {
                      MVar4 = (ModStation)FUN_00261a24(0);
                      this[0x18] = MVar4;
                    }
                    this[0x5f] = (ModStation)0x0;
                    uVar13 = Globals::sub_menu_button_count;
                  }
                  else {
                    Status::changeCredits(Globals::status,-30000000);
                    pSVar7 = (Ship *)Status::getShip(Globals::status);
                    Ship::removeCargo(pSVar7,0x6d,0x32);
                    *(undefined4 *)(Globals::status + 0x114) = 3;
                    RecordHandler::saveOptions(Globals::recordHandler);
                    this_04 = *(ChoiceWindow **)(this + 0x6c);
                    pSVar12 = (String *)GameText::getText(Globals::gameText,0x1e5);
                    ChoiceWindow::set(this_04,pSVar12);
                    pSVar14 = (Station *)Status::getStation(Globals::status);
                    Station::setItems(pSVar14,(Array *)0x0,false);
                    Station::setItems(*(Station **)(Globals::status + 0x14c),(Array *)0x0,false);
                    this[0x68] = (ModStation)0x0;
                    uVar13 = Globals::sub_menu_button_count;
                  }
                }
                else {
                  iVar5 = Status::getCredits(Globals::status);
                  if (*(int *)(this + 0xd0) <= iVar5) {
                    Status::changeCredits(Globals::status,-*(int *)(this + 0xd0));
                    this[0xd4] = (ModStation)0x1;
                    this[0x67] = (ModStation)0x0;
                    pSVar14 = (Station *)Status::getStation(Globals::status);
                    Station::setAttackedFriends(pSVar14,false);
                    this[0xfd] = (ModStation)0x1;
                    enterStation();
                    autosave(this);
                    goto LAB_000eb0bc;
                  }
                  pSVar12 = (String *)GameText::getText(Globals::gameText,0xcb);
                  AbyssEngine::String::String((String *)&local_34,pSVar12,false);
                  pSVar8 = Globals::status;
                  AbyssEngine::String::String(aSStack_4c,(String *)&local_34,false);
                  Status::getCredits(Globals::status);
                  Layout::formatCredits((int)aSStack_54);
                  AbyssEngine::String::String(aSStack_5c,"#C",false);
                  Status::replaceHash(aSStack_44,pSVar8,aSStack_4c,aSStack_54);
                  AbyssEngine::String::operator=((String *)&local_34,aSStack_44);
                  AbyssEngine::String::~String(aSStack_44);
                  AbyssEngine::String::~String(aSStack_5c);
                  AbyssEngine::String::~String(aSStack_54);
                  AbyssEngine::String::~String(aSStack_4c);
                  ChoiceWindow::set(*(String **)(this + 0x6c),(bool)((char)&stack0x00000078 + 'T'));
                  this[0xae] = (ModStation)0x1;
                  this[0x67] = (ModStation)0x1;
                  this[0x5f] = (ModStation)0x1;
LAB_000eaebe:
                  AbyssEngine::String::~String((String *)&local_34);
                  uVar13 = Globals::sub_menu_button_count;
                }
              }
              else {
                this[0xae] = (ModStation)0x0;
                iVar5 = Status::getCurrentCampaignMission(Globals::status);
                if (iVar5 == 0x18) {
                  pSVar14 = (Station *)Status::getStation(Globals::status);
                  iVar5 = Station::getIndex(pSVar14);
                  if (iVar5 == 10) {
                    pSVar14 = (Station *)Status::getStation(Globals::status);
                    piVar15 = (int *)Station::getAgents(pSVar14);
                    if (*piVar15 != 0) {
                      uVar13 = 0;
                      do {
                        pSVar14 = (Station *)Status::getStation(Globals::status);
                        iVar5 = Station::getAgents(pSVar14);
                        this_03 = *(Agent **)(*(int *)(iVar5 + 4) + uVar13 * 4);
                        iVar5 = Agent::getOffer(this_03);
                        if ((iVar5 == 2) &&
                           (iVar5 = Agent::getSellItemIndex(this_03), iVar5 == 0x44)) {
                          Agent::setEvent(this_03,1);
                          Agent::setOfferAccepted(this_03,true);
                        }
                        pSVar14 = (Station *)Status::getStation(Globals::status);
                        puVar16 = (uint *)Station::getAgents(pSVar14);
                        uVar13 = uVar13 + 1;
                      } while (uVar13 < *puVar16);
                    }
                  }
                }
                iVar5 = Status::getCurrentCampaignMission(Globals::status);
                pSVar8 = Globals::status;
                if (iVar5 == 0x30) {
                  pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,0x3a);
                  Status::departStation(pSVar8,pSVar14);
                  Level::initStreamOutPosition = 1;
                }
                else {
                  pSVar14 = (Station *)Status::getStation(Globals::status);
                  Status::departStation(pSVar8,pSVar14);
                }
                pSVar8 = Globals::status;
                *(undefined4 *)(Globals::status + 0x5c) = 0xffffffff;
                *(undefined4 *)(pSVar8 + 0x60) = 0xffffffff;
                *(undefined4 *)(pSVar8 + 100) = 0xffffffff;
                *(undefined4 *)(pSVar8 + 0x68) = 0xffffffff;
                Achievements::resetNewMedals(Globals::achievements);
                Globals::switch_to_target_setting = 1;
LAB_000eaf18:
                AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
                this[0x24] = (ModStation)0x0;
                uVar13 = Globals::sub_menu_button_count;
              }
            }
          }
        }
      }
      else {
        iVar5 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
        uVar13 = Globals::sub_menu_button_count;
        if (iVar5 == 1) {
          *Globals::layout = (Layout)0x0;
          uVar13 = Globals::sub_menu_button_count;
        }
      }
    }
  }
  goto LAB_000eb23a;
LAB_000ea7d2:
  pSVar7 = (Ship *)Status::getShip(Globals::status);
  Ship::removeCargo(pSVar7,*(Item **)(puVar16[1] + uVar13 * 4));
LAB_000ea5ba:
  if (*(HangarWindow **)(this + 0x74) != (HangarWindow *)0x0) {
    HangarWindow::initialize(*(HangarWindow **)(this + 0x74));
  }
LAB_000ea886:
  iVar5 = Mission::isCampaignMission(*(Mission **)(this + 0x98));
  if (iVar5 != 1) {
    Status::incMissionCount(Globals::status);
    pLVar1 = Globals::layout;
    cVar2 = Mission::getReward(*(Mission **)(this + 0x98));
    cVar3 = Mission::getBonus(*(Mission **)(this + 0x98));
    Layout::showMissionRewardMessage((int)pLVar1,(bool)(cVar3 + cVar2));
    goto LAB_000eaad8;
  }
  iVar5 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar5 == 0x2b) {
    Status::removeMission(Globals::status,*(Mission **)(this + 0x98));
    Status::setMission(Globals::status,Mission::empty);
    this[0x65] = (ModStation)0x0;
    fVar23 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
    FModSound::play(Globals::sound,0x90,(Vector *)0x0,(Vector *)0x0,fVar23);
    this_00 = operator_new(0x48);
    Radio::Radio(this_00);
    *(Radio **)(this + 0x50) = this_00;
    pAVar9 = operator_new(0xc);
    puVar10 = operator_new__(4);
    *(undefined4 **)(pAVar9 + 4) = puVar10;
    *(undefined4 *)(pAVar9 + 8) = 1;
    *puVar10 = 0;
    *(undefined4 *)pAVar9 = 0;
    *(Array **)(this + 0x54) = pAVar9;
    ArraySetLength<RadioMessage*>(4,pAVar9);
    pRVar11 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar11,0x817,1,5,4000);
    **(undefined4 **)(*(int *)(this + 0x54) + 4) = pRVar11;
    pRVar11 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar11,0x818,1,6,0);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x54) + 4) + 4) = pRVar11;
    pRVar11 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar11,0x819,1,6,1);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x54) + 4) + 8) = pRVar11;
    pRVar11 = operator_new(0x28);
    RadioMessage::RadioMessage(pRVar11,0x81a,1,6,2);
    *(RadioMessage **)(*(int *)(*(int *)(this + 0x54) + 4) + 0xc) = pRVar11;
    Radio::setMessages(*(Radio **)(this + 0x50),*(Array **)(this + 0x54));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1b5a,(uint *)(this + 0x58));
    iVar5 = Globals::h;
    iVar6 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x58));
    local_30 = VectorSignedToFloat(iVar6 + iVar5 + Globals::h / 2 + 10,(byte)(in_fpscr >> 0x16) & 3)
    ;
    local_34 = 0x42480000;
    local_2c = 0;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x100),(Vector *)&local_34);
    this_01 = operator_new(0x40);
    fVar23 = (float)VectorSignedToFloat(Globals::w,(byte)(in_fpscr >> 0x16) & 3);
    ScrollTouchBox::ScrollTouchBox
              (this_01,(int)*(float *)(this + 0x100),(int)*(float *)(this + 0x104),
               (int)(fVar23 + *(float *)(this + 0x100) * -2.0),5000);
    *(ScrollTouchBox **)(this + 0x94) = this_01;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x30);
    AbyssEngine::String::String(aSStack_3c,pSVar12,false);
    ScrollTouchBox::setText(this_01,aSStack_3c);
    AbyssEngine::String::~String(aSStack_3c);
    ScrollTouchBox::setTextCentered(*(ScrollTouchBox **)(this + 0x94),true);
    *(undefined4 *)(this + 0xb0) = 0xffffd120;
    *(undefined4 *)(this + 0xb4) = 0;
    this[0x5c] = (ModStation)0x1;
    uVar13 = Globals::sub_menu_button_count;
  }
  else {
    iVar5 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar5 != 0x94) {
      Status::nextCampaignMission(SUB41(Globals::status,0));
    }
    iVar5 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar5 < 0x4b) {
      uVar13 = iVar5 - 0x2c;
      if (uVar13 < 0xf) {
        if ((1 << (uVar13 & 0xff) & 0x5830U) != 0) {
          pCVar22 = *(CutScene **)(this + 0x14);
          pSVar7 = (Ship *)Status::getShip(Globals::status);
          iVar5 = Ship::getIndex(pSVar7);
          pSVar7 = (Ship *)Status::getShip(Globals::status);
          iVar6 = Ship::getRace(pSVar7);
          CutScene::replacePlayerShip(pCVar22,iVar5,iVar6);
          goto LAB_000eaad8;
        }
        if (uVar13 == 0) goto LAB_000eb2ca;
        if (uVar13 == 1) {
          Status::removeMission(Globals::status,*(Mission **)(this + 0x98));
          *(undefined4 *)(this + 0x98) = 0;
          Status::setMission(Globals::status,Mission::empty);
          this[0x65] = (ModStation)0x0;
          *(undefined4 *)(this + 0x40) = 1;
          (**(code **)(*(int *)this + 0x10))(this,*(code **)(*(int *)this + 0x10),0x10000,0);
          uVar13 = Globals::sub_menu_button_count;
          goto LAB_000eb23a;
        }
      }
      if (iVar5 == 9) {
LAB_000eb2ca:
        Status::removeMission(Globals::status,*(Mission **)(this + 0x98));
        *(undefined4 *)(this + 0x98) = 0;
        Status::setMission(Globals::status,Mission::empty);
        this[0x65] = (ModStation)0x0;
        Globals::switch_to_target_setting = 0;
        if (__stack_chk_guard == local_28) {
          uVar13 = 5;
          pAVar19 = Globals::appManager;
LAB_000eb31c:
          AbyssEngine::ApplicationManager::SetCurrentApplicationModule(pAVar19,uVar13);
          return;
        }
        goto LAB_000eb24a;
      }
      if (iVar5 != 0x12) goto LAB_000eb4d8;
      Status::removeMission(Globals::status,*(Mission **)(this + 0x98));
      *(undefined4 *)(this + 0x98) = 0;
      this[0x65] = (ModStation)0x0;
      uVar13 = Globals::sub_menu_button_count;
    }
    else {
      if ((iVar5 - 0x4bU < 9) && ((1 << (iVar5 - 0x4bU & 0xff) & 0x103U) != 0)) goto LAB_000eb2ca;
LAB_000eb4d8:
      pSVar14 = (Station *)Status::getStation(Globals::status);
      iVar6 = Station::getIndex(pSVar14);
      pSVar8 = Globals::status;
      if (iVar5 == 0x4d && iVar6 == 100) {
        pSVar14 = (Station *)Status::getStation(Globals::status);
        pSVar7 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x94),0);
        Station::addShip(pSVar14,pSVar7);
LAB_000eaad8:
        iVar5 = Mission::getReward(*(Mission **)(this + 0x98));
        iVar6 = Mission::getBonus(*(Mission **)(this + 0x98));
        pcVar20 = (char *)(iVar6 + iVar5);
        if ((char *)0xf4240 < pcVar20) {
          iVar5 = Status::getCurrentCampaignMission(Globals::status);
          if (iVar5 == 0x37) {
            pcVar20 = "ppEPFvPS0_E";
          }
          else if (iVar5 == 0x3a) {
            pcVar20 = "\x04";
          }
          else {
            pcVar20 = (char *)0x1a0a;
            if (iVar5 == 0x3d) {
              pcVar20 = (char *)0xc350;
            }
          }
        }
        Status::changeCredits(Globals::status,(int)pcVar20);
        Status::removeMission(Globals::status,*(Mission **)(this + 0x98));
        *(undefined4 *)(this + 0x98) = 0;
        if (*(int *)(this + 0x70) != 0) {
          SpaceLounge::refresh();
        }
        this[0x65] = (ModStation)0x0;
        goto LAB_000eabd0;
      }
      if (iVar5 == 0x4e) {
        *(undefined4 *)(Globals::status + 0x5c) = 0xffffffff;
        *(undefined4 *)(pSVar8 + 0x60) = 0xffffffff;
        *(undefined4 *)(pSVar8 + 100) = 0xffffffff;
        *(undefined4 *)(pSVar8 + 0x68) = 0xffffffff;
        Achievements::resetNewMedals(Globals::achievements);
        pSVar8 = Globals::status;
        pSVar14 = (Station *)Status::getStation(Globals::status);
        Status::departStation(pSVar8,pSVar14);
        Globals::switch_to_target_setting = 1;
        AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
        this[0x24] = (ModStation)0x0;
        goto LAB_000eaad8;
      }
      pSVar14 = (Station *)Status::getStation(Globals::status);
      iVar6 = Station::getIndex(pSVar14);
      pSVar8 = Globals::status;
      if (iVar5 == 0x54 && iVar6 == 100) {
        pSVar14 = (Station *)Status::getStation(Globals::status);
        iVar5 = Station::hasShip(pSVar14,0x26);
        if (iVar5 == 0) {
          pSVar7 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x98),-1);
          Station::addShip(pSVar14,pSVar7);
        }
        iVar5 = Station::hasShip(pSVar14,0x28);
        if (iVar5 == 0) {
          pSVar7 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xa0),-1);
          Station::addShip(pSVar14,pSVar7);
        }
        pSVar7 = (Ship *)Status::getShip(Globals::status);
        pIVar18 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x224),1);
        Ship::addCargo(pSVar7,pIVar18);
        goto LAB_000eaad8;
      }
      if (iVar5 < 0x77) {
        if (0x67 < iVar5) {
          if (iVar5 == 0x68) {
            if (*(HangarWindow **)(this + 0x74) != (HangarWindow *)0x0) {
              pvVar17 = (void *)HangarWindow::~HangarWindow(*(HangarWindow **)(this + 0x74));
              operator_delete(pvVar17);
            }
            *(undefined4 *)(this + 0x74) = 0;
            FUN_00261a24();
          }
          else if (iVar5 == 0x6d) {
            Globals::switch_to_target_setting = 1;
            Level::initStreamOutPosition = 1;
            pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,0x72);
            Status::departStation(pSVar8,pSVar14);
            goto LAB_000eaf18;
          }
          goto LAB_000eaad8;
        }
        if (iVar5 == 0x59) {
          Globals::switch_to_target_setting = 1;
          Level::initStreamOutPosition = 1;
          pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,0x6d);
          Status::departStation(pSVar8,pSVar14);
        }
        else {
          if (iVar5 != 99) goto LAB_000eaad8;
          Globals::switch_to_target_setting = 1;
          Level::initStreamOutPosition = 1;
          pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,10);
          Status::departStation(pSVar8,pSVar14);
        }
        goto LAB_000eaf18;
      }
      if (iVar5 < 0x85) {
        if (iVar5 != 0x77) {
          if ((iVar5 == 0x80) && (Status::activateNewWanted(), Globals::hints[0x2a] == '\0')) {
            this[0x6a] = (ModStation)0x1;
          }
          goto LAB_000eaad8;
        }
        Globals::switch_to_target_setting = 1;
        Level::initStreamOutPosition = 1;
        pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,10);
        Status::departStation(pSVar8,pSVar14);
        goto LAB_000eaf18;
      }
      if (iVar5 == 0x85) {
        Globals::switch_to_target_setting = 1;
        Level::initStreamOutPosition = 1;
        pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,0x78);
        Status::departStation(pSVar8,pSVar14);
        goto LAB_000eaf18;
      }
      if (iVar5 != 0x90) {
        if (iVar5 == 0xa0) {
          Globals::switch_to_target_setting = 1;
          Level::initStreamOutPosition = 0;
          pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,10);
          Status::departStation(pSVar8,pSVar14);
          if (__stack_chk_guard == local_28) {
            uVar13 = 2;
            pAVar19 = *(ApplicationManager **)(this + 8);
            goto LAB_000eb31c;
          }
          goto LAB_000eb24a;
        }
        goto LAB_000eaad8;
      }
      Globals::switch_to_target_setting = 1;
      Level::initStreamOutPosition = 0;
      pSVar14 = (Station *)Galaxy::getStation(Globals::galaxy,0x70);
      Status::departStation(pSVar8,pSVar14);
      pAVar19 = *(ApplicationManager **)(this + 8);
LAB_000ead6e:
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule(pAVar19,2);
      this[0x24] = (ModStation)0x0;
      uVar13 = Globals::sub_menu_button_count;
    }
  }
LAB_000eb23a:
  Globals::sub_menu_button_count = uVar13;
  if (__stack_chk_guard == local_28) {
    return;
  }
LAB_000eb24a:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ModStation::checkMedals  @0x000ebe74  (448 bytes)
/* ModStation::checkMedals() */

void __thiscall ModStation::checkMedals(ModStation *this)

{
  ModStation *this_00;
  int iVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  ChoiceWindow *this_01;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  
  Globals::reportLeaderboards();
  if ((this[0x66] == (ModStation)0x0) && (this[0x5f] == (ModStation)0x0)) {
    iVar6 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar6 == 1) {
      addAchievement((ModStation *)0x1,0,1);
    }
    uVar8 = 0;
    *(undefined4 *)(this + 0xb8) = 0;
    iVar6 = Achievements::getNewMedals(Globals::achievements);
    iVar1 = 0;
    *(undefined4 *)(this + 0xc0) = 0;
    do {
      iVar9 = iVar1 * 4;
      iVar1 = iVar1 + 1;
      if (0 < *(int *)(iVar6 + iVar9)) {
        uVar8 = uVar8 + 1;
        *(uint *)(this + 0xc0) = uVar8;
      }
    } while (iVar1 != 0x2d);
    if ((int)uVar8 < 1) {
      return;
    }
    pAVar2 = operator_new(0xc);
    puVar3 = operator_new__(4);
    iVar1 = 0;
    *(undefined4 **)(pAVar2 + 4) = puVar3;
    *(undefined4 *)(pAVar2 + 8) = 1;
    *puVar3 = 0;
    *(undefined4 *)pAVar2 = 0;
    *(Array **)(this + 0xb8) = pAVar2;
    ArraySetLength<int*>(uVar8,pAVar2);
    iVar9 = 0;
    *(undefined4 *)(this + 0xc0) = 0;
    do {
      if (0 < *(int *)(iVar6 + iVar9 * 4)) {
        pvVar4 = operator_new__(8);
        *(void **)(*(int *)(*(int *)(this + 0xb8) + 4) + iVar1 * 4) = pvVar4;
        iVar5 = *(int *)(*(int *)(this + 0xb8) + 4);
        **(int **)(iVar5 + iVar1 * 4) = iVar9;
        *(undefined4 *)(*(int *)(iVar5 + *(int *)(this + 0xc0) * 4) + 4) =
             *(undefined4 *)(iVar6 + iVar9 * 4);
        iVar1 = *(int *)(this + 0xc0) + 1;
        *(int *)(this + 0xc0) = iVar1;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != 0x2d);
    this[0x66] = (ModStation)0x1;
    *(undefined4 *)(this + 0xbc) = 0;
    this_01 = operator_new(0x54);
    ChoiceWindow::ChoiceWindow(this_01);
    *(ChoiceWindow **)(this + 0x84) = this_01;
    ChoiceWindow::setMedal
              (this_01,*(int *)**(int **)(*(int *)(this + 0xb8) + 4),
               ((int *)**(int **)(*(int *)(this + 0xb8) + 4))[1]);
    iVar6 = Status::hardCoreMode();
    if (iVar6 == 0) {
      Status::changeCredits
                (Globals::status,
                 (&DAT_00251ff0)[*(int *)(**(int **)(*(int *)(this + 0xb8) + 4) + 4)]);
    }
    this_00 = (ModStation *)**(undefined4 **)(*(int *)(this + 0xb8) + 4);
  }
  else {
    iVar6 = *(int *)(this + 0xbc) + 1;
    *(int *)(this + 0xbc) = iVar6;
    if (*(int *)(this + 0xc0) <= iVar6) {
      this[0x66] = (ModStation)0x0;
      return;
    }
    piVar7 = *(int **)(*(int *)(*(int *)(this + 0xb8) + 4) + iVar6 * 4);
    ChoiceWindow::setMedal(*(ChoiceWindow **)(this + 0x84),*piVar7,piVar7[1]);
    iVar6 = Status::hardCoreMode();
    if (iVar6 == 0) {
      Status::changeCredits
                (Globals::status,
                 (&DAT_00251ff0)
                 [*(int *)(*(int *)(*(int *)(*(int *)(this + 0xb8) + 4) + *(int *)(this + 0xbc) * 4)
                          + 4)]);
    }
    this_00 = *(ModStation **)(*(int *)(*(int *)(this + 0xb8) + 4) + *(int *)(this + 0xbc) * 4);
  }
  addAchievement(this_00,*(int *)this_00,*(int *)(this_00 + 4));
  return;
}

// ===== ModStation::resetIdleCamForHangar  @0x000ec06c  (330 bytes)
/* ModStation::resetIdleCamForHangar() */

void ModStation::resetIdleCamForHangar(void)

{
  PaintCanvas *pPVar1;
  int in_r0;
  EaseInOut *pEVar2;
  uint uVar3;
  Matrix *pMVar4;
  Station *pSVar5;
  int iVar6;
  SolarSystem *this;
  undefined4 uVar7;
  undefined4 in_s0;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  undefined4 in_s1;
  undefined8 uVar8;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s2;
  AEMath aAStack_50 [60];
  int local_14;
  
  uVar8 = CONCAT44(in_s1,in_s0);
  local_14 = __stack_chk_guard;
  if (*(CutScene **)(in_r0 + 0x14) != (CutScene *)0x0) {
    uVar8 = CutScene::resetCamera(*(CutScene **)(in_r0 + 0x14));
  }
  if (*(EaseInOut **)(in_r0 + 0x138) == (EaseInOut *)0x0) {
    pEVar2 = operator_new(0x10);
    uVar8 = AbyssEngine::EaseInOut::EaseInOut(pEVar2,extraout_s0,extraout_s1);
    *(EaseInOut **)(in_r0 + 0x138) = pEVar2;
  }
  else {
    uVar8 = AbyssEngine::EaseInOut::SetRange
                      (*(EaseInOut **)(in_r0 + 0x138),(float)uVar8,(float)((ulonglong)uVar8 >> 0x20)
                      );
  }
  if (*(EaseInOut **)(in_r0 + 0x13c) == (EaseInOut *)0x0) {
    pEVar2 = operator_new(0x10);
    uVar8 = AbyssEngine::EaseInOut::EaseInOut(pEVar2,extraout_s0_00,extraout_s1_00);
    *(EaseInOut **)(in_r0 + 0x13c) = pEVar2;
  }
  else {
    uVar8 = AbyssEngine::EaseInOut::SetRange
                      (*(EaseInOut **)(in_r0 + 0x13c),(float)uVar8,(float)((ulonglong)uVar8 >> 0x20)
                      );
  }
  if (*(EaseInOut **)(in_r0 + 0x140) == (EaseInOut *)0x0) {
    pEVar2 = operator_new(0x10);
    AbyssEngine::EaseInOut::EaseInOut(pEVar2,extraout_s0_01,extraout_s1_01);
    *(EaseInOut **)(in_r0 + 0x140) = pEVar2;
  }
  else {
    AbyssEngine::EaseInOut::SetRange
              (*(EaseInOut **)(in_r0 + 0x140),(float)uVar8,(float)((ulonglong)uVar8 >> 0x20));
  }
  pPVar1 = Globals::Canvas;
  uVar3 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar3);
  AbyssEngine::AEMath::MatrixSetTranslation
            (aAStack_50,pMVar4,*(float *)(in_r0 + 0x134),extraout_s1_02,extraout_s2);
  pSVar5 = (Station *)Status::getStation(Globals::status);
  iVar6 = Station::getIndex(pSVar5);
  if (iVar6 == 0x65) {
    iVar6 = 8;
  }
  else {
    pSVar5 = (Station *)Status::getStation(Globals::status);
    iVar6 = Station::getIndex(pSVar5);
    if (iVar6 == 100) {
      iVar6 = 7;
    }
    else {
      this = (SolarSystem *)Status::getSystem(Globals::status);
      iVar6 = SolarSystem::getRace(this);
    }
  }
  pPVar1 = Globals::Canvas;
  uVar3 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  uVar7 = AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar3);
  AbyssEngine::AEMath::MatrixSetRotation
            (aAStack_50,uVar7,*(undefined4 *)(&UNK_0025473c + iVar6 * 4),
             *(undefined4 *)(&UNK_0025478c + iVar6 * 4),0,2);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ModStation::leaveStation  @0x000ec1ec  (586 bytes)
/* ModStation::leaveStation() */

void __thiscall ModStation::leaveStation(ModStation *this)

{
  ModStation MVar1;
  bool bVar2;
  Ship *pSVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  Station *pSVar7;
  Mission *pMVar8;
  String *pSVar9;
  ChoiceWindow *pCVar10;
  
  pSVar3 = (Ship *)Status::getShip(Globals::status);
  iVar4 = Ship::getCurrentLoad(pSVar3);
  pSVar3 = (Ship *)Status::getShip(Globals::status);
  iVar5 = Ship::getMaxLoad(pSVar3);
  if (iVar5 < iVar4) {
    iVar4 = 0xcc;
    pCVar10 = *(ChoiceWindow **)(this + 0x6c);
    goto LAB_000ec386;
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 != 6) {
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar4 != 7) {
LAB_000ec2b2:
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x14) {
        pSVar7 = (Station *)Status::getStation(Globals::status);
        iVar4 = Station::getIndex(pSVar7);
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar5 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar5) {
          iVar4 = 0x213;
          pCVar10 = *(ChoiceWindow **)(this + 0x6c);
          goto LAB_000ec386;
        }
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x15) {
        pSVar7 = (Station *)Status::getStation(Globals::status);
        iVar4 = Station::getIndex(pSVar7);
        pMVar8 = (Mission *)Status::getCampaignMission(Globals::status);
        iVar5 = Mission::getTargetStation(pMVar8);
        if (iVar4 == iVar5) {
          pSVar3 = (Ship *)Status::getShip(Globals::status);
          iVar4 = Ship::hasEquipment(pSVar3,0x29,1);
          if (iVar4 == 0) {
            pSVar3 = (Ship *)Status::getShip(Globals::status);
            iVar4 = Ship::hasEquipment(pSVar3,0x2a,1);
            if (iVar4 == 0) {
              pSVar3 = (Ship *)Status::getShip(Globals::status);
              iVar4 = Ship::hasEquipment(pSVar3,0x2b,1);
              if (iVar4 == 0) {
                pCVar10 = *(ChoiceWindow **)(this + 0x6c);
                pSVar9 = (String *)GameText::getText(Globals::gameText,0x213);
                ChoiceWindow::set(pCVar10,pSVar9);
                this[0x5f] = (ModStation)0x1;
                return;
              }
            }
          }
          if (this[0x5f] != (ModStation)0x0) {
            return;
          }
          if (this[0x65] != (ModStation)0x0) {
            return;
          }
          MVar1 = this[0x66];
          goto joined_r0x000ec3da;
        }
      }
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x4d) {
        pSVar3 = (Ship *)Status::getShip(Globals::status);
        iVar4 = Ship::getIndex(pSVar3);
        if (iVar4 != 0x25) {
          iVar4 = 0x146;
          pCVar10 = *(ChoiceWindow **)(this + 0x6c);
          goto LAB_000ec386;
        }
      }
      if (this[0x5f] != (ModStation)0x0) {
        return;
      }
      if (this[0x65] != (ModStation)0x0) {
        return;
      }
      MVar1 = this[0x66];
joined_r0x000ec3da:
      if (MVar1 != (ModStation)0x0) {
        return;
      }
      pSVar9 = *(String **)(this + 0x6c);
      bVar2 = (bool)GameText::getText(Globals::gameText,0x18d);
      ChoiceWindow::set(pSVar9,bVar2);
      ChoiceWindow::left();
      this[0x5f] = (ModStation)0x1;
      this[0xae] = (ModStation)0x1;
      return;
    }
    pSVar3 = (Ship *)Status::getShip(Globals::status);
    fVar6 = (float)Ship::getFirePower(pSVar3);
    if (fVar6 != 0.0) {
      pSVar3 = (Ship *)Status::getShip(Globals::status);
      iVar4 = Ship::getCombinedHP(pSVar3);
      pSVar3 = (Ship *)Status::getShip(Globals::status);
      iVar5 = Ship::getBaseHP(pSVar3);
      if (iVar4 != iVar5) goto LAB_000ec2b2;
    }
  }
  pSVar3 = (Ship *)Status::getShip(Globals::status);
  iVar4 = Ship::hasCargoType(pSVar3,0);
  if (iVar4 == 0) {
    pSVar3 = (Ship *)Status::getShip(Globals::status);
    iVar4 = Ship::hasCargoType(pSVar3,3);
    if (iVar4 != 1) {
      iVar4 = 0x211;
      pCVar10 = *(ChoiceWindow **)(this + 0x6c);
      goto LAB_000ec386;
    }
  }
  iVar4 = 0x212;
  pCVar10 = *(ChoiceWindow **)(this + 0x6c);
LAB_000ec386:
  pSVar9 = (String *)GameText::getText(Globals::gameText,iVar4);
  ChoiceWindow::set(pCVar10,pSVar9);
  this[0x5f] = (ModStation)0x1;
  return;
}

// ===== ModStation::OnRelease  @0x000ec498  (502 bytes)
/* ModStation::OnRelease() */

void __thiscall ModStation::OnRelease(ModStation *this)

{
  Globals *this_00;
  int iVar1;
  void *pvVar2;
  
  if (Globals::sound != (FModSound *)0x0) {
    FModSound::disableReverb(Globals::sound);
    FModSound::stopAllSoundFXEvents(Globals::sound);
  }
  AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,0,1);
  if (*(Array **)(this + 0x88) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x88));
    pvVar2 = *(void **)(this + 0x88);
    if (pvVar2 != (void *)0x0) {
      if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar2 + 4));
      }
      operator_delete(pvVar2);
    }
  }
  *(undefined4 *)(this + 0x88) = 0;
  if (*(HangarWindow **)(this + 0x74) != (HangarWindow *)0x0) {
    pvVar2 = (void *)HangarWindow::~HangarWindow(*(HangarWindow **)(this + 0x74));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x74) = 0;
  if (*(StarMap **)(this + 0x10) != (StarMap *)0x0) {
    pvVar2 = (void *)StarMap::~StarMap(*(StarMap **)(this + 0x10));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x10) = 0;
  if (*(SpaceLounge **)(this + 0x70) != (SpaceLounge *)0x0) {
    pvVar2 = (void *)SpaceLounge::~SpaceLounge(*(SpaceLounge **)(this + 0x70));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x70) = 0;
  if (*(MissionsWindow **)(this + 0x7c) != (MissionsWindow *)0x0) {
    pvVar2 = (void *)MissionsWindow::~MissionsWindow(*(MissionsWindow **)(this + 0x7c));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x7c) = 0;
  if (*(DialogueWindow **)(this + 0x80) != (DialogueWindow *)0x0) {
    pvVar2 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x80));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x80) = 0;
  if (*(ChoiceWindow **)(this + 0x84) != (ChoiceWindow *)0x0) {
    pvVar2 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0x84));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x84) = 0;
  if (*(StatusWindow **)(this + 0x78) != (StatusWindow *)0x0) {
    pvVar2 = (void *)StatusWindow::~StatusWindow(*(StatusWindow **)(this + 0x78));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(CutScene **)(this + 0x14) != (CutScene *)0x0) {
    pvVar2 = (void *)CutScene::~CutScene(*(CutScene **)(this + 0x14));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x14) = 0;
  if (*(MenuTouchWindow **)(this + 0x4c) != (MenuTouchWindow *)0x0) {
    pvVar2 = (void *)MenuTouchWindow::~MenuTouchWindow(*(MenuTouchWindow **)(this + 0x4c));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x4c) = 0;
  if (*(Radio **)(this + 0x50) != (Radio *)0x0) {
    pvVar2 = (void *)Radio::~Radio(*(Radio **)(this + 0x50));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x50) = 0;
  pvVar2 = *(void **)(this + 0x54);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x54) = 0;
  if (*(NewsTicker **)(this + 0x1c) != (NewsTicker *)0x0) {
    pvVar2 = (void *)NewsTicker::~NewsTicker(*(NewsTicker **)(this + 0x1c));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  if (*(ChoiceWindow **)(this + 0x6c) != (ChoiceWindow *)0x0) {
    pvVar2 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0x6c));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x6c) = 0;
  AbyssEngine::PaintCanvas::ReleaseAllResources(Globals::Canvas);
  this_00 = Globals::globals;
  iVar1 = GameText::getLanguage();
  Globals::loadFont(this_00,iVar1);
  if (Globals::layout != (Layout *)0x0) {
    Layout::reload(Globals::layout);
    ImageFactory::reload(Globals::imageFactory);
    Layout::initTip(Globals::layout);
  }
  pvVar2 = *(void **)(this + 0x20);
  if (pvVar2 != (void *)0x0) {
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar2 + 0x58));
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar2 + 0x3c));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x20) = 0;
  if (*(void **)(this + 0x138) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x138));
  }
  *(undefined4 *)(this + 0x138) = 0;
  if (*(void **)(this + 0x13c) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x13c));
  }
  *(undefined4 *)(this + 0x13c) = 0;
  if (*(void **)(this + 0x140) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x140));
  }
  *(undefined4 *)(this + 0x140) = 0;
  if (*(Radio **)(this + 0x50) != (Radio *)0x0) {
    pvVar2 = (void *)Radio::~Radio(*(Radio **)(this + 0x50));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x50) = 0;
  if (*(ScrollTouchBox **)(this + 0x94) != (ScrollTouchBox *)0x0) {
    pvVar2 = (void *)ScrollTouchBox::~ScrollTouchBox(*(ScrollTouchBox **)(this + 0x94));
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined2 *)(this + 0xac) = 0;
  if (Globals::sound == (FModSound *)0x0) {
    return;
  }
  FModSound::freeAllEvents(Globals::sound);
  return;
}

// ===== ModStation::OnKeyPress  @0x000ec6f8  (2584 bytes)
/* ModStation::OnKeyPress(long long, long long) */

void ModStation::OnKeyPress(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  FModSound *this;
  ModStation MVar2;
  undefined1 uVar3;
  ModStation *this_00;
  String *pSVar4;
  Station *pSVar5;
  DialogueWindow *pDVar6;
  String *pSVar7;
  Agent *this_01;
  void *pvVar8;
  MissionsWindow *this_02;
  Ship *pSVar9;
  SpaceLounge *this_03;
  HangarWindow *pHVar10;
  uint *puVar11;
  Engine *this_04;
  StarMap *this_05;
  int iVar12;
  int *extraout_r1;
  uint uVar13;
  int iVar14;
  StatusWindow *this_06;
  ChoiceWindow *this_07;
  uint uVar15;
  bool bVar16;
  float fVar17;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  String aSStack_80 [8];
  String aSStack_78 [8];
  String aSStack_70 [8];
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  String aSStack_50 [12];
  float local_44;
  float local_3c;
  String aSStack_30 [8];
  int local_28;
  
  this_00 = (ModStation *)param_1;
  iVar12 = (int)((ulonglong)param_2 >> 0x20);
  local_28 = __stack_chk_guard;
  if (this_00[0x24] != (ModStation)0x0) {
    Status::checkForLevelUp(Globals::status);
    iVar14 = *(int *)(this_00 + 0x34);
    bVar16 = 999 < *(uint *)(this_00 + 0x30);
    if ((int)(-(uint)bVar16 - iVar14) < 0 == (SBORROW4(0,iVar14) != SBORROW4(-iVar14,(uint)bVar16)))
    {
      if (param_2 == 0x10000) {
        *(undefined4 *)(this_00 + 0x30) = 0x3e9;
        *(undefined4 *)(this_00 + 0x34) = 0;
      }
    }
    else if (((((this_00[0x5f] == (ModStation)0x0) && (this_00[0x65] == (ModStation)0x0)) &&
              (this_00[0x61] == (ModStation)0x0)) &&
             (((*(ushort *)(this_00 + 0x62) & 0xff) == 0 && (*(ushort *)(this_00 + 0x62) < 0x100))))
            && ((this_00[0x60] == (ModStation)0x0 && ((*(uint *)(this_00 + 100) & 0xff) == 0)))) {
      if ((*(uint *)(this_00 + 100) & 0xff0000) == 0) {
        MVar2 = this_00[0x5e];
        if (this_00[0x5d] == (ModStation)0x0) {
LAB_000ec884:
          bVar16 = MVar2 == (ModStation)0x0;
          if (param_2 == 0x40000 && MVar2 == (ModStation)0x0) {
            if (__stack_chk_guard == local_28) {
              leaveStation(this_00);
              return;
            }
            goto LAB_000ec8e0;
          }
        }
        else {
          bVar16 = false;
          if (MVar2 == (ModStation)0x0) {
            bVar16 = 0xffff < (uint)param_2;
            if ((int)(-(uint)bVar16 - iVar12) < 0 ==
                (SBORROW4(0,iVar12) != SBORROW4(-iVar12,(uint)bVar16))) {
              if (param_2 == 0x4000) {
                iVar12 = *(int *)(this_00 + 0x44);
                *(undefined4 *)(iVar12 + *(int *)(this_00 + 0x40) * 4) = 0;
                iVar14 = 4;
                if (0 < *(int *)(this_00 + 0x40)) {
                  iVar14 = *(int *)(this_00 + 0x40) + -1;
                }
              }
              else {
                MVar2 = (ModStation)0x0;
                if (param_2 != 0x8000) goto LAB_000ec884;
                iVar12 = *(int *)(this_00 + 0x44);
                iVar14 = 0;
                *(undefined4 *)(iVar12 + *(int *)(this_00 + 0x40) * 4) = 0;
                if (*(int *)(this_00 + 0x40) < 4) {
                  iVar14 = *(int *)(this_00 + 0x40) + 1;
                }
              }
              *(int *)(this_00 + 0x40) = iVar14;
              *(undefined4 *)(iVar12 + iVar14 * 4) = 1;
            }
            else if (param_2 != 0x20000) {
              MVar2 = (ModStation)0x0;
              if (param_2 != 0x10000) goto LAB_000ec884;
              switch(*(undefined4 *)(this_00 + 0x40)) {
              case 0:
                iVar12 = Status::getCurrentCampaignMission(Globals::status);
                if ((((iVar12 < 5) ||
                     (iVar12 = Status::getCurrentCampaignMission(Globals::status), iVar12 == 0x30))
                    || (iVar12 = Status::getCurrentCampaignMission(Globals::status), iVar12 == 0x31)
                    ) || (iVar12 = Status::getCurrentCampaignMission(Globals::status),
                         iVar12 == 0x38)) {
LAB_000eca24:
                  iVar12 = 0x210;
                  this_07 = *(ChoiceWindow **)(this_00 + 0x6c);
LAB_000eca2e:
                  pSVar4 = (String *)GameText::getText(Globals::gameText,iVar12);
                  ChoiceWindow::set(this_07,pSVar4);
                  this_00[0x5f] = (ModStation)0x1;
                }
                else {
                  pSVar5 = (Station *)Status::getStation(Globals::status);
                  iVar12 = Station::getIndex(pSVar5);
                  if (iVar12 == 4) {
                    pSVar5 = (Station *)Status::getStation(Globals::status);
                    iVar12 = Station::stationHasPirateBase(pSVar5);
                    if (iVar12 == 1) {
                      if (*(int *)(this_00 + 0x80) == 0) {
                        pDVar6 = operator_new(0x6c);
                        pSVar4 = (String *)GameText::getText(Globals::gameText,0x1b0);
                        pSVar7 = (String *)GameText::getText(Globals::gameText,0x649);
                        DialogueWindow::DialogueWindow(pDVar6,pSVar4,pSVar7,(int *)&DAT_0026a1c4);
                        *(DialogueWindow **)(this_00 + 0x80) = pDVar6;
                        this_00[0x65] = (ModStation)0x1;
                        this_01 = operator_new(0x88);
                        AbyssEngine::String::String(aSStack_30,"",false);
                        Agent::Agent(this_01,0,aSStack_30,0);
                        AbyssEngine::String::~String(aSStack_30);
                        iVar12 = 0x1b0;
LAB_000ecb24:
                        this = Globals::sound;
                        iVar12 = Globals::getDialogueSoundId(Globals::globals,iVar12,this_01);
                        FModSound::play(this,iVar12,(Vector *)0x0,(Vector *)0x0,extraout_s0);
                        pvVar8 = (void *)Agent::~Agent(this_01);
                        operator_delete(pvVar8);
                      }
                      break;
                    }
                  }
                  if (*(int *)(this_00 + 0x74) == 0) {
                    pHVar10 = operator_new(0x134);
                    HangarWindow::HangarWindow(pHVar10);
                    *(HangarWindow **)(this_00 + 0x74) = pHVar10;
                    HangarWindow::initialize(pHVar10);
                  }
                  if ((*(SpaceLounge **)(this_00 + 0x70) == (SpaceLounge *)0x0) ||
                     (iVar12 = SpaceLounge::hangarNeedsUpdate(*(SpaceLounge **)(this_00 + 0x70)),
                     iVar12 != 1)) {
                    if ((*(MissionsWindow **)(this_00 + 0x7c) != (MissionsWindow *)0x0) &&
                       (iVar12 = MissionsWindow::hangarNeedsUpdate
                                           (*(MissionsWindow **)(this_00 + 0x7c)), iVar12 == 1)) {
                      if (*(HangarWindow **)(this_00 + 0x74) != (HangarWindow *)0x0) {
                        pvVar8 = (void *)HangarWindow::~HangarWindow
                                                   (*(HangarWindow **)(this_00 + 0x74));
                        operator_delete(pvVar8);
                      }
                      *(undefined4 *)(this_00 + 0x74) = 0;
                      pHVar10 = operator_new(0x134);
                      HangarWindow::HangarWindow(pHVar10);
                      *(HangarWindow **)(this_00 + 0x74) = pHVar10;
                      HangarWindow::initialize(pHVar10);
                      MissionsWindow::setHangarUpdate(*(MissionsWindow **)(this_00 + 0x7c),false);
                    }
                  }
                  else {
                    if (*(HangarWindow **)(this_00 + 0x74) != (HangarWindow *)0x0) {
                      pvVar8 = (void *)HangarWindow::~HangarWindow
                                                 (*(HangarWindow **)(this_00 + 0x74));
                      operator_delete(pvVar8);
                    }
                    *(undefined4 *)(this_00 + 0x74) = 0;
                    pHVar10 = operator_new(0x134);
                    HangarWindow::HangarWindow(pHVar10);
                    *(HangarWindow **)(this_00 + 0x74) = pHVar10;
                    HangarWindow::initialize(pHVar10);
                    SpaceLounge::setHangarUpdate(*(SpaceLounge **)(this_00 + 0x70),false);
                  }
                  iVar12 = *(int *)(this_00 + 0x74);
                  uVar13 = 0;
                  if (**(int **)(iVar12 + 4) != 0) {
                    uVar15 = 0;
                    do {
                      if ((int)uVar15 < 10) {
                        TouchButton::getPosition();
                        *(int *)(Globals::sub_menu_buttons_x + uVar15 * 4) = (int)local_3c;
                        TouchButton::getPosition();
                        *(int *)(Globals::sub_menu_buttons_y + uVar15 * 4) = (int)local_44;
                        iVar12 = *(int *)(this_00 + 0x74);
                      }
                      uVar15 = uVar15 + 1;
                      uVar13 = **(uint **)(iVar12 + 4);
                    } while (uVar15 < uVar13);
                  }
                  Globals::sub_menu_button_count = uVar13;
                  *(undefined4 *)(this_00 + 0xcc) = 0;
                  pSVar9 = (Ship *)Status::getShip(Globals::status);
                  puVar11 = (uint *)Ship::getCargo(pSVar9);
                  fVar17 = extraout_s0_00;
                  if ((puVar11 != (uint *)0x0) && (*puVar11 != 0)) {
                    uVar13 = 0;
                    do {
                      iVar12 = Item::getIndex(*(Item **)(puVar11[1] + uVar13 * 4));
                      fVar17 = extraout_s0_01;
                      if ((0x83 < iVar12) &&
                         (iVar12 = Item::getIndex(*(Item **)(puVar11[1] + uVar13 * 4)),
                         fVar17 = extraout_s0_02, iVar12 < 0x9a)) {
                        iVar12 = Item::getAmount(*(Item **)(puVar11[1] + uVar13 * 4));
                        *(int *)(this_00 + 0xcc) = iVar12 + *(int *)(this_00 + 0xcc);
                        fVar17 = extraout_s0_03;
                      }
                      uVar13 = uVar13 + 1;
                    } while (uVar13 < *puVar11);
                  }
                  FModSound::setParamValue((int)Globals::sound,0,fVar17);
                  fVar17 = (float)FModSound::stop(Globals::sound,0x7a);
                  FModSound::play(Globals::sound,0x5f,(Vector *)0x0,(Vector *)0x0,fVar17);
                  this_04 = (Engine *)
                            AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
                  MVar2 = (ModStation)AbyssEngine::Engine::IsPostEffectActivated(this_04);
                  this_00[0x128] = MVar2;
                  uVar3 = FUN_00261924(1,&PTR_hints_002658f4);
                  uVar1 = Globals::layout;
                  if (*(char *)(*extraout_r1 + 8) == '\0') {
                    Globals::hints[8] = uVar3;
                    pSVar4 = (String *)GameText::getText(Globals::gameText,0x26e);
                    AbyssEngine::String::String(aSStack_50,pSVar4,false);
                    Layout::initHelpWindow(uVar1,aSStack_50);
                    AbyssEngine::String::~String(aSStack_50);
                  }
                }
                break;
              case 1:
                iVar12 = Status::getCurrentCampaignMission(Globals::status);
                if ((iVar12 < 0xd) ||
                   (iVar12 = Status::getCurrentCampaignMission(Globals::status), iVar12 == 0x31))
                goto LAB_000eca24;
                pSVar5 = (Station *)Status::getStation(Globals::status);
                iVar12 = Station::getIndex(pSVar5);
                if (iVar12 == 0x58) {
                  pSVar5 = (Station *)Status::getStation(Globals::status);
                  iVar12 = Station::stationHasPirateBase(pSVar5);
                  if (iVar12 == 1) {
                    if (*(int *)(this_00 + 0x80) == 0) {
                      pDVar6 = operator_new(0x6c);
                      pSVar4 = (String *)GameText::getText(Globals::gameText,0x1b1);
                      pSVar7 = (String *)GameText::getText(Globals::gameText,0x63d);
                      DialogueWindow::DialogueWindow(pDVar6,pSVar4,pSVar7,(int *)&DAT_0026cbf0);
                      *(DialogueWindow **)(this_00 + 0x80) = pDVar6;
                      this_00[0x65] = (ModStation)0x1;
                      this_01 = operator_new(0x88);
                      AbyssEngine::String::String(aSStack_58,"",false);
                      Agent::Agent(this_01,0,aSStack_58,0);
                      AbyssEngine::String::~String(aSStack_58);
                      iVar12 = 0x1b1;
                      goto LAB_000ecb24;
                    }
                    break;
                  }
                }
                if (*(SpaceLounge **)(this_00 + 0x70) == (SpaceLounge *)0x0) {
                  this_03 = operator_new(0x108);
                  fVar17 = (float)SpaceLounge::SpaceLounge(this_03);
                  *(SpaceLounge **)(this_00 + 0x70) = this_03;
                }
                else {
                  fVar17 = (float)SpaceLounge::init(*(SpaceLounge **)(this_00 + 0x70));
                }
                FModSound::setParamValue((int)Globals::sound,0,fVar17);
                fVar17 = (float)FModSound::stop(Globals::sound,0x7a);
                FModSound::play(Globals::sound,0x6c,(Vector *)0x0,(Vector *)0x0,fVar17);
                this_00[0x61] = (ModStation)0x1;
                uVar1 = Globals::layout;
                if (Globals::hints[0xd] == '\0') {
                  Globals::hints[0xd] = '\x01';
                  pSVar4 = (String *)GameText::getText(Globals::gameText,0x273);
                  AbyssEngine::String::String(aSStack_60,pSVar4,false);
                  Layout::initHelpWindow(uVar1,aSStack_60);
                  AbyssEngine::String::~String(aSStack_60);
                }
                break;
              case 2:
                iVar12 = Status::getCurrentCampaignMission(Globals::status);
                if (((iVar12 < 9) ||
                    (iVar12 = Status::getCurrentCampaignMission(Globals::status), iVar12 == 0x30))
                   || (iVar12 = Status::getCurrentCampaignMission(Globals::status), iVar12 == 0x31))
                goto LAB_000eca24;
                pSVar9 = (Ship *)Status::getShip(Globals::status);
                iVar12 = Ship::getCurrentLoad(pSVar9);
                pSVar9 = (Ship *)Status::getShip(Globals::status);
                iVar14 = Ship::getMaxLoad(pSVar9);
                if (iVar14 < iVar12) {
                  iVar12 = 0xcc;
                  this_07 = *(ChoiceWindow **)(this_00 + 0x6c);
                  goto LAB_000eca2e;
                }
                iVar12 = Status::getCurrentCampaignMission(Globals::status);
                if (iVar12 == 0x4d) {
                  pSVar9 = (Ship *)Status::getShip(Globals::status);
                  iVar12 = Ship::getIndex(pSVar9);
                  if (iVar12 != 0x25) {
                    iVar12 = 0x146;
                    this_07 = *(ChoiceWindow **)(this_00 + 0x6c);
                    goto LAB_000eca2e;
                  }
                }
                if (*(StarMap **)(this_00 + 0x10) == (StarMap *)0x0) {
                  this_05 = operator_new(0x1e8);
                  StarMap::StarMap(this_05,false,(Mission *)0x0,false,-1);
                  *(StarMap **)(this_00 + 0x10) = this_05;
                }
                else {
                  StarMap::init(*(StarMap **)(this_00 + 0x10),false,(Mission *)0x0,false,-1);
                }
                pSVar9 = (Ship *)Status::getShip(Globals::status);
                iVar12 = Ship::hasEquipment(pSVar9,0x55,1);
                if (iVar12 == 0) {
                  pSVar9 = (Ship *)Status::getShip(Globals::status);
                  iVar12 = Ship::hasJumpDriveIntegrated(pSVar9);
                  if (iVar12 == 1) goto LAB_000ed018;
                }
                else {
LAB_000ed018:
                  StarMap::setJumpMapMode(*(StarMap **)(this_00 + 0x10),false,true);
                }
                this_00[99] = (ModStation)0x1;
                fVar17 = (float)FModSound::stop(Globals::sound,0x7a);
                FModSound::setParamValue((int)Globals::sound,0,fVar17);
                if ((Globals::hints[0xe] == '\0') &&
                   (iVar12 = Status::getCurrentCampaignMission(Globals::status),
                   uVar1 = Globals::layout, 0xf < iVar12)) {
                  Globals::hints[0xe] = '\x01';
                  pSVar4 = (String *)GameText::getText(Globals::gameText,0x274);
                  AbyssEngine::String::String(aSStack_68,pSVar4,false);
                  Layout::initHelpWindow(uVar1,aSStack_68);
                  AbyssEngine::String::~String(aSStack_68);
                }
                else if ((Globals::hints[0xf] == '\0') &&
                        (iVar12 = Status::getCurrentCampaignMission(Globals::status),
                        uVar1 = Globals::layout, iVar12 < 0x10)) {
                  Globals::hints[0xf] = '\x01';
                  pSVar4 = (String *)GameText::getText(Globals::gameText,0x277);
                  AbyssEngine::String::String(aSStack_70,pSVar4,false);
                  Layout::initHelpWindow(uVar1,aSStack_70);
                  AbyssEngine::String::~String(aSStack_70);
                }
                break;
              case 3:
                iVar12 = Status::getCurrentCampaignMission(Globals::status);
                if (iVar12 < 9) goto LAB_000eca24;
                if (*(MissionsWindow **)(this_00 + 0x7c) == (MissionsWindow *)0x0) {
                  this_02 = operator_new(0x44);
                  fVar17 = (float)MissionsWindow::MissionsWindow(this_02);
                  *(MissionsWindow **)(this_00 + 0x7c) = this_02;
                }
                else {
                  fVar17 = (float)MissionsWindow::init(*(MissionsWindow **)(this_00 + 0x7c));
                }
                this_00[0x60] = (ModStation)0x1;
                FModSound::setParamValue((int)Globals::sound,0,fVar17);
                uVar1 = Globals::layout;
                if (Globals::hints[0x13] == '\0') {
                  Globals::hints[0x13] = '\x01';
                  pSVar4 = (String *)GameText::getText(Globals::gameText,0x27b);
                  AbyssEngine::String::String(aSStack_78,pSVar4,false);
                  Layout::initHelpWindow(uVar1,aSStack_78);
                  AbyssEngine::String::~String(aSStack_78);
                }
                break;
              case 4:
                this_06 = *(StatusWindow **)(this_00 + 0x78);
                if (this_06 == (StatusWindow *)0x0) {
                  this_06 = operator_new(0x7c);
                  StatusWindow::StatusWindow(this_06);
                  *(StatusWindow **)(this_00 + 0x78) = this_06;
                }
                fVar17 = (float)StatusWindow::reInit(this_06);
                this_00[100] = (ModStation)0x1;
                FModSound::setParamValue((int)Globals::sound,0,fVar17);
                uVar1 = Globals::layout;
                if (Globals::iPad == '\0' && Globals::hints[0x18] == '\0') {
                  Globals::hints[0x18] = '\x01';
                  pSVar4 = (String *)GameText::getText(Globals::gameText,0x280);
                  AbyssEngine::String::String(aSStack_80,pSVar4,false);
                  Layout::initHelpWindow(uVar1,aSStack_80);
                  AbyssEngine::String::~String(aSStack_80);
                }
              }
            }
            goto switchD_000ec828_default;
          }
        }
        if ((param_2 == 0x20000) && (bVar16)) {
          this_00[0x5d] = (ModStation)((byte)this_00[0x5d] ^ 1);
        }
      }
      else if (param_2 == 0x10000) {
        if (__stack_chk_guard == local_28) {
          checkMedals(this_00);
          return;
        }
        goto LAB_000ec8e0;
      }
    }
  }
switchD_000ec828_default:
  if (__stack_chk_guard == local_28) {
    return;
  }
LAB_000ec8e0:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ModStation::OnUpdate  @0x000ed2a8  (3708 bytes)
/* ModStation::OnUpdate() */

void __thiscall ModStation::OnUpdate(ModStation *this)

{
  ModStation *pMVar1;
  ModStation MVar2;
  byte bVar3;
  bool bVar4;
  Status *pSVar5;
  PaintCanvas *this_00;
  Achievements *this_01;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  String *pSVar9;
  int iVar10;
  void *pvVar11;
  float fVar12;
  float fVar13;
  Matrix *pMVar14;
  CutScene *this_02;
  SpaceLounge *this_03;
  undefined4 uVar15;
  Mission *pMVar16;
  SolarSystem *this_04;
  Mission *pMVar17;
  Station *pSVar18;
  DialogueWindow *pDVar19;
  String *pSVar20;
  Mission *this_05;
  undefined4 extraout_r1;
  uint uVar21;
  int iVar22;
  undefined4 uVar23;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 extraout_r3_06;
  undefined4 extraout_r3_07;
  undefined4 extraout_r3_08;
  undefined4 extraout_r3_09;
  undefined4 extraout_r3_10;
  undefined4 extraout_r3_11;
  undefined4 extraout_r3_12;
  undefined4 extraout_r3_13;
  undefined4 extraout_r3_14;
  undefined4 extraout_r3_15;
  undefined4 extraout_r3_16;
  undefined4 extraout_r3_17;
  undefined4 extraout_r3_18;
  undefined4 extraout_r3_19;
  ChoiceWindow *pCVar24;
  ScrollTouchBox *this_06;
  TouchButton *this_07;
  int iVar25;
  EaseInOut *pEVar26;
  uint in_fpscr;
  float fVar27;
  float extraout_s0;
  float fVar28;
  float extraout_s0_00;
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
  undefined8 uVar29;
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
  undefined4 extraout_s9;
  undefined4 extraout_s9_00;
  undefined4 extraout_s9_01;
  undefined4 extraout_s9_02;
  undefined4 extraout_s9_03;
  undefined4 extraout_s9_04;
  undefined4 extraout_s9_05;
  undefined4 extraout_s9_06;
  undefined4 extraout_s9_07;
  undefined4 extraout_s9_08;
  undefined4 extraout_s9_09;
  undefined4 extraout_s9_10;
  undefined4 extraout_s9_11;
  undefined4 extraout_s9_12;
  undefined4 extraout_s9_13;
  undefined4 extraout_s9_14;
  undefined4 extraout_s9_15;
  undefined4 extraout_s9_16;
  String aSStack_78 [60];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  iVar7 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis(*(ApplicationManager **)(this + 8));
  if ((iVar7 < 0x97) &&
     (iVar7 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                        (*(ApplicationManager **)(this + 8)), iVar7 < 0)) {
    uVar8 = 0;
  }
  else {
    iVar7 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                      (*(ApplicationManager **)(this + 8));
    if (iVar7 < 0x97) {
      uVar8 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                        (*(ApplicationManager **)(this + 8));
    }
    else {
      uVar8 = 0x96;
    }
  }
  *(uint *)(this + 0x28) = uVar8;
  pMVar1 = this + 0x30;
  uVar21 = *(uint *)pMVar1;
  *(uint *)pMVar1 = uVar21 + uVar8;
  *(uint *)(this + 0x34) = *(int *)(this + 0x34) + ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar21,uVar8)
  ;
  FModSound::updateAll(Globals::sound,(Vector *)0x0,(Vector *)0x0,(Vector *)0x0,(Vector *)0x0);
  Layout::update(Globals::layout,*(int *)(this + 0x28));
  if (this[0x5e] == (ModStation)0x0) {
    Status::incPlayingTime(CONCAT44(extraout_r1,Globals::status));
  }
  this_07 = *(TouchButton **)(this + 0x90);
  Status::getCredits(Globals::status);
  Layout::formatCredits((int)aSStack_78);
  TouchButton::setText(this_07,aSStack_78);
  AbyssEngine::String::~String(aSStack_78);
  this_01 = Globals::achievements;
  iVar7 = Status::getCredits(Globals::status);
  Achievements::updateCredits(this_01,iVar7);
  if ((this[0x24] != (ModStation)0x0) && (Globals::enterSpaceLounge != '\0')) {
    this[0xd4] = (ModStation)0x1;
    Globals::enterSpaceLounge = '\0';
    if (*(SpaceLounge **)(this + 0x70) == (SpaceLounge *)0x0) {
      this_03 = operator_new(0x108);
      fVar27 = (float)SpaceLounge::SpaceLounge(this_03);
      *(SpaceLounge **)(this + 0x70) = this_03;
    }
    else {
      fVar27 = (float)SpaceLounge::init(*(SpaceLounge **)(this + 0x70));
    }
    FModSound::setParamValue((int)Globals::sound,0,fVar27);
    fVar27 = (float)FModSound::stop(Globals::sound,0x7a);
    FModSound::play(Globals::sound,0x6c,(Vector *)0x0,(Vector *)0x0,fVar27);
    this[0x61] = (ModStation)0x1;
    goto LAB_000ed88e;
  }
  iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  uVar15 = extraout_r3;
  fVar27 = extraout_s2;
  uVar23 = extraout_s9;
  fVar28 = extraout_s0;
  fVar12 = extraout_s1;
  if (*(char *)(iVar7 + 0x36) != '\0') {
    pCVar24 = *(ChoiceWindow **)(this + 0x6c);
    pSVar9 = (String *)GameText::getText(Globals::gameText,100);
    fVar28 = (float)ChoiceWindow::set(pCVar24,pSVar9);
    this[0x5f] = (ModStation)0x1;
    *(undefined1 *)(iVar7 + 0x36) = 0;
    uVar15 = extraout_r3_00;
    fVar27 = extraout_s2_00;
    uVar23 = extraout_s9_00;
    fVar12 = extraout_s1_00;
  }
  if ((((*(char *)(iVar7 + 0x35) != '\0') && (*(int **)(iVar7 + 0x4c) != (int *)0x0)) &&
      (**(int **)(iVar7 + 0x4c) != 0)) && (*(int *)(iVar7 + 0x3c) - 0x32U < 5)) {
    iVar10 = Globals::getInAppPurchaseArrayIndex
                       (Globals::globals,*(int *)(iVar7 + 0x3c),*(Array **)(iVar7 + 0x48));
    iVar10 = *(int *)(*(int *)(*(int *)(iVar7 + 0x54) + 4) + iVar10 * 4);
    uVar15 = extraout_r3_01;
    fVar27 = extraout_s2_01;
    uVar23 = extraout_s9_01;
    fVar28 = extraout_s0_00;
    fVar12 = extraout_s1_01;
    if (-1 < iVar10) {
      Status::changeCredits(Globals::status,iVar10);
      autosave(this);
      pCVar24 = *(ChoiceWindow **)(this + 0x6c);
      pSVar9 = (String *)GameText::getText(Globals::gameText,0x7d);
      fVar28 = (float)ChoiceWindow::set(pCVar24,pSVar9);
      this[0x5f] = (ModStation)0x1;
      *(undefined1 *)(iVar7 + 0x35) = 0;
      uVar15 = extraout_r3_02;
      fVar27 = extraout_s2_02;
      uVar23 = extraout_s9_02;
      fVar12 = extraout_s1_02;
      if (*(HangarWindow **)(this + 0x74) != (HangarWindow *)0x0) {
        fVar28 = (float)HangarWindow::hideMessage(*(HangarWindow **)(this + 0x74));
        uVar15 = extraout_r3_03;
        fVar27 = extraout_s2_03;
        uVar23 = extraout_s9_03;
        fVar12 = extraout_s1_03;
      }
      if (*(MenuTouchWindow **)(this + 0x4c) != (MenuTouchWindow *)0x0) {
        pvVar11 = (void *)MenuTouchWindow::~MenuTouchWindow(*(MenuTouchWindow **)(this + 0x4c));
        operator_delete(pvVar11);
        uVar15 = extraout_r3_04;
        fVar27 = extraout_s2_04;
        uVar23 = extraout_s9_04;
        fVar28 = extraout_s0_01;
        fVar12 = extraout_s1_04;
      }
      *(undefined4 *)(this + 0x4c) = 0;
    }
  }
  if (((*(int *)(this + 0x60) == 0) && (this[100] == (ModStation)0x0)) &&
     (this[0x5c] == (ModStation)0x0)) {
    if (*(NewsTicker **)(this + 0x1c) != (NewsTicker *)0x0) {
      NewsTicker::update(*(NewsTicker **)(this + 0x1c),*(int *)(this + 0x28));
    }
    if (*(int *)(this + 0x14) != 0) {
      CutScene::process(*(int *)(this + 0x14));
    }
    iVar25 = *(int *)(this + 0x28);
    iVar7 = -iVar25;
    iVar10 = iVar25;
    if (this[0x12a] != (ModStation)0x0) {
      iVar10 = iVar7;
    }
    fVar27 = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::EaseInOut::Increase(*(EaseInOut **)(this + 0x138),fVar27);
    fVar12 = (float)AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(this + 0x138));
    fVar28 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(this + 0x138));
    fVar13 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(this + 0x138));
    fVar27 = -(fVar12 - fVar13);
    if (0.0 < fVar12 - fVar28) {
      fVar27 = fVar12 - fVar13;
    }
    uVar8 = in_fpscr & 0xfffffff | (uint)(fVar27 == 5.0) << 0x1e | (uint)(5.0 <= fVar27) << 0x1d;
    bVar3 = (byte)(uVar8 >> 0x18);
    if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
      MVar2 = this[0x12a];
      this[0x12a] = (ModStation)((byte)MVar2 ^ 1);
      pEVar26 = *(EaseInOut **)(this + 0x138);
      fVar27 = *(float *)(this + 300);
      iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x83);
      iVar22 = iVar10 + 0x12;
      if (MVar2 == (ModStation)0x0) {
        iVar22 = -0x12 - iVar10;
      }
      fVar12 = (float)VectorSignedToFloat(iVar22,(byte)(uVar8 >> 0x16) & 3);
      AbyssEngine::EaseInOut::SetRange(pEVar26,fVar27 + fVar12,extraout_s1_05);
    }
    iVar10 = iVar7;
    if (this[0x129] != (ModStation)0x0) {
      iVar10 = iVar25;
    }
    fVar27 = (float)VectorSignedToFloat(iVar10,(byte)(uVar8 >> 0x16) & 3);
    AbyssEngine::EaseInOut::Increase(*(EaseInOut **)(this + 0x13c),fVar27);
    fVar12 = (float)AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(this + 0x13c));
    fVar28 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(this + 0x13c));
    fVar13 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(this + 0x13c));
    fVar27 = -(fVar12 - fVar13);
    if (0.0 < fVar12 - fVar28) {
      fVar27 = fVar12 - fVar13;
    }
    uVar8 = uVar8 & 0xfffffff | (uint)(fVar27 == 5.0) << 0x1e | (uint)(5.0 <= fVar27) << 0x1d;
    bVar3 = (byte)(uVar8 >> 0x18);
    if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
      MVar2 = this[0x129];
      this[0x129] = (ModStation)((byte)MVar2 ^ 1);
      pEVar26 = *(EaseInOut **)(this + 0x13c);
      fVar27 = *(float *)(this + 0x130);
      iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x78);
      iVar22 = iVar10 + 0x1e;
      if (MVar2 == (ModStation)0x0) {
        iVar22 = -0x1e - iVar10;
      }
      fVar12 = (float)VectorSignedToFloat(iVar22,(byte)(uVar8 >> 0x16) & 3);
      AbyssEngine::EaseInOut::SetRange(pEVar26,fVar27 + fVar12,extraout_s1_06);
    }
    if (this[299] != (ModStation)0x0) {
      iVar7 = iVar25;
    }
    fVar27 = (float)VectorSignedToFloat(iVar7,(byte)(uVar8 >> 0x16) & 3);
    AbyssEngine::EaseInOut::Increase(*(EaseInOut **)(this + 0x140),fVar27);
    fVar12 = (float)AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(this + 0x140));
    fVar28 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(this + 0x140));
    fVar13 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(this + 0x140));
    fVar27 = -(fVar12 - fVar13);
    if (0.0 < fVar12 - fVar28) {
      fVar27 = fVar12 - fVar13;
    }
    in_fpscr = uVar8 & 0xfffffff | (uint)(fVar27 == 5.0) << 0x1e | (uint)(5.0 <= fVar27) << 0x1d;
    bVar3 = (byte)(in_fpscr >> 0x18);
    if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
      MVar2 = this[299];
      this[299] = (ModStation)((byte)MVar2 ^ 1);
      pEVar26 = *(EaseInOut **)(this + 0x140);
      fVar27 = *(float *)(this + 0x134);
      iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
      iVar10 = iVar7 + 0x32;
      if (MVar2 == (ModStation)0x0) {
        iVar10 = -0x32 - iVar7;
      }
      fVar12 = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::EaseInOut::SetRange(pEVar26,fVar27 + fVar12,extraout_s1_07);
    }
    this_00 = Globals::Canvas;
    uVar8 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar14 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar8);
    fVar28 = (float)AbyssEngine::AEMath::MatrixSetTranslation
                              ((AEMath *)aSStack_78,pMVar14,extraout_s0_02,extraout_s1_08,
                               extraout_s2_05);
    uVar15 = extraout_r3_05;
    fVar27 = extraout_s2_06;
    uVar23 = extraout_s9_05;
    fVar12 = extraout_s1_09;
  }
  if (*(int *)(this + 0x34) < (int)(uint)(*(uint *)pMVar1 < 1000)) goto LAB_000ed88e;
  if (this[0x5c] == (ModStation)0x0) {
    if (this[0x65] == (ModStation)0x0) {
      if (this[99] == (ModStation)0x0) {
        if (this[0x62] == (ModStation)0x0) {
          if ((*(ushort *)(this + 0x60) & 0xff) == 0) {
            if (*(ushort *)(this + 0x60) < 0x100) {
              if (this[100] != (ModStation)0x0) {
                fVar28 = (float)StatusWindow::update(*(int *)(this + 0x78));
                uVar15 = extraout_r3_12;
                fVar27 = extraout_s2_13;
                uVar23 = extraout_s9_12;
                fVar12 = extraout_s1_16;
              }
            }
            else {
              fVar28 = (float)SpaceLounge::update(*(SpaceLounge **)(this + 0x70),
                                                  *(int *)(this + 0x28));
              uVar15 = extraout_r3_13;
              fVar27 = extraout_s2_14;
              uVar23 = extraout_s9_13;
              fVar12 = extraout_s1_17;
            }
          }
          else {
            fVar28 = (float)MissionsWindow::update(*(int *)(this + 0x7c));
            uVar15 = extraout_r3_11;
            fVar27 = extraout_s2_12;
            uVar23 = extraout_s9_11;
            fVar12 = extraout_s1_15;
          }
        }
        else {
          fVar28 = (float)HangarWindow::update
                                    (*(HangarWindow **)(this + 0x74),*(int *)(this + 0x28));
          uVar15 = extraout_r3_10;
          fVar27 = extraout_s2_11;
          uVar23 = extraout_s9_10;
          fVar12 = extraout_s1_14;
        }
      }
      else {
        fVar28 = (float)StarMap::update(*(int *)(this + 0x10));
        uVar15 = extraout_r3_08;
        fVar27 = extraout_s2_09;
        uVar23 = extraout_s9_08;
        fVar12 = extraout_s1_12;
      }
    }
    else {
      fVar28 = (float)DialogueWindow::update
                                (*(DialogueWindow **)(this + 0x80),*(int *)(this + 0x28));
      uVar15 = extraout_r3_07;
      fVar27 = extraout_s2_08;
      uVar23 = extraout_s9_07;
      fVar12 = extraout_s1_11;
    }
  }
  else {
    iVar7 = *(int *)(this + 0xb0);
    if ((iVar7 < -6000) && (-0x1771 < *(int *)(this + 0x28) + iVar7)) {
      if (*(CutScene **)(this + 0x14) != (CutScene *)0x0) {
        pvVar11 = (void *)CutScene::~CutScene(*(CutScene **)(this + 0x14));
        operator_delete(pvVar11);
      }
      *(undefined4 *)(this + 0x14) = 0;
      this_02 = operator_new(0xa0);
      CutScene::CutScene(this_02,2);
      *(CutScene **)(this + 0x14) = this_02;
      CutScene::initialize(this_02);
      *(undefined4 *)(*(int *)(this + 0x14) + 0x24) = 0x37fba882;
      this[0x5c] = (ModStation)0x1;
      iVar7 = *(int *)(this + 0xb0);
    }
    *(int *)(this + 0xb0) = iVar7 + *(int *)(this + 0x28);
    CutScene::update(*(int *)(this + 0x14));
    iVar7 = Radio::lastMessageShown(*(Radio **)(this + 0x50));
    uVar15 = extraout_r3_06;
    fVar27 = extraout_s2_07;
    uVar23 = extraout_s9_06;
    fVar28 = extraout_s0_03;
    fVar12 = extraout_s1_10;
    if (iVar7 == 1) {
      fVar27 = (float)VectorSignedToFloat(Globals::h / 2,(byte)(in_fpscr >> 0x16) & 3);
      fVar28 = *(float *)(this + 0x104);
      iVar7 = *(int *)(this + 0x28);
      uVar8 = in_fpscr & 0xfffffff;
      uVar21 = uVar8 | (uint)(fVar28 < fVar27) << 0x1f | (uint)(fVar28 == fVar27) << 0x1e;
      in_fpscr = uVar21 | (uint)(NAN(fVar28) || NAN(fVar27)) << 0x1c;
      bVar3 = (byte)(uVar21 >> 0x18);
      if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar13 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
        fVar13 = fVar28 + fVar13 * -0.03;
        in_fpscr = uVar8 | (uint)(fVar13 == fVar27) << 0x1e | (uint)(fVar27 <= fVar13) << 0x1d;
        bVar3 = (byte)(in_fpscr >> 0x18);
        if (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) {
          *(undefined4 *)(this + 0xb4) = 4000;
          *(float *)(this + 0x104) = fVar13;
          fVar28 = fVar13;
        }
      }
      if (*(int *)(this + 0xb4) < 1) {
        fVar27 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
        fVar28 = fVar28 + fVar27 * -0.03;
        *(float *)(this + 0x104) = fVar28;
        this_06 = *(ScrollTouchBox **)(this + 0x94);
        fVar13 = *(float *)(this + 0x100);
        uVar15 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x58));
        fVar27 = (float)VectorSignedToFloat(uVar15,(byte)(in_fpscr >> 0x16) & 3);
        fVar12 = (float)VectorSignedToFloat(Globals::h / 2,(byte)(in_fpscr >> 0x16) & 3);
        fVar28 = (float)ScrollTouchBox::setPosition
                                  (this_06,(int)fVar13,(int)(fVar28 + fVar27 + fVar12));
        uVar15 = extraout_r3_09;
        fVar27 = extraout_s2_10;
        uVar23 = extraout_s9_09;
        fVar12 = extraout_s1_13;
      }
      else {
        *(int *)(this + 0xb4) = *(int *)(this + 0xb4) - iVar7;
      }
    }
    if (0x21340 < *(int *)(this + 0xb0)) {
      this[0x24] = (ModStation)0x0;
      Status::nextCampaignMission(SUB41(Globals::status,0));
      Globals::switch_to_target_setting = 0;
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
      this[0x5c] = (ModStation)0x0;
      goto LAB_000ed88e;
    }
  }
  if (this[0x5f] != (ModStation)0x0) {
    fVar28 = (float)ChoiceWindow::update(*(int *)(this + 0x6c));
    uVar15 = extraout_r3_14;
    fVar27 = extraout_s2_15;
    uVar23 = extraout_s9_14;
    fVar12 = extraout_s1_18;
  }
  if ((*(ushort *)(this + 0x5e) & 0xff) == 0) {
    uVar6 = *(ushort *)(this + 0x5e) >> 8;
  }
  else {
    fVar28 = (float)MenuTouchWindow::update(*(int *)(this + 0x4c));
    uVar6 = (ushort)(byte)this[0x5f];
    uVar15 = extraout_r3_15;
    fVar27 = extraout_s2_16;
    uVar23 = extraout_s9_15;
    fVar12 = extraout_s1_19;
  }
  if (((uVar6 == 0) && (this[0x65] == (ModStation)0x0)) && (this[0xac] == (ModStation)0x0)) {
    if (this[0xd6] == (ModStation)0x0) {
      checkPendingProducts(this);
      this[0xd6] = (ModStation)0x1;
      uVar15 = extraout_r3_16;
    }
    if (this[0xd5] == (ModStation)0x0) {
      checkMedals(this);
      this[0xd5] = (ModStation)0x1;
      uVar15 = extraout_r3_17;
    }
    if (((this[0x66] == (ModStation)0x0) && (this[0x6a] != (ModStation)0x0)) &&
       (Globals::hints[0x2a] == '\0')) {
      pCVar24 = *(ChoiceWindow **)(this + 0x6c);
      pSVar9 = (String *)GameText::getText(Globals::gameText,0x259);
      ChoiceWindow::set(pCVar24,pSVar9);
      this[0x5f] = (ModStation)0x1;
      Globals::hints[0x2a] = '\x01';
      this[0x6a] = (ModStation)0x0;
      uVar15 = extraout_r3_18;
    }
    pSVar5 = Globals::status;
    bVar4 = false;
    uVar23 = 0;
    if (this[0x61] != (ModStation)0x0) {
      uVar23 = SpaceLounge::introFinished(*(SpaceLounge **)(this + 0x70));
      uVar15 = extraout_r3_19;
    }
    pMVar16 = (Mission *)Status::missionCompleted(SUB41(pSVar5,0),true,CONCAT44(uVar15,uVar23));
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if ((pMVar16 == (Mission *)0x0) && (iVar7 == 0x74)) {
      if ((this[0x61] != (ModStation)0x0) &&
         (iVar7 = SpaceLounge::introFinished(*(SpaceLounge **)(this + 0x70)), iVar7 == 1)) {
        this_04 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar7 = SolarSystem::getIndex(this_04);
        if (iVar7 == 0x12) {
          pMVar17 = (Mission *)Status::getCampaignMission(Globals::status);
          uVar8 = Mission::getStatusValue(pMVar17);
          pSVar18 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::getIndex(pSVar18);
          bVar4 = true;
          if ((1 << (iVar7 - 0x5aU & 0xff) & uVar8) == 0) {
            pMVar17 = (Mission *)Status::getCampaignMission(Globals::status);
            this_05 = (Mission *)Status::getCampaignMission(Globals::status);
            uVar8 = Mission::getStatusValue(this_05);
            pSVar18 = (Station *)Status::getStation(Globals::status);
            iVar7 = Station::getIndex(pSVar18);
            Mission::setStatusValue(pMVar17,1 << (iVar7 - 0x5aU & 0xff) | uVar8);
            goto LAB_000edb36;
          }
        }
      }
      bVar4 = false;
    }
LAB_000edb36:
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar7 < 0x94) || (iVar7 = Status::getCurrentCampaignMission(Globals::status), 0x97 < iVar7)
       ) {
LAB_000edc66:
      if (bVar4) {
        pSVar18 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::getIndex(pSVar18);
        iVar10 = iVar7 + -0x5a;
        if (iVar7 == 0x5e) {
          iVar10 = 3;
        }
        FModSound::play(Globals::sound,iVar10 + 0x619,(Vector *)0x0,(Vector *)0x0,extraout_s0_04);
        iVar7 = iVar10 + 0xa9c;
        iVar25 = 0x3a;
        if (iVar7 == 0xa9d) {
          iVar25 = 0x39;
        }
        if (iVar10 == 0 || iVar7 == 0xa9e) {
          iVar25 = 0;
        }
        pDVar19 = operator_new(0x6c);
        pSVar9 = (String *)GameText::getText(Globals::gameText,iVar7);
        iVar22 = 0x5ec;
        if (iVar10 == 0 || iVar7 == 0xa9e) {
          iVar22 = 0x63d;
        }
        pSVar20 = (String *)GameText::getText(Globals::gameText,iVar22);
        DialogueWindow::DialogueWindow(pDVar19,pSVar9,pSVar20,(int *)(&PTR_DAT_00263fb8)[iVar25]);
        *(DialogueWindow **)(this + 0x80) = pDVar19;
        this[0x65] = (ModStation)0x1;
      }
      else if (pMVar16 == (Mission *)0x0) {
        pMVar16 = (Mission *)Status::missionFailed(SUB41(Globals::status,0),0);
        if (pMVar16 != (Mission *)0x0) {
          pDVar19 = operator_new(0x6c);
          DialogueWindow::DialogueWindow(pDVar19,pMVar16,(Level *)0x0,2);
          *(DialogueWindow **)(this + 0x80) = pDVar19;
          this[0x65] = (ModStation)0x1;
          Status::removeMission(Globals::status,pMVar16);
          iVar7 = Mission::getType(pMVar16);
          pSVar5 = Globals::status;
          if (iVar7 == 0xd) {
            Globals::status[0xf0] = (Status)0x0;
            pSVar5[0xf1] = (Status)0x0;
            autosave(this);
          }
        }
      }
      else {
        *(Mission **)(this + 0x98) = pMVar16;
        pDVar19 = operator_new(0x6c);
        DialogueWindow::DialogueWindow(pDVar19,pMVar16,(Level *)0x0,1);
        *(DialogueWindow **)(this + 0x80) = pDVar19;
        this[0x65] = (ModStation)0x1;
        iVar7 = Mission::getType(pMVar16);
        pSVar5 = Globals::status;
        if (iVar7 == 0xd) {
          Globals::status[0xf0] = (Status)0x0;
          pSVar5[0xf1] = (Status)0x0;
          autosave(this);
        }
        if (*(SpaceLounge **)(this + 0x70) != (SpaceLounge *)0x0) {
          SpaceLounge::setHangarUpdate(*(SpaceLounge **)(this + 0x70),true);
        }
      }
    }
    else {
      pSVar18 = (Station *)Status::getStation(Globals::status);
      iVar7 = Station::getIndex(pSVar18);
      if (iVar7 == 0x37) {
        uVar8 = 1;
      }
      else if (iVar7 == 0x42) {
        uVar8 = 2;
      }
      else {
        uVar8 = 0;
        if (iVar7 == 9) {
          uVar8 = 4;
        }
      }
      if (pMVar16 == (Mission *)0x0) {
        if ((((this[0x61] != (ModStation)0x0) &&
             (iVar10 = SpaceLounge::introFinished(*(SpaceLounge **)(this + 0x70)), iVar10 == 1)) &&
            (iVar10 = Status::getCurrentCampaignMission(Globals::status), 0x93 < iVar10)) &&
           ((iVar10 = Status::getCurrentCampaignMission(Globals::status), iVar10 < 0x97 &&
            ((iVar7 == 9 || iVar7 == 0x37 || (iVar7 == 0x42)))))) {
          pMVar17 = (Mission *)Status::getCampaignMission(Globals::status);
          uVar21 = Mission::getStatusValue(pMVar17);
          if ((uVar21 & uVar8) == 0) {
            pMVar16 = (Mission *)Status::getCampaignMission(Globals::status);
            pMVar17 = (Mission *)Status::getCampaignMission(Globals::status);
            uVar21 = Mission::getStatusValue(pMVar17);
            Mission::setStatusValue(pMVar16,uVar21 | uVar8);
            pSVar18 = (Station *)Status::getStation(Globals::status);
            iVar7 = Station::getIndex(pSVar18);
            iVar10 = 0x94;
            if (iVar7 == 0x42) {
              iVar10 = 0x95;
            }
            if (iVar7 == 9) {
              iVar10 = 0x96;
            }
            pDVar19 = operator_new(0x6c);
            DialogueWindow::DialogueWindow(pDVar19);
            *(DialogueWindow **)(this + 0x80) = pDVar19;
            pMVar16 = operator_new(100);
            Mission::Mission(pMVar16,0xa0,0,-1);
            Mission::setCampaignMission(pMVar16,true);
            pDVar19 = *(DialogueWindow **)(this + 0x80);
            goto LAB_000edc04;
          }
        }
        goto LAB_000edc66;
      }
      if (((this[0x61] == (ModStation)0x0) ||
          (iVar10 = SpaceLounge::introFinished(*(SpaceLounge **)(this + 0x70)), iVar10 != 1)) ||
         ((iVar10 = Status::getCurrentCampaignMission(Globals::status), iVar10 < 0x94 ||
          ((iVar10 = Status::getCurrentCampaignMission(Globals::status), iVar7 != 0x60 ||
           (0x96 < iVar10)))))) goto LAB_000edc66;
      Status::setCurrentCampaignMission(Globals::status,0x97);
      pDVar19 = operator_new(0x6c);
      DialogueWindow::DialogueWindow(pDVar19);
      iVar10 = 0x97;
      *(DialogueWindow **)(this + 0x80) = pDVar19;
      *(Mission **)(this + 0x98) = pMVar16;
LAB_000edc04:
      DialogueWindow::set(pDVar19,pMVar16,1,iVar10);
      this[0x65] = (ModStation)0x1;
    }
    fVar28 = (float)checkHints(this);
    fVar27 = extraout_s2_17;
    uVar23 = extraout_s9_16;
    fVar12 = extraout_s1_20;
  }
  if (this[0xfc] == (ModStation)0x0) {
    fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x28),(byte)(in_fpscr >> 0x16) & 3);
    uVar29 = FloatVectorMin(CONCAT44(fVar12,fVar27 * 0.05),CONCAT44(uVar23,0x3f800000),2,0x20);
    fVar27 = *(float *)(this + 0xf0) * (float)uVar29;
    fVar12 = (float)((ulonglong)uVar29 >> 0x20);
    fVar28 = *(float *)(this + 0xf4) * fVar27;
    fVar27 = -(*(float *)(this + 0xf4) * fVar27);
    if (0.0 < fVar28) {
      fVar27 = fVar28;
    }
    *(float *)(this + 0xf4) = fVar28;
    uVar8 = in_fpscr & 0xfffffff | (uint)(fVar27 < 1.0) << 0x1f | (uint)(fVar27 == 1.0) << 0x1e;
    in_fpscr = uVar8 | (uint)NAN(fVar27) << 0x1c;
    bVar3 = (byte)(uVar8 >> 0x18);
    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xe0),(byte)(in_fpscr >> 0x16) & 3)
      ;
      fVar28 = (float)(int)(fVar28 + fVar27);
      *(float *)(this + 0xe0) = fVar28;
    }
  }
  iVar7 = *(int *)(this + 0x14);
  if ((iVar7 != 0) && (this[0x5c] == (ModStation)0x0)) {
    fVar27 = 120.0;
    fVar28 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xe0),(byte)(in_fpscr >> 0x16) & 3);
    fVar28 = fVar28 / 120.0;
    *(float *)(iVar7 + 4) = fVar28;
  }
  if (this[0x114] != (ModStation)0x0) {
    iVar10 = *(int *)(this + 0x110);
    if (iVar10 < *(int *)(Globals::layout + 0xc)) {
      iVar10 = *(int *)(this + 0x10c);
      if (iVar10 < 100) {
        AEGeometry::translate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
        fVar27 = -10.0;
      }
      else {
        if (199 < iVar10) {
          if (iVar10 < 300) {
            AEGeometry::rotate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
            iVar7 = *(int *)(this + 0x14);
            fVar27 = 0.01;
          }
          else {
            if (399 < iVar10) goto LAB_000ed88e;
            AEGeometry::rotate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
            iVar7 = *(int *)(this + 0x14);
            fVar27 = -0.01;
          }
          *(float *)(iVar7 + 0x14) = *(float *)(iVar7 + 0x14) + fVar27;
          goto LAB_000ed88e;
        }
        AEGeometry::translate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
        fVar27 = 10.0;
      }
      *(float *)(*(int *)(this + 0x14) + 0xc) = *(float *)(*(int *)(this + 0x14) + 0xc) + fVar27;
    }
    else {
      iVar25 = *(int *)(this + 0x10c);
      if (iVar10 < Globals::h + *(int *)(Globals::layout + 0x10) * -2) {
        if (iVar25 < 0x46) {
          AEGeometry::rotate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
          iVar7 = *(int *)(this + 0x14);
          fVar27 = 0.01;
        }
        else {
          if (iVar25 <= Globals::w + -0x46) {
            if ((100 < iVar25) && (iVar25 < Globals::w + -100)) {
              if (iVar10 < Globals::h / 2) {
                fVar27 = (float)VectorSignedToFloat(-*(int *)(this + 0x28),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                AEGeometry::moveForward(*(AEGeometry **)(iVar7 + 0x20),fVar27);
                fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x28),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                *(float *)(*(int *)(this + 0x14) + 0x10) =
                     *(float *)(*(int *)(this + 0x14) + 0x10) - fVar27;
              }
              else {
                fVar27 = (float)VectorSignedToFloat(*(int *)(this + 0x28),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                AEGeometry::moveForward(*(AEGeometry **)(iVar7 + 0x20),fVar27);
                fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x28),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                *(float *)(*(int *)(this + 0x14) + 0x10) =
                     fVar27 + *(float *)(*(int *)(this + 0x14) + 0x10);
              }
            }
            goto LAB_000ed88e;
          }
          AEGeometry::rotate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
          iVar7 = *(int *)(this + 0x14);
          fVar27 = -0.01;
        }
        *(float *)(iVar7 + 0x18) = *(float *)(iVar7 + 0x18) + fVar27;
      }
      else {
        if (iVar25 < 0x46) {
          fVar28 = (float)VectorSignedToFloat(-*(int *)(this + 0x28),(byte)(in_fpscr >> 0x16) & 3);
          AEGeometry::translate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
          fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x28),
                                              (byte)(in_fpscr >> 0x16) & 3);
          iVar7 = *(int *)(this + 0x14);
          fVar27 = *(float *)(iVar7 + 8) - fVar27;
        }
        else {
          if (iVar25 <= Globals::w + -0x46) goto LAB_000ed88e;
          fVar28 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x28),
                                              (byte)(in_fpscr >> 0x16) & 3);
          AEGeometry::translate(*(AEGeometry **)(iVar7 + 0x20),fVar28,fVar12,fVar27);
          fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x28),
                                              (byte)(in_fpscr >> 0x16) & 3);
          iVar7 = *(int *)(this + 0x14);
          fVar27 = fVar27 + *(float *)(iVar7 + 8);
        }
        *(float *)(iVar7 + 8) = fVar27;
      }
    }
  }
LAB_000ed88e:
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ModStation::checkPendingProducts  @0x000ee258  (532 bytes)
/* ModStation::checkPendingProducts() */

void __thiscall ModStation::checkPendingProducts(ModStation *this)

{
  GameText *this_00;
  int iVar1;
  String *pSVar2;
  uint *puVar3;
  Station *this_01;
  int iVar4;
  Item *this_02;
  Ship *this_03;
  undefined4 uVar5;
  PendingProduct *pPVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  String aSStack_68 [8];
  undefined4 local_60 [2];
  String aSStack_58 [8];
  AbyssEngine aAStack_50 [8];
  AbyssEngine aAStack_48 [8];
  AbyssEngine aAStack_40 [8];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  pSVar2 = (String *)GameText::getText(Globals::gameText,0xd5);
  AbyssEngine::String::String(aSStack_38,"\n",false);
  AbyssEngine::operator+(aAStack_30,pSVar2,aSStack_38);
  AbyssEngine::String::~String(aSStack_38);
  puVar3 = (uint *)Status::getPendingProducts(Globals::status);
  if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
    uVar11 = 0;
    do {
      iVar9 = *(int *)(puVar3[1] + uVar11 * 4);
      if (iVar9 != 0) {
        iVar10 = *(int *)(iVar9 + 8);
        this_01 = (Station *)Status::getStation(Globals::status);
        iVar4 = Station::getIndex(this_01);
        if (iVar10 == iVar4) {
          if (iVar1 == 0x92 && *(int *)(iVar9 + 0x10) == 0xd2) {
            uVar8 = puVar3[1];
            pPVar6 = *(PendingProduct **)(uVar8 + uVar11 * 4);
            if (pPVar6 != (PendingProduct *)0x0) {
              pvVar7 = (void *)PendingProduct::~PendingProduct(pPVar6);
              operator_delete(pvVar7);
              uVar8 = puVar3[1];
            }
            *(undefined4 *)(uVar8 + uVar11 * 4) = 0;
            goto LAB_000ee44e;
          }
          this_02 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) +
                                                     *(int *)(iVar9 + 0x10) * 4),
                                           *(int *)(iVar9 + 0xc));
          this_03 = (Ship *)Status::getShip(Globals::status);
          Ship::addCargo(this_03,this_02);
          AbyssEngine::String::String(aSStack_58,"\n",false);
          AbyssEngine::operator+(aAStack_50,aAStack_30,aSStack_58);
          uVar5 = Item::getAmount(this_02);
          local_60[0] = 0;
          AbyssEngine::String::Set(CONCAT44(uVar5,(String *)local_60));
          AbyssEngine::operator+(aAStack_48,aAStack_50,(String *)local_60);
          AbyssEngine::String::String(aSStack_68,"x ",false);
          AbyssEngine::operator+(aAStack_40,aAStack_48,aSStack_68);
          this_00 = Globals::gameText;
          iVar9 = Item::getIndex(this_02);
          pSVar2 = (String *)GameText::getText(this_00,iVar9 + 0x4fa);
          AbyssEngine::operator+((AbyssEngine *)aSStack_38,aAStack_40,pSVar2);
          AbyssEngine::String::operator=((String *)aAStack_30,(AbyssEngine *)aSStack_38);
          AbyssEngine::String::~String(aSStack_38);
          AbyssEngine::String::~String((String *)aAStack_40);
          AbyssEngine::String::~String(aSStack_68);
          AbyssEngine::String::~String((String *)aAStack_48);
          AbyssEngine::String::~String((String *)local_60);
          AbyssEngine::String::~String((String *)aAStack_50);
          AbyssEngine::String::~String(aSStack_58);
          uVar8 = puVar3[1];
          pPVar6 = *(PendingProduct **)(uVar8 + uVar11 * 4);
          if (pPVar6 != (PendingProduct *)0x0) {
            pvVar7 = (void *)PendingProduct::~PendingProduct(pPVar6);
            operator_delete(pvVar7);
            uVar8 = puVar3[1];
          }
          *(undefined4 *)(uVar8 + uVar11 * 4) = 0;
          this[0x5f] = (ModStation)0x1;
        }
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < *puVar3);
  }
  if (this[0x5f] != (ModStation)0x0) {
    ChoiceWindow::set(*(ChoiceWindow **)(this + 0x6c),aAStack_30);
  }
LAB_000ee44e:
  AbyssEngine::String::~String((String *)aAStack_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ModStation::checkHints  @0x000ee500  (2634 bytes)
/* ModStation::checkHints() */

void __thiscall ModStation::checkHints(ModStation *this)

{
  Status *pSVar1;
  GameText *pGVar2;
  FModSound *this_00;
  int iVar3;
  String *pSVar4;
  String *pSVar5;
  String *pSVar6;
  String *pSVar7;
  String *pSVar8;
  undefined4 uVar9;
  void *pvVar10;
  DialogueWindow *pDVar11;
  Agent *this_01;
  ChoiceWindow *pCVar12;
  float fVar13;
  float extraout_s0;
  String aSStack_100 [8];
  String aSStack_f8 [8];
  String aSStack_f0 [8];
  String aSStack_e8 [8];
  String aSStack_e0 [8];
  String aSStack_d8 [8];
  String aSStack_d0 [8];
  String aSStack_c8 [8];
  String aSStack_c0 [8];
  String aSStack_b8 [8];
  String aSStack_b0 [8];
  String aSStack_a8 [8];
  String aSStack_a0 [8];
  String aSStack_98 [8];
  String aSStack_90 [8];
  String aSStack_88 [8];
  String aSStack_80 [8];
  String aSStack_78 [8];
  String aSStack_70 [8];
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((*(uint *)(this + 0x5c) & 0xff) != 0) goto LAB_000eee58;
  if (((this[0x66] == (ModStation)0x0) &&
      (*(uint *)(this + 0x5c) >> 0x18 == 0 && Globals::options[0x34] == '\0')) &&
     (iVar3 = Status::getCurrentCampaignMission(Globals::status), 0x12 < iVar3)) {
    pCVar12 = *(ChoiceWindow **)(this + 0x6c);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x3e);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x49);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x7e);
    pSVar7 = (String *)GameText::getText(Globals::gameText,0x7f);
    pSVar8 = (String *)GameText::getText(Globals::gameText,0x20c);
    ChoiceWindow::set(pCVar12,pSVar4,pSVar5,true,pSVar6,pSVar7,pSVar8,-1,-1);
    Globals::options[0x34] = '\x01';
    this[0xd8] = (ModStation)0x1;
    this[0x5f] = (ModStation)0x1;
  }
  if (this[0x65] == (ModStation)0x0) {
    if (((this[0x66] == (ModStation)0x0) &&
        (Globals::hints[0x33] == '\0' && this[0x5f] == (ModStation)0x0)) &&
       (iVar3 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x18)),
       iVar3 == 1)) {
      pSVar4 = (String *)GameText::getText(Globals::gameText,0xca0);
      AbyssEngine::String::String(aSStack_30,pSVar4,false);
      pSVar1 = Globals::status;
      AbyssEngine::String::String(aSStack_40,aSStack_30,false);
      pGVar2 = Globals::gameText;
      iVar3 = Wanted::getShip(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x18));
      pSVar4 = (String *)GameText::getText(pGVar2,iVar3 + 0x391);
      AbyssEngine::String::String(aSStack_48,pSVar4,false);
      uVar9 = AbyssEngine::String::String(aSStack_50,"#SHIP_NAME",false);
      Status::replaceHash(aSStack_38,pSVar1,aSStack_40,aSStack_48,uVar9);
      AbyssEngine::String::operator=(aSStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      AbyssEngine::String::~String(aSStack_50);
      AbyssEngine::String::~String(aSStack_48);
      AbyssEngine::String::~String(aSStack_40);
      pSVar1 = Globals::status;
      AbyssEngine::String::String(aSStack_58,aSStack_30,false);
      Wanted::getName();
      uVar9 = AbyssEngine::String::String(aSStack_68,"#WANTED_NAME",false);
      Status::replaceHash(aSStack_38,pSVar1,aSStack_58,aSStack_60,uVar9);
      AbyssEngine::String::operator=(aSStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      AbyssEngine::String::~String(aSStack_68);
      AbyssEngine::String::~String(aSStack_60);
      AbyssEngine::String::~String(aSStack_58);
      ChoiceWindow::set(*(ChoiceWindow **)(this + 0x6c),aSStack_30);
      this[0x5f] = (ModStation)0x1;
      Globals::hints[0x33] = '\x01';
      AbyssEngine::String::~String(aSStack_30);
    }
    if (this[0x65] != (ModStation)0x0) goto LAB_000eeb76;
    if (((this[0x66] == (ModStation)0x0) &&
        (Globals::hints[0x34] == '\0' && this[0x5f] == (ModStation)0x0)) &&
       (iVar3 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x30)),
       iVar3 == 1)) {
      pSVar4 = (String *)GameText::getText(Globals::gameText,0xca0);
      AbyssEngine::String::String(aSStack_30,pSVar4,false);
      pSVar1 = Globals::status;
      AbyssEngine::String::String(aSStack_70,aSStack_30,false);
      pGVar2 = Globals::gameText;
      iVar3 = Wanted::getShip(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x30));
      pSVar4 = (String *)GameText::getText(pGVar2,iVar3 + 0x391);
      AbyssEngine::String::String(aSStack_78,pSVar4,false);
      uVar9 = AbyssEngine::String::String(aSStack_80,"#SHIP_NAME",false);
      Status::replaceHash(aSStack_38,pSVar1,aSStack_70,aSStack_78,uVar9);
      AbyssEngine::String::operator=(aSStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      AbyssEngine::String::~String(aSStack_80);
      AbyssEngine::String::~String(aSStack_78);
      AbyssEngine::String::~String(aSStack_70);
      pSVar1 = Globals::status;
      AbyssEngine::String::String(aSStack_88,aSStack_30,false);
      Wanted::getName();
      uVar9 = AbyssEngine::String::String(aSStack_98,"#WANTED_NAME",false);
      Status::replaceHash(aSStack_38,pSVar1,aSStack_88,aSStack_90,uVar9);
      AbyssEngine::String::operator=(aSStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      AbyssEngine::String::~String(aSStack_98);
      AbyssEngine::String::~String(aSStack_90);
      AbyssEngine::String::~String(aSStack_88);
      ChoiceWindow::set(*(ChoiceWindow **)(this + 0x6c),aSStack_30);
      this[0x5f] = (ModStation)0x1;
      Globals::hints[0x34] = '\x01';
      AbyssEngine::String::~String(aSStack_30);
    }
    if (this[0x65] != (ModStation)0x0) goto LAB_000eeb76;
    if (((this[0x66] == (ModStation)0x0) &&
        (Globals::hints[0x35] == '\0' && this[0x5f] == (ModStation)0x0)) &&
       (iVar3 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x48)),
       iVar3 == 1)) {
      pSVar4 = (String *)GameText::getText(Globals::gameText,0xca0);
      AbyssEngine::String::String(aSStack_30,pSVar4,false);
      pSVar1 = Globals::status;
      AbyssEngine::String::String(aSStack_a0,aSStack_30,false);
      pGVar2 = Globals::gameText;
      iVar3 = Wanted::getShip(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x48));
      pSVar4 = (String *)GameText::getText(pGVar2,iVar3 + 0x391);
      AbyssEngine::String::String(aSStack_a8,pSVar4,false);
      uVar9 = AbyssEngine::String::String(aSStack_b0,"#SHIP_NAME",false);
      Status::replaceHash(aSStack_38,pSVar1,aSStack_a0,aSStack_a8,uVar9);
      AbyssEngine::String::operator=(aSStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      AbyssEngine::String::~String(aSStack_b0);
      AbyssEngine::String::~String(aSStack_a8);
      AbyssEngine::String::~String(aSStack_a0);
      pSVar1 = Globals::status;
      AbyssEngine::String::String(aSStack_b8,aSStack_30,false);
      Wanted::getName();
      uVar9 = AbyssEngine::String::String(aSStack_c8,"#WANTED_NAME",false);
      Status::replaceHash(aSStack_38,pSVar1,aSStack_b8,aSStack_c0,uVar9);
      AbyssEngine::String::operator=(aSStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      AbyssEngine::String::~String(aSStack_c8);
      AbyssEngine::String::~String(aSStack_c0);
      AbyssEngine::String::~String(aSStack_b8);
      ChoiceWindow::set(*(ChoiceWindow **)(this + 0x6c),aSStack_30);
      this[0x5f] = (ModStation)0x1;
      Globals::hints[0x35] = '\x01';
      AbyssEngine::String::~String(aSStack_30);
    }
    if (this[0x65] != (ModStation)0x0) goto LAB_000eeb76;
    if (this[0x66] == (ModStation)0x0) {
      if ((Globals::hints[0x36] == '\0' && this[0x5f] == (ModStation)0x0) &&
         (iVar3 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x60)),
         iVar3 == 1)) {
        pSVar4 = (String *)GameText::getText(Globals::gameText,0xca0);
        AbyssEngine::String::String(aSStack_30,pSVar4,false);
        pSVar1 = Globals::status;
        AbyssEngine::String::String(aSStack_d0,aSStack_30,false);
        pGVar2 = Globals::gameText;
        iVar3 = Wanted::getShip(*(Wanted **)(*(int *)(*(int *)Globals::status + 4) + 0x60));
        pSVar4 = (String *)GameText::getText(pGVar2,iVar3 + 0x391);
        AbyssEngine::String::String(aSStack_d8,pSVar4,false);
        uVar9 = AbyssEngine::String::String(aSStack_e0,"#SHIP_NAME",false);
        Status::replaceHash(aSStack_38,pSVar1,aSStack_d0,aSStack_d8,uVar9);
        AbyssEngine::String::operator=(aSStack_30,aSStack_38);
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::~String(aSStack_e0);
        AbyssEngine::String::~String(aSStack_d8);
        AbyssEngine::String::~String(aSStack_d0);
        pSVar1 = Globals::status;
        AbyssEngine::String::String(aSStack_e8,aSStack_30,false);
        Wanted::getName();
        uVar9 = AbyssEngine::String::String(aSStack_f8,"#WANTED_NAME",false);
        Status::replaceHash(aSStack_38,pSVar1,aSStack_e8,aSStack_f0,uVar9);
        AbyssEngine::String::operator=(aSStack_30,aSStack_38);
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::~String(aSStack_f8);
        AbyssEngine::String::~String(aSStack_f0);
        AbyssEngine::String::~String(aSStack_e8);
        ChoiceWindow::set(*(ChoiceWindow **)(this + 0x6c),aSStack_30);
        this[0x5f] = (ModStation)0x1;
        Globals::hints[0x36] = '\x01';
        AbyssEngine::String::~String(aSStack_30);
      }
      goto LAB_000eeb76;
    }
  }
  else {
LAB_000eeb76:
    if (this[0x66] == (ModStation)0x0) {
      if ((Globals::hints[0x1a] == '\0' && this[0x5f] == (ModStation)0x0) &&
         (iVar3 = Achievements::gotAllMedals(Globals::achievements), iVar3 == 1)) {
        pCVar12 = *(ChoiceWindow **)(this + 0x6c);
        pSVar4 = (String *)GameText::getText(Globals::gameText,0x289);
        ChoiceWindow::set(pCVar12,pSVar4);
        Globals::hints[0x1a] = '\x01';
        this[0x5f] = (ModStation)0x1;
      }
      if (this[0x66] == (ModStation)0x0) {
        if ((Globals::hints[0x1b] == '\0' && this[0x5f] == (ModStation)0x0) &&
           (iVar3 = Achievements::gotAllGoldMedals(Globals::achievements), iVar3 == 1)) {
          pCVar12 = *(ChoiceWindow **)(this + 0x6c);
          pSVar4 = (String *)GameText::getText(Globals::gameText,0x28a);
          ChoiceWindow::set(pCVar12,pSVar4);
          Globals::hints[0x1b] = '\x01';
          this[0x5f] = (ModStation)0x1;
        }
        if (this[0x66] == (ModStation)0x0) {
          if ((((this[0x5f] == (ModStation)0x0) &&
               (iVar3 = Status::isBlueprintUnlocked(Globals::status,0xe8), iVar3 == 0)) &&
              (iVar3 = Achievements::gotAllGoldMedals(Globals::achievements), iVar3 == 1)) &&
             (iVar3 = Achievements::gotAllSupernovaMedals(Globals::achievements), iVar3 == 1)) {
            pCVar12 = *(ChoiceWindow **)(this + 0x6c);
            pSVar4 = (String *)GameText::getText(Globals::gameText,0x28b);
            ChoiceWindow::set(pCVar12,pSVar4);
            Status::unlockBluePrint(Globals::status,0xe8);
            autosave(this);
            this[0x5f] = (ModStation)0x1;
          }
          if ((((this[0x66] == (ModStation)0x0) &&
               (Globals::hints[0x3a] == '\0' && this[0x5f] == (ModStation)0x0)) &&
              (iVar3 = Status::getCurrentCampaignMission(Globals::status), 0xa1 < iVar3)) &&
             ((((iVar3 = Achievements::gotAllGoldMedals(Globals::achievements), iVar3 == 1 &&
                (iVar3 = Achievements::gotAllSupernovaMedals(Globals::achievements), iVar3 == 1)) &&
               (iVar3 = Status::hardCoreMode(), iVar3 != 1)) ||
              (iVar3 = Status::hardCoreMode(), iVar3 == 1)))) {
            Globals::hints[0x3a] = '\x01';
            pCVar12 = *(ChoiceWindow **)(this + 0x6c);
            pSVar4 = (String *)GameText::getText(Globals::gameText,0xca1);
            ChoiceWindow::set(pCVar12,pSVar4);
            autosave(this);
            this[0x5f] = (ModStation)0x1;
          }
        }
      }
    }
  }
  if ((this[0x65] == (ModStation)0x0) && (this[0x66] == (ModStation)0x0)) {
    if (((this[0x5f] == (ModStation)0x0) &&
        (((*(int *)(Globals::status + 0x24) != 0 && (this[0xd7] == (ModStation)0x0)) &&
         (*(int *)(Globals::status + 0x30) < 1)))) && (*(char *)(Globals::layout + 0x2ec) == '\0'))
    {
      if (*(DialogueWindow **)(this + 0x80) != (DialogueWindow *)0x0) {
        pvVar10 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x80));
        operator_delete(pvVar10);
        *(undefined4 *)(this + 0x80) = 0;
      }
      pDVar11 = operator_new(0x6c);
      pSVar4 = (String *)GameText::getText(Globals::gameText,0x139);
      DialogueWindow::DialogueWindow
                (pDVar11,pSVar4,(String *)**(undefined4 **)(*(int *)(Globals::status + 0x24) + 4),
                 *(int **)(Globals::status + 0x28));
      *(DialogueWindow **)(this + 0x80) = pDVar11;
      this_01 = operator_new(0x88);
      AbyssEngine::String::String(aSStack_100,"",false);
      Agent::Agent(this_01,0,aSStack_100,0,0,*(undefined4 *)(Globals::status + 0x2c),1,0,0,0,0);
      AbyssEngine::String::~String(aSStack_100);
      this_00 = Globals::sound;
      iVar3 = Globals::getDialogueSoundId(Globals::globals,0x139,this_01);
      FModSound::play(this_00,iVar3,(Vector *)0x0,(Vector *)0x0,extraout_s0);
      pvVar10 = (void *)Agent::~Agent(this_01);
      operator_delete(pvVar10);
      this[0x65] = (ModStation)0x1;
      this[0xd7] = (ModStation)0x1;
      Status::setWingmen(Globals::status,(Array *)0x0);
    }
    else if (((this[0x5f] == (ModStation)0x0) && (Globals::status[0xf9] != (Status)0x0)) &&
            (*(char *)(Globals::layout + 0x2ec) == '\0')) {
      if (*(DialogueWindow **)(this + 0x80) != (DialogueWindow *)0x0) {
        pvVar10 = (void *)DialogueWindow::~DialogueWindow(*(DialogueWindow **)(this + 0x80));
        operator_delete(pvVar10);
        *(undefined4 *)(this + 0x80) = 0;
      }
      pDVar11 = operator_new(0x6c);
      pSVar4 = (String *)GameText::getText(Globals::gameText,0x1ba);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x67e);
      fVar13 = (float)DialogueWindow::DialogueWindow(pDVar11,pSVar4,pSVar5,(int *)&DAT_0026a1c4);
      *(DialogueWindow **)(this + 0x80) = pDVar11;
      FModSound::play(Globals::sound,0x24d,(Vector *)0x0,(Vector *)0x0,fVar13);
      this[0x65] = (ModStation)0x1;
      pSVar1 = Globals::status;
      Globals::status[0xf9] = (Status)0x0;
      Status::changeCredits(pSVar1,20000);
    }
  }
LAB_000eee58:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ModStation::OnRender2D  @0x000ef208  (1822 bytes)
/* ModStation::OnRender2D() */

void __thiscall ModStation::OnRender2D(ModStation *this)

{
  GameText *this_00;
  Layout *pLVar1;
  ChoiceWindow *this_01;
  int iVar2;
  uint uVar3;
  Station *pSVar4;
  undefined4 uVar5;
  SolarSystem *pSVar6;
  String *pSVar7;
  int iVar8;
  NewsTicker *this_02;
  undefined4 uVar9;
  int iVar10;
  PaintCanvas *pPVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  bool bVar17;
  uint in_fpscr;
  undefined4 local_70 [2];
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::Begin2d(*(PaintCanvas **)(this + 4));
  AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
  if (this[0x24] == (ModStation)0x0) goto LAB_000ef2f6;
  if (this[0x62] == (ModStation)0x0) {
    if (this[0x61] == (ModStation)0x0) {
      if ((*(uint *)(this + 0x60) & 0xff) == 0) {
        if (*(uint *)(this + 0x60) < 0x1000000) {
          if (this[100] == (ModStation)0x0) {
            if (this[0x5e] == (ModStation)0x0) {
              if (this[0x5c] == (ModStation)0x0) {
                Layout::drawFooterStation(Globals::layout);
                pLVar1 = Globals::layout;
                Status::getStation(Globals::status);
                Station::getName();
                AbyssEngine::String::String(aSStack_38,aSStack_40,false);
                pSVar4 = (Station *)Status::getStation(Globals::status);
                iVar2 = Station::getIndex(pSVar4);
                if (iVar2 != 0x65) {
                  AbyssEngine::String::String(aSStack_50," ",false);
                  pSVar7 = (String *)GameText::getText(Globals::gameText,0x88);
                  AbyssEngine::operator+((AbyssEngine *)aSStack_48,aSStack_50,pSVar7);
                }
                else {
                  AbyssEngine::String::String(aSStack_48,"",false);
                }
                AbyssEngine::operator+(aAStack_30,aSStack_38,aSStack_48);
                Layout::drawHeader(pLVar1,aAStack_30);
                AbyssEngine::String::~String((String *)aAStack_30);
                AbyssEngine::String::~String(aSStack_48);
                if (iVar2 != 0x65) {
                  AbyssEngine::String::~String(aSStack_50);
                }
                AbyssEngine::String::~String(aSStack_38);
                AbyssEngine::String::~String(aSStack_40);
                pLVar1 = Globals::layout;
                if (this[0x5d] != (ModStation)0x0) {
                  uVar14 = *(undefined4 *)(this + 0x9c);
                  uVar15 = *(undefined4 *)(this + 0xa0);
                  uVar12 = *(undefined4 *)(this + 0xa4);
                  uVar9 = *(undefined4 *)(this + 0xa8);
                  uVar5 = AbyssEngine::String::String(aSStack_58,"",false);
                  Layout::drawBox(pLVar1,2,uVar14,uVar15,uVar12,uVar9,uVar5);
                  AbyssEngine::String::~String(aSStack_58);
                  pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
                  iVar2 = SolarSystem::hasNoOwner(pSVar6);
                  if (iVar2 == 0) {
                    AbyssEngine::PaintCanvas::DrawImage2D
                              (*(PaintCanvas **)(this + 4),*(uint *)(this + 0x48),
                               *(int *)(Globals::layout + 0x28),
                               *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                               *(int *)(Globals::layout + 0x2c) * 2);
                  }
                  Status::getSystem(Globals::status);
                  SolarSystem::getName();
                  AbyssEngine::String::String(aSStack_48,aSStack_60,false);
                  AbyssEngine::String::String(aSStack_68," ",false);
                  AbyssEngine::operator+((AbyssEngine *)aSStack_40,aSStack_48,aSStack_68);
                  pSVar7 = (String *)GameText::getText(Globals::gameText,0x89);
                  AbyssEngine::operator+((AbyssEngine *)aSStack_38,aSStack_40,pSVar7);
                  AbyssEngine::String::~String(aSStack_40);
                  AbyssEngine::String::~String(aSStack_68);
                  AbyssEngine::String::~String(aSStack_48);
                  AbyssEngine::String::~String(aSStack_60);
                  iVar2 = AbyssEngine::PaintCanvas::GetTextWidth
                                    (Globals::Canvas,Globals::font,aSStack_38);
                  iVar16 = *(int *)(this + 0xa4);
                  iVar10 = *(int *)(Globals::layout + 0x28);
                  iVar13 = *(int *)(Globals::layout + 0x4c);
                  iVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth
                                    (*(PaintCanvas **)(this + 4),*(uint *)(this + 0x48));
                  if (((iVar16 + iVar10 * -2) - iVar13) - iVar8 < iVar2) {
                    Status::getSystem(Globals::status);
                    SolarSystem::getName();
                    AbyssEngine::String::operator=(aSStack_38,aSStack_40);
                    AbyssEngine::String::~String(aSStack_40);
                  }
                  uVar3 = Globals::font;
                  pPVar11 = *(PaintCanvas **)(this + 4);
                  iVar8 = *(int *)(Globals::layout + 0x28);
                  iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(pPVar11,*(uint *)(this + 0x48));
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar11,uVar3,aSStack_38,
                             iVar2 + iVar8 + *(int *)(Globals::layout + 0x4c),
                             *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                             *(int *)(Globals::layout + 0x2c) * 2,false);
                  uVar3 = Globals::font;
                  pPVar11 = *(PaintCanvas **)(this + 4);
                  pSVar7 = (String *)GameText::getText(Globals::gameText,0x85);
                  AbyssEngine::String::String(aSStack_60,": ",false);
                  AbyssEngine::operator+((AbyssEngine *)aSStack_48,pSVar7,aSStack_60);
                  pSVar4 = (Station *)Status::getStation(Globals::status);
                  uVar5 = Station::getTecLevel(pSVar4);
                  local_70[0] = 0;
                  AbyssEngine::String::Set(CONCAT44(uVar5,local_70));
                  AbyssEngine::String::String(aSStack_68,(String *)local_70,false);
                  AbyssEngine::operator+((AbyssEngine *)aSStack_40,aSStack_48,aSStack_68);
                  iVar8 = *(int *)(Globals::layout + 0x28);
                  iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth
                                    (*(PaintCanvas **)(this + 4),*(uint *)(this + 0x48));
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar11,uVar3,aSStack_40,
                             iVar2 + iVar8 + *(int *)(Globals::layout + 0x4c),
                             *(int *)(Globals::layout + 4) +
                             *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                             *(int *)(Globals::layout + 0x2c) * 4,false);
                  AbyssEngine::String::~String(aSStack_40);
                  AbyssEngine::String::~String(aSStack_68);
                  AbyssEngine::String::~String((String *)local_70);
                  AbyssEngine::String::~String(aSStack_48);
                  AbyssEngine::String::~String(aSStack_60);
                  if (Globals::layout[0x286] != (Layout)0x0) {
                    pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
                    iVar2 = SolarSystem::hasNoOwner(pSVar6);
                    uVar3 = Globals::font;
                    this_00 = Globals::gameText;
                    if (iVar2 != 1) {
                      pPVar11 = *(PaintCanvas **)(this + 4);
                      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
                      iVar2 = SolarSystem::getRace(pSVar6);
                      pSVar7 = (String *)GameText::getText(this_00,iVar2 + 0x196);
                      iVar8 = *(int *)(Globals::layout + 0x28);
                      iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth
                                        (*(PaintCanvas **)(this + 4),*(uint *)(this + 0x48));
                      AbyssEngine::PaintCanvas::DrawString
                                (pPVar11,uVar3,pSVar7,
                                 iVar2 + iVar8 + *(int *)(Globals::layout + 0x4c),
                                 *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20)
                                 + *(int *)(Globals::layout + 4) * 2 +
                                 *(int *)(Globals::layout + 0x2c) * 6,false);
                    }
                  }
                  iVar2 = 0;
                  do {
                    TouchButton::draw(*(TouchButton **)
                                       (*(int *)(*(int *)(this + 0x88) + 4) + iVar2 * 4));
                    iVar2 = iVar2 + 1;
                  } while (iVar2 < 5);
                  TouchButton::draw(*(TouchButton **)(this + 0x8c));
                  TouchButton::draw(*(TouchButton **)(this + 0x90));
                  pSVar4 = (Station *)Status::getStation(Globals::status);
                  iVar2 = Station::getIndex(pSVar4);
                  if (iVar2 != 0x65) {
                    pSVar4 = (Station *)Status::getStation(Globals::status);
                    iVar2 = Station::getIndex(pSVar4);
                    if (iVar2 != 0x6c) {
                      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
                      this_02 = (NewsTicker *)SolarSystem::getIndex(pSVar6);
                      bVar17 = this_02 != (NewsTicker *)0x19;
                      if (bVar17) {
                        this_02 = *(NewsTicker **)(this + 0x1c);
                      }
                      if (bVar17 && this_02 != (NewsTicker *)0x0) {
                        NewsTicker::draw(this_02);
                      }
                    }
                  }
                  Layout::drawMissionRewardMessage(Globals::layout,true);
                  AbyssEngine::String::~String(aSStack_38);
                }
                uVar3 = Globals::font;
                iVar2 = *(int *)(this + 0x34);
                if ((int)(-(uint)(2999 < *(uint *)(this + 0x30)) - iVar2) < 0 ==
                    (SBORROW4(0,iVar2) != SBORROW4(-iVar2,(uint)(2999 < *(uint *)(this + 0x30))))) {
                  pPVar11 = *(PaintCanvas **)(this + 4);
                  iVar2 = 0x32;
                  if (this[0xac] != (ModStation)0x0) {
                    iVar2 = 0x36;
                  }
                  pSVar7 = (String *)GameText::getText(Globals::gameText,iVar2);
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar11,uVar3,pSVar7,
                             *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xa4),
                             *(int *)(Globals::layout + 0x18),false);
                }
                else {
                  this[0xac] = (ModStation)0x0;
                }
              }
              else {
                Radio::draw((ulonglong)*(uint *)(this + 0x50),*(PlayerEgo **)(this + 0xb0),
                            (LevelScript *)((int)*(PlayerEgo **)(this + 0xb0) >> 0x1f));
                iVar2 = Radio::lastMessageShown(*(Radio **)(this + 0x50));
                if (iVar2 == 1) {
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)(this + 0x58),0,(int)*(float *)(this + 0x104),
                             '\x14','D');
                  ScrollTouchBox::draw(*(ScrollTouchBox **)(this + 0x94));
                }
                uVar3 = *(uint *)(this + 0xb0);
                if ((int)uVar3 < 0x1fbd1) {
                  if ((int)uVar3 < -6000) {
                    VectorSignedToFloat(uVar3 + 12000,(byte)(in_fpscr >> 0x16) & 3);
                    AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
                    goto LAB_000ef908;
                  }
                  if (0x7fffffff < uVar3) {
                    VectorSignedToFloat(uVar3 + 6000,(byte)(in_fpscr >> 0x16) & 3);
                    AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
                    goto LAB_000ef908;
                  }
                }
                else {
                  VectorSignedToFloat(uVar3 - 130000,(byte)(in_fpscr >> 0x16) & 3);
                  AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
LAB_000ef908:
                  AbyssEngine::PaintCanvas::FillRectangle(Globals::Canvas,0,0,Globals::w,Globals::h)
                  ;
                }
                if (-6000 < *(int *)(this + 0xb0)) {
                  CutScene::render2D();
                }
              }
            }
            else {
              MenuTouchWindow::draw(*(MenuTouchWindow **)(this + 0x4c));
            }
          }
          else {
            StatusWindow::draw(*(StatusWindow **)(this + 0x78));
          }
        }
        else {
          StarMap::draw(*(StarMap **)(this + 0x10));
        }
      }
      else {
        MissionsWindow::draw(*(MissionsWindow **)(this + 0x7c));
      }
    }
    else {
      SpaceLounge::draw(*(SpaceLounge **)(this + 0x70));
    }
  }
  else {
    HangarWindow::render(*(HangarWindow **)(this + 0x74));
  }
  if (this[0x66] == (ModStation)0x0) {
    if (this[0x5f] != (ModStation)0x0) {
      this_01 = *(ChoiceWindow **)(this + 0x6c);
      goto LAB_000ef292;
    }
  }
  else {
    this_01 = *(ChoiceWindow **)(this + 0x84);
LAB_000ef292:
    ChoiceWindow::draw(this_01);
  }
  if (this[0x65] != (ModStation)0x0) {
    DialogueWindow::draw(*(DialogueWindow **)(this + 0x80));
  }
  if (*Globals::layout != (Layout)0x0) {
    Layout::drawHelpWindow();
  }
  AbyssEngine::PaintCanvas::End2d(*(PaintCanvas **)(this + 4));
  if ((*Globals::layout == (Layout)0x0) &&
     (((this[0x62] == (ModStation)0x0 ||
       (HangarWindow::render3D(*(HangarWindow **)(this + 0x74)), *Globals::layout == (Layout)0x0))
      && (this[0x61] != (ModStation)0x0)))) {
    SpaceLounge::draw3DShip(*(SpaceLounge **)(this + 0x70));
  }
  AbyssEngine::PaintCanvas::SwapBuffer();
LAB_000ef2f6:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ModStation::OnRender3D  @0x000efac4  (212 bytes)
/* ModStation::OnRender3D() */

void __thiscall ModStation::OnRender3D(ModStation *this)

{
  ModStation MVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  bool bVar5;
  
  if (this[0x24] == (ModStation)0x0) {
    return;
  }
  AbyssEngine::PaintCanvas::ClearBuffer((uint)Globals::Canvas);
  if (*(CutScene **)(this + 0x14) == (CutScene *)0x0) {
    uVar2 = (uint)(byte)this[99];
LAB_000efb0c:
    if (uVar2 != 0) {
LAB_000efb12:
      StarMap::renderBG();
      goto LAB_000efb3a;
    }
  }
  else {
    if ((*(ushort *)(this + 0x62) & 0xff) != 0) {
      uVar2 = (uint)(*(ushort *)(this + 0x62) >> 8);
      goto LAB_000efb0c;
    }
    uVar3 = *(uint *)(this + 0x60);
    bVar5 = (uVar3 & 0xff) == 0;
    uVar2 = uVar3 >> 0x18;
    uVar4 = extraout_r3;
    if (bVar5) {
      uVar4 = (uint)(byte)this[100];
    }
    if (!bVar5 || uVar4 != 0) goto LAB_000efb0c;
    if (uVar2 != 0) goto LAB_000efb12;
    bVar5 = (uVar3 & 0xff00) == 0;
    MVar1 = (ModStation)0x0;
    if (bVar5) {
      MVar1 = this[0x5e];
    }
    if (bVar5 && MVar1 == (ModStation)0x0) {
      CutScene::renderBG(*(CutScene **)(this + 0x14));
      goto LAB_000efb3a;
    }
  }
  if (this[0x61] != (ModStation)0x0) {
    SpaceLounge::OnRenderBG(*(SpaceLounge **)(this + 0x70));
  }
LAB_000efb3a:
  AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
  if (this[0x61] == (ModStation)0x0) {
    if (this[99] == (ModStation)0x0) {
      if ((*(uint *)(this + 0x60) & 0xff) == 0) {
        if (((*(uint *)(this + 0x60) & 0xff0000) == 0) &&
           (*(CutScene **)(this + 0x14) != (CutScene *)0x0)) {
          CutScene::render3D(*(CutScene **)(this + 0x14));
        }
      }
      else {
        MissionsWindow::render3D(*(MissionsWindow **)(this + 0x7c));
      }
    }
    else {
      StarMap::render(*(StarMap **)(this + 0x10));
    }
  }
  else {
    SpaceLounge::OnRender3D(*(SpaceLounge **)(this + 0x70));
  }
  AbyssEngine::PaintCanvas::End3d(Globals::Canvas);
  return;
}

// ===== ModStation::setGameLoaded  @0x000efba4  (12 bytes)
/* ModStation::setGameLoaded() */

void __thiscall ModStation::setGameLoaded(ModStation *this)

{
  this[0xac] = (ModStation)0x1;
  this[0xaf] = (ModStation)0x1;
  return;
}

// ===== ModStation::addAchievement  @0x000efbb0  (120 bytes)
/* ModStation::addAchievement(int, int) */

void __thiscall ModStation::addAchievement(ModStation *this,int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = Achievements::isEliteMedal(Globals::achievements,param_1);
  if (iVar1 == 0) {
    if (param_2 - 1U < 2) {
      iVar1 = Achievements::getValue(Globals::achievements,param_1,3);
      if (iVar1 != -1) {
        g_android_current_achievements._0_4_ = param_1 * 3;
      }
      if ((param_2 == 1) &&
         (iVar1 = Achievements::getValue(Globals::achievements,param_1,2), iVar1 != -1)) {
        g_android_current_achievements._4_4_ = param_1 * 3 + 1;
      }
    }
    g_android_current_achievements._8_4_ = (param_1 * 3 + 3) - param_2;
  }
  return;
}

// ===== ModStation::showMapWindow  @0x000efc74  (14 bytes)
/* ModStation::showMapWindow() */

void __thiscall ModStation::showMapWindow(ModStation *this)

{
  this[0x60] = (ModStation)0x0;
  this[99] = (ModStation)0x1;
  return;
}

// ===== ModStation::showCBSMessage  @0x000efc84  (164 bytes)
/* ModStation::showCBSMessage() */

void __thiscall ModStation::showCBSMessage(ModStation *this)

{
  String *pSVar1;
  ChoiceWindow *this_00;
  String aSStack_3c [8];
  String aSStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_2c,"Code",false);
  AbyssEngine::String::String(aSStack_34,"In-App Purchase",false);
  this_00 = *(ChoiceWindow **)(this + 0x6c);
  pSVar1 = (String *)GameText::getText(Globals::gameText,0x186);
  AbyssEngine::String::String
            (aSStack_3c,
             "Zum Weiterspielen musst Du Galaxy on Fire 2 freischalten. Moechtest Du die Vollversion mit einen COMPUTERBILD SPIELE Freischalt-Code oder via In-App-Purchase freischalten?"
             ,false);
  ChoiceWindow::set(this_00,pSVar1,aSStack_3c,true,aSStack_2c,aSStack_34,aSStack_2c,-1,-1);
  AbyssEngine::String::~String(aSStack_3c);
  this[0x5f] = (ModStation)0x1;
  this[0xd9] = (ModStation)0x1;
  AbyssEngine::String::~String(aSStack_34);
  AbyssEngine::String::~String(aSStack_2c);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ModStation::showDlcMenu  @0x000efd64  (202 bytes)
/* ModStation::showDlcMenu() */

void __thiscall ModStation::showDlcMenu(ModStation *this)

{
  int iVar1;
  uint uVar2;
  MenuTouchWindow *this_00;
  uint uVar3;
  float local_3c;
  float local_34;
  
  iVar1 = __stack_chk_guard;
  this_00 = *(MenuTouchWindow **)(this + 0x4c);
  if (this_00 == (MenuTouchWindow *)0x0) {
    this_00 = operator_new(0x240);
    MenuTouchWindow::MenuTouchWindow(this_00,2);
    *(MenuTouchWindow **)(this + 0x4c) = this_00;
  }
  this[0x5e] = (ModStation)0x1;
  if (**(int **)(this_00 + 4) == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = 0;
    do {
      if ((int)uVar3 < 10) {
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_x + uVar3 * 4) = (int)local_34;
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_y + uVar3 * 4) = (int)local_3c;
        this_00 = *(MenuTouchWindow **)(this + 0x4c);
      }
      uVar3 = uVar3 + 1;
      uVar2 = **(uint **)(this_00 + 4);
    } while (uVar3 < uVar2);
  }
  Globals::sub_menu_button_count = uVar2;
  FUN_00261a24(0);
  MenuTouchWindow::callDlcMenu(this_00);
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ModStation::OnResume  @0x000efe50  (50 bytes)
/* ModStation::OnResume() */

void ModStation::OnResume(void)

{
  int iVar1;
  float extraout_s0;
  
  if ((Globals::sound != 0) && (iVar1 = FModSound::tryToStopMusicForBGMusic(), iVar1 == 0)) {
    FModSound::setVolume((FModSound *)Globals::sound,1,extraout_s0);
    return;
  }
  return;
}

// ===== ModStation::OnSuspend  @0x000efe90  (24 bytes)
/* ModStation::OnSuspend() */

void __thiscall ModStation::OnSuspend(ModStation *this)

{
  *(undefined4 *)(this + 0x124) = 0;
  if (Globals::recordHandler == 0) {
    return;
  }
  RecordHandler::saveOptions((RecordHandler *)Globals::recordHandler);
  return;
}

// ===== ModStation::OnKeyRelease  @0x000efeac  (2 bytes)
/* ModStation::OnKeyRelease(long long, long long) */

longlong ModStation::OnKeyRelease(longlong param_1,longlong param_2)

{
  return param_1;
}

// ===== ModStation::OnTouchBegin  @0x000efeae  (2 bytes)
/* ModStation::OnTouchBegin(int, int) */

int ModStation::OnTouchBegin(int param_1,int param_2)

{
  return param_1;
}

// ===== ModStation::OnTouchMove  @0x000efeb0  (2 bytes)
/* ModStation::OnTouchMove(int, int) */

int ModStation::OnTouchMove(int param_1,int param_2)

{
  return param_1;
}

// ===== ModStation::OnTouchEnd  @0x000efeb2  (2 bytes)
/* ModStation::OnTouchEnd(int, int) */

int ModStation::OnTouchEnd(int param_1,int param_2)

{
  return param_1;
}

// ===== ModStation::ShowLoadingScreen  @0x000efeb4  (4 bytes)
/* ModStation::ShowLoadingScreen() */

undefined4 ModStation::ShowLoadingScreen(void)

{
  return 1;
}

