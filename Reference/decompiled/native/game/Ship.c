// Class: Ship
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Ship::Ship  @0x001a335c  (132 bytes)
/* Ship::Ship(int, int, int, int, int, int, int, int, float) */

Ship * __thiscall
Ship::Ship(Ship *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
          int param_7,int param_8,float param_9)

{
  int *piVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  float in_stack_00000014;
  
  *(int *)this = param_1;
  *(int *)(this + 4) = param_2;
  *(int *)(this + 8) = param_4;
  *(int *)(this + 0xc) = param_3;
  *(undefined4 *)(this + 0x10) = 0;
  *(int *)(this + 0x14) = param_4;
  piVar1 = operator_new__(0x10);
  *(int **)(this + 0x68) = piVar1;
  *piVar1 = param_5;
  piVar1[1] = param_6;
  piVar1[2] = param_7;
  piVar1[3] = param_8;
  *(float *)(this + 0x18) = in_stack_00000014 / 100.0;
  pAVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar2 + 4) = puVar3;
  *puVar3 = 0;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *(undefined4 *)pAVar2 = 0;
  *(Array **)(this + 0x6c) = pAVar2;
  ArraySetLength<Item*>(param_6 + param_5 + param_7 + param_8,pAVar2);
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  refreshValue(this);
  return this;
}

// ===== Ship::refreshValue  @0x001a33f4  (880 bytes)
/* Ship::refreshValue() */

void __thiscall Ship::refreshValue(Ship *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  Standing *pSVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  Item *this_00;
  uint *puVar8;
  uint uVar9;
  uint in_fpscr;
  float fVar10;
  float fVar11;
  float fVar12;
  
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  this[0x50] = (Ship)0x0;
  this[0x51] = (Ship)0x0;
  this[0x5c] = (Ship)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = uVar5;
  *(undefined4 *)(this + 0x24) = uVar1;
  *(undefined4 *)(this + 0x28) = uVar2;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = uVar5;
  *(undefined4 *)(this + 0x44) = uVar1;
  *(undefined4 *)(this + 0x48) = uVar2;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = uVar5;
  *(undefined4 *)(this + 0x38) = uVar1;
  *(undefined4 *)(this + 0x3c) = uVar2;
  *(undefined4 *)(this + 0x60) = 0xffffffff;
  *(undefined4 *)(this + 0x54) = 0x3f800000;
  *(undefined4 *)(this + 0x58) = 0x3f800000;
  if ((Globals::status != (Status *)0x0) &&
     (iVar3 = Status::getStanding(Globals::status), iVar3 != 0)) {
    pSVar4 = (Standing *)Status::getStanding(Globals::status);
    Standing::setPlayerSignatureRace(pSVar4,-1);
  }
  *(undefined4 *)(this + 8) = *(undefined4 *)(this + 0x14);
  puVar8 = *(uint **)(this + 0x6c);
  if (*puVar8 == 0) {
    *(undefined4 *)(this + 0x48) = 0;
  }
  else {
    iVar3 = 0;
    uVar9 = 0;
    do {
      if (*(Item **)(puVar8[1] + iVar3) != (Item *)0x0) {
        uVar5 = Item::getSort(*(Item **)(puVar8[1] + iVar3));
        switch(uVar5) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 8:
        case 0x19:
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),9);
          fVar11 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0xb);
          fVar10 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
          *(float *)(this + 0x48) = *(float *)(this + 0x48) + (fVar11 / fVar10) * 1000.0;
          break;
        case 9:
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x12);
          *(undefined4 *)(this + 0x1c) = uVar5;
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x13);
          *(undefined4 *)(this + 0x24) = uVar5;
          break;
        case 10:
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x14);
          *(undefined4 *)(this + 0x20) = uVar5;
          break;
        case 0xc:
          iVar6 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x16);
          *(int *)(this + 0x28) = iVar6 + *(int *)(this + 0x28);
          break;
        case 0xe:
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x19);
          *(undefined4 *)(this + 0x34) = uVar5;
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x1b);
          *(undefined4 *)(this + 0x3c) = uVar5;
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x1a);
          *(undefined4 *)(this + 0x38) = uVar5;
          break;
        case 0xf:
          iVar6 = Item::getIndex(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3));
          *(uint *)(this + 0x4c) = (uint)(iVar6 != 0x4b);
          break;
        case 0x10:
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x1c);
          *(undefined4 *)(this + 0x40) = uVar5;
          break;
        case 0x11:
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x1f);
          *(undefined4 *)(this + 0x30) = uVar5;
          break;
        case 0x12:
          this[0x50] = (Ship)0x1;
          break;
        case 0x14:
          iVar6 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x22);
          *(int *)(this + 0x44) = iVar6 + *(int *)(this + 0x44);
          break;
        case 0x15:
          this[0x51] = (Ship)0x1;
          break;
        case 0x1b:
          this[0x5c] = (Ship)0x1;
          break;
        case 0x1c:
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x27);
          fVar10 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
          fVar10 = 1.0 - fVar10 / 100.0;
          uVar7 = in_fpscr & 0xfffffff | (uint)(fVar10 == -9.7979795e+08) << 0x1e;
          if ((byte)(uVar7 >> 0x1e) != 0) {
            fVar10 = 1.0;
          }
          *(float *)(this + 0x54) = fVar10;
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3),0x28);
          fVar10 = (float)VectorSignedToFloat(uVar5,(byte)(uVar7 >> 0x16) & 3);
          fVar10 = fVar10 / 100.0 + 1.0;
          in_fpscr = uVar7 & 0xfffffff | (uint)(fVar10 == -9.7979795e+08) << 0x1e;
          *(float *)(this + 0x58) = fVar10;
          if ((byte)(in_fpscr >> 0x1e) != 0) {
            *(undefined4 *)(this + 0x58) = 0x3f800000;
          }
          break;
        case 0x1d:
          iVar6 = Item::getIndex(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3));
          *(int *)(this + 0x60) = iVar6 + -0xbd;
          if ((Globals::status != (Status *)0x0) &&
             (iVar6 = Status::getStanding(Globals::status), iVar6 != 0)) {
            pSVar4 = (Standing *)Status::getStanding(Globals::status);
            Standing::setPlayerSignatureRace(pSVar4,*(int *)(this + 0x60));
          }
        }
        iVar6 = Item::getTotalPrice(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar3));
        *(int *)(this + 8) = iVar6 + *(int *)(this + 8);
        puVar8 = *(uint **)(this + 0x6c);
      }
      uVar7 = *puVar8;
      uVar9 = uVar9 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar9 < uVar7);
    *(undefined4 *)(this + 0x48) = 0;
    if (uVar7 != 0) {
      uVar9 = 0;
      do {
        this_00 = *(Item **)(puVar8[1] + uVar9 * 4);
        if (((this_00 != (Item *)0x0) && (uVar7 = Item::getSort(this_00), uVar7 < 0x1a)) &&
           ((1 << (uVar7 & 0xff) & 0x200010fU) != 0)) {
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + uVar9 * 4),9);
          fVar11 = *(float *)(this + 0x58);
          fVar12 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
          uVar5 = Item::getAttribute(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + uVar9 * 4),0xb
                                    );
          fVar10 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
          *(float *)(this + 0x48) =
               *(float *)(this + 0x48) +
               ((fVar12 * fVar11) / (fVar10 * *(float *)(this + 0x54))) * 1000.0;
        }
        puVar8 = *(uint **)(this + 0x6c);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *puVar8);
    }
  }
  puVar8 = *(uint **)(this + 0x78);
  if ((puVar8 == (uint *)0x0) || (*puVar8 == 0)) {
    iVar3 = 0;
  }
  else {
    uVar9 = 0;
    iVar3 = 0;
    do {
      iVar6 = uVar9 * 4;
      uVar9 = uVar9 + 1;
      if (*(int *)(puVar8[1] + iVar6) == 1) {
        iVar3 = iVar3 + 0x1e;
      }
    } while (uVar9 < *puVar8);
  }
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0x28);
  fVar10 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x28),(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorSignedToFloat(*(int *)(this + 0xc) + iVar3,(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x28) = iVar3 + (int)((fVar11 * fVar10) / 100.0);
  iVar3 = getCargoValue(this);
  *(int *)(this + 8) = iVar3 + *(int *)(this + 8);
  return;
}

// ===== Ship::~Ship  @0x001a37a0  (116 bytes)
/* Ship::~Ship() */

Ship * __thiscall Ship::~Ship(Ship *this)

{
  Array *pAVar1;
  void *pvVar2;
  
  pAVar1 = *(Array **)(this + 0x6c);
  if (pAVar1 != (Array *)0x0) {
    if (*(int *)pAVar1 != 0) {
      ArrayReleaseClasses<Item*>(pAVar1);
      pAVar1 = *(Array **)(this + 0x6c);
      if (pAVar1 == (Array *)0x0) goto LAB_001a37c8;
    }
    if (*(void **)(pAVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar1 + 4));
    }
    operator_delete(pAVar1);
  }
LAB_001a37c8:
  *(undefined4 *)(this + 0x6c) = 0;
  pAVar1 = *(Array **)(this + 0x70);
  if (pAVar1 != (Array *)0x0) {
    if (*(int *)pAVar1 != 0) {
      ArrayReleaseClasses<Item*>(pAVar1);
      pAVar1 = *(Array **)(this + 0x70);
      if (pAVar1 == (Array *)0x0) goto LAB_001a37ec;
    }
    if (*(void **)(pAVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar1 + 4));
    }
    operator_delete(pAVar1);
  }
