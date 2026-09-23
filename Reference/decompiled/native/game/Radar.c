// Class: Radar
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Radar::Radar  @0x001545e0  (2816 bytes)
/* Radar::Radar(Level*) */

void __thiscall Radar::Radar(Radar *this,Level *param_1)

{
  undefined4 uVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  AbyssEngine *this_00;
  String *pSVar5;
  Station *this_01;
  ushort *puVar6;
  uint *puVar7;
  PlayerEgo *pPVar8;
  Sprite *pSVar9;
  Ship *pSVar10;
  Item *pIVar11;
  Item *this_02;
  void *pvVar12;
  undefined4 *puVar13;
  int iVar14;
  String *pSVar15;
  uint uVar16;
  BombGun *this_03;
  MineGun *this_04;
  uint in_fpscr;
  float fVar17;
  float fVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  String aSStack_54 [8];
  uint local_4c [2];
  String aSStack_44 [8];
  uint local_3c [2];
  int local_34;
  
  uVar1 = 0;
  uVar19 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar20 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar21 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_34 = __stack_chk_guard;
  *(undefined4 *)(this + 0x174) = 0;
  *(undefined4 *)(this + 0x178) = uVar19;
  *(undefined4 *)(this + 0x17c) = uVar20;
  *(undefined4 *)(this + 0x180) = uVar21;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x168) = uVar19;
  *(undefined4 *)(this + 0x16c) = uVar20;
  *(undefined4 *)(this + 0x170) = uVar21;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = uVar19;
  *(undefined4 *)(this + 0x15c) = uVar20;
  *(undefined4 *)(this + 0x160) = uVar21;
  AbyssEngine::String::String((String *)(this + 0x18c));
  *(undefined4 *)(this + 0x1cc) = 0x3f800000;
  *(undefined4 *)(this + 0x1d0) = uVar1;
  *(undefined4 *)(this + 0x1d4) = uVar19;
  *(undefined4 *)(this + 0x1d8) = uVar20;
  *(undefined4 *)(this + 0x1dc) = uVar21;
  *(undefined4 *)(this + 0x1e0) = 0x3f800000;
  *(undefined4 *)(this + 0x1e4) = uVar1;
  *(undefined4 *)(this + 0x1e8) = uVar19;
  *(undefined4 *)(this + 0x1ec) = uVar20;
  *(undefined4 *)(this + 0x1f0) = uVar21;
  *(undefined8 *)(this + 500) = 0x3f800000;
  *(undefined8 *)(this + 0x1fc) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x204) = 0x3f800000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = uVar1;
  *(undefined4 *)(this + 0x2c) = uVar19;
  *(undefined4 *)(this + 0x30) = uVar20;
  *(undefined4 *)(this + 0x34) = uVar21;
  *(undefined4 *)(this + 0x1c) = uVar1;
  *(undefined4 *)(this + 0x20) = uVar19;
  *(undefined4 *)(this + 0x24) = uVar20;
  *(undefined4 *)(this + 0x28) = uVar21;
  this[0x48] = (Radar)0x1;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x188) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x208) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  this[0x130] = (Radar)0x0;
  this[0x54] = (Radar)0x0;
  this[0x120] = (Radar)0x0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x144) = uVar1;
  *(undefined4 *)(this + 0x148) = uVar19;
  *(undefined4 *)(this + 0x14c) = uVar20;
  *(undefined4 *)(this + 0x150) = uVar21;
  *(undefined4 *)(this + 0x134) = uVar1;
  *(undefined4 *)(this + 0x138) = uVar19;
  *(undefined4 *)(this + 0x13c) = uVar20;
  *(undefined4 *)(this + 0x140) = uVar21;
  *(undefined4 *)(this + 0x194) = uVar1;
  *(undefined4 *)(this + 0x198) = uVar19;
  *(undefined4 *)(this + 0x19c) = uVar20;
  *(undefined4 *)(this + 0x1a0) = uVar21;
  this[0x1a4] = (Radar)0x0;
  *(Level **)this = param_1;
  iVar2 = Globals::layout;
  iVar14 = *(int *)(Globals::layout + 0xac);
  *(int *)(this + 0x218) = iVar14;
  *(int *)(this + 0x21c) = iVar14 >> 1;
  iVar14 = *(int *)(iVar2 + 0xa8);
  *(int *)(this + 0x220) = iVar14;
  *(int *)(this + 0x224) = iVar14 >> 1;
  *(undefined4 *)(this + 0x228) = *(undefined4 *)(iVar2 + 0xa0);
  *(undefined4 *)(this + 0x22c) = *(undefined4 *)(iVar2 + 0xa4);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c7,(uint *)(this + 0x1c0));
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x1c0));
  *(undefined4 *)(this + 0x4c) = uVar1;
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x1c0));
  *(int *)(this + 0x50) = iVar2;
  *(int *)(this + 0x104) = Globals::w / 2;
  *(int *)(this + 0x108) = Globals::h / 2;
  iVar14 = *(int *)(this + 0x4c) * *(int *)(this + 0x4c);
  fVar17 = (float)VectorSignedToFloat(iVar14,(byte)(in_fpscr >> 0x16) & 3);
  fVar18 = (float)VectorSignedToFloat(iVar2 * iVar2,(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x114) = iVar14;
  *(float *)(this + 0x10c) = 1.0 / fVar17;
  *(int *)(this + 0x118) = iVar2 * iVar2;
  *(float *)(this + 0x110) = 1.0 / fVar18;
  pAVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar4;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar4 = 0;
  *(undefined4 *)pAVar3 = 0;
  *(Array **)(this + 0x188) = pAVar3;
  ArraySetLength<AbyssEngine::String*>(4,pAVar3);
  this_00 = operator_new(8);
  iVar2 = Status::inAlienOrbit(Globals::status);
  if (iVar2 != 1) {
    Status::getStation(Globals::status);
    Station::getName();
    AbyssEngine::String::String((String *)local_3c,aSStack_44,false);
  }
  else {
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x19f);
    AbyssEngine::String::String((String *)local_3c,pSVar5,false);
  }
  this_01 = (Station *)Status::getStation(Globals::status);
  iVar14 = Station::getIndex(this_01);
  if (iVar14 != 0x65) {
    AbyssEngine::String::String(aSStack_54," ",false);
    pSVar5 = (String *)GameText::getText(Globals::gameText,0x88);
    AbyssEngine::operator+((AbyssEngine *)local_4c,aSStack_54,pSVar5);
  }
  else {
    AbyssEngine::String::String((String *)local_4c,"",false);
  }
  AbyssEngine::operator+(this_00,(String *)local_3c,(String *)local_4c);
  **(undefined4 **)(*(int *)(this + 0x188) + 4) = this_00;
  AbyssEngine::String::~String((String *)local_4c);
  if (iVar14 != 0x65) {
    AbyssEngine::String::~String(aSStack_54);
  }
  AbyssEngine::String::~String((String *)local_3c);
  if (iVar2 != 1) {
    AbyssEngine::String::~String(aSStack_44);
  }
  iVar2 = Status::inAlienOrbit(Globals::status);
  if (((iVar2 == 1) && (iVar2 = Status::dlc1Won(Globals::status), iVar2 == 1)) &&
     (iVar2 = Status::inEmptyOrbit(Globals::status), iVar2 == 0)) {
    pSVar15 = (String *)**(undefined4 **)(*(int *)(this + 0x188) + 4);
    iVar2 = Level::getLandmarks(param_1);
    puVar6 = AbyssEngine::String::operator_cast_to_unsigned_short_
                       ((String *)(**(int **)(iVar2 + 4) + 0x18));
    AbyssEngine::String::Set(pSVar15,puVar6);
  }
  pSVar15 = operator_new(8);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x223);
  AbyssEngine::String::String(pSVar15,pSVar5,false);
  *(String **)(*(int *)(*(int *)(this + 0x188) + 4) + 4) = pSVar15;
  pSVar15 = operator_new(8);
  AbyssEngine::String::String(pSVar15,"",false);
  *(String **)(*(int *)(*(int *)(this + 0x188) + 4) + 8) = pSVar15;
  pSVar15 = operator_new(8);
  pSVar5 = (String *)GameText::getText(Globals::gameText,0x221);
  AbyssEngine::String::String(pSVar15,pSVar5,false);
  *(String **)(*(int *)(*(int *)(this + 0x188) + 4) + 0xc) = pSVar15;
  puVar7 = (uint *)Level::getPlayerGuns(param_1);
  if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
    uVar16 = 0;
    do {
      iVar2 = (**(code **)(**(int **)(puVar7[1] + uVar16 * 4) + 0x20))();
      if (iVar2 == 1) {
        RocketGun::setRadar(*(Radar **)(puVar7[1] + uVar16 * 4));
      }
      iVar2 = (**(code **)(**(int **)(puVar7[1] + uVar16 * 4) + 0x24))();
      if (iVar2 == 1) {
        this_03 = *(BombGun **)(puVar7[1] + uVar16 * 4);
        pPVar8 = (PlayerEgo *)Level::getPlayer(param_1);
        BombGun::setPlayer(this_03,pPVar8);
      }
      iVar2 = (**(code **)(**(int **)(puVar7[1] + uVar16 * 4) + 0x28))();
      if (iVar2 == 1) {
        this_04 = *(MineGun **)(puVar7[1] + uVar16 * 4);
        pPVar8 = (PlayerEgo *)Level::getPlayer(param_1);
        MineGun::setPlayer(this_04,pPVar8);
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 < *puVar7);
  }
  puVar7 = (uint *)Level::getEnemyGuns(param_1);
  if ((puVar7 != (uint *)0x0) && (*puVar7 != 0)) {
    uVar16 = 0;
    do {
      iVar2 = (**(code **)(**(int **)(puVar7[1] + uVar16 * 4) + 0x20))();
      if (iVar2 == 1) {
        RocketGun::setRadar(*(Radar **)(puVar7[1] + uVar16 * 4));
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 < *puVar7);
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d4,(uint *)(this + 0xd4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d9,(uint *)(this + 0xd0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d6,(uint *)(this + 0xd8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d7,(uint *)(this + 0xdc));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d3,(uint *)(this + 0xe4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4da,(uint *)(this + 0xe0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d5,(uint *)(this + 0xe8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d8,(uint *)(this + 0xec));
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0xd4));
  *(undefined4 *)(this + 0x1c4) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0xd4));
  *(undefined4 *)(this + 0x1c8) = uVar1;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x454,(uint *)(this + 200));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x455,(uint *)(this + 0xc4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4dc,(uint *)(this + 0x74));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4cb,(uint *)(this + 0x78));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c9,(uint *)(this + 0x98));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4db,(uint *)(this + 0x5c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4cc,(uint *)(this + 0x60));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c8,(uint *)(this + 0x90));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4d2,(uint *)(this + 100));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4cd,(uint *)(this + 0x68));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ca,(uint *)(this + 0x94));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f0,(uint *)(this + 0x6c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ef,(uint *)(this + 0x70));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f2,(uint *)(this + 0x88));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f1,(uint *)(this + 0x8c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c8,(uint *)(this + 0x7c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ca,(uint *)(this + 0x80));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c9,(uint *)(this + 0x84));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f2,(uint *)(this + 0x9c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f1,(uint *)(this + 0xa4));
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(this + 0xa4);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x451,(uint *)(this + 0xa8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x44f,(uint *)(this + 0xb0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x44c,(uint *)(this + 0xac));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x44d,(uint *)(this + 0xb4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x450,(uint *)(this + 0xb8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x453,(uint *)(this + 0xbc));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f62,(uint *)(this + 0xc0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c4,(uint *)(this + 0xcc));
  iVar2 = Globals::w;
  iVar14 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0xcc));
  *(int *)(this + 0x20c) = iVar2 / 2 - iVar14 / 2;
  *(undefined4 *)(this + 0x210) = *(undefined4 *)(Globals::layout + 0xb0);
  puVar7 = operator_new__(0x28);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4a1,puVar7);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x49c,puVar7 + 1);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x49e,puVar7 + 3);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x49f,puVar7 + 2);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4a0,puVar7 + 8);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x49d,puVar7 + 9);
  pSVar9 = operator_new(0x40);
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*puVar7);
  iVar14 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*puVar7);
  Sprite::Sprite(pSVar9,puVar7,10,iVar2,iVar14);
  *(Sprite **)(this + 0xf0) = pSVar9;
  local_3c[0] = 0;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x456,local_3c);
  iVar2 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,local_3c[0]);
  pSVar9 = operator_new(0x40);
  Sprite::Sprite(pSVar9,local_3c[0],iVar2,iVar2);
  *(Sprite **)(this + 0xf4) = pSVar9;
  Sprite::defineReferencePixel(pSVar9,iVar2 / 2,iVar2 / 2);
  local_4c[0] = 0;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x44e,local_4c);
  pSVar9 = operator_new(0x40);
  Sprite::Sprite(pSVar9,local_4c[0],*(int *)(Globals::layout + 0xb8),
                 *(int *)(Globals::layout + 0xb4));
  *(Sprite **)(this + 0xf8) = pSVar9;
  pSVar10 = (Ship *)Status::getShip(Globals::status);
  iVar2 = Ship::getFirstEquipmentOfSort(pSVar10,0x13);
  pSVar10 = (Ship *)Status::getShip(Globals::status);
  pIVar11 = (Item *)Ship::getFirstEquipmentOfSort(pSVar10,0x11);
  pSVar10 = (Ship *)Status::getShip(Globals::status);
  this_02 = (Item *)Ship::getFirstEquipmentOfSort(pSVar10,0xd);
  this[0x1a8] = (Radar)(iVar2 != 0);
  if (pIVar11 == (Item *)0x0) {
    this[0x1a7] = (Radar)0x0;
    *(undefined2 *)(this + 0x1a5) = 0;
    uVar1 = 8000;
  }
  else {
    this[0x1a7] = (Radar)0x1;
    iVar2 = Item::getAttribute(pIVar11,0x1f);
    this[0x1a5] = (Radar)(iVar2 == 1);
    iVar2 = Item::getAttribute(pIVar11,0x1e);
    this[0x1a6] = (Radar)(iVar2 == 1);
    uVar1 = Item::getAttribute(pIVar11,0x1d);
  }
  *(undefined4 *)(this + 0x1b4) = uVar1;
  if (this_02 == (Item *)0x0) {
    this[0x1a9] = (Radar)0x0;
    *(undefined4 *)(this + 0x1b0) = 0;
    *(undefined2 *)(this + 0x1aa) = 0;
  }
  else {
    this[0x1a9] = (Radar)0x1;
    iVar2 = Item::getAttribute(this_02,0x17);
    this[0x1aa] = (Radar)(iVar2 == 1);
    uVar1 = Item::getAttribute(this_02,0x18);
    *(undefined4 *)(this + 0x1b0) = uVar1;
    iVar2 = Item::getAttribute(this_02,0x17);
    this[0x1ab] = (Radar)(iVar2 == 2);
  }
  this[0x1ac] = (Radar)0x1;
  *(undefined4 *)(this + 0x1b8) = 0;
  this[0x48] = (Radar)0x1;
  pvVar12 = operator_new__(0x14);
  *(void **)(this + 0x58) = pvVar12;
  __aeabi_memset4(pvVar12,0x14,0xff);
  iVar2 = Globals::w / 6;
  iVar14 = Globals::w + ((uint)(Globals::w >> 0x1f) >> 0x1d);
  *(int *)(this + 0x124) = (int)(Globals::w + ((uint)(Globals::w >> 0x1f) >> 0x1c)) >> 4;
  *(int *)(this + 0x128) = iVar2;
  *(int *)(this + 300) = iVar14 >> 3;
  pSVar10 = (Ship *)Status::getShip(Globals::status);
  pIVar11 = (Item *)Ship::getFirstEquipmentOfSort(pSVar10,0x23);
  if ((pIVar11 != (Item *)0x0) && (iVar2 = Item::getAttribute(pIVar11,0x32), iVar2 != 0)) {
    pSVar10 = (Ship *)Status::getShip(Globals::status);
    pIVar11 = (Item *)Ship::getFirstEquipmentOfSort(pSVar10,0x23);
    uVar1 = Item::getAttribute(pIVar11,0x32);
    fVar17 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    fVar18 = (float)VectorSignedToFloat(*(undefined4 *)(this + 300),(byte)(in_fpscr >> 0x16) & 3);
    *(int *)(this + 300) = (int)((fVar17 / 100.0) * fVar18);
  }
  pSVar10 = (Ship *)Status::getShip(Globals::status);
  pIVar11 = (Item *)Ship::getFirstEquipmentOfSort(pSVar10,0x25);
  if (pIVar11 != (Item *)0x0) {
    puVar4 = operator_new(0xc);
    puVar13 = operator_new__(4);
    puVar4[1] = puVar13;
    puVar4[2] = 1;
    *puVar13 = 0;
    *puVar4 = 0;
    *(undefined4 **)(this + 0x34) = puVar4;
    uVar16 = Item::getAttribute(pIVar11,0x37);
    ArraySetLength<KIPlayer*>(uVar16,*(Array **)(this + 0x34));
  }
  if (__stack_chk_guard - local_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_34);
  }
  return;
}

// ===== Radar::~Radar  @0x001552d0  (40 bytes)
/* Radar::~Radar() */

Radar * __thiscall Radar::~Radar(Radar *this)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(this + 0x34);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x34) = 0;
  AbyssEngine::String::~String((String *)(this + 0x18c));
  return this;
}

// ===== Radar::update  @0x001552f8  (216 bytes)
/* Radar::update(AbyssEngine::AEMath::Vector) */

