// Class: HangarWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== HangarWindow::HangarWindow  @0x00171630  (114 bytes)
/* HangarWindow::HangarWindow() */

void __thiscall HangarWindow::HangarWindow(HangarWindow *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  this[0x3c] = (HangarWindow)0x0;
  this[0xac] = (HangarWindow)0x0;
  this[0x11e] = (HangarWindow)0x0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  lastTab = 1;
  this[0xd0] = (HangarWindow)0x0;
  this[0x130] = (HangarWindow)0x0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0xae) = 0;
  iVar4 = Globals::layout;
  uVar1 = *(undefined4 *)(Globals::layout + 0x23c);
  uVar2 = *(undefined4 *)(Globals::layout + 0x240);
  uVar3 = *(undefined4 *)(Globals::layout + 0x244);
  *(undefined4 *)(this + 0x100) = *(undefined4 *)(Globals::layout + 0x238);
  *(undefined4 *)(this + 0x104) = uVar1;
  *(undefined4 *)(this + 0x108) = uVar2;
  *(undefined4 *)(this + 0x10c) = uVar3;
  *(undefined4 *)(this + 0x110) = *(undefined4 *)(iVar4 + 0x248);
  *(undefined4 *)(this + 0x114) = *(undefined4 *)(iVar4 + 0x24c);
  *(undefined4 *)(this + 0x118) = *(undefined4 *)(iVar4 + 0x250);
  return;
}

// ===== HangarWindow::~HangarWindow  @0x001716ac  (146 bytes)
/* HangarWindow::~HangarWindow() */

HangarWindow * __thiscall HangarWindow::~HangarWindow(HangarWindow *this)

{
  void *pvVar1;
  
  if (*(HangarList **)(this + 0x14) != (HangarList *)0x0) {
    pvVar1 = (void *)HangarList::~HangarList(*(HangarList **)(this + 0x14));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x14) = 0;
  if (*(ListItemWindow **)(this + 0x18) != (ListItemWindow *)0x0) {
    pvVar1 = (void *)ListItemWindow::~ListItemWindow(*(ListItemWindow **)(this + 0x18));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(ChoiceWindow **)(this + 0x1c) != (ChoiceWindow *)0x0) {
    pvVar1 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0x1c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  if (*(ChoiceWindow **)(this + 0x20) != (ChoiceWindow *)0x0) {
    pvVar1 = (void *)ChoiceWindow::~ChoiceWindow(*(ChoiceWindow **)(this + 0x20));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x20) = 0;
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
  if (*(Array **)(this + 0x24) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x24));
    pvVar1 = *(void **)(this + 0x24);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x24) = 0;
  this[0xc] = (HangarWindow)0x0;
  if (*(void **)(this + 0x30) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x30));
  }
  *(undefined4 *)(this + 0x30) = 0;
  return this;
}

// ===== HangarWindow::initialize  @0x00171740  (3286 bytes)
/* HangarWindow::initialize() */

void __thiscall HangarWindow::initialize(HangarWindow *this)

{
  bool bVar1;
  Station *pSVar2;
  int iVar3;
  HangarList *pHVar4;
  Ship *pSVar5;
  Array *pAVar6;
  Array *pAVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  TouchButton *pTVar10;
  String *pSVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  int *piVar17;
  SolarSystem *pSVar18;
  Status *pSVar19;
  ListItemWindow *this_00;
  ChoiceWindow *pCVar20;
  ushort uVar21;
  HangarWindow HVar22;
  ushort uVar23;
  uint uVar24;
  Item *this_01;
  Array *pAVar25;
  uint in_fpscr;
  float fVar26;
  float fVar27;
  uint local_58;
  uint auStack_54 [2];
  uint local_4c;
  uint local_48;
  uint local_44 [2];
  float local_3c;
  float local_34;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar2 = (Station *)Status::getStation(Globals::status);
  iVar3 = Station::getIndex(pSVar2);
  pSVar19 = Globals::status;
  HVar22 = (HangarWindow)0x0;
  if ((iVar3 == 0x6c) && (*(int *)(Globals::status + 0x114) == 3)) {
    HVar22 = (HangarWindow)0x1;
  }
  this[0x11d] = HVar22;
  Status::calcCargoPrices(pSVar19);
  pHVar4 = operator_new(0xc);
  HangarList::HangarList(pHVar4);
  *(HangarList **)(this + 0x14) = pHVar4;
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  pAVar6 = (Array *)Ship::getCargo(pSVar5);
  pSVar2 = (Station *)Status::getStation(Globals::status);
  pAVar7 = (Array *)Station::getItems(pSVar2);
  uVar8 = Item::mixItems(pAVar6,pAVar7);
  *(undefined4 *)(this + 0x10) = uVar8;
  pHVar4 = *(HangarList **)(this + 0x14);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  pAVar25 = *(Array **)(this + 0x10);
  pSVar2 = (Station *)Status::getStation(Globals::status);
  pAVar6 = (Array *)Station::getShips(pSVar2);
  pAVar7 = (Array *)Status::getBluePrints(Globals::status);
  HangarList::init(pHVar4,pSVar5,pAVar25,pAVar6,pAVar7);
  pAVar6 = operator_new(0xc);
  puVar9 = operator_new__(4);
  *(undefined4 **)(pAVar6 + 4) = puVar9;
  *(undefined4 *)(pAVar6 + 8) = 1;
  *puVar9 = 0;
  *(undefined4 *)pAVar6 = 0;
  *(Array **)(this + 4) = pAVar6;
  ArraySetLength<TouchButton*>(3,pAVar6);
  pTVar10 = operator_new(0xc0);
  pSVar11 = (String *)GameText::getText(Globals::gameText,0x110);
  iVar3 = Globals::w;
  iVar12 = Layout::getHelpButtonOffset(Globals::layout);
  TouchButton::TouchButton(pTVar10,pSVar11,3,iVar3 - iVar12,0,'\x12');
  *(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + 8) = pTVar10;
  pTVar10 = operator_new(0xc0);
  iVar3 = 0xb9;
  if (this[0x11d] != (HangarWindow)0x0) {
    iVar3 = 0xba;
  }
  pSVar11 = (String *)GameText::getText(Globals::gameText,iVar3);
  iVar3 = Globals::w;
  iVar12 = Layout::getHelpButtonOffset(Globals::layout);
  iVar13 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + 8));
  TouchButton::TouchButton
            (pTVar10,pSVar11,3,((iVar3 - iVar12) - iVar13) + *(int *)(Globals::layout + 0x38),0,
             '\x12');
  *(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + 4) = pTVar10;
  pTVar10 = operator_new(0xc0);
  pSVar11 = (String *)GameText::getText(Globals::gameText,0xb7);
  iVar3 = Globals::w;
  iVar12 = Layout::getHelpButtonOffset(Globals::layout);
  iVar13 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + 8));
  iVar14 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + 4));
  TouchButton::TouchButton
            (pTVar10,pSVar11,3,
             (((iVar3 - iVar12) - iVar13) - iVar14) + *(int *)(Globals::layout + 0x38) * 2,0,'\x12')
  ;
  **(undefined4 **)(*(int *)(this + 4) + 4) = pTVar10;
  this[0x11f] = Globals::showNewCreditsMenu;
  puVar15 = operator_new__(0x18);
  *(uint **)(this + 0x30) = puVar15;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x232a,puVar15);
  uVar23 = 0x232b;
  iVar3 = 4;
  do {
    AbyssEngine::PaintCanvas::Image2DCreate
              (Globals::Canvas,uVar23,(uint *)(*(int *)(this + 0x30) + iVar3));
    iVar3 = iVar3 + 4;
    uVar23 = uVar23 + 1;
  } while (iVar3 != 0x18);
  puVar15 = *(uint **)(this + 4);
  if (*puVar15 == 0) {
    uVar16 = 0;
  }
  else {
    uVar24 = 0;
    do {
      if ((int)uVar24 < 10) {
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_x + uVar24 * 4) = (int)local_34;
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_y + uVar24 * 4) = (int)local_3c;
        puVar15 = *(uint **)(this + 4);
      }
      uVar16 = *puVar15;
      uVar24 = uVar24 + 1;
    } while (uVar24 < uVar16);
  }
  Globals::sub_menu_button_count = uVar16;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x52e,(uint *)(this + 0xe8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x544,(uint *)(this + 0xec));
  pAVar6 = operator_new(0xc);
  puVar9 = operator_new__(4);
  *(undefined4 **)(pAVar6 + 4) = puVar9;
  *(undefined4 *)(pAVar6 + 8) = 1;
  *puVar9 = 0;
  *(undefined4 *)pAVar6 = 0;
  *(Array **)(this + 0x24) = pAVar6;
  ArraySetLength<TouchButton*>(0x18,pAVar6);
  local_44[0] = 0xffffffff;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x470,local_44);
  pTVar10 = operator_new(0xc0);
  TouchButton::TouchButton(pTVar10,local_44[0],7,0,0,*(int *)(Globals::layout + 0x60),'\x11','\x04')
  ;
  **(undefined4 **)(*(int *)(this + 0x24) + 4) = pTVar10;
  iVar3 = Status::getCurrentCampaignMission(Globals::status);
  bVar1 = false;
  if (iVar3 == 0x4d) {
    pSVar2 = (Station *)Status::getStation(Globals::status);
    iVar3 = Station::getIndex(pSVar2);
    if (iVar3 == 100) {
      bVar1 = true;
    }
  }
  pTVar10 = operator_new(0xc0);
  iVar3 = 0x12d;
  if (this[0x11d] != (HangarWindow)0x0) {
    iVar3 = 0x14c;
  }
  if (bVar1) {
    iVar3 = 0x14c;
  }
  pSVar11 = (String *)GameText::getText(Globals::gameText,iVar3);
  TouchButton::TouchButton(pTVar10,pSVar11,7,0,0,'\x11');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 4) = pTVar10;
  pTVar10 = operator_new(0xc0);
  pSVar11 = (String *)GameText::getText(Globals::gameText,0x12e);
  TouchButton::TouchButton(pTVar10,pSVar11,7,0,0,'\x11');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 8) = pTVar10;
  local_48 = 0xffffffff;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x533,&local_48);
  pTVar10 = operator_new(0xc0);
  TouchButton::TouchButton(pTVar10,local_48,7,0,0,*(int *)(Globals::layout + 100),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0xc) = pTVar10;
  local_4c = 0xffffffff;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x532,&local_4c);
  pTVar10 = operator_new(0xc0);
  TouchButton::TouchButton(pTVar10,local_4c,7,0,0,*(int *)(Globals::layout + 100),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x10) = pTVar10;
  pTVar10 = operator_new(0xc0);
  pSVar11 = (String *)GameText::getText(Globals::gameText,0x117);
  TouchButton::TouchButton(pTVar10,pSVar11,7,0,0,*(int *)(this + 0x110),'\x11','\x01');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x14) = pTVar10;
  pTVar10 = operator_new(0xc0);
  pSVar11 = (String *)GameText::getText(Globals::gameText,0x11a);
  TouchButton::TouchButton(pTVar10,pSVar11,7,0,0,*(int *)(this + 0x110),'\x11','\x01');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x18) = pTVar10;
  pTVar10 = operator_new(0xc0);
  pSVar11 = (String *)GameText::getText(Globals::gameText,0x11b);
  TouchButton::TouchButton(pTVar10,pSVar11,7,0,0,'\x11');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x1c) = pTVar10;
  pTVar10 = operator_new(0xc0);
  AbyssEngine::String::String((String *)auStack_54,"",false);
  TouchButton::TouchButton
            (pTVar10,(String *)auStack_54,8,0,0,*(int *)(Globals::layout + 0x50),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20) = pTVar10;
  AbyssEngine::String::~String((String *)auStack_54);
  pTVar10 = operator_new(0xc0);
  AbyssEngine::String::String((String *)auStack_54,"",false);
  TouchButton::TouchButton
            (pTVar10,(String *)auStack_54,9,0,0,*(int *)(Globals::layout + 0x50),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24) = pTVar10;
  AbyssEngine::String::~String((String *)auStack_54);
  pTVar10 = operator_new(0xc0);
  pSVar11 = (String *)GameText::getText(Globals::gameText,0x14a);
  TouchButton::TouchButton(pTVar10,pSVar11,7,0,0,*(int *)(Globals::layout + 0x50),'\x11','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x28) = pTVar10;
  pTVar10 = operator_new(0xc0);
  Status::getCredits(Globals::status);
  Layout::formatCredits((int)auStack_54);
  iVar12 = Globals::w;
  iVar3 = Globals::h;
  iVar13 = Layout::getFooterTransitionWidth(Globals::layout);
  TouchButton::TouchButton(pTVar10,(String *)auStack_54,0xb,iVar12,iVar3,iVar13,'\"','\x04');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x2c) = pTVar10;
  AbyssEngine::String::~String((String *)auStack_54);
  HVar22 = this[0x11f];
  pTVar10 = operator_new(0xc0);
  iVar12 = 0;
  iVar3 = 0xc;
  do {
    if (HVar22 == (HangarWindow)0x0) {
      AbyssEngine::String::String((String *)auStack_54,"",false);
      TouchButton::TouchButton
                (pTVar10,(String *)auStack_54,0,0,0,*(int *)(Globals::layout + 0x264),'\x11','\x01')
      ;
      *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar3 * 4) = pTVar10;
      AbyssEngine::String::~String((String *)auStack_54);
      iVar13 = iVar3;
    }
    else {
      AbyssEngine::String::String((String *)auStack_54,"",false);
      TouchButton::TouchButton(pTVar10,(String *)auStack_54,10,0,0,'\x01');
      *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar3 * 4) = pTVar10;
      AbyssEngine::String::~String((String *)auStack_54);
      iVar13 = iVar12 + 0xc;
    }
    TouchButton::setVisible
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar13 * 4),false);
    HVar22 = this[0x11f];
    pTVar10 = operator_new(0xc0);
    iVar12 = iVar12 + 1;
    iVar13 = iVar3 + -0xb;
    iVar3 = iVar3 + 1;
  } while (iVar13 < 5);
  if (HVar22 == (HangarWindow)0x0) {
    AbyssEngine::String::String((String *)auStack_54,"",false);
    TouchButton::TouchButton
              (pTVar10,(String *)auStack_54,0,0,0,*(int *)(Globals::layout + 0x264),'\x11','\x01');
  }
  else {
    AbyssEngine::String::String((String *)auStack_54,"",false);
    TouchButton::TouchButton(pTVar10,(String *)auStack_54,10,0,0,'\x01');
  }
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44) = pTVar10;
  AbyssEngine::String::~String((String *)auStack_54);
  TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44),false);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x233e,(uint *)(this + 0x34));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x233f,(uint *)(this + 0x38));
  pTVar10 = operator_new(0xc0);
  AbyssEngine::String::String((String *)auStack_54,"Autocomplete",false);
  TouchButton::TouchButton(pTVar10,(String *)auStack_54,7,0,0,'\x11');
  *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x5c) = pTVar10;
  AbyssEngine::String::~String((String *)auStack_54);
  local_58 = 0xffffffff;
  auStack_54[0] = 0xffffffff;
  uVar23 = 0x2331;
  iVar3 = 0x12;
  do {
    if (iVar3 == 0x12) {
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x233c,auStack_54);
      uVar21 = 0x233d;
    }
    else {
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar23 - 1,auStack_54);
      uVar21 = uVar23;
    }
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar21,&local_58);
    pTVar10 = operator_new(0xc0);
    TouchButton::TouchButton(pTVar10,auStack_54[0],local_58,0x13,0,0,'\x01');
    *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar3 * 4) = pTVar10;
    TouchButton::setVisible
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar3 * 4),false);
    uVar23 = uVar23 + 2;
    iVar12 = iVar3 + -0x11;
    iVar3 = iVar3 + 1;
  } while (iVar12 < 5);
  uVar8 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x30));
  *(undefined4 *)(this + 0x120) = uVar8;
  iVar3 = TouchButton::getHeight(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x30));
  *(int *)(this + 0x124) = iVar3;
  fVar26 = (float)VectorSignedToFloat(-*(int *)(this + 0x120),(byte)(in_fpscr >> 0x16) & 3);
  fVar27 = (float)VectorSignedToFloat(-iVar3,(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x128) = (int)(fVar26 * 0.1);
  *(int *)(this + 300) = (int)(fVar27 * 0.1);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x475,(uint *)(this + 0x78));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x476,(uint *)(this + 0x7c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x477,(uint *)(this + 0x74));
  uVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x7c));
  *(undefined4 *)(this + 0xdc) = uVar8;
  uVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x7c));
  *(undefined4 *)(this + 0xe0) = uVar8;
  if (((*(int *)(this + 0x10) != 0) &&
      (iVar3 = Status::inBlackMarketSystem(Globals::status), iVar3 == 0)) &&
     (this[0x11d] == (HangarWindow)0x0)) {
    pSVar5 = (Ship *)Status::getShip(Globals::status);
    piVar17 = (int *)Ship::getEquipment(pSVar5);
    iVar3 = 0;
    uVar16 = 0;
    while( true ) {
      uVar24 = **(uint **)(this + 0x10);
      if (piVar17 == (int *)0x0) {
        iVar12 = 0;
      }
      else {
        iVar12 = *piVar17;
      }
      if (iVar12 + uVar24 <= uVar16) break;
      if (uVar16 < uVar24) {
        puVar9 = (undefined4 *)((*(uint **)(this + 0x10))[1] + iVar3);
      }
      else {
        puVar9 = (undefined4 *)(piVar17[1] + (uVar16 - uVar24) * 4);
      }
      this_01 = (Item *)*puVar9;
      if (this_01 != (Item *)0x0) {
        iVar12 = Item::getSinglePrice(this_01);
        iVar13 = Item::getIndex(this_01);
        pSVar19 = Globals::status;
        iVar14 = *(int *)(*(int *)(*(int *)(Globals::status + 0x40) + 4) + iVar13 * 4);
        if ((iVar14 < iVar12) || (iVar14 == 0)) {
          *(int *)(*(int *)(*(int *)(Globals::status + 0x40) + 4) + iVar13 * 4) = iVar12;
          pSVar18 = (SolarSystem *)Status::getSystem(pSVar19);
          uVar8 = SolarSystem::getIndex(pSVar18);
          pSVar19 = Globals::status;
          *(undefined4 *)(*(int *)(*(int *)(Globals::status + 0x48) + 4) + iVar13 * 4) = uVar8;
        }
        iVar14 = *(int *)(*(int *)(*(int *)(pSVar19 + 0x3c) + 4) + iVar13 * 4);
        if ((iVar12 < iVar14) || (iVar14 == 0)) {
          *(int *)(*(int *)(*(int *)(pSVar19 + 0x3c) + 4) + iVar13 * 4) = iVar12;
          pSVar18 = (SolarSystem *)Status::getSystem(pSVar19);
          uVar8 = SolarSystem::getIndex(pSVar18);
          *(undefined4 *)(*(int *)(*(int *)(Globals::status + 0x44) + 4) + iVar13 * 4) = uVar8;
        }
      }
      iVar3 = iVar3 + 4;
      uVar16 = uVar16 + 1;
    }
  }
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  Ship::adjustPrice(pSVar5);
  this_00 = operator_new(0x134);
  ListItemWindow::ListItemWindow(this_00);
  *(ListItemWindow **)(this + 0x18) = this_00;
  pCVar20 = operator_new(0x54);
  ChoiceWindow::ChoiceWindow(pCVar20);
  iVar13 = 0;
  *(ChoiceWindow **)(this + 0x1c) = pCVar20;
  *(undefined4 *)(this + 0x58) = 0;
  pCVar20 = operator_new(0x54);
  ChoiceWindow::ChoiceWindow(pCVar20);
  *(ChoiceWindow **)(this + 0x20) = pCVar20;
  this[0x3c] = (HangarWindow)0x0;
  this[0x11c] = (HangarWindow)0x0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  this[0x130] = (HangarWindow)0x0;
  *(undefined2 *)(this + 0xd1) = 0;
  this[0xb1] = (HangarWindow)0x0;
  *(undefined4 *)(this + 0xad) = 0;
  *(undefined4 *)(this + 0x40) = 0x10;
  *(undefined4 *)(this + 0x44) = 5;
  *(undefined4 *)(this + 0x48) = 5;
  iVar3 = Globals::w;
  iVar12 = Globals::w + -10;
  *(int *)(this + 0x4c) = iVar12;
  *(int *)(this + 0x50) = Globals::h + -10;
  piVar17 = operator_new__(0xc);
  iVar12 = iVar12 / 3 + -2;
  *(int **)(this + 0x54) = piVar17;
  *piVar17 = iVar12;
  piVar17[1] = iVar12;
  piVar17[2] = iVar3 + -0xe + iVar12 * -2;
  HangarList::setCurrentTab(*(int *)(this + 0x14),SUB41(lastTab,0));
  refreshCurrentContentHeight(this);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  uVar8 = Ship::getCurrentLoad(pSVar5);
  *(undefined4 *)(this + 0xa8) = uVar8;
  *(int *)(this + 0xd8) =
       (((Globals::h - *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0xc)) -
       *(int *)(Globals::layout + 0x20)) - *(int *)(Globals::layout + 0x24);
  if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6a4,(uint *)(this + 0xf0));
    fVar26 = (float)VectorSignedToFloat(Globals::w,(byte)(in_fpscr >> 0x16) & 3);
    iVar13 = (int)(fVar26 * 0.2);
  }
  *(int *)(this + 0xf4) = iVar13;
  *(undefined4 *)(this + 0x68) = 0;
  this[0x88] = (HangarWindow)0x0;
  this[0x89] = (HangarWindow)0x0;
  this[0xac] = (HangarWindow)0x0;
  this[0x90] = (HangarWindow)0x0;
  this[0x91] = (HangarWindow)0x0;
  this[0x92] = (HangarWindow)0x0;
  *(undefined4 *)(this + 0xe4) = 0;
  *this = (HangarWindow)0x0;
  *(undefined4 *)(this + 0xc1) = 0;
  *(undefined4 *)(this + 0xc5) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc9) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xcd) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  this[0xc] = (HangarWindow)0x1;
  this[0xf8] = (HangarWindow)0x0;
  *(undefined4 *)(this + 0xfc) = 0xffffffff;
  iVar3 = Status::getCurrentCampaignMission(Globals::status);
  if ((0xd < iVar3) && (Globals::options[0x4e] == '\0')) {
    pCVar20 = *(ChoiceWindow **)(this + 0x20);
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x6d);
    ChoiceWindow::set(pCVar20,pSVar11);
    Globals::options[0x4e] = '\x01';
    RecordHandler::saveOptions(Globals::recordHandler);
    this[0x3c] = (HangarWindow)0x1;
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== HangarWindow::refreshCurrentContentHeight  @0x001725b4  (44 bytes)
/* HangarWindow::refreshCurrentContentHeight() */

void __thiscall HangarWindow::refreshCurrentContentHeight(HangarWindow *this)

{
  int *piVar1;
  
  piVar1 = (int *)HangarList::getCurrentTabItems(*(HangarList **)(this + 0x14));
  if (piVar1 != (int *)0x0) {
    *(int *)(this + 0xd4) =
         *(int *)(this + 0x10c) * (*piVar1 + -1) + *piVar1 * *(int *)(Globals::layout + 0x70);
  }
  return;
}

// ===== HangarWindow::isInitialized  @0x001725e4  (4 bytes)
/* HangarWindow::isInitialized() */

HangarWindow __thiscall HangarWindow::isInitialized(HangarWindow *this)

{
  return this[0xc];
}

// ===== HangarWindow::getCurrentTab  @0x001725e8  (8 bytes)
/* HangarWindow::getCurrentTab() */

void __thiscall HangarWindow::getCurrentTab(HangarWindow *this)

{
  HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
  return;
}

// ===== HangarWindow::listMode  @0x001725ee  (30 bytes)
/* HangarWindow::listMode() */

undefined4 __thiscall HangarWindow::listMode(HangarWindow *this)

