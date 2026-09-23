// Class: ScrollTouchWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ScrollTouchWindow::ScrollTouchWindow  @0x001a2ef0  (124 bytes)
/* ScrollTouchWindow::ScrollTouchWindow(int, int, int, int, bool) */

ScrollTouchWindow * __thiscall
ScrollTouchWindow::ScrollTouchWindow
          (ScrollTouchWindow *this,int param_1,int param_2,int param_3,int param_4,bool param_5)

{
  ScrollTouchBox *this_00;
  int iVar1;
  int iVar2;
  undefined3 in_stack_00000005;
  
  AbyssEngine::String::String((String *)(this + 4));
  *(int *)(this + 0x10) = param_1;
  *(int *)(this + 0x14) = param_2;
  *(int *)(this + 0x18) = param_3;
  *(int *)(this + 0x1c) = param_4;
  this_00 = operator_new(0x40);
  iVar1 = *(int *)(Globals::layout + 0x4c);
  if (_param_5 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(Globals::layout + 8);
    param_2 = iVar2 + param_2;
  }
  ScrollTouchBox::ScrollTouchBox
            (this_00,iVar1 + param_1,param_2 + iVar1,param_3 + iVar1 * -2,
             (param_4 - iVar2) + iVar1 * -2);
  *(ScrollTouchBox **)this = this_00;
  this[0xc] = (ScrollTouchWindow)0x0;
  this[0xd] = (ScrollTouchWindow)param_5;
  return this;
}

// ===== ScrollTouchWindow::ScrollTouchWindow  @0x001a2f88  (102 bytes)
/* ScrollTouchWindow::ScrollTouchWindow(int, int, int, int) */

ScrollTouchWindow * __thiscall
ScrollTouchWindow::ScrollTouchWindow
          (ScrollTouchWindow *this,int param_1,int param_2,int param_3,int param_4)

{
  ScrollTouchBox *this_00;
  int iVar1;
  
  AbyssEngine::String::String((String *)(this + 4));
  *(int *)(this + 0x10) = param_1;
  *(int *)(this + 0x14) = param_2;
  *(int *)(this + 0x18) = param_3;
  *(int *)(this + 0x1c) = param_4;
  this_00 = operator_new(0x40);
  iVar1 = *(int *)(Globals::layout + 0x4c);
  ScrollTouchBox::ScrollTouchBox
            (this_00,iVar1 + param_1,*(int *)(Globals::layout + 8) + iVar1 + param_2,
             param_3 + iVar1 * -2,(param_4 - *(int *)(Globals::layout + 8)) + iVar1 * -2);
  *(ScrollTouchBox **)this = this_00;
  *(undefined2 *)(this + 0xc) = 0x100;
  return this;
}

// ===== ScrollTouchWindow::~ScrollTouchWindow  @0x001a300c  (34 bytes)
/* ScrollTouchWindow::~ScrollTouchWindow() */

ScrollTouchWindow * __thiscall ScrollTouchWindow::~ScrollTouchWindow(ScrollTouchWindow *this)