void Radar::update(int param_1,float param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  AEMath aAStack_34 [12];
  float local_28;
  float local_24;
  undefined4 uStack_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_28 = param_2;
  local_24 = param_3;
  uStack_20 = param_4;
  AbyssEngine::AEMath::MatrixTransformVector
            (aAStack_34,(Matrix *)(param_1 + 0x1cc),(Vector *)&local_28);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x154),(Vector *)aAStack_34);
  *(float *)(param_1 + 0x158) = -*(float *)(param_1 + 0x158);
  *(float *)(param_1 + 0x15c) = -*(float *)(param_1 + 0x15c);
  iVar1 = AbyssEngine::PaintCanvas::GetScreenPosition
                    (Globals::Canvas,(Vector *)&local_28,(Vector *)&local_28);
  *(char *)(param_1 + 0x11c) = (char)iVar1;
  *(int *)(param_1 + 0xfc) = (int)local_28;
  *(int *)(param_1 + 0x100) = (int)local_24;
  if (iVar1 == 0) {
    elipsoidIntersect((Vector *)aAStack_34,param_1,(int)local_28,(int)local_24,
                      *(undefined4 *)(param_1 + 0x154),*(undefined4 *)(param_1 + 0x158),
                      *(undefined4 *)(param_1 + 0x15c));
    AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x154),(Vector *)aAStack_34);
    *(int *)(param_1 + 0xfc) = (int)*(float *)(param_1 + 0x154);
    *(int *)(param_1 + 0x100) = (int)*(float *)(param_1 + 0x158);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Radar::elipsoidIntersect  @0x001553dc  (214 bytes)
/* Radar::elipsoidIntersect(int, int, AbyssEngine::AEMath::Vector) */

