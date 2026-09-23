// Class: PlayerEgo
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PlayerEgo::PlayerEgo  @0x000a5610  (2042 bytes)
/* PlayerEgo::PlayerEgo(Player*) */

PlayerEgo * __thiscall PlayerEgo::PlayerEgo(PlayerEgo *this,Player *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  PlayerEgo PVar4;
  MovingStars *this_00;
  undefined4 uVar5;
  Ship *pSVar6;
  Item *pIVar7;
  int iVar8;
  undefined4 uVar9;
  AEGeometry *pAVar10;
  AEGeometry *this_01;
  void *pvVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x40) = 0x3f800000;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = uVar5;
  *(undefined4 *)(this + 0x4c) = uVar9;
  *(undefined4 *)(this + 0x50) = uVar3;
  *(undefined4 *)(this + 0x54) = 0x3f800000;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = uVar5;
  *(undefined4 *)(this + 0x60) = uVar9;
  *(undefined4 *)(this + 100) = uVar3;
  *(undefined8 *)(this + 0x68) = 0x3f800000;
  *(undefined8 *)(this + 0x70) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x78) = 0x3f800000;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x168) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  *(undefined4 *)(this + 0x1c8) = 0;
  *(undefined4 *)(this + 0x1cc) = 0;
  *(undefined4 *)(this + 0x1d0) = 0;
  *(undefined4 *)(this + 0x224) = 0;
  *(undefined4 *)(this + 0x228) = 0;
  *(undefined4 *)(this + 0x22c) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = uVar5;
  *(undefined4 *)(this + 0x9c) = uVar9;
  *(undefined4 *)(this + 0xa0) = uVar3;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = uVar5;
  *(undefined4 *)(this + 0xe8) = uVar9;
  *(undefined4 *)(this + 0xec) = uVar3;
  *(undefined4 *)(this + 0xf0) = 0;
  *(undefined4 *)(this + 0xf4) = 0;
  *(undefined4 *)(this + 0x2ac) = 0x3f800000;
  *(undefined4 *)(this + 0x2b0) = 0;
  *(undefined4 *)(this + 0x2b4) = uVar5;
  *(undefined4 *)(this + 0x2b8) = uVar9;
  *(undefined4 *)(this + 700) = uVar3;
  *(undefined4 *)(this + 0x2c0) = 0x3f800000;
  *(undefined4 *)(this + 0x2c4) = 0;
  *(undefined4 *)(this + 0x2c8) = uVar5;
  *(undefined4 *)(this + 0x2cc) = uVar9;
  *(undefined4 *)(this + 0x2d0) = uVar3;
  *(undefined8 *)(this + 0x2d4) = 0x3f800000;
  *(undefined8 *)(this + 0x2dc) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x2e4) = 0x3f800000;
  *(undefined4 *)(this + 0x314) = 0;
  *(undefined4 *)(this + 0x318) = 0;
  *(undefined4 *)(this + 0x31c) = 0;
  *(undefined4 *)(this + 0x338) = 0;
  *(undefined4 *)(this + 0x33c) = uVar5;
  *(undefined4 *)(this + 0x340) = uVar9;
  *(undefined4 *)(this + 0x344) = uVar3;
  *(undefined4 *)(this + 0x348) = 0;
  *(undefined4 *)(this + 0x34c) = 0;
  *(undefined4 *)(this + 200) = 5;
  *(undefined4 *)(this + 0xcc) = 5000;
  *(undefined4 *)(this + 0xd0) = 20000;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0xd8) = 0xffffffff;
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0xf8) = 0;
  *(undefined4 *)(this + 0xfc) = uVar5;
  *(undefined4 *)(this + 0x100) = uVar9;
  *(undefined4 *)(this + 0x104) = uVar3;
  *(undefined4 *)(this + 0x108) = 0;
  *(undefined4 *)(this + 0x10c) = 0xffffffff;
  *(undefined4 *)(this + 0x110) = 0;
  this[0x24] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x254) = 0;
  this[0x158] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x15c) = 0;
  this[0x160] = (PlayerEgo)0x0;
  this[0x170] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x128) = 0;
  *(undefined4 *)(this + 300) = uVar5;
  *(undefined4 *)(this + 0x130) = uVar9;
  *(undefined4 *)(this + 0x134) = uVar3;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = uVar5;
  *(undefined4 *)(this + 0x120) = uVar9;
  *(undefined4 *)(this + 0x124) = uVar3;
  *(undefined4 *)(this + 0x139) = 0;
  *(undefined4 *)(this + 0x135) = 0;
  this[0x146] = (PlayerEgo)0x0;
  *(undefined2 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x174) = 0xffffffff;
  *(undefined4 *)(this + 0x178) = 0;
  *(undefined4 *)(this + 0x17c) = 0;
  *(undefined4 *)(this + 0x19c) = 0;
  this[0x1a0] = (PlayerEgo)0x0;
  this[0x1a1] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x1c4) = 0;
  this[0x1d4] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x1f0) = 0;
  this[500] = (PlayerEgo)0x0;
  this[0x25] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x230) = 0;
  this[0x234] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x24c) = 0;
  *(undefined4 *)(this + 0x2f8) = 0;
  this[0x308] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x35) = 0;
  *(undefined4 *)(this + 0x31) = 0;
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1a8) = 0;
  *(undefined2 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1b4) = uVar5;
  *(undefined4 *)(this + 0x1b8) = uVar9;
  *(undefined4 *)(this + 0x1bc) = uVar3;
  this[0x1c0] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x1d8) = 0;
  *(undefined4 *)(this + 0x1dc) = uVar5;
  *(undefined4 *)(this + 0x1e0) = uVar9;
  *(undefined4 *)(this + 0x1e4) = uVar3;
  *(undefined4 *)(this + 0x1eb) = 0;
  *(undefined4 *)(this + 0x1e7) = 0;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x1fc) = 0;
  *(undefined4 *)(this + 0x201) = 0;
  *(undefined4 *)(this + 0x1fd) = 0;
  *(undefined4 *)(this + 0x214) = 0;
  *(undefined4 *)(this + 0x218) = uVar5;
  *(undefined4 *)(this + 0x21c) = uVar9;
  *(undefined4 *)(this + 0x220) = uVar3;
  *(undefined4 *)(this + 0x208) = 0;
  *(undefined4 *)(this + 0x20c) = uVar5;
  *(undefined4 *)(this + 0x210) = uVar9;
  *(undefined4 *)(this + 0x214) = uVar3;
  *(undefined4 *)(this + 0x300) = 0xffffffff;
  *(undefined4 *)(this + 0x304) = 0xffffffff;
  this[0x309] = (PlayerEgo)0x1;
  this[0x32e] = (PlayerEgo)0x1;
  this[0x32f] = (PlayerEgo)0x1;
  this[0x32d] = (PlayerEgo)0x0;
  this[0x30a] = (PlayerEgo)0x0;
  this[0x330] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x334) = 0;
  *(undefined4 *)(this + 0x350) = 0;
  *(undefined4 *)(this + 0x194) = 0;
  this[0x180] = (PlayerEgo)0x0;
  this[0x355] = (PlayerEgo)0x1;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x30c) = 0;
  *(undefined4 *)(this + 0x310) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  this[0x356] = (PlayerEgo)0x0;
  this[0x399] = (PlayerEgo)0x0;
  this[0xb2] = (PlayerEgo)0x0;
  this[0x370] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x184) = 0;
  *(undefined4 *)(this + 0x188) = uVar5;
  *(undefined4 *)(this + 0x18c) = uVar9;
  *(undefined4 *)(this + 400) = uVar3;
  *(undefined4 *)(this + 0x374) = 2000;
  this[0xb0] = (PlayerEgo)0x0;
  this[0xb1] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x37c) = 0;
  *(undefined4 *)(this + 0x380) = 0x3dcccccd;
  *(undefined4 *)(this + 900) = 0;
  *(undefined4 *)(this + 0x278) = 0;
  *(undefined4 *)(this + 0x27c) = 0;
  *(undefined4 *)(this + 0x2f0) = 0;
  *(undefined4 *)(this + 0x2e8) = 0;
  *(undefined4 *)(this + 0x2ec) = 0;
  this[0x2f5] = (PlayerEgo)0x0;
  this[0x2a9] = (PlayerEgo)0x0;
  this[0x324] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 600) = 0;
  *(undefined4 *)(this + 0x25c) = uVar5;
  *(undefined4 *)(this + 0x260) = uVar9;
  *(undefined4 *)(this + 0x264) = uVar3;
  *(Player **)this = param_1;
  Player::setPlayShootSound(param_1,true,2);
  *(undefined4 *)(this + 0x108) = 1;
  this_00 = operator_new(0x1c);
  MovingStars::MovingStars(this_00);
  *(MovingStars **)(this + 0xf8) = this_00;
  uVar5 = Player::getCombinedHP(*(Player **)this);
  *(undefined4 *)(this + 0x130) = uVar5;
  *(undefined4 *)(this + 0xb8) = 0x40000000;
  *(undefined4 *)(this + 0xbc) = 0x3f800000;
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  uVar5 = Ship::getBoostDelay(pSVar6);
  *(undefined4 *)(this + 0xd0) = uVar5;
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  uVar5 = Ship::getBoostSpeed(pSVar6);
  fVar12 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 200) = (int)(fVar12 / 100.0 + fVar12 / 100.0) + 2;
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  uVar5 = Ship::getBoostTime(pSVar6);
  *(undefined4 *)(this + 0xcc) = uVar5;
  this[0x146] = (PlayerEgo)(0 < *(int *)(this + 0xd0));
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  pIVar7 = (Item *)Ship::getFirstEquipmentOfSort(pSVar6,0xe);
  if (pIVar7 == (Item *)0x0) goto LAB_000a5940;
  iVar8 = Item::getIndex(pIVar7);
  switch(iVar8) {
  case 0x47:
    iVar8 = 0x26;
    break;
  case 0x48:
    iVar8 = 0x27;
    break;
  case 0x49:
    iVar8 = 0x28;
    break;
  case 0x4a:
    iVar8 = 0x29;
    break;
  default:
    if (iVar8 == 0xc3) {
      iVar8 = 0x44e;
      break;
    }
    iVar8 = *(int *)(this + 0xd4);
    goto LAB_000a5932;
  }
  *(int *)(this + 0xd4) = iVar8;
LAB_000a5932:
  Globals::addSoundResourceToList(Globals::globals,iVar8);
LAB_000a5940:
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  uVar5 = Ship::getHandling(pSVar6);
  *(undefined4 *)(this + 0x154) = uVar5;
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getIndex(pSVar6);
  if (iVar8 == 0x2a) {
    iVar8 = 0x450;
  }
  else {
    pSVar6 = (Ship *)Status::getShip(Globals::status);
    iVar8 = Ship::getIndex(pSVar6);
    if (iVar8 == 0x2b) {
      iVar8 = 0x452;
    }
    else {
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      iVar8 = Ship::getIndex(pSVar6);
      if (iVar8 == 0x28) {
        iVar8 = 0x453;
      }
      else {
        fVar12 = *(float *)(this + 0x154);
        uVar1 = in_fpscr & 0xfffffff;
        uVar2 = uVar1 | (uint)(fVar12 < 1.4) << 0x1f;
        in_fpscr = uVar2 | (uint)NAN(fVar12) << 0x1c;
        if ((byte)(uVar2 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
          iVar8 = 0x2d;
        }
        else {
          uVar2 = uVar1 | (uint)(fVar12 < 1.15) << 0x1f;
          in_fpscr = uVar2 | (uint)NAN(fVar12) << 0x1c;
          if ((byte)(uVar2 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
            iVar8 = 0x2c;
          }
          else {
            uVar1 = uVar1 | (uint)(fVar12 < 0.95) << 0x1f;
            in_fpscr = uVar1 | (uint)NAN(fVar12) << 0x1c;
            if ((byte)(uVar1 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
              iVar8 = 0x2b;
            }
            else {
              iVar8 = 0x2a;
            }
          }
        }
      }
    }
  }
  *(int *)(this + 0x1c) = iVar8;
  Globals::addSoundResourceToList(Globals::globals,iVar8);
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  uVar5 = Ship::getAgility(pSVar6);
  fVar12 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0x254) = fVar12;
  *(float *)(this + 0x154) =
       (*(float *)(this + 0x154) + *(float *)(this + 0x154) * (fVar12 / 100.0)) * 20.0;
  PVar4 = (PlayerEgo)Status::hardCoreMode();
  this[0x235] = PVar4;
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  uVar5 = Ship::getMaxShieldHP(pSVar6);
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  uVar9 = Ship::getShieldRegen(pSVar6);
  fVar12 = (float)VectorSignedToFloat(uVar9,(byte)(in_fpscr >> 0x16) & 3);
  fVar13 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0x218) = fVar13 / (fVar12 / 100.0);
  *(undefined4 *)(this + 0x388) = 0xffffffff;
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::hasCloakIntegrated(pSVar6);
  pSVar6 = (Ship *)Status::getShip(Globals::status);
  pIVar7 = (Item *)Ship::getFirstEquipmentOfSort(pSVar6,0x15);
  do {
    *(Item **)(this + 0x1b0) = pIVar7;
    *(undefined4 *)(this + 0x208) = 0xffffffff;
    if (pIVar7 != (Item *)0x0) {
      uVar5 = Item::getAttribute(pIVar7,0x23);
      *(undefined4 *)(this + 0x210) = uVar5;
      if (*(Item **)(this + 0x1b0) == (Item *)0x0) {
LAB_000a5aec:
        *(undefined4 *)(this + 0x214) = 0;
      }
      else {
        uVar5 = Item::getAttribute(*(Item **)(this + 0x1b0),0x24);
        *(undefined4 *)(this + 0x214) = uVar5;
        if (*(int *)(this + 0x1b0) != 0) {
          Globals::addSoundResourceToList(Globals::globals,0x1e);
        }
      }
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      pIVar7 = (Item *)Ship::getFirstEquipmentOfSort(pSVar6,0x12);
      if (pIVar7 == (Item *)0x0) {
        *(undefined4 *)(this + 0x200) = 0;
        pSVar6 = (Ship *)Status::getShip(Globals::status);
        iVar8 = Ship::hasJumpDriveIntegrated(pSVar6);
        if (iVar8 == 1) {
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(Globals::items + 4) + 0x154),0x25);
          *(undefined4 *)(this + 0x200) = uVar5;
        }
      }
      else {
        uVar5 = Item::getAttribute(pIVar7,0x25);
        *(undefined4 *)(this + 0x200) = uVar5;
        Globals::addSoundResourceToList(Globals::globals,0x20);
        Globals::addSoundResourceToList(Globals::globals,0x21);
      }
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      iVar8 = Ship::getFirstEquipmentOfSort(pSVar6,0x13);
      if (iVar8 != 0) {
        Globals::addSoundResourceToList(Globals::globals,1);
        Globals::addSoundResourceToList(Globals::globals,3);
        Globals::addSoundResourceToList(Globals::globals,2);
      }
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      iVar8 = Ship::getFirstEquipmentOfSort(pSVar6,9);
      if (iVar8 != 0) {
        Globals::addSoundResourceToList(Globals::globals,0x19);
      }
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      iVar8 = Ship::getFirstEquipmentOfSort(pSVar6,10);
      if (iVar8 != 0) {
        Globals::addSoundResourceToList(Globals::globals,0x17);
      }
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      PVar4 = (PlayerEgo)Ship::hasVolatileGoods(pSVar6);
      this[0x398] = PVar4;
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      uVar5 = Ship::getFreeSpace(pSVar6);
      *(undefined4 *)(this + 0x250) = uVar5;
      pSVar6 = (Ship *)Status::getShip(Globals::status);
      iVar8 = Ship::getFirstEquipmentOfSort(pSVar6,0x2b);
      this[0x39a] = (PlayerEgo)(iVar8 != 0);
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4c0,(uint *)(this + 0x23c));
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ce,(uint *)(this + 0x240));
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f5e,(uint *)(this + 0x244));
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x1f5d,(uint *)(this + 0x248));
      AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x548,(uint *)(this + 0x238));
      this[0xc4] = (PlayerEgo)0x0;
      PVar4 = (PlayerEgo)Status::inBlackMarketSystem(Globals::status);
      this[0x354] = PVar4;
      *(undefined4 *)(this + 0x20) = 0;
      uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      *(float *)(this + 0x284) = ((*(float *)(this + 0x154) * 750.0) / 63.0) * 1.2;
      *(undefined4 *)(this + 0x288) = 0x41723ace;
      *(undefined4 *)(this + 0x328) = 0;
      this[0x32c] = (PlayerEgo)0x0;
      *(undefined4 *)(this + 0x299) = 0;
      *(undefined4 *)(this + 0x29d) = uVar5;
      *(undefined4 *)(this + 0x2a1) = uVar9;
      *(undefined4 *)(this + 0x2a5) = uVar3;
      *(undefined4 *)(this + 0x290) = 0;
      *(undefined4 *)(this + 0x294) = uVar5;
      *(undefined4 *)(this + 0x298) = uVar9;
      *(undefined4 *)(this + 0x29c) = uVar3;
      this[0x378] = (PlayerEgo)(Globals::mouseCursorActivated == 0);
      this[0x84] = (PlayerEgo)0x1;
      *(undefined4 *)(this + 0x36c) = 0;
      *(undefined4 *)(this + 0x268) = 0;
      *(undefined4 *)(this + 0x26c) = uVar5;
      *(undefined4 *)(this + 0x270) = uVar9;
      *(undefined4 *)(this + 0x274) = uVar3;
      *(undefined4 *)(this + 0x358) = 0;
      *(undefined4 *)(this + 0x35c) = uVar5;
      *(undefined4 *)(this + 0x360) = uVar9;
      *(undefined4 *)(this + 0x364) = uVar3;
      *(undefined4 *)(this + 0xb4) = 0xffffffff;
      this[0x39b] = (PlayerEgo)0x0;
      if ((float)Globals::options._44_4_ <= 0.0) {
        uVar5 = 5000;
      }
      else if ((float)Globals::options._44_4_ <= 0.6) {
        uVar5 = 7000;
      }
      else {
        uVar5 = 12000;
        if ((float)Globals::options._44_4_ <= 1.1) {
          uVar5 = 9000;
        }
      }
      *(undefined4 *)(this + 0x368) = uVar5;
      iVar8 = Status::inSupernovaSystem(Globals::status);
      if ((iVar8 != 0) || (iVar8 = Status::inSupernovaOrbit(Globals::status), iVar8 == 1)) {
        pSVar6 = (Ship *)Status::getShip(Globals::status);
        iVar8 = Ship::getFirstEquipmentOfSort(pSVar6,0x26);
        if (iVar8 != 0) {
          pSVar6 = (Ship *)Status::getShip(Globals::status);
          pIVar7 = (Item *)Ship::getFirstEquipmentOfSort(pSVar6,0x26);
          iVar8 = Item::getIndex(pIVar7);
          uVar5 = 0x8d4;
          if (iVar8 == 0xcd) {
            uVar5 = 0x8d5;
          }
          *(undefined4 *)(this + 0xb4) = uVar5;
          this[0x38] = (PlayerEgo)0x1;
          pAVar10 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar10,Globals::Canvas);
          *(AEGeometry **)(this + 0x34) = pAVar10;
          pAVar10 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar10,0x4973,Globals::Canvas,false);
          this_01 = operator_new(0xc0);
          AEGeometry::AEGeometry(this_01,0x4972,Globals::Canvas,false);
          AEGeometry::addChild(*(AEGeometry **)(this + 0x34),*(uint *)(pAVar10 + 0xc));
          pvVar11 = (void *)AEGeometry::~AEGeometry(pAVar10);
          operator_delete(pvVar11);
          AEGeometry::addChild(*(AEGeometry **)(this + 0x34),*(uint *)(this_01 + 0xc));
          pvVar11 = (void *)AEGeometry::~AEGeometry(this_01);
          operator_delete(pvVar11);
        }
      }
      return this;
    }
    if (iVar8 == 0) {
      *(undefined4 *)(this + 0x210) = 0;
      goto LAB_000a5aec;
    }
    pIVar7 = *(Item **)(*(int *)(Globals::items + 4) + 0x17c);
  } while( true );
}

// ===== PlayerEgo::~PlayerEgo  @0x000a5ee0  (358 bytes)
/* PlayerEgo::~PlayerEgo() */

PlayerEgo * __thiscall PlayerEgo::~PlayerEgo(PlayerEgo *this)

{
  void *pvVar1;
  
  if (*(Player **)this != (Player *)0x0) {
    pvVar1 = (void *)Player::~Player(*(Player **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  if (*(AEGeometry **)(this + 4) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(AEGeometry **)(this + 8) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(AEGeometry **)(this + 0xdc) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xdc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xdc) = 0;
  if (*(AEGeometry **)(this + 0x28) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x28));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(Route **)(this + 0xfc) != (Route *)0x0) {
    pvVar1 = (void *)Route::~Route(*(Route **)(this + 0xfc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xfc) = 0;
  if (*(AEGeometry **)(this + 0x178) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x178));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x178) = 0;
  if (*(AEGeometry **)(this + 0x17c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x17c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x17c) = 0;
  if (*(AEGeometry **)(this + 0x2c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x2c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  if (*(AEGeometry **)(this + 0x30) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x30));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x30) = 0;
  if (*(AEGeometry **)(this + 0x34) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x34));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x34) = 0;
  if (*(AEGeometry **)(this + 0x19c) != (AEGeometry *)0x0) {
    pvVar1 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0x19c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x19c) = 0;
  if (*(TractorBeam **)(this + 0x1b4) != (TractorBeam *)0x0) {
    pvVar1 = (void *)TractorBeam::~TractorBeam(*(TractorBeam **)(this + 0x1b4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1b4) = 0;
  if (*(MiningGame **)(this + 0x1e4) != (MiningGame *)0x0) {
    pvVar1 = (void *)MiningGame::~MiningGame(*(MiningGame **)(this + 0x1e4));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1e4) = 0;
  if (*(Explosion **)(this + 0x8c) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0x8c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x8c) = 0;
  if (*(Explosion **)(this + 0x90) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0x90));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x90) = 0;
  pvVar1 = *(void **)(this + 0x358);
  if (pvVar1 != (void *)0x0) {
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar1 + 0x58));
    AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar1 + 0x3c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x358) = 0;
  if (*(Array **)(this + 0x1b8) != (Array *)0x0) {
    ArrayReleaseClasses<RepairBeam*>(*(Array **)(this + 0x1b8));
    pvVar1 = *(void **)(this + 0x1b8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x1b8) = 0;
  return this;
}

// ===== PlayerEgo::setShip  @0x000a6088  (656 bytes)
/* PlayerEgo::setShip(int, int) */

void __thiscall PlayerEgo::setShip(PlayerEgo *this,int param_1,int param_2)

{
  int iVar1;
  AEGeometry *pAVar2;
  Ship *pSVar3;
  Item *pIVar4;
  TractorBeam *this_00;
  undefined4 *puVar5;
  undefined4 *puVar6;
  RepairBeam *this_01;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  
  iVar1 = Globals::getShipGroup(Globals::globals,param_1,param_2,true);
  *(int *)(this + 4) = iVar1;
  iVar1 = AbyssEngine::PaintCanvas::MeshGetPointer(Globals::Canvas,*(uint *)(iVar1 + 0x1c));
  *(undefined4 *)(this + 0x394) = *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x20);
  pAVar2 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar2,Globals::Canvas);
  *(AEGeometry **)(this + 8) = pAVar2;
  AEGeometry::addChild(pAVar2,*(uint *)(*(int *)(this + 4) + 0xc));
  pSVar3 = (Ship *)Status::getShip(Globals::status);
  iVar1 = Ship::getFirstEquipmentOfSort(pSVar3,0xd);
  if (iVar1 != 0) {
    pSVar3 = (Ship *)Status::getShip(Globals::status);
    pIVar4 = (Item *)Ship::getFirstEquipmentOfSort(pSVar3,0xd);
    iVar1 = Item::getIndex(pIVar4);
    iVar10 = 3;
    if (iVar1 < 0x48) {
      iVar10 = iVar1 + -0x44;
    }
    this_00 = operator_new(0x1c);
    TractorBeam::TractorBeam(this_00,*(AEGeometry **)(this + 8),iVar10);
    *(TractorBeam **)(this + 0x1b4) = this_00;
    Globals::addSoundResourceToList(Globals::globals,0);
    Globals::addSoundResourceToList(Globals::globals,4);
  }
  iVar1 = 0;
  do {
    iVar10 = 0x29;
    if (iVar1 == 0) {
      iVar10 = 0x25;
    }
    pSVar3 = (Ship *)Status::getShip(Globals::status);
    pIVar4 = (Item *)Ship::getFirstEquipmentOfSort(pSVar3,iVar10);
    if (pIVar4 != (Item *)0x0) {
      if (*(int *)(this + 0x1b8) == 0) {
        puVar5 = operator_new(0xc);
        puVar6 = operator_new__(4);
        puVar5[1] = puVar6;
        puVar5[2] = 1;
        *puVar6 = 0;
        *puVar5 = 0;
        *(undefined4 **)(this + 0x1b8) = puVar5;
      }
      this_01 = operator_new(0x24);
      iVar10 = Item::getIndex(pIVar4);
      iVar7 = Item::getSort(pIVar4);
      RepairBeam::RepairBeam(this_01,iVar10,iVar7);
      iVar10 = Item::getIndex(pIVar4);
      if (iVar10 == 0xde) {
        iVar10 = 0x8db;
LAB_000a61dc:
        Globals::addSoundResourceToList(Globals::globals,iVar10);
      }
      else {
        iVar10 = Item::getIndex(pIVar4);
        if (iVar10 == 0xdf) {
          iVar10 = 0x8dc;
          goto LAB_000a61dc;
        }
      }
      piVar11 = *(int **)(this + 0x1b8);
      piVar11[2] = *piVar11 + 1;
      pvVar8 = realloc((void *)piVar11[1],(*piVar11 + 1) * 4);
      piVar11[1] = (int)pvVar8;
      *(RepairBeam **)((int)pvVar8 + *piVar11 * 4) = this_01;
      *piVar11 = piVar11[2];
    }
    iVar1 = iVar1 + 1;
    if (1 < iVar1) {
      pSVar3 = (Ship *)Status::getShip(Globals::status);
      iVar1 = Ship::getFirstEquipmentOfSort(pSVar3,0x1b);
      if (iVar1 != 0) {
        pSVar3 = (Ship *)Status::getShip(Globals::status);
        iVar1 = Ship::hasEmergencySystem(pSVar3);
        if (iVar1 == 1) {
          pAVar2 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar2,0x3826,Globals::Canvas,false);
          *(AEGeometry **)(this + 0xac) = pAVar2;
          pSVar3 = (Ship *)Status::getShip(Globals::status);
          pIVar4 = (Item *)Ship::getFirstEquipmentOfSort(pSVar3,0x1b);
          uVar9 = Item::getAttribute(pIVar4,0x29);
          *(undefined4 *)(this + 0x310) = uVar9;
          iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                            (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
          AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x314),(Vector *)(iVar1 + 0xd4));
          iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                            (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
          *(float *)(this + 800) = *(float *)(iVar1 + 0xe0) / 500.0 + 0.1;
        }
      }
      iVar1 = Status::inSupernovaSystem(Globals::status);
      if ((iVar1 != 0) || (iVar1 = Status::inSupernovaOrbit(Globals::status), iVar1 == 1)) {
        iVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
        *(float *)(this + 0x3c) = *(float *)(iVar1 + 0xe0) * 1.75;
      }
      if (*(int *)(this + 0x1b0) == 0) {
        return;
      }
      AbyssEngine::PaintCanvas::MeshCloneMaterial
                (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0x1c),(uint *)(this + 0x388));
      return;
    }
  } while( true );
}

// ===== PlayerEgo::setExhaustVisible  @0x000a637c  (84 bytes)
/* PlayerEgo::setExhaustVisible(bool) */

void __thiscall PlayerEgo::setExhaustVisible(PlayerEgo *this,bool param_1)

{
  ParticleSystemManager *this_00;
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  this[0x32f] = (PlayerEgo)param_1;
  iVar1 = *(int *)(this + 0xc);
  this_00 = *(ParticleSystemManager **)(iVar1 + 0x80);
  *this_00 = (ParticleSystemManager)param_1;
  puVar3 = *(uint **)(iVar1 + 0xa8);
  if (((puVar3 != (uint *)0x0) && (*puVar3 != 0)) &&
     (ParticleSystemManager::enableSystemEmit(this_00,*(int *)puVar3[1],param_1), 1 < *puVar3)) {
    uVar2 = 1;
    do {
      ParticleSystemManager::enableSystemEmit
                (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x80),
                 *(int *)(puVar3[1] + uVar2 * 4),param_1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar3);
  }
  return;
}

// ===== PlayerEgo::PlayEngineSound  @0x000a63d0  (140 bytes)
/* PlayerEgo::PlayEngineSound() */

void __thiscall PlayerEgo::PlayEngineSound(PlayerEgo *this)

{
  Status *this_00;
  Ship *this_01;
  int iVar1;
  Station *this_02;
  int iVar2;
  float fVar3;
  
  this_01 = (Ship *)Status::getShip(Globals::status);
  iVar1 = Ship::getFirstEquipmentOfSort(this_01,0x26);
  if ((iVar1 != 0) &&
     (iVar1 = Status::inAlienOrbit(Globals::status), this_00 = Globals::status, iVar1 == 0)) {
    this_02 = (Station *)Status::getStation(Globals::status);
    iVar1 = Station::getIndex(this_02);
    iVar2 = Status::getCurrentCampaignMission(Globals::status);
    fVar3 = (float)Status::getGammaRayDamagePerSecond(this_00,iVar1,iVar2);
    if ((0.0 < fVar3) && (*(int *)(this + 0xb4) != -1)) {
      FModSound::play(Globals::sound,*(int *)(this + 0xb4),(Vector *)0x0,(Vector *)0x0,fVar3);
    }
  }
  Player::PlayEngineSound(*(int *)this,*(Vector **)(this + 0x1c));
  return;
}

// ===== PlayerEgo::PauseEngineSound  @0x000a646c  (6 bytes)
/* PlayerEgo::PauseEngineSound() */

void __thiscall PlayerEgo::PauseEngineSound(PlayerEgo *this)

{
  Player::PauseEngineSound(*(Player **)this);
  return;
}

// ===== PlayerEgo::ResumeEngineSound  @0x000a6472  (8 bytes)
/* PlayerEgo::ResumeEngineSound() */

void __thiscall PlayerEgo::ResumeEngineSound(PlayerEgo *this)

{
  Player::ResumeEngineSound(*(Player **)this,false);
  return;
}

// ===== PlayerEgo::StopEngineSound  @0x000a647c  (150 bytes)
/* PlayerEgo::StopEngineSound() */

void __thiscall PlayerEgo::StopEngineSound(PlayerEgo *this)

{
  Status *this_00;
  Ship *this_01;
  int iVar1;
  Station *this_02;
  int iVar2;
  float fVar3;
  
  if ((this[0x356] == (PlayerEgo)0x0) || (*(int *)(this + 0x1c4) != 1)) {
    this_01 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Ship::getFirstEquipmentOfSort(this_01,0x26);
    if ((iVar1 != 0) &&
       (iVar1 = Status::inAlienOrbit(Globals::status), this_00 = Globals::status, iVar1 == 0)) {
      this_02 = (Station *)Status::getStation(Globals::status);
      iVar1 = Station::getIndex(this_02);
      iVar2 = Status::getCurrentCampaignMission(Globals::status);
      fVar3 = (float)Status::getGammaRayDamagePerSecond(this_00,iVar1,iVar2);
      if ((0.0 < fVar3) && (*(int *)(this + 0xb4) != -1)) {
        FModSound::play(Globals::sound,*(int *)(this + 0xb4),(Vector *)0x0,(Vector *)0x0,fVar3);
      }
    }
  }
  Player::StopEngineSound(*(Player **)this);
  return;
}

// ===== PlayerEgo::isDockedToDockingPoint  @0x000a6524  (22 bytes)
/* PlayerEgo::isDockedToDockingPoint() */

bool __thiscall PlayerEgo::isDockedToDockingPoint(PlayerEgo *this)

{
  if (this[0x356] != (PlayerEgo)0x0) {
    return *(int *)(this + 0x1c4) == 1;
  }
  return false;
}

// ===== PlayerEgo::resetMovement  @0x000a653a  (20 bytes)
/* PlayerEgo::resetMovement() */

void __thiscall PlayerEgo::resetMovement(PlayerEgo *this)

{
  *(undefined4 *)(this + 0x278) = 0;
  *(undefined4 *)(this + 0x27c) = 0;
  *(undefined4 *)(this + 0x268) = 0;
  *(undefined4 *)(this + 0x26c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x270) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x274) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  return;
}

// ===== PlayerEgo::resetLastHP  @0x000a654e  (18 bytes)
/* PlayerEgo::resetLastHP() */

void __thiscall PlayerEgo::resetLastHP(PlayerEgo *this)

{
  undefined4 uVar1;
  
  uVar1 = Player::getCombinedHP(*(Player **)this);
  *(undefined4 *)(this + 0x130) = uVar1;
  return;
}

// ===== PlayerEgo::startJumpDrive  @0x000a6560  (64 bytes)
/* PlayerEgo::startJumpDrive() */

void PlayerEgo::startJumpDrive(void)

{
  int in_r0;
  float in_s0;
  
  if (*(char *)(in_r0 + 0x204) == '\0') {
    FModSound::play(Globals::sound,0x21,(Vector *)0x0,(Vector *)0x0,in_s0);
    Hud::hudEvent(*(int *)(in_r0 + 0x220),(PlayerEgo *)0x19,in_r0);
    *(undefined1 *)(in_r0 + 0x204) = 1;
    *(undefined4 *)(in_r0 + 0x1fc) = 0;
  }
  return;
}

// ===== PlayerEgo::toggleCloaking  @0x000a65a4  (646 bytes)
/* PlayerEgo::toggleCloaking() */

void PlayerEgo::toggleCloaking(void)

{
  PaintCanvas *pPVar1;
  int *in_r0;
  int iVar2;
  int iVar3;
  Mesh *pMVar4;
  Ship *pSVar5;
  Item *pIVar6;
  ushort uVar7;
  float in_s0;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  uint local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (*(char *)((int)in_r0 + 0x1ad) == '\0') {
    if (((char)in_r0[0x6b] == '\0') && (in_r0[0x83] < 1)) {
      iVar3 = Item::getAttribute((Item *)in_r0[0x6c],0x26);
      pSVar5 = (Ship *)Status::getShip(Globals::status);
      pIVar6 = (Item *)Ship::getCargo(pSVar5,0x7a);
      if (pIVar6 == (Item *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = Item::getAmount(pIVar6);
      }
      if (iVar3 <= iVar2) {
        pSVar5 = (Ship *)Status::getShip(Globals::status);
        Ship::removeCargo(pSVar5,0x7a,iVar3);
        *(undefined1 *)((int)in_r0 + 0x1ad) = 1;
        Hud::hudEvent(in_r0[0x88],(PlayerEgo *)0x1e,(int)in_r0);
        Hud::hudEvent(in_r0[0x88],(PlayerEgo *)0x1c,(int)in_r0);
      }
    }
  }
  else if (in_r0[0x85] <= in_r0[0x82]) {
    FModSound::play(Globals::sound,0x1e,(Vector *)0x0,(Vector *)0x0,in_s0);
    *(undefined1 *)(*in_r0 + 0x5e) = 1;
    *(undefined1 *)(in_r0 + 0x6b) = 1;
    in_r0[0x82] = 0;
    local_24 = 0;
    iVar3 = AbyssEngine::PaintCanvas::MaterialGetMaterial(Globals::Canvas,in_r0[0xe2]);
    *(undefined4 *)(iVar3 + 0x20) = 0xe;
    AbyssEngine::PaintCanvas::MeshChangeMaterial
              (Globals::Canvas,*(uint *)(in_r0[1] + 0x1c),*(ushort *)(in_r0 + 0xe2));
    pPVar1 = Globals::Canvas;
    pMVar4 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                               (Globals::Canvas,*(uint *)(in_r0[1] + 0x1c));
    AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar1,pMVar4,extraout_s0,0);
    pPVar1 = Globals::Canvas;
    pMVar4 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                               (Globals::Canvas,*(uint *)(in_r0[1] + 0x1c));
    AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar1,pMVar4,extraout_s0_00,0);
    if ((char)in_r0[0x5c] != '\0') {
      iVar3 = AbyssEngine::PaintCanvas::MaterialGetMaterial(Globals::Canvas,in_r0[0xe3]);
      *(undefined4 *)(iVar3 + 0x20) = 0xe;
      iVar3 = AbyssEngine::PaintCanvas::MaterialGetMaterial(Globals::Canvas,in_r0[0xe4]);
      *(undefined4 *)(iVar3 + 0x20) = 0xe;
      AbyssEngine::PaintCanvas::MeshChangeMaterial
                (Globals::Canvas,*(uint *)(in_r0[0x37] + 0x1c),*(ushort *)(in_r0 + 0xe3));
      AbyssEngine::PaintCanvas::MeshChangeMaterial
                (Globals::Canvas,*(uint *)(in_r0[10] + 0x1c),*(ushort *)(in_r0 + 0xe4));
      pPVar1 = Globals::Canvas;
      pMVar4 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                 (Globals::Canvas,*(uint *)(in_r0[0x37] + 0x1c));
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar1,pMVar4,extraout_s0_01,0);
      pPVar1 = Globals::Canvas;
      pMVar4 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                 (Globals::Canvas,*(uint *)(in_r0[0x37] + 0x1c));
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar1,pMVar4,extraout_s0_02,0);
      pPVar1 = Globals::Canvas;
      pMVar4 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                 (Globals::Canvas,*(uint *)(in_r0[10] + 0x1c));
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar1,pMVar4,extraout_s0_03,0);
      pPVar1 = Globals::Canvas;
      pMVar4 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                 (Globals::Canvas,*(uint *)(in_r0[10] + 0x1c));
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar1,pMVar4,extraout_s0_04,0);
      if ((char)in_r0[0x5c] != '\0') {
        pSVar5 = (Ship *)Status::getShip(Globals::status);
        pIVar6 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,8);
        uVar7 = 0x4e8e;
        if ((pIVar6 != (Item *)0x0) && (iVar3 = Item::getIndex(pIVar6), iVar3 == 0xe0)) {
          uVar7 = 0x5e17;
        }
        pSVar5 = (Ship *)Status::getShip(Globals::status);
        pIVar6 = (Item *)Ship::getFirstEquipmentOfSort(pSVar5,0x23);
        if (pIVar6 != (Item *)0x0) {
          iVar3 = Item::getIndex(pIVar6);
          uVar7 = 0x716d;
          if (iVar3 == 199) {
            uVar7 = 0x7167;
          }
          if (iVar3 == 0xc6) {
            uVar7 = 0x7161;
          }
        }
        AbyssEngine::PaintCanvas::MaterialCreate(Globals::Canvas,uVar7,&local_24);
        AbyssEngine::PaintCanvas::MeshChangeResourceMaterial
                  (Globals::Canvas,*(uint *)(in_r0[0x37] + 0x1c),uVar7);
        AbyssEngine::PaintCanvas::MeshChangeResourceMaterial
                  (Globals::Canvas,*(uint *)(in_r0[10] + 0x1c),uVar7);
      }
    }
  }
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== PlayerEgo::hasCloak  @0x000a6854  (12 bytes)
/* PlayerEgo::hasCloak() */

bool __thiscall PlayerEgo::hasCloak(PlayerEgo *this)

{
  return *(int *)(this + 0x1b0) != 0;
}

