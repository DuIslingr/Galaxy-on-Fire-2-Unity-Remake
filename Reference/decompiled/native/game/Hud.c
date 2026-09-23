// Class: Hud
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Hud::Hud  @0x0018ce3e  (98 bytes)
/* Hud::Hud() */

Hud * __thiscall Hud::Hud(Hud *this)

{
  int iVar1;
  
  iVar1 = 0x1c;
  do {
    AbyssEngine::String::String((String *)(this + iVar1));
    iVar1 = iVar1 + 8;
  } while (iVar1 != 0xbc);
  AbyssEngine::String::String((String *)(this + 400));
  AbyssEngine::String::String((String *)(this + 0x1a0));
  AbyssEngine::String::String((String *)(this + 0x1a8));
  AbyssEngine::String::String((String *)(this + 0x1cc));
  AbyssEngine::String::String((String *)(this + 0x354));
  AbyssEngine::String::String((String *)(this + 0x4b8));
  init(this);
  return this;
}

// ===== Hud::init  @0x0018cf20  (3452 bytes)
/* Hud::init() */

void __thiscall Hud::init(Hud *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  PaintCanvas *this_00;
  Globals *pGVar4;
  Hud HVar5;
  short sVar6;
  undefined2 uVar7;
  short sVar8;
  ushort uVar9;
  int iVar10;
  Array *pAVar11;
  undefined4 *puVar12;
  Ship *pSVar13;
  float fVar14;
  void *pvVar15;
  SolarSystem *this_01;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  String aSStack_44 [8];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ac,(uint *)(this + 0x244));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ad,(uint *)(this + 0x248));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ae,(uint *)(this + 0x24c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4af,(uint *)(this + 0x250));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4aa,(uint *)(this + 0x254));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ab,(uint *)(this + 600));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4a7,(uint *)(this + 0x25c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4a8,(uint *)(this + 0x260));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x524,(uint *)(this + 0x264));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f59,(uint *)(this + 0x270));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f5a,(uint *)(this + 0x26c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f5b,(uint *)(this + 0x268));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4a9,(uint *)(this + 0x274));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4bb,(uint *)(this + 0x2ec));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ba,(uint *)(this + 0x2f0));
  if (Globals::iPad == '\0') {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c6,(uint *)(this + 0x2e8));
  }
  else {
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c6,(uint *)(this + 4));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x6aa,(uint *)(this + 8));
    *(undefined4 *)(this + 0x2e8) = *(undefined4 *)(this + 4);
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b5,(uint *)(this + 0x280));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b4,(uint *)(this + 0x284));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x536,(uint *)(this + 0x288));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4bd,(uint *)(this + 0x28c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4bc,(uint *)(this + 0x290));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b9,(uint *)(this + 0x294));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b8,(uint *)(this + 0x298));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b3,(uint *)(this + 0x29c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b2,(uint *)(this + 0x2a0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b1,(uint *)(this + 0x2ac));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b0,(uint *)(this + 0x2b0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b7,(uint *)(this + 0x2a4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b6,(uint *)(this + 0x2a8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c1,(uint *)(this + 700));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c5,(uint *)(this + 0x2c0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x520,(uint *)(this + 0x2c4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c3,(uint *)(this + 0x2f4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c2,(uint *)(this + 0x2f8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4cf,(uint *)(this + 0x238));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d1,(uint *)(this + 0x240));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d0,(uint *)(this + 0x23c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x537,(uint *)(this + 0x310));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x538,(uint *)(this + 0x314));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x539,(uint *)(this + 0x31c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x53a,(uint *)(this + 0x318));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x53a,(uint *)(this + 0x328));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f41,(uint *)(this + 0x32c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x525,(uint *)(this + 0x300));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x526,(uint *)(this + 0x304));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x52b,(uint *)(this + 0x308));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x52c,(uint *)(this + 0x30c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x528,(uint *)(this + 0x490));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x527,(uint *)(this + 0x4a0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e9,(uint *)(this + 0x494));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ea,(uint *)(this + 0x4a4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4be,(uint *)(this + 0x498));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4bf,(uint *)(this + 0x4a8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x52a,(uint *)(this + 0x49c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x529,(uint *)(this + 0x4ac));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x540,(uint *)(this + 0x330));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x541,(uint *)(this + 0x334));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x53f,(uint *)(this + 0x338));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x542,(uint *)(this + 0x33c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x543,(uint *)(this + 0x340));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x546,(uint *)(this + 0x2b4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x547,(uint *)(this + 0x2b8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f58,(uint *)(this + 0x344));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f57,(uint *)(this + 0x348));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b1,(uint *)(this + 0x34c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4b0,(uint *)(this + 0x350));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f43,(uint *)(this + 0x2d4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f42,(uint *)(this + 0x2e4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,8000,(uint *)(this + 800));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f61,(uint *)(this + 0x2d8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f60,(uint *)(this + 0x2dc));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f5f,(uint *)(this + 0x324));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f5c,(uint *)(this + 0x2e0));
  *(undefined4 *)(this + 0x43d) = 0;
  *(undefined4 *)(this + 0x448) = 0;
  *(undefined4 *)(this + 0x44c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x450) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x454) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  iVar10 = Globals::layout;
  uVar19 = *(undefined8 *)(Globals::layout + 300);
  uVar20 = *(undefined8 *)(Globals::layout + 0x134);
  *(undefined8 *)(this + 0x470) = uVar19;
  *(undefined8 *)(this + 0x478) = uVar20;
  uVar16 = *(undefined4 *)(iVar10 + 0x140);
  uVar1 = *(undefined4 *)(iVar10 + 0x144);
  uVar2 = *(undefined4 *)(iVar10 + 0x148);
  *(undefined4 *)(this + 0x480) = *(undefined4 *)(iVar10 + 0x13c);
  *(undefined4 *)(this + 0x484) = uVar16;
  *(undefined4 *)(this + 0x488) = uVar1;
  *(undefined4 *)(this + 0x48c) = uVar2;
  *(short *)(this + 0x3d0) = (short)Globals::w - (short)*(undefined4 *)(iVar10 + 0x14c);
  iVar10 = Globals::h;
  sVar6 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
  *(short *)(this + 0x3d2) =
       (((short)iVar10 - (short)uVar19) - sVar6) - (short)*(undefined4 *)(Globals::layout + 0x150);
  uVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x28c));
  *(undefined2 *)(this + 0x38c) = uVar7;
  uVar16 = *(undefined4 *)(Globals::layout + 0x154);
  sVar6 = (short)Globals::w;
  sVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x284));
  *(short *)(this + 0x380) = (sVar6 - (short)uVar16) - sVar8;
  uVar16 = *(undefined4 *)(Globals::layout + 0x158);
  sVar6 = (short)Globals::h;
  sVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x284));
  *(short *)(this + 0x382) = (sVar6 - (short)uVar16) - sVar8;
  iVar17 = Globals::w;
  iVar10 = Globals::layout;
  *(short *)(this + 0x388) =
       ((short)Globals::w - (short)*(undefined4 *)(Globals::layout + 0x15c)) -
       *(short *)(this + 0x38c);
  *(short *)(this + 0x38a) =
       ((short)Globals::h - (short)*(undefined4 *)(iVar10 + 0x160)) - *(short *)(this + 0x38c);
  *(short *)(this + 0x386) = (short)*(undefined4 *)(iVar10 + 0x164);
  iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2f4));
  *(short *)(this + 0x37c) =
       (short)((uint)(iVar17 - (iVar17 >> 0x1f)) >> 1) -
       (short)((uint)(iVar10 - (iVar10 >> 0x1f)) >> 1);
  *(short *)(this + 0x37e) = (short)*(undefined4 *)(Globals::layout + 0x168);
  sVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x490));
  *(short *)(this + 0x392) = sVar6;
  iVar10 = Globals::layout;
  *(short *)(this + 0x38e) =
       ((short)Globals::w - sVar6) - (short)*(undefined4 *)(Globals::layout + 0x16c);
  uVar16 = *(undefined4 *)(iVar10 + 0x170);
  sVar6 = (short)Globals::h;
  sVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x490));
  *(short *)(this + 0x390) = (sVar6 - (short)uVar16) - sVar8;
  sVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2ec));
  *(short *)(this + 0x3b6) = sVar6;
  iVar10 = Globals::layout;
  *(short *)(this + 0x3b8) = (short)*(undefined4 *)(Globals::layout + 0x174);
  *(short *)(this + 0x3b2) = ((short)Globals::w - (short)*(undefined4 *)(iVar10 + 0x178)) - sVar6;
  uVar16 = *(undefined4 *)(iVar10 + 0x17c);
  sVar6 = (short)Globals::h;
  sVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x2ec));
  *(short *)(this + 0x3b4) = (sVar6 - (short)uVar16) - sVar8;
  sVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2b0));
  *(short *)(this + 0x398) = sVar6;
  iVar10 = Globals::layout;
  *(short *)(this + 0x394) = (short)*(undefined4 *)(Globals::layout + 0x180);
  *(short *)(this + 0x396) = ((short)Globals::h - (short)*(undefined4 *)(iVar10 + 0x184)) - sVar6;
  uVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2b0));
  *(undefined2 *)(this + 0x39e) = uVar7;
  iVar10 = Globals::layout;
  *(short *)(this + 0x39a) =
       ((short)Globals::w - (short)*(undefined4 *)(Globals::layout + 0x180)) -
       *(short *)(this + 0x398);
  *(short *)(this + 0x39c) =
       ((short)Globals::h - (short)*(undefined4 *)(iVar10 + 0x184)) - *(short *)(this + 0x398);
  sVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x294));
  *(short *)(this + 0x3aa) = sVar8;
  iVar10 = Globals::layout;
  sVar6 = (short)Globals::w;
  *(short *)(this + 0x3a6) = (sVar6 - sVar8) - (short)*(undefined4 *)(Globals::layout + 0x194);
  *(short *)(this + 0x3a8) = (short)*(undefined4 *)(iVar10 + 0x198);
  sVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2c0));
  iVar10 = Globals::layout;
  *(short *)(this + 0x3d4) = (sVar6 - sVar8) - (short)*(undefined4 *)(Globals::layout + 0x19c);
  *(short *)(this + 0x3d6) = (short)*(undefined4 *)(iVar10 + 0x1a0);
  uVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 700));
  *(undefined2 *)(this + 0x3cc) = uVar7;
  uVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x344));
  *(ushort *)(this + 0x3f8) = uVar9;
  iVar10 = Globals::layout;
  sVar3 = (short)(Globals::w / 2);
  sVar8 = sVar3 - (uVar9 >> 1);
  sVar6 = (short)*(undefined4 *)(Globals::layout + 0x31c);
  *(short *)(this + 0x3f0) = sVar8 - sVar6;
  *(ushort *)(this + 0x3f4) = (sVar6 + sVar3) - (uVar9 >> 1);
  iVar17 = Globals::h;
  sVar6 = (short)(Globals::h / 2) - (short)*(undefined4 *)(iVar10 + 800);
  *(short *)(this + 0x3f2) = sVar6;
  *(short *)(this + 0x3f6) = sVar6;
  *(short *)(this + 0x3fa) = sVar8;
  *(undefined2 *)(this + 0x3fc) = *(undefined2 *)(this + 0x38a);
  *(short *)(this + 0x3c8) = (short)*(undefined4 *)(iVar10 + 0x1a4);
  uVar16 = *(undefined4 *)(iVar10 + 0x1a8);
  sVar6 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 700));
  *(short *)(this + 0x3ca) = ((short)iVar17 - (short)uVar16) - sVar6;
  uVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2a4));
  *(undefined2 *)(this + 0x3be) = uVar7;
  sVar6 = (short)*(undefined4 *)(this + 0x3c8) + (*(ushort *)(this + 0x3cc) >> 1);
  *(short *)(this + 0x3c0) = sVar6;
  sVar8 = (*(ushort *)(this + 0x3cc) >> 1) + (short)((uint)*(undefined4 *)(this + 0x3c8) >> 0x10);
  *(short *)(this + 0x3c2) = sVar8;
  *(short *)(this + 0x3ba) = sVar6;
  *(short *)(this + 0x3bc) = sVar8;
  sVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x29c));
  *(short *)(this + 0x3b0) = sVar6;
  iVar10 = Globals::layout;
  *(short *)(this + 0x3ac) = (short)*(undefined4 *)(Globals::layout + 0x1ac);
  *(short *)(this + 0x3ae) = ((short)Globals::h - (short)*(undefined4 *)(iVar10 + 0x1b0)) - sVar6;
  sVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x334));
  *(short *)(this + 0x3a4) = sVar6;
  iVar10 = Globals::layout;
  *(short *)(this + 0x3a0) = (short)*(undefined4 *)(Globals::layout + 0x188);
  *(short *)(this + 0x3a2) = ((short)Globals::h - (short)*(undefined4 *)(iVar10 + 0x18c)) - sVar6;
  *(undefined4 *)(this + 0x3ec) = *(undefined4 *)(iVar10 + 400);
  iVar17 = Globals::w;
  if (Globals::iPad == '\0') {
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x238));
    *(int *)(this + 0x360) = iVar17 / 2 - iVar10 / 2;
    *(undefined4 *)(this + 0x364) = *(undefined4 *)(Globals::layout + 0x1b4);
  }
  else {
    iVar17 = Globals::w - *(int *)(iVar10 + 0x28);
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x238));
    *(int *)(this + 0x360) = iVar17 - iVar10;
    iVar18 = *(int *)(Globals::layout + 0x2c);
    iVar17 = *(int *)(Globals::layout + 0x30);
    uVar9 = *(ushort *)(this + 0x3b4);
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x238));
    *(uint *)(this + 0x364) = (((uint)uVar9 - iVar18) + iVar17 * -6) - iVar10;
    uVar16 = Globals::options._84_4_;
    pGVar4 = Globals::globals;
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 700));
    iVar17 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2b0));
    iVar18 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x2a0));
    Globals::setCoordsSteer
              (pGVar4,uVar16,iVar10,iVar17,iVar18,(ushort *)(this + 0x394),(ushort *)(this + 0x396),
               (ushort *)(this + 0x3c8),(ushort *)(this + 0x3ca),(ushort *)(this + 0x3c0),
               (ushort *)(this + 0x3c2),(ushort *)(this + 0x3ac),(ushort *)(this + 0x3ae),
               (ushort *)(this + 0x3a0),(ushort *)(this + 0x3a2));
    *(short *)(this + 0x3ba) = (short)*(undefined4 *)(this + 0x3c0);
    *(short *)(this + 0x3bc) = (short)((uint)*(undefined4 *)(this + 0x3c0) >> 0x10);
    uVar16 = Globals::options._88_4_;
    pGVar4 = Globals::globals;
    iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 4));
    Globals::setCoordsFire
              (pGVar4,uVar16,iVar10,*(uint *)(this + 4),*(uint *)(this + 8),(uint *)(this + 0x2e8),
               (ushort *)(this + 0xc),(ushort *)(this + 0xe),(ushort *)(this + 0x380),
               (ushort *)(this + 0x382),(ushort *)(this + 0x3b2),(ushort *)(this + 0x3b4),
               (ushort *)(this + 0x38e),(ushort *)(this + 0x390),(ushort *)(this + 0x388),
               (ushort *)(this + 0x38a),(ushort *)(this + 0x39a),(ushort *)(this + 0x39c));
    *(undefined4 *)(this + 0x10) = Globals::options._84_4_;
    *(undefined4 *)(this + 0x14) = Globals::options._88_4_;
  }
  uVar16 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x238));
  *(undefined4 *)(this + 0x368) = uVar16;
  uVar16 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x240));
  *(undefined4 *)(this + 0x36c) = uVar16;
  iVar10 = Globals::layout;
  *(int *)(this + 0x370) = *(int *)(this + 0x360) + *(int *)(Globals::layout + 0x1b8);
  *(int *)(this + 0x374) =
       *(int *)(iVar10 + 0x1bc) +
       ((*(int *)(this + 0x364) + *(int *)(this + 0x368)) - *(int *)(iVar10 + 0x30) / 2);
  iVar17 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x240));
  iVar10 = Globals::layout;
  *(int *)(this + 0x378) = iVar17 - *(int *)(Globals::layout + 0x1c0);
  sVar6 = (short)*(undefined4 *)(iVar10 + 0x1c4);
  *(short *)(this + 0x3d8) = sVar6;
  sVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x244));
  *(short *)(this + 0x3da) = sVar8 + sVar6;
  iVar10 = Globals::layout;
  *(short *)(this + 0x3e0) = (short)*(undefined4 *)(Globals::layout + 0x1c8);
  *(short *)(this + 0x3e4) = (short)*(undefined4 *)(iVar10 + 0x1cc);
  *(short *)(this + 0x3de) = (short)*(undefined4 *)(iVar10 + 0x1d0);
  *(short *)(this + 0x3e6) = (short)*(undefined4 *)(iVar10 + 0x1d4);
  uVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x250));
  *(undefined2 *)(this + 0x3e2) = uVar7;
  *(undefined2 *)(this + 0x3dc) = *(undefined2 *)(this + 0x3da);
  uVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x250));
  *(undefined2 *)(this + 1000) = uVar7;
  this[0x43c] = (Hud)0x0;
  this[0x412] = (Hud)0x1;
  this[0x410] = (Hud)0x1;
  *(undefined4 *)(this + 0x434) = 0;
  *(undefined4 *)(this + 0x438) = 0;
  *(undefined4 *)(this + 0x458) = 0;
  *(undefined4 *)(this + 0x460) = 0;
  this[0x441] = (Hud)0x0;
  this[0x222] = (Hud)0x0;
  *(undefined4 *)(this + 0x420) = 0;
  *(undefined4 *)(this + 0x424) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x428) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x42c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x10c) = 0xffffffff;
  pAVar11 = operator_new(0xc);
  puVar12 = operator_new__(4);
  *(undefined4 **)(pAVar11 + 4) = puVar12;
  *(undefined4 *)(pAVar11 + 8) = 1;
  *puVar12 = 0;
  *(undefined4 *)pAVar11 = 0;
  *(Array **)(this + 0x204) = pAVar11;
  ArraySetLength<ListItem*>(0x14,pAVar11);
  iVar17 = Globals::w;
  *(int *)(this + 0x110) = Globals::w >> 1;
  iVar10 = Globals::h;
  RADAR_WIDTH = iVar17 + -0x1c;
  *(int *)(this + 0x114) = Globals::h - *(int *)(this + 0x480);
  RADAR_HEIGHT = (((iVar10 + -0x21) - *(int *)(this + 0x480)) - *(int *)(this + 0x488)) -
                 *(int *)(Globals::layout + 0x1d8);
  this[0x18e] = (Hud)0x0;
  *(undefined4 *)(this + 0x180) = 10000;
  *(int *)(this + 0x1bc) = iVar17 + -5;
  pSVar13 = (Ship *)Status::getShip(Globals::status);
  iVar10 = Ship::getBoostDelay(pSVar13);
  this[0x1c2] = (Hud)(0 < iVar10);
  pSVar13 = (Ship *)Status::getShip(Globals::status);
  iVar10 = Ship::getMaxShieldHP(pSVar13);
  this[0x1c3] = (Hud)(0 < iVar10);
  pSVar13 = (Ship *)Status::getShip(Globals::status);
  iVar10 = Ship::getMaxArmorHP(pSVar13);
  this[0x1c4] = (Hud)(0 < iVar10);
  pSVar13 = (Ship *)Status::getShip(Globals::status);
  fVar14 = (float)Ship::getFirePower(pSVar13);
  this[0x1c5] = (Hud)(0.0 < fVar14);
  pSVar13 = (Ship *)Status::getShip(Globals::status);
  HVar5 = (Hud)Ship::hasCloak(pSVar13);
  this[0x1c1] = HVar5;
  this[0x20c] = (Hud)0x0;
  this[0x1d4] = (Hud)0x0;
  this[0x1d5] = (Hud)0x0;
  this[0x1d6] = (Hud)0x0;
  this[1] = (Hud)0x1;
  this[0x214] = (Hud)0x0;
  *(undefined4 *)(this + 0x208) = 0;
  *(undefined4 *)(this + 0x210) = 0;
  this[0x1e4] = (Hud)0x0;
  *(undefined4 *)(this + 0x408) = 0;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x468) = 0;
  *(undefined4 *)(this + 0x46c) = 0;
  this[0x216] = (Hud)0x0;
  this[0x217] = (Hud)0x0;
  this[0x218] = (Hud)0x0;
  *(undefined4 *)(this + 0x174) = 0xffffffff;
  *(undefined4 *)(this + 0x21c) = 0;
  *this = (Hud)0x0;
  this[0x220] = (Hud)0x1;
  this[0x221] = (Hud)0x0;
  *(undefined4 *)(this + 0x458) = 0xffffffff;
  *(undefined4 *)(this + 0x45c) = 0xffffffff;
  *(undefined4 *)(this + 0x4c4) = 0;
  this[0x464] = (Hud)0x0;
  this[0x4c0] = (Hud)0x0;
  pAVar11 = operator_new(0xc);
  puVar12 = operator_new__(4);
  *(undefined4 **)(pAVar11 + 4) = puVar12;
  *(undefined4 *)(pAVar11 + 8) = 1;
  *puVar12 = 0;
  *(undefined4 *)pAVar11 = 0;
  *(Array **)(this + 0x22c) = pAVar11;
  ArraySetLength<void*>(0x19,pAVar11);
  pvVar15 = operator_new__(100);
  *(void **)(this + 0x230) = pvVar15;
  iVar10 = 0;
  do {
    *(undefined4 *)(*(int *)(*(int *)(this + 0x22c) + 4) + iVar10 * 4) = 0;
    *(undefined4 *)(*(int *)(this + 0x230) + iVar10 * 4) = 0;
    iVar10 = iVar10 + 1;
  } while (iVar10 != 0x19);
  *(undefined4 *)(this + 0x224) = 0;
  iVar10 = Status::inAlienOrbit(Globals::status);
  this_00 = Globals::Canvas;
  if (iVar10 == 0) {
    this_01 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar10 = SolarSystem::getRace(this_01);
    AbyssEngine::PaintCanvas::Image2DCreate
              (this_00,*(ushort *)(&DAT_00259e78 + iVar10 * 4),(uint *)(this + 0x174));
  }
  *(undefined4 *)(this + 0x4b0) = 0xffffffff;
  *(undefined4 *)(this + 0x4b4) = 0;
  AbyssEngine::String::String(aSStack_44,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x4b8),aSStack_44);
  AbyssEngine::String::~String(aSStack_44);
  closeHudMenu(this);
  checkIfQuickMenuIsEmpty(this);
  releaseAllKeys(this);
  *(undefined4 *)(this + 0x4c8) = 0;
  iVar10 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x294));
  Globals::pause_x = (Globals::w - iVar10) - *(int *)(Globals::layout + 0x194);
  Globals::pause_y = *(undefined4 *)(Globals::layout + 0x198);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Hud::~Hud  @0x0018dd48  (180 bytes)
/* Hud::~Hud() */

