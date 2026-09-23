// Class: TouchSlider
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== TouchSlider::TouchSlider  @0x000aea04  (212 bytes)
/* TouchSlider::TouchSlider(int, int, int, float) */

TouchSlider * __thiscall
TouchSlider::TouchSlider(TouchSlider *this,int param_1,int param_2,int param_3,float param_4)

{
  undefined4 uVar1;
  int iVar2;
  ushort uVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  undefined4 in_stack_00000000;
  
  *(int *)(this + 0x10) = param_1;
  *(undefined4 *)(this + 0x24) = in_stack_00000000;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x51a,(uint *)(this + 0x30));
  uVar3 = 0x51b;
  if (param_1 == 1) {
    uVar3 = 0x51c;
  }
  if (param_1 == 0) {
    uVar3 = 0x519;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar3,(uint *)(this + 0x2c));
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x30));
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x30));
  *(undefined4 *)(this + 0x18) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2c));
  *(undefined4 *)(this + 0x1c) = uVar1;
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x2c));
  *(int *)(this + 0x20) = iVar2;
  this[0x34] = (TouchSlider)0x0;
  this[0x35] = (TouchSlider)0x0;
  *(int *)this = param_2;
  *(int *)(this + 4) = param_3;
  fVar4 = (float)VectorSignedToFloat(*(int *)(this + 0x1c) - *(int *)(this + 0x14),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar5 = (float)VectorSignedToFloat(param_2 + *(int *)(this + 0x14) / 2,
                                     (byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 8) = (int)(fVar5 + *(float *)(this + 0x24) * fVar4);
  *(int *)(this + 0xc) = param_3 + iVar2 / 2;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(Globals::layout + 0x7c);
  return this;
}

// ===== TouchSlider::setPosition  @0x000aeae0  (72 bytes)
/* TouchSlider::setPosition(int, int) */

void __thiscall TouchSlider::setPosition(TouchSlider *this,int param_1,int param_2)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  *(int *)this = param_1;
  *(int *)(this + 4) = param_2;
  fVar1 = (float)VectorSignedToFloat(*(int *)(this + 0x1c) - *(int *)(this + 0x14),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(param_1 + *(int *)(this + 0x14) / 2,
                                     (byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 8) = (int)(fVar2 + *(float *)(this + 0x24) * fVar1);
  *(int *)(this + 0xc) = param_2 + *(int *)(this + 0x20) / 2;
  return;
}

// ===== TouchSlider::~TouchSlider  @0x000aeb28  (2 bytes)
/* TouchSlider::~TouchSlider() */

TouchSlider * __thiscall TouchSlider::~TouchSlider(TouchSlider *this)

{
  return this;
}

// ===== TouchSlider::getWidth  @0x000aeb2a  (4 bytes)
/* TouchSlider::getWidth() */

undefined4 __thiscall TouchSlider::getWidth(TouchSlider *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== TouchSlider::draw  @0x000aeb30  (72 bytes)
/* TouchSlider::draw() */

void __thiscall TouchSlider::draw(TouchSlider *this)

{
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x2c),*(int *)this,*(int *)(this + 4));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x30),*(int *)(this + 8),*(int *)(this + 0xc),'\x11',
             'D');
  return;
}

// ===== TouchSlider::getValue  @0x000aeb7c  (46 bytes)
/* TouchSlider::getValue() */