LAB_001a37ec:
  *(undefined4 *)(this + 0x70) = 0;
  if (*(void **)(this + 0x68) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x68));
  }
  *(undefined4 *)(this + 0x68) = 0;
  pvVar2 = *(void **)(this + 0x78);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x78) = 0;
  return this;
}

// ===== Ship::setRace  @0x001a3814  (4 bytes)
/* Ship::setRace(int) */

void __thiscall Ship::setRace(Ship *this,int param_1)

{
  *(int *)(this + 100) = param_1;
  return;
}

// ===== Ship::getRace  @0x001a3818  (4 bytes)
/* Ship::getRace() */

undefined4 __thiscall Ship::getRace(Ship *this)

{
  return *(undefined4 *)(this + 100);
}

// ===== Ship::getIndex  @0x001a381c  (4 bytes)
/* Ship::getIndex() */

undefined4 __thiscall Ship::getIndex(Ship *this)

{
  return *(undefined4 *)this;
}

// ===== Ship::getPrice  @0x001a3820  (4 bytes)
/* Ship::getPrice() */

undefined4 __thiscall Ship::getPrice(Ship *this)

{
  return *(undefined4 *)(this + 0x14);
}

// ===== Ship::setCurrentWeaponSlot  @0x001a3824  (4 bytes)
/* Ship::setCurrentWeaponSlot(int) */

void __thiscall Ship::setCurrentWeaponSlot(Ship *this,int param_1)

{
  *(int *)(this + 0x74) = param_1;
  return;
}

// ===== Ship::getCurrentWeaponSlot  @0x001a3828  (4 bytes)
/* Ship::getCurrentWeaponSlot() */

undefined4 __thiscall Ship::getCurrentWeaponSlot(Ship *this)

{
  return *(undefined4 *)(this + 0x74);
}

// ===== Ship::getHandlingForShop  @0x001a382c  (66 bytes)
/* Ship::getHandlingForShop() */

float __thiscall Ship::getHandlingForShop(Ship *this)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  float fVar4;
  
  puVar2 = *(uint **)(this + 0x78);
  fVar4 = 0.0;
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    fVar4 = 0.0;
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      if (*(int *)(puVar2[1] + iVar1) == 3) {
        fVar4 = fVar4 + 0.2;
      }
    } while (uVar3 < *puVar2);
  }
  return fVar4 + *(float *)(this + 0x18);
}

// ===== Ship::getHandling  @0x001a3878  (66 bytes)
/* Ship::getHandling() */

float __thiscall Ship::getHandling(Ship *this)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  float fVar4;
  
  puVar2 = *(uint **)(this + 0x78);
  fVar4 = 0.0;
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    fVar4 = 0.0;
    do {
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      if (*(int *)(puVar2[1] + iVar1) == 3) {
        fVar4 = fVar4 + 0.2;
      }
    } while (uVar3 < *puVar2);
  }
  return fVar4 + *(float *)(this + 0x18);
}

// ===== Ship::getBaseHP  @0x001a38c4  (4 bytes)
/* Ship::getBaseHP() */

undefined4 __thiscall Ship::getBaseHP(Ship *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== Ship::getCombinedHP  @0x001a38c8  (58 bytes)
/* Ship::getCombinedHP() */

int __thiscall Ship::getCombinedHP(Ship *this)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(this + 0x78);
  if ((puVar2 == (uint *)0x0) || (*puVar2 == 0)) {
    iVar3 = 0;
  }
  else {
    uVar4 = 0;
    iVar3 = 0;
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      if (*(int *)(puVar2[1] + iVar1) == 0) {
        iVar3 = iVar3 + 0x28;
      }
    } while (uVar4 < *puVar2);
  }
  return *(int *)(this + 0x20) + iVar3 + *(int *)(this + 4) + *(int *)(this + 0x1c);
}

// ===== Ship::getMaxArmorHP  @0x001a3902  (4 bytes)
/* Ship::getMaxArmorHP() */