Hud * __thiscall Hud::~Hud(Hud *this)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = *(void **)(this + 0x1fc);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1fc) = 0;
  pvVar1 = *(void **)(this + 0x204);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x204) = 0;
  if (*(Array **)(this + 0x18) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x18));
    pvVar1 = *(void **)(this + 0x18);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x18) = 0;
  pvVar1 = *(void **)(this + 0x4c8);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x4c8) = 0;
  AbyssEngine::String::~String((String *)(this + 0x4b8));
  AbyssEngine::String::~String((String *)(this + 0x354));
  AbyssEngine::String::~String((String *)(this + 0x1cc));
  AbyssEngine::String::~String((String *)(this + 0x1a8));
  AbyssEngine::String::~String((String *)(this + 0x1a0));
  AbyssEngine::String::~String((String *)(this + 400));
  iVar2 = 0xb4;
  do {
    AbyssEngine::String::~String((String *)(this + iVar2));
    iVar2 = iVar2 + -8;
  } while (iVar2 != 0x14);
  return this;
}

// ===== Hud::setAutofireEnabled  @0x0018ddfc  (6 bytes)
/* Hud::setAutofireEnabled(bool) */

void __thiscall Hud::setAutofireEnabled(Hud *this,bool param_1)

{
  this[0x43c] = (Hud)param_1;
  return;
}

// ===== Hud::closeHudMenu  @0x0018de36  (44 bytes)
/* Hud::closeHudMenu() */

void __thiscall Hud::closeHudMenu(Hud *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0x18) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x18));
    pvVar1 = *(void **)(this + 0x18);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0x18) = 0;
  }
  this[0x222] = (Hud)0x0;
  return;
}

// ===== Hud::checkIfQuickMenuIsEmpty  @0x0018de64  (120 bytes)
/* Hud::checkIfQuickMenuIsEmpty() */

void __thiscall Hud::checkIfQuickMenuIsEmpty(Hud *this)

{
  byte bVar1;
  Hud HVar2;
  Ship *pSVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  pSVar3 = (Ship *)Status::getShip(Globals::status);
  puVar4 = (uint *)Ship::getEquipment(pSVar3,1);
  *(uint **)(this + 0x1fc) = puVar4;
  if ((puVar4 != (uint *)0x0) && (*puVar4 != 0)) {
    uVar6 = 0;
    do {
      if (*(int *)(puVar4[1] + uVar6 * 4) != 0) goto LAB_0018deb6;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *puVar4);
  }
  pSVar3 = (Ship *)Status::getShip(Globals::status);
  iVar5 = Ship::hasJumpDrive(pSVar3);
  if ((iVar5 == 0) && (iVar5 = Status::getWingmen(Globals::status), iVar5 == 0)) {
    pSVar3 = (Ship *)Status::getShip(Globals::status);
    bVar1 = Ship::hasCloak(pSVar3);
    HVar2 = (Hud)(bVar1 ^ 1);
  }
  else {
LAB_0018deb6:
    HVar2 = (Hud)0x0;
  }
  this[0x223] = HVar2;
  updateSecondaryWeaponString(this);
  return;
}

// ===== Hud::releaseAllKeys  @0x0018deec  (50 bytes)
/* Hud::releaseAllKeys() */

void __thiscall Hud::releaseAllKeys(Hud *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  *(undefined4 *)(this + 0x224) = 0;
  do {
    if ((*(int *)(this + 0x22c) != 0) &&
       (iVar2 = *(int *)(*(int *)(this + 0x22c) + 4), *(int *)(iVar2 + iVar1 * 4) != 0)) {
      *(undefined4 *)(iVar2 + iVar1 * 4) = 0;
    }
    *(undefined4 *)(*(int *)(this + 0x230) + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x19);
  *(undefined4 *)(this + 0x228) = 0;
  return;
}

// ===== Hud::setVisible  @0x0018df1e  (4 bytes)
/* Hud::setVisible(bool) */

void __thiscall Hud::setVisible(Hud *this,bool param_1)

{
  this[1] = (Hud)param_1;
  return;
}

// ===== Hud::updateSecondaryWeaponString  @0x0018df24  (240 bytes)
/* Hud::updateSecondaryWeaponString() */

void __thiscall Hud::updateSecondaryWeaponString(Hud *this)

{
  GameText *this_00;
  int iVar1;
  String *pSVar2;
  undefined4 uVar3;
  int iVar4;
  String aSStack_48 [8];
  undefined4 local_40 [2];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  AbyssEngine aAStack_28 [8];
  AbyssEngine aAStack_20 [8];
  int local_18;
  
  this_00 = Globals::gameText;
  local_18 = __stack_chk_guard;
  if (*(Item **)(this + 0x1f8) != (Item *)0x0) {
    iVar1 = Item::getIndex(*(Item **)(this + 0x1f8));
    pSVar2 = (String *)GameText::getText(this_00,iVar1 + 0x4fa);
    AbyssEngine::String::String(aSStack_38," (",false);
    AbyssEngine::operator+(aAStack_30,pSVar2,aSStack_38);
    uVar3 = Item::getAmount(*(Item **)(this + 0x1f8));
    local_40[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar3,local_40));
    AbyssEngine::operator+(aAStack_28,aAStack_30,(String *)local_40);
    AbyssEngine::String::String(aSStack_48,")",false);
    AbyssEngine::operator+(aAStack_20,aAStack_28,aSStack_48);
    AbyssEngine::String::operator=((String *)(this + 0x354),aAStack_20);
    AbyssEngine::String::~String((String *)aAStack_20);
    AbyssEngine::String::~String(aSStack_48);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)local_40);
    AbyssEngine::String::~String((String *)aAStack_30);
    AbyssEngine::String::~String(aSStack_38);
    iVar1 = Globals::w;
    iVar4 = AbyssEngine::PaintCanvas::GetTextWidth
                      (Globals::Canvas,Globals::font,(String *)(this + 0x354));
    *(int *)(this + 0x35c) = (iVar1 >> 1) - (iVar4 >> 1);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Hud::initHudMenu  @0x0018e080  (3540 bytes)
/* Hud::initHudMenu(int, Level*) */

void __thiscall Hud::initHudMenu(Hud *this,int param_1,Level *param_2)

{
  GameText *pGVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  Ship *pSVar5;
  undefined4 uVar6;
  TouchButton *pTVar7;
  String *pSVar8;
  Station *this_00;
  Item *pIVar9;
  SolarSystem *this_01;
  PlayerEgo *pPVar10;
  Route *this_02;
  int iVar11;
  uint *puVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  float *pfVar17;
  int *piVar18;
  uint uVar19;
  void *pvVar20;
  int iVar21;
  uint in_fpscr;
  float fVar22;
  float fVar23;
  float local_cc;
  float local_c4;
  float local_b4;
  float local_ac;
  float local_9c;
  float local_94;
  String aSStack_88 [4];
  int local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  String aSStack_6c [8];
  undefined4 local_64 [2];
  String aSStack_5c [8];
  String aSStack_54 [8];
  AbyssEngine aAStack_4c [8];
  undefined4 local_44;
  int local_40 [4];
  
  local_40[3] = __stack_chk_guard;
  if (*(Array **)(this + 0x18) != (Array *)0x0) {
    ArrayReleaseClasses<TouchButton*>(*(Array **)(this + 0x18));
    pvVar20 = *(void **)(this + 0x18);
    if (pvVar20 != (void *)0x0) {
      if (*(void **)((int)pvVar20 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar20 + 4));
      }
      operator_delete(pvVar20);
    }
    *(undefined4 *)(this + 0x18) = 0;
  }
  puVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  puVar3[1] = puVar4;
  puVar3[2] = 1;
  *puVar4 = 0;
  *puVar3 = 0;
  *(undefined4 **)(this + 0x18) = puVar3;
  *(int *)(this + 0x1d8) = param_1;
  pvVar20 = *(void **)(this + 0x1fc);
  if (pvVar20 != (void *)0x0) {
    if (*(void **)((int)pvVar20 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar20 + 4));
    }
    operator_delete(pvVar20);
  }
  *(undefined4 *)(this + 0x1fc) = 0;
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  uVar6 = Ship::getEquipment(pSVar5,1);
  *(undefined4 *)(this + 0x1fc) = uVar6;
  updateSecondaryWeaponString(this);
  *(undefined4 *)(this + 0x468) = 0;
  cVar2 = Globals::iPad;
  iVar16 = Globals::layout;
  iVar15 = *(int *)(Globals::layout + 0x1dc);
  if (Globals::iPad == '\0') {
    iVar21 = *(int *)(this + 0x374);
  }
  else {
    if (*(int *)(this + 0x1d8) == 3) {
      fVar22 = (float)VectorSignedToFloat(Globals::options._84_4_,(byte)(in_fpscr >> 0x16) & 3);
    }
    else {
      fVar22 = (float)VectorSignedToFloat(Globals::options._88_4_,(byte)(in_fpscr >> 0x16) & 3);
      if (Globals::iPadHD == '\0') {
        pfVar17 = (float *)&DAT_0018ef8c;
        if (Globals::iPadLarge != '\0') {
          pfVar17 = (float *)&DAT_0018ef90;
        }
        fVar23 = *pfVar17;
      }
      else {
        fVar23 = 112.5;
      }
      fVar22 = fVar22 - fVar23;
    }
    in_fpscr = in_fpscr & 0xfffffff;
    if (0.0 <= fVar22) {
      if (*(int *)(this + 0x1d8) == 3) {
        fVar22 = (float)VectorSignedToFloat(Globals::options._84_4_,(byte)(in_fpscr >> 0x16) & 3);
      }
      else {
        fVar22 = (float)VectorSignedToFloat(Globals::options._88_4_,(byte)(in_fpscr >> 0x16) & 3);
        if (Globals::iPadHD == '\0') {
          pfVar17 = (float *)&DAT_0018ef8c;
          if (Globals::iPadLarge != '\0') {
            pfVar17 = (float *)&DAT_0018ef90;
          }
          fVar23 = *pfVar17;
        }
        else {
          fVar23 = 112.5;
        }
        fVar22 = fVar22 - fVar23;
      }
    }
    else {
      fVar22 = 0.0;
    }
    *(int *)(this + 0x364) = (int)fVar22;
    iVar21 = ((*(int *)(this + 0x368) + (int)fVar22) - *(int *)(iVar16 + 0x30) / 2) + 1;
    *(int *)(this + 0x374) = iVar21;
  }
  switch(param_1) {
  case 0:
    puVar12 = *(uint **)(this + 0x1fc);
    if ((puVar12 != (uint *)0x0) && (*puVar12 != 0)) {
      uVar14 = 0;
      do {
        if (*(int *)(puVar12[1] + uVar14 * 4) != 0) {
          pTVar7 = operator_new(0xc0);
          pSVar8 = (String *)GameText::getText(Globals::gameText,0x10a);
          TouchButton::TouchButton
                    (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11',
                     '\x04');
          *(undefined4 *)pTVar7 = 0x200;
          *(undefined4 *)(pTVar7 + 4) = 0;
          piVar18 = *(int **)(this + 0x18);
          piVar18[2] = *piVar18 + 1;
          pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
          piVar18[1] = (int)pvVar20;
          *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
          *piVar18 = piVar18[2];
          iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
          break;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < *puVar12);
    }
    iVar16 = Status::getWingmen(Globals::status);
    if (((iVar16 != 0) && (iVar16 = Status::inSupernovaSystem(Globals::status), iVar16 == 0)) &&
       (iVar16 = Status::getCurrentCampaignMission(Globals::status), iVar16 != 0x9e)) {
      pTVar7 = operator_new(0xc0);
      pSVar8 = (String *)GameText::getText(Globals::gameText,0x132);
      TouchButton::TouchButton
                (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11','\x04')
      ;
      *(undefined4 *)pTVar7 = 0x400;
      *(undefined4 *)(pTVar7 + 4) = 0;
      piVar18 = *(int **)(this + 0x18);
      piVar18[2] = *piVar18 + 1;
      pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
      piVar18[1] = (int)pvVar20;
      *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
      *piVar18 = piVar18[2];
      iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
    }
    pSVar5 = (Ship *)Status::getShip(Globals::status);
    iVar16 = Ship::hasCloak(pSVar5);
    if (iVar16 == 1) {
      pSVar5 = (Ship *)Status::getShip(Globals::status);
      pIVar9 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,0x15);
      pTVar7 = operator_new(0xc0);
      pGVar1 = Globals::gameText;
      iVar16 = Item::getIndex(pIVar9);
      pSVar8 = (String *)GameText::getText(pGVar1,iVar16 + 0x4fa);
      TouchButton::TouchButton
                (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11','\x04')
      ;
      TouchButton::setPressProgressHighlight(pTVar7,false);
      pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
      iVar16 = PlayerEgo::isCloaked(pPVar10);
      if (iVar16 == 0) {
        pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
        iVar16 = PlayerEgo::isChargingCloak(pPVar10);
        if (iVar16 != 0) goto LAB_0018e7c4;
        pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
        iVar16 = PlayerEgo::isRechargingCloak(pPVar10);
        if (iVar16 == 1) goto LAB_0018e7c4;
      }
      else {
LAB_0018e7c4:
        pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
        iVar16 = PlayerEgo::isRechargingCloak(pPVar10);
        if (iVar16 == 1) {
          pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
          fVar22 = (float)PlayerEgo::getCloakRechargeRate(pPVar10);
          TouchButton::setPressProgress(pTVar7,fVar22);
        }
        TouchButton::setHalfTransparent(pTVar7,true);
      }
      *(undefined4 *)pTVar7 = 0x800;
      *(undefined4 *)(pTVar7 + 4) = 0;
      piVar18 = *(int **)(this + 0x18);
      piVar18[2] = *piVar18 + 1;
      pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
      piVar18[1] = (int)pvVar20;
      *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
      *piVar18 = piVar18[2];
      iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
    }
    pSVar5 = (Ship *)Status::getShip(Globals::status);
    iVar16 = Ship::hasJumpDrive(pSVar5);
    if (iVar16 == 1) {
      pTVar7 = operator_new(0xc0);
      pSVar8 = (String *)GameText::getText(Globals::gameText,0x54f);
      TouchButton::TouchButton
                (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11','\x04')
      ;
      pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
      iVar16 = PlayerEgo::isChargingDrive(pPVar10);
      if (iVar16 == 0) {
        pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
        iVar16 = PlayerEgo::emergencySystemActive(pPVar10);
        if (iVar16 == 1) goto LAB_0018e892;
      }
      else {
LAB_0018e892:
        TouchButton::setHalfTransparent(pTVar7,true);
      }
      *(undefined4 *)pTVar7 = 0x1000;
      *(undefined4 *)(pTVar7 + 4) = 0;
      piVar18 = *(int **)(this + 0x18);
      piVar18[2] = *piVar18 + 1;
      pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
      piVar18[1] = (int)pvVar20;
      *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
      *piVar18 = piVar18[2];
    }
    pSVar5 = (Ship *)Status::getShip(Globals::status);
    pIVar9 = (Item *)Ship::getCargo(pSVar5,0x7a);
    if (pIVar9 == (Item *)0x0) {
      uVar6 = 0;
    }
    else {
      uVar6 = Item::getAmount(pIVar9);
    }
    *(undefined4 *)(this + 0x21c) = uVar6;
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f5,(uint *)(this + 0x2fc));
    goto switchD_0018e23a_default;
  case 1:
    puVar12 = *(uint **)(this + 0x1fc);
    if (*puVar12 != 0) {
      uVar14 = 0;
      do {
        if (*(int *)(puVar12[1] + uVar14 * 4) != 0) {
          pTVar7 = operator_new(0xc0);
          pGVar1 = Globals::gameText;
          iVar16 = Item::getIndex(*(Item **)(puVar12[1] + uVar14 * 4));
          pSVar8 = (String *)GameText::getText(pGVar1,iVar16 + 0x4fa);
          AbyssEngine::String::String(aSStack_5c," (",false);
          uVar6 = Item::getAmount(*(Item **)(*(int *)(*(int *)(this + 0x1fc) + 4) + uVar14 * 4));
          local_64[0] = 0;
          AbyssEngine::String::Set(CONCAT44(uVar6,local_64));
          AbyssEngine::operator+((AbyssEngine *)aSStack_54,aSStack_5c,(String *)local_64);
          AbyssEngine::String::String(aSStack_6c,")",false);
          AbyssEngine::operator+(aAStack_4c,aSStack_54,aSStack_6c);
          AbyssEngine::String::String((String *)&local_80,aAStack_4c,false);
          AbyssEngine::operator+((AbyssEngine *)&local_44,pSVar8,(String *)&local_80);
          TouchButton::TouchButton
                    (pTVar7,(AbyssEngine *)&local_44,0,*(int *)(this + 0x370),iVar21,
                     *(int *)(this + 0x378),'\x11','\x04');
          AbyssEngine::String::~String((String *)&local_44);
          AbyssEngine::String::~String((String *)&local_80);
          AbyssEngine::String::~String((String *)aAStack_4c);
          AbyssEngine::String::~String(aSStack_6c);
          AbyssEngine::String::~String(aSStack_54);
          AbyssEngine::String::~String((String *)local_64);
          AbyssEngine::String::~String(aSStack_5c);
          if (uVar14 == 0) {
            uVar6 = 0x2000;
          }
          else if (uVar14 == 1) {
            uVar6 = 0x4000;
          }
          else {
            uVar6 = 0x10000;
            if (uVar14 == 2) {
              uVar6 = 0x8000;
            }
          }
          *(undefined4 *)pTVar7 = uVar6;
          *(undefined4 *)(pTVar7 + 4) = 0;
          piVar18 = *(int **)(this + 0x18);
          piVar18[2] = *piVar18 + 1;
          pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
          piVar18[1] = (int)pvVar20;
          *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
          *piVar18 = piVar18[2];
          puVar12 = *(uint **)(this + 0x1fc);
          iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < *puVar12);
    }
    uVar13 = 0x4f6;
    break;
  case 2:
    iVar16 = 0x133;
    local_44 = 0x133;
    local_40[0] = 0x134;
    local_40[1] = 0x135;
    local_40[2] = 0x136;
    if (Globals::status[0xf8] != (Status)0x0) {
      local_40[2] = 0x137;
    }
    local_80 = 0x4000000020000;
    uStack_78 = 0x10000000080000;
    iVar11 = 0;
    while( true ) {
      pTVar7 = operator_new(0xc0);
      pSVar8 = (String *)GameText::getText(Globals::gameText,iVar16);
      TouchButton::TouchButton
                (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11','\x04')
      ;
      iVar16 = *(int *)((int)&local_80 + iVar11 * 4);
      *(int *)pTVar7 = iVar16;
      *(int *)(pTVar7 + 4) = iVar16 >> 0x1f;
      piVar18 = *(int **)(this + 0x18);
      piVar18[2] = *piVar18 + 1;
      pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
      piVar18[1] = (int)pvVar20;
      *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
      *piVar18 = piVar18[2];
      if (3 < iVar11 + 1) break;
      iVar16 = local_40[iVar11];
      iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
      iVar11 = iVar11 + 1;
    }
    uVar13 = 0x4f3;
    break;
  case 3:
    if (cVar2 != '\0') {
      *(int *)(this + 0x468) = *(int *)(iVar16 + 0x28) - *(int *)(this + 0x360);
    }
    iVar16 = Status::inAlienOrbit(Globals::status);
    if (iVar16 == 0) {
      pTVar7 = operator_new(0xc0);
      pSVar8 = (String *)GameText::getText(Globals::gameText,0x225);
      TouchButton::TouchButton
                (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11','\x04')
      ;
      *(undefined4 *)pTVar7 = 0x1000000;
      *(undefined4 *)(pTVar7 + 4) = 0;
      piVar18 = *(int **)(this + 0x18);
      piVar18[2] = *piVar18 + 1;
      pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
      piVar18[1] = (int)pvVar20;
      *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
      *piVar18 = piVar18[2];
      iVar21 = iVar21 + iVar15 + *(int *)(Globals::layout + 0x30);
      iVar16 = Status::inEmptyOrbit(Globals::status);
      if (iVar16 == 0) {
        pTVar7 = operator_new(0xc0);
        Status::getStation(Globals::status);
        Station::getName();
        AbyssEngine::String::String((String *)&local_80,aAStack_4c,false);
        this_00 = (Station *)Status::getStation(Globals::status);
        iVar16 = Station::getIndex(this_00);
        if (iVar16 != 0x65) {
          AbyssEngine::String::String(aSStack_5c," ",false);
          pSVar8 = (String *)GameText::getText(Globals::gameText,0x88);
          AbyssEngine::operator+((AbyssEngine *)aSStack_54,aSStack_5c,pSVar8);
        }
        else {
          AbyssEngine::String::String(aSStack_54,"",false);
        }
        AbyssEngine::operator+((AbyssEngine *)&local_44,(String *)&local_80,aSStack_54);
        TouchButton::TouchButton
                  (pTVar7,(String *)&local_44,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378)
                   ,'\x11','\x04');
        AbyssEngine::String::~String((String *)&local_44);
        AbyssEngine::String::~String(aSStack_54);
        if (iVar16 != 0x65) {
          AbyssEngine::String::~String(aSStack_5c);
        }
        AbyssEngine::String::~String((String *)&local_80);
        AbyssEngine::String::~String((String *)aAStack_4c);
        *(undefined4 *)pTVar7 = 0x800000;
        *(undefined4 *)(pTVar7 + 4) = 0;
        piVar18 = *(int **)(this + 0x18);
        piVar18[2] = *piVar18 + 1;
        pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
        piVar18[1] = (int)pvVar20;
        *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
        *piVar18 = piVar18[2];
        iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
      }
      this_01 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar16 = SolarSystem::currentOrbitHasWarpGate(this_01);
      if (iVar16 == 1) {
        pTVar7 = operator_new(0xc0);
        pSVar8 = (String *)GameText::getText(Globals::gameText,0x223);
        TouchButton::TouchButton
                  (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11',
                   '\x04');
        *(undefined4 *)pTVar7 = 0x400000;
        *(undefined4 *)(pTVar7 + 4) = 0;
        piVar18 = *(int **)(this + 0x18);
        piVar18[2] = *piVar18 + 1;
        pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
        piVar18[1] = (int)pvVar20;
        *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
        *piVar18 = piVar18[2];
        iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
      }
      pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
      iVar16 = PlayerEgo::getRoute(pPVar10);
      if (iVar16 != 0) {
        pPVar10 = (PlayerEgo *)Level::getPlayer(param_2);
        this_02 = (Route *)PlayerEgo::getRoute(pPVar10);
        iVar16 = Route::getLastWaypoint(this_02);
        if (*(char *)(iVar16 + 300) == '\0') {
          pTVar7 = operator_new(0xc0);
          pSVar8 = (String *)GameText::getText(Globals::gameText,0x23d);
          TouchButton::TouchButton
                    (pTVar7,pSVar8,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378),'\x11',
                     '\x04');
          *(undefined4 *)pTVar7 = 0x2000000;
          *(undefined4 *)(pTVar7 + 4) = 0;
          piVar18 = *(int **)(this + 0x18);
          piVar18[2] = *piVar18 + 1;
          pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
          piVar18[1] = (int)pvVar20;
          *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
          *piVar18 = piVar18[2];
          iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
        }
      }
      if (Level::programmedStation != 0) {
        pTVar7 = operator_new(0xc0);
        pSVar8 = (String *)GameText::getText(Globals::gameText,0x222);
        AbyssEngine::String::String((String *)aAStack_4c,": ",false);
        AbyssEngine::operator+((AbyssEngine *)&local_80,pSVar8,aAStack_4c);
        Station::getName();
        AbyssEngine::String::String(aSStack_54,(String *)local_64,false);
        AbyssEngine::operator+((AbyssEngine *)&local_44,(String *)&local_80,aSStack_54);
        TouchButton::TouchButton
                  (pTVar7,(String *)&local_44,0,*(int *)(this + 0x370),iVar21,*(int *)(this + 0x378)
                   ,'\x11','\x04');
        AbyssEngine::String::~String((String *)&local_44);
        AbyssEngine::String::~String(aSStack_54);
        AbyssEngine::String::~String((String *)local_64);
        AbyssEngine::String::~String((String *)&local_80);
        AbyssEngine::String::~String((String *)aAStack_4c);
        *(undefined4 *)pTVar7 = 0x200000;
        *(undefined4 *)(pTVar7 + 4) = 0;
        piVar18 = *(int **)(this + 0x18);
        piVar18[2] = *piVar18 + 1;
        pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
        piVar18[1] = (int)pvVar20;
        *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
        *piVar18 = piVar18[2];
        iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
      }
    }
    iVar16 = Level::getNumDockingTargets(param_2);
    if (0 < iVar16) {
      uVar14 = 0;
      do {
        Level::getDockingTarget(param_2,uVar14);
        PlayerFixedObject::getName();
        iVar11 = local_84;
        AbyssEngine::String::~String(aSStack_88);
        if (iVar11 != 0) {
          pTVar7 = operator_new(0xc0);
          Level::getDockingTarget(param_2,uVar14);
          PlayerFixedObject::getName();
          TouchButton::TouchButton
                    (pTVar7,(String *)&local_44,0,*(int *)(this + 0x370),iVar21,
                     *(int *)(this + 0x378),'\x11','\x04');
          AbyssEngine::String::~String((String *)&local_44);
          iVar11 = 0x4000000 << (uVar14 & 0xff);
          *(int *)pTVar7 = iVar11;
          *(int *)(pTVar7 + 4) = iVar11 >> 0x1f;
          piVar18 = *(int **)(this + 0x18);
          piVar18[2] = *piVar18 + 1;
          pvVar20 = realloc((void *)piVar18[1],(*piVar18 + 1) * 4);
          piVar18[1] = (int)pvVar20;
          *(TouchButton **)((int)pvVar20 + *piVar18 * 4) = pTVar7;
          *piVar18 = piVar18[2];
          iVar21 = iVar15 + iVar21 + *(int *)(Globals::layout + 0x30);
        }
        uVar14 = uVar14 + 1;
      } while ((int)uVar14 < iVar16);
    }
    if ((Globals::iPad == '\0') && (puVar12 = *(uint **)(this + 0x18), 4 < *puVar12)) {
      uVar14 = 0;
      do {
        pTVar7 = *(TouchButton **)(puVar12[1] + uVar14 * 4);
        TouchButton::getPosition();
        TouchButton::getPosition();
        fVar22 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x30),
                                            (byte)(in_fpscr >> 0x16) & 3);
        TouchButton::setPosition(pTVar7,(int)local_94,(int)(local_9c - fVar22));
        puVar12 = *(uint **)(this + 0x18);
        uVar14 = uVar14 + 1;
      } while (uVar14 < *puVar12);
    }
    uVar13 = 0x4f4;
    break;
  default:
    goto switchD_0018e23a_default;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar13,(uint *)(this + 0x2fc));
switchD_0018e23a_default:
  puVar12 = *(uint **)(this + 0x18);
  uVar14 = *puVar12;
  if (Globals::iPad == '\0') {
    if (uVar14 < 5) {
      *(undefined4 *)(this + 0x46c) = 0;
      if (uVar14 == 0) goto LAB_0018ee3c;
    }
    else {
      *(int *)(this + 0x46c) = -*(int *)(Globals::layout + 0x30);
    }
    uVar14 = 0;
    do {
      if ((int)uVar14 < 10) {
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_x + uVar14 * 4) = (int)local_c4;
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_y + uVar14 * 4) = (int)local_cc;
        puVar12 = *(uint **)(this + 0x18);
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < *puVar12);
  }
  else if (uVar14 != 0) {
    uVar19 = 0;
    iVar16 = (4 - uVar14) * (iVar15 + *(int *)(Globals::layout + 0x30));
    if (param_1 == 3) {
      iVar16 = iVar16 - *(int *)(Globals::layout + 0x30);
    }
    *(int *)(this + 0x46c) = iVar16;
    while( true ) {
      TouchButton::translate
                (*(TouchButton **)(puVar12[1] + uVar19 * 4),*(int *)(this + 0x468),iVar16);
      if ((int)uVar19 < 10) {
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_x + uVar19 * 4) = (int)local_ac;
        TouchButton::getPosition();
        *(int *)(Globals::sub_menu_buttons_y + uVar19 * 4) = (int)local_b4;
      }
      puVar12 = *(uint **)(this + 0x18);
      uVar19 = uVar19 + 1;
      if (*puVar12 <= uVar19) break;
      iVar16 = *(int *)(this + 0x46c);
    }
  }
