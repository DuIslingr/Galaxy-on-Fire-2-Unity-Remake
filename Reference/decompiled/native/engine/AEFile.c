// Class: AEFile
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AEFile::SetInterface  @0x00079154  (128 bytes)
/* AEFile::SetInterface(FileInterface*) */

void AEFile::SetInterface(FileInterface *param_1)

{
  FileInterface *pFVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  pFVar1 = fileInterface;
  if ((param_1 != (FileInterface *)0x0) && (param_1[4] != (FileInterface)0x0)) {
    if (appRoot != 0) {
      (**(code **)(*(int *)param_1 + 0x34))(param_1);
    }
    if (pakFileEntryList == (undefined4 *)0x0) {
      puVar2 = operator_new(0xc);
      puVar3 = operator_new__(4);
      puVar2[1] = puVar3;
      puVar2[2] = 1;
      *puVar3 = 0;
      *puVar2 = 0;
      pakFileEntryList = puVar2;
    }
    pFVar1 = param_1;
    if (file == (undefined4 *)0x0) {
      puVar2 = operator_new(0xc);
      puVar3 = operator_new__(4);
      puVar2[1] = puVar3;
      puVar2[2] = 1;
      *puVar3 = 0;
      *puVar2 = 0;
      file = puVar2;
      pFVar1 = param_1;
    }
  }
  fileInterface = pFVar1;
  return;
}

// ===== AEFile::Release  @0x000791fc  (162 bytes)
/* AEFile::Release() */

void AEFile::Release(void)

{
  Array *pAVar1;
  uint *puVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  
  if (file != (Array *)0x0) {
    ArrayReleaseClasses<AELowLevelFile*>(file);
    pAVar1 = file;
    if (file != (Array *)0x0) {
      if (*(void **)(file + 4) != (void *)0x0) {
        operator_delete__(*(void **)(file + 4));
      }
      operator_delete(pAVar1);
    }
    file = (Array *)0x0;
  }
  if (pakFileEntryList != (uint *)0x0) {
    if (*pakFileEntryList != 0) {
      uVar5 = 0;
      do {
        uVar3 = pakFileEntryList[1];
        pvVar4 = *(void **)(uVar3 + uVar5 * 4);
        if (pvVar4 != (void *)0x0) {
          AbyssEngine::String::~String((String *)((int)pvVar4 + 4));
          operator_delete(pvVar4);
          uVar3 = pakFileEntryList[1];
        }
        *(undefined4 *)(uVar3 + uVar5 * 4) = 0;
        uVar5 = uVar5 + 1;
      } while (uVar5 < *pakFileEntryList);
      if (pakFileEntryList == (uint *)0x0) {
        pakFileEntryList = (uint *)0x0;
        return;
      }
    }
    puVar2 = pakFileEntryList;
    if ((void *)pakFileEntryList[1] != (void *)0x0) {
      operator_delete__((void *)pakFileEntryList[1]);
    }
    operator_delete(puVar2);
    pakFileEntryList = (uint *)0x0;
    return;
  }
  return;
}

// ===== AEFile::sortPakFileEntryList  @0x000792fc  (96 bytes)
/* AEFile::sortPakFileEntryList() */

void AEFile::sortPakFileEntryList(void)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  
  iVar1 = *pakFileEntryList;
  if (iVar1 != 0) {
    while ((iVar1 = iVar1 + -1, -1 < iVar1 && (0 < iVar1))) {
      iVar4 = 0;
      do {
        iVar2 = pakFileEntryList[1];
        puVar3 = *(uint **)(iVar2 + iVar4 * 4);
        puVar5 = *(uint **)(iVar2 + iVar4 * 4 + 4);
        if (*puVar5 < *puVar3) {
          *(uint **)(iVar2 + iVar4 * 4) = puVar5;
          *(uint **)(pakFileEntryList[1] + iVar4 * 4 + 4) = puVar3;
        }
        iVar4 = iVar4 + 1;
      } while (iVar1 != iVar4);
    }
  }
  return;
}

// ===== AEFile::collectFilesInPakFiles  @0x00079368  (642 bytes)
/* AEFile::collectFilesInPakFiles(AbyssEngine::String&) */

