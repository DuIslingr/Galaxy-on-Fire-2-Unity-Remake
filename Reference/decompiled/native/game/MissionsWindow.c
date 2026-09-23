// Class: MissionsWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MissionsWindow::MissionsWindow  @0x0017a5b0  (74 bytes)
/* MissionsWindow::MissionsWindow() */

MissionsWindow * __thiscall MissionsWindow::MissionsWindow(MissionsWindow *this)

{
  int iVar1;
  
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  iVar1 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
  *(int *)(this + 0x1c) = iVar1 / 2 + -1;
  init(this);
  return this;
}

// ===== MissionsWindow::init  @0x0017a604  (2370 bytes)
/* MissionsWindow::init() */

void __thiscall MissionsWindow::init(MissionsWindow *this)

{
  undefined1 *puVar1;
  Status *pSVar2;
  GameText *this_00;
  Layout *pLVar3;
  ImageFactory *this_01;
  uint uVar4;
  Array *pAVar5;
  undefined4 *puVar6;
  TouchButton *pTVar7;
  String *pSVar8;
  int iVar9;
  ScrollTouchWindow *pSVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  Ship *this_02;
  String *this_03;
  Mission *pMVar16;
  undefined4 uVar17;
  Agent *this_04;
  int *piVar18;
  ChoiceWindow *this_05;
  WantedWindow *this_06;
  float *pfVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  void *pvVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  float fVar29;
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
  undefined4 local_48 [2];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (Globals::iPad == '\0') {
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x34) = 0;
    *(int *)(this + 0x38) = Globals::w;
    *(int *)(this + 0x3c) = Globals::h;
  }
  else {
    if (Globals::iPadHD == '\0') {
      pfVar19 = (float *)&DAT_0017b064;
      if (Globals::iPadLarge != '\0') {
        pfVar19 = (float *)&DAT_0017b068;
      }
      uVar4 = 0x28a;
      fVar29 = *pfVar19;
      if (Globals::iPadLarge != '\0') {
        uVar4 = 0x514;
      }
    }
    else {
      uVar4 = 0x392;
      fVar29 = 703.125;
    }
    *(uint *)(this + 0x38) = uVar4;
    *(int *)(this + 0x3c) = (int)fVar29;
    *(uint *)(this + 0x30) = (Globals::w >> 1) - (uVar4 >> 1);
    *(int *)(this + 0x34) = (Globals::h >> 1) - ((int)fVar29 >> 1);
  }
  pAVar5 = operator_new(0xc);
  puVar6 = operator_new__(4);
  *(undefined4 **)(pAVar5 + 4) = puVar6;
  *(undefined4 *)(pAVar5 + 8) = 1;
  *puVar6 = 0;
  *(undefined4 *)pAVar5 = 0;
  *(Array **)(this + 0x14) = pAVar5;
  ArraySetLength<TouchButton*>(2,pAVar5);
  pTVar7 = operator_new(0xc0);
  pSVar8 = (String *)GameText::getText(Globals::gameText,0xc93);
  iVar20 = *(int *)(this + 0x30);
  iVar22 = *(int *)(this + 0x38);
  iVar9 = Layout::getHelpButtonOffset(Globals::layout);
  TouchButton::TouchButton(pTVar7,pSVar8,3,(iVar22 + iVar20) - iVar9,*(int *)(this + 0x34),'\x12');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x14) + 4) + 4) = pTVar7;
  pTVar7 = operator_new(0xc0);
  pSVar8 = (String *)GameText::getText(Globals::gameText,0x81);
  iVar26 = *(int *)(this + 0x30);
  iVar22 = *(int *)(this + 0x38);
  iVar9 = Layout::getHelpButtonOffset(Globals::layout);
  iVar20 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 0x14) + 4) + 4));
  TouchButton::TouchButton
            (pTVar7,pSVar8,3,
             (((iVar22 + iVar26) - iVar9) - iVar20) + *(int *)(Globals::layout + 0x38),
             *(int *)(this + 0x34),'\x12');
  **(undefined4 **)(*(int *)(this + 0x14) + 4) = pTVar7;
  TouchButton::setAlwaysPressed((TouchButton *)**(undefined4 **)(*(int *)(this + 0x14) + 4),true);
  Layout::setWindowDimensions
            (Globals::layout,*(int *)(this + 0x30),*(int *)(this + 0x34),*(int *)(this + 0x38),
             *(int *)(this + 0x3c));
  if (*(Array **)(this + 0x18) != (Array *)0x0) {
    ArrayReleaseClasses<ImagePart*>(*(Array **)(this + 0x18));
    pvVar23 = *(void **)(this + 0x18);
    if (pvVar23 != (void *)0x0) {
      if (*(void **)((int)pvVar23 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar23 + 4));
      }
      operator_delete(pvVar23);
    }
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(ScrollTouchWindow **)this != (ScrollTouchWindow *)0x0) {
    pvVar23 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)this);
    operator_delete(pvVar23);
  }
  *(undefined4 *)this = 0;
  if (*(ScrollTouchWindow **)(this + 4) != (ScrollTouchWindow *)0x0) {
    pvVar23 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 4));
    operator_delete(pvVar23);
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(ChoiceWindow **)(this + 0xc) != (ChoiceWindow *)0x0) {
    pvVar23 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0xc));
    operator_delete(pvVar23);
  }
  *(undefined4 *)(this + 0xc) = 0;
  if (*(TouchButton **)(this + 0x24) != (TouchButton *)0x0) {
    pvVar23 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x24));
    operator_delete(pvVar23);
  }
  *(undefined4 *)(this + 0x24) = 0;
  if (*(TouchButton **)(this + 0x28) != (TouchButton *)0x0) {
    pvVar23 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x28));
    operator_delete(pvVar23);
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(TouchButton **)(this + 0x2c) != (TouchButton *)0x0) {
    pvVar23 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x2c));
    operator_delete(pvVar23);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  pLVar3 = Globals::layout;
  iVar28 = *(int *)(this + 0x34);
  iVar9 = *(int *)(Globals::layout + 0xc);
  iVar20 = *(int *)(Globals::layout + 0x20);
  iVar22 = *(int *)(Globals::layout + 0x2c);
  iVar26 = *(int *)(Globals::layout + 0x5c);
  pSVar10 = operator_new(0x20);
  iVar11 = *(int *)(pLVar3 + 0x10);
  iVar12 = *(int *)(pLVar3 + 0x24);
  iVar25 = *(int *)(pLVar3 + 0x28);
  iVar27 = *(int *)(pLVar3 + 0x2c);
  iVar24 = *(int *)(this + 0x30);
  iVar21 = *(int *)(this + 0x38);
  iVar13 = *(int *)(this + 0x3c);
  iVar14 = Status::gameWon(Globals::status);
  iVar15 = 0;
  iVar22 = iVar9 + iVar28 + iVar20 + iVar26 + iVar22;
  if (iVar14 == 0) {
    iVar15 = *(int *)(Globals::layout + 0x30);
  }
  ScrollTouchWindow::ScrollTouchWindow
            (pSVar10,iVar25 + iVar24,iVar22,(iVar21 >> 1) - (iVar27 + iVar25),
             (((((iVar28 - iVar22) + iVar13) - iVar11) - iVar12) - iVar15) +
             *(int *)(Globals::layout + 0x2c) * -2,false);
  *(ScrollTouchWindow **)this = pSVar10;
  iVar9 = Status::gameWon(Globals::status);
  if ((iVar9 == 1) && (Globals::options[0x37] == '\0' && Globals::options[0x35] == '\0')) {
    iVar9 = Achievements::gotAllGoldMedals(Globals::achievements);
    if (iVar9 == 1) {
      this_02 = (Ship *)Status::getShip(Globals::status);
      iVar9 = Ship::getIndex(this_02);
      if (iVar9 != 8) {
        pSVar10 = *(ScrollTouchWindow **)this;
        AbyssEngine::String::String(aSStack_80,"",false);
        pSVar8 = (String *)GameText::getText(Globals::gameText,0x28a);
        AbyssEngine::String::String(aSStack_88,pSVar8,false);
        ScrollTouchWindow::setText(pSVar10,aSStack_80,aSStack_88);
        AbyssEngine::String::~String(aSStack_88);
        this_03 = aSStack_80;
        goto LAB_0017ab4e;
      }
    }
    pSVar10 = *(ScrollTouchWindow **)this;
    AbyssEngine::String::String(aSStack_90,"",false);
    pSVar8 = (String *)GameText::getText(Globals::gameText,0x29e);
    AbyssEngine::String::String(aSStack_98,pSVar8,false);
    ScrollTouchWindow::setText(pSVar10,aSStack_90,aSStack_98);
    AbyssEngine::String::~String(aSStack_98);
    this_03 = aSStack_90;
    goto LAB_0017ab4e;
  }
  AbyssEngine::String::String(aSStack_30,"",false);
  iVar9 = Status::getCurrentCampaignMission(Globals::status);
  this_00 = Globals::gameText;
  if (iVar9 < 0xa4) {
    iVar9 = Status::getCurrentCampaignMission(Globals::status);
    pSVar8 = (String *)GameText::getText(this_00,*(int *)(&DAT_00258f68 + iVar9 * 4));
    AbyssEngine::String::operator=(aSStack_30,pSVar8);
  }
  pMVar16 = (Mission *)Status::getCampaignMission(Globals::status);
  iVar9 = Mission::getType(pMVar16);
  if (iVar9 == 0xa7) {
LAB_0017a9f0:
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_40,aSStack_30,false);
    pMVar16 = (Mission *)Status::getCampaignMission(Globals::status);
    Mission::getProductionGoodAmount(pMVar16);
    pMVar16 = (Mission *)Status::getCampaignMission(Globals::status);
    Mission::getStatusValue(pMVar16);
    local_48[0] = 0;
    AbyssEngine::String::Set(ZEXT48(local_48));
    uVar17 = AbyssEngine::String::String(aSStack_50,"#Q",false);
    Status::replaceHash(aSStack_38,pSVar2,aSStack_40,local_48,uVar17);
    AbyssEngine::String::operator=(aSStack_30,aSStack_38);
    AbyssEngine::String::~String(aSStack_38);
    AbyssEngine::String::~String(aSStack_50);
    AbyssEngine::String::~String((String *)local_48);
    puVar1 = &stack0x0000009c;
  }
  else {
    pMVar16 = (Mission *)Status::getCampaignMission(Globals::status);
    iVar9 = Mission::getType(pMVar16);
    pSVar2 = Globals::status;
    if (iVar9 == 0xae) goto LAB_0017a9f0;
    AbyssEngine::String::String(aSStack_58,aSStack_30,false);
    Status::getCampaignMission(Globals::status);
    Mission::getTargetStationName();
    uVar17 = AbyssEngine::String::String(aSStack_68,"#",false);
    Status::replaceHash(aSStack_38,pSVar2,aSStack_58,aSStack_60,uVar17);
    AbyssEngine::String::operator=(aSStack_30,aSStack_38);
    AbyssEngine::String::~String(aSStack_38);
    AbyssEngine::String::~String(aSStack_68);
    AbyssEngine::String::~String(aSStack_60);
    puVar1 = &stack0x00000084;
  }
  AbyssEngine::String::~String((String *)(puVar1 + -0xdc));
  pSVar10 = *(ScrollTouchWindow **)this;
  AbyssEngine::String::String(aSStack_70,"",false);
  AbyssEngine::String::String(aSStack_78,aSStack_30,false);
  ScrollTouchWindow::setText(pSVar10,aSStack_70,aSStack_78);
  AbyssEngine::String::~String(aSStack_78);
  AbyssEngine::String::~String(aSStack_70);
  this_03 = aSStack_30;