LAB_0018ee3c:
  this[0x222] = (Hud)0x1;
  if (__stack_chk_guard == local_40[3]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Hud::setCurrentSecondaryWeapon  @0x0018f090  (10 bytes)
/* Hud::setCurrentSecondaryWeapon(Item*) */

void __thiscall Hud::setCurrentSecondaryWeapon(Hud *this,Item *param_1)

{
  *(Item **)(this + 0x1f8) = param_1;
  updateSecondaryWeaponString(this);
  return;
}

// ===== Hud::drawEventQueue  @0x0018f098  (374 bytes)
/* Hud::drawEventQueue() */

void __thiscall Hud::drawEventQueue(Hud *this)

{
  PaintCanvas *this_00;
  char cVar1;
  uchar uVar2;
  int iVar3;
  uchar uVar4;
  uchar uVar5;
  uint uVar6;
  int iVar7;
  String *pSVar8;
  uint uVar9;
  int iVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  
  cVar1 = Radar::drawTarget;
  if (Radar::drawTarget == '\0') {
    uVar9 = 0;
  }
  else {
    uVar9 = (uint)*(ushort *)(this + 0x37e);
  }
  VectorSignedToFloat(*(undefined4 *)(this + 0x208),(byte)(in_fpscr >> 0x16) & 3);
  iVar10 = *(int *)(Globals::layout + 0x1e4);
  fVar12 = *(float *)(Globals::layout + 0x1e0);
  AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
  uVar6 = 0;
  if (Radar::drawTarget != '\0') {
    uVar6 = *(uint *)(this + 0x37c) >> 0x10;
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x2f4),*(uint *)(this + 0x37c) & 0xffff,
             uVar6 - *(int *)(Globals::layout + 0x1e4));
  fVar11 = -2.0;
  if (cVar1 != '\0') {
    fVar11 = -1.0;
  }
  iVar7 = *(int *)(*(int *)(*(int *)(this + 0x204) + 4) + 4);
  if (iVar7 == 0) goto LAB_0018f1e6;
  iVar3 = *(int *)(iVar7 + 0x30);
  if (iVar3 == 2) {
    uVar2 = '\0';
    uVar4 = 0xed;
LAB_0018f196:
    uVar5 = '\0';
  }
  else {
    if (iVar3 == 1) {
      uVar2 = 0xff;
      uVar4 = '*';
      goto LAB_0018f196;
    }
    if (iVar3 == 3) {
      uVar2 = 0xff;
      uVar4 = 0x80;
      goto LAB_0018f196;
    }
    uVar2 = 0xff;
    uVar4 = 0xff;
    uVar5 = 0xff;
  }
  AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,uVar2,uVar4,uVar5);
  iVar3 = Globals::w;
  uVar6 = Globals::font;
  this_00 = Globals::Canvas;
  pSVar8 = *(String **)(iVar7 + 0x1c);
  iVar7 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,pSVar8);
  AbyssEngine::PaintCanvas::DrawString
            (this_00,uVar6,pSVar8,(iVar3 >> 1) - iVar7 / 2,uVar9 + iVar10 + (int)(fVar12 * fVar11),
             false);
LAB_0018f1e6:
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  return;
}

// ===== Hud::addToEventQueue  @0x0018f244  (52 bytes)
/* Hud::addToEventQueue(ListItem*) */

void __thiscall Hud::addToEventQueue(Hud *this,ListItem *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = **(uint **)(this + 0x204);
  if (1 < uVar3) {
    uVar2 = (*(uint **)(this + 0x204))[1];
    uVar1 = 1;
    while (*(int *)(uVar2 + uVar1 * 4) != 0) {
      uVar1 = uVar1 + 1;
      if (uVar3 <= uVar1) {
        return;
      }
    }
    *(ListItem **)(uVar2 + uVar1 * 4) = param_1;
    this[0x20c] = (Hud)0x1;
  }
  return;
}

// ===== Hud::setTimeExtender  @0x0018f278  (40 bytes)
/* Hud::setTimeExtender(bool, bool, bool, bool) */

void __thiscall Hud::setTimeExtender(Hud *this,bool param_1,bool param_2,bool param_3,bool param_4)

{
  *this = (Hud)param_1;
  this[0x220] = (Hud)param_3;
  this[0x221] = (Hud)param_4;
  if (param_2) {
    if (param_3) {
      *(undefined4 *)(this + 0x458) = 0x50;
      *(undefined4 *)(this + 0x45c) = 2000;
    }
    return;
  }
  return;
}

// ===== Hud::updateQueue  @0x0018f2a0  (132 bytes)
/* Hud::updateQueue(int) */

void __thiscall Hud::updateQueue(Hud *this,int param_1)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  iVar1 = *(int *)(this + 0x208) + param_1;
  *(int *)(this + 0x208) = iVar1;
  if (iVar1 < 0xfa1) {
    if (iVar1 < 0x7d1) {
      return;
    }
    if (*(int *)(this + 0x210) != 0) {
      return;
    }
    uVar4 = 1;
  }
  else {
    *(undefined4 *)(this + 0x208) = 0;
    puVar5 = *(undefined4 **)(*(int *)(this + 0x204) + 4);
    if ((ListItem *)*puVar5 != (ListItem *)0x0) {
      pvVar2 = (void *)::ListItem::~ListItem((ListItem *)*puVar5);
      operator_delete(pvVar2);
      puVar5 = *(undefined4 **)(*(int *)(this + 0x204) + 4);
    }
    *puVar5 = 0;
    uVar3 = (*(uint **)(this + 0x204))[1];
    if (1 < **(uint **)(this + 0x204)) {
      iVar1 = 0;
      do {
        *(undefined4 *)(uVar3 + iVar1 * 4) = *(undefined4 *)(uVar3 + iVar1 * 4 + 4);
        uVar6 = iVar1 + 2;
        iVar1 = iVar1 + 1;
        uVar3 = (*(uint **)(this + 0x204))[1];
      } while (uVar6 < **(uint **)(this + 0x204));
    }
    if (*(int *)(uVar3 + 4) == 0) {
      this[0x20c] = (Hud)0x0;
    }
    uVar4 = 0;
  }
  *(undefined4 *)(this + 0x210) = uVar4;
  return;
}

// ===== Hud::clearQueue  @0x0018f324  (70 bytes)
/* Hud::clearQueue() */

void __thiscall Hud::clearQueue(Hud *this)

{
  uint *puVar1;
  ListItem *this_00;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(this + 0x204);
  if (1 < *puVar1) {
    uVar4 = 1;
    do {
      uVar3 = puVar1[1];
      this_00 = *(ListItem **)(uVar3 + uVar4 * 4);
      if (this_00 != (ListItem *)0x0) {
        pvVar2 = (void *)::ListItem::~ListItem(this_00);
        operator_delete(pvVar2);
        uVar3 = *(uint *)(*(int *)(this + 0x204) + 4);
      }
      *(undefined4 *)(uVar3 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1;
      puVar1 = *(uint **)(this + 0x204);
    } while (uVar4 < *puVar1);
  }
  *(undefined4 *)(this + 0x210) = 0;
  return;
}

// ===== Hud::hudEventMedal  @0x0018f36c  (374 bytes)
/* Hud::hudEventMedal(int, int) */

void Hud::hudEventMedal(int param_1,int param_2)

{
  String *pSVar1;
  int iVar2;
  ListItem *this;
  String *this_00;
  uint uVar3;
  undefined4 extraout_r1;
  uint uVar4;
  uint uVar5;
  String *this_01;
  String aSStack_58 [8];
  String aSStack_50 [8];
  undefined4 local_48 [2];
  String aSStack_40 [8];
  AbyssEngine aAStack_38 [8];
  AbyssEngine aAStack_30 [8];
  AbyssEngine aAStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pSVar1 = (String *)GameText::getText(Globals::gameText,param_2 + 0x5e3);
  AbyssEngine::String::String(aSStack_40,":",false);
  AbyssEngine::operator+(aAStack_38,pSVar1,aSStack_40);
  local_48[0] = 0;
  AbyssEngine::String::Set(CONCAT44(extraout_r1,local_48));
  AbyssEngine::operator+(aAStack_30,aAStack_38,(String *)local_48);
  AbyssEngine::String::String(aSStack_50,"%",false);
  AbyssEngine::operator+(aAStack_28,aAStack_30,aSStack_50);
  this_01 = (String *)(param_1 + 400);
  AbyssEngine::String::operator=(this_01,aAStack_28);
  AbyssEngine::String::~String((String *)aAStack_28);
  AbyssEngine::String::~String(aSStack_50);
  AbyssEngine::String::~String((String *)aAStack_30);
  AbyssEngine::String::~String((String *)local_48);
  AbyssEngine::String::~String((String *)aAStack_38);
  AbyssEngine::String::~String(aSStack_40);
  AbyssEngine::String::String(aSStack_58,this_01,false);
  iVar2 = sameHudEventAsBefore((Hud *)param_1,aSStack_58);
  AbyssEngine::String::~String(aSStack_58);
  if (iVar2 == 0) {
    this = operator_new(0x48);
    this_00 = operator_new(8);
    AbyssEngine::String::String(this_00,this_01,false);
    ::ListItem::ListItem(this,this_00,3);
    uVar3 = **(uint **)(param_1 + 0x204);
    if (1 < uVar3) {
      uVar4 = (*(uint **)(param_1 + 0x204))[1];
      uVar5 = 1;
      do {
        if (*(int *)(uVar4 + uVar5 * 4) == 0) {
          *(ListItem **)(uVar4 + uVar5 * 4) = this;
          *(undefined1 *)(param_1 + 0x20c) = 1;
          break;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar3);
    }
    iVar2 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,this_01);
    *(bool *)(param_1 + 0x198) =
         (Globals::w / 2 - *(int *)(param_1 + 0x484)) + *(int *)(param_1 + 0x48c) * -2 < iVar2;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined1 *)(param_1 + 0x18e) = 1;
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Hud::sameHudEventAsBefore  @0x0018f55c  (66 bytes)
/* Hud::sameHudEventAsBefore(AbyssEngine::String) */

undefined4 __thiscall Hud::sameHudEventAsBefore(Hud *this,String *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(this + 0x204);
  iVar4 = *piVar2 + -1;
  if (0 < iVar4) {
    while( true ) {
      iVar3 = *(int *)(piVar2[1] + iVar4 * 4);
      if ((iVar3 != 0) &&
         (cVar1 = AbyssEngine::String::Compare(*(String **)(iVar3 + 0x1c),param_2), cVar1 == '\0'))
      {
        return 1;
      }
      iVar4 = iVar4 + -1;
      if (iVar4 < 1) break;
      piVar2 = *(int **)(this + 0x204);
    }
  }
  return 0;
}

// ===== Hud::hudEvent  @0x0018f5a0  (2462 bytes)
/* Hud::hudEvent(int, PlayerEgo*, int) */

void Hud::hudEvent(int param_1,PlayerEgo *param_2,int param_3)

{
  Station *this;
  int iVar1;
  ListItem *this_00;
  String *pSVar2;
  uint uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  uint uVar4;
  uint uVar5;
  String *pSVar6;
  float fVar7;
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  undefined4 local_50 [2];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  AbyssEngine aAStack_30 [8];
  AbyssEngine aAStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  switch(param_2) {
  case (PlayerEgo *)0x1:
    if (*(char *)(param_1 + 0x1c5) == '\0') goto LAB_0018ff84;
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x25);
    AbyssEngine::String::String(aSStack_38," ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x26);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    goto LAB_0018fcde;
  case (PlayerEgo *)0x2:
    if (*(char *)(param_1 + 0x1c5) == '\0') goto LAB_0018ff84;
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x25);
    AbyssEngine::String::String(aSStack_38," ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x27);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    goto LAB_0018fcde;
  case (PlayerEgo *)0x3:
    if ((*(char *)(param_1 + 0x1c2) == '\0') ||
       (iVar1 = PlayerEgo::readyToBoost((PlayerEgo *)param_3), iVar1 != 1)) goto LAB_0018ff84;
    iVar1 = 0x13a;
    break;
  case (PlayerEgo *)0x4:
    if (*(char *)(param_1 + 0x1c2) == '\0') goto LAB_0018ff84;
    iVar1 = 0x13b;
    break;
  case (PlayerEgo *)0x5:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x23b);
    AbyssEngine::String::String(aSStack_38," ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x26);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_38);
    goto LAB_0018fe6a;
  case (PlayerEgo *)0x6:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x23b);
    AbyssEngine::String::String(aSStack_38," ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x27);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_38);
    iVar1 = 0x1d;
    goto LAB_0018fe72;
  case (PlayerEgo *)0x7:
    iVar1 = 0x229;
    break;
  case (PlayerEgo *)0x8:
    iVar1 = 0x21b;
    break;
  case (PlayerEgo *)0x9:
    iVar1 = 0x21c;
    break;
  case (PlayerEgo *)0xa:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x222);
    AbyssEngine::String::String(aSStack_40,": ",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_38,pSVar6,aSStack_40);
    Status::getStation(Globals::status);
    Station::getName();
    AbyssEngine::String::String(aSStack_48,(String *)local_50,false);
    AbyssEngine::operator+(aAStack_30,aSStack_38,aSStack_48);
    this = (Station *)Status::getStation(Globals::status);
    iVar1 = Station::getIndex(this);
    if (iVar1 != 0x65) {
      AbyssEngine::String::String(aSStack_60," ",false);
      pSVar6 = (String *)GameText::getText(Globals::gameText,0x88);
      AbyssEngine::operator+((AbyssEngine *)aSStack_58,aSStack_60,pSVar6);
    }
    else {
      AbyssEngine::String::String(aSStack_58,"",false);
    }
    AbyssEngine::operator+(aAStack_28,aAStack_30,aSStack_58);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String(aSStack_58);
    if (iVar1 != 0x65) {
      AbyssEngine::String::~String(aSStack_60);
    }
    AbyssEngine::String::~String((String *)aAStack_30);
    AbyssEngine::String::~String(aSStack_48);
    AbyssEngine::String::~String((String *)local_50);
    AbyssEngine::String::~String(aSStack_38);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_40);
    goto LAB_0018fe6a;
  case (PlayerEgo *)0xb:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x222);
    AbyssEngine::String::String(aSStack_38,": ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x226);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_38);
    goto LAB_0018fe6a;
  case (PlayerEgo *)0xc:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x222);
    AbyssEngine::String::String(aSStack_38,": ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x223);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_38);
    goto LAB_0018fe6a;
  case (PlayerEgo *)0xd:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x222);
    AbyssEngine::String::String(aSStack_38,": ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x224);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_38);
    goto LAB_0018fe6a;
  case (PlayerEgo *)0xe:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x222);
    AbyssEngine::String::String(aSStack_38,": ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x225);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_38);
    goto LAB_0018fe6a;
  case (PlayerEgo *)0xf:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x222);
    AbyssEngine::String::String(aSStack_38,": ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x221);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    fVar7 = (float)AbyssEngine::String::~String(aSStack_38);
LAB_0018fe6a:
    iVar1 = 0x1c;
LAB_0018fe72:
    FModSound::play(Globals::sound,iVar1,(Vector *)0x0,(Vector *)0x0,fVar7);
    goto LAB_0018fe7c;
  case (PlayerEgo *)0x10:
    iVar1 = 0x133;
    break;
  case (PlayerEgo *)0x11:
    iVar1 = 0x134;
    break;
  case (PlayerEgo *)0x12:
    iVar1 = 0x135;
    break;
  case (PlayerEgo *)0x13:
    pSVar6 = (String *)(param_1 + 0xb4);
    goto LAB_0018fd4c;
  case (PlayerEgo *)0x14:
    iVar1 = 0x21d;
    break;
  case (PlayerEgo *)0x15:
    iVar1 = 0x20d;
    break;
  case (PlayerEgo *)0x16:
    iVar1 = 0x21e;
    break;
  case (PlayerEgo *)0x17:
    iVar1 = 0x21f;
    break;
  case (PlayerEgo *)0x18:
    iVar1 = 0x220;
    break;
  case (PlayerEgo *)0x19:
    *(undefined1 *)(param_1 + 0x217) = 1;
    goto LAB_0018fb9c;
  case (PlayerEgo *)0x1a:
    *(undefined1 *)(param_1 + 0x217) = 0;
    goto LAB_0018ff84;
  case (PlayerEgo *)0x1b:
    iVar1 = 0x142;
    break;
  case (PlayerEgo *)0x1c:
    *(undefined1 *)(param_1 + 0x216) = 1;
LAB_0018fb9c:
    *(undefined4 *)(param_1 + 0x400) = 0;
    goto LAB_0018ff84;
  case (PlayerEgo *)0x1d:
    *(undefined1 *)(param_1 + 0x216) = 0;
    goto LAB_0018ff84;
  case (PlayerEgo *)0x1e:
    AbyssEngine::String::String(aSStack_48,"-",false);
    local_50[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1,local_50));
    AbyssEngine::operator+((AbyssEngine *)aSStack_40,aSStack_48,(String *)local_50);
    AbyssEngine::String::String(aSStack_58,"t ",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_38,aSStack_40,aSStack_58);
    AbyssEngine::String::String((String *)aAStack_30,aSStack_38,false);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x574);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    goto LAB_0018fdc0;
  case (PlayerEgo *)0x1f:
    iVar1 = 0x144;
    break;
  case (PlayerEgo *)0x20:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0xda);
    AbyssEngine::String::String(aSStack_38," ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x26);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
    goto LAB_0018fcde;
  case (PlayerEgo *)0x21:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0xda);
    AbyssEngine::String::String(aSStack_38," ",false);
    AbyssEngine::operator+(aAStack_30,pSVar6,aSStack_38);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x27);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
