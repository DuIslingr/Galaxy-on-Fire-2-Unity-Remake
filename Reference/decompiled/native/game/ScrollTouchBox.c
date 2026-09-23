// Class: ScrollTouchBox
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ScrollTouchBox::ScrollTouchBox  @0x0015e07c  (58 bytes)
/* ScrollTouchBox::ScrollTouchBox(int, int, int, int) */

void __thiscall
ScrollTouchBox::ScrollTouchBox(ScrollTouchBox *this,int param_1,int param_2,int param_3,int param_4)

{
  *(int *)(this + 4) = param_1;
  *(int *)(this + 8) = param_2;
  *(int *)(this + 0xc) = param_3;
  *(int *)(this + 0x10) = param_4;
  *(int *)(this + 0x14) = param_3;
  *(undefined4 *)this = 0;
  this[0x30] = (ScrollTouchBox)0x0;
  *(undefined4 *)(this + 0x34) = 0;
  this[0x38] = (ScrollTouchBox)0x0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x3c) = Globals::font;
  return;
}

// ===== ScrollTouchBox::~ScrollTouchBox  @0x0015e0bc  (40 bytes)
/* ScrollTouchBox::~ScrollTouchBox() */

ScrollTouchBox * __thiscall ScrollTouchBox::~ScrollTouchBox(ScrollTouchBox *this)

{
  void *pvVar1;
  
  if (*(Array **)this != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)this);
    pvVar1 = *(void **)this;
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)this = 0;
  }
  return this;
}

// ===== ScrollTouchBox::setText  @0x0015e0e4  (306 bytes)
/* ScrollTouchBox::setText(AbyssEngine::String, int) */

void __thiscall ScrollTouchBox::setText(ScrollTouchBox *this,String *param_2,uint param_3)

{
  int iVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  String *this_00;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  
  if (*(Array **)this != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)this);
    pvVar5 = *(void **)this;
    if (pvVar5 != (void *)0x0) {
      if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar5 + 4));
      }
      operator_delete(pvVar5);
    }
    *(undefined4 *)this = 0;
  }
  *(uint *)(this + 0x3c) = param_3;
  pAVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar2 + 4) = puVar3;
  *puVar3 = 0;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *(undefined4 *)pAVar2 = 0;
  *(Array **)this = pAVar2;
  Globals::getLineArray(Globals::globals,param_3,param_2,*(int *)(this + 0x14),pAVar2);
  iVar1 = Globals::layout;
  pAVar2 = *(Array **)this;
  iVar4 = *(int *)(Globals::layout + 4) * *(int *)pAVar2;
  *(int *)(this + 0x18) = iVar4;
  if (iVar4 - *(int *)(this + 0x10) != 0 && *(int *)(this + 0x10) <= iVar4) {
    *(int *)(this + 0xc) = *(int *)(this + 0x14) - *(int *)(iVar1 + 0x48);
    if (pAVar2 != (Array *)0x0) {
      ArrayReleaseClasses<AbyssEngine::String*>(pAVar2);
      pvVar5 = *(void **)this;
      if (pvVar5 != (void *)0x0) {
        if (*(void **)((int)pvVar5 + 4) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar5 + 4));
        }
        operator_delete(pvVar5);
      }
      *(undefined4 *)this = 0;
    }
    pAVar2 = operator_new(0xc);
    puVar3 = operator_new__(4);
    *(undefined4 **)(pAVar2 + 4) = puVar3;
    *(undefined4 *)(pAVar2 + 8) = 1;
    *puVar3 = 0;
    *(undefined4 *)pAVar2 = 0;
    *(Array **)this = pAVar2;
    Globals::getLineArray(Globals::globals,param_3,param_2,*(int *)(this + 0xc),pAVar2);
    this_00 = operator_new(8);
    AbyssEngine::String::String(this_00,"\n",false);
    piVar6 = *(int **)this;
    piVar6[2] = *piVar6 + 1;
    pvVar5 = realloc((void *)piVar6[1],(*piVar6 + 1) * 4);
    piVar6[1] = (int)pvVar5;
    *(String **)((int)pvVar5 + *piVar6 * 4) = this_00;
    *piVar6 = piVar6[2];
    *(int *)(this + 0x18) = *(int *)(Globals::layout + 4) * **(int **)this;
  }
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x2d) = 0;
  *(undefined4 *)(this + 0x29) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  return;
}

