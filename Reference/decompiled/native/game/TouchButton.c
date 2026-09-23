// Class: TouchButton
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== TouchButton::TouchButton  @0x00196154  (122 bytes)
/* TouchButton::TouchButton(AbyssEngine::String const&, int, int, int, unsigned char) */

TouchButton * __thiscall
TouchButton::TouchButton
          (TouchButton *this,String *param_1,int param_2,int param_3,int param_4,uchar param_5)

{
  uint uVar1;
  undefined4 uVar2;
  
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x24));
  uVar1 = Globals::font;
  *(uint *)(this + 8) = Globals::font;
  uVar2 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,uVar1);
  *(undefined4 *)(this + 0xb8) = uVar2;
  init(this,param_1,0xffffffff,param_2,-1,-1,param_3,param_4,0,param_5,'D');
  return this;
}

// ===== TouchButton::init  @0x001961f8  (1694 bytes)
/* TouchButton::init(AbyssEngine::String const&, unsigned int, int, int, int, int, int, int,
   unsigned char, unsigned char) */

void __thiscall
TouchButton::init(TouchButton *this,String *param_1,uint param_2,int param_3,int param_4,int param_5
                 ,int param_6,int param_7,int param_8,uchar param_9,uchar param_10)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined *puVar7;
  TouchButton *pTVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  float fVar11;
  String aSStack_3c [8];
  int local_34;
  
  local_34 = __stack_chk_guard;
  *(int *)(this + 100) = param_3;
  *(undefined2 *)(this + 0xa6) = 1;
  AbyssEngine::String::operator=((String *)(this + 0xc),param_1);
  *(uint *)(this + 0x1c) = param_2;
  *(undefined4 *)(this + 0xa0) = 0xffffffff;
  *(int *)(this + 0x60) = param_8;
  this[0x69] = (TouchButton)param_10;
  this[0x68] = (TouchButton)param_9;
  this[0xa4] = (TouchButton)0x0;
  this[0xa5] = (TouchButton)0x0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  pTVar8 = this + 0x7c;
  *(undefined4 *)pTVar8 = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  this[0xac] = (TouchButton)0x1;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(int *)(this + 0x74) = param_6;
  *(int *)(this + 0x78) = param_7;
  AbyssEngine::String::String(aSStack_3c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x24),aSStack_3c);
  AbyssEngine::String::~String(aSStack_3c);
  AbyssEngine::String::String(aSStack_3c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x14),aSStack_3c);
  AbyssEngine::String::~String(aSStack_3c);
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  switch(param_3) {
  case 10:
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,9000,(uint *)(this + 0x3c));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x2329,(uint *)(this + 0x30));
    *(undefined4 *)(this + 0x48) = *(undefined4 *)(this + 0x30);
    uVar3 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x3c));
    *(undefined4 *)(this + 0x7c) = uVar3;
    iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x3c));
    *(int *)(this + 0x84) = iVar2;
    *(int *)(this + 0x88) = iVar2;
    *(undefined4 *)(this + 0x80) = *(undefined4 *)(this + 0x7c);
    iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,*(uint *)(this + 8),param_1);
    *(int *)(this + 0x98) = iVar2 / 2 - iVar4 / 2;
    uVar3 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,*(uint *)(this + 8));
    *(undefined4 *)(this + 0x9c) = uVar3;
    *(undefined4 *)(this + 0xb4) = *(undefined4 *)(Globals::layout + 0x80);
    goto LAB_001964b6;
  case 0xb:
  case 0xe:
  case 0xf:
  case 0x11:
  case 0x12:
    break;
  case 0xc:
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x472,(uint *)(this + 0x3c));
    uVar1 = 0x473;
    goto LAB_0019643e;
  case 0xd:
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x517,(uint *)(this + 0x3c));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x518,(uint *)(this + 0x30));
    *(undefined4 *)(this + 0x48) = *(undefined4 *)(this + 0x30);
    goto LAB_00196442;
  case 0x10:
    *(uint *)(this + 0x3c) = param_2;
    uVar1 = 0xbb9;
LAB_0019643e:
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar1,(uint *)(this + 0x30));
LAB_00196442:
    uVar6 = *(uint *)(this + 0x3c);
