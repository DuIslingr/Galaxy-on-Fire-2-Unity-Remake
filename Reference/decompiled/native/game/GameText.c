// Class: GameText
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== GameText::getRegionCode  @0x00089560  (16 bytes)
/* GameText::getRegionCode() */

void __thiscall GameText::getRegionCode(GameText *this)

{
  AbyssEngine::String::String((String *)this,"gb",false);
  return;
}

// ===== GameText::convertStringFromArabic  @0x00089574  (766 bytes)
/* GameText::convertStringFromArabic(AbyssEngine::String) */

void GameText::convertStringFromArabic(String *param_1,undefined4 param_2,String *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  String aSStack_48 [8];
  String aSStack_40 [4];
  int local_3c;
  String aSStack_38 [8];
  String aSStack_30 [4];
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_30,param_3,false);
  uVar3 = (local_2c + 1U) * 2;
  if (uVar3 < local_2c + 1U) {
    uVar3 = 0xffffffff;
  }
  puVar4 = operator_new__(uVar3);
  puVar5 = AbyssEngine::String::operator_cast_to_unsigned_short_(aSStack_30);
  __aeabi_memcpy(puVar4,puVar5,local_2c * 2 + 2);
  iVar13 = *(int *)(param_3 + 4);
  if (iVar13 < 1) {
LAB_00089848:
    AbyssEngine::String::String(param_1,puVar4,false);
    if (puVar4 != (ushort *)0x0) {
      operator_delete__(puVar4);
    }
    AbyssEngine::String::~String(aSStack_30);
    if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  iVar12 = iVar13 + -1;
  iVar7 = iVar12;
LAB_000895f0:
  if (iVar7 == 0) {
    iVar11 = 0;
  }
  else {
    puVar5 = (ushort *)AbyssEngine::String::operator[](param_3,iVar7 + -1);
    uVar1 = *puVar5;
    puVar6 = (undefined2 *)AbyssEngine::String::operator[](param_3,iVar7);
    iVar11 = iVar7;
    if (uVar1 == 0x644) {
      switch(*puVar6) {
      case 0x622:
        uVar2 = 5;
        break;
      case 0x623:
        uVar2 = 3;
        break;
      default:
        goto switchD_0008961a_caseD_624;
      case 0x625:
        uVar2 = 4;
        break;
      case 0x627:
        uVar2 = 2;
      }
      puVar4[iVar7] = uVar2;
      AbyssEngine::String::String(aSStack_38,puVar4,false);
      AbyssEngine::String::SubString((uint)aSStack_40,(uint)aSStack_38);
      AbyssEngine::String::SubString((uint)aSStack_48,(uint)aSStack_38);
      AbyssEngine::String::operator+=(aSStack_40,aSStack_48);
      AbyssEngine::String::~String(aSStack_48);
      operator_delete__(puVar4);
      uVar3 = (local_3c + 1U) * 2;
      if (uVar3 < local_3c + 1U) {
        uVar3 = 0xffffffff;
      }
      puVar4 = operator_new__(uVar3);
      puVar5 = AbyssEngine::String::operator_cast_to_unsigned_short_(aSStack_40);
      __aeabi_memcpy(puVar4,puVar5,local_3c * 2 + 2);
      AbyssEngine::String::~String(aSStack_40);
      AbyssEngine::String::~String(aSStack_38);
      iVar11 = iVar7 + -1;
    }
switchD_0008961a_caseD_624:
    iVar7 = 0;
    do {
      if ((uint)uVar1 == (&DAT_002229f0)[iVar7]) {
        iVar7 = 0;
        puVar8 = (undefined4 *)&UNK_00222a28;
        goto LAB_00089802;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 10);
  }
  uVar3 = (uint)puVar4[iVar11];
  iVar7 = iVar11 + -1;
  iVar10 = 0;
  do {
    if ((uVar3 & 0xffff) == *(uint *)((int)&DAT_00222a18 + iVar10)) {
      if (iVar11 == 0) {
        if ((iVar13 != 1) && (uVar1 = puVar4[1], 0x5ff < uVar1)) {
          uVar2 = 0x61f;
          if (uVar1 != 0x61f) {
            uVar2 = 0x60c;
          }
          if (uVar1 != 0x61f && uVar1 != uVar2) {
LAB_00089712:
            uVar3 = *(uint *)(&UNK_00222a28 + iVar10);
            goto LAB_000897da;
          }
        }
LAB_000897d8:
        uVar3 = *(uint *)((int)&DAT_00222a1c + iVar10);
      }
      else {
        if (iVar12 <= iVar11) {
          uVar1 = puVar4[iVar7];
          if (0x5ff < uVar1) {
            uVar2 = 0x61f;
            if (uVar1 != 0x61f) {
              uVar2 = 0x60c;
            }
            if (uVar1 != 0x61f && uVar1 != uVar2) goto LAB_00089732;
          }
          goto LAB_000897d8;
        }
        uVar1 = puVar4[iVar11 + 1];
        if (uVar1 < 0x600) {
LAB_0008976c:
          uVar2 = puVar4[iVar7];
          if (0x5ff < uVar2) {
            uVar9 = 0x61f;
            if (uVar2 != 0x61f) {
              uVar9 = 0x60c;
            }
            if (uVar2 != 0x61f && uVar2 != uVar9) goto LAB_000896f2;
          }
          goto LAB_000897d8;
        }
        uVar2 = 0x61f;
        if (uVar1 != 0x61f) {
          uVar2 = 0x60c;
        }
        if (uVar1 == 0x61f || uVar1 == uVar2) goto LAB_0008976c;
        uVar2 = puVar4[iVar7];
        if (uVar2 < 0x600) goto LAB_00089712;
LAB_000896f2:
        uVar9 = 0x61f;
        if (uVar2 != 0x61f) {
          uVar9 = 0x60c;
        }
        if (uVar2 == 0x61f || uVar2 == uVar9) goto LAB_00089712;
        if (0x5ff < uVar1) {
          uVar2 = 0x61f;
          if (uVar1 != 0x61f) {
            uVar2 = 0x60c;
          }
          if (uVar1 != 0x61f && uVar1 != uVar2) {
            uVar3 = *(uint *)(&UNK_00222a24 + iVar10);
            goto LAB_000897da;
          }
        }
LAB_00089732:
        uVar3 = *(uint *)(&UNK_00222a20 + iVar10);
      }
LAB_000897da:
      puVar4[iVar11] = (ushort)uVar3;
    }
    iVar10 = iVar10 + 0x14;
  } while (iVar10 != 0x334);
  goto LAB_00089840;
  while( true ) {
    iVar7 = iVar7 + 1;
    puVar8 = puVar8 + 5;
    if (0x28 < iVar7) break;
LAB_00089802:
    if ((uint)puVar4[iVar11] == puVar8[-4]) {
      if ((iVar11 < iVar12) && (uVar1 = puVar4[iVar11 + 1], 0x5ff < uVar1)) {
        uVar2 = 0x61f;
        if (uVar1 != 0x61f) {
          uVar2 = 0x60c;
        }
        if (uVar1 == 0x61f || uVar1 == uVar2) goto LAB_00089834;
      }
      else {
LAB_00089834:
        puVar8 = puVar8 + -3;
      }
      puVar4[iVar11] = (ushort)*puVar8;
      break;
    }
  }
LAB_00089840:
  iVar7 = iVar11 + -1;
  if (iVar11 < 1) goto LAB_00089848;
  goto LAB_000895f0;
}

// ===== GameText::setLanguage  @0x000898fc  (10 bytes)
/* GameText::setLanguage(int) */

void GameText::setLanguage(int param_1)

{
  int in_r1;
  
  setLanguage((GameText *)param_1,0,in_r1);
  return;
}

// ===== GameText::setLanguage  @0x00089904  (840 bytes)
/* GameText::setLanguage(short, int) */

void __thiscall GameText::setLanguage(GameText *this,short param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  String aSStack_2c [8];
  String aSStack_24 [8];
  uint local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (currentLang == param_1) goto LAB_00089c56;
  release(this);
  *(int *)(this + 0x18) = param_2;
  uVar1 = (uint)((ulonglong)(uint)param_2 * 4);
  if ((int)((ulonglong)(uint)param_2 * 4 >> 0x20) != 0) {
    uVar1 = 0xffffffff;
  }
  puVar2 = operator_new__(uVar1);
  *(undefined4 **)(this + 0xc) = puVar2;
  if ((0 < param_2) && (*puVar2 = 0, param_2 != 1)) {
    iVar3 = 1;
    do {
      *(undefined4 *)(*(int *)(this + 0xc) + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
    } while (param_2 != iVar3);
  }
  local_1c = 0;
  AbyssEngine::String::String(aSStack_24,"gb.lang",false);
  switch(param_1) {
  case 0:
    AbyssEngine::String::String(aSStack_2c,"gb.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    goto LAB_00089c00;
  case 1:
    AbyssEngine::String::String(aSStack_2c,"de.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 1;
    break;
  case 2:
    AbyssEngine::String::String(aSStack_2c,"fr.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 2;
    break;
  case 3:
    AbyssEngine::String::String(aSStack_2c,"it.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 3;
    break;
  case 4:
    AbyssEngine::String::String(aSStack_2c,"es.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 4;
    break;
  case 5:
    AbyssEngine::String::String(aSStack_2c,"ru.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 5;
    break;
  case 6:
    AbyssEngine::String::String(aSStack_2c,"pl.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 6;
    break;
  case 7:
    AbyssEngine::String::String(aSStack_2c,"pt.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 7;
    break;
  case 8:
    AbyssEngine::String::String(aSStack_2c,"cz.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 8;
    break;
  case 9:
    AbyssEngine::String::String(aSStack_2c,"ar.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 9;
    break;
  case 10:
    AbyssEngine::String::String(aSStack_2c,"gb.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    goto LAB_00089c00;
  case 0xb:
    AbyssEngine::String::String(aSStack_2c,"gb.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    goto LAB_00089c00;
  case 0xc:
    AbyssEngine::String::String(aSStack_2c,"ptl.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 0xc;
    break;
  case 0xd:
    AbyssEngine::String::String(aSStack_2c,"mex.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 0xd;
    break;
  case 0xe:
    AbyssEngine::String::String(aSStack_2c,"ko.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 0xe;
    break;
  case 0xf:
    AbyssEngine::String::String(aSStack_2c,"ja.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 0xf;
    break;
  default:
    AbyssEngine::String::String(aSStack_2c,"gb.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
LAB_00089c00:
    currentLang = 0;
  }
  iVar3 = AEFile::FileExist(aSStack_24);
  if (iVar3 == 0) {
    pvVar4 = (void *)AbyssEngine::String::GetAEChar(aSStack_24);
    if (pvVar4 != (void *)0x0) {
      operator_delete__(pvVar4);
    }
    AbyssEngine::String::String(aSStack_2c,"gb.lang",false);
    AbyssEngine::String::operator=(aSStack_24,aSStack_2c);
    AbyssEngine::String::~String(aSStack_2c);
    currentLang = 0;
  }
  AEFile::OpenRead(aSStack_24,&local_1c);
  ReadLangFile(this,local_1c,param_2);
  AbyssEngine::String::~String(aSStack_24);
LAB_00089c56:
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== GameText::ReadLangFile  @0x00089d6c  (306 bytes)
/* WARNING: Removing unreachable block (ram,0x00089e70) */
/* GameText::ReadLangFile(unsigned int, int) */

void __thiscall GameText::ReadLangFile(GameText *this,uint param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  ushort *puVar6;
  String *this_00;
  undefined4 extraout_r1;
  uint uVar7;
  int iVar8;
  String aSStack_34 [10];
  ushort uStack_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == 0) {
    release(this);
    return;
  }
  if (0 < param_2) {
    iVar8 = 0;
    do {
      iVar4 = AEFile::Read(2,&uStack_2a,param_1);
      uVar3 = uStack_2a;
      if (iVar4 != 1) {
LAB_00089e78:
        release(this);
        break;
      }
      uVar7 = (uint)uStack_2a;
      uVar1 = uStack_2a >> 8;
      uStack_2a = uStack_2a >> 8 | uStack_2a << 8;
      pcVar5 = operator_new__(((uVar7 << 0x18 | (uint)uVar1 << 0x10) >> 0x10) + 1);
      iVar4 = AEFile::Read((uVar7 & 0xff) << 8 | (uint)(uVar3 >> 8),pcVar5,param_1);
      if (iVar4 != 1) {
        operator_delete__(pcVar5);
        goto LAB_00089e78;
      }
      pcVar5[uStack_2a] = '\0';
      puVar6 = (ushort *)AbyssEngine::String::getWCharFromUtf8(pcVar5,(uint)uStack_2a);
      sVar2 = currentLang;
      this_00 = operator_new(8);
      if (sVar2 == 9) {
        AbyssEngine::String::String(aSStack_34,puVar6,false);
        convertStringFromArabic(this_00,extraout_r1,aSStack_34);
        *(String **)(*(int *)(this + 0xc) + iVar8 * 4) = this_00;
        AbyssEngine::String::~String(aSStack_34);
      }
      else {
        AbyssEngine::String::String(this_00,puVar6,false);
        *(String **)(*(int *)(this + 0xc) + iVar8 * 4) = this_00;
      }
      if (puVar6 != (ushort *)0x0) {
        operator_delete__(puVar6);
      }
      operator_delete__(pcVar5);
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_2);
  }
  AEFile::Close(param_1);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== GameText::isNonArabicString  @0x00089ec8  (94 bytes)
/* GameText::isNonArabicString(unsigned short const*, unsigned int) */

undefined4 GameText::isNonArabicString(ushort *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  ushort uVar7;
  
  if (param_2 != 0) {
    uVar2 = 0;
    uVar7 = 0;
    do {
      bVar1 = true;
      iVar6 = 0;
      puVar3 = &DAT_00222a18;
      do {
        iVar4 = 5;
        puVar5 = puVar3;
        do {
          iVar4 = iVar4 + -1;
          bVar1 = (bool)(bVar1 & (uint)param_1[uVar2] != *puVar5);
          puVar5 = puVar5 + 1;
        } while (iVar4 != 0);
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 5;
      } while (iVar6 != 0x29);
      if (!bVar1) {
        return 0;
      }
      uVar7 = uVar7 + 1;
      uVar2 = (uint)uVar7;
    } while (uVar2 < param_2);
  }
  return 1;
}

// ===== GameText::GameText  @0x0008bf54  (112 bytes)
/* GameText::GameText() */

void __thiscall GameText::GameText(GameText *this)

{
  undefined4 *puVar1;
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 4) = puVar1;
  *(undefined4 *)(this + 8) = 1;
  *puVar1 = 0;
  *(undefined4 *)this = 0;
  AbyssEngine::String::String((String *)(this + 0x10));
  currentLang = 0xffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  AbyssEngine::String::String(aSStack_20,"Error Language",false);
  AbyssEngine::String::operator=((String *)(this + 0x10),aSStack_20);
  AbyssEngine::String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== GameText::~GameText  @0x0008bffc  (44 bytes)
/* GameText::~GameText() */

GameText * __thiscall GameText::~GameText(GameText *this)

{
  release(this);
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xc));
  }
  *(undefined4 *)(this + 0xc) = 0;
  AbyssEngine::String::~String((String *)(this + 0x10));
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== GameText::release  @0x0008c028  (58 bytes)
/* GameText::release() */

void __thiscall GameText::release(GameText *this)

{
  String *this_00;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 0xc);
  if ((iVar3 != 0) && (iVar2 = *(int *)(this + 0x18), 0 < iVar2)) {
    iVar4 = 0;
    while( true ) {
      this_00 = *(String **)(iVar3 + iVar4 * 4);
      if (this_00 != (String *)0x0) {
        pvVar1 = (void *)AbyssEngine::String::~String(this_00);
        operator_delete(pvVar1);
        iVar3 = *(int *)(this + 0xc);
        iVar2 = *(int *)(this + 0x18);
      }
      *(undefined4 *)(iVar3 + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
      if (iVar2 <= iVar4) break;
      iVar3 = *(int *)(this + 0xc);
    }
  }
  return;
}

// ===== GameText::getLanguage  @0x0008c064  (12 bytes)
/* GameText::getLanguage() */

int GameText::getLanguage(void)

{
  return (int)currentLang;
}

// ===== GameText::setSubstituteArray  @0x0008c074  (84 bytes)
/* GameText::setSubstituteArray(int*, unsigned int) */

void __thiscall GameText::setSubstituteArray(GameText *this,int *param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 != 0) && ((param_2 & 1) == 0)) {
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 8) = 1;
    pvVar1 = realloc(*(void **)(this + 4),4);
    *(void **)(this + 4) = pvVar1;
    __aeabi_memclr4(pvVar1,*(int *)(this + 8) << 2);
    iVar2 = *(int *)this;
    pvVar1 = *(void **)(this + 4);
    do {
      iVar3 = *param_1;
      *(int *)(this + 8) = iVar2 + 1;
      pvVar1 = realloc(pvVar1,(iVar2 + 1) * 4);
      *(void **)(this + 4) = pvVar1;
      param_2 = param_2 - 1;
      *(int *)((int)pvVar1 + *(int *)this * 4) = iVar3;
      iVar2 = *(int *)(this + 8);
      *(int *)this = iVar2;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

// ===== GameText::getText  @0x0008c0c8  (292 bytes)
/* GameText::getText(int) */

GameText * __thiscall GameText::getText(GameText *this,int param_1)

{
  int iVar1;
  char *pcVar2;
  GameText *pGVar3;
  uint uVar4;
  
  if (param_1 == 5000) {
    DataMemoryBarrier(0x1b);
    if ((DAT_0026ca0c & 1) == 0) {
      iVar1 = __cxa_guard_acquire(&DAT_0026ca0c);
      if (iVar1 == 0) {
        pGVar3 = (GameText *)&DAT_0026ca04;
      }
      else {
        pcVar2 = "Datenschutzrichtlinie";
        if (currentLang != 1) {
          pcVar2 = "Privacy Policy";
        }
        AbyssEngine::String::String((String *)&DAT_0026ca04,pcVar2,false);
        pGVar3 = (GameText *)&DAT_0026ca04;
        __cxa_atexit(AbyssEngine::String::~String,&DAT_0026ca04,&DAT_00269000);
        __cxa_guard_release(&DAT_0026ca0c);
      }
    }
    else {
      pGVar3 = (GameText *)&DAT_0026ca04;
    }
  }
  else if (param_1 == 0x1389) {
    DataMemoryBarrier(0x1b);
    if ((DAT_0026ca18 & 1) == 0) {
      iVar1 = __cxa_guard_acquire(&DAT_0026ca18);
      if (iVar1 == 0) {
        pGVar3 = (GameText *)&DAT_0026ca10;
      }
      else {
        pcVar2 = "Nutzungsbestimmungen";
        if (currentLang != 1) {
          pcVar2 = "Terms of Service";
        }
        AbyssEngine::String::String((String *)&DAT_0026ca10,pcVar2,false);
        pGVar3 = (GameText *)&DAT_0026ca10;
        __cxa_atexit(AbyssEngine::String::~String,&DAT_0026ca10,&DAT_00269000);
        __cxa_guard_release(&DAT_0026ca18);
      }
    }
    else {
      pGVar3 = (GameText *)&DAT_0026ca10;
    }
  }
  else {
    if (*(uint *)this != 0) {
      uVar4 = 0;
      do {
        if (*(int *)(*(int *)(this + 4) + uVar4 * 4) == param_1) {
          param_1 = *(int *)(*(int *)(this + 4) + uVar4 * 4 + 4);
          break;
        }
        uVar4 = uVar4 + 2;
      } while (uVar4 < *(uint *)this);
    }
    if ((((param_1 < 0) || (*(int *)(this + 0x18) <= param_1)) || (*(int *)(this + 0xc) == 0)) ||
       (pGVar3 = *(GameText **)(*(int *)(this + 0xc) + param_1 * 4), pGVar3 == (GameText *)0x0)) {
      pGVar3 = this + 0x10;
    }
  }
  return pGVar3;
}

