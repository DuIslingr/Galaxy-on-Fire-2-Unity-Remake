// Class: ChoiceWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ChoiceWindow::ChoiceWindow  @0x00170014  (108 bytes)
/* ChoiceWindow::ChoiceWindow() */

ChoiceWindow * __thiscall ChoiceWindow::ChoiceWindow(ChoiceWindow *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  AbyssEngine::String::String((String *)(this + 0x20));
  AbyssEngine::String::String((String *)(this + 0x38));
  iVar4 = Globals::layout;
  iVar6 = *(int *)(Globals::layout + 0x264);
  puVar5 = (undefined4 *)(Globals::layout + 0x268);
  *(int *)(this + 8) = iVar6;
  uVar1 = *(undefined4 *)(iVar4 + 0x26c);
  uVar2 = *(undefined4 *)(iVar4 + 0x270);
  uVar3 = *(undefined4 *)(iVar4 + 0x274);
  *(undefined4 *)(this + 0x40) = *puVar5;
  *(undefined4 *)(this + 0x44) = uVar1;
  *(undefined4 *)(this + 0x48) = uVar2;
  *(undefined4 *)(this + 0x4c) = uVar3;
  *(int *)this = Globals::w / 2 - iVar6 / 2;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  this[0x51] = (ChoiceWindow)0x1;
  return this;
}

// ===== ChoiceWindow::~ChoiceWindow  @0x00170098  (86 bytes)
/* ChoiceWindow::~ChoiceWindow() */

ChoiceWindow * __thiscall ChoiceWindow::~ChoiceWindow(ChoiceWindow *this)

{
  void *pvVar1;
  
  if (*(TouchButton **)(this + 0x10) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x10));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x10) = 0;
  if (*(TouchButton **)(this + 0x14) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x14));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x14) = 0;
  if (*(TouchButton **)(this + 0x18) != (TouchButton *)0x0) {
    pvVar1 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x18));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(ScrollTouchWindow **)(this + 0x1c) != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0x1c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  AbyssEngine::String::~String((String *)(this + 0x38));
  AbyssEngine::String::~String((String *)(this + 0x20));
  return this;
}

// ===== ChoiceWindow::set  @0x001700f0  (40 bytes)
/* ChoiceWindow::set(AbyssEngine::String const&) */

void __thiscall ChoiceWindow::set(ChoiceWindow *this,String *param_1)

{
  String *pSVar1;
  
  pSVar1 = (String *)GameText::getText(Globals::gameText,0x186);
  set(this,pSVar1,param_1,false);
  return;
}

// ===== ChoiceWindow::set  @0x0017011c  (84 bytes)
/* ChoiceWindow::set(AbyssEngine::String const&, AbyssEngine::String const&, bool) */

void __thiscall ChoiceWindow::set(ChoiceWindow *this,String *param_1,String *param_2,bool param_3)

{
  String *pSVar1;
  String *pSVar2;
  String *pSVar3;
  
  pSVar1 = (String *)GameText::getText(Globals::gameText,0x86);
  pSVar2 = (String *)GameText::getText(Globals::gameText,0x87);
  pSVar3 = (String *)GameText::getText(Globals::gameText,0x20c);
  set(this,param_1,param_2,param_3,pSVar1,pSVar2,pSVar3,-1,-1);
  return;
}

// ===== ChoiceWindow::set  @0x00170174  (82 bytes)
/* ChoiceWindow::set(AbyssEngine::String const&, AbyssEngine::String const&) */

void __thiscall ChoiceWindow::set(ChoiceWindow *this,String *param_1,String *param_2)

{
  String *pSVar1;
  String *pSVar2;
  String *pSVar3;
  
  pSVar1 = (String *)GameText::getText(Globals::gameText,0x186);
  pSVar2 = (String *)GameText::getText(Globals::gameText,0x86);
  pSVar3 = (String *)GameText::getText(Globals::gameText,0x87);
  set(this,pSVar1,param_1,false,pSVar2,pSVar3,param_2,-1,-1);
  return;
}