// ===== ScrollTouchBox::setText  @0x0015e23c  (72 bytes)
/* ScrollTouchBox::setText(AbyssEngine::String) */

void __thiscall ScrollTouchBox::setText(ScrollTouchBox *this,String *param_2)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_1c,param_2,false);
  setText(this,aSStack_1c,Globals::font);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ScrollTouchBox::setPosition  @0x0015e2a0  (6 bytes)
/* ScrollTouchBox::setPosition(int, int) */

void __thiscall ScrollTouchBox::setPosition(ScrollTouchBox *this,int param_1,int param_2)

{
  *(int *)(this + 4) = param_1;
  *(int *)(this + 8) = param_2;
  return;
}

// ===== ScrollTouchBox::setYPosition  @0x0015e2a6  (4 bytes)
/* ScrollTouchBox::setYPosition(int) */

void __thiscall ScrollTouchBox::setYPosition(ScrollTouchBox *this,int param_1)

{
  *(int *)(this + 8) = param_1;
  return;
}

// ===== ScrollTouchBox::draw  @0x0015e2ac  (410 bytes)
/* ScrollTouchBox::draw() */

void __thiscall ScrollTouchBox::draw(ScrollTouchBox *this)

{
  PaintCanvas *this_00;
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  String *pSVar8;
  uint uVar9;
  int iVar10;
  
  iVar2 = GameText::getLanguage();
  if ((iVar2 - 10U & 0xffff) < 6) {
    uVar3 = 0x33U >> (iVar2 - 10U & 0x3f) & 1;
  }
  else {
    uVar3 = 0;
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  if ((*(uint **)this != (uint *)0x0) && (uVar4 = **(uint **)this, uVar4 != 0)) {
    uVar9 = 0;
    do {
      iVar2 = 0;
      if (((uVar9 == uVar4 - 1 & uVar3) == 1) && (iVar2 = -4, Globals::retinaDisplay != '\0')) {
        iVar2 = -8;
      }
      iVar6 = *(int *)(this + 8);
      iVar10 = *(int *)(Globals::layout + 4) * uVar9 + iVar6 + *(int *)(this + 0x34);
      if ((uVar4 == 1) ||
         ((iVar6 <= iVar10 &&
          (iVar7 = *(int *)(this + 0x10),
          iVar5 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,*(uint *)(this + 0x3c)),
          iVar10 + iVar2 <= (iVar7 + iVar6) - iVar5)))) {
        sVar1 = GameText::getLanguage();
        this_00 = Globals::Canvas;
        if (sVar1 == 9) {
          AbyssEngine::Engine::enableReverseFlag = 0;
          iVar6 = *(int *)(this + 4);
          uVar4 = *(uint *)(this + 0x3c);
          pSVar8 = *(String **)(*(int *)(*(int *)this + 4) + uVar9 * 4);
          iVar5 = *(int *)(this + 0xc);
          if (this[0x38] == (ScrollTouchBox)0x0) {
            iVar2 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,uVar4,pSVar8);
            iVar2 = (iVar6 + iVar5) - iVar2;
          }
          else {
            iVar2 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,uVar4,pSVar8);
            iVar2 = (iVar6 + (iVar5 >> 1)) - (iVar2 >> 1);
          }
        }
        else {
          iVar2 = *(int *)(this + 4);
          uVar4 = *(uint *)(this + 0x3c);
          pSVar8 = *(String **)(*(int *)(*(int *)this + 4) + uVar9 * 4);
          if (this[0x38] != (ScrollTouchBox)0x0) {
            iVar6 = *(int *)(this + 0xc);
            iVar5 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,uVar4,pSVar8);
            iVar2 = (iVar2 + (iVar6 >> 1)) - (iVar5 >> 1);
          }
        }
        AbyssEngine::PaintCanvas::DrawString(this_00,uVar4,pSVar8,iVar2,iVar10,false);
      }
      uVar9 = uVar9 + 1;
      uVar4 = **(uint **)this;
    } while (uVar9 < uVar4);
  }
  AbyssEngine::Engine::enableReverseFlag = 1;
  return;
}