LAB_0017ab4e:
  AbyssEngine::String::~String(this_03);
  pMVar16 = (Mission *)Status::getFreelanceMission(Globals::status);
  iVar20 = Mission::isEmpty(pMVar16);
  pSVar10 = operator_new(0x20);
  iVar9 = *(int *)(this + 0x38) >> 1;
  iVar26 = *(int *)(Globals::layout + 0x2c);
  iVar11 = *(int *)(this + 0x30) + iVar9 + iVar26;
  if (iVar20 == 1) {
    ScrollTouchWindow::ScrollTouchWindow
              (pSVar10,iVar11,iVar22,(iVar9 - iVar26) - *(int *)(Globals::layout + 0x28),
               ((*(int *)(this + 0x3c) + (*(int *)(this + 0x34) - (iVar22 + iVar26 * 2))) -
               *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0x24),false);
    *(ScrollTouchWindow **)(this + 4) = pSVar10;
    AbyssEngine::String::String(aSStack_a0,"",false);
    pSVar8 = (String *)GameText::getText(Globals::gameText,0xae);
    AbyssEngine::String::String(aSStack_a8,pSVar8,false);
    ScrollTouchWindow::setText(pSVar10,aSStack_a0,aSStack_a8);
    AbyssEngine::String::~String(aSStack_a8);
    puVar1 = &stack0x0000003c;
  }
  else {
    iVar20 = *(int *)(Globals::layout + 0x2d8) + iVar22 + iVar26;
    ScrollTouchWindow::ScrollTouchWindow
              (pSVar10,iVar11,iVar20,(iVar9 - iVar26) - *(int *)(Globals::layout + 0x28),
               (((((*(int *)(this + 0x34) - iVar20) + *(int *)(this + 0x3c)) -
                 *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0x24)) -
               *(int *)(Globals::layout + 0x4c)) - *(int *)(Globals::layout + 0x30),false);
    *(ScrollTouchWindow **)(this + 4) = pSVar10;
    pMVar16 = (Mission *)Status::getFreelanceMission(Globals::status);
    Mission::getAgent(pMVar16);
    Globals::getAgentMissionText((Agent *)aSStack_30);
    pSVar2 = Globals::status;
    AbyssEngine::String::String(aSStack_b0,(Agent *)aSStack_30,false);
    pMVar16 = (Mission *)Status::getFreelanceMission(Globals::status);
    Mission::getReward(pMVar16);
    pMVar16 = (Mission *)Status::getFreelanceMission(Globals::status);
    Mission::getBonus(pMVar16);
    Layout::formatCredits((int)aSStack_b8);
    uVar17 = AbyssEngine::String::String(aSStack_c0,"#C",false);
    Status::replaceHash(aSStack_38,pSVar2,aSStack_b0,aSStack_b8,uVar17);
    AbyssEngine::String::operator=(aSStack_30,aSStack_38);
    AbyssEngine::String::~String(aSStack_38);
    AbyssEngine::String::~String(aSStack_c0);
    AbyssEngine::String::~String(aSStack_b8);
    AbyssEngine::String::~String(aSStack_b0);
    pSVar10 = *(ScrollTouchWindow **)(this + 4);
    AbyssEngine::String::String(aSStack_c8,"",false);
    AbyssEngine::String::String(aSStack_d0,aSStack_30,false);
    ScrollTouchWindow::setText(pSVar10,aSStack_c8,aSStack_d0);
    AbyssEngine::String::~String(aSStack_d0);
    AbyssEngine::String::~String(aSStack_c8);
    this_01 = Globals::imageFactory;
    pMVar16 = (Mission *)Status::getFreelanceMission(Globals::status);
    this_04 = (Agent *)Mission::getAgent(pMVar16);
    piVar18 = (int *)Agent::getImageParts(this_04);
    uVar17 = ImageFactory::loadChar(this_01,piVar18);
    *(undefined4 *)(this + 0x18) = uVar17;
    puVar1 = &stack0x000000ac;
  }
  AbyssEngine::String::~String((String *)(puVar1 + -0xdc));
  iVar20 = *(int *)(this + 0x38);
  iVar22 = *(int *)(Globals::layout + 0x28);
  iVar9 = Status::inAlienOrbit(Globals::status);
  if (iVar9 == 0) {
    iVar22 = ((iVar20 >> 1) - (iVar20 >> 0x1f) >> 1) - iVar22;
    iVar9 = Status::gameWon(Globals::status);
    if (iVar9 == 0) {
      pTVar7 = operator_new(0xc0);
      pSVar8 = (String *)GameText::getText(Globals::gameText,0x1a8);
      TouchButton::TouchButton
                (pTVar7,pSVar8,0,*(int *)(this + 0x30) + *(int *)(Globals::layout + 0x28),
                 (((*(int *)(this + 0x34) + *(int *)(this + 0x3c)) -
                  *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0x24)) -
                 *(int *)(Globals::layout + 0x2c),iVar22,'!','\x04');
      *(TouchButton **)(this + 0x24) = pTVar7;
    }
    pMVar16 = (Mission *)Status::getFreelanceMission(Globals::status);
    iVar9 = Mission::isEmpty(pMVar16);
    if (iVar9 == 0) {
      pTVar7 = operator_new(0xc0);
      pSVar8 = (String *)GameText::getText(Globals::gameText,0x1a8);
      TouchButton::TouchButton
                (pTVar7,pSVar8,0,
                 *(int *)(this + 0x30) + (*(int *)(this + 0x38) >> 1) +
                 *(int *)(Globals::layout + 0x2c),
                 (((*(int *)(this + 0x34) - *(int *)(Globals::layout + 0x2c)) +
                  *(int *)(this + 0x3c)) - *(int *)(Globals::layout + 0x10)) -
                 *(int *)(Globals::layout + 0x24),iVar22,'!','\x04');
      *(TouchButton **)(this + 0x28) = pTVar7;
      iVar9 = AbyssEngine::ApplicationManager::GetCurrentApplicationModule(Globals::appManager);
      if (iVar9 == 5) {
        pTVar7 = operator_new(0xc0);
        pSVar8 = (String *)GameText::getText(Globals::gameText,0x1a7);
        TouchButton::TouchButton
                  (pTVar7,pSVar8,0,
                   *(int *)(this + 0x30) + iVar22 + (*(int *)(this + 0x38) >> 1) +
                   *(int *)(Globals::layout + 0x2c) * 2,
                   (((*(int *)(this + 0x34) - *(int *)(Globals::layout + 0x2c)) +
                    *(int *)(this + 0x3c)) - *(int *)(Globals::layout + 0x10)) -
                   *(int *)(Globals::layout + 0x24),iVar22,'!','\x04');
        *(TouchButton **)(this + 0x2c) = pTVar7;
        TouchButton::setTextColor(pTVar7,-0xd5ff01);
      }
      this_05 = operator_new(0x54);
      ChoiceWindow::ChoiceWindow(this_05);
      *(ChoiceWindow **)(this + 0xc) = this_05;
    }
  }
  this[0x23] = (MissionsWindow)0x0;
  *(undefined4 *)(this + 0x40) = 0;
  iVar9 = Status::wantedBoardAccessible();
  if (iVar9 == 1) {
    if (*(WantedWindow **)(this + 0x10) == (WantedWindow *)0x0) {
      this_06 = operator_new(0x9c);
      WantedWindow::WantedWindow(this_06);
      *(WantedWindow **)(this + 0x10) = this_06;
    }
    else {
      WantedWindow::init(*(WantedWindow **)(this + 0x10));
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MissionsWindow::~MissionsWindow  @0x0017b164  (178 bytes)
/* MissionsWindow::~MissionsWindow() */

MissionsWindow * __thiscall MissionsWindow::~MissionsWindow(MissionsWindow *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0x18) != (Array *)0x0) {
    ArrayReleaseClasses<ImagePart*>(*(Array **)(this + 0x18));
    pvVar1 = *(void **)(this + 0x18);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(Array **)(this + 0x14) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x14));
    pvVar1 = *(void **)(this + 0x14);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x14) = 0;
  if (*(ScrollTouchWindow **)this != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  if (*(ScrollTouchWindow **)(this + 4) != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(ChoiceWindow **)(this + 0xc) != (ChoiceWindow *)0x0) {
    pvVar1 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0xc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc) = 0;
  if (*(TouchButton **)(this + 0x24) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x24));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x24) = 0;
  if (*(TouchButton **)(this + 0x28) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x28));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(TouchButton **)(this + 0x2c) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x2c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  if (*(WantedWindow **)(this + 0x10) != (WantedWindow *)0x0) {
    pvVar1 = (void *)WantedWindow::~WantedWindow(*(WantedWindow **)(this + 0x10));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x10) = 0;
  return this;
}

