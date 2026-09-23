// Class: MenuTouchWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MenuTouchWindow::MenuTouchWindow  @0x0014816c  (10470 bytes)
/* MenuTouchWindow::MenuTouchWindow(int) */

void __thiscall MenuTouchWindow::MenuTouchWindow(MenuTouchWindow *this,int param_1)

{
  undefined4 uVar1;
  Globals *pGVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  String *pSVar5;
  Mission *pMVar6;
  TouchButton *pTVar7;
  void *pvVar8;
  TouchButton *pTVar9;
  int iVar10;
  TouchButton *this_00;
  uint *puVar11;
  Array *pAVar12;
  ScrollTouchWindow *pSVar13;
  TouchSlider *pTVar14;
  String *pSVar15;
  ChoiceWindow *pCVar16;
  ushort uVar17;
  MenuTouchWindow *pMVar18;
  uint uVar19;
  float *pfVar20;
  int *piVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  undefined4 uVar25;
  int iVar26;
  undefined4 uVar27;
  int iVar28;
  int iVar29;
  bool bVar30;
  uint in_fpscr;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  String aSStack_18c [8];
  String aSStack_184 [8];
  String aSStack_17c [8];
  String aSStack_174 [8];
  String aSStack_16c [8];
  AbyssEngine aAStack_164 [8];
  AbyssEngine aAStack_15c [8];
  AbyssEngine aAStack_154 [8];
  String aSStack_14c [8];
  AbyssEngine aAStack_144 [8];
  uint local_13c;
  uint local_138;
  String aSStack_134 [8];
  String aSStack_12c [8];
  String aSStack_124 [8];
  String aSStack_11c [12];
  float local_110;
  String aSStack_108 [8];
  String aSStack_100 [8];
  String aSStack_f8 [8];
  String aSStack_f0 [8];
  String aSStack_e8 [8];
  String aSStack_e0 [4];
  uint local_dc;
  float local_d8;
  float local_d4;
  undefined4 local_d0;
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
  String aSStack_4c [8];
  String aSStack_44 [8];
  int local_3c;
  
  iVar22 = Globals::layout;
  local_3c = __stack_chk_guard;
  uVar27 = *(undefined4 *)(Globals::layout + 0x298);
  uVar25 = *(undefined4 *)(Globals::layout + 0x29c);
  uVar1 = *(undefined4 *)(Globals::layout + 0x2a0);
  pMVar18 = this + 0x1a8;
  *(undefined4 *)pMVar18 = *(undefined4 *)(Globals::layout + 0x294);
  *(undefined4 *)(this + 0x1ac) = uVar27;
  *(undefined4 *)(this + 0x1b0) = uVar25;
  *(undefined4 *)(this + 0x1b4) = uVar1;
  *(undefined4 *)(this + 0x1b8) = *(undefined4 *)(iVar22 + 0x2a4);
  *(undefined4 *)(this + 0x1bc) = *(undefined4 *)(iVar22 + 0x2a8);
  *(undefined4 *)(this + 0x1c0) = *(undefined4 *)(iVar22 + 0x2ac);
  uVar27 = *(undefined4 *)(iVar22 + 0x2b0);
  *(int *)(this + 0x168) = param_1;
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  *puVar4 = 0;
  puVar3[2] = 1;
  *puVar3 = 0;
  *(undefined4 **)(this + 4) = puVar3;
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  puVar3[2] = 1;
  *puVar4 = 0;
  *puVar3 = 0;
  *(undefined4 **)(this + 0xc0) = puVar3;
  *(undefined4 *)(this + 0xe4) = 0;
  *(undefined4 *)(this + 0xe8) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *this = (MenuTouchWindow)0x0;
  *(undefined4 *)(this + 0x120) = 0xffffffff;
  *(undefined4 *)(this + 0x18c) = 0;
  this[0x1c4] = (MenuTouchWindow)0x0;
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined4 *)(this + 0xf4) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined4 *)(this + 0x230) = 0;
  *(undefined4 *)(this + 0x234) = 0;
  this[0x238] = (MenuTouchWindow)0x0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  loadPreviewRecords(this);
  if (param_1 == 0) {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1b5a,(uint *)(this + 0x120));
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x1c);
    AbyssEngine::String::String(aSStack_44,pSVar5,false);
    addButton(this,0,aSStack_44,0,*(undefined4 *)(this + 4),uVar27);
    AbyssEngine::String::~String(aSStack_44);
    if (Globals::lastRecordWritten < 0) {
LAB_00148720:
      iVar22 = 1;
    }
    else {
      iVar22 = 1;
      if ((*(int *)(this + 0xbc) != 0) && (Globals::lastRecordWritten < Globals::recordSlots)) {
        if (*(int *)(*(int *)(*(int *)(this + 0xbc) + 4) + Globals::lastRecordWritten * 4) == 0)
        goto LAB_00148720;
        pSVar5 = (String *)GameText::getText(Globals::gameText,0x29);
        AbyssEngine::String::String(aSStack_4c,pSVar5,false);
        addButton(this,0xb,aSStack_4c,1,*(undefined4 *)(this + 4),uVar27);
        AbyssEngine::String::~String(aSStack_4c);
        iVar22 = 2;
      }
    }
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x1d);
    AbyssEngine::String::String(aSStack_54,pSVar5,false);
    addButton(this,1,aSStack_54,iVar22,*(undefined4 *)(this + 4),uVar27);
    AbyssEngine::String::~String(aSStack_54);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x1f);
    AbyssEngine::String::String(aSStack_5c,pSVar5,false);
    addButton(this,3,aSStack_5c,iVar22 + 1,*(undefined4 *)(this + 4),uVar27);
    iVar10 = iVar22 + 2;
    AbyssEngine::String::~String(aSStack_5c);
    if (Globals::iPad != '\0') {
      pSVar5 = (String *)GameText::getText(Globals::gameText,0);
      AbyssEngine::String::String(aSStack_64,pSVar5,false);
      addButton(this,0x19,aSStack_64,iVar10,*(undefined4 *)(this + 4),uVar27);
      AbyssEngine::String::~String(aSStack_64);
      iVar10 = iVar22 + 3;
    }
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x2b);
    AbyssEngine::String::String(aSStack_6c,pSVar5,false);
    addButton(this,4,aSStack_6c,iVar10,*(undefined4 *)(this + 4),uVar27);
    pSVar15 = aSStack_6c;
LAB_0014883e:
    AbyssEngine::String::~String(pSVar15);
LAB_00148842:
    if (param_1 != 1) goto LAB_0014884e;
    bVar30 = false;
  }
  else {
    if (param_1 == 1) {
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x534,(uint *)(this + 0x120));
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x1f);
      AbyssEngine::String::String(aSStack_a4,pSVar5,false);
      addButton(this,3,aSStack_a4,0,*(undefined4 *)(this + 4),0);
      AbyssEngine::String::~String(aSStack_a4);
      iVar22 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar22 < 0x10) || (iVar22 = Status::inAlienOrbit(Globals::status), iVar22 != 0)) {
LAB_001484c6:
        iVar22 = 1;
      }
      else {
        pMVar6 = (Mission *)Status::getMission(Globals::status);
        iVar22 = Mission::getType(pMVar6);
        if (iVar22 == 0xb7) goto LAB_001484c6;
        pSVar5 = (String *)GameText::getText(Globals::gameText,0x81);
        AbyssEngine::String::String(aSStack_ac,pSVar5,false);
        addButton(this,10,aSStack_ac,1,*(undefined4 *)(this + 4),0);
        AbyssEngine::String::~String(aSStack_ac);
        iVar22 = 2;
      }
      iVar10 = Status::getCurrentCampaignMission(Globals::status);
      if (1 < iVar10) {
        pMVar6 = (Mission *)Status::getMission(Globals::status);
        iVar10 = Mission::getType(pMVar6);
        if (iVar10 != 0xb7) {
          pSVar5 = (String *)GameText::getText(Globals::gameText,0xa6);
          AbyssEngine::String::String(aSStack_b4,pSVar5,false);
          addButton(this,0xc,aSStack_b4,iVar22,*(undefined4 *)(this + 4),0);
          AbyssEngine::String::~String(aSStack_b4);
          iVar22 = iVar22 + 1;
        }
      }
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x20a);
      AbyssEngine::String::String(aSStack_bc,pSVar5,false);
      addButton(this,6,aSStack_bc,iVar22,*(undefined4 *)(this + 4),0);
      AbyssEngine::String::~String(aSStack_bc);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x3b);
      AbyssEngine::String::String(aSStack_c4,pSVar5,false);
      addButton(this,0x13,aSStack_c4,iVar22 + 1,*(undefined4 *)(this + 4),0);
      AbyssEngine::String::~String(aSStack_c4);
      iVar10 = Status::getCurrentCampaignMission(Globals::status);
      if ((iVar10 - 0x9aU < 5) && ((1 << (iVar10 - 0x9aU & 0xff) & 0x19U) != 0)) {
        pSVar5 = (String *)GameText::getText(Globals::gameText,0x18b);
        AbyssEngine::String::String(aSStack_cc,pSVar5,false);
        addButton(this,0x12,aSStack_cc,iVar22 + 2,*(undefined4 *)(this + 4),0);
        AbyssEngine::String::~String(aSStack_cc);
      }
      pTVar7 = operator_new(0xc0);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x3d);
      TouchButton::TouchButton
                (pTVar7,pSVar5,0,Globals::w - *(int *)(Globals::layout + 0x2c),
                 Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
      *(undefined4 *)pTVar7 = 0x14;
      *(undefined4 *)(pTVar7 + 4) = 0;
      piVar21 = *(int **)(this + 0xc0);
      piVar21[2] = *piVar21 + 1;
      pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
      piVar21[1] = (int)pvVar8;
      *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar7;
      *piVar21 = piVar21[2];
      pTVar9 = operator_new(0xc0);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x3c);
      iVar22 = Globals::w;
      iVar23 = *(int *)(Globals::layout + 0x2c);
      iVar10 = TouchButton::getWidth(pTVar7);
      TouchButton::TouchButton
                (pTVar9,pSVar5,0,(iVar22 + iVar23 * -2) - iVar10,
                 Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
      *(undefined4 *)pTVar9 = 0x15;
      *(undefined4 *)(pTVar9 + 4) = 0;
      piVar21 = *(int **)(this + 0xc0);
      piVar21[2] = *piVar21 + 1;
      pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
      piVar21[1] = (int)pvVar8;
      *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar9;
      *piVar21 = piVar21[2];
      TouchButton::setPosition
                (pTVar9,Globals::w - *(int *)(Globals::layout + 0x2c),
                 Globals::h - *(int *)(Globals::layout + 0x2c));
      goto LAB_00148842;
    }
    if (param_1 == 2) {
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x1c);
      AbyssEngine::String::String(aSStack_74,pSVar5,false);
      addButton(this,0,aSStack_74,0,*(undefined4 *)(this + 4),0);
      AbyssEngine::String::~String(aSStack_74);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x1d);
      AbyssEngine::String::String(aSStack_7c,pSVar5,false);
      addButton(this,1,aSStack_7c,1,*(undefined4 *)(this + 4),0);
      AbyssEngine::String::~String(aSStack_7c);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x1e);
      AbyssEngine::String::String(aSStack_84,pSVar5,false);
      addButton(this,2,aSStack_84,2,*(undefined4 *)(this + 4),0);
      AbyssEngine::String::~String(aSStack_84);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x1f);
      AbyssEngine::String::String(aSStack_8c,pSVar5,false);
      addButton(this,3,aSStack_8c,3,*(undefined4 *)(this + 4),0);
      AbyssEngine::String::~String(aSStack_8c);
      if (Globals::iPad == '\0') {
        uVar27 = 4;
      }
      else {
        pSVar5 = (String *)GameText::getText(Globals::gameText,0);
        AbyssEngine::String::String(aSStack_94,pSVar5,false);
        addButton(this,0x19,aSStack_94,4,*(undefined4 *)(this + 4),0);
        AbyssEngine::String::~String(aSStack_94);
        uVar27 = 5;
      }
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x2b);
      AbyssEngine::String::String(aSStack_9c,pSVar5,false);
      addButton(this,4,aSStack_9c,uVar27,*(undefined4 *)(this + 4),0);
      pSVar15 = aSStack_9c;
      goto LAB_0014883e;
    }
