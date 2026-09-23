// Class: ModMainMenu
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ModMainMenu::ModMainMenu  @0x001a462c  (30 bytes)
/* ModMainMenu::ModMainMenu() */

void __thiscall ModMainMenu::ModMainMenu(ModMainMenu *this)

{
  *(undefined ***)this = &PTR__ModMainMenu_00264934;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  this[0x10] = (ModMainMenu)0x0;
  this[0x29] = (ModMainMenu)0x0;
  *(undefined4 *)(this + 0xc) = 100;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}

// ===== ModMainMenu::~ModMainMenu  @0x001a4650  (26 bytes)
/* ModMainMenu::~ModMainMenu() */

ModMainMenu * __thiscall ModMainMenu::~ModMainMenu(ModMainMenu *this)

{
  *(undefined ***)this = &PTR__ModMainMenu_00264934;
  OnRelease(this);
  return this;
}

// ===== ModMainMenu::~ModMainMenu  @0x001a4674  (16 bytes)
/* ModMainMenu::~ModMainMenu() */

void __thiscall ModMainMenu::~ModMainMenu(ModMainMenu *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~ModMainMenu(this);
  operator_delete(pvVar1);
  return;
}

// ===== ModMainMenu::OnResume  @0x001a4684  (50 bytes)
/* ModMainMenu::OnResume() */

void ModMainMenu::OnResume(void)

{
  int iVar1;
  float extraout_s0;
  
  if ((Globals::sound != 0) && (iVar1 = FModSound::tryToStopMusicForBGMusic(), iVar1 == 0)) {
    FModSound::setVolume((FModSound *)Globals::sound,1,extraout_s0);
    return;
  }
  return;
}

// ===== ModMainMenu::OnSuspend  @0x001a46c4  (20 bytes)
/* ModMainMenu::OnSuspend() */

void ModMainMenu::OnSuspend(void)

{
  if (Globals::recordHandler == 0) {
    return;
  }
  RecordHandler::saveOptions((RecordHandler *)Globals::recordHandler);
  return;
}

// ===== ModMainMenu::OnInitialize  @0x001a46dc  (524 bytes)
/* ModMainMenu::OnInitialize() */

void ModMainMenu::OnInitialize(void)