// ===== ChoiceWindow::set  @0x001701cc  (884 bytes)
/* ChoiceWindow::set(AbyssEngine::String const&, AbyssEngine::String const&, bool,
   AbyssEngine::String const&, AbyssEngine::String const&, AbyssEngine::String const&, int, int) */

void __thiscall
ChoiceWindow::set(ChoiceWindow *this,String *param_1,String *param_2,bool param_3,String *param_4,
                 String *param_5,String *param_6,int param_7,int param_8)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  String *pSVar4;
  void *pvVar5;
  Array *pAVar6;
  undefined4 *puVar7;
  uint uVar8;
  ScrollTouchWindow *this_00;
  TouchButton *pTVar9;
  int iVar10;
  uint uVar11;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float fVar12;
  float fVar13;
  String aSStack_4c [8];
  String aSStack_44 [8];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  this[0x50] = (ChoiceWindow)param_3;
  pSVar4 = (String *)GameText::getText(Globals::gameText,0x86);
  cVar3 = AbyssEngine::String::Compare(pSVar4,param_4);
  bVar1 = false;
  fVar12 = extraout_s0;
  if (cVar3 == '\0') {
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x87);
    cVar3 = AbyssEngine::String::Compare(pSVar4,param_5);
    fVar12 = extraout_s0_00;
    if (cVar3 == '\0') {
      bVar1 = true;
    }
  }
  if (param_8 == -1) {
    param_8 = *(int *)(Globals::layout + 0x264);
  }
  if (!bVar1) {
    fVar12 = (float)VectorSignedToFloat(param_8,(byte)(in_fpscr >> 0x16) & 3);
    param_8 = (int)(fVar12 * 1.2);
    fVar12 = (float)param_8;
  }
  *(int *)(this + 8) = param_8;
  *(int *)this = Globals::w / 2 - param_8 / 2;
  FModSound::play(Globals::sound,0x7e,(Vector *)0x0,(Vector *)0x0,fVar12);
  AbyssEngine::String::operator=((String *)(this + 0x20),param_1);
  if (*(ScrollTouchWindow **)(this + 0x1c) != (ScrollTouchWindow *)0x0) {
    pvVar5 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0x1c));
    operator_delete(pvVar5);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  pAVar6 = operator_new(0xc);
  puVar7 = operator_new__(4);
  *(undefined4 **)(pAVar6 + 4) = puVar7;
  *(undefined4 *)(pAVar6 + 8) = 1;
  *puVar7 = 0;
  *(undefined4 *)pAVar6 = 0;
  Globals::getLineArray
            (Globals::globals,Globals::font,param_2,
             (*(int *)(this + 8) + *(int *)(Globals::layout + 0x4c) * -2) -
             *(int *)(Globals::layout + 0x48),pAVar6);
  iVar2 = Globals::layout;
  iVar10 = *(int *)(this + 0x40);
  uVar8 = *(int *)(Globals::layout + 4) * *(int *)pAVar6 + *(int *)(Globals::layout + 8) +
          *(int *)(Globals::layout + 0x30) + (iVar10 + *(int *)(Globals::layout + 0x4c)) * 2;
  uVar11 = *(uint *)(Globals::layout + 0x278);
  if (uVar8 < *(uint *)(Globals::layout + 0x278)) {
    uVar11 = uVar8;
  }
  *(uint *)(this + 0xc) = uVar11;
  if (param_7 == -1) {
    param_7 = Globals::h / 2 - (int)uVar11 / 2;
  }
  *(int *)(this + 4) = param_7;
  this_00 = operator_new(0x20);
  ScrollTouchWindow::ScrollTouchWindow
            (this_00,*(int *)this,*(int *)(iVar2 + 8) + param_7,*(int *)(this + 8),
             (((uVar11 - *(int *)(iVar2 + 8)) + iVar10 * -2) - *(int *)(iVar2 + 0x30)) +
             *(int *)(iVar2 + 700),false);
  *(ScrollTouchWindow **)(this + 0x1c) = this_00;
  AbyssEngine::String::String(aSStack_44,param_1,false);
  AbyssEngine::String::String(aSStack_4c,param_2,false);
  ScrollTouchWindow::setText(this_00,aSStack_44,aSStack_4c);
  AbyssEngine::String::~String(aSStack_4c);
  AbyssEngine::String::~String(aSStack_44);
  ArrayReleaseClasses<AbyssEngine::String*>(pAVar6);
  if (*(void **)(pAVar6 + 4) != (void *)0x0) {
    operator_delete__(*(void **)(pAVar6 + 4));
  }
  operator_delete(pAVar6);
  if (*(TouchButton **)(this + 0x10) != (TouchButton *)0x0) {
    pvVar5 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x10));
    operator_delete(pvVar5);
  }
  *(undefined4 *)(this + 0x10) = 0;
  if (*(TouchButton **)(this + 0x14) != (TouchButton *)0x0) {
    pvVar5 = (void *)TouchButton::~TouchButton(*(TouchButton **)(this + 0x14));
    operator_delete(pvVar5);
  }
  *(undefined4 *)(this + 0x14) = 0;
  iVar2 = Globals::layout;
  if (param_3) {
    fVar13 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x40),
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar12 = fVar13 * 1.5;
    if (bVar1) {
      fVar12 = fVar13;
    }
    pTVar9 = operator_new(0xc0);
    TouchButton::TouchButton
              (pTVar9,param_4,0,(*(int *)this + *(int *)(this + 8) / 2) - *(int *)(iVar2 + 0x4c) / 2
               ,(*(int *)(this + 4) + *(int *)(this + 0xc)) - *(int *)(this + 0x40),(int)fVar12,'\"'
               ,'\x04');
    *(TouchButton **)(this + 0x10) = pTVar9;
    pTVar9 = operator_new(0xc0);
    TouchButton::TouchButton
              (pTVar9,param_5,0,
               *(int *)this + *(int *)(this + 8) / 2 + *(int *)(Globals::layout + 0x4c) / 2,
               (*(int *)(this + 4) + *(int *)(this + 0xc)) - *(int *)(this + 0x40),(int)fVar12,'!',
               '\x04');
    *(TouchButton **)(this + 0x14) = pTVar9;
  }
  else {
    pTVar9 = operator_new(0xc0);
    TouchButton::TouchButton
              (pTVar9,param_6,0,*(int *)this + *(int *)(this + 8) / 2,
               (*(int *)(this + 4) + *(int *)(this + 0xc)) - *(int *)(this + 0x40),
               *(int *)(Globals::layout + 0x40),'$','\x04');
    *(TouchButton **)(this + 0x10) = pTVar9;
  }
  this[0x51] = (ChoiceWindow)0x1;
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ChoiceWindow::set  @0x001705b4  (48 bytes)
/* ChoiceWindow::set(AbyssEngine::String const&, bool) */