LAB_0014884e:
    if (*(char *)(Globals::layout + 0x285) != '\0') {
      pTVar7 = operator_new(0xc0);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x21);
      TouchButton::TouchButton
                (pTVar7,pSVar5,0,Globals::w - *(int *)(Globals::layout + 0x2c),
                 Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
      *(undefined4 *)pTVar7 = 0x11;
      *(undefined4 *)(pTVar7 + 4) = 0;
      piVar21 = *(int **)(this + 0xc0);
      piVar21[2] = *piVar21 + 1;
      pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
      piVar21[1] = (int)pvVar8;
      *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar7;
      *piVar21 = piVar21[2];
    }
    bVar30 = true;
  }
  pTVar7 = operator_new(0xc0);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x3e);
  TouchButton::TouchButton
            (pTVar7,pSVar5,0,Globals::w - *(int *)(Globals::layout + 0x2c),
             Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
  *(undefined4 *)pTVar7 = 0x16;
  *(undefined4 *)(pTVar7 + 4) = 0;
  piVar21 = *(int **)(this + 0xc0);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar7;
  *piVar21 = piVar21[2];
  if (*(int *)(this + 4) == 0) {
    local_d8 = 0.0;
    local_d4 = 0.0;
    local_d0 = 0;
  }
  else {
    TouchButton::getPosition();
  }
  fVar32 = local_d8;
  iVar22 = *(int *)pMVar18;
  pTVar9 = operator_new(0xc0);
  AbyssEngine::String::String(aSStack_e0,"Leaderboards",false);
  fVar31 = (float)VectorSignedToFloat(iVar22,(byte)(in_fpscr >> 0x16) & 3);
  fVar33 = (float)VectorSignedToFloat(iVar22 / 3,(byte)(in_fpscr >> 0x16) & 3);
  TouchButton::TouchButton(pTVar9,aSStack_e0,0x11,(int)(fVar32 + fVar31 + fVar33),(int)local_d4,'D')
  ;
  AbyssEngine::String::~String(aSStack_e0);
  *(undefined4 *)pTVar9 = 0xff;
  *(undefined4 *)(pTVar9 + 4) = 0;
  piVar21 = *(int **)(this + 0xc0);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  fVar32 = local_d8;
  piVar21[1] = (int)pvVar8;
  *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar9;
  *piVar21 = piVar21[2];
  iVar22 = *(int *)(this + 0x1a8);
  pTVar9 = operator_new(0xc0);
  AbyssEngine::String::String(aSStack_e0,"Achievements",false);
  fVar31 = (float)VectorSignedToFloat(iVar22 / 3,(byte)(in_fpscr >> 0x16) & 3);
  TouchButton::TouchButton(pTVar9,aSStack_e0,0x11,(int)(fVar32 - fVar31),(int)local_d4,'D');
  AbyssEngine::String::~String(aSStack_e0);
  *(undefined4 *)pTVar9 = 0xff;
  *(undefined4 *)(pTVar9 + 4) = 0;
  piVar21 = *(int **)(this + 0xc0);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar9;
  *piVar21 = piVar21[2];
  pTVar9 = operator_new(0xc0);
  pSVar5 = (String *)GameText::getText(Globals::gameText,5000);
  iVar22 = Globals::w;
  iVar23 = *(int *)(Globals::layout + 0x2c);
  iVar10 = TouchButton::getWidth(pTVar7);
  TouchButton::TouchButton
            (pTVar9,pSVar5,0,(iVar22 + iVar23 * -2) - iVar10,
             Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
  *(undefined4 *)pTVar9 = 0x6d;
  *(undefined4 *)(pTVar9 + 4) = 0;
  piVar21 = *(int **)(this + 0xc0);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar9;
  *piVar21 = piVar21[2];
  this_00 = operator_new(0xc0);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x1389);
  iVar22 = Globals::w;
  iVar28 = *(int *)(Globals::layout + 0x2c);
  iVar10 = TouchButton::getWidth(pTVar7);
  iVar23 = TouchButton::getWidth(pTVar9);
  TouchButton::TouchButton
            (this_00,pSVar5,0,((iVar28 * -3 + iVar22) - iVar10) - iVar23,
             Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
  *(undefined4 *)this_00 = 0x6e;
  *(undefined4 *)(this_00 + 4) = 0;
  piVar21 = *(int **)(this + 0xc0);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = this_00;
  *piVar21 = piVar21[2];
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  puVar3[2] = 1;
  *puVar4 = 0;
  *puVar3 = 0;
  *(undefined4 **)(this + 0xac) = puVar3;
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x1e9);
  AbyssEngine::String::String(aSStack_e8,pSVar5,false);
  addButton(this,8,aSStack_e8,0,*(undefined4 *)(this + 0xac),0);
  AbyssEngine::String::~String(aSStack_e8);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x1f2);
  AbyssEngine::String::String(aSStack_f0,pSVar5,false);
  addButton(this,9,aSStack_f0,1,*(undefined4 *)(this + 0xac),0);
  AbyssEngine::String::~String(aSStack_f0);
  if (bVar30) {
    pSVar5 = (String *)GameText::getText(Globals::gameText,0);
    AbyssEngine::String::String(aSStack_f8,pSVar5,false);
    addButton(this,0x19,aSStack_f8,2,*(undefined4 *)(this + 0xac),0);
    AbyssEngine::String::~String(aSStack_f8);
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    uVar24 = 0;
    puVar3[1] = puVar4;
    puVar3[2] = 1;
    *puVar4 = 0;
    *puVar3 = 0;
    *(undefined4 **)(this + 0xb0) = puVar3;
    fVar31 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x34),
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar32 = fVar31 * 0.9;
    if (Globals::iPad != '\0') {
      fVar32 = fVar31;
    }
    do {
      iVar22 = (int)(Globals::w + ((uint)(Globals::w >> 0x1f) >> 0x1e)) >> 2;
      fVar31 = (float)VectorSignedToFloat(*(int *)pMVar18,(byte)(in_fpscr >> 0x16) & 3);
      if ((uVar24 & 1) != 0) {
        iVar22 = Globals::w - iVar22;
      }
      fVar33 = (float)VectorSignedToFloat(iVar22,(byte)(in_fpscr >> 0x16) & 3);
      iVar10 = Globals::h / 2 - *(int *)(this + 0x1ac);
      iVar22 = (int)fVar32 + 2 + *(int *)(Globals::layout + 0x30);
      iVar23 = (int)(fVar33 + fVar31 * -0.5);
      if (Globals::iPad == '\0') {
        iVar22 = iVar22 * ((int)uVar24 / 2) + ((iVar10 + -0xc) - *(int *)(Globals::layout + 0x29c));
      }
      else {
        iVar22 = iVar22 * uVar24 +
                 ((iVar10 - *(int *)(Globals::layout + 0x29c)) - *(int *)(Globals::layout + 0x30));
        iVar23 = Globals::w / 2 - *(int *)pMVar18 / 2;
      }
      uVar19 = Globals::font;
      if ((uVar24 | 1) == 9) {
        uVar19 = Globals::fontLangSelect;
      }
      iVar10 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,uVar19);
      iVar28 = *(int *)pMVar18;
      pTVar7 = operator_new(0xc0);
      pSVar5 = (String *)GameText::getText(Globals::gameText,(&DAT_002585a8)[uVar24]);
      TouchButton::TouchButton(pTVar7,pSVar5,0,iVar23,iVar22,iVar28,'\x11','\x04',uVar19,iVar10);
      iVar22 = (&DAT_00258580)[uVar24];
      *(int *)pTVar7 = iVar22;
      *(int *)(pTVar7 + 4) = iVar22 >> 0x1f;
      if ((uVar24 | 1) == 9) {
        *(uint *)(pTVar7 + 8) = Globals::fontLangSelect;
      }
      piVar21 = *(int **)(this + 0xb0);
      piVar21[2] = *piVar21 + 1;
      pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
      piVar21[1] = (int)pvVar8;
      uVar24 = uVar24 + 1;
      *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar7;
      *piVar21 = piVar21[2];
    } while ((int)uVar24 < 10);
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x515,(uint *)(this + 0x10c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x516,(uint *)(this + 0x110));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x517,(uint *)(this + 0x114));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x518,(uint *)(this + 0x118));
  puVar11 = operator_new__(0x14);
  *(uint **)(this + 0x134) = puVar11;
  pvVar8 = operator_new__(0x14);
  *(void **)(this + 0x138) = pvVar8;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbba,puVar11);
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,0xbbc,(uint *)(*(int *)(this + 0x134) + 4));
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,0xbc3,(uint *)(*(int *)(this + 0x134) + 8));
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,0xbc5,(uint *)(*(int *)(this + 0x134) + 0xc));
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,0xbc7,(uint *)(*(int *)(this + 0x134) + 0x10));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbbb,*(uint **)(this + 0x138));
  if (Globals::iPad == '\0') {
    uVar17 = 0xbbd;
  }
  else {
    uVar17 = 0xbc6;
  }
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,uVar17,(uint *)(*(int *)(this + 0x138) + 4));
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,0xbc4,(uint *)(*(int *)(this + 0x138) + 8));
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,0xbc6,(uint *)(*(int *)(this + 0x138) + 0xc));
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,0xbc8,(uint *)(*(int *)(this + 0x138) + 0x10));
  if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xc1d,(uint *)(this + 0x14c));
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,3000,(uint *)(this + 0x13c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbb9,(uint *)(this + 0x140));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbbe,(uint *)(this + 0x144));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbbf,(uint *)(this + 0x148));
  uVar25 = 0;
  this[0x1d9] = (MenuTouchWindow)0x0;
  uVar27 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,**(uint **)(this + 0x134));
  *(undefined4 *)(this + 0x1e4) = uVar27;
  uVar27 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,**(uint **)(this + 0x134));
  *(undefined4 *)(this + 0x1e8) = uVar27;
  iVar22 = Globals::layout;
  *(int *)(this + 0x1ec) = *(int *)(Globals::layout + 0x28) + *(int *)(Globals::layout + 0x2c);
  *(int *)(this + 0x1f0) = *(int *)(iVar22 + 0x20) + *(int *)(iVar22 + 0xc);
  if ((Globals::iPad == '\0') || (Globals::iPadAssetsWithLowerRes != '\0')) {
    uVar25 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x13c));
  }
  *(undefined4 *)(this + 500) = uVar25;
  uVar27 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,**(uint **)(this + 0x138));
  *(undefined4 *)(this + 0x1f8) = uVar27;
  uVar27 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,**(uint **)(this + 0x138));
  *(undefined4 *)(this + 0x1fc) = uVar27;
  iVar22 = Globals::layout;
  iVar10 = *(int *)(this + 0x1e8) + *(int *)(Globals::layout + 0x2c) * 2;
  *(int *)(this + 0x200) = iVar10;
  *(int *)(this + 0x204) =
       ((Globals::w - iVar10) + *(int *)(iVar22 + 0x28) * -2) - *(int *)(this + 500);
  pAVar12 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar12 + 4) = puVar3;
  *(undefined4 *)(pAVar12 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar12 = 0;
  *(Array **)(this + 0xf8) = pAVar12;
  ArraySetLength<TouchButton*>(5,pAVar12);
  iVar22 = Globals::layout;
  iVar10 = *(int *)(Globals::layout + 0x2c);
  *(int *)(this + 0x208) = iVar10;
  if (**(int **)(this + 0xf8) != 0) {
    uVar24 = 0;
    while( true ) {
      pTVar7 = operator_new(0xc0);
      TouchButton::TouchButton
                (pTVar7,*(uint *)(*(int *)(this + 0x134) + uVar24 * 4),0x10,*(int *)(this + 0x1ec),
                 (iVar10 + *(int *)(this + 0x1e4)) * uVar24 + *(int *)(this + 0x1f0),'\x11');
      iVar22 = uVar24 + 0x36;
      *(TouchButton **)(*(int *)(*(int *)(this + 0xf8) + 4) + uVar24 * 4) = pTVar7;
      puVar11 = *(uint **)(this + 0xf8);
      piVar21 = *(int **)(puVar11[1] + uVar24 * 4);
      uVar24 = uVar24 + 1;
      *piVar21 = iVar22;
      piVar21[1] = iVar22 >> 0x1f;
      if (*puVar11 <= uVar24) break;
      iVar10 = *(int *)(this + 0x208);
    }
    iVar10 = *(int *)(Globals::layout + 0x2c);
    iVar22 = Globals::layout;
  }
  iVar23 = *(int *)(this + 0x1fc);
  iVar10 = (((((Globals::h - *(int *)(iVar22 + 0xc)) - *(int *)(iVar22 + 0x20)) - iVar23) - iVar10)
           - *(int *)(iVar22 + 0x10)) - *(int *)(iVar22 + 0x24);
  if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
    iVar22 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x14c));
    iVar10 = iVar10 + iVar22 * -2;
    iVar23 = *(int *)(this + 0x1fc);
    iVar22 = Globals::layout;
  }
  pSVar13 = operator_new(0x20);
  ScrollTouchWindow::ScrollTouchWindow
            (pSVar13,(Globals::w - *(int *)(iVar22 + 0x28)) - *(int *)(this + 0x204),
             *(int *)(iVar22 + 0xc) + *(int *)(iVar22 + 0x20) + iVar23 + *(int *)(iVar22 + 0x2c),
             *(int *)(this + 0x204),iVar10,false);
  *(ScrollTouchWindow **)(this + 0xf4) = pSVar13;
  AbyssEngine::String::String(aSStack_100,"",false);
  pSVar5 = (String *)GameText::getText(Globals::gameText,*(int *)(this + 0x1e0) + 0x57);
  AbyssEngine::String::String(aSStack_108,pSVar5,false);
  ScrollTouchWindow::setText(pSVar13,aSStack_100,aSStack_108);
  AbyssEngine::String::~String(aSStack_108);
  AbyssEngine::String::~String(aSStack_100);
  fVar32 = local_d8;
  iVar22 = *(int *)(this + 0x1a8);
  TouchButton::getPosition();
  iVar10 = *(int *)(Globals::layout + 0x2c);
  pTVar7 = operator_new(0xc0);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x61);
  fVar31 = (float)VectorSignedToFloat(iVar22,(byte)(in_fpscr >> 0x16) & 3);
  fVar33 = (float)VectorSignedToFloat(iVar10 * 3,(byte)(in_fpscr >> 0x16) & 3);
  fVar34 = (float)VectorSignedToFloat(iVar22 / 3,(byte)(in_fpscr >> 0x16) & 3);
  TouchButton::TouchButton
            (pTVar7,pSVar5,0x11,(int)(fVar32 + fVar31 + fVar34),(int)(local_110 - fVar33),'\x14');
  *(undefined4 *)pTVar7 = 0x35;
  *(undefined4 *)(pTVar7 + 4) = 0;
  piVar21 = *(int **)(this + 0xc0);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar7;
  *piVar21 = piVar21[2];
  if (Globals::inAppPurchaseSupported == '\0') {
    TouchButton::setVisible(pTVar7,false);
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbc2,(uint *)(this + 0x124));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x233f,(uint *)(this + 0x128));
  iVar22 = Globals::w;
  if (Globals::iPad == '\0') {
    *(undefined4 *)(this + 0x19c) = 0;
    *(int *)(this + 0x1a0) = iVar22;
    iVar10 = Globals::layout;
    iVar23 = ((((Globals::h - *(int *)(Globals::layout + 0xc)) - *(int *)(Globals::layout + 0x10)) -
              *(int *)(Globals::layout + 0x20)) - *(int *)(Globals::layout + 0x24)) / 2;
    *(int *)(this + 0x154) = iVar23;
  }
  else {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c1,(uint *)(this + 0x1c));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b2,(uint *)(this + 0x20));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b0,(uint *)(this + 0x24));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b6,(uint *)(this + 0x28));
    uVar27 = Globals::options._84_4_;
    pGVar2 = Globals::globals;
    iVar22 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x1c));
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x24));
    iVar23 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x20));
    Globals::setCoordsSteer
              (pGVar2,uVar27,iVar22,iVar10,iVar23,(ushort *)(this + 0x2e),(ushort *)(this + 0x30),
               (ushort *)(this + 0x40),(ushort *)(this + 0x42),(ushort *)(this + 0x3c),
               (ushort *)(this + 0x3e),(ushort *)(this + 0x34),(ushort *)(this + 0x32),
               (ushort *)(this + 0x48),(ushort *)(this + 0x4a));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c6,(uint *)(this + 0x78));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6aa,(uint *)(this + 0x7c));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ba,(uint *)(this + 0x84));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b4,(uint *)(this + 0x80));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4be,(uint *)(this + 0x88));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4bc,(uint *)(this + 0x8c));
    uVar27 = Globals::options._88_4_;
    pGVar2 = Globals::globals;
    iVar22 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x78));
    Globals::setCoordsFire
              (pGVar2,uVar27,iVar22,*(uint *)(this + 0x78),*(uint *)(this + 0x7c),
               (uint *)(this + 0x74),(ushort *)(this + 0x60),(ushort *)(this + 0x62),
               (ushort *)(this + 100),(ushort *)(this + 0x66),(ushort *)(this + 0x68),
               (ushort *)(this + 0x6a),(ushort *)(this + 0x6c),(ushort *)(this + 0x6e),
               (ushort *)(this + 0x70),(ushort *)(this + 0x72),(ushort *)(this + 0x4c),
               (ushort *)(this + 0x4e));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6a5,(uint *)(this + 0x50));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6a6,(uint *)(this + 0x54));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6a7,(uint *)(this + 0x58));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6a8,(uint *)(this + 0x5c));
    pTVar7 = operator_new(0xc0);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x1f1);
    if (Globals::iPadHD == '\0') {
      pfVar20 = (float *)&DAT_0014991c;
      if (Globals::iPadLarge != '\0') {
        pfVar20 = (float *)&DAT_00149920;
      }
      fVar32 = *pfVar20;
    }
    else {
      fVar32 = 281.25;
    }
    TouchButton::TouchButton
              (pTVar7,pSVar5,0,Globals::w >> 1,
               *(int *)(Globals::layout + 0x308) + *(int *)(Globals::layout + 0x300) +
               *(int *)(Globals::layout + 0x34) * -2 + *(int *)(Globals::layout + 0x30) * -2,
               (int)fVar32,'D','\x04');
    *(TouchButton **)(this + 0x18) = pTVar7;
    pTVar7 = operator_new(0xc0);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x1f0);
    if (Globals::iPadHD == '\0') {
      pfVar20 = (float *)&DAT_0014991c;
      if (Globals::iPadLarge != '\0') {
        pfVar20 = (float *)&DAT_00149920;
      }
      fVar32 = *pfVar20;
    }
    else {
      fVar32 = 281.25;
    }
    TouchButton::TouchButton
              (pTVar7,pSVar5,0,Globals::w >> 1,
               ((*(int *)(Globals::layout + 0x308) + *(int *)(Globals::layout + 0x300)) -
               *(int *)(Globals::layout + 0x34)) - *(int *)(Globals::layout + 0x30),(int)fVar32,'D',
               '\x04');
    *(TouchButton **)(this + 0x14) = pTVar7;
    pSVar13 = operator_new(0x20);
    ScrollTouchWindow::ScrollTouchWindow
              (pSVar13,(Globals::w >> 1) - *(int *)(Globals::layout + 0x304) / 2,
               *(int *)(Globals::layout + 8) + *(int *)(Globals::layout + 0x300),
               *(int *)(Globals::layout + 0x304),*(int *)(Globals::layout + 0x308),false);
    *(ScrollTouchWindow **)(this + 0x10) = pSVar13;
    AbyssEngine::String::String(aSStack_11c,"",false);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x1ef);
    AbyssEngine::String::String(aSStack_124,pSVar5,false);
    ScrollTouchWindow::setText(pSVar13,aSStack_11c,aSStack_124);
    AbyssEngine::String::~String(aSStack_124);
    AbyssEngine::String::~String(aSStack_11c);
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0xc) = 0;
    if (Globals::iPadHD == '\0') {
      pfVar20 = (float *)&DAT_00149954;
      if (Globals::iPadLarge != '\0') {
        pfVar20 = (float *)&DAT_00149958;
      }
      fVar32 = *pfVar20;
    }
    else {
      fVar32 = 703.125;
    }
    bVar30 = Globals::iPadHD == '\0';
    *(int *)(this + 0x1a0) = (int)fVar32;
    iVar22 = (int)fVar32;
    *(int *)(this + 0x19c) = (Globals::w - iVar22) / 2;
    if (bVar30) {
      pfVar20 = (float *)&DAT_00149968;
      if (Globals::iPadLarge != '\0') {
        pfVar20 = (float *)&DAT_0014996c;
      }
      fVar32 = *pfVar20;
    }
    else {
      fVar32 = 175.78125;
    }
    iVar23 = (int)fVar32;
    *(int *)(this + 0x154) = (int)fVar32;
    iVar10 = Globals::layout;
  }
  iVar22 = iVar22 + *(int *)(iVar10 + 0x28) * -2;
  *(int *)(this + 0x150) = iVar22;
  iVar10 = *(int *)(iVar10 + 0x2c);
  *(int *)(this + 0x158) = (1 - iVar10) + iVar22 / 2;
  *(int *)(this + 0x15c) = (iVar23 / 2 + 1) - iVar10;
  iVar22 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x114));
  *(int *)(this + 0x160) = iVar22;
  *(int *)(this + 0x164) = iVar22 + 0xf;
  pTVar7 = operator_new(0xc0);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x1ec);
  TouchButton::TouchButton
            (pTVar7,pSVar5,0,
             ((*(int *)(this + 0x1a0) + *(int *)(this + 0x19c)) - *(int *)(Globals::layout + 0x28))
             - *(int *)(this + 0x158) / 2,
             *(int *)(Globals::layout + 0x2c) +
             *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
             *(int *)(this + 0x154) + *(int *)(this + 0x15c) / 2,*(int *)(this + 0x158) + -0x14,'D',
             '\x04');
  *(TouchButton **)(this + 0xd0) = pTVar7;
  pTVar7 = operator_new(0xc0);
  AbyssEngine::String::String(aSStack_e0,"",false);
  TouchButton::TouchButton
            (pTVar7,aSStack_e0,0xd,
             *(int *)(this + 0x19c) + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x158) +
             -10,*(int *)(Globals::layout + 0x2c) +
                 *(int *)(this + 0x154) +
                 *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                 *(int *)(this + 0x15c) / 2,'B');
  *(TouchButton **)(this + 0xcc) = pTVar7;
  AbyssEngine::String::~String(aSStack_e0);
  pTVar7 = operator_new(0xc0);
  AbyssEngine::String::String(aSStack_e0,"",false);
  TouchButton::TouchButton
            (pTVar7,aSStack_e0,0xd,
             (*(int *)(this + 0x19c) + *(int *)(this + 0x1a0) + -0x19) -
             *(int *)(Globals::layout + 0x28),
             *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
             *(int *)(this + 0x154) + *(int *)(this + 0x164) * 3 + *(int *)(this + 0x164) / 2 +
             *(int *)(Globals::layout + 0x2fc) * 2 + *(int *)(Globals::layout + 0x2c) * 7 +
             *(int *)(Globals::layout + 0x1c) * 3 + *(int *)(this + 0x15c) * 2,'B');
  *(TouchButton **)(this + 0xe8) = pTVar7;
  AbyssEngine::String::~String(aSStack_e0);
  TouchButton::setHalfTransparent(*(TouchButton **)(this + 0xd0),(bool)Globals::options[0x11]);
  TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xcc),(bool)Globals::options[0x10]);
  TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xe8),(bool)Globals::options[0x40]);
  if (Globals::iPad != '\0') {
    pTVar7 = operator_new(0xc0);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x1ee);
    TouchButton::TouchButton
              (pTVar7,pSVar5,0,
               ((*(int *)(this + 0x1a0) + *(int *)(this + 0x19c)) - *(int *)(Globals::layout + 0x28)
               ) - *(int *)(this + 0x158) / 2,
               *(int *)(Globals::layout + 0x2c) +
               *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
               *(int *)(this + 0x154) + *(int *)(this + 0x15c) / 2,*(int *)(this + 0x158) + -0x14,
               'D','\x04');
    *(TouchButton **)(this + 0xe4) = pTVar7;
  }
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  puVar3[2] = 1;
  *puVar4 = 0;
  *puVar3 = 0;
  *(undefined4 **)(this + 0xb4) = puVar3;
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x207);
  AbyssEngine::String::String(aSStack_12c,pSVar5,false);
  addButton(this,0x10,aSStack_12c,0,*(undefined4 *)(this + 0xb4),0);
  AbyssEngine::String::~String(aSStack_12c);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x19);
  AbyssEngine::String::String(aSStack_134,pSVar5,false);
  addButton(this,0x32,aSStack_134,1,*(undefined4 *)(this + 0xb4),0);
  AbyssEngine::String::~String(aSStack_134);
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  puVar3[2] = 1;
  *puVar4 = 0;
  *puVar3 = 0;
  iVar22 = 0;
  *(undefined4 **)(this + 0xb8) = puVar3;
  local_13c = 0xffffffff;
  local_138 = 0xffffffff;
  do {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,(&DAT_002585d0)[iVar22 * 4],&local_138);
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,(&DAT_002585d4)[iVar22 * 4],&local_13c);
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,local_138);
    iVar23 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,local_138);
    if (iVar22 == 0) {
      iVar10 = (-iVar10 - iVar10 / 2) + Globals::w / 2;
    }
    else {
      iVar10 = iVar10 / 2;
      if (iVar22 == 1) {
        iVar10 = -iVar10;
      }
      iVar10 = iVar10 + Globals::w / 2;
    }
    pTVar7 = operator_new(0xc0);
    TouchButton::TouchButton
              (pTVar7,local_138,local_13c,0x13,iVar10,Globals::h / 2 - iVar23 / 2,'\x01');
    piVar21 = *(int **)(this + 0xb8);
    piVar21[2] = *piVar21 + 1;
    pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
    piVar21[1] = (int)pvVar8;
    iVar22 = iVar22 + 1;
    *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar7;
    *piVar21 = piVar21[2];
    iVar10 = Globals::layout;
  } while (iVar22 < 3);
  iVar23 = *(int *)(Globals::layout + 0x2b4);
  iVar22 = *(int *)(Globals::layout + 0x2b8);
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  puVar3[2] = 1;
  *puVar4 = 0;
  *puVar3 = 0;
  *(undefined4 **)(this + 0xec) = puVar3;
  pTVar14 = operator_new(0x3c);
  pfVar20 = (float *)(Globals::options + 0x18);
  if (Globals::options[0x11] != '\0') {
    pfVar20 = (float *)(Globals::options + 0x14);
  }
  TouchSlider::TouchSlider
            (pTVar14,0,((Globals::w + 10) - *(int *)(iVar10 + 0x28)) - *(int *)(this + 0x158),
             (*(int *)(iVar10 + 0xc) - iVar23) + *(int *)(iVar10 + 0x20) + *(int *)(this + 0x154) +
             (*(int *)(this + 0x15c) + *(int *)(iVar10 + 0x2c)) * 2,*pfVar20);
  piVar21 = *(int **)(this + 0xec);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchSlider **)((int)pvVar8 + *piVar21 * 4) = pTVar14;
  *piVar21 = piVar21[2];
  pTVar14 = operator_new(0x3c);
  TouchSlider::TouchSlider
            (pTVar14,1,*(int *)(Globals::layout + 0x28) + *(int *)(this + 0x1c0),
             *(int *)(Globals::layout + 0xc) + iVar22 + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x1c) + *(int *)(Globals::layout + 0x2c),
             (float)Globals::options._0_4_);
  piVar21 = *(int **)(this + 0xec);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchSlider **)((int)pvVar8 + *piVar21 * 4) = pTVar14;
  *piVar21 = piVar21[2];
  pTVar14 = operator_new(0x3c);
  TouchSlider::TouchSlider
            (pTVar14,1,*(int *)(this + 0x1c0) + *(int *)(Globals::layout + 0x28),
             *(int *)(this + 0x160) +
             *(int *)(Globals::layout + 0x2c) * 3 +
             *(int *)(Globals::layout + 0xc) + iVar22 + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x1c),(float)Globals::options._4_4_);
  piVar21 = *(int **)(this + 0xec);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchSlider **)((int)pvVar8 + *piVar21 * 4) = pTVar14;
  *piVar21 = piVar21[2];
  pTVar14 = operator_new(0x3c);
  TouchSlider::TouchSlider
            (pTVar14,1,*(int *)(this + 0x1c0) + *(int *)(Globals::layout + 0x28),
             *(int *)(Globals::layout + 0x2c) * 5 +
             *(int *)(Globals::layout + 0xc) + iVar22 + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x1c) + *(int *)(this + 0x160) * 2,
             (float)Globals::options._8_4_);
  piVar21 = *(int **)(this + 0xec);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchSlider **)((int)pvVar8 + *piVar21 * 4) = pTVar14;
  *piVar21 = piVar21[2];
  pTVar14 = operator_new(0x3c);
  dVar36 = (double)VectorSignedToFloat(*(undefined4 *)(this + 0x160),(byte)(in_fpscr >> 0x16) & 3);
  dVar37 = (double)VectorSignedToFloat(*(int *)(Globals::layout + 0xc) +
                                       *(int *)(Globals::layout + 0x20) +
                                       *(int *)(Globals::layout + 0x1c) * 3 +
                                       *(int *)(Globals::layout + 0x2c) * 6,
                                       (byte)(in_fpscr >> 0x16) & 3);
  dVar35 = (double)VectorSignedToFloat(iVar22,(byte)(in_fpscr >> 0x16) & 3);
  iVar10 = (int)(longlong)(dVar35 + dVar37 + dVar36 * 2.5);
  TouchSlider::TouchSlider
            (pTVar14,2,*(int *)(this + 0x1c0) + *(int *)(Globals::layout + 0x28),iVar10,
             (float)iVar10);
  piVar21 = *(int **)(this + 0xec);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchSlider **)((int)pvVar8 + *piVar21 * 4) = pTVar14;
  *piVar21 = piVar21[2];
  pTVar14 = operator_new(0x3c);
  dVar36 = (double)VectorSignedToFloat(*(undefined4 *)(this + 0x160),(byte)(in_fpscr >> 0x16) & 3);
  dVar37 = (double)VectorSignedToFloat(*(int *)(Globals::layout + 0xc) +
                                       *(int *)(Globals::layout + 0x20) +
                                       *(int *)(Globals::layout + 0x1c) * 3 +
                                       *(int *)(Globals::layout + 0x2c) * 8,
                                       (byte)(in_fpscr >> 0x16) & 3);
  dVar38 = (double)VectorSignedToFloat(*(undefined4 *)(this + 0x164),(byte)(in_fpscr >> 0x16) & 3);
  iVar10 = (int)(longlong)(dVar35 + dVar38 + dVar37 + dVar36 * 2.5);
  TouchSlider::TouchSlider
            (pTVar14,2,*(int *)(this + 0x1c0) + *(int *)(Globals::layout + 0x28),iVar10,
             (float)iVar10);
  piVar21 = *(int **)(this + 0xec);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchSlider **)((int)pvVar8 + *piVar21 * 4) = pTVar14;
  *piVar21 = piVar21[2];
  pTVar14 = operator_new(0x3c);
  TouchSlider::TouchSlider
            (pTVar14,2,*(int *)(Globals::layout + 0x28) + *(int *)(this + 0x1c0),
             *(int *)(Globals::layout + 0xc) + iVar22 + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x1c) + *(int *)(Globals::layout + 0x2c),
             (float)Globals::options._44_4_);
  piVar21 = *(int **)(this + 0xec);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchSlider **)((int)pvVar8 + *piVar21 * 4) = pTVar14;
  *piVar21 = piVar21[2];
  iVar10 = Globals::w;
  pTVar14 = *(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x18);
  iVar23 = TouchSlider::getWidth(pTVar14);
  TouchSlider::setPosition
            (pTVar14,iVar10 / 2 - iVar23 / 2,
             *(int *)(Globals::layout + 0xc) + iVar22 + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x1c) + *(int *)(Globals::layout + 0x2c));
  pTVar7 = operator_new(0xc0);
  AbyssEngine::String::String(aSStack_e0,"",false);
  TouchButton::TouchButton
            (pTVar7,aSStack_e0,0xd,Globals::w - *(int *)(Globals::layout + 0x28),
             *(int *)(Globals::layout + 0x2c) +
             *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x1c),'\x12');
  *(TouchButton **)(this + 0xd4) = pTVar7;
  AbyssEngine::String::~String(aSStack_e0);
  TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xd4),(bool)Globals::options[0xd]);
  TouchSlider::setHalfTransparent
            (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 4),
             Globals::options[0xd] == '\0');
  pTVar7 = operator_new(0xc0);
  AbyssEngine::String::String(aSStack_e0,"",false);
  TouchButton::TouchButton
            (pTVar7,aSStack_e0,0xd,Globals::w - *(int *)(Globals::layout + 0x28),
             *(int *)(Globals::layout + 0x2c) * 3 +
             *(int *)(this + 0x160) +
             *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x1c),'\x12');
  *(TouchButton **)(this + 0xd8) = pTVar7;
  AbyssEngine::String::~String(aSStack_e0);
  TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xd8),(bool)Globals::options[0xc]);
  TouchSlider::setHalfTransparent
            (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 8),
             Globals::options[0xe] == '\0');
  pTVar7 = operator_new(0xc0);
  AbyssEngine::String::String(aSStack_e0,"",false);
  TouchButton::TouchButton
            (pTVar7,aSStack_e0,0xd,Globals::w - *(int *)(Globals::layout + 0x28),
             *(int *)(Globals::layout + 0x2c) * 5 +
             *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
             *(int *)(this + 0x160) * 2 + *(int *)(Globals::layout + 0x1c),'\x12');
  *(TouchButton **)(this + 0xdc) = pTVar7;
  AbyssEngine::String::~String(aSStack_e0);
  TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xdc),(bool)Globals::options[0xe]);
  TouchSlider::setHalfTransparent
            (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0xc),
             Globals::options[0xe] == '\0');
  TouchSlider::setFixedScale(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x14),1);
  TouchSlider::setFixedScale(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x18),1);
  if (Globals::iPad == '\0') {
    *(undefined4 *)(this + 0x198) = 0;
    pSVar13 = operator_new(0x20);
    iVar22 = *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20);
    ScrollTouchWindow::ScrollTouchWindow
              (pSVar13,*(int *)(Globals::layout + 0x28),iVar22,
               Globals::w + *(int *)(Globals::layout + 0x28) * -2,
               ((Globals::h - iVar22) - *(int *)(Globals::layout + 0x10)) -
               *(int *)(Globals::layout + 0x24),false);
    *(ScrollTouchWindow **)(this + 0xf0) = pSVar13;
  }
  else {
    fVar32 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x1c) +
                                        *(int *)(Globals::layout + 0x20) +
                                        *(int *)(Globals::layout + 0xc) + *(int *)(this + 0x154) +
                                        *(int *)(this + 0x15c) * 2 +
                                        *(int *)(Globals::layout + 0x2c) * 3,
                                        (byte)(in_fpscr >> 0x16) & 3);
    if (Globals::iPadHD == '\0') {
      fVar31 = 25.0;
      if (Globals::iPadLarge != '\0') {
        fVar31 = 50.0;
      }
    }
    else {
      fVar31 = 35.15625;
    }
    TouchSlider::setPosition
              ((TouchSlider *)**(undefined4 **)(*(int *)(this + 0xec) + 4),
               *(int *)(this + 0x19c) + *(int *)(Globals::layout + 0x28) + 10,(int)(fVar32 - fVar31)
              );
    fVar33 = 19.6875;
    fVar31 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x2fc) +
                                        *(int *)(this + 0x154) +
                                        *(int *)(Globals::layout + 0x20) +
                                        *(int *)(Globals::layout + 0xc) + *(int *)(this + 0x15c) * 2
                                        + *(int *)(Globals::layout + 0x2c) * 4 +
                                        *(int *)(Globals::layout + 0x1c) * 2,
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar32 = fVar33;
    if ((Globals::iPadHD == '\0') && (fVar32 = 14.0, Globals::iPadLarge != '\0')) {
      fVar32 = 28.0;
    }
    TouchSlider::setPosition
              (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 4),
               *(int *)(this + 0x1c0) + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x19c),
               (int)(fVar31 + fVar32));
    fVar31 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x2fc) +
                                        *(int *)(this + 0x154) +
                                        *(int *)(Globals::layout + 0x20) +
                                        *(int *)(Globals::layout + 0xc) + *(int *)(this + 0x164) +
                                        *(int *)(Globals::layout + 0x2c) * 5 +
                                        *(int *)(Globals::layout + 0x1c) * 2 +
                                        *(int *)(this + 0x15c) * 2,(byte)(in_fpscr >> 0x16) & 3);
    fVar32 = fVar33;
    if ((Globals::iPadHD == '\0') && (fVar32 = 14.0, Globals::iPadLarge != '\0')) {
      fVar32 = 28.0;
    }
    TouchSlider::setPosition
              (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 8),
               *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x19c) + *(int *)(this + 0x1c0),
               (int)(fVar31 + fVar32));
    fVar32 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x2fc) +
                                        *(int *)(this + 0x154) +
                                        *(int *)(Globals::layout + 0x20) +
                                        *(int *)(Globals::layout + 0xc) +
                                        *(int *)(Globals::layout + 0x2c) * 6 +
                                        *(int *)(Globals::layout + 0x1c) * 2 +
                                        (*(int *)(this + 0x164) + *(int *)(this + 0x15c)) * 2,
                                        (byte)(in_fpscr >> 0x16) & 3);
    if ((Globals::iPadHD == '\0') && (fVar33 = 14.0, Globals::iPadLarge != '\0')) {
      fVar33 = 28.0;
    }
    TouchSlider::setPosition
              (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0xc),
               *(int *)(this + 0x19c) + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x1c0),
               (int)(fVar32 + fVar33));
    pTVar14 = *(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x10);
    if (Globals::iPadLargePossible == '\0') {
      fVar33 = 9.84375;
      fVar31 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0xc) +
                                          *(int *)(Globals::layout + 0x20) + *(int *)(this + 0x154)
                                          + *(int *)(this + 0x164) * 3 +
                                          *(int *)(Globals::layout + 0x2fc) * 2 +
                                          *(int *)(Globals::layout + 0x2c) * 6 +
                                          *(int *)(Globals::layout + 0x1c) * 3 +
                                          *(int *)(this + 0x15c) * 2,(byte)(in_fpscr >> 0x16) & 3);
      fVar32 = fVar33;
      if ((Globals::iPadHD == '\0') && (fVar32 = 7.0, Globals::iPadLarge != '\0')) {
        fVar32 = 14.0;
      }
      TouchSlider::setPosition
                (pTVar14,*(int *)(this + 0x1c0) +
                         *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x19c),
                 (int)(fVar31 + fVar32));
      fVar32 = (float)VectorSignedToFloat(*(int *)(this + 0x154) +
                                          *(int *)(Globals::layout + 0x20) +
                                          *(int *)(Globals::layout + 0xc) +
                                          *(int *)(this + 0x164) * 4 +
                                          *(int *)(Globals::layout + 0x2fc) * 2 +
                                          *(int *)(Globals::layout + 0x2c) * 7 +
                                          *(int *)(Globals::layout + 0x1c) * 3 +
                                          *(int *)(this + 0x15c) * 2,(byte)(in_fpscr >> 0x16) & 3);
      if ((Globals::iPadHD == '\0') && (fVar33 = 7.0, Globals::iPadLarge != '\0')) {
        fVar33 = 14.0;
      }
      TouchSlider::setPosition
                (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x14),
                 *(int *)(this + 0x19c) + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x1c0),
                 (int)(fVar32 + fVar33));
    }
    else {
      TouchSlider::setPosition(pTVar14,-100000,-100000);
      fVar32 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x2c) * 7 +
                                          *(int *)(Globals::layout + 0xc) +
                                          *(int *)(Globals::layout + 0x20) + *(int *)(this + 0x154)
                                          + *(int *)(this + 0x164) * 4 +
                                          *(int *)(Globals::layout + 0x2fc) * 2 +
                                          *(int *)(Globals::layout + 0x1c) * 3 +
                                          *(int *)(this + 0x15c) * 2,(byte)(in_fpscr >> 0x16) & 3);
      if (Globals::iPadHD == '\0') {
        fVar31 = 7.0;
        if (Globals::iPadLarge != '\0') {
          fVar31 = 14.0;
        }
      }
      else {
        fVar31 = 9.84375;
      }
      fVar32 = (float)TouchSlider::setPosition
                                (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x14),
                                 *(int *)(Globals::layout + 0x28) + *(int *)(this + 0x19c) +
                                 *(int *)(this + 0x1c0),(int)(fVar32 + fVar31));
      TouchSlider::setValue(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x14),fVar32);
    }
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6a4,(uint *)(this + 0x11c));
    iVar22 = Globals::w;
    fVar32 = (float)VectorSignedToFloat(Globals::w,(byte)(in_fpscr >> 0x16) & 3);
    iVar10 = (int)(fVar32 * 0.2);
    if (Globals::iPadAssetsWithLowerRes != '\0') {
      iVar10 = 0x32;
    }
    *(int *)(this + 0x198) = iVar10;
    pSVar13 = operator_new(0x20);
    iVar10 = *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20);
    ScrollTouchWindow::ScrollTouchWindow
              (pSVar13,*(int *)(Globals::layout + 0x28) + (iVar22 >> 2),iVar10,
               (iVar22 >> 1) + *(int *)(Globals::layout + 0x28) * -2,
               ((Globals::h - iVar10) - *(int *)(Globals::layout + 0x10)) -
               *(int *)(Globals::layout + 0x24),false);
    *(ScrollTouchWindow **)(this + 0xf0) = pSVar13;
  }
  iVar22 = AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::String::String(aSStack_e0,(String *)(iVar22 + 0x34),false);
  if (local_dc < 3) {
    AbyssEngine::String::String((String *)aAStack_144,"",false);
    AbyssEngine::String::operator=(aSStack_e0,aAStack_144);
    pSVar15 = (String *)aAStack_144;
  }
  else {
    AbyssEngine::String::String(aSStack_14c," v",false);
    AbyssEngine::operator+(aAStack_144,aSStack_14c,aSStack_e0);
    AbyssEngine::String::operator=(aSStack_e0,aAStack_144);
    AbyssEngine::String::~String((String *)aAStack_144);
    pSVar15 = aSStack_14c;
  }
  AbyssEngine::String::~String(pSVar15);
  AbyssEngine::String::String(aSStack_16c,"Galaxy on Fire 2 FHD",false);
  AbyssEngine::operator+(aAStack_164,aSStack_16c,aSStack_e0);
  AbyssEngine::String::String(aSStack_174,"\n\n",false);
  AbyssEngine::operator+(aAStack_15c,aAStack_164,aSStack_174);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x2d);
  AbyssEngine::operator+(aAStack_154,aAStack_15c,pSVar5);
  AbyssEngine::String::String(aSStack_17c,"",false);
  AbyssEngine::operator+((AbyssEngine *)aSStack_14c,aAStack_154,aSStack_17c);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x30);
  AbyssEngine::operator+(aAStack_144,aSStack_14c,pSVar5);
  AbyssEngine::String::~String(aSStack_14c);
  AbyssEngine::String::~String(aSStack_17c);
  AbyssEngine::String::~String((String *)aAStack_154);
  AbyssEngine::String::~String((String *)aAStack_15c);
  AbyssEngine::String::~String(aSStack_174);
  AbyssEngine::String::~String((String *)aAStack_164);
  AbyssEngine::String::~String(aSStack_16c);
  pSVar13 = *(ScrollTouchWindow **)(this + 0xf0);
  AbyssEngine::String::String(aSStack_184,"",false);
  AbyssEngine::String::String(aSStack_18c,aAStack_144,false);
  ScrollTouchWindow::setText(pSVar13,aSStack_184,aSStack_18c);
  AbyssEngine::String::~String(aSStack_18c);
  AbyssEngine::String::~String(aSStack_184);
  ScrollTouchWindow::setTextCentered(SUB41(*(undefined4 *)(this + 0xf0),0));
  if ((Globals::iPad == '\0') || (Globals::iPadAssetsWithLowerRes != '\0')) {
    pTVar7 = operator_new(0xc0);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x62);
    TouchButton::TouchButton
              (pTVar7,pSVar5,0,Globals::w - *(int *)(Globals::layout + 0x2c),
               Globals::h - *(int *)(Globals::layout + 0x2c),'\"');
  }
  else {
    pTVar7 = operator_new(0xc0);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x62);
    iVar22 = Globals::h;
    iVar23 = *(int *)(this + 0x200);
    uVar27 = *(undefined4 *)(this + 0x204);
    iVar29 = *(int *)(Globals::layout + 0x10);
    iVar28 = *(int *)(Globals::layout + 0x24);
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x14c));
    fVar32 = (float)VectorSignedToFloat(uVar27,(byte)(in_fpscr >> 0x16) & 3);
    fVar31 = (float)VectorSignedToFloat(iVar23 + iVar26,(byte)(in_fpscr >> 0x16) & 3);
    TouchButton::TouchButton
              (pTVar7,pSVar5,7,(int)(fVar31 + fVar32 * 0.5),
               (((iVar22 + 5) - iVar29) - iVar28) - iVar10,'$');
  }
  *(undefined4 *)pTVar7 = 0x34;
  *(undefined4 *)(pTVar7 + 4) = 0;
  piVar21 = *(int **)(this + 0xc0);
  piVar21[2] = *piVar21 + 1;
  pvVar8 = realloc((void *)piVar21[1],(*piVar21 + 1) * 4);
  piVar21[1] = (int)pvVar8;
  *(TouchButton **)((int)pvVar8 + *piVar21 * 4) = pTVar7;
  *piVar21 = piVar21[2];
  this[0x170] = (MenuTouchWindow)0x0;
  this[0x17f] = (MenuTouchWindow)0x0;
  this[0x180] = (MenuTouchWindow)0x0;
  this[0x181] = (MenuTouchWindow)0x0;
  pCVar16 = operator_new(0x54);
  ChoiceWindow::ChoiceWindow(pCVar16);
  *(ChoiceWindow **)(this + 0x104) = pCVar16;
  iVar22 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  if ((Globals::options[0x35] == '\0') && (*(char *)(iVar22 + 0x60) != '\0')) {
    Globals::options[0x35] = '\x01';
    RecordHandler::saveOptions(Globals::recordHandler);
    *(undefined1 *)(iVar22 + 0x60) = 0;
    pCVar16 = *(ChoiceWindow **)(this + 0x104);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x4a);
    ChoiceWindow::set(pCVar16,pSVar5);
  }
  else {
    if ((Globals::iPadLargePossible == '\0') || (Globals::options[0x41] != '\0')) goto LAB_0014ac42;
    Globals::options[0x41] = '\x01';
    RecordHandler::saveOptions(Globals::recordHandler);
    pCVar16 = *(ChoiceWindow **)(this + 0x104);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x7b);
    ChoiceWindow::set(pCVar16,pSVar5);
  }
  this[0x170] = (MenuTouchWindow)0x1;
  this[0x17f] = (MenuTouchWindow)0x1;
LAB_0014ac42:
  *(undefined4 *)(this + 0xfc) = 0;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  this[0x171] = (MenuTouchWindow)0x0;
  *(undefined4 *)(this + 0x177) = 0;
  *(undefined4 *)(this + 0x173) = 0;
  *(undefined4 *)(this + 0x17b) = 0;
  *(undefined4 *)(this + 0x18c) = 0xffffffff;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 200) = 0;
  this[0x108] = (MenuTouchWindow)0x0;
  this[0x109] = (MenuTouchWindow)0x0;
  *(undefined4 *)(this + 0x1a4) = 0x3f000000;
  *(undefined4 *)(this + 0x184) = 0xffffffff;
  this[0x188] = (MenuTouchWindow)0x0;
  this[0x189] = (MenuTouchWindow)0x0;
  this[0x172] = (MenuTouchWindow)0x0;
  this[400] = (MenuTouchWindow)0x0;
  *(undefined4 *)(this + 0x194) = 0;
  this[0x1de] = (MenuTouchWindow)0x0;
  *(undefined4 *)(this + 0x1da) = 0;
  *(undefined4 *)(this + 0x215) = 0;
  *(undefined4 *)(this + 0x219) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x21d) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x221) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x20c) = 0;
  *(undefined4 *)(this + 0x210) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x214) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x218) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  AbyssEngine::String::~String((String *)aAStack_144);
  AbyssEngine::String::~String(aSStack_e0);
  if (__stack_chk_guard - local_3c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_3c);
}

// ===== MenuTouchWindow::loadPreviewRecords  @0x0014b040  (162 bytes)
/* MenuTouchWindow::loadPreviewRecords() */

void __thiscall MenuTouchWindow::loadPreviewRecords(MenuTouchWindow *this)

{
  int iVar1;
  RecordHandler *this_00;
  undefined4 uVar2;
  void *pvVar3;
  
  *(undefined4 *)(this + 0x194) = 0;
  *(undefined4 *)(this + 0x215) = 0;
  *(undefined4 *)(this + 0x219) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x21d) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x221) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x20c) = 0;
  *(undefined4 *)(this + 0x210) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x214) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x218) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  iVar1 = Globals::layout;
  *(int *)(this + 0x228) =
       (((Globals::h - *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0xc)) -
       *(int *)(Globals::layout + 0x20)) - *(int *)(Globals::layout + 0x24);
  *(int *)(this + 0x22c) = Globals::recordSlots * (*(int *)(iVar1 + 0x70) + *(int *)(this + 0x1b4));
  pvVar3 = *(void **)(this + 0xbc);
  if (pvVar3 != (void *)0x0) {
    if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar3 + 4));
    }
    operator_delete(pvVar3);
    *(undefined4 *)(this + 0xbc) = 0;
  }
  this_00 = operator_new(0x20);
  RecordHandler::RecordHandler(this_00);
  uVar2 = RecordHandler::readAllPreviewRecords(this_00);
  *(undefined4 *)(this + 0xbc) = uVar2;
  pvVar3 = (void *)RecordHandler::~RecordHandler(this_00);
  operator_delete(pvVar3);
  return;
}

// ===== MenuTouchWindow::addButton  @0x0014b0fc  (292 bytes)
/* MenuTouchWindow::addButton(int, AbyssEngine::String, int, Array<TouchButton*>*, int) */

void __thiscall
MenuTouchWindow::addButton
          (MenuTouchWindow *this,int param_1,String *param_3,int param_4,uint *param_5,int param_6)

{
  int iVar1;
  TouchButton *this_00;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  float local_38;
  float local_30;
  
  iVar1 = __stack_chk_guard;
  this_00 = operator_new(0xc0);
  TouchButton::TouchButton
            (this_00,param_3,0,Globals::w / 2 - *(int *)(this + 0x1a8) / 2,
             (*(int *)(Globals::layout + 0x30) + *(int *)(this + 0x1b0)) * param_4 +
             (param_6 - *(int *)(this + 0x1ac)) + Globals::h / 2,*(int *)(this + 0x1a8),'\x11',
             '\x04');
  *(int *)this_00 = param_1;
  *(int *)(this_00 + 4) = param_1 >> 0x1f;
  param_5[2] = *param_5 + 1;
  pvVar2 = realloc((void *)param_5[1],(*param_5 + 1) * 4);
  param_5[1] = (uint)pvVar2;
  *(TouchButton **)((int)pvVar2 + *param_5 * 4) = this_00;
  uVar3 = param_5[2];
  *param_5 = uVar3;
  if (uVar3 == 0) {
    uVar3 = 0;
  }
  else {
    uVar4 = 0;
    do {
      if ((int)uVar4 < 10) {
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_x + uVar4 * 4) = (int)local_30;
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_y + uVar4 * 4) = (int)local_38;
        uVar3 = *param_5;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  Globals::sub_menu_button_count = uVar3;
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== MenuTouchWindow::~MenuTouchWindow  @0x0014b250  (598 bytes)
/* MenuTouchWindow::~MenuTouchWindow() */

MenuTouchWindow * __thiscall MenuTouchWindow::~MenuTouchWindow(MenuTouchWindow *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 4) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 4));
    pvVar1 = *(void **)(this + 4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(Array **)(this + 0xac) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0xac));
    pvVar1 = *(void **)(this + 0xac);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xac) = 0;
  if (*(Array **)(this + 0xc0) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0xc0));
    pvVar1 = *(void **)(this + 0xc0);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xc0) = 0;
  if (*(Array **)(this + 0xb4) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0xb4));
    pvVar1 = *(void **)(this + 0xb4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xb4) = 0;
  if (*(Array **)(this + 0xb8) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0xb8));
    pvVar1 = *(void **)(this + 0xb8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xb8) = 0;
  if (*(Array **)(this + 0xb0) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0xb0));
    pvVar1 = *(void **)(this + 0xb0);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xb0) = 0;
  if (*(Array **)(this + 0xec) != (Array *)0x0) {
    ArrayReleaseClasses<TouchSlider*>(*(Array **)(this + 0xec));
    pvVar1 = *(void **)(this + 0xec);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xec) = 0;
  if (*(Array **)(this + 0xf8) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0xf8));
    pvVar1 = *(void **)(this + 0xf8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xf8) = 0;
  if (*(Array **)(this + 0x9c) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x9c));
    pvVar1 = *(void **)(this + 0x9c);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x9c) = 0;
  if (*(Array **)(this + 0xa0) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0xa0));
    pvVar1 = *(void **)(this + 0xa0);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xa0) = 0;
  if (*(TouchButton **)(this + 0xcc) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xcc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xcc) = 0;
  if (*(TouchButton **)(this + 0xc4) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xc4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc4) = 0;
  if (*(TouchButton **)(this + 0xd0) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xd0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xd0) = 0;
  if (*(TouchButton **)(this + 0xd4) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xd4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xd4) = 0;
  if (*(TouchButton **)(this + 0xd8) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xd8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xd8) = 0;
  if (*(TouchButton **)(this + 0xdc) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xdc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xdc) = 0;
  if (*(ChoiceWindow **)(this + 0x104) != (ChoiceWindow *)0x0) {
    pvVar1 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0x104));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x104) = 0;
  if (*(TouchButton **)(this + 200) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 200));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 200) = 0;
  if (*(TouchButton **)(this + 0xe8) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xe8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xe8) = 0;
  if (*(ScrollTouchWindow **)(this + 0xf0) != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0xf0));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xf0) = 0;
  if (*(ScrollTouchWindow **)(this + 0xf4) != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0xf4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xf4) = 0;
  if (*(void **)(this + 0x134) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x134));
  }
  *(undefined4 *)(this + 0x134) = 0;
  if (*(void **)(this + 0x138) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x138));
  }
  *(undefined4 *)(this + 0x138) = 0;
  return this;
}

// ===== MenuTouchWindow::isInMissionScreen  @0x0014b4e8  (14 bytes)
/* MenuTouchWindow::isInMissionScreen() */

bool __thiscall MenuTouchWindow::isInMissionScreen(MenuTouchWindow *this)

{
  return *(int *)(this + 0x16c) == 9;
}

// ===== MenuTouchWindow::setCutsceneMode  @0x0014b4f6  (62 bytes)
/* MenuTouchWindow::setCutsceneMode(bool) */

void __thiscall MenuTouchWindow::setCutsceneMode(MenuTouchWindow *this,bool param_1)

