// Class: HangarList
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== HangarList::HangarList  @0x00142b88  (10 bytes)
/* HangarList::HangarList() */

void __thiscall HangarList::HangarList(HangarList *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}

// ===== HangarList::~HangarList  @0x00142b92  (14 bytes)
/* HangarList::~HangarList() */

HangarList * __thiscall HangarList::~HangarList(HangarList *this)

{
  release(this);
  return this;
}

// ===== HangarList::release  @0x00142ba0  (112 bytes)
/* HangarList::release() */

void __thiscall HangarList::release(HangarList *this)

{
  Array *pAVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  pAVar1 = *(Array **)this;
  if (pAVar1 != (Array *)0x0) {
    if (*(int *)pAVar1 != 0) {
      uVar4 = 0;
      do {
        iVar2 = *(int *)(pAVar1 + 4);
        pAVar1 = *(Array **)(iVar2 + uVar4 * 4);
        if (pAVar1 != (Array *)0x0) {
          if (*(int *)pAVar1 != 0) {
            ArrayReleaseClasses<ListItem*>(pAVar1);
            iVar2 = *(int *)(*(int *)this + 4);
            pAVar1 = *(Array **)(iVar2 + uVar4 * 4);
            if (pAVar1 == (Array *)0x0) goto LAB_00142be4;
          }
          if (*(void **)(pAVar1 + 4) != (void *)0x0) {
            operator_delete__(*(void **)(pAVar1 + 4));
          }
          operator_delete(pAVar1);
          iVar2 = *(int *)(*(int *)this + 4);
        }
LAB_00142be4:
        *(undefined4 *)(iVar2 + uVar4 * 4) = 0;
        uVar4 = uVar4 + 1;
        pAVar1 = *(Array **)this;
      } while (uVar4 < *(uint *)pAVar1);
    }
    ArrayReleaseClasses<Array<ListItem*>*>(pAVar1);
    pvVar3 = *(void **)this;
    if (pvVar3 != (void *)0x0) {
      if (*(void **)((int)pvVar3 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar3 + 4));
      }
      operator_delete(pvVar3);
    }
  }
  *(undefined4 *)this = 0;
  return;
}

// ===== HangarList::initShipTab  @0x00142c98  (674 bytes)
/* HangarList::initShipTab(Ship*) */

void __thiscall HangarList::initShipTab(HangarList *this,Ship *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  ListItem *pLVar8;
  String *pSVar9;
  int iVar10;
  uint uVar11;
  Array *pAVar12;
  uint uVar13;
  undefined4 uVar14;
  uint *local_30;
  
  puVar2 = *(undefined4 **)(*(int *)this + 4);
  pAVar12 = (Array *)*puVar2;
  if (pAVar12 != (Array *)0x0) {
    if (*(int *)pAVar12 != 0) {
      ArrayReleaseClasses<ListItem*>(pAVar12);
      puVar2 = *(undefined4 **)(*(int *)this + 4);
      pAVar12 = (Array *)*puVar2;
      if (pAVar12 == (Array *)0x0) goto LAB_00142cd6;
    }
    if (*(void **)(pAVar12 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar12 + 4));
    }
    operator_delete(pAVar12);
    puVar2 = *(undefined4 **)(*(int *)this + 4);
  }