void ChoiceWindow::set(String *param_1,bool param_2)

{
  String *pSVar1;
  bool in_r2;
  
  pSVar1 = (String *)GameText::getText(Globals::gameText,0x186);
  set((ChoiceWindow *)param_1,pSVar1,(String *)(uint)param_2,in_r2);
  return;
}

// ===== ChoiceWindow::removeButtons  @0x001705e8  (8 bytes)
/* ChoiceWindow::removeButtons() */

void __thiscall ChoiceWindow::removeButtons(ChoiceWindow *this)

{
  this[0x51] = (ChoiceWindow)0x0;
  return;
}

// ===== ChoiceWindow::hasChoice  @0x001705f0  (6 bytes)
/* ChoiceWindow::hasChoice() */

ChoiceWindow __thiscall ChoiceWindow::hasChoice(ChoiceWindow *this)

{
  return this[0x50];
}

// ===== ChoiceWindow::setWidth  @0x001705f8  (28 bytes)
/* ChoiceWindow::setWidth(int) */

void __thiscall ChoiceWindow::setWidth(ChoiceWindow *this,int param_1)

{
  *(int *)(this + 8) = param_1;
  *(int *)this = Globals::w / 2 - param_1 / 2;
  return;
}

// ===== ChoiceWindow::setHeight  @0x00170618  (186 bytes)
/* ChoiceWindow::setHeight(int) */