// ===== PlayerEgo::hasVolatileGoods  @0x000a6860  (6 bytes)
/* PlayerEgo::hasVolatileGoods() */

PlayerEgo __thiscall PlayerEgo::hasVolatileGoods(PlayerEgo *this)

{
  return this[0x398];
}

// ===== PlayerEgo::getVolatileForce  @0x000a6868  (46 bytes)
/* PlayerEgo::getVolatileForce() */

float __thiscall PlayerEgo::getVolatileForce(PlayerEgo *this)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *(float *)(*(int *)this + 0x60);
  if ((int)((uint)(fVar1 < 0.0) << 0x1f) < 0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = 1.0;
    if (fVar1 <= 1.0) {
      fVar2 = fVar1;
    }
  }
  return fVar2;
}

// ===== PlayerEgo::addNukeVolatileForce  @0x000a689c  (28 bytes)
/* PlayerEgo::addNukeVolatileForce(float) */

void __thiscall PlayerEgo::addNukeVolatileForce(PlayerEgo *this,float param_1)

{
  float in_r1;
  
  *(float *)(*(int *)this + 0x60) = in_r1 * 3.0 + *(float *)(*(int *)this + 0x60);
  return;
}

// ===== PlayerEgo::isInTurretMode  @0x000a68b8  (6 bytes)
/* PlayerEgo::isInTurretMode() */

PlayerEgo __thiscall PlayerEgo::isInTurretMode(PlayerEgo *this)

{
  return this[0x1a0];
}

// ===== PlayerEgo::setDockingCamera  @0x000a68c0  (346 bytes)
/* PlayerEgo::setDockingCamera() */

void __thiscall PlayerEgo::setDockingCamera(PlayerEgo *this)

{
  bool bVar1;
  PaintCanvas *pPVar2;
  int iVar3;
  AEGeometry *pAVar4;
  Matrix *pMVar5;
  float fVar6;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  
  if (*(int *)(this + 0x178) == 0) {
    AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0x174));
    pPVar2 = Globals::Canvas;
    iVar3 = Status::inAlienOrbit(Globals::status);
    fVar6 = 300000.0;
    if (iVar3 != 0) {
      fVar6 = 450000.0;
    }
    AbyssEngine::PaintCanvas::CameraSetPerspective((uint)pPVar2,fVar6,extraout_s1,450000.0);
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,Globals::Canvas);
    *(AEGeometry **)(this + 0x178) = pAVar4;
    AEGeometry::setRotationOrder(pAVar4,2);
    fVar6 = *(float *)(this + 0x224);
    bVar1 = fVar6 == 0.0;
    if (bVar1) {
      fVar6 = *(float *)(this + 0x228);
    }
    if ((bVar1 && (bVar1 && fVar6 == 0.0)) && (*(float *)(this + 0x22c) == 0.0)) {
      *(undefined4 *)(this + 0x228) = 0x43160000;
      *(undefined4 *)(this + 0x22c) = 0x43fa0000;
    }
    AEGeometry::translate(*(Vector **)(this + 0x178));
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,Globals::Canvas);
    *(AEGeometry **)(this + 0x19c) = pAVar4;
    AEGeometry::translate(pAVar4,extraout_s0,extraout_s1_00,extraout_s2);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x178),*(uint *)(*(int *)(this + 0x19c) + 0xc));
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,Globals::Canvas);
    *(AEGeometry **)(this + 0x17c) = pAVar4;
    AEGeometry::addChild(pAVar4,*(uint *)(*(int *)(this + 0x178) + 0xc));
  }
  AEGeometry::setPosition(*(Vector **)(this + 0x17c));
  pMVar5 = *(Matrix **)(this + 0x17c);
  AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  AEGeometry::setMatrix(pMVar5);
  AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
  return;
}

// ===== PlayerEgo::setTurretMode  @0x000a6a48  (552 bytes)
/* PlayerEgo::setTurretMode(bool) */

void __thiscall PlayerEgo::setTurretMode(PlayerEgo *this,bool param_1)

{
  PaintCanvas *pPVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  AEGeometry *pAVar5;
  Ship *this_00;
  Transform *this_01;
  Matrix *pMVar6;
  float extraout_s0;
  float fVar7;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  
  iVar2 = __stack_chk_guard;
  if (((this[0x170] == (PlayerEgo)0x0) || (*(int *)(this + 0x1e4) != 0)) ||
     (this[0x180] != (PlayerEgo)0x0)) {
    if (*(int *)(this + 0x194) != 0) {
      AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
      LevelScript::resetCamera(*(LevelScript **)(this + 0x10),*(Level **)(this + 0xc));
    }
LAB_000a6a90:
    uVar3 = 0;
  }
  else {
    this[0x1a0] = (PlayerEgo)param_1;
    if (param_1) {
      if (*(int *)(this + 0x194) != 0) goto LAB_000a6a90;
      if (*(int *)(this + 0x178) == 0) {
        AbyssEngine::PaintCanvas::CameraCreate(Globals::Canvas,(uint *)(this + 0x174));
        pPVar1 = Globals::Canvas;
        iVar4 = Status::inAlienOrbit(Globals::status);
        fVar7 = 300000.0;
        if (iVar4 != 0) {
          fVar7 = 450000.0;
        }
        AbyssEngine::PaintCanvas::CameraSetPerspective((uint)pPVar1,fVar7,extraout_s1,450000.0);
        pAVar5 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar5,Globals::Canvas);
        *(AEGeometry **)(this + 0x178) = pAVar5;
        AEGeometry::setRotationOrder(pAVar5,2);
        AEGeometry::translate(*(Vector **)(this + 0x178));
        pAVar5 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar5,Globals::Canvas);
        *(AEGeometry **)(this + 0x19c) = pAVar5;
        AEGeometry::translate(pAVar5,extraout_s0,extraout_s1_00,extraout_s2);
        AEGeometry::addChild(*(AEGeometry **)(this + 0x178),*(uint *)(*(int *)(this + 0x19c) + 0xc))
        ;
        pAVar5 = operator_new(0xc0);
        AEGeometry::AEGeometry(pAVar5,Globals::Canvas);
        *(AEGeometry **)(this + 0x17c) = pAVar5;
        AEGeometry::addChild(pAVar5,*(uint *)(*(int *)(this + 0x178) + 0xc));
        this_00 = (Ship *)Status::getShip(Globals::status);
        iVar4 = Ship::getFirstEquipmentOfSort(this_00,0x23);
        if (iVar4 != 0) {
          AEGeometry::rotate(*(Vector **)(this + 0x178));
        }
      }
      AEGeometry::setPosition(*(Vector **)(this + 0x17c));
      pMVar6 = *(Matrix **)(this + 0x17c);
      AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
      AEGeometry::setMatrix(pMVar6);
      AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
      Player::stopShooting(*(Player **)this,0);
    }
    else {
      stopShooting(this,2);
      AbyssEngine::PaintCanvas::CameraSetCurrent((uint)Globals::Canvas);
      LevelScript::resetCamera(*(LevelScript **)(this + 0x10),*(Level **)(this + 0xc));
    }
    if (*(int *)(this + 0x30) != 0) {
      this_01 = (Transform *)
                AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x30) + 0xc));
      fVar7 = (float)AbyssEngine::Transform::SetVisible(this_01,param_1);
      if (param_1) {
        FModSound::play(Globals::sound,0x8cf,(Vector *)0x0,(Vector *)0x0,fVar7);
      }
      else {
        FModSound::stop(Globals::sound,0x8cf);
      }
    }
    uVar3 = 1;
  }
  if (__stack_chk_guard == iVar2) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

// ===== PlayerEgo::isMining  @0x000a6cbc  (12 bytes)
/* PlayerEgo::isMining() */

bool __thiscall PlayerEgo::isMining(PlayerEgo *this)

{
  return *(int *)(this + 0x1e4) != 0;
}

// ===== PlayerEgo::isInRocketControl  @0x000a6cc8  (12 bytes)
/* PlayerEgo::isInRocketControl() */

bool __thiscall PlayerEgo::isInRocketControl(PlayerEgo *this)

{
  return *(int *)(this + 0x194) != 0;
}

// ===== PlayerEgo::stopShooting  @0x000a6cd4  (68 bytes)
/* PlayerEgo::stopShooting(int) */

void __thiscall PlayerEgo::stopShooting(PlayerEgo *this,int param_1)

{
  Player *this_00;
  int iVar1;
  
  this_00 = *(Player **)this;
  if (this[0x1a0] == (PlayerEgo)0x0) {
    iVar1 = Player::getHitpoints(this_00);
    if (iVar1 < 1) {
      return;
    }
    this_00 = *(Player **)this;
    if (param_1 == 1) {
      Player::stopShooting(this_00,1,*(int *)(this + 0x10c));
      return;
    }
  }
  else {
    param_1 = 2;
  }
  Player::stopShooting(this_00,param_1);
  return;
}

// ===== PlayerEgo::stopBoost  @0x000a6d18  (70 bytes)
/* PlayerEgo::stopBoost() */

void __thiscall PlayerEgo::stopBoost(PlayerEgo *this)

{
  *(undefined4 *)(this + 0xb8) = 0x40000000;
  this[0x13c] = (PlayerEgo)0x0;
  FModSound::stop(Globals::sound,0x27);
  FModSound::stop(Globals::sound,0x26);
  FModSound::stop(Globals::sound,0x29);
  FModSound::stop(Globals::sound,0x28);
  FModSound::stop(Globals::sound,0x44e);
  return;
}

// ===== PlayerEgo::isBoostRefreshed  @0x000a6d64  (30 bytes)
/* PlayerEgo::isBoostRefreshed() */

undefined4 __thiscall PlayerEgo::isBoostRefreshed(PlayerEgo *this)

{
  if (((this[0x13c] == (PlayerEgo)0x0) && (this[0x146] != (PlayerEgo)0x0)) &&
     (-1 < *(int *)(this + 0x138))) {
    return 1;
  }
  return 0;
}

// ===== PlayerEgo::boost  @0x000a6d84  (84 bytes)
/* PlayerEgo::boost() */

void __thiscall PlayerEgo::boost(PlayerEgo *this)

{
  uint in_fpscr;
  float fVar1;
  
  if ((((this[0x13c] == (PlayerEgo)0x0) && (this[0x146] != (PlayerEgo)0x0)) &&
      (*(int *)(this + 0x194) == 0)) && (-1 < *(int *)(this + 0x138))) {
    *(undefined4 *)(this + 0x138) = 0;
    fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 200),(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(this + 0xb8) = fVar1;
    this[0x13c] = (PlayerEgo)0x1;
    FModSound::play(Globals::sound,*(int *)(this + 0xd4),(Vector *)0x0,(Vector *)0x0,fVar1);
    return;
  }
  return;
}

// ===== PlayerEgo::getBoostSpeed  @0x000a6ddc  (6 bytes)
/* PlayerEgo::getBoostSpeed() */

undefined4 __thiscall PlayerEgo::getBoostSpeed(PlayerEgo *this)

{
  return *(undefined4 *)(this + 200);
}

// ===== PlayerEgo::forceBoost  @0x000a6de2  (30 bytes)
/* PlayerEgo::forceBoost() */

void __thiscall PlayerEgo::forceBoost(PlayerEgo *this)

{
  *(undefined4 *)(this + 0x138) = 0;
  this[0x13c] = (PlayerEgo)0x1;
  *(undefined4 *)(this + 0xb8) = 0x41000000;
  *(undefined4 *)(this + 0xcc) = 10000;
  *(undefined4 *)(this + 0xd0) = 0;
  return;
}

// ===== PlayerEgo::getCurrentMiningAmount  @0x000a6e00  (16 bytes)
/* PlayerEgo::getCurrentMiningAmount() */

undefined4 __thiscall PlayerEgo::getCurrentMiningAmount(PlayerEgo *this)

{
  undefined4 uVar1;
  
  if (*(MiningGame **)(this + 0x1e4) == (MiningGame *)0x0) {
    return 0;
  }
  uVar1 = MiningGame::getOreAmount(*(MiningGame **)(this + 0x1e4));
  return uVar1;
}

// ===== PlayerEgo::boosting  @0x000a6e0e  (6 bytes)
/* PlayerEgo::boosting() */

PlayerEgo __thiscall PlayerEgo::boosting(PlayerEgo *this)

{
  return this[0x13c];
}

// ===== PlayerEgo::readyToBoost  @0x000a6e14  (16 bytes)
/* PlayerEgo::readyToBoost() */

bool __thiscall PlayerEgo::readyToBoost(PlayerEgo *this)

{
  return *(uint *)(this + 0x138) < 0x80000000;
}

// ===== PlayerEgo::getBoostPercentage  @0x000a6e24  (92 bytes)
/* PlayerEgo::getBoostPercentage() */

float __thiscall PlayerEgo::getBoostPercentage(PlayerEgo *this)

{
  bool bVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x138),(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)VectorSignedToFloat(*(int *)(this + 0xcc) / 6,(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = fVar2 / fVar3;
  if ((-1 < (int)((uint)(fVar2 < 1.0) << 0x1f)) &&
     (fVar3 = 6.0 - fVar2, bVar1 = 5.0 < fVar2, fVar2 = 1.0, bVar1)) {
    fVar2 = fVar3;
  }
  return fVar2;
}

// ===== PlayerEgo::getBoostRate  @0x000a6e80  (48 bytes)
/* PlayerEgo::getBoostRate() */

float __thiscall PlayerEgo::getBoostRate(PlayerEgo *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0xd0),(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x138),(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = fVar2 / fVar1 + 1.0;
  if (0.0 < fVar2 / fVar1) {
    fVar3 = 1.0;
  }
  return fVar3;
}

// ===== PlayerEgo::getCloakRate  @0x000a6eb0  (60 bytes)
/* PlayerEgo::getCloakRate() */

float __thiscall PlayerEgo::getCloakRate(PlayerEgo *this)

{
  PlayerEgo *pPVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  float fVar4;
  
  pPVar1 = this + 0x210;
  if (this[0x1ac] == (PlayerEgo)0x0) {
    pPVar1 = this + 0x214;
  }
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)VectorSignedToFloat(*(undefined4 *)pPVar1,(byte)(in_fpscr >> 0x16) & 3);
  fVar4 = 1.0;
  if (0.0 <= fVar2 / fVar3) {
    fVar4 = fVar2 / fVar3;
  }
  return fVar4;
}

// ===== PlayerEgo::getDriveChargeRate  @0x000a6eec  (44 bytes)
/* PlayerEgo::getDriveChargeRate() */

float __thiscall PlayerEgo::getDriveChargeRate(PlayerEgo *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x200),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x1fc),(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = 1.0;
  if (0.0 <= fVar1 / fVar2) {
    fVar3 = fVar1 / fVar2;
  }
  return fVar3;
}

// ===== PlayerEgo::driveReady  @0x000a6f18  (14 bytes)
/* PlayerEgo::driveReady() */

bool __thiscall PlayerEgo::driveReady(PlayerEgo *this)

{
  return *(int *)(this + 0x200) <= *(int *)(this + 0x1fc);
}

// ===== PlayerEgo::isChargingDrive  @0x000a6f26  (6 bytes)
/* PlayerEgo::isChargingDrive() */

PlayerEgo __thiscall PlayerEgo::isChargingDrive(PlayerEgo *this)

{
  return this[0x204];
}

// ===== PlayerEgo::resetChargingDrive  @0x000a6f2c  (8 bytes)
/* PlayerEgo::resetChargingDrive() */

void __thiscall PlayerEgo::resetChargingDrive(PlayerEgo *this)

{
  this[0x204] = (PlayerEgo)0x0;
  return;
}

// ===== PlayerEgo::isChargingCloak  @0x000a6f34  (6 bytes)
/* PlayerEgo::isChargingCloak() */

PlayerEgo __thiscall PlayerEgo::isChargingCloak(PlayerEgo *this)

{
  return this[0x1ad];
}

// ===== PlayerEgo::isRechargingCloak  @0x000a6f3a  (14 bytes)
/* PlayerEgo::isRechargingCloak() */

bool __thiscall PlayerEgo::isRechargingCloak(PlayerEgo *this)

{
  return 0 < *(int *)(this + 0x20c);
}

// ===== PlayerEgo::getCloakRechargeRate  @0x000a6f48  (34 bytes)
/* PlayerEgo::getCloakRechargeRate() */

float __thiscall PlayerEgo::getCloakRechargeRate(PlayerEgo *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x368),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x20c),(byte)(in_fpscr >> 0x16) & 3);
  return 1.0 - fVar1 / fVar2;
}

// ===== PlayerEgo::readyForCloak  @0x000a6f6a  (26 bytes)
/* PlayerEgo::readyForCloak() */

undefined4 __thiscall PlayerEgo::readyForCloak(PlayerEgo *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this[0x1ad] != (PlayerEgo)0x0) && (*(int *)(this + 0x214) <= *(int *)(this + 0x208))) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== PlayerEgo::isCloaked  @0x000a6f84  (6 bytes)
/* PlayerEgo::isCloaked() */

PlayerEgo __thiscall PlayerEgo::isCloaked(PlayerEgo *this)

{
  return this[0x1ac];
}

// ===== PlayerEgo::setCollide  @0x000a6f8a  (6 bytes)
/* PlayerEgo::setCollide(bool) */

void __thiscall PlayerEgo::setCollide(PlayerEgo *this,bool param_1)

{
  this[0x144] = (PlayerEgo)param_1;
  return;
}

// ===== PlayerEgo::setLevel  @0x000a6f90  (146 bytes)
/* PlayerEgo::setLevel(Level*) */

void __thiscall PlayerEgo::setLevel(PlayerEgo *this,Level *param_1)

{
  undefined4 uVar1;
  int iVar2;
  ParticleSystemManager *pPVar3;
  
  *(Level **)(this + 0xc) = param_1;
  pPVar3 = *(ParticleSystemManager **)(param_1 + 0x74);
  uVar1 = AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,9,0);
  *(int *)(this + 0x2fc) = iVar2;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x74),iVar2,false);
  iVar2 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar2 < 2) {
    pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x78);
    uVar1 = AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
    iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,0xf,0);
    *(int *)(this + 0x300) = iVar2;
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x78),iVar2,false);
    pPVar3 = *(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x84);
    uVar1 = AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
    iVar2 = ParticleSystemManager::addSystem(pPVar3,uVar1,0x2a,0);
    *(int *)(this + 0x304) = iVar2;
    ParticleSystemManager::enableSystemEmit
              (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x84),iVar2,false);
    return;
  }
  return;
}

// ===== PlayerEgo::setRoute  @0x000a7028  (6 bytes)
/* PlayerEgo::setRoute(Route*) */

void __thiscall PlayerEgo::setRoute(PlayerEgo *this,Route *param_1)

{
  *(Route **)(this + 0xfc) = param_1;
  return;
}

// ===== PlayerEgo::getRoute  @0x000a702e  (6 bytes)
/* PlayerEgo::getRoute() */

undefined4 __thiscall PlayerEgo::getRoute(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0xfc);
}

// ===== PlayerEgo::removeRoute  @0x000a7034  (28 bytes)
/* PlayerEgo::removeRoute() */

void __thiscall PlayerEgo::removeRoute(PlayerEgo *this)

{
  void *pvVar1;
  
  if (*(Route **)(this + 0xfc) != (Route *)0x0) {
    pvVar1 = (void *)Route::~Route(*(Route **)(this + 0xfc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xfc) = 0;
  return;
}

// ===== PlayerEgo::levelCollision  @0x000a7050  (4 bytes)
/* PlayerEgo::levelCollision() */

undefined4 PlayerEgo::levelCollision(void)

{
  return 0;
}

// ===== PlayerEgo::isDead  @0x000a7054  (22 bytes)
/* PlayerEgo::isDead() */

bool __thiscall PlayerEgo::isDead(PlayerEgo *this)

{
  int iVar1;
  
  iVar1 = Player::getHitpoints(*(Player **)this);
  return iVar1 < 1;
}

// ===== PlayerEgo::getHitpoints  @0x000a706a  (8 bytes)
/* PlayerEgo::getHitpoints() */

void PlayerEgo::getHitpoints(void)

{
  undefined4 *in_r0;
  
  Player::getHitpoints((Player *)*in_r0);
  return;
}

// ===== PlayerEgo::shoot  @0x000a7070  (250 bytes)
/* PlayerEgo::shoot(int, int) */

void __thiscall PlayerEgo::shoot(PlayerEgo *this,int param_1,int param_2)

{
  Matrix *pMVar1;
  Matrix *pMVar2;
  int iVar3;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (this[0x1a0] == (PlayerEgo)0x0) {
    iVar3 = Player::getHitpoints(*(Player **)this);
    if (0 < iVar3) {
      if (param_2 == 1) {
        iVar3 = Player::shoot(*(int *)this,1,CONCAT44(param_1 >> 0x1f,*(undefined4 *)(this + 0x10c))
                              ,SUB41(param_1,0));
        if (iVar3 == 0) {
          *(undefined4 *)(this + 0x10c) = 0xffffffff;
        }
      }
      else {
        Player::shoot(*(int *)this,(longlong)param_1,false);
      }
    }
  }
  else {
    pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
    pMVar2 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x28));
    AbyssEngine::AEMath::operator*((AEMath *)&local_64,pMVar1,pMVar2);
    Player::shoot(*(undefined4 *)this,2,param_1,param_1 >> 0x1f,0,local_64,local_60,local_5c,
                  local_58,local_54,uStack_50,local_4c,uStack_48,local_44,uStack_40,local_3c,
                  uStack_38,local_34,uStack_30,uStack_2c);
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerEgo::hasAutoTurret  @0x000a7178  (6 bytes)
/* PlayerEgo::hasAutoTurret() */

PlayerEgo __thiscall PlayerEgo::hasAutoTurret(PlayerEgo *this)

{
  return this[0x180];
}

// ===== PlayerEgo::setAutoTurret  @0x000a717e  (18 bytes)
/* PlayerEgo::setAutoTurret(bool) */

void __thiscall PlayerEgo::setAutoTurret(PlayerEgo *this,bool param_1)

{
  this[0x355] = (PlayerEgo)param_1;
  if (!param_1) {
    Player::stopShooting(*(Player **)this,2);
    return;
  }
  return;
}

// ===== PlayerEgo::autoTurretIsEnabled  @0x000a718e  (6 bytes)
/* PlayerEgo::autoTurretIsEnabled() */

PlayerEgo __thiscall PlayerEgo::autoTurretIsEnabled(PlayerEgo *this)

{
  return this[0x355];
}

// ===== PlayerEgo::setTurretPosition  @0x000a7194  (60 bytes)
/* PlayerEgo::setTurretPosition(AbyssEngine::AEMath::Vector) */

void PlayerEgo::setTurretPosition
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_18 = param_2;
  uStack_14 = param_3;
  uStack_10 = param_4;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x224),(Vector *)&local_18);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::getTurretPosition  @0x000a71d8  (76 bytes)
/* PlayerEgo::getTurretPosition() */

void PlayerEgo::getTurretPosition(void)

{
  AEMath *in_r0;
  Matrix *pMVar1;
  Matrix *pMVar2;
  int in_r1;
  AEMath aAStack_54 [60];
  int local_18;
  
  local_18 = __stack_chk_guard;
  pMVar1 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(in_r1 + 8));
  pMVar2 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(in_r1 + 0x28));
  AbyssEngine::AEMath::operator*(aAStack_54,pMVar1,pMVar2);
  AbyssEngine::AEMath::MatrixGetPosition(in_r0,aAStack_54);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::checkForTurret  @0x000a722c  (1058 bytes)
/* PlayerEgo::checkForTurret() */

void __thiscall PlayerEgo::checkForTurret(PlayerEgo *this)

{
  int iVar1;
  Ship *this_00;
  undefined4 uVar2;
  int iVar3;
  AEGeometry *pAVar4;
  void *pvVar5;
  Transform *this_01;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float fVar10;
  float extraout_s0_02;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar11;
  float extraout_s1_02;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar12;
  float extraout_s2_02;
  double dVar13;
  int local_48;
  
  if (this[0x170] != (PlayerEgo)0x0) {
    return;
  }
  iVar1 = Player::gunAvailable(*(Player **)this,2);
  this[0x170] = SUB41(iVar1,0);
  if (iVar1 == 0) {
    return;
  }
  this[0x180] = (PlayerEgo)0x0;
  this_00 = (Ship *)Status::getShip(Globals::status);
  iVar1 = Ship::getEquipment(this_00,2);
  uVar2 = Item::getAttribute((Item *)**(undefined4 **)(iVar1 + 4),0x11);
  dVar13 = (double)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x1f8) = (int)(longlong)(dVar13 * 1.5);
  iVar3 = Item::getIndex((Item *)**(undefined4 **)(iVar1 + 4));
  uVar6 = 0xffff;
  if (iVar3 < 0xb6) {
    if (iVar3 < 0x31) {
      if (iVar3 == 0x2f) {
        uVar7 = 0x1a72;
        uVar6 = 0x1a73;
      }
      else {
        if (iVar3 != 0x30) goto LAB_000a763a;
        uVar7 = 0x1a74;
        uVar6 = 0x1a75;
      }
    }
    else if (iVar3 == 0x31) {
      uVar7 = 0x1a76;
      uVar6 = 0x1a77;
    }
    else if (iVar3 == 0xb4) {
      this[0x180] = (PlayerEgo)0x1;
      uVar7 = 0x1a95;
      uVar6 = 0x1a96;
    }
    else {
      if (iVar3 != 0xb5) goto LAB_000a763a;
      this[0x180] = (PlayerEgo)0x1;
      uVar7 = 0x1a97;
      uVar6 = 0x1a98;
    }
LAB_000a73e4:
    iVar9 = -1;
    iVar8 = -1;
  }
  else {
    if (iVar3 < 199) {
      if (iVar3 == 0xb6) {
        uVar7 = 0x1a99;
        this[0x180] = (PlayerEgo)0x1;
        uVar6 = 0x1a9a;
      }
      else {
        if (iVar3 == 0xc6) {
          local_48 = 0x4a7f;
          iVar3 = -1;
          uVar7 = 0x4963;
          iVar9 = 0x4966;
          iVar8 = 0x4964;
          uVar6 = 0x4967;
          goto LAB_000a73ee;
        }
LAB_000a763a:
        uVar7 = 0xffff;
      }
      goto LAB_000a73e4;
    }
    if (iVar3 == 199) {
      local_48 = 0x4a7f;
      iVar3 = -1;
      uVar7 = 0x4968;
      iVar9 = 0x496a;
      iVar8 = 0x4969;
      uVar6 = 0x496b;
      goto LAB_000a73ee;
    }
    if (iVar3 == 200) {
      local_48 = 0x4a7f;
      iVar3 = 0x4970;
      uVar7 = 0x496c;
      iVar9 = 0x496e;
      iVar8 = 0x496d;
      uVar6 = 0x496f;
      goto LAB_000a73ee;
    }
    if (iVar3 != 0xe0) goto LAB_000a763a;
    uVar7 = 0x499a;
    iVar9 = 0x499d;
    iVar8 = 0x499c;
    uVar6 = 0x499b;
  }
  iVar3 = -1;
  local_48 = -1;
LAB_000a73ee:
  pAVar4 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar4,uVar7,Globals::Canvas,false);
  *(AEGeometry **)(this + 0xdc) = pAVar4;
  pAVar4 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar4,uVar6,Globals::Canvas,false);
  *(AEGeometry **)(this + 0x28) = pAVar4;
  AEGeometry::setRotationOrder(pAVar4,2);
  pAVar4 = operator_new(0xc0);
  AEGeometry::AEGeometry(pAVar4,Globals::Canvas);
  *(AEGeometry **)(this + 0x2c) = pAVar4;
  if (iVar8 != -1) {
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,(ushort)iVar8,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0xdc),*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
  }
  if (iVar9 != -1) {
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,(ushort)iVar9,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x28),*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
  }
  if (iVar3 != -1) {
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,(ushort)iVar3,Globals::Canvas,false);
    AEGeometry::addChild(*(AEGeometry **)(this + 0x28),*(uint *)(pAVar4 + 0xc));
    pvVar5 = (void *)AEGeometry::~AEGeometry(pAVar4);
    operator_delete(pvVar5);
  }
  if (local_48 != -1) {
    pAVar4 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar4,(ushort)local_48,Globals::Canvas,false);
    *(AEGeometry **)(this + 0x30) = pAVar4;
    AEGeometry::addChild(*(AEGeometry **)(this + 0x28),*(uint *)(pAVar4 + 0xc));
    this_01 = (Transform *)
              AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(this + 0x30) + 0xc));
    AbyssEngine::Transform::SetVisible(this_01,(bool)this[0x1a0]);
  }
  iVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0x2c) + 0xc));
  *(undefined4 *)(iVar3 + 0xe0) = 0x49742400;
  uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar2,2,0);
  AEGeometry::setPosition(*(Vector **)(this + 0xdc));
  AEGeometry::setPosition(*(Vector **)(this + 0x28));
  AEGeometry::translate(*(AEGeometry **)(this + 0x28),extraout_s0,extraout_s1,extraout_s2);
  iVar3 = Item::getIndex((Item *)**(undefined4 **)(iVar1 + 4));
  fVar10 = extraout_s0_00;
  fVar11 = extraout_s1_00;
  fVar12 = extraout_s2_00;
  if ((iVar3 < 0xc6) ||
     (iVar1 = Item::getIndex((Item *)**(undefined4 **)(iVar1 + 4)), fVar10 = extraout_s0_01,
     fVar11 = extraout_s1_01, fVar12 = extraout_s2_01, 200 < iVar1)) {
    AEGeometry::rotate(*(AEGeometry **)(this + 0xdc),fVar10,fVar11,fVar12);
    AEGeometry::rotate(*(AEGeometry **)(this + 0x28),extraout_s0_02,extraout_s1_02,extraout_s2_02);
  }
  AEGeometry::addChild(*(AEGeometry **)(this + 0x2c),*(uint *)(*(int *)(this + 0xdc) + 0xc));
  AEGeometry::addChild(*(AEGeometry **)(this + 0x2c),*(uint *)(*(int *)(this + 0x28) + 0xc));
  if ((*(int *)(this + 0x1b0) != 0) && (this[0x170] != (PlayerEgo)0x0)) {
    AbyssEngine::PaintCanvas::MeshCloneMaterial
              (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0x1c),(uint *)(this + 0x38c));
    AbyssEngine::PaintCanvas::MeshCloneMaterial
              (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0x1c),(uint *)(this + 0x390));
    return;
  }
  return;
}

// ===== PlayerEgo::addGun  @0x000a76c4  (22 bytes)
/* PlayerEgo::addGun(Gun*, int) */

void __thiscall PlayerEgo::addGun(PlayerEgo *this,Gun *param_1,int param_2)

{
  Player::addGun(*(Player **)this,param_1,param_2);
  checkForTurret(this);
  return;
}

// ===== PlayerEgo::addGun  @0x000a76da  (24 bytes)
/* PlayerEgo::addGun(Array<Gun*>*, int) */

void __thiscall PlayerEgo::addGun(PlayerEgo *this,Array *param_1,int param_2)

{
  Player::addGun(*(Player **)this,param_1,param_2);
  checkForTurret(this);
  return;
}

// ===== PlayerEgo::getHullDamageRate  @0x000a76f0  (8 bytes)
/* PlayerEgo::getHullDamageRate() */

void PlayerEgo::getHullDamageRate(void)

{
  undefined4 *in_r0;
  
  Player::getDamageRate((Player *)*in_r0);
  return;
}

// ===== PlayerEgo::getShieldDamageRate  @0x000a76f6  (8 bytes)
/* PlayerEgo::getShieldDamageRate() */

void PlayerEgo::getShieldDamageRate(void)

{
  undefined4 *in_r0;
  
  Player::getShieldDamageRate((Player *)*in_r0);
  return;
}

// ===== PlayerEgo::getCurrentSecondaryWeaponIndex  @0x000a76fc  (6 bytes)
/* PlayerEgo::getCurrentSecondaryWeaponIndex() */

undefined4 __thiscall PlayerEgo::getCurrentSecondaryWeaponIndex(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x10c);
}

// ===== PlayerEgo::setCurrentSecondaryWeaponIndex  @0x000a7704  (18 bytes)
/* PlayerEgo::setCurrentSecondaryWeaponIndex(int) */

void __thiscall PlayerEgo::setCurrentSecondaryWeaponIndex(PlayerEgo *this,int param_1)

{
  *(int *)(this + 0x10c) = param_1;
  *(int *)(Globals::status + 0xf4) = param_1;
  return;
}

// ===== PlayerEgo::GetUpVector  @0x000a771c  (12 bytes)
/* PlayerEgo::GetUpVector() */

void PlayerEgo::GetUpVector(void)

{
  AEGeometry::getUpVector();
  return;
}

// ===== PlayerEgo::GetDirVector  @0x000a7728  (12 bytes)
/* PlayerEgo::GetDirVector() */

void PlayerEgo::GetDirVector(void)

{
  AEGeometry::getDirection();
  return;
}

// ===== PlayerEgo::getPosition  @0x000a7734  (12 bytes)
/* PlayerEgo::getPosition() */

void PlayerEgo::getPosition(void)

{
  AEGeometry::getPosition();
  return;
}

// ===== PlayerEgo::setActive  @0x000a7740  (6 bytes)
/* PlayerEgo::setActive(bool) */

void __thiscall PlayerEgo::setActive(PlayerEgo *this,bool param_1)

{
  Player::setActive(*(Player **)this,param_1);
  return;
}

// ===== PlayerEgo::setComputerControlled  @0x000a7746  (6 bytes)
/* PlayerEgo::setComputerControlled(bool) */

void __thiscall PlayerEgo::setComputerControlled(PlayerEgo *this,bool param_1)

{
  this[500] = (PlayerEgo)param_1;
  return;
}

// ===== PlayerEgo::setFreeze  @0x000a774c  (6 bytes)
/* PlayerEgo::setFreeze(bool) */

void __thiscall PlayerEgo::setFreeze(PlayerEgo *this,bool param_1)

{
  this[0x24] = (PlayerEgo)param_1;
  return;
}

// ===== PlayerEgo::setAutoPilot  @0x000a7754  (94 bytes)
/* PlayerEgo::setAutoPilot(KIPlayer*) */

void __thiscall PlayerEgo::setAutoPilot(PlayerEgo *this,KIPlayer *param_1)

{
  PlayerEgo PVar1;
  int iVar2;
  PlayerEgo PVar3;
  
  *(KIPlayer **)(this + 0x15c) = param_1;
  PVar3 = SUB41(param_1,0);
  this[0x160] = (PlayerEgo)0x0;
  PVar1 = this[0x158];
  if (param_1 != (KIPlayer *)0x0) {
    PVar3 = (PlayerEgo)0x1;
  }
  this[0x158] = PVar3;
  if (param_1 == (KIPlayer *)0x0) {
    *(undefined4 *)(*(int *)(this + 0x14) + 0x2c) = 0;
    if (PVar1 != (PlayerEgo)0x0) {
      *(undefined4 *)(this + 0x2a4) = 0;
      this[0x2a8] = (PlayerEgo)0x0;
      return;
    }
  }
  else {
    if (param_1[0x6e] != (KIPlayer)0x0) {
      this[0x160] = (PlayerEgo)0x1;
    }
    iVar2 = AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
    *(undefined4 *)(iVar2 + 0x350) = 0;
    *(undefined4 *)(this + 0xbc) = 0x3f800000;
  }
  return;
}

// ===== PlayerEgo::setThrust  @0x000a77b8  (6 bytes)
/* PlayerEgo::setThrust(float) */

void __thiscall PlayerEgo::setThrust(PlayerEgo *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xbc) = in_r1;
  return;
}

// ===== PlayerEgo::getAutoPilotTarget  @0x000a77be  (6 bytes)
/* PlayerEgo::getAutoPilotTarget() */

undefined4 __thiscall PlayerEgo::getAutoPilotTarget(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x15c);
}

// ===== PlayerEgo::goingToPlanet  @0x000a77c4  (58 bytes)
/* PlayerEgo::goingToPlanet() */

undefined4 __thiscall PlayerEgo::goingToPlanet(PlayerEgo *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((this[0x158] != (PlayerEgo)0x0) &&
     (iVar3 = *(int *)(this + 0x15c), iVar1 = Level::getLandmarks(*(Level **)(this + 0xc)),
     iVar3 != *(int *)(*(int *)(iVar1 + 4) + 4))) {
    iVar1 = goingToStation(this);
    uVar2 = 0;
    if ((iVar1 == 0) && (this[0x160] == (PlayerEgo)0x0)) {
      uVar2 = 1;
    }
    return uVar2;
  }
  return 0;
}

// ===== PlayerEgo::isAutoPilot  @0x000a77fe  (6 bytes)
/* PlayerEgo::isAutoPilot() */

PlayerEgo __thiscall PlayerEgo::isAutoPilot(PlayerEgo *this)

{
  return this[0x158];
}

// ===== PlayerEgo::goingToStream  @0x000a7804  (30 bytes)
/* PlayerEgo::goingToStream() */

bool __thiscall PlayerEgo::goingToStream(PlayerEgo *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x15c);
  iVar1 = Level::getLandmarks(*(Level **)(this + 0xc));
  return iVar2 == *(int *)(*(int *)(iVar1 + 4) + 4);
}

// ===== PlayerEgo::goingToStation  @0x000a7822  (44 bytes)
/* PlayerEgo::goingToStation() */

undefined4 __thiscall PlayerEgo::goingToStation(PlayerEgo *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = Level::getLandmarks(*(Level **)(this + 0xc));
  uVar2 = 0;
  if ((**(int **)(iVar1 + 4) != 0) &&
     (iVar3 = *(int *)(this + 0x15c), iVar1 = Level::getLandmarks(*(Level **)(this + 0xc)),
     iVar3 == **(int **)(iVar1 + 4))) {
    uVar2 = 1;
  }
  return uVar2;
}

// ===== PlayerEgo::goingToWaypoint  @0x000a784e  (6 bytes)
/* PlayerEgo::goingToWaypoint() */

PlayerEgo __thiscall PlayerEgo::goingToWaypoint(PlayerEgo *this)

{
  return this[0x160];
}

// ===== PlayerEgo::goingToWormhole  @0x000a7854  (30 bytes)
/* PlayerEgo::goingToWormhole() */

bool __thiscall PlayerEgo::goingToWormhole(PlayerEgo *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x15c);
  iVar1 = Level::getLandmarks(*(Level **)(this + 0xc));
  return iVar2 == *(int *)(*(int *)(iVar1 + 4) + 0xc);
}

// ===== PlayerEgo::setPosition  @0x000a7874  (58 bytes)
/* PlayerEgo::setPosition(float, float, float) */

void PlayerEgo::setPosition(float param_1,float param_2,float param_3)

