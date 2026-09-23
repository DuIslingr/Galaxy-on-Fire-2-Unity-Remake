// Class: ListItemWindow
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ListItemWindow::ListItemWindow  @0x001592c0  (160 bytes)
/* ListItemWindow::ListItemWindow() */

ListItemWindow * __thiscall ListItemWindow::ListItemWindow(ListItemWindow *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  AbyssEngine::String::String((String *)(this + 0x74));
  AbyssEngine::String::String((String *)(this + 0x7c));
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x90) = 0x3f800000;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = uVar1;
  *(undefined4 *)(this + 0x9c) = uVar2;
  *(undefined4 *)(this + 0xa0) = uVar3;
  *(undefined4 *)(this + 0xa4) = 0x3f800000;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xac) = uVar1;
  *(undefined4 *)(this + 0xb0) = uVar2;
  *(undefined4 *)(this + 0xb4) = uVar3;
  *(undefined8 *)(this + 0xb8) = 0x3f800000;
  *(undefined8 *)(this + 0xc0) = 0x3f8000003f800000;
  *(undefined4 *)(this + 200) = 0x3f800000;
  *(undefined4 *)(this + 0xcc) = 0x3f800000;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0xd4) = uVar1;
  *(undefined4 *)(this + 0xd8) = uVar2;
  *(undefined4 *)(this + 0xdc) = uVar3;
  *(undefined4 *)(this + 0xe0) = 0x3f800000;
  *(undefined4 *)(this + 0xe4) = 0;
  *(undefined4 *)(this + 0xe8) = uVar1;
  *(undefined4 *)(this + 0xec) = uVar2;
  *(undefined4 *)(this + 0xf0) = uVar3;
  *(undefined8 *)(this + 0xf4) = 0x3f800000;
  *(undefined8 *)(this + 0xfc) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x104) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  iVar4 = AbyssEngine::PaintCanvas::GetTextHeight(Globals::Canvas,Globals::font);
  *(int *)(this + 0x1c) = iVar4 / 2 + -1;
  *(undefined4 *)(this + 0x20) = 0;
  return this;
}

// ===== ListItemWindow::~ListItemWindow  @0x001593a0  (198 bytes)
/* ListItemWindow::~ListItemWindow() */

ListItemWindow * __thiscall ListItemWindow::~ListItemWindow(ListItemWindow *this)

{
  void *pvVar1;
  void *pvVar2;
  
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
  if (*(Array **)(this + 4) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 4));
    pvVar1 = *(void **)(this + 4);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 4) = 0;
  }
  pvVar1 = *(void **)(this + 8);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
