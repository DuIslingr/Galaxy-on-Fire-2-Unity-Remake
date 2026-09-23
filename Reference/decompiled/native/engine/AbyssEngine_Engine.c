// Class: AbyssEngine::Engine
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::Engine::SetScreenOrientation  @0x00076752  (2 bytes)
/* AbyssEngine::Engine::SetScreenOrientation(AbyssEngine::LandscapeMode) */

void AbyssEngine::Engine::SetScreenOrientation(void)

{
  return;
}

// ===== AbyssEngine::Engine::initFileInterface  @0x00076754  (32 bytes)
/* AbyssEngine::Engine::initFileInterface() */

void __thiscall AbyssEngine::Engine::initFileInterface(Engine *this)

{
  FileInterfaceAndroid *this_00;
  
  this_00 = operator_new(0x38);
  FileInterfaceAndroid::FileInterfaceAndroid(this_00);
  *(FileInterfaceAndroid **)(this + 0x1c) = this_00;
  AEFile::SetInterface((FileInterface *)this_00);
  return;
}

// ===== AbyssEngine::Engine::InitGL  @0x00076780  (358 bytes)
/* AbyssEngine::Engine::InitGL(bool, int, int) */

void __thiscall AbyssEngine::Engine::InitGL(Engine *this,bool param_1,int param_2,int param_3)

{
  FileInterfaceAndroid *this_00;
  FBOContainer *pFVar1;
  String aSStack_30 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  *(undefined4 *)(this + 0x408) = 0;
  *(int *)(this + 0x360) = param_2;
  *(int *)(this + 0x364) = param_3;
  *(int *)(this + 0x358) = param_2;
  *(int *)(this + 0x35c) = param_3;
  this_00 = operator_new(0x38);
  FileInterfaceAndroid::FileInterfaceAndroid(this_00);
  *(FileInterfaceAndroid **)(this + 0x1c) = this_00;
  AEFile::SetInterface((FileInterface *)this_00);
  this[0x470] = (Engine)0x0;
  this[0x24] = (Engine)0x0;
  *(undefined4 *)(this + 0xc) = 0;
  enableShader = param_1;
  *(undefined4 *)(this + 0x3fc) = 0;
  ResetLightParam(this);
  glViewport(0,0,*(undefined4 *)(this + 0x364),*(undefined4 *)(this + 0x360));
  if (enableShader == '\0') {
    glEnable(0x803a);
    glDisable(0xb50);
    glLineWidth(0x3f800000);
  }
  else {
    ShaderInit(this);
  }
  local_28 = 0;
  local_24 = 0x3f800000;
  local_20 = 0;
  AEMath::Vector::operator=((Vector *)(this + 0x458),(Vector *)&local_28);
  *(undefined4 *)(this + 0x368) = 0;
  local_28 = 0;
  local_24 = 0x3f800000;
  local_20 = 0;
  AEMath::Vector::operator=((Vector *)(this + 0x464),(Vector *)&local_28);
  *(undefined4 *)(this + 0x36c) = 0;
  glEnable(0xb71);
  GlEnable(this,0xde1,true);
  glDisable(0xbe2);
  glCullFace(0x405);
  glEnable(0xb44);
  AfterGLInit(this);
  PaintCanvas::Initialize((PaintCanvas *)**(undefined4 **)(this + 0x28),false);
  *(undefined4 *)(this + 8) = 0;
  glGetIntegerv(0xd33,this + 8);
  if ((enableShader != '\0') && (EnablePostEffect != '\0')) {
    pFVar1 = operator_new(0x34);
    String::String(aSStack_30,"refractFBO",false);
    FBOContainer::FBOContainer(pFVar1,this,aSStack_30);
    *(FBOContainer **)(this + 0x408) = pFVar1;
    String::~String(aSStack_30);
    FBOContainer::Create
              (*(int *)(this + 0x408),*(int *)(this + 0x358),SUB41(*(undefined4 *)(this + 0x35c),0),
               true);
  }
  if (__stack_chk_guard - local_1c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_1c);
  }
  return;
}

// ===== AbyssEngine::Engine::SetFrameBufferScaleFactor  @0x0007691c  (2 bytes)
/* AbyssEngine::Engine::SetFrameBufferScaleFactor(float, int) */

int AbyssEngine::Engine::SetFrameBufferScaleFactor(float param_1,int param_2)

{
  return param_2;
}

// ===== AbyssEngine::Engine::ReleaseGL  @0x0007691e  (2 bytes)
/* AbyssEngine::Engine::ReleaseGL() */

void AbyssEngine::Engine::ReleaseGL(void)

{
  return;
}

// ===== AbyssEngine::Engine::PreUpdate  @0x00076920  (2 bytes)
/* AbyssEngine::Engine::PreUpdate() */

void AbyssEngine::Engine::PreUpdate(void)

{
  return;
}

// ===== AbyssEngine::Engine::ActivateTextureFBO  @0x00076922  (14 bytes)
/* AbyssEngine::Engine::ActivateTextureFBO() */

void __thiscall AbyssEngine::Engine::ActivateTextureFBO(Engine *this)

{
  if (*(FBOContainer **)(this + 0x404) == (FBOContainer *)0x0) {
    return;
  }
  FBOContainer::Activate(*(FBOContainer **)(this + 0x404));
  return;
}

// ===== AbyssEngine::Engine::ActivateRender2TextureFBO  @0x00076930  (14 bytes)
/* AbyssEngine::Engine::ActivateRender2TextureFBO() */

void __thiscall AbyssEngine::Engine::ActivateRender2TextureFBO(Engine *this)

{
  if (*(FBOContainer **)(this + 0x404) == (FBOContainer *)0x0) {
    return;
  }
  FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x404));
  return;
}

// ===== AbyssEngine::Engine::DeactivateRender2TextureFBO  @0x0007693e  (14 bytes)
/* AbyssEngine::Engine::DeactivateRender2TextureFBO() */

void __thiscall AbyssEngine::Engine::DeactivateRender2TextureFBO(Engine *this)

{
  if (*(FBOContainer **)(this + 0x404) == (FBOContainer *)0x0) {
    return;
  }
  FBOContainer::EndCapture(*(FBOContainer **)(this + 0x404));
  return;
}

// ===== AbyssEngine::Engine::ActivateRefractFBO  @0x0007694c  (16 bytes)
/* AbyssEngine::Engine::ActivateRefractFBO() */

void __thiscall AbyssEngine::Engine::ActivateRefractFBO(Engine *this)

{
  if (*(FBOContainer **)(this + 0x408) == (FBOContainer *)0x0) {
    return;
  }
  FBOContainer::Activate(*(FBOContainer **)(this + 0x408));
  return;
}

// ===== AbyssEngine::Engine::ActivateRender2FracFBO  @0x0007695a  (16 bytes)
/* AbyssEngine::Engine::ActivateRender2FracFBO() */

void __thiscall AbyssEngine::Engine::ActivateRender2FracFBO(Engine *this)

{
  if (*(FBOContainer **)(this + 0x408) == (FBOContainer *)0x0) {
    return;
  }
  FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x408));
  return;
}

// ===== AbyssEngine::Engine::DeactivateRender2FracFBO  @0x00076968  (16 bytes)
/* AbyssEngine::Engine::DeactivateRender2FracFBO() */

void __thiscall AbyssEngine::Engine::DeactivateRender2FracFBO(Engine *this)

{
  if (*(FBOContainer **)(this + 0x408) == (FBOContainer *)0x0) {
    return;
  }
  FBOContainer::EndCapture(*(FBOContainer **)(this + 0x408));
  return;
}

// ===== AbyssEngine::Engine::ActivateFrameBuffer  @0x00076976  (2 bytes)
/* AbyssEngine::Engine::ActivateFrameBuffer(int) */

int AbyssEngine::Engine::ActivateFrameBuffer(int param_1)

{
  return param_1;
}

// ===== AbyssEngine::Engine::ActivateViewBuffer  @0x00076978  (34 bytes)
/* AbyssEngine::Engine::ActivateViewBuffer() */

void __thiscall AbyssEngine::Engine::ActivateViewBuffer(Engine *this)

{
  glBindFramebuffer(0x8d40,*(undefined4 *)(this + 0x3fc));
  glViewport(0,0,*(undefined4 *)(this + 0x360),*(undefined4 *)(this + 0x364));
  return;
}

// ===== AbyssEngine::Engine::CopyFBO  @0x0007699c  (158 bytes)
/* AbyssEngine::Engine::CopyFBO() */

void __thiscall AbyssEngine::Engine::CopyFBO(Engine *this)

{
  int iVar1;
  
  if (enableShader == '\0') {
    return;
  }
  iVar1 = IsPostEffectActivated(this);
  if (iVar1 == 1) {
    if (*(FBOContainer **)(this + 0x404) != (FBOContainer *)0x0) {
      FBOContainer::EndCapture(*(FBOContainer **)(this + 0x404));
    }
    DrawCloakFBO((FBOContainer *)this);
    if (*(FBOContainer **)(this + 0x404) != (FBOContainer *)0x0) {
      FBOContainer::BeginCapture(*(FBOContainer **)(this + 0x404));
    }
  }
  else {
    if (*(FBOContainer **)(this + 0x408) != (FBOContainer *)0x0) {
      FBOContainer::EndCapture(*(FBOContainer **)(this + 0x408));
    }
    DrawCloakFBO((FBOContainer *)this);
    glBindFramebuffer(0x8d40,*(undefined4 *)(this + 0x3fc));
    glViewport(0,0,*(undefined4 *)(this + 0x360),*(undefined4 *)(this + 0x364));
  }
  glEnable(0xb71);
  glDepthMask(1);
  glDisable(0xbe2);
  glClearColor(0,0,0,0);
  glClear(0x100);
  return;
}

// ===== AbyssEngine::Engine::SwapBuffer  @0x00076a40  (32 bytes)
/* AbyssEngine::Engine::SwapBuffer() */

void __thiscall AbyssEngine::Engine::SwapBuffer(Engine *this)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(this + 0x3c8) != 0) {
    iVar1 = *(int *)(this + 0x3cc);
    uVar2 = 0;
    do {
      *(undefined4 *)(iVar1 + uVar2 * 4) = 0;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(this + 0x3c8));
  }
  return;
}

// ===== AbyssEngine::Engine::GrabFrameBuffer  @0x00076a60  (2 bytes)
/* AbyssEngine::Engine::GrabFrameBuffer() */

void AbyssEngine::Engine::GrabFrameBuffer(void)

{
  return;
}

// ===== AbyssEngine::Engine::SaveImageToPhotosAlbum  @0x00076a62  (2 bytes)
/* AbyssEngine::Engine::SaveImageToPhotosAlbum() */

void AbyssEngine::Engine::SaveImageToPhotosAlbum(void)

{
  return;
}

// ===== AbyssEngine::Engine::GetJPEGImageData  @0x00076a64  (4 bytes)
/* AbyssEngine::Engine::GetJPEGImageData(float) */

undefined4 AbyssEngine::Engine::GetJPEGImageData(float param_1)

{
  return 0;
}

// ===== AbyssEngine::Engine::Engine  @0x0008eb58  (496 bytes)
/* AbyssEngine::Engine::Engine() */

void __thiscall AbyssEngine::Engine::Engine(Engine *this)

