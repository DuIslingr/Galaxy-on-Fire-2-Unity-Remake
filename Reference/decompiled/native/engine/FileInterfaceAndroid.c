// Class: FileInterfaceAndroid
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== FileInterfaceAndroid::FileInterfaceAndroid  @0x00076a6c  (28 bytes)
/* FileInterfaceAndroid::FileInterfaceAndroid() */

void __thiscall FileInterfaceAndroid::FileInterfaceAndroid(FileInterfaceAndroid *this)

{
  *(undefined ***)this = &PTR__FileInterfaceAndroid_002632dc;
  this[4] = (FileInterfaceAndroid)0x1;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  this[0x24] = (FileInterfaceAndroid)0x0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

// ===== FileInterfaceAndroid::OpenAppend  @0x00076a8c  (4 bytes)
/* FileInterfaceAndroid::OpenAppend(AbyssEngine::String, int, bool, unsigned int) */

undefined4 FileInterfaceAndroid::OpenAppend(void)

{
  return 0;
}

// ===== FileInterfaceAndroid::FileInterfaceAndroid  @0x00076a90  (60 bytes)
/* FileInterfaceAndroid::FileInterfaceAndroid(zip_file*, bool, int, int, int) */

FileInterfaceAndroid * __thiscall
FileInterfaceAndroid::FileInterfaceAndroid
          (FileInterfaceAndroid *this,zip_file *param_1,bool param_2,int param_3,int param_4,
          int param_5)

{
  *(undefined ***)this = &PTR__FileInterfaceAndroid_002632dc;
  *(undefined4 *)(this + 8) = 0;
  *(zip_file **)(this + 0xc) = param_1;
  *(undefined4 *)(this + 0x10) = 0;
  this[0x14] = (FileInterfaceAndroid)0x0;
  fileCounter = fileCounter + 1;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  Seek(this,param_3);
  this[0x24] = (FileInterfaceAndroid)param_2;
  return this;
}

// ===== FileInterfaceAndroid::FileInterfaceAndroid  @0x00076ad4  (48 bytes)
/* FileInterfaceAndroid::FileInterfaceAndroid(__sFILE*, bool) */

void __thiscall
FileInterfaceAndroid::FileInterfaceAndroid(FileInterfaceAndroid *this,__sFILE *param_1,bool param_2)

{
  *(undefined ***)this = &PTR__FileInterfaceAndroid_002632dc;
  *(__sFILE **)(this + 8) = param_1;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  this[0x14] = (FileInterfaceAndroid)param_2;
  fileCounter = fileCounter + 1;
  return;
}

// ===== FileInterfaceAndroid::FileInterfaceAndroid  @0x00076b0c  (246 bytes)
/* FileInterfaceAndroid::FileInterfaceAndroid(_jobject*, bool) */

FileInterfaceAndroid * __thiscall
FileInterfaceAndroid::FileInterfaceAndroid
          (FileInterfaceAndroid *this,_jobject *param_1,bool param_2)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  
  *(undefined ***)this = &PTR__FileInterfaceAndroid_002632dc;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(_jobject **)(this + 0x10) = param_1;
  this[0x14] = (FileInterfaceAndroid)param_2;
  fileCounter = fileCounter + 1;
  if (param_2) {
    uVar1 = (**(code **)(*env + 0x7c))();
    if (methodWrite == 0) {
      methodWrite = (**(code **)(*env + 0x84))(env,uVar1,"write","([B)V");
    }
    if (methodCloseWrite != 0) {
      return this;
    }
    uVar1 = (**(code **)(*env + 0x84))(env,uVar1,"close",&DAT_0021f19b);
    ppuVar2 = &PTR_methodCloseWrite_00265580;
  }
  else {
    uVar1 = (**(code **)(*env + 0x7c))();
    if (methodRead == 0) {
      methodRead = (**(code **)(*env + 0x84))(env,uVar1,&DAT_0021f708,"([B)I");
    }
    if (methodCloseRead != 0) {
      return this;
    }
    uVar1 = (**(code **)(*env + 0x84))(env,uVar1,"close",&DAT_0021f19b);
    ppuVar2 = &PTR_methodCloseRead_00265578;
  }
  *(undefined4 *)*ppuVar2 = uVar1;
  return this;
}

