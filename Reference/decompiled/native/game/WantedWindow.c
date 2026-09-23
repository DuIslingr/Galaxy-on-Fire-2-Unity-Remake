// Class: WantedWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== WantedWindow::WantedWindow  @0x000f4a58  (168 bytes)
/* WantedWindow::WantedWindow() */

WantedWindow * __thiscall WantedWindow::WantedWindow(WantedWindow *this)

{
  int iVar1;
  
  AbyssEngine::String::String((String *)(this + 0x3c));
  AbyssEngine::String::String((String *)(this + 0x44));
  AbyssEngine::String::String((String *)(this + 0x4c));
  AbyssEngine::String::String((String *)(this + 0x54));
  AbyssEngine::String::String((String *)(this + 0x5c));
  AbyssEngine::String::String((String *)(this + 100));
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  iVar1 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
  *(int *)(this + 0x10) = iVar1 / 2 + -1;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x454,(uint *)(this + 0x94));
  init(this);
  return this;
}

// ===== WantedWindow::init  @0x000f4b4c  (974 bytes)
/* WantedWindow::init() */

void __thiscall WantedWindow::init(WantedWindow *this)

{
  Layout *pLVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  SolarSystem *pSVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  uint uVar10;
  Array *pAVar11;
  TouchButton *pTVar12;
  String *pSVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  undefined4 uVar20;
  bool bVar21;
  
  *(undefined4 *)(this + 0x79) = 0;
  *(undefined4 *)(this + 0x7d) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x81) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x85) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x74) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x78) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  puVar2[1] = puVar3;
  puVar2[2] = 1;
  *puVar3 = 0;
  *puVar2 = 0;
  *(undefined4 **)(this + 0x38) = puVar2;
  puVar4 = (uint *)Status::getWanted(Globals::status);
  iVar14 = *(int *)(Globals::layout + 0x28);
  iVar15 = *(int *)(Globals::layout + 0x4c);
  iVar5 = *(int *)(Globals::layout + 0xcc);
  if (*puVar4 != 0) {
    uVar16 = 0;
    do {
      pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar7 = SolarSystem::getRace(pSVar6);
      iVar8 = Wanted::getBoard(*(Wanted **)(puVar4[1] + uVar16 * 4));
      if (iVar7 == iVar8) {
        pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar7 = SolarSystem::getRace(pSVar6);
        if ((iVar7 != 0) ||
           (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 < 0x80)) {
          pSVar6 = (SolarSystem *)Status::getSystem(Globals::status);
          iVar7 = SolarSystem::getRace(pSVar6);
          if ((iVar7 == 0) ||
             (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 < 0xa2))
          goto LAB_000f4c54;
        }
        piVar18 = *(int **)(this + 0x38);
        uVar20 = *(undefined4 *)(puVar4[1] + uVar16 * 4);
        piVar18[2] = *piVar18 + 1;
        pvVar9 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
        piVar18[1] = (int)pvVar9;
        *(undefined4 *)((int)pvVar9 + *piVar18 * 4) = uVar20;
        *piVar18 = piVar18[2];
      }
LAB_000f4c54:
      uVar16 = uVar16 + 1;
    } while (uVar16 < *puVar4);
  }
  if (Globals::iPad == '\0') {
    *(undefined4 *)(this + 0x1c) = 0;
    *(undefined4 *)(this + 0x20) = 0;
    *(int *)(this + 0x24) = Globals::w;
    *(int *)(this + 0x28) = Globals::h;
  }
  else {
    if (Globals::iPadHD == '\0') {
      uVar16 = 0x28a;
      bVar21 = Globals::iPadLarge != '\0';
      if (bVar21) {
        uVar16 = 0x514;
      }
      uVar10 = 500;
      *(uint *)(this + 0x24) = uVar16;
      if (bVar21) {
        uVar10 = 1000;
      }
      uVar16 = uVar16 >> 1;
    }
    else {
      uVar16 = 0x1c9;
      *(undefined4 *)(this + 0x24) = 0x392;
      uVar10 = 0x2bf;
    }
    *(uint *)(this + 0x28) = uVar10;
    *(uint *)(this + 0x1c) = (Globals::w >> 1) - uVar16;
    *(uint *)(this + 0x20) = (Globals::h >> 1) - (uVar10 >> 1);
  }
  uVar16 = 0;
  uVar10 = 0;
  *(undefined4 *)(this + 0x30) = 0;
  puVar4 = *(uint **)(this + 0x38);
  if (*puVar4 != 0) {
    do {
      iVar7 = Wanted::isActive(*(Wanted **)(puVar4[1] + uVar10 * 4));
      if (iVar7 == 1) {
        *(uint *)(this + 0x30) = uVar10;
        puVar4 = *(uint **)(this + 0x38);
        uVar16 = *puVar4;
        goto LAB_000f4d26;
      }
      puVar4 = *(uint **)(this + 0x38);
      uVar10 = uVar10 + 1;
      uVar16 = *puVar4;
    } while (uVar10 < uVar16);
    uVar10 = *(uint *)(this + 0x30);
  }