LAB_00196458:
    uVar3 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,uVar6);
    *(undefined4 *)(this + 0x7c) = uVar3;
    iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x3c));
    *(int *)(this + 0x88) = iVar2;
    *(int *)(this + 0x84) = iVar2;
    *(undefined4 *)(this + 0x80) = *(undefined4 *)(this + 0x7c);
    iVar4 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,param_2);
    *(int *)(this + 0x98) = iVar2 / 2 - iVar4 / 2;
    iVar4 = *(int *)(this + 0x7c);
    iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,param_2);
    *(int *)(this + 0x9c) = iVar4 / 2 - iVar2 / 2;
    goto LAB_001964b6;
  case 0x13:
    *(uint *)(this + 0x3c) = param_2;
    *(undefined4 *)(this + 0x30) = *(undefined4 *)(this + 0x20);
    uVar6 = param_2;
    goto LAB_00196458;
  default:
    if (param_3 == 4) {
      iVar2 = Achievements::isEliteMedal(Globals::achievements,param_4);
      if (iVar2 == 1) {
        puVar5 = (undefined4 *)&DAT_00252030;
        puVar7 = &DAT_00252050;
      }
      else {
        puVar5 = &DAT_00252040;
        puVar7 = &DAT_00252060;
      }
      *(undefined4 *)(this + 0xa8) = *(undefined4 *)(puVar7 + param_5 * 4);
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(puVar5 + param_5),(uint *)(this + 0x54));
      uVar3 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x54));
      *(undefined4 *)(this + 0x7c) = uVar3;
      iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x54));
      *(int *)(this + 0x84) = iVar2;
      *(int *)(this + 0x88) = iVar2;
      *(int *)(this + 0x80) = *(int *)(this + 0x7c);
      *(int *)(this + 0x9c) = *(int *)(this + 0x7c) + 5;
      iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,*(uint *)(this + 8),param_1);
      *(int *)(this + 0x98) = iVar2 / 2 - iVar4 / 2;
      *(uint *)(this + 0x5c) = 0xffffffff;
      *(uint *)(this + 0x58) = 0xffffffff;
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c7dc + param_4 * 4),(uint *)(this + 0x5c));
      if ((param_5 != 0) ||
         (iVar2 = Achievements::isEliteMedal(Globals::achievements,param_4), iVar2 == 1)) {
        AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x96c,(uint *)(this + 0x58));
      }
      goto LAB_001964b6;
    }
  }
  switch(param_3) {
  case 0xe:
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x53c,(uint *)(this + 0x3c));
    uVar1 = 0x53b;
    break;
  case 0xf:
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x53e,(uint *)(this + 0x3c));
    uVar1 = 0x53d;
    break;
  default:
    if (Globals::iPad == '\0') {
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cb84 + param_3 * 0x24),(uint *)(this + 0x3c));
      iVar2 = param_3 * 0x24;
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cb88 + iVar2),(uint *)(this + 0x40));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cb8c + iVar2),(uint *)(this + 0x44));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cb90 + iVar2),(uint *)(this + 0x30));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cb94 + iVar2),(uint *)(this + 0x34));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cb98 + iVar2),(uint *)(this + 0x38));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cb9c + iVar2),(uint *)(this + 0x48));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025cba0 + iVar2),(uint *)(this + 0x4c));
      uVar1 = *(ushort *)(&DAT_0025cba4 + iVar2);
    }
    else {
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c890 + param_3 * 0x24),(uint *)(this + 0x3c));
      iVar2 = param_3 * 0x24;
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c894 + iVar2),(uint *)(this + 0x40));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c898 + iVar2),(uint *)(this + 0x44));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c89c + iVar2),(uint *)(this + 0x30));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c8a0 + iVar2),(uint *)(this + 0x34));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c8a4 + iVar2),(uint *)(this + 0x38));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c8a8 + iVar2),(uint *)(this + 0x48));
      AbyssEngine::PaintCanvas::Image2DCreate
                (Globals::Canvas,*(ushort *)(&DAT_0025c8ac + iVar2),(uint *)(this + 0x4c));
      uVar1 = *(ushort *)(&DAT_0025c8b0 + iVar2);
    }
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar1,(uint *)(this + 0x50));
    uVar3 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x30));
    *(undefined4 *)(this + 0x7c) = uVar3;
    uVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x30));
    *(undefined4 *)(this + 0x88) = uVar3;
    uVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x34));
    *(undefined4 *)(this + 0x8c) = uVar3;
    iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x38));
    *(int *)(this + 0x90) = iVar2;
    if (param_3 != 0xb) {
      pTVar8 = (TouchButton *)(Globals::layout + 0x30);
    }
    *(undefined4 *)(this + 0x80) = *(undefined4 *)pTVar8;
    if (((uint)param_3 < 7) && ((1 << (param_3 & 0xffU) & 0x61U) != 0)) {
      *(int *)(this + 0x90) = iVar2 + -2;
    }
    if ((param_3 - 7U < 3) && (Globals::iPad != '\0')) {
      if (Globals::iPadHD == '\0') {
        uVar3 = 0x32;
        if (Globals::iPadLarge != '\0') {
          uVar3 = 100;
        }
      }
      else {
        uVar3 = 0x46;
      }
      *(undefined4 *)(this + 0x80) = uVar3;
    }
    setText(this,param_1);
    goto LAB_001964b6;
  case 0x11:
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbc0,(uint *)(this + 0x3c));
    uVar1 = 0xbc1;
    break;
  case 0x12:
  case 0x14:
    if (param_3 == 0x14) {
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f6e,(uint *)(this + 0x3c));
      uVar1 = 0x1f6f;
    }
    else {
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0xbc0,(uint *)(this + 0x3c));
      uVar1 = 0xbc1;
    }
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar1,(uint *)(this + 0x30));
    goto LAB_001966d2;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar1,(uint *)(this + 0x30));
