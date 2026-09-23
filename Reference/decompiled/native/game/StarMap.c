// Class: StarMap
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== StarMap::StarMap  @0x000d6880  (1028 bytes)
/* StarMap::StarMap(bool, Mission*, bool, int) */

void __thiscall
StarMap::StarMap(StarMap *this,bool param_1,Mission *param_2,bool param_3,int param_4)

{
  int iVar1;
  short sVar2;
  void *pvVar3;
  undefined4 uVar4;
  AEGeometry *pAVar5;
  Array *pAVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  uint uVar12;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float fVar13;
  float extraout_s0_02;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float fVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float fVar17;
  undefined4 uVar18;
  float fVar19;
  float fVar20;
  
  iVar1 = __stack_chk_guard;
  uVar4 = 0;
  uVar15 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar16 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar18 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = uVar15;
  *(undefined4 *)(this + 0x80) = uVar16;
  *(undefined4 *)(this + 0x84) = uVar18;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  AbyssEngine::EaseInOut::EaseInOut((EaseInOut *)(this + 0xac));
  AbyssEngine::EaseInOut::EaseInOut((EaseInOut *)(this + 0xbc));
  AbyssEngine::EaseInOut::EaseInOut((EaseInOut *)(this + 0xcc));
  *(undefined4 *)(this + 0x188) = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 400) = 0;
  *(undefined4 *)(this + 0x154) = uVar4;
  *(undefined4 *)(this + 0x158) = uVar15;
  *(undefined4 *)(this + 0x15c) = uVar16;
  *(undefined4 *)(this + 0x160) = uVar18;
  *(undefined4 *)(this + 0x144) = uVar4;
  *(undefined4 *)(this + 0x148) = uVar15;
  *(undefined4 *)(this + 0x14c) = uVar16;
  *(undefined4 *)(this + 0x150) = uVar18;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x1c8) = *(undefined4 *)(Globals::layout + 0x88);
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x60) = 0xffffffff;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x194) = 0;
  *(undefined4 *)(this + 0x198) = 0;
  this[0x1e4] = (StarMap)0x0;
  this[1] = (StarMap)0x0;
  this[0x120] = (StarMap)0x0;
  *(undefined4 *)(this + 0x17c) = 0;
  *(undefined4 *)(this + 0x180) = 0;
  *(undefined4 *)(this + 0x184) = 0;
  *(undefined4 *)(this + 0x168) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  *(undefined4 *)(this + 0x171) = 0;
  *(undefined4 *)(this + 0x16d) = 0;
  pvVar3 = operator_new__(0x14);
  *(void **)(this + 0xfc) = pvVar3;
  uVar4 = Galaxy::getSystems(Globals::galaxy);
  *(undefined4 *)(this + 0x54) = uVar4;
  *(undefined4 *)(this + 0x10) = 500;
  *(undefined4 *)(this + 0x14) = 500;
  pAVar5 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar5,Globals::Canvas);
  *(AEGeometry **)(this + 0x6c) = pAVar5;
  pAVar6 = operator_new(0xc);
  puVar7 = operator_new__(4);
  *(undefined4 **)(pAVar6 + 4) = puVar7;
  *puVar7 = 0;
  *(undefined4 *)(pAVar6 + 8) = 1;
  *(undefined4 *)pAVar6 = 0;
  *(Array **)(this + 0x68) = pAVar6;
  puVar7 = operator_new(0xc);
  puVar8 = operator_new__(4);
  puVar7[1] = puVar8;
  puVar7[2] = 1;
  *puVar8 = 0;
  *puVar7 = 0;
  *(undefined4 **)(this + 0x194) = puVar7;
  ArraySetLength<AEGeometry*>(0x22,pAVar6);
  ArraySetLength<AbyssEngine::AEMath::Vector*>(0x22,*(Array **)(this + 0x194));
  if (**(int **)(this + 0x68) != 0) {
    fVar14 = 100.0;
    fVar17 = 14000.0;
    uVar12 = 0;
    do {
      sVar2 = SolarSystem::getTextureIndex
                        (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + uVar12 * 4));
      iVar9 = Status::getCurrentCampaignMission(Globals::status);
      uVar11 = sVar2 + 0x4696U;
      if (0x9d < iVar9) {
        uVar11 = 0x469b;
      }
      if (uVar12 != 0x1b) {
        uVar11 = sVar2 + 0x4696U;
      }
      pAVar5 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar5,uVar11,Globals::Canvas,false);
      *(AEGeometry **)(*(int *)(*(int *)(this + 0x68) + 4) + uVar12 * 4) = pAVar5;
      iVar9 = SolarSystem::getTextureIndex
                        (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + uVar12 * 4));
      fVar13 = extraout_s0;
      fVar19 = extraout_s1;
      fVar20 = extraout_s2;
      if ((iVar9 == 0xf) &&
         (iVar9 = Status::getCurrentCampaignMission(Globals::status), fVar13 = extraout_s0_00,
         fVar19 = extraout_s1_00, fVar20 = extraout_s2_00, iVar9 < 0x9e)) {
        Status::getCurrentCampaignMission(Globals::status);
        pAVar5 = *(AEGeometry **)(*(int *)(*(int *)(this + 0x68) + 4) + uVar12 * 4);
        fVar13 = extraout_s0_01;
        fVar19 = extraout_s1_01;
        fVar20 = extraout_s2_01;
      }
      else {
        pAVar5 = *(AEGeometry **)(*(int *)(*(int *)(this + 0x68) + 4) + uVar12 * 4);
      }
      AEGeometry::setScaling(pAVar5,fVar13,fVar19,fVar20);
      iVar9 = SolarSystem::getX(*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + uVar12 * 4))
      ;
      iVar10 = SolarSystem::getY(*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + uVar12 * 4)
                                );
      fVar19 = (float)VectorSignedToFloat(100 - iVar9,(byte)(in_fpscr >> 0x16) & 3);
      fVar20 = (float)VectorSignedToFloat(100 - iVar10,(byte)(in_fpscr >> 0x16) & 3);
      iVar9 = SolarSystem::getZ(*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + uVar12 * 4))
      ;
      fVar13 = (float)VectorSignedToFloat(100 - iVar9,(byte)(in_fpscr >> 0x16) & 3);
      fVar19 = (float)VectorSignedToFloat((int)((fVar19 / fVar14) * fVar17) + -10000,
                                          (byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat((int)((fVar20 / fVar14) * 13000.0) + -9000,(byte)(in_fpscr >> 0x16) & 3);
      fVar13 = (float)VectorSignedToFloat((int)((fVar13 / fVar14) * 6000.0) + 1000,
                                          (byte)(in_fpscr >> 0x16) & 3);
      AEGeometry::setPosition(fVar13,extraout_s1_02,fVar19);
      AEGeometry::addChild
                (*(AEGeometry **)(this + 0x6c),
                 *(uint *)(*(int *)(*(int *)(*(int *)(this + 0x68) + 4) + uVar12 * 4) + 0xc));
      puVar7 = operator_new(0xc);
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      *(undefined4 **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar12 * 4) = puVar7;
      uVar12 = uVar12 + 1;
    } while (uVar12 < **(uint **)(this + 0x68));
  }
  AbyssEngine::AERandom::reset(Globals::rnd);
  this[0xa9] = (StarMap)0x0;
  *(undefined4 *)(this + 0xf8) = 0;
  iVar9 = Status::getCurrentCampaignMission(Globals::status);
  if ((0x1f < iVar9) && (-1 < *(int *)(Globals::status + 0x7c))) {
    pAVar5 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar5,0x4262,Globals::Canvas,false);
    *(AEGeometry **)(this + 0xf8) = pAVar5;
    AEGeometry::getPosition();
    AEGeometry::setPosition((Vector *)pAVar5);
    uVar4 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xf8) + 0xc));
    AbyssEngine::Transform::SetAnimationState(uVar4,2,0);
    AEGeometry::setRotation
              (*(AEGeometry **)(this + 0xf8),extraout_s0_02,extraout_s1_03,extraout_s2_02);
  }
  init(this,param_1,param_2,param_3,param_4);
  if (__stack_chk_guard - iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - iVar1);
}

// ===== StarMap::init  @0x000d6d20  (2386 bytes)
/* StarMap::init(bool, Mission*, bool, int) */

void __thiscall StarMap::init(StarMap *this,bool param_1,Mission *param_2,bool param_3,int param_4)

{
  Galaxy *this_00;
  PaintCanvas *pPVar1;
  undefined4 uVar2;
  EaseInOut *pEVar3;
  int iVar4;
  SolarSystem *pSVar5;
  Station *this_01;
  uint uVar6;
  undefined4 *puVar7;
  FileRead *this_02;
  TouchButton *this_03;
  String *pSVar8;
  ChoiceWindow *this_04;
  SystemPathFinder *pSVar9;
  uint uVar10;
  uint *puVar11;
  int *piVar12;
  int iVar13;
  Status *this_05;
  int iVar14;
  Ship *this_06;
  Item *this_07;
  AEGeometry *pAVar15;
  undefined4 *puVar16;
  void *pvVar17;
  Array *pAVar18;
  bool bVar19;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float fVar20;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
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
  float extraout_s1_07;
  float extraout_s1_08;
  float extraout_s1_09;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar21;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  float extraout_s2_07;
  float extraout_s2_08;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_68 [5];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  int local_28;
  
  uVar10 = (uint)param_1;
  local_28 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,0,1);
  this[0xa8] = (StarMap)param_1;
  this[0x118] = (StarMap)param_3;
  *(int *)(this + 0x114) = param_4;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4a1,(uint *)(this + 0x124));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x49c,(uint *)(this + 0x128));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x49f,(uint *)(this + 300));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x49e,(uint *)(this + 0x130));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x452,(uint *)(this + 0x20));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4a2,(uint *)(this + 0x30));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x453,(uint *)(this + 0x2c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x455,(uint *)(this + 0x28));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x454,(uint *)(this + 0x24));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x48c,(uint *)(this + 0x40));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x48a,(uint *)(this + 0x44));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4fd,(uint *)(this + 0x48));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x545,(uint *)(this + 0x134));
  uVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x40));
  *(undefined4 *)(this + 0x1a8) = uVar2;
  uVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x28));
  *(undefined4 *)(this + 0x1ac) = uVar2;
  *(undefined4 *)(this + 0x1d0) = 0;
  this[0x1d4] = (StarMap)0x0;
  *(undefined4 *)(this + 0x1c4) = 0xffffffff;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  *(undefined4 *)(this + 0x19c) = 0xffffffff;
  *(undefined4 *)(this + 0x1a0) = 0xffffffff;
  *(undefined4 *)(this + 0x1dc) = 0xffffffff;
  *(undefined4 *)(this + 0x1e0) = 0xffffffff;
  *(undefined4 *)(this + 0xe8) = 0;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  this[1] = (StarMap)0x0;
  this[0x174] = (StarMap)0x0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  pEVar3 = operator_new(0x10);
  AbyssEngine::EaseInOut::EaseInOut(pEVar3);
  *(EaseInOut **)(this + 0x17c) = pEVar3;
  pEVar3 = operator_new(0x10);
  AbyssEngine::EaseInOut::EaseInOut(pEVar3);
  *(EaseInOut **)(this + 0x180) = pEVar3;
  pEVar3 = operator_new(0x10);
  AbyssEngine::EaseInOut::EaseInOut(pEVar3);
  *(EaseInOut **)(this + 0x184) = pEVar3;
  *(undefined4 *)(this + 0x1cc) = *(undefined4 *)(Globals::layout + 0x90);
  uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  *(undefined4 *)(this + 0x74) = uVar2;
  AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0x70));
  AbyssEngine::PaintCanvas::CameraSetPerspective
            ((uint)Globals::Canvas,extraout_s0,extraout_s1,extraout_s2);
  uStack_4c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_48 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar16 = (undefined4 *)((uint)local_68 | 4);
  local_68[0] = 0x3f800000;
  *puVar16 = 0;
  puVar16[1] = uStack_4c;
  puVar16[2] = uStack_48;
  puVar16[3] = uStack_44;
  local_54 = 0x3f800000;
  local_50 = 0;
  local_40 = 0x3f800000;
  uStack_38 = 0x3f8000003f800000;
  local_30 = 0x3f800000;
  AbyssEngine::AEMath::MatrixSetTranslation
            ((AEMath *)&local_a8,(Matrix *)local_68,extraout_s0_00,extraout_s1_00,extraout_s2_00);
  AbyssEngine::AEMath::MatrixSetRotation
            ((Matrix *)&local_a8,extraout_s0_01,extraout_s1_01,extraout_s2_01);
  fVar20 = (float)VectorSignedToFloat((int)*(float *)(this + 8) * 0x14,(byte)(in_fpscr >> 0x16) & 3)
  ;
  fVar21 = (float)VectorSignedToFloat((int)*(float *)(this + 0xc) * 0x14,
                                      (byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::MatrixSetTranslation
            ((AEMath *)&local_a8,(Matrix *)local_68,fVar20,extraout_s1_02,fVar21);
  AbyssEngine::PaintCanvas::CameraSetLocal
            (Globals::Canvas,*(uint *)(this + 0x70),(Matrix *)local_68);
  AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  uVar2 = 3;
  this[0xf4] = (StarMap)(0xf < iVar4);
  if (0xf < iVar4) {
    uVar2 = 0;
  }
  *(undefined4 *)(this + 4) = uVar2;
  pSVar5 = (SolarSystem *)Status::getSystem(Globals::status);
  uVar2 = SolarSystem::getIndex(pSVar5);
  *(undefined4 *)(this + 0x60) = uVar2;
  this_00 = Globals::galaxy;
  if (((param_3) || (uVar10 != 1)) || (this[0xf4] == (StarMap)0x0)) {
    AEGeometry::getPosition();
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_a8);
  }
  else {
    iVar4 = Mission::getTargetStation(param_2);
    this_01 = (Station *)Galaxy::getStation(this_00,iVar4);
    if ((this_01 == (Station *)0x0) || (iVar4 = Station::getSystem(this_01), iVar4 < 0)) {
      if (-1 < *(int *)(Globals::status + 0x7c)) {
        AEGeometry::getPosition();
        goto LAB_000d7454;
      }
    }
    else {
      Station::getSystem(this_01);
      AEGeometry::getPosition();
LAB_000d7454:
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_a8);
    }
    if ((this_01 != *(Station **)(Globals::status + 0x78)) && (this_01 != (Station *)0x0)) {
      pvVar17 = (void *)Station::~Station(this_01);
      operator_delete(pvVar17);
    }
  }
  pPVar1 = Globals::Canvas;
  uVar6 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  puVar16 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar6);
  local_a8 = *puVar16;
  uStack_a4 = puVar16[1];
  uStack_a0 = puVar16[2];
  uStack_9c = puVar16[3];
  uStack_98 = puVar16[4];
  local_94 = puVar16[5];
  uStack_90 = puVar16[6];
  uStack_8c = puVar16[7];
  uStack_88 = puVar16[8];
  uStack_84 = puVar16[9];
  local_80 = puVar16[10];
  uStack_7c = puVar16[0xb];
  uStack_78 = puVar16[0xc];
  uStack_74 = puVar16[0xd];
  uStack_70 = puVar16[0xe];
  AbyssEngine::AEMath::MatrixSetTranslation
            ((AEMath *)&local_e8,(AEMath *)&local_a8,extraout_s0_02,extraout_s1_03,extraout_s2_02);
  AbyssEngine::PaintCanvas::CameraSetLocal
            (Globals::Canvas,*(uint *)(this + 0x70),(AEMath *)&local_a8);
  *(float *)(this + 8) = *(float *)(this + 0x78) / 20.0;
  *(float *)(this + 0xc) = *(float *)(this + 0x7c) / 20.0;
  if (*(int *)(this + 4) == 3) {
    *(undefined4 *)(this + 100) = 0xffffffff;
    initStarSystem(this);
    AEGeometry::getPosition();
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_e8);
    *(float *)(this + 0x80) = *(float *)(this + 0x80) + -500.0;
    pPVar1 = Globals::Canvas;
    uVar6 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    puVar16 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar6);
    local_e8 = *puVar16;
    uStack_e4 = puVar16[1];
    uStack_e0 = puVar16[2];
    uStack_dc = puVar16[3];
    uStack_d8 = puVar16[4];
    local_d4 = puVar16[5];
    uStack_d0 = puVar16[6];
    uStack_cc = puVar16[7];
    uStack_c8 = puVar16[8];
    uStack_c4 = puVar16[9];
    local_c0 = puVar16[10];
    uStack_b8 = puVar16[0xc];
    uStack_b4 = puVar16[0xd];
    uStack_b0 = puVar16[0xe];
    local_bc = *(undefined4 *)(this + 0x80);
    AbyssEngine::PaintCanvas::CameraSetLocal
              (Globals::Canvas,*(uint *)(this + 0x70),(Vector *)&local_e8);
  }
  else {
    *(undefined4 *)(this + 0x19c) = *(undefined4 *)(this + 0x60);
    if (*(Array **)(this + 0x58) != (Array *)0x0) {
      ArrayReleaseClasses<Station*>(*(Array **)(this + 0x58));
      pvVar17 = *(void **)(this + 0x58);
      if (pvVar17 != (void *)0x0) {
        if (*(void **)((int)pvVar17 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar17 + 4));
        }
        operator_delete(pvVar17);
      }
      *(undefined4 *)(this + 0x58) = 0;
    }
    puVar16 = operator_new(0xc);
    puVar7 = operator_new__(4);
    puVar16[1] = puVar7;
    puVar16[2] = 1;
    *puVar7 = 0;
    *puVar16 = 0;
    *(undefined4 **)(this + 0x58) = puVar16;
    this_02 = operator_new(1);
    FileRead::FileRead(this_02);
    uVar2 = FileRead::loadStationsBinary
                      (this_02,*(SolarSystem **)
                                (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
    *(undefined4 *)(this + 0x58) = uVar2;
    pvVar17 = (void *)FileRead::~FileRead(this_02);
    operator_delete(pvVar17);
  }
  if (param_3) {
    *(undefined4 *)(this + 0x60) = 0xffffffff;
    *(undefined4 *)(this + 0x19c) = 0xffffffff;
  }
  this[0x108] = (StarMap)0x0;
  this[0xaa] = (StarMap)0x0;
  this[0xab] = (StarMap)0x0;
  *this = (StarMap)0x0;
  this_03 = operator_new(0xc0);
  pSVar8 = (String *)GameText::getText(Globals::gameText,400);
  TouchButton::TouchButton
            (this_03,pSVar8,0,Globals::w - *(int *)(Globals::layout + 0x2c),
             Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
  *(TouchButton **)(this + 0x4c) = this_03;
  this_04 = operator_new(0x54);
  ChoiceWindow::ChoiceWindow(this_04);
  *(ChoiceWindow **)(this + 0x5c) = this_04;
  *(undefined4 *)(this + 0xa0) = 0;
  pSVar9 = operator_new(1);
  SystemPathFinder::SystemPathFinder(pSVar9);
  *(SystemPathFinder **)(this + 0x50) = pSVar9;
  bVar19 = uVar10 != 1;
  if (!bVar19) {
    uVar10 = *(uint *)(this + 4);
  }
  if (bVar19 || uVar10 != 0) goto LAB_000d74d8;
  *(undefined4 *)(this + 0x60) = 0xffffffff;
  *(undefined4 *)(this + 0x104) = 0xffffffff;
  iVar4 = Mission::isEmpty(param_2);
  if ((iVar4 == 0) &&
     ((iVar4 = Mission::isVisible(param_2), iVar4 != 0 ||
      (iVar4 = Mission::getType(param_2), iVar4 == 0xe)))) {
    if (*(int *)(this + 4) != 3) {
      pSVar5 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar4 = SolarSystem::getRoutes(pSVar5);
      if (iVar4 == 0) goto LAB_000d7384;
    }
    puVar11 = *(uint **)(this + 0x54);
    if (*puVar11 != 0) {
      uVar10 = 0;
      do {
        iVar4 = SolarSystem::getStations(*(SolarSystem **)(puVar11[1] + uVar10 * 4));
        if ((iVar4 != 0) &&
           (piVar12 = (int *)SolarSystem::getStations
                                       (*(SolarSystem **)
                                         (*(int *)(*(int *)(this + 0x54) + 4) + uVar10 * 4)),
           *piVar12 != 0)) {
          uVar6 = 0;
          do {
            iVar4 = Mission::getTargetStation(param_2);
            iVar13 = SolarSystem::getStations
                               (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + uVar10 * 4))
            ;
            if (iVar4 == *(int *)(*(int *)(iVar13 + 4) + uVar6 * 4)) {
              *(uint *)(this + 0x104) = uVar10;
              if (*(int *)(this + 4) == 3) {
                *(uint *)(this + 100) = uVar6;
                *(uint *)(this + 0x1a0) = uVar6;
                this[0x13b] = (StarMap)0x1;
              }
              break;
            }
            puVar11 = (uint *)SolarSystem::getStations
                                        (*(SolarSystem **)
                                          (*(int *)(*(int *)(this + 0x54) + 4) + uVar10 * 4));
            uVar6 = uVar6 + 1;
          } while (uVar6 < *puVar11);
        }
        puVar11 = *(uint **)(this + 0x54);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar11);
    }
    iVar4 = *(int *)(this + 0x104);
    if (iVar4 == -1) {
      iVar4 = Mission::getTargetStation(param_2);
      this_05 = Globals::status;
      if ((iVar4 != -1) || (*(int *)(Globals::status + 0x7c) < 0)) {
        iVar4 = *(int *)(this + 0x104);
        goto LAB_000d7494;
      }
      *(int *)(this + 0x104) = *(int *)(Globals::status + 0x7c);
    }
    else {
LAB_000d7494:
      this_05 = Globals::status;
      if (iVar4 < 0) goto LAB_000d74be;
    }
    pSVar9 = *(SystemPathFinder **)(this + 0x50);
    pAVar18 = *(Array **)(this + 0x54);
    pSVar5 = (SolarSystem *)Status::getSystem(this_05);
    iVar4 = SolarSystem::getIndex(pSVar5);
    uVar2 = SystemPathFinder::getSystemPath(pSVar9,pAVar18,iVar4,*(int *)(this + 0x104));
    *(undefined4 *)(this + 0xa0) = uVar2;
  }
  else {
LAB_000d7384:
    iVar4 = Mission::isEmpty(param_2);
    if ((iVar4 == 0) &&
       ((iVar4 = Mission::isVisible(param_2), iVar4 != 0 ||
        (iVar4 = Mission::getType(param_2), iVar4 == 0xe)))) {
      pSVar5 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar4 = SolarSystem::getRoutes(pSVar5);
      if ((iVar4 == 0) && (puVar11 = *(uint **)(this + 0x54), *puVar11 != 0)) {
        uVar10 = 0;
        do {
          iVar4 = SolarSystem::getStations(*(SolarSystem **)(puVar11[1] + uVar10 * 4));
          if ((iVar4 != 0) &&
             (piVar12 = (int *)SolarSystem::getStations
                                         (*(SolarSystem **)
                                           (*(int *)(*(int *)(this + 0x54) + 4) + uVar10 * 4)),
             *piVar12 != 0)) {
            uVar6 = 0;
            do {
              iVar4 = Mission::getTargetStation(param_2);
              iVar13 = SolarSystem::getStations
                                 (*(SolarSystem **)
                                   (*(int *)(*(int *)(this + 0x54) + 4) + uVar10 * 4));
              if (iVar4 == *(int *)(*(int *)(iVar13 + 4) + uVar6 * 4)) {
                *(uint *)(this + 0x104) = uVar10;
                break;
              }
              uVar6 = uVar6 + 1;
              puVar11 = (uint *)SolarSystem::getStations
                                          (*(SolarSystem **)
                                            (*(int *)(*(int *)(this + 0x54) + 4) + uVar10 * 4));
            } while (uVar6 < *puVar11);
          }
          puVar11 = *(uint **)(this + 0x54);
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar11);
      }
    }
  }
LAB_000d74be:
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(this + 0x104);
  this[0x13a] = (StarMap)0x1;
  *(undefined4 *)(this + 0x168) = 0x3f666666;
LAB_000d74d8:
  iVar4 = 0;
  *(undefined4 *)(this + 0x10c) = 0;
  do {
    uVar10 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar8 = (String *)GameText::getText(Globals::gameText,(&DAT_0025446c)[iVar4]);
    iVar14 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar1,uVar10,pSVar8);
    iVar4 = iVar4 + 1;
    iVar13 = *(int *)(this + 0x10c);
    if (*(int *)(this + 0x10c) < iVar14) {
      *(int *)(this + 0x10c) = iVar14;
      iVar13 = iVar14;
    }
    iVar14 = Globals::layout;
  } while (iVar4 != 6);
  uVar2 = 0;
  *(int *)(this + 0x10c) = iVar13 + *(int *)(Globals::layout + 0x8c);
  *(int *)(this + 0x110) = *(int *)(iVar14 + 4) * 5 + *(int *)(iVar14 + 0x2c) * 2;
  *(undefined4 *)(this + 0x11c) = 0;
  this_06 = (Ship *)Status::getShip(Globals::status);
  this_07 = (Item *)Ship::getCargo(this_06,0x7a);
  if (this_07 != (Item *)0x0) {
    uVar2 = Item::getAmount(this_07);
  }
  *(undefined4 *)(this + 0x1d8) = uVar2;
  pAVar15 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar15,0x41d2,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x1b0) = pAVar15;
  AEGeometry::setRotation(pAVar15,extraout_s0_03,extraout_s1_04,extraout_s2_03);
  AEGeometry::setPosition(extraout_s0_04,extraout_s1_05,extraout_s2_04);
  pAVar15 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar15,0x41d3,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x1b4) = pAVar15;
  AEGeometry::setRotation(pAVar15,extraout_s0_05,extraout_s1_06,extraout_s2_05);
  AEGeometry::setPosition(extraout_s0_06,extraout_s1_07,extraout_s2_06);
  pAVar15 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar15,0x41d4,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x1b8) = pAVar15;
  AEGeometry::setRotation(pAVar15,extraout_s0_07,extraout_s1_08,extraout_s2_07);
  AEGeometry::setPosition(extraout_s0_08,extraout_s1_09,extraout_s2_08);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarMap::~StarMap  @0x000d7720  (240 bytes)
