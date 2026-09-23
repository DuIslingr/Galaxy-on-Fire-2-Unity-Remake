// Class: SpaceLounge
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== SpaceLounge::SpaceLounge  @0x00197890  (1166 bytes)
/* SpaceLounge::SpaceLounge() */

void __thiscall SpaceLounge::SpaceLounge(SpaceLounge *this)

{
  PaintCanvas *pPVar1;
  uint *puVar2;
  int iVar3;
  Mission *this_00;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  SolarSystem *this_01;
  EaseInOutMatrix *pEVar8;
  Agent *this_02;
  uint uVar9;
  CutScene *this_03;
  int iVar10;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float fVar11;
  float extraout_s2;
  float extraout_s2_00;
  undefined4 uVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  Matrix aMStack_1a4 [60];
  AEMath aAStack_168 [60];
  AEMath aAStack_12c [60];
  AEMath aAStack_f0 [8];
  float local_e8;
  float local_e4 [3];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  float local_58 [2];
  float local_50;
  int local_4c;
  
  uVar12 = 0;
  uVar14 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar15 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar16 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_4c = __stack_chk_guard;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = uVar14;
  *(undefined4 *)(this + 0x94) = uVar15;
  *(undefined4 *)(this + 0x98) = uVar16;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  AbyssEngine::String::String((String *)(this + 0xa4));
  *(undefined4 *)(this + 0xc4) = 0x3f800000;
  *(undefined4 *)(this + 200) = uVar12;
  *(undefined4 *)(this + 0xcc) = uVar14;
  *(undefined4 *)(this + 0xd0) = uVar15;
  *(undefined4 *)(this + 0xd4) = uVar16;
  *(undefined4 *)(this + 0xd8) = 0x3f800000;
  *(undefined4 *)(this + 0xdc) = uVar12;
  *(undefined4 *)(this + 0xe0) = uVar14;
  *(undefined4 *)(this + 0xe4) = uVar15;
  *(undefined4 *)(this + 0xe8) = uVar16;
  *(undefined8 *)(this + 0xec) = 0x3f800000;
  *(undefined8 *)(this + 0xf4) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xfc) = 0x3f800000;
  this[0xac] = (SpaceLounge)0x0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  this[0x35] = (SpaceLounge)0x0;
  this[0x34] = (SpaceLounge)0x0;
  this[0x36] = (SpaceLounge)0x0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x1c] = (SpaceLounge)0x0;
  *(undefined4 *)(this + 0x20) = uVar12;
  *(undefined4 *)(this + 0x24) = uVar14;
  *(undefined4 *)(this + 0x28) = uVar15;
  *(undefined4 *)(this + 0x2c) = uVar16;
  *(undefined4 *)(this + 0x38) = uVar12;
  *(undefined4 *)(this + 0x3c) = uVar14;
  *(undefined4 *)(this + 0x40) = uVar15;
  *(undefined4 *)(this + 0x44) = uVar16;
  *(undefined4 *)(this + 0x48) = 0;
  init(this);
  puVar2 = *(uint **)(this + 0x24);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar9 = 0;
    do {
      this_02 = *(Agent **)(puVar2[1] + uVar9 * 4);
      iVar3 = Agent::getOffer(this_02);
      if (((iVar3 == 6) || (iVar3 = Agent::getOffer(this_02), iVar3 == 0)) &&
         (iVar3 = Agent::getMission(this_02), iVar3 != 0)) {
        this_00 = (Mission *)Agent::getMission(this_02);
        iVar3 = Mission::getType(this_00);
        if ((iVar3 == 0xc) && (iVar3 = Agent::hasAcceptedOffer(this_02), iVar3 != 0)) {
          if (-1 < (int)uVar9) {
            ArrayRemove<Agent*>(*(Agent **)(*(int *)(*(Array **)(this + 0x24) + 4) + uVar9 * 4),
                                *(Array **)(this + 0x24));
            init(this);
          }
          break;
        }
      }
      puVar2 = *(uint **)(this + 0x24);
      uVar9 = uVar9 + 1;
    } while (uVar9 < *puVar2);
  }
  this_03 = *(CutScene **)(this + 0x44);
  if (this_03 == (CutScene *)0x0) {
    this_03 = operator_new(0xa0);
    CutScene::CutScene(this_03,4);
    *(CutScene **)(this + 0x44) = this_03;
  }
  while( true ) {
    iVar3 = CutScene::isInitialized(this_03);
    if (iVar3 != 0) break;
    CutScene::initialize(*(CutScene **)(this + 0x44));
    this_03 = *(CutScene **)(this + 0x44);
  }
  iVar4 = Level::getEnemies(*(Level **)*(CutScene **)(this + 0x44));
  piVar5 = *(int **)(this + 0x24);
  iVar3 = 0;
  if (piVar5 != (int *)0x0) {
    iVar3 = *piVar5;
  }
  if (piVar5 != (int *)0x0 && iVar3 != 0) {
    fVar13 = -100.0;
    uVar9 = 0;
    do {
      (**(code **)(**(int **)(*(int *)(iVar4 + 4) + uVar9 * 4) + 0x28))((Vector *)local_58);
      pPVar1 = Globals::Canvas;
      uVar6 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      puVar7 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar6);
      local_98 = *puVar7;
      local_94 = puVar7[1];
      local_90 = puVar7[2];
      local_8c = puVar7[3];
      local_88 = puVar7[4];
      local_84 = puVar7[5];
      local_80 = puVar7[6];
      uStack_7c = puVar7[7];
      local_78 = puVar7[8];
      local_74 = puVar7[9];
      local_70 = *(undefined8 *)(puVar7 + 10);
      local_68 = *(undefined8 *)(puVar7 + 0xc);
      local_60 = puVar7[0xe];
      AbyssEngine::AEMath::MatrixGetPosition(aAStack_12c,(Matrix *)&local_98);
      AbyssEngine::AEMath::MatrixGetUp(aAStack_168,(Matrix *)&local_98);
      AbyssEngine::AEMath::MatrixGetLookAt
                ((AEMath *)&local_d8,(Vector *)aAStack_12c,(Vector *)local_58,(Vector *)aAStack_168)
      ;
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_98,(AEMath *)&local_d8);
      AEGeometry::setMatrix(*(Matrix **)(*(int *)(*(int *)(iVar4 + 4) + uVar9 * 4) + 8));
      piVar5 = *(int **)(*(int *)(iVar4 + 4) + uVar9 * 4);
      (**(code **)(*piVar5 + 0x44))(piVar5,(Vector *)local_58);
      AEGeometry::setMatrix
                (*(Matrix **)
                  (*(int *)(*(int *)(iVar4 + 4) + (**(int **)(this + 0x24) + uVar9) * 4) + 8));
      AbyssEngine::AEMath::MatrixGetDir((AEMath *)local_e4,(Matrix *)&local_98);
      local_58[0] = local_58[0] + local_e4[0] * fVar13;
      AbyssEngine::AEMath::MatrixGetDir(aAStack_f0,(Matrix *)&local_98);
      local_50 = local_50 + local_e8 * fVar13;
      piVar5 = *(int **)(*(int *)(iVar4 + 4) + (**(int **)(this + 0x24) + uVar9) * 4);
      (**(code **)(*piVar5 + 0x44))(piVar5,(Vector *)local_58);
      uVar9 = uVar9 + 1;
    } while (uVar9 < **(uint **)(this + 0x24));
  }
  uStack_7c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_78 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  local_74 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar7 = (undefined4 *)((uint)&local_98 | 4);
  local_98 = 0x3f800000;
  *puVar7 = 0;
  puVar7[1] = uStack_7c;
  puVar7[2] = local_78;
  puVar7[3] = local_74;
  local_84 = 0x3f800000;
  local_80 = 0;
  local_70 = 0x3f800000;
  local_68 = 0x3f8000003f800000;
  local_60 = 0x3f800000;
  this_01 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar3 = SolarSystem::getRace(this_01);
  iVar4 = iVar3 * 3 + 1;
  iVar10 = iVar3 * 3 + 2;
  VectorSignedToFloat(*(undefined4 *)(&DAT_0025ce84 + iVar3 * 0xc),(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_0025ce84 + iVar4 * 4),
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar13 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_0025ce84 + iVar10 * 4),
                                      (byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::MatrixSetTranslation
            ((AEMath *)&local_d8,(Matrix *)&local_98,fVar13,extraout_s1,fVar11);
  AbyssEngine::AEMath::MatrixSetRotation(aAStack_12c,extraout_s0,extraout_s1_00,extraout_s2);
  uStack_bc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_b8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_b4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar7 = (undefined4 *)((uint)&local_d8 | 4);
  VectorSignedToFloat(*(undefined4 *)(&DAT_0025ceb4 + iVar3 * 0xc),(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_0025ceb4 + iVar4 * 4),
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_d8 = 0x3f800000;
  *puVar7 = 0;
  puVar7[1] = uStack_bc;
  puVar7[2] = local_b8;
  puVar7[3] = uStack_b4;
  local_c4 = 0x3f800000;
  local_c0 = 0;
  fVar13 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_0025ceb4 + iVar10 * 4),
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_b0 = 0x3f800000;
  local_a8 = 0x3f8000003f800000;
  local_a0 = 0x3f800000;
  AbyssEngine::AEMath::MatrixSetTranslation
            (aAStack_168,(AEMath *)&local_d8,fVar13,extraout_s1_01,fVar11);
  AbyssEngine::AEMath::MatrixSetRotation(aMStack_1a4,extraout_s0_00,extraout_s1_02,extraout_s2_00);
  pEVar8 = operator_new(0xf4);
  AbyssEngine::EaseInOutMatrix::EaseInOutMatrix
            (pEVar8,local_98,local_94,local_90,local_8c,local_88,local_84,local_80,uStack_7c,
             local_78,local_74,(undefined4)local_70,local_70._4_4_,(undefined4)local_68,
             local_68._4_4_,local_60,local_d8,local_d4,local_d0,local_cc,local_c8,local_c4,local_c0,
             uStack_bc,local_b8,uStack_b4,(undefined4)local_b0,local_b0._4_4_,(undefined4)local_a8,
             local_a8._4_4_,local_a0,3000);
  *(EaseInOutMatrix **)(this + 0x48) = pEVar8;
  pPVar1 = Globals::Canvas;
  uVar9 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  AbyssEngine::PaintCanvas::CameraSetLocal(pPVar1,uVar9,(Matrix *)&local_98);
  this[0xb9] = (SpaceLounge)0x0;
  this[0xac] = (SpaceLounge)0x1;
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== SpaceLounge::init  @0x00197da0  (2282 bytes)
/* SpaceLounge::init() */

void __thiscall SpaceLounge::init(SpaceLounge *this)

{
  bool bVar1;
  byte bVar2;
  PaintCanvas *this_00;
  ImageFactory *this_01;
  SpaceLounge SVar3;
  Station *pSVar4;
  uint *puVar5;
  Array *pAVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  void *pvVar11;
  ChoiceWindow *this_02;
  ScrollTouchWindow *pSVar12;
  TouchButton *pTVar13;
  String *pSVar14;
  SolarSystem *this_03;
  StarSystem *this_04;
  Engine *pEVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  Agent *this_05;
  int iVar20;
  int iVar21;
  uint in_fpscr;
  uint uVar22;
  float fVar23;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar24;
  float extraout_s2;
  float extraout_s2_00;
  float fVar25;
  float fVar26;
  AEMath aAStack_a4 [60];
  undefined4 local_68 [5];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  this[0xac] = (SpaceLounge)0x0;
  this[0xae] = (SpaceLounge)0x0;
  this[0xb8] = (SpaceLounge)0x0;
  pSVar4 = (Station *)Status::getStation(Globals::status);
  puVar5 = (uint *)Station::getAgents(pSVar4);
  *(uint **)(this + 0x24) = puVar5;
  if (((*(int *)(this + 0x38) == 0) && (puVar5 != (uint *)0x0)) && (*(int *)(this + 0x40) == 0)) {
    pAVar6 = operator_new(0xc);
    puVar7 = operator_new__(4);
    *(undefined4 **)(pAVar6 + 4) = puVar7;
    *(undefined4 *)(pAVar6 + 8) = 1;
    *puVar7 = 0;
    *(undefined4 *)pAVar6 = 0;
    *(Array **)(this + 0x38) = pAVar6;
    ArraySetLength<Array<ImagePart*>*>(*puVar5,pAVar6);
    pAVar6 = operator_new(0xc);
    puVar7 = operator_new__(4);
    *(undefined4 **)(pAVar6 + 4) = puVar7;
    *(undefined4 *)(pAVar6 + 8) = 1;
    *puVar7 = 0;
    *(undefined4 *)pAVar6 = 0;
    *(Array **)(this + 0x40) = pAVar6;
    ArraySetLength<AbyssEngine::AEMath::Vector*>(**(int **)(this + 0x24) << 1,pAVar6);
    puVar5 = *(uint **)(this + 0x24);
    if (*puVar5 != 0) {
      uVar18 = 0;
      do {
        this_01 = Globals::imageFactory;
        piVar8 = (int *)Agent::getImageParts(*(Agent **)(puVar5[1] + uVar18 * 4));
        uVar9 = ImageFactory::loadChar(this_01,piVar8);
        *(undefined4 *)(*(int *)(*(int *)(this + 0x38) + 4) + uVar18 * 4) = uVar9;
        puVar7 = operator_new(0xc);
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        *(undefined4 **)(*(int *)(*(int *)(this + 0x40) + 4) + uVar18 * 4) = puVar7;
        puVar7 = operator_new(0xc);
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        iVar16 = **(int **)(this + 0x24) + uVar18;
        uVar18 = uVar18 + 1;
        *(undefined4 **)(*(int *)(*(int *)(this + 0x40) + 4) + iVar16 * 4) = puVar7;
        puVar5 = *(uint **)(this + 0x24);
      } while (uVar18 < *puVar5);
    }
    puVar7 = operator_new(0xc);
    puVar10 = operator_new__(4);
    puVar7[1] = puVar10;
    puVar7[2] = 1;
    *puVar10 = 0;
    *puVar7 = 0;
    *(undefined4 **)(this + 0x3c) = puVar7;
    uVar9 = ImageFactory::loadChar(Globals::imageFactory,(int *)&DAT_0026d3d0);
    *(undefined4 *)(this + 0x3c) = uVar9;
  }
  if (*(ChoiceWindow **)(this + 8) != (ChoiceWindow *)0x0) {
    pvVar11 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 8));
    operator_delete(pvVar11);
    *(undefined4 *)(this + 8) = 0;
  }
  this_02 = operator_new(0x54);
  ChoiceWindow::ChoiceWindow(this_02);
  *(ChoiceWindow **)(this + 8) = this_02;
  this[0x35] = (SpaceLounge)0x0;
  if (*(CutScene **)(this + 0x44) != (CutScene *)0x0) {
    CutScene::resetCamera(*(CutScene **)(this + 0x44));
  }
  this[0x18] = (SpaceLounge)0x0;
  puVar7 = operator_new__(0x15);
  *(undefined4 **)(this + 0x58) = puVar7;
  *puVar7 = 0;
  puVar7[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  puVar7[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  puVar7[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)((int)puVar7 + 0x11) = 0;
  iVar16 = Globals::layout;
  *(undefined4 *)((int)puVar7 + 0xd) = 0;
  iVar17 = *(int *)(iVar16 + 0x68);
  iVar21 = Globals::w / 2 - iVar17 / 2;
  *(int *)(this + 0x70) = iVar21;
  iVar20 = *(int *)(iVar16 + 0x20) + *(int *)(iVar16 + 0xc);
  *(int *)(this + 0x74) = iVar20;
  iVar17 = (*(int *)(iVar16 + 0x4c) * -3 + iVar17) - *(int *)(iVar16 + 0x2d4);
  *(int *)(this + 0x6c) = iVar17;
  pSVar12 = operator_new(0x20);
  ScrollTouchWindow::ScrollTouchWindow
            (pSVar12,iVar21 + *(int *)(iVar16 + 0x4c) * 2 + *(int *)(iVar16 + 0x2d4),iVar20,iVar17,
             *(int *)(iVar16 + 0x6c),false);
  *(ScrollTouchWindow **)(this + 0x60) = pSVar12;
  iVar16 = Globals::layout;
  *(int *)(this + 0x78) =
       *(int *)(this + 0x74) + *(int *)(Globals::layout + 0x6c) + *(int *)(Globals::layout + 0x2c);
  *(undefined4 *)(this + 0x14) = 0;
  *(int *)(this + 100) = (*(int *)(iVar16 + 0x34) + *(int *)(iVar16 + 0x30)) * 5;
  if (*(Array **)(this + 0x5c) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x5c));
    pvVar11 = *(void **)(this + 0x5c);
    if (pvVar11 != (void *)0x0) {
      if (*(void **)((int)pvVar11 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar11 + 4));
      }
      operator_delete(pvVar11);
    }
  }
  *(undefined4 *)(this + 0x5c) = 0;
  pAVar6 = operator_new(0xc);
  puVar7 = operator_new__(4);
  *(undefined4 **)(pAVar6 + 4) = puVar7;
  *(undefined4 *)(pAVar6 + 8) = 1;
  *puVar7 = 0;
  *(undefined4 *)pAVar6 = 0;
  *(Array **)(this + 0x5c) = pAVar6;
  ArraySetLength<TouchButton*>(5,pAVar6);
  iVar16 = Globals::layout;
  iVar20 = *(int *)(Globals::layout + 0x4c);
  *(int *)(this + 0x84) =
       ((*(int *)(this + 0x70) + *(int *)(Globals::layout + 0x68)) - iVar20) - *(int *)(this + 0x6c)
  ;
  iVar17 = *(int *)(iVar16 + 0x30);
  iVar21 = *(int *)(this + 0x78);
  iVar16 = *(int *)(iVar16 + 0x34);
  pTVar13 = operator_new(0xc0);
  pSVar14 = (String *)GameText::getText(Globals::gameText,0x35c);
  iVar20 = iVar20 + iVar21;
  TouchButton::TouchButton
            (pTVar13,pSVar14,0,*(int *)(this + 0x84),iVar20,
             *(int *)(this + 0x6c) / 2 - *(int *)(Globals::layout + 0x4c) / 2,'\x11','\x04');
  **(undefined4 **)(*(int *)(this + 0x5c) + 4) = pTVar13;
  TouchButton::setTextColor((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),0xed00ff);
  pTVar13 = operator_new(0xc0);
  pSVar14 = (String *)GameText::getText(Globals::gameText,0x35d);
  TouchButton::TouchButton
            (pTVar13,pSVar14,0,
             (*(int *)(Globals::layout + 0x68) + *(int *)(this + 0x70)) -
             *(int *)(Globals::layout + 0x4c),iVar20,
             *(int *)(this + 0x6c) / 2 - *(int *)(Globals::layout + 0x4c),'\x12','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 4) = pTVar13;
  TouchButton::setTextColor(*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 4),-0xd5ff01);
  pTVar13 = operator_new(0xc0);
  pSVar14 = (String *)GameText::getText(Globals::gameText,0x308);
  iVar16 = iVar17 + iVar20 + iVar16;
  TouchButton::TouchButton
            (pTVar13,pSVar14,0,*(int *)(this + 0x84),iVar16,*(int *)(this + 0x6c),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 8) = pTVar13;
  pTVar13 = operator_new(0xc0);
  pSVar14 = (String *)GameText::getText(Globals::gameText,0x324);
  TouchButton::TouchButton
            (pTVar13,pSVar14,0,*(int *)(this + 0x84),iVar16,*(int *)(this + 0x6c),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0xc) = pTVar13;
  pTVar13 = operator_new(0xc0);
  pSVar14 = (String *)GameText::getText(Globals::gameText,0x327);
  TouchButton::TouchButton
            (pTVar13,pSVar14,0,*(int *)(this + 0x84),
             *(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30) + iVar16,
             *(int *)(this + 0x6c),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0x10) = pTVar13;
  iVar17 = *(int *)(Globals::layout + 0x2d8);
  iVar16 = *(int *)(Globals::layout + 0x30);
  *(undefined4 *)(this + 0x88) = 0xffffffff;
  *(int *)(this + 0x7c) = (iVar20 + iVar17 / 2) - iVar16 / 2;
  *(int *)(this + 0x80) = iVar20;
  this_03 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar16 = SolarSystem::getRace(this_03);
  uStack_4c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  local_48 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  iVar16 = iVar16 * 0xc;
  puVar7 = (undefined4 *)((uint)local_68 | 4);
  VectorSignedToFloat(*(undefined4 *)(&DAT_0025ceb4 + iVar16),(byte)(in_fpscr >> 0x16) & 3);
  uVar9 = *(undefined4 *)(&DAT_0025cebc + iVar16);
  fVar24 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_0025ceb8 + iVar16),
                                      (byte)(in_fpscr >> 0x16) & 3);
  local_68[0] = 0x3f800000;
  *puVar7 = 0;
  puVar7[1] = uStack_4c;
  puVar7[2] = local_48;
  puVar7[3] = uStack_44;
  local_54 = 0x3f800000;
  local_50 = 0;
  fVar23 = (float)VectorSignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
  local_40 = 0x3f800000;
  local_38 = 0x3f8000003f800000;
  local_30 = 0x3f800000;
  AbyssEngine::AEMath::MatrixSetTranslation(aAStack_a4,(Matrix *)local_68,fVar23,extraout_s1,fVar24)
  ;
  AbyssEngine::AEMath::MatrixSetRotation(aAStack_a4,extraout_s0,extraout_s1_00,extraout_s2);
  this_00 = Globals::Canvas;
  uVar18 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  AbyssEngine::PaintCanvas::CameraSetLocal(this_00,uVar18,(Matrix *)local_68);
  if (*(int *)(this + 0x48) != 0) {
    AbyssEngine::EaseInOutMatrix::SetRange(*(int *)(this + 0x48));
  }
  *(undefined4 *)(this + 0x100) = 0;
  this[0xb9] = (SpaceLounge)0x1;
  if (*(undefined4 **)(this + 0x44) != (undefined4 *)0x0) {
    this_04 = (StarSystem *)Level::getStarSystem((Level *)**(undefined4 **)(this + 0x44));
    StarSystem::initLight(this_04);
  }
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorSpecular
            (pEVar15,extraout_s0_00,extraout_s1_01,extraout_s2_00,0x3f000000);
  iVar16 = Globals::layout;
  if (Globals::iPad != '\0') {
    if (Globals::iPadHD == '\0') {
      fVar23 = 10.0;
      if (Globals::iPadLarge != '\0') {
        fVar23 = 20.0;
      }
    }
    else {
      fVar23 = 14.0;
    }
    puVar5 = *(uint **)(this + 0x40);
    if (((puVar5 != (uint *)0x0) && (iVar17 = *(int *)(this + 0x20), -1 < iVar17)) &&
       ((uint)(iVar17 << 1) < *puVar5)) {
      fVar24 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x68),
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar25 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x28),
                                          (byte)(in_fpscr >> 0x16) & 3);
      in_fpscr = in_fpscr & 0xfffffff;
      if (fVar25 <= (**(float **)(puVar5[1] + iVar17 * 8) - fVar23) - fVar24) {
        fVar24 = (*(float *)(this + 0x8c) - fVar23) - fVar24;
        bVar1 = NAN(fVar25) || NAN(fVar24);
        uVar18 = in_fpscr | (uint)(fVar25 < fVar24) << 0x1f | (uint)(fVar25 == fVar24) << 0x1e;
      }
      else {
        fVar25 = fVar23 + *(float *)(this + 0x98);
        fVar24 = (float)VectorSignedToFloat(Globals::w - *(int *)(Globals::layout + 0x28),
                                            (byte)(in_fpscr >> 0x16) & 3);
        bVar1 = NAN(fVar24) || NAN(fVar25);
        uVar18 = in_fpscr | (uint)(fVar24 < fVar25) << 0x1f | (uint)(fVar24 == fVar25) << 0x1e;
      }
      bVar2 = (byte)(uVar18 >> 0x18);
      if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == bVar1) {
        fVar24 = fVar25;
      }
      *(int *)(this + 0x70) = (int)fVar24;
      fVar25 = (float)VectorSignedToFloat(*(int *)(iVar16 + 0x6c) / 3,(byte)(uVar18 >> 0x16) & 3);
      fVar23 = (float)VectorSignedToFloat(((Globals::h - *(int *)(iVar16 + 0x10)) -
                                          *(int *)(iVar16 + 0x24)) - *(int *)(iVar16 + 0x6c),
                                          (byte)(uVar18 >> 0x16) & 3);
      fVar26 = (float)VectorSignedToFloat(*(int *)(iVar16 + 0x20) + *(int *)(iVar16 + 0xc),
                                          (byte)(uVar18 >> 0x16) & 3);
      if (*(float *)(this + 0x9c) - fVar25 < fVar23) {
        fVar23 = *(float *)(this + 0x9c) - fVar25;
      }
      uVar18 = uVar18 & 0xfffffff | (uint)(fVar26 < fVar23) << 0x1f |
               (uint)(fVar26 == fVar23) << 0x1e;
      uVar22 = uVar18 | (uint)(NAN(fVar26) || NAN(fVar23)) << 0x1c;
      bVar2 = (byte)(uVar18 >> 0x18);
      if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar22 >> 0x1c) & 1)) {
        fVar23 = fVar26;
      }
      iVar20 = (int)fVar24;
      iVar17 = (int)fVar23;
      *(int *)(this + 0x74) = (int)fVar23;
      if (*(ScrollTouchWindow **)(this + 0x60) != (ScrollTouchWindow *)0x0) {
        pvVar11 = (void *)ScrollTouchWindow::~ScrollTouchWindow
                                    (*(ScrollTouchWindow **)(this + 0x60));
        operator_delete(pvVar11);
        iVar20 = *(int *)(this + 0x70);
        iVar17 = *(int *)(this + 0x74);
        iVar16 = Globals::layout;
      }
      *(undefined4 *)(this + 0x60) = 0;
      pSVar12 = operator_new(0x20);
      ScrollTouchWindow::ScrollTouchWindow
                (pSVar12,iVar20 + *(int *)(iVar16 + 0x4c) * 2 + *(int *)(iVar16 + 0x2d4),iVar17,
                 *(int *)(this + 0x6c),*(int *)(iVar16 + 0x6c),false);
      *(ScrollTouchWindow **)(this + 0x60) = pSVar12;
      iVar16 = Globals::layout;
      iVar17 = *(int *)(this + 0x74) + *(int *)(Globals::layout + 0x6c) +
               *(int *)(Globals::layout + 0x2c);
      *(int *)(this + 0x78) = iVar17;
      iVar21 = *(int *)(iVar16 + 0x4c);
      iVar20 = ((*(int *)(this + 0x70) + *(int *)(iVar16 + 0x68)) - iVar21) - *(int *)(this + 0x6c);
      *(int *)(this + 0x84) = iVar20;
      fVar23 = (float)VectorSignedToFloat(*(undefined4 *)(iVar16 + 0x34),(byte)(uVar22 >> 0x16) & 3)
      ;
      if (Globals::iPadHD == '\0') {
        fVar24 = 11.0;
        if (Globals::iPadLarge != '\0') {
          fVar24 = 22.0;
        }
      }
      else {
        fVar24 = 15.46875;
      }
      iVar19 = *(int *)(iVar16 + 0x30);
      *(int *)(this + 0x7c) = ((iVar21 + iVar17) - iVar19 / 2) + *(int *)(iVar16 + 0x2d8) / 2;
      *(int *)(this + 0x80) = iVar21 + iVar17;
      iVar19 = iVar19 + iVar21 + iVar17 + (int)(fVar23 + fVar24);
      TouchButton::setPosition
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 8),iVar20,iVar19);
      TouchButton::setPosition
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0xc),*(int *)(this + 0x84),
                 iVar19);
      TouchButton::setPosition
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0x10),*(int *)(this + 0x84)
                 ,iVar19 + (int)(fVar23 + fVar24) + *(int *)(Globals::layout + 0x30));
    }
  }
  pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  SVar3 = (SpaceLounge)AbyssEngine::Engine::IsPostEffectActivated(pEVar15);
  this[0xad] = SVar3;
  iVar16 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar16 == 0x18) {
    pSVar4 = (Station *)Status::getStation(Globals::status);
    iVar16 = Station::getIndex(pSVar4);
    if ((iVar16 == 10) && (puVar5 = *(uint **)(this + 0x24), *puVar5 != 0)) {
      uVar18 = 0;
      do {
        this_05 = *(Agent **)(puVar5[1] + uVar18 * 4);
        iVar16 = Agent::getOffer(this_05);
        if (((iVar16 == 2) && (iVar16 = Agent::getSellItemIndex(this_05), iVar16 == 0x44)) &&
           (iVar16 = Agent::isKnown(this_05), iVar16 == 0)) {
          *(uint *)(this + 0x20) = uVar18;
          startChat(this);
          break;
        }
        puVar5 = *(uint **)(this + 0x24);
        uVar18 = uVar18 + 1;
      } while (uVar18 < *puVar5);
    }
  }
  this[0xac] = (SpaceLounge)0x1;
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== SpaceLounge::introFinished  @0x001987b2  (6 bytes)
/* SpaceLounge::introFinished() */

SpaceLounge __thiscall SpaceLounge::introFinished(SpaceLounge *this)

{
  return this[0xb9];
}

// ===== SpaceLounge::~SpaceLounge  @0x001987b8  (314 bytes)
/* SpaceLounge::~SpaceLounge() */

SpaceLounge * __thiscall SpaceLounge::~SpaceLounge(SpaceLounge *this)