void Radar::elipsoidIntersect
               (undefined4 *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  byte bVar2;
  uint in_fpscr;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar6 = (float)VectorSignedToFloat(*(int *)(param_2 + 0x108) - param_4,
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar7 = (float)VectorSignedToFloat(*(int *)(param_2 + 0x104) - param_3,
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar4 = *(float *)(param_2 + 0x110) * fVar6 * fVar6;
  fVar8 = *(float *)(param_2 + 0x10c) * fVar7 * fVar7 + fVar4;
  uVar1 = in_fpscr & 0xfffffff | (uint)(fVar8 < 0.0) << 0x1f;
  uVar3 = uVar1 | (uint)NAN(fVar8) << 0x1c;
  if ((byte)(uVar1 >> 0x1f) == ((byte)(uVar3 >> 0x1c) & 1)) {
    fVar4 = (float)Globals::sqrt(fVar4);
    fVar8 = (fVar8 - fVar4) / fVar8;
    if ((!NAN(fVar8)) &&
       (uVar1 = uVar3 & 0xfffffff | (uint)(fVar8 == 1.0) << 0x1e | (uint)(1.0 <= fVar8) << 0x1d,
       bVar2 = (byte)(uVar1 >> 0x18), !(bool)(bVar2 >> 5 & 1) || (bool)(bVar2 >> 6))) {
      fVar4 = (float)VectorSignedToFloat(param_4,(byte)(uVar1 >> 0x16) & 3);
      fVar5 = (float)VectorSignedToFloat(param_3,(byte)(uVar1 >> 0x16) & 3);
      param_6 = VectorSignedToFloat((int)(fVar4 + fVar6 * fVar8),(byte)(uVar1 >> 0x16) & 3);
      param_5 = VectorSignedToFloat((int)(fVar5 + fVar7 * fVar8),(byte)(uVar1 >> 0x16) & 3);
    }
  }
  *param_1 = param_5;
  param_1[1] = param_6;
  param_1[2] = param_7;
  return;
}

// ===== Radar::update  @0x001554b8  (58 bytes)
/* Radar::update(KIPlayer*) */

void __thiscall Radar::update(Radar *this,KIPlayer *param_1)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  (**(code **)(*(int *)param_1 + 0x28))(&local_20);
  update(this,local_20,uStack_1c,uStack_18);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Radar::draw  @0x001554fc  (11040 bytes)
/* Radar::draw(Player*, Hud*, int) */

void __thiscall Radar::draw(Radar *this,Player *param_1,Hud *param_2,int param_3)

{
  ushort uVar1;
  Radar **ppRVar2;
  FModSound *this_00;
  byte bVar3;
  Radar RVar4;
  KIPlayer KVar5;
  Mission *pMVar6;
  int iVar7;
  PlayerEgo *pPVar8;
  undefined4 *puVar9;
  float *pfVar10;
  undefined4 uVar11;
  StarSystem *pSVar12;
  Matrix *pMVar13;
  SolarSystem *this_01;
  int *piVar14;
  Station *pSVar15;
  SolarSystem *pSVar16;
  uint *puVar17;
  uint uVar18;
  Mission *this_02;
  int iVar19;
  Agent *this_03;
  Player *this_04;
  Radar *pRVar20;
  String *pSVar21;
  Ship *pSVar22;
  Item *pIVar23;
  uint uVar24;
  Radar *pRVar25;
  Radar *pRVar26;
  Radar *pRVar27;
  Radar *pRVar28;
  Radar *pRVar29;
  Radar *pRVar30;
  Radar *pRVar31;
  Radar *pRVar32;
  Radar *pRVar33;
  KIPlayer *pKVar34;
  Matrix *this_05;
  Radar *pRVar35;
  Sprite *pSVar36;
  Level *this_06;
  uint uVar37;
  PaintCanvas *pPVar38;
  int iVar39;
  Vector *this_07;
  int iVar40;
  undefined1 *puVar41;
  PlayerGasCloud *this_08;
  Vector *this_09;
  KIPlayer *pKVar42;
  bool bVar43;
  uint in_fpscr;
  float fVar44;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
  float extraout_s0_07;
  float extraout_s0_08;
  float extraout_s0_09;
  float extraout_s0_10;
  float extraout_s0_11;
  float extraout_s0_12;
  float extraout_s0_13;
  float extraout_s0_14;
  float extraout_s0_15;
  float extraout_s0_16;
  float extraout_s0_17;
  float extraout_s0_18;
  float extraout_s0_19;
  float extraout_s0_20;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  undefined8 uVar45;
  float extraout_s1_04;
  float fVar46;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s3_01;
  float extraout_s3_02;
  float extraout_s3_03;
  float extraout_s3_04;
  float extraout_s5;
  float extraout_s5_00;
  float extraout_s5_01;
  float extraout_s5_02;
  float extraout_s5_03;
  float extraout_s5_04;
  float fVar47;
  Radar *local_148;
  Radar *local_144;
  Radar *local_140;
  uint *local_13c;
  uint *local_138;
  Radar *local_134;
  float *local_130;
  float *local_12c;
  Radar *local_128;
  Radar *local_124;
  Radar *local_120;
  Radar *local_11c;
  Radar *local_118;
  Hud *local_114;
  Radar *local_110;
  int local_10c;
  Radar *local_108;
  Radar *local_104;
  Radar *local_100;
  Radar *local_fc;
  Radar *local_f8;
  Radar *local_f4;
  float *local_f0;
  undefined4 *local_ec;
  undefined4 *local_e8;
  Player *local_e4;
  uint local_e0;
  Radar *local_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  String aSStack_cc [12];
  AbyssEngine aAStack_c0 [12];
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8 [2];
  String aSStack_a0 [8];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  local_e4 = param_1;
  if (this[0x48] == (Radar)0x0) goto LAB_00157d4a;
  uVar37 = 0;
  this[0x130] = (Radar)0x0;
  this[0x214] = (Radar)0x0;
  local_114 = param_2;
  local_10c = param_3;
  local_dc = this;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  pMVar6 = (Mission *)Status::getMission(Globals::status);
  iVar7 = Mission::isEmpty(pMVar6);
  if (iVar7 == 0) {
    iVar7 = Mission::getType(pMVar6);
    if (((iVar7 == 0xb) || (iVar7 = Mission::getType(pMVar6), iVar7 == 0)) ||
       (iVar7 = Mission::getType(pMVar6), iVar7 == 0xd)) {
      uVar37 = 0;
    }
    else {
      iVar7 = Mission::getType(pMVar6);
      uVar37 = 0;
      if (iVar7 != 0xab) {
        iVar7 = Mission::getType(pMVar6);
        uVar37 = (uint)(iVar7 != 0xac);
      }
    }
  }
  pRVar26 = local_dc;
  local_fc = (Radar *)uVar37;
  pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)local_dc);
  local_e0 = PlayerEgo::isInTurretMode(pPVar8);
  puVar9 = (undefined4 *)Status::inAlienOrbit(Globals::status);
  pfVar10 = (float *)Status::getCurrentCampaignMission(Globals::status);
  uVar11 = Level::getEnemies(*(Level **)pRVar26);
  *(undefined4 *)(pRVar26 + 0x134) = uVar11;
  uVar11 = Level::getLandmarks(*(Level **)pRVar26);
  *(undefined4 *)(pRVar26 + 0x138) = uVar11;
  uVar11 = Level::getPlayerRoute(*(Level **)pRVar26);
  *(undefined4 *)(pRVar26 + 0x150) = uVar11;
  uVar11 = Level::getAsteroids(*(Level **)pRVar26);
  *(undefined4 *)(pRVar26 + 0x13c) = uVar11;
  uVar11 = Level::getGasClouds(*(Level **)pRVar26);
  *(undefined4 *)(pRVar26 + 0x144) = uVar11;
  pSVar12 = (StarSystem *)Level::getStarSystem(*(Level **)pRVar26);
  uVar11 = StarSystem::getPlanetTargets(pSVar12);
  *(undefined4 *)(pRVar26 + 0x140) = uVar11;
  pPVar38 = Globals::Canvas;
  uVar37 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  pMVar13 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar38,uVar37);
  this_05 = (Matrix *)(pRVar26 + 0x1cc);
  AbyssEngine::AEMath::Matrix::operator=(this_05,pMVar13);
  *(undefined4 *)(pRVar26 + 0x238) = *(undefined4 *)(pRVar26 + 0x1d8);
  *(undefined4 *)(pRVar26 + 0x23c) = *(undefined4 *)(pRVar26 + 0x1e8);
  *(undefined4 *)(pRVar26 + 0x240) = *(undefined4 *)(pRVar26 + 0x1f8);
  AbyssEngine::AEMath::MatrixGetInverse((AEMath *)&local_98,this_05);
  AbyssEngine::AEMath::Matrix::operator=(this_05,(AEMath *)&local_98);
  pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
  iVar7 = PlayerEgo::goingToPlanet(pPVar8);
  local_ec = puVar9;
  if (puVar9 == (undefined4 *)0x0) {
    if (iVar7 == 1) {
      pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
      iVar7 = PlayerEgo::isDockingToPlanet(pPVar8);
      RVar4 = (Radar)0x0;
      if (iVar7 == 0) {
        pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
        iVar7 = PlayerEgo::getAutoPilotTarget(pPVar8);
        pSVar12 = (StarSystem *)Level::getStarSystem(*(Level **)pRVar26);
        iVar40 = StarSystem::getPlanetTargets(pSVar12);
        pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
        this_01 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar19 = SolarSystem::getStations(this_01);
        iVar19 = SolarSystem::getStationEnumIndex
                           (pSVar16,*(int *)(*(int *)(iVar19 + 4) + *(int *)(pRVar26 + 0x40) * 4));
        RVar4 = (Radar)(iVar7 == *(int *)(*(int *)(iVar40 + 4) + iVar19 * 4));
      }
    }
    else {
      RVar4 = (Radar)0x0;
    }
    pRVar26[0x1a4] = RVar4;
  }
  else {
    if (iVar7 == 1) {
      pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
      bVar3 = PlayerEgo::isDockingToPlanet(pPVar8);
      RVar4 = (Radar)(bVar3 ^ 1);
    }
    else {
      RVar4 = (Radar)0x0;
    }
    pRVar26[0x1a4] = RVar4;
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(pRVar26 + 0x1c0),
             *(int *)(pRVar26 + 0x104) - *(int *)(pRVar26 + 0x4c),
             *(int *)(pRVar26 + 0x108) - *(int *)(pRVar26 + 0x50));
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(pRVar26 + 0x1c0),*(int *)(pRVar26 + 0x104),
             *(int *)(pRVar26 + 0x108) - *(int *)(pRVar26 + 0x50),'\x01');
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(pRVar26 + 0x1c0),
             *(int *)(pRVar26 + 0x104) - *(int *)(pRVar26 + 0x4c),*(int *)(pRVar26 + 0x108),'\x02');
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(pRVar26 + 0x1c0),*(int *)(pRVar26 + 0x104),
             *(int *)(pRVar26 + 0x108),'\x03');
  if ((*(Route **)(pRVar26 + 0x150) != (Route *)0x0) &&
     (piVar14 = (int *)Route::getWaypoint(*(Route **)(pRVar26 + 0x150)), piVar14 != (int *)0x0)) {
    (**(code **)(*piVar14 + 0x28))(&local_98,piVar14);
    update(pRVar26,local_98,uStack_94,uStack_90);
    VectorSignedToFloat(piVar14[0x48],(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(piVar14[0x49],(byte)(in_fpscr >> 0x16) & 3);
    fVar44 = (float)VectorSignedToFloat(piVar14[0x4a],(byte)(in_fpscr >> 0x16) & 3);
    calcDistance(fVar44,extraout_s1,*(float *)(pRVar26 + 0x238),extraout_s3,
                 *(float *)(pRVar26 + 0x23c),extraout_s5);
    AbyssEngine::String::operator=((String *)(pRVar26 + 0x18c),(String *)&local_98);
    AbyssEngine::String::~String((String *)&local_98);
    if (pRVar26[0x11c] == (Radar)0x0) {
      if (pRVar26[0x1a7] != (Radar)0x0) {
        AbyssEngine::PaintCanvas::DrawImage2D
                  (Globals::Canvas,*(uint *)(pRVar26 + 0x70),*(int *)(pRVar26 + 0xfc),
                   *(int *)(pRVar26 + 0x100),'\x11','D');
      }
    }
    else {
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,*(uint *)(pRVar26 + 0x6c),*(int *)(pRVar26 + 0xfc),
                 *(int *)(pRVar26 + 0x100),'\x11','D');
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,(String *)(pRVar26 + 0x18c),
                 *(int *)(pRVar26 + 0xfc) - *(int *)(pRVar26 + 0x224),
                 *(int *)(pRVar26 + 0x100) + *(int *)(pRVar26 + 0x21c),false);
    }
  }
  local_104 = pRVar26 + 0xc;
  if (((*(int *)local_104 == 0) && (*(int *)(pRVar26 + 0x38) == 0)) &&
     (*(int *)(pRVar26 + 0x1c) == 0)) {
    uVar37 = (uint)(*(int *)(pRVar26 + 0x14) != 0);
  }
  else {
    uVar37 = 1;
  }
  if (*(int *)(local_dc + 0x138) == 0) {
LAB_001558a6:
    local_f4 = (Radar *)0x0;
    pRVar26 = local_dc;
  }
  else {
    pSVar15 = (Station *)Status::getStation(Globals::status);
    iVar7 = Station::getIndex(pSVar15);
    if (iVar7 == 0x6d) goto LAB_001558a6;
    pSVar15 = (Station *)Status::getStation(Globals::status);
    iVar7 = Station::getIndex(pSVar15);
    if (iVar7 == 0x6e) goto LAB_001558a6;
    pSVar15 = (Station *)Status::getStation(Globals::status);
    iVar7 = Station::getIndex(pSVar15);
    if ((iVar7 == 0x6f) &&
       (iVar7 = Status::getCurrentCampaignMission(Globals::status), 0x5d < iVar7))
    goto LAB_001558a6;
    puVar17 = *(uint **)(local_dc + 0x138);
    local_e8 = (undefined4 *)0x0;
    local_f0 = pfVar10;
    if (*puVar17 != 0) {
      pRVar26 = (Radar *)(uVar37 ^ 1);
      local_100 = local_dc + 0x18c;
      local_108 = local_dc + 0x22c;
      local_110 = local_dc + 0x178;
      local_118 = local_dc + 0x16c;
      iVar7 = 0;
      uVar37 = 0;
      local_124 = (Radar *)(local_e0 ^ 1);
      local_f4 = (Radar *)&Globals::Canvas;
      local_f8 = (Radar *)&Globals::Canvas;
      local_12c = (float *)PlayerEgo::crosshairPos;
      local_11c = (Radar *)&Globals::Canvas;
      local_120 = (Radar *)&Globals::font;
      local_140 = (Radar *)&Globals::layout;
      local_144 = (Radar *)&Globals::Canvas;
      local_148 = (Radar *)&Globals::font;
      local_134 = (Radar *)&Globals::font;
      local_138 = (uint *)&Globals::Canvas;
      local_13c = &Globals::gameText;
      local_130 = (float *)&Globals::Canvas;
      local_e8 = (undefined4 *)0x0;
      do {
        pRVar25 = local_dc;
        if (((iVar7 != 8) && (*(KIPlayer **)(puVar17[1] + iVar7) != (KIPlayer *)0x0)) &&
           (iVar40 = KIPlayer::isVisible(*(KIPlayer **)(puVar17[1] + iVar7)), iVar40 == 1)) {
          (**(code **)(**(int **)(*(int *)(*(int *)(pRVar25 + 0x138) + 4) + iVar7) + 0x28))
                    ((Vector *)&local_98);
          update(pRVar25,local_98,uStack_94,uStack_90);
          pRVar27 = local_100;
          if (pRVar25[0x11c] != (Radar)0x0) {
            iVar40 = *(int *)(pRVar25 + 0xfc);
            iVar19 = *(int *)(pRVar25 + 0x128);
            if ((*(int *)(pRVar25 + 0x104) - iVar19 < iVar40) &&
               (iVar40 < *(int *)(pRVar25 + 0x104) + iVar19)) {
              iVar39 = *(int *)(pRVar25 + 0x100);
              if ((*(int *)(pRVar25 + 0x108) - iVar19 < iVar39) &&
                 (iVar39 < iVar19 + *(int *)(pRVar25 + 0x108))) {
                uVar18 = (uint)(iVar7 != 0xc);
                bVar43 = ((uint)(((uint)local_e8 & 1) == 0) & (uint)pRVar26) == 1;
                if (bVar43) {
                  uVar18 = uVar18 & (uint)local_124;
                }
                if (bVar43 && uVar18 == 1) {
                  iVar19 = *(int *)(pRVar25 + 0x124);
                  fVar44 = (float)VectorSignedToFloat(iVar19,(byte)(in_fpscr >> 0x16) & 3);
                  if ((((int)(*local_12c - fVar44) < iVar40) &&
                      (pRVar25 = local_dc, iVar39 < (int)(local_12c[1] - fVar44) + iVar19 * 2)) &&
                     (((int)(local_12c[1] - fVar44) < iVar39 &&
                      (iVar40 < (int)(*local_12c - fVar44) + iVar19 * 2)))) {
                    iVar40 = *(int *)(*(int *)(*(int *)(local_dc + 0x138) + 4) + iVar7);
                    if (*(int *)(local_dc + 0x28) != iVar40) {
                      *(undefined4 *)(local_dc + 0x1a0) = 0;
                    }
                    *(int *)(local_dc + 0x28) = iVar40;
                    local_e8 = (undefined4 *)0x1;
                  }
                }
                local_128 = pRVar26;
                Player::getPosition();
                AbyssEngine::AEMath::Vector::operator=((Vector *)local_118,(Vector *)&local_98);
                Player::getPosition();
                AbyssEngine::AEMath::Vector::operator=((Vector *)local_110,(Vector *)&local_98);
                if (iVar7 != 0xc) {
                  AbyssEngine::PaintCanvas::DrawImage2D
                            ((PaintCanvas *)*local_130,*(uint *)(pRVar25 + 0x88),
                             *(int *)(pRVar25 + 0xfc),*(int *)(pRVar25 + 0x100),'\x11','D');
                }
                pRVar28 = local_108;
                if (iVar7 == 0) {
                  pRVar28 = pRVar25 + 0x228;
                }
                AbyssEngine::PaintCanvas::DrawString
                          (*(PaintCanvas **)local_11c,*(uint *)local_120,
                           *(String **)(*(int *)(*(int *)(pRVar25 + 0x188) + 4) + iVar7),
                           *(int *)pRVar28 + *(int *)(pRVar25 + 0xfc),*(int *)(pRVar25 + 0x100),
                           false);
                pRVar25 = local_dc;
                pRVar26 = local_128;
                if ((int)uVar37 < 2) {
                  if (iVar7 == 0 && local_ec == (undefined4 *)0x0) {
                    uVar18 = *(uint *)local_134;
                    pPVar38 = (PaintCanvas *)*local_138;
                    pSVar21 = (String *)GameText::getText((GameText *)*local_13c,0x85);
                    AbyssEngine::String::String(aSStack_cc,": ",false);
                    AbyssEngine::operator+(aAStack_c0,pSVar21,aSStack_cc);
                    pRVar25 = local_dc;
                    pSVar15 = (Station *)Status::getStation(Globals::status);
                    uVar11 = Station::getTecLevel(pSVar15);
                    local_a8[0] = 0;
                    AbyssEngine::String::Set(CONCAT44(uVar11,local_a8));
                    AbyssEngine::String::String(aSStack_a0,(String *)local_a8,false);
                    pRVar26 = local_128;
                    AbyssEngine::operator+((AbyssEngine *)&local_98,aAStack_c0,aSStack_a0);
                    AbyssEngine::PaintCanvas::DrawString
                              (pPVar38,uVar18,(Vector *)&local_98,
                               *(int *)(pRVar25 + 0x228) + *(int *)(pRVar25 + 0xfc),
                               *(int *)(Globals::layout + 4) + *(int *)(pRVar25 + 0x100),false);
                    AbyssEngine::String::~String((String *)&local_98);
                    AbyssEngine::String::~String(aSStack_a0);
                    AbyssEngine::String::~String((String *)local_a8);
                    AbyssEngine::String::~String((String *)aAStack_c0);
                    AbyssEngine::String::~String(aSStack_cc);
                    calcDistance(*(float *)(pRVar25 + 0x238),extraout_s1_02,
                                 *(float *)(pRVar25 + 0x23c),extraout_s3_02,
                                 *(float *)(pRVar25 + 0x240),extraout_s5_02);
                    pRVar27 = local_100;
                    AbyssEngine::String::operator=((String *)local_100,(Vector *)&local_98);
                    AbyssEngine::String::~String((String *)&local_98);
                    AbyssEngine::PaintCanvas::DrawString
                              (Globals::Canvas,Globals::font,pRVar27,
                               *(int *)(pRVar25 + 0x228) + *(int *)(pRVar25 + 0xfc),
                               *(int *)(pRVar25 + 0x100) + *(int *)(Globals::layout + 4) * 2,false);
                  }
                  else {
                    calcDistance(*(float *)(local_dc + 0x238),extraout_s1_01,
                                 *(float *)(local_dc + 0x23c),extraout_s3_01,
                                 *(float *)(local_dc + 0x240),extraout_s5_01);
                    AbyssEngine::String::operator=((String *)pRVar27,(Vector *)&local_98);
                    AbyssEngine::String::~String((String *)&local_98);
                    AbyssEngine::PaintCanvas::DrawString
                              (*(PaintCanvas **)local_144,*(uint *)local_148,pRVar27,
                               *(int *)pRVar28 + *(int *)(pRVar25 + 0xfc),
                               *(int *)(pRVar25 + 0x100) + *(int *)(*(int *)local_140 + 4),false);
                    pRVar26 = local_128;
                  }
                }
                goto LAB_00156d64;
              }
            }
          }
          if (uVar37 == 1) {
            uVar18 = *(uint *)(pRVar25 + 0xbc);
            iVar40 = *(int *)(pRVar25 + 0xfc);
            iVar19 = *(int *)(pRVar25 + 0x100);
            pRVar27 = local_f4;
          }
          else {
            if (uVar37 != 3) goto LAB_00156d64;
            uVar18 = *(uint *)(pRVar25 + 0xb8);
            iVar40 = *(int *)(pRVar25 + 0xfc);
            iVar19 = *(int *)(pRVar25 + 0x100);
            pRVar27 = local_f8;
          }
          AbyssEngine::PaintCanvas::DrawImage2D
                    (*(PaintCanvas **)pRVar27,uVar18,iVar40,iVar19,'\x11','D');
        }
LAB_00156d64:
        puVar17 = *(uint **)(pRVar25 + 0x138);
        iVar7 = iVar7 + 4;
        uVar37 = uVar37 + 1;
      } while (uVar37 < *puVar17);
    }
    pRVar26 = local_dc;
    pfVar10 = local_f0;
    local_f4 = (Radar *)((uint)local_e8 & 1);
    if (local_e0 == 0) {
      if (*(KIPlayer **)(local_dc + 0x24) != (KIPlayer *)0x0) {
        iVar7 = KIPlayer::isDead(*(KIPlayer **)(local_dc + 0x24));
        if (iVar7 == 0) {
          iVar7 = *(int *)(pRVar26 + 0x24);
        }
        else {
          iVar7 = 0;
          *(undefined4 *)(pRVar26 + 0x24) = 0;
        }
        if (iVar7 == *(int *)(pRVar26 + 0x28)) {
          pRVar26[0x214] = (Radar)0x1;
        }
        *(undefined4 *)(pRVar26 + 0x24) = 0;
      }
      if (local_f4 != (Radar *)0x0) {
        pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
        iVar7 = PlayerEgo::isDockingToAsteroid(pPVar8);
        if (iVar7 == 0) {
          pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
          iVar7 = PlayerEgo::isDockingToDockingPoint(pPVar8);
          if (iVar7 == 0) {
            pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
            iVar7 = PlayerEgo::isAutoPilot(pPVar8);
            if (iVar7 == 0) {
              iVar7 = *(int *)(pRVar26 + 0x1a0) + local_10c;
              *(int *)(pRVar26 + 0x1a0) = iVar7;
              if (*(int *)(pRVar26 + 0x1b4) < iVar7) {
                if (pRVar26[0x214] == (Radar)0x0) {
                  FModSound::play(Globals::sound,0x1a,(Vector *)0x0,(Vector *)0x0,extraout_s0_05);
                  iVar7 = *(int *)(pRVar26 + 0x1a0);
                }
                *(undefined4 *)(pRVar26 + 0x24) = *(undefined4 *)(pRVar26 + 0x28);
              }
              if (0 < iVar7) {
                if ((*(int *)(pRVar26 + 0x28) == 0) ||
                   (*(int *)(pRVar26 + 0x28) == *(int *)(pRVar26 + 0x24))) {
                  pSVar36 = *(Sprite **)(local_dc + 0xf4);
                  iVar7 = Sprite::getRawFrameCount(pSVar36);
                  pRVar26 = local_dc;
                  Sprite::setFrame(pSVar36,iVar7 + -1);
                }
                else {
                  pSVar36 = *(Sprite **)(local_dc + 0xf4);
                  iVar7 = Sprite::getRawFrameCount(pSVar36);
                  pRVar26 = local_dc;
                  fVar47 = (float)VectorSignedToFloat(*(undefined4 *)(local_dc + 0x1b4),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  fVar44 = (float)VectorSignedToFloat(*(undefined4 *)(local_dc + 0x1a0),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  fVar46 = (float)VectorSignedToFloat(iVar7 + -1,(byte)(in_fpscr >> 0x16) & 3);
                  Sprite::setFrame(pSVar36,(int)(fVar46 * (fVar44 / fVar47)));
                }
                uVar45 = Sprite::setRefPixelPosition
                                   (*(Sprite **)(pRVar26 + 0xf4),
                                    (int)(float)PlayerEgo::crosshairPos._0_4_,
                                    (int)(float)PlayerEgo::crosshairPos._4_4_);
                Sprite::draw((float)uVar45,(float)((ulonglong)uVar45 >> 0x20));
              }
              local_f4 = (Radar *)0x1;
              goto LAB_001558ae;
            }
          }
        }
      }
      if (*(int *)(pRVar26 + 0x24) == 0) {
        *(undefined4 *)(pRVar26 + 0x28) = 0;
      }
      *(undefined4 *)(pRVar26 + 0x1a0) = 0;
    }
  }
LAB_001558ae:
  if (((*(int *)local_104 == 0) && (*(int *)(pRVar26 + 0x38) == 0)) &&
     (*(int *)(pRVar26 + 0x1c) == 0)) {
    local_e8 = (undefined4 *)(uint)(*(int *)(pRVar26 + 0x24) != 0);
  }
  else {
    local_e8 = (undefined4 *)0x1;
  }
  if ((1 < (int)pfVar10) && (local_ec == (undefined4 *)0x0 && *(int *)(pRVar26 + 0x140) != 0)) {
    pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
    iVar7 = PlayerEgo::isDockingToPlanet(pPVar8);
    if (iVar7 == 0) {
      pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
      pfVar10 = (float *)SolarSystem::getStations(pSVar16);
      puVar17 = *(uint **)(pRVar26 + 0x140);
      local_ec = (undefined4 *)0x0;
      if (*puVar17 != 0) {
        local_110 = pRVar26 + 0x124;
        uVar37 = 0;
        local_100 = (Radar *)&Globals::status;
        local_108 = (Radar *)&Globals::status;
        local_118 = (Radar *)&StarSystem::orbitPlanetIndex;
        local_11c = (Radar *)PlayerEgo::crosshairPos;
        local_13c = &Globals::font;
        local_140 = (Radar *)&Globals::Canvas;
        local_144 = (Radar *)&Globals::status;
        local_134 = (Radar *)&Globals::Canvas;
        local_124 = (Radar *)&Globals::status;
        local_128 = (Radar *)&Globals::status;
        local_12c = (float *)&Globals::status;
        local_130 = (float *)&Globals::status;
        local_148 = (Radar *)&Globals::status;
        local_138 = (uint *)&Globals::status;
        local_120 = (Radar *)&Globals::Canvas;
        local_ec = (undefined4 *)0x0;
        local_f0 = pfVar10;
        do {
          piVar14 = *(int **)(puVar17[1] + uVar37 * 4);
          if (piVar14 != (int *)0x0) {
            (**(code **)(*piVar14 + 0x28))(&local_98);
            update(pRVar26,local_98,uStack_94,uStack_90);
            pRVar25 = local_100;
            if (pRVar26[0x11c] != (Radar)0x0) {
              iVar40 = *(int *)((int)pfVar10[1] + uVar37 * 4);
              pSVar15 = (Station *)Status::getStation(*(Status **)local_100);
              iVar7 = Station::getIndex(pSVar15);
              pSVar16 = (SolarSystem *)Status::getSystem(*(Status **)pRVar25);
              uVar18 = SolarSystem::getWarpGateEnumIndex(pSVar16);
              pRVar25 = (Radar *)0xa;
              if ((iVar40 != iVar7) && (uVar37 == uVar18)) {
                AbyssEngine::PaintCanvas::DrawImage2D
                          (*(PaintCanvas **)local_120,*(uint *)(pRVar26 + 0xbc),
                           *(int *)(pRVar26 + 0xfc) + 10,*(int *)(pRVar26 + 0x100) + -10);
                pRVar25 = (Radar *)0x18;
              }
              pRVar26 = local_108;
              local_f8 = pRVar25;
              pMVar6 = (Mission *)Status::getCampaignMission(*(Status **)local_108);
              this_02 = (Mission *)Status::getFreelanceMission(*(Status **)pRVar26);
              if ((((pMVar6 == (Mission *)0x0) || (iVar19 = Mission::isEmpty(pMVar6), iVar19 != 0))
                  || (iVar19 = Mission::isVisible(pMVar6), iVar19 != 1)) ||
                 ((iVar19 = Status::getCurrentCampaignMission(*(Status **)local_124), 0x93 < iVar19
                  && (iVar19 = Status::getCurrentCampaignMission((Status *)*local_138),
                     iVar19 < 0x98)))) {
                bVar43 = false;
                goto LAB_00155d0a;
              }
              iVar39 = *(int *)((int)local_f0[1] + uVar37 * 4);
              iVar19 = Mission::getTargetStation(pMVar6);
              bVar43 = false;
              if ((iVar40 != iVar7) && (iVar39 == iVar19)) {
                iVar19 = Status::getCurrentCampaignMission(*(Status **)local_148);
                if (iVar19 == 0x78) {
                  bVar43 = false;
                }
                else {
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)(local_dc + 200),
                             (int)(local_f8 + *(int *)(local_dc + 0xfc)),
                             *(int *)(local_dc + 0x100) + -10);
                  bVar43 = true;
                }
              }
              iVar19 = Status::getCurrentCampaignMission(*(Status **)local_128);
              if ((iVar19 == 0x74) && (*(int *)((int)local_f0[1] + uVar37 * 4) - 0x5aU < 5)) {
                pMVar6 = (Mission *)Status::getCampaignMission(Globals::status);
                uVar18 = Mission::getStatusValue(pMVar6);
                if ((1 << (*(int *)((int)local_f0[1] + uVar37 * 4) - 0x5aU & 0xff) & uVar18) != 0)
                goto LAB_00155b8c;
                uVar18 = *(uint *)(local_dc + 200);
                iVar19 = *(int *)(local_dc + 0xfc);
                iVar39 = *(int *)(local_dc + 0x100);
LAB_00155c24:
                AbyssEngine::PaintCanvas::DrawImage2D
                          (Globals::Canvas,uVar18,(int)(local_f8 + iVar19),iVar39 + -10);
                bVar43 = true;
              }
              else {
LAB_00155b8c:
                iVar19 = Status::getCurrentCampaignMission((Status *)*local_12c);
                if ((iVar19 == 0x78) && (*(int *)((int)local_f0[1] + uVar37 * 4) == 0x5d)) {
                  uVar18 = *(uint *)(local_dc + 200);
                  iVar19 = *(int *)(local_dc + 0xfc);
                  iVar39 = *(int *)(local_dc + 0x100);
                  goto LAB_00155c24;
                }
                iVar19 = Status::getCurrentCampaignMission((Status *)*local_130);
                pfVar10 = local_f0;
                if ((iVar19 == 0x7d) &&
                   (iVar19 = Status::isFreighterMissionStation
                                       (Globals::status,*(int *)((int)local_f0[1] + uVar37 * 4)),
                   iVar19 == 1)) {
                  pMVar6 = (Mission *)Status::getCampaignMission(Globals::status);
                  uVar18 = Mission::getStatusValue(pMVar6);
                  uVar24 = Status::getFreighterMissionStationBit
                                     (Globals::status,*(int *)((int)pfVar10[1] + uVar37 * 4));
                  if ((1 << (uVar24 & 0xff) & uVar18) == 0) {
                    uVar18 = *(uint *)(local_dc + 200);
                    iVar19 = *(int *)(local_dc + 0xfc);
                    iVar39 = *(int *)(local_dc + 0x100);
                    goto LAB_00155c24;
                  }
                }
              }
LAB_00155d0a:
              pfVar10 = local_f0;
              if (((this_02 != (Mission *)0x0) &&
                  (iVar19 = Mission::isEmpty(this_02), pfVar10 = local_f0, iVar19 == 0)) &&
                 (iVar19 = Mission::isVisible(this_02), pfVar10 = local_f0, iVar19 == 1)) {
                iVar39 = *(int *)((int)local_f0[1] + uVar37 * 4);
                iVar19 = Mission::getType(this_02);
                if (iVar19 == 0xe) {
                  this_03 = (Agent *)Mission::getAgent(this_02);
                  iVar19 = Agent::getStation(this_03);
                }
                else {
                  iVar19 = Mission::getTargetStation(this_02);
                }
                pfVar10 = local_f0;
                if ((iVar40 != iVar7) && (iVar39 == iVar19)) {
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (*(PaintCanvas **)local_134,*(uint *)(local_dc + 0xc4),
                             (int)(local_f8 + *(int *)(local_dc + 0xfc)),
                             *(int *)(local_dc + 0x100) + -10);
                  bVar43 = true;
                }
              }
              if ((((uint)local_e8 | (uint)local_ec | local_e0) & 1) == 0) {
                pRVar26 = local_110;
                if (uVar37 == *(uint *)local_118) {
                  pRVar26 = local_dc + 0x128;
                }
                iVar19 = *(int *)pRVar26;
                fVar44 = (float)VectorSignedToFloat(iVar19 >> 1,(byte)(in_fpscr >> 0x16) & 3);
                local_ec = (undefined4 *)0x0;
                if (((int)(*(float *)local_11c - fVar44) < *(int *)(local_dc + 0xfc)) &&
                   (*(int *)(local_dc + 0xfc) < (int)(*(float *)local_11c - fVar44) + iVar19)) {
                  local_ec = (undefined4 *)0x0;
                  if (((int)(*(float *)(local_11c + 4) - fVar44) < *(int *)(local_dc + 0x100)) &&
                     (*(int *)(local_dc + 0x100) <
                      iVar19 + (int)(*(float *)(local_11c + 4) - fVar44))) {
                    if (uVar37 == *(uint *)local_118) {
                      local_ec = (undefined4 *)0x0;
                    }
                    else {
                      iVar19 = *(int *)(*(int *)(*(int *)(local_dc + 0x140) + 4) + uVar37 * 4);
                      if (*(int *)(local_dc + 0x18) != iVar19) {
                        *(undefined4 *)(local_dc + 0x19c) = 0;
                      }
                      *(uint *)(local_dc + 0x40) = uVar37;
                      *(int *)(local_dc + 0x18) = iVar19;
                      local_ec = (undefined4 *)0x1;
                    }
                    if (iVar40 != iVar7) {
                      uVar18 = *local_13c;
                      pPVar38 = *(PaintCanvas **)local_140;
                      iVar7 = Status::getPlanetNames(*(Status **)local_144);
                      pfVar10 = local_f0;
                      pRVar26 = local_f8;
                      if (bVar43) {
                        pRVar26 = local_f8 + 0xe;
                      }
                      AbyssEngine::PaintCanvas::DrawString
                                (pPVar38,uVar18,*(String **)(*(int *)(iVar7 + 4) + uVar37 * 4),
                                 (int)(pRVar26 + *(int *)(local_dc + 0xfc)),
                                 *(int *)(local_dc + 0x100) + -10,false);
                    }
                  }
                }
              }
            }
          }
          uVar37 = uVar37 + 1;
          puVar17 = *(uint **)(local_dc + 0x140);
          pRVar26 = local_dc;
        } while (uVar37 < *puVar17);
      }
      pRVar25 = local_fc;
      if (local_e0 == 0 && local_f4 == (Radar *)0x0) {
        if (*(int *)(pRVar26 + 0x14) != 0) {
          if (*(int *)(pRVar26 + 0x14) == *(int *)(pRVar26 + 0x18)) {
            pRVar26[0x214] = (Radar)0x1;
          }
          *(undefined4 *)(pRVar26 + 0x14) = 0;
        }
        if (((uint)local_ec & 1) != 0) {
          pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
          iVar7 = PlayerEgo::isDockingToAsteroid(pPVar8);
          if (iVar7 == 0) {
            pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
            iVar7 = PlayerEgo::isDockingToDockingPoint(pPVar8);
            if (iVar7 == 0) {
              iVar7 = *(int *)(pRVar26 + 0x19c);
              *(int *)(pRVar26 + 0x19c) = iVar7 + local_10c;
              if (*(int *)(pRVar26 + 0x1b4) < iVar7 + local_10c) {
                if (pRVar25 == (Radar *)0x1) {
                  iVar7 = Level::getPlayer(*(Level **)pRVar26);
                  Hud::hudEvent((int)local_114,(PlayerEgo *)0x15,iVar7);
                  goto LAB_00155ebe;
                }
                if (pRVar26[0x214] == (Radar)0x0) {
                  FModSound::play(Globals::sound,0x1a,(Vector *)0x0,(Vector *)0x0,extraout_s0);
                }
                *(undefined4 *)(pRVar26 + 0x14) = *(undefined4 *)(pRVar26 + 0x18);
                if (pRVar26[0x1a4] != (Radar)0x0) {
                  pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
                  PlayerEgo::dockToPlanet(pPVar8);
                }
              }
              if (pRVar25 == (Radar *)0x0 && 0 < *(int *)(pRVar26 + 0x19c)) {
                if ((*(int *)(pRVar26 + 0x18) == 0) ||
                   (*(int *)(pRVar26 + 0x18) == *(int *)(pRVar26 + 0x14))) {
                  pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
                  iVar7 = PlayerEgo::isDockingToPlanet(pPVar8);
                  if (iVar7 != 0) goto LAB_00155ebe;
                  pSVar36 = *(Sprite **)(local_dc + 0xf4);
                  iVar7 = Sprite::getRawFrameCount(pSVar36);
                  pRVar26 = local_dc;
                  Sprite::setFrame(pSVar36,iVar7 + -1);
                }
                else {
                  pSVar36 = *(Sprite **)(local_dc + 0xf4);
                  iVar7 = Sprite::getRawFrameCount(pSVar36);
                  pRVar26 = local_dc;
                  fVar47 = (float)VectorSignedToFloat(*(undefined4 *)(local_dc + 0x1b4),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  fVar44 = (float)VectorSignedToFloat(*(undefined4 *)(local_dc + 0x19c),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  fVar46 = (float)VectorSignedToFloat(iVar7 + -1,(byte)(in_fpscr >> 0x16) & 3);
                  Sprite::setFrame(pSVar36,(int)(fVar46 * (fVar44 / fVar47)));
                }
                uVar45 = Sprite::setRefPixelPosition
                                   (*(Sprite **)(pRVar26 + 0xf4),
                                    (int)(float)PlayerEgo::crosshairPos._0_4_,
                                    (int)(float)PlayerEgo::crosshairPos._4_4_);
                Sprite::draw((float)uVar45,(float)((ulonglong)uVar45 >> 0x20));
              }
              goto LAB_00155ebe;
            }
          }
        }
        if (*(int *)(pRVar26 + 0x14) == 0) {
          *(undefined4 *)(pRVar26 + 0x18) = 0;
        }
        *(undefined4 *)(pRVar26 + 0x19c) = 0;
      }
    }
  }
LAB_00155ebe:
  local_fc = pRVar26 + 4;
  if ((*(KIPlayer **)local_fc != (KIPlayer *)0x0) &&
     ((iVar7 = KIPlayer::isDying(*(KIPlayer **)local_fc), iVar7 != 0 ||
      (iVar7 = KIPlayer::isDead(*(KIPlayer **)local_fc), iVar7 == 1)))) {
    *(undefined4 *)(pRVar26 + 4) = 0;
    local_e8 = (undefined4 *)0x0;
    *(undefined4 *)(pRVar26 + 8) = 0;
  }
  if ((pRVar26[0x1a7] == (Radar)0x0) ||
     (puVar17 = *(uint **)(pRVar26 + 0x134), puVar17 == (uint *)0x0)) {
    local_f8 = (Radar *)0x0;
    local_110 = (Radar *)0x0;
    local_118 = (Radar *)0x0;
  }
  else {
    pRVar25 = (Radar *)0x0;
    local_f0 = (float *)0x0;
    local_108 = (Radar *)0x0;
    if (*puVar17 != 0) {
      pRVar27 = pRVar26 + 0xd0;
      pRVar28 = pRVar26 + 0xe0;
      pRVar29 = pRVar26 + 100;
      pRVar30 = pRVar26 + 0xd4;
      pRVar31 = pRVar26 + 0xe4;
      pRVar32 = pRVar26 + 0x80;
      local_140 = pRVar26 + 0x7c;
      local_118 = pRVar26 + 0x18c;
      local_11c = pRVar26 + 0xa0;
      local_f4 = pRVar26 + 0x178;
      local_f8 = pRVar26 + 0x16c;
      local_128 = pRVar26 + 0x60;
      local_144 = pRVar26 + 0x68;
      local_148 = pRVar26 + 0x78;
      local_134 = pRVar26 + 0xb0;
      pRVar33 = pRVar26 + 0xa8;
      pRVar25 = (Radar *)0x0;
      uVar37 = 0;
      local_138 = (uint *)&Globals::Canvas;
      local_13c = (uint *)&Globals::Canvas;
      local_120 = (Radar *)&Globals::Canvas;
      local_124 = (Radar *)PlayerEgo::crosshairPos;
      local_12c = (float *)&Globals::font;
      local_130 = (float *)&Globals::Canvas;
      local_f0 = (float *)0x0;
      local_108 = (Radar *)0x0;
      do {
        pKVar42 = *(KIPlayer **)(puVar17[1] + uVar37 * 4);
        iVar7 = Player::isActive(*(Player **)(pKVar42 + 4));
        if (iVar7 == 1) {
          uVar18 = KIPlayer::isDying(pKVar42);
          bVar43 = uVar18 == 1;
          if (bVar43) {
            uVar18 = (uint)(byte)pKVar42[0x48];
          }
          if ((bVar43 && uVar18 == 0) || (pKVar42[0x70] != (KIPlayer)0x0)) goto LAB_00156244;
          (**(code **)(*(int *)pKVar42 + 0x28))((Vector *)&local_98,pKVar42);
          update(pRVar26,local_98,uStack_94,uStack_90);
          if (pKVar42[0x48] == (KIPlayer)0x0) {
            puVar9 = (undefined4 *)0x0;
          }
          else {
            iVar7 = KIPlayer::isDead(pKVar42);
            if (iVar7 == 0) {
              puVar9 = (undefined4 *)KIPlayer::isDying(pKVar42);
            }
            else {
              puVar9 = (undefined4 *)0x1;
            }
          }
          pKVar42[0x71] = (KIPlayer)0x0;
          iVar7 = KIPlayer::isDead(pKVar42);
          if (((iVar7 == 0) && (iVar7 = KIPlayer::isDying(pKVar42), iVar7 != 1)) ||
             (pKVar42[0x48] != (KIPlayer)0x0)) {
            pRVar35 = *(Radar **)local_fc;
            if (((*(ushort *)(pKVar42 + 0x38) & 0xff) == 0 &&
                 (*(ushort *)(pKVar42 + 0x38) < 0x100 && puVar9 == (undefined4 *)0x0)) &&
               (this_04 = *(Player **)(pKVar42 + 4), this_04[0x5c] != (Player)0x0)) {
              *(int *)(pRVar26 + 0x1b8) = *(int *)(pRVar26 + 0x1b8) + 1;
              if (*(int *)(pKVar42 + 0x24) == 10) {
                pRVar25 = (Radar *)0x1;
              }
              if ((pKVar42[0x3e] != (KIPlayer)0x0) &&
                 (iVar7 = Player::isAlwaysEnemy(this_04), iVar7 != 0)) {
                local_f0 = (float *)0x1;
              }
            }
            if (pRVar26[0x11c] == (Radar)0x0) {
              pKVar42[0x72] = (KIPlayer)0x0;
              pKVar42[0x6f] = (KIPlayer)0x0;
              if (puVar9 == (undefined4 *)0x1) {
                iVar7 = *(int *)(*(int *)(*(int *)(pRVar26 + 0x134) + 4) + uVar37 * 4);
                pPVar38 = (PaintCanvas *)*local_138;
                pRVar35 = local_134;
                if ((*(char *)(iVar7 + 0x39) == '\0') &&
                   (pRVar35 = pRVar33, *(int *)(iVar7 + 0x24) == 9)) {
                  pRVar35 = pRVar26 + 0xb4;
                }
                iVar7 = *(int *)(pRVar26 + 0xfc);
                iVar40 = *(int *)(pRVar26 + 0x100);
                uVar18 = *(uint *)pRVar35;
              }
              else {
                if ((*(ushort *)(*(int *)(pKVar42 + 4) + 0x5c) & 0xff) == 0) {
                  if (*(ushort *)(*(int *)(pKVar42 + 4) + 0x5c) < 0x100) {
                    pRVar20 = local_148;
                    if (pKVar42 == (KIPlayer *)pRVar35) {
                      pRVar20 = pRVar26 + 0x98;
                    }
                  }
                  else {
                    pRVar20 = local_144;
                    if (pKVar42 == (KIPlayer *)pRVar35) {
                      pRVar20 = pRVar26 + 0x94;
                    }
                  }
                }
                else {
                  pRVar20 = local_128;
                  if (pKVar42 == (KIPlayer *)pRVar35) {
                    pRVar20 = pRVar26 + 0x90;
                  }
                }
                iVar7 = *(int *)(pRVar26 + 0xfc);
                iVar40 = *(int *)(pRVar26 + 0x100);
                uVar18 = *(uint *)pRVar20;
                pPVar38 = (PaintCanvas *)*local_13c;
              }
              AbyssEngine::PaintCanvas::DrawImage2D(pPVar38,uVar18,iVar7,iVar40,'\x11','D');
            }
            else {
              pKVar42[0x72] = (KIPlayer)0x1;
              local_110 = pRVar35;
              local_100 = pRVar25;
              local_ec = puVar9;
              Player::getPosition();
              pRVar25 = local_f8;
              AbyssEngine::AEMath::Vector::operator=((Vector *)local_f8,(Vector *)&local_98);
              Player::getPosition();
              pRVar35 = local_f4;
              AbyssEngine::AEMath::Vector::operator=((Vector *)local_f4,(Vector *)&local_98);
              fVar44 = *(float *)pRVar25 - *(float *)pRVar35;
              in_fpscr = in_fpscr & 0xfffffff;
              uVar18 = in_fpscr | (uint)(fVar44 < 24000.0) << 0x1f |
                       (uint)(fVar44 == 24000.0) << 0x1e;
              uVar24 = uVar18 | (uint)NAN(fVar44) << 0x1c;
              bVar3 = (byte)(uVar18 >> 0x18);
              if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar24 >> 0x1c) & 1)) ||
                 (uVar24 = in_fpscr, fVar44 < -24000.0)) {
LAB_001563f2:
                pRVar25 = local_100;
                pRVar35 = local_110;
                pRVar20 = local_11c;
                if (local_ec == (undefined4 *)0x0) {
                  uVar1 = *(ushort *)(*(int *)(pKVar42 + 4) + 0x5c);
                  if (pKVar42 == (KIPlayer *)local_110) {
                    pRVar20 = local_140;
                    if (((uVar1 & 0xff) == 0) && (pRVar20 = pRVar32, uVar1 >> 8 == 0)) {
                      pRVar20 = pRVar26 + 0x84;
                    }
                  }
                  else {
                    pRVar20 = local_128;
                    if ((uVar1 & 0xff) == 0) {
                      ppRVar2 = &local_144;
                      if (uVar1 >> 8 == 0) {
                        ppRVar2 = &local_148;
                      }
                      pRVar20 = *ppRVar2;
                    }
                  }
                }
                AbyssEngine::PaintCanvas::DrawImage2D
                          (*(PaintCanvas **)local_120,*(uint *)pRVar20,*(int *)(pRVar26 + 0xfc),
                           *(int *)(pRVar26 + 0x100),'\x11','D');
                KVar5 = (KIPlayer)0x0;
                pKVar42[0x6f] = (KIPlayer)0x0;
                fVar46 = *(float *)local_124;
                fVar47 = *(float *)(local_124 + 4);
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_98,(Vector *)local_f8,(Vector *)local_f4);
                fVar44 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_98);
                pRVar20 = local_118;
                in_fpscr = uVar24 & 0xfffffff;
                if (fVar44 < 60000.0) {
                  iVar7 = *(int *)(pRVar26 + 0x124);
                  KVar5 = (KIPlayer)0x0;
                  if (((int)fVar46 - iVar7 < *(int *)(pRVar26 + 0xfc)) &&
                     (*(int *)(pRVar26 + 0xfc) < (int)fVar46 + iVar7)) {
                    if ((int)fVar47 - iVar7 < *(int *)(pRVar26 + 0x100)) {
                      KVar5 = (KIPlayer)(*(int *)(pRVar26 + 0x100) < iVar7 + (int)fVar47);
                    }
                    else {
                      KVar5 = (KIPlayer)0x0;
                    }
                  }
                }
                pKVar42[0x6f] = KVar5;
                if (pKVar42 == (KIPlayer *)pRVar35) {
                  calcDistance(*(float *)(pRVar26 + 0x180),extraout_s1_00,
                               *(float *)(pRVar26 + 0x238),extraout_s3_00,
                               *(float *)(pRVar26 + 0x23c),extraout_s5_00);
                  AbyssEngine::String::operator=((String *)pRVar20,(String *)&local_98);
                  AbyssEngine::String::~String((String *)&local_98);
                  pRVar35 = local_dc;
                  AbyssEngine::PaintCanvas::DrawString
                            ((PaintCanvas *)*local_130,(uint)*local_12c,pRVar20,
                             *(int *)(pRVar26 + 0xfc) - *(int *)(local_dc + 0x224),
                             *(int *)(pRVar26 + 0x100) + *(int *)(pRVar26 + 0x21c),false);
                  pRVar25 = local_100;
                  pRVar26 = pRVar35;
                }
              }
              else {
                fVar44 = *(float *)(pRVar26 + 0x170) - *(float *)(pRVar26 + 0x17c);
                uVar18 = in_fpscr | (uint)(fVar44 < 24000.0) << 0x1f |
                         (uint)(fVar44 == 24000.0) << 0x1e;
                uVar24 = uVar18 | (uint)NAN(fVar44) << 0x1c;
                bVar3 = (byte)(uVar18 >> 0x18);
                if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar24 >> 0x1c) & 1)) ||
                   (uVar24 = in_fpscr, fVar44 < -24000.0)) goto LAB_001563f2;
                fVar44 = *(float *)(pRVar26 + 0x174) - *(float *)(pRVar26 + 0x180);
                uVar18 = in_fpscr | (uint)(fVar44 < 24000.0) << 0x1f |
                         (uint)(fVar44 == 24000.0) << 0x1e;
                uVar24 = uVar18 | (uint)NAN(fVar44) << 0x1c;
                bVar3 = (byte)(uVar18 >> 0x18);
                if (((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar24 >> 0x1c) & 1)) ||
                    (uVar24 = in_fpscr, fVar44 < -24000.0)) ||
                   (iVar7 = KIPlayer::getType(pKVar42), uVar24 = in_fpscr, iVar7 == 0x4215))
                goto LAB_001563f2;
                if (local_ec == (undefined4 *)0x0) {
                  iVar7 = KIPlayer::isDead(pKVar42);
                  pRVar25 = local_100;
                  if (iVar7 == 0) {
                    iVar7 = *(int *)(pRVar26 + 0x124);
                    KVar5 = (KIPlayer)0x0;
                    if (((int)(float)PlayerEgo::crosshairPos._0_4_ - iVar7 <
                         *(int *)(pRVar26 + 0xfc)) &&
                       (*(int *)(pRVar26 + 0xfc) < (int)(float)PlayerEgo::crosshairPos._0_4_ + iVar7
                       )) {
                      if ((int)(float)PlayerEgo::crosshairPos._4_4_ - iVar7 <
                          *(int *)(local_dc + 0x100)) {
                        KVar5 = (KIPlayer)
                                (*(int *)(local_dc + 0x100) <
                                (int)(float)PlayerEgo::crosshairPos._4_4_ + iVar7);
                      }
                      else {
                        KVar5 = (KIPlayer)0x0;
                      }
                    }
                    pKVar42[0x6f] = KVar5;
                    pRVar26 = local_dc;
                  }
                  pRVar35 = pRVar28;
                  pRVar20 = pRVar27;
                  if (((*(ushort *)(*(int *)(pKVar42 + 4) + 0x5c) & 0xff) == 0) &&
                     (pRVar35 = pRVar31, pRVar20 = pRVar30,
                     *(ushort *)(*(int *)(pKVar42 + 4) + 0x5c) < 0x100)) {
                    pRVar35 = pRVar26 + 0xe8;
                    pRVar20 = pRVar26 + 0xd8;
                  }
                  uVar18 = *(uint *)pRVar20;
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)pRVar35,
                             (*(int *)(pRVar26 + 0xfc) + 2) - *(int *)(pRVar26 + 0x224),
                             *(int *)(pRVar26 + 0x100) + *(int *)(pRVar26 + 0x21c) + 2);
                  uVar11 = Player::getDamageRate(*(Player **)(pKVar42 + 4));
                  fVar44 = (float)VectorSignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
                  fVar47 = (float)VectorSignedToFloat(*(undefined4 *)(pRVar26 + 0x1c4),
                                                      (byte)(in_fpscr >> 0x16) & 3);
                  fVar47 = (fVar44 / 100.0) * fVar47;
                  *(int *)(pRVar26 + 0x184) = (int)fVar47;
                  iVar7 = (int)fVar47;
                  AbyssEngine::PaintCanvas::DrawRegion2D
                            (Globals::Canvas,uVar18,0,0,iVar7,*(int *)(pRVar26 + 0x1c8),(float)iVar7
                             ,0,0,0,(*(int *)(pRVar26 + 0xfc) + 3) - *(int *)(pRVar26 + 0x224));
                  iVar7 = Player::getEmpPoints(*(Player **)(pKVar42 + 4));
                  iVar40 = Player::getMaxEmpPoints(*(Player **)(pKVar42 + 4));
                  pRVar26 = local_dc;
                  if (iVar7 < iVar40) {
                    AbyssEngine::PaintCanvas::DrawImage2D
                              (Globals::Canvas,*(uint *)(local_dc + 0xec),
                               (*(int *)(local_dc + 0xfc) + 2) - *(int *)(local_dc + 0x224),
                               *(int *)(local_dc + 0x100) + *(int *)(local_dc + 0x21c) + 8);
                    uVar11 = Player::getEmpDamageRate(*(Player **)(pKVar42 + 4));
                    fVar44 = (float)VectorSignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
                    fVar47 = (float)VectorSignedToFloat(*(undefined4 *)(pRVar26 + 0x1c4),
                                                        (byte)(in_fpscr >> 0x16) & 3);
                    fVar47 = (fVar44 / 100.0) * fVar47;
                    *(int *)(pRVar26 + 0x184) = (int)fVar47;
                    iVar7 = (int)fVar47;
                    AbyssEngine::PaintCanvas::DrawRegion2D
                              (Globals::Canvas,*(uint *)(pRVar26 + 0xdc),0,0,iVar7,
                               *(int *)(pRVar26 + 0x1c8),(float)iVar7,0,0,0,
                               (*(int *)(pRVar26 + 0xfc) + 3) - *(int *)(pRVar26 + 0x224));
                  }
                  pRVar26 = local_dc;
                  if (pKVar42 == (KIPlayer *)local_110) {
                    pRVar35 = pRVar29;
                    if (*(ushort *)(*(int *)(pKVar42 + 4) + 0x5c) < 0x100) {
                      pRVar35 = local_dc + 0x74;
                    }
                    if ((*(ushort *)(*(int *)(pKVar42 + 4) + 0x5c) & 0xff) != 0) {
                      pRVar35 = local_dc + 0x5c;
                    }
                    AbyssEngine::PaintCanvas::DrawImage2D
                              (Globals::Canvas,*(uint *)pRVar35,*(int *)(local_dc + 0xfc),
                               *(int *)(local_dc + 0x100),'\x11','D');
                  }
                }
                else {
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)(pRVar26 + 0x9c),*(int *)(pRVar26 + 0xfc),
                             *(int *)(pRVar26 + 0x100),'\x11','D');
                  pRVar25 = local_100;
                }
              }
              pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
              iVar7 = PlayerEgo::isAutoPilot(pPVar8);
              puVar9 = local_ec;
              if (iVar7 == 0) {
                pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
                iVar7 = PlayerEgo::isDockedToDockingPoint(pPVar8);
                puVar9 = local_ec;
                if (((iVar7 == 0) &&
                    (pKVar42[0x39] == (KIPlayer)0x0 || local_ec != (undefined4 *)0x0)) &&
                   ((((uint)local_108 & 1) == 0 || (pKVar42[0x20] != (KIPlayer)0x0)))) {
                  if (local_ec == (undefined4 *)0x1) {
                    iVar7 = KIPlayer::isDead(pKVar42);
                    if (iVar7 == 1) {
                      if ((*(int *)(pRVar26 + 0x1c) != 0) || (pRVar26[0x1aa] == (Radar)0x0))
                      goto LAB_00156730;
                      *(KIPlayer **)(pRVar26 + 0x1c) = pKVar42;
                      goto LAB_001567a8;
                    }
                  }
                  else {
LAB_00156730:
                    iVar7 = *(int *)(pRVar26 + 0x124);
                    fVar44 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
                    if ((((int)((float)PlayerEgo::crosshairPos._0_4_ - fVar44) <
                          *(int *)(pRVar26 + 0xfc)) &&
                        (((*(int *)(pRVar26 + 0xfc) <
                           (int)((float)PlayerEgo::crosshairPos._0_4_ - fVar44) + iVar7 * 2 &&
                          ((int)((float)PlayerEgo::crosshairPos._4_4_ - fVar44) <
                           *(int *)(pRVar26 + 0x100))) &&
                         (*(int *)(pRVar26 + 0x100) <
                          iVar7 * 2 + (int)((float)PlayerEgo::crosshairPos._4_4_ - fVar44))))) &&
                       (((pKVar42[0x71] = (KIPlayer)0x1, puVar9 == (undefined4 *)0x1 &&
                         (pRVar26[0x1a9] != (Radar)0x0)) ||
                        ((pRVar26[0x1ac] != (Radar)0x0 && (pRVar26[0x1a4] == (Radar)0x0)))))) {
                      if (*(KIPlayer **)(pRVar26 + 8) != pKVar42) {
                        *(undefined4 *)(pRVar26 + 0x194) = 0;
                      }
LAB_001567a8:
                      *(KIPlayer **)(pRVar26 + 8) = pKVar42;
                      local_108 = (Radar *)0x1;
                    }
                  }
                }
              }
            }
            if (((pRVar26[0x1ab] != (Radar)0x0) && (*(int *)(pRVar26 + 0x1c) == 0)) &&
               ((puVar9 == (undefined4 *)0x1 && (iVar7 = KIPlayer::isDead(pKVar42), iVar7 == 1)))) {
              *(KIPlayer **)(pRVar26 + 0x1c) = pKVar42;
              *(KIPlayer **)(pRVar26 + 8) = pKVar42;
              local_108 = (Radar *)0x1;
            }
          }
        }
        else {
LAB_00156244:
          if (((*(int *)(pKVar42 + 0x24) == 10) &&
              (((iVar7 = Player::isActive(*(Player **)(pKVar42 + 4)), iVar7 == 1 &&
                (iVar7 = KIPlayer::isDead(pKVar42), iVar7 == 0)) &&
               (iVar7 = KIPlayer::isDying(pKVar42), iVar7 == 0)))) &&
             (*(int *)(pRVar26 + 0x1b8) = *(int *)(pRVar26 + 0x1b8) + 1,
             *(int *)(pKVar42 + 0x24) == 10)) {
            pRVar25 = (Radar *)0x1;
          }
        }
        puVar17 = *(uint **)(pRVar26 + 0x134);
        uVar37 = uVar37 + 1;
      } while (uVar37 < *puVar17);
    }
    pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
    iVar7 = PlayerEgo::isDockingToAsteroid(pPVar8);
    local_118 = (Radar *)((uint)pRVar25 & 1);
    local_110 = (Radar *)((uint)local_f0 & 1);
    local_f8 = (Radar *)((uint)local_108 & 1);
    if (iVar7 == 0) {
      pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
      iVar7 = PlayerEgo::isDockingToDockingPoint(pPVar8);
      if ((iVar7 == 0 && local_e0 == 0) && local_e8 == (undefined4 *)0x0) {
        pKVar42 = *(KIPlayer **)(pRVar26 + 8);
        if ((pKVar42 == (KIPlayer *)0x0) || (pKVar42[0x48] == (KIPlayer)0x0)) {
          iVar7 = 0;
          fVar44 = extraout_s0_00;
        }
        else {
          iVar7 = KIPlayer::isDead(pKVar42);
          if (iVar7 == 0) {
            iVar7 = KIPlayer::isDying(*(KIPlayer **)(pRVar26 + 8));
            fVar44 = extraout_s0_02;
          }
          else {
            iVar7 = 1;
            fVar44 = extraout_s0_01;
          }
        }
        if ((*(KIPlayer **)local_fc != (KIPlayer *)0x0) &&
           ((iVar40 = KIPlayer::isDying(*(KIPlayer **)local_fc), fVar44 = extraout_s0_03,
            iVar40 != 0 ||
            (iVar40 = KIPlayer::isDead(*(KIPlayer **)local_fc), fVar44 = extraout_s0_04, iVar40 == 1
            )))) {
          *(undefined4 *)local_fc = 0;
        }
        if (local_f8 == (Radar *)0x0) {
          if (iVar7 == 1) {
            iVar7 = *(int *)(pRVar26 + 0x1c);
          }
          else {
            iVar7 = *(int *)local_fc;
          }
          if (iVar7 == 0) {
            *(undefined4 *)(pRVar26 + 8) = 0;
          }
          local_f8 = (Radar *)0x0;
          *(undefined4 *)(pRVar26 + 0x194) = 0;
        }
        else {
          iVar40 = *(int *)(pRVar26 + 0x194) + local_10c;
          *(int *)(pRVar26 + 0x194) = iVar40;
          if ((iVar7 == 0) && (*(char *)(*(int *)(pRVar26 + 8) + 0x20) == '\0')) {
            pRVar25 = pRVar26 + 0x1b4;
          }
          else {
            pRVar25 = pRVar26 + 0x1b0;
          }
          if (*(int *)pRVar25 < iVar40) {
            if (iVar7 == 1) {
              iVar40 = *(int *)(pRVar26 + 8);
LAB_00156916:
              *(int *)(pRVar26 + 0x1c) = iVar40;
              if (pRVar26[0x1a9] == (Radar)0x0) {
                iVar40 = Level::getPlayer(*(Level **)pRVar26);
                Hud::hudEvent((int)local_114,(PlayerEgo *)0x9,iVar40);
                *(undefined4 *)(local_dc + 0x1c) = 0;
                pRVar26 = local_dc;
              }
            }
            else {
              iVar40 = *(int *)(pRVar26 + 8);
              if (*(char *)(iVar40 + 0x20) != '\0') goto LAB_00156916;
              if (*(int *)local_fc != iVar40) {
                FModSound::play(Globals::sound,0x1a,(Vector *)0x0,(Vector *)0x0,fVar44);
                *(undefined4 *)(pRVar26 + 4) = *(undefined4 *)(pRVar26 + 8);
                if (pRVar26[0x1a5] != (Radar)0x0) {
                  Player::getPosition();
                  AbyssEngine::AEMath::Vector::operator=
                            ((Vector *)(local_dc + 0x16c),(Vector *)&local_98);
                  Player::getPosition();
                  pRVar26 = local_dc;
                  AbyssEngine::AEMath::Vector::operator=
                            ((Vector *)(local_dc + 0x178),(Vector *)&local_98);
                  fVar44 = *(float *)(pRVar26 + 0x16c) - *(float *)(pRVar26 + 0x178);
                  uVar37 = in_fpscr & 0xfffffff;
                  in_fpscr = uVar37;
                  if (((((fVar44 < 24000.0) ||
                        (uVar18 = uVar37 | (uint)(fVar44 < -24000.0) << 0x1f |
                                  (uint)(fVar44 == -24000.0) << 0x1e,
                        in_fpscr = uVar18 | (uint)NAN(fVar44) << 0x1c,
                        bVar3 = (byte)(uVar18 >> 0x18),
                        !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) ||
                       (fVar44 = *(float *)(pRVar26 + 0x170) - *(float *)(pRVar26 + 0x17c),
                       in_fpscr = uVar37, fVar44 < 24000.0)) ||
                      ((uVar18 = uVar37 | (uint)(fVar44 < -24000.0) << 0x1f |
                                 (uint)(fVar44 == -24000.0) << 0x1e,
                       in_fpscr = uVar18 | (uint)NAN(fVar44) << 0x1c, bVar3 = (byte)(uVar18 >> 0x18)
                       , !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1) ||
                       (fVar44 = *(float *)(pRVar26 + 0x174) - *(float *)(pRVar26 + 0x180),
                       in_fpscr = uVar37, fVar44 < 24000.0)))) ||
                     (uVar37 = uVar37 | (uint)(fVar44 < -24000.0) << 0x1f |
                               (uint)(fVar44 == -24000.0) << 0x1e,
                     in_fpscr = uVar37 | (uint)NAN(fVar44) << 0x1c, bVar3 = (byte)(uVar37 >> 0x18),
                     !(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) {
                    puVar17 = *(uint **)(*(int *)local_fc + 0x4c);
                    if (puVar17 == (uint *)0x0) {
                      iVar40 = Level::getPlayer(*(Level **)pRVar26);
                      Hud::hudEvent((int)local_114,(PlayerEgo *)&DAT_00000016,iVar40);
                    }
                    else if (*puVar17 != 0) {
                      piVar14 = (int *)puVar17[1];
                      uVar37 = 0;
                      do {
                        if (0 < piVar14[uVar37 + 1]) {
                          Hud::catchCargo(local_114,*piVar14,piVar14[1],false,false,false,true,false
                                         );
                          break;
                        }
                        uVar37 = uVar37 + 2;
                      } while (uVar37 < *puVar17);
                    }
                  }
                }
              }
            }
            iVar40 = 0;
            *(undefined4 *)(pRVar26 + 0x194) = 0;
          }
          if ((iVar7 == 0) && (*(char *)(*(int *)(pRVar26 + 8) + 0x20) == '\0')) {
            iVar19 = 0;
          }
          else {
            iVar19 = 500;
          }
          if ((iVar19 < iVar40) && (iVar40 = *(int *)(pRVar26 + 8), iVar40 != 0)) {
            if ((iVar7 != 0) || (pRVar25 = local_fc, *(char *)(iVar40 + 0x20) != '\0')) {
              pRVar25 = pRVar26 + 0x1c;
            }
            if (iVar40 != *(int *)pRVar25) {
              pSVar36 = *(Sprite **)(pRVar26 + 0xf4);
              iVar40 = Sprite::getRawFrameCount(pSVar36);
              fVar44 = (float)VectorSignedToFloat(iVar40 + -1,(byte)(in_fpscr >> 0x16) & 3);
              iVar40 = *(int *)(pRVar26 + 0x194);
              if (iVar7 == 1) {
                fVar47 = (float)VectorSignedToFloat(iVar40 + -500,(byte)(in_fpscr >> 0x16) & 3);
LAB_00156e30:
                iVar7 = *(int *)(local_dc + 0x1b0) + -500;
                pRVar26 = local_dc;
              }
              else {
                bVar43 = *(char *)(*(int *)(pRVar26 + 8) + 0x20) != '\0';
                if (bVar43) {
                  iVar40 = iVar40 + -500;
                }
                fVar47 = (float)VectorSignedToFloat(iVar40,(byte)(in_fpscr >> 0x16) & 3);
                if (bVar43) goto LAB_00156e30;
                iVar7 = *(int *)(pRVar26 + 0x1b4);
              }
              fVar46 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
              Sprite::setFrame(pSVar36,(int)(fVar44 * (fVar47 / fVar46)));
              uVar45 = Sprite::setRefPixelPosition
                                 (*(Sprite **)(pRVar26 + 0xf4),
                                  (int)(float)PlayerEgo::crosshairPos._0_4_,
                                  (int)(float)PlayerEgo::crosshairPos._4_4_);
              Sprite::draw((float)uVar45,(float)((ulonglong)uVar45 >> 0x20));
            }
          }
          local_f8 = (Radar *)0x1;
        }
      }
    }
  }
  if ((((*(int *)(pRVar26 + 8) == 0) || (*(int *)local_fc != 0)) && (*(int *)(pRVar26 + 0x1c) == 0))
     && (*(int *)(pRVar26 + 0x24) == 0)) {
    pRVar25 = (Radar *)(uint)(*(int *)(pRVar26 + 0x14) != 0);
  }
  else {
    pRVar25 = (Radar *)0x1;
  }
  puVar17 = *(uint **)(pRVar26 + 0x144);
  if (puVar17 != (uint *)0x0) {
    local_108 = (Radar *)0x0;
    local_11c = pRVar25;
    if (*puVar17 != 0) {
      local_120 = local_dc + 0x178;
      local_124 = local_dc + 0x16c;
      uVar37 = 0;
      local_f4 = local_dc + 0x18c;
      local_100 = (Radar *)&Globals::status;
      local_12c = (float *)&Globals::status;
      local_140 = (Radar *)&Globals::Canvas;
      local_128 = (Radar *)&Globals::Canvas;
      local_138 = &Globals::font;
      local_13c = (uint *)&Globals::Canvas;
      local_130 = (float *)PlayerEgo::crosshairPos;
      local_e8 = &Globals::status;
      puVar41 = PlayerEgo::crosshairPos;
      local_ec = &Globals::status;
      local_108 = (Radar *)0x0;
      local_f0 = (float *)PlayerEgo::crosshairPos;
      pRVar26 = local_dc;
      do {
        this_08 = *(PlayerGasCloud **)(puVar17[1] + uVar37 * 4);
        puVar17 = (uint *)PlayerGasCloud::getSparks(this_08);
        if (puVar17 != (uint *)0x0) {
          pSVar22 = (Ship *)Status::getShip((Status *)*local_e8);
          iVar7 = Ship::getFirstEquipmentOfSort(pSVar22,0x23);
          if ((iVar7 != 0) && (*puVar17 != 0)) {
            uVar18 = 0;
            do {
              AEGeometry::getPosition();
              update(pRVar26,local_b4,uStack_b0,uStack_ac);
              if (pRVar26[0x11c] == (Radar)0x0) {
LAB_001570a8:
                PlayerGasCloud::setSparkInSight(this_08,uVar18,false);
              }
              else {
                iVar7 = *(int *)(pRVar26 + 300);
                fVar44 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
                if (((*(int *)(pRVar26 + 0xfc) <= (int)(*(float *)puVar41 - fVar44)) ||
                    ((int)(*(float *)puVar41 - fVar44) + iVar7 * 2 <= *(int *)(pRVar26 + 0xfc))) ||
                   ((*(int *)(pRVar26 + 0x100) <= (int)(*(float *)((int)puVar41 + 4) - fVar44) ||
                    (iVar7 * 2 + (int)(*(float *)((int)puVar41 + 4) - fVar44) <=
                     *(int *)(pRVar26 + 0x100))))) goto LAB_001570a8;
                AEGeometry::getPosition();
                Level::getPlayer(*(Level **)pRVar26);
                PlayerEgo::getPosition();
                AbyssEngine::AEMath::operator-
                          ((AEMath *)&local_98,(Vector *)aAStack_c0,(Vector *)aSStack_cc);
                fVar44 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_98);
                pSVar22 = (Ship *)Status::getShip((Status *)*local_ec);
                pIVar23 = (Item *)Ship::getFirstEquipmentOfSort(pSVar22,0x23);
                uVar11 = Item::getAttribute(pIVar23,0x33);
                pRVar26 = local_dc;
                fVar47 = (float)VectorSignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
                uVar24 = in_fpscr & 0xfffffff | (uint)(fVar44 == fVar47) << 0x1e |
                         (uint)(fVar47 <= fVar44) << 0x1d;
                bVar3 = (byte)(uVar24 >> 0x18);
                if ((!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6)) &&
                   (iVar7 = PlayerGasCloud::isSparkAlive(this_08,uVar18), iVar7 == 1)) {
                  pRVar26[0x130] = (Radar)0x1;
                }
                in_fpscr = uVar24 & 0xfffffff | (uint)(fVar44 == fVar47) << 0x1e |
                           (uint)(fVar47 <= fVar44) << 0x1d;
                bVar3 = (byte)(in_fpscr >> 0x18);
                PlayerGasCloud::setSparkInSight
                          (this_08,uVar18,
                           (bool)((byte)local_e0 & (!(bool)(bVar3 >> 5 & 1) || (bool)(bVar3 >> 6))))
                ;
                puVar41 = (undefined1 *)local_f0;
              }
              uVar18 = uVar18 + 1;
            } while (uVar18 < *puVar17);
          }
        }
        iVar7 = Player::isActive(*(Player **)(this_08 + 4));
        if ((iVar7 == 1) &&
           (iVar7 = KIPlayer::isDying((KIPlayer *)this_08), pRVar25 = local_f4, iVar7 == 0)) {
          pSVar22 = (Ship *)Status::getShip(*(Status **)local_100);
          pIVar23 = (Item *)Ship::getFirstEquipmentOfSort(pSVar22,0x21);
          iVar7 = Item::getAttribute(pIVar23,0x39);
          if (iVar7 == 1) {
            (**(code **)(*(int *)this_08 + 0x28))(&local_98,this_08);
            update(pRVar26,local_98,uStack_94,uStack_90);
            this_08[0x71] = (PlayerGasCloud)0x0;
            iVar7 = KIPlayer::isDead((KIPlayer *)this_08);
            if ((iVar7 == 0) && (iVar7 = KIPlayer::isDying((KIPlayer *)this_08), iVar7 == 0)) {
              if (pRVar26[0x11c] == (Radar)0x0) {
                pSVar22 = (Ship *)Status::getShip((Status *)*local_12c);
                pIVar23 = (Item *)Ship::getFirstEquipmentOfSort(pSVar22,0x21);
                iVar7 = Item::getAttribute(pIVar23,0x3a);
                if (iVar7 == 1) {
                  this_08[0x72] = (PlayerGasCloud)0x0;
                  this_08[0x6f] = (PlayerGasCloud)0x0;
                  AbyssEngine::PaintCanvas::DrawImage2D
                            (*(PaintCanvas **)local_140,*(uint *)(pRVar26 + 0xc0),
                             *(int *)(pRVar26 + 0xfc),*(int *)(pRVar26 + 0x100),'\x11','D');
                }
              }
              else {
                local_134 = *(Radar **)(pRVar26 + 0x38);
                this_08[0x72] = (PlayerGasCloud)0x1;
                Player::getPosition();
                pRVar27 = local_124;
                AbyssEngine::AEMath::Vector::operator=((Vector *)local_124,(Vector *)&local_98);
                Player::getPosition();
                pRVar28 = local_120;
                AbyssEngine::AEMath::Vector::operator=((Vector *)local_120,(Vector *)&local_98);
                pRVar26 = local_dc;
                fVar44 = *(float *)pRVar27 - *(float *)pRVar28;
                uVar18 = in_fpscr & 0xfffffff;
                uVar24 = uVar18 | (uint)(fVar44 < 24000.0) << 0x1f |
                         (uint)(fVar44 == 24000.0) << 0x1e;
                in_fpscr = uVar24 | (uint)NAN(fVar44) << 0x1c;
                bVar3 = (byte)(uVar24 >> 0x18);
                if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) ||
                   (in_fpscr = uVar18, fVar44 < -24000.0)) {
LAB_001571cc:
                  this_08[0x6f] = (PlayerGasCloud)0x0;
                }
                else {
                  fVar44 = *(float *)(local_dc + 0x170) - *(float *)(local_dc + 0x17c);
                  uVar24 = uVar18 | (uint)(fVar44 < 24000.0) << 0x1f |
                           (uint)(fVar44 == 24000.0) << 0x1e;
                  in_fpscr = uVar24 | (uint)NAN(fVar44) << 0x1c;
                  bVar3 = (byte)(uVar24 >> 0x18);
                  if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) ||
                     (in_fpscr = uVar18, fVar44 < -24000.0)) goto LAB_001571cc;
                  fVar44 = *(float *)(local_dc + 0x174) - *(float *)(local_dc + 0x180);
                  uVar24 = uVar18 | (uint)(fVar44 < 24000.0) << 0x1f |
                           (uint)(fVar44 == 24000.0) << 0x1e;
                  in_fpscr = uVar24 | (uint)NAN(fVar44) << 0x1c;
                  bVar3 = (byte)(uVar24 >> 0x18);
                  if ((!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) ||
                     (in_fpscr = uVar18, fVar44 < -24000.0)) goto LAB_001571cc;
                }
                AbyssEngine::PaintCanvas::DrawImage2D
                          (*(PaintCanvas **)local_128,*(uint *)(local_dc + 0x8c),
                           *(int *)(local_dc + 0xfc),*(int *)(local_dc + 0x100),'\x11','D');
                this_08[0x6f] = (PlayerGasCloud)0x0;
                if (this_08 == (PlayerGasCloud *)local_134) {
                  calcDistance(*(float *)(pRVar26 + 0x180),extraout_s1_03,
                               *(float *)(pRVar26 + 0x238),extraout_s3_03,
                               *(float *)(pRVar26 + 0x23c),extraout_s5_03);
                  AbyssEngine::String::operator=((String *)pRVar25,(String *)&local_98);
                  AbyssEngine::String::~String((String *)&local_98);
                  AbyssEngine::PaintCanvas::DrawString
                            ((PaintCanvas *)*local_13c,*local_138,pRVar25,
                             *(int *)(pRVar26 + 0xfc) - *(int *)(pRVar26 + 0x224),
                             *(int *)(pRVar26 + 0x21c) + *(int *)(pRVar26 + 0x100),false);
                }
                pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
                iVar7 = PlayerEgo::isAutoPilot(pPVar8);
                if ((iVar7 == 0 && local_11c == (Radar *)0x0) && local_f8 == (Radar *)0x0) {
                  iVar7 = *(int *)(pRVar26 + 0x124);
                  fVar44 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
                  if (((((int)(*local_130 - fVar44) < *(int *)(pRVar26 + 0xfc)) &&
                       (*(int *)(pRVar26 + 0xfc) < (int)(*local_130 - fVar44) + iVar7 * 2)) &&
                      ((int)(local_130[1] - fVar44) < *(int *)(pRVar26 + 0x100))) &&
                     (((*(int *)(pRVar26 + 0x100) < iVar7 * 2 + (int)(local_130[1] - fVar44) &&
                       (this_08[0x71] = (PlayerGasCloud)0x1, pRVar26[0x1ac] != (Radar)0x0)) &&
                      (pRVar26[0x1a4] == (Radar)0x0)))) {
                    if (*(PlayerGasCloud **)(pRVar26 + 0x3c) != this_08) {
                      *(undefined4 *)(pRVar26 + 0x148) = 0;
                    }
                    *(PlayerGasCloud **)(pRVar26 + 0x3c) = this_08;
                    local_108 = (Radar *)0x1;
                  }
                }
              }
            }
          }
        }
        puVar17 = *(uint **)(pRVar26 + 0x144);
        uVar37 = uVar37 + 1;
      } while (uVar37 < *puVar17);
    }
    pRVar26 = local_dc;
    if (local_e0 == 0 && local_f8 == (Radar *)0x0) {
      if (*(KIPlayer **)(local_dc + 0x38) != (KIPlayer *)0x0) {
        iVar7 = KIPlayer::isDead(*(KIPlayer **)(local_dc + 0x38));
        if (iVar7 == 0) {
          iVar7 = *(int *)(pRVar26 + 0x38);
        }
        else {
          iVar7 = 0;
          *(undefined4 *)(pRVar26 + 0x38) = 0;
        }
        if (iVar7 == *(int *)(pRVar26 + 0x3c)) {
          pRVar26[0x214] = (Radar)0x1;
        }
        *(undefined4 *)(pRVar26 + 0x38) = 0;
      }
      if (((uint)local_108 & 1) == 0) {
        *(undefined4 *)(pRVar26 + 0x3c) = 0;
        *(undefined4 *)(pRVar26 + 0x148) = 0;
      }
      else {
        iVar7 = *(int *)(pRVar26 + 0x148) + local_10c;
        *(int *)(pRVar26 + 0x148) = iVar7;
        if (*(int *)(pRVar26 + 0x1b4) + -200 < iVar7) {
          if ((pRVar26[0x214] == (Radar)0x0) &&
             (iVar7 = FModSound::isPlaying(Globals::sound,0), iVar7 == 0)) {
            FModSound::play(Globals::sound,0x1a,(Vector *)0x0,(Vector *)0x0,extraout_s0_06);
          }
          iVar40 = *(int *)(local_dc + 0x3c);
          *(int *)(local_dc + 0x38) = iVar40;
          iVar7 = *(int *)(local_dc + 0x148);
        }
        else {
          iVar40 = 0;
        }
        if (500 < iVar7) {
          pSVar36 = *(Sprite **)(local_dc + 0xf4);
          iVar19 = *(int *)(local_dc + 0x3c);
          iVar7 = Sprite::getRawFrameCount(pSVar36);
          if ((iVar19 == 0) || (iVar19 == iVar40)) {
            Sprite::setFrame(pSVar36,iVar7 + -1);
            uVar45 = Sprite::setRefPixelPosition
                               (*(Sprite **)(local_dc + 0xf4),
                                (int)(float)PlayerEgo::crosshairPos._0_4_,
                                (int)(float)PlayerEgo::crosshairPos._4_4_);
          }
          else {
            fVar44 = (float)VectorSignedToFloat(*(int *)(local_dc + 0x1b4) + -500,
                                                (byte)(in_fpscr >> 0x16) & 3);
            fVar47 = (float)VectorSignedToFloat(*(int *)(local_dc + 0x148) + -500,
                                                (byte)(in_fpscr >> 0x16) & 3);
            fVar46 = (float)VectorSignedToFloat(iVar7 + -1,(byte)(in_fpscr >> 0x16) & 3);
            iVar40 = (int)(fVar46 * (fVar47 / fVar44));
            iVar7 = Sprite::getRawFrameCount(*(Sprite **)(local_dc + 0xf4));
            pRVar26 = local_dc;
            if (iVar7 + -1 <= iVar40) goto LAB_001574b4;
            Sprite::setFrame(*(Sprite **)(local_dc + 0xf4),iVar40);
            uVar45 = Sprite::setRefPixelPosition
                               (*(Sprite **)(pRVar26 + 0xf4),
                                (int)(float)PlayerEgo::crosshairPos._0_4_,
                                (int)(float)PlayerEgo::crosshairPos._4_4_);
          }
          Sprite::draw((float)uVar45,(float)((ulonglong)uVar45 >> 0x20));
        }
      }
    }
  }