LAB_001966d2:
  uVar1 = GameText::getLanguage();
  uVar6 = (uint)uVar1;
  if ((uVar6 < 0x10) && ((1 << (uVar6 & 0xff) & 0x8c00U) != 0)) {
    fVar11 = 1.0;
  }
  else {
    fVar11 = 1.5;
    if (uVar6 == 0xe) {
      fVar11 = 1.0;
    }
  }
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(this + 0x30);
  uVar3 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x3c));
  *(undefined4 *)(this + 0x7c) = uVar3;
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x3c));
  *(int *)(this + 0x84) = iVar2;
  *(int *)(this + 0x88) = iVar2;
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(this + 0x7c);
  iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,*(uint *)(this + 8),param_1);
  *(int *)(this + 0x98) = iVar2 / 2 - iVar4 / 2;
  iVar2 = *(int *)(this + 0x7c);
  uVar3 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,*(uint *)(this + 8));
  fVar9 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  fVar10 = (float)VectorSignedToFloat(iVar2 / 2,(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x9c) = (int)(fVar10 + fVar11 * fVar9);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(Globals::layout + 0x80);
LAB_001964b6:
  setPosition(this,param_6,param_7,param_9);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== TouchButton::TouchButton  @0x00196960  (166 bytes)
/* TouchButton::TouchButton(unsigned int, int, int, int, unsigned char) */

void __thiscall
TouchButton::TouchButton
          (TouchButton *this,uint param_1,int param_2,int param_3,int param_4,uchar param_5)

{
  uint uVar1;
  undefined4 uVar2;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x24));
  uVar1 = Globals::font;
  *(uint *)(this + 8) = Globals::font;
  uVar2 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,uVar1);
  *(undefined4 *)(this + 0xb8) = uVar2;
  AbyssEngine::String::String(aSStack_30,"",false);
  init(this,aSStack_30,param_1,param_2,-1,-1,param_3,param_4,0,param_5,'D');
  AbyssEngine::String::~String(aSStack_30);
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== TouchButton::TouchButton  @0x00196a48  (168 bytes)
/* TouchButton::TouchButton(unsigned int, unsigned int, int, int, int, unsigned char) */

void __thiscall
TouchButton::TouchButton
          (TouchButton *this,uint param_1,uint param_2,int param_3,int param_4,int param_5,
          uchar param_6)

{
  uint uVar1;
  undefined4 uVar2;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x24));
  uVar1 = Globals::font;
  *(uint *)(this + 8) = Globals::font;
  *(uint *)(this + 0x20) = param_2;
  uVar2 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,uVar1);
  *(undefined4 *)(this + 0xb8) = uVar2;
  AbyssEngine::String::String(aSStack_30,"",false);
  init(this,aSStack_30,param_1,param_3,-1,-1,param_4,param_5,0,param_6,'D');
  AbyssEngine::String::~String(aSStack_30);
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== TouchButton::TouchButton  @0x00196b34  (122 bytes)
/* TouchButton::TouchButton(AbyssEngine::String const&, int, int, int, int, unsigned char, unsigned
   char) */

TouchButton * __thiscall
TouchButton::TouchButton
          (TouchButton *this,String *param_1,int param_2,int param_3,int param_4,int param_5,
          uchar param_6,uchar param_7)

{
  uint uVar1;
  undefined4 uVar2;
  
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x24));
  uVar1 = Globals::font;
  *(uint *)(this + 8) = Globals::font;
  uVar2 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,uVar1);
  *(undefined4 *)(this + 0xb8) = uVar2;
  init(this,param_1,0xffffffff,param_2,-1,-1,param_3,param_4,param_5,param_6,param_7);
  return this;
}

// ===== TouchButton::TouchButton  @0x00196bd8  (162 bytes)
/* TouchButton::TouchButton(AbyssEngine::String const&, int, int, int, int, unsigned char, unsigned
   char, unsigned int, int) */

TouchButton * __thiscall
TouchButton::TouchButton
          (TouchButton *this,String *param_1,int param_2,int param_3,int param_4,int param_5,
          uchar param_6,uchar param_7,uint param_8,int param_9)

{
  short sVar1;
  
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x24));
  *(uint *)(this + 8) = param_8;
  *(int *)(this + 0xb8) = param_9;
  sVar1 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,param_8);
  AbyssEngine::PaintCanvas::FontSetSpacing(Globals::Canvas,param_8,(short)param_9);
  init(this,param_1,0xffffffff,param_2,-1,-1,param_3,param_4,param_5,param_6,param_7);
  AbyssEngine::PaintCanvas::FontSetSpacing(Globals::Canvas,param_8,sVar1);
  return this;
}

// ===== TouchButton::TouchButton  @0x00196cac  (164 bytes)
/* TouchButton::TouchButton(unsigned int, int, int, int, int, unsigned char, unsigned char) */

void __thiscall
TouchButton::TouchButton
          (TouchButton *this,uint param_1,int param_2,int param_3,int param_4,int param_5,
          uchar param_6,uchar param_7)

