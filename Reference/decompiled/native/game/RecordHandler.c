// Class: RecordHandler
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== RecordHandler::RecordHandler  @0x000dc3b8  (154 bytes)
/* RecordHandler::RecordHandler() */

void __thiscall RecordHandler::RecordHandler(RecordHandler *this)

{
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 8));
  AbyssEngine::String::String((String *)(this + 0x10));
  AbyssEngine::String::String((String *)(this + 0x18));
  AbyssEngine::String::String(aSStack_24,"gof2_save_options",false);
  AbyssEngine::String::operator=((String *)(this + 8),aSStack_24);
  AbyssEngine::String::~String(aSStack_24);
  AbyssEngine::String::String(aSStack_24,"gof2_save_game_",false);
  AbyssEngine::String::operator=((String *)(this + 0x10),aSStack_24);
  AbyssEngine::String::~String(aSStack_24);
  AbyssEngine::String::String(aSStack_24,"gof2_save_game_preview_",false);
  AbyssEngine::String::operator=((String *)(this + 0x18),aSStack_24);
  AbyssEngine::String::~String(aSStack_24);
  if (__stack_chk_guard - local_1c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_1c);
  }
  return;
}

// ===== RecordHandler::~RecordHandler  @0x000dc49c  (34 bytes)
/* RecordHandler::~RecordHandler() */

RecordHandler * __thiscall RecordHandler::~RecordHandler(RecordHandler *this)

{
  AbyssEngine::String::~String((String *)(this + 0x18));
  AbyssEngine::String::~String((String *)(this + 0x10));
  AbyssEngine::String::~String((String *)(this + 8));
  return this;
}

// ===== RecordHandler::notEnoughMemory  @0x000dc4be  (22 bytes)
/* RecordHandler::notEnoughMemory() */

bool RecordHandler::notEnoughMemory(void)

{
  int iVar1;
  
  iVar1 = AEFile::GetDeviceFreeSpace();
  return iVar1 < 900;
}

// ===== RecordHandler::readAllPreviewRecords  @0x000dc4d4  (90 bytes)
/* RecordHandler::readAllPreviewRecords() */

Array * __thiscall RecordHandler::readAllPreviewRecords(RecordHandler *this)

{
  Array *pAVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  ArraySetLength<GameRecord*>(Globals::recordSlots,pAVar1);
  if (0 < (int)Globals::recordSlots) {
    iVar4 = 0;
    do {
      uVar3 = recordStoreReadPreview(this,iVar4);
      *(undefined4 *)(*(int *)(pAVar1 + 4) + iVar4 * 4) = uVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)Globals::recordSlots);
  }
  return pAVar1;
}

// ===== RecordHandler::recordStoreReadPreview  @0x000dc578  (210 bytes)
/* RecordHandler::recordStoreReadPreview(int) */

void __thiscall RecordHandler::recordStoreReadPreview(RecordHandler *this,int param_1)

{
  int iVar1;
  GameRecord *this_00;
  uint local_24 [2];
  AbyssEngine aAStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_24[0] = 0;
  AbyssEngine::String::Set(CONCAT44(param_1,local_24));
  AbyssEngine::operator+(aAStack_1c,this + 0x18,(String *)local_24);
  AbyssEngine::String::~String((String *)local_24);
  iVar1 = AEFile::FileExist(aAStack_1c);
  if (iVar1 == 1) {
    AEFile::OpenRead(aAStack_1c,local_24);
    this_00 = operator_new(0x1c0);
    GameRecord::GameRecord(this_00);
    AEFile::Read((longlong *)(this_00 + 0x10),local_24[0]);
    AEFile::Read((int *)(this_00 + 8),local_24[0]);
    AEFile::Read(this_00 + 400,local_24[0],true);
    AEFile::Read(this_00 + 0x188,local_24[0],true);
    AEFile::Read((int *)(this_00 + 0x40),local_24[0]);
    AEFile::Read((int *)(this_00 + 0x20),local_24[0]);
    AEFile::Read((float *)(this_00 + 0x11c),local_24[0]);
    AEFile::Read((int *)(this_00 + 0x198),local_24[0]);
    AEFile::Close(local_24[0]);
  }
  AbyssEngine::String::~String((String *)aAStack_1c);
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== RecordHandler::readAllRecords  @0x000dc674  (90 bytes)
/* RecordHandler::readAllRecords() */

Array * __thiscall RecordHandler::readAllRecords(RecordHandler *this)

{
  Array *pAVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  ArraySetLength<GameRecord*>(Globals::recordSlots,pAVar1);
  if (0 < (int)Globals::recordSlots) {
    iVar4 = 0;
    do {
      uVar3 = recordStoreRead(this,iVar4);
      *(undefined4 *)(*(int *)(pAVar1 + 4) + iVar4 * 4) = uVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)Globals::recordSlots);
  }
  return pAVar1;
}

// ===== RecordHandler::recordStoreRead  @0x000dc6e4  (5780 bytes)
/* RecordHandler::recordStoreRead(int) */

void __thiscall RecordHandler::recordStoreRead(RecordHandler *this,int param_1)