{
  int iVar1;
  int in_r0;
  
  iVar1 = __stack_chk_guard;
  AEGeometry::setPosition(*(Vector **)(in_r0 + 8));
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::setPosition  @0x000a78b8  (58 bytes)
/* PlayerEgo::setPosition(AbyssEngine::AEMath::Vector) */

void PlayerEgo::setPosition(int param_1)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  AEGeometry::setPosition(*(Vector **)(param_1 + 8));
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::isInWormhole  @0x000a78fc  (32 bytes)
/* PlayerEgo::isInWormhole() */

bool __thiscall PlayerEgo::isInWormhole(PlayerEgo *this)

{
  int iVar1;
  
  iVar1 = Player::getHitpoints(*(Player **)this);
  if (0 < iVar1) {
    return this[0x25] != (PlayerEgo)0x0;
  }
  return false;
}

// ===== PlayerEgo::handleTurretView  @0x000a791c  (714 bytes)
/* PlayerEgo::handleTurretView(int) */

void __thiscall PlayerEgo::handleTurretView(PlayerEgo *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  Matrix *pMVar3;
  Matrix *pMVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint in_fpscr;
  uint uVar8;
  float fVar9;
  float fVar10;
  AEMath aAStack_d0 [60];
  float local_94;
  float local_90;
  float local_8c;
  AEMath aAStack_88 [12];
  float local_7c;
  float local_78;
  float local_74;
  AEMath aAStack_70 [60];
  int local_34;
  
  local_34 = __stack_chk_guard;
  if (((*(int *)(this + 0x15c) == 0) || (this[0x1ed] != (PlayerEgo)0x0)) &&
     ((this[0x356] == (PlayerEgo)0x0 || (*(int *)(this + 0x1c4) != 1)))) {
    fVar9 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::moveForward
              (*(AEGeometry **)(this + 8),fVar9 * *(float *)(this + 0xbc) * *(float *)(this + 0xb8))
    ;
  }
  pMVar3 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  pMVar4 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x178));
  AbyssEngine::AEMath::operator*(aAStack_70,pMVar3,pMVar4);
  pMVar3 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x19c));
  AbyssEngine::AEMath::Matrix::operator*=((Matrix *)aAStack_70,pMVar3);
  if ((this[0x32c] != (PlayerEgo)0x0) || (this[0x13c] != (PlayerEgo)0x0)) {
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_7c,aAStack_70);
    AbyssEngine::AEMath::MatrixGetUp(aAStack_88,aAStack_70);
    AbyssEngine::AEMath::MatrixGetDir(aAStack_d0,aAStack_70);
    AbyssEngine::AEMath::operator-((AEMath *)&local_94,(Vector *)&local_7c,(Vector *)aAStack_d0);
    if (this[0x32c] != (PlayerEgo)0x0) {
      iVar5 = *(int *)(this + 0x328);
      *(int *)(this + 0x328) = iVar5 + param_1;
      if (1000 < iVar5 + param_1) {
        this[0x32c] = (PlayerEgo)0x0;
      }
      iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xc);
      fVar9 = (float)VectorSignedToFloat(iVar5 + -6,(byte)(in_fpscr >> 0x16) & 3);
      local_7c = local_7c + fVar9 * 0.001;
      iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xc);
      fVar9 = (float)VectorSignedToFloat(iVar5 + -6,(byte)(in_fpscr >> 0x16) & 3);
      local_78 = local_78 + fVar9 * 0.001;
      iVar5 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xc);
      fVar9 = (float)VectorSignedToFloat(iVar5 + -6,(byte)(in_fpscr >> 0x16) & 3);
      local_74 = local_74 + fVar9 * 0.001;
    }
    if (this[0x13c] != (PlayerEgo)0x0) {
      fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x138),(byte)(in_fpscr >> 0x16) & 3)
      ;
      fVar10 = (float)VectorSignedToFloat(*(int *)(this + 0xcc) / 6,(byte)(in_fpscr >> 0x16) & 3);
      fVar9 = fVar9 / fVar10;
      uVar8 = in_fpscr & 0xfffffff;
      if (1.0 <= fVar9) {
        uVar1 = uVar8 | (uint)(fVar9 < 5.0) << 0x1f | (uint)(fVar9 == 5.0) << 0x1e;
        uVar8 = uVar1 | (uint)NAN(fVar9) << 0x1c;
        bVar2 = (byte)(uVar1 >> 0x18);
        fVar10 = 6.0 - fVar9;
        fVar9 = 1.0;
        if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar8 >> 0x1c) & 1)) {
          fVar9 = fVar10;
        }
      }
      iVar6 = *(int *)(this + 200);
      iVar5 = iVar6;
      if (iVar6 < 2) {
        iVar5 = 2;
      }
      if (7 < iVar6) {
        iVar5 = 8;
      }
      iVar7 = iVar5 << 1;
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar7);
      fVar10 = (float)VectorSignedToFloat(iVar6 - iVar5,(byte)(uVar8 >> 0x16) & 3);
      local_94 = local_94 + fVar9 * fVar10 * 0.0015;
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar7);
      fVar10 = (float)VectorSignedToFloat(iVar6 - iVar5,(byte)(uVar8 >> 0x16) & 3);
      local_90 = local_90 + fVar9 * fVar10 * 0.0015;
      iVar6 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar7);
      fVar10 = (float)VectorSignedToFloat(iVar6 - iVar5,(byte)(uVar8 >> 0x16) & 3);
      local_8c = local_8c + fVar9 * fVar10 * 0.0015;
    }
    AbyssEngine::AEMath::MatrixGetLookAt
              (aAStack_d0,(Vector *)&local_7c,(Vector *)&local_94,(Vector *)aAStack_88);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)aAStack_70,aAStack_d0);
  }
  AbyssEngine::PaintCanvas::CameraSetLocal(Globals::Canvas,*(uint *)(this + 0x174),aAStack_70);
  *(undefined8 *)(this + 0x100) = 0;
  roll(this,*(int *)(this + 0x134));
  iVar5 = *(int *)this;
  pMVar3 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
  pMVar4 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::AEMath::operator*(aAStack_d0,pMVar3,pMVar4);
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar5 + 4),aAStack_d0);
  if (__stack_chk_guard == local_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerEgo::roll  @0x000a7c04  (424 bytes)
/* PlayerEgo::roll(int) */

void __thiscall PlayerEgo::roll(PlayerEgo *this,int param_1)

{
  byte bVar1;
  PlayerEgo PVar2;
  int iVar3;
  float *pfVar4;
  uint in_fpscr;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float extraout_s1;
  float fVar8;
  float fVar9;
  AEMath aAStack_54 [60];
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (this[0x2f4] == (PlayerEgo)0x0) goto LAB_000a7cf6;
  iVar3 = AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  fVar7 = *(float *)(iVar3 + 0x10);
  fVar8 = *(float *)(iVar3 + 0x14);
  uVar6 = in_fpscr & 0xfffffff | (uint)(fVar8 < 0.0) << 0x1f | (uint)(fVar8 == 0.0) << 0x1e;
  fVar9 = -fVar7;
  if (0.0 < fVar7) {
    fVar9 = fVar7;
  }
  if (0x3c < param_1) {
    param_1 = 0x3c;
  }
  bVar1 = (byte)(uVar6 >> 0x18);
  if ((!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar8)) &&
     (uVar6 = in_fpscr & 0xfffffff, fVar9 < 0.015)) {
    AbyssEngine::AEMath::MatrixIdentity(aAStack_54,(Matrix *)(this + 0x2ac));
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x2ac),aAStack_54);
    this[0x2f4] = (PlayerEgo)0x0;
    this[0x2a9] = (PlayerEgo)0x0;
    this[0x324] = (PlayerEgo)0x0;
    goto LAB_000a7cf6;
  }
  if (this[0x324] == (PlayerEgo)0x0) {
    uVar6 = uVar6 & 0xfffffff;
    uVar5 = uVar6 | (uint)(fVar7 < 0.0) << 0x1f;
    if ((fVar7 == 0.0 || SUB41(uVar5 >> 0x1f,0) != NAN(fVar7)) || (this[0x2a9] != (PlayerEgo)0x1)) {
      uVar5 = uVar6;
      if (0.0 <= fVar7) {
        if ((NAN(fVar7)) || (0.0 <= fVar8)) {
LAB_000a7d6c:
          uVar5 = uVar6 | (uint)(fVar7 < 0.0) << 0x1f;
          if ((fVar7 != 0.0 && SUB41(uVar5 >> 0x1f,0) == NAN(fVar7)) &&
             (uVar5 = uVar6 | (uint)(fVar8 < 0.0) << 0x1f,
             fVar8 != 0.0 && SUB41(uVar5 >> 0x1f,0) == NAN(fVar8))) {
            fVar8 = 0.3;
            pfVar4 = (float *)&UNK_000a7dd8;
            if (0.3 < fVar7) {
              pfVar4 = (float *)&DAT_000a7ddc;
            }
LAB_000a7da6:
            fVar9 = *pfVar4;
            uVar5 = uVar6;
          }
        }
        else {
          fVar9 = -0.00075;
        }
      }
      else if (this[0x2a9] == (PlayerEgo)0x2) {
        fVar9 = 0.00035;
        this[0x324] = (PlayerEgo)0x1;
      }
      else {
        if (0.0 <= fVar8) {
          if (NAN(fVar8)) goto LAB_000a7d6c;
          fVar8 = -0.3;
          pfVar4 = (float *)&DAT_000a7dcc;
          uVar6 = uVar6 | (uint)(fVar7 < -0.3) << 0x1f;
          if (fVar7 != -0.3 && SUB41(uVar6 >> 0x1f,0) == NAN(fVar7)) {
            pfVar4 = (float *)&DAT_000a7dd0;
          }
          goto LAB_000a7da6;
        }
        fVar9 = 0.00075;
      }
    }
    else {
      fVar9 = -0.00035;
      this[0x324] = (PlayerEgo)0x1;
    }
  }
  else {
    pfVar4 = (float *)&DAT_000a7db8;
    if (!NAN(fVar8)) {
      pfVar4 = (float *)&DAT_000a7dbc;
    }
    fVar8 = *pfVar4;
    uVar5 = uVar6 & 0xfffffff;
    fVar9 = -0.0002;
    if (fVar7 < 0.0) {
      fVar9 = fVar8;
    }
  }
  uVar6 = uVar5 & 0xfffffff | (uint)(fVar7 < 0.0) << 0x1f | (uint)(fVar7 == 0.0) << 0x1e;
  uVar5 = uVar6 | (uint)NAN(fVar7) << 0x1c;
  if ((int)uVar6 < 0) {
    PVar2 = (PlayerEgo)0x1;
LAB_000a7cc2:
    this[0x2a9] = PVar2;
  }
  else if (!(bool)((byte)(uVar6 >> 0x1e) & 1) && ((byte)(uVar5 >> 0x1c) & 1) == 0) {
    PVar2 = (PlayerEgo)0x2;
    goto LAB_000a7cc2;
  }
  fVar7 = (float)VectorSignedToFloat(param_1,(byte)(uVar5 >> 0x16) & 3);
  this[0x2f4] = (PlayerEgo)0x1;
  AbyssEngine::AEMath::MatrixSetRotation(aAStack_54,fVar7 * fVar9,extraout_s1,fVar8);
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x2ac),aAStack_54);
LAB_000a7cf6:
  if (__stack_chk_guard == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerEgo::handleShip  @0x000a7df0  (866 bytes)
/* PlayerEgo::handleShip(int) */

void __thiscall PlayerEgo::handleShip(PlayerEgo *this,int param_1)

{
  uint uVar1;
  byte bVar2;
  Event *pEVar3;
  int iVar4;
  undefined4 *puVar5;
  Matrix *pMVar6;
  Matrix *pMVar7;
  uint in_fpscr;
  float fVar8;
  float extraout_s1;
  float extraout_s1_00;
  float fVar9;
  AEMath aAStack_11c [12];
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  undefined4 local_b0 [5];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  float local_68;
  float local_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int local_34;
  
  pEVar3 = Globals::sound;
  local_34 = __stack_chk_guard;
  iVar4 = Player::GetEngineEvent(*(Player **)this);
  in_fpscr = in_fpscr & 0xfffffff;
  FModSound::setParamValue(pEVar3,iVar4,*(float *)(this + 0x268));
  pEVar3 = Globals::sound;
  iVar4 = Player::GetEngineEvent(*(Player **)this);
  FModSound::setParamValue(pEVar3,iVar4,*(float *)(this + 0x268) * 0.2 + 0.5);
  puVar5 = (undefined4 *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
  uStack_94 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_90 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_8c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_70 = *puVar5;
  local_6c = puVar5[1];
  local_68 = (float)puVar5[2];
  local_64 = (float)puVar5[3];
  local_60 = puVar5[4];
  local_5c = puVar5[5];
  local_58 = (float)puVar5[6];
  local_54 = (float)puVar5[7];
  local_50 = puVar5[8];
  local_4c = puVar5[9];
  local_48 = (float)puVar5[10];
  local_44 = (float)puVar5[0xb];
  uStack_40 = puVar5[0xc];
  uStack_3c = puVar5[0xd];
  uStack_38 = puVar5[0xe];
  puVar5 = (undefined4 *)((uint)local_b0 | 4);
  local_b0[0] = 0x3f800000;
  *puVar5 = 0;
  puVar5[1] = uStack_94;
  puVar5[2] = uStack_90;
  puVar5[3] = uStack_8c;
  local_9c = 0x3f800000;
  local_98 = 0;
  local_88 = 0x3f800000;
  uStack_80 = 0x3f8000003f800000;
  local_78 = 0x3f800000;
  fVar9 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::MatrixSetRotation
            ((Matrix *)&local_ec,
             fVar9 * *(float *)(this + 0x27c) * 1.5258789e-05 * 6.2831855 * 0.033,extraout_s1,
             fVar9 * *(float *)(this + 0x278) * 1.5258789e-05 * 6.2831855 * 0.033);
  *(undefined4 *)(this + 0x280) = *(undefined4 *)(this + 0x27c);
  AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_70,(Matrix *)local_b0);
  if (this[0x2f4] != (PlayerEgo)0x0) {
    AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_70,this + 0x2ac);
  }
  fVar9 = fVar9 * *(float *)(this + 0xbc) * *(float *)(this + 0xb8);
  local_f8 = local_68;
  local_64 = local_64 + local_68 * fVar9;
  local_f4 = local_58;
  local_54 = local_54 + fVar9 * local_58;
  local_f0 = local_48;
  local_44 = local_44 + fVar9 * local_48;
  local_104 = local_6c;
  local_100 = local_5c;
  local_fc = local_4c;
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_ec,(Vector *)&local_f8);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_f8,(Vector *)&local_ec);
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_ec,(Vector *)&local_104);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_104,(Vector *)&local_ec);
  AbyssEngine::AEMath::VectorCross((AEMath *)&local_110,(Vector *)&local_104,(Vector *)&local_f8);
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_ec,(Vector *)&local_110);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_110,(Vector *)&local_ec);
  local_70 = local_110;
  local_60 = local_10c;
  local_50 = local_108;
  local_6c = local_104;
  local_5c = local_100;
  local_4c = local_fc;
  local_68 = local_f8;
  local_58 = local_f4;
  local_48 = local_f0;
  fVar8 = *(float *)(this + 0x37c);
  fVar9 = -fVar8;
  if (0.0 < fVar8) {
    fVar9 = fVar8;
  }
  uVar1 = in_fpscr & 0xfffffff | (uint)(fVar9 < 0.01) << 0x1f | (uint)(fVar9 == 0.01) << 0x1e;
  bVar2 = (byte)(uVar1 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar9)) {
    *(undefined4 *)(this + 0x380) = 0x3dcccccd;
  }
  else {
    local_ec = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(uVar1 >> 0x16) & 3);
    local_ec = fVar8 * local_ec;
    local_e8 = 0.0;
    local_e4 = 0.0;
    AbyssEngine::AEMath::MatrixRotateVector(aAStack_11c,(Matrix *)&local_70,(Vector *)&local_ec);
    AbyssEngine::AEMath::Vector::operator=((Vector *)&local_ec,(Vector *)aAStack_11c);
    local_64 = local_ec + local_64;
    local_54 = local_e8 + local_54;
    local_44 = local_e4 + local_44;
    fVar9 = *(float *)(this + 0x37c);
    *(float *)(this + 0x37c) = fVar9 * 0.7;
    TargetFollowCamera::translateNoUpdate
              (*(TargetFollowCamera **)(this + 0x88),fVar9 * 0.7,extraout_s1_00,0.7);
  }
  AbyssEngine::PaintCanvas::TransformSetLocal
            (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc),(Matrix *)&local_70);
  *(undefined4 *)(this + 600) = 0;
  *(undefined4 *)(this + 0x25c) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x270) = 0;
  *(undefined4 *)(this + 0x268) = 0;
  iVar4 = *(int *)this;
  pMVar6 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
  pMVar7 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::AEMath::operator*((AEMath *)&local_ec,pMVar6,pMVar7);
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar4 + 4),(AEMath *)&local_ec);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::getCloakingPercentage  @0x000a81a0  (118 bytes)
/* PlayerEgo::getCloakingPercentage() */

float __thiscall PlayerEgo::getCloakingPercentage(PlayerEgo *this)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  fVar2 = 0.0;
  if ((this[0x1ac] != (PlayerEgo)0x0) && (iVar1 = *(int *)(this + 0x208), -1 < iVar1)) {
    if (iVar1 < 2000) {
      fVar2 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
      fVar2 = (fVar2 * 100.0) / 2000.0;
    }
    else if (*(int *)(this + 0x210) + -2000 < iVar1) {
      fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0x210) + -2000,(byte)(in_fpscr >> 0x16) & 3
                                        );
      fVar3 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
      fVar2 = ((fVar3 - fVar2) / -2000.0 + 1.0) * 100.0;
    }
    else {
      fVar2 = 100.0;
    }
  }
  return fVar2;
}

// ===== PlayerEgo::updateManeuver  @0x000a8230  (1180 bytes)
/* PlayerEgo::updateManeuver() */

void __thiscall PlayerEgo::updateManeuver(PlayerEgo *this)

{
  Matrix *pMVar1;
  undefined8 *puVar2;
  Matrix *pMVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  AEGeometry *pAVar6;
  int iVar7;
  uint in_fpscr;
  float fVar8;
  float extraout_s0;
  float fVar9;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s2;
  float extraout_s2_00;
  float fVar10;
  AEMath local_10c [60];
  undefined4 local_d0 [5];
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 local_98;
  AEMath aAStack_90 [12];
  AEMath aAStack_84 [12];
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  float local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  float local_50 [2];
  float local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  if (*(int *)(this + 0x334) - 1U < 2) {
    *(int *)(this + 0x350) = *(int *)(this + 0x134) + *(int *)(this + 0x350);
    AEGeometry::getRightVector();
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    fVar8 = (float)AbyssEngine::AEMath::operator*(local_10c,(Vector *)&local_60,fVar8);
    AbyssEngine::AEMath::operator*((AEMath *)local_d0,(Vector *)local_10c,fVar8);
    fVar10 = 1.0;
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x350),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator*((AEMath *)local_50,(Vector *)local_d0,fVar8 / -1200.0 + 1.0);
    fVar8 = (float)AbyssEngine::AEMath::Vector::operator*=
                             ((Vector *)local_50,*(float *)(this + 0x154) * 0.05);
    if (*(int *)(this + 0x334) == 2) {
      AbyssEngine::AEMath::Vector::operator*=((Vector *)local_50,fVar8);
    }
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::moveForward
              (*(AEGeometry **)(this + 8),fVar8 * *(float *)(this + 0xbc) * *(float *)(this + 0xb8))
    ;
    AEGeometry::translate(*(AEGeometry **)(this + 8),extraout_s0,extraout_s1,extraout_s2);
    uStack_b4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_b0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_ac = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar5 = (undefined4 *)((uint)local_d0 | 4);
    local_d0[0] = 0x3f800000;
    *puVar5 = 0;
    puVar5[1] = uStack_b4;
    puVar5[2] = uStack_b0;
    puVar5[3] = uStack_ac;
    local_bc = 0x3f800000;
    local_b8 = 0;
    local_a8 = 0x3f800000;
    uStack_a0 = 0x3f8000003f800000;
    local_98 = 0x3f800000;
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x350),(byte)(in_fpscr >> 0x16) & 3);
    fVar8 = 1.0;
    if (*(int *)(this + 0x334) == 1) {
      fVar8 = -1.0;
    }
    AbyssEngine::AEMath::MatrixSetRotation
              (local_10c,fVar8 * (1.0 - fVar9 / 1200.0) * 0.006283186,extraout_s1_00,0.006283186);
    pAVar6 = *(AEGeometry **)(this + 8);
    pMVar1 = (Matrix *)AEGeometry::getMatrix(pAVar6);
    AbyssEngine::AEMath::operator*(local_10c,pMVar1,(AEMath *)local_d0);
    AEGeometry::setMatrix(pAVar6);
    VectorSignedToFloat(*(undefined4 *)(this + 0x350),(byte)(in_fpscr >> 0x16) & 3);
    fVar9 = *(float *)(this + 0x154) * 0.05 * 750.0;
    fVar8 = (float)AbyssEngine::AEMath::Sinf(fVar9);
    if (*(int *)(this + 0x334) == 1) {
      fVar10 = -1.0;
    }
    *(float *)(this + 0x27c) = fVar8 * fVar9 * 0.4 * fVar10;
    puVar2 = (undefined8 *)
             TargetFollowCamera::getTargetOffset(*(TargetFollowCamera **)(this + 0x88));
    local_58 = *(undefined4 *)(puVar2 + 1);
    _local_60 = CONCAT44((int)((ulonglong)*puVar2 >> 0x20),*(float *)(this + 0x27c) * -3.0);
    TargetFollowCamera::setTargetOffset(*(TargetFollowCamera **)(this + 0x88),(Vector *)&local_60);
    iVar7 = *(int *)this;
    pMVar1 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    pMVar3 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
    AbyssEngine::AEMath::operator*(local_10c,pMVar1,pMVar3);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar7 + 4),local_10c);
    TargetFollowCamera::translateNoUpdate
              (*(TargetFollowCamera **)(this + 0x88),local_48 * -0.9,extraout_s1_01,
               local_50[0] * -0.9);
    if (0x4af < *(int *)(this + 0x350)) {
      *(undefined4 *)(this + 0x334) = 0;
      LevelScript::resetCamera(*(LevelScript **)(this + 0x10),*(Level **)(this + 0xc));
    }
  }
  else {
    if (*(int *)(this + 0x334) != 3) {
      uVar4 = 0;
      goto LAB_000a86b8;
    }
    *(int *)(this + 0x350) = *(int *)(this + 0x134) + *(int *)(this + 0x350);
    AEGeometry::getDirection();
    AEGeometry::getRightVector();
    AEGeometry::getUpVector();
    fVar8 = (float)AEGeometry::getPosition();
    AbyssEngine::AEMath::operator*(aAStack_84,fVar8,(Vector *)0x461c4000);
    fVar8 = (float)AbyssEngine::AEMath::operator+
                             ((AEMath *)local_d0,(Vector *)local_10c,(Vector *)aAStack_84);
    AbyssEngine::AEMath::operator*(aAStack_90,fVar8,(Vector *)0x461c4000);
    AbyssEngine::AEMath::operator+((AEMath *)&local_78,(Vector *)local_d0,(Vector *)aAStack_90);
    if (900 < *(int *)(this + 0x350)) {
      AbyssEngine::AEMath::Vector::operator=((Vector *)&local_78,(Vector *)(this + 0x338));
    }
    moveToPosition(this,local_78,uStack_74,uStack_70,1,0x40e00000);
    uStack_b4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_b0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_ac = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar5 = (undefined4 *)((uint)local_d0 | 4);
    local_d0[0] = 0x3f800000;
    *puVar5 = 0;
    puVar5[1] = uStack_b4;
    puVar5[2] = uStack_b0;
    puVar5[3] = uStack_ac;
    local_bc = 0x3f800000;
    local_b8 = 0;
    local_a8 = 0x3f800000;
    uStack_a0 = 0x3f8000003f800000;
    local_98 = 0x3f800000;
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x350),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::MatrixSetRotation
              (local_10c,(fVar8 / 3000.0) * 6.2831855,extraout_s1_02,6.2831855);
    pAVar6 = *(AEGeometry **)(this + 8);
    pMVar1 = (Matrix *)AEGeometry::getMatrix(pAVar6);
    AbyssEngine::AEMath::operator*(local_10c,pMVar1,(AEMath *)local_d0);
    AEGeometry::setMatrix(pAVar6);
    iVar7 = *(int *)this;
    pMVar1 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    pMVar3 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
    AbyssEngine::AEMath::operator*(local_10c,pMVar1,pMVar3);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar7 + 4),local_10c);
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x88),true);
    fVar8 = (float)TargetFollowCamera::useTargetsUpVector
                             (*(TargetFollowCamera **)(this + 0x88),false);
    AbyssEngine::AEMath::operator*(aAStack_90,(Vector *)(this + 0x344),fVar8);
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator*(aAStack_84,(Vector *)aAStack_90,fVar8);
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x350),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::AEMath::operator*(local_10c,(Vector *)aAStack_84,1.0 - fVar8 / 3000.0);
    TargetFollowCamera::translate
              (*(TargetFollowCamera **)(this + 0x88),extraout_s0_00,extraout_s1_03,extraout_s2_00);
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::moveForward
              (*(AEGeometry **)(this + 8),fVar8 * *(float *)(this + 0xbc) * *(float *)(this + 0xb8))
    ;
    if (2999 < *(int *)(this + 0x350)) {
      *(undefined4 *)(this + 0x334) = 0;
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x88),false);
      TargetFollowCamera::useTargetsUpVector(*(TargetFollowCamera **)(this + 0x88),true);
    }
  }
  uVar4 = 1;
LAB_000a86b8:
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}

// ===== PlayerEgo::moveToPosition  @0x000a8720  (932 bytes)
/* PlayerEgo::moveToPosition(AbyssEngine::AEMath::Vector, bool, float) */

void PlayerEgo::moveToPosition
               (PlayerEgo *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5,float param_6)

{
  uint uVar1;
  byte bVar2;
  undefined4 *puVar3;
  Matrix *pMVar4;
  int iVar5;
  int iVar6;
  Vector *pVVar7;
  Vector *this;
  uint in_fpscr;
  float fVar8;
  float fVar9;
  float extraout_s1;
  AEMath aAStack_84 [12];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 uStack_70;
  float local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 uStack_60;
  float local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  float local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined8 local_38;
  float local_30;
  int local_2c;
  
  pVVar7 = (Vector *)(param_1 + 0xec);
  local_2c = __stack_chk_guard;
  local_78 = param_2;
  local_74 = param_3;
  uStack_70 = param_4;
  AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)&local_78);
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator-=(pVVar7,(Vector *)&local_78);
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_78,pVVar7);
  AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)&local_78);
  AEGeometry::getDirection();
  this = (Vector *)(param_1 + 0xe0);
  AbyssEngine::AEMath::Vector::operator=(this,(Vector *)&local_78);
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_78,this);
  AbyssEngine::AEMath::Vector::operator=(this,(Vector *)&local_78);
  AbyssEngine::AEMath::Vector::operator-=(pVVar7,this);
  fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x134),(byte)(in_fpscr >> 0x16) & 3);
  fVar8 = (float)VectorSignedToFloat((int)(fVar8 * param_6),(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::Vector::operator*=(pVVar7,fVar8 * 0.00024414062);
  AbyssEngine::AEMath::operator+((AEMath *)&local_78,this,pVVar7);
  pVVar7 = (Vector *)(param_1 + 0x164);
  AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)&local_78);
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_78,pVVar7);
  AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)&local_78);
  if (param_5 != 1) goto LAB_000a895e;
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_78,this);
  fVar8 = (float)AbyssEngine::AEMath::VectorDot((Vector *)&local_78,pVVar7);
  fVar9 = 0.0;
  in_fpscr = in_fpscr & 0xfffffff;
  if ((fVar8 < 1.0) &&
     (uVar1 = in_fpscr | (uint)(fVar8 < -1.0) << 0x1f | (uint)(fVar8 == -1.0) << 0x1e,
     in_fpscr = uVar1 | (uint)NAN(fVar8) << 0x1c, bVar2 = (byte)(uVar1 >> 0x18),
     !(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))) {
    fVar9 = (float)AbyssEngine::AEMath::ACosf(0.0);
  }
  fVar8 = -fVar9;
  if (0.0 < fVar9) {
    fVar8 = fVar9;
  }
  in_fpscr = in_fpscr & 0xfffffff | (uint)(fVar8 == 0.0) << 0x1e;
  if ((byte)(in_fpscr >> 0x1e) == 0) {
    AEGeometry::getRightVector();
    local_38 = *(ulonglong *)pVVar7;
    local_30 = *(float *)(param_1 + 0x16c);
    fVar9 = (float)AbyssEngine::AEMath::VectorDot((Vector *)&local_78,(Vector *)&local_38);
    fVar9 = (float)AbyssEngine::AEMath::ACosf(fVar9);
    in_fpscr = in_fpscr & 0xfffffff;
    if (fVar9 < 1.5707964) {
      fVar8 = -fVar8;
    }
  }
  *(float *)(param_1 + *(int *)(param_1 + 0x2a4) * 4 + 0x290) = fVar8;
  if (param_1[0x2a8] == (PlayerEgo)0x0) {
    iVar5 = *(int *)(param_1 + 0x2a4);
    if (iVar5 != 0) {
      if (0 < iVar5) {
        iVar6 = 0;
        do {
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar5);
      }
      VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
      goto LAB_000a8906;
    }
    *(undefined4 *)(param_1 + 0x2a4) = 1;
  }
  else {
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 4;
    } while (iVar5 != 0x14);
    iVar5 = *(int *)(param_1 + 0x2a4);
LAB_000a8906:
    *(int *)(param_1 + 0x2a4) = iVar5 + 1;
    if ((3 < iVar5) && (*(undefined4 *)(param_1 + 0x2a4) = 0, param_1[0x2a8] == (PlayerEgo)0x0)) {
      param_1[0x2a8] = (PlayerEgo)0x1;
    }
  }
  in_fpscr = in_fpscr & 0xfffffff;
LAB_000a895e:
  local_78 = 0;
  local_74 = 0x3f800000;
  uStack_70 = 0;
  AEGeometry::setDirection(*(AEGeometry **)(param_1 + 8),pVVar7,(Vector *)&local_78);
  fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x134),(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::moveForward
            (*(AEGeometry **)(param_1 + 8),
             fVar8 * *(float *)(param_1 + 0xbc) * *(float *)(param_1 + 0xb8));
  roll(param_1,*(int *)(param_1 + 0x134));
  fVar9 = *(float *)(param_1 + 0x37c);
  fVar8 = -fVar9;
  if (0.0 < fVar9) {
    fVar8 = fVar9;
  }
  uVar1 = in_fpscr & 0xfffffff | (uint)(fVar8 < 0.01) << 0x1f | (uint)(fVar8 == 0.01) << 0x1e;
  bVar2 = (byte)(uVar1 >> 0x18);
  if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar8)) {
    *(undefined4 *)(param_1 + 0x380) = 0x3dcccccd;
  }
  else {
    fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x134),(byte)(uVar1 >> 0x16) & 3);
    local_38 = (ulonglong)(uint)(fVar9 * fVar8);
    local_30 = 0.0;
    puVar3 = (undefined4 *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 8));
    local_78 = *puVar3;
    local_74 = puVar3[1];
    uStack_70 = puVar3[2];
    local_6c = (float)puVar3[3];
    uStack_68 = puVar3[4];
    local_64 = puVar3[5];
    uStack_60 = puVar3[6];
    local_5c = (float)puVar3[7];
    uStack_58 = puVar3[8];
    uStack_54 = puVar3[9];
    local_50 = puVar3[10];
    local_4c = (float)puVar3[0xb];
    uStack_48 = puVar3[0xc];
    uStack_44 = puVar3[0xd];
    uStack_40 = puVar3[0xe];
    AbyssEngine::AEMath::MatrixRotateVector(aAStack_84,(Vector *)&local_78,(Vector *)&local_38);
    AbyssEngine::AEMath::Vector::operator=((Vector *)&local_38,(Vector *)aAStack_84);
    local_6c = (float)local_38 + local_6c;
    local_5c = local_38._4_4_ + local_5c;
    local_4c = local_30 + local_4c;
    fVar8 = *(float *)(param_1 + 0x37c);
    *(float *)(param_1 + 0x37c) = fVar8 * 0.7;
    TargetFollowCamera::translateNoUpdate
              (*(TargetFollowCamera **)(param_1 + 0x88),fVar8 * 0.7,extraout_s1,0.7);
    AEGeometry::setMatrix(*(Matrix **)(param_1 + 8));
  }
  iVar5 = *(int *)param_1;
  pMVar4 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar5 + 4),pMVar4);
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x148),(Vector *)&local_78);
  if (__stack_chk_guard - local_2c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_2c);
  }
  return;
}

// ===== PlayerEgo::handleAutoTurret  @0x000a8ae0  (952 bytes)
/* PlayerEgo::handleAutoTurret(int) */

void __thiscall PlayerEgo::handleAutoTurret(PlayerEgo *this,int param_1)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  Matrix *pMVar7;
  Matrix *pMVar8;
  int *piVar9;
  KIPlayer *this_00;
  uint uVar10;
  bool bVar11;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar12;
  float extraout_s2;
  float fVar13;
  longlong lVar14;
  float local_dc;
  float local_d8;
  AEMath aAStack_a0 [12];
  AEMath aAStack_94 [12];
  AEMath aAStack_88 [12];
  Vector aVStack_7c [12];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar2 = *(int *)(this + 0x184);
  *(int *)(this + 0x184) = iVar2 + param_1;
  if (3000 < iVar2 + param_1) {
    *(undefined4 *)(this + 0x18c) = 0;
    *(undefined4 *)(this + 0x184) = 0;
    puVar3 = (uint *)Level::getEnemies(*(Level **)(this + 0xc));
    if ((puVar3 != (uint *)0x0) && (*puVar3 != 0)) {
      uVar10 = 0;
      iVar2 = 60000;
      do {
        this_00 = *(KIPlayer **)(puVar3[1] + uVar10 * 4);
        iVar4 = KIPlayer::isDead(this_00);
        if (((iVar4 == 0) && (iVar4 = KIPlayer::isDying(this_00), iVar4 == 0)) &&
           (iVar4 = Player::isActive(*(Player **)(this_00 + 4)), iVar4 == 1)) {
          uVar5 = KIPlayer::isEnemy(this_00);
          bVar11 = uVar5 == 1;
          if (bVar11) {
            uVar5 = (uint)(byte)this_00[0x70];
          }
          if (bVar11 && uVar5 == 0) {
            (**(code **)(*(int *)this_00 + 0x28))((Vector *)&local_dc,this_00);
            AbyssEngine::AEMath::operator-
                      ((AEMath *)&local_70,(Vector *)(this + 0x148),(Vector *)&local_dc);
            fVar6 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_70);
            if (((int)fVar6 < iVar2) &&
               ((*(int *)(this + 0x18c) == 0 || (*(int *)(this + 0x18c) != *(int *)(this + 400)))))
            {
              *(KIPlayer **)(this + 0x18c) = this_00;
              iVar2 = (int)fVar6;
            }
          }
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar3);
    }
  }
  piVar9 = *(int **)(this + 0x18c);
  if ((piVar9 != (int *)0x0) && (piVar9[2] != 0)) {
    iVar2 = piVar9[1];
    local_70 = *(undefined4 *)(iVar2 + 4);
    local_6c = *(undefined4 *)(iVar2 + 8);
    local_68 = *(undefined4 *)(iVar2 + 0xc);
    local_64 = *(undefined4 *)(iVar2 + 0x10);
    local_60 = *(undefined4 *)(iVar2 + 0x14);
    local_5c = *(undefined4 *)(iVar2 + 0x18);
    uStack_58 = *(undefined4 *)(iVar2 + 0x1c);
    local_54 = *(undefined4 *)(iVar2 + 0x20);
    uStack_50 = *(undefined4 *)(iVar2 + 0x24);
    uStack_4c = *(undefined4 *)(iVar2 + 0x28);
    local_48 = *(undefined4 *)(iVar2 + 0x2c);
    uStack_44 = *(undefined4 *)(iVar2 + 0x30);
    local_40 = *(undefined4 *)(iVar2 + 0x34);
    uStack_3c = *(undefined4 *)(iVar2 + 0x38);
    uStack_38 = *(undefined4 *)(iVar2 + 0x3c);
    (**(code **)(*piVar9 + 0x28))(aVStack_7c);
    AbyssEngine::AEMath::MatrixGetDir(aAStack_a0,(Matrix *)&local_70);
    fVar6 = (float)AbyssEngine::AEMath::VectorNormalize(aAStack_94,(Vector *)aAStack_a0);
    AbyssEngine::AEMath::operator*(aAStack_88,(Vector *)aAStack_94,fVar6);
    AbyssEngine::AEMath::operator+((AEMath *)&local_dc,aVStack_7c,(Vector *)aAStack_88);
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xec),(Vector *)&local_dc);
    pMVar7 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
    pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x28));
    AbyssEngine::AEMath::operator*((AEMath *)&local_dc,pMVar7,pMVar8);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_70,(AEMath *)&local_dc);
    AbyssEngine::AEMath::MatrixInverseTransformVector
              ((AEMath *)aVStack_7c,(Matrix *)&local_70,(Vector *)(this + 0xec));
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_dc,aVStack_7c);
    in_fpscr = in_fpscr & 0xfffffff;
    uVar10 = in_fpscr | (uint)(local_dc < 0.05) << 0x1f | (uint)(local_dc == 0.05) << 0x1e;
    uVar5 = uVar10 | (uint)NAN(local_dc) << 0x1c;
    bVar1 = (byte)(uVar10 >> 0x18);
    if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar5 >> 0x1c) & 1)) {
      if (local_dc < -0.05) {
        iVar2 = -param_1;
        fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x1f8),
                                           (byte)(in_fpscr >> 0x16) & 3);
        goto LAB_000a8cd4;
      }
      bVar11 = true;
      fVar6 = extraout_s1;
    }
    else {
      fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x1f8),(byte)(uVar5 >> 0x16) & 3);
      in_fpscr = uVar5;
      iVar2 = param_1;
LAB_000a8cd4:
      fVar12 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
      bVar11 = false;
      AEGeometry::rotate(*(AEGeometry **)(this + 0xdc),
                         (fVar12 / (200.0 / fVar6)) * 0.00024414062 * 6.2831855,extraout_s1,
                         6.2831855);
      AEGeometry::rotate(*(AEGeometry **)(this + 0x28),extraout_s0,extraout_s1_00,extraout_s2);
      fVar6 = extraout_s1_01;
    }
    if (local_d8 <= 0.05) {
      if (local_d8 < -0.05) {
        if (70.0 <= *(float *)(this + 0x1a8)) goto LAB_000a8da8;
        fVar13 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),
                                            (byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
        fVar12 = *(float *)(this + 0x1a8) + fVar13;
        goto LAB_000a8d84;
      }
      if (bVar11) {
        Player::shoot(*(undefined4 *)this,2,param_1,param_1 >> 0x1f,0,local_70,local_6c,local_68,
                      local_64,local_60,local_5c,uStack_58,local_54,uStack_50,uStack_4c,local_48,
                      uStack_44,local_40,uStack_3c,uStack_38);
        lVar14 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0xc));
        AbyssEngine::Transform::Update(lVar14,SUB41(param_1,0));
        lVar14 = AbyssEngine::PaintCanvas::TransformGetTransform
                           (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0xc));
        AbyssEngine::Transform::Update(lVar14,SUB41(param_1,0));
        *(undefined4 *)(this + 0x188) = 0;
        goto LAB_000a8e7a;
      }
    }
    else {
      fVar12 = *(float *)(this + 0x1a8);
      uVar10 = in_fpscr & 0xfffffff | (uint)(fVar12 < -500.0) << 0x1f |
               (uint)(fVar12 == -500.0) << 0x1e;
      bVar1 = (byte)(uVar10 >> 0x18);
      if ((bool)(bVar1 >> 6 & 1) || (bool)(bVar1 >> 7) != NAN(fVar12)) {
LAB_000a8da8:
        *(undefined4 *)(this + 400) = *(undefined4 *)(this + 0x18c);
        *(int *)(this + 0x184) = *(int *)(this + 0x184) + param_1;
      }
      else {
        fVar13 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(uVar10 >> 0x16) & 3
                                           );
        fVar12 = fVar12 - fVar13;
LAB_000a8d84:
        *(float *)(this + 0x1a8) = fVar12;
        AEGeometry::rotate(*(AEGeometry **)(this + 0x28),fVar12,fVar6,fVar13);
        *(undefined4 *)(this + 400) = 0;
      }
    }
    iVar2 = *(int *)(this + 0x188);
    *(int *)(this + 0x188) = iVar2 + param_1;
    if (iVar2 + param_1 < 0x1f5) goto LAB_000a8e7a;
  }
  Player::stopShooting(*(Player **)this,2);