/* StarMap::~StarMap() */

StarMap * __thiscall StarMap::~StarMap(StarMap *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0x194) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(*(Array **)(this + 0x194));
    pvVar1 = *(void **)(this + 0x194);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x194) = 0;
  if (*(Array **)(this + 0x198) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(*(Array **)(this + 0x198));
    pvVar1 = *(void **)(this + 0x198);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x198) = 0;
  if (*(AEGeometry **)(this + 0x1bc) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x1bc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1bc) = 0;
  if (*(AEGeometry **)(this + 0x1b0) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x1b0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1b0) = 0;
  if (*(AEGeometry **)(this + 0x1b4) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x1b4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1b4) = 0;
  if (*(AEGeometry **)(this + 0x1b8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x1b8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1b8) = 0;
  if (*(void **)(this + 0x17c) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x17c));
  }
  *(undefined4 *)(this + 0x17c) = 0;
  if (*(void **)(this + 0x180) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x180));
  }
  *(undefined4 *)(this + 0x180) = 0;
  if (*(void **)(this + 0x184) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x184));
  }
  *(undefined4 *)(this + 0x184) = 0;
  if (*(AEGeometry **)(this + 0xf8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xf8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xf8) = 0;
  if (*(SystemPathFinder **)(this + 0x50) != (SystemPathFinder *)0x0) {
    pvVar1 = (void *)SystemPathFinder::~SystemPathFinder(*(SystemPathFinder **)(this + 0x50));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x50) = 0;
  return this;
}

// ===== StarMap::initStarSystem  @0x000d7810  (2162 bytes)
/* StarMap::initStarSystem() */

void __thiscall StarMap::initStarSystem(StarMap *this)

{
  Status *this_00;
  PaintCanvas *pPVar1;
  AERandom *pAVar2;
  short sVar3;
  uint *puVar4;
  Array *pAVar5;
  undefined4 *puVar6;
  FileRead *this_01;
  undefined4 uVar7;
  void *pvVar8;
  AEGeometry *pAVar9;
  undefined1 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  Matrix *pMVar14;
  Engine *pEVar15;
  ushort uVar16;
  uint uVar17;
  undefined4 extraout_r1;
  uint uVar18;
  uint uVar19;
  Vector *pVVar20;
  uint uVar21;
  int iVar22;
  uint in_fpscr;
  float fVar23;
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
  float fVar24;
  float extraout_s2_11;
  float extraout_s2_12;
  float extraout_s2_13;
  float extraout_s2_14;
  float extraout_s2_15;
  float extraout_s2_16;
  float fVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  uint local_f8 [3];
  AEMath aAStack_ec [12];
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 uStack_d0;
  undefined4 local_cc;
  uint local_98 [5];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  puVar4 = (uint *)SolarSystem::getStations
                             (*(SolarSystem **)
                               (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
  uVar21 = *puVar4;
  pAVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  *(undefined4 **)(pAVar5 + 4) = puVar6;
  *(undefined4 *)(pAVar5 + 8) = 1;
  *puVar6 = 0;
  *(undefined4 *)pAVar5 = 0;
  *(Array **)(this + 0x58) = pAVar5;
  ArraySetLength<Station*>(uVar21,pAVar5);
  this_01 = operator_new(1);
  FileRead::FileRead(this_01);
  uVar7 = FileRead::loadStationsBinary
                    (this_01,*(SolarSystem **)
                              (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
  *(undefined4 *)(this + 0x58) = uVar7;
  pvVar8 = (void *)FileRead::~FileRead(this_01);
  operator_delete(pvVar8);
  uVar19 = (uint)((ulonglong)uVar21 * 4);
  if ((int)((ulonglong)uVar21 * 4 >> 0x20) != 0) {
    uVar19 = 0xffffffff;
  }
  pvVar8 = operator_new__(uVar19);
  *(void **)(this + 0x98) = pvVar8;
  pvVar8 = operator_new__(uVar19);
  *(void **)(this + 0x9c) = pvVar8;
  *(undefined4 *)(this + 0x1c4) = 0xffffffff;
  pAVar2 = Globals::rnd;
  SolarSystem::getIndex
            (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
  AbyssEngine::AERandom::setSeed(CONCAT44(1000,pAVar2));
  pAVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  *(undefined4 **)(pAVar5 + 4) = puVar6;
  *(undefined4 *)(pAVar5 + 8) = 1;
  *puVar6 = 0;
  *(undefined4 *)pAVar5 = 0;
  *(Array **)(this + 0x90) = pAVar5;
  ArraySetLength<AEGeometry*>(uVar21 + 1,pAVar5);
  pAVar9 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar9,Globals::Canvas);
  *(AEGeometry **)(this + 0xa4) = pAVar9;
  pAVar5 = operator_new(0xc);
  puVar10 = operator_new__(1);
  *(undefined1 **)(pAVar5 + 4) = puVar10;
  *(undefined4 *)(pAVar5 + 8) = 1;
  *puVar10 = 0;
  *(undefined4 *)pAVar5 = 0;
  *(Array **)(this + 0x100) = pAVar5;
  ArraySetLength<bool>(**(uint **)(this + 0x90),pAVar5);
  uVar19 = **(uint **)(this + 0x100);
  if (uVar19 != 0) {
    uVar17 = (*(uint **)(this + 0x100))[1];
    uVar18 = 0;
    do {
      *(undefined1 *)(uVar17 + uVar18) = 0;
      uVar18 = uVar18 + 1;
    } while (uVar18 < uVar19);
  }
  puVar4 = *(uint **)(this + 0x90);
  if (*puVar4 != 0) {
    uVar7 = 0;
    uVar26 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar27 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uVar28 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar6 = (undefined4 *)((uint)local_98 | 4);
    uVar19 = 0;
    do {
      if (0 < (int)uVar19) {
        pAVar9 = operator_new(0xc0);
        iVar22 = uVar19 - 1;
        sVar3 = Station::getTextureIndex
                          (*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + iVar22 * 4));
        AEGeometry::AEGeometry(pAVar9,sVar3 + 0x4704,Globals::Canvas,false);
        *(AEGeometry **)(*(int *)(*(int *)(this + 0x90) + 4) + uVar19 * 4) = pAVar9;
        local_98[0] = 0x3f800000;
        *puVar6 = uVar7;
        puVar6[1] = uVar26;
        puVar6[2] = uVar27;
        puVar6[3] = uVar28;
        local_84 = 0x3f800000;
        local_70 = 0x3f800000;
        uStack_68 = 0x3f8000003f800000;
        local_60 = 0x3f800000;
        piVar11 = *(int **)(this + 0x100);
        local_80 = uVar7;
        uStack_7c = uVar26;
        uStack_78 = uVar27;
        uStack_74 = uVar28;
        do {
          iVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,*piVar11);
          piVar11 = *(int **)(this + 0x100);
        } while (*(char *)(piVar11[1] + iVar12) != '\0');
        *(undefined1 *)(piVar11[1] + iVar12) = 1;
        iVar13 = __aeabi_uidiv(0x10000,*piVar11);
        fVar23 = (float)VectorSignedToFloat(iVar12 * iVar13,(byte)(in_fpscr >> 0x16) & 3);
        *(int *)(*(int *)(this + 0x98) + iVar22 * 4) = iVar12 * iVar13;
        AbyssEngine::AEMath::MatrixSetRotation
                  ((Matrix *)&local_d4,fVar23 * 1.5258789e-05 * 6.2831855,extraout_s1,extraout_s2);
        if (uVar19 == 1) {
          iVar12 = 0x1900;
        }
        else {
          iVar12 = *(int *)(*(int *)(this + 0x9c) + uVar19 * 4 + -8);
        }
        iVar13 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x15e0);
        iVar12 = iVar13 + iVar12 + 0x640;
        local_cc = VectorSignedToFloat(iVar12,(byte)(in_fpscr >> 0x16) & 3);
        *(int *)(*(int *)(this + 0x9c) + iVar22 * 4) = iVar12;
        local_d4 = 0;
        uStack_d0 = 0;
        local_e0 = 0;
        uStack_dc = 0;
        local_d8 = 0;
        AbyssEngine::AEMath::MatrixTransformVector
                  (aAStack_ec,(Matrix *)local_98,(Vector *)&local_d4);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e0,(Vector *)aAStack_ec);
        AEGeometry::translate(*(Vector **)(*(int *)(*(int *)(this + 0x90) + 4) + uVar19 * 4));
        uVar17 = Station::getTextureIndex
                           (*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + iVar22 * 4));
        fVar23 = (float)VectorSignedToFloat(*(int *)(&DAT_00254484 + uVar17 * 4) << 4,
                                            (byte)(in_fpscr >> 0x16) & 3);
        AEGeometry::setScaling
                  (*(AEGeometry **)(*(int *)(*(int *)(this + 0x90) + 4) + uVar19 * 4),
                   fVar23 * 1.5258789e-05,extraout_s1_00,extraout_s2_00);
        AEGeometry::getPosition();
        AbyssEngine::AEMath::VectorNormalize((AEMath *)local_f8,(Vector *)aAStack_ec);
        AbyssEngine::AEMath::Vector::operator=((Vector *)aAStack_ec,(Vector *)local_f8);
        AEGeometry::addChild
                  (*(AEGeometry **)(this + 0xa4),
                   *(uint *)(*(int *)(*(int *)(*(int *)(this + 0x90) + 4) + uVar19 * 4) + 0xc));
        this_00 = Globals::status;
        if ((uVar17 < 0x16) && ((1 << (uVar17 & 0xff) & 0x210200U) != 0)) {
LAB_000d7bc6:
          local_f8[0] = 0xffffffff;
          AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,local_f8);
          AbyssEngine::PaintCanvas::TransformAddMesh(Globals::Canvas,local_f8[0],0x41d5,false);
          uVar17 = local_f8[0];
          pPVar1 = Globals::Canvas;
          pMVar14 = (Matrix *)
                    AEGeometry::getMatrix
                              (*(AEGeometry **)(*(int *)(*(int *)(this + 0x90) + 4) + uVar19 * 4));
          AbyssEngine::PaintCanvas::TransformSetLocal(pPVar1,uVar17,pMVar14);
          AEGeometry::addChild(*(AEGeometry **)(this + 0xa4),local_f8[0]);
        }
        else {
          iVar12 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + iVar22 * 4)
                                    );
          iVar12 = Status::orbitHasPlanetRing(this_00,iVar12);
          if (iVar12 == 1) goto LAB_000d7bc6;
        }
        if (((*(int *)(this + 0xf8) != 0) &&
            (*(int *)(this + 0x60) == *(int *)(Globals::status + 0x7c))) &&
           (iVar22 = Station::getIndex(*(Station **)
                                        (*(int *)(*(int *)(this + 0x58) + 4) + iVar22 * 4)),
           iVar22 == *(int *)(Globals::status + 0x80))) {
          *(uint *)(this + 0x1c4) = uVar19;
        }
        puVar4 = *(uint **)(this + 0x90);
      }
      iVar22 = *(int *)(puVar4[1] + uVar19 * 4);
      if (iVar22 != 0) {
        AEGeometry::addChild(*(AEGeometry **)(this + 0xa4),*(uint *)(iVar22 + 0xc));
        puVar4 = *(uint **)(this + 0x90);
      }
      uVar19 = uVar19 + 1;
    } while (uVar19 < *puVar4);
  }
  AEGeometry::setVisible(*(AEGeometry **)(puVar4[1] + 4),false);
  pAVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  *(undefined4 **)(pAVar5 + 4) = puVar6;
  *(undefined4 *)(pAVar5 + 8) = 1;
  *puVar6 = 0;
  *(undefined4 *)pAVar5 = 0;
  *(Array **)(this + 0x94) = pAVar5;
  ArraySetLength<AEGeometry*>(uVar21,pAVar5);
  if (**(int **)(this + 0x94) != 0) {
    uVar19 = 0;
    do {
      pAVar9 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar9,0x1a7b,Globals::Canvas,false);
      *(AEGeometry **)(*(int *)(*(int *)(this + 0x94) + 4) + uVar19 * 4) = pAVar9;
      AEGeometry::addChild
                (*(AEGeometry **)(this + 0xa4),
                 *(uint *)(*(int *)(*(int *)(*(int *)(this + 0x94) + 4) + uVar19 * 4) + 0xc));
      pAVar9 = *(AEGeometry **)(*(int *)(*(int *)(this + 0x94) + 4) + uVar19 * 4);
      fVar25 = (float)VectorSignedToFloat(*(undefined4 *)(*(int *)(this + 0x9c) + uVar19 * 4),
                                          (byte)(in_fpscr >> 0x16) & 3);
      uVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xc45);
      fVar23 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
      AEGeometry::setRotation(pAVar9,fVar23 / 1000.0,extraout_s1_01,extraout_s2_01);
      fVar23 = (float)VectorSignedToFloat((int)fVar25 << 1,(byte)(in_fpscr >> 0x16) & 3);
      AEGeometry::setScaling
                (*(AEGeometry **)(*(int *)(*(int *)(this + 0x94) + 4) + uVar19 * 4),
                 fVar23 * 1.5258789e-05,extraout_s1_02,extraout_s2_02);
      uVar19 = uVar19 + 1;
    } while (uVar19 < **(uint **)(this + 0x94));
  }
  pVVar20 = *(Vector **)(this + 0xa4);
  AEGeometry::getPosition();
  AEGeometry::setPosition(pVVar20);
  AEGeometry::setScaling(*(AEGeometry **)(this + 0xa4),extraout_s0,extraout_s1_03,extraout_s2_03);
  AEGeometry::setRotation
            (*(AEGeometry **)(this + 0xa4),extraout_s0_00,extraout_s1_04,extraout_s2_04);
  *(undefined4 *)(this + 0x188) = 0x45800000;
  *(undefined4 *)(this + 0x18c) = 0xc5800000;
  AEGeometry::setRotation
            (*(AEGeometry **)(this + 0xa4),extraout_s0_01,extraout_s1_05,extraout_s2_05);
  *(undefined4 *)(this + 100) = 0xffffffff;
  pPVar1 = Globals::Canvas;
  iVar22 = SolarSystem::getRace
                     (*(SolarSystem **)
                       (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
  AbyssEngine::PaintCanvas::Image2DCreate
            (pPVar1,*(ushort *)(&DAT_002544f4 + iVar22 * 4),(uint *)(this + 0x34));
  if (*(Array **)(this + 0x198) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(*(Array **)(this + 0x198));
    pvVar8 = *(void **)(this + 0x198);
    if (pvVar8 != (void *)0x0) {
      if (*(void **)((int)pvVar8 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar8 + 4));
      }
      operator_delete(pvVar8);
    }
  }
  *(undefined4 *)(this + 0x198) = 0;
  pAVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  *(undefined4 **)(pAVar5 + 4) = puVar6;
  *(undefined4 *)(pAVar5 + 8) = 1;
  *puVar6 = 0;
  *(undefined4 *)pAVar5 = 0;
  *(Array **)(this + 0x198) = pAVar5;
  ArraySetLength<AbyssEngine::AEMath::Vector*>(**(uint **)(this + 0x58),pAVar5);
  puVar4 = *(uint **)(this + 0x198);
  if (*puVar4 != 0) {
    uVar19 = 0;
    do {
      puVar6 = operator_new(0xc);
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      *(undefined4 **)(puVar4[1] + uVar19 * 4) = puVar6;
      uVar19 = uVar19 + 1;
      puVar4 = *(uint **)(this + 0x198);
    } while (uVar19 < *puVar4);
  }
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightDirection
            (pEVar15,extraout_s0_02,extraout_s1_06,extraout_s2_06,0);
  if (*(AEGeometry **)(this + 0x1bc) != (AEGeometry *)0x0) {
    pvVar8 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x1bc));
    operator_delete(pvVar8);
  }
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x178) = 0xffffffff;
  iVar22 = SolarSystem::getTextureIndex
                     (*(SolarSystem **)
                       (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
  uVar16 = *(ushort *)(&DAT_00254420 + iVar22 * 4);
  if (*(int *)(this + 0x60) == 0x1b) {
    uVar16 = 0x2734;
  }
  AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,uVar16,(uint *)(this + 0x178),false);
  pAVar9 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar9,0x1a70,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x1bc) = pAVar9;
  AEGeometry::getPosition();
  AEGeometry::setPosition((Vector *)pAVar9);
  AEGeometry::setRotation
            (*(AEGeometry **)(this + 0x1bc),extraout_s0_03,extraout_s1_07,extraout_s2_07);
  iVar22 = SolarSystem::getTextureIndex
                     (*(SolarSystem **)
                       (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
  if (iVar22 == 0xf) {
    iVar22 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar22 < 0x6a) {
      pAVar9 = *(AEGeometry **)(this + 0x1bc);
      fVar23 = extraout_s0_05;
      fVar25 = extraout_s1_09;
      fVar24 = extraout_s2_09;
    }
    else {
      Status::getCurrentCampaignMission(Globals::status);
      pAVar9 = *(AEGeometry **)(this + 0x1bc);
      fVar23 = extraout_s0_06;
      fVar25 = extraout_s1_10;
      fVar24 = extraout_s2_10;
    }
  }
  else {
    pAVar9 = *(AEGeometry **)(this + 0x1bc);
    fVar23 = extraout_s0_04;
    fVar25 = extraout_s1_08;
    fVar24 = extraout_s2_08;
  }
  AEGeometry::setScaling(pAVar9,fVar23,fVar25,fVar24);
  AEGeometry::setVisible
            (*(AEGeometry **)(*(int *)(*(int *)(this + 0x68) + 4) + *(int *)(this + 0x60) * 4),false
            );
  AEGeometry::getPosition();
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightPosition
            (pEVar15,extraout_s0_07,extraout_s1_11,extraout_s2_11,local_98[0]);
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorAmbient
            (pEVar15,extraout_s0_08,extraout_s1_12,extraout_s2_12,0x3e4ccccd);
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorDiffuse
            (pEVar15,extraout_s0_09,extraout_s1_13,extraout_s2_13,0x40000000);
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorAmbient
            (pEVar15,extraout_s0_10,extraout_s1_14,extraout_s2_14);
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorDiffuse
            (pEVar15,extraout_s0_11,extraout_s1_15,extraout_s2_15);
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorSpecular
            (pEVar15,extraout_s0_12,extraout_s1_16,extraout_s2_16);
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorShininess(pEVar15,extraout_s0_13);
  iVar22 = AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  *(undefined4 *)(iVar22 + 0x31c) = 1;
  pAVar2 = Globals::rnd;
  Status::getPlayingTime(Globals::status);
  AbyssEngine::AERandom::setSeed(CONCAT44(extraout_r1,pAVar2));
  if (__stack_chk_guard != local_5c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarMap::initLights  @0x000d8130  (54 bytes)
/* StarMap::initLights() */

void StarMap::initLights(void)

{
  Engine *this;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  
  this = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorAmbient(this,extraout_s0,extraout_s1,extraout_s2);
  AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,0,1);
  return;
}

// ===== StarMap::setStart  @0x000d816c  (62 bytes)
/* StarMap::setStart(int, int) */

void __thiscall StarMap::setStart(StarMap *this,int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  
  *(int *)(this + 0x1dc) = param_2;
  *(int *)(this + 0x1e0) = param_1;
  pvVar2 = *(void **)(this + 0xa0);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0xa0) = 0;
  uVar1 = SystemPathFinder::getSystemPath
                    (*(SystemPathFinder **)(this + 0x50),*(Array **)(this + 0x54),param_1,
                     *(int *)(this + 0x104));
  *(undefined4 *)(this + 0xa0) = uVar1;
  return;
}