{
  void *pvVar1;
  Array *pAVar2;
  int iVar3;
  uint uVar4;
  
  if (*(ChoiceWindow **)(this + 8) != (ChoiceWindow *)0x0) {
    pvVar1 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(CutScene **)(this + 0x44) != (CutScene *)0x0) {
    pvVar1 = (void *)CutScene::~CutScene(*(CutScene **)(this + 0x44));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x44) = 0;
  if (*(void **)(this + 0x58) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  if (*(Array **)(this + 0x28) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x28));
    pvVar1 = *(void **)(this + 0x28);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(Array **)(this + 0x5c) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x5c));
    pvVar1 = *(void **)(this + 0x5c);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x5c) = 0;
  if (*(Array **)(this + 0x3c) != (Array *)0x0) {
    ArrayReleaseClasses<ImagePart*>(*(Array **)(this + 0x3c));
    pvVar1 = *(void **)(this + 0x3c);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x3c) = 0;
  pAVar2 = *(Array **)(this + 0x38);
  if (pAVar2 != (Array *)0x0) {
    if (*(int *)pAVar2 != 0) {
      uVar4 = 0;
      do {
        ArrayReleaseClasses<ImagePart*>(*(Array **)(*(int *)(pAVar2 + 4) + uVar4 * 4));
        iVar3 = *(int *)(*(int *)(this + 0x38) + 4);
        pvVar1 = *(void **)(iVar3 + uVar4 * 4);
        if (pvVar1 != (void *)0x0) {
          if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar1 + 4));
          }
          operator_delete(pvVar1);
          iVar3 = *(int *)(*(int *)(this + 0x38) + 4);
        }
        *(undefined4 *)(iVar3 + uVar4 * 4) = 0;
        uVar4 = uVar4 + 1;
        pAVar2 = *(Array **)(this + 0x38);
      } while (uVar4 < *(uint *)pAVar2);
    }
    ArrayReleaseClasses<Array<ImagePart*>*>(pAVar2);
    pvVar1 = *(void **)(this + 0x38);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x38) = 0;
  if (*(Array **)(this + 0x40) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::AEMath::Vector*>(*(Array **)(this + 0x40));
    pvVar1 = *(void **)(this + 0x40);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x40) = 0;
  pvVar1 = *(void **)(this + 0x48);
  if (pvVar1 != (void *)0x0) {
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar1 + 0x58));
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar1 + 0x3c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x48) = 0;
  if (*(void **)(this + 0xbc) != (void *)0x0) {
    operator_delete(*(void **)(this + 0xbc));
  }
  *(undefined4 *)(this + 0xbc) = 0;
  AbyssEngine::String::~String((String *)(this + 0xa4));
  return this;
}

// ===== SpaceLounge::setHangarUpdate  @0x0019896c  (6 bytes)
/* SpaceLounge::setHangarUpdate(bool) */

void __thiscall SpaceLounge::setHangarUpdate(SpaceLounge *this,bool param_1)

{
  this[0x35] = (SpaceLounge)param_1;
  return;
}

// ===== SpaceLounge::startChat  @0x00198974  (11830 bytes)
/* SpaceLounge::startChat() */

void __thiscall SpaceLounge::startChat(SpaceLounge *this)

{
  bool bVar1;
  byte bVar2;
  Galaxy *this_00;
  Status *pSVar3;
  GameText *pGVar4;
  FModSound *pFVar5;
  int iVar6;
  void *pvVar7;
  ScrollTouchWindow *pSVar8;
  undefined4 *puVar9;
  int iVar10;
  String *pSVar11;
  undefined4 uVar12;
  Generator *this_01;
  Ship *pSVar13;
  SpaceLounge *pSVar14;
  Station *this_02;
  Array *pAVar15;
  uint uVar16;
  undefined4 uVar17;
  Mission *pMVar18;
  String *pSVar19;
  Mission *pMVar20;
  Standing *pSVar21;
  int iVar22;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  int iVar23;
  int iVar24;
  Agent *pAVar25;
  Agent *this_03;
  bool bVar26;
  uint in_fpscr;
  uint uVar27;
  float fVar28;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  String aSStack_558 [8];
  String aSStack_550 [8];
  String aSStack_548 [8];
  String aSStack_540 [8];
  String aSStack_538 [8];
  String aSStack_530 [8];
  String aSStack_528 [8];
  String aSStack_520 [8];
  String aSStack_518 [8];
  String aSStack_510 [8];
  String aSStack_508 [8];
  String aSStack_500 [8];
  String aSStack_4f8 [8];
  String aSStack_4f0 [8];
  String aSStack_4e8 [8];
  String aSStack_4e0 [8];
  String aSStack_4d8 [8];
  String aSStack_4d0 [8];
  String aSStack_4c8 [8];
  String aSStack_4c0 [8];
  String aSStack_4b8 [8];
  String aSStack_4b0 [8];
  String aSStack_4a8 [8];
  String aSStack_4a0 [8];
  String aSStack_498 [8];
  String aSStack_490 [8];
  String aSStack_488 [8];
  String aSStack_480 [8];
  String aSStack_478 [8];
  String aSStack_470 [8];
  String aSStack_468 [8];
  String aSStack_460 [8];
  String aSStack_458 [8];
  String aSStack_450 [8];
  String aSStack_448 [8];
  String aSStack_440 [8];
  String aSStack_438 [8];
  String aSStack_430 [8];
  String aSStack_428 [8];
  String aSStack_420 [8];
  String aSStack_418 [8];
  String aSStack_410 [8];
  String aSStack_408 [8];
  String aSStack_400 [8];
  String aSStack_3f8 [8];
  String aSStack_3f0 [8];
  String aSStack_3e8 [8];
  String aSStack_3e0 [8];
  String aSStack_3d8 [8];
  String aSStack_3d0 [8];
  String aSStack_3c8 [8];
  String aSStack_3c0 [8];
  String aSStack_3b8 [8];
  String aSStack_3b0 [8];
  AbyssEngine aAStack_3a8 [8];
  String aSStack_3a0 [8];
  AbyssEngine aAStack_398 [8];
  AbyssEngine aAStack_390 [8];
  String aSStack_388 [8];
  AbyssEngine aAStack_380 [8];
  String aSStack_378 [8];
  String aSStack_370 [8];
  String aSStack_368 [8];
  String aSStack_360 [8];
  String aSStack_358 [8];
  String aSStack_350 [8];
  String aSStack_348 [8];
  String aSStack_340 [8];
  String aSStack_338 [8];
  String aSStack_330 [8];
  String aSStack_328 [8];
  String aSStack_320 [8];
  String aSStack_318 [8];
  String aSStack_310 [8];
  String aSStack_308 [8];
  String aSStack_300 [8];
  String aSStack_2f8 [8];
  String aSStack_2f0 [8];
  String aSStack_2e8 [8];
  String aSStack_2e0 [8];
  String aSStack_2d8 [8];
  String aSStack_2d0 [8];
  String aSStack_2c8 [8];
  String aSStack_2c0 [8];
  String aSStack_2b8 [8];
  String aSStack_2b0 [8];
  String aSStack_2a8 [8];
  String aSStack_2a0 [8];
  AbyssEngine aAStack_298 [8];
  String aSStack_290 [8];
  String aSStack_288 [8];
  String aSStack_280 [8];
  String aSStack_278 [8];
  undefined4 local_270 [2];
  String aSStack_268 [8];
  String aSStack_260 [8];
  String aSStack_258 [8];
  String aSStack_250 [8];
  AbyssEngine aAStack_248 [8];
  String aSStack_240 [8];
  String aSStack_238 [8];
  String aSStack_230 [8];
  String aSStack_228 [8];
  String aSStack_220 [8];
  String aSStack_218 [8];
  String aSStack_210 [8];
  String aSStack_208 [8];
  String aSStack_200 [8];
  String aSStack_1f8 [8];
  String aSStack_1f0 [8];
  String aSStack_1e8 [8];
  String aSStack_1e0 [8];
  String aSStack_1d8 [8];
  String aSStack_1d0 [8];
  String aSStack_1c8 [8];
  String aSStack_1c0 [8];
  String aSStack_1b8 [8];
  String aSStack_1b0 [8];
  String aSStack_1a8 [8];
  String aSStack_1a0 [8];
  String aSStack_198 [8];
  String aSStack_190 [8];
  String aSStack_188 [8];
  String aSStack_180 [8];
  String aSStack_178 [8];
  String aSStack_170 [8];
  String aSStack_168 [8];
  String aSStack_160 [8];
  String aSStack_158 [8];
  String aSStack_150 [8];
  String aSStack_148 [8];
  String aSStack_140 [8];
  String aSStack_138 [8];
  String aSStack_130 [8];
  String aSStack_128 [8];
  String aSStack_120 [8];
  String aSStack_118 [8];
  String aSStack_110 [8];
  String aSStack_108 [8];
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
  AbyssEngine aAStack_a8 [8];
  String aSStack_a0 [8];
  String aSStack_98 [8];
  AbyssEngine aAStack_90 [8];
  String aSStack_88 [8];
  undefined4 auStack_80 [2];
  String aSStack_78 [8];
  String aSStack_70 [8];
  String aSStack_68 [8];
  undefined4 auStack_60 [2];
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  
  iVar10 = Globals::layout;
  iStack_34 = __stack_chk_guard;
  iVar6 = *(int *)(this + 0x20);
  this_03 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar6 * 4);
  if (Globals::iPad != '\0') {
    if (Globals::iPadHD == '\0') {
      fVar28 = 10.0;
      if (Globals::iPadLarge != '\0') {
        fVar28 = 20.0;
      }
    }
    else {
      fVar28 = 14.0625;
    }
    iVar22 = *(int *)(*(int *)(this + 0x40) + 4);
    fVar29 = (float)VectorSignedToFloat((int)fVar28,(byte)(in_fpscr >> 0x16) & 3);
    fVar28 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x68),
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar33 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x28),
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar28 = (**(float **)(iVar22 + iVar6 * 8) - fVar29) - fVar28;
    uVar16 = in_fpscr & 0xfffffff;
    if (fVar28 < fVar33) {
      fVar29 = fVar29 + **(float **)(iVar22 + (iVar6 << 1 | 1U) * 4);
      fVar28 = (float)VectorSignedToFloat(Globals::w - *(int *)(Globals::layout + 0x28),
                                          (byte)(uVar16 >> 0x16) & 3);
      uVar16 = uVar16 | (uint)(fVar28 < fVar29) << 0x1f | (uint)(fVar28 == fVar29) << 0x1e;
      bVar2 = (byte)(uVar16 >> 0x18);
      if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == (NAN(fVar28) || NAN(fVar29))) {
        fVar28 = fVar29;
      }
    }
    *(int *)(this + 0x70) = (int)fVar28;
    fVar30 = (float)VectorSignedToFloat(*(int *)(iVar10 + 0x6c) / 3,(byte)(uVar16 >> 0x16) & 3);
    fVar30 = *(float *)(*(int *)(iVar22 + (iVar6 << 1 | 1U) * 4) + 4) - fVar30;
    fVar29 = (float)VectorSignedToFloat(((Globals::h - *(int *)(iVar10 + 0x10)) -
                                        *(int *)(iVar10 + 0x24)) - *(int *)(iVar10 + 0x6c),
                                        (byte)(uVar16 >> 0x16) & 3);
    fVar32 = (float)VectorSignedToFloat(*(int *)(iVar10 + 0x20) + *(int *)(iVar10 + 0xc),
                                        (byte)(uVar16 >> 0x16) & 3);
    fVar33 = fVar29;
    if (fVar30 < fVar29) {
      fVar33 = fVar30;
    }
    fVar31 = fVar30;
    if (fVar33 < fVar32) {
      fVar31 = fVar32;
    }
    uVar16 = uVar16 & 0xfffffff | (uint)(fVar32 < fVar33) << 0x1f | (uint)(fVar32 == fVar33) << 0x1e
    ;
    in_fpscr = uVar16 | (uint)(NAN(fVar32) || NAN(fVar33)) << 0x1c;
    if (fVar30 < fVar29) {
      fVar29 = fVar31;
    }
    bVar2 = (byte)(uVar16 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar29 = fVar31;
    }
    iVar22 = (int)fVar28;
    iVar6 = (int)fVar29;
    *(int *)(this + 0x74) = (int)fVar29;
    if (*(ScrollTouchWindow **)(this + 0x60) != (ScrollTouchWindow *)0x0) {
      pvVar7 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0x60));
      operator_delete(pvVar7);
      iVar22 = *(int *)(this + 0x70);
      iVar6 = *(int *)(this + 0x74);
      iVar10 = Globals::layout;
    }
    *(undefined4 *)(this + 0x60) = 0;
    pSVar8 = operator_new(0x20);
    ScrollTouchWindow::ScrollTouchWindow
              (pSVar8,iVar22 + *(int *)(iVar10 + 0x4c) * 2 + *(int *)(iVar10 + 0x2d4),iVar6,
               *(int *)(this + 0x6c),*(int *)(iVar10 + 0x6c),false);
    *(ScrollTouchWindow **)(this + 0x60) = pSVar8;
    iVar10 = Globals::layout;
    iVar6 = *(int *)(this + 0x74) + *(int *)(Globals::layout + 0x6c) +
            *(int *)(Globals::layout + 0x2c);
    *(int *)(this + 0x78) = iVar6;
    iVar23 = *(int *)(iVar10 + 0x4c);
    iVar22 = ((*(int *)(this + 0x70) + *(int *)(iVar10 + 0x68)) - iVar23) - *(int *)(this + 0x6c);
    *(int *)(this + 0x84) = iVar22;
    fVar28 = (float)VectorSignedToFloat(*(undefined4 *)(iVar10 + 0x34),(byte)(in_fpscr >> 0x16) & 3)
    ;
    if (Globals::iPadHD == '\0') {
      fVar29 = 11.0;
      if (Globals::iPadLarge != '\0') {
        fVar29 = 0.0;
      }
    }
    else {
      fVar29 = 0.0;
    }
    iVar24 = *(int *)(iVar10 + 0x30);
    *(int *)(this + 0x7c) = ((iVar23 + iVar6) - iVar24 / 2) + *(int *)(iVar10 + 0x2d8) / 2;
    *(int *)(this + 0x80) = iVar23 + iVar6;
    iVar24 = iVar24 + iVar23 + iVar6 + (int)(fVar28 + fVar29);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 8),iVar22,iVar24);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0xc),*(int *)(this + 0x84),
               iVar24);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0x10),*(int *)(this + 0x84),
               iVar24 + (int)(fVar28 + fVar29) + *(int *)(Globals::layout + 0x30));
    puVar9 = *(undefined4 **)(*(int *)(*(int *)(this + 0x40) + 4) + *(int *)(this + 0x20) * 8);
    uStack_40 = *puVar9;
    uStack_3c = puVar9[1];
    uStack_38 = puVar9[2];
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x8c),(Vector *)&uStack_40);
    puVar9 = *(undefined4 **)
              (*(int *)(*(int *)(this + 0x40) + 4) + (*(int *)(this + 0x20) << 3 | 4U));
    uStack_40 = *puVar9;
    uStack_3c = puVar9[1];
    uStack_38 = puVar9[2];
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x98),(Vector *)&uStack_40);
  }
  iVar10 = Agent::getOffer(this_03);
  iVar6 = Agent::isGenericAgent(this_03);
  if (iVar6 != 1) {
    AbyssEngine::String::String((String *)&uStack_40);
    iVar10 = Agent::getEvent(this_03);
    if (iVar10 < 1) {
      iVar10 = Agent::hasAcceptedOffer(this_03);
      if (iVar10 == 1) {
        pSVar11 = (String *)GameText::getText(Globals::gameText,0x35a);
        AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
        iVar10 = getSoundId(this,this_03);
        if (-1 < iVar10) {
          FModSound::play(Globals::sound,iVar10,(Vector *)0x0,(Vector *)0x0,extraout_s0);
        }
        goto LAB_00198d06;
      }
      *(int *)(Globals::status + 0xd0) = *(int *)(Globals::status + 0xd0) + 1;
      iVar10 = Agent::getOffer(this_03);
      if (iVar10 != 8) {
        iVar10 = Agent::getOffer(this_03);
        if (iVar10 == 9) {
          iVar10 = *(int *)(this_03 + 0x20);
          if (iVar10 == -1) {
            iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar10 = iVar10 + 0x36a;
          }
          *(int *)(this_03 + 0x20) = iVar10;
          pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10);
          AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
          AbyssEngine::String::String((String *)auStack_60," ",false);
          pGVar4 = Globals::gameText;
          iVar10 = Agent::getIndex(this_03);
          pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x376);
          AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
          AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
          AbyssEngine::String::~String(aSStack_58);
          AbyssEngine::String::~String((String *)auStack_60);
          iVar10 = *(int *)(this_03 + 0x24);
          if (iVar10 == -1) {
            iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
            iVar10 = iVar10 + 0x305;
          }
          *(int *)(this_03 + 0x24) = iVar10;
          AbyssEngine::String::String((String *)auStack_60,"\n",false);
          pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10);
          AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
          AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
          AbyssEngine::String::~String(aSStack_58);
          AbyssEngine::String::~String((String *)auStack_60);
          pSVar3 = Globals::status;
          AbyssEngine::String::String(aSStack_410,(String *)&uStack_40,false);
          uVar12 = Agent::getSellItemQuantity(this_03);
          auStack_60[0] = 0;
          AbyssEngine::String::Set(CONCAT44(uVar12,auStack_60));
          AbyssEngine::String::String(aSStack_418,(String *)auStack_60,false);
          uVar12 = AbyssEngine::String::String(aSStack_420,"#Q",false);
          Status::replaceHash(aSStack_58,pSVar3,aSStack_410,aSStack_418,uVar12);
          AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
          AbyssEngine::String::~String(aSStack_58);
          AbyssEngine::String::~String(aSStack_420);
          AbyssEngine::String::~String(aSStack_418);
          AbyssEngine::String::~String((String *)auStack_60);
          AbyssEngine::String::~String(aSStack_410);
          pSVar3 = Globals::status;
          AbyssEngine::String::String(aSStack_428,(String *)&uStack_40,false);
          pGVar4 = Globals::gameText;
          iVar10 = Agent::getSellItemIndex(this_03);
          pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x4fa);
          AbyssEngine::String::String(aSStack_430,pSVar11,false);
          uVar12 = AbyssEngine::String::String(aSStack_438,"#P",false);
          Status::replaceHash(aSStack_58,pSVar3,aSStack_428,aSStack_430,uVar12);
          AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
          AbyssEngine::String::~String(aSStack_58);
          AbyssEngine::String::~String(aSStack_438);
          AbyssEngine::String::~String(aSStack_430);
          AbyssEngine::String::~String(aSStack_428);
          pSVar3 = Globals::status;
          AbyssEngine::String::String(aSStack_440,(String *)&uStack_40,false);
          uVar12 = Agent::getSellItemPrice(this_03);
          VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
          Layout::formatCredits((int)auStack_60);
          AbyssEngine::String::String(aSStack_448,(String *)auStack_60,false);
          uVar12 = AbyssEngine::String::String(aSStack_450,"#C",false);
          Status::replaceHash(aSStack_58,pSVar3,aSStack_440,aSStack_448,uVar12);
          AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
          AbyssEngine::String::~String(aSStack_58);
          AbyssEngine::String::~String(aSStack_450);
          AbyssEngine::String::~String(aSStack_448);
          AbyssEngine::String::~String((String *)auStack_60);
          AbyssEngine::String::~String(aSStack_440);
          iVar10 = Agent::getSellItemQuantity(this_03);
          if (1 < iVar10) {
            AbyssEngine::String::String((String *)auStack_60," ",false);
            pSVar11 = (String *)GameText::getText(Globals::gameText,0x307);
            AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
            AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
            AbyssEngine::String::~String(aSStack_58);
            AbyssEngine::String::~String((String *)auStack_60);
            pSVar3 = Globals::status;
            AbyssEngine::String::String(aSStack_458,(String *)&uStack_40,false);
            uVar12 = Agent::getSellItemPrice(this_03);
            uVar17 = Agent::getSellItemQuantity(this_03);
            uVar12 = __aeabi_idiv(uVar12,uVar17);
            VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
            Layout::formatCredits((int)auStack_60);
            AbyssEngine::String::String(aSStack_460,(String *)auStack_60,false);
            uVar12 = AbyssEngine::String::String(aSStack_468,"#C",false);
            Status::replaceHash(aSStack_58,pSVar3,aSStack_458,aSStack_460,uVar12);
            AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
            AbyssEngine::String::~String(aSStack_58);
            AbyssEngine::String::~String(aSStack_468);
            AbyssEngine::String::~String(aSStack_460);
            AbyssEngine::String::~String((String *)auStack_60);
            pSVar19 = aSStack_458;
            goto LAB_0019b7ce;
          }
        }
        else {
          iVar10 = Agent::getOffer(this_03);
          pGVar4 = Globals::gameText;
          if (iVar10 == 10) {
            if (*(int *)(Globals::status + 0x114) < 3) {
              iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
              pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x2ee);
              AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
              pFVar5 = Globals::sound;
              iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar6 = Agent::getRace(this_03);
              pSVar14 = (SpaceLounge *)Agent::isMale(this_03);
              iVar10 = getSpecificSoundForRace(pSVar14,iVar10 + 0x30d,iVar6,SUB41(pSVar14,0));
              FModSound::play(pFVar5,iVar10,(Vector *)0x0,(Vector *)0x0,extraout_s0_02);
              *(int *)(Globals::status + 0xd0) = *(int *)(Globals::status + 0xd0) + -1;
              pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
              Agent::getName();
              AbyssEngine::String::String(aSStack_478,(String *)&uStack_40,false);
              ScrollTouchWindow::setText(pSVar8,aSStack_470,aSStack_478);
              AbyssEngine::String::~String(aSStack_478);
              pSVar19 = aSStack_470;
              goto LAB_00198d30;
            }
            iVar10 = *(int *)(this_03 + 0x20);
            if (iVar10 == -1) {
              iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar10 = iVar10 + 0x36a;
            }
            *(int *)(this_03 + 0x20) = iVar10;
            pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10);
            AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
            AbyssEngine::String::String((String *)auStack_60," ",false);
            pGVar4 = Globals::gameText;
            iVar10 = Agent::getIndex(this_03);
            pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x376);
            AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
            AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
            AbyssEngine::String::~String(aSStack_58);
            AbyssEngine::String::~String((String *)auStack_60);
            iVar10 = *(int *)(this_03 + 0x24);
            if (iVar10 == -1) {
              iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              iVar10 = iVar10 + 0x305;
            }
            *(int *)(this_03 + 0x24) = iVar10;
            AbyssEngine::String::String((String *)auStack_60,"\n",false);
            pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10);
            AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
            AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
            AbyssEngine::String::~String(aSStack_58);
            AbyssEngine::String::~String((String *)auStack_60);
            pSVar3 = Globals::status;
            AbyssEngine::String::String(aSStack_480,(String *)&uStack_40,false);
            auStack_60[0] = 0;
            AbyssEngine::String::Set(CONCAT44(extraout_r1_00,auStack_60));
            AbyssEngine::String::String(aSStack_488,(String *)auStack_60,false);
            uVar12 = AbyssEngine::String::String(aSStack_490,"#Q",false);
            Status::replaceHash(aSStack_58,pSVar3,aSStack_480,aSStack_488,uVar12);
            AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
            AbyssEngine::String::~String(aSStack_58);
            AbyssEngine::String::~String(aSStack_490);
            AbyssEngine::String::~String(aSStack_488);
            AbyssEngine::String::~String((String *)auStack_60);
            AbyssEngine::String::~String(aSStack_480);
            pSVar3 = Globals::status;
            AbyssEngine::String::String(aSStack_498,(String *)&uStack_40,false);
            pGVar4 = Globals::gameText;
            iVar10 = Agent::getSellItemIndex(this_03);
            pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x391);
            AbyssEngine::String::String(aSStack_4a0,pSVar11,false);
            uVar12 = AbyssEngine::String::String(aSStack_4a8,"#P",false);
            Status::replaceHash(aSStack_58,pSVar3,aSStack_498,aSStack_4a0,uVar12);
            AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
            AbyssEngine::String::~String(aSStack_58);
            AbyssEngine::String::~String(aSStack_4a8);
            AbyssEngine::String::~String(aSStack_4a0);
            AbyssEngine::String::~String(aSStack_498);
            pSVar3 = Globals::status;
            AbyssEngine::String::String(aSStack_4b0,(String *)&uStack_40,false);
            uVar12 = Agent::getSellItemPrice(this_03);
            VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
            Layout::formatCredits((int)auStack_60);
            AbyssEngine::String::String(aSStack_4b8,(String *)auStack_60,false);
            uVar12 = AbyssEngine::String::String(aSStack_4c0,"#C",false);
            Status::replaceHash(aSStack_58,pSVar3,aSStack_4b0,aSStack_4b8,uVar12);
            AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
            AbyssEngine::String::~String(aSStack_58);
            AbyssEngine::String::~String(aSStack_4c0);
            AbyssEngine::String::~String(aSStack_4b8);
            AbyssEngine::String::~String((String *)auStack_60);
            pSVar19 = aSStack_4b0;
          }
          else {
            iVar10 = Agent::getOffer(this_03);
            if (iVar10 == 4) {
              iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              *(int *)(this_03 + 0x20) = iVar10 + 0x36a;
              pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10 + 0x36a);
              AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
              AbyssEngine::String::String((String *)auStack_60," ",false);
              pGVar4 = Globals::gameText;
              iVar10 = Agent::getIndex(this_03);
              pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x376);
              AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
              AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String((String *)auStack_60);
              AbyssEngine::String::String((String *)auStack_60," ",false);
              pSVar11 = (String *)GameText::getText(Globals::gameText,0x36d);
              AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
              AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String((String *)auStack_60);
              this_00 = Globals::galaxy;
              iVar10 = Agent::getSellSystemIndex(this_03);
              Galaxy::getSystem(this_00,iVar10);
              pSVar3 = Globals::status;
              AbyssEngine::String::String(aSStack_4c8,(String *)&uStack_40,false);
              SolarSystem::getName();
              AbyssEngine::String::String(aSStack_4d0,(String *)auStack_60,false);
              uVar12 = AbyssEngine::String::String(aSStack_4d8,"#S",false);
              Status::replaceHash(aSStack_58,pSVar3,aSStack_4c8,aSStack_4d0,uVar12);
              AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String(aSStack_4d8);
              AbyssEngine::String::~String(aSStack_4d0);
              AbyssEngine::String::~String((String *)auStack_60);
              AbyssEngine::String::~String(aSStack_4c8);
              pSVar3 = Globals::status;
              AbyssEngine::String::String(aSStack_4e0,(String *)&uStack_40,false);
              Agent::getSellItemPrice(this_03);
              Layout::formatCredits((int)auStack_60);
              AbyssEngine::String::String(aSStack_4e8,(String *)auStack_60,false);
              uVar12 = AbyssEngine::String::String(aSStack_4f0,"#C",false);
              Status::replaceHash(aSStack_58,pSVar3,aSStack_4e0,aSStack_4e8,uVar12);
              AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String(aSStack_4f0);
              AbyssEngine::String::~String(aSStack_4e8);
              AbyssEngine::String::~String((String *)auStack_60);
              pSVar19 = aSStack_4e0;
            }
            else {
              iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
              *(int *)(this_03 + 0x20) = iVar10 + 0x36a;
              pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10 + 0x36a);
              AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
              AbyssEngine::String::String((String *)auStack_60," ",false);
              pGVar4 = Globals::gameText;
              iVar10 = Agent::getIndex(this_03);
              pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x376);
              AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
              AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String((String *)auStack_60);
              AbyssEngine::String::String((String *)auStack_60," ",false);
              pSVar11 = (String *)GameText::getText(Globals::gameText,0x36c);
              AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
              AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String((String *)auStack_60);
              pSVar3 = Globals::status;
              AbyssEngine::String::String(aSStack_4f8,(String *)&uStack_40,false);
              iVar10 = Globals::items;
              pGVar4 = Globals::gameText;
              iVar6 = Agent::getSellBlueprintIndex(this_03);
              iVar10 = Item::getIndex(*(Item **)(*(int *)(iVar10 + 4) + iVar6 * 4));
              pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x4fa);
              AbyssEngine::String::String(aSStack_500,pSVar11,false);
              uVar12 = AbyssEngine::String::String(aSStack_508,"#N",false);
              Status::replaceHash(aSStack_58,pSVar3,aSStack_4f8,aSStack_500,uVar12);
              AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String(aSStack_508);
              AbyssEngine::String::~String(aSStack_500);
              AbyssEngine::String::~String(aSStack_4f8);
              pSVar3 = Globals::status;
              AbyssEngine::String::String(aSStack_510,(String *)&uStack_40,false);
              Agent::getSellItemPrice(this_03);
              Layout::formatCredits((int)auStack_60);
              AbyssEngine::String::String(aSStack_518,(String *)auStack_60,false);
              uVar12 = AbyssEngine::String::String(aSStack_520,"#C",false);
              Status::replaceHash(aSStack_58,pSVar3,aSStack_510,aSStack_518,uVar12);
              AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
              AbyssEngine::String::~String(aSStack_58);
              AbyssEngine::String::~String(aSStack_520);
              AbyssEngine::String::~String(aSStack_518);
              AbyssEngine::String::~String((String *)auStack_60);
              pSVar19 = aSStack_510;
            }
          }