{
  Galaxy *this;
  Status *this_00;
  short sVar1;
  int in_r0;
  int iVar2;
  undefined4 uVar3;
  Station *pSVar4;
  CutScene *this_01;
  GameRecord *this_02;
  void *pvVar5;
  MenuTouchWindow *this_03;
  SolarSystem *this_04;
  ushort uVar6;
  undefined4 in_r1;
  undefined4 extraout_r1;
  PaintCanvas *this_05;
  uint local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (*(int *)(in_r0 + 0x1c) == 0) {
    Globals::startNewSoundResourceList(Globals::globals);
    Globals::addSoundResourceToList(Globals::globals,0x7e);
    Globals::addSoundResourceToList(Globals::globals,0x15);
    Globals::addSoundResourceToList(Globals::globals,0x12);
    Globals::addSoundResourceToList(Globals::globals,0x13);
    Globals::addSoundResourceToList(Globals::globals,0x14);
    Status::resetGame(Globals::status);
    AbyssEngine::AERandom::reset(Globals::rnd);
    this_00 = Globals::status;
    this = Globals::galaxy;
    iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,100);
    pSVar4 = (Station *)Galaxy::getStation(this,iVar2);
    Status::setStation(this_00,pSVar4);
    this_01 = operator_new(0xa0);
    CutScene::CutScene(this_01,2);
    *(CutScene **)(in_r0 + 0x1c) = this_01;
    CutScene::initialize(this_01);
    iVar2 = Status::inAlienOrbit(Globals::status);
    this_05 = *(PaintCanvas **)(in_r0 + 4);
    if (iVar2 == 1) {
      uVar6 = 0x2f08;
    }
    else {
      this_04 = (SolarSystem *)Status::getSystem(Globals::status);
      sVar1 = SolarSystem::getTextureIndex(this_04);
      uVar6 = sVar1 + 0x2efe;
    }
    AbyssEngine::PaintCanvas::TextureCreate(this_05,uVar6,&local_20,false);
    AbyssEngine::PaintCanvas::ChangeCubeTexture(*(PaintCanvas **)(in_r0 + 4),local_20);
    uVar3 = 100;
    goto LAB_001a48d0;
  }
  iVar2 = *(int *)(in_r0 + 0xc);
  if (iVar2 < 0x50) {
    if (iVar2 == 0x1e) {
      *(undefined4 *)(in_r0 + 0xc) = 1;
    }
    else if (iVar2 == 0x3c) {
      uVar3 = 0x1e;
      goto LAB_001a48cc;
    }
LAB_001a486c:
    if (Globals::switch_to_target_setting != -1) {
      Globals::playMusicAndFadeOutCurrent(Globals::globals,Globals::switch_to_target_setting);
    }
    Globals::switch_to_target_setting = -1;
    *(undefined4 *)(in_r0 + 0xc) = 100;
    *(undefined1 *)(in_r0 + 0x10) = 1;
    uVar3 = 0;
  }
  else {
    if (iVar2 == 0x50) {
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1b5a,(uint *)(in_r0 + 0x20));
      *(undefined4 *)(in_r0 + 0x24) = 0;
      *(undefined1 *)(in_r0 + 0x28) = 1;
      Globals::logoIsShown = 1;
      uVar3 = 0x3c;
    }
    else {
      if (iVar2 != 100) goto LAB_001a486c;
      if (Globals::options[0x48] == '\0') {
        this_02 = (GameRecord *)RecordHandler::recordStoreReadPreview(Globals::recordHandler,0);
        if (this_02 != (GameRecord *)0x0) {
          *(undefined1 *)(in_r0 + 0x29) = 1;
          pvVar5 = (void *)GameRecord::~GameRecord(this_02);
          operator_delete(pvVar5);
        }
        Globals::options[0x48] = '\x01';
        RecordHandler::saveOptions(Globals::recordHandler);
        in_r1 = extraout_r1;
      }
      Status::setPlayingTime(CONCAT44(in_r1,Globals::status));
      this_03 = operator_new(0x240);
      MenuTouchWindow::MenuTouchWindow(this_03,0);
      *(MenuTouchWindow **)(in_r0 + 0x18) = this_03;
      if (*(char *)(in_r0 + 0x29) != '\0') {
        MenuTouchWindow::showSupernovaMessage(this_03);
        *(undefined1 *)(in_r0 + 0x29) = 0;
      }
      uVar3 = 0x50;
    }
LAB_001a48cc:
    *(undefined4 *)(in_r0 + 0xc) = uVar3;
  }
LAB_001a48d0:
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

// ===== ModMainMenu::OnTouchBegin  @0x001a4940  (20 bytes)
/* ModMainMenu::OnTouchBegin(int, int, void*) */

void ModMainMenu::OnTouchBegin(int param_1,int param_2,void *param_3)

{
  if (*(char *)(param_1 + 0x28) == '\0') {
    MenuTouchWindow::OnTouchBegin(*(int *)(param_1 + 0x18),param_2,param_3);
    return;
  }
  return;
}

// ===== ModMainMenu::OnTouchMove  @0x001a4952  (18 bytes)
/* ModMainMenu::OnTouchMove(int, int, void*) */

void ModMainMenu::OnTouchMove(int param_1,int param_2,void *param_3)

{
  void *in_r3;
  
  if (*(char *)(param_1 + 0x28) == '\0') {
    MenuTouchWindow::OnTouchMove(*(MenuTouchWindow **)(param_1 + 0x18),param_2,(int)param_3,in_r3);
    return;
  }
  return;
}

// ===== ModMainMenu::OnTouchEnd  @0x001a4964  (50 bytes)
/* ModMainMenu::OnTouchEnd(int, int, void*) */