{
  undefined4 uVar1;
  
  if (*(int *)(this + 0x58) != 0) {
    return 0;
  }
  uVar1 = 0;
  if ((this[0x89] == (HangarWindow)0x0) && (this[0x3c] == (HangarWindow)0x0)) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== HangarWindow::isInSpecialMode  @0x0017260c  (22 bytes)
/* HangarWindow::isInSpecialMode() */

bool __thiscall HangarWindow::isInSpecialMode(HangarWindow *this)

{
  if (this[0x89] != (HangarWindow)0x0) {
    return true;
  }
  return this[0x3c] != (HangarWindow)0x0;
}

// ===== HangarWindow::getCurrentItem  @0x00172622  (4 bytes)
/* HangarWindow::getCurrentItem() */

undefined4 __thiscall HangarWindow::getCurrentItem(HangarWindow *this)

{
  return *(undefined4 *)(this + 0x68);
}

// ===== HangarWindow::update  @0x00172626  (506 bytes)
/* HangarWindow::update(int) */

void __thiscall HangarWindow::update(HangarWindow *this,int param_1)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  
  if (this[0xc] != (HangarWindow)0x0) {
    *(int *)(this + 8) = param_1;
    if (*(int *)(this + 0x58) == 1) {
      ListItemWindow::update(*(int *)(this + 0x18));
      return;
    }
    uVar2 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
    puVar3 = *(uint **)(this + 4);
    if (*puVar3 != 0) {
      uVar8 = 0;
      do {
        bVar5 = true;
        if ((uVar2 != uVar8) && (uVar8 != 0 || uVar2 != 3)) {
          bVar5 = uVar8 == 2 && uVar2 == 4;
        }
        TouchButton::setAlwaysPressed(*(TouchButton **)(puVar3[1] + uVar8 * 4),bVar5);
        puVar3 = *(uint **)(this + 4);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar3);
    }
    if (this[0xd0] == (HangarWindow)0x0) {
      fVar9 = *(float *)(this + 0xc4) * *(float *)(this + 200);
      fVar10 = -(*(float *)(this + 0xc4) * *(float *)(this + 200));
      if (0.0 < fVar9) {
        fVar10 = fVar9;
      }
      *(float *)(this + 200) = fVar9;
      uVar2 = in_fpscr & 0xfffffff | (uint)(fVar10 < 1.0) << 0x1f | (uint)(fVar10 == 1.0) << 0x1e;
      in_fpscr = uVar2 | (uint)NAN(fVar10) << 0x1c;
      bVar1 = (byte)(uVar2 >> 0x18);
      if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xb4),
                                            (byte)(in_fpscr >> 0x16) & 3);
        *(int *)(this + 0xb4) = (int)(fVar9 + fVar10);
      }
    }
    if (0 < *(int *)(this + 0xb4)) {
      fVar10 = (float)VectorSignedToFloat(-*(int *)(this + 0xb4),(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 200) = fVar10 * 0.5;
      *(undefined4 *)(this + 0xc4) = 0x3f800000;
    }
    iVar4 = HangarList::getCurrentTabItems(*(HangarList **)(this + 0x14));
    if (iVar4 != 0) {
      iVar4 = *(int *)(this + 0xd8) - *(int *)(this + 0xd4);
      if (iVar4 < 0) {
        if (*(int *)(this + 0xb4) < iVar4) {
          fVar10 = (float)VectorSignedToFloat(iVar4 - *(int *)(this + 0xb4),
                                              (byte)(in_fpscr >> 0x16) & 3);
          *(float *)(this + 200) = fVar10 * 0.5;
          *(undefined4 *)(this + 0xc4) = 0x3f800000;
        }
      }
      else {
        *(undefined4 *)(this + 0xb4) = 0;
        *(undefined4 *)(this + 200) = 0;
      }
    }
    if ((this[0x88] != (HangarWindow)0x0) &&
       ((iVar4 = TouchButton::isTouched
                           (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20)),
        iVar4 != 0 ||
        (iVar4 = TouchButton::isTouched
                           (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24)),
        iVar4 == 1)))) {
      iVar4 = *(int *)(this + 0x70);
      iVar7 = 200;
      *(int *)(this + 0x70) = iVar4 + param_1;
      iVar6 = *(int *)(this + 0x6c);
      *(int *)(this + 0x6c) = iVar6 + param_1;
      if (0x5dc < iVar6 + param_1) {
        iVar7 = 0x1e;
      }
      if (iVar7 < iVar4 + param_1) {
        *(undefined4 *)(this + 0x70) = 0;
        if (((*(ushort *)(this + 0x88) & 0xff) != 0) || (0xff < *(ushort *)(this + 0x88))) {
          iVar4 = TouchButton::isTouched
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24));
          if ((iVar4 == 1) &&
             (iVar4 = TouchButton::isVisible
                                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24)),
             iVar4 == 1)) {
            iVar4 = 1;
            iVar6 = 0;
            if (4000 < *(int *)(this + 0x6c)) {
              iVar4 = 5;
            }
            do {
              transaction(this,true);
              iVar6 = iVar6 + 1;
            } while (iVar6 < iVar4);
          }
          else {
            iVar4 = TouchButton::isTouched
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20));
            if ((iVar4 == 1) &&
               (iVar4 = TouchButton::isVisible
                                  (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20)),
               iVar4 == 1)) {
              iVar4 = 1;
              iVar6 = 0;
              if (4000 < *(int *)(this + 0x6c)) {
                iVar4 = 5;
              }
              do {
                transaction(this,false);
                iVar6 = iVar6 + 1;
              } while (iVar6 < iVar4);
            }
          }
        }
      }
    }
  }
  return;
}

// ===== HangarWindow::transaction  @0x00172820  (888 bytes)
/* HangarWindow::transaction(bool) */

void __thiscall HangarWindow::transaction(HangarWindow *this,bool param_1)

{
  Status *pSVar1;
  uint uVar2;
  int iVar3;
  String *pSVar4;
  uint uVar5;
  Ship *pSVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  ChoiceWindow *this_00;
  BluePrint *this_01;
  Item *pIVar10;
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar2 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
  if ((uVar2 | 1) != 1) {
    if (uVar2 == 4) {
      if (param_1) {
        iVar3 = Item::getBlueprintAmount(*(Item **)(*(int *)(this + 0x68) + 0x10));
        this_01 = *(BluePrint **)(this + 0x80);
        iVar9 = Item::getIndex(*(Item **)(*(int *)(this + 0x68) + 0x10));
        iVar9 = BluePrint::getRemainingAmount(this_01,iVar9);
        if (iVar3 < iVar9) {
          iVar3 = Item::transactionBlueprint
                            (SUB41(*(undefined4 *)(*(int *)(this + 0x68) + 0x10),0),0);
          if (iVar3 < 0) {
            *(int *)(this + 0xa8) = *(int *)(this + 0xa8) + 1;
          }
          else if (iVar3 != 0) {
            *(int *)(this + 0x94) = *(int *)(this + 0x94) + 1;
            pSVar6 = (Ship *)Status::getShip(Globals::status);
            Ship::changeLoad(pSVar6,-1);
          }
        }
      }
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      puVar8 = (uint *)Ship::getCargo(pSVar6);
      if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
        uVar2 = 0;
        do {
          iVar3 = Item::getIndex(*(Item **)(puVar8[1] + uVar2 * 4));
          iVar9 = Item::getIndex(*(Item **)(*(int *)(this + 0x68) + 0x10));
          if (iVar3 == iVar9) {
            pIVar10 = *(Item **)(puVar8[1] + uVar2 * 4);
            iVar3 = Item::getAmount(*(Item **)(*(int *)(this + 0x68) + 0x10));
            Item::setAmount(pIVar10,iVar3);
            pIVar10 = *(Item **)(puVar8[1] + uVar2 * 4);
            iVar3 = Item::getBlueprintAmount(*(Item **)(*(int *)(this + 0x68) + 0x10));
            Item::setBlueprintAmount(pIVar10,iVar3);
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < *puVar8);
      }
    }
    goto LAB_00172b80;
  }
  iVar3 = Item::isUnsaleable(*(Item **)(*(int *)(this + 0x68) + 0x10));
  if (iVar3 == 1) {
    this_00 = *(ChoiceWindow **)(this + 0x20);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x143);
    ChoiceWindow::set(this_00,pSVar4);
    this[0x3c] = (HangarWindow)0x1;
    this[0x88] = (HangarWindow)0x0;
    goto LAB_00172b80;
  }
  uVar2 = Item::transaction(*(Item **)(*(int *)(this + 0x68) + 0x10),param_1,*(int *)(this + 0xa8),
                            (bool)this[0x11d]);
  uVar5 = Item::getIndex(*(Item **)(*(int *)(this + 0x68) + 0x10));
  puVar8 = *(uint **)(Globals::status + 0x54);
  if (uVar5 < *puVar8) {
    iVar3 = Item::getIndex(*(Item **)(*(int *)(this + 0x68) + 0x10));
    *(undefined1 *)(puVar8[1] + iVar3) = 1;
  }
  if ((uVar2 < 0x80000000) || (!param_1)) {
    if (uVar2 == 0 && param_1) {
      iVar3 = Status::getCredits(Globals::status);
      iVar9 = Item::getSinglePrice(*(Item **)(*(int *)(this + 0x68) + 0x10));
      pSVar1 = Globals::status;
      if ((iVar3 < iVar9) && (this[0x11d] == (HangarWindow)0x0)) {
        pSVar4 = (String *)GameText::getText(Globals::gameText,0xcb);
        AbyssEngine::String::String(aSStack_38,pSVar4,false);
        Item::getSinglePrice(*(Item **)(*(int *)(this + 0x68) + 0x10));
        Status::getCredits(Globals::status);
        Layout::formatCredits((int)aSStack_48);
        AbyssEngine::String::String(aSStack_40,aSStack_48,false);
        uVar7 = AbyssEngine::String::String(aSStack_50,"#C",false);
        Status::replaceHash(aSStack_30,pSVar1,aSStack_38,aSStack_40,uVar7);
        AbyssEngine::String::~String(aSStack_50);
        AbyssEngine::String::~String(aSStack_40);
        AbyssEngine::String::~String(aSStack_48);
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::String(aSStack_58,"\n\n",false);
        pSVar4 = (String *)GameText::getText(Globals::gameText,0x7c);
        AbyssEngine::operator+((AbyssEngine *)aSStack_48,aSStack_58,pSVar4);
        AbyssEngine::String::operator+=(aSStack_30,aSStack_48);
        AbyssEngine::String::~String(aSStack_48);
        AbyssEngine::String::~String(aSStack_58);
        ChoiceWindow::set(*(String **)(this + 0x20),(bool)((char)&stack0x0000000c + -0x3c));
        this[0xaf] = (HangarWindow)0x1;
        this[0x3c] = (HangarWindow)0x1;
        TouchButton::resetTouch(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20));
        TouchButton::resetTouch(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24));
        AbyssEngine::String::~String(aSStack_30);
        goto LAB_00172b6c;
      }
    }
    if ((0 < (int)uVar2) && (!param_1)) {
      *(int *)(this + 0xa8) = *(int *)(this + 0xa8) + -1;
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      Ship::changeLoad(pSVar6,-1);
    }
  }
  else {
    *(int *)(this + 0xa8) = *(int *)(this + 0xa8) + 1;
    pSVar6 = (Ship *)Status::getShip(Globals::status);
    Ship::changeLoad(pSVar6,1);
    iVar3 = ::ListItem::getIndex(*(ListItem **)(this + 0x68));
    if ((0x83 < iVar3) && (iVar3 = ::ListItem::getIndex(*(ListItem **)(this + 0x68)), iVar3 < 0x9a))
    {
      iVar9 = *(int *)(Globals::status + 0xac);
      iVar3 = ::ListItem::getIndex(*(ListItem **)(this + 0x68));
      *(undefined1 *)(iVar3 + *(int *)(iVar9 + 4) + -0x84) = 1;
    }
  }
LAB_00172b6c:
  if (this[0x11d] == (HangarWindow)0x0) {
    Status::changeCredits(Globals::status,uVar2);
  }
LAB_00172b80:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== HangarWindow::refreshCargoAvailabilityForBlueprints  @0x00172c28  (196 bytes)
/* HangarWindow::refreshCargoAvailabilityForBlueprints() */

void __thiscall HangarWindow::refreshCargoAvailabilityForBlueprints(HangarWindow *this)

{
  int iVar1;
  Ship *this_00;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  ListItem *this_01;
  BluePrint *this_02;
  uint uVar7;
  uint uVar8;
  
  iVar1 = HangarList::getItems(*(HangarList **)(this + 0x14));
  puVar6 = *(uint **)(*(int *)(iVar1 + 4) + 8);
  if ((puVar6 != (uint *)0x0) && (*puVar6 != 0)) {
    uVar8 = 0;
    do {
      this_01 = *(ListItem **)(puVar6[1] + uVar8 * 4);
      this_01[0x45] = (ListItem)0x0;
      if ((this_01 != (ListItem *)0x0) && (iVar1 = ::ListItem::isBluePrint(this_01), iVar1 == 1)) {
        this_02 = *(BluePrint **)(this_01 + 8);
        this_00 = (Ship *)Status::getShip(Globals::status);
        puVar2 = (uint *)Ship::getCargo(this_00);
        puVar3 = (uint *)BluePrint::getIngredientList(this_02);
        if ((puVar2 != (uint *)0x0) && (uVar4 = *puVar3, uVar4 != 0)) {
          iVar1 = *(int *)this_02;
          uVar7 = 0;
          do {
            if ((0 < *(int *)(*(int *)(iVar1 + 4) + uVar7 * 4)) && (*puVar2 != 0)) {
              uVar4 = 0;
              do {
                iVar5 = Item::getIndex(*(Item **)(puVar2[1] + uVar4 * 4));
                uVar4 = uVar4 + 1;
                if (iVar5 == *(int *)(puVar3[1] + uVar7 * 4)) {
                  this_01[0x45] = (ListItem)0x1;
                }
              } while (uVar4 < *puVar2);
              uVar4 = *puVar3;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar4);
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *puVar6);
  }
  return;
}

// ===== HangarWindow::render3D  @0x00172cf0  (14 bytes)
/* HangarWindow::render3D() */

void __thiscall HangarWindow::render3D(HangarWindow *this)

{
  if (*(int *)(this + 0x58) == 1) {
    ListItemWindow::render(*(ListItemWindow **)(this + 0x18));
    return;
  }
  return;
}

// ===== HangarWindow::render  @0x00172d00  (10534 bytes)
/* HangarWindow::render() */

void __thiscall HangarWindow::render(HangarWindow *this)

{
  char cVar1;
  byte bVar2;
  PaintCanvas *pPVar3;
  PaintCanvas *pPVar4;
  GameText *pGVar5;
  uint uVar6;
  Layout *pLVar7;
  ImageFactory *pIVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  Item *pIVar12;
  String *pSVar13;
  Ship *pSVar14;
  Station *this_00;
  Array *pAVar15;
  String *pSVar16;
  float *pfVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  String *pSVar21;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  HangarWindow *pHVar22;
  uint uVar23;
  ListItem *this_01;
  BluePrint *pBVar24;
  TouchButton *pTVar25;
  ChoiceWindow *this_02;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  bool bVar35;
  uint in_fpscr;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  int iVar42;
  undefined8 uVar43;
  int local_124;
  int local_104;
  int local_e4;
  String aSStack_dc [8];
  String aSStack_d4 [8];
  String aSStack_cc [8];
  undefined4 local_c4 [2];
  String aSStack_bc [8];
  String aSStack_b4 [8];
  undefined4 local_ac [2];
  undefined4 local_a4 [2];
  String aSStack_9c [8];
  undefined4 local_94 [2];
  AbyssEngine aAStack_8c [8];
  undefined4 local_84 [2];
  undefined4 local_7c [2];
  String aSStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  String aSStack_4c [8];
  int local_44;
  
  local_44 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar9 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
  cVar1 = '\0';
  if (iVar9 != 0) {
    cVar1 = *(char *)(iVar9 + 0x18);
  }
  if ((iVar9 == 0 || cVar1 == '\0') && (*(int *)(this + 0x58) == 0)) {
    Layout::drawBG(Globals::layout);
    iVar9 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
    puVar10 = (uint *)HangarList::getCurrentTabItems(*(HangarList **)(this + 0x14));
    if (puVar10 != (uint *)0x0) {
      if (*(int *)(this + 0xb4) < 1) {
        fVar36 = (float)VectorSignedToFloat(*(int *)(this + 0xb4),(byte)(in_fpscr >> 0x16) & 3);
        fVar37 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xd4),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar37 = -fVar36 / fVar37;
      }
      else {
        fVar37 = 0.0;
      }
      fVar38 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xd8),(byte)(in_fpscr >> 0x16) & 3)
      ;
      fVar36 = (float)getRelativeScrollHeight(this);
      iVar42 = (int)(fVar36 * fVar38);
      iVar32 = (int)(fVar37 * fVar38);
      iVar30 = Globals::w;
      if (0 < iVar42) {
        iVar30 = (Globals::w - *(int *)(Globals::layout + 0x48)) - *(int *)(Globals::layout + 0x2c);
      }
      iVar30 = iVar30 + (*(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28)) * -2;
      if (iVar9 == 0) {
        iVar27 = *(int *)(Globals::layout + 0x4c) << 1;
      }
      else if (iVar9 == 4 || iVar9 == 1) {
        iVar27 = *(int *)(Globals::layout + 0x50);
      }
      else {
        iVar27 = 0;
      }
      iVar31 = *(int *)(Globals::layout + 0x2cc);
      iVar29 = *(int *)(Globals::layout + 0x4c);
      if ((Globals::iPad != '\0') && (Globals::iPadAssetsWithLowerRes == '\0')) {
        iVar33 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0xf0));
        iVar18 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0xf0));
        iVar19 = __aeabi_idiv(Globals::h,iVar18);
        if (-1 < iVar19) {
          iVar19 = iVar19 + 1;
          iVar28 = 0;
          do {
            AbyssEngine::PaintCanvas::DrawImage2D
                      (Globals::Canvas,*(uint *)(this + 0xf0),
                       (*(int *)(Globals::layout + 0x28) - iVar33) + *(int *)(this + 0xf4),iVar28,
                       '\x01');
            if (iVar42 < 1) {
              iVar26 = 0;
            }
            else {
              iVar26 = *(int *)(Globals::layout + 0x48) + *(int *)(Globals::layout + 0x2c);
            }
            AbyssEngine::PaintCanvas::DrawImage2D
                      (Globals::Canvas,*(uint *)(this + 0xf0),
                       iVar30 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4) + iVar26,
                       iVar28,'\0');
            iVar28 = iVar28 + iVar18;
            iVar19 = iVar19 + -1;
          } while (iVar19 != 0);
        }
      }
      iVar33 = 0;
      iVar29 = iVar29 + iVar31 + iVar27;
      do {
        if ((this[0xd0] == (HangarWindow)0x0) &&
           (pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar33 * 4),
           pTVar25 != (TouchButton *)0x0)) {
          TouchButton::setVisible(pTVar25,false);
        }
        iVar33 = iVar33 + 1;
      } while (iVar33 != 0x18);
      uVar11 = *puVar10;
      if (uVar11 != 0) {
        uVar23 = 0;
        iVar31 = iVar27 + -2;
        do {
          iVar33 = (*(int *)(Globals::layout + 0x70) + *(int *)(this + 0x10c)) * uVar23 +
                   *(int *)(this + 0xb4) +
                   *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc);
          if ((-1 < iVar33) && (iVar33 <= Globals::h)) {
            this_01 = *(ListItem **)(puVar10[1] + uVar23 * 4);
            iVar18 = ::ListItem::isSelectable(this_01);
            if (iVar18 == 1) {
              if ((*(ListItem **)(this + 0x68) == this_01) &&
                 (iVar18 = ::ListItem::isTextButton(this_01), pLVar7 = Globals::layout, iVar18 == 0)
                 ) {
                if ((iVar9 == 0) && (-1 < *(int *)(this_01 + 0x3c))) {
                  pSVar16 = aSStack_4c;
                  iVar19 = *(int *)(this + 0xf4);
                  iVar18 = *(int *)(Globals::layout + 0x28);
                  uVar20 = *(undefined4 *)(Globals::layout + 0x70);
                  AbyssEngine::String::String(pSVar16,"",false);
                  Layout::drawBox(pLVar7,10,iVar19 + iVar18,iVar33,iVar30,uVar20,pSVar16);
                }
                else {
                  pSVar16 = aSStack_54;
                  iVar19 = *(int *)(this + 0xf4);
                  iVar18 = *(int *)(Globals::layout + 0x28);
                  uVar20 = *(undefined4 *)(Globals::layout + 0x70);
                  AbyssEngine::String::String(pSVar16,"",false);
                  Layout::drawBox(pLVar7,4,iVar19 + iVar18,iVar33,iVar30,uVar20,pSVar16);
                }
              }
              else {
                pLVar7 = Globals::layout;
                if ((iVar9 == 0) && (-1 < *(int *)(this_01 + 0x3c))) {
                  pSVar16 = aSStack_5c;
                  iVar19 = *(int *)(this + 0xf4);
                  iVar18 = *(int *)(Globals::layout + 0x28);
                  uVar20 = *(undefined4 *)(Globals::layout + 0x70);
                  AbyssEngine::String::String(pSVar16,"",false);
                  Layout::drawBox(pLVar7,9,iVar19 + iVar18,iVar33,iVar30,uVar20,pSVar16);
                }
                else {
                  pSVar16 = aSStack_64;
                  iVar19 = *(int *)(this + 0xf4);
                  iVar18 = *(int *)(Globals::layout + 0x28);
                  uVar20 = *(undefined4 *)(Globals::layout + 0x70);
                  AbyssEngine::String::String(pSVar16,"",false);
                  Layout::drawBox(pLVar7,3,iVar19 + iVar18,iVar33,iVar30,uVar20,pSVar16);
                }
              }
              AbyssEngine::String::~String(pSVar16);
            }
            AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
            AbyssEngine::String::String(aSStack_6c);
            iVar18 = ::ListItem::isItem(this_01);
            pGVar5 = Globals::gameText;
            if (iVar18 == 1) {
              iVar18 = Item::getIndex(*(Item **)(this_01 + 0x10));
              pSVar21 = (String *)GameText::getText(pGVar5,iVar18 + 0x4fa);
              AbyssEngine::String::operator=(aSStack_6c,pSVar21);
              if (iVar9 == 4 || iVar9 == 1) {
                if (this_01 == *(ListItem **)(this + 0x68)) {
                  iVar18 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
                  if ((iVar18 == 1) ||
                     ((iVar18 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14)),
                      iVar18 == 4 && (iVar18 = ::ListItem::isItem(this_01), iVar18 == 1)))) {
                    if (iVar9 == 1) {
                      iVar18 = Item::getStationAmount(*(Item **)(this_01 + 0x10));
                      iVar19 = Item::getAmount(*(Item **)(this_01 + 0x10));
                    }
                    else {
                      iVar18 = Item::getAmount(*(Item **)(this_01 + 0x10));
                      pBVar24 = *(BluePrint **)(this + 0x80);
                      iVar19 = Item::getIndex(*(Item **)(this_01 + 0x10));
                      iVar19 = BluePrint::getCurrentAmount(pBVar24,iVar19);
                    }
                    if (0 < iVar19) {
                      TouchButton::setPosition
                                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20),
                                 *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28),
                                 *(int *)(this + 0x114) + iVar33,'\x11');
                      TouchButton::setVisible
                                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20),true)
                      ;
                      TouchButton::draw(*(TouchButton **)
                                         (*(int *)(*(int *)(this + 0x24) + 4) + 0x20));
                    }
                    if (0 < iVar18) {
                      TouchButton::setPosition
                                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24),
                                 *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28) + iVar30,
                                 *(int *)(this + 0x114) + iVar33,'\x12');
                      TouchButton::setVisible
                                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24),true)
                      ;
                      TouchButton::draw(*(TouchButton **)
                                         (*(int *)(*(int *)(this + 0x24) + 4) + 0x24));
                    }
                    local_104 = TouchButton::getWidth
                                          (*(TouchButton **)
                                            (*(int *)(*(int *)(this + 0x24) + 4) + 0x24));
                    local_104 = local_104 + *(int *)(Globals::layout + 0x2c);
                  }
                  else {
                    local_104 = 0;
                  }
                  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                  uVar11 = Globals::font;
                  pPVar3 = Globals::Canvas;
                  if (iVar9 != 1) {
                    pSVar21 = (String *)GameText::getText(Globals::gameText,0xb7);
                    uVar6 = Globals::font;
                    pPVar4 = Globals::Canvas;
                    iVar19 = *(int *)(Globals::layout + 0x28);
                    iVar26 = *(int *)(this + 0xf4);
                    iVar28 = *(int *)(this + 0x100);
                    iVar34 = *(int *)(Globals::layout + 0x254);
                    pSVar13 = (String *)GameText::getText(Globals::gameText,0xb7);
                    iVar18 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar4,uVar6,pSVar13);
                    AbyssEngine::PaintCanvas::DrawString
                              (pPVar3,uVar11,pSVar21,
                               ((iVar26 + iVar19 + iVar28) - iVar34) - iVar18 / 2,iVar33 + 2,false);
                    uVar11 = Globals::font;
                    pPVar3 = Globals::Canvas;
                    pSVar21 = (String *)GameText::getText(Globals::gameText,0x10f);
                    uVar6 = Globals::font;
                    pPVar4 = Globals::Canvas;
                    iVar26 = *(int *)(this + 0xf4);
                    iVar28 = *(int *)(this + 0x100);
                    iVar19 = *(int *)(Globals::layout + 600);
                    pSVar13 = (String *)GameText::getText(Globals::gameText,0x10f);
                    iVar18 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar4,uVar6,pSVar13);
                    AbyssEngine::PaintCanvas::DrawString
                              (pPVar3,uVar11,pSVar21,
                               (((iVar30 + iVar26) - iVar28) + iVar19) - iVar18 / 2,iVar33 + 2,false
                              );
                    pIVar12 = *(Item **)(this_01 + 0x10);
                    goto LAB_00174322;
                  }
                  pSVar21 = (String *)GameText::getText(Globals::gameText,0x88);
                  uVar6 = Globals::font;
                  pPVar4 = Globals::Canvas;
                  iVar26 = *(int *)(this + 0xf4);
                  iVar28 = *(int *)(this + 0x100);
                  iVar19 = *(int *)(Globals::layout + 0x28);
                  pSVar13 = (String *)GameText::getText(Globals::gameText,0x88);
                  iVar18 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar4,uVar6,pSVar13);
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar3,uVar11,pSVar21,(iVar26 + iVar19 + iVar28) - iVar18 / 2,
                             iVar33 + 2,false);
                  uVar11 = Globals::font;
                  pPVar3 = Globals::Canvas;
                  pSVar21 = (String *)GameText::getText(Globals::gameText,0xb7);
                  uVar6 = Globals::font;
                  pPVar4 = Globals::Canvas;
                  iVar28 = *(int *)(this + 0xf4);
                  iVar19 = *(int *)(this + 0x100);
                  pSVar13 = (String *)GameText::getText(Globals::gameText,0xb7);
                  iVar18 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar4,uVar6,pSVar13);
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar3,uVar11,pSVar21,((iVar30 + iVar28) - iVar19) - iVar18 / 2,
                             iVar33 + 2,false);
                  pIVar12 = *(Item **)(this_01 + 0x10);