{
  undefined1 auVar1 [16];
  undefined4 *puVar2;
  ApplicationManager *this_00;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  String::String((String *)this);
  String::String((String *)(this + 0x10));
  String::String((String *)(this + 0x34));
  String::String((String *)(this + 0x40));
  uVar3 = 0;
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x330) = 0;
  *(undefined4 *)(this + 0x334) = 0;
  *(undefined4 *)(this + 800) = 0;
  *(undefined4 *)(this + 0x324) = uVar4;
  *(undefined4 *)(this + 0x328) = uVar5;
  *(undefined4 *)(this + 0x32c) = uVar6;
  *(undefined4 *)(this + 0x33c) = 0;
  *(undefined4 *)(this + 0x340) = 0;
  *(undefined4 *)(this + 0x344) = 0;
  *(undefined4 *)(this + 0x3bc) = 0;
  *(undefined4 *)(this + 0x3c0) = 0;
  *(undefined4 *)(this + 0x3c4) = 0;
  puVar2 = operator_new__(4);
  *(undefined4 **)(this + 0x3cc) = puVar2;
  *(undefined4 *)(this + 0x3d0) = 1;
  *puVar2 = 0;
  *(undefined4 *)(this + 0x3c8) = 0;
  *(undefined4 *)(this + 0x458) = uVar3;
  *(undefined4 *)(this + 0x45c) = uVar4;
  *(undefined4 *)(this + 0x460) = uVar5;
  *(undefined4 *)(this + 0x464) = uVar6;
  *(undefined4 *)(this + 0x468) = 0;
  *(undefined4 *)(this + 0x46c) = 0;
  *(undefined4 *)(this + 0x3e0) = uVar3;
  *(undefined4 *)(this + 0x3e4) = uVar4;
  *(undefined4 *)(this + 1000) = uVar5;
  *(undefined4 *)(this + 0x3ec) = uVar6;
  *(undefined4 *)(this + 0x3f0) = 0;
  *(undefined4 *)(this + 0x3f4) = 0;
  puVar2 = operator_new__(4);
  *(undefined4 **)(this + 0x504) = puVar2;
  *(undefined4 *)(this + 0x508) = 1;
  *puVar2 = 0;
  *(undefined4 *)(this + 0x500) = 0;
  *(undefined4 *)(this + 0x370) = 0;
  *(undefined4 *)(this + 0x3fc) = 0;
  *(undefined4 *)(this + 0x400) = 0;
  this[0x3b4] = (Engine)0x0;
  *(undefined4 *)(this + 0x3b8) = 0;
  local_48 = 0x3f000000;
  local_44 = 0x3e99999a;
  local_40 = 0;
  AEMath::Vector::operator=((Vector *)(this + 0x3bc),(Vector *)&local_48);
  *(undefined4 *)(this + 0x348) = 0;
  *(undefined4 *)(this + 0x404) = 0;
  *(undefined4 *)(this + 0x408) = 0;
  this[0x40c] = (Engine)0x0;
  *(undefined4 *)(this + 0x350) = 0;
  *(undefined4 *)(this + 0x498) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined4 *)(this + 0x3d4) = 0xffffffff;
  __aeabi_memset4(this + 0x6c,0x50,0xff);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x480) = 0xffffffff;
  *(undefined4 *)(this + 0x47c) = 0xffffffff;
  this[0xef] = (Engine)0x0;
  *(undefined4 *)(this + 0x494) = 0;
  this[0xed] = (Engine)0x0;
  this[0xee] = (Engine)0x1;
  *(undefined4 *)(this + 0x68) = 0xffffffff;
  this[100] = (Engine)0x0;
  *(undefined4 *)(this + 0x410) = 0;
  this[0x414] = (Engine)0x0;
  this[0x3c] = (Engine)0x0;
  *(undefined4 *)(this + 0x474) = 0;
  *(undefined4 *)(this + 0x310) = 0;
  *(undefined4 *)(this + 0x314) = 0;
  *(undefined4 *)(this + 0x318) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  this[0x30] = (Engine)0x0;
  *(undefined4 *)(this + 0x358) = 0;
  *(undefined4 *)(this + 0x35c) = uVar3;
  *(undefined4 *)(this + 0x360) = uVar4;
  *(undefined4 *)(this + 0x364) = uVar5;
  *(undefined4 *)(this + 0x4a0) = 0;
  *(undefined4 *)(this + 0x4a4) = uVar3;
  *(undefined4 *)(this + 0x4a8) = uVar4;
  *(undefined4 *)(this + 0x4ac) = uVar5;
  *(undefined4 *)(this + 0x4b4) = 0;
  *(undefined4 *)(this + 0x4b0) = 0;
  *(undefined4 *)(this + 0x4d0) = 0;
  *(undefined4 *)(this + 0x4d4) = uVar3;
  *(undefined4 *)(this + 0x4d8) = uVar4;
  *(undefined4 *)(this + 0x4dc) = uVar5;
  *(undefined4 *)(this + 0x4e0) = 0;
  *(undefined4 *)(this + 0x4e4) = 0;
  *(undefined4 *)(this + 0x20) = 0x14;
  this[0x18] = (Engine)0x1;
  *(undefined4 *)(this + 0xbc) = 0x3f333333;
  this_00 = operator_new(0xc0);
  ApplicationManager::ApplicationManager(this_00,this);
  auVar1._8_8_ = SUB128(SUB1612((undefined1  [16])0x0,4),4);
  auVar1._0_8_ = 0xbf800000bf800000;
  auVar1 = auVar1 << 0x40 | auVar1;
  *(ApplicationManager **)(this + 0x28) = this_00;
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)auVar1;
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(auVar1 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(auVar1 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(auVar1 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x3d8) = 0;
  *(undefined4 *)(this + 0x3dc) = 0x47435000;
  local_48 = 0x3f800000;
  local_44 = 0;
  local_40 = 0;
  AEMath::Vector::operator=((Vector *)(this + 0x3e0),(Vector *)&local_48);
  initFileInterface(this);
  if (__stack_chk_guard - local_3c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_3c);
  }
  return;
}

// ===== AbyssEngine::Engine::~Engine  @0x0008edca  (174 bytes)
/* AbyssEngine::Engine::~Engine() */

void __thiscall AbyssEngine::Engine::~Engine(Engine *this)

{
  void *pvVar1;
  
  if (*(code **)(this + 0x474) != (code *)0x0) {
    (**(code **)(this + 0x474))(this);
  }
  if (*(ApplicationManager **)(this + 0x28) != (ApplicationManager *)0x0) {
    pvVar1 = (void *)ApplicationManager::~ApplicationManager(*(ApplicationManager **)(this + 0x28));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(int **)(this + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x1c) + 4))();
  }
  *(undefined4 *)(this + 0x1c) = 0;
  AEFile::Release();
  ArrayReleaseClasses<AbyssEngine::ShaderBaseStruct*>((Array *)(this + 0x500));
  if (*(FBOContainer **)(this + 0x404) != (FBOContainer *)0x0) {
    pvVar1 = (void *)FBOContainer::~FBOContainer(*(FBOContainer **)(this + 0x404));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x404) = 0;
  if (*(FBOContainer **)(this + 0x408) != (FBOContainer *)0x0) {
    pvVar1 = (void *)FBOContainer::~FBOContainer(*(FBOContainer **)(this + 0x408));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x408) = 0;
  MeshRelease(this,(Mesh **)(this + 0x370));
  ReleaseGL();
  if (*(void **)(this + 0x504) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x504));
  }
  *(undefined4 *)(this + 0x504) = 0;
  if (*(void **)(this + 0x3cc) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x3cc));
  }
  *(undefined4 *)(this + 0x3cc) = 0;
  String::~String((String *)(this + 0x40));
  String::~String((String *)(this + 0x34));
  String::~String((String *)(this + 0x10));
  String::~String((String *)this);
  return;
}

// ===== AbyssEngine::Engine::AfterGLInit  @0x0008ef0c  (164 bytes)
/* AbyssEngine::Engine::AfterGLInit() */

void __thiscall AbyssEngine::Engine::AfterGLInit(Engine *this)