LAB_000f4d26:
  if (uVar10 == uVar16 - 1) {
    iVar7 = Wanted::isActive(*(Wanted **)(puVar4[1] + uVar10 * 4));
    if (iVar7 == 1) {
      uVar10 = *(uint *)(this + 0x30);
    }
    else {
      uVar10 = 0;
      *(undefined4 *)(this + 0x30) = 0;
    }
  }
  *(uint *)(this + 0x34) = uVar10;
  selectWanted(this,uVar10);
  pAVar11 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar11 + 4) = puVar2;
  *(undefined4 *)(pAVar11 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar11 = 0;
  *(Array **)(this + 0xc) = pAVar11;
  ArraySetLength<TouchButton*>(2,pAVar11);
  pTVar12 = operator_new(0xc0);
  pSVar13 = (String *)GameText::getText(Globals::gameText,0xc93);
  iVar8 = *(int *)(this + 0x1c);
  iVar19 = *(int *)(this + 0x24);
  iVar7 = Layout::getHelpButtonOffset(Globals::layout);
  TouchButton::TouchButton(pTVar12,pSVar13,3,(iVar19 + iVar8) - iVar7,*(int *)(this + 0x20),'\x12');
  *(TouchButton **)(*(int *)(*(int *)(this + 0xc) + 4) + 4) = pTVar12;
  pTVar12 = operator_new(0xc0);
  pSVar13 = (String *)GameText::getText(Globals::gameText,0x81);
  iVar19 = *(int *)(this + 0x1c);
  iVar17 = *(int *)(this + 0x24);
  iVar7 = Layout::getHelpButtonOffset(Globals::layout);
  iVar8 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 0xc) + 4) + 4));
  TouchButton::TouchButton
            (pTVar12,pSVar13,3,
             (((iVar17 + iVar19) - iVar7) - iVar8) + *(int *)(Globals::layout + 0x38),
             *(int *)(this + 0x20),'\x12');
  **(undefined4 **)(*(int *)(this + 0xc) + 4) = pTVar12;
  TouchButton::setAlwaysPressed(*(TouchButton **)(*(int *)(*(int *)(this + 0xc) + 4) + 4),true);
  Layout::setWindowDimensions
            (Globals::layout,*(int *)(this + 0x1c),*(int *)(this + 0x20),*(int *)(this + 0x24),
             *(int *)(this + 0x28));
  pLVar1 = Globals::layout;
  *(int *)(this + 0x8c) =
       (*(int *)(Globals::layout + 0x34) + *(int *)(Globals::layout + 0x70)) *
       **(int **)(this + 0x38);
  *(int *)(this + 0x90) =
       (((((*(int *)(this + 0x28) - *(int *)(pLVar1 + 0x10)) - *(int *)(pLVar1 + 0xc)) -
         *(int *)(pLVar1 + 0x20)) - *(int *)(pLVar1 + 0x24)) - *(int *)(pLVar1 + 0x5c)) +
       *(int *)(pLVar1 + 0x2c);
  if (*(TouchButton **)(this + 0x18) != (TouchButton *)0x0) {
    pvVar9 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x18));
    operator_delete(pvVar9);
  }
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined2 *)(this + 0x14) = 0;
  pTVar12 = operator_new(0xc0);
  pSVar13 = (String *)GameText::getText(Globals::gameText,0x1a8);
  TouchButton::TouchButton
            (pTVar12,pSVar13,0,
             *(int *)(this + 0x1c) + (*(int *)(this + 0x24) >> 1) + *(int *)(Globals::layout + 0x2c)
             ,((*(int *)(this + 0x28) + (*(int *)(this + 0x20) - *(int *)(Globals::layout + 0x2c)))
              - *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0x24),
             (iVar5 - iVar14) - iVar15,'!','\x04');
  *(TouchButton **)(this + 0x18) = pTVar12;
  this[0x15] = (WantedWindow)0x0;
  *(undefined4 *)this = 1;
  return;
}

// ===== WantedWindow::~WantedWindow  @0x000f4f90  (190 bytes)
/* WantedWindow::~WantedWindow() */

WantedWindow * __thiscall WantedWindow::~WantedWindow(WantedWindow *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 8) != (Array *)0x0) {
    ArrayReleaseClasses<ImagePart*>(*(Array **)(this + 8));
    pvVar1 = *(void **)(this + 8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(Array **)(this + 0xc) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0xc));
    pvVar1 = *(void **)(this + 0xc);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  if (*(TouchButton **)(this + 0x18) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x18));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  pvVar1 = *(void **)(this + 0x38);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x38) = 0;
  if (*(Mission **)(this + 0x98) != (Mission *)0x0) {
    pvVar1 = (void *)Mission::~Mission(*(Mission **)(this + 0x98));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x98) = 0;
  if (*(ScrollTouchWindow **)(this + 0x2c) != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0x2c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  AbyssEngine::String::~String((String *)(this + 100));
  AbyssEngine::String::~String((String *)(this + 0x5c));
  AbyssEngine::String::~String((String *)(this + 0x54));
  AbyssEngine::String::~String((String *)(this + 0x4c));
  AbyssEngine::String::~String((String *)(this + 0x44));
  AbyssEngine::String::~String((String *)(this + 0x3c));
  return this;
}

// ===== WantedWindow::selectWanted  @0x000f5090  (1678 bytes)
/* WantedWindow::selectWanted(int) */

void __thiscall WantedWindow::selectWanted(WantedWindow *this,int param_1)