// ===== StarMap::depart  @0x000d81ac  (526 bytes)
/* StarMap::depart(bool) */

void __thiscall StarMap::depart(StarMap *this,bool param_1)

{
  Status *this_00;
  int iVar1;
  SolarSystem *pSVar2;
  int iVar3;
  Ship *pSVar4;
  Station *pSVar5;
  void *pvVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  Station *this_01;
  StarMap *pSVar10;
  
  if (*(int *)(this + 100) < 0) {
    return;
  }
  if (this[0xaa] != (StarMap)0x0) {
    Status::departStation
              (Globals::status,
               *(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + *(int *)(this + 100) * 4));
    Level::programmedStation = (Station *)0x0;
    Level::setInitStreamOut();
    Status::jumpgateUsed(Globals::status);
    if ((param_1) && (this[0xab] != (StarMap)0x0)) {
      iVar1 = Station::getSystem(*(Station **)
                                  (*(int *)(*(int *)(this + 0x58) + 4) + *(int *)(this + 100) * 4));
      pSVar2 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::getIndex(pSVar2);
      Level::doInstantJump = iVar1 != iVar3;
      if ((bool)Level::doInstantJump) {
        Level::energyCellsForNextJump = *(undefined4 *)(this + 0x1d0);
      }
    }
    else {
      Level::doInstantJump = 0;
    }
    goto LAB_000d833e;
  }
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  this_00 = Globals::status;
  if (iVar1 == 3) goto LAB_000d833e;
  *(undefined4 *)(Globals::status + 0x5c) = 0xffffffff;
  *(undefined4 *)(this_00 + 0x60) = 0xffffffff;
  *(undefined4 *)(this_00 + 100) = 0xffffffff;
  *(undefined4 *)(this_00 + 0x68) = 0xffffffff;
  pSVar5 = (Station *)Status::getStation(this_00);
  Status::departStation(this_00,pSVar5);
  this_01 = *(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + *(int *)(this + 100) * 4);
  pSVar5 = (Station *)Status::getStation(Globals::status);
  iVar1 = Station::equals(this_01,pSVar5);
  if (iVar1 == 0) {
    Level::programmedStation =
         *(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + *(int *)(this + 100) * 4);
  }
  if (param_1) {
    pSVar4 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Ship::hasVolatileGoods(pSVar4);
    if (iVar1 != 0) goto LAB_000d8328;
    pSVar4 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Ship::hasJumpDriveIntegrated(pSVar4);
    if ((iVar1 == 0) && (this[0xab] == (StarMap)0x0)) goto LAB_000d8328;
    iVar1 = Station::getSystem(Level::programmedStation);
    pSVar2 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar3 = SolarSystem::getIndex(pSVar2);
    Level::doInstantJump = iVar1 != iVar3;
    if ((bool)Level::doInstantJump) {
      Level::energyCellsForNextJump = *(undefined4 *)(this + 0x1d0);
    }
  }
  else {
LAB_000d8328:
    Level::doInstantJump = false;
  }
  Achievements::resetNewMedals(Globals::achievements);
LAB_000d833e:
  pSVar10 = this + 0x58;
  puVar8 = *(uint **)pSVar10;
  if (*puVar8 != 0) {
    uVar9 = 0;
    do {
      if (uVar9 != *(uint *)(this + 100)) {
        uVar7 = puVar8[1];
        pSVar5 = *(Station **)(uVar7 + uVar9 * 4);
        if (pSVar5 != (Station *)0x0) {
          pvVar6 = (void *)Station::~Station(pSVar5);
          operator_delete(pvVar6);
          uVar7 = *(uint *)(*(int *)pSVar10 + 4);
        }
        *(undefined4 *)(uVar7 + uVar9 * 4) = 0;
        puVar8 = *(uint **)pSVar10;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *puVar8);
  }
  if (puVar8 != (uint *)0x0) {
    if ((void *)puVar8[1] != (void *)0x0) {
      operator_delete__((void *)puVar8[1]);
    }
    operator_delete(puVar8);
  }
  *(undefined4 *)pSVar10 = 0;
  FModSound::stop(Globals::sound,0x66);
  Globals::switch_to_target_setting = 1;
  AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
  return;
}

// ===== StarMap::isInPlanetMode  @0x000d840c  (12 bytes)
/* StarMap::isInPlanetMode() */

bool __thiscall StarMap::isInPlanetMode(StarMap *this)

{
  return *(int *)(this + 4) == 3;
}

// ===== StarMap::setJumpMapMode  @0x000d8418  (10 bytes)
/* StarMap::setJumpMapMode(bool, bool) */

void __thiscall StarMap::setJumpMapMode(StarMap *this,bool param_1,bool param_2)

{
  this[0xaa] = (StarMap)param_1;
  this[0xab] = (StarMap)param_2;
  return;
}

// ===== StarMap::renderBG  @0x000d8422  (2 bytes)
/* StarMap::renderBG() */

void StarMap::renderBG(void)

{
  return;
}

// ===== StarMap::render  @0x000d8424  (130 bytes)
/* StarMap::render() */

void __thiscall StarMap::render(StarMap *this)

{
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AEGeometry::render(*(AEGeometry **)(this + 0x1b0));
  AEGeometry::render(*(AEGeometry **)(this + 0x1b4));
  AEGeometry::render(*(AEGeometry **)(this + 0x1b8));
  AEGeometry::render(*(AEGeometry **)(this + 0x6c));
  AbyssEngine::PaintCanvas::End3d(Globals::Canvas);
  AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
  if (*(int *)(this + 0xa4) != 0) {
    AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 0x178),0xffffffff);
    AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,2);
    AEGeometry::render(*(AEGeometry **)(this + 0x1bc));
    AEGeometry::render(*(AEGeometry **)(this + 0xa4));
  }
  if (*(AEGeometry **)(this + 0xf8) == (AEGeometry *)0x0) {
    return;
  }
  AEGeometry::render(*(AEGeometry **)(this + 0xf8));
  return;
}

// ===== StarMap::drawKey  @0x000d84b0  (550 bytes)
/* StarMap::drawKey() */

void __thiscall StarMap::drawKey(StarMap *this)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  Layout *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  String *pSVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar4 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x30));
  iVar11 = Globals::w;
  iVar9 = Globals::h;
  pLVar3 = Globals::layout;
  iVar13 = *(int *)(this + 0x10c);
  iVar12 = *(int *)(this + 0x110);
  iVar5 = *(int *)(Globals::layout + 4);
  iVar10 = *(int *)(Globals::layout + 8);
  iVar6 = *(int *)(Globals::layout + 0x10);
  iVar14 = *(int *)(Globals::layout + 0x2c);
  uVar7 = AbyssEngine::String::String(aSStack_30,"",false);
  iVar11 = iVar11 - iVar13;
  Layout::drawBox(pLVar3,7,iVar11,((iVar9 - iVar6) - iVar12) - iVar10,iVar13,iVar10 + iVar12,uVar7);
  iVar11 = iVar11 + iVar14;
  iVar4 = iVar4 + iVar14 + iVar11;
  iVar5 = ((iVar9 - iVar14) - iVar6) - iVar5;
  AbyssEngine::String::~String(aSStack_30);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x20),iVar11,iVar5);
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  pSVar8 = (String *)GameText::getText(Globals::gameText,0x112);
  AbyssEngine::PaintCanvas::DrawString(pPVar1,uVar2,pSVar8,iVar4,iVar5,false);
  iVar5 = iVar5 - *(int *)(Globals::layout + 4);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x30),iVar11,iVar5);
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  pSVar8 = (String *)GameText::getText(Globals::gameText,0x191);
  AbyssEngine::PaintCanvas::DrawString(pPVar1,uVar2,pSVar8,iVar4,iVar5,false);
  iVar5 = iVar5 - *(int *)(Globals::layout + 4);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x2c),iVar11,iVar5);
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  pSVar8 = (String *)GameText::getText(Globals::gameText,0x223);
  AbyssEngine::PaintCanvas::DrawString(pPVar1,uVar2,pSVar8,iVar4,iVar5,false);
  iVar5 = iVar5 - *(int *)(Globals::layout + 4);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x28),iVar11,iVar5);
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  pSVar8 = (String *)GameText::getText(Globals::gameText,0x22c);
  AbyssEngine::PaintCanvas::DrawString(pPVar1,uVar2,pSVar8,iVar4,iVar5,false);
  iVar9 = *(int *)(Globals::layout + 4);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x24),iVar11,iVar5 - iVar9)
  ;
  uVar2 = Globals::font;
  pPVar1 = Globals::Canvas;
  pSVar8 = (String *)GameText::getText(Globals::gameText,0x22b);
  AbyssEngine::PaintCanvas::DrawString(pPVar1,uVar2,pSVar8,iVar4,iVar5 - iVar9,false);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarMap::drawOnScreenInfo  @0x000d8710  (3720 bytes)
/* StarMap::drawOnScreenInfo(int, bool) */

void __thiscall StarMap::drawOnScreenInfo(StarMap *this,int param_1,bool param_2)

{
  byte bVar1;
  Status *pSVar2;
  PaintCanvas *pPVar3;
  GameText *this_00;
  int iVar4;
  undefined8 *puVar5;
  Mission *this_01;
  Mission *this_02;
  Mission *pMVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  Agent *pAVar10;
  Ship *this_03;
  Station *this_04;
  int iVar11;
  String *pSVar12;
  undefined4 uVar13;
  SolarSystem *pSVar14;
  StarMap *pSVar15;
  uchar uVar16;
  uchar uVar17;
  int iVar18;
  bool bVar19;
  bool bVar20;
  uint in_fpscr;
  uint uVar21;
  int iVar22;
  float extraout_s0;
  float fVar23;
  float fVar24;
  undefined8 uVar25;
  undefined4 local_68 [2];
  String aSStack_60 [8];
  String aSStack_58 [8];
  AbyssEngine aAStack_50 [8];
  undefined8 local_48;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (param_2) {
    iVar4 = *(int *)(this + 0x198);
  }
  else {
    iVar4 = *(int *)(this + 0x194);
  }
  puVar5 = *(undefined8 **)(*(int *)(iVar4 + 4) + param_1 * 4);
  local_48 = *puVar5;
  local_40 = *(undefined4 *)(puVar5 + 1);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_48);
  fVar23 = *(float *)(this + 0x78);
  in_fpscr = in_fpscr & 0xfffffff;
  if (((fVar23 < -50.0) ||
      (fVar24 = (float)VectorSignedToFloat(Globals::w + 0x32,(byte)(in_fpscr >> 0x16) & 3),
      fVar24 < fVar23)) || (fVar23 = *(float *)(this + 0x7c), fVar23 < -50.0)) goto LAB_000d957e;
  fVar24 = (float)VectorSignedToFloat(Globals::h + 0x32,(byte)(in_fpscr >> 0x16) & 3);
  uVar7 = in_fpscr | (uint)(fVar23 < fVar24) << 0x1f | (uint)(fVar23 == fVar24) << 0x1e;
  uVar21 = uVar7 | (uint)(NAN(fVar23) || NAN(fVar24)) << 0x1c;
  bVar1 = (byte)(uVar7 >> 0x18);
  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar21 >> 0x1c) & 1)) goto LAB_000d957e;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  __aeabi_memset4(*(undefined4 *)(this + 0xfc),0x14,0xff);
  if (param_2) {
    iVar4 = Station::isDiscovered(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
    if (iVar4 != 0) {
LAB_000d8808:
      **(undefined4 **)(this + 0xfc) = *(undefined4 *)(this + 0x30);
    }
  }
  else {
    iVar4 = SolarSystem::isFullyDiscovered
                      (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
    if (iVar4 == 1) goto LAB_000d8808;
  }
  this_01 = (Mission *)Status::getCampaignMission(Globals::status);
  this_02 = (Mission *)Status::getFreelanceMission(Globals::status);
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x34) {
    if (param_2) {
      iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
      if (iVar4 == 0x4a) {
LAB_000d8862:
        *(undefined4 *)(*(int *)(this + 0xfc) + 4) = *(undefined4 *)(this + 0x24);
      }
    }
    else {
      iVar4 = SolarSystem::getStationEnumIndex
                        (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4),0x4a);
      if (-1 < iVar4) goto LAB_000d8862;
    }
  }
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (((iVar4 == 0x74 && param_2) &&
      (iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4)),
      0x59 < iVar4)) &&
     (iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4)),
     iVar4 < 0x5f)) {
    pMVar6 = (Mission *)Status::getCampaignMission(Globals::status);
    uVar7 = Mission::getStatusValue(pMVar6);
    iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
    if ((1 << (iVar4 - 0x5aU & 0xff) & uVar7) != 0) goto LAB_000d88da;
    goto LAB_000d8a02;
  }
LAB_000d88da:
  iVar4 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar4 == 0x78) {
    if (param_2) {
      iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
      if (iVar4 != 0x5d) goto LAB_000d891a;
    }
    else {
      iVar4 = SolarSystem::getStationEnumIndex
                        (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4),0x5d);
      if (iVar4 < 0) goto LAB_000d891a;
    }
LAB_000d8a02:
    *(undefined4 *)(*(int *)(this + 0xfc) + 4) = *(undefined4 *)(this + 0x24);
  }
  else {
LAB_000d891a:
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    pSVar2 = Globals::status;
    if (iVar4 == 0x7d && param_2) {
      iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
      iVar4 = Status::isFreighterMissionStation(pSVar2,iVar4);
      if (iVar4 == 1) {
        pMVar6 = (Mission *)Status::getCampaignMission(Globals::status);
        uVar7 = Mission::getStatusValue(pMVar6);
        pSVar2 = Globals::status;
        iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
        uVar9 = Status::getFreighterMissionStationBit(pSVar2,iVar4);
        if ((1 << (uVar9 & 0xff) & uVar7) == 0) goto LAB_000d8a02;
      }
    }
    iVar4 = Status::getCurrentCampaignMission(Globals::status);
    pSVar2 = Globals::status;
    if (iVar4 == 0x7d && !param_2) {
      iVar4 = SolarSystem::getWarpGateIndex
                        (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
      iVar4 = Status::isFreighterMissionStation(pSVar2,iVar4);
      if (iVar4 == 1) {
        pMVar6 = (Mission *)Status::getCampaignMission(Globals::status);
        uVar7 = Mission::getStatusValue(pMVar6);
        pSVar2 = Globals::status;
        iVar4 = SolarSystem::getWarpGateIndex
                          (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
        uVar9 = Status::getFreighterMissionStationBit(pSVar2,iVar4);
        if ((1 << (uVar9 & 0xff) & uVar7) == 0) goto LAB_000d8a02;
      }
    }
  }
  if (this_01 != (Mission *)0x0) {
    iVar4 = Mission::getType(this_01);
    if (((iVar4 == 0xa3) && (puVar8 = *(uint **)(Globals::status + 0x90), puVar8 != (uint *)0x0)) &&
       (*puVar8 != 0)) {
      uVar7 = 0;
      do {
        if (param_2) {
          iVar18 = *(int *)(puVar8[1] + uVar7 * 4);
          iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4)
                                   );
          if (iVar18 == iVar4) {
LAB_000d8b42:
            bVar20 = true;
            goto LAB_000d8a92;
          }
        }
        else {
          uVar9 = SolarSystem::getStationEnumIndex
                            (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4),
                             *(int *)(puVar8[1] + uVar7 * 4));
          if (uVar9 < 0x80000000) goto LAB_000d8b42;
        }
        uVar7 = uVar7 + 1;
        puVar8 = *(uint **)(Globals::status + 0x90);
      } while (uVar7 < *puVar8);
    }
    bVar20 = false;
