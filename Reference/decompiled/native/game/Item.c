// Class: Item
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Item::Item  @0x000f3f1c  (22 bytes)
/* Item::Item(Array<int>*, Array<int>*, Array<int>*) */

Item * __thiscall Item::Item(Item *this,Array *param_1,Array *param_2,Array *param_3)

{
  *(Array **)(this + 0x28) = param_1;
  *(Array **)(this + 0x2c) = param_2;
  *(Array **)(this + 0x30) = param_3;
  init(this);
  return this;
}

// ===== Item::init  @0x000f3f32  (78 bytes)
/* Item::init() */

void __thiscall Item::init(Item *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(this + 0x30) != 0) {
    iVar1 = *(int *)(*(int *)(this + 0x30) + 4);
    *(undefined4 *)this = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(this + 4) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(this + 8) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(this + 0x1c) = *(undefined4 *)(iVar1 + 0x34);
    iVar2 = *(int *)(iVar1 + 0x3c);
    *(int *)(this + 0x20) = iVar2;
    iVar3 = *(int *)(iVar1 + 0x44);
    *(int *)(this + 0x24) = iVar3;
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(this + 0x14) = *(undefined4 *)(iVar1 + 0x2c);
    *(int *)(this + 0x18) = iVar2 + (iVar3 - iVar2) / 2;
    *(undefined4 *)(this + 0x34) = 0;
    *(undefined4 *)(this + 0x38) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    *(undefined4 *)(this + 0x3c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    *(undefined4 *)(this + 0x40) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    this[0x44] = (Item)0x0;
  }
  return;
}

// ===== Item::~Item  @0x000f3f80  (2 bytes)
/* Item::~Item() */

Item * __thiscall Item::~Item(Item *this)

{
  return this;
}

// ===== Item::setUnsaleable  @0x000f3f82  (6 bytes)
/* Item::setUnsaleable(bool) */

void __thiscall Item::setUnsaleable(Item *this,bool param_1)

{
  this[0x44] = (Item)param_1;
  return;
}

// ===== Item::canBeInstalledMultipleTimes  @0x000f3f88  (10 bytes)
/* Item::canBeInstalledMultipleTimes() */

undefined1 __thiscall Item::canBeInstalledMultipleTimes(Item *this)

{
  return (&DAT_00254930)[*(int *)(this + 8)];
}

// ===== Item::getIndex  @0x000f3f98  (4 bytes)
/* Item::getIndex() */

undefined4 __thiscall Item::getIndex(Item *this)

{
  return *(undefined4 *)this;
}

// ===== Item::getType  @0x000f3f9c  (4 bytes)
/* Item::getType() */