// ===== ScrollTouchBox::setTextCentered  @0x0015e468  (6 bytes)
/* ScrollTouchBox::setTextCentered(bool) */

void __thiscall ScrollTouchBox::setTextCentered(ScrollTouchBox *this,bool param_1)

{
  this[0x38] = (ScrollTouchBox)param_1;
  return;
}

// ===== ScrollTouchBox::getRelativeScrollStartPos  @0x0015e470  (42 bytes)
/* ScrollTouchBox::getRelativeScrollStartPos() */

float __thiscall ScrollTouchBox::getRelativeScrollStartPos(ScrollTouchBox *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (*(int *)(this + 0x34) < 1) {
    fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0x34),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x18),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = -fVar2 / fVar1;
  }
  else {
    fVar1 = 0.0;
  }
  return fVar1;
}

// ===== ScrollTouchBox::getRelativeScrollHeight  @0x0015e4a0  (76 bytes)
/* ScrollTouchBox::getRelativeScrollHeight() */

float __thiscall ScrollTouchBox::getRelativeScrollHeight(ScrollTouchBox *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  iVar2 = *(int *)(this + 0x10);
  iVar3 = *(int *)(this + 0x18);
  if (iVar3 < iVar2) {
    return 0.0;
  }
  iVar1 = *(int *)(this + 0x34);
  if (iVar1 < 1) {
    if (iVar2 - iVar3 <= iVar1) {
      fVar4 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
      goto LAB_0015e4de;
    }
    iVar2 = iVar1 + iVar3;
  }
  else {
    iVar2 = iVar2 - iVar1;
  }
  fVar4 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
LAB_0015e4de:
  fVar5 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
  return fVar5 / fVar4;
}

// ===== ScrollTouchBox::update  @0x0015e4f0  (138 bytes)
/* ScrollTouchBox::update(int) */

void ScrollTouchBox::update(int param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x10) <= *(int *)(param_1 + 0x18)) {
    if (*(char *)(param_1 + 0x30) == '\0') {
      fVar5 = *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x24);
      fVar6 = -(*(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x24));
      if (0.0 < fVar5) {
        fVar6 = fVar5;
      }
      *(float *)(param_1 + 0x24) = fVar5;
      uVar1 = in_fpscr & 0xfffffff | (uint)(fVar6 < 1.5) << 0x1f | (uint)(fVar6 == 1.5) << 0x1e;
      in_fpscr = uVar1 | (uint)NAN(fVar6) << 0x1c;
      bVar2 = (byte)(uVar1 >> 0x18);
      if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x34),
                                           (byte)(in_fpscr >> 0x16) & 3);
        *(int *)(param_1 + 0x34) = (int)(fVar5 + fVar6);
      }
    }
    iVar4 = *(int *)(param_1 + 0x34);
    if (iVar4 < 1) {
      iVar3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x10);
      if (-iVar3 <= iVar4) {
        return;
      }
      iVar4 = iVar3 + iVar4;
    }
    fVar6 = (float)VectorSignedToFloat(-iVar4,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(param_1 + 0x24) = fVar6 * 0.5;
    *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
  }
  return;
}

// ===== ScrollTouchBox::touchIsInside  @0x0015e57a  (48 bytes)
/* ScrollTouchBox::touchIsInside(int, int) */