void __thiscall ChoiceWindow::setHeight(ChoiceWindow *this,int param_1)

{
  int iVar1;
  TouchButton *this_00;
  int iVar2;
  uchar uVar3;
  int iVar4;
  
  iVar2 = Globals::layout;
  iVar1 = *(int *)(Globals::layout + 8);
  *(int *)(this + 0xc) = iVar1 + param_1;
  iVar4 = Globals::h / 2 - param_1 / 2;
  *(int *)(this + 4) = iVar4 - iVar1;
  this_00 = *(TouchButton **)(this + 0x10);
  if (this[0x50] == (ChoiceWindow)0x0) {
    if (this_00 == (TouchButton *)0x0) {
      return;
    }
    uVar3 = '$';
    iVar1 = (param_1 + iVar4) - *(int *)(this + 0x40);
    iVar2 = *(int *)this + *(int *)(this + 8) / 2;
  }
  else {
    if (this_00 != (TouchButton *)0x0) {
      TouchButton::setPosition
                (this_00,(*(int *)this + *(int *)(this + 8) / 2) - *(int *)(iVar2 + 0x4c) / 2,
                 (param_1 + iVar4) - *(int *)(this + 0x40),'\"');
    }
    this_00 = *(TouchButton **)(this + 0x14);
    if (this_00 == (TouchButton *)0x0) {
      return;
    }
    iVar1 = (*(int *)(this + 4) + *(int *)(this + 0xc)) - *(int *)(this + 0x40);
    iVar2 = *(int *)this + *(int *)(this + 8) / 2 + *(int *)(Globals::layout + 0x4c) / 2;
    uVar3 = '!';
  }
  TouchButton::setPosition(this_00,iVar2,iVar1,uVar3);
  return;
}

// ===== ChoiceWindow::setMedal  @0x001706e0  (366 bytes)
/* ChoiceWindow::setMedal(int, int) */

void __thiscall ChoiceWindow::setMedal(ChoiceWindow *this,int param_1,int param_2)