{
  Galaxy *pGVar1;
  GameText *this_00;
  ImageFactory *this_01;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  Station *this_02;
  Station *this_03;
  Station *this_04;
  String *pSVar5;
  int iVar6;
  ScrollTouchWindow *pSVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  void *pvVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  String aSStack_70 [8];
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  AbyssEngine aAStack_40 [8];
  undefined4 local_38 [2];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pvVar12 = *(void **)(this + 8);
  if (pvVar12 != (void *)0x0) {
    if (*(void **)((int)pvVar12 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar12 + 4));
    }
    operator_delete(pvVar12);
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(ScrollTouchWindow **)(this + 0x2c) != (ScrollTouchWindow *)0x0) {
    pvVar12 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0x2c));
    operator_delete(pvVar12);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  this_01 = Globals::imageFactory;
  piVar2 = (int *)Wanted::getImageParts
                            (*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
  uVar3 = ImageFactory::loadChar(this_01,piVar2);
  *(undefined4 *)(this + 8) = uVar3;
  Wanted::getName();
  AbyssEngine::String::operator=((String *)(this + 0x4c),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  iVar4 = Wanted::isActive(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
  pGVar1 = Globals::galaxy;
  if (iVar4 == 1) {
    iVar4 = Wanted::getLastSeen(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
    this_02 = (Station *)Galaxy::getStation(pGVar1,iVar4);
    pGVar1 = Globals::galaxy;
    iVar4 = Wanted::getTravelsTo(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
    this_03 = (Station *)Galaxy::getStation(pGVar1,iVar4);
    pGVar1 = Globals::galaxy;
    iVar4 = Wanted::getCurrentLocation
                      (*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
    this_04 = (Station *)Galaxy::getStation(pGVar1,iVar4);
    pGVar1 = Globals::galaxy;
    iVar4 = Station::getSystem(this_02);
    Galaxy::getSystem(pGVar1,iVar4);
    pGVar1 = Globals::galaxy;
    iVar4 = Station::getSystem(this_03);
    Galaxy::getSystem(pGVar1,iVar4);
    pGVar1 = Globals::galaxy;
    iVar4 = Station::getSystem(this_04);
    Galaxy::getSystem(pGVar1,iVar4);
    Station::getName();
    AbyssEngine::String::String(aSStack_50," (",false);
    AbyssEngine::operator+(aAStack_40,aSStack_48,aSStack_50);
    SolarSystem::getName();
    AbyssEngine::operator+((AbyssEngine *)local_38,aAStack_40,aSStack_58);
    AbyssEngine::String::String(aSStack_60,")",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_30,(String *)local_38,aSStack_60);
    AbyssEngine::String::operator=((String *)(this + 0x3c),aSStack_30);
    AbyssEngine::String::~String(aSStack_30);
    AbyssEngine::String::~String(aSStack_60);
    AbyssEngine::String::~String((String *)local_38);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String((String *)aAStack_40);
    AbyssEngine::String::~String(aSStack_50);
    AbyssEngine::String::~String(aSStack_48);
    Station::getName();
    AbyssEngine::String::String(aSStack_50," (",false);
    AbyssEngine::operator+(aAStack_40,aSStack_48,aSStack_50);
    SolarSystem::getName();
    AbyssEngine::operator+((AbyssEngine *)local_38,aAStack_40,aSStack_58);
    AbyssEngine::String::String(aSStack_60,")",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_30,(String *)local_38,aSStack_60);
    AbyssEngine::String::operator=((String *)(this + 0x44),aSStack_30);
    AbyssEngine::String::~String(aSStack_30);
    AbyssEngine::String::~String(aSStack_60);
    AbyssEngine::String::~String((String *)local_38);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String((String *)aAStack_40);
    AbyssEngine::String::~String(aSStack_50);
    AbyssEngine::String::~String(aSStack_48);
    Station::getName();
    AbyssEngine::String::String(aSStack_50," (",false);
    AbyssEngine::operator+(aAStack_40,aSStack_48,aSStack_50);
    SolarSystem::getName();
    AbyssEngine::operator+((AbyssEngine *)local_38,aAStack_40,aSStack_58);
    AbyssEngine::String::String(aSStack_60,")",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_30,(String *)local_38,aSStack_60);
    AbyssEngine::String::operator=((String *)(this + 0x5c),aSStack_30);
    AbyssEngine::String::~String(aSStack_30);
    AbyssEngine::String::~String(aSStack_60);
    AbyssEngine::String::~String((String *)local_38);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String((String *)aAStack_40);
    AbyssEngine::String::~String(aSStack_50);
    AbyssEngine::String::~String(aSStack_48);
    uVar3 = Wanted::getReward(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
    local_38[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar3,local_38));
    AbyssEngine::String::String((String *)aAStack_40,"$",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_30,(String *)local_38,aAStack_40);
    AbyssEngine::String::operator=((String *)(this + 100),aSStack_30);
    AbyssEngine::String::~String(aSStack_30);
    AbyssEngine::String::~String((String *)aAStack_40);
    AbyssEngine::String::~String((String *)local_38);
    if (this_02 != (Station *)0x0) {
      pvVar12 = (void *)Station::~Station(this_02);
      operator_delete(pvVar12);
    }
    if (this_03 != (Station *)0x0) {
      pvVar12 = (void *)Station::~Station(this_03);
      operator_delete(pvVar12);
    }
    if (this_04 != (Station *)0x0) {
      pvVar12 = (void *)Station::~Station(this_04);
      operator_delete(pvVar12);
    }
  }
  else {
    iVar4 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
    if (iVar4 == 1) {
      AbyssEngine::String::String(aSStack_30," -- ",false);
      AbyssEngine::String::operator=((String *)(this + 0x3c),aSStack_30);
      AbyssEngine::String::~String(aSStack_30);
      AbyssEngine::String::String(aSStack_30," --",false);
      AbyssEngine::String::operator=((String *)(this + 0x44),aSStack_30);
      AbyssEngine::String::~String(aSStack_30);
      AbyssEngine::String::String(aSStack_30," --",false);
      AbyssEngine::String::operator=((String *)(this + 0x5c),aSStack_30);
      AbyssEngine::String::~String(aSStack_30);
      AbyssEngine::String::String(aSStack_30," --",false);
      AbyssEngine::String::operator=((String *)(this + 100),aSStack_30);
      AbyssEngine::String::~String(aSStack_30);
    }
    else {
      pSVar5 = (String *)GameText::getText(Globals::gameText,0xc9d);
      AbyssEngine::String::operator=((String *)(this + 0x3c),pSVar5);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0xc9d);
      AbyssEngine::String::operator=((String *)(this + 0x44),pSVar5);
      uVar3 = Wanted::getReward(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
      local_38[0] = 0;
      AbyssEngine::String::Set(CONCAT44(uVar3,local_38));
      AbyssEngine::String::String((String *)aAStack_40,"$",false);
      AbyssEngine::operator+((AbyssEngine *)aSStack_30,(String *)local_38,aAStack_40);
      AbyssEngine::String::operator=((String *)(this + 100),aSStack_30);
      AbyssEngine::String::~String(aSStack_30);
      AbyssEngine::String::~String((String *)aAStack_40);
      AbyssEngine::String::~String((String *)local_38);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0xc9d);
      AbyssEngine::String::operator=((String *)(this + 0x5c),pSVar5);
    }
  }
  iVar4 = Wanted::isTerminated(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
  if (iVar4 == 1) {
    iVar4 = 0xc9b;
  }
  else {
    iVar4 = 0xc9c;
  }
  pSVar5 = (String *)GameText::getText(Globals::gameText,iVar4);
  AbyssEngine::String::operator=((String *)(this + 0x54),pSVar5);
  iVar8 = *(int *)(this + 0x20);
  iVar17 = *(int *)(this + 0x28);
  iVar13 = *(int *)(Globals::layout + 0x20);
  iVar9 = *(int *)(Globals::layout + 0x24);
  iVar11 = *(int *)(Globals::layout + 0x2c);
  iVar10 = *(int *)(Globals::layout + 0xc);
  iVar16 = *(int *)(Globals::layout + 0x10);
  iVar15 = *(int *)(Globals::layout + 0x2d8);
  iVar14 = *(int *)(Globals::layout + 0x5c);
  iVar6 = Wanted::isActive(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
  iVar4 = Globals::layout;
  iVar10 = iVar8 + iVar10 + iVar13 + iVar14 + iVar11;
  iVar9 = (((((iVar8 - iVar11) + iVar17) - iVar10) - iVar16) - iVar15) - iVar9;
  if (iVar6 == 1) {
    iVar9 = (iVar9 - *(int *)(Globals::layout + 0x4c)) - *(int *)(Globals::layout + 0x30);
  }
  pSVar7 = operator_new(0x20);
  iVar6 = *(int *)(iVar4 + 0x2c);
  ScrollTouchWindow::ScrollTouchWindow
            (pSVar7,*(int *)(this + 0x1c) + (*(int *)(this + 0x24) >> 1) + iVar6,
             *(int *)(iVar4 + 0x2d8) + iVar6 + iVar10,
             ((*(int *)(this + 0x24) >> 1) - iVar6) - *(int *)(iVar4 + 0x28),iVar9,false);
  *(ScrollTouchWindow **)(this + 0x2c) = pSVar7;
  AbyssEngine::String::String(aSStack_30,"",false);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0xc97);
  AbyssEngine::String::operator=(aSStack_30,pSVar5);
  AbyssEngine::String::String((String *)aAStack_40,"\n",false);
  AbyssEngine::operator+((AbyssEngine *)local_38,aAStack_40,this + 0x3c);
  AbyssEngine::String::operator+=(aSStack_30,(String *)local_38);
  AbyssEngine::String::~String((String *)local_38);
  AbyssEngine::String::~String((String *)aAStack_40);
  AbyssEngine::String::String((String *)aAStack_40,"\n\n",false);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0xc98);
  AbyssEngine::operator+((AbyssEngine *)local_38,aAStack_40,pSVar5);
  AbyssEngine::String::operator+=(aSStack_30,(String *)local_38);
  AbyssEngine::String::~String((String *)local_38);
  AbyssEngine::String::~String((String *)aAStack_40);
  AbyssEngine::String::String((String *)aAStack_40,"\n",false);
  AbyssEngine::operator+((AbyssEngine *)local_38,aAStack_40,this + 0x44);
  AbyssEngine::String::operator+=(aSStack_30,(String *)local_38);
  AbyssEngine::String::~String((String *)local_38);
  AbyssEngine::String::~String((String *)aAStack_40);
  AbyssEngine::String::String((String *)aAStack_40,"\n\n",false);
  this_00 = Globals::gameText;
  iVar4 = Wanted::getIndex(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + param_1 * 4));
  pSVar5 = (String *)GameText::getText(this_00,iVar4 + 0xc66);
  AbyssEngine::operator+((AbyssEngine *)local_38,aAStack_40,pSVar5);
  AbyssEngine::String::operator+=(aSStack_30,(String *)local_38);
  AbyssEngine::String::~String((String *)local_38);
  AbyssEngine::String::~String((String *)aAStack_40);
  pSVar7 = *(ScrollTouchWindow **)(this + 0x2c);
  AbyssEngine::String::String(aSStack_68,"",false);
  AbyssEngine::String::String(aSStack_70,aSStack_30,false);
  ScrollTouchWindow::setText(pSVar7,aSStack_68,aSStack_70);
  AbyssEngine::String::~String(aSStack_70);
  AbyssEngine::String::~String(aSStack_68);
  AbyssEngine::String::~String(aSStack_30);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== WantedWindow::setHangarUpdate  @0x000f5880  (4 bytes)
/* WantedWindow::setHangarUpdate(bool) */

void __thiscall WantedWindow::setHangarUpdate(WantedWindow *this,bool param_1)

{
  this[0x15] = (WantedWindow)param_1;
  return;
}

// ===== WantedWindow::getRelativeScrollStartPos  @0x000f5884  (42 bytes)
/* WantedWindow::getRelativeScrollStartPos() */

float __thiscall WantedWindow::getRelativeScrollStartPos(WantedWindow *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (*(int *)(this + 0x6c) < 1) {
    fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0x6c),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x8c),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = -fVar2 / fVar1;
  }
  else {
    fVar1 = 0.0;
  }
  return fVar1;
}

// ===== WantedWindow::getRelativeScrollHeight  @0x000f58b4  (76 bytes)
/* WantedWindow::getRelativeScrollHeight() */

float __thiscall WantedWindow::getRelativeScrollHeight(WantedWindow *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  iVar2 = *(int *)(this + 0x8c);
  iVar3 = *(int *)(this + 0x90);
  if (iVar2 < iVar3) {
    return 0.0;
  }
  iVar1 = *(int *)(this + 0x6c);
  if (iVar1 < 1) {
    if (iVar3 - iVar2 <= iVar1) {
      fVar4 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
      goto LAB_000f58f2;
    }
    iVar3 = iVar1 + iVar2;
  }
  else {
    iVar3 = iVar3 - iVar1;
  }
  fVar4 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
LAB_000f58f2:
  fVar5 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
  return fVar5 / fVar4;
}

// ===== WantedWindow::render3D  @0x000f5904  (12 bytes)
/* WantedWindow::render3D() */

void __thiscall WantedWindow::render3D(WantedWindow *this)

{
  if (this[0x14] == (WantedWindow)0x0) {
    return;
  }
  StarMap::render(*(StarMap **)(this + 4));
  return;
}

// ===== WantedWindow::draw  @0x000f5910  (2040 bytes)
/* WARNING: Removing unreachable block (ram,0x000f5958) */
/* WantedWindow::draw() */

void __thiscall WantedWindow::draw(WantedWindow *this)

{
  PaintCanvas *pPVar1;
  Layout *pLVar2;
  float fVar3;
  uint uVar4;
  undefined4 uVar5;
  String *pSVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  uint in_fpscr;
  float fVar18;
  float fVar19;
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
  
  local_3c = __stack_chk_guard;
  if (this[0x14] != (WantedWindow)0x0) {
    StarMap::draw(*(StarMap **)(this + 4));
    return;
  }
  AbyssEngine::PaintCanvas::EnableClip
            (Globals::Canvas,*(int *)(this + 0x1c),
             *(int *)(Globals::layout + 0x5c) +
             *(int *)(Globals::layout + 0xc) + *(int *)(this + 0x20) +
             *(int *)(Globals::layout + 0x20),*(int *)(this + 0x24),
             *(int *)(Globals::layout + 0x2c) + *(int *)(this + 0x90));
  iVar11 = *(int *)(this + 0x6c);
  if (iVar11 < 1) {
    fVar3 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
    fVar18 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x8c),(byte)(in_fpscr >> 0x16) & 3);
    fVar18 = -fVar3 / fVar18;
  }
  else {
    fVar18 = 0.0;
  }
  iVar9 = *(int *)(this + 0x90);
  fVar19 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)getRelativeScrollHeight(this);
  if ((0 < (int)(fVar3 * fVar19)) || (0 < (int)(fVar18 * fVar19))) {
    Layout::drawScrollBar
              (Globals::layout,
               ((*(int *)(this + 0x1c) + (*(int *)(this + 0x24) >> 1)) -
               *(int *)(Globals::layout + 0x2c)) - *(int *)(Globals::layout + 0x48),
               *(int *)(this + 0x20) + *(int *)(Globals::layout + 0x2c) +
               *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
               *(int *)(Globals::layout + 0x5c),iVar9,(int)(fVar18 * fVar19),(int)(fVar3 * fVar19));
    iVar11 = *(int *)(this + 0x6c);
  }
  if (**(int **)(this + 0x38) != 0) {
    iVar11 = *(int *)(Globals::layout + 0x2c) +
             *(int *)(this + 0x20) + *(int *)(Globals::layout + 0xc) +
             *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0x5c) + iVar11;
    uVar10 = 0;
    do {
      pLVar2 = Globals::layout;
      uVar4 = *(uint *)(this + 0x30);
      bVar17 = uVar10 != uVar4;
      if (bVar17) {
        uVar4 = *(uint *)(this + 0x34);
      }
      if (bVar17 && uVar10 != uVar4) {
        uVar5 = 3;
      }
      else {
        uVar5 = 4;
      }
      iVar13 = *(int *)(Globals::layout + 0x28);
      iVar9 = *(int *)(this + 0x1c);
      AbyssEngine::String::String(aSStack_44,"",false);
      Layout::drawBox(pLVar2,uVar5,iVar13 + iVar9,iVar11);
      AbyssEngine::String::~String(aSStack_44);
      pPVar1 = Globals::Canvas;
      Wanted::isActive(*(Wanted **)(*(int *)(*(int *)(this + 0x38) + 4) + uVar10 * 4));
      AbyssEngine::PaintCanvas::SetColor((uint)pPVar1);
      uVar4 = Globals::font;
      pPVar1 = Globals::Canvas;
      Wanted::getName();
      iVar15 = *(int *)(this + 0x1c);
      iVar13 = *(int *)(Globals::layout + 0x28);
      iVar14 = *(int *)(Globals::layout + 0x44);
      iVar12 = *(int *)(Globals::layout + 0x70);
      iVar9 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar4,aSStack_4c,iVar13 + iVar15 + iVar14,(iVar11 + iVar12 / 2) - iVar9 / 2,
                 false);
      AbyssEngine::String::~String(aSStack_4c);
      iVar9 = Status::getCurrentCampaignMission(Globals::status);
      if ((uVar10 == 0 && iVar9 == 0x80) ||
         (iVar9 = Status::getCurrentCampaignMission(Globals::status), uVar10 == 1 && iVar9 == 0x82))
      {
        uVar4 = Globals::font;
        pPVar1 = Globals::Canvas;
        iVar12 = *(int *)(this + 0x1c);
        uVar8 = *(uint *)(this + 0x94);
        iVar16 = *(int *)(Globals::layout + 0x28);
        iVar15 = *(int *)(Globals::layout + 0x44);
        Wanted::getName();
        AbyssEngine::String::String(aSStack_5c," ",false);
        AbyssEngine::operator+((AbyssEngine *)aSStack_4c,aSStack_54,aSStack_5c);
        iVar9 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar1,uVar4,(AbyssEngine *)aSStack_4c);
        iVar14 = *(int *)(Globals::layout + 0x70);
        iVar13 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
        AbyssEngine::PaintCanvas::DrawImage2D
                  (pPVar1,uVar8,iVar12 + iVar16 + iVar15 + iVar9,(iVar11 + iVar14 / 2) - iVar13 / 2)
        ;
        AbyssEngine::String::~String(aSStack_4c);
        AbyssEngine::String::~String(aSStack_5c);
        AbyssEngine::String::~String(aSStack_54);
      }
      uVar10 = uVar10 + 1;
      iVar11 = *(int *)(Globals::layout + 0x70) + iVar11 + *(int *)(Globals::layout + 0x34);
    } while (uVar10 < **(uint **)(this + 0x38));
  }
  AbyssEngine::PaintCanvas::DisableClip();
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  pLVar2 = Globals::layout;
  pSVar6 = (String *)GameText::getText(Globals::gameText,0xc93);
  AbyssEngine::String::String(aSStack_64,pSVar6,false);
  Layout::drawHeader(pLVar2,aSStack_64);
  AbyssEngine::String::~String(aSStack_64);
  puVar7 = *(uint **)(this + 0xc);
  if (*puVar7 != 0) {
    uVar10 = 0;
    do {
      TouchButton::draw(*(TouchButton **)(puVar7[1] + uVar10 * 4));
      puVar7 = *(uint **)(this + 0xc);
      uVar10 = uVar10 + 1;
    } while (uVar10 < *puVar7);
  }
  pLVar2 = Globals::layout;
  iVar11 = *(int *)(this + 0x1c);
  iVar9 = *(int *)(this + 0x20);
  iVar13 = *(int *)(Globals::layout + 0x20);
  iVar14 = *(int *)(Globals::layout + 0xc);
  iVar12 = *(int *)(Globals::layout + 0x28);
  pSVar6 = (String *)GameText::getText(Globals::gameText,0xc95);
  AbyssEngine::String::String(aSStack_6c,pSVar6,false);
  Layout::drawBox(pLVar2,1,iVar12 + iVar11,iVar9 + iVar14 + iVar13);
  AbyssEngine::String::~String(aSStack_6c);
  pLVar2 = Globals::layout;
  iVar11 = *(int *)(this + 0x1c);
  iVar9 = *(int *)(this + 0x20);
  iVar13 = *(int *)(Globals::layout + 0xc);
  iVar14 = *(int *)(Globals::layout + 0x28);
  iVar12 = *(int *)(Globals::layout + 0x2c);
  iVar16 = *(int *)(Globals::layout + 0x20);
  iVar15 = *(int *)(Globals::layout + 0x5c);
  AbyssEngine::String::String(aSStack_74,"",false);
  Layout::drawBox(pLVar2,5,iVar14 + iVar11,iVar9 + iVar13 + iVar16 + iVar15 + iVar12);
  AbyssEngine::String::~String(aSStack_74);
  pLVar2 = Globals::layout;
  iVar11 = *(int *)(this + 0x1c);
  iVar9 = *(int *)(this + 0x20);
  iVar13 = *(int *)(Globals::layout + 0x20);
  iVar12 = *(int *)(this + 0x24);
  iVar15 = *(int *)(Globals::layout + 0xc);
  iVar14 = *(int *)(Globals::layout + 0x2c);
  pSVar6 = (String *)GameText::getText(Globals::gameText,0xc96);
  AbyssEngine::String::String(aSStack_7c,pSVar6,false);
  Layout::drawBox(pLVar2,1,iVar11 + (iVar12 >> 1) + iVar14,iVar9 + iVar15 + iVar13);
  AbyssEngine::String::~String(aSStack_7c);
  pLVar2 = Globals::layout;
  iVar11 = *(int *)(this + 0x1c);
  iVar9 = *(int *)(this + 0x20);
  iVar16 = *(int *)(this + 0x24);
  iVar15 = *(int *)(Globals::layout + 0xc);
  iVar14 = *(int *)(Globals::layout + 0x2c);
  iVar13 = *(int *)(Globals::layout + 0x20);
  iVar12 = *(int *)(Globals::layout + 0x5c);
  AbyssEngine::String::String(aSStack_84,"",false);
  Layout::drawBox(pLVar2,5,iVar11 + (iVar16 >> 1) + iVar14,iVar9 + iVar14 + iVar15 + iVar13 + iVar12
                 );
  AbyssEngine::String::~String(aSStack_84);
  if (*(Array **)(this + 8) != (Array *)0x0) {
    iVar11 = *(int *)(this + 0x1c) + (*(int *)(this + 0x24) >> 1) + *(int *)(Globals::layout + 0x2c)
    ;
    iVar13 = *(int *)(this + 0x20) + *(int *)(Globals::layout + 0x2c) +
             *(int *)(Globals::layout + 0xc) + *(int *)(Globals::layout + 0x20) +
             *(int *)(Globals::layout + 0x5c);
    ImageFactory::drawChar(Globals::imageFactory,*(Array **)(this + 8),iVar11,iVar13,false);
    iVar11 = *(int *)(Globals::layout + 0x2d4) + iVar11 + *(int *)(Globals::layout + 0x2c);
    AbyssEngine::PaintCanvas::DrawString
              (Globals::Canvas,Globals::font,this + 0x4c,iVar11,iVar13,false);
    uVar10 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar9 = *(int *)(Globals::layout + 4);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0xc9a);
    AbyssEngine::String::String(aSStack_5c," ",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_54,pSVar6,aSStack_5c);
    AbyssEngine::operator+((AbyssEngine *)aSStack_4c,aSStack_54,this + 0x54);
    iVar13 = iVar13 + iVar9 * 2;
    AbyssEngine::PaintCanvas::DrawString(pPVar1,uVar10,aSStack_4c,iVar11,iVar13,false);
    AbyssEngine::String::~String(aSStack_4c);
    AbyssEngine::String::~String(aSStack_54);
    AbyssEngine::String::~String(aSStack_5c);
    uVar10 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar9 = *(int *)(Globals::layout + 4);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0xc99);
    AbyssEngine::String::String(aSStack_5c," ",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_54,pSVar6,aSStack_5c);
    AbyssEngine::operator+((AbyssEngine *)aSStack_4c,aSStack_54,this + 100);
    AbyssEngine::PaintCanvas::DrawString(pPVar1,uVar10,aSStack_4c,iVar11,iVar9 + iVar13,false);
    AbyssEngine::String::~String(aSStack_4c);
    AbyssEngine::String::~String(aSStack_54);
    AbyssEngine::String::~String(aSStack_5c);
    ScrollTouchWindow::draw(*(ScrollTouchWindow **)(this + 0x2c));
  }
  if ((*(int *)(this + 0x18) != 0) &&
     (iVar11 = Wanted::isActive(*(Wanted **)
                                 (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4)),
     iVar11 == 1)) {
    TouchButton::draw(*(TouchButton **)(this + 0x18));
  }
  Layout::drawFooter(Globals::layout);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== WantedWindow::getWantedAtPosition  @0x000f6228  (90 bytes)