LAB_0018fcde:
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    AbyssEngine::String::~String(aSStack_38);
    goto LAB_0018fe7c;
  case (PlayerEgo *)0x22:
    iVar1 = 0xc7f;
    break;
  case (PlayerEgo *)0x23:
    *(undefined1 *)(param_1 + 0x21a) = 1;
    *(undefined4 *)(param_1 + 0x404) = 0;
    *(undefined2 *)(param_1 + 0x218) = 1;
    goto LAB_0018ff84;
  case (PlayerEgo *)0x24:
  case (PlayerEgo *)0x26:
  case (PlayerEgo *)0x28:
  case (PlayerEgo *)0x2a:
    pSVar6 = (String *)GameText::getText(Globals::gameText,0xc80);
    AbyssEngine::String::operator=((String *)(param_1 + 400),pSVar6);
    *(undefined1 *)(param_1 + 0x218) = 0;
    goto LAB_0018fe7c;
  case (PlayerEgo *)0x25:
    *(undefined1 *)(param_1 + 0x21a) = 1;
    *(undefined4 *)(param_1 + 0x404) = 0;
    *(undefined2 *)(param_1 + 0x218) = 0x101;
    goto LAB_0018ff84;
  case (PlayerEgo *)0x27:
    *(undefined1 *)(param_1 + 0x21a) = 0;
    *(undefined4 *)(param_1 + 0x404) = 0;
    *(undefined2 *)(param_1 + 0x218) = 1;
    goto LAB_0018ff84;
  case (PlayerEgo *)0x29:
    *(undefined1 *)(param_1 + 0x21a) = 0;
    *(undefined4 *)(param_1 + 0x404) = 0;
    *(undefined2 *)(param_1 + 0x218) = 0x101;
    goto LAB_0018fe7c;
  case (PlayerEgo *)0x2b:
    iVar1 = 0xc83;
    break;
  case (PlayerEgo *)0x2c:
    iVar1 = 0xc81;
    break;
  case (PlayerEgo *)0x2d:
    iVar1 = 0xc82;
    break;
  case (PlayerEgo *)0x2e:
    iVar1 = 0x13c;
    break;
  case (PlayerEgo *)0x2f:
    AbyssEngine::String::String(aSStack_48,"-",false);
    local_50[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_50));
    AbyssEngine::operator+((AbyssEngine *)aSStack_40,aSStack_48,(String *)local_50);
    AbyssEngine::String::String(aSStack_58,"t ",false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_38,aSStack_40,aSStack_58);
    AbyssEngine::String::String((String *)aAStack_30,aSStack_38,false);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x5c4);
    AbyssEngine::operator+(aAStack_28,aAStack_30,pSVar6);
    AbyssEngine::String::operator=((String *)(param_1 + 400),aAStack_28);
LAB_0018fdc0:
    AbyssEngine::String::~String((String *)aAStack_28);
    AbyssEngine::String::~String((String *)aAStack_30);
    AbyssEngine::String::~String(aSStack_38);
    AbyssEngine::String::~String(aSStack_58);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String((String *)local_50);
    AbyssEngine::String::~String(aSStack_48);
    clearQueue((Hud *)param_1);
  default:
    goto LAB_0018fe7c;
  }
  pSVar6 = (String *)GameText::getText(Globals::gameText,iVar1);
LAB_0018fd4c:
  AbyssEngine::String::operator=((String *)(param_1 + 400),pSVar6);
LAB_0018fe7c:
  pSVar6 = (String *)(param_1 + 400);
  AbyssEngine::String::String(aSStack_68,pSVar6,false);
  iVar1 = sameHudEventAsBefore((Hud *)param_1,aSStack_68);
  AbyssEngine::String::~String(aSStack_68);
  if (iVar1 == 0) {
    this_00 = operator_new(0x48);
    if ((param_2 + -0x1b < (PlayerEgo *)0x15) &&
       ((1 << ((uint)(param_2 + -0x1b) & 0xff) & 0x100019U) != 0)) {
      pSVar2 = operator_new(8);
      AbyssEngine::String::String(pSVar2,pSVar6,false);
      ::ListItem::ListItem(this_00,pSVar2,1);
      uVar3 = **(uint **)(param_1 + 0x204);
      if (1 < uVar3) {
        uVar4 = (*(uint **)(param_1 + 0x204))[1];
        uVar5 = 1;
        do {
          if (*(int *)(uVar4 + uVar5 * 4) == 0) goto LAB_0018ff2e;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar3);
      }
    }
    else {
      pSVar2 = operator_new(8);
      AbyssEngine::String::String(pSVar2,pSVar6,false);
      ::ListItem::ListItem(this_00,pSVar2);
      uVar3 = **(uint **)(param_1 + 0x204);
      if (1 < uVar3) {
        uVar4 = (*(uint **)(param_1 + 0x204))[1];
        uVar5 = 1;
        do {
          if (*(int *)(uVar4 + uVar5 * 4) == 0) goto LAB_0018ff2e;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar3);
      }
    }
LAB_0018ff38:
    iVar1 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,pSVar6);
    *(bool *)(param_1 + 0x198) =
         (Globals::w / 2 - *(int *)(param_1 + 0x484)) + *(int *)(param_1 + 0x48c) * -2 < iVar1;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined1 *)(param_1 + 0x18e) = 1;
  }
LAB_0018ff84:
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0018ff2e:
  *(ListItem **)(uVar4 + uVar5 * 4) = this_00;
  *(undefined1 *)(param_1 + 0x20c) = 1;
  goto LAB_0018ff38;
}

// ===== Hud::sameHudEventAsBeforeAggregate  @0x0019022c  (66 bytes)
/* Hud::sameHudEventAsBeforeAggregate(AbyssEngine::String) */

int __thiscall Hud::sameHudEventAsBeforeAggregate(Hud *this,String *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(this + 0x204);
  iVar4 = *piVar2 + -1;
  if (0 < iVar4) {
    while( true ) {
      iVar3 = *(int *)(piVar2[1] + iVar4 * 4);
      if ((iVar3 != 0) &&
         (cVar1 = AbyssEngine::String::Compare(*(String **)(iVar3 + 0x1c),param_2), cVar1 == '\0'))
      {
        return iVar4;
      }
      iVar4 = iVar4 + -1;
      if (iVar4 < 1) break;
      piVar2 = *(int **)(this + 0x204);
    }
  }
  return -1;
}

// ===== Hud::playerHit  @0x0019026e  (14 bytes)
/* Hud::playerHit() */

void __thiscall Hud::playerHit(Hud *this)

{
  this[0x1e4] = (Hud)0x1;
  *(undefined4 *)(this + 0x408) = 0;
  return;
}

// ===== Hud::catchCargo  @0x0019027c  (1024 bytes)
/* Hud::catchCargo(int, int, bool, bool, bool, bool, bool) */

void __thiscall
Hud::catchCargo(Hud *this,int param_1,int param_2,bool param_3,bool param_4,bool param_5,
               bool param_6,bool param_7)