LAB_0019b7ce:
          AbyssEngine::String::~String(pSVar19);
        }
        AbyssEngine::String::String((String *)auStack_60,"\n",false);
        pGVar4 = Globals::gameText;
        iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
        pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x349);
        AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
        AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String((String *)auStack_60);
        pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
        Agent::getName();
        AbyssEngine::String::String(aSStack_530,(String *)&uStack_40,false);
        ScrollTouchWindow::setText(pSVar8,aSStack_528,aSStack_530);
        AbyssEngine::String::~String(aSStack_530);
        AbyssEngine::String::~String(aSStack_528);
        pAVar25 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4);
        AbyssEngine::String::String(aSStack_538,(String *)&uStack_40,false);
        Agent::setMissionString(pAVar25,aSStack_538);
        AbyssEngine::String::~String(aSStack_538);
        *(undefined4 *)(this + 0x2c) = 0;
        *(undefined4 *)(this + 0x14) = 2;
        iVar10 = getSoundId(this,this_03);
        if (-1 < iVar10) {
          FModSound::play(Globals::sound,iVar10,(Vector *)0x0,(Vector *)0x0,extraout_s0_04);
        }
        goto LAB_00198d40;
      }
      pSVar13 = (Ship *)Status::getShip(Globals::status);
      iVar10 = Agent::getSellModIndex(this_03);
      iVar10 = Ship::hasModInstalled(pSVar13,iVar10);
      if (iVar10 != 1) {
        iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
        *(int *)(this_03 + 0x20) = iVar10 + 0x36a;
        pSVar13 = (Ship *)Status::getShip(Globals::status);
        iVar10 = Ship::getPrice(pSVar13);
        iVar6 = Agent::getModPricePercentage(this_03);
        Agent::setSellItemPrice(this_03,(iVar10 * iVar6) / 100);
        pSVar11 = (String *)GameText::getText(Globals::gameText,*(int *)(this_03 + 0x20));
        AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
        AbyssEngine::String::String((String *)auStack_60," ",false);
        pGVar4 = Globals::gameText;
        iVar10 = Agent::getIndex(this_03);
        pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x376);
        AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
        AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String((String *)auStack_60);
        AbyssEngine::String::String((String *)auStack_60," ",false);
        pSVar11 = (String *)GameText::getText(Globals::gameText,0x36f);
        AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
        AbyssEngine::String::operator+=((String *)&uStack_40,aSStack_58);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String((String *)auStack_60);
        pSVar3 = Globals::status;
        AbyssEngine::String::String(aSStack_3c8,(String *)&uStack_40,false);
        pGVar4 = Globals::gameText;
        pSVar13 = (Ship *)Status::getShip(Globals::status);
        iVar10 = Ship::getIndex(pSVar13);
        pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x391);
        AbyssEngine::String::String(aSStack_3d0,pSVar11,false);
        uVar12 = AbyssEngine::String::String(aSStack_3d8,"#SHIP_NAME",false);
        Status::replaceHash(aSStack_58,pSVar3,aSStack_3c8,aSStack_3d0,uVar12);
        AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String(aSStack_3d8);
        AbyssEngine::String::~String(aSStack_3d0);
        AbyssEngine::String::~String(aSStack_3c8);
        pSVar3 = Globals::status;
        AbyssEngine::String::String(aSStack_3e0,(String *)&uStack_40,false);
        Agent::getSellModIndex(this_03);
        auStack_60[0] = 0;
        AbyssEngine::String::Set(CONCAT44(&DAT_00254400,auStack_60));
        AbyssEngine::String::String(aSStack_3e8,(String *)auStack_60,false);
        uVar12 = AbyssEngine::String::String(aSStack_3f0,"#N",false);
        Status::replaceHash(aSStack_58,pSVar3,aSStack_3e0,aSStack_3e8,uVar12);
        AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String(aSStack_3f0);
        AbyssEngine::String::~String(aSStack_3e8);
        AbyssEngine::String::~String((String *)auStack_60);
        AbyssEngine::String::~String(aSStack_3e0);
        pSVar3 = Globals::status;
        AbyssEngine::String::String(aSStack_3f8,(String *)&uStack_40,false);
        uVar12 = Agent::getSellItemPrice(this_03);
        VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
        Layout::formatCredits((int)auStack_60);
        AbyssEngine::String::String(aSStack_400,(String *)auStack_60,false);
        uVar12 = AbyssEngine::String::String(aSStack_408,"#C",false);
        Status::replaceHash(aSStack_58,pSVar3,aSStack_3f8,aSStack_400,uVar12);
        AbyssEngine::String::operator=((String *)&uStack_40,aSStack_58);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String(aSStack_408);
        AbyssEngine::String::~String(aSStack_400);
        AbyssEngine::String::~String((String *)auStack_60);
        pSVar19 = aSStack_3f8;
        goto LAB_0019b7ce;
      }
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x35a);
      AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
      pFVar5 = Globals::sound;
      iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      iVar6 = Agent::getRace(this_03);
      pSVar14 = (SpaceLounge *)Agent::isMale(this_03);
      iVar10 = getSpecificSoundForRace(pSVar14,iVar10 + 0x30d,iVar6,SUB41(pSVar14,0));
      FModSound::play(pFVar5,iVar10,(Vector *)0x0,(Vector *)0x0,extraout_s0_00);
      *(int *)(Globals::status + 0xd0) = *(int *)(Globals::status + 0xd0) + -1;
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String(aSStack_3c0,(String *)&uStack_40,false);
      ScrollTouchWindow::setText(pSVar8,aSStack_3b8,aSStack_3c0);
      AbyssEngine::String::~String(aSStack_3c0);
      pSVar19 = aSStack_3b8;
    }
    else {
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x35a);
      AbyssEngine::String::operator=((String *)&uStack_40,pSVar11);
LAB_00198d06:
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String(aSStack_548,(String *)&uStack_40,false);
      ScrollTouchWindow::setText(pSVar8,aSStack_540,aSStack_548);
      AbyssEngine::String::~String(aSStack_548);
      pSVar19 = aSStack_540;
    }
LAB_00198d30:
    AbyssEngine::String::~String(pSVar19);
    *(undefined4 *)(this + 0x2c) = 0;
    *(undefined4 *)(this + 0x14) = 3;
LAB_00198d40:
    AbyssEngine::String::~String((String *)&uStack_40);
    goto LAB_0019acf0;
  }
  iVar6 = Agent::isKnown(this_03);
  if ((iVar6 == 1) && (iVar6 = Agent::getOffer(this_03), iVar6 != 7)) {
    iVar10 = Agent::hasAcceptedOffer(this_03);
    pGVar4 = Globals::gameText;
    if (iVar10 == 1) {
      iVar10 = Agent::getOffer(this_03);
      if (iVar10 == 5) {
        iVar6 = 0x359;
      }
      else {
        iVar10 = Agent::getOffer(this_03);
        if (iVar10 == 6) {
          iVar6 = 0x35b;
        }
        else {
          iVar10 = Agent::getMission(this_03);
          iVar6 = 0x35a;
          if (iVar10 != 0) {
            pMVar20 = (Mission *)Agent::getMission(this_03);
            iVar10 = Mission::getType(pMVar20);
            if (iVar10 == 0xc) {
              iVar6 = 0x35b;
            }
          }
        }
      }
      pSVar11 = (String *)GameText::getText(pGVar4,iVar6);
      AbyssEngine::String::String((String *)&uStack_40,pSVar11,false);
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String(aSStack_50,(String *)&uStack_40,false);
      ScrollTouchWindow::setText(pSVar8,aSStack_48,aSStack_50);
      AbyssEngine::String::~String(aSStack_50);
      AbyssEngine::String::~String(aSStack_48);
      *(undefined4 *)(this + 0x2c) = 0;
      *(undefined4 *)(this + 0x14) = 3;
      iVar10 = getSoundId(this,this_03);
      if (-1 < iVar10) {
        FModSound::play(Globals::sound,iVar10,(Vector *)0x0,(Vector *)0x0,extraout_s0_03);
      }
      goto LAB_00198d40;
    }
    iVar10 = Agent::getOffer(this_03);
    if ((iVar10 == 0) && (iVar10 = Agent::getMission(this_03), iVar10 != 0)) {
      pMVar20 = (Mission *)Agent::getMission(this_03);
      iVar10 = Mission::getType(pMVar20);
      if (iVar10 == 8) goto LAB_001991a2;
      pMVar20 = (Mission *)Agent::getMission(this_03);
      iVar10 = Mission::getType(pMVar20);
      if (iVar10 == 0xc) goto LAB_001991a2;
      pSVar21 = (Standing *)Status::getStanding(Globals::status);
      iVar10 = Agent::getRace(this_03);
      fVar28 = (float)Standing::getMissionBonus(pSVar21,iVar10);
      pMVar20 = (Mission *)Agent::getMission(this_03);
      uVar12 = Mission::getReward(pMVar20);
      fVar29 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      iVar10 = (int)(fVar28 * fVar29) / 0x32;
      iVar6 = (int)(fVar28 * fVar29) * 2 + iVar10 * -0x32;
      if (iVar6 % 0x32 != 0) {
        iVar6 = iVar10 * 0x32;
      }
      pMVar20 = (Mission *)Agent::getMission(this_03);
      Mission::setBonus(pMVar20,iVar6);
      if (fVar28 <= 0.0) {
        AbyssEngine::String::String((String *)&uStack_40,"",false);
      }
      else {
        AbyssEngine::String::String((String *)auStack_60," ",false);
        pSVar3 = Globals::status;
        pSVar11 = (String *)GameText::getText(Globals::gameText,0x2ff);
        AbyssEngine::String::String(aSStack_70,pSVar11,false);
        auStack_80[0] = 0;
        AbyssEngine::String::Set(CONCAT44(extraout_r1_01,auStack_80));
        AbyssEngine::String::String(aSStack_78,(String *)auStack_80,false);
        uVar12 = AbyssEngine::String::String(aSStack_88,"#P",false);
        Status::replaceHash(aSStack_68,pSVar3,aSStack_70,aSStack_78,uVar12);
        AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,aSStack_68);
        AbyssEngine::String::String((String *)aAStack_90," ",false);
        AbyssEngine::operator+((AbyssEngine *)&uStack_40,aSStack_58,aAStack_90);
      }
      AbyssEngine::String::operator=((String *)(this + 0xa4),(String *)&uStack_40);
      AbyssEngine::String::~String((String *)&uStack_40);
      if (0.0 < fVar28) {
        AbyssEngine::String::~String((String *)aAStack_90);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String(aSStack_68);
        AbyssEngine::String::~String(aSStack_88);
        AbyssEngine::String::~String(aSStack_78);
        AbyssEngine::String::~String((String *)auStack_80);
        AbyssEngine::String::~String(aSStack_70);
        AbyssEngine::String::~String((String *)auStack_60);
      }
      Globals::getAgentMissionText((Agent *)&uStack_40);
      pSVar3 = Globals::status;
      AbyssEngine::String::String(aSStack_a0,(Agent *)&uStack_40,false);
      pMVar20 = (Mission *)Agent::getMission(this_03);
      Mission::getReward(pMVar20);
      pMVar20 = (Mission *)Agent::getMission(this_03);
      Mission::getBonus(pMVar20);
      Layout::formatCredits((int)aSStack_b8);
      AbyssEngine::String::String(aSStack_b0,aSStack_b8,false);
      AbyssEngine::operator+(aAStack_a8,aSStack_b0,(String *)(this + 0xa4));
      uVar12 = AbyssEngine::String::String(aSStack_c0,"#C",false);
      Status::replaceHash(aSStack_98,pSVar3,aSStack_a0,aAStack_a8,uVar12);
      AbyssEngine::String::operator=((String *)&uStack_40,aSStack_98);
      AbyssEngine::String::~String(aSStack_98);
      AbyssEngine::String::~String(aSStack_c0);
      AbyssEngine::String::~String((String *)aAStack_a8);
      AbyssEngine::String::~String(aSStack_b0);
      AbyssEngine::String::~String(aSStack_b8);
      AbyssEngine::String::~String(aSStack_a0);
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String(aSStack_d0,(String *)&uStack_40,false);
      ScrollTouchWindow::setText(pSVar8,aSStack_c8,aSStack_d0);
      AbyssEngine::String::~String(aSStack_d0);
      pSVar19 = aSStack_c8;
    }
    else {
LAB_001991a2:
      Globals::getAgentMissionText((Agent *)&uStack_40);
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String(aSStack_e0,(String *)&uStack_40,false);
      ScrollTouchWindow::setText(pSVar8,aSStack_d8,aSStack_e0);
      AbyssEngine::String::~String(aSStack_e0);
      pSVar19 = aSStack_d8;
    }
    goto LAB_0019ac60;
  }
  *(int *)(Globals::status + 0xd0) = *(int *)(Globals::status + 0xd0) + 1;
  pGVar4 = Globals::gameText;
  if (iVar10 == 1 || iVar10 == 7) {
    AbyssEngine::String::String((String *)&uStack_40,"",false);
    AbyssEngine::String::String(aSStack_98,"",false);
  }
  else {
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
    pSVar11 = (String *)GameText::getText(pGVar4,iVar6 + 0x2ee);
    AbyssEngine::String::String((String *)&uStack_40,pSVar11,false);
    pGVar4 = Globals::gameText;
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    pSVar11 = (String *)GameText::getText(pGVar4,iVar6 + 0x2f4);
    AbyssEngine::String::String(aSStack_98,pSVar11,false);
  }
  pGVar4 = Globals::gameText;
  if (iVar10 == 5 || iVar10 == 0) {
    iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,6);
    pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x2f6);
    AbyssEngine::String::String(aSStack_b0,pSVar11,false);
  }
  else {
    AbyssEngine::String::String(aSStack_b0,"",false);
  }
  AbyssEngine::String::String(aSStack_b8,"",false);
  pSVar3 = Globals::status;
  AbyssEngine::String::String(aSStack_e8,aSStack_98,false);
  Agent::getName();
  AbyssEngine::String::String(aSStack_f0,(String *)auStack_60,false);
  uVar12 = AbyssEngine::String::String(aSStack_f8,"#N",false);
  Status::replaceHash(aSStack_58,pSVar3,aSStack_e8,aSStack_f0,uVar12);
  AbyssEngine::String::operator=(aSStack_98,aSStack_58);
  AbyssEngine::String::~String(aSStack_58);
  AbyssEngine::String::~String(aSStack_f8);
  AbyssEngine::String::~String(aSStack_f0);
  AbyssEngine::String::~String((String *)auStack_60);
  AbyssEngine::String::~String(aSStack_e8);
  this_01 = operator_new(1);
  Generator::Generator(this_01);
  uVar12 = Agent::getOffer(this_03);
  pGVar4 = Globals::gameText;
  switch(uVar12) {
  case 0:
    pMVar20 = (Mission *)Agent::getMission(this_03);
    pGVar4 = Globals::gameText;
    iVar10 = Mission::getType(pMVar20);
    pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x312);
    AbyssEngine::String::operator+=(aSStack_b8,pSVar11);
    iVar10 = Mission::getType(pMVar20);
    if ((iVar10 == 5) || (iVar10 = Mission::getType(pMVar20), iVar10 == 3)) {
      AbyssEngine::String::String((String *)auStack_60," ",false);
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x322);
      AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
      AbyssEngine::String::operator+=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String((String *)auStack_60);
    }
    iVar10 = Mission::getType(pMVar20);
    pSVar3 = Globals::status;
    if (iVar10 == 0xf) {
      AbyssEngine::String::String(aSStack_1b8,aSStack_b8,false);
      pGVar4 = Globals::gameText;
      iVar10 = Mission::getProductionGoodIndex(pMVar20);
      pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x4fa);
      AbyssEngine::String::String(aSStack_1c0,pSVar11,false);
      uVar12 = AbyssEngine::String::String(aSStack_1c8,"#P",false);
      Status::replaceHash(aSStack_58,pSVar3,aSStack_1b8,aSStack_1c0,uVar12);
      AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String(aSStack_1c8);
      AbyssEngine::String::~String(aSStack_1c0);
      pSVar19 = aSStack_1b8;
    }
    else {
      AbyssEngine::String::String(aSStack_1d0,aSStack_b8,false);
      pGVar4 = Globals::gameText;
      iVar10 = Mission::getProductionGoodIndex(pMVar20);
      pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x32d);
      AbyssEngine::String::String(aSStack_1d8,pSVar11,false);
      uVar12 = AbyssEngine::String::String(aSStack_1e0,"#P",false);
      Status::replaceHash(aSStack_58,pSVar3,aSStack_1d0,aSStack_1d8,uVar12);
      AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String(aSStack_1e0);
      AbyssEngine::String::~String(aSStack_1d8);
      pSVar19 = aSStack_1d0;
    }
    AbyssEngine::String::~String(pSVar19);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_1e8,aSStack_b8,false);
    uVar12 = Mission::getProductionGoodAmount(pMVar20);
    auStack_60[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar12,auStack_60));
    AbyssEngine::String::String(aSStack_1f0,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_1f8,"#Q",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_1e8,aSStack_1f0,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_1f8);
    AbyssEngine::String::~String(aSStack_1f0);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_1e8);
    iVar10 = Mission::getType(pMVar20);
    pSVar3 = Globals::status;
    if (iVar10 == 0xe) {
      AbyssEngine::String::String(aSStack_200,aSStack_b8,false);
      Mission::getTargetSystemName();
      AbyssEngine::String::String(aSStack_208,(String *)auStack_60,false);
      uVar12 = AbyssEngine::String::String(aSStack_210,"#S",false);
      Status::replaceHash(aSStack_58,pSVar3,aSStack_200,aSStack_208,uVar12);
      AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String(aSStack_210);
      AbyssEngine::String::~String(aSStack_208);
      AbyssEngine::String::~String((String *)auStack_60);
      pSVar19 = aSStack_200;
    }
    else {
      AbyssEngine::String::String(aSStack_218,aSStack_b8,false);
      Mission::getTargetStationName();
      AbyssEngine::String::String(aSStack_220,(String *)auStack_60,false);
      uVar12 = AbyssEngine::String::String(aSStack_228,"#S",false);
      Status::replaceHash(aSStack_58,pSVar3,aSStack_218,aSStack_220,uVar12);
      AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String(aSStack_228);
      AbyssEngine::String::~String(aSStack_220);
      AbyssEngine::String::~String((String *)auStack_60);
      pSVar19 = aSStack_218;
    }
    AbyssEngine::String::~String(pSVar19);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_230,aSStack_b8,false);
    Mission::getTargetName();
    AbyssEngine::String::String(aSStack_238,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_240,"#N",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_230,aSStack_238,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_240);
    AbyssEngine::String::~String(aSStack_238);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_230);
    iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
    *(int *)(this_03 + 0x20) = iVar10 + 0x2fc;
    AbyssEngine::String::String((String *)auStack_60,"\n",false);
    pSVar11 = (String *)GameText::getText(Globals::gameText,*(int *)(this_03 + 0x20));
    AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
    AbyssEngine::String::operator+=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String((String *)auStack_60);
    pSVar21 = (Standing *)Status::getStanding(Globals::status);
    iVar10 = Agent::getRace(this_03);
    fVar28 = (float)Standing::getMissionBonus(pSVar21,iVar10);
    uVar16 = in_fpscr & 0xfffffff | (uint)(fVar28 < 0.0) << 0x1f | (uint)(fVar28 == 0.0) << 0x1e;
    uVar27 = uVar16 | (uint)NAN(fVar28) << 0x1c;
    bVar2 = (byte)(uVar16 >> 0x18);
    bVar26 = (bool)(bVar2 >> 6 & 1);
    bVar1 = bVar2 >> 7 != ((byte)(uVar27 >> 0x1c) & 1);
    if (bVar26 || bVar1) {
      AbyssEngine::String::String(aSStack_58,"",false);
    }
    else {
      AbyssEngine::String::String(aSStack_250," ",false);
      pSVar3 = Globals::status;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x2ff);
      AbyssEngine::String::String(aSStack_260,pSVar11,false);
      local_270[0] = 0;
      AbyssEngine::String::Set(CONCAT44(extraout_r1,local_270));
      AbyssEngine::String::String(aSStack_268,(String *)local_270,false);
      uVar12 = AbyssEngine::String::String(aSStack_278,"#P",false);
      Status::replaceHash(aSStack_258,pSVar3,aSStack_260,aSStack_268,uVar12);
      AbyssEngine::operator+(aAStack_248,aSStack_250,aSStack_258);
      AbyssEngine::String::String(aSStack_280," ",false);
      AbyssEngine::operator+((AbyssEngine *)aSStack_58,aAStack_248,aSStack_280);
    }
    AbyssEngine::String::operator=((String *)(this + 0xa4),aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    if (!bVar26 && !bVar1) {
      AbyssEngine::String::~String(aSStack_280);
      AbyssEngine::String::~String((String *)aAStack_248);
      AbyssEngine::String::~String(aSStack_258);
      AbyssEngine::String::~String(aSStack_278);
      AbyssEngine::String::~String(aSStack_268);
      AbyssEngine::String::~String((String *)local_270);
      AbyssEngine::String::~String(aSStack_260);
      AbyssEngine::String::~String(aSStack_250);
    }
    AbyssEngine::String::String(aSStack_288,aSStack_b8,false);
    Agent::setMissionString(this_03,aSStack_288);
    AbyssEngine::String::~String(aSStack_288);
    pMVar18 = (Mission *)Agent::getMission(this_03);
    uVar12 = Mission::getReward(pMVar18);
    fVar29 = (float)VectorSignedToFloat(uVar12,(byte)(uVar27 >> 0x16) & 3);
    iVar6 = (int)(fVar28 * fVar29);
    pMVar18 = (Mission *)Agent::getMission(this_03);
    iVar10 = iVar6 % 0x32 + iVar6;
    if (iVar10 % 0x32 != 0) {
      iVar10 = iVar6 - iVar6 % 0x32;
    }
    Mission::setBonus(pMVar18,iVar10);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_290,aSStack_b8,false);
    Mission::getReward(pMVar20);
    Mission::getBonus(pMVar20);
    Layout::formatCredits((int)aSStack_68);
    AbyssEngine::String::String((String *)auStack_60,aSStack_68,false);
    AbyssEngine::operator+(aAStack_298,(String *)auStack_60,(String *)(this + 0xa4));
    uVar12 = AbyssEngine::String::String(aSStack_2a0,"#C",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_290,aAStack_298,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_2a0);
    AbyssEngine::String::~String((String *)aAStack_298);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_68);
    pSVar19 = aSStack_290;
    goto LAB_0019a756;
  case 1:
    do {
      iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x15);
    } while (*(char *)(*(int *)(this + 0x58) + iVar10) != '\0');
    *(undefined1 *)(*(int *)(this + 0x58) + iVar10) = 1;
    iVar22 = Agent::getRace(this_03);
    iVar6 = iVar10;
    if (iVar22 != 0) {
      iVar6 = 4;
    }
    if (iVar10 != 0x10) {
      iVar6 = iVar10;
    }
    iVar22 = Agent::isMale(this_03);
    iVar10 = iVar6 + 0x334;
    if (iVar22 != 1) {
      iVar10 = 0x338;
    }
    if (iVar6 != 0xd) {
      iVar10 = iVar6 + 0x334;
    }
    *(int *)(this_03 + 0x20) = iVar10;
    pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10);
    AbyssEngine::String::operator=(aSStack_b8,pSVar11);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_170,aSStack_b8,false);
    Globals::getRandomPlanetName();
    AbyssEngine::String::String(aSStack_178,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_180,"#S",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_170,aSStack_178,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_180);
    AbyssEngine::String::~String(aSStack_178);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_170);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_188,aSStack_b8,false);
    Agent::getName();
    AbyssEngine::String::String(aSStack_190,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_198,"#N",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_188,aSStack_190,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_198);
    AbyssEngine::String::~String(aSStack_190);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_188);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_1a0,aSStack_b8,false);
    pGVar4 = Globals::gameText;
    iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
    pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x594);
    AbyssEngine::String::String(aSStack_1a8,pSVar11,false);
    uVar12 = AbyssEngine::String::String(aSStack_1b0,"#ORE",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_1a0,aSStack_1a8,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_1b0);
    AbyssEngine::String::~String(aSStack_1a8);
    pSVar19 = aSStack_1a0;
    goto LAB_0019a756;
  case 2:
    iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
    *(int *)(this_03 + 0x20) = iVar10 + 0x300;
    iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    *(int *)(this_03 + 0x24) = iVar10 + 0x305;
    iVar10 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar10 == 0x18) {
      this_02 = (Station *)Status::getStation(Globals::status);
      iVar10 = Station::getIndex(this_02);
      if ((iVar10 == 10) && (iVar10 = Agent::getSellItemIndex(this_03), iVar10 == 0x44)) {
        *(undefined4 *)(this_03 + 0x20) = 0xc1;
        *(undefined4 *)(this_03 + 0x24) = 0xc2;
      }
    }
    pSVar11 = (String *)GameText::getText(Globals::gameText,*(int *)(this_03 + 0x20));
    AbyssEngine::String::operator+=(aSStack_b8,pSVar11);
    AbyssEngine::String::String((String *)auStack_60,"\n",false);
    pSVar11 = (String *)GameText::getText(Globals::gameText,*(int *)(this_03 + 0x24));
    AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
    AbyssEngine::String::operator+=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String((String *)auStack_60);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_2a8,aSStack_b8,false);
    uVar12 = Agent::getSellItemQuantity(this_03);
    auStack_60[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar12,auStack_60));
    AbyssEngine::String::String(aSStack_2b0,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_2b8,"#Q",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_2a8,aSStack_2b0,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_2b8);
    AbyssEngine::String::~String(aSStack_2b0);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_2a8);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_2c0,aSStack_b8,false);
    pGVar4 = Globals::gameText;
    iVar10 = Agent::getSellItemIndex(this_03);
    pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x4fa);
    AbyssEngine::String::String(aSStack_2c8,pSVar11,false);
    uVar12 = AbyssEngine::String::String(aSStack_2d0,"#P",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_2c0,aSStack_2c8,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_2d0);
    AbyssEngine::String::~String(aSStack_2c8);
    AbyssEngine::String::~String(aSStack_2c0);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_2d8,aSStack_b8,false);
    Agent::getSellItemPrice(this_03);
    Layout::formatCredits((int)auStack_60);
    AbyssEngine::String::String(aSStack_2e0,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_2e8,"#C",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_2d8,aSStack_2e0,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_2e8);
    AbyssEngine::String::~String(aSStack_2e0);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_2d8);
    iVar10 = Agent::getSellItemQuantity(this_03);
    if (1 < iVar10) {
      AbyssEngine::String::String((String *)auStack_60," ",false);
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x307);
      AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,pSVar11);
      AbyssEngine::String::operator+=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String((String *)auStack_60);
      pSVar3 = Globals::status;
      AbyssEngine::String::String(aSStack_2f0,aSStack_b8,false);
      uVar12 = Agent::getSellItemPrice(this_03);
      uVar17 = Agent::getSellItemQuantity(this_03);
      __aeabi_idiv(uVar12,uVar17);
      Layout::formatCredits((int)auStack_60);
      AbyssEngine::String::String(aSStack_2f8,(String *)auStack_60,false);
      uVar12 = AbyssEngine::String::String(aSStack_300,"#C",false);
      Status::replaceHash(aSStack_58,pSVar3,aSStack_2f0,aSStack_2f8,uVar12);
      AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String(aSStack_300);
      AbyssEngine::String::~String(aSStack_2f8);
      AbyssEngine::String::~String((String *)auStack_60);
      pSVar19 = aSStack_2f0;
      goto LAB_0019a756;
    }
    break;
  case 5:
    pAVar15 = (Array *)Galaxy::getSystems(Globals::galaxy);
    pMVar20 = (Mission *)Generator::createMission(this_01,this_03,pAVar15);
    Agent::setMission(this_03,pMVar20);
    iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    *(int *)(this_03 + 0x20) = iVar10 + 0x309;
    pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10 + 0x309);
    AbyssEngine::String::operator+=(aSStack_b8,pSVar11);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_128,aSStack_b8,false);
    pMVar20 = (Mission *)Agent::getMission(this_03);
    uVar12 = Mission::getProductionGoodAmount(pMVar20);
    auStack_60[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar12,auStack_60));
    AbyssEngine::String::String(aSStack_130,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_138,"#Q",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_128,aSStack_130,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_138);
    AbyssEngine::String::~String(aSStack_130);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_128);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_140,aSStack_b8,false);
    pGVar4 = Globals::gameText;
    pMVar20 = (Mission *)Agent::getMission(this_03);
    iVar10 = Mission::getProductionGoodIndex(pMVar20);
    pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x4fa);
    AbyssEngine::String::String(aSStack_148,pSVar11,false);
    uVar12 = AbyssEngine::String::String(aSStack_150,"#P",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_140,aSStack_148,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_150);
    AbyssEngine::String::~String(aSStack_148);
    AbyssEngine::String::~String(aSStack_140);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_158,aSStack_b8,false);
    pMVar20 = (Mission *)Agent::getMission(this_03);
    Mission::getReward(pMVar20);
    Layout::formatCredits((int)auStack_60);
    AbyssEngine::String::String(aSStack_160,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_168,"#C",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_158,aSStack_160,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_168);
    AbyssEngine::String::~String(aSStack_160);
    AbyssEngine::String::~String((String *)auStack_60);
    pSVar19 = aSStack_158;