// ===== MissionsWindow::setHangarUpdate  @0x0017b216  (6 bytes)
/* MissionsWindow::setHangarUpdate(bool) */

void __thiscall MissionsWindow::setHangarUpdate(MissionsWindow *this,bool param_1)

{
  this[0x23] = (MissionsWindow)param_1;
  return;
}

// ===== MissionsWindow::render3D  @0x0017b21c  (36 bytes)
/* MissionsWindow::render3D() */

void __thiscall MissionsWindow::render3D(MissionsWindow *this)

{
  if (*(int *)(this + 0x40) == 1) {
    WantedWindow::render3D(*(WantedWindow **)(this + 0x10));
  }
  if (this[0x22] != (MissionsWindow)0x0) {
    StarMap::render(*(StarMap **)(this + 8));
    return;
  }
  return;
}

// ===== MissionsWindow::draw  @0x0017b240  (1212 bytes)
/* WARNING: Removing unreachable block (ram,0x0017b278) */
/* WARNING: Removing unreachable block (ram,0x0017b29c) */
/* MissionsWindow::draw() */

void __thiscall MissionsWindow::draw(MissionsWindow *this)

{
  PaintCanvas *pPVar1;
  GameText *this_00;
  Layout *pLVar2;
  String *pSVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  Mission *pMVar7;
  Agent *this_01;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(int *)(this + 0x40) == 1) {
    WantedWindow::draw(*(WantedWindow **)(this + 0x10));
    return;
  }
  if (this[0x22] == (MissionsWindow)0x0) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pLVar2 = Globals::layout;
    pSVar3 = (String *)GameText::getText(Globals::gameText,0x81);
    AbyssEngine::String::String(aSStack_30,pSVar3,false);
    Layout::drawHeader(pLVar2,aSStack_30);
    AbyssEngine::String::~String(aSStack_30);
    iVar4 = Status::wantedBoardAccessible();
    if ((iVar4 == 1) && (puVar5 = *(uint **)(this + 0x14), *puVar5 != 0)) {
      uVar9 = 0;
      do {
        TouchButton::draw(*(TouchButton **)(puVar5[1] + uVar9 * 4));
        puVar5 = *(uint **)(this + 0x14);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *puVar5);
    }
    pLVar2 = Globals::layout;
    iVar4 = *(int *)(this + 0x30);
    iVar6 = *(int *)(this + 0x34);
    iVar8 = *(int *)(Globals::layout + 0x20);
    iVar12 = *(int *)(Globals::layout + 0xc);
    iVar10 = *(int *)(Globals::layout + 0x28);
    pSVar3 = (String *)GameText::getText(Globals::gameText,0x22b);
    AbyssEngine::String::String(aSStack_38,pSVar3,false);
    Layout::drawBox(pLVar2,1,iVar10 + iVar4,iVar6 + iVar12 + iVar8);
    AbyssEngine::String::~String(aSStack_38);
    pLVar2 = Globals::layout;
    iVar4 = *(int *)(this + 0x30);
    iVar6 = *(int *)(this + 0x34);
    iVar11 = *(int *)(Globals::layout + 0xc);
    iVar12 = *(int *)(Globals::layout + 0x28);
    iVar8 = *(int *)(Globals::layout + 0x2c);
    iVar10 = *(int *)(Globals::layout + 0x20);
    iVar13 = *(int *)(Globals::layout + 0x5c);
    AbyssEngine::String::String(aSStack_40,"",false);
    Layout::drawBox(pLVar2,5,iVar12 + iVar4,iVar6 + iVar11 + iVar10 + iVar13 + iVar8);
    AbyssEngine::String::~String(aSStack_40);
    ScrollTouchWindow::draw(*(ScrollTouchWindow **)this);
    if (*(TouchButton **)(this + 0x24) != (TouchButton *)0x0) {
      TouchButton::draw(*(TouchButton **)(this + 0x24));
    }
    pLVar2 = Globals::layout;
    iVar4 = *(int *)(this + 0x30);
    iVar6 = *(int *)(this + 0x34);
    iVar8 = *(int *)(Globals::layout + 0x20);
    iVar10 = *(int *)(this + 0x38);
    iVar11 = *(int *)(Globals::layout + 0xc);
    iVar12 = *(int *)(Globals::layout + 0x2c);
    pSVar3 = (String *)GameText::getText(Globals::gameText,0x22c);
    AbyssEngine::String::String(aSStack_48,pSVar3,false);
    Layout::drawBox(pLVar2,1,iVar4 + (iVar10 >> 1) + iVar12,iVar6 + iVar11 + iVar8);
    AbyssEngine::String::~String(aSStack_48);
    pLVar2 = Globals::layout;
    iVar4 = *(int *)(this + 0x30);
    iVar6 = *(int *)(this + 0x34);
    iVar13 = *(int *)(this + 0x38);
    iVar11 = *(int *)(Globals::layout + 0xc);
    iVar12 = *(int *)(Globals::layout + 0x2c);
    iVar8 = *(int *)(Globals::layout + 0x20);
    iVar10 = *(int *)(Globals::layout + 0x5c);
    AbyssEngine::String::String(aSStack_50,"",false);
    Layout::drawBox(pLVar2,5,iVar4 + (iVar13 >> 1) + iVar12,iVar6 + iVar12 + iVar11 + iVar8 + iVar10
                   );
    AbyssEngine::String::~String(aSStack_50);
    pMVar7 = (Mission *)Status::getFreelanceMission(Globals::status);
    if (((pMVar7 != (Mission *)0x0) && (iVar4 = Mission::isEmpty(pMVar7), iVar4 == 0)) &&
       (*(Array **)(this + 0x18) != (Array *)0x0)) {
      ImageFactory::drawChar
                (Globals::imageFactory,*(Array **)(this + 0x18),
                 *(int *)(this + 0x30) + (*(int *)(this + 0x38) >> 1) +
                 *(int *)(Globals::layout + 0x2c),
                 *(int *)(Globals::layout + 0x2c) + *(int *)(this + 0x34) +
                 *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                 *(int *)(Globals::layout + 0x5c),false);
      uVar9 = Globals::font;
      pPVar1 = Globals::Canvas;
      Mission::getAgent(pMVar7);
      Agent::getName();
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar9,aSStack_58,
                 *(int *)(this + 0x30) + (*(int *)(this + 0x38) >> 1) +
                 *(int *)(Globals::layout + 0x2d4) + *(int *)(Globals::layout + 0x2c) * 2,
                 *(int *)(Globals::layout + 0x5c) +
                 *(int *)(Globals::layout + 0xc) +
                 *(int *)(this + 0x34) + *(int *)(Globals::layout + 0x2c) +
                 *(int *)(Globals::layout + 0x20),false);
      AbyssEngine::String::~String(aSStack_58);
      uVar9 = Globals::font;
      pPVar1 = Globals::Canvas;
      Mission::getAgent(pMVar7);
      Agent::getStationName();
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar9,aSStack_58,
                 *(int *)(this + 0x30) + (*(int *)(this + 0x38) >> 1) +
                 *(int *)(Globals::layout + 0x2d4) + *(int *)(Globals::layout + 0x2c) * 2,
                 *(int *)(Globals::layout + 0x20) +
                 *(int *)(this + 0x34) + *(int *)(Globals::layout + 0x2c) +
                 *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x5c) +
                 *(int *)(Globals::layout + 4),false);
      AbyssEngine::String::~String(aSStack_58);
      uVar9 = Globals::font;
      this_00 = Globals::gameText;
      pPVar1 = Globals::Canvas;
      this_01 = (Agent *)Mission::getAgent(pMVar7);
      pMVar7 = (Mission *)Agent::getMission(this_01);
      iVar4 = Mission::getType(pMVar7);
      pSVar3 = (String *)GameText::getText(this_00,iVar4 + 0x162);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar9,pSVar3,
                 *(int *)(this + 0x30) + (*(int *)(this + 0x38) >> 1) +
                 *(int *)(Globals::layout + 0x2d4) + *(int *)(Globals::layout + 0x2c) * 2,
                 *(int *)(Globals::layout + 0x5c) +
                 *(int *)(this + 0x34) + *(int *)(Globals::layout + 0x2c) +
                 *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
                 *(int *)(Globals::layout + 4) * 2,false);
    }
    ScrollTouchWindow::draw(*(ScrollTouchWindow **)(this + 4));
    if (*(TouchButton **)(this + 0x2c) != (TouchButton *)0x0) {
      TouchButton::draw(*(TouchButton **)(this + 0x2c));
    }
    if (*(TouchButton **)(this + 0x28) != (TouchButton *)0x0) {
      TouchButton::draw(*(TouchButton **)(this + 0x28));
    }
    Layout::drawFooter(Globals::layout);
    if ((this[0x21] != (MissionsWindow)0x0) || (this[0x20] != (MissionsWindow)0x0)) {
      ChoiceWindow::draw(*(ChoiceWindow **)(this + 0xc));
    }
    if (__stack_chk_guard == local_28) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  StarMap::draw(*(StarMap **)(this + 8));
  return;
}