{
  undefined4 *puVar1;
  char *pcVar2;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  ResetLightParam(this);
  MeshCreate(this,4,2,0x13,this + 0x370);
  puVar1 = *(undefined4 **)(*(int *)(this + 0x370) + 0x2c);
  *puVar1 = 0x20000;
  puVar1[1] = 1;
  puVar1[2] = 0x20003;
  pcVar2 = (char *)glGetString(0x1f00);
  String::String(aSStack_1c,pcVar2,false);
  String::operator=((String *)&vendor,aSStack_1c);
  String::~String(aSStack_1c);
  pcVar2 = (char *)glGetString(0x1f01);
  String::String(aSStack_1c,pcVar2,false);
  String::operator=((String *)&renderer,aSStack_1c);
  String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Engine::ResetLightParam  @0x0008efd0  (486 bytes)
/* AbyssEngine::Engine::ResetLightParam() */

void __thiscall AbyssEngine::Engine::ResetLightParam(Engine *this)

{
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  *(undefined4 *)(this + 0x31c) = 1;
  *(undefined4 *)(this + 0x478) = 0x3f800000;
  *(undefined4 *)(this + 0x298) = 0x3e4ccccd;
  *(undefined4 *)(this + 0x29c) = 0x3e4ccccd;
  *(undefined4 *)(this + 0x2a0) = 0x3e4ccccd;
  *(undefined4 *)(this + 0x2a4) = 0x3f800000;
  *(undefined4 *)(this + 0x288) = 0x3f4ccccd;
  *(undefined4 *)(this + 0x28c) = 0x3f4ccccd;
  *(undefined4 *)(this + 0x290) = 0x3f4ccccd;
  *(undefined4 *)(this + 0x294) = 0x3f800000;
  *(undefined4 *)(this + 0x2a8) = 0;
  *(undefined4 *)(this + 0x2ac) = 0;
  *(undefined4 *)(this + 0x2b0) = 0;
  *(undefined4 *)(this + 0x2b4) = 0x3f800000;
  *(undefined4 *)(this + 0x2b8) = 0;
  *(undefined4 *)(this + 600) = 0;
  *(undefined4 *)(this + 0x25c) = 0;
  *(undefined4 *)(this + 0x260) = 0;
  *(undefined4 *)(this + 0x264) = 0x3f800000;
  *(undefined8 *)(this + 0x278) = 0;
  *(undefined8 *)(this + 0x280) = 0x3f80000000000000;
  *(undefined4 *)(this + 0x304) = 0;
  *(undefined4 *)(this + 0x308) = 0;
  *(undefined4 *)(this + 0x30c) = 0;
  *(undefined4 *)(this + 0x238) = 0x3f800000;
  *(undefined4 *)(this + 0x23c) = 0x3f800000;
  *(undefined4 *)(this + 0x218) = 0x3f800000;
  *(undefined4 *)(this + 0x21c) = 0x3f800000;
  *(undefined4 *)(this + 0x240) = 0x3f800000;
  *(undefined4 *)(this + 0x220) = 0x3f800000;
  *(undefined8 *)(this + 0x244) = 0x3f800000;
  *(undefined8 *)(this + 0x24c) = 0;
  *(undefined8 *)(this + 0x224) = 0x3f800000;
  *(undefined8 *)(this + 0x22c) = 0;
  *(undefined8 *)(this + 0x268) = 0;
  *(undefined8 *)(this + 0x270) = 0x3f80000000000000;
  *(undefined4 *)(this + 0x254) = 0x3f800000;
  *(undefined4 *)(this + 0x234) = 0x3f800000;
  *(undefined4 *)(this + 0x2ec) = 0x3f4ccccd;
  *(undefined4 *)(this + 0x2f0) = 0x3f4ccccd;
  *(undefined8 *)(this + 0x2f4) = 0x3f4ccccd;
  *(undefined8 *)(this + 0x2fc) = 0;
  *(float *)(this + 700) = *(float *)(this + 0x298) * 0.0;
  *(float *)(this + 0x2c0) = *(float *)(this + 0x29c) * 0.0;
  *(float *)(this + 0x2c4) = *(float *)(this + 0x2a0) * 0.0;
  *(float *)(this + 0x2c8) = *(float *)(this + 0x298) * 0.0;
  *(float *)(this + 0x2cc) = *(float *)(this + 0x29c) * 0.0;
  *(float *)(this + 0x2d0) = *(float *)(this + 0x2a0) * 0.0;
  *(float *)(this + 0x2d4) = *(float *)(this + 0x2a8);
  *(float *)(this + 0x2d8) = *(float *)(this + 0x2ac);
  *(float *)(this + 0x2dc) = *(float *)(this + 0x2b0);
  *(float *)(this + 0x2e0) = *(float *)(this + 0x2a8) * 0.0;
  *(float *)(this + 0x2e4) = *(float *)(this + 0x2ac) * 0.0;
  *(float *)(this + 0x2e8) = *(float *)(this + 0x2b0) * 0.0;
  if (enableShader == '\0') {
    glLightfv(0x4000,0x1200,this + 600);
    glLightfv(0x4000,0x1201,this + 0x218);
    glLightfv(0x4000,0x1202,this + 0x238);
    glMaterialfv(0x408,0x1200,this + 0x298);
    glMaterialfv(0x408,0x1201,this + 0x288);
    glMaterialfv(0x408,0x1202,this + 0x2a8);
    glMaterialf(0x408,0x1601,*(undefined4 *)(this + 0x2b8));
  }
  local_34 = 0;
  uStack_30 = 0x3f800000;
  local_2c = 0;
  AEMath::Vector::operator=((Vector *)(this + 0x458),(Vector *)&local_34);
  *(undefined4 *)(this + 0x368) = 0;
  local_34 = 0;
  uStack_30 = 0x3f800000;
  local_2c = 0;
  AEMath::Vector::operator=((Vector *)(this + 0x464),(Vector *)&local_34);
  *(undefined4 *)(this + 0x36c) = 0;
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Engine::Initialize  @0x0008f200  (6 bytes)
/* AbyssEngine::Engine::Initialize(void (*)(AbyssEngine::Engine*)) */

void __thiscall AbyssEngine::Engine::Initialize(Engine *this,_func_void_Engine_ptr *param_1)

{
  if (param_1 != (_func_void_Engine_ptr *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0008f202. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*param_1)(this);
    return;
  }
  return;
}

// ===== AbyssEngine::Engine::Release  @0x0008f206  (2 bytes)
/* AbyssEngine::Engine::Release() */

void AbyssEngine::Engine::Release(void)

{
  return;
}

// ===== AbyssEngine::Engine::GetDisplayWidth  @0x0008f208  (6 bytes)
/* AbyssEngine::Engine::GetDisplayWidth() */

undefined4 __thiscall AbyssEngine::Engine::GetDisplayWidth(Engine *this)

{
  return *(undefined4 *)(this + 0x358);
}

// ===== AbyssEngine::Engine::GetDisplayHeight  @0x0008f20e  (6 bytes)
/* AbyssEngine::Engine::GetDisplayHeight() */

undefined4 __thiscall AbyssEngine::Engine::GetDisplayHeight(Engine *this)

{
  return *(undefined4 *)(this + 0x35c);
}

// ===== AbyssEngine::Engine::HasVibration  @0x0008f214  (22 bytes)
/* AbyssEngine::Engine::HasVibration() */

bool __thiscall AbyssEngine::Engine::HasVibration(Engine *this)

{
  if (this[0x470] != (Engine)0x0) {
    return this[0x24] != (Engine)0x0;
  }
  return false;
}

// ===== AbyssEngine::Engine::Vibrate  @0x0008f22a  (2 bytes)
/* AbyssEngine::Engine::Vibrate(unsigned short) */

ushort AbyssEngine::Engine::Vibrate(ushort param_1)

{
  return param_1;
}

// ===== AbyssEngine::Engine::ClearBuffer  @0x0008f230  (118 bytes)
/* AbyssEngine::Engine::ClearBuffer(unsigned int) */

void __thiscall AbyssEngine::Engine::ClearBuffer(Engine *this,uint param_1)

{
  uint in_fpscr;
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)VectorUnsignedToFloat(param_1 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
  dVar2 = (double)VectorUnsignedToFloat((param_1 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  dVar3 = (double)VectorUnsignedToFloat((param_1 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
  dVar4 = (double)VectorUnsignedToFloat(param_1 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
  glClearColor((float)(dVar1 / 255.0),(float)(dVar2 / 255.0),(float)(dVar3 / 255.0),
               (float)(dVar4 / 255.0));
  glClear(0x4100);
  return;
}

// ===== AbyssEngine::Engine::SetOnDestroyApp  @0x0008f2b0  (6 bytes)
/* AbyssEngine::Engine::SetOnDestroyApp(void (*)(AbyssEngine::Engine*)) */

void __thiscall AbyssEngine::Engine::SetOnDestroyApp(Engine *this,_func_void_Engine_ptr *param_1)

{
  *(_func_void_Engine_ptr **)(this + 0x474) = param_1;
  return;
}

// ===== AbyssEngine::Engine::Suspend  @0x0008f2b6  (16 bytes)
/* AbyssEngine::Engine::Suspend() */

undefined4 __thiscall AbyssEngine::Engine::Suspend(Engine *this)

{
  PaintCanvas::Suspend((PaintCanvas *)**(undefined4 **)(this + 0x28));
  return 1;
}

// ===== AbyssEngine::Engine::Resume  @0x0008f2c6  (30 bytes)
/* AbyssEngine::Engine::Resume() */

undefined4 __thiscall AbyssEngine::Engine::Resume(Engine *this)

{
  PaintCanvas::Resume((PaintCanvas *)**(undefined4 **)(this + 0x28));
  __aeabi_memset4(this + 0x6c,0x50,0xff);
  return 1;
}

// ===== AbyssEngine::Engine::ShaderInit  @0x0008f384  (794 bytes)
/* AbyssEngine::Engine::ShaderInit() */

undefined4 __thiscall AbyssEngine::Engine::ShaderInit(Engine *this)

{
  TextureShader *this_00;
  SimpleShader *this_01;
  TextureVtxColorShader *this_02;
  NoTexShader *this_03;
  NoTexVtxColorShader *this_04;
  TextureAlphaTestShader *this_05;
  CubeMapping *this_06;
  CubeNormalMapping *this_07;
  BumpMapping *this_08;
  SandboxShader *this_09;
  GenericShader *this_10;
  GenericShader1 *this_11;
  GenericShader2 *this_12;
  TexOnlyShader *this_13;
  BumpShaderV2 *this_14;
  BumpShaderV3 *this_15;
  VertexColorShader *this_16;
  VertexColorAlphaTextureShader *this_17;
  PulseShader *this_18;
  BumpShader *this_19;
  BumpShaderV4 *this_20;
  BloomShader *this_21;
  BlurShader *this_22;
  PostBWShader *this_23;
  TextureLightShader *this_24;
  BumpRimCubeShader *this_25;
  BumpShaderCloak *this_26;
  SpecCubeMapping *this_27;
  SpecCubeAlphaMapping *this_28;
  EnergyShield *this_29;
  SimpleRefractionShader *this_30;
  GlowShader *this_31;
  GlowPPShader *this_32;
  DrawFBOShader *this_33;
  ColorMixAdd *this_34;
  BumpShaderParticle *this_35;
  DNSShader *this_36;
  BumpShaderRefract *this_37;
  BumpRimCubeShader_new *this_38;
  
  this_00 = operator_new(0x88);
  TextureShader::TextureShader(this_00);
  ShaderRegister(this,(ShaderBaseStruct *)this_00);
  this_01 = operator_new(0x28);
  SimpleShader::SimpleShader(this_01);
  ShaderRegister(this,(ShaderBaseStruct *)this_01);
  this_02 = operator_new(0x90);
  TextureVtxColorShader::TextureVtxColorShader(this_02);
  ShaderRegister(this,(ShaderBaseStruct *)this_02);
  this_03 = operator_new(0x28);
  NoTexShader::NoTexShader(this_03);
  ShaderRegister(this,(ShaderBaseStruct *)this_03);
  this_04 = operator_new(0x2c);
  NoTexVtxColorShader::NoTexVtxColorShader(this_04);
  ShaderRegister(this,(ShaderBaseStruct *)this_04);
  this_05 = operator_new(0x70);
  TextureAlphaTestShader::TextureAlphaTestShader(this_05);
  ShaderRegister(this,(ShaderBaseStruct *)this_05);
  this_06 = operator_new(0x58);
  CubeMapping::CubeMapping(this_06);
  ShaderRegister(this,(ShaderBaseStruct *)this_06);
  this_07 = operator_new(100);
  CubeNormalMapping::CubeNormalMapping(this_07);
  ShaderRegister(this,(ShaderBaseStruct *)this_07);
  this_08 = operator_new(0x40);
  BumpMapping::BumpMapping(this_08);
  ShaderRegister(this,(ShaderBaseStruct *)this_08);
  this_09 = operator_new(0x4c);
  SandboxShader::SandboxShader(this_09);
  ShaderRegister(this,(ShaderBaseStruct *)this_09);
  this_10 = operator_new(0x60);
  GenericShader::GenericShader(this_10);
  ShaderRegister(this,(ShaderBaseStruct *)this_10);
  this_11 = operator_new(0x54);
  GenericShader1::GenericShader1(this_11);
  ShaderRegister(this,(ShaderBaseStruct *)this_11);
  this_12 = operator_new(0x54);
  GenericShader2::GenericShader2(this_12);
  ShaderRegister(this,(ShaderBaseStruct *)this_12);
  this_13 = operator_new(0x2c);
  TexOnlyShader::TexOnlyShader(this_13);
  ShaderRegister(this,(ShaderBaseStruct *)this_13);
  this_14 = operator_new(0x5c);
  BumpShaderV2::BumpShaderV2(this_14);
  ShaderRegister(this,(ShaderBaseStruct *)this_14);
  this_15 = operator_new(0x80);
  BumpShaderV3::BumpShaderV3(this_15);
  ShaderRegister(this,(ShaderBaseStruct *)this_15);
  this_16 = operator_new(0x58);
  VertexColorShader::VertexColorShader(this_16);
  ShaderRegister(this,(ShaderBaseStruct *)this_16);
  this_17 = operator_new(0x58);
  VertexColorAlphaTextureShader::VertexColorAlphaTextureShader(this_17);
  ShaderRegister(this,(ShaderBaseStruct *)this_17);
  this_18 = operator_new(0x58);
  PulseShader::PulseShader(this_18);
  ShaderRegister(this,(ShaderBaseStruct *)this_18);
  this_19 = operator_new(0x80);
  BumpShader::BumpShader(this_19);
  ShaderRegister(this,(ShaderBaseStruct *)this_19);
  this_20 = operator_new(0x58);
  BumpShaderV4::BumpShaderV4(this_20);
  ShaderRegister(this,(ShaderBaseStruct *)this_20);
  this_21 = operator_new(0x9c);
  BloomShader::BloomShader(this_21);
  ShaderRegister(this,(ShaderBaseStruct *)this_21);
  this_22 = operator_new(0x60);
  BlurShader::BlurShader(this_22);
  ShaderRegister(this,(ShaderBaseStruct *)this_22);
  this_23 = operator_new(0x30);
  PostBWShader::PostBWShader(this_23);
  ShaderRegister(this,(ShaderBaseStruct *)this_23);
  this_24 = operator_new(0x6c);
  TextureLightShader::TextureLightShader(this_24);
  ShaderRegister(this,(ShaderBaseStruct *)this_24);
  this_25 = operator_new(0x94);
  BumpRimCubeShader::BumpRimCubeShader(this_25);
  ShaderRegister(this,(ShaderBaseStruct *)this_25);
  this_26 = operator_new(0x94);
  BumpShaderCloak::BumpShaderCloak(this_26);
  ShaderRegister(this,(ShaderBaseStruct *)this_26);
  this_27 = operator_new(0x58);
  SpecCubeMapping::SpecCubeMapping(this_27);
  ShaderRegister(this,(ShaderBaseStruct *)this_27);
  this_28 = operator_new(0x58);
  SpecCubeAlphaMapping::SpecCubeAlphaMapping(this_28);
  ShaderRegister(this,(ShaderBaseStruct *)this_28);
  this_29 = operator_new(0x5c);
  EnergyShield::EnergyShield(this_29);
  ShaderRegister(this,(ShaderBaseStruct *)this_29);
  this_30 = operator_new(0x54);
  SimpleRefractionShader::SimpleRefractionShader(this_30);
  ShaderRegister(this,(ShaderBaseStruct *)this_30);
  this_31 = operator_new(0x30);
  GlowShader::GlowShader(this_31);
  ShaderRegister(this,(ShaderBaseStruct *)this_31);
  this_32 = operator_new(0xa4);
  GlowPPShader::GlowPPShader(this_32);
  ShaderRegister(this,(ShaderBaseStruct *)this_32);
  this_33 = operator_new(0x5c);
  DrawFBOShader::DrawFBOShader(this_33);
  ShaderRegister(this,(ShaderBaseStruct *)this_33);
  this_34 = operator_new(0x3c);
  ColorMixAdd::ColorMixAdd(this_34);
  ShaderRegister(this,(ShaderBaseStruct *)this_34);
  this_35 = operator_new(0x68);
  BumpShaderParticle::BumpShaderParticle(this_35);
  ShaderRegister(this,(ShaderBaseStruct *)this_35);
  this_36 = operator_new(0x60);
  DNSShader::DNSShader(this_36);
  ShaderRegister(this,(ShaderBaseStruct *)this_36);
  this_37 = operator_new(0x48);
  BumpShaderRefract::BumpShaderRefract(this_37);
  ShaderRegister(this,(ShaderBaseStruct *)this_37);
  this_38 = operator_new(0x94);
  BumpRimCubeShader_new::BumpRimCubeShader_new(this_38);
  ShaderRegister(this,(ShaderBaseStruct *)this_38);
  glGetError();
  return 1;
}

// ===== AbyssEngine::Engine::ShaderRegister  @0x0008f6f8  (178 bytes)
/* AbyssEngine::Engine::ShaderRegister(AbyssEngine::ShaderBaseStruct*) */

void __thiscall AbyssEngine::Engine::ShaderRegister(Engine *this,ShaderBaseStruct *param_1)

{
  String *this_00;
  void *pvVar1;
  void *pvVar2;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (param_1 != (ShaderBaseStruct *)0x0) {
    this_00 = (String *)String::String(aSStack_24,param_1 + 0xc,false);
    pvVar1 = (void *)String::GetAEChar(this_00);
    String::~String(aSStack_24);
    (*(code *)**(undefined4 **)param_1)(param_1,this);
    *(int *)(this + 0x508) = *(int *)(this + 0x500) + 1;
    pvVar2 = realloc(*(void **)(this + 0x504),(*(int *)(this + 0x500) + 1) * 4);
    *(void **)(this + 0x504) = pvVar2;
    *(ShaderBaseStruct **)((int)pvVar2 + *(int *)(this + 0x500) * 4) = param_1;
    *(undefined4 *)(this + 0x500) = *(undefined4 *)(this + 0x508);
    *(int *)(this + 0x3d0) = *(int *)(this + 0x3c8) + 1;
    pvVar2 = realloc(*(void **)(this + 0x3cc),(*(int *)(this + 0x3c8) + 1) * 4);
    *(void **)(this + 0x3cc) = pvVar2;
    *(undefined4 *)((int)pvVar2 + *(int *)(this + 0x3c8) * 4) = 0;
    *(undefined4 *)(this + 0x3c8) = *(undefined4 *)(this + 0x3d0);
    if (pvVar1 != (void *)0x0) {
      operator_delete__(pvVar1);
    }
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Engine::SetFrameBufferTexture  @0x0008f7c0  (100 bytes)
/* AbyssEngine::Engine::SetFrameBufferTexture(int, int) */

void __thiscall AbyssEngine::Engine::SetFrameBufferTexture(Engine *this,int param_1,int param_2)

{
  Engine *pEVar1;
  undefined8 uVar2;
  
  pEVar1 = this + param_1 * 4;
  uVar2 = CONCAT44(*(int *)(pEVar1 + 0x47c),pEVar1);
  if (*(int *)(pEVar1 + 0x47c) != -1) {
    glActiveTexture(0x84c0);
    uVar2 = glBindTexture(0xde1,*(undefined4 *)(pEVar1 + 0x47c));
  }
  if (param_2 != -1) {
    uVar2 = CONCAT44(*(undefined4 *)(this + param_2 * 4 + 0x47c),this + param_2 * 4);
  }
  if (param_2 == -1 || (int)((ulonglong)uVar2 >> 0x20) == -1) {
    return;
  }
  glActiveTexture(0x84c1);
  glBindTexture(0xde1,*(undefined4 *)((int)uVar2 + 0x47c));
  return;
}

// ===== AbyssEngine::Engine::SetAddData  @0x0008f822  (6 bytes)
/* AbyssEngine::Engine::SetAddData(void*, int) */

void __thiscall AbyssEngine::Engine::SetAddData(Engine *this,void *param_1,int param_2)

{
  *(void **)(this + 0x348) = param_1;
  *(int *)(this + 0x34c) = param_2;
  return;
}

// ===== AbyssEngine::Engine::SetTexturesExt  @0x0008f828  (324 bytes)
/* AbyssEngine::Engine::SetTexturesExt(unsigned int, ...) */

void AbyssEngine::Engine::SetTexturesExt(uint param_1,...)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint in_r1;
  uint in_r2;
  undefined4 in_r3;
  int iVar4;
  int iVar5;
  float fVar6;
  uint *local_34;
  uint local_8;
  undefined4 uStack_4;
  
  iVar1 = __stack_chk_guard;
  local_8 = in_r2;
  uStack_4 = in_r3;
  if (*(int *)(**(int **)(param_1 + 0x28) + 0x10) == 0) goto LAB_0008f950;
  if (in_r1 == 0xffffffff) {
    iVar5 = 0;
LAB_0008f936:
    __aeabi_memset4(param_1 + iVar5 * 4 + 0x6c,iVar5 * -4 + 0x50,0xff);
  }
  else {
    iVar5 = 0;
    local_34 = &local_8;
    do {
      if ((in_r1 < *(uint *)(**(int **)(param_1 + 0x28) + 0x10)) &&
         (iVar4 = **(int **)(*(int *)(**(int **)(param_1 + 0x28) + 0x14) + in_r1 * 4),
         *(int *)(param_1 + 0x6c + iVar5 * 4) != iVar4)) {
        glActiveTexture(iVar5 + 0x84c0);
        iVar2 = *(int *)(*(int *)(**(int **)(param_1 + 0x28) + 0x14) + in_r1 * 4);
        fVar6 = *(float *)(iVar2 + 0xc);
        if (currentLODBias != fVar6) {
          currentLODBias = fVar6;
          if (enableShader == '\0') {
            glTexEnvf(0x8500,0x8501,fVar6);
            iVar2 = *(int *)(*(int *)(**(int **)(param_1 + 0x28) + 0x14) + in_r1 * 4);
          }
          else if (BiasErrorOutputFlag != '\0') {
            BiasErrorOutputFlag = '\0';
          }
        }
        if (*(char *)(iVar2 + 0x10) == '\0') {
          uVar3 = 0xde1;
        }
        else {
          uVar3 = 0x8513;
        }
        glBindTexture(uVar3,iVar4);
        *(int *)(param_1 + 0x6c + iVar5 * 4) = iVar4;
      }
      iVar5 = iVar5 + 1;
      in_r1 = *local_34;
      local_34 = local_34 + 1;
    } while (in_r1 != 0xffffffff);
    if (iVar5 < 0x14) goto LAB_0008f936;
  }
  glActiveTexture(0x84c0);
LAB_0008f950:
  if (__stack_chk_guard == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Engine::SetTextures  @0x0008f988  (318 bytes)
/* AbyssEngine::Engine::SetTextures(unsigned int, unsigned int) */

void __thiscall AbyssEngine::Engine::SetTextures(Engine *this,uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  iVar1 = **(int **)(this + 0x28);
  iVar3 = *(int *)(iVar1 + 0x10);
  if (iVar3 == 0) {
    return;
  }
  if (iVar3 - 1U < param_1) {
    return;
  }
  iVar4 = **(int **)(*(int *)(iVar1 + 0x14) + param_1 * 4);
  if (*(int *)(this + 0x6c) != iVar4) {
    glActiveTexture(0x84c0);
    fVar5 = *(float *)(*(int *)(*(int *)(**(int **)(this + 0x28) + 0x14) + param_1 * 4) + 0xc);
    if (currentLODBias != fVar5) {
      currentLODBias = fVar5;
      if (enableShader == '\0') {
        glTexEnvf(0x8500,0x8501,fVar5);
      }
      else if (BiasErrorOutputFlag != '\0') {
        BiasErrorOutputFlag = '\0';
      }
    }
    glBindTexture(0xde1,iVar4);
    *(int *)(this + 0x6c) = iVar4;
    iVar1 = **(int **)(this + 0x28);
    iVar3 = *(int *)(iVar1 + 0x10);
  }
  if (iVar3 - 1U < param_2) {
    if (*(int *)(this + 0x70) == -1) {
      return;
    }
    if (enableShader == '\0') {
      glActiveTexture(0x84c1);
      glDisable(0xde1);
      glActiveTexture(0x84c0);
    }
    *(undefined4 *)(this + 0x70) = 0xffffffff;
    return;
  }
  iVar1 = **(int **)(*(int *)(iVar1 + 0x14) + param_2 * 4);
  if (*(int *)(this + 0x70) == iVar1) {
    return;
  }
  glActiveTexture(0x84c1);
  if (enableShader == '\0') {
    glEnable(0xde1);
    if (enableShader != '\0') goto LAB_0008faa6;
  }
  else {
    *(uint *)(this + 0x410) = *(uint *)(this + 0x410) | 1;
LAB_0008faa6:
    if ((*(uint *)(this + 0x410) & 0x80008) != 0) {
      uVar2 = 0x8513;
      goto LAB_0008faba;
    }
  }
  uVar2 = 0xde1;
LAB_0008faba:
  glBindTexture(uVar2,iVar1);
  *(int *)(this + 0x70) = iVar1;
  return;
}

// ===== AbyssEngine::Engine::GlEnable  @0x0008fae8  (568 bytes)
/* AbyssEngine::Engine::GlEnable(unsigned int, bool) */

void __thiscall AbyssEngine::Engine::GlEnable(Engine *this,uint param_1,bool param_2)

{
  uint uVar1;
  
  if (enableShader == '\0') {
    if (param_1 >> 0x14 < 0x11) {
      if (param_1 == 0x1000000) {
        param_1 = 0xbc0;
      }
      if (param_2) {
        glEnable();
        return;
      }
      glDisable(param_1);
      return;
    }
  }
  else {
    switch(param_1) {
    case 0x1100000:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 4;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffffffb;
      }
      break;
    case 0x1100001:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 8;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffffff7;
      }
      break;
    case 0x1100002:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x10;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffffffef;
      }
      break;
    case 0x1100003:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x20;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffffffdf;
      }
      break;
    case 0x1100004:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x80;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffffff7f;
      }
      break;
    case 0x1100005:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x40;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffffffbf;
      }
      break;
    case 0x1100006:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x100;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffffeff;
      }
      break;
    case 0x1100007:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x200;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffffdff;
      }
      break;
    case 0x1100008:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x400;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffffbff;
      }
      break;
    case 0x1100009:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x1000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffffefff;
      }
      break;
    case 0x110000a:
    case 0x110000b:
    case 0x110000c:
    case 0x110000d:
    case 0x110000e:
    case 0x110000f:
    case 0x110001a:
    case 0x110001b:
    case 0x110001c:
    case 0x110001d:
    case 0x110001e:
    case 0x110001f:
      goto switchD_0008fafc_caseD_110000a;
    case 0x1100010:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x2000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffffdfff;
      }
      break;
    case 0x1100011:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x4000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffffbfff;
      }
      break;
    case 0x1100012:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x8000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffff7fff;
      }
      break;
    case 0x1100013:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x10000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffeffff;
      }
      break;
    case 0x1100014:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x20000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffdffff;
      }
      break;
    case 0x1100015:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x40000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfffbffff;
      }
      break;
    case 0x1100016:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x80000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfff7ffff;
      }
      break;
    case 0x1100017:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x100000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffefffff;
      }
      break;
    case 0x1100018:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x200000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffdfffff;
      }
      break;
    case 0x1100019:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x400000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xffbfffff;
      }
      break;
    case 0x1100020:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x800000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xff7fffff;
      }
      break;
    case 0x1100021:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x1000000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfeffffff;
      }
      break;
    case 0x1100022:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x2000000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfdffffff;
      }
      break;
    case 0x1100023:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x4000000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xfbffffff;
      }
      break;
    case 0x1100024:
      if (param_2) {
        uVar1 = *(uint *)(this + 0x410) | 0x8000000;
      }
      else {
        uVar1 = *(uint *)(this + 0x410) & 0xf7ffffff;
      }
      break;
    default:
      if (param_1 == 0xde1) {
        if (param_2) {
          uVar1 = *(uint *)(this + 0x410) | 1;
        }
        else {
          uVar1 = *(uint *)(this + 0x410) & 0xfffffffe;
        }
      }
      else {
        if (param_1 != 0x1000000) {
          return;
        }
        if (param_2) {
          uVar1 = *(uint *)(this + 0x410) | 2;
        }
        else {
          uVar1 = *(uint *)(this + 0x410) & 0xfffffffd;
        }
      }
    }
    *(uint *)(this + 0x410) = uVar1;
  }