LAB_00174238:
                  iVar18 = Item::getStationAmount(pIVar12);
                  uVar43 = Item::getAmount(*(Item **)(this_01 + 0x10));
                }
                else {
                  pIVar12 = *(Item **)(this_01 + 0x10);
                  local_104 = 0;
                  if (iVar9 == 1) goto LAB_00174238;
LAB_00174322:
                  iVar18 = Item::getAmount(pIVar12);
                  pBVar24 = *(BluePrint **)(this + 0x80);
                  iVar19 = Item::getIndex(*(Item **)(this_01 + 0x10));
                  iVar19 = BluePrint::getCurrentAmount(pBVar24,iVar19);
                  uVar43 = Item::getBlueprintAmount(*(Item **)(this_01 + 0x10));
                  uVar43 = CONCAT44((int)((ulonglong)uVar43 >> 0x20),(int)uVar43 + iVar19);
                }
                local_124 = (int)uVar43;
                local_7c[0] = 0;
                AbyssEngine::String::Set
                          (CONCAT44((int)((ulonglong)uVar43 >> 0x20),(String *)local_7c));
                AbyssEngine::String::String((String *)local_84,"t",false);
                AbyssEngine::operator+
                          ((AbyssEngine *)aSStack_74,(String *)local_7c,(String *)local_84);
                AbyssEngine::String::~String((String *)local_84);
                AbyssEngine::String::~String((String *)local_7c);
                if (iVar9 != 1) {
                  local_94[0] = 0;
                  AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_94));
                  AbyssEngine::String::String(aSStack_9c,"/",false);
                  AbyssEngine::operator+(aAStack_8c,(String *)local_94,aSStack_9c);
                  pBVar24 = *(BluePrint **)(this + 0x80);
                  iVar19 = Item::getIndex(*(Item **)(this_01 + 0x10));
                  uVar20 = BluePrint::getTotalAmount(pBVar24,iVar19);
                  local_a4[0] = 0;
                  AbyssEngine::String::Set(CONCAT44(uVar20,local_a4));
                  AbyssEngine::operator+((AbyssEngine *)local_84,aAStack_8c,(String *)local_a4);
                }
                else {
                  local_84[0] = 0;
                  AbyssEngine::String::Set(CONCAT44(extraout_r1_00,(String *)local_84));
                }
                AbyssEngine::String::String((String *)local_ac,"t",false);
                AbyssEngine::operator+
                          ((AbyssEngine *)local_7c,(String *)local_84,(String *)local_ac);
                AbyssEngine::String::~String((String *)local_ac);
                AbyssEngine::String::~String((String *)local_84);
                if (iVar9 != 1) {
                  AbyssEngine::String::~String((String *)local_a4);
                  AbyssEngine::String::~String((String *)aAStack_8c);
                  AbyssEngine::String::~String(aSStack_9c);
                  AbyssEngine::String::~String((String *)local_94);
                }
                AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                uVar11 = Globals::font;
                pPVar3 = Globals::Canvas;
                if (0 < iVar18) {
                  iVar19 = *(int *)(this + 0xf4);
                  iVar28 = *(int *)(this + 0x100);
                  iVar34 = *(int *)(this + 0x108);
                  iVar26 = *(int *)(Globals::layout + 0x28);
                  iVar18 = AbyssEngine::PaintCanvas::GetTextWidth
                                     (Globals::Canvas,Globals::font,aSStack_74);
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar3,uVar11,aSStack_74,(iVar19 + iVar26 + iVar28 + iVar34) - iVar18,
                             iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1,false);
                }
                uVar11 = Globals::font;
                pPVar3 = Globals::Canvas;
                if ((iVar9 == 4) || (0 < local_124)) {
                  if (iVar9 == 4) {
                    iVar18 = *(int *)(Globals::layout + 0x25c);
                  }
                  else {
                    iVar18 = 0;
                  }
                  iVar26 = *(int *)(this + 0xf4);
                  iVar28 = *(int *)(this + 0x100);
                  iVar34 = *(int *)(this + 0x104);
                  iVar19 = AbyssEngine::PaintCanvas::GetTextWidth
                                     (Globals::Canvas,Globals::font,(String *)local_7c);
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar3,uVar11,(String *)local_7c,
                             (((iVar30 + iVar18 + iVar26) - iVar28) + iVar34) - iVar19,
                             iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1,false);
                }
                AbyssEngine::String::~String((String *)local_7c);
                AbyssEngine::String::~String(aSStack_74);
              }
              else {
                local_104 = 0;
              }
              pPVar3 = Globals::Canvas;
              if (iVar9 == 1) {
                Item::getSinglePrice(*(Item **)(this_01 + 0x10));
                Status::getCredits(Globals::status);
                AbyssEngine::PaintCanvas::SetColor((uint)pPVar3);
              }
              else {
                AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
              }
              uVar11 = Globals::font;
              pPVar3 = Globals::Canvas;
              if (this[0x11d] == (HangarWindow)0x0) {
                Item::getSinglePrice(*(Item **)(this_01 + 0x10));
                Layout::formatCredits((int)aSStack_74);
                AbyssEngine::PaintCanvas::DrawString
                          (pPVar3,uVar11,aSStack_74,
                           iVar29 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4),
                           iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1,false);
                AbyssEngine::String::~String(aSStack_74);
              }
              pIVar8 = Globals::imageFactory;
              iVar18 = Item::getIndex(*(Item **)(this_01 + 0x10));
              iVar19 = Item::getType(*(Item **)(this_01 + 0x10));
              ImageFactory::drawItem
                        (pIVar8,iVar18,iVar19,
                         *(int *)(Globals::layout + 0x28) + iVar27 + *(int *)(this + 0xf4),
                         *(int *)(this + 0x118) + iVar33);
              if ((iVar9 == 1) &&
                 (iVar19 = *(int *)(Globals::status + 0x54),
                 iVar18 = Item::getIndex(*(Item **)(this_01 + 0x10)),
                 *(char *)(*(int *)(iVar19 + 4) + iVar18) == '\0')) {
                AbyssEngine::PaintCanvas::DrawImage2D
                          (Globals::Canvas,*(uint *)(this + 0xec),
                           *(int *)(Globals::layout + 0x28) + iVar31 + *(int *)(this + 0xf4) +
                           *(int *)(Globals::layout + 0x2cc),
                           iVar33 + *(int *)(this + 0x118) + *(int *)(Globals::layout + 0x2d0) + -2,
                           '\x11','\"');
              }
              else {
                if (*(uint *)(this_01 + 0x3c) < 0x80000000) {
LAB_0017464e:
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)(this + 0xe8),
                             *(int *)(Globals::layout + 0x28) + iVar31 + *(int *)(this + 0xf4) +
                             *(int *)(Globals::layout + 0x2cc),
                             iVar33 + *(int *)(this + 0x118) + *(int *)(Globals::layout + 0x2d0) +
                             -2,'\x11','\"');
                }
                else {
                  if (iVar9 == 1) {
                    pSVar14 = (Ship *)Status::getShip(Globals::status);
                    iVar18 = Item::getIndex(*(Item **)(this_01 + 0x10));
                    iVar18 = Ship::hasEquipment(pSVar14,iVar18,1);
                    if (iVar18 == 1) goto LAB_0017464e;
                  }
                  if (iVar9 == 4) {
                    pIVar12 = *(Item **)(this_01 + 0x10);
                    this_00 = (Station *)Status::getStation(Globals::status);
                    pAVar15 = (Array *)Station::getItems(this_00);
                    iVar18 = Item::isInList(pIVar12,pAVar15);
                    if (iVar18 == 1) {
                      AbyssEngine::PaintCanvas::DrawImage2D
                                (Globals::Canvas,*(uint *)(this + 0xe8),
                                 *(int *)(Globals::layout + 0x28) + iVar31 + *(int *)(this + 0xf4) +
                                 *(int *)(Globals::layout + 0x2cc),
                                 iVar33 + *(int *)(this + 0x118) + *(int *)(Globals::layout + 0x2d0)
                                 + -2,'\x11','\"');
                    }
                    goto LAB_00173e6c;
                  }
                }
                if ((iVar9 == 3 || iVar9 == 0) &&
                   (iVar18 = Item::getAmount(*(Item **)(this_01 + 0x10)), 1 < iVar18)) {
                  AbyssEngine::String::String((String *)local_84," (",false);
                  uVar20 = Item::getAmount(*(Item **)(this_01 + 0x10));
                  local_ac[0] = 0;
                  AbyssEngine::String::Set(CONCAT44(uVar20,local_ac));
                  AbyssEngine::operator+
                            ((AbyssEngine *)local_7c,(String *)local_84,(String *)local_ac);
                  AbyssEngine::String::String(aSStack_b4,")",false);
                  AbyssEngine::operator+
                            ((AbyssEngine *)aSStack_74,(AbyssEngine *)local_7c,aSStack_b4);
                  AbyssEngine::String::operator+=(aSStack_6c,(AbyssEngine *)aSStack_74);
                  AbyssEngine::String::~String(aSStack_74);
                  AbyssEngine::String::~String(aSStack_b4);
                  AbyssEngine::String::~String((String *)local_7c);
                  AbyssEngine::String::~String((String *)local_ac);
                  AbyssEngine::String::~String((String *)local_84);
                }
              }
LAB_00173e6c:
              AbyssEngine::PaintCanvas::DrawString
                        (Globals::Canvas,Globals::font,aSStack_6c,
                         *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28) + iVar29,
                         iVar33 + 2,false);
              if (this_01 == *(ListItem **)(this + 0x68)) {
                iVar18 = ::ListItem::isShip(this_01);
                if (iVar18 == 1) {
                  if (iVar9 != 0) {
                    if ((iVar9 == 3) &&
                       (iVar19 = *(int *)(*(int *)(this + 0x68) + 0xc),
                       iVar18 = Status::getShip(Globals::status), iVar19 == iVar18))
                    goto LAB_001749ea;
                    TouchButton::setPosition
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 4),
                               *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28) + iVar30,
                               *(int *)(this + 0x114) + iVar33,'\x12');
                    TouchButton::setVisible
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 4),true);
                    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 4));
                    local_104 = TouchButton::getWidth
                                          (*(TouchButton **)
                                            (*(int *)(*(int *)(this + 0x24) + 4) + 4));
                    local_104 = local_104 + *(int *)(Globals::layout + 0x2c);
                  }
                  if ((iVar9 == 1) && (this[0x11d] != (HangarWindow)0x0)) {
                    TouchButton::setVisible
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 8),true);
                    TouchButton::setPosition
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x28),
                               *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28),
                               *(int *)(this + 0x114) + iVar33,'\x11');
                    TouchButton::setVisible
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x28),true);
                    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x28))
                    ;
                  }
                }
                else if (iVar9 == 2) {
                  iVar18 = ::ListItem::isBluePrint(this_01);
                  if (iVar18 == 1) {
                    TouchButton::setPosition
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x1c),
                               *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28) + iVar30,
                               *(int *)(this + 0x114) + iVar33,'\x12');
                    TouchButton::setVisible
                              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x1c),true);
                    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x1c))
                    ;
                    local_104 = TouchButton::getWidth
                                          (*(TouchButton **)
                                            (*(int *)(*(int *)(this + 0x24) + 4) + 0x1c));
                    local_104 = local_104 + *(int *)(Globals::layout + 0x2c);
                  }
                }
                else if ((iVar9 == 0) && (iVar18 = ::ListItem::isItem(this_01), iVar18 == 1)) {
                  pSVar14 = (Ship *)Status::getShip(Globals::status);
                  iVar18 = Item::getSort(*(Item **)(this_01 + 0x10));
                  pIVar12 = (Item *)Ship::getFirstEquipmentOfSort(pSVar14,iVar18);
                  if (pIVar12 == (Item *)0x0) {
                    uVar11 = 0;
                    bVar35 = false;
                  }
                  else {
                    uVar11 = Item::canBeInstalledMultipleTimes(*(Item **)(this_01 + 0x10));
                    iVar18 = Item::getType(pIVar12);
                    uVar11 = uVar11 ^ 1;
                    if (iVar18 == 3) {
                      iVar18 = Item::getIndex(pIVar12);
                      iVar19 = Item::getIndex(*(Item **)(this_01 + 0x10));
                      bVar35 = iVar18 == iVar19;
                    }
                    else {
                      bVar35 = false;
                    }
                  }
                  if (0x7fffffff < *(uint *)(this_01 + 0x3c)) {
                    pSVar14 = (Ship *)Status::getShip(Globals::status);
                    iVar18 = Item::getType(*(Item **)(this_01 + 0x10));
                    iVar18 = Ship::getFreeSlots(pSVar14,iVar18);
                    if ((iVar18 == 0 && uVar11 == 0) ||
                       ((bVar35 &&
                        (iVar18 = Item::canBeInstalledMultipleTimes(*(Item **)(this_01 + 0x10)),
                        iVar18 == 0)))) goto LAB_001749ea;
                  }
                  iVar18 = 3 - (*(int *)(this_01 + 0x3c) >> 0x1f);
                  TouchButton::setPosition
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar18 * 4),
                             iVar30 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4) +
                             *(int *)(Globals::layout + 0x2c) * -2,*(int *)(this + 0x114) + iVar33,
                             '\x12');
                  TouchButton::setVisible
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar18 * 4),
                             true);
                  TouchButton::draw(*(TouchButton **)
                                     (*(int *)(*(int *)(this + 0x24) + 4) + iVar18 * 4));
                  local_104 = TouchButton::getWidth
                                        (*(TouchButton **)
                                          (*(int *)(*(int *)(this + 0x24) + 4) + iVar18 * 4));
                  local_104 = local_104 + *(int *)(Globals::layout + 0x2c) * 2;
                }
LAB_001749ea:
                iVar18 = ::ListItem::isItem(this_01);
                if ((((iVar18 != 0) || (iVar18 = ::ListItem::isShip(this_01), iVar18 != 0)) ||
                    (iVar18 = ::ListItem::isBluePrint(this_01), iVar18 != 0)) ||
                   (iVar18 = ::ListItem::isPendingProduct(this_01), iVar18 == 1)) {
                  TouchButton::setPosition
                            ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x24) + 4),
                             *(int *)(this + 0xf4) +
                             *(int *)(Globals::layout + 0x28) + (iVar30 - local_104),
                             *(int *)(this + 0x114) + iVar33,'\x12');
                  TouchButton::setVisible
                            ((TouchButton *)**(undefined4 **)(*(int *)(this + 0x24) + 4),true);
                  TouchButton::draw((TouchButton *)**(undefined4 **)(*(int *)(this + 0x24) + 4));
                }
              }
            }
            else {
              iVar18 = ::ListItem::isShip(this_01);
              pGVar5 = Globals::gameText;
              if (iVar18 == 1) {
                iVar18 = Ship::getIndex(*(Ship **)(this_01 + 0xc));
                pSVar21 = (String *)GameText::getText(pGVar5,iVar18 + 0x391);
                AbyssEngine::String::operator=(aSStack_6c,pSVar21);
                AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                uVar11 = Globals::font;
                pPVar3 = Globals::Canvas;
                if ((iVar9 == 1) && (this[0x11d] != (HangarWindow)0x0)) {
                  Ship::getPrice(*(Ship **)(this_01 + 0xc));
                  Layout::formatCredits((int)aSStack_74);
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar3,uVar11,aSStack_74,
                             iVar29 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4),
                             iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1,false);
LAB_001739ea:
                  AbyssEngine::String::~String(aSStack_74);
                }
                else {
                  if ((iVar9 != 1) && ((int)uVar23 < 2)) {
                    Ship::getPrice(*(Ship **)(this_01 + 0xc));
                    Layout::formatCredits((int)aSStack_74);
                    AbyssEngine::PaintCanvas::DrawString
                              (pPVar3,uVar11,aSStack_74,
                               iVar29 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4),
                               iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1,false);
                    goto LAB_001739ea;
                  }
                  Ship::getPrice(*(Ship **)(this_01 + 0xc));
                  pSVar14 = (Ship *)Status::getShip(Globals::status);
                  Ship::getPrice(pSVar14);
                  Status::getCredits(Globals::status);
                  AbyssEngine::PaintCanvas::SetColor((uint)pPVar3);
                  uVar11 = Globals::font;
                  pPVar3 = Globals::Canvas;
                  Ship::getPrice(*(Ship **)(this_01 + 0xc));
                  pSVar14 = (Ship *)Status::getShip(Globals::status);
                  Ship::getPrice(pSVar14);
                  Layout::formatCredits((int)aSStack_74);
                  AbyssEngine::PaintCanvas::DrawString
                            (pPVar3,uVar11,aSStack_74,
                             iVar29 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4),
                             iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1,false);
                  AbyssEngine::String::~String(aSStack_74);
                }
                pIVar8 = Globals::imageFactory;
                iVar18 = Ship::getIndex(*(Ship **)(this_01 + 0xc));
                ImageFactory::drawShip
                          (pIVar8,iVar18,
                           *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28) + iVar27,
                           *(int *)(this + 0x118) + iVar33);
                AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