void __thiscall ModMainMenu::OnTouchEnd(ModMainMenu *this,int param_1,int param_2,void *param_3)

{
  StarSystem *this_00;
  
  if (this[0x28] == (ModMainMenu)0x0) {
    MenuTouchWindow::OnTouchEnd(*(MenuTouchWindow **)(this + 0x18),param_1,param_2,param_3);
    this_00 = (StarSystem *)Level::getStarSystem((Level *)**(undefined4 **)(this + 0x1c));
    StarSystem::initLight(this_00);
    return;
  }
  this[0x28] = (ModMainMenu)0x0;
  Globals::logoIsShown = 0;
  return;
}

// ===== ModMainMenu::OnRelease  @0x001a499c  (126 bytes)
/* ModMainMenu::OnRelease() */

void __thiscall ModMainMenu::OnRelease(ModMainMenu *this)

{
  Globals *this_00;
  void *pvVar1;
  int iVar2;
  
  if (*(CutScene **)(this + 0x1c) != (CutScene *)0x0) {
    pvVar1 = (void *)CutScene::~CutScene(*(CutScene **)(this + 0x1c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  if (*(MenuTouchWindow **)(this + 0x18) != (MenuTouchWindow *)0x0) {
    pvVar1 = (void *)MenuTouchWindow::~MenuTouchWindow(*(MenuTouchWindow **)(this + 0x18));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  AbyssEngine::PaintCanvas::ReleaseAllResources(Globals::Canvas);
  this_00 = Globals::globals;
  iVar2 = GameText::getLanguage();
  Globals::loadFont(this_00,iVar2);
  if (Globals::layout != (Layout *)0x0) {
    Layout::reload(Globals::layout);
    ImageFactory::reload(Globals::imageFactory);
    Layout::initTip(Globals::layout);
  }
  if (Globals::sound == 0) {
    return;
  }
  FModSound::freeAllEvents((FModSound *)Globals::sound);
  return;
}

// ===== ModMainMenu::OnUpdate  @0x001a4a34  (138 bytes)
/* ModMainMenu::OnUpdate() */

void __thiscall ModMainMenu::OnUpdate(ModMainMenu *this)

{
  int iVar1;
  
  iVar1 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis(*(ApplicationManager **)(this + 8));
  if ((iVar1 < 0x97) &&
     (iVar1 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                        (*(ApplicationManager **)(this + 8)), iVar1 < 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                      (*(ApplicationManager **)(this + 8));
    if (iVar1 < 0x97) {
      iVar1 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                        (*(ApplicationManager **)(this + 8));
    }
    else {
      iVar1 = 0x96;
    }
  }
  *(int *)(this + 0x14) = iVar1;
  Layout::update(Globals::layout,iVar1);
  CutScene::update(*(int *)(this + 0x1c));
  if (this[0x28] == (ModMainMenu)0x0) {
    MenuTouchWindow::update(*(int *)(this + 0x18));
  }
  Layout::update(Globals::layout,*(int *)(this + 0x14));
  *(int *)(this + 0x24) = *(int *)(this + 0x14) + *(int *)(this + 0x24);
  FModSound::updateAll(Globals::sound,(Vector *)0x0,(Vector *)0x0,(Vector *)0x0,(Vector *)0x0);
  return;
}

// ===== ModMainMenu::OnRender2D  @0x001a4acc  (420 bytes)
/* ModMainMenu::OnRender2D() */

void __thiscall ModMainMenu::OnRender2D(ModMainMenu *this)

{
  PaintCanvas *pPVar1;
  PaintCanvas *this_00;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  String *pSVar7;
  String *pSVar8;
  int iVar9;
  int iVar10;
  uint in_fpscr;
  
  AbyssEngine::PaintCanvas::Begin2d(*(PaintCanvas **)(this + 4));
  AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
  CutScene::render2D();
  if (this[0x28] == (ModMainMenu)0x0) {
    MenuTouchWindow::draw(*(MenuTouchWindow **)(this + 0x18));
  }
  else {
    if (*(int *)(this + 0x24) < 0xf3c) {
      VectorSignedToFloat(*(int *)(this + 0x24),(byte)(in_fpscr >> 0x16) & 3);
    }
    AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x20),0,0,'D','D');
    pPVar1 = Globals::Canvas;
    if (0xf3b < *(int *)(this + 0x24)) {
      AbyssEngine::ApplicationManager::GetSystemTimeMillis(Globals::appManager);
      fVar6 = (float)__aeabi_l2f();
      AbyssEngine::AEMath::Sinf(fVar6 * 0.003);
      AbyssEngine::ApplicationManager::GetSystemTimeMillis(Globals::appManager);
      fVar6 = (float)__aeabi_l2f();
      AbyssEngine::AEMath::Sinf(fVar6 * 0.003);
      AbyssEngine::PaintCanvas::SetColor((uchar)pPVar1,0xff,0xff,0xff);
      uVar2 = Globals::font;
      pPVar1 = Globals::Canvas;
      pSVar7 = (String *)GameText::getText(Globals::gameText,199);
      iVar5 = Globals::w;
      uVar3 = Globals::font;
      this_00 = Globals::Canvas;
      pSVar8 = (String *)GameText::getText(Globals::gameText,199);
      iVar9 = AbyssEngine::PaintCanvas::GetTextWidth(this_00,uVar3,pSVar8);
      iVar4 = Globals::h;
      iVar10 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x20));
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar2,pSVar7,(iVar5 >> 1) - (iVar9 >> 1),(iVar4 >> 1) + (iVar10 >> 1) + 10,
                 false);
    }
  }
  AbyssEngine::PaintCanvas::End2d(*(PaintCanvas **)(this + 4));
  return;
}