LAB_000a8e7a:
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::update  @0x000a8ed0  (9228 bytes)
/* PlayerEgo::update(int, Radar*, Hud*, Radio*, LevelScript*, int, bool, int) */

void __thiscall
PlayerEgo::update(PlayerEgo *this,int param_1,Radar *param_2,Hud *param_3,Radio *param_4,
                 LevelScript *param_5,int param_6,bool param_7,int param_8)

{
  Status *pSVar1;
  byte bVar2;
  Status *pSVar3;
  PaintCanvas *pPVar4;
  FModSound *pFVar5;
  PlayerEgo PVar6;
  uint uVar7;
  int iVar8;
  Ship *pSVar9;
  Item *pIVar10;
  int iVar11;
  undefined4 uVar12;
  Station *pSVar13;
  void *pvVar14;
  uint *puVar15;
  PlayerFixedObject *this_00;
  Engine *this_01;
  Mesh *pMVar16;
  Transform *pTVar17;
  Matrix *pMVar18;
  Matrix *pMVar19;
  Array *pAVar20;
  Explosion *pEVar21;
  Mission *this_02;
  Mission *this_03;
  HackingGame *this_04;
  int iVar22;
  undefined1 *this_05;
  float *pfVar23;
  PlayerEgo *pPVar24;
  int *piVar25;
  undefined4 *puVar26;
  uint uVar27;
  undefined1 *this_06;
  bool bVar28;
  Radar *extraout_r2;
  int extraout_r2_00;
  uint uVar29;
  ushort uVar30;
  Level *this_07;
  Vector *pVVar31;
  undefined4 uVar32;
  Matrix *pMVar33;
  Player *pPVar34;
  int iVar35;
  undefined4 uVar36;
  AEGeometry *this_08;
  PlayerEgo *pPVar37;
  bool bVar38;
  uint in_fpscr;
  float extraout_s0;
  float fVar39;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float fVar40;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
  float extraout_s0_07;
  undefined4 extraout_s1;
  undefined8 uVar41;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s1_07;
  float extraout_s1_08;
  float extraout_s1_09;
  float extraout_s1_10;
  float extraout_s1_11;
  float extraout_s1_12;
  float extraout_s1_13;
  float extraout_s1_14;
  float extraout_s1_15;
  float extraout_s1_16;
  float extraout_s1_17;
  float extraout_s1_18;
  float extraout_s1_19;
  float extraout_s1_20;
  float extraout_s1_21;
  float extraout_s1_22;
  float extraout_s1_23;
  float extraout_s1_24;
  float extraout_s1_25;
  float extraout_s1_26;
  float extraout_s1_27;
  float extraout_s1_28;
  float extraout_s1_29;
  float extraout_s1_30;
  float extraout_s1_31;
  float extraout_s1_32;
  float extraout_s1_33;
  float extraout_s1_34;
  float extraout_s1_35;
  float extraout_s1_36;
  float extraout_s1_37;
  float extraout_s1_38;
  float extraout_s1_39;
  float extraout_s1_40;
  float extraout_s1_41;
  float extraout_s1_42;
  float extraout_s1_43;
  float extraout_s1_44;
  float extraout_s1_45;
  float extraout_s1_46;
  float extraout_s1_47;
  float fVar42;
  float extraout_s2;
  float extraout_s2_00;
  float fVar43;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  float extraout_s2_07;
  float extraout_s2_08;
  float extraout_s2_09;
  float fVar44;
  float extraout_s2_10;
  float extraout_s2_11;
  float extraout_s2_12;
  float fVar45;
  undefined4 extraout_s7;
  float fVar46;
  undefined1 in_q8 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  longlong lVar49;
  undefined3 in_stack_0000000d;
  AEMath aAStack_108 [12];
  AEMath aAStack_fc [12];
  undefined8 local_f0;
  undefined4 local_e8;
  float local_e4 [15];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  float local_60;
  int local_54;
  
  local_54 = __stack_chk_guard;
  *(LevelScript **)(this + 0x10) = param_5;
  if (*(int *)(this + 0x220) == 0) {
    *(Hud **)(this + 0x220) = param_3;
    *(Radar **)(this + 0x14) = param_2;
    *(Radio **)(this + 0x18) = param_4;
  }
  if (this[0x24] != (PlayerEgo)0x0) goto LAB_000ab3cc;
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x148),(Vector *)&local_a8);
  *(int *)(this + 0x134) = param_1;
  uVar7 = *(uint *)(this + 0x138);
  if ((0x7fffffff < uVar7) && (0 < (int)(param_1 * 3 + uVar7))) {
    uVar7 = 0;
    *(undefined4 *)(this + 0x138) = 0;
  }
  *(uint *)(this + 0x138) = uVar7 + param_1;
  if (((this[0x39a] != (PlayerEgo)0x0) && (this[0x399] == (PlayerEgo)0x0)) &&
     (iVar8 = Player::getShieldHP(*(Player **)this), iVar8 < 1)) {
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    iVar8 = Ship::getFirstEquipmentOfSort(pSVar9,0x2b);
    if (iVar8 != 0) {
      pSVar9 = (Ship *)Status::getShip(Globals::status);
      pIVar10 = (Item *)Ship::getFirstEquipmentOfSort(pSVar9,0x2b);
      iVar8 = Item::getAttribute(pIVar10,0x3b);
      pSVar9 = (Ship *)Status::getShip(Globals::status);
      iVar11 = Ship::hasCargo(pSVar9,0xca,iVar8);
      if (iVar11 == 1) {
        this[0x399] = (PlayerEgo)0x1;
        fVar39 = (float)FModSound::play(Globals::sound,0x8d2,(Vector *)0x0,(Vector *)0x0,extraout_s0
                                       );
        FModSound::play(Globals::sound,0x8d1,(Vector *)0x0,(Vector *)0x0,fVar39);
        local_a8 = 0;
        uStack_a4 = 0;
        local_a0 = 0;
        AEGeometry::getPosition();
        FModSound::updateEvent3DAttributes
                  (Globals::sound,0x8d2,(Vector *)local_e4,(Vector *)&local_a8,false);
        pSVar9 = (Ship *)Status::getShip(Globals::status);
        Ship::removeCargo(pSVar9,0xca,iVar8);
        Hud::hudEvent((int)param_3,(PlayerEgo *)0x2f,(int)this);
      }
    }
  }
  if (this[0x399] != (PlayerEgo)0x0) {
    iVar8 = Player::getShieldHP(*(Player **)this);
    iVar11 = Player::getMaxShieldHP(*(Player **)this);
    if (iVar8 < iVar11) {
      pPVar34 = *(Player **)this;
      uVar12 = Player::getShieldHP(pPVar34);
      fVar39 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar42 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      uVar41 = FloatVectorMax(CONCAT44(extraout_s1,fVar39 * 0.15),CONCAT44(extraout_s7,0x3f800000),2
                              ,0x20);
      Player::setShieldHP(pPVar34,(int)((float)uVar41 + fVar42));
      pFVar5 = Globals::sound;
      uVar12 = Player::getShieldHP(*(Player **)this);
      fVar42 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      uVar12 = Player::getMaxShieldHP(*(Player **)this);
      fVar39 = (float)VectorSignedToFloat(uVar12,(byte)(in_fpscr >> 0x16) & 3);
      FModSound::setParamValue((int)pFVar5,0,fVar42 / fVar39);
      local_a8 = 0;
      uStack_a4 = 0;
      local_a0 = 0;
      AEGeometry::getPosition();
      FModSound::updateEvent3DAttributes
                (Globals::sound,0x8d1,(Vector *)local_e4,(Vector *)&local_a8,false);
    }
    else {
      FModSound::play(Globals::sound,0x8d3,(Vector *)0x0,(Vector *)0x0,extraout_s0_00);
      FModSound::stop(Globals::sound,0x8d1);
      local_a8 = 0;
      uStack_a4 = 0;
      local_a0 = 0;
      AEGeometry::getPosition();
      FModSound::updateEvent3DAttributes
                (Globals::sound,0x8d3,(Vector *)local_e4,(Vector *)&local_a8,false);
      this[0x399] = (PlayerEgo)0x0;
    }
  }
  if ((0 < *(int *)(this + 0x20c)) &&
     (iVar8 = *(int *)(this + 0x20c) - param_1, *(int *)(this + 0x20c) = iVar8, iVar8 < 1)) {
    Hud::hudEvent((int)param_3,(PlayerEgo *)0x2e,(int)this);
  }
  if (*(int *)(this + 0x1e8) != 0) {
    HackingGame::update(*(int *)(this + 0x1e8));
    iVar8 = HackingGame::gameWon(*(HackingGame **)(this + 0x1e8));
    if (iVar8 == 1) {
      Hud::setHackingGameActive(param_3,false);
      pSVar13 = (Station *)Status::getStation(Globals::status);
      iVar8 = Station::stationHasHiddenBlueprint(pSVar13,false);
      if (iVar8 == 1) {
        pSVar13 = (Station *)Status::getStation(Globals::status);
        iVar8 = Station::getHiddenBlueprintIndex(pSVar13);
        Status::unlockBluePrint(Globals::status,*(int *)(&DAT_002521f0 + iVar8 * 4));
        if (*(HackingGame **)(this + 0x1e8) != (HackingGame *)0x0) {
          pvVar14 = (void *)HackingGame::~HackingGame(*(HackingGame **)(this + 0x1e8));
          operator_delete(pvVar14);
        }
        *(undefined4 *)(this + 0x1e8) = 0;
        puVar15 = (uint *)Level::getEnemies(*(Level **)(this + 0xc));
        if ((puVar15 != (uint *)0x0) && (*puVar15 != 0)) {
          uVar7 = 0;
          do {
            this_00 = *(PlayerFixedObject **)(puVar15[1] + uVar7 * 4);
            if (this_00[0x6c] != (PlayerFixedObject)0x0) {
              this_00[0x6c] = (PlayerFixedObject)0x0;
              PlayerFixedObject::setDockingType(this_00,0);
              iVar11 = *(int *)(puVar15[1] + uVar7 * 4);
              pvVar14 = *(void **)(iVar11 + 0x4c);
              if (pvVar14 != (void *)0x0) {
                if (*(void **)((int)pvVar14 + 4) != (void *)0x0) {
                  operator_delete__(*(void **)((int)pvVar14 + 4));
                }
                operator_delete(pvVar14);
                iVar11 = *(int *)(puVar15[1] + uVar7 * 4);
              }
              *(undefined4 *)(iVar11 + 0x4c) = 0;
              break;
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < *puVar15);
        }
        Level::createRadioMessage(*(Level **)(this + 0xc),iVar8 + 0x15,0);
        *(undefined1 *)(*(int *)(*(int *)(Globals::status + 0x58) + 4) + iVar8) = 1;
      }
    }
  }
  pSVar9 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getFreeSpace(pSVar9);
  fVar39 = extraout_s2;
  fVar40 = extraout_s0_01;
  fVar42 = extraout_s1_00;
  if (iVar8 < *(int *)(this + 0x250)) {
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    uVar12 = Ship::getFreeSpace(pSVar9);
    *(undefined4 *)(this + 0x250) = uVar12;
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    PVar6 = (PlayerEgo)Ship::hasVolatileGoods(pSVar9);
    this[0x398] = PVar6;
    fVar39 = extraout_s2_00;
    fVar40 = extraout_s0_02;
    fVar42 = extraout_s1_01;
  }
  if (this[0x13c] != (PlayerEgo)0x0) {
    if (this[0x398] != (PlayerEgo)0x0) {
      pSVar9 = (Ship *)Status::getShip(Globals::status);
      pIVar10 = (Item *)Ship::getFirstEquipmentOfSort(pSVar9,0xe);
      if (pIVar10 == (Item *)0x0) {
        fVar40 = 0.13;
        fVar42 = extraout_s1_02;
      }
      else {
        iVar8 = Item::getIndex(pIVar10);
        pfVar23 = (float *)&DAT_000a9ccc;
        if (iVar8 == 0xc3) {
          pfVar23 = (float *)&DAT_000a9cd0;
        }
        fVar40 = *pfVar23;
        fVar42 = extraout_s1_03;
      }
      fVar43 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar39 = *(float *)(*(int *)this + 0x60);
      fVar40 = fVar43 * 0.001 * fVar40 + fVar39;
      *(float *)(*(int *)this + 0x60) = fVar40;
    }
    if ((*(int **)(*(int *)(this + 0xc) + 0xa4) != (int *)0x0) &&
       (**(int **)(*(int *)(this + 0xc) + 0xa4) != 0)) {
      uVar7 = 0;
      pfVar23 = (float *)(ParticleSettingsRef::cur + 0x11bc);
      do {
        AEGeometry::getScaling();
        fVar42 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x138),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar39 = (float)VectorSignedToFloat(*(int *)(this + 0xcc) / 6,(byte)(in_fpscr >> 0x16) & 3);
        fVar42 = fVar42 / fVar39;
        in_fpscr = in_fpscr & 0xfffffff;
        fVar39 = fVar42;
        if (1.0 <= fVar42) {
          uVar29 = in_fpscr | (uint)(fVar42 < 5.0) << 0x1f | (uint)(fVar42 == 5.0) << 0x1e;
          in_fpscr = uVar29 | (uint)NAN(fVar42) << 0x1c;
          bVar2 = (byte)(uVar29 >> 0x18);
          fVar39 = 1.0;
          if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
            fVar39 = 6.0 - fVar42;
          }
        }
        uVar7 = uVar7 + 1;
        fVar39 = fVar39 * 0.5 + 1.0;
        fVar40 = local_60 * 250.0 * fVar39;
        *pfVar23 = fVar40;
        pfVar23 = pfVar23 + 0x27;
        fVar42 = extraout_s1_04;
      } while (uVar7 < **(uint **)(*(int *)(this + 0xc) + 0xa4));
    }
    if (*(int *)(this + 0xcc) < *(int *)(this + 0x138)) {
      this_01 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
      fVar40 = (float)AbyssEngine::Engine::SetPostEffect(this_01,0x1400002,false);
      *(undefined4 *)(this + 0xb8) = 0x40000000;
      this[0x13c] = (PlayerEgo)0x0;
      *(int *)(this + 0x138) = -*(int *)(this + 0xd0);
      fVar39 = extraout_s2_01;
      fVar42 = extraout_s1_05;
      if (this[0x146] == (PlayerEgo)0x0) {
        *(undefined4 *)(this + 200) = 2;
        *(undefined4 *)(this + 0xcc) = 0;
        *(undefined4 *)(this + 0xd0) = 0;
      }
    }
  }
  if ((*(ushort *)(this + 0x1ac) & 0xff) == 0) {
    if ((0xff < *(ushort *)(this + 0x1ac)) &&
       (iVar8 = *(int *)(this + 0x208), *(int *)(this + 0x208) = *(int *)(this + 0x134) + iVar8,
       *(int *)(this + 0x214) < *(int *)(this + 0x134) + iVar8)) {
      Hud::hudEvent((int)param_3,(PlayerEgo *)0x1d,(int)this);
      fVar40 = (float)toggleCloaking();
      this[0x1ad] = (PlayerEgo)0x0;
      fVar39 = extraout_s2_02;
      fVar42 = extraout_s1_06;
    }
  }
  else {
    uVar7 = *(uint *)(this + 0x134);
    iVar8 = *(int *)(this + 0x208) + uVar7;
    *(int *)(this + 0x208) = iVar8;
    pSVar3 = Globals::status;
    uVar29 = *(uint *)(Globals::status + 0xc0);
    pSVar1 = Globals::status + 0xc4;
    *(uint *)(Globals::status + 0xc0) = uVar29 + uVar7;
    *(uint *)(pSVar3 + 0xc4) = *(int *)pSVar1 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar29,uVar7);
    if (iVar8 < 2000) {
      fVar39 = (float)VectorSignedToFloat(iVar8,(byte)(in_fpscr >> 0x16) & 3);
      uVar7 = 0xff - (int)((fVar39 / 2000.0) * 255.0);
      if ((int)uVar7 < 0x32) {
        uVar7 = 0x32;
      }
      if (iVar8 == 0) {
        *(undefined4 *)(this + 0x208) = 1;
      }
      pPVar4 = Globals::Canvas;
      uVar7 = uVar7 | 0xffffff00;
      pPVar24 = this + 4;
      pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                  (Globals::Canvas,*(uint *)(*(int *)pPVar24 + 0x1c));
      fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),(byte)(in_fpscr >> 0x16) & 3
                                         );
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
                (pPVar4,pMVar16,fVar39 / 2000.0,(uint)(fVar39 / 2000.0));
      pPVar4 = Globals::Canvas;
      if (this[0x170] != (PlayerEgo)0x0) {
        pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                    (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0x1c));
        fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),
                                            (byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
                  (pPVar4,pMVar16,fVar39 / 2000.0,(uint)(fVar39 / 2000.0));
        pPVar4 = Globals::Canvas;
        pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                    (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0x1c));
        fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),
                                            (byte)(in_fpscr >> 0x16) & 3);
        AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
                  (pPVar4,pMVar16,fVar39 / 2000.0,(uint)(fVar39 / 2000.0));
      }
      iVar8 = *(int *)pPVar24;
      if (*(uint *)(iVar8 + 0x10) != 0xffffffff) {
        AbyssEngine::PaintCanvas::TransformSetColor(Globals::Canvas,*(uint *)(iVar8 + 0x10),uVar7);
        iVar8 = *(int *)pPVar24;
      }
      if (*(uint *)(iVar8 + 0x14) != 0xffffffff) {
        AbyssEngine::PaintCanvas::TransformSetColor(Globals::Canvas,*(uint *)(iVar8 + 0x14),uVar7);
      }
      if (this[0x170] != (PlayerEgo)0x0) {
        AbyssEngine::PaintCanvas::TransformSetColor
                  (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0xc),uVar7);
        AbyssEngine::PaintCanvas::TransformSetColor
                  (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0xc),uVar7);
      }
      fVar39 = (float)getCloakingPercentage(this);
      uVar7 = in_fpscr & 0xfffffff | (uint)(fVar39 < 25.0) << 0x1f | (uint)(fVar39 == 25.0) << 0x1e;
      in_fpscr = uVar7 | (uint)NAN(fVar39) << 0x1c;
      bVar2 = (byte)(uVar7 >> 0x18);
      if ((!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) &&
         (this[0x325] == (PlayerEgo)0x0)) {
        this[0x325] = (PlayerEgo)0x1;
        if ((*(int *)(this + 4) != 0) &&
           (uVar7 = *(uint *)(*(int *)(this + 4) + 0x14), uVar7 != 0xffffffff)) {
          pTVar17 = (Transform *)
                    AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar7);
          AbyssEngine::Transform::SetVisible(pTVar17,this[0x325] == (PlayerEgo)0x0);
        }
      }
    }
    pPVar4 = Globals::Canvas;
    pPVar37 = this + 4;
    pPVar24 = this + 0x170;
    pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                (Globals::Canvas,*(uint *)(*(int *)pPVar37 + 0x1c));
    fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),(byte)(in_fpscr >> 0x16) & 3);
    fVar39 = (float)AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
                              (pPVar4,pMVar16,fVar39 * 0.001,(uint)(fVar39 * 0.001));
    pPVar4 = Globals::Canvas;
    if (*pPVar24 != (PlayerEgo)0x0) {
      pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                  (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0x1c));
      fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),(byte)(in_fpscr >> 0x16) & 3
                                         );
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
                (pPVar4,pMVar16,fVar39 * 0.001,(uint)(fVar39 * 0.001));
      pPVar4 = Globals::Canvas;
      pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                  (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0x1c));
      fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),(byte)(in_fpscr >> 0x16) & 3
                                         );
      fVar39 = (float)AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
                                (pPVar4,pMVar16,fVar39 * 0.001,(uint)(fVar39 * 0.001));
    }
    pPVar4 = Globals::Canvas;
    iVar8 = *(int *)(this + 0x210);
    iVar11 = *(int *)(this + 0x208);
    if (iVar8 + -2000 < iVar11) {
      pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                  (Globals::Canvas,*(uint *)(*(int *)pPVar37 + 0x1c));
      fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),(byte)(in_fpscr >> 0x16) & 3
                                         );
      fVar42 = (float)VectorSignedToFloat(*(int *)(this + 0x210) + -2000,
                                          (byte)(in_fpscr >> 0x16) & 3);
      fVar39 = 1.0 - (fVar39 - fVar42) / 2000.0;
      AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar4,pMVar16,fVar39,(uint)fVar39);
      pPVar4 = Globals::Canvas;
      fVar39 = (float)VectorSignedToFloat(iVar8 + -2000,(byte)(in_fpscr >> 0x16) & 3);
      fVar42 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
      uVar7 = (uint)(((fVar42 - fVar39) / 2000.0) * 255.0);
      if ((int)uVar7 < 0x32) {
        uVar7 = 0x32;
      }
      uVar7 = uVar7 | 0xffffff00;
      if (*pPVar24 != (PlayerEgo)0x0) {
        pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                    (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0x1c));
        fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar42 = (float)VectorSignedToFloat(*(int *)(this + 0x210) + -2000,
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar39 = 1.0 - (fVar39 - fVar42) / 2000.0;
        AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar4,pMVar16,fVar39,(uint)fVar39);
        pPVar4 = Globals::Canvas;
        pMVar16 = (Mesh *)AbyssEngine::PaintCanvas::MeshGetPointer
                                    (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0x1c));
        fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x208),
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar42 = (float)VectorSignedToFloat(*(int *)(this + 0x210) + -2000,
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar39 = 1.0 - (fVar39 - fVar42) / 2000.0;
        AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(pPVar4,pMVar16,fVar39,(uint)fVar39);
      }
      iVar8 = *(int *)pPVar37;
      if (*(uint *)(iVar8 + 0x10) != 0xffffffff) {
        AbyssEngine::PaintCanvas::TransformSetColor(Globals::Canvas,*(uint *)(iVar8 + 0x10),uVar7);
        iVar8 = *(int *)pPVar37;
      }
      if (*(uint *)(iVar8 + 0x14) != 0xffffffff) {
        AbyssEngine::PaintCanvas::TransformSetColor(Globals::Canvas,*(uint *)(iVar8 + 0x14),uVar7);
      }
      if (*pPVar24 != (PlayerEgo)0x0) {
        AbyssEngine::PaintCanvas::TransformSetColor
                  (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0xc),uVar7);
        AbyssEngine::PaintCanvas::TransformSetColor
                  (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0xc),uVar7);
      }
      fVar42 = (float)getCloakingPercentage(this);
      fVar39 = 25.0;
      in_fpscr = in_fpscr & 0xfffffff;
      if ((fVar42 < 25.0) && (this[0x325] != (PlayerEgo)0x0)) {
        this[0x325] = (PlayerEgo)0x0;
        if ((*(int *)pPVar37 != 0) &&
           (uVar7 = *(uint *)(*(int *)pPVar37 + 0x14), uVar7 != 0xffffffff)) {
          pTVar17 = (Transform *)
                    AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar7);
          fVar39 = (float)AbyssEngine::Transform::SetVisible(pTVar17,this[0x325] == (PlayerEgo)0x0);
        }
      }
    }
    if (*(int *)(this + 0x210) < *(int *)(this + 0x208)) {
      *(undefined4 *)(this + 0x208) = 0;
      *(undefined4 *)(this + 0x20c) = *(undefined4 *)(this + 0x368);
      this[0x1ac] = (PlayerEgo)0x0;
      *(undefined1 *)(*(int *)this + 0x5e) = 0;
      FModSound::play(Globals::sound,0x1e,(Vector *)0x0,(Vector *)0x0,fVar39);
      if (this[0x325] != (PlayerEgo)0x0) {
        this[0x325] = (PlayerEgo)0x0;
        if ((*(int *)pPVar37 != 0) &&
           (uVar7 = *(uint *)(*(int *)pPVar37 + 0x14), uVar7 != 0xffffffff)) {
          pTVar17 = (Transform *)
                    AbyssEngine::PaintCanvas::TransformGetTransform(Globals::Canvas,uVar7);
          AbyssEngine::Transform::SetVisible(pTVar17,this[0x325] == (PlayerEgo)0x0);
        }
      }
      uVar12 = *(undefined4 *)(this + 0x394);
      iVar8 = AbyssEngine::PaintCanvas::MaterialGetMaterial(Globals::Canvas,*(uint *)(this + 0x388))
      ;
      *(undefined4 *)(iVar8 + 0x20) = uVar12;
      if (*pPVar24 != (PlayerEgo)0x0) {
        uVar12 = *(undefined4 *)(this + 0x394);
        iVar8 = AbyssEngine::PaintCanvas::MaterialGetMaterial
                          (Globals::Canvas,*(uint *)(this + 0x38c));
        *(undefined4 *)(iVar8 + 0x20) = uVar12;
        uVar12 = *(undefined4 *)(this + 0x394);
        iVar8 = AbyssEngine::PaintCanvas::MaterialGetMaterial
                          (Globals::Canvas,*(uint *)(this + 0x390));
        *(undefined4 *)(iVar8 + 0x20) = uVar12;
        if (*pPVar24 != (PlayerEgo)0x0) {
          pSVar9 = (Ship *)Status::getShip(Globals::status);
          pIVar10 = (Item *)Ship::getFirstEquipmentOfSort(pSVar9,8);
          uVar30 = 0x4e86;
          if ((pIVar10 != (Item *)0x0) && (iVar8 = Item::getIndex(pIVar10), iVar8 == 0xe0)) {
            uVar30 = 0x5e15;
          }
          pSVar9 = (Ship *)Status::getShip(Globals::status);
          pIVar10 = (Item *)Ship::getFirstEquipmentOfSort(pSVar9,0x23);
          if (pIVar10 != (Item *)0x0) {
            iVar8 = Item::getIndex(pIVar10);
            uVar30 = 0x716b;
            if (iVar8 == 199) {
              uVar30 = 0x7165;
            }
            if (iVar8 == 0xc6) {
              uVar30 = 0x715f;
            }
          }
          AbyssEngine::PaintCanvas::MeshChangeResourceMaterial
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0xdc) + 0x1c),uVar30);
          AbyssEngine::PaintCanvas::MeshChangeResourceMaterial
                    (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0x1c),uVar30);
        }
      }
    }
    this_07 = *(Level **)(this + 0xc);
    fVar39 = (float)getCloakingPercentage(this);
    fVar40 = 221.0;
    fVar39 = fVar39 * -201.0 * 0.01 + 221.0;
    in_fpscr = in_fpscr & 0xfffffff;
    fVar42 = fVar40;
    if (fVar39 < 0.0) {
      fVar42 = 0.0;
    }
    bVar28 = fVar39 < 0.0;
    if (221.0 <= fVar39) {
      fVar39 = fVar40;
      fVar42 = fVar40;
    }
    if (bVar28) {
      fVar39 = fVar42;
    }
    fVar40 = (float)Level::setPlayerEngineColor(this_07,(short)(int)fVar39);
    fVar39 = extraout_s2_03;
    fVar42 = extraout_s1_07;
  }
  if (this[0x204] != (PlayerEgo)0x0) {
    iVar8 = *(int *)(this + 0x1fc);
    *(int *)(this + 0x1fc) = *(int *)(this + 0x134) + iVar8;
    if (*(int *)(this + 0x200) <= *(int *)(this + 0x134) + iVar8) {
      this[0x38] = (PlayerEgo)0x0;
      fVar40 = (float)Hud::hudEvent((int)param_3,(PlayerEgo *)0x1a,(int)this);
      fVar39 = extraout_s2_04;
      fVar42 = extraout_s1_08;
    }
    if (this[0x398] != (PlayerEgo)0x0) {
      fVar40 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar39 = *(float *)(*(int *)this + 0x60);
      fVar40 = fVar40 * 0.001 * 0.5 + fVar39;
      *(float *)(*(int *)this + 0x60) = fVar40;
    }
  }
  if (*(TractorBeam **)(this + 0x1b4) != (TractorBeam *)0x0) {
    fVar40 = (float)TractorBeam::update(*(TractorBeam **)(this + 0x1b4),*(int *)(this + 0x134),
                                        param_2,*(Level **)(this + 0xc),param_3);
    fVar39 = extraout_s2_05;
    fVar42 = extraout_s1_09;
  }
  puVar15 = *(uint **)(this + 0x1b8);
  if ((puVar15 != (uint *)0x0) && (*puVar15 != 0)) {
    uVar7 = 0;
    do {
      fVar40 = (float)RepairBeam::update(*(int *)(puVar15[1] + uVar7 * 4),*(Radar **)(this + 0x134),
                                         (Level *)param_2,*(Hud **)(this + 0xc));
      puVar15 = *(uint **)(this + 0x1b8);
      uVar7 = uVar7 + 1;
      fVar39 = extraout_s2_06;
      fVar42 = extraout_s1_10;
    } while (uVar7 < *puVar15);
  }
  if ((this[0x370] != (PlayerEgo)0x0) &&
     (iVar8 = *(int *)(this + 0x374), *(int *)(this + 0x374) = iVar8 + param_1,
     1999 < iVar8 + param_1)) {
    this[0x370] = (PlayerEgo)0x0;
  }
  bVar28 = SUB41(param_1,0);
  if (((this[0x170] != (PlayerEgo)0x0) && (this[0x180] == (PlayerEgo)0x0)) &&
     (this[0x1a0] != (PlayerEgo)0x0)) {
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    iVar8 = Ship::getFirstEquipmentOfSort(pSVar9,0x23);
    fVar39 = extraout_s2_07;
    fVar40 = extraout_s0_03;
    fVar42 = extraout_s1_11;
    if (iVar8 != 0) {
      uVar12 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (Globals::Canvas,*(uint *)(*(int *)(this + 0x28) + 0xc));
      fVar40 = (float)AbyssEngine::Transform::Update(CONCAT44(1,uVar12),bVar28);
      fVar39 = extraout_s2_08;
      fVar42 = extraout_s1_12;
      if (*(int *)(this + 0x30) != 0) {
        uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                          (Globals::Canvas,*(uint *)(*(int *)(this + 0x30) + 0xc));
        fVar40 = (float)AbyssEngine::Transform::Update((ulonglong)uVar7,bVar28);
        fVar39 = extraout_s2_09;
        fVar42 = extraout_s1_13;
      }
    }
  }
  if ((*(AEGeometry **)(this + 0x34) != (AEGeometry *)0x0) && (this[0x38] != (PlayerEgo)0x0)) {
    AEGeometry::setScaling(*(AEGeometry **)(this + 0x34),fVar40,fVar42,fVar39);
    this_08 = *(AEGeometry **)(this + 0x34);
    Level::getStarSystem(*(Level **)(this + 0xc));
    StarSystem::getLightDirection();
    AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_a8,(Vector *)local_e4);
    local_6c = 0;
    local_68 = 0x3f800000;
    uStack_64 = 0;
    AEGeometry::setDirection(this_08,(Vector *)&local_a8,(Vector *)&local_6c);
    pVVar31 = *(Vector **)(this + 0x34);
    AEGeometry::getPosition();
    AEGeometry::setPosition(pVVar31);
    pSVar9 = (Ship *)Status::getShip(Globals::status);
    iVar8 = Ship::getIndex(pSVar9);
    if (iVar8 == 8) {
      pVVar31 = *(Vector **)(this + 0x34);
      AEGeometry::getDirection();
      fVar39 = (float)AbyssEngine::AEMath::VectorNormalize((AEMath *)local_e4,(Vector *)&local_6c);
      AbyssEngine::AEMath::operator*((AEMath *)&local_a8,(Vector *)local_e4,fVar39);
      AEGeometry::translate(pVVar31);
    }
    uVar12 = AbyssEngine::PaintCanvas::TransformGetTransform
                       (Globals::Canvas,*(uint *)(*(int *)(this + 0x34) + 0xc));
    AbyssEngine::Transform::Update(CONCAT44(1,uVar12),SUB41(*(undefined4 *)(this + 0x134),0));
  }
  lVar49 = AbyssEngine::PaintCanvas::TransformGetTransform
                     (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::Transform::Update(lVar49,bVar28);
  this[0x145] = (PlayerEgo)0x0;
  this[0x330] = (PlayerEgo)0x0;
  if (this[500] == (PlayerEgo)0x0) {
    if (this[0x1ee] != (PlayerEgo)0x0) {
      this[0x145] = (PlayerEgo)0x1;
      goto LAB_000a9d90;
    }
    if (this[0x1ed] != (PlayerEgo)0x0) {
      this[0x145] = (PlayerEgo)0x1;
      goto LAB_000a9d9e;
    }
  }
  else {
    this[0x145] = (PlayerEgo)0x1;
    if (this[0x1ee] != (PlayerEgo)0x0) {
LAB_000a9d90:
      *(int *)(this + 0x1f0) = *(int *)(this + 0x134) + *(int *)(this + 0x1f0);
    }
LAB_000a9d9e:
    fVar39 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    AEGeometry::moveForward(*(AEGeometry **)(this + 8),fVar39 * *(float *)(this + 0xb8));
    iVar8 = *(int *)this;
    pMVar18 = (Matrix *)
              AbyssEngine::PaintCanvas::TransformGetLocal
                        (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    pMVar19 = (Matrix *)
              AbyssEngine::PaintCanvas::TransformGetLocal
                        (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
    AbyssEngine::AEMath::operator*((AEMath *)&local_a8,pMVar18,pMVar19);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar8 + 4),(AEMath *)&local_a8);
  }
  if ((this[0x144] != (PlayerEgo)0x0) && (iVar8 = Player::isActive(*(Player **)this), iVar8 == 1)) {
    this[0x234] = (PlayerEgo)0x0;
    pAVar20 = (Array *)Level::getLandmarks(*(Level **)(this + 0xc));
    calcCollision(this,pAVar20);
    pAVar20 = (Array *)Level::getEnemies(*(Level **)(this + 0xc));
    calcCollision(this,pAVar20);
    pAVar20 = (Array *)Level::getAsteroids(*(Level **)(this + 0xc));
    calcCollision(this,pAVar20);
    if ((this[0x234] != (PlayerEgo)0x0) && (this[0x1a0] != (PlayerEgo)0x0)) {
      handleTurretView(this,param_1);
    }
  }
  if (this[0x398] == (PlayerEgo)0x0) {
    *(undefined4 *)(*(int *)this + 0x60) = 0;
  }
  else {
    iVar8 = FModSound::isPlaying(Globals::sound,0x23);
    if (iVar8 == 0) {
      FModSound::play(Globals::sound,0x23,(Vector *)0x0,(Vector *)0x0,extraout_s0_04);
    }
    fVar43 = *(float *)(this + 0x270);
    fVar42 = *(float *)(this + 0x268);
    fVar45 = fVar43 - *(float *)(this + 0x274);
    fVar46 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar40 = fVar42 - *(float *)(this + 0x26c);
    fVar39 = -fVar45;
    if (0.0 < fVar45) {
      fVar39 = fVar45;
    }
    fVar45 = -fVar40;
    if (0.0 < fVar40) {
      fVar45 = fVar40;
    }
    if (fVar45 < fVar39) {
      fVar45 = fVar39;
    }
    pPVar34 = *(Player **)this;
    fVar39 = *(float *)(pPVar34 + 0x60) + fVar46 * 0.001 * 0.5 * fVar45;
    *(float *)(pPVar34 + 0x60) = fVar39;
    uVar7 = in_fpscr & 0xfffffff | (uint)(fVar39 < 1.0) << 0x1f;
    in_fpscr = uVar7 | (uint)NAN(fVar39) << 0x1c;
    *(float *)(this + 0x274) = fVar43;
    *(float *)(this + 0x26c) = fVar42;
    if (((((byte)(uVar7 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) &&
         (this[0x1ee] == (PlayerEgo)0x0)) && (this[0x1ed] == (PlayerEgo)0x0)) &&
       (Player::setHitpoints(pPVar34,0), *(int *)(this + 0x90) == 0)) {
      pEVar21 = operator_new(0x68);
      fVar39 = (float)Explosion::Explosion(pEVar21,0xc);
      *(Explosion **)(this + 0x90) = pEVar21;
      Explosion::setScaling(fVar39);
      pEVar21 = *(Explosion **)(this + 0x90);
      AEGeometry::getPosition();
      local_e4[0] = 0.0;
      local_e4[1] = 0.0;
      local_e4[2] = 0.0;
      Explosion::start(pEVar21,(Vector *)&local_a8,(Vector *)local_e4);
    }
    Player::getHitpoints(*(Player **)this);
    FModSound::setParamValue((int)Globals::sound,0,extraout_s0_05);
  }
  iVar8 = Player::getGammaHP(*(Player **)this);
  fVar39 = extraout_s1_14;
  if (((iVar8 < 1) && (this[0x1ee] == (PlayerEgo)0x0)) && (this[0x1ec] == (PlayerEgo)0x0)) {
    Player::setHitpoints(*(Player **)this,0);
    fVar39 = extraout_s1_15;
  }
  if (this[0x1c0] != (PlayerEgo)0x0) {
    this[0x145] = (PlayerEgo)0x1;
    if (((*(KIPlayer **)(this + 0x1bc) == (KIPlayer *)0x0) ||
        (iVar8 = KIPlayer::isDying(*(KIPlayer **)(this + 0x1bc)), iVar8 != 0)) ||
       (iVar8 = KIPlayer::isDead(*(KIPlayer **)(this + 0x1bc)), iVar8 == 1)) {
      dockToAsteroid(this,(KIPlayer *)0x0,param_2);
      goto LAB_000ab3cc;
    }
    approachAsteroid((Hud *)this,(int)param_3,extraout_r2);
    fVar39 = extraout_s1_16;
  }
  if ((this[0x356] != (PlayerEgo)0x0) &&
     (iVar8 = Player::getHitpoints(*(Player **)this), fVar39 = extraout_s1_17, 0 < iVar8)) {
    this[0x145] = (PlayerEgo)0x1;
    if ((*(KIPlayer **)(this + 0x1bc) == (KIPlayer *)0x0) ||
       ((iVar8 = KIPlayer::isDying(*(KIPlayer **)(this + 0x1bc)), iVar8 != 0 ||
        (iVar8 = KIPlayer::isDead(*(KIPlayer **)(this + 0x1bc)), iVar8 == 1)))) {
      dockToDockingPoint((KIPlayer *)this,(Radar *)0x0);
      goto LAB_000ab3cc;
    }
    iVar8 = approachDockingPoint(this,param_3,extraout_r2_00,param_2);
    fVar39 = extraout_s1_18;
    if (iVar8 == 1) {
      this_02 = (Mission *)Status::getMission(Globals::status);
      this_03 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar8 = Mission::isEmpty(this_02);
      if ((iVar8 == 0) &&
         (((iVar8 = Mission::getType(this_02), iVar8 == 0xf ||
           (iVar8 = Mission::getType(this_02), iVar8 == 0xb8)) &&
          (iVar8 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc)),
          iVar8 == 1)))) {
        iVar8 = *(int *)(this + 0x364);
        fVar39 = extraout_s1_19;
        if (iVar8 != *(int *)(this + 0x360)) {
          iVar11 = Mission::getType(this_02);
          fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x35c),
                                              (byte)(in_fpscr >> 0x16) & 3);
          if (iVar11 == 0xb8) {
            fVar42 = 1500.0;
          }
          else {
            fVar42 = 1000.0;
          }
          iVar11 = (int)(fVar39 / fVar42);
          *(int *)(this + 0x364) = (int)(fVar39 / fVar42);
          fVar39 = extraout_s1_20;
          if (*(int *)(this + 0x360) <= iVar11) {
            if (iVar8 < iVar11) {
              iVar11 = Mission::getType(this_02);
              if (iVar11 == 0xb8) {
                pPVar24 = (PlayerEgo *)0x26;
              }
              else {
                pPVar24 = (PlayerEgo *)0x2a;
              }
              Hud::hudEvent((int)param_3,pPVar24,(int)this);
              fVar39 = extraout_s1_21;
            }
            iVar11 = *(int *)(this + 0x360);
            *(int *)(this + 0x364) = iVar11;
          }
          if (iVar8 < iVar11) {
            iVar11 = Mission::getType(this_02);
            if (iVar11 == 0xb8) {
              fVar39 = extraout_s1_22;
              if (0 < *(int *)(Globals::status + 0x174)) {
                *(int *)(Globals::status + 0x174) =
                     (*(int *)(Globals::status + 0x174) + iVar8) - *(int *)(this + 0x364);
                iVar11 = Mission::getStatusValue(this_02);
                Mission::setStatusValue(this_02,(iVar11 + iVar8) - *(int *)(this + 0x364));
                uVar7 = Mission::getStatusValue(this_02);
                fVar39 = extraout_s1_23;
                if (0x7fffffff < uVar7) {
                  Mission::setStatusValue(this_02,0);
                  fVar39 = extraout_s1_24;
                }
                if (0x7fffffff < *(uint *)(Globals::status + 0x174)) {
                  *(undefined4 *)(Globals::status + 0x174) = 0;
                }
              }
            }
            else {
              iVar11 = Mission::getType(this_02);
              fVar39 = extraout_s1_45;
              if (iVar11 == 0xf) {
                pSVar9 = (Ship *)Status::getShip(Globals::status);
                iVar11 = Mission::getProductionGoodIndex(this_02);
                Ship::removeCargo(pSVar9,iVar11,*(int *)(this + 0x364) - iVar8);
                Level::incNumDeliveredOre(*(Level **)(this + 0xc),*(int *)(this + 0x364) - iVar8);
                fVar39 = extraout_s1_46;
              }
            }
          }
        }
      }
      else {
        iVar8 = Mission::isEmpty(this_02);
        if ((iVar8 == 0) &&
           (((iVar8 = Mission::getType(this_02), iVar8 == 0xb8 ||
             (iVar8 = Mission::getType(this_02), iVar8 == 0xa8)) &&
            (iVar8 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc)),
            iVar8 == 2)))) {
          iVar8 = *(int *)(this + 0x364);
          fVar39 = extraout_s1_25;
          if (iVar8 != *(int *)(this + 0x360)) {
            fVar42 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x35c),
                                                (byte)(in_fpscr >> 0x16) & 3);
            iVar11 = (int)(fVar42 / 1500.0);
            *(int *)(this + 0x364) = (int)(fVar42 / 1500.0);
            if (*(int *)(this + 0x360) <= iVar11) {
              if (iVar8 < iVar11) {
                iVar11 = Mission::getType(this_02);
                if ((iVar11 == 0xb8) || (iVar11 = Mission::getType(this_02), iVar11 == 0xa8)) {
                  pPVar24 = (PlayerEgo *)0x24;
                }
                else {
                  pPVar24 = (PlayerEgo *)0x28;
                }
                Hud::hudEvent((int)param_3,pPVar24,(int)this);
                fVar39 = extraout_s1_47;
              }
              iVar11 = *(int *)(this + 0x360);
              *(int *)(this + 0x364) = iVar11;
            }
            if (iVar8 < iVar11) {
              *(int *)(Globals::status + 0x174) =
                   (iVar11 - iVar8) + *(int *)(Globals::status + 0x174);
            }
          }
        }
        else if (((this_03 == (Mission *)0x0) || (iVar8 = Mission::isEmpty(this_03), iVar8 != 0)) ||
                (((iVar8 = Mission::getType(this_03), iVar8 != 0xa7 &&
                  (iVar8 = Mission::getType(this_03), iVar8 != 0xae)) ||
                 (iVar8 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc)),
                 iVar8 != 1)))) {
          iVar8 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc));
          bVar38 = iVar8 == 3;
          if (bVar38) {
            iVar8 = *(int *)(this + 0x1e8);
          }
          fVar39 = extraout_s1_29;
          if (bVar38 && iVar8 == 0) {
            iVar11 = Level::getNumDockingTargets(*(Level **)(this + 0xc));
            iVar8 = 0;
            if (0 < iVar11) {
              iVar11 = 0;
              do {
                iVar35 = *(int *)(this + 0x1bc);
                iVar22 = Level::getDockingTarget(*(Level **)(this + 0xc),iVar11);
                if (iVar35 == iVar22) {
                  iVar8 = iVar11;
                }
                iVar11 = iVar11 + 1;
                iVar22 = Level::getNumDockingTargets(*(Level **)(this + 0xc));
              } while (iVar11 < iVar22);
            }
            iVar11 = Status::getCurrentCampaignMission(Globals::status);
            this_04 = operator_new(0x140);
            iVar22 = 4;
            if (iVar11 == 0x5b) {
              iVar22 = 1;
            }
            HackingGame::HackingGame(this_04,0,iVar22,-1,-1,iVar8);
            *(HackingGame **)(this + 0x1e8) = this_04;
            Hud::setHackingGameActive(param_3,true);
            fVar39 = extraout_s1_30;
          }
        }
        else {
          iVar8 = *(int *)(this + 0x360);
          iVar11 = *(int *)(this + 0x364);
          fVar39 = extraout_s1_26;
          if (iVar11 != iVar8) {
            fVar42 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x35c),
                                                (byte)(in_fpscr >> 0x16) & 3);
            iVar22 = (int)(fVar42 / 1000.0);
            *(int *)(this + 0x364) = (int)(fVar42 / 1000.0);
            if (iVar8 <= iVar22) {
              if (iVar11 < iVar22) {
                Hud::hudEvent((int)param_3,(PlayerEgo *)0x2a,(int)this);
                iVar8 = *(int *)(this + 0x360);
                fVar39 = extraout_s1_27;
              }
              *(int *)(this + 0x364) = iVar8;
              iVar22 = iVar8;
            }
            if (iVar11 < iVar22) {
              pSVar9 = (Ship *)Status::getShip(Globals::status);
              iVar8 = Mission::getProductionGoodIndex(this_03);
              Ship::removeCargo(pSVar9,iVar8,*(int *)(this + 0x364) - iVar11);
              iVar8 = Mission::getStatusValue(this_03);
              Mission::setStatusValue(this_03,iVar8 + 1);
              fVar39 = extraout_s1_28;
            }
          }
        }
      }
      *(int *)(this + 0x35c) = *(int *)(this + 0x134) + *(int *)(this + 0x35c);
    }
    if (((*(ushort *)(this + 0x1a0) & 0xff) != 0) || (0xff < *(ushort *)(this + 0x1a0))) {
      handleTurretView(this,param_1);
      fVar39 = extraout_s1_31;
    }
  }
  if ((this[0x158] == (PlayerEgo)0x0) || (*(int *)(this + 0x15c) == 0)) {
    fVar42 = 0.0;
    if (this[0x145] == (PlayerEgo)0x0) {
      if (((*(ushort *)(this + 0x1a0) & 0xff) == 0) && (*(ushort *)(this + 0x1a0) < 0x100)) {
        roll(this,*(int *)(this + 0x134));
        iVar8 = updateManeuver(this);
        fVar39 = extraout_s1_34;
        if (iVar8 == 0) {
          handleShip(this,param_1);
          fVar39 = extraout_s1_35;
        }
      }
      else {
LAB_000aa4c6:
        handleTurretView(this,param_1);
        fVar39 = extraout_s1_37;
      }
    }
  }
  else {
    fVar42 = 0.0;
    if ((this[0x145] == (PlayerEgo)0x0) &&
       (iVar8 = updateManeuver(this), fVar39 = extraout_s1_32, iVar8 == 0)) {
      if (this[0x160] == (PlayerEgo)0x0) {
        piVar25 = *(int **)(this + 0x15c);
      }
      else {
        piVar25 = *(int **)(this + 0x15c);
        if ((Route *)piVar25[0x4c] != (Route *)0x0) {
          piVar25 = (int *)Route::getWaypoint((Route *)piVar25[0x4c]);
          *(int **)(this + 0x15c) = piVar25;
          fVar39 = extraout_s1_33;
        }
      }
      if ((piVar25 == (int *)0x0) || (this[0x1ed] != (PlayerEgo)0x0)) {
        *(undefined4 *)(this + 0x15c) = 0;
        this[0x160] = (PlayerEgo)0x0;
        PVar6 = this[0x158];
        this[0x158] = (PlayerEgo)0x0;
        *(undefined4 *)(*(int *)(this + 0x14) + 0x2c) = 0;
        if (PVar6 != (PlayerEgo)0x0) {
          *(undefined4 *)(this + 0x2a4) = 0;
          this[0x2a8] = (PlayerEgo)0x0;
        }
      }
      else {
        (**(code **)(*piVar25 + 0x28))((Vector *)&local_a8);
        AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xec),(Vector *)&local_a8);
        AEGeometry::getPosition();
        AbyssEngine::AEMath::operator-
                  ((AEMath *)&local_a8,(Vector *)(this + 0xec),(Vector *)local_e4);
        fVar39 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_a8);
        if ((int)fVar39 < 20000) {
          this[0x330] = (PlayerEgo)0x1;
        }
        uVar32 = *(undefined4 *)(this + 0xec);
        uVar36 = *(undefined4 *)(this + 0xf0);
        uVar12 = *(undefined4 *)(this + 0xf4);
        pSVar9 = (Ship *)Status::getShip(Globals::status);
        fVar39 = (float)Ship::getHandling(pSVar9);
        fVar42 = 4.0;
        in_fpscr = in_fpscr & 0xfffffff;
        if (fVar39 + 2.7 < 4.0) {
          pSVar9 = (Ship *)Status::getShip(Globals::status);
          fVar42 = (float)Ship::getHandling(pSVar9);
          fVar42 = fVar42 + 2.7;
        }
        fVar42 = (float)moveToPosition(this,uVar32,uVar36,uVar12,1,fVar42);
        fVar39 = extraout_s1_36;
        if (this[0x1a0] != (PlayerEgo)0x0) goto LAB_000aa4c6;
      }
    }
  }
  if ((((this[0x356] != (PlayerEgo)0x0) && (*(uint *)(this + 0x1c4) != 1)) &&
      (this[0x1a0] == (PlayerEgo)0x0)) && ((*(uint *)(this + 0x1c4) | 1) != 3)) {
    updateManeuver(this);
    fVar39 = extraout_s1_38;
  }
  if (((this[0x180] != (PlayerEgo)0x0) && (this[0x355] != (PlayerEgo)0x0)) &&
     ((this[0x354] == (PlayerEgo)0x0 ||
      ((int)(uint)(*(uint *)(param_5 + 8) < 10000) <= *(int *)(param_5 + 0xc))))) {
    iVar8 = Player::getHitpoints(*(Player **)this);
    if (iVar8 < 1) {
      this[0x355] = (PlayerEgo)0x0;
      Player::stopShooting(*(Player **)this,2);
      fVar39 = extraout_s1_40;
    }
    else {
      handleAutoTurret(this,param_1);
      fVar39 = extraout_s1_39;
    }
  }
  if ((this[0x1c0] == (PlayerEgo)0x0) && (1 < *(int *)(this + 0x1c4) - 1U)) {
    uStack_8c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_88 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_84 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar26 = (undefined4 *)((uint)&local_a8 | 4);
    local_a8 = 0x3f800000;
    *puVar26 = 0;
    puVar26[1] = uStack_8c;
    puVar26[2] = uStack_88;
    puVar26[3] = uStack_84;
    local_94 = 0x3f800000;
    local_90 = 0;
    local_80 = 0x3f800000;
    uStack_78 = 0x3f8000003f800000;
    local_70 = 0x3f800000;
    if ((*(int *)(this + 0x15c) == 0) || (this[0x1ed] != (PlayerEgo)0x0)) {
      bVar38 = false;
    }
    else {
      fVar43 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar40 = *(float *)(this + 0x280);
      uVar7 = in_fpscr & 0xfffffff;
      uVar29 = uVar7 | (uint)(fVar40 < fVar42) << 0x1f | (uint)(fVar40 == fVar42) << 0x1e;
      in_fpscr = uVar29 | (uint)(NAN(fVar40) || NAN(fVar42)) << 0x1c;
      fVar43 = fVar43 * *(float *)(this + 0x154) * 0.012345679;
      if ((int)uVar29 < 0) {
        fVar40 = fVar40 + fVar43;
        uVar29 = uVar7 | (uint)(fVar40 < fVar42) << 0x1f | (uint)(fVar40 == fVar42) << 0x1e;
        uVar7 = uVar29 | (uint)(NAN(fVar40) || NAN(fVar42)) << 0x1c;
        *(float *)(this + 0x280) = fVar40;
        bVar2 = (byte)(uVar29 >> 0x18);
        in_fpscr = uVar7;
        if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar7 >> 0x1c) & 1)) {
LAB_000aa632:
          *(float *)(this + 0x280) = fVar42;
          in_fpscr = uVar7;
          fVar40 = fVar42;
        }
      }
      else if (!(bool)((byte)(uVar29 >> 0x1e) & 1) && ((byte)(in_fpscr >> 0x1c) & 1) == 0) {
        fVar40 = fVar40 - fVar43;
        *(float *)(this + 0x280) = fVar40;
        in_fpscr = uVar7;
        if (fVar40 < fVar42) goto LAB_000aa632;
      }
      bVar38 = true;
      *(float *)(this + 0x27c) = fVar40;
    }
    auVar48._0_8_ = (double)*(float *)(this + 0x278) * 0.25 * 0.000244140625 * 6.2831854820251465;
    auVar48._8_8_ = 0x401921fb60000000;
    AbyssEngine::AEMath::MatrixSetRotation
              ((Matrix *)local_e4,*(float *)(this + 0x27c) * -0.00024414062 * 6.2831855,fVar39,
               6.2831855);
    AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_a8,(Matrix *)local_e4);
    AEGeometry::setMatrix(*(Matrix **)(this + 4));
    if (bVar38) {
      iVar8 = *(int *)this;
      pMVar18 = (Matrix *)
                AbyssEngine::PaintCanvas::TransformGetLocal
                          (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
      pMVar19 = (Matrix *)
                AbyssEngine::PaintCanvas::TransformGetLocal
                          (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
      AbyssEngine::AEMath::operator*((AEMath *)local_e4,pMVar18,pMVar19);
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar8 + 4),(AEMath *)local_e4);
    }
    fVar39 = *(float *)(this + 0x27c);
    in_fpscr = in_fpscr & 0xfffffff;
    uVar7 = in_fpscr | (uint)(fVar39 < 0.0) << 0x1f | (uint)(fVar39 == 0.0) << 0x1e;
    bVar2 = (byte)(uVar7 >> 0x18);
    if (Globals::mouseCursorActivated == 0) {
      if (((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar39)) ||
         (*(int *)(this + 0x104) != 0)) {
        if ((fVar39 < 0.0) && (*(int *)(this + 0x104) == 0)) {
          fVar42 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
          fVar39 = fVar39 + (fVar42 * *(float *)(this + 0x154)) / 126.0;
          goto LAB_000aa752;
        }
        goto LAB_000aa79c;
      }
      fVar42 = (float)VectorSignedToFloat(param_1,(byte)(uVar7 >> 0x16) & 3);
      fVar39 = fVar39 + (fVar42 * *(float *)(this + 0x154)) / -126.0;
LAB_000aa788:
      *(float *)(this + 0x27c) = fVar39;
      if (fVar39 < 0.0) {
LAB_000aa796:
        *(undefined4 *)(this + 0x27c) = 0;
      }
    }
    else {
      if ((!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == NAN(fVar39)) &&
         (*(int *)(this + 0x104) == 0)) {
        fVar39 = fVar39 * 0.7;
        goto LAB_000aa788;
      }
      if ((fVar39 < 0.0) && (*(int *)(this + 0x104) == 0)) {
        fVar39 = fVar39 * 0.7;
LAB_000aa752:
        in_fpscr = in_fpscr | (uint)(fVar39 < 0.0) << 0x1f | (uint)(fVar39 == 0.0) << 0x1e;
        *(float *)(this + 0x27c) = fVar39;
        bVar2 = (byte)(in_fpscr >> 0x18);
        if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar39)) goto LAB_000aa79c;
        goto LAB_000aa796;
      }
    }