{
  TouchButton *this_00;
  uint *puVar1;
  uint uVar2;
  
  this[0x238] = (MenuTouchWindow)param_1;
  puVar1 = *(uint **)(this + 4);
  if (*puVar1 != 0) {
    uVar2 = 0;
    do {
      this_00 = *(TouchButton **)(puVar1[1] + uVar2 * 4);
      if (*(int *)this_00 == 0x13 && *(int *)(this_00 + 4) == 0) {
        TouchButton::setVisible(this_00,!param_1);
        puVar1 = *(uint **)(this + 4);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}

// ===== MenuTouchWindow::createRecordButtons  @0x0014b534  (1602 bytes)
/* MenuTouchWindow::createRecordButtons(bool) */

void __thiscall MenuTouchWindow::createRecordButtons(MenuTouchWindow *this,bool param_1)

{
  char cVar1;
  Array *pAVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  String *pSVar6;
  AbyssEngine *this_00;
  String *pSVar7;
  TouchButton *pTVar8;
  Array *pAVar9;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  void *pvVar10;
  uint uVar11;
  int iVar12;
  float fVar13;
  undefined4 local_64 [2];
  String aSStack_5c [8];
  String aSStack_54 [8];
  String aSStack_4c [8];
  String aSStack_44 [8];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  pAVar2 = *(Array **)(this + 0x100);
  if (pAVar2 != (Array *)0x0) {
    if (*(int *)pAVar2 != 0) {
      uVar11 = 0;
      do {
        pAVar9 = *(Array **)(*(int *)(pAVar2 + 4) + uVar11 * 4);
        if (pAVar9 != (Array *)0x0) {
          ArrayReleaseClasses<AbyssEngine::String*>(pAVar9);
          iVar3 = *(int *)(*(int *)(this + 0x100) + 4);
          pvVar10 = *(void **)(iVar3 + uVar11 * 4);
          if (pvVar10 != (void *)0x0) {
            if (*(void **)((int)pvVar10 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar10 + 4));
            }
            operator_delete(pvVar10);
            iVar3 = *(int *)(*(int *)(this + 0x100) + 4);
          }
          *(undefined4 *)(iVar3 + uVar11 * 4) = 0;
          pAVar2 = *(Array **)(this + 0x100);
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)pAVar2);
    }
    ArrayReleaseClasses<Array<AbyssEngine::String*>*>(pAVar2);
    pvVar10 = *(void **)(this + 0x100);
    if (pvVar10 != (void *)0x0) {
      if (*(void **)((int)pvVar10 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar10 + 4));
      }
      operator_delete(pvVar10);
    }
    *(undefined4 *)(this + 0x100) = 0;
  }
  pAVar2 = operator_new(0xc);
  puVar4 = operator_new__(4);
  *(undefined4 **)(pAVar2 + 4) = puVar4;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *puVar4 = 0;
  *(undefined4 *)pAVar2 = 0;
  *(Array **)(this + 0x100) = pAVar2;
  ArraySetLength<Array<AbyssEngine::String*>*>(Globals::recordSlots,pAVar2);
  if (0 < (int)Globals::recordSlots) {
    iVar12 = 0;
    iVar3 = 0;
    do {
      puVar4 = operator_new(0xc);
      puVar5 = operator_new__(4);
      puVar4[1] = puVar5;
      puVar4[2] = 1;
      *puVar5 = 0;
      *puVar4 = 0;
      *(undefined4 **)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) = puVar4;
      ArraySetLength<AbyssEngine::String*>
                (6,*(Array **)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12));
      AbyssEngine::String::String(aSStack_44);
      if ((*(int *)(this + 0xbc) == 0) ||
         (*(int *)(*(int *)(*(int *)(this + 0xbc) + 4) + iVar12) == 0)) {
        AbyssEngine::String::String(aSStack_54);
        Globals::longToTimeStringNoSeconds(CONCAT44(extraout_r1,Globals::globals),(String *)0x0);
        pSVar6 = operator_new(8);
        AbyssEngine::String::String(pSVar6,aSStack_54,false);
        **(undefined4 **)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) = pSVar6;
        pSVar6 = operator_new(8);
        pSVar7 = (String *)GameText::getText(Globals::gameText,0xae);
        AbyssEngine::String::String(pSVar6,pSVar7,false);
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 4) =
             pSVar6;
        pSVar6 = operator_new(8);
        if (iVar12 == 0) {
          pSVar7 = (String *)GameText::getText(Globals::gameText,0x1e6);
          AbyssEngine::String::String(pSVar6,pSVar7,false);
        }
        else {
          AbyssEngine::String::String(pSVar6,"",false);
        }
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 8) =
             pSVar6;
        pSVar6 = operator_new(8);
        AbyssEngine::String::String(pSVar6,"",false);
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 0xc) =
             pSVar6;
        pSVar6 = operator_new(8);
        AbyssEngine::String::String(pSVar6,"",false);
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 0x10) =
             pSVar6;
        pSVar6 = operator_new(8);
        AbyssEngine::String::String(pSVar6,"",false);
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 0x14) =
             pSVar6;
        pSVar6 = aSStack_54;
      }
      else {
        AbyssEngine::String::String(aSStack_4c);
        Globals::longToTimeStringNoSeconds
                  (CONCAT44(aSStack_4c,Globals::globals),
                   *(String **)(*(int *)(*(int *)(*(int *)(this + 0xbc) + 4) + iVar12) + 0x10));
        pSVar6 = operator_new(8);
        AbyssEngine::String::String(pSVar6,aSStack_4c,false);
        **(undefined4 **)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) = pSVar6;
        pSVar6 = operator_new(8);
        AbyssEngine::String::String
                  (pSVar6,(String *)(*(int *)(*(int *)(*(int *)(this + 0xbc) + 4) + iVar12) + 400),
                   false);
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 4) =
             pSVar6;
        pSVar6 = operator_new(8);
        if (iVar12 == 0) {
          pSVar7 = (String *)GameText::getText(Globals::gameText,0x1e6);
          AbyssEngine::String::String(pSVar6,pSVar7,false);
        }
        else {
          AbyssEngine::String::String(pSVar6,"",false);
        }
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 8) =
             pSVar6;
        pvVar10 = operator_new(8);
        Layout::formatCredits((int)pvVar10);
        *(void **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 0xc) =
             pvVar10;
        this_00 = operator_new(8);
        pSVar7 = (String *)GameText::getText(Globals::gameText,0x141);
        AbyssEngine::String::String(aSStack_5c,": ",false);
        AbyssEngine::operator+((AbyssEngine *)aSStack_54,pSVar7,aSStack_5c);
        local_64[0] = 0;
        AbyssEngine::String::Set(CONCAT44(extraout_r1_00,(String *)local_64));
        AbyssEngine::operator+(this_00,aSStack_54,(String *)local_64);
        *(AbyssEngine **)
         (*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 0x10) = this_00;
        AbyssEngine::String::~String((String *)local_64);
        AbyssEngine::String::~String(aSStack_54);
        AbyssEngine::String::~String(aSStack_5c);
        pSVar6 = operator_new(8);
        fVar13 = *(float *)(*(int *)(*(int *)(*(int *)(this + 0xbc) + 4) + iVar12) + 0x11c);
        if (fVar13 <= 0.0) {
          pSVar7 = (String *)GameText::getText(Globals::gameText,0x207);
        }
        else if (fVar13 <= 0.5) {
          pSVar7 = (String *)GameText::getText(Globals::gameText,0x207);
        }
        else if (fVar13 <= 1.0) {
          pSVar7 = (String *)GameText::getText(Globals::gameText,0x207);
        }
        else {
          pSVar7 = (String *)GameText::getText(Globals::gameText,0x19);
        }
        AbyssEngine::String::String(pSVar6,pSVar7,false);
        *(String **)(*(int *)(*(int *)(*(int *)(*(int *)(this + 0x100) + 4) + iVar12) + 4) + 0x14) =
             pSVar6;
        pSVar6 = aSStack_4c;
      }
      AbyssEngine::String::~String(pSVar6);
      AbyssEngine::String::~String(aSStack_44);
      iVar12 = iVar12 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)Globals::recordSlots);
  }
  if (*(TouchButton **)(this + 0xc4) != (TouchButton *)0x0) {
    pvVar10 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0xc4));
    operator_delete(pvVar10);
    *(undefined4 *)(this + 0xc4) = 0;
  }
  cVar1 = Globals::iPad;
  iVar12 = *(int *)(Globals::layout + 0x108);
  pTVar8 = operator_new(0xc0);
  iVar3 = 0x1f9;
  if (param_1) {
    iVar3 = 0x1fa;
  }
  if (cVar1 == '\0') {
    pSVar7 = (String *)GameText::getText(Globals::gameText,iVar3);
    TouchButton::TouchButton
              (pTVar8,pSVar7,0,
               (Globals::w - *(int *)(this + 0x198)) - *(int *)(Globals::layout + 0x28),
               *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) + iVar12,
               *(int *)(Globals::layout + 0x2a4),'\x12','\x04');
  }
  else {
    pSVar7 = (String *)GameText::getText(Globals::gameText,iVar3);
    TouchButton::TouchButton
              (pTVar8,pSVar7,7,
               (Globals::w - *(int *)(this + 0x198)) - *(int *)(Globals::layout + 0x28),
               *(int *)(Globals::layout + 0xc) + iVar12 + *(int *)(Globals::layout + 0x20),'\x12');
  }
  *(TouchButton **)(this + 0xc4) = pTVar8;
  TouchButton::setPosition
            (pTVar8,(Globals::w - *(int *)(this + 0x198)) - *(int *)(Globals::layout + 0x28),
             (*(int *)(Globals::layout + 0x70) + *(int *)(this + 0x1b4)) * *(int *)(this + 0x18c) +
             *(int *)(Globals::layout + 0xc) + iVar12 + *(int *)(Globals::layout + 0x20) +
             *(int *)(this + 0x194));
  if (*(TouchButton **)(this + 200) != (TouchButton *)0x0) {
    pvVar10 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 200));
    operator_delete(pvVar10);
    *(undefined4 *)(this + 200) = 0;
  }
  pTVar8 = operator_new(0xc0);
  pSVar7 = (String *)GameText::getText(Globals::gameText,0x41);
  TouchButton::TouchButton
            (pTVar8,pSVar7,7,
             (Globals::w - *(int *)(this + 0x198)) - *(int *)(Globals::layout + 0x28),
             *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) + iVar12,'\x12');
  *(TouchButton **)(this + 200) = pTVar8;
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MenuTouchWindow::saveGame  @0x0014bcf8  (150 bytes)
/* MenuTouchWindow::saveGame(int) */

void __thiscall MenuTouchWindow::saveGame(MenuTouchWindow *this,int param_1)

{
  bool bVar1;
  RecordHandler *this_00;
  GameRecord *this_01;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  String *pSVar5;
  
  this_00 = operator_new(0x20);
  RecordHandler::RecordHandler(this_00);
  RecordHandler::recordStoreWrite(this_00,param_1);
  RecordHandler::recordStoreWritePreview(this_00,param_1);
  iVar4 = *(int *)(*(int *)(this + 0xbc) + 4);
  this_01 = *(GameRecord **)(iVar4 + param_1 * 4);
  if (this_01 != (GameRecord *)0x0) {
    pvVar2 = (void *)GameRecord::~GameRecord(this_01);
    operator_delete(pvVar2);
    iVar4 = *(int *)(*(int *)(this + 0xbc) + 4);
  }
  *(undefined4 *)(iVar4 + param_1 * 4) = 0;
  uVar3 = RecordHandler::recordStoreReadPreview(this_00,param_1);
  *(undefined4 *)(*(int *)(*(int *)(this + 0xbc) + 4) + param_1 * 4) = uVar3;
  pvVar2 = (void *)RecordHandler::~RecordHandler(this_00);
  operator_delete(pvVar2);
  createRecordButtons(this,true);
  pSVar5 = *(String **)(this + 0x104);
  bVar1 = (bool)GameText::getText(Globals::gameText,0x32);
  ChoiceWindow::set(pSVar5,bVar1);
  this[0x170] = (MenuTouchWindow)0x1;
  this[0x173] = (MenuTouchWindow)0x0;
  return;
}

// ===== MenuTouchWindow::showSupernovaMessage  @0x0014bda0  (66 bytes)
/* MenuTouchWindow::showSupernovaMessage() */

void __thiscall MenuTouchWindow::showSupernovaMessage(MenuTouchWindow *this)

{
  String *pSVar1;
  String *pSVar2;
  ChoiceWindow *this_00;
  
  this_00 = *(ChoiceWindow **)(this + 0x104);
  pSVar1 = (String *)GameText::getText(Globals::gameText,0x266);
  pSVar2 = (String *)GameText::getText(Globals::gameText,0x267);
  ChoiceWindow::set(this_00,pSVar1,pSVar2,false);
  this[0x170] = (MenuTouchWindow)0x1;
  this[0x180] = (MenuTouchWindow)0x1;
  return;
}

// ===== MenuTouchWindow::loadGame  @0x0014bde8  (286 bytes)
/* MenuTouchWindow::loadGame(int) */

undefined4 MenuTouchWindow::loadGame(int param_1)

{
  bool bVar1;
  RecordHandler *this;
  GameRecord *this_00;
  void *pvVar2;
  ModStation *this_01;
  int iVar3;
  String *pSVar4;
  
  this = operator_new(0x20);
  RecordHandler::RecordHandler(this);
  this_00 = (GameRecord *)RecordHandler::readRecord((int)this);
  if (this_00 == (GameRecord *)0x0) {
    Status::resetGame(Globals::status);
    pSVar4 = *(String **)(param_1 + 0x104);
    bVar1 = (bool)GameText::getText(Globals::gameText,100);
    ChoiceWindow::set(pSVar4,bVar1);
    *(undefined1 *)(param_1 + 0x170) = 1;
    *(undefined1 *)(param_1 + 0x17e) = 1;
  }
  else {
    if ((this_00[0x117] == (GameRecord)0x0) || (Globals::options[0x37] != '\0')) {
      if ((this_00[0x115] == (GameRecord)0x0) || (Globals::options[0x35] != '\0')) {
        Status::resetGame(Globals::status);
        GameRecord::load(this_00);
        pvVar2 = (void *)RecordHandler::~RecordHandler(this);
        operator_delete(pvVar2);
        pvVar2 = (void *)GameRecord::~GameRecord(this_00);
        operator_delete(pvVar2);
        this_01 = (ModStation *)
                  AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
        ModStation::setGameLoaded(this_01);
        Globals::switch_to_target_setting = 0;
        AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
        return 1;
      }
      iVar3 = 0x65;
      pSVar4 = *(String **)(param_1 + 0x104);
    }
    else {
      iVar3 = 0x66;
      pSVar4 = *(String **)(param_1 + 0x104);
    }
    bVar1 = (bool)GameText::getText(Globals::gameText,iVar3);
    ChoiceWindow::set(pSVar4,bVar1);
    *(undefined1 *)(param_1 + 0x170) = 1;
    pvVar2 = (void *)GameRecord::~GameRecord(this_00);
    operator_delete(pvVar2);
  }
  pvVar2 = (void *)RecordHandler::~RecordHandler(this);
  operator_delete(pvVar2);
  return 0;
}

// ===== MenuTouchWindow::getRelativeScrollStartPos  @0x0014bf38  (44 bytes)
/* MenuTouchWindow::getRelativeScrollStartPos() */

float __thiscall MenuTouchWindow::getRelativeScrollStartPos(MenuTouchWindow *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (*(int *)(this + 0x194) < 1) {
    fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0x194),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x22c),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = -fVar2 / fVar1;
  }
  else {
    fVar1 = 0.0;
  }
  return fVar1;
}

// ===== MenuTouchWindow::getRelativeScrollHeight  @0x0014bf68  (78 bytes)
/* MenuTouchWindow::getRelativeScrollHeight() */

float __thiscall MenuTouchWindow::getRelativeScrollHeight(MenuTouchWindow *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  iVar2 = *(int *)(this + 0x228);
  iVar3 = *(int *)(this + 0x22c);
  if (iVar3 < iVar2) {
    return 0.0;
  }
  iVar1 = *(int *)(this + 0x194);
  if (iVar1 < 1) {
    if (iVar2 - iVar3 <= iVar1) {
      fVar4 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
      goto LAB_0014bfa8;
    }
    iVar2 = iVar1 + iVar3;
  }
  else {
    iVar2 = iVar2 - iVar1;
  }
  fVar4 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
LAB_0014bfa8:
  fVar5 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
  return fVar5 / fVar4;
}

// ===== MenuTouchWindow::drawLoadSaveMenu  @0x0014bfbc  (1226 bytes)
/* MenuTouchWindow::drawLoadSaveMenu(bool) */

void MenuTouchWindow::drawLoadSaveMenu(bool param_1)

{
  Layout *pLVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int local_54;
  int local_50;
  String aSStack_30 [8];
  int local_28;
  
  uVar2 = (uint)param_1;
  local_28 = __stack_chk_guard;
  iVar6 = *(int *)(Globals::layout + 0x10c);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  local_54 = *(int *)(Globals::layout + 0x110);
  local_50 = *(int *)(Globals::layout + 0x114);
  iVar12 = Globals::w + *(int *)(Globals::layout + 0x28) * -2 + *(int *)(uVar2 + 0x198) * -2;
  if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
    if (Globals::iPadHD == '\0') {
      local_50 = 4;
      if (Globals::iPadLarge != '\0') {
        local_50 = 8;
      }
      local_54 = 6;
      if (Globals::iPadLarge != '\0') {
        local_54 = 0xc;
      }
    }
    else {
      local_50 = 5;
      local_54 = 8;
    }
    iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(uVar2 + 0x11c));
    iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(uVar2 + 0x11c));
    iVar5 = __aeabi_idiv(Globals::h,iVar4);
    if (-1 < iVar5) {
      iVar5 = iVar5 + 1;
      iVar9 = 0;
      do {
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(uVar2 + 0x11c),
                   (*(int *)(Globals::layout + 0x28) - iVar3) + *(int *)(uVar2 + 0x198),iVar9,'\x01'
                  );
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(uVar2 + 0x11c),
                   *(int *)(Globals::layout + 0x28) + iVar12 + *(int *)(uVar2 + 0x198),iVar9,'\0');
        iVar9 = iVar9 + iVar4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  TouchButton::setPosition
            (*(TouchButton **)(uVar2 + 0xc4),
             (Globals::w - *(int *)(uVar2 + 0x198)) - *(int *)(Globals::layout + 0x28),
             *(int *)(Globals::layout + 0x108) +
             (*(int *)(uVar2 + 0x1b4) + *(int *)(Globals::layout + 0x70)) * *(int *)(uVar2 + 0x18c)
             + *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
               *(int *)(uVar2 + 0x194));
  if (0 < Globals::recordSlots) {
    iVar3 = 0;
    do {
      iVar4 = (*(int *)(Globals::layout + 0x70) + *(int *)(uVar2 + 0x1b4)) * iVar3 +
              *(int *)(uVar2 + 0x194) +
              *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc);
      if ((-1 < iVar4) && (iVar4 <= Globals::h)) {
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        pLVar1 = Globals::layout;
        iVar11 = *(int *)(uVar2 + 0x18c);
        iVar9 = *(int *)(uVar2 + 0x198);
        iVar5 = *(int *)(Globals::layout + 0x28);
        uVar10 = *(undefined4 *)(Globals::layout + 0x70);
        AbyssEngine::String::String(aSStack_30,"",false);
        uVar7 = 3;
        if (iVar3 == iVar11) {
          uVar7 = 4;
        }
        Layout::drawBox(pLVar1,uVar7,iVar5 + iVar9,iVar4,iVar12 + -3,uVar10,aSStack_30);
        AbyssEngine::String::~String(aSStack_30);
        iVar9 = local_54 + iVar4;
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,
                   (String *)
                   **(undefined4 **)
                     (*(int *)(*(int *)(*(int *)(uVar2 + 0x100) + 4) + iVar3 * 4) + 4),
                   *(int *)(Globals::layout + 0x28) + *(int *)(uVar2 + 0x198) +
                   *(int *)(Globals::layout + 0x2c),iVar9,false);
        iVar5 = *(int *)(*(int *)(*(int *)(uVar2 + 0xbc) + 4) + iVar3 * 4);
        if ((iVar5 != 0) && (uVar8 = *(uint *)(iVar5 + 0x198), uVar8 < 0x40)) {
          ImageFactory::drawShip
                    (Globals::imageFactory,uVar8,
                     *(int *)(Globals::layout + 0x2c) +
                     *(int *)(Globals::layout + 0x28) + *(int *)(uVar2 + 0x198) +
                     *(int *)(uVar2 + 0x1bc),iVar4 + iVar6);
        }
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,
                   *(String **)
                    (*(int *)(*(int *)(*(int *)(*(int *)(uVar2 + 0x100) + 4) + iVar3 * 4) + 4) + 4),
                   *(int *)(Globals::layout + 0x2c4) +
                   *(int *)(Globals::layout + 0x28) + *(int *)(uVar2 + 0x198) +
                   *(int *)(Globals::layout + 0x2c) * 2 + *(int *)(uVar2 + 0x1bc),iVar9,false);
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        iVar4 = iVar4 + local_50;
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,
                   *(String **)
                    (*(int *)(*(int *)(*(int *)(*(int *)(uVar2 + 0x100) + 4) + iVar3 * 4) + 4) + 8),
                   *(int *)(Globals::layout + 0x28) + *(int *)(uVar2 + 0x198) +
                   *(int *)(Globals::layout + 0x2c),iVar4 + *(int *)(Globals::layout + 0x70) / 2,
                   false);
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,
                   *(String **)
                    (*(int *)(*(int *)(*(int *)(*(int *)(uVar2 + 0x100) + 4) + iVar3 * 4) + 4) + 0xc
                    ),*(int *)(Globals::layout + 0x28) + *(int *)(uVar2 + 0x198) +
                      *(int *)(Globals::layout + 0x2c) * 2 + *(int *)(uVar2 + 0x1bc) +
                      *(int *)(Globals::layout + 0x2c4),iVar4 + *(int *)(Globals::layout + 0x70) / 2
                   ,false);
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,
                   *(String **)
                    (*(int *)(*(int *)(*(int *)(*(int *)(uVar2 + 0x100) + 4) + iVar3 * 4) + 4) +
                    0x10),*(int *)(Globals::layout + 0x28) + *(int *)(uVar2 + 0x198) +
                          *(int *)(Globals::layout + 0x2c4) +
                          (*(int *)(Globals::layout + 0x2c) + *(int *)(uVar2 + 0x1b8)) * 2,iVar9,
                   false);
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,
                   *(String **)
                    (*(int *)(*(int *)(*(int *)(*(int *)(uVar2 + 0x100) + 4) + iVar3 * 4) + 4) +
                    0x14),*(int *)(Globals::layout + 0x28) + *(int *)(uVar2 + 0x198) +
                          *(int *)(Globals::layout + 0x2c4) +
                          (*(int *)(Globals::layout + 0x2c) + *(int *)(uVar2 + 0x1b8)) * 2,
                   iVar4 + *(int *)(Globals::layout + 0x70) / 2,false);
        if (iVar3 == *(int *)(uVar2 + 0x18c)) {
          TouchButton::draw(*(TouchButton **)(uVar2 + 0xc4));
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < Globals::recordSlots);
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== MenuTouchWindow::draw  @0x0014c50c  (13424 bytes)
/* MenuTouchWindow::draw() */

void __thiscall MenuTouchWindow::draw(MenuTouchWindow *this)