LAB_00173e68:
                local_104 = 0;
                goto LAB_00173e6c;
              }
              iVar18 = ::ListItem::isSlot(this_01);
              if (iVar18 == 1) {
                pSVar21 = (String *)GameText::getText(Globals::gameText,0xae);
                AbyssEngine::String::operator=(aSStack_6c,pSVar21);
                if ((iVar9 == 4) && (uVar23 == *puVar10 - 1)) {
                  TouchButton::setPosition
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x5c),
                             *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28) + iVar30 / 2,
                             *(int *)(this + 0x114) + iVar33,'\x14');
                  TouchButton::setVisible
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x5c),true);
                  TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x5c));
                  AbyssEngine::String::String(aSStack_74,"",false);
                  AbyssEngine::String::operator=(aSStack_6c,aSStack_74);
                  AbyssEngine::String::~String(aSStack_74);
                }
                goto LAB_00173e68;
              }
              iVar18 = ::ListItem::isBluePrint(this_01);
              pGVar5 = Globals::gameText;
              if (iVar18 == 1) {
                iVar18 = BluePrint::getIndex(*(BluePrint **)(this_01 + 8));
                pSVar21 = (String *)GameText::getText(pGVar5,iVar18 + 0x4fa);
                AbyssEngine::String::operator=(aSStack_6c,pSVar21);
                fVar36 = (float)BluePrint::getCompletionRate(*(BluePrint **)(this_01 + 8));
                uVar11 = in_fpscr & 0xfffffff | (uint)(fVar36 < 0.0) << 0x1f |
                         (uint)(fVar36 == 0.0) << 0x1e;
                in_fpscr = uVar11 | (uint)NAN(fVar36) << 0x1c;
                bVar2 = (byte)(uVar11 >> 0x18);
                if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
                  fVar36 = (float)BluePrint::getCompletionRate(*(BluePrint **)(this_01 + 8));
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)(this + 0x78),
                             *(int *)(Globals::layout + 0x28) + iVar29 + 2 + *(int *)(this + 0xf4),
                             iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1);
                  fVar37 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xdc),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  AbyssEngine::PaintCanvas::DrawRegion2D
                            (Globals::Canvas,*(uint *)(this + 0x7c),0,0,(int)(fVar36 * fVar37),
                             *(int *)(this + 0xe0),(float)(int)(fVar36 * fVar37),0,0,0,
                             *(int *)(Globals::layout + 0x28) + iVar29 + 3 + *(int *)(this + 0xf4));
                  fVar37 = (float)VectorSignedToFloat(*(int *)(this + 0xdc) + -4,
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)(this + 0x74),
                             *(int *)(this + 0xf4) +
                             *(int *)(Globals::layout + 0x28) + iVar29 + 5 + (int)(fVar36 * fVar37),
                             iVar33 + 2 + *(int *)(Globals::layout + 0x70) / 2,'\x11','\x14');
                  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                  local_ac[0] = 0;
                  AbyssEngine::String::Set(CONCAT44(extraout_r1,local_ac));
                  AbyssEngine::String::String(aSStack_b4,"%  (",false);
                  AbyssEngine::operator+((AbyssEngine *)local_7c,(String *)local_ac,aSStack_b4);
                  AbyssEngine::operator+
                            ((AbyssEngine *)aSStack_74,(AbyssEngine *)local_7c,
                             (String *)(*(int *)(this_01 + 8) + 0x14));
                  AbyssEngine::String::String(aSStack_bc,")",false);
                  AbyssEngine::operator+
                            ((AbyssEngine *)local_84,(AbyssEngine *)aSStack_74,aSStack_bc);
                  AbyssEngine::String::~String(aSStack_bc);
                  AbyssEngine::String::~String(aSStack_74);
                  AbyssEngine::String::~String((String *)local_7c);
                  AbyssEngine::String::~String(aSStack_b4);
                  AbyssEngine::String::~String((String *)local_ac);
                  AbyssEngine::PaintCanvas::DrawString
                            (Globals::Canvas,Globals::font,(AbyssEngine *)local_84,
                             iVar29 + 2 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4) +
                             *(int *)(this + 0xdc) + *(int *)(Globals::layout + 0x2c),
                             *(int *)(Globals::layout + 0x260) +
                             iVar33 + *(int *)(Globals::layout + 0x70) / 2 + *(int *)(this + 0x114),
                             false);
                  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                  AbyssEngine::String::~String((String *)local_84);
                }
                pIVar8 = Globals::imageFactory;
                iVar19 = BluePrint::getIndex(*(BluePrint **)(this_01 + 8));
                iVar18 = Globals::items;
                iVar28 = BluePrint::getIndex(*(BluePrint **)(this_01 + 8));
                iVar18 = Item::getType(*(Item **)(*(int *)(iVar18 + 4) + iVar28 * 4));
                ImageFactory::drawItem
                          (pIVar8,iVar19,iVar18,
                           *(int *)(Globals::layout + 0x28) + iVar27 + *(int *)(this + 0xf4),
                           *(int *)(this + 0x118) + iVar33);
                if (this_01[0x45] != (ListItem)0x0) {
                  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                }
                goto LAB_00173e68;
              }
              uVar43 = ::ListItem::isPendingProduct(this_01);
              if ((int)uVar43 == 1) {
                bVar35 = *(int *)(*(int *)(this_01 + 0x18) + 0xc) < 2;
                if (bVar35) {
                  AbyssEngine::String::String((String *)local_7c,"",false);
                }
                else {
                  local_c4[0] = 0;
                  AbyssEngine::String::Set(CONCAT44((int)((ulonglong)uVar43 >> 0x20),local_c4));
                  AbyssEngine::String::String(aSStack_cc,"x ",false);
                  AbyssEngine::operator+((AbyssEngine *)local_7c,(String *)local_c4,aSStack_cc);
                }
                pSVar21 = (String *)
                          GameText::getText(Globals::gameText,
                                            *(int *)(*(int *)(this_01 + 0x18) + 0x10) + 0x4fa);
                AbyssEngine::operator+((AbyssEngine *)aSStack_74,(String *)local_7c,pSVar21);
                AbyssEngine::String::operator=(aSStack_6c,(AbyssEngine *)aSStack_74);
                AbyssEngine::String::~String(aSStack_74);
                AbyssEngine::String::~String((String *)local_7c);
                if (!bVar35) {
                  AbyssEngine::String::~String(aSStack_cc);
                  AbyssEngine::String::~String((String *)local_c4);
                }
                AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                uVar11 = Globals::font;
                pPVar3 = Globals::Canvas;
                pSVar21 = (String *)GameText::getText(Globals::gameText,0x113);
                AbyssEngine::String::String((String *)local_84," ",false);
                AbyssEngine::operator+((AbyssEngine *)local_7c,pSVar21,(String *)local_84);
                AbyssEngine::operator+
                          ((AbyssEngine *)aSStack_74,(AbyssEngine *)local_7c,
                           *(String **)(this_01 + 0x18));
                AbyssEngine::PaintCanvas::DrawString
                          (pPVar3,uVar11,(AbyssEngine *)aSStack_74,
                           iVar29 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4),
                           iVar33 + *(int *)(Globals::layout + 0x70) / 2 + 1,false);
                AbyssEngine::String::~String(aSStack_74);
                AbyssEngine::String::~String((String *)local_7c);
                AbyssEngine::String::~String((String *)local_84);
                AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
                pIVar8 = Globals::imageFactory;
                iVar19 = *(int *)(*(int *)(this_01 + 0x18) + 0x10);
                iVar18 = Item::getType(*(Item **)(*(int *)(Globals::items + 4) + iVar19 * 4));
                ImageFactory::drawItem
                          (pIVar8,iVar19,iVar18,
                           iVar27 + *(int *)(Globals::layout + 0x28) + *(int *)(this + 0xf4),
                           *(int *)(this + 0x118) + iVar33);
                goto LAB_00173e68;
              }
              iVar18 = ::ListItem::isMoveToCargoButton(this_01);
              if (iVar18 == 1) {
                TouchButton::setPosition
                          (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x18),
                           *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28),iVar33,'\x11');
                TouchButton::setVisible
                          (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x18),true);
                TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x18));
              }
              else {
                iVar18 = ::ListItem::isSellButton(this_01);
                pLVar7 = Globals::layout;
                if (iVar18 == 1) {
                  TouchButton::setPosition
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x14),
                             *(int *)(this + 0xf4) + *(int *)(Globals::layout + 0x28),iVar33,'\x11')
                  ;
                  TouchButton::setVisible
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x14),true);
                  TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x14));
                }
                else {
                  iVar18 = *(int *)(Globals::layout + 0x1c);
                  iVar19 = *(int *)(this + 0xf4);
                  iVar26 = *(int *)(Globals::layout + 0x28);
                  iVar28 = *(int *)(Globals::layout + 0x70);
                  AbyssEngine::String::String(aSStack_d4,*(String **)(this_01 + 0x1c),false);
                  Layout::drawBox(pLVar7,0,iVar19 + iVar26,(iVar33 + iVar28) - iVar18,iVar30,iVar18,
                                  aSStack_d4);
                  AbyssEngine::String::~String(aSStack_d4);
                }
              }
            }
            AbyssEngine::String::~String(aSStack_6c);
            uVar11 = *puVar10;
          }
          uVar23 = uVar23 + 1;
        } while (uVar23 < uVar11);
      }
      iVar9 = iVar42;
      if (iVar42 < 1) {
        iVar9 = iVar32 + -1;
      }
      if (iVar9 < 0 == (iVar42 < 1 && SBORROW4(iVar32,1))) {
        Layout::drawScrollBar
                  (Globals::layout,
                   ((Globals::w - *(int *)(Globals::layout + 0x48)) -
                   *(int *)(Globals::layout + 0x28)) - *(int *)(this + 0xf4),
                   *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc),
                   *(int *)(this + 0xd8),iVar32,iVar42);
      }
    }
    pLVar7 = Globals::layout;
    pSVar21 = (String *)GameText::getText(Globals::gameText,0xa7);
    AbyssEngine::String::String(aSStack_dc,pSVar21,false);
    Layout::drawHeader(pLVar7,aSStack_dc);
    AbyssEngine::String::~String(aSStack_dc);
    puVar10 = *(uint **)(this + 4);
    if (*puVar10 != 0) {
      uVar11 = 0;
      do {
        TouchButton::draw(*(TouchButton **)(puVar10[1] + uVar11 * 4));
        puVar10 = *(uint **)(this + 4);
        uVar11 = uVar11 + 1;
      } while (uVar11 < *puVar10);
    }
  }
  pHVar22 = this + 0x58;
  if (*(int *)pHVar22 == 1) {
    *(undefined4 *)pHVar22 = 0;
    render(this);
    *(undefined4 *)pHVar22 = 1;
    ListItemWindow::draw(*(ListItemWindow **)(this + 0x18));
  }
  Layout::drawFooter(Globals::layout);
  TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x2c),true);
  TouchButton::setAlwaysPressed
            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x2c),
             Globals::options[0x4e] == '\0');
  pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x2c);
  Status::getCredits(Globals::status);
  Layout::formatCredits((int)aSStack_6c);
  TouchButton::setText(pTVar25,aSStack_6c);
  AbyssEngine::String::~String(aSStack_6c);
  TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x2c));
  if (this[0x3c] == (HangarWindow)0x0) goto LAB_001758c2;
  ChoiceWindow::draw(*(ChoiceWindow **)(this + 0x20));
  if (this[0xae] == (HangarWindow)0x0) {
    if (this[0xb0] != (HangarWindow)0x0) {
      iVar27 = 0x48;
      iVar31 = 0;
      iVar30 = (*(int **)(this + 0x20))[1];
      iVar32 = *(int *)(Globals::layout + 8);
      iVar9 = *(int *)(Globals::layout + 0x2c);
      iVar29 = *(int *)(Globals::layout + 0x28) + **(int **)(this + 0x20);
      iVar42 = 0;
      do {
        pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar27);
        if ((((iVar27 == 0x48) || ((iVar27 == 0x4c && (Globals::options[0x49] != '\0')))) ||
            ((iVar27 == 0x50 && ((Globals::options._74_2_ & 0xff) != 0)))) ||
           ((iVar27 == 0x54 && (0xff < (ushort)Globals::options._74_2_)))) {
          bVar35 = false;
        }
        else {
          bVar35 = iVar27 != 0x58 || Globals::options[0x4c] == '\0';
        }
        TouchButton::setVisible(pTVar25,bVar35);
        iVar33 = (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30)) * iVar31 +
                 iVar30 + iVar32 + iVar9 * 2;
        TouchButton::setPosition(pTVar25,iVar29,iVar33);
        TouchButton::draw(pTVar25);
        if (bVar35 != false) {
          iVar18 = TouchButton::getWidth(pTVar25);
          iVar19 = *(int *)(Globals::layout + 0x2c);
          uVar20 = TouchButton::getHeight(pTVar25);
          AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
          uVar11 = Globals::font;
          pPVar3 = Globals::Canvas;
          fVar36 = (float)VectorSignedToFloat(uVar20,(byte)(in_fpscr >> 0x16) & 3);
          fVar37 = (float)VectorSignedToFloat(iVar33,(byte)(in_fpscr >> 0x16) & 3);
          iVar33 = (int)(fVar37 + fVar36 * 0.2);
          iVar19 = iVar18 + iVar29 + iVar19;
          if (iVar27 == 0x48) {
            pSVar21 = (String *)GameText::getText(Globals::gameText,0xd48);
            AbyssEngine::PaintCanvas::DrawString(pPVar3,uVar11,pSVar21,iVar19,iVar33,false);
          }
          else {
            pSVar21 = (String *)GameText::getText(Globals::gameText,iVar42 + 0x70);
            AbyssEngine::PaintCanvas::DrawString(pPVar3,uVar11,pSVar21,iVar19,iVar33,false);
          }
          AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
          uVar11 = Globals::font;
          pPVar3 = Globals::Canvas;
          if (iVar27 == 0x48) {
            pSVar16 = aSStack_6c;
            AbyssEngine::String::String(pSVar16,"",false);
            AbyssEngine::PaintCanvas::DrawString
                      (pPVar3,uVar11,pSVar16,iVar19,*(int *)(Globals::layout + 4) + iVar33,false);
          }
          else {
            AbyssEngine::String::String((String *)local_7c,"(+",false);
            Layout::formatCredits((int)local_84);
            AbyssEngine::operator+((AbyssEngine *)aSStack_74,(String *)local_7c,(String *)local_84);
            AbyssEngine::String::String((String *)local_ac,")",false);
            AbyssEngine::operator+((AbyssEngine *)aSStack_6c,aSStack_74,(String *)local_ac);
            AbyssEngine::PaintCanvas::DrawString
                      (pPVar3,uVar11,(AbyssEngine *)aSStack_6c,iVar19,
                       *(int *)(Globals::layout + 4) + iVar33,false);
            AbyssEngine::String::~String(aSStack_6c);
            AbyssEngine::String::~String((String *)local_ac);
            AbyssEngine::String::~String(aSStack_74);
            AbyssEngine::String::~String((String *)local_84);
            pSVar16 = (String *)local_7c;
          }
          AbyssEngine::String::~String(pSVar16);
          iVar31 = iVar31 + 1;
        }
        iVar42 = iVar42 + 1;
        iVar27 = iVar27 + 4;
      } while (iVar42 < 5);
    }
    goto LAB_001758c2;
  }
  iVar9 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  if (this[0x11f] == (HangarWindow)0x0) {
    iVar32 = *(int *)(*(int *)(this + 0x20) + 4);
    iVar30 = *(int *)(Globals::layout + 8);
    iVar42 = *(int *)(Globals::layout + 0x2c);
    TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x30),true);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x30);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListDescription_00,false);
    TouchButton::setText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x30);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListPrice_00,false);
    TouchButton::setSplitText(pTVar25,aSStack_6c);
    iVar30 = iVar30 + iVar32 + iVar42 * 5;
    AbyssEngine::String::~String(aSStack_6c);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x30),Globals::w / 2,iVar30,
               '\x14');
    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x30));
    TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x34),true);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x34);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListDescription_01,false);
    TouchButton::setText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x34);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListPrice_01,false);
    TouchButton::setSplitText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x34),Globals::w / 2,
               *(int *)(Globals::layout + 0x30) + iVar30 + *(int *)(Globals::layout + 0x34),'\x14');
    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x34));
    TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x38),true);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x38);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListDescription_02,false);
    TouchButton::setText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x38);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListPrice_02,false);
    TouchButton::setSplitText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x38),Globals::w / 2,
               iVar30 + (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30)) * 2,
               '\x14');
    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x38));
    TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x3c),true);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x3c);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListDescription_03,false);
    TouchButton::setText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x3c);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListPrice_03,false);
    TouchButton::setSplitText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x3c),Globals::w / 2,
               (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30)) * 3 + iVar30,
               '\x14');
    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x3c));
    TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x40),true);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x40);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListDescription_04,false);
    TouchButton::setText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x40);
    AbyssEngine::String::String(aSStack_6c,Globals::cItemListPrice_04,false);
    TouchButton::setSplitText(pTVar25,aSStack_6c);
    AbyssEngine::String::~String(aSStack_6c);
    TouchButton::setPosition
              (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x40),Globals::w / 2,
               iVar30 + (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x30)) * 4,
               '\x14');
    TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x40));
    local_e4 = 5;
  }
  else {
    iVar30 = 0;
    local_e4 = 0;
    do {
      AbyssEngine::String::String(aSStack_6c,"",false);
      AbyssEngine::String::String((String *)local_ac,"",false);
      TouchButton::setVisible
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar30 + 0x30),true);
      switch(local_e4) {
      case 0:
        AbyssEngine::String::String(aSStack_74,Globals::cItemListDescription_00,false);
        AbyssEngine::String::operator=(aSStack_6c,aSStack_74);
        AbyssEngine::String::~String(aSStack_74);
        AbyssEngine::String::String(aSStack_74,Globals::cItemListPrice_00,false);
        AbyssEngine::String::operator=((String *)local_ac,aSStack_74);
        break;
      case 1:
        AbyssEngine::String::String(aSStack_74,Globals::cItemListDescription_01,false);
        AbyssEngine::String::operator=(aSStack_6c,aSStack_74);
        AbyssEngine::String::~String(aSStack_74);
        AbyssEngine::String::String(aSStack_74,Globals::cItemListPrice_01,false);
        AbyssEngine::String::operator=((String *)local_ac,aSStack_74);
        break;
      case 2:
        AbyssEngine::String::String(aSStack_74,Globals::cItemListDescription_02,false);
        AbyssEngine::String::operator=(aSStack_6c,aSStack_74);
        AbyssEngine::String::~String(aSStack_74);
        AbyssEngine::String::String(aSStack_74,Globals::cItemListPrice_02,false);
        AbyssEngine::String::operator=((String *)local_ac,aSStack_74);
        break;
      case 3:
        AbyssEngine::String::String(aSStack_74,Globals::cItemListDescription_03,false);
        AbyssEngine::String::operator=(aSStack_6c,aSStack_74);
        AbyssEngine::String::~String(aSStack_74);
        AbyssEngine::String::String(aSStack_74,Globals::cItemListPrice_03,false);
        AbyssEngine::String::operator=((String *)local_ac,aSStack_74);
        break;
      case 4:
        AbyssEngine::String::String(aSStack_74,Globals::cItemListDescription_04,false);
        AbyssEngine::String::operator=(aSStack_6c,aSStack_74);
        AbyssEngine::String::~String(aSStack_74);
        AbyssEngine::String::String(aSStack_74,Globals::cItemListPrice_04,false);
        AbyssEngine::String::operator=((String *)local_ac,aSStack_74);
        break;
      default:
        AbyssEngine::String::String(aSStack_74,"",false);
        AbyssEngine::String::operator=(aSStack_6c,aSStack_74);
        pSVar16 = (String *)AbyssEngine::String::~String(aSStack_74);
        AbyssEngine::String::String(pSVar16,"",false);
        AbyssEngine::String::operator=((String *)local_ac,aSStack_74);
      }
      AbyssEngine::String::~String(aSStack_74);
      fVar36 = (float)VectorSignedToFloat(*(int *)(this + 300),(byte)(in_fpscr >> 0x16) & 3);
      fVar37 = (float)VectorSignedToFloat((Globals::h / 2 - *(int *)(this + 0x124) / 2) +
                                          *(int *)(Globals::layout + 0x20) * -3,
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar38 = (float)VectorSignedToFloat((local_e4 / 3) *
                                          (*(int *)(this + 300) + *(int *)(this + 0x124)),
                                          (byte)(in_fpscr >> 0x16) & 3);
      iVar32 = (*(int *)(this + 0x128) + *(int *)(this + 0x120)) * (local_e4 % 3) +
               ((Globals::w / 2 - *(int *)(this + 0x120)) - *(int *)(this + 0x128));
      iVar42 = (int)(fVar37 + fVar36 * -0.5 + fVar38);
      TouchButton::setPosition
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar30 + 0x30),iVar32,
                 iVar42,'D');
      TouchButton::replaceTextKeepSize
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar30 + 0x30),aSStack_6c);
      TouchButton::setSplitText
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar30 + 0x30),
                 (String *)local_ac);
      TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar30 + 0x30));
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(*(int *)(this + 0x30) + iVar30),iVar32,
                 iVar42 - *(int *)(Globals::layout + 0x2c),'\x11','D');
      if ((iVar30 == 0x10) && (Globals::showBestDeal != '\0')) {
        fVar37 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x124),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar36 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x120),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar38 = (float)VectorSignedToFloat(iVar42,(byte)(in_fpscr >> 0x16) & 3);
        pfVar17 = (float *)&DAT_00175b00;
        if (Globals::iPad != '\0') {
          pfVar17 = (float *)&DAT_00175b04;
        }
        fVar40 = (float)VectorSignedToFloat(iVar32,(byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(this + 0x34),(int)(fVar40 + fVar36 * *pfVar17),
                   (int)(fVar38 + fVar37 * -0.1),'\x11','\x11');
      }
      AbyssEngine::String::~String((String *)local_ac);
      AbyssEngine::String::~String(aSStack_6c);
      local_e4 = local_e4 + 1;
      iVar30 = iVar30 + 4;
    } while (local_e4 < 5);
  }
  iVar32 = Globals::w;
  iVar30 = Globals::h;
  bVar35 = (char)Globals::options._74_2_ != '\0';
  if ((ushort)Globals::options._74_2_ < 0x100) {
LAB_00175604:
    iVar31 = *(int *)(this + 0x120);
    iVar29 = *(int *)(this + 0x124);
    iVar9 = *(int *)(this + 0x128);
    iVar27 = *(int *)(this + 300);
    iVar42 = *(int *)(Globals::layout + 0x20);
    TouchButton::setVisible(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44),true);
    fVar36 = (float)VectorSignedToFloat(iVar27,(byte)(in_fpscr >> 0x16) & 3);
    fVar37 = (float)VectorSignedToFloat((iVar30 / 2 - iVar29 / 2) + iVar42 * -3,
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar38 = (float)VectorSignedToFloat(iVar27 + iVar29,(byte)(in_fpscr >> 0x16) & 3);
    iVar30 = (int)(fVar38 + fVar37 + fVar36 * -0.5);
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44);
    if (this[0x11f] == (HangarWindow)0x0) {
      pSVar21 = (String *)GameText::getText(Globals::gameText,0x76);
      TouchButton::setText(pTVar25,pSVar21);
      TouchButton::setPosition
                (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44),Globals::w / 2,
                 (*(int *)(Globals::layout + 0x30) + *(int *)(Globals::layout + 0x34)) * local_e4 +
                 *(int *)(this + 0x48),'\x14');
      TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44));
    }
    else {
      iVar9 = iVar32 / 2 + iVar31 + iVar9;
      TouchButton::setPosition(pTVar25,iVar9,iVar30,'D');
      pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44);
      pSVar21 = (String *)GameText::getText(Globals::gameText,0x76);
      TouchButton::replaceTextKeepSize(pTVar25,pSVar21);
      TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44));
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(*(int *)(this + 0x30) + 0x14),iVar9,
                 iVar30 - *(int *)(Globals::layout + 0x2c),'\x11','D');
      iVar9 = *(int *)(this + 0x124);
      fVar36 = (float)VectorSignedToFloat(*(int *)(this + 300),(byte)(in_fpscr >> 0x16) & 3);
      pfVar17 = (float *)&DAT_00175b00;
      fVar37 = (float)VectorSignedToFloat((Globals::h / 2 - iVar9 / 2) +
                                          *(int *)(Globals::layout + 0x20) * -3,
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar38 = (float)VectorSignedToFloat(*(int *)(this + 300) + iVar9,(byte)(in_fpscr >> 0x16) & 3)
      ;
      if (Globals::iPad != '\0') {
        pfVar17 = (float *)&DAT_00175b04;
      }
      fVar40 = (float)VectorSignedToFloat(*(int *)(this + 0x120),(byte)(in_fpscr >> 0x16) & 3);
      fVar39 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
      fVar41 = (float)VectorSignedToFloat(Globals::w / 2 + *(int *)(this + 0x120) +
                                          *(int *)(this + 0x128),(byte)(in_fpscr >> 0x16) & 3);
      fVar36 = (float)VectorSignedToFloat((int)(fVar38 + fVar37 + fVar36 * -0.5),
                                          (byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x38),(int)(fVar41 + fVar40 * *pfVar17),
                 (int)(fVar36 + fVar39 * -0.1),'\x11','\x11');
    }
    pTVar25 = *(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x44);
    pSVar21 = (String *)GameText::getText(Globals::gameText,0x77);
    TouchButton::setSplitText(pTVar25,pSVar21);
    local_e4 = local_e4 + 1;
  }
  else {
    cVar1 = '\0';
    if (Globals::options[0x4c] != '\0' &&
        ((Globals::options[0x49] != '\0' && bVar35) && Globals::options[0x4d] != '\0')) {
      cVar1 = *(char *)(iVar9 + 0x15);
    }
    if ((Globals::options[0x4c] == '\0' ||
        ((Globals::options[0x49] == '\0' || !bVar35) || Globals::options[0x4d] == '\0')) ||
        cVar1 != '\0') goto LAB_00175604;
  }
  if (this[0x11f] == (HangarWindow)0x0) {
    iVar32 = *(int *)(Globals::layout + 0x30);
    iVar9 = *(int *)(Globals::layout + 0x34);
    this_02 = *(ChoiceWindow **)(this + 0x20);
    iVar30 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
    ChoiceWindow::setHeight(this_02,(iVar9 + iVar32) * (local_e4 + 1) + iVar30 * 2);
  }
LAB_001758c2:
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== HangarWindow::getRelativeScrollStartPos  @0x00175bf0  (44 bytes)
/* HangarWindow::getRelativeScrollStartPos() */

float __thiscall HangarWindow::getRelativeScrollStartPos(HangarWindow *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (*(int *)(this + 0xb4) < 1) {
    fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0xb4),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xd4),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = -fVar2 / fVar1;
  }
  else {
    fVar1 = 0.0;
  }
  return fVar1;
}

// ===== HangarWindow::getRelativeScrollHeight  @0x00175c20  (78 bytes)
/* HangarWindow::getRelativeScrollHeight() */

float __thiscall HangarWindow::getRelativeScrollHeight(HangarWindow *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  iVar2 = *(int *)(this + 0xd4);
  iVar3 = *(int *)(this + 0xd8);
  if (iVar2 < iVar3) {
    return 0.0;
  }
  iVar1 = *(int *)(this + 0xb4);
  if (iVar1 < 1) {
    if (iVar3 - iVar2 <= iVar1) {
      fVar4 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
      goto LAB_00175c60;
    }
    iVar3 = iVar1 + iVar2;
  }
  else {
    iVar3 = iVar3 - iVar1;
  }
  fVar4 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
LAB_00175c60:
  fVar5 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
  return fVar5 / fVar4;
}

// ===== HangarWindow::OnTouchBegin  @0x00175c74  (1082 bytes)
/* HangarWindow::OnTouchBegin(int, int) */

void __thiscall HangarWindow::OnTouchBegin(HangarWindow *this,int param_1,int param_2)

{
  bool bVar1;
  Status *pSVar2;
  uint uVar3;
  int iVar4;
  ListItem *pLVar5;
  Ship *this_00;
  Array *pAVar6;
  Station *pSVar7;
  uint uVar8;
  TouchButton *this_01;
  String *pSVar9;
  undefined4 uVar10;
  HangarWindow HVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  HangarList *this_02;
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
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  uVar3 = Layout::OnTouchBegin(Globals::layout,param_1,param_2);
  if (this[0x3c] != (HangarWindow)0x0) {
    if (this[0xae] == (HangarWindow)0x0) {
      if (this[0xb0] != (HangarWindow)0x0) {
        iVar4 = 0x12;
        do {
          TouchButton::OnTouchBegin
                    (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar4 * 4),param_1,
                     param_2);
          iVar4 = iVar4 + 1;
        } while (iVar4 != 0x17);
      }
    }
    else {
      iVar4 = *(int *)(this + 0x24);
      iVar13 = 0xc;
      do {
        TouchButton::OnTouchBegin
                  (*(TouchButton **)(*(int *)(iVar4 + 4) + iVar13 * 4),param_1,param_2);
        iVar4 = *(int *)(this + 0x24);
        iVar13 = iVar13 + 1;
      } while (iVar13 != 0x11);
      TouchButton::OnTouchBegin(*(TouchButton **)(*(int *)(iVar4 + 4) + 0x44),param_1,param_2);
    }
    ChoiceWindow::OnTouchBegin(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
    goto LAB_00175d32;
  }
  *(int *)(this + 0xb8) = param_2;
  *(int *)(this + 0xcc) = param_2;
  *(undefined4 *)(this + 0xc0) = 0;
  this[0xd0] = (HangarWindow)0x1;
  if (*(int *)(this + 0x58) == 1) {
    ListItemWindow::OnTouchBegin(*(ListItemWindow **)(this + 0x18),param_1,param_2);
    goto LAB_00175d32;
  }
  if ((*(int *)(Globals::layout + 0xc) < param_2) &&
     (param_2 < Globals::h - *(int *)(Globals::layout + 0x10))) {
    this_02 = *(HangarList **)(this + 0x14);
    iVar4 = __aeabi_idiv((((param_2 - *(int *)(Globals::layout + 0xc)) -
                          *(int *)(Globals::layout + 0x20)) - *(int *)(this + 0x10c)) -
                         *(int *)(this + 0xb4),
                         *(int *)(Globals::layout + 0x70) + *(int *)(this + 0x10c));
    iVar13 = HangarList::getCurrentLength(this_02);
    if (iVar13 <= iVar4) goto LAB_00175e20;
    HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),iVar4);
    pLVar5 = (ListItem *)HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
    highlightItem(this,pLVar5);
    if (this[0x11d] == (HangarWindow)0x0) {
LAB_00175f1e:
      bVar1 = false;
    }
    else {
      pLVar5 = (ListItem *)HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
      iVar4 = ::ListItem::isShip(pLVar5);
      if ((iVar4 != 1) ||
         (iVar4 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14)), iVar4 != 1))
      goto LAB_00175f1e;
      this_00 = (Ship *)Status::getShip(Globals::status);
      pAVar6 = (Array *)Item::extractItems(*(Array **)(this + 0x10),true);
      Ship::setCargo(this_00,pAVar6);
      pSVar7 = (Station *)Status::getStation(Globals::status);
      bVar1 = false;
      pAVar6 = (Array *)Item::extractItems(*(Array **)(this + 0x10),false);
      Station::setItems(pSVar7,pAVar6,false);
    }
  }
  else {
LAB_00175e20:
    bVar1 = true;
  }
  iVar4 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
  if (((((iVar4 == 4) && (this[0x88] != (HangarWindow)0x0)) &&
       (bVar1 || *(int *)(this + 0x68) != *(int *)(this + 0x84))) &&
      ((0 < *(int *)(this + 0x94) && (this[0x3c] == (HangarWindow)0x0)))) &&
     (iVar4 = BluePrint::isEmpty(*(BluePrint **)(this + 0x80)), iVar4 == 0)) {
    iVar4 = BluePrint::getStationIndex(*(BluePrint **)(this + 0x80));
    pSVar7 = (Station *)Status::getStation(Globals::status);
    iVar13 = Station::getIndex(pSVar7);
    if (iVar4 != iVar13) {
      iVar4 = Item::getIndex(*(Item **)(*(int *)(this + 0x84) + 0x10));
      if (iVar4 == 0xd1) {
        HVar11 = (HangarWindow)0x1;
      }
      else {
        iVar4 = Item::getIndex(*(Item **)(*(int *)(this + 0x84) + 0x10));
        HVar11 = (HangarWindow)0x0;
        if (iVar4 == 0xcc) {
          HVar11 = (HangarWindow)0x1;
        }
      }
      this[0x11e] = HVar11;
      AbyssEngine::String::String(aSStack_30);
      if (this[0x11e] == (HangarWindow)0x0) {
        pSVar9 = (String *)GameText::getText(Globals::gameText,0x120);
        AbyssEngine::String::String(aSStack_38,pSVar9,false);
      }
      else {
        pSVar9 = (String *)GameText::getText(Globals::gameText,0x121);
        AbyssEngine::String::String(aSStack_38,pSVar9,false);
      }
      AbyssEngine::String::operator=(aSStack_30,aSStack_38);
      AbyssEngine::String::~String(aSStack_38);
      pSVar2 = Globals::status;
      if (this[0x11e] == (HangarWindow)0x0) {
        AbyssEngine::String::String(aSStack_40,aSStack_30,false);
        BluePrint::getStationName();
        AbyssEngine::String::String(aSStack_48,aSStack_50,false);
        uVar10 = AbyssEngine::String::String(aSStack_58,"#S",false);
        Status::replaceHash(aSStack_38,pSVar2,aSStack_40,aSStack_48,uVar10);
        AbyssEngine::String::operator=(aSStack_30,aSStack_38);
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String(aSStack_48);
        AbyssEngine::String::~String(aSStack_50);
        AbyssEngine::String::~String(aSStack_40);
        pSVar2 = Globals::status;
        AbyssEngine::String::String(aSStack_60,aSStack_30,false);
        Item::getBlueprintAmount(*(Item **)(*(int *)(this + 0x84) + 0x10));
        Layout::formatCredits((int)aSStack_50);
        AbyssEngine::String::String(aSStack_68,aSStack_50,false);
        uVar10 = AbyssEngine::String::String(aSStack_70,"#C",false);
        Status::replaceHash(aSStack_38,pSVar2,aSStack_60,aSStack_68,uVar10);
        AbyssEngine::String::operator=(aSStack_30,aSStack_38);
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::~String(aSStack_70);
        AbyssEngine::String::~String(aSStack_68);
        AbyssEngine::String::~String(aSStack_50);
        AbyssEngine::String::~String(aSStack_60);
      }
      ChoiceWindow::set(*(String **)(this + 0x20),(bool)((char)&stack0x00000024 + -0x54));
      this[0xac] = (HangarWindow)0x1;
      this[0x3c] = (HangarWindow)0x1;
      this[0xd1] = (HangarWindow)0x1;
      AbyssEngine::String::~String(aSStack_30);
      goto LAB_00175d32;
    }
  }
  puVar12 = *(uint **)(this + 4);
  if (*puVar12 != 0) {
    uVar14 = 0;
    do {
      uVar8 = TouchButton::OnTouchBegin(*(TouchButton **)(puVar12[1] + uVar14 * 4),param_1,param_2);
      puVar12 = *(uint **)(this + 4);
      uVar3 = uVar3 | uVar8;
      uVar14 = uVar14 + 1;
    } while (uVar14 < *puVar12);
  }
  puVar12 = *(uint **)(this + 0x24);
  if (*puVar12 != 0) {
    uVar14 = 0;
    do {
      this_01 = *(TouchButton **)(puVar12[1] + uVar14 * 4);
      if (this_01 != (TouchButton *)0x0) {
        TouchButton::OnTouchBegin(this_01,param_1,param_2);
        puVar12 = *(uint **)(this + 0x24);
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < *puVar12);
  }
  if (((this[0xf8] != (HangarWindow)0x0) &&
      (iVar4 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14)), iVar4 == 1)) &&
     ((iVar4 = *(int *)(this + 0xfc), -1 < iVar4 &&
      (iVar13 = HangarList::getCurrentItemIndex(*(HangarList **)(this + 0x14)),
      iVar4 != iVar13 || (uVar3 & 1) != 0)))) {
    this[0xf8] = (HangarWindow)0x0;
    autoEquipSecondaryWeapons(this,*(int *)(this + 0xfc));
  }
