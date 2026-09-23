// Class: StatusWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== StatusWindow::StatusWindow  @0x0018345c  (720 bytes)
/* StatusWindow::StatusWindow() */

StatusWindow * __thiscall StatusWindow::StatusWindow(StatusWindow *this)

{
  Layout *pLVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  TouchButton *pTVar4;
  String *pSVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  
  pAVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar2 + 4) = puVar3;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar2 = 0;
  *(Array **)(this + 4) = pAVar2;
  ArraySetLength<TouchButton*>(2,pAVar2);
  pTVar4 = operator_new(0xc0);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0xa8);
  iVar9 = Globals::w;
  iVar6 = Layout::getHelpButtonOffset(Globals::layout);
  TouchButton::TouchButton(pTVar4,pSVar5,3,iVar9 - iVar6,0,'\x12');
  *(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + 4) = pTVar4;
  pTVar4 = operator_new(0xc0);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x241);
  iVar9 = Globals::w;
  iVar6 = Layout::getHelpButtonOffset(Globals::layout);
  iVar7 = TouchButton::getWidth(*(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + 4));
  TouchButton::TouchButton
            (pTVar4,pSVar5,3,((iVar9 - iVar6) - iVar7) + *(int *)(Globals::layout + 0x38),0,'\x12');
  **(undefined4 **)(*(int *)(this + 4) + 4) = pTVar4;
  uVar8 = (uint)Globals::iPad;
  *(uint *)(this + 0x30) = uVar8;
  TouchButton::setAlwaysPressed
            (*(TouchButton **)(*(int *)(*(int *)(this + 4) + 4) + uVar8 * 4),true);
  *(undefined4 *)(this + 0x78) = *(undefined4 *)(Globals::layout + 0x84);
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  pAVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar2 + 4) = puVar3;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar2 = 0;
  *(Array **)(this + 8) = pAVar2;
  *(undefined4 *)this = 0x2d;
  ArraySetLength<TouchButton*>(0x2d,pAVar2);
  iVar9 = Achievements::getMedals(Globals::achievements);
  if (0 < *(int *)this) {
    iVar6 = 0;
    do {
      pTVar4 = operator_new(0xc0);
      iVar7 = *(int *)(iVar9 + iVar6 * 4);
      pSVar5 = (String *)GameText::getText(Globals::gameText,iVar6 + 0x5e3);
      TouchButton::TouchButton(pTVar4,iVar6,iVar7,pSVar5,0,0,'D');
      *(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + iVar6 * 4) = pTVar4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)this);
  }
  reInit(this);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x48e,(uint *)(this + 0x24));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x48f,(uint *)(this + 0x28));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x48d,(uint *)(this + 0x2c));
  iVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x24));
  *(int *)(this + 0x70) = iVar9 / 2;
  uVar10 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x24));
  *(undefined4 *)(this + 0x74) = uVar10;
  *(undefined4 *)(this + 0x45) = 0;
  *(undefined4 *)(this + 0x49) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x4d) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x51) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  piVar11 = operator_new__(0xc);
  *(int **)(this + 0x68) = piVar11;
  pLVar1 = Globals::layout;
  *piVar11 = *(int *)(this + 100) +
             *(int *)(Globals::layout + 0x1c) * 3 + *(int *)(Globals::layout + 0x2d8) +
             *(int *)(Globals::layout + 0x2c) * 8 + *(int *)(Globals::layout + 4) * 7;
  if (Globals::iPad == 0) {
    iVar9 = *(int *)(this + 0x78) * (*(int *)this / 3);
  }
  else {
    iVar9 = (*(int *)this / 3) * *(int *)(this + 0x78) +
            *(int *)(pLVar1 + 0x1c) + *(int *)(pLVar1 + 0x2c);
  }
  piVar11[1] = iVar9 + 10;
  *(int *)(this + 0x58) = piVar11[*(int *)(this + 0x30)];
  *(int *)(this + 0x5c) =
       (((Globals::h - *(int *)(pLVar1 + 0x10)) - *(int *)(pLVar1 + 0xc)) - *(int *)(pLVar1 + 0x20))
       - *(int *)(pLVar1 + 0x24);
  return this;
}

// ===== StatusWindow::reInit  @0x00183784  (250 bytes)
/* StatusWindow::reInit() */

void __thiscall StatusWindow::reInit(StatusWindow *this)

{
  undefined4 uVar1;
  Standing *pSVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  
  uVar1 = ImageFactory::loadChar(Globals::imageFactory,(int *)&DAT_0026d398);
  *(undefined4 *)(this + 0xc) = uVar1;
  pSVar2 = (Standing *)Status::getStanding(Globals::status);
  iVar3 = Standing::isEnemy(pSVar2,0);
  pSVar2 = (Standing *)Status::getStanding(Globals::status);
  iVar4 = Standing::isEnemy(pSVar2,1);
  pSVar2 = (Standing *)Status::getStanding(Globals::status);
  iVar5 = Standing::isEnemy(pSVar2,2);
  pSVar2 = (Standing *)Status::getStanding(Globals::status);
  iVar6 = Standing::isEnemy(pSVar2,3);
  uVar7 = 0x493;
  if (iVar4 != 0) {
    uVar7 = 0x494;
  }
  if (iVar3 != 0) {
    uVar7 = 0x495;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar7,(uint *)(this + 0x14));
  uVar7 = 0x492;
  if (iVar3 != 0) {
    uVar7 = 0x496;
  }
  if (iVar4 != 0) {
    uVar7 = 0x497;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar7,(uint *)(this + 0x18));
  uVar7 = 0x490;
  if (iVar6 != 0) {
    uVar7 = 0x498;
  }
  if (iVar5 != 0) {
    uVar7 = 0x499;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar7,(uint *)(this + 0x1c));
  uVar7 = 0x491;
  if (iVar5 != 0) {
    uVar7 = 0x49a;
  }
  if (iVar6 != 0) {
    uVar7 = 0x49b;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar7,(uint *)(this + 0x20));
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x14));
  *(undefined4 *)(this + 0x60) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x14));
  *(undefined4 *)(this + 100) = uVar1;
  return;
}

// ===== StatusWindow::~StatusWindow  @0x00183890  (130 bytes)
/* StatusWindow::~StatusWindow() */

StatusWindow * __thiscall StatusWindow::~StatusWindow(StatusWindow *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 4) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 4));
    pvVar1 = *(void **)(this + 4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(Array **)(this + 8) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 8));
    pvVar1 = *(void **)(this + 8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(Array **)(this + 0xc) != (Array *)0x0) {
    ArrayReleaseClasses<ImagePart*>(*(Array **)(this + 0xc));
    pvVar1 = *(void **)(this + 0xc);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  if (*(Array **)(this + 0x10) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x10));
    pvVar1 = *(void **)(this + 0x10);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x10) = 0;
  return this;
}

// ===== StatusWindow::getRelativeScrollStartPos  @0x00183914  (42 bytes)
/* StatusWindow::getRelativeScrollStartPos() */