/* WantedWindow::getWantedAtPosition(int, int) */

uint __thiscall WantedWindow::getWantedAtPosition(WantedWindow *this,int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  
  if (param_1 < *(int *)(this + 0x1c) + (*(int *)(this + 0x24) >> 1)) {
    piVar2 = *(int **)(this + 0x38);
    uVar1 = __aeabi_idiv(((((param_2 - *(int *)(this + 0x20)) - *(int *)(Globals::layout + 0xc)) -
                          *(int *)(Globals::layout + 0x20)) - *(int *)(Globals::layout + 0x5c)) -
                         *(int *)(this + 0x6c),
                         *(int *)(Globals::layout + 0x70) + *(int *)(Globals::layout + 0x34));
    if (*piVar2 - 1U < uVar1) {
      uVar1 = 0xffffffff;
    }
    return uVar1;
  }
  return 0xffffffff;
}

// ===== WantedWindow::hangarNeedsUpdate  @0x000f6288  (4 bytes)
/* WantedWindow::hangarNeedsUpdate() */

WantedWindow __thiscall WantedWindow::hangarNeedsUpdate(WantedWindow *this)

{
  return this[0x15];
}

// ===== WantedWindow::update  @0x000f628c  (210 bytes)
/* WantedWindow::update(int) */