{
  uint uVar1;
  undefined4 uVar2;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x24));
  uVar1 = Globals::font;
  *(uint *)(this + 8) = Globals::font;
  uVar2 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,uVar1);
  *(undefined4 *)(this + 0xb8) = uVar2;
  AbyssEngine::String::String(aSStack_30,"",false);
  init(this,aSStack_30,param_1,param_2,-1,-1,param_3,param_4,param_5,param_6,param_7);
  AbyssEngine::String::~String(aSStack_30);
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== TouchButton::TouchButton  @0x00196d94  (120 bytes)
/* TouchButton::TouchButton(int, int, AbyssEngine::String const&, int, int, unsigned char) */

TouchButton * __thiscall
TouchButton::TouchButton
          (TouchButton *this,int param_1,int param_2,String *param_3,int param_4,int param_5,
          uchar param_6)

{
  uint uVar1;
  undefined4 uVar2;
  
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x24));
  uVar1 = Globals::font;
  *(uint *)(this + 8) = Globals::font;
  uVar2 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,uVar1);
  *(undefined4 *)(this + 0xb8) = uVar2;
  init(this,param_3,0xffffffff,4,param_1,param_2,param_4,param_5,0,param_6,'D');
  return this;
}

// ===== TouchButton::~TouchButton  @0x00196e38  (34 bytes)
/* TouchButton::~TouchButton() */

TouchButton * __thiscall TouchButton::~TouchButton(TouchButton *this)

{
  AbyssEngine::String::~String((String *)(this + 0x24));
  AbyssEngine::String::~String((String *)(this + 0x14));
  AbyssEngine::String::~String((String *)(this + 0xc));
  return this;
}

// ===== TouchButton::setText  @0x00196e5c  (256 bytes)
/* TouchButton::setText(AbyssEngine::String const&) */

void __thiscall TouchButton::setText(TouchButton *this,String *param_1)

{
  int iVar1;
  int iVar2;
  
  AbyssEngine::String::operator=((String *)(this + 0xc),param_1);
  iVar1 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,*(uint *)(this + 8),param_1);
  if (*(uint *)(this + 0x1c) != 0xffffffff) {
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x1c));
  }
  iVar2 = iVar1;
  if (0 < *(int *)(this + 0x60)) {
    iVar2 = (*(int *)(this + 0x60) - *(int *)(this + 0x88)) - *(int *)(this + 0x90);
  }
  *(int *)(this + 0x94) = iVar2;
  iVar2 = *(int *)(this + 0x88) + iVar2 + *(int *)(this + 0x90);
  *(int *)(this + 0x84) = iVar2;
  if (((byte)this[0x69] & 2) == 0) {
    if (((byte)this[0x69] & 1) == 0) {
      iVar1 = (iVar2 - iVar1) / 2;
      *(int *)(this + 0x98) = iVar1;
      if (*(int *)(this + 100) == 6) {
        iVar1 = iVar1 + -5;
      }
      else {
        if (*(int *)(this + 100) != 5) goto LAB_00196ef0;
        iVar1 = iVar1 + 5;
      }
    }
    else {
      iVar1 = *(int *)(this + 0x88);
    }
  }
  else {
    iVar1 = (iVar2 - iVar1) - *(int *)(this + 0x88);
  }
  *(int *)(this + 0x98) = iVar1;
LAB_00196ef0:
  iVar2 = *(int *)(this + 0x7c);
  iVar1 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,*(uint *)(this + 8));
  iVar1 = (iVar2 - iVar1) / 2;
  *(int *)(this + 0x9c) = iVar1;
  if (*(int *)(this + 100) == 3) {
    *(int *)(this + 0x9c) = iVar1 + 2;
  }
  if (*(uint *)(this + 0x1c) != 0xffffffff) {
    iVar2 = *(int *)(this + 0x7c);
    iVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x1c));
    *(int *)(this + 0x9c) = (iVar2 - iVar1) / 2;
    if (*(int *)(this + 100) == 1) {
      *(int *)(this + 0x98) = *(int *)(this + 0x98) + 3;
    }
  }
  setPosition(this,*(int *)(this + 0x74),*(int *)(this + 0x78),(uchar)this[0x68]);
  return;
}

// ===== TouchButton::setPosition  @0x00196f6c  (82 bytes)
/* TouchButton::setPosition(int, int, unsigned char) */

void __thiscall TouchButton::setPosition(TouchButton *this,int param_1,int param_2,uchar param_3)

{
  *(int *)(this + 0x6c) = param_1;
  *(int *)(this + 0x70) = param_2;
  this[0x68] = (TouchButton)param_3;
  if ((param_3 & 0x20) != 0) {
    param_2 = param_2 - *(int *)(this + 0x80);
    *(int *)(this + 0x70) = param_2;
  }
  if ((param_3 & 2) != 0) {
    param_1 = param_1 - *(int *)(this + 0x84);
    *(int *)(this + 0x6c) = param_1;
  }
  if ((param_3 & 0x40) != 0) {
    *(int *)(this + 0x70) = param_2 - *(int *)(this + 0x80) / 2;
  }
  if ((param_3 & 4) != 0) {
    *(int *)(this + 0x6c) = param_1 - *(int *)(this + 0x84) / 2;
  }
  return;
}

