// Class: FileRead
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== FileRead::FileRead  @0x00144cdc  (2 bytes)
/* FileRead::FileRead() */

FileRead * __thiscall FileRead::FileRead(FileRead *this)

{
  return this;
}

// ===== FileRead::~FileRead  @0x00144cde  (2 bytes)
/* FileRead::~FileRead() */

FileRead * __thiscall FileRead::~FileRead(FileRead *this)

{
  return this;
}

// ===== FileRead::loadStation  @0x00144ce0  (38 bytes)
/* FileRead::loadStation(int) */

undefined4 __thiscall FileRead::loadStation(FileRead *this,int param_1)

{
  FileRead *this_00;
  int iVar1;
  undefined4 uVar2;
  
  this_00 = operator_new__(2);
  *(short *)this_00 = (short)param_1;
  iVar1 = loadStationsBinary(this_00,(short *)this_00,1);
  uVar2 = **(undefined4 **)(iVar1 + 4);
  operator_delete__(this_00);
  return uVar2;
}

// ===== FileRead::loadStationsBinary  @0x00144d08  (294 bytes)
/* FileRead::loadStationsBinary(short*, int) */

void __thiscall FileRead::loadStationsBinary(FileRead *this,short *param_1,int param_2)

{
  Array *pAVar1;
  undefined4 *puVar2;
  String *pSVar3;
  int iVar4;
  Station *pSVar5;
  int iVar6;
  int iVar7;
  String aSStack_4c [8];
  int local_44;
  int iStack_40;
  int local_3c;
  int iStack_38;
  uint local_34;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  ArraySetLength<Station*>(param_2,pAVar1);
  pSVar3 = (String *)AbyssEngine::String::String(aSStack_30,"data/bin/stations.bin",false);
  iVar4 = AEFile::FileExist(pSVar3);
  AbyssEngine::String::~String(aSStack_30);
  if (iVar4 == 1) {
    AEFile::OpenRead("data/bin/stations.bin",&local_34);
    AbyssEngine::String::String(aSStack_30);
    iVar7 = 0;
    iVar4 = 0;
    do {
      AEFile::ReadSwitched(aSStack_30,local_34);
      AbyssEngine::String::ConvertFromUTF8(aSStack_30);
      AEFile::ReadSwitched(&iStack_38,local_34);
      AEFile::ReadSwitched(&local_3c,local_34);
      AEFile::ReadSwitched(&iStack_40,local_34);
      AEFile::ReadSwitched(&local_44,local_34);
      if (0 < param_2) {
        iVar6 = 0;
        do {
          if (param_1[iVar6] == iVar7) {
            pSVar5 = operator_new(0x30);
            AbyssEngine::String::String(aSStack_4c,aSStack_30,false);
            Station::Station(pSVar5,aSStack_4c,iStack_38,local_3c,iStack_40,local_44);
            *(Station **)(*(int *)(pAVar1 + 4) + iVar4 * 4) = pSVar5;
            AbyssEngine::String::~String(aSStack_4c);
            iVar4 = iVar4 + 1;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_2);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x87);
    AEFile::Close(local_34);
    AbyssEngine::String::~String(aSStack_30);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileRead::loadShipParts  @0x00144e70  (376 bytes)
/* FileRead::loadShipParts(int) */

void __thiscall FileRead::loadShipParts(FileRead *this,int param_1)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  short local_34;
  char cStack_32;
  char cStack_31;
  uint local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String((String *)local_30,"data/bin/shipparts.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String((String *)local_30);
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/shipparts.bin",local_30);
    iVar2 = 0;
    do {
      AEFile::Read(&cStack_31,local_30[0]);
      AEFile::Read(&cStack_32,local_30[0]);
      pAVar3 = operator_new(0xc);
      puVar4 = operator_new__(4);
      *(undefined4 **)(pAVar3 + 4) = puVar4;
      *puVar4 = 0;
      *(undefined4 *)(pAVar3 + 8) = 1;
      *(undefined4 *)pAVar3 = 0;
      ArraySetLength<int>(cStack_32 * 10,pAVar3);
      if (*(int *)pAVar3 != 0) {
        uVar6 = 0;
        iVar7 = 0x14;
        do {
          AEFile::ReadSwitched(&local_34,local_30[0]);
          iVar5 = *(int *)(pAVar3 + 4);
          *(int *)(iVar5 + iVar7 + -0x14) = (int)local_34;
          AEFile::ReadSwitched((int *)(iVar5 + iVar7 + -0x10),local_30[0]);
          AEFile::ReadSwitched((int *)(*(int *)(pAVar3 + 4) + iVar7 + -0xc),local_30[0]);
          AEFile::ReadSwitched((int *)(*(int *)(pAVar3 + 4) + iVar7 + -8),local_30[0]);
          AEFile::ReadSwitched(&local_34,local_30[0]);
          *(int *)(*(int *)(pAVar3 + 4) + iVar7 + -4) = (int)local_34;
          AEFile::ReadSwitched(&local_34,local_30[0]);
          *(int *)(*(int *)(pAVar3 + 4) + iVar7) = (int)local_34;
          AEFile::ReadSwitched(&local_34,local_30[0]);
          *(int *)(*(int *)(pAVar3 + 4) + iVar7 + 4) = (int)local_34;
          AEFile::ReadSwitched(&local_34,local_30[0]);
          *(int *)(*(int *)(pAVar3 + 4) + iVar7 + 8) = (int)local_34;
          AEFile::ReadSwitched(&local_34,local_30[0]);
          *(int *)(*(int *)(pAVar3 + 4) + iVar7 + 0xc) = (int)local_34;
          AEFile::ReadSwitched(&local_34,local_30[0]);
          uVar6 = uVar6 + 10;
          iVar5 = *(int *)(pAVar3 + 4) + iVar7;
          iVar7 = iVar7 + 0x28;
          *(int *)(iVar5 + 0x10) = (int)local_34;
        } while (uVar6 < *(uint *)pAVar3);
      }
      if ((int)cStack_31 == param_1 + 1) goto LAB_00144fce;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x40);
    AEFile::Close(local_30[0]);
  }
LAB_00144fce:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileRead::loadStationCollision  @0x00145010  (260 bytes)
/* FileRead::loadStationCollision(int) */

void __thiscall FileRead::loadStationCollision(FileRead *this,int param_1)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_30;
  int local_2c;
  uint local_28 [2];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String((String *)local_28,"data/bin/collision.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String((String *)local_28);
  iVar7 = 0;
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/collision.bin",local_28);
    local_30 = 0;
    local_2c = 0;
    do {
      AEFile::Read(&local_2c,local_28[0]);
      AEFile::Read((int *)&local_30,local_28[0]);
      uVar8 = local_30 + 1;
      local_30 = uVar8;
      if (local_2c == param_1) {
        pAVar3 = operator_new(0xc);
        puVar4 = operator_new__(4);
        uVar6 = (uint)((ulonglong)uVar8 * 4);
        *(undefined4 **)(pAVar3 + 4) = puVar4;
        *(undefined4 *)(pAVar3 + 8) = 1;
        *puVar4 = 0;
        *(undefined4 *)pAVar3 = 0;
        if ((int)((ulonglong)uVar8 * 4 >> 0x20) != 0) {
          uVar6 = 0xffffffff;
        }
        pvVar5 = operator_new__(uVar6);
        AEFile::Read(uVar8 * 4,pvVar5,local_28[0]);
        ArraySetLength<int>(local_30,pAVar3);
        if (0 < (int)local_30) {
          iVar2 = *(int *)(pAVar3 + 4);
          iVar7 = 0;
          do {
            *(undefined4 *)(iVar2 + iVar7 * 4) = *(undefined4 *)((int)pvVar5 + iVar7 * 4);
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)local_30);
        }
        operator_delete__(pvVar5);
        AEFile::Close(local_28[0]);
        goto LAB_001450fa;
      }
      AEFile::Skip(uVar8 * 4,local_28[0]);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x88);
    AEFile::Close(local_28[0]);
  }
LAB_001450fa:
  if (__stack_chk_guard - local_20 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_20);
}

// ===== FileRead::loadWreckCollision  @0x0014513c  (260 bytes)
/* FileRead::loadWreckCollision(int) */

void __thiscall FileRead::loadWreckCollision(FileRead *this,int param_1)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_30;
  int local_2c;
  uint local_28 [2];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pSVar1 = (String *)
           AbyssEngine::String::String((String *)local_28,"data/bin/wreck_collisions.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String((String *)local_28);
  iVar7 = 0;
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/wreck_collisions.bin",local_28);
    local_30 = 0;
    local_2c = 0;
    do {
      AEFile::Read(&local_2c,local_28[0]);
      AEFile::Read((int *)&local_30,local_28[0]);
      uVar8 = local_30 + 1;
      local_30 = uVar8;
      if (local_2c == param_1) {
        pAVar3 = operator_new(0xc);
        puVar4 = operator_new__(4);
        uVar6 = (uint)((ulonglong)uVar8 * 4);
        *(undefined4 **)(pAVar3 + 4) = puVar4;
        *(undefined4 *)(pAVar3 + 8) = 1;
        *puVar4 = 0;
        *(undefined4 *)pAVar3 = 0;
        if ((int)((ulonglong)uVar8 * 4 >> 0x20) != 0) {
          uVar6 = 0xffffffff;
        }
        pvVar5 = operator_new__(uVar6);
        AEFile::Read(uVar8 * 4,pvVar5,local_28[0]);
        ArraySetLength<int>(local_30,pAVar3);
        if (0 < (int)local_30) {
          iVar2 = *(int *)(pAVar3 + 4);
          iVar7 = 0;
          do {
            *(undefined4 *)(iVar2 + iVar7 * 4) = *(undefined4 *)((int)pvVar5 + iVar7 * 4);
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)local_30);
        }
        operator_delete__(pvVar5);
        AEFile::Close(local_28[0]);
        goto LAB_00145226;
      }
      AEFile::Skip(uVar8 * 4,local_28[0]);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 6);
    AEFile::Close(local_28[0]);
  }
LAB_00145226:
  if (__stack_chk_guard - local_20 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_20);
}