// ===== MissionsWindow::hangarNeedsUpdate  @0x0017b79c  (6 bytes)
/* MissionsWindow::hangarNeedsUpdate() */

MissionsWindow __thiscall MissionsWindow::hangarNeedsUpdate(MissionsWindow *this)

{
  return this[0x23];
}

// ===== MissionsWindow::update  @0x0017b7a4  (498 bytes)
/* WARNING: Removing unreachable block (ram,0x0017b7fe) */
/* WARNING: Removing unreachable block (ram,0x0017b7da) */
/* MissionsWindow::update(int) */

void MissionsWindow::update(int param_1)

{
  Status *pSVar1;
  GameText *this;
  Mission *pMVar2;
  int iVar3;
  String *pSVar4;
  uint *puVar5;
  ScrollTouchWindow *pSVar6;
  uint uVar7;
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  undefined4 local_38 [2];
  String aSStack_30 [8];
  String aSStack_28 [8];
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (*(int *)(param_1 + 0x40) == 1) {
    WantedWindow::update(*(int *)(param_1 + 0x10));
    return;
  }
  if (*(char *)(param_1 + 0x22) != '\0') {
    StarMap::update(*(int *)(param_1 + 8));
    return;
  }
  ScrollTouchWindow::update(*(int *)param_1);
  ScrollTouchWindow::update(*(int *)(param_1 + 4));
  pMVar2 = (Mission *)Status::getCampaignMission(Globals::status);
  iVar3 = Mission::getType(pMVar2);
  if (iVar3 != 0xa7) {
    pMVar2 = (Mission *)Status::getCampaignMission(Globals::status);
    iVar3 = Mission::getType(pMVar2);
    if (iVar3 != 0xae) goto LAB_0017b956;
  }
  iVar3 = Status::gameWon(Globals::status);
  if ((iVar3 != 1) || (Globals::options[0x37] != '\0' || Globals::options[0x35] != '\0')) {
    AbyssEngine::String::String(aSStack_20,"",false);
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    this = Globals::gameText;
    if (iVar3 < 0xa4) {
      iVar3 = Status::getCurrentCampaignMission(Globals::status);
      pSVar4 = (String *)GameText::getText(this,*(int *)(&DAT_00258f68 + iVar3 * 4));
      AbyssEngine::String::operator=(aSStack_20,pSVar4);
      pSVar1 = Globals::status;
      AbyssEngine::String::String(aSStack_30,aSStack_20,false);
      pMVar2 = (Mission *)Status::getCampaignMission(Globals::status);
      Mission::getProductionGoodAmount(pMVar2);
      pMVar2 = (Mission *)Status::getCampaignMission(Globals::status);
      Mission::getStatusValue(pMVar2);
      local_38[0] = 0;
      AbyssEngine::String::Set(ZEXT48(local_38));
      AbyssEngine::String::String(aSStack_40,"#Q",false);
      Status::replaceHash(aSStack_28,pSVar1,aSStack_30,local_38);
      AbyssEngine::String::operator=(aSStack_20,aSStack_28);
      AbyssEngine::String::~String(aSStack_28);
      AbyssEngine::String::~String(aSStack_40);
      AbyssEngine::String::~String((String *)local_38);
      AbyssEngine::String::~String(aSStack_30);
      pSVar6 = *(ScrollTouchWindow **)param_1;
      AbyssEngine::String::String(aSStack_48,"",false);
      AbyssEngine::String::String(aSStack_50,aSStack_20,false);
      ScrollTouchWindow::setText(pSVar6,aSStack_48,aSStack_50);
      AbyssEngine::String::~String(aSStack_50);
      AbyssEngine::String::~String(aSStack_48);
    }
    AbyssEngine::String::~String(aSStack_20);
  }
LAB_0017b956:
  puVar5 = *(uint **)(param_1 + 0x14);
  if (*puVar5 != 0) {
    uVar7 = 0;
    do {
      TouchButton::setAlwaysPressed
                (*(TouchButton **)(puVar5[1] + uVar7 * 4),uVar7 == *(uint *)(param_1 + 0x40));
      puVar5 = *(uint **)(param_1 + 0x14);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *puVar5);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MissionsWindow::OnTouchBegin  @0x0017ba28  (196 bytes)
/* MissionsWindow::OnTouchBegin(int, int) */

undefined4 __thiscall MissionsWindow::OnTouchBegin(MissionsWindow *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  if (*(int *)(this + 0x40) == 1) {
    uVar1 = WantedWindow::OnTouchBegin(*(WantedWindow **)(this + 0x10),param_1,param_2);
    return uVar1;
  }
  if ((*(uint *)(this + 0x20) & 0xff) == 0) {
    if ((*(uint *)(this + 0x20) & 0xff0000) == 0) {
      iVar2 = Status::wantedBoardAccessible();
      if ((iVar2 == 1) && (puVar3 = *(uint **)(this + 0x14), *puVar3 != 0)) {
        uVar4 = 0;
        do {
          TouchButton::OnTouchBegin(*(TouchButton **)(puVar3[1] + uVar4 * 4),param_1,param_2);
          puVar3 = *(uint **)(this + 0x14);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar3);
      }
      Layout::OnTouchBegin(Globals::layout,param_1,param_2);
      ScrollTouchWindow::OnTouchBegin(*(int *)this,param_1);
      ScrollTouchWindow::OnTouchBegin(*(int *)(this + 4),param_1);
      if (*(TouchButton **)(this + 0x24) != (TouchButton *)0x0) {
        TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x24),param_1,param_2);
      }
      if (*(TouchButton **)(this + 0x2c) != (TouchButton *)0x0) {
        TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x2c),param_1,param_2);
      }
      if (*(TouchButton **)(this + 0x28) != (TouchButton *)0x0) {
        TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x28),param_1,param_2);
      }
    }
    else {
      StarMap::OnTouchBegin(*(StarMap **)(this + 8),param_1,param_2);
    }
  }
  else {
    ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(this + 0xc),param_1,param_2);
  }
  return 0;
}