{
  Status *pSVar1;
  GameText *this_00;
  String *pSVar2;
  Mission *this_01;
  int iVar3;
  undefined4 uVar4;
  ListItem *pLVar5;
  String *this_02;
  uint uVar6;
  int iVar7;
  undefined4 extraout_r1;
  uint uVar8;
  undefined4 extraout_r1_00;
  int extraout_r1_01;
  uint uVar9;
  String *pSVar10;
  undefined3 in_stack_00000001;
  undefined3 in_stack_00000005;
  undefined3 in_stack_00000009;
  undefined3 in_stack_0000000d;
  String aSStack_8c [8];
  String aSStack_84 [8];
  undefined4 local_7c [2];
  undefined4 local_74 [2];
  AbyssEngine aAStack_6c [8];
  String aSStack_64 [8];
  String aSStack_5c [8];
  undefined4 local_54 [2];
  String aSStack_4c [8];
  String aSStack_44 [8];
  String aSStack_3c [8];
  String aSStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  this[0x1d5] = (Hud)param_3;
  *(undefined4 *)(this + 0x180) = 0;
  if (_param_4 == 1) {
    pSVar2 = (String *)GameText::getText(Globals::gameText,0x219);
    pSVar10 = (String *)(this + 0x1a0);
    AbyssEngine::String::operator=(pSVar10,pSVar2);
    pSVar1 = Globals::status;
    AbyssEngine::String::String(aSStack_34,pSVar10,false);
    this_00 = Globals::gameText;
    this_01 = (Mission *)Status::getMission(Globals::status);
    iVar3 = Mission::getType(this_01);
    iVar7 = 0x56f;
    if (iVar3 == 3) {
      iVar7 = 0x56e;
    }
    pSVar2 = (String *)GameText::getText(this_00,iVar7);
    AbyssEngine::String::String(aSStack_3c,pSVar2,false);
    uVar4 = AbyssEngine::String::String(aSStack_44,"#N",false);
    Status::replaceHash(aSStack_2c,pSVar1,aSStack_34,aSStack_3c,uVar4);
    AbyssEngine::String::operator=(pSVar10,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    AbyssEngine::String::~String(aSStack_44);
    AbyssEngine::String::~String(aSStack_3c);
    AbyssEngine::String::~String(aSStack_34);
    pSVar1 = Globals::status;
    AbyssEngine::String::String(aSStack_4c,pSVar10,false);
    local_54[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1,local_54));
    uVar4 = AbyssEngine::String::String(aSStack_5c,"#Q",false);
    Status::replaceHash(aSStack_2c,pSVar1,aSStack_4c,local_54,uVar4);
    AbyssEngine::String::operator=(pSVar10,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    AbyssEngine::String::~String(aSStack_5c);
    AbyssEngine::String::~String((String *)local_54);
    AbyssEngine::String::~String(aSStack_4c);
    pLVar5 = operator_new(0x48);
    this_02 = operator_new(8);
    AbyssEngine::String::String(this_02,pSVar10,false);
    ::ListItem::ListItem(pLVar5,this_02);
    *(int *)(pLVar5 + 0x2c) = param_1;
    uVar6 = **(uint **)(this + 0x204);
    if (1 < uVar6) {
      uVar8 = (*(uint **)(this + 0x204))[1];
      uVar9 = 1;
      do {
        if (*(int *)(uVar8 + uVar9 * 4) == 0) goto LAB_0019057a;
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar6);
    }
  }
  else if (param_3) {
    pSVar2 = (String *)GameText::getText(Globals::gameText,0x142);
    AbyssEngine::String::operator=((String *)(this + 0x1a0),pSVar2);
    pLVar5 = operator_new(0x48);
    pSVar10 = operator_new(8);
    AbyssEngine::String::String(pSVar10,(String *)(this + 0x1a0),false);
    ::ListItem::ListItem(pLVar5,pSVar10,1);
    uVar6 = **(uint **)(this + 0x204);
    if (1 < uVar6) {
      uVar8 = (*(uint **)(this + 0x204))[1];
      uVar9 = 1;
      do {
        if (*(int *)(uVar8 + uVar9 * 4) == 0) goto LAB_0019057a;
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar6);
    }
  }
  else if (0 < param_2) {
    if ((_param_7 == 1) && (this[0x20c] != (Hud)0x0)) {
      local_74[0] = 0;
      AbyssEngine::String::Set(CONCAT44(_param_4,local_74));
      AbyssEngine::String::String((String *)local_7c,"t ",false);
      AbyssEngine::operator+(aAStack_6c,(String *)local_74,(String *)local_7c);
      AbyssEngine::String::String(aSStack_64,aAStack_6c,false);
      pSVar2 = (String *)GameText::getText(Globals::gameText,param_1 + 0x4fa);
      AbyssEngine::operator+((AbyssEngine *)aSStack_2c,aSStack_64,pSVar2);
      AbyssEngine::String::~String(aSStack_64);
      AbyssEngine::String::~String((String *)aAStack_6c);
      AbyssEngine::String::~String((String *)local_7c);
      AbyssEngine::String::~String((String *)local_74);
      AbyssEngine::String::String(aSStack_84,aSStack_2c,false);
      iVar3 = sameHudEventAsBeforeAggregate(this,aSStack_84);
      AbyssEngine::String::~String(aSStack_84);
      if (-1 < iVar3) {
        *(int *)(this + 0x4c4) = *(int *)(this + 0x4c4) + param_2;
        *(undefined4 *)(this + 0x208) = 2000;
        pSVar10 = *(String **)(*(int *)(*(int *)(*(int *)(this + 0x204) + 4) + iVar3 * 4) + 0x1c);
        local_7c[0] = 0;
        AbyssEngine::String::Set(CONCAT44(extraout_r1_00,local_7c));
        AbyssEngine::String::String(aSStack_8c,"t ",false);
        AbyssEngine::operator+((AbyssEngine *)local_74,(String *)local_7c,aSStack_8c);
        AbyssEngine::String::String((String *)aAStack_6c,(String *)local_74,false);
        pSVar2 = (String *)GameText::getText(Globals::gameText,param_1 + 0x4fa);
        AbyssEngine::operator+((AbyssEngine *)aSStack_64,aAStack_6c,pSVar2);
        AbyssEngine::String::operator=(pSVar10,aSStack_64);
        AbyssEngine::String::~String(aSStack_64);
        AbyssEngine::String::~String((String *)aAStack_6c);
        AbyssEngine::String::~String((String *)local_74);
        AbyssEngine::String::~String(aSStack_8c);
        AbyssEngine::String::~String((String *)local_7c);
        AbyssEngine::String::~String(aSStack_2c);
        goto LAB_0019065e;
      }
      AbyssEngine::String::~String(aSStack_2c);
      _param_4 = extraout_r1_01;
    }
    *(int *)(this + 0x4c4) = param_2;
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(_param_4,local_74));
    AbyssEngine::String::String((String *)local_7c,"t ",false);
    AbyssEngine::operator+(aAStack_6c,(String *)local_74,(String *)local_7c);
    AbyssEngine::String::String(aSStack_64,aAStack_6c,false);
    pSVar2 = (String *)GameText::getText(Globals::gameText,param_1 + 0x4fa);
    AbyssEngine::operator+((AbyssEngine *)aSStack_2c,aSStack_64,pSVar2);
    AbyssEngine::String::operator=((String *)(this + 0x1a0),aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    AbyssEngine::String::~String(aSStack_64);
    AbyssEngine::String::~String((String *)aAStack_6c);
    AbyssEngine::String::~String((String *)local_7c);
    AbyssEngine::String::~String((String *)local_74);
    pLVar5 = operator_new(0x48);
    pSVar10 = operator_new(8);
    AbyssEngine::String::String(pSVar10,(String *)(this + 0x1a0),false);
    ::ListItem::ListItem(pLVar5,pSVar10);
    *(int *)(pLVar5 + 0x2c) = param_1;
    if ((_param_5 != 0) || (_param_6 == 0)) {
      *(undefined4 *)(pLVar5 + 0x30) = 2;
    }
    if (_param_6 == 1) {
      pLVar5[0x24] = (ListItem)0x1;
    }
    uVar6 = **(uint **)(this + 0x204);
    if (1 < uVar6) {
      uVar8 = (*(uint **)(this + 0x204))[1];
      uVar9 = 1;
      do {
        if (*(int *)(uVar8 + uVar9 * 4) == 0) {
          *(ListItem **)(uVar8 + uVar9 * 4) = pLVar5;
          goto LAB_0019057e;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar6);
    }
  }
  goto LAB_0019065e;
LAB_0019057a:
  *(ListItem **)(uVar8 + uVar9 * 4) = pLVar5;
LAB_0019057e:
  this[0x20c] = (Hud)0x1;
LAB_0019065e:
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Hud::cargoFull  @0x001907ac  (6 bytes)
/* Hud::cargoFull() */

Hud __thiscall Hud::cargoFull(Hud *this)

{
  return this[0x1d5];
}

// ===== Hud::setHackingGameActive  @0x001907b2  (6 bytes)
/* Hud::setHackingGameActive(bool) */

void __thiscall Hud::setHackingGameActive(Hud *this,bool param_1)

{
  this[0x4c0] = (Hud)param_1;
  return;
}

// ===== Hud::isHackingGameActive  @0x001907b8  (6 bytes)
/* Hud::isHackingGameActive() */

Hud __thiscall Hud::isHackingGameActive(Hud *this)

{
  return this[0x4c0];
}

// ===== Hud::firePressed  @0x001907be  (10 bytes)
/* Hud::firePressed() */

uint __thiscall Hud::firePressed(Hud *this)

{
  return ((byte)this[0x224] & 0x1f) >> 4;
}

// ===== Hud::drawEventString  @0x001907c8  (158 bytes)
/* Hud::drawEventString(AbyssEngine::String, bool) */

void __thiscall Hud::drawEventString(Hud *this,String *param_2,int param_3)

{
  PaintCanvas *this_00;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = Globals::w;
  uVar1 = Globals::font;
  this_00 = Globals::Canvas;
  if (this[0x198] == (Hud)0x0) {
    iVar3 = *(int *)(this + 0x484);
    iVar4 = *(int *)(this + 0x110);
    if (param_3 == 1) {
      iVar3 = -3 - iVar3;
    }
    else {
      iVar2 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_2);
      iVar3 = (iVar3 + 3) - iVar2;
    }
    iVar2 = *(int *)(this + 0x114);
    iVar3 = iVar3 + iVar4;
  }
  else {
    iVar3 = *(int *)(this + 0x48c);
    if (param_3 == 1) {
      iVar3 = iVar3 + 1;
    }
    else {
      iVar2 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,param_2);
      iVar3 = ((iVar4 + -1) - iVar3) - iVar2;
    }
    iVar2 = *(int *)(this + 0x114);
  }
  AbyssEngine::PaintCanvas::DrawString(this_00,uVar1,param_2,iVar3,iVar2 + -1,false);
  return;
}

// ===== Hud::drawPauseButton  @0x00190874  (68 bytes)
/* Hud::drawPauseButton() */

void __thiscall Hud::drawPauseButton(Hud *this)

{
  uint uVar1;
  
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  if (((byte)this[0x224] & 1) == 0) {
    uVar1 = *(uint *)(this + 0x298);
  }
  else {
    uVar1 = *(uint *)(this + 0x294);
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,uVar1,(int)*(undefined2 *)(this + 0x3a6),
             (int)*(undefined2 *)(this + 0x3a8));
  return;
}

// ===== Hud::drawChallengeModeScore  @0x001908bc  (930 bytes)
/* Hud::drawChallengeModeScore(int) */

void Hud::drawChallengeModeScore(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  Sprite *this;
  int iVar8;
  int iVar9;
  uint in_fpscr;
  undefined8 uVar10;
  String aSStack_64 [8];
  String aSStack_5c [8];
  String aSStack_54 [8];
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  uint local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar1 = Sprite::getFrameWidth(*(Sprite **)(param_1 + 0x4cc));
  iVar5 = *(int *)(Globals::layout + 0x2c);
  iVar2 = Sprite::getFrameHeight(*(Sprite **)(param_1 + 0x4cc));
  iVar3 = Globals::w;
  iVar9 = *(int *)(Globals::layout + 0x2c);
  local_3c = 0;
  AbyssEngine::String::Set(CONCAT44(Globals::w,&local_3c));
  if ((local_38 < 7) && (iVar8 = 7 - local_38, 0 < iVar8)) {
    iVar7 = 0;
    do {
      AbyssEngine::String::String((String *)&local_4c,"0",false);
      AbyssEngine::operator+((AbyssEngine *)&local_44,(String *)&local_4c,(String *)&local_3c);
      AbyssEngine::String::operator=((String *)&local_3c,(AbyssEngine *)&local_44);
      AbyssEngine::String::~String((String *)&local_44);
      AbyssEngine::String::~String((String *)&local_4c);
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar8);
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar1 = iVar1 - iVar5;
  iVar3 = iVar3 / 2 - (iVar1 * 7) / 2;
  if (local_38 != 0) {
    uVar6 = 0;
    iVar5 = iVar3;
    do {
      uVar6 = uVar6 + 1;
      AbyssEngine::String::SubString((uint)aSStack_54,(uint)&local_3c);
      iVar8 = AbyssEngine::String::ValueOf(aSStack_54);
      AbyssEngine::String::~String(aSStack_54);
      Sprite::setFrame(*(Sprite **)(param_1 + 0x4cc),iVar8);
      uVar10 = Sprite::setPosition(*(Sprite **)(param_1 + 0x4cc),iVar5,iVar9);
      Sprite::draw((float)uVar10,(float)((ulonglong)uVar10 >> 0x20));
      iVar5 = iVar5 + iVar1;
    } while (uVar6 < local_38);
  }
  if ((0 < *(int *)(Globals::status + 0x17c)) && (1 < *(int *)(Globals::status + 0x188))) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    iVar8 = *(int *)(Globals::layout + 0x2c);
    iVar5 = iVar9 + iVar2 + iVar8;
    if (*(int *)(Globals::status + 0x17c) < 0xbb9) {
      if (*(int *)(Globals::status + 0x17c) % 100 < 0x32) goto LAB_00190c3a;
      VectorSignedToFloat(*(int *)(Globals::status + 0x188),(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(*(int *)(Globals::status + 0x188) * 1000,(byte)(in_fpscr >> 0x16) & 3);
      local_44 = 0;
      AbyssEngine::String::Set(CONCAT44(1000,&local_44));
      iVar7 = 0;
      for (iVar9 = 1; iVar9 - 1U < local_40; iVar9 = iVar9 + 1) {
        AbyssEngine::String::SubString((uint)aSStack_5c,(uint)&local_44);
        iVar4 = AbyssEngine::String::ValueOf(aSStack_5c);
        AbyssEngine::String::~String(aSStack_5c);
        Sprite::setFrame(*(Sprite **)(param_1 + 0x4cc),iVar4);
        uVar10 = Sprite::setPosition(*(Sprite **)(param_1 + 0x4cc),
                                     (Globals::w / 2 - (local_40 * iVar1 >> 1)) + iVar7,
                                     iVar2 + iVar5 + *(int *)(Globals::layout + 0x2c));
        iVar7 = iVar7 + iVar1;
        Sprite::draw((float)uVar10,(float)((ulonglong)uVar10 >> 0x20));
      }
      AbyssEngine::String::~String((String *)&local_44);
    }
    iVar8 = iVar8 + iVar3;
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(param_1 + 0x4d0),iVar8,iVar5);
    iVar3 = *(int *)(Globals::status + 0x17c) + -7000;
    VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    local_4c = 0;
    AbyssEngine::String::Set(CONCAT44(iVar3,&local_4c));
    for (iVar3 = 1; iVar3 - 1U < local_48; iVar3 = iVar3 + 1) {
      AbyssEngine::String::SubString((uint)aSStack_64,(uint)&local_4c);
      iVar2 = AbyssEngine::String::ValueOf(aSStack_64);
      AbyssEngine::String::~String(aSStack_64);
      Sprite::setFrame(*(Sprite **)(param_1 + 0x4cc),iVar2);
      this = *(Sprite **)(param_1 + 0x4cc);
      iVar2 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(param_1 + 0x4d0));
      uVar10 = Sprite::setPosition(this,iVar8 + iVar2,iVar5);
      iVar8 = iVar8 + iVar1;
      Sprite::draw((float)uVar10,(float)((ulonglong)uVar10 >> 0x20));
    }
    AbyssEngine::String::~String((String *)&local_4c);
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
LAB_00190c3a:
  AbyssEngine::String::~String((String *)&local_3c);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Hud::draw  @0x00190d08  (10094 bytes)
/* Hud::draw(long long, long long, PlayerEgo*, bool, unsigned int, unsigned int) */

void Hud::draw(longlong param_1,longlong param_2,PlayerEgo *param_3,bool param_4,uint param_5,
              uint param_6)

{
  ushort uVar1;
  Status *this;
  GameText *this_00;
  Globals *pGVar2;
  byte bVar3;
  Hud HVar4;
  ushort uVar5;
  Hud *this_01;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  undefined4 uVar11;
  Station *pSVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  Mission *pMVar16;
  float fVar17;
  Item *this_02;
  Ship *pSVar18;
  String *pSVar19;
  String *pSVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  PaintCanvas *pPVar24;
  undefined4 extraout_r1;
  uint uVar25;
  uint uVar26;
  int iVar27;
  bool bVar28;
  uint in_fpscr;
  uint uVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  undefined8 uVar33;
  undefined3 in_stack_00000005;
  int in_stack_00000010;
  int in_stack_00000014;
  AbyssEngine aAStack_94 [8];
  String aSStack_8c [8];
  undefined4 local_84 [2];
  undefined4 local_7c [2];
  undefined4 local_74 [2];
  int local_6c [2];
  undefined4 local_64 [2];
  AbyssEngine aAStack_5c [8];
  AbyssEngine aAStack_54 [8];
  int local_4c;
  
  iVar15 = (int)param_2;
  this_01 = (Hud *)param_1;
  local_4c = __stack_chk_guard;
  uVar6 = PlayerEgo::isMining((PlayerEgo *)param_5);
  if (((uVar6 == 0) && (this_01[0x20c] != (Hud)0x0)) && (this_01[0x4c0] == (Hud)0x0)) {
    updateQueue(this_01,iVar15);
    drawEventQueue(this_01);
  }
  uVar11 = Globals::options._84_4_;
  pGVar2 = Globals::globals;
  if ((Globals::iPad != '\0') &&
     ((*(int *)(this_01 + 0x10) != Globals::options._84_4_ ||
      (*(int *)(this_01 + 0x14) != Globals::options._88_4_)))) {
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 700));
    iVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 0x2b0));
    iVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 0x2a0));
    Globals::setCoordsSteer
              (pGVar2,uVar11,iVar7,iVar8,iVar9,(ushort *)(this_01 + 0x394),
               (ushort *)(this_01 + 0x396),(ushort *)(this_01 + 0x3c8),(ushort *)(this_01 + 0x3ca),
               (ushort *)(this_01 + 0x3c0),(ushort *)(this_01 + 0x3c2),(ushort *)(this_01 + 0x3ac),
               (ushort *)(this_01 + 0x3ae),(ushort *)(this_01 + 0x3a0),(ushort *)(this_01 + 0x3a2));
    *(short *)(this_01 + 0x3ba) = (short)*(undefined4 *)(this_01 + 0x3c0);
    *(short *)(this_01 + 0x3bc) = (short)((uint)*(undefined4 *)(this_01 + 0x3c0) >> 0x10);
    uVar11 = Globals::options._88_4_;
    pGVar2 = Globals::globals;
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 4));
    Globals::setCoordsFire
              (pGVar2,uVar11,iVar7,*(uint *)(this_01 + 4),*(uint *)(this_01 + 8),
               (uint *)(this_01 + 0x2e8),(ushort *)(this_01 + 0xc),(ushort *)(this_01 + 0xe),
               (ushort *)(this_01 + 0x380),(ushort *)(this_01 + 0x382),(ushort *)(this_01 + 0x3b2),
               (ushort *)(this_01 + 0x3b4),(ushort *)(this_01 + 0x38e),(ushort *)(this_01 + 0x390),
               (ushort *)(this_01 + 0x388),(ushort *)(this_01 + 0x38a),(ushort *)(this_01 + 0x39a),
               (ushort *)(this_01 + 0x39c));
    *(undefined4 *)(this_01 + 0x10) = Globals::options._84_4_;
    *(undefined4 *)(this_01 + 0x14) = Globals::options._88_4_;
  }
  AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
  if ((this_01[0x1e4] != (Hud)0x0) &&
     (iVar7 = *(int *)(this_01 + 0x408), *(int *)(this_01 + 0x408) = iVar7 + iVar15,
     500 < iVar7 + iVar15)) {
    *(undefined4 *)(this_01 + 0x408) = 0;
    this_01[0x1e4] = (Hud)0x0;
  }
  if (0 < *(int *)(this_01 + 0x40c)) {
    *(int *)(this_01 + 0x40c) = *(int *)(this_01 + 0x40c) - iVar15;
  }
  fVar10 = (float)PlayerEgo::getBoostRate((PlayerEgo *)param_5);
  fVar17 = 1.0;
  uVar29 = in_fpscr & 0xfffffff | (uint)(fVar10 == 1.0) << 0x1e;
  bVar28 = false;
  if ((byte)(uVar29 >> 0x1e) != 0) {
    bVar28 = this_01[0x410] == (Hud)0x0;
  }
  if (bVar28) {
    this_01[0x410] = (Hud)0x1;
    *(undefined4 *)(this_01 + 0x420) = 2000;
    *(undefined4 *)(this_01 + 0x424) = 0x50;
    iVar7 = *(int *)(this_01 + 0x470);
    if (*(int *)(this_01 + 0x428) < 0) {
      *(int *)(this_01 + 0x418) = iVar7;
    }
    else {
      iVar8 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
      *(int *)(this_01 + 0x418) = iVar8 + iVar7;
    }
  }
  else {
    fVar10 = (float)PlayerEgo::getBoostRate((PlayerEgo *)param_5);
    uVar29 = uVar29 & 0xfffffff | (uint)(fVar10 == 1.0) << 0x1e;
    this_01[0x410] = (Hud)((byte)(uVar29 >> 0x1e) != 0);
  }
  if (this_01[0x1c1] != (Hud)0x0) {
    if (((this_01[0x412] == (Hud)0x0) &&
        (iVar7 = PlayerEgo::isCloaked((PlayerEgo *)param_5), iVar7 == 0)) &&
       (iVar7 = PlayerEgo::isRechargingCloak((PlayerEgo *)param_5), iVar7 == 0)) {
      this_01[0x412] = (Hud)0x1;
      *(undefined4 *)(this_01 + 0x434) = 2000;
      *(undefined4 *)(this_01 + 0x438) = 0x50;
    }
    else {
      iVar7 = PlayerEgo::isCloaked((PlayerEgo *)param_5);
      if (iVar7 == 0) {
        bVar3 = PlayerEgo::isRechargingCloak((PlayerEgo *)param_5);
        HVar4 = (Hud)(bVar3 ^ 1);
      }
      else {
        HVar4 = (Hud)0x0;
      }
      this_01[0x412] = HVar4;
    }
  }
  iVar7 = *(int *)(Globals::layout + 0x1e8);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  pPVar24 = Globals::Canvas;
  if (this_01[0x1c3] == (Hud)0x0) {
    uVar1 = *(ushort *)(this_01 + 0x3e6);
    uVar5 = *(ushort *)(this_01 + 0x3de);
  }
  else {
    iVar8 = Player::getShieldHP(*(Player **)param_5);
    if ((iVar8 < 2) || (this_01[0x1e4] == (Hud)0x0)) {
      iVar8 = 0x244;
    }
    else {
      iVar8 = 0x248;
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar24,*(uint *)(this_01 + iVar8),(uint)*(ushort *)(this_01 + 0x3d8),
               (uint)*(ushort *)(this_01 + 0x3de));
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x274),(uint)*(ushort *)(this_01 + 0x3da),
               (uint)*(ushort *)(this_01 + 0x3de) + iVar7);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x24c),(uint)*(ushort *)(this_01 + 0x3dc),
               (uint)*(ushort *)(this_01 + 0x3e6));
    uVar11 = Player::getShieldDamageRate(*(Player **)param_5);
    fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
    fVar31 = (float)VectorUnsignedToFloat
                              ((uint)*(ushort *)(this_01 + 0x3e2),(byte)(uVar29 >> 0x16) & 3);
    iVar8 = (int)(fVar10 * 0.01 * fVar31);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)(this_01 + 0x250),0,0,iVar8,
               (uint)*(ushort *)(this_01 + 1000),(float)iVar8,0,0,0,
               (uint)*(ushort *)(this_01 + 0x3dc));
    uVar5 = *(ushort *)(this_01 + 0x3e0);
    uVar1 = *(ushort *)(this_01 + 0x3e4);
  }
  pPVar24 = Globals::Canvas;
  iVar9 = Player::getArmorHP(*(Player **)param_5);
  iVar8 = 0x254;
  if (iVar9 < 1) {
    iVar8 = 600;
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (pPVar24,*(uint *)(this_01 + iVar8),(uint)*(ushort *)(this_01 + 0x3d8),(uint)uVar5);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this_01 + 0x274),(uint)*(ushort *)(this_01 + 0x3da),
             (uint)uVar5 + iVar7);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this_01 + 0x25c),(uint)*(ushort *)(this_01 + 0x3dc),
             (uint)uVar1);
  uVar11 = PlayerEgo::getHullDamageRate();
  fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
  fVar31 = (float)VectorUnsignedToFloat
                            ((uint)*(ushort *)(this_01 + 0x3e2),(byte)(uVar29 >> 0x16) & 3);
  iVar8 = (int)(fVar10 * 0.01 * fVar31);
  AbyssEngine::PaintCanvas::DrawRegion2D
            (Globals::Canvas,*(uint *)(this_01 + 0x264),0,0,iVar8,(uint)*(ushort *)(this_01 + 1000),
             (float)iVar8,0,0,0,(uint)*(ushort *)(this_01 + 0x3dc));
  if (this_01[0x1c4] != (Hud)0x0) {
    uVar11 = Player::getArmorDamageRate(*(Player **)param_5);
    fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
    fVar31 = (float)VectorUnsignedToFloat
                              ((uint)*(ushort *)(this_01 + 0x3e2),(byte)(uVar29 >> 0x16) & 3);
    iVar8 = (int)(fVar10 * 0.01 * fVar31);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)(this_01 + 0x260),0,0,iVar8,
               (uint)*(ushort *)(this_01 + 1000),(float)iVar8,0,0,0,
               (uint)*(ushort *)(this_01 + 0x3dc));
  }
  this = Globals::status;
  pSVar12 = (Station *)Status::getStation(Globals::status);
  iVar8 = Station::getIndex(pSVar12);
  iVar9 = Status::getCurrentCampaignMission(Globals::status);
  fVar10 = (float)Status::getGammaRayDamagePerSecond(this,iVar8,iVar9);
  uVar25 = uVar29 & 0xfffffff | (uint)(fVar10 < 0.0) << 0x1f | (uint)(fVar10 == 0.0) << 0x1e;
  uVar29 = uVar25 | (uint)NAN(fVar10) << 0x1c;
  bVar3 = (byte)(uVar25 >> 0x18);
  if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar29 >> 0x1c) & 1)) {
    uVar25 = *(uint *)(this_01 + 0x3e4);
    iVar8 = (uint)*(ushort *)(this_01 + 0x3e0) * 2 - (uint)*(ushort *)(this_01 + 0x3de);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x270),(uint)*(ushort *)(this_01 + 0x3d8),iVar8);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x274),(uint)*(ushort *)(this_01 + 0x3da),
               iVar8 + iVar7);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x26c),(uint)*(ushort *)(this_01 + 0x3dc),
               ((uVar25 & 0xffff) - (uVar25 >> 0x10)) + (uVar25 & 0xffff));
    uVar11 = Player::getGammaHP(*(Player **)param_5);
    fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
    fVar31 = (float)VectorUnsignedToFloat
                              ((uint)*(ushort *)(this_01 + 0x3e2),(byte)(uVar29 >> 0x16) & 3);
    iVar7 = (int)((fVar10 / 100.0) * fVar31);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)(this_01 + 0x268),0,0,iVar7,
               (uint)*(ushort *)(this_01 + 1000),(float)iVar7,0,0,0,
               (uint)*(ushort *)(this_01 + 0x3dc));
  }
  iVar7 = PlayerEgo::isInRocketControl((PlayerEgo *)param_5);
  if (iVar7 == 1) {
    if ((((byte)this_01[0x224] & 8) == 0) &&
       ((*(int *)(this_01 + 0x428) < 1 || (0 < *(int *)(this_01 + 0x42c))))) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x290),*(uint *)(this_01 + 0x388) & 0xffff,
                 *(uint *)(this_01 + 0x388) >> 0x10);
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x28c),*(uint *)(this_01 + 0x388) & 0xffff,
                 *(uint *)(this_01 + 0x388) >> 0x10);
      if (0 < *(int *)(this_01 + 0x428)) {
        *(undefined4 *)(this_01 + 0x42c) = 0x50;
      }
    }
    if ((Globals::options[0x11] == '\0') ||
       ((((((iVar15 = PlayerEgo::isAutoPilot((PlayerEgo *)param_5), iVar15 != 0 ||
            (iVar15 = PlayerEgo::isDockingToAsteroid((PlayerEgo *)param_5), iVar15 != 0)) ||
           (iVar15 = PlayerEgo::isDockingToDockingPoint((PlayerEgo *)param_5), iVar15 != 0)) ||
          (this_01[0x4c0] != (Hud)0x0)) ||
         ((iVar15 = PlayerEgo::isDockedToDockingPoint((PlayerEgo *)param_5), iVar15 == 1 &&
          (iVar15 = PlayerEgo::isInTurretMode((PlayerEgo *)param_5), iVar15 == 0)))) &&
        ((Globals::options[0x11] == '\0' ||
         (iVar15 = PlayerEgo::isInTurretMode((PlayerEgo *)param_5), iVar15 != 1)))))) {
      AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    }
    else {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 700),*(uint *)(this_01 + 0x3c8) & 0xffff,
               *(uint *)(this_01 + 0x3c8) >> 0x10);
    if ((Globals::options[0x11] == '\0') || (((byte)this_01[0x224] & 0x20) == 0)) {
      uVar29 = *(uint *)(this_01 + 0x3c0);
      *(short *)(this_01 + 0x3ba) = (short)uVar29;
      uVar25 = uVar29 >> 0x10;
      *(short *)(this_01 + 0x3bc) = (short)(uVar29 >> 0x10);
      uVar29 = uVar29 & 0xffff;
      uVar6 = *(uint *)(this_01 + 0x2a8);
    }
    else {
      uVar25 = (uint)*(ushort *)(this_01 + 0x3bc);
      uVar29 = (uint)*(ushort *)(this_01 + 0x3ba);
      uVar6 = *(uint *)(this_01 + 0x2a4);
    }
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar6,uVar29,uVar25,'\x11','D');
    iVar15 = __stack_chk_guard - local_4c;
    pPVar24 = Globals::Canvas;
    if (iVar15 == 0) {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      return;
    }
    goto LAB_0019375e;
  }
  iVar8 = PlayerEgo::getShieldDamageRate();
  iVar7 = 0x30c;
  if (iVar8 < 1) {
    iVar7 = 0x304;
  }
  uVar26 = *(uint *)(this_01 + iVar7);
  iVar8 = PlayerEgo::getShieldDamageRate();
  iVar7 = 0x308;
  uVar25 = *(uint *)(param_5 + 0x20);
  if (iVar8 < 1) {
    iVar7 = 0x300;
  }
  uVar13 = *(uint *)(this_01 + iVar7);
  if ((uVar25 & 1) != 0) {
    *(undefined4 *)(this_01 + 0x448) = 300;
  }
  if ((uVar25 & 2) != 0) {
    *(undefined4 *)(this_01 + 0x44c) = 300;
  }
  if ((uVar25 & 0x24) != 0) {
    *(undefined4 *)(this_01 + 0x454) = 300;
  }
  if ((uVar25 & 0x18) != 0) {
    *(undefined4 *)(this_01 + 0x450) = 300;
  }
  if (0 < *(int *)(this_01 + 0x448)) {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    iVar8 = Globals::w;
    iVar7 = Globals::h;
    pPVar24 = Globals::Canvas;
    iVar27 = *(int *)(*(int *)(param_5 + 0x14) + 0x4c);
    iVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar26);
    iVar14 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,uVar26);
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar24,uVar26,(iVar8 >> 1) - iVar27,iVar7 >> 1,iVar9,iVar14,'\x11','A','\x01');
    *(int *)(this_01 + 0x448) = *(int *)(this_01 + 0x448) - iVar15;
  }
  if (0 < *(int *)(this_01 + 0x44c)) {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,uVar26,(Globals::w >> 1) - *(int *)(*(int *)(param_5 + 0x14) + 0x4c),
               Globals::h >> 1,'\x12','B');
    *(int *)(this_01 + 0x44c) = *(int *)(this_01 + 0x44c) - iVar15;
  }
  if (0 < *(int *)(this_01 + 0x450)) {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,uVar13,Globals::w >> 1,
               (Globals::h >> 1) - *(int *)(*(int *)(param_5 + 0x14) + 0x50),'\x11','\x14');
    *(int *)(this_01 + 0x450) = *(int *)(this_01 + 0x450) - iVar15;
  }
  if (0 < *(int *)(this_01 + 0x454)) {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    iVar8 = Globals::w;
    iVar7 = Globals::h;
    pPVar24 = Globals::Canvas;
    iVar27 = *(int *)(*(int *)(param_5 + 0x14) + 0x50);
    iVar9 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar13);
    iVar14 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,uVar13);
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar24,uVar13,iVar8 >> 1,(iVar7 >> 1) - iVar27,iVar9,iVar14,'!','$','\x02');
    *(int *)(this_01 + 0x454) = *(int *)(this_01 + 0x454) - iVar15;
  }
  if ((Globals::options[0x11] == '\0') ||
     (((((iVar7 = PlayerEgo::isAutoPilot((PlayerEgo *)param_5), iVar7 != 0 ||
         (iVar7 = PlayerEgo::isDockingToAsteroid((PlayerEgo *)param_5), iVar7 != 0)) ||
        (iVar7 = PlayerEgo::isDockingToDockingPoint((PlayerEgo *)param_5), iVar7 != 0)) ||
       ((this_01[0x4c0] != (Hud)0x0 ||
        ((iVar7 = PlayerEgo::isDockedToDockingPoint((PlayerEgo *)param_5), iVar7 == 1 &&
         (iVar7 = PlayerEgo::isInTurretMode((PlayerEgo *)param_5), iVar7 == 0)))))) &&
      ((Globals::options[0x11] == '\0' ||
       (iVar7 = PlayerEgo::isInTurretMode((PlayerEgo *)param_5), iVar7 != 1)))))) {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
  }
  else {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this_01 + 700),*(uint *)(this_01 + 0x3c8) & 0xffff,
             *(uint *)(this_01 + 0x3c8) >> 0x10);
  if ((Globals::options[0x11] == '\0') || (((byte)this_01[0x224] & 0x20) == 0)) {
    uVar26 = *(uint *)(this_01 + 0x3c0);
    *(short *)(this_01 + 0x3ba) = (short)uVar26;
    uVar13 = uVar26 >> 0x10;
    *(short *)(this_01 + 0x3bc) = (short)(uVar26 >> 0x10);
    uVar26 = uVar26 & 0xffff;
    uVar25 = *(uint *)(this_01 + 0x2a8);
  }
  else {
    uVar13 = (uint)*(ushort *)(this_01 + 0x3bc);
    uVar26 = (uint)*(ushort *)(this_01 + 0x3ba);
    uVar25 = *(uint *)(this_01 + 0x2a4);
  }
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar25,uVar26,uVar13,'\x11','D');
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar7 = Status::getMission(Globals::status);
  if (iVar7 == 0) {
LAB_00191910:
    if (((int)(uint)(param_3 == (PlayerEgo *)0x0) <= _param_4) &&
       (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 != 0x2a)) {
      AbyssEngine::String::String((String *)aAStack_54);
      Globals::longToTimeString(CONCAT44(Globals::globals,Globals::globals),param_3);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x2c0),*(uint *)(this_01 + 0x3d4) & 0xffff,
                 *(uint *)(this_01 + 0x3d4) >> 0x10);
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,aAStack_54,
                 *(int *)(Globals::layout + 0x204) + (*(uint *)(this_01 + 0x3d4) & 0xffff),
                 (*(uint *)(this_01 + 0x3d4) >> 0x10) + 5,false);
      goto LAB_00191f46;
    }
    iVar7 = Status::getMission(Globals::status);
    if (iVar7 == 0) {
LAB_00191994:
      iVar7 = Status::getMission(Globals::status);
      if (iVar7 != 0) {
        pMVar16 = (Mission *)Status::getMission(Globals::status);
        iVar7 = Mission::getType(pMVar16);
        if (iVar7 == 0xae) {
          pSVar18 = (Ship *)Status::getShip(Globals::status);
          pMVar16 = (Mission *)Status::getMission(Globals::status);
          iVar7 = Mission::getProductionGoodIndex(pMVar16);
          iVar7 = Ship::getCargo(pSVar18,iVar7);
          if (iVar7 == 0) {
            local_6c[0] = 0;
          }
          else {
            pSVar18 = (Ship *)Status::getShip(Globals::status);
            pMVar16 = (Mission *)Status::getMission(Globals::status);
            iVar7 = Mission::getProductionGoodIndex(pMVar16);
            this_02 = (Item *)Ship::getCargo(pSVar18,iVar7);
            local_6c[0] = Item::getAmount(this_02);
          }
          AbyssEngine::String::String((String *)aAStack_5c," / ",false);
          AbyssEngine::operator+(aAStack_54,local_6c,(String *)aAStack_5c);
          pSVar18 = (Ship *)Status::getShip(Globals::status);
          Ship::getFreeSpace(pSVar18);
          local_64[0] = 0;
          AbyssEngine::String::Set(CONCAT44(local_6c[0],local_64));
          AbyssEngine::operator+((AbyssEngine *)local_74,aAStack_54,(String *)local_64);
          AbyssEngine::String::~String((String *)local_64);
          AbyssEngine::String::~String((String *)aAStack_54);
          AbyssEngine::String::~String((String *)aAStack_5c);
          AbyssEngine::PaintCanvas::DrawImage2D
                    (Globals::Canvas,*(uint *)(this_01 + 0x2d8),
                     (*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1f0),
                     *(uint *)(this_01 + 0x3d4) >> 0x10);
          iVar7 = PlayerEgo::hasVolatileGoods((PlayerEgo *)param_5);
          if (iVar7 == 1) {
            uVar11 = AbyssEngine::PaintCanvas::GetImage2DWidth
                               (Globals::Canvas,*(uint *)(this_01 + 0x2e0));
            iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight
                              (Globals::Canvas,*(uint *)(this_01 + 0x2e0));
            pPVar24 = Globals::Canvas;
            uVar26 = *(uint *)(this_01 + 0x2e0);
            fVar10 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
            fVar17 = 1.0;
            uVar25 = uVar29 & 0xfffffff | (uint)(fVar10 < 1.0) << 0x1f |
                     (uint)(fVar10 == 1.0) << 0x1e;
            uVar29 = uVar25 | (uint)NAN(fVar10) << 0x1c;
            bVar3 = (byte)(uVar25 >> 0x18);
            if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar29 >> 0x1c) & 1)) {
              fVar17 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
            }
            fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
            AbyssEngine::PaintCanvas::DrawRegion2D
                      (pPVar24,uVar26,0,0,(int)(fVar10 * fVar17),iVar7,(float)(int)(fVar10 * fVar17)
                       ,0,0,0,(*(uint *)(this_01 + 0x3d4) & 0xffff) -
                              *(int *)(Globals::layout + 0x1ec));
          }
          AbyssEngine::PaintCanvas::DrawString
                    (Globals::Canvas,Globals::font,(String *)local_74,
                     *(int *)(Globals::layout + 0x200) + (*(uint *)(this_01 + 0x3d4) & 0xffff),
                     (*(uint *)(this_01 + 0x3d4) >> 0x10) + 4,false);
          pMVar16 = (Mission *)Status::getMission(Globals::status);
          Mission::getProductionGoodAmount(pMVar16);
          pMVar16 = (Mission *)Status::getMission(Globals::status);
          Mission::getStatusValue(pMVar16);
          local_7c[0] = 0;
          AbyssEngine::String::Set(ZEXT48(local_7c));
          pPVar24 = Globals::Canvas;
          uVar26 = *(uint *)(this_01 + 0x2dc);
          uVar25 = *(uint *)(this_01 + 0x3d4);
          iVar8 = *(int *)(Globals::layout + 0x1f0);
          iVar9 = *(int *)(Globals::layout + 500);
          iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight
                            (Globals::Canvas,*(uint *)(this_01 + 0x2d4));
          AbyssEngine::PaintCanvas::DrawImage2D
                    (pPVar24,uVar26,(uVar25 & 0xffff) - iVar8,iVar9 + (uVar25 >> 0x10) + iVar7);
          uVar25 = Globals::font;
          pPVar24 = Globals::Canvas;
          uVar26 = *(uint *)(this_01 + 0x3d4);
          iVar14 = *(int *)(Globals::layout + 500);
          iVar8 = *(int *)(Globals::layout + 0x1f8);
          iVar9 = *(int *)(Globals::layout + 0x200);
          iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight
                            (Globals::Canvas,*(uint *)(this_01 + 0x2d4));
          AbyssEngine::PaintCanvas::DrawString
                    (pPVar24,uVar25,(String *)local_7c,iVar9 + (uVar26 & 0xffff),
                     iVar7 + iVar8 + (uVar26 >> 0x10) + iVar14,false);
          AbyssEngine::String::~String((String *)local_7c);
          pSVar19 = (String *)local_74;
          goto LAB_0019254e;
        }
      }
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      uVar11 = Ship::getCurrentLoad(pSVar18);
      local_64[0] = 0;
      AbyssEngine::String::Set(CONCAT44(uVar11,local_64));
      AbyssEngine::String::String((String *)local_6c," / ",false);
      AbyssEngine::operator+(aAStack_5c,(String *)local_64,(String *)local_6c);
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      uVar11 = Ship::getMaxLoad(pSVar18);
      local_74[0] = 0;
      AbyssEngine::String::Set(CONCAT44(uVar11,local_74));
      AbyssEngine::operator+(aAStack_54,aAStack_5c,(String *)local_74);
      AbyssEngine::String::String((String *)local_7c,"t",false);
      AbyssEngine::operator+((AbyssEngine *)local_84,aAStack_54,(String *)local_7c);
      AbyssEngine::String::~String((String *)local_7c);
      AbyssEngine::String::~String((String *)aAStack_54);
      AbyssEngine::String::~String((String *)local_74);
      AbyssEngine::String::~String((String *)aAStack_5c);
      AbyssEngine::String::~String((String *)local_6c);
      AbyssEngine::String::~String((String *)local_64);
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      iVar8 = Ship::getCurrentLoad(pSVar18);
      iVar7 = 0;
      if (100 < iVar8) {
        iVar7 = *(int *)(Globals::layout + 0x2c) * -2;
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x2c4),
                 (*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1ec),
                 *(uint *)(this_01 + 0x3d4) >> 0x10);
      iVar8 = PlayerEgo::hasVolatileGoods((PlayerEgo *)param_5);
      if (iVar8 == 1) {
        uVar11 = AbyssEngine::PaintCanvas::GetImage2DWidth
                           (Globals::Canvas,*(uint *)(this_01 + 0x2e0));
        iVar8 = AbyssEngine::PaintCanvas::GetImage2DHeight
                          (Globals::Canvas,*(uint *)(this_01 + 0x2e0));
        pPVar24 = Globals::Canvas;
        uVar26 = *(uint *)(this_01 + 0x2e0);
        fVar10 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
        fVar17 = 1.0;
        uVar25 = uVar29 & 0xfffffff | (uint)(fVar10 < 1.0) << 0x1f | (uint)(fVar10 == 1.0) << 0x1e;
        uVar29 = uVar25 | (uint)NAN(fVar10) << 0x1c;
        bVar3 = (byte)(uVar25 >> 0x18);
        if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar29 >> 0x1c) & 1)) {
          fVar17 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
        }
        fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
        AbyssEngine::PaintCanvas::DrawRegion2D
                  (pPVar24,uVar26,0,0,(int)(fVar10 * fVar17),iVar8,(float)(int)(fVar10 * fVar17),0,0
                   ,0,(*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1ec));
      }
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,(String *)local_84,
                 (iVar7 + (*(uint *)(this_01 + 0x3d4) & 0xffff)) - *(int *)(Globals::layout + 0x208)
                 ,(*(uint *)(this_01 + 0x3d4) >> 0x10) + 5,false);
      pSVar19 = (String *)local_84;
      goto LAB_00191f48;
    }
    pMVar16 = (Mission *)Status::getMission(Globals::status);
    iVar7 = Mission::getType(pMVar16);
    if (iVar7 != 0xb8) goto LAB_00191994;
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if ((iVar7 == 0x66) && (iVar7 = Status::inAlienOrbit(Globals::status), iVar7 == 0)) {
      pSVar12 = (Station *)Status::getStation(Globals::status);
      uVar33 = Station::getIndex(pSVar12);
      uVar11 = (undefined4)((ulonglong)uVar33 >> 0x20);
      if ((int)uVar33 != 0x71) goto LAB_00191f4e;
      bVar28 = false;
    }
    else {
LAB_00191f4e:
      uVar33 = Status::getCurrentCampaignMission(Globals::status);
      uVar11 = (undefined4)((ulonglong)uVar33 >> 0x20);
      if ((int)uVar33 == 0x8b) {
        uVar33 = Status::inAlienOrbit(Globals::status);
        uVar11 = (undefined4)((ulonglong)uVar33 >> 0x20);
        bVar28 = false;
        if ((int)uVar33 == 0) {
          pSVar12 = (Station *)Status::getStation(Globals::status);
          uVar33 = Station::getIndex(pSVar12);
          uVar11 = (undefined4)((ulonglong)uVar33 >> 0x20);
          bVar28 = (int)uVar33 == 0x83;
        }
      }
      else {
        bVar28 = false;
      }
      bVar28 = (bool)(bVar28 ^ 1);
    }
    local_64[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar11,local_64));
    AbyssEngine::String::String((String *)local_6c," / ",false);
    AbyssEngine::operator+(aAStack_54,(String *)local_64,(String *)local_6c);
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar11 = Ship::getMaxPassengers(pSVar18);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar11,local_74));
    AbyssEngine::operator+(aAStack_5c,aAStack_54,(String *)local_74);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)aAStack_54);
    AbyssEngine::String::~String((String *)local_6c);
    AbyssEngine::String::~String((String *)local_64);
    if (bVar28) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x2d4),
                 (*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1f0),
                 *(uint *)(this_01 + 0x3d4) >> 0x10);
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x2c4),
                 (*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1ec),
                 *(uint *)(this_01 + 0x3d4) >> 0x10);
    }
    iVar7 = PlayerEgo::hasVolatileGoods((PlayerEgo *)param_5);
    if (iVar7 == 1) {
      uVar11 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 0x2e0))
      ;
      iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this_01 + 0x2e0))
      ;
      pPVar24 = Globals::Canvas;
      uVar26 = *(uint *)(this_01 + 0x2e0);
      fVar10 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
      fVar17 = 1.0;
      uVar25 = uVar29 & 0xfffffff | (uint)(fVar10 < 1.0) << 0x1f | (uint)(fVar10 == 1.0) << 0x1e;
      uVar29 = uVar25 | (uint)NAN(fVar10) << 0x1c;
      bVar3 = (byte)(uVar25 >> 0x18);
      if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar29 >> 0x1c) & 1)) {
        fVar17 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
      }
      fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawRegion2D
                (pPVar24,uVar26,0,0,(int)(fVar10 * fVar17),iVar7,(float)(int)(fVar10 * fVar17),0,0,0
                 ,(*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1ec));
    }
    if (bVar28) {
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,aAStack_5c,
                 *(int *)(Globals::layout + 0x200) + (*(uint *)(this_01 + 0x3d4) & 0xffff),
                 (*(uint *)(this_01 + 0x3d4) >> 0x10) + 5,false);
    }
    else {
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      uVar11 = Ship::getCurrentLoad(pSVar18);
      local_74[0] = 0;
      AbyssEngine::String::Set(CONCAT44(uVar11,local_74));
      AbyssEngine::String::String((String *)local_7c," / ",false);
      AbyssEngine::operator+((AbyssEngine *)local_6c,(String *)local_74,(String *)local_7c);
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      uVar11 = Ship::getMaxLoad(pSVar18);
      local_84[0] = 0;
      AbyssEngine::String::Set(CONCAT44(uVar11,local_84));
      AbyssEngine::operator+(aAStack_54,(String *)local_6c,(String *)local_84);
      AbyssEngine::String::String(aSStack_8c,"t",false);
      AbyssEngine::operator+((AbyssEngine *)local_64,aAStack_54,aSStack_8c);
      AbyssEngine::String::~String(aSStack_8c);
      AbyssEngine::String::~String((String *)aAStack_54);
      AbyssEngine::String::~String((String *)local_84);
      AbyssEngine::String::~String((String *)local_6c);
      AbyssEngine::String::~String((String *)local_7c);
      AbyssEngine::String::~String((String *)local_74);
      pSVar18 = (Ship *)Status::getShip(Globals::status);
      iVar8 = Ship::getCurrentLoad(pSVar18);
      iVar7 = 0;
      if (100 < iVar8) {
        iVar7 = *(int *)(Globals::layout + 0x2c) * -2;
      }
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,(String *)local_64,
                 (iVar7 + (*(uint *)(this_01 + 0x3d4) & 0xffff)) - *(int *)(Globals::layout + 0x208)
                 ,(*(uint *)(this_01 + 0x3d4) >> 0x10) + 5,false);
      AbyssEngine::String::~String((String *)local_64);
    }
    pMVar16 = (Mission *)Status::getMission(Globals::status);
    uVar11 = Mission::getStatusValue(pMVar16);
    local_6c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar11,local_6c));
    pPVar24 = Globals::Canvas;
    uVar26 = *(uint *)(this_01 + 0x2e4);
    uVar25 = *(uint *)(this_01 + 0x3d4);
    iVar8 = *(int *)(Globals::layout + 0x1f0);
    iVar9 = *(int *)(Globals::layout + 500);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this_01 + 0x2d4));
    AbyssEngine::PaintCanvas::DrawImage2D
              (pPVar24,uVar26,(uVar25 & 0xffff) - iVar8,iVar9 + (uVar25 >> 0x10) + iVar7);
    uVar25 = Globals::font;
    pPVar24 = Globals::Canvas;
    uVar26 = *(uint *)(this_01 + 0x3d4);
    iVar8 = *(int *)(Globals::layout + 500);
    iVar14 = *(int *)(Globals::layout + 0x1f8);
    iVar9 = *(int *)(Globals::layout + 0x200);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this_01 + 0x2d4));
    AbyssEngine::PaintCanvas::DrawString
              (pPVar24,uVar25,(String *)local_6c,iVar9 + (uVar26 & 0xffff),
               iVar7 + iVar8 + (uVar26 >> 0x10) + iVar14 * 2,false);
    AbyssEngine::String::~String((String *)local_6c);
    pSVar19 = (String *)aAStack_5c;