LAB_000d8a92:
    iVar4 = Mission::isEmpty(this_01);
    if (((((iVar4 == 0) &&
          (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 != 0x34)) &&
         (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 != 0x78)) &&
        ((iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 != 0x80 &&
         (iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 != 0x82)))) &&
       ((iVar4 = Status::getCurrentCampaignMission(Globals::status), iVar4 < 0x94 ||
        (iVar4 = Status::getCurrentCampaignMission(Globals::status), 0x97 < iVar4)))) {
      iVar4 = Status::getCurrentCampaignMission(Globals::status);
      if (iVar4 == 0x3b) {
        if (param_2) {
          iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4)
                                   );
          if (iVar4 != 0x65) goto LAB_000d8b50;
        }
        else {
          iVar4 = SolarSystem::getIndex
                            (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
          if (iVar4 != 0x17) goto LAB_000d8b86;
        }
      }
      else {
        if (param_2) {
LAB_000d8b50:
          iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4)
                                   );
          iVar18 = Mission::getTargetStation(this_01);
          bVar19 = iVar4 == iVar18;
        }
        else {
LAB_000d8b86:
          pSVar14 = *(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4);
          iVar4 = Mission::getTargetStation(this_01);
          iVar4 = SolarSystem::getStationEnumIndex(pSVar14,iVar4);
          bVar19 = false;
          if (-1 < iVar4) {
            bVar19 = true;
          }
        }
        if (bVar20 || bVar19) {
LAB_000d8c12:
          *(undefined4 *)(*(int *)(this + 0xfc) + 4) = *(undefined4 *)(this + 0x24);
        }
        else {
          iVar4 = Status::getCurrentCampaignMission(Globals::status);
          if (0x20 < iVar4) {
            if (param_2) {
              iVar4 = Station::getIndex(*(Station **)
                                         (*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
              if (iVar4 == *(int *)(Globals::status + 0x80)) {
LAB_000d8c06:
                iVar4 = Mission::getTargetStation(this_01);
                if (iVar4 == -1) goto LAB_000d8c12;
              }
            }
            else {
              iVar4 = SolarSystem::getStationEnumIndex
                                (*(SolarSystem **)
                                  (*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4),
                                 *(int *)(Globals::status + 0x80));
              if (-1 < iVar4) goto LAB_000d8c06;
            }
          }
        }
      }
    }
  }
  if ((this_02 == (Mission *)0x0) || (iVar4 = Mission::isEmpty(this_02), iVar4 != 0)) {
LAB_000d8cb8:
    if (param_2) {
LAB_000d8cbe:
      if (-1 < *(int *)(this + 0x60)) {
        iVar4 = SolarSystem::getWarpGateIndex
                          (*(SolarSystem **)
                            (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
        uVar25 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4))
        ;
        bVar20 = iVar4 == (int)uVar25;
        if (bVar20) {
          uVar25 = CONCAT44(*(undefined4 *)(this + 0xfc),*(undefined4 *)(this + 0x2c));
        }
        if (bVar20) {
          *(int *)((int)((ulonglong)uVar25 >> 0x20) + 0xc) = (int)uVar25;
        }
      }
    }
  }
  else {
    if (param_2) {
      iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
      iVar18 = Mission::getType(this_02);
      if (iVar18 == 0xe) {
        pAVar10 = (Agent *)Mission::getAgent(this_02);
        iVar18 = Agent::getStation(pAVar10);
      }
      else {
        iVar18 = Mission::getTargetStation(this_02);
      }
      if (iVar4 == iVar18) goto LAB_000d8cae;
      goto LAB_000d8cbe;
    }
    pSVar14 = *(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4);
    iVar4 = Mission::getType(this_02);
    if (iVar4 == 0xe) {
      this_03 = (Ship *)Status::getShip(Globals::status);
      iVar4 = Ship::hasCargo(this_03,0x73,1);
      if (iVar4 != 1) goto LAB_000d8c90;
      pAVar10 = (Agent *)Mission::getAgent(this_02);
      iVar4 = Agent::getStation(pAVar10);
    }
    else {
LAB_000d8c90:
      iVar4 = Mission::getTargetStation(this_02);
    }
    iVar4 = SolarSystem::getStationEnumIndex(pSVar14,iVar4);
    if (-1 < iVar4) {
LAB_000d8cae:
      *(undefined4 *)(*(int *)(this + 0xfc) + 8) = *(undefined4 *)(this + 0x28);
      goto LAB_000d8cb8;
    }
  }
  puVar8 = (uint *)Status::getPendingProducts(Globals::status);
  if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
    uVar7 = 0;
    do {
      iVar4 = *(int *)(puVar8[1] + uVar7 * 4);
      if (iVar4 != 0) {
        if (param_2) {
          iVar18 = *(int *)(iVar4 + 8);
          iVar4 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4)
                                   );
          if (iVar18 == iVar4) {
LAB_000d8d4c:
            *(undefined4 *)(*(int *)(this + 0xfc) + 0x10) = *(undefined4 *)(this + 0x20);
            break;
          }
        }
        else {
          iVar4 = SolarSystem::getStationEnumIndex
                            (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4),
                             *(int *)(iVar4 + 8));
          if (-1 < iVar4) goto LAB_000d8d4c;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *puVar8);
  }
  uVar7 = Globals::font;
  pPVar3 = Globals::Canvas;
  fVar23 = (float)VectorSignedToFloat(*(int *)(this + 0x1a8) >> 1,(byte)(uVar21 >> 0x16) & 3);
  fVar24 = *(float *)(this + 0x78);
  iVar4 = (int)(*(float *)(this + 0x7c) + fVar23 + -3.0);
  if (param_2) {
    Station::getName();
    iVar18 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar3,uVar7,(String *)&local_48);
    AbyssEngine::String::~String((String *)&local_48);
    fVar23 = (float)VectorSignedToFloat(iVar18 / 2,(byte)(uVar21 >> 0x16) & 3);
    this_04 = (Station *)Status::getStation(Globals::status);
    iVar18 = Station::getIndex(this_04);
    iVar22 = (int)(fVar24 - fVar23);
    iVar11 = Station::getIndex(*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
    pPVar3 = Globals::Canvas;
    if (iVar18 == iVar11) {
      iVar18 = *(int *)(this + 0x1a4);
      Layout::getPulseValue(Globals::layout,extraout_s0);
      VectorSignedToFloat(0xff - iVar18,(byte)(uVar21 >> 0x16) & 3);
      AbyssEngine::PaintCanvas::SetColor((uchar)pPVar3,0xff,0xff,0xff);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x48),(int)*(float *)(this + 0x78),
                 (int)*(float *)(this + 0x7c),'\x11','D');
    }
    if (*(int *)(this + 100) == param_1) {
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0x80,'\0');
      uVar7 = Globals::font;
      pPVar3 = Globals::Canvas;
      Station::getName();
      AbyssEngine::PaintCanvas::DrawString(pPVar3,uVar7,(String *)&local_48,iVar22,iVar4,false);
      AbyssEngine::String::~String((String *)&local_48);
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
      iVar18 = Station::getTecLevel
                         (*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
      uVar7 = Globals::font;
      pPVar3 = Globals::Canvas;
      if (0 < iVar18) {
        pSVar12 = (String *)GameText::getText(Globals::gameText,0x85);
        AbyssEngine::String::String(aSStack_58,": ",false);
        AbyssEngine::operator+(aAStack_50,pSVar12,aSStack_58);
        uVar13 = Station::getTecLevel
                           (*(Station **)(*(int *)(*(int *)(this + 0x58) + 4) + param_1 * 4));
        local_68[0] = 0;
        AbyssEngine::String::Set(CONCAT44(uVar13,local_68));
        AbyssEngine::String::String(aSStack_60,(String *)local_68,false);
        AbyssEngine::operator+((AbyssEngine *)&local_48,aAStack_50,aSStack_60);
        AbyssEngine::PaintCanvas::DrawString
                  (pPVar3,uVar7,(String *)&local_48,iVar22,*(int *)(Globals::layout + 4) + iVar4,
                   false);
        AbyssEngine::String::~String((String *)&local_48);
        AbyssEngine::String::~String(aSStack_60);
        AbyssEngine::String::~String((String *)local_68);
        AbyssEngine::String::~String((String *)aAStack_50);
        AbyssEngine::String::~String(aSStack_58);
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x40),(int)*(float *)(this + 0x78),
                 (int)*(float *)(this + 0x7c),'\x11','D');
    }
    else {
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x44),(int)*(float *)(this + 0x78),
                 (int)*(float *)(this + 0x7c),'\x11','D');
      if (-1 < *(int *)(this + 100)) {
        AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
      }
      uVar7 = Globals::font;
      pPVar3 = Globals::Canvas;
      Station::getName();
      AbyssEngine::PaintCanvas::DrawString(pPVar3,uVar7,(String *)&local_48,iVar22,iVar4,false);
      AbyssEngine::String::~String((String *)&local_48);
    }
  }
  else {
    SolarSystem::getName();
    iVar18 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar3,uVar7,(String *)&local_48);
    AbyssEngine::String::~String((String *)&local_48);
    fVar23 = (float)VectorSignedToFloat(iVar18 / 2,(byte)(uVar21 >> 0x16) & 3);
    iVar18 = (int)(fVar24 - fVar23);
    if (this[0xa8] != (StarMap)0x0) {
      SolarSystem::getIndex(*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
    }
    pSVar14 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar11 = SolarSystem::getIndex(pSVar14);
    iVar22 = SolarSystem::getIndex
                       (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
    pPVar3 = Globals::Canvas;
    if (iVar11 == iVar22) {
      VectorSignedToFloat(*(float *)(this + 0x1a4),(byte)(uVar21 >> 0x16) & 3);
      Layout::getPulseValue(Globals::layout,*(float *)(this + 0x1a4));
      AbyssEngine::PaintCanvas::SetColor((uchar)pPVar3,0xff,0xff,0xff);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x48),(int)*(float *)(this + 0x78),
                 (int)*(float *)(this + 0x7c),'\x11','D');
    }
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    if (*(int *)(this + 0x60) == param_1) {
      uVar16 = 0x80;
      uVar17 = '\0';
LAB_000d91fc:
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,uVar16,uVar17);
    }
    else if (-1 < *(int *)(this + 0x60)) {
      uVar16 = 0xff;
      uVar17 = 0xff;
      goto LAB_000d91fc;
    }
    uVar7 = Globals::font;
    pPVar3 = Globals::Canvas;
    SolarSystem::getName();
    AbyssEngine::PaintCanvas::DrawString(pPVar3,uVar7,(String *)&local_48,iVar18,iVar4,false);
    AbyssEngine::String::~String((String *)&local_48);
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    iVar11 = SolarSystem::hasNoOwner
                       (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
    if (iVar11 == 0) {
      iVar11 = SolarSystem::getRace
                         (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
      if (iVar11 == 2) {
        pSVar15 = this + 300;
      }
      else if (iVar11 == 1) {
        pSVar15 = this + 0x128;
      }
      else if (iVar11 == 0) {
        pSVar15 = this + 0x124;
      }
      else {
        pSVar15 = this + 0x130;
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)pSVar15,iVar18,iVar4 + -3,'\x11','\x12');
    }
    if ((param_1 == 0x1a) && (*(int *)(Globals::status + 0x114) == 3)) {
      fVar23 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x2c),
                                          (byte)(uVar21 >> 0x16) & 3);
      fVar24 = (float)VectorSignedToFloat(iVar4,(byte)(uVar21 >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x134),iVar18,(int)(fVar24 + fVar23 * 0.5),'\x11',
                 '\x12');
    }
    iVar11 = *(int *)(this + 0x60);
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    if (iVar11 == param_1) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x40),(int)*(float *)(this + 0x78),
                 (int)*(float *)(this + 0x7c),'\x11','D');
      iVar22 = *(int *)(Globals::layout + 4);
      iVar11 = SolarSystem::hasNoOwner
                         (*(SolarSystem **)(*(int *)(*(int *)(this + 0x54) + 4) + param_1 * 4));
      uVar7 = Globals::font;
      this_00 = Globals::gameText;
      pPVar3 = Globals::Canvas;
      if (iVar11 == 0) {
        iVar11 = SolarSystem::getRace
                           (*(SolarSystem **)
                             (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
        pSVar12 = (String *)GameText::getText(this_00,iVar11 + 0x196);
        AbyssEngine::PaintCanvas::DrawString
                  (pPVar3,uVar7,pSVar12,iVar18,*(int *)(Globals::layout + 4) + iVar4,false);
        iVar22 = *(int *)(Globals::layout + 4) << 1;
      }
      iVar11 = SolarSystem::getSecurityLevel
                         (*(SolarSystem **)
                           (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
      if ((param_1 == 0x1a) && (1 < *(int *)(Globals::status + 0x114))) {
        iVar11 = 3;
      }
      AbyssEngine::PaintCanvas::SetColor
                ((uchar)Globals::Canvas,(&DAT_0025451c)[iVar11 * 0xc],(&DAT_00254520)[iVar11 * 0xc],
                 (&DAT_00254524)[iVar11 * 0xc]);
      uVar7 = Globals::font;
      pPVar3 = Globals::Canvas;
      pSVar12 = (String *)GameText::getText(Globals::gameText,iVar11 + 0x192);
      AbyssEngine::PaintCanvas::DrawString(pPVar3,uVar7,pSVar12,iVar18,iVar4 + iVar22,false);
      uVar16 = (uchar)Globals::Canvas;
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x44),(int)*(float *)(this + 0x78),
                 (int)*(float *)(this + 0x7c),'\x11','D');
      if (*(int *)(this + 0x60) < 0) goto LAB_000d94d6;
      uVar16 = (uchar)Globals::Canvas;
    }
    AbyssEngine::PaintCanvas::SetColor(uVar16,0xff,0xff,0xff);
  }
LAB_000d94d6:
  iVar18 = 0;
  fVar23 = (float)VectorSignedToFloat(*(int *)(this + 0x1a8) >> 1,(byte)(uVar21 >> 0x16) & 3);
  iVar4 = (int)((*(float *)(this + 0x7c) - fVar23) + 10.0);
  iVar11 = (int)(*(float *)(this + 0x78) + fVar23 + -7.0);
  do {
    uVar7 = *(uint *)(*(int *)(this + 0xfc) + iVar18 * 4);
    while (uVar7 != 0xffffffff) {
      if (iVar18 != 0) {
        AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar7,iVar11,iVar4);
        iVar4 = iVar4 + *(int *)(this + 0x1ac);
        break;
      }
      iVar18 = -0x23;
      if (Globals::iPadHD != '\0') {
        iVar18 = -0x18;
      }
      iVar22 = 0x12;
      if (Globals::iPadHD != '\0') {
        iVar22 = 0xc;
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,uVar7,iVar11 - iVar22,iVar18 + *(int *)(this + 0x1a8) + iVar4);
      iVar18 = 1;
      uVar7 = *(uint *)(*(int *)(this + 0xfc) + 4);
    }
    iVar18 = iVar18 + 1;
  } while (iVar18 != 5);
LAB_000d957e:
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarMap::draw  @0x000d970c  (2704 bytes)
/* StarMap::draw() */

void __thiscall StarMap::draw(StarMap *this)