LAB_00159400:
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    else {
      operator_delete__(*(void **)((int)pvVar1 + 4));
      pvVar2 = *(void **)(this + 8);
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      pvVar1 = pvVar2;
      if (pvVar2 != (void *)0x0) goto LAB_00159400;
    }
    *(undefined4 *)(this + 8) = 0;
  }
  pvVar1 = *(void **)(this + 0xc);
  if (pvVar1 == (void *)0x0) goto LAB_00159440;
  if (*(void **)((int)pvVar1 + 4) == (void *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = 0;
LAB_0015942e:
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  else {
    operator_delete__(*(void **)((int)pvVar1 + 4));
    pvVar2 = *(void **)(this + 0xc);
    *(undefined4 *)((int)pvVar1 + 4) = 0;
    pvVar1 = pvVar2;
    if (pvVar2 != (void *)0x0) goto LAB_0015942e;
  }
  *(undefined4 *)(this + 0xc) = 0;
LAB_00159440:
  if (*(ScrollTouchWindow **)(this + 0x18) != (ScrollTouchWindow *)0x0) {
    pvVar1 = (void *)ScrollTouchWindow::~ScrollTouchWindow(*(ScrollTouchWindow **)(this + 0x18));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  AbyssEngine::String::~String((String *)(this + 0x7c));
  AbyssEngine::String::~String((String *)(this + 0x74));
  return this;
}

// ===== ListItemWindow::set  @0x00159468  (7438 bytes)
/* ListItemWindow::set(ListItem*, unsigned int, unsigned int, unsigned int, unsigned int, bool) */

void __thiscall
ListItemWindow::set(ListItemWindow *this,ListItem *param_1,uint param_2,uint param_3,uint param_4,
                   uint param_5,bool param_6)

{
  ListItemWindow *pLVar1;
  byte bVar2;
  bool bVar3;
  PaintCanvas *pPVar4;
  GameText *pGVar5;
  Globals *this_00;
  char cVar6;
  short sVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  Engine *pEVar10;
  ScrollTouchWindow *pSVar11;
  ListItem *pLVar12;
  String *pSVar13;
  String *pSVar14;
  String *pSVar15;
  AbyssEngine *pAVar16;
  SolarSystem *pSVar17;
  Ship *pSVar18;
  void *pvVar19;
  ushort uVar20;
  int iVar21;
  Layout *pLVar22;
  char *pcVar23;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  int iVar24;
  float *pfVar25;
  uint uVar26;
  void *pvVar27;
  int *piVar28;
  Item *this_01;
  uint in_fpscr;
  float fVar29;
  int iVar30;
  undefined4 uVar31;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s2;
  float fVar32;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float fVar33;
  undefined8 uVar34;
  undefined3 in_stack_00000009;
  ListItemWindow *local_164;
  String aSStack_15c [8];
  String aSStack_154 [8];
  AbyssEngine aAStack_14c [8];
  String aSStack_144 [8];
  String aSStack_13c [8];
  String aSStack_134 [8];
  String aSStack_12c [8];
  String aSStack_124 [8];
  String aSStack_11c [8];
  String aSStack_114 [8];
  AbyssEngine aAStack_10c [8];
  int local_104 [2];
  int local_fc [2];
  undefined4 local_f4 [2];
  String aSStack_ec [4];
  int local_e8;
  String aSStack_e4 [8];
  AEMath aAStack_dc [60];
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int local_64;
  
  local_64 = __stack_chk_guard;
  *(ListItem **)(this + 0x14) = param_1;
  *(uint *)(this + 0x34) = param_2;
  *(uint *)(this + 0x38) = param_3;
  *(uint *)(this + 0x3c) = param_4;
  *(uint *)(this + 0x40) = param_5;
  cVar6 = Globals::iPadHD;
  if (Globals::iPad == '\0') {
    iVar24 = 0;
    *(undefined4 *)(this + 100) = 0;
    *(undefined4 *)(this + 0x68) = 0;
    uVar26 = Globals::w;
    *(uint *)(this + 0x6c) = Globals::w;
    iVar30 = Globals::h;
    iVar21 = 0;
    *(int *)(this + 0x70) = Globals::h;
    *(undefined4 *)(this + 0x10c) = 0;
  }
  else {
    if (Globals::iPadHD == '\0') {
      pfVar25 = (float *)&DAT_0015a358;
      uVar26 = 0x28a;
      if (Globals::iPadLarge != '\0') {
        pfVar25 = (float *)&DAT_0015a35c;
      }
      fVar29 = *pfVar25;
      if (Globals::iPadLarge != '\0') {
        uVar26 = 0x514;
      }
    }
    else {
      fVar29 = 562.5;
      uVar26 = 0x392;
    }
    *(uint *)(this + 0x6c) = uVar26;
    iVar30 = (int)fVar29;
    *(int *)(this + 0x70) = iVar30;
    iVar21 = ((int)Globals::w >> 1) - (uVar26 >> 1);
    *(int *)(this + 100) = iVar21;
    iVar24 = (Globals::h >> 1) - (iVar30 >> 1);
    *(int *)(this + 0x68) = iVar24;
    if (cVar6 == '\0') {
      puVar8 = &DAT_0015a36c;
      if (Globals::retinaDisplay != '\0') {
        puVar8 = &DAT_0015a370;
      }
      uVar31 = *puVar8;
    }
    else {
      uVar31 = 0xbe99999a;
    }
    *(undefined4 *)(this + 0x10c) = uVar31;
  }
  local_164 = this + 100;
  Layout::setWindowDimensions(Globals::layout,iVar21,iVar24,uVar26,iVar30);
  if (*(Array **)this != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)this);
    pvVar27 = *(void **)this;
    if (pvVar27 != (void *)0x0) {
      if (*(void **)((int)pvVar27 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar27 + 4));
      }
      operator_delete(pvVar27);
    }
  }
  *(undefined4 *)this = 0;
  if (*(Array **)(this + 4) != (Array *)0x0) {
    ArrayReleaseClasses<AbyssEngine::String*>(*(Array **)(this + 4));
    pvVar27 = *(void **)(this + 4);
    if (pvVar27 != (void *)0x0) {
      if (*(void **)((int)pvVar27 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar27 + 4));
      }
      operator_delete(pvVar27);
    }
  }
  *(undefined4 *)(this + 4) = 0;
  puVar8 = operator_new(0xc);
  puVar9 = operator_new__(4);
  puVar8[1] = puVar9;
  *puVar9 = 0;
  puVar8[2] = 1;
  *puVar8 = 0;
  *(undefined4 **)this = puVar8;
  puVar8 = operator_new(0xc);
  puVar9 = operator_new__(4);
  puVar8[1] = puVar9;
  puVar8[2] = 1;
  *puVar9 = 0;
  *puVar8 = 0;
  *(undefined4 **)(this + 4) = puVar8;
  iVar30 = ::ListItem::isShip(param_1);
  if (iVar30 == 1) {
    *(int *)(this + 0x20) =
         ((((*(int *)(this + 0x70) - *(int *)(Globals::layout + 0xc)) -
           *(int *)(Globals::layout + 0x10)) - *(int *)(Globals::layout + 0x20)) -
         *(int *)(Globals::layout + 0x24)) / 2 - *(int *)(Globals::layout + 0x2c);
    this[0x54] = (ListItemWindow)0x1;
    *(undefined4 *)(this + 0x110) = 0x40333333;
    iVar30 = Ship::getRace(*(Ship **)(param_1 + 0xc));
    this_00 = Globals::globals;
    iVar21 = Ship::getIndex(*(Ship **)(param_1 + 0xc));
    uVar31 = Globals::getShipGroup(this_00,iVar21,iVar30,true);
    *(undefined4 *)(this + 0x10) = uVar31;
    AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x84));
    pPVar4 = Globals::Canvas;
    uVar26 = *(uint *)(this + 0x84);
    iVar21 = Ship::getIndex(*(Ship **)(param_1 + 0xc));
    AbyssEngine::PaintCanvas::TransformAddMesh
              (pPVar4,uVar26,*(ushort *)(&DAT_00258630 + iVar21 * 2),false);
    pLVar1 = this + 0x88;
    *(uint *)pLVar1 = 0xffffffff;
    iVar21 = Ship::getIndex(*(Ship **)(param_1 + 0xc));
    if (*(short *)(&DAT_002586b0 + iVar21 * 2) != -1) {
      AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)pLVar1);
      pPVar4 = Globals::Canvas;
      uVar26 = *(uint *)pLVar1;
      iVar21 = Ship::getIndex(*(Ship **)(param_1 + 0xc));
      AbyssEngine::PaintCanvas::TransformAddMesh
                (pPVar4,uVar26,*(ushort *)(&DAT_002586b0 + iVar21 * 2),false);
    }
    if (iVar30 == 0) {
      uVar20 = 0x276f;
    }
    else if (iVar30 == 1) {
      uVar20 = 0x2771;
    }
    else if (iVar30 == 3) {
      uVar20 = 0x2770;
    }
    else {
      uVar20 = 0x2773;
      if (iVar30 == 2) {
        uVar20 = 0x2772;
      }
    }
    AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,uVar20,(uint *)(this + 0x108),false);
    AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0x8c));
    AbyssEngine::PaintCanvas::CameraSetPerspective
              ((uint)Globals::Canvas,extraout_s0,extraout_s1,extraout_s2);
    AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
    puVar8 = (undefined4 *)
             AbyssEngine::PaintCanvas::CameraGetLocal(Globals::Canvas,*(uint *)(this + 0x8c));
    local_a0 = *puVar8;
    uStack_9c = puVar8[1];
    uStack_98 = puVar8[2];
    uStack_94 = puVar8[3];
    uStack_90 = puVar8[4];
    local_8c = puVar8[5];
    uStack_88 = puVar8[6];
    uStack_84 = puVar8[7];
    uStack_80 = puVar8[8];
    uStack_7c = puVar8[9];
    local_78 = puVar8[10];
    uStack_74 = puVar8[0xb];
    uStack_70 = puVar8[0xc];
    uStack_6c = puVar8[0xd];
    uStack_68 = puVar8[0xe];
    iVar30 = ::ListItem::getIndex(param_1);
    pfVar25 = (float *)&UNK_0015a3ac;
    if (iVar30 == 0x33) {
      pfVar25 = (float *)&DAT_0015a3b0;
    }
    if (Globals::iPadHD == '\0') {
      if (Globals::iPadLarge != '\0') {
        fVar29 = 0.6;
        VectorSignedToFloat(0x800 - Globals::w,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(Globals::w - 0x400,(byte)(in_fpscr >> 0x16) & 3);
        goto LAB_00159882;
      }
      if (Globals::iPad != '\0') {
        VectorSignedToFloat(0x400 - Globals::w,(byte)(in_fpscr >> 0x16) & 3);
        VectorSignedToFloat(Globals::w - 0x400,(byte)(in_fpscr >> 0x16) & 3);
        fVar29 = (float)VectorSignedToFloat(Globals::h + -0x300,(byte)(in_fpscr >> 0x16) & 3);
        fVar32 = -5531.0 - fVar29 * 0.6;
        fVar29 = *pfVar25 + fVar32;
        goto LAB_001598bc;
      }
      AbyssEngine::AEMath::MatrixSetTranslation
                (aAStack_dc,(Matrix *)&local_a0,*pfVar25 + -3500.0,extraout_s1_00,-3500.0);
      fVar29 = extraout_s0_05;
      fVar32 = extraout_s1_06;
      fVar33 = extraout_s2_05;
    }
    else {
      fVar29 = 0.1;
      VectorSignedToFloat(0x800 - Globals::w,(byte)(in_fpscr >> 0x16) & 3);
      VectorSignedToFloat(Globals::w - 0x400,(byte)(in_fpscr >> 0x16) & 3);
LAB_00159882:
      fVar33 = (float)VectorSignedToFloat(Globals::h + -0x600,(byte)(in_fpscr >> 0x16) & 3);
      fVar32 = -5531.0;
      fVar29 = -5531.0 - fVar33 * fVar29;
LAB_001598bc:
      AbyssEngine::AEMath::MatrixSetTranslation
                (aAStack_dc,(Matrix *)&local_a0,fVar29,extraout_s1_00,fVar32);
      fVar29 = extraout_s0_00;
      fVar32 = extraout_s1_01;
      fVar33 = extraout_s2_00;
    }
    AbyssEngine::AEMath::MatrixSetRotation(aAStack_dc,fVar29,fVar32,fVar33);
    AbyssEngine::PaintCanvas::CameraSetLocal
              (Globals::Canvas,*(uint *)(this + 0x8c),(Matrix *)&local_a0);
    pEVar10 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    AbyssEngine::Engine::LightSetLightDirection
              (pEVar10,extraout_s0_01,extraout_s1_02,extraout_s2_01,0xc0a00000);
    pEVar10 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    AbyssEngine::Engine::LightSetLightColorDiffuse
              (pEVar10,extraout_s0_02,extraout_s1_03,extraout_s2_02,0x3f800000);
    pEVar10 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    AbyssEngine::Engine::LightSetLightColorAmbient
              (pEVar10,extraout_s0_03,extraout_s1_04,extraout_s2_03,0x3e800000);
    pEVar10 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    AbyssEngine::Engine::LightSetLightColorSpecular
              (pEVar10,extraout_s0_04,extraout_s1_05,extraout_s2_04,0x3f000000);
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x50b,(uint *)(this + 0x44));
    uVar31 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x44));
    *(undefined4 *)(this + 0x2c) = uVar31;
    uVar31 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x44));
    *(undefined4 *)(this + 0x30) = uVar31;
    pLVar22 = Globals::layout;
    *(int *)(this + 0x24) =
         *(int *)(this + 100) + (*(int *)(this + 0x6c) >> 1) + *(int *)(Globals::layout + 0x2c) +
         (((*(int *)(this + 0x6c) >> 1) - *(int *)(Globals::layout + 0x2c)) -
         *(int *)(Globals::layout + 0x28)) / 2;
    *(int *)(this + 0x28) =
         *(int *)(pLVar22 + 0x20) + *(int *)(this + 0x68) + *(int *)(pLVar22 + 0xc) +
         *(int *)(this + 0x20) / 2;
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x512,(uint *)(this + 0x4c));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x513,(uint *)(this + 0x48));
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x514,(uint *)(this + 0x50));
    uVar31 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x4c));
    *(undefined4 *)(this + 0x60) = uVar31;
    puVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    puVar8[1] = puVar9;
    *puVar9 = 0;
    puVar8[2] = 1;
    *puVar8 = 0;
    *(undefined4 **)(this + 8) = puVar8;
    puVar8 = operator_new(0xc);
    puVar9 = operator_new__(4);
    puVar8[1] = puVar9;
    puVar8[2] = 1;
    *puVar9 = 0;
    *puVar8 = 0;
    *(undefined4 **)(this + 0xc) = puVar8;
    iVar30 = *(int *)(this + 0x20);
  }
  else {
    iVar30 = 0;
    this[0x54] = (ListItemWindow)0x0;
    *(undefined4 *)(this + 0x20) = 0;
  }
  pSVar11 = operator_new(0x20);
  pLVar22 = Globals::layout + 0x5c;
  if (0 < iVar30) {
    pLVar22 = Globals::layout + 0x1c;
  }
  iVar21 = *(int *)(Globals::layout + 0x2c);
  ScrollTouchWindow::ScrollTouchWindow
            (pSVar11,*(int *)local_164 + (*(int *)(this + 0x6c) >> 1) + iVar21,
             *(int *)(this + 0x68) + iVar21 + *(int *)(Globals::layout + 0xc) +
             *(int *)(Globals::layout + 0x20) + iVar30 + *(int *)pLVar22,
             (*(int *)(this + 0x6c) >> 1) - *(int *)(Globals::layout + 0x28),
             ((*(int *)(this + 0x70) -
              (*(int *)(Globals::layout + 0xc) + iVar21 * 2 + *(int *)(Globals::layout + 0x20) +
               iVar30 + *(int *)pLVar22)) - *(int *)(Globals::layout + 0x10)) -
             *(int *)(Globals::layout + 0x24),false);
  *(ScrollTouchWindow **)(this + 0x18) = pSVar11;
  iVar30 = ::ListItem::isItem(param_1);
  if (((iVar30 == 0) && (iVar30 = ::ListItem::isBluePrint(param_1), iVar30 == 0)) &&
     (iVar30 = ::ListItem::isPendingProduct(param_1), iVar30 != 1)) {
    iVar30 = ::ListItem::isShip(param_1);
    if (iVar30 != 1) goto LAB_0015a832;
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0xa5);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    iVar30 = Ship::getBaseHP(*(Ship **)(param_1 + 0xc));
    iVar21 = Ship::getMaxHP(*(Ship **)(param_1 + 0xc));
    pAVar16 = operator_new(8);
    if (iVar30 < iVar21) {
      uVar31 = Ship::getMaxHP(*(Ship **)(param_1 + 0xc));
      local_a0 = 0;
      AbyssEngine::String::Set(CONCAT44(uVar31,&local_a0));
      AbyssEngine::String::String((String *)aAStack_dc," (+)",false);
      AbyssEngine::operator+(pAVar16,(String *)&local_a0,aAStack_dc);
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      AbyssEngine::String::~String((String *)aAStack_dc);
      AbyssEngine::String::~String((String *)&local_a0);
      uVar31 = Ship::getMaxHP(*(Ship **)(param_1 + 0xc));
    }
    else {
      uVar31 = Ship::getBaseHP(*(Ship **)(param_1 + 0xc));
      *(undefined4 *)pAVar16 = 0;
      AbyssEngine::String::Set(CONCAT44(uVar31,pAVar16));
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      uVar31 = Ship::getBaseHP(*(Ship **)(param_1 + 0xc));
    }
    piVar28 = *(int **)(this + 8);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar31 = Ship::getBaseHP(pSVar18);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0xa6);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    iVar30 = Ship::getBaseLoad(*(Ship **)(param_1 + 0xc));
    iVar21 = Ship::getModdedLoad(*(Ship **)(param_1 + 0xc));
    pAVar16 = operator_new(8);
    if (iVar30 < iVar21) {
      uVar31 = Ship::getModdedLoad(*(Ship **)(param_1 + 0xc));
      local_a0 = 0;
      AbyssEngine::String::Set(CONCAT44(uVar31,&local_a0));
      AbyssEngine::String::String((String *)aAStack_dc," (+)",false);
      AbyssEngine::operator+(pAVar16,(String *)&local_a0,aAStack_dc);
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      AbyssEngine::String::~String((String *)aAStack_dc);
      AbyssEngine::String::~String((String *)&local_a0);
      uVar31 = Ship::getModdedLoad(*(Ship **)(param_1 + 0xc));
    }
    else {
      uVar31 = Ship::getBaseLoad(*(Ship **)(param_1 + 0xc));
      *(undefined4 *)pAVar16 = 0;
      AbyssEngine::String::Set(CONCAT44(uVar31,pAVar16));
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      uVar31 = Ship::getBaseLoad(*(Ship **)(param_1 + 0xc));
    }
    piVar28 = *(int **)(this + 8);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar31 = Ship::getBaseLoad(pSVar18);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0x109);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    puVar8 = operator_new(8);
    uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),0);
    *puVar8 = 0;
    AbyssEngine::String::Set(CONCAT44(uVar31,puVar8));
    piVar28 = *(int **)(this + 4);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 **)((int)pvVar27 + *piVar28 * 4) = puVar8;
    *piVar28 = piVar28[2];
    uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),0);
    piVar28 = *(int **)(this + 8);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar31 = Ship::getSlots(pSVar18,0);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0x10a);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    puVar8 = operator_new(8);
    uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),1);
    *puVar8 = 0;
    AbyssEngine::String::Set(CONCAT44(uVar31,puVar8));
    piVar28 = *(int **)(this + 4);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 **)((int)pvVar27 + *piVar28 * 4) = puVar8;
    *piVar28 = piVar28[2];
    uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),1);
    piVar28 = *(int **)(this + 8);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar31 = Ship::getSlots(pSVar18,1);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0x10b);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    puVar8 = operator_new(8);
    uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),2);
    *puVar8 = 0;
    AbyssEngine::String::Set(CONCAT44(uVar31,puVar8));
    piVar28 = *(int **)(this + 4);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 **)((int)pvVar27 + *piVar28 * 4) = puVar8;
    *piVar28 = piVar28[2];
    uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),2);
    piVar28 = *(int **)(this + 8);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar31 = Ship::getSlots(pSVar18,2);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0x10d);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    iVar30 = Ship::getNumAddedDeviceSlots(*(Ship **)(param_1 + 0xc));
    pAVar16 = operator_new(8);
    if (iVar30 < 1) {
      uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),3);
      *(undefined4 *)pAVar16 = 0;
      AbyssEngine::String::Set(CONCAT44(uVar31,pAVar16));
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),3);
      piVar28 = *(int **)(this + 8);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
      *piVar28 = piVar28[2];
    }
    else {
      uVar31 = Ship::getSlots(*(Ship **)(param_1 + 0xc),3);
      local_a0 = 0;
      AbyssEngine::String::Set(CONCAT44(uVar31,&local_a0));
      AbyssEngine::String::String((String *)aAStack_dc," (+)",false);
      AbyssEngine::operator+(pAVar16,(String *)&local_a0,aAStack_dc);
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      AbyssEngine::String::~String((String *)aAStack_dc);
      AbyssEngine::String::~String((String *)&local_a0);
      iVar30 = Ship::getSlots(*(Ship **)(param_1 + 0xc),3);
      iVar21 = Ship::getNumAddedDeviceSlots(*(Ship **)(param_1 + 0xc));
      piVar28 = *(int **)(this + 8);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(int *)((int)pvVar27 + *piVar28 * 4) = iVar21 + iVar30;
      *piVar28 = piVar28[2];
    }
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar31 = Ship::getSlots(pSVar18,3);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0xa4);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    fVar29 = (float)Ship::getHandlingForShop(*(Ship **)(param_1 + 0xc));
    fVar32 = (float)Ship::getUnmoddedHandling(*(Ship **)(param_1 + 0xc));
    pAVar16 = operator_new(8);
    if (fVar29 <= fVar32) {
      Ship::getHandlingForShop(*(Ship **)(param_1 + 0xc));
      *(undefined4 *)pAVar16 = 0;
      AbyssEngine::String::Set(CONCAT44(extraout_r1_04,pAVar16));
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
    }
    else {
      Ship::getHandling(*(Ship **)(param_1 + 0xc));
      local_a0 = 0;
      AbyssEngine::String::Set(CONCAT44(extraout_r1_03,&local_a0));
      AbyssEngine::String::String((String *)aAStack_dc," (+)",false);
      AbyssEngine::operator+(pAVar16,(String *)&local_a0,aAStack_dc);
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      AbyssEngine::String::~String((String *)aAStack_dc);
      AbyssEngine::String::~String((String *)&local_a0);
    }
    fVar29 = (float)Ship::getHandlingForShop(*(Ship **)(param_1 + 0xc));
    piVar28 = *(int **)(this + 8);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(int *)((int)pvVar27 + *piVar28 * 4) = (int)(fVar29 * 100.0);
    *piVar28 = piVar28[2];
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    fVar29 = (float)Ship::getUnmoddedHandling(pSVar18);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(int *)((int)pvVar27 + *piVar28 * 4) = (int)(fVar29 * 100.0);
    *piVar28 = piVar28[2];
    pSVar13 = operator_new(8);
    pSVar14 = (String *)GameText::getText(Globals::gameText,0x84);
    AbyssEngine::String::String(pSVar13,pSVar14,false);
    piVar28 = *(int **)this;
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
    *piVar28 = piVar28[2];
    pvVar27 = operator_new(8);
    ::ListItem::getPrice(param_1);
    Layout::formatCredits((int)pvVar27);
    piVar28 = *(int **)(this + 4);
    piVar28[2] = *piVar28 + 1;
    pvVar19 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar19;
    *(void **)((int)pvVar19 + *piVar28 * 4) = pvVar27;
    *piVar28 = piVar28[2];
    uVar31 = ::ListItem::getPrice(param_1);
    piVar28 = *(int **)(this + 8);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar18 = (Ship *)Status::getShip(Globals::status);
    uVar31 = Ship::getPrice(pSVar18);
    piVar28 = *(int **)(this + 0xc);
    piVar28[2] = *piVar28 + 1;
    pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
    piVar28[1] = (int)pvVar27;
    *(undefined4 *)((int)pvVar27 + *piVar28 * 4) = uVar31;
    *piVar28 = piVar28[2];
    pSVar11 = *(ScrollTouchWindow **)(this + 0x18);
    AbyssEngine::String::String(aSStack_154,"",false);
    pGVar5 = Globals::gameText;
    iVar30 = Ship::getIndex(*(Ship **)(param_1 + 0xc));
    pSVar14 = (String *)GameText::getText(pGVar5,iVar30 + 0x3d1);
    AbyssEngine::String::String(aSStack_15c,pSVar14,false);
    ScrollTouchWindow::setText(pSVar11,aSStack_154,aSStack_15c);
    AbyssEngine::String::~String(aSStack_15c);
    pSVar13 = aSStack_154;
  }
  else {
    iVar30 = ::ListItem::isItem(param_1);
    if (iVar30 == 1) {
      pLVar12 = param_1 + 0x10;
    }
    else {
      iVar21 = ::ListItem::isBluePrint(param_1);
      iVar30 = Globals::items;
      if (iVar21 == 1) {
        iVar21 = BluePrint::getIndex(*(BluePrint **)(param_1 + 8));
      }
      else {
        iVar21 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
      }
      pLVar12 = (ListItem *)(*(int *)(iVar30 + 4) + iVar21 * 4);
    }
    this_01 = *(Item **)pLVar12;
    iVar21 = *(int *)(Globals::status + 0x54);
    iVar30 = Item::getIndex(this_01);
    *(undefined1 *)(*(int *)(iVar21 + 4) + iVar30) = 1;
    uVar26 = 0;
    do {
      iVar30 = Item::getIndex(this_01);
      if ((iVar30 < 9) || (iVar30 = Item::getIndex(this_01), 0xb < iVar30)) {
        iVar30 = Item::getIndex(this_01);
        bVar2 = 0;
        if (iVar30 == 0xe4) {
          bVar2 = 1;
        }
      }
      else {
        bVar2 = 1;
      }
      iVar30 = 0;
      do {
        if ((&DAT_00258730)[iVar30] == uVar26 || (bool)(bVar2 & uVar26 == 0xd)) goto LAB_00159e80;
        iVar30 = iVar30 + 1;
      } while (iVar30 < 0xb);
      local_fc[0] = Item::getAttribute(this_01,uVar26);
      if (local_fc[0] != -0x3a6687db) {
        pSVar13 = operator_new(8);
        pSVar14 = (String *)GameText::getText(Globals::gameText,(&DAT_0025875c)[uVar26]);
        AbyssEngine::String::String(pSVar13,pSVar14,false);
        if (uVar26 < 0x20) {
          if ((1 << (uVar26 & 0xff) & 0xc0818000U) != 0) goto LAB_00159cac;
          if (uVar26 != 2) goto LAB_00159ca2;
          pSVar15 = operator_new(8);
          pSVar14 = (String *)GameText::getText(Globals::gameText,local_fc[0] + 0xdd);
          AbyssEngine::String::String(pSVar15,pSVar14,false);
        }
        else {
LAB_00159ca2:
          if (uVar26 - 0x39 < 2) {
LAB_00159cac:
            pSVar15 = operator_new(8);
            if (uVar26 == 0x17) {
              iVar30 = 0x9b;
              if (local_fc[0] == 1) {
                iVar30 = 0x9a;
              }
              if (local_fc[0] == 0) {
                iVar30 = 0x87;
              }
              pSVar14 = (String *)GameText::getText(Globals::gameText,iVar30);
              AbyssEngine::String::String(pSVar15,pSVar14,false);
            }
            else {
              iVar30 = 0x86;
              if (local_fc[0] == 0) {
                iVar30 = 0x87;
              }
              pSVar14 = (String *)GameText::getText(Globals::gameText,iVar30);
              AbyssEngine::String::String(pSVar15,pSVar14,false);
            }
          }
          else {
            if (uVar26 - 0x27 < 2) {
              pSVar15 = operator_new(8);
              pcVar23 = "";
              if (0 < local_fc[0]) {
                pcVar23 = "+";
              }
              AbyssEngine::String::String((String *)aAStack_dc,pcVar23,false);
              AbyssEngine::operator+((String *)&local_a0,(int *)aAStack_dc);
              AbyssEngine::String::String
                        (aSStack_e4,*(char **)(LISTITEMWINDOW_UNITS + uVar26 * 4),false);
              AbyssEngine::operator+((AbyssEngine *)pSVar15,(String *)&local_a0,aSStack_e4);
              AbyssEngine::String::~String(aSStack_e4);
              AbyssEngine::String::~String((String *)&local_a0);
              AbyssEngine::String::~String((String *)aAStack_dc);
              goto LAB_00159cf4;
            }
            if ((int)uVar26 < 0x26) {
              if (uVar26 == 0xc) {
                iVar30 = Item::getSort(this_01);
                if (iVar30 == 0xb) {
                  local_fc[0] = Item::getAttribute(this_01,0xc);
                  local_fc[0] = local_fc[0] / 1000;
                  pSVar15 = operator_new(8);
                  local_a0 = 0;
                  AbyssEngine::String::Set(CONCAT44(extraout_r1_01,(String *)&local_a0));
                  AbyssEngine::String::String((String *)aAStack_dc,"s",false);
                  AbyssEngine::operator+
                            ((AbyssEngine *)pSVar15,(String *)&local_a0,(String *)aAStack_dc);
                  AbyssEngine::String::~String((String *)aAStack_dc);
                  AbyssEngine::String::~String((String *)&local_a0);
                  pvVar27 = (void *)AbyssEngine::String::~String(pSVar13);
                  operator_delete(pvVar27);
                  pSVar13 = operator_new(8);
                  pSVar14 = (String *)GameText::getText(Globals::gameText,0x9d);
                  AbyssEngine::String::String(pSVar13,pSVar14,false);
                  goto LAB_00159cf4;
                }
                fVar29 = (float)VectorSignedToFloat(local_fc[0],(byte)(in_fpscr >> 0x16) & 3);
                iVar30 = Item::getAttribute(this_01,0xd);
                fVar32 = (float)VectorSignedToFloat(iVar30 * 0xfa,(byte)(in_fpscr >> 0x16) & 3);
                iVar21 = (int)((fVar29 / 3600.0) * fVar32);
                iVar30 = iVar21 / 100;
                local_fc[0] = iVar21 * 2 + iVar30 * -100;
                if (local_fc[0] % 100 != 0) {
                  local_fc[0] = iVar30 * 100;
                }
              }
              else if (uVar26 == 0xd) {
                local_fc[0] = local_fc[0] * 0xfa;
              }
              else if (uVar26 == 0xe) {
                pSVar15 = operator_new(8);
                VectorSignedToFloat(local_fc[0],(byte)(in_fpscr >> 0x16) & 3);
                local_a0 = 0;
                AbyssEngine::String::Set(CONCAT44(extraout_r1,(String *)&local_a0));
                AbyssEngine::String::String
                          ((String *)aAStack_dc,(char *)LISTITEMWINDOW_UNITS._56_4_,false);
                AbyssEngine::operator+
                          ((AbyssEngine *)pSVar15,(String *)&local_a0,(String *)aAStack_dc);
                goto LAB_0015a144;
              }
LAB_0015a0fe:
              pSVar15 = (String *)
                        AbyssEngine::String::String
                                  (aSStack_ec,*(char **)(LISTITEMWINDOW_UNITS + uVar26 * 4),false);
              iVar30 = local_e8;
              AbyssEngine::String::~String(pSVar15);
              pSVar15 = operator_new(8);
              if (iVar30 == 0) {
                *(undefined4 *)pSVar15 = 0;
                AbyssEngine::String::Set(CONCAT44(extraout_r1_02,pSVar15));
                goto LAB_00159cf4;
              }
              local_a0 = 0;
              AbyssEngine::String::Set(CONCAT44(extraout_r1_02,(String *)&local_a0));
              AbyssEngine::String::String
                        ((String *)aAStack_dc,*(char **)(LISTITEMWINDOW_UNITS + uVar26 * 4),false);
              AbyssEngine::operator+
                        ((AbyssEngine *)pSVar15,(String *)&local_a0,(String *)aAStack_dc);
            }
            else {
              if ((int)uVar26 < 0x33) {
                if (uVar26 == 0x26) {
                  iVar30 = ::ListItem::getIndex(param_1);
                  if ((iVar30 == 0x55) && (iVar30 = Status::hardCoreMode(), iVar30 == 1)) {
                    pSVar15 = operator_new(8);
                    *(undefined4 *)pSVar15 = 0;
                    AbyssEngine::String::Set(ZEXT48(pSVar15));
                    goto LAB_00159cf4;
                  }
                }
                else if (uVar26 == 0x31) {
                  fVar29 = (float)VectorSignedToFloat(local_fc[0],(byte)(in_fpscr >> 0x16) & 3);
                  local_fc[0] = (int)(fVar29 * 50.0);
                }
                goto LAB_0015a0fe;
              }
              if (uVar26 != 0x33 && uVar26 != 0x35) goto LAB_0015a0fe;
              pSVar15 = operator_new(8);
              VectorSignedToFloat(local_fc[0],(byte)(in_fpscr >> 0x16) & 3);
              local_a0 = 0;
              AbyssEngine::String::Set(CONCAT44(extraout_r1_00,(String *)&local_a0));
              AbyssEngine::String::String
                        ((String *)aAStack_dc,*(char **)(LISTITEMWINDOW_UNITS + uVar26 * 4),false);
              AbyssEngine::operator+
                        ((AbyssEngine *)pSVar15,(String *)&local_a0,(String *)aAStack_dc);
            }
LAB_0015a144:
            AbyssEngine::String::~String((String *)aAStack_dc);
            AbyssEngine::String::~String((String *)&local_a0);
          }
        }
LAB_00159cf4:
        piVar28 = *(int **)this;
        piVar28[2] = *piVar28 + 1;
        pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
        piVar28[1] = (int)pvVar27;
        *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
        *piVar28 = piVar28[2];
        piVar28 = *(int **)(this + 4);
        piVar28[2] = *piVar28 + 1;
        pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
        piVar28[1] = (int)pvVar27;
        *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar15;
        *piVar28 = piVar28[2];
        if ((uVar26 == 0xb) &&
           (((iVar30 = Item::getType(this_01), iVar30 == 0 ||
             (iVar30 = Item::getType(this_01), iVar30 == 2)) ||
            (iVar30 = Item::getSort(this_01), iVar30 == 0x27)))) {
          pSVar13 = operator_new(8);
          pSVar14 = (String *)GameText::getText(Globals::gameText,0xbc);
          AbyssEngine::String::String(pSVar13,pSVar14,false);
          piVar28 = *(int **)this;
          piVar28[2] = *piVar28 + 1;
          pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
          piVar28[1] = (int)pvVar27;
          *(String **)((int)pvVar27 + *piVar28 * 4) = pSVar13;
          *piVar28 = piVar28[2];
          iVar30 = Item::getAttribute(this_01,9);
          if (iVar30 == 0) {
            iVar30 = Item::getAttribute(this_01,10);
          }
          uVar34 = Item::getAttribute(this_01,0xb);
          fVar29 = (float)VectorSignedToFloat(iVar30,(byte)(in_fpscr >> 0x16) & 3);
          fVar32 = (float)VectorSignedToFloat((int)uVar34,(byte)(in_fpscr >> 0x16) & 3);
          iVar30 = (int)((fVar29 / fVar32) * 1000.0);
          VectorSignedToFloat(iVar30,(byte)(in_fpscr >> 0x16) & 3);
          local_f4[0] = 0;
          AbyssEngine::String::Set(CONCAT44((int)((ulonglong)uVar34 >> 0x20),(String *)local_f4));
          AbyssEngine::String::SubString((uint)&local_a0,(uint)local_f4);
          AbyssEngine::String::~String((String *)local_f4);
          pAVar16 = operator_new(8);
          local_104[0] = iVar30;
          AbyssEngine::String::String(aSStack_e4,".",false);
          AbyssEngine::operator+((AbyssEngine *)aAStack_dc,local_104,aSStack_e4);
          AbyssEngine::operator+(pAVar16,(AbyssEngine *)aAStack_dc,(String *)&local_a0);
          piVar28 = *(int **)(this + 4);
          piVar28[2] = *piVar28 + 1;
          pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
          piVar28[1] = (int)pvVar27;
          *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
          *piVar28 = piVar28[2];
          AbyssEngine::String::~String((String *)aAStack_dc);
          AbyssEngine::String::~String(aSStack_e4);
          AbyssEngine::String::~String((String *)&local_a0);
        }
      }
LAB_00159e80:
      uVar26 = uVar26 + 1;
    } while ((int)uVar26 < 0x3e);
    iVar30 = ::ListItem::isBluePrint(param_1);
    if (((iVar30 == 0) && (iVar30 = ::ListItem::isPendingProduct(param_1), iVar30 == 0)) &&
       (_param_6 == 1)) {
      pAVar16 = operator_new(8);
      AbyssEngine::String::String((String *)&local_a0,"\n",false);
      pSVar14 = (String *)GameText::getText(Globals::gameText,0x84);
      AbyssEngine::operator+(pAVar16,(String *)&local_a0,pSVar14);
      piVar28 = *(int **)this;
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      AbyssEngine::String::~String((String *)&local_a0);
      pAVar16 = operator_new(8);
      AbyssEngine::String::String((String *)&local_a0,"\n",false);
      Item::getSinglePrice(this_01);
      Layout::formatCredits((int)aAStack_dc);
      AbyssEngine::operator+(pAVar16,(String *)&local_a0,aAStack_dc);
      piVar28 = *(int **)(this + 4);
      piVar28[2] = *piVar28 + 1;
      pvVar27 = realloc((void *)piVar28[1],(*piVar28 + 1) * 4);
      piVar28[1] = (int)pvVar27;
      *(AbyssEngine **)((int)pvVar27 + *piVar28 * 4) = pAVar16;
      *piVar28 = piVar28[2];
      AbyssEngine::String::~String((String *)aAStack_dc);
      AbyssEngine::String::~String((String *)&local_a0);
    }
    AbyssEngine::String::String((String *)&local_a0);
    iVar30 = ::ListItem::isItem(param_1);
    if (iVar30 == 0) {
LAB_0015a5f8:
      bVar3 = false;
      AbyssEngine::String::String((String *)aAStack_dc,"",false);
    }
    else {
      Galaxy::getSystems(Globals::galaxy);
      iVar21 = *(int *)(Globals::status + 0x3c);
      iVar30 = ::ListItem::getIndex(param_1);
      if (*(int *)(*(int *)(iVar21 + 4) + iVar30 * 4) < 1) {
        AbyssEngine::String::String((String *)aAStack_dc,"",false);
        AbyssEngine::String::operator=((String *)(this + 0x74),aAStack_dc);
        AbyssEngine::String::~String((String *)aAStack_dc);
        bVar3 = false;
      }
      else {
        AbyssEngine::String::String((String *)aAStack_dc,"",false);
        iVar21 = *(int *)(Globals::status + 0x44);
        iVar30 = ::ListItem::getIndex(param_1);
        iVar21 = *(int *)(*(int *)(iVar21 + 4) + iVar30 * 4);
        pSVar17 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar30 = SolarSystem::getIndex(pSVar17);
        if (iVar21 == iVar30) {
          pSVar14 = (String *)GameText::getText(Globals::gameText,0xd7);
          AbyssEngine::String::operator=((String *)aAStack_dc,pSVar14);
        }
        else {
          ::ListItem::getIndex(param_1);
          SolarSystem::getName();
          AbyssEngine::String::operator=((String *)aAStack_dc,aSStack_e4);
          AbyssEngine::String::~String(aSStack_e4);
        }
        sVar7 = GameText::getLanguage();
        if (sVar7 == 9) {
          AbyssEngine::String::String(aSStack_114,"",false);
        }
        else {
          AbyssEngine::String::String(aSStack_114,"-> ",false);
        }
        ::ListItem::getIndex(param_1);
        Layout::formatCredits((int)aSStack_11c);
        AbyssEngine::operator+(aAStack_10c,aSStack_114,aSStack_11c);
        AbyssEngine::String::String(aSStack_124," (",false);
        AbyssEngine::operator+((AbyssEngine *)local_104,aAStack_10c,aSStack_124);
        AbyssEngine::operator+((AbyssEngine *)local_fc,(String *)local_104,aAStack_dc);
        AbyssEngine::String::String(aSStack_12c,")",false);
        AbyssEngine::operator+((AbyssEngine *)aSStack_e4,(String *)local_fc,aSStack_12c);
        AbyssEngine::String::operator=((String *)(this + 0x74),aSStack_e4);
        AbyssEngine::String::~String(aSStack_e4);
        AbyssEngine::String::~String(aSStack_12c);
        AbyssEngine::String::~String((String *)local_fc);
        AbyssEngine::String::~String((String *)local_104);
        AbyssEngine::String::~String(aSStack_124);
        AbyssEngine::String::~String((String *)aAStack_10c);
        AbyssEngine::String::~String(aSStack_11c);
        AbyssEngine::String::~String(aSStack_114);
        AbyssEngine::String::~String((String *)aAStack_dc);
        bVar3 = true;
      }
      iVar21 = *(int *)(Globals::status + 0x40);
      iVar30 = ::ListItem::getIndex(param_1);
      if (*(int *)(*(int *)(iVar21 + 4) + iVar30 * 4) < 1) {
        AbyssEngine::String::String((String *)aAStack_dc,"",false);
        AbyssEngine::String::operator=((String *)(this + 0x7c),aAStack_dc);
        AbyssEngine::String::~String((String *)aAStack_dc);
        if (!bVar3) goto LAB_0015a5f8;
      }
      else {
        AbyssEngine::String::String(aSStack_e4,"",false);
        iVar21 = *(int *)(Globals::status + 0x48);
        iVar30 = ::ListItem::getIndex(param_1);
        iVar21 = *(int *)(*(int *)(iVar21 + 4) + iVar30 * 4);
        pSVar17 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar30 = SolarSystem::getIndex(pSVar17);
        if (iVar21 == iVar30) {
          pSVar14 = (String *)GameText::getText(Globals::gameText,0xd7);
          AbyssEngine::String::operator=(aSStack_e4,pSVar14);
        }
        else {
          ::ListItem::getIndex(param_1);
          SolarSystem::getName();
          AbyssEngine::String::operator=(aSStack_e4,aAStack_dc);
          AbyssEngine::String::~String((String *)aAStack_dc);
        }
        sVar7 = GameText::getLanguage();
        if (sVar7 == 9) {
          AbyssEngine::String::String(aSStack_114,"",false);
        }
        else {
          AbyssEngine::String::String(aSStack_114,"-> ",false);
        }
        ::ListItem::getIndex(param_1);
        Layout::formatCredits((int)aSStack_11c);
        AbyssEngine::operator+(aAStack_10c,aSStack_114,aSStack_11c);
        AbyssEngine::String::String(aSStack_124," (",false);
        AbyssEngine::operator+((AbyssEngine *)local_104,aAStack_10c,aSStack_124);
        AbyssEngine::operator+((AbyssEngine *)local_fc,(String *)local_104,aSStack_e4);
        AbyssEngine::String::String(aSStack_12c,")",false);
        AbyssEngine::operator+((AbyssEngine *)aAStack_dc,(String *)local_fc,aSStack_12c);
        AbyssEngine::String::operator=((String *)(this + 0x7c),aAStack_dc);
        AbyssEngine::String::~String((String *)aAStack_dc);
        AbyssEngine::String::~String(aSStack_12c);
        AbyssEngine::String::~String((String *)local_fc);
        AbyssEngine::String::~String((String *)local_104);
        AbyssEngine::String::~String(aSStack_124);
        AbyssEngine::String::~String((String *)aAStack_10c);
        AbyssEngine::String::~String(aSStack_11c);
        AbyssEngine::String::~String(aSStack_114);
        AbyssEngine::String::~String(aSStack_e4);
      }
      AbyssEngine::String::String(aSStack_11c,"\n\n",false);
      pSVar14 = (String *)GameText::getText(Globals::gameText,0xd6);
      AbyssEngine::operator+((AbyssEngine *)aSStack_114,aSStack_11c,pSVar14);
      AbyssEngine::String::String(aSStack_124,"\n",false);
      AbyssEngine::operator+(aAStack_10c,aSStack_114,aSStack_124);
      AbyssEngine::String::String(aSStack_12c,this + 0x74,false);
      AbyssEngine::operator+((AbyssEngine *)local_104,aAStack_10c,aSStack_12c);
      AbyssEngine::String::String(aSStack_134,"\n",false);
      AbyssEngine::operator+((AbyssEngine *)local_fc,(String *)local_104,aSStack_134);
      AbyssEngine::String::String(aSStack_13c,this + 0x7c,false);
      AbyssEngine::operator+((AbyssEngine *)aAStack_dc,(String *)local_fc,aSStack_13c);
      bVar3 = true;
    }
    AbyssEngine::String::operator=((String *)&local_a0,aAStack_dc);
    AbyssEngine::String::~String((String *)aAStack_dc);
    if (bVar3) {
      AbyssEngine::String::~String(aSStack_13c);
      AbyssEngine::String::~String((String *)local_fc);
      AbyssEngine::String::~String(aSStack_134);
      AbyssEngine::String::~String((String *)local_104);
      AbyssEngine::String::~String(aSStack_12c);
      AbyssEngine::String::~String((String *)aAStack_10c);
      AbyssEngine::String::~String(aSStack_124);
      AbyssEngine::String::~String(aSStack_114);
      AbyssEngine::String::~String(aSStack_11c);
    }
    pSVar11 = *(ScrollTouchWindow **)(this + 0x18);
    AbyssEngine::String::String(aSStack_144,"",false);
    pGVar5 = Globals::gameText;
    iVar30 = ::ListItem::getIndex(param_1);
    pSVar14 = (String *)GameText::getText(pGVar5,iVar30 + 0x411);
    AbyssEngine::operator+(aAStack_14c,pSVar14,(String *)&local_a0);
    ScrollTouchWindow::setText(pSVar11,aSStack_144,aAStack_14c);
    AbyssEngine::String::~String((String *)aAStack_14c);
    AbyssEngine::String::~String(aSStack_144);
    pSVar13 = (String *)&local_a0;
  }
  AbyssEngine::String::~String(pSVar13);