// ===== FileRead::loadStaticCollision  @0x00145268  (260 bytes)
/* FileRead::loadStaticCollision(int) */

void __thiscall FileRead::loadStaticCollision(FileRead *this,int param_1)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_30;
  int local_2c;
  uint local_28 [2];
  int local_20;
  
  local_20 = __stack_chk_guard;
  pSVar1 = (String *)
           AbyssEngine::String::String((String *)local_28,"data/bin/static_collisions.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String((String *)local_28);
  iVar7 = 0;
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/static_collisions.bin",local_28);
    local_30 = 0;
    local_2c = 0;
    do {
      AEFile::Read(&local_2c,local_28[0]);
      AEFile::Read((int *)&local_30,local_28[0]);
      uVar8 = local_30 + 1;
      local_30 = uVar8;
      if (local_2c == param_1) {
        pAVar3 = operator_new(0xc);
        puVar4 = operator_new__(4);
        uVar6 = (uint)((ulonglong)uVar8 * 4);
        *(undefined4 **)(pAVar3 + 4) = puVar4;
        *(undefined4 *)(pAVar3 + 8) = 1;
        *puVar4 = 0;
        *(undefined4 *)pAVar3 = 0;
        if ((int)((ulonglong)uVar8 * 4 >> 0x20) != 0) {
          uVar6 = 0xffffffff;
        }
        pvVar5 = operator_new__(uVar6);
        AEFile::Read(uVar8 * 4,pvVar5,local_28[0]);
        ArraySetLength<int>(local_30,pAVar3);
        if (0 < (int)local_30) {
          iVar2 = *(int *)(pAVar3 + 4);
          iVar7 = 0;
          do {
            *(undefined4 *)(iVar2 + iVar7 * 4) = *(undefined4 *)((int)pvVar5 + iVar7 * 4);
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)local_30);
        }
        operator_delete__(pvVar5);
        AEFile::Close(local_28[0]);
        goto LAB_00145352;
      }
      AEFile::Skip(uVar8 * 4,local_28[0]);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 7);
    AEFile::Close(local_28[0]);
  }
LAB_00145352:
  if (__stack_chk_guard - local_20 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_20);
}

// ===== FileRead::loadStationParts  @0x00145394  (396 bytes)
/* FileRead::loadStationParts(int, int) */

void __thiscall FileRead::loadStationParts(FileRead *this,int param_1,int param_2)