LAB_000aa79c:
    fVar39 = *(float *)(this + 0x278);
    in_fpscr = in_fpscr & 0xfffffff;
    uVar7 = in_fpscr | (uint)(fVar39 < 0.0) << 0x1f | (uint)(fVar39 == 0.0) << 0x1e;
    uVar29 = uVar7 | (uint)NAN(fVar39) << 0x1c;
    bVar2 = (byte)(uVar7 >> 0x18);
    if (((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar29 >> 0x1c) & 1)) ||
       (*(int *)(this + 0x100) != 0)) {
      if ((fVar39 < 0.0) && (*(int *)(this + 0x100) == 0)) {
        fVar42 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar39 = fVar39 + (fVar42 * *(float *)(this + 0x154)) / 126.0;
        uVar7 = in_fpscr | (uint)(fVar39 < 0.0) << 0x1f | (uint)(fVar39 == 0.0) << 0x1e;
        in_fpscr = uVar7 | (uint)NAN(fVar39) << 0x1c;
        *(float *)(this + 0x278) = fVar39;
        bVar2 = (byte)(uVar7 >> 0x18);
        if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1))
        goto LAB_000aa816;
      }
    }
    else {
      fVar42 = (float)VectorSignedToFloat(param_1,(byte)(uVar29 >> 0x16) & 3);
      fVar39 = fVar39 + (fVar42 * *(float *)(this + 0x154)) / -126.0;
      *(float *)(this + 0x278) = fVar39;
      if (fVar39 < 0.0) {
LAB_000aa816:
        *(undefined4 *)(this + 0x278) = 0;
      }
    }
    if (*(int *)(this + 0x194) != 0) {
      TargetFollowCamera::setRumblePercentage
                (*(TargetFollowCamera **)(this + 0x88),fVar39,0x3e4ccccd);
    }
    in_q8._8_8_ = 0;
    in_q8._0_8_ = auVar48._8_8_;
    in_q8 = in_q8 << 0x40;
    *(undefined4 *)(this + 600) = 0;
    *(undefined4 *)(this + 0x25c) = 0;
    *(undefined8 *)(this + 0x100) = 0;
    *(undefined4 *)(this + 0x270) = 0;
    *(undefined4 *)(this + 0x268) = 0;
  }
  pSVar9 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getShieldRegen(pSVar9);
  if ((0 < iVar8) && (iVar8 = Player::getHitpoints(*(Player **)this), 0 < iVar8)) {
    uVar7 = *(uint *)(this + 0x118) + param_1;
    iVar8 = *(int *)(this + 0x11c) +
            (param_1 >> 0x1f) + (uint)CARRY4(*(uint *)(this + 0x118),param_1);
    *(uint *)(this + 0x118) = uVar7;
    *(int *)(this + 0x11c) = iVar8;
    if ((int)(uint)(uVar7 < 0x65) <= iVar8) {
      *(undefined4 *)(this + 0x118) = 0;
      *(undefined4 *)(this + 0x11c) = 0;
      Player::regenerateShield(*(Player **)this,extraout_s0_06);
    }
  }
  pSVar9 = (Ship *)Status::getShip(Globals::status);
  iVar8 = Ship::getRepairType(pSVar9);
  if ((-1 < iVar8) && (iVar11 = Player::getHitpoints(*(Player **)this), 0 < iVar11)) {
    pPVar24 = this + 0x120;
    pfVar23 = (float *)&DAT_000ab4a8;
    if (iVar8 == 0) {
      pfVar23 = (float *)&DAT_000ab4ac;
    }
    fVar42 = *pfVar23;
    auVar47._8_8_ = in_q8._8_8_ & 0xffff0000ffff0000 | (ulonglong)(uint)param_1 & 0xffff;
    auVar47._0_8_ = in_q8._0_8_ & 0xffff0000ffff0000 | (ulonglong)(uint)param_1 & 0xffff;
    auVar48 = VectorAdd(*(undefined1 (*) [16])pPVar24,auVar47,8);
    *(longlong *)pPVar24 = auVar48._0_8_;
    *(longlong *)(this + 0x128) = auVar48._8_8_;
    fVar39 = (float)__aeabi_l2f(auVar48._0_4_,auVar48._4_4_);
    uVar7 = in_fpscr & 0xfffffff | (uint)(fVar39 < fVar42) << 0x1f |
            (uint)(fVar39 == fVar42) << 0x1e;
    uVar29 = uVar7 | (uint)(NAN(fVar39) || NAN(fVar42)) << 0x1c;
    bVar2 = (byte)(uVar7 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(uVar29 >> 0x1c) & 1)) {
      *(undefined4 *)pPVar24 = 0;
      *(undefined4 *)(this + 0x124) = 0;
      iVar11 = Player::getHitpoints(*(Player **)this);
      iVar22 = Player::getMaxHitpoints(*(Player **)this);
      if (iVar11 < iVar22) {
        Player::regenerateHull(*(Player **)this);
      }
    }
    pfVar23 = (float *)&DAT_000ab4b0;
    if (iVar8 == 0) {
      pfVar23 = (float *)&DAT_000ab4b4;
    }
    fVar39 = (float)__aeabi_l2f(*(undefined4 *)(this + 0x128),*(undefined4 *)(this + 300));
    fVar42 = *pfVar23;
    uVar7 = uVar29 & 0xfffffff | (uint)(fVar39 < fVar42) << 0x1f | (uint)(fVar39 == fVar42) << 0x1e;
    in_fpscr = uVar7 | (uint)(NAN(fVar39) || NAN(fVar42)) << 0x1c;
    bVar2 = (byte)(uVar7 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
      *(undefined4 *)(this + 0x128) = 0;
      *(undefined4 *)(this + 300) = 0;
      iVar8 = Player::getHitpoints(*(Player **)this);
      iVar11 = Player::getMaxHitpoints(*(Player **)this);
      if (iVar11 <= iVar8) {
        iVar8 = Player::getArmorHP(*(Player **)this);
        iVar11 = Player::getMaxArmorHP(*(Player **)this);
        if (iVar8 < iVar11) {
          Player::regenerateArmor(*(Player **)this);
        }
      }
    }
  }
  if ((*(int *)(this + 0xac) != 0) && (0 < *(int *)(this + 0x30c))) {
    Player::setVulnerable(*(Player **)this,false);
    *(int *)(this + 0x30c) = *(int *)(this + 0x30c) - param_1;
    AEGeometry::setMatrix(*(Matrix **)(this + 0xac));
    AbyssEngine::AEMath::MatrixRotateVector
              ((AEMath *)&local_a8,(Matrix *)(*(int *)this + 4),(Vector *)(this + 0x314));
    AEGeometry::translate(*(Vector **)(this + 0xac));
    fVar39 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    iVar8 = AbyssEngine::PaintCanvas::MeshGetPointer
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xac) + 0x1c));
    *(float *)(iVar8 + 0x24) = fVar39 * 0.001 + *(float *)(iVar8 + 0x24);
    fVar39 = (float)VectorSignedToFloat(*(int *)(this + 0x310),(byte)(in_fpscr >> 0x16) & 3);
    fVar42 = (float)VectorSignedToFloat(*(int *)(this + 0x30c),(byte)(in_fpscr >> 0x16) & 3);
    fVar40 = fVar39 * 0.95;
    in_fpscr = in_fpscr & 0xfffffff;
    uVar7 = in_fpscr | (uint)(fVar42 < fVar40) << 0x1f | (uint)(fVar42 == fVar40) << 0x1e;
    uVar29 = uVar7 | (uint)(NAN(fVar42) || NAN(fVar40)) << 0x1c;
    bVar2 = (byte)(uVar7 >> 0x18);
    if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(uVar29 >> 0x1c) & 1)) {
      if (fVar42 < fVar39 * 0.05) goto LAB_000aaa5c;
      fVar42 = 1.0;
    }
    else {
      fVar42 = (float)VectorSignedToFloat(*(int *)(this + 0x310) - *(int *)(this + 0x30c),
                                          (byte)(uVar29 >> 0x16) & 3);
      in_fpscr = uVar29;
LAB_000aaa5c:
      fVar42 = fVar42 / (fVar39 * 0.05);
    }
    AEGeometry::setScaling
              (*(AEGeometry **)(this + 0xac),fVar42 * *(float *)(this + 800),extraout_s1_41,
               *(float *)(this + 800));
    uVar7 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0xac) + 0xc));
    AbyssEngine::Transform::Update((ulonglong)uVar7,bVar28);
    if (*(int *)(this + 0x30c) < 1) {
      if (*(AEGeometry **)(this + 0xac) != (AEGeometry *)0x0) {
        pvVar14 = (void *)AEGeometry::~AEGeometry(*(AEGeometry **)(this + 0xac));
        operator_delete(pvVar14);
      }
      *(undefined4 *)(this + 0xac) = 0;
      Player::setVulnerable(*(Player **)this,true);
      FModSound::stop(Globals::sound,0x45b);
      *(undefined4 *)(Globals::status + 0x13c) = 0;
    }
  }
  pPVar34 = *(Player **)this;
  iVar8 = Player::getHitpoints(pPVar34);
  bVar28 = false;
  if ((0 < iVar8) && (*(int *)(this + 0x1c) != -1)) {
    bVar28 = true;
  }
  Player::update(pPVar34,param_1,bVar28);
  if (((this[0x38] != (PlayerEgo)0x0) && (Globals::options[0xf] != '\0')) &&
     (*(int *)(this + 0xb4) != -1)) {
    Player::getPosition();
    FModSound::updateEvent3DAttributes
              (Globals::sound,*(int *)(this + 0xb4),(Vector *)&local_a8,(Vector *)0x0,false);
  }
  pMVar18 = (Matrix *)
            AbyssEngine::PaintCanvas::TransformGetLocal
                      (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
  AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_a8,pMVar18);
  AbyssEngine::AEMath::Vector::operator=((Vector *)vec_up,(Vector *)&local_a8);
  uVar12 = ParticleSettingsRef::cur._672_4_;
  if (this[0x13c] == (PlayerEgo)0x0) {
    AbyssEngine::String::operator=
              ((String *)(ParticleSettingsRef::cur + 0x270),ParticleSettingsRef::init + 0x270);
    __aeabi_memcpy4(0x26d65c,0x26f39c,0x94);
    ParticleSettingsRef::cur._672_4_ = uVar12;
  }
  else {
    fVar39 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x138),(byte)(in_fpscr >> 0x16) & 3);
    fVar42 = (float)VectorSignedToFloat(*(int *)(this + 0xcc) / 6,(byte)(in_fpscr >> 0x16) & 3);
    fVar39 = fVar39 / fVar42;
    in_fpscr = in_fpscr & 0xfffffff;
    if (1.0 <= fVar39) {
      uVar7 = in_fpscr | (uint)(fVar39 < 5.0) << 0x1f | (uint)(fVar39 == 5.0) << 0x1e;
      in_fpscr = uVar7 | (uint)NAN(fVar39) << 0x1c;
      bVar2 = (byte)(uVar7 >> 0x18);
      fVar42 = 6.0 - fVar39;
      fVar39 = 1.0;
      if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar39 = fVar42;
      }
    }
    ParticleSettings::Interpolate(4,6,fVar39,4);
  }
  if (*(Route **)(this + 0xfc) != (Route *)0x0) {
    iVar8 = Route::getCurrent(*(Route **)(this + 0xfc));
    Route::update(*(Vector **)(this + 0xfc));
    iVar11 = Route::getCurrent(*(Route **)(this + 0xfc));
    if (iVar11 != iVar8) {
      if (((*(Route **)(this + 0xfc))[4] == (Route)0x0) &&
         (iVar8 = Route::getCurrent(*(Route **)(this + 0xfc)), iVar8 == 0)) {
        pPVar24 = (PlayerEgo *)0x18;
      }
      else {
        pPVar24 = (PlayerEgo *)0x17;
      }
      Hud::hudEvent((int)param_3,pPVar24,(int)this);
    }
  }
  this[0x30a] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0x20) = 0;
  if ((byte)this[0x378] != Globals::mouseCursorActivated) {
    this[0x84] = (PlayerEgo)0x1;
  }
  iVar11 = *(int *)(this + 0x130);
  iVar8 = Player::getCombinedHP(*(Player **)this);
  if (((iVar8 < iVar11) && (this[500] == (PlayerEgo)0x0)) && (this[0x24] == (PlayerEgo)0x0)) {
    Hud::playerHit(param_3);
    uVar12 = Player::getCombinedHP(*(Player **)this);
    *(undefined4 *)(this + 0x130) = uVar12;
    *(undefined4 *)(this + 0x328) = 0;
    this[0x32c] = (PlayerEgo)0x1;
    fVar39 = (float)TargetFollowCamera::hit(*(TargetFollowCamera **)(this + 0x88));
    uVar7 = *(uint *)(*(int *)this + 100);
    if ((uVar7 & 0xff) == 0) {
      if ((uVar7 & 0xff00) == 0) {
        if ((uVar7 & 0xff0000) != 0) {
          FModSound::play(Globals::sound,0x18,(Vector *)0x0,(Vector *)0x0,fVar39);
          *(undefined1 *)(*(int *)this + 0x66) = 0;
        }
      }
      else {
        FModSound::play(Globals::sound,0x17,(Vector *)0x0,(Vector *)0x0,fVar39);
        *(undefined1 *)(*(int *)this + 0x65) = 0;
      }
    }
    else {
      this[0x30a] = (PlayerEgo)0x1;
      FModSound::play(Globals::sound,0x19,(Vector *)0x0,(Vector *)0x0,fVar39);
      *(undefined1 *)(*(int *)this + 100) = 0;
    }
    Player::getHitVector();
    fVar39 = (float)AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_a8,(Vector *)local_e4);
    pPVar4 = Globals::Canvas;
    local_e4[0] = 0.0;
    local_e4[1] = 0.0;
    local_e4[2] = 0.0;
    AbyssEngine::AEMath::operator*((AEMath *)&local_f0,(Vector *)&local_a8,fVar39);
    AbyssEngine::AEMath::operator+((AEMath *)&local_6c,(Vector *)&local_f0,(Vector *)(this + 0x148))
    ;
    AbyssEngine::PaintCanvas::GetScreenPosition(pPVar4,(Vector *)&local_6c,(Vector *)local_e4);
    uVar7 = in_fpscr & 0xfffffff | (uint)(local_e4[0] == 0.0) << 0x1e |
            (uint)(0.0 <= local_e4[0]) << 0x1d;
    bVar2 = (byte)(uVar7 >> 0x18);
    if (!(bool)(bVar2 >> 5 & 1) || (bool)(bVar2 >> 6)) {
      uVar29 = 1;
    }
    else {
      fVar39 = (float)VectorSignedToFloat(Globals::w,(byte)(uVar7 >> 0x16) & 3);
      uVar7 = in_fpscr & 0xfffffff | (uint)(local_e4[0] < fVar39) << 0x1f;
      if (SUB41(uVar7 >> 0x1f,0) == (NAN(local_e4[0]) || NAN(fVar39))) {
        uVar29 = 2;
      }
      else {
        uVar29 = 0;
      }
    }
    *(uint *)(this + 0x20) = uVar29;
    uVar7 = uVar7 & 0xfffffff;
    if (0.0 <= local_e4[2]) {
      uVar27 = uVar29 | 0x20;
      *(uint *)(this + 0x20) = uVar27;
      if (-50000.0 <= local_e4[0]) {
        if (local_e4[0] < -15000.0) {
          uVar27 = uVar29 | 0x21;
          goto LAB_000aae32;
        }
      }
      else {
        uVar27 = 1;
LAB_000aae32:
        *(uint *)(this + 0x20) = uVar27;
      }
      uVar29 = uVar7 | (uint)(local_e4[0] < 50000.0) << 0x1f |
               (uint)(local_e4[0] == 50000.0) << 0x1e;
      in_fpscr = uVar29 | (uint)NAN(local_e4[0]) << 0x1c;
      bVar2 = (byte)(uVar29 >> 0x18);
      if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) {
        uVar7 = uVar7 | (uint)(local_e4[0] < 15000.0) << 0x1f |
                (uint)(local_e4[0] == 15000.0) << 0x1e;
        in_fpscr = uVar7 | (uint)NAN(local_e4[0]) << 0x1c;
        bVar2 = (byte)(uVar7 >> 0x18);
        if ((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1))
        goto LAB_000aae5e;
        uVar29 = uVar27 | 2;
      }
      else {
        uVar29 = 2;
      }
    }
    else {
      uVar29 = uVar29 | 0x10;
      in_fpscr = uVar7;
    }
    *(uint *)(this + 0x20) = uVar29;
  }