LAB_00175d32:
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== HangarWindow::highlightItem  @0x00176164  (90 bytes)
/* HangarWindow::highlightItem(ListItem*) */

undefined4 __thiscall HangarWindow::highlightItem(HangarWindow *this,ListItem *param_1)

{
  byte bVar1;
  int iVar2;
  HangarWindow HVar3;
  float extraout_s0;
  
  if ((param_1 != (ListItem *)0x0) && (iVar2 = ::ListItem::isSelectable(param_1), iVar2 == 1)) {
    HVar3 = (HangarWindow)0x0;
    FModSound::play(Globals::sound,0x7c,(Vector *)0x0,(Vector *)0x0,extraout_s0);
    if (*(ListItem **)(this + 0x68) != param_1) {
      bVar1 = ::ListItem::isTextButton(param_1);
      HVar3 = (HangarWindow)(bVar1 ^ 1);
    }
    this[0xd2] = HVar3;
    *(ListItem **)(this + 0x68) = param_1;
    iVar2 = ::ListItem::isShip(param_1);
    if (iVar2 == 1) {
      Ship::adjustPrice(*(Ship **)(*(int *)(this + 0x68) + 0xc));
    }
  }
  return 0;
}

// ===== HangarWindow::autoEquipSecondaryWeapons  @0x001761c4  (518 bytes)
/* HangarWindow::autoEquipSecondaryWeapons(int) */

void __thiscall HangarWindow::autoEquipSecondaryWeapons(HangarWindow *this,int param_1)

{
  Status *pSVar1;
  GameText *this_00;
  ListItem *this_01;
  int iVar2;
  Ship *pSVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  String *pSVar7;
  undefined4 uVar8;
  Item *pIVar9;
  HangarList *this_02;
  Item *this_03;
  uint uVar10;
  String aSStack_4c [8];
  String aSStack_44 [8];
  String aSStack_3c [8];
  String aSStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  this_01 = (ListItem *)HangarList::getCurrentItemAt(*(HangarList **)(this + 0x14),param_1);
  if (((((this_01 != (ListItem *)0x0) && (*(Item **)(this_01 + 0x10) != (Item *)0x0)) &&
       (iVar2 = Item::getType(*(Item **)(this_01 + 0x10)), iVar2 == 1)) &&
      ((iVar2 = ::ListItem::isItem(this_01), iVar2 == 1 &&
       (iVar2 = Item::getType(*(Item **)(this_01 + 0x10)), iVar2 == 1)))) &&
     (iVar2 = Item::getAmount(*(Item **)(this_01 + 0x10)), 0 < iVar2)) {
    pSVar3 = (Ship *)Status::getShip(Globals::status);
    puVar4 = (uint *)Ship::getEquipment(pSVar3,1);
    uVar5 = 0;
    if (puVar4 != (uint *)0x0) {
      uVar5 = *puVar4;
    }
    if (puVar4 != (uint *)0x0 && uVar5 != 0) {
      uVar10 = 0;
      do {
        pIVar9 = *(Item **)(puVar4[1] + uVar10 * 4);
        if (pIVar9 != (Item *)0x0) {
          iVar2 = Item::getIndex(pIVar9);
          iVar6 = Item::getIndex(*(Item **)(this_01 + 0x10));
          if (iVar2 == iVar6) {
            this_03 = *(Item **)(this_01 + 0x10);
            iVar2 = Item::getAmount(this_03);
            iVar6 = Item::getAmount(pIVar9);
            pIVar9 = (Item *)Item::makeItem(this_03,iVar6 + iVar2);
            puVar4 = *(uint **)(this + 0x10);
            if ((puVar4 != (uint *)0x0) && (*puVar4 != 0)) {
              uVar5 = 0;
              do {
                iVar2 = Item::getIndex(*(Item **)(puVar4[1] + uVar5 * 4));
                iVar6 = Item::getIndex(pIVar9);
                if (iVar2 == iVar6) {
                  Item::setAmount(*(Item **)(*(int *)(*(int *)(this + 0x10) + 4) + uVar5 * 4),0);
                }
                puVar4 = *(uint **)(this + 0x10);
                uVar5 = uVar5 + 1;
              } while (uVar5 < *puVar4);
            }
            pSVar3 = (Ship *)Status::getShip(Globals::status);
            Ship::setEquipment(pSVar3,pIVar9,uVar10);
            pSVar3 = (Ship *)Status::getShip(Globals::status);
            iVar2 = Item::getIndex(pIVar9);
            iVar6 = Item::getAmount(pIVar9);
            Ship::removeCargo(pSVar3,iVar2,iVar6);
            this_02 = *(HangarList **)(this + 0x14);
            pSVar3 = (Ship *)Status::getShip(Globals::status);
            HangarList::initShipTab(this_02,pSVar3);
            pSVar7 = (String *)GameText::getText(Globals::gameText,0xd0);
            AbyssEngine::String::String(aSStack_2c,pSVar7,false);
            pSVar1 = Globals::status;
            AbyssEngine::String::String(aSStack_3c,aSStack_2c,false);
            this_00 = Globals::gameText;
            iVar2 = Item::getIndex(pIVar9);
            pSVar7 = (String *)GameText::getText(this_00,iVar2 + 0x4fa);
            AbyssEngine::String::String(aSStack_44,pSVar7,false);
            uVar8 = AbyssEngine::String::String(aSStack_4c,"#N",false);
            Status::replaceHash(aSStack_34,pSVar1,aSStack_3c,aSStack_44,uVar8);
            AbyssEngine::String::operator=(aSStack_2c,aSStack_34);
            AbyssEngine::String::~String(aSStack_34);
            AbyssEngine::String::~String(aSStack_4c);
            AbyssEngine::String::~String(aSStack_44);
            AbyssEngine::String::~String(aSStack_3c);
            ChoiceWindow::set(*(ChoiceWindow **)(this + 0x20),aSStack_2c);
            this[0x3c] = (HangarWindow)0x1;
            this[0xad] = (HangarWindow)0x1;
            AbyssEngine::String::~String(aSStack_2c);
            break;
          }
          uVar5 = *puVar4;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar5);
    }
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== HangarWindow::OnTouchMove  @0x00176420  (360 bytes)
/* HangarWindow::OnTouchMove(int, int) */

undefined4 __thiscall HangarWindow::OnTouchMove(HangarWindow *this,int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  Layout::OnTouchMove(Globals::layout,param_1,param_2);
  if (this[0x3c] == (HangarWindow)0x0) {
    if (*(int *)(this + 0x58) == 1) {
      ListItemWindow::OnTouchMove(*(ListItemWindow **)(this + 0x18),param_1,param_2);
    }
    else {
      if ((*(int *)(Globals::layout + 0xc) < param_2) &&
         (param_2 < Globals::h - *(int *)(Globals::layout + 0x10))) {
        iVar1 = *(int *)(this + 0xb8);
        *(int *)(this + 0xc0) = param_2 - iVar1;
        *(int *)(this + 0xb8) = param_2;
        *(undefined4 *)(this + 0xc4) = 0x3f800000;
        *(int *)(this + 0xb4) = (param_2 - iVar1) + *(int *)(this + 0xb4);
        iVar1 = TouchButton::isTouched
                          (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20));
        if (iVar1 == 0) {
          iVar1 = TouchButton::isTouched
                            (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24));
        }
        else {
          iVar1 = 1;
        }
        iVar3 = param_2 - *(int *)(this + 0xcc);
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if ((iVar1 == 0) && (5 < iVar3)) {
          *(undefined4 *)(this + 0x6c) = 0;
          *(undefined4 *)(this + 0x70) = 0;
          puVar2 = *(uint **)(this + 0x24);
          if (*puVar2 != 0) {
            uVar4 = 0;
            do {
              TouchButton::OnTouchMove(*(TouchButton **)(puVar2[1] + uVar4 * 4),param_1,param_2);
              puVar2 = *(uint **)(this + 0x24);
              uVar4 = uVar4 + 1;
            } while (uVar4 < *puVar2);
          }
          setSellMode(this,false);
          *(undefined4 *)(this + 0x68) = 0;
          this[0xd2] = (HangarWindow)0x0;
          TouchButton::resetTouch(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x20));
          TouchButton::resetTouch(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x24));
        }
      }
      puVar2 = *(uint **)(this + 4);
      if (*puVar2 != 0) {
        uVar4 = 0;
        do {
          TouchButton::OnTouchMove(*(TouchButton **)(puVar2[1] + uVar4 * 4),param_1,param_2);
          puVar2 = *(uint **)(this + 4);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar2);
      }
    }
  }
  else {
    if (this[0xae] == (HangarWindow)0x0) {
      if (this[0xb0] != (HangarWindow)0x0) {
        iVar1 = 0x12;
        do {
          TouchButton::OnTouchMove
                    (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar1 * 4),param_1,
                     param_2);
          iVar1 = iVar1 + 1;
        } while (iVar1 != 0x17);
      }
    }
    else {
      iVar1 = *(int *)(this + 0x24);
      iVar3 = 0xc;
      do {
        TouchButton::OnTouchMove(*(TouchButton **)(*(int *)(iVar1 + 4) + iVar3 * 4),param_1,param_2)
        ;
        iVar1 = *(int *)(this + 0x24);
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0x11);
      TouchButton::OnTouchMove(*(TouchButton **)(*(int *)(iVar1 + 4) + 0x44),param_1,param_2);
    }
    ChoiceWindow::OnTouchMove(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
  }
  return 0;
}

// ===== HangarWindow::setSellMode  @0x00176594  (1762 bytes)
/* HangarWindow::setSellMode(bool) */

void __thiscall HangarWindow::setSellMode(HangarWindow *this,bool param_1)

{
  HangarWindow HVar1;
  Status *pSVar2;
  GameText *pGVar3;
  undefined1 uVar4;
  int iVar5;
  String *pSVar6;
  undefined4 uVar7;
  SolarSystem *this_00;
  Ship *pSVar8;
  Array *pAVar9;
  Station *pSVar10;
  Array *pAVar11;
  int iVar12;
  Ship *this_01;
  uint *puVar13;
  ListItem *pLVar14;
  void *pvVar15;
  BluePrint *this_02;
  ChoiceWindow *pCVar16;
  Item *pIVar17;
  int *piVar18;
  uint uVar19;
  HangarList *pHVar20;
  String aSStack_84 [8];
  String aSStack_7c [8];
  String aSStack_74 [8];
  String aSStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  String aSStack_4c [8];
  String aSStack_44 [8];
  String aSStack_3c [8];
  String aSStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  pLVar14 = *(ListItem **)(this + 0x68);
  if (this[0x88] == (HangarWindow)0x0) {
    if ((pLVar14 != (ListItem *)0x0) && (param_1)) goto LAB_001765c0;
LAB_001765ec:
    this[0x88] = (HangarWindow)0x0;
  }
  else {
    if (pLVar14 == (ListItem *)0x0) goto LAB_001765ec;
LAB_001765c0:
    iVar5 = ::ListItem::isShip(pLVar14);
    if ((((iVar5 != 0) || (iVar5 = ::ListItem::isSlot(pLVar14), iVar5 != 0)) ||
        (iVar5 = ::ListItem::isTextButton(pLVar14), iVar5 != 0)) ||
       ((iVar5 = ::ListItem::isSelectable(pLVar14), iVar5 != 1 ||
        (iVar5 = ::ListItem::isBluePrint(pLVar14), iVar5 == 1)))) goto LAB_001765ec;
    this[0x88] = (HangarWindow)param_1;
    iVar5 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
    if (iVar5 == 1) {
      if (this[0x88] == (HangarWindow)0x0) {
        iVar5 = ::ListItem::isItem(pLVar14);
        if (((iVar5 == 1) && (iVar5 = Item::getType(*(Item **)(pLVar14 + 0x10)), iVar5 != 4)) &&
           (Globals::hints[0x1e] == '\0')) {
          pCVar16 = *(ChoiceWindow **)(this + 0x20);
          pSVar6 = (String *)GameText::getText(Globals::gameText,0x24d);
          ChoiceWindow::set(pCVar16,pSVar6);
          Globals::hints[0x1e] = '\x01';
          this[0x3c] = (HangarWindow)0x1;
        }
        this[0xf8] = (HangarWindow)0x1;
        uVar7 = HangarList::getCurrentItemIndex(*(HangarList **)(this + 0x14));
        *(undefined4 *)(this + 0xfc) = uVar7;
      }
      else {
        if (Globals::hints[0x1d] == '\0') {
          pCVar16 = *(ChoiceWindow **)(this + 0x20);
          pSVar6 = (String *)GameText::getText(Globals::gameText,0x24c);
          ChoiceWindow::set(pCVar16,pSVar6);
          Globals::hints[0x1d] = '\x01';
          this[0x3c] = (HangarWindow)0x1;
        }
        if (pLVar14 != (ListItem *)0x0) {
          uVar7 = Item::getStationAmount(*(Item **)(pLVar14 + 0x10));
          *(undefined4 *)(this + 0x8c) = uVar7;
          uVar7 = Item::getAmount(*(Item **)(pLVar14 + 0x10));
          *(undefined4 *)(this + 0xa0) = uVar7;
          uVar7 = Status::getCredits(Globals::status);
          *(undefined4 *)(this + 0x98) = uVar7;
          *(undefined4 *)(this + 0x9c) = *(undefined4 *)(this + 0xa8);
        }
      }
      pSVar8 = (Ship *)Status::getShip(Globals::status);
      pAVar9 = (Array *)Item::extractItems(*(Array **)(this + 0x10),true);
      Ship::setCargo(pSVar8,pAVar9);
      pSVar10 = (Station *)Status::getStation(Globals::status);
      pAVar9 = (Array *)Item::extractItems(*(Array **)(this + 0x10),false);
      Station::setItems(pSVar10,pAVar9,false);
      if (*(Array **)(this + 0x10) != (Array *)0x0) {
        ArrayReleaseClasses<Item*>(*(Array **)(this + 0x10));
        pvVar15 = *(void **)(this + 0x10);
        if (pvVar15 != (void *)0x0) {
          if (*(void **)((int)pvVar15 + 4) != (void *)0x0) {
            operator_delete__(*(void **)((int)pvVar15 + 4));
          }
          operator_delete(pvVar15);
        }
      }
      *(undefined4 *)(this + 0x10) = 0;
      pSVar8 = (Ship *)Status::getShip(Globals::status);
      pAVar9 = (Array *)Ship::getCargo(pSVar8);
      pSVar10 = (Station *)Status::getStation(Globals::status);
      pAVar11 = (Array *)Station::getItems(pSVar10);
      pAVar9 = (Array *)Item::mixItems(pAVar9,pAVar11);
      *(Array **)(this + 0x10) = pAVar9;
      pHVar20 = *(HangarList **)(this + 0x14);
      pSVar10 = (Station *)Status::getStation(Globals::status);
      pAVar11 = (Array *)Station::getShips(pSVar10);
      HangarList::initShopTab(pHVar20,pAVar9,pAVar11);
      pHVar20 = *(HangarList **)(this + 0x14);
      pSVar8 = (Ship *)Status::getShip(Globals::status);
      HangarList::initShipTab(pHVar20,pSVar8);
      pLVar14 = (ListItem *)HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
      *(ListItem **)(this + 0x68) = pLVar14;
      if ((pLVar14 != (ListItem *)0x0) && (iVar5 = ::ListItem::isShip(pLVar14), iVar5 == 1)) {
        Ship::adjustPrice(*(Ship **)(*(int *)(this + 0x68) + 0xc));
      }
      refreshCurrentContentHeight(this);
LAB_00176c3e:
      if (__stack_chk_guard == local_24) {
        refreshCurrentContentHeight(this);
        return;
      }
      goto LAB_00176608;
    }
    iVar5 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
    if (iVar5 != 4) goto LAB_00176c3e;
    if (this[0x88] != (HangarWindow)0x0) {
      *(undefined4 *)(this + 0x94) = 0;
      iVar5 = BluePrint::isEmpty(*(BluePrint **)(this + 0x80));
      if ((iVar5 == 1) &&
         (iVar5 = Item::getAmount(*(Item **)(*(int *)(this + 0x68) + 0x10)), 0 < iVar5)) {
        iVar5 = BluePrint::getIndex(*(BluePrint **)(this + 0x80));
        if ((iVar5 == 0xd2) ||
           (iVar5 = BluePrint::getIndex(*(BluePrint **)(this + 0x80)), iVar5 == 0xdf)) {
          this_00 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar5 = SolarSystem::getRoutes(this_00);
          if (iVar5 != 0) goto LAB_001766f8;
          this[0x130] = (HangarWindow)0x1;
          pSVar6 = *(String **)(this + 0x20);
          uVar4 = GameText::getText(Globals::gameText,0x210);
        }
        else {
LAB_001766f8:
          pSVar6 = *(String **)(this + 0x20);
          uVar4 = GameText::getText(Globals::gameText,0xd4);
        }
        ChoiceWindow::set(pSVar6,(bool)uVar4);
        this[0x3c] = (HangarWindow)0x1;
      }
      uVar7 = Item::getBlueprintAmount(*(Item **)(pLVar14 + 0x10));
      *(undefined4 *)(this + 0xa4) = uVar7;
      uVar7 = Item::getAmount(*(Item **)(pLVar14 + 0x10));
      *(undefined4 *)(this + 0xa0) = uVar7;
      uVar7 = Status::getCredits(Globals::status);
      *(undefined4 *)(this + 0x98) = uVar7;
      *(undefined4 *)(this + 0x9c) = *(undefined4 *)(this + 0xa8);
      *(undefined4 *)(this + 0x84) = *(undefined4 *)(this + 0x68);
      goto LAB_00176c3e;
    }
    if ((*(int *)(this + 0x84) != 0) &&
       (this_02 = *(BluePrint **)(this + 0x80), this_02 != (BluePrint *)0x0)) {
      pIVar17 = *(Item **)(*(int *)(this + 0x84) + 0x10);
      iVar5 = Item::getBlueprintAmount(pIVar17);
      pSVar10 = (Station *)Status::getStation(Globals::status);
      iVar12 = Station::getIndex(pSVar10);
      BluePrint::addItem(this_02,pIVar17,iVar5,iVar12);
    }
    iVar5 = BluePrint::isCompleted(*(BluePrint **)(this + 0x80));
    if (iVar5 == 1) {
      iVar5 = BluePrint::getStationIndex(*(BluePrint **)(this + 0x80));
      pSVar10 = (Station *)Status::getStation(Globals::status);
      iVar12 = Station::getIndex(pSVar10);
      if (iVar5 == iVar12) {
        pSVar6 = (String *)GameText::getText(Globals::gameText,0xd3);
        AbyssEngine::String::String(aSStack_2c,pSVar6,false);
        pSVar2 = Globals::status;
        AbyssEngine::String::String(aSStack_74,aSStack_2c,false);
        pGVar3 = Globals::gameText;
        iVar5 = BluePrint::getIndex(*(BluePrint **)(this + 0x80));
        pSVar6 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
        AbyssEngine::String::String(aSStack_7c,pSVar6,false);
        AbyssEngine::String::String(aSStack_84,"#N",false);
        Status::replaceHash(aSStack_34,pSVar2,aSStack_74,aSStack_7c);
        AbyssEngine::String::operator=(aSStack_2c,aSStack_34);
        AbyssEngine::String::~String(aSStack_34);
        AbyssEngine::String::~String(aSStack_84);
        AbyssEngine::String::~String(aSStack_7c);
        AbyssEngine::String::~String(aSStack_74);
        ChoiceWindow::set(*(ChoiceWindow **)(this + 0x20),aSStack_2c);
        iVar5 = Globals::items;
        iVar12 = BluePrint::getIndex(*(BluePrint **)(this + 0x80));
        pIVar17 = *(Item **)(*(int *)(iVar5 + 4) + iVar12 * 4);
        iVar5 = BluePrint::getQuantity(*(BluePrint **)(this + 0x80));
        pIVar17 = (Item *)Item::makeItem(pIVar17,iVar5);
        pSVar8 = (Ship *)Status::getShip(Globals::status);
        Ship::addCargo(pSVar8,pIVar17);
        piVar18 = *(int **)(this + 0x10);
        piVar18[2] = *piVar18 + 1;
        pvVar15 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
        piVar18[1] = (int)pvVar15;
        *(Item **)((int)pvVar15 + *piVar18 * 4) = pIVar17;
        *piVar18 = piVar18[2];
        HangarList::setCurrentTab(*(int *)(this + 0x14),true);
        refreshCurrentContentHeight(this);
      }
      else {
        pSVar6 = (String *)GameText::getText(Globals::gameText,0xd2);
        AbyssEngine::String::String(aSStack_2c,pSVar6,false);
        pSVar2 = Globals::status;
        AbyssEngine::String::String(aSStack_3c,aSStack_2c,false);
        pGVar3 = Globals::gameText;
        iVar5 = BluePrint::getIndex(*(BluePrint **)(this + 0x80));
        pSVar6 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
        AbyssEngine::String::String(aSStack_44,pSVar6,false);
        AbyssEngine::String::String(aSStack_4c,"#N",false);
        Status::replaceHash(aSStack_34,pSVar2,aSStack_3c,aSStack_44);
        AbyssEngine::String::operator=(aSStack_2c,aSStack_34);
        AbyssEngine::String::~String(aSStack_34);
        AbyssEngine::String::~String(aSStack_4c);
        AbyssEngine::String::~String(aSStack_44);
        AbyssEngine::String::~String(aSStack_3c);
        pSVar2 = Globals::status;
        AbyssEngine::String::String(aSStack_54,aSStack_2c,false);
        BluePrint::getStationName();
        AbyssEngine::String::String(aSStack_5c,aSStack_64,false);
        AbyssEngine::String::String(aSStack_6c,"#S",false);
        Status::replaceHash(aSStack_34,pSVar2,aSStack_54,aSStack_5c);
        AbyssEngine::String::operator=(aSStack_2c,aSStack_34);
        AbyssEngine::String::~String(aSStack_34);
        AbyssEngine::String::~String(aSStack_6c);
        AbyssEngine::String::~String(aSStack_5c);
        AbyssEngine::String::~String(aSStack_64);
        AbyssEngine::String::~String(aSStack_54);
        ChoiceWindow::set(*(ChoiceWindow **)(this + 0x20),aSStack_2c);
        Status::addPendingProduct(Globals::status,*(BluePrint **)(this + 0x80));
        HangarList::setCurrentTab(*(int *)(this + 0x14),true);
        refreshCargoAvailabilityForBlueprints(this);
      }
      AbyssEngine::String::~String(aSStack_2c);
      BluePrint::reset(*(BluePrint **)(this + 0x80));
      HVar1 = (HangarWindow)0x1;
    }
    else {
      HVar1 = (HangarWindow)0x0;
    }
    pSVar8 = (Ship *)Status::getShip(Globals::status);
    this_01 = (Ship *)Status::getShip(Globals::status);
    pAVar9 = (Array *)Ship::getCargo(this_01);
    pAVar9 = (Array *)Item::extractItems(pAVar9,true);
    Ship::setCargo(pSVar8,pAVar9);
    pHVar20 = *(HangarList **)(this + 0x14);
    pSVar8 = (Ship *)Status::getShip(Globals::status);
    pAVar9 = (Array *)Ship::getCargo(pSVar8);
    pSVar10 = (Station *)Status::getStation(Globals::status);
    pAVar11 = (Array *)Station::getItems(pSVar10);
    pAVar9 = (Array *)Item::mixItems(pAVar9,pAVar11);
    pSVar10 = (Station *)Status::getStation(Globals::status);
    pAVar11 = (Array *)Station::getShips(pSVar10);
    HangarList::initShopTab(pHVar20,pAVar9,pAVar11);
    pHVar20 = *(HangarList **)(this + 0x14);
    pAVar9 = (Array *)Status::getBluePrints(Globals::status);
    HangarList::initBlueprintTab(pHVar20,pAVar9);
    pSVar8 = (Ship *)Status::getShip(Globals::status);
    pAVar9 = (Array *)Ship::getCargo(pSVar8);
    pSVar10 = (Station *)Status::getStation(Globals::status);
    pAVar11 = (Array *)Station::getItems(pSVar10);
    uVar7 = Item::mixItems(pAVar9,pAVar11);
    *(undefined4 *)(this + 0x10) = uVar7;
    this[0x3c] = HVar1;
    if (((bool)HVar1) &&
       (puVar13 = (uint *)HangarList::getCurrentTabItems(*(HangarList **)(this + 0x14)),
       *puVar13 != 0)) {
      uVar19 = 0;
      do {
        pLVar14 = *(ListItem **)(puVar13[1] + uVar19 * 4);
        if ((pLVar14 != (ListItem *)0x0) && (iVar5 = ::ListItem::isItem(pLVar14), iVar5 == 1)) {
          iVar5 = Item::getIndex(*(Item **)(pLVar14 + 0x10));
          iVar12 = BluePrint::getIndex(*(BluePrint **)(this + 0x80));
          if (iVar5 == iVar12) {
            pSVar8 = (Ship *)Status::getShip(Globals::status);
            iVar5 = Item::getIndex(*(Item **)(pLVar14 + 0x10));
            iVar5 = Ship::hasEquipment(pSVar8,iVar5,1);
            if (iVar5 == 1) {
              this[0xf8] = (HangarWindow)0x1;
              *(uint *)(this + 0xfc) = uVar19;
              autoEquipSecondaryWeapons(this,uVar19);
              this[0xf8] = (HangarWindow)0x0;
              break;
            }
          }
        }
        uVar19 = uVar19 + 1;
      } while (uVar19 < *puVar13);
    }
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
LAB_00176608:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== HangarWindow::OnTouchEnd  @0x00176d94  (5604 bytes)
/* HangarWindow::OnTouchEnd(int, int) */

void __thiscall HangarWindow::OnTouchEnd(HangarWindow *this,int param_1,int param_2)

{
  HangarWindow HVar1;
  GameText *this_00;
  Layout *pLVar2;
  char cVar3;
  undefined2 uVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  String *pSVar9;
  undefined4 uVar10;
  Station *pSVar11;
  ListItem *pLVar12;
  uint *puVar13;
  int iVar14;
  String *this_01;
  Array *pAVar15;
  int iVar16;
  Ship *pSVar17;
  Status *pSVar18;
  String *pSVar19;
  String *pSVar20;
  String *pSVar21;
  uint *puVar22;
  Ship *this_02;
  Item *pIVar23;
  int *piVar24;
  ModStation *this_03;
  uint uVar25;
  uint uVar26;
  ListItemWindow *this_04;
  uint uVar27;
  Station *this_05;
  void *pvVar28;
  HangarList *pHVar29;
  Ship *pSVar30;
  ChoiceWindow *pCVar31;
  HangarWindow *pHVar32;
  Array *pAVar33;
  HangarWindow *pHVar34;
  uint in_fpscr;
  undefined4 uVar35;
  float fVar36;
  undefined8 uVar37;
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
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  this[0xd0] = (HangarWindow)0x0;
  if (this[0xd1] != (HangarWindow)0x0) {
    this[0xd1] = (HangarWindow)0x0;
    goto LAB_00176dc2;
  }
  if (this[0x3c] == (HangarWindow)0x0) {
    if (*(int *)(this + 0x58) == 1) {
      ListItemWindow::OnTouchEnd(*(int *)(this + 0x18),param_1);
    }
    iVar7 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
    if (iVar7 != 1) {
      iVar8 = *(int *)(this + 0xc0);
      uVar10 = VectorSignedToFloat(iVar8,(byte)(in_fpscr >> 0x16) & 3);
      iVar7 = iVar8;
      if (iVar8 < 0) {
        iVar7 = -iVar8;
      }
      uVar35 = 0;
      if (3 < iVar7) {
        uVar35 = uVar10;
      }
      *(undefined4 *)(this + 200) = uVar35;
      *(undefined4 *)(this + 0xc4) = 0x3f666666;
      iVar7 = *(int *)(this + 0xb4);
      *(int *)(this + 0xb4) = iVar8 + iVar7;
      *(int *)(this + 0xbc) = iVar8 + iVar7;
      puVar13 = *(uint **)(this + 4);
      if (*puVar13 != 0) {
        uVar26 = 0;
        do {
          iVar7 = TouchButton::OnTouchEnd
                            (*(TouchButton **)(puVar13[1] + uVar26 * 4),param_1,param_2);
          if (iVar7 == 1) {
            setSellMode(this,false);
            setSellMode(this,true);
            setSellMode(this,false);
            *(undefined4 *)(this + 0x68) = 0;
            HangarList::setCurrentTab(*(int *)(this + 0x14),SUB41(uVar26,0));
            if (uVar26 == 2) {
              refreshCargoAvailabilityForBlueprints(this);
            }
            refreshCurrentContentHeight(this);
            *(undefined4 *)(this + 0xbc) = 0;
            *(undefined4 *)(this + 0xb4) = 0;
            HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),-1);
          }
          puVar13 = *(uint **)(this + 4);
          uVar26 = uVar26 + 1;
        } while (uVar26 < *puVar13);
      }
      if (*(int *)(Globals::layout + 0xc) < param_2) {
        pHVar29 = *(HangarList **)(this + 0x14);
        iVar7 = __aeabi_idiv((((param_2 - *(int *)(Globals::layout + 0xc)) -
                              *(int *)(Globals::layout + 0x20)) - *(int *)(this + 0x10c)) -
                             *(int *)(this + 0xb4),
                             *(int *)(Globals::layout + 0x70) + *(int *)(this + 0x10c));
        iVar8 = HangarList::getCurrentLength(pHVar29);
        if (iVar7 < iVar8) {
          HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),iVar7);
          iVar7 = HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
          if (((iVar7 != 0) && (iVar7 == *(int *)(this + 0x68))) &&
             (this[0xd2] != (HangarWindow)0x0)) {
            setSellMode(this,false);
            setSellMode(this,true);
          }
        }
      }
      if (this[0xd2] != (HangarWindow)0x0) {
        this[0xd2] = (HangarWindow)0x0;
        goto LAB_00176dc2;
      }
      iVar7 = TouchButton::OnTouchEnd
                        (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x5c),param_1,
                         param_2);
      if (iVar7 == 1) {
        BluePrint::getAutoCompletionPrice(*(BluePrint **)(this + 0x80));
        pSVar18 = Globals::status;
        pSVar19 = *(String **)(this + 0x20);
        pSVar9 = (String *)GameText::getText(Globals::gameText,0xc3);
        AbyssEngine::String::String(aSStack_a8,pSVar9,false);
        Layout::formatCredits((int)aSStack_b0);
        uVar10 = AbyssEngine::String::String(aSStack_b8,"#C",false);
        Status::replaceHash(aSStack_30,pSVar18,aSStack_a8,aSStack_b0,uVar10);
        ChoiceWindow::set(pSVar19,(bool)((char)&stack0x000000c4 + '\f'));
        AbyssEngine::String::~String(aSStack_30);
        AbyssEngine::String::~String(aSStack_b8);
        AbyssEngine::String::~String(aSStack_b0);
        AbyssEngine::String::~String(aSStack_a8);
        this[0x3c] = (HangarWindow)0x1;
        this[0xb1] = (HangarWindow)0x1;
      }
      iVar7 = HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
      if (((iVar7 != 0) && (iVar7 == *(int *)(this + 0x68))) &&
         (puVar13 = *(uint **)(this + 0x24), *puVar13 != 0)) {
        uVar26 = 0;
        do {
          iVar7 = TouchButton::OnTouchEnd
                            (*(TouchButton **)(puVar13[1] + uVar26 * 4),param_1,param_2);
          if (iVar7 == 1) {
            iVar7 = __aeabi_idiv((((param_2 - *(int *)(Globals::layout + 0xc)) -
                                  *(int *)(Globals::layout + 0x20)) - *(int *)(this + 0x10c)) -
                                 *(int *)(this + 0xb4),
                                 *(int *)(Globals::layout + 0x70) + *(int *)(this + 0x10c));
            switch(uVar26) {
            case 0:
              HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),iVar7);
              this_04 = *(ListItemWindow **)(this + 0x18);
              pLVar12 = (ListItem *)HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
              fVar36 = (float)ListItemWindow::set(this_04,pLVar12,0,0,0,0,true);
              *(undefined4 *)(this + 0x58) = 1;
              FModSound::play(Globals::sound,0x61,(Vector *)0x0,(Vector *)0x0,fVar36);
              goto LAB_00176dc2;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
              HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),iVar7);
              selectItem(this,*(ListItem **)(this + 0x68));
              break;
            case 8:
              HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),iVar7);
              fVar36 = (float)transaction(this,false);
              FModSound::play(Globals::sound,100,(Vector *)0x0,(Vector *)0x0,fVar36);
              break;
            case 9:
              HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),iVar7);
              fVar36 = (float)transaction(this,true);
              FModSound::play(Globals::sound,0x65,(Vector *)0x0,(Vector *)0x0,fVar36);
              pLVar12 = (ListItem *)HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
              iVar7 = ::ListItem::isItem(pLVar12);
              if (iVar7 == 1) {
                iVar7 = HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
                iVar7 = Item::getType(*(Item **)(iVar7 + 0x10));
                if (iVar7 == 1) {
                  this[0xf8] = (HangarWindow)0x1;
                  uVar10 = HangarList::getCurrentItemIndex(*(HangarList **)(this + 0x14));
                  *(undefined4 *)(this + 0xfc) = uVar10;
                }
              }
              break;
            case 10:
              pSVar9 = *(String **)(this + 0x20);
              bVar6 = (bool)GameText::getText(Globals::gameText,0x14e);
              ChoiceWindow::set(pSVar9,bVar6);
              this[0x3c] = (HangarWindow)0x1;
              this[0x93] = (HangarWindow)0x1;
              break;
            case 0xb:
              Globals::options[0x4e] = 1;
              RecordHandler::saveOptions(Globals::recordHandler);
              showCreditsBuyWindow(this);
            }
          }
          puVar13 = *(uint **)(this + 0x24);
          uVar26 = uVar26 + 1;
        } while (uVar26 < *puVar13);
      }
      iVar7 = Layout::helpPressed(Globals::layout);
      pLVar2 = Globals::layout;
      if (iVar7 == 1) {
        if (*(int *)(this + 0x58) == 1) {
          pSVar9 = (String *)GameText::getText(Globals::gameText,0x283);
          AbyssEngine::String::String(aSStack_c0,pSVar9,false);
          Layout::initHelpWindow(pLVar2,aSStack_c0);
          this_01 = aSStack_c0;
        }
        else {
          uVar10 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
          pLVar2 = Globals::layout;
          switch(uVar10) {
          case 0:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x26f);
            AbyssEngine::String::String(aSStack_c8,pSVar9,false);
            Layout::initHelpWindow(pLVar2,aSStack_c8);
            this_01 = aSStack_c8;
            break;
          case 1:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x26e);
            AbyssEngine::String::String(aSStack_d0,pSVar9,false);
            Layout::initHelpWindow(pLVar2,aSStack_d0);
            this_01 = aSStack_d0;
            break;
          case 2:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x271);
            AbyssEngine::String::String(aSStack_d8,pSVar9,false);
            Layout::initHelpWindow(pLVar2,aSStack_d8);
            this_01 = aSStack_d8;
            break;
          case 3:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x270);
            AbyssEngine::String::String(aSStack_e0,pSVar9,false);
            Layout::initHelpWindow(pLVar2,aSStack_e0);
            this_01 = aSStack_e0;
            break;
          case 4:
            pSVar9 = (String *)GameText::getText(Globals::gameText,0x272);
            AbyssEngine::String::String(aSStack_e8,pSVar9,false);
            Layout::initHelpWindow(pLVar2,aSStack_e8);
            this_01 = aSStack_e8;
            break;
          default:
            goto switchD_0017778a_default;
          }
        }
        AbyssEngine::String::~String(this_01);
      }