LAB_0019a756:
    AbyssEngine::String::~String(pSVar19);
    break;
  case 6:
    iVar10 = Achievements::gotAllMedals(Globals::achievements);
    iVar6 = Agent::getWingmanFriendsCount(this_03);
    iVar22 = 0x30b;
    if (iVar10 != 0) {
      iVar22 = 0x30e;
    }
    pSVar11 = (String *)GameText::getText(pGVar4,iVar22 + iVar6);
    AbyssEngine::String::operator+=(aSStack_b8,pSVar11);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_308,aSStack_b8,false);
    Agent::getCosts(this_03);
    Layout::formatCredits((int)auStack_60);
    AbyssEngine::String::String(aSStack_310,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_318,"#C",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_308,aSStack_310,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_318);
    AbyssEngine::String::~String(aSStack_310);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_308);
    iVar10 = Agent::getWingmanFriendsCount(this_03);
    pSVar3 = Globals::status;
    if (0 < iVar10) {
      AbyssEngine::String::String(aSStack_320,aSStack_b8,false);
      Agent::getWingmanName((int)auStack_60);
      AbyssEngine::String::String(aSStack_328,(String *)auStack_60,false);
      uVar12 = AbyssEngine::String::String(aSStack_330,"#W",false);
      Status::replaceHash(aSStack_58,pSVar3,aSStack_320,aSStack_328,uVar12);
      AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String(aSStack_330);
      AbyssEngine::String::~String(aSStack_328);
      AbyssEngine::String::~String((String *)auStack_60);
      pSVar19 = aSStack_320;
      goto LAB_0019a756;
    }
    break;
  case 7:
    uVar16 = Agent::getRace(this_03);
    pSVar21 = (Standing *)Status::getStanding(Globals::status);
    iVar10 = Standing::getStanding(pSVar21,(uint)((uVar16 | 1) == 3));
    pSVar21 = (Standing *)Status::getStanding(Globals::status);
    iVar6 = Standing::isEnemy(pSVar21,uVar16);
    if (iVar6 != 1) {
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x373);
      AbyssEngine::String::operator=(aSStack_b8,pSVar11);
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String(aSStack_120,aSStack_b8,false);
      ScrollTouchWindow::setText(pSVar8,aSStack_118,aSStack_120);
      AbyssEngine::String::~String(aSStack_120);
      AbyssEngine::String::~String(aSStack_118);
      *(undefined4 *)(this + 0x2c) = 0;
      *(undefined4 *)(this + 0x14) = 3;
      AbyssEngine::String::~String(aSStack_b8);
      AbyssEngine::String::~String(aSStack_b0);
      AbyssEngine::String::~String(aSStack_98);
      goto LAB_00198d40;
    }
    if (iVar10 < 0) {
      iVar10 = -iVar10;
    }
    iVar6 = 0x370;
    fVar28 = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
    iVar10 = 0x372;
    if (uVar16 == 2) {
      iVar6 = 0x36e;
    }
    if (uVar16 == 0) {
      iVar10 = 0x371;
    }
    if ((uVar16 | 1) == 3) {
      iVar10 = iVar6;
    }
    pSVar11 = (String *)GameText::getText(Globals::gameText,iVar10);
    AbyssEngine::String::operator=(aSStack_b8,pSVar11);
    pSVar3 = Globals::status;
    AbyssEngine::String::String(aSStack_100,aSStack_b8,false);
    Layout::formatCredits((int)auStack_60);
    AbyssEngine::String::String(aSStack_108,(String *)auStack_60,false);
    uVar12 = AbyssEngine::String::String(aSStack_110,"#C",false);
    Status::replaceHash(aSStack_58,pSVar3,aSStack_100,aSStack_108,uVar12);
    AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_110);
    AbyssEngine::String::~String(aSStack_108);
    AbyssEngine::String::~String((String *)auStack_60);
    AbyssEngine::String::~String(aSStack_100);
    Agent::setCosts(this_03,(int)((fVar28 / 100.0) * 16000.0));
  }
  pvVar7 = (void *)Generator::~Generator(this_01);
  operator_delete(pvVar7);
  iVar10 = Agent::getOffer(this_03);
  if (iVar10 == 0) {
    pMVar20 = (Mission *)Agent::getMission(this_03);
    iVar10 = Mission::getType(pMVar20);
    if (iVar10 == 8) goto LAB_0019a77a;
  }
  else {
LAB_0019a77a:
    AbyssEngine::String::String(aSStack_338,aSStack_b8,false);
    Agent::setMissionString(this_03,aSStack_338);
    AbyssEngine::String::~String(aSStack_338);
  }
  iVar10 = Agent::getOffer(this_03);
  if (iVar10 == 1) {
    pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
    Agent::getName();
    AbyssEngine::String::String(aSStack_348,aSStack_b8,false);
    ScrollTouchWindow::setText(pSVar8,aSStack_340,aSStack_348);
    AbyssEngine::String::~String(aSStack_348);
    AbyssEngine::String::~String(aSStack_340);
    Agent::setEvent(this_03,1);
  }
  else {
    iVar10 = Agent::getOffer(this_03);
    if (iVar10 == 7) {
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String(aSStack_358,aSStack_b8,false);
      ScrollTouchWindow::setText(pSVar8,aSStack_350,aSStack_358);
      AbyssEngine::String::~String(aSStack_358);
      pSVar19 = aSStack_350;
    }
    else {
      iVar10 = Agent::getMission(this_03);
      if (iVar10 != 0) {
        pMVar20 = (Mission *)Agent::getMission(this_03);
        iVar10 = Mission::getType(pMVar20);
        if (iVar10 == 0xc) {
          pSVar11 = (String *)GameText::getText(Globals::gameText,0x31e);
          AbyssEngine::String::operator=(aSStack_b8,pSVar11);
          pSVar3 = Globals::status;
          AbyssEngine::String::String(aSStack_360,aSStack_b8,false);
          pMVar20 = (Mission *)Agent::getMission(this_03);
          Mission::getReward(pMVar20);
          pMVar20 = (Mission *)Agent::getMission(this_03);
          Mission::getBonus(pMVar20);
          Layout::formatCredits((int)auStack_60);
          AbyssEngine::String::String(aSStack_368,(String *)auStack_60,false);
          uVar12 = AbyssEngine::String::String(aSStack_370,"#C",false);
          Status::replaceHash(aSStack_58,pSVar3,aSStack_360,aSStack_368,uVar12);
          AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
          AbyssEngine::String::~String(aSStack_58);
          AbyssEngine::String::~String(aSStack_370);
          AbyssEngine::String::~String(aSStack_368);
          AbyssEngine::String::~String((String *)auStack_60);
          AbyssEngine::String::~String(aSStack_360);
          AbyssEngine::String::String(aSStack_378,aSStack_b8,false);
          Agent::setMissionString(this_03,aSStack_378);
          AbyssEngine::String::~String(aSStack_378);
          AbyssEngine::String::String(aSStack_58,"\n",false);
          pGVar4 = Globals::gameText;
          iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
          pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x349);
          AbyssEngine::operator+(aAStack_380,aSStack_58,pSVar11);
          AbyssEngine::String::~String(aSStack_58);
          pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
          Agent::getName();
          AbyssEngine::operator+(aAStack_390,aSStack_b8,aAStack_380);
          ScrollTouchWindow::setText(pSVar8,aSStack_388,aAStack_390);
          AbyssEngine::String::~String((String *)aAStack_390);
          AbyssEngine::String::~String(aSStack_388);
          pSVar19 = (String *)aAStack_380;
          goto LAB_0019ac48;
        }
      }
      AbyssEngine::String::String((String *)auStack_60,"\n",false);
      AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,aSStack_b8);
      AbyssEngine::String::operator=(aSStack_b8,aSStack_58);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String((String *)auStack_60);
      AbyssEngine::String::String(aSStack_58,"\n",false);
      pGVar4 = Globals::gameText;
      iVar10 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
      pSVar11 = (String *)GameText::getText(pGVar4,iVar10 + 0x349);
      AbyssEngine::operator+(aAStack_398,aSStack_58,pSVar11);
      AbyssEngine::String::~String(aSStack_58);
      pSVar8 = *(ScrollTouchWindow **)(this + 0x60);
      Agent::getName();
      AbyssEngine::String::String((String *)aAStack_380," ",false);
      AbyssEngine::operator+(aAStack_90,(String *)&uStack_40,aAStack_380);
      AbyssEngine::operator+((AbyssEngine *)auStack_80,aAStack_90,aSStack_98);
      AbyssEngine::String::String(aSStack_3b0," ",false);
      AbyssEngine::operator+((AbyssEngine *)aSStack_68,(String *)auStack_80,aSStack_3b0);
      AbyssEngine::operator+((AbyssEngine *)auStack_60,aSStack_68,aSStack_b0);
      AbyssEngine::operator+((AbyssEngine *)aSStack_58,(String *)auStack_60,aSStack_b8);
      AbyssEngine::operator+(aAStack_3a8,aSStack_58,aAStack_398);
      ScrollTouchWindow::setText(pSVar8,aSStack_3a0,aAStack_3a8);
      AbyssEngine::String::~String((String *)aAStack_3a8);
      AbyssEngine::String::~String(aSStack_58);
      AbyssEngine::String::~String((String *)auStack_60);
      AbyssEngine::String::~String(aSStack_68);
      AbyssEngine::String::~String(aSStack_3b0);
      AbyssEngine::String::~String((String *)auStack_80);
      AbyssEngine::String::~String((String *)aAStack_90);
      AbyssEngine::String::~String((String *)aAStack_380);
      AbyssEngine::String::~String(aSStack_3a0);
      pSVar19 = (String *)aAStack_398;
    }
LAB_0019ac48:
    AbyssEngine::String::~String(pSVar19);
  }
  AbyssEngine::String::~String(aSStack_b8);
  AbyssEngine::String::~String(aSStack_b0);
  pSVar19 = aSStack_98;
LAB_0019ac60:
  AbyssEngine::String::~String(pSVar19);
  AbyssEngine::String::~String((String *)&uStack_40);
  Status::getStation(Globals::status);
  Station::getName();
  Agent::setStationName(this_03,aSStack_550);
  AbyssEngine::String::~String(aSStack_550);
  Status::getSystem(Globals::status);
  SolarSystem::getName();
  Agent::setSystemName(this_03,aSStack_558);
  AbyssEngine::String::~String(aSStack_558);
  *(undefined4 *)(this + 0x14) = 1;
  *(undefined4 *)(this + 0x2c) = 0;
  onKeyPress(this,0x10000);
  iVar10 = getSoundId(this,this_03);
  if (-1 < iVar10) {
    FModSound::play(Globals::sound,iVar10,(Vector *)0x0,(Vector *)0x0,extraout_s0_01);
  }
LAB_0019acf0:
  if (__stack_chk_guard == iStack_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== SpaceLounge::refresh  @0x0019c6f8  (2 bytes)
/* SpaceLounge::refresh() */

void SpaceLounge::refresh(void)

{
  return;
}

// ===== SpaceLounge::onKeyPress  @0x0019c6fc  (7592 bytes)
/* SpaceLounge::onKeyPress(int) */

void __thiscall SpaceLounge::onKeyPress(SpaceLounge *this,int param_1)

{
  SpaceLounge SVar1;
  ushort uVar2;
  char cVar3;
  Galaxy *this_00;
  Status *pSVar4;
  GameText *pGVar5;
  Engine *this_01;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  String *pSVar9;
  Mission *pMVar10;
  int iVar11;
  ListItemWindow *pLVar12;
  ListItem *this_02;
  Array *pAVar13;
  void *pvVar14;
  Standing *this_03;
  int *piVar15;
  uint *puVar16;
  Item *pIVar17;
  Ship *pSVar18;
  SolarSystem *this_04;
  Agent *pAVar19;
  String *pSVar20;
  int iVar21;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  Agent *pAVar22;
  Item *pIVar23;
  undefined4 uVar24;
  StarMap *pSVar25;
  Station *pSVar26;
  ScrollTouchWindow *pSVar27;
  String *pSVar28;
  bool bVar29;
  uint in_fpscr;
  float fVar30;
  float fVar31;
  float fVar32;
  String aSStack_294 [8];
  String aSStack_28c [8];
  String aSStack_284 [8];
  String aSStack_27c [8];
  String aSStack_274 [8];
  String aSStack_26c [8];
  Agent aAStack_264 [8];
  String aSStack_25c [8];
  String aSStack_254 [8];
  String aSStack_24c [8];
  String aSStack_244 [8];
  String aSStack_23c [8];
  String aSStack_234 [8];
  String aSStack_22c [8];
  String aSStack_224 [8];
  String aSStack_21c [8];
  String aSStack_214 [8];
  String aSStack_20c [8];
  String aSStack_204 [8];
  String aSStack_1fc [8];
  String aSStack_1f4 [8];
  String aSStack_1ec [8];
  String aSStack_1e4 [8];
  String aSStack_1dc [8];
  String aSStack_1d4 [8];
  String aSStack_1cc [8];
  String aSStack_1c4 [8];
  String aSStack_1bc [8];
  String aSStack_1b4 [8];
  String aSStack_1ac [8];
  String aSStack_1a4 [8];
  String aSStack_19c [8];
  String aSStack_194 [8];
  String aSStack_18c [8];
  String aSStack_184 [8];
  String aSStack_17c [8];
  String aSStack_174 [8];
  String aSStack_16c [8];
  String aSStack_164 [8];
  String aSStack_15c [8];
  String aSStack_154 [8];
  String aSStack_14c [8];
  String aSStack_144 [8];
  String aSStack_13c [8];
  String aSStack_134 [8];
  String aSStack_12c [8];
  String aSStack_124 [8];
  String aSStack_11c [8];
  String aSStack_114 [8];
  String aSStack_10c [8];
  String aSStack_104 [8];
  String aSStack_fc [8];
  String aSStack_f4 [8];
  String aSStack_ec [8];
  String aSStack_e4 [8];
  String aSStack_dc [8];
  String aSStack_d4 [8];
  String aSStack_cc [8];
  String aSStack_c4 [8];
  String aSStack_bc [8];
  String aSStack_b4 [8];
  String aSStack_ac [8];
  String aSStack_a4 [8];
  String aSStack_9c [8];
  String aSStack_94 [8];
  String aSStack_8c [8];
  String aSStack_84 [8];
  String aSStack_7c [8];
  String aSStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  undefined4 local_4c [2];
  String aSStack_44 [8];
  String aSStack_3c [8];
  int local_34;
  
  local_34 = __stack_chk_guard;
  if (this[0x1b] != (SpaceLounge)0x0) {
    if (param_1 != 0x1000) {
      if (param_1 != 0x2000) {
        if (param_1 == 0x10000) {
          this[0x1b] = (SpaceLounge)0x0;
        }
        goto switchD_0019c744_default;
      }
LAB_0019c8a6:
      ChoiceWindow::right();
      goto switchD_0019c744_default;
    }
LAB_0019c89e:
    ChoiceWindow::left();
    goto switchD_0019c744_default;
  }
  switch(*(int *)(this + 0x14)) {
  case 0:
    if (param_1 < 0x8000) {
      if (param_1 != 0x1000) {
        if ((param_1 == 0x2000 || param_1 == 0x4000) &&
           (iVar6 = *(int *)(this + 0x20), *(int *)(this + 0x20) = iVar6 + -1, iVar6 < 1)) {
          *(int *)(this + 0x20) = **(int **)(this + 0x24) + -1;
        }
        goto switchD_0019c744_default;
      }
LAB_0019c92e:
      uVar7 = *(int *)(this + 0x20) + 1;
      *(uint *)(this + 0x20) = uVar7;
      if (**(uint **)(this + 0x24) <= uVar7) {
        uVar7 = 0;
      }
      *(uint *)(this + 0x20) = uVar7;
    }
    else {
      if (param_1 < 0x20000) {
        if (param_1 == 0x8000) goto LAB_0019c92e;
        if (param_1 != 0x10000) goto switchD_0019c744_default;
      }
      else if (param_1 != 0x20000) goto switchD_0019c744_default;
      startChat(this);
    }
    goto switchD_0019c744_default;
  case 1:
  case 3:
    if (param_1 == 0x10000 || param_1 == 0x20000) {
      uVar24 = 0;
      *(undefined4 *)(this + 0x30) = 0;
      pAVar22 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4);
      iVar6 = Agent::getOffer(pAVar22);
      if (iVar6 == 1) {
        *(undefined4 *)(this + 0x14) = 2;
      }
      else {
        bVar29 = *(int *)(this + 0x14) == 1;
        if (bVar29) {
          uVar24 = 2;
        }
        *(undefined4 *)(this + 0x14) = uVar24;
        SVar1 = (SpaceLounge)0x1;
        if (!bVar29) {
          SVar1 = this[0x18];
        }
        if (!bVar29 && SVar1 != (SpaceLounge)0x0) {
          iVar6 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
          pSVar25 = *(StarMap **)(iVar6 + 0x10);
          *(StarMap **)(this + 4) = pSVar25;
          if (pSVar25 == (StarMap *)0x0) {
            pSVar25 = operator_new(0x1e8);
            iVar6 = Agent::getSellSystemIndex(pAVar22);
            StarMap::StarMap(pSVar25,false,(Mission *)0x0,true,iVar6);
            iVar6 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
            *(StarMap **)(iVar6 + 0x10) = pSVar25;
            iVar6 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
            *(undefined4 *)(this + 4) = *(undefined4 *)(iVar6 + 0x10);
          }
          else {
            iVar6 = Agent::getSellSystemIndex(pAVar22);
            StarMap::init(pSVar25,false,(Mission *)0x0,true,iVar6);
          }
          this[0x34] = (SpaceLounge)0x1;
          this[0x18] = (SpaceLounge)0x0;
        }
      }
    }
    else if (param_1 == 0x40000) {
      if (*(int *)(this + 0x2c) < 3) {
        if (*(int *)(this + 0x14) == 1) {
          *(undefined4 *)(this + 0x14) = 0;
          *(undefined4 *)(this + 0x2c) = 0;
        }
      }
      else {
        *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + -0x28;
      }
    }
    goto switchD_0019c744_default;
  case 2:
    iVar6 = Agent::getMission(*(Agent **)
                               (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
    if (iVar6 == 0) {
LAB_0019c7b8:
      iVar6 = Agent::getOffer(*(Agent **)
                               (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
      if ((((iVar6 == 2) ||
           (iVar6 = Agent::getOffer(*(Agent **)
                                     (*(int *)(*(int *)(this + 0x24) + 4) +
                                     *(int *)(this + 0x20) * 4)), iVar6 == 3)) ||
          (iVar6 = Agent::getOffer(*(Agent **)
                                    (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4
                                    )), iVar6 == 8)) ||
         ((iVar6 = Agent::getOffer(*(Agent **)
                                    (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4
                                    )), iVar6 == 9 ||
          (iVar6 = Agent::getOffer(*(Agent **)
                                    (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4
                                    )), iVar6 == 10)))) {
        iVar6 = 4;
      }
      else {
        iVar6 = 3;
      }
    }
    else {
      Agent::getMission(*(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4)
                       );
      iVar6 = Mission::isOutsideMission();
      if (iVar6 == 0) goto LAB_0019c7b8;
      iVar6 = 5;
    }
    pGVar5 = Globals::gameText;
    if (this[0x1c] != (SpaceLounge)0x0) {
      if (param_1 == 0x40000) {
        this[0x1c] = (SpaceLounge)0x0;
        this_01 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
        AbyssEngine::Engine::SetPostEffect(this_01,0x1400000,(bool)this[0xad]);
      }
      goto switchD_0019c744_default;
    }
    cVar3 = (char)&stack0xffffffdc;
    if (this[0x19] == (SpaceLounge)0x0) {
      if (param_1 < 0x10000) {
        if (param_1 == 0x4000) {
          iVar21 = *(int *)(this + 0x30);
          *(int *)(this + 0x30) = iVar21 + -1;
          if (iVar21 < 1) {
            *(int *)(this + 0x30) = iVar6 + -1;
          }
        }
        else if (param_1 == 0x8000) {
          iVar21 = *(int *)(this + 0x30) + 1;
          if (iVar6 <= iVar21) {
            iVar21 = 0;
          }
          *(int *)(this + 0x30) = iVar21;
        }
        goto switchD_0019c744_default;
      }
      if (param_1 != 0x10000 && param_1 != 0x20000) goto switchD_0019c744_default;
      if (4 < *(uint *)(this + 0x30)) goto LAB_0019e680;
      pAVar22 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4);
      switch(*(uint *)(this + 0x30)) {
      case 0:
        iVar6 = Agent::getOffer(pAVar22);
        AbyssEngine::String::String(aSStack_3c,"",false);
        switch(iVar6) {
        case 0:
        case 5:
          pMVar10 = (Mission *)Agent::getMission(pAVar22);
          iVar6 = Mission::getType(pMVar10);
          if (iVar6 != 0) {
            pMVar10 = (Mission *)Agent::getMission(pAVar22);
            iVar6 = Mission::getType(pMVar10);
            if (iVar6 == 0xb) {
              pMVar10 = (Mission *)Agent::getMission(pAVar22);
              iVar6 = Mission::getProductionGoodAmount(pMVar10);
              pSVar18 = (Ship *)Status::getShip(Globals::status);
              iVar21 = Ship::getMaxPassengers(pSVar18);
              if (iVar21 < iVar6) {
                pSVar9 = (String *)GameText::getText(Globals::gameText,0x152);
                AbyssEngine::String::operator=(aSStack_3c,pSVar9);
                pSVar4 = Globals::status;
                AbyssEngine::String::String(aSStack_cc,aSStack_3c,false);
                local_4c[0] = 0;
                AbyssEngine::String::Set(CONCAT44(extraout_r1,local_4c));
                AbyssEngine::String::String(aSStack_d4,(String *)local_4c,false);
                uVar24 = AbyssEngine::String::String(aSStack_dc,"#Q",false);
                Status::replaceHash(aSStack_44,pSVar4,aSStack_cc,aSStack_d4,uVar24);
                AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
                AbyssEngine::String::~String(aSStack_44);
                AbyssEngine::String::~String(aSStack_dc);
                AbyssEngine::String::~String(aSStack_d4);
                AbyssEngine::String::~String((String *)local_4c);
                pSVar20 = aSStack_cc;
                goto LAB_0019e2c4;
              }
            }
LAB_0019dc66:
            iVar6 = Agent::isGenericAgent(pAVar22);
            if (iVar6 == 1) {
              pSVar9 = (String *)GameText::getText(Globals::gameText,0x361);
              AbyssEngine::String::operator=(aSStack_3c,pSVar9);
              pSVar4 = Globals::status;
              AbyssEngine::String::String(aSStack_e4,aSStack_3c,false);
              pMVar10 = (Mission *)Agent::getMission(pAVar22);
              Mission::getReward(pMVar10);
              pMVar10 = (Mission *)Agent::getMission(pAVar22);
              Mission::getBonus(pMVar10);
              Layout::formatCredits((int)local_4c);
              AbyssEngine::String::String(aSStack_ec,(String *)local_4c,false);
              uVar24 = AbyssEngine::String::String(aSStack_f4,"#C",false);
              Status::replaceHash(aSStack_44,pSVar4,aSStack_e4,aSStack_ec,uVar24);
              AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
              AbyssEngine::String::~String(aSStack_44);
              AbyssEngine::String::~String(aSStack_f4);
              AbyssEngine::String::~String(aSStack_ec);
              AbyssEngine::String::~String((String *)local_4c);
              AbyssEngine::String::~String(aSStack_e4);
              pSVar4 = Globals::status;
              AbyssEngine::String::String(aSStack_fc,aSStack_3c,false);
              pGVar5 = Globals::gameText;
              pMVar10 = (Mission *)Agent::getMission(pAVar22);
              iVar6 = Mission::getType(pMVar10);
              pSVar9 = (String *)GameText::getText(pGVar5,iVar6 + 0x162);
              AbyssEngine::String::String(aSStack_104,pSVar9,false);
              uVar24 = AbyssEngine::String::String(aSStack_10c,"#M",false);
              Status::replaceHash(aSStack_44,pSVar4,aSStack_fc,aSStack_104,uVar24);
              AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
              AbyssEngine::String::~String(aSStack_44);
              AbyssEngine::String::~String(aSStack_10c);
              AbyssEngine::String::~String(aSStack_104);
              AbyssEngine::String::~String(aSStack_fc);
            }
            else {
              pSVar9 = (String *)GameText::getText(Globals::gameText,0x35f);
              AbyssEngine::String::operator=(aSStack_3c,pSVar9);
            }
            pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
            if ((pMVar10 != (Mission *)0x0) && (iVar6 = Mission::isEmpty(pMVar10), iVar6 == 0)) {
              AbyssEngine::String::String((String *)local_4c," ",false);
              pSVar9 = (String *)GameText::getText(Globals::gameText,0x360);
              AbyssEngine::operator+((AbyssEngine *)aSStack_44,(String *)local_4c,pSVar9);
              AbyssEngine::String::operator+=(aSStack_3c,aSStack_44);
              AbyssEngine::String::~String(aSStack_44);
              pSVar20 = (String *)local_4c;
              break;
            }
            goto switchD_0019c9b0_default;
          }
          pMVar10 = (Mission *)Agent::getMission(pAVar22);
          iVar6 = Mission::getProductionGoodAmount(pMVar10);
          pSVar18 = (Ship *)Status::getShip(Globals::status);
          iVar6 = Ship::spaceAvailable(pSVar18,iVar6);
          if (iVar6 != 0) goto LAB_0019dc66;
          pSVar9 = (String *)GameText::getText(Globals::gameText,0x151);
          AbyssEngine::String::operator=(aSStack_3c,pSVar9);
          pSVar4 = Globals::status;
          AbyssEngine::String::String(aSStack_b4,aSStack_3c,false);
          local_4c[0] = 0;
          AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_4c));
          AbyssEngine::String::String(aSStack_bc,(String *)local_4c,false);
          uVar24 = AbyssEngine::String::String(aSStack_c4,"#Q",false);
          Status::replaceHash(aSStack_44,pSVar4,aSStack_b4,aSStack_bc,uVar24);
          AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
          AbyssEngine::String::~String(aSStack_44);
          AbyssEngine::String::~String(aSStack_c4);
          AbyssEngine::String::~String(aSStack_bc);
          AbyssEngine::String::~String((String *)local_4c);
          pSVar20 = aSStack_b4;
LAB_0019e2c4:
          AbyssEngine::String::~String(pSVar20);
          ChoiceWindow::set(*(String **)(this + 8),(bool)(cVar3 + -0x18));
          this[0x1b] = (SpaceLounge)0x1;
          goto LAB_0019e67a;
        case 1:
          *(undefined4 *)(this + 0x14) = 0;
LAB_0019caf0:
          AbyssEngine::String::~String(aSStack_3c);
          goto switchD_0019c744_default;
        case 2:
        case 3:
        case 4:
        case 8:
        case 9:
        case 10:
          fVar30 = 1.0;
          if (Globals::options[0x38] == '\0') {
            fVar30 = 2.0;
          }
          fVar32 = 1.0;
          if (iVar6 - 8U < 3) {
            fVar32 = fVar30;
          }
          uVar24 = Status::getCredits(Globals::status);
          uVar8 = Agent::getSellItemPrice(pAVar22);
          pSVar4 = Globals::status;
          fVar30 = (float)VectorSignedToFloat(uVar8,(byte)(in_fpscr >> 0x16) & 3);
          fVar31 = (float)VectorSignedToFloat(uVar24,(byte)(in_fpscr >> 0x16) & 3);
          in_fpscr = in_fpscr & 0xfffffff;
          if (fVar31 < fVar32 * fVar30) {
            pSVar28 = *(String **)(this + 8);
            pSVar9 = (String *)GameText::getText(Globals::gameText,0xcb);
            AbyssEngine::String::String(aSStack_114,pSVar9,false);
            uVar24 = Agent::getSellItemPrice(pAVar22);
            uVar8 = Status::getCredits(Globals::status);
            VectorSignedToFloat(uVar24,(byte)(in_fpscr >> 0x16) & 3);
            VectorSignedToFloat(uVar8,(byte)(in_fpscr >> 0x16) & 3);
            Layout::formatCredits((int)local_4c);
            AbyssEngine::String::String(aSStack_11c,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_124,"#C",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_114,aSStack_11c,uVar24);
            ChoiceWindow::set(pSVar28,(bool)(cVar3 + -0x20));
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_124);
            AbyssEngine::String::~String(aSStack_11c);
            AbyssEngine::String::~String((String *)local_4c);
            pSVar20 = aSStack_114;
LAB_0019cae8:
            AbyssEngine::String::~String(pSVar20);
LAB_0019caec:
            this[0x1b] = (SpaceLounge)0x1;
            goto LAB_0019caf0;
          }
          switch(iVar6) {
          case 2:
          case 9:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x364);
            AbyssEngine::String::operator=(aSStack_3c,pSVar9);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_1bc,aSStack_3c,false);
            uVar24 = Agent::getSellItemQuantity(pAVar22);
            local_4c[0] = 0;
            AbyssEngine::String::Set(CONCAT44(uVar24,local_4c));
            AbyssEngine::String::String(aSStack_1c4,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_1cc,"#Q",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_1bc,aSStack_1c4,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_1cc);
            AbyssEngine::String::~String(aSStack_1c4);
            AbyssEngine::String::~String((String *)local_4c);
            AbyssEngine::String::~String(aSStack_1bc);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_1d4,aSStack_3c,false);
            pGVar5 = Globals::gameText;
            iVar6 = Agent::getSellItemIndex(pAVar22);
            pSVar9 = (String *)GameText::getText(pGVar5,iVar6 + 0x4fa);
            AbyssEngine::String::String(aSStack_1dc,pSVar9,false);
            uVar24 = AbyssEngine::String::String(aSStack_1e4,"#P",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_1d4,aSStack_1dc,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_1e4);
            AbyssEngine::String::~String(aSStack_1dc);
            AbyssEngine::String::~String(aSStack_1d4);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_1ec,aSStack_3c,false);
            uVar24 = Agent::getSellItemPrice(pAVar22);
            VectorSignedToFloat(uVar24,(byte)(in_fpscr >> 0x16) & 3);
            Layout::formatCredits((int)local_4c);
            AbyssEngine::String::String(aSStack_1f4,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_1fc,"#C",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_1ec,aSStack_1f4,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_1fc);
            AbyssEngine::String::~String(aSStack_1f4);
            AbyssEngine::String::~String((String *)local_4c);
            pSVar20 = aSStack_1ec;
            break;
          case 3:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x365);
            AbyssEngine::String::operator=(aSStack_3c,pSVar9);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_15c,aSStack_3c,false);
            iVar6 = Globals::items;
            pGVar5 = Globals::gameText;
            iVar21 = Agent::getSellBlueprintIndex(pAVar22);
            iVar6 = Item::getIndex(*(Item **)(*(int *)(iVar6 + 4) + iVar21 * 4));
            pSVar9 = (String *)GameText::getText(pGVar5,iVar6 + 0x4fa);
            AbyssEngine::String::String(aSStack_164,pSVar9,false);
            uVar24 = AbyssEngine::String::String(aSStack_16c,"#P",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_15c,aSStack_164,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_16c);
            AbyssEngine::String::~String(aSStack_164);
            AbyssEngine::String::~String(aSStack_15c);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_174,aSStack_3c,false);
            Agent::getSellItemPrice(pAVar22);
            Layout::formatCredits((int)local_4c);
            AbyssEngine::String::String(aSStack_17c,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_184,"#C",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_174,aSStack_17c,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_184);
            AbyssEngine::String::~String(aSStack_17c);
            AbyssEngine::String::~String((String *)local_4c);
            pSVar20 = aSStack_174;
            break;
          case 4:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x366);
            AbyssEngine::String::operator=(aSStack_3c,pSVar9);
            this_00 = Globals::galaxy;
            iVar6 = Agent::getSellSystemIndex(pAVar22);
            Galaxy::getSystem(this_00,iVar6);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_18c,aSStack_3c,false);
            SolarSystem::getName();
            AbyssEngine::String::String(aSStack_194,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_19c,"#S",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_18c,aSStack_194,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_19c);
            AbyssEngine::String::~String(aSStack_194);
            AbyssEngine::String::~String((String *)local_4c);
            AbyssEngine::String::~String(aSStack_18c);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_1a4,aSStack_3c,false);
            Agent::getSellItemPrice(pAVar22);
            Layout::formatCredits((int)local_4c);
            AbyssEngine::String::String(aSStack_1ac,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_1b4,"#C",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_1a4,aSStack_1ac,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_1b4);
            AbyssEngine::String::~String(aSStack_1ac);
            AbyssEngine::String::~String((String *)local_4c);
            pSVar20 = aSStack_1a4;
            break;
          default:
            goto switchD_0019c9b0_default;
          case 8:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x367);
            AbyssEngine::String::operator=(aSStack_3c,pSVar9);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_12c,aSStack_3c,false);
            uVar24 = Agent::getSellItemPrice(pAVar22);
            VectorSignedToFloat(uVar24,(byte)(in_fpscr >> 0x16) & 3);
            Layout::formatCredits((int)local_4c);
            AbyssEngine::String::String(aSStack_134,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_13c,"#C",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_12c,aSStack_134,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_13c);
            AbyssEngine::String::~String(aSStack_134);
            AbyssEngine::String::~String((String *)local_4c);
            pSVar20 = aSStack_12c;
            break;
          case 10:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x369);
            AbyssEngine::String::operator=(aSStack_3c,pSVar9);
            pSVar4 = Globals::status;
            AbyssEngine::String::String(aSStack_144,aSStack_3c,false);
            uVar24 = Agent::getSellItemPrice(pAVar22);
            VectorSignedToFloat(uVar24,(byte)(in_fpscr >> 0x16) & 3);
            Layout::formatCredits((int)local_4c);
            AbyssEngine::String::String(aSStack_14c,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_154,"#C",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_144,aSStack_14c,uVar24);
            AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_154);
            AbyssEngine::String::~String(aSStack_14c);
            AbyssEngine::String::~String((String *)local_4c);
            pSVar20 = aSStack_144;
          }
          break;
        case 6:
          iVar6 = Achievements::gotAllMedals(Globals::achievements);
          if (iVar6 == 0) {
            iVar6 = Status::getCredits(Globals::status);
            iVar21 = Agent::getCosts(pAVar22);
            pSVar4 = Globals::status;
            if (iVar6 < iVar21) {
              pSVar28 = *(String **)(this + 8);
              pSVar9 = (String *)GameText::getText(Globals::gameText,0xcb);
              AbyssEngine::String::String(aSStack_204,pSVar9,false);
              Agent::getCosts(pAVar22);
              Status::getCredits(Globals::status);
              Layout::formatCredits((int)local_4c);
              AbyssEngine::String::String(aSStack_20c,(String *)local_4c,false);
              uVar24 = AbyssEngine::String::String(aSStack_214,"#C",false);
              Status::replaceHash(aSStack_44,pSVar4,aSStack_204,aSStack_20c,uVar24);
              ChoiceWindow::set(pSVar28,(bool)(cVar3 + -0x20));
              AbyssEngine::String::~String(aSStack_44);
              AbyssEngine::String::~String(aSStack_214);
              AbyssEngine::String::~String(aSStack_20c);
              AbyssEngine::String::~String((String *)local_4c);
              pSVar20 = aSStack_204;
              goto LAB_0019cae8;
            }
          }
          iVar6 = Status::getWingmen(Globals::status);
          pGVar5 = Globals::gameText;
          if (iVar6 != 0) {
            pSVar9 = *(String **)(this + 8);
            bVar29 = (bool)GameText::getText(Globals::gameText,0x311);
            ChoiceWindow::set(pSVar9,bVar29);
            goto LAB_0019caec;
          }
          iVar6 = Achievements::gotAllMedals(Globals::achievements);
          iVar21 = 0x362;
          if (iVar6 != 0) {
            iVar21 = 0x363;
          }
          pSVar9 = (String *)GameText::getText(pGVar5,iVar21);
          AbyssEngine::String::operator=(aSStack_3c,pSVar9);
          pSVar4 = Globals::status;
          AbyssEngine::String::String(aSStack_21c,aSStack_3c,false);
          Agent::getWingmanFriendsCount(pAVar22);
          local_4c[0] = 0;
          AbyssEngine::String::Set(ZEXT48(local_4c));
          AbyssEngine::String::String(aSStack_224,(String *)local_4c,false);
          uVar24 = AbyssEngine::String::String(aSStack_22c,"#Q",false);
          Status::replaceHash(aSStack_44,pSVar4,aSStack_21c,aSStack_224,uVar24);
          AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
          AbyssEngine::String::~String(aSStack_44);
          AbyssEngine::String::~String(aSStack_22c);
          AbyssEngine::String::~String(aSStack_224);
          AbyssEngine::String::~String((String *)local_4c);
          AbyssEngine::String::~String(aSStack_21c);
          pSVar4 = Globals::status;
          AbyssEngine::String::String(aSStack_234,aSStack_3c,false);
          Agent::getCosts(pAVar22);
          Layout::formatCredits((int)local_4c);
          AbyssEngine::String::String(aSStack_23c,(String *)local_4c,false);
          uVar24 = AbyssEngine::String::String(aSStack_244,"#C",false);
          Status::replaceHash(aSStack_44,pSVar4,aSStack_234,aSStack_23c,uVar24);
          AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
          AbyssEngine::String::~String(aSStack_44);
          AbyssEngine::String::~String(aSStack_244);
          AbyssEngine::String::~String(aSStack_23c);
          AbyssEngine::String::~String((String *)local_4c);
          pSVar20 = aSStack_234;
          break;
        case 7:
          iVar6 = Status::getCredits(Globals::status);
          iVar21 = Agent::getCosts(pAVar22);
          pSVar4 = Globals::status;
          if (iVar6 < iVar21) {
            pSVar28 = *(String **)(this + 8);
            pSVar9 = (String *)GameText::getText(Globals::gameText,0xcb);
            AbyssEngine::String::String(aSStack_84,pSVar9,false);
            Agent::getCosts(pAVar22);
            Status::getCredits(Globals::status);
            Layout::formatCredits((int)local_4c);
            AbyssEngine::String::String(aSStack_8c,(String *)local_4c,false);
            uVar24 = AbyssEngine::String::String(aSStack_94,"#C",false);
            Status::replaceHash(aSStack_44,pSVar4,aSStack_84,aSStack_8c,uVar24);
            ChoiceWindow::set(pSVar28,(bool)(cVar3 + -0x20));
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_94);
            AbyssEngine::String::~String(aSStack_8c);
            AbyssEngine::String::~String((String *)local_4c);
            pSVar20 = aSStack_84;
            goto LAB_0019cae8;
          }
          pSVar9 = (String *)GameText::getText(Globals::gameText,0x375);
          AbyssEngine::String::operator=(aSStack_3c,pSVar9);
          pSVar4 = Globals::status;
          AbyssEngine::String::String(aSStack_9c,aSStack_3c,false);
          Agent::getCosts(pAVar22);
          Layout::formatCredits((int)local_4c);
          AbyssEngine::String::String(aSStack_a4,(String *)local_4c,false);
          uVar24 = AbyssEngine::String::String(aSStack_ac,"#C",false);
          Status::replaceHash(aSStack_44,pSVar4,aSStack_9c,aSStack_a4,uVar24);
          AbyssEngine::String::operator=(aSStack_3c,aSStack_44);
          AbyssEngine::String::~String(aSStack_44);
          AbyssEngine::String::~String(aSStack_ac);
          AbyssEngine::String::~String(aSStack_a4);
          AbyssEngine::String::~String((String *)local_4c);
          pSVar20 = aSStack_9c;
          break;
        default:
          goto switchD_0019c9b0_default;
        }
        AbyssEngine::String::~String(pSVar20);