void WantedWindow::update(int param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  
  if (*(char *)(param_1 + 0x14) != '\0') {
    StarMap::update(*(int *)(param_1 + 4));
    return;
  }
  TouchButton::setAlwaysPressed(*(TouchButton **)(*(int *)(*(int *)(param_1 + 0xc) + 4) + 4),true);
  ScrollTouchWindow::update(*(int *)(param_1 + 0x2c));
  if (*(char *)(param_1 + 0x88) == '\0') {
    fVar5 = *(float *)(param_1 + 0x7c) * *(float *)(param_1 + 0x80);
    fVar6 = -(*(float *)(param_1 + 0x7c) * *(float *)(param_1 + 0x80));
    if (0.0 < fVar5) {
      fVar6 = fVar5;
    }
    *(float *)(param_1 + 0x80) = fVar5;
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar6 < 1.0) << 0x1f | (uint)(fVar6 == 1.0) << 0x1e;
    in_fpscr = uVar1 | (uint)NAN(fVar6) << 0x1c;
    bVar2 = (byte)(uVar1 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x6c),
                                         (byte)(in_fpscr >> 0x16) & 3);
      *(int *)(param_1 + 0x6c) = (int)(fVar5 + fVar6);
    }
  }
  iVar3 = *(int *)(param_1 + 0x6c);
  if (0 < iVar3) {
    fVar6 = (float)VectorSignedToFloat(-iVar3,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(param_1 + 0x80) = fVar6 * 0.5;
    *(undefined4 *)(param_1 + 0x7c) = 0x3f800000;
  }
  iVar4 = *(int *)(param_1 + 0x90) - *(int *)(param_1 + 0x8c);
  if (iVar4 < 0) {
    if (iVar3 < iVar4) {
      fVar6 = (float)VectorSignedToFloat(iVar4 - iVar3,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x80) = fVar6 * 0.5;
      *(undefined4 *)(param_1 + 0x7c) = 0x3f800000;
      return;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  return;
}

// ===== WantedWindow::OnTouchBegin  @0x000f6360  (152 bytes)
/* WantedWindow::OnTouchBegin(int, int) */

undefined4 __thiscall WantedWindow::OnTouchBegin(WantedWindow *this,int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (this[0x14] == (WantedWindow)0x0) {
    *(int *)(this + 0x70) = param_2;
    *(int *)(this + 0x84) = param_2;
    *(undefined4 *)(this + 0x78) = 0;
    this[0x88] = (WantedWindow)0x1;
    ScrollTouchWindow::OnTouchBegin(*(int *)(this + 0x2c),param_1);
    puVar1 = *(uint **)(this + 0xc);
    if (*puVar1 != 0) {
      uVar4 = 0;
      do {
        TouchButton::OnTouchBegin(*(TouchButton **)(puVar1[1] + uVar4 * 4),param_1,param_2);
        puVar1 = *(uint **)(this + 0xc);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *puVar1);
    }
    Layout::OnTouchBegin(Globals::layout,param_1,param_2);
    if ((*(int *)(this + 0x18) != 0) &&
       (iVar2 = Wanted::isActive(*(Wanted **)
                                  (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4))
       , iVar2 == 1)) {
      TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x18),param_1,param_2);
    }
    uVar3 = getWantedAtPosition(this,param_1,param_2);
    *(undefined4 *)(this + 0x34) = uVar3;
  }
  else {
    StarMap::OnTouchBegin(*(StarMap **)(this + 4),param_1,param_2);
  }
  return 0;
}