switchD_0017778a_default:
      iVar7 = TouchButton::OnTouchEnd
                        (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x2c),param_1,
                         param_2);
      if (iVar7 == 1) {
        Globals::options[0x4e] = 1;
        RecordHandler::saveOptions(Globals::recordHandler);
        showCreditsBuyWindow(this);
      }
      goto LAB_00176dc2;
    }
    if (*(int *)(this + 0x58) == 1) {
      Layout::resetWindowDimensions(Globals::layout);
      *(undefined4 *)(this + 0x58) = 0;
      goto LAB_00176dc2;
    }
    iVar7 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
    if (iVar7 != 4) {
      iVar7 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
      if (iVar7 == 3) {
        HangarList::setCurrentTab(*(int *)(this + 0x14),false);
        refreshCargoAvailabilityForBlueprints(this);
        refreshCurrentContentHeight(this);
      }
      else {
        iVar7 = readyToClose(this);
        if (iVar7 == 1) {
          setSellMode(this,false);
          *(undefined4 *)(this + 0x68) = 0;
          HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),-1);
        }
      }
      goto LAB_00176dc2;
    }
    setSellMode(this,false);
    *(undefined4 *)(this + 0x68) = 0;
    HangarList::setCurrentTab(*(int *)(this + 0x14),true);
    refreshCargoAvailabilityForBlueprints(this);
    refreshCurrentContentHeight(this);
    *(undefined4 *)(this + 0xbc) = 0;
    *(undefined4 *)(this + 0xb4) = 0;
