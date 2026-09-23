// Class: AbyssEngine::ConfigReader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::ConfigReader::ConfigReader  @0x00092238  (160 bytes)
/* AbyssEngine::ConfigReader::ConfigReader(AbyssEngine::Engine*) */

void __thiscall AbyssEngine::ConfigReader::ConfigReader(ConfigReader *this,Engine *param_1)

{
  undefined4 *puVar1;
  String aSStack_2c [8];
  String aSStack_24 [8];
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 4) = puVar1;
  *(undefined4 *)(this + 8) = 1;
  *puVar1 = 0;
  *(undefined4 *)this = 0;
  *(Engine **)(this + 0xc) = param_1;
  String::String(aSStack_1c,"TIMER",false);
  RegisterTokenReadFunction(this,aSStack_1c,&DAT_00092385,param_1);
  String::~String(aSStack_1c);
  String::String(aSStack_24,"KEYMAP",false);
  RegisterTokenReadFunction(this,aSStack_24,&DAT_000923f1,param_1);
  String::~String(aSStack_24);
  String::String(aSStack_2c,"VIBRATION",false);
  RegisterTokenReadFunction(this,aSStack_2c,0x92611,param_1);
  String::~String(aSStack_2c);
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== AbyssEngine::ConfigReader::RegisterTokenReadFunction  @0x00092324  (80 bytes)
/* AbyssEngine::ConfigReader::RegisterTokenReadFunction(AbyssEngine::String, void
   (*)(AbyssEngine::ConfigReader*, void*), void*) */

void __thiscall
AbyssEngine::ConfigReader::RegisterTokenReadFunction
          (ConfigReader *this,String *param_2,undefined4 param_3,undefined4 param_4)

{
  String *this_00;
  void *pvVar1;
  
  this_00 = operator_new(0x10);
  *(undefined4 *)this_00 = 0;
  *(undefined4 *)(this_00 + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this_00 + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this_00 + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  String::String(this_00);
  String::operator=(this_00,param_2);
  *(undefined4 *)(this_00 + 8) = param_3;
  *(undefined4 *)(this_00 + 0xc) = param_4;
  *(int *)(this + 8) = *(int *)this + 1;
  pvVar1 = realloc(*(void **)(this + 4),(*(int *)this + 1) * 4);
  *(void **)(this + 4) = pvVar1;
  *(String **)((int)pvVar1 + *(int *)this * 4) = this_00;
  *(undefined4 *)this = *(undefined4 *)(this + 8);
  return;
}

// ===== AbyssEngine::ConfigReader::~ConfigReader  @0x00092690  (68 bytes)
/* AbyssEngine::ConfigReader::~ConfigReader() */

ConfigReader * __thiscall AbyssEngine::ConfigReader::~ConfigReader(ConfigReader *this)

{
  void *pvVar1;
  uint uVar2;
  String *this_00;
  uint uVar3;
  
  uVar2 = *(uint *)this;
  pvVar1 = *(void **)(this + 4);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      this_00 = *(String **)((int)pvVar1 + uVar3 * 4);
      if (this_00 != (String *)0x0) {
        pvVar1 = (void *)String::~String(this_00);
        operator_delete(pvVar1);
        uVar2 = *(uint *)this;
        pvVar1 = *(void **)(this + 4);
      }
      *(undefined4 *)((int)pvVar1 + uVar3 * 4) = 0;
      uVar3 = uVar3 + 1;
      pvVar1 = *(void **)(this + 4);
    } while (uVar3 < uVar2);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== AbyssEngine::ConfigReader::ParseFile  @0x000926d4  (238 bytes)
/* AbyssEngine::ConfigReader::ParseFile(AbyssEngine::String) */

void __thiscall AbyssEngine::ConfigReader::ParseFile(ConfigReader *this,String *param_2)

{
  char cVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  String *this_00;
  String aSStack_38 [8];
  String aSStack_30 [4];
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar2 = AEFile::OpenRead(param_2,(uint *)(this + 0x10));
  if (iVar2 == 1) {
    GetNewLine();
    while (cVar1 = String::Compare(aSStack_30,"EOF"), cVar1 != '\0') {
      psVar3 = (short *)String::operator[](aSStack_30,0);
      if (((*psVar3 == 0x5b) &&
          (psVar3 = (short *)String::operator[](aSStack_30,local_2c + -1), *psVar3 == 0x5d)) &&
         (*(int *)this != 0)) {
        uVar4 = 0;
        do {
          this_00 = *(String **)(*(int *)(this + 4) + uVar4 * 4);
          String::SubString((uint)aSStack_38,(uint)aSStack_30);
          cVar1 = String::Compare(this_00,aSStack_38);
          String::~String(aSStack_38);
          if (cVar1 == '\0') {
            iVar2 = *(int *)(*(int *)(this + 4) + uVar4 * 4);
            (**(code **)(iVar2 + 8))(this,*(undefined4 *)(iVar2 + 0xc));
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)this);
      }
      GetNewLine();
      String::operator=(aSStack_30,aSStack_38);
      String::~String(aSStack_38);
    }
    AEFile::Close(*(uint *)(this + 0x10));
    String::~String(aSStack_30);
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::ConfigReader::GetNewLine  @0x000927f0  (230 bytes)
/* AbyssEngine::ConfigReader::GetNewLine() */

void AbyssEngine::ConfigReader::GetNewLine(void)

{
  bool bVar1;
  String *in_r0;
  int iVar2;
  int in_r1;
  String aSStack_34 [11];
  char cStack_29;
  int local_28;
  
  local_28 = __stack_chk_guard;
  String::String(in_r0);
  cStack_29 = '\0';
  if (*(int *)(in_r0 + 4) == 0) {
LAB_00092828:
    do {
      iVar2 = AEFile::Read(&cStack_29,*(uint *)(in_r1 + 0x10));
      if (iVar2 == 1) {
        if (cStack_29 == '\r') goto LAB_00092828;
        if (cStack_29 != '\n') {
          String::operator+=(in_r0,&cStack_29);
          goto LAB_00092828;
        }
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      String::Trim(in_r0);
      String::String(aSStack_34,"//",false);
      iVar2 = String::IndexOf(in_r0,aSStack_34);
      String::~String(aSStack_34);
      if (iVar2 != -1) {
        String::SubString((uint)aSStack_34,(uint)in_r0);
        String::operator=(in_r0,aSStack_34);
        String::~String(aSStack_34);
        String::Trim(in_r0);
      }
      iVar2 = *(int *)(in_r0 + 4);
      if (iVar2 == 0 && !bVar1) {
        String::Set(in_r0,"EOF");
        iVar2 = *(int *)(in_r0 + 4);
      }
    } while (iVar2 == 0);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