switchD_0008fafc_caseD_110000a:
  return;
}

// ===== AbyssEngine::Engine::SetTextureSlot  @0x0008fd70  (192 bytes)
/* AbyssEngine::Engine::SetTextureSlot(unsigned int, unsigned int) */

void __thiscall AbyssEngine::Engine::SetTextureSlot(Engine *this,uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  
  iVar3 = *(int *)(**(int **)(this + 0x28) + 0x10);
  if (((iVar3 != 0) && (param_2 < 8)) && (param_1 <= iVar3 - 1U)) {
    iVar3 = **(int **)(*(int *)(**(int **)(this + 0x28) + 0x14) + param_1 * 4);
    if (*(int *)(this + param_2 * 4 + 0x6c) != iVar3) {
      glActiveTexture(param_2 + 0x84c0);
      iVar1 = *(int *)(*(int *)(**(int **)(this + 0x28) + 0x14) + param_1 * 4);
      fVar4 = *(float *)(iVar1 + 0xc);
      if (currentLODBias != fVar4) {
        currentLODBias = fVar4;
        if (enableShader == '\0') {
          glTexEnvf(0x8500,0x8501,fVar4);
          iVar1 = *(int *)(*(int *)(**(int **)(this + 0x28) + 0x14) + param_1 * 4);
        }
        else if (BiasErrorOutputFlag != '\0') {
          BiasErrorOutputFlag = '\0';
        }
      }
      if (*(char *)(iVar1 + 0x10) == '\0') {
        uVar2 = 0xde1;
      }
      else {
        uVar2 = 0x8513;
      }
      glBindTexture(uVar2,iVar3);
      *(int *)(this + param_2 * 4 + 0x6c) = iVar3;
    }
  }
  return;
}

// ===== AbyssEngine::Engine::SetEyePosition  @0x0008fe44  (60 bytes)
/* AbyssEngine::Engine::SetEyePosition(float, float, float) */

void __thiscall
AbyssEngine::Engine::SetEyePosition(Engine *this,float param_1,float param_2,float param_3)

{
  Vector local_18 [12];
  int local_c;
  
  local_c = __stack_chk_guard;
  AEMath::Vector::operator=((Vector *)(this + 0x3ec),local_18);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Engine::SetUVMatrix  @0x0008fe88  (142 bytes)
/* AbyssEngine::Engine::SetUVMatrix(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::Engine::SetUVMatrix(Engine *this,Matrix *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  if (enableShader == '\0') {
    glMatrixMode(0x1702);
    AEMath::MatrixGetGL(param_1,(float *)(this + 0x418));
    glLoadMatrixf(this + 0x418);
    glMatrixMode(0x1700);
    return;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  uVar7 = *(undefined4 *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar10 = *(undefined4 *)(param_1 + 0x2c);
  uVar8 = *(undefined4 *)(param_1 + 8);
  uVar6 = *(undefined4 *)(param_1 + 0xc);
  uVar5 = *(undefined4 *)(param_1 + 0x10);
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  uVar9 = *(undefined4 *)(param_1 + 0x1c);
  uVar4 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x1b4) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x1b8) = uVar5;
  *(undefined4 *)(this + 0x1bc) = uVar1;
  *(undefined4 *)(this + 0x1c0) = 0;
  *(undefined4 *)(this + 0x1c4) = uVar4;
  *(undefined4 *)(this + 0x1c8) = uVar2;
  *(undefined4 *)(this + 0x1cc) = uVar7;
  *(undefined4 *)(this + 0x1d0) = 0;
  *(undefined4 *)(this + 0x1d4) = uVar8;
  *(undefined4 *)(this + 0x1d8) = uVar3;
  *(undefined4 *)(this + 0x1dc) = uVar11;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1e4) = uVar6;
  *(undefined4 *)(this + 0x1e8) = uVar9;
  *(undefined4 *)(this + 0x1ec) = uVar10;
  *(undefined4 *)(this + 0x1f0) = 0x3f800000;
  return;
}

// ===== AbyssEngine::Engine::ResetUVMatrix  @0x0008ff1c  (108 bytes)
/* AbyssEngine::Engine::ResetUVMatrix() */

void __thiscall AbyssEngine::Engine::ResetUVMatrix(Engine *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (enableShader == '\0') {
    glMatrixMode(0x1702);
    glLoadIdentity();
    glScalef(0x3f800000,0xbf800000,0x3f800000);
    glMatrixMode(0x1700);
    return;
  }
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x1b4) = 0x3f800000;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = uVar1;
  *(undefined4 *)(this + 0x1c0) = uVar2;
  *(undefined4 *)(this + 0x1c4) = uVar3;
  *(undefined4 *)(this + 0x1c8) = 0x3f800000;
  *(undefined4 *)(this + 0x1cc) = 0;
  *(undefined4 *)(this + 0x1d0) = uVar1;
  *(undefined4 *)(this + 0x1d4) = uVar2;
  *(undefined4 *)(this + 0x1d8) = uVar3;
  *(undefined4 *)(this + 0x1dc) = 0x3f800000;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1e4) = uVar1;
  *(undefined4 *)(this + 0x1e8) = uVar2;
  *(undefined4 *)(this + 0x1ec) = uVar3;
  *(undefined4 *)(this + 0x1f0) = 0x3f800000;
  return;
}

// ===== AbyssEngine::Engine::SetModelMatrix  @0x0008ff8c  (406 bytes)
/* AbyssEngine::Engine::SetModelMatrix(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::Engine::SetModelMatrix(Engine *this,Matrix *param_1)

{
  Vector *pVVar1;
  AEMath aAStack_38 [12];
  AEMath aAStack_2c [12];
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (enableShader != '\0') {
    *(undefined4 *)(this + 500) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x1f8) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(this + 0x1fc) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(this + 0x200) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 0x204) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(this + 0x208) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(this + 0x20c) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(this + 0x210) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(this + 0x214) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(this + 0x134) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x138) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(this + 0x13c) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(this + 0x140) = 0;
    *(undefined4 *)(this + 0x144) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 0x148) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(this + 0x14c) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(this + 0x150) = 0;
    *(undefined4 *)(this + 0x154) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(this + 0x158) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(this + 0x15c) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(this + 0x160) = 0;
    *(undefined4 *)(this + 0x164) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(this + 0x168) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(this + 0x16c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(this + 0x170) = 0x3f800000;
    if (*(float *)(this + 0x368) == 0.0) {
      AEMath::MatrixInverseRotateVector(aAStack_38,param_1,(Vector *)(this + 0x458));
      pVVar1 = (Vector *)aAStack_2c;
      AEMath::VectorNormalize((AEMath *)pVVar1,(Vector *)aAStack_38);
    }
    else {
      pVVar1 = (Vector *)(this + 0x458);
    }
    AEMath::Vector::operator=((Vector *)(this + 800),pVVar1);
    if (1 < *(int *)(this + 0x31c)) {
      if (*(float *)(this + 0x36c) == 0.0) {
        AEMath::MatrixInverseRotateVector(aAStack_38,param_1,(Vector *)(this + 0x464));
        pVVar1 = (Vector *)aAStack_2c;
        AEMath::VectorNormalize((AEMath *)pVVar1,(Vector *)aAStack_38);
      }
      else {
        pVVar1 = (Vector *)(this + 0x464);
      }
      AEMath::Vector::operator=((Vector *)(this + 0x32c),pVVar1);
    }
    ShaderUpdate(this);
    AEMath::MatrixInverseTransformVector(aAStack_2c,param_1,(Vector *)(this + 0x3ec));
    AEMath::Vector::operator=((Vector *)(this + 0x33c),(Vector *)aAStack_2c);
    *(float *)(this + 0x33c) = *(float *)(this + 0x33c) / *(float *)(param_1 + 0x30);
    *(float *)(this + 0x340) = *(float *)(this + 0x340) / *(float *)(param_1 + 0x34);
    *(float *)(this + 0x344) = *(float *)(this + 0x344) / *(float *)(param_1 + 0x38);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Engine::ShaderUpdate  @0x00090130  (38 bytes)
/* AbyssEngine::Engine::ShaderUpdate() */