LAB_0015a832:
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x124) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x128) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 300) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  this[0x130] = (ListItemWindow)0x0;
  *(undefined4 *)(this + 0x114) = 0x104;
  *(undefined4 *)(this + 0x11c) = 0;
  if (__stack_chk_guard == local_64) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ListItemWindow::shows3DShip  @0x0015b618  (6 bytes)
/* ListItemWindow::shows3DShip() */

ListItemWindow __thiscall ListItemWindow::shows3DShip(ListItemWindow *this)

{
  return this[0x54];
}

// ===== ListItemWindow::draw  @0x0015b620  (2010 bytes)
/* ListItemWindow::draw() */

void __thiscall ListItemWindow::draw(ListItemWindow *this)

{
  GameText *pGVar1;
  Layout *pLVar2;
  ImageFactory *pIVar3;
  undefined4 uVar4;
  String *pSVar5;
  int iVar6;
  int iVar7;
  ListItem *pLVar8;
  PaintCanvas *this_00;
  int iVar9;
  int iVar10;
  uint uVar11;
  ListItemWindow *pLVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  uint uVar18;
  undefined4 uVar19;
  Item *this_01;
  undefined4 uVar20;
  int iVar21;
  undefined4 uVar22;
  int iVar23;
  String aSStack_70 [8];
  String aSStack_68 [8];
  String aSStack_60 [8];
  String aSStack_58 [8];
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (Globals::iPad != '\0') {
    Layout::drawMask();
  }
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::FillRectangle
            (Globals::Canvas,*(int *)(this + 100),*(int *)(this + 0x68),*(int *)(this + 0x6c),
             *(int *)(this + 0x70));
  pLVar2 = Globals::layout;
  uVar20 = *(undefined4 *)(this + 100);
  uVar22 = *(undefined4 *)(this + 0x68);
  uVar16 = *(undefined4 *)(this + 0x6c);
  uVar19 = *(undefined4 *)(this + 0x70);
  uVar4 = AbyssEngine::String::String(aSStack_30,"",false);
  Layout::drawBox(pLVar2,2,uVar20,uVar22,uVar16,uVar19,uVar4);
  AbyssEngine::String::~String(aSStack_30);
  pLVar2 = Globals::layout;
  if (Globals::iPad != '\0') {
    uVar20 = *(undefined4 *)(this + 100);
    uVar22 = *(undefined4 *)(this + 0x68);
    uVar16 = *(undefined4 *)(this + 0x6c);
    uVar19 = *(undefined4 *)(this + 0x70);
    uVar4 = AbyssEngine::String::String(aSStack_38,"",false);
    Layout::drawBox(pLVar2,7,uVar20,uVar22,uVar16,uVar19,uVar4);
    AbyssEngine::String::~String(aSStack_38);
  }
  pLVar2 = Globals::layout;
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x186);
  AbyssEngine::String::String(aSStack_40,pSVar5,false);
  Layout::drawHeader(pLVar2,aSStack_40);
  AbyssEngine::String::~String(aSStack_40);
  iVar6 = ::ListItem::isShip(*(ListItem **)(this + 0x14));
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar7 = ::ListItem::isItem(*(ListItem **)(this + 0x14));
  if (((iVar7 == 0) && (iVar7 = ::ListItem::isBluePrint(*(ListItem **)(this + 0x14)), iVar7 == 0))
     && (iVar7 = ::ListItem::isPendingProduct(*(ListItem **)(this + 0x14)), pLVar2 = Globals::layout
        , pGVar1 = Globals::gameText, iVar7 != 1)) {
    if (iVar6 == 1) {
      iVar14 = *(int *)(this + 100);
      iVar15 = *(int *)(this + 0x68);
      iVar9 = *(int *)(Globals::layout + 0xc);
      iVar21 = *(int *)(this + 0x6c);
      iVar10 = *(int *)(Globals::layout + 0x20);
      iVar17 = *(int *)(Globals::layout + 0x28);
      iVar23 = *(int *)(Globals::layout + 0x2c);
      uVar16 = *(undefined4 *)(Globals::layout + 0x5c);
      iVar7 = Ship::getIndex(*(Ship **)(*(int *)(this + 0x14) + 0xc));
      pSVar5 = (String *)GameText::getText(pGVar1,iVar7 + 0x391);
      uVar4 = AbyssEngine::String::String(aSStack_50,pSVar5,false);
      Layout::drawBox(pLVar2,1,iVar17 + iVar14,iVar15 + iVar9 + iVar10,
                      (iVar21 >> 1) - (iVar23 + iVar17),uVar16,uVar4,2);
      AbyssEngine::String::~String(aSStack_50);
      pIVar3 = Globals::imageFactory;
      iVar7 = Ship::getIndex(*(Ship **)(*(int *)(this + 0x14) + 0xc));
      ImageFactory::drawShip
                (pIVar3,iVar7,
                 *(int *)(Globals::layout + 0x28) + *(int *)(this + 100) +
                 *(int *)(Globals::layout + 0x2c),
                 ((*(int *)(Globals::layout + 0xc) + *(int *)(this + 0x68) +
                   *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0x5c) / 2) -
                 *(int *)(Globals::layout + 0x2c8) / 2) + *(int *)(Globals::layout + 0x124));
    }
  }
  else {
    pLVar2 = Globals::layout;
    pGVar1 = Globals::gameText;
    iVar14 = *(int *)(this + 100);
    iVar15 = *(int *)(this + 0x68);
    iVar9 = *(int *)(Globals::layout + 0xc);
    iVar21 = *(int *)(this + 0x6c);
    iVar10 = *(int *)(Globals::layout + 0x20);
    iVar17 = *(int *)(Globals::layout + 0x28);
    iVar23 = *(int *)(Globals::layout + 0x2c);
    uVar16 = *(undefined4 *)(Globals::layout + 0x5c);
    iVar7 = ::ListItem::getIndex(*(ListItem **)(this + 0x14));
    pSVar5 = (String *)GameText::getText(pGVar1,iVar7 + 0x4fa);
    uVar4 = AbyssEngine::String::String(aSStack_48,pSVar5,false);
    Layout::drawBox(pLVar2,1,iVar17 + iVar14,iVar15 + iVar9 + iVar10,
                    (iVar21 >> 1) - (iVar23 + iVar17),uVar16,uVar4,2);
    AbyssEngine::String::~String(aSStack_48);
    iVar7 = ::ListItem::isItem(*(ListItem **)(this + 0x14));
    if (iVar7 == 1) {
      pLVar8 = *(ListItem **)(this + 0x14) + 0x10;
    }
    else {
      iVar9 = ::ListItem::isBluePrint(*(ListItem **)(this + 0x14));
      iVar7 = Globals::items;
      if (iVar9 == 1) {
        iVar9 = BluePrint::getIndex(*(BluePrint **)(*(int *)(this + 0x14) + 8));
      }
      else {
        iVar9 = *(int *)(*(int *)(*(int *)(this + 0x14) + 0x18) + 0x10);
      }
      pLVar8 = (ListItem *)(*(int *)(iVar7 + 4) + iVar9 * 4);
    }
    pIVar3 = Globals::imageFactory;
    this_01 = *(Item **)pLVar8;
    iVar7 = Item::getIndex(this_01);
    iVar9 = Item::getType(this_01);
    ImageFactory::drawItem
              (pIVar3,iVar7,iVar9,
               *(int *)(Globals::layout + 0x28) + *(int *)(this + 100) +
               *(int *)(Globals::layout + 0x2c),
               ((*(int *)(this + 0x68) + *(int *)(Globals::layout + 0xc) +
                 *(int *)(Globals::layout + 0x20) + *(int *)(Globals::layout + 0x5c) / 2) -
               *(int *)(Globals::layout + 0x2c8) / 2) + *(int *)(Globals::layout + 0x124));
  }
  if (*(int **)this != (int *)0x0) {
    iVar9 = *(int *)(Globals::layout + 0x2c);
    iVar7 = **(int **)this;
    iVar10 = *(int *)(Globals::layout + 0x5c) +
             *(int *)(this + 0x68) + *(int *)(Globals::layout + 0xc) +
             *(int *)(Globals::layout + 0x20) + iVar9;
    if ((uint)(Globals::h - *(int *)(Globals::layout + 0x10)) <
        (uint)((*(int *)(Globals::layout + 0x1c) + iVar9) * iVar7 + iVar10)) {
      iVar9 = 2;
    }
    if (iVar7 != 0) {
      uVar18 = 0;
      do {
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        pLVar2 = Globals::layout;
        iVar7 = *(int *)(this + 100);
        iVar14 = *(int *)(this + 0x6c);
        uVar4 = *(undefined4 *)(Globals::layout + 0x1c);
        iVar17 = *(int *)(Globals::layout + 0x28);
        iVar15 = *(int *)(Globals::layout + 0x2c);
        AbyssEngine::String::String
                  (aSStack_58,*(String **)(*(int *)(*(int *)this + 4) + uVar18 * 4),false);
        Layout::drawBox(pLVar2,6,iVar17 + iVar7,iVar10,(iVar14 >> 1) - (iVar15 + iVar17),uVar4,
                        aSStack_58);
        AbyssEngine::String::~String(aSStack_58);
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        uVar13 = Globals::font;
        this_00 = Globals::Canvas;
        if (iVar6 == 1) {
          uVar11 = **(uint **)(this + 8);
          if (uVar11 <= uVar18) goto LAB_0015ba9a;
          if (uVar18 < uVar11 - 1) {
            iVar14 = *(int *)((*(uint **)(this + 8))[1] + uVar18 * 4);
            iVar7 = *(int *)(*(int *)(*(int *)(this + 0xc) + 4) + uVar18 * 4);
            pLVar12 = this + 0x50;
            if (iVar14 < iVar7) {
              pLVar12 = this + 0x4c;
            }
            if (iVar7 < iVar14) {
              pLVar12 = this + 0x48;
            }
            AbyssEngine::PaintCanvas::DrawImage2D
                      (Globals::Canvas,*(uint *)pLVar12,
                       ((*(int *)(this + 100) + (*(int *)(this + 0x6c) >> 1)) -
                       *(int *)(Globals::layout + 0x2c)) - *(int *)(this + 0x60),iVar10);
          }
          uVar13 = Globals::font;
          this_00 = Globals::Canvas;
          iVar17 = *(int *)(this + 100);
          iVar21 = *(int *)(this + 0x60);
          iVar23 = *(int *)(this + 0x6c);
          pSVar5 = *(String **)(*(int *)(*(int *)(this + 4) + 4) + uVar18 * 4);
          iVar14 = *(int *)(Globals::layout + 0x2c);
          iVar7 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,pSVar5);
          iVar15 = (iVar10 + *(int *)(Globals::layout + 0x1c) / 2) - *(int *)(this + 0x1c);
          iVar7 = (((iVar17 + (iVar23 >> 1) + 10) - iVar14) - iVar21) - iVar7;
        }
        else {
LAB_0015ba9a:
          iVar17 = *(int *)(this + 100);
          iVar21 = *(int *)(this + 0x6c);
          pSVar5 = *(String **)(*(int *)(*(int *)(this + 4) + 4) + uVar18 * 4);
          iVar14 = *(int *)(Globals::layout + 0x2c);
          iVar7 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,pSVar5);
          iVar15 = (iVar10 + *(int *)(Globals::layout + 0x1c) / 2) - *(int *)(this + 0x1c);
          iVar7 = (iVar17 + (iVar21 >> 1) + iVar14 * -2) - iVar7;
        }
        AbyssEngine::PaintCanvas::DrawString(this_00,uVar13,pSVar5,iVar7,iVar15,false);
        uVar18 = uVar18 + 1;
        iVar10 = iVar9 + iVar10 + *(int *)(Globals::layout + 0x1c);
      } while (uVar18 < **(uint **)this);
    }
  }
  pLVar2 = Globals::layout;
  if (*(int *)(this + 0x20) < 1) {
    iVar6 = *(int *)(this + 100);
    iVar7 = *(int *)(this + 0x68);
    iVar9 = *(int *)(this + 0x6c);
    iVar15 = *(int *)(Globals::layout + 0xc);
    iVar17 = *(int *)(Globals::layout + 0x20);
    iVar14 = *(int *)(Globals::layout + 0x28);
    iVar10 = *(int *)(Globals::layout + 0x2c);
    uVar16 = *(undefined4 *)(Globals::layout + 0x5c);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x118);
    uVar4 = AbyssEngine::String::String(aSStack_70,pSVar5,false);
    Layout::drawBox(pLVar2,1,iVar6 + (iVar9 >> 1) + iVar10,iVar7 + iVar15 + iVar17,
                    ((iVar9 >> 1) - iVar10) - iVar14,uVar16,uVar4);
    AbyssEngine::String::~String(aSStack_70);
  }
  else {
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    pLVar2 = Globals::layout;
    uVar16 = *(undefined4 *)(this + 0x20);
    iVar6 = *(int *)(this + 100);
    iVar7 = *(int *)(this + 0x68);
    iVar9 = *(int *)(Globals::layout + 0x20);
    iVar10 = *(int *)(this + 0x6c);
    iVar17 = *(int *)(Globals::layout + 0xc);
    iVar14 = *(int *)(Globals::layout + 0x28);
    iVar15 = *(int *)(Globals::layout + 0x2c);
    uVar4 = AbyssEngine::String::String(aSStack_60,"",false);
    Layout::drawBox(pLVar2,8,iVar6 + (iVar10 >> 1) + iVar15,iVar7 + iVar17 + iVar9,
                    ((iVar10 >> 1) - iVar15) - iVar14,uVar16,uVar4);
    AbyssEngine::String::~String(aSStack_60);
    pLVar2 = Globals::layout;
    iVar15 = *(int *)(this + 0x20);
    iVar6 = *(int *)(this + 100);
    iVar7 = *(int *)(this + 0x68);
    iVar9 = *(int *)(Globals::layout + 0xc);
    iVar21 = *(int *)(this + 0x6c);
    iVar10 = *(int *)(Globals::layout + 0x20);
    uVar16 = *(undefined4 *)(Globals::layout + 0x1c);
    iVar17 = *(int *)(Globals::layout + 0x28);
    iVar14 = *(int *)(Globals::layout + 0x2c);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x118);
    uVar4 = AbyssEngine::String::String(aSStack_68,pSVar5,false);
    iVar10 = iVar7 + iVar9 + iVar10;
    if (0 < iVar15) {
      iVar10 = iVar10 + iVar15 + iVar14;
    }
    Layout::drawBox(pLVar2,0,iVar6 + (iVar21 >> 1) + iVar14,iVar10,((iVar21 >> 1) - iVar14) - iVar17
                    ,uVar16,uVar4);
    AbyssEngine::String::~String(aSStack_68);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x44),*(int *)(this + 0x24) - *(int *)(this + 0x2c),
               *(int *)(this + 0x28) - *(int *)(this + 0x30) / 3);
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x44),*(int *)(this + 0x24),
               *(int *)(this + 0x28) - *(int *)(this + 0x30) / 3,'\x01');
  }
  ScrollTouchWindow::drawTextBG(*(ScrollTouchWindow **)(this + 0x18));
  ScrollTouchWindow::draw(*(ScrollTouchWindow **)(this + 0x18));
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ListItemWindow::update  @0x0015bee8  (340 bytes)
/* ListItemWindow::update(int) */