LAB_000aae5e:
  AbyssEngine::AEMath::MatrixGetPosition((AEMath *)local_e4,(Matrix *)(*(int *)this + 4));
  AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_6c,(Matrix *)(*(int *)this + 4));
  if (this[0x1a0] != (PlayerEgo)0x0) {
    pMVar18 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x2c));
    pMVar19 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 0x28));
    AbyssEngine::AEMath::operator*((AEMath *)&local_a8,pMVar18,pMVar19);
    AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_f0,(AEMath *)&local_a8);
    AbyssEngine::AEMath::Vector::operator=((Vector *)local_e4,(Vector *)&local_f0);
    AbyssEngine::AEMath::MatrixGetDir((AEMath *)&local_f0,(AEMath *)&local_a8);
    AbyssEngine::AEMath::Vector::operator=((Vector *)&local_6c,(Vector *)&local_f0);
  }
  if ((Globals::mouseCursorActivated == 0) || (_param_7 != 0)) {
LAB_000ab050:
    fVar39 = (float)AbyssEngine::AEMath::VectorNormalize(aAStack_fc,(Vector *)&local_6c);
    AbyssEngine::AEMath::operator*((AEMath *)&local_f0,fVar39,(Vector *)0x46abe000);
    AbyssEngine::AEMath::operator+((AEMath *)&local_a8,(Vector *)local_e4,(Vector *)&local_f0);
    AbyssEngine::PaintCanvas::GetScreenPosition
              (Globals::Canvas,(Vector *)&local_a8,(Vector *)crosshairPos);
    if ((float)crosshairPos._8_4_ <= 0.0) {
      this_05 = crosshairPos;
      fVar39 = (float)AbyssEngine::AEMath::operator*
                                (aAStack_fc,(Vector *)crosshairPos,(float)crosshairPos._8_4_);
      AbyssEngine::AEMath::operator*(aAStack_108,(Vector *)(this + 0x94),fVar39);
      this_06 = (undefined1 *)&local_f0;
      AbyssEngine::AEMath::operator+((AEMath *)this_06,(Vector *)aAStack_fc,(Vector *)aAStack_108);
    }
    else {
      this_05 = crosshairPos;
      local_f0._4_4_ = crosshairPos._4_4_;
      local_f0._0_4_ = crosshairPos._0_4_;
      local_e8 = crosshairPos._8_4_;
      this_06 = (undefined1 *)&local_f0;
    }
  }
  else {
    if ((param_8 == 3) || (this[0x158] != (PlayerEgo)0x0 && param_8 != 1)) goto LAB_000ab050;
    fVar45 = (float)VectorSignedToFloat(Globals::w >> 1,(byte)(in_fpscr >> 0x16) & 3);
    fVar39 = fVar45 * 0.7;
    fVar43 = (float)VectorSignedToFloat(Globals::mouseDeltaX,(byte)(in_fpscr >> 0x16) & 3);
    in_fpscr = in_fpscr & 0xfffffff;
    uVar7 = in_fpscr | (uint)(fVar39 < fVar43) << 0x1f | (uint)(fVar39 == fVar43) << 0x1e;
    bVar2 = (byte)(uVar7 >> 0x18);
    fVar46 = (float)VectorSignedToFloat(Globals::h >> 1,(byte)(uVar7 >> 0x16) & 3);
    fVar42 = fVar46 * 0.7;
    fVar40 = fVar39;
    if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == (NAN(fVar39) || NAN(fVar43))) {
      fVar40 = fVar43;
    }
    if (fVar40 < -fVar39) {
      fVar40 = -fVar39;
    }
    Globals::mouseDeltaX = (int)fVar40;
    fVar44 = (float)VectorSignedToFloat(Globals::mouseDeltaY,(byte)(in_fpscr >> 0x16) & 3);
    fVar43 = fVar42;
    if (fVar44 < fVar42) {
      fVar43 = fVar44;
    }
    if (fVar43 < -fVar42) {
      fVar43 = -fVar42;
    }
    uVar7 = (uint)fVar40;
    fVar40 = (float)VectorSignedToFloat(uVar7,(byte)(in_fpscr >> 0x16) & 3);
    uVar29 = (uint)fVar43;
    fVar44 = (float)VectorSignedToFloat(uVar29,(byte)(in_fpscr >> 0x16) & 3);
    crosshairPos._0_4_ = fVar45 + fVar39;
    if (fVar45 + fVar40 < fVar45 + fVar39) {
      crosshairPos._0_4_ = fVar45 + fVar40;
    }
    crosshairPos._4_4_ = fVar46 + fVar42;
    if (fVar46 + fVar44 < fVar46 + fVar42) {
      crosshairPos._4_4_ = fVar46 + fVar44;
    }
    Globals::mouseDeltaY = (int)fVar43;
    if ((float)crosshairPos._0_4_ < fVar45 - fVar39) {
      crosshairPos._0_4_ = fVar45 - fVar39;
    }
    if ((float)crosshairPos._4_4_ < fVar46 - fVar42) {
      crosshairPos._4_4_ = fVar46 - fVar42;
    }
    if ((int)uVar7 < 1) {
      if (0x7fffffff < uVar7) {
        left((int)this,-fVar40 / fVar39);
      }
    }
    else {
      right((int)this,fVar40 / fVar39);
    }
    if ((int)uVar29 < 1) {
      if (0x7fffffff < uVar29) {
        up((int)this,-fVar44 / fVar42);
      }
    }
    else {
      down((int)this,fVar44 / fVar42);
    }
    fVar39 = (float)AbyssEngine::AEMath::VectorNormalize(aAStack_fc,(Vector *)&local_6c);
    AbyssEngine::AEMath::operator*((AEMath *)&local_f0,fVar39,(Vector *)0x46abe000);
    AbyssEngine::AEMath::operator+((AEMath *)&local_a8,(Vector *)local_e4,(Vector *)&local_f0);
    AbyssEngine::PaintCanvas::GetScreenPosition
              (Globals::Canvas,(Vector *)&local_a8,(Vector *)crosshairShootPos);
    if ((float)crosshairShootPos._8_4_ <= 0.0) {
      fVar39 = (float)AbyssEngine::AEMath::operator*
                                (aAStack_fc,(Vector *)crosshairShootPos,
                                 (float)crosshairShootPos._8_4_);
      AbyssEngine::AEMath::operator*(aAStack_108,(Vector *)(this + 0xa0),fVar39);
      AbyssEngine::AEMath::operator+((AEMath *)&local_f0,(Vector *)aAStack_fc,(Vector *)aAStack_108)
      ;
      AbyssEngine::AEMath::Vector::operator=((Vector *)crosshairShootPos,(Vector *)&local_f0);
    }
    else {
      local_e8 = crosshairShootPos._8_4_;
      local_f0 = crosshairShootPos._0_8_;
      AbyssEngine::AEMath::Vector::operator=((Vector *)crosshairShootPos,(Vector *)&local_f0);
    }
    this_05 = this + 0xa0;
    this_06 = crosshairShootPos;
  }
  AbyssEngine::AEMath::Vector::operator=((Vector *)this_05,(Vector *)this_06);
  if ((this[0x84] != (PlayerEgo)0x0) &&
     (iVar8 = TargetFollowCamera::isInFastForwardMode(*(TargetFollowCamera **)(this + 0x88)),
     iVar8 == 0)) {
    if (Globals::mouseCursorActivated == 0) {
      TargetFollowCamera::resetShipHandling();
    }
    else {
      TargetFollowCamera::setShipHandling(*(TargetFollowCamera **)(this + 0x88),extraout_s0_07);
    }
    this[0x84] = (PlayerEgo)0x0;
  }
  this[0x378] = (PlayerEgo)(Globals::mouseCursorActivated != 0);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x94),(Vector *)crosshairPos);
  iVar8 = Player::getHitpoints(*(Player **)this);
  if ((iVar8 < 1) && (*(int *)(this + 0x8c) != 0)) {
    fVar40 = (float)Player::stopShooting(*(Player **)this,0);
    fVar39 = extraout_s2_10;
    fVar42 = extraout_s1_42;
    if (*(int *)(this + 0x1b4) != 0) {
      fVar40 = (float)FModSound::stop(Globals::sound,0);
      fVar39 = extraout_s2_11;
      fVar42 = extraout_s1_43;
    }
    if (*(int *)(this + 0x1b8) != 0) {
      fVar40 = (float)FModSound::stop(Globals::sound,0);
      fVar39 = extraout_s2_12;
      fVar42 = extraout_s1_44;
    }
    if ((this[0x356] == (PlayerEgo)0x0) || (*(int *)(this + 0x1c4) != 1)) {
      AEGeometry::rotate(*(AEGeometry **)(this + 4),fVar40,fVar42,fVar39);
    }
    iVar8 = *(int *)(this + 0x2f8);
    if (iVar8 < 3000) {
      if (2999 < iVar8 + *(int *)(this + 0x134)) {
        pEVar21 = *(Explosion **)(this + 0x8c);
        AEGeometry::getPosition();
        local_f0 = 0;
        local_e8 = 0;
        Explosion::start(pEVar21,(Vector *)&local_a8,(Vector *)&local_f0);
        ParticleSystemManager::enableSystemEmit
                  (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x74),*(int *)(this + 0x2fc),
                   false);
        fVar39 = (float)ParticleSystemManager::enableSystemRender
                                  (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x74),
                                   *(int *)(this + 0x2fc),false);
        ParticleSystemManager::emitManual
                  (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x74),
                   *(int *)(*(int *)(this + 0xc) + 0x3c),(Vector *)local_e4,0,(Vector *)&local_6c,
                   fVar39);
      }
    }
    else if (iVar8 != 3000) {
      iVar8 = *(int *)(this + 0x8c);
      pVVar31 = *(Vector **)(this + 0x134);
      AEGeometry::getPosition();
      Explosion::update(iVar8,pVVar31);
    }
    iVar8 = *(int *)(this + 0x90);
    if (iVar8 != 0) {
      pVVar31 = *(Vector **)(this + 0x134);
      AEGeometry::getPosition();
      Explosion::update(iVar8,pVVar31);
    }
    *(int *)(this + 0x2f8) = *(int *)(this + 0x134) + *(int *)(this + 0x2f8);
  }
  if (this[0x170] != (PlayerEgo)0x0) {
    pMVar33 = *(Matrix **)(this + 0x2c);
    pMVar18 = (Matrix *)
              AbyssEngine::PaintCanvas::TransformGetLocal
                        (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
    pMVar19 = (Matrix *)
              AbyssEngine::PaintCanvas::TransformGetLocal
                        (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
    AbyssEngine::AEMath::operator*((AEMath *)&local_a8,pMVar18,pMVar19);
    AEGeometry::setMatrix(pMVar33);
  }
LAB_000ab3cc:
  if (__stack_chk_guard != local_54) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::calcCollision  @0x000ab550  (1058 bytes)
/* PlayerEgo::calcCollision(Array<KIPlayer*>*) */

void __thiscall PlayerEgo::calcCollision(PlayerEgo *this,Array *param_1)

{
  Vector *this_00;
  int iVar1;
  float fVar2;
  Matrix *pMVar3;
  Matrix *pMVar4;
  code *pcVar5;
  KIPlayer *this_01;
  int iVar6;
  uint uVar7;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float fVar8;
  float extraout_s1;
  float extraout_s2;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if ((param_1 != (Array *)0x0) &&
     (((this[0x356] == (PlayerEgo)0x0 || (2 < *(int *)(this + 0x1c4) - 1U)) &&
      (*(int *)param_1 != 0)))) {
    this_00 = (Vector *)(this + 0xec);
    uVar7 = 0;
    do {
      this_01 = *(KIPlayer **)(*(int *)(param_1 + 4) + uVar7 * 4);
      if (this_01 != (KIPlayer *)0x0) {
        if ((uVar7 == 0) && (iVar1 = Status::inAlienOrbit(Globals::status), iVar1 == 0)) {
          fVar2 = (float)AbyssEngine::AEMath::VectorLength((Vector *)(this + 0x148));
          in_fpscr = in_fpscr & 0xfffffff;
          if ((fVar2 < 16000.0) && (this_01[0x6d] != (KIPlayer)0x0)) {
            this[0x234] = (PlayerEgo)0x1;
          }
        }
        pcVar5 = *(code **)(*(int *)this_01 + 0x40);
        AEGeometry::getPosition();
        iVar1 = (*pcVar5)(this_01,(Vector *)&local_88);
        if (iVar1 == 1) {
          iVar1 = KIPlayer::getType(this_01);
          if ((iVar1 == 0x4262) && (iVar1 = KIPlayer::isVisible(this_01), iVar1 == 1)) {
            iVar1 = PlayerWormHole::isShrinking((PlayerWormHole *)this_01);
            if ((iVar1 == 0) && (*(int *)(this + 0x1e4) == 0)) {
              (**(code **)(*(int *)this_01 + 0x28))((Vector *)&local_88,this_01);
              AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_88);
              AEGeometry::getPosition();
              AbyssEngine::AEMath::Vector::operator-=(this_00,(Vector *)&local_88);
              fVar2 = (float)AbyssEngine::AEMath::VectorLength(this_00);
              iVar6 = 40000 - (int)fVar2;
              iVar1 = FModSound::isPlaying(Globals::sound,0x22);
              if (iVar6 < 1) {
                if (iVar1 == 1) {
                  FModSound::stop(Globals::sound,0x22);
                }
              }
              else {
                if (iVar1 == 0) {
                  FModSound::play(Globals::sound,0x22,(Vector *)0x0,(Vector *)0x0,extraout_s0);
                }
                else {
                  local_88 = 0;
                  local_80 = 0;
                  (**(code **)(*(int *)this_01 + 0x28))((Vector *)&local_48,this_01);
                  FModSound::updateEvent3DAttributes
                            (Globals::sound,0x22,(Vector *)&local_48,(Vector *)&local_88,false);
                }
                AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_88,this_00);
                AbyssEngine::AEMath::Vector::operator=(this_00,(Vector *)&local_88);
                local_88 = *(undefined8 *)this_00;
                local_80 = *(undefined4 *)(this + 0xf4);
                AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xe0),(Vector *)&local_88);
                fVar8 = (float)VectorSignedToFloat(iVar6 >> 8,(byte)(in_fpscr >> 0x16) & 3);
                AbyssEngine::AEMath::Vector::operator*=((Vector *)(this + 0xe0),fVar8);
                AEGeometry::translate(*(Vector **)(this + 8));
                *(undefined4 *)(this + 0x328) = 0;
                this[0x32c] = (PlayerEgo)0x1;
                TargetFollowCamera::hit(*(TargetFollowCamera **)(this + 0x88));
                if ((int)fVar2 < 1000) {
                  this[0x25] = (PlayerEgo)0x1;
                }
                iVar1 = *(int *)this;
                pMVar3 = (Matrix *)
                         AbyssEngine::PaintCanvas::TransformGetLocal
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
                pMVar4 = (Matrix *)
                         AbyssEngine::PaintCanvas::TransformGetLocal
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
                AbyssEngine::AEMath::operator*((AEMath *)&local_88,pMVar3,pMVar4);
                AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar1 + 4),(Vector *)&local_88);
              }
            }
          }
          else if (this_01[0x38] == (KIPlayer)0x0) {
            iVar1 = KIPlayer::isVisible(this_01);
            if (iVar1 == 1) {
              pcVar5 = *(code **)(*(int *)this_01 + 0x58);
              AEGeometry::getPosition();
              (*pcVar5)((Vector *)&local_48,this_01,(Vector *)&local_88);
              local_88 = 0;
              local_80 = 0;
              iVar1 = AbyssEngine::AEMath::operator!=((Vector *)&local_48,(Vector *)&local_88);
              if (iVar1 == 1) {
                AEGeometry::setPosition(*(Vector **)(this + 8));
                iVar1 = *(int *)this;
                pMVar3 = (Matrix *)
                         AbyssEngine::PaintCanvas::TransformGetLocal
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 8) + 0xc));
                pMVar4 = (Matrix *)
                         AbyssEngine::PaintCanvas::TransformGetLocal
                                   (Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
                AbyssEngine::AEMath::operator*((AEMath *)&local_88,pMVar3,pMVar4);
                AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar1 + 4),(Vector *)&local_88);
                if ((uVar7 == 0) && (this_01[0x6d] != (KIPlayer)0x0)) {
                  this[0x234] = (PlayerEgo)0x1;
                }
              }
              *(undefined4 *)(this + 0x328) = 0;
              this[0x32c] = (PlayerEgo)0x1;
              TargetFollowCamera::hit(*(TargetFollowCamera **)(this + 0x88));
            }
          }
          else {
            iVar1 = KIPlayer::isDying(this_01);
            if (((iVar1 == 0) && (iVar1 = KIPlayer::isDead(this_01), iVar1 == 0)) &&
               (((this[0x1c0] == (PlayerEgo)0x0 && (this[0x356] == (PlayerEgo)0x0)) ||
                (this_01 != *(KIPlayer **)(this + 0x1bc))))) {
              pcVar5 = *(code **)(*(int *)this_01 + 0x50);
              AEGeometry::getPosition();
              (*pcVar5)((Vector *)&local_88,this_01,(Vector *)&local_48);
              local_48 = 0;
              uStack_44 = 0;
              local_40 = 0;
              iVar1 = AbyssEngine::AEMath::operator!=((Vector *)&local_88,(Vector *)&local_48);
              if (iVar1 == 1) {
                fVar2 = (float)Player::setHitVector
                                         (*(Player **)(this_01 + 4),extraout_s0_00,extraout_s1,
                                          extraout_s2);
                Player::setBombForce(*(Player **)(this_01 + 4),fVar2);
                Player::damage(*(Player **)(this_01 + 4),9999);
                Player::damage(*(Player **)this,0x14);
                if (this[0x398] != (PlayerEgo)0x0) {
                  *(float *)(*(int *)this + 0x60) = *(float *)(*(int *)this + 0x60) + 0.2;
                }
                *(undefined4 *)(this + 0x328) = 0;
                this[0x32c] = (PlayerEgo)0x1;
                TargetFollowCamera::hit(*(TargetFollowCamera **)(this + 0x88));
              }
            }
          }
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)param_1);
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::isDockingToPlanet  @0x000ab9a8  (6 bytes)
/* PlayerEgo::isDockingToPlanet() */

PlayerEgo __thiscall PlayerEgo::isDockingToPlanet(PlayerEgo *this)

{
  return this[0x1ee];
}

// ===== PlayerEgo::isDockingToStream  @0x000ab9ae  (6 bytes)
/* PlayerEgo::isDockingToStream() */

PlayerEgo __thiscall PlayerEgo::isDockingToStream(PlayerEgo *this)

{
  return this[0x1ec];
}

// ===== PlayerEgo::dockToAsteroid  @0x000ab9b4  (196 bytes)
/* PlayerEgo::dockToAsteroid(KIPlayer*, Radar*) */

void __thiscall PlayerEgo::dockToAsteroid(PlayerEgo *this,KIPlayer *param_1,Radar *param_2)

{
  void *pvVar1;
  float fVar2;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (this[0x1c0] == (PlayerEgo)0x0) {
    if (param_1 != (KIPlayer *)0x0) {
      *(undefined4 *)(this + 0x1dc) = 0;
      this[0x1c0] = (PlayerEgo)0x1;
      *(KIPlayer **)(this + 0x1bc) = param_1;
      fVar2 = (float)PlayerAsteroid::getScaling((PlayerAsteroid *)param_1);
      *(int *)(this + 0x1d8) = (int)(fVar2 * 2500.0);
      this[0x145] = (PlayerEgo)0x1;
      *(undefined4 *)(this + 0x1c4) = 0;
    }
  }
  else {
    PlayerAsteroid::setRotationEnabled(*(PlayerAsteroid **)(this + 0x1bc),true);
    this[0x1c0] = (PlayerEgo)0x0;
    this[0x145] = (PlayerEgo)0x0;
    *(undefined4 *)(this + 0x1bc) = 0;
    local_24 = 0;
    uStack_20 = 0;
    local_1c = 0;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x1c8),(Vector *)&local_24);
    TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x88),true);
    Player::resetGunDelay(*(Player **)this,0);
    if (*(MiningGame **)(this + 0x1e4) != (MiningGame *)0x0) {
      pvVar1 = (void *)MiningGame::~MiningGame(*(MiningGame **)(this + 0x1e4));
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 0x1e4) = 0;
    Radar::unlockAsteroid(param_2);
    *(undefined4 *)(this + 0x1c4) = 0;
    setExhaustVisible(this,true);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::approachAsteroid  @0x000aba90  (1128 bytes)
/* PlayerEgo::approachAsteroid(Hud*, int, Radar*) */

void PlayerEgo::approachAsteroid(Hud *param_1,int param_2,Radar *param_3)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  float fVar4;
  Ship *pSVar5;
  MiningGame *this;
  undefined4 *puVar6;
  Vector *pVVar7;
  uint in_fpscr;
  float fVar8;
  float extraout_s1;
  float fVar9;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_88 [5];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  Vector aVStack_4c [12];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar3 = KIPlayer::isDying(*(KIPlayer **)(param_1 + 0x1bc));
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x1c4) == 1) {
      fVar4 = *(float *)(param_1 + 0x1dc);
      uVar1 = in_fpscr & 0xfffffff | (uint)(fVar4 < -1024.0) << 0x1f |
              (uint)(fVar4 == -1024.0) << 0x1e;
      bVar2 = (byte)(uVar1 >> 0x18);
      if ((bool)(bVar2 >> 6 & 1) || (bool)(bVar2 >> 7) != NAN(fVar4)) {
        if (*(MiningGame **)(param_1 + 0x1e4) == (MiningGame *)0x0) {
          param_1[0x39b] = (Hud)0x0;
          param_1[0x2f5] = (Hud)0x0;
          Globals::hints[0x37] = 0;
          this = operator_new(0xd4);
          iVar3 = PlayerAsteroid::getQuality(*(PlayerAsteroid **)(param_1 + 0x1bc));
          fVar4 = (float)MiningGame::MiningGame
                                   (this,iVar3,*(int *)(*(int *)(param_1 + 0x1bc) + 0x124),
                                    (Hud *)param_2);
          *(MiningGame **)(param_1 + 0x1e4) = this;
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1bc) + 4) + 0x40) = 0;
          FModSound::play(Globals::sound,1,(Vector *)0x0,(Vector *)0x0,fVar4);
          FModSound::pause(Globals::sound,*(int *)(param_1 + 0x1c));
        }
        else {
          iVar3 = MiningGame::update(*(MiningGame **)(param_1 + 0x1e4),*(int *)(param_1 + 0x134));
          if (iVar3 == 0) {
            iVar3 = MiningGame::gameLost(*(MiningGame **)(param_1 + 0x1e4));
            if ((iVar3 == 0) &&
               (iVar3 = MiningGame::getOreAmount(*(MiningGame **)(param_1 + 0x1e4)), 0 < iVar3)) {
              stopMining((PlayerEgo *)param_1);
            }
            else {
              iVar3 = MiningGame::gameLost(*(MiningGame **)(param_1 + 0x1e4));
              if (iVar3 == 1) {
                param_1[0x39b] = (Hud)0x1;
                *(undefined4 *)(Globals::status + 0x124) = 0;
                stopMining((PlayerEgo *)param_1);
                Hud::hudEvent(param_2,(PlayerEgo *)0x8,(int)param_1);
              }
            }
          }
          else {
            iVar3 = KIPlayer::isDying(*(KIPlayer **)(param_1 + 0x1bc));
            if ((iVar3 != 0) ||
               (iVar3 = KIPlayer::isDead(*(KIPlayer **)(param_1 + 0x1bc)), iVar3 == 1)) {
              *(undefined4 *)(Globals::status + 0x124) = 0;
              stopMining((PlayerEgo *)param_1);
              Hud::hudEvent(param_2,(PlayerEgo *)0x8,(int)param_1);
            }
          }
        }
      }
      else {
        fVar9 = (float)VectorSignedToFloat(-*(int *)(param_1 + 0x134) >> 1,(byte)(uVar1 >> 0x16) & 3
                                          );
        *(float *)(param_1 + 0x1dc) = fVar4 + fVar9;
      }
    }
    else if (*(int *)(param_1 + 0x1c4) == 0) {
      if (param_1[0x1a0] != (Hud)0x0) {
        setTurretMode((PlayerEgo *)param_1,false);
      }
      (**(code **)(**(int **)(param_1 + 0x1bc) + 0x28))((Vector *)local_88);
      pVVar7 = (Vector *)(param_1 + 0xec);
      AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)local_88);
      AEGeometry::getPosition();
      AbyssEngine::AEMath::Vector::operator-=(pVVar7,(Vector *)local_88);
      fVar4 = (float)AbyssEngine::AEMath::VectorLength(pVVar7);
      if ((int)fVar4 < *(int *)(param_1 + 0x1d8)) {
        if (param_1[0x1d4] != (Hud)0x0) {
          if ((*(PlayerAsteroid **)(param_1 + 0x1bc))[0x38] != (PlayerAsteroid)0x0) {
            PlayerAsteroid::setRotationEnabled(*(PlayerAsteroid **)(param_1 + 0x1bc),false);
          }
          *(undefined4 *)(param_1 + 0x1c4) = 1;
        }
      }
      else {
        AEGeometry::getPosition();
        pSVar5 = (Ship *)Status::getShip(Globals::status);
        fVar9 = (float)Ship::getHandling(pSVar5);
        fVar8 = 4.0;
        in_fpscr = in_fpscr & 0xfffffff;
        if (fVar9 + 2.7 < 4.0) {
          pSVar5 = (Ship *)Status::getShip(Globals::status);
          fVar8 = (float)Ship::getHandling(pSVar5);
          fVar8 = fVar8 + 2.7;
        }
        moveToPosition(param_1,local_40,uStack_3c,uStack_38,1,fVar8);
        (**(code **)(**(int **)(param_1 + 0x1bc) + 0x28))((Vector *)local_88);
        AEGeometry::getPosition();
        AbyssEngine::AEMath::operator-((AEMath *)&local_c8,(Vector *)local_88,aVStack_4c);
        fVar9 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_c8);
        if ((int)fVar9 < 20000) {
          param_1[0x330] = (Hud)0x1;
        }
      }
      if ((int)fVar4 < *(int *)(param_1 + 0x1d8) + 2000) {
        *(undefined4 *)(param_1 + 0xbc) = 0x3f800000;
        if (param_1[0x2f5] == (Hud)0x0) {
          fVar4 = (float)setExhaustVisible((PlayerEgo *)param_1,false);
          FModSound::play(Globals::sound,2,(Vector *)0x0,(Vector *)0x0,fVar4);
          *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0xcc) - *(int *)(param_1 + 0xcc) / 6;
          TargetFollowCamera::setActive(*(TargetFollowCamera **)(param_1 + 0x88),false);
          AEGeometry::getUpVector();
          pVVar7 = (Vector *)(param_1 + 0x1c8);
          AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)local_88);
          AbyssEngine::AEMath::VectorNormalize((AEMath *)local_88,pVVar7);
          AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)local_88);
          param_1[0x2f5] = (Hud)0x1;
        }
        AEGeometry::getDirection();
        pVVar7 = (Vector *)(param_1 + 0xe0);
        AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)local_88);
        AbyssEngine::AEMath::VectorNormalize((AEMath *)local_88,pVVar7);
        AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)local_88);
        fVar4 = (float)AbyssEngine::AEMath::VectorDot(pVVar7,(Vector *)(param_1 + 0x1c8));
        fVar4 = (float)AbyssEngine::AEMath::ACosf(fVar4);
        if (0.2 < fVar4) {
          fVar4 = *(float *)(param_1 + 0x1dc);
          uVar1 = in_fpscr & 0xfffffff | (uint)(fVar4 < -1024.0) << 0x1f |
                  (uint)(fVar4 == -1024.0) << 0x1e;
          bVar2 = (byte)(uVar1 >> 0x18);
          if (!(bool)(bVar2 >> 6 & 1) && (bool)(bVar2 >> 7) == NAN(fVar4)) {
            uStack_6c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
            uStack_68 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
            uStack_64 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
            fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x134),
                                               (byte)(uVar1 >> 0x16) & 3);
            puVar6 = (undefined4 *)((uint)local_88 | 4);
            fVar4 = fVar4 + fVar9 * -0.35;
            *(float *)(param_1 + 0x1dc) = fVar4;
            local_88[0] = 0x3f800000;
            *puVar6 = 0;
            puVar6[1] = uStack_6c;
            puVar6[2] = uStack_68;
            puVar6[3] = uStack_64;
            local_74 = 0x3f800000;
            local_70 = 0;
            local_60 = 0x3f800000;
            uStack_58 = 0x3f8000003f800000;
            local_50 = 0x3f800000;
            AbyssEngine::AEMath::MatrixSetRotation
                      ((Matrix *)&local_c8,fVar4,extraout_s1,fVar4 * 1.5258789e-05 * 6.2831855);
            puVar6 = (undefined4 *)
                     AbyssEngine::PaintCanvas::TransformGetLocal
                               (Globals::Canvas,*(uint *)(*(int *)(param_1 + 4) + 0xc));
            local_c8 = *puVar6;
            uStack_c4 = puVar6[1];
            uStack_c0 = puVar6[2];
            uStack_bc = puVar6[3];
            uStack_b8 = puVar6[4];
            local_b4 = puVar6[5];
            uStack_b0 = puVar6[6];
            uStack_ac = puVar6[7];
            uStack_a8 = puVar6[8];
            uStack_a4 = puVar6[9];
            local_a0 = puVar6[10];
            uStack_9c = puVar6[0xb];
            uStack_98 = puVar6[0xc];
            uStack_94 = puVar6[0xd];
            uStack_90 = puVar6[0xe];
            AbyssEngine::AEMath::Matrix::operator*=((Matrix *)&local_c8,(AEMath *)local_88);
            AEGeometry::setMatrix(*(Matrix **)(param_1 + 4));
            goto LAB_000abc8c;
          }
        }
        param_1[0x2f5] = (Hud)0x0;
        param_1[0x2f4] = (Hud)0x0;
        param_1[0x1d4] = (Hud)0x1;
      }
    }
  }
LAB_000abc8c:
  if (__stack_chk_guard - local_34 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_34);
}

// ===== PlayerEgo::dockToDockingPoint  @0x000abf60  (714 bytes)
/* PlayerEgo::dockToDockingPoint(KIPlayer*, Radar*) */

void PlayerEgo::dockToDockingPoint(KIPlayer *param_1,Radar *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  EaseInOutMatrix *pEVar3;
  SpacePoint *this;
  void *pvVar4;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_a4 [60];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar1 = Player::getHitpoints(*(Player **)param_1);
  if (iVar1 < 1) goto LAB_000ac212;
  if (param_1[0x356] == (KIPlayer)0x0) {
    if (param_2 != (Radar *)0x0) {
      *(undefined4 *)(param_1 + 0x1dc) = 0;
      param_1[0x356] = (KIPlayer)0x1;
      *(Radar **)(param_1 + 0x1bc) = param_2;
      *(undefined4 *)(param_1 + 0x1d8) = 0x578;
      param_1[0x145] = (KIPlayer)0x1;
      *(undefined4 *)(param_1 + 0x1c4) = 0;
    }
    goto LAB_000ac212;
  }
  if (param_2 == (Radar *)0x0) {
LAB_000ac18e:
    PlayEngineSound((PlayerEgo *)param_1);
    param_1[0x1a1] = (KIPlayer)0x0;
    param_1[0x356] = (KIPlayer)0x0;
    param_1[0x145] = (KIPlayer)0x0;
    *(undefined4 *)(param_1 + 0x1bc) = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
    AbyssEngine::AEMath::Vector::operator=((Vector *)(param_1 + 0x1c8),(Vector *)&local_68);
    TargetFollowCamera::setActive(*(TargetFollowCamera **)(param_1 + 0x88),true);
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(param_1 + 0x88),false);
    TargetFollowCamera::useTargetsUpVector(*(TargetFollowCamera **)(param_1 + 0x88),false);
    Player::resetGunDelay(*(Player **)param_1,0);
    *(undefined4 *)(param_1 + 0x1c4) = 0;
    setExhaustVisible((PlayerEgo *)param_1,true);
    this = *(SpacePoint **)(param_1 + 0x36c);
    if (this != (SpacePoint *)0x0) {
      SpacePoint::giveFree(this);
      *(undefined4 *)(param_1 + 0x36c) = 0;
    }
  }
  else {
    AEGeometry::getPosition();
    iVar1 = KIPlayer::getNearestNavigationPoint
                      ((KIPlayer *)param_2,(Vector *)&local_68,*(SpacePoint **)(param_1 + 0x36c));
    if (iVar1 == 0) {
      if (param_2[0x6c] != (Radar)0x0) {
        param_2[0x88] = (Radar)0x1;
      }
      goto LAB_000ac18e;
    }
    if (param_2[0x6c] != (Radar)0x0) {
      param_2[0x88] = (Radar)0x1;
    }
    setTurretMode((PlayerEgo *)param_1,false);
    param_1[0x1a1] = (KIPlayer)0x0;
    AbyssEngine::PaintCanvas::CameraSetCurrent(Globals::Canvas);
    LevelScript::resetCamera(*(LevelScript **)(param_1 + 0x10),*(Level **)(param_1 + 0xc));
    PlayEngineSound((PlayerEgo *)param_1);
    *(undefined4 *)(param_1 + 0x1c4) = 3;
    TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(param_1 + 0x88),true);
    TargetFollowCamera::useTargetsUpVector(*(TargetFollowCamera **)(param_1 + 0x88),false);
    pvVar4 = *(void **)(param_1 + 0x358);
    if (pvVar4 != (void *)0x0) {
      AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar4 + 0x58));
      AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar4 + 0x3c));
      operator_delete(pvVar4);
    }
    *(undefined4 *)(param_1 + 0x358) = 0;
    AEGeometry::getPosition();
    iVar1 = KIPlayer::getNearestNavigationPoint
                      ((KIPlayer *)param_2,(Vector *)&local_68,*(SpacePoint **)(param_1 + 0x36c));
    puVar2 = (undefined4 *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 8));
    local_68 = *puVar2;
    local_64 = puVar2[1];
    local_60 = puVar2[2];
    local_5c = puVar2[3];
    local_58 = puVar2[4];
    local_54 = puVar2[5];
    local_50 = puVar2[6];
    uStack_4c = puVar2[7];
    local_48 = puVar2[8];
    uStack_44 = puVar2[9];
    local_40 = puVar2[10];
    uStack_3c = puVar2[0xb];
    local_38 = puVar2[0xc];
    uStack_34 = puVar2[0xd];
    uStack_30 = puVar2[0xe];
    AbyssEngine::AEMath::MatrixSetTranslation
              (aAStack_a4,(Vector *)&local_68,*(float *)(iVar1 + 8),extraout_s1,extraout_s2);
    pEVar3 = operator_new(0xf4);
    puVar2 = (undefined4 *)AEGeometry::getMatrix(*(AEGeometry **)(param_1 + 8));
    AbyssEngine::EaseInOutMatrix::EaseInOutMatrix
              (pEVar3,*puVar2,puVar2[1],puVar2[2],puVar2[3],puVar2[4],puVar2[5],puVar2[6],puVar2[7],
               puVar2[8],puVar2[9],puVar2[10],puVar2[0xb],puVar2[0xc],puVar2[0xd],puVar2[0xe],
               local_68,local_64,local_60,local_5c,local_58,local_54,local_50,uStack_4c,local_48,
               uStack_44,local_40,uStack_3c,local_38,uStack_34,uStack_30,3000);
    *(EaseInOutMatrix **)(param_1 + 0x358) = pEVar3;
    setExhaustVisible((PlayerEgo *)param_1,true);
  }
  if (*(HackingGame **)(param_1 + 0x1e8) != (HackingGame *)0x0) {
    pvVar4 = (void *)HackingGame::~HackingGame(*(HackingGame **)(param_1 + 0x1e8));
    operator_delete(pvVar4);
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    Hud::setHackingGameActive(*(Hud **)(param_1 + 0x220),false);
  }
LAB_000ac212:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerEgo::approachDockingPoint  @0x000ac250  (2592 bytes)
/* PlayerEgo::approachDockingPoint(Hud*, int, Radar*) */

void __thiscall
PlayerEgo::approachDockingPoint(PlayerEgo *this,Hud *param_1,int param_2,Radar *param_3)

{
  int iVar1;
  SpacePoint *this_00;
  SpacePoint *this_01;
  EaseInOutMatrix *pEVar2;
  Ship *pSVar3;
  Mission *this_02;
  Mission *this_03;
  Item *pIVar4;
  undefined4 uVar5;
  int iVar6;
  Vector *pVVar7;
  Matrix *pMVar8;
  float fVar9;
  void *pvVar10;
  float fVar11;
  undefined4 *puVar12;
  PlayerEgo *pPVar13;
  int iVar14;
  KIPlayer *pKVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  uint in_fpscr;
  float fVar18;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined4 local_c0;
  Vector aVStack_bc [12];
  AEMath aAStack_b0 [12];
  Vector aVStack_a4 [12];
  AEMath aAStack_98 [12];
  AEMath aAStack_8c [12];
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  AEMath aAStack_40 [12];
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar1 = KIPlayer::isDying(*(KIPlayer **)(this + 0x1bc));
  if (iVar1 != 0) goto switchD_000ac28a_caseD_1;
  switch(*(undefined4 *)(this + 0x1c4)) {
  case 0:
    pKVar15 = *(KIPlayer **)(this + 0x1bc);
    AEGeometry::getPosition();
    this_00 = (SpacePoint *)
              KIPlayer::getNearestNavigationPoint
                        (pKVar15,(Vector *)&local_80,*(SpacePoint **)(this + 0x36c));
    if (this_00 != (SpacePoint *)0x0) {
      this_01 = *(SpacePoint **)(this + 0x36c);
      if (this_01 != this_00) {
        if (this_01 != (SpacePoint *)0x0) {
          SpacePoint::giveFree(this_01);
        }
        *(SpacePoint **)(this + 0x36c) = this_00;
        SpacePoint::take(this_00);
      }
      (**(code **)(**(int **)(this + 0x1bc) + 0x28))((Vector *)&local_f8);
      pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
      AbyssEngine::AEMath::MatrixRotateVector(aAStack_40,pMVar8,(Vector *)this_00);
      AbyssEngine::AEMath::operator+((AEMath *)&local_80,(Vector *)&local_f8,(Vector *)aAStack_40);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xec),(Vector *)&local_80);
      AEGeometry::getPosition();
      AbyssEngine::AEMath::operator-
                ((AEMath *)&local_80,(Vector *)(this + 0xec),(Vector *)&local_f8);
      fVar9 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_80);
      if ((int)fVar9 < *(int *)(this + 0x1d8)) {
        if (*(char *)(*(int *)(this + 0x1bc) + 0x6c) != '\0') {
          *(undefined1 *)(*(int *)(this + 0x1bc) + 0x88) = 0;
        }
        *(undefined4 *)(this + 0x1c4) = 2;
        TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x88),true);
        TargetFollowCamera::useTargetsUpVector(*(TargetFollowCamera **)(this + 0x88),false);
        pvVar10 = *(void **)(this + 0x358);
        if (pvVar10 != (void *)0x0) {
          AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar10 + 0x58));
          AbyssEngine::Quaternion::~Quaternion((Quaternion *)((int)pvVar10 + 0x3c));
          operator_delete(pvVar10);
        }
        *(undefined4 *)(this + 0x358) = 0;
        pKVar15 = *(KIPlayer **)(this + 0x1bc);
        (**(code **)(*(int *)pKVar15 + 0x28))((Vector *)&local_f8,pKVar15);
        pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
        AbyssEngine::AEMath::MatrixRotateVector(aAStack_40,pMVar8,*(Vector **)(this + 0x36c));
        AbyssEngine::AEMath::operator+((AEMath *)&local_80,(Vector *)&local_f8,(Vector *)aAStack_40)
        ;
        pVVar7 = (Vector *)KIPlayer::getNearestDockingPoint(pKVar15,(Vector *)&local_80);
        pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
        AbyssEngine::AEMath::MatrixRotateVector((AEMath *)&local_80,pMVar8,pVVar7 + 0xc);
        AbyssEngine::AEMath::VectorNormalize(aAStack_40,(Vector *)&local_80);
        pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_f8,pMVar8,*(Vector **)(this + 0x36c));
        pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
        AbyssEngine::AEMath::MatrixRotateVector(aAStack_98,pMVar8,pVVar7);
        AbyssEngine::AEMath::operator-((AEMath *)&local_80,(Vector *)&local_f8,(Vector *)aAStack_98)
        ;
        AbyssEngine::AEMath::VectorNormalize(aAStack_8c,(Vector *)&local_80);
        AbyssEngine::AEMath::VectorCross
                  ((AEMath *)&local_80,(Vector *)aAStack_8c,(Vector *)aAStack_40);
        AbyssEngine::AEMath::VectorNormalize(aAStack_98,(Vector *)&local_80);
        uStack_64 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        local_60 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_5c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        puVar12 = (undefined4 *)((uint)&local_80 | 4);
        local_80 = 0x3f800000;
        *puVar12 = 0;
        puVar12[1] = uStack_64;
        puVar12[2] = local_60;
        puVar12[3] = uStack_5c;
        local_6c = 0x3f800000;
        local_68 = 0;
        local_58 = 0x3f800000;
        local_50 = 0x3f8000003f800000;
        local_48 = 0x3f800000;
        AbyssEngine::AEMath::MatrixSetRotation
                  ((AEMath *)&local_f8,(AEMath *)&local_80,(Vector *)aAStack_98,(Vector *)aAStack_8c
                   ,(Vector *)aAStack_40);
        pEVar2 = operator_new(0xf4);
        puVar12 = (undefined4 *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
        fVar9 = (float)AbyssEngine::EaseInOutMatrix::EaseInOutMatrix
                                 (pEVar2,*puVar12,puVar12[1],puVar12[2],puVar12[3],puVar12[4],
                                  puVar12[5],puVar12[6],puVar12[7],puVar12[8],puVar12[9],puVar12[10]
                                  ,puVar12[0xb],puVar12[0xc],puVar12[0xd],puVar12[0xe],local_80,
                                  local_7c,local_78,local_74,local_70,local_6c,local_68,uStack_64,
                                  local_60,uStack_5c,(undefined4)local_58,local_58._4_4_,
                                  (undefined4)local_50,local_50._4_4_,local_48,2000);
        *(EaseInOutMatrix **)(this + 0x358) = pEVar2;
        FModSound::play(Globals::sound,0x8de,(Vector *)0x0,(Vector *)0x0,fVar9);
        local_f8 = 0;
        uStack_f4 = 0;
        local_f0 = 0;
        Player::getPosition();
        FModSound::updateEvent3DAttributes
                  (Globals::sound,0x8de,aVStack_a4,(Vector *)&local_f8,false);
        StopEngineSound(this);
      }
      else {
        uVar16 = *(undefined4 *)(this + 0xec);
        uVar17 = *(undefined4 *)(this + 0xf0);
        uVar5 = *(undefined4 *)(this + 0xf4);
        pSVar3 = (Ship *)Status::getShip(Globals::status);
        fVar11 = (float)Ship::getHandling(pSVar3);
        fVar18 = 4.0;
        if ((int)((uint)(fVar11 + 2.7 < 4.0) << 0x1f) < 0) {
          pSVar3 = (Ship *)Status::getShip(Globals::status);
          fVar18 = (float)Ship::getHandling(pSVar3);
          fVar18 = fVar18 + 2.7;
        }
        moveToPosition(this,uVar16,uVar17,uVar5,1,fVar18);
        if ((int)fVar9 < 20000) {
          this[0x330] = (PlayerEgo)0x1;
        }
      }
    }
  default:
    goto switchD_000ac28a_caseD_1;
  case 2:
    this[0x330] = (PlayerEgo)0x1;
    if (this[0x1a0] != (PlayerEgo)0x0) {
      setTurretMode(this,false);
    }
    pKVar15 = *(KIPlayer **)(this + 0x1bc);
    (**(code **)(*(int *)pKVar15 + 0x28))((Vector *)&local_f8,pKVar15);
    pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
    AbyssEngine::AEMath::MatrixRotateVector(aAStack_40,pMVar8,*(Vector **)(this + 0x36c));
    AbyssEngine::AEMath::operator+((AEMath *)&local_80,(Vector *)&local_f8,(Vector *)aAStack_40);
    pVVar7 = (Vector *)KIPlayer::getNearestDockingPoint(pKVar15,(Vector *)&local_80);
    (**(code **)(**(int **)(this + 0x1bc) + 0x28))((Vector *)&local_f8);
    pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
    AbyssEngine::AEMath::MatrixRotateVector(aAStack_40,pMVar8,pVVar7);
    AbyssEngine::AEMath::operator+((AEMath *)&local_80,(Vector *)&local_f8,(Vector *)aAStack_40);
    pVVar7 = (Vector *)(this + 0xec);
    AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)&local_80);
    AEGeometry::getPosition();
    AbyssEngine::AEMath::operator-((AEMath *)&local_80,pVVar7,(Vector *)&local_f8);
    fVar9 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_80);
    pSVar3 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Ship::getIndex(pSVar3);
    if ((int)fVar9 < *(int *)(&DAT_00252204 + iVar1 * 4)) {
      this_02 = (Mission *)Status::getMission(Globals::status);
      this_03 = (Mission *)Status::getCampaignMission(Globals::status);
      iVar1 = Mission::isEmpty(this_02);
      if (((iVar1 == 0) && (iVar1 = Mission::getType(this_02), iVar1 == 0xf)) &&
         (iVar1 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc)),
         iVar1 == 1)) {
        pSVar3 = (Ship *)Status::getShip(Globals::status);
        iVar1 = Mission::getProductionGoodIndex(this_02);
        iVar1 = Ship::hasCargo(pSVar3,iVar1,1);
        if (iVar1 == 1) {
          pSVar3 = (Ship *)Status::getShip(Globals::status);
          iVar1 = Mission::getProductionGoodIndex(this_02);
          pIVar4 = (Item *)Ship::getCargo(pSVar3,iVar1);
          uVar5 = Item::getAmount(pIVar4);
          *(undefined4 *)(this + 0x360) = uVar5;
          iVar6 = Mission::getProductionGoodAmount(this_02);
          iVar1 = Level::getNumDeliveredOre(*(Level **)(this + 0xc));
LAB_000acbb6:
          iVar6 = iVar6 - iVar1;
          iVar1 = *(int *)(this + 0x360);
          if (iVar6 < *(int *)(this + 0x360)) {
            *(int *)(this + 0x360) = iVar6;
            iVar1 = iVar6;
          }
          *(undefined4 *)(this + 0x35c) = 0;
          *(undefined4 *)(this + 0x364) = 0;
          if (0 < iVar1) {
            pPVar13 = (PlayerEgo *)0x29;
            goto LAB_000acc56;
          }
        }
      }
      else {
        iVar1 = Mission::isEmpty(this_02);
        if (((iVar1 != 0) ||
            ((iVar1 = Mission::getType(this_02), iVar1 != 0xb8 &&
             (iVar1 = Mission::getType(this_02), iVar1 != 0xa8)))) ||
           (iVar1 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc)),
           iVar1 != 2)) {
          iVar1 = Mission::isEmpty(this_02);
          if (((iVar1 == 0) && (iVar1 = Mission::getType(this_02), iVar1 == 0xb8)) &&
             (iVar1 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc)),
             iVar1 == 1)) {
            iVar1 = *(int *)(Globals::status + 0x174);
            if (0 < iVar1) {
              *(undefined4 *)(this + 0x35c) = 0;
              *(int *)(this + 0x360) = iVar1;
              *(undefined4 *)(this + 0x364) = 0;
              pPVar13 = (PlayerEgo *)0x25;
              goto LAB_000acc56;
            }
          }
          else if ((((this_03 != (Mission *)0x0) && (iVar1 = Mission::isEmpty(this_03), iVar1 == 0))
                   && ((iVar1 = Mission::getType(this_03), iVar1 == 0xa7 ||
                       (iVar1 = Mission::getType(this_03), iVar1 == 0xae)))) &&
                  (iVar1 = PlayerFixedObject::getDockingType(*(PlayerFixedObject **)(this + 0x1bc)),
                  iVar1 == 1)) {
            pSVar3 = (Ship *)Status::getShip(Globals::status);
            iVar1 = Mission::getProductionGoodIndex(this_03);
            iVar1 = Ship::hasCargo(pSVar3,iVar1,1);
            if (iVar1 == 1) {
              pSVar3 = (Ship *)Status::getShip(Globals::status);
              iVar1 = Mission::getProductionGoodIndex(this_03);
              pIVar4 = (Item *)Ship::getCargo(pSVar3,iVar1);
              uVar5 = Item::getAmount(pIVar4);
              *(undefined4 *)(this + 0x360) = uVar5;
              iVar6 = Mission::getProductionGoodAmount(this_03);
              iVar1 = Mission::getStatusValue(this_03);
              goto LAB_000acbb6;
            }
          }
          goto LAB_000acc5e;
        }
        pSVar3 = (Ship *)Status::getShip(Globals::status);
        iVar1 = Ship::getMaxPassengers(pSVar3);
        if (iVar1 < 1) {
LAB_000aca34:
          iVar1 = Mission::getType(this_02);
          if (iVar1 != 0xa8) {
            pSVar3 = (Ship *)Status::getShip(Globals::status);
            iVar1 = Ship::getMaxPassengers(pSVar3);
            if (iVar1 == 0) {
              pPVar13 = (PlayerEgo *)0x2b;
              goto LAB_000acc56;
            }
            goto LAB_000acc5e;
          }
        }
        else {
          iVar6 = *(int *)(Globals::status + 0x174);
          pSVar3 = (Ship *)Status::getShip(Globals::status);
          iVar1 = Ship::getMaxPassengers(pSVar3);
          if (iVar1 <= iVar6) goto LAB_000aca34;
        }
        iVar1 = Mission::getType(this_02);
        if (iVar1 == 0xa8) {
          iVar1 = Mission::getStatusValue(this_02);
        }
        else {
          pSVar3 = (Ship *)Status::getShip(Globals::status);
          iVar1 = Ship::getMaxPassengers(pSVar3);
        }
        iVar14 = *(int *)(Globals::status + 0x174);
        *(int *)(this + 0x360) = iVar1 - iVar14;
        iVar6 = Mission::getStatusValue(this_02);
        if (iVar6 - *(int *)(Globals::status + 0x174) < iVar1 - iVar14) {
          iVar1 = Mission::getStatusValue(this_02);
          iVar1 = iVar1 - *(int *)(Globals::status + 0x174);
          *(int *)(this + 0x360) = iVar1;
        }
        else {
          iVar1 = *(int *)(this + 0x360);
        }
        *(undefined4 *)(this + 0x35c) = 0;
        *(undefined4 *)(this + 0x364) = 0;
        if (0 < iVar1) {
          pPVar13 = (PlayerEgo *)0x23;
LAB_000acc56:
          Hud::hudEvent((int)param_1,pPVar13,(int)this);
        }
      }