{
  void *pvVar1;
  
  if (*(ScrollTouchBox **)this != (ScrollTouchBox *)0x0) {
    pvVar1 = (void *)ScrollTouchBox::~ScrollTouchBox(*(ScrollTouchBox **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  AbyssEngine::String::~String((String *)(this + 4));
  return this;
}

// ===== ScrollTouchWindow::setText  @0x001a3030  (82 bytes)
/* ScrollTouchWindow::setText(AbyssEngine::String, AbyssEngine::String) */

void __thiscall ScrollTouchWindow::setText(ScrollTouchWindow *this,String *param_2,String *param_3)

{
  ScrollTouchBox *pSVar1;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pSVar1 = *(ScrollTouchBox **)this;
  AbyssEngine::String::String(aSStack_24,param_3,false);
  ScrollTouchBox::setText(pSVar1,aSStack_24);
  AbyssEngine::String::~String(aSStack_24);
  AbyssEngine::String::operator=((String *)(this + 4),param_2);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ScrollTouchWindow::setText  @0x001a3098  (86 bytes)
/* ScrollTouchWindow::setText(AbyssEngine::String, AbyssEngine::String, int) */

void __thiscall
ScrollTouchWindow::setText
          (ScrollTouchWindow *this,String *param_2,String *param_3,undefined4 param_4)

{
  ScrollTouchBox *pSVar1;
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pSVar1 = *(ScrollTouchBox **)this;
  AbyssEngine::String::String(aSStack_28,param_3,false);
  ScrollTouchBox::setText(pSVar1,aSStack_28,param_4);
  AbyssEngine::String::~String(aSStack_28);
  AbyssEngine::String::operator=((String *)(this + 4),param_2);
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ScrollTouchWindow::setYPosition  @0x001a3104  (8 bytes)
/* ScrollTouchWindow::setYPosition(int) */

void ScrollTouchWindow::setYPosition(int param_1)

{
  int in_r1;
  
  ScrollTouchBox::setYPosition(*(ScrollTouchBox **)param_1,in_r1);
  return;
}

// ===== ScrollTouchWindow::draw  @0x001a310c  (308 bytes)
/* ScrollTouchWindow::draw() */

void __thiscall ScrollTouchWindow::draw(ScrollTouchWindow *this)

{
  Layout *pLVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  String aSStack_3c [8];
  int local_34;
  
  local_34 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  pLVar1 = Globals::layout;
  if (this[0xd] == (ScrollTouchWindow)0x0) {
    iVar4 = *(int *)(this + 0x1c) + *(int *)(Globals::layout + 0x2c) * -2;
  }
  else {
    AbyssEngine::String::String(aSStack_3c,this + 4,false);
    Layout::drawWindow(pLVar1,aSStack_3c,*(undefined4 *)(this + 0x10),*(undefined4 *)(this + 0x14),
                       *(undefined4 *)(this + 0x18),*(undefined4 *)(this + 0x1c),1);
    AbyssEngine::String::~String(aSStack_3c);
    iVar4 = *(int *)(this + 0x1c) + *(int *)(Globals::layout + 0x2c) * -2;
    if (this[0xd] != (ScrollTouchWindow)0x0) {
      iVar6 = *(int *)(Globals::layout + 8);
      goto LAB_001a3196;
    }
  }
  iVar6 = 0;
LAB_001a3196:
  ScrollTouchBox::draw(*(ScrollTouchBox **)this);
  fVar7 = (float)VectorSignedToFloat(iVar4 - iVar6,(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)ScrollTouchBox::getRelativeScrollStartPos(*(ScrollTouchBox **)this);
  fVar3 = (float)ScrollTouchBox::getRelativeScrollHeight(*(ScrollTouchBox **)this);
  if ((0 < (int)(fVar7 * fVar2)) || (0 < (int)(fVar7 * fVar3))) {
    if (this[0xd] == (ScrollTouchWindow)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(Globals::layout + 8);
    }
    Layout::drawScrollBar
              (Globals::layout,
               ((*(int *)(this + 0x10) + *(int *)(this + 0x18)) - *(int *)(Globals::layout + 0x48))
               - *(int *)(Globals::layout + 0x2c),
               iVar5 + *(int *)(this + 0x14) + *(int *)(Globals::layout + 0x2c),iVar4 - iVar6,
               (int)(fVar7 * fVar2),(int)(fVar7 * fVar3));
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ScrollTouchWindow::setTextCentered  @0x001a3270  (8 bytes)
/* ScrollTouchWindow::setTextCentered(bool) */

void ScrollTouchWindow::setTextCentered(bool param_1)

{
  bool in_r1;
  
  ScrollTouchBox::setTextCentered(*(ScrollTouchBox **)(uint)param_1,in_r1);
  return;
}

// ===== ScrollTouchWindow::drawTextBG  @0x001a3278  (150 bytes)
/* ScrollTouchWindow::drawTextBG() */

void __thiscall ScrollTouchWindow::drawTextBG(ScrollTouchWindow *this)

{
  Layout *pLVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  String aSStack_30 [8];
  int local_28;
  
  pLVar1 = Globals::layout;
  local_28 = __stack_chk_guard;
  uVar8 = *(undefined4 *)(this + 0x10);
  iVar10 = *(int *)(this + 0x14);
  iVar9 = *(int *)(this + 0x18);
  iVar7 = *(int *)(Globals::layout + 0x2c);
  fVar2 = (float)ScrollTouchBox::getRelativeScrollHeight(*(ScrollTouchBox **)this);
  iVar3 = *(int *)(Globals::layout + 0x2c);
  iVar5 = iVar3;
  if (0.0 < fVar2) {
    iVar5 = *(int *)(Globals::layout + 0x48) + iVar3 * 2;
  }
  iVar6 = *(int *)(this + 0x1c);
  uVar4 = AbyssEngine::String::String(aSStack_30,"",false);
  Layout::drawBox(pLVar1,5,uVar8,iVar10 + iVar7,iVar9 - iVar5,iVar6 + iVar3 * -2,uVar4);
  AbyssEngine::String::~String(aSStack_30);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ScrollTouchWindow::update  @0x001a332c  (8 bytes)
/* ScrollTouchWindow::update(int) */

void ScrollTouchWindow::update(int param_1)

{
  ScrollTouchBox::update(*(int *)param_1);
  return;
}

// ===== ScrollTouchWindow::OnTouchBegin  @0x001a3332  (8 bytes)
/* ScrollTouchWindow::OnTouchBegin(int, int) */

void ScrollTouchWindow::OnTouchBegin(int param_1,int param_2)

{
  int in_r2;
  
  ScrollTouchBox::OnTouchBegin(*(ScrollTouchBox **)param_1,param_2,in_r2);
  return;
}

// ===== ScrollTouchWindow::OnTouchMove  @0x001a3338  (18 bytes)
/* ScrollTouchWindow::OnTouchMove(int, int) */

void __thiscall ScrollTouchWindow::OnTouchMove(ScrollTouchWindow *this,int param_1,int param_2)

{
  ScrollTouchBox::OnTouchMove(*(ScrollTouchBox **)this,param_1,param_2);
  this[0xc] = (ScrollTouchWindow)0x1;
  return;
}

// ===== ScrollTouchWindow::OnTouchEnd  @0x001a334a  (18 bytes)
/* ScrollTouchWindow::OnTouchEnd(int, int) */

void ScrollTouchWindow::OnTouchEnd(int param_1,int param_2)

{
  ScrollTouchBox::OnTouchEnd(*(int *)param_1,param_2);
  *(undefined1 *)(param_1 + 0xc) = 0;
  return;
}