{
  short *psVar1;
  char cVar2;
  String *pSVar3;
  int iVar4;
  Array *pAVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  char in_ZR;
  undefined4 unaff_s16;
  int iVar12;
  undefined4 unaff_s17;
  int iVar13;
  undefined4 unaff_s18;
  int iVar14;
  undefined4 unaff_s19;
  int iVar15;
  char acStack_49 [37];
  
  if (in_ZR != '\0') {
    register0x00000054 = (BADSPACEBASE *)&stack0xffffffdc;
  }
  *(undefined4 *)((int)register0x00000054 + -0x14) = unaff_s16;
  *(undefined4 *)((int)register0x00000054 + -0x10) = unaff_s17;
  *(undefined4 *)((int)register0x00000054 + -0xc) = unaff_s18;
  *(undefined4 *)((int)register0x00000054 + -8) = unaff_s19;
  *(int *)((int)register0x00000054 + -0x18) = __stack_chk_guard;
  pSVar3 = (String *)
           AbyssEngine::String::String
                     ((String *)((int)register0x00000054 + -0x20),"data/bin/stationparts.bin",false)
  ;
  iVar4 = AEFile::FileExist(pSVar3);
  AbyssEngine::String::~String((String *)((int)register0x00000054 + -0x20));
  if (iVar4 == 1) {
    AEFile::OpenRead("data/bin/stationparts.bin",(uint *)((int)register0x00000054 + -0x20));
    iVar4 = param_1 + 1;
    if (param_2 == 1) {
      iVar4 = 0x65;
    }
    uVar8 = *(uint *)((int)register0x00000054 + -0x20);
    iVar12 = 0;
    iVar13 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    iVar14 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    iVar15 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    psVar1 = (short *)((int)register0x00000054 + -0x28);
    iVar11 = 0;
    do {
      AEFile::Read((signed *)((int)register0x00000054 + -0x21),uVar8);
      AEFile::ReadSwitched
                ((short *)((int)register0x00000054 + -0x24),
                 *(uint *)((int)register0x00000054 + -0x20));
      AEFile::Read((signed *)((int)register0x00000054 + -0x25),
                   *(uint *)((int)register0x00000054 + -0x20));
      pAVar5 = operator_new(0xc);
      puVar6 = operator_new__(4);
      *(undefined4 **)(pAVar5 + 4) = puVar6;
      *puVar6 = 0;
      cVar2 = *(char *)((int)register0x00000054 + -0x25);
      *(undefined4 *)(pAVar5 + 8) = 1;
      *(undefined4 *)pAVar5 = 0;
      ArraySetLength<int>(cVar2 * 7 + 7,pAVar5);
      piVar9 = *(int **)(pAVar5 + 4);
      *piVar9 = (int)*(short *)((int)register0x00000054 + -0x24);
      piVar9[1] = iVar12;
      piVar9[2] = iVar13;
      piVar9[3] = iVar14;
      piVar9[4] = iVar15;
      piVar9[5] = 0x800;
      piVar9[6] = 0;
      if (7 < *(uint *)pAVar5) {
        uVar8 = 7;
        iVar10 = 0x34;
        do {
          AEFile::ReadSwitched(psVar1,*(uint *)((int)register0x00000054 + -0x20));
          iVar7 = *(int *)(pAVar5 + 4);
          *(int *)(iVar7 + iVar10 + -0x18) = (int)*(short *)((int)register0x00000054 + -0x28);
          AEFile::ReadSwitched
                    ((int *)(iVar7 + iVar10 + -0x14),*(uint *)((int)register0x00000054 + -0x20));
          AEFile::ReadSwitched
                    ((int *)(*(int *)(pAVar5 + 4) + iVar10 + -0x10),
                     *(uint *)((int)register0x00000054 + -0x20));
          AEFile::ReadSwitched
                    ((int *)(*(int *)(pAVar5 + 4) + iVar10 + -0xc),
                     *(uint *)((int)register0x00000054 + -0x20));
          AEFile::ReadSwitched(psVar1,*(uint *)((int)register0x00000054 + -0x20));
          *(int *)(*(int *)(pAVar5 + 4) + iVar10 + -8) =
               (int)*(short *)((int)register0x00000054 + -0x28);
          AEFile::ReadSwitched(psVar1,*(uint *)((int)register0x00000054 + -0x20));
          *(int *)(*(int *)(pAVar5 + 4) + iVar10 + -4) =
               (int)*(short *)((int)register0x00000054 + -0x28);
          AEFile::ReadSwitched(psVar1,*(uint *)((int)register0x00000054 + -0x20));
          piVar9 = *(int **)(pAVar5 + 4);
          uVar8 = uVar8 + 7;
          *(int *)((int)piVar9 + iVar10) = (int)*(short *)((int)register0x00000054 + -0x28);
          iVar10 = iVar10 + 0x1c;
        } while (uVar8 < *(uint *)pAVar5);
      }
      if (*(char *)((int)register0x00000054 + -0x21) == iVar4) goto LAB_001454fe;
      if (piVar9 != (int *)0x0) {
        operator_delete__(piVar9);
      }
      uVar8 = *(uint *)((int)register0x00000054 + -0x20);
      iVar11 = iVar11 + 1;
      *(undefined4 *)(pAVar5 + 4) = 0;
    } while (iVar11 < 0x88);
    AEFile::Close(uVar8);
  }
LAB_001454fe:
  if (__stack_chk_guard - *(int *)((int)register0x00000054 + -0x18) == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - *(int *)((int)register0x00000054 + -0x18));
}

// ===== FileRead::loadStationsBinary  @0x00145548  (308 bytes)
/* FileRead::loadStationsBinary(SolarSystem*) */

void __thiscall FileRead::loadStationsBinary(FileRead *this,SolarSystem *param_1)