switchD_0019c9b0_default:
        ChoiceWindow::set(*(String **)(this + 8),(bool)(cVar3 + -0x18));
        this[0x19] = (SpaceLounge)0x1;
LAB_0019e67a:
        AbyssEngine::String::~String(aSStack_3c);
        break;
      case 1:
        pSVar27 = *(ScrollTouchWindow **)(this + 0x60);
        Agent::getName();
        pGVar5 = Globals::gameText;
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
        pSVar9 = (String *)GameText::getText(pGVar5,iVar6 + 0x34d);
        AbyssEngine::String::String(aSStack_254,pSVar9,false);
        ScrollTouchWindow::setText(pSVar27,aSStack_24c,aSStack_254);
        AbyssEngine::String::~String(aSStack_254);
        AbyssEngine::String::~String(aSStack_24c);
        *(undefined4 *)(this + 0x14) = 3;
        *(undefined4 *)(this + 0x2c) = 0;
        *(int *)(Globals::status + 0xe0) = *(int *)(Globals::status + 0xe0) + 1;
        break;
      case 2:
        *(undefined4 *)(this + 0x14) = 2;
        pSVar27 = *(ScrollTouchWindow **)(this + 0x60);
        Agent::getName();
        Globals::getAgentMissionText(aAStack_264);
        ScrollTouchWindow::setText(pSVar27,aSStack_25c,aAStack_264);
        AbyssEngine::String::~String((String *)aAStack_264);
        AbyssEngine::String::~String(aSStack_25c);
        *(undefined4 *)(this + 0x2c) = 0;
        *(int *)(Globals::status + 0xe4) = *(int *)(Globals::status + 0xe4) + 1;
        break;
      case 3:
        iVar6 = Agent::getOffer(pAVar22);
        if ((iVar6 != 2) &&
           (iVar6 = Agent::getOffer(*(Agent **)
                                     (*(int *)(*(int *)(this + 0x24) + 4) +
                                     *(int *)(this + 0x20) * 4)), iVar6 != 3)) {
          pAVar22 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4);
          pAVar22[0x1d] = (Agent)0x1;
          pMVar10 = (Mission *)Agent::getMission(pAVar22);
          iVar6 = Mission::getTargetStation(pMVar10);
          pSVar26 = (Station *)Status::getStation(Globals::status);
          iVar21 = Station::getIndex(pSVar26);
          if (iVar6 == iVar21) {
            pSVar27 = *(ScrollTouchWindow **)(this + 0x60);
            Agent::getName();
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x325);
            AbyssEngine::String::String(aSStack_274,pSVar9,false);
            ScrollTouchWindow::setText(pSVar27,aSStack_26c,aSStack_274);
            AbyssEngine::String::~String(aSStack_274);
            pSVar20 = aSStack_26c;
          }
          else {
            this_04 = (SolarSystem *)Status::getSystem(Globals::status);
            pMVar10 = (Mission *)
                      Agent::getMission(*(Agent **)
                                         (*(int *)(*(int *)(this + 0x24) + 4) +
                                         *(int *)(this + 0x20) * 4));
            iVar6 = Mission::getTargetStation(pMVar10);
            iVar6 = SolarSystem::stationIsInSystem(this_04,iVar6);
            if (iVar6 != 1) {
              iVar6 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
              pSVar25 = *(StarMap **)(iVar6 + 0x10);
              *(StarMap **)(this + 4) = pSVar25;
              if (pSVar25 == (StarMap *)0x0) {
                pSVar25 = operator_new(0x1e8);
                pMVar10 = (Mission *)
                          Agent::getMission(*(Agent **)
                                             (*(int *)(*(int *)(this + 0x24) + 4) +
                                             *(int *)(this + 0x20) * 4));
                StarMap::StarMap(pSVar25,true,pMVar10,false,-1);
                iVar6 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5)
                ;
                *(StarMap **)(iVar6 + 0x10) = pSVar25;
                iVar6 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5)
                ;
                *(undefined4 *)(this + 4) = *(undefined4 *)(iVar6 + 0x10);
              }
              else {
                pMVar10 = (Mission *)
                          Agent::getMission(*(Agent **)
                                             (*(int *)(*(int *)(this + 0x24) + 4) +
                                             *(int *)(this + 0x20) * 4));
                StarMap::init(pSVar25,true,pMVar10,false,-1);
              }
              this[0x34] = (SpaceLounge)0x1;
              break;
            }
            pSVar27 = *(ScrollTouchWindow **)(this + 0x60);
            Agent::getName();
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x326);
            AbyssEngine::String::String(aSStack_284,pSVar9,false);
            ScrollTouchWindow::setText(pSVar27,aSStack_27c,aSStack_284);
            AbyssEngine::String::~String(aSStack_284);
            pSVar20 = aSStack_27c;
          }
          goto LAB_0019cd32;
        }
        if (*(int *)(this + 0xc) == 0) {
          pLVar12 = operator_new(0x134);
          ListItemWindow::ListItemWindow(pLVar12);
          *(ListItemWindow **)(this + 0xc) = pLVar12;
        }
        iVar6 = Agent::getOffer(*(Agent **)
                                 (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
        if (iVar6 == 2) {
          pLVar12 = *(ListItemWindow **)(this + 0xc);
          this_02 = operator_new(0x48);
          iVar6 = Globals::items;
          iVar21 = Agent::getSellItemIndex
                             (*(Agent **)
                               (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
          ::ListItem::ListItem(this_02,*(Item **)(*(int *)(iVar6 + 4) + iVar21 * 4));
LAB_0019da1c:
          ListItemWindow::set(pLVar12,this_02,0,0,0,0,false);
        }
        else {
          piVar15 = (int *)Status::getBluePrints(Globals::status);
          if (*piVar15 != 0) {
            uVar7 = 0;
            do {
              iVar6 = Status::getBluePrints(Globals::status);
              iVar6 = BluePrint::getIndex(*(BluePrint **)(*(int *)(iVar6 + 4) + uVar7 * 4));
              iVar21 = Agent::getSellBlueprintIndex
                                 (*(Agent **)
                                   (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4)
                                 );
              if (iVar6 == iVar21) {
                pLVar12 = *(ListItemWindow **)(this + 0xc);
                this_02 = operator_new(0x48);
                iVar6 = Globals::items;
                iVar21 = Status::getBluePrints(Globals::status);
                iVar21 = BluePrint::getIndex(*(BluePrint **)(*(int *)(iVar21 + 4) + uVar7 * 4));
                ::ListItem::ListItem(this_02,*(Item **)(*(int *)(iVar6 + 4) + iVar21 * 4));
                goto LAB_0019da1c;
              }
              puVar16 = (uint *)Status::getBluePrints(Globals::status);
              uVar7 = uVar7 + 1;
            } while (uVar7 < *puVar16);
          }
        }
        this[0x1c] = (SpaceLounge)0x1;
        break;
      case 4:
        pAVar22[0x1c] = (Agent)0x1;
        pMVar10 = (Mission *)Agent::getMission(pAVar22);
        uVar24 = Mission::getDifficulty(pMVar10);
        pSVar27 = *(ScrollTouchWindow **)(this + 0x60);
        Agent::getName();
        fVar30 = (float)VectorSignedToFloat(uVar24,(byte)(in_fpscr >> 0x16) & 3);
        pSVar9 = (String *)GameText::getText(Globals::gameText,(int)((fVar30 / 10.0) * 5.0) + 0x328)
        ;
        AbyssEngine::String::String(aSStack_294,pSVar9,false);
        ScrollTouchWindow::setText(pSVar27,aSStack_28c,aSStack_294);
        AbyssEngine::String::~String(aSStack_294);
        pSVar20 = aSStack_28c;
LAB_0019cd32:
        AbyssEngine::String::~String(pSVar20);
        *(undefined4 *)(this + 0x14) = 2;
        *(undefined4 *)(this + 0x2c) = 0;
      }
LAB_0019e680:
      iVar6 = Agent::isGenericAgent
                        (*(Agent **)
                          (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
      if (iVar6 == 1) {
        Agent::setEvent(*(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4)
                        ,1);
      }
      goto switchD_0019c744_default;
    }
    if (param_1 != 0x10000) {
      if (param_1 == 0x2000) goto LAB_0019c8a6;
      if (param_1 != 0x1000) goto switchD_0019c744_default;
      goto LAB_0019c89e;
    }
    break;
  default:
    goto switchD_0019c744_default;
  }
  iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
  pSVar9 = (String *)GameText::getText(pGVar5,iVar6 + 0x352);
  AbyssEngine::String::String(aSStack_3c,pSVar9,false);
  pAVar22 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4);
  uVar24 = Agent::getOffer(pAVar22);
  pSVar4 = Globals::status;
  switch(uVar24) {
  case 0:
  case 5:
    iVar6 = Status::hardCoreMode();
    if (iVar6 == 1) {
      pMVar10 = (Mission *)Agent::getMission(pAVar22);
      iVar6 = Mission::getReward(pMVar10);
      pMVar10 = (Mission *)Agent::getMission(pAVar22);
      iVar21 = Mission::getBonus(pMVar10);
      iVar11 = Status::getCredits(Globals::status);
      iVar6 = (iVar21 + iVar6) / 10;
      if (iVar11 < iVar6) {
        pSVar9 = (String *)GameText::getText(Globals::gameText,0xcb);
        AbyssEngine::String::String(aSStack_44,pSVar9,false);
        pSVar4 = Globals::status;
        AbyssEngine::String::String(aSStack_54,aSStack_44,false);
        Status::getCredits(Globals::status);
        Layout::formatCredits((int)aSStack_64);
        AbyssEngine::String::String(aSStack_5c,aSStack_64,false);
        uVar24 = AbyssEngine::String::String(aSStack_6c,"#C",false);
        Status::replaceHash(local_4c,pSVar4,aSStack_54,aSStack_5c,uVar24);
        AbyssEngine::String::operator=(aSStack_44,(String *)local_4c);
        AbyssEngine::String::~String((String *)local_4c);
        AbyssEngine::String::~String(aSStack_6c);
        AbyssEngine::String::~String(aSStack_5c);
        AbyssEngine::String::~String(aSStack_64);
        AbyssEngine::String::~String(aSStack_54);
        ChoiceWindow::set(*(String **)(this + 8),(bool)(cVar3 + -0x20));
        this[0x1b] = (SpaceLounge)0x1;
        this[0x19] = (SpaceLounge)0x0;
        AbyssEngine::String::~String(aSStack_44);
        AbyssEngine::String::~String(aSStack_3c);
        goto switchD_0019c744_default;
      }
      Status::changeCredits(Globals::status,-iVar6);
    }
    iVar6 = Status::getFreelanceMission(Globals::status);
    if (iVar6 != 0) {
      pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
      iVar6 = Mission::isEmpty(pMVar10);
      if (iVar6 == 0) {
        pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
        iVar6 = Mission::getType(pMVar10);
        if (iVar6 == 0) {
LAB_0019d2e0:
          pSVar18 = (Ship *)Status::getShip(Globals::status);
          puVar16 = (uint *)Ship::getCargo(pSVar18);
          if ((puVar16 != (uint *)0x0) && (*puVar16 != 0)) {
            uVar7 = 0;
            do {
              iVar6 = Item::isUnsaleable(*(Item **)(puVar16[1] + uVar7 * 4));
              if ((iVar6 == 1) &&
                 (iVar6 = Item::getIndex(*(Item **)(puVar16[1] + uVar7 * 4)), iVar6 == 0x74)) {
                pSVar18 = (Ship *)Status::getShip(Globals::status);
                Ship::removeCargo(pSVar18,*(Item **)(puVar16[1] + uVar7 * 4));
                this[0x35] = (SpaceLounge)0x1;
                break;
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 < *puVar16);
          }
        }
        else {
          pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
          iVar6 = Mission::getType(pMVar10);
          if (iVar6 == 3) goto LAB_0019d2e0;
          pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
          iVar6 = Mission::getType(pMVar10);
          if (iVar6 == 5) goto LAB_0019d2e0;
          pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
          iVar6 = Mission::getType(pMVar10);
          if (iVar6 == 0xb) {
            Status::setPassengers(Globals::status,0);
          }
        }
        pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
        pAVar19 = (Agent *)Mission::getAgent(pMVar10);
        iVar6 = Agent::isGenericAgent(pAVar19);
        if (iVar6 == 0) {
          pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
          pAVar19 = (Agent *)Mission::getAgent(pMVar10);
          Agent::setOfferAccepted(pAVar19,false);
        }
        Status::setFreelanceMission(Globals::status,Mission::empty);
      }
    }
    pMVar10 = (Mission *)Agent::getMission(pAVar22);
    iVar6 = Mission::getType(pMVar10);
    if (iVar6 == 0) {
      pIVar23 = *(Item **)(*(int *)(Globals::items + 4) + 0x1d0);
      pMVar10 = (Mission *)Agent::getMission(pAVar22);
      iVar6 = Mission::getProductionGoodAmount(pMVar10);
      pIVar23 = (Item *)Item::makeItem(pIVar23,iVar6);
      Item::setUnsaleable(pIVar23,true);
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      Ship::addCargo(pSVar18,pIVar23);
    }
    else {
      pMVar10 = (Mission *)Agent::getMission(pAVar22);
      iVar6 = Mission::getType(pMVar10);
      pSVar4 = Globals::status;
      if (iVar6 == 0xb) {
        pMVar10 = (Mission *)Agent::getMission(pAVar22);
        iVar6 = Mission::getProductionGoodAmount(pMVar10);
        Status::setPassengers(pSVar4,iVar6);
      }
    }
    pMVar10 = (Mission *)Agent::getMission(pAVar22);
    iVar6 = Mission::getType(pMVar10);
    if (iVar6 == 0xc) {
      pSVar9 = (String *)GameText::getText(Globals::gameText,0x358);
      AbyssEngine::String::operator=(aSStack_3c,pSVar9);
    }
    else {
      AbyssEngine::String::String((String *)local_4c," ",false);
      pGVar5 = Globals::gameText;
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,3);
      pSVar9 = (String *)GameText::getText(pGVar5,iVar6 + 0x355);
      AbyssEngine::operator+((AbyssEngine *)aSStack_44,(String *)local_4c,pSVar9);
      AbyssEngine::String::operator+=(aSStack_3c,aSStack_44);
      AbyssEngine::String::~String(aSStack_44);
      AbyssEngine::String::~String((String *)local_4c);
    }
    Agent::getMission(pAVar22);
    iVar6 = Mission::isOutsideMission();
    if (iVar6 == 1) {
      uVar2 = *(ushort *)(pAVar22 + 0x1c);
      if ((uVar2 & 0xff) == 0) {
        *(int *)(Globals::status + 0xe8) = *(int *)(Globals::status + 0xe8) + 1;
      }
      if (uVar2 < 0x100) {
        *(int *)(Globals::status + 0xec) = *(int *)(Globals::status + 0xec) + 1;
      }
    }
    pSVar4 = Globals::status;
    pMVar10 = (Mission *)Agent::getMission(pAVar22);
    Status::setFreelanceMission(pSVar4,pMVar10);
    pMVar10 = (Mission *)Status::getFreelanceMission(Globals::status);
    Mission::setAgent(pMVar10,pAVar22);
    init(this);
    break;
  default:
    goto switchD_0019cb3c_caseD_1;
  case 2:
    iVar6 = Agent::getSellItemPrice(pAVar22);
    Status::changeCredits(pSVar4,-iVar6);
    iVar6 = Globals::items;
    iVar21 = Agent::getSellItemIndex(pAVar22);
    pIVar23 = *(Item **)(*(int *)(iVar6 + 4) + iVar21 * 4);
    iVar6 = Agent::getSellItemQuantity(pAVar22);
    pIVar23 = (Item *)Item::makeItem(pIVar23,iVar6);
    iVar6 = Item::getType(pIVar23);
    if (iVar6 == 1) {
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      puVar16 = (uint *)Ship::getEquipment(pSVar18);
      uVar7 = 0;
      if (puVar16 != (uint *)0x0) {
        uVar7 = *puVar16;
      }
      if (puVar16 == (uint *)0x0 || uVar7 == 0) goto LAB_0019cf34;
      bVar29 = false;
      uVar7 = 0;
      do {
        pIVar17 = *(Item **)(puVar16[1] + uVar7 * 4);
        if (pIVar17 != (Item *)0x0) {
          iVar6 = Item::getIndex(pIVar17);
          iVar21 = Item::getIndex(pIVar23);
          if (iVar6 == iVar21) {
            pIVar17 = *(Item **)(puVar16[1] + uVar7 * 4);
            iVar6 = Item::getAmount(pIVar23);
            Item::changeAmount(pIVar17,iVar6);
            bVar29 = true;
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *puVar16);
      if (!bVar29) goto LAB_0019cf34;
    }
    else {
LAB_0019cf34:
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      Ship::addCargo(pSVar18,pIVar23);
    }
    iVar6 = Agent::getSellItemIndex(pAVar22);
    if ((0x83 < iVar6) && (iVar6 = Agent::getSellItemIndex(pAVar22), iVar6 < 0x9a)) {
      iVar21 = *(int *)(Globals::status + 0xac);
      iVar6 = Agent::getSellItemIndex(pAVar22);
      *(undefined1 *)(iVar6 + *(int *)(iVar21 + 4) + -0x84) = 1;
    }
    break;
  case 3:
    iVar6 = Agent::getSellItemPrice(pAVar22);
    Status::changeCredits(pSVar4,-iVar6);
    for (uVar7 = 0; puVar16 = (uint *)Status::getBluePrints(Globals::status), uVar7 < *puVar16;
        uVar7 = uVar7 + 1) {
      iVar6 = Status::getBluePrints(Globals::status);
      iVar6 = BluePrint::getIndex(*(BluePrint **)(*(int *)(iVar6 + 4) + uVar7 * 4));
      iVar21 = Agent::getSellBlueprintIndex(pAVar22);
      if (iVar6 == iVar21) {
        iVar6 = Status::getBluePrints(Globals::status);
        BluePrint::unlock(*(BluePrint **)(*(int *)(iVar6 + 4) + uVar7 * 4));
        break;
      }
    }
    puVar16 = (uint *)Status::getAgents(Globals::status);
    uVar7 = Agent::getIndex(pAVar22);
    if (uVar7 < *puVar16) {
      iVar6 = Agent::getIndex(pAVar22);
      Agent::setOfferAccepted(*(Agent **)(puVar16[1] + iVar6 * 4),true);
    }
    break;
  case 4:
    iVar6 = Agent::getSellItemPrice(pAVar22);
    Status::changeCredits(pSVar4,-iVar6);
    pSVar4 = Globals::status;
    iVar6 = Agent::getSellSystemIndex(pAVar22);
    Status::setSystemVisibility(pSVar4,iVar6,true);
    this[0x35] = (SpaceLounge)0x1;
    this[0x18] = (SpaceLounge)0x1;
    puVar16 = (uint *)Status::getAgents(Globals::status);
    uVar7 = Agent::getIndex(pAVar22);
    if (uVar7 < *puVar16) {
      iVar6 = Agent::getIndex(pAVar22);
      Agent::setOfferAccepted(*(Agent **)(puVar16[1] + iVar6 * 4),true);
    }
    goto switchD_0019cb3c_caseD_1;
  case 6:
    iVar6 = Agent::getWingmanFriendsCount(pAVar22);
    pSVar4 = Globals::status;
    *(int *)(Globals::status + 0xd4) = iVar6 + *(int *)(Globals::status + 0xd4) + 1;
    pAVar13 = (Array *)Agent::getWingmanNames(pAVar22);
    Status::setWingmen(pSVar4,pAVar13);
    uVar24 = Agent::getRace(pAVar22);
    pSVar4 = Globals::status;
    *(undefined4 *)(Globals::status + 0x2c) = uVar24;
    *(undefined4 *)(pSVar4 + 0x30) = 600000;
    pvVar14 = operator_new__(0x14);
    iVar6 = 0;
    do {
      iVar21 = Agent::getImageParts(pAVar22);
      *(undefined4 *)((int)pvVar14 + iVar6 * 4) = *(undefined4 *)(iVar21 + iVar6 * 4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 5);
    *(void **)(Globals::status + 0x28) = pvVar14;
    iVar6 = Achievements::gotAllMedals(Globals::achievements);
    pSVar4 = Globals::status;
    if (iVar6 == 1) {
      iVar6 = Agent::getCosts(pAVar22);
      Status::changeCredits(pSVar4,iVar6);
    }
    else {
      iVar6 = Agent::getCosts(pAVar22);
      Status::changeCredits(pSVar4,-iVar6);
    }
    goto switchD_0019cb3c_caseD_1;
  case 7:
    this_03 = (Standing *)Status::getStanding(Globals::status);
    iVar6 = Agent::getRace(pAVar22);
    Standing::rehabilitate(this_03,iVar6);
    pSVar4 = Globals::status;
    iVar6 = Agent::getCosts(pAVar22);
    Status::changeCredits(pSVar4,-iVar6);
    goto switchD_0019cb3c_caseD_1;
  case 8:
    if (Globals::options[0x38] == '\0') {
      iVar6 = Agent::getSellItemPrice(pAVar22);
      fVar30 = (float)VectorSignedToFloat(-iVar6,(byte)(in_fpscr >> 0x16) & 3);
      fVar30 = fVar30 + fVar30;
    }
    else {
      iVar6 = Agent::getSellItemPrice(pAVar22);
      fVar30 = (float)VectorSignedToFloat(-iVar6,(byte)(in_fpscr >> 0x16) & 3);
    }
    Status::changeCredits(pSVar4,(int)fVar30);
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    iVar6 = Agent::getSellModIndex(pAVar22);
    Ship::addMod(pSVar18,iVar6);
    break;
  case 9:
    if (Globals::options[0x38] == '\0') {
      iVar6 = Agent::getSellItemPrice(pAVar22);
      fVar30 = (float)VectorSignedToFloat(-iVar6,(byte)(in_fpscr >> 0x16) & 3);
      fVar30 = fVar30 + fVar30;
    }
    else {
      iVar6 = Agent::getSellItemPrice(pAVar22);
      fVar30 = (float)VectorSignedToFloat(-iVar6,(byte)(in_fpscr >> 0x16) & 3);
    }
    Status::changeCredits(pSVar4,(int)fVar30);
    iVar6 = Globals::items;
    iVar21 = Agent::getSellItemIndex(pAVar22);
    pIVar23 = *(Item **)(*(int *)(iVar6 + 4) + iVar21 * 4);
    iVar6 = Agent::getSellItemQuantity(pAVar22);
    pIVar23 = (Item *)Item::makeItem(pIVar23,iVar6);
    iVar6 = Item::getType(pIVar23);
    if (iVar6 == 1) {
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      puVar16 = (uint *)Ship::getEquipment(pSVar18);
      uVar7 = 0;
      if (puVar16 != (uint *)0x0) {
        uVar7 = *puVar16;
      }
      if (puVar16 != (uint *)0x0 && uVar7 != 0) {
        uVar7 = 0;
        bVar29 = false;
        do {
          pIVar17 = *(Item **)(puVar16[1] + uVar7 * 4);
          if (pIVar17 != (Item *)0x0) {
            iVar6 = Item::getIndex(pIVar17);
            iVar21 = Item::getIndex(pIVar23);
            if (iVar6 == iVar21) {
              pIVar17 = *(Item **)(puVar16[1] + uVar7 * 4);
              iVar6 = Item::getAmount(pIVar23);
              Item::changeAmount(pIVar17,iVar6);
              bVar29 = true;
            }
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *puVar16);
        if (bVar29) break;
      }
    }
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    Ship::addCargo(pSVar18,pIVar23);
    break;
  case 10:
    if (Globals::options[0x38] == '\0') {
      iVar6 = Agent::getSellItemPrice(pAVar22);
      fVar30 = (float)VectorSignedToFloat(-iVar6,(byte)(in_fpscr >> 0x16) & 3);
      fVar30 = fVar30 + fVar30;
    }
    else {
      iVar6 = Agent::getSellItemPrice(pAVar22);
      fVar30 = (float)VectorSignedToFloat(-iVar6,(byte)(in_fpscr >> 0x16) & 3);
    }
    Status::changeCredits(pSVar4,(int)fVar30);
    iVar6 = Globals::ships;
    pSVar26 = *(Station **)(Globals::status + 0x14c);
    iVar21 = Agent::getSellItemIndex(pAVar22);
    pSVar18 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(iVar6 + 4) + iVar21 * 4),-1);
    Station::addShip(pSVar26,pSVar18);
    pSVar26 = (Station *)Status::getStation(Globals::status);
    iVar6 = Globals::ships;
    iVar21 = Agent::getSellItemIndex(pAVar22);
    pSVar18 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(iVar6 + 4) + iVar21 * 4),-1);
    Station::addShip(pSVar26,pSVar18);
  }
  this[0x35] = (SpaceLounge)0x1;
switchD_0019cb3c_caseD_1:
  iVar6 = Agent::getOffer(pAVar22);
  if (iVar6 != 8) {
    Agent::setOfferAccepted(pAVar22,true);
  }
  pSVar27 = *(ScrollTouchWindow **)(this + 0x60);
  Agent::getName();
  AbyssEngine::String::String(aSStack_7c,aSStack_3c,false);
  ScrollTouchWindow::setText(pSVar27,aSStack_74,aSStack_7c);
  AbyssEngine::String::~String(aSStack_7c);
  AbyssEngine::String::~String(aSStack_74);
  *(undefined4 *)(this + 0x14) = 3;
  *(undefined4 *)(this + 0x2c) = 0;
  AbyssEngine::String::~String(aSStack_3c);
  this[0x19] = (SpaceLounge)0x0;
switchD_0019c744_default:
  if (__stack_chk_guard - local_34 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_34);
}

// ===== SpaceLounge::updateScreenPositions  @0x0019ec30  (694 bytes)
/* SpaceLounge::updateScreenPositions() */

void __thiscall SpaceLounge::updateScreenPositions(SpaceLounge *this)

{
  PaintCanvas *pPVar1;
  int iVar2;
  uint uVar3;
  Matrix *pMVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  SolarSystem *this_00;
  int iVar9;
  float fVar10;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  AEMath aAStack_160 [60];
  AEMath aAStack_124 [8];
  float local_11c;
  float local_118 [3];
  AEMath aAStack_10c [12];
  undefined4 local_100 [5];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  float local_64;
  undefined4 local_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  if (*(int *)(this + 0x24) != 0) {
    iVar2 = Level::getEnemies((Level *)**(undefined4 **)(this + 0x44));
    pPVar1 = Globals::Canvas;
    local_68 = 0;
    local_64 = 0.0;
    local_60 = 0;
    local_70 = 0;
    uStack_6c = 0;
    local_80 = 0;
    uStack_7c = 0;
    local_78 = 0;
    uStack_74 = 0;
    uVar3 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    pMVar4 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar3);
    fVar10 = (float)AbyssEngine::AEMath::MatrixGetRight((AEMath *)local_100,pMVar4);
    AbyssEngine::AEMath::operator*((AEMath *)&local_c0,fVar10,(Vector *)0x43160000);
    AbyssEngine::AEMath::Vector::operator=((Vector *)&local_80,(Vector *)&local_c0);
    if (**(int **)(this + 0x24) != 0) {
      uVar11 = 0;
      uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar14 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar5 = (undefined4 *)((uint)local_100 | 4);
      uVar3 = 0;
      do {
        (**(code **)(**(int **)(*(int *)(iVar2 + 4) + uVar3 * 4) + 0x28))((AEMath *)&local_c0);
        AbyssEngine::AEMath::Vector::operator=((Vector *)&uStack_74,(Vector *)&local_c0);
        AbyssEngine::AEMath::operator-((AEMath *)&local_c0,(Vector *)&uStack_74,(Vector *)&local_80)
        ;
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_68,(Vector *)&local_c0);
        AbyssEngine::PaintCanvas::GetScreenPosition
                  (Globals::Canvas,(Vector *)&local_68,
                   *(Vector **)(*(int *)(*(int *)(this + 0x40) + 4) + uVar3 * 8));
        AbyssEngine::AEMath::operator+((AEMath *)&local_c0,(Vector *)&uStack_74,(Vector *)&local_80)
        ;
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_68,(Vector *)&local_c0);
        local_64 = local_64 + 450.0;
        AbyssEngine::PaintCanvas::GetScreenPosition
                  (Globals::Canvas,(Vector *)&local_68,
                   *(Vector **)(*(int *)(*(int *)(this + 0x40) + 4) + uVar3 * 8 + 4));
        pPVar1 = Globals::Canvas;
        uVar6 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
        puVar7 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar6);
        local_c0 = *puVar7;
        uStack_bc = puVar7[1];
        uStack_b8 = puVar7[2];
        uStack_b4 = puVar7[3];
        uStack_b0 = puVar7[4];
        local_ac = puVar7[5];
        uStack_a8 = puVar7[6];
        uStack_a4 = puVar7[7];
        uStack_a0 = puVar7[8];
        uStack_9c = puVar7[9];
        local_98 = puVar7[10];
        uStack_94 = puVar7[0xb];
        uStack_90 = puVar7[0xc];
        uStack_8c = puVar7[0xd];
        uStack_88 = puVar7[0xe];
        AbyssEngine::AEMath::MatrixGetPosition(aAStack_160,(AEMath *)&local_c0);
        AbyssEngine::AEMath::MatrixGetUp(aAStack_10c,(AEMath *)&local_c0);
        AbyssEngine::AEMath::MatrixGetLookAt
                  ((AEMath *)local_100,(Vector *)aAStack_160,(Vector *)&uStack_74,
                   (Vector *)aAStack_10c);
        AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_c0,(AEMath *)local_100);
        AEGeometry::setMatrix
                  (*(Matrix **)
                    (*(int *)(*(int *)(iVar2 + 4) + (**(int **)(this + 0x24) + uVar3) * 4) + 8));
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x4c),(Vector *)&uStack_74);
        AbyssEngine::AEMath::MatrixGetDir((AEMath *)local_118,(AEMath *)&local_c0);
        *(float *)(this + 0x4c) = *(float *)(this + 0x4c) - local_118[0] * 100.0;
        AbyssEngine::AEMath::MatrixGetDir(aAStack_124,(AEMath *)&local_c0);
        *(float *)(this + 0x54) = *(float *)(this + 0x54) - local_11c * 100.0;
        piVar8 = *(int **)(*(int *)(iVar2 + 4) + (**(int **)(this + 0x24) + uVar3) * 4);
        (**(code **)(*piVar8 + 0x44))(piVar8,(Vector *)(this + 0x4c));
        this_00 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar9 = SolarSystem::getRace(this_00);
        if (iVar9 == 0) {
          local_100[0] = 0x3f800000;
          *puVar5 = uVar11;
          puVar5[1] = uVar12;
          puVar5[2] = uVar13;
          puVar5[3] = uVar14;
          local_ec = 0x3f800000;
          local_d8 = 0x3f800000;
          uStack_d0 = 0x3f8000003f800000;
          local_c8 = 0x3f800000;
          local_e8 = uVar11;
          uStack_e4 = uVar12;
          uStack_e0 = uVar13;
          uStack_dc = uVar14;
          AbyssEngine::AEMath::MatrixSetRotation(aAStack_160,extraout_s0,extraout_s1,extraout_s2);
          AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_c0,(Matrix *)local_100);
        }
        AEGeometry::setMatrix(*(Matrix **)(*(int *)(*(int *)(iVar2 + 4) + uVar3 * 4) + 8));
        piVar8 = *(int **)(*(int *)(iVar2 + 4) + uVar3 * 4);
        (**(code **)(*piVar8 + 0x44))(piVar8,(Vector *)&uStack_74);
        uVar3 = uVar3 + 1;
      } while (uVar3 < **(uint **)(this + 0x24));
    }
  }
  if (__stack_chk_guard != local_5c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== SpaceLounge::update  @0x0019ef20  (1116 bytes)
/* WARNING: Removing unreachable block (ram,0x0019efa0) */
/* WARNING: Removing unreachable block (ram,0x0019ef76) */
/* SpaceLounge::update(int) */

void __thiscall SpaceLounge::update(SpaceLounge *this,int param_1)

{
  SpaceLounge *pSVar1;
  ushort uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  Matrix *pMVar6;
  EaseInOut *pEVar7;
  uint uVar8;
  PaintCanvas *pPVar9;
  int iVar10;
  uint in_fpscr;
  float fVar11;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  undefined8 uVar12;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float fVar13;
  float extraout_s2;
  AEMath aAStack_ac [60];
  Matrix aMStack_70 [60];
  int local_34;
  
  local_34 = __stack_chk_guard;
  if (0x31 < param_1) {
    param_1 = 0x32;
  }
  if (this[0xac] == (SpaceLounge)0x0) goto LAB_0019f32c;
  if (this[0x34] != (SpaceLounge)0x0) {
    StarMap::update(*(int *)(this + 4));
    return;
  }
  if (this[0x1c] != (SpaceLounge)0x0) {
    ListItemWindow::update(*(int *)(this + 0xc));
    return;
  }
  if ((*(ushort *)(this + 0xb8) & 0xff) == 0) {
    fVar11 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::EaseInOutMatrix::Increase(*(EaseInOutMatrix **)(this + 0x48),fVar11);
    uVar2 = (ushort)(byte)this[0xb9];
  }
  else {
    uVar2 = *(ushort *)(this + 0xb8) >> 8;
  }
  if (uVar2 == 0) {
    AbyssEngine::EaseInOutMatrix::GetMaxValue();
    AbyssEngine::EaseInOutMatrix::GetValue();
    iVar3 = AbyssEngine::AEMath::operator==(aMStack_70,aAStack_ac);
    if (iVar3 == 1) goto LAB_0019efec;
    this[0xb8] = (SpaceLounge)0x0;
    pPVar9 = Globals::Canvas;
    uVar8 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    AbyssEngine::EaseInOutMatrix::GetValue();
  }
  else {
LAB_0019efec:
    fVar11 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar11 = fVar11 * 0.0025;
    uVar8 = in_fpscr & 0xfffffff;
    fVar13 = 0.12;
    if (fVar11 < 0.12) {
      fVar13 = fVar11;
    }
    fVar4 = 0.12;
    if (fVar13 < 0.05) {
      fVar4 = 0.05;
    }
    if (0.12 <= fVar11) {
      fVar11 = fVar4;
    }
    if (fVar13 < 0.05) {
      fVar11 = fVar4;
    }
    this[0xb9] = (SpaceLounge)0x1;
    fVar13 = *(float *)(this + 0x100);
    *(float *)(this + 0x100) = fVar11 + fVar13;
    AbyssEngine::AEMath::Sinf(fVar11 + fVar13);
    pPVar9 = Globals::Canvas;
    VectorSignedToFloat(*(undefined4 *)(this + 0x104),(byte)(uVar8 >> 0x16) & 3);
    in_fpscr = uVar8 & 0xfffffff;
    if (this[0xb8] == (SpaceLounge)0x0) {
      uVar8 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
      pMVar6 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar9,uVar8);
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0xc4),pMVar6);
      this[0xb8] = (SpaceLounge)0x1;
      uVar12 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
      this[0xc0] = (SpaceLounge)0x0;
      pEVar7 = *(EaseInOut **)(this + 0xbc);
      if (pEVar7 == (EaseInOut *)0x0) {
        pEVar7 = operator_new(0x10);
        AbyssEngine::EaseInOut::EaseInOut(pEVar7,extraout_s0,extraout_s1_00);
        *(EaseInOut **)(this + 0xbc) = pEVar7;
      }
      else {
        AbyssEngine::EaseInOut::SetRange(pEVar7,(float)uVar12,(float)((ulonglong)uVar12 >> 0x20));
      }
      *(undefined4 *)(this + 0x104) = 2;
    }
    else {
      pSVar1 = this + 0xbc;
      fVar13 = (float)AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)pSVar1);
      fVar4 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)pSVar1);
      fVar5 = (float)AbyssEngine::EaseInOut::GetMaxValue(*(EaseInOut **)pSVar1);
      in_fpscr = in_fpscr & 0xfffffff;
      fVar11 = -(fVar13 - fVar5);
      if (0.0 < fVar13 - fVar4) {
        fVar11 = fVar13 - fVar5;
      }
      if (0.25 <= fVar11) {
        iVar3 = *(int *)(this + 0x104);
      }
      else {
        iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,10);
        fVar11 = (float)VectorSignedToFloat(5 - iVar3,(byte)(in_fpscr >> 0x16) & 3);
        in_fpscr = in_fpscr & 0xfffffff;
        this[0xc0] = (SpaceLounge)(fVar11 < fVar13);
        AbyssEngine::EaseInOut::SetRange(*(EaseInOut **)(this + 0xbc),fVar11,extraout_s1);
        iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
        iVar3 = iVar3 + 1;
        *(int *)(this + 0x104) = iVar3;
      }
      if (this[0xc0] != (SpaceLounge)0x0) {
        iVar3 = -iVar3;
      }
      fVar11 = (float)VectorSignedToFloat(param_1 * iVar3,(byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::EaseInOut::Increase(*(EaseInOut **)(this + 0xbc),fVar11);
    }
    fVar11 = (float)AbyssEngine::EaseInOut::GetValue(*(EaseInOut **)(this + 0xbc));
    AbyssEngine::AEMath::MatrixSetRotation(aMStack_70,fVar11 / 35.0,extraout_s1_01,fVar11);
    AbyssEngine::AEMath::MatrixSetTranslation
              (aAStack_ac,aMStack_70,extraout_s0_00,extraout_s1_02,extraout_s2);
    AbyssEngine::AEMath::Matrix::operator*=(aMStack_70,this + 0xc4);
    pPVar9 = Globals::Canvas;
    uVar8 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  }
  AbyssEngine::PaintCanvas::CameraSetLocal(pPVar9,uVar8,aMStack_70);
  updateScreenPositions(this);
  if (*(int *)(this + 0x14) != 0) {
    ScrollTouchWindow::update(*(int *)(this + 0x60));
  }
  CutScene::update(*(CutScene **)(this + 0x44));
  if (this[0xae] != (SpaceLounge)0x0) {
    iVar3 = *(int *)(this + 0xb4);
    if (iVar3 < *(int *)(Globals::layout + 0xc)) {
      if (*(int *)(this + 0xb0) < 0x96) {
        fVar11 = -10.0;
      }
      else {
        if (*(int *)(this + 0xb0) <= Globals::w + -0x96) goto LAB_0019f32c;
        fVar11 = 10.0;
      }
      *(float *)(*(int *)(this + 0x44) + 0xc) = *(float *)(*(int *)(this + 0x44) + 0xc) + fVar11;
    }
    else {
      iVar10 = *(int *)(this + 0xb0);
      if (iVar3 < Globals::h + *(int *)(Globals::layout + 0x10) * -2) {
        if (iVar10 < 0x46) {
          iVar3 = *(int *)(this + 0x44);
          fVar11 = 0.01;
        }
        else {
          if (iVar10 <= Globals::w + -0x46) {
            if ((100 < iVar10) && (iVar10 < Globals::w + -100)) {
              fVar11 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
              fVar13 = *(float *)(*(int *)(this + 0x44) + 0x10);
              if (iVar3 < Globals::h / 2) {
                fVar11 = fVar13 - fVar11;
              }
              else {
                fVar11 = fVar11 + fVar13;
              }
              *(float *)(*(int *)(this + 0x44) + 0x10) = fVar11;
            }
            goto LAB_0019f32c;
          }
          iVar3 = *(int *)(this + 0x44);
          fVar11 = -0.01;
        }
        *(float *)(iVar3 + 4) = *(float *)(iVar3 + 4) + fVar11;
      }
      else {
        if (iVar10 < 0x46) {
          fVar11 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          iVar3 = *(int *)(this + 0x44);
          fVar11 = *(float *)(iVar3 + 8) - fVar11;
        }
        else {
          if (iVar10 <= Globals::w + -0x46) goto LAB_0019f32c;
          fVar11 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          iVar3 = *(int *)(this + 0x44);
          fVar11 = fVar11 + *(float *)(iVar3 + 8);
        }
        *(float *)(iVar3 + 8) = fVar11;
      }
    }
  }