// ===== FileInterfaceAndroid::~FileInterfaceAndroid  @0x00076c6c  (52 bytes)
/* FileInterfaceAndroid::~FileInterfaceAndroid() */

FileInterfaceAndroid * __thiscall
FileInterfaceAndroid::~FileInterfaceAndroid(FileInterfaceAndroid *this)

{
  *(undefined ***)this = &PTR__FileInterfaceAndroid_002632dc;
  Close(this);
  if (fileCounter == 0) {
    this[4] = (FileInterfaceAndroid)0x0;
  }
  else {
    fileCounter = fileCounter + -1;
  }
  return this;
}

// ===== FileInterfaceAndroid::~FileInterfaceAndroid  @0x00076cba  (16 bytes)
/* FileInterfaceAndroid::~FileInterfaceAndroid() */

void __thiscall FileInterfaceAndroid::~FileInterfaceAndroid(FileInterfaceAndroid *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~FileInterfaceAndroid(this);
  operator_delete(pvVar1);
  return;
}

// ===== FileInterfaceAndroid::OpenRead  @0x00076ccc  (494 bytes)
/* FileInterfaceAndroid::OpenRead(AbyssEngine::String, int, bool, int, int, unsigned int) */

void __thiscall
FileInterfaceAndroid::OpenRead
          (FileInterfaceAndroid *this,String *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,uint param_7)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  FileInterfaceAndroid *this_00;
  char *__filename;
  FILE *pFVar7;
  undefined4 *puVar8;
  ushort *puVar9;
  String aSStack_50 [8];
  AbyssEngine aAStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar2 = (ushort *)AbyssEngine::String::GetAEWChar(param_2);
  if (this[4] == (FileInterfaceAndroid)0x0) goto LAB_00076e28;
  uVar1 = *puVar2;
  AbyssEngine::String::String(aSStack_30,"assets/",false);
  puVar9 = puVar2 + 1;
  if (uVar1 != 0x2f) {
    puVar9 = puVar2;
  }
  AbyssEngine::String::String(aSStack_38,puVar9,false);
  AbyssEngine::String::operator+=(aSStack_30,aSStack_38);
  AbyssEngine::String::~String(aSStack_38);
  AbyssEngine::String::String(aSStack_38,"47947_GOF2CONTENT_ETC/assets/",false);
  AbyssEngine::String::String(aSStack_40,puVar9,false);
  AbyssEngine::String::operator+=(aSStack_38,aSStack_40);
  AbyssEngine::String::~String(aSStack_40);
  uVar3 = AbyssEngine::String::GetAEChar(aSStack_30);
  fprintf((FILE *)glColorMask,"OpenRead(\'%s\', %d, %d, %d, %d, %d)\n",uVar3,param_3,param_4,param_5
          ,param_6,param_7);
  uVar3 = APKArchive;
  uVar4 = AbyssEngine::String::GetAEChar(aSStack_30);
  iVar5 = zip_fopen(uVar3,uVar4,0);
  uVar3 = ZIPArchive;
  uVar4 = AbyssEngine::String::GetAEChar(aSStack_38);
  iVar6 = zip_fopen(uVar3,uVar4,0);
  if (iVar5 == 0) {
    if (iVar6 != 0) {
      this_00 = operator_new(0x38);
      *(undefined ***)this_00 = &PTR__FileInterfaceAndroid_002632dc;
      *(undefined4 *)(this_00 + 8) = 0;
      *(int *)(this_00 + 0xc) = iVar6;
      *(undefined4 *)(this_00 + 0x10) = 0;
      this_00[0x14] = (FileInterfaceAndroid)0x0;
      fileCounter = fileCounter + 1;
      *(undefined4 *)(this_00 + 0x1c) = 0;
      *(undefined4 *)(this_00 + 0x28) = 0;
      Seek(this_00,param_7);
      goto LAB_00076e18;
    }
    if (*(char **)(this + 0x30) != (char *)0x0) {
      AbyssEngine::String::String(aSStack_40,*(char **)(this + 0x30),false);
      AbyssEngine::String::String(aSStack_50,puVar9,false);
      AbyssEngine::operator+(aAStack_48,aSStack_40,aSStack_50);
      AbyssEngine::String::~String(aSStack_50);
      __filename = (char *)AbyssEngine::String::GetAEChar((String *)aAStack_48);
      pFVar7 = fopen(__filename,"rb");
      if (pFVar7 != (FILE *)0x0) {
        puVar8 = operator_new(0x38);
        *puVar8 = &PTR__FileInterfaceAndroid_002632dc;
        puVar8[2] = pFVar7;
        puVar8[3] = 0;
        puVar8[4] = 0;
        *(undefined1 *)(puVar8 + 5) = 0;
        fileCounter = fileCounter + 1;
      }
      AbyssEngine::String::~String((String *)aAStack_48);
      AbyssEngine::String::~String(aSStack_40);
    }
  }
  else {
    this_00 = operator_new(0x38);
    *(undefined ***)this_00 = &PTR__FileInterfaceAndroid_002632dc;
    *(undefined4 *)(this_00 + 8) = 0;
    *(int *)(this_00 + 0xc) = iVar5;
    *(undefined4 *)(this_00 + 0x10) = 0;
    this_00[0x14] = (FileInterfaceAndroid)0x0;
    fileCounter = fileCounter + 1;
    *(undefined4 *)(this_00 + 0x1c) = 0;
    *(undefined4 *)(this_00 + 0x28) = 0;
    Seek(this_00,param_7);
LAB_00076e18:
    this_00[0x24] = SUB41(param_4,0);
  }
  AbyssEngine::String::~String(aSStack_38);
  AbyssEngine::String::~String(aSStack_30);