// ===== TouchButton::setNumberText  @0x00196fbe  (6 bytes)
/* TouchButton::setNumberText(AbyssEngine::String const&) */

void __thiscall TouchButton::setNumberText(TouchButton *this,String *param_1)

{
  AbyssEngine::String::operator=((String *)(this + 0x24),param_1);
  return;
}

// ===== TouchButton::setGamePadButtonImage  @0x00196fc4  (4 bytes)
/* TouchButton::setGamePadButtonImage(unsigned int) */

void __thiscall TouchButton::setGamePadButtonImage(TouchButton *this,uint param_1)

{
  *(uint *)(this + 0x2c) = param_1;
  return;
}

// ===== TouchButton::replaceTextKeepSize  @0x00196fc8  (66 bytes)
/* TouchButton::replaceTextKeepSize(AbyssEngine::String const&) */

void __thiscall TouchButton::replaceTextKeepSize(TouchButton *this,String *param_1)

{
  int iVar1;
  int iVar2;
  
  AbyssEngine::String::operator=((String *)(this + 0xc),param_1);
  if (*(int *)(this + 100) == 10) {
    iVar2 = *(int *)(this + 0x84);
    iVar1 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,*(uint *)(this + 8),param_1);
    *(int *)(this + 0x98) = iVar2 / 2 - iVar1 / 2;
  }
  return;
}

// ===== TouchButton::setSplitText  @0x00197010  (6 bytes)
/* TouchButton::setSplitText(AbyssEngine::String const&) */

void __thiscall TouchButton::setSplitText(TouchButton *this,String *param_1)

{
  AbyssEngine::String::operator=((String *)(this + 0x14),param_1);
  return;
}

// ===== TouchButton::getText  @0x00197016  (14 bytes)
/* TouchButton::getText() */

void TouchButton::getText(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0xc),false);
  return;
}

// ===== TouchButton::getWidth  @0x00197024  (6 bytes)
/* TouchButton::getWidth() */

undefined4 __thiscall TouchButton::getWidth(TouchButton *this)

{
  return *(undefined4 *)(this + 0x84);
}

// ===== TouchButton::getHeight  @0x0019702a  (4 bytes)
/* TouchButton::getHeight() */

undefined4 __thiscall TouchButton::getHeight(TouchButton *this)

{
  return *(undefined4 *)(this + 0x7c);
}

// ===== TouchButton::setPosition  @0x0019702e  (8 bytes)
/* TouchButton::setPosition(int, int) */

void __thiscall TouchButton::setPosition(TouchButton *this,int param_1,int param_2)

{
  setPosition(this,param_1,param_2,(uchar)this[0x68]);
  return;
}

// ===== TouchButton::setYPosition  @0x00197036  (14 bytes)
/* TouchButton::setYPosition(int) */

void __thiscall TouchButton::setYPosition(TouchButton *this,int param_1)

{
  setPosition(this,*(int *)(this + 0x6c),param_1,(uchar)this[0x68]);
  return;
}

// ===== TouchButton::getPosition  @0x00197042  (30 bytes)
/* TouchButton::getPosition() */

void TouchButton::getPosition(void)

{
  undefined4 *in_r0;
  int in_r1;
  uint in_fpscr;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x6c),(byte)(in_fpscr >> 0x16) & 3);
  uVar2 = VectorSignedToFloat(*(undefined4 *)(in_r1 + 0x70),(byte)(in_fpscr >> 0x16) & 3);
  in_r0[2] = 0;
  *in_r0 = uVar1;
  in_r0[1] = uVar2;
  return;
}

// ===== TouchButton::setHalfTransparent  @0x00197060  (6 bytes)
/* TouchButton::setHalfTransparent(bool) */

void __thiscall TouchButton::setHalfTransparent(TouchButton *this,bool param_1)

{
  this[0xa7] = (TouchButton)param_1;
  return;
}

// ===== TouchButton::setVisible  @0x00197066  (6 bytes)
/* TouchButton::setVisible(bool) */

void __thiscall TouchButton::setVisible(TouchButton *this,bool param_1)

{
  this[0xa6] = (TouchButton)param_1;
  return;
}

// ===== TouchButton::isVisible  @0x0019706c  (6 bytes)
/* TouchButton::isVisible() */

TouchButton __thiscall TouchButton::isVisible(TouchButton *this)

{
  return this[0xa6];
}

// ===== TouchButton::translate  @0x00197072  (14 bytes)
/* TouchButton::translate(int, int) */

void __thiscall TouchButton::translate(TouchButton *this,int param_1,int param_2)

{
  *(int *)(this + 0x6c) = param_1 + *(int *)(this + 0x6c);
  *(int *)(this + 0x70) = *(int *)(this + 0x70) + param_2;
  return;
}

// ===== TouchButton::setAlwaysPressed  @0x00197080  (6 bytes)
/* TouchButton::setAlwaysPressed(bool) */

void __thiscall TouchButton::setAlwaysPressed(TouchButton *this,bool param_1)

{
  this[0xa5] = (TouchButton)param_1;
  return;
}