void ListItemWindow::update(int param_1)

{
  uint uVar1;
  byte bVar2;
  Matrix *pMVar3;
  uint in_fpscr;
  float fVar4;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float fVar5;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float fVar6;
  AEMath aAStack_60 [60];
  int local_24;
  
  local_24 = __stack_chk_guard;
  ScrollTouchWindow::update(*(int *)(param_1 + 0x18));
  if (*(char *)(param_1 + 0x54) != '\0') {
    if (*(char *)(param_1 + 0x130) == '\0') {
      fVar4 = *(float *)(param_1 + 0x124) * *(float *)(param_1 + 0x128);
      fVar5 = -(*(float *)(param_1 + 0x124) * *(float *)(param_1 + 0x128));
      if (0.0 < fVar4) {
        fVar5 = fVar4;
      }
      *(float *)(param_1 + 0x128) = fVar4;
      uVar1 = in_fpscr & 0xfffffff | (uint)(fVar5 < 1.0) << 0x1f | (uint)(fVar5 == 1.0) << 0x1e;
      in_fpscr = uVar1 | (uint)NAN(fVar5) << 0x1c;
      bVar2 = (byte)(uVar1 >> 0x18);
      if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x114),
                                           (byte)(in_fpscr >> 0x16) & 3);
        *(int *)(param_1 + 0x114) = (int)(fVar4 + fVar5);
      }
    }
    Ship::getIndex(*(Ship **)(*(int *)(param_1 + 0x14) + 0xc));
    fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x114),(byte)(in_fpscr >> 0x16) & 3
                                      );
    *(float *)(param_1 + 0x110) = fVar5 / 120.0;
    AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(param_1 + 0x84));
    AbyssEngine::AEMath::MatrixSetRotation(aAStack_60,extraout_s0,extraout_s1,extraout_s2);
    pMVar3 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(param_1 + 0x84));
    AbyssEngine::AEMath::MatrixSetScaling
              (aAStack_60,pMVar3,extraout_s0_00,extraout_s1_00,extraout_s2_00);
    fVar5 = extraout_s0_01;
    fVar4 = extraout_s1_01;
    fVar6 = extraout_s2_01;
    if (*(uint *)(param_1 + 0x88) != 0xffffffff) {
      AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(param_1 + 0x88));
      AbyssEngine::AEMath::MatrixSetRotation
                (aAStack_60,extraout_s0_02,extraout_s1_02,extraout_s2_02);
      pMVar3 = (Matrix *)
               AbyssEngine::PaintCanvas::TransformGetLocal
                         (Globals::Canvas,*(uint *)(param_1 + 0x88));
      AbyssEngine::AEMath::MatrixSetScaling
                (aAStack_60,pMVar3,extraout_s0_03,extraout_s1_03,extraout_s2_03);
      fVar5 = extraout_s0_04;
      fVar4 = extraout_s1_04;
      fVar6 = extraout_s2_04;
    }
    AEGeometry::setRotation(*(AEGeometry **)(param_1 + 0x10),fVar5,fVar4,fVar6);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ListItemWindow::render  @0x0015c054  (162 bytes)