void __thiscall AbyssEngine::Engine::ShaderUpdate(Engine *this)

{
  uint uVar1;
  
  if (*(int *)(this + 0x500) != 0) {
    uVar1 = 0;
    do {
      ShaderBaseStruct::Update(*(ShaderBaseStruct **)(*(int *)(this + 0x504) + uVar1 * 4));
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(this + 0x500));
  }
  return;
}

// ===== AbyssEngine::Engine::SetWorldViewMatrix  @0x00090158  (204 bytes)
/* AbyssEngine::Engine::SetWorldViewMatrix(AbyssEngine::AEMath::Matrix const&) */

void __thiscall AbyssEngine::Engine::SetWorldViewMatrix(Engine *this,Matrix *param_1)

{
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (enableShader == '\0') {
    AEMath::MatrixGetGL(param_1,(float *)(this + 0x418));
    if (__stack_chk_guard == local_1c) {
      glLoadMatrixf(this + 0x418);
      return;
    }
  }
  else {
    local_60 = *(undefined4 *)param_1;
    local_5c = *(undefined4 *)(param_1 + 0x10);
    local_58 = *(undefined4 *)(param_1 + 0x20);
    local_54 = 0;
    local_50 = *(undefined4 *)(param_1 + 4);
    local_4c = *(undefined4 *)(param_1 + 0x14);
    local_48 = *(undefined4 *)(param_1 + 0x24);
    uStack_44 = 0;
    local_40 = *(undefined4 *)(param_1 + 8);
    local_3c = *(undefined4 *)(param_1 + 0x18);
    local_38 = *(undefined4 *)(param_1 + 0x28);
    uStack_34 = 0;
    local_30 = *(undefined4 *)(param_1 + 0xc);
    local_2c = *(undefined4 *)(param_1 + 0x1c);
    local_28 = *(undefined4 *)(param_1 + 0x2c);
    local_24 = 0x3f800000;
    *(undefined4 *)(this + 0x174) = local_60;
    *(undefined4 *)(this + 0x178) = local_5c;
    *(undefined4 *)(this + 0x17c) = local_58;
    *(undefined4 *)(this + 0x180) = 0;
    *(undefined4 *)(this + 0x184) = local_50;
    *(undefined4 *)(this + 0x188) = local_4c;
    *(undefined4 *)(this + 0x18c) = local_48;
    *(undefined4 *)(this + 400) = 0;
    *(undefined4 *)(this + 0x194) = local_40;
    *(undefined4 *)(this + 0x198) = local_3c;
    *(undefined4 *)(this + 0x19c) = local_38;
    *(undefined4 *)(this + 0x1a0) = 0;
    *(undefined4 *)(this + 0x1a4) = local_30;
    *(undefined4 *)(this + 0x1a8) = local_2c;
    *(undefined4 *)(this + 0x1ac) = local_28;
    *(undefined4 *)(this + 0x1b0) = 0x3f800000;
    esMatrixMultiply((ESMatrix *)(this + 0xf4),(ESMatrix *)&local_60,(ESMatrix *)(this + 0x374));
    if (__stack_chk_guard == local_1c) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Engine::SetPerspMatrix  @0x00090234  (108 bytes)
/* AbyssEngine::Engine::SetPerspMatrix(float*) */

void __thiscall AbyssEngine::Engine::SetPerspMatrix(Engine *this,float *param_1)

{
  if (enableShader != '\0') {
    *(float *)(this + 0x374) = *param_1;
    *(float *)(this + 0x378) = param_1[1];
    *(float *)(this + 0x37c) = param_1[2];
    *(float *)(this + 0x380) = param_1[3];
    *(float *)(this + 900) = param_1[4];
    *(float *)(this + 0x388) = param_1[5];
    *(float *)(this + 0x38c) = param_1[6];
    *(float *)(this + 0x390) = param_1[7];
    *(float *)(this + 0x394) = param_1[8];
    *(float *)(this + 0x398) = param_1[9];
    *(float *)(this + 0x39c) = param_1[10];
    *(float *)(this + 0x3a0) = param_1[0xb];
    *(float *)(this + 0x3a4) = param_1[0xc];
    *(float *)(this + 0x3a8) = param_1[0xd];
    *(float *)(this + 0x3ac) = param_1[0xe];
    *(float *)(this + 0x3b0) = param_1[0xf];
  }
  return;
}

// ===== AbyssEngine::Engine::SetOrthoMatrix  @0x000902a4  (258 bytes)
/* AbyssEngine::Engine::SetOrthoMatrix(float*, float*, bool) */

void __thiscall
AbyssEngine::Engine::SetOrthoMatrix(Engine *this,float *param_1,float *param_2,bool param_3)

{
  undefined8 local_4c;
  undefined8 uStack_44;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined8 local_2c;
  undefined8 uStack_24;
  undefined8 local_1c;
  undefined8 uStack_14;
  int local_c;
  
  local_c = __stack_chk_guard;
  if (enableShader != '\0') {
    *(float *)(this + 0x374) = *param_1;
    *(float *)(this + 0x378) = param_1[1];
    *(float *)(this + 0x37c) = param_1[2];
    *(float *)(this + 0x380) = param_1[3];
    *(float *)(this + 900) = param_1[4];
    *(float *)(this + 0x388) = param_1[5];
    *(float *)(this + 0x38c) = param_1[6];
    *(float *)(this + 0x390) = param_1[7];
    *(float *)(this + 0x394) = param_1[8];
    *(float *)(this + 0x398) = param_1[9];
    *(float *)(this + 0x39c) = param_1[10];
    *(float *)(this + 0x3a0) = param_1[0xb];
    *(float *)(this + 0x3a4) = param_1[0xc];
    *(float *)(this + 0x3a8) = param_1[0xd];
    *(float *)(this + 0x3ac) = param_1[0xe];
    *(float *)(this + 0x3b0) = param_1[0xf];
    if (param_3) {
      local_4c = *(undefined8 *)param_2;
      uStack_44 = *(undefined8 *)(param_2 + 2);
      local_3c = *(undefined8 *)(param_2 + 4);
      uStack_34 = *(undefined8 *)(param_2 + 6);
      local_2c = *(undefined8 *)(param_2 + 8);
      uStack_24 = *(undefined8 *)(param_2 + 10);
      local_1c = *(undefined8 *)(param_2 + 0xc);
      uStack_14 = *(undefined8 *)(param_2 + 0xe);
      esMatrixMultiply((ESMatrix *)(this + 0x374),(ESMatrix *)&local_4c,(ESMatrix *)(this + 0x374));
    }
  }
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Engine::SetColor  @0x000903b4  (218 bytes)
/* AbyssEngine::Engine::SetColor(float, float, float, float) */

void __thiscall
AbyssEngine::Engine::SetColor(Engine *this,float param_1,float param_2,float param_3,float param_4)

{
  float in_r1;
  float in_r2;
  float in_r3;
  float in_stack_00000000;
  
  if ((((*(float *)(this + 0xc0) == in_r1) && (*(float *)(this + 0xc4) == in_r2)) &&
      (*(float *)(this + 200) == in_r3)) && (*(float *)(this + 0xcc) == in_stack_00000000)) {
    return;
  }
  *(float *)(this + 0xc0) = in_r1;
  *(float *)(this + 0xc4) = in_r2;
  *(float *)(this + 200) = in_r3;
  *(float *)(this + 0xcc) = in_stack_00000000;
  *(int *)(this + 0xd0) =
       (int)(in_r2 * 255.0) * 0x10000 + (int)(in_r1 * 255.0) * 0x1000000 +
       (int)(in_r3 * 255.0) * 0x100 + (int)(in_stack_00000000 * 255.0);
  if (enableShader == '\0') {
    LightSetMaterialColorAlpha(this,in_stack_00000000);
    glColor4f();
    return;
  }
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetMaterialColorAlpha  @0x00090494  (98 bytes)
/* AbyssEngine::Engine::LightSetMaterialColorAlpha(float) */

void __thiscall AbyssEngine::Engine::LightSetMaterialColorAlpha(Engine *this,float param_1)

{
  undefined4 in_r1;
  
  if (this[0x414] == (Engine)0x0) {
    return;
  }
  *(undefined4 *)(this + 0x478) = in_r1;
  *(undefined4 *)(this + 0x2a4) = in_r1;
  glMaterialfv(0x408,0x1200,this + 0x298);
  *(undefined4 *)(this + 0x2b4) = *(undefined4 *)(this + 0x478);
  glMaterialfv(0x408,0x1202,this + 0x2a8);
  *(undefined4 *)(this + 0x294) = *(undefined4 *)(this + 0x478);
  glMaterialfv(0x408,0x1201,this + 0x288);
  return;
}

// ===== AbyssEngine::Engine::LightSetLightCount  @0x000904f6  (20 bytes)
/* AbyssEngine::Engine::LightSetLightCount(int) */

void __thiscall AbyssEngine::Engine::LightSetLightCount(Engine *this,int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (8 < param_1) {
    iVar1 = 8;
  }
  if (param_1 < 0) {
    iVar1 = 0;
  }
  *(int *)(this + 0x31c) = iVar1;
  return;
}

// ===== AbyssEngine::Engine::LightEnable  @0x0009050c  (92 bytes)
/* AbyssEngine::Engine::LightEnable(bool) */

void AbyssEngine::Engine::LightEnable(bool param_1)

{
  Engine *this;
  uint in_r1;
  float in_s0;
  
  this = (Engine *)(uint)param_1;
  if ((byte)this[0x414] == in_r1) {
    return;
  }
  this[0x414] = SUB41(in_r1,0);
  if (in_r1 == 0) {
    LightSetMaterialColorAlpha(this,in_s0);
  }
  if (enableShader == '\0') {
    if (in_r1 != 1) {
      glDisable(0x4000);
      glDisable(0xb50);
      return;
    }
    glEnable(0xb50);
    glEnable(0x4000);
    return;
  }
  return;
}

// ===== AbyssEngine::Engine::LightSetLight  @0x00090568  (154 bytes)
/* AbyssEngine::Engine::LightSetLight(unsigned int) */

void __thiscall AbyssEngine::Engine::LightSetLight(Engine *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 local_20;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_28 = 0x3f80000000000000;
  local_20 = 0;
  uVar1 = param_1 - 0x4000;
  if (uVar1 < 8) {
    iVar2 = param_1 - 0x3fff;
    if ((int)(param_1 - 0x3fff) < *(int *)(this + 0x31c)) {
      iVar2 = *(int *)(this + 0x31c);
    }
    *(int *)(this + 0x31c) = iVar2;
    local_28 = *(undefined8 *)(this + uVar1 * 0xc + 0x458);
    local_20 = CONCAT44(*(undefined4 *)(this + uVar1 * 4 + 0x368),
                        *(undefined4 *)(this + uVar1 * 0xc + 0x460));
    if (enableShader == '\0') {
      glLightfv(param_1,0x1203,&local_28);
    }
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::Engine::LightSetParticleAmbient  @0x00090614  (8 bytes)
/* AbyssEngine::Engine::LightSetParticleAmbient(float, float, float) */

Engine * __thiscall
AbyssEngine::Engine::LightSetParticleAmbient(Engine *this,float param_1,float param_2,float param_3)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  *(undefined4 *)(this + 0x304) = in_r1;
  *(undefined4 *)(this + 0x308) = in_r2;
  *(undefined4 *)(this + 0x30c) = in_r3;
  return this + 0x310;
}

// ===== AbyssEngine::Engine::LightSetGlobalSceneColorAmbient  @0x0009061c  (180 bytes)
/* AbyssEngine::Engine::LightSetGlobalSceneColorAmbient(float, float, float) */

void __thiscall
AbyssEngine::Engine::LightSetGlobalSceneColorAmbient
          (Engine *this,float param_1,float param_2,float param_3)

{
  float in_r1;
  undefined4 in_r2;
  int iVar1;
  undefined4 in_r3;
  int iVar2;
  int iVar3;
  
  *(float *)(this + 0x278) = in_r1;
  *(undefined4 *)(this + 0x27c) = in_r2;
  *(undefined4 *)(this + 0x280) = in_r3;
  *(undefined4 *)(this + 0x284) = 0x3f800000;
  if (enableShader == '\0') {
    glLightModelfv(0xb53);
    return;
  }
  if (0 < *(int *)(this + 0x31c)) {
    iVar2 = 0;
    iVar3 = 0;
    iVar1 = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      *(float *)(this + iVar2 + 700) =
           (in_r1 + *(float *)(this + iVar3 + 600)) * *(float *)(this + 0x298);
      *(float *)(this + iVar2 + 0x2c0) =
           (*(float *)(this + 0x27c) + *(float *)(this + iVar3 + 0x25c)) * *(float *)(this + 0x29c);
      *(float *)(this + iVar2 + 0x2c4) =
           (*(float *)(this + 0x280) + *(float *)(this + iVar3 + 0x260)) * *(float *)(this + 0x2a0);
      if (*(int *)(this + 0x31c) <= iVar1) break;
      iVar2 = iVar2 + 0xc;
      iVar3 = iVar3 + 0x10;
      in_r1 = *(float *)(this + 0x278);
    }
  }
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetLightDirection  @0x000906d4  (138 bytes)
/* AbyssEngine::Engine::LightSetLightDirection(float, float, float, unsigned int) */

void __thiscall
AbyssEngine::Engine::LightSetLightDirection
          (Engine *this,float param_1,float param_2,float param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  int in_stack_00000000;
  uint local_30 [3];
  AEMath aAStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  uVar2 = in_stack_00000000 - 0x4000;
  if (uVar2 < 8) {
    iVar1 = in_stack_00000000 + -0x3fff;
    if (in_stack_00000000 + -0x3fff < *(int *)(this + 0x31c)) {
      iVar1 = *(int *)(this + 0x31c);
    }
    *(int *)(this + 0x31c) = iVar1;
    local_30[0] = param_4;
    AEMath::VectorNormalize(aAStack_24,(Vector *)local_30);
    AEMath::Vector::operator=((Vector *)(this + uVar2 * 0xc + 0x458),(Vector *)aAStack_24);
    *(undefined4 *)(this + uVar2 * 4 + 0x368) = 0;
    param_1 = extraout_s0;
    param_2 = extraout_s1;
    param_3 = extraout_s2;
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_1,param_2,param_3);
  }
  return;
}

// ===== AbyssEngine::Engine::LightSetLightPosition  @0x00090768  (130 bytes)
/* AbyssEngine::Engine::LightSetLightPosition(float, float, float, unsigned int) */

void __thiscall
AbyssEngine::Engine::LightSetLightPosition
          (Engine *this,float param_1,float param_2,float param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  int in_stack_00000000;
  uint local_20 [3];
  int local_14;
  
  local_14 = __stack_chk_guard;
  uVar2 = in_stack_00000000 - 0x4000;
  if (uVar2 < 8) {
    iVar1 = in_stack_00000000 + -0x3fff;
    if (in_stack_00000000 + -0x3fff < *(int *)(this + 0x31c)) {
      iVar1 = *(int *)(this + 0x31c);
    }
    *(int *)(this + 0x31c) = iVar1;
    local_20[0] = param_4;
    AEMath::Vector::operator=((Vector *)(this + uVar2 * 0xc + 0x458),(Vector *)local_20);
    *(undefined4 *)(this + uVar2 * 4 + 0x368) = 0x3f800000;
    param_1 = extraout_s0;
    param_2 = extraout_s1;
    param_3 = extraout_s2;
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_1,param_2,param_3);
  }
  return;
}

// ===== AbyssEngine::Engine::LightSetLightColorDiffuse  @0x000907f4  (176 bytes)
/* AbyssEngine::Engine::LightSetLightColorDiffuse(float, float, float, unsigned int) */

void __thiscall
AbyssEngine::Engine::LightSetLightColorDiffuse
          (Engine *this,float param_1,float param_2,float param_3,uint param_4)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint uVar2;
  int in_stack_00000000;
  
  uVar2 = in_stack_00000000 - 0x4000;
  if (7 < uVar2) {
    return;
  }
  iVar1 = in_stack_00000000 + -0x3fff;
  if (in_stack_00000000 + -0x3fff < *(int *)(this + 0x31c)) {
    iVar1 = *(int *)(this + 0x31c);
  }
  *(int *)(this + 0x31c) = iVar1;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x224) = 0x3f800000;
  *(uint *)(this + uVar2 * 0x10 + 0x218) = param_4;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x21c) = in_r2;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x220) = in_r3;
  if (enableShader == '\0') {
    glLightfv(in_stack_00000000,0x1201,this + uVar2 * 0x10 + 0x218);
    return;
  }
  *(float *)(this + uVar2 * 0xc + 0x2ec) = *(float *)(this + 0x288) * (float)param_4;
  *(float *)(this + uVar2 * 0xc + 0x2f0) =
       *(float *)(this + uVar2 * 0x10 + 0x21c) * *(float *)(this + 0x28c);
  *(float *)(this + uVar2 * 0xc + 0x2f4) =
       *(float *)(this + uVar2 * 0x10 + 0x220) * *(float *)(this + 0x290);
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetLightColorAmbient  @0x000908a8  (200 bytes)
/* AbyssEngine::Engine::LightSetLightColorAmbient(float, float, float, unsigned int) */