{
  ushort uVar1;
  ushort uVar2;
  MenuTouchWindow **ppMVar3;
  bool bVar4;
  PaintCanvas *pPVar5;
  GameText *this_00;
  MenuTouchWindow *pMVar6;
  short sVar7;
  ushort uVar8;
  uint uVar9;
  PaintCanvas *pPVar10;
  String *pSVar11;
  undefined4 uVar12;
  int *piVar13;
  Ship *this_01;
  TouchButton *pTVar14;
  MenuTouchWindow *pMVar15;
  MenuTouchWindow *extraout_r1;
  MenuTouchWindow *extraout_r1_00;
  MenuTouchWindow *extraout_r1_01;
  undefined **ppuVar16;
  MenuTouchWindow *extraout_r1_02;
  MenuTouchWindow *extraout_r1_03;
  float *pfVar17;
  MenuTouchWindow *extraout_r1_04;
  uint uVar18;
  MenuTouchWindow *extraout_r1_05;
  undefined4 extraout_r1_06;
  MenuTouchWindow *extraout_r1_07;
  MenuTouchWindow *extraout_r1_08;
  undefined4 extraout_r1_09;
  MenuTouchWindow *extraout_r1_10;
  MenuTouchWindow *extraout_r1_11;
  MenuTouchWindow *pMVar19;
  uint *puVar20;
  undefined **ppuVar21;
  MenuTouchWindow *pMVar22;
  uint uVar23;
  MenuTouchWindow *pMVar24;
  int iVar25;
  int iVar26;
  Layout *pLVar27;
  int iVar28;
  MenuTouchWindow *pMVar29;
  undefined4 uVar30;
  int iVar31;
  int iVar32;
  String *pSVar33;
  undefined4 uVar34;
  int iVar35;
  int iVar36;
  undefined4 uVar37;
  bool bVar38;
  uint in_fpscr;
  float fVar39;
  float fVar40;
  float fVar41;
  float fVar42;
  undefined8 uVar43;
  MenuTouchWindow *local_234;
  MenuTouchWindow *local_230;
  MenuTouchWindow *local_22c;
  String aSStack_228 [8];
  String aSStack_220 [8];
  float local_218;
  float local_214;
  String aSStack_20c [8];
  String aSStack_204 [12];
  float local_1f8;
  float local_1f0;
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
  undefined4 local_11c [2];
  String aSStack_114 [8];
  String aSStack_10c [8];
  AbyssEngine aAStack_104 [8];
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
  String aSStack_ac [12];
  float local_a0;
  float local_98;
  String aSStack_8c [8];
  String aSStack_84 [8];
  String aSStack_7c [12];
  float local_70;
  float local_68;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  Globals::is_menu_visible = 1;
  local_234 = this + 4;
  Globals::topMenuIndex = *(int *)(this + 0x16c);
  pMVar19 = this + 0xb4;
  pMVar22 = local_234;
  if (Globals::topMenuIndex == 0xc) {
    pMVar22 = pMVar19;
  }
  local_230 = this + 0xb0;
  if (Globals::topMenuIndex == 0xe) {
    pMVar22 = local_230;
  }
  puVar20 = *(uint **)pMVar22;
  uVar9 = *puVar20;
  local_22c = this;
  if (uVar9 == 0) {
    uVar9 = 0;
  }
  else {
    uVar23 = 0;
    do {
      if ((int)uVar23 < 10) {
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_x + uVar23 * 4) = (int)local_68;
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_y + uVar23 * 4) = (int)local_70;
        uVar9 = *puVar20;
      }
      uVar23 = uVar23 + 1;
    } while (uVar23 < uVar9);
  }
  pMVar22 = local_22c;
  pMVar29 = *(MenuTouchWindow **)(Globals::layout + 0x118);
  pMVar24 = *(MenuTouchWindow **)(Globals::layout + 0x11c);
  iVar26 = *(int *)(Globals::layout + 0x120);
  Globals::sub_menu_button_count = uVar9;
  if (*(int *)(local_22c + 0x168) == 0) {
LAB_0014c5fc:
    pMVar15 = *(MenuTouchWindow **)(pMVar22 + 0x16c);
  }
  else {
    pMVar15 = *(MenuTouchWindow **)(local_22c + 0x16c);
    if (((uint)pMVar15 | 4) != 0xd) {
      Layout::drawBG(Globals::layout);
      goto LAB_0014c5fc;
    }
  }
  pMVar6 = local_22c;
  pMVar22 = local_230;
  pLVar27 = Globals::layout;
  if ((MenuTouchWindow *)0x11 < pMVar15) goto switchD_0014c608_caseD_5;
  iVar25 = Globals::w >> 1;
  switch(pMVar15) {
  case (MenuTouchWindow *)0x0:
    if (*(int *)(local_22c + 0x168) == 0) {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      pPVar10 = Globals::Canvas;
      uVar9 = *(uint *)(pMVar6 + 0x120);
      iVar26 = Globals::w >> 1;
      if ((Globals::iPad == '\0') || (Globals::iPadAssetsWithLowerRes != '\0')) {
        iVar31 = *(int *)(Globals::layout + 0xc);
        iVar25 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar9);
        iVar28 = AbyssEngine::PaintCanvas::GetImage2DHeight
                           (Globals::Canvas,*(uint *)(local_22c + 0x120));
        AbyssEngine::PaintCanvas::DrawImage2D
                  (pPVar10,uVar9,iVar26,(int)(iVar31 + ((uint)(iVar31 >> 0x1f) >> 0x1e)) >> 2,
                   iVar25 / 2,iVar28 / 2,'\x11','\x14','\0');
      }
      else {
        AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar9,iVar26,0x50,'\x11','\x14');
      }
    }
    else {
      iVar26 = 0xab;
      if (*(int *)(local_22c + 0x168) == 1) {
        iVar26 = 0x28;
      }
      pSVar11 = (String *)GameText::getText(Globals::gameText,iVar26);
      AbyssEngine::String::String(aSStack_1e4,pSVar11,false);
      Layout::drawHeader(pLVar27,aSStack_1e4,0);
      AbyssEngine::String::~String(aSStack_1e4);
    }
    pMVar22 = local_234;
    puVar20 = *(uint **)local_234;
    if (*puVar20 != 0) {
      uVar9 = 0;
      do {
        TouchButton::draw(*(TouchButton **)(puVar20[1] + uVar9 * 4));
        puVar20 = *(uint **)pMVar22;
        uVar9 = uVar9 + 1;
      } while (uVar9 < *puVar20);
    }
    piVar13 = *(int **)(local_22c + 0xc0);
    pMVar15 = (MenuTouchWindow *)0x0;
    if (*piVar13 != 0) {
      pMVar22 = (MenuTouchWindow *)0x0;
      local_234 = (MenuTouchWindow *)Globals::options;
      do {
        pMVar19 = local_22c;
        pTVar14 = *(TouchButton **)(piVar13[1] + (int)pMVar22 * 4);
        if (*(int *)pTVar14 == 0x35) {
          TouchButton::draw(pTVar14);
          pMVar19 = local_22c;
          if ((Globals::inAppPurchaseSupported != '\0') && (local_234[0x3b] == (MenuTouchWindow)0x0)
             ) {
            iVar26 = AbyssEngine::PaintCanvas::GetImage2DWidth
                               (Globals::Canvas,*(uint *)(local_22c + 0x124));
            uVar12 = TouchButton::getWidth
                               (*(TouchButton **)
                                 (*(int *)(*(int *)(pMVar19 + 0xc0) + 4) + (int)pMVar22 * 4));
            fVar39 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
            iVar25 = (int)(fVar39 * 0.25);
            if (Globals::retinaDisplay == '\0') {
              if (Globals::iPadHD != '\0') {
                iVar25 = iVar25 + -4;
              }
            }
            else {
              iVar25 = iVar25 + -5;
            }
            uVar43 = AbyssEngine::ApplicationManager::GetCurrentTimeMillis(Globals::appManager);
            pMVar19 = local_22c;
            pPVar10 = Globals::Canvas;
            local_230 = *(MenuTouchWindow **)(local_22c + 0x124);
            TouchButton::getPosition();
            fVar39 = local_1f0;
            TouchButton::getPosition();
            fVar42 = (float)VectorSignedToFloat(iVar25,(byte)(in_fpscr >> 0x16) & 3);
            fVar41 = (float)VectorSignedToFloat(iVar26,(byte)(in_fpscr >> 0x16) & 3);
            fVar40 = (float)__aeabi_l2f((int)uVar43,(int)((ulonglong)uVar43 >> 0x20));
            AbyssEngine::PaintCanvas::DrawRegion2D
                      (pPVar10,(uint)local_230,0,0,iVar26,iVar26,(float)(int)(local_1f8 - fVar42),
                       (int)(fVar40 * 0.004),(int)(fVar41 * 0.5),(int)(fVar41 * 0.5),
                       (int)(fVar39 - fVar42));
          }
        }
        else if (*(int *)pTVar14 - 0x17U < 2) {
          TouchButton::draw(pTVar14);
        }
        piVar13 = *(int **)(pMVar19 + 0xc0);
        pMVar22 = pMVar22 + 1;
        pMVar15 = (MenuTouchWindow *)*piVar13;
      } while (pMVar22 < pMVar15);
    }
    break;
  case (MenuTouchWindow *)0x1:
  case (MenuTouchWindow *)0x2:
    Layout::drawBG(Globals::layout);
    pMVar22 = local_22c;
    pLVar27 = Globals::layout;
    iVar26 = 0x1d;
    if (*(int *)(local_22c + 0x16c) == 2) {
      iVar26 = 0x1e;
    }
    pSVar11 = (String *)GameText::getText(Globals::gameText,iVar26);
    AbyssEngine::String::String(aSStack_bc,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_bc,0);
    AbyssEngine::String::~String(aSStack_bc);
    drawLoadSaveMenu(SUB41(pMVar22,0));
    pMVar15 = extraout_r1;
    break;
  case (MenuTouchWindow *)0x3:
    if (Globals::iPad == '\0') {
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f);
      AbyssEngine::String::String(aSStack_174,pSVar11,false);
      Layout::drawHeader(pLVar27,aSStack_174,0);
      AbyssEngine::String::~String(aSStack_174);
      piVar13 = *(int **)(local_22c + 0xac);
      pMVar15 = (MenuTouchWindow *)0x0;
      if (*piVar13 != 0) {
        pMVar22 = (MenuTouchWindow *)0x0;
        do {
          TouchButton::draw(*(TouchButton **)(piVar13[1] + (int)pMVar22 * 4));
          pMVar22 = pMVar22 + 1;
          piVar13 = *(int **)(local_22c + 0xac);
          pMVar15 = (MenuTouchWindow *)*piVar13;
        } while (pMVar22 < pMVar15);
      }
      break;
    }
    local_234 = pMVar24;
    local_230 = pMVar29;
    Layout::drawBG(Globals::layout);
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f2);
    AbyssEngine::String::String(aSStack_cc,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_cc,0);
    AbyssEngine::String::~String(aSStack_cc);
    pMVar22 = local_22c;
    iVar25 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(local_22c + 0x11c))
    ;
    iVar28 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(pMVar22 + 0x11c));
    iVar31 = __aeabi_idiv(Globals::h,iVar28);
    if (-1 < iVar31) {
      iVar31 = iVar31 + 1;
      iVar35 = 0;
      pMVar19 = pMVar22;
      do {
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(pMVar19 + 0x11c),
                   *(int *)(Globals::layout + 0x28) + (*(int *)(pMVar19 + 0x19c) - iVar25),iVar35,
                   '\x01');
        pMVar22 = local_22c;
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(pMVar19 + 0x11c),
                   *(int *)(Globals::layout + 0x28) + *(int *)(pMVar19 + 0x19c) +
                   *(int *)(local_22c + 0x1a0),iVar35,'\0');
        iVar35 = iVar35 + iVar28;
        iVar31 = iVar31 + -1;
        pMVar19 = pMVar22;
      } while (iVar31 != 0);
    }
    pLVar27 = Globals::layout;
    uVar34 = *(undefined4 *)(pMVar22 + 0x150);
    iVar25 = *(int *)(pMVar22 + 0x19c);
    iVar35 = *(int *)(Globals::layout + 0xc);
    uVar37 = *(undefined4 *)(Globals::layout + 0x1c);
    iVar28 = *(int *)(Globals::layout + 0x20);
    iVar31 = *(int *)(Globals::layout + 0x28);
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f2);
    uVar12 = AbyssEngine::String::String(aSStack_d4,pSVar11,false);
    Layout::drawBox(pLVar27,0,iVar31 + iVar25,iVar35 + iVar28,uVar34,uVar37,uVar12);
    AbyssEngine::String::~String(aSStack_d4);
    pLVar27 = Globals::layout;
    uVar12 = *(undefined4 *)(pMVar22 + 0x154);
    uVar37 = *(undefined4 *)(pMVar22 + 0x150);
    iVar25 = *(int *)(pMVar22 + 0x19c);
    iVar31 = *(int *)(Globals::layout + 0x1c);
    iVar36 = *(int *)(Globals::layout + 0x28);
    iVar32 = *(int *)(Globals::layout + 0x2c);
    uVar34 = AbyssEngine::String::String(aSStack_dc,"",false);
    iVar32 = iVar31 + iVar35 + iVar28 + iVar32;
    Layout::drawBox(pLVar27,5,iVar36 + iVar25,iVar32,uVar37,uVar12,uVar34);
    AbyssEngine::String::~String(aSStack_dc);
    pMVar19 = local_22c;
    pMVar22 = local_230;
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pMVar24 = local_22c;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(pMVar19 + 0x110),
               *(int *)(Globals::layout + 0x28) + *(int *)(local_22c + 0x19c) +
               *(int *)(pMVar19 + 0x158) / 2,iVar32 + (int)pMVar22 * 2,'\x11','\x14');
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(pMVar24 + 0x10c),
               ((*(int *)(pMVar24 + 0x19c) + *(int *)(pMVar24 + 0x1a0)) -
               *(int *)(Globals::layout + 0x28)) - *(int *)(pMVar24 + 0x158) / 2,
               (int)(local_230 + iVar32),'\x11','\x14');
    local_230 = (MenuTouchWindow *)Globals::options;
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pMVar22 = Globals::font;
    pPVar10 = Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1ea);
    pMVar19 = Globals::font;
    pPVar5 = Globals::Canvas;
    iVar25 = *(int *)(Globals::layout + 0x28);
    iVar28 = *(int *)(pMVar24 + 0x158);
    iVar31 = *(int *)(pMVar24 + 0x19c);
    pSVar33 = (String *)GameText::getText(Globals::gameText,0x1ea);
    iVar35 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar19,pSVar33);
    local_234 = (MenuTouchWindow *)(iVar32 - (int)local_234);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)pMVar22,pSVar11,(iVar25 + iVar31 + iVar28 / 2) - iVar35 / 2,
               (int)(local_234 + *(int *)(pMVar24 + 0x154)),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pPVar10 = Globals::Canvas;
    local_230 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1eb);
    pMVar22 = Globals::font;
    pPVar5 = Globals::Canvas;
    iVar25 = *(int *)(Globals::layout + 0x28);
    iVar36 = *(int *)(pMVar24 + 0x158);
    iVar31 = *(int *)(pMVar24 + 0x19c);
    iVar35 = *(int *)(pMVar24 + 0x1a0);
    pSVar33 = (String *)GameText::getText(Globals::gameText,0x1eb);
    iVar28 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar22,pSVar33);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_230,pSVar11,
               (((iVar35 + iVar31) - iVar25) - iVar36 / 2) - iVar28 / 2,
               (int)(local_234 + *(int *)(pMVar24 + 0x154)),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pLVar27 = Globals::layout;
    uVar34 = *(undefined4 *)(pMVar24 + 0x158);
    local_230 = *(MenuTouchWindow **)(pMVar24 + 0x15c);
    iVar25 = *(int *)(pMVar24 + 0x154);
    iVar35 = *(int *)(pMVar24 + 0x19c);
    iVar31 = *(int *)(Globals::layout + 0x28);
    iVar28 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_e4,"",false);
    pMVar22 = local_230;
    local_230 = (MenuTouchWindow *)(iVar32 + iVar25 + iVar28);
    Layout::drawBox(pLVar27,5,iVar31 + iVar35,local_230,uVar34,pMVar22,uVar12);
    AbyssEngine::String::~String(aSStack_e4);
    pLVar27 = Globals::layout;
    iVar28 = *(int *)(pMVar24 + 0x158);
    uVar34 = *(undefined4 *)(pMVar24 + 0x15c);
    iVar31 = *(int *)(pMVar24 + 0x19c);
    iVar25 = *(int *)(Globals::layout + 0x28);
    iVar35 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_ec,"",false);
    Layout::drawBox(pLVar27,5,iVar31 + iVar25 + iVar28 + iVar35 + 1,local_230,iVar28,uVar34,uVar12);
    AbyssEngine::String::~String(aSStack_ec);
    pLVar27 = Globals::layout;
    uVar34 = *(undefined4 *)(pMVar24 + 0x158);
    iVar25 = *(int *)(pMVar24 + 0x15c);
    iVar28 = *(int *)(pMVar24 + 0x19c);
    iVar31 = *(int *)(Globals::layout + 0x28);
    iVar35 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_f4,"",false);
    Layout::drawBox(pLVar27,5,iVar31 + iVar28,local_230 + iVar35 + iVar25,uVar34,iVar25,uVar12);
    AbyssEngine::String::~String(aSStack_f4);
    pLVar27 = Globals::layout;
    iVar32 = *(int *)(pMVar24 + 0x158);
    iVar25 = *(int *)(pMVar24 + 0x15c);
    iVar31 = *(int *)(pMVar24 + 0x19c);
    iVar35 = *(int *)(Globals::layout + 0x28);
    iVar28 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_fc,"",false);
    Layout::drawBox(pLVar27,5,iVar31 + iVar35 + iVar32 + iVar28 + 1,local_230 + iVar25 + iVar28,
                    iVar32,iVar25,uVar12);
    AbyssEngine::String::~String(aSStack_fc);
    pPVar10 = Globals::Canvas;
    local_234 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,500);
    iVar28 = *(int *)(pMVar24 + 0x15c);
    iVar35 = *(int *)(pMVar24 + 0x19c);
    iVar31 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_234,pSVar11,iVar35 + iVar31 + 10,
               (int)(local_230 + (iVar28 / 2 - iVar25 / 2) + 1),false);
    pMVar22 = Globals::font;
    pPVar10 = Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,499);
    AbyssEngine::String::String(aSStack_10c," [",false);
    AbyssEngine::operator+(aAStack_104,pSVar11,aSStack_10c);
    TouchSlider::getValue((TouchSlider *)**(undefined4 **)(*(int *)(pMVar24 + 0xec) + 4));
    local_11c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1_09,local_11c));
    AbyssEngine::String::String(aSStack_114,(String *)local_11c,false);
    pMVar19 = local_230;
    AbyssEngine::operator+((AbyssEngine *)aSStack_b4,aAStack_104,aSStack_114);
    AbyssEngine::String::String(aSStack_124,"]",false);
    AbyssEngine::operator+((AbyssEngine *)&local_218,aSStack_b4,aSStack_124);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)pMVar22,(String *)&local_218,
               *(int *)(pMVar24 + 0x19c) + *(int *)(Globals::layout + 0x28) + 10,
               (int)(pMVar19 + *(int *)(pMVar24 + 0x15c) + *(int *)(Globals::layout + 0x2c) + 10),
               false);
    AbyssEngine::String::~String((String *)&local_218);
    AbyssEngine::String::~String(aSStack_124);
    AbyssEngine::String::~String(aSStack_b4);
    AbyssEngine::String::~String(aSStack_114);
    AbyssEngine::String::~String((String *)local_11c);
    AbyssEngine::String::~String((String *)aAStack_104);
    AbyssEngine::String::~String(aSStack_10c);
    TouchSlider::draw((TouchSlider *)**(undefined4 **)(*(int *)(pMVar24 + 0xec) + 4));
    TouchButton::setPosition
              (*(TouchButton **)(pMVar24 + 0xcc),
               *(int *)(pMVar24 + 0x19c) + *(int *)(Globals::layout + 0x28) +
               *(int *)(pMVar24 + 0x158) + -10,(int)(pMVar19 + *(int *)(pMVar24 + 0x15c) / 2));
    TouchButton::draw(*(TouchButton **)(pMVar24 + 0xcc));
    TouchButton::setPosition
              (*(TouchButton **)(pMVar24 + 0xd0),
               ((*(int *)(pMVar24 + 0x1a0) + *(int *)(pMVar24 + 0x19c)) -
               *(int *)(Globals::layout + 0x28)) - *(int *)(pMVar24 + 0x158) / 2,
               (int)(pMVar19 + *(int *)(pMVar24 + 0x15c) / 2));
    TouchButton::draw(*(TouchButton **)(pMVar24 + 0xd0));
    TouchButton::setPosition
              (*(TouchButton **)(pMVar24 + 0xe4),
               ((*(int *)(pMVar24 + 0x1a0) + *(int *)(pMVar24 + 0x19c)) -
               *(int *)(Globals::layout + 0x28)) - *(int *)(pMVar24 + 0x158) / 2,
               (int)(pMVar19 +
                    *(int *)(pMVar24 + 0x15c) / 2 +
                    *(int *)(Globals::layout + 0x2c) + *(int *)(pMVar24 + 0x15c)));
    TouchButton::draw(*(TouchButton **)(pMVar24 + 0xe4));
    pMVar19 = pMVar19 + *(int *)(Globals::layout + 0x2fc) +
                        *(int *)(Globals::layout + 0x2c) + *(int *)(pMVar24 + 0x15c) * 2;
    TouchButton::setPosition
              (*(TouchButton **)(pMVar24 + 0xd4),
               (*(int *)(pMVar24 + 0x19c) + *(int *)(pMVar24 + 0x1a0) + -0x19) -
               *(int *)(Globals::layout + 0x28),
               (int)(pMVar19 +
                    *(int *)(Globals::layout + 0x1c) + *(int *)(Globals::layout + 0x2c) + 7));
    TouchButton::setPosition
              (*(TouchButton **)(pMVar24 + 0xd8),
               (*(int *)(pMVar24 + 0x19c) + *(int *)(pMVar24 + 0x1a0) + -0x19) -
               *(int *)(Globals::layout + 0x28),
               (int)(pMVar19 +
                    *(int *)(Globals::layout + 0x2c) * 2 +
                    *(int *)(Globals::layout + 0x1c) + *(int *)(pMVar24 + 0x164) + 7));
    TouchButton::setPosition
              (*(TouchButton **)(pMVar24 + 0xdc),
               (*(int *)(pMVar24 + 0x1a0) + *(int *)(pMVar24 + 0x19c) + -0x19) -
               *(int *)(Globals::layout + 0x28),
               (int)(pMVar19 +
                    *(int *)(Globals::layout + 0x2c) * 3 +
                    *(int *)(Globals::layout + 0x1c) + *(int *)(pMVar24 + 0x164) * 2 + 7));
    pLVar27 = Globals::layout;
    uVar37 = *(undefined4 *)(pMVar24 + 0x150);
    iVar28 = *(int *)(pMVar24 + 0x19c);
    uVar34 = *(undefined4 *)(Globals::layout + 0x1c);
    iVar25 = *(int *)(Globals::layout + 0x28);
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f5);
    uVar12 = AbyssEngine::String::String(aSStack_12c,pSVar11,false);
    local_230 = pMVar19;
    Layout::drawBox(pLVar27,0,iVar25 + iVar28,pMVar19,uVar37,uVar34,uVar12);
    AbyssEngine::String::~String(aSStack_12c);
    pLVar27 = Globals::layout;
    uVar34 = *(undefined4 *)(pMVar24 + 0x150);
    uVar37 = *(undefined4 *)(pMVar24 + 0x164);
    local_234 = *(MenuTouchWindow **)(pMVar24 + 0x19c);
    iVar25 = *(int *)(Globals::layout + 0x1c);
    iVar28 = *(int *)(Globals::layout + 0x28);
    iVar31 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_134,"",false);
    pMVar19 = local_230 + iVar31 + iVar25;
    Layout::drawBox(pLVar27,5,local_234 + iVar28,pMVar19,uVar34,uVar37,uVar12);
    AbyssEngine::String::~String(aSStack_134);
    local_230 = Globals::font;
    local_234 = (MenuTouchWindow *)Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x22);
    iVar35 = *(int *)(pMVar24 + 0x19c);
    iVar31 = *(int *)(pMVar24 + 0x164);
    iVar28 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              ((PaintCanvas *)local_234,(uint)local_230,pSVar11,iVar35 + iVar28 + 10,
               (int)(pMVar19 + (iVar31 / 2 - iVar25 / 2) + 1),false);
    pLVar27 = Globals::layout;
    local_230 = *(MenuTouchWindow **)(pMVar24 + 0x19c);
    uVar34 = *(undefined4 *)(pMVar24 + 0x150);
    iVar25 = *(int *)(pMVar24 + 0x164);
    iVar31 = *(int *)(Globals::layout + 0x28);
    iVar28 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_13c,"",false);
    pMVar22 = local_230 + iVar31;
    local_230 = pMVar19 + iVar28 + iVar25;
    Layout::drawBox(pLVar27,5,pMVar22,pMVar19 + iVar28 + iVar25,uVar34,iVar25,uVar12);
    AbyssEngine::String::~String(aSStack_13c);
    pPVar10 = Globals::Canvas;
    local_234 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x23);
    iVar35 = *(int *)(pMVar24 + 0x19c);
    iVar31 = *(int *)(pMVar24 + 0x164);
    iVar28 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    pMVar22 = local_230;
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_234,pSVar11,iVar35 + iVar28 + 10,
               (int)(local_230 + (iVar31 / 2 - iVar25 / 2) + 1),false);
    pLVar27 = Globals::layout;
    local_234 = *(MenuTouchWindow **)(pMVar24 + 0x19c);
    uVar34 = *(undefined4 *)(pMVar24 + 0x150);
    iVar25 = *(int *)(pMVar24 + 0x164);
    iVar31 = *(int *)(Globals::layout + 0x28);
    iVar28 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_144,"",false);
    pMVar22 = pMVar22 + iVar28 + iVar25;
    Layout::drawBox(pLVar27,5,local_234 + iVar31,pMVar22,uVar34,iVar25,uVar12);
    AbyssEngine::String::~String(aSStack_144);
    local_230 = Globals::font;
    local_234 = (MenuTouchWindow *)Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x24);
    iVar35 = *(int *)(pMVar24 + 0x19c);
    iVar31 = *(int *)(pMVar24 + 0x164);
    iVar28 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              ((PaintCanvas *)local_234,(uint)local_230,pSVar11,iVar35 + iVar28 + 10,
               (int)(pMVar22 + (iVar31 / 2 - iVar25 / 2) + 1),false);
    pLVar27 = Globals::layout;
    pMVar22 = pMVar22 + *(int *)(Globals::layout + 0x2fc) + *(int *)(pMVar24 + 0x164);
    if (Globals::iPadLargePossible == '\0') {
      local_230 = *(MenuTouchWindow **)(pMVar24 + 0x19c);
      uVar37 = *(undefined4 *)(pMVar24 + 0x150);
      uVar34 = *(undefined4 *)(Globals::layout + 0x1c);
      iVar25 = *(int *)(Globals::layout + 0x28);
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f6);
      uVar12 = AbyssEngine::String::String(aSStack_14c,pSVar11,false);
      pMVar19 = local_230 + iVar25;
      local_230 = pMVar22;
      Layout::drawBox(pLVar27,0,pMVar19,pMVar22,uVar37,uVar34,uVar12);
      AbyssEngine::String::~String(aSStack_14c);
      pLVar27 = Globals::layout;
      uVar34 = *(undefined4 *)(pMVar24 + 0x150);
      uVar37 = *(undefined4 *)(pMVar24 + 0x164);
      iVar31 = *(int *)(pMVar24 + 0x19c);
      iVar25 = *(int *)(Globals::layout + 0x1c);
      iVar28 = *(int *)(Globals::layout + 0x28);
      iVar35 = *(int *)(Globals::layout + 0x2c);
      uVar12 = AbyssEngine::String::String(aSStack_154,"",false);
      pMVar22 = local_230 + iVar35 + iVar25;
      Layout::drawBox(pLVar27,5,iVar28 + iVar31,pMVar22,uVar34,uVar37,uVar12);
      AbyssEngine::String::~String(aSStack_154);
      pPVar10 = Globals::Canvas;
      pMVar24 = local_22c;
      if (Globals::iPadLargePossible != '\0') goto LAB_0014f068;
      local_234 = Globals::font;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f7);
      pMVar19 = local_22c;
      iVar31 = *(int *)(local_22c + 0x160);
      iVar35 = *(int *)(local_22c + 0x19c);
      iVar28 = *(int *)(Globals::layout + 0x28);
      iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
      local_230 = pMVar22;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)local_234,pSVar11,iVar35 + iVar28 + 10,
                 (int)(pMVar22 + (iVar31 / 2 - iVar25 / 2) + 1),false);
      pMVar24 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x201);
      local_234 = pMVar22 + -iVar26;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar24,pSVar11,
                 *(int *)(pMVar19 + 0x1c0) +
                 *(int *)(Globals::layout + 0x28) + *(int *)(pMVar19 + 0x19c),
                 (int)(local_234 + *(int *)(pMVar19 + 0x164)),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x202);
      iVar25 = *(int *)(Globals::layout + 0x28);
      iVar35 = *(int *)(pMVar19 + 0x19c);
      iVar32 = *(int *)(pMVar19 + 0x1c0);
      iVar28 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar19 + 0xec) + 4) + 0x10));
      pMVar24 = Globals::font;
      pPVar5 = Globals::Canvas;
      pSVar33 = (String *)GameText::getText(Globals::gameText,0x202);
      iVar31 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar24,pSVar33);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,(iVar25 + iVar35 + iVar32 + iVar28 / 2) - iVar31 / 2,
                 (int)(local_234 + *(int *)(pMVar19 + 0x164)),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x203);
      iVar25 = *(int *)(Globals::layout + 0x28);
      iVar35 = *(int *)(pMVar19 + 0x19c);
      iVar32 = *(int *)(pMVar19 + 0x1c0);
      iVar28 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar19 + 0xec) + 4) + 0x10));
      pMVar24 = Globals::font;
      pPVar5 = Globals::Canvas;
      pSVar33 = (String *)GameText::getText(Globals::gameText,0x203);
      iVar31 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar24,pSVar33);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,(iVar25 + iVar35 + iVar32 + iVar28) - iVar31,
                 (int)(local_234 + *(int *)(pMVar19 + 0x164)),false);
      pLVar27 = Globals::layout;
      uVar34 = *(undefined4 *)(pMVar19 + 0x150);
      iVar25 = *(int *)(pMVar19 + 0x164);
      iVar31 = *(int *)(pMVar19 + 0x19c);
      iVar35 = *(int *)(Globals::layout + 0x28);
      iVar28 = *(int *)(Globals::layout + 0x2c);
      uVar12 = AbyssEngine::String::String(aSStack_16c,"",false);
      local_230 = local_230 + iVar28 + iVar25;
      Layout::drawBox(pLVar27,5,iVar35 + iVar31,local_230,uVar34,iVar25,uVar12);
      AbyssEngine::String::~String(aSStack_16c);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f8);
      local_234 = (MenuTouchWindow *)&Globals::layout;
      iVar31 = *(int *)(pMVar19 + 0x160);
      iVar28 = *(int *)(pMVar19 + 0x19c);
      iVar35 = *(int *)(Globals::layout + 0x28);
      iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
      pMVar29 = local_230;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,iVar28 + iVar35 + 10,
                 (int)(local_230 + (iVar31 / 2 - iVar25 / 2) + 1),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1fb);
      pMVar24 = local_234;
      local_230 = pMVar29 + -iVar26;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,
                 *(int *)(pMVar19 + 0x1c0) +
                 *(int *)(*(int *)local_234 + 0x28) + *(int *)(pMVar19 + 0x19c),
                 (int)(local_230 + *(int *)(pMVar19 + 0x164)),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1fc);
      iVar26 = *(int *)(*(int *)pMVar24 + 0x28);
      iVar31 = *(int *)(pMVar19 + 0x19c);
      iVar35 = *(int *)(pMVar19 + 0x1c0);
      iVar25 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar19 + 0xec) + 4) + 0x14));
      pMVar24 = Globals::font;
      pPVar5 = Globals::Canvas;
      pSVar33 = (String *)GameText::getText(Globals::gameText,0x1fc);
      iVar28 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar24,pSVar33);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,(iVar26 + iVar31 + iVar35 + iVar25 / 2) - iVar28 / 2,
                 (int)(local_230 + *(int *)(pMVar19 + 0x164)),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1fd);
      local_234 = *(MenuTouchWindow **)(*(int *)local_234 + 0x28);
      iVar28 = *(int *)(pMVar19 + 0x19c);
      iVar31 = *(int *)(pMVar19 + 0x1c0);
      iVar26 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar19 + 0xec) + 4) + 0x14));
      pMVar24 = Globals::font;
      pPVar5 = Globals::Canvas;
      pSVar33 = (String *)GameText::getText(Globals::gameText,0x1fd);
      iVar25 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar24,pSVar33);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,
                 (int)(local_234 + ((iVar26 + iVar31 + iVar28) - iVar25)),
                 (int)(local_230 + *(int *)(pMVar19 + 0x164)),false);
    }
    else {
LAB_0014f068:
      pLVar27 = Globals::layout;
      uVar37 = *(undefined4 *)(pMVar24 + 0x150);
      iVar25 = *(int *)(pMVar24 + 0x19c);
      uVar34 = *(undefined4 *)(Globals::layout + 0x1c);
      iVar28 = *(int *)(Globals::layout + 0x28);
      local_230 = pMVar22;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f6);
      uVar12 = AbyssEngine::String::String(aSStack_15c,pSVar11,false);
      Layout::drawBox(pLVar27,0,iVar28 + iVar25,pMVar22,uVar37,uVar34,uVar12);
      AbyssEngine::String::~String(aSStack_15c);
      pLVar27 = Globals::layout;
      uVar34 = *(undefined4 *)(pMVar24 + 0x150);
      uVar37 = *(undefined4 *)(pMVar24 + 0x164);
      local_234 = *(MenuTouchWindow **)(pMVar24 + 0x19c);
      iVar25 = *(int *)(Globals::layout + 0x1c);
      iVar31 = *(int *)(Globals::layout + 0x28);
      iVar28 = *(int *)(Globals::layout + 0x2c);
      uVar12 = AbyssEngine::String::String(aSStack_164,"",false);
      local_230 = local_230 + iVar28 + iVar25;
      Layout::drawBox(pLVar27,5,local_234 + iVar31,local_230,uVar34,uVar37,uVar12);
      AbyssEngine::String::~String(aSStack_164);
      pPVar10 = Globals::Canvas;
      local_234 = Globals::font;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f8);
      iVar31 = *(int *)(pMVar24 + 0x160);
      iVar35 = *(int *)(pMVar24 + 0x19c);
      iVar28 = *(int *)(Globals::layout + 0x28);
      iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
      pMVar19 = local_230;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)local_234,pSVar11,iVar35 + iVar28 + 10,
                 (int)(local_230 + (iVar31 / 2 - iVar25 / 2) + 1),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      AbyssEngine::String::String((String *)&local_218,"1024x768",false);
      local_230 = pMVar19 + -iVar26;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,(String *)&local_218,
                 *(int *)(pMVar24 + 0x1c0) +
                 *(int *)(Globals::layout + 0x28) + *(int *)(pMVar24 + 0x19c),
                 (int)(local_230 + *(int *)(pMVar24 + 0x164)),false);
      AbyssEngine::String::~String((String *)&local_218);
      pPVar10 = Globals::Canvas;
      local_234 = Globals::font;
      AbyssEngine::String::String((String *)&local_218,"1440x1080",false);
      iVar35 = *(int *)(pMVar24 + 0x19c);
      iVar31 = *(int *)(pMVar24 + 0x1c0);
      iVar28 = *(int *)(Globals::layout + 0x28);
      iVar26 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar24 + 0xec) + 4) + 0x14));
      pMVar22 = Globals::font;
      pPVar5 = Globals::Canvas;
      AbyssEngine::String::String(aSStack_b4,"1440x1080",false);
      iVar25 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar22,aSStack_b4);
      pMVar22 = local_22c;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)local_234,(String *)&local_218,
                 (iVar28 + iVar35 + iVar31 + iVar26 / 2) - iVar25 / 2,
                 (int)(local_230 + *(int *)(local_22c + 0x164)),false);
      AbyssEngine::String::~String(aSStack_b4);
      AbyssEngine::String::~String((String *)&local_218);
      pPVar10 = Globals::Canvas;
      local_234 = Globals::font;
      AbyssEngine::String::String((String *)&local_218,"2048x1536",false);
      iVar31 = *(int *)(pMVar22 + 0x19c);
      iVar35 = *(int *)(pMVar22 + 0x1c0);
      iVar28 = *(int *)(Globals::layout + 0x28);
      iVar26 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar22 + 0xec) + 4) + 0x14));
      pMVar22 = Globals::font;
      pPVar5 = Globals::Canvas;
      AbyssEngine::String::String(aSStack_b4,"2048x1536",false);
      iVar25 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar22,aSStack_b4);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)local_234,(String *)&local_218,
                 (iVar28 + iVar31 + iVar35 + iVar26) - iVar25,
                 (int)(local_230 + *(int *)(local_22c + 0x164)),false);
      AbyssEngine::String::~String(aSStack_b4);
      AbyssEngine::String::~String((String *)&local_218);
      pMVar19 = local_22c;
    }
    piVar13 = *(int **)(pMVar19 + 0xec);
    if (1 < *piVar13 - 1U) {
      uVar9 = 1;
      do {
        TouchSlider::draw(*(TouchSlider **)(piVar13[1] + uVar9 * 4));
        piVar13 = *(int **)(pMVar19 + 0xec);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *piVar13 - 1U);
    }
    TouchButton::draw(*(TouchButton **)(pMVar19 + 0xd4));
    TouchButton::draw(*(TouchButton **)(pMVar19 + 0xd8));
    TouchButton::draw(*(TouchButton **)(pMVar19 + 0xdc));
    pMVar15 = extraout_r1_10;
    break;
  case (MenuTouchWindow *)0x4:
    Layout::drawBG(Globals::layout);
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x2b);
    AbyssEngine::String::String(aSStack_204,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_204,0);
    AbyssEngine::String::~String(aSStack_204);
    pMVar22 = local_22c;
    ScrollTouchWindow::draw(*(ScrollTouchWindow **)(local_22c + 0xf0));
    Layout::drawEmptyFooter(Globals::layout,true);
    puVar20 = *(uint **)(pMVar22 + 0xc0);
    pMVar15 = extraout_r1_00;
    if (*puVar20 != 0) {
      uVar9 = 0;
      do {
        pTVar14 = *(TouchButton **)(puVar20[1] + uVar9 * 4);
        uVar23 = *(uint *)pTVar14;
        if (((-(*(uint *)(pTVar14 + 4) - (uint)(uVar23 < 0x6a)) < (uint)(uVar23 - 0x6a < 5)) &&
            ((1 << (uVar23 - 0x6a & 0xff) & 0x19U) != 0)) ||
           (pMVar15 = (MenuTouchWindow *)(uVar23 ^ 0x16 | *(uint *)(pTVar14 + 4)),
           pMVar15 == (MenuTouchWindow *)0x0)) {
          TouchButton::draw(pTVar14);
          puVar20 = *(uint **)(local_22c + 0xc0);
          pMVar15 = extraout_r1_01;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *puVar20);
    }
    break;
  case (MenuTouchWindow *)0x7:
    Layout::drawBG(Globals::layout);
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1e9);
    AbyssEngine::String::String(aSStack_17c,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_17c,0);
    AbyssEngine::String::~String(aSStack_17c);
    pLVar27 = Globals::layout;
    iVar25 = *(int *)(Globals::layout + 0xc);
    uVar34 = *(undefined4 *)(local_22c + 0x150);
    uVar30 = *(undefined4 *)(Globals::layout + 0x1c);
    iVar28 = *(int *)(Globals::layout + 0x20);
    uVar37 = *(undefined4 *)(Globals::layout + 0x28);
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f5);
    uVar12 = AbyssEngine::String::String(aSStack_184,pSVar11,false);
    Layout::drawBox(pLVar27,0,uVar37,iVar25 + iVar28,uVar34,uVar30,uVar12);
    AbyssEngine::String::~String(aSStack_184);
    pLVar27 = Globals::layout;
    iVar31 = *(int *)(Globals::layout + 0x1c);
    uVar30 = *(undefined4 *)(local_22c + 0x150);
    uVar37 = *(undefined4 *)(local_22c + 0x160);
    uVar34 = *(undefined4 *)(Globals::layout + 0x28);
    iVar35 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_18c,"",false);
    iVar35 = iVar35 + iVar31 + iVar25 + iVar28;
    Layout::drawBox(pLVar27,5,uVar34,iVar35,uVar30,uVar37,uVar12);
    AbyssEngine::String::~String(aSStack_18c);
    pPVar10 = Globals::Canvas;
    local_230 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x22);
    pMVar22 = local_22c;
    iVar31 = *(int *)(local_22c + 0x160);
    iVar28 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_230,pSVar11,iVar28 + 10,((iVar35 + iVar31 / 2) - iVar25 / 2) + 1,
               false);
    pLVar27 = Globals::layout;
    uVar37 = *(undefined4 *)(pMVar22 + 0x150);
    iVar28 = *(int *)(pMVar22 + 0x160);
    uVar34 = *(undefined4 *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_194,"",false);
    iVar35 = iVar28 + iVar35 + iVar25 * 2;
    Layout::drawBox(pLVar27,5,uVar34,iVar35,uVar37,iVar28,uVar12);
    AbyssEngine::String::~String(aSStack_194);
    pPVar10 = Globals::Canvas;
    local_230 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x23);
    pMVar22 = local_22c;
    iVar31 = *(int *)(local_22c + 0x160);
    iVar28 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_230,pSVar11,iVar28 + 10,((iVar35 + iVar31 / 2) - iVar25 / 2) + 1,
               false);
    pLVar27 = Globals::layout;
    uVar37 = *(undefined4 *)(pMVar22 + 0x150);
    iVar28 = *(int *)(pMVar22 + 0x160);
    uVar34 = *(undefined4 *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_19c,"",false);
    local_230 = (MenuTouchWindow *)(iVar28 + iVar35 + iVar25 * 2);
    Layout::drawBox(pLVar27,5,uVar34,local_230,uVar37,iVar28,uVar12);
    AbyssEngine::String::~String(aSStack_19c);
    pPVar10 = Globals::Canvas;
    local_234 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x24);
    pMVar19 = local_22c;
    iVar31 = *(int *)(local_22c + 0x160);
    iVar28 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    pMVar22 = local_230;
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_234,pSVar11,iVar28 + 10,
               (int)(local_230 + (iVar31 / 2 - iVar25 / 2) + 1),false);
    pLVar27 = Globals::layout;
    uVar37 = *(undefined4 *)(pMVar19 + 0x150);
    iVar31 = *(int *)(pMVar19 + 0x160);
    uVar30 = *(undefined4 *)(Globals::layout + 0x1c);
    uVar34 = *(undefined4 *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x2c);
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f6);
    uVar12 = AbyssEngine::String::String(aSStack_1a4,pSVar11,false);
    Layout::drawBox(pLVar27,0,uVar34,pMVar22 + iVar25 * 2 + iVar31,uVar37,uVar30,uVar12);
    AbyssEngine::String::~String(aSStack_1a4);
    pLVar27 = Globals::layout;
    iVar35 = *(int *)(Globals::layout + 0x1c);
    uVar30 = *(undefined4 *)(local_22c + 0x150);
    uVar37 = *(undefined4 *)(local_22c + 0x164);
    uVar34 = *(undefined4 *)(Globals::layout + 0x28);
    iVar28 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_1ac,"",false);
    pMVar15 = pMVar22 + iVar25 * 2 + iVar31 + iVar28 + iVar35;
    Layout::drawBox(pLVar27,5,uVar34,pMVar15,uVar30,uVar37,uVar12);
    AbyssEngine::String::~String(aSStack_1ac);
    pPVar10 = Globals::Canvas;
    local_230 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f7);
    pMVar29 = local_22c;
    local_234 = (MenuTouchWindow *)&Globals::layout;
    iVar28 = *(int *)(local_22c + 0x160);
    iVar31 = *(int *)(Globals::layout + 0x28);
    iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_230,pSVar11,iVar31 + 10,
               (int)(pMVar15 + (iVar28 / 2 - iVar25 / 2) + 1),false);
    pMVar22 = Globals::font;
    pPVar10 = Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x201);
    pMVar19 = local_234;
    local_230 = pMVar15 + -iVar26;
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)pMVar22,pSVar11,
               *(int *)(*(int *)local_234 + 0x28) + *(int *)(pMVar29 + 0x1c0),
               (int)(local_230 + *(int *)(pMVar29 + 0x164)),false);
    pMVar22 = Globals::font;
    pPVar10 = Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x202);
    iVar25 = *(int *)(*(int *)pMVar19 + 0x28);
    iVar35 = *(int *)(pMVar29 + 0x1c0);
    iVar28 = TouchSlider::getWidth(*(TouchSlider **)(*(int *)(*(int *)(pMVar29 + 0xec) + 4) + 0x10))
    ;
    pMVar19 = Globals::font;
    pPVar5 = Globals::Canvas;
    pSVar33 = (String *)GameText::getText(Globals::gameText,0x202);
    iVar31 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar19,pSVar33);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)pMVar22,pSVar11,(iVar25 + iVar35 + iVar28 / 2) - iVar31 / 2,
               (int)(local_230 + *(int *)(pMVar29 + 0x164)),false);
    pMVar22 = Globals::font;
    pPVar10 = Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x203);
    pMVar24 = local_234;
    iVar25 = *(int *)(*(int *)local_234 + 0x28);
    iVar35 = *(int *)(pMVar29 + 0x1c0);
    iVar28 = TouchSlider::getWidth(*(TouchSlider **)(*(int *)(*(int *)(pMVar29 + 0xec) + 4) + 0x10))
    ;
    pMVar19 = Globals::font;
    pPVar5 = Globals::Canvas;
    pSVar33 = (String *)GameText::getText(Globals::gameText,0x203);
    iVar31 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar19,pSVar33);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)pMVar22,pSVar11,(iVar25 + iVar35 + iVar28) - iVar31,
               (int)(local_230 + *(int *)(pMVar29 + 0x164)),false);
    pLVar27 = *(Layout **)pMVar24;
    if (pLVar27[0x284] != (Layout)0x0) {
      uVar37 = *(undefined4 *)(pLVar27 + 0x28);
      iVar28 = *(int *)(pLVar27 + 0x2c);
      uVar34 = *(undefined4 *)(pMVar29 + 0x150);
      iVar25 = *(int *)(pMVar29 + 0x164);
      uVar12 = AbyssEngine::String::String(aSStack_1b4,"",false);
      pMVar15 = pMVar15 + iVar28 + iVar25;
      Layout::drawBox(pLVar27,5,uVar37,pMVar15,uVar34,iVar25,uVar12);
      AbyssEngine::String::~String(aSStack_1b4);
      pPVar10 = Globals::Canvas;
      local_230 = Globals::font;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f8);
      local_234 = (MenuTouchWindow *)&Globals::layout;
      iVar31 = *(int *)(pMVar29 + 0x160);
      iVar28 = *(int *)(Globals::layout + 0x28);
      iVar25 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)local_230,pSVar11,iVar28 + 10,
                 (int)(pMVar15 + (iVar31 / 2 - iVar25 / 2) + 1),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1fb);
      pMVar19 = local_234;
      local_230 = pMVar15 + -iVar26;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,
                 *(int *)(*(int *)local_234 + 0x28) + *(int *)(pMVar29 + 0x1c0),
                 (int)(local_230 + *(int *)(pMVar29 + 0x164)),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1fc);
      iVar26 = *(int *)(*(int *)pMVar19 + 0x28);
      iVar31 = *(int *)(pMVar29 + 0x1c0);
      iVar25 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar29 + 0xec) + 4) + 0x14));
      pMVar19 = Globals::font;
      pPVar5 = Globals::Canvas;
      pSVar33 = (String *)GameText::getText(Globals::gameText,0x1fc);
      iVar28 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar19,pSVar33);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,(iVar26 + iVar31 + iVar25 / 2) - iVar28 / 2,
                 (int)(local_230 + *(int *)(pMVar29 + 0x164)),false);
      pMVar22 = Globals::font;
      pPVar10 = Globals::Canvas;
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1fd);
      local_234 = *(MenuTouchWindow **)(*(int *)local_234 + 0x28);
      iVar28 = *(int *)(pMVar29 + 0x1c0);
      iVar26 = TouchSlider::getWidth
                         (*(TouchSlider **)(*(int *)(*(int *)(pMVar29 + 0xec) + 4) + 0x14));
      pMVar19 = Globals::font;
      pPVar5 = Globals::Canvas;
      pSVar33 = (String *)GameText::getText(Globals::gameText,0x1fd);
      iVar25 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar19,pSVar33);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar11,(int)(local_234 + ((iVar26 + iVar28) - iVar25)),
                 (int)(local_230 + *(int *)(pMVar29 + 0x164)),false);
    }
    piVar13 = *(int **)(pMVar29 + 0xec);
    if (1 < *piVar13 - 1U) {
      ppuVar21 = (undefined **)0x1;
      ppuVar16 = &PTR_layout_002658c8;
      do {
        if (ppuVar21 == (undefined **)0x5) {
          ppuVar16 = (undefined **)(uint)(byte)Globals::layout[0x284];
        }
        if (ppuVar21 != (undefined **)0x5 || ppuVar16 != (undefined **)0x0) {
          TouchSlider::draw(*(TouchSlider **)(piVar13[1] + (int)ppuVar21 * 4));
          piVar13 = *(int **)(local_22c + 0xec);
        }
        ppuVar21 = (undefined **)((int)ppuVar21 + 1);
        ppuVar16 = (undefined **)(*piVar13 + -1);
      } while (ppuVar21 < ppuVar16);
    }
    pMVar22 = local_22c;
    TouchButton::draw(*(TouchButton **)(local_22c + 0xd4));
    TouchButton::draw(*(TouchButton **)(pMVar22 + 0xd8));
    TouchButton::draw(*(TouchButton **)(pMVar22 + 0xdc));
    pMVar15 = extraout_r1_02;
    break;
  case (MenuTouchWindow *)0x8:
    local_234 = pMVar24;
    local_230 = pMVar29;
    Layout::drawBG(Globals::layout);
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1f2);
    AbyssEngine::String::String(aSStack_1bc,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_1bc,0);
    AbyssEngine::String::~String(aSStack_1bc);
    pLVar27 = Globals::layout;
    uVar37 = *(undefined4 *)(local_22c + 0x150);
    uVar34 = *(undefined4 *)(local_22c + 0x154);
    iVar26 = *(int *)(Globals::layout + 0xc);
    iVar25 = *(int *)(Globals::layout + 0x20);
    uVar30 = *(undefined4 *)(Globals::layout + 0x28);
    uVar12 = AbyssEngine::String::String(aSStack_1c4,"",false);
    Layout::drawBox(pLVar27,5,uVar30,iVar25 + iVar26,uVar37,uVar34,uVar12);
    AbyssEngine::String::~String(aSStack_1c4);
    pMVar22 = local_22c;
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pMVar24 = local_22c;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(pMVar22 + 0x110),
               *(int *)(Globals::layout + 0x28) + *(int *)(pMVar22 + 0x158) / 2,
               *(int *)(Globals::layout + 0xc) + (int)local_230 * 2 +
               *(int *)(Globals::layout + 0x20),'\x11','\x14');
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(pMVar24 + 0x10c),
               (Globals::w - *(int *)(Globals::layout + 0x28)) - *(int *)(pMVar24 + 0x158) / 2,
               (int)(local_230 + *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc))
               ,'\x11','\x14');
    local_230 = (MenuTouchWindow *)Globals::options;
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pMVar22 = Globals::font;
    pPVar10 = Globals::Canvas;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1ea);
    pMVar19 = Globals::font;
    pPVar5 = Globals::Canvas;
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(pMVar24 + 0x158);
    pSVar33 = (String *)GameText::getText(Globals::gameText,0x1ea);
    iVar28 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar19,pSVar33);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)pMVar22,pSVar11,(iVar26 + iVar25 / 2) - iVar28 / 2,
               *(int *)(Globals::layout + 0x20) + (*(int *)(Globals::layout + 0xc) - (int)local_234)
               + *(int *)(pMVar24 + 0x154),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pPVar10 = Globals::Canvas;
    local_230 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x1eb);
    iVar26 = Globals::w;
    pMVar22 = Globals::font;
    pPVar5 = Globals::Canvas;
    iVar25 = *(int *)(Globals::layout + 0x28);
    iVar31 = *(int *)(pMVar24 + 0x158);
    pSVar33 = (String *)GameText::getText(Globals::gameText,0x1eb);
    iVar28 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar5,(uint)pMVar22,pSVar33);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_230,pSVar11,((iVar26 - iVar25) - iVar31 / 2) - iVar28 / 2,
               *(int *)(Globals::layout + 0x20) + (*(int *)(Globals::layout + 0xc) - (int)local_234)
               + *(int *)(pMVar24 + 0x154),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pLVar27 = Globals::layout;
    local_230 = *(MenuTouchWindow **)(pMVar24 + 0x154);
    uVar37 = *(undefined4 *)(pMVar24 + 0x158);
    uVar34 = *(undefined4 *)(pMVar24 + 0x15c);
    iVar25 = *(int *)(Globals::layout + 0xc);
    iVar28 = *(int *)(Globals::layout + 0x20);
    uVar30 = *(undefined4 *)(Globals::layout + 0x28);
    iVar26 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_1cc,"",false);
    Layout::drawBox(pLVar27,5,uVar30,local_230 + iVar26 + iVar28 + iVar25,uVar37,uVar34,uVar12);
    AbyssEngine::String::~String(aSStack_1cc);
    pLVar27 = Globals::layout;
    local_230 = *(MenuTouchWindow **)(local_22c + 0x154);
    iVar26 = *(int *)(local_22c + 0x158);
    uVar34 = *(undefined4 *)(local_22c + 0x15c);
    iVar28 = *(int *)(Globals::layout + 0xc);
    iVar31 = *(int *)(Globals::layout + 0x20);
    iVar35 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_1d4,"",false);
    Layout::drawBox(pLVar27,5,iVar35 + iVar26 + iVar25 + 1,local_230 + iVar28 + iVar25 + iVar31,
                    iVar26,uVar34,uVar12);
    AbyssEngine::String::~String(aSStack_1d4);
    pLVar27 = Globals::layout;
    local_230 = *(MenuTouchWindow **)(local_22c + 0x154);
    iVar25 = *(int *)(local_22c + 0x158);
    iVar26 = *(int *)(local_22c + 0x15c);
    iVar35 = *(int *)(Globals::layout + 0xc);
    iVar32 = *(int *)(Globals::layout + 0x20);
    iVar31 = *(int *)(Globals::layout + 0x28);
    iVar28 = *(int *)(Globals::layout + 0x2c);
    uVar12 = AbyssEngine::String::String(aSStack_1dc,"",false);
    Layout::drawBox(pLVar27,5,iVar31 + iVar25 + iVar28 + 1,
                    local_230 + iVar28 * 2 + iVar26 + iVar32 + iVar35,iVar25,iVar26,uVar12);
    AbyssEngine::String::~String(aSStack_1dc);
    pPVar10 = Globals::Canvas;
    local_230 = (MenuTouchWindow *)&Globals::gameText;
    local_234 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,500);
    iVar28 = *(int *)(local_22c + 0x154);
    iVar31 = *(int *)(local_22c + 0x15c);
    iVar25 = *(int *)(Globals::layout + 0x28);
    iVar32 = *(int *)(Globals::layout + 0xc);
    iVar36 = *(int *)(Globals::layout + 0x20);
    iVar35 = *(int *)(Globals::layout + 0x2c);
    iVar26 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,(uint)Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_234,pSVar11,iVar25 + 10,
               ((iVar32 + iVar36 + iVar28 + iVar35 + iVar31 / 2) - iVar26 / 2) + 1,false);
    pMVar22 = Globals::font;
    pPVar10 = Globals::Canvas;
    pSVar11 = (String *)GameText::getText(*(GameText **)local_230,499);
    AbyssEngine::String::String(aSStack_10c," [",false);
    AbyssEngine::operator+(aAStack_104,pSVar11,aSStack_10c);
    pMVar19 = local_22c;
    TouchSlider::getValue((TouchSlider *)**(undefined4 **)(*(int *)(local_22c + 0xec) + 4));
    local_11c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1_06,local_11c));
    AbyssEngine::String::String(aSStack_114,(String *)local_11c,false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_b4,aAStack_104,aSStack_114);
    AbyssEngine::String::String(aSStack_124,"]",false);
    AbyssEngine::operator+((AbyssEngine *)&local_218,aSStack_b4,aSStack_124);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)pMVar22,(String *)&local_218,
               *(int *)(Globals::layout + 0x2c) +
               *(int *)(Globals::layout + 0x28) + *(int *)(pMVar19 + 0x158) + 10,
               *(int *)(pMVar19 + 0x154) +
               *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x2c) * 2 +
               *(int *)(Globals::layout + 0x20) + *(int *)(pMVar19 + 0x15c) + 10,false);
    AbyssEngine::String::~String((String *)&local_218);
    AbyssEngine::String::~String(aSStack_124);
    AbyssEngine::String::~String(aSStack_b4);
    AbyssEngine::String::~String(aSStack_114);
    AbyssEngine::String::~String((String *)local_11c);
    AbyssEngine::String::~String((String *)aAStack_104);
    AbyssEngine::String::~String(aSStack_10c);
    TouchSlider::draw((TouchSlider *)**(undefined4 **)(*(int *)(pMVar19 + 0xec) + 4));
    TouchButton::draw(*(TouchButton **)(pMVar19 + 0xcc));
    TouchButton::draw(*(TouchButton **)(pMVar19 + 0xd0));
    pMVar15 = extraout_r1_07;
    break;
  case (MenuTouchWindow *)0x9:
    MissionsWindow::draw(*(MissionsWindow **)(local_22c + 0xfc));
    pMVar15 = extraout_r1_03;
    break;
  case (MenuTouchWindow *)0xb:
    if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
      iVar26 = AbyssEngine::PaintCanvas::GetImage2DWidth
                         (Globals::Canvas,*(uint *)(local_22c + 0x54));
      iVar25 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(pMVar6 + 0x50));
      pMVar22 = pMVar6 + 0x5c;
      uVar12 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)pMVar22);
      uVar8 = *(ushort *)(pMVar6 + 0x40);
      iVar28 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(pMVar6 + 0x1c));
      local_234 = (MenuTouchWindow *)(iVar28 - (iVar28 >> 0x1f));
      local_230 = (MenuTouchWindow *)((uint)uVar8 - iVar26 / 2);
      uVar1 = *(ushort *)(pMVar6 + 0x60);
      iVar28 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(pMVar6 + 0x74));
      uVar2 = *(ushort *)(pMVar6 + 0x42);
      iVar31 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(pMVar6 + 0x1c));
      uVar8 = *(ushort *)(pMVar6 + 0x62);
      iVar35 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(pMVar6 + 0x74));
      iVar32 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(pMVar6 + 0x54));
      pMVar19 = local_22c;
      fVar40 = (float)VectorSignedToFloat(iVar32 + 100,(byte)(in_fpscr >> 0x16) & 3);
      fVar39 = 91.40625;
      if (Globals::iPadHD == '\0') {
        pfVar17 = (float *)&DAT_0014d56c;
        if (Globals::iPadLarge != '\0') {
          pfVar17 = (float *)&DAT_0014d570;
        }
        fVar39 = *pfVar17;
      }
      iVar32 = 0;
      local_234 = local_230 + ((int)local_234 >> 1);
      local_230 = (MenuTouchWindow *)(((uint)uVar1 - iVar26 / 2) + iVar28 / 2);
      do {
        ppMVar3 = &local_230;
        if (iVar32 == 0) {
          ppMVar3 = &local_234;
        }
        pMVar24 = *ppMVar3;
        fVar41 = 91.40625;
        if (Globals::iPadHD == '\0') {
          pfVar17 = (float *)&DAT_0014d56c;
          if (Globals::iPadLarge != '\0') {
            pfVar17 = (float *)&DAT_0014d570;
          }
          fVar41 = *pfVar17;
        }
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(local_22c + 0x54),(int)pMVar24,(int)(100.0 - fVar41));
        iVar28 = 5;
        iVar26 = (int)(fVar40 - fVar39);
        do {
          AbyssEngine::PaintCanvas::DrawImage2D
                    (Globals::Canvas,*(uint *)(pMVar19 + 0x50),(int)pMVar24,iVar26);
          pMVar29 = local_22c;
          iVar26 = iVar26 + iVar25;
          iVar28 = iVar28 + -1;
        } while (iVar28 != 0);
        iVar32 = iVar32 + 1;
      } while (iVar32 != 2);
      fVar39 = (float)VectorSignedToFloat((uint)uVar2 + iVar31 / 2,(byte)(in_fpscr >> 0x16) & 3);
      pMVar24 = local_22c + 0x58;
      pMVar19 = pMVar24;
      if (*(int *)(local_22c + 8) == 0) {
        pMVar19 = pMVar22;
      }
      pMVar15 = local_234 + 3;
      if (Globals::iPadHD == '\0') {
        pfVar17 = (float *)&DAT_0014ff98;
        if (Globals::iPadLarge != '\0') {
          pfVar17 = (float *)&DAT_0014ff9c;
        }
        fVar40 = *pfVar17;
      }
      else {
        fVar40 = 239.0625;
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)pMVar19,(int)pMVar15,(int)(fVar39 - fVar40));
      fVar40 = (float)VectorSignedToFloat((uint)uVar8 + iVar35 / 2,(byte)(in_fpscr >> 0x16) & 3);
      pMVar19 = pMVar24;
      if (*(int *)(pMVar29 + 0xc) == 0) {
        pMVar19 = pMVar22;
      }
      pMVar29 = local_230 + 3;
      if (Globals::iPadHD == '\0') {
        pfVar17 = (float *)&DAT_0014ffac;
        if (Globals::iPadLarge != '\0') {
          pfVar17 = (float *)&DAT_0014ffb0;
        }
        fVar41 = *pfVar17;
      }
      else {
        fVar41 = 225.0;
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)pMVar19,(int)pMVar29,(int)(fVar40 - fVar41));
      pMVar19 = pMVar24;
      if (*(int *)(local_22c + 8) == 0) {
        pMVar19 = pMVar22;
      }
      if (Globals::iPadHD == '\0') {
        pfVar17 = (float *)&DAT_0014ff98;
        if (Globals::iPadLarge != '\0') {
          pfVar17 = (float *)&DAT_0014ff9c;
        }
        fVar41 = *pfVar17;
      }
      else {
        fVar41 = 239.0625;
      }
      fVar42 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)pMVar19,(int)pMVar15,(int)((fVar39 + fVar41) - fVar42),
                 '\x02');
      if (*(int *)(local_22c + 0xc) == 0) {
        pMVar24 = pMVar22;
      }
      if (Globals::iPadHD == '\0') {
        pfVar17 = (float *)&DAT_0014ffac;
        if (Globals::iPadLarge != '\0') {
          pfVar17 = (float *)&DAT_0014ffb0;
        }
        fVar39 = *pfVar17;
      }
      else {
        fVar39 = 225.0;
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)pMVar24,(int)pMVar29,(int)((fVar40 + fVar39) - fVar42),
                 '\x02');
      pMVar22 = local_22c;
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(local_22c + 0x1c),*(uint *)(local_22c + 0x40) & 0xffff,
                 *(uint *)(local_22c + 0x40) >> 0x10);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x28),*(uint *)(pMVar22 + 0x3c) & 0xffff,
                 *(uint *)(pMVar22 + 0x3c) >> 0x10,'\x11','D');
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x24),(uint)*(ushort *)(pMVar22 + 0x2e),
                 (uint)*(ushort *)(pMVar22 + 0x30));
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x20),(uint)*(ushort *)(pMVar22 + 0x34),
                 (uint)*(ushort *)(pMVar22 + 0x32));
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x74),*(uint *)(pMVar22 + 0x60) & 0xffff,
                 *(uint *)(pMVar22 + 0x60) >> 0x10);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x80),*(uint *)(pMVar22 + 100) & 0xffff,
                 *(uint *)(pMVar22 + 100) >> 0x10,'\x11','D');
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x84),*(uint *)(pMVar22 + 0x68) & 0xffff,
                 *(uint *)(pMVar22 + 0x68) >> 0x10);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x88),*(uint *)(pMVar22 + 0x6c) & 0xffff,
                 *(uint *)(pMVar22 + 0x6c) >> 0x10);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pMVar22 + 0x8c),*(uint *)(pMVar22 + 0x70) & 0xffff,
                 *(uint *)(pMVar22 + 0x70) >> 0x10);
      iVar26 = Globals::w;
      pLVar27 = Globals::layout;
      uVar34 = *(undefined4 *)(Globals::layout + 0x300);
      iVar25 = *(int *)(Globals::layout + 0x304);
      uVar37 = *(undefined4 *)(Globals::layout + 0x308);
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x1ee);
      uVar12 = AbyssEngine::String::String(aSStack_c4,pSVar11,false);
      Layout::drawBox(pLVar27,7,(iVar26 >> 1) - iVar25 / 2,uVar34,iVar25,uVar37,uVar12);
      AbyssEngine::String::~String(aSStack_c4);
      ScrollTouchWindow::draw(*(ScrollTouchWindow **)(pMVar22 + 0x10));
      TouchButton::draw(*(TouchButton **)(pMVar22 + 0x14));
      TouchButton::draw(*(TouchButton **)(pMVar22 + 0x18));
      pMVar15 = extraout_r1_11;
    }
    break;
  case (MenuTouchWindow *)0xc:
    if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(local_22c + 0x120),iVar25,0x50,'\x11','\x14');
    }
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x205);
    AbyssEngine::String::String(aSStack_220,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_220,0);
    AbyssEngine::String::~String(aSStack_220);
    piVar13 = *(int **)pMVar19;
    pMVar15 = (MenuTouchWindow *)0x0;
    if (*piVar13 != 0) {
      pMVar22 = (MenuTouchWindow *)0x0;
      do {
        TouchButton::draw(*(TouchButton **)(piVar13[1] + (int)pMVar22 * 4));
        piVar13 = *(int **)pMVar19;
        pMVar22 = pMVar22 + 1;
        pMVar15 = (MenuTouchWindow *)*piVar13;
      } while (pMVar22 < pMVar15);
    }
    break;
  case (MenuTouchWindow *)0xd:
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(local_22c + 0x120),
               Globals::w - *(int *)(Globals::layout + 0x2c),*(int *)(Globals::layout + 0x2c),'\x11'
               ,'\x12');
    if (((pMVar6[0x189] == (MenuTouchWindow)0x0) || (pMVar6[0x1c4] == (MenuTouchWindow)0x0)) ||
       (pMVar6[0x188] == (MenuTouchWindow)0x0)) {
      iVar26 = *(int *)(pMVar6 + 0x184);
      if (iVar26 < 0) {
        uVar43 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
        pMVar15 = (MenuTouchWindow *)((ulonglong)uVar43 >> 0x20);
        if (*(char *)((int)uVar43 + 4) == '\0') {
          uVar43 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
          pMVar15 = (MenuTouchWindow *)((ulonglong)uVar43 >> 0x20);
          if (*(char *)((int)uVar43 + 0xc) == '\0') {
            Layout::drawEmptyFooter(Globals::layout,true);
            pMVar15 = extraout_r1_08;
          }
        }
      }
      else {
        pMVar15 = (MenuTouchWindow *)0x0;
        if (pMVar6[0x188] != (MenuTouchWindow)0x0) {
          iVar26 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
          this_00 = Globals::gameText;
          this_01 = (Ship *)Status::getShip(Globals::status);
          iVar25 = Ship::getIndex(this_01);
          pSVar11 = (String *)GameText::getText(this_00,iVar25 + 0x391);
          AbyssEngine::String::operator=((String *)(iVar26 + 0x18),pSVar11);
          iVar25 = Status::inAlienOrbit(Globals::status);
          if (iVar25 == 1) {
            AbyssEngine::String::String((String *)&local_218,"Void mothership",false);
            AbyssEngine::String::operator=((String *)(iVar26 + 0x20),(String *)&local_218);
            AbyssEngine::String::~String((String *)&local_218);
            AbyssEngine::String::String((String *)&local_218,"Void",false);
            AbyssEngine::String::operator=((String *)(iVar26 + 0x28),(String *)&local_218);
          }
          else {
            Status::getStation(Globals::status);
            Station::getName();
            AbyssEngine::String::operator=((String *)(iVar26 + 0x20),(String *)&local_218);
            AbyssEngine::String::~String((String *)&local_218);
            Status::getSystem(Globals::status);
            SolarSystem::getName();
            AbyssEngine::String::operator=((String *)(iVar26 + 0x28),(String *)&local_218);
          }
          AbyssEngine::String::~String((String *)&local_218);
          *(undefined1 *)(iVar26 + 4) = 1;
          local_22c[0x188] = (MenuTouchWindow)0x0;
          iVar26 = *(int *)(local_22c + 0x184);
          pMVar15 = local_22c;
        }
        if ((iVar26 == 1) && (local_22c[0x1c4] == (MenuTouchWindow)0x0)) {
          uVar43 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
          pMVar15 = (MenuTouchWindow *)((ulonglong)uVar43 >> 0x20);
          if (*(char *)((int)uVar43 + 4) == '\0') {
            uVar43 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
            pMVar15 = (MenuTouchWindow *)((ulonglong)uVar43 >> 0x20);
            if (*(char *)((int)uVar43 + 0xc) == '\0') {
              iVar26 = AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
              pMVar15 = (MenuTouchWindow *)0x1;
              *(undefined1 *)(iVar26 + 0xef) = 1;
              local_22c[0x1c4] = (MenuTouchWindow)0x1;
              local_22c[0x188] = (MenuTouchWindow)0x1;
            }
          }
        }
      }
    }
    else {
      iVar26 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
      *(undefined1 *)(iVar26 + 0xc) = 1;
      AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
      AbyssEngine::Engine::SaveImageToPhotosAlbum();
      pMVar6[0x1c4] = (MenuTouchWindow)0x0;
      *(undefined2 *)(pMVar6 + 0x188) = 0;
      pMVar15 = extraout_r1_04;
    }
    *(int *)(pMVar6 + 0x184) = *(int *)(pMVar6 + 0x184) + -1;
    break;
  case (MenuTouchWindow *)0xe:
    if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(local_22c + 0x120),iVar25,0x50,'\x11','\x14');
    }
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0);
    AbyssEngine::String::String(aSStack_228,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_228,0);
    AbyssEngine::String::~String(aSStack_228);
    piVar13 = *(int **)pMVar22;
    pMVar15 = (MenuTouchWindow *)0x0;
    if (*piVar13 != 0) {
      pMVar19 = (MenuTouchWindow *)0x0;
      local_234 = (MenuTouchWindow *)&Globals::Canvas;
      do {
        bVar4 = false;
        bVar38 = false;
        puVar20 = *(uint **)(piVar13[1] + (int)pMVar19 * 4);
        uVar23 = *puVar20;
        uVar9 = puVar20[1];
        if (uVar23 == 0x22 && uVar9 == 0) {
          sVar7 = GameText::getLanguage();
          bVar38 = false;
          puVar20 = *(uint **)(*(int *)(*(int *)pMVar22 + 4) + (int)pMVar19 * 4);
          uVar23 = *puVar20;
          uVar9 = puVar20[1];
          if (sVar7 != 9) {
            bVar38 = true;
          }
        }
        uVar18 = uVar23 - 0x21;
        iVar26 = uVar9 - (uVar23 < 0x21);
        pPVar10 = (PaintCanvas *)(-(uint)(uVar18 >= 5) - iVar26);
        if (((uint)-iVar26 < (uint)(uVar18 < 5)) &&
           (pPVar10 = (PaintCanvas *)(1 << (uVar18 & 0xff)), ((uint)pPVar10 & 0x19) != 0)) {
          uVar8 = GameText::getLanguage();
          bVar4 = false;
          pPVar10 = (PaintCanvas *)(uint)uVar8;
          if (pPVar10 == (PaintCanvas *)0x9) {
            bVar4 = true;
          }
        }
        if (bVar38) {
          *(undefined1 *)(*(int *)local_234 + 0x1c) = 0;
        }
        else {
          if (bVar4) {
            pPVar10 = Globals::Canvas;
          }
          if (bVar4) {
            pPVar10[0x1c] = (PaintCanvas)0x1;
          }
        }
        TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)pMVar22 + 4) + (int)pMVar19 * 4));
        if (bVar38) {
          Globals::Canvas[0x1c] = (PaintCanvas)0x1;
        }
        else if (bVar4) {
          Globals::Canvas[0x1c] = (PaintCanvas)0x0;
        }
        piVar13 = *(int **)pMVar22;
        pMVar19 = pMVar19 + 1;
        pMVar15 = (MenuTouchWindow *)*piVar13;
      } while (pMVar19 < pMVar15);
    }
    break;
  case (MenuTouchWindow *)0xf:
    Layout::drawBG(Globals::layout);
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x61);
    AbyssEngine::String::String(aSStack_7c,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_7c,0);
    AbyssEngine::String::~String(aSStack_7c);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    Layout::drawEmptyFooter(Globals::layout,true);
    iVar26 = Globals::h;
    pLVar27 = Globals::layout;
    uVar34 = *(undefined4 *)(local_22c + 0x200);
    iVar25 = *(int *)(Globals::layout + 0xc);
    iVar35 = *(int *)(Globals::layout + 0x10);
    iVar28 = *(int *)(Globals::layout + 0x20);
    iVar31 = *(int *)(Globals::layout + 0x24);
    local_230 = *(MenuTouchWindow **)(Globals::layout + 0x28);
    uVar12 = AbyssEngine::String::String(aSStack_84,"",false);
    local_234 = (MenuTouchWindow *)((((iVar26 - iVar25) - iVar35) - iVar28) - iVar31);
    Layout::drawBox(pLVar27,5,local_230,iVar28 + iVar25,uVar34,local_234,uVar12);
    AbyssEngine::String::~String(aSStack_84);
    pLVar27 = Globals::layout;
    iVar35 = 0;
    local_230 = *(MenuTouchWindow **)(local_22c + 500);
    iVar28 = *(int *)(local_22c + 0x200);
    uVar34 = *(undefined4 *)(local_22c + 0x204);
    iVar26 = *(int *)(Globals::layout + 0xc);
    iVar31 = *(int *)(Globals::layout + 0x20);
    iVar25 = *(int *)(Globals::layout + 0x28);
    uVar12 = AbyssEngine::String::String(aSStack_8c,"",false);
    Layout::drawBox(pLVar27,5,local_230 + iVar28 + iVar25,iVar31 + iVar26,uVar34,local_234,uVar12);
    AbyssEngine::String::~String(aSStack_8c);
    AbyssEngine::PaintCanvas::EnableClip
              (Globals::Canvas,0,*(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc),
               Globals::w,
               ((Globals::h - (*(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc)))
               - *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0x24));
    pMVar22 = local_22c;
    uVar12 = AbyssEngine::PaintCanvas::GetImage2DHeight
                       (Globals::Canvas,**(uint **)(local_22c + 0x134));
    *(undefined4 *)(pMVar22 + 0x1e4) = uVar12;
    iVar26 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
    local_230 = (MenuTouchWindow *)&Globals::iPad;
    local_234 = (MenuTouchWindow *)&Globals::iPadAssetsWithLowerRes;
    do {
      if (iVar35 == *(int *)(pMVar22 + 0x1e0)) {
        if (*local_230 == (MenuTouchWindow)0x0 && *local_234 == (MenuTouchWindow)0x0) {
          AbyssEngine::PaintCanvas::DrawImage2D
                    (Globals::Canvas,*(uint *)(pMVar22 + 0x13c),
                     *(int *)(Globals::layout + 0x2c) +
                     *(int *)(pMVar22 + 0x1ec) + *(int *)(pMVar22 + 0x1e8),
                     (*(int *)(pMVar22 + 0x208) + *(int *)(pMVar22 + 0x1e4)) * iVar35 +
                     *(int *)(pMVar22 + 0x194) + *(int *)(pMVar22 + 0x1f0));
        }
        iVar25 = *(int *)(pMVar22 + 0xf8);
        bVar38 = true;
      }
      else {
        iVar25 = *(int *)(pMVar22 + 0xf8);
        bVar38 = false;
      }
      TouchButton::setAlwaysPressed(*(TouchButton **)(*(int *)(iVar25 + 4) + iVar35 * 4),bVar38);
      pMVar19 = local_22c;
      TouchButton::setYPosition
                (*(TouchButton **)(*(int *)(*(int *)(pMVar22 + 0xf8) + 4) + iVar35 * 4),
                 (*(int *)(Globals::layout + 0x2c) + *(int *)(pMVar22 + 0x1e4)) * iVar35 +
                 *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
                 *(int *)(pMVar22 + 0x194));
      TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(pMVar19 + 0xf8) + 4) + iVar35 * 4));
      pPVar10 = Globals::Canvas;
      if (((((iVar35 == 0) && (Globals::options[0x35] != '\0')) ||
           ((iVar35 == 1 && ((Globals::options._54_2_ & 0xff) != 0)))) ||
          ((iVar35 == 2 && (0xff < (ushort)Globals::options._54_2_)))) ||
         ((iVar35 == 3 && ((Globals::options._56_2_ & 0xff) != 0)))) {
LAB_0014db4c:
        uVar9 = *(uint *)(pMVar19 + 0x144);
        TouchButton::getPosition();
        fVar39 = local_98;
        fVar41 = (float)VectorSignedToFloat(*(undefined4 *)(pMVar19 + 0x1e8),
                                            (byte)(in_fpscr >> 0x16) & 3);
        TouchButton::getPosition();
        fVar40 = (float)VectorSignedToFloat(*(undefined4 *)(pMVar19 + 0x1e4),
                                            (byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::PaintCanvas::DrawImage2D
                  (pPVar10,uVar9,(int)(fVar39 + fVar41),(int)(local_a0 + fVar40),'\x11','\"');
      }
      else if (iVar35 == 4) {
        if ((Globals::options[0x35] != '\0' && 0xff < (ushort)Globals::options._54_2_) ||
           (0xff < (ushort)Globals::options._56_2_)) goto LAB_0014db4c;
        break;
      }
      iVar35 = iVar35 + 1;
      pMVar22 = pMVar19;
    } while (iVar35 != 5);
    pLVar27 = Globals::layout;
    iVar25 = *(int *)(pMVar19 + 0x1f8);
    local_230 = *(MenuTouchWindow **)(pMVar19 + 500);
    local_234 = *(MenuTouchWindow **)(pMVar19 + 0x200);
    iVar28 = *(int *)(Globals::layout + 0xc);
    iVar31 = *(int *)(pMVar19 + 0x204);
    uVar34 = *(undefined4 *)(Globals::layout + 0x1c);
    iVar32 = *(int *)(Globals::layout + 0x20);
    iVar36 = *(int *)(Globals::layout + 0x28);
    iVar35 = *(int *)(Globals::layout + 0x2c);
    pSVar11 = (String *)GameText::getText(Globals::gameText,*(int *)(pMVar19 + 0x1e0) + 0x4d);
    uVar12 = AbyssEngine::String::String(aSStack_ac,pSVar11,false);
    Layout::drawBox(pLVar27,0,local_234 + (int)(local_230 + iVar36),iVar32 + iVar28,
                    (iVar31 - iVar35) - iVar25,uVar34,uVar12);
    AbyssEngine::String::~String(aSStack_ac);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(*(int *)(pMVar19 + 0x138) + *(int *)(pMVar19 + 0x1e0) * 4),
               Globals::w - *(int *)(Globals::layout + 0x28),
               *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20),'\x11','\x12');
    pPVar10 = Globals::Canvas;
    local_230 = Globals::font;
    pSVar11 = (String *)GameText::getText(Globals::gameText,*(int *)(pMVar19 + 0x1e0) + 0x52);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar10,(uint)local_230,pSVar11,
               *(int *)(pMVar19 + 500) +
               *(int *)(Globals::layout + 0x28) + *(int *)(pMVar19 + 0x200) +
               *(int *)(Globals::layout + 0x2c),
               *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x2c) +
               *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0x1c),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    if (((*(int **)(iVar26 + 0x44) != (int *)0x0) && (**(int **)(iVar26 + 0x44) != 0)) &&
       (iVar25 = Globals::getInAppPurchaseArrayIndex
                           (Globals::globals,*(int *)(pMVar19 + 0x1e0),*(Array **)(iVar26 + 0x48)),
       pMVar22 = Globals::font, pPVar10 = Globals::Canvas, iVar25 != -1)) {
      local_230 = *(MenuTouchWindow **)(pMVar19 + 500);
      local_234 = *(MenuTouchWindow **)(pMVar19 + 0x200);
      pSVar33 = *(String **)(*(int *)(*(int *)(iVar26 + 0x44) + 4) + iVar25 * 4);
      iVar28 = *(int *)(Globals::layout + 0x28);
      iVar25 = *(int *)(Globals::layout + 0x2c);
      pSVar11 = (String *)GameText::getText(Globals::gameText,0x84);
      AbyssEngine::String::String(aSStack_b4,":",false);
      AbyssEngine::operator+((AbyssEngine *)&local_218,pSVar11,aSStack_b4);
      iVar26 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar10,(uint)pMVar22,(String *)&local_218);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar10,(uint)pMVar22,pSVar33,
                 (int)(local_234 + iVar28 + (int)local_230 + iVar26 + iVar25 * 2),
                 *(int *)(Globals::layout + 0x2c) +
                 *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                 *(int *)(Globals::layout + 0x1c) + *(int *)(Globals::layout + 4),false);
      AbyssEngine::String::~String((String *)&local_218);
      AbyssEngine::String::~String(aSStack_b4);
      pMVar19 = local_22c;
    }
    ScrollTouchWindow::draw(*(ScrollTouchWindow **)(pMVar19 + 0xf4));
    uVar9 = *(uint *)(pMVar19 + 0x1e0);
    if (((((uVar9 == 0) && (Globals::options[0x35] != '\0')) ||
         ((uVar9 == 1 && ((Globals::options._54_2_ & 0xff) != 0)))) ||
        (((uVar9 == 2 && (0xff < (ushort)Globals::options._54_2_)) ||
         ((uVar9 == 3 && ((Globals::options._56_2_ & 0xff) != 0)))))) ||
       (((uVar9 == 4 && (0xff < (ushort)Globals::options._56_2_)) ||
        (((uVar9 | 2) == 2 && (0xff < (ushort)Globals::options._56_2_)))))) {
      bVar38 = false;
    }
    else {
      bVar38 = (uVar9 != 4 || Globals::options[0x35] == '\0') ||
               (ushort)Globals::options._54_2_ < 0x100;
    }
    AbyssEngine::PaintCanvas::DisableClip();
    piVar13 = *(int **)(pMVar19 + 0xc0);
    pMVar15 = (MenuTouchWindow *)0x0;
    if (*piVar13 != 0) {
      pMVar22 = (MenuTouchWindow *)0x0;
      do {
        pTVar14 = *(TouchButton **)(piVar13[1] + (int)pMVar22 * 4);
        if (*(int *)pTVar14 == 0x3c && *(int *)(pTVar14 + 4) == 0) {
LAB_0014e020:
          TouchButton::draw(pTVar14);
        }
        else if (*(int *)(pTVar14 + 4) == 0 && *(int *)pTVar14 == 0x34) {
          TouchButton::setVisible(pTVar14,bVar38);
          pSVar11 = (String *)GameText::getText(Globals::gameText,0x62);
          TouchButton::setText(pTVar14,pSVar11);
          goto LAB_0014e020;
        }
        pMVar22 = pMVar22 + 1;
        piVar13 = *(int **)(local_22c + 0xc0);
        pMVar15 = (MenuTouchWindow *)*piVar13;
      } while (pMVar22 < pMVar15);
    }
    break;
  case (MenuTouchWindow *)0x10:
    pMVar15 = *(MenuTouchWindow **)(local_22c + 0xc0);
    if (*(int *)pMVar15 != 0) {
      uVar9 = 0;
      do {
        pTVar14 = *(TouchButton **)(*(int *)(pMVar15 + 4) + uVar9 * 4);
        if (-(*(int *)(pTVar14 + 4) - (uint)(*(uint *)pTVar14 < 0x65)) <
            (uint)(*(uint *)pTVar14 - 0x65 < 5)) {
          TouchButton::draw(pTVar14);
          pMVar15 = *(MenuTouchWindow **)(local_22c + 0xc0);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)pMVar15);
    }
    break;
  case (MenuTouchWindow *)0x11:
    if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(local_22c + 0x120),iVar25,0x50,'\x11','\x14');
    }
    pLVar27 = Globals::layout;
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x67);
    AbyssEngine::String::String(aSStack_20c,pSVar11,false);
    Layout::drawHeader(pLVar27,aSStack_20c,0);
    AbyssEngine::String::~String(aSStack_20c);
    pMVar22 = local_22c;
    puVar20 = *(uint **)(local_22c + 0xb8);
    if (*puVar20 != 0) {
      uVar9 = 0;
      do {
        TouchButton::draw(*(TouchButton **)(puVar20[1] + uVar9 * 4));
        puVar20 = *(uint **)(pMVar22 + 0xb8);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *puVar20);
    }
    TouchButton::getPosition();
    pPVar10 = Globals::Canvas;
    uVar9 = *(uint *)(pMVar22 + 0x128);
    uVar12 = TouchButton::getWidth((TouchButton *)**(undefined4 **)(*(int *)(pMVar22 + 0xb8) + 4));
    fVar39 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
    fVar40 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x2c) * 5,
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar41 = (float)VectorSignedToFloat(*(int *)(Globals::layout + 0x2c) * 0x14,
                                        (byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar10,uVar9,(int)((local_218 + fVar39) - fVar41),(int)(local_214 + fVar40),'D');
    pMVar15 = extraout_r1_05;
  }