float __thiscall StatusWindow::getRelativeScrollStartPos(StatusWindow *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (*(int *)(this + 0x38) < 1) {
    fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0x38),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x58),(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = -fVar2 / fVar1;
  }
  else {
    fVar1 = 0.0;
  }
  return fVar1;
}

// ===== StatusWindow::getRelativeScrollHeight  @0x00183944  (76 bytes)
/* StatusWindow::getRelativeScrollHeight() */

float __thiscall StatusWindow::getRelativeScrollHeight(StatusWindow *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  iVar2 = *(int *)(this + 0x58);
  iVar3 = *(int *)(this + 0x5c);
  if (iVar2 < iVar3) {
    return 0.0;
  }
  iVar1 = *(int *)(this + 0x38);
  if (iVar1 < 1) {
    if (iVar3 - iVar2 <= iVar1) {
      fVar4 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
      goto LAB_00183982;
    }
    iVar3 = iVar1 + iVar2;
  }
  else {
    iVar3 = iVar3 - iVar1;
  }
  fVar4 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
LAB_00183982:
  fVar5 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
  return fVar5 / fVar4;
}

// ===== StatusWindow::update  @0x00183994  (208 bytes)
/* StatusWindow::update(int) */

void StatusWindow::update(int param_1)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  
  if (*(char *)(param_1 + 0x54) == '\0') {
    fVar6 = *(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x4c);
    fVar7 = -(*(float *)(param_1 + 0x48) * *(float *)(param_1 + 0x4c));
    if (0.0 < fVar6) {
      fVar7 = fVar6;
    }
    *(float *)(param_1 + 0x4c) = fVar6;
    uVar5 = in_fpscr & 0xfffffff | (uint)(fVar7 < 1.0) << 0x1f | (uint)(fVar7 == 1.0) << 0x1e;
    in_fpscr = uVar5 | (uint)NAN(fVar7) << 0x1c;
    bVar1 = (byte)(uVar5 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x38),
                                         (byte)(in_fpscr >> 0x16) & 3);
      *(int *)(param_1 + 0x38) = (int)(fVar6 + fVar7);
    }
  }
  iVar2 = *(int *)(param_1 + 0x38);
  if (0 < iVar2) {
    fVar7 = (float)VectorSignedToFloat(-iVar2,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(param_1 + 0x4c) = fVar7 * 0.5;
    *(undefined4 *)(param_1 + 0x48) = 0x3f800000;
  }
  iVar4 = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58);
  if (iVar4 < 0) {
    if (iVar2 < iVar4) {
      fVar7 = (float)VectorSignedToFloat(iVar4 - iVar2,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x4c) = fVar7 * 0.5;
      *(undefined4 *)(param_1 + 0x48) = 0x3f800000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  puVar3 = *(uint **)(param_1 + 4);
  if (*puVar3 != 0) {
    uVar5 = 0;
    do {
      TouchButton::setAlwaysPressed
                (*(TouchButton **)(puVar3[1] + uVar5 * 4),uVar5 == *(uint *)(param_1 + 0x30));
      puVar3 = *(uint **)(param_1 + 4);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar3);
  }
  return;
}

// ===== StatusWindow::draw  @0x00183a64  (7538 bytes)
/* StatusWindow::draw() */

void __thiscall StatusWindow::draw(StatusWindow *this)

{
  PaintCanvas *pPVar1;
  PaintCanvas *pPVar2;
  GameText *this_00;
  uint uVar3;
  Globals *pGVar4;
  Layout *pLVar5;
  ImageFactory *this_01;
  char cVar6;
  short sVar7;
  float fVar8;
  Ship *pSVar9;
  Standing *pSVar10;
  String *pSVar11;
  String *pSVar12;
  undefined4 uVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 uVar24;
  int iVar25;
  uint in_fpscr;
  int iVar26;
  float fVar27;
  float fVar28;
  undefined8 uVar29;
  int local_e8;
  String aSStack_e0 [8];
  String aSStack_d8 [8];
  String aSStack_d0 [8];
  String aSStack_c8 [8];
  String aSStack_c0 [8];
  String aSStack_b8 [8];
  String aSStack_b0 [8];
  String aSStack_a8 [8];
  String aSStack_a0 [8];
  String aSStack_98 [8];
  undefined4 local_90 [2];
  int local_88;
  undefined4 local_84 [2];
  String aSStack_7c [8];
  undefined4 local_74 [2];
  int local_6c [2];
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  String aSStack_4c [8];
  String aSStack_44 [8];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::FillRectangle(Globals::Canvas,0,0,Globals::w,Globals::h);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  Layout::drawBG(Globals::layout);
  if (*(int *)(this + 0x38) < 1) {
    fVar8 = (float)VectorSignedToFloat(*(int *)(this + 0x38),(byte)(in_fpscr >> 0x16) & 3);
    fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x58),(byte)(in_fpscr >> 0x16) & 3);
    fVar27 = -fVar8 / fVar27;
  }
  else {
    fVar27 = 0.0;
  }
  iVar21 = *(int *)(this + 0x5c);
  fVar28 = (float)VectorSignedToFloat(iVar21,(byte)(in_fpscr >> 0x16) & 3);
  fVar8 = (float)getRelativeScrollHeight(this);
  iVar26 = (int)(fVar8 * fVar28);
  if ((0 < iVar26) || (0 < (int)(fVar27 * fVar28))) {
    Layout::drawScrollBar
              (Globals::layout,
               (Globals::w - *(int *)(Globals::layout + 0x48)) - *(int *)(Globals::layout + 0x28),
               *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc),iVar21,
               (int)(fVar27 * fVar28),iVar26);
  }
  local_e8 = *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0xc);
  if (Globals::iPad == '\0') {
    local_e8 = local_e8 + *(int *)(this + 0x38);
    iVar15 = *(int *)(Globals::layout + 0x28);
    iVar21 = Globals::w;
  }
  else {
    iVar15 = *(int *)(Globals::layout + 0x28);
    iVar21 = Globals::w >> 1;
  }
  if (iVar26 < 1) {
    iVar21 = iVar21 + iVar15 * -2;
  }
  else {
    iVar21 = ((iVar21 - *(int *)(Globals::layout + 0x48)) - *(int *)(Globals::layout + 0x2c)) +
             iVar15 * -2;
  }
  *(int *)(this + 0x6c) = iVar21;
  AbyssEngine::String::String(aSStack_44);
  sVar7 = GameText::getLanguage();
  if (sVar7 == 9) {
    AbyssEngine::String::String(aSStack_4c,"",false);
  }
  else {
    AbyssEngine::String::String(aSStack_4c,":",false);
  }
  pLVar5 = Globals::layout;
  iVar21 = *(int *)(this + 0x30);
  if ((iVar21 == 0) || (Globals::iPad != '\0')) {
    uVar17 = *(undefined4 *)(this + 0x6c);
    uVar18 = *(undefined4 *)(Globals::layout + 0x1c);
    uVar24 = *(undefined4 *)(Globals::layout + 0x28);
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x63d);
    uVar13 = AbyssEngine::String::String(aSStack_54,pSVar12,false);
    Layout::drawBox(pLVar5,0,uVar24,local_e8,uVar17,uVar18,uVar13);
    AbyssEngine::String::~String(aSStack_54);
    pLVar5 = Globals::layout;
    iVar26 = *(int *)(Globals::layout + 0x1c);
    uVar17 = *(undefined4 *)(Globals::layout + 0x28);
    iVar21 = *(int *)(Globals::layout + 0x2c);
    iVar15 = *(int *)(this + 0x6c);
    uVar18 = *(undefined4 *)(Globals::layout + 0x2d8);
    uVar13 = AbyssEngine::String::String(aSStack_5c,"",false);
    iVar26 = local_e8 + iVar26 + iVar21;
    Layout::drawBox(pLVar5,5,uVar17,iVar26,(iVar15 >> 1) - iVar21,uVar18,uVar13);
    AbyssEngine::String::~String(aSStack_5c);
    ImageFactory::drawChar
              (Globals::imageFactory,*(Array **)(this + 0xc),
               *(int *)(Globals::layout + 0x28) + *(int *)(Globals::layout + 0x4c),iVar26,false);
    Status::getCredits(Globals::status);
    Layout::formatCredits((int)aSStack_64);
    AbyssEngine::String::operator=(aSStack_44,aSStack_64);
    AbyssEngine::String::~String(aSStack_64);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar25 = *(int *)(this + 0x6c);
    iVar15 = *(int *)(Globals::layout + 0x2c);
    iVar16 = *(int *)(Globals::layout + 0x4c);
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_44);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,aSStack_44,(((iVar25 >> 1) - iVar15) - iVar16) - iVar21,
               *(int *)(Globals::layout + 0x2c) + iVar26,false);
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x141);
    AbyssEngine::String::String((String *)local_74," ",false);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,(String *)local_74);
    local_90[0] = Status::getLevel(Globals::status);
    AbyssEngine::operator+(aSStack_64,local_6c);
    AbyssEngine::String::operator=(aSStack_44,aSStack_64);
    AbyssEngine::String::~String(aSStack_64);
    AbyssEngine::String::~String((String *)local_6c);
    AbyssEngine::String::~String((String *)local_74);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar25 = *(int *)(this + 0x6c);
    iVar15 = *(int *)(Globals::layout + 0x2c);
    iVar16 = *(int *)(Globals::layout + 0x4c);
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_44);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,aSStack_44,(((iVar25 >> 1) - iVar15) - iVar16) - iVar21,
               *(int *)(Globals::layout + 0x2c) + iVar26 + *(int *)(Globals::layout + 4),false);
    pGVar4 = Globals::globals;
    uVar29 = Status::getPlayingTime(Globals::status);
    Globals::longToTimeStringNoSeconds
              (CONCAT44((int)((ulonglong)uVar29 >> 0x20),pGVar4),(String *)uVar29);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar25 = *(int *)(this + 0x6c);
    iVar15 = *(int *)(Globals::layout + 0x2c);
    iVar16 = *(int *)(Globals::layout + 0x4c);
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_44);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,aSStack_44,(((iVar25 >> 1) - iVar15) - iVar16) - iVar21,
               *(int *)(Globals::layout + 0x2c) + iVar26 + *(int *)(Globals::layout + 4) * 2,false);
    pLVar5 = Globals::layout;
    iVar15 = *(int *)(this + 0x6c);
    iVar25 = *(int *)(Globals::layout + 0x28);
    iVar21 = *(int *)(Globals::layout + 0x2c);
    uVar17 = *(undefined4 *)(Globals::layout + 0x2d8);
    uVar13 = AbyssEngine::String::String(aSStack_7c,"",false);
    Layout::drawBox(pLVar5,5,(iVar15 >> 1) + iVar25 + iVar21,iVar26,(iVar15 >> 1) - iVar21,uVar17,
                    uVar13);
    AbyssEngine::String::~String(aSStack_7c);
    this_01 = Globals::imageFactory;
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    iVar21 = Ship::getIndex(pSVar9);
    ImageFactory::drawShip
              (this_01,iVar21,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) * 2,iVar26);
    uVar20 = Globals::font;
    this_00 = Globals::gameText;
    pPVar1 = Globals::Canvas;
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    iVar21 = Ship::getIndex(pSVar9);
    pSVar12 = (String *)GameText::getText(this_00,iVar21 + 0x391);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,pSVar12,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) * 3 + *(int *)(Globals::layout + 0x2cc),
               *(int *)(Globals::layout + 0x2c) + iVar26,false);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x239);
    AbyssEngine::operator+((AbyssEngine *)aSStack_64,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,aSStack_64,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) * 3 + *(int *)(Globals::layout + 0x2cc),
               *(int *)(Globals::layout + 4) + *(int *)(Globals::layout + 0x2c) + iVar26,false);
    AbyssEngine::String::~String(aSStack_64);
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    Ship::getFirePower(pSVar9);
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    uVar29 = Ship::getFirePower(pSVar9);
    VectorSignedToFloat((int)(float)uVar29,(byte)(in_fpscr >> 0x16) & 3);
    local_84[0] = 0;
    AbyssEngine::String::Set(CONCAT44((int)((ulonglong)uVar29 >> 0x20),local_84));
    AbyssEngine::String::SubString((uint)aSStack_64,(uint)local_84);
    AbyssEngine::String::~String((String *)local_84);
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    fVar8 = (float)Ship::getFirePower(pSVar9);
    local_88 = (int)fVar8;
    AbyssEngine::String::String((String *)local_90,".",false);
    AbyssEngine::operator+((AbyssEngine *)local_74,&local_88,(String *)local_90);
    AbyssEngine::operator+((AbyssEngine *)local_6c,(String *)local_74,aSStack_64);
    AbyssEngine::String::operator=(aSStack_44,(String *)local_6c);
    AbyssEngine::String::~String((String *)local_6c);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_90);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar25 = *(int *)(this + 0x6c);
    iVar15 = *(int *)(Globals::layout + 0x28);
    iVar16 = *(int *)(Globals::layout + 0x4c);
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_44);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,aSStack_44,((iVar25 + iVar15) - iVar16) - iVar21,
               *(int *)(Globals::layout + 0x2c) + iVar26 + *(int *)(Globals::layout + 4),false);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x23a);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) * 3 + *(int *)(Globals::layout + 0x2cc),
               *(int *)(Globals::layout + 0x2c) + iVar26 + *(int *)(Globals::layout + 4) * 2,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    uVar13 = Ship::getCombinedHP(pSVar9);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar16 = *(int *)(this + 0x6c);
    iVar15 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    uVar13 = Ship::getCombinedHP(pSVar9);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,((iVar16 + iVar15) - iVar25) - iVar21,
               *(int *)(Globals::layout + 0x2c) + iVar26 + *(int *)(Globals::layout + 4) * 2,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    pLVar5 = Globals::layout;
    iVar15 = *(int *)(Globals::layout + 0x2d8);
    uVar18 = *(undefined4 *)(Globals::layout + 0x28);
    iVar21 = *(int *)(Globals::layout + 0x2c);
    uVar17 = *(undefined4 *)(Globals::layout + 0x1c);
    uVar24 = *(undefined4 *)(this + 0x6c);
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x240);
    uVar13 = AbyssEngine::String::String(aSStack_98,pSVar12,false);
    iVar21 = iVar15 + iVar26 + iVar21;
    Layout::drawBox(pLVar5,0,uVar18,iVar21,uVar24,uVar17,uVar13);
    AbyssEngine::String::~String(aSStack_98);
    pLVar5 = Globals::layout;
    uVar13 = *(undefined4 *)(Globals::layout + 0x28);
    iVar19 = *(int *)(Globals::layout + 4);
    iVar15 = *(int *)(Globals::layout + 0x1c);
    iVar26 = *(int *)(Globals::layout + 0x2c);
    iVar25 = *(int *)(this + 100);
    iVar23 = *(int *)(this + 0x6c);
    uVar17 = AbyssEngine::String::String(aSStack_a0,"",false);
    iVar16 = iVar15 + iVar21 + iVar26;
    Layout::drawBox(pLVar5,5,uVar13,iVar16,(iVar23 >> 1) - iVar26,iVar25 + iVar26 * 2 + iVar19,
                    uVar17);
    AbyssEngine::String::~String(aSStack_a0);
    pLVar5 = Globals::layout;
    iVar25 = *(int *)(this + 100);
    iVar21 = *(int *)(this + 0x6c);
    iVar19 = *(int *)(Globals::layout + 4);
    iVar15 = *(int *)(Globals::layout + 0x28);
    iVar26 = *(int *)(Globals::layout + 0x2c);
    uVar13 = AbyssEngine::String::String(aSStack_a8,"",false);
    Layout::drawBox(pLVar5,5,(iVar21 >> 1) + iVar15 + iVar26,iVar16,(iVar21 >> 1) - iVar26,
                    iVar25 + iVar26 * 2 + iVar19,uVar13);
    AbyssEngine::String::~String(aSStack_a8);
    iVar16 = *(int *)(Globals::layout + 0x2c) + iVar16;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x14),
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),iVar16);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x18),
               ((*(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1)) -
               *(int *)(Globals::layout + 0x2c)) - *(int *)(Globals::layout + 0x4c),iVar16,'\x11',
               '\x12');
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x1c),
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0x4c),iVar16);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x20),
               (*(int *)(Globals::layout + 0x28) + *(int *)(this + 0x6c)) -
               *(int *)(Globals::layout + 0x4c),iVar16,'\x11','\x12');
    iVar15 = *(int *)(Globals::layout + 0x2c) + *(int *)(this + 100) + iVar16;
    iVar21 = *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 2);
    iVar26 = (iVar15 - (*(int *)(this + 100) >> 1)) - (*(int *)(this + 0x74) >> 1);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x24),iVar21,iVar26,'\x11','\x14');
    pSVar10 = (Standing *)Status::getStanding(Globals::status);
    fVar8 = (float)Standing::getStandingRate(pSVar10,0);
    fVar27 = (float)VectorSignedToFloat(*(int *)(this + 0x70),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)(this + 0x28),*(int *)(this + 0x70),0,(int)-(fVar8 * fVar27)
               ,*(int *)(this + 0x74),(float)(int)-(fVar8 * fVar27),0,0,0,iVar21);
    fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x70),(byte)(in_fpscr >> 0x16) & 3);
    fVar28 = (float)VectorSignedToFloat(iVar21,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x2c),(int)(fVar28 + fVar27 * -fVar8),
               iVar15 - (*(int *)(this + 100) >> 1),'\x11','D');
    iVar21 = (*(int *)(this + 0x6c) -
             (*(int *)(this + 0x6c) + *(int *)(Globals::layout + 0x2c) * -2 >> 2)) +
             *(int *)(Globals::layout + 0x2c) * 2;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x24),iVar21,iVar26,'\x11','\x14');
    pSVar10 = (Standing *)Status::getStanding(Globals::status);
    fVar8 = (float)Standing::getStandingRate(pSVar10,1);
    fVar27 = (float)VectorSignedToFloat(*(int *)(this + 0x70),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)(this + 0x28),*(int *)(this + 0x70),0,(int)-(fVar8 * fVar27)
               ,*(int *)(this + 0x74),(float)(int)-(fVar8 * fVar27),0,0,0,iVar21);
    fVar27 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x70),(byte)(in_fpscr >> 0x16) & 3);
    fVar28 = (float)VectorSignedToFloat(iVar21,(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x2c),(int)(fVar28 + fVar27 * -fVar8),
               iVar15 - (*(int *)(this + 100) >> 1),'\x11','D');
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x196);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,pSVar12,
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),iVar15,false);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x197);
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar26 = *(int *)(this + 0x6c);
    iVar16 = *(int *)(Globals::layout + 0x28);
    iVar19 = *(int *)(Globals::layout + 0x2c);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x197);
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,pSVar11);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,pSVar12,(((iVar16 + (iVar26 >> 1)) - iVar19) - iVar25) - iVar21,iVar15,
               false);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x198);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,pSVar12,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0x4c),iVar15,false);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x199);
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar16 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    pSVar11 = (String *)GameText::getText(Globals::gameText,0x199);
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,pSVar11);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,pSVar12,((iVar16 + iVar26) - iVar25) - iVar21,iVar15,false);
    pLVar5 = Globals::layout;
    iVar26 = *(int *)(Globals::layout + 4);
    uVar24 = *(undefined4 *)(Globals::layout + 0x1c);
    uVar18 = *(undefined4 *)(this + 0x6c);
    uVar17 = *(undefined4 *)(Globals::layout + 0x28);
    iVar21 = *(int *)(Globals::layout + 0x2c);
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x241);
    uVar13 = AbyssEngine::String::String(aSStack_b0,pSVar12,false);
    iVar21 = iVar15 + iVar26 + iVar21;
    Layout::drawBox(pLVar5,0,uVar17,iVar21,uVar18,uVar24,uVar13);
    AbyssEngine::String::~String(aSStack_b0);
    pLVar5 = Globals::layout;
    iVar25 = *(int *)(Globals::layout + 4);
    iVar15 = *(int *)(Globals::layout + 0x1c);
    uVar17 = *(undefined4 *)(Globals::layout + 0x28);
    iVar26 = *(int *)(Globals::layout + 0x2c);
    iVar19 = *(int *)(this + 0x6c);
    uVar13 = AbyssEngine::String::String(aSStack_b8,"",false);
    iVar16 = iVar15 + iVar21 + iVar26;
    Layout::drawBox(pLVar5,5,uVar17,iVar16,(iVar19 >> 1) - iVar26,iVar26 + iVar25 * 6,uVar13);
    AbyssEngine::String::~String(aSStack_b8);
    pLVar5 = Globals::layout;
    iVar21 = *(int *)(this + 0x6c);
    iVar25 = *(int *)(Globals::layout + 4);
    iVar15 = *(int *)(Globals::layout + 0x28);
    iVar26 = *(int *)(Globals::layout + 0x2c);
    uVar13 = AbyssEngine::String::String(aSStack_c0,"",false);
    Layout::drawBox(pLVar5,5,(iVar21 >> 1) + iVar15 + iVar26,iVar16,(iVar21 >> 1) - iVar26,
                    iVar26 + iVar25 * 6,uVar13);
    AbyssEngine::String::~String(aSStack_c0);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    local_e8 = *(int *)(Globals::layout + 0x2c);
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x238);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    local_e8 = local_e8 + iVar16;
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),local_e8,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    uVar13 = Status::getMissionCount(Globals::status);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar25 = *(int *)(Globals::layout + 0x2c);
    iVar15 = *(int *)(Globals::layout + 0x4c);
    iVar26 = *(int *)(this + 0x6c);
    uVar13 = Status::getMissionCount(Globals::status);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,(((iVar26 >> 1) - iVar25) - iVar15) - iVar21,
               local_e8,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0xb0);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),
               *(int *)(Globals::layout + 4) + local_e8,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    uVar13 = Status::getKills(Globals::status);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar25 = *(int *)(Globals::layout + 0x2c);
    iVar15 = *(int *)(Globals::layout + 0x4c);
    iVar26 = *(int *)(this + 0x6c);
    uVar13 = Status::getKills(Globals::status);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,(((iVar26 >> 1) - iVar25) - iVar15) - iVar21,
               *(int *)(Globals::layout + 4) + local_e8,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x228);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),
               local_e8 + *(int *)(Globals::layout + 4) * 2,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::Canvas,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x2c);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::font,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,(((iVar15 >> 1) - iVar26) - iVar25) - iVar21,
               local_e8 + *(int *)(Globals::layout + 4) * 2,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x22f);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),
               *(int *)(Globals::layout + 4) * 3 + local_e8,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    uVar13 = Status::getCapturedCrates(Globals::status);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar25 = *(int *)(Globals::layout + 0x2c);
    iVar15 = *(int *)(Globals::layout + 0x4c);
    iVar26 = *(int *)(this + 0x6c);
    uVar13 = Status::getCapturedCrates(Globals::status);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,(((iVar26 >> 1) - iVar25) - iVar15) - iVar21,
               *(int *)(Globals::layout + 4) * 3 + local_e8,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x22d);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),
               local_e8 + *(int *)(Globals::layout + 4) * 4,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    uVar13 = Status::getStationsVisited(Globals::status);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar25 = *(int *)(Globals::layout + 0x2c);
    iVar15 = *(int *)(Globals::layout + 0x4c);
    iVar26 = *(int *)(this + 0x6c);
    uVar13 = Status::getStationsVisited(Globals::status);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,(((iVar26 >> 1) - iVar25) - iVar15) - iVar21,
               local_e8 + *(int *)(Globals::layout + 4) * 4,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0xca3);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),
               *(int *)(Globals::layout + 4) * 5 + local_e8,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::Canvas,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x2c);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::font,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,(((iVar15 >> 1) - iVar26) - iVar25) - iVar21,
               *(int *)(Globals::layout + 4) * 5 + local_e8,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x234);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0x4c),local_e8,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    uVar13 = Status::getJumpgateUsed(Globals::status);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    uVar13 = Status::getJumpgateUsed(Globals::status);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,((iVar15 + iVar26) - iVar25) - iVar21,local_e8,false
              );
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x22e);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0x4c),
               *(int *)(Globals::layout + 4) + local_e8,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    uVar13 = Status::getGoodsProduced(Globals::status);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    uVar13 = Status::getGoodsProduced(Globals::status);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar13,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,((iVar15 + iVar26) - iVar25) - iVar21,
               *(int *)(Globals::layout + 4) + local_e8,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x230);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0x4c),
               local_e8 + *(int *)(Globals::layout + 4) * 2,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::Canvas,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::font,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,((iVar15 + iVar26) - iVar25) - iVar21,
               local_e8 + *(int *)(Globals::layout + 4) * 2,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x231);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0x4c),
               *(int *)(Globals::layout + 4) * 3 + local_e8,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::Canvas,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::font,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,((iVar15 + iVar26) - iVar25) - iVar21,
               *(int *)(Globals::layout + 4) * 3 + local_e8,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    pSVar12 = (String *)GameText::getText(Globals::gameText,0x237);
    AbyssEngine::operator+((AbyssEngine *)local_6c,pSVar12,aSStack_4c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,
               *(int *)(Globals::layout + 0x28) + (*(int *)(this + 0x6c) >> 1) +
               *(int *)(Globals::layout + 0x2c) + *(int *)(Globals::layout + 0x4c),
               local_e8 + *(int *)(Globals::layout + 4) * 4,false);
    AbyssEngine::String::~String((String *)local_6c);
    uVar20 = Globals::font;
    pPVar1 = Globals::Canvas;
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::Canvas,local_6c));
    uVar3 = Globals::font;
    pPVar2 = Globals::Canvas;
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = *(int *)(Globals::layout + 0x28);
    iVar25 = *(int *)(Globals::layout + 0x4c);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(&Globals::font,local_74));
    iVar21 = AbyssEngine::PaintCanvas::GetTextWidth(pPVar2,uVar3,(String *)local_74);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar20,(String *)local_6c,((iVar15 + iVar26) - iVar25) - iVar21,
               local_e8 + *(int *)(Globals::layout + 4) * 4,false);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    AbyssEngine::String::~String(aSStack_64);
    iVar21 = *(int *)(this + 0x30);
    cVar6 = Globals::iPad;
  }
  else {
    cVar6 = '\0';
  }
  pLVar5 = Globals::layout;
  if ((cVar6 != '\0') || (iVar21 == 1)) {
    iVar15 = *(int *)(this + 0x6c);
    iVar26 = iVar15 / 3 + (iVar15 >> 0x1f);
    iVar25 = *(int *)(Globals::layout + 0x28);
    iVar21 = iVar26 / 2;
    if (cVar6 == '\0') {
      iVar16 = *(int *)(Globals::layout + 0xc);
    }
    else {
      iVar16 = *(int *)(Globals::layout + 0xc);
      iVar21 = iVar15 + iVar21;
      local_e8 = *(int *)(Globals::layout + 0x20) + iVar16 + *(int *)(this + 0x38);
    }
    iVar19 = *(int *)(this + 0x78);
    iVar16 = iVar16 + (iVar19 >> 1) + *(int *)(Globals::layout + 0x2c);
    if (cVar6 != '\0') {
      uVar17 = *(undefined4 *)(Globals::layout + 0x1c);
      pSVar12 = (String *)GameText::getText(Globals::gameText,0xa8);
      uVar13 = AbyssEngine::String::String(aSStack_c8,pSVar12,false);
      Layout::drawBox(pLVar5,0,iVar15 + iVar25 * 2,local_e8,iVar15 + iVar25,uVar17,uVar13);
      AbyssEngine::String::~String(aSStack_c8);
      iVar16 = *(int *)(Globals::layout + 0x1c) + iVar16 + *(int *)(Globals::layout + 0x2c);
    }
    if (0 < *(int *)this) {
      iVar23 = 0;
      do {
        iVar22 = (iVar23 / 3) * iVar19 + iVar16 + *(int *)(this + 0x38);
        TouchButton::setPosition
                  (*(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + iVar23 * 4),
                   (iVar23 % 3) * (iVar26 - (iVar15 >> 0x1f)) + iVar21 + iVar25,iVar22);
        if ((-1 < iVar22) && (iVar22 <= Globals::h)) {
          TouchButton::draw(*(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + iVar23 * 4));
        }
        iVar23 = iVar23 + 1;
      } while (iVar23 < *(int *)this);
    }
    if (-1 < *(int *)(this + 0x34)) {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      iVar21 = Globals::h;
      pLVar5 = Globals::layout;
      uVar18 = *(undefined4 *)(this + 0x6c);
      iVar26 = **(int **)(this + 0x10);
      uVar13 = *(undefined4 *)(Globals::layout + 0x28);
      iVar15 = *(int *)(Globals::layout + 4);
      iVar16 = *(int *)(Globals::layout + 0x10);
      iVar19 = *(int *)(Globals::layout + 0x24);
      iVar25 = *(int *)(Globals::layout + 0x4c);
      uVar17 = AbyssEngine::String::String(aSStack_d0,"",false);
      Layout::drawBox(pLVar5,2,uVar13,(((iVar21 - iVar16) - iVar19) - iVar15 * iVar26) + iVar25 * -2
                      ,uVar18,iVar25 * 2 + iVar15 * iVar26,uVar17);
      AbyssEngine::String::~String(aSStack_d0);
      iVar21 = Globals::h;
      pLVar5 = Globals::layout;
      uVar18 = *(undefined4 *)(this + 0x6c);
      iVar26 = **(int **)(this + 0x10);
      uVar13 = *(undefined4 *)(Globals::layout + 0x28);
      iVar15 = *(int *)(Globals::layout + 4);
      iVar16 = *(int *)(Globals::layout + 0x10);
      iVar19 = *(int *)(Globals::layout + 0x24);
      iVar25 = *(int *)(Globals::layout + 0x4c);
      uVar17 = AbyssEngine::String::String(aSStack_d8,"",false);
      Layout::drawBox(pLVar5,5,uVar13,(((iVar21 - iVar16) - iVar19) - iVar15 * iVar26) + iVar25 * -2
                      ,uVar18,iVar25 * 2 + iVar15 * iVar26,uVar17);
      AbyssEngine::String::~String(aSStack_d8);
      Globals::drawLines(Globals::globals,Globals::font,*(Array **)(this + 0x10),
                         *(int *)(Globals::layout + 0x4c) + *(int *)(Globals::layout + 0x28),
                         (((Globals::h - *(int *)(Globals::layout + 0x10)) -
                          *(int *)(Globals::layout + 0x24)) - *(int *)(Globals::layout + 0x2c)) -
                         *(int *)(Globals::layout + 4) * *(int *)*(Array **)(this + 0x10),false);
    }
  }
  pLVar5 = Globals::layout;
  pSVar12 = (String *)GameText::getText(Globals::gameText,0xa9);
  AbyssEngine::String::String(aSStack_e0,pSVar12,false);
  Layout::drawHeader(pLVar5,aSStack_e0);
  AbyssEngine::String::~String(aSStack_e0);
  Layout::drawFooter(Globals::layout);
  if ((Globals::iPad == '\0') && (puVar14 = *(uint **)(this + 4), *puVar14 != 0)) {
    uVar20 = 0;
    do {
      TouchButton::draw(*(TouchButton **)(puVar14[1] + uVar20 * 4));
      puVar14 = *(uint **)(this + 4);
      uVar20 = uVar20 + 1;
    } while (uVar20 < *puVar14);
  }
  AbyssEngine::String::~String(aSStack_4c);
  AbyssEngine::String::~String(aSStack_44);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StatusWindow::getMedalHintText  @0x00185da4  (1050 bytes)