undefined4 __thiscall Ship::getMaxArmorHP(Ship *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== Ship::getMaxHP  @0x001a3906  (50 bytes)
/* Ship::getMaxHP() */

int __thiscall Ship::getMaxHP(Ship *this)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(this + 0x78);
  if ((puVar2 == (uint *)0x0) || (*puVar2 == 0)) {
    iVar3 = 0;
  }
  else {
    uVar4 = 0;
    iVar3 = 0;
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      if (*(int *)(puVar2[1] + iVar1) == 0) {
        iVar3 = iVar3 + 0x28;
      }
    } while (uVar4 < *puVar2);
  }
  return *(int *)(this + 4) + iVar3;
}

// ===== Ship::getMaxShieldHP  @0x001a3938  (4 bytes)
/* Ship::getMaxShieldHP() */

undefined4 __thiscall Ship::getMaxShieldHP(Ship *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== Ship::getShieldRegen  @0x001a393c  (4 bytes)
/* Ship::getShieldRegen() */

undefined4 __thiscall Ship::getShieldRegen(Ship *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== Ship::getValue  @0x001a3940  (4 bytes)
/* Ship::getValue() */

undefined4 __thiscall Ship::getValue(Ship *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== Ship::getRadarType  @0x001a3944  (4 bytes)
/* Ship::getRadarType() */

undefined4 __thiscall Ship::getRadarType(Ship *this)

{
  return *(undefined4 *)(this + 0x30);
}

// ===== Ship::getBoostSpeed  @0x001a3948  (4 bytes)
/* Ship::getBoostSpeed() */

undefined4 __thiscall Ship::getBoostSpeed(Ship *this)

{
  return *(undefined4 *)(this + 0x34);
}

// ===== Ship::getBoostTime  @0x001a394c  (4 bytes)
/* Ship::getBoostTime() */

undefined4 __thiscall Ship::getBoostTime(Ship *this)

{
  return *(undefined4 *)(this + 0x3c);
}

// ===== Ship::getBoostDelay  @0x001a3950  (4 bytes)
/* Ship::getBoostDelay() */

undefined4 __thiscall Ship::getBoostDelay(Ship *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== Ship::getAgility  @0x001a3954  (4 bytes)
/* Ship::getAgility() */

undefined4 __thiscall Ship::getAgility(Ship *this)

{
  return *(undefined4 *)(this + 0x40);
}

// ===== Ship::getFireRateFactor  @0x001a3958  (4 bytes)
/* Ship::getFireRateFactor() */

undefined4 __thiscall Ship::getFireRateFactor(Ship *this)

{
  return *(undefined4 *)(this + 0x54);
}

// ===== Ship::getDamageFactor  @0x001a395c  (4 bytes)
/* Ship::getDamageFactor() */

undefined4 __thiscall Ship::getDamageFactor(Ship *this)

{
  return *(undefined4 *)(this + 0x58);
}

// ===== Ship::hasSecondaryWeapons  @0x001a3960  (56 bytes)
/* Ship::hasSecondaryWeapons() */

undefined4 __thiscall Ship::hasSecondaryWeapons(Ship *this)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  if (((*(int *)(*(int *)(this + 0x68) + 4) != 0) &&
      (puVar2 = *(uint **)(this + 0x6c), puVar2 != (uint *)0x0)) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getType(this_00);
        if (iVar1 == 1) {
          return 1;
        }
        puVar2 = *(uint **)(this + 0x6c);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return 0;
}

// ===== Ship::hasBooster  @0x001a3998  (12 bytes)
/* Ship::hasBooster() */

bool __thiscall Ship::hasBooster(Ship *this)

{
  return 0 < *(int *)(this + 0x34);
}

// ===== Ship::hasJumpDrive  @0x001a39a4  (38 bytes)
/* Ship::hasJumpDrive() */

uint __thiscall Ship::hasJumpDrive(Ship *this)

{
  if (this[0x50] != (Ship)0x0) {
    return 1;
  }
  if (*(int *)this - 0x25U < 4) {
    return 0xbU >> (*(int *)this - 0x25U & 0xf) & 1;
  }
  return 0;
}

// ===== Ship::hasJumpDriveIntegrated  @0x001a39ca  (28 bytes)
/* Ship::hasJumpDriveIntegrated() */

uint __thiscall Ship::hasJumpDriveIntegrated(Ship *this)

{
  if (*(int *)this - 0x25U < 4) {
    return 0xbU >> (*(int *)this - 0x25U & 0xf) & 1;
  }
  return 0;
}

// ===== Ship::hasCloak  @0x001a39e6  (34 bytes)
/* Ship::hasCloak() */

bool __thiscall Ship::hasCloak(Ship *this)

{
  if (this[0x51] != (Ship)0x0) {
    return true;
  }
  return *(int *)this == 0x2c || *(int *)this == 0x31;
}

// ===== Ship::hasCloakIntegrated  @0x001a3a08  (24 bytes)
/* Ship::hasCloakIntegrated() */

bool __thiscall Ship::hasCloakIntegrated(Ship *this)

{
  return *(int *)this == 0x2c || *(int *)this == 0x31;
}

// ===== Ship::hasEmergencySystem  @0x001a3a20  (6 bytes)
/* Ship::hasEmergencySystem() */

Ship __thiscall Ship::hasEmergencySystem(Ship *this)

{
  return this[0x5c];
}

// ===== Ship::getRepairType  @0x001a3a26  (4 bytes)
/* Ship::getRepairType() */

undefined4 __thiscall Ship::getRepairType(Ship *this)

{
  return *(undefined4 *)(this + 0x4c);
}

// ===== Ship::getSignatureRace  @0x001a3a2a  (4 bytes)
/* Ship::getSignatureRace() */

undefined4 __thiscall Ship::getSignatureRace(Ship *this)

{
  return *(undefined4 *)(this + 0x60);
}

// ===== Ship::getFirePower  @0x001a3a2e  (4 bytes)
/* Ship::getFirePower() */

undefined4 __thiscall Ship::getFirePower(Ship *this)

{
  return *(undefined4 *)(this + 0x48);
}

// ===== Ship::getBaseLoad  @0x001a3a32  (4 bytes)
/* Ship::getBaseLoad() */

undefined4 __thiscall Ship::getBaseLoad(Ship *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== Ship::getCargoPlus  @0x001a3a36  (4 bytes)
/* Ship::getCargoPlus() */

undefined4 __thiscall Ship::getCargoPlus(Ship *this)

{
  return *(undefined4 *)(this + 0x28);
}

// ===== Ship::getCompression  @0x001a3a3a  (4 bytes)
/* Ship::getCompression() */

undefined4 __thiscall Ship::getCompression(Ship *this)

{
  return *(undefined4 *)(this + 0x2c);
}

// ===== Ship::getMaxLoad  @0x001a3a3e  (8 bytes)
/* Ship::getMaxLoad() */

int __thiscall Ship::getMaxLoad(Ship *this)

{
  return *(int *)(this + 0x28) + *(int *)(this + 0xc);
}

// ===== Ship::getCurrentLoad  @0x001a3a46  (4 bytes)
/* Ship::getCurrentLoad() */

undefined4 __thiscall Ship::getCurrentLoad(Ship *this)

{
  return *(undefined4 *)(this + 0x10);
}

// ===== Ship::changeLoad  @0x001a3a4c  (40 bytes)
/* Ship::changeLoad(int) */

void __thiscall Ship::changeLoad(Ship *this,int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x10);
  *(int *)(this + 0x10) = param_1 + iVar1;
  iVar1 = (*(int *)(this + 0xc) - (param_1 + iVar1)) + *(int *)(this + 0x28);
  if (*(int *)(Globals::status + 0xdc) < iVar1) {
    *(int *)(Globals::status + 0xdc) = iVar1;
  }
  return;
}

// ===== Ship::getFreeSpace  @0x001a3a78  (12 bytes)
/* Ship::getFreeSpace() */

int __thiscall Ship::getFreeSpace(Ship *this)

{
  return (*(int *)(this + 0x28) + *(int *)(this + 0xc)) - *(int *)(this + 0x10);
}

// ===== Ship::getEquipment  @0x001a3a84  (4 bytes)
/* Ship::getEquipment() */

undefined4 __thiscall Ship::getEquipment(Ship *this)

{
  return *(undefined4 *)(this + 0x6c);
}

// ===== Ship::getCargo  @0x001a3a88  (4 bytes)
/* Ship::getCargo() */

undefined4 __thiscall Ship::getCargo(Ship *this)

{
  return *(undefined4 *)(this + 0x70);
}

// ===== Ship::replaceCargo  @0x001a3a8c  (82 bytes)
/* Ship::replaceCargo(Array<Item*>*) */

void __thiscall Ship::replaceCargo(Ship *this,Array *param_1)

{
  int iVar1;
  uint uVar2;
  
  *(Array **)(this + 0x70) = param_1;
  *(undefined4 *)(this + 0x10) = 0;
  if (*(int *)param_1 != 0) {
    uVar2 = 0;
    do {
      iVar1 = Item::getAmount(*(Item **)(*(uint *)(param_1 + 4) + uVar2 * 4));
      uVar2 = uVar2 + 1;
      *(int *)(this + 0x10) = iVar1 + *(int *)(this + 0x10);
      param_1 = *(Array **)(this + 0x70);
    } while (uVar2 < *(uint *)param_1);
  }
  refreshValue(this);
  iVar1 = (*(int *)(this + 0xc) + *(int *)(this + 0x28)) - *(int *)(this + 0x10);
  if (*(int *)(Globals::status + 0xdc) < iVar1) {
    *(int *)(Globals::status + 0xdc) = iVar1;
  }
  return;
}

// ===== Ship::getFirstEquipmentOfSort  @0x001a3ae4  (90 bytes)
/* Ship::getFirstEquipmentOfSort(int) */

undefined4 __thiscall Ship::getFirstEquipmentOfSort(Ship *this,int param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x6c);
  if (puVar2 != (uint *)0x0) {
    if (*puVar2 != 0) {
      uVar3 = 0;
      do {
        this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
        if (this_00 != (Item *)0x0) {
          iVar1 = Item::getSort(this_00);
          puVar2 = *(uint **)(this + 0x6c);
          if (iVar1 == param_1) {
            return *(undefined4 *)(puVar2[1] + uVar3 * 4);
          }
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *puVar2);
    }
    if ((param_1 == 0x15) && (*(int *)this == 0x31 || *(int *)this == 0x2c)) {
      return *(undefined4 *)(*(int *)(Globals::items + 4) + 0x17c);
    }
  }
  return 0;
}

// ===== Ship::hasEquipment  @0x001a3b44  (76 bytes)
/* Ship::hasEquipment(int, int) */

undefined4 __thiscall Ship::hasEquipment(Ship *this,int param_1,int param_2)

{
  uint *puVar1;
  Item *this_00;
  int iVar2;
  uint uVar3;
  
  puVar1 = *(uint **)(this + 0x6c);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar1[1] + uVar3 * 4);
      if (((this_00 != (Item *)0x0) && (iVar2 = Item::getIndex(this_00), iVar2 == param_1)) &&
         (iVar2 = Item::getAmount(*(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + uVar3 * 4)),
         param_2 <= iVar2)) {
        return 1;
      }
      puVar1 = *(uint **)(this + 0x6c);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return 0;
}

// ===== Ship::hasVolatileGoods  @0x001a3b90  (34 bytes)
/* Ship::hasVolatileGoods() */

undefined4 __thiscall Ship::hasVolatileGoods(Ship *this)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  iVar1 = hasCargo(this,0xd1,1);
  if (iVar1 == 0) {
    uVar2 = hasCargo(this,0xcc,1);
  }
  return uVar2;
}

// ===== Ship::hasCargo  @0x001a3bb2  (76 bytes)
/* Ship::hasCargo(int, int) */

undefined4 __thiscall Ship::hasCargo(Ship *this,int param_1,int param_2)

{
  uint *puVar1;
  Item *this_00;
  int iVar2;
  uint uVar3;
  
  puVar1 = *(uint **)(this + 0x70);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar1[1] + uVar3 * 4);
      if (((this_00 != (Item *)0x0) && (iVar2 = Item::getIndex(this_00), iVar2 == param_1)) &&
         (iVar2 = Item::getAmount(*(Item **)(*(int *)(*(int *)(this + 0x70) + 4) + uVar3 * 4)),
         param_2 <= iVar2)) {
        return 1;
      }
      puVar1 = *(uint **)(this + 0x70);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return 0;
}

// ===== Ship::hasCargoType  @0x001a3bfe  (56 bytes)
/* Ship::hasCargoType(int) */

undefined4 __thiscall Ship::hasCargoType(Ship *this,int param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x70);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getType(this_00);
        if (iVar1 == param_1) {
          return 1;
        }
        puVar2 = *(uint **)(this + 0x70);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return 0;
}