{
  undefined4 uVar1;
  String *pSVar2;
  undefined4 uVar3;
  String aSStack_60 [8];
  undefined4 local_58 [2];
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  AbyssEngine aAStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pSVar2 = (String *)GameText::getText(Globals::gameText,param_1 + 0x5e3);
  AbyssEngine::String::operator=((String *)(this + 0x38),pSVar2);
  AbyssEngine::String::String(aSStack_38,"\n\n\n\n\n\n",false);
  uVar1 = Globals::status;
  pSVar2 = (String *)GameText::getText(Globals::gameText,param_1 + 0x610);
  AbyssEngine::String::String(aSStack_48,pSVar2,false);
  uVar3 = Achievements::getValue(Globals::achievements,param_1,param_2);
  local_58[0] = 0;
  AbyssEngine::String::Set(CONCAT44(uVar3,local_58));
  AbyssEngine::String::String(aSStack_50,(String *)local_58,false);
  Status::replaceHash(aSStack_40,uVar1,aSStack_48,aSStack_50);
  AbyssEngine::operator+(aAStack_30,aSStack_38,aSStack_40);
  AbyssEngine::String::String(aSStack_60,"\n\n",false);
  AbyssEngine::operator+(aAStack_28,aAStack_30,aSStack_60);
  AbyssEngine::String::~String(aSStack_60);
  AbyssEngine::String::~String((String *)aAStack_30);
  AbyssEngine::String::~String(aSStack_40);
  AbyssEngine::String::~String(aSStack_50);
  AbyssEngine::String::~String((String *)local_58);
  AbyssEngine::String::~String(aSStack_48);
  AbyssEngine::String::~String(aSStack_38);
  pSVar2 = (String *)GameText::getText(Globals::gameText,0x161);
  set(this,pSVar2,aAStack_28,false);
  ScrollTouchWindow::setTextCentered(SUB41(*(undefined4 *)(this + 0x1c),0));
  if (param_2 < 0x24) {
    AbyssEngine::PaintCanvas::Image2DCreate
              (Globals::Canvas,*(ushort *)(&DAT_00252040 + param_2),(uint *)(this + 0x30));
  }
  else {
    AbyssEngine::PaintCanvas::Image2DCreate
              (Globals::Canvas,*(ushort *)(&DAT_00252030 + param_2 * 4),(uint *)(this + 0x30));
  }
  AbyssEngine::PaintCanvas::Image2DCreate
            (Globals::Canvas,*(ushort *)(&DAT_00258e90 + param_1 * 4),(uint *)(this + 0x34));
  *(int *)(this + 0x28) = param_2;
  *(int *)(this + 0x2c) = param_1;
  this[0x51] = (ChoiceWindow)0x1;
  AbyssEngine::String::~String((String *)aAStack_28);
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ChoiceWindow::setMiscButton  @0x001708d4  (312 bytes)
/* ChoiceWindow::setMiscButton(AbyssEngine::String const&) */

void __thiscall ChoiceWindow::setMiscButton(ChoiceWindow *this,String *param_1)

{
  ChoiceWindow *pCVar1;
  int iVar2;
  int iVar3;
  TouchButton *this_00;
  int iVar4;
  
  if ((*(TouchButton **)(this + 0x10) == (TouchButton *)0x0) || (*(int *)(this + 0x14) == 0)) {
    iVar4 = *(int *)(this + 0x40);
    iVar2 = iVar4 + *(int *)(Globals::layout + 0x40) * 2;
  }
  else {
    iVar2 = TouchButton::getWidth(*(TouchButton **)(this + 0x10));
    iVar3 = TouchButton::getWidth(*(TouchButton **)(this + 0x14));
    iVar4 = *(int *)(this + 0x40);
    iVar2 = iVar3 + iVar2 + iVar4;
  }
  iVar3 = Globals::layout;
  this_00 = operator_new(0xc0);
  TouchButton::TouchButton
            (this_00,param_1,0,(*(int *)this + *(int *)(this + 8) / 2) - *(int *)(iVar3 + 0x4c) / 2,
             (*(int *)(this + 4) + *(int *)(this + 0xc)) - iVar4,iVar2,'\"','\x04');
  *(TouchButton **)(this + 0x18) = this_00;
  pCVar1 = this + 0x40;
  setHeight(this,(*(int *)(this + 0xc) - *(int *)(Globals::layout + 8)) + *(int *)pCVar1 * 2 +
                 *(int *)(Globals::layout + 0x30));
  TouchButton::setPosition
            (*(TouchButton **)(this + 0x18),*(int *)this + *(int *)(this + 8) / 2,
             (*(int *)(this + 4) + *(int *)(this + 0xc)) - *(int *)(this + 0x40),'$');
  if (*(TouchButton **)(this + 0x10) != (TouchButton *)0x0) {
    TouchButton::translate
              (*(TouchButton **)(this + 0x10),0,-(*(int *)(Globals::layout + 0x30) + *(int *)pCVar1)
              );
  }
  if (*(TouchButton **)(this + 0x14) != (TouchButton *)0x0) {
    TouchButton::translate
              (*(TouchButton **)(this + 0x14),0,-(*(int *)(Globals::layout + 0x30) + *(int *)pCVar1)
              );
  }
  ScrollTouchWindow::setYPosition(*(int *)(this + 0x1c));
  return;
}

// ===== ChoiceWindow::update  @0x00170a34  (8 bytes)
/* ChoiceWindow::update(int) */

void ChoiceWindow::update(int param_1)

{
  ScrollTouchWindow::update(*(int *)(param_1 + 0x1c));
  return;
}

// ===== ChoiceWindow::draw  @0x00170a3c  (704 bytes)
/* ChoiceWindow::draw() */

void __thiscall ChoiceWindow::draw(ChoiceWindow *this)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  Layout *pLVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  float local_88;
  float local_80;
  float local_70;
  float local_68;
  float local_58;
  float local_50;
  String aSStack_44 [8];
  String aSStack_3c [8];
  AbyssEngine aAStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  Layout::drawMask();
  pLVar3 = Globals::layout;
  uVar7 = *(undefined4 *)this;
  uVar9 = *(undefined4 *)(this + 4);
  uVar6 = *(undefined4 *)(this + 8);
  uVar11 = *(undefined4 *)(this + 0xc);
  uVar4 = AbyssEngine::String::String(aSStack_2c,this + 0x20,false);
  Layout::drawBox(pLVar3,7,uVar7,uVar9,uVar6,uVar11,uVar4);
  AbyssEngine::String::~String(aSStack_2c);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  if (*(uint *)(this + 0x30) != 0xffffffff) {
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x30),*(int *)this + (*(int *)(this + 8) >> 1),
               *(int *)(this + 0x44) + *(int *)(this + 4) + 1,'\x11','D');
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x34),*(int *)this + (*(int *)(this + 8) >> 1),
               *(int *)(this + 0x44) + *(int *)(this + 4),'\x11','D');
    iVar5 = Status::hardCoreMode();
    if ((iVar5 == 0) &&
       (iVar5 = Achievements::isEliteMedal(Globals::achievements,*(int *)(this + 0x2c)), iVar5 == 0)
       ) {
      AbyssEngine::String::String(aSStack_3c,"+ ",false);
      Layout::formatCredits((int)aSStack_44);
      AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_44);
      AbyssEngine::String::~String(aSStack_44);
      AbyssEngine::String::~String(aSStack_3c);
      uVar2 = Globals::font;
      pPVar1 = Globals::Canvas;
      iVar8 = *(int *)this;
      iVar10 = *(int *)(this + 8);
      iVar5 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_34);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar2,aAStack_34,(iVar8 + (iVar10 >> 1)) - iVar5 / 2,
                 (*(int *)(this + 4) + *(int *)(this + 0xc)) - *(int *)(this + 0x48),false);
      AbyssEngine::String::~String((String *)aAStack_34);
    }
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    uVar2 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar8 = *(int *)this;
    iVar10 = *(int *)(this + 8);
    iVar5 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,this + 0x38);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar2,this + 0x38,(iVar8 + (iVar10 >> 1)) - iVar5 / 2,
               *(int *)(this + 4) + *(int *)(this + 0x4c),false);
  }
  ScrollTouchWindow::draw(*(ScrollTouchWindow **)(this + 0x1c));
  if (this[0x51] != (ChoiceWindow)0x0) {
    if (*(TouchButton **)(this + 0x10) != (TouchButton *)0x0) {
      TouchButton::draw(*(TouchButton **)(this + 0x10));
    }
    if ((*(TouchButton **)(this + 0x14) != (TouchButton *)0x0) &&
       (TouchButton::draw(*(TouchButton **)(this + 0x14)), *(int *)(this + 0x14) != 0)) {
      TouchButton::getPosition();
      Globals::other_buttons_x._8_4_ = (undefined4)local_50;
      TouchButton::getPosition();
      Globals::other_buttons_y._8_4_ = (undefined4)local_58;
    }
    if (*(int *)(this + 0x10) != 0) {
      TouchButton::getPosition();
      Globals::other_buttons_x._12_4_ = (undefined4)local_68;
      TouchButton::getPosition();
      Globals::other_buttons_y._12_4_ = (undefined4)local_70;
      if (*(int *)(this + 0x14) == 0) {
        TouchButton::getPosition();
        Globals::other_buttons_x._8_4_ = (undefined4)local_80;
        TouchButton::getPosition();
        Globals::other_buttons_y._8_4_ = (undefined4)local_88;
      }
    }
    Globals::is_choice_window_visible = 1;
    if (*(TouchButton **)(this + 0x18) != (TouchButton *)0x0) {
      TouchButton::draw(*(TouchButton **)(this + 0x18));
    }
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ChoiceWindow::OnTouchBegin  @0x00170d80  (72 bytes)
/* ChoiceWindow::OnTouchBegin(int, int) */

undefined4 __thiscall ChoiceWindow::OnTouchBegin(ChoiceWindow *this,int param_1,int param_2)

{
  if (this[0x51] != (ChoiceWindow)0x0) {
    if (*(TouchButton **)(this + 0x10) != (TouchButton *)0x0) {
      TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x10),param_1,param_2);
    }
    if (*(TouchButton **)(this + 0x14) != (TouchButton *)0x0) {
      TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x14),param_1,param_2);
    }
    if (*(TouchButton **)(this + 0x18) != (TouchButton *)0x0) {
      TouchButton::OnTouchBegin(*(TouchButton **)(this + 0x18),param_1,param_2);
    }
  }
  if (*(int *)(this + 0x1c) != 0) {
    ScrollTouchWindow::OnTouchBegin(*(int *)(this + 0x1c),param_1);
  }
  return 0;
}