LAB_00076e28:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FileInterfaceAndroid::OpenWrite  @0x00076f44  (170 bytes)
/* FileInterfaceAndroid::OpenWrite(AbyssEngine::String, int, bool, unsigned int) */

void FileInterfaceAndroid::OpenWrite(int param_1,String *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  char *__filename;
  FILE *pFVar4;
  undefined4 *puVar5;
  String aSStack_2c [8];
  AbyssEngine aAStack_24 [8];
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  puVar2 = (ushort *)AbyssEngine::String::GetAEWChar(param_2);
  puVar3 = puVar2;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
  } while (uVar1 != 0);
  AbyssEngine::String::String(aSStack_1c,*(char **)(param_1 + 0x30),false);
  AbyssEngine::String::String(aSStack_2c,puVar2,false);
  AbyssEngine::operator+(aAStack_24,aSStack_1c,aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  __filename = (char *)AbyssEngine::String::GetAEChar((String *)aAStack_24);
  pFVar4 = fopen(__filename,"wb");
  if (pFVar4 != (FILE *)0x0) {
    puVar5 = operator_new(0x38);
    *puVar5 = &PTR__FileInterfaceAndroid_002632dc;
    puVar5[2] = pFVar4;
    puVar5[3] = 0;
    puVar5[4] = 0;
    *(undefined1 *)(puVar5 + 5) = 1;
    fileCounter = fileCounter + 1;
  }
  AbyssEngine::String::~String((String *)aAStack_24);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== FileInterfaceAndroid::Read  @0x00077024  (358 bytes)
/* FileInterfaceAndroid::Read(unsigned int, void*) */

uint __thiscall FileInterfaceAndroid::Read(FileInterfaceAndroid *this,uint param_1,void *param_2)

{
  uint uVar1;
  size_t sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  undefined4 local_38 [2];
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(int *)(this + 0xc) != 0) {
    uVar1 = zip_fread(*(int *)(this + 0xc),param_2,param_1);
    uVar1 = (uint)(uVar1 == param_1);
    if (__stack_chk_guard == local_28) {
      return uVar1;
    }
    goto LAB_00077186;
  }
  if (*(FILE **)(this + 8) == (FILE *)0x0) {
    if (*(int *)(this + 0x10) == 0) {
      uVar5 = 0;
    }
    else {
      uVar3 = (**(code **)(*(int *)env + 0x2c0))(env,param_1);
      uVar1 = _JNIEnv::CallIntMethod(env,*(_jmethodID **)(this + 0x10),methodRead,uVar3);
      iVar4 = (**(code **)(*(int *)env + 0x3c))();
      if (iVar4 == 0) {
        if (uVar1 != param_1) goto LAB_0007715e;
        (**(code **)(*(int *)env + 800))(env,uVar3,0,param_1,param_2);
        AbyssEngine::String::String(aSStack_30);
        if (param_1 != 0) {
          uVar1 = 0;
          do {
            AbyssEngine::String::String((String *)local_38," ",false);
            AbyssEngine::String::operator+=(aSStack_30,(String *)local_38);
            lVar6 = AbyssEngine::String::~String((String *)local_38);
            local_38[0] = 0;
            AbyssEngine::String::Set(lVar6);
            AbyssEngine::String::operator+=(aSStack_30,(String *)local_38);
            AbyssEngine::String::~String((String *)local_38);
            uVar1 = uVar1 + 1;
          } while (uVar1 < param_1);
        }
        AbyssEngine::String::~String(aSStack_30);
        uVar5 = 1;
      }
      else {
        (**(code **)(*(int *)env + 0x40))();
        (**(code **)(*(int *)env + 0x44))();
LAB_0007715e:
        uVar5 = 0;
      }
      (**(code **)(*(int *)env + 0x5c))(env,uVar3);
    }
  }
  else {
    sVar2 = fread(param_2,1,param_1,*(FILE **)(this + 8));
    uVar5 = (uint)(sVar2 == param_1);
  }
  uVar1 = __stack_chk_guard - local_28;
  if (uVar1 == 0) {
    return uVar5;
  }
LAB_00077186:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

// ===== FileInterfaceAndroid::Write  @0x0007721c  (172 bytes)
/* FileInterfaceAndroid::Write(unsigned int, void const*) */

bool __thiscall FileInterfaceAndroid::Write(FileInterfaceAndroid *this,uint param_1,void *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  if (*(FILE **)(this + 8) != (FILE *)0x0) {
    sVar1 = fwrite(param_2,1,param_1,*(FILE **)(this + 8));
    return sVar1 == param_1;
  }
  if (*(int *)(this + 0x10) == 0) {
    bVar4 = true;
  }
  else {
    uVar2 = (**(code **)(*(int *)env + 0x2c0))(env,param_1);
    (**(code **)(*(int *)env + 0x340))(env,uVar2,0,param_1,param_2);
    _JNIEnv::CallVoidMethod(env,*(_jmethodID **)(this + 0x10),methodWrite,uVar2);
    iVar3 = (**(code **)(*(int *)env + 0x3c))();
    bVar4 = iVar3 == 0;
    if (!bVar4) {
      (**(code **)(*(int *)env + 0x44))();
    }
    (**(code **)(*(int *)env + 0x5c))(env,uVar2);
  }
  return bVar4;
}

// ===== FileInterfaceAndroid::Seek  @0x00077328  (82 bytes)
/* FileInterfaceAndroid::Seek(unsigned int) */

undefined4 __thiscall FileInterfaceAndroid::Seek(FileInterfaceAndroid *this,uint param_1)

{
  void *__ptr;
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  if (param_1 == 0) {
    uVar2 = 1;
  }
  else {
    iVar3 = *(int *)(this + 0xc);
    if (iVar3 == 0) {
      if (*(FILE **)(this + 8) == (FILE *)0x0) {
        return 0;
      }
      iVar3 = fseek(*(FILE **)(this + 8),param_1,1);
      bVar4 = iVar3 == 0;
    }
    else {
      __ptr = malloc(param_1);
      if (__ptr == (void *)0x0) {
        return 0;
      }
      uVar1 = zip_fread(iVar3,__ptr,param_1);
      free(__ptr);
      bVar4 = uVar1 == param_1;
    }
    uVar2 = 0;
    if (bVar4) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

// ===== FileInterfaceAndroid::GetFileSize  @0x0007737a  (38 bytes)
/* FileInterfaceAndroid::GetFileSize() */

long __thiscall FileInterfaceAndroid::GetFileSize(FileInterfaceAndroid *this)

{
  long lVar1;
  
  fseek(*(FILE **)(this + 8),0,2);
  lVar1 = ftell(*(FILE **)(this + 8));
  fseek(*(FILE **)(this + 8),0,0);
  return lVar1;
}

// ===== FileInterfaceAndroid::GetAppRootDir  @0x000773a0  (4 bytes)
/* FileInterfaceAndroid::GetAppRootDir() */

undefined4 __thiscall FileInterfaceAndroid::GetAppRootDir(FileInterfaceAndroid *this)

{
  return *(undefined4 *)(this + 0x30);
}

// ===== FileInterfaceAndroid::FileExist  @0x000773cc  (228 bytes)
/* FileInterfaceAndroid::FileExist(AbyssEngine::String) */

void __thiscall FileInterfaceAndroid::FileExist(FileInterfaceAndroid *this,String *param_2)

{
  undefined4 uVar1;
  String *this_00;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *__filename;
  FILE *__stream;
  AbyssEngine aAStack_3c [8];
  String aSStack_34 [8];
  String aSStack_2c [8];
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  this_00 = (String *)AbyssEngine::String::String(aSStack_24,"assets/",false);
  AbyssEngine::String::operator+=(this_00,param_2);
  AbyssEngine::String::String(aSStack_2c,"47947_GOF2CONTENT_ETC/assets/",false);
  AbyssEngine::String::operator+=(aSStack_2c,param_2);
  uVar1 = APKArchive;
  uVar2 = AbyssEngine::String::GetAEChar(aSStack_24);
  iVar3 = zip_fopen(uVar1,uVar2,0);
  uVar1 = ZIPArchive;
  uVar2 = AbyssEngine::String::GetAEChar(aSStack_2c);
  iVar4 = zip_fopen(uVar1,uVar2,0);
  if (iVar3 == 0) {
    if (iVar4 == 0) {
      AbyssEngine::String::String(aSStack_34,*(char **)(this + 0x30),false);
      AbyssEngine::operator+(aAStack_3c,aSStack_34,param_2);
      __filename = (char *)AbyssEngine::String::GetAEChar((String *)aAStack_3c);
      __stream = fopen(__filename,"rb");
      if (__stream != (FILE *)0x0) {
        fclose(__stream);
      }
      AbyssEngine::String::~String((String *)aAStack_3c);
      AbyssEngine::String::~String(aSStack_34);
    }
    else {
      zip_fclose();
    }
  }
  else {
    zip_fclose(iVar3);
  }
  AbyssEngine::String::~String(aSStack_2c);
  AbyssEngine::String::~String(aSStack_24);
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== FileInterfaceAndroid::FileDelete  @0x000774fc  (52 bytes)
/* FileInterfaceAndroid::FileDelete(AbyssEngine::String) */

void __thiscall FileInterfaceAndroid::FileDelete(undefined4 param_1,String *param_2)

{
  String *this;
  String aSStack_14 [8];
  int local_c;
  
  local_c = __stack_chk_guard;
  this = (String *)AbyssEngine::String::String(aSStack_14,param_2,false);
  AbyssEngine::String::~String(this);
  if (__stack_chk_guard - local_c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_c);
  }
  return;
}

// ===== FileInterfaceAndroid::GetDeviceFreeSpace  @0x00077538  (4 bytes)
/* FileInterfaceAndroid::GetDeviceFreeSpace() */

undefined4 FileInterfaceAndroid::GetDeviceFreeSpace(void)

{
  return 0;
}

// ===== FileInterfaceAndroid::FileEnumInit  @0x0007753c  (4 bytes)
/* FileInterfaceAndroid::FileEnumInit(char*, bool) */

longlong FileInterfaceAndroid::FileEnumInit(char *param_1,bool param_2)

{
  return (ulonglong)param_2 << 0x20;
}

// ===== FileInterfaceAndroid::FileGetNextEnum  @0x00077540  (4 bytes)
/* FileInterfaceAndroid::FileGetNextEnum(AbyssEngine::String&) */

undefined4 FileInterfaceAndroid::FileGetNextEnum(String *param_1)

{
  return 0;
}

// ===== FileInterfaceAndroid::Close  @0x00077544  (72 bytes)
/* FileInterfaceAndroid::Close() */

void __thiscall FileInterfaceAndroid::Close(FileInterfaceAndroid *this)

{
  undefined **ppuVar1;
  
  if (*(FILE **)(this + 8) != (FILE *)0x0) {
    fclose(*(FILE **)(this + 8));
    *(undefined4 *)(this + 8) = 0;
  }
  if (*(int *)(this + 0xc) != 0) {
    zip_fclose();
    *(undefined4 *)(this + 0xc) = 0;
  }
  if (*(_jmethodID **)(this + 0x10) != (_jmethodID *)0x0) {
    if (this[0x14] == (FileInterfaceAndroid)0x0) {
      ppuVar1 = &PTR_methodCloseRead_00265578;
    }
    else {
      ppuVar1 = &PTR_methodCloseWrite_00265580;
    }
    _JNIEnv::CallVoidMethod(env,*(_jmethodID **)(this + 0x10),*(undefined4 *)*ppuVar1);
    *(undefined4 *)(this + 0x10) = 0;
  }
  return;
}

// ===== FileInterfaceAndroid::SetAppRootDir  @0x00077598  (6 bytes)
/* FileInterfaceAndroid::SetAppRootDir(void*) */

void __thiscall FileInterfaceAndroid::SetAppRootDir(FileInterfaceAndroid *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    *(void **)(this + 0x30) = param_1;
  }
  return;
}

// ===== FileInterfaceAndroid::SetZipDirectory  @0x0007759e  (6 bytes)
/* FileInterfaceAndroid::SetZipDirectory(void*) */

void __thiscall FileInterfaceAndroid::SetZipDirectory(FileInterfaceAndroid *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    *(void **)(this + 0x34) = param_1;
  }
  return;
}

// ===== FileInterfaceAndroid::Output  @0x000775a4  (2 bytes)
/* FileInterfaceAndroid::Output(char*) */

char * FileInterfaceAndroid::Output(char *param_1)

{
  return param_1;
}

// ===== FileInterfaceAndroid::SetSaveDirectory  @0x000775aa  (2 bytes)
/* FileInterfaceAndroid::SetSaveDirectory(AbyssEngine::String) */

void FileInterfaceAndroid::SetSaveDirectory(void)

{
  return;
}

// ===== FileInterfaceAndroid::ResetSaveDirectory  @0x000775ac  (2 bytes)
/* FileInterfaceAndroid::ResetSaveDirectory() */

void FileInterfaceAndroid::ResetSaveDirectory(void)

{
  return;
}

// ===== FileInterfaceAndroid::GetDirPreFix  @0x000775b0  (16 bytes)
/* FileInterfaceAndroid::GetDirPreFix() */

void __thiscall FileInterfaceAndroid::GetDirPreFix(FileInterfaceAndroid *this)

{
  AbyssEngine::String::String((String *)this,"",false);
  return;
}

