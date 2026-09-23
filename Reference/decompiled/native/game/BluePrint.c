// Class: BluePrint
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== BluePrint::BluePrint  @0x001a6044  (172 bytes)
/* BluePrint::BluePrint(int) */

BluePrint * __thiscall BluePrint::BluePrint(BluePrint *this,int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  Item *this_00;
  
  AbyssEngine::String::String((String *)(this + 0x14));
  *(int *)(this + 0x1c) = param_1;
  this_00 = *(Item **)(*(int *)(Globals::items + 4) + param_1 * 4);
  iVar1 = Item::getType(this_00);
  uVar6 = 1;
  if (iVar1 == 1) {
    uVar6 = 10;
  }
  *(undefined4 *)(this + 0x20) = uVar6;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  iVar1 = Item::getQuantities(this_00);
  *(undefined4 *)this = 0;
  iVar2 = Item::getIngredients(this_00);
  if (iVar2 != 0) {
    puVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    puVar3[1] = puVar4;
    puVar3[2] = 1;
    *puVar4 = 0;
    *puVar3 = 0;
    *(undefined4 **)this = puVar3;
    puVar5 = (uint *)Item::getIngredients(this_00);
    ArraySetLength<int>(*puVar5,*(Array **)this);
    puVar5 = *(uint **)this;
    if (*puVar5 != 0) {
      uVar7 = puVar5[1];
      uVar8 = 0;
      iVar1 = *(int *)(iVar1 + 4);
      do {
        *(undefined4 *)(uVar7 + uVar8 * 4) = *(undefined4 *)(iVar1 + uVar8 * 4);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *puVar5);
    }
  }
  this[8] = (BluePrint)0x0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(this + 0x20);
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== BluePrint::~BluePrint  @0x001a6110  (68 bytes)
/* BluePrint::~BluePrint() */

BluePrint * __thiscall BluePrint::~BluePrint(BluePrint *this)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)this;
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((int)pvVar2 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar2 + 4));
      pvVar1 = *(void **)this;
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      pvVar2 = pvVar1;
      if (pvVar1 == (void *)0x0) goto LAB_001a6142;
    }
    if (*(void **)((int)pvVar2 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar2 + 4));
    }
    operator_delete(pvVar2);
  }
LAB_001a6142:
  *(undefined4 *)this = 0;
  AbyssEngine::String::~String((String *)(this + 0x14));
  return this;
}

// ===== BluePrint::addItem  @0x001a6154  (294 bytes)
/* BluePrint::addItem(Item*, int, int) */

void __thiscall BluePrint::addItem(BluePrint *this,Item *param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  Station *pSVar4;
  void *pvVar5;
  int iVar6;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_2 != 0) {
    Item::setBlueprintAmount(param_1,0);
    puVar1 = (uint *)Item::getIngredients
                               (*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4)
                               );
    uVar2 = 0;
    if (puVar1 != (uint *)0x0) {
      uVar2 = *puVar1;
    }
    if (puVar1 != (uint *)0x0 && uVar2 != 0) {
      uVar2 = 0;
      do {
        iVar6 = *(int *)(puVar1[1] + uVar2 * 4);
        iVar3 = Item::getIndex(param_1);
        if (iVar6 == iVar3) {
          *(int *)(*(int *)(*(int *)this + 4) + uVar2 * 4) =
               *(int *)(*(int *)(*(int *)this + 4) + uVar2 * 4) - param_2;
          iVar3 = Item::getSinglePrice(param_1);
          *(int *)(this + 4) = iVar3 * param_2 + *(int *)(this + 4);
          if ((-1 < param_3) && (*(int *)(this + 0x10) < 0)) {
            *(int *)(this + 0x10) = param_3;
            pSVar4 = (Station *)Status::getStation(Globals::status);
            iVar3 = Station::getIndex(pSVar4);
            if (iVar3 == param_3) {
              Status::getStation(Globals::status);
              Station::getName();
              AbyssEngine::String::operator=((String *)(this + 0x14),aSStack_30);
              AbyssEngine::String::~String(aSStack_30);
            }
            else {
              pSVar4 = (Station *)Galaxy::getStation(Globals::galaxy,param_3);
              Station::getName();
              AbyssEngine::String::operator=((String *)(this + 0x14),aSStack_30);
              AbyssEngine::String::~String(aSStack_30);
              if (pSVar4 != (Station *)0x0) {
                pvVar5 = (void *)Station::~Station(pSVar4);
                operator_delete(pvVar5);
              }
            }
          }
          break;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *puVar1);
    }
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== BluePrint::getIngredientList  @0x001a62a4  (22 bytes)
/* BluePrint::getIngredientList() */

void __thiscall BluePrint::getIngredientList(BluePrint *this)

{
  Item::getIngredients(*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4));
  return;
}