switchD_0014c608_caseD_5:
  pMVar22 = local_22c;
  uVar9 = *(uint *)(local_22c + 0x16c);
  if (uVar9 != 0xb) {
    pMVar15 = *(MenuTouchWindow **)(local_22c + 0x168);
  }
  if ((uVar9 != 0xb && (pMVar15 != (MenuTouchWindow *)0x0 || uVar9 != 0)) &&
     ((0xf < uVar9 || ((1 << (uVar9 & 0xff) & 0xa010U) == 0)))) {
    Layout::drawEmptyFooter(Globals::layout,true);
  }
  if (Globals::layout[0x285] != (Layout)0x0) {
    uVar9 = *(uint *)(pMVar22 + 0x168) | 2;
    bVar38 = uVar9 == 2;
    if (bVar38) {
      uVar9 = *(uint *)(pMVar22 + 0x16c);
    }
    if ((bVar38 && uVar9 == 0) && (puVar20 = *(uint **)(pMVar22 + 0xc0), *puVar20 != 0)) {
      uVar9 = 0;
      do {
        pTVar14 = *(TouchButton **)(puVar20[1] + uVar9 * 4);
        if (*(int *)pTVar14 == 0x11 && *(int *)(pTVar14 + 4) == 0) {
          TouchButton::draw(pTVar14);
          puVar20 = *(uint **)(pMVar22 + 0xc0);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *puVar20);
    }
  }
  if (pMVar22[0x170] != (MenuTouchWindow)0x0) {
    ChoiceWindow::draw(*(ChoiceWindow **)(pMVar22 + 0x104));
  }
  if (*Globals::layout != (Layout)0x0) {
    Layout::drawHelpWindow();
  }
  if (__stack_chk_guard != local_5c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MenuTouchWindow::update  @0x0014ffec  (1598 bytes)
/* MenuTouchWindow::update(int) */

void MenuTouchWindow::update(int param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  String *pSVar5;
  TouchButton *pTVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  ChoiceWindow *pCVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint in_fpscr;
  float fVar14;
  float fVar15;
  float local_30;
  
  iVar2 = __stack_chk_guard;
  if ((*(uint *)(param_1 + 0x16c) < 0x10) &&
     ((1 << (*(uint *)(param_1 + 0x16c) & 0xff) & 0x8006U) != 0)) {
    if (*(char *)(param_1 + 0x224) == '\0') {
      fVar14 = *(float *)(param_1 + 0x218) * *(float *)(param_1 + 0x21c);
      fVar15 = -(*(float *)(param_1 + 0x218) * *(float *)(param_1 + 0x21c));
      if (0.0 < fVar14) {
        fVar15 = fVar14;
      }
      *(float *)(param_1 + 0x21c) = fVar14;
      uVar12 = in_fpscr & 0xfffffff | (uint)(fVar15 < 1.0) << 0x1f | (uint)(fVar15 == 1.0) << 0x1e;
      in_fpscr = uVar12 | (uint)NAN(fVar15) << 0x1c;
      bVar1 = (byte)(uVar12 >> 0x18);
      if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar15 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x194),
                                            (byte)(in_fpscr >> 0x16) & 3);
        *(int *)(param_1 + 0x194) = (int)(fVar14 + fVar15);
      }
    }
    iVar4 = *(int *)(param_1 + 0x194);
    if (0 < iVar4) {
      fVar15 = (float)VectorSignedToFloat(-iVar4,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x21c) = fVar15 * 0.5;
      *(undefined4 *)(param_1 + 0x218) = 0x3f800000;
    }
    iVar8 = *(int *)(param_1 + 0x228) - *(int *)(param_1 + 0x22c);
    if (iVar8 < 0) {
      if (iVar4 < iVar8) {
        fVar15 = (float)VectorSignedToFloat(iVar8 - iVar4,(byte)(in_fpscr >> 0x16) & 3);
        *(float *)(param_1 + 0x21c) = fVar15 * 0.5;
        *(undefined4 *)(param_1 + 0x218) = 0x3f800000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x194) = 0;
      *(undefined4 *)(param_1 + 0x21c) = 0;
    }
  }
  iVar4 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  cVar3 = *(char *)(param_1 + 0x17a);
  if ((cVar3 == '\0') && (*(char *)(param_1 + 400) == '\0')) {
LAB_00150176:
    if (*(char *)(param_1 + 400) != '\0') goto LAB_0015017c;
  }
  else {
    if (*(char *)(iVar4 + 0x34) != '\0') {
      *(int *)(param_1 + 0x228) =
           (((Globals::h - *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0xc)) -
           *(int *)(Globals::layout + 0x20)) - *(int *)(Globals::layout + 0x24);
      iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight
                        (Globals::Canvas,**(uint **)(param_1 + 0x134));
      *(int *)(param_1 + 0x1e4) = iVar8;
      *(int *)(param_1 + 0x22c) = (iVar8 + *(int *)(Globals::layout + 0x2c)) * 5;
      *(undefined4 *)(param_1 + 0x16c) = 0xf;
      *(undefined1 *)(param_1 + 0x170) = 0;
      *(undefined1 *)(param_1 + 0x17a) = 0;
      *(undefined1 *)(iVar4 + 0x34) = 0;
      Globals::options[0x3b] = 1;
      RecordHandler::saveOptions(Globals::recordHandler);
      cVar3 = *(char *)(param_1 + 0x17a);
    }
    if (cVar3 == '\0') goto LAB_00150176;
LAB_0015017c:
    if (*(char *)(iVar4 + 0x36) != '\0') {
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      pSVar5 = (String *)GameText::getText(Globals::gameText,100);
      ChoiceWindow::set(pCVar10,pSVar5);
      *(undefined1 *)(param_1 + 0x170) = 1;
      *(undefined1 *)(param_1 + 0x17d) = 1;
      *(undefined1 *)(param_1 + 0x17b) = 0;
      *(undefined1 *)(param_1 + 0x17a) = 0;
      *(undefined1 *)(iVar4 + 0x36) = 0;
      *(undefined1 *)(param_1 + 400) = 0;
    }
  }
  if ((*(uint *)(iVar4 + 0x3c) < 5) && (*(char *)(iVar4 + 0x35) != '\0')) {
    switch(*(uint *)(iVar4 + 0x3c)) {
    case 0:
      Globals::options[0x35] = '\x01';
      Status::setSystemVisibility(Globals::status,0x19,true);
      iVar8 = 0x5c;
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      break;
    case 1:
      *(undefined4 *)(Globals::status + 0x114) = 3;
      Globals::options[0x36] = 1;
      iVar8 = 0x5d;
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      break;
    case 2:
      Globals::options[0x37] = 1;
      Status::setSystemVisibility(Globals::status,0x19,true);
      iVar8 = 0x5e;
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      break;
    case 3:
      Globals::options[0x38] = 1;
      iVar8 = 0x5f;
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      break;
    case 4:
      Globals::options[0x39] = 1;
      Globals::options[0x35] = '\x01';
      Status::setSystemVisibility(Globals::status,0x19,true);
      iVar8 = 0x60;
      Globals::options[0x37] = 1;
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      break;
    default:
      goto switchD_001501ce_default;
    }
    pSVar5 = (String *)GameText::getText(Globals::gameText,iVar8);
    ChoiceWindow::set(pCVar10,pSVar5);
switchD_001501ce_default:
    RecordHandler::saveOptions(Globals::recordHandler);
LAB_00150324:
    *(undefined1 *)(param_1 + 0x170) = 1;
    *(undefined1 *)(param_1 + 0x17a) = 0;
    *(undefined1 *)(param_1 + 0x17c) = 1;
    *(undefined1 *)(iVar4 + 0x35) = 0;
  }
  else if ((*(char *)(param_1 + 400) != '\0') && (*(char *)(iVar4 + 0x35) != '\0')) {
    RecordHandler::saveOptions(Globals::recordHandler);
    if (*(char *)(param_1 + 400) != '\0') {
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x4c);
      ChoiceWindow::set(pCVar10,pSVar5);
      *(undefined1 *)(param_1 + 400) = 0;
    }
    goto LAB_00150324;
  }
  if ((Globals::isTelekomCustomer != '\0') &&
     (Globals::options[0x35] == '\0' && *(char *)(param_1 + 0x170) == '\0')) {
    pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0xca2);
    ChoiceWindow::set(pCVar10,pSVar5);
    *(undefined1 *)(param_1 + 0x170) = 1;
    *(undefined1 *)(param_1 + 0x181) = 1;
    Globals::options[0x35] = '\x01';
    Status::setSystemVisibility(Globals::status,0x19,true);
    RecordHandler::saveOptions(Globals::recordHandler);
  }
  switch(*(int *)(param_1 + 0x16c)) {
  case 0:
    if (*(int *)(param_1 + 0x168) == 1) {
      puVar7 = *(uint **)(param_1 + 4);
      uVar12 = *puVar7;
      if (uVar12 != 0) {
        iVar8 = *(int *)(param_1 + 0x1b0);
        iVar9 = *(int *)(Globals::layout + 0x30);
        iVar11 = iVar9 * uVar12;
        iVar13 = Globals::h / 2;
        iVar4 = iVar8 * (uVar12 - 1);
        uVar12 = 0;
        while( true ) {
          TouchButton::setYPosition
                    (*(TouchButton **)(puVar7[1] + uVar12 * 4),
                     (iVar8 + iVar9) * uVar12 + (iVar13 - ((uint)(iVar4 + iVar11) >> 1)));
          pTVar6 = *(TouchButton **)(*(int *)(*(int *)(param_1 + 4) + 4) + uVar12 * 4);
          if (((*(int *)pTVar6 == 0x12 && *(int *)(pTVar6 + 4) == 0) &&
              (iVar8 = TouchButton::isVisible(pTVar6), iVar8 == 1)) &&
             (*(char *)(param_1 + 0x238) != '\0')) {
            pTVar6 = *(TouchButton **)(*(int *)(*(int *)(param_1 + 4) + 4) + uVar12 * 4);
            TouchButton::getPosition();
            TouchButton::setYPosition(pTVar6,(int)local_30);
          }
          puVar7 = *(uint **)(param_1 + 4);
          uVar12 = uVar12 + 1;
          if (*puVar7 <= uVar12) break;
          iVar8 = *(int *)(param_1 + 0x1b0);
          iVar9 = *(int *)(Globals::layout + 0x30);
        }
      }
    }
    break;
  case 1:
  case 2:
  case 5:
  case 6:
  case 7:
  case 8:
    break;
  case 3:
    iVar4 = **(int **)(param_1 + 0xac);
    if (iVar4 != 0) {
      iVar4 = Globals::h / 2 -
              ((uint)((**(int **)(param_1 + 4) + -1) * *(int *)(param_1 + 0x1b0) +
                     *(int *)(Globals::layout + 0x30) * iVar4) >> 1);
      TouchButton::setYPosition(*(TouchButton **)(*(int **)(param_1 + 0xac))[1],iVar4);
      puVar7 = *(uint **)(param_1 + 0xac);
      if (1 < *puVar7) {
        uVar12 = 1;
        do {
          TouchButton::setYPosition
                    (*(TouchButton **)(puVar7[1] + uVar12 * 4),
                     (*(int *)(Globals::layout + 0x30) + *(int *)(param_1 + 0x1b0)) * uVar12 + iVar4
                    );
          puVar7 = *(uint **)(param_1 + 0xac);
          uVar12 = uVar12 + 1;
        } while (uVar12 < *puVar7);
      }
    }
    break;
  case 4:
    iVar4 = *(int *)(param_1 + 0xf0);
LAB_001504fc:
    ScrollTouchWindow::update(iVar4);
    break;
  case 9:
    if (*(int *)(param_1 + 0xfc) != 0) {
      MissionsWindow::update(*(int *)(param_1 + 0xfc));
    }
    break;
  default:
    if (*(int *)(param_1 + 0x16c) == 0xf) {
      iVar4 = *(int *)(param_1 + 0xf4);
      goto LAB_001504fc;
    }
  }
  if (*(char *)(param_1 + 0x170) != '\0') {
    ChoiceWindow::update(*(int *)(param_1 + 0x104));
  }
  if (*(int *)(param_1 + 0x16c) != 0xd) goto LAB_00150622;
  iVar4 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  if (*(char *)(iVar4 + 0xc) != '\0') {
    iVar4 = AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    if (*(int *)(iVar4 + 0xf0) == 2) {
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x38);
      ChoiceWindow::set(pCVar10,pSVar5);
    }
    else {
      if (*(int *)(iVar4 + 0xf0) != 1) goto LAB_001505a4;
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x37);
      ChoiceWindow::set(pCVar10,pSVar5);
    }
    *(undefined1 *)(param_1 + 0x170) = 1;
    *(undefined1 *)(param_1 + 0x189) = 0;
    iVar4 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
    *(undefined1 *)(iVar4 + 0xc) = 0;
  }