{
  longlong lVar1;
  int iVar2;
  RecordHandler *pRVar3;
  GameRecord *this_00;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  void *pvVar7;
  Array *pAVar8;
  Station *pSVar9;
  Array *pAVar10;
  int *piVar11;
  Standing *this_01;
  BluePrint *this_02;
  uint *puVar12;
  PendingProduct *pPVar13;
  String *this_03;
  int iVar14;
  undefined4 *puVar15;
  GameRecord *pGVar16;
  Item *pIVar17;
  uint uVar18;
  uint uVar19;
  int *piVar20;
  int iVar21;
  uint local_a8;
  int local_a4;
  uint local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  RecordHandler *local_88 [2];
  String aSStack_80 [8];
  uint local_78 [2];
  int local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38 [2];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_38[0] = 0;
  AbyssEngine::String::Set(CONCAT44(param_1,local_38));
  AbyssEngine::operator+(aAStack_30,this + 0x10,(String *)local_38);
  AbyssEngine::String::~String((String *)local_38);
  iVar2 = AEFile::FileExist(aAStack_30);
  if (iVar2 == 1) {
    pRVar3 = (RecordHandler *)AEFile::OpenRead(aAStack_30,&local_3c);
    iVar2 = checkHash(pRVar3,local_3c);
    AEFile::Close(local_3c);
    if (iVar2 != 0) {
      AEFile::OpenRead(aAStack_30,&local_3c);
      this_00 = operator_new(0x1c0);
      GameRecord::GameRecord(this_00);
      pGVar16 = this_00 + 4;
      *(int *)pGVar16 = 0;
      AEFile::Read((int *)pGVar16,local_3c);
      if (*(int *)pGVar16 != 0) {
        uVar18 = 0;
        do {
          AEFile::Read((bool *)(*(int *)this_00 + uVar18),local_3c);
          uVar18 = uVar18 + 1;
        } while (uVar18 < *(uint *)pGVar16);
      }
      AEFile::Read((int *)(this_00 + 8),local_3c);
      AEFile::Read((int *)(this_00 + 0xc),local_3c);
      AEFile::Read((longlong *)(this_00 + 0x10),local_3c);
      AEFile::Read((int *)(this_00 + 0x18),local_3c);
      AEFile::Read((int *)(this_00 + 0x1c),local_3c);
      AEFile::Read((int *)(this_00 + 0x20),local_3c);
      AEFile::Read((int *)(this_00 + 0x24),local_3c);
      AEFile::Read((int *)(this_00 + 0x28),local_3c);
      AEFile::Read((int *)(this_00 + 0x3c),local_3c);
      AEFile::Read((int *)(this_00 + 0x40),local_3c);
      uVar4 = readMission(this,local_3c);
      *(undefined4 *)(this_00 + 0x54) = uVar4;
      uVar4 = readMission(this,local_3c);
      *(undefined4 *)(this_00 + 0x58) = uVar4;
      AEFile::Read((int *)(this_00 + 0x30),local_3c);
      AEFile::Read((int *)(this_00 + 0x34),local_3c);
      AEFile::Read((int *)(this_00 + 0x38),local_3c);
      AEFile::Read((int *)(this_00 + 0x2c),local_3c);
      AEFile::Read((int *)(this_00 + 0x44),local_3c);
      AEFile::Read((int *)(this_00 + 0x48),local_3c);
      AEFile::Read((int *)(this_00 + 0x4c),local_3c);
      AEFile::Read((int *)(this_00 + 0x50),local_3c);
      puVar5 = operator_new(0xc);
      puVar6 = operator_new__(1);
      puVar5[1] = puVar6;
      puVar5[2] = 1;
      *puVar6 = 0;
      *puVar5 = 0;
      local_40 = 0;
      *(undefined4 **)(this_00 + 0x68) = puVar5;
      AEFile::Read((int *)&local_40,local_3c);
      ArraySetLength<bool>(local_40,*(Array **)(this_00 + 0x68));
      if (0 < (int)local_40) {
        iVar2 = 0;
        do {
          AEFile::Read((bool *)(*(int *)(*(int *)(this_00 + 0x68) + 4) + iVar2),local_3c);
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)local_40);
      }
      puVar5 = operator_new(0xc);
      puVar6 = operator_new__(1);
      puVar5[1] = puVar6;
      puVar5[2] = 1;
      *puVar6 = 0;
      *puVar5 = 0;
      local_44 = 0;
      *(undefined4 **)(this_00 + 0x6c) = puVar5;
      AEFile::Read((int *)&local_44,local_3c);
      ArraySetLength<bool>(local_44,*(Array **)(this_00 + 0x6c));
      if (0 < (int)local_44) {
        iVar2 = 0;
        do {
          AEFile::Read((bool *)(*(int *)(*(int *)(this_00 + 0x6c) + 4) + iVar2),local_3c);
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)local_44);
      }
      AEFile::Read((int *)(this_00 + 0x74),local_3c);
      AEFile::Read((int *)(this_00 + 0x78),local_3c);
      AEFile::Read((int *)(this_00 + 0x7c),local_3c);
      AEFile::Read((int *)(this_00 + 0x80),local_3c);
      puVar5 = operator_new(0xc);
      puVar6 = operator_new__(1);
      puVar5[1] = puVar6;
      puVar5[2] = 1;
      *puVar6 = 0;
      *puVar5 = 0;
      local_48 = 0;
      *(undefined4 **)(this_00 + 0x84) = puVar5;
      AEFile::Read((int *)&local_48,local_3c);
      ArraySetLength<bool>(local_48,*(Array **)(this_00 + 0x84));
      if (0 < (int)local_48) {
        iVar2 = 0;
        do {
          AEFile::Read((bool *)(*(int *)(*(int *)(this_00 + 0x84) + 4) + iVar2),local_3c);
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)local_48);
      }
      AEFile::Read((int *)(this_00 + 0x88),local_3c);
      puVar5 = operator_new(0xc);
      puVar6 = operator_new__(1);
      puVar5[1] = puVar6;
      puVar5[2] = 1;
      *puVar6 = 0;
      *puVar5 = 0;
      local_4c = 0;
      *(undefined4 **)(this_00 + 0x8c) = puVar5;
      AEFile::Read((int *)&local_4c,local_3c);
      ArraySetLength<bool>(local_4c,*(Array **)(this_00 + 0x8c));
      if (0 < (int)local_4c) {
        iVar2 = 0;
        do {
          AEFile::Read((bool *)(*(int *)(*(int *)(this_00 + 0x8c) + 4) + iVar2),local_3c);
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)local_4c);
      }
      AEFile::Read((int *)(this_00 + 0x90),local_3c);
      AEFile::Read((longlong *)(this_00 + 0x98),local_3c);
      AEFile::Read((int *)(this_00 + 0xa0),local_3c);
      AEFile::Read((int *)(this_00 + 0xa4),local_3c);
      AEFile::Read((int *)(this_00 + 0xa8),local_3c);
      AEFile::Read((int *)(this_00 + 0xac),local_3c);
      AEFile::Read((int *)(this_00 + 0xb0),local_3c);
      AEFile::Read((int *)(this_00 + 0xb4),local_3c);
      AEFile::Read((int *)(this_00 + 0xb8),local_3c);
      AEFile::Read((int *)(this_00 + 0xbc),local_3c);
      AEFile::Read((int *)(this_00 + 0xc0),local_3c);
      AEFile::Read((int *)(this_00 + 0xc4),local_3c);
      pGVar16 = this_00 + 100;
      AEFile::Read((int *)pGVar16,local_3c);
      uVar19 = *(uint *)pGVar16;
      lVar1 = (ulonglong)uVar19 * 4;
      uVar18 = (uint)lVar1;
      if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
        uVar18 = 0xffffffff;
      }
      pvVar7 = operator_new__(uVar18);
      *(void **)(this_00 + 0x60) = pvVar7;
      if (0 < (int)uVar19) {
        iVar2 = 0;
        iVar21 = 0;
        while( true ) {
          AEFile::Read((int *)((int)pvVar7 + iVar2),local_3c);
          iVar21 = iVar21 + 1;
          if (*(int *)pGVar16 <= iVar21) break;
          iVar2 = iVar2 + 4;
          pvVar7 = *(void **)(this_00 + 0x60);
        }
      }
      local_50 = 0;
      AEFile::Read(&local_50,local_3c);
      uVar4 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + local_50 * 4),-1);
      *(undefined4 *)(this_00 + 0x130) = uVar4;
      local_54 = 0;
      AEFile::Read(&local_54,local_3c);
      Ship::setRace(*(Ship **)(this_00 + 0x130),local_54);
      local_58 = 0;
      AEFile::Read((int *)&local_58,local_3c);
      uVar18 = local_58;
      if (0 < (int)local_58) {
        pAVar8 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar5;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar8 = 0;
        ArraySetLength<Item*>(uVar18,pAVar8);
        if (0 < (int)local_58) {
          iVar2 = 0;
          do {
            local_38[0] = 0;
            AEFile::Read((int *)local_38,local_3c);
            if (local_38[0] == 0xffffffff) {
              *(undefined4 *)(*(int *)(pAVar8 + 4) + iVar2 * 4) = 0;
            }
            else {
              local_78[0] = 0;
              AEFile::Read((int *)local_78,local_3c);
              uVar18 = local_78[0];
              pIVar17 = *(Item **)(*(int *)(Globals::items + 4) + local_38[0] * 4);
              iVar21 = Item::getMaxPrice(pIVar17);
              uVar4 = Item::makeItem(pIVar17,uVar18,iVar21);
              *(undefined4 *)(*(int *)(pAVar8 + 4) + iVar2 * 4) = uVar4;
              local_88[0] = (RecordHandler *)((uint)local_88[0] & 0xffffff00);
              AEFile::Read((bool *)local_88,local_3c);
              Item::setUnsaleable(*(Item **)(*(int *)(pAVar8 + 4) + iVar2 * 4),
                                  (bool)local_88[0]._0_1_);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)local_58);
        }
        Ship::replaceEquipment(*(Ship **)(this_00 + 0x130),pAVar8);
      }
      local_5c = 0;
      AEFile::Read((int *)&local_5c,local_3c);
      uVar18 = local_5c;
      if (0 < (int)local_5c) {
        pAVar8 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar5;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar8 = 0;
        ArraySetLength<Item*>(uVar18,pAVar8);
        if (0 < (int)local_5c) {
          iVar2 = 0;
          do {
            local_88[0] = (RecordHandler *)0x0;
            AEFile::Read((int *)local_38,local_3c);
            AEFile::Read((int *)local_78,local_3c);
            AEFile::Read((int *)local_88,local_3c);
            local_60 = local_60 & 0xffffff00;
            AEFile::Read((bool *)&local_60,local_3c);
            uVar18 = local_78[0];
            pIVar17 = *(Item **)(*(int *)(Globals::items + 4) + local_38[0] * 4);
            iVar21 = Item::getMaxPrice(pIVar17);
            uVar4 = Item::makeItem(pIVar17,uVar18,iVar21);
            *(undefined4 *)(*(int *)(pAVar8 + 4) + iVar2 * 4) = uVar4;
            Item::setPrice(*(Item **)(*(int *)(pAVar8 + 4) + iVar2 * 4),(int)local_88[0]);
            Item::setUnsaleable(*(Item **)(*(int *)(pAVar8 + 4) + iVar2 * 4),local_60._0_1_);
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)local_5c);
        }
        Ship::replaceCargo(*(Ship **)(this_00 + 0x130),pAVar8);
      }
      pAVar8 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar8 + 4) = puVar5;
      *(undefined4 *)(pAVar8 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar8 = 0;
      local_60 = 0;
      AEFile::Read((int *)&local_60,local_3c);
      ArraySetLength<Station*>(local_60,pAVar8);
      if (*(int *)pAVar8 != -1) {
        uVar18 = 0;
        do {
          local_38[0] = 0;
          AEFile::Read((int *)local_38,local_3c);
          if (local_38[0] == 0xffffffff) {
            pSVar9 = (Station *)0x0;
          }
          else {
            pSVar9 = (Station *)Galaxy::getStation(Globals::galaxy,local_38[0]);
            AEFile::Read((int *)&local_5c,local_3c);
            uVar19 = local_5c;
            if (0 < (int)local_5c) {
              pAVar10 = operator_new(0xc);
              puVar5 = operator_new__(4);
              *(undefined4 **)(pAVar10 + 4) = puVar5;
              *(undefined4 *)(pAVar10 + 8) = 1;
              *puVar5 = 0;
              *(undefined4 *)pAVar10 = 0;
              ArraySetLength<Item*>(uVar19,pAVar10);
              if (0 < (int)local_5c) {
                iVar2 = 0;
                do {
                  local_64 = 0;
                  AEFile::Read((int *)local_78,local_3c);
                  AEFile::Read((int *)local_88,local_3c);
                  AEFile::Read((int *)&local_64,local_3c);
                  local_68 = local_68 & 0xffffff00;
                  AEFile::Read((bool *)&local_68,local_3c);
                  pRVar3 = local_88[0];
                  pIVar17 = *(Item **)(*(int *)(Globals::items + 4) + local_78[0] * 4);
                  iVar21 = Item::getMaxPrice(pIVar17);
                  uVar4 = Item::makeItem(pIVar17,(int)pRVar3,iVar21);
                  *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = uVar4;
                  Item::setPrice(*(Item **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_64);
                  Item::setUnsaleable(*(Item **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_68._0_1_);
                  iVar2 = iVar2 + 1;
                } while (iVar2 < (int)local_5c);
              }
              Station::setItems(pSVar9,pAVar10,false);
            }
            local_78[0] = 0;
            AEFile::Read((int *)local_78,local_3c);
            uVar19 = local_78[0];
            if (0 < (int)local_78[0]) {
              pAVar10 = operator_new(0xc);
              puVar5 = operator_new__(4);
              *(undefined4 **)(pAVar10 + 4) = puVar5;
              *(undefined4 *)(pAVar10 + 8) = 1;
              *puVar5 = 0;
              *(undefined4 *)pAVar10 = 0;
              ArraySetLength<Ship*>(uVar19,pAVar10);
              if (0 < (int)local_78[0]) {
                iVar2 = 0;
                do {
                  local_88[0] = (RecordHandler *)0x0;
                  AEFile::Read((int *)local_88,local_3c);
                  uVar4 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) +
                                                   (int)local_88[0] * 4),-1);
                  *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = uVar4;
                  local_64 = 0;
                  AEFile::Read((int *)&local_64,local_3c);
                  Ship::setRace(*(Ship **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_64);
                  iVar2 = iVar2 + 1;
                } while (iVar2 < (int)local_78[0]);
              }
              Station::setShips(pSVar9,pAVar10,false);
            }
            local_88[0] = (RecordHandler *)0x0;
            AEFile::Read((int *)local_88,local_3c);
            pRVar3 = local_88[0];
            if (0 < (int)local_88[0]) {
              pAVar10 = operator_new(0xc);
              puVar5 = operator_new__(4);
              *(undefined4 **)(pAVar10 + 4) = puVar5;
              *(undefined4 *)(pAVar10 + 8) = 1;
              *puVar5 = 0;
              *(undefined4 *)pAVar10 = 0;
              ArraySetLength<Agent*>((uint)pRVar3,pAVar10);
              if (0 < (int)local_88[0]) {
                iVar2 = 0;
                do {
                  uVar4 = readAgent(this,local_3c);
                  *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = uVar4;
                  iVar2 = iVar2 + 1;
                } while (iVar2 < (int)local_88[0]);
              }
              Station::setAgents(pSVar9,pAVar10);
            }
            local_64 = local_64 & 0xffffff00;
            AEFile::Read((bool *)&local_64,local_3c);
            Station::setAttackedFriends(pSVar9,local_64._0_1_);
          }
          uVar19 = *(uint *)pAVar8;
          if (uVar18 == uVar19) {
            *(Station **)(this_00 + 0x138) = pSVar9;
          }
          else {
            *(Station **)(*(int *)(pAVar8 + 4) + uVar18 * 4) = pSVar9;
          }
          uVar18 = uVar18 + 1;
        } while (uVar18 < uVar19 + 1);
      }
      *(Array **)(this_00 + 0x5c) = pAVar8;
      local_64 = 0;
      AEFile::Read((int *)&local_64,local_3c);
      uVar18 = local_64;
      uVar19 = (uint)((ulonglong)local_64 * 4);
      if ((int)((ulonglong)local_64 * 4 >> 0x20) != 0) {
        uVar19 = 0xffffffff;
      }
      piVar11 = operator_new__(uVar19);
      if (0 < (int)uVar18) {
        iVar2 = 0;
        piVar20 = piVar11;
        do {
          AEFile::Read(piVar20,local_3c);
          iVar2 = iVar2 + 1;
          piVar20 = piVar20 + 1;
        } while (iVar2 < (int)local_64);
      }
      this_01 = operator_new(8);
      Standing::Standing(this_01);
      *(Standing **)(this_00 + 0x13c) = this_01;
      Standing::setStandings(this_01,piVar11);
      pAVar10 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar10 + 4) = puVar5;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar10 = 0;
      local_68 = 0;
      AEFile::Read((int *)&local_68,local_3c);
      ArraySetLength<BluePrint*>(local_68,pAVar10);
      if (*(int *)pAVar10 != 0) {
        uVar18 = 0;
        do {
          this_02 = operator_new(0x28);
          iVar2 = Status::getBluePrints(Globals::status);
          iVar2 = BluePrint::getIndex(*(BluePrint **)(*(int *)(iVar2 + 4) + uVar18 * 4));
          BluePrint::BluePrint(this_02,iVar2);
          *(BluePrint **)(*(int *)(pAVar10 + 4) + uVar18 * 4) = this_02;
          piVar11 = *(int **)(*(int *)(pAVar10 + 4) + uVar18 * 4);
          puVar12 = (uint *)*piVar11;
          if (*puVar12 != 0) {
            iVar2 = 0;
            uVar19 = 0;
            do {
              AEFile::Read((int *)(puVar12[1] + iVar2),local_3c);
              puVar12 = (uint *)*piVar11;
              iVar2 = iVar2 + 4;
              uVar19 = uVar19 + 1;
            } while (uVar19 < *puVar12);
          }
          AEFile::Read(piVar11 + 1,local_3c);
          AEFile::Read((bool *)(piVar11 + 2),local_3c);
          AEFile::Read(piVar11 + 3,local_3c);
          AEFile::Read(piVar11 + 4,local_3c);
          AbyssEngine::String::String((String *)local_38);
          AEFile::Read((String *)local_38,local_3c,true);
          AbyssEngine::String::operator=((String *)(piVar11 + 5),(String *)local_38);
          AbyssEngine::String::~String((String *)local_38);
          uVar18 = uVar18 + 1;
        } while (uVar18 < *(uint *)pAVar10);
      }
      local_38[0] = 0;
      *(Array **)(this_00 + 0x140) = pAVar10;
      AEFile::Read((int *)local_38,local_3c);
      uVar18 = local_38[0];
      if ((int)local_38[0] < 1) {
        *(undefined4 *)(this_00 + 0x144) = 0;
      }
      else {
        pAVar10 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar10 + 4) = puVar5;
        *(undefined4 *)(pAVar10 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar10 = 0;
        ArraySetLength<PendingProduct*>(uVar18,pAVar10);
        if (*(int *)pAVar10 != 0) {
          uVar18 = 0;
          do {
            local_70 = 0;
            AEFile::Read((int *)local_88,local_3c);
            AEFile::Read((int *)&local_6c,local_3c);
            AEFile::Read(&local_70,local_3c);
            AbyssEngine::String::String((String *)local_78);
            AEFile::Read((String *)local_78,local_3c,true);
            pPVar13 = operator_new(0x14);
            pRVar3 = local_88[0];
            AbyssEngine::String::String(aSStack_80,(String *)local_78,false);
            PendingProduct::PendingProduct(pPVar13,pRVar3,aSStack_80,local_70,local_6c);
            *(PendingProduct **)(*(int *)(pAVar10 + 4) + uVar18 * 4) = pPVar13;
            AbyssEngine::String::~String(aSStack_80);
            AbyssEngine::String::~String((String *)local_78);
            uVar18 = uVar18 + 1;
          } while (uVar18 < *(uint *)pAVar10);
        }
        *(Array **)(this_00 + 0x144) = pAVar10;
      }
      local_78[0] = 0;
      AEFile::Read((int *)local_78,local_3c);
      uVar18 = local_78[0];
      if ((int)local_78[0] < 1) {
        *(undefined4 *)(this_00 + 0x14c) = 0;
      }
      else {
        pAVar10 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar10 + 4) = puVar5;
        *(undefined4 *)(pAVar10 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar10 = 0;
        ArraySetLength<AbyssEngine::String*>(uVar18,pAVar10);
        if (0 < (int)local_78[0]) {
          iVar2 = 0;
          do {
            AbyssEngine::String::String((String *)local_88);
            AEFile::Read((String *)local_88,local_3c,true);
            this_03 = operator_new(8);
            AbyssEngine::String::String(this_03,(String *)local_88,false);
            *(String **)(*(int *)(pAVar10 + 4) + iVar2 * 4) = this_03;
            AbyssEngine::String::~String((String *)local_88);
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)local_78[0]);
        }
        *(Array **)(this_00 + 0x14c) = pAVar10;
        AEFile::Read((int *)(this_00 + 0x150),local_3c);
        AEFile::Read((int *)(this_00 + 0x154),local_3c);
        local_88[0] = (RecordHandler *)0x0;
        AEFile::Read((int *)local_88,local_3c);
        pRVar3 = local_88[0];
        uVar18 = (uint)(ZEXT48(local_88[0]) * 4);
        if ((int)(ZEXT48(local_88[0]) * 4 >> 0x20) != 0) {
          uVar18 = 0xffffffff;
        }
        pvVar7 = operator_new__(uVar18);
        *(void **)(this_00 + 0x158) = pvVar7;
        if (0 < (int)pRVar3) {
          iVar2 = 0;
          iVar21 = 0;
          while( true ) {
            AEFile::Read((int *)((int)pvVar7 + iVar2),local_3c);
            iVar21 = iVar21 + 1;
            if ((int)local_88[0] <= iVar21) break;
            iVar2 = iVar2 + 4;
            pvVar7 = *(void **)(this_00 + 0x158);
          }
        }
      }
      AEFile::Read((int *)(this_00 + 0x15c),local_3c);
      local_88[0] = (RecordHandler *)0x0;
      AEFile::Read((int *)local_88,local_3c);
      pAVar10 = operator_new(0xc);
      puVar6 = operator_new__(1);
      *(undefined1 **)(pAVar10 + 4) = puVar6;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar6 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x160) = pAVar10;
      ArraySetLength<bool>((uint)local_88[0],pAVar10);
      puVar12 = *(uint **)(this_00 + 0x160);
      if (*puVar12 != 0) {
        uVar18 = 0;
        do {
          AEFile::Read((bool *)(puVar12[1] + uVar18),local_3c);
          puVar12 = *(uint **)(this_00 + 0x160);
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      AEFile::Read((int *)local_88,local_3c);
      pAVar10 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar10 + 4) = puVar5;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x168) = pAVar10;
      ArraySetLength<int>((uint)local_88[0],pAVar10);
      puVar12 = *(uint **)(this_00 + 0x168);
      if (*puVar12 != 0) {
        iVar2 = 0;
        uVar18 = 0;
        do {
          AEFile::Read((int *)(puVar12[1] + iVar2),local_3c);
          puVar12 = *(uint **)(this_00 + 0x168);
          iVar2 = iVar2 + 4;
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      AEFile::Read((int *)local_88,local_3c);
      pAVar10 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar10 + 4) = puVar5;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x164) = pAVar10;
      ArraySetLength<int>((uint)local_88[0],pAVar10);
      puVar12 = *(uint **)(this_00 + 0x164);
      if (*puVar12 != 0) {
        iVar2 = 0;
        uVar18 = 0;
        do {
          AEFile::Read((int *)(puVar12[1] + iVar2),local_3c);
          puVar12 = *(uint **)(this_00 + 0x164);
          iVar2 = iVar2 + 4;
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      AEFile::Read((int *)local_88,local_3c);
      pAVar10 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar10 + 4) = puVar5;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x170) = pAVar10;
      ArraySetLength<int>((uint)local_88[0],pAVar10);
      puVar12 = *(uint **)(this_00 + 0x170);
      if (*puVar12 != 0) {
        iVar2 = 0;
        uVar18 = 0;
        do {
          AEFile::Read((int *)(puVar12[1] + iVar2),local_3c);
          puVar12 = *(uint **)(this_00 + 0x170);
          iVar2 = iVar2 + 4;
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      AEFile::Read((int *)local_88,local_3c);
      pAVar10 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar10 + 4) = puVar5;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x16c) = pAVar10;
      ArraySetLength<int>((uint)local_88[0],pAVar10);
      puVar12 = *(uint **)(this_00 + 0x16c);
      if (*puVar12 != 0) {
        iVar2 = 0;
        uVar18 = 0;
        do {
          AEFile::Read((int *)(puVar12[1] + iVar2),local_3c);
          puVar12 = *(uint **)(this_00 + 0x16c);
          iVar2 = iVar2 + 4;
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      AEFile::Read((int *)local_88,local_3c);
      pAVar10 = operator_new(0xc);
      puVar6 = operator_new__(1);
      *(undefined1 **)(pAVar10 + 4) = puVar6;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar6 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x174) = pAVar10;
      ArraySetLength<bool>((uint)local_88[0],pAVar10);
      puVar12 = *(uint **)(this_00 + 0x174);
      if (*puVar12 != 0) {
        uVar18 = 0;
        do {
          AEFile::Read((bool *)(puVar12[1] + uVar18),local_3c);
          puVar12 = *(uint **)(this_00 + 0x174);
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      local_6c = 0;
      AEFile::Read((int *)&local_6c,local_3c);
      pAVar10 = operator_new(0xc);
      puVar5 = operator_new__(4);
      *(undefined4 **)(pAVar10 + 4) = puVar5;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar5 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x148) = pAVar10;
      ArraySetLength<Agent*>(local_6c,pAVar10);
      if (**(int **)(this_00 + 0x148) != 0) {
        uVar18 = 0;
        do {
          uVar4 = readAgent(this,local_3c);
          *(undefined4 *)(*(int *)(*(int *)(this_00 + 0x148) + 4) + uVar18 * 4) = uVar4;
          uVar18 = uVar18 + 1;
        } while (uVar18 < **(uint **)(this_00 + 0x148));
      }
      AEFile::Read((bool *)(this_00 + 0xe4),local_3c);
      AEFile::Read((bool *)(this_00 + 0xe5),local_3c);
      AEFile::Read((bool *)(this_00 + 0xe6),local_3c);
      AEFile::Read((bool *)(this_00 + 0xe7),local_3c);
      AEFile::Read((bool *)(this_00 + 0xe8),local_3c);
      AEFile::Read((bool *)(this_00 + 0xe9),local_3c);
      AEFile::Read((bool *)(this_00 + 0xea),local_3c);
      AEFile::Read((bool *)(this_00 + 0xeb),local_3c);
      AEFile::Read((bool *)(this_00 + 0xec),local_3c);
      AEFile::Read((bool *)(this_00 + 0xed),local_3c);
      AEFile::Read((bool *)(this_00 + 0xee),local_3c);
      AEFile::Read((bool *)(this_00 + 0xef),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf0),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf1),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf2),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf3),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf4),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf5),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf6),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf7),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf8),local_3c);
      AEFile::Read((bool *)(this_00 + 0xf9),local_3c);
      AEFile::Read((bool *)(this_00 + 0xfa),local_3c);
      AEFile::Read((bool *)(this_00 + 0xfb),local_3c);
      AEFile::Read((bool *)(this_00 + 0xfc),local_3c);
      AEFile::Read((bool *)(this_00 + 0xfe),local_3c);
      AEFile::Read((bool *)(this_00 + 0xfd),local_3c);
      AEFile::Read((bool *)(this_00 + 0xff),local_3c);
      AEFile::Read((bool *)(this_00 + 0x100),local_3c);
      AEFile::Read((float *)(this_00 + 0x11c),local_3c);
      AEFile::Read((longlong *)(this_00 + 200),local_3c);
      AEFile::Read((bool *)(this_00 + 0x101),local_3c);
      AEFile::Read((bool *)(this_00 + 0x102),local_3c);
      local_70 = 0;
      AEFile::Read(&local_70,local_3c);
      if (0 < local_70) {
        local_8c = 0;
        AEFile::Read((int *)&local_8c,local_3c);
        uVar4 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + local_8c * 4),-1);
        *(undefined4 *)(this_00 + 0x134) = uVar4;
        local_90 = 0;
        AEFile::Read((int *)&local_90,local_3c);
        Ship::setRace(*(Ship **)(this_00 + 0x134),local_90);
        local_94 = 0;
        AEFile::Read((int *)&local_94,local_3c);
        uVar18 = local_94;
        if (0 < (int)local_94) {
          pAVar10 = operator_new(0xc);
          puVar5 = operator_new__(4);
          *(undefined4 **)(pAVar10 + 4) = puVar5;
          *(undefined4 *)(pAVar10 + 8) = 1;
          *puVar5 = 0;
          *(undefined4 *)pAVar10 = 0;
          ArraySetLength<Item*>(uVar18,pAVar10);
          if (0 < (int)local_94) {
            iVar2 = 0;
            do {
              local_98 = 0;
              AEFile::Read((int *)&local_98,local_3c);
              if (local_98 == 0xffffffff) {
                *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = 0;
              }
              else {
                local_9c = 0;
                AEFile::Read(&local_9c,local_3c);
                iVar21 = local_9c;
                pIVar17 = *(Item **)(*(int *)(Globals::items + 4) + local_98 * 4);
                iVar14 = Item::getMaxPrice(pIVar17);
                uVar4 = Item::makeItem(pIVar17,iVar21,iVar14);
                *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = uVar4;
                local_a0 = local_a0 & 0xffffff00;
                AEFile::Read((bool *)&local_a0,local_3c);
                Item::setUnsaleable(*(Item **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_a0._0_1_);
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 < (int)local_94);
          }
          Ship::replaceEquipment(*(Ship **)(this_00 + 0x134),pAVar10);
        }
        local_98 = 0;
        AEFile::Read((int *)&local_98,local_3c);
        uVar18 = local_98;
        if (0 < (int)local_98) {
          pAVar10 = operator_new(0xc);
          puVar5 = operator_new__(4);
          *(undefined4 **)(pAVar10 + 4) = puVar5;
          *(undefined4 *)(pAVar10 + 8) = 1;
          *puVar5 = 0;
          *(undefined4 *)pAVar10 = 0;
          ArraySetLength<Item*>(uVar18,pAVar10);
          if (0 < (int)local_98) {
            iVar2 = 0;
            do {
              local_a4 = 0;
              AEFile::Read(&local_9c,local_3c);
              AEFile::Read((int *)&local_a0,local_3c);
              AEFile::Read(&local_a4,local_3c);
              local_a8 = local_a8 & 0xffffff00;
              AEFile::Read((bool *)&local_a8,local_3c);
              uVar18 = local_a0;
              pIVar17 = *(Item **)(*(int *)(Globals::items + 4) + local_9c * 4);
              iVar21 = Item::getMaxPrice(pIVar17);
              uVar4 = Item::makeItem(pIVar17,uVar18,iVar21);
              *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = uVar4;
              Item::setPrice(*(Item **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_a4);
              Item::setUnsaleable(*(Item **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_a8._0_1_);
              iVar2 = iVar2 + 1;
            } while (iVar2 < (int)local_98);
          }
          Ship::replaceCargo(*(Ship **)(this_00 + 0x134),pAVar10);
        }
      }
      puVar5 = operator_new(0xc);
      puVar15 = operator_new__(4);
      puVar5[1] = puVar15;
      puVar5[2] = 1;
      *puVar15 = 0;
      *puVar5 = 0;
      local_8c = 0;
      *(undefined4 **)(this_00 + 0x70) = puVar5;
      AEFile::Read((int *)&local_8c,local_3c);
      ArraySetLength<int>(local_8c,*(Array **)(this_00 + 0x70));
      if (0 < (int)local_8c) {
        iVar2 = 0;
        iVar21 = 0;
        do {
          AEFile::Read((int *)(*(int *)(*(int *)(this_00 + 0x70) + 4) + iVar2),local_3c);
          iVar21 = iVar21 + 1;
          iVar2 = iVar2 + 4;
        } while (iVar21 < (int)local_8c);
      }
      AEFile::Read((int *)(this_00 + 0xd0),local_3c);
      AEFile::Read((bool *)(this_00 + 0xd4),local_3c);
      AEFile::Read((int *)(this_00 + 0xd8),local_3c);
      AEFile::Read((bool *)(this_00 + 0xdc),local_3c);
      local_90 = 0;
      AEFile::Read((int *)&local_90,local_3c);
      uVar18 = local_90;
      if (0 < (int)local_90) {
        pAVar10 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar10 + 4) = puVar5;
        *(undefined4 *)(pAVar10 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar10 = 0;
        ArraySetLength<Item*>(uVar18,pAVar10);
        if (0 < (int)local_90) {
          iVar2 = 0;
          do {
            local_9c = 0;
            AEFile::Read((int *)&local_94,local_3c);
            AEFile::Read((int *)&local_98,local_3c);
            AEFile::Read(&local_9c,local_3c);
            local_a0 = local_a0 & 0xffffff00;
            AEFile::Read((bool *)&local_a0,local_3c);
            uVar18 = local_98;
            pIVar17 = *(Item **)(*(int *)(Globals::items + 4) + local_94 * 4);
            iVar21 = Item::getMaxPrice(pIVar17);
            uVar4 = Item::makeItem(pIVar17,uVar18,iVar21);
            *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = uVar4;
            Item::setPrice(*(Item **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_9c);
            Item::setUnsaleable(*(Item **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_a0._0_1_);
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)local_90);
        }
        *(Array **)(this_00 + 0x180) = pAVar10;
      }
      local_94 = 0;
      AEFile::Read((int *)&local_94,local_3c);
      uVar18 = local_94;
      if (0 < (int)local_94) {
        pAVar10 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar10 + 4) = puVar5;
        *(undefined4 *)(pAVar10 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar10 = 0;
        ArraySetLength<Ship*>(uVar18,pAVar10);
        if (0 < (int)local_94) {
          iVar2 = 0;
          do {
            local_98 = 0;
            AEFile::Read((int *)&local_98,local_3c);
            uVar4 = Ship::makeShip(*(Ship **)(*(int *)(Globals::ships + 4) + local_98 * 4),-1);
            *(undefined4 *)(*(int *)(pAVar10 + 4) + iVar2 * 4) = uVar4;
            local_9c = 0;
            AEFile::Read(&local_9c,local_3c);
            Ship::setRace(*(Ship **)(*(int *)(pAVar10 + 4) + iVar2 * 4),local_9c);
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)local_94);
        }
        *(Array **)(this_00 + 0x184) = pAVar10;
      }
      AEFile::Read((bool *)(this_00 + 0x103),local_3c);
      AEFile::Read((bool *)(this_00 + 0x115),local_3c);
      AEFile::Read((bool *)(this_00 + 0x116),local_3c);
      AEFile::Read((int *)local_88,local_3c);
      pAVar10 = operator_new(0xc);
      puVar6 = operator_new__(1);
      *(undefined1 **)(pAVar10 + 4) = puVar6;
      *(undefined4 *)(pAVar10 + 8) = 1;
      *puVar6 = 0;
      *(undefined4 *)pAVar10 = 0;
      *(Array **)(this_00 + 0x178) = pAVar10;
      ArraySetLength<bool>((uint)local_88[0],pAVar10);
      puVar12 = *(uint **)(this_00 + 0x178);
      if (*puVar12 != 0) {
        uVar18 = 0;
        do {
          AEFile::Read((bool *)(puVar12[1] + uVar18),local_3c);
          puVar12 = *(uint **)(this_00 + 0x178);
          uVar18 = uVar18 + 1;
        } while (uVar18 < *puVar12);
      }
      AEFile::Read((int *)(this_00 + 0x1b4),local_3c);
      if (*(int *)(this_00 + 0x1b4) == 0x6e6a78) {
        local_98 = 0;
        AEFile::Read((int *)&local_98,local_3c);
        uVar18 = local_98;
        if (0 < (int)local_98) {
          pAVar10 = operator_new(0xc);
          puVar5 = operator_new__(4);
          *(undefined4 **)(pAVar10 + 4) = puVar5;
          *(undefined4 *)(pAVar10 + 8) = 1;
          *puVar5 = 0;
          *(undefined4 *)pAVar10 = 0;
          ArraySetLength<int>(uVar18,pAVar10);
          if (0 < (int)local_98) {
            iVar2 = 0;
            iVar21 = 0;
            do {
              AEFile::Read((int *)(*(int *)(pAVar10 + 4) + iVar2),local_3c);
              iVar21 = iVar21 + 1;
              iVar2 = iVar2 + 4;
            } while (iVar21 < (int)local_98);
          }
          Ship::setMods(*(Ship **)(this_00 + 0x130),pAVar10);
        }
        AEFile::Read((int *)&local_98,local_3c);
        uVar18 = local_98;
        if (0 < (int)local_98) {
          pAVar10 = operator_new(0xc);
          puVar5 = operator_new__(4);
          *(undefined4 **)(pAVar10 + 4) = puVar5;
          *(undefined4 *)(pAVar10 + 8) = 1;
          *puVar5 = 0;
          *(undefined4 *)pAVar10 = 0;
          ArraySetLength<int>(uVar18,pAVar10);
          if (0 < (int)local_98) {
            iVar2 = 0;
            iVar21 = 0;
            do {
              AEFile::Read((int *)(*(int *)(pAVar10 + 4) + iVar2),local_3c);
              iVar21 = iVar21 + 1;
              iVar2 = iVar2 + 4;
            } while (iVar21 < (int)local_98);
          }
          Ship::setMods(*(Ship **)(this_00 + 0x134),pAVar10);
        }
        local_9c = 0;
        AEFile::Read(&local_9c,local_3c);
        if (0 < local_9c) {
          iVar2 = 0;
          do {
            local_98 = 0;
            AEFile::Read((int *)&local_98,local_3c);
            uVar18 = local_98;
            if (0 < (int)local_98) {
              pAVar10 = operator_new(0xc);
              puVar5 = operator_new__(4);
              *(undefined4 **)(pAVar10 + 4) = puVar5;
              *(undefined4 *)(pAVar10 + 8) = 1;
              *puVar5 = 0;
              *(undefined4 *)pAVar10 = 0;
              ArraySetLength<int>(uVar18,pAVar10);
              if (0 < (int)local_98) {
                iVar14 = 0;
                iVar21 = 0;
                do {
                  AEFile::Read((int *)(*(int *)(pAVar10 + 4) + iVar14),local_3c);
                  iVar21 = iVar21 + 1;
                  iVar14 = iVar14 + 4;
                } while (iVar21 < (int)local_98);
              }
              Ship::setMods(*(Ship **)(*(int *)(*(int *)(this_00 + 0x184) + 4) + iVar2 * 4),pAVar10)
              ;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < local_9c);
        }
        uVar18 = *(uint *)pAVar8;
        if (uVar18 != 0xffffffff) {
          uVar19 = 0;
          do {
            pGVar16 = this_00 + 0x138;
            if (uVar19 != uVar18) {
              pGVar16 = (GameRecord *)(*(int *)(pAVar8 + 4) + uVar19 * 4);
            }
            pSVar9 = *(Station **)pGVar16;
            if (pSVar9 != (Station *)0x0) {
              local_a0 = 0;
              AEFile::Read((int *)&local_a0,local_3c);
              if (0 < (int)local_a0) {
                iVar2 = 0;
                do {
                  local_a4 = 0;
                  AEFile::Read(&local_a4,local_3c);
                  if (0 < local_a4) {
                    iVar21 = 0;
                    do {
                      AEFile::Read((int *)&local_a8,local_3c);
                      iVar14 = Station::getShips(pSVar9);
                      Ship::addMod(*(Ship **)(*(int *)(iVar14 + 4) + iVar2 * 4),local_a8);
                      iVar21 = iVar21 + 1;
                    } while (iVar21 < local_a4);
                  }
                  iVar2 = iVar2 + 1;
                } while (iVar2 < (int)local_a0);
              }
              uVar18 = *(uint *)pAVar8;
            }
            uVar19 = uVar19 + 1;
          } while (uVar19 < uVar18 + 1);
        }
        local_88[0] = (RecordHandler *)0x0;
        AEFile::Read((int *)local_88,local_3c);
        pRVar3 = local_88[0];
        if (0 < (int)local_88[0]) {
          pAVar8 = operator_new(0xc);
          puVar5 = operator_new__(4);
          *(undefined4 **)(pAVar8 + 4) = puVar5;
          *(undefined4 *)(pAVar8 + 8) = 1;
          *puVar5 = 0;
          *(undefined4 *)pAVar8 = 0;
          *(Array **)(this_00 + 0x1ac) = pAVar8;
          ArraySetLength<Wanted*>((uint)pRVar3,pAVar8);
          if (0 < (int)local_88[0]) {
            iVar2 = 0;
            do {
              uVar4 = readWanted(local_88[0],local_3c);
              *(undefined4 *)(*(int *)(*(int *)(this_00 + 0x1ac) + 4) + iVar2 * 4) = uVar4;
              iVar2 = iVar2 + 1;
            } while (iVar2 < (int)local_88[0]);
          }
        }
        pGVar16 = this_00 + 0x19c;
        iVar2 = 0;
        do {
          AEFile::Read((int *)pGVar16,local_3c);
          iVar2 = iVar2 + 1;
          pGVar16 = pGVar16 + 4;
        } while (iVar2 < 4);
        AEFile::Read((bool *)(this_00 + 0x117),local_3c);
        AEFile::Read((int *)(this_00 + 0x1b0),local_3c);
        AEFile::Read((bool *)(this_00 + 0x104),local_3c);
        AEFile::Read((bool *)(this_00 + 0x105),local_3c);
        AEFile::Read((bool *)(this_00 + 0x108),local_3c);
        AEFile::Read((bool *)(this_00 + 0x106),local_3c);
        AEFile::Read((bool *)(this_00 + 0x107),local_3c);
        AEFile::Read((bool *)(this_00 + 0x10a),local_3c);
        AEFile::Read((bool *)(this_00 + 0x10b),local_3c);
        AEFile::Read((bool *)(this_00 + 0x10c),local_3c);
        AEFile::Read((int *)local_88,local_3c);
        pAVar8 = operator_new(0xc);
        puVar6 = operator_new__(1);
        *(undefined1 **)(pAVar8 + 4) = puVar6;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar6 = 0;
        *(undefined4 *)pAVar8 = 0;
        *(Array **)(this_00 + 0x17c) = pAVar8;
        ArraySetLength<bool>((uint)local_88[0],pAVar8);
        puVar12 = *(uint **)(this_00 + 0x17c);
        if (*puVar12 != 0) {
          uVar18 = 0;
          do {
            AEFile::Read((bool *)(puVar12[1] + uVar18),local_3c);
            puVar12 = *(uint **)(this_00 + 0x17c);
            uVar18 = uVar18 + 1;
          } while (uVar18 < *puVar12);
        }
        AEFile::Read((bool *)(this_00 + 0x119),local_3c);
        AEFile::Read((bool *)(this_00 + 0x109),local_3c);
        AEFile::Read((bool *)(this_00 + 0x11a),local_3c);
        AEFile::Read((int *)(this_00 + 0xe0),local_3c);
        AEFile::Read((bool *)(this_00 + 0x10d),local_3c);
        AEFile::Read((bool *)(this_00 + 0x10e),local_3c);
        AEFile::Read((bool *)(this_00 + 0x10f),local_3c);
        AEFile::Read((bool *)(this_00 + 0x110),local_3c);
        AEFile::Read((bool *)(this_00 + 0x111),local_3c);
        AEFile::Read((bool *)(this_00 + 0x113),local_3c);
        AEFile::Read((bool *)(this_00 + 0x112),local_3c);
        AEFile::Read((bool *)(this_00 + 0x114),local_3c);
        AEFile::Close(local_3c);
      }
      else {
        AEFile::Close(local_3c);
      }
    }
  }
  AbyssEngine::String::~String((String *)aAStack_30);
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== RecordHandler::readRecord  @0x000ddf30  (4 bytes)
/* RecordHandler::readRecord(int) */

void RecordHandler::readRecord(int param_1)

{
  int in_r1;
  
  recordStoreRead((RecordHandler *)param_1,in_r1);
  return;
}

// ===== RecordHandler::loadResolutionValue  @0x000ddf34  (464 bytes)
/* RecordHandler::loadResolutionValue(float) */

void RecordHandler::loadResolutionValue(float param_1)

{
  int in_r0;
  int iVar1;
  String *pSVar2;
  short local_94;
  bool bStack_91;
  int iStack_90;
  String aSStack_8c [8];
  uint local_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  bool bStack_74;
  bool bStack_73;
  bool abStack_72 [2];
  bool bStack_70;
  bool abStack_6f [3];
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float afStack_58 [2];
  bool bStack_4e;
  bool bStack_4d;
  bool bStack_4c;
  bool bStack_4b;
  bool bStack_4a;
  bool abStack_49 [3];
  bool bStack_46;
  bool bStack_45;
  bool bStack_44;
  bool bStack_43;
  bool bStack_42;
  bool bStack_41;
  bool bStack_40;
  bool abStack_3f [3];
  float local_3c [4];
  int iStack_2c;
  int aiStack_28 [3];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = AEFile::FileExist((String *)(in_r0 + 8));
  if (iVar1 == 1) {
    AEFile::OpenRead((String *)(in_r0 + 8),&local_84);
    AEFile::Read(&bStack_70,local_84);
    AEFile::Read(abStack_6f,local_84);
    AEFile::Read(&fStack_6c,local_84);
    AEFile::Read(&fStack_68,local_84);
    AEFile::Read(&fStack_64,local_84);
    AEFile::Read(&fStack_80,local_84);
    AEFile::Read(&bStack_74,local_84);
    AEFile::Read(&bStack_73,local_84);
    AEFile::Read(&fStack_7c,local_84);
    AEFile::Read(&fStack_5c,local_84);
    AEFile::Read(afStack_58,local_84);
    pSVar2 = (String *)AbyssEngine::String::String(aSStack_8c);
    AEFile::Read(pSVar2,local_84,false);
    AEFile::Read(&iStack_90,local_84);
    AEFile::Read(&bStack_91,local_84);
    AEFile::Read(&iStack_2c,local_84);
    AEFile::Read(aiStack_28,local_84);
    AEFile::Read(&fStack_78,local_84);
    AEFile::Read(abStack_72,local_84);
    AEFile::Read(&bStack_4e,local_84);
    AEFile::Read(&bStack_4d,local_84);
    AEFile::Read(&bStack_4c,local_84);
    AEFile::Read(&fStack_60,local_84);
    local_94 = -1;
    AEFile::Read(&local_94,local_84);
    AEFile::Read(&bStack_91,local_84);
    AEFile::Read(&bStack_4b,local_84);
    AEFile::Read(&bStack_4a,local_84);
    AEFile::Read(&bStack_46,local_84);
    AEFile::Read(&bStack_45,local_84);
    AEFile::Read(&bStack_44,local_84);
    AEFile::Read(abStack_49,local_84);
    AEFile::Read(&bStack_43,local_84);
    AEFile::Read(&bStack_42,local_84);
    AEFile::Read(&bStack_41,local_84);
    AEFile::Read(&bStack_40,local_84);
    AEFile::Read(abStack_3f,local_84);
    AEFile::Read(local_3c,local_84);
    AEFile::Close(local_84);
    AbyssEngine::String::~String(aSStack_8c);
  }
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== RecordHandler::loadOptions  @0x000de120  (1018 bytes)
/* RecordHandler::loadOptions() */

void __thiscall RecordHandler::loadOptions(RecordHandler *this)

{
  int iVar1;
  RecordHandler *this_00;
  void *pvVar2;
  String *pSVar3;
  String *this_01;
  RecordHandler *pRVar4;
  float fVar5;
  short sStack_22;
  String aSStack_20 [4];
  int local_1c;
  uint local_18;
  int local_14;
  
  pRVar4 = this + 8;
  local_14 = __stack_chk_guard;
  iVar1 = AEFile::FileExist(pRVar4);
  if (iVar1 == 1) {
    this_00 = (RecordHandler *)AEFile::OpenRead(pRVar4,&local_18);
    iVar1 = checkHash(this_00,local_18);
    AEFile::Close(local_18);
    if (iVar1 == 1) {
      AEFile::OpenRead(pRVar4,&local_18);
      AEFile::Read((bool *)(Globals::options + 0x10),local_18);
      AEFile::Read((bool *)(Globals::options + 0x11),local_18);
      *(undefined1 *)(Globals::status + 0xfa) = Globals::options[0x11];
      AEFile::Read((float *)(Globals::options + 0x14),local_18);
      AEFile::Read((float *)(Globals::options + 0x18),local_18);
      AEFile::Read((float *)(Globals::options + 0x1c),local_18);
      AEFile::Read((float *)Globals::options,local_18);
      AEFile::Read((bool *)(Globals::options + 0xc),local_18);
      AEFile::Read((bool *)(Globals::options + 0xd),local_18);
      AEFile::Read((float *)(Globals::options + 4),local_18);
      AEFile::Read((float *)(Globals::options + 0x24),local_18);
      AEFile::Read((float *)(Globals::options + 0x28),local_18);
      if (Globals::instantActionPlayerName != (String *)0x0) {
        pvVar2 = (void *)AbyssEngine::String::~String(Globals::instantActionPlayerName);
        operator_delete(pvVar2);
        Globals::instantActionPlayerName = (String *)0x0;
      }
      pSVar3 = (String *)AbyssEngine::String::String(aSStack_20);
      AEFile::Read(pSVar3,local_18,false);
      if (local_1c != 0) {
        this_01 = operator_new(8);
        AbyssEngine::String::String(this_01,aSStack_20,false);
        Globals::instantActionPlayerName = this_01;
      }
      AEFile::Read(&Globals::lastRecordWritten,local_18);
      AEFile::Read((bool *)&Globals::first_start_ever,local_18);
      AEFile::Read((int *)(Globals::options + 0x54),local_18);
      AEFile::Read((int *)(Globals::options + 0x58),local_18);
      AEFile::Read((float *)(Globals::options + 8),local_18);
      AEFile::Read((bool *)(Globals::options + 0xe),local_18);
      AEFile::Read((bool *)(Globals::options + 0x32),local_18);
      AEFile::Read((bool *)(Globals::options + 0x33),local_18);
      AEFile::Read((bool *)(Globals::options + 0x34),local_18);
      AEFile::Read((float *)(Globals::options + 0x20),local_18);
      sStack_22 = -1;
      AEFile::Read(&sStack_22,local_18);
      AEFile::Read((bool *)&Globals::startLiteVersionWithMoreCredits,local_18);
      AEFile::Read((bool *)(Globals::options + 0x35),local_18);
      AEFile::Read((bool *)(Globals::options + 0x36),local_18);
      AEFile::Read((bool *)(Globals::options + 0x3a),local_18);
      AEFile::Read((bool *)(Globals::options + 0x3b),local_18);
      AEFile::Read((bool *)(Globals::options + 0x3c),local_18);
      AEFile::Read((bool *)(Globals::options + 0x37),local_18);
      AEFile::Read((bool *)(Globals::options + 0x3d),local_18);
      AEFile::Read((bool *)(Globals::options + 0x3e),local_18);
      AEFile::Read((bool *)(Globals::options + 0x3f),local_18);
      AEFile::Read((bool *)(Globals::options + 0x40),local_18);
      AEFile::Read((bool *)(Globals::options + 0x41),local_18);
      AEFile::Read((float *)(Globals::options + 0x44),local_18);
      AEFile::Read((bool *)(Globals::options + 0x48),local_18);
      AEFile::Read((bool *)(Globals::options + 0x38),local_18);
      AEFile::Read((bool *)(Globals::options + 0x4e),local_18);
      AEFile::Read((bool *)(Globals::options + 0x49),local_18);
      AEFile::Read((bool *)(Globals::options + 0x4a),local_18);
      AEFile::Read((bool *)(Globals::options + 0x4b),local_18);
      AEFile::Read((bool *)(Globals::options + 0x4c),local_18);
      AEFile::Read((bool *)(Globals::options + 0x4d),local_18);
      AEFile::Read((int *)(Globals::options + 0x50),local_18);
      AEFile::Read((bool *)(Globals::options + 0x60),local_18);
      AEFile::Read((bool *)(Globals::options + 0x61),local_18);
      AEFile::Close(local_18);
      if (-1 < sStack_22) {
        if (sStack_22 == 9) {
          sStack_22 = 0;
        }
        GameText::setLanguage(Globals::gameText,sStack_22,0xd49);
        Globals::loadFont(Globals::globals,(int)sStack_22);
      }
      if (Globals::sound != (FModSound *)0x0) {
        FModSound::setAudioLanguage((int)Globals::sound);
        FModSound::enableCategory((int)Globals::sound,true);
        FModSound::enableCategory((int)Globals::sound,true);
        fVar5 = (float)FModSound::enableCategory((int)Globals::sound,true);
        fVar5 = (float)FModSound::setVolume(Globals::sound,1,fVar5);
        fVar5 = (float)FModSound::setVolume(Globals::sound,2,fVar5);
        FModSound::setVolume(Globals::sound,3,fVar5);
      }
      AEFile::Read((bool *)(Globals::options + 0x62),local_18);
      AbyssEngine::String::~String(aSStack_20);
    }
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RecordHandler::checkHash  @0x000de618  (276 bytes)
/* RecordHandler::checkHash(unsigned int) */

void __thiscall RecordHandler::checkHash(RecordHandler *this,uint param_1)

{
  uint __size;
  void *pvVar1;
  uint *puVar2;
  undefined1 *__ptr;
  void *pvVar3;
  uchar *md;
  SHA256_CTX *c;
  int iVar4;
  undefined8 local_38;
  undefined1 uStack_30;
  undefined7 local_2f;
  undefined1 uStack_28;
  char acStack_27 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  __size = AEFile::GetFileSize(param_1);
  if (-1 < (int)__size) {
    pvVar1 = operator_new__(__size);
    AEFile::Read(__size,pvVar1,param_1);
    puVar2 = operator_new(0xc);
    __ptr = operator_new__(1);
    puVar2[1] = (uint)__ptr;
    *puVar2 = 0;
    *__ptr = 0;
    puVar2[2] = __size;
    pvVar3 = realloc(__ptr,__size);
    puVar2[1] = (uint)pvVar3;
    __aeabi_memcpy((int)pvVar3 + *puVar2,pvVar1,__size);
    *puVar2 = puVar2[2];
    operator_delete__(pvVar1);
    if (0x21 < *puVar2) {
      md = operator_new__(0x20);
      c = operator_new(0x70);
      SHA256_Init(c);
      SHA256_Update(c,(void *)puVar2[1],*puVar2 - 0x20);
      uStack_28 = 0x72;
      builtin_strncpy(acStack_27,"&_%=$+#",8);
      local_38 = 0x4c4c3052a7c22b23;
      uStack_30 = 0x33;
      local_2f = 0x65745361302872;
      SHA256_Update(c,&local_38,0x19);
      SHA256_Update(c,g_android_origami_super_club,0x10);
      SHA256_Final(md,c);
      iVar4 = 0;
      do {
        if (md[iVar4] != *(uchar *)(*puVar2 + puVar2[1] + -0x20 + iVar4)) break;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x20);
      operator_delete__(md);
      operator_delete(c);
    }
  }
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== RecordHandler::saveOptions  @0x000de74c  (584 bytes)
/* RecordHandler::saveOptions() */

void __thiscall RecordHandler::saveOptions(RecordHandler *this)

{
  short sVar1;
  int iVar2;
  String *pSVar3;
  RecordHandler *pRVar4;
  float fVar5;
  String aSStack_20 [8];
  uint local_18;
  int local_14;
  
  pRVar4 = this + 8;
  local_14 = __stack_chk_guard;
  iVar2 = AEFile::FileExist(pRVar4);
  if (iVar2 == 1) {
    AEFile::FileDelete(pRVar4);
  }
  AEFile::OpenWrite(pRVar4,&local_18);
  AEFile::Write((bool)Globals::options[0x10],local_18);
  fVar5 = (float)AEFile::Write((bool)Globals::options[0x11],local_18);
  fVar5 = (float)AEFile::Write(fVar5,Globals::options._20_4_);
  fVar5 = (float)AEFile::Write(fVar5,Globals::options._24_4_);
  fVar5 = (float)AEFile::Write(fVar5,Globals::options._28_4_);
  AEFile::Write(fVar5,Globals::options._0_4_);
  AEFile::Write((bool)Globals::options[0xc],local_18);
  fVar5 = (float)AEFile::Write((bool)Globals::options[0xd],local_18);
  fVar5 = (float)AEFile::Write(fVar5,Globals::options._4_4_);
  fVar5 = (float)AEFile::Write(fVar5,Globals::options._36_4_);
  AEFile::Write(fVar5,Globals::options._40_4_);
  if (Globals::instantActionPlayerName == (String *)0x0) {
    pSVar3 = (String *)AbyssEngine::String::String(aSStack_20,"",false);
    AEFile::Write(pSVar3,local_18,false);
    AbyssEngine::String::~String(aSStack_20);
  }
  else {
    AEFile::Write(Globals::instantActionPlayerName,local_18,false);
  }
  AEFile::Write(Globals::lastRecordWritten,local_18);
  AEFile::Write((bool)Globals::first_start_ever,local_18);
  AEFile::Write(Globals::options._84_4_,local_18);
  fVar5 = (float)AEFile::Write(Globals::options._88_4_,local_18);
  AEFile::Write(fVar5,Globals::options._8_4_);
  AEFile::Write((bool)Globals::options[0xe],local_18);
  AEFile::Write((bool)Globals::options[0x32],local_18);
  AEFile::Write((bool)Globals::options[0x33],local_18);
  fVar5 = (float)AEFile::Write((bool)Globals::options[0x34],local_18);
  AEFile::Write(fVar5,Globals::options._32_4_);
  sVar1 = GameText::getLanguage();
  AEFile::Write(sVar1,local_18);
  AEFile::Write((bool)Globals::startLiteVersionWithMoreCredits,local_18);
  AEFile::Write((bool)Globals::options[0x35],local_18);
  AEFile::Write((bool)Globals::options[0x36],local_18);
  AEFile::Write((bool)Globals::options[0x3a],local_18);
  AEFile::Write((bool)Globals::options[0x3b],local_18);
  AEFile::Write((bool)Globals::options[0x3c],local_18);
  AEFile::Write((bool)Globals::options[0x37],local_18);
  AEFile::Write((bool)Globals::options[0x3d],local_18);
  AEFile::Write((bool)Globals::options[0x3e],local_18);
  AEFile::Write((bool)Globals::options[0x3f],local_18);
  AEFile::Write((bool)Globals::options[0x40],local_18);
  fVar5 = (float)AEFile::Write((bool)Globals::options[0x41],local_18);
  AEFile::Write(fVar5,Globals::options._68_4_);
  AEFile::Write((bool)Globals::options[0x48],local_18);
  AEFile::Write((bool)Globals::options[0x38],local_18);
  AEFile::Write((bool)Globals::options[0x4e],local_18);
  AEFile::Write((bool)Globals::options[0x49],local_18);
  AEFile::Write((bool)Globals::options[0x4a],local_18);
  AEFile::Write((bool)Globals::options[0x4b],local_18);
  AEFile::Write((bool)Globals::options[0x4c],local_18);
  AEFile::Write((bool)Globals::options[0x4d],local_18);
  AEFile::Write(Globals::options._80_4_,local_18);
  AEFile::Write((bool)Globals::options[0x60],local_18);
  AEFile::Write((bool)Globals::options[0x61],local_18);
  AEFile::Write((bool)Globals::options[0x62],local_18);
  AEFile::Close(local_18);
  addHashToOptions(this);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RecordHandler::addHashToOptions  @0x000de9c8  (240 bytes)
/* RecordHandler::addHashToOptions() */

void __thiscall RecordHandler::addHashToOptions(RecordHandler *this)

{
  signed *psVar1;
  size_t len;
  uchar *md;
  SHA256_CTX *c;
  signed *psVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  signed *local_4c;
  undefined8 local_48;
  undefined1 uStack_40;
  undefined7 local_3f;
  undefined1 uStack_38;
  char acStack_37 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_4c = (signed *)0x0;
  len = readOptionsFileAsByteArray(this,&local_4c);
  if (-1 < (int)len) {
    md = operator_new__(0x20);
    c = operator_new(0x70);
    SHA256_Init(c);
    psVar1 = local_4c;
    SHA256_Update(c,local_4c,len);
    uStack_38 = 0x72;
    builtin_strncpy(acStack_37,"&_%=$+#",8);
    local_48 = 0x4c4c3052a7c22b23;
    uStack_40 = 0x33;
    local_3f = 0x65745361302872;
    SHA256_Update(c,&local_48,0x19);
    SHA256_Update(c,g_android_origami_super_club,0x10);
    SHA256_Final(md,c);
    psVar2 = operator_new__(len + 0x20);
    __aeabi_memcpy(psVar2,psVar1,len);
    uVar4 = *(undefined8 *)(md + 8);
    uVar5 = *(undefined8 *)(md + 0x10);
    uVar6 = *(undefined8 *)(md + 0x18);
    puVar3 = (undefined8 *)(psVar2 + len);
    *puVar3 = *(undefined8 *)md;
    puVar3[1] = uVar4;
    puVar3[2] = uVar5;
    puVar3[3] = uVar6;
    writeByteArrayAsOptionsFile(this,psVar2,len + 0x20);
    if (psVar1 != (signed *)0x0) {
      operator_delete__(psVar1);
    }
    local_4c = (signed *)0x0;
    operator_delete__(psVar2);
    operator_delete__(md);
    operator_delete(c);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RecordHandler::readRecordAsByteArray  @0x000deac8  (164 bytes)
/* RecordHandler::readRecordAsByteArray(signed char**, int, bool) */

void __thiscall
RecordHandler::readRecordAsByteArray(RecordHandler *this,signed **param_1,int param_2,bool param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  signed *psVar4;
  uint local_2c [2];
  AbyssEngine aAStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_2c[0] = 0;
  AbyssEngine::String::Set(CONCAT44(param_1,local_2c));
  iVar1 = 0x10;
  if (param_3) {
    iVar1 = 0x18;
  }
  AbyssEngine::operator+(aAStack_24,this + iVar1,(String *)local_2c);
  AbyssEngine::String::~String((String *)local_2c);
  iVar1 = AEFile::FileExist(aAStack_24);
  if (iVar1 == 1) {
    AEFile::OpenRead(aAStack_24,local_2c);
    uVar2 = AEFile::GetFileSize(local_2c[0]);
    uVar3 = uVar2;
    if (0x7fffffff < uVar2) {
      uVar3 = 0xffffffff;
    }
    psVar4 = operator_new__(uVar3);
    *param_1 = psVar4;
    AEFile::Read(uVar2,psVar4,local_2c[0]);
    AEFile::Close(local_2c[0]);
  }
  AbyssEngine::String::~String((String *)aAStack_24);
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== RecordHandler::writeByteArrayAsRecord  @0x000deb8c  (142 bytes)
/* RecordHandler::writeByteArrayAsRecord(signed char*, int, int, bool) */

void __thiscall
RecordHandler::writeByteArrayAsRecord
          (RecordHandler *this,signed *param_1,int param_2,int param_3,bool param_4)

{
  int iVar1;
  undefined3 in_stack_00000001;
  uint local_2c [2];
  AbyssEngine aAStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_2c[0] = 0;
  AbyssEngine::String::Set(CONCAT44(param_3 >> 0x1f,local_2c));
  iVar1 = 0x10;
  if (_param_4 != 0) {
    iVar1 = 0x18;
  }
  AbyssEngine::operator+(aAStack_24,this + iVar1,(String *)local_2c);
  AbyssEngine::String::~String((String *)local_2c);
  iVar1 = AEFile::FileExist(aAStack_24);
  if (iVar1 == 1) {
    AEFile::FileDelete(aAStack_24);
  }
  AEFile::OpenWrite(aAStack_24,local_2c);
  AEFile::Write(param_2,param_1,local_2c[0]);
  AEFile::Close(local_2c[0]);
  AbyssEngine::String::~String((String *)aAStack_24);
  if (__stack_chk_guard - local_1c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_1c);
  }
  return;
}

// ===== RecordHandler::readOptionsFileAsByteArray  @0x000dec38  (124 bytes)
/* RecordHandler::readOptionsFileAsByteArray(signed char**) */

void __thiscall RecordHandler::readOptionsFileAsByteArray(RecordHandler *this,signed **param_1)

{
  String *pSVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  signed *psVar5;
  uint local_20;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String(aSStack_1c,this + 8,false);
  iVar2 = AEFile::FileExist(pSVar1);
  if (iVar2 == 1) {
    AEFile::OpenRead(aSStack_1c,&local_20);
    uVar3 = AEFile::GetFileSize(local_20);
    uVar4 = uVar3;
    if (0x7fffffff < uVar3) {
      uVar4 = 0xffffffff;
    }
    psVar5 = operator_new__(uVar4);
    *param_1 = psVar5;
    AEFile::Read(uVar3,psVar5,local_20);
    AEFile::Close(local_20);
  }
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== RecordHandler::writeByteArrayAsOptionsFile  @0x000decd0  (100 bytes)
/* RecordHandler::writeByteArrayAsOptionsFile(signed char*, int) */

void __thiscall
RecordHandler::writeByteArrayAsOptionsFile(RecordHandler *this,signed *param_1,int param_2)

{
  String *pSVar1;
  int iVar2;
  uint local_20;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String(aSStack_1c,this + 8,false);
  iVar2 = AEFile::FileExist(pSVar1);
  if (iVar2 == 1) {
    AEFile::FileDelete(aSStack_1c);
  }
  AEFile::OpenWrite(aSStack_1c,&local_20);
  AEFile::Write(param_2,param_1,local_20);
  AEFile::Close(local_20);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== RecordHandler::addHash  @0x000ded4c  (256 bytes)
/* RecordHandler::addHash(int) */

void __thiscall RecordHandler::addHash(RecordHandler *this,int param_1)

{
  signed *psVar1;
  size_t len;
  uchar *md;
  SHA256_CTX *c;
  signed *psVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  signed *local_4c;
  undefined8 local_48;
  undefined1 uStack_40;
  undefined7 local_3f;
  undefined1 uStack_38;
  char acStack_37 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_4c = (signed *)0x0;
  len = readRecordAsByteArray(this,&local_4c,param_1,false);
  if (-1 < (int)len) {
    md = operator_new__(0x20);
    c = operator_new(0x70);
    SHA256_Init(c);
    psVar1 = local_4c;
    SHA256_Update(c,local_4c,len);
    uStack_38 = 0x72;
    builtin_strncpy(acStack_37,"&_%=$+#",8);
    local_48 = 0x4c4c3052a7c22b23;
    uStack_40 = 0x33;
    local_3f = 0x65745361302872;
    SHA256_Update(c,&local_48,0x19);
    SHA256_Update(c,g_android_origami_super_club,0x10);
    SHA256_Final(md,c);
    psVar2 = operator_new__(len + 0x20);
    __aeabi_memcpy(psVar2,psVar1,len);
    puVar3 = (undefined8 *)(psVar2 + len);
    uVar4 = *(undefined8 *)(md + 8);
    uVar5 = *(undefined8 *)(md + 0x10);
    uVar6 = *(undefined8 *)(md + 0x18);
    *puVar3 = *(undefined8 *)md;
    puVar3[1] = uVar4;
    puVar3[2] = uVar5;
    puVar3[3] = uVar6;
    writeByteArrayAsRecord(this,psVar2,len + 0x20,param_1,false);
    if (psVar1 != (signed *)0x0) {
      operator_delete__(psVar1);
    }
    local_4c = (signed *)0x0;
    operator_delete__(psVar2);
    operator_delete__(md);
    operator_delete(c);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RecordHandler::readMission  @0x000dee5c  (554 bytes)
/* RecordHandler::readMission(unsigned int) */

void __thiscall RecordHandler::readMission(RecordHandler *this,uint param_1)

{
  String *pSVar1;
  uint uVar2;
  Agent *this_00;
  Mission *this_01;
  int iVar3;
  int *piVar4;
  int *piVar5;
  String aSStack_8c [8];
  String aSStack_84 [8];
  int local_7c;
  bool bStack_75;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  bool bStack_49;
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_28 = 0;
  AEFile::Read(&local_28,param_1);
  if (local_28 != -1) {
    pSVar1 = (String *)AbyssEngine::String::String(aSStack_30);
    AEFile::Read(pSVar1,param_1,true);
    AbyssEngine::String::String(aSStack_38);
    AEFile::Read(aSStack_38,param_1,true);
    AbyssEngine::String::String(aSStack_40);
    AEFile::Read(aSStack_40,param_1,true);
    AbyssEngine::String::String(aSStack_48);
    AEFile::Read(aSStack_48,param_1,true);
    bStack_49 = false;
    AEFile::Read(&bStack_49,param_1);
    local_50 = 0;
    AEFile::Read((int *)&local_50,param_1);
    piVar5 = (int *)0x0;
    if (0 < (int)local_50) {
      uVar2 = (uint)((ulonglong)local_50 * 4);
      if ((int)((ulonglong)local_50 * 4 >> 0x20) != 0) {
        uVar2 = 0xffffffff;
      }
      piVar5 = operator_new__(uVar2);
      iVar3 = 0;
      piVar4 = piVar5;
      do {
        AEFile::Read(piVar4,param_1);
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar3 < (int)local_50);
    }
    local_54 = 0;
    local_5c = 0;
    local_58 = 0;
    local_64 = 0;
    local_60 = 0;
    local_6c = 0;
    local_68 = 0;
    local_74 = 0;
    local_70 = 0;
    bStack_75 = false;
    AEFile::Read(&local_54,param_1);
    AEFile::Read(&local_58,param_1);
    AEFile::Read(&local_5c,param_1);
    AEFile::Read(&local_60,param_1);
    AEFile::Read(&local_64,param_1);
    AEFile::Read(&local_68,param_1);
    AEFile::Read(&local_6c,param_1);
    AEFile::Read(&local_70,param_1);
    AEFile::Read(&local_74,param_1);
    AEFile::Read(&bStack_75,param_1);
    local_7c = 0;
    AEFile::Read(&local_7c,param_1);
    if (local_7c < 1) {
      this_00 = (Agent *)0x0;
    }
    else {
      this_00 = (Agent *)readAgent(this,param_1);
    }
    if (bStack_49 == false) {
      this_01 = operator_new(100);
      iVar3 = local_28;
      AbyssEngine::String::String(aSStack_84,aSStack_30,false);
      Mission::Mission(this_01,iVar3,aSStack_84,piVar5,local_54,local_60,local_64,local_68);
      AbyssEngine::String::~String(aSStack_84);
    }
    else {
      this_01 = operator_new(100);
      Mission::Mission(this_01,local_28,local_60,local_64);
    }
    Mission::setCosts(this_01,local_58);
    Mission::setBonus(this_01,local_5c);
    Mission::setProductionGoods(this_01,local_6c,local_70);
    Mission::setStatusValue(this_01,local_74);
    Mission::setVisible(this_01,bStack_75);
    Mission::setAgent(this_01,this_00);
    AbyssEngine::String::String(aSStack_8c,aSStack_38,false);
    Mission::setTargetName(this_01,aSStack_8c);
    AbyssEngine::String::~String(aSStack_8c);
    if (this_00 != (Agent *)0x0) {
      Agent::setMission(this_00,this_01);
    }
    AbyssEngine::String::~String(aSStack_48);
    AbyssEngine::String::~String(aSStack_40);
    AbyssEngine::String::~String(aSStack_38);
    AbyssEngine::String::~String(aSStack_30);
  }
  if (__stack_chk_guard - local_24 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_24);
  }
  return;
}

// ===== RecordHandler::readAgent  @0x000df0ec  (914 bytes)
/* RecordHandler::readAgent(unsigned int) */

void __thiscall RecordHandler::readAgent(RecordHandler *this,uint param_1)

{
  uint uVar1;
  Agent *this_00;
  String *pSVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  String *this_01;
  int *piVar5;
  int iVar6;
  int *piVar7;
  Mission *local_c4;
  String aSStack_c0 [8];
  String aSStack_b8 [8];
  String aSStack_b0 [8];
  String aSStack_a8 [8];
  int local_a0;
  String aSStack_9c [4];
  int local_98;
  String aSStack_94 [4];
  int local_90;
  String aSStack_8c [8];
  String aSStack_84 [8];
  String aSStack_7c [8];
  String aSStack_74 [8];
  int local_6c;
  uint local_68;
  Agent AStack_61;
  Agent local_60;
  bool bStack_5f;
  bool bStack_5e;
  bool bStack_5d;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  piVar7 = (int *)0x0;
  local_28 = __stack_chk_guard;
  local_2c = 0;
  AEFile::Read(&local_2c,param_1);
  local_30 = 0;
  AEFile::Read(&local_30,param_1);
  local_34 = 0;
  AEFile::Read(&local_34,param_1);
  local_38 = 0;
  AEFile::Read(&local_38,param_1);
  local_3c = 0;
  AEFile::Read(&local_3c,param_1);
  local_40 = 0;
  AEFile::Read(&local_40,param_1);
  local_44 = 0;
  AEFile::Read(&local_44,param_1);
  local_48 = 0;
  AEFile::Read(&local_48,param_1);
  local_4c = 0;
  AEFile::Read(&local_4c,param_1);
  local_50 = 0;
  AEFile::Read(&local_50,param_1);
  local_54 = 0;
  AEFile::Read(&local_54,param_1);
  local_58 = 0;
  AEFile::Read(&local_58,param_1);
  local_5c = 0;
  AEFile::Read((int *)&local_5c,param_1);
  bStack_5d = false;
  AEFile::Read(&bStack_5d,param_1);
  bStack_5e = false;
  AEFile::Read(&bStack_5e,param_1);
  bStack_5f = false;
  AEFile::Read(&bStack_5f,param_1);
  local_60 = (Agent)0x0;
  AEFile::Read((bool *)&local_60,param_1);
  AStack_61 = (Agent)0x0;
  AEFile::Read((bool *)&AStack_61,param_1);
  local_68 = 0;
  AEFile::Read((int *)&local_68,param_1);
  if (0 < (int)local_68) {
    uVar1 = (uint)((ulonglong)local_68 * 4);
    if ((int)((ulonglong)local_68 * 4 >> 0x20) != 0) {
      uVar1 = 0xffffffff;
    }
    piVar7 = operator_new__(uVar1);
    iVar6 = 0;
    piVar5 = piVar7;
    do {
      AEFile::Read(piVar5,param_1);
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)local_68);
  }
  local_6c = -1;
  if (0x12 < local_3c) {
    AEFile::Read(&local_6c,param_1);
  }
  AbyssEngine::String::String(aSStack_74);
  AbyssEngine::String::String(aSStack_7c);
  AbyssEngine::String::String(aSStack_84);
  AbyssEngine::String::String(aSStack_8c);
  AbyssEngine::String::String(aSStack_94);
  AbyssEngine::String::String(aSStack_9c);
  AEFile::Read(aSStack_74,param_1,true);
  AEFile::Read(aSStack_7c,param_1,true);
  AEFile::Read(aSStack_84,param_1,true);
  AEFile::Read(aSStack_8c,param_1,true);
  AEFile::Read(aSStack_94,param_1,true);
  AEFile::Read(aSStack_9c,param_1,true);
  local_a0 = 0;
  AEFile::Read(&local_a0,param_1);
  if (local_a0 < 1) {
    local_c4 = (Mission *)0x0;
  }
  else {
    local_c4 = (Mission *)readMission(this,param_1);
  }
  this_00 = operator_new(0x88);
  iVar6 = local_3c;
  AbyssEngine::String::String(aSStack_a8,aSStack_7c,false);
  Agent::Agent(this_00,iVar6,aSStack_a8,local_54,local_58,local_44,bStack_5d,local_30,local_34,
               local_6c,local_4c);
  AbyssEngine::String::~String(aSStack_a8);
  Agent::setCosts(this_00,local_2c);
  Agent::setEvent(this_00,local_38);
  Agent::setOffer(this_00,local_40);
  Agent::setSellItemData(this_00,local_48,local_50,local_4c);
  if (local_90 != 0) {
    pSVar2 = operator_new(8);
    AbyssEngine::String::String(pSVar2,aSStack_94,false);
    *(String **)(this_00 + 8) = pSVar2;
  }
  if (local_98 != 0) {
    pSVar2 = operator_new(8);
    AbyssEngine::String::String(pSVar2,aSStack_9c,false);
    *(String **)(this_00 + 0xc) = pSVar2;
  }
  uVar1 = local_5c;
  *(uint *)(this_00 + 0x10) = local_5c;
  pAVar3 = operator_new(0xc);
  puVar4 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar4;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar4 = 0;
  *(undefined4 *)pAVar3 = 0;
  ArraySetLength<AbyssEngine::String*>(uVar1,pAVar3);
  if (0 < (int)local_5c) {
    iVar6 = 0;
    do {
      this_01 = operator_new(8);
      pSVar2 = aSStack_9c;
      if (iVar6 == 0) {
        pSVar2 = aSStack_94;
      }
      AbyssEngine::String::String(this_01,pSVar2,false);
      *(String **)(*(int *)(pAVar3 + 4) + iVar6 * 4) = this_01;
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)local_5c);
  }
  Agent::setWingmanFriendNames(this_00,pAVar3);
  Agent::giveRewardAtNextChat(this_00,bStack_5e);
  Agent::setOfferAccepted(this_00,bStack_5f);
  Agent::setImageParts(this_00,piVar7);
  AbyssEngine::String::String(aSStack_b0,aSStack_74,false);
  Agent::setMissionString(this_00,aSStack_b0);
  AbyssEngine::String::~String(aSStack_b0);
  AbyssEngine::String::String(aSStack_b8,aSStack_84,false);
  Agent::setStationName(this_00,aSStack_b8);
  AbyssEngine::String::~String(aSStack_b8);
  AbyssEngine::String::String(aSStack_c0,aSStack_8c,false);
  Agent::setSystemName(this_00,aSStack_c0);
  AbyssEngine::String::~String(aSStack_c0);
  Agent::setMission(this_00,local_c4);
  this_00[0x1c] = local_60;
  this_00[0x1d] = AStack_61;
  AbyssEngine::String::~String(aSStack_9c);
  AbyssEngine::String::~String(aSStack_94);
  AbyssEngine::String::~String(aSStack_8c);
  AbyssEngine::String::~String(aSStack_84);
  AbyssEngine::String::~String(aSStack_7c);
  AbyssEngine::String::~String(aSStack_74);
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== RecordHandler::readWanted  @0x000df578  (438 bytes)
/* RecordHandler::readWanted(unsigned int) */

void __thiscall RecordHandler::readWanted(RecordHandler *this,uint param_1)

{
  String *pSVar1;
  Wanted *this_00;
  int *piVar2;
  int *piVar3;
  int iVar4;
  String aSStack_7c [8];
  int local_74;
  int iStack_70;
  int local_6c;
  int iStack_68;
  int local_64;
  int iStack_60;
  int local_5c;
  int iStack_58;
  int local_54;
  bool bStack_4d;
  int local_4c;
  int iStack_48;
  int local_44;
  String aSStack_40 [8];
  int local_38;
  int local_34;
  int local_30;
  bool bStack_2a;
  bool bStack_29;
  int local_28;
  
  local_28 = __stack_chk_guard;
  bStack_29 = false;
  bStack_2a = false;
  local_30 = -1;
  local_38 = -1;
  local_34 = -1;
  AEFile::Read(&bStack_29,param_1);
  AEFile::Read(&bStack_2a,param_1);
  AEFile::Read(&local_30,param_1);
  AEFile::Read(&local_34,param_1);
  AEFile::Read(&local_38,param_1);
  pSVar1 = (String *)AbyssEngine::String::String(aSStack_40);
  local_44 = 0;
  local_4c = 0;
  iStack_48 = 0;
  bStack_4d = true;
  local_54 = 0;
  local_5c = 0;
  iStack_58 = 0;
  local_64 = 0;
  iStack_60 = 0;
  local_6c = 0;
  iStack_68 = 0;
  local_74 = 0;
  iStack_70 = 0;
  AEFile::Read(pSVar1,param_1,true);
  AEFile::Read(&local_44,param_1);
  AEFile::Read(&iStack_48,param_1);
  AEFile::Read(&local_4c,param_1);
  AEFile::Read(&bStack_4d,param_1);
  AEFile::Read(&local_54,param_1);
  AEFile::Read(&iStack_58,param_1);
  AEFile::Read(&local_5c,param_1);
  AEFile::Read(&iStack_60,param_1);
  AEFile::Read(&local_64,param_1);
  AEFile::Read(&iStack_68,param_1);
  AEFile::Read(&local_6c,param_1);
  AEFile::Read(&iStack_70,param_1);
  AEFile::Read(&local_74,param_1);
  this_00 = operator_new(0x50);
  iVar4 = local_44;
  AbyssEngine::String::String(aSStack_7c,aSStack_40,false);
  Wanted::Wanted(this_00,iVar4,aSStack_7c,iStack_48,local_4c,bStack_4d,local_54,iStack_58,local_5c,
                 iStack_60,local_64,iStack_68,local_6c,iStack_70,local_74);
  AbyssEngine::String::~String(aSStack_7c);
  piVar2 = operator_new__(0x14);
  iVar4 = 0;
  piVar3 = piVar2;
  do {
    AEFile::Read(piVar3,param_1);
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 5);
  Wanted::setImageParts(this_00,piVar2);
  Wanted::setActive(this_00,bStack_29);
  Wanted::setTerminated(this_00,bStack_2a);
  Wanted::setCurrentLocation(this_00,local_30);
  Wanted::setTravelsTo(this_00,local_34);
  Wanted::setLastSeen(this_00,local_38);
  AbyssEngine::String::~String(aSStack_40);
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== RecordHandler::recordStoreWrite  @0x000df760  (5118 bytes)
/* RecordHandler::recordStoreWrite(int) */

void __thiscall RecordHandler::recordStoreWrite(RecordHandler *this,int param_1)

{
  bool bVar1;
  int iVar2;
  AEFile *this_00;
  Mission *pMVar3;
  uint *puVar4;
  Ship *pSVar5;
  Item *pIVar6;
  Station *pSVar7;
  uint *puVar8;
  Standing *this_01;
  uint *puVar9;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  float fVar15;
  uint in_stack_ffffffc0;
  uint local_38 [2];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_38[0] = 0;
  AbyssEngine::String::Set(CONCAT44(param_1,local_38));
  AbyssEngine::operator+(aAStack_30,this + 0x10,(String *)local_38);
  AbyssEngine::String::~String((String *)local_38);
  iVar2 = AEFile::FileExist(aAStack_30);
  if (iVar2 == 1) {
    AEFile::FileDelete(aAStack_30);
  }
  AEFile::OpenWrite(aAStack_30,local_38);
  iVar2 = Galaxy::getVisited(Globals::galaxy);
  AEFile::Write(0x87,local_38[0]);
  uVar10 = 0;
  do {
    AEFile::Write(*(bool *)(iVar2 + uVar10),local_38[0]);
    uVar10 = uVar10 + 1;
  } while (uVar10 < 0x87);
  iVar2 = Status::getCredits(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getRating(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  this_00 = (AEFile *)Status::getPlayingTime(Globals::status);
  AEFile::Write(this_00,CONCAT44(extraout_r3,local_38[0]),in_stack_ffffffc0);
  iVar2 = Status::getKills(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getMissionCount(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getLevel(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getLastXP(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getGoodsProduced(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getStationsVisited(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getCurrentCampaignMission(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  pMVar3 = (Mission *)Status::getFreelanceMission(Globals::status);
  writeMission(this,pMVar3,local_38[0]);
  pMVar3 = (Mission *)Status::getCampaignMission(Globals::status);
  writeMission(this,pMVar3,local_38[0]);
  iVar2 = Status::getJumpgateUsed(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getCapturedCrates(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getBoughtEquipment(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  iVar2 = Status::getPirateKills(Globals::status);
  AEFile::Write(iVar2,local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0x80),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0x7c),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0x84),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0x88),local_38[0]);
  AEFile::Write(**(int **)(Globals::status + 0x94),local_38[0]);
  puVar4 = *(uint **)(Globals::status + 0x94);
  if (*puVar4 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar4[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar4 = *(uint **)(Globals::status + 0x94);
    } while (uVar10 < *puVar4);
  }
  AEFile::Write(**(int **)(Globals::status + 0x98),local_38[0]);
  puVar4 = *(uint **)(Globals::status + 0x98);
  if (*puVar4 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar4[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar4 = *(uint **)(Globals::status + 0x98);
    } while (uVar10 < *puVar4);
  }
  AEFile::Write(*(int *)(Globals::status + 0x9c),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xa0),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xa4),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xa8),local_38[0]);
  AEFile::Write(**(int **)(Globals::status + 0xac),local_38[0]);
  puVar4 = *(uint **)(Globals::status + 0xac);
  if (*puVar4 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar4[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar4 = *(uint **)(Globals::status + 0xac);
    } while (uVar10 < *puVar4);
  }
  AEFile::Write(*(int *)(Globals::status + 0xb0),local_38[0]);
  AEFile::Write(**(int **)(Globals::status + 0xb4),local_38[0]);
  puVar4 = *(uint **)(Globals::status + 0xb4);
  if (*puVar4 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar4[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar4 = *(uint **)(Globals::status + 0xb4);
    } while (uVar10 < *puVar4);
  }
  AEFile::Write(*(int *)(Globals::status + 0xb8),local_38[0]);
  AEFile::Write(*(AEFile **)(Globals::status + 0xc0),CONCAT44(extraout_r3_00,local_38[0]),
                in_stack_ffffffc0);
  AEFile::Write(*(int *)(Globals::status + 200),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xcc),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xd0),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xd4),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xd8),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xdc),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xe0),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xe4),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xe8),local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0xec),local_38[0]);
  iVar2 = Achievements::getMedals(Globals::achievements);
  AEFile::Write(0x2d,local_38[0]);
  iVar11 = 0;
  do {
    AEFile::Write(*(int *)(iVar2 + iVar11 * 4),local_38[0]);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 0x2d);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  iVar2 = Ship::getIndex(pSVar5);
  AEFile::Write(iVar2,local_38[0]);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  iVar2 = Ship::getRace(pSVar5);
  AEFile::Write(iVar2,local_38[0]);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  puVar4 = (uint *)Ship::getEquipment(pSVar5);
  if (puVar4 == (uint *)0x0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    AEFile::Write(*puVar4,local_38[0]);
    if (*puVar4 != 0) {
      uVar10 = 0;
      do {
        pIVar6 = *(Item **)(puVar4[1] + uVar10 * 4);
        if (pIVar6 == (Item *)0x0) {
          AEFile::Write(-1,local_38[0]);
        }
        else {
          iVar2 = Item::getIndex(pIVar6);
          AEFile::Write(iVar2,local_38[0]);
          iVar2 = Item::getAmount(*(Item **)(puVar4[1] + uVar10 * 4));
          AEFile::Write(iVar2,local_38[0]);
          bVar1 = (bool)Item::isUnsaleable(*(Item **)(puVar4[1] + uVar10 * 4));
          AEFile::Write(bVar1,local_38[0]);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar4);
    }
  }
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  puVar4 = (uint *)Ship::getCargo(pSVar5);
  if (puVar4 == (uint *)0x0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    AEFile::Write(*puVar4,local_38[0]);
    if (*puVar4 != 0) {
      uVar10 = 0;
      do {
        iVar2 = Item::getIndex(*(Item **)(puVar4[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        iVar2 = Item::getAmount(*(Item **)(puVar4[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        iVar2 = Item::getSinglePrice(*(Item **)(puVar4[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        bVar1 = (bool)Item::isUnsaleable(*(Item **)(puVar4[1] + uVar10 * 4));
        AEFile::Write(bVar1,local_38[0]);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar4);
    }
  }
  puVar4 = (uint *)Status::getStationStack(Globals::status);
  AEFile::Write(3,local_38[0]);
  uVar10 = *puVar4;
  if (uVar10 != 0xffffffff) {
    uVar12 = 0;
    do {
      if (uVar12 == uVar10) {
        pSVar7 = (Station *)Status::getStation(Globals::status);
      }
      else {
        pSVar7 = *(Station **)(puVar4[1] + uVar12 * 4);
      }
      if (pSVar7 == (Station *)0x0) {
        AEFile::Write(-1,local_38[0]);
      }
      else {
        iVar2 = Station::getIndex(pSVar7);
        AEFile::Write(iVar2,local_38[0]);
        puVar8 = (uint *)Station::getItems(pSVar7);
        if (puVar8 == (uint *)0x0) {
          AEFile::Write(0,local_38[0]);
        }
        else {
          AEFile::Write(*puVar8,local_38[0]);
          if (*puVar8 != 0) {
            uVar10 = 0;
            do {
              iVar2 = Item::getIndex(*(Item **)(puVar8[1] + uVar10 * 4));
              AEFile::Write(iVar2,local_38[0]);
              iVar2 = Item::getAmount(*(Item **)(puVar8[1] + uVar10 * 4));
              AEFile::Write(iVar2,local_38[0]);
              iVar2 = Item::getSinglePrice(*(Item **)(puVar8[1] + uVar10 * 4));
              AEFile::Write(iVar2,local_38[0]);
              bVar1 = (bool)Item::isUnsaleable(*(Item **)(puVar8[1] + uVar10 * 4));
              AEFile::Write(bVar1,local_38[0]);
              uVar10 = uVar10 + 1;
            } while (uVar10 < *puVar8);
          }
        }
        puVar8 = (uint *)Station::getShips(pSVar7);
        if (puVar8 == (uint *)0x0) {
          AEFile::Write(0,local_38[0]);
        }
        else {
          AEFile::Write(*puVar8,local_38[0]);
          if (*puVar8 != 0) {
            uVar10 = 0;
            do {
              iVar2 = Ship::getIndex(*(Ship **)(puVar8[1] + uVar10 * 4));
              AEFile::Write(iVar2,local_38[0]);
              iVar2 = Ship::getRace(*(Ship **)(puVar8[1] + uVar10 * 4));
              AEFile::Write(iVar2,local_38[0]);
              uVar10 = uVar10 + 1;
            } while (uVar10 < *puVar8);
          }
        }
        puVar8 = (uint *)Station::getAgents(pSVar7);
        if (puVar8 == (uint *)0x0) {
          AEFile::Write(0,local_38[0]);
        }
        else {
          AEFile::Write(*puVar8,local_38[0]);
          if (*puVar8 != 0) {
            uVar10 = 0;
            do {
              writeAgent(this,*(Agent **)(puVar8[1] + uVar10 * 4),local_38[0]);
              uVar10 = uVar10 + 1;
            } while (uVar10 < *puVar8);
          }
        }
        bVar1 = (bool)Station::hasAttackedFriends(pSVar7);
        AEFile::Write(bVar1,local_38[0]);
      }
      uVar10 = *puVar4;
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar10 + 1);
  }
  this_01 = (Standing *)Status::getStanding(Globals::status);
  iVar2 = Standing::getStandings(this_01);
  AEFile::Write(2,local_38[0]);
  iVar11 = 0;
  do {
    AEFile::Write(*(int *)(iVar2 + iVar11 * 4),local_38[0]);
    iVar11 = iVar11 + 1;
  } while (iVar11 < 2);
  puVar8 = (uint *)Status::getBluePrints(Globals::status);
  AEFile::Write(*puVar8,local_38[0]);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      piVar13 = *(int **)(puVar8[1] + uVar10 * 4);
      puVar9 = (uint *)*piVar13;
      if (*puVar9 != 0) {
        uVar12 = 0;
        do {
          AEFile::Write(*(int *)(puVar9[1] + uVar12 * 4),local_38[0]);
          puVar9 = (uint *)*piVar13;
          uVar12 = uVar12 + 1;
        } while (uVar12 < *puVar9);
      }
      AEFile::Write(piVar13[1],local_38[0]);
      AEFile::Write(SUB41(piVar13[2],0),local_38[0]);
      AEFile::Write(piVar13[3],local_38[0]);
      AEFile::Write(piVar13[4],local_38[0]);
      AEFile::Write((String *)(piVar13 + 5),local_38[0],true);
      uVar10 = uVar10 + 1;
    } while (uVar10 < *puVar8);
  }
  puVar8 = (uint *)Status::getPendingProducts(Globals::status);
  if (puVar8 == (uint *)0x0) {
    AEFile::Write(-1,local_38[0]);
  }
  else {
    if (*puVar8 != 0) {
      uVar10 = 0;
      iVar2 = 0;
      do {
        iVar11 = uVar10 * 4;
        uVar10 = uVar10 + 1;
        if (*(int *)(puVar8[1] + iVar11) != 0) {
          iVar2 = iVar2 + 1;
        }
      } while (uVar10 < *puVar8);
      if (iVar2 != 0) {
        AEFile::Write(iVar2,local_38[0]);
        uVar10 = *puVar8;
        if (uVar10 != 0) {
          uVar12 = 0;
          do {
            iVar2 = *(int *)(puVar8[1] + uVar12 * 4);
            if (iVar2 != 0) {
              AEFile::Write(*(int *)(iVar2 + 0x10),local_38[0]);
              AEFile::Write(*(int *)(*(int *)(puVar8[1] + uVar12 * 4) + 0xc),local_38[0]);
              AEFile::Write(*(int *)(*(int *)(puVar8[1] + uVar12 * 4) + 8),local_38[0]);
              AEFile::Write(*(String **)(puVar8[1] + uVar12 * 4),local_38[0],true);
              uVar10 = *puVar8;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar10);
        }
        goto LAB_000dffb4;
      }
    }
    AEFile::Write(-1,local_38[0]);
  }
LAB_000dffb4:
  if (*(int **)(Globals::status + 0x24) == (int *)0x0) {
    AEFile::Write(-1,local_38[0]);
  }
  else {
    AEFile::Write(**(int **)(Globals::status + 0x24),local_38[0]);
    puVar8 = *(uint **)(Globals::status + 0x24);
    if (*puVar8 != 0) {
      uVar10 = 0;
      do {
        AEFile::Write(*(String **)(puVar8[1] + uVar10 * 4),local_38[0],true);
        uVar10 = uVar10 + 1;
        puVar8 = *(uint **)(Globals::status + 0x24);
      } while (uVar10 < *puVar8);
    }
    AEFile::Write(*(int *)(Globals::status + 0x2c),local_38[0]);
    AEFile::Write(*(int *)(Globals::status + 0x30),local_38[0]);
    AEFile::Write(5,local_38[0]);
    iVar2 = 0;
    do {
      AEFile::Write(*(int *)(*(int *)(Globals::status + 0x28) + iVar2 * 4),local_38[0]);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
  }
  AEFile::Write(*(int *)(Globals::status + 0x34),local_38[0]);
  AEFile::Write(**(int **)(Globals::status + 0x38),local_38[0]);
  puVar8 = *(uint **)(Globals::status + 0x38);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar8[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar8 = *(uint **)(Globals::status + 0x38);
    } while (uVar10 < *puVar8);
  }
  AEFile::Write(**(int **)(Globals::status + 0x40),local_38[0]);
  puVar8 = *(uint **)(Globals::status + 0x40);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(int *)(puVar8[1] + uVar10 * 4),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar8 = *(uint **)(Globals::status + 0x40);
    } while (uVar10 < *puVar8);
  }
  AEFile::Write(**(int **)(Globals::status + 0x3c),local_38[0]);
  puVar8 = *(uint **)(Globals::status + 0x3c);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(int *)(puVar8[1] + uVar10 * 4),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar8 = *(uint **)(Globals::status + 0x3c);
    } while (uVar10 < *puVar8);
  }
  AEFile::Write(**(int **)(Globals::status + 0x48),local_38[0]);
  puVar8 = *(uint **)(Globals::status + 0x48);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(int *)(puVar8[1] + uVar10 * 4),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar8 = *(uint **)(Globals::status + 0x48);
    } while (uVar10 < *puVar8);
  }
  AEFile::Write(**(int **)(Globals::status + 0x44),local_38[0]);
  puVar8 = *(uint **)(Globals::status + 0x44);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(int *)(puVar8[1] + uVar10 * 4),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar8 = *(uint **)(Globals::status + 0x44);
    } while (uVar10 < *puVar8);
  }
  AEFile::Write(**(int **)(Globals::status + 0x4c),local_38[0]);
  puVar8 = *(uint **)(Globals::status + 0x4c);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar8[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar8 = *(uint **)(Globals::status + 0x4c);
    } while (uVar10 < *puVar8);
  }
  puVar8 = (uint *)Status::getAgents(Globals::status);
  AEFile::Write(*puVar8,local_38[0]);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      writeAgent(this,*(Agent **)(puVar8[1] + uVar10 * 4),local_38[0]);
      uVar10 = uVar10 + 1;
    } while (uVar10 < *puVar8);
  }
  AEFile::Write((bool)Globals::hints[8],local_38[0]);
  AEFile::Write((bool)Globals::hints[9],local_38[0]);
  AEFile::Write((bool)Globals::hints[10],local_38[0]);
  AEFile::Write((bool)Globals::hints[0xb],local_38[0]);
  AEFile::Write((bool)Globals::hints[0xc],local_38[0]);
  AEFile::Write((bool)Globals::hints[0xd],local_38[0]);
  AEFile::Write((bool)Globals::hints[0xe],local_38[0]);
  AEFile::Write((bool)Globals::hints[0xf],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x10],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x11],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x12],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x13],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x14],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x15],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x16],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x17],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x18],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x19],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x1a],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x1b],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x1c],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x1d],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x1e],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x1f],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x20],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x22],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x21],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x23],local_38[0]);
  fVar15 = (float)AEFile::Write((bool)Globals::hints[0x24],local_38[0]);
  AEFile::Write(fVar15,Globals::options._44_4_);
  AEFile::Write(*(AEFile **)(Globals::status + 0x100),CONCAT44(extraout_r3_01,local_38[0]),
                in_stack_ffffffc0);
  AEFile::Write((bool)Globals::hints[0x25],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x26],local_38[0]);
  if (*(int *)(Globals::status + 0x8c) == 0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    AEFile::Write(1,local_38[0]);
    iVar2 = Ship::getIndex(*(Ship **)(Globals::status + 0x8c));
    AEFile::Write(iVar2,local_38[0]);
    iVar2 = Ship::getRace(*(Ship **)(Globals::status + 0x8c));
    AEFile::Write(iVar2,local_38[0]);
    puVar8 = (uint *)Ship::getEquipment(*(Ship **)(Globals::status + 0x8c));
    if (puVar8 == (uint *)0x0) {
      AEFile::Write(0,local_38[0]);
    }
    else {
      AEFile::Write(*puVar8,local_38[0]);
      if (*puVar8 != 0) {
        uVar10 = 0;
        do {
          pIVar6 = *(Item **)(puVar8[1] + uVar10 * 4);
          if (pIVar6 == (Item *)0x0) {
            AEFile::Write(-1,local_38[0]);
          }
          else {
            iVar2 = Item::getIndex(pIVar6);
            AEFile::Write(iVar2,local_38[0]);
            iVar2 = Item::getAmount(*(Item **)(puVar8[1] + uVar10 * 4));
            AEFile::Write(iVar2,local_38[0]);
            bVar1 = (bool)Item::isUnsaleable(*(Item **)(puVar8[1] + uVar10 * 4));
            AEFile::Write(bVar1,local_38[0]);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar8);
      }
    }
    puVar8 = (uint *)Ship::getCargo(*(Ship **)(Globals::status + 0x8c));
    if (puVar8 == (uint *)0x0) {
      AEFile::Write(0,local_38[0]);
    }
    else {
      AEFile::Write(*puVar8,local_38[0]);
      if (*puVar8 != 0) {
        uVar10 = 0;
        do {
          iVar2 = Item::getIndex(*(Item **)(puVar8[1] + uVar10 * 4));
          AEFile::Write(iVar2,local_38[0]);
          iVar2 = Item::getAmount(*(Item **)(puVar8[1] + uVar10 * 4));
          AEFile::Write(iVar2,local_38[0]);
          iVar2 = Item::getSinglePrice(*(Item **)(puVar8[1] + uVar10 * 4));
          AEFile::Write(iVar2,local_38[0]);
          bVar1 = (bool)Item::isUnsaleable(*(Item **)(puVar8[1] + uVar10 * 4));
          AEFile::Write(bVar1,local_38[0]);
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar8);
      }
    }
  }
  AEFile::Write(**(int **)(Globals::status + 0x90),local_38[0]);
  puVar8 = *(uint **)(Globals::status + 0x90);
  if (*puVar8 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(int *)(puVar8[1] + uVar10 * 4),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar8 = *(uint **)(Globals::status + 0x90);
    } while (uVar10 < *puVar8);
  }
  AEFile::Write(*(int *)(Globals::status + 0x10c),local_38[0]);
  AEFile::Write((bool)Globals::status[0x110],local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0x114),local_38[0]);
  AEFile::Write((bool)Globals::status[0x111],local_38[0]);
  puVar8 = (uint *)Station::getItems(*(Station **)(Globals::status + 0x14c));
  if (puVar8 == (uint *)0x0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    AEFile::Write(*puVar8,local_38[0]);
    if (*puVar8 != 0) {
      uVar10 = 0;
      do {
        iVar2 = Item::getIndex(*(Item **)(puVar8[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        iVar2 = Item::getAmount(*(Item **)(puVar8[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        iVar2 = Item::getSinglePrice(*(Item **)(puVar8[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        bVar1 = (bool)Item::isUnsaleable(*(Item **)(puVar8[1] + uVar10 * 4));
        AEFile::Write(bVar1,local_38[0]);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar8);
    }
  }
  puVar8 = (uint *)Station::getShips(*(Station **)(Globals::status + 0x14c));
  if (puVar8 == (uint *)0x0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    AEFile::Write(*puVar8,local_38[0]);
    if (*puVar8 != 0) {
      uVar10 = 0;
      do {
        iVar2 = Ship::getIndex(*(Ship **)(puVar8[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        iVar2 = Ship::getRace(*(Ship **)(puVar8[1] + uVar10 * 4));
        AEFile::Write(iVar2,local_38[0]);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar8);
    }
  }
  AEFile::Write((bool)Globals::hints[0x27],local_38[0]);
  AEFile::Write((bool)Globals::options[0x35],local_38[0]);
  AEFile::Write((bool)Globals::options[0x36],local_38[0]);
  AEFile::Write(**(int **)(Globals::status + 0x54),local_38[0]);
  puVar9 = *(uint **)(Globals::status + 0x54);
  if (*puVar9 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar9[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar9 = *(uint **)(Globals::status + 0x54);
    } while (uVar10 < *puVar9);
  }
  AEFile::Write(0x6e6a78,local_38[0]);
  pSVar5 = (Ship *)Status::getShip(Globals::status);
  puVar9 = (uint *)Ship::getMods(pSVar5);
  if (puVar9 == (uint *)0x0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    AEFile::Write(*puVar9,local_38[0]);
    if (*puVar9 != 0) {
      uVar10 = 0;
      do {
        AEFile::Write(*(int *)(puVar9[1] + uVar10 * 4),local_38[0]);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar9);
    }
  }
  if (*(Ship **)(Globals::status + 0x8c) == (Ship *)0x0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    puVar9 = (uint *)Ship::getMods(*(Ship **)(Globals::status + 0x8c));
    if (puVar9 == (uint *)0x0) {
      AEFile::Write(0,local_38[0]);
    }
    else {
      AEFile::Write(*puVar9,local_38[0]);
      if (*puVar9 != 0) {
        uVar10 = 0;
        do {
          AEFile::Write(*(int *)(puVar9[1] + uVar10 * 4),local_38[0]);
          uVar10 = uVar10 + 1;
        } while (uVar10 < *puVar9);
      }
    }
  }
  if (puVar8 == (uint *)0x0) {
    AEFile::Write(0,local_38[0]);
  }
  else {
    AEFile::Write(*puVar8,local_38[0]);
    if (*puVar8 != 0) {
      uVar10 = 0;
      do {
        puVar9 = (uint *)Ship::getMods(*(Ship **)(puVar8[1] + uVar10 * 4));
        if (puVar9 == (uint *)0x0) {
          AEFile::Write(0,local_38[0]);
        }
        else {
          AEFile::Write(*puVar9,local_38[0]);
          if (*puVar9 != 0) {
            uVar12 = 0;
            do {
              AEFile::Write(*(int *)(puVar9[1] + uVar12 * 4),local_38[0]);
              uVar12 = uVar12 + 1;
            } while (uVar12 < *puVar9);
          }
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < *puVar8);
    }
  }
  uVar10 = *puVar4;
  if (uVar10 != 0xffffffff) {
    uVar12 = 0;
    do {
      if (uVar12 == uVar10) {
        pSVar7 = (Station *)Status::getStation(Globals::status);
      }
      else {
        pSVar7 = *(Station **)(puVar4[1] + uVar12 * 4);
      }
      if (pSVar7 != (Station *)0x0) {
        puVar8 = (uint *)Station::getShips(pSVar7);
        if (puVar8 == (uint *)0x0) {
          AEFile::Write(0,local_38[0]);
        }
        else {
          AEFile::Write(*puVar8,local_38[0]);
          if (*puVar8 != 0) {
            uVar10 = 0;
            do {
              iVar2 = Ship::getMods(*(Ship **)(puVar8[1] + uVar10 * 4));
              if (iVar2 == 0) {
                AEFile::Write(0,local_38[0]);
              }
              else {
                puVar9 = (uint *)Ship::getMods(*(Ship **)(puVar8[1] + uVar10 * 4));
                AEFile::Write(*puVar9,local_38[0]);
                puVar9 = (uint *)Ship::getMods(*(Ship **)(puVar8[1] + uVar10 * 4));
                if (*puVar9 != 0) {
                  uVar14 = 0;
                  do {
                    AEFile::Write(*(int *)(puVar9[1] + uVar14 * 4),local_38[0]);
                    uVar14 = uVar14 + 1;
                  } while (uVar14 < *puVar9);
                }
              }
              uVar10 = uVar10 + 1;
            } while (uVar10 < *puVar8);
          }
        }
      }
      uVar12 = uVar12 + 1;
      uVar10 = *puVar4;
    } while (uVar12 < uVar10 + 1);
  }
  AEFile::Write(**(int **)Globals::status,local_38[0]);
  puVar4 = *(uint **)Globals::status;
  if (*puVar4 != 0) {
    uVar10 = 0;
    do {
      writeWanted((RecordHandler *)puVar4[1],*(Wanted **)((RecordHandler *)puVar4[1] + uVar10 * 4),
                  local_38[0]);
      uVar10 = uVar10 + 1;
      puVar4 = *(uint **)Globals::status;
    } while (uVar10 < *puVar4);
  }
  iVar2 = 0;
  do {
    iVar11 = Status::getCollectedBounties(Globals::status,iVar2);
    AEFile::Write(iVar11,local_38[0]);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  AEFile::Write((bool)Globals::options[0x37],local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0x174),local_38[0]);
  AEFile::Write((bool)Globals::hints[0x28],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x29],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x2c],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x2a],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x2b],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x2e],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x2f],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x30],local_38[0]);
  AEFile::Write(**(int **)(Globals::status + 0x58),local_38[0]);
  puVar4 = *(uint **)(Globals::status + 0x58);
  if (*puVar4 != 0) {
    uVar10 = 0;
    do {
      AEFile::Write(*(bool *)(puVar4[1] + uVar10),local_38[0]);
      uVar10 = uVar10 + 1;
      puVar4 = *(uint **)(Globals::status + 0x58);
    } while (uVar10 < *puVar4);
  }
  AEFile::Write((bool)Globals::hints[0x31],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x2d],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x32],local_38[0]);
  AEFile::Write(*(int *)(Globals::status + 0x118),local_38[0]);
  AEFile::Write((bool)Globals::hints[0x33],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x34],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x35],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x36],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x37],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x38],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x39],local_38[0]);
  AEFile::Write((bool)Globals::hints[0x3a],local_38[0]);
  AEFile::Close(local_38[0]);
  addHash(this,param_1);
  Globals::lastRecordWritten = param_1;
  saveOptions(this);
  AbyssEngine::String::~String((String *)aAStack_30);
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== RecordHandler::writeMission  @0x000e0e7c  (412 bytes)
/* RecordHandler::writeMission(Mission*, unsigned int) */