// ===== BluePrint::complete  @0x001a62bc  (28 bytes)
/* BluePrint::complete() */

void __thiscall BluePrint::complete(BluePrint *this)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = *(uint **)this;
  if (*puVar1 != 0) {
    uVar2 = puVar1[1];
    uVar3 = 0;
    do {
      *(undefined4 *)(uVar2 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return;
}

// ===== BluePrint::isCompleted  @0x001a62d8  (32 bytes)
/* BluePrint::isCompleted() */

undefined4 __thiscall BluePrint::isCompleted(BluePrint *this)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = **(uint **)this;
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      if (0 < *(int *)((*(uint **)this)[1] + uVar2 * 4)) {
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return 1;
}

// ===== BluePrint::getIndex  @0x001a62f8  (4 bytes)
/* BluePrint::getIndex() */

undefined4 __thiscall BluePrint::getIndex(BluePrint *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== BluePrint::getMoneySpent  @0x001a62fc  (4 bytes)
/* BluePrint::getMoneySpent() */

undefined4 __thiscall BluePrint::getMoneySpent(BluePrint *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== BluePrint::setMoneySpent  @0x001a6300  (4 bytes)
/* BluePrint::setMoneySpent(int) */

void __thiscall BluePrint::setMoneySpent(BluePrint *this,int param_1)

{
  *(int *)(this + 4) = param_1;
  return;
}

// ===== BluePrint::getQuantityList  @0x001a6304  (22 bytes)
/* BluePrint::getQuantityList() */

void __thiscall BluePrint::getQuantityList(BluePrint *this)

{
  Item::getQuantities(*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4));
  return;
}

// ===== BluePrint::getTotalAmount  @0x001a631c  (86 bytes)
/* BluePrint::getTotalAmount(int) */

undefined4 __thiscall BluePrint::getTotalAmount(BluePrint *this,int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  iVar1 = Item::getIngredients(*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4))
  ;
  puVar2 = (uint *)Item::getQuantities(*(Item **)(*(int *)(Globals::items + 4) +
                                                 *(int *)(this + 0x1c) * 4));
  if (*puVar2 != 0) {
    uVar3 = 0;
    do {
      if (*(int *)(*(int *)(iVar1 + 4) + uVar3 * 4) == param_1) {
        return *(undefined4 *)(puVar2[1] + uVar3 * 4);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  return 0;
}

// ===== BluePrint::getCurrentAmount  @0x001a6378  (30 bytes)
/* BluePrint::getCurrentAmount(int) */

int __thiscall BluePrint::getCurrentAmount(BluePrint *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = getTotalAmount(this,param_1);
  iVar2 = getRemainingAmount(this,param_1);
  return iVar1 - iVar2;
}

// ===== BluePrint::getRemainingAmount  @0x001a6398  (64 bytes)
/* BluePrint::getRemainingAmount(int) */

undefined4 __thiscall BluePrint::getRemainingAmount(BluePrint *this,int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = Item::getIngredients(*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4))
  ;
  uVar3 = **(uint **)this;
  if (uVar3 != 0) {
    uVar2 = 0;
    do {
      if (*(int *)(*(int *)(iVar1 + 4) + uVar2 * 4) == param_1) {
        return *(undefined4 *)((*(uint **)this)[1] + uVar2 * 4);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  return 0;
}

// ===== BluePrint::getCompletionRate  @0x001a63dc  (112 bytes)
/* BluePrint::getCompletionRate() */

float __thiscall BluePrint::getCompletionRate(BluePrint *this)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  puVar2 = (uint *)Item::getQuantities(*(Item **)(*(int *)(Globals::items + 4) +
                                                 *(int *)(this + 0x1c) * 4));
  if (*puVar2 == 0) {
    fVar5 = 0.0;
  }
  else {
    uVar3 = 0;
    fVar6 = (float)VectorUnsignedToFloat(**(undefined4 **)this,(byte)(in_fpscr >> 0x16) & 3);
    fVar5 = 0.0;
    do {
      iVar4 = *(int *)(puVar2[1] + uVar3 * 4);
      iVar1 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      fVar7 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
      fVar8 = (float)VectorSignedToFloat(iVar4 - *(int *)((*(undefined4 **)this)[1] + iVar1),
                                         (byte)(in_fpscr >> 0x16) & 3);
      fVar5 = fVar5 + (fVar8 / fVar7) / fVar6;
    } while (uVar3 < *puVar2);
  }
  return fVar5;
}

// ===== BluePrint::getIngredientsValue  @0x001a6454  (106 bytes)
/* BluePrint::getIngredientsValue() */

int __thiscall BluePrint::getIngredientsValue(BluePrint *this)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = (uint *)Item::getIngredients
                             (*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4));
  if ((puVar2 == (uint *)0x0) || (*puVar2 == 0)) {
    iVar5 = 0;
  }
  else {
    uVar4 = 0;
    iVar5 = 0;
    do {
      iVar3 = Item::getSinglePrice
                        (*(Item **)(*(int *)(Globals::items + 4) +
                                   *(int *)(puVar2[1] + uVar4 * 4) * 4));
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      iVar5 = *(int *)(*(int *)(*(int *)this + 4) + iVar1) * iVar3 + iVar5;
    } while (uVar4 < *puVar2);
  }
  return iVar5;
}

// ===== BluePrint::getAutoCompletionPrice  @0x001a64c8  (76 bytes)
/* BluePrint::getAutoCompletionPrice() */

undefined * __thiscall BluePrint::getAutoCompletionPrice(BluePrint *this)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  
  if (*(int *)(this + 0x1c) == 0xd2) {
    iVar1 = getIngredientsValue(this);
    return &UNK_001e8480 + iVar1;
  }
  iVar1 = Item::getMaxPrice(*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4));
  fVar2 = (float)VectorSignedToFloat(*(int *)(this + 0x20) * iVar1,(byte)(in_fpscr >> 0x16) & 3);
  return (undefined *)(int)(fVar2 * 1.25);
}

// ===== BluePrint::getBaseQuantity  @0x001a6518  (4 bytes)
/* BluePrint::getBaseQuantity() */

undefined4 __thiscall BluePrint::getBaseQuantity(BluePrint *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== BluePrint::getStationIndex  @0x001a651c  (4 bytes)
/* BluePrint::getStationIndex() */

undefined4 __thiscall BluePrint::getStationIndex(BluePrint *this)

{
  return *(undefined4 *)(this + 0x10);
}

// ===== BluePrint::getStationName  @0x001a6520  (14 bytes)
/* BluePrint::getStationName() */

void BluePrint::getStationName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0x14),false);
  return;
}