LAB_00142cd6:
  *puVar2 = 0;
  pAVar12 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar12 + 4) = puVar2;
  bVar1 = true;
  *puVar2 = 0;
  *(undefined4 *)(pAVar12 + 8) = 1;
  *(undefined4 *)pAVar12 = 0;
  puVar3 = (uint *)Ship::getEquipment(param_1);
  puVar4 = (uint *)Ship::getCargo(param_1);
  if (puVar4 == (uint *)0x0) {
    local_30 = (uint *)0x0;
  }
  else {
    local_30 = operator_new(0xc);
    puVar2 = operator_new__(4);
    bVar1 = false;
    local_30[1] = (uint)puVar2;
    local_30[2] = 1;
    *puVar2 = 0;
    *local_30 = 0;
    if (*puVar4 != 0) {
      uVar13 = 0;
      do {
        iVar5 = Item::getType(*(Item **)(puVar4[1] + uVar13 * 4));
        if (iVar5 != 4) {
          iVar5 = Item::getType(*(Item **)(puVar4[1] + uVar13 * 4));
          iVar5 = Ship::getSlots(param_1,iVar5);
          if (0 < iVar5) {
            uVar14 = *(undefined4 *)(puVar4[1] + uVar13 * 4);
            local_30[2] = *local_30 + 1;
            pvVar6 = realloc((void *)local_30[1],(*local_30 + 1) * 4);
            local_30[1] = (uint)pvVar6;
            *(undefined4 *)((int)pvVar6 + *local_30 * 4) = uVar14;
            *local_30 = local_30[2];
          }
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *puVar4);
      bVar1 = false;
      iVar5 = *local_30 + 2;
      goto LAB_00142d88;
    }
  }
  iVar5 = 2;
LAB_00142d88:
  uVar13 = *puVar3;
  iVar7 = Ship::getSlotTypes(param_1);
  ArraySetLength<ListItem*>(iVar7 + iVar5 + uVar13,pAVar12);
  pLVar8 = operator_new(0x48);
  pSVar9 = (String *)GameText::getText(Globals::gameText,0xb7);
  ::ListItem::ListItem(pLVar8,pSVar9);
  **(undefined4 **)(pAVar12 + 4) = pLVar8;
  pLVar8 = operator_new(0x48);
  ::ListItem::ListItem(pLVar8,param_1);
  iVar5 = 2;
  iVar7 = 0;
  *(ListItem **)(*(int *)(pAVar12 + 4) + 4) = pLVar8;
  do {
    iVar10 = Ship::getSlots(param_1,iVar7);
    if (0 < iVar10) {
      pLVar8 = operator_new(0x48);
      if (iVar7 == 0) {
        iVar10 = 0x109;
      }
      else if (iVar7 == 1) {
        iVar10 = 0x10a;
      }
      else if (iVar7 == 2) {
        iVar10 = 0x10b;
      }
      else {
        iVar10 = 0x10e;
        if (iVar7 == 3) {
          iVar10 = 0x10d;
        }
      }
      pSVar9 = (String *)GameText::getText(Globals::gameText,iVar10);
      ::ListItem::ListItem(pLVar8,pSVar9,iVar7);
      *(ListItem **)(*(int *)(pAVar12 + 4) + iVar5 * 4) = pLVar8;
      puVar4 = (uint *)Ship::getEquipment(param_1,iVar7);
      iVar5 = iVar5 + 1;
      pvVar6 = (void *)puVar4[1];
      if (*puVar4 != 0) {
        uVar13 = 0;
        do {
          iVar10 = *(int *)((int)pvVar6 + uVar13 * 4);
          pLVar8 = operator_new(0x48);
          if (iVar10 == 0) {
            ::ListItem::ListItem(pLVar8,iVar7);
          }
          else {
            ::ListItem::ListItem(pLVar8,*(Item **)(puVar4[1] + uVar13 * 4));
          }
          *(ListItem **)(*(int *)(pAVar12 + 4) + iVar5 * 4) = pLVar8;
          if (*puVar3 == 0) {
            iVar10 = *(int *)(*(int *)(pAVar12 + 4) + iVar5 * 4);
          }
          else {
            iVar10 = *(int *)(*(int *)(pAVar12 + 4) + iVar5 * 4);
            uVar11 = 0;
            do {
              if (*(int *)(puVar3[1] + uVar11 * 4) == *(int *)(iVar10 + 0x10)) {
                *(uint *)(iVar10 + 0x40) = uVar11;
                break;
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 < *puVar3);
          }
          *(uint *)(iVar10 + 0x3c) = uVar13;
          iVar5 = iVar5 + 1;
          pvVar6 = (void *)puVar4[1];
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar4);
      }
      if (pvVar6 != (void *)0x0) {
        operator_delete__(pvVar6);
      }
      operator_delete(puVar4);
      if ((!bVar1) && (*local_30 != 0)) {
        uVar13 = 0;
        do {
          iVar10 = Item::getType(*(Item **)(local_30[1] + uVar13 * 4));
          if (iVar10 == iVar7) {
            pLVar8 = operator_new(0x48);
            ::ListItem::ListItem(pLVar8,*(Item **)(local_30[1] + uVar13 * 4));
            *(ListItem **)(*(int *)(pAVar12 + 4) + iVar5 * 4) = pLVar8;
            iVar5 = iVar5 + 1;
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *local_30);
      }
    }
    iVar7 = iVar7 + 1;
    if (3 < iVar7) {
      **(undefined4 **)(*(int *)this + 4) = pAVar12;
      return;
    }
  } while( true );
}

// ===== HangarList::initShopTab  @0x00142f9c  (578 bytes)
/* HangarList::initShopTab(Array<Item*>*, Array<Ship*>*) */

void __thiscall HangarList::initShopTab(HangarList *this,Array *param_1,Array *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  ListItem *pLVar4;
  String *pSVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  Array *pAVar10;
  int local_40 [6];
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar1 = *(int *)(*(int *)this + 4);
  pAVar10 = *(Array **)(iVar1 + 4);
  if (pAVar10 != (Array *)0x0) {
    if (*(int *)pAVar10 != 0) {
      ArrayReleaseClasses<ListItem*>(pAVar10);
      iVar1 = *(int *)(*(int *)this + 4);
      pAVar10 = *(Array **)(iVar1 + 4);
      if (pAVar10 == (Array *)0x0) goto LAB_00142fe0;
    }
    if (*(void **)(pAVar10 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar10 + 4));
    }
    operator_delete(pAVar10);
    iVar1 = *(int *)(*(int *)this + 4);
  }
LAB_00142fe0:
  *(undefined4 *)(iVar1 + 4) = 0;
  if (param_1 != (Array *)0x0) {
    iVar1 = *(int *)param_1;
  }
  if ((param_1 != (Array *)0x0 && iVar1 != 0) ||
     ((param_2 != (Array *)0x0 && (*(int *)param_2 != 0)))) {
    pAVar10 = operator_new(0xc);
    puVar2 = operator_new__(4);
    *(undefined4 **)(pAVar10 + 4) = puVar2;
    *(undefined4 *)(pAVar10 + 8) = 1;
    *puVar2 = 0;
    local_40[0] = 0;
    local_40[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_40[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    local_40[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    piVar3 = local_40 + 4;
    *(undefined4 *)pAVar10 = 0;
    local_40[4] = 0;
    if (param_1 != (Array *)0x0) {
      piVar3 = *(int **)param_1;
    }
    if (param_1 != (Array *)0x0 && piVar3 != (int *)0x0) {
      uVar8 = 0;
      do {
        iVar1 = Item::getType(*(Item **)(*(int *)(param_1 + 4) + uVar8 * 4));
        uVar8 = uVar8 + 1;
        local_40[iVar1] = local_40[iVar1] + 1;
      } while (uVar8 < *(uint *)param_1);
    }
    iVar6 = 0;
    iVar1 = 0;
    do {
      piVar3 = local_40 + iVar6;
      iVar6 = iVar6 + 1;
      if (0 < *piVar3) {
        iVar1 = iVar1 + 1;
      }
    } while (iVar6 != 5);
    if ((param_2 != (Array *)0x0) && (*(int *)param_2 != 0)) {
      iVar1 = iVar1 + *(int *)param_2 + 1;
    }
    if (param_1 == (Array *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)param_1;
    }
    ArraySetLength<ListItem*>(iVar1 + iVar6,pAVar10);
    if ((param_2 == (Array *)0x0) || (*(int *)param_2 == 0)) {
      iVar1 = 0;
    }
    else {
      pLVar4 = operator_new(0x48);
      pSVar5 = (String *)GameText::getText(Globals::gameText,0xad);
      ::ListItem::ListItem(pLVar4,pSVar5,-1);
      **(undefined4 **)(pAVar10 + 4) = pLVar4;
      if (*(int *)param_2 == 0) {
        iVar1 = 1;
      }
      else {
        uVar8 = 0;
        do {
          uVar9 = uVar8;
          Ship::adjustPrice(*(Ship **)(*(int *)(param_2 + 4) + uVar9 * 4));
          pLVar4 = operator_new(0x48);
          ::ListItem::ListItem(pLVar4,*(Ship **)(*(int *)(param_2 + 4) + uVar9 * 4));
          *(ListItem **)(*(int *)(pAVar10 + 4) + uVar9 * 4 + 4) = pLVar4;
          uVar8 = uVar9 + 1;
        } while (uVar9 + 1 < *(uint *)param_2);
        iVar1 = uVar9 + 2;
      }
    }
    iVar6 = 0;
    do {
      if (0 < local_40[iVar6]) {
        pLVar4 = operator_new(0x48);
        if (iVar6 == 0) {
          iVar7 = 0x109;
        }
        else if (iVar6 == 1) {
          iVar7 = 0x10a;
        }
        else if (iVar6 == 2) {
          iVar7 = 0x10b;
        }
        else {
          iVar7 = 0x10e;
          if (iVar6 == 3) {
            iVar7 = 0x10d;
          }
        }
        pSVar5 = (String *)GameText::getText(Globals::gameText,iVar7);
        ::ListItem::ListItem(pLVar4,pSVar5,iVar6);
        iVar7 = *(int *)(pAVar10 + 4);
        *(ListItem **)(iVar7 + iVar1 * 4) = pLVar4;
        iVar1 = iVar1 + 1;
        if (param_1 != (Array *)0x0) {
          iVar7 = *(int *)param_1;
        }
        if (param_1 != (Array *)0x0 && iVar7 != 0) {
          uVar8 = 0;
          do {
            iVar7 = Item::getType(*(Item **)(*(int *)(param_1 + 4) + uVar8 * 4));
            if (iVar7 == iVar6) {
              pLVar4 = operator_new(0x48);
              ::ListItem::ListItem(pLVar4,*(Item **)(*(int *)(param_1 + 4) + uVar8 * 4));
              *(ListItem **)(*(int *)(pAVar10 + 4) + iVar1 * 4) = pLVar4;
              iVar1 = iVar1 + 1;
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(uint *)param_1);
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 5);
    *(Array **)(*(int *)(*(int *)this + 4) + 4) = pAVar10;
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== HangarList::initBlueprintTab  @0x00143208  (444 bytes)
/* HangarList::initBlueprintTab(Array<BluePrint*>*) */

void __thiscall HangarList::initBlueprintTab(HangarList *this,Array *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  ListItem *pLVar5;
  String *pSVar6;
  int iVar7;
  uint uVar8;
  Array *pAVar9;
  uint uVar10;
  uint uVar11;
  
  iVar2 = *(int *)(*(int *)this + 4);
  pAVar9 = *(Array **)(iVar2 + 8);
  if (pAVar9 != (Array *)0x0) {
    if (*(int *)pAVar9 != 0) {
      ArrayReleaseClasses<ListItem*>(pAVar9);
      iVar2 = *(int *)(*(int *)this + 4);
      pAVar9 = *(Array **)(iVar2 + 8);
      if (pAVar9 == (Array *)0x0) goto LAB_00143246;
    }
    if (*(void **)(pAVar9 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar9 + 4));
    }
    operator_delete(pAVar9);
    iVar2 = *(int *)(*(int *)this + 4);
  }
LAB_00143246:
  *(undefined4 *)(iVar2 + 8) = 0;
  pAVar9 = operator_new(0xc);
  puVar3 = operator_new__(4);
  uVar10 = 1;
  *(undefined4 **)(pAVar9 + 4) = puVar3;
  *(undefined4 *)(pAVar9 + 8) = 1;
  *puVar3 = 0;
  *(undefined4 *)pAVar9 = 0;
  if (*(int *)param_1 != 0) {
    uVar10 = 1;
    uVar11 = 0;
    do {
      iVar2 = BluePrint::isUnlocked(*(BluePrint **)(*(int *)(param_1 + 4) + uVar11 * 4));
      if (iVar2 != 0) {
        uVar10 = uVar10 + 1;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(uint *)param_1);
  }
  puVar4 = (uint *)Status::getPendingProducts(Globals::status);
  uVar11 = uVar10;
  if (puVar4 == (uint *)0x0) {
    bVar1 = true;
  }
  else {
    if (*puVar4 != 0) {
      uVar8 = 0;
      do {
        iVar2 = uVar8 * 4;
        uVar8 = uVar8 + 1;
        if (*(int *)(puVar4[1] + iVar2) != 0) {
          uVar11 = uVar11 + 1;
        }
      } while (uVar8 < *puVar4);
    }
    bVar1 = (int)uVar11 <= (int)uVar10;
    if ((int)uVar10 < (int)uVar11) {
      uVar11 = uVar11 + 1;
    }
  }
  ArraySetLength<ListItem*>(uVar11,pAVar9);
  pLVar5 = operator_new(0x48);
  pSVar6 = (String *)GameText::getText(Globals::gameText,0x111);
  ::ListItem::ListItem(pLVar5,pSVar6);
  **(undefined4 **)(pAVar9 + 4) = pLVar5;
  iVar2 = 1;
  if (*(int *)param_1 != 0) {
    uVar10 = 0;
    do {
      iVar7 = BluePrint::isUnlocked(*(BluePrint **)(*(int *)(param_1 + 4) + uVar10 * 4));
      if (iVar7 == 1) {
        pLVar5 = operator_new(0x48);
        ::ListItem::ListItem(pLVar5,*(BluePrint **)(*(int *)(param_1 + 4) + uVar10 * 4));
        *(ListItem **)(*(int *)(pAVar9 + 4) + iVar2 * 4) = pLVar5;
        iVar2 = iVar2 + 1;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(uint *)param_1);
  }
  if (!bVar1) {
    pLVar5 = operator_new(0x48);
    pSVar6 = (String *)GameText::getText(Globals::gameText,0x112);
    ::ListItem::ListItem(pLVar5,pSVar6);
    *(ListItem **)(*(int *)(pAVar9 + 4) + iVar2 * 4) = pLVar5;
    uVar10 = *puVar4;
    if (uVar10 != 0) {
      iVar2 = iVar2 + 1;
      uVar11 = 0;
      do {
        if (*(int *)(puVar4[1] + uVar11 * 4) != 0) {
          pLVar5 = operator_new(0x48);
          ::ListItem::ListItem(pLVar5,*(PendingProduct **)(puVar4[1] + uVar11 * 4));
          *(ListItem **)(*(int *)(pAVar9 + 4) + iVar2 * 4) = pLVar5;
          iVar2 = iVar2 + 1;
          uVar10 = *puVar4;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar10);
    }
  }
  *(Array **)(*(int *)(*(int *)this + 4) + 8) = pAVar9;
  return;
}

// ===== HangarList::init  @0x001433f4  (88 bytes)
/* HangarList::init(Ship*, Array<Item*>*, Array<Ship*>*, Array<BluePrint*>*) */

void __thiscall
HangarList::init(HangarList *this,Ship *param_1,Array *param_2,Array *param_3,Array *param_4)

{
  Array *pAVar1;
  undefined4 *puVar2;
  
  release(this);
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  *(Array **)this = pAVar1;
  ArraySetLength<Array<ListItem*>*>(5,pAVar1);
  initShipTab(this,param_1);
  initShopTab(this,param_2,param_3);
  initBlueprintTab(this,param_4);
  return;
}

// ===== HangarList::fillBuyList  @0x0014348c  (694 bytes)
/* HangarList::fillBuyList(ListItem*) */

void __thiscall HangarList::fillBuyList(HangarList *this,ListItem *param_1)

{
  int iVar1;
  Station *pSVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  ListItem *pLVar8;
  String *pSVar9;
  uint *puVar10;
  Ship *pSVar11;
  Array *pAVar12;
  int iVar13;
  int iVar14;
  
  iVar1 = *(int *)(*(int *)this + 4);
  pAVar12 = *(Array **)(iVar1 + 0xc);
  if (pAVar12 != (Array *)0x0) {
    if (*(int *)pAVar12 != 0) {
      ArrayReleaseClasses<ListItem*>(pAVar12);
      iVar1 = *(int *)(*(int *)this + 4);
      pAVar12 = *(Array **)(iVar1 + 0xc);
      if (pAVar12 == (Array *)0x0) goto LAB_001434c4;
    }
    if (*(void **)(pAVar12 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pAVar12 + 4));
    }
    operator_delete(pAVar12);
    iVar1 = *(int *)(*(int *)this + 4);
  }
LAB_001434c4:
  *(undefined4 *)(iVar1 + 0xc) = 0;
  iVar1 = ::ListItem::isShip(param_1);
  iVar14 = *(int *)(param_1 + 0x28);
  if (iVar1 == 0) {
    iVar13 = ::ListItem::isSlot(param_1);
    if (iVar13 == 0) {
      iVar14 = Item::getType(*(Item **)(param_1 + 0x10));
    }
    pSVar11 = (Ship *)Status::getShip(Globals::status);
    puVar10 = (uint *)Ship::getCargo(pSVar11);
    if ((puVar10 != (uint *)0x0) && (*puVar10 != 0)) {
      iVar13 = 0;
      uVar7 = 0;
      do {
        iVar4 = Item::getType(*(Item **)(puVar10[1] + uVar7 * 4));
        if (iVar4 == iVar14) {
          iVar13 = iVar13 + 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *puVar10);
      goto LAB_0014353e;
    }
  }
  else {
    pSVar2 = (Station *)Status::getStation(Globals::status);
    piVar3 = (int *)Station::getShips(pSVar2);
    if (piVar3 != (int *)0x0) {
      iVar13 = *piVar3;
      goto LAB_0014353e;
    }
  }
  iVar13 = 0;
LAB_0014353e:
  iVar4 = ::ListItem::isSlot(param_1);
  pAVar12 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar12 + 4) = puVar5;
  *(undefined4 *)(pAVar12 + 8) = 1;
  *puVar5 = 0;
  iVar6 = 3;
  *(undefined4 *)pAVar12 = 0;
  if (iVar13 == 0) {
    iVar6 = 4;
  }
  uVar7 = iVar6 + iVar13;
  if (iVar1 == 0 && iVar4 == 0) {
    uVar7 = uVar7 + 3;
  }
  ArraySetLength<ListItem*>(uVar7,pAVar12);
  pLVar8 = operator_new(0x48);
  pSVar9 = (String *)GameText::getText(Globals::gameText,0x115);
  ::ListItem::ListItem(pLVar8,pSVar9);
  **(undefined4 **)(pAVar12 + 4) = pLVar8;
  pLVar8 = operator_new(0x48);
  ::ListItem::ListItem(pLVar8,param_1);
  *(ListItem **)(*(int *)(pAVar12 + 4) + 4) = pLVar8;
  if (iVar1 == 0 && iVar4 == 0) {
    pLVar8 = operator_new(0x48);
    pSVar9 = (String *)GameText::getText(Globals::gameText,0x116);
    ::ListItem::ListItem(pLVar8,pSVar9);
    *(ListItem **)(*(int *)(pAVar12 + 4) + 8) = pLVar8;
    pLVar8 = operator_new(0x48);
    pSVar9 = (String *)GameText::getText(Globals::gameText,0x117);
    ::ListItem::ListItem(pLVar8,pSVar9,true,0);
    *(ListItem **)(*(int *)(pAVar12 + 4) + 0xc) = pLVar8;
    pLVar8 = operator_new(0x48);
    pSVar9 = (String *)GameText::getText(Globals::gameText,0x11a);
    ::ListItem::ListItem(pLVar8,pSVar9,true,1);
    iVar4 = 5;
    *(ListItem **)(*(int *)(pAVar12 + 4) + 0x10) = pLVar8;
  }
  else {
    iVar4 = 2;
  }
  pLVar8 = operator_new(0x48);
  if (iVar1 == 1) {
    pSVar9 = (String *)GameText::getText(Globals::gameText,0x11d);
  }
  else {
    pSVar9 = (String *)GameText::getText(Globals::gameText,0x11c);
  }
  ::ListItem::ListItem(pLVar8,pSVar9);
  iVar6 = iVar4 + 1;
  *(ListItem **)(*(int *)(pAVar12 + 4) + iVar4 * 4) = pLVar8;
  if (iVar13 < 1) {
    pLVar8 = operator_new(0x48);
    ::ListItem::ListItem(pLVar8,iVar6);
    *(ListItem **)(*(int *)(pAVar12 + 4) + iVar6 * 4) = pLVar8;
  }
  else if (iVar1 == 1) {
    pSVar2 = (Station *)Status::getStation(Globals::status);
    puVar10 = (uint *)Station::getShips(pSVar2);
    if (*puVar10 != 0) {
      uVar7 = 0;
      do {
        pLVar8 = operator_new(0x48);
        ::ListItem::ListItem(pLVar8,*(Ship **)(puVar10[1] + uVar7 * 4));
        *(ListItem **)(*(int *)(pAVar12 + 4) + iVar4 * 4 + 4 + uVar7 * 4) = pLVar8;
        uVar7 = uVar7 + 1;
      } while (uVar7 < *puVar10);
    }
  }
  else {
    pSVar11 = (Ship *)Status::getShip(Globals::status);
    puVar10 = (uint *)Ship::getCargo(pSVar11);
    if (*puVar10 != 0) {
      uVar7 = 0;
      do {
        iVar1 = Item::getType(*(Item **)(puVar10[1] + uVar7 * 4));
        if (iVar1 == iVar14) {
          pLVar8 = operator_new(0x48);
          ::ListItem::ListItem(pLVar8,*(Item **)(puVar10[1] + uVar7 * 4));
          *(ListItem **)(*(int *)(pAVar12 + 4) + iVar6 * 4) = pLVar8;
          iVar6 = iVar6 + 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *puVar10);
    }
  }
  *(Array **)(*(int *)(*(int *)this + 4) + 0xc) = pAVar12;
  return;
}

// ===== HangarList::fillIngredientsList  @0x0014378c  (372 bytes)
/* HangarList::fillIngredientsList(BluePrint*, bool) */

void HangarList::fillIngredientsList(BluePrint *param_1,bool param_2)

{
  GameText *this;
  int iVar1;
  Ship *this_00;
  uint *puVar2;
  uint *puVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  ListItem *pLVar6;
  int iVar7;
  String *pSVar8;
  int iVar9;
  Item *this_01;
  void *pvVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  
  this_00 = (Ship *)Status::getShip(Globals::status);
  puVar2 = (uint *)Ship::getCargo(this_00);
  iVar1 = Globals::items;
  puVar3 = (uint *)BluePrint::getIngredientList((BluePrint *)(uint)param_2);
  uVar12 = *puVar3;
  pAVar4 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar4 + 4) = puVar5;
  *(undefined4 *)(pAVar4 + 8) = 1;
  *puVar5 = 0;
  *(undefined4 *)pAVar4 = 0;
  ArraySetLength<ListItem*>(uVar12 + 1,pAVar4);
  pLVar6 = operator_new(0x48);
  this = Globals::gameText;
  iVar7 = BluePrint::getIndex((BluePrint *)(uint)param_2);
  pSVar8 = (String *)GameText::getText(this,iVar7 + 0x4fa);
  ::ListItem::ListItem(pLVar6,pSVar8);
  **(undefined4 **)(pAVar4 + 4) = pLVar6;
  if (*puVar3 != 0) {
    iVar7 = 1;
    uVar12 = 0;
    do {
      if ((puVar2 != (uint *)0x0) && (*puVar2 != 0)) {
        uVar13 = 0;
        do {
          iVar9 = Item::getIndex(*(Item **)(puVar2[1] + uVar13 * 4));
          if (iVar9 == *(int *)(puVar3[1] + uVar12 * 4)) {
            pLVar6 = operator_new(0x48);
            ::ListItem::ListItem(pLVar6,*(Item **)(puVar2[1] + uVar13 * 4));
            *(ListItem **)(*(int *)(pAVar4 + 4) + iVar7 * 4) = pLVar6;
            this_01 = *(Item **)(puVar2[1] + uVar13 * 4);
            goto LAB_001438a8;
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar2);
      }
      pLVar6 = operator_new(0x48);
      ::ListItem::ListItem
                (pLVar6,*(Item **)(*(int *)(iVar1 + 4) + *(int *)(puVar3[1] + uVar12 * 4) * 4));
      *(ListItem **)(*(int *)(pAVar4 + 4) + iVar7 * 4) = pLVar6;
      this_01 = *(Item **)(*(int *)(iVar1 + 4) + *(int *)(puVar3[1] + uVar12 * 4) * 4);
LAB_001438a8:
      Item::setBlueprintAmount(this_01,0);
      uVar12 = uVar12 + 1;
      iVar7 = iVar7 + 1;
    } while (uVar12 < *puVar3);
  }
  *(Array **)(*(int *)(*(int *)param_1 + 4) + 0x10) = pAVar4;
  pLVar6 = operator_new(0x48);
  ::ListItem::ListItem(pLVar6,0);
  pLVar6[0x24] = (ListItem)0x0;
  piVar11 = *(int **)(*(int *)(*(int *)param_1 + 4) + 0x10);
  piVar11[2] = *piVar11 + 1;
  pvVar10 = realloc((void *)piVar11[1],(*piVar11 + 1) * 4);
  piVar11[1] = (int)pvVar10;
  *(ListItem **)((int)pvVar10 + *piVar11 * 4) = pLVar6;
  *piVar11 = piVar11[2];
  return;
}

// ===== HangarList::getCurrentItem  @0x00143930  (8 bytes)
/* HangarList::getCurrentItem() */

void __thiscall HangarList::getCurrentItem(HangarList *this)

{
  getCurrentItemAt(this,*(int *)(this + 8));
  return;
}

// ===== HangarList::getCurrentItemAt  @0x00143936  (40 bytes)
/* HangarList::getCurrentItemAt(int) */

undefined4 __thiscall HangarList::getCurrentItemAt(HangarList *this,int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((*(int *)this != 0) &&
     (piVar2 = *(int **)(*(int *)(*(int *)this + 4) + *(int *)(this + 4) * 4), piVar2 != (int *)0x0)
     ) {
    uVar1 = 0;
    if (-1 < param_1) {
      if (param_1 < *piVar2) {
        uVar1 = *(undefined4 *)(piVar2[1] + param_1 * 4);
      }
      return uVar1;
    }
    return 0;
  }
  return 0;
}

// ===== HangarList::getCurrentTabItems  @0x0014395e  (12 bytes)
/* HangarList::getCurrentTabItems() */

undefined4 __thiscall HangarList::getCurrentTabItems(HangarList *this)

{
  return *(undefined4 *)(*(int *)(*(int *)this + 4) + *(int *)(this + 4) * 4);
}

// ===== HangarList::getItems  @0x0014396a  (4 bytes)
/* HangarList::getItems() */

undefined4 __thiscall HangarList::getItems(HangarList *this)

{
  return *(undefined4 *)this;
}

// ===== HangarList::setCurrentTab  @0x0014396e  (4 bytes)
/* HangarList::setCurrentTab(int, bool) */

void HangarList::setCurrentTab(int param_1,bool param_2)

{
  *(uint *)(param_1 + 4) = (uint)param_2;
  return;
}

// ===== HangarList::getCurrentLength  @0x00143972  (20 bytes)
/* HangarList::getCurrentLength() */

undefined4 __thiscall HangarList::getCurrentLength(HangarList *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined4 **)(*(int *)(*(int *)this + 4) + *(int *)(this + 4) * 4);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *puVar1;
  }
  return uVar2;
}

// ===== HangarList::getCurrentTab  @0x00143986  (4 bytes)
/* HangarList::getCurrentTab() */

undefined4 __thiscall HangarList::getCurrentTab(HangarList *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== HangarList::getCurrentItemIndex  @0x0014398a  (4 bytes)
/* HangarList::getCurrentItemIndex() */

undefined4 __thiscall HangarList::getCurrentItemIndex(HangarList *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== HangarList::setCurrentItemIndex  @0x0014398e  (4 bytes)
/* HangarList::setCurrentItemIndex(int) */

void __thiscall HangarList::setCurrentItemIndex(HangarList *this,int param_1)

{
  *(int *)(this + 8) = param_1;
  return;
}