{
  Array *pAVar1;
  undefined4 *puVar2;
  String *pSVar3;
  int iVar4;
  uint *puVar5;
  Station *pSVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  String aSStack_4c [8];
  int local_44;
  int iStack_40;
  int local_3c;
  int iStack_38;
  uint local_34;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pAVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  *(undefined4 **)(pAVar1 + 4) = puVar2;
  *(undefined4 *)(pAVar1 + 8) = 1;
  *puVar2 = 0;
  *(undefined4 *)pAVar1 = 0;
  pSVar3 = (String *)AbyssEngine::String::String(aSStack_30,"data/bin/stations.bin",false);
  iVar4 = AEFile::FileExist(pSVar3);
  AbyssEngine::String::~String(aSStack_30);
  if (iVar4 == 1) {
    AEFile::OpenRead("data/bin/stations.bin",&local_34);
    puVar5 = (uint *)SolarSystem::getStations(param_1);
    ArraySetLength<Station*>(*puVar5,pAVar1);
    AbyssEngine::String::String(aSStack_30);
    iVar4 = 0;
    uVar9 = 0;
    do {
      AEFile::ReadSwitched(aSStack_30,local_34);
      AbyssEngine::String::ConvertFromUTF8(aSStack_30);
      AEFile::ReadSwitched(&iStack_38,local_34);
      AEFile::ReadSwitched(&local_3c,local_34);
      AEFile::ReadSwitched(&iStack_40,local_34);
      AEFile::ReadSwitched(&local_44,local_34);
      uVar7 = *puVar5;
      if (uVar7 != 0) {
        uVar8 = 0;
        do {
          if (*(int *)(puVar5[1] + uVar8 * 4) == iVar4) {
            pSVar6 = operator_new(0x30);
            AbyssEngine::String::String(aSStack_4c,aSStack_30,false);
            Station::Station(pSVar6,aSStack_4c,iStack_38,local_3c,iStack_40,local_44);
            *(Station **)(*(int *)(pAVar1 + 4) + uVar9 * 4) = pSVar6;
            AbyssEngine::String::~String(aSStack_4c);
            uVar7 = *puVar5;
            uVar9 = uVar9 + 1;
          }
          if (uVar9 == uVar7) {
            AEFile::Close(local_34);
            goto LAB_0014565c;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar7);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x87);
    AEFile::Close(local_34);
LAB_0014565c:
    AbyssEngine::String::~String(aSStack_30);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileRead::loadAgents  @0x001456c0  (420 bytes)
/* FileRead::loadAgents() */

void FileRead::loadAgents(void)

{
  int iVar1;
  String *pSVar2;
  int iVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  Agent *pAVar6;
  int *piVar7;
  uint local_6c;
  char cStack_65;
  String aSStack_64 [8];
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int iStack_4c;
  int local_48;
  int iStack_44;
  int local_40;
  int iStack_3c;
  int local_38;
  uint local_34;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar2 = (String *)AbyssEngine::String::String(aSStack_30,"data/bin/agents.bin",false);
  iVar3 = AEFile::FileExist(pSVar2);
  AbyssEngine::String::~String(aSStack_30);
  if (iVar3 == 1) {
    AEFile::OpenRead("data/bin/agents.bin",&local_34);
    pAVar4 = operator_new(0xc);
    puVar5 = operator_new__(4);
    *(undefined4 **)(pAVar4 + 4) = puVar5;
    *(undefined4 *)(pAVar4 + 8) = 1;
    *puVar5 = 0;
    *(undefined4 *)pAVar4 = 0;
    ArraySetLength<Agent*>(0x1b,pAVar4);
    AbyssEngine::String::String(aSStack_30);
    local_5c = -1;
    if (*(int *)pAVar4 != 0) {
      local_6c = 0;
      do {
        AEFile::ReadSwitched(aSStack_30,local_34);
        AbyssEngine::String::ConvertFromUTF8(aSStack_30);
        AEFile::ReadSwitched(&local_38,local_34);
        AEFile::ReadSwitched(&iStack_3c,local_34);
        AEFile::ReadSwitched(&local_40,local_34);
        AEFile::ReadSwitched(&iStack_44,local_34);
        AEFile::ReadSwitched(&local_54,local_34);
        iVar3 = local_54;
        AEFile::ReadSwitched(&local_48,local_34);
        AEFile::ReadSwitched(&iStack_4c,local_34);
        AEFile::ReadSwitched(&local_5c,local_34);
        AEFile::ReadSwitched(&local_50,local_34);
        pAVar6 = operator_new(0x88);
        iVar1 = local_38;
        AbyssEngine::String::String(aSStack_64,aSStack_30,false);
        Agent::Agent(pAVar6,iVar1,aSStack_64,iStack_3c,local_40,iStack_44,iVar3 == 1,local_48,
                     iStack_4c,local_5c,local_50);
        *(Agent **)(*(int *)(pAVar4 + 4) + local_6c * 4) = pAVar6;
        AbyssEngine::String::~String(aSStack_64);
        AEFile::ReadSwitched(&local_58,local_34);
        if (0 < local_58) {
          piVar7 = operator_new__(0x14);
          iVar3 = 0;
          do {
            AEFile::Read(&cStack_65,local_34);
            piVar7[iVar3] = (int)cStack_65;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 5);
          Agent::setImageParts(*(Agent **)(*(int *)(pAVar4 + 4) + local_6c * 4),piVar7);
        }
        local_6c = local_6c + 1;
      } while (local_6c < *(uint *)pAVar4);
    }
    AEFile::Close(local_34);
    AbyssEngine::String::~String(aSStack_30);
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FileRead::loadWanted  @0x001458a8  (494 bytes)
/* FileRead::loadWanted() */

void FileRead::loadWanted(void)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  Wanted *pWVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  char cStack_75;
  String aSStack_74 [8];
  int local_6c;
  int iStack_68;
  int local_64;
  int iStack_60;
  int local_5c;
  int iStack_58;
  int local_54;
  int local_50;
  int local_4c;
  int iStack_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String(aSStack_30,"data/bin/wanted.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String(aSStack_30);
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/wanted.bin",&local_34);
    pAVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    *(undefined4 **)(pAVar3 + 4) = puVar4;
    *(undefined4 *)(pAVar3 + 8) = 1;
    *puVar4 = 0;
    *(undefined4 *)pAVar3 = 0;
    ArraySetLength<Wanted*>(0x19,pAVar3);
    AbyssEngine::String::String(aSStack_30);
    if (*(int *)pAVar3 != 0) {
      uVar8 = 0;
      do {
        AEFile::ReadSwitched(aSStack_30,local_34);
        AbyssEngine::String::ConvertFromUTF8(aSStack_30);
        AEFile::ReadSwitched(&local_38,local_34);
        AEFile::ReadSwitched(&local_3c,local_34);
        AEFile::ReadSwitched(&local_40,local_34);
        AEFile::ReadSwitched(&local_50,local_34);
        AEFile::ReadSwitched(&local_44,local_34);
        AEFile::ReadSwitched(&iStack_48,local_34);
        AEFile::ReadSwitched(&local_4c,local_34);
        AEFile::ReadSwitched(&iStack_58,local_34);
        AEFile::ReadSwitched(&local_5c,local_34);
        AEFile::ReadSwitched(&iStack_60,local_34);
        AEFile::ReadSwitched(&local_64,local_34);
        AEFile::ReadSwitched(&iStack_68,local_34);
        AEFile::ReadSwitched(&local_6c,local_34);
        pWVar5 = operator_new(0x50);
        iVar2 = local_38;
        AbyssEngine::String::String(aSStack_74,aSStack_30,false);
        uVar6 = Wanted::Wanted(pWVar5,iVar2,aSStack_74,local_3c,local_40,local_50 == 1,local_44,
                               iStack_48,local_4c,iStack_58,local_5c,iStack_60,local_64,iStack_68,
                               local_6c);
        *(undefined4 *)(*(int *)(pAVar3 + 4) + uVar8 * 4) = uVar6;
        AbyssEngine::String::~String(aSStack_74);
        AEFile::ReadSwitched(&local_54,local_34);
        if (0 < local_54) {
          piVar7 = operator_new__(0x14);
          iVar2 = 0;
          do {
            AEFile::Read(&cStack_75,local_34);
            piVar7[iVar2] = (int)cStack_75;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 5);
          Wanted::setImageParts(*(Wanted **)(*(int *)(pAVar3 + 4) + uVar8 * 4),piVar7);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)pAVar3);
    }
    AEFile::Close(local_34);
    AbyssEngine::String::~String(aSStack_30);
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FileRead::loadStationsBinary  @0x00145adc  (224 bytes)
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* FileRead::loadStationsBinary() */

void FileRead::loadStationsBinary(void)

{
  String *pSVar1;
  int iVar2;
  int iVar3;
  int local_44;
  int iStack_40;
  int local_3c;
  int local_38;
  uint local_34;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String(aSStack_30,"data/bin/stations.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String(aSStack_30);
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/stations.bin",&local_34);
    iVar2 = 0;
    ArraySetLength<signed_char>(0x195,(Array *)0x0);
    AbyssEngine::String::String(aSStack_30);
    local_44 = 0;
    do {
      AEFile::ReadSwitched(aSStack_30,local_34);
      AEFile::ReadSwitched(&local_44,local_34);
      AEFile::ReadSwitched(&local_38,local_34);
      AEFile::ReadSwitched(&local_3c,local_34);
      AEFile::ReadSwitched(&iStack_40,local_34);
      iVar2 = iVar2 + 1;
      *(char *)(_DAT_00000004 + local_44) = (char)local_38;
      iVar3 = local_44 + 2;
      *(char *)(_DAT_00000004 + local_44 + 1) = (char)local_3c;
      local_44 = local_44 + 3;
      *(char *)(_DAT_00000004 + iVar3) = (char)iStack_40;
    } while (iVar2 < 0x87);
    AEFile::Close(local_34);
    AbyssEngine::String::~String(aSStack_30);
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FileRead::loadSystemsBinary  @0x00145c10  (674 bytes)
/* FileRead::loadSystemsBinary() */

void FileRead::loadSystemsBinary(void)

{
  int iVar1;
  String *pSVar2;
  int iVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  Array *pAVar8;
  Array *pAVar9;
  Array *pAVar10;
  SolarSystem *pSVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  String aSStack_60 [8];
  uint local_58;
  int local_54;
  int local_50;
  int iStack_4c;
  int local_48;
  int iStack_44;
  int iStack_40;
  int local_3c;
  int iStack_38;
  uint local_34;
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar2 = (String *)AbyssEngine::String::String(aSStack_30,"data/bin/systems.bin",false);
  iVar3 = AEFile::FileExist(pSVar2);
  AbyssEngine::String::~String(aSStack_30);
  if (iVar3 == 1) {
    AEFile::OpenRead("data/bin/systems.bin",&local_34);
    pAVar4 = operator_new(0xc);
    puVar5 = operator_new__(4);
    *(undefined4 **)(pAVar4 + 4) = puVar5;
    *(undefined4 *)(pAVar4 + 8) = 1;
    *puVar5 = 0;
    *(undefined4 *)pAVar4 = 0;
    ArraySetLength<SolarSystem*>(0x22,pAVar4);
    AbyssEngine::String::String(aSStack_30);
    iVar3 = 0;
    do {
      AEFile::ReadSwitched(aSStack_30,local_34);
      AbyssEngine::String::ConvertFromUTF8(aSStack_30);
      AEFile::ReadSwitched(&iStack_38,local_34);
      AEFile::ReadSwitched(&local_54,local_34);
      iVar1 = local_54;
      AEFile::ReadSwitched(&local_3c,local_34);
      AEFile::ReadSwitched(&iStack_40,local_34);
      AEFile::ReadSwitched(&iStack_44,local_34);
      AEFile::ReadSwitched(&local_48,local_34);
      AEFile::ReadSwitched(&iStack_4c,local_34);
      AEFile::ReadSwitched(&local_50,local_34);
      AEFile::ReadSwitched((int *)&local_58,local_34);
      uVar14 = local_58;
      uVar6 = (uint)((ulonglong)local_58 * 4);
      if ((int)((ulonglong)local_58 * 4 >> 0x20) != 0) {
        uVar6 = 0xffffffff;
      }
      piVar7 = operator_new__(uVar6);
      if (0 < (int)uVar14) {
        iVar13 = 0;
        piVar12 = piVar7;
        do {
          AEFile::ReadSwitched(piVar12,local_34);
          iVar13 = iVar13 + 1;
          piVar12 = piVar12 + 1;
        } while (iVar13 < (int)local_58);
      }
      AEFile::ReadSwitched((int *)&local_58,local_34);
      uVar14 = local_58;
      if ((int)local_58 < 1) {
        pAVar8 = (Array *)0x0;
      }
      else {
        pAVar8 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar5;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar8 = 0;
        ArraySetLength<int>(uVar14,pAVar8);
        if (*(int *)pAVar8 != 0) {
          iVar13 = 0;
          uVar14 = 0;
          do {
            AEFile::ReadSwitched((int *)(*(int *)(pAVar8 + 4) + iVar13),local_34);
            iVar13 = iVar13 + 4;
            uVar14 = uVar14 + 1;
          } while (uVar14 < *(uint *)pAVar8);
        }
      }
      AEFile::ReadSwitched((int *)&local_58,local_34);
      uVar14 = local_58;
      if ((int)local_58 < 1) {
        pAVar9 = (Array *)0x0;
      }
      else {
        pAVar9 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar9 + 4) = puVar5;
        *(undefined4 *)(pAVar9 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar9 = 0;
        ArraySetLength<int>(uVar14,pAVar9);
        if (*(int *)pAVar9 != 0) {
          iVar13 = 0;
          uVar14 = 0;
          do {
            AEFile::ReadSwitched((int *)(*(int *)(pAVar9 + 4) + iVar13),local_34);
            iVar13 = iVar13 + 4;
            uVar14 = uVar14 + 1;
          } while (uVar14 < *(uint *)pAVar9);
        }
      }
      AEFile::ReadSwitched((int *)&local_58,local_34);
      uVar14 = local_58;
      if ((int)local_58 < 1) {
        pAVar10 = (Array *)0x0;
      }
      else {
        pAVar10 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar10 + 4) = puVar5;
        *(undefined4 *)(pAVar10 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar10 = 0;
        ArraySetLength<int>(uVar14,pAVar10);
        if (*(int *)pAVar10 != 0) {
          iVar13 = 0;
          uVar14 = 0;
          do {
            AEFile::ReadSwitched((int *)(*(int *)(pAVar10 + 4) + iVar13),local_34);
            iVar13 = iVar13 + 4;
            uVar14 = uVar14 + 1;
          } while (uVar14 < *(uint *)pAVar10);
        }
      }
      pSVar11 = operator_new(0x44);
      AbyssEngine::String::String(aSStack_60,aSStack_30,false);
      SolarSystem::SolarSystem
                (pSVar11,iVar3,aSStack_60,iStack_38,iVar1 == 1,local_3c,iStack_40,iStack_44,local_48
                 ,iStack_4c,local_50,piVar7,pAVar8,pAVar9,pAVar10);
      *(SolarSystem **)(*(int *)(pAVar4 + 4) + iVar3 * 4) = pSVar11;
      AbyssEngine::String::~String(aSStack_60);
      operator_delete__(piVar7);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x22);
    AEFile::Close(local_34);
    AbyssEngine::String::~String(aSStack_30);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileRead::loadItemsBinary  @0x00145f48  (450 bytes)
/* FileRead::loadItemsBinary() */

void FileRead::loadItemsBinary(void)

{
  uint uVar1;
  String *pSVar2;
  int iVar3;
  Array *pAVar4;
  undefined4 *puVar5;
  Array *pAVar6;
  Array *pAVar7;
  Array *pAVar8;
  Item *this;
  int iVar9;
  int iVar10;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar2 = (String *)AbyssEngine::String::String((String *)local_30,"data/bin/items.bin",false);
  iVar3 = AEFile::FileExist(pSVar2);
  AbyssEngine::String::~String((String *)local_30);
  if (iVar3 == 1) {
    AEFile::OpenRead("data/bin/items.bin",local_30);
    pAVar4 = operator_new(0xc);
    puVar5 = operator_new__(4);
    *(undefined4 **)(pAVar4 + 4) = puVar5;
    *(undefined4 *)(pAVar4 + 8) = 1;
    *puVar5 = 0;
    *(undefined4 *)pAVar4 = 0;
    ArraySetLength<Item*>(0xe9,pAVar4);
    local_34 = 0;
    iVar3 = 0;
    local_3c = 0;
    local_38 = 0;
    do {
      AEFile::ReadSwitched((int *)&local_34,local_30[0]);
      uVar1 = local_34;
      if ((int)local_34 < 1) {
        pAVar6 = (Array *)0x0;
      }
      else {
        pAVar6 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar6 + 4) = puVar5;
        *(undefined4 *)(pAVar6 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar6 = 0;
        ArraySetLength<int>(uVar1,pAVar6);
        if (0 < (int)local_34) {
          iVar9 = 0;
          iVar10 = 0;
          do {
            AEFile::ReadSwitched((int *)(*(int *)(pAVar6 + 4) + iVar9),local_30[0]);
            iVar9 = iVar9 + 4;
            iVar10 = iVar10 + 1;
          } while (iVar10 < (int)local_34);
        }
      }
      AEFile::ReadSwitched((int *)&local_38,local_30[0]);
      uVar1 = local_38;
      if ((int)local_38 < 1) {
        pAVar7 = (Array *)0x0;
      }
      else {
        pAVar7 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar7 + 4) = puVar5;
        *(undefined4 *)(pAVar7 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar7 = 0;
        ArraySetLength<int>(uVar1,pAVar7);
        if (0 < (int)local_38) {
          iVar9 = 0;
          iVar10 = 0;
          do {
            AEFile::ReadSwitched((int *)(*(int *)(pAVar7 + 4) + iVar9),local_30[0]);
            iVar9 = iVar9 + 4;
            iVar10 = iVar10 + 1;
          } while (iVar10 < (int)local_38);
        }
      }
      AEFile::ReadSwitched((int *)&local_3c,local_30[0]);
      uVar1 = local_3c;
      if ((int)local_3c < 1) {
        pAVar8 = (Array *)0x0;
      }
      else {
        pAVar8 = operator_new(0xc);
        puVar5 = operator_new__(4);
        *(undefined4 **)(pAVar8 + 4) = puVar5;
        *(undefined4 *)(pAVar8 + 8) = 1;
        *puVar5 = 0;
        *(undefined4 *)pAVar8 = 0;
        ArraySetLength<int>(uVar1,pAVar8);
        if (0 < (int)local_3c) {
          iVar10 = 0;
          iVar9 = 0;
          do {
            AEFile::ReadSwitched((int *)(*(int *)(pAVar8 + 4) + iVar10),local_30[0]);
            iVar10 = iVar10 + 4;
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)local_3c);
        }
      }
      this = operator_new(0x48);
      Item::Item(this,pAVar6,pAVar7,pAVar8);
      *(Item **)(*(int *)(pAVar4 + 4) + iVar3 * 4) = this;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xe9);
    AEFile::Close(local_30[0]);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileRead::loadShipsBinary  @0x00146148  (282 bytes)
/* FileRead::loadShipsBinary() */

void FileRead::loadShipsBinary(void)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  Ship *this;
  uint in_fpscr;
  float fVar5;
  int local_54;
  int local_50;
  int iStack_4c;
  int local_48;
  int iStack_44;
  int local_40;
  int iStack_3c;
  int local_38;
  int iStack_34;
  uint local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String((String *)local_30,"data/bin/ships.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String((String *)local_30);
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/ships.bin",local_30);
    pAVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    iVar2 = 0;
    *(undefined4 **)(pAVar3 + 4) = puVar4;
    *(undefined4 *)(pAVar3 + 8) = 1;
    *puVar4 = 0;
    *(undefined4 *)pAVar3 = 0;
    ArraySetLength<Ship*>(0x40,pAVar3);
    do {
      AEFile::ReadSwitched(&iStack_34,local_30[0]);
      AEFile::ReadSwitched(&local_38,local_30[0]);
      AEFile::ReadSwitched(&iStack_3c,local_30[0]);
      AEFile::ReadSwitched(&local_40,local_30[0]);
      AEFile::ReadSwitched(&iStack_44,local_30[0]);
      AEFile::ReadSwitched(&local_48,local_30[0]);
      AEFile::ReadSwitched(&iStack_4c,local_30[0]);
      AEFile::ReadSwitched(&local_50,local_30[0]);
      AEFile::ReadSwitched(&local_54,local_30[0]);
      this = operator_new(0x80);
      fVar5 = (float)VectorSignedToFloat(local_54,(byte)(in_fpscr >> 0x16) & 3);
      Ship::Ship(this,iStack_34,local_38,iStack_3c,local_40,iStack_44,local_48,iStack_4c,local_50,
                 fVar5);
      *(Ship **)(*(int *)(pAVar3 + 4) + iVar2 * 4) = this;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x40);
    AEFile::Close(local_30[0]);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileRead::loadNamesBinary  @0x00146290  (692 bytes)
/* FileRead::loadNamesBinary(int, bool, bool) */

void __thiscall FileRead::loadNamesBinary(FileRead *this,int param_1,bool param_2,bool param_3)

{
  int iVar1;
  Array *pAVar2;
  undefined4 *puVar3;
  String *this_00;
  char *pcVar4;
  uint local_3c;
  uint local_38 [2];
  String aSStack_30 [8];
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_28,"",false);
  switch(param_1) {
  case 0:
    pcVar4 = "names_terran_0_m.bin";
    if (!param_2) {
      pcVar4 = "names_terran_0_w.bin";
    }
    if (!param_3) {
      pcVar4 = "names_terran_1.bin";
    }
    AbyssEngine::String::String(aSStack_30,pcVar4,false);
    AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    break;
  case 1:
    pcVar4 = "names_vossk_0.bin";
    if (!param_3) {
      pcVar4 = "names_vossk_1.bin";
    }
    AbyssEngine::String::String(aSStack_30,pcVar4,false);
    AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    break;
  case 2:
    pcVar4 = "names_nivelian_0.bin";
    if (!param_3) {
      pcVar4 = "names_nivelian_1.bin";
    }
    AbyssEngine::String::String(aSStack_30,pcVar4,false);
    AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    break;
  case 3:
    if (param_3) {
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      pcVar4 = "names_terran_0_m.bin";
      if (iVar1 != 0) {
        pcVar4 = "names_nivelian_0.bin";
      }
      AbyssEngine::String::String(aSStack_30,pcVar4,false);
      AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    }
    else {
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      pcVar4 = "names_terran_1.bin";
      if (iVar1 != 0) {
        pcVar4 = "names_nivelian_1.bin";
      }
      AbyssEngine::String::String(aSStack_30,pcVar4,false);
      AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    }
    break;
  case 4:
    pcVar4 = "names_multipod_0.bin";
    if (!param_3) {
      pcVar4 = "names_multipod_1.bin";
    }
    AbyssEngine::String::String(aSStack_30,pcVar4,false);
    AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    break;
  case 5:
    if (!param_3) goto switchD_001462be_default;
    AbyssEngine::String::String(aSStack_30,"names_cyborg_0.bin",false);
    AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    break;
  case 6:
    pcVar4 = "names_bobolan_0.bin";
    if (!param_3) {
      pcVar4 = "names_bobolan_1.bin";
    }
    AbyssEngine::String::String(aSStack_30,pcVar4,false);
    AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    break;
  case 7:
    if (!param_3) goto switchD_001462be_default;
    AbyssEngine::String::String(aSStack_30,"names_grey_0.bin",false);
    AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    break;
  case 8:
    if (param_3) {
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      pcVar4 = "names_terran_0_m.bin";
      if (iVar1 != 0) {
        pcVar4 = "names_nivelian_0.bin";
      }
      AbyssEngine::String::String(aSStack_30,pcVar4,false);
      AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    }
    else {
      iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
      pcVar4 = "names_terran_1.bin";
      if (iVar1 != 0) {
        pcVar4 = "names_nivelian_1.bin";
      }
      AbyssEngine::String::String(aSStack_30,pcVar4,false);
      AbyssEngine::String::operator=(aSStack_28,aSStack_30);
    }
    break;
  default:
    goto switchD_001462be_default;
  }
  AbyssEngine::String::~String(aSStack_30);
  AbyssEngine::String::String((String *)local_38,"data/bin/",false);
  AbyssEngine::operator+((AbyssEngine *)aSStack_30,(String *)local_38,aSStack_28);
  AbyssEngine::String::operator=(aSStack_28,aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  AbyssEngine::String::~String((String *)local_38);
  iVar1 = AEFile::FileExist(aSStack_28);
  if (iVar1 == 1) {
    AEFile::OpenRead(aSStack_28,local_38);
    AEFile::ReadSwitched((int *)&local_3c,local_38[0]);
    pAVar2 = operator_new(0xc);
    puVar3 = operator_new__(4);
    *(undefined4 **)(pAVar2 + 4) = puVar3;
    *(undefined4 *)(pAVar2 + 8) = 1;
    *puVar3 = 0;
    *(undefined4 *)pAVar2 = 0;
    ArraySetLength<AbyssEngine::String*>(local_3c,pAVar2);
    AbyssEngine::String::String(aSStack_30);
    if (0 < (int)local_3c) {
      iVar1 = 0;
      do {
        AEFile::ReadSwitched(aSStack_30,local_38[0]);
        this_00 = operator_new(8);
        AbyssEngine::String::String(this_00,aSStack_30,false);
        *(String **)(*(int *)(pAVar2 + 4) + iVar1 * 4) = this_00;
        iVar1 = iVar1 + 1;
      } while (iVar1 < (int)local_3c);
    }
    AEFile::Close(local_38[0]);
    AbyssEngine::String::~String(aSStack_30);
  }
switchD_001462be_default:
  AbyssEngine::String::~String(aSStack_28);
  if (__stack_chk_guard - local_20 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_20);
}

// ===== FileRead::loadTicker  @0x00146634  (280 bytes)
/* FileRead::loadTicker() */

void FileRead::loadTicker(void)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  bool *pbVar5;
  int iVar6;
  NewsItem *this;
  int local_48;
  int iStack_44;
  int local_40;
  uint local_3c;
  String local_38 [4];
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String(local_38,"data/bin/ticker.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String(local_38);
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/ticker.bin",&local_3c);
    pAVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    iVar2 = 0;
    *(undefined4 **)(pAVar3 + 4) = puVar4;
    *(undefined4 *)(pAVar3 + 8) = 1;
    *puVar4 = 0;
    *(undefined4 *)pAVar3 = 0;
    ArraySetLength<NewsItem*>(0x3b,pAVar3);
    do {
      AEFile::ReadSwitched(&local_40,local_3c);
      AEFile::Read((int *)local_38,local_3c);
      AEFile::Read(&iStack_34,local_3c);
      AEFile::Read(&iStack_30,local_3c);
      AEFile::Read(&iStack_2c,local_3c);
      AEFile::ReadSwitched(&iStack_44,local_3c);
      AEFile::ReadSwitched(&local_48,local_3c);
      pbVar5 = operator_new__(4);
      iVar6 = 0;
      do {
        pbVar5[iVar6] = *(int *)(local_38 + iVar6 * 4) != 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 4);
      this = operator_new(0x1c);
      NewsItem::NewsItem(this,iVar2,local_40 != 0,pbVar5,4,iStack_44,local_48);
      *(NewsItem **)(*(int *)(pAVar3 + 4) + iVar2 * 4) = this;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x3b);
    AEFile::Close(local_3c);
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FileRead::loadWeaponPositions  @0x001467b0  (528 bytes)
/* FileRead::loadWeaponPositions(int) */

void __thiscall FileRead::loadWeaponPositions(FileRead *this,int param_1)

{
  String *pSVar1;
  int iVar2;
  Array *pAVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  uint in_fpscr;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  float local_48;
  float fStack_44;
  float local_40;
  short local_3c;
  short sStack_3a;
  short local_38;
  short local_36;
  short local_34;
  short sStack_32;
  uint local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String((String *)local_30,"data/bin/weapons_hd.bin",false)
  ;
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String((String *)local_30);
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/weapons_hd.bin",local_30);
    pAVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    *puVar4 = 0;
    *(undefined4 **)(pAVar3 + 4) = puVar4;
    *(undefined4 *)(pAVar3 + 8) = 1;
    *(undefined4 *)pAVar3 = 0;
    ArraySetLength<Array<AbyssEngine::AEMath::Vector*>*>(4,pAVar3);
    uVar5 = *(uint *)pAVar3;
    if (uVar5 != 0) {
      uVar9 = 0;
      do {
        *(undefined4 *)(*(int *)(pAVar3 + 4) + uVar9 * 4) = 0;
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar5);
    }
    sStack_32 = 0;
    local_34 = 0;
    local_3c = 0;
    local_48 = 0.0;
    do {
      AEFile::Read(&sStack_32,local_30[0]);
      AEFile::Read(&local_34,local_30[0]);
      iVar2 = (int)sStack_32;
      if (0 < local_34) {
        iVar13 = 0;
        do {
          AEFile::Read(&local_36,local_30[0]);
          AEFile::Read(&local_38,local_30[0]);
          AEFile::Read(&sStack_3a,local_30[0]);
          AEFile::Read(&local_3c,local_30[0]);
          if (local_36 == 3) {
            AEFile::Read(&local_40,local_30[0]);
            AEFile::Read(&fStack_44,local_30[0]);
            AEFile::Read(&local_48,local_30[0]);
          }
          if (iVar2 == param_1) {
            iVar12 = (int)local_36;
            iVar10 = *(int *)(pAVar3 + 4);
            if (*(int *)(iVar10 + iVar12 * 4) == 0) {
              puVar4 = operator_new(0xc);
              puVar6 = operator_new__(4);
              puVar4[1] = puVar6;
              puVar4[2] = 1;
              *puVar6 = 0;
              *puVar4 = 0;
              *(undefined4 **)(iVar10 + iVar12 * 4) = puVar4;
              iVar10 = *(int *)(pAVar3 + 4);
            }
            puVar4 = operator_new(0xc);
            uVar14 = VectorSignedToFloat((int)local_38,(byte)(in_fpscr >> 0x16) & 3);
            uVar15 = VectorSignedToFloat((int)local_3c,(byte)(in_fpscr >> 0x16) & 3);
            uVar16 = VectorSignedToFloat(-(int)sStack_3a,(byte)(in_fpscr >> 0x16) & 3);
            *puVar4 = uVar14;
            puVar4[1] = uVar15;
            puVar4[2] = uVar16;
            piVar11 = *(int **)(iVar10 + iVar12 * 4);
            piVar11[2] = *piVar11 + 1;
            pvVar7 = realloc((void *)piVar11[1],(*piVar11 + 1) * 4);
            piVar11[1] = (int)pvVar7;
            *(undefined4 **)((int)pvVar7 + *piVar11 * 4) = puVar4;
            *piVar11 = piVar11[2];
            if (local_36 == 3) {
              pfVar8 = operator_new(0xc);
              *pfVar8 = local_40;
              pfVar8[1] = local_48;
              pfVar8[2] = fStack_44;
              piVar11 = *(int **)(*(int *)(pAVar3 + 4) + 0xc);
              piVar11[2] = *piVar11 + 1;
              pvVar7 = realloc((void *)piVar11[1],(*piVar11 + 1) * 4);
              piVar11[1] = (int)pvVar7;
              *(float **)((int)pvVar7 + *piVar11 * 4) = pfVar8;
              *piVar11 = piVar11[2];
            }
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < local_34);
      }
    } while (iVar2 != param_1);
    AEFile::Close(local_30[0]);
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileRead::loadSpacePoints  @0x00146a30  (624 bytes)
/* FileRead::loadSpacePoints(int, int) */

void __thiscall FileRead::loadSpacePoints(FileRead *this,int param_1,int param_2)

{
  String *pSVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  SpacePoint *this_00;
  void *pvVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  AEMath aAStack_114 [60];
  undefined4 local_d8 [5];
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined4 local_a0;
  ushort uStack_96;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  float fStack_88;
  float local_84;
  float fStack_80;
  float local_7c;
  float local_78;
  float local_74;
  float fStack_70;
  float local_6c;
  float local_68;
  ushort local_64;
  ushort uStack_62;
  uint local_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  pSVar1 = (String *)AbyssEngine::String::String((String *)local_d8,"data/bin/docks_hd.bin",false);
  iVar2 = AEFile::FileExist(pSVar1);
  AbyssEngine::String::~String((String *)local_d8);
  if (iVar2 == 1) {
    AEFile::OpenRead("data/bin/docks_hd.bin",&local_60);
    uStack_62 = 0;
    local_64 = 0;
    local_6c = 0.0;
    local_68 = 0.0;
    local_7c = 0.0;
    local_78 = 0.0;
    local_74 = 0.0;
    fStack_70 = 0.0;
    local_84 = 0.0;
    fStack_80 = 0.0;
    local_94 = 0;
    uStack_90 = 0;
    local_8c = 0;
    fStack_88 = 0.0;
    AEFile::Read(&uStack_62,local_60);
    AEFile::Read(&local_64,local_60);
    if ((uint)uStack_62 != param_1) {
      do {
        AEFile::Skip((uint)local_64 * 0x26,local_60);
        AEFile::Read(&uStack_62,local_60);
        AEFile::Read(&local_64,local_60);
      } while ((uint)uStack_62 != param_1);
    }
    piVar3 = operator_new(0xc);
    puVar4 = operator_new__(4);
    piVar3[1] = (int)puVar4;
    piVar3[2] = 1;
    *puVar4 = 0;
    *piVar3 = 0;
    if (local_64 != 0) {
      puVar4 = (undefined4 *)((uint)local_d8 | 4);
      uVar9 = 0;
      uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      iVar2 = 0;
      do {
        AEFile::Read(&uStack_96,local_60);
        AEFile::Read(&fStack_70,local_60);
        AEFile::Read(&local_6c,local_60);
        AEFile::Read(&local_68,local_60);
        AEFile::Read(&local_7c,local_60);
        AEFile::Read(&local_78,local_60);
        AEFile::Read(&local_74,local_60);
        AEFile::Read(&fStack_88,local_60);
        AEFile::Read(&local_84,local_60);
        AEFile::Read(&fStack_80,local_60);
        fVar7 = -local_6c;
        local_d8[0] = 0x3f800000;
        local_6c = local_68;
        local_7c = local_7c * -0.017453292;
        *puVar4 = uVar9;
        puVar4[1] = uVar10;
        puVar4[2] = uVar11;
        puVar4[3] = uVar12;
        local_c4 = 0x3f800000;
        fVar8 = local_74 * -0.017453292;
        local_74 = local_78 * 0.017453292;
        local_b0 = 0x3f800000;
        uStack_a8 = 0x3f8000003f800000;
        local_a0 = 0x3f800000;
        local_78 = fVar8;
        local_68 = fVar7;
        local_c0 = uVar9;
        uStack_bc = uVar10;
        uStack_b8 = uVar11;
        uStack_b4 = uVar12;
        AbyssEngine::AEMath::MatrixSetRotation
                  (aAStack_114,(String *)local_d8,local_7c,fVar8,local_74);
        AbyssEngine::AEMath::Matrix::operator=((Matrix *)local_d8,aAStack_114);
        AbyssEngine::AEMath::MatrixGetDir(aAStack_114,(String *)local_d8);
        iVar5 = AbyssEngine::AEMath::Vector::operator=((Vector *)&local_94,(Vector *)aAStack_114);
        if (param_2 != -1) {
          iVar5 = iVar2 / 2;
        }
        if (param_2 == -1 || iVar5 == param_2) {
          this_00 = operator_new(0x24);
          SpacePoint::SpacePoint
                    (this_00,(uint)uStack_96,(Vector *)&fStack_70,(Vector *)&local_94,iVar2);
          piVar3[2] = *piVar3 + 1;
          pvVar6 = realloc((void *)piVar3[1],(*piVar3 + 1) * 4);
          piVar3[1] = (int)pvVar6;
          *(SpacePoint **)((int)pvVar6 + *piVar3 * 4) = this_00;
          *piVar3 = piVar3[2];
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)local_64);
    }
    AEFile::Close(local_60);
  }
  if (__stack_chk_guard - local_5c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_5c);
  }
  return;
}