LAB_000acc5e:
      *(undefined4 *)(this + 0x1c4) = 1;
      if (this[0xb2] == (PlayerEgo)0x0) {
        this[0xb1] = (PlayerEgo)0x1;
      }
      this[0xb2] = (PlayerEgo)0x0;
      goto switchD_000ac28a_caseD_1;
    }
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::EaseInOutMatrix::Increase(*(EaseInOutMatrix **)(this + 0x358),fVar9);
    AbyssEngine::EaseInOutMatrix::GetValue();
    AEGeometry::getPosition();
    AEGeometry::getPosition();
    AbyssEngine::AEMath::operator-(aAStack_b0,pVVar7,aVStack_bc);
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    fVar9 = (float)AbyssEngine::AEMath::operator*((AEMath *)aVStack_a4,(Vector *)aAStack_b0,fVar9);
    AbyssEngine::AEMath::operator*(aAStack_98,aVStack_a4,fVar9);
    AbyssEngine::AEMath::operator+(aAStack_40,(Vector *)aAStack_8c,(Vector *)aAStack_98);
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_f8,(Matrix *)&local_80,(Vector *)aAStack_40);
    uStack_dc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_d8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_d4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar12 = (undefined4 *)((uint)&local_f8 | 4);
    *puVar12 = 0;
    puVar12[1] = uStack_dc;
    puVar12[2] = uStack_d8;
    puVar12[3] = uStack_d4;
    break;
  case 3:
    pKVar15 = *(KIPlayer **)(this + 0x1bc);
    AEGeometry::getPosition();
    pVVar7 = (Vector *)
             KIPlayer::getNearestNavigationPoint
                       (pKVar15,(Vector *)&local_80,*(SpacePoint **)(this + 0x36c));
    (**(code **)(**(int **)(this + 0x1bc) + 0x28))((Vector *)&local_f8);
    pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(*(int *)(this + 0x1bc) + 8));
    AbyssEngine::AEMath::MatrixRotateVector(aAStack_40,pMVar8,pVVar7);
    AbyssEngine::AEMath::operator+((AEMath *)&local_80,(Vector *)&local_f8,(Vector *)aAStack_40);
    pVVar7 = (Vector *)(this + 0xec);
    AbyssEngine::AEMath::Vector::operator=(pVVar7,(Vector *)&local_80);
    AEGeometry::getPosition();
    AbyssEngine::AEMath::operator-((AEMath *)&local_80,pVVar7,(Vector *)&local_f8);
    fVar9 = (float)AbyssEngine::AEMath::VectorLength((Vector *)&local_80);
    if ((int)fVar9 < 200) {
      this[0x356] = (PlayerEgo)0x0;
      this[0x145] = (PlayerEgo)0x0;
      *(undefined4 *)(this + 0x1bc) = 0;
      *(undefined4 *)(param_3 + 4) = 0;
      *(undefined4 *)(param_3 + 8) = 0;
      local_80 = 0;
      local_7c = 0;
      local_78 = 0;
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x1c8),(Vector *)&local_80);
      TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x88),true);
      TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x88),false);
      TargetFollowCamera::useTargetsUpVector(*(TargetFollowCamera **)(this + 0x88),false);
      LevelScript::resetCamera(*(LevelScript **)(this + 0x10),*(Level **)(this + 0xc));
      Player::resetGunDelay(*(Player **)this,0);
      this[0xb0] = (PlayerEgo)0x1;
      *(undefined4 *)(this + 0x1c4) = 0;
      if (*(SpacePoint **)(this + 0x36c) != (SpacePoint *)0x0) {
        SpacePoint::giveFree(*(SpacePoint **)(this + 0x36c));
        *(undefined4 *)(this + 0x36c) = 0;
      }
      if (*(HackingGame **)(this + 0x1e8) != (HackingGame *)0x0) {
        pvVar10 = (void *)HackingGame::~HackingGame(*(HackingGame **)(this + 0x1e8));
        operator_delete(pvVar10);
        *(undefined4 *)(this + 0x1e8) = 0;
        Hud::setHackingGameActive(param_1,false);
      }
      goto switchD_000ac28a_caseD_1;
    }
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::EaseInOutMatrix::Increase(*(EaseInOutMatrix **)(this + 0x358),fVar9);
    AbyssEngine::EaseInOutMatrix::GetValue();
    AEGeometry::getPosition();
    AEGeometry::getPosition();
    AbyssEngine::AEMath::operator-(aAStack_b0,pVVar7,aVStack_bc);
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x134),(byte)(in_fpscr >> 0x16) & 3);
    fVar9 = (float)AbyssEngine::AEMath::operator*((AEMath *)aVStack_a4,(Vector *)aAStack_b0,fVar9);
    AbyssEngine::AEMath::operator*(aAStack_98,aVStack_a4,fVar9);
    AbyssEngine::AEMath::operator+(aAStack_40,(Vector *)aAStack_8c,(Vector *)aAStack_98);
    AbyssEngine::AEMath::MatrixSetTranslation
              ((AEMath *)&local_f8,(Matrix *)&local_80,(Vector *)aAStack_40);
    uStack_dc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_d8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_d4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar12 = (undefined4 *)((uint)&local_f8 | 4);
    *puVar12 = 0;
    puVar12[1] = uStack_dc;
    puVar12[2] = uStack_d8;
    puVar12[3] = uStack_d4;
  }
  uStack_c8 = 0x3f8000003f800000;
  local_d0 = 0x3f800000;
  local_e0 = 0;
  local_e4 = 0x3f800000;
  local_f8 = 0x3f800000;
  local_c0 = 0x3f800000;
  AEGeometry::setMatrix(*(Matrix **)(this + 4));
  AEGeometry::setMatrix(*(Matrix **)(this + 8));
  iVar1 = *(int *)this;
  pMVar8 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(iVar1 + 4),pMVar8);
  AEGeometry::getPosition();
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x148),(Vector *)aAStack_40);
switchD_000ac28a_caseD_1:
  if (__stack_chk_guard - local_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_34);
  }
  return;
}

// ===== PlayerEgo::isDockingToDockingPoint  @0x000acd00  (22 bytes)
/* PlayerEgo::isDockingToDockingPoint() */

undefined4 __thiscall PlayerEgo::isDockingToDockingPoint(PlayerEgo *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this[0x356] != (PlayerEgo)0x0) && (*(int *)(this + 0x1c4) != 1)) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== PlayerEgo::isLandingOrTakingOff  @0x000acd16  (28 bytes)
/* PlayerEgo::isLandingOrTakingOff() */

bool __thiscall PlayerEgo::isLandingOrTakingOff(PlayerEgo *this)

{
  if (this[0x356] != (PlayerEgo)0x0) {
    return (*(uint *)(this + 0x1c4) | 1) == 3;
  }
  return false;
}

// ===== PlayerEgo::hitCamera  @0x000acd32  (22 bytes)
/* PlayerEgo::hitCamera() */

void __thiscall PlayerEgo::hitCamera(PlayerEgo *this)

{
  *(undefined4 *)(this + 0x328) = 0;
  this[0x32c] = (PlayerEgo)0x1;
  TargetFollowCamera::hit(*(TargetFollowCamera **)(this + 0x88));
  return;
}

// ===== PlayerEgo::right  @0x000acd48  (538 bytes)
/* PlayerEgo::right(int, float) */

void PlayerEgo::right(int param_1,float param_2)

{
  byte bVar1;
  Ship *pSVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 in_r1;
  float in_r2;
  float *pfVar5;
  uint in_fpscr;
  float fVar6;
  float extraout_s0;
  float extraout_s0_00;
  float in_s1;
  float extraout_s1;
  float extraout_s1_00;
  float fVar7;
  float extraout_s2;
  float extraout_s2_00;
  undefined8 in_d1;
  undefined4 extraout_s3;
  undefined8 uVar8;
  uint uVar9;
  undefined4 in_s7;
  undefined4 extraout_s7;
  float fVar10;
  float fVar11;
  
  if (*(MiningGame **)(param_1 + 0x1e4) != (MiningGame *)0x0) {
    MiningGame::right(*(MiningGame **)(param_1 + 0x1e4),param_2);
    return;
  }
  if (*(char *)(param_1 + 0x1a0) == '\0') {
    if (*(int *)(param_1 + 0x194) == 0) {
      if ((*(char *)(param_1 + 0x158) == '\0') &&
         ((*(char *)(param_1 + 0x356) == '\0' || (*(int *)(param_1 + 0x1c4) == 1)))) {
        *(undefined4 *)(param_1 + 0x104) = 0xffffffff;
        if (*(char *)(param_1 + 0x235) == '\0') {
          fVar7 = *(float *)(param_1 + 0x154);
          uVar3 = (undefined4)((ulonglong)in_d1 >> 0x20);
          fVar6 = fVar7;
        }
        else {
          pSVar2 = (Ship *)Status::getShip(Globals::status);
          uVar3 = Ship::getCurrentLoad(pSVar2);
          fVar11 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
          pSVar2 = (Ship *)Status::getShip(Globals::status);
          uVar3 = Ship::getMaxLoad(pSVar2);
          fVar6 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
          fVar7 = *(float *)(param_1 + 0x154);
          in_s7 = extraout_s7;
          fVar6 = fVar7 * 0.6 + fVar7 * (1.0 - fVar11 / fVar6) * 0.4;
          uVar3 = extraout_s3;
        }
        uVar9 = (uint)(in_r2 * -750.0 * fVar6);
        iVar4 = (int)((longlong)(int)uVar9 * -0x7df7df7d + ((ulonglong)uVar9 << 0x20) >> 0x20);
        fVar11 = (float)VectorSignedToFloat((iVar4 >> 5) - (iVar4 >> 0x1f),
                                            (byte)(in_fpscr >> 0x16) & 3);
        *(float *)(param_1 + 0x25c) = -fVar7;
        *(float *)(param_1 + 0x268) = in_r2;
        fVar7 = *(float *)(param_1 + 0x27c);
        uVar9 = in_fpscr & 0xfffffff | (uint)(fVar7 < fVar11) << 0x1f |
                (uint)(fVar7 == fVar11) << 0x1e;
        bVar1 = (byte)(uVar9 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == (NAN(fVar7) || NAN(fVar11))) {
          if (Globals::mouseCursorActivated == 0) {
            pfVar5 = (float *)(Globals::options + 0x18);
            if (Globals::options[0x11] != '\0') {
              pfVar5 = (float *)(Globals::options + 0x14);
            }
            fVar10 = (float)VectorSignedToFloat(in_r1,(byte)(uVar9 >> 0x16) & 3);
            fVar6 = (fVar10 * fVar6) / ((3.3 - *pfVar5) * 20.0);
          }
          else {
            uVar8 = FloatVectorMin(CONCAT44(uVar3,(fVar6 * 25.0) / 5.999999),
                                   CONCAT44(in_s7,0x438c0000),2,0x20);
            fVar6 = (float)uVar8;
          }
          fVar10 = fVar7 - fVar6;
          if ((int)((uint)(fVar7 - fVar6 < fVar11) << 0x1f) < 0) {
            fVar10 = fVar11;
          }
          *(float *)(param_1 + 0x27c) = fVar10;
        }
      }
    }
    else {
      fVar6 = (float)VectorSignedToFloat(in_r1,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x80) = in_r2 * -0.003 * *(float *)(*(int *)(param_1 + 0x194) + 0x50);
      *(float *)(param_1 + 0x198) = fVar6 * in_r2 * 0.01 + *(float *)(param_1 + 0x198);
    }
    return;
  }
  fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x1f8),(byte)(in_fpscr >> 0x16) & 3);
  fVar7 = (float)VectorSignedToFloat(in_r1,(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x178),
                     ((fVar7 * in_r2) / (200.0 / fVar6)) * 0.00024414062 * -6.2831855,in_s1,
                     -6.2831855);
  AEGeometry::rotate(*(AEGeometry **)(param_1 + 0xdc),extraout_s0,extraout_s1,extraout_s2);
  AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x28),extraout_s0_00,extraout_s1_00,extraout_s2_00);
  return;
}

// ===== PlayerEgo::left  @0x000acf98  (534 bytes)
/* PlayerEgo::left(int, float) */

void PlayerEgo::left(int param_1,float param_2)

{
  Ship *pSVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_r1;
  float in_r2;
  float *pfVar4;
  uint in_fpscr;
  float fVar5;
  float extraout_s0;
  float extraout_s0_00;
  uint uVar6;
  float in_s1;
  float extraout_s1;
  float extraout_s1_00;
  float fVar7;
  float extraout_s2;
  float extraout_s2_00;
  undefined8 in_d1;
  undefined4 extraout_s3;
  undefined8 uVar8;
  undefined4 in_s7;
  undefined4 extraout_s7;
  float fVar9;
  
  if (*(MiningGame **)(param_1 + 0x1e4) != (MiningGame *)0x0) {
    MiningGame::left(*(MiningGame **)(param_1 + 0x1e4),param_2);
    return;
  }
  if (*(char *)(param_1 + 0x1a0) == '\0') {
    if (*(int *)(param_1 + 0x194) == 0) {
      if ((*(char *)(param_1 + 0x158) == '\0') &&
         ((*(char *)(param_1 + 0x356) == '\0' || (*(int *)(param_1 + 0x1c4) == 1)))) {
        *(undefined4 *)(param_1 + 0x104) = 1;
        if (*(char *)(param_1 + 0x235) == '\0') {
          uVar2 = (undefined4)((ulonglong)in_d1 >> 0x20);
          fVar5 = *(float *)(param_1 + 0x154);
        }
        else {
          pSVar1 = (Ship *)Status::getShip(Globals::status);
          uVar2 = Ship::getCurrentLoad(pSVar1);
          fVar7 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
          pSVar1 = (Ship *)Status::getShip(Globals::status);
          uVar2 = Ship::getMaxLoad(pSVar1);
          fVar5 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
          fVar5 = *(float *)(param_1 + 0x154) * 0.6 +
                  *(float *)(param_1 + 0x154) * (1.0 - fVar7 / fVar5) * 0.4;
          in_s7 = extraout_s7;
          uVar2 = extraout_s3;
        }
        uVar6 = (uint)(in_r2 * 750.0 * fVar5);
        iVar3 = (int)((longlong)(int)uVar6 * -0x7df7df7d + ((ulonglong)uVar6 << 0x20) >> 0x20);
        fVar7 = (float)VectorSignedToFloat((iVar3 >> 5) - (iVar3 >> 0x1f),
                                           (byte)(in_fpscr >> 0x16) & 3);
        *(float *)(param_1 + 0x25c) = fVar5;
        *(float *)(param_1 + 0x268) = -in_r2;
        if (*(float *)(param_1 + 0x27c) < fVar7) {
          if (Globals::mouseCursorActivated == 0) {
            pfVar4 = (float *)(Globals::options + 0x18);
            if (Globals::options[0x11] != '\0') {
              pfVar4 = (float *)(Globals::options + 0x14);
            }
            fVar9 = (float)VectorSignedToFloat(in_r1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
            fVar5 = (fVar9 * fVar5) / ((3.3 - *pfVar4) * 20.0);
          }
          else {
            uVar8 = FloatVectorMin(CONCAT44(uVar2,(fVar5 * 25.0) / 5.999999),
                                   CONCAT44(in_s7,0x438c0000),2,0x20);
            fVar5 = (float)uVar8;
          }
          fVar5 = *(float *)(param_1 + 0x27c) + fVar5;
          if (fVar7 < fVar5) {
            fVar5 = fVar7;
          }
          *(float *)(param_1 + 0x27c) = fVar5;
        }
      }
    }
    else {
      fVar5 = (float)VectorSignedToFloat(in_r1,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(param_1 + 0x80) = in_r2 * 0.003 * *(float *)(*(int *)(param_1 + 0x194) + 0x50);
      *(float *)(param_1 + 0x198) = *(float *)(param_1 + 0x198) + fVar5 * in_r2 * -0.01;
    }
    return;
  }
  fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x1f8),(byte)(in_fpscr >> 0x16) & 3);
  fVar7 = (float)VectorSignedToFloat(in_r1,(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x178),
                     ((fVar7 * in_r2) / (200.0 / fVar5)) * 0.00024414062 * 6.2831855,in_s1,6.2831855
                    );
  AEGeometry::rotate(*(AEGeometry **)(param_1 + 0xdc),extraout_s0,extraout_s1,extraout_s2);
  AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x28),extraout_s0_00,extraout_s1_00,extraout_s2_00);
  return;
}

// ===== PlayerEgo::down  @0x000ad1e4  (584 bytes)
/* PlayerEgo::down(int, float) */

void PlayerEgo::down(int param_1,float param_2)

{
  Ship *pSVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 in_r1;
  float in_r2;
  uint in_fpscr;
  float fVar4;
  float in_s1;
  float extraout_s1;
  float fVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  
  if (*(MiningGame **)(param_1 + 0x1e4) != (MiningGame *)0x0) {
    if (Globals::options[0x10] == '\0') {
      (*(code *)&LAB_0006b6c0)();
      return;
    }
    MiningGame::down(*(MiningGame **)(param_1 + 0x1e4),param_2);
    return;
  }
  if (*(char *)(param_1 + 0x1a0) == '\0') {
    if (*(int *)(param_1 + 0x194) == 0) {
      if ((*(char *)(param_1 + 0x158) == '\0') &&
         ((*(char *)(param_1 + 0x356) == '\0' || (*(int *)(param_1 + 0x1c4) == 1)))) {
        *(undefined4 *)(param_1 + 0x100) = 0xffffffff;
        if (*(char *)(param_1 + 0x235) == '\0') {
          fVar4 = *(float *)(param_1 + 0x154);
        }
        else {
          pSVar1 = (Ship *)Status::getShip(Globals::status);
          uVar2 = Ship::getCurrentLoad(pSVar1);
          fVar5 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
          pSVar1 = (Ship *)Status::getShip(Globals::status);
          uVar2 = Ship::getMaxLoad(pSVar1);
          fVar4 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
          fVar4 = *(float *)(param_1 + 0x154) * 0.6 +
                  *(float *)(param_1 + 0x154) * (1.0 - fVar5 / fVar4) * 0.4;
        }
        uVar6 = (uint)(in_r2 * 750.0 * fVar4);
        iVar3 = (int)((longlong)(int)uVar6 * -0x7df7df7d + ((ulonglong)uVar6 << 0x20) >> 0x20);
        fVar5 = (float)VectorSignedToFloat((iVar3 >> 5) - (iVar3 >> 0x1f),
                                           (byte)(in_fpscr >> 0x16) & 3);
        *(float *)(param_1 + 600) = -fVar4;
        *(float *)(param_1 + 0x270) = in_r2;
        if (*(float *)(param_1 + 0x278) < fVar5) {
          if (Globals::mouseCursorActivated == 0) {
            fVar8 = (float)Globals::options._24_4_ * 1.45;
            if (Globals::options[0x11] != '\0') {
              fVar8 = (float)Globals::options._20_4_;
            }
            fVar7 = (float)VectorSignedToFloat(in_r1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
            fVar8 = (3.3 - fVar8) * 20.0;
          }
          else {
            fVar7 = (float)VectorSignedToFloat(in_r1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
            fVar8 = 11.999998;
          }
          fVar4 = *(float *)(param_1 + 0x278) + (fVar7 * fVar4) / fVar8;
          if (fVar5 < fVar4) {
            fVar4 = fVar5;
          }
          *(float *)(param_1 + 0x278) = fVar4;
        }
      }
    }
    else {
      *(float *)(param_1 + 0x7c) = in_r2 * 0.003 * *(float *)(*(int *)(param_1 + 0x194) + 0x50);
    }
  }
  else {
    uVar6 = in_fpscr & 0xfffffff;
    if (*(float *)(param_1 + 0x1a8) < 70.0) {
      fVar5 = (float)VectorSignedToFloat(in_r1,(byte)(uVar6 >> 0x16) & 3);
      fVar4 = fVar5 * in_r2 + *(float *)(param_1 + 0x1a8);
      *(float *)(param_1 + 0x1a8) = fVar4;
      AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x28),fVar4,in_s1,fVar5 * in_r2);
      in_s1 = extraout_s1;
    }
    if (*(float *)(param_1 + 0x1a4) < 70.0) {
      fVar4 = (float)VectorSignedToFloat(in_r1,(byte)((uVar6 & 0xfffffff) >> 0x16) & 3);
      fVar5 = fVar4 * in_r2 * 0.5;
      fVar4 = fVar5 + *(float *)(param_1 + 0x1a4);
      *(float *)(param_1 + 0x1a4) = fVar4;
      AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x19c),fVar4,in_s1,fVar5);
      return;
    }
  }
  return;
}

// ===== PlayerEgo::up  @0x000ad468  (590 bytes)
/* PlayerEgo::up(int, float) */

void PlayerEgo::up(int param_1,float param_2)

{
  byte bVar1;
  Ship *pSVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 in_r1;
  float in_r2;
  uint in_fpscr;
  uint uVar5;
  float fVar6;
  float in_s1;
  float extraout_s1;
  float fVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  if (*(MiningGame **)(param_1 + 0x1e4) != (MiningGame *)0x0) {
    if (Globals::options[0x10] == '\0') {
      MiningGame::down(*(MiningGame **)(param_1 + 0x1e4),param_2);
      return;
    }
    (*(code *)&LAB_0006b6c0)();
    return;
  }
  if (*(char *)(param_1 + 0x1a0) == '\0') {
    if (*(int *)(param_1 + 0x194) == 0) {
      if ((*(char *)(param_1 + 0x158) == '\0') &&
         ((*(char *)(param_1 + 0x356) == '\0' || (*(int *)(param_1 + 0x1c4) == 1)))) {
        *(undefined4 *)(param_1 + 0x100) = 1;
        if (*(char *)(param_1 + 0x235) == '\0') {
          fVar6 = *(float *)(param_1 + 0x154);
        }
        else {
          pSVar2 = (Ship *)Status::getShip(Globals::status);
          uVar3 = Ship::getCurrentLoad(pSVar2);
          fVar7 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
          pSVar2 = (Ship *)Status::getShip(Globals::status);
          uVar3 = Ship::getMaxLoad(pSVar2);
          fVar6 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
          fVar6 = *(float *)(param_1 + 0x154) * 0.6 +
                  *(float *)(param_1 + 0x154) * (1.0 - fVar7 / fVar6) * 0.4;
        }
        uVar8 = (uint)(in_r2 * -750.0 * fVar6);
        iVar4 = (int)((longlong)(int)uVar8 * -0x7df7df7d + ((ulonglong)uVar8 << 0x20) >> 0x20);
        fVar9 = (float)VectorSignedToFloat((iVar4 >> 5) - (iVar4 >> 0x1f),
                                           (byte)(in_fpscr >> 0x16) & 3);
        *(float *)(param_1 + 600) = fVar6;
        *(float *)(param_1 + 0x270) = -in_r2;
        fVar7 = *(float *)(param_1 + 0x278);
        uVar8 = in_fpscr & 0xfffffff | (uint)(fVar7 < fVar9) << 0x1f |
                (uint)(fVar7 == fVar9) << 0x1e;
        bVar1 = (byte)(uVar8 >> 0x18);
        if (!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == (NAN(fVar7) || NAN(fVar9))) {
          if (Globals::mouseCursorActivated == 0) {
            fVar11 = (float)Globals::options._24_4_ * 1.25;
            if (Globals::options[0x11] != '\0') {
              fVar11 = (float)Globals::options._20_4_;
            }
            fVar10 = (float)VectorSignedToFloat(in_r1,(byte)(uVar8 >> 0x16) & 3);
            fVar11 = (3.3 - fVar11) * 20.0;
          }
          else {
            fVar10 = (float)VectorSignedToFloat(in_r1,(byte)(uVar8 >> 0x16) & 3);
            fVar11 = 11.999998;
          }
          fVar7 = fVar7 - (fVar10 * fVar6) / fVar11;
          if ((int)((uint)(fVar7 < fVar9) << 0x1f) < 0) {
            fVar7 = fVar9;
          }
          *(float *)(param_1 + 0x278) = fVar7;
        }
      }
    }
    else {
      *(float *)(param_1 + 0x7c) = in_r2 * -0.003 * *(float *)(*(int *)(param_1 + 0x194) + 0x50);
    }
  }
  else {
    fVar6 = *(float *)(param_1 + 0x1a8);
    uVar8 = in_fpscr & 0xfffffff | (uint)(fVar6 < -500.0) << 0x1f | (uint)(fVar6 == -500.0) << 0x1e;
    uVar5 = uVar8 | (uint)NAN(fVar6) << 0x1c;
    bVar1 = (byte)(uVar8 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar5 >> 0x1c) & 1)) {
      fVar7 = (float)VectorSignedToFloat(in_r1,(byte)(uVar5 >> 0x16) & 3);
      fVar6 = fVar6 - fVar7 * in_r2;
      *(float *)(param_1 + 0x1a8) = fVar6;
      AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x28),fVar6,in_s1,fVar7 * in_r2);
      in_s1 = extraout_s1;
    }
    fVar6 = *(float *)(param_1 + 0x1a4);
    uVar8 = uVar5 & 0xfffffff | (uint)(fVar6 < -250.0) << 0x1f | (uint)(fVar6 == -250.0) << 0x1e;
    bVar1 = (byte)(uVar8 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar6)) {
      fVar7 = (float)VectorSignedToFloat(in_r1,(byte)(uVar8 >> 0x16) & 3);
      fVar7 = fVar7 * in_r2 * 0.5;
      fVar6 = fVar6 - fVar7;
      *(float *)(param_1 + 0x1a4) = fVar6;
      AEGeometry::rotate(*(AEGeometry **)(param_1 + 0x19c),fVar6,in_s1,fVar7);
      return;
    }
  }
  return;
}

// ===== PlayerEgo::tryToStartEmergencySystem  @0x000ad6f0  (124 bytes)
/* PlayerEgo::tryToStartEmergencySystem() */

undefined4 __thiscall PlayerEgo::tryToStartEmergencySystem(PlayerEgo *this)

{
  int iVar1;
  Ship *this_00;
  Ship *this_01;
  Item *pIVar2;
  undefined4 uVar3;
  float fVar4;
  
  if ((*(int *)(this + 0xac) == 0) || (*(int *)(this + 0x30c) != 0)) {
    uVar3 = 0;
  }
  else {
    iVar1 = Player::getHitpoints(*(Player **)this);
    uVar3 = 0;
    if (iVar1 < 2) {
      Player::setHitpoints(*(Player **)this,1);
      *(undefined4 *)(this + 0x30c) = *(undefined4 *)(this + 0x310);
      Player::setVulnerable(*(Player **)this,false);
      this_00 = (Ship *)Status::getShip(Globals::status);
      this_01 = (Ship *)Status::getShip(Globals::status);
      pIVar2 = (Item *)Ship::getFirstEquipmentOfSort(this_01,0x1b);
      fVar4 = (float)Ship::removeEquipment(this_00,pIVar2);
      FModSound::play(Globals::sound,0x45b,(Vector *)0x0,(Vector *)0x0,fVar4);
      uVar3 = 1;
    }
  }
  return uVar3;
}

// ===== PlayerEgo::emergencySystemActive  @0x000ad774  (14 bytes)
/* PlayerEgo::emergencySystemActive() */

bool __thiscall PlayerEgo::emergencySystemActive(PlayerEgo *this)

{
  return 0 < *(int *)(this + 0x30c);
}

// ===== PlayerEgo::collidesWithStation  @0x000ad782  (6 bytes)
/* PlayerEgo::collidesWithStation() */

PlayerEgo __thiscall PlayerEgo::collidesWithStation(PlayerEgo *this)

{
  return this[0x234];
}

// ===== PlayerEgo::isHacking  @0x000ad788  (12 bytes)
/* PlayerEgo::isHacking() */

bool __thiscall PlayerEgo::isHacking(PlayerEgo *this)

{
  return *(int *)(this + 0x1e8) != 0;
}

// ===== PlayerEgo::hackingWon  @0x000ad794  (20 bytes)
/* PlayerEgo::hackingWon() */

undefined4 __thiscall PlayerEgo::hackingWon(PlayerEgo *this)

{
  undefined4 uVar1;
  
  if (*(HackingGame **)(this + 0x1e8) != (HackingGame *)0x0) {
    uVar1 = HackingGame::gameWon(*(HackingGame **)(this + 0x1e8));
    return uVar1;
  }
  return 0;
}

// ===== PlayerEgo::deleteHackingGame  @0x000ad7a8  (28 bytes)
/* PlayerEgo::deleteHackingGame() */

void __thiscall PlayerEgo::deleteHackingGame(PlayerEgo *this)

{
  void *pvVar1;
  
  if (*(HackingGame **)(this + 0x1e8) != (HackingGame *)0x0) {
    pvVar1 = (void *)HackingGame::~HackingGame(*(HackingGame **)(this + 0x1e8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1e8) = 0;
  return;
}

// ===== PlayerEgo::getHackingGameDockIndex  @0x000ad7c4  (18 bytes)
/* PlayerEgo::getHackingGameDockIndex() */

undefined4 __thiscall PlayerEgo::getHackingGameDockIndex(PlayerEgo *this)

{
  undefined4 uVar1;
  
  if (*(HackingGame **)(this + 0x1e8) == (HackingGame *)0x0) {
    return 0xffffffff;
  }
  uVar1 = HackingGame::getDockingIndex(*(HackingGame **)(this + 0x1e8));
  return uVar1;
}

// ===== PlayerEgo::isInDockingProcedure  @0x000ad7d4  (22 bytes)
/* PlayerEgo::isInDockingProcedure() */

bool __thiscall PlayerEgo::isInDockingProcedure(PlayerEgo *this)

{
  if (this[0x1c0] != (PlayerEgo)0x0) {
    return true;
  }
  return this[0x356] != (PlayerEgo)0x0;
}

// ===== PlayerEgo::turnVertical  @0x000ad7ec  (38 bytes)
/* PlayerEgo::turnVertical(int, float) */

void __thiscall PlayerEgo::turnVertical(PlayerEgo *this,int param_1,float param_2)

{
  float in_r2;
  
  if ((int)((uint)(in_r2 < -0.0) << 0x1f) < 0) {
    down((int)this,in_r2);
    return;
  }
  if (in_r2 <= 0.0) {
    return;
  }
  up((int)this,in_r2);
  return;
}

// ===== PlayerEgo::turnHorizontal  @0x000ad818  (30 bytes)
/* PlayerEgo::turnHorizontal(int, float) */

void __thiscall PlayerEgo::turnHorizontal(PlayerEgo *this,int param_1,float param_2)

{
  float in_r2;
  
  if (in_r2 < 0.0) {
    left((int)this,in_r2);
    return;
  }
  if (in_r2 == 0.0) {
    return;
  }
  right((int)this,in_r2);
  return;
}

// ===== PlayerEgo::getRocketBanking  @0x000ad832  (6 bytes)
/* PlayerEgo::getRocketBanking() */

undefined4 __thiscall PlayerEgo::getRocketBanking(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x198);
}

// ===== PlayerEgo::strafe  @0x000ad838  (198 bytes)
/* PlayerEgo::strafe(int, bool) */

void __thiscall PlayerEgo::strafe(PlayerEgo *this,int param_1,bool param_2)

{
  Ship *pSVar1;
  undefined4 uVar2;
  uint in_fpscr;
  float fVar3;
  undefined8 in_d0;
  undefined4 extraout_s1;
  undefined4 uVar5;
  undefined8 uVar4;
  undefined8 in_d1;
  undefined4 extraout_s3;
  undefined8 uVar6;
  undefined4 in_s5;
  undefined4 extraout_s5;
  undefined4 in_s9;
  undefined4 extraout_s9;
  float fVar7;
  
  uVar2 = (undefined4)((ulonglong)in_d1 >> 0x20);
  if (*(int *)(this + 0x194) == 0) {
    if (this[0x235] == (PlayerEgo)0x0) {
      uVar5 = (undefined4)((ulonglong)in_d0 >> 0x20);
      fVar3 = *(float *)(this + 0x154);
    }
    else {
      pSVar1 = (Ship *)Status::getShip(Globals::status);
      uVar2 = Ship::getCurrentLoad(pSVar1);
      fVar7 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      pSVar1 = (Ship *)Status::getShip(Globals::status);
      uVar2 = Ship::getMaxLoad(pSVar1);
      fVar3 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
      fVar3 = *(float *)(this + 0x154) * 0.6 +
              *(float *)(this + 0x154) * (1.0 - fVar7 / fVar3) * 0.4;
      in_s5 = extraout_s5;
      in_s9 = extraout_s9;
      uVar5 = extraout_s1;
      uVar2 = extraout_s3;
    }
    fVar7 = -1.0;
    if (param_2) {
      fVar7 = 1.0;
    }
    uVar4 = FloatVectorMin(CONCAT44(uVar5,fVar3 * 30.0 * 0.002),CONCAT44(in_s9,0x40000000),2,0x20);
    uVar6 = FloatVectorMin(CONCAT44(in_s5,*(float *)(this + 0x380) * 1.5),CONCAT44(uVar2,0x3f800000)
                           ,2,0x20);
    *(float *)(this + 0x37c) = *(float *)(this + 0x380) * fVar7 * (float)uVar4;
    *(int *)(this + 0x380) = (int)uVar6;
  }
  return;
}

// ===== PlayerEgo::hackingRotateRCW  @0x000ad910  (46 bytes)
/* PlayerEgo::hackingRotateRCW() */

void __thiscall PlayerEgo::hackingRotateRCW(PlayerEgo *this)

{
  int iVar1;
  
  if (((*(HackingGame **)(this + 0x1e8) != (HackingGame *)0x0) &&
      (iVar1 = HackingGame::isRotating(*(HackingGame **)(this + 0x1e8)), iVar1 == 0)) &&
     (iVar1 = HackingGame::gameWon(*(HackingGame **)(this + 0x1e8)), iVar1 == 0)) {
    HackingGame::rotateRightCW(SUB41(*(undefined4 *)(this + 0x1e8),0));
    return;
  }
  return;
}

// ===== PlayerEgo::hackingRotateLCW  @0x000ad93c  (46 bytes)
/* PlayerEgo::hackingRotateLCW() */

void __thiscall PlayerEgo::hackingRotateLCW(PlayerEgo *this)

{
  int iVar1;
  
  if (((*(HackingGame **)(this + 0x1e8) != (HackingGame *)0x0) &&
      (iVar1 = HackingGame::isRotating(*(HackingGame **)(this + 0x1e8)), iVar1 == 0)) &&
     (iVar1 = HackingGame::gameWon(*(HackingGame **)(this + 0x1e8)), iVar1 == 0)) {
    HackingGame::rotateLeftCW(SUB41(*(undefined4 *)(this + 0x1e8),0));
    return;
  }
  return;
}

// ===== PlayerEgo::hackingShuffle  @0x000ad968  (16 bytes)
/* PlayerEgo::hackingShuffle() */

void __thiscall PlayerEgo::hackingShuffle(PlayerEgo *this)

{
  if (*(HackingGame **)(this + 0x1e8) == (HackingGame *)0x0) {
    return;
  }
  HackingGame::reInit(*(HackingGame **)(this + 0x1e8));
  return;
}

// ===== PlayerEgo::alignToHorizon  @0x000ad976  (8 bytes)
/* PlayerEgo::alignToHorizon() */

void __thiscall PlayerEgo::alignToHorizon(PlayerEgo *this)

{
  this[0x2f4] = (PlayerEgo)0x1;
  return;
}

// ===== PlayerEgo::rotate  @0x000ad980  (124 bytes)
/* PlayerEgo::rotate(float, float, float) */

void __thiscall PlayerEgo::rotate(PlayerEgo *this,float param_1,float param_2,float param_3)

{
  float in_r1;
  float in_r2;
  float in_r3;
  float extraout_s1;
  float extraout_s2;
  Matrix aMStack_50 [60];
  int local_14;
  
  local_14 = __stack_chk_guard;
  *(float *)(this + 0x2e8) = *(float *)(this + 0x2e8) + in_r1;
  *(float *)(this + 0x2ec) = *(float *)(this + 0x2ec) + in_r2;
  *(float *)(this + 0x2f0) = *(float *)(this + 0x2f0) + in_r3;
  AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::AEMath::MatrixSetRotation
            (aMStack_50,*(float *)(this + 0x2f0),extraout_s1,extraout_s2);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::setRotation  @0x000ada08  (88 bytes)
/* PlayerEgo::setRotation(float, float, float) */

void __thiscall PlayerEgo::setRotation(PlayerEgo *this,float param_1,float param_2,float param_3)

{
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  float extraout_s1;
  float extraout_s2;
  Matrix aMStack_50 [60];
  int local_14;
  
  local_14 = __stack_chk_guard;
  *(undefined4 *)(this + 0x2e8) = in_r1;
  *(undefined4 *)(this + 0x2ec) = in_r2;
  *(undefined4 *)(this + 0x2f0) = in_r3;
  AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(*(int *)(this + 4) + 0xc));
  AbyssEngine::AEMath::MatrixSetRotation
            (aMStack_50,*(float *)(this + 0x2f0),extraout_s1,extraout_s2);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::explode  @0x000ada6c  (174 bytes)
/* PlayerEgo::explode() */

void __thiscall PlayerEgo::explode(PlayerEgo *this)

{
  Explosion *this_00;
  
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x74),*(int *)(this + 0x2fc),true);
  if (*(int *)(this + 0x8c) == 0) {
    TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x88),false);
    this_00 = operator_new(0x68);
    Explosion::Explosion(this_00,0);
    *(Explosion **)(this + 0x8c) = this_00;
    Player::setActive(*(Player **)this,false);
    FModSound::stop(Globals::sound,*(int *)Globals::sound);
    FModSound::stop(Globals::sound,*(int *)(this + 0x1c));
    FModSound::stop(Globals::sound,0x1b);
    FModSound::stop(Globals::sound,0x23);
    FModSound::stop(Globals::sound,0x8d5);
    FModSound::stop(Globals::sound,0x8d4);
    FModSound::stop(Globals::sound,0x8cc);
    FModSound::stop(Globals::sound,0x447);
    FModSound::stop(Globals::sound,0x448);
    FModSound::stop(Globals::sound,0x449);
    setExhaustVisible(this,false);
    return;
  }
  return;
}