LAB_0019254e:
    AbyssEngine::String::~String(pSVar19);
  }
  else {
    pMVar16 = (Mission *)Status::getMission(Globals::status);
    uVar33 = Mission::getType(pMVar16);
    if ((int)uVar33 != 0xc) goto LAB_00191910;
    local_64[0] = 0;
    AbyssEngine::String::Set(CONCAT44((int)((ulonglong)uVar33 >> 0x20),local_64));
    AbyssEngine::String::String((String *)local_6c," : ",false);
    AbyssEngine::operator+(aAStack_5c,(String *)local_64,(String *)local_6c);
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1,local_74));
    AbyssEngine::operator+(aAStack_54,aAStack_5c,(String *)local_74);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)aAStack_5c);
    AbyssEngine::String::~String((String *)local_6c);
    AbyssEngine::String::~String((String *)local_64);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x2c4),
               (*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1ec),
               *(uint *)(this_01 + 0x3d4) >> 0x10);
    iVar7 = PlayerEgo::hasVolatileGoods((PlayerEgo *)param_5);
    if (iVar7 == 1) {
      uVar11 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 0x2e0))
      ;
      iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this_01 + 0x2e0))
      ;
      pPVar24 = Globals::Canvas;
      uVar26 = *(uint *)(this_01 + 0x2e0);
      fVar10 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
      uVar25 = uVar29 & 0xfffffff | (uint)(fVar10 < 1.0) << 0x1f | (uint)(fVar10 == 1.0) << 0x1e;
      uVar29 = uVar25 | (uint)NAN(fVar10) << 0x1c;
      bVar3 = (byte)(uVar25 >> 0x18);
      if ((bool)(bVar3 >> 6 & 1) || bVar3 >> 7 != ((byte)(uVar29 >> 0x1c) & 1)) {
        fVar17 = (float)PlayerEgo::getVolatileForce((PlayerEgo *)param_5);
      }
      fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawRegion2D
                (pPVar24,uVar26,0,0,(int)(fVar10 * fVar17),iVar7,(float)(int)(fVar10 * fVar17),0,0,0
                 ,(*(uint *)(this_01 + 0x3d4) & 0xffff) - *(int *)(Globals::layout + 0x1ec));
    }
    AbyssEngine::PaintCanvas::DrawString
              (Globals::Canvas,Globals::font,aAStack_54,
               *(int *)(Globals::layout + 0x1fc) + (*(uint *)(this_01 + 0x3d4) & 0xffff),
               (*(uint *)(this_01 + 0x3d4) >> 0x10) + 5,false);
LAB_00191f46:
    pSVar19 = (String *)aAStack_54;
LAB_00191f48:
    AbyssEngine::String::~String(pSVar19);
  }
  if ((Globals::mouseCursorActivated != 0) || (this_01[0x222] != (Hud)0x0)) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  if (Globals::iPad == '\0') {
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x2e8),Globals::w,Globals::h,'\x11','\"');
  }
  else {
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x2e8),*(uint *)(this_01 + 0xc) & 0xffff,
               *(uint *)(this_01 + 0xc) >> 0x10);
  }
  if ((this_01[0x4c0] != (Hud)0x0) &&
     (iVar7 = PlayerEgo::isInTurretMode((PlayerEgo *)param_5), iVar7 == 0)) {
    if (((byte)this_01[0x225] & 2) == 0) {
      uVar25 = *(uint *)(this_01 + 0x348);
    }
    else {
      uVar25 = *(uint *)(this_01 + 0x344);
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,uVar25,*(uint *)(this_01 + 0x3f0) & 0xffff,
               *(uint *)(this_01 + 0x3f0) >> 0x10);
    if (((byte)this_01[0x225] & 4) == 0) {
      uVar25 = *(uint *)(this_01 + 0x348);
    }
    else {
      uVar25 = *(uint *)(this_01 + 0x344);
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,uVar25,*(uint *)(this_01 + 0x3f4) & 0xffff,
               *(uint *)(this_01 + 0x3f4) >> 0x10);
  }
  if ((((uVar6 != 0) || (this_01[0x4c0] != (Hud)0x0)) ||
      (iVar7 = PlayerEgo::isDockedToDockingPoint((PlayerEgo *)param_5), iVar7 != 0)) ||
     (iVar7 = PlayerEgo::isLandingOrTakingOff((PlayerEgo *)param_5), iVar7 == 1)) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  iVar7 = Status::inAlienOrbit(Globals::status);
  if (((iVar7 != 1) ||
      (((iVar7 = Status::inAlienOrbit(Globals::status), iVar7 == 1 &&
        (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 0x9a)) &&
       (iVar7 = Level::getNumDockingTargets(*(Level **)(param_5 + 0xc)), 0 < iVar7)))) &&
     (iVar7 = Status::getCurrentCampaignMission(Globals::status), 1 < iVar7)) {
    iVar7 = Status::getMission(Globals::status);
    if (iVar7 != 0) {
      pMVar16 = (Mission *)Status::getMission(Globals::status);
      iVar7 = Mission::getType(pMVar16);
      if (iVar7 == 0xb7) goto LAB_001926f6;
    }
    if (((byte)this_01[0x224] & 0x40) == 0) {
      uVar25 = *(uint *)(this_01 + 0x2b0);
    }
    else {
      uVar25 = *(uint *)(this_01 + 0x2ac);
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,uVar25,*(uint *)(this_01 + 0x394) & 0xffff,
               *(uint *)(this_01 + 0x394) >> 0x10);
  }
LAB_001926f6:
  iVar7 = Radio::isShowingMessage(*(Radio **)(param_5 + 0x18));
  if (iVar7 == 0) {
    iVar7 = PlayerEgo::isAutoPilot((PlayerEgo *)param_5);
    if ((((iVar7 == 0) && (iVar7 = PlayerEgo::isDockingToAsteroid((PlayerEgo *)param_5), iVar7 == 0)
         ) && (((iVar7 = PlayerEgo::isDockingToDockingPoint((PlayerEgo *)param_5), iVar7 != 1 ||
                (iVar7 = PlayerEgo::isLandingOrTakingOff((PlayerEgo *)param_5), iVar7 == 1)) &&
               (this_01[0x4c0] == (Hud)0x0)))) ||
       ((*(char *)(*(int *)(param_5 + 0x14) + 0x54) != '\0' ||
        (iVar7 = PlayerEgo::aboutToReachAutoTarget((PlayerEgo *)param_5), iVar7 != 0)))) {
      if (*this_01 != (Hud)0x0) {
        if (-1 < *(int *)(this_01 + 0x45c)) {
          *(int *)(this_01 + 0x45c) = *(int *)(this_01 + 0x45c) - iVar15;
          *(int *)(this_01 + 0x458) = *(int *)(this_01 + 0x458) - iVar15;
        }
        AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
        if (this_01[0x220] == (Hud)0x0) {
          AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
        }
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(this_01 + 0x338),
                   *(int *)(this_01 + 0x3ec) + (*(uint *)(this_01 + 0x3a0) & 0xffff),
                   *(uint *)(this_01 + 0x3a0) >> 0x10);
        if (((byte)this_01[0x225] & 1) == 0) {
          if ((0 < *(int *)(this_01 + 0x45c)) && (*(int *)(this_01 + 0x458) < 1)) goto LAB_001927dc;
          if (this_01[0x221] != (Hud)0x0) goto LAB_001927d8;
          uVar26 = *(uint *)(this_01 + 0x3a0);
          uVar25 = *(uint *)(this_01 + 0x340);
        }
        else {
LAB_001927d8:
          if (0 < *(int *)(this_01 + 0x45c)) {
LAB_001927dc:
            *(undefined4 *)(this_01 + 0x458) = 0x50;
          }
          uVar26 = *(uint *)(this_01 + 0x3a0);
          uVar25 = *(uint *)(this_01 + 0x33c);
        }
        AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar25,uVar26 & 0xffff,uVar26 >> 0x10)
        ;
        goto LAB_00192888;
      }
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x338),
                 *(int *)(this_01 + 0x3ec) + (*(uint *)(this_01 + 0x3a0) & 0xffff),
                 *(uint *)(this_01 + 0x3a0) >> 0x10);
      if (Globals::mouseCursorActivated != 0) {
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      }
      if (((byte)this_01[0x225] & 1) == 0) {
        uVar25 = *(uint *)(this_01 + 0x334);
      }
      else {
        uVar25 = *(uint *)(this_01 + 0x330);
      }
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,uVar25,*(uint *)(this_01 + 0x3a0) & 0xffff,
                 *(uint *)(this_01 + 0x3a0) >> 0x10);
      if ((Globals::mouseCursorActivated != 0) || (this_01[0x222] != (Hud)0x0)) {
LAB_00192888:
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      }
    }
  }
  iVar7 = PlayerEgo::isAutoPilot((PlayerEgo *)param_5);
  if ((((iVar7 != 0) || (iVar7 = PlayerEgo::isInDockingProcedure((PlayerEgo *)param_5), iVar7 == 1))
      && (iVar7 = PlayerEgo::isDockedToDockingPoint((PlayerEgo *)param_5), iVar7 == 0)) &&
     (iVar7 = PlayerEgo::isLandingOrTakingOff((PlayerEgo *)param_5), iVar7 == 0)) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x2ac),*(uint *)(this_01 + 0x394) & 0xffff,
               *(uint *)(this_01 + 0x394) >> 0x10);
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  if ((Globals::mouseCursorActivated != 0) || (this_01[0x222] != (Hud)0x0)) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  if (((byte)this_01[0x224] & 0x80) == 0) {
    uVar25 = *(uint *)(this_01 + in_stack_00000014 * 4 + 0x490);
  }
  else {
    uVar25 = *(uint *)(this_01 + in_stack_00000014 * 4 + 0x4a0);
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,uVar25,(uint)*(ushort *)(this_01 + 0x38e),
             (uint)*(ushort *)(this_01 + 0x390));
  if (*(int *)(this_01 + 0x4b0) == -1) {
    *(int *)(this_01 + 0x4b0) = in_stack_00000010;
  }
  else if (*(int *)(this_01 + 0x4b0) != in_stack_00000010) {
    *(int *)(this_01 + 0x4b0) = in_stack_00000010;
    *(int *)(this_01 + 0x4b4) = iVar15;
    switch(in_stack_00000010) {
    case 0:
      iVar7 = 0xd9;
      break;
    case 1:
      iVar7 = 0xda;
      break;
    case 2:
      iVar7 = 0xdb;
      break;
    case 3:
      iVar7 = 0xdc;
      break;
    default:
      goto switchD_00192958_default;
    }
    pSVar20 = (String *)GameText::getText(Globals::gameText,iVar7);
    AbyssEngine::String::operator=((String *)(this_01 + 0x4b8),pSVar20);
  }