/* ListItemWindow::render() */

void __thiscall ListItemWindow::render(ListItemWindow *this)

{
  Matrix *pMVar1;
  int iVar2;
  
  if (this[0x54] == (ListItemWindow)0x0) {
    return;
  }
  AbyssEngine::PaintCanvas::Begin3d(Globals::Canvas);
  iVar2 = *(int *)(Globals::layout + 0x128);
  AbyssEngine::PaintCanvas::EnableClip
            (Globals::Canvas,
             *(int *)(this + 100) + iVar2 + (*(int *)(this + 0x6c) >> 1) +
             *(int *)(Globals::layout + 0x2c),
             *(int *)(this + 0x68) + iVar2 + *(int *)(Globals::layout + 0xc) +
             *(int *)(Globals::layout + 0x20),
             ((*(int *)(this + 0x6c) >> 1) - (*(int *)(Globals::layout + 0x2c) + iVar2 * 2)) -
             *(int *)(Globals::layout + 0x28),*(int *)(this + 0x20) + iVar2 * -2);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::CameraGetLocal(Globals::Canvas,*(uint *)(this + 0x8c));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x90),pMVar1);
  AEGeometry::render(*(AEGeometry **)(this + 0x10));
  AbyssEngine::PaintCanvas::End3d(Globals::Canvas);
  AbyssEngine::PaintCanvas::DisableClip();
  return;
}