LAB_00177428:
    HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),-1);
  }
  else {
    if (this[0xb1] != (HangarWindow)0x0) {
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
      if (iVar7 == 1) {
        this[0x3c] = (HangarWindow)0x0;
      }
      else if (iVar7 == 0) {
        iVar7 = BluePrint::getAutoCompletionPrice(*(BluePrint **)(this + 0x80));
        iVar8 = Status::getCredits(Globals::status);
        pSVar18 = Globals::status;
        if (iVar8 < iVar7) {
          pSVar9 = (String *)GameText::getText(Globals::gameText,0xcb);
          AbyssEngine::String::String(aSStack_38,pSVar9,false);
          Status::getCredits(Globals::status);
          Layout::formatCredits((int)aSStack_48);
          AbyssEngine::String::String(aSStack_40,aSStack_48,false);
          uVar10 = AbyssEngine::String::String(aSStack_50,"#C",false);
          Status::replaceHash(aSStack_30,pSVar18,aSStack_38,aSStack_40,uVar10);
          AbyssEngine::String::~String(aSStack_50);
          AbyssEngine::String::~String(aSStack_40);
          AbyssEngine::String::~String(aSStack_48);
          AbyssEngine::String::~String(aSStack_38);
          AbyssEngine::String::String(aSStack_58,"\n\n",false);
          pSVar9 = (String *)GameText::getText(Globals::gameText,0x7c);
          AbyssEngine::operator+((AbyssEngine *)aSStack_48,aSStack_58,pSVar9);
          AbyssEngine::String::operator+=(aSStack_30,aSStack_48);
          AbyssEngine::String::~String(aSStack_48);
          AbyssEngine::String::~String(aSStack_58);
          ChoiceWindow::set(*(String **)(this + 0x20),(bool)((char)&stack0x000000c4 + '\f'));
          this[0xaf] = (HangarWindow)0x1;
          AbyssEngine::String::~String(aSStack_30);
        }
        else {
          this[0x3c] = (HangarWindow)0x0;
          if (*(BluePrint **)(this + 0x80) != (BluePrint *)0x0) {
            iVar8 = BluePrint::isEmpty(*(BluePrint **)(this + 0x80));
            if (iVar8 == 1) {
              pSVar11 = (Station *)Status::getStation(Globals::status);
              uVar10 = Station::getIndex(pSVar11);
              iVar8 = *(int *)(this + 0x80);
              *(undefined4 *)(iVar8 + 0x10) = uVar10;
              Status::getStation(Globals::status);
              Station::getName();
              AbyssEngine::String::operator=((String *)(iVar8 + 0x14),aSStack_30);
              AbyssEngine::String::~String(aSStack_30);
            }
            BluePrint::complete(*(BluePrint **)(this + 0x80));
            pLVar12 = (ListItem *)HangarList::getCurrentItemAt(*(HangarList **)(this + 0x14),1);
            highlightItem(this,pLVar12);
            this[0x88] = (HangarWindow)0x1;
            setSellMode(this,false);
            Status::changeCredits(Globals::status,-iVar7);
          }
        }
      }
      this[0xb1] = (HangarWindow)0x0;
      goto LAB_00176dc2;
    }
    if (this[0x11c] == (HangarWindow)0x0) {
      if (this[0xaf] != (HangarWindow)0x0) {
        iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
        if (iVar7 == 1) {
          this[0x3c] = (HangarWindow)0x0;
          this[0xaf] = (HangarWindow)0x0;
        }
        else if (iVar7 == 0) {
          Globals::options[0x4e] = 1;
          RecordHandler::saveOptions(Globals::recordHandler);
          showCreditsBuyWindow(this);
        }
        goto LAB_001773f4;
      }
      if (this[0xae] == (HangarWindow)0x0) {
        if (this[0xb0] != (HangarWindow)0x0) {
          iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
          if (iVar7 == 0) {
            iVar7 = 0x12;
            do {
              TouchButton::setVisible
                        (*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + iVar7 * 4),false);
              iVar7 = iVar7 + 1;
            } while (iVar7 != 0x17);
            this[0xb0] = (HangarWindow)0x0;
            showCreditsBuyWindow(this);
          }
          iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
          iVar8 = 0;
          do {
            while (iVar14 = TouchButton::OnTouchEnd
                                      (*(TouchButton **)
                                        (*(int *)(*(int *)(this + 0x24) + 4) + iVar8 * 4 + 0x48),
                                       param_1,param_2), iVar14 == 1) {
              switch(iVar8) {
              case 0:
                RecordHandler::recordStoreWrite(Globals::recordHandler,0);
                RecordHandler::recordStoreWritePreview(Globals::recordHandler,0);
                break;
              case 1:
                *(undefined1 *)(iVar7 + 0x88) = 1;
                NFC::free_credits_likeGOF2OnFacebook();
                Status::changeCredits(Globals::status,0x1d4c);
                Globals::options[0x49] = '\x01';
                break;
              case 2:
                *(undefined1 *)(iVar7 + 0x89) = 1;
                NFC::free_credits_likeFishlabsOnFacebook();
                Status::changeCredits(Globals::status,5000);
                Globals::options[0x4a] = 1;
                break;
              case 3:
                *(undefined1 *)(iVar7 + 0x8a) = 1;
                NFC::free_credits_subscribeToYoutubeChannel();
                Status::changeCredits(Globals::status,5000);
                Globals::options[0x4b] = 1;
                break;
              case 4:
                *(undefined1 *)(iVar7 + 0x8b) = 1;
                NFC::free_credits_followOnTwitter();
                Status::changeCredits(Globals::status,5000);
                Globals::options[0x4c] = '\x01';
                goto LAB_001773f4;
              default:
                goto switchD_00177546_default;
              }
              iVar8 = iVar8 + 1;
            }
switchD_00177546_default:
            iVar8 = iVar8 + 1;
          } while (iVar8 != 5);
          goto LAB_001773f4;
        }
        if (this[0xac] != (HangarWindow)0x0) {
          iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
          iVar8 = Item::getBlueprintAmount(*(Item **)(*(int *)(this + 0x84) + 0x10));
          iVar14 = iVar8 * 200;
          if (iVar7 == 0) {
            iVar16 = Status::getCredits(Globals::status);
            if ((iVar16 < iVar14) || (this[0x11e] != (HangarWindow)0x0)) goto LAB_00177a72;
            Status::changeCredits(Globals::status,iVar8 * -200);
            setSellMode(this,false);
            *(undefined4 *)(this + 0x68) = 0;
            HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),-1);
            this[0xac] = (HangarWindow)0x0;
            this[0x11e] = (HangarWindow)0x0;
          }
          else {
            if (iVar7 != 1) {
LAB_00177a72:
              iVar8 = Status::getCredits(Globals::status);
              if ((iVar14 <= iVar8) && ((iVar7 != 0 || (this[0x11e] == (HangarWindow)0x0))))
              goto LAB_00177bae;
            }
            Item::setStationAmount(*(Item **)(*(int *)(this + 0x84) + 0x10),*(int *)(this + 0x8c));
            Item::setAmount(*(Item **)(*(int *)(this + 0x84) + 0x10),*(int *)(this + 0xa0));
            Item::setBlueprintAmount(*(Item **)(*(int *)(this + 0x84) + 0x10),*(int *)(this + 0xa4))
            ;
            Status::setCredits(Globals::status,*(int *)(this + 0x98));
            *(undefined4 *)(this + 0xa8) = *(undefined4 *)(this + 0x9c);
            *(undefined4 *)(this + 0x8c) = 0;
            *(undefined4 *)(this + 0xa0) = 0;
            *(undefined4 *)(this + 0xa4) = 0;
            *(undefined4 *)(this + 0x94) = 0;
            *(undefined4 *)(this + 0x68) = 0;
            HangarList::setCurrentItemIndex(*(HangarList **)(this + 0x14),-1);
            this[0xac] = (HangarWindow)0x0;
            this[0x3c] = (HangarWindow)0x0;
            this[0x88] = (HangarWindow)0x0;
            iVar7 = Status::getCredits(Globals::status);
            pSVar18 = Globals::status;
            if ((iVar7 < iVar14) && (this[0x11e] == (HangarWindow)0x0)) {
              pCVar31 = *(ChoiceWindow **)(this + 0x20);
              pSVar9 = (String *)GameText::getText(Globals::gameText,0xcb);
              AbyssEngine::String::String(aSStack_60,pSVar9,false);
              Status::getCredits(Globals::status);
              Layout::formatCredits((int)aSStack_48);
              AbyssEngine::String::String(aSStack_68,aSStack_48,false);
              uVar10 = AbyssEngine::String::String(aSStack_70,"#C",false);
              Status::replaceHash(aSStack_30,pSVar18,aSStack_60,aSStack_68,uVar10);
              ChoiceWindow::set(pCVar31,aSStack_30);
              AbyssEngine::String::~String(aSStack_30);
              AbyssEngine::String::~String(aSStack_70);
              AbyssEngine::String::~String(aSStack_68);
              AbyssEngine::String::~String(aSStack_48);
              AbyssEngine::String::~String(aSStack_60);
              this[0x3c] = (HangarWindow)0x1;
            }
            this[0x11e] = (HangarWindow)0x0;
          }
LAB_00177bae:
          refreshCurrentContentHeight(this);
          goto LAB_00176dc2;
        }
        if (this[0x93] == (HangarWindow)0x0) {
          pHVar34 = this + 0x20;
          if (this[0x90] != (HangarWindow)0x0) {
            iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
            pSVar18 = Globals::status;
            if (*(int *)(Globals::status + 0x114) == 3) {
              if (this[0x11d] != (HangarWindow)0x0) goto LAB_00177d1c;
              if (this[0x91] == (HangarWindow)0x0) {
                if (iVar7 == 1) goto LAB_00177e68;
                if (iVar7 == 0) {
                  pCVar31 = *(ChoiceWindow **)pHVar34;
                  AbyssEngine::String::String(aSStack_30,"",false);
                  pSVar9 = (String *)GameText::getText(Globals::gameText,0x147);
                  pSVar19 = (String *)GameText::getText(Globals::gameText,0x14a);
                  pSVar20 = (String *)GameText::getText(Globals::gameText,0x14b);
                  pSVar21 = (String *)GameText::getText(Globals::gameText,0x14a);
                  ChoiceWindow::set(pCVar31,aSStack_30,pSVar9,true,pSVar19,pSVar20,pSVar21,-1,-1);
                  AbyssEngine::String::~String(aSStack_30);
                  this[0x91] = (HangarWindow)0x1;
                  goto LAB_00176dc2;
                }
              }
              else {
                if (iVar7 == 0) goto LAB_00177d28;
                if (iVar7 == 1) {
                  pSVar11 = *(Station **)(Globals::status + 0x14c);
                  pSVar17 = (Ship *)Status::getShip(Globals::status);
                  iVar7 = Ship::getIndex(pSVar17);
                  iVar7 = Station::hasShip(pSVar11,iVar7);
                  if (iVar7 != 1) {
                    iVar7 = Ship::getPrice(*(Ship **)(*(int *)(this + 0x68) + 0xc));
                    iVar8 = Status::getCredits(Globals::status);
                    pSVar18 = Globals::status;
                    if (iVar8 < iVar7) {
                      pSVar9 = (String *)GameText::getText(Globals::gameText,0xcb);
                      AbyssEngine::String::String(aSStack_78,pSVar9,false);
                      Ship::getPrice(*(Ship **)(*(int *)(this + 0x68) + 0xc));
                      Status::getCredits(Globals::status);
                      Layout::formatCredits((int)aSStack_30);
                      AbyssEngine::String::String(aSStack_80,aSStack_30,false);
                      uVar10 = AbyssEngine::String::String(aSStack_88,"#C",false);
                      Status::replaceHash(aSStack_48,pSVar18,aSStack_78,aSStack_80,uVar10);
                      AbyssEngine::String::~String(aSStack_88);
                      AbyssEngine::String::~String(aSStack_80);
                      AbyssEngine::String::~String(aSStack_30);
                      AbyssEngine::String::~String(aSStack_78);
                      AbyssEngine::String::String(aSStack_58,"\n\n",false);
                      pSVar9 = (String *)GameText::getText(Globals::gameText,0x7c);
                      AbyssEngine::operator+((AbyssEngine *)aSStack_30,aSStack_58,pSVar9);
                      AbyssEngine::String::operator+=(aSStack_48,aSStack_30);
                      AbyssEngine::String::~String(aSStack_30);
                      AbyssEngine::String::~String(aSStack_58);
                      ChoiceWindow::set(*(String **)pHVar34,(bool)((char)&stack0x000000ac + '\f'));
                      this[0xaf] = (HangarWindow)0x1;
                      this[0x3c] = (HangarWindow)0x1;
                      this[0x90] = (HangarWindow)0x0;
                      this[0x91] = (HangarWindow)0x0;
                      AbyssEngine::String::~String(aSStack_48);
                      goto LAB_00176dc2;
                    }
                    bVar6 = true;
                    goto LAB_00177d2c;
                  }
                  pCVar31 = *(ChoiceWindow **)(this + 0x20);
                  pSVar9 = (String *)GameText::getText(Globals::gameText,0x148);
                  ChoiceWindow::set(pCVar31,pSVar9);
                  this[0x3c] = (HangarWindow)0x1;
                  goto LAB_0017832e;
                }
              }
            }
            else {
              if (this[0x11d] == (HangarWindow)0x0) {
                if (this[0x92] == (HangarWindow)0x0) {
                  if (iVar7 != 1) {
                    if (iVar7 == 0) {
                      pCVar31 = *(ChoiceWindow **)pHVar34;
                      AbyssEngine::String::String(aSStack_30,"",false);
                      pSVar9 = (String *)GameText::getText(Globals::gameText,0xbd);
                      ChoiceWindow::set(pCVar31,aSStack_30,pSVar9,true);
                      AbyssEngine::String::~String(aSStack_30);
                      this[0x92] = (HangarWindow)0x1;
                      goto LAB_00176dc2;
                    }
                    goto LAB_001773f4;
                  }
LAB_00177e68:
                  this[0x90] = (HangarWindow)0x0;
                  this[0x91] = (HangarWindow)0x0;
                  this[0x3c] = (HangarWindow)0x0;
                  goto LAB_00176dc2;
                }
                if (iVar7 == 0) {
                  this_03 = (ModStation *)
                            AbyssEngine::ApplicationManager::GetApplicationModule
                                      (Globals::appManager,5);
                  ModStation::showDlcMenu(this_03);
                  this[0x92] = (HangarWindow)0x0;
                  this[0x3c] = (HangarWindow)0x0;
LAB_0017832e:
                  this[0x90] = (HangarWindow)0x0;
                  this[0x91] = (HangarWindow)0x0;
                  goto LAB_00176dc2;
                }
                if (iVar7 != 1) goto LAB_001773f4;
                bVar6 = false;
                this[0x92] = (HangarWindow)0x0;
LAB_00177d2c:
                pSVar17 = (Ship *)Status::getShip(pSVar18);
                pAVar15 = (Array *)Item::extractItems(*(Array **)(this + 0x10),true);
                Ship::setCargo(pSVar17,pAVar15);
                pSVar18 = Globals::status;
                if (bVar6) {
                  iVar7 = Ship::getPrice(*(Ship **)(*(int *)(this + 0x68) + 0xc));
                  iVar7 = -iVar7;
LAB_00177e9e:
                  Status::changeCredits(pSVar18,iVar7);
                }
                else if (this[0x11d] == (HangarWindow)0x0) {
                  pSVar17 = (Ship *)Status::getShip(Globals::status);
                  iVar7 = Ship::getPrice(pSVar17);
                  iVar8 = Ship::getPrice(*(Ship **)(*(int *)(this + 0x68) + 0xc));
                  iVar7 = iVar7 - iVar8;
                  goto LAB_00177e9e;
                }
                pHVar32 = this + 0x68;
                pSVar17 = (Ship *)Status::getShip(Globals::status);
                puVar13 = (uint *)Ship::getEquipment(pSVar17);
                puVar22 = (uint *)Ship::getCargo(pSVar17);
                iVar7 = Globals::ships;
                iVar8 = Ship::getIndex(*(Ship **)(*(int *)pHVar32 + 0xc));
                this_02 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(iVar7 + 4) + iVar8 * 4),-1);
                iVar7 = Ship::getRace(*(Ship **)(*(int *)pHVar32 + 0xc));
                Ship::setRace(this_02,iVar7);
                uVar26 = Ship::adjustPrice(this_02);
                if ((puVar22 != (uint *)0x0) && (uVar25 = *puVar22, uVar25 != 0)) {
                  uVar27 = 0;
                  do {
                    pIVar23 = *(Item **)(puVar22[1] + uVar27 * 4);
                    uVar26 = 0;
                    if (pIVar23 != (Item *)0x0) {
                      pIVar23 = (Item *)Item::clone(pIVar23);
                      uVar26 = Ship::addCargo(this_02,pIVar23);
                      uVar25 = *puVar22;
                    }
                    uVar27 = uVar27 + 1;
                  } while (uVar27 < uVar25);
                }
                if (puVar13 != (uint *)0x0) {
                  uVar26 = *puVar13;
                }
                if (puVar13 != (uint *)0x0 && uVar26 != 0) {
                  uVar26 = 0;
                  do {
                    pIVar23 = *(Item **)(puVar13[1] + uVar26 * 4);
                    if (pIVar23 != (Item *)0x0) {
                      pIVar23 = (Item *)Item::clone(pIVar23);
                      iVar7 = Ship::addEquipment(this_02,pIVar23);
                      if (iVar7 == 0) {
                        Ship::addCargo(this_02,pIVar23);
                      }
                    }
                    uVar26 = uVar26 + 1;
                  } while (uVar26 < *puVar13);
                }
                iVar7 = Ship::getMods(*(Ship **)(*(int *)pHVar32 + 0xc));
                if ((iVar7 != 0) &&
                   (piVar24 = (int *)Ship::getMods(*(Ship **)(*(int *)pHVar32 + 0xc)), *piVar24 != 0
                   )) {
                  uVar26 = 0;
                  do {
                    iVar7 = Ship::getMods(*(Ship **)(*(int *)pHVar32 + 0xc));
                    Ship::addMod(this_02,*(int *)(*(int *)(iVar7 + 4) + uVar26 * 4));
                    puVar13 = (uint *)Ship::getMods(*(Ship **)(*(int *)pHVar32 + 0xc));
                    uVar26 = uVar26 + 1;
                  } while (uVar26 < *puVar13);
                }
                pSVar11 = (Station *)Status::getStation(Globals::status);
                pAVar15 = (Array *)Station::getShips(pSVar11);
                if (*(int *)pAVar15 != 0) {
                  uVar26 = 0;
                  do {
                    iVar7 = Ship::getIndex(*(Ship **)(*(int *)(pAVar15 + 4) + uVar26 * 4));
                    iVar8 = Ship::getIndex(*(Ship **)(*(int *)pHVar32 + 0xc));
                    if (iVar7 == iVar8) {
                      iVar7 = *(int *)(pAVar15 + 4);
                      pSVar30 = *(Ship **)(iVar7 + uVar26 * 4);
                      if (bVar6) {
                        ArrayRemove<Ship*>(pSVar30,pAVar15);
                        uVar26 = 0xffffffff;
                        goto LAB_0017800e;
                      }
                      if (pSVar30 != (Ship *)0x0) {
                        pvVar28 = (void *)Ship::~Ship(pSVar30);
                        operator_delete(pvVar28);
                        iVar7 = *(int *)(pAVar15 + 4);
                      }
                      *(undefined4 *)(iVar7 + uVar26 * 4) = 0;
                      iVar7 = Globals::ships;
                      iVar8 = Ship::getIndex(pSVar17);
                      uVar10 = Ship::makeShip(*(Ship **)(*(int *)(iVar7 + 4) + iVar8 * 4),-1);
                      *(undefined4 *)(*(int *)(pAVar15 + 4) + uVar26 * 4) = uVar10;
                      Ship::adjustPrice(*(Ship **)(*(int *)(pAVar15 + 4) + uVar26 * 4));
                      pSVar30 = *(Ship **)(*(int *)(pAVar15 + 4) + uVar26 * 4);
                      iVar7 = Ship::getRace(pSVar17);
                      Ship::setRace(pSVar30,iVar7);
                      goto LAB_00177fee;
                    }
                    uVar26 = uVar26 + 1;
                  } while (uVar26 < *(uint *)pAVar15);
                }
                uVar26 = 0xffffffff;
LAB_00177fee:
                if (bVar6) {
LAB_0017800e:
                  iVar7 = Globals::ships;
                  pSVar11 = *(Station **)(Globals::status + 0x14c);
                  iVar8 = Ship::getIndex(pSVar17);
                  pSVar30 = (Ship *)Ship::makeShip(*(Ship **)(*(int *)(iVar7 + 4) + iVar8 * 4),-1);
                  Station::addShip(pSVar11,pSVar30);
                  iVar7 = Ship::getMods(pSVar17);
                  if ((iVar7 != 0) && (piVar24 = (int *)Ship::getMods(pSVar17), *piVar24 != 0)) {
                    uVar25 = 0;
                    do {
                      iVar7 = Station::getShips(*(Station **)(Globals::status + 0x14c));
                      piVar24 = (int *)Station::getShips(*(Station **)(Globals::status + 0x14c));
                      pSVar30 = *(Ship **)(*(int *)(iVar7 + 4) + *piVar24 * 4 + -4);
                      iVar7 = Ship::getMods(pSVar17);
                      Ship::addMod(pSVar30,*(int *)(*(int *)(iVar7 + 4) + uVar25 * 4));
                      puVar13 = (uint *)Ship::getMods(pSVar17);
                      uVar25 = uVar25 + 1;
                    } while (uVar25 < *puVar13);
                  }
                }
                iVar7 = Ship::getMods(pSVar17);
                if (((-1 < (int)uVar26) && (iVar7 != 0)) &&
                   (piVar24 = (int *)Ship::getMods(pSVar17), *piVar24 != 0)) {
                  uVar25 = 0;
                  do {
                    if (this[0x11d] != (HangarWindow)0x0) {
                      iVar7 = Station::getShips(*(Station **)(Globals::status + 0x14c));
                      pSVar30 = *(Ship **)(*(int *)(iVar7 + 4) + uVar26 * 4);
                      iVar7 = Ship::getMods(pSVar17);
                      Ship::addMod(pSVar30,*(int *)(*(int *)(iVar7 + 4) + uVar25 * 4));
                    }
                    pSVar30 = *(Ship **)(*(int *)(pAVar15 + 4) + uVar26 * 4);
                    iVar7 = Ship::getMods(pSVar17);
                    Ship::addMod(pSVar30,*(int *)(*(int *)(iVar7 + 4) + uVar25 * 4));
                    puVar13 = (uint *)Ship::getMods(pSVar17);
                    uVar25 = uVar25 + 1;
                  } while (uVar25 < *puVar13);
                }
                if (this[0x11d] != (HangarWindow)0x0) {
                  this_05 = *(Station **)(Globals::status + 0x14c);
                  pSVar11 = (Station *)Status::getStation(Globals::status);
                  pAVar15 = (Array *)Station::getShips(pSVar11);
                  Station::setShips(this_05,pAVar15,true);
                }
                Status::setShip(Globals::status,this_02);
                pSVar17 = (Ship *)Status::getShip(Globals::status);
                Ship::refreshValue(pSVar17);
                pHVar29 = *(HangarList **)(this + 0x14);
                pSVar17 = (Ship *)Status::getShip(Globals::status);
                HangarList::initShipTab(pHVar29,pSVar17);
                if (*(Array **)(this + 0x10) != (Array *)0x0) {
                  ArrayReleaseClasses<Item*>(*(Array **)(this + 0x10));
                  pvVar28 = *(void **)(this + 0x10);
                  if (pvVar28 != (void *)0x0) {
                    if (*(void **)((int)pvVar28 + 4) != (void *)0x0) {
                      operator_delete__(*(void **)((int)pvVar28 + 4));
                    }
                    operator_delete(pvVar28);
                  }
                }
                *(undefined4 *)(this + 0x10) = 0;
                pSVar17 = (Ship *)Status::getShip(Globals::status);
                pAVar15 = (Array *)Ship::getCargo(pSVar17);
                pSVar11 = (Station *)Status::getStation(Globals::status);
                pAVar33 = (Array *)Station::getItems(pSVar11);
                pAVar15 = (Array *)Item::mixItems(pAVar15,pAVar33);
                *(Array **)(this + 0x10) = pAVar15;
                pHVar29 = *(HangarList **)(this + 0x14);
                pSVar11 = (Station *)Status::getStation(Globals::status);
                pAVar33 = (Array *)Station::getShips(pSVar11);
                HangarList::initShopTab(pHVar29,pAVar15,pAVar33);
                HangarList::setCurrentTab(*(int *)(this + 0x14),false);
                refreshCurrentContentHeight(this);
                this[0x3c] = (HangarWindow)0x0;
                if (this[0x11d] == (HangarWindow)0x0) {
                  pSVar9 = (String *)GameText::getText(Globals::gameText,0x12f);
                  AbyssEngine::String::String(aSStack_30,pSVar9,false);
                  pSVar18 = Globals::status;
                  AbyssEngine::String::String(aSStack_90,aSStack_30,false);
                  this_00 = Globals::gameText;
                  iVar7 = Ship::getIndex(this_02);
                  pSVar9 = (String *)GameText::getText(this_00,iVar7 + 0x391);
                  AbyssEngine::String::String(aSStack_98,pSVar9,false);
                  uVar10 = AbyssEngine::String::String(aSStack_a0,"#N",false);
                  Status::replaceHash(aSStack_48,pSVar18,aSStack_90,aSStack_98,uVar10);
                  AbyssEngine::String::operator=(aSStack_30,aSStack_48);
                  AbyssEngine::String::~String(aSStack_48);
                  AbyssEngine::String::~String(aSStack_a0);
                  AbyssEngine::String::~String(aSStack_98);
                  AbyssEngine::String::~String(aSStack_90);
                  ChoiceWindow::set(*(ChoiceWindow **)pHVar34,aSStack_30);
                  this[0x3c] = (HangarWindow)0x1;
                  AbyssEngine::String::~String(aSStack_30);
                }
                this[0x90] = (HangarWindow)0x0;
                this[0x91] = (HangarWindow)0x0;
                *this = (HangarWindow)0x1;
                goto LAB_00176dc2;
              }
LAB_00177d1c:
              if (iVar7 == 1) goto LAB_00177e68;
              if (iVar7 == 0) {
LAB_00177d28:
                bVar6 = false;
                goto LAB_00177d2c;
              }
            }
          }
        }
        else {
          iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
          if (iVar7 == 1) {
            this[0x3c] = (HangarWindow)0x0;
            this[0x93] = (HangarWindow)0x0;
          }
          else if (iVar7 == 0) {
            this[0x3c] = (HangarWindow)0x0;
            this[0x93] = (HangarWindow)0x0;
            pSVar18 = Globals::status;
            iVar7 = ::ListItem::getPrice(*(ListItem **)(this + 0x68));
            Status::changeCredits(pSVar18,iVar7);
            pSVar11 = (Station *)Status::getStation(Globals::status);
            Station::removeShip(pSVar11,*(Ship **)(*(int *)(this + 0x68) + 0xc));
            pAVar33 = *(Array **)(this + 0x10);
            pHVar29 = *(HangarList **)(this + 0x14);
            pSVar11 = (Station *)Status::getStation(Globals::status);
            pAVar15 = (Array *)Station::getShips(pSVar11);
            HangarList::initShopTab(pHVar29,pAVar33,pAVar15);
            refreshCurrentContentHeight(this);
          }
        }
        goto LAB_001773f4;
      }
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
      if (iVar7 != 0) {
LAB_0017732a:
        pHVar34 = this + 0x24;
        iVar7 = 0;
        do {
          iVar8 = TouchButton::OnTouchEnd
                            (*(TouchButton **)(*(int *)(*(int *)pHVar34 + 4) + iVar7 * 4 + 0x30),
                             param_1,param_2);
          if (iVar8 == 1) {
            switch(iVar7) {
            case 0:
              NFC::iap_buy_credits_100_000();
              break;
            case 1:
              NFC::iap_buy_credits_300_000();
              break;
            case 2:
              NFC::iap_buy_credits_1_000_000();
              break;
            case 3:
              NFC::iap_buy_credits_3_000_000();
              break;
            case 4:
              NFC::iap_buy_credits_10_000_000();
            }
            break;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < 5);
        iVar7 = TouchButton::OnTouchEnd
                          (*(TouchButton **)(*(int *)(*(int *)pHVar34 + 4) + 0x44),param_1,param_2);
        cVar5 = Globals::options[0x4c];
        uVar4 = Globals::options._74_2_;
        cVar3 = Globals::options[0x49];
        if (iVar7 == 1) {
          uVar26 = (uint)Globals::options[0x4d];
          uVar37 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
          if ((uVar4 & 0xff) != 0) {
            uVar25 = (uint)((ulonglong)uVar37 >> 0x20);
            if (cVar3 != '\0') {
              uVar25 = uVar26;
            }
            if (((cVar3 != '\0' && uVar25 != 0) && (cVar5 != '\0')) &&
               ((0xff < (ushort)uVar4 && (*(char *)((int)uVar37 + 0x15) != '\0'))))
            goto LAB_001773f4;
          }
          iVar7 = 0xc;
          do {
            TouchButton::setVisible
                      (*(TouchButton **)(*(int *)(*(int *)pHVar34 + 4) + iVar7 * 4),false);
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0x11);
          showFreeCreditsWindow(this);
        }
        goto LAB_001773f4;
      }
      this[0x3c] = (HangarWindow)0x0;
      iVar8 = 0xc;
      this[0xae] = (HangarWindow)0x0;
      iVar7 = *(int *)(this + 0x24);
      do {
        TouchButton::setVisible(*(TouchButton **)(*(int *)(iVar7 + 4) + iVar8 * 4),false);
        iVar7 = *(int *)(this + 0x24);
        iVar8 = iVar8 + 1;
      } while (iVar8 != 0x11);
      TouchButton::setVisible(*(TouchButton **)(*(int *)(iVar7 + 4) + 0x44),false);
      iVar7 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
      *(undefined1 *)(iVar7 + 0x34) = 0;
      iVar7 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
      if ((iVar7 == 0) || (*(char *)(iVar7 + 0x18) == '\0')) goto LAB_0017732a;
    }
    else {
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
      if (iVar7 == 1) {
        this[0x11c] = (HangarWindow)0x0;
        this[0x3c] = (HangarWindow)0x0;
        *(undefined4 *)(this + 0xb4) = *(undefined4 *)(this + 0xe4);
      }
      else if (((iVar7 == 0) && (*(int *)(this + 0x28) != 0)) &&
              (*(Item **)(this + 0x2c) != (Item *)0x0)) {
        demountItem(this,*(Item **)(this + 0x2c),-1);
        *(undefined4 *)(this + 0xe4) = *(undefined4 *)(this + 0xb4);
        mountItem(this,*(Item **)(this + 0x28));
        this[0x11c] = (HangarWindow)0x0;
        this[0x3c] = (HangarWindow)0x0;
      }
LAB_001773f4:
      HVar1 = this[0x88];
      iVar7 = ChoiceWindow::OnTouchEnd(*(ChoiceWindow **)(this + 0x20),param_1,param_2);
      if (HVar1 != (HangarWindow)0x0) {
        if (iVar7 != 1) {
          if (iVar7 != 0) goto LAB_00176dc2;
          if (this[0x130] == (HangarWindow)0x0) {
            this[0x3c] = (HangarWindow)0x0;
            if (this[0xad] == (HangarWindow)0x0) {
              this[0x88] = (HangarWindow)0x1;
            }
            else {
              puVar13 = *(uint **)(this + 4);
              if (*puVar13 != 0) {
                uVar26 = 0;
                do {
                  TouchButton::resetTouch(*(TouchButton **)(puVar13[1] + uVar26 * 4));
                  puVar13 = *(uint **)(this + 4);
                  uVar26 = uVar26 + 1;
                } while (uVar26 < *puVar13);
              }
            }
            goto LAB_00176dc2;
          }
          this[0x130] = (HangarWindow)0x0;
        }
        this[0x3c] = (HangarWindow)0x0;
        this[0x88] = (HangarWindow)0x0;
        *(undefined4 *)(this + 0x68) = 0;
        goto LAB_00177428;
      }
      if (iVar7 != 0) goto LAB_00176dc2;
      this[0x3c] = (HangarWindow)0x0;
      iVar7 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
      if (*(char *)(iVar7 + 0x18) == '\0') goto LAB_00176dc2;
    }
    *(undefined1 *)(iVar7 + 0x18) = 0;
  }
LAB_00176dc2:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== HangarWindow::demountItem  @0x00178674  (416 bytes)
/* HangarWindow::demountItem(Item*, int) */

void __thiscall HangarWindow::demountItem(HangarWindow *this,Item *param_1,int param_2)

{
  int iVar1;
  Item *this_00;
  Ship *pSVar2;
  int iVar3;
  void *pvVar4;
  Array *pAVar5;
  Station *pSVar6;
  Array *pAVar7;
  undefined4 uVar8;
  uint *puVar9;
  HangarList *pHVar10;
  uint uVar11;
  Item *this_01;
  float fVar12;
  
  iVar1 = Item::getType(param_1);
  if (iVar1 == 1) {
    iVar1 = Item::getAmount(param_1);
  }
  else {
    iVar1 = 1;
  }
  this_00 = (Item *)Item::makeItem(param_1,iVar1);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  Ship::addCargo(pSVar2,this_00);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  if (param_2 < 0) {
    Ship::freeSlot(pSVar2,param_1);
  }
  else {
    Ship::freeSlot(pSVar2,param_1,param_2);
  }
  puVar9 = *(uint **)(this + 0x10);
  if (*puVar9 == 0) {
    uVar11 = 1;
  }
  else {
    uVar11 = 0;
    do {
      this_01 = *(Item **)(puVar9[1] + uVar11 * 4);
      iVar1 = Item::getIndex(this_01);
      iVar3 = Item::getIndex(this_00);
      if (iVar1 == iVar3) {
        iVar1 = Item::getAmount(this_00);
        Item::changeAmount(this_01,iVar1);
        goto LAB_00178726;
      }
      puVar9 = *(uint **)(this + 0x10);
      uVar11 = uVar11 + 1;
    } while (uVar11 < *puVar9);
    uVar11 = *puVar9 + 1;
  }
  puVar9[2] = uVar11;
  pvVar4 = realloc((void *)puVar9[1],uVar11 << 2);
  puVar9[1] = (uint)pvVar4;
  *(Item **)((int)pvVar4 + *puVar9 * 4) = this_00;
  *puVar9 = puVar9[2];
LAB_00178726:
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  pAVar5 = (Array *)Item::extractItems(*(Array **)(this + 0x10),true);
  Ship::setCargo(pSVar2,pAVar5);
  if (*(Array **)(this + 0x10) != (Array *)0x0) {
    ArrayReleaseClasses<Item*>(*(Array **)(this + 0x10));
    pvVar4 = *(void **)(this + 0x10);
    if (pvVar4 != (void *)0x0) {
      if (*(void **)((int)pvVar4 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar4 + 4));
      }
      operator_delete(pvVar4);
    }
  }
  *(undefined4 *)(this + 0x10) = 0;
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  pAVar5 = (Array *)Ship::getCargo(pSVar2);
  pSVar6 = (Station *)Status::getStation(Globals::status);
  pAVar7 = (Array *)Station::getItems(pSVar6);
  uVar8 = Item::mixItems(pAVar5,pAVar7);
  *(undefined4 *)(this + 0x10) = uVar8;
  pHVar10 = *(HangarList **)(this + 0x14);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  HangarList::initShipTab(pHVar10,pSVar2);
  pHVar10 = *(HangarList **)(this + 0x14);
  pSVar2 = (Ship *)Status::getShip(Globals::status);
  pAVar5 = (Array *)Ship::getCargo(pSVar2);
  pSVar6 = (Station *)Status::getStation(Globals::status);
  pAVar7 = (Array *)Station::getItems(pSVar6);
  pAVar5 = (Array *)Item::mixItems(pAVar5,pAVar7);
  pSVar6 = (Station *)Status::getStation(Globals::status);
  pAVar7 = (Array *)Station::getShips(pSVar6);
  HangarList::initShopTab(pHVar10,pAVar5,pAVar7);
  HangarList::setCurrentTab(*(int *)(this + 0x14),false);
  fVar12 = (float)refreshCurrentContentHeight(this);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(this + 0xe4);
  FModSound::play(Globals::sound,0x60,(Vector *)0x0,(Vector *)0x0,fVar12);
  return;
}

// ===== HangarWindow::mountItem  @0x00178824  (376 bytes)
/* HangarWindow::mountItem(Item*) */

void __thiscall HangarWindow::mountItem(HangarWindow *this,Item *param_1)