/* StatusWindow::getMedalHintText(int) */

void StatusWindow::getMedalHintText(int param_1)

{
  GameText *pGVar1;
  int iVar2;
  String *pSVar3;
  int iVar4;
  uint *puVar5;
  int in_r2;
  uint uVar6;
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar2 = Achievements::getMedals(Globals::achievements);
  iVar2 = *(int *)(iVar2 + in_r2 * 4);
  AbyssEngine::String::String((String *)param_1);
  if (iVar2 != 0) {
    if (in_r2 == 2 && iVar2 == 2) {
      AbyssEngine::String::String(aSStack_38,"\n\n",false);
      pSVar3 = (String *)GameText::getText(Globals::gameText,0x114);
      AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
      AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
      AbyssEngine::String::~String((String *)aAStack_30);
      AbyssEngine::String::~String(aSStack_38);
      puVar5 = *(uint **)(Globals::status + 0x94);
      if (*puVar5 != 0) {
        uVar6 = 0;
        iVar2 = Globals::status;
        do {
          if (*(char *)(puVar5[1] + uVar6) == '\0') {
            AbyssEngine::String::String(aSStack_38,"\n- ",false);
            pSVar3 = (String *)GameText::getText(Globals::gameText,uVar6 + 0x594);
            AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
            AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
            AbyssEngine::String::~String((String *)aAStack_30);
            AbyssEngine::String::~String(aSStack_38);
            iVar2 = Globals::status;
          }
          puVar5 = *(uint **)(iVar2 + 0x94);
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar5);
      }
    }
    else if (in_r2 == 3 && iVar2 == 2) {
      AbyssEngine::String::String(aSStack_38,"\n\n",false);
      pSVar3 = (String *)GameText::getText(Globals::gameText,0x114);
      AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
      AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
      AbyssEngine::String::~String((String *)aAStack_30);
      AbyssEngine::String::~String(aSStack_38);
      puVar5 = *(uint **)(Globals::status + 0x98);
      if (*puVar5 != 0) {
        uVar6 = 0;
        iVar2 = Globals::status;
        do {
          if (*(char *)(puVar5[1] + uVar6) == '\0') {
            AbyssEngine::String::String(aSStack_38,"\n- ",false);
            pSVar3 = (String *)GameText::getText(Globals::gameText,uVar6 + 0x59f);
            AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
            AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
            AbyssEngine::String::~String((String *)aAStack_30);
            AbyssEngine::String::~String(aSStack_38);
            iVar2 = Globals::status;
          }
          puVar5 = *(uint **)(iVar2 + 0x98);
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar5);
      }
    }
    else if (in_r2 == 9 && iVar2 == 2) {
      AbyssEngine::String::String(aSStack_38,"\n\n",false);
      pSVar3 = (String *)GameText::getText(Globals::gameText,0x114);
      AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
      AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
      AbyssEngine::String::~String((String *)aAStack_30);
      AbyssEngine::String::~String(aSStack_38);
      puVar5 = *(uint **)(Globals::status + 0xac);
      if (*puVar5 != 0) {
        uVar6 = 0;
        iVar2 = Globals::status;
        do {
          if (*(char *)(puVar5[1] + uVar6) == '\0') {
            AbyssEngine::String::String(aSStack_38,"\n- ",false);
            pSVar3 = (String *)GameText::getText(Globals::gameText,uVar6 + 0x57e);
            AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
            AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
            AbyssEngine::String::~String((String *)aAStack_30);
            AbyssEngine::String::~String(aSStack_38);
            iVar2 = Globals::status;
          }
          puVar5 = *(uint **)(iVar2 + 0xac);
          uVar6 = uVar6 + 1;
        } while (uVar6 < *puVar5);
      }
    }
    else if (in_r2 == 0xd && iVar2 == 2) {
      AbyssEngine::String::String(aSStack_38,"\n\n",false);
      pSVar3 = (String *)GameText::getText(Globals::gameText,0x114);
      AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
      AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
      AbyssEngine::String::~String((String *)aAStack_30);
      AbyssEngine::String::~String(aSStack_38);
      iVar2 = 0;
      do {
        if (*(char *)(*(int *)(*(int *)(*(int *)(Globals::status + 0x18) + 4) + iVar2 * 4) + 8) ==
            '\0') {
          AbyssEngine::String::String(aSStack_38,"\n- ",false);
          pGVar1 = Globals::gameText;
          iVar4 = BluePrint::getIndex(*(BluePrint **)
                                       (*(int *)(*(int *)(Globals::status + 0x18) + 4) + iVar2 * 4))
          ;
          pSVar3 = (String *)GameText::getText(pGVar1,iVar4 + 0x4fa);
          AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
          AbyssEngine::String::operator+=((String *)param_1,(String *)aAStack_30);
          AbyssEngine::String::~String((String *)aAStack_30);
          AbyssEngine::String::~String(aSStack_38);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0xd);
    }
    else if (in_r2 == 0xe && iVar2 == 2) {
      AbyssEngine::String::String(aSStack_38,"\n\n",false);
      pSVar3 = (String *)GameText::getText(Globals::gameText,0x114);
      AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
      AbyssEngine::String::operator+=((String *)param_1,aAStack_30);
      AbyssEngine::String::~String((String *)aAStack_30);
      AbyssEngine::String::~String(aSStack_38);
      iVar2 = 0;
      do {
        if (*(int *)(*(int *)(*(int *)(*(int *)(Globals::status + 0x18) + 4) + iVar2 * 4) + 0xc) ==
            0) {
          AbyssEngine::String::String(aSStack_38,"\n- ",false);
          pGVar1 = Globals::gameText;
          iVar4 = BluePrint::getIndex(*(BluePrint **)
                                       (*(int *)(*(int *)(Globals::status + 0x18) + 4) + iVar2 * 4))
          ;
          pSVar3 = (String *)GameText::getText(pGVar1,iVar4 + 0x4fa);
          AbyssEngine::operator+(aAStack_30,aSStack_38,pSVar3);
          AbyssEngine::String::operator+=((String *)param_1,(String *)aAStack_30);
          AbyssEngine::String::~String((String *)aAStack_30);
          AbyssEngine::String::~String(aSStack_38);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0xd);
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StatusWindow::OnTouchBegin  @0x0018629c  (172 bytes)
/* StatusWindow::OnTouchBegin(int, int) */

undefined4 __thiscall StatusWindow::OnTouchBegin(StatusWindow *this,int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  *(int *)(this + 0x3c) = param_2;
  *(int *)(this + 0x50) = param_2;
  *(undefined4 *)(this + 0x44) = 0;
  this[0x54] = (StatusWindow)0x1;
  Layout::OnTouchBegin(Globals::layout,param_1,param_2);
  if ((Globals::iPad == '\0') && (puVar1 = *(uint **)(this + 4), *puVar1 != 0)) {
    uVar4 = 0;
    do {
      TouchButton::OnTouchBegin(*(TouchButton **)(puVar1[1] + uVar4 * 4),param_1,param_2);
      puVar1 = *(uint **)(this + 4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  if ((*(int *)(this + 0x30) == 1) &&
     (iVar2 = Achievements::getMedals(Globals::achievements), 0 < *(int *)this)) {
    iVar5 = 0;
    do {
      if ((*(int *)(iVar2 + iVar5 * 4) != 0) ||
         (iVar3 = Achievements::isEliteMedal(Globals::achievements,iVar5), iVar3 == 1)) {
        TouchButton::OnTouchBegin
                  (*(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + iVar5 * 4),param_1,param_2);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)this);
  }
  return 0;
}

// ===== StatusWindow::OnTouchMove  @0x00186358  (266 bytes)
/* StatusWindow::OnTouchMove(int, int) */

undefined4 __thiscall StatusWindow::OnTouchMove(StatusWindow *this,int param_1,int param_2)

{
  Layout *this_00;
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  this_00 = Globals::layout;
  if (((*(int *)(Globals::layout + 0xc) < param_2) &&
      (param_2 < Globals::h - *(int *)(Globals::layout + 0x10))) || (Globals::mouse_wheel != 0)) {
    iVar3 = *(int *)(this + 0x3c);
    *(int *)(this + 0x44) = param_2 - iVar3;
    *(int *)(this + 0x3c) = param_2;
    *(undefined4 *)(this + 0x48) = 0x3f800000;
    *(int *)(this + 0x38) = (param_2 - iVar3) + *(int *)(this + 0x38);
    if (-1 < *(int *)(this + 0x34)) {
      iVar3 = *(int *)(this + 0x50) - param_2;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if (3 < iVar3) {
        TouchButton::setAlwaysPressed
                  (*(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + *(int *)(this + 0x34) * 4),
                   false);
        *(undefined4 *)(this + 0x34) = 0xffffffff;
        this_00 = Globals::layout;
      }
    }
  }
  Layout::OnTouchMove(this_00,param_1,param_2);
  if ((Globals::iPad == '\0') && (puVar1 = *(uint **)(this + 4), *puVar1 != 0)) {
    uVar4 = 0;
    do {
      TouchButton::OnTouchMove(*(TouchButton **)(puVar1[1] + uVar4 * 4),param_1,param_2);
      puVar1 = *(uint **)(this + 4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar1);
  }
  if ((*(int *)(this + 0x30) == 1) &&
     (iVar3 = Achievements::getMedals(Globals::achievements), 0 < *(int *)this)) {
    iVar5 = 0;
    do {
      if ((*(int *)(iVar3 + iVar5 * 4) != 0) ||
         (iVar2 = Achievements::isEliteMedal(Globals::achievements,iVar5), iVar2 == 1)) {
        TouchButton::OnTouchMove
                  (*(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + iVar5 * 4),param_1,param_2);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)this);
  }
  return 0;
}

// ===== StatusWindow::OnTouchEnd  @0x00186484  (700 bytes)
/* StatusWindow::OnTouchEnd(int, int) */

void __thiscall StatusWindow::OnTouchEnd(StatusWindow *this,int param_1,int param_2)

{
  undefined1 *puVar1;
  Layout *pLVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  String *pSVar10;
  int iVar11;
  uint uVar12;
  void *pvVar13;
  uint in_fpscr;
  undefined4 uVar14;
  String aSStack_58 [8];
  String aSStack_50 [8];
  undefined4 local_48 [2];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar3 = *(int *)(this + 0x44);
  uVar14 = VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
  iVar11 = iVar3;
  if (iVar3 < 0) {
    iVar11 = -iVar3;
  }
  uVar9 = 0;
  if (3 < iVar11) {
    uVar9 = uVar14;
  }
  *(undefined4 *)(this + 0x4c) = uVar9;
  *(undefined4 *)(this + 0x48) = 0x3f666666;
  this[0x54] = (StatusWindow)0x0;
  iVar11 = *(int *)(this + 0x38);
  *(int *)(this + 0x38) = iVar3 + iVar11;
  *(int *)(this + 0x40) = iVar3 + iVar11;
  iVar11 = Layout::OnTouchEnd(Globals::layout,param_1,param_2);
  if (iVar11 != 0) {
    uVar14 = 1;
    goto LAB_00186728;
  }
  if ((Globals::iPad == '\0') && (puVar4 = *(uint **)(this + 4), *puVar4 != 0)) {
    uVar12 = 0;
    do {
      iVar11 = TouchButton::OnTouchEnd(*(TouchButton **)(puVar4[1] + uVar12 * 4),param_1,param_2);
      if (iVar11 == 1) {
        *(uint *)(this + 0x30) = uVar12;
        *(undefined4 *)(this + 0x58) = *(undefined4 *)(*(int *)(this + 0x68) + uVar12 * 4);
        *(undefined4 *)(this + 0x38) = 0;
      }
      puVar4 = *(uint **)(this + 4);
      uVar12 = uVar12 + 1;
    } while (uVar12 < *puVar4);
  }
  if ((*(int *)(this + 0x30) == 1) && (0 < *(int *)this)) {
    iVar11 = 0;
    do {
      iVar3 = TouchButton::OnTouchEnd
                        (*(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + iVar11 * 4),param_1,
                         param_2);
      if (iVar3 == 1) {
        iVar5 = Achievements::getMedals(Globals::achievements);
        iVar6 = Achievements::isEliteMedal(Globals::achievements,iVar11);
        iVar3 = iVar6;
        if (iVar6 == 0) {
          iVar3 = *(int *)(iVar5 + iVar11 * 4);
        }
        if (iVar6 != 0 || iVar3 != 0) {
          if (-1 < *(int *)(this + 0x34)) {
            TouchButton::setAlwaysPressed
                      (*(TouchButton **)
                        (*(int *)(*(int *)(this + 8) + 4) + *(int *)(this + 0x34) * 4),false);
          }
          *(int *)(this + 0x34) = iVar11;
          if (*(Array **)(this + 0x10) != (Array *)0x0) {
            ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 0x10));
            pvVar13 = *(void **)(this + 0x10);
            if (pvVar13 != (void *)0x0) {
              if (*(void **)((int)pvVar13 + 4) != (void *)0x0) {
                operator_delete__(*(void **)((int)pvVar13 + 4));
              }
              operator_delete(pvVar13);
            }
          }
          *(undefined4 *)(this + 0x10) = 0;
          puVar7 = operator_new(0xc);
          puVar8 = operator_new__(4);
          iVar3 = 1;
          puVar7[1] = puVar8;
          *puVar8 = 0;
          puVar7[2] = 1;
          *puVar7 = 0;
          *(undefined4 **)(this + 0x10) = puVar7;
          uVar14 = Globals::status;
          if (iVar6 == 0) {
            iVar3 = *(int *)(iVar5 + *(int *)(this + 0x34) * 4);
          }
          pSVar10 = (String *)GameText::getText(Globals::gameText,*(int *)(this + 0x34) + 0x610);
          AbyssEngine::String::String(aSStack_38,pSVar10,false);
          uVar9 = Achievements::getValue(Globals::achievements,*(int *)(this + 0x34),iVar3);
          local_48[0] = 0;
          AbyssEngine::String::Set(CONCAT44(uVar9,local_48));
          AbyssEngine::String::String(aSStack_40,(String *)local_48,false);
          Status::replaceHash(aSStack_30,uVar14,aSStack_38,aSStack_40);
          AbyssEngine::String::~String(aSStack_40);
          AbyssEngine::String::~String((String *)local_48);
          AbyssEngine::String::~String(aSStack_38);
          getMedalHintText((int)local_48);
          AbyssEngine::String::operator+=(aSStack_30,(String *)local_48);
          AbyssEngine::String::~String((String *)local_48);
          Globals::getLineArray
                    (Globals::globals,Globals::font,aSStack_30,
                     *(int *)(this + 0x6c) + *(int *)(Globals::layout + 0x4c) * -2,
                     *(Array **)(this + 0x10));
          TouchButton::setAlwaysPressed
                    (*(TouchButton **)(*(int *)(*(int *)(this + 8) + 4) + iVar11 * 4),true);
          AbyssEngine::String::~String(aSStack_30);
        }
        break;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)this);
  }
  iVar11 = Layout::helpPressed(Globals::layout);
  pLVar2 = Globals::layout;
  if (iVar11 == 1) {
    if (*(int *)(this + 0x30) == 1) {
      pSVar10 = (String *)GameText::getText(Globals::gameText,0x287);
      AbyssEngine::String::String(aSStack_58,pSVar10,false);
      Layout::initHelpWindow(pLVar2,aSStack_58);
      puVar1 = &stack0xffffffe4;
    }
    else {
      if (*(int *)(this + 0x30) != 0) goto LAB_00186726;
      pSVar10 = (String *)GameText::getText(Globals::gameText,0x280);
      AbyssEngine::String::String(aSStack_50,pSVar10,false);
      Layout::initHelpWindow(pLVar2,aSStack_50);
      puVar1 = &stack0xffffffec;
    }
    AbyssEngine::String::~String((String *)(puVar1 + -0x3c));
  }
LAB_00186726:
  uVar14 = 0;
LAB_00186728:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar14);
}