void __thiscall
AbyssEngine::Engine::LightSetLightColorAmbient
          (Engine *this,float param_1,float param_2,float param_3,uint param_4)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint uVar2;
  int in_stack_00000000;
  
  uVar2 = in_stack_00000000 - 0x4000;
  if (7 < uVar2) {
    return;
  }
  iVar1 = in_stack_00000000 + -0x3fff;
  if (in_stack_00000000 + -0x3fff < *(int *)(this + 0x31c)) {
    iVar1 = *(int *)(this + 0x31c);
  }
  *(int *)(this + 0x31c) = iVar1;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x264) = 0x3f800000;
  *(uint *)(this + uVar2 * 0x10 + 600) = param_4;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x25c) = in_r2;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x260) = in_r3;
  if (enableShader == '\0') {
    glLightfv(in_stack_00000000,0x1200,this + uVar2 * 0x10 + 600);
    return;
  }
  *(float *)(this + uVar2 * 0xc + 700) =
       (*(float *)(this + 0x278) + (float)param_4) * *(float *)(this + 0x298);
  *(float *)(this + uVar2 * 0xc + 0x2c0) =
       (*(float *)(this + 0x27c) + *(float *)(this + uVar2 * 0x10 + 0x25c)) *
       *(float *)(this + 0x29c);
  *(float *)(this + uVar2 * 0xc + 0x2c4) =
       (*(float *)(this + 0x280) + *(float *)(this + uVar2 * 0x10 + 0x260)) *
       *(float *)(this + 0x2a0);
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetLightColorSpecular  @0x00090974  (178 bytes)
/* AbyssEngine::Engine::LightSetLightColorSpecular(float, float, float, unsigned int) */

void __thiscall
AbyssEngine::Engine::LightSetLightColorSpecular
          (Engine *this,float param_1,float param_2,float param_3,uint param_4)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint uVar2;
  int in_stack_00000000;
  
  uVar2 = in_stack_00000000 - 0x4000;
  if (7 < uVar2) {
    return;
  }
  iVar1 = in_stack_00000000 + -0x3fff;
  if (in_stack_00000000 + -0x3fff < *(int *)(this + 0x31c)) {
    iVar1 = *(int *)(this + 0x31c);
  }
  *(int *)(this + 0x31c) = iVar1;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x244) = 0x3f800000;
  *(uint *)(this + uVar2 * 0x10 + 0x238) = param_4;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x23c) = in_r2;
  *(undefined4 *)(this + uVar2 * 0x10 + 0x240) = in_r3;
  if (enableShader == '\0') {
    glLightfv(in_stack_00000000,0x1202,this + uVar2 * 0x10 + 0x238);
    return;
  }
  *(float *)(this + uVar2 * 0xc + 0x2d4) = *(float *)(this + 0x2a8) * (float)param_4;
  *(float *)(this + uVar2 * 0xc + 0x2d8) =
       *(float *)(this + uVar2 * 0x10 + 0x23c) * *(float *)(this + 0x2ac);
  *(float *)(this + uVar2 * 0xc + 0x2dc) =
       *(float *)(this + uVar2 * 0x10 + 0x240) * *(float *)(this + 0x2b0);
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetMaterialColorDiffuse  @0x00090a28  (154 bytes)
/* AbyssEngine::Engine::LightSetMaterialColorDiffuse(float, float, float) */

void __thiscall
AbyssEngine::Engine::LightSetMaterialColorDiffuse
          (Engine *this,float param_1,float param_2,float param_3)

{
  float in_r1;
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  int iVar2;
  int iVar3;
  
  *(float *)(this + 0x288) = in_r1;
  *(undefined4 *)(this + 0x28c) = in_r2;
  *(undefined4 *)(this + 0x290) = in_r3;
  *(undefined4 *)(this + 0x294) = *(undefined4 *)(this + 0x478);
  if (enableShader == '\0') {
    glMaterialfv(0x408,0x1201);
    return;
  }
  if (0 < *(int *)(this + 0x31c)) {
    iVar2 = 0;
    iVar3 = 0;
    iVar1 = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      *(float *)(this + iVar2 + 0x2ec) = *(float *)(this + iVar3 + 0x218) * in_r1;
      *(float *)(this + iVar2 + 0x2f0) = *(float *)(this + iVar3 + 0x21c) * *(float *)(this + 0x28c)
      ;
      *(float *)(this + iVar2 + 0x2f4) = *(float *)(this + iVar3 + 0x220) * *(float *)(this + 0x290)
      ;
      if (*(int *)(this + 0x31c) <= iVar1) break;
      iVar2 = iVar2 + 0xc;
      iVar3 = iVar3 + 0x10;
      in_r1 = *(float *)(this + 0x288);
    }
  }
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetMaterialColorAmbient  @0x00090ac8  (180 bytes)
/* AbyssEngine::Engine::LightSetMaterialColorAmbient(float, float, float) */

void __thiscall
AbyssEngine::Engine::LightSetMaterialColorAmbient
          (Engine *this,float param_1,float param_2,float param_3)

{
  float in_r1;
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  int iVar2;
  int iVar3;
  
  *(float *)(this + 0x298) = in_r1;
  *(undefined4 *)(this + 0x29c) = in_r2;
  *(undefined4 *)(this + 0x2a0) = in_r3;
  *(undefined4 *)(this + 0x2a4) = *(undefined4 *)(this + 0x478);
  if (enableShader == '\0') {
    glMaterialfv(0x408,0x1200);
    return;
  }
  if (0 < *(int *)(this + 0x31c)) {
    iVar2 = 0;
    iVar3 = 0;
    iVar1 = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      *(float *)(this + iVar2 + 700) =
           (*(float *)(this + 0x278) + *(float *)(this + iVar3 + 600)) * in_r1;
      *(float *)(this + iVar2 + 0x2c0) =
           (*(float *)(this + 0x27c) + *(float *)(this + iVar3 + 0x25c)) * *(float *)(this + 0x29c);
      *(float *)(this + iVar2 + 0x2c4) =
           (*(float *)(this + 0x280) + *(float *)(this + iVar3 + 0x260)) * *(float *)(this + 0x2a0);
      if (*(int *)(this + 0x31c) <= iVar1) break;
      iVar2 = iVar2 + 0xc;
      iVar3 = iVar3 + 0x10;
      in_r1 = *(float *)(this + 0x298);
    }
  }
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetMaterialColorSpecular  @0x00090b80  (156 bytes)
/* AbyssEngine::Engine::LightSetMaterialColorSpecular(float, float, float) */

void __thiscall
AbyssEngine::Engine::LightSetMaterialColorSpecular
          (Engine *this,float param_1,float param_2,float param_3)

{
  float in_r1;
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  int iVar2;
  int iVar3;
  
  *(float *)(this + 0x2a8) = in_r1;
  *(undefined4 *)(this + 0x2ac) = in_r2;
  *(undefined4 *)(this + 0x2b0) = in_r3;
  *(undefined4 *)(this + 0x2b4) = *(undefined4 *)(this + 0x478);
  if (enableShader == '\0') {
    glMaterialfv(0x408,0x1202);
    return;
  }
  if (0 < *(int *)(this + 0x31c)) {
    iVar2 = 0;
    iVar3 = 0;
    iVar1 = 0;
    while( true ) {
      iVar1 = iVar1 + 1;
      *(float *)(this + iVar2 + 0x2d4) = *(float *)(this + iVar3 + 0x238) * in_r1;
      *(float *)(this + iVar2 + 0x2d8) = *(float *)(this + iVar3 + 0x23c) * *(float *)(this + 0x2ac)
      ;
      *(float *)(this + iVar2 + 0x2dc) = *(float *)(this + iVar3 + 0x240) * *(float *)(this + 0x2b0)
      ;
      if (*(int *)(this + 0x31c) <= iVar1) break;
      iVar2 = iVar2 + 0xc;
      iVar3 = iVar3 + 0x10;
      in_r1 = *(float *)(this + 0x2a8);
    }
  }
  ShaderUpdate(this);
  return;
}

// ===== AbyssEngine::Engine::LightSetRimColor  @0x00090c20  (52 bytes)
/* AbyssEngine::Engine::LightSetRimColor(float, float, float) */

void __thiscall
AbyssEngine::Engine::LightSetRimColor(Engine *this,float param_1,float param_2,float param_3)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  if (enableShader != '\0') {
    *(undefined4 *)(this + 0x310) = in_r1;
    *(undefined4 *)(this + 0x314) = in_r2;
    *(undefined4 *)(this + 0x318) = in_r3;
    ShaderUpdate(this);
    return;
  }
  return;
}

// ===== AbyssEngine::Engine::LightSetMaterialColorShininess  @0x00090c58  (32 bytes)
/* AbyssEngine::Engine::LightSetMaterialColorShininess(float) */

void __thiscall AbyssEngine::Engine::LightSetMaterialColorShininess(Engine *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0x2b8) = in_r1;
  if (enableShader == '\0') {
    glMaterialf(0x408,0x1601);
    return;
  }
  return;
}

// ===== AbyssEngine::Engine::DrawLine2D  @0x00090c80  (48 bytes)
/* AbyssEngine::Engine::DrawLine2D(float*, int, bool) */

void __thiscall
AbyssEngine::Engine::DrawLine2D(Engine *this,float *param_1,int param_2,bool param_3)