LAB_001505a4:
  iVar4 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  if (*(char *)(iVar4 + 5) != '\0') {
    iVar4 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
    if (*(int *)(iVar4 + 8) == 2) {
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x3a);
      ChoiceWindow::set(pCVar10,pSVar5);
    }
    else {
      if (*(int *)(iVar4 + 8) != 1) goto LAB_00150622;
      pCVar10 = *(ChoiceWindow **)(param_1 + 0x104);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0x39);
      ChoiceWindow::set(pCVar10,pSVar5);
    }
    *(undefined1 *)(param_1 + 0x170) = 1;
    *(undefined4 *)(param_1 + 0x184) = 0xffffffff;
    iVar4 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
    *(undefined1 *)(iVar4 + 5) = 0;
  }
LAB_00150622:
  if (__stack_chk_guard == iVar2) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== MenuTouchWindow::OnTouchBegin  @0x00150704  (1974 bytes)
/* MenuTouchWindow::OnTouchBegin(int, int, void*) */

undefined4 MenuTouchWindow::OnTouchBegin(int param_1,int param_2,void *param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint *puVar3;
  TouchButton *pTVar4;
  undefined **ppuVar5;
  int iVar6;
  int iVar7;
  int in_r3;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined **ppuVar11;
  int iVar12;
  Layout *pLVar13;
  int iVar14;
  int iVar15;
  float in_s0;
  float fVar16;
  
  pLVar13 = Globals::layout;
  if (*(char *)(param_1 + 0x170) != '\0') {
    ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(param_1 + 0x104),param_2,(int)param_3);
    return 0;
  }
  if (*Globals::layout != (Layout)0x0) {
    Layout::OnTouchBegin(Globals::layout,param_2,(int)param_3);
    return 0;
  }
  switch(*(undefined4 *)(param_1 + 0x16c)) {
  case 1:
  case 2:
    *(void **)(param_1 + 0x20c) = param_3;
    *(void **)(param_1 + 0x220) = param_3;
    *(undefined4 *)(param_1 + 0x214) = 0;
    *(undefined1 *)(param_1 + 0x224) = 1;
    iVar14 = *(int *)(param_1 + 0x18c);
    iVar12 = *(int *)(pLVar13 + 0xc);
    iVar7 = iVar14;
    if ((iVar12 < (int)param_3) && ((int)param_3 < Globals::h - *(int *)(pLVar13 + 0x10))) {
      iVar6 = *(int *)(pLVar13 + 0x20);
      iVar8 = *(int *)(param_1 + 0x194);
      iVar15 = *(int *)(param_1 + 0x1b4) + *(int *)(pLVar13 + 0x70);
      iVar2 = __aeabi_idiv((int)param_3 + ((-iVar6 - iVar12) - iVar8),iVar15);
      if (iVar2 < Globals::recordSlots) {
        *(int *)(param_1 + 0x18c) = iVar2;
        fVar16 = (float)TouchButton::setPosition
                                  (*(TouchButton **)(param_1 + 0xc4),
                                   (Globals::w - *(int *)(param_1 + 0x198)) -
                                   *(int *)(pLVar13 + 0x28),
                                   iVar15 * iVar2 + iVar6 + iVar12 + iVar8 +
                                   *(int *)(pLVar13 + 0x108));
        FModSound::play(Globals::sound,0x7c,(Vector *)0x0,(Vector *)0x0,fVar16);
        iVar7 = *(int *)(param_1 + 0x18c);
      }
    }
    if (iVar14 != iVar7) break;
    pTVar4 = *(TouchButton **)(param_1 + 0xc4);
    goto LAB_00150836;
  case 3:
    if (Globals::iPad == '\0') {
      puVar3 = *(uint **)(param_1 + 0xac);
      if (*puVar3 != 0) {
        uVar10 = 0;
        do {
          TouchButton::OnTouchBegin(*(TouchButton **)(puVar3[1] + uVar10 * 4),param_2,(int)param_3);
          puVar3 = *(uint **)(param_1 + 0xac);
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar3);
      }
      break;
    }
    fVar16 = (float)TouchButton::OnTouchBegin
                              (*(TouchButton **)(param_1 + 0xe4),param_2,(int)param_3);
    *(undefined2 *)(param_1 + 0x108) = 0;
    iVar12 = *(int *)(param_1 + 0x19c);
    iVar7 = *(int *)(Globals::layout + 0x28);
    if ((((iVar7 + iVar12 < param_2) && (param_2 < iVar7 + iVar12 + *(int *)(param_1 + 0x158))) &&
        (*(int *)(Globals::layout + 0xc) + iVar7 < (int)param_3)) &&
       ((int)param_3 <
        *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
        *(int *)(param_1 + 0x154))) {
      *(undefined1 *)(param_1 + 0x108) = 1;
      fVar16 = (float)FModSound::play(Globals::sound,0x7c,(Vector *)0x0,(Vector *)0x0,fVar16);
      iVar12 = *(int *)(param_1 + 0x19c);
      iVar7 = *(int *)(Globals::layout + 0x28);
    }
    if (((*(int *)(param_1 + 0x158) + iVar7 + iVar12 < param_2) &&
        (param_2 < (iVar12 - iVar7) + *(int *)(param_1 + 0x1a0))) &&
       ((iVar7 + *(int *)(Globals::layout + 0xc) < (int)param_3 &&
        ((int)param_3 <
         *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
         *(int *)(param_1 + 0x154))))) {
      *(undefined1 *)(param_1 + 0x109) = 1;
      FModSound::play(Globals::sound,0x7c,(Vector *)0x0,(Vector *)0x0,fVar16);
    }
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xcc),param_2,(int)param_3);
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xd0),param_2,(int)param_3);
    TouchSlider::OnTouchBegin
              ((TouchSlider *)**(undefined4 **)(*(int *)(param_1 + 0xec) + 4),param_2,(int)param_3);
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xd4),param_2,(int)param_3);
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xd8),param_2,(int)param_3);
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xdc),param_2,(int)param_3);
    puVar3 = *(uint **)(param_1 + 0xec);
    if (1 < *puVar3) {
      uVar10 = 1;
      do {
        TouchSlider::OnTouchBegin(*(TouchSlider **)(puVar3[1] + uVar10 * 4),param_2,(int)param_3);
        puVar3 = *(uint **)(param_1 + 0xec);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
    if ((Globals::iPadLargePossible == '\0') ||
       (pTVar4 = *(TouchButton **)(param_1 + 0xe8), pTVar4 == (TouchButton *)0x0)) break;
LAB_00150836:
    TouchButton::OnTouchBegin(pTVar4,param_2,(int)param_3);
    break;
  case 4:
    ScrollTouchWindow::OnTouchBegin(*(int *)(param_1 + 0xf0),param_2);
    puVar3 = *(uint **)(param_1 + 0xc0);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        pTVar4 = *(TouchButton **)(puVar3[1] + uVar10 * 4);
        uVar9 = *(uint *)pTVar4;
        if (((-(*(int *)(pTVar4 + 4) - (uint)(uVar9 < 0x6a)) < (uint)(uVar9 - 0x6a < 5)) &&
            ((1 << (uVar9 - 0x6a & 0xff) & 0x19U) != 0)) ||
           (uVar9 == 0x16 && *(int *)(pTVar4 + 4) == 0)) {
          TouchButton::OnTouchBegin(pTVar4,param_2,(int)param_3);
          puVar3 = *(uint **)(param_1 + 0xc0);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
    break;
  default:
    puVar3 = *(uint **)(param_1 + 4);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        TouchButton::OnTouchBegin(*(TouchButton **)(puVar3[1] + uVar10 * 4),param_2,(int)param_3);
        puVar3 = *(uint **)(param_1 + 4);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
    puVar3 = *(uint **)(param_1 + 0xc0);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        pTVar4 = *(TouchButton **)(puVar3[1] + uVar10 * 4);
        if (*(int *)pTVar4 - 0x17U < 2) {
          TouchButton::OnTouchBegin(pTVar4,param_2,(int)param_3);
          puVar3 = *(uint **)(param_1 + 0xc0);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
      if (*puVar3 != 0) {
        uVar10 = 0;
        do {
          pTVar4 = *(TouchButton **)(puVar3[1] + uVar10 * 4);
          uVar9 = *(uint *)pTVar4;
          iVar7 = *(int *)(pTVar4 + 4);
          if ((int)(-(uint)(0x34 < uVar9) - iVar7) < 0 ==
              (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(0x34 < uVar9)))) {
            if (uVar9 == 5 && iVar7 == 0) goto LAB_00150a98;
            uVar9 = uVar9 ^ 0x11;
LAB_00150a94:
            if (iVar7 == 0 && uVar9 == 0) goto LAB_00150a98;
          }
          else {
            if (uVar9 != 100 || iVar7 != 0) {
              uVar9 = uVar9 ^ 0x35;
              goto LAB_00150a94;
            }
LAB_00150a98:
            TouchButton::OnTouchBegin(pTVar4,param_2,(int)param_3);
            puVar3 = *(uint **)(param_1 + 0xc0);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar3);
      }
    }
    break;
  case 6:
  case 0xd:
    break;
  case 7:
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xd4),param_2,(int)param_3);
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xd8),param_2,(int)param_3);
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xdc),param_2,(int)param_3);
    puVar3 = *(uint **)(param_1 + 0xec);
    if (1 < *puVar3) {
      ppuVar11 = (undefined **)0x1;
      ppuVar5 = &PTR_layout_002658c8;
      do {
        if (ppuVar11 == (undefined **)0x5) {
          ppuVar5 = (undefined **)(uint)(byte)Globals::layout[0x284];
        }
        if (ppuVar11 != (undefined **)0x5 || ppuVar5 != (undefined **)0x0) {
          TouchSlider::OnTouchBegin
                    (*(TouchSlider **)(puVar3[1] + (int)ppuVar11 * 4),param_2,(int)param_3);
          puVar3 = *(uint **)(param_1 + 0xec);
        }
        ppuVar11 = (undefined **)((int)ppuVar11 + 1);
        ppuVar5 = (undefined **)*puVar3;
      } while (ppuVar11 < ppuVar5);
    }
    break;
  case 8:
    *(undefined2 *)(param_1 + 0x108) = 0;
    iVar12 = *(int *)(param_1 + 0x19c);
    iVar7 = *(int *)(pLVar13 + 0x28);
    if ((((iVar7 + iVar12 < param_2) && (param_2 < iVar7 + iVar12 + *(int *)(param_1 + 0x158))) &&
        (*(int *)(pLVar13 + 0xc) + iVar7 < (int)param_3)) &&
       ((int)param_3 <
        *(int *)(pLVar13 + 0xc) + *(int *)(pLVar13 + 0x20) + *(int *)(param_1 + 0x154))) {
      *(undefined1 *)(param_1 + 0x108) = 1;
      in_s0 = (float)FModSound::play(Globals::sound,0x7c,(Vector *)0x0,(Vector *)0x0,in_s0);
      iVar12 = *(int *)(param_1 + 0x19c);
      iVar7 = *(int *)(Globals::layout + 0x28);
      pLVar13 = Globals::layout;
    }
    if (((*(int *)(param_1 + 0x158) + iVar7 + iVar12 < param_2) &&
        (param_2 < (iVar12 - iVar7) + *(int *)(param_1 + 0x1a0))) &&
       ((iVar7 + *(int *)(pLVar13 + 0xc) < (int)param_3 &&
        ((int)param_3 <
         *(int *)(pLVar13 + 0x20) + *(int *)(pLVar13 + 0xc) + *(int *)(param_1 + 0x154))))) {
      *(undefined1 *)(param_1 + 0x109) = 1;
      FModSound::play(Globals::sound,0x7c,(Vector *)0x0,(Vector *)0x0,in_s0);
    }
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xcc),param_2,(int)param_3);
    TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0xd0),param_2,(int)param_3);
    TouchSlider::OnTouchBegin
              ((TouchSlider *)**(undefined4 **)(*(int *)(param_1 + 0xec) + 4),param_2,(int)param_3);
    break;
  case 9:
    MissionsWindow::OnTouchBegin(*(MissionsWindow **)(param_1 + 0xfc),param_2,(int)param_3);
    break;
  case 0xb:
    if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
      TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0x14),param_2,(int)param_3);
      TouchButton::OnTouchBegin(*(TouchButton **)(param_1 + 0x18),param_2,(int)param_3);
      if ((in_r3 == 0) ||
         ((((*(int *)(param_1 + 8) != 0 || (0xd1 < param_2)) || (*(int *)(param_1 + 0xc) == in_r3))
          || (((int)param_3 <= Globals::options._84_4_ + -0x14 ||
              (Globals::options._84_4_ + 300 <= (int)param_3)))))) {
        if ((*(int *)(param_1 + 8) == in_r3) ||
           (((*(int *)(param_1 + 0xc) != 0 || in_r3 == 0 || (param_2 <= Globals::w + -0xdc)) ||
            (((int)param_3 <= Globals::options._88_4_ + -0x14 ||
             (Globals::options._88_4_ + 0xe6 <= (int)param_3)))))) {
          *(undefined2 *)(param_1 + 0x98) = 0;
        }
        else {
          *(int *)(param_1 + 0xc) = in_r3;
          *(undefined1 *)(param_1 + 0x98) = 0;
          *(undefined1 *)(param_1 + 0x99) = 1;
          *(void **)(param_1 + 0x94) = param_3;
        }
      }
      else {
        *(int *)(param_1 + 8) = in_r3;
        *(undefined1 *)(param_1 + 0x98) = 1;
        *(undefined1 *)(param_1 + 0x99) = 0;
        *(void **)(param_1 + 0x90) = param_3;
      }
    }
    break;
  case 0xc:
    puVar3 = *(uint **)(param_1 + 0xb4);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        TouchButton::OnTouchBegin(*(TouchButton **)(puVar3[1] + uVar10 * 4),param_2,(int)param_3);
        puVar3 = *(uint **)(param_1 + 0xb4);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
    break;
  case 0xe:
    puVar3 = *(uint **)(param_1 + 0xb0);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        TouchButton::OnTouchBegin(*(TouchButton **)(puVar3[1] + uVar10 * 4),param_2,(int)param_3);
        puVar3 = *(uint **)(param_1 + 0xb0);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
    break;
  case 0xf:
    goto LAB_00150d0c;
  case 0x10:
    puVar3 = *(uint **)(param_1 + 0xc0);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        pTVar4 = *(TouchButton **)(puVar3[1] + uVar10 * 4);
        if (-(*(int *)(pTVar4 + 4) - (uint)(*(uint *)pTVar4 < 0x65)) <
            (uint)(*(uint *)pTVar4 - 0x65 < 5)) {
          TouchButton::OnTouchBegin(pTVar4,param_2,(int)param_3);
          puVar3 = *(uint **)(param_1 + 0xc0);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
LAB_00150d0c:
    ScrollTouchWindow::OnTouchBegin(*(int *)(param_1 + 0xf4),param_2);
    puVar3 = *(uint **)(param_1 + 0xc0);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        pTVar4 = *(TouchButton **)(puVar3[1] + uVar10 * 4);
        if ((*(uint *)pTVar4 | 8) == 0x3c && *(int *)(pTVar4 + 4) == 0) {
          TouchButton::OnTouchBegin(pTVar4,param_2,(int)param_3);
          puVar3 = *(uint **)(param_1 + 0xc0);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
    puVar3 = *(uint **)(param_1 + 0xf8);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        TouchButton::OnTouchBegin(*(TouchButton **)(puVar3[1] + uVar10 * 4),param_2,(int)param_3);
        puVar3 = *(uint **)(param_1 + 0xf8);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
    iVar12 = Globals::w - *(int *)(Globals::layout + 0x28);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth
                      (Globals::Canvas,
                       *(uint *)(*(int *)(param_1 + 0x138) + *(int *)(param_1 + 0x1e0) * 4));
    if ((iVar12 - iVar7 < param_2) &&
       (iVar14 = *(int *)(Globals::layout + 0xc), iVar12 = *(int *)(Globals::layout + 0x20),
       iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight
                         (Globals::Canvas,
                          *(uint *)(*(int *)(param_1 + 0x138) + *(int *)(param_1 + 0x1e0) * 4)),
       (int)param_3 < iVar7 + iVar12 + iVar14)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
    *(undefined1 *)(param_1 + 0x1d9) = uVar1;
    iVar12 = *(int *)(Globals::layout + 0x28);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,**(uint **)(param_1 + 0x134));
    if (param_2 < iVar7 + iVar12) {
      *(void **)(param_1 + 0x20c) = param_3;
      *(void **)(param_1 + 0x220) = param_3;
      *(undefined4 *)(param_1 + 0x214) = 0;
      *(undefined1 *)(param_1 + 0x224) = 1;
    }
    break;
  case 0x11:
    puVar3 = *(uint **)(param_1 + 0xb8);
    if (*puVar3 != 0) {
      uVar10 = 0;
      do {
        TouchButton::OnTouchBegin(*(TouchButton **)(puVar3[1] + uVar10 * 4),param_2,(int)param_3);
        puVar3 = *(uint **)(param_1 + 0xb8);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
  }
  iVar7 = Layout::OnTouchBegin(Globals::layout,param_2,(int)param_3);
  if ((iVar7 == 1) && (*(int *)(param_1 + 0x16c) == 0xd)) {
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return 0;
}

// ===== MenuTouchWindow::OnTouchMove  @0x00150f4c  (1996 bytes)
/* MenuTouchWindow::OnTouchMove(int, int, void*) */

undefined4 __thiscall
MenuTouchWindow::OnTouchMove(MenuTouchWindow *this,int param_1,int param_2,void *param_3)

{
  Globals *this_00;
  Layout *pLVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  FModSound *pFVar4;
  uint *puVar5;
  TouchButton *pTVar6;
  int iVar7;
  undefined **ppuVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined **ppuVar14;
  MenuTouchWindow *pMVar15;
  float fVar16;
  
  pLVar1 = Globals::layout;
  if (this[0x170] != (MenuTouchWindow)0x0) {
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
    return 0;
  }
  if (*Globals::layout != (Layout)0x0) goto LAB_0015172a;
  switch(*(undefined4 *)(this + 0x16c)) {
  case 1:
  case 2:
    if ((*(int *)(Globals::layout + 0xc) < param_2) &&
       (param_2 < Globals::h - *(int *)(Globals::layout + 0x10))) {
      iVar9 = *(int *)(this + 0x20c);
      *(int *)(this + 0x214) = param_2 - iVar9;
      *(int *)(this + 0x20c) = param_2;
      *(undefined4 *)(this + 0x218) = 0x3f800000;
      *(int *)(this + 0x194) = (param_2 - iVar9) + *(int *)(this + 0x194);
    }
    pTVar6 = *(TouchButton **)(this + 0xc4);
LAB_00150ff2:
    TouchButton::OnTouchMove(pTVar6,param_1,param_2);
    break;
  case 3:
    if (Globals::iPad == '\0') {
      puVar5 = *(uint **)(this + 0xac);
      if (*puVar5 != 0) {
        uVar13 = 0;
        do {
          TouchButton::OnTouchMove(*(TouchButton **)(puVar5[1] + uVar13 * 4),param_1,param_2);
          puVar5 = *(uint **)(this + 0xac);
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar5);
      }
    }
    else {
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0xe4),param_1,param_2);
      *(undefined2 *)(this + 0x108) = 0;
      pLVar1 = Globals::layout;
      iVar9 = *(int *)(Globals::layout + 0x28);
      iVar7 = iVar9 + *(int *)(this + 0x19c);
      iVar12 = *(int *)(this + 0x158) + iVar7;
      if (((iVar7 < param_1) && (param_1 < iVar12)) &&
         ((*(int *)(Globals::layout + 0xc) + iVar9 < param_2 &&
          (param_2 < *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                     *(int *)(this + 0x154))))) {
        this[0x108] = (MenuTouchWindow)0x1;
      }
      if ((((iVar12 < param_1) &&
           (param_1 < (*(int *)(this + 0x19c) - iVar9) + *(int *)(this + 0x1a0))) &&
          (iVar12 = *(int *)(pLVar1 + 0xc), iVar9 + iVar12 < param_2)) &&
         (param_2 < *(int *)(pLVar1 + 0x20) + iVar12 + *(int *)(this + 0x154))) {
        this[0x109] = (MenuTouchWindow)0x1;
      }
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0xcc),param_1,param_2);
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0xd0),param_1,param_2);
      TouchSlider::OnTouchMove(**(int **)(*(int *)(this + 0xec) + 4),param_1);
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0xd4),param_1,param_2);
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0xd8),param_1,param_2);
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0xdc),param_1,param_2);
      iVar9 = FModSound::tryToStopMusicForBGMusic();
      pFVar4 = Globals::sound;
      if (iVar9 == 0) {
        fVar16 = (float)TouchSlider::getValue
                                  (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 4));
        FModSound::setVolume(pFVar4,1,fVar16);
      }
      pFVar4 = Globals::sound;
      fVar16 = (float)TouchSlider::getValue
                                (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 8));
      FModSound::setVolume(pFVar4,2,fVar16);
      pFVar4 = Globals::sound;
      fVar16 = (float)TouchSlider::getValue
                                (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0xc));
      FModSound::setVolume(pFVar4,3,fVar16);
      puVar5 = *(uint **)(this + 0xec);
      if (1 < *puVar5) {
        uVar13 = 1;
        do {
          TouchSlider::OnTouchMove(*(int *)(puVar5[1] + uVar13 * 4),param_1);
          puVar5 = *(uint **)(this + 0xec);
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar5);
      }
      if ((Globals::iPadLargePossible != '\0') &&
         (pTVar6 = *(TouchButton **)(this + 0xe8), pTVar6 != (TouchButton *)0x0)) goto LAB_00150ff2;
    }
    break;
  case 4:
    ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 0xf0),param_1,param_2);
    puVar5 = *(uint **)(this + 0xc0);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        pTVar6 = *(TouchButton **)(puVar5[1] + uVar13 * 4);
        uVar10 = *(uint *)pTVar6;
        if (((-(*(int *)(pTVar6 + 4) - (uint)(uVar10 < 0x6a)) < (uint)(uVar10 - 0x6a < 5)) &&
            ((1 << (uVar10 - 0x6a & 0xff) & 0x19U) != 0)) ||
           (uVar10 == 0x16 && *(int *)(pTVar6 + 4) == 0)) {
          TouchButton::OnTouchMove(pTVar6,param_1,param_2);
          puVar5 = *(uint **)(this + 0xc0);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
    break;
  default:
    puVar5 = *(uint **)(this + 4);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        TouchButton::OnTouchMove(*(TouchButton **)(puVar5[1] + uVar13 * 4),param_1,param_2);
        puVar5 = *(uint **)(this + 4);
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
    puVar5 = *(uint **)(this + 0xc0);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        pTVar6 = *(TouchButton **)(puVar5[1] + uVar13 * 4);
        if (*(int *)pTVar6 - 0x17U < 2) {
          TouchButton::OnTouchBegin(pTVar6,param_1,param_2);
          puVar5 = *(uint **)(this + 0xc0);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
      if (*puVar5 != 0) {
        uVar13 = 0;
        do {
          pTVar6 = *(TouchButton **)(puVar5[1] + uVar13 * 4);
          uVar10 = *(uint *)pTVar6;
          iVar9 = *(int *)(pTVar6 + 4);
          if ((int)(-(uint)(0x34 < uVar10) - iVar9) < 0 ==
              (SBORROW4(0,iVar9) != SBORROW4(-iVar9,(uint)(0x34 < uVar10)))) {
            if (uVar10 == 5 && iVar9 == 0) goto LAB_00151274;
            uVar10 = uVar10 ^ 0x11;
LAB_00151270:
            if (iVar9 == 0 && uVar10 == 0) goto LAB_00151274;
          }
          else {
            if (uVar10 != 100 || iVar9 != 0) {
              uVar10 = uVar10 ^ 0x35;
              goto LAB_00151270;
            }
LAB_00151274:
            TouchButton::OnTouchMove(pTVar6,param_1,param_2);
            puVar5 = *(uint **)(this + 0xc0);
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar5);
      }
    }
    break;
  case 6:
  case 0xd:
    break;
  case 7:
    TouchButton::OnTouchMove(*(TouchButton **)(this + 0xd4),param_1,param_2);
    TouchButton::OnTouchMove(*(TouchButton **)(this + 0xd8),param_1,param_2);
    TouchButton::OnTouchMove(*(TouchButton **)(this + 0xdc),param_1,param_2);
    iVar9 = FModSound::tryToStopMusicForBGMusic();
    pFVar4 = Globals::sound;
    if (iVar9 != 1) {
      fVar16 = (float)TouchSlider::getValue
                                (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 4));
      FModSound::setVolume(pFVar4,1,fVar16);
    }
    pFVar4 = Globals::sound;
    pMVar15 = this + 0xec;
    fVar16 = (float)TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)pMVar15 + 4) + 8));
    FModSound::setVolume(pFVar4,2,fVar16);
    pFVar4 = Globals::sound;
    fVar16 = (float)TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)pMVar15 + 4) + 0xc));
    FModSound::setVolume(pFVar4,3,fVar16);
    puVar5 = *(uint **)pMVar15;
    if (1 < *puVar5) {
      ppuVar14 = (undefined **)0x1;
      ppuVar8 = &PTR_layout_002658c8;
      do {
        if (ppuVar14 == (undefined **)0x5) {
          ppuVar8 = (undefined **)(uint)(byte)Globals::layout[0x284];
        }
        if (ppuVar14 != (undefined **)0x5 || ppuVar8 != (undefined **)0x0) {
          TouchSlider::OnTouchMove(*(int *)(puVar5[1] + (int)ppuVar14 * 4),param_1);
          puVar5 = *(uint **)pMVar15;
        }
        ppuVar14 = (undefined **)((int)ppuVar14 + 1);
        ppuVar8 = (undefined **)*puVar5;
      } while (ppuVar14 < ppuVar8);
    }
    break;
  case 8:
    *(undefined2 *)(this + 0x108) = 0;
    iVar9 = *(int *)(pLVar1 + 0x28);
    iVar7 = iVar9 + *(int *)(this + 0x19c);
    iVar12 = *(int *)(this + 0x158) + iVar7;
    if (((iVar7 < param_1) && (param_1 < iVar12)) &&
       ((*(int *)(pLVar1 + 0xc) + iVar9 < param_2 &&
        (param_2 < *(int *)(pLVar1 + 0xc) + *(int *)(pLVar1 + 0x20) + *(int *)(this + 0x154))))) {
      this[0x108] = (MenuTouchWindow)0x1;
    }
    if ((((iVar12 < param_1) &&
         (param_1 < (*(int *)(this + 0x19c) - iVar9) + *(int *)(this + 0x1a0))) &&
        (iVar9 + *(int *)(pLVar1 + 0xc) < param_2)) &&
       (param_2 < *(int *)(pLVar1 + 0x20) + *(int *)(pLVar1 + 0xc) + *(int *)(this + 0x154))) {
      this[0x109] = (MenuTouchWindow)0x1;
    }
    TouchButton::OnTouchMove(*(TouchButton **)(this + 0xcc),param_1,param_2);
    TouchButton::OnTouchMove(*(TouchButton **)(this + 0xd0),param_1,param_2);
    TouchSlider::OnTouchMove(**(int **)(*(int *)(this + 0xec) + 4),param_1);
    break;
  case 9:
    MissionsWindow::OnTouchMove(*(MissionsWindow **)(this + 0xfc),param_1,param_2);
    break;
  case 0xb:
    if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0x14),param_1,param_2);
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0x18),param_1,param_2);
      uVar3 = Globals::options._88_4_;
      uVar2 = Globals::options._84_4_;
      this_00 = Globals::globals;
      if (param_3 != (void *)0x0) {
        if (*(void **)(this + 8) == param_3) {
          iVar11 = *(int *)(this + 0x90);
          iVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x1c));
          iVar12 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x24))
          ;
          iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x20));
          Globals::setCoordsSteer
                    (this_00,(uVar2 + param_2) - iVar11,iVar9,iVar12,iVar7,(ushort *)(this + 0x2e),
                     (ushort *)(this + 0x30),(ushort *)(this + 0x40),(ushort *)(this + 0x42),
                     (ushort *)(this + 0x3c),(ushort *)(this + 0x3e),(ushort *)(this + 0x34),
                     (ushort *)(this + 0x32),(ushort *)(this + 0x48),(ushort *)(this + 0x4a));
          *(int *)(this + 0x90) = param_2;
        }
        else if (*(void **)(this + 0xc) == param_3) {
          iVar12 = *(int *)(this + 0x94);
          iVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x78));
          Globals::setCoordsFire
                    (this_00,(uVar3 + param_2) - iVar12,iVar9,*(uint *)(this + 0x78),
                     *(uint *)(this + 0x7c),(uint *)(this + 0x74),(ushort *)(this + 0x60),
                     (ushort *)(this + 0x62),(ushort *)(this + 100),(ushort *)(this + 0x66),
                     (ushort *)(this + 0x68),(ushort *)(this + 0x6a),(ushort *)(this + 0x6c),
                     (ushort *)(this + 0x6e),(ushort *)(this + 0x70),(ushort *)(this + 0x72),
                     (ushort *)(this + 0x4c),(ushort *)(this + 0x4e));
          *(int *)(this + 0x94) = param_2;
        }
      }
    }
    break;
  case 0xc:
    puVar5 = *(uint **)(this + 0xb4);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        TouchButton::OnTouchMove(*(TouchButton **)(puVar5[1] + uVar13 * 4),param_1,param_2);
        puVar5 = *(uint **)(this + 0xb4);
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
    break;
  case 0xe:
    puVar5 = *(uint **)(this + 0xb0);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        TouchButton::OnTouchMove(*(TouchButton **)(puVar5[1] + uVar13 * 4),param_1,param_2);
        puVar5 = *(uint **)(this + 0xb0);
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
    break;
  case 0xf:
    goto LAB_001514e6;
  case 0x10:
    puVar5 = *(uint **)(this + 0xc0);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        pTVar6 = *(TouchButton **)(puVar5[1] + uVar13 * 4);
        if (-(*(int *)(pTVar6 + 4) - (uint)(*(uint *)pTVar6 < 0x65)) <
            (uint)(*(uint *)pTVar6 - 0x65 < 5)) {
          TouchButton::OnTouchMove(pTVar6,param_1,param_2);
          puVar5 = *(uint **)(this + 0xc0);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
LAB_001514e6:
    ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 0xf4),param_1,param_2);
    puVar5 = *(uint **)(this + 0xc0);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        pTVar6 = *(TouchButton **)(puVar5[1] + uVar13 * 4);
        if ((*(uint *)pTVar6 | 8) == 0x3c && *(int *)(pTVar6 + 4) == 0) {
          TouchButton::OnTouchMove(pTVar6,param_1,param_2);
          puVar5 = *(uint **)(this + 0xc0);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
    puVar5 = *(uint **)(this + 0xf8);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        TouchButton::OnTouchMove(*(TouchButton **)(puVar5[1] + uVar13 * 4),param_1,param_2);
        puVar5 = *(uint **)(this + 0xf8);
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
    if (((*(int *)(Globals::layout + 0xc) < param_2) &&
        (param_2 < Globals::h - *(int *)(Globals::layout + 0x10))) &&
       (iVar12 = *(int *)(Globals::layout + 0x28),
       iVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,**(uint **)(this + 0x134)),
       param_1 < iVar9 + iVar12)) {
      iVar9 = *(int *)(this + 0x20c);
      *(int *)(this + 0x214) = param_2 - iVar9;
      *(int *)(this + 0x20c) = param_2;
      *(undefined4 *)(this + 0x218) = 0x3f800000;
      *(int *)(this + 0x194) = (param_2 - iVar9) + *(int *)(this + 0x194);
    }
    break;
  case 0x11:
    puVar5 = *(uint **)(this + 0xb8);
    if (*puVar5 != 0) {
      uVar13 = 0;
      do {
        TouchButton::OnTouchMove(*(TouchButton **)(puVar5[1] + uVar13 * 4),param_1,param_2);
        puVar5 = *(uint **)(this + 0xb8);
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar5);
    }
  }