// ===== Ship::removeCargo  @0x001a3c36  (40 bytes)
/* Ship::removeCargo(Item*) */

void __thiscall Ship::removeCargo(Ship *this,Item *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Item::getIndex(param_1);
  iVar2 = Item::getAmount(param_1);
  removeCargo(this,iVar1,iVar2);
  return;
}

// ===== Ship::removeCargo  @0x001a3c5e  (116 bytes)
/* Ship::removeCargo(int, int) */

undefined4 __thiscall Ship::removeCargo(Ship *this,int param_1,int param_2)

{
  int iVar1;
  Array *pAVar2;
  uint uVar3;
  
  pAVar2 = *(Array **)(this + 0x70);
  if (pAVar2 != (Array *)0x0) {
    if (*(uint *)pAVar2 != 0) {
      uVar3 = 0;
      do {
        iVar1 = Item::getIndex(*(Item **)(*(uint *)(pAVar2 + 4) + uVar3 * 4));
        if (iVar1 == param_1) {
          Item::changeAmount(*(Item **)(*(int *)(*(int *)(this + 0x70) + 4) + uVar3 * 4),-param_2);
          iVar1 = Item::getAmount(*(Item **)(*(int *)(*(int *)(this + 0x70) + 4) + uVar3 * 4));
          pAVar2 = *(Array **)(this + 0x70);
          if (iVar1 < 1) {
            pAVar2 = (Array *)Item::extractItems(pAVar2,true);
            setCargo(this,pAVar2);
            return 1;
          }
          break;
        }
        pAVar2 = *(Array **)(this + 0x70);
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)pAVar2);
    }
    setCargo(this,pAVar2);
  }
  return 0;
}