void __thiscall RecordHandler::writeMission(RecordHandler *this,Mission *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  Agent *pAVar4;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = Mission::getType(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Mission::isEmpty(param_1);
  if (iVar2 == 0) {
    Mission::getClientName();
    AEFile::Write(aSStack_24,param_2,true);
    AbyssEngine::String::~String(aSStack_24);
    Mission::getTargetName();
    AEFile::Write(aSStack_24,param_2,true);
    AbyssEngine::String::~String(aSStack_24);
    Mission::getTargetStationName();
    AEFile::Write(aSStack_24,param_2,true);
    AbyssEngine::String::~String(aSStack_24);
    Mission::getTargetSystemName();
    AEFile::Write(aSStack_24,param_2,true);
    AbyssEngine::String::~String(aSStack_24);
    bVar1 = (bool)Mission::isCampaignMission(param_1);
    AEFile::Write(bVar1,param_2);
    iVar2 = Mission::getClientImage(param_1);
    if (iVar2 == 0) {
      AEFile::Write(-1,param_2);
    }
    else {
      AEFile::Write(5,param_2);
      iVar2 = 0;
      do {
        iVar3 = Mission::getClientImage(param_1);
        AEFile::Write(*(int *)(iVar3 + iVar2 * 4),param_2);
        iVar2 = iVar2 + 1;
      } while (iVar2 != 5);
    }
    iVar2 = Mission::getClientRace(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getCosts(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getBonus(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getReward(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getTargetStation(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getDifficulty(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getProductionGoodIndex(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getProductionGoodAmount(param_1);
    AEFile::Write(iVar2,param_2);
    iVar2 = Mission::getStatusValue(param_1);
    AEFile::Write(iVar2,param_2);
    bVar1 = (bool)Mission::isVisible(param_1);
    AEFile::Write(bVar1,param_2);
    *(Mission **)this = param_1;
    pAVar4 = (Agent *)Mission::getAgent(param_1);
    if ((pAVar4 == (Agent *)0x0) || (*(Agent **)(this + 4) == pAVar4)) {
      AEFile::Write(-1,param_2);
    }
    else {
      AEFile::Write(1,param_2);
      writeAgent(this,pAVar4,param_2);
    }
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== RecordHandler::writeAgent  @0x000e1034  (566 bytes)
/* RecordHandler::writeAgent(Agent*, unsigned int) */

void __thiscall RecordHandler::writeAgent(RecordHandler *this,Agent *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  String *pSVar4;
  Mission *pMVar5;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = Agent::getCosts(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getSellSystemIndex(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getSellBlueprintIndex(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getEvent(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getIndex(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getOffer(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getRace(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getSellItemIndex(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getSellItemPrice(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getSellItemQuantity(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getStation(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getSystem(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Agent::getWingmanFriendsCount(param_1);
  AEFile::Write(iVar2,param_2);
  bVar1 = (bool)Agent::isMale(param_1);
  AEFile::Write(bVar1,param_2);
  bVar1 = (bool)Agent::hasReward(param_1);
  AEFile::Write(bVar1,param_2);
  bVar1 = (bool)Agent::hasAcceptedOffer(param_1);
  AEFile::Write(bVar1,param_2);
  AEFile::Write((bool)param_1[0x1c],param_2);
  AEFile::Write((bool)param_1[0x1d],param_2);
  iVar2 = Agent::getImageParts(param_1);
  if (iVar2 == 0) {
    AEFile::Write(-1,param_2);
  }
  else {
    AEFile::Write(5,param_2);
    iVar2 = 0;
    do {
      iVar3 = Agent::getImageParts(param_1);
      AEFile::Write(*(int *)(iVar3 + iVar2 * 4),param_2);
      iVar2 = iVar2 + 1;
    } while (iVar2 != 5);
  }
  iVar2 = Agent::getIndex(param_1);
  if (0x12 < iVar2) {
    iVar2 = Agent::getSellModIndex(param_1);
    AEFile::Write(iVar2,param_2);
  }
  Agent::getMissionString();
  AEFile::Write(aSStack_24,param_2,true);
  AbyssEngine::String::~String(aSStack_24);
  Agent::getName();
  AEFile::Write(aSStack_24,param_2,true);
  AbyssEngine::String::~String(aSStack_24);
  Agent::getStationName();
  AEFile::Write(aSStack_24,param_2,true);
  AbyssEngine::String::~String(aSStack_24);
  Agent::getSystemName();
  AEFile::Write(aSStack_24,param_2,true);
  AbyssEngine::String::~String(aSStack_24);
  if (*(String **)(param_1 + 8) == (String *)0x0) {
    pSVar4 = (String *)AbyssEngine::String::String(aSStack_24,"",false);
    AEFile::Write(pSVar4,param_2,true);
    AbyssEngine::String::~String(aSStack_24);
  }
  else {
    AEFile::Write(*(String **)(param_1 + 8),param_2,true);
  }
  if (*(String **)(param_1 + 0xc) == (String *)0x0) {
    pSVar4 = (String *)AbyssEngine::String::String(aSStack_24,"",false);
    AEFile::Write(pSVar4,param_2,true);
    AbyssEngine::String::~String(aSStack_24);
  }
  else {
    AEFile::Write(*(String **)(param_1 + 0xc),param_2,true);
  }
  *(Agent **)(this + 4) = param_1;
  pMVar5 = (Mission *)Agent::getMission(param_1);
  if ((pMVar5 == (Mission *)0x0) || (*(Mission **)this == pMVar5)) {
    AEFile::Write(-1,param_2);
  }
  else {
    AEFile::Write(1,param_2);
    writeMission(this,pMVar5,param_2);
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== RecordHandler::writeWanted  @0x000e1294  (308 bytes)
/* RecordHandler::writeWanted(Wanted*, unsigned int) */

void __thiscall RecordHandler::writeWanted(RecordHandler *this,Wanted *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  bVar1 = (bool)Wanted::isActive(param_1);
  AEFile::Write(bVar1,param_2);
  bVar1 = (bool)Wanted::isTerminated(param_1);
  AEFile::Write(bVar1,param_2);
  iVar2 = Wanted::getCurrentLocation(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getTravelsTo(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getLastSeen(param_1);
  AEFile::Write(iVar2,param_2);
  Wanted::getName();
  AEFile::Write(aSStack_20,param_2,true);
  AbyssEngine::String::~String(aSStack_20);
  iVar2 = Wanted::getIndex(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getBoard(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getRace(param_1);
  AEFile::Write(iVar2,param_2);
  bVar1 = (bool)Wanted::isMale(param_1);
  AEFile::Write(bVar1,param_2);
  iVar2 = Wanted::getShip(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getWeapon(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getHitpoints(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getLoot(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getLootAmount(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getReward(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getRequiredBounties(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getRequiredMission(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = Wanted::getNumWingmen(param_1);
  AEFile::Write(iVar2,param_2);
  iVar2 = 0;
  do {
    iVar3 = Wanted::getImageParts(param_1);
    AEFile::Write(*(int *)(iVar3 + iVar2 * 4),param_2);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RecordHandler::recordStoreWritePreview  @0x000e13e0  (292 bytes)
/* RecordHandler::recordStoreWritePreview(int) */

void __thiscall RecordHandler::recordStoreWritePreview(RecordHandler *this,int param_1)

{
  int iVar1;
  AEFile *this_00;
  Ship *this_01;
  undefined4 extraout_r3;
  float fVar2;
  uint in_stack_ffffffd8;
  undefined4 local_24 [2];
  AbyssEngine aAStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_24[0] = 0;
  AbyssEngine::String::Set(CONCAT44(param_1,local_24));
  AbyssEngine::operator+(aAStack_1c,this + 0x18,(String *)local_24);
  AbyssEngine::String::~String((String *)local_24);
  iVar1 = AEFile::FileExist(aAStack_1c);
  if (iVar1 == 1) {
    AEFile::FileDelete(aAStack_1c);
  }
  AEFile::OpenWrite(aAStack_1c,(uint *)&stack0xffffffd8);
  this_00 = (AEFile *)Status::getPlayingTime(Globals::status);
  AEFile::Write(this_00,CONCAT44(extraout_r3,in_stack_ffffffd8),in_stack_ffffffd8);
  iVar1 = Status::getCredits(Globals::status);
  AEFile::Write(iVar1,in_stack_ffffffd8);
  Status::getStation(Globals::status);
  Station::getName();
  AEFile::Write((String *)local_24,in_stack_ffffffd8,true);
  AbyssEngine::String::~String((String *)local_24);
  Status::getSystem(Globals::status);
  SolarSystem::getName();
  AEFile::Write((String *)local_24,in_stack_ffffffd8,true);
  AbyssEngine::String::~String((String *)local_24);
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  AEFile::Write(iVar1,in_stack_ffffffd8);
  iVar1 = Status::getLevel(Globals::status);
  fVar2 = (float)AEFile::Write(iVar1,in_stack_ffffffd8);
  AEFile::Write(fVar2,Globals::options._44_4_);
  this_01 = (Ship *)Status::getShip(Globals::status);
  iVar1 = Ship::getIndex(this_01);
  AEFile::Write(iVar1,in_stack_ffffffd8);
  AEFile::Close(in_stack_ffffffd8);
  AbyssEngine::String::~String((String *)aAStack_1c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== RecordHandler::recordStoreWritePreview  @0x000e1554  (214 bytes)
/* RecordHandler::recordStoreWritePreview(GameRecord*, int) */

void RecordHandler::recordStoreWritePreview(GameRecord *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r3;
  float fVar3;
  uint in_stack_ffffffd0;
  uint local_2c;
  undefined4 local_28 [2];
  AbyssEngine aAStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  uVar1 = 0;
  if (param_2 != 0) {
    local_28[0] = 0;
    AbyssEngine::String::Set(CONCAT44(param_2,local_28));
    AbyssEngine::operator+(aAStack_20,param_1 + 0x18,(String *)local_28);
    AbyssEngine::String::~String((String *)local_28);
    iVar2 = AEFile::FileExist(aAStack_20);
    if (iVar2 == 1) {
      AEFile::FileDelete(aAStack_20);
    }
    AEFile::OpenWrite(aAStack_20,&local_2c);
    AEFile::Write(*(AEFile **)(param_2 + 0x10),CONCAT44(extraout_r3,local_2c),in_stack_ffffffd0);
    AEFile::Write(*(int *)(param_2 + 8),local_2c);
    Station::getName();
    AEFile::Write((String *)local_28,local_2c,true);
    AbyssEngine::String::~String((String *)local_28);
    AEFile::Write((String *)(param_2 + 0x188),local_2c,true);
    AEFile::Write(*(int *)(param_2 + 0x40),local_2c);
    fVar3 = (float)AEFile::Write(*(int *)(param_2 + 0x20),local_2c);
    AEFile::Write(fVar3,*(uint *)(param_2 + 0x11c));
    iVar2 = Ship::getIndex(*(Ship **)(param_2 + 0x130));
    AEFile::Write(iVar2,local_2c);
    AEFile::Close(local_2c);
    AbyssEngine::String::~String((String *)aAStack_20);
    uVar1 = 1;
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}

// ===== RecordHandler::recoverSDVersionSaves  @0x000e1654  (2 bytes)
/* RecordHandler::recoverSDVersionSaves() */

void RecordHandler::recoverSDVersionSaves(void)

{
  return;
}

// ===== RecordHandler::convertSDVersionSaves  @0x000e1658  (578 bytes)
/* RecordHandler::convertSDVersionSaves() */

void __thiscall RecordHandler::convertSDVersionSaves(RecordHandler *this)

{
  Array *pAVar1;
  undefined4 *puVar2;
  Array *pAVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  signed *psVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  longlong lVar13;
  undefined4 local_38 [2];
  AbyssEngine aAStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *puVar2 = 0;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *(undefined4 *)pAVar1 = 0;
  ArraySetLength<signed_char*>(Globals::recordSlots,pAVar1);
  pAVar3 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar2;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar3 = 0;
  ArraySetLength<signed_char*>(Globals::recordSlots,pAVar3);
  uVar9 = Globals::recordSlots;
  uVar10 = (uint)((ulonglong)Globals::recordSlots * 4);
  if ((int)((ulonglong)Globals::recordSlots * 4 >> 0x20) != 0) {
    uVar10 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar10);
  pvVar5 = operator_new__(uVar10);
  if ((int)uVar9 < 1) {
    iVar11 = *(int *)(pAVar1 + 4);
  }
  else {
    iVar11 = 0;
    iVar12 = 0;
    do {
      uVar6 = readRecordAsByteArray(this,(signed **)(*(int *)(pAVar1 + 4) + iVar11),iVar12,false);
      *(undefined4 *)((int)pvVar4 + iVar12 * 4) = uVar6;
      uVar6 = readRecordAsByteArray(this,(signed **)(*(int *)(pAVar3 + 4) + iVar11),iVar12,true);
      local_38[0] = 0;
      *(undefined4 *)((int)pvVar5 + iVar12 * 4) = uVar6;
      AbyssEngine::String::Set(CONCAT44(pvVar5,(String *)local_38));
      AbyssEngine::operator+(aAStack_30,this + 0x10,(String *)local_38);
      AEFile::FileDelete(aAStack_30);
      AbyssEngine::String::~String((String *)aAStack_30);
      lVar13 = AbyssEngine::String::~String((String *)local_38);
      local_38[0] = 0;
      AbyssEngine::String::Set(lVar13);
      AbyssEngine::operator+(aAStack_30,this + 0x18,(String *)local_38);
      AEFile::FileDelete(aAStack_30);
      AbyssEngine::String::~String((String *)aAStack_30);
      AbyssEngine::String::~String((String *)local_38);
      iVar11 = iVar11 + 4;
      iVar12 = iVar12 + 1;
    } while (iVar12 < (int)Globals::recordSlots);
    iVar11 = *(int *)(pAVar1 + 4);
    uVar9 = Globals::recordSlots;
    if (1 < (int)Globals::recordSlots) {
      iVar12 = 0;
      do {
        psVar8 = *(signed **)(iVar11 + iVar12 * 4);
        if (psVar8 != (signed *)0x0) {
          iVar11 = iVar12 + 1;
          writeByteArrayAsRecord(this,psVar8,*(int *)((int)pvVar4 + iVar12 * 4),iVar11,false);
          addHash(this,iVar11);
          writeByteArrayAsRecord
                    (this,*(signed **)(*(int *)(pAVar3 + 4) + iVar12 * 4),
                     *(int *)((int)pvVar5 + iVar12 * 4),iVar11,true);
          iVar11 = *(int *)(pAVar1 + 4);
          uVar9 = Globals::recordSlots;
        }
        iVar12 = iVar12 + 1;
        iVar7 = uVar9 - 1;
      } while (iVar12 < iVar7);
      goto LAB_000e1820;
    }
  }
  iVar7 = uVar9 - 1;
LAB_000e1820:
  psVar8 = *(signed **)(iVar11 + iVar7 * 4);
  if (psVar8 != (signed *)0x0) {
    writeByteArrayAsRecord(this,psVar8,*(int *)((int)pvVar4 + iVar7 * 4),0,false);
    addHash(this,0);
    iVar11 = Globals::recordSlots * 4 + -4;
    writeByteArrayAsRecord
              (this,*(signed **)(*(int *)(pAVar3 + 4) + iVar11),*(int *)((int)pvVar5 + iVar11),0,
               true);
  }
  ArrayReleaseArrays<signed_char*>(pAVar1);
  ArrayReleaseArrays<signed_char*>(pAVar3);
  operator_delete__(pvVar4);
  operator_delete__(pvVar5);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== RecordHandler::changeSaveDirectoryToBackupDirectory  @0x000e1954  (376 bytes)
/* RecordHandler::changeSaveDirectoryToBackupDirectory() */

void __thiscall RecordHandler::changeSaveDirectoryToBackupDirectory(RecordHandler *this)

{
  Array *pAVar1;
  undefined4 *puVar2;
  Array *pAVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint uVar7;
  signed *psVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *puVar2 = 0;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *(undefined4 *)pAVar1 = 0;
  ArraySetLength<signed_char*>(Globals::recordSlots,pAVar1);
  pAVar3 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar2;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar3 = 0;
  ArraySetLength<signed_char*>(Globals::recordSlots,pAVar3);
  uVar7 = Globals::recordSlots;
  uVar9 = (uint)((ulonglong)Globals::recordSlots * 4);
  if ((int)((ulonglong)Globals::recordSlots * 4 >> 0x20) != 0) {
    uVar9 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar9);
  pvVar5 = operator_new__(uVar9);
  if ((int)uVar7 < 1) {
    AbyssEngine::Engine::backupSaveGames = 1;
  }
  else {
    iVar10 = 0;
    iVar11 = 0;
    do {
      uVar6 = readRecordAsByteArray(this,(signed **)(*(int *)(pAVar1 + 4) + iVar10),iVar11,false);
      *(undefined4 *)((int)pvVar4 + iVar11 * 4) = uVar6;
      uVar6 = readRecordAsByteArray(this,(signed **)(*(int *)(pAVar3 + 4) + iVar10),iVar11,true);
      iVar10 = iVar10 + 4;
      *(undefined4 *)((int)pvVar5 + iVar11 * 4) = uVar6;
      iVar11 = iVar11 + 1;
    } while (iVar11 < (int)Globals::recordSlots);
    AbyssEngine::Engine::backupSaveGames = 1;
    if (0 < (int)Globals::recordSlots) {
      iVar10 = 0;
      uVar7 = Globals::recordSlots;
      do {
        psVar8 = *(signed **)(*(int *)(pAVar1 + 4) + iVar10 * 4);
        if (psVar8 != (signed *)0x0) {
          writeByteArrayAsRecord(this,psVar8,*(int *)((int)pvVar4 + iVar10 * 4),iVar10,false);
          addHash(this,iVar10 + 1);
          writeByteArrayAsRecord
                    (this,*(signed **)(*(int *)(pAVar3 + 4) + iVar10 * 4),
                     *(int *)((int)pvVar5 + iVar10 * 4),iVar10,true);
          uVar7 = Globals::recordSlots;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)uVar7);
    }
  }
  ArrayReleaseArrays<signed_char*>(pAVar1);
  ArrayReleaseArrays<signed_char*>(pAVar3);
  operator_delete__(pvVar4);
  operator_delete__(pvVar5);
  return;
}