{
  PaintCanvas *pPVar1;
  GameText *this_00;
  StarMap SVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  SolarSystem *pSVar10;
  float fVar11;
  String *pSVar12;
  Ship *this_01;
  Layout *pLVar13;
  undefined4 uVar14;
  uint *puVar15;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  ushort uVar16;
  uint extraout_r2;
  uint extraout_r2_00;
  ushort uVar17;
  int extraout_r3;
  int extraout_r3_00;
  Layout *pLVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  bool bVar23;
  undefined8 uVar24;
  undefined4 local_98 [2];
  String aSStack_90 [8];
  undefined4 local_88 [2];
  AbyssEngine aAStack_80 [8];
  AbyssEngine aAStack_78 [8];
  String aSStack_70 [8];
  String aSStack_68 [8];
  AbyssEngine aAStack_60 [8];
  String aSStack_58 [8];
  undefined8 local_50;
  undefined4 local_48;
  int local_44;
  
  uVar14 = 0;
  uVar16 = 0;
  local_44 = __stack_chk_guard;
  iVar3 = *(int *)(this + 4);
  if (iVar3 == 0) {
    uVar14 = 0xff;
  }
  *(undefined4 *)(this + 0x1a4) = uVar14;
  if (((*(ushort *)(this + 0x138) & 0xff) == 0) && (*(ushort *)(this + 0x138) < 0x100)) {
    uVar17 = 0;
  }
  else {
    fVar11 = (float)AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(this + 0x184));
    fVar4 = (float)AbyssEngine::EaseInOut::GetMinValue(*(EaseInOut **)(this + 0x184));
    fVar5 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(this + 0x184));
    fVar6 = (float)AbyssEngine::EaseInOut::GetMinValue(*(EaseInOut **)(this + 0x184));
    uVar17 = *(ushort *)(this + 0x138);
    uVar16 = uVar17 >> 8;
    fVar11 = (fVar11 - fVar4) / (fVar5 - fVar6);
    if ((uVar17 & 0xff) != 0) {
      fVar11 = 1.0 - fVar11;
    }
    *(int *)(this + 0x1a4) = (int)(fVar11 * 255.0);
    iVar3 = *(int *)(this + 4);
  }
  if ((uVar16 != 0 || (uVar17 & 0xff) != 0) || iVar3 != 3) {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    if (**(int **)(this + 0x68) != 0) {
      uVar19 = 0;
      do {
        iVar3 = Status::getSystemVisibilities(Globals::status);
        if ((*(char *)(*(int *)(iVar3 + 4) + uVar19) != '\0') &&
           ((((this[0x118] == (StarMap)0x0 || (*(uint *)(this + 0x114) != uVar19)) ||
             (3999 < *(int *)(this + 0x11c))) &&
            (puVar7 = (uint *)SolarSystem::getRoutes
                                        (*(SolarSystem **)
                                          (*(int *)(*(int *)(this + 0x54) + 4) + uVar19 * 4)),
            puVar7 != (uint *)0x0)))) {
          puVar8 = *(undefined8 **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar19 * 4);
          local_50 = *puVar8;
          local_48 = *(undefined4 *)(puVar8 + 1);
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_50);
          if (*puVar7 != 0) {
            uVar21 = 0;
            do {
              iVar3 = Status::getSystemVisibilities(Globals::status);
              uVar9 = *(uint *)(puVar7[1] + uVar21 * 4);
              if (((*(char *)(*(int *)(iVar3 + 4) + uVar9) != '\0') &&
                  (puVar15 = *(uint **)(this + 0x194), uVar9 < *puVar15)) &&
                 ((this[0x118] == (StarMap)0x0 ||
                  ((*(uint *)(this + 0x114) != uVar9 || (3999 < *(int *)(this + 0x11c))))))) {
                puVar8 = *(undefined8 **)(puVar15[1] + uVar9 * 4);
                local_50 = *puVar8;
                local_48 = *(undefined4 *)(puVar8 + 1);
                AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x84),(Vector *)&local_50);
                if ((-1 < (int)((uint)(*(float *)(this + 0x80) < 0.0) << 0x1f)) ||
                   (-1 < (int)((uint)(*(float *)(this + 0x8c) < 0.0) << 0x1f))) {
                  AbyssEngine::PaintCanvas::DrawLine
                            (Globals::Canvas,(int)*(float *)(this + 0x78),
                             (int)*(float *)(this + 0x7c),(int)*(float *)(this + 0x84),
                             (int)*(float *)(this + 0x88));
                }
              }
              uVar21 = uVar21 + 1;
            } while (uVar21 < *puVar7);
          }
        }
        uVar19 = uVar19 + 1;
      } while (uVar19 < **(uint **)(this + 0x68));
    }
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    iVar20 = *(int *)(this + 0x194);
    pSVar10 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar3 = SolarSystem::getIndex(pSVar10);
    puVar8 = *(undefined8 **)(*(int *)(iVar20 + 4) + iVar3 * 4);
    local_50 = *puVar8;
    local_48 = *(undefined4 *)(puVar8 + 1);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x84),(Vector *)&local_50);
    pSVar10 = (SolarSystem *)Status::getSystem(Globals::status);
    puVar7 = (uint *)SolarSystem::getRoutes(pSVar10);
    if (**(int **)(this + 0x54) != 0) {
      uVar19 = 0;
      do {
        if ((uVar19 < **(uint **)(this + 0x194)) &&
           (iVar3 = Status::getSystemVisibilities(Globals::status),
           *(char *)(*(int *)(iVar3 + 4) + uVar19) != '\0')) {
          puVar8 = *(undefined8 **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar19 * 4);
          local_50 = *puVar8;
          local_48 = *(undefined4 *)(puVar8 + 1);
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_50);
          if ((int)((uint)(*(float *)(this + 0x80) < 0.0) << 0x1f) < 0) {
            bVar23 = (int)((uint)(*(float *)(this + 0x8c) < 0.0) << 0x1f) < 0;
          }
          else {
            bVar23 = false;
          }
          if (puVar7 != (uint *)0x0) {
            SVar2 = (StarMap)(bVar23 ^ 1);
            bVar23 = SVar2 == (StarMap)0x1;
            if (bVar23) {
              SVar2 = this[0xab];
            }
            if ((bVar23 && SVar2 == (StarMap)0x0) && (*puVar7 != 0)) {
              uVar21 = 0;
              do {
                if (*(uint *)(puVar7[1] + uVar21 * 4) == uVar19) {
                  uVar24 = Status::getPlayingTime(Globals::status);
                  uVar24 = __aeabi_ldivmod((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),10,0);
                  __aeabi_ldivmod((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),99,0);
                  fVar11 = (float)__aeabi_l2f(0x65 - extraout_r2,
                                              -(uint)(0x65 < extraout_r2) - extraout_r3);
                  AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
                  AbyssEngine::PaintCanvas::DrawLine
                            (Globals::Canvas,(int)*(float *)(this + 0x84),
                             (int)*(float *)(this + 0x88),
                             (int)(*(float *)(this + 0x78) +
                                  (fVar11 / 100.0) *
                                  (*(float *)(this + 0x84) - *(float *)(this + 0x78))),
                             (int)(*(float *)(this + 0x7c) +
                                  (fVar11 / 100.0) *
                                  (*(float *)(this + 0x88) - *(float *)(this + 0x7c))));
                  break;
                }
                uVar21 = uVar21 + 1;
              } while (uVar21 < *puVar7);
            }
          }
          if (((*(ushort *)(this + 0x138) & 0xff) == 0) && (*(ushort *)(this + 0x138) < 0x100)) {
            drawOnScreenInfo(this,uVar19,false);
          }
        }
        uVar19 = uVar19 + 1;
      } while (uVar19 < **(uint **)(this + 0x54));
    }
  }
  if ((((*(int *)(this + 4) == 0) && ((*(ushort *)(this + 0x138) & 0xff) == 0)) &&
      (*(ushort *)(this + 0x138) < 0x100)) && (*(int *)(this + 0xa0) != 0)) {
    uVar24 = Status::getPlayingTime(Globals::status);
    uVar24 = __aeabi_ldivmod((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),10,0);
    __aeabi_ldivmod((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),99,0);
    fVar11 = (float)__aeabi_l2f(0x65 - extraout_r2_00,
                                -(uint)(0x65 < extraout_r2_00) - extraout_r3_00);
    uVar19 = *(uint *)(this + 0xe8);
    fVar11 = fVar11 / 100.0;
    if (fVar11 <= *(float *)(this + 0xec)) {
      puVar7 = *(uint **)(this + 0xa0);
    }
    else {
      uVar21 = uVar19 + 1;
      *(uint *)(this + 0xe8) = uVar21;
      puVar7 = *(uint **)(this + 0xa0);
      uVar19 = 0;
      if (uVar21 < *puVar7) {
        uVar19 = uVar21;
      }
      *(uint *)(this + 0xe8) = uVar19;
    }
    *(float *)(this + 0xec) = fVar11;
    if (uVar19 == *puVar7 - 1) {
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,'\0');
    }
    else {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    }
    uVar19 = *(uint *)(this + 0xe8);
    if (0 < (int)uVar19) {
      iVar3 = 0;
      do {
        puVar8 = *(undefined8 **)
                  (*(int *)(*(int *)(this + 0x194) + 4) +
                  *(int *)(*(int *)(*(int *)(this + 0xa0) + 4) + iVar3 * 4) * 4);
        local_50 = *puVar8;
        local_48 = *(undefined4 *)(puVar8 + 1);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x84),(Vector *)&local_50);
        puVar8 = *(undefined8 **)
                  (*(int *)(*(int *)(this + 0x194) + 4) +
                  *(int *)(*(int *)(*(int *)(this + 0xa0) + 4) + iVar3 * 4 + 4) * 4);
        local_50 = *puVar8;
        local_48 = *(undefined4 *)(puVar8 + 1);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_50);
        AbyssEngine::PaintCanvas::DrawLine
                  (Globals::Canvas,(int)*(float *)(this + 0x84),(int)*(float *)(this + 0x88),
                   (int)*(float *)(this + 0x78),(int)*(float *)(this + 0x7c));
        uVar19 = *(uint *)(this + 0xe8);
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)uVar19);
    }
    if (uVar19 < **(int **)(this + 0xa0) - 1U) {
      puVar8 = *(undefined8 **)
                (*(int *)(*(int *)(this + 0x194) + 4) +
                *(int *)((*(int **)(this + 0xa0))[1] + uVar19 * 4) * 4);
      local_50 = *puVar8;
      local_48 = *(undefined4 *)(puVar8 + 1);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x84),(Vector *)&local_50);
      puVar8 = *(undefined8 **)
                (*(int *)(*(int *)(this + 0x194) + 4) +
                *(int *)(*(int *)(*(int *)(this + 0xa0) + 4) + *(int *)(this + 0xe8) * 4 + 4) * 4);
      local_50 = *puVar8;
      local_48 = *(undefined4 *)(puVar8 + 1);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)&local_50);
      AbyssEngine::PaintCanvas::DrawLine
                (Globals::Canvas,(int)*(float *)(this + 0x84),(int)*(float *)(this + 0x88),
                 (int)(*(float *)(this + 0x78) +
                      fVar11 * (*(float *)(this + 0x84) - *(float *)(this + 0x78))),
                 (int)(*(float *)(this + 0x7c) +
                      fVar11 * (*(float *)(this + 0x88) - *(float *)(this + 0x7c))));
    }
  }
  if ((-1 < *(int *)(this + 0x60)) &&
     ((this[0x118] == (StarMap)0x0 || (3999 < *(int *)(this + 0x11c))))) {
    drawOnScreenInfo(this,*(int *)(this + 0x60),false);
  }
  if ((*(int *)(this + 0xa4) != 0) && (*(int *)(this + 0x58) != 0)) {
    iVar3 = SolarSystem::hasNoOwner
                      (*(SolarSystem **)
                        (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
    if (iVar3 != 1) {
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x34),*(int *)(Globals::layout + 0x2c),
                 *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x2c));
      iVar20 = *(int *)(Globals::layout + 0x2c);
      iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x34));
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0x80,'\0');
      uVar19 = Globals::font;
      pPVar1 = Globals::Canvas;
      SolarSystem::getName();
      iVar3 = iVar3 + iVar20 * 2;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar19,(String *)&local_50,iVar3,
                 *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0xc) + 2,false);
      AbyssEngine::String::~String((String *)&local_50);
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
      uVar19 = Globals::font;
      this_00 = Globals::gameText;
      pPVar1 = Globals::Canvas;
      iVar20 = SolarSystem::getRace
                         (*(SolarSystem **)
                           (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
      pSVar12 = (String *)GameText::getText(this_00,iVar20 + 0x196);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar19,pSVar12,iVar3,
                 *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0xc) +
                 *(int *)(Globals::layout + 4) + 2,false);
      iVar20 = SolarSystem::getSecurityLevel
                         (*(SolarSystem **)
                           (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4));
      AbyssEngine::PaintCanvas::SetColor
                ((uchar)Globals::Canvas,(&DAT_0025451c)[iVar20 * 0xc],(&DAT_00254520)[iVar20 * 0xc],
                 (&DAT_00254524)[iVar20 * 0xc]);
      uVar19 = Globals::font;
      pPVar1 = Globals::Canvas;
      pSVar12 = (String *)GameText::getText(Globals::gameText,iVar20 + 0x192);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar19,pSVar12,iVar3,
                 *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0xc) +
                 *(int *)(Globals::layout + 4) * 2 + 2,false);
    }
    puVar7 = *(uint **)(this + 0x58);
    uVar19 = *(uint *)(this + 100);
    if (*puVar7 != 0) {
      uVar21 = 0;
      do {
        if (uVar21 != uVar19) {
          drawOnScreenInfo(this,uVar21,true);
          puVar7 = *(uint **)(this + 0x58);
          uVar19 = *(uint *)(this + 100);
        }
        uVar21 = uVar21 + 1;
      } while (uVar21 < *puVar7);
    }
    if (-1 < (int)uVar19) {
      drawOnScreenInfo(this,uVar19,true);
    }
  }
  if (this[0x108] != (StarMap)0x0) {
    drawKey(this);
  }
  pLVar18 = Globals::layout;
  pSVar12 = (String *)GameText::getText(Globals::gameText,0xb1);
  AbyssEngine::String::String(aSStack_58,pSVar12,false);
  Layout::drawHeader(pLVar18,aSStack_58);
  AbyssEngine::String::~String(aSStack_58);
  Layout::drawEmptyFooter(Globals::layout,true);
  this_01 = (Ship *)Status::getShip(Globals::status);
  iVar3 = Ship::hasJumpDriveIntegrated(this_01);
  if ((iVar3 != 0) || (this[0xab] != (StarMap)0x0)) {
    iVar3 = *(int *)(this + 0x1d0);
    if (0 < iVar3) {
      pLVar18 = *(Layout **)(this + 0x60);
    }
    pLVar13 = (Layout *)(iVar3 + -1);
    if (iVar3 >= 1) {
      pLVar13 = pLVar18;
    }
    if ((int)pLVar13 < 0 == (iVar3 < 1 && SBORROW4(iVar3,1))) {
      pSVar10 = (SolarSystem *)Status::getSystem(Globals::status);
      pLVar13 = (Layout *)SolarSystem::getIndex(pSVar10);
      if (pLVar18 != pLVar13) {
        pSVar12 = (String *)GameText::getText(Globals::gameText,0x242);
        AbyssEngine::String::String(aSStack_68," ",false);
        AbyssEngine::operator+(aAStack_60,pSVar12,aSStack_68);
        local_88[0] = 0;
        AbyssEngine::String::Set(CONCAT44(extraout_r1,local_88));
        AbyssEngine::String::String(aSStack_90," / ",false);
        AbyssEngine::operator+(aAStack_80,(String *)local_88,aSStack_90);
        local_98[0] = 0;
        AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_98));
        AbyssEngine::operator+(aAStack_78,aAStack_80,(String *)local_98);
        AbyssEngine::String::String(aSStack_70,aAStack_78,false);
        AbyssEngine::operator+((AbyssEngine *)&local_50,aAStack_60,aSStack_70);
        AbyssEngine::String::~String(aSStack_70);
        AbyssEngine::String::~String((String *)aAStack_78);
        AbyssEngine::String::~String((String *)local_98);
        AbyssEngine::String::~String((String *)aAStack_80);
        AbyssEngine::String::~String(aSStack_90);
        AbyssEngine::String::~String((String *)local_88);
        AbyssEngine::String::~String((String *)aAStack_60);
        AbyssEngine::String::~String(aSStack_68);
        if (*(int *)(this + 0x1d8) < *(int *)(this + 0x1d0)) {
          AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        }
        uVar19 = Globals::font;
        pPVar1 = Globals::Canvas;
        iVar20 = *(int *)(Globals::layout + 0x2dc);
        iVar22 = *(int *)(Globals::layout + 0x2e4);
        iVar3 = AbyssEngine::PaintCanvas::GetTextWidth
                          (Globals::Canvas,Globals::font,(String *)&local_50);
        AbyssEngine::PaintCanvas::DrawString
                  (pPVar1,uVar19,(String *)&local_50,(iVar20 + iVar22 / 2) - iVar3 / 2,
                   (*(int *)(Globals::layout + 0x2e0) + *(int *)(Globals::layout + 0x2e8)) -
                   *(int *)(Globals::layout + 0x14),false);
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        AbyssEngine::String::~String((String *)&local_50);
      }
    }
  }
  TouchButton::draw(*(TouchButton **)(this + 0x4c));
  if (this[0xa9] != (StarMap)0x0) {
    ChoiceWindow::draw(*(ChoiceWindow **)(this + 0x5c));
  }
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarMap::missionChanged  @0x000da2a0  (6 bytes)
/* StarMap::missionChanged() */

StarMap __thiscall StarMap::missionChanged(StarMap *this)

{
  return this[0xdc];
}

// ===== StarMap::askForJumpIntoAlienWorld  @0x000da2a8  (50 bytes)
/* StarMap::askForJumpIntoAlienWorld() */

void __thiscall StarMap::askForJumpIntoAlienWorld(StarMap *this)

{
  bool bVar1;
  String *pSVar2;
  
  this[0x120] = (StarMap)0x1;
  pSVar2 = *(String **)(this + 0x5c);
  bVar1 = (bool)GameText::getText(Globals::gameText,0x1a6);
  ChoiceWindow::set(pSVar2,bVar1);
  this[0xa9] = (StarMap)0x1;
  return;
}

// ===== StarMap::update  @0x000da2e0  (3094 bytes)
/* StarMap::update(int) */

void StarMap::update(int param_1)