switchD_00192958_default:
  iVar7 = PlayerEgo::hasAutoTurret((PlayerEgo *)param_5);
  if (iVar7 == 1) {
    iVar7 = PlayerEgo::autoTurretIsEnabled((PlayerEgo *)param_5);
    if ((iVar7 == 0) && (((byte)this_01[0x227] & 0x20) == 0)) {
      uVar5 = *(ushort *)(this_01 + 0x39c);
      uVar1 = *(ushort *)(this_01 + 0x39a);
      uVar25 = *(uint *)(this_01 + 0x2b8);
    }
    else {
      uVar5 = *(ushort *)(this_01 + 0x39c);
      uVar1 = *(ushort *)(this_01 + 0x39a);
      uVar25 = *(uint *)(this_01 + 0x2b4);
    }
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar25,(uint)uVar1,(uint)uVar5);
  }
  else if (0 < *(int *)(this_01 + 0x4b4)) {
    uVar5 = *(ushort *)(this_01 + 0x3b4);
    iVar7 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this_01 + 0x2f4));
    iVar14 = *(int *)(Globals::layout + 0x20c);
    iVar9 = *(int *)(Globals::layout + 0x210);
    iVar8 = AbyssEngine::PaintCanvas::GetWidth();
    VectorSignedToFloat(*(undefined4 *)(this_01 + 0x4b4),(byte)(uVar29 >> 0x16) & 3);
    uVar1 = *(ushort *)(this_01 + 0x388);
    AbyssEngine::PaintCanvas::GetColor(Globals::Canvas);
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    iVar14 = ((uint)uVar5 - iVar7) - iVar14;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x2f4),(uint)*(ushort *)(this_01 + 0x388),iVar14)
    ;
    uVar25 = Globals::font;
    pPVar24 = Globals::Canvas;
    uVar5 = *(ushort *)(this_01 + 0x388);
    iVar7 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,this_01 + 0x4b8);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar24,uVar25,this_01 + 0x4b8,(uint)uVar5 + (int)((iVar8 - (uint)uVar1) - iVar7) / 2
               ,iVar9 + iVar14,false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    iVar7 = *(int *)(this_01 + 0x4b4) + iVar15;
    if (4000 < iVar7) {
      iVar7 = 0;
    }
    *(int *)(this_01 + 0x4b4) = iVar7;
  }
  if ((Globals::mouseCursorActivated == 0) && ((*(ushort *)(this_01 + 0x222) & 0xff) == 0)) {
    uVar5 = *(ushort *)(this_01 + 0x222) >> 8;
  }
  else {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    uVar5 = (ushort)(byte)this_01[0x223];
  }
  if (uVar5 == 0) {
    if ((((byte)this_01[0x224] & 4) == 0) &&
       ((*(int *)(this_01 + 0x434) < 1 || (0 < *(int *)(this_01 + 0x438))))) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x2f0),(uint)*(ushort *)(this_01 + 0x3b2),
                 (uint)*(ushort *)(this_01 + 0x3b4));
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x2ec),(uint)*(ushort *)(this_01 + 0x3b2),
                 (uint)*(ushort *)(this_01 + 0x3b4));
      if (0 < *(int *)(this_01 + 0x434)) {
        *(undefined4 *)(this_01 + 0x438) = 0x50;
      }
    }
  }
  if ((((*(int *)(this_01 + 0x1f8) != 0) &&
       (iVar7 = PlayerEgo::isInTurretMode((PlayerEgo *)param_5), iVar7 == 0)) &&
      (iVar7 = Item::getAmount(*(Item **)(this_01 + 0x1f8)), 0 < iVar7)) ||
     (*(char *)(*(int *)(param_5 + 0xc) + 0x69) != '\0')) {
    if ((((byte)this_01[0x224] & 8) == 0) &&
       ((*(int *)(this_01 + 0x428) < 1 || (0 < *(int *)(this_01 + 0x42c))))) {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x290),*(uint *)(this_01 + 0x388) & 0xffff,
                 *(uint *)(this_01 + 0x388) >> 0x10);
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x28c),*(uint *)(this_01 + 0x388) & 0xffff,
                 *(uint *)(this_01 + 0x388) >> 0x10);
      if (0 < *(int *)(this_01 + 0x428)) {
        *(undefined4 *)(this_01 + 0x42c) = 0x50;
      }
    }
    if (Globals::mouseCursorActivated != 0) {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x2f8),Globals::w >> 1,Globals::h,'\x11','$');
    this_00 = Globals::gameText;
    iVar7 = Item::getIndex(*(Item **)(this_01 + 0x1f8));
    pSVar20 = (String *)GameText::getText(this_00,iVar7 + 0x4fa);
    AbyssEngine::String::String((String *)local_6c," (",false);
    uVar11 = Item::getAmount(*(Item **)(this_01 + 0x1f8));
    local_74[0] = 0;
    AbyssEngine::String::Set(CONCAT44(uVar11,local_74));
    AbyssEngine::operator+((AbyssEngine *)local_64,(String *)local_6c,(String *)local_74);
    AbyssEngine::String::String((String *)local_7c,")",false);
    AbyssEngine::operator+(aAStack_5c,(String *)local_64,(String *)local_7c);
    AbyssEngine::String::String((String *)aAStack_54,aAStack_5c,false);
    AbyssEngine::operator+((AbyssEngine *)aSStack_8c,pSVar20,aAStack_54);
    AbyssEngine::String::~String((String *)aAStack_54);
    AbyssEngine::String::~String((String *)aAStack_5c);
    AbyssEngine::String::~String((String *)local_7c);
    AbyssEngine::String::~String((String *)local_64);
    AbyssEngine::String::~String((String *)local_74);
    AbyssEngine::String::~String((String *)local_6c);
    iVar7 = Globals::w;
    uVar25 = Globals::font;
    pPVar24 = Globals::Canvas;
    iVar8 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_8c);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar24,uVar25,aSStack_8c,(iVar7 >> 1) - (iVar8 >> 1),
               (Globals::h - *(int *)(Globals::layout + 4)) + *(int *)(Globals::layout + 0x214),
               false);
    if ((Globals::mouseCursorActivated != 0) || (this_01[0x222] != (Hud)0x0)) {
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    }
    AbyssEngine::String::~String(aSStack_8c);
  }
  if ((this_01[0x1c1] != (Hud)0x0) && (-1 < *(int *)(this_01 + 0x434))) {
    *(int *)(this_01 + 0x434) = *(int *)(this_01 + 0x434) - iVar15;
    *(int *)(this_01 + 0x438) = *(int *)(this_01 + 0x438) - iVar15;
  }
  if (this_01[0x1c2] != (Hud)0x0) {
    if (-1 < *(int *)(this_01 + 0x420)) {
      *(int *)(this_01 + 0x420) = *(int *)(this_01 + 0x420) - iVar15;
      *(int *)(this_01 + 0x424) = *(int *)(this_01 + 0x424) - iVar15;
    }
    pPVar24 = Globals::Canvas;
    iVar7 = PlayerEgo::boosting((PlayerEgo *)param_5);
    if (iVar7 == 0) {
      fVar10 = (float)PlayerEgo::getBoostRate((PlayerEgo *)param_5);
      uVar29 = uVar29 & 0xfffffff;
      if (fVar10 < 1.0) {
        PlayerEgo::getBoostRate((PlayerEgo *)param_5);
      }
    }
    AbyssEngine::PaintCanvas::SetColor((uchar)pPVar24,0xff,0xff,0xff);
    uVar6 = Globals::mouseCursorActivated != 0 | uVar6;
    bVar28 = uVar6 != 0;
    if (!bVar28) {
      uVar6 = (uint)(byte)this_01[0x4c0];
    }
    if ((bVar28 || uVar6 != 0) ||
       (iVar7 = PlayerEgo::isDockedToDockingPoint((PlayerEgo *)param_5), iVar7 == 1)) {
      PlayerEgo::getBoostRate((PlayerEgo *)param_5);
      uVar29 = uVar29 & 0xfffffff;
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    }
    if (((byte)this_01[0x224] & 2) == 0) {
      if ((0 < *(int *)(this_01 + 0x420)) && (*(int *)(this_01 + 0x424) < 1)) {
LAB_00192eba:
        *(undefined4 *)(this_01 + 0x424) = 0x50;
        if (Globals::mouseCursorActivated != 0) {
          AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        }
        goto LAB_00192ede;
      }
      uVar25 = *(uint *)(this_01 + 0x3ac);
      uVar6 = *(uint *)(this_01 + 0x2a0);
    }
    else {
      if (0 < *(int *)(this_01 + 0x420)) goto LAB_00192eba;
LAB_00192ede:
      uVar25 = *(uint *)(this_01 + 0x3ac);
      uVar6 = *(uint *)(this_01 + 0x29c);
    }
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar6,uVar25 & 0xffff,uVar25 >> 0x10);
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  if ((Globals::mouseCursorActivated != 0) || (this_01[0x222] != (Hud)0x0)) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  }
  HVar4 = this_01[0x224];
  bVar28 = ((byte)HVar4 & 0x10) == 0;
  if (bVar28) {
    HVar4 = this_01[0x441];
  }
  if (bVar28 && HVar4 == (Hud)0x0) {
    uVar6 = *(uint *)(this_01 + 0x284);
  }
  else {
    uVar6 = *(uint *)(this_01 + 0x280);
  }
  uVar26 = *(uint *)(this_01 + 0x380) >> 0x10;
  uVar25 = *(uint *)(this_01 + 0x380) & 0xffff;
  if (Globals::iPad == '\0') {
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar6,uVar25,uVar26);
  }
  else {
    AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,uVar6,uVar25,uVar26,'\x11','D');
  }
  iVar7 = PlayerEgo::isDockingToAsteroid((PlayerEgo *)param_5);
  if ((((iVar7 == 0) && (iVar7 = PlayerEgo::isMining((PlayerEgo *)param_5), iVar7 == 0)) &&
      (iVar7 = PlayerEgo::isDockingToStream((PlayerEgo *)param_5), iVar7 == 0)) &&
     ((((iVar7 = PlayerEgo::isInDockingProcedure((PlayerEgo *)param_5), iVar7 == 0 &&
        (iVar7 = PlayerEgo::isDockingToDockingPoint((PlayerEgo *)param_5), iVar7 == 0)) &&
       (iVar7 = PlayerEgo::isInTurretMode((PlayerEgo *)param_5), iVar7 == 0)) &&
      (((iVar7 = *(int *)(param_5 + 0x14), *(int *)(iVar7 + 0x14) != 0 ||
        (*(int *)(iVar7 + 0xc) != 0)) ||
       ((*(int *)(iVar7 + 0x24) != 0 ||
        (((iVar7 = *(int *)(iVar7 + 4), iVar7 != 0 && (*(char *)(iVar7 + 0x6c) != '\0')) &&
         (*(char *)(iVar7 + 0x71) != '\0')))))))))) {
    iVar8 = (uint)*(ushort *)(this_01 + 0x386) + (*(uint *)(this_01 + 0x380) >> 0x10);
    iVar7 = (uint)*(ushort *)(this_01 + 0x386) + (*(uint *)(this_01 + 0x380) & 0xffff);
    if (Globals::iPad == '\0') {
      AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this_01 + 0x288),iVar7,iVar8);
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x288),iVar7,iVar8,'\x11','D');
    }
  }
  if (((this_01[0x217] != (Hud)0x0) || (this_01[0x216] != (Hud)0x0)) || (this_01[0x218] != (Hud)0x0)
     ) {
    if (((this_01[0x218] == (Hud)0x0) ||
        (iVar7 = PlayerEgo::isDockedToDockingPoint((PlayerEgo *)param_5), iVar7 != 1)) ||
       (iVar7 = PlayerEgo::getHitpoints(), iVar7 < 1)) {
      iVar7 = 0;
    }
    else {
      uVar11 = AbyssEngine::PaintCanvas::GetImage2DHeight
                         (Globals::Canvas,*(uint *)(this_01 + 0x31c));
      uVar21 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
      uVar22 = PlayerEgo::getDockTransferedAmount((PlayerEgo *)param_5);
      uVar23 = PlayerEgo::getDockTotalAmount((PlayerEgo *)param_5);
      HVar4 = this_01[0x219];
      iVar7 = 0xc84;
      if (HVar4 != (Hud)0x0) {
        iVar7 = 0xc85;
      }
      pSVar20 = (String *)GameText::getText(Globals::gameText,iVar7);
      AbyssEngine::String::String((String *)aAStack_54," ",false);
      fVar17 = (float)VectorSignedToFloat(uVar22,(byte)(uVar29 >> 0x16) & 3);
      fVar31 = (float)VectorSignedToFloat(uVar23,(byte)(uVar29 >> 0x16) & 3);
      fVar30 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
      fVar32 = (float)VectorSignedToFloat(uVar21,(byte)(uVar29 >> 0x16) & 3);
      fVar10 = 1.0 - fVar17 / fVar31;
      if (HVar4 == (Hud)0x0) {
        fVar10 = fVar17 / fVar31;
      }
      iVar7 = (int)(fVar30 * 2.5 + fVar32);
      AbyssEngine::operator+(aAStack_94,pSVar20,(String *)aAStack_54);
      AbyssEngine::String::~String((String *)aAStack_54);
      iVar8 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 0x31c));
      iVar9 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this_01 + 0x31c))
      ;
      VectorSignedToFloat(*(int *)(this_01 + 0x404) + iVar15,(byte)(uVar29 >> 0x16) & 3);
      uVar29 = uVar29 & 0xfffffff;
      uVar5 = *(ushort *)(this_01 + 0x37e);
      *(int *)(this_01 + 0x404) = *(int *)(this_01 + 0x404) + iVar15;
      AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(this_01 + 0x318),Globals::w >> 1,(uint)uVar5 << 1,'\x11',
                 '\x14');
      fVar17 = (float)VectorSignedToFloat(iVar8,(byte)(uVar29 >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawRegion2D
                (Globals::Canvas,*(uint *)(this_01 + 0x32c),0,0,(int)(fVar10 * fVar17),iVar9,
                 (float)(int)(fVar10 * fVar17),0,0,0,(Globals::w >> 1) - iVar8 / 2);
      iVar8 = Globals::w;
      uVar6 = Globals::font;
      pPVar24 = Globals::Canvas;
      iVar14 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_94);
      fVar10 = (float)VectorSignedToFloat(iVar9,(byte)(uVar29 >> 0x16) & 3);
      fVar17 = (float)VectorSignedToFloat((uint)uVar5 << 1,(byte)(uVar29 >> 0x16) & 3);
      fVar17 = fVar10 * 2.5 + fVar17;
      AbyssEngine::PaintCanvas::DrawString
                (pPVar24,uVar6,aAStack_94,(iVar8 >> 1) - (iVar14 >> 1),(int)fVar17,false);
      if ((this_01[0x21a] != (Hud)0x0) && (iVar8 = Status::getMission(Globals::status), iVar8 != 0))
      {
        pMVar16 = (Mission *)Status::getMission(Globals::status);
        iVar9 = Mission::getType(pMVar16);
        iVar8 = Globals::w;
        pPVar24 = Globals::Canvas;
        if (iVar9 != 0xa8) {
          uVar6 = *(uint *)(this_01 + 800);
          iVar9 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_94);
          iVar14 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
          fVar10 = (float)VectorSignedToFloat(iVar14 / 2,(byte)(uVar29 >> 0x16) & 3);
          AbyssEngine::PaintCanvas::DrawImage2D
                    (pPVar24,uVar6,(iVar9 >> 1) + (iVar8 >> 1),(int)(fVar17 + fVar10),'\x11','A');
        }
      }
      iVar8 = Status::getMission(Globals::status);
      if (iVar8 != 0) {
        pMVar16 = (Mission *)Status::getMission(Globals::status);
        iVar9 = Mission::getType(pMVar16);
        iVar8 = Globals::w;
        pPVar24 = Globals::Canvas;
        if (iVar9 == 0xae) {
          uVar6 = *(uint *)(this_01 + 0x324);
          iVar9 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_94);
          iVar14 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
          fVar10 = (float)VectorSignedToFloat(iVar14 / 2,(byte)(uVar29 >> 0x16) & 3);
          AbyssEngine::PaintCanvas::DrawImage2D
                    (pPVar24,uVar6,(iVar9 >> 1) + (iVar8 >> 1),(int)(fVar17 + fVar10),'\x11','A');
        }
      }
      AbyssEngine::String::~String((String *)aAStack_94);
    }
    if (this_01[0x217] == (Hud)0x0) {
      if ((*(ushort *)(this_01 + 0x216) & 0xff) == 0) goto LAB_00193608;
      if (0xff < *(ushort *)(this_01 + 0x216)) goto LAB_001933fc;
      fVar10 = (float)PlayerEgo::getCloakRate((PlayerEgo *)param_5);
    }
    else {
LAB_001933fc:
      fVar10 = (float)PlayerEgo::getDriveChargeRate((PlayerEgo *)param_5);
    }
    fVar17 = 1.0;
    uVar29 = uVar29 & 0xfffffff;
    if (fVar10 * 1.05 < 1.0) {
      if (this_01[0x217] == (Hud)0x0) {
        fVar17 = (float)PlayerEgo::getCloakRate((PlayerEgo *)param_5);
      }
      else {
        fVar17 = (float)PlayerEgo::getDriveChargeRate((PlayerEgo *)param_5);
      }
      fVar17 = fVar17 * 1.05;
    }
    iVar8 = 0x13d;
    if (this_01[0x217] != (Hud)0x0) {
      iVar8 = 0x13e;
    }
    pSVar20 = (String *)GameText::getText(Globals::gameText,iVar8);
    AbyssEngine::String::String((String *)aAStack_54,pSVar20,false);
    uVar11 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this_01 + 0x31c));
    fVar10 = (float)VectorSignedToFloat(uVar11,(byte)(uVar29 >> 0x16) & 3);
    iVar9 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this_01 + 0x31c));
    VectorSignedToFloat(*(int *)(this_01 + 0x400) + iVar15,(byte)(uVar29 >> 0x16) & 3);
    uVar5 = *(ushort *)(this_01 + 0x37e);
    *(int *)(this_01 + 0x400) = *(int *)(this_01 + 0x400) + iVar15;
    uVar29 = uVar29 & 0xfffffff;
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    iVar7 = iVar7 + (uint)uVar5 * 2;
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this_01 + 0x318),Globals::w >> 1,iVar7,'\x11','\x14');
    fVar10 = (float)VectorSignedToFloat((int)(fVar10 * 0.5),(byte)(uVar29 >> 0x16) & 3);
    fVar17 = fVar17 * fVar10;
    fVar31 = (float)VectorSignedToFloat(Globals::w >> 1,(byte)(uVar29 >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)(this_01 + 0x31c),(int)(fVar10 - fVar17),0,
               (int)(fVar17 + fVar17),iVar9,(float)(int)(fVar10 - fVar17),0,0,0,
               (int)(fVar31 - fVar17));
    iVar8 = Globals::w;
    uVar6 = Globals::font;
    pPVar24 = Globals::Canvas;
    iVar14 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_54);
    fVar10 = (float)VectorSignedToFloat(iVar9,(byte)(uVar29 >> 0x16) & 3);
    fVar17 = (float)VectorSignedToFloat(iVar7,(byte)(uVar29 >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar24,uVar6,aAStack_54,(iVar8 >> 1) - (iVar14 >> 1),(int)(fVar10 * 2.5 + fVar17),
               false);
    AbyssEngine::String::~String((String *)aAStack_54);
  }
LAB_00193608:
  iVar7 = PlayerEgo::isMining((PlayerEgo *)param_5);
  if (((((Globals::hints[0x11] == '\0') && (iVar7 == 0)) &&
       (iVar7 = Status::getCurrentCampaignMission(Globals::status), iVar7 == 2)) &&
      (((int)(uint)(*(uint *)(*(int *)(param_5 + 0x10) + 8) < 0x2ee1) <=
        *(int *)(*(int *)(param_5 + 0x10) + 0xc) &&
       (iVar7 = PlayerEgo::isDockingToAsteroid((PlayerEgo *)param_5), iVar7 == 0)))) &&
     (iVar7 = PlayerEgo::isDockedToAsteroid((PlayerEgo *)param_5), iVar7 == 0)) {
    iVar15 = *(int *)(this_01 + 0x460) + iVar15;
    if (2000 < iVar15) {
      iVar15 = 0;
    }
    VectorSignedToFloat(iVar15,(byte)(uVar29 >> 0x16) & 3);
    *(int *)(this_01 + 0x460) = iVar15;
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    pSVar20 = (String *)GameText::getText(Globals::gameText,0x26a);
    AbyssEngine::String::String((String *)aAStack_54,pSVar20,false);
    iVar15 = Globals::w;
    uVar6 = Globals::font;
    pPVar24 = Globals::Canvas;
    iVar7 = AbyssEngine::PaintCanvas::GetTextWidth
                      (Globals::Canvas,Globals::font,(String *)aAStack_54);
    AbyssEngine::PaintCanvas::DrawString
              (pPVar24,uVar6,aAStack_54,iVar15 / 2 - iVar7 / 2,
               *(int *)(Globals::layout + 0x2c) + (uint)*(ushort *)(this_01 + 0x37e),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::String::~String((String *)aAStack_54);
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  pPVar24 = (PaintCanvas *)(__stack_chk_guard - local_4c);
  iVar15 = local_4c;
  if ((PaintCanvas *)(__stack_chk_guard - local_4c) == (PaintCanvas *)0x0) {
    return;
  }
LAB_0019375e:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pPVar24,iVar15);
}

// ===== Hud::resetAnalogStick  @0x00193a24  (16 bytes)
/* Hud::resetAnalogStick() */

void __thiscall Hud::resetAnalogStick(Hud *this)

{
  *(short *)(this + 0x3ba) = (short)*(undefined4 *)(this + 0x3c0);
  *(short *)(this + 0x3bc) = (short)((uint)*(undefined4 *)(this + 0x3c0) >> 0x10);
  return;
}

// ===== Hud::drawBigNumber  @0x00193a36  (2 bytes)
/* Hud::drawBigNumber(int, int, int, bool) */

int Hud::drawBigNumber(int param_1,int param_2,int param_3,bool param_4)

{
  return param_1;
}

// ===== Hud::drawTitleImage  @0x00193a38  (2 bytes)
/* Hud::drawTitleImage(bool) */

bool Hud::drawTitleImage(bool param_1)

{
  return param_1;
}

// ===== Hud::drawCredits  @0x00193a3a  (2 bytes)
/* Hud::drawCredits() */

void Hud::drawCredits(void)

{
  return;
}

// ===== Hud::drawOrbitInformation  @0x00193a3c  (542 bytes)
/* Hud::drawOrbitInformation() */

void __thiscall Hud::drawOrbitInformation(Hud *this)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  int iVar3;
  SolarSystem *pSVar4;
  int iVar5;
  int iVar6;
  String *pSVar7;
  String aSStack_4c [8];
  String aSStack_44 [8];
  String aSStack_3c [8];
  AbyssEngine aAStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  iVar3 = Status::inAlienOrbit(Globals::status);
  if (iVar3 == 0) {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x174));
    iVar3 = *(int *)(Globals::layout + 0x21c) + iVar3;
    pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar5 = SolarSystem::hasNoOwner(pSVar4);
    if (iVar5 == 0) {
      AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 0x174),3,3);
    }
    uVar2 = Globals::font;
    pPVar1 = Globals::Canvas;
    Status::getStation(Globals::status);
    Station::getName();
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar2,aSStack_2c,iVar3,*(int *)(Globals::layout + 0x220),false);
    AbyssEngine::String::~String(aSStack_2c);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    iVar5 = Status::getCurrentCampaignMission(Globals::status);
    if (0xf < iVar5) {
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar5 = SolarSystem::getSecurityLevel(pSVar4);
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar6 = SolarSystem::getIndex(pSVar4);
      uVar2 = Globals::font;
      pPVar1 = Globals::Canvas;
      if ((iVar6 == 0x1a) && (1 < *(int *)(Globals::status + 0x114))) {
        iVar5 = 3;
      }
      Status::getSystem(Globals::status);
      SolarSystem::getName();
      AbyssEngine::String::String(aSStack_3c,aSStack_44,false);
      AbyssEngine::String::String(aSStack_4c," ",false);
      AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_4c);
      pSVar7 = (String *)GameText::getText(Globals::gameText,0x89);
      AbyssEngine::operator+((AbyssEngine *)aSStack_2c,aAStack_34,pSVar7);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar2,aSStack_2c,iVar3,*(int *)(Globals::layout + 0x224),false);
      AbyssEngine::String::~String(aSStack_2c);
      AbyssEngine::String::~String((String *)aAStack_34);
      AbyssEngine::String::~String(aSStack_4c);
      AbyssEngine::String::~String(aSStack_3c);
      AbyssEngine::String::~String(aSStack_44);
      AbyssEngine::PaintCanvas::SetColor
                ((uchar)Globals::Canvas,(&UNK_00259ea0)[iVar5 * 0xc],(&UNK_00259ea4)[iVar5 * 0xc],
                 (&UNK_00259ea8)[iVar5 * 0xc]);
      uVar2 = Globals::font;
      pPVar1 = Globals::Canvas;
      pSVar7 = (String *)GameText::getText(Globals::gameText,iVar5 + 0x192);
      AbyssEngine::PaintCanvas::DrawString
                (pPVar1,uVar2,pSVar7,iVar3,*(int *)(Globals::layout + 0x228),false);
    }
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Hud::drawMenu  @0x00193cf8  (650 bytes)
/* Hud::drawMenu(int) */

