// Class: Sprite
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Sprite::Sprite  @0x000e26f0  (98 bytes)
/* Sprite::Sprite(unsigned int, int, int) */

Sprite * __thiscall Sprite::Sprite(Sprite *this,uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)this = 0;
  *(uint *)(this + 4) = param_1;
  *(int *)(this + 0x18) = param_2;
  *(int *)(this + 0x1c) = param_3;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,param_1);
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 4));
  *(undefined4 *)(this + 0x24) = uVar1;
  iVar2 = __aeabi_idiv(*(undefined4 *)(this + 0x20),*(undefined4 *)(this + 0x18));
  *(int *)(this + 0x30) = iVar2;
  iVar3 = __aeabi_idiv(uVar1,*(undefined4 *)(this + 0x1c));
  *(int *)(this + 0x34) = iVar3;
  *(undefined4 *)(this + 0x38) = 0;
  *(int *)(this + 0x3c) = iVar3 * iVar2;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  return this;
}

// ===== Sprite::setFrame  @0x000e2758  (54 bytes)
/* Sprite::setFrame(int) */

void __thiscall Sprite::setFrame(Sprite *this,int param_1)

{
  int extraout_r1;
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  *(int *)(this + 0x38) = param_1;
  if (*(int *)(this + 0x3c) <= param_1) {
    __aeabi_idivmod(param_1,*(int *)(this + 0x3c));
    *(int *)(this + 0x38) = extraout_r1;
    param_1 = extraout_r1;
  }
  iVar1 = *(int *)(this + 0x18);
  uVar2 = __aeabi_idivmod(param_1,*(undefined4 *)(this + 0x30));
  *(int *)(this + 0x28) = iVar1 * (int)((ulonglong)uVar2 >> 0x20);
  *(int *)(this + 0x2c) = *(int *)(this + 0x1c) * (int)uVar2;
  return;
}

// ===== Sprite::Sprite  @0x000e2790  (92 bytes)
/* Sprite::Sprite(unsigned int*, int, int, int) */

Sprite * __thiscall Sprite::Sprite(Sprite *this,uint *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  *(uint **)this = param_1;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(int *)(this + 0x18) = param_3;
  *(int *)(this + 0x1c) = param_4;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*param_1);
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,**(uint **)this);
  *(undefined4 *)(this + 0x24) = uVar1;
  *(undefined4 *)(this + 0x38) = 0;
  *(int *)(this + 0x3c) = param_2;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0x100000001;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  return this;
}

// ===== Sprite::~Sprite  @0x000e2810  (22 bytes)
/* Sprite::~Sprite() */

Sprite * __thiscall Sprite::~Sprite(Sprite *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  return this;
}

// ===== Sprite::defineReferencePixel  @0x000e2826  (6 bytes)
/* Sprite::defineReferencePixel(int, int) */

void __thiscall Sprite::defineReferencePixel(Sprite *this,int param_1,int param_2)

{
  *(int *)(this + 8) = param_1;
  *(int *)(this + 0xc) = param_2;
  return;
}

// ===== Sprite::setRefPixelPosition  @0x000e282c  (6 bytes)
/* Sprite::setRefPixelPosition(int, int) */

void __thiscall Sprite::setRefPixelPosition(Sprite *this,int param_1,int param_2)

{
  *(int *)(this + 0x10) = param_1;
  *(int *)(this + 0x14) = param_2;
  return;
}

// ===== Sprite::setPosition  @0x000e2832  (6 bytes)
/* Sprite::setPosition(int, int) */

void __thiscall Sprite::setPosition(Sprite *this,int param_1,int param_2)

{
  *(int *)(this + 0x10) = param_1;
  *(int *)(this + 0x14) = param_2;
  return;
}

// ===== Sprite::getFrame  @0x000e2838  (4 bytes)
/* Sprite::getFrame() */