{
  int iVar1;
  int iVar2;
  Item *pIVar3;
  Ship *pSVar4;
  int iVar5;
  uint *puVar6;
  Array *pAVar7;
  Station *pSVar8;
  Array *pAVar9;
  HangarList *pHVar10;
  uint uVar11;
  float fVar12;
  
  iVar1 = Item::getType(param_1);
  if (iVar1 == 1) {
    iVar2 = Item::getAmount(param_1);
  }
  else {
    iVar2 = 1;
  }
  pIVar3 = (Item *)Item::makeItem(param_1,iVar2);
  pSVar4 = (Ship *)Status::getShip(Globals::status);
  Ship::addEquipment(pSVar4,pIVar3);
  pSVar4 = (Ship *)Status::getShip(Globals::status);
  iVar2 = Item::getIndex(pIVar3);
  if (iVar1 == 1) {
    iVar5 = Item::getAmount(pIVar3);
  }
  else {
    iVar5 = 1;
  }
  Ship::removeCargo(pSVar4,iVar2,iVar5);
  puVar6 = *(uint **)(this + 0x10);
  if ((puVar6 != (uint *)0x0) && (*puVar6 != 0)) {
    uVar11 = 0;
    do {
      pIVar3 = *(Item **)(puVar6[1] + uVar11 * 4);
      iVar2 = Item::getIndex(pIVar3);
      iVar5 = Item::getIndex(param_1);
      if (iVar2 == iVar5) {
        iVar2 = Item::getStationAmount(pIVar3);
        if (iVar2 == 0) {
          if ((iVar1 == 1) || (iVar1 = Item::getAmount(pIVar3), iVar1 == 1)) {
            ArrayRemove<Item*>(pIVar3,*(Array **)(this + 0x10));
            break;
          }
LAB_001788f2:
          iVar1 = -1;
        }
        else {
          if (iVar1 != 1) goto LAB_001788f2;
          iVar1 = Item::getAmount(pIVar3);
          iVar1 = -iVar1;
        }
        Item::changeAmount(pIVar3,iVar1);
        break;
      }
      puVar6 = *(uint **)(this + 0x10);
      uVar11 = uVar11 + 1;
    } while (uVar11 < *puVar6);
  }
  pSVar4 = (Ship *)Status::getShip(Globals::status);
  pAVar7 = (Array *)Item::extractItems(*(Array **)(this + 0x10),true);
  Ship::setCargo(pSVar4,pAVar7);
  pHVar10 = *(HangarList **)(this + 0x14);
  pSVar4 = (Ship *)Status::getShip(Globals::status);
  HangarList::initShipTab(pHVar10,pSVar4);
  pHVar10 = *(HangarList **)(this + 0x14);
  pSVar4 = (Ship *)Status::getShip(Globals::status);
  pAVar7 = (Array *)Ship::getCargo(pSVar4);
  pSVar8 = (Station *)Status::getStation(Globals::status);
  pAVar9 = (Array *)Station::getItems(pSVar8);
  pAVar7 = (Array *)Item::mixItems(pAVar7,pAVar9);
  pSVar8 = (Station *)Status::getStation(Globals::status);
  pAVar9 = (Array *)Station::getShips(pSVar8);
  HangarList::initShopTab(pHVar10,pAVar7,pAVar9);
  HangarList::setCurrentTab(*(int *)(this + 0x14),false);
  fVar12 = (float)refreshCurrentContentHeight(this);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(this + 0xe4);
  FModSound::play(Globals::sound,0x62,(Vector *)0x0,(Vector *)0x0,fVar12);
  return;
}

// ===== HangarWindow::showCreditsBuyWindow  @0x001789a8  (416 bytes)
/* HangarWindow::showCreditsBuyWindow() */

void __thiscall HangarWindow::showCreditsBuyWindow(HangarWindow *this)

{
  int iVar1;
  String *pSVar2;
  ChoiceWindow *pCVar3;
  uint in_fpscr;
  float fVar4;
  String aSStack_3c [8];
  String aSStack_34 [8];
  String aSStack_2c [8];
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  *(undefined1 *)(iVar1 + 0x40) = 0;
  iVar1 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  *(undefined1 *)(iVar1 + 0x31) = 1;
  pCVar3 = *(ChoiceWindow **)(this + 0x20);
  if (this[0x11f] == (HangarWindow)0x0) {
    AbyssEngine::String::String(aSStack_24,"",false);
    AbyssEngine::String::String(aSStack_2c,"\n\n\n\n\n\n\n\n",false);
    AbyssEngine::String::String(aSStack_34,"",false);
    AbyssEngine::String::String(aSStack_3c,"",false);
    pSVar2 = (String *)GameText::getText(Globals::gameText,0xaa);
    ChoiceWindow::set(pCVar3,aSStack_24,aSStack_2c,false,aSStack_34,aSStack_3c,pSVar2,-1,-1);
    AbyssEngine::String::~String(aSStack_3c);
    AbyssEngine::String::~String(aSStack_34);
    AbyssEngine::String::~String(aSStack_2c);
    AbyssEngine::String::~String(aSStack_24);
  }
  else {
    AbyssEngine::String::String(aSStack_24,"",false);
    AbyssEngine::String::String(aSStack_2c,"",false);
    AbyssEngine::String::String(aSStack_34,"",false);
    AbyssEngine::String::String(aSStack_3c,"",false);
    pSVar2 = (String *)GameText::getText(Globals::gameText,0xaa);
    ChoiceWindow::set(pCVar3,aSStack_24,aSStack_2c,false,aSStack_34,aSStack_3c,pSVar2,-1,-1);
    AbyssEngine::String::~String(aSStack_3c);
    AbyssEngine::String::~String(aSStack_34);
    AbyssEngine::String::~String(aSStack_2c);
    AbyssEngine::String::~String(aSStack_24);
    if (Globals::iPad == '\0') {
      ChoiceWindow::setWidth(*(ChoiceWindow **)(this + 0x20),Globals::w);
      pCVar3 = *(ChoiceWindow **)(this + 0x20);
      iVar1 = Globals::h;
    }
    else {
      ChoiceWindow::setWidth(*(ChoiceWindow **)(this + 0x20),*(int *)(this + 0x120) * 3);
      fVar4 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x124),(byte)(in_fpscr >> 0x16) & 3)
      ;
      pCVar3 = *(ChoiceWindow **)(this + 0x20);
      iVar1 = (int)(fVar4 * 2.3);
    }
    ChoiceWindow::setHeight(pCVar3,iVar1);
  }
  this[0x3c] = (HangarWindow)0x1;
  this[0xae] = (HangarWindow)0x1;
  this[0xaf] = (HangarWindow)0x0;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== HangarWindow::showFreeCreditsWindow  @0x00178bc4  (388 bytes)
/* HangarWindow::showFreeCreditsWindow() */

void __thiscall HangarWindow::showFreeCreditsWindow(HangarWindow *this)

{
  PaintCanvas *this_00;
  uint uVar1;
  int iVar2;
  String *pSVar3;
  int iVar4;
  ChoiceWindow *pCVar5;
  int iVar6;
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar2 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  *(undefined1 *)(iVar2 + 0x40) = 0;
  iVar2 = AbyssEngine::ApplicationManager::GetApplicationData(Globals::appManager);
  *(undefined1 *)(iVar2 + 0x31) = 1;
  pCVar5 = *(ChoiceWindow **)(this + 0x20);
  AbyssEngine::String::String(aSStack_30,"",false);
  AbyssEngine::String::String(aSStack_38,"",false);
  AbyssEngine::String::String(aSStack_40,"",false);
  AbyssEngine::String::String(aSStack_48,"",false);
  pSVar3 = (String *)GameText::getText(Globals::gameText,0xaa);
  ChoiceWindow::set(pCVar5,aSStack_30,aSStack_38,false,aSStack_40,aSStack_48,pSVar3,-1,-1);
  AbyssEngine::String::~String(aSStack_48);
  AbyssEngine::String::~String(aSStack_40);
  AbyssEngine::String::~String(aSStack_38);
  AbyssEngine::String::~String(aSStack_30);
  pCVar5 = *(ChoiceWindow **)(this + 0x20);
  iVar2 = TouchButton::getHeight(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x48));
  ChoiceWindow::setHeight(pCVar5,iVar2 * 5);
  iVar6 = 0;
  iVar2 = 0;
  do {
    while( true ) {
      uVar1 = Globals::font;
      this_00 = Globals::Canvas;
      if (iVar6 != 0) break;
      pSVar3 = (String *)GameText::getText(Globals::gameText,0xd48);
      iVar6 = AbyssEngine::PaintCanvas::GetTextWidth(this_00,uVar1,pSVar3);
      if (iVar2 < iVar6) {
        iVar2 = iVar6;
      }
      iVar6 = 1;
    }
    pSVar3 = (String *)GameText::getText(Globals::gameText,iVar6 + 0x70);
    iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(this_00,uVar1,pSVar3);
    iVar6 = iVar6 + 1;
    if (iVar2 < iVar4) {
      iVar2 = iVar4;
    }
  } while (iVar6 != 5);
  iVar6 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 0x24) + 4) + 0x48));
  ChoiceWindow::setWidth
            (*(ChoiceWindow **)(this + 0x20),
             *(int *)(Globals::layout + 0x2c) + iVar6 + iVar2 + *(int *)(Globals::layout + 0x28) * 4
            );
  this[0x3c] = (HangarWindow)0x1;
  this[0xb0] = (HangarWindow)0x1;
  this[0xae] = (HangarWindow)0x0;
  this[0xaf] = (HangarWindow)0x0;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== HangarWindow::readyToClose  @0x00178da0  (94 bytes)
/* HangarWindow::readyToClose() */

bool __thiscall HangarWindow::readyToClose(HangarWindow *this)

{
  int iVar1;
  Station *this_00;
  int iVar2;
  
  iVar1 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
  if ((((iVar1 == 4) && (this[0x88] != (HangarWindow)0x0)) && (0 < *(int *)(this + 0x94))) &&
     ((this[0x3c] == (HangarWindow)0x0 &&
      (iVar1 = BluePrint::isEmpty(*(BluePrint **)(this + 0x80)), iVar1 == 0)))) {
    iVar1 = BluePrint::getStationIndex(*(BluePrint **)(this + 0x80));
    this_00 = (Station *)Status::getStation(Globals::status);
    iVar2 = Station::getIndex(this_00);
    if (iVar1 != iVar2) {
      return false;
    }
  }
  return this[0x3c] == (HangarWindow)0x0;
}

// ===== HangarWindow::currentItemIsHighlighted  @0x00178e04  (28 bytes)
/* HangarWindow::currentItemIsHighlighted() */

undefined4 __thiscall HangarWindow::currentItemIsHighlighted(HangarWindow *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
  uVar2 = 0;
  if ((iVar1 != 0) && (iVar1 == *(int *)(this + 0x68))) {
    uVar2 = 1;
  }
  return uVar2;
}

// ===== HangarWindow::selectItem  @0x00178e20  (1746 bytes)
/* HangarWindow::selectItem(ListItem*) */

void __thiscall HangarWindow::selectItem(HangarWindow *this,ListItem *param_1)

{
  HangarWindow HVar1;
  Status *pSVar2;
  GameText *pGVar3;
  bool bVar4;
  int iVar5;
  String *pSVar6;
  int iVar7;
  Ship *pSVar8;
  Array *pAVar9;
  Station *pSVar10;
  Array *pAVar11;
  undefined4 uVar12;
  int iVar13;
  void *pvVar14;
  ChoiceWindow *pCVar15;
  Item *pIVar16;
  HangarList *pHVar17;
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
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  *(ListItem **)(this + 0x68) = param_1;
  if ((param_1 != (ListItem *)0x0) && (iVar5 = ::ListItem::isShip(param_1), iVar5 == 1)) {
    Ship::adjustPrice(*(Ship **)(*(int *)(this + 0x68) + 0xc));
  }
  iVar5 = HangarList::getCurrentTab(*(HangarList **)(this + 0x14));
  if (iVar5 == 2) {
    iVar5 = ::ListItem::isSelectable(param_1);
    if ((iVar5 == 1) && (iVar5 = ::ListItem::isPendingProduct(param_1), iVar5 == 0)) {
      uVar12 = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(this + 0x80) = uVar12;
      HangarList::fillIngredientsList(*(BluePrint **)(this + 0x14),SUB41(uVar12,0));
      HangarList::setCurrentTab(*(int *)(this + 0x14),true);
      refreshCurrentContentHeight(this);
      if (this[0x89] != (HangarWindow)0x0) {
        this[0x89] = (HangarWindow)0x0;
      }
    }
    goto LAB_001794d8;
  }
  if (iVar5 != 1) {
    if ((iVar5 != 0) || (iVar5 = ::ListItem::isSelectable(param_1), iVar5 != 1)) goto LAB_001794d8;
    *(undefined4 *)(this + 0xe4) = *(undefined4 *)(this + 0xb4);
    *(undefined4 *)(this + 0xbc) = 0;
    *(undefined4 *)(this + 0xb4) = 0;
    if ((Globals::hints[0x1f] == '\0') && (iVar5 = ::ListItem::isSlot(param_1), iVar5 == 1)) {
      pCVar15 = *(ChoiceWindow **)(this + 0x20);
      pSVar6 = (String *)GameText::getText(Globals::gameText,0x24b);
      ChoiceWindow::set(pCVar15,pSVar6);
      Globals::hints[0x1f] = '\x01';
      this[0x3c] = (HangarWindow)0x1;
    }
    iVar5 = ::ListItem::isSelectable(param_1);
    if (iVar5 != 1) goto LAB_001794d8;
    iVar5 = HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
    pIVar16 = *(Item **)(iVar5 + 0x10);
    if (pIVar16 != (Item *)0x0) {
      iVar5 = Item::isUnsaleable(pIVar16);
      if (iVar5 == 1) {
LAB_00178ef0:
        iVar5 = 0x143;
        pCVar15 = *(ChoiceWindow **)(this + 0x20);
        goto LAB_00178faa;
      }
      iVar5 = Item::getSort(pIVar16);
      if (iVar5 == 0x14) {
        iVar13 = *(int *)(Globals::status + 0x34);
        iVar5 = iVar13;
        if (0 < iVar13) {
          iVar5 = *(int *)(param_1 + 0x3c);
        }
        iVar7 = iVar13 + -1;
        if (iVar13 >= 1) {
          iVar7 = iVar5;
        }
        if (iVar7 < 0 == (iVar13 < 1 && SBORROW4(iVar13,1))) {
          pSVar8 = (Ship *)Status::getShip(Globals::status);
          iVar5 = Ship::getMaxPassengers(pSVar8);
          iVar13 = Item::getAttribute(pIVar16,0x22);
          if (iVar5 - iVar13 < *(int *)(Globals::status + 0x34)) goto LAB_00178ef0;
        }
      }
    }
    if (-1 < *(int *)(param_1 + 0x3c)) {
      iVar5 = HangarList::getCurrentItem(*(HangarList **)(this + 0x14));
      demountItem(this,pIVar16,*(int *)(iVar5 + 0x40));
      goto LAB_001794d8;
    }
    pSVar8 = (Ship *)Status::getShip(Globals::status);
    iVar5 = Item::getSort(*(Item **)(param_1 + 0x10));
    pIVar16 = (Item *)Ship::getFirstEquipmentOfSort(pSVar8,iVar5);
    iVar5 = Item::getSort(*(Item **)(param_1 + 0x10));
    if (iVar5 == 0x15) {
      pSVar8 = (Ship *)Status::getShip(Globals::status);
      iVar5 = Ship::getIndex(pSVar8);
      if (iVar5 != 0x2c) {
        pSVar8 = (Ship *)Status::getShip(Globals::status);
        iVar5 = Ship::getIndex(pSVar8);
        if (pIVar16 != (Item *)0x0 && iVar5 != 0x31) goto LAB_0017939a;
      }
    }
    else if (pIVar16 != (Item *)0x0) {
LAB_0017939a:
      iVar5 = Item::canBeInstalledMultipleTimes(*(Item **)(param_1 + 0x10));
      if (iVar5 == 0) {
        pSVar6 = (String *)GameText::getText(Globals::gameText,0x11f);
        AbyssEngine::String::String(aSStack_28,pSVar6,false);
        pSVar2 = Globals::status;
        AbyssEngine::String::String(aSStack_40,aSStack_28,false);
        pGVar3 = Globals::gameText;
        iVar5 = Item::getIndex(pIVar16);
        pSVar6 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
        AbyssEngine::String::String(aSStack_48,pSVar6,false);
        uVar12 = AbyssEngine::String::String(aSStack_50,"#ITEM1",false);
        Status::replaceHash(aSStack_38,pSVar2,aSStack_40,aSStack_48,uVar12);
        pGVar3 = Globals::gameText;
        iVar5 = Item::getIndex(*(Item **)(param_1 + 0x10));
        pSVar6 = (String *)GameText::getText(pGVar3,iVar5 + 0x4fa);
        AbyssEngine::String::String(aSStack_58,pSVar6,false);
        uVar12 = AbyssEngine::String::String(aSStack_60,"#ITEM2",false);
        Status::replaceHash(aSStack_30,pSVar2,aSStack_38,aSStack_58,uVar12);
        AbyssEngine::String::operator=(aSStack_28,aSStack_30);
        AbyssEngine::String::~String(aSStack_30);
        AbyssEngine::String::~String(aSStack_60);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::String::~String(aSStack_38);
        AbyssEngine::String::~String(aSStack_50);
        AbyssEngine::String::~String(aSStack_48);
        AbyssEngine::String::~String(aSStack_40);
        ChoiceWindow::set(*(String **)(this + 0x20),(bool)((char)&stack0x00000044 + -0x6c));
        this[0x3c] = (HangarWindow)0x1;
        this[0x11c] = (HangarWindow)0x1;
        *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x10);
        *(Item **)(this + 0x2c) = pIVar16;
        goto LAB_001794d2;
      }
    }
    mountItem(this,*(Item **)(param_1 + 0x10));
    goto LAB_001794d8;
  }
  iVar5 = ::ListItem::isSelectable(param_1);
  if (iVar5 != 1) goto LAB_001794d8;
  iVar5 = ::ListItem::isShip(param_1);
  if (iVar5 != 1) {
    iVar5 = Item::isUnsaleable(*(Item **)(param_1 + 0x10));
    if (iVar5 == 0) {
      HVar1 = this[0x88];
      this[0x88] = (HangarWindow)((byte)HVar1 ^ 1);
      if (HVar1 == (HangarWindow)0x0) {
        if (Globals::hints[0x1d] == '\0') {
          pCVar15 = *(ChoiceWindow **)(this + 0x20);
          pSVar6 = (String *)GameText::getText(Globals::gameText,0x24c);
          ChoiceWindow::set(pCVar15,pSVar6);
          Globals::hints[0x1d] = '\x01';
          this[0x3c] = (HangarWindow)0x1;
        }
        uVar12 = Item::getStationAmount(*(Item **)(param_1 + 0x10));
        *(undefined4 *)(this + 0x8c) = uVar12;
        uVar12 = Item::getAmount(*(Item **)(param_1 + 0x10));
        *(undefined4 *)(this + 0xa0) = uVar12;
        uVar12 = Status::getCredits(Globals::status);
        *(undefined4 *)(this + 0x98) = uVar12;
        *(undefined4 *)(this + 0x9c) = *(undefined4 *)(this + 0xa8);
      }
      else {
        iVar5 = ::ListItem::isItem(param_1);
        if (((iVar5 == 1) && (iVar5 = Item::getType(*(Item **)(param_1 + 0x10)), iVar5 != 4)) &&
           (Globals::hints[0x1e] == '\0')) {
          pCVar15 = *(ChoiceWindow **)(this + 0x20);
          pSVar6 = (String *)GameText::getText(Globals::gameText,0x24d);
          ChoiceWindow::set(pCVar15,pSVar6);
          Globals::hints[0x1e] = '\x01';
          this[0x3c] = (HangarWindow)0x1;
        }
        iVar5 = ::ListItem::getIndex(param_1);
        if ((0x83 < iVar5) && (iVar5 = ::ListItem::getIndex(param_1), iVar5 < 0x9a)) {
          iVar13 = *(int *)(Globals::status + 0xac);
          iVar5 = ::ListItem::getIndex(param_1);
          *(undefined1 *)(iVar5 + *(int *)(iVar13 + 4) + -0x84) = 1;
        }
        this[0xf8] = (HangarWindow)0x1;
        uVar12 = HangarList::getCurrentItemIndex(*(HangarList **)(this + 0x14));
        *(undefined4 *)(this + 0xfc) = uVar12;
        pSVar8 = (Ship *)Status::getShip(Globals::status);
        pAVar9 = (Array *)Item::extractItems(*(Array **)(this + 0x10),true);
        Ship::setCargo(pSVar8,pAVar9);
        pSVar10 = (Station *)Status::getStation(Globals::status);
        pAVar9 = (Array *)Item::extractItems(*(Array **)(this + 0x10),false);
        Station::setItems(pSVar10,pAVar9,false);
        if (*(Array **)(this + 0x10) != (Array *)0x0) {
          ArrayReleaseClasses<Item*>(*(Array **)(this + 0x10));
          pvVar14 = *(void **)(this + 0x10);
          if (pvVar14 != (void *)0x0) {
            if (*(void **)((int)pvVar14 + 4) != (void *)0x0) {
              operator_delete__(*(void **)((int)pvVar14 + 4));
            }
            operator_delete(pvVar14);
          }
        }
        *(undefined4 *)(this + 0x10) = 0;
        pSVar8 = (Ship *)Status::getShip(Globals::status);
        pAVar9 = (Array *)Ship::getCargo(pSVar8);
        pSVar10 = (Station *)Status::getStation(Globals::status);
        pAVar11 = (Array *)Station::getItems(pSVar10);
        pAVar9 = (Array *)Item::mixItems(pAVar9,pAVar11);
        *(Array **)(this + 0x10) = pAVar9;
        pHVar17 = *(HangarList **)(this + 0x14);
        pSVar10 = (Station *)Status::getStation(Globals::status);
        pAVar11 = (Array *)Station::getShips(pSVar10);
        HangarList::initShopTab(pHVar17,pAVar9,pAVar11);
        pHVar17 = *(HangarList **)(this + 0x14);
        pSVar8 = (Ship *)Status::getShip(Globals::status);
        HangarList::initShipTab(pHVar17,pSVar8);
      }
    }
    goto LAB_001794d8;
  }
  iVar5 = Ship::getPrice(*(Ship **)(param_1 + 0xc));
  iVar13 = Status::getCredits(Globals::status);
  pSVar8 = (Ship *)Status::getShip(Globals::status);
  iVar7 = Ship::getPrice(pSVar8);
  pSVar2 = Globals::status;
  if ((iVar7 + iVar13 < iVar5) && (this[0x11d] == (HangarWindow)0x0)) {
    pSVar6 = (String *)GameText::getText(Globals::gameText,0xcb);
    AbyssEngine::String::String(aSStack_68,pSVar6,false);
    ::ListItem::getPrice(param_1);
    Status::getCredits(Globals::status);
    pSVar8 = (Ship *)Status::getShip(Globals::status);
    Ship::getPrice(pSVar8);
    Layout::formatCredits((int)aSStack_30);
    AbyssEngine::String::String(aSStack_70,aSStack_30,false);
    uVar12 = AbyssEngine::String::String(aSStack_78,"#C",false);
    Status::replaceHash(aSStack_28,pSVar2,aSStack_68,aSStack_70,uVar12);
    AbyssEngine::String::~String(aSStack_78);
    AbyssEngine::String::~String(aSStack_70);
    AbyssEngine::String::~String(aSStack_30);
    AbyssEngine::String::~String(aSStack_68);
    AbyssEngine::String::String(aSStack_80,"\n\n",false);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x7c);
    AbyssEngine::operator+((AbyssEngine *)aSStack_30,aSStack_80,pSVar6);
    AbyssEngine::String::operator+=(aSStack_28,aSStack_30);
    AbyssEngine::String::~String(aSStack_30);
    AbyssEngine::String::~String(aSStack_80);
    ChoiceWindow::set(*(String **)(this + 0x20),(bool)((char)&stack0x00000044 + -0x6c));
    this[0xaf] = (HangarWindow)0x1;
    this[0x3c] = (HangarWindow)0x1;
LAB_001794d2:
    AbyssEngine::String::~String(aSStack_28);
    goto LAB_001794d8;
  }
  if (*(int *)(Globals::status + 0x34) < 1) {
    iVar5 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar5 == 0x4d) {
      pSVar8 = (Ship *)Status::getShip(Globals::status);
      iVar5 = Ship::getIndex(pSVar8);
      if (iVar5 == 0x25) {
        iVar5 = 0x145;
        pCVar15 = *(ChoiceWindow **)(this + 0x20);
        goto LAB_00178faa;
      }
    }
    pSVar8 = (Ship *)Status::getShip(Globals::status);
    iVar5 = Ship::getIndex(pSVar8);
    iVar13 = Ship::getIndex(*(Ship **)(param_1 + 0xc));
    pCVar15 = *(ChoiceWindow **)(this + 0x20);
    if (iVar5 != iVar13) {
      this[0x90] = (HangarWindow)0x1;
      iVar5 = 0x130;
      if (this[0x11d] != (HangarWindow)0x0) {
        iVar5 = 0x14d;
      }
      bVar4 = (bool)GameText::getText(Globals::gameText,iVar5);
      ChoiceWindow::set(pCVar15,bVar4);
      this[0x3c] = (HangarWindow)0x1;
      goto LAB_001794d8;
    }
    iVar5 = 0x149;
  }
  else {
    iVar5 = 0x150;
    pCVar15 = *(ChoiceWindow **)(this + 0x20);
  }
LAB_00178faa:
  pSVar6 = (String *)GameText::getText(Globals::gameText,iVar5);
  ChoiceWindow::set(pCVar15,pSVar6);
  this[0x3c] = (HangarWindow)0x1;
LAB_001794d8:
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== HangarWindow::hideMessage  @0x00179630  (8 bytes)
/* HangarWindow::hideMessage() */

void __thiscall HangarWindow::hideMessage(HangarWindow *this)

{
  this[0x3c] = (HangarWindow)0x0;
  return;
}