void Hud::drawMenu(int param_1)

{
  PaintCanvas *this;
  uint *puVar1;
  Ship *pSVar2;
  int iVar3;
  undefined4 extraout_r1;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_3c [2];
  String aSStack_34 [8];
  AbyssEngine aAStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  Layout::drawMask();
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(param_1 + 0x238),
             *(int *)(param_1 + 0x360) + *(int *)(param_1 + 0x468),
             *(int *)(param_1 + 0x46c) + *(int *)(param_1 + 0x364));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(param_1 + 0x2fc),
             *(int *)(param_1 + 0x468) + *(int *)(param_1 + 0x370) + *(int *)(param_1 + 0x378) / 2,
             (*(int *)(param_1 + 0x46c) + *(int *)(param_1 + 0x364) + *(int *)(param_1 + 0x368) / 2)
             - *(int *)(Globals::layout + 0x22c),'\x11','D');
  iVar4 = *(int *)(param_1 + 0x364) + *(int *)(param_1 + 0x46c) + *(int *)(param_1 + 0x368);
  if ((*(uint **)(param_1 + 0x18) != (uint *)0x0) && (1 < **(uint **)(param_1 + 0x18))) {
    uVar5 = 0;
    do {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(param_1 + 0x240),
                 *(int *)(param_1 + 0x360) + *(int *)(param_1 + 0x468),iVar4);
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + *(int *)(param_1 + 0x36c);
    } while (uVar5 < **(int **)(param_1 + 0x18) - 1U);
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(param_1 + 0x23c),
             *(int *)(param_1 + 0x360) + *(int *)(param_1 + 0x468),iVar4);
  puVar1 = *(uint **)(param_1 + 0x18);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar5 = 0;
    do {
      TouchButton::draw(*(TouchButton **)(puVar1[1] + uVar5 * 4));
      puVar1 = *(uint **)(param_1 + 0x18);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar1);
  }
  if (*(int *)(param_1 + 0x1d8) == 0) {
    pSVar2 = (Ship *)Status::getShip(Globals::status);
    iVar3 = Ship::hasCloak(pSVar2);
    if (iVar3 == 0) {
      pSVar2 = (Ship *)Status::getShip(Globals::status);
      iVar3 = Ship::hasJumpDrive(pSVar2);
      if (iVar3 != 1) goto LAB_00193f6a;
    }
    AbyssEngine::String::String(aSStack_34,"X ",false);
    local_3c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1,local_3c));
    AbyssEngine::operator+(aAStack_2c,aSStack_34,(String *)local_3c);
    AbyssEngine::String::~String((String *)local_3c);
    AbyssEngine::String::~String(aSStack_34);
    iVar6 = *(int *)(param_1 + 0x468) + *(int *)(param_1 + 0x370) + *(int *)(param_1 + 0x378) / 2;
    iVar7 = iVar4 + *(int *)(Globals::layout + 0x30) / 2 + *(int *)(Globals::layout + 0x288);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(param_1 + 0x314),iVar6,iVar7,'\x11','\x14');
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(param_1 + 0x310),iVar6 - *(int *)(Globals::layout + 0x230),
               *(int *)(Globals::layout + 0x28c) + *(int *)(Globals::layout + 0x30) + iVar7,'\x11',
               '\x12');
    uVar5 = Globals::font;
    this = Globals::Canvas;
    iVar8 = *(int *)(Globals::layout + 0x230);
    iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(param_1 + 0x314));
    iVar3 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
    AbyssEngine::PaintCanvas::DrawString
              (this,uVar5,aAStack_2c,iVar8 + iVar6,
               ((iVar7 + iVar4 / 2) - iVar3 / 2) + *(int *)(Globals::layout + 0x234),false);
    AbyssEngine::String::~String((String *)aAStack_2c);
  }
LAB_00193f6a:
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Hud::hudAction  @0x00193fec  (4 bytes)
/* Hud::hudAction(int, Level*, Radar*) */

undefined4 Hud::hudAction(int param_1,Level *param_2,Radar *param_3)

{
  return 0;
}

// ===== Hud::jumpMapSelected  @0x00193ff0  (6 bytes)
/* Hud::jumpMapSelected() */

Hud __thiscall Hud::jumpMapSelected(Hud *this)

{
  return this[0x214];
}

// ===== Hud::setJumpMapSelected  @0x00193ff6  (6 bytes)
/* Hud::setJumpMapSelected(bool) */

void __thiscall Hud::setJumpMapSelected(Hud *this,bool param_1)

{
  this[0x214] = (Hud)param_1;
  return;
}

// ===== Hud::enableFireForTutorial  @0x00193ffc  (6 bytes)
/* Hud::enableFireForTutorial(bool) */

void __thiscall Hud::enableFireForTutorial(Hud *this,bool param_1)

{
  this[0x441] = (Hud)param_1;
  return;
}

// ===== Hud::getAnalogX  @0x00194002  (40 bytes)
/* Hud::getAnalogX() */

float __thiscall Hud::getAnalogX(Hud *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar2 = (float)VectorSignedToFloat((uint)*(ushort *)(this + 0x3ba) -
                                     (uint)*(ushort *)(this + 0x3c0),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x47c),(byte)(in_fpscr >> 0x16) & 3);
  return fVar2 / fVar1;
}

// ===== Hud::getAnalogY  @0x0019402a  (40 bytes)
/* Hud::getAnalogY() */

float __thiscall Hud::getAnalogY(Hud *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar2 = (float)VectorSignedToFloat((uint)*(ushort *)(this + 0x3bc) -
                                     (uint)*(ushort *)(this + 0x3c2),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x47c),(byte)(in_fpscr >> 0x16) & 3);
  return fVar2 / fVar1;
}

// ===== Hud::touchedElement  @0x00194054  (1166 bytes)
/* Hud::touchedElement(unsigned int, unsigned int) */

undefined4 __thiscall Hud::touchedElement(Hud *this,uint param_1,uint param_2)

{
  int iVar1;
  ushort uVar2;
  Hud *pHVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  
  bVar7 = (*(ushort *)(this + 0x222) & 0xff) == 0;
  pHVar3 = this;
  if (!bVar7) {
    pHVar3 = *(Hud **)(this + 0x18);
  }
  if (bVar7 || pHVar3 == (Hud *)0x0) {
    uVar2 = *(ushort *)(this + 0x222) >> 8;
    if (Globals::iPad == '\0') {
      if (this[0x4c0] != (Hud)0x0) {
        if ((((*(ushort *)(this + 0x3f2) <= param_2) &&
             (param_2 <= (uint)*(ushort *)(this + 0x3f2) + *(int *)(this + 0x474))) &&
            (*(ushort *)(this + 0x3f0) <= param_1)) &&
           (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x3f0))) {
          return 0x200;
        }
        if (((*(ushort *)(this + 0x3f6) <= param_2) &&
            (param_2 <= (uint)*(ushort *)(this + 0x3f6) + *(int *)(this + 0x474))) &&
           ((*(ushort *)(this + 0x3f4) <= param_1 &&
            (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x3f4))))) {
          return 0x400;
        }
        if (((*(ushort *)(this + 0x3fc) <= param_2) &&
            (param_2 <= (uint)*(ushort *)(this + 0x3fc) + *(int *)(this + 0x474))) &&
           ((*(ushort *)(this + 0x3fa) <= param_1 &&
            (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x3fa))))) {
          return 0x800;
        }
      }
      if (param_2 < (uint)(Globals::h >> 2)) {
        if (((*(ushort *)(this + 0x3a8) <= param_2) &&
            (param_2 <= (uint)*(ushort *)(this + 0x3a8) + *(int *)(this + 0x474))) &&
           ((*(ushort *)(this + 0x3a6) <= param_1 &&
            (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x3a6))))) {
          return 1;
        }
      }
      else if (param_1 < (uint)(Globals::w >> 1)) {
        if ((((this[0x1c2] != (Hud)0x0) && (*(ushort *)(this + 0x3ae) <= param_2)) &&
            (iVar4 = *(int *)(this + 0x474), param_2 <= (uint)*(ushort *)(this + 0x3ae) + iVar4)) &&
           (((uint)*(ushort *)(this + 0x3ac) - iVar4 <= param_1 &&
            (param_1 <= iVar4 + (uint)*(ushort *)(this + 0x3ac))))) {
          return 2;
        }
        if (((*(ushort *)(this + 0x396) <= param_2) &&
            (param_2 <= (uint)*(ushort *)(this + 0x396) + *(int *)(this + 0x474))) &&
           ((*(ushort *)(this + 0x394) <= param_1 &&
            (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x394))))) {
          return 0x40;
        }
        iVar4 = *(int *)(this + 0x474);
        if ((((*(ushort *)(this + 0x3a2) <= param_2) &&
             (param_2 <= (uint)*(ushort *)(this + 0x3a2) + iVar4)) &&
            (*(ushort *)(this + 0x3a0) <= param_1)) &&
           (param_1 <= (uint)*(ushort *)(this + 0x3a0) + iVar4)) {
          return 0x100;
        }
        uVar6 = *(uint *)(this + 0x3c0);
        if ((((uVar6 & 0xffff) - iVar4 <= param_1) && (param_1 <= iVar4 + (uVar6 & 0xffff))) &&
           (((uVar6 >> 0x10) - *(int *)(this + 0x478) <= param_2 &&
            (param_2 <= *(int *)(this + 0x478) + (uVar6 >> 0x10))))) {
          return 0x20;
        }
      }
      else {
        iVar4 = *(int *)(this + 0x474);
        if ((((*(ushort *)(this + 0x38e) <= param_1) &&
             (param_1 <= (uint)*(ushort *)(this + 0x38e) + iVar4)) &&
            (*(ushort *)(this + 0x390) <= param_2)) &&
           (param_2 <= (uint)*(ushort *)(this + 0x390) + iVar4)) goto LAB_001943a8;
        uVar6 = *(uint *)(this + 0x388);
        if (param_1 <= iVar4 + (uVar6 & 0xffff)) {
          uVar5 = (uVar6 & 0xffff) - (iVar4 >> 1);
          bVar8 = param_1 <= uVar5;
          bVar7 = uVar5 == param_1;
          if (!bVar8 || bVar7) {
            bVar8 = param_2 <= uVar6 >> 0x10;
            bVar7 = uVar6 >> 0x10 == param_2;
          }
          if ((!bVar8 || bVar7) && (param_2 <= iVar4 + (uVar6 >> 0x10))) {
            return 8;
          }
        }
        uVar6 = *(uint *)(this + 0x380) & 0xffff;
        if (((uVar6 <= param_1) && (param_1 <= uVar6 + *(int *)(this + 0x478))) &&
           ((uVar6 = *(uint *)(this + 0x380) >> 0x10, uVar6 <= param_2 &&
            (param_2 <= uVar6 + *(int *)(this + 0x478))))) {
          return 0x10;
        }
        if ((((uVar2 == 0) && (*(ushort *)(this + 0x3b2) <= param_1)) &&
            (param_1 <= (uint)*(ushort *)(this + 0x3b2) + (uint)*(ushort *)(this + 0x3b6))) &&
           ((*(ushort *)(this + 0x3b4) <= param_2 &&
            (param_2 <= (uint)*(ushort *)(this + 0x3b4) + (uint)*(ushort *)(this + 0x3b8))))) {
          return 4;
        }
        if (((*(ushort *)(this + 0x39c) <= param_2) &&
            (param_2 <= (uint)*(ushort *)(this + 0x39c) + iVar4)) &&
           ((*(ushort *)(this + 0x39a) <= param_1 &&
            (param_1 <= (uint)*(ushort *)(this + 0x39a) + iVar4)))) {
          return 0x20000000;
        }
      }
    }
    else {
      if ((((*(ushort *)(this + 0x3a8) <= param_2) &&
           (param_2 <= (uint)*(ushort *)(this + 0x3a8) + *(int *)(this + 0x474))) &&
          (*(ushort *)(this + 0x3a6) <= param_1)) &&
         (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x3a6))) {
        return 1;
      }
      if (((this[0x1c2] != (Hud)0x0) && (*(ushort *)(this + 0x3ae) <= param_2)) &&
         ((param_2 <= (uint)*(ushort *)(this + 0x3ae) + *(int *)(this + 0x474) &&
          ((*(ushort *)(this + 0x3ac) <= param_1 &&
           (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x3ac))))))) {
        return 2;
      }
      if ((((*(ushort *)(this + 0x396) <= param_2) &&
           (param_2 <= (uint)*(ushort *)(this + 0x396) + *(int *)(this + 0x474))) &&
          (*(ushort *)(this + 0x394) <= param_1)) &&
         (param_1 <= *(int *)(this + 0x474) + (uint)*(ushort *)(this + 0x394))) {
        return 0x40;
      }
      iVar4 = *(int *)(this + 0x474);
      if (((*(ushort *)(this + 0x3a2) <= param_2) &&
          (param_2 <= (uint)*(ushort *)(this + 0x3a2) + iVar4)) &&
         ((*(ushort *)(this + 0x3a0) <= param_1 &&
          (param_1 <= (uint)*(ushort *)(this + 0x3a0) + iVar4)))) {
        return 0x100;
      }
      uVar6 = *(uint *)(this + 0x3c0);
      if ((((uVar6 & 0xffff) - iVar4 <= param_1) && (param_1 <= iVar4 + (uVar6 & 0xffff))) &&
         (((uVar6 >> 0x10) - *(int *)(this + 0x478) <= param_2 &&
          (param_2 <= *(int *)(this + 0x478) + (uVar6 >> 0x10))))) {
        return 0x20;
      }
      if ((((*(ushort *)(this + 0x38e) <= param_1) &&
           (param_1 <= (uint)*(ushort *)(this + 0x38e) + iVar4)) &&
          (*(ushort *)(this + 0x390) <= param_2)) &&
         (param_2 <= (uint)*(ushort *)(this + 0x390) + iVar4)) {
LAB_001943a8:
        *(undefined4 *)(this + 0x40c) = 1000;
        return 0x80;
      }
      uVar6 = *(uint *)(this + 0x388);
      if (param_1 <= iVar4 + (uVar6 & 0xffff)) {
        uVar5 = (uVar6 & 0xffff) - (iVar4 >> 1);
        bVar8 = param_1 <= uVar5;
        bVar7 = uVar5 == param_1;
        if (!bVar8 || bVar7) {
          bVar8 = param_2 <= uVar6 >> 0x10;
          bVar7 = uVar6 >> 0x10 == param_2;
        }
        if ((!bVar8 || bVar7) && (param_2 <= iVar4 + (uVar6 >> 0x10))) {
          return 8;
        }
      }
      uVar6 = *(uint *)(this + 0x380);
      iVar1 = *(int *)(this + 0x478) >> 1;
      if ((((uVar6 & 0xffff) - iVar1 <= param_1) && (param_1 <= iVar1 + (uVar6 & 0xffff))) &&
         (((uVar6 >> 0x10) - iVar1 <= param_2 && (param_2 <= iVar1 + (uVar6 >> 0x10))))) {
        return 0x10;
      }
      if ((((uVar2 == 0) && (*(ushort *)(this + 0x3b2) <= param_1)) &&
          (param_1 <= (uint)*(ushort *)(this + 0x3b2) + (uint)*(ushort *)(this + 0x3b6))) &&
         ((*(ushort *)(this + 0x3b4) <= param_2 &&
          (param_2 <= (uint)*(ushort *)(this + 0x3b4) + (uint)*(ushort *)(this + 0x3b8))))) {
        return 4;
      }
      if (((*(ushort *)(this + 0x39c) <= param_2) &&
          (param_2 <= (uint)*(ushort *)(this + 0x39c) + iVar4)) &&
         ((*(ushort *)(this + 0x39a) <= param_1 &&
          (param_1 <= (uint)*(ushort *)(this + 0x39a) + iVar4)))) {
        return 0x20000000;
      }
      if (this[0x4c0] != (Hud)0x0) {
        if ((((*(ushort *)(this + 0x3f2) <= param_2) &&
             (param_2 <= (uint)*(ushort *)(this + 0x3f2) + iVar4)) &&
            (*(ushort *)(this + 0x3f0) <= param_1)) &&
           (param_1 <= (uint)*(ushort *)(this + 0x3f0) + iVar4)) {
          return 0x200;
        }
        if (((*(ushort *)(this + 0x3f6) <= param_2) &&
            (param_2 <= (uint)*(ushort *)(this + 0x3f6) + iVar4)) &&
           ((*(ushort *)(this + 0x3f4) <= param_1 &&
            (param_1 <= (uint)*(ushort *)(this + 0x3f4) + iVar4)))) {
          return 0x400;
        }
        if (((*(ushort *)(this + 0x3fc) <= param_2) &&
            (param_2 <= (uint)*(ushort *)(this + 0x3fc) + iVar4)) &&
           ((*(ushort *)(this + 0x3fa) <= param_1 &&
            (param_1 <= (uint)*(ushort *)(this + 0x3fa) + iVar4)))) {
          return 0x800;
        }
      }
    }
  }
  else if (*(int *)pHVar3 != 0) {
    uVar6 = 0;
    do {
      iVar4 = TouchButton::OnTouchBegin
                        (*(TouchButton **)(*(int *)(pHVar3 + 4) + uVar6 * 4),param_1,param_2);
      if (iVar4 != 0) {
        return **(undefined4 **)(*(int *)(*(int *)(this + 0x18) + 4) + uVar6 * 4);
      }
      pHVar3 = *(Hud **)(this + 0x18);
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)pHVar3);
  }
  return 0;
}

// ===== Hud::touchBegin  @0x001944f0  (182 bytes)
/* Hud::touchBegin(unsigned int, unsigned int, void*) */

undefined4 __thiscall Hud::touchBegin(Hud *this,uint param_1,uint param_2,void *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = touchedElement(this,param_1,param_2);
  if (uVar1 == 0) {
    iVar2 = 0;
    do {
      iVar3 = *(int *)(*(int *)(this + 0x22c) + 4);
      if (*(void **)(iVar3 + iVar2 * 4) == param_3) {
        *(uint *)(this + 0x224) =
             *(uint *)(this + 0x224) & ~*(uint *)(*(int *)(this + 0x230) + iVar2 * 4);
        *(undefined4 *)(*(int *)(this + 0x230) + iVar2 * 4) = 0;
        *(undefined4 *)(iVar3 + iVar2 * 4) = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x19);
  }
  else {
    iVar3 = 0;
    iVar2 = *(int *)(*(int *)(this + 0x22c) + 4);
    do {
      if (*(void **)(iVar2 + iVar3 * 4) == param_3) {
        uVar4 = *(uint *)(*(int *)(this + 0x230) + iVar3 * 4);
        if (uVar1 == uVar4) {
          uVar4 = *(uint *)(this + 0x224);
        }
        else {
          uVar4 = *(uint *)(this + 0x224) & ~uVar4;
        }
        *(uint *)(this + 0x224) = uVar4 | uVar1;
        *(uint *)(*(int *)(this + 0x230) + iVar3 * 4) = uVar1;
        goto LAB_0019459e;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x19);
    iVar3 = 0;
    do {
      if (*(int *)(iVar2 + iVar3 * 4) == 0) {
        *(void **)(iVar2 + iVar3 * 4) = param_3;
        *(uint *)(*(int *)(this + 0x230) + iVar3 * 4) = uVar1;
        *(uint *)(this + 0x224) = uVar1 | *(uint *)(this + 0x224);
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x19);
  }
LAB_0019459e:
  return *(undefined4 *)(this + 0x224);
}

// ===== Hud::touchMove  @0x001945a8  (190 bytes)
/* Hud::touchMove(unsigned int, unsigned int, void*) */

undefined4 __thiscall Hud::touchMove(Hud *this,uint param_1,uint param_2,void *param_3)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  int iVar7;
  
  iVar2 = 0;
  while ((*(void **)(*(int *)(*(int *)(this + 0x22c) + 4) + iVar2 * 4) != param_3 ||
         (*(int *)(*(int *)(this + 0x230) + iVar2 * 4) != 0x20))) {
    iVar2 = iVar2 + 1;
    if (0x18 < iVar2) {
      uVar3 = touchBegin(this,param_1,param_2,param_3);
      return uVar3;
    }
  }
  iVar4 = param_1 - (*(uint *)(this + 0x3c0) & 0xffff);
  iVar2 = param_2 - (*(uint *)(this + 0x3c0) >> 0x10);
  fVar6 = (float)VectorSignedToFloat(iVar2 * iVar2 + iVar4 * iVar4,(byte)(in_fpscr >> 0x16) & 3);
  fVar6 = (float)Globals::sqrt(fVar6);
  iVar5 = *(int *)(this + 0x47c);
  iVar7 = (int)fVar6;
  if (iVar5 < iVar7) {
    sVar1 = __aeabi_idiv(iVar5 * iVar4,iVar7);
    uVar3 = *(undefined4 *)(this + 0x3c0);
    *(short *)(this + 0x3ba) = sVar1 + (short)uVar3;
    sVar1 = __aeabi_idiv(iVar5 * iVar2,iVar7);
    *(short *)(this + 0x3bc) = sVar1 + (short)((uint)uVar3 >> 0x10);
  }
  else {
    *(short *)(this + 0x3ba) = (short)param_1;
    *(short *)(this + 0x3bc) = (short)param_2;
  }
  return 0x20;
}

// ===== Hud::touchEnd  @0x00194668  (118 bytes)
/* Hud::touchEnd(unsigned int, unsigned int, void*) */

uint __thiscall Hud::touchEnd(Hud *this,uint param_1,uint param_2,void *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = 0;
  uVar4 = 0;
  do {
    iVar3 = *(int *)(*(int *)(this + 0x22c) + 4);
    if (*(void **)(iVar3 + iVar2 * 4) == param_3) {
      uVar4 = *(uint *)(*(int *)(this + 0x230) + iVar2 * 4);
      *(uint *)(this + 0x224) = *(uint *)(this + 0x224) & ~uVar4;
      *(undefined4 *)(iVar3 + iVar2 * 4) = 0;
      *(undefined4 *)(*(int *)(this + 0x230) + iVar2 * 4) = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x19);
  if (((this[0x222] != (Hud)0x0) && (puVar1 = *(uint **)(this + 0x18), puVar1 != (uint *)0x0)) &&
     (*puVar1 != 0)) {
    uVar5 = 0;
    do {
      TouchButton::OnTouchEnd(*(TouchButton **)(puVar1[1] + uVar5 * 4),param_1,param_2);
      puVar1 = *(uint **)(this + 0x18);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar1);
  }
  return uVar4;
}

