// Class: MTitle
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MTitle::MTitle  @0x000a3378  (16 bytes)
/* MTitle::MTitle() */

void __thiscall MTitle::MTitle(MTitle *this)

{
  *(undefined ***)this = &PTR__MTitle_00263d8c;
  *(undefined4 *)(this + 0xc) = 100;
  return;
}

// ===== MTitle::~MTitle  @0x000a338c  (26 bytes)
/* MTitle::~MTitle() */

MTitle * __thiscall MTitle::~MTitle(MTitle *this)

{
  *(undefined ***)this = &PTR__MTitle_00263d8c;
  OnRelease();
  return this;
}

// ===== MTitle::~MTitle  @0x000a33b0  (16 bytes)
/* MTitle::~MTitle() */

void __thiscall MTitle::~MTitle(MTitle *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~MTitle(this);
  operator_delete(pvVar1);
  return;
}

// ===== MTitle::OnInitialize  @0x000a33c0  (78 bytes)
/* MTitle::OnInitialize() */

undefined4 __thiscall MTitle::OnInitialize(MTitle *this)

{
  float fVar1;
  
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,7000,(uint *)(this + 0x10));
  fVar1 = (float)AbyssEngine::PaintCanvas::Image2DCreate
                           (Globals::Canvas,0x1b59,(uint *)(this + 0x14));
  FModSound::play(Globals::sound,0x91,(Vector *)0x0,(Vector *)0x0,fVar1);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0xc) = 100;
  return 0;
}

// ===== MTitle::OnTouchBegin  @0x000a3418  (2 bytes)
/* MTitle::OnTouchBegin(int, int) */

int MTitle::OnTouchBegin(int param_1,int param_2)

{
  return param_1;
}

// ===== MTitle::OnTouchMove  @0x000a341a  (2 bytes)
/* MTitle::OnTouchMove(int, int) */

int MTitle::OnTouchMove(int param_1,int param_2)

{
  return param_1;
}

// ===== MTitle::OnTouchEnd  @0x000a341c  (8 bytes)
/* MTitle::OnTouchEnd(int, int) */

void MTitle::OnTouchEnd(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = 5000;
  return;
}

// ===== MTitle::OnRelease  @0x000a3424  (82 bytes)
/* MTitle::OnRelease() */

void MTitle::OnRelease(void)

{
  Globals *this;
  int iVar1;
  
  AbyssEngine::PaintCanvas::ReleaseAllResources(Globals::Canvas);
  this = Globals::globals;
  iVar1 = GameText::getLanguage();
  Globals::loadFont(this,iVar1);
  if (Globals::layout == (Layout *)0x0) {
    return;
  }
  Layout::reload(Globals::layout);
  ImageFactory::reload(Globals::imageFactory);
  Layout::initTip(Globals::layout);
  return;
}

// ===== MTitle::OnKeyPress  @0x000a3488  (2 bytes)
/* MTitle::OnKeyPress(long long, long long) */

longlong MTitle::OnKeyPress(longlong param_1,longlong param_2)

{
  return param_1;
}

// ===== MTitle::OnUpdate  @0x000a348a  (2 bytes)
/* MTitle::OnUpdate() */

void MTitle::OnUpdate(void)

{
  return;
}

// ===== MTitle::OnRender2D  @0x000a348c  (290 bytes)
/* MTitle::OnRender2D() */

void __thiscall MTitle::OnRender2D(MTitle *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint in_fpscr;
  
  AbyssEngine::PaintCanvas::Begin2d(*(PaintCanvas **)(this + 4));
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  Layout::drawBG(Globals::layout);
  Layout::drawHeader(Globals::layout);
  Layout::drawEmptyFooter(Globals::layout,false);
  iVar2 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis(*(ApplicationManager **)(this + 8));
  if (iVar2 < 0x33) {
    iVar2 = AbyssEngine::ApplicationManager::GetElapsedTimeMillis
                      (*(ApplicationManager **)(this + 8));
  }
  else {
    iVar2 = 0x32;
  }
  iVar2 = iVar2 + *(int *)(this + 0x1c);
  *(int *)(this + 0x1c) = iVar2;
  if (iVar2 < 0xfa1) {
    iVar1 = 0x10;
    if (*(int *)(this + 0x18) == 0) {
      iVar1 = 0x14;
    }
    uVar3 = *(uint *)(this + iVar1);
    if (999 < iVar2) {
      if (3000 < iVar2) {
        VectorSignedToFloat(iVar2 + -3000,(byte)(in_fpscr >> 0x16) & 3);
      }
      goto LAB_000a3568;
    }
  }
  else {
    *(undefined4 *)(this + 0x1c) = 0;
    iVar2 = *(int *)(this + 0x18) + 1;
    *(int *)(this + 0x18) = iVar2;
    if (iVar2 == 2) {
      AbyssEngine::ApplicationManager::SetCurrentApplicationModule(Globals::appManager,1);
      return;
    }
    iVar1 = 0x10;
    if (iVar2 == 0) {
      iVar1 = 0x14;
    }
    iVar2 = 0;
    uVar3 = *(uint *)(this + iVar1);
  }
  VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
LAB_000a3568:
  AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar3,0,0,'D','D');
  AbyssEngine::PaintCanvas::End2d(*(PaintCanvas **)(this + 4));
  AbyssEngine::PaintCanvas::SwapBuffer();
  return;
}

// ===== MTitle::OnRender3D  @0x000a35c8  (36 bytes)
/* MTitle::OnRender3D() */

void __thiscall MTitle::OnRender3D(MTitle *this)

{
  AbyssEngine::PaintCanvas::ClearBuffer(Globals::Canvas);
  AbyssEngine::PaintCanvas::Begin3d(*(PaintCanvas **)(this + 4));
  AbyssEngine::PaintCanvas::End3d(*(PaintCanvas **)(this + 4));
  return;
}

// ===== MTitle::OnKeyRelease  @0x000a35f0  (2 bytes)
/* MTitle::OnKeyRelease(long long, long long) */

longlong MTitle::OnKeyRelease(longlong param_1,longlong param_2)

{
  return param_1;
}

// ===== MTitle::ShowLoadingScreen  @0x000a35fc  (4 bytes)
/* MTitle::ShowLoadingScreen() */

undefined4 MTitle::ShowLoadingScreen(void)

{
  return 0;
}