{
  undefined4 uVar1;
  
  *(float **)(this + 0x338) = param_1;
  ShaderSetActive(this,NoTexShader::ShaderIndex,(Mesh *)0x0);
  if (param_3) {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  glDrawArrays(uVar1,0,param_2);
  return;
}

// ===== AbyssEngine::Engine::ShaderSetActive  @0x00090cb4  (196 bytes)
/* AbyssEngine::Engine::ShaderSetActive(int, AbyssEngine::Mesh*) */

void __thiscall AbyssEngine::Engine::ShaderSetActive(Engine *this,int param_1,Mesh *param_2)

{
  int *piVar1;
  bool bVar2;
  
  if (param_1 == -1) {
    piVar1 = &TextureShader::ShaderIndex;
    if (((byte)*param_2 & 2) == 0) {
      piVar1 = &SimpleShader::ShaderIndex;
    }
    param_1 = *piVar1;
    do {
    } while (param_1 == -1);
  }
  if (param_2 == (Mesh *)0x0) {
    bVar2 = false;
  }
  else {
    bVar2 = param_2[0x85] != (Mesh)0x0;
  }
  piVar1 = *(int **)(*(int *)(this + 0x504) + param_1 * 4);
  if (piVar1 != (int *)0x0) {
    ShaderSet = 1;
    if (piVar1[1] != *(int *)(this + 0x3d4)) {
      (**(code **)(*piVar1 + 0x20))(piVar1,bVar2);
      piVar1 = *(int **)(*(int *)(this + 0x504) + param_1 * 4);
      *(int *)(this + 0x3d4) = piVar1[1];
      currentUsedShaderIndex = param_1;
    }
    (**(code **)(*piVar1 + 0x20))(piVar1,bVar2);
    piVar1 = *(int **)(*(int *)(this + 0x504) + param_1 * 4);
    (**(code **)(*piVar1 + 4))(piVar1,param_2,this);
    if (param_2 != (Mesh *)0x0) {
      *(uint *)(*(int *)(this + 0x3cc) + param_1 * 4) =
           *(int *)(*(int *)(this + 0x3cc) + param_1 * 4) + *(ushort *)(param_2 + 0x28) / 3;
    }
  }
  return;
}

// ===== AbyssEngine::Engine::RenderMesh  @0x00090d88  (1116 bytes)
/* AbyssEngine::Engine::RenderMesh(AbyssEngine::Mesh*) */

void __thiscall AbyssEngine::Engine::RenderMesh(Engine *this,Mesh *param_1)

{
  ushort uVar1;
  uint uVar2;
  undefined **ppuVar3;
  bool bVar4;
  undefined1 auStack_18 [4];
  int local_14;
  
  local_14 = __stack_chk_guard;
  if ((param_1 != (Mesh *)0x0) && (*(short *)(param_1 + 0x28) != 0)) {
    if (enableShader == '\0') {
      glVertexPointer(3,0x1406,0,*(undefined4 *)(param_1 + 4));
      uVar2 = *(uint *)(this + 0x494);
      if ((uVar2 & 2) == 0) {
        glEnableClientState(0x8074);
        uVar2 = *(uint *)(this + 0x494) | 2;
        *(uint *)(this + 0x494) = uVar2;
      }
      if (((byte)*param_1 & 2) == 0) {
        if ((uVar2 & 4) != 0) {
          glDisableClientState(0x8078);
          uVar2 = *(uint *)(this + 0x494) & 0xfffffffb;
LAB_00090ef6:
          *(uint *)(this + 0x494) = uVar2;
        }
      }
      else if ((*(int *)(param_1 + 0x30) == 0) || (*(int *)(*(int *)(param_1 + 0x30) + 4) == -1)) {
        glTexCoordPointer(2,0x1406,0,*(undefined4 *)(param_1 + 8));
        uVar2 = *(uint *)(this + 0x494);
        if ((uVar2 & 4) == 0) {
          glEnableClientState(0x8078);
          uVar2 = *(uint *)(this + 0x494) | 4;
          goto LAB_00090ef6;
        }
      }
      if (((byte)*param_1 & 4) == 0) {
        if ((uVar2 & 1) != 0) {
          glDisableClientState(0x8075);
          uVar2 = *(uint *)(this + 0x494) & 0xfffffffe;
LAB_00090f40:
          *(uint *)(this + 0x494) = uVar2;
        }
      }
      else {
        glNormalPointer(0x1406,0,*(undefined4 *)(param_1 + 0x10));
        uVar2 = *(uint *)(this + 0x494);
        if ((uVar2 & 1) == 0) {
          glEnableClientState(0x8075);
          uVar2 = *(uint *)(this + 0x494) | 1;
          goto LAB_00090f40;
        }
      }
      if (((byte)*param_1 & 8) == 0) {
        if ((uVar2 & 8) != 0) {
          glDisableClientState(0x8076);
          uVar2 = *(uint *)(this + 0x494) & 0xfffffff7;
LAB_00090f8c:
          *(uint *)(this + 0x494) = uVar2;
        }
      }
      else {
        glColorPointer(4,0x1406,0,*(undefined4 *)(param_1 + 0xc));
        if (((byte)this[0x494] & 8) == 0) {
          glEnableClientState(0x8076);
          uVar2 = *(uint *)(this + 0x494) | 8;
          goto LAB_00090f8c;
        }
      }
      if ((*(uint *)param_1 & 0x10) == 0) {
        glDrawArrays(4,0,*(uint *)param_1 >> 0x10);
      }
      else {
        if (this[0xee] == (Engine)0x0) {
          uVar2 = (uint)*(ushort *)(param_1 + 0x28);
        }
        else {
          uVar2 = (uint)*(ushort *)(param_1 + 0x28);
          if (this[0xed] == (Engine)0x0) {
            *(uint *)(this + 0x48) = uVar2 / 3 + *(int *)(this + 0x48);
            *(int *)(this + 0x54) = *(int *)(this + 0x54) + 1;
          }
          else {
            *(uint *)(this + 0x4c) = uVar2 / 3 + *(int *)(this + 0x4c);
            *(int *)(this + 0x50) = *(int *)(this + 0x50) + 1;
          }
        }
        glDrawElements(4,uVar2,0x1403,*(undefined4 *)(param_1 + 0x2c));
      }
      uVar2 = (uint)(byte)*param_1;
      bVar4 = ((byte)*param_1 & 2) != 0;
      if (bVar4) {
        uVar2 = *(uint *)(param_1 + 0x30);
      }
      if ((bVar4 && uVar2 != 0) && (*(int *)(uVar2 + 4) != -1)) {
        if (((byte)this[0x494] & 4) != 0) {
          glDisableClientState(0x8078);
          *(uint *)(this + 0x494) = *(uint *)(this + 0x494) & 0xfffffffb;
        }
        if (__stack_chk_guard == local_14) {
          glClientActiveTexture(0x84c0);
          return;
        }
        goto LAB_000911a6;
      }
    }
    else {
      ShaderSet = '\0';
      uVar2 = *(uint *)(this + 0x410);
      if ((uVar2 & 0x1000) == 0) {
        if ((uVar2 & 0x2000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_0026567c;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x4000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_00265680;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x400) != 0) {
          ppuVar3 = &PTR_ShaderIndex_00265684;
          goto LAB_000910b8;
        }
        if ((uVar2 & 4) != 0) {
          ppuVar3 = &PTR_ShaderIndex_00265688;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x10000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_0026568c;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x1000000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_00265690;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x40000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_00265694;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x8000000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_00265698;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x200000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_0026569c;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x400000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_002656a0;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x100000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_002656a4;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x4000000) != 0) {
          ppuVar3 = &PTR_ShaderIndex_002656a8;
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x20000) != 0) {
          if (UseAdvancedShader == '\0') {
            ppuVar3 = &PTR_ShaderIndex_002656b0;
          }
          else {
            ppuVar3 = &PTR_ShaderIndex_002656ac;
          }
          goto LAB_000910b8;
        }
        if ((uVar2 & 0x2000000) == 0) {
          if ((uVar2 & 8) == 0) {
            if ((uVar2 & 0x80000) == 0) {
              if ((uVar2 & 0x8000) == 0) {
                if ((uVar2 & 2) == 0) {
                  if ((uVar2 & 1) == 0) {
                    ppuVar3 = &PTR_ShaderIndex_00265664;
                  }
                  else if (((byte)*param_1 & 10) == 8) {
                    ppuVar3 = &PTR_ShaderIndex_002656d0;
                  }
                  else if (this[0x414] == (Engine)0x0) {
                    if (((byte)*param_1 & 8) == 0) {
                      if ((uVar2 & 0x800000) == 0) {
                        ppuVar3 = &PTR_ShaderIndex_00265668;
                      }
                      else {
                        ppuVar3 = &PTR_ShaderIndex_002656cc;
                      }
                    }
                    else {
                      ppuVar3 = &PTR_ShaderIndex_002656c8;
                    }
                  }
                  else {
                    ppuVar3 = &PTR_ShaderIndex_002656c4;
                  }
                }
                else {
                  ppuVar3 = &PTR_ShaderIndex_002656c0;
                }
              }
              else {
                ppuVar3 = &PTR_ShaderIndex_002656bc;
              }
            }
            else {
              ppuVar3 = &PTR_ShaderIndex_002656b8;
            }
          }
          else {
            ppuVar3 = &PTR_ShaderIndex_002656b4;
          }
          goto LAB_000910b8;
        }
      }
      else {
        ppuVar3 = &PTR_ShaderIndex_00265678;
LAB_000910b8:
        ShaderSetActive(this,*(int *)*ppuVar3,param_1);
      }
      if (ShaderSet != '\0') {
        glGetIntegerv(0x8ca6,auStack_18);
        if ((*(uint *)param_1 & 0x10) == 0) {
          glDrawArrays(4,0,*(uint *)param_1 >> 0x10);
        }
        else {
          uVar1 = *(ushort *)(param_1 + 0x28);
          uVar2 = uVar1 / 3;
          if (param_1[0x5c] == (Mesh)0x0) {
            if (this[0xed] == (Engine)0x0) {
              *(uint *)(this + 0x48) = *(int *)(this + 0x48) + uVar2;
              *(int *)(this + 0x54) = *(int *)(this + 0x54) + 1;
            }
            else {
              *(uint *)(this + 0x4c) = *(int *)(this + 0x4c) + uVar2;
              *(int *)(this + 0x50) = *(int *)(this + 0x50) + 1;
            }
            glDrawElements(4,(uint)uVar1,0x1403,*(undefined4 *)(param_1 + 0x2c));
          }
          else {
            if (this[0xed] == (Engine)0x0) {
              *(uint *)(this + 0x58) = *(int *)(this + 0x58) + uVar2;
              *(int *)(this + 0x54) = *(int *)(this + 0x54) + 1;
            }
            else {
              *(uint *)(this + 0x5c) = *(int *)(this + 0x5c) + uVar2;
              *(int *)(this + 0x50) = *(int *)(this + 0x50) + 1;
            }
            glBindBuffer(0x8893,*(undefined4 *)(param_1 + 100));
            glDrawElements(4,*(undefined2 *)(param_1 + 0x28),0x1403,0);
            glBindBuffer(0x8892,0);
            glBindBuffer(0x8893,0);
          }
        }
        (**(code **)(**(int **)(*(int *)(this + 0x504) + currentUsedShaderIndex * 4) + 8))();
      }
    }
  }
  if (__stack_chk_guard == local_14) {
    return;
  }
LAB_000911a6:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Engine::ShaderSetInActive  @0x00091268  (22 bytes)
/* AbyssEngine::Engine::ShaderSetInActive() */

void __thiscall AbyssEngine::Engine::ShaderSetInActive(Engine *this)