// ===== ListItemWindow::OnTouchBegin  @0x0015c100  (86 bytes)
/* ListItemWindow::OnTouchBegin(int, int) */

void __thiscall ListItemWindow::OnTouchBegin(ListItemWindow *this,int param_1,int param_2)

{
  ScrollTouchWindow::OnTouchBegin(*(int *)(this + 0x18),param_1);
  if (((this[0x54] != (ListItemWindow)0x0) &&
      (*(int *)(this + 100) + (*(int *)(this + 0x6c) >> 1) < param_1)) &&
     (param_2 < *(int *)(Globals::layout + 0x20) +
                *(int *)(this + 0x68) + *(int *)(Globals::layout + 0xc) + *(int *)(this + 0x20))) {
    *(int *)(this + 0x118) = param_1;
    *(int *)(this + 300) = param_1;
    *(undefined4 *)(this + 0x120) = 0;
    this[0x130] = (ListItemWindow)0x1;
  }
  return;
}

// ===== ListItemWindow::OnTouchMove  @0x0015c15c  (60 bytes)
/* ListItemWindow::OnTouchMove(int, int) */

void __thiscall ListItemWindow::OnTouchMove(ListItemWindow *this,int param_1,int param_2)

{
  int iVar1;
  
  ScrollTouchWindow::OnTouchMove(*(ScrollTouchWindow **)(this + 0x18),param_1,param_2);
  if ((this[0x54] != (ListItemWindow)0x0) && (this[0x130] != (ListItemWindow)0x0)) {
    iVar1 = *(int *)(this + 0x118);
    *(int *)(this + 0x120) = param_1 - iVar1;
    *(int *)(this + 0x118) = param_1;
    *(undefined4 *)(this + 0x124) = 0x3f800000;
    *(int *)(this + 0x114) = (param_1 - iVar1) + *(int *)(this + 0x114);
  }
  return;
}

// ===== ListItemWindow::OnTouchEnd  @0x0015c198  (94 bytes)
/* ListItemWindow::OnTouchEnd(int, int) */

void ListItemWindow::OnTouchEnd(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  undefined4 uVar3;
  undefined4 uVar4;
  
  ScrollTouchWindow::OnTouchEnd(*(int *)(param_1 + 0x18),param_2);
  if ((*(char *)(param_1 + 0x54) != '\0') && (*(char *)(param_1 + 0x130) != '\0')) {
    iVar1 = *(int *)(param_1 + 0x120);
    uVar4 = VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    iVar2 = iVar1;
    if (iVar1 < 0) {
      iVar2 = -iVar1;
    }
    uVar3 = 0;
    if (3 < iVar2) {
      uVar3 = uVar4;
    }
    *(undefined4 *)(param_1 + 0x128) = uVar3;
    *(undefined4 *)(param_1 + 0x124) = 0x3f666666;
    *(undefined1 *)(param_1 + 0x130) = 0;
    iVar1 = iVar1 + *(int *)(param_1 + 0x114);
    *(int *)(param_1 + 0x114) = iVar1;
    *(int *)(param_1 + 0x11c) = iVar1;
  }
  return;
}