// ===== MissionsWindow::OnTouchMove  @0x0017baf4  (196 bytes)
/* MissionsWindow::OnTouchMove(int, int) */

undefined4 __thiscall MissionsWindow::OnTouchMove(MissionsWindow *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  if (*(int *)(this + 0x40) == 1) {
    uVar1 = WantedWindow::OnTouchMove(*(WantedWindow **)(this + 0x10),param_1,param_2);
    return uVar1;
  }
  if ((*(uint *)(this + 0x20) & 0xff) == 0) {
    if ((*(uint *)(this + 0x20) & 0xff0000) == 0) {
      iVar2 = Status::wantedBoardAccessible();
      if ((iVar2 == 1) && (puVar3 = *(uint **)(this + 0x14), *puVar3 != 0)) {
        uVar4 = 0;
        do {
          TouchButton::OnTouchMove(*(TouchButton **)(puVar3[1] + uVar4 * 4),param_1,param_2);
          puVar3 = *(uint **)(this + 0x14);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar3);
      }
      Layout::OnTouchMove(Globals::layout,param_1,param_2);
      ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)this,param_1,param_2);
      ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 4),param_1,param_2);
      if (*(TouchButton **)(this + 0x24) != (TouchButton *)0x0) {
        TouchButton::OnTouchMove(*(TouchButton **)(this + 0x24),param_1,param_2);
      }
      if (*(TouchButton **)(this + 0x2c) != (TouchButton *)0x0) {
        TouchButton::OnTouchMove(*(TouchButton **)(this + 0x2c),param_1,param_2);
      }
      if (*(TouchButton **)(this + 0x28) != (TouchButton *)0x0) {
        TouchButton::OnTouchMove(*(TouchButton **)(this + 0x28),param_1,param_2);
      }
    }
    else {
      StarMap::OnTouchMove(*(StarMap **)(this + 8),param_1,param_2);
    }
  }
  else {
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 0xc),param_1,param_2);
  }
  return 0;
}