LAB_0015172a:
  Layout::OnTouchMove(Globals::layout,param_1,param_2);
  return 0;
}

// ===== MenuTouchWindow::OnTouchEnd  @0x0015179c  (7204 bytes)
/* MenuTouchWindow::OnTouchEnd(int, int, void*) */

void __thiscall
MenuTouchWindow::OnTouchEnd(MenuTouchWindow *this,int param_1,int param_2,void *param_3)

{
  byte bVar1;
  Globals *pGVar2;
  ApplicationManager *this_00;
  char cVar3;
  bool bVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  void *pvVar8;
  FModSound *this_01;
  Engine *pEVar9;
  double *pdVar10;
  undefined4 *puVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  TouchButton *pTVar16;
  String *pSVar17;
  String *pSVar18;
  int extraout_r1;
  ChoiceWindow *pCVar19;
  uint uVar20;
  MenuTouchWindow *pMVar21;
  uint uVar22;
  undefined4 *puVar23;
  ScrollTouchWindow *pSVar24;
  uint uVar25;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float fVar26;
  float extraout_s0_02;
  undefined4 uVar27;
  undefined4 uVar28;
  double dVar29;
  undefined8 uVar30;
  undefined4 *local_f0;
  AbyssEngine aAStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  int local_5c;
  
  local_5c = __stack_chk_guard;
  this[0x224] = (MenuTouchWindow)0x0;
  this[1] = (MenuTouchWindow)0x0;
  if (*Globals::layout != (Layout)0x0) {
    iVar7 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
    if (iVar7 == 1) {
      *Globals::layout = (Layout)0x0;
    }
    goto switchD_00152f08_caseD_0;
  }
  switch(*(undefined4 *)(this + 0x16c)) {
  case 0:
    if (this[0x170] == (MenuTouchWindow)0x0) {
LAB_001532c4:
      puVar14 = *(uint **)(this + 4);
      if (*puVar14 != 0) {
        uVar20 = 0;
        do {
          iVar7 = TouchButton::OnTouchEnd
                            (*(TouchButton **)(puVar14[1] + uVar20 * 4),param_1,param_2);
          if (iVar7 == 1) {
            puVar14 = *(uint **)(*(int *)(*(int *)(this + 4) + 4) + uVar20 * 4);
            uVar22 = *puVar14;
            uVar25 = puVar14[1];
            if (-uVar25 < (uint)(uVar22 < 0x1a)) {
                    /* WARNING: Could not recover jumptable at 0x001534d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(&DAT_001534d8 + (uint)*(ushort *)(&DAT_001534d8 + uVar22 * 2) * 2))
                        (uVar22,uVar25,-(uint)(uVar22 >= 0x1a) - uVar25);
              return;
            }
            if (uVar22 == 0x6b && uVar25 == 0) {
              *(undefined4 *)(this + 0x16c) = 0x12;
            }
          }
          puVar14 = *(uint **)(this + 4);
          uVar20 = uVar20 + 1;
        } while (uVar20 < *puVar14);
      }
      puVar14 = *(uint **)(this + 0xc0);
      if (*puVar14 != 0) {
        uVar20 = 0;
        local_f0 = &g_android_show_leaderboards;
        do {
          pTVar16 = *(TouchButton **)(puVar14[1] + uVar20 * 4);
          iVar7 = *(int *)pTVar16;
          if (iVar7 == 0x18) {
            iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2);
            if (iVar7 == 1) {
              if (g_android_gp_is_linked != 0) {
                puVar11 = &g_android_show_achievements;
                goto LAB_0015381e;
              }
              pCVar19 = *(ChoiceWindow **)(this + 0x104);
              AbyssEngine::String::String((String *)aAStack_74,"No link with Google+",false);
              pSVar17 = (String *)GameText::getText(Globals::gameText,0xd46);
              ChoiceWindow::set(pCVar19,(String *)aAStack_74,pSVar17,true);
LAB_00153904:
              AbyssEngine::String::~String((String *)aAStack_74);
              this[0x170] = (MenuTouchWindow)0x1;
              this[0x191] = (MenuTouchWindow)0x1;
            }
LAB_00153914:
            Globals::reportLeaderboards();
          }
          else {
            if (iVar7 == 0x17) {
              iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2);
              if (iVar7 == 1) {
                puVar11 = local_f0;
                if (g_android_gp_is_linked == 0) {
                  pCVar19 = *(ChoiceWindow **)(this + 0x104);
                  AbyssEngine::String::String((String *)aAStack_74,"No link with Google+",false);
                  pSVar17 = (String *)GameText::getText(Globals::gameText,0xd46);
                  ChoiceWindow::set(pCVar19,(String *)aAStack_74,pSVar17,true);
                  goto LAB_00153904;
                }
LAB_0015381e:
                *puVar11 = 1;
              }
              goto LAB_00153914;
            }
            Globals::reportLeaderboards();
            if (iVar7 == 0x35) {
              iVar7 = TouchButton::OnTouchEnd
                                (*(TouchButton **)(*(int *)(*(int *)(this + 0xc0) + 4) + uVar20 * 4)
                                 ,param_1,param_2);
              if (iVar7 == 1) {
                iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
                *(undefined1 *)(iVar7 + 0x40) = 0;
                iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
                *(undefined1 *)(iVar7 + 0x31) = 1;
                this[0x17a] = (MenuTouchWindow)0x1;
                this[0x170] = (MenuTouchWindow)0x1;
                pCVar19 = *(ChoiceWindow **)(this + 0x104);
                pSVar17 = (String *)GameText::getText(Globals::gameText,0x47);
                pSVar18 = (String *)GameText::getText(Globals::gameText,0x1a9);
                ChoiceWindow::set(pCVar19,pSVar17,pSVar18);
              }
            }
            else if ((iVar7 == 0x11) &&
                    (iVar7 = TouchButton::OnTouchEnd
                                       (*(TouchButton **)
                                         (*(int *)(*(int *)(this + 0xc0) + 4) + uVar20 * 4),param_1,
                                        param_2), iVar7 != 0)) {
              pSVar17 = *(String **)(this + 0x104);
              bVar4 = (bool)GameText::getText(Globals::gameText,0x35);
              ChoiceWindow::set(pSVar17,bVar4);
              this[0x170] = (MenuTouchWindow)0x1;
              this[0x178] = (MenuTouchWindow)0x1;
              goto switchD_00152f08_caseD_b;
            }
          }
          puVar14 = *(uint **)(this + 0xc0);
          uVar20 = uVar20 + 1;
        } while (uVar20 < *puVar14);
      }
      break;
    }
    uVar20 = *(uint *)(this + 0x178);
    if ((uVar20 & 0xff) == 0) {
      if (this[0x177] != (MenuTouchWindow)0x0) {
        iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
        if (iVar7 == 1) {
          this[0x170] = (MenuTouchWindow)0x0;
          this[0x177] = (MenuTouchWindow)0x0;
          this[0x174] = (MenuTouchWindow)0x0;
        }
        else if (iVar7 == 0) {
          FModSound::resumeAll(Globals::sound);
          FModSound::stopAll(Globals::sound);
          Globals::switch_to_target_setting = 2;
          AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,1);
          this[0x170] = (MenuTouchWindow)0x0;
          this[0x177] = (MenuTouchWindow)0x0;
        }
        goto switchD_00152f08_caseD_0;
      }
      if (this[0x191] == (MenuTouchWindow)0x0) {
        if ((uVar20 & 0xff00) == 0) {
          uVar20 = uVar20 >> 0x10;
        }
        else {
          iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
          if ((iVar7 == 1) || (iVar7 == 0)) {
            Globals::reportLeaderboards();
          }
          this[0x170] = (MenuTouchWindow)0x0;
          this[0x179] = (MenuTouchWindow)0x0;
          uVar20 = (uint)(byte)this[0x17a];
        }
        if ((uVar20 & 0xff) != 0) {
          iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
          goto joined_r0x00151882;
        }
        if ((this[0x17d] != (MenuTouchWindow)0x0) ||
           (uVar20 = *(uint *)(this + 0x17c), (uVar20 & 0xff) != 0)) goto LAB_00153164;
        if ((uVar20 & 0xff0000) != 0) {
          this[0x170] = (MenuTouchWindow)0x0;
          this[0x17e] = (MenuTouchWindow)0x0;
          goto switchD_00152f08_caseD_0;
        }
        if ((uVar20 < 0x1000000) ||
           (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
           iVar7 != 0)) {
          if ((*(ushort *)(this + 0x180) & 0xff) == 0) {
            uVar6 = *(ushort *)(this + 0x180) >> 8;
          }
          else {
            iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
            if (iVar7 == 0) {
              this[0x170] = (MenuTouchWindow)0x0;
              this[0x180] = (MenuTouchWindow)0x0;
              goto switchD_00152f08_caseD_0;
            }
            uVar6 = (ushort)(byte)this[0x181];
          }
          if ((uVar6 != 0) &&
             (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
             iVar7 == 0)) {
            this[0x170] = (MenuTouchWindow)0x0;
            this[0x181] = (MenuTouchWindow)0x0;
            goto switchD_00152f08_caseD_0;
          }
          goto LAB_001532c4;
        }
        this[0x17f] = (MenuTouchWindow)0x0;
      }
      else {
        iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
        if (iVar7 != 1) {
          if (iVar7 != 0) goto switchD_00152f08_caseD_0;
          g_android_link_game_gp = 1;
        }
        this[0x191] = (MenuTouchWindow)0x0;
      }
      goto LAB_0015316e;
    }
    iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
    if (iVar7 == 1) {
      this[0x170] = (MenuTouchWindow)0x0;
      this[0x178] = (MenuTouchWindow)0x0;
      goto switchD_00152f08_caseD_0;
    }
    if (iVar7 != 0) goto switchD_00152f08_caseD_0;
    AbyssEngine::ApplicationManager::Quit(Globals::appManager);
    goto switchD_00152f08_caseD_b;
  case 1:
    if (this[0x170] != (MenuTouchWindow)0x0) {
      if (((this[0x1db] != (MenuTouchWindow)0x0) || (this[0x1da] != (MenuTouchWindow)0x0)) ||
         ((iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
          iVar7 == 0 &&
          ((iVar7 = ChoiceWindow::hasChoice(*(ChoiceWindow **)(this + 0x104)), iVar7 == 1 &&
           (iVar7 = loadGame((int)this), iVar7 != 1)))))) goto switchD_00152f08_caseD_b;
      this[0x170] = (MenuTouchWindow)0x0;
    }
    iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xc4),param_1,param_2);
    if (iVar7 != 1) break;
    if (*(int *)(*(int *)(*(int *)(this + 0xbc) + 4) + *(int *)(this + 0x18c) * 4) != 0) {
      iVar7 = Status::getPlayingTime(Globals::status);
      if (extraout_r1 < (int)(uint)(iVar7 == 0)) {
        FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,extraout_s0);
        loadGame((int)this);
        goto switchD_00152f08_caseD_0;
      }
      pSVar17 = *(String **)(this + 0x104);
      bVar4 = (bool)GameText::getText(Globals::gameText,0x33);
      ChoiceWindow::set(pSVar17,bVar4);
      this[0x170] = (MenuTouchWindow)0x1;
    }
    goto switchD_00152f08_caseD_b;
  case 2:
    uVar20 = *(uint *)(this + 0x170);
    if ((uVar20 & 0xff) == 0) {
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xc4),param_1,param_2);
      if (iVar7 != 1) break;
      if (*(int *)(this + 0x18c) == 0) {
        pCVar19 = *(ChoiceWindow **)(this + 0x104);
        pSVar17 = (String *)GameText::getText(Globals::gameText,0x1e7);
        AbyssEngine::operator+(aAStack_74,pSVar17);
        ChoiceWindow::set(pCVar19,aAStack_74);
        AbyssEngine::String::~String((String *)aAStack_74);
        this[0x170] = (MenuTouchWindow)0x1;
      }
      else {
        if (*(int *)(*(int *)(*(int *)(this + 0xbc) + 4) + *(int *)(this + 0x18c) * 4) == 0) {
          FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,extraout_s0_01);
          saveGame(this,*(int *)(this + 0x18c));
          goto switchD_00152f08_caseD_0;
        }
        pSVar17 = *(String **)(this + 0x104);
        bVar4 = (bool)GameText::getText(Globals::gameText,0x31);
        ChoiceWindow::set(pSVar17,bVar4);
        this[0x170] = (MenuTouchWindow)0x1;
        this[0x173] = (MenuTouchWindow)0x1;
      }
    }
    else if ((this[0x1db] == (MenuTouchWindow)0x0) && (this[0x1da] == (MenuTouchWindow)0x0)) {
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
      if (0xffffff < uVar20) {
        if (iVar7 == 1) {
          this[0x170] = (MenuTouchWindow)0x0;
          this[0x173] = (MenuTouchWindow)0x0;
        }
        else if (iVar7 == 0) {
          saveGame(this,*(int *)(this + 0x18c));
          this[0x173] = (MenuTouchWindow)0x0;
        }
        goto switchD_00152f08_caseD_0;
      }
      if (iVar7 != 0) goto switchD_00152f08_caseD_0;
      goto LAB_0015316e;
    }
    goto switchD_00152f08_caseD_b;
  case 3:
    if (Globals::iPad == '\0') {
      puVar14 = *(uint **)(this + 0xac);
      if (*puVar14 != 0) {
        uVar20 = 0;
        do {
          iVar7 = TouchButton::OnTouchEnd
                            (*(TouchButton **)(puVar14[1] + uVar20 * 4),param_1,param_2);
          puVar14 = *(uint **)(this + 0xac);
          if (iVar7 == 1) {
            puVar13 = *(uint **)(puVar14[1] + uVar20 * 4);
            uVar25 = *puVar13;
            uVar22 = puVar13[1];
            if (-(uVar22 - (uVar25 < 4)) < (uint)(uVar25 - 4 < 6)) {
                    /* WARNING: Could not recover jumptable at 0x0015261a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)(&UNK_0015261e + (uint)*(byte *)(uVar25 + 0x15261a) * 2))();
              return;
            }
            if (uVar25 == 0x19 && uVar22 == 0) {
              *(undefined4 *)(this + 0x16c) = 0xe;
            }
          }
          uVar20 = uVar20 + 1;
        } while (uVar20 < *puVar14);
      }
    }
    else {
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xe4),param_1,param_2);
      if (iVar7 == 1) {
        *(undefined4 *)(this + 0x16c) = 0xb;
      }
      if (((this[0x170] != (MenuTouchWindow)0x0) && (this[0x176] != (MenuTouchWindow)0x0)) &&
         (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
         iVar7 == 0)) {
        pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
        iVar7 = AbyssEngine::Engine::GetAccelValue(pEVar9);
        dVar29 = *(double *)(iVar7 + 0x10);
        pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
        pdVar10 = (double *)AbyssEngine::Engine::GetAccelValue(pEVar9);
        uVar20 = in_fpscr & 0xfffffff;
        uVar22 = uVar20 | (uint)(dVar29 < 0.0) << 0x1f | (uint)(dVar29 == 0.0) << 0x1e;
        in_fpscr = uVar22 | (uint)NAN(dVar29) << 0x1c;
        dVar29 = *pdVar10;
        bVar1 = (byte)(uVar22 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
          uVar20 = uVar20 | (uint)(dVar29 < 1.0) << 0x1f | (uint)(dVar29 == 1.0) << 0x1e;
          in_fpscr = uVar20 | (uint)NAN(dVar29) << 0x1c;
          bVar1 = (byte)(uVar20 >> 0x18);
          if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
            pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
            puVar11 = (undefined4 *)AbyssEngine::Engine::GetAccelValue(pEVar9);
            *puVar11 = 0;
            puVar11[1] = 0x3ff00000;
          }
          pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
          pdVar10 = (double *)AbyssEngine::Engine::GetAccelValue(pEVar9);
          dVar29 = (1.0 - *pdVar10) + 1.0;
        }
        Globals::options._28_4_ = (undefined4)dVar29;
        pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
        iVar7 = AbyssEngine::Engine::GetAccelValue(pEVar9);
        Globals::options._32_4_ = (undefined4)*(double *)(iVar7 + 0x10);
        this[0x170] = (MenuTouchWindow)0x0;
        this[0x176] = (MenuTouchWindow)0x0;
      }
      cVar3 = Globals::options[0x11];
      uVar28 = TouchSlider::getValue((TouchSlider *)**(undefined4 **)(*(int *)(this + 0xec) + 4));
      if (cVar3 != '\0') {
        Globals::options._20_4_ = uVar28;
        uVar28 = Globals::options._24_4_;
      }
      Globals::options._24_4_ = uVar28;
      uVar6 = *(ushort *)(this + 0x108) >> 8;
      if ((*(ushort *)(this + 0x108) & 0xff) != 0) {
        iVar7 = *(int *)(this + 0x19c) + *(int *)(Globals::layout + 0x28);
        if (((iVar7 < param_1) && (param_1 < iVar7 + *(int *)(this + 0x158))) &&
           ((*(int *)(Globals::layout + 0x28) + *(int *)(Globals::layout + 0xc) < param_2 &&
            (param_2 < *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
                       *(int *)(this + 0x154))))) {
          Globals::options[0x11] = '\x01';
          fVar26 = (float)TouchButton::setHalfTransparent(*(TouchButton **)(this + 0xd0),true);
          fVar26 = (float)TouchSlider::setValue
                                    ((TouchSlider *)**(undefined4 **)(*(int *)(this + 0xec) + 4),
                                     fVar26);
          FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,fVar26);
          uVar6 = (ushort)(byte)this[0x109];
        }
      }
      if (uVar6 != 0) {
        iVar7 = *(int *)(Globals::layout + 0x28);
        if (((*(int *)(this + 0x158) + iVar7 + *(int *)(this + 0x19c) < param_1) &&
            (param_1 < (*(int *)(this + 0x19c) - iVar7) + *(int *)(this + 0x1a0))) &&
           ((iVar7 + *(int *)(Globals::layout + 0xc) < param_2 &&
            (param_2 < *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
                       *(int *)(this + 0x154))))) {
          Globals::options[0x11] = '\0';
          fVar26 = (float)TouchButton::setHalfTransparent(*(TouchButton **)(this + 0xd0),false);
          fVar26 = (float)TouchSlider::setValue
                                    ((TouchSlider *)**(undefined4 **)(*(int *)(this + 0xec) + 4),
                                     fVar26);
          FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,fVar26);
        }
      }
      *(undefined2 *)(this + 0x108) = 0;
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xcc),param_1,param_2);
      if (iVar7 == 1) {
        Globals::options[0x10] = Globals::options[0x10] ^ 1;
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xcc),(bool)Globals::options[0x10]);
      }
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xd0),param_1,param_2);
      if (iVar7 == 1) {
        pCVar19 = *(ChoiceWindow **)(this + 0x104);
        pSVar17 = (String *)GameText::getText(Globals::gameText,0x1ed);
        ChoiceWindow::set(pCVar19,pSVar17);
        this[0x170] = (MenuTouchWindow)0x1;
        this[0x176] = (MenuTouchWindow)0x1;
      }
      TouchSlider::OnTouchEnd(**(int **)(*(int *)(this + 0xec) + 4),param_1);
      if ((this[0x170] != (MenuTouchWindow)0x0) &&
         (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
         iVar7 == 0)) goto LAB_00152cfe;
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xd4),param_1,param_2);
      if (iVar7 == 1) {
        Globals::options[0xd] = Globals::options[0xd] ^ 1;
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xd4),(bool)Globals::options[0xd]);
        TouchSlider::setHalfTransparent
                  (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 4),
                   Globals::options[0xd] == 0);
        FModSound::enableCategory((int)Globals::sound,true);
      }
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xd8),param_1,param_2);
      if (iVar7 == 1) {
        Globals::options[0xc] = Globals::options[0xc] ^ 1;
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xd8),(bool)Globals::options[0xc]);
        TouchSlider::setHalfTransparent
                  (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 8),
                   Globals::options[0xc] == 0);
        fVar26 = (float)FModSound::enableCategory((int)Globals::sound,true);
        FModSound::play(Globals::sound,0x7e,(Vector *)0x0,(Vector *)0x0,fVar26);
      }
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xdc),param_1,param_2);
      if (iVar7 == 1) {
        Globals::options[0xe] = Globals::options[0xe] ^ 1;
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xdc),(bool)Globals::options[0xe]);
        TouchSlider::setHalfTransparent
                  (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0xc),
                   Globals::options[0xe] == 0);
        FModSound::enableCategory((int)Globals::sound,true);
      }
      Globals::options._0_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 4));
      Globals::options._4_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 8));
      Globals::options._8_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0xc));
      Globals::options._36_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x10));
      Globals::options._40_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0x14));
      puVar14 = *(uint **)(this + 0xec);
      if (1 < *puVar14) {
        uVar20 = 1;
        do {
          iVar7 = TouchSlider::OnTouchEnd(*(int *)(puVar14[1] + uVar20 * 4),param_1);
          if (iVar7 == 1) {
            if (uVar20 == 5) {
              fVar26 = (float)TouchSlider::getValue
                                        (*(TouchSlider **)
                                          (*(int *)(*(int *)(this + 0xec) + 4) + 0x14));
              if (Globals::iPadLargePossible == '\0') {
                iVar7 = 0x200;
                in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar26 == 0.33) << 0x1e |
                           (uint)(0.33 <= fVar26) << 0x1d;
                pCVar19 = *(ChoiceWindow **)(this + 0x104);
                if (fVar26 <= 0.66) {
                  iVar7 = 0x1ff;
                }
                bVar1 = (byte)(in_fpscr >> 0x18);
                if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
                  iVar7 = 0x1fe;
                }
                pSVar17 = (String *)GameText::getText(Globals::gameText,iVar7);
                ChoiceWindow::set(pCVar19,pSVar17);
                this[0x170] = (MenuTouchWindow)0x1;
              }
              else {
                pCVar19 = *(ChoiceWindow **)(this + 0x104);
                pSVar17 = (String *)GameText::getText(Globals::gameText,0x7a);
                ChoiceWindow::set(pCVar19,pSVar17);
                uVar28 = 0x3f800000;
                in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar26 == 0.33) << 0x1e |
                           (uint)(0.33 <= fVar26) << 0x1d;
                if (fVar26 <= 0.66) {
                  uVar28 = 0x3f000000;
                }
                bVar1 = (byte)(in_fpscr >> 0x18);
                Globals::options._68_4_ = 0;
                if ((bool)(bVar1 >> 5 & 1) && !(bool)(bVar1 >> 6)) {
                  Globals::options._68_4_ = uVar28;
                }
                this[0x170] = (MenuTouchWindow)0x1;
                RecordHandler::saveOptions(Globals::recordHandler);
              }
            }
            else if (uVar20 == 2) {
              FModSound::play(Globals::sound,0x7e,(Vector *)0x0,(Vector *)0x0,extraout_s0_02);
            }
          }
          puVar14 = *(uint **)(this + 0xec);
          uVar20 = uVar20 + 1;
        } while (uVar20 < *puVar14);
      }
      if (((Globals::iPadLargePossible != '\0') &&
          (*(TouchButton **)(this + 0xe8) != (TouchButton *)0x0)) &&
         (iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xe8),param_1,param_2),
         iVar7 == 1)) {
        Globals::options[0x40] = Globals::options[0x40] ^ 1;
        RecordHandler::saveOptions(Globals::recordHandler);
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xe8),(bool)Globals::options[0x40]);
        pCVar19 = *(ChoiceWindow **)(this + 0x104);
        pSVar17 = (String *)GameText::getText(Globals::gameText,0x7a);
        ChoiceWindow::set(pCVar19,pSVar17);
        this[0x170] = (MenuTouchWindow)0x1;
      }
    }
    break;
  case 4:
    ScrollTouchWindow::OnTouchEnd(*(int *)(this + 0xf0),param_1);
    puVar14 = *(uint **)(this + 0xc0);
    if (*puVar14 != 0) {
      uVar20 = 0;
      do {
        pTVar16 = *(TouchButton **)(puVar14[1] + uVar20 * 4);
        uVar22 = *(uint *)pTVar16;
        iVar7 = *(int *)(pTVar16 + 4);
        if ((int)(-(uint)(0x6c < uVar22) - iVar7) < 0 ==
            (SBORROW4(0,iVar7) != SBORROW4(-iVar7,(uint)(0x6c < uVar22)))) {
          if (uVar22 == 0x16 && iVar7 == 0) {
            iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2);
            if (iVar7 == 1) {
              iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
              *(undefined1 *)(iVar7 + 0xd) = 1;
              NFC::rateGame();
            }
          }
          else if ((iVar7 == 0 && uVar22 == 0x6a) &&
                  (iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2), iVar7 == 1)) {
            NFC::rateGame();
            iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
            *(undefined1 *)(iVar7 + 0xe) = 1;
          }
        }
        else if (uVar22 == 0x6d && iVar7 == 0) {
          iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2);
          if (iVar7 == 1) {
            NFC::openPrivacyPolicy();
          }
        }
        else if ((iVar7 == 0 && uVar22 == 0x6e) &&
                (iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2), iVar7 == 1)) {
          NFC::openTermsOfService();
        }
        puVar14 = *(uint **)(this + 0xc0);
        uVar20 = uVar20 + 1;
      } while (uVar20 < *puVar14);
    }
    break;
  case 7:
    if ((this[0x170] == (MenuTouchWindow)0x0) ||
       (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
       iVar7 != 0)) {
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xd4),param_1,param_2);
      if (iVar7 == 1) {
        Globals::options[0xd] = Globals::options[0xd] ^ 1;
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xd4),(bool)Globals::options[0xd]);
        TouchSlider::setHalfTransparent
                  (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 4),
                   Globals::options[0xd] == 0);
        FModSound::enableCategory((int)Globals::sound,true);
      }
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xd8),param_1,param_2);
      if (iVar7 == 1) {
        Globals::options[0xc] = Globals::options[0xc] ^ 1;
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xd8),(bool)Globals::options[0xc]);
        TouchSlider::setHalfTransparent
                  (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 8),
                   Globals::options[0xc] == 0);
        fVar26 = (float)FModSound::enableCategory((int)Globals::sound,true);
        FModSound::play(Globals::sound,0x7e,(Vector *)0x0,(Vector *)0x0,fVar26);
      }
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xdc),param_1,param_2);
      if (iVar7 != 0) {
        Globals::options[0xe] = Globals::options[0xe] ^ 1;
        TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xdc),(bool)Globals::options[0xe]);
        TouchSlider::setHalfTransparent
                  (*(TouchSlider **)(*(int *)(*(int *)(this + 0xec) + 4) + 0xc),
                   Globals::options[0xe] == 0);
        FModSound::enableCategory((int)Globals::sound,true);
      }
      pMVar21 = this + 0xec;
      Globals::options._0_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)pMVar21 + 4) + 4));
      Globals::options._4_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)pMVar21 + 4) + 8));
      Globals::options._8_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)pMVar21 + 4) + 0xc));
      Globals::options._36_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)pMVar21 + 4) + 0x10));
      Globals::options._40_4_ =
           TouchSlider::getValue(*(TouchSlider **)(*(int *)(*(int *)pMVar21 + 4) + 0x14));
      puVar14 = *(uint **)pMVar21;
      if (1 < *puVar14) {
        puVar23 = (undefined4 *)0x1;
        puVar11 = &Globals::gameText;
        do {
          if (puVar23 == (undefined4 *)0x5) {
            puVar11 = (undefined4 *)(uint)(byte)Globals::layout[0x284];
          }
          if ((puVar23 != (undefined4 *)0x5 || puVar11 != (undefined4 *)0x0) &&
             (iVar7 = TouchSlider::OnTouchEnd(*(int *)(puVar14[1] + (int)puVar23 * 4),param_1),
             iVar7 == 1)) {
            if (puVar23 == (undefined4 *)0x2) {
              FModSound::play(Globals::sound,0x7e,(Vector *)0x0,(Vector *)0x0,extraout_s0_00);
            }
            else if (puVar23 == (undefined4 *)0x5) {
              fVar26 = (float)TouchSlider::getValue
                                        (*(TouchSlider **)
                                          (*(int *)(*(int *)(this + 0xec) + 4) + 0x14));
              iVar7 = 0x200;
              pCVar19 = *(ChoiceWindow **)(this + 0x104);
              in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar26 == 0.33) << 0x1e |
                         (uint)(0.33 <= fVar26) << 0x1d;
              if (fVar26 <= 0.66) {
                iVar7 = 0x1ff;
              }
              bVar1 = (byte)(in_fpscr >> 0x18);
              if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
                iVar7 = 0x1fe;
              }
              pSVar17 = (String *)GameText::getText(Globals::gameText,iVar7);
              ChoiceWindow::set(pCVar19,pSVar17);
              this[0x170] = (MenuTouchWindow)0x1;
            }
          }
          puVar14 = *(uint **)pMVar21;
          puVar23 = (undefined4 *)((int)puVar23 + 1);
          puVar11 = (undefined4 *)*puVar14;
        } while (puVar23 < puVar11);
      }
    }
    else {
LAB_00152cfe:
      this[0x170] = (MenuTouchWindow)0x0;
    }
    break;
  case 8:
    if (((this[0x170] != (MenuTouchWindow)0x0) && (this[0x176] != (MenuTouchWindow)0x0)) &&
       (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
       iVar7 == 0)) {
      pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
      iVar7 = AbyssEngine::Engine::GetAccelValue(pEVar9);
      dVar29 = *(double *)(iVar7 + 0x10);
      pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
      pdVar10 = (double *)AbyssEngine::Engine::GetAccelValue(pEVar9);
      uVar20 = in_fpscr & 0xfffffff;
      uVar22 = uVar20 | (uint)(dVar29 < 0.0) << 0x1f | (uint)(dVar29 == 0.0) << 0x1e;
      in_fpscr = uVar22 | (uint)NAN(dVar29) << 0x1c;
      dVar29 = *pdVar10;
      bVar1 = (byte)(uVar22 >> 0x18);
      if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        uVar20 = uVar20 | (uint)(dVar29 < 1.0) << 0x1f | (uint)(dVar29 == 1.0) << 0x1e;
        in_fpscr = uVar20 | (uint)NAN(dVar29) << 0x1c;
        bVar1 = (byte)(uVar20 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
          pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
          puVar11 = (undefined4 *)AbyssEngine::Engine::GetAccelValue(pEVar9);
          *puVar11 = 0;
          puVar11[1] = 0x3ff00000;
        }
        pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
        pdVar10 = (double *)AbyssEngine::Engine::GetAccelValue(pEVar9);
        dVar29 = (1.0 - *pdVar10) + 1.0;
      }
      Globals::options._28_4_ = (undefined4)dVar29;
      pEVar9 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
      iVar7 = AbyssEngine::Engine::GetAccelValue(pEVar9);
      Globals::options._32_4_ = (undefined4)*(double *)(iVar7 + 0x10);
      this[0x170] = (MenuTouchWindow)0x0;
      this[0x176] = (MenuTouchWindow)0x0;
    }
    cVar3 = Globals::options[0x11];
    uVar28 = TouchSlider::getValue((TouchSlider *)**(undefined4 **)(*(int *)(this + 0xec) + 4));
    if (cVar3 != '\0') {
      Globals::options._20_4_ = uVar28;
      uVar28 = Globals::options._24_4_;
    }
    Globals::options._24_4_ = uVar28;
    uVar6 = *(ushort *)(this + 0x108) >> 8;
    if ((*(ushort *)(this + 0x108) & 0xff) != 0) {
      iVar7 = *(int *)(this + 0x19c) + *(int *)(Globals::layout + 0x28);
      if (((iVar7 < param_1) && (param_1 < iVar7 + *(int *)(this + 0x158))) &&
         ((*(int *)(Globals::layout + 0x28) + *(int *)(Globals::layout + 0xc) < param_2 &&
          (param_2 < *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
                     *(int *)(this + 0x154))))) {
        Globals::options[0x11] = '\x01';
        fVar26 = (float)TouchButton::setHalfTransparent(*(TouchButton **)(this + 0xd0),true);
        fVar26 = (float)TouchSlider::setValue
                                  ((TouchSlider *)**(undefined4 **)(*(int *)(this + 0xec) + 4),
                                   fVar26);
        FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,fVar26);
        uVar6 = (ushort)(byte)this[0x109];
      }
    }
    if (uVar6 != 0) {
      iVar7 = *(int *)(Globals::layout + 0x28);
      if (((*(int *)(this + 0x158) + iVar7 + *(int *)(this + 0x19c) < param_1) &&
          (param_1 < (*(int *)(this + 0x19c) - iVar7) + *(int *)(this + 0x1a0))) &&
         ((iVar7 + *(int *)(Globals::layout + 0xc) < param_2 &&
          (param_2 < *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc) +
                     *(int *)(this + 0x154))))) {
        Globals::options[0x11] = '\0';
        fVar26 = (float)TouchButton::setHalfTransparent(*(TouchButton **)(this + 0xd0),false);
        fVar26 = (float)TouchSlider::setValue
                                  ((TouchSlider *)**(undefined4 **)(*(int *)(this + 0xec) + 4),
                                   fVar26);
        FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,fVar26);
      }
    }
    *(undefined2 *)(this + 0x108) = 0;
    iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xcc),param_1,param_2);
    if (iVar7 == 1) {
      Globals::options[0x10] = Globals::options[0x10] ^ 1;
      TouchButton::setAlwaysPressed(*(TouchButton **)(this + 0xcc),(bool)Globals::options[0x10]);
    }
    iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0xd0),param_1,param_2);
    if (iVar7 == 1) {
      pCVar19 = *(ChoiceWindow **)(this + 0x104);
      pSVar17 = (String *)GameText::getText(Globals::gameText,0x1ed);
      ChoiceWindow::set(pCVar19,pSVar17);
      this[0x170] = (MenuTouchWindow)0x1;
      this[0x176] = (MenuTouchWindow)0x1;
    }
    TouchSlider::OnTouchEnd(**(int **)(*(int *)(this + 0xec) + 4),param_1);
    break;
  case 9:
    iVar7 = MissionsWindow::OnTouchEnd(*(MissionsWindow **)(this + 0xfc),param_1,param_2);
    if (iVar7 == 1) {
      uVar28 = 0;
LAB_00152e96:
      *(undefined4 *)(this + 0x16c) = uVar28;
    }
    break;
  case 10:
    if ((this[0x170] != (MenuTouchWindow)0x0) &&
       (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
       iVar7 == 0)) {
      uVar28 = 0;
      this[0x170] = (MenuTouchWindow)0x0;
      goto LAB_00152e96;
    }
    break;
  case 0xb:
    if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
      if (param_3 != (void *)0x0) {
        if (*(void **)(this + 8) == param_3) {
          *(undefined4 *)(this + 8) = 0;
        }
        if (*(void **)(this + 0xc) == param_3) {
          *(undefined4 *)(this + 0xc) = 0;
        }
      }
      *(undefined2 *)(this + 0x98) = 0;
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x14),param_1,param_2);
      if (iVar7 == 1) {
        *(undefined4 *)(this + 0x16c) = 3;
      }
      iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x18),param_1,param_2);
      pGVar2 = Globals::globals;
      if (iVar7 == 1) {
        Globals::options._84_4_ = 0x247;
        iVar7 = 0x201;
        if (!NAN((float)Globals::options._68_4_)) {
          Globals::options._84_4_ = 0x33e;
        }
        if ((float)Globals::options._68_4_ <= 0.0) {
          Globals::options._84_4_ = 0x19f;
        }
        in_fpscr = in_fpscr & 0xfffffff | (uint)((float)Globals::options._68_4_ == 0.0) << 0x1e |
                   (uint)(0.0 <= (float)Globals::options._68_4_) << 0x1d;
        if (!NAN((float)Globals::options._68_4_)) {
          iVar7 = 0x2da;
        }
        bVar1 = (byte)(in_fpscr >> 0x18);
        if (!(bool)(bVar1 >> 5 & 1) || (bool)(bVar1 >> 6)) {
          iVar7 = 0x16d;
        }
        Globals::options._88_4_ = iVar7;
        iVar15 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x78));
        Globals::setCoordsFire
                  (pGVar2,iVar7,iVar15,*(uint *)(this + 0x78),*(uint *)(this + 0x7c),
                   (uint *)(this + 0x74),(ushort *)(this + 0x60),(ushort *)(this + 0x62),
                   (ushort *)(this + 100),(ushort *)(this + 0x66),(ushort *)(this + 0x68),
                   (ushort *)(this + 0x6a),(ushort *)(this + 0x6c),(ushort *)(this + 0x6e),
                   (ushort *)(this + 0x70),(ushort *)(this + 0x72),(ushort *)(this + 0x4c),
                   (ushort *)(this + 0x4e));
        uVar28 = Globals::options._84_4_;
        pGVar2 = Globals::globals;
        iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x1c));
        iVar15 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x24));
        iVar12 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x20));
        Globals::setCoordsSteer
                  (pGVar2,uVar28,iVar7,iVar15,iVar12,(ushort *)(this + 0x2e),(ushort *)(this + 0x30)
                   ,(ushort *)(this + 0x40),(ushort *)(this + 0x42),(ushort *)(this + 0x3c),
                   (ushort *)(this + 0x3e),(ushort *)(this + 0x34),(ushort *)(this + 0x32),
                   (ushort *)(this + 0x48),(ushort *)(this + 0x4a));
      }
    }
    break;
  case 0xc:
    if (this[0x174] == (MenuTouchWindow)0x0) {
      puVar14 = *(uint **)(this + 0xb4);
      if (*puVar14 != 0) {
        uVar20 = 0;
        do {
          iVar7 = TouchButton::OnTouchEnd
                            (*(TouchButton **)(puVar14[1] + uVar20 * 4),param_1,param_2);
          if (iVar7 == 1) {
            Globals::options._44_4_ = 0x3fc00000;
            if (uVar20 == 0) {
              Globals::options._44_4_ = 0x3f000000;
            }
            *(undefined4 *)(this + 0x1a4) = Globals::options._44_4_;
            if (uVar20 != 0) {
              pSVar17 = *(String **)(this + 0x104);
              bVar4 = (bool)GameText::getText(Globals::gameText,0x1a);
              ChoiceWindow::set(pSVar17,bVar4);
              this[0x170] = (MenuTouchWindow)0x1;
              this[0x174] = (MenuTouchWindow)0x1;
              goto switchD_00152f08_caseD_b;
            }
            uVar30 = Status::getPlayingTime(Globals::status);
            if ((int)((ulonglong)uVar30 >> 0x20) < (int)(uint)((int)uVar30 == 0)) goto LAB_00152686;
            pSVar17 = *(String **)(this + 0x104);
            bVar4 = (bool)GameText::getText(Globals::gameText,0x34);
            ChoiceWindow::set(pSVar17,bVar4);
            this[0x170] = (MenuTouchWindow)0x1;
            this[0x174] = (MenuTouchWindow)0x1;
          }
          puVar14 = *(uint **)(this + 0xb4);
          uVar20 = uVar20 + 1;
        } while (uVar20 < *puVar14);
      }
      break;
    }
    iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
    if (iVar7 == 1) {
      this[0x170] = (MenuTouchWindow)0x0;
      this[0x174] = (MenuTouchWindow)0x0;
      goto switchD_00152f08_caseD_0;
    }
    if (iVar7 != 0) goto switchD_00152f08_caseD_0;
LAB_00152686:
    if (*(int *)(this + 0x234) == 2) {
      startSupernova(this);
    }
    else if (*(int *)(this + 0x234) == 1) {
      startValkyrie(this);
    }
    else {
      startGOF2(this);
    }
    goto switchD_00152f08_caseD_b;
  case 0xd:
    if ((this[0x170] != (MenuTouchWindow)0x0) &&
       (iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2),
       iVar7 == 0)) {
LAB_0015316e:
      this[0x170] = (MenuTouchWindow)0x0;
      goto switchD_00152f08_caseD_0;
    }
    break;
  case 0xe:
    puVar14 = *(uint **)(this + 0xb0);
    if (*puVar14 != 0) {
      uVar20 = 0;
      do {
        iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(puVar14[1] + uVar20 * 4),param_1,param_2);
        if (iVar7 == 1) {
          sVar5 = GameText::getLanguage();
          puVar14 = *(uint **)(*(int *)(*(int *)(this + 0xb0) + 4) + uVar20 * 4);
          uVar22 = *puVar14;
          uVar25 = uVar22 - 0x1b;
          if (-(puVar14[1] - (uint)(uVar22 < 0x1b)) < (uint)(uVar25 < 0xd)) {
            iVar7 = *(int *)(&DAT_002585f0 + uVar25 * 4);
            Globals::loadFont(Globals::globals,iVar7);
            GameText::setLanguage(Globals::gameText,(short)iVar7,0xd49);
            if (sVar5 == 1 || uVar25 == 1) {
              if (Globals::sound != (FModSound *)0x0) {
                pvVar8 = (void *)FModSound::~FModSound(Globals::sound);
                operator_delete(pvVar8);
              }
              Globals::sound = (FModSound *)0x0;
              this_01 = operator_new(0x243c);
              FModSound::FModSound(this_01);
              Globals::sound = this_01;
              FModSound::init(this_01);
              iVar7 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule
                                (Globals::appManager);
              if (iVar7 == 5) {
                Globals::switch_to_target_setting = 1;
              }
              else {
                Globals::switch_to_target_setting = 2;
              }
            }
            RecordHandler::saveOptions(Globals::recordHandler);
            Achievements::resetNewMedals(Globals::achievements);
            Layout::reload(Globals::layout);
            iVar7 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule
                              (Globals::appManager);
            if (iVar7 == 5) {
              Globals::status[0x108] = (Status)0x1;
            }
            this_00 = Globals::appManager;
            uVar22 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule
                               (Globals::appManager);
            AbyssEngine::ApplicationManager::SetCurrentApplicationModule(this_00,uVar22);
          }
        }
        puVar14 = *(uint **)(this + 0xb0);
        uVar20 = uVar20 + 1;
      } while (uVar20 < *puVar14);
    }
    break;
  case 0xf:
    if (this[0x17a] != (MenuTouchWindow)0x0) {
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
joined_r0x00151882:
      if (iVar7 == 0) {
        iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
        *(undefined1 *)(iVar7 + 0x30) = 1;
        this[0x170] = (MenuTouchWindow)0x0;
        this[0x17a] = (MenuTouchWindow)0x0;
      }
      goto switchD_00152f08_caseD_0;
    }
    if ((this[0x17d] != (MenuTouchWindow)0x0) || (this[0x17c] != (MenuTouchWindow)0x0)) {
LAB_00153164:
      this[0x17d] = (MenuTouchWindow)0x0;
      this[0x17c] = (MenuTouchWindow)0x0;
      goto LAB_0015316e;
    }
    if (this[0x170] != (MenuTouchWindow)0x0) {
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
      if (iVar7 == 0) {
        this[0x170] = (MenuTouchWindow)0x0;
        iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
        *(undefined1 *)(iVar7 + 0x34) = 0;
      }
      goto switchD_00152f08_caseD_0;
    }
    ScrollTouchWindow::OnTouchEnd(*(int *)(this + 0xf4),param_1);
    puVar14 = *(uint **)(this + 0xc0);
    if (*puVar14 != 0) {
      uVar20 = 0;
      do {
        pTVar16 = *(TouchButton **)(puVar14[1] + uVar20 * 4);
        if (*(int *)pTVar16 == 0x3c && *(int *)(pTVar16 + 4) == 0) {
          iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2);
          if (iVar7 == 1) {
            iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
            *(undefined4 *)(iVar7 + 0x3c) = 0xffffffff;
            iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
            *(undefined1 *)(iVar7 + 0x33) = 1;
            this[400] = (MenuTouchWindow)0x1;
            goto LAB_001530b2;
          }
        }
        else if ((*(int *)(pTVar16 + 4) == 0 && *(int *)pTVar16 == 0x34) &&
                (iVar7 = TouchButton::OnTouchEnd(pTVar16,param_1,param_2), iVar7 == 1)) {
          switch(*(undefined4 *)(this + 0x1e0)) {
          case 0:
            if (Globals::options[0x35] == '\0') {
              NFC::iap_buy_dlc_valkyrie();
            }
            break;
          case 1:
            if (Globals::options[0x36] == '\0') {
              NFC::iap_buy_dlc_kaamo_club();
            }
            break;
          case 2:
            if (Globals::options[0x37] == '\0') {
              NFC::iap_buy_dlc_supernova();
            }
            break;
          case 3:
            if (Globals::options[0x38] == '\0') {
              NFC::iap_buy_dlc_vip();
            }
            break;
          case 4:
            if (Globals::options[0x39] == '\0') {
              NFC::iap_buy_dlc_full_package();
            }
          }
          uVar28 = *(undefined4 *)(this + 0x1e0);
          iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
          *(undefined4 *)(iVar7 + 0x3c) = uVar28;
LAB_001530b2:
          this[0x170] = (MenuTouchWindow)0x0;
        }
        puVar14 = *(uint **)(this + 0xc0);
        uVar20 = uVar20 + 1;
      } while (uVar20 < *puVar14);
    }
    puVar14 = *(uint **)(this + 0xf8);
    if (*puVar14 != 0) {
      uVar20 = *(uint *)(this + 0x1e0);
      uVar22 = 0;
      do {
        iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(puVar14[1] + uVar22 * 4),param_1,param_2);
        if (iVar7 == 1) {
          *(uint *)(this + 0x1e0) = uVar22;
          if (uVar20 == uVar22) {
            switch(uVar20) {
            case 0:
              NFC::iap_buy_dlc_valkyrie();
              break;
            case 1:
              NFC::iap_buy_dlc_kaamo_club();
              break;
            case 2:
              NFC::iap_buy_dlc_supernova();
              break;
            case 3:
              NFC::iap_buy_dlc_vip();
              break;
            case 4:
              NFC::iap_buy_dlc_full_package();
            }
          }
          else {
            pSVar24 = *(ScrollTouchWindow **)(this + 0xf4);
            AbyssEngine::String::String(aSStack_64,"",false);
            pSVar17 = (String *)GameText::getText(Globals::gameText,*(int *)(this + 0x1e0) + 0x57);
            AbyssEngine::String::String(aSStack_6c,pSVar17,false);
            ScrollTouchWindow::setText(pSVar24,aSStack_64,aSStack_6c);
            AbyssEngine::String::~String(aSStack_6c);
            AbyssEngine::String::~String(aSStack_64);
          }
          break;
        }
        puVar14 = *(uint **)(this + 0xf8);
        uVar22 = uVar22 + 1;
      } while (uVar22 < *puVar14);
    }
    if ((this[0x1d9] != (MenuTouchWindow)0x0) &&
       (iVar15 = Globals::w - *(int *)(Globals::layout + 0x28),
       iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth
                         (Globals::Canvas,
                          *(uint *)(*(int *)(this + 0x138) + *(int *)(this + 0x1e0) * 4)),
       iVar15 - iVar7 < param_1)) {
      AbyssEngine::PaintCanvas::GetImage2DHeight
                (Globals::Canvas,*(uint *)(*(int *)(this + 0x138) + *(int *)(this + 0x1e0) * 4));
    }
    break;
  case 0x11:
    if (this[0x175] != (MenuTouchWindow)0x0) {
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x104),param_1,param_2);
      if (iVar7 == 0) {
        *(undefined4 *)(this + 0x16c) = 0xc;
      }
      this[0x170] = (MenuTouchWindow)0x0;
      this[0x175] = (MenuTouchWindow)0x0;
      goto switchD_00152f08_caseD_0;
    }
    puVar14 = *(uint **)(this + 0xb8);
    if (*puVar14 != 0) {
      uVar20 = 0;
      do {
        iVar7 = TouchButton::OnTouchEnd(*(TouchButton **)(puVar14[1] + uVar20 * 4),param_1,param_2);
        if (iVar7 == 1) {
          *(uint *)(this + 0x234) = uVar20;
          if (uVar20 == 2) {
            if (Globals::options[0x37] == '\0') {
              NFC::iap_buy_dlc_supernova();
              goto switchD_00152f08_caseD_b;
            }
          }
          else if (uVar20 == 1) {
            if (Globals::options[0x35] == '\0') {
              NFC::iap_buy_dlc_valkyrie();
              goto switchD_00152f08_caseD_b;
            }
          }
          else {
            *(undefined4 *)(this + 0x16c) = 0xc;
          }
          uVar28 = 0xc;
          goto LAB_00152e96;
        }
        puVar14 = *(uint **)(this + 0xb8);
        uVar20 = uVar20 + 1;
      } while (uVar20 < *puVar14);
    }
  }
  if (*(int *)(this + 0x16c) - 1U < 2) {
    iVar15 = *(int *)(this + 0x214);
    uVar28 = VectorSignedToFloat(iVar15,(byte)(in_fpscr >> 0x16) & 3);
    iVar7 = iVar15;
    if (iVar15 < 0) {
      iVar7 = -iVar15;
    }
    uVar27 = 0;
    if (3 < iVar7) {
      uVar27 = uVar28;
    }
    *(undefined4 *)(this + 0x21c) = uVar27;
    *(undefined4 *)(this + 0x218) = 0x3f666666;
    this[0x224] = (MenuTouchWindow)0x0;
    iVar7 = *(int *)(this + 0x194);
    *(int *)(this + 0x194) = iVar15 + iVar7;
    *(int *)(this + 0x210) = iVar15 + iVar7;
  }
  iVar7 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
  if (iVar7 != 1) goto switchD_00152f08_caseD_b;
  switch(*(undefined4 *)(this + 0x16c)) {
  case 0:
    goto switchD_00152f08_caseD_0;
  case 3:
    RecordHandler::saveOptions(Globals::recordHandler);
  default:
    uVar28 = 0;
LAB_00152f48:
    *(undefined4 *)(this + 0x16c) = uVar28;
    break;
  case 6:
  case 7:
  case 8:
  case 0xe:
    uVar28 = 3;
    if (Globals::iPad != '\0') {
      uVar28 = 0;
    }
    *(undefined4 *)(this + 0x16c) = uVar28;
    break;
  case 0xb:
    break;
  case 0xc:
    uVar28 = 0x11;
    goto LAB_00152f48;
  }
switchD_00152f08_caseD_b:
switchD_00152f08_caseD_0:
  if (__stack_chk_guard - local_5c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_5c);
  }
  return;
}

// ===== MenuTouchWindow::startValkyrie  @0x00153ba4  (560 bytes)
/* MenuTouchWindow::startValkyrie() */

void __thiscall MenuTouchWindow::startValkyrie(MenuTouchWindow *this)

{
  Status *pSVar1;
  Mission *this_00;
  Ship *pSVar2;
  Item *pIVar3;
  Station *pSVar4;
  int iVar5;
  
  Status::resetGame(Globals::status);
  iVar5 = 0x2d;
  do {
    Status::nextCampaignMission(SUB41(Globals::status,0));
    pSVar1 = Globals::status;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  this_00 = operator_new(100);
  Mission::Mission(this_00);
  Status::setMission(pSVar1,this_00);
  pSVar1 = Globals::status;
  pSVar2 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x14),-1);
  Status::setShip(pSVar1,pSVar2);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setRace(pSVar2,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 8));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x14));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,1);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x90),10);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x144));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xcc));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,1);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x158),10);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,2);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x154));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,3);
  Status::setCredits(Globals::status,0);
  pSVar1 = Globals::status;
  pSVar4 = (Station *)Galaxy::getStation(Globals::galaxy,0x5b);
  Status::setStation(pSVar1,pSVar4);
  Status::setSystemVisibility(Globals::status,6,true);
  Status::setSystemVisibility(Globals::status,0x19,true);
  Status::setCredits(Globals::status,0);
  *(undefined4 *)(Globals::status + 0x84) = 0x1a0a;
  Globals::hints[0x17] = 1;
  Globals::hints._8_2_ = 0x101;
  Globals::hints[10] = 1;
  Globals::hints[0x1c] = 1;
  Globals::hints[0x15] = 1;
  Globals::hints[0xd] = 1;
  Globals::hints[0x13] = 1;
  Globals::hints[0xe] = 1;
  Globals::hints[0xf] = 1;
  Globals::hints[0x1d] = 1;
  Globals::hints[0x1e] = 1;
  Globals::hints[0x24] = 1;
  Globals::hints._32_4_ = 0x1010101;
  Globals::hints[0x36] = 0;
  Globals::hints._50_4_ = 0;
  Globals::hints[0x38] = 1;
  Globals::options[0x34] = 1;
  Achievements::setMedal(Globals::achievements,0x17,3);
  Achievements::setMedal(Globals::achievements,0x1e,1);
  RecordHandler::saveOptions(Globals::recordHandler);
  Status::setKills(Globals::status,0xc5);
  FModSound::stop(Globals::sound,*(int *)Globals::sound);
  Globals::options._44_4_ = *(undefined4 *)(this + 0x1a4);
  AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
  return;
}