// ===== BluePrint::getQuantity  @0x001a652e  (4 bytes)
/* BluePrint::getQuantity() */

undefined4 __thiscall BluePrint::getQuantity(BluePrint *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== BluePrint::isUnlocked  @0x001a6532  (4 bytes)
/* BluePrint::isUnlocked() */

BluePrint __thiscall BluePrint::isUnlocked(BluePrint *this)

{
  return this[8];
}

// ===== BluePrint::unlock  @0x001a6536  (6 bytes)
/* BluePrint::unlock() */

void __thiscall BluePrint::unlock(BluePrint *this)

{
  this[8] = (BluePrint)0x1;
  return;
}

// ===== BluePrint::lock  @0x001a653c  (6 bytes)
/* BluePrint::lock() */

void __thiscall BluePrint::lock(BluePrint *this)

{
  this[8] = (BluePrint)0x1;
  return;
}

// ===== BluePrint::isEmpty  @0x001a6542  (12 bytes)
/* BluePrint::isEmpty() */

bool __thiscall BluePrint::isEmpty(BluePrint *this)

{
  return *(int *)(this + 4) == 0;
}

// ===== BluePrint::reset  @0x001a6550  (90 bytes)
/* BluePrint::reset() */

void __thiscall BluePrint::reset(BluePrint *this)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
  Status::incGoodsProduced(Globals::status,1);
  iVar1 = Item::getQuantities(*(Item **)(*(int *)(Globals::items + 4) + *(int *)(this + 0x1c) * 4));
  puVar2 = *(uint **)this;
  if (*puVar2 != 0) {
    uVar3 = puVar2[1];
    uVar4 = 0;
    iVar1 = *(int *)(iVar1 + 4);
    do {
      *(undefined4 *)(uVar3 + uVar4 * 4) = *(undefined4 *)(iVar1 + uVar4 * 4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *puVar2);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(this + 0x20);
  return;
}