LAB_001574b4:
  pRVar26 = local_dc;
  __aeabi_memset4(*(undefined4 *)(local_dc + 0x58),0x14,0xff);
  if ((((*(int *)(pRVar26 + 8) == 0) || (*(int *)local_fc != 0)) && (*(int *)(pRVar26 + 0x1c) == 0))
     && (*(int *)(pRVar26 + 0x24) == 0)) {
    pRVar25 = (Radar *)(uint)(*(int *)(pRVar26 + 0x14) != 0);
  }
  else {
    pRVar25 = (Radar *)0x1;
  }
  pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
  iVar7 = PlayerEgo::isInDockingProcedure(pPVar8);
  if ((iVar7 == 0) && (puVar17 = *(uint **)(pRVar26 + 0x13c), puVar17 != (uint *)0x0)) {
    if (pRVar26[0x1a6] == (Radar)0x0) {
      local_e8 = (undefined4 *)0x0;
    }
    else {
      this_06 = *(Level **)local_dc;
      Level::getPlayer(this_06);
      PlayerEgo::getPosition();
      local_e8 = (undefined4 *)Level::isInAsteroidCenterRange(this_06,local_d8,uStack_d4,uStack_d0);
      puVar17 = *(uint **)(local_dc + 0x13c);
    }
    if (*puVar17 == 0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      uVar37 = 0;
      puVar9 = (undefined4 *)0x0;
      local_f0 = (float *)&Globals::Canvas;
      local_ec = &Globals::Canvas;
      local_fc = (Radar *)PlayerEgo::crosshairPos;
      local_100 = (Radar *)0x0;
      local_f4 = pRVar25;
      do {
        pKVar42 = *(KIPlayer **)(puVar17[1] + uVar37 * 4);
        if (((pKVar42[0x48] != (KIPlayer)0x0) &&
            ((iVar7 = KIPlayer::isDead(pKVar42), iVar7 != 0 ||
             (iVar7 = KIPlayer::isDying(pKVar42), iVar7 != 0)))) ||
           ((iVar7 = KIPlayer::isDead(pKVar42), iVar7 == 0 &&
            (iVar7 = KIPlayer::isDying(pKVar42), iVar7 == 0)))) {
          (**(code **)(*(int *)pKVar42 + 0x28))(&local_98,pKVar42);
          update(local_dc,local_98,uStack_94,uStack_90);
          if (pKVar42[0x48] == (KIPlayer)0x0) {
            uVar18 = 0;
          }
          else {
            iVar7 = KIPlayer::isDead(pKVar42);
            if (iVar7 == 0) {
              uVar18 = KIPlayer::isDying(pKVar42);
            }
            else {
              uVar18 = 1;
            }
          }
          pRVar26 = local_dc;
          pfVar10 = local_f0;
          if (local_dc[0x11c] == (Radar)0x0) {
            if (uVar18 == 1) {
              AbyssEngine::PaintCanvas::DrawImage2D
                        ((PaintCanvas *)*local_f0,*(uint *)(local_dc + 0x8c),
                         *(int *)(local_dc + 0xfc),*(int *)(local_dc + 0x100),'\x11','D');
              pRVar25 = local_f4;
              pRVar27 = pRVar26 + 0xac;
              if (((pRVar26[0x11d] == (Radar)0x0) || (pRVar26[0x11f] != (Radar)0x0)) ||
                 (pRVar26[0x120] != (Radar)0x0)) {
                uVar1 = *(ushort *)(pRVar26 + 0x11e) >> 8;
                if ((*(ushort *)(pRVar26 + 0x11e) & 0xff) == 0) {
                  iVar7 = *(int *)(pRVar26 + 0xfc);
                  if (uVar1 != 0) goto LAB_0015775a;
                  goto LAB_00157858;
                }
                pRVar26 = local_dc;
                if (uVar1 == 0) {
                  iVar7 = *(int *)(local_dc + 0xfc);
                  if (local_dc[0x120] == (Radar)0x0) {
                    iVar7 = iVar7 + -0xb;
                  }
                  goto LAB_00157858;
                }
                iVar7 = *(int *)(local_dc + 0xfc);
LAB_0015775a:
                iVar40 = *(int *)(pRVar26 + 0x100) + 0xb;
              }
              else {
                iVar7 = *(int *)(pRVar26 + 0xfc) + 0xb;
LAB_00157858:
                iVar40 = *(int *)(pRVar26 + 0x100);
                if (pRVar26[0x120] != (Radar)0x0) {
                  iVar40 = iVar40 + -0xb;
                }
              }
              AbyssEngine::PaintCanvas::DrawImage2D
                        ((PaintCanvas *)*pfVar10,*(uint *)pRVar27,iVar7,iVar40,'\x11','D');
            }
          }
          else {
            pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)local_dc);
            uVar24 = PlayerEgo::isAutoPilot(pPVar8);
            if (((uVar24 | (uint)pRVar25 | (uint)local_f8 | (uint)puVar9 | local_e0) & 1) == 0) {
              iVar7 = PlayerAsteroid::isMinable((PlayerAsteroid *)pKVar42);
              if ((iVar7 == 1) && (local_dc[0x1a4] == (Radar)0x0)) {
                iVar7 = 0;
                if (uVar18 == 1) {
                  iVar7 = *(int *)(local_dc + 0x1c);
                }
                if ((uVar18 == 1 && iVar7 == 0) && (local_dc[0x1aa] != (Radar)0x0)) {
                  *(KIPlayer **)(local_dc + 0x1c) = pKVar42;
                  puVar9 = (undefined4 *)0x1;
                  *(KIPlayer **)(local_dc + 8) = pKVar42;
                  goto LAB_001577de;
                }
                iVar7 = *(int *)(local_dc + 0x124);
                fVar44 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
                if (((int)(*(float *)local_fc - fVar44) < *(int *)(local_dc + 0xfc)) &&
                   (*(int *)(local_dc + 0xfc) < (int)(*(float *)local_fc - fVar44) + iVar7 * 2)) {
                  puVar9 = (undefined4 *)0x0;
                  if ((*(int *)(local_dc + 0x100) <= (int)(*(float *)(local_fc + 4) - fVar44)) ||
                     (iVar7 * 2 + (int)(*(float *)(local_fc + 4) - fVar44) <=
                      *(int *)(local_dc + 0x100))) goto LAB_001577de;
                  if (pKVar42[0x120] == (KIPlayer)0x0) {
                    puVar9 = (undefined4 *)0x0;
                    if ((3 < (int)local_100) || (local_dc[0x1ac] == (Radar)0x0)) goto LAB_001577de;
                    *(uint *)(*(int *)(local_dc + 0x58) + (int)local_100 * 4) = uVar37;
                    local_100 = local_100 + 1;
                  }
                }
              }
              puVar9 = (undefined4 *)0x0;
            }
LAB_001577de:
            if ((local_e8 == (undefined4 *)0x1) &&
               (iVar7 = PlayerAsteroid::getQualityFrameIndex((PlayerAsteroid *)pKVar42),
               pRVar26 = local_dc, iVar7 == 0)) {
              Sprite::setFrame(*(Sprite **)(local_dc + 0xf8),0);
              uVar45 = Sprite::setPosition(*(Sprite **)(pRVar26 + 0xf8),*(int *)(pRVar26 + 0xfc),
                                           *(int *)(pRVar26 + 0x100));
              Sprite::draw((float)uVar45,(float)((ulonglong)uVar45 >> 0x20));
            }
            if (uVar18 == 1) {
              AbyssEngine::PaintCanvas::DrawImage2D
                        ((PaintCanvas *)*local_ec,*(uint *)(local_dc + 0x9c),
                         *(int *)(local_dc + 0xfc),*(int *)(local_dc + 0x100),'\x11','D');
            }
          }
          if ((local_dc[0x1ab] != (Radar)0x0) && (*(int *)(local_dc + 0x1c) == 0)) {
            pRVar27 = (Radar *)(uVar18 ^ 1);
            pRVar26 = pRVar27;
            if (pRVar27 == (Radar *)0x0) {
              pRVar26 = local_dc;
            }
            if (pRVar27 == (Radar *)0x0) {
              *(KIPlayer **)(pRVar26 + 0x1c) = pKVar42;
              *(KIPlayer **)(pRVar26 + 8) = pKVar42;
              puVar9 = (undefined4 *)0x1;
            }
          }
        }
        uVar37 = uVar37 + 1;
        puVar17 = *(uint **)(local_dc + 0x13c);
      } while (uVar37 < *puVar17);
    }
    this_09 = (Vector *)(local_dc + 0x160);
    this_07 = (Vector *)(local_dc + 0x154);
    iVar7 = 999999;
    iVar40 = -1;
    iVar19 = 0;
    local_e8 = puVar9;
    do {
      iVar39 = *(int *)(*(int *)(local_dc + 0x58) + iVar19 * 4);
      if (-1 < iVar39) {
        (**(code **)(**(int **)(*(int *)(*(int *)(local_dc + 0x13c) + 4) + iVar39 * 4) + 0x28))
                  ((Vector *)&local_98);
        AbyssEngine::AEMath::Vector::operator=(this_07,(Vector *)&local_98);
        Player::getPosition();
        AbyssEngine::AEMath::Vector::operator=(this_09,(Vector *)&local_98);
        AbyssEngine::AEMath::Vector::operator-=(this_07,this_09);
        fVar44 = (float)AbyssEngine::AEMath::VectorLength(this_07);
        if ((int)fVar44 < iVar7) {
          iVar7 = (int)fVar44;
          iVar40 = iVar39;
        }
      }
      iVar19 = iVar19 + 1;
    } while (iVar19 != 5);
    puVar9 = local_e8;
    if (-1 < iVar40) {
      puVar9 = (undefined4 *)0x1;
      iVar7 = *(int *)(*(int *)(*(int *)(local_dc + 0x13c) + 4) + iVar40 * 4);
      if (*(int *)(local_dc + 0x10) != iVar7) {
        *(undefined4 *)(local_dc + 0x198) = 0;
      }
      *(int *)(local_dc + 0x10) = iVar7;
    }
    if (local_e0 == 0 && local_f8 == (Radar *)0x0) {
      if (*(KIPlayer **)local_104 == (KIPlayer *)0x0) {
        pRVar26 = local_dc + 0x10;
        pKVar42 = *(KIPlayer **)pRVar26;
      }
      else {
        iVar7 = KIPlayer::isDead(*(KIPlayer **)local_104);
        if (iVar7 == 0) {
          pKVar34 = *(KIPlayer **)local_104;
        }
        else {
          pKVar34 = (KIPlayer *)0x0;
          *(undefined4 *)local_104 = 0;
        }
        pRVar26 = local_dc + 0x10;
        pKVar42 = *(KIPlayer **)pRVar26;
        if (pKVar34 == pKVar42) {
          local_dc[0x214] = (Radar)0x1;
        }
        *(undefined4 *)local_104 = 0;
      }
      if ((pKVar42 == (KIPlayer *)0x0) || (pKVar42[0x48] == (KIPlayer)0x0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = KIPlayer::isDead(pKVar42);
        if (iVar7 == 0) {
          iVar7 = KIPlayer::isDying(*(KIPlayer **)pRVar26);
        }
        else {
          iVar7 = 1;
        }
      }
      if (((uint)puVar9 & 1) != 0) {
        pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)local_dc);
        iVar40 = PlayerEgo::isDockingToAsteroid(pPVar8);
        pRVar25 = local_dc;
        if (iVar40 == 0) {
          iVar40 = *(int *)(local_dc + 0x198) + local_10c;
          *(int *)(local_dc + 0x198) = iVar40;
          if (*(int *)(local_dc + 0x1b4) + -200 < iVar40) {
            if (iVar7 == 1) {
              if (local_dc[0x1a9] == (Radar)0x0) {
                iVar40 = Level::getPlayer(*(Level **)local_dc);
                pPVar8 = (PlayerEgo *)0x9;
LAB_00157b8e:
                Hud::hudEvent((int)local_114,pPVar8,iVar40);
              }
              else {
                *(undefined4 *)(local_dc + 0x1c) = *(undefined4 *)pRVar26;
              }
            }
            else {
              if (local_dc[0x1a8] == (Radar)0x0) {
                iVar40 = Level::getPlayer(*(Level **)local_dc);
                pPVar8 = (PlayerEgo *)0x14;
                goto LAB_00157b8e;
              }
              if ((local_dc[0x214] == (Radar)0x0) &&
                 (iVar40 = FModSound::isPlaying(Globals::sound,0), iVar40 == 0)) {
                FModSound::play(Globals::sound,0x1a,(Vector *)0x0,(Vector *)0x0,extraout_s0_07);
              }
              *(undefined4 *)local_104 = *(undefined4 *)pRVar26;
              pRVar25 = local_dc;
            }
            iVar40 = *(int *)(pRVar25 + 0x198);
          }
          pRVar25 = local_dc;
          if (iVar40 < 0x1f5) goto LAB_00157c6c;
          if (*(int *)pRVar26 == 0) {
LAB_00157c20:
            pSVar36 = *(Sprite **)(local_dc + 0xf4);
            iVar7 = Sprite::getRawFrameCount(pSVar36);
            Sprite::setFrame(pSVar36,iVar7 + -1);
          }
          else {
            pRVar27 = local_104;
            if (iVar7 != 0) {
              pRVar27 = local_dc + 0x1c;
            }
            if (*(int *)pRVar26 == *(int *)pRVar27) goto LAB_00157c20;
            iVar7 = Sprite::getRawFrameCount(*(Sprite **)(local_dc + 0xf4));
            fVar44 = (float)VectorSignedToFloat(*(int *)(pRVar25 + 0x1b4) + -500,
                                                (byte)(in_fpscr >> 0x16) & 3);
            fVar47 = (float)VectorSignedToFloat(*(int *)(pRVar25 + 0x198) + -500,
                                                (byte)(in_fpscr >> 0x16) & 3);
            fVar46 = (float)VectorSignedToFloat(iVar7 + -1,(byte)(in_fpscr >> 0x16) & 3);
            iVar40 = (int)(fVar46 * (fVar47 / fVar44));
            iVar7 = Sprite::getRawFrameCount(*(Sprite **)(pRVar25 + 0xf4));
            pRVar25 = local_dc;
            if (iVar7 + -1 <= iVar40) goto LAB_00157c6c;
            Sprite::setFrame(*(Sprite **)(local_dc + 0xf4),iVar40);
          }
          uVar45 = Sprite::setRefPixelPosition
                             (*(Sprite **)(pRVar25 + 0xf4),(int)(float)PlayerEgo::crosshairPos._0_4_
                              ,(int)(float)PlayerEgo::crosshairPos._4_4_);
          Sprite::draw((float)uVar45,(float)((ulonglong)uVar45 >> 0x20));
          goto LAB_00157c6c;
        }
      }
      if (iVar7 == 1) {
        iVar7 = *(int *)(local_dc + 0x1c);
      }
      else {
        iVar7 = *(int *)local_104;
      }
      if (iVar7 == 0) {
        *(undefined4 *)(local_dc + 0x10) = 0;
        *(undefined4 *)(local_dc + 0x198) = 0;
      }
      else {
        *(undefined4 *)(local_dc + 0x198) = 0;
      }
    }
  }
  else {
    pPVar8 = (PlayerEgo *)Level::getPlayer(*(Level **)pRVar26);
    iVar7 = PlayerEgo::isDockingToAsteroid(pPVar8);
    if ((iVar7 == 1) && (*(int **)local_104 != (int *)0x0)) {
      (**(code **)(**(int **)local_104 + 0x28))((Vector *)&local_98);
      pRVar26 = local_dc;
      AbyssEngine::AEMath::Vector::operator=((Vector *)(local_dc + 0x16c),(Vector *)&local_98);
      calcDistance(*(float *)(pRVar26 + 0x174),extraout_s1_04,*(float *)(pRVar26 + 0x238),
                   extraout_s3_04,*(float *)(pRVar26 + 0x23c),extraout_s5_04);
      AbyssEngine::String::operator=((String *)(pRVar26 + 0x18c),(String *)&local_98);
      AbyssEngine::String::~String((String *)&local_98);
      fVar44 = (float)VectorSignedToFloat(*(undefined4 *)(pRVar26 + 0x21c),
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar47 = (float)VectorSignedToFloat(*(undefined4 *)(pRVar26 + 0x224),
                                          (byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,(String *)(pRVar26 + 0x18c),
                 (int)((float)PlayerEgo::crosshairPos._0_4_ - fVar47),
                 (int)((float)PlayerEgo::crosshairPos._4_4_ + fVar44),false);
    }
  }
LAB_00157c6c:
  pRVar26 = local_dc;
  this_00 = Globals::sound;
  iVar7 = *(int *)Globals::sound;
  if (iVar7 == 0x8f) goto LAB_00157d4a;
  if (*(int *)(local_dc + 0x1b8) < 1) {
    local_dc[0x54] = (Radar)0x0;
    iVar7 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar7 != 0x91) {
      iVar7 = *(int *)Globals::sound;
      if (((0x19 < iVar7 - 0x7fU) || ((1 << (iVar7 - 0x7fU & 0xff) & 0x23c1c8fU) == 0)) &&
         (4 < iVar7 - 0x8beU)) {
        FModSound::stop(Globals::sound,iVar7);
        iVar7 = Status::inAlienOrbit(Globals::status);
        fVar44 = extraout_s0_11;
        if (iVar7 == 0) {
          pSVar15 = (Station *)Status::getStation(Globals::status);
          iVar7 = Station::isAttackedByAliens(pSVar15);
          fVar44 = extraout_s0_12;
          if (iVar7 != 1) {
            iVar7 = Status::getCurrentCampaignMission(Globals::status);
            if (iVar7 == 1) {
              iVar7 = 0x8f;
              fVar44 = extraout_s0_13;
              goto LAB_00157cf4;
            }
            pSVar16 = (SolarSystem *)Status::getSystem(Globals::status);
            iVar7 = SolarSystem::getRace(pSVar16);
            pSVar15 = (Station *)Status::getStation(Globals::status);
            iVar40 = Station::getIndex(pSVar15);
            if (iVar40 == 0x6c) {
              iVar7 = 0x92;
              fVar44 = extraout_s0_14;
            }
            else {
              pSVar15 = (Station *)Status::getStation(Globals::status);
              iVar40 = Station::getIndex(pSVar15);
              if (iVar40 == 0x65) {
                iVar7 = 0x93;
                fVar44 = extraout_s0_15;
              }
              else {
                iVar40 = Status::inSupernovaSystem(Globals::status);
                if (iVar40 == 1) {
                  iVar7 = Status::getMission(Globals::status);
                  fVar44 = extraout_s0_16;
                  if (iVar7 != 0) {
                    pMVar6 = (Mission *)Status::getMission(Globals::status);
                    iVar7 = Mission::isEmpty(pMVar6);
                    fVar44 = extraout_s0_17;
                    if (iVar7 == 0) {
                      pMVar6 = (Mission *)Status::getMission(Globals::status);
                      iVar7 = Mission::getTargetStation(pMVar6);
                      pSVar15 = (Station *)Status::getStation(Globals::status);
                      iVar40 = Station::getIndex(pSVar15);
                      fVar44 = extraout_s0_18;
                      if (iVar7 == iVar40) {
                        iVar7 = Status::getCurrentCampaignMission(Globals::status);
                        fVar44 = extraout_s0_19;
                        if (iVar7 < 0x6a) {
                          iVar7 = 0x8c1;
                        }
                        else {
                          iVar7 = 0x8c2;
                        }
                        goto LAB_0015815c;
                      }
                    }
                  }
                  iVar7 = 0x94;
                }
                else {
                  iVar40 = Status::inDeepScienceOrbit(Globals::status);
                  fVar44 = extraout_s0_20;
                  if (iVar40 == 1) {
                    iVar7 = 0x98;
                  }
                  else {
                    iVar7 = *(int *)(&DAT_00252010 + iVar7 * 4);
                  }
                }
              }
            }
LAB_0015815c:
            FModSound::play(Globals::sound,iVar7,(Vector *)0x0,(Vector *)0x0,fVar44);
            pRVar26 = local_dc;
            goto LAB_00157d44;
          }
        }
        iVar7 = 0x91;
        goto LAB_00157cf4;
      }
    }
  }
  else {
    local_dc[0x54] = (Radar)0x1;
    if (((0xf < iVar7 - 0x88U) || ((1 << (iVar7 - 0x88U & 0xff) & 0xe071U) == 0)) ||
       ((iVar7 != 0x97 && (local_110 == (Radar *)0x1)))) {
      FModSound::stop(this_00,iVar7);
      iVar7 = Status::inAlienOrbit(Globals::status);
      fVar44 = extraout_s0_08;
      if (iVar7 == 0) {
        pSVar15 = (Station *)Status::getStation(Globals::status);
        iVar7 = Station::isAttackedByAliens(pSVar15);
        fVar44 = extraout_s0_09;
        if ((iVar7 == 0) &&
           (iVar7 = Status::getCurrentCampaignMission(Globals::status), fVar44 = extraout_s0_10,
           iVar7 != 0x10)) {
          if (*(int *)(pRVar26 + 0x1b8) < 3) {
            if (local_110 == (Radar *)0x1) goto LAB_00157dba;
            if (local_118 == (Radar *)0x1) {
LAB_00157dac:
              iVar7 = 0x95;
            }
            else {
              iVar7 = 0x8c;
            }
          }
          else if (*(int *)(pRVar26 + 0x1b8) < 5) {
            if (local_110 == (Radar *)0x1) {
LAB_00157dba:
              iVar7 = 0x97;
            }
            else {
              if (local_118 == (Radar *)0x1) goto LAB_00157dac;
              iVar7 = 0x8d;
            }
          }
          else {
            if (local_110 == (Radar *)0x1) goto LAB_00157dba;
            if (local_118 == (Radar *)0x1) {
              iVar7 = 0x96;
            }
            else {
              iVar7 = 0x8e;
            }
          }
          goto LAB_00157cf4;
        }
      }
      iVar7 = 0x88;
LAB_00157cf4:
      FModSound::play(Globals::sound,iVar7,(Vector *)0x0,(Vector *)0x0,fVar44);
    }
  }
LAB_00157d44:
  *(undefined4 *)(pRVar26 + 0x1b8) = 0;
LAB_00157d4a:
  if (__stack_chk_guard == local_5c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Radar::calcDistance  @0x0015827c  (526 bytes)
/* Radar::calcDistance(float, float, float, float, float, float) */

void Radar::calcDistance(float param_1,float param_2,float param_3,float param_4,float param_5,
                        float param_6)

{
  AbyssEngine *in_r0;
  float fVar1;
  float in_r2;
  float in_r3;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  float in_stack_00000000;
  float in_stack_00000004;
  float in_stack_00000008;
  float in_stack_0000000c;
  String aSStack_6c [8];
  String aSStack_64 [8];
  undefined4 local_5c [2];
  AbyssEngine aAStack_54 [8];
  String aSStack_4c [8];
  undefined4 local_44 [2];
  int local_3c;
  
  lVar3 = __aeabi_f2lz(in_r3 * 0.5 - in_stack_00000008 * 0.5);
  lVar4 = __aeabi_f2lz(in_stack_00000000 * 0.5 - in_stack_0000000c * 0.5);
  lVar5 = __aeabi_f2lz(in_r2 * 0.5 - in_stack_00000004 * 0.5);
  lVar3 = lVar4 * lVar4 + lVar3 * lVar3 + lVar5 * lVar5;
  fVar1 = (float)__aeabi_l2f((int)lVar3,(int)((ulonglong)lVar3 >> 0x20));
  local_3c = __stack_chk_guard;
  uVar6 = Globals::sqrt(fVar1 * 0.00024414062);
  iVar2 = (int)(float)uVar6;
  local_44[0] = 0;
  AbyssEngine::String::Set(CONCAT44((int)((ulonglong)uVar6 >> 0x20),local_44));
  AbyssEngine::String::String(aSStack_4c,"m",false);
  AbyssEngine::operator+(in_r0,(String *)local_44,aSStack_4c);
  AbyssEngine::String::~String(aSStack_4c);
  AbyssEngine::String::~String((String *)local_44);
  if (999 < iVar2 * 8) {
    if ((uint)(iVar2 * 8) % 1000 < 100) {
      AbyssEngine::String::String((String *)local_44,"0",false);
      AbyssEngine::String::operator=((String *)in_r0,(String *)local_44);
    }
    else {
      local_44[0] = 0;
      AbyssEngine::String::Set(CONCAT44(1000,local_44));
      AbyssEngine::String::operator=((String *)in_r0,(String *)local_44);
    }
    AbyssEngine::String::~String((String *)local_44);
    AbyssEngine::String::SubString((uint)local_44,(uint)in_r0);
    AbyssEngine::String::operator=((String *)in_r0,(String *)local_44);
    AbyssEngine::String::~String((String *)local_44);
    local_5c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(iVar2 / 0x7d + (iVar2 >> 0x1f),local_5c));
    AbyssEngine::String::String(aSStack_64,".",false);
    AbyssEngine::operator+(aAStack_54,(String *)local_5c,aSStack_64);
    AbyssEngine::operator+((AbyssEngine *)aSStack_4c,aAStack_54,in_r0);
    AbyssEngine::String::String(aSStack_6c,"km",false);
    AbyssEngine::operator+((AbyssEngine *)local_44,aSStack_4c,aSStack_6c);
    AbyssEngine::String::operator=((String *)in_r0,(String *)local_44);
    AbyssEngine::String::~String((String *)local_44);
    AbyssEngine::String::~String(aSStack_6c);
    AbyssEngine::String::~String(aSStack_4c);
    AbyssEngine::String::~String((String *)aAStack_54);
    AbyssEngine::String::~String(aSStack_64);
    AbyssEngine::String::~String((String *)local_5c);
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Radar::getPlanetDockIndex  @0x00158524  (32 bytes)
/* Radar::getPlanetDockIndex() */

undefined4 __thiscall Radar::getPlanetDockIndex(Radar *this)

{
  SolarSystem *this_00;
  int iVar1;
  
  this_00 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar1 = SolarSystem::getStations(this_00);
  return *(undefined4 *)(*(int *)(iVar1 + 4) + *(int *)(this + 0x40) * 4);
}

// ===== Radar::drawCurrentLock  @0x00158548  (1648 bytes)
/* Radar::drawCurrentLock(Hud*) */

void Radar::drawCurrentLock(Hud *param_1)

{
  PaintCanvas *this;
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  String *pSVar6;
  undefined4 uVar7;
  SolarSystem *this_00;
  int extraout_r1;
  int extraout_r1_00;
  int iVar8;
  int iVar9;
  Sprite *pSVar10;
  PlayerAsteroid *pPVar11;
  String *this_01;
  PlayerAsteroid *pPVar12;
  PlayerAsteroid *this_02;
  bool bVar13;
  undefined8 uVar14;
  String aSStack_68 [8];
  undefined4 local_60 [2];
  String aSStack_58 [8];
  AbyssEngine aAStack_50 [8];
  String aSStack_48 [8];
  AbyssEngine aAStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1[0x48] == (Hud)0x0) goto LAB_0015860a;
  drawTarget = 1;
  if (*(int *)(param_1 + 0x14) == 0) {
    this_02 = *(PlayerAsteroid **)(param_1 + 0xc);
    if (this_02 == (PlayerAsteroid *)0x0) {
      this_02 = *(PlayerAsteroid **)(param_1 + 0x38);
      bVar13 = this_02 == (PlayerAsteroid *)0x0;
      if (bVar13) {
        this_02 = *(PlayerAsteroid **)(param_1 + 4);
      }
      if ((bVar13 && this_02 == (PlayerAsteroid *)0x0) &&
         (this_02 = *(PlayerAsteroid **)(param_1 + 0x24), this_02 == (PlayerAsteroid *)0x0)) {
        drawTarget = 0;
        goto LAB_0015860a;
      }
    }
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(param_1 + 0xcc),*(int *)(param_1 + 0x20c),
               *(int *)(param_1 + 0x210));
    pPVar11 = *(PlayerAsteroid **)(param_1 + 0xc);
    pPVar12 = *(PlayerAsteroid **)(param_1 + 0x24);
    if (pPVar12 == (PlayerAsteroid *)**(int **)(*(int *)(param_1 + 0x138) + 4)) {
      puVar5 = *(undefined4 **)(*(int *)(param_1 + 0x188) + 4);
    }
    else if (pPVar12 == (PlayerAsteroid *)(*(int **)(*(int *)(param_1 + 0x138) + 4))[3]) {
      puVar5 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x188) + 4) + 0xc);
    }
    else {
      puVar5 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x188) + 4) + 4);
    }
    AbyssEngine::String::String(aSStack_30,(String *)*puVar5,false);
    if (this_02 == *(PlayerAsteroid **)(param_1 + 0x38)) {
      pSVar6 = (String *)GameText::getText(Globals::gameText,0xca4);
      AbyssEngine::String::String(aSStack_38,pSVar6,false);
      iVar3 = Globals::w;
      iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_38);
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,aSStack_38,(iVar3 >> 1) - (iVar4 >> 1),
                 *(int *)(Globals::layout + 0xc4) + *(int *)(param_1 + 0x210),false);
      AbyssEngine::String::~String(aSStack_38);
    }
    else if (this_02 == pPVar11) {
      pSVar6 = (String *)GameText::getText(Globals::gameText,*(int *)(this_02 + 0x124) + 0x4fa);
      AbyssEngine::String::String((String *)aAStack_40,pSVar6,false);
      iVar3 = Globals::w;
      iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_40);
      pSVar10 = *(Sprite **)(param_1 + 0xf8);
      iVar9 = PlayerAsteroid::getQualityFrameIndex(this_02);
      Sprite::setFrame(pSVar10,iVar9);
      pSVar10 = *(Sprite **)(param_1 + 0xf8);
      iVar8 = *(int *)(Globals::layout + 0x2c);
      iVar9 = Sprite::getFrameWidth(pSVar10);
      iVar3 = (iVar3 >> 1) - (iVar4 >> 1);
      uVar14 = Sprite::setPosition(pSVar10,(iVar3 - iVar8) - iVar9,
                                   *(int *)(param_1 + 0x210) + *(int *)(Globals::layout + 0xc0));
      Sprite::draw((float)uVar14,(float)((ulonglong)uVar14 >> 0x20));
      AbyssEngine::PaintCanvas::DrawString
                (Globals::Canvas,Globals::font,aAStack_40,iVar3,
                 *(int *)(Globals::layout + 0xc4) + *(int *)(param_1 + 0x210),false);
      AbyssEngine::String::~String((String *)aAStack_40);
    }
    else {
      AbyssEngine::String::String(aSStack_48);
      this_01 = (String *)(this_02 + 0x18);
      if (*(int *)(this_02 + 0x1c) == 0) {
LAB_00158984:
        if (this_02 == pPVar12) {
          this_01 = aSStack_30;
        }
        else if (*(int *)(this_02 + 0x1c) == 0) {
          this_01 = (String *)GameText::getText(Globals::gameText,*(int *)(this_02 + 0x24) + 0x196);
        }
        AbyssEngine::String::operator=(aSStack_48,this_01);
        if (this_02 == pPVar12) {
          iVar3 = Status::inAlienOrbit(Globals::status);
          if (iVar3 == 1) {
            iVar3 = Status::dlc1Won(Globals::status);
            if (iVar3 == 1) {
              Sprite::setFrame(*(Sprite **)(param_1 + 0xf0),8);
            }
            else {
              Sprite::setFrame(*(Sprite **)(param_1 + 0xf0),9);
            }
          }
          else {
            pSVar10 = *(Sprite **)(param_1 + 0xf0);
            this_00 = (SolarSystem *)Status::getSystem(Globals::status);
            iVar3 = SolarSystem::getRace(this_00);
            Sprite::setFrame(pSVar10,iVar3);
          }
          iVar3 = Globals::w;
          iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_48);
          pSVar10 = *(Sprite **)(param_1 + 0xf0);
          iVar8 = *(int *)(Globals::layout + 0x2c);
          iVar9 = Sprite::getFrameWidth(pSVar10);
          iVar3 = (iVar3 >> 1) - (iVar4 >> 1);
          uVar14 = Sprite::setPosition(pSVar10,(iVar3 - iVar8) - iVar9,
                                       *(int *)(param_1 + 0x210) + *(int *)(Globals::layout + 200));
          Sprite::draw((float)uVar14,(float)((ulonglong)uVar14 >> 0x20));
        }
        else {
          AbyssEngine::String::String(aSStack_58," ",false);
          uVar7 = Player::getDamageRate(*(Player **)(this_02 + 4));
          local_60[0] = 0;
          AbyssEngine::String::Set(CONCAT44(uVar7,local_60));
          AbyssEngine::operator+(aAStack_50,aSStack_58,(String *)local_60);
          AbyssEngine::String::String(aSStack_68,"%",false);
          AbyssEngine::operator+(aAStack_40,aAStack_50,aSStack_68);
          AbyssEngine::String::String(aSStack_38,aAStack_40,false);
          AbyssEngine::String::operator+=(aSStack_48,aSStack_38);
          AbyssEngine::String::~String(aSStack_38);
          AbyssEngine::String::~String((String *)aAStack_40);
          AbyssEngine::String::~String(aSStack_68);
          AbyssEngine::String::~String((String *)aAStack_50);
          AbyssEngine::String::~String((String *)local_60);
          AbyssEngine::String::~String(aSStack_58);
          iVar3 = Globals::w;
          iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_48);
          iVar3 = (iVar3 >> 1) - (iVar4 >> 1);
        }
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,aSStack_48,iVar3,
                   *(int *)(Globals::layout + 0xc4) + *(int *)(param_1 + 0x210),false);
        iVar4 = extraout_r1_00;
      }
      else {
        pSVar6 = (String *)GameText::getText(Globals::gameText,0x64b);
        cVar2 = AbyssEngine::String::Compare(this_01,pSVar6);
        if (cVar2 != '\0') {
          pSVar6 = (String *)GameText::getText(Globals::gameText,0x67f);
          cVar2 = AbyssEngine::String::Compare(this_01,pSVar6);
          if ((cVar2 != '\0') && (this_02[0x3e] == (PlayerAsteroid)0x0)) goto LAB_00158984;
        }
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        AbyssEngine::String::operator=(aSStack_48,this_01);
        if (this_02[0x3e] != (PlayerAsteroid)0x0) {
          AbyssEngine::String::String(aSStack_58," ",false);
          uVar7 = Player::getDamageRate(*(Player **)(this_02 + 4));
          local_60[0] = 0;
          AbyssEngine::String::Set(CONCAT44(uVar7,local_60));
          AbyssEngine::operator+(aAStack_50,aSStack_58,(String *)local_60);
          AbyssEngine::String::String(aSStack_68,"%",false);
          AbyssEngine::operator+(aAStack_40,aAStack_50,aSStack_68);
          AbyssEngine::String::String(aSStack_38,aAStack_40,false);
          AbyssEngine::String::operator+=(aSStack_48,aSStack_38);
          AbyssEngine::String::~String(aSStack_38);
          AbyssEngine::String::~String((String *)aAStack_40);
          AbyssEngine::String::~String(aSStack_68);
          AbyssEngine::String::~String((String *)aAStack_50);
          AbyssEngine::String::~String((String *)local_60);
          AbyssEngine::String::~String(aSStack_58);
        }
        iVar3 = Globals::w;
        iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_48);
        iVar3 = (iVar3 >> 1) - (iVar4 >> 1);
        AbyssEngine::PaintCanvas::DrawString
                  (Globals::Canvas,Globals::font,aSStack_48,iVar3,
                   *(int *)(Globals::layout + 0xc4) + *(int *)(param_1 + 0x210),false);
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        iVar4 = extraout_r1;
      }
      if (this_02 != pPVar12) {
        iVar4 = *(int *)(this_02 + 0x24);
      }
      if (this_02 != pPVar12 && iVar4 != 10) {
        Sprite::setFrame(*(Sprite **)(param_1 + 0xf0),iVar4);
        pSVar10 = *(Sprite **)(param_1 + 0xf0);
        iVar9 = *(int *)(Globals::layout + 0x2c);
        iVar4 = Sprite::getFrameWidth(pSVar10);
        uVar14 = Sprite::setPosition(pSVar10,(iVar3 - iVar9) - iVar4,
                                     *(int *)(param_1 + 0x210) + *(int *)(Globals::layout + 200));
        Sprite::draw((float)uVar14,(float)((ulonglong)uVar14 >> 0x20));
      }
      AbyssEngine::String::~String(aSStack_48);
    }
  }
  else {
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(param_1 + 0xcc),*(int *)(param_1 + 0x20c),
               *(int *)(param_1 + 0x210));
    iVar3 = Status::getPlanetNames(Globals::status);
    AbyssEngine::String::String
              (aSStack_30,*(String **)(*(int *)(iVar3 + 4) + *(int *)(param_1 + 0x40) * 4),false);
    iVar3 = Globals::w;
    uVar1 = Globals::font;
    this = Globals::Canvas;
    iVar4 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aSStack_30);
    AbyssEngine::PaintCanvas::DrawString
              (this,uVar1,aSStack_30,(iVar3 >> 1) - iVar4 / 2,
               *(int *)(Globals::layout + 0xbc) + *(int *)(param_1 + 0x210),false);
  }
  AbyssEngine::String::~String(aSStack_30);
