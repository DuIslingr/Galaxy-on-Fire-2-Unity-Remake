// Class: AbyssEngine::String
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::String::Reverse  @0x0007b69c  (140 bytes)
/* AbyssEngine::String::Reverse() */

void __thiscall AbyssEngine::String::Reverse(String *this)

{
  short sVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  uint uVar7;
  void *local_20;
  int iStack_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if ((*(int *)this != 0) && (sVar1 = GameText::getLanguage(), sVar1 == 9)) {
    local_20 = (void *)0x0;
    Set((String *)&local_20,*(ushort **)this);
    uVar7 = *(uint *)(this + 4);
    if (uVar7 != 0) {
      uVar3 = 0;
      iVar4 = *(int *)this;
      uVar5 = uVar7 - 1;
      puVar2 = (undefined2 *)((int)local_20 + uVar5 * 2);
      do {
        puVar6 = &termChar;
        if ((int)uVar5 < iStack_1c) {
          puVar6 = puVar2;
        }
        if (0x7fffffff < uVar5) {
          puVar6 = &termChar;
        }
        puVar2 = puVar2 + -1;
        uVar5 = uVar5 - 1;
        *(undefined2 *)(iVar4 + uVar3 * 2) = *puVar6;
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar7);
    }
    if (local_20 != (void *)0x0) {
      operator_delete__(local_20);
    }
  }
  if (__stack_chk_guard == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::String::operator[]  @0x0007b734  (34 bytes)
/* AbyssEngine::String::operator[](int) */

undefined2 * __thiscall AbyssEngine::String::operator[](String *this,int param_1)

{
  if (param_1 < 0) {
    return &termChar;
  }
  if (*(int *)(this + 4) <= param_1) {
    return &termChar;
  }
  return (undefined2 *)(*(int *)this + param_1 * 2);
}

// ===== AbyssEngine::String::String  @0x0007b760  (8 bytes)
/* AbyssEngine::String::String() */

void __thiscall AbyssEngine::String::String(String *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

// ===== AbyssEngine::String::String  @0x0007b768  (32 bytes)
/* AbyssEngine::String::String(unsigned short const*, bool) */

String * __thiscall AbyssEngine::String::String(String *this,ushort *param_1,bool param_2)

{
  *(undefined4 *)this = 0;
  Set(this,param_1);
  if (param_2) {
    Reverse(this);
  }
  return this;
}

// ===== AbyssEngine::String::Set  @0x0007b788  (166 bytes)
/* AbyssEngine::String::Set(unsigned short const*) */

void __thiscall AbyssEngine::String::Set(String *this,ushort *param_1)

{
  uint uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar5;
  void *pvVar6;
  undefined2 *puVar7;
  uint uVar8;
  ushort *puVar4;
  
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  puVar3 = param_1;
  if (param_1 == (ushort *)0x0) {
    *(undefined4 *)(this + 4) = 0;
  }
  else {
    do {
      puVar4 = puVar3 + 1;
      uVar2 = *puVar3;
      puVar3 = puVar4;
    } while (uVar2 != 0);
    uVar1 = (int)puVar4 - (int)param_1 >> 1;
    uVar8 = uVar1 - 1;
    *(uint *)(this + 4) = uVar8;
    if (uVar8 != 0) {
      if (param_1[uVar1 - 2] != 0) {
        uVar5 = uVar1 * 2;
        if (uVar5 < uVar1) {
          uVar5 = 0xffffffff;
        }
        pvVar6 = operator_new__(uVar5);
        *(void **)this = pvVar6;
        __aeabi_memcpy(pvVar6,param_1,uVar8 * 2);
        *(undefined2 *)((int)pvVar6 + uVar8 * 2) = 0;
        return;
      }
      uVar5 = uVar8 * 2;
      if (uVar5 < uVar8) {
        uVar5 = 0xffffffff;
      }
      pvVar6 = operator_new__(uVar5);
      *(void **)this = pvVar6;
      __aeabi_memcpy(pvVar6,param_1,uVar8 * 2);
      *(undefined2 *)((int)pvVar6 + (uVar1 - 2) * 2) = 0;
      *(uint *)(this + 4) = uVar1 - 2;
      return;
    }
  }
  puVar7 = operator_new__(2);
  *(undefined2 **)this = puVar7;
  *puVar7 = 0;
  return;
}

// ===== AbyssEngine::String::String  @0x0007b82e  (32 bytes)
/* AbyssEngine::String::String(char const*, bool) */

String * __thiscall AbyssEngine::String::String(String *this,char *param_1,bool param_2)

{
  *(undefined4 *)this = 0;
  Set(this,param_1);
  if (param_2) {
    Reverse(this);
  }
  return this;
}

// ===== AbyssEngine::String::Set  @0x0007b850  (156 bytes)
/* AbyssEngine::String::Set(char const*) */

void __thiscall AbyssEngine::String::Set(String *this,char *param_1)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 *puVar5;
  char *pcVar6;
  
  pvVar2 = *(void **)this;
  do {
    pcVar6 = param_1;
    if (pvVar2 != (void *)0x0) {
      operator_delete__(pvVar2);
    }
    pvVar2 = (void *)0x0;
    *(undefined4 *)this = 0;
    pcVar4 = pcVar6;
    param_1 = "";
  } while (pcVar6 == (char *)0x0);
  do {
    pcVar3 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while (cVar1 != '\0');
  pcVar3 = pcVar3 + ~(uint)pcVar6;
  *(char **)(this + 4) = pcVar3;
  if (pcVar3 == (char *)0x0) {
    puVar5 = operator_new__(2);
    *(undefined2 **)this = puVar5;
    *puVar5 = 0;
    return;
  }
  if (pcVar6[(int)(pcVar3 + -1)] == '\0') {
    pcVar4 = (char *)((int)pcVar3 * 2);
    if (pcVar4 < pcVar3) {
      pcVar4 = (char *)0xffffffff;
    }
    pvVar2 = operator_new__((uint)pcVar4);
    pcVar4 = (char *)0x0;
    *(void **)this = pvVar2;
    do {
      *(ushort *)((int)pvVar2 + (int)pcVar4 * 2) = (ushort)(byte)pcVar6[(int)pcVar4];
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < pcVar3);
    *(char **)(this + 4) = pcVar3 + -1;
    return;
  }
  pcVar4 = (char *)((int)(pcVar3 + 1) * 2);
  if (pcVar4 < pcVar3 + 1) {
    pcVar4 = (char *)0xffffffff;
  }
  pvVar2 = operator_new__((uint)pcVar4);
  pcVar4 = (char *)0x0;
  *(void **)this = pvVar2;
  do {
    *(ushort *)((int)pvVar2 + (int)pcVar4 * 2) = (ushort)(byte)pcVar6[(int)pcVar4];
    pcVar4 = pcVar4 + 1;
  } while (pcVar4 < pcVar3);
  *(undefined2 *)((int)pvVar2 + (int)pcVar3 * 2) = 0;
  return;
}

// ===== AbyssEngine::String::String  @0x0007b8f0  (34 bytes)
/* AbyssEngine::String::String(AbyssEngine::String const&, bool) */

String * __thiscall AbyssEngine::String::String(String *this,String *param_1,bool param_2)

{
  *(undefined4 *)this = 0;
  Set(this,*(ushort **)param_1);
  if (param_2) {
    Reverse(this);
  }
  return this;
}

// ===== AbyssEngine::String::~String  @0x0007b912  (22 bytes)
/* AbyssEngine::String::~String() */

String * __thiscall AbyssEngine::String::~String(String *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  return this;
}

// ===== AbyssEngine::String::operator.cast.to.unsigned_short*  @0x0007b928  (4 bytes)
/* AbyssEngine::String::operator unsigned short*() */

ushort * __thiscall AbyssEngine::String::operator_cast_to_unsigned_short_(String *this)

{
  return *(ushort **)this;
}

// ===== AbyssEngine::String::operator.cast.to.unsigned_short*  @0x0007b92c  (4 bytes)
/* AbyssEngine::String::operator unsigned short const*() const */

ushort * __thiscall AbyssEngine::String::operator_cast_to_unsigned_short_(String *this)

{
  return *(ushort **)this;
}

// ===== AbyssEngine::String::getWCharFromUtf8  @0x0007b930  (328 bytes)
/* AbyssEngine::String::getWCharFromUtf8(char*, int) */

void AbyssEngine::String::getWCharFromUtf8(char *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  ushort uVar5;
  ushort *puVar7;
  int iVar8;
  ushort uVar6;
  
  iVar8 = 0;
  if (0 < param_2) {
    iVar1 = 0;
    do {
      if ((param_1[iVar1] & 0xe0U) == 0xc0) {
        iVar1 = iVar1 + 1;
      }
      else if ((param_1[iVar1] & 0xf0U) == 0xe0) {
        iVar1 = iVar1 + 2;
      }
      iVar1 = iVar1 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar1 < param_2);
  }
  uVar2 = (iVar8 + 1U) * 2;
  if (uVar2 < iVar8 + 1U) {
    uVar2 = 0xffffffff;
  }
  puVar3 = operator_new__(uVar2);
  if (0 < param_2) {
    iVar1 = 0;
    puVar7 = puVar3;
    do {
      uVar5 = (ushort)(byte)param_1[iVar1];
      uVar6 = (ushort)(byte)param_1[iVar1];
      if ((uVar5 & 0xe0) == 0xc0) {
        uVar6 = (uVar5 & 0x1f) << 6 | (byte)param_1[iVar1 + 1] & 0x3f;
        iVar4 = iVar1 + 1;
      }
      else {
        iVar4 = iVar1;
        if ((uVar5 & 0xf0) == 0xe0) {
          iVar4 = iVar1 + 2;
          uVar6 = (byte)param_1[iVar4] & 0x3f |
                  ((byte)param_1[iVar1 + 1] & 0x3f | (uVar5 & 0xf) << 6) << 6;
        }
      }
      iVar1 = iVar4 + 1;
      *puVar7 = uVar6;
      puVar7 = puVar7 + 1;
    } while (iVar1 < param_2);
  }
  puVar3[iVar8] = 0;
  if (0 < iVar8) {
    do {
      uVar5 = *puVar3;
      if (uVar5 < 0x430) {
        if (uVar5 < 0x410) {
          if (uVar5 == 0x60) {
            uVar5 = 0x27;
          }
          else {
            if (uVar5 == 0xaa) goto LAB_0007ba4c;
            if (uVar5 == 0xba) {
              uVar5 = 0x6f;
            }
          }
        }
        else {
          switch(uVar5) {
          case 0x410:
            uVar5 = 0x41;
            break;
          case 0x412:
            uVar5 = 0x42;
            break;
          case 0x415:
            uVar5 = 0x45;
            break;
          case 0x41a:
            uVar5 = 0x4b;
            break;
          case 0x41c:
            uVar5 = 0x4d;
            break;
          case 0x41d:
            uVar5 = 0x48;
            break;
          case 0x41e:
            uVar5 = 0x4f;
            break;
          case 0x420:
            uVar5 = 0x50;
            break;
          case 0x421:
            uVar5 = 0x43;
            break;
          case 0x422:
            uVar5 = 0x54;
            break;
          case 0x425:
            uVar5 = 0x58;
          }
        }
      }
      else {
        switch(uVar5) {
        case 0x43e:
          uVar5 = 0x6f;
          break;
        case 0x43f:
        case 0x442:
        case 0x443:
        case 0x444:
          break;
        case 0x440:
          uVar5 = 0x70;
          break;
        case 0x441:
          uVar5 = 99;
          break;
        case 0x445:
          uVar5 = 0x78;
          break;
        default:
          if (uVar5 == 0x430) {
LAB_0007ba4c:
            uVar5 = 0x61;
          }
          else if (uVar5 == 0x435) {
            uVar5 = 0x65;
          }
        }
      }
      *puVar3 = uVar5;
      iVar8 = iVar8 + -1;
      puVar3 = puVar3 + 1;
    } while (iVar8 != 0);
  }
  return;
}

// ===== AbyssEngine::String::ConvertFromUTF8  @0x0007ba98  (64 bytes)
/* AbyssEngine::String::ConvertFromUTF8() */

void __thiscall AbyssEngine::String::ConvertFromUTF8(String *this)

{
  void *pvVar1;
  char *pcVar2;
  ushort *puVar3;
  
  if (*(int *)this == 0) {
    return;
  }
  pvVar1 = (void *)GetAEChar(this);
  pcVar2 = (char *)GetAEChar(this);
  puVar3 = (ushort *)getWCharFromUtf8(pcVar2,*(int *)(this + 4));
  Set(this,puVar3);
  operator_delete__(pvVar1);
  operator_delete__(puVar3);
  return;
}

// ===== AbyssEngine::String::GetAEChar  @0x0007bad8  (58 bytes)
/* AbyssEngine::String::GetAEChar() const */

void __thiscall AbyssEngine::String::GetAEChar(String *this)

{
  void *pvVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(this + 4);
  if (iVar5 == 0) {
    puVar2 = operator_new__(1);
    *puVar2 = 0;
  }
  else {
    pvVar1 = operator_new__(iVar5 + 1U);
    if (iVar5 != -1) {
      iVar3 = *(int *)this;
      uVar4 = 0;
      do {
        *(undefined1 *)((int)pvVar1 + uVar4) = *(undefined1 *)(iVar3 + uVar4 * 2);
        uVar4 = uVar4 + 1;
      } while (uVar4 < iVar5 + 1U);
    }
  }
  return;
}

// ===== AbyssEngine::String::GetAEWChar  @0x0007bb12  (4 bytes)
/* AbyssEngine::String::GetAEWChar() const */

undefined4 __thiscall AbyssEngine::String::GetAEWChar(String *this)

{
  return *(undefined4 *)this;
}

// ===== AbyssEngine::String::operator[]  @0x0007bb18  (34 bytes)
/* AbyssEngine::String::operator[](int) const */

undefined2 * __thiscall AbyssEngine::String::operator[](String *this,int param_1)

{
  if (param_1 < 0) {
    return &termChar;
  }
  if (*(int *)(this + 4) <= param_1) {
    return &termChar;
  }
  return (undefined2 *)(*(int *)this + param_1 * 2);
}

// ===== AbyssEngine::String::operator=  @0x0007bb44  (20 bytes)
/* AbyssEngine::String::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&) */

String * __thiscall AbyssEngine::String::operator=(String *this,String *param_1)

{
  if (*(ushort **)param_1 != (ushort *)0x0) {
    Set(this,*(ushort **)param_1);
  }
  return this;
}

// ===== AbyssEngine::String::ValueOf  @0x0007bb58  (26 bytes)
/* AbyssEngine::String::ValueOf() */

int __thiscall AbyssEngine::String::ValueOf(String *this)

{
  char *__nptr;
  int iVar1;
  
  __nptr = (char *)GetAEChar(this);
  iVar1 = atoi(__nptr);
  operator_delete__(__nptr);
  return iVar1;
}

// ===== AbyssEngine::String::operator+=  @0x0007bb74  (126 bytes)
/* AbyssEngine::String::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&) */

void __thiscall AbyssEngine::String::operator+=(String *this,String *param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void *local_28;
  int local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (*(int *)(param_1 + 4) != 0) {
    local_28 = (void *)0x0;
    Set((String *)&local_28,*(ushort **)param_1);
    iVar4 = *(int *)(this + 4);
    iVar3 = local_24 + iVar4;
    *(int *)(this + 4) = iVar3;
    pvVar2 = realloc(*(void **)this,iVar3 * 2 + 2);
    pvVar1 = local_28;
    *(void **)this = pvVar2;
    __aeabi_memcpy((void *)((int)pvVar2 + iVar4 * 2),local_28,local_24 << 1);
    *(undefined2 *)((int)pvVar2 + *(int *)(this + 4) * 2) = 0;
    if (pvVar1 != (void *)0x0) {
      operator_delete__(pvVar1);
    }
  }
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== AbyssEngine::String::operator+=  @0x0007bbfc  (74 bytes)
/* AbyssEngine::String::TEMPNAMEPLACEHOLDERVALUE(char const&) */

String * __thiscall AbyssEngine::String::operator+=(String *this,char *param_1)

{
  void *pvVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 4);
  if (iVar3 == 0) {
    puVar2 = operator_new__(4);
    *(ushort **)this = puVar2;
    *puVar2 = (ushort)(byte)*param_1;
    puVar2[1] = 0;
    *(undefined4 *)(this + 4) = 1;
  }
  else {
    *(int *)(this + 4) = iVar3 + 1;
    pvVar1 = realloc(*(void **)this,iVar3 * 2 + 4);
    *(void **)this = pvVar1;
    iVar3 = *(int *)(this + 4);
    *(ushort *)((int)pvVar1 + iVar3 * 2 + -2) = (ushort)(byte)*param_1;
    *(undefined2 *)((int)pvVar1 + iVar3 * 2) = 0;
  }
  return this;
}

// ===== AbyssEngine::String::operator+=  @0x0007bc48  (106 bytes)
/* AbyssEngine::String::TEMPNAMEPLACEHOLDERVALUE(long long const&) */

void __thiscall AbyssEngine::String::operator+=(String *this,longlong *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *local_20;
  int local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_20 = (void *)0x0;
  Set(CONCAT44(param_1,&local_20));
  pvVar4 = local_20;
  if (local_1c != 0) {
    iVar3 = *(int *)(this + 4);
    iVar2 = iVar3 + local_1c;
    *(int *)(this + 4) = iVar2;
    pvVar1 = realloc(*(void **)this,iVar2 * 2 + 2);
    pvVar4 = local_20;
    *(void **)this = pvVar1;
    __aeabi_memcpy((void *)((int)pvVar1 + iVar3 * 2),local_20,local_1c << 1);
  }
  if (pvVar4 != (void *)0x0) {
    operator_delete__(pvVar4);
  }
  if (__stack_chk_guard - local_18 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_18);
}

// ===== AbyssEngine::String::operator+=  @0x0007bcbc  (52 bytes)
/* AbyssEngine::String::TEMPNAMEPLACEHOLDERVALUE(int const&) */

void __thiscall AbyssEngine::String::operator+=(String *this,int *param_1)

{
  int local_18;
  int local_14;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_18 = *param_1;
  local_14 = local_18 >> 0x1f;
  operator+=(this,(longlong *)&local_18);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::String::operator+=  @0x0007bcf8  (104 bytes)
/* WARNING: Removing unreachable block (ram,0x0007bd42) */
/* AbyssEngine::String::TEMPNAMEPLACEHOLDERVALUE(float const&) */

void __thiscall AbyssEngine::String::operator+=(String *this,float *param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  float in_s0;
  int local_1c;
  
  iVar1 = __stack_chk_guard;
  Set(in_s0);
  if (local_1c != 0) {
    iVar4 = *(int *)(this + 4);
    iVar3 = iVar4 + local_1c;
    *(int *)(this + 4) = iVar3;
    pvVar2 = realloc(*(void **)this,iVar3 * 2 + 2);
    *(void **)this = pvVar2;
    __aeabi_memcpy((void *)((int)pvVar2 + iVar4 * 2),0,local_1c << 1);
  }
  if (__stack_chk_guard - iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - iVar1);
  }
  return;
}

// ===== AbyssEngine::String::StrLen  @0x0007bd68  (16 bytes)
/* AbyssEngine::String::StrLen(char const*) */

char * __thiscall AbyssEngine::String::StrLen(String *this,char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = param_1;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return pcVar2 + ~(uint)param_1;
}

// ===== AbyssEngine::String::StrLen  @0x0007bd78  (28 bytes)
/* AbyssEngine::String::StrLen(unsigned short const*) */

int __thiscall AbyssEngine::String::StrLen(String *this,ushort *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  puVar2 = param_1;
  if (param_1 == (ushort *)0x0) {
    return 0;
  }
  do {
    puVar3 = puVar2 + 1;
    uVar1 = *puVar2;
    puVar2 = puVar3;
  } while (uVar1 != 0);
  return ((int)puVar3 - (int)param_1 >> 1) + -1;
}

// ===== AbyssEngine::String::Set  @0x0007bd94  (192 bytes)
/* AbyssEngine::String::Set(long long) */

void AbyssEngine::String::Set(longlong param_1)

{
  undefined4 *puVar1;
  ushort *puVar2;
  ushort uVar3;
  int in_r2;
  uint extraout_r2;
  int in_r3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined8 uVar11;
  uint local_28;
  
  puVar1 = (undefined4 *)param_1;
  if ((void *)*puVar1 != (void *)0x0) {
    operator_delete__((void *)*puVar1);
  }
  puVar2 = operator_new__(0x28);
  *puVar1 = puVar2;
  puVar1[1] = 0;
  if (in_r3 < 0) {
    puVar7 = puVar2 + 1;
    *puVar2 = 0x2d;
    bVar10 = in_r2 != 0;
    in_r2 = -in_r2;
    puVar1[1] = 1;
    iVar4 = -(uint)bVar10 - in_r3;
  }
  else {
    iVar4 = 0;
    puVar7 = puVar2;
  }
  uVar11 = CONCAT44(iVar4,in_r2);
  local_28 = (uint)(in_r3 < 0);
  puVar2 = puVar7 + -3;
  iVar4 = 0;
  do {
    iVar8 = iVar4;
    puVar6 = puVar2;
    iVar5 = (int)((ulonglong)uVar11 >> 0x20);
    uVar9 = (uint)uVar11;
    uVar11 = __aeabi_uldivmod(uVar9,iVar5,10,0);
    if (extraout_r2 < 10) {
      uVar3 = (ushort)extraout_r2 & 0x3f | 0x30;
    }
    else {
      uVar3 = (ushort)extraout_r2 + 0x57;
    }
    iVar4 = iVar8 + 1;
    puVar6[3] = uVar3;
    puVar2 = puVar6 + 1;
  } while ((uint)(uVar9 < 10) <= (uint)-iVar5);
  puVar1[1] = local_28 + iVar4;
  puVar6[4] = 0;
  puVar6[3] = *puVar7;
  *puVar7 = uVar3;
  if (1 < iVar8 + -1) {
    puVar2 = puVar7 + 1;
    puVar7 = puVar6 + 1;
    do {
      uVar3 = puVar7[1];
      puVar7[1] = *puVar2;
      *puVar2 = uVar3;
      bVar10 = puVar2 + 1 < puVar7;
      puVar2 = puVar2 + 1;
      puVar7 = puVar7 + -1;
    } while (bVar10);
  }
  return;
}

// ===== AbyssEngine::String::Set  @0x0007c030  (378 bytes)
/* AbyssEngine::String::Set(float) */

void AbyssEngine::String::Set(float param_1)

{
  ushort *puVar1;
  String *in_r0;
  ushort *puVar2;
  int in_r1;
  int iVar3;
  void *local_60 [2];
  void *local_58 [2];
  void *local_50 [2];
  void *local_48 [2];
  ushort *local_40 [2];
  ushort *local_38;
  undefined4 local_34;
  int local_30;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar2 = (ushort *)computeFloatString(param_1,in_r1,(int *)0xa,(int *)&local_2c,(int)&local_30);
  local_38 = (ushort *)0x0;
  local_34 = 0;
  if (((int)local_2c < 1) && (Set((String *)&local_38,"0."), 0x7fffffff < local_2c)) {
    iVar3 = 0;
    do {
      local_40[0] = (ushort *)0x0;
      Set((String *)local_40,"0");
      operator+=((String *)&local_38,(String *)local_40);
      if (local_40[0] != (ushort *)0x0) {
        operator_delete__(local_40[0]);
      }
      iVar3 = iVar3 + -1;
    } while ((int)local_2c < iVar3);
  }
  local_40[0] = (ushort *)0x0;
  Set((String *)local_40,puVar2);
  operator+=((String *)&local_38,(String *)local_40);
  if (local_40[0] != (ushort *)0x0) {
    operator_delete__(local_40[0]);
  }
  if (0 < (int)local_2c) {
    SubString((uint)local_50,(uint)&local_38);
    local_58[0] = (void *)0x0;
    Set((String *)local_58,".");
    operator+((AbyssEngine *)local_48,(String *)local_50,(String *)local_58);
    SubString((uint)local_60,(uint)&local_38);
    operator+((AbyssEngine *)local_40,(String *)local_48,(String *)local_60);
    puVar1 = local_40[0];
    if (local_40[0] != (ushort *)0x0) {
      Set((String *)&local_38,local_40[0]);
      operator_delete__(puVar1);
    }
    local_40[0] = (ushort *)0x0;
    if (local_60[0] != (void *)0x0) {
      operator_delete__(local_60[0]);
    }
    if (local_48[0] != (void *)0x0) {
      operator_delete__(local_48[0]);
    }
    local_48[0] = (void *)0x0;
    if (local_58[0] != (void *)0x0) {
      operator_delete__(local_58[0]);
    }
    if (local_50[0] != (void *)0x0) {
      operator_delete__(local_50[0]);
    }
  }
  if (local_30 != 0) {
    local_48[0] = (void *)0x0;
    Set((String *)local_48,"-");
    operator+((AbyssEngine *)local_40,(String *)local_48,(String *)&local_38);
    puVar1 = local_40[0];
    if (local_40[0] != (ushort *)0x0) {
      Set((String *)&local_38,local_40[0]);
      operator_delete__(puVar1);
    }
    local_40[0] = (ushort *)0x0;
    if (local_48[0] != (void *)0x0) {
      operator_delete__(local_48[0]);
    }
  }
  operator_delete__(puVar2);
  Set(in_r0,local_38);
  if (local_38 != (ushort *)0x0) {
    operator_delete__(local_38);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::String::SubString  @0x0007c2cc  (100 bytes)
/* AbyssEngine::String::SubString(unsigned int, unsigned int) */

void AbyssEngine::String::SubString(uint param_1,uint param_2)

{
  uint uVar1;
  ushort *puVar2;
  uint in_r2;
  uint in_r3;
  int iVar3;
  
  if (in_r2 < in_r3) {
    iVar3 = in_r3 - in_r2;
    uVar1 = (iVar3 + 1U) * 2;
    if (uVar1 < iVar3 + 1U) {
      uVar1 = 0xffffffff;
    }
    puVar2 = operator_new__(uVar1);
    __aeabi_memcpy(puVar2,*(int *)param_2 + in_r2 * 2,iVar3 * 2);
    puVar2[iVar3] = 0;
    *(undefined4 *)param_1 = 0;
    Set((String *)param_1,puVar2);
    operator_delete__(puVar2);
    return;
  }
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}

// ===== AbyssEngine::String::Compare  @0x0007c33e  (96 bytes)
/* AbyssEngine::String::Compare(AbyssEngine::String const&) */

int __thiscall AbyssEngine::String::Compare(String *this,String *param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 4) == *(int *)(this + 4)) {
    sVar1 = **(short **)this;
    if (sVar1 == 0) {
      sVar1 = 0;
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      do {
        if (*(short *)(*(int *)param_1 + iVar3 * 2) != sVar1) goto LAB_0007c378;
        sVar1 = (*(short **)this)[iVar3 + 1];
        iVar3 = iVar3 + 1;
      } while (sVar1 != 0);
      sVar1 = 0;
    }
LAB_0007c378:
    sVar2 = *(short *)(*(int *)param_1 + iVar3 * 2);
    if (sVar2 == 0) {
      sVar2 = sVar1;
      if (sVar1 != 0) {
        sVar2 = 1;
      }
    }
    else {
      sVar2 = sVar1 - sVar2;
      if (sVar1 == 0) {
        sVar2 = -1;
      }
    }
  }
  else {
    sVar2 = 0xff;
  }
  return (int)(char)sVar2;
}

// ===== AbyssEngine::String::Compare  @0x0007c39e  (102 bytes)
/* AbyssEngine::String::Compare(char const*) */

int __thiscall AbyssEngine::String::Compare(String *this,char *param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  
  if (*(int *)(this + 4) == 0) {
    cVar1 = '\x01';
  }
  else {
    uVar4 = **(ushort **)this;
    if (uVar4 == 0) {
      uVar4 = 0;
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      do {
        if (((byte)param_1[iVar3] == 0) || ((byte)param_1[iVar3] != uVar4)) goto LAB_0007c3de;
        uVar4 = (*(ushort **)this)[iVar3 + 1];
        iVar3 = iVar3 + 1;
      } while (uVar4 != 0);
      uVar4 = 0;
    }
LAB_0007c3de:
    if ((byte)param_1[iVar3] == 0) {
      uVar2 = uVar4;
      if (uVar4 != 0) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = uVar4 - (byte)param_1[iVar3];
      if (uVar4 == 0) {
        uVar2 = 0xffff;
      }
    }
    cVar1 = (char)uVar2;
  }
  return (int)cVar1;
}

// ===== AbyssEngine::String::IndexOf  @0x0007c404  (94 bytes)
/* AbyssEngine::String::IndexOf(unsigned int, AbyssEngine::String const&) */

uint __thiscall AbyssEngine::String::IndexOf(String *this,uint param_1,String *param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(this + 4);
  if (param_1 < uVar7) {
    do {
      if (uVar7 - param_1 < *(uint *)(param_2 + 4)) {
        return 0xffffffff;
      }
      iVar4 = *(int *)this;
      sVar2 = **(short **)param_2;
      if (sVar2 == *(short *)(iVar4 + param_1 * 2)) {
        if (sVar2 == *(short *)(iVar4 + param_1 * 2)) {
          uVar5 = 0;
          do {
            uVar6 = uVar5 + 1;
            if (*(uint *)(param_2 + 4) <= uVar6) {
              return param_1;
            }
            iVar1 = uVar5 * 2;
            iVar3 = uVar5 + 1;
            uVar5 = uVar6;
          } while ((*(short **)param_2)[iVar3] == *(short *)(iVar4 + param_1 * 2 + 2 + iVar1));
          param_1 = param_1 + uVar6;
        }
      }
      else {
        param_1 = param_1 + 1;
      }
    } while (param_1 < uVar7);
  }
  return 0xffffffff;
}

// ===== AbyssEngine::String::IndexOf  @0x0007c462  (10 bytes)
/* AbyssEngine::String::IndexOf(AbyssEngine::String const&) */

void __thiscall AbyssEngine::String::IndexOf(String *this,String *param_1)

{
  IndexOf(this,0,param_1);
  return;
}

// ===== AbyssEngine::String::ReplaceChar  @0x0007c46a  (48 bytes)
/* AbyssEngine::String::ReplaceChar(char, char) */

void __thiscall AbyssEngine::String::ReplaceChar(String *this,char param_1,char param_2)

{
  uint uVar1;
  uint in_r12;
  int iVar2;
  
  iVar2 = *(int *)this;
  if (iVar2 != 0) {
    in_r12 = *(uint *)(this + 4);
  }
  if (iVar2 != 0 && in_r12 != 0) {
    uVar1 = 0;
    do {
      if ((uint)*(ushort *)(iVar2 + uVar1 * 2) == (int)param_1) {
        *(short *)(iVar2 + uVar1 * 2) = (short)param_2;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < in_r12);
    return;
  }
  return;
}

// ===== AbyssEngine::String::ToUpperCase  @0x0007c49c  (146 bytes)
/* AbyssEngine::String::ToUpperCase() */

void __thiscall AbyssEngine::String::ToUpperCase(String *this)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  ushort uVar6;
  bool bVar7;
  bool bVar8;
  
  iVar2 = *(int *)this;
  if ((iVar2 != 0) && (uVar3 = *(uint *)(this + 4), uVar3 != 0)) {
    uVar4 = 0;
    do {
      uVar1 = *(ushort *)(iVar2 + uVar4 * 2);
      uVar6 = uVar1 - 0x61;
      bVar8 = 0x19 < uVar6;
      bVar7 = uVar6 == 0x1a;
      if (bVar8) {
        uVar6 = uVar1 - 0xe0;
        bVar7 = uVar6 == 0x1e;
      }
      if ((!bVar8 || uVar6 < 0x1e) || bVar7) {
        sVar5 = uVar1 - 0x20;
        goto LAB_0007c526;
      }
      if (0x90 < uVar1) {
        if (uVar1 == 0x91) {
          *(undefined2 *)(iVar2 + uVar4 * 2) = 0x92;
        }
        else {
          if (uVar1 == 0x94) {
            sVar5 = 0x99;
            goto LAB_0007c526;
          }
          if (uVar1 == 0xa4) {
            *(undefined2 *)(iVar2 + uVar4 * 2) = 0xa5;
          }
        }
        goto switchD_0007c4ce_caseD_83;
      }
      switch(uVar1) {
      case 0x81:
        sVar5 = 0x9a;
        goto LAB_0007c526;
      case 0x82:
        sVar5 = 0x90;
LAB_0007c526:
        *(short *)(iVar2 + uVar4 * 2) = sVar5;
        break;
      case 0x84:
        *(undefined2 *)(iVar2 + uVar4 * 2) = 0x8e;
        break;
      case 0x86:
        *(undefined2 *)(iVar2 + uVar4 * 2) = 0x8f;
      }
switchD_0007c4ce_caseD_83:
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return;
}

// ===== AbyssEngine::String::ToLowerCase  @0x0007c534  (140 bytes)
/* AbyssEngine::String::ToLowerCase() */

void __thiscall AbyssEngine::String::ToLowerCase(String *this)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  uint uVar8;
  bool bVar9;
  
  iVar2 = *(int *)this;
  if ((iVar2 != 0) && (uVar3 = *(uint *)(this + 4), uVar3 != 0)) {
    uVar4 = 0;
    do {
      uVar1 = *(ushort *)(iVar2 + uVar4 * 2);
      uVar6 = (uint)uVar1;
      uVar8 = uVar6 + 0xff40;
      uVar5 = uVar6 + 0xffbf & 0xffff;
      bVar9 = uVar5 == 0x1a;
      if (0x19 < uVar5) {
        uVar8 = uVar8 & 0xffff;
        bVar9 = uVar8 == 0x1e;
      }
      if ((0x19 < uVar5 && 0x1d < uVar8) && !bVar9) {
        switch(uVar6) {
        case 0x8e:
          sVar7 = 0x84;
          goto LAB_0007c5c0;
        case 0x8f:
          *(undefined2 *)(iVar2 + uVar4 * 2) = 0x86;
          break;
        case 0x90:
          *(undefined2 *)(iVar2 + uVar4 * 2) = 0x82;
          break;
        case 0x91:
        case 0x93:
        case 0x94:
        case 0x95:
        case 0x96:
        case 0x97:
        case 0x98:
          break;
        case 0x92:
          *(undefined2 *)(iVar2 + uVar4 * 2) = 0x91;
          break;
        case 0x99:
          *(undefined2 *)(iVar2 + uVar4 * 2) = 0x94;
          break;
        case 0x9a:
          *(undefined2 *)(iVar2 + uVar4 * 2) = 0x81;
          break;
        default:
          if (uVar6 == 0xa5) {
            sVar7 = 0xa4;
            goto LAB_0007c5c0;
          }
        }
      }
      else {
        sVar7 = uVar1 + 0x20;
LAB_0007c5c0:
        *(short *)(iVar2 + uVar4 * 2) = sVar7;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return;
}

// ===== AbyssEngine::String::Trim  @0x0007c5d0  (118 bytes)
/* AbyssEngine::String::Trim() */

void __thiscall AbyssEngine::String::Trim(String *this)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort *local_1c [2];
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar3 = *(int *)this;
  if ((iVar3 != 0) && (uVar2 = *(uint *)(this + 4), uVar2 != 0)) {
    uVar4 = 0;
    do {
      sVar1 = *(short *)(iVar3 + uVar4 * 2);
      if (sVar1 != 0x20 && sVar1 != 9) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
    do {
      do {
        uVar4 = uVar2 - 1;
        sVar1 = *(short *)(iVar3 + -2 + uVar2 * 2);
        uVar2 = uVar4;
      } while (sVar1 == 9);
    } while (sVar1 == 0x20);
    SubString((uint)local_1c,(uint)this);
    Set(this,local_1c[0]);
    if (local_1c[0] != (ushort *)0x0) {
      operator_delete__(local_1c[0]);
    }
    local_1c[0] = (ushort *)0x0;
  }
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== AbyssEngine::String::Split  @0x0007c660  (336 bytes)
/* AbyssEngine::String::Split(AbyssEngine::String) */

int * __thiscall AbyssEngine::String::Split(String *this,String *param_2)

{
  int *piVar1;
  undefined4 *__ptr;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int local_28;
  
  if (((*(int *)this != 0) && (*(int *)(this + 4) != 0)) &&
     (iVar4 = *(int *)(param_2 + 4), iVar4 != 0)) {
    piVar1 = operator_new(0xc);
    __ptr = operator_new__(4);
    piVar1[1] = (int)__ptr;
    piVar1[2] = 1;
    *__ptr = 0;
    *piVar1 = 0;
    uVar2 = IndexOf(this,0,param_2);
    if (uVar2 != 0xffffffff) {
      uVar5 = 0;
      local_28 = 0;
      do {
        if (uVar5 < uVar2) {
          pvVar3 = operator_new(8);
          SubString((uint)pvVar3,(uint)this);
          piVar1[2] = *piVar1 + 1;
          __ptr = realloc((void *)piVar1[1],(*piVar1 + 1) * 4);
          piVar1[1] = (int)__ptr;
          iVar4 = *piVar1;
          local_28 = piVar1[2];
          *piVar1 = local_28;
          __ptr[iVar4] = pvVar3;
          iVar4 = *(int *)(param_2 + 4);
        }
        uVar5 = iVar4 + uVar2;
        uVar2 = IndexOf(this,uVar5,param_2);
      } while (uVar2 != 0xffffffff);
      if ((uVar5 != 0) && (uVar5 < *(uint *)(this + 4))) {
        pvVar3 = operator_new(8);
        SubString((uint)pvVar3,(uint)this);
        piVar1[2] = *piVar1 + 1;
        __ptr = realloc((void *)piVar1[1],(*piVar1 + 1) * 4);
        piVar1[1] = (int)__ptr;
        __ptr[*piVar1] = pvVar3;
        local_28 = piVar1[2];
        *piVar1 = local_28;
      }
      if (local_28 != 0) {
        return piVar1;
      }
    }
    *piVar1 = 0;
    piVar1[2] = 1;
    pvVar3 = realloc(__ptr,4);
    piVar1[1] = (int)pvVar3;
    __aeabi_memclr4(pvVar3,piVar1[2] << 2);
    if (pvVar3 != (void *)0x0) {
      operator_delete__(pvVar3);
    }
    operator_delete(piVar1);
  }
  return (int *)0x0;
}

// ===== AbyssEngine::String::SplitTags  @0x0007c7c8  (522 bytes)
/* AbyssEngine::String::SplitTags(AbyssEngine::String) */

void __thiscall AbyssEngine::String::SplitTags(String *this,String *param_2)

{
  int *piVar1;
  undefined4 *__ptr;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  void *local_48 [2];
  void *local_40 [2];
  void *local_38 [2];
  ushort *local_30 [2];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (((*(int *)this != 0) && (*(int *)(this + 4) != 0)) && (*(int *)(param_2 + 4) != 0)) {
    local_40[0] = (void *)0x0;
    Set((String *)local_40,"<");
    operator+((AbyssEngine *)local_38,(String *)local_40,param_2);
    local_48[0] = (void *)0x0;
    Set((String *)local_48,":");
    operator+((AbyssEngine *)local_30,(String *)local_38,(String *)local_48);
    if (local_30[0] != (ushort *)0x0) {
      Set(param_2,local_30[0]);
      operator_delete__(local_30[0]);
    }
    local_30[0] = (ushort *)0x0;
    if (local_48[0] != (void *)0x0) {
      operator_delete__(local_48[0]);
    }
    if (local_38[0] != (void *)0x0) {
      operator_delete__(local_38[0]);
    }
    local_38[0] = (void *)0x0;
    if (local_40[0] != (void *)0x0) {
      operator_delete__(local_40[0]);
    }
    piVar1 = operator_new(0xc);
    __ptr = operator_new__(4);
    piVar1[1] = (int)__ptr;
    piVar1[2] = 1;
    *__ptr = 0;
    *piVar1 = 0;
    uVar2 = IndexOf(this,0,param_2);
    if (uVar2 != 0xffffffff) {
      iVar5 = 0;
      uVar7 = 0;
      iVar6 = 0;
      do {
        if (uVar7 <= uVar2) {
          pvVar3 = operator_new(8);
          SubString((uint)pvVar3,(uint)this);
          piVar1[2] = *piVar1 + 1;
          pvVar4 = realloc((void *)piVar1[1],(*piVar1 + 1) * 4);
          piVar1[1] = (int)pvVar4;
          *(void **)((int)pvVar4 + *piVar1 * 4) = pvVar3;
          *piVar1 = piVar1[2];
          iVar6 = *(int *)(param_2 + 4);
          local_30[0] = (ushort *)0x0;
          Set((String *)local_30,">");
          iVar6 = IndexOf(this,iVar6 + uVar2,(String *)local_30);
          if (local_30[0] != (ushort *)0x0) {
            operator_delete__(local_30[0]);
          }
          if (iVar6 == -1) goto LAB_0007c9b8;
          pvVar3 = operator_new(8);
          SubString((uint)pvVar3,(uint)this);
          piVar1[2] = *piVar1 + 1;
          __ptr = realloc((void *)piVar1[1],(*piVar1 + 1) * 4);
          piVar1[1] = (int)__ptr;
          __ptr[*piVar1] = pvVar3;
          iVar5 = piVar1[2];
          *piVar1 = iVar5;
        }
        uVar7 = iVar6 + 1;
        uVar2 = IndexOf(this,uVar7,param_2);
      } while (uVar2 != 0xffffffff);
      if ((uVar7 != 0) && (uVar7 < *(uint *)(this + 4))) {
        pvVar3 = operator_new(8);
        SubString((uint)pvVar3,(uint)this);
        piVar1[2] = *piVar1 + 1;
        __ptr = realloc((void *)piVar1[1],(*piVar1 + 1) * 4);
        piVar1[1] = (int)__ptr;
        __ptr[*piVar1] = pvVar3;
        iVar5 = piVar1[2];
        *piVar1 = iVar5;
      }
      if (iVar5 != 0) goto LAB_0007c9b8;
    }
    *piVar1 = 0;
    piVar1[2] = 1;
    pvVar3 = realloc(__ptr,4);
    piVar1[1] = (int)pvVar3;
    __aeabi_memclr4(pvVar3,piVar1[2] << 2);
    if (pvVar3 != (void *)0x0) {
      operator_delete__(pvVar3);
    }
    operator_delete(piVar1);
  }
LAB_0007c9b8:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== AbyssEngine::String::ReplaceString  @0x0007ca38  (232 bytes)
/* AbyssEngine::String::ReplaceString(AbyssEngine::String, AbyssEngine::String) */

void __thiscall AbyssEngine::String::ReplaceString(String *this,String *param_2,String *param_3)

{
  int iVar1;
  uint uVar2;
  void *local_40 [2];
  void *local_38 [2];
  ushort *local_30;
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (((*(int *)this != 0) && (*(int *)(this + 4) != 0)) && (*(int *)(param_2 + 4) != 0)) {
    local_30 = (ushort *)0x0;
    local_2c = 0;
    iVar1 = IndexOf(this,0,param_2);
    if (iVar1 != -1) {
      do {
        SubString((uint)local_40,(uint)this);
        operator+((AbyssEngine *)local_38,(String *)local_40,param_3);
        operator+=((String *)&local_30,(AbyssEngine *)local_38);
        if (local_38[0] != (void *)0x0) {
          operator_delete__(local_38[0]);
        }
        local_38[0] = (void *)0x0;
        if (local_40[0] != (void *)0x0) {
          operator_delete__(local_40[0]);
        }
        uVar2 = *(int *)(param_2 + 4) + iVar1;
        iVar1 = IndexOf(this,uVar2,param_2);
      } while (iVar1 != -1);
      if ((uVar2 != 0) && (uVar2 < *(uint *)(this + 4))) {
        SubString((uint)local_38,(uint)this);
        operator+=((String *)&local_30,(String *)local_38);
        if (local_38[0] != (void *)0x0) {
          operator_delete__(local_38[0]);
        }
      }
      if (local_2c != 0) {
        Set(this,local_30);
      }
    }
    if (local_30 != (ushort *)0x0) {
      operator_delete__(local_30);
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::String::GetStringLength  @0x0007cb6c  (16 bytes)
/* AbyssEngine::String::GetStringLength(char const*) */

char * AbyssEngine::String::GetStringLength(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = param_1;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return pcVar2 + ~(uint)param_1;
}

// ===== AbyssEngine::String::PrintOut  @0x0007cb7c  (16 bytes)
/* AbyssEngine::String::PrintOut() */

void __thiscall AbyssEngine::String::PrintOut(String *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)GetAEChar(this);
  operator_delete__(pvVar1);
  return;
}