// ===== MenuTouchWindow::startSupernova  @0x00153e14  (678 bytes)
/* MenuTouchWindow::startSupernova() */

void __thiscall MenuTouchWindow::startSupernova(MenuTouchWindow *this)

{
  Status *pSVar1;
  Ship *pSVar2;
  Item *pIVar3;
  Station *pSVar4;
  int iVar5;
  
  Status::resetGame(Globals::status);
  iVar5 = 0x54;
  do {
    Status::nextCampaignMission(SUB41(Globals::status,0));
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  Status::setMission(Globals::status,Mission::empty);
  pSVar1 = Globals::status;
  pSVar2 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0x78),-1);
  Status::setShip(pSVar1,pSVar2);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setRace(pSVar2,3);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x2c0));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x50));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,1);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x90),0x14);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xb0),0x14);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,1);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x144));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xcc));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,1);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x110));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,2);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x158));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,3);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x154));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,4);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xe0));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,5);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x1e8),8);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::addCargo(pSVar2,pIVar3);
  Status::setCredits(Globals::status,0);
  pSVar1 = Globals::status;
  pSVar4 = (Station *)Galaxy::getStation(Globals::galaxy,0x46);
  Status::setStation(pSVar1,pSVar4);
  Status::setSystemVisibility(Globals::status,6,true);
  Status::setSystemVisibility(Globals::status,0x19,true);
  Status::setCredits(Globals::status,0);
  *(undefined4 *)(Globals::status + 0x84) = 0x1a0a;
  Globals::hints[0x17] = 1;
  Globals::hints._8_2_ = 0x101;
  Globals::hints[10] = 1;
  Globals::hints[0x1c] = 1;
  Globals::hints[0x15] = 1;
  Globals::hints[0xd] = 1;
  Globals::hints[0x13] = 1;
  Globals::hints[0xe] = 1;
  Globals::hints[0xf] = 1;
  Globals::hints[0x26] = 1;
  Globals::hints[0x31] = 1;
  Globals::hints[0x24] = 1;
  Globals::hints._32_4_ = 0x1010101;
  Globals::hints[0x36] = 0;
  Globals::hints._50_4_ = 0;
  Globals::hints[0x1d] = 1;
  Globals::hints[0x1e] = 1;
  Globals::hints[0x38] = 1;
  Globals::hints[0x39] = 1;
  Globals::options[0x34] = 1;
  Achievements::setMedal(Globals::achievements,0x17,3);
  Achievements::setMedal(Globals::achievements,0x1e,1);
  Status::setKills(Globals::status,0x182);
  RecordHandler::saveOptions(Globals::recordHandler);
  FModSound::stop(Globals::sound,*(int *)Globals::sound);
  Globals::options._44_4_ = *(undefined4 *)(this + 0x1a4);
  AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,5);
  return;
}

// ===== MenuTouchWindow::startGOF2  @0x001540f0  (82 bytes)
/* MenuTouchWindow::startGOF2() */

void __thiscall MenuTouchWindow::startGOF2(MenuTouchWindow *this)

{
  float fVar1;
  
  Status::resetGame(Globals::status);
  Globals::options._44_4_ = *(undefined4 *)(this + 0x1a4);
  fVar1 = (float)FModSound::stop(Globals::sound,*(int *)Globals::sound);
  FModSound::play(Globals::sound,0x8f,(Vector *)0x0,(Vector *)0x0,fVar1);
  AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
  return;
}

// ===== MenuTouchWindow::render3D  @0x00154154  (24 bytes)
/* MenuTouchWindow::render3D() */

void __thiscall MenuTouchWindow::render3D(MenuTouchWindow *this)

{
  if (*(int *)(this + 0x16c) != 9) {
    return;
  }
  if (*(MissionsWindow **)(this + 0xfc) == (MissionsWindow *)0x0) {
    return;
  }
  MissionsWindow::render3D(*(MissionsWindow **)(this + 0xfc));
  return;
}

// ===== MenuTouchWindow::isShowingMessage  @0x0015416a  (6 bytes)
/* MenuTouchWindow::isShowingMessage() */

MenuTouchWindow __thiscall MenuTouchWindow::isShowingMessage(MenuTouchWindow *this)

{
  return this[0x170];
}

// ===== MenuTouchWindow::inCinematicMode  @0x00154170  (14 bytes)
/* MenuTouchWindow::inCinematicMode() */

bool __thiscall MenuTouchWindow::inCinematicMode(MenuTouchWindow *this)

{
  return *(int *)(this + 0x16c) == 0xd;
}

// ===== MenuTouchWindow::isMakingScreenshot  @0x0015417e  (16 bytes)
/* MenuTouchWindow::isMakingScreenshot() */

bool __thiscall MenuTouchWindow::isMakingScreenshot(MenuTouchWindow *this)

{
  return *(uint *)(this + 0x184) < 0x80000000;
}

// ===== MenuTouchWindow::hideMessage  @0x0015418e  (8 bytes)
/* MenuTouchWindow::hideMessage() */

void __thiscall MenuTouchWindow::hideMessage(MenuTouchWindow *this)

{
  this[0x170] = (MenuTouchWindow)0x0;
  return;
}

// ===== MenuTouchWindow::setSkipButtonVisible  @0x00154196  (60 bytes)
/* MenuTouchWindow::setSkipButtonVisible(bool) */

void __thiscall MenuTouchWindow::setSkipButtonVisible(MenuTouchWindow *this,bool param_1)

{
  TouchButton *this_00;
  uint *puVar1;
  uint uVar2;
  
  puVar1 = *(uint **)(this + 4);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      this_00 = *(TouchButton **)(puVar1[1] + uVar2 * 4);
      if ((this_00 != (TouchButton *)0x0) && (*(int *)this_00 == 0x12 && *(int *)(this_00 + 4) == 0)
         ) {
        TouchButton::setVisible(this_00,param_1);
        puVar1 = *(uint **)(this + 4);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return;
}

// ===== MenuTouchWindow::callDlcMenu  @0x001541d4  (94 bytes)
/* MenuTouchWindow::callDlcMenu() */

void __thiscall MenuTouchWindow::callDlcMenu(MenuTouchWindow *this)

{
  int iVar1;
  String *pSVar2;
  String *pSVar3;
  ChoiceWindow *this_00;
  
  iVar1 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  *(undefined1 *)(iVar1 + 0x40) = 0;
  iVar1 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  *(undefined1 *)(iVar1 + 0x31) = 1;
  this[0x17a] = (MenuTouchWindow)0x1;
  this[0x170] = (MenuTouchWindow)0x1;
  this_00 = *(ChoiceWindow **)(this + 0x104);
  pSVar2 = (String *)GameText::getText(Globals::gameText,0x47);
  pSVar3 = (String *)GameText::getText(Globals::gameText,0x1a9);
  ChoiceWindow::set(this_00,pSVar2,pSVar3);
  return;
}

// ===== MenuTouchWindow::startSupernovaChallenge  @0x00154238  (660 bytes)
/* MenuTouchWindow::startSupernovaChallenge() */

void MenuTouchWindow::startSupernovaChallenge(void)

{
  Status *pSVar1;
  Ship *pSVar2;
  Item *pIVar3;
  Station *this;
  Mission *pMVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  Status::resetGame(Globals::status);
  Status::setCurrentCampaignMission(Globals::status,0x98);
  pSVar1 = Globals::status;
  pSVar2 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + 0xb8),-1);
  Status::setShip(pSVar1,pSVar2);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x39c));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x398));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,1);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x39c));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,2);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x124));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xd8));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,1);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0xec));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,2);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x14c));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,3);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x338));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,4);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 300));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,5);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x130));
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,6);
  pIVar3 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + 0x360),5);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::setEquipment(pSVar2,pIVar3,0);
  this = (Station *)Galaxy::getStation(Globals::galaxy,0x6f);
  Status::setStation(Globals::status,this);
  pMVar4 = operator_new(100);
  AbyssEngine::String::String(aSStack_24,"Client",false);
  uVar5 = ImageFactory::createChar(Globals::imageFactory,true,0);
  uVar6 = Station::getIndex(this);
  Mission::Mission(pMVar4,0xb7,aSStack_24,uVar5,0,0,uVar6,1);
  AbyssEngine::String::~String(aSStack_24);
  Status::setMission(Globals::status,pMVar4);
  Status::setFreelanceMission(Globals::status,pMVar4);
  Globals::hints[0x17] = 1;
  Globals::hints._8_2_ = 0x101;
  Globals::hints[10] = 1;
  Globals::hints[0x1c] = 1;
  Globals::hints[0x15] = 1;
  Globals::hints[0xd] = 1;
  Globals::hints[0x13] = 1;
  Globals::hints[0xe] = 1;
  Globals::hints[0xf] = 1;
  Globals::hints[0x29] = 1;
  Globals::hints[0x22] = 1;
  Globals::hints._32_2_ = 0x101;
  Status::setKills(Globals::status,500);
  Status::setKills(Globals::status,0xdc);
  FModSound::stop(Globals::sound,*(int *)Globals::sound);
  Globals::switch_to_target_setting = 0xffffffff;
  Globals::enterSpaceLounge = 0;
  Globals::playMusicAndFadeOutCurrent(Globals::globals,1);
  pSVar1 = Globals::status;
  *(undefined4 *)(Globals::status + 0x5c) = 0xffffffff;
  *(undefined4 *)(pSVar1 + 0x60) = 0xffffffff;
  *(undefined4 *)(pSVar1 + 100) = 0xffffffff;
  AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,2);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