{
  byte bVar1;
  PaintCanvas *pPVar2;
  int iVar3;
  Matrix *pMVar4;
  Matrix *pMVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  AEGeometry *this;
  int in_r1;
  uint *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  void *pvVar17;
  uint uVar18;
  Vector *pVVar19;
  void *pvVar20;
  char cVar21;
  uint in_fpscr;
  uint uVar22;
  float in_s0;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s2;
  float extraout_s2_00;
  int iVar23;
  int iVar24;
  float fVar25;
  float fVar26;
  Vector *pVVar27;
  longlong lVar28;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  AEMath aAStack_b0 [12];
  AEMath aAStack_a4 [12];
  AEMath aAStack_98 [12];
  AEMath aAStack_8c [12];
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  *(int *)(param_1 + 0x18) = in_r1;
  iVar3 = *(int *)(param_1 + 4);
  if ((((iVar3 == 0) || ((*(ushort *)(param_1 + 0x138) & 0xff) != 0)) ||
      (0xff < *(ushort *)(param_1 + 0x138))) && (**(int **)(param_1 + 0x194) != 0)) {
    uVar18 = 0;
    do {
      pPVar2 = Globals::Canvas;
      AEGeometry::getPosition();
      iVar3 = AbyssEngine::PaintCanvas::GetScreenPosition
                        (pPVar2,(Vector *)&local_80,
                         *(Vector **)(*(int *)(*(int *)(param_1 + 0x194) + 4) + uVar18 * 4));
      puVar13 = *(uint **)(param_1 + 0x194);
      in_s0 = -1.0;
      if (iVar3 != 0) {
        in_s0 = 1.0;
      }
      iVar3 = uVar18 * 4;
      uVar18 = uVar18 + 1;
      *(float *)(*(int *)(puVar13[1] + iVar3) + 8) = in_s0;
    } while (uVar18 < *puVar13);
    iVar3 = *(int *)(param_1 + 4);
  }
  if ((((iVar3 == 3) || ((*(ushort *)(param_1 + 0x138) & 0xff) != 0)) ||
      (0xff < *(ushort *)(param_1 + 0x138))) && (**(int **)(param_1 + 0x198) != 0)) {
    uVar18 = 0;
    do {
      pMVar4 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 0xa4));
      pMVar5 = (Matrix *)
               AEGeometry::getMatrix
                         (*(AEGeometry **)(*(int *)(*(int *)(param_1 + 0x90) + 4) + uVar18 * 4 + 4))
      ;
      AbyssEngine::AEMath::operator*((AEMath *)&local_80,pMVar4,pMVar5);
      AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_ec,(AEMath *)&local_80);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x84),(Vector *)&local_ec);
      iVar3 = AbyssEngine::PaintCanvas::GetScreenPosition
                        (Globals::Canvas,(Vector *)(param_1 + 0x84),
                         *(Vector **)(*(int *)(*(int *)(param_1 + 0x198) + 4) + uVar18 * 4));
      puVar13 = *(uint **)(param_1 + 0x198);
      in_s0 = -1.0;
      if (iVar3 != 0) {
        in_s0 = 1.0;
      }
      iVar3 = uVar18 * 4;
      uVar18 = uVar18 + 1;
      *(float *)(*(int *)(puVar13[1] + iVar3) + 8) = in_s0;
    } while (uVar18 < *puVar13);
  }
  if (*(int *)(param_1 + 0xf8) != 0) {
    fVar6 = (float)AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(param_1 + 0x184));
    fVar7 = (float)AbyssEngine::EaseInOut::GetMinValue(*(EaseInOut **)(param_1 + 0x184));
    fVar8 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(param_1 + 0x184));
    fVar9 = (float)AbyssEngine::EaseInOut::GetMinValue(*(EaseInOut **)(param_1 + 0x184));
    pVVar27 = (Vector *)((fVar6 - fVar7) / (fVar8 - fVar9));
    if (*(char *)(param_1 + 0x139) == '\0') {
      if ((*(char *)(param_1 + 0x138) == '\0') && (*(int *)(param_1 + 4) == 0)) {
        pVVar27 = (Vector *)0x0;
      }
    }
    else {
      pVVar27 = (Vector *)(1.0 - (float)pVVar27);
    }
    AEGeometry::setScaling
              (*(AEGeometry **)(param_1 + 0xf8),(float)pVVar27 * -0.014 + 0.02,extraout_s1,
               fVar6 - fVar7);
    if ((*(int *)(param_1 + 0xa4) != 0) && (-1 < *(int *)(param_1 + 0x1c4))) {
      AEGeometry::getPosition();
      pMVar4 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 0xa4));
      pMVar5 = (Matrix *)
               AEGeometry::getMatrix
                         (*(AEGeometry **)
                           (*(int *)(*(int *)(param_1 + 0x90) + 4) + *(int *)(param_1 + 0x1c4) * 4))
      ;
      AbyssEngine::AEMath::operator*((AEMath *)&local_80,pMVar4,pMVar5);
      AbyssEngine::AEMath::MatrixGetPosition(aAStack_8c,(AEMath *)&local_80);
      pVVar19 = *(Vector **)(param_1 + 0xf8);
      fVar6 = (float)AbyssEngine::AEMath::operator-
                               (aAStack_b0,(Vector *)aAStack_8c,(Vector *)&local_ec);
      AbyssEngine::AEMath::operator*(aAStack_a4,fVar6,pVVar27);
      AbyssEngine::AEMath::operator+(aAStack_98,(Vector *)&local_ec,(Vector *)aAStack_a4);
      AEGeometry::setPosition(pVVar19);
    }
    pPVar2 = Globals::Canvas;
    uVar18 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar2,uVar18);
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_80,pMVar4);
    pVVar27 = (Vector *)(param_1 + 0x78);
    AbyssEngine::AEMath::Vector::operator=(pVVar27,(Vector *)&local_80);
    AEGeometry::getPosition();
    AbyssEngine::AEMath::Vector::operator-=(pVVar27,(Vector *)&local_80);
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_ec,pVVar27);
    AbyssEngine::AEMath::Vector::operator=(pVVar27,(Vector *)&local_ec);
    *(float *)(param_1 + 0x78) = *(float *)(param_1 + 0x78) + 0.5;
    local_ec = 0;
    local_e8 = 0x3f800000;
    uStack_e4 = 0;
    AEGeometry::setDirection(*(AEGeometry **)(param_1 + 0xf8),pVVar27,(Vector *)&local_ec);
    lVar28 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(param_1 + 0xf8) + 0xc));
    in_s0 = (float)AbyssEngine::Transform::Update(lVar28,SUB41(in_r1,0));
  }
  if (((*(ushort *)(param_1 + 0x138) & 0xff) != 0) || (0xff < *(ushort *)(param_1 + 0x138))) {
    fVar6 = (float)VectorSignedToFloat(in_r1 * 0xf,(byte)(in_fpscr >> 0x16) & 3);
    fVar6 = (float)AbyssEngine::EaseInOut::Increase(*(EaseInOut **)(param_1 + 0x17c),fVar6);
    fVar6 = (float)AbyssEngine::EaseInOut::Increase(*(EaseInOut **)(param_1 + 0x180),fVar6);
    AbyssEngine::EaseInOut::Increase(*(EaseInOut **)(param_1 + 0x184),fVar6);
    uVar10 = AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(param_1 + 0x17c));
    uVar11 = AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(param_1 + 0x180));
    local_78 = AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(param_1 + 0x184));
    local_80 = uVar10;
    uStack_7c = uVar11;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x78),(Vector *)&local_80);
    pPVar2 = Globals::Canvas;
    uVar18 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    puVar12 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar2,uVar18);
    local_80 = *puVar12;
    uStack_7c = puVar12[1];
    local_78 = puVar12[2];
    uStack_74 = puVar12[3];
    uStack_70 = puVar12[4];
    local_6c = puVar12[5];
    uStack_68 = puVar12[6];
    uStack_64 = puVar12[7];
    uStack_60 = puVar12[8];
    uStack_5c = puVar12[9];
    local_58 = puVar12[10];
    uStack_54 = puVar12[0xb];
    uStack_50 = puVar12[0xc];
    uStack_4c = puVar12[0xd];
    uStack_48 = puVar12[0xe];
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_ec,(Vector *)&local_80,*(float *)(param_1 + 0x80),extraout_s1_02,
               extraout_s2);
    pPVar2 = Globals::Canvas;
    uVar18 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    AbyssEngine::PaintCanvas::CameraSetLocal(pPVar2,uVar18,(Vector *)&local_80);
    fVar9 = *(float *)(param_1 + 0x78);
    fVar7 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(param_1 + 0x17c));
    fVar8 = *(float *)(param_1 + 0x78);
    fVar6 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(param_1 + 0x17c));
    fVar8 = fVar8 - fVar6;
    fVar6 = -fVar8;
    if (0.0 < fVar9 - fVar7) {
      fVar6 = fVar8;
    }
    if (fVar6 <= 1.0) {
      fVar9 = *(float *)(param_1 + 0x7c);
      fVar7 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(param_1 + 0x180));
      fVar8 = *(float *)(param_1 + 0x7c);
      fVar6 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(param_1 + 0x180));
      fVar8 = fVar8 - fVar6;
      fVar6 = -fVar8;
      if (0.0 < fVar9 - fVar7) {
        fVar6 = fVar8;
      }
      if (fVar6 <= 1.0) {
        fVar9 = *(float *)(param_1 + 0x80);
        fVar7 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(param_1 + 0x184));
        fVar8 = *(float *)(param_1 + 0x80);
        fVar6 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)(param_1 + 0x184));
        fVar8 = fVar8 - fVar6;
        fVar6 = -fVar8;
        if (0.0 < fVar9 - fVar7) {
          fVar6 = fVar8;
        }
        if (fVar6 <= 1.0) {
          if (*(char *)(param_1 + 0x138) == '\0') {
            ArrayReleaseClasses<AEGeometry*>(*(Array **)(param_1 + 0x90));
            pvVar17 = *(void **)(param_1 + 0x90);
            if (pvVar17 != (void *)0x0) {
              if (*(void **)((int)pvVar17 + 4) != (void *)0x0) {
                operator_delete__(*(void **)((int)pvVar17 + 4));
              }
              operator_delete(pvVar17);
            }
            *(undefined4 *)(param_1 + 0x90) = 0;
            ArrayReleaseClasses<AEGeometry*>(*(Array **)(param_1 + 0x94));
            pvVar17 = *(void **)(param_1 + 0x94);
            if (pvVar17 != (void *)0x0) {
              if (*(void **)((int)pvVar17 + 4) != (void *)0x0) {
                operator_delete__(*(void **)((int)pvVar17 + 4));
              }
              operator_delete(pvVar17);
            }
            *(undefined4 *)(param_1 + 0x94) = 0;
            if (*(void **)(param_1 + 0x98) != (void *)0x0) {
              operator_delete__(*(void **)(param_1 + 0x98));
            }
            *(undefined4 *)(param_1 + 0x98) = 0;
            if (*(void **)(param_1 + 0x9c) != (void *)0x0) {
              operator_delete__(*(void **)(param_1 + 0x9c));
            }
            *(undefined4 *)(param_1 + 0x9c) = 0;
            pvVar20 = *(void **)(param_1 + 0x100);
            pvVar17 = pvVar20;
            if (*(void **)((int)pvVar20 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar20 + 4));
              pvVar17 = *(void **)(param_1 + 0x100);
            }
            *(undefined4 *)((int)pvVar20 + 4) = 0;
            if (pvVar17 != (void *)0x0) {
              if (*(void **)((int)pvVar17 + 4) != (void *)0x0) {
                operator_delete__(*(void **)((int)pvVar17 + 4));
              }
              operator_delete(pvVar17);
            }
            *(undefined4 *)(param_1 + 0x100) = 0;
            if (*(AEGeometry **)(param_1 + 0xa4) != (AEGeometry *)0x0) {
              pvVar17 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(param_1 + 0xa4));
              operator_delete(pvVar17);
            }
            *(undefined4 *)(param_1 + 0xa4) = 0;
            *(undefined4 *)(param_1 + 4) = 0;
            AEGeometry::setVisible
                      (*(AEGeometry **)
                        (*(int *)(*(int *)(param_1 + 0x68) + 4) + *(int *)(param_1 + 0x60) * 4),true
                      );
          }
          else {
            *(undefined4 *)(param_1 + 4) = 3;
          }
          *(undefined2 *)(param_1 + 0x138) = 0;
        }
      }
    }
    goto LAB_000daf04;
  }
  FModSound::setParamValue(Globals::sound,0,in_s0);
  if (*(int *)(param_1 + 4) == 3) {
    if (*(char *)(param_1 + 0x13b) == '\0') {
      if (*(char *)(param_1 + 0x174) == '\0') {
        fVar6 = *(float *)(param_1 + 0x168);
        fVar8 = *(float *)(param_1 + 0x16c);
        fVar9 = fVar6 * fVar8;
        *(float *)(param_1 + 0x16c) = fVar9;
        fVar7 = fVar6 * *(float *)(param_1 + 0x170);
        fVar6 = -(fVar6 * fVar8);
        if (0.0 < fVar9) {
          fVar6 = fVar9;
        }
        *(float *)(param_1 + 0x170) = fVar7;
        if (0.5 < fVar6) {
          *(float *)(param_1 + 0x188) = fVar9 + *(float *)(param_1 + 0x188);
        }
        fVar6 = -fVar7;
        if (0.0 < fVar7) {
          fVar6 = fVar7;
        }
        uVar18 = in_fpscr & 0xfffffff | (uint)(fVar6 < 0.5) << 0x1f | (uint)(fVar6 == 0.5) << 0x1e;
        in_fpscr = uVar18 | (uint)NAN(fVar6) << 0x1c;
        bVar1 = (byte)(uVar18 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
          *(float *)(param_1 + 0x18c) = fVar7 + *(float *)(param_1 + 0x18c);
        }
      }
    }
    else {
      iVar23 = (int)*(float *)(param_1 + 0x188);
      iVar24 = (int)*(float *)(param_1 + 0x18c);
      iVar14 = 0x8000 - *(int *)(*(int *)(param_1 + 0x98) + *(int *)(param_1 + 100) * 4);
      iVar3 = -0xc18 - iVar24;
      if (-0xc18 < iVar24) {
        iVar3 = iVar24 + 0xc18;
      }
      iVar15 = iVar23 - iVar14;
      iVar16 = iVar15;
      if (iVar15 < 0) {
        iVar16 = -iVar15;
      }
      if (iVar23 < iVar14) {
        iVar15 = iVar14 - iVar23;
        fVar6 = 0.25;
      }
      else {
        fVar6 = -0.25;
      }
      fVar7 = (float)VectorSignedToFloat(iVar15,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x188) = *(float *)(param_1 + 0x188) + fVar7 * fVar6;
      if (iVar16 < 0xb) {
        *(undefined1 *)(param_1 + 0x13b) = 0;
      }
      if (iVar24 < -0xc18) {
        fVar6 = (float)VectorSignedToFloat(-0xc18 - iVar24,(byte)(in_fpscr >> 0x16) & 3);
        fVar6 = fVar6 * 0.25;
      }
      else {
        fVar6 = (float)VectorSignedToFloat(iVar24 + 0xc18,(byte)(in_fpscr >> 0x16) & 3);
        fVar6 = fVar6 * -0.25;
      }
      *(float *)(param_1 + 0x18c) = fVar6 + *(float *)(param_1 + 0x18c);
      if (iVar16 <= in_r1 * 4) {
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 <= in_r1 * 4) {
          *(undefined1 *)(param_1 + 0x13b) = 0;
          *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 100);
        }
      }
    }
    fVar7 = *(float *)(param_1 + 0x16c) + *(float *)(param_1 + 0x170);
    fVar6 = -fVar7;
    if (0.0 < fVar7) {
      fVar6 = fVar7;
    }
    fVar7 = 10.0;
    if (fVar6 * 0.01 < 10.0) {
      fVar7 = fVar6 * 0.01;
    }
    fVar7 = *(float *)(param_1 + 0x1c0) + fVar7;
    uVar18 = in_fpscr & 0xfffffff | (uint)(fVar7 < 100.0) << 0x1f | (uint)(fVar7 == 100.0) << 0x1e;
    uVar22 = uVar18 | (uint)NAN(fVar7) << 0x1c;
    bVar1 = (byte)(uVar18 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar22 >> 0x1c) & 1)) {
      fVar7 = 0.0;
    }
    *(float *)(param_1 + 0x1c0) = fVar7;
    puVar13 = *(uint **)(param_1 + 0x90);
    fVar6 = extraout_s1_00;
    if ((puVar13 != (uint *)0x0) && (*puVar13 != 0)) {
      fVar8 = 0.0002;
      uVar18 = 0;
      fVar7 = (float)VectorSignedToFloat(in_r1,(byte)(uVar22 >> 0x16) & 3);
      fVar7 = fVar7 * 0.0002;
      do {
        this = *(AEGeometry **)(puVar13[1] + uVar18 * 4);
        if (this != (AEGeometry *)0x0) {
          AEGeometry::rotate(this,fVar7,fVar6,fVar8);
          puVar13 = *(uint **)(param_1 + 0x90);
          fVar7 = extraout_s0;
          fVar6 = extraout_s1_04;
          fVar8 = extraout_s2_00;
        }
        uVar18 = uVar18 + 1;
      } while (uVar18 < *puVar13);
    }
    fVar8 = (float)VectorSignedToFloat((int)*(float *)(param_1 + 0x188) % 0x10000,
                                       (byte)(uVar22 >> 0x16) & 3);
    *(float *)(param_1 + 0x188) = fVar8;
    fVar9 = *(float *)(param_1 + 0x18c);
    fVar7 = -8192.0;
    if (-8192.0 < fVar9) {
      fVar7 = 8192.0;
    }
    if (8192.0 < fVar9) {
      fVar7 = 8192.0;
    }
    fVar25 = fVar9;
    if (fVar9 <= -8192.0) {
      fVar25 = fVar7;
    }
    if (8192.0 < fVar9) {
      fVar25 = fVar7;
    }
    *(float *)(param_1 + 0x18c) = fVar25;
    AEGeometry::setRotation
              (*(AEGeometry **)(param_1 + 0xa4),fVar8 * 1.5258789e-05 * 6.2831855,fVar6,
               fVar25 * 1.5258789e-05 * 6.2831855);
    goto LAB_000daf04;
  }
  if (*(int *)(param_1 + 4) != 0) goto LAB_000daf04;
  iVar3 = *(int *)(param_1 + 0x114);
  if (((-1 < iVar3) && (*(char *)(param_1 + 0x118) != '\0')) && (*(int *)(param_1 + 0x11c) < 4000))
  {
    iVar14 = *(int *)(param_1 + 0x11c) + in_r1;
    *(int *)(param_1 + 0x11c) = iVar14;
    fVar6 = extraout_s1_00;
    if (3999 < iVar14) {
      OnTouchBegin((StarMap *)param_1,Globals::w >> 1,Globals::h >> 1);
      iVar3 = *(int *)(param_1 + 0x114);
      iVar14 = *(int *)(param_1 + 0x11c);
      fVar6 = extraout_s1_01;
    }
    fVar7 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::setScaling
              (*(AEGeometry **)(*(int *)(*(int *)(param_1 + 0x68) + 4) + iVar3 * 4),
               (fVar7 / 4000.0) * 0.002,fVar6,4000.0);
  }
  if (*(char *)(param_1 + 0x174) == '\0') {
    fVar6 = *(float *)(param_1 + 0x168);
    fVar8 = *(float *)(param_1 + 0x16c);
    fVar9 = fVar6 * fVar8;
    *(float *)(param_1 + 0x16c) = fVar9;
    fVar7 = fVar6 * *(float *)(param_1 + 0x170);
    fVar6 = -(fVar6 * fVar8);
    if (0.0 < fVar9) {
      fVar6 = fVar9;
    }
    *(float *)(param_1 + 0x170) = fVar7;
    uVar18 = in_fpscr & 0xfffffff | (uint)(fVar6 < 0.5) << 0x1f | (uint)(fVar6 == 0.5) << 0x1e;
    uVar22 = uVar18 | (uint)NAN(fVar6) << 0x1c;
    bVar1 = (byte)(uVar18 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar22 >> 0x1c) & 1)) {
      fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x13c),(byte)(uVar22 >> 0x16) & 3
                                        );
      *(int *)(param_1 + 0x13c) = (int)(fVar9 + fVar6);
    }
    fVar6 = -fVar7;
    if (0.0 < fVar7) {
      fVar6 = fVar7;
    }
    uVar18 = in_fpscr & 0xfffffff | (uint)(fVar6 < 0.5) << 0x1f | (uint)(fVar6 == 0.5) << 0x1e;
    in_fpscr = uVar18 | (uint)NAN(fVar6) << 0x1c;
    bVar1 = (byte)(uVar18 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x140),
                                         (byte)(in_fpscr >> 0x16) & 3);
      *(int *)(param_1 + 0x140) = (int)(fVar7 + fVar6);
    }
  }
  fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x140),(byte)(in_fpscr >> 0x16) & 3);
  fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x13c),(byte)(in_fpscr >> 0x16) & 3);
  iVar3 = (int)(*(float *)(param_1 + 0xc) + fVar7);
  iVar14 = (int)(*(float *)(param_1 + 8) + fVar6);
  if (iVar14 < 0x79) {
    if (iVar14 < -500) {
      iVar14 = -500 - iVar14;
      goto LAB_000da9b0;
    }
  }
  else {
    iVar14 = 0x78 - iVar14;
LAB_000da9b0:
    fVar6 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(param_1 + 0x16c) = fVar6 * 0.1;
  }
  if (iVar3 < 0x8d) {
    if (iVar3 < -400) {
      iVar3 = -400 - iVar3;
      goto LAB_000da9d6;
    }
  }
  else {
    iVar3 = 0x8c - iVar3;
LAB_000da9d6:
    fVar6 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(param_1 + 0x170) = fVar6 * 0.1;
  }
  pPVar2 = Globals::Canvas;
  uVar18 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  puVar12 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar2,uVar18);
  local_80 = *puVar12;
  uStack_7c = puVar12[1];
  local_78 = puVar12[2];
  uStack_74 = puVar12[3];
  uStack_70 = puVar12[4];
  local_6c = puVar12[5];
  uStack_68 = puVar12[6];
  uStack_64 = puVar12[7];
  uStack_60 = puVar12[8];
  uStack_5c = puVar12[9];
  local_58 = puVar12[10];
  uStack_54 = puVar12[0xb];
  uStack_50 = puVar12[0xc];
  uStack_4c = puVar12[0xd];
  uStack_48 = puVar12[0xe];
  fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x13c),(byte)(in_fpscr >> 0x16) & 3);
  fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x140),(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::MatrixSetTranslation
            ((AEMath *)&local_ec,(Matrix *)&local_80,(*(float *)(param_1 + 0xc) + fVar7) * 20.0,
             extraout_s1_03,(*(float *)(param_1 + 8) + fVar6) * 20.0);
  pPVar2 = Globals::Canvas;
  uVar18 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  AbyssEngine::PaintCanvas::CameraSetLocal(pPVar2,uVar18,(Matrix *)&local_80);
  fVar7 = *(float *)(param_1 + 0x16c) + *(float *)(param_1 + 0x170);
  fVar6 = -fVar7;
  if (0.0 < fVar7) {
    fVar6 = fVar7;
  }
  fVar7 = 10.0;
  if (fVar6 < 10.0) {
    fVar7 = fVar6;
  }
  fVar7 = *(float *)(param_1 + 0x1c0) + fVar7;
  uVar18 = in_fpscr & 0xfffffff | (uint)(fVar7 < 100.0) << 0x1f | (uint)(fVar7 == 100.0) << 0x1e;
  uVar22 = uVar18 | (uint)NAN(fVar7) << 0x1c;
  bVar1 = (byte)(uVar18 >> 0x18);
  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar22 >> 0x1c) & 1)) {
    fVar7 = 0.0;
  }
  *(float *)(param_1 + 0x1c0) = fVar7;
  if ((*(char *)(param_1 + 0x13a) != '\0') && (-1 < *(int *)(param_1 + 0x60))) {
    iVar3 = Status::getSystemVisibilities(Globals::status);
    if (*(char *)(*(int *)(iVar3 + 4) + *(int *)(param_1 + 0x60)) != '\0') {
      AbyssEngine::AEMath::Vector::operator=
                ((Vector *)(param_1 + 0x78),
                 *(Vector **)
                  (*(int *)(*(int *)(param_1 + 0x194) + 4) + *(int *)(param_1 + 0x60) * 4));
      fVar8 = (float)VectorSignedToFloat(Globals::h >> 1,(byte)(uVar22 >> 0x16) & 3);
      fVar9 = *(float *)(param_1 + 0x7c);
      fVar26 = *(float *)(param_1 + 0x78);
      fVar7 = (float)VectorSignedToFloat(Globals::w >> 1,(byte)(uVar22 >> 0x16) & 3);
      fVar25 = -(fVar26 - fVar7) / 30.0;
      fVar6 = fVar25;
      if ((fVar7 <= fVar26) && (fVar6 = 0.0, fVar26 != fVar7)) {
        fVar6 = fVar25;
      }
      fVar25 = -(fVar9 - fVar8) / 30.0;
      bVar1 = (byte)(((uint)(fVar9 == fVar8) << 0x1e) >> 0x18);
      cVar21 = -((char)((byte)(((uint)(fVar9 < fVar8) << 0x1f) >> 0x18) | bVar1) >> 7);
      if (((bool)(bVar1 >> 6) || (bool)cVar21 != (NAN(fVar9) || NAN(fVar8))) && (cVar21 == '\0')) {
        fVar25 = 0.0;
      }
      iVar14 = (int)fVar6;
      iVar3 = (int)(fVar26 - fVar7);
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar14 < 0) {
        iVar14 = -iVar14;
      }
      if (iVar3 < iVar14) {
        fVar6 = fVar6 * 0.5;
      }
      iVar14 = (int)fVar25;
      iVar3 = (int)(fVar9 - fVar8);
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (iVar14 < 0) {
        iVar14 = -iVar14;
      }
      if (iVar3 < iVar14) {
        fVar25 = fVar25 * 0.5;
      }
      fVar7 = -fVar6;
      if (0.0 < fVar6) {
        fVar7 = fVar6;
      }
      *(float *)(param_1 + 0x16c) = fVar6;
      *(float *)(param_1 + 0x170) = fVar25;
      if (fVar7 <= 2.0) {
        fVar6 = -fVar25;
        if (0.0 < fVar25) {
          fVar6 = fVar25;
        }
        if (fVar6 <= 2.0) {
          *(undefined1 *)(param_1 + 0x13a) = 0;
          *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)(param_1 + 0x60);
        }
      }
    }
  }