// ===== ModMainMenu::OnRender3D  @0x001a4c98  (48 bytes)
/* ModMainMenu::OnRender3D() */

void __thiscall ModMainMenu::OnRender3D(ModMainMenu *this)

{
  AbyssEngine::PaintCanvas::ClearBuffer((uint)Globals::Canvas);
  CutScene::renderBG(*(CutScene **)(this + 0x1c));
  AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
  CutScene::render3D(*(CutScene **)(this + 0x1c));
  AbyssEngine::PaintCanvas::End3d(Globals::Canvas);
  return;
}

// ===== ModMainMenu::OnKeyPress  @0x001a4ccc  (2 bytes)
/* ModMainMenu::OnKeyPress(long long, long long) */

longlong ModMainMenu::OnKeyPress(longlong param_1,longlong param_2)

{
  return param_1;
}

// ===== ModMainMenu::OnKeyRelease  @0x001a4cce  (2 bytes)
/* ModMainMenu::OnKeyRelease(long long, long long) */

longlong ModMainMenu::OnKeyRelease(longlong param_1,longlong param_2)

{
  return param_1;
}

// ===== ModMainMenu::OnTouchBegin  @0x001a4cd0  (2 bytes)
/* ModMainMenu::OnTouchBegin(int, int) */

int ModMainMenu::OnTouchBegin(int param_1,int param_2)

{
  return param_1;
}

// ===== ModMainMenu::OnTouchMove  @0x001a4cd2  (2 bytes)
/* ModMainMenu::OnTouchMove(int, int) */

int ModMainMenu::OnTouchMove(int param_1,int param_2)

{
  return param_1;
}

// ===== ModMainMenu::OnTouchEnd  @0x001a4cd4  (2 bytes)
/* ModMainMenu::OnTouchEnd(int, int) */

int ModMainMenu::OnTouchEnd(int param_1,int param_2)

{
  return param_1;
}

// ===== ModMainMenu::ShowLoadingScreen  @0x001a4cd6  (4 bytes)
/* ModMainMenu::ShowLoadingScreen() */

undefined4 ModMainMenu::ShowLoadingScreen(void)

{
  return 1;
}