// ===== ChoiceWindow::OnTouchMove  @0x00170dc8  (72 bytes)
/* ChoiceWindow::OnTouchMove(int, int) */

undefined4 __thiscall ChoiceWindow::OnTouchMove(ChoiceWindow *this,int param_1,int param_2)

{
  if (this[0x51] != (ChoiceWindow)0x0) {
    if (*(TouchButton **)(this + 0x10) != (TouchButton *)0x0) {
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0x10),param_1,param_2);
    }
    if (*(TouchButton **)(this + 0x14) != (TouchButton *)0x0) {
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0x14),param_1,param_2);
    }
    if (*(TouchButton **)(this + 0x18) != (TouchButton *)0x0) {
      TouchButton::OnTouchMove(*(TouchButton **)(this + 0x18),param_1,param_2);
    }
  }
  if (*(ScrollTouchWindow **)(this + 0x1c) != (ScrollTouchWindow *)0x0) {
    ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 0x1c),param_1,param_2);
  }
  return 0;
}

// ===== ChoiceWindow::OnTouchEnd  @0x00170e10  (92 bytes)
/* ChoiceWindow::OnTouchEnd(int, int) */

undefined4 __thiscall ChoiceWindow::OnTouchEnd(ChoiceWindow *this,int param_1,int param_2)