LAB_000daf04:
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== StarMap::OnTouchBegin  @0x000daf80  (838 bytes)
/* StarMap::OnTouchBegin(int, int) */

undefined4 __thiscall StarMap::OnTouchBegin(StarMap *this,int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  ushort uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  FileRead *this_00;
  undefined4 uVar9;
  SolarSystem *pSVar10;
  void *pvVar11;
  SystemPathFinder *this_01;
  uint uVar12;
  Array *pAVar13;
  int iVar14;
  uint in_fpscr;
  float fVar15;
  float fVar16;
  float fVar17;
  float extraout_s0;
  float fVar18;
  float fVar19;
  
  if (this[0xa9] == (StarMap)0x0) {
    if (((*(ushort *)(this + 0x138) & 0xff) == 0) && (*(ushort *)(this + 0x138) < 0x100)) {
      Layout::OnTouchBegin(Globals::layout,param_1,param_2);
      if (this[0xa8] == (StarMap)0x0) {
        uVar4 = (ushort)(byte)this[0x13b];
      }
      else {
        if ((*(ushort *)(this + 0x13a) & 0xff) != 0) {
          return 0;
        }
        uVar4 = *(ushort *)(this + 0x13a) >> 8;
      }
      if ((((uVar4 == 0) &&
           (TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x4c),param_1,param_2),
           *(int *)(Globals::layout + 0xc) < param_2)) &&
          (param_2 < Globals::h - *(int *)(Globals::layout + 0x10))) &&
         ((this[0x118] == (StarMap)0x0 || (3999 < *(int *)(this + 0x11c))))) {
        fVar15 = (float)FModSound::stop(Globals::sound,0x66);
        FModSound::play(Globals::sound,0x66,(Vector *)0x0,(Vector *)0x0,fVar15);
        fVar15 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar19 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(this + 0x15c) = fVar15;
        *(float *)(this + 0x160) = fVar19;
        *(float *)(this + 0x144) = fVar15;
        *(float *)(this + 0x148) = fVar19;
        *(undefined4 *)(this + 0x150) = 0;
        *(undefined4 *)(this + 0x154) = 0;
        this[0x174] = (StarMap)0x1;
        this[0x13a] = (StarMap)0x0;
        if (*(int *)(this + 4) == 0) {
          iVar14 = *(int *)(this + 0x60);
          *(undefined4 *)(this + 0x60) = 0xffffffff;
          *(undefined4 *)(this + 0x1d0) = 0;
          if (**(int **)(this + 0x68) != 0) {
            uVar12 = 0;
            do {
              iVar6 = Status::getSystemVisibilities(Globals::status);
              if (*(char *)(*(int *)(iVar6 + 4) + uVar12) != '\0') {
                AbyssEngine::AEMath::Vector::operator=
                          ((Vector *)(this + 0x78),
                           *(Vector **)(*(int *)(*(int *)(this + 0x194) + 4) + uVar12 * 4));
                fVar16 = *(float *)(this + 0x80);
                uVar1 = in_fpscr & 0xfffffff;
                uVar2 = uVar1 | (uint)(fVar16 < 0.0) << 0x1f | (uint)(fVar16 == 0.0) << 0x1e;
                in_fpscr = uVar2 | (uint)NAN(fVar16) << 0x1c;
                bVar3 = (byte)(uVar2 >> 0x18);
                if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
                  fVar18 = *(float *)(this + 0x78) - fVar15;
                  fVar17 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x1c8),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  fVar16 = -fVar18;
                  if (0.0 < fVar18) {
                    fVar16 = fVar18;
                  }
                  in_fpscr = uVar1;
                  if (fVar16 < fVar17) {
                    fVar18 = *(float *)(this + 0x7c) - fVar19;
                    fVar16 = -fVar18;
                    if (0.0 < fVar18) {
                      fVar16 = fVar18;
                    }
                    if (fVar16 < fVar17) {
                      *(uint *)(this + 0x60) = uVar12;
                      if (*(Array **)(this + 0x58) != (Array *)0x0) {
                        ArrayReleaseClasses<Station*>(*(Array **)(this + 0x58));
                        pvVar11 = *(void **)(this + 0x58);
                        if (pvVar11 != (void *)0x0) {
                          if (*(void **)((int)pvVar11 + 4) != (void *)0x0) {
                            operator_delete__(*(void **)((int)pvVar11 + 4));
                          }
                          operator_delete(pvVar11);
                        }
                        *(undefined4 *)(this + 0x58) = 0;
                      }
                      puVar7 = operator_new(0xc);
                      puVar8 = operator_new__(4);
                      puVar7[1] = puVar8;
                      puVar7[2] = 1;
                      *puVar8 = 0;
                      *puVar7 = 0;
                      *(undefined4 **)(this + 0x58) = puVar7;
                      this_00 = operator_new(1);
                      FileRead::FileRead(this_00);
                      uVar9 = FileRead::loadStationsBinary
                                        (this_00,*(SolarSystem **)
                                                  (*(int *)(*(int *)(this + 0x54) + 4) +
                                                  *(int *)(this + 0x60) * 4));
                      *(undefined4 *)(this + 0x58) = uVar9;
                      pvVar11 = (void *)FileRead::~FileRead(this_00);
                      operator_delete(pvVar11);
                      if (iVar14 != *(int *)(this + 0x60)) {
                        FModSound::play(Globals::sound,0x67,(Vector *)0x0,(Vector *)0x0,extraout_s0)
                        ;
                      }
                      this_01 = *(SystemPathFinder **)(this + 0x50);
                      pAVar13 = *(Array **)(this + 0x54);
                      pSVar10 = (SolarSystem *)Status::getSystem(Globals::status);
                      iVar14 = SolarSystem::getIndex(pSVar10);
                      iVar14 = SystemPathFinder::getJumpDistance
                                         (this_01,pAVar13,iVar14,*(int *)(this + 0x60));
                      *(int *)(this + 0x1d0) = iVar14;
                      if (iVar14 == 0) {
                        pSVar10 = (SolarSystem *)Status::getSystem(Globals::status);
                        iVar14 = SolarSystem::getIndex(pSVar10);
                        if (iVar14 != *(int *)(this + 0x60)) {
                          *(undefined4 *)(this + 0x1d0) = 4;
                          iVar14 = SolarSystem::getRoutes
                                             (*(SolarSystem **)
                                               (*(int *)(*(int *)(this + 0x54) + 4) +
                                               *(int *)(this + 0x60) * 4));
                          if (iVar14 == 0) {
                            this[0x1d4] = (StarMap)0x1;
                          }
                        }
                      }
                      iVar14 = Status::hardCoreMode();
                      if (iVar14 != 1) {
                        return 0;
                      }
                      *(int *)(this + 0x1d0) = *(int *)(this + 0x1d0) << 1;
                      return 0;
                    }
                  }
                }
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 < **(uint **)(this + 0x68));
          }
        }
        else if ((*(int *)(this + 4) == 3) && (puVar5 = *(uint **)(this + 0x198), *puVar5 != 0)) {
          uVar12 = 0;
          do {
            AbyssEngine::AEMath::Vector::operator=
                      ((Vector *)(this + 0x78),*(Vector **)(puVar5[1] + uVar12 * 4));
            fVar16 = *(float *)(this + 0x80);
            uVar1 = in_fpscr & 0xfffffff;
            uVar2 = uVar1 | (uint)(fVar16 < 0.0) << 0x1f | (uint)(fVar16 == 0.0) << 0x1e;
            in_fpscr = uVar2 | (uint)NAN(fVar16) << 0x1c;
            bVar3 = (byte)(uVar2 >> 0x18);
            if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
              fVar18 = *(float *)(this + 0x78) - fVar15;
              fVar17 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x1c8),
                                                  (byte)(in_fpscr >> 0x16) & 3);
              fVar16 = -fVar18;
              if (0.0 < fVar18) {
                fVar16 = fVar18;
              }
              in_fpscr = uVar1;
              if (fVar16 < fVar17) {
                fVar18 = *(float *)(this + 0x7c) - fVar19;
                fVar16 = -fVar18;
                if (0.0 < fVar18) {
                  fVar16 = fVar18;
                }
                if (fVar16 < fVar17) {
                  *(uint *)(this + 100) = uVar12;
                  FModSound::play(Globals::sound,0x68,(Vector *)0x0,(Vector *)0x0,fVar17);
                  return 0;
                }
              }
            }
            puVar5 = *(uint **)(this + 0x198);
            uVar12 = uVar12 + 1;
          } while (uVar12 < *puVar5);
        }
      }
    }
  }
  else {
    ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(this + 0x5c),param_1,param_2);
  }
  return 0;
}

// ===== StarMap::OnTouchMove  @0x000db300  (870 bytes)
/* StarMap::OnTouchMove(int, int) */

void __thiscall StarMap::OnTouchMove(StarMap *this,int param_1,int param_2)

{
  byte bVar1;
  PaintCanvas *pPVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint in_fpscr;
  float fVar6;
  float extraout_s1;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
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
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (this[0xa9] != (StarMap)0x0) {
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 0x5c),param_1,param_2);
    goto LAB_000db328;
  }
  if (((*(ushort *)(this + 0x138) & 0xff) != 0) || (0xff < *(ushort *)(this + 0x138)))
  goto LAB_000db328;
  Layout::OnTouchMove(Globals::layout,param_1,param_2);
  if (this[0xa8] == (StarMap)0x0) {
    uVar3 = (ushort)(byte)this[0x13b];
  }
  else {
    if ((*(ushort *)(this + 0x13a) & 0xff) != 0) goto LAB_000db328;
    uVar3 = *(ushort *)(this + 0x13a) >> 8;
  }
  if ((uVar3 != 0) ||
     (TouchButton::OnTouchMove(*(TouchButton **)(this + 0x4c),param_1,param_2),
     this[0x174] == (StarMap)0x0)) goto LAB_000db328;
  fVar9 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  fVar8 = (fVar9 - *(float *)(this + 0x15c)) * *(float *)(this + 0x1cc);
  fVar6 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0x150) = fVar8;
  fVar7 = (fVar6 - *(float *)(this + 0x160)) * *(float *)(this + 0x1cc);
  *(float *)(this + 0x154) = fVar7;
  *(undefined4 *)(this + 0x168) = 0x3f800000;
  *(float *)(this + 0x15c) = fVar9;
  *(float *)(this + 0x160) = fVar6;
  if (*(int *)(this + 4) == 0) {
    fVar11 = fVar8 + fVar7;
    fVar10 = -fVar11;
    if (0.0 < fVar11) {
      fVar10 = fVar11;
    }
    fVar11 = 10.0;
    if (fVar10 < 10.0) {
      fVar11 = fVar10;
    }
    fVar11 = *(float *)(this + 0x1c0) + fVar11;
    uVar4 = in_fpscr & 0xfffffff | (uint)(fVar11 < 100.0) << 0x1f | (uint)(fVar11 == 100.0) << 0x1e;
    bVar1 = (byte)(uVar4 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar11)) {
      fVar11 = 0.0;
    }
    *(float *)(this + 0x1c0) = fVar11;
    fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x13c),(byte)(uVar4 >> 0x16) & 3);
    *(int *)(this + 0x13c) = (int)(fVar8 + fVar10);
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x140),(byte)(uVar4 >> 0x16) & 3);
    *(int *)(this + 0x140) = (int)(fVar7 + fVar8);
    fVar9 = *(float *)(this + 0x144) - fVar9;
    fVar7 = -fVar9;
    if (0.0 < fVar9) {
      fVar7 = fVar9;
    }
    if (3.0 < fVar7) {
LAB_000db614:
      *(undefined4 *)(this + 0x60) = 0xffffffff;
      *(undefined4 *)(this + 0x19c) = 0xffffffff;
      *(undefined4 *)(this + 0x1d0) = 0;
    }
    else {
      fVar6 = *(float *)(this + 0x148) - fVar6;
      fVar7 = -fVar6;
      if (0.0 < fVar6) {
        fVar7 = fVar6;
      }
      if (3.0 < fVar7) goto LAB_000db614;
    }
    pPVar2 = Globals::Canvas;
    uVar4 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    puVar5 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar2,uVar4);
    pPVar2 = Globals::Canvas;
    local_60 = *puVar5;
    uStack_5c = puVar5[1];
    uStack_58 = puVar5[2];
    uStack_54 = puVar5[3];
    uStack_50 = puVar5[4];
    local_4c = puVar5[5];
    uStack_48 = puVar5[6];
    uStack_44 = puVar5[7];
    uStack_40 = puVar5[8];
    uStack_3c = puVar5[9];
    local_38 = puVar5[10];
    uStack_34 = puVar5[0xb];
    uStack_30 = puVar5[0xc];
    uStack_2c = puVar5[0xd];
    uStack_28 = puVar5[0xe];
    uVar4 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    AbyssEngine::PaintCanvas::CameraSetLocal(pPVar2,uVar4,(Matrix *)&local_60);
    goto LAB_000db328;
  }
  fVar9 = *(float *)(this + 0x144) - fVar9;
  fVar10 = -fVar9;
  if (0.0 < fVar9) {
    fVar10 = fVar9;
  }
  uVar4 = in_fpscr & 0xfffffff | (uint)(fVar10 < 3.0) << 0x1f | (uint)(fVar10 == 3.0) << 0x1e;
  bVar1 = (byte)(uVar4 >> 0x18);
  if ((bool)(bVar1 >> 6 & 1) || (bool)(bVar1 >> 7) != NAN(fVar10)) {
    fVar6 = *(float *)(this + 0x148) - fVar6;
    fVar9 = -fVar6;
    if (0.0 < fVar6) {
      fVar9 = fVar6;
    }
    uVar4 = in_fpscr & 0xfffffff | (uint)(fVar9 < 3.0) << 0x1f | (uint)(fVar9 == 3.0) << 0x1e;
    bVar1 = (byte)(uVar4 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar9)) goto LAB_000db426;
  }
  else {
LAB_000db426:
    *(undefined4 *)(this + 100) = 0xffffffff;
    *(undefined4 *)(this + 0x1a0) = 0xffffffff;
  }
  fVar10 = fVar8 * 50.0;
  fVar9 = fVar7 * -50.0;
  fVar6 = -(fVar8 * 50.0);
  if (0.0 < fVar10) {
    fVar6 = fVar10;
  }
  fVar7 = -(fVar7 * -50.0);
  if (0.0 < fVar9) {
    fVar7 = fVar9;
  }
  fVar8 = 0.0;
  if (150.0 < fVar6) {
    fVar8 = fVar10;
  }
  fVar6 = 0.0;
  if (150.0 < fVar7) {
    fVar6 = fVar9;
  }
  *(float *)(this + 0x150) = fVar10;
  *(float *)(this + 0x154) = fVar9;
  *(float *)(this + 0x16c) = fVar8;
  *(float *)(this + 0x170) = fVar6;
  fVar9 = fVar9 + *(float *)(this + 0x18c);
  fVar6 = -8192.0;
  if (-8192.0 < fVar9) {
    fVar6 = 8192.0;
  }
  if (8192.0 < fVar9) {
    fVar6 = 8192.0;
  }
  uVar4 = uVar4 & 0xfffffff | (uint)(fVar9 < 8192.0) << 0x1f | (uint)(fVar9 == 8192.0) << 0x1e;
  fVar7 = fVar9;
  if (fVar9 <= -8192.0) {
    fVar7 = fVar6;
  }
  bVar1 = (byte)(uVar4 >> 0x18);
  fVar8 = (float)VectorSignedToFloat((int)(fVar10 + *(float *)(this + 0x188)) % 0x10000,
                                     (byte)(uVar4 >> 0x16) & 3);
  if (!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar9)) {
    fVar7 = fVar6;
  }
  *(float *)(this + 0x188) = fVar8;
  *(float *)(this + 0x18c) = fVar9;
  *(float *)(this + 0x18c) = fVar7;
  AEGeometry::setRotation(*(AEGeometry **)(this + 0xa4),fVar8,extraout_s1,fVar9);
LAB_000db328:
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== StarMap::OnTouchEnd  @0x000db69c  (2928 bytes)
/* StarMap::OnTouchEnd(int, int) */

void __thiscall StarMap::OnTouchEnd(StarMap *this,int param_1,int param_2)