// ===== TouchButton::setTextColor  @0x00197086  (6 bytes)
/* TouchButton::setTextColor(int) */

void __thiscall TouchButton::setTextColor(TouchButton *this,int param_1)

{
  *(int *)(this + 0xa0) = param_1;
  return;
}

// ===== TouchButton::setPressProgress  @0x0019708c  (6 bytes)
/* TouchButton::setPressProgress(float) */

void __thiscall TouchButton::setPressProgress(TouchButton *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xb0) = in_r1;
  return;
}

// ===== TouchButton::setPressProgressHighlight  @0x00197092  (6 bytes)
/* TouchButton::setPressProgressHighlight(bool) */

void __thiscall TouchButton::setPressProgressHighlight(TouchButton *this,bool param_1)

{
  this[0xac] = (TouchButton)param_1;
  return;
}

// ===== TouchButton::draw  @0x00197098  (1488 bytes)
/* TouchButton::draw() */

void __thiscall TouchButton::draw(TouchButton *this)

{
  ushort uVar1;
  byte bVar2;
  PaintCanvas *pPVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  TouchButton *pTVar8;
  int iVar9;
  int iVar10;
  TouchButton *pTVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint in_fpscr;
  float fVar16;
  float fVar17;
  
  AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  if ((*(ushort *)(this + 0xa6) & 0xff) == 0) {
    return;
  }
  if (*(ushort *)(this + 0xa6) < 0x100) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  else {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    Layout::setDrawColor(Globals::layout,-0xd1);
  }
  sVar4 = AbyssEngine::PaintCanvas::FontGetSpacing(Globals::Canvas,*(uint *)(this + 8));
  AbyssEngine::PaintCanvas::FontSetSpacing
            (Globals::Canvas,*(uint *)(this + 8),*(short *)(this + 0xb8));
  uVar5 = *(uint *)(this + 100);
  if (uVar5 == 0x10) {
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x3c),*(int *)(this + 0x6c),*(int *)(this + 0x70));
    if (((*(ushort *)(this + 0xa4) & 0xff) == 0) && (*(ushort *)(this + 0xa4) < 0x100))
    goto LAB_001975c0;
    uVar5 = *(uint *)(this + 0x30);
    iVar9 = *(int *)(this + 0x6c);
    iVar13 = *(int *)(this + 0x70);
  }
  else {
    if (uVar5 == 4) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this + 0x54),*(int *)(this + 0x6c),*(int *)(this + 0x70))
      ;
      if (*(int *)(this + 0x5c) != -1) {
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(this + 0x5c),
                   *(int *)(this + 0x6c) + (*(int *)(this + 0x84) >> 1),
                   *(int *)(this + 0x70) + (*(int *)(this + 0x7c) >> 1) + -1,'\x11','D');
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        if (((*(ushort *)(this + 0xa4) & 0xff) != 0) || (0xff < *(ushort *)(this + 0xa4))) {
          AbyssEngine::PaintCanvas::DrawImage2D
                    (Globals::Canvas,*(uint *)(this + 0x58),*(int *)(this + 0x6c),
                     *(int *)(this + 0x70));
        }
      }
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,*(uint *)(this + 8),this + 0xc,
                 *(int *)(this + 0x98) + *(int *)(this + 0x6c),
                 *(int *)(this + 0x70) + *(int *)(this + 0x9c),false);
      goto LAB_001975c0;
    }
    uVar1 = *(ushort *)(this + 0xa4);
    if ((uVar1 & 0xff) == 0) {
      if (uVar1 >> 8 == 0) {
        pTVar11 = this + 0x3c;
      }
      else {
        pTVar11 = this + 0x48;
      }
    }
    else {
      pTVar11 = this + 0x30;
    }
    uVar12 = *(uint *)pTVar11;
    if ((0x14 < uVar5) || ((1 << (uVar5 & 0xff) & 0x1ef400U) == 0)) {
      if ((uVar1 & 0xff) == 0) {
        if (uVar1 >> 8 == 0) {
          pTVar11 = this + 0x44;
          pTVar8 = this + 0x40;
        }
        else {
          pTVar11 = this + 0x50;
          pTVar8 = this + 0x4c;
        }
      }
      else {
        pTVar11 = this + 0x38;
        pTVar8 = this + 0x34;
      }
      uVar5 = *(uint *)pTVar11;
      Layout::drawBGPattern
                (Globals::layout,*(uint *)pTVar8,*(int *)(this + 0x88) + *(int *)(this + 0x6c),
                 *(int *)(this + 0x70),*(int *)(this + 0x94),*(int *)(this + 0x7c));
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,uVar5,
                 *(int *)(this + 0x6c) + *(int *)(this + 0x88) + *(int *)(this + 0x94),
                 *(int *)(this + 0x70));
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,uVar12,*(int *)(this + 0x6c),*(int *)(this + 0x70));
    Layout::setDrawColor(Globals::layout,-1);
    fVar16 = *(float *)(this + 0xb0);
    uVar5 = in_fpscr & 0xfffffff | (uint)(fVar16 < 0.0) << 0x1f | (uint)(fVar16 == 0.0) << 0x1e;
    uVar12 = uVar5 | (uint)NAN(fVar16) << 0x1c;
    bVar2 = (byte)(uVar5 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar12 >> 0x1c) & 1)) {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      Layout::setDrawColor(Globals::layout,-0x80);
      fVar16 = *(float *)(this + 0x88);
      iVar9 = 0x30;
      fVar17 = (float)VectorSignedToFloat(*(int *)(this + 0x94) + (int)fVar16 +
                                          *(int *)(this + 0x90),(byte)(uVar12 >> 0x16) & 3);
      if (this[0xac] == (TouchButton)0x0) {
        iVar9 = 0x3c;
      }
      fVar17 = (float)(int)(*(float *)(this + 0xb0) * fVar17);
      if ((int)fVar17 < (int)fVar16) {
        fVar16 = fVar17;
      }
      fVar16 = (float)AbyssEngine::PaintCanvas::DrawRegion2D
                                (Globals::Canvas,*(uint *)(this + iVar9),0,0,(int)fVar16,
                                 *(int *)(this + 0x7c),fVar17,0,0,0,*(int *)(this + 0x6c));
      iVar9 = *(int *)(this + 0x88);
      if (iVar9 < (int)fVar17) {
        iVar13 = 0x34;
        if (this[0xac] == (TouchButton)0x0) {
          iVar13 = 0x40;
        }
        iVar10 = *(int *)(this + 0x94);
        if ((int)fVar17 - iVar9 < *(int *)(this + 0x94)) {
          iVar10 = (int)fVar17 - iVar9;
        }
        fVar16 = (float)Layout::drawBGPattern
                                  (Globals::layout,*(uint *)(this + iVar13),
                                   iVar9 + *(int *)(this + 0x6c),*(int *)(this + 0x70),iVar10,
                                   *(int *)(this + 0x7c));
        iVar9 = *(int *)(this + 0x88);
      }
      iVar13 = *(int *)(this + 0x94) + iVar9;
      if (iVar13 < (int)fVar17) {
        iVar10 = ((int)fVar17 - iVar9) - *(int *)(this + 0x94);
        iVar9 = 0x38;
        if (this[0xac] == (TouchButton)0x0) {
          iVar9 = 0x44;
        }
        iVar6 = *(int *)(this + 0x90);
        if (iVar10 < *(int *)(this + 0x90)) {
          iVar6 = iVar10;
        }
        AbyssEngine::PaintCanvas::DrawRegion2D
                  (Globals::Canvas,*(uint *)(this + iVar9),0,0,iVar6,*(int *)(this + 0x7c),fVar16,0,
                   0,0,iVar13 + *(int *)(this + 0x6c));
      }
      Layout::setDrawColor(Globals::layout,-1);
    }
    uVar7 = *(undefined4 *)(this + 0xa0);
    if (this[0xa7] == (TouchButton)0x0) {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    }
    else {
      AbyssEngine::PaintCanvas::SetColor
                ((uchar)Globals::Canvas,(uchar)((uint)uVar7 >> 0x18),(uchar)((uint)uVar7 >> 0x10),
                 (uchar)((uint)uVar7 >> 8));
    }
    uVar5 = *(uint *)(this + 0x1c);
    if (uVar5 == 0xffffffff) {
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,*(uint *)(this + 8),this + 0xc,
                 *(int *)(this + 0x6c) + *(int *)(this + 0x98),
                 *(int *)(this + 0x70) + *(int *)(this + 0x9c),false);
      pPVar3 = Globals::Canvas;
      if (*(int *)(this + 0x18) != 0) {
        pTVar11 = this + 0x14;
        uVar5 = *(uint *)(this + 8);
        iVar9 = *(int *)(this + 0x6c);
        iVar13 = *(int *)(this + 0x84);
        if (*(int *)(this + 100) == 10) {
          iVar6 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,uVar5,pTVar11);
          iVar14 = *(int *)(this + 0x70);
          iVar15 = *(int *)(this + 0x7c);
          iVar10 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
          iVar10 = iVar15 + iVar14 + iVar10 * -2;
          iVar6 = (iVar9 + iVar13 / 2) - iVar6 / 2;
        }
        else {
          iVar14 = *(int *)(this + 0x98);
          iVar6 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,uVar5,pTVar11);
          iVar10 = *(int *)(this + 0x70) + *(int *)(this + 0x9c);
          iVar6 = ((iVar13 + iVar9) - iVar14) - iVar6;
        }
        AbyssEngine::PaintCanvas::DrawString(pPVar3,uVar5,pTVar11,iVar6,iVar10,false);
      }
      if (*(int *)(this + 0x28) != 0) {
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        uVar5 = Globals::font;
        pPVar3 = Globals::Canvas;
        iVar13 = *(int *)(this + 0x6c);
        iVar10 = *(int *)(this + 0x88);
        iVar9 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,this + 0x24);
        AbyssEngine::PaintCanvas::DrawString
                  (pPVar3,uVar5,this + 0x24,(iVar10 + iVar13) - iVar9,
                   *(int *)(this + 0x70) + *(int *)(this + 0x9c),false);
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      }
      if (*(int *)(this + 0x2c) != -1) {
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(this + 0x2c),
                   (*(int *)(this + 0x6c) + *(int *)(this + 0x84) + 6) - *(int *)(this + 0x88),
                   *(int *)(this + 0x70) + 1,'\x11','\x14');
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      }
      goto LAB_001975c0;
    }
    if (*(int *)(this + 100) == 0x13) goto LAB_001975c0;
    iVar13 = *(int *)(this + 0x70) + *(int *)(this + 0x9c);
    iVar9 = *(int *)(this + 0x6c) + *(int *)(this + 0x98);
  }
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar5,iVar9,iVar13);
LAB_001975c0:
  Layout::setDrawColor(Globals::layout,-1);
  AbyssEngine::PaintCanvas::FontSetSpacing(Globals::Canvas,*(uint *)(this + 8),sVar4);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  return;
}