float __thiscall TouchSlider::getValue(TouchSlider *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar1 = (float)VectorSignedToFloat(*(int *)(this + 0x1c) - *(int *)(this + 0x14),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat((*(int *)(this + 8) - *(int *)(this + 0x14) / 2) - *(int *)this
                                     ,(byte)(in_fpscr >> 0x16) & 3);
  return fVar2 / fVar1;
}

// ===== TouchSlider::setValue  @0x000aebaa  (56 bytes)
/* TouchSlider::setValue(float) */

void __thiscall TouchSlider::setValue(TouchSlider *this,float param_1)

{
  float in_r1;
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar1 = (float)VectorSignedToFloat(*(int *)(this + 0x1c) - *(int *)(this + 0x14),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(*(int *)this + *(int *)(this + 0x14) / 2,
                                     (byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 8) = (int)(fVar2 + fVar1 * in_r1);
  return;
}

// ===== TouchSlider::setFixedScale  @0x000aebe2  (4 bytes)
/* TouchSlider::setFixedScale(int) */

void __thiscall TouchSlider::setFixedScale(TouchSlider *this,int param_1)

{
  *(int *)(this + 0x28) = param_1;
  return;
}

// ===== TouchSlider::setHalfTransparent  @0x000aebe6  (6 bytes)
/* TouchSlider::setHalfTransparent(bool) */

void __thiscall TouchSlider::setHalfTransparent(TouchSlider *this,bool param_1)

{
  this[0x35] = (TouchSlider)param_1;
  return;
}

// ===== TouchSlider::OnTouchBegin  @0x000aebec  (28 bytes)
/* TouchSlider::OnTouchBegin(int, int) */

undefined4 __thiscall TouchSlider::OnTouchBegin(TouchSlider *this,int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (this[0x35] != (TouchSlider)0x0) {
    return 0;
  }
  uVar1 = touchedInside(this,param_1,param_2);
  this[0x34] = SUB41(uVar1,0);
  return uVar1;
}

// ===== TouchSlider::touchedInside  @0x000aec08  (76 bytes)
/* TouchSlider::touchedInside(int, int) */

bool __thiscall TouchSlider::touchedInside(TouchSlider *this,int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x38);
  if (((*(int *)(this + 8) - (*(int *)(this + 0x14) >> 1)) - iVar1 <= param_1) &&
     (param_1 < (*(int *)(this + 0x14) >> 1) + *(int *)(this + 8) + iVar1)) {
    if (param_2 < (*(int *)(this + 0xc) - iVar1) - (*(int *)(this + 0x18) >> 1)) {
      return false;
    }
    return param_2 <= (*(int *)(this + 0x18) >> 1) + *(int *)(this + 0xc) + iVar1;
  }
  return false;
}

// ===== TouchSlider::OnTouchMove  @0x000aec54  (70 bytes)
/* TouchSlider::OnTouchMove(int, int) */

bool TouchSlider::OnTouchMove(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x35) != '\0') {
    return false;
  }
  if (*(char *)(param_1 + 0x34) != '\0') {
    iVar1 = *(int *)(param_1 + 0x14) / 2;
    iVar2 = *(int *)param_1 + iVar1;
    iVar1 = (*(int *)param_1 + *(int *)(param_1 + 0x1c)) - iVar1;
    if (param_2 < iVar1) {
      iVar1 = param_2;
    }
    if (iVar1 <= iVar2) {
      iVar1 = iVar2;
    }
    *(int *)(param_1 + 8) = iVar1;
  }
  return *(char *)(param_1 + 0x34) != '\0';
}

// ===== TouchSlider::OnTouchEnd  @0x000aec9c  (186 bytes)
/* TouchSlider::OnTouchEnd(int, int) */

undefined4 TouchSlider::OnTouchEnd(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  if (*(char *)(param_1 + 0x35) == '\0') {
    if (*(char *)(param_1 + 0x34) == '\0') {
      uVar3 = 0;
      *(undefined1 *)(param_1 + 0x34) = 0;
    }
    else {
      iVar5 = *(int *)(param_1 + 0x28);
      if (0 < iVar5) {
        fVar8 = (float)VectorSignedToFloat(iVar5 + 1,(byte)(in_fpscr >> 0x16) & 3);
        iVar1 = *(int *)(param_1 + 0x14) / 2;
        fVar6 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x14),
                                           (byte)(in_fpscr >> 0x16) & 3);
        iVar4 = -1;
        fVar9 = (float)VectorSignedToFloat((*(int *)(param_1 + 8) - iVar1) - *(int *)param_1,
                                           (byte)(in_fpscr >> 0x16) & 3);
        fVar9 = fVar9 / fVar6;
        fVar7 = 0.0;
        do {
          fVar10 = (1.0 / fVar8) * 0.5 + fVar7;
          in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar9 == fVar10) << 0x1e |
                     (uint)(fVar10 <= fVar9) << 0x1d;
          bVar2 = (byte)(in_fpscr >> 0x18);
          fVar10 = fVar7;
          if (!(bool)(bVar2 >> 5 & 1) || (bool)(bVar2 >> 6)) break;
          fVar7 = 1.0 / fVar8 + fVar7;
          iVar4 = iVar4 + 1;
          fVar10 = fVar9;
        } while (iVar4 <= iVar5);
        fVar7 = (float)VectorSignedToFloat(*(int *)param_1 + iVar1,(byte)(in_fpscr >> 0x16) & 3);
        *(int *)(param_1 + 8) = (int)(fVar7 + fVar10 * fVar6);
      }
      *(undefined1 *)(param_1 + 0x34) = 0;
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