undefined4 __thiscall Item::getType(Item *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== Item::getTecLevel  @0x000f3fa0  (4 bytes)
/* Item::getTecLevel() */

undefined4 __thiscall Item::getTecLevel(Item *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== Item::getSort  @0x000f3fa4  (4 bytes)
/* Item::getSort() */

undefined4 __thiscall Item::getSort(Item *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== Item::getSinglePrice  @0x000f3fa8  (4 bytes)
/* Item::getSinglePrice() */

undefined4 __thiscall Item::getSinglePrice(Item *this)

{
  return *(undefined4 *)(this + 0x18);
}

// ===== Item::getTotalPrice  @0x000f3fac  (8 bytes)
/* Item::getTotalPrice() */

int __thiscall Item::getTotalPrice(Item *this)

{
  return *(int *)(this + 0x18) * *(int *)(this + 0x34);
}

// ===== Item::getMaxPrice  @0x000f3fb4  (4 bytes)
/* Item::getMaxPrice() */

undefined4 __thiscall Item::getMaxPrice(Item *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== Item::getMinPrice  @0x000f3fb8  (4 bytes)
/* Item::getMinPrice() */

undefined4 __thiscall Item::getMinPrice(Item *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== Item::getMaxPriceSystem  @0x000f3fbc  (4 bytes)
/* Item::getMaxPriceSystem() */

undefined4 __thiscall Item::getMaxPriceSystem(Item *this)

{
  return *(undefined4 *)(this + 0x14);
}

// ===== Item::getMinPriceSystem  @0x000f3fc0  (4 bytes)
/* Item::getMinPriceSystem() */

undefined4 __thiscall Item::getMinPriceSystem(Item *this)

{
  return *(undefined4 *)(this + 0x10);
}

// ===== Item::setPrice  @0x000f3fc4  (4 bytes)
/* Item::setPrice(int) */

void __thiscall Item::setPrice(Item *this,int param_1)

{
  *(int *)(this + 0x18) = param_1;
  return;
}

// ===== Item::setMinPrice  @0x000f3fc8  (4 bytes)
/* Item::setMinPrice(int) */

void __thiscall Item::setMinPrice(Item *this,int param_1)

{
  *(int *)(this + 0x20) = param_1;
  return;
}

// ===== Item::setMaxPrice  @0x000f3fcc  (4 bytes)
/* Item::setMaxPrice(int) */

void __thiscall Item::setMaxPrice(Item *this,int param_1)

{
  *(int *)(this + 0x24) = param_1;
  return;
}

// ===== Item::getPriceRate  @0x000f3fd0  (36 bytes)
/* Item::getPriceRate() */

float __thiscall Item::getPriceRate(Item *this)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  fVar1 = (float)VectorSignedToFloat(*(int *)(this + 0x24) - *(int *)(this + 0x20),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0x18) - *(int *)(this + 0x20),
                                     (byte)(in_fpscr >> 0x16) & 3);
  return fVar2 / fVar1;
}

// ===== Item::setAmount  @0x000f3ff4  (4 bytes)
/* Item::setAmount(int) */

void __thiscall Item::setAmount(Item *this,int param_1)

{
  *(int *)(this + 0x34) = param_1;
  return;
}

// ===== Item::getOccurence  @0x000f3ff8  (4 bytes)
/* Item::getOccurence() */

undefined4 __thiscall Item::getOccurence(Item *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== Item::getAmount  @0x000f3ffc  (4 bytes)
/* Item::getAmount() */

undefined4 __thiscall Item::getAmount(Item *this)

{
  return *(undefined4 *)(this + 0x34);
}

// ===== Item::changeAmount  @0x000f4000  (8 bytes)
/* Item::changeAmount(int) */

void __thiscall Item::changeAmount(Item *this,int param_1)

{
  *(int *)(this + 0x34) = param_1 + *(int *)(this + 0x34);
  return;
}

// ===== Item::getMissingIngredients  @0x000f4008  (4 bytes)
/* Item::getMissingIngredients() */

undefined4 __thiscall Item::getMissingIngredients(Item *this)

{
  return *(undefined4 *)(this + 0x40);
}

// ===== Item::setMissingIngredients  @0x000f400c  (4 bytes)
/* Item::setMissingIngredients(int) */

void __thiscall Item::setMissingIngredients(Item *this,int param_1)

{
  *(int *)(this + 0x40) = param_1;
  return;
}

// ===== Item::setStationAmount  @0x000f4010  (4 bytes)
/* Item::setStationAmount(int) */

void __thiscall Item::setStationAmount(Item *this,int param_1)

{
  *(int *)(this + 0x38) = param_1;
  return;
}

// ===== Item::getStationAmount  @0x000f4014  (4 bytes)
/* Item::getStationAmount() */

undefined4 __thiscall Item::getStationAmount(Item *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== Item::changeStationAmount  @0x000f4018  (8 bytes)
/* Item::changeStationAmount(int) */

void __thiscall Item::changeStationAmount(Item *this,int param_1)

{
  *(int *)(this + 0x38) = param_1 + *(int *)(this + 0x38);
  return;
}

// ===== Item::setBlueprintAmount  @0x000f4020  (4 bytes)
/* Item::setBlueprintAmount(int) */

void __thiscall Item::setBlueprintAmount(Item *this,int param_1)

{
  *(int *)(this + 0x3c) = param_1;
  return;
}

// ===== Item::getBlueprintAmount  @0x000f4024  (4 bytes)
/* Item::getBlueprintAmount() */

undefined4 __thiscall Item::getBlueprintAmount(Item *this)

{
  return *(undefined4 *)(this + 0x3c);
}

// ===== Item::changeBlueprintAmount  @0x000f4028  (8 bytes)
/* Item::changeBlueprintAmount(int) */

void __thiscall Item::changeBlueprintAmount(Item *this,int param_1)

{
  *(int *)(this + 0x3c) = param_1 + *(int *)(this + 0x3c);
  return;
}

// ===== Item::getIngredients  @0x000f4030  (4 bytes)
/* Item::getIngredients() */

undefined4 __thiscall Item::getIngredients(Item *this)

{
  return *(undefined4 *)(this + 0x28);
}

// ===== Item::getQuantities  @0x000f4034  (4 bytes)
/* Item::getQuantities() */

undefined4 __thiscall Item::getQuantities(Item *this)

{
  return *(undefined4 *)(this + 0x2c);
}

// ===== Item::getAttributes  @0x000f4038  (4 bytes)
/* Item::getAttributes() */

undefined4 __thiscall Item::getAttributes(Item *this)

{
  return *(undefined4 *)(this + 0x30);
}

// ===== Item::getAttribute  @0x000f403c  (54 bytes)
/* Item::getAttribute(int) */

undefined4 __thiscall Item::getAttribute(Item *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = **(uint **)(this + 0x30);
  if (uVar2 == 0) {
    return 0xc5997825;
  }
  uVar3 = (*(uint **)(this + 0x30))[1];
  uVar1 = 0;
  do {
    if (*(int *)(uVar3 + uVar1 * 4) == param_1) {
      return *(undefined4 *)(uVar3 + uVar1 * 4 + 4);
    }
    uVar1 = uVar1 + 2;
  } while (uVar1 < uVar2);
  return 0xc5997825;
}

// ===== Item::transaction  @0x000f4074  (82 bytes)
/* Item::transaction(bool, int, bool) */

int __thiscall Item::transaction(Item *this,bool param_1,int param_2,bool param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1) {
    iVar1 = *(int *)(this + 0x38);
    if (0 < iVar1) {
      if (param_3) {
        iVar2 = *(int *)(this + 0x18);
      }
      else {
        iVar1 = Status::getCredits(Globals::status);
        iVar2 = *(int *)(this + 0x18);
        if (iVar1 < iVar2) {
          return 0;
        }
        iVar1 = *(int *)(this + 0x38);
      }
      *(int *)(this + 0x38) = iVar1 + -1;
      *(int *)(this + 0x34) = *(int *)(this + 0x34) + 1;
      return -iVar2;
    }
  }
  else if (0 < *(int *)(this + 0x34)) {
    *(int *)(this + 0x34) = *(int *)(this + 0x34) + -1;
    *(int *)(this + 0x38) = *(int *)(this + 0x38) + 1;
    return *(int *)(this + 0x18);
  }
  return 0;
}

// ===== Item::transactionBlueprint  @0x000f40cc  (50 bytes)
/* Item::transactionBlueprint(bool, int) */

int Item::transactionBlueprint(bool param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (param_2 == 1) {
    if (0 < *(int *)(uVar1 + 0x3c)) {
      *(int *)(uVar1 + 0x3c) = *(int *)(uVar1 + 0x3c) + -1;
      *(int *)(uVar1 + 0x34) = *(int *)(uVar1 + 0x34) + 1;
      return -*(int *)(uVar1 + 0x18);
    }
  }
  else if (0 < *(int *)(uVar1 + 0x34)) {
    *(int *)(uVar1 + 0x34) = *(int *)(uVar1 + 0x34) + -1;
    *(int *)(uVar1 + 0x3c) = *(int *)(uVar1 + 0x3c) + 1;
    return *(int *)(uVar1 + 0x18);
  }
  return 0;
}

// ===== Item::isInList  @0x000f40fe  (50 bytes)
/* Item::isInList(int, int, Array<Item*>*) */

undefined4 Item::isInList(int param_1,int param_2,Array *param_3)

{
  int *piVar1;
  uint uVar2;
  
  if ((param_3 != (Array *)0x0) && (*(uint *)param_3 != 0)) {
    uVar2 = 0;
    do {
      piVar1 = *(int **)(*(int *)(param_3 + 4) + uVar2 * 4);
      if ((*piVar1 == param_1) && (param_2 <= piVar1[0xd])) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)param_3);
  }
  return 0;
}

// ===== Item::isInList  @0x000f4130  (50 bytes)
/* Item::isInList(int, Array<Item*>*) */

undefined4 Item::isInList(int param_1,Array *param_2)

{
  int *piVar1;
  uint uVar2;
  
  if ((param_2 != (Array *)0x0) && (*(uint *)param_2 != 0)) {
    uVar2 = 0;
    do {
      piVar1 = *(int **)(*(int *)(param_2 + 4) + uVar2 * 4);
      if ((*piVar1 == param_1) && (0 < piVar1[0xd])) {
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)param_2);
  }
  return 0;
}

// ===== Item::isInList  @0x000f4162  (8 bytes)
/* Item::isInList(Item*, Array<Item*>*) */

void Item::isInList(Item *param_1,Array *param_2)

{
  isInList(*(int *)param_1,param_2);
  return;
}

// ===== Item::fabricate  @0x000f4168  (192 bytes)
/* Item::fabricate(Item*, Array<Item*>*, int) */

void Item::fabricate(Item *param_1,Array *param_2,int param_3)

{
  uint uVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  
  puVar13 = *(uint **)(param_1 + 0x28);
  uVar11 = *puVar13;
  if (uVar11 != 0) {
    uVar10 = 0;
    uVar9 = *(uint *)param_2;
    iVar12 = *(int *)(param_1 + 0x2c);
    uVar7 = uVar9;
    do {
      if (uVar7 == 0) {
        uVar7 = 0;
      }
      else {
        uVar1 = 0;
        do {
          piVar6 = *(int **)(*(int *)(param_2 + 4) + uVar1 * 4);
          if (*piVar6 == *(int *)(puVar13[1] + uVar10 * 4)) {
            piVar6[0xd] = piVar6[0xd] - *(int *)(*(int *)(iVar12 + 4) + uVar10 * 4) * param_3;
            break;
          }
          uVar1 = uVar1 + 1;
          uVar7 = uVar9;
        } while (uVar1 < uVar9);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar11);
  }
  pAVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar2 + 4) = puVar3;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar2 = 0;
  uVar8 = *(undefined4 *)(param_1 + 0x18);
  iVar12 = clone(param_1);
  iVar4 = *(int *)pAVar2;
  *(undefined4 *)(iVar12 + 0x18) = uVar8;
  *(int *)(pAVar2 + 8) = iVar4 + 1;
  pvVar5 = *(void **)(pAVar2 + 4);
  *(int *)(iVar12 + 0x34) = param_3;
  pvVar5 = realloc(pvVar5,(iVar4 + 1) * 4);
  *(void **)(pAVar2 + 4) = pvVar5;
  *(int *)((int)pvVar5 + *(int *)pAVar2 * 4) = iVar12;
  *(undefined4 *)pAVar2 = *(undefined4 *)(pAVar2 + 8);
  combineItems(param_2,pAVar2);
  return;
}

// ===== Item::makeItem  @0x000f4234  (18 bytes)
/* Item::makeItem(int) */

void __thiscall Item::makeItem(Item *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(this + 0x18);
  iVar1 = clone(this);
  *(undefined4 *)(iVar1 + 0x18) = uVar2;
  *(int *)(iVar1 + 0x34) = param_1;
  return;
}

// ===== Item::combineItems  @0x000f4246  (376 bytes)
/* Item::combineItems(Array<Item*>*, Array<Item*>*) */

Array * Item::combineItems(Array *param_1,Array *param_2)

{
  Array *pAVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  Array *pAVar5;
  Array *pAVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  
  pAVar6 = param_2;
  if ((param_1 != (Array *)0x0) && (pAVar6 = param_1, param_2 != (Array *)0x0)) {
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    ArraySetLength<Item*>(*(uint *)param_2,pAVar1);
    uVar3 = *(uint *)param_2;
    if (uVar3 != 0) {
      uVar7 = 0;
      do {
        *(undefined4 *)(*(int *)(pAVar1 + 4) + uVar7 * 4) =
             *(undefined4 *)(*(int *)(param_2 + 4) + uVar7 * 4);
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar3);
    }
    uVar13 = *(uint *)param_1;
    uVar7 = *(uint *)pAVar1;
    uVar3 = uVar7;
    if (uVar13 != 0) {
      uVar12 = 0;
      do {
        if (uVar7 != 0) {
          uVar8 = 0;
          do {
            iVar4 = *(int *)(pAVar1 + 4);
            piVar10 = *(int **)(iVar4 + uVar8 * 4);
            if ((piVar10 != (int *)0x0) &&
               (piVar11 = *(int **)(*(int *)(param_1 + 4) + uVar12 * 4), *piVar11 == *piVar10)) {
              uVar3 = uVar3 - 1;
              piVar11[0xd] = piVar10[0xd] + piVar11[0xd];
              *(undefined4 *)(iVar4 + uVar8 * 4) = 0;
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar7);
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar13);
    }
    if (0 < (int)uVar3) {
      pAVar5 = operator_new(0xc);
      puVar2 = operator_new__(4);
      *(undefined4 **)(pAVar5 + 4) = puVar2;
      *(undefined4 *)(pAVar5 + 8) = 1;
      *puVar2 = 0;
      *(undefined4 *)pAVar5 = 0;
      ArraySetLength<Item*>(uVar3,pAVar5);
      uVar3 = *(uint *)pAVar1;
      if (uVar3 != 0) {
        uVar7 = 0;
        iVar4 = 0;
        do {
          iVar9 = *(int *)(*(int *)(pAVar1 + 4) + uVar7 * 4);
          if (iVar9 != 0) {
            *(int *)(*(int *)(pAVar5 + 4) + iVar4 * 4) = iVar9;
            iVar4 = iVar4 + 1;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar3);
      }
      pAVar6 = operator_new(0xc);
      puVar2 = operator_new__(4);
      *(undefined4 **)(pAVar6 + 4) = puVar2;
      *(undefined4 *)(pAVar6 + 8) = 1;
      *puVar2 = 0;
      *(undefined4 *)pAVar6 = 0;
      ArraySetLength<Item*>(*(int *)param_1 + *(int *)pAVar5,pAVar6);
      uVar3 = *(uint *)param_1;
      if (uVar3 != 0) {
        uVar7 = 0;
        do {
          *(undefined4 *)(*(int *)(pAVar6 + 4) + uVar7 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 4) + uVar7 * 4);
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar3);
      }
      uVar7 = *(uint *)pAVar5;
      if (uVar7 != 0) {
        uVar13 = 0;
        do {
          *(undefined4 *)(*(int *)(pAVar6 + 4) + uVar3 * 4 + uVar13 * 4) =
               *(undefined4 *)(*(int *)(pAVar5 + 4) + uVar13 * 4);
          uVar13 = uVar13 + 1;
        } while (uVar13 < uVar7);
      }
    }
  }
  return pAVar6;
}

// ===== Item::extractItems  @0x000f43d8  (168 bytes)
/* Item::extractItems(Array<Item*>*, bool) */

int * Item::extractItems(Array *param_1,bool param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  Item *this;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  if (param_1 == (Array *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    piVar1[1] = (int)puVar2;
    piVar1[2] = 1;
    iVar5 = 0;
    *puVar2 = 0;
    *piVar1 = 0;
    if (*(int *)param_1 != 0) {
      iVar5 = 0;
      uVar7 = 0;
      do {
        this = *(Item **)(*(int *)(param_1 + 4) + uVar7 * 4);
        if (param_2) {
          iVar6 = *(int *)(this + 0x34);
        }
        else {
          iVar6 = *(int *)(this + 0x38);
        }
        if (0 < iVar6) {
          uVar8 = *(undefined4 *)(this + 0x18);
          iVar5 = clone(this);
          iVar3 = *piVar1;
          *(undefined4 *)(iVar5 + 0x18) = uVar8;
          piVar1[2] = iVar3 + 1;
          pvVar4 = (void *)piVar1[1];
          *(int *)(iVar5 + 0x34) = iVar6;
          pvVar4 = realloc(pvVar4,(iVar3 + 1) * 4);
          piVar1[1] = (int)pvVar4;
          *(int *)((int)pvVar4 + *piVar1 * 4) = iVar5;
          iVar5 = piVar1[2];
          *piVar1 = iVar5;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)param_1);
    }
    if (iVar5 == 0) {
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}

// ===== Item::combineDuplicates  @0x000f448e  (144 bytes)
/* Item::combineDuplicates(Array<Item*>*) */

void Item::combineDuplicates(Array *param_1)

{
  Item *pIVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint unaff_r9;
  uint uVar7;
  
  if (param_1 != (Array *)0x0) {
    unaff_r9 = *(uint *)param_1;
  }
  if (param_1 != (Array *)0x0 && unaff_r9 != 0) {
    uVar2 = 0;
    do {
      uVar7 = uVar2 + 1;
      if (unaff_r9 <= uVar7) break;
      iVar3 = *(int *)(param_1 + 4);
      piVar5 = *(int **)(iVar3 + uVar2 * 4);
      iVar4 = *piVar5;
      uVar2 = uVar7;
      do {
        piVar6 = *(int **)(iVar3 + uVar2 * 4);
        if (iVar4 == *piVar6) {
          piVar5[0xd] = piVar6[0xd] + piVar5[0xd];
          piVar6[0xd] = 0;
          piVar5[0xe] = piVar6[0xe] + piVar5[0xe];
          piVar6[0xe] = 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < unaff_r9);
      uVar2 = uVar7;
    } while (uVar7 < unaff_r9);
    if (unaff_r9 != 0) {
      uVar2 = 0;
      do {
        pIVar1 = *(Item **)(*(int *)(param_1 + 4) + uVar2 * 4);
        if ((*(int *)(pIVar1 + 0x34) == 0) && (*(int *)(pIVar1 + 0x38) == 0)) {
          ArrayRemove<Item*>(pIVar1,param_1);
          unaff_r9 = *(uint *)param_1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < unaff_r9);
    }
  }
  return;
}

// ===== Item::mixItems  @0x000f4560  (582 bytes)
/* Item::mixItems(Array<Item*>*, Array<Item*>*) */

Array * Item::mixItems(Array *param_1,Array *param_2)

{
  bool bVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  Item *pIVar4;
  Array *pAVar5;
  void *pvVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  
  if (param_1 == (Array *)0x0) {
    uVar9 = 0;
  }
  else {
    uVar9 = *(uint *)param_1;
  }
  if (param_2 == (Array *)0x0) {
    iVar16 = 0;
  }
  else {
    iVar16 = *(int *)param_2;
  }
  pAVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  *(undefined4 **)(pAVar2 + 4) = puVar3;
  *(undefined4 *)(pAVar2 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar2 = 0;
  ArraySetLength<Item*>(iVar16 + uVar9,pAVar2);
  if (((int)uVar9 < 1) || (iVar16 != 0)) {
    if ((uVar9 == 0) && (0 < iVar16)) {
      if (*(int *)param_2 != 0) {
        iVar16 = *(int *)(param_2 + 4);
        uVar9 = 0;
        do {
          pIVar4 = *(Item **)(iVar16 + uVar9 * 4);
          uVar10 = *(undefined4 *)(pIVar4 + 0x18);
          iVar16 = clone(pIVar4);
          iVar7 = *(int *)(pAVar2 + 4);
          *(undefined4 *)(iVar16 + 0x18) = uVar10;
          *(undefined4 *)(iVar16 + 0x34) = 0;
          *(int *)(iVar7 + uVar9 * 4) = iVar16;
          iVar16 = *(int *)(param_2 + 4);
          iVar7 = uVar9 * 4;
          iVar11 = uVar9 * 4;
          uVar9 = uVar9 + 1;
          *(undefined4 *)(*(int *)(*(int *)(pAVar2 + 4) + iVar11) + 0x38) =
               *(undefined4 *)(*(int *)(iVar16 + iVar7) + 0x34);
        } while (uVar9 < *(uint *)param_2);
      }
    }
    else if (iVar16 == 0 && uVar9 == 0) {
      pAVar2 = (Array *)0x0;
    }
    else {
      if (*(int *)param_1 != 0) {
        uVar14 = 0;
        do {
          pIVar4 = *(Item **)(*(int *)(param_1 + 4) + uVar14 * 4);
          uVar13 = *(undefined4 *)(pIVar4 + 0x18);
          uVar10 = *(undefined4 *)(pIVar4 + 0x34);
          iVar16 = clone(pIVar4);
          iVar7 = *(int *)(pAVar2 + 4);
          *(undefined4 *)(iVar16 + 0x18) = uVar13;
          *(undefined4 *)(iVar16 + 0x34) = uVar10;
          *(int *)(iVar7 + uVar14 * 4) = iVar16;
          uVar14 = uVar14 + 1;
        } while (uVar14 < *(uint *)param_1);
      }
      if (*(int *)param_2 != 0) {
        uVar14 = 0;
        do {
          if (*(uint *)pAVar2 != 0) {
            uVar15 = 0;
            pIVar4 = *(Item **)(*(int *)(param_2 + 4) + uVar14 * 4);
            do {
              piVar8 = *(int **)(*(int *)(pAVar2 + 4) + uVar15 * 4);
              if (piVar8 == (int *)0x0) {
                uVar10 = *(undefined4 *)(pIVar4 + 0x18);
                iVar16 = clone(pIVar4);
                *(undefined4 *)(iVar16 + 0x18) = uVar10;
                *(undefined4 *)(iVar16 + 0x34) = 0;
                uVar9 = uVar9 + 1;
                iVar7 = *(int *)(pAVar2 + 4);
LAB_000f46d0:
                *(int *)(iVar7 + uVar15 * 4) = iVar16;
                *(undefined4 *)(*(int *)(*(int *)(pAVar2 + 4) + uVar15 * 4) + 0x38) =
                     *(undefined4 *)(*(int *)(*(int *)(param_2 + 4) + uVar14 * 4) + 0x34);
                break;
              }
              if (*(int *)pIVar4 == *piVar8) {
                iVar11 = piVar8[0xd];
                uVar10 = *(undefined4 *)(pIVar4 + 0x18);
                iVar16 = clone(pIVar4);
                iVar7 = *(int *)(pAVar2 + 4);
                *(undefined4 *)(iVar16 + 0x18) = uVar10;
                *(int *)(iVar16 + 0x34) = iVar11;
                goto LAB_000f46d0;
              }
              uVar15 = uVar15 + 1;
            } while (uVar15 < *(uint *)pAVar2);
          }
          uVar14 = uVar14 + 1;
        } while (uVar14 < *(uint *)param_2);
      }
      pAVar5 = operator_new(0xc);
      puVar3 = operator_new__(4);
      *(undefined4 **)(pAVar5 + 4) = puVar3;
      *(undefined4 *)(pAVar5 + 8) = 1;
      *puVar3 = 0;
      *(undefined4 *)pAVar5 = 0;
      ArraySetLength<Item*>(uVar9,pAVar5);
      pvVar6 = *(void **)(pAVar2 + 4);
      if (0 < (int)uVar9) {
        uVar14 = 0;
        do {
          *(undefined4 *)(*(int *)(pAVar5 + 4) + uVar14 * 4) =
               *(undefined4 *)((int)pvVar6 + uVar14 * 4);
          uVar14 = uVar14 + 1;
          pvVar6 = *(void **)(pAVar2 + 4);
        } while (uVar9 != uVar14);
      }
      if (pvVar6 != (void *)0x0) {
        operator_delete__(pvVar6);
      }
      operator_delete(pAVar2);
      uVar9 = *(uint *)pAVar5;
      if (1 < uVar9) {
        do {
          bVar1 = true;
          iVar16 = 0;
          do {
            iVar7 = *(int *)(pAVar5 + 4);
            piVar8 = *(int **)(iVar7 + iVar16 * 4);
            piVar12 = *(int **)(iVar7 + iVar16 * 4 + 4);
            if (*piVar12 < *piVar8) {
              *(int **)(iVar7 + iVar16 * 4) = piVar12;
              bVar1 = false;
              *(int **)(*(int *)(pAVar5 + 4) + iVar16 * 4 + 4) = piVar8;
            }
            uVar14 = iVar16 + 2;
            iVar16 = iVar16 + 1;
          } while (uVar14 < uVar9);
        } while (!bVar1);
      }
      combineDuplicates(pAVar5);
      pAVar2 = pAVar5;
    }
  }
  else if (*(int *)param_1 != 0) {
    uVar9 = 0;
    do {
      pIVar4 = *(Item **)(*(int *)(param_1 + 4) + uVar9 * 4);
      uVar10 = *(undefined4 *)(pIVar4 + 0x18);
      uVar13 = *(undefined4 *)(pIVar4 + 0x34);
      iVar16 = clone(pIVar4);
      iVar7 = *(int *)(pAVar2 + 4);
      *(undefined4 *)(iVar16 + 0x18) = uVar10;
      *(undefined4 *)(iVar16 + 0x34) = uVar13;
      *(int *)(iVar7 + uVar9 * 4) = iVar16;
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)param_1);
  }
  return pAVar2;
}

// ===== Item::equals  @0x000f47ba  (18 bytes)
/* Item::equals(Item*) */

undefined4 __thiscall Item::equals(Item *this,Item *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (Item *)0x0) && (*(int *)this == *(int *)param_1)) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== Item::isWeapon  @0x000f47cc  (12 bytes)
/* Item::isWeapon() */

bool __thiscall Item::isWeapon(Item *this)

{
  return *(uint *)(this + 4) < 3;
}

// ===== Item::makeItem  @0x000f47d8  (18 bytes)
/* Item::makeItem(int, int) */

void __thiscall Item::makeItem(Item *this,int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = clone(this);
  *(int *)(iVar1 + 0x18) = param_2;
  *(int *)(iVar1 + 0x34) = param_1;
  return;
}

// ===== Item::clone  @0x000f47ea  (56 bytes)
/* Item::clone() */

Item * __thiscall Item::clone(Item *this)

{
  Item *this_00;
  undefined4 uVar1;
  undefined4 uVar2;
  
  this_00 = operator_new(0x48);
  uVar1 = *(undefined4 *)(this + 0x2c);
  uVar2 = *(undefined4 *)(this + 0x30);
  *(undefined4 *)(this_00 + 0x28) = *(undefined4 *)(this + 0x28);
  *(undefined4 *)(this_00 + 0x2c) = uVar1;
  *(undefined4 *)(this_00 + 0x30) = uVar2;
  init(this_00);
  *(undefined4 *)(this_00 + 0x18) = *(undefined4 *)(this + 0x18);
  this_00[0x44] = this[0x44];
  *(undefined4 *)(this_00 + 0x34) = *(undefined4 *)(this + 0x34);
  *(undefined4 *)(this_00 + 0x38) = *(undefined4 *)(this + 0x38);
  return this_00;
}

// ===== Item::makeItem  @0x000f4822  (18 bytes)
/* Item::makeItem() */

void __thiscall Item::makeItem(Item *this)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(this + 0x18);
  iVar1 = clone(this);
  *(undefined4 *)(iVar1 + 0x18) = uVar2;
  *(undefined4 *)(iVar1 + 0x34) = 1;
  return;
}

// ===== Item::checkCredits  @0x000f4834  (32 bytes)
/* Item::checkCredits() */

bool __thiscall Item::checkCredits(Item *this)

{
  int iVar1;
  
  iVar1 = Status::getCredits(Globals::status);
  return *(int *)(this + 0x18) <= iVar1;
}

// ===== Item::adjustPrice  @0x000f4858  (66 bytes)
/* Item::adjustPrice(Station*) */

void __thiscall Item::adjustPrice(Item *this,Station *param_1)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  
  iVar2 = *(int *)(this + 0x20);
  iVar1 = Station::getTecLevel(param_1);
  fVar3 = (float)VectorSignedToFloat(10 - iVar1,(byte)(in_fpscr >> 0x16) & 3);
  fVar4 = (float)VectorSignedToFloat(*(int *)(this + 0x24) - *(int *)(this + 0x20),
                                     (byte)(in_fpscr >> 0x16) & 3);
  *(int *)(this + 0x18) = (int)((fVar3 / 10.0) * fVar4) + iVar2;
  return;
}

// ===== Item::checkCargoSpace  @0x000f489c  (50 bytes)
/* Item::checkCargoSpace() */

bool __thiscall Item::checkCargoSpace(Item *this)

{
  Ship *pSVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  pSVar1 = (Ship *)Status::getShip(Globals::status);
  iVar2 = Ship::getCurrentLoad(pSVar1);
  iVar4 = *(int *)(this + 0x34);
  pSVar1 = (Ship *)Status::getShip(Globals::status);
  iVar3 = Ship::getMaxLoad(pSVar1);
  return iVar4 + iVar2 <= iVar3;
}

// ===== Item::isUnsaleable  @0x000f48d4  (6 bytes)
/* Item::isUnsaleable() */

Item __thiscall Item::isUnsaleable(Item *this)

{
  return this[0x44];
}