// ===== TouchButton::touchedInside  @0x001976e0  (136 bytes)
/* TouchButton::touchedInside(int, int) */

bool __thiscall TouchButton::touchedInside(TouchButton *this,int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 0x6c);
  if (*(int *)(this + 100) == 3) {
    if ((param_1 < *(int *)(Globals::layout + 0x38) + iVar3 + -1) ||
       (*(int *)(this + 0x84) + ((iVar3 + 1) - *(int *)(Globals::layout + 0x38)) <= param_1)) {
      return false;
    }
    iVar1 = *(int *)(this + 0x70);
    if (param_2 < iVar1 + -1) {
      return false;
    }
    iVar3 = *(int *)(this + 0x80);
  }
  else {
    uVar2 = *(uint *)(this + 0xb4);
    if (param_1 < (int)((iVar3 + -1) - uVar2)) {
      return false;
    }
    if ((int)(*(int *)(this + 0x84) + iVar3 + uVar2 + 1) <= param_1) {
      return false;
    }
    if (param_2 < (int)(*(int *)(this + 0x70) + ~uVar2)) {
      return false;
    }
    iVar3 = *(int *)(this + 0x80);
    iVar1 = *(int *)(this + 0x70) + uVar2;
  }
  return param_2 <= iVar3 + iVar1 + 1;
}