// ===== Ship::removeAllCargo  @0x001a3cd2  (30 bytes)
/* Ship::removeAllCargo() */

void __thiscall Ship::removeAllCargo(Ship *this)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(this + 0x70);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x70) = 0;
  return;
}

// ===== Ship::removeCargo  @0x001a3cf0  (12 bytes)
/* Ship::removeCargo(int) */

void __thiscall Ship::removeCargo(Ship *this,int param_1)

{
  removeCargo(this,param_1,9999999);
  return;
}

// ===== Ship::setCargo  @0x001a3cfc  (86 bytes)
/* Ship::setCargo(Array<Item*>*) */

void __thiscall Ship::setCargo(Ship *this,Array *param_1)

{
  int iVar1;
  uint uVar2;
  
  *(Array **)(this + 0x70) = param_1;
  *(undefined4 *)(this + 0x10) = 0;
  if ((param_1 != (Array *)0x0) && (*(int *)param_1 != 0)) {
    uVar2 = 0;
    do {
      iVar1 = Item::getAmount(*(Item **)(*(uint *)(param_1 + 4) + uVar2 * 4));
      uVar2 = uVar2 + 1;
      *(int *)(this + 0x10) = iVar1 + *(int *)(this + 0x10);
      param_1 = *(Array **)(this + 0x70);
    } while (uVar2 < *(uint *)param_1);
  }
  refreshValue(this);
  iVar1 = (*(int *)(this + 0xc) + *(int *)(this + 0x28)) - *(int *)(this + 0x10);
  if (*(int *)(Globals::status + 0xdc) < iVar1) {
    *(int *)(Globals::status + 0xdc) = iVar1;
  }
  return;
}

// ===== Ship::getCargo  @0x001a3d58  (60 bytes)
/* Ship::getCargo(int) */

undefined4 __thiscall Ship::getCargo(Ship *this,int param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x70);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getIndex(this_00);
        puVar2 = *(uint **)(this + 0x70);
        if (iVar1 == param_1) {
          return *(undefined4 *)(puVar2[1] + uVar3 * 4);
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return 0;
}

// ===== Ship::spaceAvailable  @0x001a3d94  (20 bytes)
/* Ship::spaceAvailable(int) */

bool __thiscall Ship::spaceAvailable(Ship *this,int param_1)

{
  return param_1 + *(int *)(this + 0x10) <= *(int *)(this + 0x28) + *(int *)(this + 0xc);
}

// ===== Ship::addCargo  @0x001a3da8  (76 bytes)
/* Ship::addCargo(Item*) */

void __thiscall Ship::addCargo(Ship *this,Item *param_1)

{
  Array *pAVar1;
  undefined4 *__ptr;
  void *pvVar2;
  
  pAVar1 = operator_new(0xc);
  __ptr = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = __ptr;
  *__ptr = 0;
  *(undefined4 *)pAVar1 = 0;
  *(undefined4 *)(pAVar1 + 8) = 1;
  pvVar2 = realloc(__ptr,4);
  *(void **)(pAVar1 + 4) = pvVar2;
  *(Item **)((int)pvVar2 + *(int *)pAVar1 * 4) = param_1;
  *(undefined4 *)pAVar1 = *(undefined4 *)(pAVar1 + 8);
  pAVar1 = (Array *)Item::combineItems(*(Array **)(this + 0x70),pAVar1);
  setCargo(this,pAVar1);
  return;
}

// ===== Ship::addCargo  @0x001a3e02  (26 bytes)
/* Ship::addCargo(Array<Item*>*) */

void __thiscall Ship::addCargo(Ship *this,Array *param_1)

{
  Array *pAVar1;
  
  pAVar1 = (Array *)Item::combineItems(*(Array **)(this + 0x70),param_1);
  setCargo(this,pAVar1);
  return;
}

// ===== Ship::replaceEquipment  @0x001a3e1a  (50 bytes)
/* Ship::replaceEquipment(Array<Item*>*) */

void __thiscall Ship::replaceEquipment(Ship *this,Array *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 != (Array *)0x0) {
    piVar1 = *(int **)(this + 0x68);
    uVar2 = *piVar1 + piVar1[3] + piVar1[1] + piVar1[2];
    if (uVar2 < *(uint *)param_1) {
      iVar3 = *(uint *)param_1 - uVar2;
      *(int *)(this + 0x7c) = iVar3;
      piVar1[3] = iVar3 + piVar1[3];
    }
  }
  *(Array **)(this + 0x6c) = param_1;
  refreshValue(this);
  return;
}

// ===== Ship::removeEquipment  @0x001a3e4c  (62 bytes)
/* Ship::removeEquipment(Item*) */

void __thiscall Ship::removeEquipment(Ship *this,Item *param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x6c);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::equals(this_00,param_1);
        puVar2 = *(uint **)(this + 0x6c);
        if (iVar1 == 1) {
          *(undefined4 *)(puVar2[1] + uVar3 * 4) = 0;
          return;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return;
}

// ===== Ship::setEquipment  @0x001a3e8a  (40 bytes)
/* Ship::setEquipment(Array<Item*>*) */

void __thiscall Ship::setEquipment(Ship *this,Array *param_1)

{
  uint uVar1;
  
  if (*(int *)param_1 != 0) {
    uVar1 = 0;
    do {
      setEquipment(this,*(Item **)(*(int *)(param_1 + 4) + uVar1 * 4));
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)param_1);
  }
  return;
}

// ===== Ship::setEquipment  @0x001a3eb2  (46 bytes)
/* Ship::setEquipment(Item*) */

