// Class: MarqueeImage
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MarqueeImage::MarqueeImage  @0x0018bec4  (72 bytes)
/* MarqueeImage::MarqueeImage(unsigned short, int, int, int, float) */

MarqueeImage * __thiscall
MarqueeImage::MarqueeImage
          (MarqueeImage *this,ushort param_1,int param_2,int param_3,int param_4,float param_5)

{
  undefined4 uVar1;
  undefined4 in_stack_00000004;
  
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,param_1,(uint *)this);
  *(int *)(this + 0x14) = param_2;
  *(int *)(this + 0xc) = param_3;
  *(int *)(this + 0x10) = param_4;
  *(undefined4 *)(this + 0x1c) = in_stack_00000004;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)this);
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)this);
  *(undefined4 *)(this + 8) = uVar1;
  *(undefined4 *)(this + 0x18) = 0;
  return this;
}

// ===== MarqueeImage::~MarqueeImage  @0x0018bf10  (2 bytes)
/* MarqueeImage::~MarqueeImage() */

MarqueeImage * __thiscall MarqueeImage::~MarqueeImage(MarqueeImage *this)

{
  return this;
}

// ===== MarqueeImage::setPosition  @0x0018bf12  (6 bytes)
/* MarqueeImage::setPosition(int, int) */

void __thiscall MarqueeImage::setPosition(MarqueeImage *this,int param_1,int param_2)

{
  *(int *)(this + 0xc) = param_1;
  *(int *)(this + 0x10) = param_2;
  return;
}

// ===== MarqueeImage::setSpeed  @0x0018bf18  (4 bytes)
/* MarqueeImage::setSpeed(float) */

void __thiscall MarqueeImage::setSpeed(MarqueeImage *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0x1c) = in_r1;
  return;
}

// ===== MarqueeImage::update  @0x0018bf1c  (88 bytes)
/* MarqueeImage::update(int) */

void __thiscall MarqueeImage::update(MarqueeImage *this,int param_1)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (fVar1 / 1000.0) * *(float *)(this + 0x1c);
  fVar1 = *(float *)(this + 0x18) + fVar3;
  *(float *)(this + 0x18) = fVar1;
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 4),(byte)(in_fpscr >> 0x16) & 3);
  if (fVar2 < fVar1) {
    fVar1 = fVar3 * 0.5 + (fVar1 - fVar2);
    *(float *)(this + 0x18) = fVar1;
  }
  *(int *)(this + 0x20) = (int)(fVar2 - fVar1);
  return;
}

// ===== MarqueeImage::draw  @0x0018bf78  (150 bytes)
/* MarqueeImage::draw(int, int) */

void MarqueeImage::draw(int param_1,int param_2)

{
  undefined4 in_r2;
  int iVar1;
  float in_s0;
  
  *(int *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = in_r2;
  iVar1 = *(int *)(param_1 + 0x20);
  if (-1 < iVar1) {
    if (*(int *)(param_1 + 0x14) < iVar1) {
      iVar1 = *(int *)(param_1 + 0x14);
    }
    in_s0 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                             (Globals::Canvas,*(uint *)param_1,(int)*(float *)(param_1 + 0x18),0,
                              iVar1,*(int *)(param_1 + 8),(float)(int)*(float *)(param_1 + 0x18),0,0
                              ,0,param_2);
    iVar1 = *(int *)(param_1 + 0x20);
  }
  if (iVar1 <= *(int *)(param_1 + 0x14)) {
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)param_1,0,0,*(int *)(param_1 + 0x14) - iVar1,
               *(int *)(param_1 + 8),in_s0,0,0,0,iVar1 + param_2);
  }
  return;
}

// ===== MarqueeImage::draw  @0x0018c018  (10 bytes)
/* MarqueeImage::draw() */

void __thiscall MarqueeImage::draw(MarqueeImage *this)

{
  draw((int)this,*(int *)(this + 0xc));
  return;
}