// ===== PlayerEgo::revive  @0x000adb2c  (232 bytes)
/* PlayerEgo::revive() */

void __thiscall PlayerEgo::revive(PlayerEgo *this)

{
  void *pvVar1;
  int iVar2;
  Player *pPVar3;
  float fVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x74),*(int *)(this + 0x2fc),false);
  ParticleSystemManager::enableSystemRender
            (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x74),*(int *)(this + 0x2fc),false);
  if (*(Explosion **)(this + 0x8c) != (Explosion *)0x0) {
    pvVar1 = (void *)Explosion::~Explosion(*(Explosion **)(this + 0x8c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x8c) = 0;
  TargetFollowCamera::setActive(*(TargetFollowCamera **)(this + 0x88),true);
  fVar4 = (float)Player::setActive(*(Player **)this,true);
  fVar4 = (float)FModSound::play(Globals::sound,*(int *)Globals::sound,(Vector *)0x0,(Vector *)0x0,
                                 fVar4);
  FModSound::play(Globals::sound,*(int *)(this + 0x1c),(Vector *)0x0,(Vector *)0x0,fVar4);
  setExhaustVisible(this,true);
  pPVar3 = *(Player **)this;
  iVar2 = Player::getMaxHitpoints(pPVar3);
  Player::setHitpoints(pPVar3,iVar2);
  pPVar3 = *(Player **)this;
  iVar2 = Player::getMaxArmorHP(pPVar3);
  Player::setArmorHP(pPVar3,iVar2);
  local_24 = 0;
  uStack_20 = 0;
  local_1c = 0x461c4000;
  AEGeometry::setPosition(*(Vector **)(this + 8));
  local_24 = 0;
  uStack_20 = 0;
  local_1c = 0x3f800000;
  local_30 = 0;
  uStack_2c = 0x3f800000;
  local_28 = 0;
  AEGeometry::setDirection(*(AEGeometry **)(this + 8),(Vector *)&local_24,(Vector *)&local_30);
  *(undefined4 *)(this + 0x2f8) = 0;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::startSmokeEmission  @0x000adc20  (46 bytes)
/* PlayerEgo::startSmokeEmission() */

void __thiscall PlayerEgo::startSmokeEmission(PlayerEgo *this)

{
  if (*(int *)(this + 0x300) < 0) {
    return;
  }
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x78),*(int *)(this + 0x300),true);
  ParticleSystemManager::enableSystemEmit
            (*(ParticleSystemManager **)(*(int *)(this + 0xc) + 0x84),*(int *)(this + 0x304),true);
  return;
}

// ===== PlayerEgo::endExplosion  @0x000adc4e  (14 bytes)
/* PlayerEgo::endExplosion() */

void __thiscall PlayerEgo::endExplosion(PlayerEgo *this)

{
  if (*(Explosion **)(this + 0x8c) == (Explosion *)0x0) {
    return;
  }
  Explosion::reset(*(Explosion **)(this + 0x8c));
  return;
}

// ===== PlayerEgo::explosionEnded  @0x000adc5c  (26 bytes)
/* PlayerEgo::explosionEnded() */

bool __thiscall PlayerEgo::explosionEnded(PlayerEgo *this)

{
  if (*(int *)(this + 0x8c) != 0) {
    return 8000 < *(int *)(this + 0x2f8);
  }
  return true;
}

// ===== PlayerEgo::aboutToReachAutoTarget  @0x000adc76  (6 bytes)
/* PlayerEgo::aboutToReachAutoTarget() */

PlayerEgo __thiscall PlayerEgo::aboutToReachAutoTarget(PlayerEgo *this)

{
  return this[0x330];
}

// ===== PlayerEgo::resetGunDelay  @0x000adc7c  (10 bytes)
/* PlayerEgo::resetGunDelay() */

void __thiscall PlayerEgo::resetGunDelay(PlayerEgo *this)

{
  Player::resetGunDelay(*(Player **)this,0);
  return;
}

// ===== PlayerEgo::refillGunDelay  @0x000adc84  (10 bytes)
/* PlayerEgo::refillGunDelay() */

void __thiscall PlayerEgo::refillGunDelay(PlayerEgo *this)

{
  Player::refillGunDelay(*(Player **)this,0);
  return;
}

// ===== PlayerEgo::isDockedToAsteroid  @0x000adc8c  (22 bytes)
/* PlayerEgo::isDockedToAsteroid() */

bool __thiscall PlayerEgo::isDockedToAsteroid(PlayerEgo *this)

{
  if (this[0x1c0] != (PlayerEgo)0x0) {
    return *(int *)(this + 0x1c4) == 1;
  }
  return false;
}

// ===== PlayerEgo::isDockingToAsteroid  @0x000adca2  (22 bytes)
/* PlayerEgo::isDockingToAsteroid() */

undefined4 __thiscall PlayerEgo::isDockingToAsteroid(PlayerEgo *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this[0x1c0] != (PlayerEgo)0x0) && (*(int *)(this + 0x1c4) != 1)) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== PlayerEgo::isDockedToMiningPlant  @0x000adcb8  (84 bytes)
/* PlayerEgo::isDockedToMiningPlant() */

bool __thiscall PlayerEgo::isDockedToMiningPlant(PlayerEgo *this)

{
  Mission *this_00;
  int iVar1;
  Station *this_01;
  
  if ((this[0x356] != (PlayerEgo)0x0) && (*(int *)(this + 0x1c4) == 1)) {
    this_00 = (Mission *)Status::getMission(Globals::status);
    iVar1 = Mission::isEmpty(this_00);
    if (iVar1 == 1) {
      iVar1 = Status::inAlienOrbit(Globals::status);
      if (iVar1 != 0) {
        return false;
      }
      this_01 = (Station *)Status::getStation(Globals::status);
      iVar1 = Station::getIndex(this_01);
      return iVar1 == 0x67;
    }
  }
  return false;
}

// ===== PlayerEgo::isDockedToStream  @0x000add18  (6 bytes)
/* PlayerEgo::isDockedToStream() */

PlayerEgo __thiscall PlayerEgo::isDockedToStream(PlayerEgo *this)

{
  return this[0x1ed];
}

// ===== PlayerEgo::dockToPlanet  @0x000add20  (104 bytes)
/* PlayerEgo::dockToPlanet() */

void __thiscall PlayerEgo::dockToPlanet(PlayerEgo *this)

{
  float fVar1;
  
  TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x88),true);
  *(undefined4 *)(this + 0x138) = 0;
  this[0x13c] = (PlayerEgo)0x1;
  *(undefined4 *)(this + 0xb8) = 0x41000000;
  *(undefined4 *)(this + 0xcc) = 10000;
  *(undefined4 *)(this + 0xd0) = 0;
  this[0x144] = (PlayerEgo)0x0;
  fVar1 = (float)Player::resetGunDelay(*(Player **)this,0);
  this[0x1ee] = (PlayerEgo)0x1;
  this[0x38] = (PlayerEgo)0x0;
  *(undefined4 *)(this + 0xb8) = 0x41000000;
  *(undefined4 *)(this + 0x1f0) = 0;
  FModSound::play(Globals::sound,5,(Vector *)0x0,(Vector *)0x0,fVar1);
  return;
}

// ===== PlayerEgo::stopPlanetDock  @0x000add8c  (44 bytes)
/* PlayerEgo::stopPlanetDock() */

void __thiscall PlayerEgo::stopPlanetDock(PlayerEgo *this)

{
  TargetFollowCamera::setLookAtCam(*(TargetFollowCamera **)(this + 0x88),false);
  this[0x144] = (PlayerEgo)0x1;
  this[0x1ee] = (PlayerEgo)0x0;
  stopBoost(this);
  *(undefined4 *)(this + 0xb8) = 0x40000000;
  return;
}

// ===== PlayerEgo::isDockedToPlanet  @0x000addb8  (18 bytes)
/* PlayerEgo::isDockedToPlanet() */

bool __thiscall PlayerEgo::isDockedToPlanet(PlayerEgo *this)

{
  return 3000 < *(int *)(this + 0x1f0);
}

// ===== PlayerEgo::dockToStream  @0x000addcc  (130 bytes)
/* PlayerEgo::dockToStream(bool) */

void __thiscall PlayerEgo::dockToStream(PlayerEgo *this,bool param_1)

{
  PlayerEgo PVar1;
  int iVar2;
  
  iVar2 = __stack_chk_guard;
  if (param_1) {
    *(undefined2 *)(this + 0x1ec) = 0x100;
  }
  else {
    *(undefined4 *)(this + 0xb8) = 0x40000000;
    AEGeometry::setPosition(*(Vector **)(this + 8));
    this[0x145] = (PlayerEgo)0x0;
    this[0x24] = (PlayerEgo)0x0;
    this[0x1ec] = (PlayerEgo)0x0;
    this[0x1ed] = (PlayerEgo)0x0;
    *(undefined4 *)(this + 0x15c) = 0;
    this[0x160] = (PlayerEgo)0x0;
    PVar1 = this[0x158];
    this[0x158] = (PlayerEgo)0x0;
    *(undefined4 *)(*(int *)(this + 0x14) + 0x2c) = 0;
    if (PVar1 != (PlayerEgo)0x0) {
      *(undefined4 *)(this + 0x2a4) = 0;
      this[0x2a8] = (PlayerEgo)0x0;
    }
  }
  if (__stack_chk_guard != iVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::shouldSwitchToStandardCam  @0x000ade58  (18 bytes)
/* PlayerEgo::shouldSwitchToStandardCam() */

bool __thiscall PlayerEgo::shouldSwitchToStandardCam(PlayerEgo *this)

{
  PlayerEgo PVar1;
  
  PVar1 = this[0xb0];
  if (PVar1 != (PlayerEgo)0x0) {
    this[0xb0] = (PlayerEgo)0x0;
  }
  return PVar1 != (PlayerEgo)0x0;
}

// ===== PlayerEgo::shouldSwitchToFreeLookCam  @0x000ade6a  (18 bytes)
/* PlayerEgo::shouldSwitchToFreeLookCam() */

bool __thiscall PlayerEgo::shouldSwitchToFreeLookCam(PlayerEgo *this)

{
  PlayerEgo PVar1;
  
  PVar1 = this[0xb1];
  if (PVar1 != (PlayerEgo)0x0) {
    this[0xb1] = (PlayerEgo)0x0;
  }
  return PVar1 != (PlayerEgo)0x0;
}

// ===== PlayerEgo::setDockingState  @0x000ade7c  (24 bytes)
/* PlayerEgo::setDockingState(int) */

void __thiscall PlayerEgo::setDockingState(PlayerEgo *this,int param_1)

{
  if ((param_1 == 2) && (*(int *)(this + 0x1c4) == 1)) {
    this[0xb2] = (PlayerEgo)0x1;
  }
  *(int *)(this + 0x1c4) = param_1;
  return;
}

// ===== PlayerEgo::stopMining  @0x000ade94  (518 bytes)
/* PlayerEgo::stopMining() */

void __thiscall PlayerEgo::stopMining(PlayerEgo *this)

{
  Ship *pSVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Item *pIVar5;
  Status *pSVar6;
  Hud *this_00;
  void *pvVar7;
  int iVar8;
  int iVar9;
  uint in_fpscr;
  float fVar10;
  
  iVar8 = *(int *)(*(int *)(this + 0x1bc) + 0x124);
  pSVar1 = (Ship *)Status::getShip(Globals::status);
  iVar2 = Ship::getFreeSpace(pSVar1);
  iVar9 = iVar8 + 0xb;
  iVar3 = MiningGame::getOreAmount(*(MiningGame **)(this + 0x1e4));
  if (iVar8 == 0xd9) {
    iVar9 = 0xda;
  }
  iVar4 = Status::hardCoreMode();
  if ((iVar4 == 1) && (iVar4 = MiningGame::gameWon(*(MiningGame **)(this + 0x1e4)), iVar4 == 0)) {
    fVar10 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    iVar3 = (int)(fVar10 * 0.5);
  }
  if (iVar2 <= iVar3) {
    iVar3 = iVar2;
  }
  if (iVar2 < 1) {
    this_00 = *(Hud **)(this + 0x220);
    iVar3 = 0;
  }
  else {
    iVar2 = MiningGame::gotCore(*(MiningGame **)(this + 0x1e4));
    if (iVar2 == 1) {
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + iVar9 * 4),1);
      pSVar1 = (Ship *)Status::getShip(Globals::status);
      Ship::addCargo(pSVar1,pIVar5);
      Hud::catchCargo(*(Hud **)(this + 0x220),iVar9,1,false,false,false,false,false);
      pSVar6 = Globals::status;
      *(int *)(Globals::status + 0xa4) = *(int *)(Globals::status + 0xa4) + 1;
      if (iVar9 != 0xda) {
        *(undefined1 *)(*(int *)(*(int *)(pSVar6 + 0x98) + 4) + iVar9 + -0xa5) = 1;
      }
      pSVar1 = (Ship *)Status::getShip(pSVar6);
      iVar2 = Ship::getFreeSpace(pSVar1);
      if (iVar2 < iVar3) {
        iVar3 = iVar2;
      }
    }
    pSVar6 = Globals::status;
    if (0 < iVar3) {
      pIVar5 = (Item *)Item::makeItem(*(Item **)(*(int *)(Globals::items + 4) + iVar8 * 4),iVar3);
      pSVar1 = (Ship *)Status::getShip(Globals::status);
      Ship::addCargo(pSVar1,pIVar5);
      Hud::catchCargo(*(Hud **)(this + 0x220),iVar8,iVar3,false,false,true,false,false);
      pSVar6 = Globals::status;
      *(int *)(Globals::status + 0xa0) = *(int *)(Globals::status + 0xa0) + iVar3;
      if (iVar8 != 0xd9) {
        *(undefined1 *)(*(int *)(*(int *)(pSVar6 + 0x94) + 4) + iVar8 + -0x9a) = 1;
      }
    }
    pSVar1 = (Ship *)Status::getShip(pSVar6);
    iVar2 = Ship::getFreeSpace(pSVar1);
    if (0 < iVar2) goto LAB_000ae02a;
    this_00 = *(Hud **)(this + 0x220);
  }
  Hud::catchCargo(this_00,iVar8,iVar3,true,false,true,false,false);
LAB_000ae02a:
  setExhaustVisible(this,true);
  iVar3 = *(int *)(this + 0x1bc);
  *(undefined1 *)(iVar3 + 0x48) = 0;
  Player::setHitpoints(*(Player **)(iVar3 + 4),-1);
  *(int *)(Globals::status + 0xd8) = *(int *)(Globals::status + 0xd8) + -1;
  if (*(MiningGame **)(this + 0x1e4) != (MiningGame *)0x0) {
    pvVar7 = (void *)MiningGame::~MiningGame(*(MiningGame **)(this + 0x1e4));
    operator_delete(pvVar7);
  }
  *(undefined4 *)(this + 0x1e4) = 0;
  dockToAsteroid(this,(KIPlayer *)0x0,*(Radar **)(this + 0x14));
  FModSound::stop(Globals::sound,1);
  FModSound::stop(Globals::sound,3);
  FModSound::resume(Globals::sound,*(int *)(this + 0x1c));
  return;
}

// ===== PlayerEgo::lostMiningGame  @0x000ae0b8  (6 bytes)
/* PlayerEgo::lostMiningGame() */

PlayerEgo __thiscall PlayerEgo::lostMiningGame(PlayerEgo *this)

{
  return this[0x39b];
}

// ===== PlayerEgo::setRocketControl  @0x000ae0be  (98 bytes)
/* PlayerEgo::setRocketControl(Gun*, AEGeometry*) */

void __thiscall PlayerEgo::setRocketControl(PlayerEgo *this,Gun *param_1,AEGeometry *param_2)

{
  PlayerEgo PVar1;
  Matrix *pMVar2;
  int iVar3;
  
  *(Gun **)(this + 0x194) = param_1;
  pMVar2 = *(Matrix **)(*(int *)(this + 0xc) + 100);
  iVar3 = *(int *)(*(int *)(this + 0xc) + 0x88);
  if (param_1 == (Gun *)0x0) {
    ParticleSystemManager::systemSetMatrix(iVar3,pMVar2);
    *(undefined4 *)(this + 0x198) = 0;
  }
  else {
    AEGeometry::getReferenceMatrix(param_2);
    ParticleSystemManager::systemSetMatrix(iVar3,pMVar2);
    *(undefined4 *)(this + 0x15c) = 0;
    this[0x160] = (PlayerEgo)0x0;
    PVar1 = this[0x158];
    this[0x158] = (PlayerEgo)0x0;
    *(undefined4 *)(*(int *)(this + 0x14) + 0x2c) = 0;
    if (PVar1 != (PlayerEgo)0x0) {
      *(undefined4 *)(this + 0x2a4) = 0;
      this[0x2a8] = (PlayerEgo)0x0;
    }
  }
  return;
}

// ===== PlayerEgo::killLiberator  @0x000ae120  (152 bytes)
/* PlayerEgo::killLiberator() */

void __thiscall PlayerEgo::killLiberator(PlayerEgo *this)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  piVar4 = (int *)**(undefined4 **)this;
  if ((((piVar4 != (int *)0x0) && (puVar2 = *(uint **)(piVar4[1] + 4), puVar2 != (uint *)0x0)) &&
      (*piVar4 != 0)) && ((*puVar2 != 0 && (*(int *)(this + 0x10c) == 0xb3)))) {
    uVar3 = 0;
    do {
      iVar1 = *(int *)(puVar2[1] + uVar3 * 4);
      if (*(int *)(iVar1 + 0x58) == 0xb3) {
        **(undefined4 **)(iVar1 + 0x3c) = 0xffffffff;
        local_30 = 0x47435000;
        uStack_2c = 0x47435000;
        local_28 = 0x47435000;
        AbyssEngine::AEMath::Vector::operator=(*(Vector **)(iVar1 + 0xc),(Vector *)&local_30);
        puVar2 = *(uint **)(piVar4[1] + 4);
        *(undefined1 *)(*(int *)(puVar2[1] + uVar3 * 4) + 0x4c) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  if (__stack_chk_guard - local_24 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_24);
}

// ===== PlayerEgo::initManeuver  @0x000ae1c0  (176 bytes)
/* PlayerEgo::initManeuver(int) */

void __thiscall PlayerEgo::initManeuver(PlayerEgo *this,int param_1)

{
  float fVar1;
  AEMath aAStack_40 [12];
  Vector aVStack_34 [12];
  AEMath aAStack_28 [12];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((param_1 - 1U < 2) && (this[0x398] != (PlayerEgo)0x0)) {
    *(float *)(*(int *)this + 0x60) = *(float *)(*(int *)this + 0x60) + 0.17;
  }
  if (*(int *)(this + 0x334) == 0) {
    *(undefined4 *)(this + 0x350) = 0;
    *(int *)(this + 0x334) = param_1;
    if (param_1 == 3) {
      AEGeometry::getPosition();
      fVar1 = (float)AEGeometry::getDirection();
      AbyssEngine::AEMath::operator*(aAStack_40,fVar1,(Vector *)0x461c4000);
      AbyssEngine::AEMath::operator-(aAStack_28,aVStack_34,(Vector *)aAStack_40);
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x338),(Vector *)aAStack_28);
      AEGeometry::getDirection();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x344),(Vector *)aAStack_28);
    }
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::render  @0x000ae27c  (230 bytes)
/* PlayerEgo::render(bool) */

void __thiscall PlayerEgo::render(PlayerEgo *this,bool param_1)

{
  int iVar1;
  uint *puVar2;
  Level *this_00;
  uint uVar3;
  bool bVar4;
  
  iVar1 = Player::getHitpoints(*(Player **)this);
  if (iVar1 < 1) {
    if ((*(Explosion **)(this + 0x8c) != (Explosion *)0x0) &&
       (Explosion::render(*(Explosion **)(this + 0x8c)), *(int *)(this + 0x2f8) < 3000)) {
      AEGeometry::render(*(AEGeometry **)(this + 8));
    }
    if (*(Explosion **)(this + 0x90) != (Explosion *)0x0) {
      Explosion::render(*(Explosion **)(this + 0x90));
    }
    this_00 = *(Level **)(this + 0xc);
    bVar4 = true;
  }
  else {
    if (this[0x309] == (PlayerEgo)0x0) {
      return;
    }
    if (*(Explosion **)(this + 0x8c) != (Explosion *)0x0) {
      Explosion::render(*(Explosion **)(this + 0x8c));
    }
    AEGeometry::render(*(AEGeometry **)(this + 8));
    if ((*(AEGeometry **)(this + 0xac) != (AEGeometry *)0x0) && (0 < *(int *)(this + 0x30c))) {
      AEGeometry::render(*(AEGeometry **)(this + 0xac));
    }
    if (this[0x38] != (PlayerEgo)0x0) {
      AEGeometry::render(*(AEGeometry **)(this + 0x34));
    }
    if (this[0x170] != (PlayerEgo)0x0) {
      if (*(AEGeometry **)(this + 0x30) != (AEGeometry *)0x0) {
        AEGeometry::setVisible(*(AEGeometry **)(this + 0x30),(bool)this[0x1a0]);
      }
      AEGeometry::render(*(AEGeometry **)(this + 0x2c));
    }
    if (*(TractorBeam **)(this + 0x1b4) != (TractorBeam *)0x0) {
      TractorBeam::render(*(TractorBeam **)(this + 0x1b4));
    }
    puVar2 = *(uint **)(this + 0x1b8);
    if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
      uVar3 = 0;
      do {
        RepairBeam::render(*(RepairBeam **)(puVar2[1] + uVar3 * 4));
        puVar2 = *(uint **)(this + 0x1b8);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *puVar2);
    }
    this_00 = *(Level **)(this + 0xc);
    bVar4 = false;
    if ((this[0x24] == (PlayerEgo)0x0) && (param_1)) {
      bVar4 = *(int *)(this + 0x1c4) != 1;
    }
  }
  Level::enableMovingStars(this_00,bVar4);
  return;
}

// ===== PlayerEgo::hideShipForFirstPersonCameraView  @0x000ae360  (42 bytes)
/* PlayerEgo::hideShipForFirstPersonCameraView(bool) */

void __thiscall PlayerEgo::hideShipForFirstPersonCameraView(PlayerEgo *this,bool param_1)

{
  this[0x32d] = (PlayerEgo)param_1;
  this[0x309] = (PlayerEgo)((char)*(ushort *)(this + 0x32e) != '\0' && !param_1);
  *(bool *)*(undefined4 *)(*(int *)(this + 0xc) + 0x80) =
       0xff < *(ushort *)(this + 0x32e) && !param_1;
  return;
}

// ===== PlayerEgo::setVisible  @0x000ae38a  (14 bytes)
/* PlayerEgo::setVisible(bool) */

void __thiscall PlayerEgo::setVisible(PlayerEgo *this,bool param_1)

{
  this[0x32e] = (PlayerEgo)param_1;
  this[0x309] = (PlayerEgo)param_1;
  setExhaustVisible(this,param_1);
  return;
}

// ===== PlayerEgo::draw  @0x000ae3a0  (608 bytes)
/* WARNING: Removing unreachable block (ram,0x000ae3ec) */
/* WARNING: Removing unreachable block (ram,0x000ae51e) */
/* PlayerEgo::draw(bool) */

void __thiscall PlayerEgo::draw(PlayerEgo *this,bool param_1)

{
  PlayerEgo PVar1;
  int iVar2;
  Matrix *pMVar3;
  Ship *this_00;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
  undefined4 local_50 [5];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (*(int *)(this + 0x194) == 0) {
    if ((*(HackingGame **)(this + 0x1e8) != (HackingGame *)0x0) && (this[0x1a0] == (PlayerEgo)0x0))
    {
      HackingGame::render2D(*(HackingGame **)(this + 0x1e8));
      return;
    }
    if (*(MiningGame **)(this + 0x1e4) != (MiningGame *)0x0) {
      MiningGame::render2D(*(MiningGame **)(this + 0x1e4));
      return;
    }
    if (((this[500] == (PlayerEgo)0x0) &&
        (iVar2 = Player::getHitpoints(*(Player **)this), 0 < iVar2)) &&
       (this[0x24] == (PlayerEgo)0x0)) {
      PVar1 = (PlayerEgo)!param_1;
      bVar6 = !(bool)PVar1;
      if (bVar6) {
        PVar1 = this[0x1c0];
      }
      if (((bVar6 && PVar1 == (PlayerEgo)0x0) && (this[0x1ee] == (PlayerEgo)0x0)) &&
         ((this[0x1ed] == (PlayerEgo)0x0 &&
          ((this[0x356] == (PlayerEgo)0x0 || (this[0x1a0] != (PlayerEgo)0x0)))))) {
        PVar1 = this[0x1a0];
        if (this[0x158] != (PlayerEgo)0x0) {
          if (PVar1 == (PlayerEgo)0x0) goto LAB_000ae4d0;
          PVar1 = (PlayerEgo)0x1;
        }
        uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        puVar5 = (undefined4 *)((uint)local_50 | 4);
        local_50[0] = 0x3f800000;
        *puVar5 = 0;
        puVar5[1] = uStack_34;
        puVar5[2] = uStack_30;
        puVar5[3] = uStack_2c;
        local_3c = 0x3f800000;
        local_38 = 0;
        local_28 = 0x3f800000;
        uStack_20 = 0x3f8000003f800000;
        local_18 = 0x3f800000;
        if (PVar1 == (PlayerEgo)0x0) {
          pMVar3 = (Matrix *)AEGeometry::getMatrix(*(AEGeometry **)(this + 8));
          AbyssEngine::AEMath::Matrix::operator=((Matrix *)local_50,pMVar3);
        }
        AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
        if (this[0x1a0] == (PlayerEgo)0x0) {
LAB_000ae520:
          if (*(char *)(*(int *)(this + 0xc) + 0x30) == '\0') {
            AbyssEngine::PaintCanvas::DrawImage2D
                      (Globals::Canvas,*(uint *)(this + 0x23c),(int)(float)crosshairPos._0_4_,
                       (int)(float)crosshairPos._4_4_,'\x11','D');
            *(undefined4 *)(this + 0x24c) = 0;
          }
          else {
            AbyssEngine::PaintCanvas::DrawImage2D
                      (Globals::Canvas,*(uint *)(this + 0x240),(int)(float)crosshairPos._0_4_,
                       (int)(float)crosshairPos._4_4_,'\x11','D');
            iVar2 = *(int *)(this + 0x24c);
            *(int *)(this + 0x24c) = *(int *)(this + 0x134) + iVar2;
            if (200 < *(int *)(this + 0x134) + iVar2) {
              *(undefined1 *)(*(int *)(this + 0xc) + 0x30) = 0;
            }
          }
        }
        else {
          this_00 = (Ship *)Status::getShip(Globals::status);
          iVar2 = Ship::getFirstEquipmentOfSort(this_00,0x23);
          if (iVar2 == 0) goto LAB_000ae520;
          iVar2 = Radar::isPlasmaInRange(*(Radar **)(this + 0x14));
          if (iVar2 == 1) {
            uVar4 = *(uint *)(this + 0x248);
          }
          else {
            uVar4 = *(uint *)(this + 0x244);
          }
          AbyssEngine::PaintCanvas::DrawImage2D
                    (Globals::Canvas,uVar4,(int)(float)crosshairPos._0_4_,
                     (int)(float)crosshairPos._4_4_,'\x11','D');
        }
        drawThrottle(this);
        goto LAB_000ae5e4;
      }
    }
LAB_000ae4d0:
    if ((this[0x158] != (PlayerEgo)0x0) ||
       ((this[0x356] != (PlayerEgo)0x0 && (2 < *(int *)(this + 0x1c4) - 1U)))) {
      if (__stack_chk_guard == local_14) {
        drawThrottle(this);
        return;
      }
      goto LAB_000ae5f6;
    }
  }
LAB_000ae5e4:
  if (__stack_chk_guard == local_14) {
    return;
  }
LAB_000ae5f6:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== PlayerEgo::drawThrottle  @0x000ae650  (478 bytes)
/* PlayerEgo::drawThrottle() */

void __thiscall PlayerEgo::drawThrottle(PlayerEgo *this)

{
  undefined4 uVar1;
  PaintCanvas *this_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  uint in_fpscr;
  uint uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  undefined4 local_2c [2];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (this[0x370] != (PlayerEgo)0x0) {
    iVar3 = *(int *)(this + 0x374);
    if (500 < iVar3) {
      iVar3 = 2000 - iVar3;
    }
    VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
    uVar6 = in_fpscr & 0xfffffff;
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x238));
    iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x238));
    fVar7 = (float)VectorSignedToFloat(iVar4,(byte)(uVar6 >> 0x16) & 3);
    fVar9 = (float)VectorSignedToFloat(iVar3 / 2,(byte)(uVar6 >> 0x16) & 3);
    iVar10 = (int)(fVar7 * *(float *)(this + 0xbc));
    fVar8 = (float)VectorSignedToFloat(iVar10,(byte)(uVar6 >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawRegion2D
              (Globals::Canvas,*(uint *)(this + 0x238),0,iVar4 - iVar10,iVar3,
               (int)(fVar7 * *(float *)(this + 0xbc)),
               (float)(int)((fVar7 + (float)crosshairPos._4_4_) - fVar8),0,0,0,
               (int)((float)crosshairPos._0_4_ - fVar9));
    local_2c[0] = 0;
    AbyssEngine::String::Set(CONCAT44(extraout_r1,local_2c));
    uVar5 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0x238));
    uVar2 = Globals::font;
    this_00 = Globals::Canvas;
    uVar1 = crosshairPos._0_4_;
    iVar3 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,(String *)local_2c)
    ;
    fVar7 = (float)VectorSignedToFloat(uVar5,(byte)(uVar6 >> 0x16) & 3);
    fVar8 = (float)VectorSignedToFloat(iVar3 / 2,(byte)(uVar6 >> 0x16) & 3);
    fVar7 = (float)VectorSignedToFloat((int)(fVar7 / 1.6),(byte)(uVar6 >> 0x16) & 3);
    AbyssEngine::PaintCanvas::DrawString
              (this_00,uVar2,(String *)local_2c,(int)(((float)uVar1 - fVar8) + -1.0),
               (int)(fVar7 + (float)crosshairPos._4_4_),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::String::~String((String *)local_2c);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== PlayerEgo::throttleChanged  @0x000ae874  (66 bytes)
/* PlayerEgo::throttleChanged() */

void __thiscall PlayerEgo::throttleChanged(PlayerEgo *this)

{
  int iVar1;
  
  if (this[0x370] == (PlayerEgo)0x0) {
    *(undefined4 *)(this + 0x374) = 0;
    this[0x370] = (PlayerEgo)0x1;
  }
  else {
    iVar1 = *(int *)(this + 0x374);
    if (iVar1 - 0x1f5U < 999) {
      *(undefined4 *)(this + 0x374) = 500;
      return;
    }
    if (0x5db < iVar1) {
      *(int *)(this + 0x374) = 2000 - iVar1;
      return;
    }
  }
  return;
}

// ===== PlayerEgo::getHandling  @0x000ae8b6  (6 bytes)
/* PlayerEgo::getHandling() */

undefined4 __thiscall PlayerEgo::getHandling(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x154);
}

// ===== PlayerEgo::shake  @0x000ae8bc  (150 bytes)
/* PlayerEgo::shake(int) */

void __thiscall PlayerEgo::shake(PlayerEgo *this,int param_1)

{
  int iVar1;
  int iVar2;
  AEGeometry *this_00;
  uint in_fpscr;
  float fVar3;
  int iVar4;
  float extraout_s1;
  float fVar5;
  float extraout_s2;
  
  fVar3 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  this_00 = *(AEGeometry **)(this + 8);
  fVar5 = (float)VectorSignedToFloat(*(int *)(this + 0x134) << 1,(byte)(in_fpscr >> 0x16) & 3);
  iVar4 = (int)((fVar3 / 40000.0) * fVar5);
  if (iVar4 < 1) {
    iVar4 = 1;
  }
  iVar2 = iVar4 << 1;
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar2);
  VectorSignedToFloat(iVar1 - iVar4,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar2);
  VectorSignedToFloat(iVar1 - iVar4,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,iVar2);
  fVar3 = (float)VectorSignedToFloat(iVar1 - iVar4,(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::translate(this_00,fVar3,extraout_s1,extraout_s2);
  return;
}

// ===== PlayerEgo::getHUD  @0x000ae95c  (6 bytes)
/* PlayerEgo::getHUD() */

undefined4 __thiscall PlayerEgo::getHUD(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x220);
}

// ===== PlayerEgo::isInFreeLookMode  @0x000ae962  (6 bytes)
/* PlayerEgo::isInFreeLookMode() */

PlayerEgo __thiscall PlayerEgo::isInFreeLookMode(PlayerEgo *this)

{
  return this[0xc4];
}

// ===== PlayerEgo::setFreeLookMode  @0x000ae968  (6 bytes)
/* PlayerEgo::setFreeLookMode(bool) */

void __thiscall PlayerEgo::setFreeLookMode(PlayerEgo *this,bool param_1)

{
  this[0xc4] = (PlayerEgo)param_1;
  return;
}

// ===== PlayerEgo::setTargetFollowCamera  @0x000ae96e  (18 bytes)
/* PlayerEgo::setTargetFollowCamera(TargetFollowCamera*) */

void PlayerEgo::setTargetFollowCamera(TargetFollowCamera *param_1)

{
  TargetFollowCamera *in_r1;
  float in_s0;
  
  *(TargetFollowCamera **)(param_1 + 0x88) = in_r1;
  TargetFollowCamera::setShipHandling(in_r1,in_s0);
  return;
}

// ===== PlayerEgo::getTargetFollowCamera  @0x000ae97e  (6 bytes)
/* PlayerEgo::getTargetFollowCamera() */

undefined4 __thiscall PlayerEgo::getTargetFollowCamera(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x88);
}

// ===== PlayerEgo::pitchAllPrimaryGuns  @0x000ae984  (8 bytes)
/* PlayerEgo::pitchAllPrimaryGuns(float) */

void PlayerEgo::pitchAllPrimaryGuns(float param_1)

{
  undefined4 *in_r0;
  
  Player::pitchAllPrimaryGuns((Player *)*in_r0,param_1);
  return;
}

// ===== PlayerEgo::setSpeed  @0x000ae98a  (6 bytes)
/* PlayerEgo::setSpeed(float) */

void __thiscall PlayerEgo::setSpeed(PlayerEgo *this,float param_1)

{
  undefined4 in_r1;
  
  *(undefined4 *)(this + 0xb8) = in_r1;
  return;
}

// ===== PlayerEgo::changeThrust  @0x000ae990  (86 bytes)
/* PlayerEgo::changeThrust(float) */

void __thiscall PlayerEgo::changeThrust(PlayerEgo *this,float param_1)

{
  float in_r1;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(this + 0xbc) + in_r1;
  fVar3 = 1.0;
  if ((int)((uint)(fVar1 < 1.0) << 0x1f) < 0) {
    fVar3 = 0.0;
  }
  if ((int)((uint)(fVar1 < 0.0) << 0x1f) < 0) {
    fVar3 = 0.0;
  }
  fVar2 = fVar1;
  if (-1 < (int)((uint)(fVar1 < 1.0) << 0x1f)) {
    fVar2 = fVar3;
  }
  if ((int)((uint)(fVar1 < 0.0) << 0x1f) < 0) {
    fVar2 = fVar3;
  }
  *(float *)(this + 0xbc) = fVar2;
  return;
}

// ===== PlayerEgo::getThrust  @0x000ae9ec  (6 bytes)
/* PlayerEgo::getThrust() */

undefined4 __thiscall PlayerEgo::getThrust(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0xbc);
}

// ===== PlayerEgo::getSpeed  @0x000ae9f2  (6 bytes)
/* PlayerEgo::getSpeed() */

undefined4 __thiscall PlayerEgo::getSpeed(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0xb8);
}

// ===== PlayerEgo::getDockTotalAmount  @0x000ae9f8  (6 bytes)
/* PlayerEgo::getDockTotalAmount() */

undefined4 __thiscall PlayerEgo::getDockTotalAmount(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x360);
}

// ===== PlayerEgo::getDockTransferedAmount  @0x000ae9fe  (6 bytes)
/* PlayerEgo::getDockTransferedAmount() */

undefined4 __thiscall PlayerEgo::getDockTransferedAmount(PlayerEgo *this)

{
  return *(undefined4 *)(this + 0x364);
}