// ===== TouchButton::resetTouch  @0x0019776c  (8 bytes)
/* TouchButton::resetTouch() */

void __thiscall TouchButton::resetTouch(TouchButton *this)

{
  this[0xa4] = (TouchButton)0x0;
  return;
}

// ===== TouchButton::isTouched  @0x00197774  (6 bytes)
/* TouchButton::isTouched() */

TouchButton __thiscall TouchButton::isTouched(TouchButton *this)

{
  return this[0xa4];
}

// ===== TouchButton::OnTouchBegin  @0x0019777c  (74 bytes)
/* TouchButton::OnTouchBegin(int, int) */

undefined4 __thiscall TouchButton::OnTouchBegin(TouchButton *this,int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  float extraout_s0;
  
  uVar1 = 0;
  if (((*(ushort *)(this + 0xa6) & 0xff) != 0) && (*(ushort *)(this + 0xa6) < 0x100)) {
    uVar2 = touchedInside(this,param_1,param_2);
    this[0xa4] = SUB41(uVar2,0);
    if (uVar2 == 1) {
      FModSound::play(Globals::sound,0x7c,(Vector *)0x0,(Vector *)0x0,extraout_s0);
      uVar2 = (uint)(byte)this[0xa4];
    }
    uVar1 = 0;
    if (uVar2 != 0) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

// ===== TouchButton::OnTouchMove  @0x001977cc  (52 bytes)
/* TouchButton::OnTouchMove(int, int) */

undefined4 __thiscall TouchButton::OnTouchMove(TouchButton *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((*(ushort *)(this + 0xa6) & 0xff) != 0) {
    if (0xff < *(ushort *)(this + 0xa6)) {
      return 0;
    }
    if (this[0xa4] == (TouchButton)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = touchedInside(this,param_1,param_2);
    }
    this[0xa4] = SUB41(iVar2,0);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

// ===== TouchButton::OnTouchEnd  @0x00197800  (80 bytes)
/* TouchButton::OnTouchEnd(int, int) */

undefined4 __thiscall TouchButton::OnTouchEnd(TouchButton *this,int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  float extraout_s0;
  
  uVar1 = 0;
  if (((*(ushort *)(this + 0xa6) & 0xff) != 0) && (*(ushort *)(this + 0xa6) < 0x100)) {
    if ((this[0xa4] == (TouchButton)0x0) ||
       (iVar2 = touchedInside(this,param_1,param_2), iVar2 != 1)) {
      uVar1 = 0;
      this[0xa4] = (TouchButton)0x0;
    }
    else {
      this[0xa4] = (TouchButton)0x0;
      FModSound::play(Globals::sound,0x7b,(Vector *)0x0,(Vector *)0x0,extraout_s0);
      uVar1 = 1;
    }
  }
  return uVar1;
}