// ===== WantedWindow::OnTouchMove  @0x000f63fc  (256 bytes)
/* WantedWindow::OnTouchMove(int, int) */

undefined4 __thiscall WantedWindow::OnTouchMove(WantedWindow *this,int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (this[0x14] == (WantedWindow)0x0) {
    if ((((*(int *)(Globals::layout + 0xc) < param_2) &&
         (param_2 < Globals::h - *(int *)(Globals::layout + 0x10))) && (param_1 < Globals::w / 2))
       || (Globals::mouse_wheel != 0)) {
      iVar1 = *(int *)(this + 0x70);
      *(int *)(this + 0x78) = param_2 - iVar1;
      *(int *)(this + 0x70) = param_2;
      *(undefined4 *)(this + 0x7c) = 0x3f800000;
      *(int *)(this + 0x6c) = (param_2 - iVar1) + *(int *)(this + 0x6c);
    }
    if (Globals::w / 2 < param_1) {
      ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 0x2c),param_1,param_2);
    }
    puVar2 = *(uint **)(this + 0xc);
    if (*puVar2 != 0) {
      uVar4 = 0;
      do {
        TouchButton::OnTouchMove(*(TouchButton **)(puVar2[1] + uVar4 * 4),param_1,param_2);
        puVar2 = *(uint **)(this + 0xc);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *puVar2);
    }
    Layout::OnTouchMove(Globals::layout,param_1,param_2);
    if ((*(int *)(this + 0x18) != 0) &&
       (iVar1 = Wanted::isActive(*(Wanted **)
                                  (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4))
       , iVar1 == 1)) {
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0x18),param_1,param_2);
    }
    uVar3 = getWantedAtPosition(this,param_1,param_2);
    iVar1 = param_2 - *(int *)(this + 0x84);
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (5 < iVar1) {
      uVar3 = 0xffffffff;
    }
    *(undefined4 *)(this + 0x34) = uVar3;
  }
  else {
    StarMap::OnTouchMove(*(StarMap **)(this + 4),param_1,param_2);
  }
  return 0;
}