void AEFile::collectFilesInPakFiles(String *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  String *pSVar6;
  undefined4 uVar7;
  void *pvVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  String aSStack_50 [8];
  int local_48;
  int local_44;
  char cStack_3d;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if ((fileInterface != 0) && (*(char *)(fileInterface + 4) != '\0')) {
    Open(param_1,1,0);
    if ((fileInterface != 0) &&
       (((*file != 0 && (piVar1 = *(int **)file[1], piVar1 != (int *)0x0)) &&
        (iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,1,&cStack_3d), iVar2 == 1)))) {
      uVar12 = 0;
      uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar14 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar15 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      iVar2 = 1;
      do {
        iVar11 = (int)cStack_3d;
        uVar3 = iVar11 + 1;
        if (iVar11 < -1) {
          uVar3 = 0xffffffff;
        }
        pcVar4 = operator_new__(uVar3);
        if (fileInterface == 0) {
          pcVar4[iVar11] = '\0';
        }
        else {
          if ((*file == 0) || (piVar1 = *(int **)file[1], piVar1 == (int *)0x0)) {
            pcVar4[iVar11] = '\0';
          }
          else {
            (**(code **)(*piVar1 + 0xc))(piVar1,iVar11,pcVar4);
            iVar11 = fileInterface;
            pcVar4[cStack_3d] = '\0';
            if (iVar11 == 0) goto LAB_000794d8;
          }
          if ((((*file == 0) || (piVar1 = *(int **)file[1], piVar1 == (int *)0x0)) ||
              ((**(code **)(*piVar1 + 0xc))(piVar1,4,&local_44), fileInterface != 0)) &&
             ((*file != 0 && (piVar1 = *(int **)file[1], piVar1 != (int *)0x0)))) {
            (**(code **)(*piVar1 + 0xc))(piVar1,4,&local_48);
          }
        }
LAB_000794d8:
        puVar5 = operator_new(0x18);
        puVar5[5] = 0;
        *puVar5 = uVar12;
        puVar5[1] = uVar13;
        puVar5[2] = uVar14;
        puVar5[3] = uVar15;
        puVar5[4] = 0;
        AbyssEngine::String::String((String *)(puVar5 + 1));
        pSVar6 = (String *)AbyssEngine::String::String(aSStack_50,pcVar4,false);
        uVar7 = crc32_ccitt(pSVar6);
        *puVar5 = uVar7;
        AbyssEngine::String::~String(aSStack_50);
        AbyssEngine::String::operator=((String *)(puVar5 + 1),param_1);
        iVar11 = cStack_3d + iVar2 + 8;
        puVar5[3] = iVar11;
        puVar5[5] = local_48;
        puVar5[4] = local_44;
        piVar1 = pakFileEntryList;
        iVar2 = *pakFileEntryList;
        pakFileEntryList[2] = iVar2 + 1;
        pvVar8 = realloc((void *)piVar1[1],(iVar2 + 1) * 4);
        piVar1[1] = (int)pvVar8;
        *(undefined4 **)((int)pvVar8 + *piVar1 * 4) = puVar5;
        *piVar1 = piVar1[2];
        operator_delete__(pcVar4);
        if (local_48 == -1) {
          if (fileInterface == 0) break;
          if ((*file != 0) && (piVar1 = *(int **)file[1], piVar1 != (int *)0x0)) {
            (**(code **)(*piVar1 + 0x10))(piVar1,local_44);
          }
          piVar1 = &local_44;
        }
        else {
          if (fileInterface == 0) break;
          if ((*file != 0) && (*(int **)file[1] != (int *)0x0)) {
            (**(code **)(**(int **)file[1] + 0x10))();
          }
          piVar1 = &local_48;
        }
        if (((fileInterface == 0) || (*file == 0)) ||
           (piVar9 = *(int **)file[1], piVar9 == (int *)0x0)) break;
        iVar2 = *piVar1;
        iVar10 = (**(code **)(*piVar9 + 0xc))(piVar9,1,&cStack_3d);
        iVar2 = iVar2 + iVar11 + 1;
        if (iVar10 == 0) break;
      } while( true );
    }
    Close(0);
  }
  if (__stack_chk_guard == local_3c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AEFile::OpenRead  @0x0007964c  (8 bytes)
/* AEFile::OpenRead(AbyssEngine::String&, unsigned int*) */

void AEFile::OpenRead(String *param_1,uint *param_2)

{
  Open(param_1,1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079654  (54 bytes)
/* AEFile::Read(unsigned int, void*, unsigned int) */

undefined4 AEFile::Read(uint param_1,void *param_2,uint param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (((fileInterface != 0) && (param_3 < *file)) &&
     (piVar1 = *(int **)(file[1] + param_3 * 4), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1,param_2);
    return uVar2;
  }
  return 0;
}

// ===== AEFile::crc32_ccitt  @0x00079694  (64 bytes)
/* AEFile::crc32_ccitt(AbyssEngine::String const&) */

uint AEFile::crc32_ccitt(String *param_1)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 4) < 1) {
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    uVar2 = 0;
    do {
      puVar1 = (ushort *)AbyssEngine::String::operator[]((String *)param_1,iVar3);
      iVar3 = iVar3 + 1;
      uVar2 = *(uint *)(&DAT_002225b0 + ((*puVar1 ^ uVar2) & 0xff) * 4) ^ uVar2 >> 8;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return uVar2;
}

// ===== AEFile::Skip  @0x000796d8  (52 bytes)
/* AEFile::Skip(unsigned int, unsigned int) */

undefined4 AEFile::Skip(uint param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (((fileInterface != 0) && (param_2 < *file)) &&
     (piVar1 = *(int **)(file[1] + param_2 * 4), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,param_1);
    return uVar2;
  }
  return 0;
}

// ===== AEFile::Close  @0x00079714  (62 bytes)
/* AEFile::Close(unsigned int) */

void AEFile::Close(uint param_1)

{
  int *piVar1;
  uint uVar2;
  
  if ((fileInterface != 0) && (param_1 < *file)) {
    uVar2 = file[1];
    piVar1 = *(int **)(uVar2 + param_1 * 4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
      uVar2 = file[1];
    }
    *(undefined4 *)(uVar2 + param_1 * 4) = 0;
  }
  return;
}

// ===== AEFile::RegisterPakFile  @0x00079760  (18 bytes)
/* AEFile::RegisterPakFile(AbyssEngine::String) */

void AEFile::RegisterPakFile(String *param_1)

{
  collectFilesInPakFiles(param_1);
  sortPakFileEntryList();
  return;
}

// ===== AEFile::collectPakFiles  @0x00079770  (212 bytes)
/* AEFile::collectPakFiles(AbyssEngine::String const&) */

void AEFile::collectPakFiles(String *param_1)

{
  void *pvVar1;
  int iVar2;
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((fileInterface != (int *)0x0) && ((char)fileInterface[1] != '\0')) {
    pvVar1 = (void *)AbyssEngine::String::GetAEChar((String *)param_1);
    iVar2 = (**(code **)(*fileInterface + 0x3c))(fileInterface,pvVar1,0);
    if (iVar2 == 1) {
      AbyssEngine::String::String(aSStack_30);
      while (iVar2 = (**(code **)(*fileInterface + 0x40))(fileInterface,aSStack_30), iVar2 == 1) {
        AbyssEngine::String::String(aSStack_38,aSStack_30,false);
        AbyssEngine::String::String(aSStack_40,".aez",false);
        iVar2 = AbyssEngine::String::IndexOf(aSStack_30,aSStack_40);
        AbyssEngine::String::~String(aSStack_40);
        if (iVar2 != -1) {
          collectFilesInPakFiles(aSStack_38);
        }
        AbyssEngine::String::~String(aSStack_38);
      }
      AbyssEngine::String::~String(aSStack_30);
    }
    if (pvVar1 != (void *)0x0) {
      operator_delete__(pvVar1);
    }
    sortPakFileEntryList();
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::findPakFile  @0x00079880  (312 bytes)
/* AEFile::findPakFile(AbyssEngine::String const&) */

void AEFile::findPakFile(String *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  uint *puVar12;
  code *pcVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  String aSStack_30 [8];
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (*pakFileEntryList != 0) {
    uVar4 = crc32_ccitt(param_1);
    iVar7 = *pakFileEntryList;
    iVar10 = 0;
LAB_000798ae:
    do {
      if (iVar7 <= iVar10) break;
      iVar1 = iVar7 - iVar10 >> 1;
      iVar15 = iVar10 + iVar1;
      puVar12 = *(uint **)(pakFileEntryList[1] + iVar15 * 4);
      uVar14 = *puVar12;
      do {
        if (uVar14 == uVar4) {
          puVar6 = AbyssEngine::String::operator_cast_to_unsigned_short_((String *)(puVar12 + 1));
          piVar3 = fileInterface;
          pcVar13 = *(code **)(*fileInterface + 8);
          if (*(int *)(*(int *)(pakFileEntryList[1] + iVar15 * 4) + 0x14) == -1) {
            AbyssEngine::String::String(aSStack_30,puVar6,false);
            iVar7 = *(int *)(pakFileEntryList[1] + iVar15 * 4);
            uVar8 = (*pcVar13)(piVar3,aSStack_30,*(undefined4 *)(iVar7 + 8),0,0,0,
                               *(undefined4 *)(iVar7 + 0xc));
            puVar2 = &stack0xfffffff4;
          }
          else {
            AbyssEngine::String::String(aSStack_28,puVar6,false);
            iVar7 = *(int *)(pakFileEntryList[1] + iVar15 * 4);
            uVar8 = (*pcVar13)(piVar3,aSStack_28,*(undefined4 *)(iVar7 + 8),1,
                               *(undefined4 *)(iVar7 + 0x10),*(undefined4 *)(iVar7 + 0x14),
                               *(undefined4 *)(iVar7 + 0xc));
            puVar2 = &stack0xfffffffc;
          }
          AbyssEngine::String::~String((String *)(puVar2 + -0x24));
          puVar5 = operator_new(0x14);
          iVar7 = *(int *)(pakFileEntryList[1] + iVar15 * 4);
          uVar11 = *(undefined4 *)(iVar7 + 0x10);
          uVar9 = *(undefined4 *)(iVar7 + 0x14);
          *puVar5 = &PTR__AEPakFile_00263350;
          puVar5[1] = uVar8;
          puVar5[2] = uVar11;
          puVar5[3] = uVar9;
          puVar5[4] = 0;
          goto LAB_000799a0;
        }
        if (uVar4 <= uVar14) {
          bVar16 = iVar7 == iVar15;
          iVar7 = iVar15;
          if (bVar16) goto LAB_000798da;
          goto LAB_000798ae;
        }
      } while (uVar4 <= uVar14);
      iVar10 = iVar15;
      if (iVar1 == 0) break;
    } while( true );
  }
LAB_000798da:
  puVar5 = (undefined4 *)0x0;
LAB_000799a0:
  if (__stack_chk_guard == local_20) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar5);
}

// ===== AEFile::Open  @0x000799f4  (588 bytes)
/* AEFile::Open(AbyssEngine::String&, AEFile::FileOpenType, unsigned int*) */

void AEFile::Open(String *param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  short *psVar6;
  int *piVar7;
  uint uVar8;
  undefined4 *puVar9;
  code *pcVar10;
  String aSStack_54 [8];
  String aSStack_4c [8];
  String aSStack_44 [8];
  String aSStack_3c [8];
  AbyssEngine aAStack_34 [8];
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (fileInterface == (int *)0x0) goto LAB_00079c26;
  puVar2 = AbyssEngine::String::operator_cast_to_unsigned_short_(param_1);
  piVar7 = fileInterface;
  puVar9 = (undefined4 *)0x0;
  if (param_2 == 0) {
    pcVar10 = *(code **)(*fileInterface + 0xc);
    AbyssEngine::String::String(aSStack_4c,puVar2,false);
    iVar3 = (*pcVar10)(piVar7,aSStack_4c,*(undefined4 *)(param_1 + 4),0,0);
    AbyssEngine::String::~String(aSStack_4c);
    if (iVar3 == 0) goto LAB_00079c26;
    puVar9 = operator_new(8);
LAB_00079afc:
    *puVar9 = &PTR__AENormalFile_00263374;
    puVar9[1] = iVar3;
  }
  else {
    if (param_2 == 2) {
      pcVar10 = *(code **)(*fileInterface + 0x10);
      AbyssEngine::String::String(aSStack_54,puVar2,false);
      iVar3 = (*pcVar10)(piVar7,aSStack_54,*(undefined4 *)(param_1 + 4),0,0);
      AbyssEngine::String::~String(aSStack_54);
      if (iVar3 == 0) goto LAB_00079c26;
      puVar9 = operator_new(8);
      goto LAB_00079afc;
    }
    if (param_2 == 1) {
      pcVar10 = *(code **)(*fileInterface + 8);
      AbyssEngine::String::String(aSStack_2c,puVar2,false);
      iVar3 = (*pcVar10)(piVar7,aSStack_2c,*(undefined4 *)(param_1 + 4),0,0,0,0);
      AbyssEngine::String::~String(aSStack_2c);
      if (iVar3 != 0) {
        puVar9 = operator_new(8);
        goto LAB_00079afc;
      }
      psVar6 = (short *)AbyssEngine::String::operator[](param_1,0);
      if (*psVar6 != 0x2f) {
        AbyssEngine::String::String(aSStack_3c,"/",false);
        AbyssEngine::String::String(aSStack_44,param_1,false);
        AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_44);
        AbyssEngine::String::operator=(param_1,aAStack_34);
        AbyssEngine::String::~String((String *)aAStack_34);
        AbyssEngine::String::~String(aSStack_44);
        AbyssEngine::String::~String(aSStack_3c);
      }
      puVar9 = (undefined4 *)findPakFile(param_1);
      if (puVar9 == (undefined4 *)0x0) goto LAB_00079c26;
    }
  }
  puVar1 = file;
  uVar4 = *file;
  if (param_3 == (uint *)0x0) {
    if (uVar4 == 0) {
      file[2] = 1;
      pvVar5 = realloc((void *)puVar1[1],4);
      puVar1[1] = (uint)pvVar5;
      *(undefined4 **)((int)pvVar5 + *puVar1 * 4) = puVar9;
      *puVar1 = puVar1[2];
    }
    else {
      piVar7 = (int *)file[1];
      if ((int *)*piVar7 != (int *)0x0) {
        (**(code **)(*(int *)*piVar7 + 4))();
        piVar7 = (int *)file[1];
      }
      *piVar7 = 0;
      *(undefined4 **)file[1] = puVar9;
    }
  }
  else {
    if (1 < uVar4) {
      uVar8 = 1;
      do {
        if (*(int *)(file[1] + uVar8 * 4) == 0) {
          *(undefined4 **)(file[1] + uVar8 * 4) = puVar9;
          *param_3 = uVar8;
          goto LAB_00079c26;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar4);
    }
    if (uVar4 == 0) {
      file[2] = 1;
      pvVar5 = realloc((void *)puVar1[1],4);
      puVar1[1] = (uint)pvVar5;
      *(undefined4 *)((int)pvVar5 + *puVar1 * 4) = 0;
      *puVar1 = puVar1[2];
      uVar4 = *file;
    }
    puVar1 = file;
    file[2] = uVar4 + 1;
    pvVar5 = realloc((void *)puVar1[1],(uVar4 + 1) * 4);
    puVar1[1] = (uint)pvVar5;
    *(undefined4 **)((int)pvVar5 + *puVar1 * 4) = puVar9;
    *puVar1 = puVar1[2];
    *param_3 = *file - 1;
  }
LAB_00079c26:
  if (__stack_chk_guard - local_24 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_24);
}

// ===== AEFile::OpenRead  @0x00079cb0  (68 bytes)
/* AEFile::OpenRead(char const*, unsigned int*) */

void AEFile::OpenRead(char *param_1,uint *param_2)

{
  undefined4 uVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  uVar1 = AbyssEngine::String::String(aSStack_1c,param_1,false);
  Open(uVar1,1,param_2);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== AEFile::OpenWrite  @0x00079d0c  (8 bytes)
/* AEFile::OpenWrite(AbyssEngine::String&, unsigned int*) */

void AEFile::OpenWrite(String *param_1,uint *param_2)

{
  Open(param_1,0,param_2);
  return;
}

// ===== AEFile::OpenWrite  @0x00079d14  (68 bytes)
/* AEFile::OpenWrite(char const*, unsigned int*) */

void AEFile::OpenWrite(char *param_1,uint *param_2)

{
  undefined4 uVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  uVar1 = AbyssEngine::String::String(aSStack_1c,param_1,false);
  Open(uVar1,0,param_2);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== AEFile::OpenAppend  @0x00079d70  (10 bytes)
/* AEFile::OpenAppend(AbyssEngine::String&, unsigned int*) */

void AEFile::OpenAppend(String *param_1,uint *param_2)

{
  Open(param_1,2,param_2);
  return;
}

// ===== AEFile::OpenAppend  @0x00079d78  (68 bytes)
/* AEFile::OpenAppend(char const*, unsigned int*) */

void AEFile::OpenAppend(char *param_1,uint *param_2)

{
  undefined4 uVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  uVar1 = AbyssEngine::String::String(aSStack_1c,param_1,false);
  Open(uVar1,2,param_2);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== AEFile::Read  @0x00079dd4  (10 bytes)
/* AEFile::Read(char&, unsigned int) */

void AEFile::Read(char *param_1,uint param_2)

{
  Read(1,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079dde  (10 bytes)
/* AEFile::Read(unsigned int&, unsigned int) */

void AEFile::Read(uint *param_1,uint param_2)

{
  Read(4,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079de8  (10 bytes)
/* AEFile::Read(int&, unsigned int) */

void AEFile::Read(int *param_1,uint param_2)

{
  Read(4,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079df2  (10 bytes)
/* AEFile::Read(unsigned short&, unsigned int) */

void AEFile::Read(ushort *param_1,uint param_2)

{
  Read(2,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079dfc  (10 bytes)
/* AEFile::Read(short&, unsigned int) */

void AEFile::Read(short *param_1,uint param_2)

{
  Read(2,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079e06  (10 bytes)
/* AEFile::Read(unsigned char&, unsigned int) */

void AEFile::Read(uchar *param_1,uint param_2)

{
  Read(1,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079e10  (10 bytes)
/* AEFile::Read(signed char&, unsigned int) */

void AEFile::Read(signed *param_1,uint param_2)

{
  Read(1,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079e1a  (10 bytes)
/* AEFile::Read(long long&, unsigned int) */

void AEFile::Read(longlong *param_1,uint param_2)

{
  Read(8,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079e24  (10 bytes)
/* AEFile::Read(bool&, unsigned int) */

void AEFile::Read(bool *param_1,uint param_2)

{
  Read(1,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079e2e  (12 bytes)
/* AEFile::Read(float&, unsigned int) */

void AEFile::Read(float *param_1,uint param_2)

{
  Read(4,param_1,param_2);
  return;
}

// ===== AEFile::Read  @0x00079e38  (174 bytes)
/* AEFile::Read(AbyssEngine::String&, unsigned int, bool) */

void AEFile::Read(String *param_1,uint param_2,bool param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  uint local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = Read(4,&local_20,param_2);
  uVar1 = local_20;
  if (param_3) {
    if (iVar2 != 1) goto LAB_00079ecc;
    uVar3 = (local_20 + 1) * 2;
    if (uVar3 < local_20 + 1) {
      uVar3 = 0xffffffff;
    }
    puVar4 = operator_new__(uVar3);
    iVar2 = Read(uVar1 << 1,puVar4,param_2);
    if (iVar2 == 1) {
      puVar4[local_20] = 0;
      AbyssEngine::String::Set((String *)param_1,puVar4);
    }
  }
  else {
    if (iVar2 != 1) goto LAB_00079ecc;
    puVar4 = operator_new__(local_20 + 1);
    iVar2 = Read(uVar1,puVar4,param_2);
    if (iVar2 == 1) {
      *(undefined1 *)((int)puVar4 + local_20) = 0;
      AbyssEngine::String::Set((String *)param_1,(char *)puVar4);
    }
  }
  operator_delete__(puVar4);
LAB_00079ecc:
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== AEFile::ReadSwitched  @0x00079ef0  (28 bytes)
/* AEFile::ReadSwitched(int&, unsigned int) */

void AEFile::ReadSwitched(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = Read(4,param_1,param_2);
  if (iVar1 == 1) {
    uVar2 = *param_1;
    *param_1 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
  }
  return;
}

// ===== AEFile::ReadSwitched  @0x00079f0c  (30 bytes)
/* AEFile::ReadSwitched(unsigned short&, unsigned int) */

void AEFile::ReadSwitched(ushort *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = Read(2,param_1,param_2);
  if (iVar1 == 1) {
    *param_1 = (ushort)(((uint)*param_1 << 0x18) >> 0x10) | *param_1 >> 8;
  }
  return;
}

// ===== AEFile::ReadSwitched  @0x00079f2a  (30 bytes)
/* AEFile::ReadSwitched(short&, unsigned int) */

void AEFile::ReadSwitched(short *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = Read(2,param_1,param_2);
  if (iVar1 == 1) {
    *param_1 = (ushort)(((uint)(ushort)*param_1 << 0x18) >> 0x10) | (ushort)*param_1 >> 8;
  }
  return;
}

// ===== AEFile::ReadSwitched  @0x00079f48  (130 bytes)
/* AEFile::ReadSwitched(AbyssEngine::String&, unsigned int) */

void AEFile::ReadSwitched(String *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  ushort uStack_1e;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar2 = Read(2,&uStack_1e,param_2);
  if (iVar2 == 1) {
    uVar1 = (uint)uStack_1e << 0x18 | (uint)(uStack_1e >> 8) << 0x10;
    uStack_1e = (ushort)(uVar1 >> 0x10);
    pcVar3 = operator_new__((uVar1 >> 0x10) + 1);
    iVar2 = Read(uVar1 >> 0x10,pcVar3,param_2);
    if (iVar2 == 1) {
      pcVar3[uStack_1e] = '\0';
      AbyssEngine::String::Set((String *)param_1,pcVar3);
    }
    operator_delete__(pcVar3);
  }
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== AEFile::Write  @0x00079fd4  (54 bytes)
/* AEFile::Write(unsigned int, void*, unsigned int) */

undefined4 AEFile::Write(uint param_1,void *param_2,uint param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (((fileInterface != 0) && (param_3 < *file)) &&
     (piVar1 = *(int **)(file[1] + param_3 * 4), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 8))(piVar1,param_1,param_2);
    return uVar2;
  }
  return 0;
}

// ===== AEFile::Write  @0x0007a014  (52 bytes)
/* AEFile::Write(char, unsigned int) */

void AEFile::Write(char param_1,uint param_2)

{
  char cStack_d;
  int local_c;
  
  local_c = __stack_chk_guard;
  cStack_d = param_1;
  Write(1,&cStack_d,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a050  (50 bytes)
/* AEFile::Write(unsigned int, unsigned int) */

void AEFile::Write(uint param_1,uint param_2)

{
  uint local_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_10 = param_1;
  Write(4,&local_10,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a08c  (50 bytes)
/* AEFile::Write(int, unsigned int) */

void AEFile::Write(int param_1,uint param_2)

{
  int local_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_10 = param_1;
  Write(4,&local_10,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a0c8  (52 bytes)
/* AEFile::Write(unsigned short, unsigned int) */

void AEFile::Write(ushort param_1,uint param_2)

{
  ushort uStack_e;
  int local_c;
  
  local_c = __stack_chk_guard;
  uStack_e = param_1;
  Write(2,&uStack_e,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a104  (48 bytes)
/* AEFile::Write(short, unsigned int) */

void AEFile::Write(short param_1,uint param_2)

{
  short sStack_e;
  undefined4 local_c;
  
  local_c = __stack_chk_guard;
  sStack_e = param_1;
  Write(2,&sStack_e,param_2);
  return;
}

// ===== AEFile::Write  @0x0007a140  (52 bytes)
/* AEFile::Write(unsigned char, unsigned int) */

void AEFile::Write(uchar param_1,uint param_2)

{
  uchar uStack_d;
  int local_c;
  
  local_c = __stack_chk_guard;
  uStack_d = param_1;
  Write(1,&uStack_d,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a17c  (52 bytes)
/* AEFile::Write(signed char, unsigned int) */

void AEFile::Write(undefined1 param_1,uint param_2)

{
  undefined1 uStack_d;
  int local_c;
  
  local_c = __stack_chk_guard;
  uStack_d = param_1;
  Write(1,&uStack_d,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a1b8  (50 bytes)
/* AEFile::Write(long long, unsigned int) */

void __thiscall AEFile::Write(AEFile *this,longlong param_1,uint param_2)

{
  AEFile *local_18 [3];
  int local_c;
  
  local_c = __stack_chk_guard;
  local_18[0] = this;
  Write(8,local_18,(uint)param_1);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a1f4  (52 bytes)
/* AEFile::Write(bool, unsigned int) */

void AEFile::Write(bool param_1,uint param_2)

{
  undefined1 uStack_d;
  int local_c;
  
  local_c = __stack_chk_guard;
  uStack_d = param_1;
  Write(1,&uStack_d,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a230  (50 bytes)
/* AEFile::Write(float, unsigned int) */

void AEFile::Write(float param_1,uint param_2)

{
  uint in_r1;
  uint local_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_10 = param_2;
  Write(4,&local_10,in_r1);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::Write  @0x0007a26c  (142 bytes)
/* AEFile::Write(AbyssEngine::String const&, unsigned int, bool) */

void AEFile::Write(String *param_1,uint param_2,bool param_3)

{
  void *pvVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (param_3) {
    pvVar1 = (void *)AbyssEngine::String::GetAEWChar((String *)param_1);
    local_1c = *(undefined4 *)(param_1 + 4);
    iVar2 = Write(4,&local_1c,param_2);
    if (iVar2 == 1) {
      Write(*(int *)(param_1 + 4) << 1,pvVar1,param_2);
    }
  }
  else {
    pvVar1 = (void *)AbyssEngine::String::GetAEChar((String *)param_1);
    local_20 = *(undefined4 *)(param_1 + 4);
    iVar2 = Write(4,&local_20,param_2);
    if (iVar2 == 1) {
      Write(*(uint *)(param_1 + 4),pvVar1,param_2);
    }
    if (pvVar1 != (void *)0x0) {
      operator_delete__(pvVar1);
    }
  }
  if (__stack_chk_guard - local_18 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_18);
}

// ===== AEFile::GetFileSize  @0x0007a304  (42 bytes)
/* AEFile::GetFileSize(unsigned int) */

undefined4 AEFile::GetFileSize(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (fileInterface != 0) {
    if ((param_1 < *file) && (piVar1 = *(int **)(file[1] + param_1 * 4), piVar1 != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0007a328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*piVar1 + 0x18))();
      return uVar2;
    }
  }
  return 0;
}

// ===== AEFile::FileExist  @0x0007a338  (196 bytes)
/* AEFile::FileExist(AbyssEngine::String const&) */

void AEFile::FileExist(String *param_1)

{
  int *piVar1;
  int iVar2;
  String *this;
  short *psVar3;
  code *pcVar4;
  String aSStack_44 [8];
  String aSStack_3c [8];
  AbyssEngine aAStack_34 [8];
  String aSStack_2c [8];
  String aSStack_24 [8];
  int local_1c;
  
  piVar1 = fileInterface;
  local_1c = __stack_chk_guard;
  if (fileInterface != (int *)0x0) {
    pcVar4 = *(code **)(*fileInterface + 0x24);
    AbyssEngine::String::String(aSStack_24,param_1,false);
    iVar2 = (*pcVar4)(piVar1,aSStack_24);
    AbyssEngine::String::~String(aSStack_24);
    if (iVar2 == 0) {
      this = (String *)AbyssEngine::String::String(aSStack_2c,param_1,false);
      psVar3 = (short *)AbyssEngine::String::operator[](this,0);
      if (*psVar3 != 0x2f) {
        AbyssEngine::String::String(aSStack_3c,"/",false);
        AbyssEngine::String::String(aSStack_44,param_1,false);
        AbyssEngine::operator+(aAStack_34,aSStack_3c,aSStack_44);
        AbyssEngine::String::operator=(aSStack_2c,aAStack_34);
        AbyssEngine::String::~String((String *)aAStack_34);
        AbyssEngine::String::~String(aSStack_44);
        AbyssEngine::String::~String(aSStack_3c);
      }
      findPakFile(aSStack_2c);
      AbyssEngine::String::~String(aSStack_2c);
    }
  }
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== AEFile::FileDelete  @0x0007a440  (84 bytes)
/* AEFile::FileDelete(AbyssEngine::String const&) */

void AEFile::FileDelete(String *param_1)

{
  int *piVar1;
  code *pcVar2;
  String aSStack_20 [8];
  int local_18;
  
  piVar1 = fileInterface;
  local_18 = __stack_chk_guard;
  if (fileInterface != (int *)0x0) {
    pcVar2 = *(code **)(*fileInterface + 0x28);
    AbyssEngine::String::String(aSStack_20,param_1,false);
    (*pcVar2)(piVar1,aSStack_20);
    AbyssEngine::String::~String(aSStack_20);
  }
  if (__stack_chk_guard - local_18 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_18);
}

// ===== AEFile::GetDeviceFreeSpace  @0x0007a4b0  (20 bytes)
/* AEFile::GetDeviceFreeSpace() */

undefined4 AEFile::GetDeviceFreeSpace(void)

{
  undefined4 uVar1;
  
  if (fileInterface != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007a4be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*fileInterface + 0x2c))();
    return uVar1;
  }
  return 0;
}

// ===== AEFile::GetAppRootDir  @0x0007a4c8  (20 bytes)
/* AEFile::GetAppRootDir() */

undefined4 AEFile::GetAppRootDir(void)

{
  undefined4 uVar1;
  
  if (fileInterface != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007a4d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*fileInterface + 0x30))();
    return uVar1;
  }
  return 0;
}

// ===== AEFile::SetAppRootDir  @0x0007a4e0  (20 bytes)
/* AEFile::SetAppRootDir(void*) */

void AEFile::SetAppRootDir(void *param_1)

{
  if (fileInterface != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007a4f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*fileInterface + 0x34))(fileInterface,param_1);
    return;
  }
  return;
}

// ===== AEFile::SetZipDirectory  @0x0007a4f8  (20 bytes)
/* AEFile::SetZipDirectory(void*) */

void AEFile::SetZipDirectory(void *param_1)

{
  if (fileInterface != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007a508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*fileInterface + 0x38))(fileInterface,param_1);
    return;
  }
  return;
}

// ===== AEFile::SetSaveDirectory  @0x0007a510  (76 bytes)
/* AEFile::SetSaveDirectory(AbyssEngine::String) */

void AEFile::SetSaveDirectory(String *param_1)

{
  int *piVar1;
  code *pcVar2;
  String aSStack_20 [8];
  int local_18;
  
  piVar1 = fileInterface;
  local_18 = __stack_chk_guard;
  if (fileInterface != (int *)0x0) {
    pcVar2 = *(code **)(*fileInterface + 0x50);
    AbyssEngine::String::String(aSStack_20,param_1,false);
    (*pcVar2)(piVar1,aSStack_20);
    AbyssEngine::String::~String(aSStack_20);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEFile::ResetSaveDirectory  @0x0007a578  (18 bytes)
/* AEFile::ResetSaveDirectory() */

void AEFile::ResetSaveDirectory(void)

{
  if (fileInterface != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007a586. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*fileInterface + 0x54))();
    return;
  }
  return;
}