bool __thiscall ScrollTouchBox::touchIsInside(ScrollTouchBox *this,int param_1,int param_2)

{
  int iVar1;
  int in_r12;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  iVar2 = *(int *)(this + 4);
  bVar4 = SBORROW4(iVar2,param_1);
  iVar1 = iVar2 - param_1;
  bVar3 = iVar2 == param_1;
  if (iVar2 <= param_1) {
    in_r12 = *(int *)(this + 8);
    bVar4 = SBORROW4(in_r12,param_2);
    iVar1 = in_r12 - param_2;
    bVar3 = in_r12 == param_2;
  }
  if (bVar3 || iVar1 < 0 != bVar4) {
    if (param_1 < iVar2 + *(int *)(this + 0xc)) {
      return param_2 < *(int *)(this + 0x10) + in_r12;
    }
    return false;
  }
  return false;
}

// ===== ScrollTouchBox::OnTouchBegin  @0x0015e5aa  (52 bytes)
/* ScrollTouchBox::OnTouchBegin(int, int) */

void __thiscall ScrollTouchBox::OnTouchBegin(ScrollTouchBox *this,int param_1,int param_2)

{
  int iVar1;
  int in_r12;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  iVar2 = *(int *)(this + 4);
  bVar4 = SBORROW4(iVar2,param_1);
  iVar1 = iVar2 - param_1;
  bVar3 = iVar2 == param_1;
  if (iVar2 <= param_1) {
    in_r12 = *(int *)(this + 8);
    bVar4 = SBORROW4(in_r12,param_2);
    iVar1 = in_r12 - param_2;
    bVar3 = in_r12 == param_2;
  }
  if ((bVar3 || iVar1 < 0 != bVar4) && (param_1 < *(int *)(this + 0xc) + iVar2)) {
    if (*(int *)(this + 0x10) + in_r12 <= param_2) {
      return;
    }
    *(int *)(this + 0x28) = param_2;
    *(int *)(this + 0x2c) = param_2;
    *(undefined4 *)(this + 0x1c) = 0;
    this[0x30] = (ScrollTouchBox)0x1;
  }
  return;
}

// ===== ScrollTouchBox::OnTouchMove  @0x0015e5de  (36 bytes)
/* ScrollTouchBox::OnTouchMove(int, int) */

void __thiscall ScrollTouchBox::OnTouchMove(ScrollTouchBox *this,int param_1,int param_2)

{
  int iVar1;
  
  if ((this[0x30] != (ScrollTouchBox)0x0) && (*(int *)(this + 0x10) < *(int *)(this + 0x18))) {
    iVar1 = *(int *)(this + 0x2c);
    *(int *)(this + 0x2c) = param_2;
    *(int *)(this + 0x1c) = param_2 - iVar1;
    *(undefined4 *)(this + 0x20) = 0x3f800000;
    *(int *)(this + 0x34) = (param_2 - iVar1) + *(int *)(this + 0x34);
  }
  return;
}

// ===== ScrollTouchBox::OnTouchEnd  @0x0015e604  (64 bytes)
/* ScrollTouchBox::OnTouchEnd(int, int) */

void ScrollTouchBox::OnTouchEnd(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (*(char *)(param_1 + 0x30) != '\0') {
    iVar1 = *(int *)(param_1 + 0x1c);
    uVar4 = VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    iVar2 = iVar1;
    if (iVar1 < 0) {
      iVar2 = -iVar1;
    }
    uVar3 = 0;
    if (3 < iVar2) {
      uVar3 = uVar4;
    }
    *(undefined4 *)(param_1 + 0x24) = uVar3;
    *(undefined4 *)(param_1 + 0x20) = 0x3f666666;
    *(undefined1 *)(param_1 + 0x30) = 0;
    *(int *)(param_1 + 0x34) = iVar1 + *(int *)(param_1 + 0x34);
  }
  return;
}