LAB_0019f32c:
  if (__stack_chk_guard - local_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_34,local_34);
  }
  return;
}

// ===== SpaceLounge::draw  @0x0019f3dc  (306 bytes)
/* WARNING: Removing unreachable block (ram,0x0019f484) */
/* SpaceLounge::draw() */

void __thiscall SpaceLounge::draw(SpaceLounge *this)

{
  PaintCanvas *this_00;
  Layout *pLVar1;
  int iVar2;
  int iVar3;
  String *pSVar4;
  String aSStack_24 [8];
  int local_1c;
  
  pLVar1 = Globals::layout;
  local_1c = __stack_chk_guard;
  if (this[0x1c] == (SpaceLounge)0x0) {
    if (this[0x34] != (SpaceLounge)0x0) {
      StarMap::draw(*(StarMap **)(this + 4));
      return;
    }
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x18e);
    AbyssEngine::String::String(aSStack_24,pSVar4,false);
    Layout::drawHeader(pLVar1,aSStack_24);
    AbyssEngine::String::~String(aSStack_24);
    drawLounge(this);
    if ((*(uint *)(this + 0x14) & 0xfffffffe) == 2) {
      Layout::drawFooterNoBackButton(Globals::layout);
    }
    else {
      Layout::drawFooter(Globals::layout);
    }
    if (((this[0x19] != (SpaceLounge)0x0) || ((*(ushort *)(this + 0x1a) & 0xff) != 0)) ||
       (0xff < *(ushort *)(this + 0x1a))) {
      ChoiceWindow::draw(*(ChoiceWindow **)(this + 8));
    }
    if (__stack_chk_guard == local_1c) {
      return;
    }
  }
  else {
    iVar2 = ListItemWindow::shows3DShip(*(ListItemWindow **)(this + 0xc));
    if (iVar2 == 1) {
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,'\0','\0','\0');
      this_00 = Globals::Canvas;
      iVar2 = AbyssEngine::PaintCanvas::GetWidth();
      iVar3 = AbyssEngine::PaintCanvas::GetHeight();
      AbyssEngine::PaintCanvas::FillRectangle(this_00,0,0,iVar2,iVar3);
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    }
    ListItemWindow::draw(*(ListItemWindow **)(this + 0xc));
    if (__stack_chk_guard == local_1c) {
      Layout::drawFooter(Globals::layout);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== SpaceLounge::drawLounge  @0x0019f53c  (1878 bytes)
/* SpaceLounge::drawLounge() */

void __thiscall SpaceLounge::drawLounge(SpaceLounge *this)

{
  PaintCanvas *pPVar1;
  GameText *pGVar2;
  Layout *pLVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  TouchButton *this_00;
  String *pSVar8;
  Mission *pMVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  float *pfVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  Agent *this_01;
  undefined4 uVar18;
  undefined4 uVar19;
  uint in_fpscr;
  float fVar20;
  float fVar21;
  int iVar22;
  float fVar23;
  float fVar24;
  String aSStack_7c [8];
  String aSStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  AbyssEngine aAStack_5c [8];
  String aSStack_54 [8];
  String aSStack_4c [8];
  int local_44;
  
  local_44 = __stack_chk_guard;
  if (*(int *)(this + 0x14) == 0) {
    iVar16 = *(int *)(this + 0x88);
    if (-1 < iVar16) {
      pfVar14 = *(float **)(*(int *)(*(int *)(this + 0x40) + 4) + (iVar16 << 3 | 4U));
      this_01 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar16 * 4);
      fVar21 = *pfVar14;
      fVar23 = pfVar14[1];
      iVar7 = *(int *)(Globals::layout + 0x94);
      fVar24 = **(float **)(*(int *)(*(int *)(this + 0x40) + 4) + iVar16 * 8);
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      iVar12 = iVar7 * 2;
      fVar20 = (float)VectorSignedToFloat(iVar12,(byte)(in_fpscr >> 0x16) & 3);
      iVar22 = (int)(fVar23 - fVar20);
      iVar11 = (int)(fVar24 + (fVar21 - fVar24) * 0.5);
      iVar16 = Agent::isKnown(this_01);
      if ((iVar16 == 0) &&
         (iVar16 = Agent::isStoryAgent(this_01), pGVar2 = Globals::gameText, iVar16 != 1)) {
        iVar16 = Agent::getRace(this_01);
        pSVar8 = (String *)GameText::getText(pGVar2,iVar16 + 0x196);
        AbyssEngine::String::String(aSStack_4c,pSVar8,false);
      }
      else {
        Agent::getName();
      }
      iVar16 = Agent::getMission(this_01);
      pGVar2 = Globals::gameText;
      if (iVar16 == 0) {
        iVar16 = Agent::getOffer(this_01);
        if (iVar16 == 6) {
          pSVar8 = (String *)GameText::getText(Globals::gameText,0x132);
          AbyssEngine::String::String(aSStack_54,pSVar8,false);
        }
        else {
          iVar16 = Agent::getOffer(this_01);
          if (iVar16 == 2) {
            pSVar8 = (String *)GameText::getText(Globals::gameText,0x131);
            AbyssEngine::String::String(aSStack_54,pSVar8,false);
          }
          else {
            iVar16 = Agent::getOffer(this_01);
            if (iVar16 == 7) {
              pSVar8 = (String *)GameText::getText(Globals::gameText,0x374);
              AbyssEngine::String::String(aSStack_54,pSVar8,false);
            }
            else {
              AbyssEngine::String::String(aSStack_54,"",false);
            }
          }
        }
      }
      else {
        pMVar9 = (Mission *)Agent::getMission(this_01);
        iVar16 = Mission::getType(pMVar9);
        pSVar8 = (String *)GameText::getText(pGVar2,iVar16 + 0x162);
        AbyssEngine::String::String(aSStack_54,pSVar8,false);
      }
      iVar16 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_4c);
      iVar10 = Agent::isKnown(this_01);
      uVar5 = Globals::font;
      pPVar1 = Globals::Canvas;
      if (iVar10 == 1) {
        AbyssEngine::String::String(aSStack_64,"  ",false);
        AbyssEngine::operator+(aAStack_5c,aSStack_54,aSStack_64);
        iVar10 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar1,uVar5,aAStack_5c);
        AbyssEngine::String::~String((String *)aAStack_5c);
        AbyssEngine::String::~String(aSStack_64);
        iVar16 = iVar16 + iVar10;
      }
      pLVar3 = Globals::layout;
      iVar10 = *(int *)(Globals::layout + 0x28);
      if (iVar11 - iVar7 < iVar10) {
        iVar11 = iVar10 + iVar7;
      }
      else if (Globals::w - iVar10 < iVar11 + iVar7 + iVar16) {
        iVar11 = (Globals::w - iVar10) - (iVar16 + iVar12);
      }
      uVar15 = *(undefined4 *)(Globals::layout + 0x30);
      uVar4 = AbyssEngine::String::String(aSStack_6c,"",false);
      Layout::drawBox(pLVar3,2,iVar11 - iVar7,iVar22 - iVar7,iVar12 + iVar16,uVar15,uVar4);
      AbyssEngine::String::~String(aSStack_6c);
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      AbyssEngine::PaintCanvas::DrawRectangle
                (Globals::Canvas,iVar11 - iVar7,iVar22 - iVar7,iVar12 + iVar16,
                 *(int *)(Globals::layout + 0x30));
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      uVar5 = Globals::font;
      pPVar1 = Globals::Canvas;
      iVar16 = Agent::isKnown(this_01);
      if (iVar16 == 1) {
        AbyssEngine::String::String(aSStack_64,"  ",false);
      }
      else {
        AbyssEngine::String::String(aSStack_64,"",false);
      }
      AbyssEngine::operator+(aAStack_5c,aSStack_4c,aSStack_64);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar5,aAStack_5c,iVar11,*(int *)(Globals::layout + 0x2c0) + iVar22,false);
      AbyssEngine::String::~String((String *)aAStack_5c);
      AbyssEngine::String::~String(aSStack_64);
      iVar16 = Agent::isKnown(this_01);
      if (iVar16 == 1) {
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        uVar5 = Globals::font;
        pPVar1 = Globals::Canvas;
        AbyssEngine::String::String(aSStack_64,"  ",false);
        AbyssEngine::operator+(aAStack_5c,aSStack_4c,aSStack_64);
        iVar16 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar1,uVar5,aAStack_5c);
        AbyssEngine::PaintCanvas::DrawString
                  (pPVar1,uVar5,aSStack_54,iVar16 + iVar11,
                   *(int *)(Globals::layout + 0x2c0) + iVar22,false);
        AbyssEngine::String::~String((String *)aAStack_5c);
        AbyssEngine::String::~String(aSStack_64);
      }
      AbyssEngine::String::~String(aSStack_54);
      AbyssEngine::String::~String(aSStack_4c);
    }
    goto LAB_0019fc60;
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  pLVar3 = Globals::layout;
  uVar18 = *(undefined4 *)(this + 0x70);
  uVar17 = *(undefined4 *)(this + 0x74);
  uVar15 = *(undefined4 *)(Globals::layout + 0x68);
  uVar19 = *(undefined4 *)(Globals::layout + 0x6c);
  uVar4 = AbyssEngine::String::String(aSStack_74,"",false);
  Layout::drawBox(pLVar3,2,uVar18,uVar17,uVar15,uVar19,uVar4);
  AbyssEngine::String::~String(aSStack_74);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawRectangle
            (Globals::Canvas,*(int *)(this + 0x70),*(int *)(this + 0x74),
             *(int *)(Globals::layout + 0x68),*(int *)(Globals::layout + 0x6c));
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  ImageFactory::drawChar
            (Globals::imageFactory,
             *(Array **)(*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x20) * 4),
             *(int *)(Globals::layout + 0x4c) + *(int *)(this + 0x70),
             *(int *)(this + 0x74) + *(int *)(Globals::layout + 0x4c),false);
  ScrollTouchWindow::draw(*(ScrollTouchWindow **)(this + 0x60));
  if ((*(uint *)(this + 0x14) & 0xfffffffe) != 2) goto LAB_0019fc60;
  TouchButton::setTextColor((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),0xed00ff);
  uVar5 = Agent::getOffer(*(Agent **)
                           (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
  if (*(int *)(this + 0x14) == 2) {
    TouchButton::setPosition
              ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),*(int *)(this + 0x84),
               *(int *)(this + 0x80));
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 4),
               *(int *)(this + 0x6c) + *(int *)(this + 0x84),*(int *)(this + 0x80),'\x12');
    *(undefined4 *)(this + 0x68) = 0;
    if (uVar5 < 0xb) {
      if ((1 << (uVar5 & 0xff) & 0x60cU) != 0) {
        *(undefined4 *)(this + 0x68) = 3;
        goto LAB_0019f744;
      }
      if (uVar5 == 0) {
        iVar16 = Agent::getMission(*(Agent **)
                                    (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4
                                    ));
        if (iVar16 != 0) {
          Agent::getMission(*(Agent **)
                             (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
          iVar16 = Mission::isOutsideMission();
          if (iVar16 == 1) {
            pMVar9 = (Mission *)
                     Agent::getMission(*(Agent **)
                                        (*(int *)(*(int *)(this + 0x24) + 4) +
                                        *(int *)(this + 0x20) * 4));
            iVar16 = Mission::getType(pMVar9);
            if (iVar16 != 0xc) {
              uVar4 = 4;
              if (this[0x36] != (SpaceLounge)0x0) {
                uVar4 = 1;
              }
              *(undefined4 *)(this + 0x68) = uVar4;
              if (this[0x36] != (SpaceLounge)0x0) goto LAB_0019f726;
              goto LAB_0019f744;
            }
          }
        }
      }
      else if (uVar5 == 1) {
        *(undefined4 *)(this + 0x68) = 1;
        goto LAB_0019f734;
      }
    }
    *(undefined4 *)(this + 0x68) = 2;
    TouchButton::setPosition
              ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),*(int *)(this + 0x84),
               *(int *)(this + 0x7c));
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 4),
               *(int *)(this + 0x6c) + *(int *)(this + 0x84),*(int *)(this + 0x7c),'\x12');
  }
  else {
    *(undefined4 *)(this + 0x68) = 1;
LAB_0019f726:
    TouchButton::setTextColor((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),-1);
LAB_0019f734:
    TouchButton::setPosition
              ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),*(int *)(this + 0x84),
               *(int *)(this + 0x7c));
  }