{
  int iVar1;
  
  if (this[0x51] != (ChoiceWindow)0x0) {
    if ((*(TouchButton **)(this + 0x10) != (TouchButton *)0x0) &&
       (iVar1 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x10),param_1,param_2), iVar1 != 0)
       ) {
      return 0;
    }
    if ((*(TouchButton **)(this + 0x14) != (TouchButton *)0x0) &&
       (iVar1 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x14),param_1,param_2), iVar1 != 0)
       ) {
      return 1;
    }
    if ((*(TouchButton **)(this + 0x18) != (TouchButton *)0x0) &&
       (iVar1 = TouchButton::OnTouchEnd(*(TouchButton **)(this + 0x18),param_1,param_2), iVar1 != 0)
       ) {
      return 2;
    }
  }
  if (*(int *)(this + 0x1c) != 0) {
    ScrollTouchWindow::OnTouchEnd(*(int *)(this + 0x1c),param_1);
  }
  return 0xffffffff;
}

// ===== ChoiceWindow::left  @0x00170e6c  (2 bytes)
/* ChoiceWindow::left() */

void ChoiceWindow::left(void)

{
  return;
}

// ===== ChoiceWindow::right  @0x00170e6e  (2 bytes)
/* ChoiceWindow::right() */

void ChoiceWindow::right(void)

{
  return;
}

// ===== ChoiceWindow::fire  @0x00170e70  (4 bytes)
/* ChoiceWindow::fire() */

undefined4 ChoiceWindow::fire(void)

{
  return 0;
}