{
                    /* WARNING: Could not recover jumptable at 0x0009127c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(*(int *)(this + 0x504) + currentUsedShaderIndex * 4) + 8))();
  return;
}

// ===== AbyssEngine::Engine::AEClientState  @0x00091284  (264 bytes)
/* AbyssEngine::Engine::AEClientState(unsigned int, bool) */

void __thiscall AbyssEngine::Engine::AEClientState(Engine *this,uint param_1,bool param_2)

{
  uint uVar1;
  
  if (param_2) {
    switch(param_1) {
    case 0x8074:
      if (((byte)this[0x494] & 2) != 0) {
        return;
      }
      glEnableClientState(0x8074);
      uVar1 = *(uint *)(this + 0x494) | 2;
      break;
    case 0x8075:
      if (((byte)this[0x494] & 1) != 0) {
        return;
      }
      glEnableClientState(0x8075);
      uVar1 = *(uint *)(this + 0x494) | 1;
      break;
    case 0x8076:
      if (((byte)this[0x494] & 8) != 0) {
        return;
      }
      glEnableClientState(0x8076);
      uVar1 = *(uint *)(this + 0x494) | 8;
      break;
    default:
      goto switchD_0009129a_caseD_8077;
    case 0x8078:
      if (((byte)this[0x494] & 4) != 0) {
        return;
      }
      glEnableClientState(0x8078);
      uVar1 = *(uint *)(this + 0x494) | 4;
    }
  }
  else {
    switch(param_1) {
    case 0x8074:
      if (((byte)this[0x494] & 2) == 0) {
        return;
      }
      glDisableClientState(0x8074);
      uVar1 = *(uint *)(this + 0x494) & 0xfffffffd;
      break;
    case 0x8075:
      if (((byte)this[0x494] & 1) == 0) {
        return;
      }
      glDisableClientState(0x8075);
      uVar1 = *(uint *)(this + 0x494) & 0xfffffffe;
      break;
    case 0x8076:
      if (((byte)this[0x494] & 8) == 0) {
        return;
      }
      glDisableClientState(0x8076);
      uVar1 = *(uint *)(this + 0x494) & 0xfffffff7;
      break;
    default:
      goto switchD_0009129a_caseD_8077;
    case 0x8078:
      if (((byte)this[0x494] & 4) == 0) {
        return;
      }
      glDisableClientState(0x8078);
      uVar1 = *(uint *)(this + 0x494) & 0xfffffffb;
    }
  }
  *(uint *)(this + 0x494) = uVar1;
switchD_0009129a_caseD_8077:
  return;
}

// ===== AbyssEngine::Engine::IsExtensionSupported  @0x00091398  (122 bytes)
/* AbyssEngine::Engine::IsExtensionSupported(char const*) */

undefined4 __thiscall AbyssEngine::Engine::IsExtensionSupported(Engine *this,char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = glGetString(0x1f03);
  iVar3 = 0;
  do {
    iVar2 = iVar3;
    iVar3 = iVar2 + 1;
  } while (*(char *)(iVar1 + iVar2) != '\0');
  iVar3 = 0;
  do {
    iVar4 = iVar3;
    iVar3 = iVar4 + 1;
  } while (param_1[iVar4] != '\0');
  if (0 < iVar2) {
    iVar3 = 0;
    do {
      if ((*(char *)(iVar1 + iVar3) == *param_1) && (0 < iVar4)) {
        iVar5 = 0;
        do {
          if ((iVar2 <= iVar3 + iVar5) || (param_1[iVar5] != *(char *)(iVar1 + iVar3 + iVar5)))
          break;
          if (iVar5 + 2 == iVar4 + 1) {
            return 1;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return 0;
}

// ===== AbyssEngine::Engine::GetGravValue  @0x00091412  (78 bytes)
/* AbyssEngine::Engine::GetGravValue() */

Engine * __thiscall AbyssEngine::Engine::GetGravValue(Engine *this)

{
  double dVar1;
  double dVar2;
  
  dVar2 = *(double *)(this + 0x4d8);
  dVar1 = *(double *)(this + 0x4d0);
  if (*(int *)(**(int **)(this + 0x28) + 0x30) == 1) {
    dVar2 = -*(double *)(this + 0x4d8);
    dVar1 = -*(double *)(this + 0x4d0);
  }
  *(double *)(this + 0x4e8) = dVar1;
  *(double *)(this + 0x4f0) = dVar2;
  *(undefined8 *)(this + 0x4f8) = *(undefined8 *)(this + 0x4e0);
  return this + 0x4e8;
}

// ===== AbyssEngine::Engine::GetAccelValue  @0x00091460  (78 bytes)
/* AbyssEngine::Engine::GetAccelValue() */

Engine * __thiscall AbyssEngine::Engine::GetAccelValue(Engine *this)

{
  double dVar1;
  double dVar2;
  
  dVar2 = *(double *)(this + 0x4a8);
  dVar1 = *(double *)(this + 0x4a0);
  if (*(int *)(**(int **)(this + 0x28) + 0x30) == 1) {
    dVar2 = -*(double *)(this + 0x4a8);
    dVar1 = -*(double *)(this + 0x4a0);
  }
  *(double *)(this + 0x4b8) = dVar1;
  *(double *)(this + 0x4c0) = dVar2;
  *(undefined8 *)(this + 0x4c8) = *(undefined8 *)(this + 0x4b0);
  return this + 0x4b8;
}

// ===== AbyssEngine::Engine::SetGravValue  @0x000914ae  (34 bytes)
/* AbyssEngine::Engine::SetGravValue(double, double, double) */

undefined4 AbyssEngine::Engine::SetGravValue(double param_1,double param_2,double param_3)

{
  int in_r0;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined8 in_stack_00000000;
  undefined8 in_stack_00000008;
  
  *(undefined4 *)(in_r0 + 0x4d0) = in_r2;
  *(undefined4 *)(in_r0 + 0x4d4) = in_r3;
  *(undefined8 *)(in_r0 + 0x4d8) = in_stack_00000000;
  *(undefined8 *)(in_r0 + 0x4e0) = in_stack_00000008;
  return SUB84(param_1,0);
}

// ===== AbyssEngine::Engine::SetAccelValue  @0x000914d0  (34 bytes)
/* AbyssEngine::Engine::SetAccelValue(double, double, double) */

undefined4 AbyssEngine::Engine::SetAccelValue(double param_1,double param_2,double param_3)

{
  int in_r0;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined8 in_stack_00000000;
  undefined8 in_stack_00000008;
  
  *(undefined4 *)(in_r0 + 0x4a0) = in_r2;
  *(undefined4 *)(in_r0 + 0x4a4) = in_r3;
  *(undefined8 *)(in_r0 + 0x4a8) = in_stack_00000000;
  *(undefined8 *)(in_r0 + 0x4b0) = in_stack_00000008;
  return SUB84(param_1,0);
}

// ===== AbyssEngine::Engine::ReloadShaders  @0x000914f2  (56 bytes)
/* AbyssEngine::Engine::ReloadShaders() */

void __thiscall AbyssEngine::Engine::ReloadShaders(Engine *this)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (*(int *)(this + 0x500) != 0) {
    uVar2 = 0;
    do {
      (**(code **)(**(int **)(*(int *)(this + 0x504) + uVar2 * 4) + 0x1c))();
      puVar1 = *(undefined4 **)(*(int *)(this + 0x504) + uVar2 * 4);
      (**(code **)*puVar1)(puVar1,this);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(this + 0x500));
  }
  return;
}

// ===== AbyssEngine::Engine::SetPostEffect  @0x0009152c  (326 bytes)
/* AbyssEngine::Engine::SetPostEffect(unsigned int, bool) */

void __thiscall AbyssEngine::Engine::SetPostEffect(Engine *this,uint param_1,bool param_2)

{
  FBOContainer *pFVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((*(int *)(this + 0x404) == 0) && (param_2)) {
    pFVar1 = operator_new(0x34);
    String::String(aSStack_24,"render2TextureFBO",false);
    FBOContainer::FBOContainer(pFVar1,this,aSStack_24);
    *(FBOContainer **)(this + 0x404) = pFVar1;
    String::~String(aSStack_24);
    iVar4 = *(int *)(this + 0x35c);
    iVar3 = *(int *)(this + 0x358);
    if (*(int *)(**(int **)(this + 0x28) + 0x30) == 2) {
      iVar3 = iVar4;
      iVar4 = *(int *)(this + 0x358);
    }
    FBOContainer::Create(*(int *)(this + 0x404),iVar4,SUB41(iVar3,0),true);
  }
  if (param_1 == 0x1400002) {
    if (param_2) {
      if (DAT_0026a0d8 < 1) {
        *(uint *)(this + 0x400) = *(uint *)(this + 0x400) | 4;
      }
      else {
        DAT_0026a0d8 = DAT_0026a0d8 + -1;
      }
    }
    else if (DAT_0026cae5 == '\x01') {
      *(uint *)(this + 0x400) = *(uint *)(this + 0x400) & 0xfffffffb;
      DAT_0026a0d8 = 1;
      DAT_0026cae5 = '\0';
    }
    else {
      DAT_0026cae5 = DAT_0026a0d8 < 1;
    }
  }
  else if (param_1 == 0x1400001) {
    if (param_2) {
      uVar2 = *(uint *)(this + 0x400) | 2;
    }
    else {
      uVar2 = *(uint *)(this + 0x400) & 0xfffffffd;
    }
    EnableGlow = param_2;
    *(uint *)(this + 0x400) = uVar2;
  }
  else if (param_1 == 0x1400000) {
    if (param_2) {
      uVar2 = *(uint *)(this + 0x400) | 1;
    }
    else {
      uVar2 = *(uint *)(this + 0x400) & 0xfffffffe;
    }
    *(uint *)(this + 0x400) = uVar2;
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Engine::DoPostEffect  @0x000916bc  (342 bytes)
/* AbyssEngine::Engine::DoPostEffect() */

void __thiscall AbyssEngine::Engine::DoPostEffect(Engine *this)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar3 = *(uint *)(this + 0x400);
  uVar2 = *(undefined4 *)(this + 0x404);
  local_20 = *(undefined4 *)(this + 0x408);
  if (enableShader != '\0') {
    uVar4 = uVar2;
    if ((uVar3 & 2) != 0) {
      uVar3 = uVar3 & 0xfffffffd;
      piVar1 = *(int **)(*(int *)(this + 0x504) + GlowPPShader::ShaderIndex * 4);
      if (uVar3 == 0) {
        (**(code **)(*piVar1 + 0xc))(piVar1,uVar2,this);
        uVar3 = 0;
      }
      else {
        (**(code **)(*piVar1 + 0x14))(piVar1,uVar2,&local_20,this);
        uVar4 = local_20;
        local_20 = uVar2;
      }
    }
    uVar2 = uVar4;
    if (((byte)this[0x400] & 1) != 0) {
      uVar3 = uVar3 & 0xfffffffe;
      piVar1 = *(int **)(*(int *)(this + 0x504) + BloomShader::ShaderIndex * 4);
      if (uVar3 == 0) {
        (**(code **)(*piVar1 + 0xc))(piVar1,uVar4,this);
        uVar3 = 0;
      }
      else {
        (**(code **)(*piVar1 + 0x14))(piVar1,uVar4,&local_20,this);
        uVar2 = local_20;
        local_20 = uVar4;
      }
    }
    if (((byte)this[0x400] & 4) != 0) {
      piVar1 = *(int **)(*(int *)(this + 0x504) + BlurShader::ShaderIndex * 4);
      if ((uVar3 & 0xfffffffb) == 0) {
        (**(code **)(*piVar1 + 0x10))
                  (piVar1,uVar2,this,*(undefined4 *)(this + 0x3b8),*(undefined4 *)(this + 0x3bc),
                   *(undefined4 *)(this + 0x3c0),*(undefined4 *)(this + 0x3c4));
      }
      else {
        (**(code **)(*piVar1 + 0x18))
                  (piVar1,uVar2,&local_20,this,*(undefined4 *)(this + 0x3b8),
                   *(undefined4 *)(this + 0x3bc),*(undefined4 *)(this + 0x3c0),
                   *(undefined4 *)(this + 0x3c4));
        local_20 = uVar2;
      }
    }
    if (DAT_0026cae5 == '\x01') {
      *(uint *)(this + 0x400) = *(uint *)(this + 0x400) & 0xfffffffb;
      DAT_0026a0d8 = 1;
      DAT_0026cae5 = '\0';
    }
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::Engine::DrawCloakFBO  @0x00091838  (36 bytes)
/* AbyssEngine::Engine::DrawCloakFBO(AbyssEngine::FBOContainer*) */

void AbyssEngine::Engine::DrawCloakFBO(FBOContainer *param_1)

{
  if (enableShader != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00091858. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(*(int *)(param_1 + 0x504) + DrawFBOShader::ShaderIndex * 4) + 0xc))();
    return;
  }
  return;
}

// ===== AbyssEngine::Engine::IsPostEffectActivated  @0x00091864  (12 bytes)
/* AbyssEngine::Engine::IsPostEffectActivated() */

bool __thiscall AbyssEngine::Engine::IsPostEffectActivated(Engine *this)

{
  return *(int *)(this + 0x400) != 0;
}

// ===== AbyssEngine::Engine::IsRefractActivated  @0x00091870  (4 bytes)
/* AbyssEngine::Engine::IsRefractActivated() */

undefined4 AbyssEngine::Engine::IsRefractActivated(void)

{
  return 1;
}

// ===== AbyssEngine::Engine::DrawQuad  @0x00091880  (118 bytes)
/* AbyssEngine::Engine::DrawQuad(int, int, int, int) */

void __thiscall
AbyssEngine::Engine::DrawQuad(Engine *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  uint in_fpscr;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar4 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  uVar5 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = *(int *)(this + 0x370);
  uVar6 = VectorSignedToFloat(param_1 + param_3,(byte)(in_fpscr >> 0x16) & 3);
  puVar2 = *(undefined4 **)(iVar1 + 4);
  uVar7 = VectorSignedToFloat(param_4 + param_2,(byte)(in_fpscr >> 0x16) & 3);
  *puVar2 = uVar5;
  puVar2[1] = uVar4;
  puVar2[3] = uVar6;
  puVar2[4] = uVar4;
  puVar2[6] = uVar6;
  puVar2[7] = uVar7;
  puVar2[9] = uVar5;
  puVar2[10] = uVar7;
  puVar3 = *(undefined8 **)(iVar1 + 8);
  *puVar3 = 0x3f80000000000000;
  puVar3[1] = 0x3f8000003f800000;
  puVar3[2] = 0x3f800000;
  puVar3[3] = 0;
  glDrawElements(4,*(undefined2 *)(iVar1 + 0x28),0x1403,*(undefined4 *)(iVar1 + 0x2c));
  return;
}

// ===== AbyssEngine::Engine::GlowBeginGlow  @0x00091920  (60 bytes)
/* AbyssEngine::Engine::GlowBeginGlow(int) */

void __thiscall AbyssEngine::Engine::GlowBeginGlow(Engine *this,int param_1)

{
  if ((this[0x40c] == (Engine)0x0) && (EnableGlow != '\0')) {
    glColorMask(0,0,0,1);
    GlowEnableGlow(this);
    if (this[0x40c] != (Engine)0x0) {
      glDepthFunc(param_1);
      return;
    }
  }
  return;
}

// ===== AbyssEngine::Engine::GlowEnableGlow  @0x00091960  (40 bytes)
/* AbyssEngine::Engine::GlowEnableGlow() */

void __thiscall AbyssEngine::Engine::GlowEnableGlow(Engine *this)

{
  if (this[0x40c] == (Engine)0x0) {
    glClearColor(0,0,0,0);
    glClear(0x4000);
    this[0x40c] = (Engine)0x1;
  }
  return;
}

// ===== AbyssEngine::Engine::GlowEndGlow  @0x00091988  (48 bytes)
/* AbyssEngine::Engine::GlowEndGlow() */

void __thiscall AbyssEngine::Engine::GlowEndGlow(Engine *this)

{
  if (EnableGlow == '\0') {
    return;
  }
  this[0x40c] = (Engine)0x0;
  glColorMask(1,1,1,1);
  glDepthFunc(0x201);
  return;
}