undefined4 __thiscall Sprite::getFrame(Sprite *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== Sprite::getRawFrameCount  @0x000e283c  (4 bytes)
/* Sprite::getRawFrameCount() */

undefined4 __thiscall Sprite::getRawFrameCount(Sprite *this)

{
  return *(undefined4 *)(this + 0x3c);
}

// ===== Sprite::getFrameWidth  @0x000e2840  (4 bytes)
/* Sprite::getFrameWidth() */

undefined4 __thiscall Sprite::getFrameWidth(Sprite *this)

{
  return *(undefined4 *)(this + 0x18);
}

// ===== Sprite::getFrameHeight  @0x000e2844  (4 bytes)
/* Sprite::getFrameHeight() */

undefined4 __thiscall Sprite::getFrameHeight(Sprite *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== Sprite::draw  @0x000e2848  (276 bytes)
/* Sprite::draw(float, float) */

void Sprite::draw(float param_1,float param_2)

{
  bool bVar1;
  uint uVar2;
  int *in_r0;
  float in_r1;
  uint uVar3;
  float in_r2;
  int iVar4;
  uint in_fpscr;
  float in_s2;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if (*in_r0 == 0) {
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,in_r0[1],in_r0[10],in_r0[0xb],in_r0[6],in_r0[7],param_1,0,0,0,
               in_r0[4] - in_r0[2]);
    return;
  }
  iVar4 = in_r0[2];
  uVar3 = *(uint *)(*in_r0 + in_r0[0xe] * 4);
  bVar1 = in_r1 != 1.0;
  uVar2 = in_fpscr & 0xfffffff;
  if (bVar1) {
    in_s2 = in_r2;
  }
  if (!bVar1 || (!bVar1 || in_s2 == 1.0)) {
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar3,in_r0[4] - iVar4,in_r0[5] - iVar4);
    return;
  }
  fVar6 = (float)VectorSignedToFloat(in_r0[7],(byte)(uVar2 >> 0x16) & 3);
  fVar5 = (float)VectorSignedToFloat(in_r0[6],(byte)(uVar2 >> 0x16) & 3);
  fVar8 = (float)VectorSignedToFloat(in_r0[5] - iVar4,(byte)(uVar2 >> 0x16) & 3);
  fVar7 = (float)VectorSignedToFloat(in_r0[4] - iVar4,(byte)(uVar2 >> 0x16) & 3);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,uVar3,(int)(fVar7 - (in_r1 + -1.0) * fVar5 * 0.5),
             (int)(fVar8 - (in_s2 + -1.0) * fVar6 * 0.5),(int)(fVar5 * in_r1),(int)(fVar6 * in_s2),
             '\x11','\x11','\0');
  return;
}

// ===== Sprite::drawRegion  @0x000e2964  (130 bytes)
/* Sprite::drawRegion(int, int, int, int) */

void Sprite::drawRegion(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  float in_s0;
  int in_stack_00000000;
  
  if (*(int *)param_1 == 0) {
    uVar1 = *(uint *)(param_1 + 4);
    iVar2 = (*(int *)(param_1 + 0x10) + param_2) - *(int *)(param_1 + 8);
    param_3 = *(int *)(param_1 + 0x2c) + param_3;
    param_2 = *(int *)(param_1 + 0x28) + param_2;
  }
  else {
    uVar1 = *(uint *)(*(int *)param_1 + *(int *)(param_1 + 0x38) * 4);
    iVar2 = (*(int *)(param_1 + 0x10) + param_2) - *(int *)(param_1 + 8);
  }
  AbyssEngine::PaintCanvas::DrawRegion2D
            (Globals::Canvas,uVar1,param_2,param_3,param_4,in_stack_00000000,in_s0,0,0,0,iVar2);
  return;
}

// ===== Sprite::nextFrame  @0x000e29ec  (8 bytes)
/* Sprite::nextFrame() */

void __thiscall Sprite::nextFrame(Sprite *this)

{
  setFrame(this,*(int *)(this + 0x38) + 1);
  return;
}

// ===== Sprite::prevFrame  @0x000e29f4  (10 bytes)
/* Sprite::prevFrame() */

void __thiscall Sprite::prevFrame(Sprite *this)

{
  setFrame(this,*(int *)(this + 0x38) + -1);
  return;
}