// ===== WantedWindow::OnTouchEnd  @0x000f6518  (870 bytes)
/* WantedWindow::OnTouchEnd(int, int) */

void __thiscall WantedWindow::OnTouchEnd(WantedWindow *this,int param_1,int param_2)

{
  Galaxy *this_00;
  Layout *pLVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  Station *this_01;
  Mission *pMVar6;
  void *pvVar7;
  String *pSVar8;
  undefined4 uVar9;
  uint uVar10;
  StarMap *pSVar11;
  bool bVar12;
  uint in_fpscr;
  undefined4 uVar13;
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (this[0x14] == (WantedWindow)0x0) {
    iVar4 = *(int *)(this + 0x78);
    uVar9 = VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
    iVar2 = iVar4;
    if (iVar4 < 0) {
      iVar2 = -iVar4;
    }
    uVar13 = 0;
    if (3 < iVar2) {
      uVar13 = uVar9;
    }
    *(undefined4 *)(this + 0x80) = uVar13;
    *(undefined4 *)(this + 0x7c) = 0x3f666666;
    this[0x88] = (WantedWindow)0x0;
    iVar2 = *(int *)(this + 0x6c);
    *(int *)(this + 0x6c) = iVar4 + iVar2;
    *(int *)(this + 0x74) = iVar4 + iVar2;
    ScrollTouchWindow::OnTouchEnd(*(int *)(this + 0x2c),param_1);
    puVar5 = *(uint **)(this + 0xc);
    if (*puVar5 != 0) {
      uVar10 = 0;
      do {
        iVar2 = TouchButton::OnTouchEnd(*(TouchButton **)(puVar5[1] + uVar10 * 4),param_1,param_2);
        if (iVar2 == 1) {
          *(uint *)this = uVar10;
        }
        puVar5 = *(uint **)(this + 0xc);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar5);
    }
    if (-1 < *(int *)(this + 0x34)) {
      iVar2 = getWantedAtPosition(this,param_1,param_2);
      *(int *)(this + 0x30) = iVar2;
      *(int *)(this + 0x34) = iVar2;
      selectWanted(this,iVar2);
    }
    if (((*(int *)(this + 0x18) == 0) ||
        (iVar2 = Wanted::isActive(*(Wanted **)
                                   (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4)
                                 ), iVar2 != 1)) ||
       (iVar2 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x18),param_1,param_2), iVar2 != 1)
       ) {
      iVar2 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
      if (iVar2 == 1) {
        Layout::resetWindowDimensions(Globals::layout);
        uVar9 = 1;
        goto LAB_000f6866;
      }
      iVar2 = Layout::helpPressed(Globals::layout);
      pLVar1 = Globals::layout;
      if (iVar2 == 1) {
        pSVar8 = (String *)GameText::getText(Globals::gameText,0x27b);
        AbyssEngine::String::String(aSStack_28,pSVar8,false);
        Layout::initHelpWindow(pLVar1,aSStack_28);
        AbyssEngine::String::~String(aSStack_28);
      }
    }
    else {
      iVar2 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
      *(undefined4 *)(this + 4) = *(undefined4 *)(iVar2 + 0x10);
      this_00 = Globals::galaxy;
      iVar2 = Wanted::getLastSeen(*(Wanted **)
                                   (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4)
                                 );
      this_01 = (Station *)Galaxy::getStation(this_00,iVar2);
      pMVar6 = *(Mission **)(this + 0x98);
      if (*(int *)(this + 4) == 0) {
        if (pMVar6 != (Mission *)0x0) {
          pvVar7 = (void *)Mission::~Mission(pMVar6);
          operator_delete(pvVar7);
        }
        *(undefined4 *)(this + 0x98) = 0;
        pMVar6 = operator_new(100);
        iVar2 = Wanted::getTravelsTo
                          (*(Wanted **)
                            (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4));
        Mission::Mission(pMVar6,0,0,iVar2);
        *(Mission **)(this + 0x98) = pMVar6;
        pSVar11 = operator_new(0x1e8);
        StarMap::StarMap(pSVar11,true,pMVar6,false,-1);
        iVar2 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
        *(StarMap **)(iVar2 + 0x10) = pSVar11;
        iVar2 = AbyssEngine::ApplicationManager::GetApplicationModule(Globals::appManager,5);
        pSVar11 = *(StarMap **)(iVar2 + 0x10);
        *(StarMap **)(this + 4) = pSVar11;
      }
      else {
        if (pMVar6 != (Mission *)0x0) {
          pvVar7 = (void *)Mission::~Mission(pMVar6);
          operator_delete(pvVar7);
        }
        *(undefined4 *)(this + 0x98) = 0;
        pMVar6 = operator_new(100);
        iVar2 = Wanted::getTravelsTo
                          (*(Wanted **)
                            (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4));
        Mission::Mission(pMVar6,0,0,iVar2);
        *(Mission **)(this + 0x98) = pMVar6;
        StarMap::init(*(StarMap **)(this + 4),true,pMVar6,false,-1);
        pSVar11 = *(StarMap **)(this + 4);
      }
      iVar2 = Station::getSystem(this_01);
      iVar4 = Wanted::getLastSeen(*(Wanted **)
                                   (*(int *)(*(int *)(this + 0x38) + 4) + *(int *)(this + 0x30) * 4)
                                 );
      StarMap::setStart(pSVar11,iVar2,iVar4);
      if (this_01 != (Station *)0x0) {
        pvVar7 = (void *)Station::~Station(this_01);
        operator_delete(pvVar7);
      }
      this[0x14] = (WantedWindow)0x1;
      Layout::resetWindowDimensions(Globals::layout);
    }
  }
  else {
    iVar2 = StarMap::OnTouchEnd(*(StarMap **)(this + 4),param_1,param_2);
    if (iVar2 == 1) {
      if (Globals::iPad == '\0') {
        *(undefined4 *)(this + 0x1c) = 0;
        *(undefined4 *)(this + 0x20) = 0;
        *(int *)(this + 0x24) = Globals::w;
        *(int *)(this + 0x28) = Globals::h;
      }
      else {
        if (Globals::iPadHD == '\0') {
          uVar10 = 0x28a;
          bVar12 = Globals::iPadLarge != '\0';
          if (bVar12) {
            uVar10 = 0x514;
          }
          uVar3 = 500;
          *(uint *)(this + 0x24) = uVar10;
          if (bVar12) {
            uVar3 = 1000;
          }
          uVar10 = uVar10 >> 1;
        }
        else {
          uVar10 = 0x1c9;
          *(undefined4 *)(this + 0x24) = 0x392;
          uVar3 = 0x2bf;
        }
        *(uint *)(this + 0x28) = uVar3;
        *(uint *)(this + 0x1c) = (Globals::w >> 1) - uVar10;
        *(uint *)(this + 0x20) = (Globals::h >> 1) - (uVar3 >> 1);
      }
      uVar9 = 0;
      this[0x14] = (WantedWindow)0x0;
      goto LAB_000f6866;
    }
  }
  uVar9 = 0;
LAB_000f6866:
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}