LAB_0019f744:
  puVar6 = *(uint **)(this + 0x5c);
  if (*puVar6 != 0) {
    uVar13 = 0;
    do {
      TouchButton::setVisible(*(TouchButton **)(puVar6[1] + uVar13 * 4),false);
      puVar6 = *(uint **)(this + 0x5c);
      uVar13 = uVar13 + 1;
    } while (uVar13 < *puVar6);
  }
  pLVar3 = Globals::layout;
  iVar11 = *(int *)(this + 0x68);
  iVar12 = *(int *)(Globals::layout + 0x4c);
  iVar7 = *(int *)(Globals::layout + 0x2d8);
  iVar16 = iVar7;
  if ((2 < iVar11) &&
     (iVar16 = *(int *)(Globals::layout + 0x30) * (iVar11 + -1) +
               (iVar11 + -2) * *(int *)(Globals::layout + 0x34), iVar16 < iVar7)) {
    iVar16 = iVar7;
  }
  uVar15 = *(undefined4 *)(this + 0x70);
  uVar18 = *(undefined4 *)(this + 0x78);
  uVar17 = *(undefined4 *)(Globals::layout + 0x68);
  uVar4 = AbyssEngine::String::String(aSStack_7c,"",false);
  iVar16 = iVar12 * 2 + iVar16;
  Layout::drawBox(pLVar3,2,uVar15,uVar18,uVar17,iVar16,uVar4);
  AbyssEngine::String::~String(aSStack_7c);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawRectangle
            (Globals::Canvas,*(int *)(this + 0x70),*(int *)(this + 0x78),
             *(int *)(Globals::layout + 0x68),iVar16);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  ImageFactory::drawChar
            (Globals::imageFactory,*(Array **)(this + 0x3c),
             *(int *)(Globals::layout + 0x4c) + *(int *)(this + 0x70),
             *(int *)(this + 0x78) + *(int *)(Globals::layout + 0x4c),true);
  if (((uVar5 == 1) || (this[0x36] != (SpaceLounge)0x0)) || (*(int *)(this + 0x14) == 3)) {
    TouchButton::setVisible((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),true);
    this_00 = (TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4);
  }
  else {
    TouchButton::setVisible((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),true);
    TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 4),true);
    TouchButton::draw((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4));
    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 4));
    if (10 < uVar5) goto LAB_0019fc60;
    if ((1 << (uVar5 & 0xff) & 0x60cU) == 0) {
      if (uVar5 != 0) goto LAB_0019fc60;
      Agent::getMission(*(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4)
                       );
      iVar16 = Mission::isOutsideMission();
      if (iVar16 != 1) goto LAB_0019fc60;
      pMVar9 = (Mission *)
               Agent::getMission(*(Agent **)
                                  (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4))
      ;
      iVar16 = Mission::getType(pMVar9);
      if (iVar16 == 0xc) goto LAB_0019fc60;
      TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0xc),true);
      TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0x10),true);
      TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0xc));
      this_00 = *(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 0x10);
    }
    else {
      TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 8),true);
      this_00 = *(TouchButton **)(*(int *)(*(int *)(this + 0x5c) + 4) + 8);
    }
  }
  TouchButton::draw(this_00);
LAB_0019fc60:
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== SpaceLounge::draw3DShip  @0x0019fd90  (14 bytes)
/* SpaceLounge::draw3DShip() */

void __thiscall SpaceLounge::draw3DShip(SpaceLounge *this)

{
  if (this[0x1c] == (SpaceLounge)0x0) {
    return;
  }
  ListItemWindow::render(*(ListItemWindow **)(this + 0xc));
  return;
}

// ===== SpaceLounge::checkLocationMode  @0x0019fd9c  (4 bytes)
/* SpaceLounge::checkLocationMode() */

undefined4 SpaceLounge::checkLocationMode(void)

{
  return 0;
}

// ===== SpaceLounge::mapMode  @0x0019fda0  (6 bytes)
/* SpaceLounge::mapMode() */

SpaceLounge __thiscall SpaceLounge::mapMode(SpaceLounge *this)

{
  return this[0x34];
}

// ===== SpaceLounge::listMode  @0x0019fda6  (14 bytes)
/* SpaceLounge::listMode() */

bool __thiscall SpaceLounge::listMode(SpaceLounge *this)

{
  return this[0x34] == (SpaceLounge)0x0;
}

// ===== SpaceLounge::getSoundId  @0x0019fdb4  (610 bytes)
/* SpaceLounge::getSoundId(Agent*) */

void __thiscall SpaceLounge::getSoundId(SpaceLounge *this,Agent *param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  Mission *pMVar7;
  SpaceLounge *this_00;
  String *pSVar8;
  int *piVar9;
  SpaceLounge *pSVar10;
  Agent aAStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  iVar4 = Agent::getRace(param_1);
  bVar2 = (bool)Agent::isMale(param_1);
  uVar5 = Agent::getOffer(param_1);
  iVar6 = Agent::getMission(param_1);
  if (iVar6 == 0) {
LAB_0019fdf4:
    iVar6 = -1;
  }
  else {
    pMVar7 = (Mission *)Agent::getMission(param_1);
    iVar6 = Mission::isEmpty(pMVar7);
    if (iVar6 != 0) goto LAB_0019fdf4;
    pMVar7 = (Mission *)Agent::getMission(param_1);
    iVar6 = Mission::getType(pMVar7);
  }
  Globals::getAgentMissionText(aAStack_2c);
  bVar1 = true;
  switch(uVar5) {
  case 0:
    if (iVar6 == 0 || iVar6 == 0xb) {
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
      pSVar10 = (SpaceLounge *)(iVar6 + 0x301);
    }
    else if (iVar6 == 0xc) {
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
      pSVar10 = (SpaceLounge *)(iVar6 + 0x2fa);
    }
    else {
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      if (iVar6 == 0) {
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
        pSVar10 = (SpaceLounge *)(iVar6 + 799);
      }
      else {
        iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
        pSVar10 = (SpaceLounge *)(iVar6 + 0x309);
      }
    }
    break;
  case 1:
    goto switchD_0019fe1e_caseD_1;
  case 2:
  case 3:
  case 8:
  case 9:
  case 10:
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    pSVar10 = (SpaceLounge *)(iVar6 + 0x2f7);
    break;
  case 4:
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    pSVar10 = (SpaceLounge *)(iVar6 + 0x2fe);
    break;
  case 5:
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar10 = (SpaceLounge *)(iVar6 + 0x31b);
    break;
  case 6:
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar10 = (SpaceLounge *)(iVar6 + 0x323);
    break;
  case 7:
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    pSVar10 = (SpaceLounge *)(iVar6 + 0x305);
    break;
  default:
    pSVar10 = (SpaceLounge *)0xffffffff;
  }
  iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
  bVar1 = false;
  if (iVar6 < 0x1e) {
switchD_0019fe1e_caseD_1:
    iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    pSVar10 = (SpaceLounge *)(iVar6 + 0x30d);
  }
  this_00 = (SpaceLounge *)Agent::hasAcceptedOffer(param_1);
  if (this_00 == (SpaceLounge *)0x1) {
    this_00 = (SpaceLounge *)AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    pSVar10 = this_00 + 0x30d;
  }
  if (bVar1) {
    pSVar8 = (String *)GameText::getText(Globals::gameText,0x334);
    cVar3 = AbyssEngine::String::Compare((String *)aAStack_2c,pSVar8);
    if (cVar3 != '\0') {
      pSVar8 = (String *)GameText::getText(Globals::gameText,0x338);
      cVar3 = AbyssEngine::String::Compare((String *)aAStack_2c,pSVar8);
      if (cVar3 != '\0') {
        pSVar8 = (String *)GameText::getText(Globals::gameText,0x33b);
        cVar3 = AbyssEngine::String::Compare((String *)aAStack_2c,pSVar8);
        if (cVar3 != '\0') {
          pSVar8 = (String *)GameText::getText(Globals::gameText,0x341);
          this_00 = (SpaceLounge *)AbyssEngine::String::Compare((String *)aAStack_2c,pSVar8);
          if (((uint)this_00 & 0xff) != 0) goto LAB_0019ff10;
        }
      }
    }
    this_00 = (SpaceLounge *)AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    pSVar10 = this_00 + 0x314;
  }
LAB_0019ff10:
  if (iVar4 == 3) {
    iVar4 = Agent::getImageParts(param_1);
    if (iVar4 == 0) {
      iVar4 = 3;
      this_00 = (SpaceLounge *)0x0;
    }
    else {
      piVar9 = (int *)Agent::getImageParts(param_1);
      this_00 = (SpaceLounge *)*piVar9;
      iVar4 = 0;
      if (this_00 == (SpaceLounge *)0x2) {
        iVar4 = 3;
      }
    }
  }
  getSpecificSoundForRace(this_00,(int)pSVar10,iVar4,bVar2);
  AbyssEngine::String::~String((String *)aAStack_2c);
  if (__stack_chk_guard - local_24 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_24);
  }
  return;
}

// ===== SpaceLounge::getSpecificSoundForRace  @0x001a0080  (118 bytes)
/* SpaceLounge::getSpecificSoundForRace(int, int, bool) */

int __thiscall
SpaceLounge::getSpecificSoundForRace(SpaceLounge *this,int param_1,int param_2,bool param_3)

{
  switch(param_2) {
  case 0:
  case 5:
    if (param_3) {
      if (param_1 - 0x2f7U < 0x30) {
        return param_1 + 0xf0;
      }
    }
    else if (param_1 - 0x2f7U < 0x30) {
      return param_1 + 0xc0;
    }
    break;
  case 1:
    if (param_1 - 0x2f7U < 0x30) {
      return param_1 + 0x120;
    }
    break;
  case 2:
  case 3:
    if (param_1 - 0x2f7U < 0x30) {
      return param_1 + 0x90;
    }
    break;
  case 4:
    if (param_1 - 0x2f7U < 0x30) {
      return param_1 + 0x60;
    }
    break;
  case 6:
    goto switchD_001a008c_caseD_6;
  case 7:
    if (param_1 - 0x2f7U < 0x30) {
      return param_1 + 0x30;
    }
  }
  param_1 = -1;
switchD_001a008c_caseD_6:
  return param_1;
}

// ===== SpaceLounge::hangarNeedsUpdate  @0x001a0100  (6 bytes)
/* SpaceLounge::hangarNeedsUpdate() */

SpaceLounge __thiscall SpaceLounge::hangarNeedsUpdate(SpaceLounge *this)

{
  return this[0x35];
}

// ===== SpaceLounge::OnTouchBegin  @0x001a0108  (298 bytes)
/* SpaceLounge::OnTouchBegin(int, int) */

undefined4 __thiscall SpaceLounge::OnTouchBegin(SpaceLounge *this,int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  float *pfVar4;
  uint uVar5;
  float *pfVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  
  this[0xae] = (SpaceLounge)0x1;
  *(int *)(this + 0xb0) = param_1;
  *(int *)(this + 0xb4) = param_2;
  *(undefined4 *)(this + 0x88) = 0xffffffff;
  if ((this[0x1b] == (SpaceLounge)0x0) && (this[0x19] == (SpaceLounge)0x0)) {
    if (this[0x34] == (SpaceLounge)0x0) {
      if (this[0x1c] == (SpaceLounge)0x0) {
        iVar1 = *(int *)(this + 0x14);
        if (iVar1 == 0) {
          if (this[0xb9] == (SpaceLounge)0x0) {
            return 0;
          }
          if ((*(uint **)(this + 0x24) != (uint *)0x0) &&
             (uVar5 = **(uint **)(this + 0x24), uVar5 != 0)) {
            uVar3 = 0;
            fVar7 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
            fVar8 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            iVar1 = *(int *)(*(int *)(this + 0x40) + 4);
            do {
              pfVar4 = *(float **)(iVar1 + uVar3 * 8);
              if ((((*pfVar4 < fVar8) &&
                   (pfVar6 = *(float **)(iVar1 + uVar3 * 8 + 4),
                   (int)((uint)(fVar8 < *pfVar6) << 0x1f) < 0)) &&
                  ((int)((uint)(fVar7 < pfVar4[1]) << 0x1f) < 0)) && (pfVar6[1] < fVar7)) {
                *(uint *)(this + 0x88) = uVar3;
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < uVar5);
          }
        }
        else if (iVar1 == 3) {
          TouchButton::OnTouchBegin
                    ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),param_1,param_2);
        }
        else if ((iVar1 == 2) && (puVar2 = *(uint **)(this + 0x5c), *puVar2 != 0)) {
          uVar5 = 0;
          do {
            TouchButton::OnTouchBegin(*(TouchButton **)(puVar2[1] + uVar5 * 4),param_1,param_2);
            puVar2 = *(uint **)(this + 0x5c);
            uVar5 = uVar5 + 1;
          } while (uVar5 < *puVar2);
        }
      }
      else {
        ListItemWindow::OnTouchBegin(*(ListItemWindow **)(this + 0xc),param_1,param_2);
      }
      Layout::OnTouchBegin(Globals::layout,param_1,param_2);
      ScrollTouchWindow::OnTouchBegin(*(int *)(this + 0x60),param_1);
    }
    else {
      StarMap::OnTouchBegin(*(StarMap **)(this + 4),param_1,param_2);
    }
  }
  else {
    ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(this + 8),param_1,param_2);
  }
  return 0;
}

// ===== SpaceLounge::OnTouchMove  @0x001a0238  (284 bytes)
/* SpaceLounge::OnTouchMove(int, int) */

undefined4 __thiscall SpaceLounge::OnTouchMove(SpaceLounge *this,int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  float *pfVar4;
  uint uVar5;
  float *pfVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  
  *(int *)(this + 0xb0) = param_1;
  *(int *)(this + 0xb4) = param_2;
  if ((this[0x1b] == (SpaceLounge)0x0) && (this[0x19] == (SpaceLounge)0x0)) {
    if (this[0x34] == (SpaceLounge)0x0) {
      iVar1 = *(int *)(this + 0x14);
      if (iVar1 == 0) {
        if (*(uint **)(this + 0x24) != (uint *)0x0) {
          *(undefined4 *)(this + 0x20) = 0xffffffff;
          *(undefined4 *)(this + 0x88) = 0xffffffff;
          uVar5 = **(uint **)(this + 0x24);
          if (uVar5 != 0) {
            uVar3 = 0;
            fVar7 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
            fVar8 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
            iVar1 = *(int *)(*(int *)(this + 0x40) + 4);
            do {
              pfVar4 = *(float **)(iVar1 + uVar3 * 8);
              if ((((*pfVar4 < fVar8) &&
                   (pfVar6 = *(float **)(iVar1 + uVar3 * 8 + 4),
                   (int)((uint)(fVar8 < *pfVar6) << 0x1f) < 0)) &&
                  ((int)((uint)(fVar7 < pfVar4[1]) << 0x1f) < 0)) && (pfVar6[1] < fVar7)) {
                *(uint *)(this + 0x88) = uVar3;
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < uVar5);
          }
        }
      }
      else if (iVar1 == 3) {
        TouchButton::OnTouchMove
                  ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),param_1,param_2);
      }
      else if ((iVar1 == 2) && (puVar2 = *(uint **)(this + 0x5c), *puVar2 != 0)) {
        uVar5 = 0;
        do {
          TouchButton::OnTouchMove(*(TouchButton **)(puVar2[1] + uVar5 * 4),param_1,param_2);
          puVar2 = *(uint **)(this + 0x5c);
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar2);
      }
      Layout::OnTouchMove(Globals::layout,param_1,param_2);
      if (this[0x1c] == (SpaceLounge)0x0) {
        ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 0x60),param_1,param_2);
      }
      else {
        ListItemWindow::OnTouchMove(*(ListItemWindow **)(this + 0xc),param_1,param_2);
      }
    }
    else {
      StarMap::OnTouchMove(*(StarMap **)(this + 4),param_1,param_2);
    }
  }
  else {
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 8),param_1,param_2);
  }
  return 0;
}

// ===== SpaceLounge::OnTouchEnd  @0x001a0360  (6662 bytes)
/* SpaceLounge::OnTouchEnd(int, int) */

void __thiscall SpaceLounge::OnTouchEnd(SpaceLounge *this,int param_1,int param_2)

{
  char cVar1;
  Galaxy *this_00;
  Status *pSVar2;
  PaintCanvas *this_01;
  GameText *pGVar3;
  Layout *pLVar4;
  SpaceLounge SVar5;
  bool bVar6;
  int iVar7;
  String *pSVar8;
  float *pfVar9;
  uint *puVar10;
  SolarSystem *pSVar11;
  undefined4 uVar12;
  Agent *this_02;
  Mission *pMVar13;
  ListItemWindow *pLVar14;
  ListItem *this_03;
  Station *this_04;
  int iVar15;
  Engine *pEVar16;
  Ship *pSVar17;
  int *piVar18;
  String *pSVar19;
  uint uVar20;
  undefined4 *puVar21;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  float *pfVar22;
  ScrollTouchWindow *pSVar23;
  StarMap *pSVar24;
  String *pSVar25;
  Agent *pAVar26;
  String *this_05;
  uint uVar27;
  uint in_fpscr;
  float fVar28;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float fVar29;
  float extraout_s2;
  float fVar30;
  undefined4 uVar31;
  String aSStack_33c [8];
  String aSStack_334 [8];
  String aSStack_32c [8];
  String aSStack_324 [8];
  String aSStack_31c [8];
  String aSStack_314 [8];
  String aSStack_30c [8];
  String aSStack_304 [8];
  String aSStack_2fc [8];
  String aSStack_2f4 [8];
  String aSStack_2ec [8];
  String aSStack_2e4 [8];
  String aSStack_2dc [8];
  String aSStack_2d4 [8];
  String aSStack_2cc [8];
  String aSStack_2c4 [8];
  String aSStack_2bc [8];
  String aSStack_2b4 [8];
  String aSStack_2ac [8];
  String aSStack_2a4 [8];
  String aSStack_29c [8];
  String aSStack_294 [8];
  String aSStack_28c [8];
  String aSStack_284 [8];
  String aSStack_27c [8];
  String aSStack_274 [8];
  String aSStack_26c [8];
  String aSStack_264 [8];
  String aSStack_25c [8];
  String aSStack_254 [8];
  String aSStack_24c [8];
  String aSStack_244 [8];
  String aSStack_23c [8];
  String aSStack_234 [8];
  String aSStack_22c [8];
  String aSStack_224 [8];
  String aSStack_21c [8];
  String aSStack_214 [8];
  String aSStack_20c [8];
  String aSStack_204 [8];
  String aSStack_1fc [8];
  String aSStack_1f4 [8];
  String aSStack_1ec [8];
  String aSStack_1e4 [8];
  String aSStack_1dc [8];
  String aSStack_1d4 [8];
  String aSStack_1cc [8];
  String aSStack_1c4 [8];
  String aSStack_1bc [8];
  String aSStack_1b4 [8];
  String aSStack_1ac [8];
  String aSStack_1a4 [8];
  String aSStack_19c [8];
  String aSStack_194 [8];
  String aSStack_18c [8];
  String aSStack_184 [8];
  String aSStack_17c [8];
  String aSStack_174 [8];
  String aSStack_16c [8];
  String aSStack_164 [8];
  String aSStack_15c [8];
  String aSStack_154 [8];
  String aSStack_14c [8];
  String aSStack_144 [8];
  String aSStack_13c [8];
  String aSStack_134 [8];
  String aSStack_12c [8];
  AbyssEngine aAStack_124 [8];
  AbyssEngine aAStack_11c [8];
  String aSStack_114 [8];
  String aSStack_10c [8];
  String aSStack_104 [8];
  String aSStack_fc [8];
  String aSStack_f4 [8];
  undefined4 local_ec [2];
  String aSStack_e4 [8];
  String aSStack_dc [8];
  AEMath aAStack_d4 [60];
  undefined4 auStack_98 [5];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 uStack_60;
  String aSStack_5c [8];
  int iStack_54;
  
  iStack_54 = __stack_chk_guard;
  this[0xae] = (SpaceLounge)0x0;
  if ((this[0x1b] != (SpaceLounge)0x0) || (this[0x19] != (SpaceLounge)0x0)) {
    iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 8),param_1,param_2);
    if (iVar7 == 1) {
      this[0x19] = (SpaceLounge)0x0;
    }
    else if (iVar7 == 0) {
LAB_001a1bb0:
      onKeyPress(this,0x10000);
    }
    goto LAB_001a1bbc;
  }
  if (this[0x34] != (SpaceLounge)0x0) {
    iVar7 = StarMap::OnTouchEnd(*(StarMap **)(this + 4),param_1,param_2);
    if (iVar7 == 1) {
      CutScene::resetCamera(*(CutScene **)(this + 0x44));
      this[0x34] = (SpaceLounge)0x0;
    }
    goto LAB_001a1bbc;
  }
  iVar7 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
  if (iVar7 == 1) {
    if (this[0x1c] == (SpaceLounge)0x0) {
      if (*(int *)(this + 0x14) != 0) {
        if ((-1 < *(int *)(this + 0x20)) &&
           (iVar7 = Agent::isGenericAgent
                              (*(Agent **)
                                (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4)),
           iVar7 == 1)) {
          Agent::setEvent(*(Agent **)
                           (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4),1);
        }
        this[0x36] = (SpaceLounge)0x0;
        *(undefined4 *)(this + 0x14) = 0;
      }
    }
    else {
      Layout::resetWindowDimensions(Globals::layout);
      this[0x1c] = (SpaceLounge)0x0;
    }
    goto LAB_001a1bbc;
  }
  if (this[0x1c] == (SpaceLounge)0x0) {
    switch(*(undefined4 *)(this + 0x14)) {
    case 0:
      if (this[0xb9] == (SpaceLounge)0x0) {
        pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar7 = SolarSystem::getRace(pSVar11);
        uStack_7c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        uStack_78 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_74 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        iVar7 = iVar7 * 0xc;
        puVar21 = (undefined4 *)((uint)auStack_98 | 4);
        VectorSignedToFloat(*(undefined4 *)(&DAT_0025ceb4 + iVar7),(byte)(in_fpscr >> 0x16) & 3);
        uVar31 = *(undefined4 *)(&DAT_0025cebc + iVar7);
        fVar29 = (float)VectorSignedToFloat(*(undefined4 *)(&DAT_0025ceb8 + iVar7),
                                            (byte)(in_fpscr >> 0x16) & 3);
        auStack_98[0] = 0x3f800000;
        *puVar21 = 0;
        puVar21[1] = uStack_7c;
        puVar21[2] = uStack_78;
        puVar21[3] = uStack_74;
        local_84 = 0x3f800000;
        local_80 = 0;
        fVar28 = (float)VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
        local_70 = 0x3f800000;
        uStack_68 = 0x3f8000003f800000;
        uStack_60 = 0x3f800000;
        AbyssEngine::AEMath::MatrixSetTranslation
                  (aAStack_d4,(Matrix *)auStack_98,fVar28,extraout_s1,fVar29);
        AbyssEngine::AEMath::MatrixSetRotation(aAStack_d4,extraout_s0,extraout_s1_00,extraout_s2);
        this_01 = Globals::Canvas;
        uVar27 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
        AbyssEngine::PaintCanvas::CameraSetLocal(this_01,uVar27,(Matrix *)auStack_98);
        if (*(int *)(this + 0x48) != 0) {
          AbyssEngine::EaseInOutMatrix::SetRange(*(int *)(this + 0x48));
        }
        *(undefined4 *)(this + 0x100) = 0;
        this[0xb9] = (SpaceLounge)0x1;
        goto LAB_001a1bbc;
      }
      if (*(uint **)(this + 0x24) != (uint *)0x0) {
        *(undefined4 *)(this + 0x20) = 0xffffffff;
        *(undefined4 *)(this + 0x88) = 0xffffffff;
        uVar27 = **(uint **)(this + 0x24);
        if (uVar27 != 0) {
          uVar20 = 0;
          fVar28 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
          fVar29 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          do {
            pfVar22 = *(float **)(*(int *)(*(int *)(this + 0x40) + 4) + uVar20 * 8);
            if ((((*pfVar22 < fVar29) &&
                 (pfVar9 = *(float **)(*(int *)(*(int *)(this + 0x40) + 4) + uVar20 * 8 + 4),
                 (int)((uint)(fVar29 < *pfVar9) << 0x1f) < 0)) &&
                ((int)((uint)(fVar28 < pfVar22[1]) << 0x1f) < 0)) && (pfVar9[1] < fVar28)) {
              *(uint *)(this + 0x20) = uVar20;
              goto LAB_001a1bb0;
            }
            uVar20 = uVar20 + 1;
          } while (uVar20 < uVar27);
        }
      }
      break;
    case 1:
switchD_001a04a4_caseD_1:
      onKeyPress(this,0x10000);
      break;
    case 2:
      puVar10 = *(uint **)(this + 0x5c);
      if (*puVar10 != 0) {
        uVar27 = 0;
        do {
          iVar7 = TouchButton::OnTouchEnd
                            (*(TouchButton **)(puVar10[1] + uVar27 * 4),param_1,param_2);
          if (iVar7 == 1) {
            pAVar26 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4);
            Agent::getRace(pAVar26);
            switch(uVar27) {
            case 0:
              iVar7 = Agent::getOffer(pAVar26);
              AbyssEngine::String::String((String *)auStack_98,"",false);
              cVar1 = (char)&stack0xffffffdc;
              switch(iVar7) {
              case 0:
              case 5:
                if (this[0x36] != (SpaceLounge)0x0) {
                  this[0x36] = (SpaceLounge)0x0;
                  *(undefined4 *)(this + 0x14) = 2;
                  Globals::getAgentMissionText((Agent *)aAStack_d4);
                  iVar7 = Agent::getMission(pAVar26);
                  if (iVar7 != 0) {
                    pMVar13 = (Mission *)Agent::getMission(pAVar26);
                    iVar7 = Mission::isEmpty(pMVar13);
                    pSVar2 = Globals::status;
                    if (iVar7 == 0) {
                      AbyssEngine::String::String(aSStack_114,aAStack_d4,false);
                      pMVar13 = (Mission *)Agent::getMission(pAVar26);
                      Mission::getReward(pMVar13);
                      pMVar13 = (Mission *)Agent::getMission(pAVar26);
                      Mission::getBonus(pMVar13);
                      Layout::formatCredits((int)aSStack_12c);
                      AbyssEngine::String::String((String *)aAStack_124,aSStack_12c,false);
                      AbyssEngine::operator+(aAStack_11c,aAStack_124,this + 0xa4);
                      uVar31 = AbyssEngine::String::String(aSStack_134,"#C",false);
                      Status::replaceHash(local_ec,pSVar2,aSStack_114,aAStack_11c,uVar31);
                      AbyssEngine::String::operator=((String *)aAStack_d4,(String *)local_ec);
                      AbyssEngine::String::~String((String *)local_ec);
                      AbyssEngine::String::~String(aSStack_134);
                      AbyssEngine::String::~String((String *)aAStack_11c);
                      AbyssEngine::String::~String((String *)aAStack_124);
                      AbyssEngine::String::~String(aSStack_12c);
                      AbyssEngine::String::~String(aSStack_114);
                    }
                  }
                  pSVar23 = *(ScrollTouchWindow **)(this + 0x60);
                  Agent::getName();
                  AbyssEngine::String::String(aSStack_144,aAStack_d4,false);
                  ScrollTouchWindow::setText(pSVar23,aSStack_13c,aSStack_144);
                  AbyssEngine::String::~String(aSStack_144);
                  AbyssEngine::String::~String(aSStack_13c);
                  *(undefined4 *)(this + 0x2c) = 0;
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  goto LAB_001a1ba4;
                }
                pMVar13 = (Mission *)Agent::getMission(pAVar26);
                iVar7 = Mission::getType(pMVar13);
                if (iVar7 != 0) {
                  pMVar13 = (Mission *)Agent::getMission(pAVar26);
                  iVar7 = Mission::getType(pMVar13);
                  if (iVar7 == 0xb) {
                    pMVar13 = (Mission *)Agent::getMission(pAVar26);
                    iVar7 = Mission::getProductionGoodAmount(pMVar13);
                    pSVar17 = (Ship *)Status::getShip(Globals::status);
                    iVar15 = Ship::getMaxPassengers(pSVar17);
                    if (iVar15 < iVar7) {
                      pSVar8 = (String *)GameText::getText(Globals::gameText,0x152);
                      AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                      pSVar2 = Globals::status;
                      AbyssEngine::String::String(aSStack_164,(String *)auStack_98,false);
                      local_ec[0] = 0;
                      AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_ec));
                      AbyssEngine::String::String(aSStack_16c,(String *)local_ec,false);
                      uVar31 = AbyssEngine::String::String(aSStack_174,"#Q",false);
                      Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_164,aSStack_16c,uVar31
                                         );
                      AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                      AbyssEngine::String::~String((String *)aAStack_d4);
                      AbyssEngine::String::~String(aSStack_174);
                      AbyssEngine::String::~String(aSStack_16c);
                      AbyssEngine::String::~String((String *)local_ec);
                      pSVar19 = aSStack_164;
                      goto LAB_001a0a56;
                    }
                  }
LAB_001a1890:
                  iVar7 = Agent::isGenericAgent(pAVar26);
                  if (iVar7 == 1) {
                    pSVar8 = (String *)GameText::getText(Globals::gameText,0x361);
                    AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                    pSVar2 = Globals::status;
                    AbyssEngine::String::String(aSStack_17c,(String *)auStack_98,false);
                    pMVar13 = (Mission *)Agent::getMission(pAVar26);
                    Mission::getReward(pMVar13);
                    pMVar13 = (Mission *)Agent::getMission(pAVar26);
                    Mission::getBonus(pMVar13);
                    Layout::formatCredits((int)local_ec);
                    AbyssEngine::String::String(aSStack_184,(String *)local_ec,false);
                    uVar31 = AbyssEngine::String::String(aSStack_18c,"#C",false);
                    Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_17c,aSStack_184,uVar31);
                    AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                    AbyssEngine::String::~String((String *)aAStack_d4);
                    AbyssEngine::String::~String(aSStack_18c);
                    AbyssEngine::String::~String(aSStack_184);
                    AbyssEngine::String::~String((String *)local_ec);
                    AbyssEngine::String::~String(aSStack_17c);
                    pSVar2 = Globals::status;
                    AbyssEngine::String::String(aSStack_194,(String *)auStack_98,false);
                    pGVar3 = Globals::gameText;
                    pMVar13 = (Mission *)Agent::getMission(pAVar26);
                    iVar7 = Mission::getType(pMVar13);
                    pSVar8 = (String *)GameText::getText(pGVar3,iVar7 + 0x162);
                    AbyssEngine::String::String(aSStack_19c,pSVar8,false);
                    uVar31 = AbyssEngine::String::String(aSStack_1a4,"#M",false);
                    Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_194,aSStack_19c,uVar31);
                    AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                    AbyssEngine::String::~String((String *)aAStack_d4);
                    AbyssEngine::String::~String(aSStack_1a4);
                    AbyssEngine::String::~String(aSStack_19c);
                    AbyssEngine::String::~String(aSStack_194);
                    iVar7 = Status::hardCoreMode();
                    if (iVar7 == 1) {
                      AbyssEngine::String::String(aSStack_12c,"\n",false);
                      pSVar8 = (String *)GameText::getText(Globals::gameText,0x1b);
                      AbyssEngine::operator+(aAStack_124,aSStack_12c,pSVar8);
                      AbyssEngine::String::String(aSStack_1ac,": ",false);
                      AbyssEngine::operator+((AbyssEngine *)local_ec,aAStack_124,aSStack_1ac);
                      pMVar13 = (Mission *)Agent::getMission(pAVar26);
                      Mission::getReward(pMVar13);
                      pMVar13 = (Mission *)Agent::getMission(pAVar26);
                      Mission::getBonus(pMVar13);
                      Layout::formatCredits((int)aSStack_1bc);
                      AbyssEngine::String::String(aSStack_1b4,aSStack_1bc,false);
                      AbyssEngine::operator+
                                ((AbyssEngine *)aAStack_d4,(String *)local_ec,aSStack_1b4);
                      AbyssEngine::String::operator+=
                                ((String *)auStack_98,(AbyssEngine *)aAStack_d4);
                      AbyssEngine::String::~String((String *)aAStack_d4);
                      AbyssEngine::String::~String(aSStack_1b4);
                      AbyssEngine::String::~String(aSStack_1bc);
                      AbyssEngine::String::~String((String *)local_ec);
                      AbyssEngine::String::~String(aSStack_1ac);
                      AbyssEngine::String::~String((String *)aAStack_124);
                      AbyssEngine::String::~String(aSStack_12c);
                    }
                  }
                  else {
                    pSVar8 = (String *)GameText::getText(Globals::gameText,0x35f);
                    AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                  }
                  pMVar13 = (Mission *)Status::getFreelanceMission(Globals::status);
                  if ((pMVar13 != (Mission *)0x0) && (iVar7 = Mission::isEmpty(pMVar13), iVar7 == 0)
                     ) {
                    pSVar19 = (String *)local_ec;
                    AbyssEngine::String::String(pSVar19," ",false);
                    pSVar8 = (String *)GameText::getText(Globals::gameText,0x360);
                    AbyssEngine::operator+((AbyssEngine *)aAStack_d4,pSVar19,pSVar8);
                    AbyssEngine::String::operator+=((String *)auStack_98,(String *)aAStack_d4);
                    AbyssEngine::String::~String((String *)aAStack_d4);
                    goto LAB_001a1afc;
                  }
                  break;
                }
                pMVar13 = (Mission *)Agent::getMission(pAVar26);
                iVar7 = Mission::getProductionGoodAmount(pMVar13);
                pSVar17 = (Ship *)Status::getShip(Globals::status);
                iVar7 = Ship::spaceAvailable(pSVar17,iVar7);
                if (iVar7 != 0) goto LAB_001a1890;
                pSVar8 = (String *)GameText::getText(Globals::gameText,0x151);
                AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                pSVar2 = Globals::status;
                AbyssEngine::String::String(aSStack_14c,(String *)auStack_98,false);
                local_ec[0] = 0;
                AbyssEngine::String::Set(CONCAT44(extraout_r1,local_ec));
                AbyssEngine::String::String(aSStack_154,(String *)local_ec,false);
                uVar31 = AbyssEngine::String::String(aSStack_15c,"#Q",false);
                Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_14c,aSStack_154,uVar31);
                AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                AbyssEngine::String::~String((String *)aAStack_d4);
                AbyssEngine::String::~String(aSStack_15c);
                AbyssEngine::String::~String(aSStack_154);
                AbyssEngine::String::~String((String *)local_ec);
                pSVar19 = aSStack_14c;