// ===== MissionsWindow::OnTouchEnd  @0x0017bbc0  (1170 bytes)
/* MissionsWindow::OnTouchEnd(int, int) */

void __thiscall MissionsWindow::OnTouchEnd(MissionsWindow *this,int param_1,int param_2)

{
  MissionsWindow MVar1;
  Layout *pLVar2;
  undefined4 uVar3;
  int iVar4;
  Ship *pSVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  Mission *pMVar9;
  Agent *pAVar10;
  StarMap *pSVar11;
  String *pSVar12;
  bool bVar13;
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (*(int *)(this + 0x40) == 1) {
    uVar3 = WantedWindow::OnTouchEnd(*(WantedWindow **)(this + 0x10),param_1,param_2);
    if (**(int **)(this + 0x10) == 0) {
      *(undefined4 *)(this + 0x40) = 0;
      **(int **)(this + 0x10) = 1;
    }
    goto LAB_0017c03a;
  }
  if ((*(uint *)(this + 0x20) & 0xff) == 0) {
    uVar6 = *(uint *)(this + 0x20) >> 0x10;
LAB_0017bcc6:
    if ((uVar6 & 0xff) == 0) {
      iVar4 = Status::wantedBoardAccessible();
      if ((iVar4 == 1) && (puVar8 = *(uint **)(this + 0x14), *puVar8 != 0)) {
        uVar6 = 0;
        do {
          iVar4 = TouchButton::OnTouchEnd(*(TouchButton **)(puVar8[1] + uVar6 * 4),param_1,param_2);
          if (iVar4 == 1) {
            *(uint *)(this + 0x40) = uVar6;
          }
          puVar8 = *(uint **)(this + 0x14);
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar8);
      }
      ScrollTouchWindow::OnTouchEnd(*(int *)this,param_1);
      ScrollTouchWindow::OnTouchEnd(*(int *)(this + 4),param_1);
      if ((*(TouchButton **)(this + 0x24) == (TouchButton *)0x0) ||
         (iVar4 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x24),param_1,param_2),
         iVar4 != 1)) {
        if ((*(TouchButton **)(this + 0x2c) != (TouchButton *)0x0) &&
           (iVar4 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x2c),param_1,param_2),
           iVar4 == 1)) {
          pSVar12 = *(String **)(this + 0xc);
          bVar13 = (bool)GameText::getText(Globals::gameText,0x1a2);
          ChoiceWindow::set(pSVar12,bVar13);
          this[0x20] = (MissionsWindow)0x1;
        }
        if ((*(TouchButton **)(this + 0x28) == (TouchButton *)0x0) ||
           (iVar4 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x28),param_1,param_2),
           iVar4 != 1)) {
          iVar4 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
          if (iVar4 == 1) {
            Layout::resetWindowDimensions(Globals::layout);
            uVar3 = 1;
            goto LAB_0017c03a;
          }
          iVar4 = Layout::helpPressed(Globals::layout);
          pLVar2 = Globals::layout;
          if (iVar4 == 1) {
            pSVar12 = (String *)GameText::getText(Globals::gameText,0x27b);
            AbyssEngine::String::String(aSStack_2c,pSVar12,false);
            Layout::initHelpWindow(pLVar2,aSStack_2c);
            AbyssEngine::String::~String(aSStack_2c);
          }
          goto LAB_0017c038;
        }
        iVar4 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
        pSVar11 = *(StarMap **)(iVar4 + 0x10);
        *(StarMap **)(this + 8) = pSVar11;
        if (pSVar11 == (StarMap *)0x0) {
          pSVar11 = operator_new(0x1e8);
          pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
          StarMap::StarMap(pSVar11,true,pMVar9,false,-1);
          iVar4 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
          *(StarMap **)(iVar4 + 0x10) = pSVar11;
          iVar4 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
          *(undefined4 *)(this + 8) = *(undefined4 *)(iVar4 + 0x10);
        }
        else {
          pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
          StarMap::init(pSVar11,true,pMVar9,false,-1);
        }
      }
      else {
        iVar4 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
        pSVar11 = *(StarMap **)(iVar4 + 0x10);
        *(StarMap **)(this + 8) = pSVar11;
        if (pSVar11 == (StarMap *)0x0) {
          pSVar11 = operator_new(0x1e8);
          pMVar9 = (Mission *)Status::getCampaignMission(Globals::status);
          StarMap::StarMap(pSVar11,true,pMVar9,false,-1);
          iVar4 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
          *(StarMap **)(iVar4 + 0x10) = pSVar11;
          iVar4 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
          *(undefined4 *)(this + 8) = *(undefined4 *)(iVar4 + 0x10);
        }
        else {
          pMVar9 = (Mission *)Status::getCampaignMission(Globals::status);
          StarMap::init(pSVar11,true,pMVar9,false,-1);
        }
      }
      this[0x22] = (MissionsWindow)0x1;
      Layout::resetWindowDimensions(Globals::layout);
    }
    else {
      iVar4 = StarMap::OnTouchEnd(*(StarMap **)(this + 8),param_1,param_2);
      if (iVar4 == 1) {
        if (Globals::iPad == '\0') {
          *(undefined4 *)(this + 0x30) = 0;
          *(undefined4 *)(this + 0x34) = 0;
          *(int *)(this + 0x38) = Globals::w;
          *(int *)(this + 0x3c) = Globals::h;
        }
        else {
          if (Globals::iPadHD == '\0') {
            uVar6 = 0x28a;
            bVar13 = Globals::iPadLarge != '\0';
            if (bVar13) {
              uVar6 = 0x514;
            }
            uVar7 = 500;
            *(uint *)(this + 0x38) = uVar6;
            if (bVar13) {
              uVar7 = 1000;
            }
            uVar6 = uVar6 >> 1;
          }
          else {
            uVar6 = 0x1c9;
            *(undefined4 *)(this + 0x38) = 0x392;
            uVar7 = 0x2bf;
          }
          *(uint *)(this + 0x3c) = uVar7;
          *(uint *)(this + 0x30) = (Globals::w >> 1) - uVar6;
          *(uint *)(this + 0x34) = (Globals::h >> 1) - (uVar7 >> 1);
        }
        uVar3 = 0;
        this[0x22] = (MissionsWindow)0x0;
        goto LAB_0017c03a;
      }
    }
  }
  else {
    iVar4 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0xc),param_1,param_2);
    if (iVar4 != 0) {
      if (iVar4 == 1) {
        uVar3 = 0;
        this[0x20] = (MissionsWindow)0x0;
        goto LAB_0017c03a;
      }
      uVar6 = (uint)(byte)this[0x22];
      goto LAB_0017bcc6;
    }
    pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
    iVar4 = Mission::getType(pMVar9);
    if (iVar4 == 0) {
LAB_0017bc74:
      pSVar5 = (Ship *)Status::getShip(Globals::status);
      puVar8 = (uint *)Ship::getCargo(pSVar5);
      if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
        uVar6 = 0;
        do {
          iVar4 = Item::isUnsaleable(*(Item **)(puVar8[1] + uVar6 * 4));
          if ((iVar4 == 1) &&
             (iVar4 = Item::getIndex(*(Item **)(puVar8[1] + uVar6 * 4)), iVar4 == 0x74)) {
            pSVar5 = (Ship *)Status::getShip(Globals::status);
            Ship::removeCargo(pSVar5,*(Item **)(puVar8[1] + uVar6 * 4));
            this[0x23] = (MissionsWindow)0x1;
            break;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar8);
      }
    }
    else {
      pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
      iVar4 = Mission::getType(pMVar9);
      if (iVar4 == 3) goto LAB_0017bc74;
      pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
      iVar4 = Mission::getType(pMVar9);
      if (iVar4 == 5) goto LAB_0017bc74;
      pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
      iVar4 = Mission::getType(pMVar9);
      if (iVar4 == 0xb) {
        Status::setPassengers(Globals::status,0);
      }
    }
    pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
    pAVar10 = (Agent *)Mission::getAgent(pMVar9);
    iVar4 = Agent::isGenericAgent(pAVar10);
    if (iVar4 == 0) {
      pMVar9 = (Mission *)Status::getFreelanceMission(Globals::status);
      pAVar10 = (Agent *)Mission::getAgent(pMVar9);
      Agent::setOfferAccepted(pAVar10,false);
    }
    Status::setFreelanceMission(Globals::status,Mission::empty);
    MVar1 = this[0x23];
    init(this);
    this[0x23] = MVar1;
  }
LAB_0017c038:
  uVar3 = 0;
LAB_0017c03a:
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