LAB_0015860a:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== Radar::getLockedGasCloud  @0x00158d18  (4 bytes)
/* Radar::getLockedGasCloud() */

undefined4 __thiscall Radar::getLockedGasCloud(Radar *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== Radar::getLockedAsteroid  @0x00158d1c  (4 bytes)
/* Radar::getLockedAsteroid() */

undefined4 __thiscall Radar::getLockedAsteroid(Radar *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== Radar::unlockAsteroid  @0x00158d20  (6 bytes)
/* Radar::unlockAsteroid() */

void __thiscall Radar::unlockAsteroid(Radar *this)

{
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

// ===== Radar::getLockedEnemy  @0x00158d26  (4 bytes)
/* Radar::getLockedEnemy() */

undefined4 __thiscall Radar::getLockedEnemy(Radar *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== Radar::stationLocked  @0x00158d2a  (20 bytes)
/* Radar::stationLocked() */

bool __thiscall Radar::stationLocked(Radar *this)

{
  if (*(int *)(this + 0x24) != 0) {
    return *(char *)(*(int *)(this + 0x24) + 0x6d) != '\0';
  }
  return false;
}

// ===== Radar::getTurretScopeWidth  @0x00158d3e  (8 bytes)
/* Radar::getTurretScopeWidth() */

int __thiscall Radar::getTurretScopeWidth(Radar *this)

{
  return *(int *)(this + 300) << 1;
}

// ===== Radar::isPlasmaInRange  @0x00158d46  (6 bytes)
/* Radar::isPlasmaInRange() */

Radar __thiscall Radar::isPlasmaInRange(Radar *this)

{
  return this[0x130];
}

// ===== Radar::hasScanner  @0x00158d4c  (6 bytes)
/* Radar::hasScanner() */

Radar __thiscall Radar::hasScanner(Radar *this)

{
  return this[0x1a7];
}