void __thiscall Ship::setEquipment(Ship *this,Item *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = **(uint **)(this + 0x6c);
  if (uVar2 != 0) {
    uVar3 = (*(uint **)(this + 0x6c))[1];
    uVar1 = 0;
    do {
      if (*(int *)(uVar3 + uVar1 * 4) == 0) {
        *(Item **)(uVar3 + uVar1 * 4) = param_1;
        break;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  refreshValue(this);
  return;
}

// ===== Ship::getEquipment  @0x001a3ee0  (158 bytes)
/* Ship::getEquipment(int) */

Array * __thiscall Ship::getEquipment(Ship *this,int param_1)

{
  Array *pAVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  if ((param_1 < 4) && (iVar8 = *(int *)(this + 0x68), *(int *)(iVar8 + param_1 * 4) != 0)) {
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    iVar7 = 0;
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    ArraySetLength<Item*>(*(uint *)(iVar8 + param_1 * 4),pAVar1);
    piVar3 = *(int **)(this + 0x68);
    if (0 < param_1) {
      iVar7 = 0;
      iVar8 = param_1;
      piVar5 = piVar3;
      do {
        iVar8 = iVar8 + -1;
        iVar7 = iVar7 + *piVar5;
        piVar5 = piVar5 + 1;
      } while (iVar8 != 0);
    }
    if (0 < piVar3[param_1]) {
      uVar4 = *(uint *)pAVar1;
      uVar6 = 0;
      iVar8 = iVar7;
      do {
        if (uVar6 < uVar4) {
          *(undefined4 *)(*(int *)(pAVar1 + 4) + uVar6 * 4) =
               *(undefined4 *)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar8 * 4);
          uVar6 = uVar6 + 1;
          piVar3 = *(int **)(this + 0x68);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < piVar3[param_1] + iVar7);
    }
  }
  else {
    pAVar1 = (Array *)0x0;
  }
  return pAVar1;
}

// ===== Ship::getSlotPos  @0x001a3f8c  (88 bytes)
/* Ship::getSlotPos(Item*) */

uint __thiscall Ship::getSlotPos(Ship *this,Item *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == (Item *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar1 = **(uint **)(this + 0x6c);
    if (uVar1 != 0) {
      uVar4 = 0;
      do {
        if (*(Item **)((*(uint **)(this + 0x6c))[1] + uVar4 * 4) == param_1) goto LAB_001a3fb6;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    uVar4 = 0xffffffff;
LAB_001a3fb6:
    iVar2 = Item::getType(param_1);
    if (0 < iVar2) {
      iVar2 = 0;
      do {
        iVar3 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        uVar4 = uVar4 - *(int *)(*(int *)(this + 0x68) + iVar3);
        iVar3 = Item::getType(param_1);
      } while (iVar2 < iVar3);
    }
  }
  return uVar4;
}

// ===== Ship::addEquipment  @0x001a3fe4  (78 bytes)
/* Ship::addEquipment(Item*) */

undefined4 __thiscall Ship::addEquipment(Ship *this,Item *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = Item::getType(param_1);
  iVar3 = (*(int **)(this + 0x68))[iVar1];
  if (0 < iVar3) {
    iVar2 = 0;
    piVar4 = *(int **)(this + 0x68);
    if (0 < iVar1) {
      do {
        iVar1 = iVar1 + -1;
        iVar2 = iVar2 + *piVar4;
        piVar4 = piVar4 + 1;
      } while (iVar1 != 0);
      if (iVar3 < 1) {
        return 0;
      }
    }
    iVar3 = iVar3 + iVar2;
    do {
      if (*(int *)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar2 * 4) == 0) {
        *(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + iVar2 * 4) = param_1;
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return 0;
}

// ===== Ship::setEquipment  @0x001a4032  (100 bytes)
/* Ship::setEquipment(Item*, int) */

void __thiscall Ship::setEquipment(Ship *this,Item *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  Item *this_00;
  void *pvVar3;
  uint uVar4;
  
  iVar1 = Item::getType(param_1);
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 * 4;
      iVar1 = iVar1 + 1;
      param_2 = param_2 + *(int *)(*(int *)(this + 0x68) + iVar2);
      iVar2 = Item::getType(param_1);
    } while (iVar1 < iVar2);
  }
  if ((uint)param_2 < **(uint **)(this + 0x6c)) {
    uVar4 = (*(uint **)(this + 0x6c))[1];
    this_00 = *(Item **)(uVar4 + param_2 * 4);
    if (this_00 != (Item *)0x0) {
      pvVar3 = (void *)Item::~Item(this_00);
      operator_delete(pvVar3);
      uVar4 = *(uint *)(*(int *)(this + 0x6c) + 4);
    }
    *(undefined4 *)(uVar4 + param_2 * 4) = 0;
    *(Item **)(*(int *)(*(int *)(this + 0x6c) + 4) + param_2 * 4) = param_1;
    refreshValue(this);
    return;
  }
  return;
}

// ===== Ship::getCargoValue  @0x001a4096  (54 bytes)
/* Ship::getCargoValue() */

int __thiscall Ship::getCargoValue(Ship *this)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(this + 0x70);
  if ((puVar2 == (uint *)0x0) || (*puVar2 == 0)) {
    iVar3 = 0;
  }
  else {
    uVar4 = 0;
    iVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar4 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getTotalPrice(this_00);
        puVar2 = *(uint **)(this + 0x70);
        iVar3 = iVar3 + iVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  return iVar3;
}

// ===== Ship::getEquipmentValue  @0x001a40cc  (52 bytes)
/* Ship::getEquipmentValue() */

int __thiscall Ship::getEquipmentValue(Ship *this)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(this + 0x6c);
  if (*puVar2 == 0) {
    iVar3 = 0;
  }
  else {
    uVar4 = 0;
    iVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar4 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getTotalPrice(this_00);
        puVar2 = *(uint **)(this + 0x6c);
        iVar3 = iVar3 + iVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  return iVar3;
}

// ===== Ship::getMaxPassengers  @0x001a4100  (4 bytes)
/* Ship::getMaxPassengers() */

undefined4 __thiscall Ship::getMaxPassengers(Ship *this)

{
  return *(undefined4 *)(this + 0x44);
}

// ===== Ship::freeAllSlots  @0x001a4104  (54 bytes)
/* Ship::freeAllSlots() */

void __thiscall Ship::freeAllSlots(Ship *this)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(this + 0x6c);
  if (*puVar2 != 0) {
    uVar1 = 0;
    do {
      if (*(int *)(puVar2[1] + uVar1 * 4) != 0) {
        *(undefined4 *)(puVar2[1] + uVar1 * 4) = 0;
        puVar2 = *(uint **)(this + 0x6c);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *puVar2);
  }
  refreshValue(this);
  return;
}

// ===== Ship::freeSlot  @0x001a413a  (72 bytes)
/* Ship::freeSlot(Item*, int) */

void __thiscall Ship::freeSlot(Ship *this,Item *param_1,int param_2)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x6c);
  if (*puVar2 != 0) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::equals(this_00,param_1);
        puVar2 = *(uint **)(this + 0x6c);
        if (param_2 == uVar3 && iVar1 == 1) {
          *(undefined4 *)(puVar2[1] + param_2 * 4) = 0;
          break;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  refreshValue(this);
  return;
}

// ===== Ship::freeSlot  @0x001a4182  (68 bytes)
/* Ship::freeSlot(Item*) */

void __thiscall Ship::freeSlot(Ship *this,Item *param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(this + 0x6c);
  if (*puVar2 != 0) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::equals(this_00,param_1);
        puVar2 = *(uint **)(this + 0x6c);
        if (iVar1 == 1) {
          *(undefined4 *)(puVar2[1] + uVar3 * 4) = 0;
          break;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  refreshValue(this);
  return;
}

// ===== Ship::getSlots  @0x001a41c6  (8 bytes)
/* Ship::getSlots(int) */

undefined4 __thiscall Ship::getSlots(Ship *this,int param_1)

{
  return *(undefined4 *)(*(int *)(this + 0x68) + param_1 * 4);
}

// ===== Ship::getSlotTypes  @0x001a41ce  (24 bytes)
/* Ship::getSlotTypes() */

int __thiscall Ship::getSlotTypes(Ship *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    if (0 < *(int *)(*(int *)(this + 0x68) + iVar1)) {
      iVar2 = iVar2 + 1;
    }
  } while (iVar3 != 4);
  return iVar2;
}

// ===== Ship::getUsedSlots  @0x001a41e6  (58 bytes)
/* Ship::getUsedSlots(int) */

int __thiscall Ship::getUsedSlots(Ship *this,int param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = *(uint **)(this + 0x6c);
  if (*puVar2 == 0) {
    iVar4 = 0;
  }
  else {
    uVar3 = 0;
    iVar4 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getType(this_00);
        puVar2 = *(uint **)(this + 0x6c);
        if (iVar1 == param_1) {
          iVar4 = iVar4 + 1;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return iVar4;
}

// ===== Ship::slotAvailable  @0x001a4220  (62 bytes)
/* Ship::slotAvailable(int) */

undefined4 __thiscall Ship::slotAvailable(Ship *this,int param_1)

{
  Item *this_00;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  if (((param_1 != 0) && (param_1 != 0xc)) && (puVar2 = *(uint **)(this + 0x6c), *puVar2 != 0)) {
    uVar3 = 0;
    do {
      this_00 = *(Item **)(puVar2[1] + uVar3 * 4);
      if (this_00 != (Item *)0x0) {
        iVar1 = Item::getSort(this_00);
        if (iVar1 == param_1) {
          return 0;
        }
        puVar2 = *(uint **)(this + 0x6c);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return 1;
}

// ===== Ship::getFreeSlots  @0x001a425e  (18 bytes)
/* Ship::getFreeSlots(int) */

int __thiscall Ship::getFreeSlots(Ship *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(this + 0x68) + param_1 * 4);
  iVar1 = getUsedSlots(this,param_1);
  return iVar2 - iVar1;
}

// ===== Ship::makeShip  @0x001a4270  (18 bytes)
/* Ship::makeShip(int) */

void __thiscall Ship::makeShip(Ship *this,int param_1)

{
  int iVar1;
  
  iVar1 = clone(this);
  if (-1 < param_1) {
    *(int *)(iVar1 + 0x14) = param_1;
  }
  return;
}

// ===== Ship::clone  @0x001a4284  (118 bytes)
/* Ship::clone() */

Ship * __thiscall Ship::clone(Ship *this)

{
  Ship *this_00;
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  
  this_00 = operator_new(0x80);
  piVar1 = *(int **)(this + 0x68);
  Ship(this_00,*(int *)this,*(int *)(this + 4),*(int *)(this + 0xc),*(int *)(this + 0x14),*piVar1,
       piVar1[1],piVar1[2],piVar1[3] - *(int *)(this + 0x7c),*(float *)(this + 0x18) * 100.0);
  puVar2 = *(uint **)(this + 0x78);
  if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
    uVar3 = 0;
    do {
      addMod(this_00,*(int *)(puVar2[1] + uVar3 * 4));
      puVar2 = *(uint **)(this + 0x78);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return this_00;
}

// ===== Ship::priceDecline  @0x001a430c  (42 bytes)
/* Ship::priceDecline() */

void __thiscall Ship::priceDecline(Ship *this)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorSignedToFloat(*(undefined4 *)
                                      (*(int *)(*(int *)(Globals::ships + 4) + *(int *)this * 4) +
                                      0x14),(byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x14) = (int)(fVar1 / 1.25);
  return;
}

// ===== Ship::adjustPrice  @0x001a433c  (164 bytes)
/* Ship::adjustPrice() */

void __thiscall Ship::adjustPrice(Ship *this)

{
  int iVar1;
  SolarSystem *this_00;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  
  iVar1 = Status::getStation(Globals::status);
  if ((iVar1 != 0) && (0 < *(int *)(this + 0x14))) {
    iVar2 = **(int **)(*(int *)(Globals::ships + 4) + *(int *)this * 4);
    this_00 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar1 = SolarSystem::getRace(this_00);
    fVar4 = 0.0;
    fVar3 = (float)VectorSignedToFloat(*(undefined4 *)
                                        (*(int *)(*(int *)(Globals::ships + 4) + *(int *)this * 4) +
                                        0x14),(byte)(in_fpscr >> 0x16) & 3);
    fVar5 = fVar4;
    if (*(int *)(&DAT_0025cee4 + iVar2 * 4) == iVar1) {
      fVar5 = fVar3 * -0.01;
    }
    if (Globals::globalPriceRaise != 0) {
      fVar4 = (float)VectorSignedToFloat(Globals::globalPriceRaise,(byte)(in_fpscr >> 0x16) & 3);
      fVar4 = fVar3 * fVar4 * 0.01;
    }
    *(int *)(this + 0x14) = (int)(fVar3 + fVar5 + fVar4);
  }
  return;
}

// ===== Ship::setPrice  @0x001a4400  (4 bytes)
/* Ship::setPrice(int) */

void __thiscall Ship::setPrice(Ship *this,int param_1)

{
  *(int *)(this + 0x14) = param_1;
  return;
}

// ===== Ship::addMod  @0x001a4404  (224 bytes)
/* Ship::addMod(int) */

void __thiscall Ship::addMod(Ship *this,int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  Item *pIVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  
  puVar7 = *(uint **)(this + 0x78);
  if (puVar7 == (uint *)0x0) {
    puVar7 = operator_new(0xc);
    puVar1 = operator_new__(4);
    puVar7[1] = (uint)puVar1;
    puVar7[2] = 1;
    *puVar1 = 0;
    *puVar7 = 0;
    *(uint **)(this + 0x78) = puVar7;
  }
  if (*puVar7 == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
    do {
      iVar5 = *(int *)(puVar7[1] + uVar4 * 4);
      uVar4 = uVar4 + 1;
      if (*puVar7 <= uVar4) break;
    } while (iVar5 != param_1);
    if (iVar5 == param_1) {
      return;
    }
    uVar4 = *puVar7 + 1;
  }
  puVar7[2] = uVar4;
  pvVar2 = realloc((void *)puVar7[1],uVar4 << 2);
  puVar7[1] = (uint)pvVar2;
  *(int *)((int)pvVar2 + *puVar7 * 4) = param_1;
  uVar4 = puVar7[2];
  *puVar7 = uVar4;
  if (param_1 == 2) {
    uVar4 = *(uint *)(this + 0x7c);
  }
  if (param_1 == 2 && uVar4 == 0) {
    *(int *)(*(int *)(this + 0x68) + 0xc) = *(int *)(*(int *)(this + 0x68) + 0xc) + 1;
    *(int *)(this + 0x7c) = *(int *)(this + 0x7c) + 1;
    pIVar3 = operator_new(0x48);
    Item::Item(pIVar3,(Array *)0x0,(Array *)0x0,(Array *)0x0);
    piVar8 = *(int **)(this + 0x6c);
    piVar8[2] = *piVar8 + 1;
    pvVar2 = realloc((void *)piVar8[1],(*piVar8 + 1) * 4);
    piVar8[1] = (int)pvVar2;
    *(Item **)((int)pvVar2 + *piVar8 * 4) = pIVar3;
    *piVar8 = piVar8[2];
    iVar5 = **(int **)(this + 0x6c);
    iVar6 = (*(int **)(this + 0x6c))[1];
    pIVar3 = *(Item **)(iVar6 + iVar5 * 4 + -4);
    if (pIVar3 != (Item *)0x0) {
      pvVar2 = (void *)Item::~Item(pIVar3);
      operator_delete(pvVar2);
      iVar5 = **(int **)(this + 0x6c);
      iVar6 = (*(int **)(this + 0x6c))[1];
    }
    *(undefined4 *)(iVar6 + iVar5 * 4 + -4) = 0;
  }
  refreshValue(this);
  return;
}

// ===== Ship::equals  @0x001a44f8  (14 bytes)
/* Ship::equals(Ship*) */

bool __thiscall Ship::equals(Ship *this,Ship *param_1)

{
  return *(int *)this == *(int *)param_1;
}

// ===== Ship::getNumAddedDeviceSlots  @0x001a4506  (4 bytes)
/* Ship::getNumAddedDeviceSlots() */

undefined4 __thiscall Ship::getNumAddedDeviceSlots(Ship *this)

{
  return *(undefined4 *)(this + 0x7c);
}

// ===== Ship::getUnmoddedHandling  @0x001a450a  (4 bytes)
/* Ship::getUnmoddedHandling() */

undefined4 __thiscall Ship::getUnmoddedHandling(Ship *this)

{
  return *(undefined4 *)(this + 0x18);
}

// ===== Ship::getModdedLoad  @0x001a450e  (42 bytes)
/* Ship::getModdedLoad() */

int __thiscall Ship::getModdedLoad(Ship *this)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = *(uint **)(this + 0x78);
  iVar2 = *(int *)(this + 0xc);
  if (puVar3 != (uint *)0x0) {
    if (*puVar3 == 0) {
      return iVar2;
    }
    uVar4 = 0;
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      if (*(int *)(puVar3[1] + iVar1) == 1) {
        iVar2 = iVar2 + 0x1e;
      }
    } while (uVar4 < *puVar3);
  }
  return iVar2;
}

// ===== Ship::getMods  @0x001a4538  (4 bytes)
/* Ship::getMods() */

undefined4 __thiscall Ship::getMods(Ship *this)

{
  return *(undefined4 *)(this + 0x78);
}

// ===== Ship::setMods  @0x001a453c  (186 bytes)
/* Ship::setMods(Array<int>*) */

void __thiscall Ship::setMods(Ship *this,Array *param_1)

{
  Ship *pSVar1;
  Item *pIVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  Ship *pSVar7;
  bool bVar8;
  
  *(Array **)(this + 0x78) = param_1;
  pSVar1 = this;
  if (param_1 != (Array *)0x0) {
    pSVar1 = *(Ship **)param_1;
  }
  if (param_1 != (Array *)0x0 && pSVar1 != (Ship *)0x0) {
    pSVar7 = (Ship *)0x0;
    do {
      iVar4 = *(int *)(*(int *)(param_1 + 4) + (int)pSVar7 * 4);
      bVar8 = iVar4 == 2;
      if (bVar8) {
        iVar4 = *(int *)(this + 0x7c);
      }
      if (bVar8 && iVar4 == 0) {
        *(int *)(*(int *)(this + 0x68) + 0xc) = *(int *)(*(int *)(this + 0x68) + 0xc) + 1;
        *(int *)(this + 0x7c) = *(int *)(this + 0x7c) + 1;
        pIVar2 = operator_new(0x48);
        Item::Item(pIVar2,(Array *)0x0,(Array *)0x0,(Array *)0x0);
        piVar6 = *(int **)(this + 0x6c);
        piVar6[2] = *piVar6 + 1;
        pvVar3 = realloc((void *)piVar6[1],(*piVar6 + 1) * 4);
        piVar6[1] = (int)pvVar3;
        *(Item **)((int)pvVar3 + *piVar6 * 4) = pIVar2;
        *piVar6 = piVar6[2];
        iVar4 = **(int **)(this + 0x6c);
        iVar5 = (*(int **)(this + 0x6c))[1];
        pIVar2 = *(Item **)(iVar5 + iVar4 * 4 + -4);
        if (pIVar2 != (Item *)0x0) {
          pvVar3 = (void *)Item::~Item(pIVar2);
          operator_delete(pvVar3);
          iVar4 = **(int **)(this + 0x6c);
          iVar5 = (*(int **)(this + 0x6c))[1];
        }
        *(undefined4 *)(iVar5 + iVar4 * 4 + -4) = 0;
        pSVar1 = *(Ship **)param_1;
      }
      pSVar7 = pSVar7 + 1;
    } while (pSVar7 < pSVar1);
  }
  refreshValue(this);
  return;
}

// ===== Ship::hasModInstalled  @0x001a4602  (40 bytes)
/* Ship::hasModInstalled(int) */

undefined4 __thiscall Ship::hasModInstalled(Ship *this,int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = *(uint **)(this + 0x78);
  if ((puVar1 != (uint *)0x0) && (*puVar1 != 0)) {
    uVar2 = 0;
    do {
      if (*(int *)(puVar1[1] + uVar2 * 4) == param_1) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  return 0;
}

