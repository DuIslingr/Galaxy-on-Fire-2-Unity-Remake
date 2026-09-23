// Class: AbyssEngine::FBOContainer
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::FBOContainer::FBOContainer  @0x00089f2c  (60 bytes)
/* AbyssEngine::FBOContainer::FBOContainer(AbyssEngine::Engine*, AbyssEngine::String) */

FBOContainer * __thiscall
AbyssEngine::FBOContainer::FBOContainer(FBOContainer *this,undefined4 param_1,String *param_3)

{
  String::String((String *)(this + 0x1c));
  this[0x24] = (FBOContainer)0x0;
  this[0x18] = (FBOContainer)0x0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x10) = 0;
  String::operator=((String *)(this + 0x1c),param_3);
  *(undefined4 *)(this + 0x14) = param_1;
  return this;
}

// ===== AbyssEngine::FBOContainer::~FBOContainer  @0x00089f76  (22 bytes)
/* AbyssEngine::FBOContainer::~FBOContainer() */

FBOContainer * __thiscall AbyssEngine::FBOContainer::~FBOContainer(FBOContainer *this)

{
  Release(this);
  String::~String((String *)(this + 0x1c));
  return this;
}

// ===== AbyssEngine::FBOContainer::Release  @0x00089f9c  (94 bytes)
/* AbyssEngine::FBOContainer::Release() */

void __thiscall AbyssEngine::FBOContainer::Release(FBOContainer *this)

{
  if (this[0x18] == (FBOContainer)0x0) {
    return;
  }
  glDeleteFramebuffers(1,this);
  *(undefined4 *)this = 0;
  glDeleteTextures(1,this + 4);
  *(undefined4 *)(this + 4) = 0;
  glDeleteRenderbuffers(1,this + 8);
  *(undefined4 *)(this + 8) = 0;
  this[0x18] = (FBOContainer)0x0;
  glDeleteRenderbuffers(1,this + 0x2c);
  glDeleteRenderbuffers(1,this + 0x30);
  glBindFramebuffer(0x8d40,0);
  glDeleteFramebuffers(1,this + 0x28);
  return;
}

// ===== AbyssEngine::FBOContainer::Create  @0x00089ff8  (294 bytes)
/* AbyssEngine::FBOContainer::Create(int, int, bool, bool) */

void AbyssEngine::FBOContainer::Create(int param_1,int param_2,bool param_3,bool param_4)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xc) = param_2;
  *(uint *)(param_1 + 0x10) = (uint)param_3;
  glGenFramebuffers(1,param_1);
  glBindFramebuffer(0x8d40,*(undefined4 *)param_1);
  glGenTextures(1,param_1 + 4);
  glBindTexture(0xde1,*(undefined4 *)(param_1 + 4));
  glPixelStorei(0xcf5,1);
  glTexParameteri(0xde1,0x2802,0x812f);
  glTexParameteri(0xde1,0x2803,0x812f);
  if (param_4) {
    glTexParameteri(0xde1,0x2800,0x2601);
    uVar1 = 0x2601;
  }
  else {
    glTexParameteri(0xde1,0x2800,0x2600);
    uVar1 = 0x2600;
  }
  glTexParameteri(0xde1,0x2801,uVar1);
  glTexImage2D(0xde1,0,0x1908,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),0,
               0x1908,0x1401,0);
  glFramebufferTexture2D(0x8d40,0x8ce0,0xde1,*(undefined4 *)(param_1 + 4),0);
  glGenRenderbuffers(1,param_1 + 8);
  glBindRenderbuffer(0x8d41,*(undefined4 *)(param_1 + 8));
  glRenderbufferStorage
            (0x8d41,0x81a6,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  glFramebufferRenderbuffer(0x8d40,0x8d00,0x8d41,*(undefined4 *)(param_1 + 8));
  glCheckFramebufferStatus(0x8d40);
  *(undefined1 *)(param_1 + 0x18) = 1;
  glBindFramebuffer(0x8d40,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x3fc));
  return;
}

// ===== AbyssEngine::FBOContainer::BeginCapture  @0x0008a11e  (34 bytes)
/* AbyssEngine::FBOContainer::BeginCapture() */

void __thiscall AbyssEngine::FBOContainer::BeginCapture(FBOContainer *this)

{
  glBindFramebuffer(0x8d40,*(undefined4 *)this);
  glViewport(0,0,*(undefined4 *)(this + 0xc),*(undefined4 *)(this + 0x10));
  return;
}

// ===== AbyssEngine::FBOContainer::EndCapture  @0x0008a13e  (16 bytes)
/* AbyssEngine::FBOContainer::EndCapture() */

void __thiscall AbyssEngine::FBOContainer::EndCapture(FBOContainer *this)

{
  glBindFramebuffer(0x8d40,*(undefined4 *)(*(int *)(this + 0x14) + 0x3fc));
  return;
}

// ===== AbyssEngine::FBOContainer::Activate  @0x0008a14c  (10 bytes)
/* AbyssEngine::FBOContainer::Activate() */

void __thiscall AbyssEngine::FBOContainer::Activate(FBOContainer *this)

{
  glBindTexture(0xde1,*(undefined4 *)(this + 4));
  return;
}