LAB_001a0a56:
                AbyssEngine::String::~String(pSVar19);
                ChoiceWindow::set(*(String **)(this + 8),(bool)((char)&stack0xffffffe8 + -0x80));
                this[0x1b] = (SpaceLounge)0x1;
                goto LAB_001a1b14;
              case 1:
                *(undefined4 *)(this + 0x14) = 0;
LAB_001a1ba4:
                AbyssEngine::String::~String((String *)auStack_98);
                goto LAB_001a1bbc;
              case 2:
              case 3:
              case 4:
              case 8:
              case 9:
              case 10:
                fVar28 = 1.0;
                if (Globals::options[0x38] == '\0') {
                  fVar28 = 2.0;
                }
                fVar29 = 1.0;
                if (iVar7 - 8U < 3) {
                  fVar29 = fVar28;
                }
                uVar31 = Status::getCredits(Globals::status);
                uVar12 = Agent::getSellItemPrice(pAVar26);
                pSVar2 = Globals::status;
                fVar28 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
                fVar30 = (float)VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
                in_fpscr = in_fpscr & 0xfffffff;
                if (fVar30 < fVar29 * fVar28) {
                  pSVar25 = *(String **)(this + 8);
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0xcb);
                  AbyssEngine::String::String(aSStack_1c4,pSVar8,false);
                  uVar31 = Agent::getSellItemPrice(pAVar26);
                  uVar12 = Status::getCredits(Globals::status);
                  VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
                  VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_1cc,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_1d4,"#C",false);
                  Status::replaceHash(aAStack_d4,pSVar2,aSStack_1c4,aSStack_1cc,uVar31);
                  ChoiceWindow::set(pSVar25,(bool)(cVar1 + 'P'));
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_1d4);
                  AbyssEngine::String::~String(aSStack_1cc);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_1c4;
LAB_001a1ca0:
                  AbyssEngine::String::~String(pSVar19);
                  goto LAB_001a1ca4;
                }
                switch(iVar7) {
                case 2:
                case 9:
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0x364);
                  AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_26c,(String *)auStack_98,false);
                  uVar31 = Agent::getSellItemQuantity(pAVar26);
                  local_ec[0] = 0;
                  AbyssEngine::String::Set(CONCAT44(uVar31,local_ec));
                  AbyssEngine::String::String(aSStack_274,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_27c,"#Q",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_26c,aSStack_274,uVar31);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_27c);
                  AbyssEngine::String::~String(aSStack_274);
                  AbyssEngine::String::~String((String *)local_ec);
                  AbyssEngine::String::~String(aSStack_26c);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_284,(String *)auStack_98,false);
                  pGVar3 = Globals::gameText;
                  iVar7 = Agent::getSellItemIndex(pAVar26);
                  pSVar8 = (String *)GameText::getText(pGVar3,iVar7 + 0x4fa);
                  AbyssEngine::String::String(aSStack_28c,pSVar8,false);
                  uVar31 = AbyssEngine::String::String(aSStack_294,"#P",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_284,aSStack_28c,uVar31);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_294);
                  AbyssEngine::String::~String(aSStack_28c);
                  AbyssEngine::String::~String(aSStack_284);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_29c,(String *)auStack_98,false);
                  uVar31 = Agent::getSellItemPrice(pAVar26);
                  VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_2a4,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_2ac,"#C",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_29c,aSStack_2a4,uVar31);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_2ac);
                  AbyssEngine::String::~String(aSStack_2a4);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_29c;
                  break;
                case 3:
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0x365);
                  AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_20c,(String *)auStack_98,false);
                  iVar7 = Globals::items;
                  pGVar3 = Globals::gameText;
                  iVar15 = Agent::getSellBlueprintIndex(pAVar26);
                  iVar7 = Item::getIndex(*(Item **)(*(int *)(iVar7 + 4) + iVar15 * 4));
                  pSVar8 = (String *)GameText::getText(pGVar3,iVar7 + 0x4fa);
                  AbyssEngine::String::String(aSStack_214,pSVar8,false);
                  uVar31 = AbyssEngine::String::String(aSStack_21c,"#P",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_20c,aSStack_214,uVar31);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_21c);
                  AbyssEngine::String::~String(aSStack_214);
                  AbyssEngine::String::~String(aSStack_20c);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_224,(String *)auStack_98,false);
                  Agent::getSellItemPrice(pAVar26);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_22c,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_234,"#C",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_224,aSStack_22c,uVar31);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_234);
                  AbyssEngine::String::~String(aSStack_22c);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_224;
                  break;
                case 4:
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0x366);
                  AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                  this_00 = Globals::galaxy;
                  iVar7 = Agent::getSellSystemIndex(pAVar26);
                  Galaxy::getSystem(this_00,iVar7);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_23c,(String *)auStack_98,false);
                  SolarSystem::getName();
                  AbyssEngine::String::String(aSStack_244,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_24c,"#S",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_23c,aSStack_244,uVar31);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_24c);
                  AbyssEngine::String::~String(aSStack_244);
                  AbyssEngine::String::~String((String *)local_ec);
                  AbyssEngine::String::~String(aSStack_23c);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_254,(String *)auStack_98,false);
                  Agent::getSellItemPrice(pAVar26);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_25c,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_264,"#C",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_254,aSStack_25c,uVar31);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_264);
                  AbyssEngine::String::~String(aSStack_25c);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_254;
                  break;
                default:
                  goto switchD_001a0acc_default;
                case 8:
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0x367);
                  AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_1dc,(String *)auStack_98,false);
                  uVar31 = Agent::getSellItemPrice(pAVar26);
                  VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_1e4,(String *)local_ec,false);
                  AbyssEngine::String::String(aSStack_1ec,"#C",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_1dc,aSStack_1e4,
                                      aSStack_1ec);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_1ec);
                  AbyssEngine::String::~String(aSStack_1e4);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_1dc;
                  break;
                case 10:
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0x369);
                  AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                  pSVar2 = Globals::status;
                  AbyssEngine::String::String(aSStack_1f4,(String *)auStack_98,false);
                  uVar31 = Agent::getSellItemPrice(pAVar26);
                  VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_1fc,(String *)local_ec,false);
                  AbyssEngine::String::String(aSStack_204,"#C",false);
                  Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_1f4,aSStack_1fc,
                                      aSStack_204);
                  AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_204);
                  AbyssEngine::String::~String(aSStack_1fc);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_1f4;
                }
LAB_001a1afc:
                AbyssEngine::String::~String(pSVar19);
                break;
              case 6:
                iVar7 = Status::getWingmen(Globals::status);
                if (iVar7 == 0) {
                  iVar7 = Status::getCredits(Globals::status);
                  iVar15 = Agent::getCosts(pAVar26);
                  pGVar3 = Globals::gameText;
                  pSVar2 = Globals::status;
                  if (iVar15 <= iVar7) {
                    iVar7 = Achievements::gotAllMedals(Globals::achievements);
                    iVar15 = 0x362;
                    if (iVar7 != 0) {
                      iVar15 = 0x363;
                    }
                    pSVar8 = (String *)GameText::getText(pGVar3,iVar15);
                    AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                    pSVar2 = Globals::status;
                    AbyssEngine::String::String(aSStack_2cc,(String *)auStack_98,false);
                    Agent::getWingmanFriendsCount(pAVar26);
                    local_ec[0] = 0;
                    AbyssEngine::String::Set(ZEXT48(local_ec));
                    AbyssEngine::String::String(aSStack_2d4,(String *)local_ec,false);
                    AbyssEngine::String::String(aSStack_2dc,"#Q",false);
                    Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_2cc,aSStack_2d4,
                                        aSStack_2dc);
                    AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                    AbyssEngine::String::~String((String *)aAStack_d4);
                    AbyssEngine::String::~String(aSStack_2dc);
                    AbyssEngine::String::~String(aSStack_2d4);
                    AbyssEngine::String::~String((String *)local_ec);
                    AbyssEngine::String::~String(aSStack_2cc);
                    pSVar2 = Globals::status;
                    AbyssEngine::String::String(aSStack_2e4,(String *)auStack_98,false);
                    Agent::getCosts(pAVar26);
                    Layout::formatCredits((int)local_ec);
                    AbyssEngine::String::String(aSStack_2ec,(String *)local_ec,false);
                    uVar31 = AbyssEngine::String::String(aSStack_2f4,"#C",false);
                    Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_2e4,aSStack_2ec,uVar31);
                    AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                    AbyssEngine::String::~String((String *)aAStack_d4);
                    AbyssEngine::String::~String(aSStack_2f4);
                    AbyssEngine::String::~String(aSStack_2ec);
                    AbyssEngine::String::~String((String *)local_ec);
                    pSVar19 = aSStack_2e4;
                    goto LAB_001a1afc;
                  }
                  pSVar25 = *(String **)(this + 8);
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0xcb);
                  AbyssEngine::String::String(aSStack_2b4,pSVar8,false);
                  Agent::getCosts(pAVar26);
                  Status::getCredits(Globals::status);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_2bc,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_2c4,"#C",false);
                  Status::replaceHash(aAStack_d4,pSVar2,aSStack_2b4,aSStack_2bc,uVar31);
                  ChoiceWindow::set(pSVar25,(bool)(cVar1 + 'P'));
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_2c4);
                  AbyssEngine::String::~String(aSStack_2bc);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_2b4;
                  goto LAB_001a1ca0;
                }
                pSVar8 = *(String **)(this + 8);
                bVar6 = (bool)GameText::getText(Globals::gameText,0x311);
                ChoiceWindow::set(pSVar8,bVar6);
LAB_001a1ca4:
                this[0x1b] = (SpaceLounge)0x1;
                pSVar19 = (String *)auStack_98;
                goto LAB_001a1b9a;
              case 7:
                iVar7 = Status::getCredits(Globals::status);
                iVar15 = Agent::getCosts(pAVar26);
                pSVar2 = Globals::status;
                if (iVar7 < iVar15) {
                  pSVar25 = *(String **)(this + 8);
                  pSVar8 = (String *)GameText::getText(Globals::gameText,0xcb);
                  AbyssEngine::String::String(aSStack_dc,pSVar8,false);
                  Agent::getCosts(pAVar26);
                  Status::getCredits(Globals::status);
                  Layout::formatCredits((int)local_ec);
                  AbyssEngine::String::String(aSStack_e4,(String *)local_ec,false);
                  uVar31 = AbyssEngine::String::String(aSStack_f4,"#C",false);
                  Status::replaceHash(aAStack_d4,pSVar2,aSStack_dc,aSStack_e4,uVar31);
                  ChoiceWindow::set(pSVar25,(bool)(cVar1 + 'P'));
                  AbyssEngine::String::~String((String *)aAStack_d4);
                  AbyssEngine::String::~String(aSStack_f4);
                  AbyssEngine::String::~String(aSStack_e4);
                  AbyssEngine::String::~String((String *)local_ec);
                  pSVar19 = aSStack_dc;
                  goto LAB_001a1ca0;
                }
                pSVar8 = (String *)GameText::getText(Globals::gameText,0x375);
                AbyssEngine::String::operator=((String *)auStack_98,pSVar8);
                pSVar2 = Globals::status;
                AbyssEngine::String::String(aSStack_fc,(String *)auStack_98,false);
                Agent::getCosts(pAVar26);
                Layout::formatCredits((int)local_ec);
                AbyssEngine::String::String(aSStack_104,(String *)local_ec,false);
                AbyssEngine::String::String(aSStack_10c,"#C",false);
                Status::replaceHash((String *)aAStack_d4,pSVar2,aSStack_fc,aSStack_104,aSStack_10c);
                AbyssEngine::String::operator=((String *)auStack_98,(String *)aAStack_d4);
                AbyssEngine::String::~String((String *)aAStack_d4);
                AbyssEngine::String::~String(aSStack_10c);
                AbyssEngine::String::~String(aSStack_104);
                AbyssEngine::String::~String((String *)local_ec);
                AbyssEngine::String::~String(aSStack_fc);
              }
switchD_001a0acc_default:
              ChoiceWindow::set(*(String **)(this + 8),(bool)((char)&stack0xffffffe8 + -0x80));
              this[0x19] = (SpaceLounge)0x1;
LAB_001a1b14:
              AbyssEngine::String::~String((String *)auStack_98);
              break;
            case 1:
              pSVar23 = *(ScrollTouchWindow **)(this + 0x60);
              Agent::getName();
              pGVar3 = Globals::gameText;
              iVar7 = AbyssEngine::AERandom::nextInt(Globals::rnd,5);
              pSVar8 = (String *)GameText::getText(pGVar3,iVar7 + 0x34d);
              AbyssEngine::String::String(aSStack_304,pSVar8,false);
              ScrollTouchWindow::setText(pSVar23,aSStack_2fc,aSStack_304);
              AbyssEngine::String::~String(aSStack_304);
              AbyssEngine::String::~String(aSStack_2fc);
              *(undefined4 *)(this + 0x14) = 0;
              *(undefined4 *)(this + 0x2c) = 0;
              *(int *)(Globals::status + 0xe0) = *(int *)(Globals::status + 0xe0) + 1;
              break;
            case 2:
              if (*(int *)(this + 0xc) == 0) {
                pLVar14 = operator_new(0x134);
                ListItemWindow::ListItemWindow(pLVar14);
                *(ListItemWindow **)(this + 0xc) = pLVar14;
              }
              iVar7 = Agent::getOffer(*(Agent **)
                                       (*(int *)(*(int *)(this + 0x24) + 4) +
                                       *(int *)(this + 0x20) * 4));
              if ((iVar7 == 2) ||
                 (iVar7 = Agent::getOffer(*(Agent **)
                                           (*(int *)(*(int *)(this + 0x24) + 4) +
                                           *(int *)(this + 0x20) * 4)), iVar7 == 9)) {
                pLVar14 = *(ListItemWindow **)(this + 0xc);
                this_03 = operator_new(0x48);
                iVar7 = Globals::items;
                iVar15 = Agent::getSellItemIndex
                                   (*(Agent **)
                                     (*(int *)(*(int *)(this + 0x24) + 4) +
                                     *(int *)(this + 0x20) * 4));
                ::ListItem::ListItem(this_03,*(Item **)(*(int *)(iVar7 + 4) + iVar15 * 4));
LAB_001a0df0:
                ListItemWindow::set(pLVar14,this_03,0,0,0,0,false);
              }
              else {
                iVar7 = Agent::getOffer(*(Agent **)
                                         (*(int *)(*(int *)(this + 0x24) + 4) +
                                         *(int *)(this + 0x20) * 4));
                if (iVar7 == 10) {
                  pEVar16 = (Engine *)
                            AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
                  SVar5 = (SpaceLounge)AbyssEngine::Engine::IsPostEffectActivated(pEVar16);
                  this[0xad] = SVar5;
                  pEVar16 = (Engine *)
                            AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
                  AbyssEngine::Engine::SetPostEffect(pEVar16,0x1400000,false);
                  pLVar14 = *(ListItemWindow **)(this + 0xc);
                  this_03 = operator_new(0x48);
                  iVar7 = Globals::ships;
                  iVar15 = Agent::getSellItemIndex
                                     (*(Agent **)
                                       (*(int *)(*(int *)(this + 0x24) + 4) +
                                       *(int *)(this + 0x20) * 4));
                  ::ListItem::ListItem(this_03,*(Ship **)(*(int *)(iVar7 + 4) + iVar15 * 4));
                  goto LAB_001a0df0;
                }
                piVar18 = (int *)Status::getBluePrints(Globals::status);
                if (*piVar18 != 0) {
                  uVar20 = 0;
                  do {
                    iVar7 = Status::getBluePrints(Globals::status);
                    iVar7 = BluePrint::getIndex(*(BluePrint **)(*(int *)(iVar7 + 4) + uVar20 * 4));
                    iVar15 = Agent::getSellBlueprintIndex
                                       (*(Agent **)
                                         (*(int *)(*(int *)(this + 0x24) + 4) +
                                         *(int *)(this + 0x20) * 4));
                    if (iVar7 == iVar15) {
                      pLVar14 = *(ListItemWindow **)(this + 0xc);
                      this_03 = operator_new(0x48);
                      iVar7 = Globals::items;
                      iVar15 = Status::getBluePrints(Globals::status);
                      iVar15 = BluePrint::getIndex(*(BluePrint **)
                                                    (*(int *)(iVar15 + 4) + uVar20 * 4));
                      ::ListItem::ListItem(this_03,*(Item **)(*(int *)(iVar7 + 4) + iVar15 * 4));
                      goto LAB_001a0df0;
                    }
                    puVar10 = (uint *)Status::getBluePrints(Globals::status);
                    uVar20 = uVar20 + 1;
                  } while (uVar20 < *puVar10);
                }
              }
              this[0x1c] = (SpaceLounge)0x1;
              break;
            case 3:
              pAVar26 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4)
              ;
              pAVar26[0x1d] = (Agent)0x1;
              pMVar13 = (Mission *)Agent::getMission(pAVar26);
              iVar7 = Mission::getTargetStation(pMVar13);
              this_04 = (Station *)Status::getStation(Globals::status);
              iVar15 = Station::getIndex(this_04);
              if (iVar7 == iVar15) {
                pSVar23 = *(ScrollTouchWindow **)(this + 0x60);
                Agent::getName();
                pSVar8 = (String *)GameText::getText(Globals::gameText,0x325);
                this_05 = aSStack_314;
                AbyssEngine::String::String(this_05,pSVar8,false);
                pSVar19 = aSStack_30c;
                ScrollTouchWindow::setText(pSVar23,pSVar19,this_05);
              }
              else {
                pSVar11 = (SolarSystem *)Status::getSystem(Globals::status);
                pMVar13 = (Mission *)
                          Agent::getMission(*(Agent **)
                                             (*(int *)(*(int *)(this + 0x24) + 4) +
                                             *(int *)(this + 0x20) * 4));
                iVar7 = Mission::getTargetStation(pMVar13);
                iVar7 = SolarSystem::stationIsInSystem(pSVar11,iVar7);
                if (iVar7 != 1) {
                  iVar7 = AbyssEngine::ApplicationManager::GetApplicationModule
                                    (Globals::appManager,5);
                  pSVar24 = *(StarMap **)(iVar7 + 0x10);
                  *(StarMap **)(this + 4) = pSVar24;
                  if (pSVar24 == (StarMap *)0x0) {
                    pSVar24 = operator_new(0x1e8);
                    pMVar13 = (Mission *)
                              Agent::getMission(*(Agent **)
                                                 (*(int *)(*(int *)(this + 0x24) + 4) +
                                                 *(int *)(this + 0x20) * 4));
                    StarMap::StarMap(pSVar24,true,pMVar13,false,-1);
                    iVar7 = AbyssEngine::ApplicationManager::GetApplicationModule
                                      (Globals::appManager,5);
                    *(StarMap **)(iVar7 + 0x10) = pSVar24;
                    iVar7 = AbyssEngine::ApplicationManager::GetApplicationModule
                                      (Globals::appManager,5);
                    *(undefined4 *)(this + 4) = *(undefined4 *)(iVar7 + 0x10);
                  }
                  else {
                    pMVar13 = (Mission *)
                              Agent::getMission(*(Agent **)
                                                 (*(int *)(*(int *)(this + 0x24) + 4) +
                                                 *(int *)(this + 0x20) * 4));
                    StarMap::init(pSVar24,true,pMVar13,false,-1);
                  }
                  this[0x34] = (SpaceLounge)0x1;
                  break;
                }
                pSVar23 = *(ScrollTouchWindow **)(this + 0x60);
                Agent::getName();
                pSVar8 = (String *)GameText::getText(Globals::gameText,0x326);
                this_05 = aSStack_324;
                AbyssEngine::String::String(this_05,pSVar8,false);
                pSVar19 = aSStack_31c;
                ScrollTouchWindow::setText(pSVar23,pSVar19,this_05);
              }
              AbyssEngine::String::~String(this_05);
              AbyssEngine::String::~String(pSVar19);
              *(undefined4 *)(this + 0x14) = 2;
              *(undefined4 *)(this + 0x2c) = 0;
              break;
            case 4:
              this_02 = *(Agent **)(*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4)
              ;
              this_02[0x1c] = (Agent)0x1;
              pMVar13 = (Mission *)Agent::getMission(this_02);
              uVar31 = Mission::getDifficulty(pMVar13);
              pSVar23 = *(ScrollTouchWindow **)(this + 0x60);
              Agent::getName();
              fVar28 = (float)VectorSignedToFloat(uVar31,(byte)(in_fpscr >> 0x16) & 3);
              pSVar8 = (String *)
                       GameText::getText(Globals::gameText,(int)((fVar28 / 10.0) * 5.0) + 0x328);
              AbyssEngine::String::String(aSStack_334,pSVar8,false);
              ScrollTouchWindow::setText(pSVar23,aSStack_32c,aSStack_334);
              AbyssEngine::String::~String(aSStack_334);
              AbyssEngine::String::~String(aSStack_32c);
              *(undefined4 *)(this + 0x14) = 2;
              this[0x36] = (SpaceLounge)0x1;
              *(undefined4 *)(this + 0x2c) = 0;
              Agent::getRace(pAVar26);
            }
            iVar7 = Agent::isGenericAgent
                              (*(Agent **)
                                (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4));
            if (iVar7 == 1) {
              Agent::setEvent(*(Agent **)
                               (*(int *)(*(int *)(this + 0x24) + 4) + *(int *)(this + 0x20) * 4),1);
            }
          }
          puVar10 = *(uint **)(this + 0x5c);
          uVar27 = uVar27 + 1;
        } while (uVar27 < *puVar10);
      }
      break;
    case 3:
      iVar7 = TouchButton::OnTouchEnd
                        ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x5c) + 4),param_1,param_2
                        );
      if (iVar7 == 1) goto switchD_001a04a4_caseD_1;
    }
    ScrollTouchWindow::OnTouchEnd(*(int *)(this + 0x60),param_1);
    iVar7 = Layout::helpPressed(Globals::layout);
    pLVar4 = Globals::layout;
    if (iVar7 != 1) goto LAB_001a1bbc;
    pSVar8 = (String *)GameText::getText(Globals::gameText,0x273);
    AbyssEngine::String::String(aSStack_33c,pSVar8,false);
    Layout::initHelpWindow(pLVar4,aSStack_33c);
    pSVar19 = aSStack_33c;
  }
  else {
    ListItemWindow::OnTouchEnd(*(int *)(this + 0xc),param_1);
    iVar7 = Layout::helpPressed(Globals::layout);
    pLVar4 = Globals::layout;
    if (iVar7 != 1) goto LAB_001a1bbc;
    pSVar8 = (String *)GameText::getText(Globals::gameText,0x283);
    AbyssEngine::String::String(aSStack_5c,pSVar8,false);
    Layout::initHelpWindow(pLVar4,aSStack_5c);
    pSVar19 = aSStack_5c;
  }
LAB_001a1b9a:
  AbyssEngine::String::~String(pSVar19);
LAB_001a1bbc:
  if (__stack_chk_guard - iStack_54 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - iStack_54);
  }
  return;
}

// ===== SpaceLounge::OnRender3D  @0x001a2490  (54 bytes)
/* SpaceLounge::OnRender3D() */

void __thiscall SpaceLounge::OnRender3D(SpaceLounge *this)

{
  CutScene *this_00;
  int iVar1;
  
  if (this[0x34] != (SpaceLounge)0x0) {
    StarMap::render(*(StarMap **)(this + 4));
    return;
  }
  this_00 = *(CutScene **)(this + 0x44);
  if (this_00 == (CutScene *)0x0) {
    return;
  }
  if (this[0x1c] != (SpaceLounge)0x0) {
    iVar1 = ListItemWindow::shows3DShip(*(ListItemWindow **)(this + 0xc));
    if (iVar1 != 0) {
      return;
    }
    this_00 = *(CutScene **)(this + 0x44);
  }
  CutScene::render3D(this_00);
  return;
}

// ===== SpaceLounge::OnRenderBG  @0x001a24c2  (14 bytes)
/* SpaceLounge::OnRenderBG() */

void __thiscall SpaceLounge::OnRenderBG(SpaceLounge *this)

{
  if (*(CutScene **)(this + 0x44) == (CutScene *)0x0) {
    return;
  }
  CutScene::renderBG(*(CutScene **)(this + 0x44));
  return;
}