{
  PaintCanvas *this_00;
  Layout *pLVar1;
  int iVar2;
  Station *pSVar3;
  uint uVar4;
  String *pSVar5;
  SolarSystem *pSVar6;
  Mission *pMVar7;
  Ship *pSVar8;
  Matrix *pMVar9;
  int iVar10;
  int extraout_r2;
  ChoiceWindow *pCVar11;
  EaseInOut *pEVar12;
  String *pSVar13;
  bool bVar14;
  float fVar15;
  float fVar16;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float fVar17;
  float fVar18;
  undefined8 uVar19;
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  String aSStack_50 [8];
  AbyssEngine aAStack_48 [8];
  AbyssEngine aAStack_40 [8];
  AbyssEngine aAStack_38 [8];
  AbyssEngine aAStack_30 [12];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (this[0xa9] != (StarMap)0x0) {
    uVar19 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x5c),param_1,param_2);
    iVar10 = (int)((ulonglong)uVar19 >> 0x20);
    if ((int)uVar19 == 1) {
      this[0x120] = (StarMap)0x0;
      this[0xa9] = (StarMap)0x0;
      goto LAB_000dc1ce;
    }
    if ((int)uVar19 != 0) goto LAB_000dc1ce;
    this[0xa9] = (StarMap)0x0;
    if (this[0x1e4] == (StarMap)0x0) {
      if (*(int *)(this + 4) == 3) {
        iVar2 = Station::getIndex(*(Station **)
                                   (*(int *)(*(int *)(this + 0x58) + 4) + *(int *)(this + 100) * 4))
        ;
        pSVar3 = (Station *)Status::getStation(Globals::status);
        uVar19 = Station::getIndex(pSVar3);
        iVar10 = (int)((ulonglong)uVar19 >> 0x20);
        if (iVar2 == (int)uVar19) goto LAB_000db712;
      }
      if ((((this[0x120] == (StarMap)0x0) || (*(int *)(this + 4) != 0)) ||
          (this[0xa8] != (StarMap)0x0)) || (this[0x118] != (StarMap)0x0)) {
        uVar4 = *(uint *)(this + 0xa8);
        bVar14 = (uVar4 & 0xff) == 0;
        if (bVar14) {
          iVar10 = *(int *)(this + 4);
        }
        if (bVar14 && iVar10 == 3) {
          if ((uVar4 < 0x1000000) || (*(int *)(this + 0x1d0) <= *(int *)(this + 0x1d8))) {
            if ((uVar4 >> 0x10 & 0xff) == 0) {
              depart(this,true);
            }
            else {
              Level::programmedStation =
                   *(undefined4 *)(*(int *)(*(int *)(this + 0x58) + 4) + *(int *)(this + 100) * 4);
              if (uVar4 >> 0x18 == 0) {
                Level::doInstantJump = false;
              }
              else {
                iVar10 = Station::getSystem(*(Station **)
                                             (*(int *)(*(int *)(this + 0x58) + 4) +
                                             *(int *)(this + 100) * 4));
                pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
                iVar2 = SolarSystem::getIndex(pSVar6);
                Level::doInstantJump = iVar10 != iVar2;
                if ((bool)Level::doInstantJump) {
                  Level::energyCellsForNextJump = *(undefined4 *)(this + 0x1d0);
                }
              }
              *this = (StarMap)0x1;
              AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
            }
          }
          else if (*(int *)(this + 0x1d0) == 1) {
            if ((uVar4 >> 0x10 & 0xff) == 0) {
              depart(this,false);
            }
            else {
              Level::programmedStation =
                   *(undefined4 *)(*(int *)(*(int *)(this + 0x58) + 4) + *(int *)(this + 100) * 4);
              Level::doInstantJump = 0;
              *this = (StarMap)0x1;
              AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
            }
          }
        }
      }
      else {
        Level::programmedStation = *(undefined4 *)(Globals::status + 0x78);
        *this = (StarMap)0x1;
        this[0x120] = (StarMap)0x0;
        Level::doInstantJump = 1;
        Level::energyCellsForNextJump = *(undefined4 *)(this + 0x1d0);
        AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
      }
    }
    else {
LAB_000db712:
      this[0x1e4] = (StarMap)0x0;
    }
    goto LAB_000dc1ce;
  }
  if (((*(ushort *)(this + 0x138) & 0xff) != 0) || (0xff < *(ushort *)(this + 0x138)))
  goto LAB_000dc1ce;
  if ((*Globals::layout == (Layout)0x0) &&
     (iVar10 = Layout::OnTouchEnd(Globals::layout,param_1,param_2), iVar10 == 1)) {
    if ((*(int *)(this + 4) == 3) && (this[0xf4] != (StarMap)0x0)) {
      this[0x139] = (StarMap)0x1;
      *(undefined4 *)(this + 0x168) = 0;
      *(undefined4 *)(this + 0x16c) = 0;
      *(undefined4 *)(this + 0x170) = 0;
      pEVar12 = *(EaseInOut **)(this + 0x17c);
      AbyssEngine::EaseInOut::GetMaxValue(pEVar12);
      uVar19 = AbyssEngine::EaseInOut::GetMinValue(*(EaseInOut **)(this + 0x17c));
      AbyssEngine::EaseInOut::SetRange(pEVar12,(float)uVar19,(float)((ulonglong)uVar19 >> 0x20));
      pEVar12 = *(EaseInOut **)(this + 0x180);
      AbyssEngine::EaseInOut::GetMaxValue(pEVar12);
      uVar19 = AbyssEngine::EaseInOut::GetMinValue(*(EaseInOut **)(this + 0x180));
      AbyssEngine::EaseInOut::SetRange(pEVar12,(float)uVar19,(float)((ulonglong)uVar19 >> 0x20));
      pEVar12 = *(EaseInOut **)(this + 0x184);
      AbyssEngine::EaseInOut::GetMaxValue(pEVar12);
      uVar19 = AbyssEngine::EaseInOut::GetMinValue(*(EaseInOut **)(this + 0x184));
      fVar15 = (float)AbyssEngine::EaseInOut::SetRange
                                (pEVar12,(float)uVar19,(float)((ulonglong)uVar19 >> 0x20));
      FModSound::play(Globals::sound,0x6b,(Vector *)0x0,(Vector *)0x0,fVar15);
    }
    else {
      AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
      FModSound::stop(Globals::sound,0x66);
    }
    goto LAB_000dc1ce;
  }
  if ((this[0xa8] != (StarMap)0x0) && (this[0x13a] != (StarMap)0x0)) goto LAB_000dc1ce;
  iVar10 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x4c),param_1,param_2);
  if (iVar10 == 1) {
    this[0x108] = (StarMap)((byte)this[0x108] ^ 1);
  }
  if (this[0x174] != (StarMap)0x0) {
    fVar16 = *(float *)(this + 0x150);
    fVar18 = 0.0;
    fVar15 = -fVar16;
    if (0.0 < fVar16) {
      fVar15 = fVar16;
    }
    fVar17 = fVar18;
    if (3.0 < fVar15) {
      fVar17 = fVar16;
    }
    *(float *)(this + 0x16c) = fVar17;
    fVar16 = *(float *)(this + 0x154);
    fVar15 = -fVar16;
    if (0.0 < fVar16) {
      fVar15 = fVar16;
    }
    fVar17 = fVar18;
    if (3.0 < fVar15) {
      fVar17 = fVar16;
    }
    *(float *)(this + 0x170) = fVar17;
    *(undefined4 *)(this + 0x168) = 0x3f666666;
    this[0x174] = (StarMap)0x0;
    if (*(int *)(this + 4) == 0) {
      if (-1 < *(int *)(this + 0x60)) {
        if (this[0x118] == (StarMap)0x0) {
          bVar14 = (*(uint *)(this + 0xa8) & 0xff) == 0;
          iVar10 = extraout_r2;
          if (bVar14) {
            iVar10 = *(int *)(this + 0x19c);
          }
          if (bVar14 && iVar10 == *(int *)(this + 0x60)) {
            if (*(uint *)(this + 0xa8) >> 0x18 == 0) {
              pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
              iVar10 = SolarSystem::getIndex
                                 (*(SolarSystem **)
                                   (*(int *)(*(int *)(this + 0x54) + 4) + *(int *)(this + 0x60) * 4)
                                 );
              iVar10 = SolarSystem::systemIsInSystemRoutes(pSVar6,iVar10);
              if (iVar10 == 0) {
                iVar10 = 0x1a4;
                pSVar5 = *(String **)(this + 0x5c);
LAB_000dc088:
                bVar14 = (bool)GameText::getText(Globals::gameText,iVar10);
                ChoiceWindow::set(pSVar5,bVar14);
                this[0xa9] = (StarMap)0x1;
                goto LAB_000dc1ce;
              }
              fVar15 = extraout_s0;
              if (this[0xab] != (StarMap)0x0) goto LAB_000dbf6a;
            }
            else {
LAB_000dbf6a:
              pSVar8 = (Ship *)Status::getShip(Globals::status);
              iVar10 = Ship::hasVolatileGoods(pSVar8);
              fVar15 = extraout_s0_00;
              if (iVar10 == 1) {
                pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
                iVar10 = SolarSystem::getIndex
                                   (*(SolarSystem **)
                                     (*(int *)(*(int *)(this + 0x54) + 4) +
                                     *(int *)(this + 0x60) * 4));
                iVar10 = SolarSystem::systemIsInSystemRoutes(pSVar6,iVar10);
                fVar15 = extraout_s0_01;
                if (iVar10 == 0) {
                  iVar10 = 0x264;
                  pSVar5 = *(String **)(this + 0x5c);
                  goto LAB_000dc088;
                }
              }
            }
            FModSound::play(Globals::sound,0x6a,(Vector *)0x0,(Vector *)0x0,fVar15);
            initStarSystem(this);
            this[0x138] = (StarMap)0x1;
            AEGeometry::getPosition();
            AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)aAStack_30);
            *(float *)(this + 0x80) = *(float *)(this + 0x80) + -500.0;
            this_00 = Globals::Canvas;
            uVar4 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
            pMVar9 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar4);
            AbyssEngine::AEMath::MatrixGetPosition((AEMath *)aAStack_30,pMVar9);
            uVar19 = AbyssEngine::AEMath::Vector::operator=
                               ((Vector *)(this + 0x84),(Vector *)aAStack_30);
            uVar19 = AbyssEngine::EaseInOut::SetRange
                               (*(EaseInOut **)(this + 0x17c),(float)uVar19,
                                (float)((ulonglong)uVar19 >> 0x20));
            uVar19 = AbyssEngine::EaseInOut::SetRange
                               (*(EaseInOut **)(this + 0x180),(float)uVar19,
                                (float)((ulonglong)uVar19 >> 0x20));
            AbyssEngine::EaseInOut::SetRange
                      (*(EaseInOut **)(this + 0x184),(float)uVar19,
                       (float)((ulonglong)uVar19 >> 0x20));
            *(undefined4 *)(this + 0x168) = 0;
            *(undefined4 *)(this + 0x16c) = 0;
            *(undefined4 *)(this + 0x170) = 0;
            goto LAB_000dc1ce;
          }
        }
        this[0x13a] = (StarMap)0x1;
        *(undefined4 *)(this + 0x19c) = 0xffffffff;
      }
    }
    else {
      iVar10 = *(int *)(this + 100);
      if (-1 < iVar10) {
        if (*(int *)(this + 0x1a0) == iVar10) {
          if (this[0xa8] == (StarMap)0x0) {
            iVar10 = Station::getIndex(*(Station **)
                                        (*(int *)(*(int *)(this + 0x58) + 4) + iVar10 * 4));
            pSVar3 = (Station *)Status::getStation(Globals::status);
            iVar2 = Station::getIndex(pSVar3);
            pCVar11 = *(ChoiceWindow **)(this + 0x5c);
            if (iVar10 == iVar2) {
              if (pCVar11 == (ChoiceWindow *)0x0) {
                pCVar11 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar11);
                *(ChoiceWindow **)(this + 0x5c) = pCVar11;
              }
              iVar10 = 0x1a3;
LAB_000db984:
              pSVar5 = (String *)GameText::getText(Globals::gameText,iVar10);
              ChoiceWindow::set(pCVar11,pSVar5);
            }
            else {
              if (pCVar11 == (ChoiceWindow *)0x0) {
                pCVar11 = operator_new(0x54);
                ChoiceWindow::ChoiceWindow(pCVar11);
                *(ChoiceWindow **)(this + 0x5c) = pCVar11;
              }
              iVar10 = Status::getCurrentCampaignMission(Globals::status);
              if (iVar10 == 0x18) {
                iVar10 = Station::getIndex(*(Station **)
                                            (*(int *)(*(int *)(this + 0x58) + 4) +
                                            *(int *)(this + 100) * 4));
                pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                iVar2 = Mission::getTargetStation(pMVar7);
                if (iVar10 != iVar2) goto LAB_000dbb5a;
                pSVar8 = (Ship *)Status::getShip(Globals::status);
                iVar10 = Ship::getFirstEquipmentOfSort(pSVar8,0xd);
                if (iVar10 != 0) {
                  pSVar8 = (Ship *)Status::getShip(Globals::status);
                  iVar10 = Ship::getFirstEquipmentOfSort(pSVar8,0x11);
                  if (iVar10 != 0) goto LAB_000dbb5a;
                }
                iVar10 = 0x214;
                pCVar11 = *(ChoiceWindow **)(this + 0x5c);
              }
              else {
LAB_000dbb5a:
                iVar10 = Status::getCurrentCampaignMission(Globals::status);
                if (iVar10 == 0x87) {
                  iVar10 = Station::getIndex(*(Station **)
                                              (*(int *)(*(int *)(this + 0x58) + 4) +
                                              *(int *)(this + 100) * 4));
                  pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                  iVar2 = Mission::getTargetStation(pMVar7);
                  if (iVar10 == iVar2) {
                    pSVar8 = (Ship *)Status::getShip(Globals::status);
                    iVar10 = Ship::getFirstEquipmentOfSort(pSVar8,0x13);
                    if (iVar10 == 0) {
                      iVar10 = 0xc8d;
                      pCVar11 = *(ChoiceWindow **)(this + 0x5c);
                      goto LAB_000dc10e;
                    }
                  }
                }
                iVar10 = Status::getCurrentCampaignMission(Globals::status);
                if (iVar10 != 0x5b) {
LAB_000dbc08:
                  iVar10 = Status::getCurrentCampaignMission(Globals::status);
                  if (iVar10 == 0x5e) {
                    iVar10 = Station::getIndex(*(Station **)
                                                (*(int *)(*(int *)(this + 0x58) + 4) +
                                                *(int *)(this + 100) * 4));
                    pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                    iVar2 = Mission::getTargetStation(pMVar7);
                    if (iVar10 == iVar2) {
                      pSVar8 = (Ship *)Status::getShip(Globals::status);
                      iVar10 = Ship::getMaxPassengers(pSVar8);
                      if (iVar10 == 0) goto LAB_000dc0d4;
                    }
                  }
                  iVar10 = Status::getCurrentCampaignMission(Globals::status);
                  if (iVar10 == 0x69) {
                    iVar10 = Station::getIndex(*(Station **)
                                                (*(int *)(*(int *)(this + 0x58) + 4) +
                                                *(int *)(this + 100) * 4));
                    pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                    iVar2 = Mission::getTargetStation(pMVar7);
                    if (iVar10 != iVar2) goto LAB_000dbcae;
                    pSVar8 = (Ship *)Status::getShip(Globals::status);
                    iVar10 = Ship::hasEquipment(pSVar8,0xce,1);
                    if (iVar10 != 0) goto LAB_000dbcae;
                    pCVar11 = *(ChoiceWindow **)(this + 0x5c);
                    pSVar5 = (String *)GameText::getText(Globals::gameText,0xc91);
                    ChoiceWindow::set(pCVar11,pSVar5);
                    this[0x1e4] = (StarMap)0x1;
                    goto LAB_000dc122;
                  }
LAB_000dbcae:
                  iVar10 = Status::getCurrentCampaignMission(Globals::status);
                  if (iVar10 == 0x8b) {
                    iVar10 = Station::getIndex(*(Station **)
                                                (*(int *)(*(int *)(this + 0x58) + 4) +
                                                *(int *)(this + 100) * 4));
                    pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                    iVar2 = Mission::getTargetStation(pMVar7);
                    if (iVar10 == iVar2) {
                      pSVar8 = (Ship *)Status::getShip(Globals::status);
                      iVar10 = Ship::getIndex(pSVar8);
                      if (iVar10 != 0x2a) {
                        pSVar8 = (Ship *)Status::getShip(Globals::status);
                        iVar10 = Ship::getIndex(pSVar8);
                        if (*(int *)(&DAT_0025454c + iVar10 * 4) == 1) {
                          pSVar8 = (Ship *)Status::getShip(Globals::status);
                          iVar10 = Ship::hasEquipment(pSVar8,0xbe,1);
                          if (iVar10 != 0) goto LAB_000dbd3a;
                        }
                        iVar10 = 0xc8f;
                        pCVar11 = *(ChoiceWindow **)(this + 0x5c);
                        goto LAB_000dc10e;
                      }
                    }
                  }
LAB_000dbd3a:
                  iVar10 = Status::getCurrentCampaignMission(Globals::status);
                  if (iVar10 == 0x8e) {
                    iVar10 = Station::getIndex(*(Station **)
                                                (*(int *)(*(int *)(this + 0x58) + 4) +
                                                *(int *)(this + 100) * 4));
                    pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                    iVar2 = Mission::getTargetStation(pMVar7);
                    if (iVar10 == iVar2) {
                      pSVar8 = (Ship *)Status::getShip(Globals::status);
                      iVar10 = Ship::getFirstEquipmentOfSort(pSVar8,0x21);
                      if (iVar10 != 0) {
                        pSVar8 = (Ship *)Status::getShip(Globals::status);
                        iVar10 = Ship::hasEquipment(pSVar8,0xc5,0xf);
                        if (iVar10 == 1) {
                          pSVar8 = (Ship *)Status::getShip(Globals::status);
                          iVar10 = Ship::getFirstEquipmentOfSort(pSVar8,0x23);
                          if (iVar10 != 0) goto LAB_000dbdc2;
                        }
                      }
                      iVar10 = 0xc90;
                      pCVar11 = *(ChoiceWindow **)(this + 0x5c);
                      goto LAB_000dc10e;
                    }
                  }
LAB_000dbdc2:
                  iVar10 = Status::getCurrentCampaignMission(Globals::status);
                  if (iVar10 == 0x8e) {
                    iVar10 = Station::getIndex(*(Station **)
                                                (*(int *)(*(int *)(this + 0x58) + 4) +
                                                *(int *)(this + 100) * 4));
                    pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                    iVar2 = Mission::getTargetStation(pMVar7);
                    if (iVar10 == iVar2) {
                      pSVar8 = (Ship *)Status::getShip(Globals::status);
                      iVar10 = Ship::getFreeSpace(pSVar8);
                      if (iVar10 == 0) {
                        iVar10 = 0xc92;
                        pCVar11 = *(ChoiceWindow **)(this + 0x5c);
                        goto LAB_000dc10e;
                      }
                    }
                  }
                  if (this[0xab] != (StarMap)0x0) {
                    if (*(int *)(this + 0x1d8) < *(int *)(this + 0x1d0)) {
                      pSVar8 = (Ship *)Status::getShip(Globals::status);
                      iVar10 = Ship::hasVolatileGoods(pSVar8);
                      if (iVar10 != 0) {
                        if (this[0xab] == (StarMap)0x0) goto LAB_000dbe6e;
                        goto LAB_000dbe42;
                      }
                      pCVar11 = *(ChoiceWindow **)(this + 0x5c);
                      if (*(int *)(this + 0x1d0) != 1) {
                        iVar10 = 0x243;
                        goto LAB_000db984;
                      }
                      iVar10 = 0x246;
LAB_000dc202:
                      bVar14 = (bool)GameText::getText(Globals::gameText,iVar10);
                      ChoiceWindow::set(pCVar11,bVar14);
                      goto LAB_000dc122;
                    }
LAB_000dbe42:
                    if ((this[0x1d4] != (StarMap)0x0) &&
                       (*(int *)(this + 0x1d8) < *(int *)(this + 0x1d0) * 2)) {
                      pSVar8 = (Ship *)Status::getShip(Globals::status);
                      iVar10 = Ship::hasVolatileGoods(pSVar8);
                      if (iVar10 == 0) {
                        iVar10 = 0x245;
                        pCVar11 = *(ChoiceWindow **)(this + 0x5c);
                        goto LAB_000dc202;
                      }
                    }
                  }
LAB_000dbe6e:
                  pSVar13 = *(String **)(this + 0x5c);
                  pSVar5 = (String *)GameText::getText(Globals::gameText,0x23e);
                  AbyssEngine::String::String(aSStack_50,": ",false);
                  AbyssEngine::operator+(aAStack_48,pSVar5,aSStack_50);
                  Station::getName();
                  AbyssEngine::operator+(aAStack_40,aAStack_48,aSStack_58);
                  AbyssEngine::String::String(aSStack_60,"\n",false);
                  AbyssEngine::operator+(aAStack_38,aAStack_40,aSStack_60);
                  pSVar5 = (String *)GameText::getText(Globals::gameText,0x1a5);
                  AbyssEngine::operator+(aAStack_30,aAStack_38,pSVar5);
                  ChoiceWindow::set(pSVar13,(bool)((char)&stack0xffffffe8 + -0x18));
                  AbyssEngine::String::~String((String *)aAStack_30);
                  AbyssEngine::String::~String((String *)aAStack_38);
                  AbyssEngine::String::~String(aSStack_60);
                  AbyssEngine::String::~String((String *)aAStack_40);
                  AbyssEngine::String::~String(aSStack_58);
                  AbyssEngine::String::~String((String *)aAStack_48);
                  AbyssEngine::String::~String(aSStack_50);
                  goto LAB_000dc122;
                }
                iVar10 = Station::getIndex(*(Station **)
                                            (*(int *)(*(int *)(this + 0x58) + 4) +
                                            *(int *)(this + 100) * 4));
                pMVar7 = (Mission *)Status::getCampaignMission(Globals::status);
                iVar2 = Mission::getTargetStation(pMVar7);
                if (iVar10 != iVar2) goto LAB_000dbc08;
                pSVar8 = (Ship *)Status::getShip(Globals::status);
                iVar10 = Ship::getMaxPassengers(pSVar8);
                if (9 < iVar10) goto LAB_000dbc08;
LAB_000dc0d4:
                iVar10 = 0xc8e;
                pCVar11 = *(ChoiceWindow **)(this + 0x5c);
              }
LAB_000dc10e:
              pSVar5 = (String *)GameText::getText(Globals::gameText,iVar10);
              ChoiceWindow::set(pCVar11,pSVar5);
              this[0x1e4] = (StarMap)0x1;
            }
LAB_000dc122:
            this[0xa9] = (StarMap)0x1;
          }
        }
        else {
          FModSound::play(Globals::sound,0x69,(Vector *)0x0,(Vector *)0x0,fVar16);
          this[0x13b] = (StarMap)0x1;
        }
      }
      fVar16 = *(float *)(this + 0x150);
      fVar15 = -fVar16;
      if (0.0 < fVar16) {
        fVar15 = fVar16;
      }
      fVar17 = fVar18;
      if (150.0 < fVar15) {
        fVar17 = fVar16;
      }
      *(float *)(this + 0x16c) = fVar17;
      fVar16 = *(float *)(this + 0x154);
      fVar15 = -fVar16;
      if (0.0 < fVar16) {
        fVar15 = fVar16;
      }
      if (150.0 < fVar15) {
        fVar18 = fVar16;
      }
      *(float *)(this + 0x170) = fVar18;
    }
  }
  iVar10 = Layout::helpPressed(Globals::layout);
  pLVar1 = Globals::layout;
  if (iVar10 == 1) {
    iVar10 = 0x277;
    if (*(int *)(this + 4) == 0) {
      iVar10 = 0x274;
    }
    pSVar5 = (String *)GameText::getText(Globals::gameText,iVar10);
    AbyssEngine::String::String(aSStack_68,pSVar5,false);
    Layout::initHelpWindow(pLVar1,aSStack_68);
    AbyssEngine::String::~String(aSStack_68);
  }
LAB_000dc1ce:
  if (__stack_chk_guard - local_24 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_24);
  }
  return;
}

