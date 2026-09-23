// Class: _unnamed
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== FUN_00092610  @0x00092610  (94 bytes)
void FUN_00092610(undefined4 param_1,int param_2)

{
  char cVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::ConfigReader::GetNewLine();
  cVar1 = AbyssEngine::String::Compare(aSStack_1c,"EOF");
  if ((cVar1 != '\0') && (cVar1 = AbyssEngine::String::Compare(aSStack_1c,"ON"), cVar1 == '\0')) {
    *(undefined1 *)(param_2 + 0x24) = 1;
  }
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_0009a468  @0x0009a468  (8 bytes)
void FUN_0009a468(ShaderBaseStruct *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                 )

{
  String aSStack_3c [8];
  int iStack_34;
  undefined4 uStack_30;
  
  iStack_34 = __stack_chk_guard;
  uStack_30 = param_4;
  AbyssEngine::ShaderBaseStruct::ShaderBaseStruct(param_1);
  *(undefined ***)param_1 = &PTR_Init_00263a2c;
  AbyssEngine::BumpShaderRefract::ShaderIndex = AbyssEngine::ShaderBaseStruct::shaderIndexIntern;
  AbyssEngine::String::String(aSStack_3c,"BumpShaderRefract",false);
  AbyssEngine::String::operator=((String *)(param_1 + 0xc),aSStack_3c);
  AbyssEngine::String::~String(aSStack_3c);
  if (__stack_chk_guard - iStack_34 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - iStack_34);
  }
  return;
}

// ===== FUN_001b8dc8  @0x001b8dc8  (184 bytes)
undefined4 FUN_001b8dc8(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  iVar1 = *(int *)(iVar4 + 0x34);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1 + 0x20))
                      (*(undefined4 *)(param_1 + 0x28),1 << (*(uint *)(iVar4 + 0x24) & 0xff),1);
    *(int *)(iVar4 + 0x34) = iVar1;
    if (iVar1 == 0) {
      return 1;
    }
  }
  uVar2 = *(uint *)(iVar4 + 0x28);
  if (uVar2 == 0) {
    uVar2 = 1 << (*(uint *)(iVar4 + 0x24) & 0xff);
    *(uint *)(iVar4 + 0x28) = uVar2;
    *(undefined4 *)(iVar4 + 0x2c) = 0;
    *(undefined4 *)(iVar4 + 0x30) = 0;
  }
  uVar3 = param_2 - *(int *)(param_1 + 0x10);
  if (uVar3 < uVar2) {
    uVar2 = uVar2 - *(int *)(iVar4 + 0x30);
    if (uVar3 < uVar2) {
      uVar2 = uVar3;
    }
    __aeabi_memcpy(iVar1 + *(int *)(iVar4 + 0x30),*(int *)(param_1 + 0xc) - uVar3,uVar2);
    iVar1 = uVar3 - uVar2;
    if (iVar1 == 0) {
      uVar3 = *(int *)(iVar4 + 0x30) + uVar2;
      if (uVar3 == *(uint *)(iVar4 + 0x28)) {
        uVar3 = 0;
      }
      *(uint *)(iVar4 + 0x30) = uVar3;
      if (*(uint *)(iVar4 + 0x28) <= *(uint *)(iVar4 + 0x2c)) {
        return 0;
      }
      iVar1 = *(uint *)(iVar4 + 0x2c) + uVar2;
    }
    else {
      __aeabi_memcpy(*(undefined4 *)(iVar4 + 0x34),*(int *)(param_1 + 0xc) - iVar1,iVar1);
      *(int *)(iVar4 + 0x30) = iVar1;
      iVar1 = *(int *)(iVar4 + 0x28);
    }
    *(int *)(iVar4 + 0x2c) = iVar1;
    return 0;
  }
  __aeabi_memcpy(iVar1,*(int *)(param_1 + 0xc) - uVar2);
  *(undefined4 *)(iVar4 + 0x30) = 0;
  *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x28);
  return 0;
}

// ===== FUN_001b9068  @0x001b9068  (76 bytes)
uint FUN_001b9068(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar3 = *param_1;
  uVar1 = 0;
  if ((uVar3 < 4) && (param_3 != 0)) {
    uVar1 = 0;
    uVar4 = uVar3;
    do {
      cVar2 = -1;
      if (uVar4 < 2) {
        cVar2 = '\0';
      }
      if (*(char *)(param_2 + uVar1) == cVar2) {
        uVar3 = uVar4 + 1;
      }
      else {
        uVar3 = 0;
        if (*(char *)(param_2 + uVar1) == '\0') {
          uVar3 = 4 - uVar4;
        }
      }
      uVar1 = uVar1 + 1;
      bVar5 = 2 < uVar3;
      if (uVar3 < 4) {
        bVar5 = param_3 <= uVar1;
      }
      uVar4 = uVar3;
    } while (!bVar5);
  }
  *param_1 = uVar3;
  return uVar1;
}

// ===== FUN_001b9e38  @0x001b9e38  (70 bytes)
void FUN_001b9e38(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(*(int *)(param_1 + 0x1c) + 0x14);
  if (*(uint *)(param_1 + 0x10) < uVar3) {
    uVar3 = *(uint *)(param_1 + 0x10);
  }
  if (uVar3 != 0) {
    __aeabi_memcpy(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x10),
                   uVar3);
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar3;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(uint *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + uVar3;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar3;
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - uVar3;
    iVar2 = *(int *)(iVar1 + 0x14) - uVar3;
    *(int *)(iVar1 + 0x14) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 8);
    }
  }
  return;
}

// ===== FUN_001b9fca  @0x001b9fca  (260 bytes)
undefined4 FUN_001b9fca(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0xffff;
  if (param_1[3] - 5U < 0xffff) {
    uVar5 = param_1[3] - 5U;
  }
  do {
    uVar1 = param_1[0x1d];
    if (uVar1 < 2) {
      FUN_001ba714(param_1);
      uVar1 = param_1[0x1d];
      if (uVar1 == 0 && param_2 == 0) {
        return 0;
      }
      if (uVar1 == 0) {
        iVar2 = param_1[0x17];
        iVar3 = 0;
        if (-1 < iVar2) {
          iVar3 = param_1[0xe] + iVar2;
        }
        _tr_flush_block(param_1,iVar3,param_1[0x1b] - iVar2,param_2 == 4);
        param_1[0x17] = param_1[0x1b];
        FUN_001b9e38(*param_1);
        if (*(int *)(*param_1 + 0x10) != 0) {
          if (param_2 != 4) {
            return 1;
          }
          return 3;
        }
        if (param_2 != 4) {
          return 0;
        }
        return 2;
      }
    }
    uVar1 = param_1[0x1b] + uVar1;
    param_1[0x1b] = uVar1;
    param_1[0x1d] = 0;
    iVar2 = param_1[0x17];
    uVar4 = iVar2 + uVar5;
    if ((uVar1 == 0) || (uVar4 <= uVar1)) {
      param_1[0x1d] = uVar1 - uVar4;
      param_1[0x1b] = uVar4;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_1[0xe] + iVar2;
      }
      _tr_flush_block(param_1,iVar2,uVar5,0);
      param_1[0x17] = param_1[0x1b];
      FUN_001b9e38(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
      iVar2 = param_1[0x17];
      uVar1 = param_1[0x1b];
    }
    if (param_1[0xb] - 0x106U <= uVar1 - iVar2) {
      if (iVar2 < 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = param_1[0xe] + iVar2;
      }
      _tr_flush_block(param_1,iVar3,uVar1 - iVar2,0);
      param_1[0x17] = param_1[0x1b];
      FUN_001b9e38(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}

// ===== FUN_001ba714  @0x001ba714  (276 bytes)
void FUN_001ba714(int *param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  int *piVar10;
  
  uVar9 = param_1[0xb];
  uVar4 = param_1[0x1d];
  uVar7 = uVar9;
  do {
    uVar2 = param_1[0x1b];
    uVar4 = (param_1[0xf] - uVar4) - uVar2;
    if ((uVar9 - 0x106) + uVar7 <= uVar2) {
      __aeabi_memcpy(param_1[0xe],param_1[0xe] + uVar9,uVar9);
      param_1[0x1c] = param_1[0x1c] - uVar9;
      uVar2 = param_1[0x1b] - uVar9;
      param_1[0x1b] = uVar2;
      param_1[0x17] = param_1[0x17] - uVar9;
      iVar6 = param_1[0x11];
      iVar5 = param_1[0x13];
      do {
        uVar1 = *(ushort *)(iVar6 + -2 + iVar5 * 2);
        sVar8 = uVar1 - (short)uVar9;
        if (uVar1 < uVar9) {
          sVar8 = 0;
        }
        *(short *)(iVar6 + -2 + iVar5 * 2) = sVar8;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      iVar5 = param_1[0x10];
      uVar7 = uVar9;
      do {
        uVar1 = *(ushort *)(iVar5 + -2 + uVar7 * 2);
        sVar8 = uVar1 - (short)uVar9;
        if (uVar1 < uVar9) {
          sVar8 = 0;
        }
        *(short *)(iVar5 + -2 + uVar7 * 2) = sVar8;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
      uVar4 = uVar4 + uVar9;
    }
    piVar10 = (int *)*param_1;
    uVar7 = piVar10[1];
    if (uVar7 == 0) {
      return;
    }
    iVar5 = param_1[0x1d];
    if (uVar7 <= uVar4) {
      uVar4 = uVar7;
    }
    if (uVar4 == 0) {
      uVar4 = 0;
    }
    else {
      iVar6 = param_1[0xe];
      piVar10[1] = uVar7 - uVar4;
      if (*(int *)(piVar10[7] + 0x18) == 1) {
        iVar3 = adler32(piVar10[0xc],*piVar10,uVar4);
LAB_001ba7d6:
        piVar10[0xc] = iVar3;
      }
      else if (*(int *)(piVar10[7] + 0x18) == 2) {
        iVar3 = crc32(piVar10[0xc],*piVar10,uVar4);
        goto LAB_001ba7d6;
      }
      __aeabi_memcpy(uVar2 + iVar6 + iVar5,*piVar10,uVar4);
      *piVar10 = *piVar10 + uVar4;
      piVar10[2] = piVar10[2] + uVar4;
      iVar5 = param_1[0x1d];
    }
    uVar4 = iVar5 + uVar4;
    param_1[0x1d] = uVar4;
    if (2 < uVar4) {
      uVar7 = (uint)*(byte *)(param_1[0xe] + param_1[0x1b]);
      param_1[0x12] = uVar7;
      param_1[0x12] =
           ((uint)*(byte *)(param_1[0xe] + param_1[0x1b] + 1) ^ uVar7 << (param_1[0x16] & 0xffU)) &
           param_1[0x15];
      if (0x82 < uVar4 >> 1) {
        return;
      }
    }
    if (*(int *)(*param_1 + 4) == 0) {
      return;
    }
    uVar7 = param_1[0xb];
  } while( true );
}

// ===== FUN_001ba828  @0x001ba828  (402 bytes)
char * FUN_001ba828(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  char cVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  char *pcVar15;
  char *pcVar16;
  
  pcVar4 = *(char **)(param_1 + 0x78);
  uVar5 = *(uint *)(param_1 + 0x7c);
  uVar11 = *(uint *)(param_1 + 0x6c);
  uVar8 = *(int *)(param_1 + 0x2c) - 0x106;
  if (*(char **)(param_1 + 0x8c) <= pcVar4) {
    uVar5 = uVar5 >> 2;
  }
  uVar9 = uVar11 - uVar8;
  if (uVar11 < uVar8 || uVar9 == 0) {
    uVar9 = 0;
  }
  pcVar3 = *(char **)(param_1 + 0x74);
  pcVar15 = (char *)(*(int *)(param_1 + 0x38) + uVar11);
  pcVar6 = *(char **)(param_1 + 0x90);
  if (pcVar3 < *(char **)(param_1 + 0x90)) {
    pcVar6 = pcVar3;
  }
  cVar7 = pcVar15[(int)pcVar4];
  cVar10 = pcVar15[(int)(pcVar4 + -1)];
  do {
    pcVar13 = (char *)(*(int *)(param_1 + 0x38) + param_2);
    if ((((pcVar13[(int)pcVar4] == cVar7) && (pcVar13[(int)(pcVar4 + -1)] == cVar10)) &&
        (*pcVar13 == *pcVar15)) && (pcVar13[1] == pcVar15[1])) {
      iVar12 = 2;
      iVar14 = 0;
      while( true ) {
        if (pcVar15[iVar14 + 3] != pcVar13[iVar14 + 3]) {
          pcVar16 = pcVar15 + iVar14 + 3;
          goto LAB_001ba964;
        }
        if (pcVar15[iVar14 + 4] != pcVar13[iVar14 + 4]) break;
        if (pcVar15[iVar14 + 5] != pcVar13[iVar14 + 5]) {
          pcVar16 = pcVar15 + iVar12 + 3;
          goto LAB_001ba964;
        }
        if (pcVar15[iVar14 + 6] != pcVar13[iVar14 + 6]) {
          pcVar16 = pcVar15 + iVar12 + 4;
          goto LAB_001ba964;
        }
        if (pcVar15[iVar14 + 7] != pcVar13[iVar14 + 7]) {
          pcVar16 = pcVar15 + iVar12 + 5;
          goto LAB_001ba964;
        }
        if (pcVar15[iVar14 + 8] != pcVar13[iVar14 + 8]) {
          pcVar16 = pcVar15 + iVar12 + 6;
          goto LAB_001ba964;
        }
        if (pcVar15[iVar14 + 9] != pcVar13[iVar14 + 9]) {
          pcVar16 = pcVar15 + iVar12 + 7;
          goto LAB_001ba964;
        }
        iVar12 = iVar12 + 8;
        pcVar16 = pcVar15 + iVar12;
        if ((0x101 < iVar14 + 10) ||
           (iVar2 = iVar14 + 10, iVar1 = iVar14 + 10, iVar14 = iVar14 + 8,
           pcVar15[iVar1] != pcVar13[iVar2])) goto LAB_001ba964;
      }
      pcVar16 = pcVar15 + iVar12 + 2;
LAB_001ba964:
      pcVar13 = pcVar16 + (0x102 - (int)(pcVar15 + 0x102));
      if ((int)pcVar4 < (int)pcVar13) {
        *(uint *)(param_1 + 0x70) = param_2;
        if ((int)pcVar6 <= (int)pcVar13) {
LAB_001ba9a6:
          if (pcVar3 < pcVar13) {
            pcVar13 = pcVar3;
          }
          return pcVar13;
        }
        cVar7 = pcVar15[(int)pcVar13];
        cVar10 = pcVar15[(int)(pcVar16 + (0x101 - (int)(pcVar15 + 0x102)))];
        pcVar4 = pcVar13;
      }
    }
    pcVar13 = pcVar4;
    param_2 = (uint)*(ushort *)
                     (*(int *)(param_1 + 0x40) + (param_2 & *(uint *)(param_1 + 0x34)) * 2);
    if ((param_2 <= uVar9) || (uVar5 = uVar5 - 1, pcVar4 = pcVar13, uVar5 == 0)) goto LAB_001ba9a6;
  } while( true );
}

// ===== FUN_001ba9ba  @0x001ba9ba  (210 bytes)
uint FUN_001ba9ba(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (*(char *)(iVar1 + param_2) == *(char *)(iVar1 + *(int *)(param_1 + 0x6c))) {
    iVar7 = iVar1 + *(int *)(param_1 + 0x6c);
    if (*(char *)(iVar1 + param_2 + 1) == *(char *)(iVar7 + 1)) {
      iVar3 = 2;
      iVar4 = 0;
      while( true ) {
        iVar5 = iVar7 + iVar4;
        iVar6 = iVar1 + param_2 + iVar4;
        if (*(char *)(iVar5 + 3) != *(char *)(iVar6 + 3)) {
          iVar8 = iVar5 + 3;
          goto LAB_001baa6c;
        }
        iVar8 = iVar7 + iVar3;
        if (*(char *)(iVar5 + 4) != *(char *)(iVar6 + 4)) break;
        if (*(char *)(iVar5 + 5) != *(char *)(iVar6 + 5)) {
          iVar8 = iVar8 + 3;
          goto LAB_001baa6c;
        }
        if (*(char *)(iVar5 + 6) != *(char *)(iVar6 + 6)) {
          iVar8 = iVar8 + 4;
          goto LAB_001baa6c;
        }
        if (*(char *)(iVar5 + 7) != *(char *)(iVar6 + 7)) {
          iVar8 = iVar8 + 5;
          goto LAB_001baa6c;
        }
        if (*(char *)(iVar5 + 8) != *(char *)(iVar6 + 8)) {
          iVar8 = iVar8 + 6;
          goto LAB_001baa6c;
        }
        if (*(char *)(iVar5 + 9) != *(char *)(iVar6 + 9)) {
          iVar8 = iVar8 + 7;
          goto LAB_001baa6c;
        }
        iVar3 = iVar3 + 8;
        iVar8 = iVar7 + iVar3;
        if ((0x101 < iVar4 + 10) ||
           (iVar4 = iVar4 + 8, *(char *)(iVar5 + 10) != *(char *)(iVar6 + 10))) goto LAB_001baa6c;
      }
      iVar8 = iVar8 + 2;
LAB_001baa6c:
      uVar2 = (iVar8 - (iVar7 + 0x102)) + 0x102;
      if (2 < (int)uVar2) {
        *(int *)(param_1 + 0x70) = param_2;
        if (uVar2 <= *(uint *)(param_1 + 0x74)) {
          return uVar2;
        }
        return *(uint *)(param_1 + 0x74);
      }
    }
  }
  return 2;
}

// ===== FUN_001bbfa4  @0x001bbfa4  (90 bytes)
void FUN_001bbfa4(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(undefined2 *)(param_1 + 0x94 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x11e);
  iVar1 = 0;
  do {
    *(undefined2 *)(param_1 + 0x988 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x1e);
  iVar1 = 0;
  do {
    *(undefined2 *)(param_1 + 0xa7c + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x13);
  *(undefined2 *)(param_1 + 0x494) = 1;
  *(undefined4 *)(param_1 + 0x16ac) = 0;
  *(undefined4 *)(param_1 + 0x16a8) = 0;
  *(undefined4 *)(param_1 + 0x16b0) = 0;
  *(undefined4 *)(param_1 + 0x16a0) = 0;
  return;
}

// ===== FUN_001bc20e  @0x001bc20e  (108 bytes)
void FUN_001bc20e(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x16bc);
  if (*(int *)(param_1 + 0x16bc) == 0x10) {
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b8);
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b9);
    *(undefined2 *)(param_1 + 0x16b8) = 0;
    *piVar2 = 0;
    return;
  }
  if (*(int *)(param_1 + 0x16bc) < 8) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x14) = iVar1 + 1;
  *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b8);
  *(ushort *)(param_1 + 0x16b8) = (ushort)*(byte *)(param_1 + 0x16b9);
  *piVar2 = *piVar2 + -8;
  return;
}

// ===== FUN_001bc624  @0x001bc624  (934 bytes)
void FUN_001bc624(int param_1,int *param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ushort uVar13;
  short *psVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  bool bVar22;
  int local_4c;
  ushort auStack_48 [16];
  int local_28;
  
  piVar15 = (int *)(param_1 + 0x1450);
  local_28 = __stack_chk_guard;
  iVar16 = *param_2;
  iVar11 = ((int *)param_2[2])[3];
  iVar18 = *(int *)param_2[2];
  *(undefined4 *)(param_1 + 0x1450) = 0;
  *(undefined4 *)(param_1 + 0x1454) = 0x23d;
  piVar2 = (int *)(param_1 + 0x1454);
  if (iVar11 < 1) {
    iVar8 = 0;
    local_4c = -1;
  }
  else {
    local_4c = -1;
    iVar8 = 0;
    do {
      if (*(short *)(iVar16 + iVar8 * 4) == 0) {
        *(undefined2 *)(iVar16 + iVar8 * 4 + 2) = 0;
      }
      else {
        iVar9 = *piVar15;
        *piVar15 = iVar9 + 1;
        *(int *)(param_1 + (iVar9 + 1) * 4 + 0xb5c) = iVar8;
        *(undefined1 *)(param_1 + 0x1458 + iVar8) = 0;
        local_4c = iVar8;
      }
      iVar8 = iVar8 + 1;
    } while (iVar11 != iVar8);
    iVar8 = *piVar15;
    if (1 < iVar8) goto LAB_001bc726;
  }
  do {
    *piVar15 = iVar8 + 1;
    iVar9 = 0;
    if (local_4c < 2) {
      iVar9 = local_4c + 1;
    }
    *(int *)(param_1 + (iVar8 + 1) * 4 + 0xb5c) = iVar9;
    *(undefined2 *)(iVar16 + iVar9 * 4) = 1;
    *(undefined1 *)(param_1 + iVar9 + 0x1458) = 0;
    *(int *)(param_1 + 0x16a8) = *(int *)(param_1 + 0x16a8) + -1;
    if (local_4c < 2) {
      local_4c = local_4c + 1;
    }
    if (iVar18 != 0) {
      *(int *)(param_1 + 0x16ac) =
           *(int *)(param_1 + 0x16ac) - (uint)*(ushort *)(iVar18 + iVar9 * 4 + 2);
    }
    iVar8 = *piVar15;
  } while (iVar8 < 2);
LAB_001bc726:
  param_2[1] = local_4c;
  iVar18 = iVar8 / 2;
  do {
    FUN_001bcdb8(param_1,iVar16,iVar18);
    iVar8 = iVar18 + -1;
    bVar22 = 0 < iVar18;
    iVar18 = iVar8;
  } while (iVar8 != 0 && bVar22);
  iVar18 = *piVar15;
  iVar8 = param_1 + 0x1458;
  do {
    iVar17 = param_1 + 0xb5c;
    iVar19 = *(int *)(param_1 + 0xb60);
    *piVar15 = iVar18 + -1;
    *(undefined4 *)(param_1 + 0xb60) = *(undefined4 *)(iVar17 + iVar18 * 4);
    FUN_001bcdb8(param_1,iVar16,1);
    iVar18 = *piVar2;
    iVar9 = *(int *)(param_1 + 0xb60);
    *piVar2 = iVar18 + -1;
    *(int *)(iVar17 + (iVar18 + -1) * 4) = iVar19;
    iVar18 = *piVar2;
    *piVar2 = iVar18 + -1;
    *(int *)(iVar17 + (iVar18 + -1) * 4) = iVar9;
    *(short *)(iVar16 + iVar11 * 4) =
         *(short *)(iVar16 + iVar19 * 4) + *(short *)(iVar16 + iVar9 * 4);
    bVar1 = *(byte *)(iVar8 + iVar19);
    if (*(byte *)(iVar8 + iVar19) < *(byte *)(iVar8 + iVar9)) {
      bVar1 = *(byte *)(iVar8 + iVar9);
    }
    *(byte *)(iVar8 + iVar11) = bVar1 + 1;
    *(short *)(iVar16 + iVar9 * 4 + 2) = (short)iVar11;
    *(short *)(iVar16 + iVar19 * 4 + 2) = (short)iVar11;
    *(int *)(param_1 + 0xb60) = iVar11;
    FUN_001bcdb8(param_1,iVar16,1);
    iVar18 = *piVar15;
    iVar11 = iVar11 + 1;
  } while (1 < iVar18);
  iVar11 = *piVar2;
  *piVar2 = iVar11 + -1;
  *(undefined4 *)(iVar17 + (iVar11 + -1) * 4) = *(undefined4 *)(param_1 + 0xb60);
  iVar20 = *param_2;
  iVar8 = param_2[1];
  piVar15 = (int *)param_2[2];
  iVar11 = piVar15[1];
  iVar18 = *piVar15;
  iVar9 = piVar15[2];
  uVar21 = piVar15[4];
  *(undefined4 *)(param_1 + 0xb4c) = 0;
  *(undefined4 *)(param_1 + 0xb50) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(param_1 + 0xb54) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(param_1 + 0xb58) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(param_1 + 0xb3c) = 0;
  *(undefined4 *)(param_1 + 0xb40) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(param_1 + 0xb44) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(param_1 + 0xb48) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  iVar19 = *piVar2;
  *(undefined2 *)(iVar20 + *(int *)(iVar17 + iVar19 * 4) * 4 + 2) = 0;
  if (iVar19 + 1 < 0x23d) {
    iVar17 = 0;
    piVar2 = (int *)(param_1 + 0x16a8);
    do {
      iVar3 = *(int *)(param_1 + iVar19 * 4 + 0xb60);
      iVar6 = iVar20 + iVar3 * 4;
      uVar12 = (uint)*(ushort *)(iVar20 + (uint)*(ushort *)(iVar6 + 2) * 4 + 2);
      uVar10 = uVar21;
      if ((int)uVar12 < (int)uVar21) {
        uVar10 = uVar12 + 1;
      }
      *(short *)(iVar6 + 2) = (short)uVar10;
      if ((int)uVar21 <= (int)uVar12) {
        iVar17 = iVar17 + 1;
      }
      if (iVar3 <= iVar8) {
        iVar6 = param_1 + uVar10 * 2;
        *(short *)(iVar6 + 0xb3c) = *(short *)(iVar6 + 0xb3c) + 1;
        if (iVar3 < iVar9) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(iVar11 + (iVar3 - iVar9) * 4);
        }
        uVar12 = (uint)*(ushort *)(iVar20 + iVar3 * 4);
        *piVar2 = uVar12 * (uVar10 + iVar6) + *piVar2;
        if (iVar18 != 0) {
          *(int *)(param_1 + 0x16ac) =
               ((uint)*(ushort *)(iVar18 + iVar3 * 4 + 2) + iVar6) * uVar12 +
               *(int *)(param_1 + 0x16ac);
        }
      }
      iVar19 = iVar19 + 1;
    } while (iVar19 != 0x23c);
    if (iVar17 != 0) {
      iVar11 = param_1 + uVar21 * 2;
      psVar14 = (short *)(iVar11 + 0xb3e);
      puVar7 = (ushort *)(iVar11 + 0xb3c);
      psVar5 = psVar14;
      do {
        do {
          psVar4 = psVar5;
          psVar5 = psVar4 + -1;
        } while (psVar4[-2] == 0);
        psVar4[-2] = psVar4[-2] + -1;
        iVar11 = iVar17 + -2;
        *psVar5 = *psVar5 + 2;
        uVar13 = *puVar7 - 1;
        *puVar7 = uVar13;
        bVar22 = 1 < iVar17;
        psVar5 = psVar14;
        iVar17 = iVar11;
      } while (iVar11 != 0 && bVar22);
      if (uVar21 != 0) {
        iVar11 = 0x23d;
        while( true ) {
          uVar10 = (uint)uVar13;
          iVar18 = iVar11;
          while (uVar10 != 0) {
            iVar9 = *(int *)(param_1 + 0xb58 + iVar18 * 4);
            iVar18 = iVar18 + -1;
            if (iVar9 <= iVar8) {
              puVar7 = (ushort *)(iVar20 + iVar9 * 4 + 2);
              uVar12 = (uint)*puVar7;
              if (uVar21 != uVar12) {
                *piVar2 = (uint)*(ushort *)(iVar20 + iVar9 * 4) * (uVar21 - uVar12) + *piVar2;
                *puVar7 = (ushort)uVar21;
              }
              uVar10 = uVar10 - 1;
              iVar11 = iVar18;
            }
          }
          uVar21 = uVar21 - 1;
          if (uVar21 == 0) break;
          uVar13 = *(ushort *)(param_1 + uVar21 * 2 + 0xb3c);
        }
      }
    }
  }
  iVar11 = 0;
  uVar13 = 0;
  do {
    uVar13 = (uVar13 + *(short *)(param_1 + 0xb3c + iVar11 * 2)) * 2;
    auStack_48[iVar11 + 1] = uVar13;
    iVar11 = iVar11 + 1;
  } while (iVar11 != 0xf);
  if (-1 < local_4c) {
    iVar11 = 0;
    do {
      uVar21 = (uint)*(ushort *)(iVar16 + iVar11 * 4 + 2);
      if (uVar21 != 0) {
        uVar10 = (uint)auStack_48[uVar21];
        auStack_48[uVar21] = auStack_48[uVar21] + 1;
        iVar18 = uVar21 + 1;
        uVar21 = 0;
        do {
          iVar18 = iVar18 + -1;
          uVar12 = uVar10 & 1 | uVar21;
          uVar10 = uVar10 >> 1;
          uVar21 = uVar12 << 1;
        } while (1 < iVar18);
        *(short *)(iVar16 + iVar11 * 4) = (short)uVar12;
      }
      bVar22 = iVar11 != local_4c;
      iVar11 = iVar11 + 1;
    } while (bVar22);
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== FUN_001bc9d4  @0x001bc9d4  (708 bytes)
void FUN_001bc9d4(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  ushort *puVar14;
  
  if (*(int *)(param_1 + 0x16a0) == 0) {
    uVar3 = *(ushort *)(param_1 + 0x16b8);
    uVar6 = *(uint *)(param_1 + 0x16bc);
  }
  else {
    puVar14 = (ushort *)(param_1 + 0x16b8);
    puVar13 = (uint *)(param_1 + 0x16bc);
    uVar12 = 0;
    do {
      uVar10 = (uint)*(ushort *)(*(int *)(param_1 + 0x16a4) + uVar12 * 2);
      uVar11 = (uint)*(byte *)(*(int *)(param_1 + 0x1698) + uVar12);
      uVar12 = uVar12 + 1;
      if (uVar10 == 0) {
        uVar10 = (uint)*(ushort *)(param_2 + uVar11 * 4);
        uVar6 = *puVar13;
        uVar11 = (uint)*(ushort *)(param_2 + uVar11 * 4 + 2);
        uVar2 = (uint)*puVar14 | uVar10 << (uVar6 & 0xff);
        uVar3 = (ushort)uVar2;
        *puVar14 = uVar3;
        if ((int)(0x10 - uVar11) < (int)uVar6) {
          iVar4 = *(int *)(param_1 + 0x14);
LAB_001bcbe0:
          *(int *)(param_1 + 0x14) = iVar4 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)uVar2;
          iVar4 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar4 + 1;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar4) = *(undefined1 *)(param_1 + 0x16b9);
          uVar3 = (ushort)(uVar10 >> (0x10 - *puVar13 & 0xff));
          *puVar14 = uVar3;
          uVar6 = (uVar11 + *puVar13) - 0x10;
        }
        else {
          uVar6 = uVar6 + uVar11;
        }
LAB_001bcc12:
        *puVar13 = uVar6;
      }
      else {
        uVar6 = *puVar13;
        uVar2 = (uint)(byte)_length_code[uVar11];
        iVar4 = param_2 + (uVar2 | 0x100) * 4;
        uVar3 = *(ushort *)(iVar4 + 4);
        uVar8 = (uint)*(ushort *)(iVar4 + 6);
        uVar5 = (uint)uVar3 << (uVar6 & 0xff) | (uint)*puVar14;
        *puVar14 = (ushort)uVar5;
        if ((int)(0x10 - uVar8) < (int)uVar6) {
          iVar4 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar4 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)uVar5;
          iVar4 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar4 + 1;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar4) = *(undefined1 *)(param_1 + 0x16b9);
          uVar3 = uVar3 >> (0x10 - *puVar13 & 0xff);
          uVar5 = (uint)uVar3;
          uVar6 = (*puVar13 + uVar8) - 0x10;
          *puVar14 = uVar3;
        }
        else {
          uVar6 = uVar6 + uVar8;
        }
        uVar3 = (ushort)uVar5;
        *puVar13 = uVar6;
        if (uVar2 - 8 < 0x14) {
          iVar9 = *(int *)(&DAT_00260ff8 + uVar2 * 4);
          iVar4 = *(int *)(&DAT_00261144 + uVar2 * 4);
          uVar2 = uVar5 & 0xffff | uVar11 - iVar4 << (uVar6 & 0xff);
          uVar3 = (ushort)uVar2;
          *puVar14 = uVar3;
          if (0x10 - iVar9 < (int)uVar6) {
            iVar7 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar7 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar7) = (char)uVar2;
            iVar7 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar7 + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar7) = *(undefined1 *)(param_1 + 0x16b9);
            uVar3 = (ushort)((uVar11 - iVar4 & 0xffff) >> (0x10 - *puVar13 & 0xff));
            *puVar14 = uVar3;
            uVar6 = (iVar9 + *puVar13) - 0x10;
          }
          else {
            uVar6 = uVar6 + iVar9;
          }
          *puVar13 = uVar6;
        }
        uVar10 = uVar10 - 1;
        uVar11 = uVar10;
        if (0xff < uVar10) {
          uVar11 = (uVar10 >> 7) + 0x100;
        }
        uVar2 = (uint)(byte)_dist_code[uVar11];
        uVar1 = *(ushort *)(param_3 + uVar2 * 4);
        uVar11 = (uint)*(ushort *)(param_3 + uVar2 * 4 + 2);
        uVar5 = (uint)uVar3 | (uint)uVar1 << (uVar6 & 0xff);
        *puVar14 = (ushort)uVar5;
        if ((int)(0x10 - uVar11) < (int)uVar6) {
          iVar4 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar4 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)uVar5;
          iVar4 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar4 + 1;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar4) = *(undefined1 *)(param_1 + 0x16b9);
          uVar1 = uVar1 >> (0x10 - *puVar13 & 0xff);
          uVar5 = (uint)uVar1;
          uVar6 = (*puVar13 + uVar11) - 0x10;
          *puVar14 = uVar1;
        }
        else {
          uVar6 = uVar6 + uVar11;
        }
        uVar3 = (ushort)uVar5;
        *puVar13 = uVar6;
        if (uVar2 - 4 < 0x1a) {
          uVar11 = *(uint *)(&DAT_0026106c + uVar2 * 4);
          iVar9 = *(int *)(&DAT_002611b8 + uVar2 * 4);
          uVar2 = uVar5 & 0xffff | uVar10 - iVar9 << (uVar6 & 0xff);
          uVar3 = (ushort)uVar2;
          *puVar14 = uVar3;
          if ((int)(0x10 - uVar11) < (int)uVar6) {
            iVar4 = *(int *)(param_1 + 0x14);
            uVar10 = uVar10 - iVar9 & 0xffff;
            goto LAB_001bcbe0;
          }
          uVar6 = uVar6 + uVar11;
          goto LAB_001bcc12;
        }
      }
    } while (uVar12 < *(uint *)(param_1 + 0x16a0));
  }
  uVar1 = *(ushort *)(param_2 + 0x400);
  uVar12 = (uint)*(ushort *)(param_2 + 0x402);
  uVar10 = (uint)uVar1 << (uVar6 & 0xff) | (uint)uVar3;
  *(ushort *)(param_1 + 0x16b8) = (ushort)uVar10;
  if ((int)(0x10 - uVar12) < (int)uVar6) {
    iVar4 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(char *)(*(int *)(param_1 + 8) + iVar4) = (char)uVar10;
    iVar4 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar4 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar4) = *(undefined1 *)(param_1 + 0x16b9);
    iVar9 = *(int *)(param_1 + 0x16bc);
    iVar4 = uVar12 + iVar9 + -0x10;
    *(ushort *)(param_1 + 0x16b8) = uVar1 >> (0x10U - iVar9 & 0xff);
  }
  else {
    iVar4 = uVar12 + uVar6;
  }
  *(int *)(param_1 + 0x16bc) = iVar4;
  *(uint *)(param_1 + 0x16b4) = (uint)*(ushort *)(param_2 + 0x402);
  return;
}

// ===== FUN_001bccb0  @0x001bccb0  (92 bytes)
void FUN_001bccb0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x16bc) < 9) {
    if (0 < *(int *)(param_1 + 0x16bc)) {
      iVar1 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar1 + 1;
      *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b8);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b8);
    iVar1 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    *(undefined1 *)(*(int *)(param_1 + 8) + iVar1) = *(undefined1 *)(param_1 + 0x16b9);
  }
  *(undefined2 *)(param_1 + 0x16b8) = 0;
  *(undefined4 *)(param_1 + 0x16bc) = 0;
  return;
}

// ===== FUN_001bcdb8  @0x001bcdb8  (174 bytes)
void FUN_001bcdb8(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar3 = *(int *)(param_1 + 0x1450);
  uVar4 = param_3 * 2;
  iVar7 = *(int *)(param_1 + param_3 * 4 + 0xb5c);
  if (uVar4 - iVar3 == 0 || (int)uVar4 < iVar3) {
    do {
      uVar6 = uVar4;
      if ((int)uVar4 < iVar3) {
        uVar8 = uVar4 | 1;
        iVar5 = *(int *)(param_1 + 0xb5c + uVar4 * 4);
        iVar3 = *(int *)(param_1 + 0xb5c + uVar8 * 4);
        uVar1 = *(ushort *)(param_2 + iVar5 * 4);
        uVar2 = *(ushort *)(param_2 + iVar3 * 4);
        uVar6 = uVar8;
        if (((uVar1 <= uVar2) && (uVar6 = uVar4, uVar2 == uVar1)) &&
           (*(byte *)(param_1 + 0x1458 + iVar3) <= *(byte *)(param_1 + 0x1458 + iVar5))) {
          uVar6 = uVar8;
        }
      }
      iVar3 = *(int *)(param_1 + uVar6 * 4 + 0xb5c);
      uVar1 = *(ushort *)(param_2 + iVar7 * 4);
      uVar2 = *(ushort *)(param_2 + iVar3 * 4);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(param_1 + iVar7 + 0x1458) <= *(byte *)(param_1 + iVar3 + 0x1458))))) break;
      uVar4 = uVar6 * 2;
      *(int *)(param_1 + param_3 * 4 + 0xb5c) = iVar3;
      iVar3 = *(int *)(param_1 + 0x1450);
      param_3 = uVar6;
    } while (uVar4 - iVar3 == 0 || (int)uVar4 < iVar3);
  }
  *(int *)(param_1 + param_3 * 4 + 0xb5c) = iVar7;
  return;
}

// ===== FUN_001bce66  @0x001bce66  (194 bytes)
void FUN_001bce66(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  uVar1 = *(ushort *)(param_2 + 2);
  iVar4 = 4;
  iVar6 = 7;
  *(undefined2 *)(param_2 + param_3 * 4 + 6) = 0xffff;
  if (uVar1 == 0) {
    iVar4 = 3;
    iVar6 = 0x8a;
  }
  iVar9 = 0;
  uVar3 = (uint)uVar1;
  uVar8 = 0xffffffff;
  do {
    uVar2 = uVar3;
    iVar7 = 0;
    do {
      if (param_3 < iVar9 + iVar7) {
        return;
      }
      uVar3 = (uint)*(ushort *)(param_2 + 6 + iVar9 * 4 + iVar7 * 4);
      iVar7 = iVar7 + 1;
    } while ((iVar7 < iVar6) && (uVar2 == uVar3));
    iVar9 = iVar9 + iVar7;
    if (iVar7 < iVar4) {
      iVar4 = param_1 + uVar2 * 4;
      *(short *)(iVar4 + 0xa7c) = *(short *)(iVar4 + 0xa7c) + (short)iVar7;
    }
    else if (uVar2 == 0) {
      if (iVar7 < 0xb) {
        *(short *)(param_1 + 0xac0) = *(short *)(param_1 + 0xac0) + 1;
      }
      else {
        *(short *)(param_1 + 0xac4) = *(short *)(param_1 + 0xac4) + 1;
      }
    }
    else {
      sVar5 = (short)iVar6;
      if (uVar2 != uVar8) {
        iVar4 = param_1 + uVar2 * 4;
        sVar5 = *(short *)(iVar4 + 0xa7c) + 1;
      }
      if (uVar2 != uVar8) {
        *(short *)(iVar4 + 0xa7c) = sVar5;
      }
      *(short *)(param_1 + 0xabc) = *(short *)(param_1 + 0xabc) + 1;
    }
    iVar4 = 4;
    if (uVar2 == uVar3) {
      iVar4 = 3;
    }
    iVar6 = 7;
    if (uVar3 == 0) {
      iVar4 = 3;
    }
    if (uVar2 == uVar3) {
      iVar6 = 6;
    }
    uVar8 = uVar2;
    if (uVar3 == 0) {
      iVar6 = 0x8a;
    }
  } while( true );
}

// ===== FUN_001bcf28  @0x001bcf28  (870 bytes)
void FUN_001bcf28(int param_1,int param_2,int param_3)

{
  int iVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  ushort *puVar14;
  int iVar15;
  int iVar16;
  
  puVar14 = (ushort *)(param_1 + 0x16b8);
  puVar5 = (uint *)(param_1 + 0x16bc);
  iVar6 = 7;
  iVar8 = 4;
  if (*(ushort *)(param_2 + 2) == 0) {
    iVar6 = 0x8a;
    iVar8 = 3;
  }
  iVar15 = 0;
  uVar11 = (uint)*(ushort *)(param_2 + 2);
  uVar4 = 0xffffffff;
  do {
    uVar10 = uVar11;
    puVar3 = (ushort *)(param_2 + 6 + iVar15 * 4);
    uVar13 = 0xfffffffd;
    iVar1 = -1;
    do {
      iVar16 = iVar1;
      uVar7 = uVar13;
      if (param_3 < (int)(iVar15 + uVar7 + 3)) {
        return;
      }
      uVar11 = (uint)*puVar3;
      uVar13 = uVar7 + 1;
    } while (((int)(uVar7 + 4) < iVar6) &&
            (puVar3 = puVar3 + 2, iVar1 = iVar16 + -1, uVar10 == uVar11));
    iVar6 = uVar7 + 4;
    iVar15 = iVar15 + uVar13 + 3;
    if (iVar6 < iVar8) {
      iVar6 = param_1 + uVar10 * 4;
      uVar13 = (uint)*puVar14;
      uVar4 = *puVar5;
      do {
        uVar12 = *(ushort *)(iVar6 + 0xa7c);
        uVar7 = (uint)*(ushort *)(iVar6 + 0xa7e);
        uVar13 = uVar13 & 0xffff | (uint)uVar12 << (uVar4 & 0xff);
        *puVar14 = (ushort)uVar13;
        if ((int)(0x10 - uVar7) < (int)uVar4) {
          iVar8 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar8 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar8) = (char)uVar13;
          iVar8 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar8 + 1;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar8) = *(undefined1 *)(param_1 + 0x16b9);
          uVar4 = (*puVar5 + uVar7) - 0x10;
          uVar12 = uVar12 >> (0x10 - *puVar5 & 0xff);
          uVar13 = (uint)uVar12;
          *puVar14 = uVar12;
        }
        else {
          uVar4 = uVar4 + uVar7;
        }
        iVar16 = iVar16 + 1;
        *puVar5 = uVar4;
      } while (iVar16 != 0);
    }
    else {
      if (uVar10 == 0) {
        if (iVar6 < 0xb) {
          uVar7 = *puVar5;
          uVar12 = *(ushort *)(param_1 + 0xac0);
          uVar9 = (uint)*(ushort *)(param_1 + 0xac2);
          uVar4 = (uint)*puVar14 | (uint)uVar12 << (uVar7 & 0xff);
          uVar2 = (ushort)uVar4;
          *puVar14 = uVar2;
          if ((int)(0x10 - uVar9) < (int)uVar7) {
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar4;
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar6) = *(undefined1 *)(param_1 + 0x16b9);
            uVar9 = (uVar9 + *puVar5) - 0x10;
            uVar2 = uVar12 >> (0x10 - *puVar5 & 0xff);
            *puVar14 = uVar2;
          }
          else {
            uVar9 = uVar9 + uVar7;
          }
          uVar4 = (uint)uVar2 | uVar13 << (uVar9 & 0xff);
          *puVar5 = uVar9;
          *puVar14 = (ushort)uVar4;
          if ((int)uVar9 < 0xe) {
            uVar9 = uVar9 + 3;
          }
          else {
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar4;
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar6) = *(undefined1 *)(param_1 + 0x16b9);
            uVar9 = *puVar5 - 0xd;
            *puVar14 = (ushort)((uVar13 & 0xffff) >> (0x10 - *puVar5 & 0xff));
          }
        }
        else {
          uVar9 = *puVar5;
          uVar12 = *(ushort *)(param_1 + 0xac4);
          uVar13 = (uint)*(ushort *)(param_1 + 0xac6);
          uVar4 = (uint)*puVar14 | (uint)uVar12 << (uVar9 & 0xff);
          uVar2 = (ushort)uVar4;
          *puVar14 = uVar2;
          if ((int)(0x10 - uVar13) < (int)uVar9) {
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar4;
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar6) = *(undefined1 *)(param_1 + 0x16b9);
            uVar2 = uVar12 >> (0x10 - *puVar5 & 0xff);
            uVar9 = (uVar13 + *puVar5) - 0x10;
            *puVar14 = uVar2;
          }
          else {
            uVar9 = uVar9 + uVar13;
          }
          *puVar5 = uVar9;
          uVar4 = (uint)uVar2 | uVar7 - 7 << (uVar9 & 0xff);
          *puVar14 = (ushort)uVar4;
          if ((int)uVar9 < 10) {
            uVar9 = uVar9 + 7;
          }
          else {
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar6) = (char)uVar4;
            iVar6 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar6 + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar6) = *(undefined1 *)(param_1 + 0x16b9);
            uVar9 = *puVar5 - 9;
            *puVar14 = (ushort)((uVar7 - 7 & 0xffff) >> (0x10 - *puVar5 & 0xff));
          }
        }
      }
      else {
        if (uVar10 == uVar4) {
          uVar12 = *puVar14;
          uVar4 = *puVar5;
        }
        else {
          iVar8 = param_1 + uVar10 * 4;
          uVar13 = *puVar5;
          iVar6 = uVar7 + 3;
          uVar2 = *(ushort *)(iVar8 + 0xa7c);
          uVar4 = (uint)*(ushort *)(iVar8 + 0xa7e);
          uVar7 = (uint)*puVar14 | (uint)uVar2 << (uVar13 & 0xff);
          uVar12 = (ushort)uVar7;
          *puVar14 = uVar12;
          if ((int)(0x10 - uVar4) < (int)uVar13) {
            iVar8 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar8 + 1;
            *(char *)(*(int *)(param_1 + 8) + iVar8) = (char)uVar7;
            iVar8 = *(int *)(param_1 + 0x14);
            *(int *)(param_1 + 0x14) = iVar8 + 1;
            *(undefined1 *)(*(int *)(param_1 + 8) + iVar8) = *(undefined1 *)(param_1 + 0x16b9);
            uVar4 = (uVar4 + *puVar5) - 0x10;
            uVar12 = uVar2 >> (0x10 - *puVar5 & 0xff);
            *puVar14 = uVar12;
          }
          else {
            uVar4 = uVar4 + uVar13;
          }
          *puVar5 = uVar4;
        }
        uVar2 = *(ushort *)(param_1 + 0xabc);
        uVar9 = (uint)*(ushort *)(param_1 + 0xabe);
        uVar13 = (uint)uVar2 << (uVar4 & 0xff) | (uint)uVar12;
        uVar12 = (ushort)uVar13;
        *puVar14 = uVar12;
        if ((int)(0x10 - uVar9) < (int)uVar4) {
          iVar8 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar8 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar8) = (char)uVar13;
          iVar8 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar8 + 1;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar8) = *(undefined1 *)(param_1 + 0x16b9);
          uVar9 = (*puVar5 + uVar9) - 0x10;
          uVar12 = uVar2 >> (0x10 - *puVar5 & 0xff);
          *puVar14 = uVar12;
        }
        else {
          uVar9 = uVar9 + uVar4;
        }
        *puVar5 = uVar9;
        uVar4 = (uint)uVar12 | iVar6 - 3U << (uVar9 & 0xff);
        *puVar14 = (ushort)uVar4;
        if ((int)uVar9 < 0xf) {
          uVar9 = uVar9 + 2;
        }
        else {
          iVar8 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar8 + 1;
          *(char *)(*(int *)(param_1 + 8) + iVar8) = (char)uVar4;
          iVar8 = *(int *)(param_1 + 0x14);
          *(int *)(param_1 + 0x14) = iVar8 + 1;
          *(undefined1 *)(*(int *)(param_1 + 8) + iVar8) = *(undefined1 *)(param_1 + 0x16b9);
          *puVar14 = (ushort)((iVar6 - 3U & 0xffff) >> (0x10 - *puVar5 & 0xff));
          uVar9 = *puVar5 - 0xe;
        }
      }
      *puVar5 = uVar9;
    }
    iVar6 = 7;
    if (uVar10 == uVar11) {
      iVar6 = 6;
    }
    iVar8 = 4;
    if (uVar11 == 0) {
      iVar6 = 0x8a;
    }
    if (uVar10 == uVar11) {
      iVar8 = 3;
    }
    uVar4 = uVar10;
    if (uVar11 == 0) {
      iVar8 = 3;
    }
  } while( true );
}

// ===== FUN_001bdde8  @0x001bdde8  (126 bytes)
uint FUN_001bdde8(int *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  switch(param_4) {
  case 0:
    *param_1 = param_1[1];
    break;
  case 1:
    uVar1 = param_1[2] - *param_1;
    if (param_3 < uVar1) {
      uVar1 = param_3;
    }
    if (uVar1 != 0) {
      __aeabi_memcpy(param_2,*param_1,uVar1);
      *param_1 = *param_1 + uVar1;
      return uVar1;
    }
    break;
  case 2:
    goto switchD_001bddf8_caseD_2;
  case 3:
    if (0x1b < param_3) {
      zip_stat_init(param_2);
      param_2[3] = param_1[3];
      param_2[4] = param_1[2] - param_1[1];
      return 0x1c;
    }
  default:
switchD_001bddf8_default:
    uVar1 = 0xffffffff;
    goto switchD_001bddf8_caseD_2;
  case 4:
    if (7 < param_3) {
      *param_2 = 0;
      param_2[1] = 0;
      return 8;
    }
    goto switchD_001bddf8_default;
  case 5:
    if (param_1[4] != 0) {
      free((void *)param_1[1]);
    }
    free(param_1);
  }
  uVar1 = 0;
switchD_001bddf8_caseD_2:
  return uVar1;
}

// ===== FUN_001bedf0  @0x001bedf0  (294 bytes)
void FUN_001bedf0(int *param_1,int *param_2,uint param_3,undefined4 param_4)

{
  FILE *__stream;
  uint uVar1;
  size_t sVar2;
  int iVar3;
  int *piVar4;
  uint __n;
  stat sStack_80;
  int local_18;
  
  local_18 = __stack_chk_guard;
  switch(param_4) {
  case 0:
    if ((char *)*param_1 == (char *)0x0) {
      __stream = (FILE *)param_1[1];
LAB_001beeaa:
      iVar3 = fseeko(__stream,param_1[2],0);
      if (-1 < iVar3) {
        param_1[4] = param_1[3];
        break;
      }
      iVar3 = 4;
    }
    else {
      __stream = fopen((char *)*param_1,"rb");
      param_1[1] = (int)__stream;
      if (__stream != (FILE *)0x0) goto LAB_001beeaa;
      iVar3 = 0xb;
    }
    goto LAB_001beed0;
  case 1:
    uVar1 = param_1[4];
    __n = param_3;
    if (uVar1 < param_3) {
      __n = uVar1;
    }
    if (uVar1 == 0xffffffff) {
      __n = param_3;
    }
    sVar2 = fread(param_2,1,__n,(FILE *)param_1[1]);
    if (-1 < (int)sVar2) {
      if (param_1[4] != -1) {
        param_1[4] = param_1[4] - sVar2;
      }
      break;
    }
    goto LAB_001beece;
  case 2:
    if (*param_1 != 0) {
      fclose((FILE *)param_1[1]);
      param_1[1] = 0;
    }
    break;
  case 3:
    if (param_3 < 0x1c) break;
    if (param_1[1] == 0) {
      iVar3 = stat((char *)*param_1,&sStack_80);
    }
    else {
      iVar3 = fstat((int)*(short *)(param_1[1] + 0xe),&sStack_80);
    }
    if (iVar3 == 0) {
      zip_stat_init(param_2);
      param_2[3] = sStack_80.__unused4;
      iVar3 = param_1[3];
      if ((param_1[3] != -1) ||
         (iVar3 = sStack_80.st_blksize, (sStack_80.st_mode & 0xf000) == 0x8000)) {
        param_2[4] = iVar3;
      }
      break;
    }
LAB_001beece:
    iVar3 = 5;
LAB_001beed0:
    param_1[5] = iVar3;
    piVar4 = (int *)__errno();
    param_1[6] = *piVar4;
    break;
  case 4:
    if (7 < param_3) {
      iVar3 = param_1[5];
      param_2[1] = param_1[6];
      *param_2 = iVar3;
    }
    break;
  case 5:
    free((void *)*param_1);
    if ((FILE *)param_1[1] != (FILE *)0x0) {
      fclose((FILE *)param_1[1]);
    }
    free(param_1);
  }
  if (__stack_chk_guard - local_18 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_18);
}

// ===== FUN_001bfdcc  @0x001bfdcc  (92 bytes)
void FUN_001bfdcc(char *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  undefined1 auStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  puVar1 = (undefined4 *)_zip_new(auStack_24);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_001bfe30(param_2,auStack_24,0);
  }
  else {
    pcVar2 = strdup(param_1);
    *puVar1 = pcVar2;
    if ((pcVar2 == (char *)0x0) && (_zip_free(puVar1), param_2 != (undefined4 *)0x0)) {
      *param_2 = 0xe;
    }
  }
  if (__stack_chk_guard - local_18 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_18);
}

// ===== FUN_001bfe30  @0x001bfe30  (82 bytes)
void FUN_001bfe30(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = param_3;
  if (param_2 != 0) {
    _zip_error_get(param_2,&local_18,&local_1c);
    iVar1 = zip_error_get_sys_type(local_18);
    if (iVar1 == 1) {
      puVar2 = (undefined4 *)__errno();
      *puVar2 = local_1c;
    }
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = local_18;
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_001bfe8c  @0x001bfe8c  (376 bytes)
void FUN_001bfe8c(FILE *param_1,int *param_2,undefined4 param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  undefined1 auStack_64 [2];
  short local_62;
  byte local_60;
  short local_5e;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  char *local_4c;
  ushort local_48;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_2[1] == 0) {
    uVar12 = 0;
    uVar13 = 0;
  }
  else {
    uVar12 = *(uint *)(*param_2 + 0x38);
    uVar13 = uVar12;
    if (0 < param_2[1]) {
      iVar10 = 0;
      iVar11 = 0x38;
      do {
        uVar6 = *(uint *)(*param_2 + iVar11);
        if (uVar6 < uVar12) {
          uVar12 = uVar6;
        }
        if ((uint)param_2[3] < uVar12) {
LAB_001bffd8:
          uVar7 = 0x13;
LAB_001bffe2:
          _zip_error_set(param_3,uVar7,0);
LAB_001bffe8:
          iVar10 = -1;
          goto LAB_001bffec;
        }
        iVar8 = *param_2 + iVar11;
        uVar9 = (uint)*(ushort *)(iVar8 + -0x1c) + *(int *)(iVar8 + -0x28) + uVar6 + 0x1e;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
        if ((uint)param_2[3] < uVar13) goto LAB_001bffd8;
        iVar8 = fseeko(param_1,uVar6,0);
        if (iVar8 != 0) {
          uVar7 = 4;
          goto LAB_001bffe2;
        }
        iVar8 = _zip_dirent_read(auStack_64,param_1,0,0,1,param_3);
        if (iVar8 == -1) goto LAB_001bffe8;
        iVar8 = *param_2 + iVar11;
        sVar1 = *(short *)(iVar8 + -0x36);
        sVar2 = local_62;
        sVar3 = sVar1;
        if (sVar1 == local_62) {
          sVar2 = *(short *)(iVar8 + -0x32);
          sVar3 = local_5e;
        }
        if (sVar1 != local_62 || sVar2 != sVar3) {
LAB_001bffc6:
          _zip_error_set(param_3,0x15,0);
          _zip_dirent_finalize(auStack_64);
          goto LAB_001bffe8;
        }
        uVar6 = *(uint *)(iVar8 + -0x30);
        bVar14 = uVar6 != local_5c;
        uVar9 = local_5c;
        if (!bVar14) {
          uVar9 = (uint)local_48;
          uVar6 = (uint)*(ushort *)(iVar8 + -0x1c);
        }
        if ((((bVar14 || uVar6 != uVar9) || (*(char **)(iVar8 + -0x20) == (char *)0x0)) ||
            (local_4c == (char *)0x0)) ||
           (iVar5 = strcmp(*(char **)(iVar8 + -0x20),local_4c), iVar5 != 0)) goto LAB_001bffc6;
        if ((local_60 & 8) == 0) {
          iVar5 = *(int *)(iVar8 + -0x2c);
          bVar14 = iVar5 == local_58;
          iVar4 = local_58;
          if (bVar14) {
            iVar5 = *(int *)(iVar8 + -0x28);
            iVar4 = local_54;
          }
          if ((!bVar14 || iVar5 != iVar4) || (*(int *)(iVar8 + -0x24) != local_50))
          goto LAB_001bffc6;
        }
        else if ((local_58 != 0 || local_54 != 0) || local_50 != 0) goto LAB_001bffc6;
        _zip_dirent_finalize(auStack_64);
        iVar11 = iVar11 + 0x3c;
        iVar10 = iVar10 + 1;
      } while (iVar10 < param_2[1]);
    }
  }
  iVar10 = uVar13 - uVar12;
LAB_001bffec:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar10);
}

// ===== FUN_001c0434  @0x001c0434  (48 bytes)
void FUN_001c0434(uint param_1,FILE *param_2)

{
  putc(param_1 & 0xff,param_2);
  putc((param_1 & 0xffff) >> 8,param_2);
  putc((param_1 & 0xffffff) >> 0x10,param_2);
  putc(param_1 >> 0x18,param_2);
  return;
}

// ===== FUN_001c07be  @0x001c07be  (104 bytes)
char * FUN_001c07be(int *param_1,size_t param_2,int param_3,undefined4 param_4)

{
  size_t __size;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  __size = param_2;
  if (param_3 != 0) {
    __size = param_2 + 1;
  }
  pcVar1 = malloc(__size);
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)0x0;
    _zip_error_set(param_4,0xe,0);
  }
  else {
    iVar3 = *param_1;
    __aeabi_memcpy(pcVar1,iVar3,param_2);
    *param_1 = iVar3 + param_2;
    if ((param_3 != 0) && (pcVar1[param_2] = '\0', 0 < (int)param_2)) {
      pcVar2 = pcVar1;
      do {
        if (*pcVar2 == '\0') {
          *pcVar2 = ' ';
        }
        pcVar2 = pcVar2 + 1;
      } while (pcVar2 < pcVar1 + param_2);
    }
  }
  return pcVar1;
}

// ===== FUN_001c0826  @0x001c0826  (122 bytes)
char * FUN_001c0826(FILE *param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint __size;
  char *__ptr;
  size_t sVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  __size = param_2;
  if (param_3 != 0) {
    __size = param_2 + 1;
  }
  __ptr = malloc(__size);
  if (__ptr == (char *)0x0) {
    __ptr = (char *)0x0;
    _zip_error_set(param_4,0xe,0);
  }
  else {
    sVar1 = fread(__ptr,1,param_2,param_1);
    if (sVar1 < param_2) {
      free(__ptr);
      puVar2 = (undefined4 *)__errno();
      _zip_error_set(param_4,5,*puVar2);
      __ptr = (char *)0x0;
    }
    else if ((param_3 != 0) && (__ptr[param_2] = '\0', 0 < (int)param_2)) {
      pcVar3 = __ptr;
      do {
        if (*pcVar3 == '\0') {
          *pcVar3 = ' ';
        }
        pcVar3 = pcVar3 + 1;
      } while (pcVar3 < __ptr + param_2);
    }
  }
  return __ptr;
}

// ===== FUN_001c344e  @0x001c344e  (98 bytes)
uint * FUN_001c344e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = __cxa_get_globals();
  iVar3 = *(int *)(iVar1 + 8);
  if (iVar3 != 0) {
    if ((*(uint *)(iVar3 + 0x28) >> 8 | *(uint *)(iVar3 + 0x2c) << 0x18) == 0x47432b2b &&
        *(uint *)(iVar3 + 0x2c) >> 8 == 0x434c4e) {
      iVar2 = *(int *)(iVar3 + 0x20) + -1;
      *(int *)(iVar3 + 0x20) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar3 + 0x1c);
        *(undefined4 *)(iVar3 + 0x1c) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar1 + 8) = 0;
    }
    return (uint *)(iVar3 + 0x28);
  }
                    /* WARNING: Subroutine does not return */
  std::terminate();
}

// ===== FUN_001c3770  @0x001c3770  (36 bytes)
void FUN_001c3770(int param_1,int param_2)

{
  if (param_1 == 1) {
    __cxa_decrement_exception_refcount(*(undefined4 *)(param_2 + -0x28));
    FUN_001c46cc((undefined4 *)(param_2 + -0x28));
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_001c3a3c(*(undefined4 *)(param_2 + -0x18));
}

// ===== FUN_001c3840  @0x001c3840  (30 bytes)
void FUN_001c3840(void)

{
  int iVar1;
  
  iVar1 = pthread_key_create(&DAT_00270edc,(__destr_function *)0x1c386d);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("cannot create thread specific key for __cxa_get_globals()");
}

// ===== FUN_001c386c  @0x001c386c  (32 bytes)
void FUN_001c386c(void)

{
  int iVar1;
  
  FUN_001c46cc();
  iVar1 = pthread_setspecific(DAT_00270edc,(void *)0x0);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("cannot zero out thread value for __cxa_get_globals()");
}

// ===== FUN_001c39fc  @0x001c39fc  (14 bytes)
void FUN_001c39fc(code *param_1)

{
  (*param_1)();
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("unexpected_handler unexpectedly returned");
}

// ===== FUN_001c3a3c  @0x001c3a3c  (14 bytes)
void FUN_001c3a3c(code *param_1)

{
  (*param_1)();
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("terminate_handler unexpectedly returned");
}

// ===== FUN_001c3afc  @0x001c3afc  (68 bytes)
void FUN_001c3afc(size_t param_1)

{
  void *pvVar1;
  code *pcVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    pvVar1 = malloc(param_1);
    if (pvVar1 != (void *)0x0) {
      return;
    }
    pcVar2 = (code *)std::get_new_handler();
    if (pcVar2 == (code *)0x0) break;
    (*pcVar2)();
  }
  puVar3 = (undefined4 *)__cxa_allocate_exception(4);
  *puVar3 = &PTR__bad_array_length_00264c30;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar3,&std::bad_alloc::typeinfo,std::bad_array_length::~bad_array_length);
}

// ===== FUN_001c3dd4  @0x001c3dd4  (898 bytes)
void FUN_001c3dd4(int *param_1,uint param_2,int param_3,int *param_4,undefined4 param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int extraout_r3;
  uint uVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint uVar16;
  bool bVar17;
  byte *local_54;
  byte *local_38;
  byte *local_34;
  byte *local_30;
  byte *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  __aeabi_memclr8(param_1,0x18);
  uVar13 = param_2 & 1;
  param_1[6] = 3;
  if (uVar13 == 0) {
    if ((param_2 & 2) == 0) goto LAB_001c3e12;
    if ((param_2 & 0xc) != 0xc) goto LAB_001c3e3c;
    iVar5 = 2;
  }
  else if ((param_2 & 0xe) == 0) {
LAB_001c3e3c:
    pbVar3 = (byte *)_Unwind_GetLanguageSpecificData(param_5);
    if (pbVar3 != (byte *)0x0) {
      param_1[3] = (int)pbVar3;
      local_2c = (byte *)0x0;
      local_30 = pbVar3;
      _Unwind_VRS_Get(param_5,0,0xf,0,&local_2c);
      pbVar15 = local_2c;
      iVar4 = _Unwind_GetRegionStart(param_5);
      local_30 = pbVar3 + 1;
      iVar5 = FUN_001c43d8(&local_30,*pbVar3);
      pbVar3 = local_30 + 1;
      if (iVar5 == 0) {
        iVar5 = iVar4;
      }
      pbVar9 = (byte *)0x0;
      if (*local_30 != 0xff) {
        uVar11 = 0;
        pbVar14 = pbVar3;
        do {
          pbVar3 = pbVar14 + 1;
          bVar1 = *pbVar14;
          uVar11 = uVar11 | (bVar1 & 0x7f) << ((uint)pbVar9 & 0xff);
          pbVar9 = pbVar9 + 7;
          pbVar14 = pbVar3;
        } while ((bVar1 & 0x80) != 0);
        pbVar9 = pbVar3 + uVar11;
      }
      uVar16 = (((uint)pbVar15 & 0xfffffffe) - 1) - iVar4;
      uVar11 = 0;
      bVar1 = *pbVar3;
      uVar10 = 0;
      pbVar3 = pbVar3 + 1;
      do {
        local_2c = pbVar3 + 1;
        bVar2 = *pbVar3;
        uVar10 = uVar10 | (bVar2 & 0x7f) << (uVar11 & 0xff);
        uVar11 = uVar11 + 7;
        pbVar3 = local_2c;
      } while ((bVar2 & 0x80) != 0);
      pbVar3 = local_2c + uVar10;
      local_30 = local_2c;
      do {
        if (pbVar3 <= local_2c) break;
        uVar11 = FUN_001c43d8(&local_2c,bVar1);
        iVar4 = FUN_001c43d8(&local_2c,bVar1);
        iVar6 = FUN_001c43d8(&local_2c,bVar1);
        uVar12 = 0;
        uVar10 = 0;
        pbVar15 = local_2c;
        do {
          local_2c = pbVar15 + 1;
          bVar2 = *pbVar15;
          uVar10 = uVar10 | (bVar2 & 0x7f) << (uVar12 & 0xff);
          uVar12 = uVar12 + 7;
          pbVar15 = local_2c;
        } while ((bVar2 & 0x80) != 0);
        bVar17 = uVar16 <= uVar11;
        if (uVar11 <= uVar16) {
          bVar17 = iVar4 + uVar11 <= uVar16;
        }
        if (!bVar17) {
          if (iVar6 == 0) goto LAB_001c40d0;
          iVar6 = iVar6 + iVar5;
          if (uVar10 != 0) {
            pbVar3 = pbVar3 + (uVar10 - 1);
            bVar17 = (param_2 & 4) != 0;
            local_54 = (byte *)(param_4 + 0x16);
            uVar11 = param_2 & 8;
            goto LAB_001c3fbc;
          }
          if ((param_2 & 6) != 2) goto LAB_001c40d0;
          *param_1 = 0;
          param_1[1] = 0;
          iVar8 = 6;
          param_1[4] = iVar6;
          goto LAB_001c40d4;
        }
      } while (uVar11 <= uVar16);
                    /* WARNING: Subroutine does not return */
      FUN_001c4160(param_3,param_4);
    }
    iVar5 = 8;
    local_30 = (byte *)0x0;
  }
  else {
LAB_001c3e12:
    iVar5 = 3;
  }
  param_1[6] = iVar5;
LAB_001c3e18:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_001c3fbc:
  local_34 = pbVar3;
  iVar5 = FUN_001c4508(&local_34);
  iVar4 = iVar5 >> 0x1f;
  if (iVar5 < 1) {
    if (iVar5 < 0) {
      if (param_3 == 1) {
        pbVar15 = local_54;
        if (*param_4 == 0x432b2b01 && param_4[1] == 0x434c4e47) {
          pbVar15 = (byte *)param_4[-10];
        }
        iVar8 = extraout_r3;
        if (pbVar15 != (byte *)0x0) {
          iVar8 = param_4[-9];
        }
        if (pbVar15 == (byte *)0x0 || iVar8 == 0) goto LAB_001c4146;
        iVar8 = FUN_001c449c(iVar5,iVar4,pbVar9,iVar8,pbVar15,param_4);
        if (iVar8 == 1) {
          if (uVar13 != 0) {
            iVar8 = 6;
            *param_1 = iVar5;
            param_1[1] = iVar4;
            param_1[2] = (int)pbVar3;
            param_1[4] = iVar6;
            param_1[5] = (int)pbVar15;
            goto LAB_001c40d4;
          }
LAB_001c4090:
          if (uVar11 == 0) {
LAB_001c4146:
                    /* WARNING: Subroutine does not return */
            FUN_001c4160(1,param_4);
          }
        }
      }
      else {
        if (bVar17 || uVar13 != 0) goto LAB_001c40d8;
        if (uVar11 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_001c4160(0,param_4);
        }
      }
    }
    else if ((param_2 & 6) == 2) {
LAB_001c40d8:
      param_1[4] = iVar6;
      *param_1 = iVar5;
      param_1[1] = iVar4;
      param_1[2] = (int)pbVar3;
      if (*param_4 == 0x432b2b01 && param_4[1] == 0x434c4e47) {
        local_54 = (byte *)param_4[-10];
      }
      param_1[5] = (int)local_54;
      param_1[6] = 6;
      goto LAB_001c3e18;
    }
  }
  else {
    if (pbVar9 == (byte *)0x0) {
LAB_001c413e:
                    /* WARNING: Subroutine does not return */
      FUN_001c4160(param_3,param_4);
    }
    iVar8 = *(int *)(pbVar9 + iVar5 * -4);
    if ((iVar8 == 0) || (piVar7 = *(int **)(pbVar9 + iVar5 * -4 + iVar8), piVar7 == (int *)0x0)) {
      if (bVar17 || uVar13 != 0) goto LAB_001c40d8;
      if (uVar11 == 0) goto LAB_001c413e;
    }
    else if (param_3 == 1) {
      local_38 = local_54;
      if (*param_4 == 0x432b2b01 && param_4[1] == 0x434c4e47) {
        local_38 = (byte *)param_4[-10];
      }
      if ((local_38 == (byte *)0x0) || (param_4[-9] == 0)) goto LAB_001c4146;
      iVar8 = (**(code **)(*piVar7 + 0x10))(piVar7,param_4[-9],&local_38);
      if (iVar8 == 1) {
        if (uVar13 == 0) goto LAB_001c4090;
        *param_1 = iVar5;
        param_1[1] = iVar4;
        param_1[2] = (int)pbVar3;
        param_1[4] = iVar6;
        param_1[5] = (int)local_38;
        iVar8 = 6;
        goto LAB_001c40d4;
      }
    }
  }
  pbVar3 = local_34;
  local_38 = local_34;
  iVar5 = FUN_001c4508(&local_38);
  if (iVar5 == 0) goto LAB_001c40d0;
  pbVar3 = pbVar3 + iVar5;
  goto LAB_001c3fbc;
LAB_001c40d0:
  iVar8 = 8;
LAB_001c40d4:
  param_1[6] = iVar8;
  goto LAB_001c3e18;
}

// ===== FUN_001c4160  @0x001c4160  (30 bytes)
void FUN_001c4160(int param_1,int param_2)

{
  __cxa_begin_catch(param_2);
  if (param_1 != 1) {
                    /* WARNING: Subroutine does not return */
    std::terminate();
  }
                    /* WARNING: Subroutine does not return */
  FUN_001c3a3c(*(undefined4 *)(param_2 + -0x18));
}

// ===== FUN_001c4180  @0x001c4180  (130 bytes)
void FUN_001c4180(uint param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  uint local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_20 = param_1;
  _Unwind_VRS_Set(param_2,0,0,0,&local_20);
  local_20 = *param_3;
  _Unwind_VRS_Set(param_2,0,1,0,&local_20);
  uVar1 = param_3[4];
  local_20 = 0;
  _Unwind_VRS_Get(param_2,0,0xf,0,&local_20);
  local_20 = local_20 & 1 | uVar1;
  _Unwind_VRS_Set(param_2,0,0xf,0,&local_20);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_001c43d8  @0x001c43d8  (174 bytes)
void FUN_001c43d8(int *param_1,uint param_2)

{
  ushort uVar1;
  uint *puVar2;
  ushort *puVar3;
  uint uVar4;
  ushort *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (param_2 == 0xff) {
    puVar2 = (uint *)0x0;
    goto LAB_001c4476;
  }
  local_1c = (ushort *)*param_1;
  switch(param_2 & 0xf) {
  case 0:
  case 3:
  case 0xb:
    puVar2 = *(uint **)local_1c;
    local_1c = local_1c + 2;
    break;
  case 1:
    uVar4 = 0;
    puVar2 = (uint *)0x0;
    puVar3 = local_1c;
    do {
      local_1c = (ushort *)((int)puVar3 + 1);
      uVar1 = *puVar3;
      puVar2 = (uint *)((uint)puVar2 | ((byte)uVar1 & 0x7f) << (uVar4 & 0xff));
      uVar4 = uVar4 + 7;
      puVar3 = local_1c;
    } while (((byte)uVar1 & 0x80) != 0);
    break;
  case 2:
    puVar2 = (uint *)(uint)*local_1c;
    local_1c = local_1c + 1;
    break;
  case 4:
  case 0xc:
    puVar2 = *(uint **)local_1c;
    local_1c = local_1c + 4;
    break;
  default:
                    /* WARNING: Subroutine does not return */
    abort();
  case 9:
    puVar2 = (uint *)FUN_001c4508(&local_1c);
    break;
  case 10:
    puVar2 = (uint *)(int)(short)*local_1c;
    local_1c = local_1c + 1;
  }
  if ((param_2 & 0x70) == 0) {
LAB_001c4462:
    if ((param_2 & 0x80) != 0 && puVar2 != (uint *)0x0) {
      puVar2 = (uint *)*puVar2;
    }
  }
  else {
    if ((param_2 & 0x70) != 0x10) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    if (puVar2 != (uint *)0x0) {
      puVar2 = (uint *)((int)puVar2 + *param_1);
      goto LAB_001c4462;
    }
    puVar2 = (uint *)0x0;
  }
  *param_1 = (int)local_1c;
LAB_001c4476:
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(puVar2);
  }
  return;
}

// ===== FUN_001c449c  @0x001c449c  (100 bytes)
void FUN_001c449c(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_001c4160(0,param_6);
  }
  piVar4 = (int *)(param_3 + ~param_1 * 4);
  do {
    if (*piVar4 == 0) {
      uVar3 = 1;
      goto LAB_001c44e0;
    }
    piVar1 = *(int **)(*piVar4 + (int)piVar4);
    local_20 = param_5;
    iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,param_4,&local_20);
    piVar4 = piVar4 + 1;
  } while (iVar2 != 1);
  uVar3 = 0;
LAB_001c44e0:
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

// ===== FUN_001c4508  @0x001c4508  (64 bytes)
uint FUN_001c4508(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar6;
  byte *pbVar5;
  
  uVar3 = 0;
  uVar6 = 0;
  pbVar5 = (byte *)*param_1;
  do {
    pbVar4 = pbVar5 + 1;
    bVar1 = *pbVar5;
    uVar6 = uVar6 | (bVar1 & 0x7f) << (uVar3 & 0xff);
    uVar3 = uVar3 + 7;
    pbVar5 = pbVar4;
  } while ((bVar1 & 0x80) != 0);
  *param_1 = pbVar4;
  uVar2 = uVar6;
  if ((bVar1 & 0x40) != 0) {
    uVar2 = uVar6 | -1 << (uVar3 & 0xff);
  }
  if (0x1f < uVar3) {
    uVar2 = uVar6;
  }
  return uVar2;
}

// ===== FUN_001c458c  @0x001c458c  (24 bytes)
void FUN_001c458c(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 != (void *)0x0) {
    return;
  }
  FUN_001c45a4(param_1);
  return;
}

// ===== FUN_001c45a4  @0x001c45a4  (204 bytes)
void FUN_001c45a4(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  ushort *puVar6;
  undefined *local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  local_18 = &DAT_00270ef0;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_00270ef0);
  if (DAT_00270ef4 == (ushort *)0x0) {
    DAT_00270ef4 = (ushort *)&DAT_00270f00;
    DAT_00270f00 = 0x800080;
  }
  if ((DAT_00270ef4 != (ushort *)0x0) && (DAT_00270ef4 != (ushort *)S)) {
    uVar5 = (param_1 + 3U >> 2) + 1;
    puVar4 = DAT_00270ef4;
    puVar6 = (ushort *)0x0;
    while( true ) {
      puVar2 = puVar4;
      uVar1 = puVar2[1];
      uVar3 = (uint)uVar1;
      if (uVar5 <= uVar3 && uVar3 != uVar5) {
        uVar1 = uVar1 - (ushort)uVar5;
        puVar2[1] = uVar1;
        puVar2[(uint)uVar1 * 2] = 0;
        puVar2[(uint)uVar1 * 2 + 1] = (ushort)uVar5;
        goto LAB_001c4652;
      }
      if (uVar3 == uVar5) break;
      puVar4 = (ushort *)(&DAT_00270f00 + *puVar2);
      if ((puVar4 == (ushort *)0x0) || (puVar6 = puVar2, puVar4 == (ushort *)S)) goto LAB_001c4652;
    }
    if (puVar6 == (ushort *)0x0) {
      DAT_00270ef4 = (ushort *)(&DAT_00270f00 + *puVar2);
    }
    else {
      *puVar6 = *puVar2;
    }
    *puVar2 = 0;
  }
LAB_001c4652:
  FUN_001c4800(&local_18);
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== FUN_001c469c  @0x001c469c  (48 bytes)
void * FUN_001c469c(size_t param_1,size_t param_2)

{
  void *pvVar1;
  
  pvVar1 = calloc(param_1,param_2);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)FUN_001c45a4(param_1 * param_2);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      __aeabi_memclr(pvVar1,param_1 * param_2);
    }
  }
  return pvVar1;
}

// ===== FUN_001c46cc  @0x001c46cc  (252 bytes)
/* WARNING: Removing unreachable block (ram,0x001c4782) */

void FUN_001c46cc(undefined4 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined *local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if ((param_1 < &DAT_00270f00) || ((undefined4 *)0x2710ff < param_1)) {
    free(param_1);
    return;
  }
  local_24 = &DAT_00270ef0;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_00270ef0);
  puVar3 = (ushort *)(param_1 + -1);
  if ((DAT_00270ef4 != (ushort *)0x0) && (DAT_00270ef4 != (ushort *)S)) {
    uVar2 = *(ushort *)((int)param_1 + -2);
    puVar5 = (ushort *)0x0;
    puVar6 = DAT_00270ef4;
    do {
      uVar1 = puVar6[1];
      if (puVar6 + (uint)uVar1 * 2 == puVar3) {
        puVar6[1] = uVar1 + uVar2;
        goto LAB_001c47aa;
      }
      if (puVar3 + (uint)uVar2 * 2 == puVar6) {
        *(ushort *)((int)param_1 + -2) = uVar1 + uVar2;
        if (puVar5 == (ushort *)0x0) {
          DAT_00270ef4 = puVar3;
          *puVar3 = puVar3[(uint)uVar2 * 2];
        }
        else {
          *puVar5 = (ushort)((uint)(param_1 + -0x9c3c1) >> 2);
        }
        goto LAB_001c47aa;
      }
      puVar4 = (ushort *)(&DAT_00270f00 + *puVar6);
    } while ((puVar4 != (ushort *)0x0) && (puVar5 = puVar6, puVar6 = puVar4, puVar4 != (ushort *)S))
    ;
  }
  *puVar3 = (ushort)((uint)(DAT_00270ef4 + -0x138780) >> 2);
  DAT_00270ef4 = puVar3;
LAB_001c47aa:
  FUN_001c4800(&local_24);
  if (__stack_chk_guard == local_20) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== FUN_001c4800  @0x001c4800  (16 bytes)
undefined4 * FUN_001c4800(undefined4 *param_1)

{
  pthread_mutex_unlock((pthread_mutex_t *)*param_1);
  return param_1;
}

// ===== FUN_001c4818  @0x001c4818  (16 bytes)
void FUN_001c4818(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c482c  @0x001c482c  (16 bytes)
void FUN_001c482c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c483c  @0x001c483c  (16 bytes)
void FUN_001c483c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c484c  @0x001c484c  (16 bytes)
void FUN_001c484c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c485c  @0x001c485c  (16 bytes)
void FUN_001c485c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c486c  @0x001c486c  (16 bytes)
void FUN_001c486c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c487c  @0x001c487c  (16 bytes)
void FUN_001c487c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c488c  @0x001c488c  (16 bytes)
void FUN_001c488c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c489c  @0x001c489c  (16 bytes)
void FUN_001c489c(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c48ac  @0x001c48ac  (16 bytes)
void FUN_001c48ac(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c48bc  @0x001c48bc  (16 bytes)
void FUN_001c48bc(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c48cc  @0x001c48cc  (16 bytes)
void FUN_001c48cc(type_info *param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)std::type_info::~type_info(param_1);
  operator_delete(pvVar1);
  return;
}

// ===== FUN_001c48fc  @0x001c48fc  (140 bytes)
void FUN_001c48fc(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int *local_54;
  undefined1 auStack_50 [4];
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_3c;
  undefined4 local_24;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (((param_1 != param_2) && (param_2 != 0)) &&
     (piVar1 = (int *)__dynamic_cast(param_2,&__cxxabiv1::__shim_type_info::typeinfo,
                                     &__cxxabiv1::__class_type_info::typeinfo,0),
     piVar1 != (int *)0x0)) {
    __aeabi_memclr4(auStack_50,0x34);
    local_48 = 0xffffffff;
    local_24 = 1;
    local_54 = piVar1;
    local_4c = param_1;
    (**(code **)(*piVar1 + 0x1c))(piVar1,&local_54,*param_3,1);
    if (local_3c == 1) {
      *param_3 = local_44;
    }
  }
  if (__stack_chk_guard - local_1c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_1c);
}

// ===== FUN_001c4a46  @0x001c4a46  (54 bytes)
void FUN_001c4a46(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1[1];
  if (param_3 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)uVar1 >> 8;
    if ((uVar1 & 1) != 0) {
      iVar2 = *(int *)(*param_3 + iVar2);
    }
  }
  if ((uVar1 & 2) == 0) {
    param_4 = 2;
  }
                    /* WARNING: Could not recover jumptable at 0x001c4a7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,param_2,(int)param_3 + iVar2,param_4);
  return;
}

// ===== FUN_001c4a7c  @0x001c4a7c  (138 bytes)
void FUN_001c4a7c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == *(int *)(param_2 + 8)) {
    if (*(int *)(param_2 + 0x10) == 0) {
      *(int *)(param_2 + 0x10) = param_3;
      *(undefined4 *)(param_2 + 0x18) = param_4;
      *(undefined4 *)(param_2 + 0x24) = 1;
      return;
    }
    if (*(int *)(param_2 + 0x10) != param_3) {
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
      *(undefined4 *)(param_2 + 0x18) = 2;
      *(undefined1 *)(param_2 + 0x36) = 1;
      return;
    }
    if (*(int *)(param_2 + 0x18) == 2) {
      *(undefined4 *)(param_2 + 0x18) = param_4;
      return;
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc);
    FUN_001c4a46(param_1 + 0x10,param_2,param_3,param_4);
    if (iVar2 < 2) {
      return;
    }
    uVar1 = param_1 + 0x18;
    do {
      FUN_001c4a46(uVar1,param_2,param_3,param_4);
      if (*(char *)(param_2 + 0x36) != '\0') {
        return;
      }
      uVar1 = uVar1 + 8;
    } while (uVar1 < (uint)(param_1 + 0x10 + iVar2 * 8));
  }
  return;
}

// ===== FUN_001c4b08  @0x001c4b08  (84 bytes)
bool FUN_001c4b08(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 8) & 0x18) == 0) {
    if (param_2 == 0) {
      return false;
    }
    iVar1 = __dynamic_cast(param_2,&__cxxabiv1::__shim_type_info::typeinfo,
                           &__cxxabiv1::__pbase_type_info::typeinfo,0);
    if (iVar1 == 0) {
      return false;
    }
    if ((*(byte *)(iVar1 + 8) & 0x18) == 0) {
      return param_1 == param_2;
    }
  }
  iVar1 = strcmp(*(char **)(param_1 + 4),*(char **)(param_2 + 4));
  return iVar1 == 0;
}

// ===== FUN_001c4b64  @0x001c4b64  (432 bytes)
void FUN_001c4b64(int param_1,pointer_____offset_0x8___ *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  pointer_____offset_0x8___ *ppuVar3;
  int *piVar4;
  int *local_58;
  undefined1 auStack_54 [4];
  int local_50;
  undefined4 local_4c;
  int local_48;
  int local_40;
  undefined4 local_28;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (param_2 == &decltype(nullptr)::typeinfo) {
    local_48 = 0;
  }
  else {
    iVar1 = FUN_001c4b08(param_1,param_2);
    if (iVar1 == 1) {
      if ((int *)*param_3 == (int *)0x0) goto LAB_001c4cfa;
      local_48 = *(int *)*param_3;
    }
    else {
      if ((param_2 == (pointer_____offset_0x8___ *)0x0) ||
         (iVar1 = __dynamic_cast(param_2,&__cxxabiv1::__shim_type_info::typeinfo,
                                 &__cxxabiv1::__pointer_type_info::typeinfo,0), iVar1 == 0))
      goto LAB_001c4cfa;
      if ((int *)*param_3 != (int *)0x0) {
        *param_3 = *(int *)*param_3;
      }
      if ((((*(uint *)(iVar1 + 8) & ~*(uint *)(param_1 + 8)) != 0) ||
          (*(int *)(param_1 + 0xc) == *(int *)(iVar1 + 0xc))) ||
         (iVar2 = FUN_001c4d54(), iVar2 != 0)) goto LAB_001c4cfa;
      ppuVar3 = *(pointer_____offset_0x8___ **)(param_1 + 0xc);
      if (ppuVar3 == &void::typeinfo) {
        if (*(int *)(iVar1 + 0xc) != 0) {
          __dynamic_cast(*(int *)(iVar1 + 0xc),&__cxxabiv1::__shim_type_info::typeinfo,
                         &__cxxabiv1::__function_type_info::typeinfo,0);
        }
        goto LAB_001c4cfa;
      }
      if (ppuVar3 == (pointer_____offset_0x8___ *)0x0) goto LAB_001c4cfa;
      iVar2 = __dynamic_cast(ppuVar3,&__cxxabiv1::__shim_type_info::typeinfo,
                             &__cxxabiv1::__pointer_type_info::typeinfo,0);
      if (iVar2 != 0) {
        if ((*(byte *)(param_1 + 8) & 1) != 0) {
          FUN_001c4de0(iVar2,*(undefined4 *)(iVar1 + 0xc));
        }
        goto LAB_001c4cfa;
      }
      if (*(int *)(param_1 + 0xc) == 0) goto LAB_001c4cfa;
      iVar2 = __dynamic_cast(*(int *)(param_1 + 0xc),&__cxxabiv1::__shim_type_info::typeinfo,
                             &__cxxabiv1::__pointer_to_member_type_info::typeinfo,0);
      if (iVar2 != 0) {
        if ((*(byte *)(param_1 + 8) & 1) != 0) {
          FUN_001c4ea0(iVar2,*(undefined4 *)(iVar1 + 0xc));
        }
        goto LAB_001c4cfa;
      }
      if (((*(int *)(param_1 + 0xc) == 0) ||
          (iVar2 = __dynamic_cast(*(int *)(param_1 + 0xc),&__cxxabiv1::__shim_type_info::typeinfo,
                                  &__cxxabiv1::__class_type_info::typeinfo,0), iVar2 == 0)) ||
         ((*(int *)(iVar1 + 0xc) == 0 ||
          (piVar4 = (int *)__dynamic_cast(*(int *)(iVar1 + 0xc),
                                          &__cxxabiv1::__shim_type_info::typeinfo,
                                          &__cxxabiv1::__class_type_info::typeinfo,0),
          piVar4 == (int *)0x0)))) goto LAB_001c4cfa;
      __aeabi_memclr4(auStack_54,0x34);
      local_4c = 0xffffffff;
      local_28 = 1;
      local_58 = piVar4;
      local_50 = iVar2;
      (**(code **)(*piVar4 + 0x1c))(piVar4,&local_58,*param_3,1);
      if ((local_40 != 1) || (*param_3 == 0)) goto LAB_001c4cfa;
    }
  }
  *param_3 = local_48;
LAB_001c4cfa:
  if (__stack_chk_guard - local_20 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_20);
}

// ===== FUN_001c4d54  @0x001c4d54  (122 bytes)
bool FUN_001c4d54(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  if (param_1 != 0) {
    iVar1 = __dynamic_cast(param_1,&std::type_info::typeinfo,
                           &__cxxabiv1::__qualified_function_type_info::typeinfo,0);
    if (iVar1 == 0) {
      return false;
    }
    uVar2 = *(uint *)(iVar1 + 0xc);
    bVar4 = (uVar2 & 0xffffff1f) == 0;
    if (bVar4) {
      uVar2 = *(uint *)(iVar1 + 8);
    }
    if (bVar4 && uVar2 == param_2) {
      return true;
    }
    if (param_2 != 0) {
      iVar3 = __dynamic_cast(param_2,&std::type_info::typeinfo,
                             &__cxxabiv1::__qualified_function_type_info::typeinfo,0);
      if (iVar3 == 0) {
        return false;
      }
      if ((*(uint *)(iVar3 + 0xc) & ~*(uint *)(iVar1 + 0xc)) == 0) {
        if ((*(uint *)(iVar1 + 0xc) & ~*(uint *)(iVar3 + 0xc) & 0xffffff1f) != 0) {
          return false;
        }
        return *(int *)(iVar1 + 8) == *(int *)(iVar3 + 8);
      }
    }
  }
  return false;
}

// ===== FUN_001c4de0  @0x001c4de0  (168 bytes)
undefined4 FUN_001c4de0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    iVar1 = __dynamic_cast(param_2,&__cxxabiv1::__shim_type_info::typeinfo,
                           &__cxxabiv1::__pointer_type_info::typeinfo,0);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(uint *)(iVar1 + 8) & ~*(uint *)(param_1 + 8)) != 0) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar2 == *(int *)(iVar1 + 0xc)) break;
    if ((*(uint *)(param_1 + 8) & 1) == 0 || iVar2 == 0) {
      return 0;
    }
    iVar2 = __dynamic_cast(iVar2,&__cxxabiv1::__shim_type_info::typeinfo,
                           &__cxxabiv1::__pointer_type_info::typeinfo,0);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0xc) == 0) {
        return 0;
      }
      iVar2 = __dynamic_cast(*(int *)(param_1 + 0xc),&__cxxabiv1::__shim_type_info::typeinfo,
                             &__cxxabiv1::__pointer_to_member_type_info::typeinfo,0);
      if (iVar2 != 0) {
        uVar3 = FUN_001c4ea0(iVar2,*(undefined4 *)(iVar1 + 0xc));
        return uVar3;
      }
      return 0;
    }
    param_2 = *(int *)(iVar1 + 0xc);
    param_1 = iVar2;
  }
  return 1;
}

// ===== FUN_001c4ea0  @0x001c4ea0  (72 bytes)
bool FUN_001c4ea0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = __dynamic_cast(param_2,&__cxxabiv1::__shim_type_info::typeinfo,
                           &__cxxabiv1::__pointer_to_member_type_info::typeinfo,0);
    if (iVar1 == 0) {
      return false;
    }
    if ((*(uint *)(iVar1 + 8) & ~*(uint *)(param_1 + 8)) == 0) {
      if (*(int *)(param_1 + 0xc) != *(int *)(iVar1 + 0xc)) {
        return false;
      }
      return *(int *)(param_1 + 0x10) == *(int *)(iVar1 + 0x10);
    }
  }
  return false;
}

// ===== FUN_001c4ef0  @0x001c4ef0  (156 bytes)
bool FUN_001c4ef0(int param_1,pointer_____offset_0x8___ *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  if (param_2 == &decltype(nullptr)::typeinfo) {
    if (*(int *)(param_1 + 0xc) == 0) {
      puVar3 = &DAT_00261448;
    }
    else {
      iVar1 = __dynamic_cast(*(int *)(param_1 + 0xc),&__cxxabiv1::__shim_type_info::typeinfo,
                             &__cxxabiv1::__function_type_info::typeinfo,0);
      puVar3 = &UNK_00261440;
      if (iVar1 == 0) {
        puVar3 = &DAT_00261448;
      }
    }
    *param_3 = puVar3;
  }
  else {
    iVar1 = FUN_001c4b08(param_1,param_2);
    if (iVar1 == 0) {
      if (param_2 != (pointer_____offset_0x8___ *)0x0) {
        iVar1 = __dynamic_cast(param_2,&__cxxabiv1::__shim_type_info::typeinfo,
                               &__cxxabiv1::__pointer_to_member_type_info::typeinfo,0);
        if (iVar1 == 0) {
          return false;
        }
        if (((*(uint *)(iVar1 + 8) & ~*(uint *)(param_1 + 8)) == 0) &&
           ((*(int *)(param_1 + 0xc) == *(int *)(iVar1 + 0xc) ||
            (iVar2 = FUN_001c4d54(), iVar2 == 1)))) {
          return *(int *)(param_1 + 0x10) == *(int *)(iVar1 + 0x10);
        }
      }
      return false;
    }
  }
  return true;
}

// ===== FUN_001c50e4  @0x001c50e4  (458 bytes)
void FUN_001c50e4(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *__s1;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_5 == 1) {
    __s1 = *(char **)(param_1 + 4);
    iVar3 = strcmp(__s1,*(char **)(param_2[2] + 4));
    if (iVar3 == 0) {
LAB_001c517e:
      if (param_2[1] != param_3) {
        return;
      }
      if (param_2[7] == 1) {
        return;
      }
      param_2[7] = param_4;
      return;
    }
    iVar3 = strcmp(__s1,*(char **)(*param_2 + 4));
    if (iVar3 != 0) {
LAB_001c5126:
      iVar3 = *(int *)(param_1 + 0xc);
      FUN_001c52e4(param_1 + 0x10,param_2,param_3,param_4,param_5);
      if (iVar3 < 2) {
        return;
      }
      uVar5 = param_1 + 0x10 + iVar3 * 8;
      uVar4 = param_1 + 0x18;
      if (((*(uint *)(param_1 + 8) & 2) == 0) && (param_2[9] != 1)) {
        if ((*(uint *)(param_1 + 8) & 1) != 0) {
          while( true ) {
            if (*(char *)((int)param_2 + 0x36) != '\0') {
              return;
            }
            iVar3 = param_2[9];
            bVar6 = iVar3 == 1;
            if (bVar6) {
              iVar3 = param_2[6];
            }
            if (bVar6 && iVar3 == 1) break;
            FUN_001c52e4(uVar4,param_2,param_3,param_4,param_5);
            uVar4 = uVar4 + 8;
            if (uVar5 <= uVar4) {
              return;
            }
          }
          return;
        }
        while( true ) {
          if (*(char *)((int)param_2 + 0x36) != '\0') {
            return;
          }
          if (param_2[9] == 1) break;
          FUN_001c52e4(uVar4,param_2,param_3,param_4,param_5);
          uVar4 = uVar4 + 8;
          if (uVar5 <= uVar4) {
            return;
          }
        }
        return;
      }
      do {
        if (*(char *)((int)param_2 + 0x36) != '\0') {
          return;
        }
        FUN_001c52e4(uVar4,param_2,param_3,param_4,param_5);
        uVar4 = uVar4 + 8;
      } while (uVar4 < uVar5);
      return;
    }
  }
  else {
    if (param_1 == param_2[2]) goto LAB_001c517e;
    if (param_1 != *param_2) goto LAB_001c5126;
  }
  iVar3 = param_2[4];
  bVar6 = iVar3 != param_3;
  if (bVar6) {
    iVar3 = param_2[5];
  }
  if (!bVar6 || iVar3 == param_3) {
    if (param_4 != 1) {
      return;
    }
    param_2[8] = 1;
    return;
  }
  param_2[8] = param_4;
  if (param_2[0xb] == 4) {
    return;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  bVar6 = false;
  if (0 < iVar3) {
    uVar4 = param_1 + 0x10;
    bVar6 = false;
    bVar2 = false;
    do {
      *(undefined2 *)(param_2 + 0xd) = 0;
      FUN_001c52ae(uVar4,param_2,param_3,param_3,1,param_5);
      if (*(char *)((int)param_2 + 0x36) != '\0') break;
      if (*(char *)((int)param_2 + 0x35) != '\0') {
        if ((char)param_2[0xd] == '\0') {
          bVar6 = true;
          if ((*(byte *)(param_1 + 8) & 1) == 0) break;
        }
        else {
          bVar1 = 0;
          if (param_2[6] != 1) {
            bVar1 = *(byte *)(param_1 + 8);
          }
          if (param_2[6] == 1 || (bVar1 & 2) == 0) goto LAB_001c524c;
          bVar6 = true;
          bVar2 = true;
        }
      }
      uVar4 = uVar4 + 8;
    } while (uVar4 < param_1 + iVar3 * 8 + 0x10U);
    if (bVar2) goto LAB_001c5246;
  }
  param_2[5] = param_3;
  param_2[10] = param_2[10] + 1;
  if ((param_2[9] == 1) && (param_2[6] == 2)) {
    *(undefined1 *)((int)param_2 + 0x36) = 1;
  }
LAB_001c5246:
  if (bVar6) {
LAB_001c524c:
    iVar3 = 3;
  }
  else {
    iVar3 = 4;
  }
  param_2[0xb] = iVar3;
  return;
}

// ===== FUN_001c52ae  @0x001c52ae  (54 bytes)
void FUN_001c52ae(undefined4 *param_1)

{
  (**(code **)(*(int *)*param_1 + 0x14))();
  return;
}

// ===== FUN_001c52e4  @0x001c52e4  (52 bytes)
void FUN_001c52e4(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  iVar1 = (int)uVar2 >> 8;
  if ((uVar2 & 1) != 0) {
    iVar1 = *(int *)(*param_3 + iVar1);
  }
  if ((uVar2 & 2) == 0) {
    param_4 = 2;
  }
  (**(code **)(*(int *)*param_1 + 0x18))
            ((int *)*param_1,param_2,(int)param_3 + iVar1,param_4,param_5);
  return;
}

// ===== FUN_001c5318  @0x001c5318  (226 bytes)
void FUN_001c5318(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  char *__s1;
  bool bVar2;
  bool bVar3;
  
  if (param_5 == 1) {
    __s1 = *(char **)(param_1 + 4);
    iVar1 = strcmp(__s1,*(char **)(param_2[2] + 4));
    if (iVar1 == 0) {
LAB_001c536c:
      if (param_2[1] != param_3) {
        return;
      }
      if (param_2[7] == 1) {
        return;
      }
      param_2[7] = param_4;
      return;
    }
    iVar1 = strcmp(__s1,*(char **)(*param_2 + 4));
    if (iVar1 != 0) {
LAB_001c5358:
      (**(code **)(**(int **)(param_1 + 8) + 0x18))
                (*(int **)(param_1 + 8),param_2,param_3,param_4,param_5);
      return;
    }
  }
  else {
    if (param_1 == param_2[2]) goto LAB_001c536c;
    if (param_1 != *param_2) goto LAB_001c5358;
  }
  iVar1 = param_2[4];
  bVar2 = iVar1 != param_3;
  if (bVar2) {
    iVar1 = param_2[5];
  }
  if (!bVar2 || iVar1 == param_3) {
    if (param_4 != 1) {
      return;
    }
    param_2[8] = 1;
    return;
  }
  param_2[8] = param_4;
  if (param_2[0xb] == 4) {
    return;
  }
  bVar2 = false;
  *(undefined2 *)(param_2 + 0xd) = 0;
  (**(code **)(**(int **)(param_1 + 8) + 0x14))
            (*(int **)(param_1 + 8),param_2,param_3,param_3,1,param_5);
  if (*(char *)((int)param_2 + 0x35) == '\0') {
LAB_001c53c6:
    param_2[5] = param_3;
    param_2[10] = param_2[10] + 1;
    iVar1 = param_2[9];
    bVar3 = iVar1 == 1;
    if (bVar3) {
      iVar1 = param_2[6];
    }
    if (bVar3 && iVar1 == 2) {
      *(undefined1 *)((int)param_2 + 0x36) = 1;
    }
    if (!bVar2) {
      iVar1 = 4;
      goto LAB_001c53f2;
    }
  }
  else if ((char)param_2[0xd] == '\0') {
    bVar2 = true;
    goto LAB_001c53c6;
  }
  iVar1 = 3;
LAB_001c53f2:
  param_2[0xb] = iVar1;
  return;
}

// ===== FUN_001c53fa  @0x001c53fa  (146 bytes)
void FUN_001c53fa(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  char *__s1;
  bool bVar2;
  
  if (param_5 == 1) {
    __s1 = *(char **)(param_1 + 4);
    iVar1 = strcmp(__s1,*(char **)(param_2[2] + 4));
    if (iVar1 == 0) {
LAB_001c5450:
      if (param_2[1] != param_3) {
        return;
      }
      if (param_2[7] == 1) {
        return;
      }
      param_2[7] = param_4;
      return;
    }
    iVar1 = strcmp(__s1,*(char **)(*param_2 + 4));
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    if (param_1 == param_2[2]) goto LAB_001c5450;
    if (param_1 != *param_2) {
      return;
    }
  }
  iVar1 = param_2[4];
  bVar2 = iVar1 != param_3;
  if (bVar2) {
    iVar1 = param_2[5];
  }
  if (bVar2 && iVar1 != param_3) {
    param_2[8] = param_4;
    param_2[5] = param_3;
    param_2[10] = param_2[10] + 1;
    if ((param_2[9] == 1) && (param_2[6] == 2)) {
      *(undefined1 *)((int)param_2 + 0x36) = 1;
    }
    param_2[0xb] = 4;
    return;
  }
  if (param_4 == 1) {
    param_2[8] = 1;
    return;
  }
  return;
}

// ===== FUN_001c548c  @0x001c548c  (296 bytes)
void FUN_001c548c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  
  if (param_6 == 1) {
    iVar3 = strcmp(*(char **)(param_1 + 4),*(char **)(*(int *)(param_2 + 8) + 4));
    if (iVar3 != 0) {
LAB_001c54ba:
      iVar3 = *(int *)(param_1 + 0xc);
      uVar1 = *(undefined2 *)(param_2 + 0x34);
      *(undefined2 *)(param_2 + 0x34) = 0;
      FUN_001c52ae(param_1 + 0x10,param_2,param_3,param_4,param_5,param_6);
      if (1 < iVar3) {
        uVar4 = param_1 + 0x18;
        do {
          if (*(char *)(param_2 + 0x36) != '\0') break;
          if ((*(ushort *)(param_2 + 0x34) & 0xff) == 0) {
            if (0xff < *(ushort *)(param_2 + 0x34)) {
              bVar2 = *(byte *)(param_1 + 8) & 1;
              goto joined_r0x001c551e;
            }
          }
          else {
            if (*(int *)(param_2 + 0x18) == 1) break;
            bVar2 = *(byte *)(param_1 + 8) & 2;
joined_r0x001c551e:
            if (bVar2 == 0) break;
          }
          *(undefined2 *)(param_2 + 0x34) = 0;
          FUN_001c52ae(uVar4,param_2,param_3,param_4,param_5,param_6);
          uVar4 = uVar4 + 8;
        } while (uVar4 < (uint)(param_1 + 0x10 + iVar3 * 8));
      }
      *(char *)(param_2 + 0x34) = (char)uVar1;
      *(char *)(param_2 + 0x35) = (char)((ushort)uVar1 >> 8);
      return;
    }
  }
  else if (param_1 != *(int *)(param_2 + 8)) goto LAB_001c54ba;
  *(undefined1 *)(param_2 + 0x35) = 1;
  if (*(int *)(param_2 + 4) != param_4) {
    return;
  }
  *(undefined1 *)(param_2 + 0x34) = 1;
  if (*(int *)(param_2 + 0x10) == 0) {
    *(int *)(param_2 + 0x10) = param_3;
    *(int *)(param_2 + 0x18) = param_5;
    *(undefined4 *)(param_2 + 0x24) = 1;
    iVar3 = param_5;
    if (*(int *)(param_2 + 0x30) != 1) {
      return;
    }
  }
  else {
    if (*(int *)(param_2 + 0x10) != param_3) {
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
      goto LAB_001c50ca;
    }
    iVar3 = *(int *)(param_2 + 0x18);
    if (*(int *)(param_2 + 0x18) == 2) {
      *(int *)(param_2 + 0x18) = param_5;
      iVar3 = param_5;
    }
    if (*(int *)(param_2 + 0x30) != 1) {
      return;
    }
  }
  if (iVar3 != 1) {
    return;
  }
LAB_001c50ca:
  *(undefined1 *)(param_2 + 0x36) = 1;
  return;
}

// ===== FUN_001c555e  @0x001c555e  (82 bytes)
void FUN_001c555e(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_6 == 1) {
    iVar1 = strcmp(*(char **)(param_1 + 4),*(char **)(*(int *)(param_2 + 8) + 4));
    if (iVar1 != 0) {
LAB_001c5588:
      (**(code **)(**(int **)(param_1 + 8) + 0x14))
                (*(int **)(param_1 + 8),param_2,param_3,param_4,param_5,param_6);
      return;
    }
  }
  else if (param_1 != *(int *)(param_2 + 8)) goto LAB_001c5588;
  *(undefined1 *)(param_2 + 0x35) = 1;
  if (*(int *)(param_2 + 4) != param_4) {
    return;
  }
  *(undefined1 *)(param_2 + 0x34) = 1;
  if (*(int *)(param_2 + 0x10) == 0) {
    *(int *)(param_2 + 0x10) = param_3;
    *(int *)(param_2 + 0x18) = param_5;
    *(undefined4 *)(param_2 + 0x24) = 1;
    iVar1 = param_5;
    if (*(int *)(param_2 + 0x30) != 1) {
      return;
    }
  }
  else {
    if (*(int *)(param_2 + 0x10) != param_3) {
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
      goto LAB_001c50ca;
    }
    iVar1 = *(int *)(param_2 + 0x18);
    if (*(int *)(param_2 + 0x18) == 2) {
      *(int *)(param_2 + 0x18) = param_5;
      iVar1 = param_5;
    }
    if (*(int *)(param_2 + 0x30) != 1) {
      return;
    }
  }
  if (iVar1 != 1) {
    return;
  }
LAB_001c50ca:
  *(undefined1 *)(param_2 + 0x36) = 1;
  return;
}

// ===== FUN_001c55b0  @0x001c55b0  (56 bytes)
void FUN_001c55b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  
  if (param_6 == 1) {
    iVar1 = strcmp(*(char **)(param_1 + 4),*(char **)(*(int *)(param_2 + 8) + 4));
    if (iVar1 != 0) {
      return;
    }
  }
  else if (param_1 != *(int *)(param_2 + 8)) {
    return;
  }
  *(undefined1 *)(param_2 + 0x35) = 1;
  if (*(int *)(param_2 + 4) != param_4) {
    return;
  }
  *(undefined1 *)(param_2 + 0x34) = 1;
  if (*(int *)(param_2 + 0x10) == 0) {
    *(int *)(param_2 + 0x10) = param_3;
    *(int *)(param_2 + 0x18) = param_5;
    *(undefined4 *)(param_2 + 0x24) = 1;
    iVar1 = param_5;
    if (*(int *)(param_2 + 0x30) != 1) {
      return;
    }
  }
  else {
    if (*(int *)(param_2 + 0x10) != param_3) {
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
      goto LAB_001c50ca;
    }
    iVar1 = *(int *)(param_2 + 0x18);
    if (*(int *)(param_2 + 0x18) == 2) {
      *(int *)(param_2 + 0x18) = param_5;
      iVar1 = param_5;
    }
    if (*(int *)(param_2 + 0x30) != 1) {
      return;
    }
  }
  if (iVar1 != 1) {
    return;
  }
LAB_001c50ca:
  *(undefined1 *)(param_2 + 0x36) = 1;
  return;
}

// ===== FUN_001c5650  @0x001c5650  (84 bytes)
void FUN_001c5650(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *local_28;
  undefined4 *local_24;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_24 = &local_c;
  local_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_001d6628(glColorMask,param_1,&local_c);
  fputc(10,(FILE *)glColorMask);
  vasprintf(&local_28,param_1,&local_c);
  __assert2("/Volumes/Android/buildbot/src/android/ndk-r14-release/external/libcxx/../../external/libcxxabi/src/abort_message.cpp"
            ,0x4a,"void abort_message(const char *, ...)",local_28);
                    /* WARNING: Subroutine does not return */
  abort();
}

// ===== FUN_001c56b0  @0x001c56b0  (216 bytes)
void FUN_001c56b0(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_41c;
  undefined1 auStack_418 [1024];
  int iStack_18;
  int *piStack_14;
  
  piVar2 = (int *)__cxa_get_globals_fast();
  if ((piVar2 == (int *)0x0) || (piVar2 = (int *)*piVar2, piVar2 == (int *)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("terminating");
  }
  uVar5 = piVar2[0xb];
  if (uVar5 >> 8 != 0x434c4e || ((uint)piVar2[10] >> 8 | uVar5 << 0x18) != 0x47432b2b) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("terminating with %s foreign exception",DAT_0026b940);
  }
  if (uVar5 == 0x434c4e47 && piVar2[10] == 0x432b2b01) {
    piStack_14 = (int *)*piVar2;
  }
  else {
    piStack_14 = piVar2 + 0x20;
  }
  iVar6 = piVar2[1];
  local_41c = 0x400;
  uVar3 = __cxa_demangle(*(undefined4 *)(iVar6 + 4),auStack_418,&local_41c,&iStack_18);
  if (iStack_18 != 0) {
    uVar3 = *(undefined4 *)(iVar6 + 4);
  }
  iVar6 = FUN_001c48fc(&std::exception::typeinfo,iVar6,&piStack_14);
  uVar1 = DAT_0026b940;
  if (iVar6 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_001c5650("terminating with %s exception of type %s",DAT_0026b940,uVar3);
  }
  uVar4 = (**(code **)(*piStack_14 + 8))();
                    /* WARNING: Subroutine does not return */
  FUN_001c5650("terminating with %s exception of type %s: %s",uVar1,uVar3,uVar4);
}

// ===== FUN_001c57a8  @0x001c57a8  (18 bytes)
void FUN_001c57a8(void)

{
  DAT_0026b940 = "unexpected";
                    /* WARNING: Subroutine does not return */
  std::terminate();
}

// ===== FUN_001c5af8  @0x001c5af8  (572 bytes)
void FUN_001c5af8(byte *param_1,byte *param_2,int *param_3,int *param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  void *pvVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  void *__ptr;
  bool bVar12;
  uint local_58;
  uint uStack_54;
  byte *local_50;
  uint local_48;
  uint uStack_44;
  void *local_40;
  uint local_38;
  uint local_34;
  void *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 < param_2) {
    if (*param_1 != 0x5f) {
      pbVar2 = (byte *)FUN_001c6af0(param_1,param_2,param_3);
      goto LAB_001c5b80;
    }
    if (3 < (int)param_2 - (int)param_1) {
      if (param_1[1] == 0x5f) {
        bVar1 = param_1[2];
        bVar12 = bVar1 == 0x5f;
        if (bVar12) {
          bVar1 = param_1[3];
        }
        if ((bVar12 && bVar1 == 0x5a) &&
           (pbVar2 = (byte *)FUN_001c5f90(param_1 + 4,param_2,param_3),
           pbVar2 != param_1 + 4 && pbVar2 != param_2)) {
          if (0xc < (int)param_2 - (int)pbVar2) {
            iVar3 = 2;
            do {
              if (pbVar2[iVar3 + -2] != (&UNK_002224ad)[iVar3]) goto LAB_001c5b80;
              iVar7 = iVar3 + 1;
              iVar10 = iVar3 + -1;
              iVar3 = iVar7;
            } while (iVar10 < 0xd);
            pbVar4 = param_2;
            if (pbVar2 + (iVar7 - (int)param_2) != (byte *)0x2) {
              pbVar8 = pbVar2 + iVar7;
              if (pbVar8[-2] == 0x5f) {
                if ((pbVar2 + iVar7 + (1 - (int)param_2) == (byte *)0x2) || (9 < pbVar8[-1] - 0x30))
                goto LAB_001c5b80;
              }
              else {
                pbVar8 = pbVar8 + -2;
              }
              for (; (pbVar4 = param_2, pbVar8 != param_2 && (pbVar4 = pbVar8, *pbVar8 - 0x30 < 10))
                  ; pbVar8 = pbVar8 + 1) {
              }
            }
            if (*param_3 != param_3[1]) {
              FUN_001caf2a(param_3[1] + -0x18,0,"invocation function for block in ",0x21);
              pbVar2 = pbVar4;
            }
          }
LAB_001c5b80:
          if (pbVar2 == param_2) goto LAB_001c5cd0;
        }
      }
      else if (param_1[1] == 0x5a) {
        pbVar2 = (byte *)FUN_001c5f90(param_1 + 2,param_2,param_3);
        if (((pbVar2 == param_1 + 2 || pbVar2 == param_2) || (*pbVar2 != 0x2e)) ||
           (iVar3 = param_3[1], *param_3 == iVar3)) {
          if (pbVar2 != param_2) goto LAB_001c5cdc;
        }
        else {
          uVar11 = (int)param_2 - (int)pbVar2;
          local_50 = (byte *)0x0;
          local_58 = 0;
          uStack_54 = 0;
          if (uVar11 < 0xb) {
            local_58 = (uint)(byte)((char)uVar11 * '\x02');
            pbVar4 = (byte *)((uint)&local_58 | 1);
          }
          else {
            uVar9 = uVar11 + 0x10 & 0xfffffff0;
            pbVar4 = malloc(uVar9);
            local_58 = uVar9 | 1;
            uStack_54 = uVar11;
            local_50 = pbVar4;
          }
          *pbVar4 = 0x2e;
          pbVar8 = pbVar4;
          while (pbVar2 = pbVar2 + 1, pbVar2 != param_2) {
            pbVar8 = pbVar8 + 1;
            *pbVar8 = *pbVar2;
          }
          pbVar4[uVar11] = 0;
          puVar5 = (uint *)FUN_001caf2a(&local_58,0,&DAT_0022045a,2);
          local_48 = *puVar5;
          uStack_44 = puVar5[1];
          local_40 = (void *)puVar5[2];
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5 = (uint *)FUN_001cb080(&local_48,&DAT_0022045d,1);
          local_38 = *puVar5;
          local_34 = puVar5[1];
          __ptr = (void *)puVar5[2];
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          uVar11 = local_38 & 1;
          uVar9 = local_34;
          pvVar6 = __ptr;
          if ((local_38 & 1) == 0) {
            pvVar6 = (void *)((uint)&local_38 | 1);
            uVar9 = local_38 >> 1 & 0x7f;
          }
          local_30 = __ptr;
          FUN_001cb080(iVar3 + -0x18,pvVar6,uVar9);
          if (uVar11 != 0) {
            free(__ptr);
          }
          if ((local_48 & 1) != 0) {
            free(local_40);
          }
          if ((local_58 & 1) != 0) {
            free(local_50);
          }
        }
LAB_001c5cd0:
        if ((*param_4 != 0) || (*param_3 != param_3[1])) goto LAB_001c5ce2;
      }
    }
  }
LAB_001c5cdc:
  *param_4 = -2;
LAB_001c5ce2:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== FUN_001c5d4c  @0x001c5d4c  (48 bytes)
int * FUN_001c5d4c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = param_1[1];
    if (iVar1 != iVar2) {
      do {
        param_1[1] = iVar1 + -0x10;
        FUN_001c5d7c();
        iVar1 = param_1[1];
      } while (iVar1 != iVar2);
      iVar2 = *param_1;
    }
    FUN_001c5e0a(param_1[3],iVar2,param_1[2] - iVar2);
  }
  return param_1;
}

// ===== FUN_001c5d7c  @0x001c5d7c  (48 bytes)
int * FUN_001c5d7c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = param_1[1];
    if (iVar1 != iVar2) {
      do {
        param_1[1] = iVar1 + -0x10;
        FUN_001c5dac();
        iVar1 = param_1[1];
      } while (iVar1 != iVar2);
      iVar2 = *param_1;
    }
    FUN_001c5e0a(param_1[3],iVar2,param_1[2] - iVar2);
  }
  return param_1;
}

// ===== FUN_001c5dac  @0x001c5dac  (94 bytes)
int * FUN_001c5dac(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = param_1[1];
    if (iVar1 != iVar2) {
      do {
        param_1[1] = iVar1 + -0x18;
        if ((*(byte *)(iVar1 + -0xc) & 1) != 0) {
          free(*(void **)(iVar1 + -4));
        }
        if ((*(byte *)(iVar1 + -0x18) & 1) != 0) {
          free(*(void **)(iVar1 + -0x10));
        }
        iVar1 = param_1[1];
      } while (iVar1 != iVar2);
      iVar2 = *param_1;
    }
    FUN_001c5e0a(param_1[3],iVar2,param_1[2] - iVar2);
  }
  return param_1;
}

// ===== FUN_001c5e0a  @0x001c5e0a  (42 bytes)
void FUN_001c5e0a(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  if ((param_2 <= param_1 + 0x400) && (param_1 <= param_2)) {
    if ((param_3 + 0xfU & 0xfffffff0) + (int)param_2 == param_1[0x400]) {
      param_1[0x400] = param_2;
    }
    return;
  }
  free(param_2);
  return;
}

// ===== FUN_001c5e34  @0x001c5e34  (46 bytes)
undefined4 * FUN_001c5e34(undefined4 *param_1,byte *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if ((*param_2 & 1) == 0) {
    uVar1 = *(undefined4 *)(param_2 + 4);
    uVar2 = *(undefined4 *)(param_2 + 8);
    *param_1 = *(undefined4 *)param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
  }
  else {
    FUN_001c5e62(param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4));
  }
  return param_1;
}

// ===== FUN_001c5e62  @0x001c5e62  (72 bytes)
void FUN_001c5e62(uint *param_1,undefined4 param_2,uint param_3)

{
  undefined1 *puVar1;
  uint __size;
  
  if (param_3 < 0xb) {
    puVar1 = (undefined1 *)((int)param_1 + 1);
    *(char *)param_1 = (char)(param_3 << 1);
    if (param_3 == 0) goto LAB_001c5ea2;
  }
  else {
    __size = param_3 + 0x10 & 0xfffffff0;
    puVar1 = malloc(__size);
    *param_1 = __size | 1;
    param_1[1] = param_3;
    param_1[2] = (uint)puVar1;
  }
  __aeabi_memcpy(puVar1,param_2,param_3);
LAB_001c5ea2:
  puVar1[param_3] = 0;
  return;
}

// ===== FUN_001c5eaa  @0x001c5eaa  (76 bytes)
undefined4 * FUN_001c5eaa(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  void *pvVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar1 = (void *)0x0;
  param_1[3] = 0;
  param_1[4] = param_4;
  if (param_2 != 0) {
    puVar3 = (undefined4 *)(*param_4 + 0x1000);
    pvVar1 = *(void **)(*param_4 + 0x1000);
    if ((uint)((int)puVar3 - (int)pvVar1) < (uint)(param_2 << 4)) {
      pvVar1 = malloc(param_2 * 0x10);
    }
    else {
      *puVar3 = (void *)(param_2 * 0x10 + (int)pvVar1);
    }
  }
  pvVar2 = (void *)((int)pvVar1 + param_3 * 0x10);
  *param_1 = pvVar1;
  param_1[1] = pvVar2;
  param_1[2] = pvVar2;
  param_1[3] = (void *)((int)pvVar1 + param_2 * 0x10);
  return param_1;
}

// ===== FUN_001c5ef6  @0x001c5ef6  (108 bytes)
void FUN_001c5ef6(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)*param_1;
  if ((undefined4 *)param_1[1] == puVar5) {
    iVar3 = param_2[1];
  }
  else {
    iVar3 = param_2[1];
    puVar2 = (undefined4 *)param_1[1];
    do {
      *(undefined4 *)(iVar3 + -0x10) = 0;
      *(undefined4 *)(iVar3 + -0xc) = 0;
      uVar4 = puVar2[-1];
      *(undefined4 *)(iVar3 + -8) = 0;
      *(undefined4 *)(iVar3 + -4) = uVar4;
      puVar1 = puVar2 + -4;
      *(undefined4 *)(iVar3 + -0x10) = *puVar1;
      *(undefined4 *)(iVar3 + -0xc) = puVar2[-3];
      *(undefined4 *)(iVar3 + -8) = puVar2[-2];
      *puVar1 = 0;
      puVar2[-3] = 0;
      puVar2[-2] = 0;
      iVar3 = param_2[1] + -0x10;
      param_2[1] = iVar3;
      puVar2 = puVar1;
    } while (puVar5 != puVar1);
    puVar5 = (undefined4 *)*param_1;
  }
  *param_1 = iVar3;
  param_2[1] = puVar5;
  iVar3 = param_1[1];
  param_1[1] = param_2[2];
  param_2[2] = iVar3;
  iVar3 = param_1[2];
  param_1[2] = param_2[3];
  param_2[3] = iVar3;
  *param_2 = param_2[1];
  return;
}

// ===== FUN_001c5f62  @0x001c5f62  (44 bytes)
int * FUN_001c5f62(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  while (param_1[2] != iVar1) {
    param_1[2] = param_1[2] + -0x10;
    FUN_001c5d7c();
  }
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_001c5e0a(*(undefined4 *)param_1[4],iVar1,param_1[3] - iVar1);
  }
  return param_1;
}

// ===== FUN_001c5f90  @0x001c5f90  (2772 bytes)
void FUN_001c5f90(char *param_1,char *param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  bool bVar6;
  bool bVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  uint *puVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  int iVar16;
  uint uVar17;
  undefined1 *__ptr;
  int iVar18;
  uint uVar19;
  void *pvVar20;
  int iVar21;
  uint uVar22;
  undefined *puVar23;
  uint uVar24;
  int iVar25;
  undefined4 uVar26;
  uint uVar27;
  undefined1 *puVar28;
  void *pvVar29;
  uint uVar30;
  int iVar31;
  bool bVar32;
  uint local_98;
  uint local_70;
  uint local_6c;
  void *local_68;
  uint local_60;
  uint local_5c;
  void *local_58;
  uint local_50;
  uint local_4c;
  void *local_48;
  uint local_40;
  uint local_3c;
  undefined1 *local_38;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == param_2) goto LAB_001c63e0;
  iVar31 = param_3[0xe];
  param_3[0xe] = iVar31 + 1U;
  uVar2 = *(undefined1 *)((int)param_3 + 0x3d);
  if (1 < iVar31 + 1U) {
    *(undefined1 *)((int)param_3 + 0x3d) = 1;
  }
  cVar3 = *param_1;
  if (cVar3 == 'T' || cVar3 == 'G') {
    if (2 < (int)param_2 - (int)param_1) {
      if (cVar3 == 'G') {
        if (param_1[1] == 'R') {
          pcVar8 = (char *)FUN_001c9fb8(param_1 + 2,param_2,param_3,0);
          if ((pcVar8 != param_1 + 2) && (*param_3 != param_3[1])) {
            iVar9 = param_3[1] + -0x18;
            uVar26 = 0x18;
            pcVar8 = "reference temporary for ";
            goto LAB_001c6446;
          }
        }
        else if (((param_1[1] == 'V') &&
                 (pcVar8 = (char *)FUN_001c9fb8(param_1 + 2,param_2,param_3,0),
                 pcVar8 != param_1 + 2)) && (*param_3 != param_3[1])) {
          iVar9 = param_3[1] + -0x18;
          uVar26 = 0x13;
          pcVar8 = "guard variable for ";
LAB_001c6446:
          FUN_001caf2a(iVar9,0,pcVar8,uVar26);
        }
      }
      else if (cVar3 == 'T') {
        pbVar13 = (byte *)(param_1 + 1);
        bVar5 = *pbVar13;
        if (bVar5 < 0x54) {
          if (bVar5 == 0x43) {
            pcVar8 = (char *)FUN_001c6af0(param_1 + 2,param_2,param_3);
            if ((((pcVar8 != param_1 + 2) &&
                 (pcVar10 = (char *)FUN_001caeea(pcVar8,param_2),
                 pcVar10 != pcVar8 && pcVar10 != param_2)) && (*pcVar10 == '_')) &&
               ((pcVar8 = (char *)FUN_001c6af0(pcVar10 + 1,param_2,param_3), pcVar8 != pcVar10 + 1
                && (iVar9 = param_3[1], 1 < (uint)((iVar9 - *param_3 >> 3) * -0x55555555))))) {
              uVar24 = *(uint *)(iVar9 + -8);
              iVar18 = *(int *)(iVar9 + -4);
              if ((*(byte *)(iVar9 + -0xc) & 1) == 0) {
                iVar18 = iVar9 + -0xb;
                uVar24 = (uint)(*(byte *)(iVar9 + -0xc) >> 1);
              }
              puVar11 = (uint *)FUN_001cb080(iVar9 + -0x18,iVar18,uVar24);
              local_40 = *puVar11;
              local_3c = puVar11[1];
              local_38 = (undefined1 *)puVar11[2];
              *puVar11 = 0;
              puVar11[1] = 0;
              puVar11[2] = 0;
              iVar18 = param_3[1];
              iVar9 = iVar18;
              do {
                param_3[1] = iVar9 + -0x18;
                if ((*(byte *)(iVar9 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar9 + -4));
                }
                if ((*(byte *)(iVar9 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar9 + -0x10));
                }
                iVar9 = param_3[1];
              } while (iVar9 != iVar18 + -0x18);
              if (*param_3 != iVar18 + -0x18) {
                puVar11 = (uint *)FUN_001caf2a(&local_40,0,"construction vtable for ",0x18);
                local_60 = *puVar11;
                local_5c = puVar11[1];
                local_58 = (void *)puVar11[2];
                *puVar11 = 0;
                puVar11[1] = 0;
                puVar11[2] = 0;
                puVar11 = (uint *)FUN_001cb080(&local_60,&DAT_002221b1,4);
                local_50 = *puVar11;
                local_4c = puVar11[1];
                local_48 = (void *)puVar11[2];
                *puVar11 = 0;
                puVar11[1] = 0;
                puVar11[2] = 0;
                iVar12 = param_3[1];
                uVar24 = *(uint *)(iVar12 + -8);
                iVar9 = *(int *)(iVar12 + -4);
                if ((*(byte *)(iVar12 + -0xc) & 1) == 0) {
                  iVar9 = iVar12 + -0xb;
                  uVar24 = (uint)(*(byte *)(iVar12 + -0xc) >> 1);
                }
                puVar11 = (uint *)FUN_001cb080(iVar12 + -0x18,iVar9,uVar24);
                local_70 = *puVar11;
                local_6c = puVar11[1];
                pvVar29 = (void *)puVar11[2];
                *puVar11 = 0;
                puVar11[1] = 0;
                puVar11[2] = 0;
                uVar19 = local_70 & 1;
                uVar24 = local_6c;
                pvVar20 = pvVar29;
                if ((local_70 & 1) == 0) {
                  pvVar20 = (void *)((uint)&local_70 | 1);
                  uVar24 = local_70 >> 1 & 0x7f;
                }
                local_68 = pvVar29;
                pbVar13 = (byte *)FUN_001cb080(&local_50,pvVar20,uVar24);
                bVar5 = *pbVar13;
                __aeabi_memcpy(&local_30,pbVar13 + 1,7);
                uVar26 = *(undefined4 *)(pbVar13 + 8);
                pbVar13[0] = 0;
                pbVar13[1] = 0;
                pbVar13[2] = 0;
                pbVar13[3] = 0;
                pbVar13[4] = 0;
                pbVar13[5] = 0;
                pbVar13[6] = 0;
                pbVar13[7] = 0;
                pbVar13[8] = 0;
                pbVar13[9] = 0;
                pbVar13[10] = 0;
                pbVar13[0xb] = 0;
                puVar11 = (uint *)(iVar18 + -0x30);
                if ((*(byte *)puVar11 & 1) == 0) {
                  *(undefined2 *)(iVar18 + -0x30) = 0;
                }
                else {
                  puVar1 = (undefined4 *)(iVar18 + -0x28);
                  *(undefined1 *)*puVar1 = 0;
                  *(undefined4 *)(iVar18 + -0x2c) = 0;
                  uVar24 = (uint)*(byte *)(iVar18 + -0x30);
                  if ((*(byte *)(iVar18 + -0x30) & 1) == 0) {
                    uVar30 = 10;
                  }
                  else {
                    uVar24 = *puVar11;
                    uVar30 = (uVar24 & 0xfffffffe) - 1;
                  }
                  if ((uVar24 & 1) == 0) {
                    local_98 = (uVar24 & 0xff) >> 1;
                    if ((uVar24 & 0xff) < 0x16) {
                      uVar27 = 10;
                    }
                    else {
                      uVar27 = (local_98 + 0x10 & 0xf0) - 1;
                    }
                    bVar32 = true;
                  }
                  else {
                    uVar27 = 10;
                    local_98 = 0;
                    bVar32 = false;
                  }
                  if (uVar27 != uVar30) {
                    if (uVar27 == 10) {
                      puVar28 = (undefined1 *)*puVar1;
                      if (bVar32) {
                        __aeabi_memcpy((undefined1 *)(iVar18 + -0x2f),puVar28,
                                       ((uVar24 & 0xfe) >> 1) + 1);
                      }
                      else {
                        *(undefined1 *)(iVar18 + -0x2f) = *puVar28;
                      }
                      free(puVar28);
                      *(byte *)puVar11 = (byte)(local_98 << 1);
                    }
                    else {
                      puVar28 = malloc(uVar27 + 1);
                      if ((uVar30 < uVar27) || (puVar28 != (undefined1 *)0x0)) {
                        if (bVar32) {
                          __aeabi_memcpy(puVar28,iVar18 + -0x2f,((uVar24 & 0xfe) >> 1) + 1);
                        }
                        else {
                          __ptr = (undefined1 *)*puVar1;
                          *puVar28 = *__ptr;
                          free(__ptr);
                        }
                        *(uint *)(iVar18 + -0x30) = uVar27 + 1 | 1;
                        *(uint *)(iVar18 + -0x2c) = local_98;
                        *(undefined1 **)(iVar18 + -0x28) = puVar28;
                      }
                    }
                  }
                }
                *(byte *)puVar11 = bVar5;
                __aeabi_memcpy(iVar18 + -0x2f,&local_30,7);
                *(undefined4 *)(iVar18 + -0x28) = uVar26;
                local_2a = 0;
                local_2c = 0;
                local_30 = 0;
                if (uVar19 != 0) {
                  free(pvVar29);
                }
                if ((local_50 & 1) != 0) {
                  free(local_48);
                }
                if ((local_60 & 1) != 0) {
                  free(local_58);
                }
              }
              if ((local_40 & 1) != 0) {
                free(local_38);
              }
            }
          }
          else if (bVar5 == 0x49) {
            pcVar8 = (char *)FUN_001c6af0(param_1 + 2,param_2,param_3);
            if ((pcVar8 != param_1 + 2) && (*param_3 != param_3[1])) {
              iVar9 = param_3[1] + -0x18;
              uVar26 = 0xd;
              pcVar8 = "typeinfo for ";
              goto LAB_001c6446;
            }
          }
          else if (bVar5 == 0x53) {
            pcVar8 = (char *)FUN_001c6af0(param_1 + 2,param_2,param_3);
            if ((pcVar8 != param_1 + 2) && (*param_3 != param_3[1])) {
              iVar9 = param_3[1] + -0x18;
              uVar26 = 0x12;
              pcVar8 = "typeinfo name for ";
              goto LAB_001c6446;
            }
          }
          else {
LAB_001c636a:
            pbVar14 = (byte *)FUN_001cae94(pbVar13,param_2);
            if (((pbVar14 != pbVar13) &&
                (pbVar15 = (byte *)FUN_001c5f90(pbVar14,param_2,param_3), pbVar15 != pbVar14)) &&
               (*param_3 != param_3[1])) {
              if (*pbVar13 == 0x76) {
                uVar26 = 0x11;
                pcVar8 = "virtual thunk to ";
              }
              else {
                uVar26 = 0x15;
                pcVar8 = "non-virtual thunk to ";
              }
              FUN_001caf2a(param_3[1] + -0x18,0,pcVar8,uVar26);
            }
          }
        }
        else if (bVar5 == 0x54) {
          pcVar8 = (char *)FUN_001c6af0(param_1 + 2,param_2,param_3);
          if ((pcVar8 != param_1 + 2) && (*param_3 != param_3[1])) {
            iVar9 = param_3[1] + -0x18;
            uVar26 = 8;
            pcVar8 = "VTT for ";
            goto LAB_001c6446;
          }
        }
        else if (bVar5 == 99) {
          pcVar8 = (char *)FUN_001cae94(param_1 + 2,param_2);
          if (((pcVar8 != param_1 + 2) &&
              (pcVar10 = (char *)FUN_001cae94(pcVar8,param_2), pcVar10 != pcVar8)) &&
             ((pcVar8 = (char *)FUN_001c5f90(pcVar10,param_2,param_3), pcVar8 != pcVar10 &&
              (*param_3 != param_3[1])))) {
            iVar9 = param_3[1] + -0x18;
            uVar26 = 0x1a;
            pcVar8 = "covariant return thunk to ";
            goto LAB_001c6446;
          }
        }
        else {
          if (bVar5 != 0x56) goto LAB_001c636a;
          pcVar8 = (char *)FUN_001c6af0(param_1 + 2,param_2,param_3);
          if ((pcVar8 != param_1 + 2) && (*param_3 != param_3[1])) {
            iVar9 = param_3[1] + -0x18;
            uVar26 = 0xb;
            pcVar8 = "vtable for ";
            goto LAB_001c6446;
          }
        }
      }
    }
  }
  else {
    local_70 = local_70 & 0xffffff00;
    pcVar8 = (char *)FUN_001c9fb8(param_1,param_2,param_3,&local_70);
    if (((pcVar8 != param_1) && (pcVar8 != param_2)) && (*pcVar8 != '.' && *pcVar8 != 'E')) {
      uVar24 = param_3[0xc];
      iVar18 = param_3[0xd];
      uVar4 = *(undefined1 *)((int)param_3 + 0x3d);
      *(undefined1 *)((int)param_3 + 0x3d) = 0;
      local_38 = (undefined1 *)0x0;
      local_40 = 0;
      local_3c = 0;
      iVar9 = param_3[1];
      if (*param_3 == iVar9) {
LAB_001c65da:
        bVar32 = true;
      }
      else {
        bVar5 = *(byte *)(iVar9 + -0x18);
        bVar32 = (bVar5 & 1) == 0;
        if (bVar32) {
          bVar5 = bVar5 >> 1;
        }
        uVar19 = (uint)bVar5;
        if (!bVar32) {
          uVar19 = *(uint *)(iVar9 + -0x14);
        }
        if (uVar19 == 0) goto LAB_001c65da;
        if (((char)param_3[0xf] == '\0') && ((char)local_70 != '\0')) {
          pcVar10 = (char *)FUN_001c6af0(pcVar8,param_2,param_3);
          puVar28 = local_38;
          uVar19 = local_40;
          if ((pcVar10 != pcVar8) &&
             (iVar9 = param_3[1], 1 < (uint)((iVar9 - *param_3 >> 3) * -0x55555555))) {
            local_50 = *(uint *)(iVar9 + -0x18);
            local_4c = *(uint *)(iVar9 + -0x14);
            local_48 = *(void **)(iVar9 + -0x10);
            *(undefined4 *)(iVar9 + -0x18) = 0;
            *(undefined4 *)(iVar9 + -0x14) = 0;
            *(undefined4 *)(iVar9 + -0x10) = 0;
            iVar9 = param_3[1];
            if ((local_40 & 1) != 0) {
              *local_38 = 0;
              local_3c = 0;
              if ((local_40 & 1) == 0) {
                if (0x15 < (local_40 & 0xff)) {
                  uVar30 = (local_40 & 0xfffffffe) - 1;
                  uVar27 = ((local_40 & 0xff) >> 1) + 0x10 & 0xf0;
                  uVar22 = uVar27 - 1;
                  if ((uVar22 != uVar30) &&
                     ((pvVar20 = malloc(uVar27), uVar30 < uVar22 || (pvVar20 != (void *)0x0)))) {
                    __aeabi_memcpy(pvVar20,(uint)&local_40 | 1,((uVar19 & 0xff) >> 1) + 1);
                  }
                  goto LAB_001c651a;
                }
                __aeabi_memcpy((uint)&local_40 | 1,local_38,((local_40 & 0xff) >> 1) + 1);
              }
              else {
                local_40._0_2_ = (ushort)(byte)local_40;
              }
              free(puVar28);
            }
LAB_001c651a:
            local_40 = *(uint *)(iVar9 + -0xc);
            local_3c = *(uint *)(iVar9 + -8);
            local_38 = *(undefined1 **)(iVar9 + -4);
            *(uint *)(iVar9 + -0xc) = 0;
            *(undefined4 *)(iVar9 + -8) = 0;
            *(undefined4 *)(iVar9 + -4) = 0;
            uVar19 = *(uint *)((uint)&local_40 | 4);
            if ((local_40 & 1) == 0) {
              uVar19 = local_40 >> 1 & 0x7f;
            }
            if (uVar19 == 0) {
              FUN_001d530c(&local_50,0x20);
            }
            iVar12 = param_3[1];
            iVar9 = iVar12;
            do {
              param_3[1] = iVar9 + -0x18;
              if ((*(byte *)(iVar9 + -0xc) & 1) != 0) {
                free(*(void **)(iVar9 + -4));
              }
              if ((*(byte *)(iVar9 + -0x18) & 1) != 0) {
                free(*(void **)(iVar9 + -0x10));
              }
              iVar9 = param_3[1];
            } while (iVar9 != iVar12 + -0x18);
            if (*param_3 == iVar12 + -0x18) {
              bVar32 = true;
            }
            else {
              bVar32 = false;
              uVar19 = local_4c;
              pvVar20 = local_48;
              if ((local_50 & 1) == 0) {
                pvVar20 = (void *)((uint)&local_50 | 1);
                uVar19 = local_50 >> 1 & 0x7f;
              }
              FUN_001caf2a(iVar12 + -0x30,0,pvVar20,uVar19);
              pcVar8 = pcVar10;
            }
            if ((local_50 & 1) != 0) {
              free(local_48);
            }
            if (bVar32) goto LAB_001c65da;
            iVar9 = param_3[1];
            goto LAB_001c65e4;
          }
          bVar32 = true;
        }
        else {
LAB_001c65e4:
          FUN_001d530c(iVar9 + -0x18,0x28);
          if ((pcVar8 == param_2) || (*pcVar8 != 'v')) {
            bVar7 = true;
            do {
              iVar9 = *param_3;
              iVar12 = param_3[1];
              pcVar10 = pcVar8;
              do {
                pcVar8 = (char *)FUN_001c6af0(pcVar10,param_2,param_3);
                iVar21 = *param_3;
                iVar16 = param_3[1];
                if (pcVar8 == pcVar10) goto LAB_001c67c8;
                iVar25 = iVar12 - iVar9 >> 3;
                uVar30 = iVar25 * -0x55555555;
                uVar19 = (iVar16 - iVar21 >> 3) * -0x55555555;
                iVar9 = iVar21;
                iVar12 = iVar16;
                pcVar10 = pcVar8;
              } while (uVar19 < uVar30 || uVar19 + iVar25 * 0x55555555 == 0);
              iVar25 = iVar25 * 8;
              uVar22 = 0;
              local_48 = (void *)0x0;
              local_50 = 0;
              local_4c = 0;
              uVar27 = uVar30;
              while( true ) {
                uVar17 = local_4c;
                if ((uVar22 & 1) == 0) {
                  uVar17 = uVar22 >> 1;
                }
                if (uVar17 != 0) {
                  FUN_001cb080(&local_50,&DAT_00222122,2);
                }
                iVar12 = *param_3 + iVar25;
                uVar22 = *(uint *)(iVar12 + 0x10);
                iVar9 = *(int *)(iVar12 + 0x14);
                if ((*(byte *)(iVar12 + 0xc) & 1) == 0) {
                  iVar9 = iVar12 + 0xd;
                  uVar22 = (uint)(*(byte *)(iVar12 + 0xc) >> 1);
                }
                puVar11 = (uint *)FUN_001cb080(iVar12,iVar9,uVar22);
                local_60 = *puVar11;
                local_5c = puVar11[1];
                pvVar29 = (void *)puVar11[2];
                *puVar11 = 0;
                puVar11[1] = 0;
                puVar11[2] = 0;
                uVar22 = local_60 & 1;
                uVar17 = local_5c;
                pvVar20 = pvVar29;
                if ((local_60 & 1) == 0) {
                  pvVar20 = (void *)((uint)&local_60 | 1);
                  uVar17 = local_60 >> 1 & 0x7f;
                }
                local_58 = pvVar29;
                FUN_001cb080(&local_50,pvVar20,uVar17);
                if (uVar22 != 0) {
                  free(pvVar29);
                }
                uVar27 = uVar27 + 1;
                if (uVar19 == uVar27) break;
                iVar25 = iVar25 + 0x18;
                uVar22 = local_50 & 0xff;
              }
              iVar9 = param_3[1];
              do {
                if (*param_3 == iVar9) goto LAB_001c67a0;
                iVar12 = iVar9 + -0x18;
                do {
                  param_3[1] = iVar9 + -0x18;
                  if ((*(byte *)(iVar9 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar9 + -4));
                  }
                  if ((*(byte *)(iVar9 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar9 + -0x10));
                  }
                  iVar9 = param_3[1];
                } while (iVar9 != iVar12);
                uVar30 = uVar30 + 1;
                iVar9 = iVar12;
              } while (uVar30 < uVar19);
              uVar19 = local_4c;
              if ((local_50 & 1) == 0) {
                uVar19 = local_50 >> 1 & 0x7f;
              }
              if (uVar19 == 0) {
                bVar6 = false;
              }
              else {
                iVar9 = param_3[1];
                if (*param_3 == iVar9) {
LAB_001c67a0:
                  bVar6 = true;
                }
                else {
                  if (!bVar7) {
                    FUN_001cb080(iVar9 + -0x18,&DAT_00222122,2);
                    iVar9 = param_3[1];
                  }
                  pvVar20 = local_48;
                  uVar19 = local_4c;
                  if ((local_50 & 1) == 0) {
                    uVar19 = (local_50 & 0xff) >> 1;
                    pvVar20 = (void *)((uint)&local_50 | 1);
                  }
                  FUN_001cb080(iVar9 + -0x18,pvVar20,uVar19);
                  bVar6 = false;
                  bVar7 = false;
                }
              }
              if ((local_50 & 1) != 0) {
                free(local_48);
              }
              bVar32 = true;
            } while (!bVar6);
          }
          else {
            iVar21 = *param_3;
            iVar16 = param_3[1];
LAB_001c67c8:
            if (iVar21 == iVar16) {
              bVar32 = true;
            }
            else {
              FUN_001d530c(iVar16 + -0x18,0x29);
              if ((uVar24 & 1) != 0) {
                FUN_001cb080(param_3[1] + -0x18," const",6);
              }
              if ((uVar24 & 2) != 0) {
                FUN_001cb080(param_3[1] + -0x18," volatile",9);
              }
              if ((uVar24 & 4) != 0) {
                FUN_001cb080(param_3[1] + -0x18," restrict",9);
              }
              if (iVar18 == 2) {
                iVar9 = param_3[1];
                uVar26 = 3;
                puVar23 = &DAT_00222143;
LAB_001c6846:
                FUN_001cb080(iVar9 + -0x18,puVar23,uVar26);
              }
              else if (iVar18 == 1) {
                iVar9 = param_3[1];
                uVar26 = 2;
                puVar23 = &DAT_00222140;
                goto LAB_001c6846;
              }
              uVar24 = local_3c;
              puVar28 = local_38;
              if ((local_40 & 1) == 0) {
                puVar28 = (undefined1 *)((uint)&local_40 | 1);
                uVar24 = local_40 >> 1 & 0x7f;
              }
              FUN_001cb080(param_3[1] + -0x18,puVar28,uVar24);
              bVar32 = false;
            }
          }
        }
      }
      if ((local_40 & 1) != 0) {
        free(local_38);
      }
      *(undefined1 *)((int)param_3 + 0x3d) = uVar4;
      if (bVar32) {
        *(undefined1 *)((int)param_3 + 0x3d) = uVar2;
        param_3[0xe] = iVar31;
        goto LAB_001c63e0;
      }
    }
  }
  *(undefined1 *)((int)param_3 + 0x3d) = uVar2;
  param_3[0xe] = iVar31;
LAB_001c63e0:
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001c6af0  @0x001c6af0  (13138 bytes)
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_001c6af0(byte *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  uint uVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined1 *puVar12;
  uint *puVar13;
  ushort uVar14;
  int iVar15;
  uint uVar16;
  char *pcVar17;
  uint *puVar18;
  void *pvVar19;
  undefined *puVar20;
  int iVar21;
  undefined2 *puVar22;
  int iVar23;
  undefined1 *puVar24;
  int iVar25;
  void *pvVar26;
  byte *pbVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  byte *pbVar31;
  byte bVar32;
  byte *unaff_r9;
  uint uVar33;
  undefined *puVar34;
  bool bVar35;
  bool bVar36;
  undefined8 uVar37;
  uint local_d4;
  uint local_c8;
  uint local_c4;
  byte *local_c0;
  uint local_b0;
  uint local_ac;
  uint *local_a8;
  undefined4 local_a4;
  uint local_a0;
  char *local_9c;
  undefined4 local_98;
  undefined2 local_94;
  undefined1 local_92;
  uint local_90;
  undefined4 local_8c;
  void *pvStack_88;
  undefined4 local_80;
  undefined2 local_7c;
  undefined1 local_7a;
  undefined4 local_78;
  undefined2 local_74;
  undefined1 local_72;
  uint local_70;
  undefined4 local_6c;
  void *local_68;
  uint local_60;
  undefined4 local_5c;
  void *local_58;
  uint local_50;
  uint local_4c;
  void *local_48;
  undefined4 local_44;
  uint local_40;
  void *local_3c;
  uint local_38;
  uint local_34;
  uint *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == param_2) goto LAB_001c98c8;
  bVar32 = *param_1;
  bVar36 = false;
  local_c4 = 0xaaaaaaa;
  pbVar27 = param_1;
  if ((bVar32 == 0x4b) || (bVar32 == 0x56)) {
LAB_001c6b40:
    bVar35 = bVar32 == 0x56;
    if (bVar35) {
      pbVar27 = pbVar27 + 1;
      bVar32 = *pbVar27;
    }
    if (bVar32 == 0x4b) {
      pbVar27 = pbVar27 + 1;
    }
    if (pbVar27 != param_1) {
      iVar28 = *param_3;
      iVar23 = param_3[1];
      bVar2 = *pbVar27;
      pbVar4 = (byte *)FUN_001c6af0(pbVar27,param_2);
      if (pbVar4 != pbVar27) {
        iVar21 = *param_3;
        iVar15 = param_3[1];
        iVar23 = iVar23 - iVar28 >> 3;
        puVar5 = (undefined4 *)param_3[5];
        puVar10 = puVar5;
        if (bVar2 == 0x46) {
          puVar10 = puVar5 + -4;
          do {
            param_3[5] = (int)(puVar5 + -4);
            FUN_001c5dac();
            puVar5 = (undefined4 *)param_3[5];
          } while (puVar5 != puVar10);
        }
        uVar33 = param_3[3];
        uVar29 = (iVar15 - iVar21 >> 3) * -0x55555555;
        if (puVar10 < (undefined4 *)param_3[6]) {
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          puVar10[3] = uVar33;
          param_3[5] = param_3[5] + 0x10;
        }
        else {
          iVar28 = param_3[6] - param_3[4];
          iVar15 = (int)puVar10 - param_3[4] >> 4;
          if ((uint)(iVar28 >> 4) < 0x7ffffff) {
            uVar6 = iVar15 + 1;
            uVar16 = iVar28 >> 3;
            if (uVar16 < uVar6) {
              uVar16 = uVar6;
            }
          }
          else {
            uVar16 = 0xfffffff;
          }
          FUN_001d53d2(&local_b0,uVar16,iVar15,param_3 + 7);
          *local_a8 = 0;
          local_a8[1] = 0;
          local_a8[2] = 0;
          local_a8[3] = uVar33;
          local_a8 = local_a8 + 4;
          FUN_001d541e(param_3 + 4,&local_b0);
          FUN_001d548a(&local_b0);
        }
        if ((uint)(iVar23 * -0x55555555) < uVar29) {
          iVar28 = uVar29 + iVar23 * 0x55555555;
          iVar23 = iVar23 * 8 + 0xc;
          do {
            if (bVar2 == 0x46) {
              bVar1 = *(byte *)(*param_3 + iVar23);
              iVar15 = *param_3 + iVar23;
              if ((bVar1 & 1) == 0) {
                iVar21 = iVar15 + 1;
                uVar29 = (uint)(bVar1 >> 1);
              }
              else {
                uVar29 = *(uint *)(iVar15 + 4);
                iVar21 = *(int *)(iVar15 + 8);
              }
              if (*(char *)(iVar21 + (uVar29 - 2)) == '&') {
                uVar29 = uVar29 - 3;
              }
              else {
                if ((bVar1 & 1) == 0) {
                  iVar21 = iVar15 + 1;
                  uVar33 = (uint)(bVar1 >> 1);
                }
                else {
                  uVar33 = *(uint *)(iVar15 + 4);
                  iVar21 = *(int *)(iVar15 + 8);
                }
                if (*(char *)(uVar33 + iVar21 + -1) == '&') {
                  uVar29 = uVar29 - 2;
                }
              }
              if (bVar32 == 0x4b) {
                FUN_001caf2a(iVar15,uVar29," const",6);
                uVar29 = uVar29 + 6;
              }
              if (bVar35) {
                FUN_001caf2a(*param_3 + iVar23,uVar29," volatile",9);
                uVar29 = uVar29 + 9;
              }
              if (bVar36) {
                FUN_001caf2a(*param_3 + iVar23,uVar29," restrict",9);
              }
            }
            else {
              if (bVar32 == 0x4b) {
                FUN_001cb080(*param_3 + iVar23 + -0xc," const",6);
              }
              if (bVar35) {
                FUN_001cb080(*param_3 + iVar23 + -0xc," volatile",9);
              }
              if (bVar36) {
                FUN_001cb080(*param_3 + iVar23 + -0xc," restrict",9);
              }
            }
            iVar25 = *param_3;
            iVar21 = param_3[5];
            iVar15 = *(int *)(iVar21 + -0xc);
            if (iVar15 == *(int *)(iVar21 + -8)) {
              iVar15 = iVar15 - *(int *)(iVar21 + -0x10) >> 3;
              uVar33 = iVar15 * -0x55555555;
              uVar29 = 0xaaaaaaa;
              if (uVar33 < 0x5555555) {
                uVar29 = iVar15 * 0x55555556;
                if (uVar29 < uVar33 + 1) {
                  uVar29 = uVar33 + 1;
                }
              }
              FUN_001ccdd4(&local_b0,uVar29,uVar33,iVar21 + -4);
              iVar25 = iVar25 + iVar23;
              iVar15 = FUN_001c5e34(local_a8,iVar25 + -0xc);
              FUN_001c5e34(iVar15 + 0xc,iVar25);
              local_a8 = local_a8 + 6;
              FUN_001cce32(iVar21 + -0x10,&local_b0);
              FUN_001cceae(&local_b0);
            }
            else {
              iVar25 = iVar25 + iVar23;
              iVar15 = FUN_001c5e34(iVar15,iVar25 + -0xc);
              FUN_001c5e34(iVar15 + 0xc,iVar25);
              *(int *)(iVar21 + -0xc) = *(int *)(iVar21 + -0xc) + 0x18;
            }
            iVar23 = iVar23 + 0x18;
            iVar28 = iVar28 + -1;
          } while (iVar28 != 0);
        }
      }
    }
    goto LAB_001c98c8;
  }
  if (bVar32 == 0x72) {
    bVar36 = true;
    bVar32 = param_1[1];
    pbVar27 = param_1 + 1;
    goto LAB_001c6b40;
  }
  pbVar27 = (byte *)FUN_001d555c(param_1,param_2);
  if (pbVar27 != param_1) goto LAB_001c98c8;
  switch(*param_1) {
  case 0x41:
    pbVar27 = param_1 + 1;
    if (pbVar27 == param_2) break;
    if (*pbVar27 == 0x5f) {
      pbVar27 = param_1 + 2;
      uVar37 = FUN_001c6af0(pbVar27,param_2,param_3);
      pbVar31 = (byte *)uVar37;
      if (pbVar31 != pbVar27) {
        uVar37 = CONCAT44(*param_3,param_3[1]);
      }
      iVar23 = (int)uVar37;
      if (pbVar31 == pbVar27 || (int)((ulonglong)uVar37 >> 0x20) == iVar23) break;
      bVar36 = false;
      local_a8 = (uint *)0x0;
      local_b0 = 0;
      local_ac = 0;
      uVar29 = *(uint *)(iVar23 + -8);
      iVar28 = *(int *)(iVar23 + -4);
      if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
        iVar28 = iVar23 + -0xb;
        uVar29 = (uint)(*(byte *)(iVar23 + -0xc) >> 1);
      }
      if (1 < uVar29) {
        uVar29 = 2;
      }
      FUN_001c5e62(&local_b0,iVar28,uVar29);
      uVar29 = local_ac;
      if ((local_b0 & 1) == 0) {
        uVar29 = local_b0 >> 1 & 0x7f;
      }
      if (uVar29 == 2) {
        puVar13 = local_a8;
        if ((local_b0 & 1) == 0) {
          puVar13 = (uint *)((uint)&local_b0 | 1);
        }
        if ((short)*puVar13 == 0x5b20) {
          bVar36 = true;
        }
      }
      if ((local_b0 & 1) != 0) {
        free(local_a8);
      }
      if (bVar36) {
        FUN_001d64e8(param_3[1] + -0xc);
      }
      FUN_001caf2a(param_3[1] + -0xc,0,&DAT_0022251e,3);
    }
    else {
      if ((byte)(*pbVar27 - 0x31) < 9) {
        pbVar4 = (byte *)FUN_001caeea(pbVar27,param_2);
        if ((pbVar4 == param_2) || (*pbVar4 != 0x5f)) break;
        pbVar8 = pbVar4 + 1;
        uVar37 = FUN_001c6af0(pbVar8,param_2,param_3);
        pbVar31 = (byte *)uVar37;
        if (pbVar31 != pbVar8) {
          uVar37 = CONCAT44(*param_3,param_3[1]);
        }
        iVar23 = (int)uVar37;
        if (pbVar31 == pbVar8 || (int)((ulonglong)uVar37 >> 0x20) == iVar23) break;
        bVar36 = false;
        local_a8 = (uint *)0x0;
        local_b0 = 0;
        local_ac = 0;
        uVar29 = *(uint *)(iVar23 + -8);
        iVar28 = *(int *)(iVar23 + -4);
        if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
          iVar28 = iVar23 + -0xb;
          uVar29 = (uint)(*(byte *)(iVar23 + -0xc) >> 1);
        }
        if (1 < uVar29) {
          uVar29 = 2;
        }
        FUN_001c5e62(&local_b0,iVar28,uVar29);
        uVar29 = local_ac;
        if ((local_b0 & 1) == 0) {
          uVar29 = local_b0 >> 1 & 0x7f;
        }
        if (uVar29 == 2) {
          puVar13 = local_a8;
          if ((local_b0 & 1) == 0) {
            puVar13 = (uint *)((uint)&local_b0 | 1);
          }
          if (*(short *)puVar13 == 0x5b20) {
            bVar36 = true;
          }
        }
        if ((local_b0 & 1) != 0) {
          free(local_a8);
        }
        if (bVar36) {
          FUN_001d64e8(param_3[1] + -0xc);
        }
        uVar29 = (int)pbVar4 - (int)pbVar27;
        iVar23 = param_3[1];
        local_30 = (uint *)0x0;
        local_38 = 0;
        local_34 = 0;
        if (uVar29 < 0xb) {
          local_38 = (uint)(byte)((char)uVar29 * '\x02');
          puVar13 = (uint *)((uint)&local_38 | 1);
        }
        else {
          uVar33 = uVar29 + 0x10 & 0xfffffff0;
          puVar13 = malloc(uVar33);
          local_38 = uVar33 | 1;
          local_34 = uVar29;
          local_30 = puVar13;
        }
        puVar18 = puVar13;
        if (pbVar27 != pbVar4) {
          do {
            pbVar8 = pbVar27 + 1;
            *(byte *)puVar18 = *pbVar27;
            puVar18 = (uint *)((int)puVar18 + 1);
            pbVar27 = pbVar8;
          } while (pbVar4 != pbVar8);
          puVar13 = (uint *)((int)puVar13 + uVar29);
        }
        *(byte *)puVar13 = 0;
        puVar13 = (uint *)FUN_001caf2a(&local_38,0,&DAT_002213c5,2);
        local_50 = *puVar13;
        local_4c = puVar13[1];
        local_48 = (void *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13 = (uint *)FUN_001cb080(&local_50,&DAT_002213c8,1);
        local_b0 = *puVar13;
        local_ac = puVar13[1];
        local_a8 = (uint *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        uVar29 = local_ac;
        puVar13 = local_a8;
        if ((local_b0 & 1) == 0) {
          puVar13 = (uint *)((uint)&local_b0 | 1);
          uVar29 = local_b0 >> 1 & 0x7f;
        }
        FUN_001caf2a(iVar23 + -0xc,0,puVar13,uVar29);
        if ((local_b0 & 1) != 0) {
          free(local_a8);
        }
        puVar13 = local_30;
        uVar29 = local_38;
        if ((local_50 & 1) != 0) {
          free(local_48);
          puVar13 = local_30;
          uVar29 = local_38;
        }
      }
      else {
        pbVar4 = (byte *)FUN_001ccfb8(pbVar27,param_2,param_3);
        if (((pbVar4 == pbVar27 || pbVar4 == param_2) || (*pbVar4 != 0x5f)) ||
           ((pbVar31 = (byte *)FUN_001c6af0(pbVar4 + 1,param_2,param_3), pbVar31 == pbVar4 + 1 ||
            (iVar23 = param_3[1], (uint)((iVar23 - *param_3 >> 3) * -0x55555555) < 2)))) break;
        local_b0 = *(uint *)(iVar23 + -0x18);
        local_ac = *(undefined4 *)(iVar23 + -0x14);
        local_a8 = *(uint **)(iVar23 + -0x10);
        *(undefined4 *)(iVar23 + -0x10) = 0;
        *(undefined4 *)(iVar23 + -0x18) = 0;
        *(undefined4 *)(iVar23 + -0x14) = 0;
        local_a4 = *(uint *)(iVar23 + -0xc);
        local_a0 = *(uint *)(iVar23 + -8);
        local_9c = *(char **)(iVar23 + -4);
        *(undefined4 *)(iVar23 + -4) = 0;
        *(undefined4 *)(iVar23 + -0xc) = 0;
        *(undefined4 *)(iVar23 + -8) = 0;
        iVar28 = param_3[1];
        iVar23 = iVar28;
        do {
          param_3[1] = iVar23 + -0x18;
          if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
            free(*(void **)(iVar23 + -4));
          }
          if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
            free(*(void **)(iVar23 + -0x10));
          }
          iVar23 = param_3[1];
        } while (iVar23 != iVar28 + -0x18);
        local_50 = *(uint *)(iVar28 + -0x30);
        local_4c = *(uint *)(iVar28 + -0x2c);
        local_48 = *(void **)(iVar28 + -0x28);
        *(undefined4 *)(iVar28 + -0x28) = 0;
        *(undefined4 *)(iVar28 + -0x30) = 0;
        *(undefined4 *)(iVar28 + -0x2c) = 0;
        local_44 = *(uint *)(iVar28 + -0x24);
        local_40 = *(uint *)(iVar28 + -0x20);
        local_3c = *(void **)(iVar28 + -0x1c);
        *(undefined4 *)(iVar28 + -0x1c) = 0;
        *(undefined4 *)(iVar28 + -0x24) = 0;
        *(undefined4 *)(iVar28 + -0x20) = 0;
        iVar23 = param_3[1];
        puVar13 = (uint *)(iVar23 + -0x18);
        if ((*(byte *)puVar13 & 1) == 0) {
          *(undefined2 *)puVar13 = 0;
        }
        else {
          **(undefined1 **)(iVar23 + -0x10) = 0;
          *(undefined4 *)(iVar23 + -0x14) = 0;
          uVar29 = (uint)*(byte *)(iVar23 + -0x18);
          if ((*(byte *)(iVar23 + -0x18) & 1) == 0) {
            uVar33 = 10;
          }
          else {
            uVar29 = *puVar13;
            uVar33 = (uVar29 & 0xfffffffe) - 1;
          }
          if ((uVar29 & 1) == 0) {
            uVar6 = (uVar29 & 0xff) >> 1;
            if ((uVar29 & 0xff) < 0x16) {
              uVar16 = 10;
            }
            else {
              uVar16 = (uVar6 + 0x10 & 0xf0) - 1;
            }
            bVar36 = true;
          }
          else {
            uVar16 = 10;
            uVar6 = 0;
            bVar36 = false;
          }
          if (uVar16 != uVar33) {
            if (uVar16 == 10) {
              puVar24 = *(undefined1 **)(iVar23 + -0x10);
              if (bVar36) {
                __aeabi_memcpy((undefined1 *)(iVar23 + -0x17),puVar24,((uVar29 & 0xfe) >> 1) + 1);
              }
              else {
                *(undefined1 *)(iVar23 + -0x17) = *puVar24;
              }
              free(puVar24);
              *(byte *)puVar13 = (byte)(uVar6 << 1);
            }
            else {
              puVar24 = malloc(uVar16 + 1);
              if ((uVar33 < uVar16) || (puVar24 != (undefined1 *)0x0)) {
                if (bVar36) {
                  __aeabi_memcpy(puVar24,iVar23 + -0x17,((uVar29 & 0xfe) >> 1) + 1);
                }
                else {
                  puVar12 = *(undefined1 **)(iVar23 + -0x10);
                  *puVar24 = *puVar12;
                  free(puVar12);
                }
                *(uint *)(iVar23 + -0x18) = uVar16 + 1 | 1;
                *(uint *)(iVar23 + -0x14) = uVar6;
                *(undefined1 **)(iVar23 + -0x10) = puVar24;
              }
            }
          }
        }
        uVar29 = local_a0;
        bVar36 = false;
        *puVar13 = local_b0;
        *(uint *)(iVar23 + -0x14) = local_ac;
        *(uint **)(iVar23 + -0x10) = local_a8;
        local_a8 = (uint *)0x0;
        local_b0 = 0;
        local_ac = 0;
        local_30 = (uint *)0x0;
        local_38 = 0;
        local_34 = 0;
        bVar32 = (byte)local_a4;
        local_c0 = (byte *)local_9c;
        uVar33 = local_a0;
        pcVar17 = local_9c;
        if ((local_a4 & 1) == 0) {
          uVar33 = (uint)((byte)local_a4 >> 1);
          pcVar17 = (char *)((int)&local_a4 + 1);
        }
        if (1 < uVar33) {
          uVar33 = 2;
        }
        FUN_001c5e62(&local_38,pcVar17,uVar33);
        uVar33 = local_34;
        if ((local_38 & 1) == 0) {
          uVar33 = local_38 >> 1 & 0x7f;
        }
        if (uVar33 == 2) {
          puVar13 = local_30;
          if ((local_38 & 1) == 0) {
            puVar13 = (uint *)((uint)&local_38 | 1);
          }
          if (*(short *)puVar13 == 0x5b20) {
            bVar36 = true;
          }
        }
        if ((local_38 & 1) != 0) {
          free(local_30);
        }
        if (bVar36) {
          FUN_001d64e8(&local_a4);
          local_c0 = (byte *)local_9c;
          uVar29 = local_a0;
          bVar32 = (byte)local_a4;
        }
        iVar23 = param_3[1];
        uVar33 = local_40;
        pvVar26 = local_3c;
        if ((local_44 & 1) == 0) {
          pvVar26 = (void *)((int)&local_44 + 1);
          uVar33 = local_44 >> 1 & 0x7f;
        }
        puVar13 = (uint *)FUN_001cb080(&local_50,pvVar26,uVar33);
        local_70 = *puVar13;
        local_6c = puVar13[1];
        local_68 = (void *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13 = (uint *)FUN_001caf2a(&local_70,0,&DAT_002213c5,2);
        local_60 = *puVar13;
        local_5c = puVar13[1];
        local_58 = (void *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13 = (uint *)FUN_001cb080(&local_60,&DAT_002213c8,1);
        local_38 = *puVar13;
        local_34 = puVar13[1];
        local_30 = (uint *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        pbVar27 = local_c0;
        if ((bVar32 & 1) == 0) {
          uVar29 = (uint)(bVar32 >> 1);
          pbVar27 = (byte *)((int)&local_a4 + 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(&local_38,pbVar27,uVar29);
        uVar3 = *(undefined1 *)puVar10;
        __aeabi_memcpy(&local_90,(int)puVar10 + 1,7);
        uVar7 = puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar13 = (uint *)(iVar23 + -0xc);
        if ((*(byte *)puVar13 & 1) == 0) {
          *(undefined2 *)(iVar23 + -0xc) = 0;
        }
        else {
          puVar10 = (undefined4 *)(iVar23 + -4);
          *(undefined1 *)*puVar10 = 0;
          *(undefined4 *)(iVar23 + -8) = 0;
          uVar29 = (uint)*(byte *)(iVar23 + -0xc);
          if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
            uVar33 = 10;
          }
          else {
            uVar29 = *puVar13;
            uVar33 = (uVar29 & 0xfffffffe) - 1;
          }
          if ((uVar29 & 1) == 0) {
            uVar6 = (uVar29 & 0xff) >> 1;
            if ((uVar29 & 0xff) < 0x16) {
              uVar16 = 10;
            }
            else {
              uVar16 = (uVar6 + 0x10 & 0xf0) - 1;
            }
            bVar36 = true;
          }
          else {
            uVar16 = 10;
            uVar6 = 0;
            bVar36 = false;
          }
          if (uVar16 != uVar33) {
            if (uVar16 == 10) {
              puVar24 = (undefined1 *)*puVar10;
              if (bVar36) {
                __aeabi_memcpy((undefined1 *)(iVar23 + -0xb),puVar24,((uVar29 & 0xfe) >> 1) + 1);
              }
              else {
                *(undefined1 *)(iVar23 + -0xb) = *puVar24;
              }
              free(puVar24);
              *(byte *)puVar13 = (byte)(uVar6 << 1);
            }
            else {
              puVar24 = malloc(uVar16 + 1);
              if ((uVar33 < uVar16) || (puVar24 != (undefined1 *)0x0)) {
                if (bVar36) {
                  __aeabi_memcpy(puVar24,iVar23 + -0xb,((uVar29 & 0xfe) >> 1) + 1);
                }
                else {
                  puVar12 = (undefined1 *)*puVar10;
                  *puVar24 = *puVar12;
                  free(puVar12);
                }
                *(uint *)(iVar23 + -0xc) = uVar16 + 1 | 1;
                *(uint *)(iVar23 + -8) = uVar6;
                *(undefined1 **)(iVar23 + -4) = puVar24;
              }
            }
          }
        }
        *(undefined1 *)(iVar23 + -0xc) = uVar3;
        __aeabi_memcpy(iVar23 + -0xb,&local_90,7);
        *(undefined4 *)(iVar23 + -4) = uVar7;
        local_8c = (uint)local_8c._3_1_ << 0x18;
        local_90 = 0;
        if ((local_38 & 1) != 0) {
          free(local_30);
        }
        if ((local_60 & 1) != 0) {
          free(local_58);
        }
        if ((local_70 & 1) != 0) {
          free(local_68);
        }
        if ((local_44 & 1) != 0) {
          free(local_3c);
        }
        if ((local_50 & 1) != 0) {
          free(local_48);
        }
        puVar13 = local_a8;
        uVar29 = local_b0;
        if ((bVar32 & 1) != 0) {
          free(local_c0);
          puVar13 = local_a8;
          uVar29 = local_b0;
        }
      }
      if ((uVar29 & 1) != 0) {
        free(puVar13);
      }
    }
    if ((pbVar31 == param_1) || (*param_3 == param_3[1])) break;
    local_38 = param_3[3];
    FUN_001cb104(&local_50,param_3[1] + -0x18,&local_38);
    puVar13 = (uint *)param_3[5];
    if (puVar13 < (uint *)param_3[6]) {
LAB_001c9eac:
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = local_44;
      *puVar13 = local_50;
      puVar13[1] = local_4c;
      puVar13[2] = (uint)local_48;
      local_48 = (void *)0x0;
      local_4c = 0;
      local_50 = 0;
      param_3[5] = param_3[5] + 0x10;
    }
    else {
      iVar23 = param_3[6] - param_3[4];
      iVar28 = (int)puVar13 - param_3[4] >> 4;
      if ((uint)(iVar23 >> 4) < 0x7ffffff) {
        uVar33 = iVar28 + 1;
        uVar29 = iVar23 >> 3;
        if (uVar29 < uVar33) {
          uVar29 = uVar33;
        }
      }
      else {
        uVar29 = 0xfffffff;
      }
      FUN_001d53d2(&local_b0,uVar29,iVar28,param_3 + 7);
      *local_a8 = 0;
      local_a8[1] = 0;
      local_a8[2] = 0;
      local_a8[3] = local_44;
      *local_a8 = local_50;
      local_a8[1] = local_4c;
      local_a8[2] = (uint)local_48;
LAB_001c9f34:
      local_a8 = local_a8 + 4;
      local_48 = (void *)0x0;
      local_4c = 0;
      local_50 = 0;
      FUN_001d541e(param_3 + 4,&local_b0);
      FUN_001d548a(&local_b0);
    }
LAB_001c9f40:
    FUN_001c5dac(&local_50);
    break;
  case 0x43:
    pbVar27 = (byte *)FUN_001c6af0(param_1 + 1,param_2,param_3);
    if ((pbVar27 == param_1 + 1) || (iVar23 = param_3[1], *param_3 == iVar23)) break;
    uVar7 = 8;
    pcVar17 = " complex";
    goto LAB_001c7616;
  case 0x44:
    if (param_1 + 1 != param_2) {
      bVar32 = param_1[1];
      if (bVar32 < 0x74) {
        if (bVar32 == 0x54) {
LAB_001c7b3c:
          pbVar27 = (byte *)FUN_001cc0b8(param_1,param_2,param_3);
          if (pbVar27 != param_1) {
            if (*param_3 == param_3[1]) break;
            local_38 = param_3[3];
            FUN_001cb104(&local_50,param_3[1] + -0x18,&local_38);
            puVar13 = (uint *)param_3[5];
            puVar18 = (uint *)param_3[6];
            if (puVar13 < puVar18) goto LAB_001c9eac;
LAB_001c9b20:
            iVar23 = (int)puVar18 - param_3[4];
            iVar28 = (int)puVar13 - param_3[4] >> 4;
            if ((uint)(iVar23 >> 4) < 0x7ffffff) {
              uVar33 = iVar28 + 1;
              uVar29 = iVar23 >> 3;
              if (uVar29 < uVar33) {
                uVar29 = uVar33;
              }
            }
            else {
              uVar29 = 0xfffffff;
            }
            FUN_001d53d2(&local_b0,uVar29,iVar28,param_3 + 7);
            *local_a8 = 0;
            local_a8[1] = 0;
            local_a8[2] = 0;
            local_a8[3] = local_44;
            *local_a8 = local_50;
            local_a8[1] = local_4c;
            local_a8[2] = (uint)local_48;
            goto LAB_001c9f34;
          }
        }
        else if (bVar32 == 0x70) {
          iVar23 = *param_3;
          iVar28 = param_3[1];
          pbVar27 = (byte *)FUN_001c6af0(param_1 + 2,param_2);
          if (pbVar27 != param_1 + 2) {
            iVar23 = iVar28 - iVar23 >> 3;
            uVar29 = param_3[3];
            uVar33 = (param_3[1] - *param_3 >> 3) * -0x55555555;
            puVar10 = (undefined4 *)param_3[5];
            if (puVar10 < (undefined4 *)param_3[6]) {
              *puVar10 = 0;
              puVar10[1] = 0;
              puVar10[2] = 0;
              puVar10[3] = uVar29;
              param_3[5] = param_3[5] + 0x10;
            }
            else {
              iVar28 = param_3[6] - param_3[4];
              iVar15 = (int)puVar10 - param_3[4] >> 4;
              if ((uint)(iVar28 >> 4) < 0x7ffffff) {
                uVar6 = iVar15 + 1;
                uVar16 = iVar28 >> 3;
                if (uVar16 < uVar6) {
                  uVar16 = uVar6;
                }
              }
              else {
                uVar16 = 0xfffffff;
              }
              FUN_001d53d2(&local_b0,uVar16,iVar15,param_3 + 7);
              *local_a8 = 0;
              local_a8[1] = 0;
              local_a8[2] = 0;
              local_a8[3] = uVar29;
              local_a8 = local_a8 + 4;
              FUN_001d541e(param_3 + 4,&local_b0);
              FUN_001d548a(&local_b0);
            }
            if ((uint)(iVar23 * -0x55555555) < uVar33) {
              iVar28 = uVar33 + iVar23 * 0x55555555;
              iVar23 = iVar23 * 8;
              do {
                iVar25 = param_3[5];
                iVar21 = *param_3;
                iVar15 = *(int *)(iVar25 + -0xc);
                if (iVar15 == *(int *)(iVar25 + -8)) {
                  iVar15 = iVar15 - *(int *)(iVar25 + -0x10) >> 3;
                  uVar33 = iVar15 * -0x55555555;
                  uVar29 = 0xaaaaaaa;
                  if (uVar33 < 0x5555555) {
                    uVar29 = iVar15 * 0x55555556;
                    if (uVar29 < uVar33 + 1) {
                      uVar29 = uVar33 + 1;
                    }
                  }
                  FUN_001ccdd4(&local_b0,uVar29,uVar33,iVar25 + -4);
                  iVar21 = iVar21 + iVar23;
                  iVar15 = FUN_001c5e34(local_a8,iVar21);
                  FUN_001c5e34(iVar15 + 0xc,iVar21 + 0xc);
                  local_a8 = local_a8 + 6;
                  FUN_001cce32(iVar25 + -0x10,&local_b0);
                  FUN_001cceae(&local_b0);
                }
                else {
                  iVar21 = iVar21 + iVar23;
                  iVar15 = FUN_001c5e34(iVar15,iVar21);
                  FUN_001c5e34(iVar15 + 0xc,iVar21 + 0xc);
                  *(int *)(iVar25 + -0xc) = *(int *)(iVar25 + -0xc) + 0x18;
                }
                iVar23 = iVar23 + 0x18;
                iVar28 = iVar28 + -1;
              } while (iVar28 != 0);
            }
            break;
          }
        }
      }
      else {
        if (bVar32 == 0x74) goto LAB_001c7b3c;
        if ((bVar32 == 0x76) && (3 < (int)param_2 - (int)param_1)) {
          pbVar27 = param_1 + 2;
          if ((byte)(*pbVar27 - 0x31) < 9) {
            pbVar4 = (byte *)FUN_001caeea(pbVar27,param_2);
            if (((pbVar4 != param_2) && (*pbVar4 == 0x5f)) &&
               (pbVar8 = pbVar4 + 1, pbVar8 != param_2)) {
              if (*pbVar8 == 0x70) {
                local_30 = (uint *)0x0;
                local_38 = 0;
                local_34 = 0;
                FUN_001c5e62(&local_38,pbVar27,(int)pbVar4 - (int)pbVar27);
                puVar13 = (uint *)FUN_001caf2a(&local_38,0,"pixel vector[",0xd);
                local_50 = *puVar13;
                local_4c = puVar13[1];
                local_48 = (void *)puVar13[2];
                *puVar13 = 0;
                puVar13[1] = 0;
                puVar13[2] = 0;
                pbVar27 = (byte *)FUN_001cb080(&local_50,&DAT_002213c8,1,&local_44);
                bVar32 = *pbVar27;
                __aeabi_memcpy(&local_90,pbVar27 + 1,7);
                uVar29 = *(uint *)(pbVar27 + 8);
                pbVar27[0] = 0;
                pbVar27[1] = 0;
                pbVar27[2] = 0;
                pbVar27[3] = 0;
                pbVar27[4] = 0;
                pbVar27[5] = 0;
                pbVar27[6] = 0;
                pbVar27[7] = 0;
                pbVar27[8] = 0;
                pbVar27[9] = 0;
                pbVar27[10] = 0;
                pbVar27[0xb] = 0;
                __aeabi_memcpy(&local_60,&local_90,7);
                local_8c = (uint)local_8c._3_1_ << 0x18;
                local_6c = (uint)local_6c._3_1_ << 0x18;
                local_90 = 0;
                local_70 = 0;
                pbVar27 = (byte *)param_3[1];
                if (pbVar27 < (byte *)param_3[2]) {
                  *pbVar27 = bVar32;
                  __aeabi_memcpy(pbVar27 + 1,&local_60,7);
                  *(uint *)(pbVar27 + 8) = uVar29;
                  local_5c = (uint)local_5c._3_1_ << 0x18;
                  local_60 = 0;
                  pbVar27[0xc] = 0;
                  __aeabi_memcpy(pbVar27 + 0xd,&local_70,7);
                  pbVar27[0x14] = 0;
                  pbVar27[0x15] = 0;
                  pbVar27[0x16] = 0;
                  pbVar27[0x17] = 0;
                  local_6c = local_6c & 0xff000000;
                  local_70 = 0;
                  param_3[1] = param_3[1] + 0x18;
                }
                else {
                  iVar23 = param_3[2] - *param_3 >> 3;
                  iVar28 = ((int)pbVar27 - *param_3 >> 3) * -0x55555555;
                  if ((uint)(iVar23 * -0x55555555) < 0x5555555) {
                    uVar33 = iVar28 + 1;
                    local_c4 = iVar23 * 0x55555556;
                    if (local_c4 < uVar33) {
                      local_c4 = uVar33;
                    }
                  }
                  FUN_001ccdd4(&local_b0,local_c4,iVar28,param_3 + 3);
                  puVar13 = local_a8;
                  *(byte *)local_a8 = bVar32;
                  __aeabi_memcpy((byte *)((int)local_a8 + 1),&local_60,7);
                  puVar13[2] = uVar29;
                  local_5c = (uint)local_5c._3_1_ << 0x18;
                  local_60 = 0;
                  *(byte *)(puVar13 + 3) = 0;
                  __aeabi_memcpy((byte *)((int)puVar13 + 0xd),&local_70,7);
                  puVar13[5] = 0;
                  local_a8 = local_a8 + 6;
                  local_6c = local_6c & 0xff000000;
                  local_70 = 0;
                  FUN_001cce32(param_3,&local_b0);
                  FUN_001cceae(&local_b0);
                }
                if ((local_50 & 1) != 0) {
                  free(local_48);
                }
                pbVar31 = pbVar4 + 2;
              }
              else {
                pbVar31 = (byte *)FUN_001c6af0(pbVar8,param_2,param_3);
                pbVar11 = pbVar31;
                if (pbVar31 != pbVar8) {
                  pbVar11 = (byte *)*param_3;
                  unaff_r9 = (byte *)param_3[1];
                }
                if (pbVar31 == pbVar8 || pbVar11 == unaff_r9) goto switchD_001c6c02_caseD_42;
                local_30 = (uint *)0x0;
                local_38 = 0;
                local_34 = 0;
                FUN_001c5e62(&local_38,pbVar27,(int)pbVar4 - (int)pbVar27);
                puVar13 = (uint *)FUN_001caf2a(&local_38,0," vector[",8);
                local_50 = *puVar13;
                local_4c = puVar13[1];
                local_48 = (void *)puVar13[2];
                *puVar13 = 0;
                puVar13[1] = 0;
                puVar13[2] = 0;
                puVar13 = (uint *)FUN_001cb080(&local_50,&DAT_002213c8,1,&local_44);
                local_b0 = *puVar13;
                local_ac = puVar13[1];
                puVar18 = (uint *)puVar13[2];
                *puVar13 = 0;
                puVar13[1] = 0;
                puVar13[2] = 0;
                uVar29 = local_b0 & 1;
                uVar33 = local_ac;
                puVar13 = puVar18;
                if ((local_b0 & 1) == 0) {
                  puVar13 = (uint *)((uint)&local_b0 | 1);
                  uVar33 = local_b0 >> 1 & 0x7f;
                }
                local_a8 = puVar18;
                FUN_001cb080(unaff_r9 + -0x18,puVar13,uVar33);
                if (uVar29 != 0) {
                  free(puVar18);
                }
                if ((local_50 & 1) != 0) {
                  free(local_48);
                }
              }
              if ((local_38 & 1) != 0) {
                free(local_30);
              }
LAB_001c9990:
              if (pbVar31 != param_1) {
                if (*param_3 == param_3[1]) break;
                local_38 = param_3[3];
                FUN_001cb104(&local_50,param_3[1] + -0x18,&local_38);
                puVar13 = (uint *)param_3[5];
                puVar18 = (uint *)param_3[6];
                if (puVar18 <= puVar13) goto LAB_001c9b20;
                *puVar13 = 0;
                puVar13[1] = 0;
                puVar13[2] = 0;
                puVar13[3] = local_44;
                *puVar13 = local_50;
                puVar13[1] = local_4c;
                puVar13[2] = (uint)local_48;
                local_48 = (void *)0x0;
                local_50 = 0;
                local_4c = 0;
                param_3[5] = param_3[5] + 0x10;
                goto LAB_001c9f40;
              }
            }
          }
          else {
            local_a8 = (uint *)0x0;
            local_b0 = 0;
            local_ac = 0;
            if ((*pbVar27 == 0x5f) ||
               (pbVar4 = (byte *)FUN_001ccfb8(pbVar27,param_2,param_3), pbVar4 == pbVar27)) {
              puVar13 = (uint *)0x0;
              bVar32 = 0;
              pbVar4 = pbVar27;
            }
            else {
              iVar23 = param_3[1];
              if (*param_3 == iVar23) goto switchD_001c6c02_caseD_42;
              uVar29 = *(uint *)(iVar23 + -8);
              iVar28 = *(int *)(iVar23 + -4);
              if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
                iVar28 = iVar23 + -0xb;
                uVar29 = (uint)(*(byte *)(iVar23 + -0xc) >> 1);
              }
              pbVar27 = (byte *)FUN_001cb080(iVar23 + -0x18,iVar28,uVar29);
              bVar32 = *pbVar27;
              __aeabi_memcpy(&local_50,pbVar27 + 1,7);
              puVar13 = *(uint **)(pbVar27 + 8);
              pbVar27[0] = 0;
              pbVar27[1] = 0;
              pbVar27[2] = 0;
              pbVar27[3] = 0;
              pbVar27[4] = 0;
              pbVar27[5] = 0;
              pbVar27[6] = 0;
              pbVar27[7] = 0;
              pbVar27[8] = 0;
              pbVar27[9] = 0;
              pbVar27[10] = 0;
              pbVar27[0xb] = 0;
              iVar23 = param_3[1];
              local_b0 = CONCAT31(local_b0._1_3_,bVar32);
              __aeabi_memcpy((uint)&local_b0 | 1,&local_50,7);
              iVar28 = iVar23 + -0x18;
              local_a8 = puVar13;
              do {
                param_3[1] = iVar23 + -0x18;
                if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar23 + -4));
                }
                if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar23 + -0x10));
                }
                iVar23 = param_3[1];
              } while (iVar23 != iVar28);
            }
            if ((((pbVar4 == param_2) || (*pbVar4 != 0x5f)) ||
                (pbVar4 = pbVar4 + 1, pbVar4 == param_2)) ||
               (pbVar31 = (byte *)FUN_001c6af0(pbVar4,param_2,param_3), pbVar31 == pbVar4)) {
              bVar36 = false;
              pbVar31 = param_1;
            }
            else {
              iVar23 = param_3[1];
              if (*param_3 == iVar23) {
                bVar36 = true;
                pbVar31 = param_1;
              }
              else {
                FUN_001cbc00(&local_38," vector[",&local_b0);
                puVar18 = (uint *)FUN_001cb080(&local_38,&DAT_002213c8,1);
                local_50 = *puVar18;
                local_4c = puVar18[1];
                pvVar19 = (void *)puVar18[2];
                *puVar18 = 0;
                puVar18[1] = 0;
                puVar18[2] = 0;
                uVar29 = local_50 & 1;
                uVar33 = local_4c;
                pvVar26 = pvVar19;
                if ((local_50 & 1) == 0) {
                  pvVar26 = (void *)((uint)&local_50 | 1);
                  uVar33 = local_50 >> 1 & 0x7f;
                }
                local_48 = pvVar19;
                FUN_001cb080(iVar23 + -0x18,pvVar26,uVar33);
                if (uVar29 != 0) {
                  free(pvVar19);
                }
                if ((local_38 & 1) != 0) {
                  free(local_30);
                }
                bVar36 = false;
              }
            }
            if ((bVar32 & 1) != 0) {
              free(puVar13);
            }
            if (!bVar36) goto LAB_001c9990;
          }
        }
      }
    }
  default:
switchD_001c6c02_caseD_42:
    pbVar27 = (byte *)FUN_001d555c(param_1,param_2,param_3);
    if (((pbVar27 == param_1) &&
        (pbVar27 = (byte *)FUN_001c9fb8(param_1,param_2,param_3,0), pbVar27 != param_1)) &&
       (*param_3 != param_3[1])) {
      local_38 = param_3[3];
      FUN_001cb104(&local_50,param_3[1] + -0x18,&local_38);
      puVar13 = (uint *)param_3[5];
      if (puVar13 < (uint *)param_3[6]) {
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13[3] = local_44;
        *puVar13 = local_50;
        puVar13[1] = local_4c;
        puVar13[2] = (uint)local_48;
        local_48 = (void *)0x0;
        local_50 = 0;
        local_4c = 0;
        param_3[5] = param_3[5] + 0x10;
      }
      else {
        iVar23 = param_3[6] - param_3[4];
        iVar28 = (int)puVar13 - param_3[4] >> 4;
        if ((uint)(iVar23 >> 4) < 0x7ffffff) {
          uVar33 = iVar28 + 1;
          uVar29 = iVar23 >> 3;
          if (uVar29 < uVar33) {
            uVar29 = uVar33;
          }
        }
        else {
          uVar29 = 0xfffffff;
        }
        FUN_001d53d2(&local_b0,uVar29,iVar28,param_3 + 7);
        *local_a8 = 0;
        local_a8[1] = 0;
        local_a8[2] = 0;
        local_a8[3] = local_44;
        *local_a8 = local_50;
        local_a8[1] = local_4c;
        local_a8[2] = (uint)local_48;
        local_48 = (void *)0x0;
        local_50 = 0;
        local_4c = 0;
        local_a8 = local_a8 + 4;
        FUN_001d541e(param_3 + 4,&local_b0);
        FUN_001d548a(&local_b0);
      }
      FUN_001c5dac(&local_50);
    }
    break;
  case 0x46:
    pbVar27 = param_1 + 1;
    if ((pbVar27 == param_2) ||
       (((*pbVar27 == 0x59 && (pbVar27 = param_1 + 2, pbVar27 == param_2)) ||
        (pbVar4 = (byte *)FUN_001c6af0(pbVar27,param_2,param_3), pbVar4 == pbVar27)))) break;
    local_a8 = (uint *)0x0;
    local_b0 = 0;
    local_ac = 0;
    FUN_001c5e62(&local_b0,&DAT_00222248,1);
    pbVar27 = param_1;
    if (pbVar4 != param_2) {
      local_c4 = 0;
      do {
        bVar32 = *pbVar4;
        if (bVar32 < 0x52) {
          if (bVar32 == 0x4f) {
            if ((pbVar4 + 1 != param_2) && (pbVar4[1] == 0x45)) {
              local_c4 = 2;
              goto LAB_001c7466;
            }
LAB_001c7472:
            iVar23 = *param_3;
            iVar28 = param_3[1];
            pbVar8 = (byte *)FUN_001c6af0(pbVar4,param_2);
            pbVar31 = pbVar8;
            if (pbVar8 != pbVar4) {
              pbVar31 = param_2;
              local_c0 = pbVar8;
            }
            if (pbVar8 != pbVar4 && pbVar8 != pbVar31) {
              iVar23 = iVar28 - iVar23 >> 3;
              uVar33 = iVar23 * -0x55555555;
              uVar29 = (param_3[1] - *param_3 >> 3) * -0x55555555;
              pbVar4 = local_c0;
              if (uVar33 < uVar29) {
                iVar23 = iVar23 * 8;
                uVar16 = uVar33;
                do {
                  uVar6 = local_ac;
                  if ((local_b0 & 1) == 0) {
                    uVar6 = local_b0 >> 1 & 0x7f;
                  }
                  if (1 < uVar6) {
                    FUN_001cb080(&local_b0,&DAT_00222122,2);
                  }
                  iVar15 = *param_3 + iVar23;
                  uVar6 = *(uint *)(iVar15 + 0x10);
                  iVar28 = *(int *)(iVar15 + 0x14);
                  if ((*(byte *)(iVar15 + 0xc) & 1) == 0) {
                    iVar28 = iVar15 + 0xd;
                    uVar6 = (uint)(*(byte *)(iVar15 + 0xc) >> 1);
                  }
                  puVar13 = (uint *)FUN_001cb080(iVar15,iVar28,uVar6);
                  local_50 = *puVar13;
                  local_4c = puVar13[1];
                  pvVar19 = (void *)puVar13[2];
                  *puVar13 = 0;
                  puVar13[1] = 0;
                  puVar13[2] = 0;
                  uVar6 = local_50 & 1;
                  uVar9 = local_4c;
                  pvVar26 = pvVar19;
                  if ((local_50 & 1) == 0) {
                    pvVar26 = (void *)((uint)&local_50 | 1);
                    uVar9 = local_50 >> 1 & 0x7f;
                  }
                  local_48 = pvVar19;
                  FUN_001cb080(&local_b0,pvVar26,uVar9);
                  if (uVar6 != 0) {
                    free(pvVar19);
                  }
                  uVar16 = uVar16 + 1;
                  iVar23 = iVar23 + 0x18;
                } while (uVar29 - uVar16 != 0);
                if (uVar33 < uVar29) {
                  iVar23 = param_3[1];
                  do {
                    iVar28 = iVar23 + -0x18;
                    do {
                      param_3[1] = iVar23 + -0x18;
                      if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
                        free(*(void **)(iVar23 + -4));
                      }
                      if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
                        free(*(void **)(iVar23 + -0x10));
                      }
                      iVar23 = param_3[1];
                    } while (iVar23 != iVar28);
                    uVar33 = uVar33 + 1;
                    iVar23 = iVar28;
                  } while (uVar33 != uVar29);
                }
              }
              goto LAB_001c7594;
            }
          }
          else {
            if (bVar32 != 0x45) goto LAB_001c7472;
            FUN_001cb080(&local_b0,&DAT_0022045d,1);
            if (local_c4 == 1) {
              uVar7 = 2;
              puVar20 = &DAT_00222140;
LAB_001c8828:
              FUN_001cb080(&local_b0,puVar20,uVar7);
            }
            else if (local_c4 == 2) {
              uVar7 = 3;
              puVar20 = &DAT_00222143;
              goto LAB_001c8828;
            }
            if (*param_3 != param_3[1]) {
              pbVar27 = pbVar4 + 1;
              FUN_001cb080(param_3[1] + -0x18,&DAT_0021f760,1);
              bVar36 = false;
              uVar29 = local_ac;
              puVar13 = local_a8;
              if ((local_b0 & 1) == 0) {
                puVar13 = (uint *)((uint)&local_b0 | 1);
                uVar29 = local_b0 >> 1 & 0x7f;
              }
              FUN_001caf2a(param_3[1] + -0xc,0,puVar13,uVar29);
              goto LAB_001c887c;
            }
          }
          bVar36 = true;
          goto LAB_001c887c;
        }
        if (bVar32 == 0x52) {
          if ((pbVar4 + 1 == param_2) || (pbVar4[1] != 0x45)) goto LAB_001c7472;
          local_c4 = 1;
LAB_001c7466:
          pbVar4 = pbVar4 + 1;
        }
        else {
          if (bVar32 != 0x76) goto LAB_001c7472;
          pbVar4 = pbVar4 + 1;
        }
LAB_001c7594:
      } while (pbVar4 != param_2);
    }
    iVar28 = param_3[1];
    iVar23 = iVar28 + -0x18;
    do {
      param_3[1] = iVar28 + -0x18;
      if ((*(byte *)(iVar28 + -0xc) & 1) != 0) {
        free(*(void **)(iVar28 + -4));
      }
      if ((*(byte *)(iVar28 + -0x18) & 1) != 0) {
        free(*(void **)(iVar28 + -0x10));
      }
      iVar28 = param_3[1];
    } while (iVar28 != iVar23);
    bVar36 = true;
LAB_001c887c:
    if ((local_b0 & 1) != 0) {
      free(local_a8);
    }
    if ((bVar36) || (pbVar27 == param_1)) break;
    iVar28 = *param_3;
    iVar23 = param_3[1];
    goto LAB_001c88a0;
  case 0x47:
    pbVar27 = (byte *)FUN_001c6af0(param_1 + 1,param_2,param_3);
    if ((pbVar27 == param_1 + 1) || (iVar23 = param_3[1], *param_3 == iVar23)) break;
    uVar7 = 10;
    pcVar17 = " imaginary";
LAB_001c7616:
    FUN_001cb080(iVar23 + -0x18,pcVar17,uVar7);
    iVar23 = param_3[1];
LAB_001c88a6:
    local_38 = param_3[3];
    FUN_001cb104(&local_50,iVar23 + -0x18,&local_38);
    puVar13 = (uint *)param_3[5];
    if (puVar13 < (uint *)param_3[6]) {
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = local_44;
      *puVar13 = local_50;
      puVar13[1] = local_4c;
      puVar13[2] = (uint)local_48;
      local_48 = (void *)0x0;
      local_4c = 0;
      local_50 = 0;
      param_3[5] = param_3[5] + 0x10;
    }
    else {
      iVar23 = (int)puVar13 - param_3[4];
      iVar28 = param_3[6] - param_3[4];
joined_r0x001c986e:
      if ((uint)(iVar28 >> 4) < 0x7ffffff) {
        uVar33 = (iVar23 >> 4) + 1;
        uVar29 = iVar28 >> 3;
        if ((uint)(iVar28 >> 3) < uVar33) {
          uVar29 = uVar33;
        }
      }
      else {
        uVar29 = 0xfffffff;
      }
      FUN_001d53d2(&local_b0,uVar29,iVar23 >> 4,param_3 + 7);
      *local_a8 = 0;
      local_a8[1] = 0;
      local_a8[2] = 0;
      local_a8[3] = local_44;
      *local_a8 = local_50;
      local_a8[1] = local_4c;
      local_a8[2] = (uint)local_48;
      local_48 = (void *)0x0;
      local_a8 = local_a8 + 4;
      local_4c = 0;
      local_50 = 0;
      FUN_001d541e(param_3 + 4,&local_b0);
      FUN_001d548a(&local_b0);
    }
LAB_001c98c0:
    FUN_001c5dac(&local_50);
    break;
  case 0x4d:
    pbVar27 = (byte *)FUN_001c6af0(param_1 + 1,param_2,param_3);
    if (((pbVar27 == param_1 + 1) ||
        (pbVar4 = (byte *)FUN_001c6af0(pbVar27,param_2,param_3), pbVar4 == pbVar27)) ||
       (iVar23 = param_3[1], (uint)((iVar23 - *param_3 >> 3) * -0x55555555) < 2)) break;
    local_b0 = *(uint *)(iVar23 + -0x18);
    local_ac = *(uint *)(iVar23 + -0x14);
    local_a8 = *(uint **)(iVar23 + -0x10);
    *(undefined4 *)(iVar23 + -0x10) = 0;
    *(undefined4 *)(iVar23 + -0x18) = 0;
    *(undefined4 *)(iVar23 + -0x14) = 0;
    local_a4 = *(uint *)(iVar23 + -0xc);
    local_a0 = *(uint *)(iVar23 + -8);
    local_9c = *(char **)(iVar23 + -4);
    *(undefined4 *)(iVar23 + -4) = 0;
    *(undefined4 *)(iVar23 + -0xc) = 0;
    *(undefined4 *)(iVar23 + -8) = 0;
    iVar28 = param_3[1];
    iVar23 = iVar28;
    do {
      param_3[1] = iVar23 + -0x18;
      if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
        free(*(void **)(iVar23 + -4));
      }
      if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
        free(*(void **)(iVar23 + -0x10));
      }
      iVar23 = param_3[1];
    } while (iVar23 != iVar28 + -0x18);
    local_50 = *(uint *)(iVar28 + -0x30);
    local_4c = *(uint *)(iVar28 + -0x2c);
    local_48 = *(void **)(iVar28 + -0x28);
    *(undefined4 *)(iVar28 + -0x28) = 0;
    *(undefined4 *)(iVar28 + -0x30) = 0;
    *(undefined4 *)(iVar28 + -0x2c) = 0;
    local_44 = *(uint *)(iVar28 + -0x24);
    local_40 = *(uint *)(iVar28 + -0x20);
    local_3c = *(void **)(iVar28 + -0x1c);
    *(undefined4 *)(iVar28 + -0x1c) = 0;
    *(undefined4 *)(iVar28 + -0x24) = 0;
    *(undefined4 *)(iVar28 + -0x20) = 0;
    uVar29 = local_a0;
    if ((local_a4 & 1) == 0) {
      uVar29 = local_a4 >> 1 & 0x7f;
    }
    if (uVar29 == 0) {
LAB_001c81da:
      iVar23 = param_3[1];
      puVar13 = (uint *)FUN_001cb080(&local_b0,&DAT_0021f760,1);
      local_60 = *puVar13;
      local_5c = puVar13[1];
      local_58 = (void *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      uVar29 = local_40;
      pvVar26 = local_3c;
      if ((local_44 & 1) == 0) {
        pvVar26 = (void *)((int)&local_44 + 1);
        uVar29 = local_44 >> 1 & 0x7f;
      }
      puVar13 = (uint *)FUN_001cb080(&local_50,pvVar26,uVar29);
      local_70 = *puVar13;
      local_6c = puVar13[1];
      pvVar19 = (void *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      uVar33 = local_70 & 1;
      uVar29 = local_6c;
      pvVar26 = pvVar19;
      if ((local_70 & 1) == 0) {
        pvVar26 = (void *)((uint)&local_70 | 1);
        uVar29 = local_70 >> 1 & 0x7f;
      }
      local_68 = pvVar19;
      puVar13 = (uint *)FUN_001cb080(&local_60,pvVar26,uVar29);
      local_38 = *puVar13;
      local_34 = puVar13[1];
      local_30 = (uint *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar10 = (undefined4 *)FUN_001cb080(&local_38,&DAT_00222522,3);
      uVar3 = *(undefined1 *)puVar10;
      __aeabi_memcpy(&local_90,(int)puVar10 + 1,7);
      uVar7 = puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar13 = (uint *)(iVar23 + -0x18);
      if ((*(byte *)puVar13 & 1) == 0) {
        *(undefined2 *)(iVar23 + -0x18) = 0;
      }
      else {
        puVar10 = (undefined4 *)(iVar23 + -0x10);
        *(undefined1 *)*puVar10 = 0;
        *(undefined4 *)(iVar23 + -0x14) = 0;
        uVar29 = (uint)*(byte *)(iVar23 + -0x18);
        if ((*(byte *)(iVar23 + -0x18) & 1) == 0) {
          uVar16 = 10;
        }
        else {
          uVar29 = *puVar13;
          uVar16 = (uVar29 & 0xfffffffe) - 1;
        }
        if ((uVar29 & 1) == 0) {
          uVar6 = (uVar29 & 0xff) >> 1;
          if ((uVar29 & 0xff) < 0x16) {
            uVar9 = 10;
          }
          else {
            uVar9 = (uVar6 + 0x10 & 0xf0) - 1;
          }
          bVar36 = true;
        }
        else {
          uVar9 = 10;
          uVar6 = 0;
          bVar36 = false;
        }
        if (uVar9 != uVar16) {
          if (uVar9 == 10) {
            puVar24 = (undefined1 *)*puVar10;
            if (bVar36) {
              __aeabi_memcpy((undefined1 *)(iVar23 + -0x17),puVar24,((uVar29 & 0xfe) >> 1) + 1);
            }
            else {
              *(undefined1 *)(iVar23 + -0x17) = *puVar24;
            }
            free(puVar24);
            *(byte *)puVar13 = (byte)(uVar6 << 1);
          }
          else {
            puVar24 = malloc(uVar9 + 1);
            if ((uVar16 < uVar9) || (puVar24 != (undefined1 *)0x0)) {
              if (bVar36) {
                __aeabi_memcpy(puVar24,iVar23 + -0x17,((uVar29 & 0xfe) >> 1) + 1);
              }
              else {
                puVar12 = (undefined1 *)*puVar10;
                *puVar24 = *puVar12;
                free(puVar12);
              }
              *(uint *)(iVar23 + -0x18) = uVar9 + 1 | 1;
              *(uint *)(iVar23 + -0x14) = uVar6;
              *(undefined1 **)(iVar23 + -0x10) = puVar24;
            }
          }
        }
      }
      *(undefined1 *)(iVar23 + -0x18) = uVar3;
      __aeabi_memcpy(iVar23 + -0x17,&local_90,7);
      *(undefined4 *)(iVar23 + -0x10) = uVar7;
      local_8c = (uint)local_8c._3_1_ << 0x18;
      local_90 = 0;
      if ((local_38 & 1) != 0) {
        free(local_30);
      }
      if (uVar33 != 0) {
        free(pvVar19);
      }
      if ((local_60 & 1) != 0) {
        free(local_58);
      }
      iVar23 = param_3[1];
      puVar13 = (uint *)(iVar23 + -0xc);
      if ((*(byte *)puVar13 & 1) == 0) {
        *(undefined2 *)puVar13 = 0;
      }
      else {
        **(undefined1 **)(iVar23 + -4) = 0;
        *(undefined4 *)(iVar23 + -8) = 0;
        uVar29 = (uint)*(byte *)(iVar23 + -0xc);
        if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
          uVar33 = 10;
        }
        else {
          uVar29 = *puVar13;
          uVar33 = (uVar29 & 0xfffffffe) - 1;
        }
        if ((uVar29 & 1) == 0) {
          uVar6 = (uVar29 & 0xff) >> 1;
          if ((uVar29 & 0xff) < 0x16) {
            uVar16 = 10;
          }
          else {
            uVar16 = (uVar6 + 0x10 & 0xf0) - 1;
          }
          bVar36 = true;
        }
        else {
          uVar16 = 10;
          uVar6 = 0;
          bVar36 = false;
        }
        if (uVar16 != uVar33) {
          if (uVar16 == 10) {
            puVar24 = *(undefined1 **)(iVar23 + -4);
            if (bVar36) {
              __aeabi_memcpy((undefined1 *)(iVar23 + -0xb),puVar24,((uVar29 & 0xfe) >> 1) + 1);
            }
            else {
              *(undefined1 *)(iVar23 + -0xb) = *puVar24;
            }
            free(puVar24);
            *(byte *)puVar13 = (byte)(uVar6 << 1);
          }
          else {
            puVar24 = malloc(uVar16 + 1);
            if ((uVar33 < uVar16) || (puVar24 != (undefined1 *)0x0)) {
              if (bVar36) {
                __aeabi_memcpy(puVar24,iVar23 + -0xb,((uVar29 & 0xfe) >> 1) + 1);
              }
              else {
                puVar12 = *(undefined1 **)(iVar23 + -4);
                *puVar24 = *puVar12;
                free(puVar12);
              }
              *(uint *)(iVar23 + -0xc) = uVar16 + 1 | 1;
              *(uint *)(iVar23 + -8) = uVar6;
              *(undefined1 **)(iVar23 + -4) = puVar24;
            }
          }
        }
      }
      *puVar13 = local_a4;
      *(uint *)(iVar23 + -8) = local_a0;
      *(char **)(iVar23 + -4) = local_9c;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = (char *)0x0;
    }
    else {
      pcVar17 = local_9c;
      if ((local_a4 & 1) == 0) {
        pcVar17 = (char *)((int)&local_a4 + 1);
      }
      if (*pcVar17 != '(') goto LAB_001c81da;
      iVar23 = param_3[1];
      puVar13 = (uint *)FUN_001cb080(&local_b0,&DAT_00222248,1);
      local_60 = *puVar13;
      local_5c = puVar13[1];
      local_58 = (void *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      uVar29 = local_40;
      pvVar26 = local_3c;
      if ((local_44 & 1) == 0) {
        pvVar26 = (void *)((int)&local_44 + 1);
        uVar29 = local_44 >> 1 & 0x7f;
      }
      puVar13 = (uint *)FUN_001cb080(&local_50,pvVar26,uVar29);
      local_70 = *puVar13;
      local_6c = puVar13[1];
      pvVar19 = (void *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      uVar33 = local_70 & 1;
      uVar29 = local_6c;
      pvVar26 = pvVar19;
      if ((local_70 & 1) == 0) {
        pvVar26 = (void *)((uint)&local_70 | 1);
        uVar29 = local_70 >> 1 & 0x7f;
      }
      local_68 = pvVar19;
      puVar13 = (uint *)FUN_001cb080(&local_60,pvVar26,uVar29);
      local_38 = *puVar13;
      local_34 = puVar13[1];
      local_30 = (uint *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar10 = (undefined4 *)FUN_001cb080(&local_38,&DAT_00222522,3);
      uVar3 = *(undefined1 *)puVar10;
      __aeabi_memcpy(&local_90,(int)puVar10 + 1,7);
      uVar7 = puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar13 = (uint *)(iVar23 + -0x18);
      if ((*(byte *)puVar13 & 1) == 0) {
        *(undefined2 *)(iVar23 + -0x18) = 0;
      }
      else {
        puVar10 = (undefined4 *)(iVar23 + -0x10);
        *(undefined1 *)*puVar10 = 0;
        *(undefined4 *)(iVar23 + -0x14) = 0;
        uVar29 = (uint)*(byte *)(iVar23 + -0x18);
        if ((*(byte *)(iVar23 + -0x18) & 1) == 0) {
          uVar16 = 10;
        }
        else {
          uVar29 = *puVar13;
          uVar16 = (uVar29 & 0xfffffffe) - 1;
        }
        if ((uVar29 & 1) == 0) {
          local_d4 = (uVar29 & 0xff) >> 1;
          if ((uVar29 & 0xff) < 0x16) {
            uVar6 = 10;
          }
          else {
            uVar6 = (local_d4 + 0x10 & 0xf0) - 1;
          }
          bVar36 = true;
        }
        else {
          uVar6 = 10;
          local_d4 = 0;
          bVar36 = false;
        }
        if (uVar6 != uVar16) {
          if (uVar6 == 10) {
            puVar24 = (undefined1 *)*puVar10;
            if (bVar36) {
              __aeabi_memcpy((undefined1 *)(iVar23 + -0x17),puVar24,((uVar29 & 0xfe) >> 1) + 1);
            }
            else {
              *(undefined1 *)(iVar23 + -0x17) = *puVar24;
            }
            free(puVar24);
            *(byte *)puVar13 = (byte)(local_d4 << 1);
          }
          else {
            puVar24 = malloc(uVar6 + 1);
            if ((uVar16 < uVar6) || (puVar24 != (undefined1 *)0x0)) {
              if (bVar36) {
                __aeabi_memcpy(puVar24,iVar23 + -0x17,((uVar29 & 0xfe) >> 1) + 1);
              }
              else {
                puVar12 = (undefined1 *)*puVar10;
                *puVar24 = *puVar12;
                free(puVar12);
              }
              *(uint *)(iVar23 + -0x18) = uVar6 + 1 | 1;
              *(uint *)(iVar23 + -0x14) = local_d4;
              *(undefined1 **)(iVar23 + -0x10) = puVar24;
            }
          }
        }
      }
      *(undefined1 *)(iVar23 + -0x18) = uVar3;
      __aeabi_memcpy(iVar23 + -0x17,&local_90,7);
      *(undefined4 *)(iVar23 + -0x10) = uVar7;
      local_8c = (uint)local_8c._3_1_ << 0x18;
      local_90 = 0;
      if ((local_38 & 1) != 0) {
        free(local_30);
      }
      if (uVar33 != 0) {
        free(pvVar19);
      }
      if ((local_60 & 1) != 0) {
        free(local_58);
      }
      iVar23 = param_3[1];
      puVar10 = (undefined4 *)FUN_001caf2a(&local_a4,0,&DAT_0022045d,1);
      uVar3 = *(undefined1 *)puVar10;
      __aeabi_memcpy(&local_38,(int)puVar10 + 1,7);
      uVar7 = puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar13 = (uint *)(iVar23 + -0xc);
      if ((*(byte *)puVar13 & 1) == 0) {
        *(undefined2 *)(iVar23 + -0xc) = 0;
      }
      else {
        puVar10 = (undefined4 *)(iVar23 + -4);
        *(undefined1 *)*puVar10 = 0;
        *(undefined4 *)(iVar23 + -8) = 0;
        uVar29 = (uint)*(byte *)(iVar23 + -0xc);
        if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
          uVar33 = 10;
        }
        else {
          uVar29 = *puVar13;
          uVar33 = (uVar29 & 0xfffffffe) - 1;
        }
        if ((uVar29 & 1) == 0) {
          local_c8 = (uVar29 & 0xff) >> 1;
          if ((uVar29 & 0xff) < 0x16) {
            uVar16 = 10;
          }
          else {
            uVar16 = (local_c8 + 0x10 & 0xf0) - 1;
          }
          bVar36 = true;
        }
        else {
          uVar16 = 10;
          local_c8 = 0;
          bVar36 = false;
        }
        if (uVar16 != uVar33) {
          if (uVar16 == 10) {
            puVar24 = (undefined1 *)*puVar10;
            if (bVar36) {
              __aeabi_memcpy((undefined1 *)(iVar23 + -0xb),puVar24,((uVar29 & 0xfe) >> 1) + 1);
            }
            else {
              *(undefined1 *)(iVar23 + -0xb) = *puVar24;
            }
            free(puVar24);
            *(byte *)puVar13 = (byte)(local_c8 << 1);
          }
          else {
            puVar24 = malloc(uVar16 + 1);
            if ((uVar33 < uVar16) || (puVar24 != (undefined1 *)0x0)) {
              if (bVar36) {
                __aeabi_memcpy(puVar24,iVar23 + -0xb,((uVar29 & 0xfe) >> 1) + 1);
              }
              else {
                puVar12 = (undefined1 *)*puVar10;
                *puVar24 = *puVar12;
                free(puVar12);
              }
              *(uint *)(iVar23 + -0xc) = uVar16 + 1 | 1;
              *(uint *)(iVar23 + -8) = local_c8;
              *(undefined1 **)(iVar23 + -4) = puVar24;
            }
          }
        }
      }
      *(undefined1 *)(iVar23 + -0xc) = uVar3;
      __aeabi_memcpy(iVar23 + -0xb,&local_38,7);
      *(undefined4 *)(iVar23 + -4) = uVar7;
    }
    if ((local_44 & 1) != 0) {
      free(local_3c);
    }
    if ((local_50 & 1) != 0) {
      free(local_48);
    }
    if ((local_a4 & 1) != 0) {
      free(local_9c);
    }
    if ((local_b0 & 1) != 0) {
      free(local_a8);
    }
    if ((pbVar4 == param_1) || (*param_3 == param_3[1])) break;
    local_38 = param_3[3];
    FUN_001cb104(&local_50,param_3[1] + -0x18,&local_38);
    puVar13 = (uint *)param_3[5];
    if ((uint *)param_3[6] <= puVar13) {
      iVar23 = (int)puVar13 - param_3[4];
      iVar28 = param_3[6] - param_3[4];
      goto joined_r0x001c986e;
    }
    *puVar13 = 0;
    puVar13[1] = 0;
    puVar13[2] = 0;
    puVar13[3] = local_44;
    *puVar13 = local_50;
    puVar13[1] = local_4c;
    puVar13[2] = (uint)local_48;
    local_48 = (void *)0x0;
    local_50 = 0;
    local_4c = 0;
    param_3[5] = param_3[5] + 0x10;
    goto LAB_001c98c0;
  case 0x4f:
    iVar28 = *param_3;
    iVar23 = param_3[1];
    pbVar27 = (byte *)FUN_001c6af0(param_1 + 1,param_2,param_3);
    if (pbVar27 != param_1 + 1) {
      iVar23 = iVar23 - iVar28 >> 3;
      uVar33 = param_3[3];
      uVar29 = (param_3[1] - *param_3 >> 3) * -0x55555555;
      puVar10 = (undefined4 *)param_3[5];
      if (puVar10 < (undefined4 *)param_3[6]) {
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = uVar33;
        param_3[5] = param_3[5] + 0x10;
      }
      else {
        iVar28 = param_3[6] - param_3[4];
        iVar15 = (int)puVar10 - param_3[4] >> 4;
        if ((uint)(iVar28 >> 4) < 0x7ffffff) {
          uVar6 = iVar15 + 1;
          uVar16 = iVar28 >> 3;
          if (uVar16 < uVar6) {
            uVar16 = uVar6;
          }
        }
        else {
          uVar16 = 0xfffffff;
        }
        FUN_001d53d2(&local_b0,uVar16,iVar15,param_3 + 7);
        *local_a8 = 0;
        local_a8[1] = 0;
        local_a8[2] = 0;
        local_a8[3] = uVar33;
        local_a8 = local_a8 + 4;
        FUN_001d541e(param_3 + 4,&local_b0);
        FUN_001d548a(&local_b0);
      }
      if ((uint)(iVar23 * -0x55555555) < uVar29) {
        iVar28 = uVar29 + iVar23 * 0x55555555;
        iVar23 = iVar23 * 8 + 0xc;
        do {
          local_a8 = (uint *)0x0;
          local_b0 = 0;
          local_ac = 0;
          bVar32 = *(byte *)(*param_3 + iVar23);
          iVar21 = *param_3 + iVar23;
          uVar29 = *(uint *)(iVar21 + 4);
          iVar15 = *(int *)(iVar21 + 8);
          if ((bVar32 & 1) == 0) {
            iVar15 = iVar21 + 1;
            uVar29 = (uint)(bVar32 >> 1);
          }
          if (1 < uVar29) {
            uVar29 = 2;
          }
          FUN_001c5e62(&local_b0,iVar15,uVar29);
          bVar36 = false;
          uVar29 = local_ac;
          if ((local_b0 & 1) == 0) {
            uVar29 = local_b0 >> 1 & 0x7f;
          }
          if (uVar29 == 2) {
            bVar36 = false;
            puVar13 = local_a8;
            if ((local_b0 & 1) == 0) {
              puVar13 = (uint *)((uint)&local_b0 | 1);
            }
            if ((short)*puVar13 == 0x5b20) {
              bVar36 = true;
            }
          }
          if ((local_b0 & 1) != 0) {
            free(local_a8);
          }
          iVar15 = *param_3;
          if (bVar36) {
            FUN_001cb080(iVar15 + iVar23 + -0xc,&DAT_0022045a,2);
            FUN_001caf2a(*param_3 + iVar23,0,&DAT_0022045d,1);
          }
          else {
            uVar14 = *(ushort *)(iVar15 + iVar23);
            if ((uVar14 & 1) == 0) {
              uVar29 = (uVar14 & 0xff) >> 1;
            }
            else {
              uVar29 = *(uint *)(iVar15 + iVar23 + 4);
            }
            if (uVar29 != 0) {
              if ((uVar14 & 1) == 0) {
                uVar14 = uVar14 >> 8;
              }
              else {
                uVar14 = (ushort)**(byte **)(iVar15 + iVar23 + 8);
              }
              if (uVar14 == 0x28) {
                FUN_001cb080(iVar15 + iVar23 + -0xc,&DAT_00222248,1);
                FUN_001caf2a(*param_3 + iVar23,0,&DAT_0022045d,1);
              }
            }
          }
          FUN_001cb080(*param_3 + iVar23 + -0xc,&DAT_0022221c,2);
          iVar25 = param_3[5];
          iVar21 = *param_3;
          iVar15 = *(int *)(iVar25 + -0xc);
          if (iVar15 == *(int *)(iVar25 + -8)) {
            iVar15 = iVar15 - *(int *)(iVar25 + -0x10) >> 3;
            uVar33 = iVar15 * -0x55555555;
            uVar29 = 0xaaaaaaa;
            if (uVar33 < 0x5555555) {
              uVar29 = iVar15 * 0x55555556;
              if (uVar29 < uVar33 + 1) {
                uVar29 = uVar33 + 1;
              }
            }
            FUN_001ccdd4(&local_b0,uVar29,uVar33,iVar25 + -4);
            iVar21 = iVar21 + iVar23;
            iVar15 = FUN_001c5e34(local_a8,iVar21 + -0xc);
            FUN_001c5e34(iVar15 + 0xc,iVar21);
            local_a8 = local_a8 + 6;
            FUN_001cce32(iVar25 + -0x10,&local_b0);
            FUN_001cceae(&local_b0);
          }
          else {
            iVar21 = iVar21 + iVar23;
            iVar15 = FUN_001c5e34(iVar15,iVar21 + -0xc);
            FUN_001c5e34(iVar15 + 0xc,iVar21);
            *(int *)(iVar25 + -0xc) = *(int *)(iVar25 + -0xc) + 0x18;
          }
          iVar23 = iVar23 + 0x18;
          iVar28 = iVar28 + -1;
        } while (iVar28 != 0);
      }
    }
    break;
  case 0x50:
    iVar23 = *param_3;
    iVar28 = param_3[1];
    param_1 = param_1 + 1;
    pbVar27 = (byte *)FUN_001c6af0(param_1,param_2,param_3);
    if (pbVar27 != param_1) {
      iVar23 = iVar28 - iVar23 >> 3;
      uVar16 = iVar23 * -0x55555555;
      uVar29 = param_3[3];
      uVar33 = (param_3[1] - *param_3 >> 3) * -0x55555555;
      puVar10 = (undefined4 *)param_3[5];
      if (puVar10 < (undefined4 *)param_3[6]) {
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = uVar29;
        param_3[5] = param_3[5] + 0x10;
      }
      else {
        iVar28 = param_3[6] - param_3[4];
        iVar15 = (int)puVar10 - param_3[4] >> 4;
        if ((uint)(iVar28 >> 4) < 0x7ffffff) {
          uVar9 = iVar15 + 1;
          uVar6 = iVar28 >> 3;
          if (uVar6 < uVar9) {
            uVar6 = uVar9;
          }
        }
        else {
          uVar6 = 0xfffffff;
        }
        FUN_001d53d2(&local_b0,uVar6,iVar15,param_3 + 7);
        *local_a8 = 0;
        local_a8[1] = 0;
        local_a8[2] = 0;
        local_a8[3] = uVar29;
        local_a8 = local_a8 + 4;
        FUN_001d541e(param_3 + 4,&local_b0);
        FUN_001d548a(&local_b0);
      }
      if (uVar16 < uVar33) {
        iVar28 = uVar33 + iVar23 * 0x55555555;
        iVar23 = iVar23 * 8 + 0xc;
        do {
          local_a8 = (uint *)0x0;
          local_b0 = 0;
          local_ac = 0;
          bVar32 = *(byte *)(*param_3 + iVar23);
          iVar21 = *param_3 + iVar23;
          uVar29 = *(uint *)(iVar21 + 4);
          iVar15 = *(int *)(iVar21 + 8);
          if ((bVar32 & 1) == 0) {
            iVar15 = iVar21 + 1;
            uVar29 = (uint)(bVar32 >> 1);
          }
          if (1 < uVar29) {
            uVar29 = 2;
          }
          FUN_001c5e62(&local_b0,iVar15,uVar29);
          bVar36 = false;
          uVar29 = local_ac;
          if ((local_b0 & 1) == 0) {
            uVar29 = local_b0 >> 1 & 0x7f;
          }
          if (uVar29 == 2) {
            bVar36 = false;
            puVar13 = local_a8;
            if ((local_b0 & 1) == 0) {
              puVar13 = (uint *)((uint)&local_b0 | 1);
            }
            if ((short)*puVar13 == 0x5b20) {
              bVar36 = true;
            }
          }
          if ((local_b0 & 1) != 0) {
            free(local_a8);
          }
          iVar15 = *param_3;
          if (bVar36) {
            FUN_001cb080(iVar15 + iVar23 + -0xc,&DAT_0022045a,2);
            FUN_001caf2a(*param_3 + iVar23,0,&DAT_0022045d,1);
          }
          else {
            uVar14 = *(ushort *)(iVar15 + iVar23);
            if ((uVar14 & 1) == 0) {
              uVar29 = (uVar14 & 0xff) >> 1;
            }
            else {
              uVar29 = *(uint *)(iVar15 + iVar23 + 4);
            }
            if (uVar29 != 0) {
              if ((uVar14 & 1) == 0) {
                uVar14 = uVar14 >> 8;
              }
              else {
                uVar14 = (ushort)**(byte **)(iVar15 + iVar23 + 8);
              }
              if (uVar14 == 0x28) {
                FUN_001cb080(iVar15 + iVar23 + -0xc,&DAT_00222248,1);
                FUN_001caf2a(*param_3 + iVar23,0,&DAT_0022045d,1);
              }
            }
          }
          if (*param_1 == 0x55) {
            local_a8 = (uint *)0x0;
            iVar21 = *param_3 + iVar23;
            local_b0 = 0;
            local_ac = 0;
            uVar29 = *(uint *)(iVar21 + -8);
            iVar15 = *(int *)(iVar21 + -4);
            if ((*(byte *)(iVar21 + -0xc) & 1) == 0) {
              iVar15 = iVar21 + -0xb;
              uVar29 = (uint)(*(byte *)(iVar21 + -0xc) >> 1);
            }
            if (0xb < uVar29) {
              uVar29 = 0xc;
            }
            FUN_001c5e62(&local_b0,iVar15,uVar29);
            uVar29 = local_b0 & 1;
            uVar33 = local_ac;
            if ((local_b0 & 1) == 0) {
              uVar33 = local_b0 >> 1 & 0x7f;
            }
            if (uVar33 == 0xc) {
              puVar13 = local_a8;
              if ((local_b0 & 1) == 0) {
                puVar13 = (uint *)((uint)&local_b0 | 1);
              }
              iVar15 = memcmp(puVar13,"objc_object<",0xc);
              bVar36 = iVar15 != 0;
            }
            else {
              bVar36 = true;
            }
            if (uVar29 != 0) {
              free(local_a8);
            }
            iVar21 = *param_3 + iVar23;
            iVar15 = iVar21 + -0xc;
            if (bVar36) goto LAB_001c8c1c;
            bVar32 = *(byte *)(iVar21 + -0xc);
            uVar29 = (uint)bVar32;
            if ((bVar32 & 1) == 0) {
              uVar33 = 0xb;
              uVar6 = (uint)(bVar32 >> 1);
              if (uVar6 < 0xb) {
                uVar33 = (uint)(bVar32 >> 1);
              }
              iVar25 = 10;
            }
            else {
              uVar29 = *(uint *)(iVar21 + -0xc);
              uVar6 = *(uint *)(iVar21 + -8);
              uVar33 = 0xb;
              if (uVar6 < 0xb) {
                uVar33 = uVar6;
              }
              iVar25 = (uVar29 & 0xfffffffe) - 1;
            }
            if ((uVar33 - uVar6) + iVar25 < 2) {
              FUN_001cafce(iVar15,iVar25,((2 - uVar33) + uVar6) - iVar25,uVar6,0,uVar33,2,
                           &DAT_00222500);
            }
            else {
              if ((uVar29 & 1) == 0) {
                puVar22 = (undefined2 *)(iVar21 + -0xb);
              }
              else {
                puVar22 = *(undefined2 **)(iVar21 + -4);
              }
              puVar20 = &DAT_00222500;
              if (uVar33 == 2) {
                iVar25 = 2;
                puVar20 = &DAT_00222500;
                uVar29 = 0;
                uVar33 = 2;
LAB_001c8d5c:
                __aeabi_memmove((undefined *)(uVar29 + (int)puVar22),puVar20,iVar25);
              }
              else {
                iVar15 = uVar6 - uVar33;
                if (iVar15 == 0) {
                  iVar25 = 2;
                  uVar29 = 0;
                  puVar20 = &DAT_00222500;
                  goto LAB_001c8d5c;
                }
                if (uVar33 < 3) {
                  puVar34 = (undefined *)((int)puVar22 + uVar33);
                  if ((puVar22 < &DAT_00222500) &&
                     (&DAT_00222500 < (undefined *)((int)puVar22 + uVar6))) {
                    if (&DAT_00222500 < puVar34) {
                      if (uVar33 != 0) {
                        __aeabi_memcpy(puVar22,&DAT_00222500,uVar33);
                      }
                      iVar25 = 2 - uVar33;
                      __aeabi_memmove(puVar34 + iVar25,puVar34,iVar15);
                      if (iVar25 != 0) {
                        puVar20 = &DAT_00222502;
                        uVar29 = uVar33;
                        uVar33 = 0;
                        goto LAB_001c8d5c;
                      }
                      uVar33 = 0;
                      iVar25 = 0;
                      goto LAB_001c8d64;
                    }
                    puVar20 = &DAT_00222502 + -uVar33;
                  }
                  __aeabi_memmove(puVar22 + 1,puVar34,iVar15);
                  iVar25 = 2;
                  uVar29 = 0;
                  goto LAB_001c8d5c;
                }
                *puVar22 = 0x6469;
                __aeabi_memmove(puVar22 + 1,(undefined *)((int)puVar22 + uVar33),iVar15);
                iVar25 = 2;
              }
LAB_001c8d64:
              iVar15 = (iVar25 - uVar33) + uVar6;
              if ((*(byte *)(iVar21 + -0xc) & 1) == 0) {
                *(char *)(iVar21 + -0xc) = (char)iVar15 * '\x02';
              }
              else {
                *(int *)(iVar21 + -8) = iVar15;
              }
              *(undefined1 *)((int)puVar22 + iVar15) = 0;
            }
          }
          else {
            iVar15 = *param_3 + uVar16 * 0x18;
LAB_001c8c1c:
            FUN_001cb080(iVar15,&DAT_0021f89d,1);
          }
          iVar25 = param_3[5];
          iVar21 = *param_3;
          iVar15 = *(int *)(iVar25 + -0xc);
          if (iVar15 == *(int *)(iVar25 + -8)) {
            iVar15 = iVar15 - *(int *)(iVar25 + -0x10) >> 3;
            uVar33 = iVar15 * -0x55555555;
            uVar29 = 0xaaaaaaa;
            if (uVar33 < 0x5555555) {
              uVar29 = iVar15 * 0x55555556;
              if (uVar29 < uVar33 + 1) {
                uVar29 = uVar33 + 1;
              }
            }
            FUN_001ccdd4(&local_b0,uVar29,uVar33,iVar25 + -4);
            iVar21 = iVar21 + iVar23;
            iVar15 = FUN_001c5e34(local_a8,iVar21 + -0xc);
            FUN_001c5e34(iVar15 + 0xc,iVar21);
            local_a8 = local_a8 + 6;
            FUN_001cce32(iVar25 + -0x10,&local_b0);
            FUN_001cceae(&local_b0);
          }
          else {
            iVar21 = iVar21 + iVar23;
            iVar15 = FUN_001c5e34(iVar15,iVar21 + -0xc);
            FUN_001c5e34(iVar15 + 0xc,iVar21);
            *(int *)(iVar25 + -0xc) = *(int *)(iVar25 + -0xc) + 0x18;
          }
          iVar23 = iVar23 + 0x18;
          iVar28 = iVar28 + -1;
          uVar16 = uVar16 + 1;
        } while (iVar28 != 0);
      }
    }
    break;
  case 0x52:
    iVar28 = *param_3;
    iVar23 = param_3[1];
    pbVar27 = (byte *)FUN_001c6af0(param_1 + 1,param_2,param_3);
    if (pbVar27 != param_1 + 1) {
      uVar33 = param_3[3];
      iVar23 = iVar23 - iVar28 >> 3;
      uVar29 = (param_3[1] - *param_3 >> 3) * -0x55555555;
      puVar10 = (undefined4 *)param_3[5];
      if (puVar10 < (undefined4 *)param_3[6]) {
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = uVar33;
        param_3[5] = param_3[5] + 0x10;
      }
      else {
        iVar28 = param_3[6] - param_3[4];
        iVar15 = (int)puVar10 - param_3[4] >> 4;
        if ((uint)(iVar28 >> 4) < 0x7ffffff) {
          uVar6 = iVar15 + 1;
          uVar16 = iVar28 >> 3;
          if (uVar16 < uVar6) {
            uVar16 = uVar6;
          }
        }
        else {
          uVar16 = 0xfffffff;
        }
        FUN_001d53d2(&local_b0,uVar16,iVar15,param_3 + 7);
        *local_a8 = 0;
        local_a8[1] = 0;
        local_a8[2] = 0;
        local_a8[3] = uVar33;
        local_a8 = local_a8 + 4;
        FUN_001d541e(param_3 + 4,&local_b0);
        FUN_001d548a(&local_b0);
      }
      if ((uint)(iVar23 * -0x55555555) < uVar29) {
        iVar28 = uVar29 + iVar23 * 0x55555555;
        iVar23 = iVar23 * 8 + 0xc;
        do {
          local_a8 = (uint *)0x0;
          local_b0 = 0;
          local_ac = 0;
          bVar32 = *(byte *)(*param_3 + iVar23);
          iVar21 = *param_3 + iVar23;
          uVar29 = *(uint *)(iVar21 + 4);
          iVar15 = *(int *)(iVar21 + 8);
          if ((bVar32 & 1) == 0) {
            iVar15 = iVar21 + 1;
            uVar29 = (uint)(bVar32 >> 1);
          }
          if (1 < uVar29) {
            uVar29 = 2;
          }
          FUN_001c5e62(&local_b0,iVar15,uVar29);
          bVar36 = false;
          uVar29 = local_ac;
          if ((local_b0 & 1) == 0) {
            uVar29 = local_b0 >> 1 & 0x7f;
          }
          if (uVar29 == 2) {
            bVar36 = false;
            puVar13 = local_a8;
            if ((local_b0 & 1) == 0) {
              puVar13 = (uint *)((uint)&local_b0 | 1);
            }
            if ((short)*puVar13 == 0x5b20) {
              bVar36 = true;
            }
          }
          if ((local_b0 & 1) != 0) {
            free(local_a8);
          }
          iVar15 = *param_3;
          if (bVar36) {
            FUN_001cb080(iVar15 + iVar23 + -0xc,&DAT_0022045a,2);
            FUN_001caf2a(*param_3 + iVar23,0,&DAT_0022045d,1);
          }
          else {
            uVar14 = *(ushort *)(iVar15 + iVar23);
            if ((uVar14 & 1) == 0) {
              uVar29 = (uVar14 & 0xff) >> 1;
            }
            else {
              uVar29 = *(uint *)(iVar15 + iVar23 + 4);
            }
            if (uVar29 != 0) {
              if ((uVar14 & 1) == 0) {
                uVar14 = uVar14 >> 8;
              }
              else {
                uVar14 = (ushort)**(byte **)(iVar15 + iVar23 + 8);
              }
              if (uVar14 == 0x28) {
                FUN_001cb080(iVar15 + iVar23 + -0xc,&DAT_00222248,1);
                FUN_001caf2a(*param_3 + iVar23,0,&DAT_0022045d,1);
              }
            }
          }
          FUN_001cb080(*param_3 + iVar23 + -0xc,&DAT_0022221f,1);
          iVar25 = param_3[5];
          iVar21 = *param_3;
          iVar15 = *(int *)(iVar25 + -0xc);
          if (iVar15 == *(int *)(iVar25 + -8)) {
            iVar15 = iVar15 - *(int *)(iVar25 + -0x10) >> 3;
            uVar33 = iVar15 * -0x55555555;
            uVar29 = 0xaaaaaaa;
            if (uVar33 < 0x5555555) {
              uVar29 = iVar15 * 0x55555556;
              if (uVar29 < uVar33 + 1) {
                uVar29 = uVar33 + 1;
              }
            }
            FUN_001ccdd4(&local_b0,uVar29,uVar33,iVar25 + -4);
            iVar21 = iVar21 + iVar23;
            iVar15 = FUN_001c5e34(local_a8,iVar21 + -0xc);
            FUN_001c5e34(iVar15 + 0xc,iVar21);
            local_a8 = local_a8 + 6;
            FUN_001cce32(iVar25 + -0x10,&local_b0);
            FUN_001cceae(&local_b0);
          }
          else {
            iVar21 = iVar21 + iVar23;
            iVar15 = FUN_001c5e34(iVar15,iVar21 + -0xc);
            FUN_001c5e34(iVar15 + 0xc,iVar21);
            *(int *)(iVar25 + -0xc) = *(int *)(iVar25 + -0xc) + 0x18;
          }
          iVar23 = iVar23 + 0x18;
          iVar28 = iVar28 + -1;
        } while (iVar28 != 0);
      }
    }
    break;
  case 0x53:
    if ((param_1 + 1 == param_2) || (param_1[1] != 0x74)) {
      pbVar27 = (byte *)FUN_001cb6bc(param_1,param_2,param_3);
      if ((pbVar27 != param_1) &&
         ((pbVar4 = (byte *)FUN_001cb15c(pbVar27,param_2,param_3), pbVar4 != pbVar27 &&
          (iVar23 = param_3[1], 1 < (uint)((iVar23 - *param_3 >> 3) * -0x55555555))))) {
        uVar29 = *(uint *)(iVar23 + -8);
        iVar28 = *(int *)(iVar23 + -4);
        if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
          iVar28 = iVar23 + -0xb;
          uVar29 = (uint)(*(byte *)(iVar23 + -0xc) >> 1);
        }
        puVar13 = (uint *)FUN_001cb080(iVar23 + -0x18,iVar28,uVar29);
        local_38 = *puVar13;
        local_34 = puVar13[1];
        local_30 = (uint *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        iVar28 = param_3[1];
        iVar23 = iVar28;
        do {
          param_3[1] = iVar23 + -0x18;
          if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
            free(*(void **)(iVar23 + -4));
          }
          if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
            free(*(void **)(iVar23 + -0x10));
          }
          puVar13 = local_30;
          iVar23 = param_3[1];
        } while (iVar23 != iVar28 + -0x18);
        uVar29 = local_38 & 1;
        uVar33 = local_34;
        puVar18 = local_30;
        if ((local_38 & 1) == 0) {
          puVar18 = (uint *)((uint)&local_38 | 1);
          uVar33 = local_38 >> 1 & 0x7f;
        }
        FUN_001cb080(iVar28 + -0x30,puVar18,uVar33);
        local_60 = param_3[3];
        FUN_001cb104(&local_50,param_3[1] + -0x18,&local_60);
        puVar18 = (uint *)param_3[5];
        if (puVar18 < (uint *)param_3[6]) {
          *puVar18 = 0;
          puVar18[1] = 0;
          puVar18[2] = 0;
          puVar18[3] = local_44;
          *puVar18 = local_50;
          puVar18[1] = local_4c;
          puVar18[2] = (uint)local_48;
          local_48 = (void *)0x0;
          local_50 = 0;
          local_4c = 0;
          param_3[5] = param_3[5] + 0x10;
        }
        else {
          iVar23 = param_3[6] - param_3[4];
          iVar28 = (int)puVar18 - param_3[4] >> 4;
          if ((uint)(iVar23 >> 4) < 0x7ffffff) {
            uVar16 = iVar28 + 1;
            uVar33 = iVar23 >> 3;
            if (uVar33 < uVar16) {
              uVar33 = uVar16;
            }
          }
          else {
            uVar33 = 0xfffffff;
          }
          FUN_001d53d2(&local_b0,uVar33,iVar28,param_3 + 7);
          *local_a8 = 0;
          local_a8[1] = 0;
          local_a8[2] = 0;
          local_a8[3] = local_44;
          *local_a8 = local_50;
          local_a8[1] = local_4c;
          local_a8[2] = (uint)local_48;
          local_48 = (void *)0x0;
          local_50 = 0;
          local_4c = 0;
          local_a8 = local_a8 + 4;
          FUN_001d541e(param_3 + 4,&local_b0);
          FUN_001d548a(&local_b0);
        }
        FUN_001c5dac(&local_50);
        if (uVar29 != 0) {
          free(puVar13);
        }
      }
      break;
    }
    pbVar27 = (byte *)FUN_001c9fb8(param_1,param_2,param_3,0);
    if (pbVar27 == param_1) break;
    iVar28 = *param_3;
    iVar23 = param_3[1];
LAB_001c88a0:
    if (iVar28 == iVar23) break;
    goto LAB_001c88a6;
  case 0x54:
    iVar28 = *param_3;
    iVar23 = param_3[1];
    pbVar27 = (byte *)FUN_001cbc74(param_1,param_2,param_3);
    if (pbVar27 != param_1) {
      uVar29 = param_3[3];
      iVar23 = iVar23 - iVar28 >> 3;
      uVar33 = (param_3[1] - *param_3 >> 3) * -0x55555555;
      puVar10 = (undefined4 *)param_3[5];
      if (puVar10 < (undefined4 *)param_3[6]) {
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = uVar29;
        param_3[5] = param_3[5] + 0x10;
      }
      else {
        iVar28 = param_3[6] - param_3[4];
        iVar15 = (int)puVar10 - param_3[4] >> 4;
        if ((uint)(iVar28 >> 4) < 0x7ffffff) {
          uVar6 = iVar15 + 1;
          uVar16 = iVar28 >> 3;
          if (uVar16 < uVar6) {
            uVar16 = uVar6;
          }
        }
        else {
          uVar16 = 0xfffffff;
        }
        FUN_001d53d2(&local_b0,uVar16,iVar15,param_3 + 7);
        *local_a8 = 0;
        local_a8[1] = 0;
        local_a8[2] = 0;
        local_a8[3] = uVar29;
        local_a8 = local_a8 + 4;
        FUN_001d541e(param_3 + 4,&local_b0);
        FUN_001d548a(&local_b0);
      }
      if ((uint)(iVar23 * -0x55555555) < uVar33) {
        iVar28 = uVar33 + iVar23 * 0x55555555;
        iVar15 = iVar23 * 8;
        do {
          iVar30 = param_3[5];
          iVar25 = *param_3;
          iVar21 = *(int *)(iVar30 + -0xc);
          if (iVar21 == *(int *)(iVar30 + -8)) {
            iVar21 = iVar21 - *(int *)(iVar30 + -0x10) >> 3;
            uVar16 = iVar21 * -0x55555555;
            uVar29 = 0xaaaaaaa;
            if (uVar16 < 0x5555555) {
              uVar29 = iVar21 * 0x55555556;
              if (uVar29 < uVar16 + 1) {
                uVar29 = uVar16 + 1;
              }
            }
            FUN_001ccdd4(&local_b0,uVar29,uVar16,iVar30 + -4);
            iVar25 = iVar25 + iVar15;
            iVar21 = FUN_001c5e34(local_a8,iVar25);
            FUN_001c5e34(iVar21 + 0xc,iVar25 + 0xc);
            local_a8 = local_a8 + 6;
            FUN_001cce32(iVar30 + -0x10,&local_b0);
            FUN_001cceae(&local_b0);
          }
          else {
            iVar25 = iVar25 + iVar15;
            iVar21 = FUN_001c5e34(iVar21,iVar25);
            FUN_001c5e34(iVar21 + 0xc,iVar25 + 0xc);
            *(int *)(iVar30 + -0xc) = *(int *)(iVar30 + -0xc) + 0x18;
          }
          iVar15 = iVar15 + 0x18;
          iVar28 = iVar28 + -1;
        } while (iVar28 != 0);
      }
      if (((uVar33 == iVar23 * -0x55555555 + 1U) && (*(char *)((int)param_3 + 0x3f) != '\0')) &&
         (pbVar4 = (byte *)FUN_001cb15c(pbVar27,param_2,param_3), pbVar4 != pbVar27)) {
        iVar28 = param_3[1];
        uVar29 = *(uint *)(iVar28 + -8);
        iVar23 = *(int *)(iVar28 + -4);
        if ((*(byte *)(iVar28 + -0xc) & 1) == 0) {
          iVar23 = iVar28 + -0xb;
          uVar29 = (uint)(*(byte *)(iVar28 + -0xc) >> 1);
        }
        puVar13 = (uint *)FUN_001cb080(iVar28 + -0x18,iVar23,uVar29);
        local_38 = *puVar13;
        local_34 = puVar13[1];
        local_30 = (uint *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        iVar28 = param_3[1];
        iVar23 = iVar28;
        do {
          param_3[1] = iVar23 + -0x18;
          if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
            free(*(void **)(iVar23 + -4));
          }
          if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
            free(*(void **)(iVar23 + -0x10));
          }
          puVar13 = local_30;
          iVar23 = param_3[1];
        } while (iVar23 != iVar28 + -0x18);
        uVar29 = local_38 & 1;
        uVar33 = local_34;
        puVar18 = local_30;
        if ((local_38 & 1) == 0) {
          puVar18 = (uint *)((uint)&local_38 | 1);
          uVar33 = local_38 >> 1 & 0x7f;
        }
        FUN_001cb080(iVar28 + -0x30,puVar18,uVar33);
        local_60 = param_3[3];
        FUN_001cb104(&local_50,param_3[1] + -0x18,&local_60);
        puVar18 = (uint *)param_3[5];
        if (puVar18 < (uint *)param_3[6]) {
          *puVar18 = 0;
          puVar18[1] = 0;
          puVar18[2] = 0;
          puVar18[3] = local_44;
          *puVar18 = local_50;
          puVar18[1] = local_4c;
          puVar18[2] = (uint)local_48;
          local_48 = (void *)0x0;
          local_50 = 0;
          local_4c = 0;
          param_3[5] = param_3[5] + 0x10;
        }
        else {
          iVar23 = param_3[6] - param_3[4];
          iVar28 = (int)puVar18 - param_3[4] >> 4;
          if ((uint)(iVar23 >> 4) < 0x7ffffff) {
            uVar16 = iVar28 + 1;
            uVar33 = iVar23 >> 3;
            if (uVar33 < uVar16) {
              uVar33 = uVar16;
            }
          }
          else {
            uVar33 = 0xfffffff;
          }
          FUN_001d53d2(&local_b0,uVar33,iVar28,param_3 + 7);
          *local_a8 = 0;
          local_a8[1] = 0;
          local_a8[2] = 0;
          local_a8[3] = local_44;
          *local_a8 = local_50;
          local_a8[1] = local_4c;
          local_a8[2] = (uint)local_48;
          local_48 = (void *)0x0;
          local_50 = 0;
          local_4c = 0;
          local_a8 = local_a8 + 4;
          FUN_001d541e(param_3 + 4,&local_b0);
          FUN_001d548a(&local_b0);
        }
        FUN_001c5dac(&local_50);
        if (uVar29 != 0) {
          free(puVar13);
        }
      }
    }
    break;
  case 0x55:
    param_1 = param_1 + 1;
    if ((((param_1 == param_2) ||
         (pbVar27 = (byte *)FUN_001d4de4(param_1,param_2,param_3), pbVar27 == param_1)) ||
        (pbVar4 = (byte *)FUN_001c6af0(pbVar27,param_2,param_3), pbVar4 == pbVar27)) ||
       (iVar23 = param_3[1], (uint)((iVar23 - *param_3 >> 3) * -0x55555555) < 2)) break;
    uVar29 = *(uint *)(iVar23 + -8);
    iVar28 = *(int *)(iVar23 + -4);
    if ((*(byte *)(iVar23 + -0xc) & 1) == 0) {
      iVar28 = iVar23 + -0xb;
      uVar29 = (uint)(*(byte *)(iVar23 + -0xc) >> 1);
    }
    puVar13 = (uint *)FUN_001cb080(iVar23 + -0x18,iVar28,uVar29);
    local_38 = *puVar13;
    local_34 = puVar13[1];
    local_30 = (uint *)puVar13[2];
    *puVar13 = 0;
    puVar13[1] = 0;
    puVar13[2] = 0;
    iVar28 = param_3[1];
    iVar23 = iVar28;
    do {
      param_3[1] = iVar23 + -0x18;
      if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
        free(*(void **)(iVar23 + -4));
      }
      if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
        free(*(void **)(iVar23 + -0x10));
      }
      iVar23 = param_3[1];
    } while (iVar23 != iVar28 + -0x18);
    local_a8 = (uint *)0x0;
    local_b0 = 0;
    local_ac = 0;
    uVar29 = *(uint *)(iVar28 + -0x2c);
    iVar23 = *(int *)(iVar28 + -0x28);
    if ((*(byte *)(iVar28 + -0x30) & 1) == 0) {
      iVar23 = iVar28 + -0x2f;
      uVar29 = (uint)(*(byte *)(iVar28 + -0x30) >> 1);
    }
    if (8 < uVar29) {
      uVar29 = 9;
    }
    FUN_001c5e62(&local_b0,iVar23,uVar29);
    uVar29 = local_b0 & 1;
    uVar33 = local_ac;
    if ((local_b0 & 1) == 0) {
      uVar33 = local_b0 >> 1 & 0x7f;
    }
    if (uVar33 == 9) {
      puVar13 = local_a8;
      if ((local_b0 & 1) == 0) {
        puVar13 = (uint *)((uint)&local_b0 | 1);
      }
      iVar23 = memcmp(puVar13,"objcproto",9);
      bVar36 = iVar23 != 0;
    }
    else {
      bVar36 = true;
    }
    if (uVar29 != 0) {
      free(local_a8);
    }
    if (bVar36) {
      iVar28 = param_3[1];
      FUN_001d2f64(&local_50,&local_38,&DAT_0021f760);
      iVar15 = param_3[1];
      uVar29 = *(uint *)(iVar15 + -8);
      iVar23 = *(int *)(iVar15 + -4);
      if ((*(byte *)(iVar15 + -0xc) & 1) == 0) {
        iVar23 = iVar15 + -0xb;
        uVar29 = (uint)(*(byte *)(iVar15 + -0xc) >> 1);
      }
      puVar13 = (uint *)FUN_001cb080(iVar15 + -0x18,iVar23,uVar29);
      uVar29 = *puVar13;
      local_5c = puVar13[1];
      pvVar26 = (void *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      uVar33 = local_5c;
      pvVar19 = pvVar26;
      if ((uVar29 & 1) == 0) {
        pvVar19 = (void *)((uint)&local_60 | 1);
        uVar33 = uVar29 >> 1 & 0x7f;
      }
      local_60 = uVar29;
      local_58 = pvVar26;
      puVar10 = (undefined4 *)FUN_001cb080(&local_50,pvVar19,uVar33);
      uVar3 = *(undefined1 *)puVar10;
      __aeabi_memcpy(&local_78,(int)puVar10 + 1,7);
      puVar13 = (uint *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      local_b0 = CONCAT31(local_b0._1_3_,uVar3);
      __aeabi_memcpy((uint)&local_b0 | 1,&local_78,7);
      local_72 = 0;
      local_74 = 0;
      local_78 = 0;
      local_9c = (char *)0x0;
      local_a4 = 0;
      local_a0 = 0;
      local_a8 = puVar13;
      FUN_001d0d6c(iVar28 + -0x18,&local_b0);
      if ((local_a4 & 1) != 0) {
        free(local_9c);
      }
      if ((local_b0 & 1) != 0) {
        free(local_a8);
      }
joined_r0x001c8610:
      if ((uVar29 & 1) != 0) {
        free(pvVar26);
      }
    }
    else {
      iVar28 = param_3[1];
      uVar29 = *(uint *)(iVar28 + -8);
      iVar23 = *(int *)(iVar28 + -4);
      if ((*(byte *)(iVar28 + -0xc) & 1) == 0) {
        iVar23 = iVar28 + -0xb;
        uVar29 = (uint)(*(byte *)(iVar28 + -0xc) >> 1);
      }
      puVar13 = (uint *)FUN_001cb080(iVar28 + -0x18,iVar23,uVar29);
      local_50 = *puVar13;
      local_4c = puVar13[1];
      local_48 = (void *)puVar13[2];
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      iVar23 = param_3[1];
      iVar28 = iVar23 + -0x18;
      do {
        param_3[1] = iVar23 + -0x18;
        if ((*(byte *)(iVar23 + -0xc) & 1) != 0) {
          free(*(void **)(iVar23 + -4));
        }
        if ((*(byte *)(iVar23 + -0x18) & 1) != 0) {
          free(*(void **)(iVar23 + -0x10));
        }
        iVar23 = param_3[1];
      } while (iVar23 != iVar28);
      pvVar19 = (void *)((uint)&local_50 | 1);
      pvVar26 = local_48;
      uVar29 = local_4c;
      if ((local_50 & 1) == 0) {
        uVar29 = local_50 >> 1 & 0x7f;
        pvVar26 = pvVar19;
      }
      iVar23 = FUN_001d4de4((int)pvVar26 + 9,(int)pvVar26 + uVar29);
      pvVar26 = local_48;
      if ((local_50 & 1) == 0) {
        pvVar26 = pvVar19;
      }
      if (iVar23 != (int)pvVar26 + 9U) {
        iVar28 = param_3[1];
        FUN_001d2f64(&local_70,&local_38,&DAT_0021f77b);
        iVar15 = param_3[1];
        uVar29 = *(uint *)(iVar15 + -8);
        iVar23 = *(int *)(iVar15 + -4);
        if ((*(byte *)(iVar15 + -0xc) & 1) == 0) {
          iVar23 = iVar15 + -0xb;
          uVar29 = (uint)(*(byte *)(iVar15 + -0xc) >> 1);
        }
        puVar13 = (uint *)FUN_001cb080(iVar15 + -0x18,iVar23,uVar29);
        local_90 = *puVar13;
        local_8c = puVar13[1];
        pvVar19 = (void *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        uVar33 = local_90 & 1;
        uVar29 = local_8c;
        pvVar26 = pvVar19;
        if ((local_90 & 1) == 0) {
          pvVar26 = (void *)((uint)&local_90 | 1);
          uVar29 = local_90 >> 1 & 0x7f;
        }
        pvStack_88 = pvVar19;
        puVar13 = (uint *)FUN_001cb080(&local_70,pvVar26,uVar29);
        local_60 = *puVar13;
        local_5c = puVar13[1];
        local_58 = (void *)puVar13[2];
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar10 = (undefined4 *)FUN_001cb080(&local_60,&DAT_0021f77f,1);
        uVar3 = *(undefined1 *)puVar10;
        __aeabi_memcpy(&local_80,(int)puVar10 + 1,7);
        puVar13 = (uint *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        local_b0 = CONCAT31(local_b0._1_3_,uVar3);
        __aeabi_memcpy((uint)&local_b0 | 1,&local_80,7);
        local_7a = 0;
        local_7c = 0;
        local_80 = 0;
        local_9c = (char *)0x0;
        local_a4 = 0;
        local_a0 = 0;
        local_a8 = puVar13;
        FUN_001d0d6c(iVar28 + -0x18,&local_b0);
        if ((local_a4 & 1) != 0) {
          free(local_9c);
        }
        if ((local_b0 & 1) != 0) {
          free(local_a8);
        }
        if ((local_60 & 1) != 0) {
          free(local_58);
        }
        pvVar26 = local_68;
        uVar29 = local_70;
        if (uVar33 != 0) {
          free(pvVar19);
          pvVar26 = local_68;
          uVar29 = local_70;
        }
        goto joined_r0x001c8610;
      }
      FUN_001d2f64(&local_60,&local_38,&DAT_0021f760);
      uVar29 = local_4c;
      pvVar26 = local_48;
      if ((local_50 & 1) == 0) {
        uVar29 = local_50 >> 1 & 0x7f;
        pvVar26 = pvVar19;
      }
      pbVar27 = (byte *)FUN_001cb080(&local_60,pvVar26,uVar29);
      bVar32 = *pbVar27;
      __aeabi_memcpy(&local_98,pbVar27 + 1,7);
      uVar29 = *(uint *)(pbVar27 + 8);
      pbVar27[0] = 0;
      pbVar27[1] = 0;
      pbVar27[2] = 0;
      pbVar27[3] = 0;
      pbVar27[4] = 0;
      pbVar27[5] = 0;
      pbVar27[6] = 0;
      pbVar27[7] = 0;
      pbVar27[8] = 0;
      pbVar27[9] = 0;
      pbVar27[10] = 0;
      pbVar27[0xb] = 0;
      __aeabi_memcpy(&local_70,&local_98,7);
      local_92 = 0;
      local_94 = 0;
      local_8c = (uint)local_8c._3_1_ << 0x18;
      local_98 = 0;
      local_90 = 0;
      pbVar27 = (byte *)param_3[1];
      if (pbVar27 < (byte *)param_3[2]) {
        *pbVar27 = bVar32;
        __aeabi_memcpy(pbVar27 + 1,&local_70,7);
        *(uint *)(pbVar27 + 8) = uVar29;
        local_6c = (uint)local_6c._3_1_ << 0x18;
        local_70 = 0;
        pbVar27[0xc] = 0;
        __aeabi_memcpy(pbVar27 + 0xd,&local_90,7);
        pbVar27[0x14] = 0;
        pbVar27[0x15] = 0;
        pbVar27[0x16] = 0;
        pbVar27[0x17] = 0;
        local_8c = local_8c & 0xff000000;
        local_90 = 0;
        param_3[1] = param_3[1] + 0x18;
      }
      else {
        iVar23 = param_3[2] - *param_3 >> 3;
        iVar28 = ((int)pbVar27 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar23 * -0x55555555) < 0x5555555) {
          uVar33 = iVar28 + 1;
          local_c4 = iVar23 * 0x55555556;
          if (local_c4 < uVar33) {
            local_c4 = uVar33;
          }
        }
        FUN_001ccdd4(&local_b0,local_c4,iVar28,param_3 + 3);
        puVar13 = local_a8;
        *(byte *)local_a8 = bVar32;
        __aeabi_memcpy((byte *)((int)local_a8 + 1),&local_70,7);
        puVar13[2] = uVar29;
        local_6c = (uint)local_6c._3_1_ << 0x18;
        local_70 = 0;
        *(byte *)(puVar13 + 3) = 0;
        __aeabi_memcpy((byte *)((int)puVar13 + 0xd),&local_90,7);
        puVar13[5] = 0;
        local_a8 = local_a8 + 6;
        local_8c = local_8c & 0xff000000;
        local_90 = 0;
        FUN_001cce32(param_3,&local_b0);
        FUN_001cceae(&local_b0);
      }
      if ((local_60 & 1) != 0) {
        free(local_58);
      }
    }
    if ((local_50 & 1) != 0) {
      free(local_48);
    }
    local_60 = param_3[3];
    FUN_001cb104(&local_50,param_3[1] + -0x18,&local_60);
    puVar13 = (uint *)param_3[5];
    if (puVar13 < (uint *)param_3[6]) {
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = local_44;
      *puVar13 = local_50;
      puVar13[1] = local_4c;
      puVar13[2] = (uint)local_48;
      local_48 = (void *)0x0;
      local_50 = 0;
      local_4c = 0;
      param_3[5] = param_3[5] + 0x10;
    }
    else {
      iVar23 = param_3[6] - param_3[4];
      iVar28 = (int)puVar13 - param_3[4] >> 4;
      if ((uint)(iVar23 >> 4) < 0x7ffffff) {
        uVar33 = iVar28 + 1;
        uVar29 = iVar23 >> 3;
        if (uVar29 < uVar33) {
          uVar29 = uVar33;
        }
      }
      else {
        uVar29 = 0xfffffff;
      }
      FUN_001d53d2(&local_b0,uVar29,iVar28,param_3 + 7);
      *local_a8 = 0;
      local_a8[1] = 0;
      local_a8[2] = 0;
      local_a8[3] = local_44;
      *local_a8 = local_50;
      local_a8[1] = local_4c;
      local_a8[2] = (uint)local_48;
      local_48 = (void *)0x0;
      local_50 = 0;
      local_4c = 0;
      local_a8 = local_a8 + 4;
      FUN_001d541e(param_3 + 4,&local_b0);
      FUN_001d548a(&local_b0);
    }
    FUN_001c5dac(&local_50);
    if ((local_38 & 1) != 0) {
      free(local_30);
    }
  }
LAB_001c98c8:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FUN_001c9fb8  @0x001c9fb8  (3710 bytes)
void FUN_001c9fb8(byte *param_1,byte *param_2,int *param_3,undefined1 *param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int *piVar6;
  byte *pbVar7;
  int iVar8;
  uint *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  void *pvVar14;
  byte *pbVar15;
  undefined1 uVar16;
  int iVar17;
  bool bVar18;
  bool bVar19;
  byte *local_80;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  uint local_4c;
  void *local_48;
  uint local_40;
  uint local_3c;
  undefined4 *local_38;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((int)param_2 - (int)param_1 < 2) goto LAB_001cadaa;
  pbVar7 = param_1 + 1;
  if (*param_1 != 0x4c) {
    pbVar7 = param_1;
  }
  bVar1 = *pbVar7;
  if (bVar1 == 0x5a) {
    if ((((pbVar7 != param_2) &&
         (pbVar4 = (byte *)FUN_001c5f90(pbVar7 + 1,param_2,param_3),
         pbVar4 != pbVar7 + 1 && pbVar4 != param_2)) && (*pbVar4 == 0x45)) &&
       (pbVar7 = pbVar4 + 1, pbVar7 != param_2)) {
      if (*pbVar7 == 100) {
        if (((pbVar4 + 2 != param_2) &&
            (pbVar7 = (byte *)FUN_001caeea(pbVar4 + 2,param_2), pbVar7 != param_2)) &&
           (*pbVar7 == 0x5f)) {
          pbVar4 = (byte *)FUN_001c9fb8(pbVar7 + 1,param_2,param_3,param_4);
          if (pbVar4 == pbVar7 + 1) {
            iVar3 = param_3[1];
            if (*param_3 != iVar3) {
              iVar8 = iVar3 + -0x18;
              do {
                param_3[1] = iVar3 + -0x18;
                if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar3 + -4));
                }
                if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar3 + -0x10));
                }
                iVar3 = param_3[1];
              } while (iVar3 != iVar8);
            }
          }
          else {
            iVar3 = param_3[1];
            if (1 < (uint)((iVar3 - *param_3 >> 3) * -0x55555555)) {
              uVar13 = *(uint *)(iVar3 + -8);
              iVar8 = *(int *)(iVar3 + -4);
              if ((*(byte *)(iVar3 + -0xc) & 1) == 0) {
                iVar8 = iVar3 + -0xb;
                uVar13 = (uint)(*(byte *)(iVar3 + -0xc) >> 1);
              }
              puVar9 = (uint *)FUN_001cb080(iVar3 + -0x18,iVar8,uVar13);
              local_40 = *puVar9;
              local_3c = puVar9[1];
              local_38 = (undefined4 *)puVar9[2];
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar9[2] = 0;
              iVar8 = param_3[1];
              iVar3 = iVar8;
              do {
                param_3[1] = iVar3 + -0x18;
                if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar3 + -4));
                }
                if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar3 + -0x10));
                }
                iVar3 = param_3[1];
              } while (iVar3 != iVar8 + -0x18);
              uVar13 = local_40;
              if (*param_3 != iVar8 + -0x18) {
                FUN_001cb080(iVar8 + -0x30,&DAT_0022220f,2);
                uVar13 = local_40;
                uVar5 = local_3c;
                puVar10 = local_38;
                if ((local_40 & 1) == 0) {
                  puVar10 = (undefined4 *)((uint)&local_40 | 1);
                  uVar5 = local_40 >> 1 & 0x7f;
                }
                FUN_001cb080(param_3[1] + -0x18,puVar10,uVar5);
              }
              if ((uVar13 & 1) != 0) {
                free(local_38);
              }
            }
          }
        }
      }
      else if (*pbVar7 == 0x73) {
        FUN_001d536e(pbVar4 + 2,param_2);
        if (*param_3 != param_3[1]) {
          FUN_001cb080(param_3[1] + -0x18,"::string literal",0x10);
        }
      }
      else {
        pbVar4 = (byte *)FUN_001c9fb8(pbVar7,param_2,param_3,param_4);
        if (pbVar4 == pbVar7) {
          iVar3 = param_3[1];
          if (*param_3 != iVar3) {
            iVar8 = iVar3 + -0x18;
            do {
              param_3[1] = iVar3 + -0x18;
              if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
                free(*(void **)(iVar3 + -4));
              }
              if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
                free(*(void **)(iVar3 + -0x10));
              }
              iVar3 = param_3[1];
            } while (iVar3 != iVar8);
          }
        }
        else {
          FUN_001d536e(pbVar4,param_2);
          iVar3 = param_3[1];
          if (1 < (uint)((iVar3 - *param_3 >> 3) * -0x55555555)) {
            uVar13 = *(uint *)(iVar3 + -8);
            iVar8 = *(int *)(iVar3 + -4);
            if ((*(byte *)(iVar3 + -0xc) & 1) == 0) {
              iVar8 = iVar3 + -0xb;
              uVar13 = (uint)(*(byte *)(iVar3 + -0xc) >> 1);
            }
            puVar9 = (uint *)FUN_001cb080(iVar3 + -0x18,iVar8,uVar13);
            local_40 = *puVar9;
            local_3c = puVar9[1];
            local_38 = (undefined4 *)puVar9[2];
            *puVar9 = 0;
            puVar9[1] = 0;
            puVar9[2] = 0;
            iVar8 = param_3[1];
            iVar3 = iVar8;
            do {
              param_3[1] = iVar3 + -0x18;
              if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
                free(*(void **)(iVar3 + -4));
              }
              if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
                free(*(void **)(iVar3 + -0x10));
              }
              iVar3 = param_3[1];
            } while (iVar3 != iVar8 + -0x18);
            uVar13 = local_40;
            if (*param_3 != iVar8 + -0x18) {
              FUN_001cb080(iVar8 + -0x30,&DAT_0022220f,2);
              uVar13 = local_40;
              uVar5 = local_3c;
              puVar10 = local_38;
              if ((local_40 & 1) == 0) {
                puVar10 = (undefined4 *)((uint)&local_40 | 1);
                uVar5 = local_40 >> 1 & 0x7f;
              }
              FUN_001cb080(param_3[1] + -0x18,puVar10,uVar5);
            }
            if ((uVar13 & 1) != 0) {
              free(local_38);
            }
          }
        }
      }
    }
    goto LAB_001cadaa;
  }
  if (bVar1 == 0x4e) {
    if ((pbVar7 == param_2) || (local_80 = pbVar7 + 1, local_80 == param_2)) goto LAB_001cadaa;
    bVar1 = *local_80;
    if (bVar1 == 0x72) {
      uVar13 = 4;
      local_80 = pbVar7 + 2;
      bVar1 = *local_80;
    }
    else {
      uVar13 = 0;
    }
    if (bVar1 == 0x56) {
      local_80 = local_80 + 1;
      bVar1 = *local_80;
      uVar13 = uVar13 | 2;
    }
    if (bVar1 == 0x4b) {
      local_80 = local_80 + 1;
      uVar13 = uVar13 | 1;
    }
    if (local_80 == param_2) goto LAB_001cadaa;
    param_3[0xd] = 0;
    if (*local_80 == 0x4f) {
      iVar3 = 2;
LAB_001ca29a:
      local_80 = local_80 + 1;
      param_3[0xd] = iVar3;
    }
    else if (*local_80 == 0x52) {
      iVar3 = 1;
      goto LAB_001ca29a;
    }
    uVar5 = param_3[1];
    if (uVar5 < (uint)param_3[2]) {
      __aeabi_memclr4(uVar5,0x18);
      param_3[1] = param_3[1] + 0x18;
    }
    else {
      iVar8 = ((int)(uVar5 - *param_3) >> 3) * -0x55555555;
      iVar3 = param_3[2] - *param_3 >> 3;
      if ((uint)(iVar3 * -0x55555555) < 0x5555555) {
        uVar11 = iVar8 + 1;
        uVar5 = iVar3 * 0x55555556;
        if (uVar5 < uVar11) {
          uVar5 = uVar11;
        }
      }
      else {
        uVar5 = 0xaaaaaaa;
      }
      FUN_001ccdd4(&local_40,uVar5,iVar8,param_3 + 3);
      __aeabi_memclr4(local_38,0x18);
      local_38 = local_38 + 6;
      FUN_001cce32(param_3,&local_40);
      FUN_001cceae(&local_40);
    }
    if (1 < (int)param_2 - (int)local_80) {
      bVar1 = *local_80;
      bVar18 = bVar1 == 0x53;
      if (bVar18) {
        bVar1 = local_80[1];
      }
      if (bVar18 && bVar1 == 0x74) {
        FUN_001ccf02(param_3[1] + -0x18,&DAT_0022220b,3);
        local_80 = local_80 + 2;
      }
    }
    if (local_80 != param_2) {
      piVar6 = param_3 + 4;
      uVar16 = 0;
      bVar18 = false;
LAB_001ca388:
      uVar5 = (uint)*local_80;
      iVar3 = uVar5 - 0x44;
      switch(iVar3) {
      case 0:
        pbVar7 = local_80 + 1;
        bVar19 = pbVar7 != param_2;
        if (bVar19) {
          pbVar7 = (byte *)(*pbVar7 | 0x20);
        }
        if (bVar19 && pbVar7 != (byte *)0x74) goto switchD_001ca394_caseD_2;
        pbVar7 = (byte *)FUN_001cc0b8(local_80,param_2,param_3);
        if (pbVar7 == local_80 || pbVar7 == param_2) goto LAB_001cadaa;
        iVar8 = param_3[1];
        uVar5 = *(uint *)(iVar8 + -8);
        iVar3 = *(int *)(iVar8 + -4);
        if ((*(byte *)(iVar8 + -0xc) & 1) == 0) {
          iVar3 = iVar8 + -0xb;
          uVar5 = (uint)(*(byte *)(iVar8 + -0xc) >> 1);
        }
        puVar9 = (uint *)FUN_001cb080(iVar8 + -0x18,iVar3,uVar5);
        local_50 = *puVar9;
        local_4c = puVar9[1];
        local_48 = (void *)puVar9[2];
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = 0;
        iVar8 = param_3[1];
        iVar3 = iVar8;
        do {
          param_3[1] = iVar3 + -0x18;
          if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
            free(*(void **)(iVar3 + -4));
          }
          if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
            free(*(void **)(iVar3 + -0x10));
          }
          iVar3 = param_3[1];
        } while (iVar3 != iVar8 + -0x18);
        if (*param_3 == iVar8 + -0x18) goto LAB_001ca86a;
        pbVar4 = (byte *)(iVar8 + -0x30);
        bVar1 = *pbVar4;
        bVar18 = (bVar1 & 1) == 0;
        if (bVar18) {
          bVar1 = bVar1 >> 1;
        }
        uVar5 = (uint)bVar1;
        if (!bVar18) {
          uVar5 = *(uint *)(iVar8 + -0x2c);
        }
        local_80 = pbVar7;
        if (uVar5 != 0) {
          FUN_001cbc00(&local_40,&DAT_0022220f,&local_50);
          goto LAB_001ca7f4;
        }
LAB_001ca72a:
        FUN_001cbc4a(pbVar4,&local_50);
LAB_001ca81e:
        local_64 = param_3[3];
        FUN_001cb104(&local_60,param_3[1] + -0x18,&local_64);
        puVar10 = (undefined4 *)param_3[5];
        if (puVar10 < (undefined4 *)param_3[6]) {
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          puVar10[3] = local_54;
          *puVar10 = local_60;
          puVar10[1] = local_5c;
          puVar10[2] = local_58;
          local_58 = 0;
          local_5c = 0;
          local_60 = 0;
          param_3[5] = param_3[5] + 0x10;
        }
        else {
          iVar3 = param_3[6] - *piVar6;
          iVar8 = (int)puVar10 - *piVar6 >> 4;
          if ((uint)(iVar3 >> 4) < 0x7ffffff) {
            uVar11 = iVar8 + 1;
            uVar5 = iVar3 >> 3;
            if (uVar5 < uVar11) {
              uVar5 = uVar11;
            }
          }
          else {
            uVar5 = 0xfffffff;
          }
          FUN_001d53d2(&local_40,uVar5,iVar8,param_3 + 7);
          *local_38 = 0;
          local_38[1] = 0;
          local_38[2] = 0;
          local_38[3] = local_54;
          *local_38 = local_60;
          local_38[1] = local_5c;
          local_38[2] = local_58;
          local_58 = 0;
          local_38 = local_38 + 4;
          local_5c = 0;
          local_60 = 0;
          FUN_001d541e(piVar6,&local_40);
          FUN_001d548a(&local_40);
        }
        FUN_001c5dac(&local_60);
        break;
      case 1:
        param_3[0xc] = uVar13;
        iVar8 = 0;
        if (bVar18) {
          iVar3 = param_3[4];
          iVar8 = param_3[5];
        }
        if (bVar18 && iVar3 != iVar8) {
          iVar3 = iVar8 + -0x10;
          do {
            param_3[5] = iVar8 + -0x10;
            FUN_001c5dac();
            iVar8 = param_3[5];
          } while (iVar8 != iVar3);
        }
        if (param_4 != (undefined1 *)0x0) {
          *param_4 = uVar16;
        }
        goto LAB_001cadaa;
      case 2:
      case 3:
      case 4:
      case 6:
      case 7:
switchD_001ca394_caseD_2:
        pbVar7 = (byte *)FUN_001cc234(local_80,param_2,param_3);
        if (pbVar7 != local_80 && pbVar7 != param_2) {
          iVar8 = param_3[1];
          uVar5 = *(uint *)(iVar8 + -8);
          iVar3 = *(int *)(iVar8 + -4);
          if ((*(byte *)(iVar8 + -0xc) & 1) == 0) {
            iVar3 = iVar8 + -0xb;
            uVar5 = (uint)(*(byte *)(iVar8 + -0xc) >> 1);
          }
          puVar9 = (uint *)FUN_001cb080(iVar8 + -0x18,iVar3,uVar5);
          local_50 = *puVar9;
          local_4c = puVar9[1];
          local_48 = (void *)puVar9[2];
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9[2] = 0;
          iVar8 = param_3[1];
          iVar3 = iVar8;
          do {
            param_3[1] = iVar3 + -0x18;
            if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
              free(*(void **)(iVar3 + -4));
            }
            if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
              free(*(void **)(iVar3 + -0x10));
            }
            iVar3 = param_3[1];
          } while (iVar3 != iVar8 + -0x18);
          if (*param_3 != iVar8 + -0x18) {
            pbVar4 = (byte *)(iVar8 + -0x30);
            bVar1 = *pbVar4;
            bVar18 = (bVar1 & 1) == 0;
            if (bVar18) {
              bVar1 = bVar1 >> 1;
            }
            uVar5 = (uint)bVar1;
            if (!bVar18) {
              uVar5 = *(uint *)(iVar8 + -0x2c);
            }
            local_80 = pbVar7;
            if (uVar5 == 0) goto LAB_001ca72a;
            FUN_001cbc00(&local_40,&DAT_0022220f,&local_50);
LAB_001ca7f4:
            uVar5 = local_3c;
            puVar10 = local_38;
            if ((local_40 & 1) == 0) {
              uVar5 = local_40 >> 1 & 0x7f;
              puVar10 = (undefined4 *)((uint)&local_40 | 1);
            }
            FUN_001cb080(pbVar4,puVar10,uVar5);
            if ((local_40 & 1) != 0) {
              free(local_38);
            }
            goto LAB_001ca81e;
          }
LAB_001ca86a:
          bVar19 = true;
          goto LAB_001ca8f2;
        }
        goto LAB_001cadaa;
      case 5:
        pbVar7 = (byte *)FUN_001cb15c(local_80,param_2,param_3);
        if (pbVar7 != local_80 && pbVar7 != param_2) goto code_r0x001ca570;
        goto LAB_001cadaa;
      case 8:
        local_80 = local_80 + 1;
        if (local_80 == param_2) goto LAB_001cadaa;
        uVar16 = 0;
        goto LAB_001ca388;
      default:
        if (uVar5 == 0x54) {
          pbVar7 = (byte *)FUN_001cbc74(local_80,param_2,param_3);
          if (pbVar7 != local_80 && pbVar7 != param_2) {
            iVar8 = param_3[1];
            uVar5 = *(uint *)(iVar8 + -8);
            iVar3 = *(int *)(iVar8 + -4);
            if ((*(byte *)(iVar8 + -0xc) & 1) == 0) {
              iVar3 = iVar8 + -0xb;
              uVar5 = (uint)(*(byte *)(iVar8 + -0xc) >> 1);
            }
            puVar9 = (uint *)FUN_001cb080(iVar8 + -0x18,iVar3,uVar5);
            local_50 = *puVar9;
            local_4c = puVar9[1];
            local_48 = (void *)puVar9[2];
            *puVar9 = 0;
            puVar9[1] = 0;
            puVar9[2] = 0;
            iVar8 = param_3[1];
            iVar3 = iVar8;
            do {
              param_3[1] = iVar3 + -0x18;
              if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
                free(*(void **)(iVar3 + -4));
              }
              if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
                free(*(void **)(iVar3 + -0x10));
              }
              iVar3 = param_3[1];
            } while (iVar3 != iVar8 + -0x18);
            if (*param_3 != iVar8 + -0x18) {
              pbVar4 = (byte *)(iVar8 + -0x30);
              bVar1 = *pbVar4;
              bVar18 = (bVar1 & 1) == 0;
              if (bVar18) {
                bVar1 = bVar1 >> 1;
              }
              uVar5 = (uint)bVar1;
              if (!bVar18) {
                uVar5 = *(uint *)(iVar8 + -0x2c);
              }
              local_80 = pbVar7;
              if (uVar5 == 0) goto LAB_001ca72a;
              FUN_001cbc00(&local_40,&DAT_0022220f,&local_50);
              goto LAB_001ca7f4;
            }
            goto LAB_001ca86a;
          }
          goto LAB_001cadaa;
        }
        if ((uVar5 != 0x53) || ((local_80 + 1 != param_2 && (local_80[1] == 0x74))))
        goto switchD_001ca394_caseD_2;
        pbVar7 = (byte *)FUN_001cb6bc(local_80,param_2,param_3);
        if (pbVar7 == local_80 || pbVar7 == param_2) goto LAB_001cadaa;
        iVar8 = param_3[1];
        uVar5 = *(uint *)(iVar8 + -8);
        iVar3 = *(int *)(iVar8 + -4);
        if ((*(byte *)(iVar8 + -0xc) & 1) == 0) {
          iVar3 = iVar8 + -0xb;
          uVar5 = (uint)(*(byte *)(iVar8 + -0xc) >> 1);
        }
        puVar9 = (uint *)FUN_001cb080(iVar8 + -0x18,iVar3,uVar5);
        local_50 = *puVar9;
        local_4c = puVar9[1];
        local_48 = (void *)puVar9[2];
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = 0;
        iVar8 = param_3[1];
        iVar3 = iVar8;
        do {
          param_3[1] = iVar3 + -0x18;
          if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
            free(*(void **)(iVar3 + -4));
          }
          if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
            free(*(void **)(iVar3 + -0x10));
          }
          iVar3 = param_3[1];
        } while (iVar3 != iVar8 + -0x18);
        if (*param_3 == iVar8 + -0x18) goto LAB_001ca86a;
        pbVar4 = (byte *)(iVar8 + -0x30);
        bVar1 = *pbVar4;
        bVar18 = (bVar1 & 1) == 0;
        if (bVar18) {
          bVar1 = bVar1 >> 1;
        }
        uVar5 = (uint)bVar1;
        if (!bVar18) {
          uVar5 = *(uint *)(iVar8 + -0x2c);
        }
        local_80 = pbVar7;
        if (uVar5 != 0) {
          FUN_001cbc00(&local_40,&DAT_0022220f,&local_50);
          goto LAB_001ca7f4;
        }
        FUN_001cbc4a(pbVar4,&local_50);
      }
      bVar19 = false;
      bVar18 = true;
LAB_001ca8f2:
      if ((local_50 & 1) != 0) {
        free(local_48);
      }
      if (bVar19) goto LAB_001cadaa;
      uVar16 = 0;
      goto LAB_001ca388;
    }
    iVar8 = param_3[1];
    iVar3 = iVar8 + -0x18;
    do {
      param_3[1] = iVar8 + -0x18;
      if ((*(byte *)(iVar8 + -0xc) & 1) != 0) {
        free(*(void **)(iVar8 + -4));
      }
      if ((*(byte *)(iVar8 + -0x18) & 1) != 0) {
        free(*(void **)(iVar8 + -0x10));
      }
      iVar8 = param_3[1];
    } while (iVar8 != iVar3);
    goto LAB_001cadaa;
  }
  if ((int)param_2 - (int)pbVar7 < 2) {
LAB_001ca1aa:
    pbVar4 = (byte *)FUN_001cb6bc(pbVar7,param_2,param_3);
    if ((((pbVar4 == pbVar7 || pbVar4 == param_2) || (*pbVar4 != 0x49)) ||
        (pbVar7 = (byte *)FUN_001cb15c(pbVar4,param_2,param_3), pbVar7 == pbVar4)) ||
       (iVar3 = param_3[1], (uint)((iVar3 - *param_3 >> 3) * -0x55555555) < 2)) goto LAB_001cadaa;
    uVar13 = *(uint *)(iVar3 + -8);
    iVar8 = *(int *)(iVar3 + -4);
    if ((*(byte *)(iVar3 + -0xc) & 1) == 0) {
      iVar8 = iVar3 + -0xb;
      uVar13 = (uint)(*(byte *)(iVar3 + -0xc) >> 1);
    }
    puVar9 = (uint *)FUN_001cb080(iVar3 + -0x18,iVar8,uVar13);
    local_40 = *puVar9;
    local_3c = puVar9[1];
    local_38 = (undefined4 *)puVar9[2];
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    iVar17 = param_3[1];
    iVar8 = iVar17 + -0x18;
    iVar3 = iVar17;
    do {
      param_3[1] = iVar3 + -0x18;
      if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
        free(*(void **)(iVar3 + -4));
      }
      if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
        free(*(void **)(iVar3 + -0x10));
      }
      iVar3 = param_3[1];
    } while (iVar3 != iVar8);
  }
  else {
    bVar18 = bVar1 == 0x53;
    if (bVar18) {
      bVar1 = pbVar7[1];
    }
    if (bVar18 && bVar1 == 0x74) {
      pbVar4 = pbVar7 + 2;
      if (pbVar4 == param_2) {
        bVar18 = false;
        pbVar4 = param_2;
      }
      else {
        if (pbVar7[2] == 0x4c) {
          pbVar4 = pbVar7 + 3;
        }
        bVar18 = false;
      }
    }
    else {
      bVar18 = true;
      pbVar4 = pbVar7;
    }
    pbVar2 = (byte *)FUN_001cc234(pbVar4,param_2,param_3);
    pbVar15 = pbVar2;
    if (pbVar2 == pbVar4) {
      pbVar15 = pbVar7;
    }
    if ((!bVar18) && (pbVar2 != pbVar4)) {
      if (*param_3 == param_3[1]) goto LAB_001ca1aa;
      FUN_001caf2a(param_3[1] + -0x18,0,"std::",5);
      pbVar15 = pbVar2;
    }
    if (pbVar15 == pbVar7) goto LAB_001ca1aa;
    if (((pbVar15 == param_2) || (*pbVar15 != 0x49)) || (*param_3 == param_3[1])) goto LAB_001cadaa;
    local_50 = param_3[3];
    FUN_001cb104(&local_60,param_3[1] + -0x18,&local_50);
    puVar10 = (undefined4 *)param_3[5];
    if (puVar10 < (undefined4 *)param_3[6]) {
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = local_54;
      *puVar10 = local_60;
      puVar10[1] = local_5c;
      puVar10[2] = local_58;
      local_58 = 0;
      local_60 = 0;
      local_5c = 0;
      param_3[5] = param_3[5] + 0x10;
    }
    else {
      iVar3 = param_3[6] - param_3[4];
      iVar8 = (int)puVar10 - param_3[4] >> 4;
      if ((uint)(iVar3 >> 4) < 0x7ffffff) {
        uVar5 = iVar8 + 1;
        uVar13 = iVar3 >> 3;
        if (uVar13 < uVar5) {
          uVar13 = uVar5;
        }
      }
      else {
        uVar13 = 0xfffffff;
      }
      FUN_001d53d2(&local_40,uVar13,iVar8,param_3 + 7);
      *local_38 = 0;
      local_38[1] = 0;
      local_38[2] = 0;
      local_38[3] = local_54;
      *local_38 = local_60;
      local_38[1] = local_5c;
      local_38[2] = local_58;
      local_58 = 0;
      local_60 = 0;
      local_5c = 0;
      local_38 = local_38 + 4;
      FUN_001d541e(param_3 + 4,&local_40);
      FUN_001d548a(&local_40);
    }
    FUN_001c5dac(&local_60);
    pbVar7 = (byte *)FUN_001cb15c(pbVar15,param_2,param_3);
    if ((pbVar7 == pbVar15) ||
       (iVar3 = param_3[1], (uint)((iVar3 - *param_3 >> 3) * -0x55555555) < 2)) goto LAB_001cadaa;
    uVar13 = *(uint *)(iVar3 + -8);
    iVar8 = *(int *)(iVar3 + -4);
    if ((*(byte *)(iVar3 + -0xc) & 1) == 0) {
      iVar8 = iVar3 + -0xb;
      uVar13 = (uint)(*(byte *)(iVar3 + -0xc) >> 1);
    }
    puVar9 = (uint *)FUN_001cb080(iVar3 + -0x18,iVar8,uVar13);
    local_40 = *puVar9;
    local_3c = puVar9[1];
    local_38 = (undefined4 *)puVar9[2];
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    iVar17 = param_3[1];
    iVar8 = iVar17 + -0x18;
    iVar3 = iVar17;
    do {
      param_3[1] = iVar3 + -0x18;
      if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
        free(*(void **)(iVar3 + -4));
      }
      if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
        free(*(void **)(iVar3 + -0x10));
      }
      iVar3 = param_3[1];
    } while (iVar3 != iVar8);
  }
  uVar13 = local_40;
  if (*param_3 != iVar8) {
    uVar5 = local_3c;
    puVar10 = local_38;
    if ((local_40 & 1) == 0) {
      puVar10 = (undefined4 *)((uint)&local_40 | 1);
      uVar5 = local_40 >> 1 & 0x7f;
    }
    FUN_001cb080(iVar17 + -0x30,puVar10,uVar5);
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = 1;
    }
  }
  if ((uVar13 & 1) != 0) {
    free(local_38);
  }
LAB_001cadaa:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
code_r0x001ca570:
  iVar8 = param_3[1];
  uVar5 = *(uint *)(iVar8 + -8);
  iVar3 = *(int *)(iVar8 + -4);
  if ((*(byte *)(iVar8 + -0xc) & 1) == 0) {
    iVar3 = iVar8 + -0xb;
    uVar5 = (uint)(*(byte *)(iVar8 + -0xc) >> 1);
  }
  puVar9 = (uint *)FUN_001cb080(iVar8 + -0x18,iVar3,uVar5);
  local_50 = *puVar9;
  local_4c = puVar9[1];
  local_48 = (void *)puVar9[2];
  *puVar9 = 0;
  puVar9[1] = 0;
  puVar9[2] = 0;
  iVar8 = param_3[1];
  iVar3 = iVar8;
  do {
    param_3[1] = iVar3 + -0x18;
    if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
      free(*(void **)(iVar3 + -4));
    }
    if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
      free(*(void **)(iVar3 + -0x10));
    }
    uVar5 = local_50;
    iVar3 = param_3[1];
  } while (iVar3 != iVar8 + -0x18);
  if (*param_3 == iVar8 + -0x18) {
    uVar16 = 0;
    bVar19 = true;
  }
  else {
    uVar11 = local_4c;
    pvVar14 = local_48;
    if ((local_50 & 1) == 0) {
      pvVar14 = (void *)((uint)&local_50 | 1);
      uVar11 = local_50 >> 1 & 0x7f;
    }
    FUN_001cb080(iVar8 + -0x30,pvVar14,uVar11);
    local_64 = param_3[3];
    FUN_001cb104(&local_60,param_3[1] + -0x18,&local_64);
    puVar10 = (undefined4 *)param_3[5];
    if (puVar10 < (undefined4 *)param_3[6]) {
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10[3] = local_54;
      *puVar10 = local_60;
      puVar10[1] = local_5c;
      puVar10[2] = local_58;
      local_58 = 0;
      local_60 = 0;
      local_5c = 0;
      param_3[5] = param_3[5] + 0x10;
    }
    else {
      iVar3 = param_3[6] - *piVar6;
      iVar8 = (int)puVar10 - *piVar6 >> 4;
      if ((uint)(iVar3 >> 4) < 0x7ffffff) {
        uVar12 = iVar8 + 1;
        uVar11 = iVar3 >> 3;
        if (uVar11 < uVar12) {
          uVar11 = uVar12;
        }
      }
      else {
        uVar11 = 0xfffffff;
      }
      FUN_001d53d2(&local_40,uVar11,iVar8,param_3 + 7);
      *local_38 = 0;
      local_38[1] = 0;
      local_38[2] = 0;
      local_38[3] = local_54;
      *local_38 = local_60;
      local_38[1] = local_5c;
      local_38[2] = local_58;
      local_58 = 0;
      local_60 = 0;
      local_5c = 0;
      local_38 = local_38 + 4;
      FUN_001d541e(piVar6,&local_40);
      FUN_001d548a(&local_40);
    }
    FUN_001c5dac(&local_60);
    uVar16 = 1;
    bVar19 = false;
    local_80 = pbVar7;
  }
  if ((uVar5 & 1) != 0) {
    free(local_48);
  }
  if (bVar19) goto LAB_001cadaa;
  goto LAB_001ca388;
}

// ===== FUN_001cae94  @0x001cae94  (86 bytes)
char * FUN_001cae94(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  if (param_1 != param_2) {
    if (*param_1 == 'v') {
      pcVar1 = (char *)FUN_001caeea(param_1 + 1,param_2);
      if (pcVar1 == param_1 + 1 || pcVar1 == param_2) {
        return param_1;
      }
      if (*pcVar1 != '_') {
        return param_1;
      }
    }
    else {
      pcVar1 = param_1;
      if (*param_1 != 'h') {
        return param_1;
      }
    }
    pcVar2 = (char *)FUN_001caeea(pcVar1 + 1,param_2);
    if ((pcVar2 != pcVar1 + 1 && pcVar2 != param_2) && (*pcVar2 == '_')) {
      param_1 = pcVar2 + 1;
    }
  }
  return param_1;
}

// ===== FUN_001caeea  @0x001caeea  (64 bytes)
byte * FUN_001caeea(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_1 != param_2) {
    pbVar1 = param_1 + 1;
    if (*param_1 != 0x6e) {
      pbVar1 = param_1;
    }
    if (pbVar1 != param_2) {
      if (*pbVar1 == 0x30) {
        return pbVar1 + 1;
      }
      if (8 < (byte)(*pbVar1 - 0x31)) {
        return param_1;
      }
      do {
        param_1 = pbVar1 + 1;
        if (param_2 == param_1) {
          return param_2;
        }
        pbVar1 = param_1;
      } while (*param_1 - 0x30 < 10);
    }
  }
  return param_1;
}

// ===== FUN_001caf2a  @0x001caf2a  (164 bytes)
uint * FUN_001caf2a(uint *param_1,uint param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  bVar1 = (byte)*param_1;
  uVar2 = (uint)bVar1;
  if ((bVar1 & 1) == 0) {
    uVar5 = (uint)(bVar1 >> 1);
    iVar4 = 10;
  }
  else {
    uVar2 = *param_1;
    uVar5 = param_1[1];
    iVar4 = (uVar2 & 0xfffffffe) - 1;
  }
  if (iVar4 - uVar5 < param_4) {
    FUN_001cafce(param_1,iVar4,(uVar5 + param_4) - iVar4,uVar5,param_2,0,param_4,param_3);
  }
  else if (param_4 != 0) {
    if ((uVar2 & 1) == 0) {
      pbVar7 = (byte *)((int)param_1 + 1);
    }
    else {
      pbVar7 = (byte *)param_1[2];
    }
    pbVar6 = pbVar7 + param_2;
    pbVar3 = param_3;
    if (uVar5 != param_2) {
      __aeabi_memmove(pbVar6 + param_4,pbVar6);
      if (param_3 < pbVar7 + uVar5) {
        pbVar3 = param_3 + param_4;
      }
      if (param_3 < pbVar6) {
        pbVar3 = param_3;
      }
    }
    __aeabi_memmove(pbVar6,pbVar3,param_4);
    uVar5 = uVar5 + param_4;
    if ((*param_1 & 1) == 0) {
      *(char *)param_1 = (char)uVar5 * '\x02';
    }
    else {
      param_1[1] = uVar5;
    }
    pbVar7[uVar5] = 0;
  }
  return param_1;
}

// ===== FUN_001cafce  @0x001cafce  (178 bytes)
void FUN_001cafce(uint *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8)

{
  byte *__ptr;
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  
  if ((*param_1 & 1) == 0) {
    __ptr = (byte *)((int)param_1 + 1);
  }
  else {
    __ptr = (byte *)param_1[2];
  }
  if (param_2 < 0x7fffffe7) {
    uVar1 = param_3 + param_2;
    if (uVar1 < param_2 << 1) {
      uVar1 = param_2 << 1;
    }
    if (uVar1 < 0xb) {
      uVar1 = 0xb;
    }
    else {
      uVar1 = uVar1 + 0x10 & 0xfffffff0;
    }
  }
  else {
    uVar1 = 0xffffffef;
  }
  pvVar2 = malloc(uVar1);
  if (param_5 != 0) {
    __aeabi_memcpy(pvVar2,__ptr,param_5);
  }
  if (param_7 != 0) {
    __aeabi_memcpy((int)pvVar2 + param_5,param_8,param_7);
  }
  if (param_4 - param_6 != param_5) {
    __aeabi_memcpy((int)pvVar2 + param_7 + param_5,__ptr + param_6 + param_5);
  }
  if (param_2 != 10) {
    free(__ptr);
  }
  uVar3 = (param_4 - param_6) + param_7;
  *param_1 = uVar1 | 1;
  param_1[1] = uVar3;
  param_1[2] = (uint)pvVar2;
  *(undefined1 *)((int)pvVar2 + uVar3) = 0;
  return;
}

// ===== FUN_001cb080  @0x001cb080  (132 bytes)
uint * FUN_001cb080(uint *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar1 = (uint)(byte)*param_1;
  if (((byte)*param_1 & 1) == 0) {
    iVar2 = 10;
  }
  else {
    uVar1 = *param_1;
    iVar2 = (uVar1 & 0xfffffffe) - 1;
  }
  if ((uVar1 & 1) == 0) {
    uVar3 = (uVar1 & 0xff) >> 1;
  }
  else {
    uVar3 = param_1[1];
  }
  if (iVar2 - uVar3 < param_3) {
    FUN_001cafce(param_1,iVar2,(param_3 - iVar2) + uVar3,uVar3,uVar3,0,param_3,param_2);
  }
  else if (param_3 != 0) {
    if ((uVar1 & 1) == 0) {
      pbVar4 = (byte *)((int)param_1 + 1);
    }
    else {
      pbVar4 = (byte *)param_1[2];
    }
    __aeabi_memcpy(pbVar4 + uVar3,param_2,param_3);
    uVar3 = uVar3 + param_3;
    if ((*param_1 & 1) == 0) {
      *(char *)param_1 = (char)uVar3 * '\x02';
    }
    else {
      param_1[1] = uVar3;
    }
    pbVar4[uVar3] = 0;
  }
  return param_1;
}

// ===== FUN_001cb104  @0x001cb104  (86 bytes)
undefined4 * FUN_001cb104(undefined4 *param_1,int param_2,int *param_3)

{
  void *pvVar1;
  int iVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  iVar2 = *param_3;
  param_1[2] = 0;
  param_1[3] = iVar2;
  pvVar1 = *(void **)(iVar2 + 0x1000);
  if ((uint)((iVar2 + 0x1000) - (int)pvVar1) < 0x20) {
    pvVar1 = malloc(0x20);
  }
  else {
    *(int *)(iVar2 + 0x1000) = (int)pvVar1 + 0x20;
  }
  *param_1 = pvVar1;
  param_1[1] = pvVar1;
  param_1[2] = (int)pvVar1 + 0x18;
  iVar2 = FUN_001c5e34(pvVar1,param_2);
  FUN_001c5e34(iVar2 + 0xc,param_2 + 0xc);
  param_1[1] = param_1[1] + 0x18;
  return param_1;
}

// ===== FUN_001cb15c  @0x001cb15c  (1326 bytes)
void FUN_001cb15c(char *param_1,char *param_2,int *param_3)

{
  char *pcVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined *puVar9;
  uint uVar10;
  void *pvVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined1 *puVar17;
  undefined4 *__ptr;
  char *pcVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  bool bVar22;
  uint uVar23;
  uint local_68;
  uint local_64;
  void *local_60;
  uint local_58;
  uint local_54;
  undefined4 *local_50;
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((1 < (int)param_2 - (int)param_1) && (*param_1 == 'I')) {
    if (*(char *)((int)param_3 + 0x3d) != '\0') {
      iVar13 = param_3[9];
      iVar15 = *(int *)(iVar13 + -0x10);
      while (*(int *)(iVar13 + -0xc) != iVar15) {
        *(int *)(iVar13 + -0xc) = *(int *)(iVar13 + -0xc) + -0x10;
        FUN_001c5dac();
      }
    }
    local_60 = (void *)0x0;
    local_68 = 0;
    local_64 = 0;
    FUN_001c5e62(&local_68,&DAT_0021f77b,1);
    uVar23 = 0xaaaaaaa;
    if (param_1[1] != 'E') {
      pcVar18 = param_1 + 1;
      do {
        if (*(char *)((int)param_3 + 0x3d) != '\0') {
          iVar13 = param_3[3];
          puVar3 = (undefined4 *)param_3[9];
          if (puVar3 < (undefined4 *)param_3[10]) {
            *puVar3 = 0;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = iVar13;
            param_3[9] = param_3[9] + 0x10;
          }
          else {
            iVar20 = param_3[8];
            iVar15 = param_3[10] - iVar20;
            iVar20 = (int)puVar3 - iVar20 >> 4;
            if ((uint)(iVar15 >> 4) < 0x7ffffff) {
              uVar19 = iVar20 + 1;
              uVar6 = iVar15 >> 3;
              if (uVar6 < uVar19) {
                uVar6 = uVar19;
              }
            }
            else {
              uVar6 = 0xfffffff;
            }
            FUN_001c5eaa(&local_58,uVar6,iVar20,param_3 + 0xb,uVar23,param_1);
            *local_50 = 0;
            local_50[1] = 0;
            local_50[2] = 0;
            local_50[3] = iVar13;
            local_50 = local_50 + 4;
            FUN_001c5ef6(param_3 + 8,&local_58);
            FUN_001c5f62(&local_58);
          }
        }
        iVar13 = *param_3;
        iVar15 = param_3[1];
        pcVar4 = (char *)FUN_001d54b6(pcVar18,param_2,param_3);
        iVar20 = *param_3;
        iVar21 = param_3[1];
        if (*(char *)((int)param_3 + 0x3d) != '\0') {
          iVar5 = param_3[9];
          iVar14 = iVar5 + -0x10;
          do {
            param_3[9] = iVar5 + -0x10;
            FUN_001c5d7c();
            iVar5 = param_3[9];
          } while (iVar5 != iVar14);
        }
        pcVar1 = pcVar4;
        if (pcVar4 != pcVar18) {
          pcVar1 = param_2;
        }
        if (pcVar4 == pcVar18 || pcVar4 == pcVar1) goto LAB_001cb65c;
        iVar13 = iVar15 - iVar13 >> 3;
        uVar19 = (iVar21 - iVar20 >> 3) * -0x55555555;
        uVar6 = iVar13 * -0x55555555;
        if (*(char *)((int)param_3 + 0x3d) != '\0') {
          iVar15 = param_3[9];
          iVar20 = param_3[3];
          puVar3 = *(undefined4 **)(iVar15 + -0xc);
          if (puVar3 < *(undefined4 **)(iVar15 + -8)) {
            *puVar3 = 0;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = iVar20;
            *(int *)(iVar15 + -0xc) = *(int *)(iVar15 + -0xc) + 0x10;
          }
          else {
            iVar5 = (int)*(undefined4 **)(iVar15 + -8) - *(int *)(iVar15 + -0x10);
            iVar21 = (int)puVar3 - *(int *)(iVar15 + -0x10) >> 4;
            if ((uint)(iVar5 >> 4) < 0x7ffffff) {
              uVar7 = iVar21 + 1;
              uVar16 = iVar5 >> 3;
              if (uVar16 < uVar7) {
                uVar16 = uVar7;
              }
            }
            else {
              uVar16 = 0xfffffff;
            }
            FUN_001d53d2(&local_58,uVar16,iVar21,iVar15 + -4);
            *local_50 = 0;
            local_50[1] = 0;
            local_50[2] = 0;
            local_50[3] = iVar20;
            local_50 = local_50 + 4;
            FUN_001d541e(iVar15 + -0x10,&local_58);
            FUN_001d548a(&local_58);
          }
          if (uVar6 < uVar19) {
            iVar15 = uVar19 + iVar13 * 0x55555555;
            iVar20 = iVar13 * 8;
            do {
              iVar5 = *param_3;
              iVar14 = *(int *)(param_3[9] + -0xc);
              iVar21 = *(int *)(iVar14 + -0xc);
              if (iVar21 == *(int *)(iVar14 + -8)) {
                iVar21 = iVar21 - *(int *)(iVar14 + -0x10) >> 3;
                uVar7 = iVar21 * -0x55555555;
                uVar16 = 0xaaaaaaa;
                if (uVar7 < 0x5555555) {
                  uVar16 = iVar21 * 0x55555556;
                  if (uVar16 < uVar7 + 1) {
                    uVar16 = uVar7 + 1;
                  }
                }
                FUN_001ccdd4(&local_58,uVar16,uVar7,iVar14 + -4);
                iVar5 = iVar5 + iVar20;
                iVar21 = FUN_001c5e34(local_50,iVar5);
                FUN_001c5e34(iVar21 + 0xc,iVar5 + 0xc);
                local_50 = local_50 + 6;
                FUN_001cce32(iVar14 + -0x10,&local_58);
                FUN_001cceae(&local_58);
              }
              else {
                iVar5 = iVar5 + iVar20;
                iVar21 = FUN_001c5e34(iVar21,iVar5);
                FUN_001c5e34(iVar21 + 0xc,iVar5 + 0xc);
                *(int *)(iVar14 + -0xc) = *(int *)(iVar14 + -0xc) + 0x18;
              }
              iVar20 = iVar20 + 0x18;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
          }
        }
        if (uVar6 < uVar19) {
          iVar13 = iVar13 * 8;
          uVar16 = uVar19;
          do {
            uVar7 = local_64;
            if ((local_68 & 1) == 0) {
              uVar7 = local_68 >> 1 & 0x7f;
            }
            if (1 < uVar7) {
              FUN_001cb080(&local_68,&DAT_00222122,2);
            }
            iVar20 = *param_3 + iVar13;
            uVar7 = *(uint *)(iVar20 + 0x10);
            iVar15 = *(int *)(iVar20 + 0x14);
            if ((*(byte *)(iVar20 + 0xc) & 1) == 0) {
              iVar15 = iVar20 + 0xd;
              uVar7 = (uint)(*(byte *)(iVar20 + 0xc) >> 1);
            }
            puVar8 = (uint *)FUN_001cb080(iVar20,iVar15,uVar7);
            local_58 = *puVar8;
            local_54 = puVar8[1];
            __ptr = (undefined4 *)puVar8[2];
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            uVar7 = local_58 & 1;
            uVar10 = local_54;
            puVar3 = __ptr;
            if ((local_58 & 1) == 0) {
              puVar3 = (undefined4 *)((uint)&local_58 | 1);
              uVar10 = local_58 >> 1 & 0x7f;
            }
            local_50 = __ptr;
            FUN_001cb080(&local_68,puVar3,uVar10);
            if (uVar7 != 0) {
              free(__ptr);
            }
            iVar13 = iVar13 + 0x18;
            uVar16 = uVar16 - 1;
          } while (uVar6 != uVar16);
          if (uVar6 < uVar19) {
            iVar13 = param_3[1];
            do {
              iVar15 = iVar13;
              if (*param_3 != iVar13) {
                iVar15 = iVar13 + -0x18;
                do {
                  param_3[1] = iVar13 + -0x18;
                  if ((*(byte *)(iVar13 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar13 + -4));
                  }
                  if ((*(byte *)(iVar13 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar13 + -0x10));
                  }
                  iVar13 = param_3[1];
                } while (iVar13 != iVar15);
              }
              uVar19 = uVar19 - 1;
              iVar13 = iVar15;
            } while (uVar6 < uVar19);
          }
        }
        pcVar18 = pcVar4;
      } while (*pcVar4 != 'E');
    }
    bVar22 = (local_68 & 1) == 0;
    uVar6 = local_64;
    if (bVar22) {
      uVar6 = local_68 >> 1 & 0x7f;
    }
    pvVar11 = local_60;
    if (bVar22) {
      pvVar11 = (void *)((uint)&local_68 | 1);
    }
    if (*(char *)((int)pvVar11 + (uVar6 - 1)) == '>') {
      uVar12 = 2;
      puVar9 = &DAT_002224ac;
    }
    else {
      uVar12 = 1;
      puVar9 = &DAT_0021f77f;
    }
    FUN_001cb080(&local_68,puVar9,uVar12);
    uVar2 = (undefined1)local_68;
    __aeabi_memcpy(&local_40,(void *)((uint)&local_68 | 1),7);
    pvVar11 = local_60;
    local_60 = (void *)0x0;
    local_68 = 0;
    local_64 = 0;
    __aeabi_memcpy(&local_30,&local_40,7);
    local_3a = 0;
    local_3c = 0;
    local_32 = 0;
    local_34 = 0;
    local_40 = 0;
    local_38 = 0;
    puVar17 = (undefined1 *)param_3[1];
    if (puVar17 < (undefined1 *)param_3[2]) {
      *puVar17 = uVar2;
      __aeabi_memcpy(puVar17 + 1,&local_30,7);
      *(void **)(puVar17 + 8) = pvVar11;
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      puVar17[0xc] = 0;
      __aeabi_memcpy(puVar17 + 0xd,&local_38,7);
      *(undefined4 *)(puVar17 + 0x14) = 0;
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      param_3[1] = param_3[1] + 0x18;
    }
    else {
      iVar13 = param_3[2] - *param_3 >> 3;
      iVar15 = ((int)puVar17 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar13 * -0x55555555) < 0x5555555) {
        uVar6 = iVar15 + 1;
        uVar23 = iVar13 * 0x55555556;
        if (uVar23 < uVar6) {
          uVar23 = uVar6;
        }
      }
      FUN_001ccdd4(&local_58,uVar23,iVar15,param_3 + 3);
      puVar3 = local_50;
      *(undefined1 *)local_50 = uVar2;
      __aeabi_memcpy((int)local_50 + 1,&local_30,7);
      puVar3[2] = pvVar11;
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      *(undefined1 *)(puVar3 + 3) = 0;
      __aeabi_memcpy((int)puVar3 + 0xd,&local_38,7);
      puVar3[5] = 0;
      local_32 = 0;
      local_50 = local_50 + 6;
      local_34 = 0;
      local_38 = 0;
      FUN_001cce32(param_3,&local_58);
      FUN_001cceae(&local_58);
    }
LAB_001cb65c:
    if ((local_68 & 1) != 0) {
      free(local_60);
    }
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001cb6bc  @0x001cb6bc  (1284 bytes)
void FUN_001cb6bc(char *param_1,byte *param_2,int *param_3)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined1 auStack_44 [8];
  undefined4 *local_3c;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (((int)param_2 - (int)param_1 < 2) || (*param_1 != 'S')) goto LAB_001cbb08;
  uVar8 = (uint)(byte)param_1[1];
  uVar11 = 0xaaaaaaa;
  switch(uVar8) {
  case 0x5f:
    piVar1 = (int *)param_3[4];
    if (piVar1 != (int *)param_3[5]) {
      iVar3 = *piVar1;
      iVar9 = piVar1[1];
      if (iVar3 != iVar9) {
        do {
          iVar5 = param_3[1];
          if (iVar5 == param_3[2]) {
            iVar5 = iVar5 - *param_3 >> 3;
            uVar4 = iVar5 * -0x55555555;
            uVar8 = uVar11;
            if (uVar4 < 0x5555555) {
              uVar8 = iVar5 * 0x55555556;
              if (uVar8 < uVar4 + 1) {
                uVar8 = uVar4 + 1;
              }
            }
            FUN_001ccdd4(auStack_44,uVar8,uVar4,param_3 + 3);
            iVar5 = FUN_001c5e34(local_3c,iVar3);
            FUN_001c5e34(iVar5 + 0xc,iVar3 + 0xc);
            local_3c = local_3c + 6;
            FUN_001cce32(param_3,auStack_44);
            FUN_001cceae(auStack_44);
          }
          else {
            iVar5 = FUN_001c5e34(iVar5,iVar3);
            FUN_001c5e34(iVar5 + 0xc,iVar3 + 0xc);
            param_3[1] = param_3[1] + 0x18;
          }
          iVar3 = iVar3 + 0x18;
        } while (iVar9 != iVar3);
      }
    }
    goto LAB_001cbb08;
  case 0x60:
  case 99:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
    goto switchD_001cb6fc_caseD_60;
  case 0x61:
    pvVar2 = malloc(0x10);
    uVar14 = 0xe;
    __aeabi_memcpy(pvVar2,"std::allocator",0xe);
    local_2a = 0;
    local_2c = 0;
    *(undefined1 *)((int)pvVar2 + 0xe) = 0;
    local_30 = 0;
    puVar12 = (undefined4 *)param_3[1];
    if (puVar12 < (undefined4 *)param_3[2]) {
LAB_001cba12:
      uVar6 = 0x11;
LAB_001cba14:
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      *puVar12 = uVar6;
      puVar12[1] = uVar14;
      puVar12[2] = pvVar2;
      *(undefined1 *)(puVar12 + 3) = 0;
      __aeabi_memcpy((int)puVar12 + 0xd,&local_30,7);
      puVar12[5] = 0;
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      param_3[1] = param_3[1] + 0x18;
      goto LAB_001cbb08;
    }
    iVar3 = param_3[2] - *param_3 >> 3;
    iVar9 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar3 * -0x55555555) < 0x5555555) {
      uVar8 = iVar9 + 1;
      uVar11 = iVar3 * 0x55555556;
      if (uVar11 < uVar8) {
        uVar11 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_44,uVar11,iVar9,param_3 + 3);
    uVar14 = 0x11;
    uVar6 = 0xe;
    break;
  case 0x62:
    pvVar2 = malloc(0x20);
    uVar14 = 0x11;
    __aeabi_memcpy(pvVar2,"std::basic_string",0x11);
    local_2a = 0;
    local_2c = 0;
    *(undefined1 *)((int)pvVar2 + 0x11) = 0;
    local_30 = 0;
    puVar12 = (undefined4 *)param_3[1];
    if (puVar12 < (undefined4 *)param_3[2]) {
      uVar6 = 0x21;
      goto LAB_001cba14;
    }
    iVar3 = param_3[2] - *param_3 >> 3;
    iVar9 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar3 * -0x55555555) < 0x5555555) {
      uVar8 = iVar9 + 1;
      uVar11 = iVar3 * 0x55555556;
      if (uVar11 < uVar8) {
        uVar11 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_44,uVar11,iVar9,param_3 + 3);
    uVar14 = 0x21;
    uVar6 = 0x11;
    break;
  case 100:
    pvVar2 = malloc(0x10);
    uVar14 = 0xd;
    __aeabi_memcpy(pvVar2,"std::iostream",0xd);
    local_2a = 0;
    local_2c = 0;
    *(undefined1 *)((int)pvVar2 + 0xd) = 0;
    local_30 = 0;
    puVar12 = (undefined4 *)param_3[1];
    if (puVar12 < (undefined4 *)param_3[2]) goto LAB_001cba12;
    iVar3 = param_3[2] - *param_3 >> 3;
    iVar9 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar3 * -0x55555555) < 0x5555555) {
      uVar8 = iVar9 + 1;
      uVar11 = iVar3 * 0x55555556;
      if (uVar11 < uVar8) {
        uVar11 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_44,uVar11,iVar9,param_3 + 3);
    uVar14 = 0x11;
    uVar6 = 0xd;
    break;
  case 0x69:
    pvVar2 = malloc(0x10);
    pcVar7 = "std::istream";
LAB_001cb9e6:
    uVar14 = 0xc;
    __aeabi_memcpy(pvVar2,pcVar7,0xc);
    local_2a = 0;
    local_2c = 0;
    *(undefined1 *)((int)pvVar2 + 0xc) = 0;
    local_30 = 0;
    puVar12 = (undefined4 *)param_3[1];
    if (puVar12 < (undefined4 *)param_3[2]) goto LAB_001cba12;
    iVar3 = param_3[2] - *param_3 >> 3;
    iVar9 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar3 * -0x55555555) < 0x5555555) {
      uVar8 = iVar9 + 1;
      uVar11 = iVar3 * 0x55555556;
      if (uVar11 < uVar8) {
        uVar11 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_44,uVar11,iVar9,param_3 + 3);
    uVar14 = 0x11;
    uVar6 = 0xc;
    break;
  default:
    if (uVar8 == 0x6f) {
      pvVar2 = malloc(0x10);
      pcVar7 = "std::ostream";
      goto LAB_001cb9e6;
    }
    if (uVar8 == 0x73) {
      pvVar2 = malloc(0x10);
      uVar14 = 0xb;
      __aeabi_memcpy(pvVar2,"std::string",0xb);
      local_2a = 0;
      local_2c = 0;
      *(undefined1 *)((int)pvVar2 + 0xb) = 0;
      local_30 = 0;
      puVar12 = (undefined4 *)param_3[1];
      if (puVar12 < (undefined4 *)param_3[2]) goto LAB_001cba12;
      iVar3 = param_3[2] - *param_3 >> 3;
      iVar9 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar3 * -0x55555555) < 0x5555555) {
        uVar8 = iVar9 + 1;
        uVar11 = iVar3 * 0x55555556;
        if (uVar11 < uVar8) {
          uVar11 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_44,uVar11,iVar9,param_3 + 3);
      uVar14 = 0x11;
      uVar6 = 0xb;
      break;
    }
    goto switchD_001cb6fc_caseD_60;
  }
  puVar12 = local_3c;
  *local_3c = uVar14;
  local_3c[1] = uVar6;
  local_3c[2] = pvVar2;
  *(undefined1 *)(local_3c + 3) = 0;
  __aeabi_memcpy((int)local_3c + 0xd,&local_30,7);
  puVar12[5] = 0;
  local_2a = 0;
  local_3c = local_3c + 6;
  local_2c = 0;
  local_30 = 0;
  FUN_001cce32(param_3,auStack_44);
  FUN_001cceae(auStack_44);
LAB_001cbb08:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
switchD_001cb6fc_caseD_60:
  uVar4 = uVar8 - 0x30;
  if (((uVar4 < 10) || ((*(byte *)(_ctype_ + uVar8 + 1) & 1) != 0)) &&
     (pbVar13 = (byte *)(param_1 + 2), pbVar13 != param_2)) {
    if (9 < uVar4) {
      uVar4 = uVar8 - 0x37;
    }
    do {
      uVar10 = (uint)*pbVar13;
      uVar8 = uVar10 - 0x30;
      if ((9 < uVar8) && ((*(byte *)(_ctype_ + 1 + uVar10) & 1) == 0)) {
        if (uVar10 == 0x5f) {
          iVar3 = param_3[4];
          uVar4 = uVar4 + 1;
          if (uVar4 < (uint)(param_3[5] - iVar3 >> 4)) {
            iVar9 = *(int *)(iVar3 + uVar4 * 0x10);
            iVar3 = *(int *)(iVar3 + uVar4 * 0x10 + 4);
            if (iVar9 != iVar3) {
              do {
                iVar5 = param_3[1];
                if (iVar5 == param_3[2]) {
                  iVar5 = iVar5 - *param_3 >> 3;
                  uVar4 = iVar5 * -0x55555555;
                  uVar8 = uVar11;
                  if (uVar4 < 0x5555555) {
                    uVar8 = iVar5 * 0x55555556;
                    if (uVar8 < uVar4 + 1) {
                      uVar8 = uVar4 + 1;
                    }
                  }
                  FUN_001ccdd4(auStack_44,uVar8,uVar4,param_3 + 3);
                  iVar5 = FUN_001c5e34(local_3c,iVar9);
                  FUN_001c5e34(iVar5 + 0xc,iVar9 + 0xc);
                  local_3c = local_3c + 6;
                  FUN_001cce32(param_3,auStack_44);
                  FUN_001cceae(auStack_44);
                }
                else {
                  iVar5 = FUN_001c5e34(iVar5,iVar9);
                  FUN_001c5e34(iVar5 + 0xc,iVar9 + 0xc);
                  param_3[1] = param_3[1] + 0x18;
                }
                iVar9 = iVar9 + 0x18;
              } while (iVar3 != iVar9);
            }
          }
        }
        break;
      }
      if (9 < uVar8) {
        uVar8 = uVar10 - 0x37;
      }
      pbVar13 = pbVar13 + 1;
      uVar4 = uVar8 + uVar4 * 0x24;
    } while (param_2 != pbVar13);
  }
  goto LAB_001cbb08;
}

// ===== FUN_001cbc00  @0x001cbc00  (74 bytes)
void FUN_001cbc00(undefined4 *param_1,char *param_2,byte *param_3)

{
  size_t sVar1;
  byte *pbVar2;
  uint uVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  sVar1 = strlen(param_2);
  uVar3 = *(uint *)(param_3 + 4);
  if ((*param_3 & 1) == 0) {
    uVar3 = (uint)(*param_3 >> 1);
  }
  FUN_001ccf70(param_1,param_2,sVar1,uVar3 + sVar1);
  pbVar2 = *(byte **)(param_3 + 8);
  if ((*param_3 & 1) == 0) {
    pbVar2 = param_3 + 1;
  }
  FUN_001cb080(param_1,pbVar2,uVar3);
  return;
}

// ===== FUN_001cbc4a  @0x001cbc4a  (40 bytes)
void FUN_001cbc4a(byte *param_1,byte *param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  if (param_1 != param_2) {
    uVar1 = *(uint *)(param_2 + 4);
    pbVar2 = *(byte **)(param_2 + 8);
    if ((*param_2 & 1) == 0) {
      pbVar2 = param_2 + 1;
      uVar1 = (uint)(*param_2 >> 1);
    }
    FUN_001ccf02(param_1,pbVar2,uVar1);
    return;
  }
  return;
}

// ===== FUN_001cbc74  @0x001cbc74  (1084 bytes)
void FUN_001cbc74(char *param_1,char *param_2,int *param_3)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined1 *puVar9;
  int iVar10;
  uint local_5c;
  uint local_58;
  uint uStack_54;
  char *local_50;
  undefined1 auStack_4c [8];
  undefined1 *local_44;
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((1 < (int)param_2 - (int)param_1) && (*param_1 == 'T')) {
    local_5c = 0xaaaaaaa;
    if ((byte)param_1[1] == 0x5f) {
      iVar5 = param_3[9];
      if (param_3[8] != iVar5) {
        piVar2 = *(int **)(iVar5 + -0x10);
        if (piVar2 == *(int **)(iVar5 + -0xc)) {
          local_2a = 0;
          local_2c = 0;
          local_30 = 0;
          puVar9 = (undefined1 *)param_3[1];
          if (puVar9 < (undefined1 *)param_3[2]) {
            *puVar9 = 4;
            *(undefined2 *)(puVar9 + 1) = 0x5f54;
            puVar9[3] = 0;
            *(undefined4 *)(puVar9 + 4) = 0;
            *(undefined4 *)(puVar9 + 8) = 0;
            puVar9[0xc] = 0;
            __aeabi_memcpy(puVar9 + 0xd,&local_30,7);
            *(undefined4 *)(puVar9 + 0x14) = 0;
            local_2a = 0;
            local_2c = 0;
            local_30 = 0;
            param_3[1] = param_3[1] + 0x18;
          }
          else {
            iVar5 = param_3[2] - *param_3 >> 3;
            iVar10 = ((int)puVar9 - *param_3 >> 3) * -0x55555555;
            if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
              uVar6 = iVar10 + 1;
              local_5c = iVar5 * 0x55555556;
              if (local_5c < uVar6) {
                local_5c = uVar6;
              }
            }
            FUN_001ccdd4(auStack_4c,local_5c,iVar10,param_3 + 3);
            puVar9 = local_44;
            *local_44 = 4;
            *(undefined2 *)(local_44 + 1) = 0x5f54;
            local_44[3] = 0;
            *(undefined4 *)(local_44 + 4) = 0;
            *(undefined4 *)(local_44 + 8) = 0;
            local_44[0xc] = 0;
            __aeabi_memcpy(local_44 + 0xd,&local_30,7);
            *(undefined4 *)(puVar9 + 0x14) = 0;
            local_2a = 0;
            local_44 = local_44 + 0x18;
            local_2c = 0;
            local_30 = 0;
            FUN_001cce32(param_3,auStack_4c);
            FUN_001cceae(auStack_4c);
          }
          *(undefined1 *)((int)param_3 + 0x3e) = 1;
        }
        else {
          iVar5 = *piVar2;
          iVar10 = piVar2[1];
          if (iVar5 != iVar10) {
            do {
              iVar3 = param_3[1];
              if (iVar3 == param_3[2]) {
                iVar3 = iVar3 - *param_3 >> 3;
                uVar7 = iVar3 * -0x55555555;
                uVar6 = 0xaaaaaaa;
                if (uVar7 < 0x5555555) {
                  uVar6 = iVar3 * 0x55555556;
                  if (uVar6 < uVar7 + 1) {
                    uVar6 = uVar7 + 1;
                  }
                }
                FUN_001ccdd4(auStack_4c,uVar6,uVar7,param_3 + 3);
                iVar3 = FUN_001c5e34(local_44,iVar5);
                FUN_001c5e34(iVar3 + 0xc,iVar5 + 0xc);
                local_44 = local_44 + 0x18;
                FUN_001cce32(param_3,auStack_4c);
                FUN_001cceae(auStack_4c);
              }
              else {
                iVar3 = FUN_001c5e34(iVar3,iVar5);
                FUN_001c5e34(iVar3 + 0xc,iVar5 + 0xc);
                param_3[1] = param_3[1] + 0x18;
              }
              iVar5 = iVar5 + 0x18;
            } while (iVar10 != iVar5);
          }
        }
      }
    }
    else {
      uVar6 = (byte)param_1[1] - 0x30;
      if ((uVar6 < 10) && (param_1 + 2 != param_2)) {
        iVar5 = 0;
        do {
          uVar7 = (byte)param_1[iVar5 + 2] - 0x30;
          if (9 < uVar7) {
            if (((byte)param_1[iVar5 + 2] == 0x5f) && (iVar10 = param_3[9], param_3[8] != iVar10)) {
              iVar3 = *(int *)(iVar10 + -0x10);
              uVar6 = uVar6 + 1;
              if (uVar6 < (uint)(*(int *)(iVar10 + -0xc) - iVar3 >> 4)) {
                iVar5 = *(int *)(iVar3 + uVar6 * 0x10);
                iVar10 = *(int *)(iVar3 + uVar6 * 0x10 + 4);
                if (iVar5 != iVar10) {
                  do {
                    iVar3 = param_3[1];
                    if (iVar3 == param_3[2]) {
                      iVar3 = iVar3 - *param_3 >> 3;
                      uVar7 = iVar3 * -0x55555555;
                      uVar6 = 0xaaaaaaa;
                      if (uVar7 < 0x5555555) {
                        uVar6 = iVar3 * 0x55555556;
                        if (uVar6 < uVar7 + 1) {
                          uVar6 = uVar7 + 1;
                        }
                      }
                      FUN_001ccdd4(auStack_4c,uVar6,uVar7,param_3 + 3);
                      iVar3 = FUN_001c5e34(local_44,iVar5);
                      FUN_001c5e34(iVar3 + 0xc,iVar5 + 0xc);
                      local_44 = local_44 + 0x18;
                      FUN_001cce32(param_3,auStack_4c);
                      FUN_001cceae(auStack_4c);
                    }
                    else {
                      iVar3 = FUN_001c5e34(iVar3,iVar5);
                      FUN_001c5e34(iVar3 + 0xc,iVar5 + 0xc);
                      param_3[1] = param_3[1] + 0x18;
                    }
                    iVar5 = iVar5 + 0x18;
                  } while (iVar10 != iVar5);
                }
              }
              else {
                uVar6 = iVar5 + 3;
                local_50 = (char *)0x0;
                local_58 = 0;
                uStack_54 = 0;
                if (uVar6 < 0xb) {
                  local_58 = (uint)(byte)((char)uVar6 * '\x02');
                  pcVar4 = (char *)((uint)&local_58 | 1);
                }
                else {
                  uVar7 = iVar5 + 0x13U & 0xfffffff0;
                  pcVar4 = malloc(uVar7);
                  local_58 = uVar7 | 1;
                  uStack_54 = uVar6;
                  local_50 = pcVar4;
                }
                if (iVar5 != -3) {
                  *pcVar4 = 'T';
                  if (iVar5 != -2) {
                    iVar5 = iVar5 + 2;
                    pcVar8 = pcVar4;
                    do {
                      param_1 = param_1 + 1;
                      pcVar8 = pcVar8 + 1;
                      iVar5 = iVar5 + -1;
                      *pcVar8 = *param_1;
                    } while (iVar5 != 0);
                  }
                  pcVar4 = pcVar4 + uVar6;
                }
                *pcVar4 = '\0';
                uVar1 = (undefined1)local_58;
                __aeabi_memcpy(&local_30,(uint)&local_58 | 1,7);
                pcVar4 = local_50;
                local_50 = (char *)0x0;
                local_58 = 0;
                uStack_54 = 0;
                local_32 = 0;
                local_34 = 0;
                local_38 = 0;
                puVar9 = (undefined1 *)param_3[1];
                if (puVar9 < (undefined1 *)param_3[2]) {
                  *puVar9 = uVar1;
                  __aeabi_memcpy(puVar9 + 1,&local_30,7);
                  *(char **)(puVar9 + 8) = pcVar4;
                  local_2a = 0;
                  local_2c = 0;
                  local_30 = 0;
                  puVar9[0xc] = 0;
                  __aeabi_memcpy(puVar9 + 0xd,&local_38,7);
                  *(undefined4 *)(puVar9 + 0x14) = 0;
                  local_32 = 0;
                  local_34 = 0;
                  local_38 = 0;
                  param_3[1] = param_3[1] + 0x18;
                }
                else {
                  iVar5 = param_3[2] - *param_3 >> 3;
                  iVar10 = ((int)puVar9 - *param_3 >> 3) * -0x55555555;
                  if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
                    uVar6 = iVar10 + 1;
                    local_5c = iVar5 * 0x55555556;
                    if (local_5c < uVar6) {
                      local_5c = uVar6;
                    }
                  }
                  FUN_001ccdd4(auStack_4c,local_5c,iVar10,param_3 + 3);
                  puVar9 = local_44;
                  *local_44 = uVar1;
                  __aeabi_memcpy(local_44 + 1,&local_30,7);
                  *(char **)(puVar9 + 8) = pcVar4;
                  local_2a = 0;
                  local_2c = 0;
                  local_30 = 0;
                  puVar9[0xc] = 0;
                  __aeabi_memcpy(puVar9 + 0xd,&local_38,7);
                  *(undefined4 *)(puVar9 + 0x14) = 0;
                  local_32 = 0;
                  local_44 = local_44 + 0x18;
                  local_34 = 0;
                  local_38 = 0;
                  FUN_001cce32(param_3,auStack_4c);
                  FUN_001cceae(auStack_4c);
                }
                *(undefined1 *)((int)param_3 + 0x3e) = 1;
              }
            }
            break;
          }
          iVar5 = iVar5 + 1;
          uVar6 = uVar7 + uVar6 * 10;
        } while (param_1 + iVar5 + (2 - (int)param_2) != (char *)0x0);
      }
    }
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FUN_001cc0b8  @0x001cc0b8  (362 bytes)
void FUN_001cc0b8(char *param_1,char *param_2,int *param_3)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  uint *puVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  uint local_68;
  uint uStack_64;
  void *local_60;
  uint local_58;
  uint uStack_54;
  void *local_50;
  byte local_48 [8];
  void *local_40;
  uint local_3c;
  undefined4 uStack_38;
  void *local_34;
  undefined4 uStack_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((((3 < (int)param_2 - (int)param_1) && (*param_1 == 'D')) &&
      ((byte)(param_1[1] | 0x20U) == 0x74)) &&
     (((pcVar2 = (char *)FUN_001ccfb8(param_1 + 2,param_2,param_3),
       pcVar2 != param_1 + 2 && pcVar2 != param_2 && (*pcVar2 == 'E')) &&
      (iVar3 = param_3[1], *param_3 != iVar3)))) {
    uVar7 = *(uint *)(iVar3 + -8);
    iVar6 = *(int *)(iVar3 + -4);
    if ((*(byte *)(iVar3 + -0xc) & 1) == 0) {
      iVar6 = iVar3 + -0xb;
      uVar7 = (uint)(*(byte *)(iVar3 + -0xc) >> 1);
    }
    puVar4 = (uint *)FUN_001cb080(iVar3 + -0x18,iVar6,uVar7);
    local_68 = *puVar4;
    uStack_64 = puVar4[1];
    local_60 = (void *)puVar4[2];
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4 = (uint *)FUN_001caf2a(&local_68,0,"decltype(",9);
    local_58 = *puVar4;
    uStack_54 = puVar4[1];
    local_50 = (void *)puVar4[2];
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    pbVar5 = (byte *)FUN_001cb080(&local_58,&DAT_0022045d,1);
    bVar1 = *pbVar5;
    __aeabi_memcpy(&uStack_30,pbVar5 + 1,7);
    pvVar8 = *(void **)(pbVar5 + 8);
    pbVar5[0] = 0;
    pbVar5[1] = 0;
    pbVar5[2] = 0;
    pbVar5[3] = 0;
    pbVar5[4] = 0;
    pbVar5[5] = 0;
    pbVar5[6] = 0;
    pbVar5[7] = 0;
    pbVar5[8] = 0;
    pbVar5[9] = 0;
    pbVar5[10] = 0;
    pbVar5[0xb] = 0;
    local_48[0] = bVar1;
    __aeabi_memcpy((uint)local_48 | 1,&uStack_30,7);
    local_2a = 0;
    local_2c = 0;
    local_34 = (void *)0x0;
    uStack_30 = 0;
    local_3c = 0;
    uStack_38 = 0;
    local_40 = pvVar8;
    FUN_001d0d6c(iVar3 + -0x18,local_48);
    if ((local_3c & 1) != 0) {
      free(local_34);
    }
    if ((local_48[0] & 1) != 0) {
      free(local_40);
    }
    if ((local_58 & 1) != 0) {
      free(local_50);
    }
    if ((local_68 & 1) != 0) {
      free(local_60);
    }
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001cc234  @0x001cc234  (2920 bytes)
/* WARNING (jumptable): Heritage AFTER dead removal. Revisit: 0xffffffb0 */
/* WARNING: Removing unreachable block (ram,0x001cc418) */
/* WARNING: Removing unreachable block (ram,0x001cc280) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_001cc234(byte *param_1,byte *param_2,int *param_3)

{
  undefined1 uVar1;
  byte bVar2;
  size_t sVar3;
  undefined4 uVar4;
  uint *puVar5;
  byte *pbVar6;
  size_t __size;
  byte *pbVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  void *pvVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  int iVar17;
  undefined1 *puVar18;
  byte *pbVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  uint uVar22;
  byte *pbVar23;
  void *pvVar24;
  int iVar25;
  uint uVar26;
  bool bVar27;
  undefined8 uVar28;
  byte *local_78;
  undefined4 local_70;
  uint local_6c;
  undefined1 *local_68;
  uint uStack_64;
  void *pvStack_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 *puStack_44;
  uint local_40;
  undefined4 local_3c;
  void *local_38;
  undefined2 uStack_34;
  undefined1 uStack_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_54 = CONCAT13(local_54._3_1_,CONCAT12(local_54._2_1_,(undefined2)local_54));
  local_28 = __stack_chk_guard;
  if (param_1 == param_2) goto LAB_001ccc06;
  uVar14 = (uint)*param_1;
  if (uVar14 - 0x31 < 9) {
    if (((param_1 != param_2) && (uVar14 = *param_1 - 0x30, uVar14 < 10)) &&
       (pbVar23 = param_1 + 1, pbVar23 != param_2)) {
      uVar10 = *pbVar23 - 0x30;
      if (uVar10 < 10) {
        pbVar6 = param_1 + 2;
        do {
          pbVar23 = pbVar6;
          if (param_2 == pbVar23) goto LAB_001d50d2;
          uVar14 = uVar10 + uVar14 * 10;
          uVar10 = *pbVar23 - 0x30;
          pbVar6 = pbVar23 + 1;
        } while (uVar10 < 10);
      }
      if (uVar14 <= (uint)((int)param_2 - (int)pbVar23)) {
        bVar27 = false;
        pvStack_60 = (void *)0x0;
        local_68 = (undefined1 *)0x0;
        uStack_64 = 0;
        FUN_001c5e62(&local_68,pbVar23,uVar14);
        local_50 = (undefined4 *)0x0;
        pvVar24 = (void *)((uint)&local_68 | 1);
        local_58._0_1_ = 0;
        local_54 = 0;
        local_6c = (uint)local_68 & 0xff;
        local_70 = pvStack_60;
        uVar14 = uStack_64;
        pvVar13 = pvStack_60;
        if (((uint)local_68 & 1) == 0) {
          uVar14 = (uint)local_68 >> 1 & 0x7f;
          pvVar13 = pvVar24;
        }
        if (9 < uVar14) {
          uVar14 = 10;
        }
        FUN_001c5e62(&local_58,pvVar13,uVar14);
        uVar14 = local_54;
        if (((byte)local_58 & 1) == 0) {
          uVar14 = (uint)((byte)local_58 >> 1);
        }
        if (uVar14 == 10) {
          puVar11 = local_50;
          if (((byte)local_58 & 1) == 0) {
            puVar11 = (undefined4 *)((uint)&local_58 | 1);
          }
          iVar12 = memcmp(puVar11,"_GLOBAL__N",10);
          if (iVar12 == 0) {
            bVar27 = true;
          }
        }
        if (((byte)local_58 & 1) != 0) {
          free(local_50);
        }
        if (bVar27) {
          pvVar13 = malloc(0x20);
          __aeabi_memcpy(pvVar13,"(anonymous namespace)",0x15);
          *(undefined1 *)((int)pvVar13 + 0x15) = 0;
          puVar11 = (undefined4 *)param_3[1];
          if (puVar11 < (undefined4 *)param_3[2]) {
            *puVar11 = 0x21;
            puVar11[1] = 0x15;
            puVar11[2] = pvVar13;
            *(undefined1 *)(puVar11 + 3) = 0;
            __aeabi_memcpy((int)puVar11 + 0xd,&local_30,7);
            puVar11[5] = 0;
            param_3[1] = param_3[1] + 0x18;
          }
          else {
            iVar12 = param_3[2] - *param_3 >> 3;
            iVar17 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
            uVar14 = 0xaaaaaaa;
            if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
              uVar10 = iVar17 + 1;
              uVar14 = iVar12 * 0x55555556;
              if (uVar14 < uVar10) {
                uVar14 = uVar10;
              }
            }
            FUN_001ccdd4(&local_58,uVar14,iVar17,param_3 + 3);
            *local_50 = 0x21;
            local_50[1] = 0x15;
            local_50[2] = pvVar13;
            *(undefined1 *)(local_50 + 3) = 0;
            __aeabi_memcpy((int)local_50 + 0xd,&local_30,7);
            local_50[5] = 0;
            FUN_001cce32(param_3,&local_58);
            FUN_001cceae(&local_58);
          }
          if ((local_6c & 1) != 0) {
            free(local_70);
          }
        }
        else {
          __aeabi_memcpy(&local_40,pvVar24,7);
          pvStack_60 = (void *)0x0;
          uStack_64 = 0;
          __aeabi_memcpy(&local_30,&local_40,7);
          uStack_32 = 0;
          uStack_34 = 0;
          puVar20 = (undefined1 *)param_3[1];
          if (puVar20 < (undefined1 *)param_3[2]) {
            *puVar20 = (undefined1)local_6c;
            __aeabi_memcpy(puVar20 + 1,&local_30,7);
            *(void **)(puVar20 + 8) = local_70;
            puVar20[0xc] = 0;
            __aeabi_memcpy(puVar20 + 0xd,&local_38,7);
            *(undefined4 *)(puVar20 + 0x14) = 0;
            uStack_32 = 0;
            uStack_34 = 0;
            param_3[1] = param_3[1] + 0x18;
          }
          else {
            iVar12 = param_3[2] - *param_3 >> 3;
            iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
            uVar14 = 0xaaaaaaa;
            if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
              uVar10 = iVar17 + 1;
              uVar14 = iVar12 * 0x55555556;
              if (uVar14 < uVar10) {
                uVar14 = uVar10;
              }
            }
            FUN_001ccdd4(&local_58,uVar14,iVar17,param_3 + 3);
            *(undefined1 *)local_50 = (undefined1)local_6c;
            __aeabi_memcpy((int)local_50 + 1,&local_30,7);
            local_50[2] = local_70;
            *(undefined1 *)(local_50 + 3) = 0;
            __aeabi_memcpy((int)local_50 + 0xd,&local_38,7);
            local_50[5] = 0;
            uStack_32 = 0;
            uStack_34 = 0;
            FUN_001cce32(param_3,&local_58);
            FUN_001cceae(&local_58);
          }
        }
      }
    }
LAB_001d50d2:
    if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(__stack_chk_guard - local_28);
    }
    return;
  }
  uVar10 = 0xaaaaaaa;
  if (uVar14 - 0x43 < 2) {
    if (((int)param_2 - (int)param_1 < 2) || (iVar12 = param_3[1], *param_3 == iVar12))
    goto LAB_001ccc06;
    if (uVar14 == 0x44) {
      if ((5 < param_1[1] - 0x30) || ((1 << (param_1[1] - 0x30 & 0xff) & 0x27U) == 0))
      goto LAB_001ccc06;
      FUN_001d50fc(&local_40,iVar12 + -0x18);
      puVar11 = (undefined4 *)FUN_001caf2a(&local_40,0,&DAT_00222226,1);
      uVar1 = *(undefined1 *)puVar11;
      __aeabi_memcpy(&local_58,(int)puVar11 + 1,7);
      uVar4 = puVar11[2];
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      __aeabi_memcpy(&local_50,&local_58,7);
      local_54 = (uint)local_54._3_1_ << 0x18;
      local_2a = 0;
      local_2c = 0;
      local_58 = 0;
      local_30 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if (puVar20 < (undefined1 *)param_3[2]) {
        *puVar20 = uVar1;
        __aeabi_memcpy(puVar20 + 1,&local_50,7);
        *(undefined4 *)(puVar20 + 8) = uVar4;
        local_4c = (uint)local_4c._3_1_ << 0x18;
        local_50 = (undefined4 *)0x0;
        puVar20[0xc] = 0;
        __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
        *(undefined4 *)(puVar20 + 0x14) = 0;
        goto LAB_001cc4de;
      }
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar14 = iVar17 + 1;
        uVar10 = iVar12 * 0x55555556;
        if (uVar10 < uVar14) {
          uVar10 = uVar14;
        }
      }
      FUN_001ccdd4(&local_70,uVar10,iVar17,param_3 + 3);
      puVar20 = local_68;
      *local_68 = uVar1;
      __aeabi_memcpy(local_68 + 1,&local_50,7);
      *(undefined4 *)(puVar20 + 8) = uVar4;
      local_4c = (uint)local_4c._3_1_ << 0x18;
      local_50 = (undefined4 *)0x0;
      puVar20[0xc] = 0;
      __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
      *(undefined4 *)(puVar20 + 0x14) = 0;
      local_2a = 0;
      local_68 = local_68 + 0x18;
      local_2c = 0;
      local_30 = 0;
      FUN_001cce32(param_3,&local_70);
LAB_001cc738:
      FUN_001cceae(&local_70);
    }
    else {
      if (((uVar14 != 0x43) || (4 < param_1[1] - 0x31)) || (param_1[1] - 0x31 == 3))
      goto LAB_001ccc06;
      FUN_001d50fc(&local_40,iVar12 + -0x18);
      uVar1 = (undefined1)local_40;
      __aeabi_memcpy(&local_50,(uint)&local_40 | 1,7);
      pvVar13 = local_38;
      local_38 = (void *)0x0;
      local_40 = 0;
      local_3c = 0;
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar14 = iVar17 + 1;
          uVar10 = iVar12 * 0x55555556;
          if (uVar10 < uVar14) {
            uVar10 = uVar14;
          }
        }
        FUN_001ccdd4(&local_70,uVar10,iVar17,param_3 + 3);
        puVar20 = local_68;
        *local_68 = uVar1;
        __aeabi_memcpy(local_68 + 1,&local_50,7);
        *(void **)(puVar20 + 8) = pvVar13;
        local_4c = (uint)local_4c._3_1_ << 0x18;
        local_50 = (undefined4 *)0x0;
        puVar20[0xc] = 0;
        __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
        *(undefined4 *)(puVar20 + 0x14) = 0;
        local_2a = 0;
        local_68 = local_68 + 0x18;
        local_2c = 0;
        local_30 = 0;
        FUN_001cce32(param_3,&local_70);
        goto LAB_001cc738;
      }
      *puVar20 = uVar1;
      __aeabi_memcpy(puVar20 + 1,&local_50,7);
      *(void **)(puVar20 + 8) = pvVar13;
      local_4c = (uint)local_4c._3_1_ << 0x18;
      local_50 = (undefined4 *)0x0;
      puVar20[0xc] = 0;
      __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
      *(undefined4 *)(puVar20 + 0x14) = 0;
LAB_001cc4de:
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      param_3[1] = param_3[1] + 0x18;
    }
    if ((local_40 & 1) != 0) {
      free(local_38);
    }
    *(undefined1 *)(param_3 + 0xf) = 1;
LAB_001ccc06:
    if (__stack_chk_guard - local_28 == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  if (uVar14 == 0x55) {
    if (2 < (int)param_2 - (int)param_1) {
      if (param_1[1] == 0x6c) {
        local_48 = 0;
        local_50 = (undefined4 *)0x0;
        local_4c = 0;
        FUN_001c5e62(&local_50,"\'lambda\'(",9);
        uVar1 = local_50._0_1_;
        __aeabi_memcpy(&local_40,(uint)&local_50 | 1,7);
        uVar4 = local_48;
        local_48 = 0;
        local_50 = (undefined4 *)0x0;
        local_4c = 0;
        local_2a = 0;
        local_2c = 0;
        local_30 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if (puVar20 < (undefined1 *)param_3[2]) {
          *puVar20 = uVar1;
          __aeabi_memcpy(puVar20 + 1,&local_40,7);
          *(undefined4 *)(puVar20 + 8) = uVar4;
          local_3c = (uint)local_3c._3_1_ << 0x18;
          local_40 = 0;
          puVar20[0xc] = 0;
          __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
          *(undefined4 *)(puVar20 + 0x14) = 0;
          local_2a = 0;
          local_2c = 0;
          local_30 = 0;
          param_3[1] = param_3[1] + 0x18;
        }
        else {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar14 = iVar17 + 1;
            uVar10 = iVar12 * 0x55555556;
            if (uVar10 < uVar14) {
              uVar10 = uVar14;
            }
          }
          FUN_001ccdd4(&local_70,uVar10,iVar17,param_3 + 3);
          puVar20 = local_68;
          *local_68 = uVar1;
          __aeabi_memcpy(local_68 + 1,&local_40,7);
          *(undefined4 *)(puVar20 + 8) = uVar4;
          local_3c = (uint)local_3c._3_1_ << 0x18;
          local_40 = 0;
          puVar20[0xc] = 0;
          __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
          *(undefined4 *)(puVar20 + 0x14) = 0;
          local_2a = 0;
          local_68 = local_68 + 0x18;
          local_2c = 0;
          local_30 = 0;
          FUN_001cce32(param_3,&local_70);
          FUN_001cceae(&local_70);
        }
        pbVar23 = param_1 + 2;
        if (*pbVar23 == 0x76) {
          FUN_001d530c(param_3[1] + -0x18,0x29);
          local_78 = param_1 + 3;
        }
        else {
          local_78 = (byte *)FUN_001c6af0(pbVar23,param_2,param_3);
          if (local_78 == pbVar23) {
            iVar12 = param_3[1];
            if (*param_3 != iVar12) {
              iVar17 = iVar12 + -0x18;
              do {
                param_3[1] = iVar12 + -0x18;
                if ((*(byte *)(iVar12 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar12 + -4));
                }
                if ((*(byte *)(iVar12 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar12 + -0x10));
                }
                iVar12 = param_3[1];
              } while (iVar12 != iVar17);
            }
            goto LAB_001ccc06;
          }
          iVar12 = param_3[1];
          if ((uint)((iVar12 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001ccc06;
          uVar14 = *(uint *)(iVar12 + -8);
          iVar17 = *(int *)(iVar12 + -4);
          if ((*(byte *)(iVar12 + -0xc) & 1) == 0) {
            iVar17 = iVar12 + -0xb;
            uVar14 = (uint)(*(byte *)(iVar12 + -0xc) >> 1);
          }
          puVar5 = (uint *)FUN_001cb080(iVar12 + -0x18,iVar17,uVar14);
          local_70 = (void *)*puVar5;
          local_6c = puVar5[1];
          local_68 = (undefined1 *)puVar5[2];
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          iVar17 = param_3[1];
          iVar12 = iVar17;
          do {
            param_3[1] = iVar12 + -0x18;
            if ((*(byte *)(iVar12 + -0xc) & 1) != 0) {
              free(*(void **)(iVar12 + -4));
            }
            if ((*(byte *)(iVar12 + -0x18) & 1) != 0) {
              free(*(void **)(iVar12 + -0x10));
            }
            puVar20 = local_68;
            iVar12 = param_3[1];
          } while (iVar12 != iVar17 + -0x18);
          uVar10 = (uint)local_70 & 0xff;
          puVar18 = (undefined1 *)((uint)&local_70 | 1);
          uVar14 = local_6c;
          puVar9 = local_68;
          if (((uint)local_70 & 1) == 0) {
            uVar14 = (uint)local_70 >> 1 & 0x7f;
            puVar9 = puVar18;
          }
          FUN_001cb080(iVar17 + -0x30,puVar9,uVar14);
          while (pbVar23 = (byte *)FUN_001c6af0(local_78,param_2,param_3), pbVar23 != local_78) {
            iVar12 = param_3[1];
            if ((uint)((iVar12 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001ccc3c;
            uVar14 = *(uint *)(iVar12 + -8);
            iVar17 = *(int *)(iVar12 + -4);
            if ((*(byte *)(iVar12 + -0xc) & 1) == 0) {
              iVar17 = iVar12 + -0xb;
              uVar14 = (uint)(*(byte *)(iVar12 + -0xc) >> 1);
            }
            pbVar6 = (byte *)FUN_001cb080(iVar12 + -0x18,iVar17,uVar14);
            bVar2 = *pbVar6;
            __aeabi_memcpy(&local_40,pbVar6 + 1,7);
            puVar9 = local_68;
            puVar21 = *(undefined1 **)(pbVar6 + 8);
            pbVar6[0] = 0;
            pbVar6[1] = 0;
            pbVar6[2] = 0;
            pbVar6[3] = 0;
            pbVar6[4] = 0;
            pbVar6[5] = 0;
            pbVar6[6] = 0;
            pbVar6[7] = 0;
            pbVar6[8] = 0;
            pbVar6[9] = 0;
            pbVar6[10] = 0;
            pbVar6[0xb] = 0;
            if ((uVar10 & 1) == 0) {
              local_70 = (void *)((uint)local_70._2_2_ << 0x10);
              sVar3 = (size_t)local_70;
            }
            else {
              *puVar20 = 0;
              local_6c = 0;
              if (((uint)local_70 & 1) == 0) {
                uVar10 = 10;
                uVar14 = (uint)local_70 & 0xff;
              }
              else {
                uVar10 = ((uint)local_70 & 0xfffffffe) - 1;
                uVar14 = (uint)local_70;
              }
              if ((uVar14 & 1) == 0) {
                uVar22 = (uVar14 & 0xff) >> 1;
                if ((uVar14 & 0xff) < 0x16) {
                  uVar26 = 10;
                }
                else {
                  uVar26 = (uVar22 + 0x10 & 0xf0) - 1;
                }
                bVar27 = true;
              }
              else {
                uVar26 = 10;
                uVar22 = 0;
                bVar27 = false;
              }
              sVar3 = (size_t)local_70;
              if (uVar26 != uVar10) {
                if (uVar26 == 10) {
                  if (bVar27) {
                    __aeabi_memcpy(puVar18,local_68,((uVar14 & 0xfe) >> 1) + 1);
                  }
                  else {
                    local_70._0_2_ = CONCAT11(*local_68,(undefined1)local_70);
                  }
                  free(puVar9);
                  local_70 = (void *)((uint)local_70 & 0xffffff00);
                  sVar3 = (size_t)local_70;
                }
                else {
                  __size = uVar26 + 1;
                  puVar20 = malloc(__size);
                  if ((uVar10 < uVar26) || (sVar3 = (size_t)local_70, puVar20 != (undefined1 *)0x0))
                  {
                    sVar3 = __size;
                    if (bVar27) {
                      __aeabi_memcpy(puVar20,puVar18,((uVar14 & 0xfe) >> 1) + 1);
                      local_6c = uVar22;
                      local_68 = puVar20;
                    }
                    else {
                      *puVar20 = *local_68;
                      free(local_68);
                      local_6c = uVar22;
                      local_68 = puVar20;
                    }
                  }
                }
              }
            }
            local_70 = (void *)sVar3;
            local_70 = (void *)CONCAT31(local_70._1_3_,bVar2);
            __aeabi_memcpy(puVar18,&local_40,7);
            iVar17 = param_3[1];
            iVar12 = iVar17;
            local_68 = puVar21;
            do {
              param_3[1] = iVar12 + -0x18;
              if ((*(byte *)(iVar12 + -0xc) & 1) != 0) {
                free(*(void **)(iVar12 + -4));
              }
              if ((*(byte *)(iVar12 + -0x18) & 1) != 0) {
                free(*(void **)(iVar12 + -0x10));
              }
              iVar12 = param_3[1];
            } while (iVar12 != iVar17 + -0x18);
            uVar14 = local_6c;
            if ((bVar2 & 1) == 0) {
              uVar14 = (uint)(bVar2 >> 1);
            }
            puVar20 = puVar21;
            uVar10 = (uint)bVar2;
            local_78 = pbVar23;
            if (uVar14 != 0) {
              FUN_001cb080(iVar17 + -0x30,&DAT_00222122,2);
              if ((bVar2 & 1) == 0) {
                puVar21 = puVar18;
              }
              FUN_001cb080(param_3[1] + -0x18,puVar21,uVar14);
            }
          }
          if (*param_3 == param_3[1]) {
LAB_001ccc3c:
            bVar27 = true;
          }
          else {
            FUN_001cb080(param_3[1] + -0x18,&DAT_0022045d,1);
            bVar27 = false;
          }
          if ((uVar10 & 1) != 0) {
            free(puVar20);
          }
          if (bVar27) goto LAB_001ccc06;
        }
        if ((local_78 == param_2) || (*local_78 != 0x45)) {
          iVar12 = param_3[1];
          if (*param_3 != iVar12) {
            iVar17 = iVar12 + -0x18;
            do {
              param_3[1] = iVar12 + -0x18;
              if ((*(byte *)(iVar12 + -0xc) & 1) != 0) {
                free(*(void **)(iVar12 + -4));
              }
              if ((*(byte *)(iVar12 + -0x18) & 1) != 0) {
                free(*(void **)(iVar12 + -0x10));
              }
              iVar12 = param_3[1];
            } while (iVar12 != iVar17);
          }
        }
        else {
          pbVar23 = local_78 + 1;
          if (pbVar23 == param_2) {
            iVar12 = param_3[1];
            if (*param_3 != iVar12) {
              iVar17 = iVar12 + -0x18;
              do {
                param_3[1] = iVar12 + -0x18;
                if ((*(byte *)(iVar12 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar12 + -4));
                }
                if ((*(byte *)(iVar12 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar12 + -0x10));
                }
                iVar12 = param_3[1];
              } while (iVar12 != iVar17);
            }
          }
          else {
            pbVar6 = pbVar23;
            if (*pbVar23 - 0x30 < 10) {
              for (local_78 = local_78 + 2;
                  (pbVar6 = param_2, local_78 != param_2 &&
                  (pbVar6 = local_78, *local_78 - 0x30 < 10)); local_78 = local_78 + 1) {
              }
              iVar12 = param_3[1];
              pbVar7 = (byte *)(iVar12 + -0x18);
              bVar2 = *pbVar7;
              uVar14 = (uint)bVar2;
              if ((bVar2 & 1) == 0) {
                iVar25 = iVar12 + -0x10;
                uVar10 = (uint)(bVar2 >> 1);
                iVar16 = iVar12 + -0x17;
                iVar17 = 10;
              }
              else {
                uVar14 = *(uint *)(iVar12 + -0x18);
                uVar10 = *(uint *)(iVar12 + -0x14);
                iVar16 = *(int *)(iVar12 + -0x10);
                iVar25 = iVar16 + 7;
                iVar17 = (uVar14 & 0xfffffffe) - 1;
              }
              uVar22 = (int)pbVar6 - (int)pbVar23;
              if (uVar22 != 0) {
                uVar26 = iVar25 - iVar16;
                if (iVar17 - uVar10 < uVar22) {
                  FUN_001d2ed2(pbVar7,iVar17,(uVar10 + uVar22) - iVar17);
                  iVar17 = *(int *)(iVar12 + -0x10);
                }
                else {
                  if ((uVar14 & 1) == 0) {
                    iVar17 = iVar12 + -0x17;
                  }
                  else {
                    iVar17 = *(int *)(iVar12 + -0x10);
                  }
                  if (uVar10 != uVar26) {
                    __aeabi_memmove(iVar17 + uVar26 + uVar22);
                  }
                }
                iVar16 = uVar10 + uVar22;
                if ((*pbVar7 & 1) == 0) {
                  *pbVar7 = (char)iVar16 * '\x02';
                }
                else {
                  *(int *)(iVar12 + -0x14) = iVar16;
                }
                *(undefined1 *)(iVar17 + iVar16) = 0;
                pbVar7 = (byte *)(iVar17 + uVar26);
                do {
                  pbVar19 = pbVar23 + 1;
                  *pbVar7 = *pbVar23;
                  pbVar7 = pbVar7 + 1;
                  pbVar23 = pbVar19;
                } while (pbVar6 != pbVar19);
              }
            }
            if (((pbVar6 == param_2) || (*pbVar6 != 0x5f)) &&
               (iVar12 = param_3[1], *param_3 != iVar12)) {
              iVar17 = iVar12 + -0x18;
              do {
                param_3[1] = iVar12 + -0x18;
                if ((*(byte *)(iVar12 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar12 + -4));
                }
                if ((*(byte *)(iVar12 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar12 + -0x10));
                }
                iVar12 = param_3[1];
              } while (iVar12 != iVar17);
            }
          }
        }
      }
      else if (param_1[1] == 0x74) {
        local_38 = (void *)0x0;
        local_40 = 0;
        local_3c = 0;
        FUN_001c5e62(&local_40,"\'unnamed",8);
        uVar1 = (undefined1)local_40;
        __aeabi_memcpy(&local_50,(uint)&local_40 | 1,7);
        pvVar13 = local_38;
        local_38 = (void *)0x0;
        local_40 = 0;
        local_3c = 0;
        local_2a = 0;
        local_2c = 0;
        local_30 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if (puVar20 < (undefined1 *)param_3[2]) {
          *puVar20 = uVar1;
          __aeabi_memcpy(puVar20 + 1,&local_50,7);
          *(void **)(puVar20 + 8) = pvVar13;
          local_4c = (uint)local_4c._3_1_ << 0x18;
          local_50 = (undefined4 *)0x0;
          puVar20[0xc] = 0;
          __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
          *(undefined4 *)(puVar20 + 0x14) = 0;
          local_2a = 0;
          local_2c = 0;
          local_30 = 0;
          param_3[1] = param_3[1] + 0x18;
        }
        else {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar14 = iVar17 + 1;
            uVar10 = iVar12 * 0x55555556;
            if (uVar10 < uVar14) {
              uVar10 = uVar14;
            }
          }
          FUN_001ccdd4(&local_70,uVar10,iVar17,param_3 + 3);
          puVar20 = local_68;
          *local_68 = uVar1;
          __aeabi_memcpy(local_68 + 1,&local_50,7);
          *(void **)(puVar20 + 8) = pvVar13;
          local_4c = (uint)local_4c._3_1_ << 0x18;
          local_50 = (undefined4 *)0x0;
          puVar20[0xc] = 0;
          __aeabi_memcpy(puVar20 + 0xd,&local_30,7);
          *(undefined4 *)(puVar20 + 0x14) = 0;
          local_2a = 0;
          local_68 = local_68 + 0x18;
          local_2c = 0;
          local_30 = 0;
          FUN_001cce32(param_3,&local_70);
          FUN_001cceae(&local_70);
        }
        pbVar23 = param_1 + 2;
        if (pbVar23 == param_2) {
          iVar17 = param_3[1];
          iVar12 = iVar17 + -0x18;
          do {
            param_3[1] = iVar17 + -0x18;
            if ((*(byte *)(iVar17 + -0xc) & 1) != 0) {
              free(*(void **)(iVar17 + -4));
            }
            if ((*(byte *)(iVar17 + -0x18) & 1) != 0) {
              free(*(void **)(iVar17 + -0x10));
            }
            iVar17 = param_3[1];
          } while (iVar17 != iVar12);
        }
        else {
          if (*pbVar23 - 0x30 < 10) {
            for (param_1 = param_1 + 3;
                (pbVar6 = param_2, param_1 != param_2 && (pbVar6 = param_1, *param_1 - 0x30 < 10));
                param_1 = param_1 + 1) {
            }
            FUN_001d2e44(param_3[1] + -0x18,pbVar23,pbVar6);
            pbVar23 = pbVar6;
          }
          FUN_001d530c(param_3[1] + -0x18,0x27);
          if ((pbVar23 == param_2) || (*pbVar23 != 0x5f)) {
            iVar17 = param_3[1];
            iVar12 = iVar17 + -0x18;
            do {
              param_3[1] = iVar17 + -0x18;
              if ((*(byte *)(iVar17 + -0xc) & 1) != 0) {
                free(*(void **)(iVar17 + -4));
              }
              if ((*(byte *)(iVar17 + -0x18) & 1) != 0) {
                free(*(void **)(iVar17 + -0x10));
              }
              iVar17 = param_3[1];
            } while (iVar17 != iVar12);
          }
        }
      }
    }
    goto LAB_001ccc06;
  }
  if ((int)param_2 - (int)param_1 < 2) goto switchD_001d3522_caseD_62;
  uVar4 = 0x3d3d72;
  uVar14 = 0xaaaaaaa;
  switch(*param_1) {
  case 0x61:
    bVar2 = param_1[1];
    if (bVar2 < 0x61) {
      if (bVar2 == 0x4e) {
        __aeabi_memcpy(&local_30,"operator&=",7);
        uStack_32 = 0;
        uStack_34 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar20) {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar10 = iVar17 + 1;
            uVar14 = iVar12 * 0x55555556;
            if (uVar14 < uVar10) {
              uVar14 = uVar10;
            }
          }
          FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
          puVar11 = puStack_44;
          *(undefined1 *)puStack_44 = 0x14;
          __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
          uVar4 = 0x3d2672;
          goto LAB_001d4c2e;
        }
        *puVar20 = 0x14;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x3d2672;
      }
      else {
        if (bVar2 != 0x53) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator=",7);
        uStack_32 = 0;
        uStack_34 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar20) {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar10 = iVar17 + 1;
            uVar14 = iVar12 * 0x55555556;
            if (uVar14 < uVar10) {
              uVar14 = uVar10;
            }
          }
          FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
          puVar11 = puStack_44;
          *(undefined1 *)puStack_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
          uVar4 = 0x3d72;
          goto LAB_001d4baa;
        }
        *puVar20 = 0x12;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x3d72;
      }
    }
    else {
      if (bVar2 != 0x6e && bVar2 != 100) {
        if (bVar2 != 0x61) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator&&",7);
        uVar4 = 0x262672;
        goto LAB_001d42e6;
      }
      __aeabi_memcpy(&local_30,"operator&",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x2672;
        goto LAB_001d4baa;
      }
      *puVar20 = 0x12;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x2672;
    }
    break;
  default:
    goto switchD_001d3522_caseD_62;
  case 99:
    bVar2 = param_1[1];
    if (bVar2 < 0x6f) {
      if (bVar2 == 0x6c) {
        __aeabi_memcpy(&local_30,"operator()",7);
        uVar4 = 0x292872;
        goto LAB_001d42e6;
      }
      if (bVar2 != 0x6d) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator,",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x2c72;
        goto LAB_001d4baa;
      }
      *puVar20 = 0x12;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x2c72;
    }
    else {
      if (bVar2 != 0x6f) {
        if (bVar2 == 0x76) {
          param_1 = param_1 + 2;
          uVar1 = *(undefined1 *)((int)param_3 + 0x3f);
          *(undefined1 *)((int)param_3 + 0x3f) = 0;
          uVar28 = FUN_001c6af0(param_1,param_2,param_3);
          *(undefined1 *)((int)param_3 + 0x3f) = uVar1;
          bVar27 = (byte *)uVar28 != param_1;
          if (bVar27) {
            uVar28 = CONCAT44(*param_3,param_3[1]);
          }
          if (bVar27 && (int)((ulonglong)uVar28 >> 0x20) != (int)uVar28) {
            FUN_001caf2a((int)uVar28 + -0x18,0,"operator ",9);
            *(undefined1 *)(param_3 + 0xf) = 1;
          }
        }
        goto switchD_001d3522_caseD_62;
      }
      __aeabi_memcpy(&local_30,"operator~",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x7e72;
        goto LAB_001d4baa;
      }
      *puVar20 = 0x12;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x7e72;
    }
    break;
  case 100:
    bVar2 = param_1[1];
    if (100 < bVar2) {
      if (bVar2 == 0x65) {
LAB_001d3f56:
        __aeabi_memcpy(&local_30,"operator*",7);
        uStack_32 = 0;
        uStack_34 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar20) {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar10 = iVar17 + 1;
            uVar14 = iVar12 * 0x55555556;
            if (uVar14 < uVar10) {
              uVar14 = uVar10;
            }
          }
          FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
          puVar11 = puStack_44;
          *(undefined1 *)puStack_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
          uVar4 = 0x2a72;
          goto LAB_001d4baa;
        }
        *puVar20 = 0x12;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x2a72;
      }
      else {
        if (bVar2 == 0x6c) {
          pvVar13 = malloc(0x10);
          uVar4 = 0xf;
          __aeabi_memcpy(pvVar13,"operator delete",0xf);
          *(undefined1 *)((int)pvVar13 + 0xf) = 0;
          puVar11 = (undefined4 *)param_3[1];
          if (puVar11 < (undefined4 *)param_3[2]) goto LAB_001d425a;
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar10 = iVar17 + 1;
            uVar14 = iVar12 * 0x55555556;
            if (uVar14 < uVar10) {
              uVar14 = uVar10;
            }
          }
          FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
          uVar4 = 0x11;
          uVar8 = 0xf;
          goto LAB_001d48d2;
        }
        if (bVar2 != 0x76) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator/",7);
        uStack_32 = 0;
        uStack_34 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar20) {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar10 = iVar17 + 1;
            uVar14 = iVar12 * 0x55555556;
            if (uVar14 < uVar10) {
              uVar14 = uVar10;
            }
          }
          FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
          puVar11 = puStack_44;
          *(undefined1 *)puStack_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
          uVar4 = 0x2f72;
          goto LAB_001d4baa;
        }
        *puVar20 = 0x12;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x2f72;
      }
      break;
    }
    if (bVar2 == 0x56) {
      __aeabi_memcpy(&local_30,"operator/=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x3d2f72;
        goto LAB_001d4c2e;
      }
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x3d2f72;
      break;
    }
    if (bVar2 != 0x61) goto switchD_001d3522_caseD_62;
    pvVar13 = malloc(0x20);
    uVar4 = 0x11;
    __aeabi_memcpy(pvVar13,"operator delete[]",0x11);
    *(undefined1 *)((int)pvVar13 + 0x11) = 0;
    puVar11 = (undefined4 *)param_3[1];
    if ((undefined4 *)param_3[2] <= puVar11) {
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      uVar4 = 0x21;
      uVar8 = 0x11;
      goto LAB_001d48d2;
    }
    uVar8 = 0x21;
LAB_001d425c:
    *puVar11 = uVar8;
    puVar11[1] = uVar4;
    puVar11[2] = pvVar13;
    *(undefined1 *)(puVar11 + 3) = 0;
    __aeabi_memcpy((int)puVar11 + 0xd,&local_30,7);
    puVar11[5] = 0;
    goto LAB_001d43b8;
  case 0x65:
    bVar2 = param_1[1];
    if (bVar2 != 0x4f) {
      if (bVar2 != 0x71) {
        if (bVar2 != 0x6f) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator^",7);
        uStack_32 = 0;
        uStack_34 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if (puVar20 < (undefined1 *)param_3[2]) {
          *puVar20 = 0x12;
          __aeabi_memcpy(puVar20 + 1,&local_30,7);
          uVar4 = 0x5e72;
          break;
        }
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x5e72;
        goto LAB_001d4baa;
      }
      __aeabi_memcpy(&local_30,"operator==",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      puVar9 = (undefined1 *)param_3[2];
      if (puVar20 < puVar9) {
        *puVar20 = 0x14;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        *(undefined4 *)(puVar20 + 8) = 0x3d3d72;
        goto LAB_001d3c16;
      }
      iVar12 = *param_3;
      iVar17 = (int)puVar20 - iVar12;
      goto LAB_001d4310;
    }
    __aeabi_memcpy(&local_30,"operator^=",7);
    uStack_32 = 0;
    uStack_34 = 0;
    puVar20 = (undefined1 *)param_3[1];
    if (puVar20 < (undefined1 *)param_3[2]) {
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      *(undefined4 *)(puVar20 + 8) = 0x3d5e72;
      puVar20[0xc] = 0;
      __aeabi_memcpy(puVar20 + 0xd,&local_38,7);
      *(undefined4 *)(puVar20 + 0x14) = 0;
LAB_001d4422:
      uStack_32 = 0;
      uStack_34 = 0;
      goto LAB_001d43b8;
    }
    iVar12 = param_3[2] - *param_3 >> 3;
    iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
      uVar10 = iVar17 + 1;
      uVar14 = iVar12 * 0x55555556;
      if (uVar14 < uVar10) {
        uVar14 = uVar10;
      }
    }
    FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
    puVar11 = puStack_44;
    *(undefined1 *)puStack_44 = 0x14;
    __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
    uVar4 = 0x3d5e72;
    goto LAB_001d4baa;
  case 0x67:
    if (param_1[1] == 0x74) {
      __aeabi_memcpy(&local_30,"operator>",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if (puVar20 < (undefined1 *)param_3[2]) {
        *puVar20 = 0x12;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x3e72;
        break;
      }
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x3e72;
    }
    else {
      if (param_1[1] != 0x65) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator>=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if (puVar20 < (undefined1 *)param_3[2]) {
        *puVar20 = 0x14;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x3d3e72;
        goto LAB_001d3c14;
      }
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x3d3e72;
    }
    goto LAB_001d4baa;
  case 0x69:
    if (param_1[1] != 0x78) goto switchD_001d3522_caseD_62;
    __aeabi_memcpy(&local_30,"operator[]",7);
    uVar4 = 0x5d5b72;
LAB_001d42e6:
    uStack_32 = 0;
    uStack_34 = 0;
    puVar20 = (undefined1 *)param_3[1];
    puVar9 = (undefined1 *)param_3[2];
    if (puVar9 <= puVar20) {
      iVar12 = *param_3;
      iVar17 = (int)puVar20 - iVar12;
LAB_001d4310:
      uStack_32 = 0;
      uStack_34 = 0;
      iVar12 = (int)puVar9 - iVar12 >> 3;
      iVar17 = (iVar17 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      puVar11[2] = uVar4;
      goto LAB_001d4bac;
    }
    *puVar20 = 0x14;
    __aeabi_memcpy(puVar20 + 1,&local_30,7);
    *(undefined4 *)(puVar20 + 8) = uVar4;
    goto LAB_001d4394;
  case 0x6c:
    bVar2 = param_1[1];
    if (0x68 < bVar2) {
      if (bVar2 == 0x69) {
        param_1 = param_1 + 2;
        uVar28 = FUN_001d4de4(param_1,param_2,param_3);
        bVar27 = (byte *)uVar28 != param_1;
        if (bVar27) {
          uVar28 = CONCAT44(*param_3,param_3[1]);
        }
        if (bVar27 && (int)((ulonglong)uVar28 >> 0x20) != (int)uVar28) {
          FUN_001caf2a((int)uVar28 + -0x18,0,"operator\"\" ",0xb);
        }
        goto switchD_001d3522_caseD_62;
      }
      if (bVar2 != 0x73) {
        if (bVar2 != 0x74) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator<",7);
        uStack_32 = 0;
        uStack_34 = 0;
        puVar20 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar20) {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar10 = iVar17 + 1;
            uVar14 = iVar12 * 0x55555556;
            if (uVar14 < uVar10) {
              uVar14 = uVar10;
            }
          }
          FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
          puVar11 = puStack_44;
          *(undefined1 *)puStack_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
          uVar4 = 0x3c72;
          goto LAB_001d4baa;
        }
        *puVar20 = 0x12;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x3c72;
        break;
      }
      __aeabi_memcpy(&local_30,"operator<<",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        puVar11[2] = 0x3c3c72;
        goto LAB_001d4c30;
      }
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      *(undefined4 *)(puVar20 + 8) = 0x3c3c72;
      goto LAB_001d4394;
    }
    if (bVar2 == 0x53) {
      pvVar13 = malloc(0x10);
      pcVar15 = "operator<<=";
      goto LAB_001d4232;
    }
    if (bVar2 != 0x65) goto switchD_001d3522_caseD_62;
    __aeabi_memcpy(&local_30,"operator<=",7);
    uStack_32 = 0;
    uStack_34 = 0;
    puVar20 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar20) {
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x3d3c72;
      goto LAB_001d4c2e;
    }
    *puVar20 = 0x14;
    __aeabi_memcpy(puVar20 + 1,&local_30,7);
    uVar4 = 0x3d3c72;
    break;
  case 0x6d:
    bVar2 = param_1[1];
    if (0x68 < bVar2) {
      if (bVar2 != 0x6d) {
        if (bVar2 != 0x6c) {
          if (bVar2 != 0x69) goto switchD_001d3522_caseD_62;
          goto LAB_001d3f94;
        }
        goto LAB_001d3f56;
      }
      __aeabi_memcpy(&local_30,"operator--",7);
      uVar4 = 0x2d2d72;
      goto LAB_001d42e6;
    }
    if (bVar2 == 0x49) {
      __aeabi_memcpy(&local_30,"operator-=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x3d2d72;
LAB_001d4c2e:
        puVar11[2] = uVar4;
LAB_001d4c30:
        *(undefined1 *)(puVar11 + 3) = 0;
        __aeabi_memcpy((undefined1 *)((int)puVar11 + 0xd),&local_38,7);
        puVar11[5] = 0;
        uStack_32 = 0;
        uStack_34 = 0;
        goto LAB_001d4c56;
      }
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x3d2d72;
    }
    else {
      if (bVar2 != 0x4c) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator*=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x3d2a72;
        goto LAB_001d4c2e;
      }
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x3d2a72;
    }
    break;
  case 0x6e:
    bVar2 = param_1[1];
    if (bVar2 < 0x67) {
      if (bVar2 == 0x61) {
        pvVar13 = malloc(0x10);
        uVar4 = 0xe;
        __aeabi_memcpy(pvVar13,"operator new[]",0xe);
        *(undefined1 *)((int)pvVar13 + 0xe) = 0;
        puVar11 = (undefined4 *)param_3[1];
        if ((undefined4 *)param_3[2] <= puVar11) {
          iVar12 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
            uVar10 = iVar17 + 1;
            uVar14 = iVar12 * 0x55555556;
            if (uVar14 < uVar10) {
              uVar14 = uVar10;
            }
          }
          FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
          uVar4 = 0x11;
          uVar8 = 0xe;
          goto LAB_001d48d2;
        }
        goto LAB_001d425a;
      }
      if (bVar2 != 0x65) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator!=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x3d2172;
        goto LAB_001d4c2e;
      }
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x3d2172;
    }
    else if (bVar2 == 0x67) {
LAB_001d3f94:
      __aeabi_memcpy(&local_30,"operator-",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x2d72;
        goto LAB_001d4baa;
      }
      *puVar20 = 0x12;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x2d72;
    }
    else {
      if (bVar2 != 0x74) {
        if (bVar2 != 0x77) goto switchD_001d3522_caseD_62;
        pvVar13 = malloc(0x10);
        uVar4 = 0xc;
        __aeabi_memcpy(pvVar13,"operator new",0xc);
        *(undefined1 *)((int)pvVar13 + 0xc) = 0;
        puVar11 = (undefined4 *)param_3[1];
        if (puVar11 < (undefined4 *)param_3[2]) goto LAB_001d425a;
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        uVar4 = 0x11;
        uVar8 = 0xc;
        goto LAB_001d48d2;
      }
      __aeabi_memcpy(&local_30,"operator!",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x2172;
        goto LAB_001d4baa;
      }
      *puVar20 = 0x12;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x2172;
    }
    break;
  case 0x6f:
    bVar2 = param_1[1];
    if (bVar2 == 0x52) {
      __aeabi_memcpy(&local_30,"operator|=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if (puVar20 < (undefined1 *)param_3[2]) {
        *puVar20 = 0x14;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x3d7c72;
LAB_001d3c14:
        *(undefined4 *)(puVar20 + 8) = uVar4;
LAB_001d3c16:
        puVar20[0xc] = 0;
        __aeabi_memcpy(puVar20 + 0xd,&local_38,7);
        *(undefined4 *)(puVar20 + 0x14) = 0;
        uStack_32 = 0;
        uStack_34 = 0;
        goto LAB_001d43b8;
      }
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x3d7c72;
    }
    else {
      if (bVar2 != 0x72) {
        if (bVar2 != 0x6f) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator||",7);
        uVar4 = 0x7c7c72;
        goto LAB_001d42e6;
      }
      __aeabi_memcpy(&local_30,"operator|",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if (puVar20 < (undefined1 *)param_3[2]) {
        *puVar20 = 0x12;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        uVar4 = 0x7c72;
        break;
      }
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x7c72;
    }
LAB_001d4baa:
    puVar11[2] = uVar4;
LAB_001d4bac:
    *(undefined1 *)(puVar11 + 3) = 0;
    __aeabi_memcpy((undefined1 *)((int)puVar11 + 0xd),&local_38,7);
    puVar11[5] = 0;
    uStack_32 = 0;
    puStack_44 = puStack_44 + 6;
    uStack_34 = 0;
    FUN_001cce32(param_3,&local_4c);
LAB_001d4c66:
    FUN_001cceae(&local_4c);
    goto switchD_001d3522_caseD_62;
  case 0x70:
    switch(param_1[1]) {
    case 0x6c:
      break;
    case 0x6d:
      pvVar13 = malloc(0x10);
      pcVar15 = "operator->*";
LAB_001d4232:
      uVar4 = 0xb;
      __aeabi_memcpy(pvVar13,pcVar15,0xb);
      *(undefined1 *)((int)pvVar13 + 0xb) = 0;
      puVar11 = (undefined4 *)param_3[1];
      if (puVar11 < (undefined4 *)param_3[2]) {
LAB_001d425a:
        uVar8 = 0x11;
        goto LAB_001d425c;
      }
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      uVar4 = 0x11;
      uVar8 = 0xb;
LAB_001d48d2:
      puVar11 = puStack_44;
      *puStack_44 = uVar4;
      puStack_44[1] = uVar8;
      puStack_44[2] = pvVar13;
      *(undefined1 *)(puStack_44 + 3) = 0;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 0xd),&local_30,7);
      puVar11[5] = 0;
LAB_001d4c56:
      puStack_44 = puStack_44 + 6;
      FUN_001cce32(param_3,&local_4c);
      goto LAB_001d4c66;
    case 0x6e:
    case 0x6f:
    case 0x71:
    case 0x72:
      goto switchD_001d3522_caseD_62;
    case 0x70:
      __aeabi_memcpy(&local_30,"operator++",7);
      uVar4 = 0x2b2b72;
      goto LAB_001d42e6;
    case 0x73:
      break;
    case 0x74:
      __aeabi_memcpy(&local_30,"operator->",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if (puVar20 < (undefined1 *)param_3[2]) {
        *puVar20 = 0x14;
        __aeabi_memcpy(puVar20 + 1,&local_30,7);
        *(undefined4 *)(puVar20 + 8) = 0x3e2d72;
        puVar20[0xc] = 0;
        __aeabi_memcpy(puVar20 + 0xd,&local_38,7);
        *(undefined4 *)(puVar20 + 0x14) = 0;
        goto LAB_001d4422;
      }
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x3e2d72;
      goto LAB_001d4baa;
    default:
      if (param_1[1] != 0x4c) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator+=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x3d2b72;
        goto LAB_001d4c2e;
      }
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x3d2b72;
      goto LAB_001d4392;
    }
    __aeabi_memcpy(&local_30,"operator+",7);
    uStack_32 = 0;
    uStack_34 = 0;
    puVar20 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar20) {
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x2b72;
      goto LAB_001d4baa;
    }
    *puVar20 = 0x12;
    __aeabi_memcpy(puVar20 + 1,&local_30,7);
    uVar4 = 0x2b72;
    break;
  case 0x71:
    if (param_1[1] != 0x75) goto switchD_001d3522_caseD_62;
    __aeabi_memcpy(&local_30,"operator?",7);
    uStack_32 = 0;
    uStack_34 = 0;
    puVar20 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar20) {
      iVar12 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
        uVar10 = iVar17 + 1;
        uVar14 = iVar12 * 0x55555556;
        if (uVar14 < uVar10) {
          uVar14 = uVar10;
        }
      }
      FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
      puVar11 = puStack_44;
      *(undefined1 *)puStack_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
      uVar4 = 0x3f72;
      goto LAB_001d4baa;
    }
    *puVar20 = 0x12;
    __aeabi_memcpy(puVar20 + 1,&local_30,7);
    uVar4 = 0x3f72;
    break;
  case 0x72:
    bVar2 = param_1[1];
    if (bVar2 < 0x6d) {
      if (bVar2 != 0x4d) {
        if (bVar2 != 0x53) goto switchD_001d3522_caseD_62;
        pvVar13 = malloc(0x10);
        pcVar15 = "operator>>=";
        goto LAB_001d4232;
      }
      __aeabi_memcpy(&local_30,"operator%=",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x3d2572;
        goto LAB_001d4c2e;
      }
      *puVar20 = 0x14;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x3d2572;
    }
    else {
      if (bVar2 == 0x73) {
        __aeabi_memcpy(&local_30,"operator>>",7);
        uVar4 = 0x3e3e72;
        goto LAB_001d42e6;
      }
      if (bVar2 != 0x6d) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator%",7);
      uStack_32 = 0;
      uStack_34 = 0;
      puVar20 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar20) {
        iVar12 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar20 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar12 * -0x55555555) < 0x5555555) {
          uVar10 = iVar17 + 1;
          uVar14 = iVar12 * 0x55555556;
          if (uVar14 < uVar10) {
            uVar14 = uVar10;
          }
        }
        FUN_001ccdd4(&local_4c,uVar14,iVar17,param_3 + 3);
        puVar11 = puStack_44;
        *(undefined1 *)puStack_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)puStack_44 + 1),&local_30,7);
        uVar4 = 0x2572;
        goto LAB_001d4baa;
      }
      *puVar20 = 0x12;
      __aeabi_memcpy(puVar20 + 1,&local_30,7);
      uVar4 = 0x2572;
    }
    break;
  case 0x76:
    if (param_1[1] - 0x30 < 10) {
      param_1 = param_1 + 2;
      uVar28 = FUN_001d4de4(param_1,param_2,param_3);
      bVar27 = (byte *)uVar28 != param_1;
      if (bVar27) {
        uVar28 = CONCAT44(*param_3,param_3[1]);
      }
      if (bVar27 && (int)((ulonglong)uVar28 >> 0x20) != (int)uVar28) {
        FUN_001caf2a((int)uVar28 + -0x18,0,"operator ",9);
      }
    }
    goto switchD_001d3522_caseD_62;
  }
LAB_001d4392:
  *(undefined4 *)(puVar20 + 8) = uVar4;
LAB_001d4394:
  puVar20[0xc] = 0;
  __aeabi_memcpy(puVar20 + 0xd,&local_38,7);
  *(undefined4 *)(puVar20 + 0x14) = 0;
  uStack_32 = 0;
  uStack_34 = 0;
LAB_001d43b8:
  param_3[1] = param_3[1] + 0x18;
switchD_001d3522_caseD_62:
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001ccdd4  @0x001ccdd4  (94 bytes)
undefined4 * FUN_001ccdd4(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  void *pvVar1;
  uint __size;
  void *pvVar2;
  int *piVar3;
  
  pvVar1 = (void *)0x0;
  param_1[3] = 0;
  param_1[4] = param_4;
  if (param_2 != 0) {
    piVar3 = (int *)(*param_4 + 0x1000);
    pvVar1 = *(void **)(*param_4 + 0x1000);
    __size = param_2 * 0x18 + 0xfU & 0xfffffff0;
    if ((uint)((int)piVar3 - (int)pvVar1) < __size) {
      pvVar1 = malloc(__size);
    }
    else {
      *piVar3 = __size + (int)pvVar1;
    }
  }
  pvVar2 = (void *)((int)pvVar1 + param_3 * 0x18);
  *param_1 = pvVar1;
  param_1[1] = pvVar2;
  param_1[2] = pvVar2;
  param_1[3] = (void *)((int)pvVar1 + param_2 * 0x18);
  return param_1;
}

// ===== FUN_001cce32  @0x001cce32  (124 bytes)
void FUN_001cce32(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)*param_1;
  if ((undefined4 *)param_1[1] == puVar6) {
    iVar5 = param_2[1];
  }
  else {
    iVar5 = param_2[1];
    puVar1 = (undefined4 *)param_1[1];
    do {
      puVar4 = puVar1 + -6;
      uVar2 = puVar1[-5];
      uVar3 = puVar1[-4];
      *(undefined4 *)(iVar5 + -0x18) = *puVar4;
      *(undefined4 *)(iVar5 + -0x14) = uVar2;
      *(undefined4 *)(iVar5 + -0x10) = uVar3;
      puVar1[-4] = 0;
      puVar1[-6] = 0;
      puVar1[-5] = 0;
      uVar2 = puVar1[-2];
      uVar3 = puVar1[-1];
      *(undefined4 *)(iVar5 + -0xc) = puVar1[-3];
      *(undefined4 *)(iVar5 + -8) = uVar2;
      *(undefined4 *)(iVar5 + -4) = uVar3;
      puVar1[-1] = 0;
      puVar1[-3] = 0;
      puVar1[-2] = 0;
      iVar5 = param_2[1] + -0x18;
      param_2[1] = iVar5;
      puVar1 = puVar4;
    } while (puVar6 != puVar4);
    puVar6 = (undefined4 *)*param_1;
  }
  *param_1 = iVar5;
  param_2[1] = puVar6;
  iVar5 = param_1[1];
  param_1[1] = param_2[2];
  param_2[2] = iVar5;
  iVar5 = param_1[2];
  param_1[2] = param_2[3];
  param_2[3] = iVar5;
  *param_2 = param_2[1];
  return;
}

// ===== FUN_001cceae  @0x001cceae  (84 bytes)
int * FUN_001cceae(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[1];
  while (iVar1 = param_1[2], iVar1 != iVar2) {
    param_1[2] = iVar1 + -0x18;
    if ((*(byte *)(iVar1 + -0xc) & 1) != 0) {
      free(*(void **)(iVar1 + -4));
    }
    if ((*(byte *)(iVar1 + -0x18) & 1) != 0) {
      free(*(void **)(iVar1 + -0x10));
    }
  }
  iVar2 = *param_1;
  if (iVar2 != 0) {
    FUN_001c5e0a(*(undefined4 *)param_1[4],iVar2,param_1[3] - iVar2);
  }
  return param_1;
}

// ===== FUN_001ccf02  @0x001ccf02  (110 bytes)
void FUN_001ccf02(uint *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar1 = (uint)(byte)*param_1;
  if (((byte)*param_1 & 1) == 0) {
    uVar2 = 10;
  }
  else {
    uVar1 = *param_1;
    uVar2 = (uVar1 & 0xfffffffe) - 1;
  }
  if (uVar2 < param_3) {
    if ((uVar1 & 1) == 0) {
      uVar1 = (uVar1 & 0xff) >> 1;
    }
    else {
      uVar1 = param_1[1];
    }
    FUN_001cafce(param_1,uVar2,param_3 - uVar2,uVar1,0,uVar1,param_3,param_2);
  }
  else {
    if ((uVar1 & 1) == 0) {
      pbVar3 = (byte *)((int)param_1 + 1);
    }
    else {
      pbVar3 = (byte *)param_1[2];
    }
    if (param_3 != 0) {
      __aeabi_memmove(pbVar3,param_2,param_3);
    }
    pbVar3[param_3] = 0;
    if ((*param_1 & 1) == 0) {
      *(byte *)param_1 = (byte)(param_3 << 1);
    }
    else {
      param_1[1] = param_3;
    }
  }
  return;
}

// ===== FUN_001ccf70  @0x001ccf70  (70 bytes)
void FUN_001ccf70(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  uint __size;
  
  if (param_4 < 0xb) {
    puVar1 = (undefined1 *)((int)param_1 + 1);
    *(char *)param_1 = (char)(param_3 << 1);
  }
  else {
    __size = param_4 + 0x10 & 0xfffffff0;
    puVar1 = malloc(__size);
    *param_1 = __size | 1;
    param_1[1] = param_3;
    param_1[2] = (uint)puVar1;
  }
  if (param_3 != 0) {
    __aeabi_memcpy(puVar1,param_2,param_3);
  }
  puVar1[param_3] = 0;
  return;
}

// ===== FUN_001ccfb8  @0x001ccfb8  (17584 bytes)
/* WARNING (jumptable): Heritage AFTER dead removal. Revisit: 0xffffff70 */
/* WARNING: Removing unreachable block (ram,0x001cd3e4) */
/* WARNING: Removing unreachable block (ram,0x001cd0c2) */
/* WARNING: Removing unreachable block (ram,0x001cd092) */
/* WARNING: Removing unreachable block (ram,0x001cd94a) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_001ccfb8(byte *param_1,byte *param_2,int *param_3)

{
  undefined1 uVar1;
  bool bVar2;
  byte bVar3;
  int *piVar4;
  int iVar5;
  byte **ppbVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  byte bVar11;
  byte *pbVar12;
  uint uVar13;
  undefined *puVar14;
  int iVar15;
  undefined1 *puVar16;
  int iVar17;
  void *pvVar18;
  undefined4 uVar19;
  uint uVar20;
  undefined4 *puVar21;
  byte **ppbVar22;
  uint uVar23;
  int iVar24;
  char cVar25;
  undefined1 *puVar26;
  byte *pbVar27;
  uint uVar28;
  byte *pbVar29;
  void *pvVar30;
  byte *pbVar31;
  int iVar32;
  byte *pbVar33;
  bool bVar34;
  bool bVar35;
  undefined8 uVar36;
  void *local_f0;
  uint local_ec;
  uint local_e8;
  int local_e4;
  byte *local_e0;
  byte local_dc [8];
  void *local_d4;
  uint local_d0;
  undefined4 local_cc;
  void *local_c8;
  uint local_c0;
  undefined4 local_bc;
  void *local_b8;
  byte *local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined2 uStack_a4;
  undefined1 uStack_a2;
  undefined1 uStack_a1;
  void *local_a0;
  undefined2 local_9c;
  undefined1 local_9a;
  uint local_98;
  undefined4 local_94;
  byte *local_90;
  undefined4 local_8c;
  byte *local_88;
  undefined2 local_84;
  undefined1 local_82;
  uint local_80;
  undefined4 local_7c;
  void *local_78;
  int local_74;
  byte *local_70;
  undefined4 local_6c;
  void *local_68;
  undefined4 local_64;
  byte *local_60;
  undefined4 local_5c;
  byte *local_58;
  byte *pbStack_54;
  byte *local_50;
  byte *local_4c;
  byte *local_48;
  byte *local_44;
  undefined4 local_40;
  void *local_3c;
  byte *local_38;
  uint local_34;
  byte *local_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_94 = CONCAT13(local_94._3_1_,CONCAT12(local_94._2_1_,(undefined2)local_94));
  local_ac = CONCAT13(local_ac._3_1_,CONCAT12(local_ac._2_1_,(undefined2)local_ac));
  local_28 = __stack_chk_guard;
  iVar5 = (int)param_2 - (int)param_1;
  if (iVar5 < 2) goto switchD_001cd01a_caseD_4d;
  pbVar12 = param_1;
  if (iVar5 < 4) {
    bVar34 = false;
  }
  else {
    bVar34 = false;
    if ((*param_1 == 0x67) && (bVar34 = param_1[1] == 0x73, bVar34)) {
      pbVar12 = param_1 + 2;
    }
  }
  pbVar31 = (byte *)0xaaaaaaa;
  pbVar33 = (byte *)0x5555555;
  switch((uint)*pbVar12) {
  case 0x4c:
    if (((int)param_2 - (int)param_1 < 4) || (*param_1 != 0x4c)) goto switchD_001d0fba_caseD_54;
    pbVar12 = param_1 + 1;
    uVar20 = 0xaaaaaaa;
    switch(*pbVar12) {
    case 0x54:
      goto switchD_001d0fba_caseD_54;
    default:
      pbVar33 = (byte *)FUN_001c6af0(pbVar12,param_2,param_3);
      if ((pbVar33 != pbVar12 && pbVar33 != param_2) &&
         (uVar20 = (uint)*pbVar33, pbVar12 = pbVar33, uVar20 != 0x45)) {
        while (uVar20 - 0x30 < 10) {
          pbVar12 = pbVar12 + 1;
          if (param_2 == pbVar12) goto switchD_001d0fba_caseD_54;
          uVar20 = (uint)*pbVar12;
        }
        if (((pbVar12 != pbVar33) && (uVar20 == 0x45)) && (iVar5 = param_3[1], *param_3 != iVar5)) {
          uVar20 = *(uint *)(iVar5 + -8);
          iVar17 = *(int *)(iVar5 + -4);
          if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
            iVar17 = iVar5 + -0xb;
            uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
          }
          local_ac = iVar5 - 0x18;
          puVar10 = (undefined4 *)FUN_001cb080(local_ac,iVar17,uVar20);
          local_a8._0_1_ = (byte)*puVar10;
          local_a0 = (void *)puVar10[2];
          uStack_a1 = (undefined1)((uint)puVar10[1] >> 0x18);
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          puVar10 = (undefined4 *)FUN_001caf2a(&local_a8,0,&DAT_00222248,1);
          local_78._0_1_ = (byte)*puVar10;
          local_74 = puVar10[1];
          local_70 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          puVar10 = (undefined4 *)FUN_001cb080(&local_78,&DAT_0022045d,1);
          local_68._0_1_ = (byte)*puVar10;
          local_64 = puVar10[1];
          local_60 = (byte *)puVar10[2];
          uVar20 = (int)pbVar12 - (int)pbVar33;
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          local_90 = (byte *)0x0;
          local_98 = 0;
          local_94 = 0;
          if (uVar20 < 0xb) {
                    /* WARNING: Ignoring partial resolution of indirect */
            local_98._0_1_ = (char)uVar20 * '\x02';
            pbVar31 = (byte *)((uint)&local_98 | 1);
            pbVar27 = pbVar31;
          }
          else {
            uVar23 = uVar20 + 0x10 & 0xfffffff0;
            pbVar31 = malloc(uVar23);
            local_98 = uVar23 | 1;
            local_94 = uVar20;
            local_90 = pbVar31;
            pbVar27 = pbVar31;
          }
          do {
            pbVar29 = pbVar33 + 1;
            *pbVar31 = *pbVar33;
            pbVar31 = pbVar31 + 1;
            pbVar33 = pbVar29;
          } while (pbVar12 != pbVar29);
          pbVar27[uVar20] = 0;
          local_b0 = local_90;
          uVar20 = local_94;
          if ((local_98 & 1) == 0) {
            local_90 = (byte *)((uint)&local_98 | 1);
            uVar20 = local_98 >> 1 & 0x7f;
          }
          pbVar12 = (byte *)FUN_001cb080(&local_68,local_90,uVar20);
          bVar11 = *pbVar12;
          __aeabi_memcpy(&local_88,pbVar12 + 1,7);
          pbVar33 = *(byte **)(pbVar12 + 8);
          pbVar12[0] = 0;
          pbVar12[1] = 0;
          pbVar12[2] = 0;
          pbVar12[3] = 0;
          pbVar12[4] = 0;
          pbVar12[5] = 0;
          pbVar12[6] = 0;
          pbVar12[7] = 0;
          pbVar12[8] = 0;
          pbVar12[9] = 0;
          pbVar12[10] = 0;
          pbVar12[0xb] = 0;
          local_50._0_1_ = bVar11;
                    /* WARNING: Ignoring partial resolution of indirect */
          __aeabi_memcpy((uint)&local_50 | 1,&local_88,7);
          local_82 = 0;
          local_84 = 0;
          local_3c = (void *)0x0;
          local_44._0_1_ = 0;
          local_48 = pbVar33;
          FUN_001d0d6c(local_ac,&local_50);
          if (((byte)local_44 & 1) != 0) {
            free(local_3c);
          }
          if (((byte)local_50 & 1) != 0) {
            free(local_48);
          }
          if ((local_98 & 1) != 0) {
            free(local_b0);
          }
          if (((byte)local_68 & 1) != 0) {
            free(local_60);
          }
          if (((byte)local_78 & 1) != 0) {
            free(local_70);
          }
          if (((byte)local_a8 & 1) != 0) {
            free(local_a0);
          }
        }
      }
      goto switchD_001d0fba_caseD_54;
    case 0x5f:
      if (param_1[2] == 0x5a) {
        FUN_001c5f90(param_1 + 3,param_2,param_3);
      }
      goto switchD_001d0fba_caseD_54;
    case 0x61:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,"signed char",0xb);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x62:
      if (param_1[3] != 0x45) goto switchD_001d0fba_caseD_54;
      if (param_1[2] == 0x31) {
        local_64 = (uint)local_64._3_1_ << 0x18;
        puVar26 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar26) {
          iVar5 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar26 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
            uVar23 = iVar17 + 1;
            uVar20 = iVar5 * 0x55555556;
            if (uVar20 < uVar23) {
              uVar20 = uVar23;
            }
          }
          FUN_001ccdd4(&local_50,uVar20,iVar17,param_3 + 3);
          *local_48 = 8;
          local_48[1] = 0x74;
          local_48[2] = 0x72;
          local_48[3] = 0x75;
          local_48[4] = 0x65;
          local_48[5] = 0;
          local_48[6] = 0;
          local_48[7] = 0;
          local_48[8] = 0;
          local_48[9] = 0;
          local_48[10] = 0;
          local_48[0xb] = 0;
          pbVar12 = local_48;
LAB_001d1880:
          pbVar12[0xc] = 0;
          __aeabi_memcpy(pbVar12 + 0xd,&local_68,7);
          pbVar12[0x14] = 0;
          pbVar12[0x15] = 0;
          pbVar12[0x16] = 0;
          pbVar12[0x17] = 0;
          local_64 = local_64 & 0xff000000;
          FUN_001cce32(param_3,&local_50);
          FUN_001cceae(&local_50);
          goto switchD_001d0fba_caseD_54;
        }
        *puVar26 = 8;
        *(undefined4 *)(puVar26 + 1) = 0x65757274;
        puVar26[5] = 0;
        *(undefined2 *)(puVar26 + 6) = 0;
        *(undefined4 *)(puVar26 + 8) = 0;
      }
      else {
        if (param_1[2] != 0x30) goto switchD_001d0fba_caseD_54;
        local_74._0_1_ = 0x65;
        local_64 = (uint)local_64._3_1_ << 0x18;
        local_78 = (void *)0x736c6166;
        puVar26 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar26) {
          iVar5 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar26 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
            uVar23 = iVar17 + 1;
            uVar20 = iVar5 * 0x55555556;
            if (uVar20 < uVar23) {
              uVar20 = uVar23;
            }
          }
          FUN_001ccdd4(&local_50,uVar20,iVar17,param_3 + 3);
          *local_48 = 10;
          local_48[5] = (byte)local_74;
          *(void **)(local_48 + 1) = local_78;
          local_48[6] = 0;
          local_48[7] = 0;
          local_48[8] = 0;
          local_48[9] = 0;
          local_48[10] = 0;
          local_48[0xb] = 0;
          local_74 = (uint)local_74._1_3_ << 8;
          pbVar12 = local_48;
          goto LAB_001d1880;
        }
        *puVar26 = 10;
        puVar26[5] = 0x65;
        *(undefined4 *)(puVar26 + 1) = 0x736c6166;
        puVar26[6] = 0;
        puVar26[7] = 0;
        *(undefined4 *)(puVar26 + 8) = 0;
        local_74 = (uint)local_74._1_3_ << 8;
      }
      puVar26[0xc] = 0;
      __aeabi_memcpy(puVar26 + 0xd,&local_68,7);
      *(undefined4 *)(puVar26 + 0x14) = 0;
      local_64 = local_64 & 0xff000000;
      param_3[1] = param_3[1] + 0x18;
      goto switchD_001d0fba_caseD_54;
    case 99:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,&DAT_002222a1,4);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 100:
      if ((uint)((int)param_2 - (int)(param_1 + 2)) < 0x11) goto switchD_001d0fba_caseD_54;
      uVar23 = (uint)param_1[2];
      iVar17 = -3;
      iVar5 = 0;
      do {
        iVar32 = iVar5;
        if ((*(byte *)(_ctype_ + 1 + uVar23) & 0x44) == 0) goto switchD_001d0fba_caseD_54;
        if (9 < uVar23 - 0x30) {
          uVar23 = uVar23 + 9;
        }
        iVar17 = iVar17 + -2;
        cVar25 = -0x57;
        if (param_1[iVar32 * 2 + 3] - 0x30 < 10) {
          cVar25 = -0x30;
        }
        *(byte *)((int)&local_a8 + iVar32) = cVar25 + param_1[iVar32 * 2 + 3] + (char)(uVar23 << 4);
        uVar23 = (uint)param_1[iVar32 * 2 + 4];
        iVar5 = iVar32 + 1;
      } while (iVar17 != -0x13);
      if (uVar23 != 0x45) goto switchD_001d0fba_caseD_54;
      if ((&local_a8 < (undefined4 *)((int)&local_a8 + iVar32)) && (iVar32 + 1 != 0)) {
        *(byte *)((int)&local_a8 + iVar32) = (byte)local_a8;
        if (1 < iVar32 + -1) {
          puVar26 = (undefined1 *)((uint)&local_a8 | 1);
          puVar7 = (undefined1 *)((int)&local_ac + iVar32 + 3);
          do {
            uVar1 = *puVar26;
            puVar8 = puVar26 + 1;
            *puVar26 = *puVar7;
            puVar16 = puVar7 + -1;
            *puVar7 = uVar1;
            puVar26 = puVar8;
            puVar7 = puVar16;
          } while (puVar8 < puVar16);
        }
      }
      __aeabi_memclr8(&local_50,0x20);
      uVar23 = FUN_001d6588(&local_50,0x20,&DAT_002222c7);
      if (0x1f < uVar23) goto switchD_001d0fba_caseD_54;
      goto LAB_001d167c;
    case 0x65:
      if ((uint)((int)param_2 - (int)(param_1 + 2)) < 0x11) goto switchD_001d0fba_caseD_54;
      uVar23 = (uint)param_1[2];
      iVar17 = -3;
      iVar5 = 0;
      do {
        iVar32 = iVar5;
        if ((*(byte *)(_ctype_ + 1 + uVar23) & 0x44) == 0) goto switchD_001d0fba_caseD_54;
        if (9 < uVar23 - 0x30) {
          uVar23 = uVar23 + 9;
        }
        iVar17 = iVar17 + -2;
        cVar25 = -0x57;
        if (param_1[iVar32 * 2 + 3] - 0x30 < 10) {
          cVar25 = -0x30;
        }
        *(byte *)((int)&local_a8 + iVar32) = cVar25 + param_1[iVar32 * 2 + 3] + (char)(uVar23 << 4);
        uVar23 = (uint)param_1[iVar32 * 2 + 4];
        iVar5 = iVar32 + 1;
      } while (iVar17 != -0x13);
      if (uVar23 != 0x45) goto switchD_001d0fba_caseD_54;
      if ((&local_a8 < (undefined4 *)((int)&local_a8 + iVar32)) && (iVar32 + 1 != 0)) {
        *(byte *)((int)&local_a8 + iVar32) = (byte)local_a8;
        if (1 < iVar32 + -1) {
          puVar26 = (undefined1 *)((uint)&local_a8 | 1);
          puVar7 = (undefined1 *)((int)&local_ac + iVar32 + 3);
          do {
            uVar1 = *puVar26;
            puVar8 = puVar26 + 1;
            *puVar26 = *puVar7;
            puVar16 = puVar7 + -1;
            *puVar7 = uVar1;
            puVar26 = puVar8;
            puVar7 = puVar16;
          } while (puVar8 < puVar16);
        }
      }
      __aeabi_memclr8(&local_50,0x28);
      uVar23 = FUN_001d6588(&local_50,0x28,&DAT_002222ca);
      if (0x27 < uVar23) goto switchD_001d0fba_caseD_54;
      goto LAB_001d167c;
    case 0x66:
      if ((uint)((int)param_2 - (int)(param_1 + 2)) < 9) goto switchD_001d0fba_caseD_54;
      uVar23 = (uint)param_1[2];
      iVar17 = -3;
      iVar5 = 0;
      do {
        iVar32 = iVar5;
        if ((*(byte *)(_ctype_ + 1 + uVar23) & 0x44) == 0) goto switchD_001d0fba_caseD_54;
        if (9 < uVar23 - 0x30) {
          uVar23 = uVar23 + 9;
        }
        iVar17 = iVar17 + -2;
        cVar25 = -0x57;
        if (param_1[iVar32 * 2 + 3] - 0x30 < 10) {
          cVar25 = -0x30;
        }
        *(byte *)((int)&local_a8 + iVar32) = cVar25 + param_1[iVar32 * 2 + 3] + (char)(uVar23 << 4);
        uVar23 = (uint)param_1[iVar32 * 2 + 4];
        iVar5 = iVar32 + 1;
      } while (iVar17 != -0xb);
      if (uVar23 != 0x45) goto switchD_001d0fba_caseD_54;
      if ((&local_a8 < (undefined4 *)((int)&local_a8 + iVar32)) && (iVar32 + 1 != 0)) {
        *(byte *)((int)&local_a8 + iVar32) = (byte)local_a8;
        if (1 < iVar32 + -1) {
          puVar26 = (undefined1 *)((uint)&local_a8 | 1);
          puVar7 = (undefined1 *)((int)&local_ac + iVar32 + 3);
          do {
            uVar1 = *puVar26;
            puVar8 = puVar26 + 1;
            *puVar26 = *puVar7;
            puVar16 = puVar7 + -1;
            *puVar7 = uVar1;
            puVar26 = puVar8;
            puVar7 = puVar16;
          } while (puVar8 < puVar16);
        }
      }
      __aeabi_memclr8(&local_50,0x18);
      uVar23 = FUN_001d6588(&local_50,0x18,&DAT_002222c3);
      if (0x17 < uVar23) goto switchD_001d0fba_caseD_54;
LAB_001d167c:
      local_70 = (byte *)0x0;
      local_74 = 0;
      local_78 = (void *)0x0;
      FUN_001c5e62(&local_78,&local_50);
      local_ac = (uint)local_78 & 0xff;
      __aeabi_memcpy(&local_98,(uint)&local_78 | 1,7);
      local_74 = 0;
      puVar26 = (undefined1 *)param_3[1];
      if (puVar26 < (undefined1 *)param_3[2]) {
        *puVar26 = (char)local_ac;
        __aeabi_memcpy(puVar26 + 1,&local_98,7);
        *(byte **)(puVar26 + 8) = local_70;
        local_94 = (uint)local_94._3_1_ << 0x18;
        puVar26[0xc] = 0;
        __aeabi_memcpy(puVar26 + 0xd,&local_80,7);
        *(undefined4 *)(puVar26 + 0x14) = 0;
        param_3[1] = param_3[1] + 0x18;
      }
      else {
        local_b0 = local_70;
        iVar5 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)puVar26 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
          uVar23 = iVar17 + 1;
          uVar20 = iVar5 * 0x55555556;
          if (uVar20 < uVar23) {
            uVar20 = uVar23;
          }
        }
        FUN_001ccdd4(&local_68,uVar20,iVar17,param_3 + 3);
        *local_60 = (byte)local_ac;
        __aeabi_memcpy(local_60 + 1,&local_98,7);
        *(byte **)(local_60 + 8) = local_b0;
        local_94 = (uint)local_94._3_1_ << 0x18;
        local_60[0xc] = 0;
        __aeabi_memcpy(local_60 + 0xd,&local_80,7);
        local_60[0x14] = 0;
        local_60[0x15] = 0;
        local_60[0x16] = 0;
        local_60[0x17] = 0;
        FUN_001cce32(param_3,&local_68);
        FUN_001cceae(&local_68);
      }
      goto switchD_001d0fba_caseD_54;
    case 0x68:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,"unsigned char",0xd);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x69:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,&DAT_0021f762,0);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x6a:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,&DAT_002222ac,1);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x6c:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,&DAT_002222ae,1);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x6d:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,&DAT_002222b0,2);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x6e:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,"__int128",8);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x6f:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,"unsigned __int128",0x11);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x73:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,"short",5);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x74:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,"unsigned short",0xe);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x77:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,"wchar_t",7);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x78:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,&DAT_002222b3,2);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x79:
      local_48 = (byte *)0x0;
      local_50._0_1_ = 0;
      FUN_001c5e62(&local_50,&DAT_002222b6,3);
      FUN_001d2ba0(param_1 + 2,param_2,&local_50,param_3);
    }
    if (((byte)local_50 & 1) != 0) {
      free(local_48);
    }
switchD_001d0fba_caseD_54:
    if (__stack_chk_guard - local_28 == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x62:
  case 0x68:
  case 0x6a:
  case 0x6b:
    goto switchD_001cd01a_caseD_4d;
  case 0x54:
    if ((1 < (int)param_2 - (int)param_1) && (*param_1 == 0x54)) {
      local_5c = 0xaaaaaaa;
      if (param_1[1] == 0x5f) {
        iVar5 = param_3[9];
        if (param_3[8] != iVar5) {
          piVar4 = *(int **)(iVar5 + -0x10);
          if (piVar4 == *(int **)(iVar5 + -0xc)) {
            uStack_2c._2_1_ = 0;
            uStack_2c._0_2_ = 0;
            puVar26 = (undefined1 *)param_3[1];
            if (puVar26 < (undefined1 *)param_3[2]) {
              *puVar26 = 4;
              *(undefined2 *)(puVar26 + 1) = 0x5f54;
              puVar26[3] = 0;
              *(undefined4 *)(puVar26 + 4) = 0;
              *(undefined4 *)(puVar26 + 8) = 0;
              puVar26[0xc] = 0;
              __aeabi_memcpy(puVar26 + 0xd,&local_30,7);
              *(undefined4 *)(puVar26 + 0x14) = 0;
              uStack_2c._2_1_ = 0;
              uStack_2c._0_2_ = 0;
              param_3[1] = param_3[1] + 0x18;
            }
            else {
              iVar5 = param_3[2] - *param_3 >> 3;
              iVar17 = ((int)puVar26 - *param_3 >> 3) * -0x55555555;
              if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
                uVar20 = iVar17 + 1;
                local_5c = iVar5 * 0x55555556;
                if (local_5c < uVar20) {
                  local_5c = uVar20;
                }
              }
              FUN_001ccdd4(&local_4c,local_5c,iVar17,param_3 + 3);
              *local_44 = 4;
              pbVar12 = local_44;
              pbVar12[1] = 0x54;
              pbVar12[2] = 0x5f;
              local_44[3] = 0;
              pbVar12[4] = 0;
              pbVar12[5] = 0;
              pbVar12[6] = 0;
              pbVar12[7] = 0;
              pbVar12[8] = 0;
              pbVar12[9] = 0;
              pbVar12[10] = 0;
              pbVar12[0xb] = 0;
              local_44[0xc] = 0;
              __aeabi_memcpy(local_44 + 0xd,&local_30,7);
              pbVar12[0x14] = 0;
              pbVar12[0x15] = 0;
              pbVar12[0x16] = 0;
              pbVar12[0x17] = 0;
              uStack_2c._2_1_ = 0;
              uStack_2c._0_2_ = 0;
              FUN_001cce32(param_3,&local_4c);
              FUN_001cceae(&local_4c);
            }
            *(undefined1 *)((int)param_3 + 0x3e) = 1;
          }
          else {
            iVar5 = *piVar4;
            iVar17 = piVar4[1];
            if (iVar5 != iVar17) {
              do {
                iVar32 = param_3[1];
                if (iVar32 == param_3[2]) {
                  iVar32 = iVar32 - *param_3 >> 3;
                  uVar23 = iVar32 * -0x55555555;
                  uVar20 = 0xaaaaaaa;
                  if (uVar23 < 0x5555555) {
                    uVar20 = iVar32 * 0x55555556;
                    if (uVar20 < uVar23 + 1) {
                      uVar20 = uVar23 + 1;
                    }
                  }
                  FUN_001ccdd4(&local_4c,uVar20,uVar23,param_3 + 3);
                  iVar32 = FUN_001c5e34(local_44,iVar5);
                  FUN_001c5e34(iVar32 + 0xc,iVar5 + 0xc);
                  local_44 = local_44 + 0x18;
                  FUN_001cce32(param_3,&local_4c);
                  FUN_001cceae(&local_4c);
                }
                else {
                  iVar32 = FUN_001c5e34(iVar32,iVar5);
                  FUN_001c5e34(iVar32 + 0xc,iVar5 + 0xc);
                  param_3[1] = param_3[1] + 0x18;
                }
                iVar5 = iVar5 + 0x18;
              } while (iVar17 != iVar5);
            }
          }
        }
      }
      else {
        uVar20 = param_1[1] - 0x30;
        if ((uVar20 < 10) && (param_1 + 2 != param_2)) {
          iVar5 = 0;
          do {
            uVar23 = param_1[iVar5 + 2] - 0x30;
            if (9 < uVar23) {
              if ((param_1[iVar5 + 2] == 0x5f) && (iVar17 = param_3[9], param_3[8] != iVar17)) {
                iVar32 = *(int *)(iVar17 + -0x10);
                uVar20 = uVar20 + 1;
                if (uVar20 < (uint)(*(int *)(iVar17 + -0xc) - iVar32 >> 4)) {
                  iVar5 = *(int *)(iVar32 + uVar20 * 0x10);
                  iVar17 = *(int *)(iVar32 + uVar20 * 0x10 + 4);
                  if (iVar5 != iVar17) {
                    do {
                      iVar32 = param_3[1];
                      if (iVar32 == param_3[2]) {
                        iVar32 = iVar32 - *param_3 >> 3;
                        uVar23 = iVar32 * -0x55555555;
                        uVar20 = 0xaaaaaaa;
                        if (uVar23 < 0x5555555) {
                          uVar20 = iVar32 * 0x55555556;
                          if (uVar20 < uVar23 + 1) {
                            uVar20 = uVar23 + 1;
                          }
                        }
                        FUN_001ccdd4(&local_4c,uVar20,uVar23,param_3 + 3);
                        iVar32 = FUN_001c5e34(local_44,iVar5);
                        FUN_001c5e34(iVar32 + 0xc,iVar5 + 0xc);
                        local_44 = local_44 + 0x18;
                        FUN_001cce32(param_3,&local_4c);
                        FUN_001cceae(&local_4c);
                      }
                      else {
                        iVar32 = FUN_001c5e34(iVar32,iVar5);
                        FUN_001c5e34(iVar32 + 0xc,iVar5 + 0xc);
                        param_3[1] = param_3[1] + 0x18;
                      }
                      iVar5 = iVar5 + 0x18;
                    } while (iVar17 != iVar5);
                  }
                }
                else {
                  pbVar12 = (byte *)(iVar5 + 3);
                  local_50 = (byte *)0x0;
                  pbStack_54 = (byte *)0x0;
                  if (pbVar12 < (byte *)0xb) {
                    /* WARNING: Ignoring partial resolution of indirect */
                    local_58._0_1_ = (char)pbVar12 * '\x02';
                    pbVar33 = (byte *)((uint)&local_58 | 1);
                  }
                  else {
                    uVar20 = iVar5 + 0x13U & 0xfffffff0;
                    pbVar33 = malloc(uVar20);
                    local_58._0_1_ = (byte)uVar20 | 1;
                    local_50 = pbVar33;
                    pbStack_54 = pbVar12;
                  }
                  if (iVar5 != -3) {
                    *pbVar33 = 0x54;
                    if (iVar5 != -2) {
                      iVar5 = iVar5 + 2;
                      pbVar31 = pbVar33;
                      do {
                        param_1 = param_1 + 1;
                        pbVar31 = pbVar31 + 1;
                        iVar5 = iVar5 + -1;
                        *pbVar31 = *param_1;
                      } while (iVar5 != 0);
                    }
                    pbVar33 = pbVar33 + (int)pbVar12;
                  }
                  *pbVar33 = 0;
                  __aeabi_memcpy(&local_30,(uint)&local_58 | 1,7);
                  pbStack_54 = (byte *)0x0;
                  pbVar12 = (byte *)param_3[1];
                  if (pbVar12 < (byte *)param_3[2]) {
                    *pbVar12 = (byte)local_58;
                    __aeabi_memcpy(pbVar12 + 1,&local_30,7);
                    *(byte **)(pbVar12 + 8) = local_50;
                    uStack_2c._2_1_ = 0;
                    uStack_2c._0_2_ = 0;
                    pbVar12[0xc] = 0;
                    __aeabi_memcpy(pbVar12 + 0xd,&local_38,7);
                    pbVar12[0x14] = 0;
                    pbVar12[0x15] = 0;
                    pbVar12[0x16] = 0;
                    pbVar12[0x17] = 0;
                    param_3[1] = param_3[1] + 0x18;
                  }
                  else {
                    iVar5 = param_3[2] - *param_3 >> 3;
                    iVar17 = ((int)pbVar12 - *param_3 >> 3) * -0x55555555;
                    if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
                      uVar20 = iVar17 + 1;
                      local_5c = iVar5 * 0x55555556;
                      if (local_5c < uVar20) {
                        local_5c = uVar20;
                      }
                    }
                    FUN_001ccdd4(&local_4c,local_5c,iVar17,param_3 + 3);
                    *local_44 = (byte)local_58;
                    __aeabi_memcpy(local_44 + 1,&local_30,7);
                    *(byte **)(local_44 + 8) = local_50;
                    uStack_2c._2_1_ = 0;
                    uStack_2c._0_2_ = 0;
                    local_44[0xc] = 0;
                    __aeabi_memcpy(local_44 + 0xd,&local_38,7);
                    local_44[0x14] = 0;
                    local_44[0x15] = 0;
                    local_44[0x16] = 0;
                    local_44[0x17] = 0;
                    FUN_001cce32(param_3,&local_4c);
                    FUN_001cceae(&local_4c);
                  }
                  *(undefined1 *)((int)param_3 + 0x3e) = 1;
                }
              }
              break;
            }
            iVar5 = iVar5 + 1;
            uVar20 = uVar23 + uVar20 * 10;
          } while (param_1 + iVar5 + (2 - (int)param_2) != (byte *)0x0);
        }
      }
    }
    if (__stack_chk_guard - local_28 == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  case 0x61:
    bVar11 = pbVar12[1];
    if (bVar11 < 100) {
      if (bVar11 == 0x4e) {
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_00222221,2);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
      else if (bVar11 == 0x53) {
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_00222224,1);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
      else {
        if (bVar11 != 0x61) goto switchD_001cd01a_caseD_4d;
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_0022221c,2);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
    }
    else {
      if (0x73 < bVar11) {
        if (bVar11 == 0x74) {
          if (iVar5 < 3) goto switchD_001cd01a_caseD_4d;
          bVar11 = *param_1;
          bVar34 = bVar11 == 0x61;
          if (bVar34) {
            bVar11 = param_1[1];
          }
          if (!bVar34 || bVar11 != 0x74) goto switchD_001cd01a_caseD_4d;
          param_1 = param_1 + 2;
          pbVar12 = (byte *)FUN_001c6af0(param_1,param_2,param_3);
          bVar34 = pbVar12 != param_1;
          if (bVar34) {
            pbVar12 = (byte *)*param_3;
            pbVar31 = (byte *)param_3[1];
          }
          if (!bVar34 || pbVar12 == pbVar31) goto switchD_001cd01a_caseD_4d;
          uVar20 = *(uint *)(pbVar31 + -8);
          pbVar12 = *(byte **)(pbVar31 + -4);
          puVar9 = (uint *)(pbVar31 + -0x18);
          if ((pbVar31[-0xc] & 1) == 0) {
            pbVar12 = pbVar31 + -0xb;
            uVar20 = (uint)(pbVar31[-0xc] >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(puVar9,pbVar12,uVar20);
          local_38 = (byte *)*puVar10;
          local_34 = puVar10[1];
          local_30 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          ppbVar6 = (byte **)FUN_001caf2a(&local_38,0,"alignof (",9);
          local_50 = *ppbVar6;
          local_4c = ppbVar6[1];
          local_48 = ppbVar6[2];
          ppbVar22 = &local_44;
        }
        else {
          if ((bVar11 != 0x7a) || (iVar5 < 3)) goto switchD_001cd01a_caseD_4d;
          bVar11 = *param_1;
          bVar34 = bVar11 == 0x61;
          if (bVar34) {
            bVar11 = param_1[1];
          }
          if (!bVar34 || bVar11 != 0x7a) goto switchD_001cd01a_caseD_4d;
          param_1 = param_1 + 2;
          pbVar12 = (byte *)FUN_001ccfb8(param_1,param_2,param_3);
          bVar34 = pbVar12 != param_1;
          if (bVar34) {
            pbVar12 = (byte *)*param_3;
            pbVar31 = (byte *)param_3[1];
          }
          if (!bVar34 || pbVar12 == pbVar31) goto switchD_001cd01a_caseD_4d;
          uVar20 = *(uint *)(pbVar31 + -8);
          pbVar12 = *(byte **)(pbVar31 + -4);
          puVar9 = (uint *)(pbVar31 + -0x18);
          if ((pbVar31[-0xc] & 1) == 0) {
            pbVar12 = pbVar31 + -0xb;
            uVar20 = (uint)(pbVar31[-0xc] >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(puVar9,pbVar12,uVar20);
          local_38 = (byte *)*puVar10;
          local_34 = puVar10[1];
          local_30 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          ppbVar6 = (byte **)FUN_001caf2a(&local_38,0,"alignof (",9);
          local_50 = *ppbVar6;
          local_4c = ppbVar6[1];
          local_48 = ppbVar6[2];
          ppbVar22 = ppbVar6;
        }
        *ppbVar6 = (byte *)0x0;
        ppbVar6[1] = (byte *)0x0;
        ppbVar6[2] = (byte *)0x0;
        pbVar12 = (byte *)FUN_001cb080(&local_50,&DAT_0022045d,1,ppbVar22);
        bVar11 = *pbVar12;
        __aeabi_memcpy(&local_60,pbVar12 + 1,7);
        uVar19 = *(undefined4 *)(pbVar12 + 8);
        pbVar12[0] = 0;
        pbVar12[1] = 0;
        pbVar12[2] = 0;
        pbVar12[3] = 0;
        pbVar12[4] = 0;
        pbVar12[5] = 0;
        pbVar12[6] = 0;
        pbVar12[7] = 0;
        pbVar12[8] = 0;
        pbVar12[9] = 0;
        pbVar12[10] = 0;
        pbVar12[0xb] = 0;
        if ((pbVar31[-0x18] & 1) == 0) {
          pbVar31[-0xffffffff00000018] = 0;
          pbVar31[-0xffffffff00000017] = 0;
        }
        else {
          pbVar12 = pbVar31 + -0x10;
          **(undefined1 **)pbVar12 = 0;
          pbVar31[-0xffffffff00000014] = 0;
          pbVar31[-0xffffffff00000013] = 0;
          pbVar31[-0xffffffff00000012] = 0;
          pbVar31[-0xffffffff00000011] = 0;
          uVar20 = (uint)pbVar31[-0x18];
          if ((pbVar31[-0x18] & 1) == 0) {
            uVar23 = 10;
          }
          else {
            uVar20 = *puVar9;
            uVar23 = (uVar20 & 0xfffffffe) - 1;
          }
          if ((uVar20 & 1) == 0) {
            local_e8 = (uVar20 & 0xff) >> 1;
            if ((uVar20 & 0xff) < 0x16) {
              uVar13 = 10;
            }
            else {
              uVar13 = (local_e8 + 0x10 & 0xf0) - 1;
            }
            bVar34 = true;
          }
          else {
            uVar13 = 10;
            local_e8 = 0;
            bVar34 = false;
          }
          if (uVar13 != uVar23) {
            if (uVar13 == 10) {
              pbVar12 = *(byte **)pbVar12;
              if (bVar34) {
                __aeabi_memcpy((byte *)((int)puVar9 + 1),pbVar12,((uVar20 & 0xfe) >> 1) + 1);
              }
              else {
                *(byte *)((int)puVar9 + 1) = *pbVar12;
              }
              free(pbVar12);
              *(byte *)puVar9 = (byte)(local_e8 << 1);
            }
            else {
              puVar26 = malloc(uVar13 + 1);
              if ((uVar23 < uVar13) || (puVar26 != (undefined1 *)0x0)) {
                if (bVar34) {
                  __aeabi_memcpy(puVar26,(byte *)((int)puVar9 + 1),((uVar20 & 0xfe) >> 1) + 1);
                }
                else {
                  puVar7 = *(undefined1 **)pbVar12;
                  *puVar26 = *puVar7;
                  free(puVar7);
                }
                *(uint *)(pbVar31 + -0x18) = uVar13 + 1 | 1;
                *(uint *)(pbVar31 + -0x14) = local_e8;
                *(undefined1 **)(pbVar31 + -0x10) = puVar26;
              }
            }
          }
        }
        pbVar31[-0x18] = bVar11;
        __aeabi_memcpy(pbVar31 + -0x17,&local_60,7);
        *(undefined4 *)(pbVar31 + -0x10) = uVar19;
        local_5c = (uint)local_5c._3_1_ << 0x18;
        local_60 = (byte *)0x0;
        pbVar12 = local_30;
        pbVar33 = local_38;
        if (((uint)local_50 & 1) != 0) {
          free(local_48);
          pbVar12 = local_30;
          pbVar33 = local_38;
        }
        goto joined_r0x001cf88c;
      }
      if (bVar11 == 100) {
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_0022221f,1);
        FUN_001d2150(param_1 + 2,param_2,&local_50,param_3);
      }
      else {
        if (bVar11 != 0x6e) goto switchD_001cd01a_caseD_4d;
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_0022221f,1);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
    }
    break;
  case 99:
    bVar11 = pbVar12[1];
    if (bVar11 < 0x6d) {
      if (bVar11 != 99) {
        if ((bVar11 == 0x6c) && (3 < iVar5)) {
          bVar11 = *param_1;
          bVar34 = bVar11 == 99;
          if (bVar34) {
            bVar11 = param_1[1];
          }
          if (bVar34 && bVar11 == 0x6c) {
            uVar36 = FUN_001ccfb8(param_1 + 2,param_2,param_3);
            pbVar12 = (byte *)uVar36;
            if (pbVar12 != param_1 + 2) {
              if (pbVar12 != param_2) {
                uVar36 = CONCAT44(*param_3,param_3[1]);
                local_e0 = pbVar12;
              }
              iVar5 = (int)uVar36;
              if (pbVar12 != param_2 && (int)((ulonglong)uVar36 >> 0x20) != iVar5) {
                uVar20 = *(uint *)(iVar5 + -8);
                iVar17 = *(int *)(iVar5 + -4);
                if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                  iVar17 = iVar5 + -0xb;
                  uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                }
                FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                iVar5 = param_3[1];
                local_4c = (byte *)((uint)local_4c & 0xff000000);
                local_50 = (byte *)0x0;
                puVar9 = (uint *)(iVar5 + -0xc);
                if ((*(byte *)puVar9 & 1) == 0) {
                  *(undefined2 *)(iVar5 + -0xc) = 0;
                }
                else {
                  puVar10 = (undefined4 *)(iVar5 + -4);
                  *(undefined1 *)*puVar10 = 0;
                  *(undefined4 *)(iVar5 + -8) = 0;
                  uVar20 = (uint)*(byte *)(iVar5 + -0xc);
                  if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                    uVar23 = 10;
                  }
                  else {
                    uVar20 = *puVar9;
                    uVar23 = (uVar20 & 0xfffffffe) - 1;
                  }
                  if ((uVar20 & 1) == 0) {
                    local_ec = (uVar20 & 0xff) >> 1;
                    if ((uVar20 & 0xff) < 0x16) {
                      uVar13 = 10;
                    }
                    else {
                      uVar13 = (local_ec + 0x10 & 0xf0) - 1;
                    }
                    bVar34 = true;
                  }
                  else {
                    uVar13 = 10;
                    local_ec = 0;
                    bVar34 = false;
                  }
                  if (uVar13 != uVar23) {
                    if (uVar13 == 10) {
                      puVar26 = (undefined1 *)*puVar10;
                      if (bVar34) {
                        __aeabi_memcpy((undefined1 *)(iVar5 + -0xb),puVar26,
                                       ((uVar20 & 0xfe) >> 1) + 1);
                      }
                      else {
                        *(undefined1 *)(iVar5 + -0xb) = *puVar26;
                      }
                      free(puVar26);
                      *(byte *)puVar9 = (byte)(local_ec << 1);
                    }
                    else {
                      puVar26 = malloc(uVar13 + 1);
                      if ((uVar23 < uVar13) || (puVar26 != (undefined1 *)0x0)) {
                        if (bVar34) {
                          __aeabi_memcpy(puVar26,iVar5 + -0xb,((uVar20 & 0xfe) >> 1) + 1);
                        }
                        else {
                          puVar7 = (undefined1 *)*puVar10;
                          *puVar26 = *puVar7;
                          free(puVar7);
                        }
                        *(uint *)(iVar5 + -0xc) = uVar13 + 1 | 1;
                        *(uint *)(iVar5 + -8) = local_ec;
                        *(undefined1 **)(iVar5 + -4) = puVar26;
                      }
                    }
                  }
                }
                *(undefined1 *)(iVar5 + -0xc) = 0;
                __aeabi_memcpy(iVar5 + -0xb,&local_50,7);
                *(undefined4 *)(iVar5 + -4) = 0;
                FUN_001cb080(param_3[1] + -0x18,&DAT_00222248,1);
                do {
                  if (*local_e0 == 0x45) {
                    if (*param_3 != param_3[1]) {
                      FUN_001cb080(param_3[1] + -0x18,&DAT_0022045d,1);
                    }
                    break;
                  }
                  uVar36 = FUN_001ccfb8(local_e0,param_2,param_3);
                  pbVar12 = (byte *)uVar36;
                  if (pbVar12 == local_e0) break;
                  if (pbVar12 != param_2) {
                    uVar36 = CONCAT44(*param_3,param_3[1]);
                  }
                  iVar5 = (int)uVar36;
                  if (pbVar12 == param_2 || (int)((ulonglong)uVar36 >> 0x20) == iVar5) break;
                  uVar20 = *(uint *)(iVar5 + -8);
                  iVar17 = *(int *)(iVar5 + -4);
                  if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                    iVar17 = iVar5 + -0xb;
                    uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                  }
                  puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                  local_50 = (byte *)*puVar10;
                  local_4c = (byte *)puVar10[1];
                  local_48 = (byte *)puVar10[2];
                  *puVar10 = 0;
                  puVar10[1] = 0;
                  puVar10[2] = 0;
                  iVar17 = param_3[1];
                  iVar5 = iVar17;
                  do {
                    param_3[1] = iVar5 + -0x18;
                    if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                      free(*(void **)(iVar5 + -4));
                    }
                    if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                      free(*(void **)(iVar5 + -0x10));
                    }
                    iVar5 = param_3[1];
                  } while (iVar5 != iVar17 + -0x18);
                  uVar20 = (uint)local_50 & 1;
                  pbVar33 = local_4c;
                  if (((uint)local_50 & 1) == 0) {
                    pbVar33 = (byte *)((uint)local_50 >> 1 & 0x7f);
                  }
                  if (pbVar33 == (byte *)0x0) {
LAB_001d0c38:
                    bVar34 = false;
                    local_e0 = pbVar12;
                  }
                  else {
                    if (*param_3 != iVar17 + -0x18) {
                      pbVar33 = local_48;
                      if (((uint)local_50 & 1) == 0) {
                        pbVar33 = (byte *)((uint)&local_50 | 1);
                      }
                      FUN_001cb080(iVar17 + -0x30,pbVar33);
                      goto LAB_001d0c38;
                    }
                    bVar34 = true;
                  }
                  if (uVar20 != 0) {
                    free(local_48);
                  }
                } while (!bVar34);
              }
            }
          }
        }
        goto switchD_001cd01a_caseD_4d;
      }
      if (iVar5 < 3) goto switchD_001cd01a_caseD_4d;
      bVar11 = *param_1;
      bVar34 = bVar11 == 99;
      if (bVar34) {
        bVar11 = param_1[1];
      }
      if ((((!bVar34 || bVar11 != 99) ||
           (pbVar12 = (byte *)FUN_001c6af0(param_1 + 2,param_2,param_3), pbVar12 == param_1 + 2)) ||
          (pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3), pbVar33 == pbVar12)) ||
         (iVar5 = param_3[1], (uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2))
      goto switchD_001cd01a_caseD_4d;
      uVar20 = *(uint *)(iVar5 + -8);
      iVar17 = *(int *)(iVar5 + -4);
      if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
        iVar17 = iVar5 + -0xb;
        uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
      }
      puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
      local_38 = (byte *)*puVar10;
      local_34 = puVar10[1];
      local_30 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      local_e4 = param_3[1];
      iVar5 = local_e4;
      do {
        param_3[1] = iVar5 + -0x18;
        if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
          free(*(void **)(iVar5 + -4));
        }
        if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
          free(*(void **)(iVar5 + -0x10));
        }
        iVar5 = param_3[1];
      } while (iVar5 != local_e4 + -0x18);
      pbVar12 = local_38;
      if (*param_3 != local_e4 + -0x18) {
        uVar20 = *(uint *)(local_e4 + -0x20);
        iVar5 = *(int *)(local_e4 + -0x1c);
        if ((*(byte *)(local_e4 + -0x24) & 1) == 0) {
          iVar5 = local_e4 + -0x23;
          uVar20 = (uint)(*(byte *)(local_e4 + -0x24) >> 1);
        }
        local_e4 = local_e4 + -0x30;
        puVar10 = (undefined4 *)FUN_001cb080(local_e4,iVar5,uVar20);
        local_90 = (byte *)*puVar10;
        local_8c = puVar10[1];
        local_88 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar9 = (uint *)FUN_001caf2a(&local_90,0,"const_cast<",0xb);
        local_80 = *puVar9;
        local_7c = puVar9[1];
        local_78 = (void *)puVar9[2];
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = 0;
        puVar9 = (uint *)FUN_001cb080(&local_80,&DAT_002222eb,2,&local_74);
        pbVar12 = local_38;
        local_70 = (byte *)*puVar9;
        local_6c = puVar9[1];
        local_68 = (void *)puVar9[2];
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = 0;
        uVar20 = local_34;
        pbVar33 = local_30;
        if (((uint)local_38 & 1) == 0) {
          pbVar33 = (byte *)((uint)&local_38 | 1);
          uVar20 = (uint)local_38 >> 1 & 0x7f;
        }
        puVar10 = (undefined4 *)FUN_001cb080(&local_70,pbVar33,uVar20);
LAB_001ce782:
        local_60 = (byte *)*puVar10;
        local_5c = puVar10[1];
        local_58 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001cb080(&local_60,&DAT_0022045d,1,&pbStack_54);
        uVar1 = *(undefined1 *)puVar10;
        __aeabi_memcpy(&local_c0,(int)puVar10 + 1,7);
        pbVar33 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
        __aeabi_memcpy((uint)&local_50 | 1,&local_c0,7);
        local_bc = (uint)local_bc._3_1_ << 0x18;
        local_c0 = 0;
        local_3c = (void *)0x0;
        local_44 = (byte *)0x0;
        local_40 = 0;
        local_48 = pbVar33;
        FUN_001d0d6c(local_e4,&local_50);
        if (((uint)local_44 & 1) != 0) {
          free(local_3c);
        }
        if (((uint)local_50 & 1) != 0) {
          free(local_48);
        }
        if (((uint)local_60 & 1) != 0) {
          free(local_58);
        }
        if (((uint)local_70 & 1) != 0) {
          free(local_68);
        }
        if ((local_80 & 1) != 0) {
          free(local_78);
        }
        if (((uint)local_90 & 1) != 0) {
          free(local_88);
        }
      }
LAB_001cfdca:
      if (((uint)pbVar12 & 1) != 0) {
        free(local_30);
      }
      goto switchD_001cd01a_caseD_4d;
    }
    if (bVar11 == 0x6d) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0021f9ef,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else {
      if (bVar11 != 0x6f) {
        if ((bVar11 != 0x76) || (iVar5 < 3)) goto switchD_001cd01a_caseD_4d;
        bVar11 = *param_1;
        bVar34 = bVar11 == 99;
        if (bVar34) {
          bVar11 = param_1[1];
        }
        if (!bVar34 || bVar11 != 0x76) goto switchD_001cd01a_caseD_4d;
        uVar1 = *(undefined1 *)((int)param_3 + 0x3f);
        *(undefined1 *)((int)param_3 + 0x3f) = 0;
        pbVar12 = (byte *)FUN_001c6af0(param_1 + 2,param_2,param_3);
        *(undefined1 *)((int)param_3 + 0x3f) = uVar1;
        if (pbVar12 == param_1 + 2 || pbVar12 == param_2) goto switchD_001cd01a_caseD_4d;
        if (*pbVar12 == 0x5f) {
          pbVar12 = pbVar12 + 1;
          if (pbVar12 == param_2) goto switchD_001cd01a_caseD_4d;
          if (*pbVar12 == 0x45) {
            uVar20 = param_3[1];
            if (uVar20 < (uint)param_3[2]) {
              __aeabi_memclr4(uVar20,0x18);
              param_3[1] = param_3[1] + 0x18;
            }
            else {
              iVar17 = ((int)(uVar20 - *param_3) >> 3) * -0x55555555;
              iVar5 = param_3[2] - *param_3 >> 3;
              if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
                pbVar12 = (byte *)(iVar17 + 1);
                pbVar31 = (byte *)(iVar5 * 0x55555556);
                if (pbVar31 < pbVar12) {
                  pbVar31 = pbVar12;
                }
              }
              FUN_001ccdd4(&local_50,pbVar31,iVar17,param_3 + 3);
              __aeabi_memclr4(local_48,0x18);
              local_48 = local_48 + 0x18;
              FUN_001cce32(param_3,&local_50);
              FUN_001cceae(&local_50);
            }
          }
          else {
            do {
              pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3);
              if (pbVar33 == param_2 || pbVar33 == pbVar12) goto switchD_001cd01a_caseD_4d;
              pbVar12 = pbVar33;
            } while (*pbVar33 != 0x45);
          }
        }
        else {
          pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3);
          if (pbVar33 == pbVar12) goto switchD_001cd01a_caseD_4d;
        }
        iVar5 = param_3[1];
        if ((uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2) goto switchD_001cd01a_caseD_4d;
        uVar20 = *(uint *)(iVar5 + -8);
        iVar17 = *(int *)(iVar5 + -4);
        if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
          iVar17 = iVar5 + -0xb;
          uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
        local_38 = (byte *)*puVar10;
        local_34 = puVar10[1];
        local_30 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        iVar17 = param_3[1];
        iVar5 = iVar17;
        do {
          param_3[1] = iVar5 + -0x18;
          if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
            free(*(void **)(iVar5 + -4));
          }
          if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
            free(*(void **)(iVar5 + -0x10));
          }
          iVar5 = param_3[1];
        } while (iVar5 != iVar17 + -0x18);
        uVar20 = *(uint *)(iVar17 + -0x20);
        iVar5 = *(int *)(iVar17 + -0x1c);
        if ((*(byte *)(iVar17 + -0x24) & 1) == 0) {
          iVar5 = iVar17 + -0x23;
          uVar20 = (uint)(*(byte *)(iVar17 + -0x24) >> 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(iVar17 + -0x30,iVar5,uVar20);
        local_90 = (byte *)*puVar10;
        local_8c = puVar10[1];
        local_88 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar9 = (uint *)FUN_001caf2a(&local_90,0,&DAT_00222248,1);
        local_80 = *puVar9;
        local_7c = puVar9[1];
        local_78 = (void *)puVar9[2];
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = 0;
        puVar9 = (uint *)FUN_001cb080(&local_80,&DAT_002222ee,2,&local_74);
        pbVar12 = local_30;
        pbVar33 = local_38;
        local_70 = (byte *)*puVar9;
        local_6c = puVar9[1];
        local_68 = (void *)puVar9[2];
        *puVar9 = 0;
        puVar9[1] = 0;
        puVar9[2] = 0;
        uVar20 = local_34;
        pbVar31 = local_30;
        if (((uint)local_38 & 1) == 0) {
          pbVar31 = (byte *)((uint)&local_38 | 1);
          uVar20 = (uint)local_38 >> 1 & 0x7f;
        }
        puVar10 = (undefined4 *)FUN_001cb080(&local_70,pbVar31,uVar20);
        local_60 = (byte *)*puVar10;
        local_5c = puVar10[1];
        local_58 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001cb080(&local_60,&DAT_0022045d,1);
        uVar1 = *(undefined1 *)puVar10;
        __aeabi_memcpy(&local_c0,(int)puVar10 + 1,7);
        pbVar31 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
        __aeabi_memcpy((uint)&local_50 | 1,&local_c0,7);
        local_bc = (uint)local_bc._3_1_ << 0x18;
        local_c0 = 0;
        local_3c = (void *)0x0;
        local_44 = (byte *)0x0;
        local_40 = 0;
        local_48 = pbVar31;
        FUN_001d0d6c(iVar17 + -0x30,&local_50);
        if (((uint)local_44 & 1) != 0) {
          free(local_3c);
        }
        if (((uint)local_50 & 1) != 0) {
          free(local_48);
        }
        if (((uint)local_60 & 1) != 0) {
          free(local_58);
        }
        if (((uint)local_70 & 1) != 0) {
          free(local_68);
        }
        if ((local_80 & 1) != 0) {
          free(local_78);
        }
        if (((uint)local_90 & 1) != 0) {
          free(local_88);
        }
        goto joined_r0x001cf88c;
      }
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222226,1);
      FUN_001d2150(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 100:
    bVar11 = pbVar12[1];
    if (bVar11 < 0x65) {
      if (bVar11 != 0x56) {
        if (bVar11 != 0x61) {
          if ((bVar11 != 99) || (iVar5 < 3)) goto switchD_001cd01a_caseD_4d;
          bVar11 = *param_1;
          bVar34 = bVar11 == 100;
          if (bVar34) {
            bVar11 = param_1[1];
          }
          if ((((!bVar34 || bVar11 != 99) ||
               (pbVar12 = (byte *)FUN_001c6af0(param_1 + 2,param_2,param_3), pbVar12 == param_1 + 2)
               ) || (pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3), pbVar33 == pbVar12))
             || (iVar5 = param_3[1], (uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2))
          goto switchD_001cd01a_caseD_4d;
          uVar20 = *(uint *)(iVar5 + -8);
          iVar17 = *(int *)(iVar5 + -4);
          if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
            iVar17 = iVar5 + -0xb;
            uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
          local_38 = (byte *)*puVar10;
          local_34 = puVar10[1];
          local_30 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          local_e4 = param_3[1];
          iVar5 = local_e4;
          do {
            param_3[1] = iVar5 + -0x18;
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = param_3[1];
          } while (iVar5 != local_e4 + -0x18);
          pbVar12 = local_38;
          if (*param_3 != local_e4 + -0x18) {
            uVar20 = *(uint *)(local_e4 + -0x20);
            iVar5 = *(int *)(local_e4 + -0x1c);
            if ((*(byte *)(local_e4 + -0x24) & 1) == 0) {
              iVar5 = local_e4 + -0x23;
              uVar20 = (uint)(*(byte *)(local_e4 + -0x24) >> 1);
            }
            local_e4 = local_e4 + -0x30;
            puVar10 = (undefined4 *)FUN_001cb080(local_e4,iVar5,uVar20);
            local_90 = (byte *)*puVar10;
            local_8c = puVar10[1];
            local_88 = (byte *)puVar10[2];
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            puVar9 = (uint *)FUN_001caf2a(&local_90,0,"dynamic_cast<",0xd);
            local_80 = *puVar9;
            local_7c = puVar9[1];
            local_78 = (void *)puVar9[2];
            *puVar9 = 0;
            puVar9[1] = 0;
            puVar9[2] = 0;
            puVar9 = (uint *)FUN_001cb080(&local_80,&DAT_002222eb,2,&local_74);
            pbVar12 = local_38;
            local_70 = (byte *)*puVar9;
            local_6c = puVar9[1];
            local_68 = (void *)puVar9[2];
            *puVar9 = 0;
            puVar9[1] = 0;
            puVar9[2] = 0;
            uVar20 = local_34;
            pbVar33 = local_30;
            if (((uint)local_38 & 1) == 0) {
              pbVar33 = (byte *)((uint)&local_38 | 1);
              uVar20 = (uint)local_38 >> 1 & 0x7f;
            }
            puVar10 = (undefined4 *)FUN_001cb080(&local_70,pbVar33,uVar20);
            goto LAB_001ce782;
          }
          goto LAB_001cfdca;
        }
        pbVar12 = pbVar12 + 2;
        pbVar31 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3);
        bVar35 = pbVar31 != pbVar12;
        if (bVar35) {
          pbVar31 = (byte *)*param_3;
          pbVar33 = (byte *)param_3[1];
        }
        if (!bVar35 || pbVar31 == pbVar33) goto switchD_001cd01a_caseD_4d;
        puVar9 = (uint *)(pbVar33 + -0x18);
        if (bVar34) {
          local_30 = (byte *)0x0;
          local_38 = (byte *)0x0;
          local_34 = 0;
          FUN_001c5e62(&local_38,&DAT_0022220f,2);
        }
        else {
          local_30 = (byte *)0x0;
          local_38 = (byte *)0x0;
          local_34 = 0;
        }
        puVar10 = (undefined4 *)FUN_001cb080(&local_38,"delete[] ",9);
        local_50 = (byte *)*puVar10;
        local_4c = (byte *)puVar10[1];
        local_48 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        iVar17 = param_3[1];
        uVar20 = *(uint *)(iVar17 + -8);
        iVar5 = *(int *)(iVar17 + -4);
        if ((*(byte *)(iVar17 + -0xc) & 1) == 0) {
          iVar5 = iVar17 + -0xb;
          uVar20 = (uint)(*(byte *)(iVar17 + -0xc) >> 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(iVar17 + -0x18,iVar5,uVar20);
        pbVar27 = (byte *)*puVar10;
        local_5c = puVar10[1];
        pbVar31 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        uVar20 = local_5c;
        pbVar12 = pbVar31;
        if (((uint)pbVar27 & 1) == 0) {
          pbVar12 = (byte *)((uint)&local_60 | 1);
          uVar20 = (uint)pbVar27 >> 1 & 0x7f;
        }
        local_60 = pbVar27;
        local_58 = pbVar31;
        pbVar12 = (byte *)FUN_001cb080(&local_50,pbVar12,uVar20);
        bVar11 = *pbVar12;
        __aeabi_memcpy(&local_70,pbVar12 + 1,7);
        uVar19 = *(undefined4 *)(pbVar12 + 8);
        pbVar12[0] = 0;
        pbVar12[1] = 0;
        pbVar12[2] = 0;
        pbVar12[3] = 0;
        pbVar12[4] = 0;
        pbVar12[5] = 0;
        pbVar12[6] = 0;
        pbVar12[7] = 0;
        pbVar12[8] = 0;
        pbVar12[9] = 0;
        pbVar12[10] = 0;
        pbVar12[0xb] = 0;
        if ((*puVar9 & 1) == 0) {
          pbVar33[-0xffffffff00000018] = 0;
          pbVar33[-0xffffffff00000017] = 0;
        }
        else {
          pbVar12 = pbVar33 + -0x10;
          **(undefined1 **)pbVar12 = 0;
          pbVar33[-0xffffffff00000014] = 0;
          pbVar33[-0xffffffff00000013] = 0;
          pbVar33[-0xffffffff00000012] = 0;
          pbVar33[-0xffffffff00000011] = 0;
          uVar20 = (uint)pbVar33[-0x18];
          if ((pbVar33[-0x18] & 1) == 0) {
            uVar23 = 10;
          }
          else {
            uVar20 = *puVar9;
            uVar23 = (uVar20 & 0xfffffffe) - 1;
          }
          if ((uVar20 & 1) == 0) {
            uVar13 = (uVar20 & 0xff) >> 1;
            if ((uVar20 & 0xff) < 0x16) {
              uVar28 = 10;
            }
            else {
              uVar28 = (uVar13 + 0x10 & 0xf0) - 1;
            }
            bVar34 = true;
          }
          else {
            uVar28 = 10;
            uVar13 = 0;
            bVar34 = false;
          }
          if (uVar28 != uVar23) {
            if (uVar28 == 10) {
              pbVar12 = *(byte **)pbVar12;
              if (bVar34) {
                __aeabi_memcpy(pbVar33 + -0x17,pbVar12,((uVar20 & 0xfe) >> 1) + 1);
              }
              else {
                pbVar33[-0x17] = *pbVar12;
              }
              free(pbVar12);
              *(byte *)puVar9 = (byte)(uVar13 << 1);
            }
            else {
              puVar26 = malloc(uVar28 + 1);
              if ((uVar23 < uVar28) || (puVar26 != (undefined1 *)0x0)) {
                if (bVar34) {
                  __aeabi_memcpy(puVar26,pbVar33 + -0x17,((uVar20 & 0xfe) >> 1) + 1);
                }
                else {
                  puVar7 = *(undefined1 **)pbVar12;
                  *puVar26 = *puVar7;
                  free(puVar7);
                }
                *(uint *)(pbVar33 + -0x18) = uVar28 + 1 | 1;
                *(uint *)(pbVar33 + -0x14) = uVar13;
                *(undefined1 **)(pbVar33 + -0x10) = puVar26;
              }
            }
          }
        }
        pbVar33[-0x18] = bVar11;
        __aeabi_memcpy(pbVar33 + -0x17,&local_70,7);
        *(undefined4 *)(pbVar33 + -0x10) = uVar19;
        goto joined_r0x001cff84;
      }
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0022223a,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      break;
    }
    switch(bVar11) {
    case 0x6c:
      pbVar12 = pbVar12 + 2;
      pbVar31 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3);
      bVar35 = pbVar31 != pbVar12;
      if (bVar35) {
        pbVar31 = (byte *)*param_3;
        pbVar33 = (byte *)param_3[1];
      }
      if (!bVar35 || pbVar31 == pbVar33) break;
      puVar9 = (uint *)(pbVar33 + -0x18);
      if (bVar34) {
        local_30 = (byte *)0x0;
        local_38 = (byte *)0x0;
        local_34 = 0;
        FUN_001c5e62(&local_38,&DAT_0022220f,2);
      }
      else {
        local_30 = (byte *)0x0;
        local_38 = (byte *)0x0;
        local_34 = 0;
      }
      puVar10 = (undefined4 *)FUN_001cb080(&local_38,"delete ",7);
      local_50 = (byte *)*puVar10;
      local_4c = (byte *)puVar10[1];
      local_48 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      iVar17 = param_3[1];
      uVar20 = *(uint *)(iVar17 + -8);
      iVar5 = *(int *)(iVar17 + -4);
      if ((*(byte *)(iVar17 + -0xc) & 1) == 0) {
        iVar5 = iVar17 + -0xb;
        uVar20 = (uint)(*(byte *)(iVar17 + -0xc) >> 1);
      }
      puVar10 = (undefined4 *)FUN_001cb080(iVar17 + -0x18,iVar5,uVar20);
      pbVar27 = (byte *)*puVar10;
      local_5c = puVar10[1];
      pbVar31 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      uVar20 = local_5c;
      pbVar12 = pbVar31;
      if (((uint)pbVar27 & 1) == 0) {
        pbVar12 = (byte *)((uint)&local_60 | 1);
        uVar20 = (uint)pbVar27 >> 1 & 0x7f;
      }
      local_60 = pbVar27;
      local_58 = pbVar31;
      pbVar12 = (byte *)FUN_001cb080(&local_50,pbVar12,uVar20);
      bVar11 = *pbVar12;
      __aeabi_memcpy(&local_70,pbVar12 + 1,7);
      uVar19 = *(undefined4 *)(pbVar12 + 8);
      pbVar12[0] = 0;
      pbVar12[1] = 0;
      pbVar12[2] = 0;
      pbVar12[3] = 0;
      pbVar12[4] = 0;
      pbVar12[5] = 0;
      pbVar12[6] = 0;
      pbVar12[7] = 0;
      pbVar12[8] = 0;
      pbVar12[9] = 0;
      pbVar12[10] = 0;
      pbVar12[0xb] = 0;
      if ((*puVar9 & 1) == 0) {
        pbVar33[-0xffffffff00000018] = 0;
        pbVar33[-0xffffffff00000017] = 0;
      }
      else {
        pbVar12 = pbVar33 + -0x10;
        **(undefined1 **)pbVar12 = 0;
        pbVar33[-0xffffffff00000014] = 0;
        pbVar33[-0xffffffff00000013] = 0;
        pbVar33[-0xffffffff00000012] = 0;
        pbVar33[-0xffffffff00000011] = 0;
        uVar20 = (uint)pbVar33[-0x18];
        if ((pbVar33[-0x18] & 1) == 0) {
          uVar23 = 10;
        }
        else {
          uVar20 = *puVar9;
          uVar23 = (uVar20 & 0xfffffffe) - 1;
        }
        if ((uVar20 & 1) == 0) {
          uVar13 = (uVar20 & 0xff) >> 1;
          if ((uVar20 & 0xff) < 0x16) {
            uVar28 = 10;
          }
          else {
            uVar28 = (uVar13 + 0x10 & 0xf0) - 1;
          }
          bVar34 = true;
        }
        else {
          uVar28 = 10;
          uVar13 = 0;
          bVar34 = false;
        }
        if (uVar28 != uVar23) {
          if (uVar28 == 10) {
            pbVar12 = *(byte **)pbVar12;
            if (bVar34) {
              __aeabi_memcpy(pbVar33 + -0x17,pbVar12,((uVar20 & 0xfe) >> 1) + 1);
            }
            else {
              pbVar33[-0x17] = *pbVar12;
            }
            free(pbVar12);
            *(byte *)puVar9 = (byte)(uVar13 << 1);
          }
          else {
            puVar26 = malloc(uVar28 + 1);
            if ((uVar23 < uVar28) || (puVar26 != (undefined1 *)0x0)) {
              if (bVar34) {
                __aeabi_memcpy(puVar26,pbVar33 + -0x17,((uVar20 & 0xfe) >> 1) + 1);
              }
              else {
                puVar7 = *(undefined1 **)pbVar12;
                *puVar26 = *puVar7;
                free(puVar7);
              }
              *(uint *)(pbVar33 + -0x18) = uVar28 + 1 | 1;
              *(uint *)(pbVar33 + -0x14) = uVar13;
              *(undefined1 **)(pbVar33 + -0x10) = puVar26;
            }
          }
        }
      }
      pbVar33[-0x18] = bVar11;
      __aeabi_memcpy(pbVar33 + -0x17,&local_70,7);
      *(undefined4 *)(pbVar33 + -0x10) = uVar19;
joined_r0x001cff84:
      local_6c = (uint)local_6c._3_1_ << 0x18;
      local_70 = (byte *)0x0;
      if (((uint)pbVar27 & 1) != 0) {
        local_70 = (byte *)0x0;
        free(pbVar31);
      }
      if (((uint)local_50 & 1) != 0) {
        free(local_48);
      }
      if (((uint)local_38 & 1) != 0) {
        free(local_30);
      }
      break;
    case 0x6d:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x75:
      break;
    case 0x6e:
      goto code_r0x001d23a4;
    case 0x73:
      if (2 < iVar5) {
        bVar11 = *param_1;
        bVar34 = bVar11 == 100;
        if (bVar34) {
          bVar11 = param_1[1];
        }
        if ((((bVar34 && bVar11 == 0x73) &&
             (pbVar12 = (byte *)FUN_001ccfb8(param_1 + 2,param_2,param_3), pbVar12 != param_1 + 2))
            && (pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3), pbVar33 != pbVar12)) &&
           (iVar5 = param_3[1], 1 < (uint)((iVar5 - *param_3 >> 3) * -0x55555555))) {
          uVar20 = *(uint *)(iVar5 + -8);
          iVar17 = *(int *)(iVar5 + -4);
          if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
            iVar17 = iVar5 + -0xb;
            uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
          local_50 = (byte *)*puVar10;
          local_4c = (byte *)puVar10[1];
          local_48 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          iVar17 = param_3[1];
          iVar5 = iVar17;
          do {
            param_3[1] = iVar5 + -0x18;
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = param_3[1];
          } while (iVar5 != iVar17 + -0x18);
          FUN_001cbc00(&local_38,&DAT_00222326,&local_50);
          uVar20 = local_34;
          pbVar12 = local_30;
          if (((uint)local_38 & 1) == 0) {
            pbVar12 = (byte *)((uint)&local_38 | 1);
            uVar20 = (uint)local_38 >> 1 & 0x7f;
          }
          FUN_001cb080(iVar17 + -0x30,pbVar12,uVar20);
          if (((uint)local_38 & 1) != 0) {
            free(local_30);
          }
          if (((uint)local_50 & 1) != 0) {
            free(local_48);
          }
        }
      }
      break;
    case 0x74:
      if (2 < iVar5) {
        bVar11 = *param_1;
        bVar34 = bVar11 == 100;
        if (bVar34) {
          bVar11 = param_1[1];
        }
        if (((bVar34 && bVar11 == 0x74) &&
            (pbVar12 = (byte *)FUN_001ccfb8(param_1 + 2,param_2,param_3), pbVar12 != param_1 + 2))
           && ((pbVar33 = (byte *)FUN_001d23a4(pbVar12,param_2,param_3), pbVar33 != pbVar12 &&
               (iVar5 = param_3[1], 1 < (uint)((iVar5 - *param_3 >> 3) * -0x55555555))))) {
          uVar20 = *(uint *)(iVar5 + -8);
          iVar17 = *(int *)(iVar5 + -4);
          if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
            iVar17 = iVar5 + -0xb;
            uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
          local_50 = (byte *)*puVar10;
          local_4c = (byte *)puVar10[1];
          local_48 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          iVar17 = param_3[1];
          iVar5 = iVar17;
          do {
            param_3[1] = iVar5 + -0x18;
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = param_3[1];
          } while (iVar5 != iVar17 + -0x18);
          if (*param_3 != iVar17 + -0x18) {
            FUN_001cbc00(&local_38,&DAT_0021f777,&local_50);
            uVar20 = local_34;
            pbVar12 = local_30;
            if (((uint)local_38 & 1) == 0) {
              pbVar12 = (byte *)((uint)&local_38 | 1);
              uVar20 = (uint)local_38 >> 1 & 0x7f;
            }
            FUN_001cb080(iVar17 + -0x30,pbVar12,uVar20);
            if (((uint)local_38 & 1) != 0) {
              free(local_30);
            }
          }
          if (((uint)local_50 & 1) != 0) {
            free(local_48);
          }
        }
      }
      break;
    case 0x76:
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0021f770,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      goto LAB_001cf676;
    default:
      if (bVar11 != 0x65) break;
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0021f89d,1);
      FUN_001d2150(param_1 + 2,param_2,&local_50,param_3);
      goto LAB_001cf676;
    }
    goto switchD_001cd01a_caseD_4d;
  case 0x65:
    bVar11 = pbVar12[1];
    if (bVar11 == 0x4f) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0022223f,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else if (bVar11 == 0x71) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222242,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else {
      if (bVar11 != 0x6f) goto switchD_001cd01a_caseD_4d;
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0022223d,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x66:
    if (((int)param_2 - (int)param_1 < 3) || (*param_1 != 0x66)) goto LAB_001d1dc2;
    if (param_1[1] == 0x4c) {
      pbVar12 = (byte *)FUN_001caeea(param_1 + 2,param_2);
      if ((pbVar12 == param_2) || (*pbVar12 != 0x70)) goto LAB_001d1dc2;
      pbVar33 = pbVar12 + 1;
      pbVar31 = param_2;
      if (pbVar33 != param_2) {
        bVar11 = *pbVar33;
        if (bVar11 == 0x72) {
          pbVar33 = pbVar12 + 2;
          bVar11 = *pbVar33;
        }
        if (bVar11 == 0x56) {
          pbVar33 = pbVar33 + 1;
          bVar11 = *pbVar33;
        }
        pbVar31 = pbVar33;
        if (bVar11 == 0x4b) {
          pbVar31 = pbVar33 + 1;
        }
      }
      pbVar12 = (byte *)FUN_001caeea(pbVar31,param_2);
      if ((pbVar12 == param_2) || (*pbVar12 != 0x5f)) goto LAB_001d1dc2;
      uVar20 = (int)pbVar12 - (int)pbVar31;
      local_60 = (byte *)0x0;
      local_64 = 0;
      if (10 < uVar20) {
        pbVar33 = malloc(uVar20 + 0x10 & 0xfffffff0);
        local_60 = pbVar33;
        local_64 = uVar20;
      }
      else {
                    /* WARNING: Ignoring partial resolution of indirect */
        pbVar33 = (byte *)((uint)&local_68 | 1);
      }
      pbVar27 = pbVar33;
      if (pbVar31 != pbVar12) {
        do {
          pbVar29 = pbVar31 + 1;
          *pbVar27 = *pbVar31;
          pbVar27 = pbVar27 + 1;
          pbVar31 = pbVar29;
        } while (pbVar12 != pbVar29);
        pbVar33 = pbVar33 + uVar20;
      }
      *pbVar33 = 0;
      local_68._0_1_ = 10 < uVar20;
      pbVar12 = (byte *)FUN_001caf2a(&local_68,0,&DAT_002222cf,2);
      bVar11 = *pbVar12;
      __aeabi_memcpy(&local_48,pbVar12 + 1,7);
      local_70 = *(byte **)(pbVar12 + 8);
      pbVar12[0] = 0;
      pbVar12[1] = 0;
      pbVar12[2] = 0;
      pbVar12[3] = 0;
      pbVar12[4] = 0;
      pbVar12[5] = 0;
      pbVar12[6] = 0;
      pbVar12[7] = 0;
      pbVar12[8] = 0;
      pbVar12[9] = 0;
      pbVar12[10] = 0;
      pbVar12[0xb] = 0;
      __aeabi_memcpy(&local_30,&local_48,7);
      pbVar12 = (byte *)param_3[1];
      if ((byte *)param_3[2] <= pbVar12) {
        iVar5 = param_3[2] - *param_3 >> 3;
        iVar17 = ((int)pbVar12 - *param_3 >> 3) * -0x55555555;
        uVar20 = 0xaaaaaaa;
        if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
          uVar23 = iVar17 + 1;
          uVar20 = iVar5 * 0x55555556;
          if (uVar20 < uVar23) {
            uVar20 = uVar23;
          }
        }
        FUN_001ccdd4(&local_5c,uVar20,iVar17,param_3 + 3);
        pbVar12 = pbStack_54;
        *pbStack_54 = bVar11;
        __aeabi_memcpy(pbStack_54 + 1,&local_30,7);
        *(byte **)(pbVar12 + 8) = local_70;
        goto LAB_001d1d74;
      }
      *pbVar12 = bVar11;
      __aeabi_memcpy(pbVar12 + 1,&local_30,7);
      *(byte **)(pbVar12 + 8) = local_70;
      uStack_2c._2_1_ = 0;
      uStack_2c._0_2_ = 0;
      pbVar12[0xc] = 0;
      __aeabi_memcpy(pbVar12 + 0xd,&local_38,7);
      pbVar12[0x14] = 0;
      pbVar12[0x15] = 0;
      pbVar12[0x16] = 0;
      pbVar12[0x17] = 0;
LAB_001d1d18:
      param_3[1] = param_3[1] + 0x18;
    }
    else {
      if (param_1[1] != 0x70) goto LAB_001d1dc2;
      pbVar12 = param_1 + 2;
      pbVar33 = param_2;
      if (pbVar12 != param_2) {
        bVar11 = *pbVar12;
        if (bVar11 == 0x72) {
          pbVar12 = param_1 + 3;
          bVar11 = *pbVar12;
        }
        if (bVar11 == 0x56) {
          pbVar12 = pbVar12 + 1;
          bVar11 = *pbVar12;
        }
        pbVar33 = pbVar12;
        if (bVar11 == 0x4b) {
          pbVar33 = pbVar12 + 1;
        }
      }
      pbVar12 = (byte *)FUN_001caeea(pbVar33,param_2);
      if ((pbVar12 == param_2) || (*pbVar12 != 0x5f)) goto LAB_001d1dc2;
      uVar20 = (int)pbVar12 - (int)pbVar33;
      local_60 = (byte *)0x0;
      local_64 = 0;
      if (10 < uVar20) {
        pbVar31 = malloc(uVar20 + 0x10 & 0xfffffff0);
        local_60 = pbVar31;
        local_64 = uVar20;
      }
      else {
                    /* WARNING: Ignoring partial resolution of indirect */
        pbVar31 = (byte *)((uint)&local_68 | 1);
      }
      local_6c = 0xaaaaaaa;
      pbVar27 = pbVar31;
      if (pbVar33 != pbVar12) {
        do {
          pbVar29 = pbVar33 + 1;
          *pbVar27 = *pbVar33;
          pbVar27 = pbVar27 + 1;
          pbVar33 = pbVar29;
        } while (pbVar12 != pbVar29);
        pbVar31 = pbVar31 + uVar20;
      }
      *pbVar31 = 0;
      local_68._0_1_ = 10 < uVar20;
      pbVar12 = (byte *)FUN_001caf2a(&local_68,0,&DAT_002222cf,2);
      bVar11 = *pbVar12;
      __aeabi_memcpy(&local_40,pbVar12 + 1,7);
      uVar19 = *(undefined4 *)(pbVar12 + 8);
      pbVar12[0] = 0;
      pbVar12[1] = 0;
      pbVar12[2] = 0;
      pbVar12[3] = 0;
      pbVar12[4] = 0;
      pbVar12[5] = 0;
      pbVar12[6] = 0;
      pbVar12[7] = 0;
      pbVar12[8] = 0;
      pbVar12[9] = 0;
      pbVar12[10] = 0;
      pbVar12[0xb] = 0;
      __aeabi_memcpy(&local_30,&local_40,7);
      pbVar12 = (byte *)param_3[1];
      if (pbVar12 < (byte *)param_3[2]) {
        *pbVar12 = bVar11;
        __aeabi_memcpy(pbVar12 + 1,&local_30,7);
        *(undefined4 *)(pbVar12 + 8) = uVar19;
        uStack_2c._2_1_ = 0;
        uStack_2c._0_2_ = 0;
        pbVar12[0xc] = 0;
        __aeabi_memcpy(pbVar12 + 0xd,&local_38,7);
        pbVar12[0x14] = 0;
        pbVar12[0x15] = 0;
        pbVar12[0x16] = 0;
        pbVar12[0x17] = 0;
        goto LAB_001d1d18;
      }
      iVar5 = param_3[2] - *param_3 >> 3;
      iVar17 = ((int)pbVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
        uVar20 = iVar17 + 1;
        local_6c = iVar5 * 0x55555556;
        if (local_6c < uVar20) {
          local_6c = uVar20;
        }
      }
      FUN_001ccdd4(&local_5c,local_6c,iVar17,param_3 + 3);
      pbVar12 = pbStack_54;
      *pbStack_54 = bVar11;
      __aeabi_memcpy(pbStack_54 + 1,&local_30,7);
      *(undefined4 *)(pbVar12 + 8) = uVar19;
LAB_001d1d74:
      uStack_2c._2_1_ = 0;
      uStack_2c._0_2_ = 0;
      pbVar12[0xc] = 0;
      __aeabi_memcpy(pbVar12 + 0xd,&local_38,7);
      pbVar12[0x14] = 0;
      pbVar12[0x15] = 0;
      pbVar12[0x16] = 0;
      pbVar12[0x17] = 0;
      pbStack_54 = pbStack_54 + 0x18;
      FUN_001cce32(param_3,&local_5c);
      FUN_001cceae(&local_5c);
    }
    if (((byte)local_68 & 1) != 0) {
      free(local_60);
    }
LAB_001d1dc2:
    if (__stack_chk_guard - local_28 == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  case 0x67:
    if (pbVar12[1] == 0x74) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0021f77f,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else {
      if (pbVar12[1] != 0x65) goto switchD_001cd01a_caseD_4d;
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222245,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x69:
    if ((pbVar12[1] != 0x78) ||
       (pbVar12 = (byte *)FUN_001ccfb8(param_1 + 2,param_2,param_3), pbVar12 == param_1 + 2))
    goto switchD_001cd01a_caseD_4d;
    pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3);
    if (pbVar33 == pbVar12) {
      iVar5 = param_3[1];
      if (*param_3 != iVar5) {
        iVar17 = iVar5 + -0x18;
        do {
          param_3[1] = iVar5 + -0x18;
          if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
            free(*(void **)(iVar5 + -4));
          }
          if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
            free(*(void **)(iVar5 + -0x10));
          }
          iVar5 = param_3[1];
        } while (iVar5 != iVar17);
      }
      goto switchD_001cd01a_caseD_4d;
    }
    iVar5 = param_3[1];
    if ((uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2) goto switchD_001cd01a_caseD_4d;
    uVar20 = *(uint *)(iVar5 + -8);
    iVar17 = *(int *)(iVar5 + -4);
    if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
      iVar17 = iVar5 + -0xb;
      uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
    }
    puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
    local_38 = (byte *)*puVar10;
    local_34 = puVar10[1];
    local_30 = (byte *)puVar10[2];
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    iVar17 = param_3[1];
    iVar5 = iVar17;
    do {
      param_3[1] = iVar5 + -0x18;
      if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
        free(*(void **)(iVar5 + -4));
      }
      if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
        free(*(void **)(iVar5 + -0x10));
      }
      iVar5 = param_3[1];
    } while (iVar5 != iVar17 + -0x18);
    uVar20 = *(uint *)(iVar17 + -0x20);
    iVar5 = *(int *)(iVar17 + -0x1c);
    if ((*(byte *)(iVar17 + -0x24) & 1) == 0) {
      iVar5 = iVar17 + -0x23;
      uVar20 = (uint)(*(byte *)(iVar17 + -0x24) >> 1);
    }
    puVar10 = (undefined4 *)FUN_001cb080(iVar17 + -0x30,iVar5,uVar20);
    local_60 = (byte *)*puVar10;
    local_5c = puVar10[1];
    local_58 = (byte *)puVar10[2];
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    iVar5 = param_3[1];
    FUN_001cbc00(&local_90,&DAT_00222248,&local_60,&pbStack_54);
    puVar9 = (uint *)FUN_001cb080(&local_90,&DAT_0022224a,2);
    pbVar33 = local_30;
    pbVar31 = local_38;
    local_80 = *puVar9;
    local_7c = puVar9[1];
    local_78 = (void *)puVar9[2];
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    uVar20 = local_34;
    pbVar12 = local_30;
    if (((uint)local_38 & 1) == 0) {
      pbVar12 = (byte *)((uint)&local_38 | 1);
      uVar20 = (uint)local_38 >> 1 & 0x7f;
    }
    puVar9 = (uint *)FUN_001cb080(&local_80,pbVar12,uVar20);
    local_70 = (byte *)*puVar9;
    local_6c = puVar9[1];
    local_68 = (void *)puVar9[2];
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    puVar10 = (undefined4 *)FUN_001cb080(&local_70,&DAT_002213c8,1,&local_64);
    uVar1 = *(undefined1 *)puVar10;
    __aeabi_memcpy(&local_98,(int)puVar10 + 1,7);
    pbVar12 = (byte *)puVar10[2];
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
    __aeabi_memcpy((uint)&local_50 | 1,&local_98,7);
    local_94 = (uint)local_94._3_1_ << 0x18;
    local_98 = 0;
    local_3c = (void *)0x0;
    local_44 = (byte *)0x0;
    local_40 = 0;
    local_48 = pbVar12;
    FUN_001d0d6c(iVar5 + -0x18,&local_50);
    if (((uint)local_44 & 1) != 0) {
      free(local_3c);
    }
    if (((uint)local_50 & 1) != 0) {
      free(local_48);
    }
    if (((uint)local_70 & 1) != 0) {
      free(local_68);
    }
    if ((local_80 & 1) != 0) {
      free(local_78);
    }
    pbVar12 = local_58;
    pbVar27 = local_60;
    if (((uint)local_90 & 1) != 0) {
      free(local_88);
      pbVar12 = local_58;
      pbVar27 = local_60;
    }
joined_r0x001ced9a:
    if (((uint)pbVar27 & 1) != 0) {
      free(pbVar12);
    }
    if (((uint)pbVar31 & 1) != 0) {
      free(pbVar33);
    }
    goto switchD_001cd01a_caseD_4d;
  case 0x6c:
    bVar11 = pbVar12[1];
    if (bVar11 < 0x73) {
      if (bVar11 == 0x53) {
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_00222253,3);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
      else {
        if (bVar11 != 0x65) goto switchD_001cd01a_caseD_4d;
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_0022224d,2);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
    }
    else if (bVar11 == 0x73) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222250,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else {
      if (bVar11 != 0x74) goto switchD_001cd01a_caseD_4d;
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0021f77b,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x6d:
    bVar11 = pbVar12[1];
    if (bVar11 < 0x69) {
      if (bVar11 == 0x49) {
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_00222257,2);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
      else {
        if (bVar11 != 0x4c) goto switchD_001cd01a_caseD_4d;
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_0022225a,2);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
    }
    else if (bVar11 == 0x6d) {
      pbVar12 = param_1 + 2;
      if ((pbVar12 == param_2) || (*pbVar12 != 0x5f)) {
        uVar36 = FUN_001ccfb8(pbVar12,param_2,param_3);
        bVar34 = (byte *)uVar36 == pbVar12;
        if (!bVar34) {
          uVar36 = CONCAT44(*param_3,param_3[1]);
        }
        iVar5 = (int)uVar36;
        if (bVar34 || (int)((ulonglong)uVar36 >> 0x20) == iVar5) goto switchD_001cd01a_caseD_4d;
        uVar20 = *(uint *)(iVar5 + -8);
        iVar17 = *(int *)(iVar5 + -4);
        iVar32 = iVar5 + -0x18;
        if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
          iVar17 = iVar5 + -0xb;
          uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(iVar32,iVar17,uVar20);
        local_60 = (byte *)*puVar10;
        local_5c = puVar10[1];
        local_58 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001caf2a(&local_60,0,&DAT_00222248,1);
        local_38 = (byte *)*puVar10;
        local_34 = puVar10[1];
        local_30 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001cb080(&local_38,&DAT_00222260,3);
        uVar1 = *(undefined1 *)puVar10;
        __aeabi_memcpy(&local_a0,(int)puVar10 + 1,7);
        pbVar12 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
        __aeabi_memcpy((uint)&local_50 | 1,&local_a0,7);
        local_9a = 0;
        local_9c = 0;
        local_a0 = (void *)0x0;
        local_48 = pbVar12;
        goto LAB_001cf84c;
      }
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0022225d,2);
      FUN_001d2150(param_1 + 3,param_2,&local_50,param_3);
    }
    else if (bVar11 == 0x6c) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0021f89d,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else {
      if (bVar11 != 0x69) goto switchD_001cd01a_caseD_4d;
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0021f779,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x6e:
    bVar11 = pbVar12[1];
    if (bVar11 < 0x74) {
      if (bVar11 == 0x61) {
LAB_001cde7a:
        if (3 < iVar5) {
          bVar11 = *param_1;
          bVar34 = false;
          if (bVar11 == 0x67) {
            bVar34 = param_1[1] == 0x73;
            if (bVar34) {
              param_1 = param_1 + 2;
            }
            bVar11 = *param_1;
          }
          if (((bVar11 == 0x6e) && (bVar11 = param_1[1], bVar11 == 0x77 || bVar11 == 0x61)) &&
             (param_1 + 2 != param_2)) {
            bVar35 = false;
            pbVar12 = param_1 + 2;
            while (*pbVar12 != 0x5f) {
              pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3);
              if ((pbVar33 == pbVar12) ||
                 (bVar35 = (bool)(bVar35 | pbVar33 != param_2), pbVar12 = pbVar33,
                 pbVar33 == param_2)) goto switchD_001cd01a_caseD_4d;
            }
            pbVar33 = (byte *)FUN_001c6af0(pbVar12 + 1,param_2,param_3);
            if (pbVar33 != pbVar12 + 1 && pbVar33 != param_2) {
              if (((int)param_2 - (int)pbVar33 < 3) || (*pbVar33 != 0x70)) {
                if (*pbVar33 == 0x45) {
                  local_34 = 0;
                  local_30 = (byte *)0x0;
                  bVar2 = false;
                  local_38 = (byte *)0x0;
                  local_e4 = param_3[1];
                  local_f0 = (void *)0x0;
                  goto LAB_001d041a;
                }
              }
              else if (pbVar33[1] == 0x69) {
                pbVar12 = pbVar33 + 2;
                goto LAB_001cfb42;
              }
            }
          }
        }
        goto switchD_001cd01a_caseD_4d;
      }
      if (bVar11 == 0x65) {
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_00222264,2);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
      else {
        if (bVar11 != 0x67) goto switchD_001cd01a_caseD_4d;
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_0021f779,1);
        FUN_001d2150(param_1 + 2,param_2,&local_50,param_3);
      }
    }
    else {
      if (bVar11 != 0x74) {
        if (bVar11 == 0x78) {
          pbVar12 = (byte *)FUN_001ccfb8(param_1 + 2,param_2,param_3);
          if ((pbVar12 != param_1 + 2) && (iVar5 = param_3[1], *param_3 != iVar5)) {
            uVar20 = *(uint *)(iVar5 + -8);
            iVar17 = *(int *)(iVar5 + -4);
            if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
              iVar17 = iVar5 + -0xb;
              uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
            }
            puVar9 = (uint *)(iVar5 + -0x18);
            puVar10 = (undefined4 *)FUN_001cb080(puVar9,iVar17,uVar20);
            local_38 = (byte *)*puVar10;
            local_34 = puVar10[1];
            local_30 = (byte *)puVar10[2];
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            puVar10 = (undefined4 *)FUN_001caf2a(&local_38,0,"noexcept (",10);
            local_50 = (byte *)*puVar10;
            local_4c = (byte *)puVar10[1];
            local_48 = (byte *)puVar10[2];
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            puVar10 = (undefined4 *)FUN_001cb080(&local_50,&DAT_0022045d,1);
            uVar1 = *(undefined1 *)puVar10;
            __aeabi_memcpy(&local_60,(int)puVar10 + 1,7);
            uVar19 = puVar10[2];
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            if ((*(byte *)(iVar5 + -0x18) & 1) == 0) {
              *(undefined2 *)(iVar5 + -0x18) = 0;
            }
            else {
              puVar10 = (undefined4 *)(iVar5 + -0x10);
              *(undefined1 *)*puVar10 = 0;
              *(undefined4 *)(iVar5 + -0x14) = 0;
              uVar20 = (uint)*(byte *)(iVar5 + -0x18);
              if ((*(byte *)(iVar5 + -0x18) & 1) == 0) {
                uVar23 = 10;
              }
              else {
                uVar20 = *puVar9;
                uVar23 = (uVar20 & 0xfffffffe) - 1;
              }
              if ((uVar20 & 1) == 0) {
                uVar13 = (uVar20 & 0xff) >> 1;
                if ((uVar20 & 0xff) < 0x16) {
                  uVar28 = 10;
                }
                else {
                  uVar28 = (uVar13 + 0x10 & 0xf0) - 1;
                }
                bVar34 = true;
              }
              else {
                uVar28 = 10;
                uVar13 = 0;
                bVar34 = false;
              }
              if (uVar28 != uVar23) {
                if (uVar28 == 10) {
                  puVar26 = (undefined1 *)*puVar10;
                  if (bVar34) {
                    __aeabi_memcpy((undefined1 *)(iVar5 + -0x17),puVar26,((uVar20 & 0xfe) >> 1) + 1)
                    ;
                  }
                  else {
                    *(undefined1 *)(iVar5 + -0x17) = *puVar26;
                  }
                  free(puVar26);
                  *(char *)puVar9 = (char)(uVar13 << 1);
                }
                else {
                  puVar26 = malloc(uVar28 + 1);
                  if ((uVar23 < uVar28) || (puVar26 != (undefined1 *)0x0)) {
                    if (bVar34) {
                      __aeabi_memcpy(puVar26,iVar5 + -0x17,((uVar20 & 0xfe) >> 1) + 1);
                    }
                    else {
                      puVar7 = (undefined1 *)*puVar10;
                      *puVar26 = *puVar7;
                      free(puVar7);
                    }
                    *(uint *)(iVar5 + -0x18) = uVar28 + 1 | 1;
                    *(uint *)(iVar5 + -0x14) = uVar13;
                    *(undefined1 **)(iVar5 + -0x10) = puVar26;
                  }
                }
              }
            }
            *(undefined1 *)(iVar5 + -0x18) = uVar1;
            __aeabi_memcpy(iVar5 + -0x17,&local_60,7);
            *(undefined4 *)(iVar5 + -0x10) = uVar19;
            local_5c = (uint)local_5c._3_1_ << 0x18;
            local_60 = (byte *)0x0;
            if (((uint)local_50 & 1) != 0) {
              free(local_48);
            }
            if (((uint)local_38 & 1) != 0) {
              free(local_30);
            }
          }
          goto switchD_001cd01a_caseD_4d;
        }
        if (bVar11 != 0x77) goto switchD_001cd01a_caseD_4d;
        goto LAB_001cde7a;
      }
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222267,1);
      FUN_001d2150(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x6f:
    bVar11 = pbVar12[1];
    if (bVar11 < 0x6f) {
      if (bVar11 != 0x52) {
        if (bVar11 != 0x6e) goto switchD_001cd01a_caseD_4d;
        goto code_r0x001d23a4;
      }
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0022226e,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else if (bVar11 == 0x6f) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222269,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else {
      if (bVar11 != 0x72) goto switchD_001cd01a_caseD_4d;
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0022226c,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x70:
    switch(pbVar12[1]) {
    case 0x6c:
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00221427,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x6d:
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222271,3);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x6e:
    case 0x6f:
    case 0x71:
    case 0x72:
      goto switchD_001cd01a_caseD_4d;
    case 0x70:
      pbVar12 = param_1 + 2;
      if ((pbVar12 == param_2) || (*pbVar12 != 0x5f)) {
        uVar36 = FUN_001ccfb8(pbVar12,param_2,param_3);
        bVar34 = (byte *)uVar36 != pbVar12;
        if (bVar34) {
          uVar36 = CONCAT44(*param_3,param_3[1]);
        }
        iVar5 = (int)uVar36;
        if (!bVar34 || (int)((ulonglong)uVar36 >> 0x20) == iVar5) goto switchD_001cd01a_caseD_4d;
        uVar20 = *(uint *)(iVar5 + -8);
        iVar17 = *(int *)(iVar5 + -4);
        iVar32 = iVar5 + -0x18;
        if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
          iVar17 = iVar5 + -0xb;
          uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(iVar32,iVar17,uVar20);
        local_60 = (byte *)*puVar10;
        local_5c = puVar10[1];
        local_58 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001caf2a(&local_60,0,&DAT_00222248,1);
        local_38 = (byte *)*puVar10;
        local_34 = puVar10[1];
        local_30 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001cb080(&local_38,&DAT_0022227b,3,&uStack_2c);
        uVar1 = *(undefined1 *)puVar10;
        __aeabi_memcpy(&local_a8,(int)puVar10 + 1,7);
        pbVar12 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
        __aeabi_memcpy((uint)&local_50 | 1,&local_a8,7);
        uStack_a2 = 0;
        uStack_a4 = 0;
        local_a8 = 0;
        local_48 = pbVar12;
        goto LAB_001cf84c;
      }
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222278,2);
      FUN_001d2150(param_1 + 3,param_2,&local_50,param_3);
      break;
    case 0x73:
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00221427,1);
      FUN_001d2150(param_1 + 2,param_2,&local_50,param_3);
      break;
    case 0x74:
      if (2 < iVar5) {
        bVar11 = *param_1;
        bVar34 = bVar11 == 0x70;
        if (bVar34) {
          bVar11 = param_1[1];
        }
        if (((bVar34 && bVar11 == 0x74) &&
            (pbVar12 = (byte *)FUN_001ccfb8(param_1 + 2,param_2,param_3), pbVar12 != param_1 + 2))
           && ((pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3), pbVar33 != pbVar12 &&
               (iVar5 = param_3[1], 1 < (uint)((iVar5 - *param_3 >> 3) * -0x55555555))))) {
          uVar20 = *(uint *)(iVar5 + -8);
          iVar17 = *(int *)(iVar5 + -4);
          if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
            iVar17 = iVar5 + -0xb;
            uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
          local_50 = (byte *)*puVar10;
          local_4c = (byte *)puVar10[1];
          local_48 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          iVar17 = param_3[1];
          iVar5 = iVar17;
          do {
            param_3[1] = iVar5 + -0x18;
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = param_3[1];
          } while (iVar5 != iVar17 + -0x18);
          FUN_001cb080(iVar17 + -0x30,&DAT_00222338,2);
          pbVar33 = local_48;
          uVar20 = (uint)local_50 & 1;
          pbVar31 = local_4c;
          pbVar12 = local_48;
          if (((uint)local_50 & 1) == 0) {
            pbVar12 = (byte *)((uint)&local_50 | 1);
            pbVar31 = (byte *)((uint)local_50 >> 1 & 0x7f);
          }
          FUN_001cb080(param_3[1] + -0x18,pbVar12,pbVar31);
          if (uVar20 != 0) {
            free(pbVar33);
          }
        }
      }
      goto switchD_001cd01a_caseD_4d;
    default:
      if (pbVar12[1] != 0x4c) goto switchD_001cd01a_caseD_4d;
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00222275,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x71:
    if ((pbVar12[1] == 0x75) &&
       (pbVar12 = (byte *)FUN_001ccfb8(param_1 + 2,param_2,param_3), pbVar12 != param_1 + 2)) {
      pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3);
      if (pbVar33 == pbVar12) {
        iVar5 = param_3[1];
        if (*param_3 != iVar5) {
          iVar17 = iVar5 + -0x18;
          do {
            param_3[1] = iVar5 + -0x18;
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = param_3[1];
          } while (iVar5 != iVar17);
        }
      }
      else {
        pbVar12 = (byte *)FUN_001ccfb8(pbVar33,param_2,param_3);
        iVar5 = param_3[1];
        uVar20 = (iVar5 - *param_3 >> 3) * -0x55555555;
        if (pbVar12 == pbVar33) {
          if (1 < uVar20) {
            iVar32 = iVar5 + -0x18;
            iVar17 = iVar5;
            do {
              param_3[1] = iVar17 + -0x18;
              if ((*(byte *)(iVar17 + -0xc) & 1) != 0) {
                free(*(void **)(iVar17 + -4));
              }
              if ((*(byte *)(iVar17 + -0x18) & 1) != 0) {
                free(*(void **)(iVar17 + -0x10));
              }
              iVar17 = param_3[1];
            } while (iVar17 != iVar32);
            do {
              param_3[1] = iVar32 + -0x18;
              if ((*(byte *)(iVar32 + -0xc) & 1) != 0) {
                free(*(void **)(iVar32 + -4));
              }
              if ((*(byte *)(iVar32 + -0x18) & 1) != 0) {
                free(*(void **)(iVar32 + -0x10));
              }
              iVar32 = param_3[1];
            } while (iVar32 != iVar5 + -0x30);
          }
        }
        else if (2 < uVar20) {
          uVar20 = *(uint *)(iVar5 + -8);
          iVar17 = *(int *)(iVar5 + -4);
          if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
            iVar17 = iVar5 + -0xb;
            uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
          local_38 = (byte *)*puVar10;
          local_34 = puVar10[1];
          local_30 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          iVar17 = param_3[1];
          iVar5 = iVar17;
          do {
            param_3[1] = iVar5 + -0x18;
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = param_3[1];
          } while (iVar5 != iVar17 + -0x18);
          uVar20 = *(uint *)(iVar17 + -0x20);
          iVar5 = *(int *)(iVar17 + -0x1c);
          if ((*(byte *)(iVar17 + -0x24) & 1) == 0) {
            iVar5 = iVar17 + -0x23;
            uVar20 = (uint)(*(byte *)(iVar17 + -0x24) >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(iVar17 + -0x30,iVar5,uVar20);
          local_60 = (byte *)*puVar10;
          local_5c = puVar10[1];
          local_58 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          iVar17 = param_3[1];
          iVar5 = iVar17;
          do {
            param_3[1] = iVar5 + -0x18;
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = param_3[1];
          } while (iVar5 != iVar17 + -0x18);
          uVar20 = *(uint *)(iVar17 + -0x20);
          iVar5 = *(int *)(iVar17 + -0x1c);
          if ((*(byte *)(iVar17 + -0x24) & 1) == 0) {
            iVar5 = iVar17 + -0x23;
            uVar20 = (uint)(*(byte *)(iVar17 + -0x24) >> 1);
          }
          puVar9 = (uint *)FUN_001cb080(iVar17 + -0x30,iVar5,uVar20);
          local_70 = (byte *)*puVar9;
          local_6c = puVar9[1];
          local_68 = (void *)puVar9[2];
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9[2] = 0;
          iVar5 = param_3[1];
          FUN_001cbc00(local_dc,&DAT_00222248,&local_70,&local_64);
          puVar9 = (uint *)FUN_001cb080(local_dc,") ? (",5);
          pbVar33 = local_58;
          local_d0 = *puVar9;
          local_cc = puVar9[1];
          local_c8 = (void *)puVar9[2];
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9[2] = 0;
          uVar23 = (uint)local_60 & 1;
          uVar20 = local_5c;
          pbVar12 = local_58;
          if (((uint)local_60 & 1) == 0) {
            pbVar12 = (byte *)((uint)&local_60 | 1);
            uVar20 = (uint)local_60 >> 1 & 0x7f;
          }
          puVar9 = (uint *)FUN_001cb080(&local_d0,pbVar12,uVar20);
          local_c0 = *puVar9;
          local_bc = puVar9[1];
          local_b8 = (void *)puVar9[2];
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9[2] = 0;
          puVar10 = (undefined4 *)FUN_001cb080(&local_c0,") : (",5);
          pbVar31 = local_30;
          local_90 = (byte *)*puVar10;
          local_8c = puVar10[1];
          local_88 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          uVar13 = (uint)local_38 & 1;
          uVar20 = local_34;
          pbVar12 = local_30;
          if (((uint)local_38 & 1) == 0) {
            pbVar12 = (byte *)((uint)&local_38 | 1);
            uVar20 = (uint)local_38 >> 1 & 0x7f;
          }
          puVar9 = (uint *)FUN_001cb080(&local_90,pbVar12,uVar20);
          local_80 = *puVar9;
          local_7c = puVar9[1];
          local_78 = (void *)puVar9[2];
          *puVar9 = 0;
          puVar9[1] = 0;
          puVar9[2] = 0;
          puVar10 = (undefined4 *)FUN_001cb080(&local_80,&DAT_0022045d,1,&local_74);
          uVar1 = *(undefined1 *)puVar10;
          __aeabi_memcpy(&local_b0,(int)puVar10 + 1,7);
          pbVar12 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
          __aeabi_memcpy((uint)&local_50 | 1,&local_b0,7);
          local_ac = (uint)local_ac._3_1_ << 0x18;
          local_b0 = (byte *)0x0;
          local_3c = (void *)0x0;
          local_44 = (byte *)0x0;
          local_40 = 0;
          local_48 = pbVar12;
          FUN_001d0d6c(iVar5 + -0x18,&local_50);
          if (((uint)local_44 & 1) != 0) {
            free(local_3c);
          }
          if (((uint)local_50 & 1) != 0) {
            free(local_48);
          }
          if ((local_80 & 1) != 0) {
            free(local_78);
          }
          if (((uint)local_90 & 1) != 0) {
            free(local_88);
          }
          if ((local_c0 & 1) != 0) {
            free(local_b8);
          }
          if ((local_d0 & 1) != 0) {
            free(local_c8);
          }
          if ((local_dc[0] & 1) != 0) {
            free(local_d4);
          }
          if (((uint)local_70 & 1) != 0) {
            free(local_68);
          }
          if (uVar23 != 0) {
            free(pbVar33);
          }
          if (uVar13 != 0) {
            free(pbVar31);
          }
        }
      }
    }
    goto switchD_001cd01a_caseD_4d;
  case 0x72:
    bVar11 = pbVar12[1];
    if (bVar11 < 99) {
      if (bVar11 == 0x4d) {
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_0022228b,2);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
      else {
        if (bVar11 != 0x53) goto switchD_001cd01a_caseD_4d;
        local_48 = (byte *)0x0;
        local_50 = (byte *)0x0;
        local_4c = (byte *)0x0;
        FUN_001c5e62(&local_50,&DAT_00222291,3);
        FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
      }
    }
    else if (bVar11 == 0x73) {
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_0022228e,2);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    else {
      if (bVar11 != 0x6d) {
        if ((bVar11 == 99) && (2 < iVar5)) {
          bVar11 = *param_1;
          bVar34 = bVar11 == 0x72;
          if (bVar34) {
            bVar11 = param_1[1];
          }
          if ((((bVar34 && bVar11 == 99) &&
               (pbVar12 = (byte *)FUN_001c6af0(param_1 + 2,param_2,param_3), pbVar12 != param_1 + 2)
               ) && (pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3), pbVar33 != pbVar12))
             && (iVar5 = param_3[1], 1 < (uint)((iVar5 - *param_3 >> 3) * -0x55555555))) {
            uVar20 = *(uint *)(iVar5 + -8);
            iVar17 = *(int *)(iVar5 + -4);
            if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
              iVar17 = iVar5 + -0xb;
              uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
            }
            puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
            local_38 = (byte *)*puVar10;
            local_34 = puVar10[1];
            local_30 = (byte *)puVar10[2];
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            iVar17 = param_3[1];
            iVar5 = iVar17;
            do {
              param_3[1] = iVar5 + -0x18;
              if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                free(*(void **)(iVar5 + -4));
              }
              if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                free(*(void **)(iVar5 + -0x10));
              }
              iVar5 = param_3[1];
            } while (iVar5 != iVar17 + -0x18);
            pbVar12 = local_38;
            if (*param_3 != iVar17 + -0x18) {
              uVar20 = *(uint *)(iVar17 + -0x20);
              iVar5 = *(int *)(iVar17 + -0x1c);
              if ((*(byte *)(iVar17 + -0x24) & 1) == 0) {
                iVar5 = iVar17 + -0x23;
                uVar20 = (uint)(*(byte *)(iVar17 + -0x24) >> 1);
              }
              puVar10 = (undefined4 *)FUN_001cb080(iVar17 + -0x30,iVar5,uVar20);
              local_90 = (byte *)*puVar10;
              local_8c = puVar10[1];
              local_88 = (byte *)puVar10[2];
              *puVar10 = 0;
              puVar10[1] = 0;
              puVar10[2] = 0;
              puVar9 = (uint *)FUN_001caf2a(&local_90,0,"reinterpret_cast<",0x11);
              local_80 = *puVar9;
              local_7c = puVar9[1];
              local_78 = (void *)puVar9[2];
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar9[2] = 0;
              puVar9 = (uint *)FUN_001cb080(&local_80,&DAT_002222eb,2,&local_74);
              pbVar12 = local_38;
              local_70 = (byte *)*puVar9;
              local_6c = puVar9[1];
              local_68 = (void *)puVar9[2];
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar9[2] = 0;
              uVar20 = local_34;
              pbVar33 = local_30;
              if (((uint)local_38 & 1) == 0) {
                pbVar33 = (byte *)((uint)&local_38 | 1);
                uVar20 = (uint)local_38 >> 1 & 0x7f;
              }
              puVar10 = (undefined4 *)FUN_001cb080(&local_70,pbVar33,uVar20);
              local_60 = (byte *)*puVar10;
              local_5c = puVar10[1];
              local_58 = (byte *)puVar10[2];
              *puVar10 = 0;
              puVar10[1] = 0;
              puVar10[2] = 0;
              puVar10 = (undefined4 *)FUN_001cb080(&local_60,&DAT_0022045d,1,&pbStack_54);
              uVar1 = *(undefined1 *)puVar10;
              __aeabi_memcpy(&local_c0,(int)puVar10 + 1,7);
              pbVar33 = (byte *)puVar10[2];
              *puVar10 = 0;
              puVar10[1] = 0;
              puVar10[2] = 0;
              local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
              __aeabi_memcpy((uint)&local_50 | 1,&local_c0,7);
              local_bc = (uint)local_bc._3_1_ << 0x18;
              local_c0 = 0;
              local_3c = (void *)0x0;
              local_44 = (byte *)0x0;
              local_40 = 0;
              local_48 = pbVar33;
              FUN_001d0d6c(iVar17 + -0x30,&local_50);
              if (((uint)local_44 & 1) != 0) {
                free(local_3c);
              }
              if (((uint)local_50 & 1) != 0) {
                free(local_48);
              }
              if (((uint)local_60 & 1) != 0) {
                free(local_58);
              }
              if (((uint)local_70 & 1) != 0) {
                free(local_68);
              }
              if ((local_80 & 1) != 0) {
                free(local_78);
              }
              if (((uint)local_90 & 1) != 0) {
                free(local_88);
              }
            }
            if (((uint)pbVar12 & 1) != 0) {
              free(local_30);
            }
          }
        }
        goto switchD_001cd01a_caseD_4d;
      }
      local_48 = (byte *)0x0;
      local_50 = (byte *)0x0;
      local_4c = (byte *)0x0;
      FUN_001c5e62(&local_50,&DAT_00221418,1);
      FUN_001d1dec(param_1 + 2,param_2,&local_50,param_3);
    }
    break;
  case 0x73:
    bVar11 = pbVar12[1];
    if (bVar11 < 0x72) {
      if (bVar11 == 0x5a) {
        if ((int)param_2 - (int)pbVar12 < 3) goto switchD_001cd01a_caseD_4d;
        if (pbVar12[2] != 0x66) {
          if ((pbVar12[2] == 0x54) && (2 < iVar5)) {
            bVar11 = *param_1;
            bVar34 = bVar11 == 0x73;
            if (bVar34) {
              bVar11 = param_1[1];
            }
            if ((bVar34 && bVar11 == 0x5a) && (param_1 = param_1 + 2, *param_1 == 0x54)) {
              iVar5 = *param_3;
              iVar17 = param_3[1];
              pbVar12 = (byte *)FUN_001cbc74(param_1,param_2,param_3);
              if (pbVar12 != param_1) {
                iVar32 = *param_3;
                iVar5 = iVar17 - iVar5 >> 3;
                iVar24 = iVar5 * -0x55555555;
                iVar17 = param_3[1] - iVar32 >> 3;
                local_e0 = (byte *)(iVar17 * -0x55555555);
                local_38 = (byte *)CONCAT31(local_38._1_3_,0x14);
                __aeabi_memcpy((uint)&local_38 | 1,"sizeof...(",10);
                local_30 = (byte *)((uint)local_30 & 0xffffff);
                if (iVar24 + iVar17 * 0x55555555 == 0) {
                  FUN_001cb080(&local_38,&DAT_0022045d,1);
                  pbVar12 = (byte *)param_3[1];
                }
                else {
                  iVar32 = iVar32 + iVar5 * 8;
                  uVar20 = *(uint *)(iVar32 + 0x10);
                  iVar15 = *(int *)(iVar32 + 0x14);
                  if ((*(byte *)(iVar32 + 0xc) & 1) == 0) {
                    iVar15 = iVar32 + 0xd;
                    uVar20 = (uint)(*(byte *)(iVar32 + 0xc) >> 1);
                  }
                  puVar9 = (uint *)FUN_001cb080(iVar32,iVar15,uVar20);
                  local_50 = (byte *)*puVar9;
                  local_4c = (byte *)puVar9[1];
                  pbVar27 = (byte *)puVar9[2];
                  *puVar9 = 0;
                  puVar9[1] = 0;
                  puVar9[2] = 0;
                  uVar20 = (uint)local_50 & 1;
                  pbVar33 = local_4c;
                  pbVar12 = pbVar27;
                  if (((uint)local_50 & 1) == 0) {
                    pbVar33 = (byte *)((uint)local_50 >> 1 & 0x7f);
                    pbVar12 = (byte *)((uint)&local_50 | 1);
                  }
                  local_48 = pbVar27;
                  FUN_001cb080(&local_38,pbVar12,pbVar33);
                  if (uVar20 != 0) {
                    free(pbVar27);
                  }
                  if ((byte *)(iVar24 + 1) != local_e0) {
                    local_e4 = (int)local_e0 + -1 + iVar5 * 0x55555555;
                    iVar5 = iVar5 << 3;
                    do {
                      iVar15 = *param_3 + iVar5;
                      uVar20 = *(uint *)(iVar15 + 0x28);
                      iVar32 = *(int *)(iVar15 + 0x2c);
                      if ((*(byte *)(iVar15 + 0x24) & 1) == 0) {
                        iVar32 = iVar15 + 0x25;
                        uVar20 = (uint)(*(byte *)(iVar15 + 0x24) >> 1);
                      }
                      puVar10 = (undefined4 *)FUN_001cb080(iVar15 + 0x18,iVar32,uVar20);
                      local_60 = (byte *)*puVar10;
                      local_5c = puVar10[1];
                      local_58 = (byte *)puVar10[2];
                      *puVar10 = 0;
                      puVar10[1] = 0;
                      puVar10[2] = 0;
                      puVar9 = (uint *)FUN_001caf2a(&local_60,0,&DAT_00222122,2);
                      local_50 = (byte *)*puVar9;
                      local_4c = (byte *)puVar9[1];
                      pbVar27 = (byte *)puVar9[2];
                      *puVar9 = 0;
                      puVar9[1] = 0;
                      puVar9[2] = 0;
                      uVar20 = (uint)local_50 & 1;
                      pbVar33 = local_4c;
                      pbVar12 = pbVar27;
                      if (((uint)local_50 & 1) == 0) {
                        pbVar33 = (byte *)((uint)local_50 >> 1 & 0x7f);
                        pbVar12 = (byte *)((uint)&local_50 | 1);
                      }
                      local_48 = pbVar27;
                      FUN_001cb080(&local_38,pbVar12,pbVar33);
                      if (uVar20 != 0) {
                        free(pbVar27);
                      }
                      if (((uint)local_60 & 1) != 0) {
                        free(local_58);
                      }
                      iVar5 = iVar5 + 0x18;
                      local_e4 = local_e4 + -1;
                    } while (local_e4 != 0);
                  }
                  FUN_001cb080(&local_38,&DAT_0022045d,1);
                  iVar32 = param_3[1];
                  iVar5 = iVar32;
                  do {
                    iVar15 = iVar5 + -0x18;
                    do {
                      param_3[1] = iVar5 + -0x18;
                      if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                        free(*(void **)(iVar5 + -4));
                      }
                      if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                        free(*(void **)(iVar5 + -0x10));
                      }
                      iVar5 = param_3[1];
                    } while (iVar5 != iVar15);
                    local_e0 = (byte *)((int)local_e0 + -1);
                    iVar5 = iVar15;
                  } while (local_e0 != (byte *)iVar24);
                  pbVar12 = (byte *)(iVar32 + (iVar24 + iVar17 * 0x55555555) * 0x18);
                }
                bVar11 = (byte)local_38;
                __aeabi_memcpy(&local_80,(uint)&local_38 | 1,7);
                pbVar33 = local_30;
                local_30 = (byte *)0x0;
                local_38 = (byte *)0x0;
                local_34 = 0;
                __aeabi_memcpy(&local_70,&local_80,7);
                local_7c = (uint)local_7c._3_1_ << 0x18;
                local_5c = local_5c & 0xff000000;
                local_80 = 0;
                local_60 = (byte *)0x0;
                if (pbVar12 < (byte *)param_3[2]) {
                  *pbVar12 = bVar11;
                  __aeabi_memcpy(pbVar12 + 1,&local_70,7);
                  *(byte **)(pbVar12 + 8) = pbVar33;
                  local_6c = (uint)local_6c._3_1_ << 0x18;
                  local_70 = (byte *)0x0;
                  pbVar12[0xc] = 0;
                  __aeabi_memcpy(pbVar12 + 0xd,&local_60,7);
                  pbVar12[0x14] = 0;
                  pbVar12[0x15] = 0;
                  pbVar12[0x16] = 0;
                  pbVar12[0x17] = 0;
                  local_5c = local_5c & 0xff000000;
                  local_60 = (byte *)0x0;
                  param_3[1] = param_3[1] + 0x18;
                }
                else {
                  iVar5 = param_3[2] - *param_3 >> 3;
                  iVar17 = ((int)pbVar12 - *param_3 >> 3) * -0x55555555;
                  if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
                    pbVar12 = (byte *)(iVar17 + 1);
                    pbVar31 = (byte *)(iVar5 * 0x55555556);
                    if (pbVar31 < pbVar12) {
                      pbVar31 = pbVar12;
                    }
                  }
                  FUN_001ccdd4(&local_50,pbVar31,iVar17,param_3 + 3);
                  pbVar12 = local_48;
                  *local_48 = bVar11;
                  __aeabi_memcpy(local_48 + 1,&local_70,7);
                  *(byte **)(pbVar12 + 8) = pbVar33;
                  local_6c = (uint)local_6c._3_1_ << 0x18;
                  local_70 = (byte *)0x0;
                  pbVar12[0xc] = 0;
                  __aeabi_memcpy(pbVar12 + 0xd,&local_60,7);
                  pbVar12[0x14] = 0;
                  pbVar12[0x15] = 0;
                  pbVar12[0x16] = 0;
                  pbVar12[0x17] = 0;
                  local_48 = local_48 + 0x18;
                  local_5c = local_5c & 0xff000000;
                  local_60 = (byte *)0x0;
                  FUN_001cce32(param_3,&local_50);
                  FUN_001cceae(&local_50);
                }
                if (((uint)local_38 & 1) != 0) {
                  free(local_30);
                }
              }
            }
          }
          goto switchD_001cd01a_caseD_4d;
        }
        if (iVar5 < 3) goto switchD_001cd01a_caseD_4d;
        bVar11 = *param_1;
        bVar34 = bVar11 == 0x73;
        if (bVar34) {
          bVar11 = param_1[1];
        }
        if ((!bVar34 || bVar11 != 0x5a) || (param_1 = param_1 + 2, *param_1 != 0x66))
        goto switchD_001cd01a_caseD_4d;
        uVar36 = FUN_001d1a3c(param_1,param_2,param_3);
        bVar34 = (byte *)uVar36 != param_1;
        if (bVar34) {
          uVar36 = CONCAT44(*param_3,param_3[1]);
        }
        iVar5 = (int)uVar36;
        if (!bVar34 || (int)((ulonglong)uVar36 >> 0x20) == iVar5) goto switchD_001cd01a_caseD_4d;
        uVar20 = *(uint *)(iVar5 + -8);
        iVar17 = *(int *)(iVar5 + -4);
        iVar32 = iVar5 + -0x18;
        if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
          iVar17 = iVar5 + -0xb;
          uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(iVar32,iVar17,uVar20);
        local_60 = (byte *)*puVar10;
        local_5c = puVar10[1];
        local_58 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001caf2a(&local_60,0,"sizeof...(",10);
LAB_001cde1e:
        local_38 = (byte *)*puVar10;
        local_34 = puVar10[1];
        local_30 = (byte *)puVar10[2];
        puVar21 = &uStack_2c;
        goto LAB_001cee64;
      }
      if (bVar11 != 99) {
        if ((bVar11 == 0x70) && (2 < iVar5)) {
          bVar11 = *param_1;
          bVar34 = bVar11 == 0x73;
          if (bVar34) {
            bVar11 = param_1[1];
          }
          if (bVar34 && bVar11 == 0x70) {
            FUN_001ccfb8(param_1 + 2,param_2,param_3);
          }
        }
        goto switchD_001cd01a_caseD_4d;
      }
      if (iVar5 < 3) goto switchD_001cd01a_caseD_4d;
      bVar11 = *param_1;
      bVar34 = bVar11 == 0x73;
      if (bVar34) {
        bVar11 = param_1[1];
      }
      if ((((!bVar34 || bVar11 != 99) ||
           (pbVar12 = (byte *)FUN_001c6af0(param_1 + 2,param_2,param_3), pbVar12 == param_1 + 2)) ||
          (pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3), pbVar33 == pbVar12)) ||
         (iVar5 = param_3[1], (uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2))
      goto switchD_001cd01a_caseD_4d;
      uVar20 = *(uint *)(iVar5 + -8);
      iVar17 = *(int *)(iVar5 + -4);
      if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
        iVar17 = iVar5 + -0xb;
        uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
      }
      puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
      local_38 = (byte *)*puVar10;
      local_34 = puVar10[1];
      local_30 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      iVar17 = param_3[1];
      iVar5 = iVar17;
      do {
        param_3[1] = iVar5 + -0x18;
        if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
          free(*(void **)(iVar5 + -4));
        }
        if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
          free(*(void **)(iVar5 + -0x10));
        }
        iVar5 = param_3[1];
      } while (iVar5 != iVar17 + -0x18);
      uVar20 = *(uint *)(iVar17 + -0x20);
      iVar5 = *(int *)(iVar17 + -0x1c);
      if ((*(byte *)(iVar17 + -0x24) & 1) == 0) {
        iVar5 = iVar17 + -0x23;
        uVar20 = (uint)(*(byte *)(iVar17 + -0x24) >> 1);
      }
      puVar10 = (undefined4 *)FUN_001cb080(iVar17 + -0x30,iVar5,uVar20);
      local_90 = (byte *)*puVar10;
      local_8c = puVar10[1];
      local_88 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar9 = (uint *)FUN_001caf2a(&local_90,0,"static_cast<",0xc);
      local_80 = *puVar9;
      local_7c = puVar9[1];
      local_78 = (void *)puVar9[2];
      *puVar9 = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      puVar9 = (uint *)FUN_001cb080(&local_80,&DAT_002222eb,2,&local_74);
      pbVar33 = local_30;
      pbVar31 = local_38;
      local_70 = (byte *)*puVar9;
      local_6c = puVar9[1];
      local_68 = (void *)puVar9[2];
      *puVar9 = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      uVar20 = local_34;
      pbVar12 = local_30;
      if (((uint)local_38 & 1) == 0) {
        pbVar12 = (byte *)((uint)&local_38 | 1);
        uVar20 = (uint)local_38 >> 1 & 0x7f;
      }
      puVar10 = (undefined4 *)FUN_001cb080(&local_70,pbVar12,uVar20);
      local_60 = (byte *)*puVar10;
      local_5c = puVar10[1];
      local_58 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10 = (undefined4 *)FUN_001cb080(&local_60,&DAT_0022045d,1,&pbStack_54);
      uVar1 = *(undefined1 *)puVar10;
      __aeabi_memcpy(&local_c0,(int)puVar10 + 1,7);
      pbVar12 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
      __aeabi_memcpy((uint)&local_50 | 1,&local_c0,7);
      local_bc = (uint)local_bc._3_1_ << 0x18;
      local_c0 = 0;
      local_3c = (void *)0x0;
      local_44 = (byte *)0x0;
      local_40 = 0;
      local_48 = pbVar12;
      FUN_001d0d6c(iVar17 + -0x30,&local_50);
      if (((uint)local_44 & 1) != 0) {
        free(local_3c);
      }
      if (((uint)local_50 & 1) != 0) {
        free(local_48);
      }
      if (((uint)local_60 & 1) != 0) {
        free(local_58);
      }
      if (((uint)local_70 & 1) != 0) {
        free(local_68);
      }
      pbVar12 = local_88;
      pbVar27 = local_90;
      if ((local_80 & 1) != 0) {
        free(local_78);
        pbVar12 = local_88;
        pbVar27 = local_90;
      }
      goto joined_r0x001ced9a;
    }
    if (bVar11 != 0x72) {
      if (bVar11 != 0x74) {
        if ((bVar11 != 0x7a) || (iVar5 < 3)) goto switchD_001cd01a_caseD_4d;
        bVar11 = *param_1;
        bVar34 = bVar11 == 0x73;
        if (bVar34) {
          bVar11 = param_1[1];
        }
        if (!bVar34 || bVar11 != 0x7a) goto switchD_001cd01a_caseD_4d;
        param_1 = param_1 + 2;
        uVar36 = FUN_001ccfb8(param_1,param_2,param_3);
        bVar34 = (byte *)uVar36 != param_1;
        if (bVar34) {
          uVar36 = CONCAT44(*param_3,param_3[1]);
        }
        iVar5 = (int)uVar36;
        if (!bVar34 || (int)((ulonglong)uVar36 >> 0x20) == iVar5) goto switchD_001cd01a_caseD_4d;
        uVar20 = *(uint *)(iVar5 + -8);
        iVar17 = *(int *)(iVar5 + -4);
        iVar32 = iVar5 + -0x18;
        if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
          iVar17 = iVar5 + -0xb;
          uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
        }
        puVar10 = (undefined4 *)FUN_001cb080(iVar32,iVar17,uVar20);
        local_60 = (byte *)*puVar10;
        local_5c = puVar10[1];
        local_58 = (byte *)puVar10[2];
        *puVar10 = 0;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = (undefined4 *)FUN_001caf2a(&local_60,0,"sizeof (",8);
        goto LAB_001cde1e;
      }
      if (iVar5 < 3) goto switchD_001cd01a_caseD_4d;
      bVar11 = *param_1;
      bVar34 = bVar11 == 0x73;
      if (bVar34) {
        bVar11 = param_1[1];
      }
      if (!bVar34 || bVar11 != 0x74) goto switchD_001cd01a_caseD_4d;
      param_1 = param_1 + 2;
      uVar36 = FUN_001c6af0(param_1,param_2,param_3);
      bVar34 = (byte *)uVar36 != param_1;
      if (bVar34) {
        uVar36 = CONCAT44(*param_3,param_3[1]);
      }
      iVar5 = (int)uVar36;
      if (!bVar34 || (int)((ulonglong)uVar36 >> 0x20) == iVar5) goto switchD_001cd01a_caseD_4d;
      uVar20 = *(uint *)(iVar5 + -8);
      iVar17 = *(int *)(iVar5 + -4);
      iVar32 = iVar5 + -0x18;
      if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
        iVar17 = iVar5 + -0xb;
        uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
      }
      puVar10 = (undefined4 *)FUN_001cb080(iVar32,iVar17,uVar20);
      local_60 = (byte *)*puVar10;
      local_5c = puVar10[1];
      local_58 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10 = (undefined4 *)FUN_001caf2a(&local_60,0,"sizeof (",8);
      local_38 = (byte *)*puVar10;
      local_34 = puVar10[1];
      local_30 = (byte *)puVar10[2];
      puVar21 = puVar10;
LAB_001cee64:
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      puVar10 = (undefined4 *)FUN_001cb080(&local_38,&DAT_0022045d,1,puVar21);
      uVar1 = *(undefined1 *)puVar10;
      __aeabi_memcpy(&local_70,(int)puVar10 + 1,7);
      pbVar12 = (byte *)puVar10[2];
      *puVar10 = 0;
      puVar10[1] = 0;
      puVar10[2] = 0;
      local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
      __aeabi_memcpy((uint)&local_50 | 1,&local_70,7);
      local_6c = (uint)local_6c._3_1_ << 0x18;
      local_70 = (byte *)0x0;
      local_48 = pbVar12;
      goto LAB_001cf84c;
    }
    goto code_r0x001d23a4;
  case 0x74:
    bVar11 = pbVar12[1];
    if (0x71 < bVar11) {
      if (bVar11 == 0x72) {
        local_34 = local_34 & 0xff000000;
        local_60 = (byte *)0x6f726874;
        local_38 = (byte *)0x0;
        puVar26 = (undefined1 *)param_3[1];
        if (puVar26 < (undefined1 *)param_3[2]) {
          *puVar26 = 10;
          puVar26[5] = 0x77;
          *(undefined4 *)(puVar26 + 1) = 0x6f726874;
          puVar26[6] = 0;
          puVar26[7] = 0;
          *(undefined4 *)(puVar26 + 8) = 0;
          local_5c = (uint)local_5c._1_3_ << 8;
          local_60 = (byte *)0x0;
          puVar26[0xc] = 0;
          __aeabi_memcpy(puVar26 + 0xd,&local_38,7);
          *(undefined4 *)(puVar26 + 0x14) = 0;
          local_34 = local_34 & 0xff000000;
          local_38 = (byte *)0x0;
          param_3[1] = param_3[1] + 0x18;
        }
        else {
          iVar5 = param_3[2] - *param_3 >> 3;
          iVar17 = ((int)puVar26 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
            pbVar12 = (byte *)(iVar17 + 1);
            pbVar31 = (byte *)(iVar5 * 0x55555556);
            if (pbVar31 < pbVar12) {
              pbVar31 = pbVar12;
            }
          }
          FUN_001ccdd4(&local_50,pbVar31,iVar17,param_3 + 3);
          *local_48 = 10;
          local_48[5] = 0x77;
          *(byte **)(local_48 + 1) = local_60;
          local_48[6] = 0;
          local_48[7] = 0;
          pbVar12 = local_48;
          pbVar12[8] = 0;
          pbVar12[9] = 0;
          pbVar12[10] = 0;
          pbVar12[0xb] = 0;
          local_5c = (uint)local_5c._1_3_ << 8;
          local_60 = (byte *)0x0;
          local_48[0xc] = 0;
          __aeabi_memcpy(local_48 + 0xd,&local_38,7);
          pbVar12[0x14] = 0;
          pbVar12[0x15] = 0;
          pbVar12[0x16] = 0;
          pbVar12[0x17] = 0;
          local_48 = local_48 + 0x18;
          local_34 = local_34 & 0xff000000;
          local_38 = (byte *)0x0;
          FUN_001cce32(param_3,&local_50);
          FUN_001cceae(&local_50);
        }
      }
      else if ((bVar11 == 0x77) && (2 < iVar5)) {
        bVar11 = *param_1;
        bVar34 = bVar11 == 0x74;
        if (bVar34) {
          bVar11 = param_1[1];
        }
        if (bVar34 && bVar11 == 0x77) {
          param_1 = param_1 + 2;
          uVar36 = FUN_001ccfb8(param_1,param_2,param_3);
          bVar34 = (byte *)uVar36 != param_1;
          if (bVar34) {
            uVar36 = CONCAT44(*param_3,param_3[1]);
          }
          iVar5 = (int)uVar36;
          if (bVar34 && (int)((ulonglong)uVar36 >> 0x20) != iVar5) {
            uVar20 = *(uint *)(iVar5 + -8);
            iVar17 = *(int *)(iVar5 + -4);
            if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
              iVar17 = iVar5 + -0xb;
              uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
            }
            puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
            local_38 = (byte *)*puVar10;
            local_34 = puVar10[1];
            local_30 = (byte *)puVar10[2];
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            puVar10 = (undefined4 *)FUN_001caf2a(&local_38,0,"throw ",6);
            uVar1 = *(undefined1 *)puVar10;
            __aeabi_memcpy(&local_60,(int)puVar10 + 1,7);
            pbVar12 = (byte *)puVar10[2];
            *puVar10 = 0;
            puVar10[1] = 0;
            puVar10[2] = 0;
            local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
            __aeabi_memcpy((uint)&local_50 | 1,&local_60,7);
            local_5c = (uint)local_5c._3_1_ << 0x18;
            local_60 = (byte *)0x0;
            local_3c = (void *)0x0;
            local_44 = (byte *)0x0;
            local_40 = 0;
            local_48 = pbVar12;
            FUN_001d0d6c(iVar5 + -0x18,&local_50);
            if (((uint)local_44 & 1) != 0) {
              free(local_3c);
            }
            if (((uint)local_50 & 1) != 0) {
              free(local_48);
            }
            if (((uint)local_38 & 1) != 0) {
              free(local_30);
            }
          }
        }
      }
      goto switchD_001cd01a_caseD_4d;
    }
    if ((((bVar11 != 0x65 && bVar11 != 0x69) || (iVar5 < 3)) || (*param_1 != 0x74)) ||
       (bVar11 = param_1[1], bVar11 != 0x69 && bVar11 != 0x65)) goto switchD_001cd01a_caseD_4d;
    param_1 = param_1 + 2;
    if (bVar11 == 0x65) {
      uVar36 = FUN_001ccfb8(param_1,param_2,param_3);
    }
    else {
      uVar36 = FUN_001c6af0(param_1,param_2,param_3);
    }
    bVar34 = (byte *)uVar36 != param_1;
    if (bVar34) {
      uVar36 = CONCAT44(*param_3,param_3[1]);
    }
    iVar5 = (int)uVar36;
    if (!bVar34 || (int)((ulonglong)uVar36 >> 0x20) == iVar5) goto switchD_001cd01a_caseD_4d;
    uVar20 = *(uint *)(iVar5 + -8);
    iVar17 = *(int *)(iVar5 + -4);
    iVar32 = iVar5 + -0x18;
    if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
      iVar17 = iVar5 + -0xb;
      uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
    }
    puVar10 = (undefined4 *)FUN_001cb080(iVar32,iVar17,uVar20);
    local_60 = (byte *)*puVar10;
    local_5c = puVar10[1];
    local_58 = (byte *)puVar10[2];
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    puVar10 = (undefined4 *)FUN_001caf2a(&local_60,0,"typeid(",7);
    local_38 = (byte *)*puVar10;
    local_34 = puVar10[1];
    local_30 = (byte *)puVar10[2];
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    puVar10 = (undefined4 *)FUN_001cb080(&local_38,&DAT_0022045d,1);
    uVar1 = *(undefined1 *)puVar10;
    __aeabi_memcpy(&local_70,(int)puVar10 + 1,7);
    pbVar12 = (byte *)puVar10[2];
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    local_50 = (byte *)CONCAT31(local_50._1_3_,uVar1);
    __aeabi_memcpy((uint)&local_50 | 1,&local_70,7);
    local_6c = (uint)local_6c._3_1_ << 0x18;
    local_70 = (byte *)0x0;
    local_48 = pbVar12;
LAB_001cf84c:
    local_3c = (void *)0x0;
    local_40 = 0;
    local_44 = (byte *)0x0;
    FUN_001d0d6c(iVar32,&local_50);
    if (((uint)local_44 & 1) != 0) {
      free(local_3c);
    }
    if (((uint)local_50 & 1) != 0) {
      free(local_48);
    }
    pbVar12 = local_58;
    pbVar33 = local_60;
    if (((uint)local_38 & 1) != 0) {
      free(local_30);
      pbVar12 = local_58;
      pbVar33 = local_60;
    }
joined_r0x001cf88c:
    if (((uint)pbVar33 & 1) != 0) {
      free(pbVar12);
    }
    goto switchD_001cd01a_caseD_4d;
  default:
    if (8 < *pbVar12 - 0x31) goto switchD_001cd01a_caseD_4d;
code_r0x001d23a4:
    if (2 < (int)param_2 - (int)param_1) {
      bVar34 = false;
      if ((*param_1 == 0x67) && (param_1[1] == 0x73)) {
        param_1 = param_1 + 2;
        bVar34 = true;
      }
      pbVar12 = (byte *)FUN_001d2fb0(param_1,param_2,param_3);
      if (pbVar12 == param_1) {
        if (2 < (int)param_2 - (int)param_1) {
          bVar11 = *param_1;
          bVar35 = bVar11 == 0x73;
          if (bVar35) {
            bVar11 = param_1[1];
          }
          if (bVar35 && bVar11 == 0x72) {
            pbVar12 = param_1 + 2;
            if (*pbVar12 == 0x4e) {
              pbVar12 = (byte *)FUN_001d31dc(param_1 + 3,param_2,param_3);
              if (pbVar12 == param_1 + 3 || pbVar12 == param_2) goto LAB_001d2ae2;
              pbVar33 = (byte *)FUN_001cb15c(pbVar12,param_2,param_3);
              if (pbVar33 != pbVar12) {
                iVar5 = param_3[1];
                if ((uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
                uVar20 = *(uint *)(iVar5 + -8);
                iVar17 = *(int *)(iVar5 + -4);
                if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                  iVar17 = iVar5 + -0xb;
                  uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                }
                local_4c = pbVar33;
                puVar9 = (uint *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                local_38 = (byte *)*puVar9;
                local_34 = puVar9[1];
                local_30 = (byte *)puVar9[2];
                *puVar9 = 0;
                puVar9[1] = 0;
                puVar9[2] = 0;
                pbVar31 = (byte *)param_3[1];
                pbVar12 = pbVar31 + -0x18;
                local_50 = pbVar31;
                do {
                  param_3[1] = (int)(pbVar31 + -0x18);
                  if ((pbVar31[-0xc] & 1) != 0) {
                    free(*(void **)(pbVar31 + -4));
                  }
                  if ((pbVar31[-0x18] & 1) != 0) {
                    free(*(void **)(pbVar31 + -0x10));
                  }
                  pbVar31 = (byte *)param_3[1];
                } while (pbVar31 != pbVar12);
                pbVar12 = local_30;
                if (((uint)local_38 & 1) == 0) {
                  pbVar12 = (byte *)((uint)&local_38 | 1);
                  local_34 = (uint)local_38 >> 1 & 0x7f;
                }
                FUN_001cb080(local_50 + -0x30,pbVar12,local_34);
                local_50 = (byte *)((uint)local_38 & 1);
                if (local_4c == param_2) {
                  local_4c = local_30;
                  iVar17 = param_3[1];
                  iVar5 = iVar17 + -0x18;
                  do {
                    param_3[1] = iVar17 + -0x18;
                    if ((*(byte *)(iVar17 + -0xc) & 1) != 0) {
                      free(*(void **)(iVar17 + -4));
                    }
                    if ((*(byte *)(iVar17 + -0x18) & 1) != 0) {
                      free(*(void **)(iVar17 + -0x10));
                    }
                    iVar17 = param_3[1];
                  } while (iVar17 != iVar5);
                  bVar34 = true;
                  local_30 = local_4c;
                }
                else {
                  bVar34 = false;
                }
                if (local_50 != (byte *)0x0) {
                  free(local_30);
                }
                pbVar12 = pbVar33;
                if (bVar34) goto LAB_001d2ae2;
              }
              while (*pbVar12 != 0x45) {
                local_4c = (byte *)FUN_001d4cdc(pbVar12,param_2,param_3);
                if ((local_4c == pbVar12 || local_4c == param_2) ||
                   (iVar5 = param_3[1], (uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2))
                goto LAB_001d2ae2;
                uVar20 = *(uint *)(iVar5 + -8);
                iVar17 = *(int *)(iVar5 + -4);
                if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                  iVar17 = iVar5 + -0xb;
                  uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                }
                puVar9 = (uint *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                local_38 = (byte *)*puVar9;
                local_30 = (byte *)puVar9[2];
                *puVar9 = 0;
                puVar9[1] = 0;
                puVar9[2] = 0;
                iVar17 = param_3[1];
                iVar5 = iVar17;
                do {
                  param_3[1] = iVar5 + -0x18;
                  if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar5 + -4));
                  }
                  if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar5 + -0x10));
                  }
                  iVar5 = param_3[1];
                } while (iVar5 != iVar17 + -0x18);
                puVar9 = (uint *)FUN_001caf2a(&local_38,0,&DAT_0022220f,2);
                uVar23 = *puVar9;
                uVar20 = puVar9[1];
                pvVar30 = (void *)puVar9[2];
                *puVar9 = 0;
                puVar9[1] = 0;
                puVar9[2] = 0;
                pvVar18 = pvVar30;
                if ((uVar23 & 1) == 0) {
                  pvVar18 = (void *)((uint)&local_48 | 1);
                  uVar20 = uVar23 >> 1 & 0x7f;
                }
                FUN_001cb080(iVar17 + -0x30,pvVar18,uVar20);
                if ((uVar23 & 1) != 0) {
                  free(pvVar30);
                }
                pbVar12 = local_4c;
                if (((uint)local_38 & 1) != 0) {
                  free(local_30);
                }
              }
              pbVar33 = (byte *)FUN_001d2fb0(pbVar12 + 1,param_2,param_3);
              if (pbVar33 == pbVar12 + 1) {
                iVar5 = param_3[1];
                if (*param_3 != iVar5) {
                  iVar17 = iVar5 + -0x18;
                  do {
                    param_3[1] = iVar5 + -0x18;
                    if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                      free(*(void **)(iVar5 + -4));
                    }
                    if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                      free(*(void **)(iVar5 + -0x10));
                    }
                    iVar5 = param_3[1];
                  } while (iVar5 != iVar17);
                }
                goto LAB_001d2ae2;
              }
              iVar5 = param_3[1];
              if ((uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
              uVar20 = *(uint *)(iVar5 + -8);
              iVar17 = *(int *)(iVar5 + -4);
              if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                iVar17 = iVar5 + -0xb;
                uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
              }
              puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
              local_38 = (byte *)*puVar10;
              local_30 = (byte *)puVar10[2];
              *puVar10 = 0;
              puVar10[1] = 0;
              puVar10[2] = 0;
              iVar17 = param_3[1];
              iVar5 = iVar17;
              do {
                param_3[1] = iVar5 + -0x18;
                if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar5 + -4));
                }
                if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar5 + -0x10));
                }
                iVar5 = param_3[1];
              } while (iVar5 != iVar17 + -0x18);
            }
            else {
              pbVar33 = (byte *)FUN_001d31dc(pbVar12,param_2,param_3);
              if (pbVar33 == pbVar12) {
                pbVar33 = (byte *)FUN_001d4cdc(pbVar12,param_2,param_3);
                if (pbVar33 == pbVar12 || pbVar33 == param_2) goto LAB_001d2ae2;
                if (bVar34) {
                  if (*param_3 == param_3[1]) goto LAB_001d2ae2;
                  FUN_001caf2a(param_3[1] + -0x18,0,&DAT_0022220f,2);
                }
                bVar11 = *pbVar33;
                while (bVar11 != 0x45) {
                  local_4c = (byte *)FUN_001d4cdc(pbVar33,param_2,param_3);
                  if ((local_4c == pbVar33 || local_4c == param_2) ||
                     (iVar5 = param_3[1], (uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2))
                  goto LAB_001d2ae2;
                  uVar20 = *(uint *)(iVar5 + -8);
                  iVar17 = *(int *)(iVar5 + -4);
                  if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                    iVar17 = iVar5 + -0xb;
                    uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                  }
                  puVar9 = (uint *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                  local_38 = (byte *)*puVar9;
                  local_30 = (byte *)puVar9[2];
                  *puVar9 = 0;
                  puVar9[1] = 0;
                  puVar9[2] = 0;
                  iVar17 = param_3[1];
                  iVar5 = iVar17;
                  do {
                    param_3[1] = iVar5 + -0x18;
                    if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                      free(*(void **)(iVar5 + -4));
                    }
                    if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                      free(*(void **)(iVar5 + -0x10));
                    }
                    iVar5 = param_3[1];
                  } while (iVar5 != iVar17 + -0x18);
                  puVar9 = (uint *)FUN_001caf2a(&local_38,0,&DAT_0022220f,2);
                  uVar23 = *puVar9;
                  uVar20 = puVar9[1];
                  pvVar30 = (void *)puVar9[2];
                  *puVar9 = 0;
                  puVar9[1] = 0;
                  puVar9[2] = 0;
                  pvVar18 = pvVar30;
                  if ((uVar23 & 1) == 0) {
                    pvVar18 = (void *)((uint)&local_48 | 1);
                    uVar20 = uVar23 >> 1 & 0x7f;
                  }
                  FUN_001cb080(iVar17 + -0x30,pvVar18,uVar20);
                  if ((uVar23 & 1) != 0) {
                    free(pvVar30);
                  }
                  if (((uint)local_38 & 1) != 0) {
                    free(local_30);
                  }
                  pbVar33 = local_4c;
                  bVar11 = *local_4c;
                }
                pbVar12 = (byte *)FUN_001d2fb0(pbVar33 + 1,param_2,param_3);
                if (pbVar12 == pbVar33 + 1) {
                  iVar5 = param_3[1];
                  if (*param_3 != iVar5) {
                    iVar17 = iVar5 + -0x18;
                    do {
                      param_3[1] = iVar5 + -0x18;
                      if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                        free(*(void **)(iVar5 + -4));
                      }
                      if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                        free(*(void **)(iVar5 + -0x10));
                      }
                      iVar5 = param_3[1];
                    } while (iVar5 != iVar17);
                  }
                  goto LAB_001d2ae2;
                }
                iVar5 = param_3[1];
                if ((uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
                uVar20 = *(uint *)(iVar5 + -8);
                iVar17 = *(int *)(iVar5 + -4);
                if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                  iVar17 = iVar5 + -0xb;
                  uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                }
                puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                local_38 = (byte *)*puVar10;
                local_30 = (byte *)puVar10[2];
                *puVar10 = 0;
                puVar10[1] = 0;
                puVar10[2] = 0;
                iVar17 = param_3[1];
                iVar5 = iVar17;
                do {
                  param_3[1] = iVar5 + -0x18;
                  if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar5 + -4));
                  }
                  if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar5 + -0x10));
                  }
                  iVar5 = param_3[1];
                } while (iVar5 != iVar17 + -0x18);
              }
              else {
                pbVar12 = (byte *)FUN_001cb15c(pbVar33,param_2,param_3);
                if (pbVar12 != pbVar33) {
                  iVar5 = param_3[1];
                  if ((uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
                  uVar20 = *(uint *)(iVar5 + -8);
                  iVar17 = *(int *)(iVar5 + -4);
                  if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                    iVar17 = iVar5 + -0xb;
                    uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                  }
                  puVar9 = (uint *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                  local_38 = (byte *)*puVar9;
                  local_34 = puVar9[1];
                  local_30 = (byte *)puVar9[2];
                  *puVar9 = 0;
                  puVar9[1] = 0;
                  puVar9[2] = 0;
                  pbVar31 = (byte *)param_3[1];
                  pbVar33 = pbVar31 + -0x18;
                  local_4c = pbVar31;
                  do {
                    param_3[1] = (int)(pbVar31 + -0x18);
                    if ((pbVar31[-0xc] & 1) != 0) {
                      free(*(void **)(pbVar31 + -4));
                    }
                    if ((pbVar31[-0x18] & 1) != 0) {
                      free(*(void **)(pbVar31 + -0x10));
                    }
                    pbVar31 = (byte *)param_3[1];
                  } while (pbVar31 != pbVar33);
                  pbVar33 = local_30;
                  if (((uint)local_38 & 1) == 0) {
                    pbVar33 = (byte *)((uint)&local_38 | 1);
                    local_34 = (uint)local_38 >> 1 & 0x7f;
                  }
                  FUN_001cb080(local_4c + -0x30,pbVar33,local_34);
                  pbVar33 = pbVar12;
                  if (((uint)local_38 & 1) != 0) {
                    free(local_30);
                  }
                }
                pbVar12 = (byte *)FUN_001d2fb0(pbVar33,param_2,param_3);
                if (pbVar12 == pbVar33) {
                  iVar5 = param_3[1];
                  if (*param_3 != iVar5) {
                    iVar17 = iVar5 + -0x18;
                    do {
                      param_3[1] = iVar5 + -0x18;
                      if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                        free(*(void **)(iVar5 + -4));
                      }
                      if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                        free(*(void **)(iVar5 + -0x10));
                      }
                      iVar5 = param_3[1];
                    } while (iVar5 != iVar17);
                  }
                  goto LAB_001d2ae2;
                }
                iVar5 = param_3[1];
                if ((uint)((iVar5 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
                uVar20 = *(uint *)(iVar5 + -8);
                iVar17 = *(int *)(iVar5 + -4);
                if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
                  iVar17 = iVar5 + -0xb;
                  uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
                }
                puVar10 = (undefined4 *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
                local_38 = (byte *)*puVar10;
                local_30 = (byte *)puVar10[2];
                *puVar10 = 0;
                puVar10[1] = 0;
                puVar10[2] = 0;
                iVar17 = param_3[1];
                iVar5 = iVar17;
                do {
                  param_3[1] = iVar5 + -0x18;
                  if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar5 + -4));
                  }
                  if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar5 + -0x10));
                  }
                  iVar5 = param_3[1];
                } while (iVar5 != iVar17 + -0x18);
              }
            }
            puVar9 = (uint *)FUN_001caf2a(&local_38,0,&DAT_0022220f,2);
            uVar23 = *puVar9;
            uVar20 = puVar9[1];
            pvVar30 = (void *)puVar9[2];
            *puVar9 = 0;
            puVar9[1] = 0;
            puVar9[2] = 0;
            pvVar18 = pvVar30;
            if ((uVar23 & 1) == 0) {
              pvVar18 = (void *)((uint)&local_48 | 1);
              uVar20 = uVar23 >> 1 & 0x7f;
            }
            FUN_001cb080(iVar17 + -0x30,pvVar18,uVar20);
            if ((uVar23 & 1) != 0) {
              free(pvVar30);
            }
            if (((byte)local_38 & 1) != 0) {
              free(local_30);
            }
          }
        }
      }
      else if ((bVar34) && (*param_3 != param_3[1])) {
        FUN_001caf2a(param_3[1] + -0x18,0,&DAT_0022220f,2);
      }
    }
LAB_001d2ae2:
    if (__stack_chk_guard - local_28 == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
LAB_001cf676:
  if (((uint)local_50 & 1) != 0) {
    free(local_48);
  }
switchD_001cd01a_caseD_4d:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
  while ((pbVar33 = (byte *)FUN_001ccfb8(pbVar12,param_2,param_3), pbVar33 != pbVar12 &&
         (pbVar12 = pbVar33, pbVar33 != param_2))) {
LAB_001cfb42:
    if (*pbVar12 == 0x45) {
      local_30 = (byte *)0x0;
      local_38 = (byte *)0x0;
      local_34 = 0;
      piVar4 = param_3 + 1;
      iVar5 = *piVar4;
      if (*param_3 != iVar5) {
        uVar20 = *(uint *)(iVar5 + -8);
        iVar17 = *(int *)(iVar5 + -4);
        if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
          iVar17 = iVar5 + -0xb;
          uVar20 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
        }
        pbVar12 = (byte *)FUN_001cb080(iVar5 + -0x18,iVar17,uVar20);
        bVar3 = *pbVar12;
        local_f0 = (void *)(uint)bVar3;
        __aeabi_memcpy(&local_50,pbVar12 + 1,7);
        pbVar33 = *(byte **)(pbVar12 + 8);
        pbVar12[0] = 0;
        pbVar12[1] = 0;
        pbVar12[2] = 0;
        pbVar12[3] = 0;
        pbVar12[4] = 0;
        pbVar12[5] = 0;
        pbVar12[6] = 0;
        pbVar12[7] = 0;
        pbVar12[8] = 0;
        pbVar12[9] = 0;
        pbVar12[10] = 0;
        pbVar12[0xb] = 0;
        iVar5 = *piVar4;
        local_38 = (byte *)CONCAT31(local_38._1_3_,bVar3);
        __aeabi_memcpy((uint)&local_38 | 1,&local_50,7);
        local_e4 = iVar5 + -0x18;
        local_30 = pbVar33;
        do {
          *piVar4 = iVar5 + -0x18;
          if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
            free(*(void **)(iVar5 + -4));
          }
          if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
            free(*(void **)(iVar5 + -0x10));
          }
          iVar5 = param_3[1];
        } while (iVar5 != local_e4);
        bVar2 = true;
LAB_001d041a:
        local_e0 = (byte *)(param_3 + 1);
        if (*param_3 != local_e4) {
          uVar20 = *(uint *)(local_e4 + -8);
          iVar5 = *(int *)(local_e4 + -4);
          if ((*(byte *)(local_e4 + -0xc) & 1) == 0) {
            iVar5 = local_e4 + -0xb;
            uVar20 = (uint)(*(byte *)(local_e4 + -0xc) >> 1);
          }
          puVar10 = (undefined4 *)FUN_001cb080(local_e4 + -0x18,iVar5,uVar20);
          local_60 = (byte *)*puVar10;
          local_5c = puVar10[1];
          local_58 = (byte *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          iVar17 = *(int *)local_e0;
          iVar5 = iVar17;
          do {
            *(byte **)local_e0 = (byte *)(iVar5 + -0x18);
            if ((*(byte *)(iVar5 + -0xc) & 1) != 0) {
              free(*(void **)(iVar5 + -4));
            }
            if ((*(byte *)(iVar5 + -0x18) & 1) != 0) {
              free(*(void **)(iVar5 + -0x10));
            }
            iVar5 = *(int *)local_e0;
          } while (iVar5 != iVar17 + -0x18);
          local_68 = (void *)0x0;
          local_70 = (byte *)0x0;
          local_6c = 0;
          if (bVar35) {
            if (*param_3 != iVar17 + -0x18) {
              uVar20 = *(uint *)(iVar17 + -0x20);
              iVar5 = *(int *)(iVar17 + -0x1c);
              if ((*(byte *)(iVar17 + -0x24) & 1) == 0) {
                iVar5 = iVar17 + -0x23;
                uVar20 = (uint)(*(byte *)(iVar17 + -0x24) >> 1);
              }
              pbVar12 = (byte *)FUN_001cb080(iVar17 + -0x30,iVar5,uVar20);
              bVar3 = *pbVar12;
              __aeabi_memcpy(&local_50,pbVar12 + 1,7);
              local_f0 = *(void **)(pbVar12 + 8);
              pbVar12[0] = 0;
              pbVar12[1] = 0;
              pbVar12[2] = 0;
              pbVar12[3] = 0;
              pbVar12[4] = 0;
              pbVar12[5] = 0;
              pbVar12[6] = 0;
              pbVar12[7] = 0;
              pbVar12[8] = 0;
              pbVar12[9] = 0;
              pbVar12[10] = 0;
              pbVar12[0xb] = 0;
              iVar17 = *(int *)local_e0;
              local_70 = (byte *)CONCAT31(local_70._1_3_,bVar3);
              __aeabi_memcpy((uint)&local_70 | 1,&local_50,7);
              iVar5 = iVar17 + -0x18;
              local_68 = local_f0;
              do {
                *(byte **)local_e0 = (byte *)(iVar17 + -0x18);
                if ((*(byte *)(iVar17 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar17 + -4));
                }
                if ((*(byte *)(iVar17 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar17 + -0x10));
                }
                iVar17 = *(int *)local_e0;
              } while (iVar17 != iVar5);
              bVar3 = bVar3 & 1;
              goto LAB_001d057a;
            }
          }
          else {
            local_f0 = (void *)0x0;
            bVar3 = 0;
LAB_001d057a:
            local_78 = (void *)0x0;
            local_80 = 0;
            local_7c = 0;
            if (bVar34) {
              FUN_001ccf02(&local_80,&DAT_0022220f,2);
            }
            if (bVar11 == 0x61) {
              uVar19 = 3;
              puVar14 = &DAT_00222329;
            }
            else {
              uVar19 = 1;
              puVar14 = &DAT_0021f760;
            }
            FUN_001cb080(&local_80,puVar14,uVar19);
            if (bVar35) {
              FUN_001cbc00(&local_90,&DAT_00222248,&local_70);
              puVar9 = (uint *)FUN_001cb080(&local_90,&DAT_002222d2,2);
              local_50 = (byte *)*puVar9;
              local_4c = (byte *)puVar9[1];
              pbVar27 = (byte *)puVar9[2];
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar9[2] = 0;
              uVar20 = (uint)local_50 & 1;
              pbVar33 = local_4c;
              pbVar12 = pbVar27;
              if (((uint)local_50 & 1) == 0) {
                pbVar12 = (byte *)((uint)&local_50 | 1);
                pbVar33 = (byte *)((uint)local_50 >> 1 & 0x7f);
              }
              local_48 = pbVar27;
              FUN_001cb080(&local_80,pbVar12,pbVar33);
              if (uVar20 != 0) {
                free(pbVar27);
              }
              if (((uint)local_90 & 1) != 0) {
                free(local_88);
              }
            }
            uVar20 = local_5c;
            pbVar12 = local_58;
            if (((uint)local_60 & 1) == 0) {
              pbVar12 = (byte *)((uint)&local_60 | 1);
              uVar20 = (uint)local_60 >> 1 & 0x7f;
            }
            FUN_001cb080(&local_80,pbVar12,uVar20);
            if (bVar2) {
              FUN_001cbc00(&local_90,&DAT_0022045a,&local_38);
              puVar9 = (uint *)FUN_001cb080(&local_90,&DAT_0022045d,1);
              local_50 = (byte *)*puVar9;
              local_4c = (byte *)puVar9[1];
              pbVar27 = (byte *)puVar9[2];
              *puVar9 = 0;
              puVar9[1] = 0;
              puVar9[2] = 0;
              uVar20 = (uint)local_50 & 1;
              pbVar33 = local_4c;
              pbVar12 = pbVar27;
              if (((uint)local_50 & 1) == 0) {
                pbVar12 = (byte *)((uint)&local_50 | 1);
                pbVar33 = (byte *)((uint)local_50 >> 1 & 0x7f);
              }
              local_48 = pbVar27;
              FUN_001cb080(&local_80,pbVar12,pbVar33);
              if (uVar20 != 0) {
                free(pbVar27);
              }
              if (((uint)local_90 & 1) != 0) {
                free(local_88);
              }
            }
            bVar11 = (byte)local_80;
            __aeabi_memcpy(&local_d0,(uint)&local_80 | 1,7);
            pvVar18 = local_78;
            local_78 = (void *)0x0;
            local_80 = 0;
            local_7c = 0;
            __aeabi_memcpy(&local_90,&local_d0,7);
            local_cc = (uint)local_cc._3_1_ << 0x18;
            local_bc = (uint)local_bc._3_1_ << 0x18;
            local_d0 = 0;
            local_c0 = 0;
            pbVar12 = (byte *)param_3[1];
            if (pbVar12 < (byte *)param_3[2]) {
              *pbVar12 = bVar11;
              __aeabi_memcpy(pbVar12 + 1,&local_90,7);
              *(void **)(pbVar12 + 8) = pvVar18;
              local_8c = (uint)local_8c._3_1_ << 0x18;
              local_90 = (byte *)0x0;
              pbVar12[0xc] = 0;
              __aeabi_memcpy(pbVar12 + 0xd,&local_c0,7);
              pbVar12[0x14] = 0;
              pbVar12[0x15] = 0;
              pbVar12[0x16] = 0;
              pbVar12[0x17] = 0;
              local_bc = local_bc & 0xff000000;
              local_c0 = 0;
              *(int *)local_e0 = *(int *)local_e0 + 0x18;
            }
            else {
              iVar5 = param_3[2] - *param_3 >> 3;
              iVar17 = ((int)pbVar12 - *param_3 >> 3) * -0x55555555;
              if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
                pbVar12 = (byte *)(iVar17 + 1);
                pbVar31 = (byte *)(iVar5 * 0x55555556);
                if (pbVar31 < pbVar12) {
                  pbVar31 = pbVar12;
                }
              }
              FUN_001ccdd4(&local_50,pbVar31,iVar17,param_3 + 3);
              pbVar12 = local_48;
              *local_48 = bVar11;
              __aeabi_memcpy(local_48 + 1,&local_90,7);
              *(void **)(pbVar12 + 8) = pvVar18;
              local_8c = (uint)local_8c._3_1_ << 0x18;
              local_90 = (byte *)0x0;
              pbVar12[0xc] = 0;
              __aeabi_memcpy(pbVar12 + 0xd,&local_c0,7);
              pbVar12[0x14] = 0;
              pbVar12[0x15] = 0;
              pbVar12[0x16] = 0;
              pbVar12[0x17] = 0;
              local_48 = local_48 + 0x18;
              local_bc = local_bc & 0xff000000;
              local_c0 = 0;
              FUN_001cce32(param_3,&local_50);
              FUN_001cceae(&local_50);
            }
            if ((local_80 & 1) != 0) {
              free(local_78);
            }
            if (bVar3 != 0) {
              free(local_f0);
            }
          }
          if (((uint)local_60 & 1) != 0) {
            free(local_58);
          }
          local_f0 = (void *)((uint)local_38 & 0xff);
        }
        if (((uint)local_f0 & 1) != 0) {
          free(local_30);
        }
      }
      break;
    }
  }
  goto switchD_001cd01a_caseD_4d;
}

// ===== FUN_001d0d6c  @0x001d0d6c  (520 bytes)
void FUN_001d0d6c(uint *param_1,uint *param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  
  if ((*param_1 & 1) == 0) {
    *(undefined2 *)param_1 = 0;
  }
  else {
    *(undefined1 *)param_1[2] = 0;
    param_1[1] = 0;
    uVar6 = (uint)(byte)*param_1;
    if (((byte)*param_1 & 1) == 0) {
      uVar7 = 10;
    }
    else {
      uVar6 = *param_1;
      uVar7 = (uVar6 & 0xfffffffe) - 1;
    }
    if ((uVar6 & 1) == 0) {
      uVar9 = (uVar6 & 0xff) >> 1;
      if ((uVar6 & 0xff) < 0x16) {
        uVar5 = 10;
      }
      else {
        uVar5 = (uVar9 + 0x10 & 0xf0) - 1;
      }
      bVar2 = true;
    }
    else {
      uVar5 = 10;
      uVar9 = 0;
      bVar2 = false;
    }
    if (uVar5 != uVar7) {
      if (uVar5 == 10) {
        pbVar8 = (byte *)param_1[2];
        if (bVar2) {
          __aeabi_memcpy((byte *)((int)param_1 + 1),pbVar8,((uVar6 & 0xfe) >> 1) + 1);
        }
        else {
          *(byte *)((int)param_1 + 1) = *pbVar8;
        }
        free(pbVar8);
        *(byte *)param_1 = (byte)(uVar9 << 1);
      }
      else {
        puVar3 = malloc(uVar5 + 1);
        if ((uVar7 < uVar5) || (puVar3 != (undefined1 *)0x0)) {
          if (bVar2) {
            __aeabi_memcpy(puVar3,(byte *)((int)param_1 + 1),((uVar6 & 0xfe) >> 1) + 1);
          }
          else {
            puVar4 = (undefined1 *)param_1[2];
            *puVar3 = *puVar4;
            free(puVar4);
          }
          *param_1 = uVar5 + 1 | 1;
          param_1[1] = uVar9;
          param_1[2] = (uint)puVar3;
        }
      }
    }
  }
  uVar6 = param_2[1];
  uVar7 = param_2[2];
  *param_1 = *param_2;
  param_1[1] = uVar6;
  param_1[2] = uVar7;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  puVar1 = param_1 + 3;
  if ((*puVar1 & 1) == 0) {
    *(undefined2 *)puVar1 = 0;
  }
  else {
    *(undefined1 *)param_1[5] = 0;
    param_1[4] = 0;
    uVar6 = (uint)(byte)param_1[3];
    if (((byte)param_1[3] & 1) == 0) {
      uVar7 = 10;
    }
    else {
      uVar6 = *puVar1;
      uVar7 = (uVar6 & 0xfffffffe) - 1;
    }
    if ((uVar6 & 1) == 0) {
      uVar5 = (uVar6 & 0xff) >> 1;
      if ((uVar6 & 0xff) < 0x16) {
        uVar9 = 10;
      }
      else {
        uVar9 = (uVar5 + 0x10 & 0xf0) - 1;
      }
      bVar2 = true;
    }
    else {
      uVar9 = 10;
      uVar5 = 0;
      bVar2 = false;
    }
    if (uVar9 != uVar7) {
      if (uVar9 == 10) {
        pbVar8 = (byte *)param_1[5];
        if (bVar2) {
          __aeabi_memcpy((byte *)((int)param_1 + 0xd),pbVar8,((uVar6 & 0xfe) >> 1) + 1);
        }
        else {
          *(byte *)((int)param_1 + 0xd) = *pbVar8;
        }
        free(pbVar8);
        *(byte *)puVar1 = (byte)(uVar5 << 1);
      }
      else {
        puVar3 = malloc(uVar9 + 1);
        if ((uVar7 < uVar9) || (puVar3 != (undefined1 *)0x0)) {
          if (bVar2) {
            __aeabi_memcpy(puVar3,(byte *)((int)param_1 + 0xd),((uVar6 & 0xfe) >> 1) + 1);
          }
          else {
            puVar4 = (undefined1 *)param_1[5];
            *puVar3 = *puVar4;
            free(puVar4);
          }
          param_1[3] = uVar9 + 1 | 1;
          param_1[4] = uVar5;
          param_1[5] = (uint)puVar3;
        }
      }
    }
  }
  uVar6 = param_2[4];
  uVar7 = param_2[5];
  *puVar1 = param_2[3];
  param_1[4] = uVar6;
  param_1[5] = uVar7;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return;
}

// ===== FUN_001d1a3c  @0x001d1a3c  (928 bytes)
void FUN_001d1a3c(char *param_1,char *param_2,int *param_3)

{
  undefined1 uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  char cVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  char *pcVar12;
  char *pcVar13;
  undefined4 uVar14;
  uint local_6c;
  uint local_68;
  uint uStack_64;
  char *local_60;
  undefined1 auStack_5c [8];
  undefined1 *local_54;
  undefined4 local_48;
  undefined2 local_44;
  undefined1 local_42;
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (((int)param_2 - (int)param_1 < 3) || (*param_1 != 'f')) goto LAB_001d1dc2;
  if (param_1[1] == 'L') {
    pcVar2 = (char *)FUN_001caeea(param_1 + 2,param_2);
    if ((pcVar2 == param_2) || (*pcVar2 != 'p')) goto LAB_001d1dc2;
    pcVar12 = pcVar2 + 1;
    pcVar3 = param_2;
    if (pcVar12 != param_2) {
      cVar6 = *pcVar12;
      if (cVar6 == 'r') {
        pcVar12 = pcVar2 + 2;
        cVar6 = *pcVar12;
      }
      if (cVar6 == 'V') {
        pcVar12 = pcVar12 + 1;
        cVar6 = *pcVar12;
      }
      pcVar3 = pcVar12;
      if (cVar6 == 'K') {
        pcVar3 = pcVar12 + 1;
      }
    }
    pcVar2 = (char *)FUN_001caeea(pcVar3,param_2);
    if ((pcVar2 == param_2) || (*pcVar2 != '_')) goto LAB_001d1dc2;
    uVar11 = (int)pcVar2 - (int)pcVar3;
    local_60 = (char *)0x0;
    local_68 = 0;
    uStack_64 = 0;
    if (uVar11 < 0xb) {
      local_68 = (uint)(byte)((char)uVar11 * '\x02');
      pcVar12 = (char *)((uint)&local_68 | 1);
    }
    else {
      uVar9 = uVar11 + 0x10 & 0xfffffff0;
      pcVar12 = malloc(uVar9);
      local_68 = uVar9 | 1;
      uStack_64 = uVar11;
      local_60 = pcVar12;
    }
    pcVar7 = pcVar12;
    if (pcVar3 != pcVar2) {
      do {
        pcVar13 = pcVar3 + 1;
        *pcVar7 = *pcVar3;
        pcVar7 = pcVar7 + 1;
        pcVar3 = pcVar13;
      } while (pcVar2 != pcVar13);
      pcVar12 = pcVar12 + uVar11;
    }
    *pcVar12 = '\0';
    puVar4 = (undefined4 *)FUN_001caf2a(&local_68,0,&DAT_002222cf,2);
    uVar1 = *(undefined1 *)puVar4;
    __aeabi_memcpy(&local_48,(int)puVar4 + 1,7);
    uVar14 = puVar4[2];
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    __aeabi_memcpy(&local_30,&local_48,7);
    local_42 = 0;
    local_44 = 0;
    local_32 = 0;
    local_34 = 0;
    local_48 = 0;
    local_38 = 0;
    puVar10 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar10) {
      iVar5 = param_3[2] - *param_3 >> 3;
      iVar8 = ((int)puVar10 - *param_3 >> 3) * -0x55555555;
      uVar11 = 0xaaaaaaa;
      if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
        uVar9 = iVar8 + 1;
        uVar11 = iVar5 * 0x55555556;
        if (uVar11 < uVar9) {
          uVar11 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_5c,uVar11,iVar8,param_3 + 3);
      puVar10 = local_54;
      *local_54 = uVar1;
      __aeabi_memcpy(local_54 + 1,&local_30,7);
      *(undefined4 *)(puVar10 + 8) = uVar14;
      goto LAB_001d1d74;
    }
    *puVar10 = uVar1;
    __aeabi_memcpy(puVar10 + 1,&local_30,7);
    *(undefined4 *)(puVar10 + 8) = uVar14;
    local_2a = 0;
    local_2c = 0;
    local_30 = 0;
    puVar10[0xc] = 0;
    __aeabi_memcpy(puVar10 + 0xd,&local_38,7);
    *(undefined4 *)(puVar10 + 0x14) = 0;
LAB_001d1d18:
    local_32 = 0;
    local_34 = 0;
    local_38 = 0;
    param_3[1] = param_3[1] + 0x18;
  }
  else {
    if (param_1[1] != 'p') goto LAB_001d1dc2;
    pcVar2 = param_1 + 2;
    pcVar12 = param_2;
    if (pcVar2 != param_2) {
      cVar6 = *pcVar2;
      if (cVar6 == 'r') {
        pcVar2 = param_1 + 3;
        cVar6 = *pcVar2;
      }
      if (cVar6 == 'V') {
        pcVar2 = pcVar2 + 1;
        cVar6 = *pcVar2;
      }
      pcVar12 = pcVar2;
      if (cVar6 == 'K') {
        pcVar12 = pcVar2 + 1;
      }
    }
    pcVar2 = (char *)FUN_001caeea(pcVar12,param_2);
    if ((pcVar2 == param_2) || (*pcVar2 != '_')) goto LAB_001d1dc2;
    uVar11 = (int)pcVar2 - (int)pcVar12;
    local_60 = (char *)0x0;
    local_68 = 0;
    uStack_64 = 0;
    if (uVar11 < 0xb) {
      local_68 = (uint)(byte)((char)uVar11 * '\x02');
      pcVar3 = (char *)((uint)&local_68 | 1);
    }
    else {
      uVar9 = uVar11 + 0x10 & 0xfffffff0;
      pcVar3 = malloc(uVar9);
      local_68 = uVar9 | 1;
      uStack_64 = uVar11;
      local_60 = pcVar3;
    }
    local_6c = 0xaaaaaaa;
    pcVar7 = pcVar3;
    if (pcVar12 != pcVar2) {
      do {
        pcVar13 = pcVar12 + 1;
        *pcVar7 = *pcVar12;
        pcVar7 = pcVar7 + 1;
        pcVar12 = pcVar13;
      } while (pcVar2 != pcVar13);
      pcVar3 = pcVar3 + uVar11;
    }
    *pcVar3 = '\0';
    puVar4 = (undefined4 *)FUN_001caf2a(&local_68,0,&DAT_002222cf,2);
    uVar1 = *(undefined1 *)puVar4;
    __aeabi_memcpy(&local_40,(int)puVar4 + 1,7);
    uVar14 = puVar4[2];
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    __aeabi_memcpy(&local_30,&local_40,7);
    local_3a = 0;
    local_3c = 0;
    local_32 = 0;
    local_34 = 0;
    local_40 = 0;
    local_38 = 0;
    puVar10 = (undefined1 *)param_3[1];
    if (puVar10 < (undefined1 *)param_3[2]) {
      *puVar10 = uVar1;
      __aeabi_memcpy(puVar10 + 1,&local_30,7);
      *(undefined4 *)(puVar10 + 8) = uVar14;
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      puVar10[0xc] = 0;
      __aeabi_memcpy(puVar10 + 0xd,&local_38,7);
      *(undefined4 *)(puVar10 + 0x14) = 0;
      goto LAB_001d1d18;
    }
    iVar5 = param_3[2] - *param_3 >> 3;
    iVar8 = ((int)puVar10 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
      uVar11 = iVar8 + 1;
      local_6c = iVar5 * 0x55555556;
      if (local_6c < uVar11) {
        local_6c = uVar11;
      }
    }
    FUN_001ccdd4(auStack_5c,local_6c,iVar8,param_3 + 3);
    puVar10 = local_54;
    *local_54 = uVar1;
    __aeabi_memcpy(local_54 + 1,&local_30,7);
    *(undefined4 *)(puVar10 + 8) = uVar14;
LAB_001d1d74:
    local_2a = 0;
    local_2c = 0;
    local_30 = 0;
    puVar10[0xc] = 0;
    __aeabi_memcpy(puVar10 + 0xd,&local_38,7);
    *(undefined4 *)(puVar10 + 0x14) = 0;
    local_32 = 0;
    local_54 = local_54 + 0x18;
    local_34 = 0;
    local_38 = 0;
    FUN_001cce32(param_3,auStack_5c);
    FUN_001cceae(auStack_5c);
  }
  if ((local_68 & 1) != 0) {
    free(local_60);
  }
LAB_001d1dc2:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FUN_001d1dec  @0x001d1dec  (802 bytes)
void FUN_001d1dec(int param_1,undefined4 param_2,byte *param_3,int *param_4)

{
  byte *pbVar1;
  byte bVar2;
  void *__ptr;
  int iVar3;
  int iVar4;
  uint *puVar5;
  byte *pbVar6;
  void *pvVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  void *__ptr_00;
  byte local_a4 [8];
  void *local_9c;
  uint local_98;
  uint uStack_94;
  void *local_90;
  uint local_88;
  uint uStack_84;
  void *local_80;
  uint local_78;
  uint uStack_74;
  void *local_70;
  uint local_68;
  uint uStack_64;
  void *local_60;
  undefined1 auStack_5c [4];
  uint local_58;
  uint local_54;
  void *local_50;
  uint local_48;
  uint uStack_44;
  void *local_40;
  uint local_38;
  uint local_34;
  void *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  iVar3 = FUN_001ccfb8(param_1,param_2,param_4);
  if (iVar3 != param_1) {
    iVar4 = FUN_001ccfb8(iVar3,param_2,param_4);
    if (iVar4 == iVar3) {
      iVar3 = param_4[1];
      if (*param_4 != iVar3) {
        iVar4 = iVar3 + -0x18;
        do {
          param_4[1] = iVar3 + -0x18;
          if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
            free(*(void **)(iVar3 + -4));
          }
          if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
            free(*(void **)(iVar3 + -0x10));
          }
          iVar3 = param_4[1];
        } while (iVar3 != iVar4);
      }
    }
    else {
      iVar3 = param_4[1];
      if (1 < (uint)((iVar3 - *param_4 >> 3) * -0x55555555)) {
        uVar8 = *(uint *)(iVar3 + -8);
        iVar4 = *(int *)(iVar3 + -4);
        if ((*(byte *)(iVar3 + -0xc) & 1) == 0) {
          iVar4 = iVar3 + -0xb;
          uVar8 = (uint)(*(byte *)(iVar3 + -0xc) >> 1);
        }
        puVar5 = (uint *)FUN_001cb080(iVar3 + -0x18,iVar4,uVar8);
        local_38 = *puVar5;
        local_34 = puVar5[1];
        local_30 = (void *)puVar5[2];
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        iVar4 = param_4[1];
        iVar3 = iVar4;
        do {
          param_4[1] = iVar3 + -0x18;
          if ((*(byte *)(iVar3 + -0xc) & 1) != 0) {
            free(*(void **)(iVar3 + -4));
          }
          if ((*(byte *)(iVar3 + -0x18) & 1) != 0) {
            free(*(void **)(iVar3 + -0x10));
          }
          iVar3 = param_4[1];
        } while (iVar3 != iVar4 + -0x18);
        uVar8 = *(uint *)(iVar4 + -0x20);
        iVar3 = *(int *)(iVar4 + -0x1c);
        if ((*(byte *)(iVar4 + -0x24) & 1) == 0) {
          iVar3 = iVar4 + -0x23;
          uVar8 = (uint)(*(byte *)(iVar4 + -0x24) >> 1);
        }
        puVar5 = (uint *)FUN_001cb080(iVar4 + -0x30,iVar3,uVar8);
        local_48 = *puVar5;
        uStack_44 = puVar5[1];
        local_40 = (void *)puVar5[2];
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        iVar3 = param_4[1];
        pbVar1 = (byte *)(iVar3 + -0x18);
        if ((*pbVar1 & 1) == 0) {
          pbVar1[0] = 0;
          pbVar1[1] = 0;
        }
        else {
          **(undefined1 **)(iVar3 + -0x10) = 0;
          *(undefined4 *)(iVar3 + -0x14) = 0;
        }
        bVar2 = *param_3;
        uVar8 = *(uint *)(param_3 + 4);
        if ((bVar2 & 1) == 0) {
          uVar8 = (uint)(bVar2 >> 1);
        }
        if (uVar8 == 1) {
          pbVar6 = *(byte **)(param_3 + 8);
          if ((bVar2 & 1) == 0) {
            pbVar6 = param_3 + 1;
          }
          if (*pbVar6 == 0x3e) {
            FUN_001d530c(pbVar1,0x28);
          }
        }
        FUN_001cbc00(local_a4,&DAT_00222248,&local_48);
        puVar5 = (uint *)FUN_001cb080(local_a4,&DAT_002222d2,2);
        local_98 = *puVar5;
        uStack_94 = puVar5[1];
        local_90 = (void *)puVar5[2];
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        uVar8 = *(uint *)(param_3 + 4);
        pbVar6 = *(byte **)(param_3 + 8);
        if ((*param_3 & 1) == 0) {
          uVar8 = (uint)(*param_3 >> 1);
          pbVar6 = param_3 + 1;
        }
        puVar5 = (uint *)FUN_001cb080(&local_98,pbVar6,uVar8);
        local_88 = *puVar5;
        uStack_84 = puVar5[1];
        local_80 = (void *)puVar5[2];
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5 = (uint *)FUN_001cb080(&local_88,&DAT_0022045a,2);
        __ptr = local_30;
        local_78 = *puVar5;
        uStack_74 = puVar5[1];
        local_70 = (void *)puVar5[2];
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        uVar10 = local_38 & 1;
        uVar8 = local_34;
        pvVar7 = local_30;
        if ((local_38 & 1) == 0) {
          pvVar7 = (void *)((uint)&local_38 | 1);
          uVar8 = local_38 >> 1 & 0x7f;
        }
        puVar5 = (uint *)FUN_001cb080(&local_78,pvVar7,uVar8);
        local_68 = *puVar5;
        uStack_64 = puVar5[1];
        local_60 = (void *)puVar5[2];
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5 = (uint *)FUN_001cb080(&local_68,&DAT_0022045d,1,auStack_5c);
        local_58 = *puVar5;
        local_54 = puVar5[1];
        __ptr_00 = (void *)puVar5[2];
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        uVar8 = local_58 & 1;
        uVar9 = local_54;
        pvVar7 = __ptr_00;
        if ((local_58 & 1) == 0) {
          pvVar7 = (void *)((uint)&local_58 | 1);
          uVar9 = local_58 >> 1 & 0x7f;
        }
        local_50 = __ptr_00;
        FUN_001cb080(pbVar1,pvVar7,uVar9);
        if (uVar8 != 0) {
          free(__ptr_00);
        }
        if ((local_68 & 1) != 0) {
          free(local_60);
        }
        if ((local_78 & 1) != 0) {
          free(local_70);
        }
        if ((local_88 & 1) != 0) {
          free(local_80);
        }
        if ((local_98 & 1) != 0) {
          free(local_90);
        }
        if ((local_a4[0] & 1) != 0) {
          free(local_9c);
        }
        bVar2 = *param_3;
        uVar8 = *(uint *)(param_3 + 4);
        if ((bVar2 & 1) == 0) {
          uVar8 = (uint)(bVar2 >> 1);
        }
        if (uVar8 == 1) {
          pbVar6 = *(byte **)(param_3 + 8);
          if ((bVar2 & 1) == 0) {
            pbVar6 = param_3 + 1;
          }
          if (*pbVar6 == 0x3e) {
            FUN_001d530c(pbVar1,0x29);
          }
        }
        if ((local_48 & 1) != 0) {
          free(local_40);
        }
        if (uVar10 != 0) {
          free(__ptr);
        }
      }
    }
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FUN_001d2150  @0x001d2150  (578 bytes)
void FUN_001d2150(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 *__ptr;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  uint uVar9;
  void *__ptr_00;
  uint uVar10;
  uint uVar11;
  undefined1 *puVar12;
  uint uVar13;
  int unaff_r10;
  bool bVar14;
  undefined8 uVar15;
  uint local_58;
  uint local_54;
  void *local_50;
  byte local_4c [8];
  void *local_44;
  uint local_40;
  uint uStack_3c;
  void *local_38;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar15 = FUN_001ccfb8(param_1,param_2,param_4);
  iVar6 = (int)((ulonglong)uVar15 >> 0x20);
  bVar14 = (int)uVar15 != param_1;
  if (bVar14) {
    iVar6 = *param_4;
    unaff_r10 = param_4[1];
  }
  if (bVar14 && iVar6 != unaff_r10) {
    FUN_001d2f64(local_4c,param_3,&DAT_00222248);
    iVar2 = param_4[1];
    uVar9 = *(uint *)(iVar2 + -8);
    iVar6 = *(int *)(iVar2 + -4);
    if ((*(byte *)(iVar2 + -0xc) & 1) == 0) {
      iVar6 = iVar2 + -0xb;
      uVar9 = (uint)(*(byte *)(iVar2 + -0xc) >> 1);
    }
    puVar3 = (uint *)FUN_001cb080(iVar2 + -0x18,iVar6,uVar9);
    local_58 = *puVar3;
    local_54 = puVar3[1];
    __ptr_00 = (void *)puVar3[2];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    uVar10 = local_58 & 1;
    uVar9 = local_54;
    pvVar7 = __ptr_00;
    if ((local_58 & 1) == 0) {
      pvVar7 = (void *)((uint)&local_58 | 1);
      uVar9 = local_58 >> 1 & 0x7f;
    }
    local_50 = __ptr_00;
    puVar3 = (uint *)FUN_001cb080(local_4c,pvVar7,uVar9);
    local_40 = *puVar3;
    uStack_3c = puVar3[1];
    local_38 = (void *)puVar3[2];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar4 = (undefined4 *)FUN_001cb080(&local_40,&DAT_0022045d,1,auStack_34);
    uVar1 = *(undefined1 *)puVar4;
    __aeabi_memcpy(&local_30,(int)puVar4 + 1,7);
    uVar5 = puVar4[2];
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar3 = (uint *)(unaff_r10 + -0x18);
    if ((*(byte *)puVar3 & 1) == 0) {
      *(undefined2 *)(unaff_r10 + -0x18) = 0;
    }
    else {
      puVar4 = (undefined4 *)(unaff_r10 + -0x10);
      *(undefined1 *)*puVar4 = 0;
      *(undefined4 *)(unaff_r10 + -0x14) = 0;
      uVar9 = (uint)*(byte *)(unaff_r10 + -0x18);
      if ((*(byte *)(unaff_r10 + -0x18) & 1) == 0) {
        uVar13 = 10;
      }
      else {
        uVar9 = *puVar3;
        uVar13 = (uVar9 & 0xfffffffe) - 1;
      }
      if ((uVar9 & 1) == 0) {
        uVar8 = (uVar9 & 0xff) >> 1;
        if ((uVar9 & 0xff) < 0x16) {
          uVar11 = 10;
        }
        else {
          uVar11 = (uVar8 + 0x10 & 0xf0) - 1;
        }
        bVar14 = true;
      }
      else {
        uVar11 = 10;
        uVar8 = 0;
        bVar14 = false;
      }
      if (uVar11 != uVar13) {
        if (uVar11 == 10) {
          puVar12 = (undefined1 *)*puVar4;
          if (bVar14) {
            __aeabi_memcpy((undefined1 *)(unaff_r10 + -0x17),puVar12,((uVar9 & 0xfe) >> 1) + 1);
          }
          else {
            *(undefined1 *)(unaff_r10 + -0x17) = *puVar12;
          }
          free(puVar12);
          *(byte *)puVar3 = (byte)(uVar8 << 1);
        }
        else {
          puVar12 = malloc(uVar11 + 1);
          if ((uVar13 < uVar11) || (puVar12 != (undefined1 *)0x0)) {
            if (bVar14) {
              __aeabi_memcpy(puVar12,unaff_r10 + -0x17,((uVar9 & 0xfe) >> 1) + 1);
            }
            else {
              __ptr = (undefined1 *)*puVar4;
              *puVar12 = *__ptr;
              free(__ptr);
            }
            *(uint *)(unaff_r10 + -0x18) = uVar11 + 1 | 1;
            *(uint *)(unaff_r10 + -0x14) = uVar8;
            *(undefined1 **)(unaff_r10 + -0x10) = puVar12;
          }
        }
      }
    }
    *(undefined1 *)(unaff_r10 + -0x18) = uVar1;
    __aeabi_memcpy(unaff_r10 + -0x17,&local_30,7);
    *(undefined4 *)(unaff_r10 + -0x10) = uVar5;
    local_2a = 0;
    local_2c = 0;
    local_30 = 0;
    if ((local_40 & 1) != 0) {
      free(local_38);
    }
    if (uVar10 != 0) {
      free(__ptr_00);
    }
    if ((local_4c[0] & 1) != 0) {
      free(local_44);
    }
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FUN_001d23a4  @0x001d23a4  (2008 bytes)
void FUN_001d23a4(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  uint *puVar5;
  int iVar6;
  void *pvVar7;
  void *pvVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  uint local_48;
  uint local_44;
  void *local_40;
  uint local_38;
  uint local_34;
  void *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (2 < (int)param_2 - (int)param_1) {
    bVar2 = false;
    if ((*param_1 == 'g') && (param_1[1] == 's')) {
      param_1 = param_1 + 2;
      bVar2 = true;
    }
    pcVar3 = (char *)FUN_001d2fb0(param_1,param_2,param_3);
    if (pcVar3 == param_1) {
      if (2 < (int)param_2 - (int)param_1) {
        cVar1 = *param_1;
        bVar12 = cVar1 == 's';
        if (bVar12) {
          cVar1 = param_1[1];
        }
        if (bVar12 && cVar1 == 'r') {
          pcVar3 = param_1 + 2;
          if (*pcVar3 == 'N') {
            pcVar3 = (char *)FUN_001d31dc(param_1 + 3,param_2,param_3);
            if (pcVar3 == param_1 + 3 || pcVar3 == param_2) goto LAB_001d2ae2;
            pcVar4 = (char *)FUN_001cb15c(pcVar3,param_2,param_3);
            if (pcVar4 != pcVar3) {
              iVar10 = param_3[1];
              if ((uint)((iVar10 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
              uVar9 = *(uint *)(iVar10 + -8);
              iVar6 = *(int *)(iVar10 + -4);
              if ((*(byte *)(iVar10 + -0xc) & 1) == 0) {
                iVar6 = iVar10 + -0xb;
                uVar9 = (uint)(*(byte *)(iVar10 + -0xc) >> 1);
              }
              puVar5 = (uint *)FUN_001cb080(iVar10 + -0x18,iVar6,uVar9);
              local_38 = *puVar5;
              local_34 = puVar5[1];
              local_30 = (void *)puVar5[2];
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              iVar6 = param_3[1];
              iVar10 = iVar6;
              do {
                param_3[1] = iVar10 + -0x18;
                if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar10 + -4));
                }
                if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar10 + -0x10));
                }
                pvVar8 = local_30;
                iVar10 = param_3[1];
              } while (iVar10 != iVar6 + -0x18);
              uVar11 = local_38 & 1;
              uVar9 = local_34;
              pvVar7 = local_30;
              if ((local_38 & 1) == 0) {
                pvVar7 = (void *)((uint)&local_38 | 1);
                uVar9 = local_38 >> 1 & 0x7f;
              }
              FUN_001cb080(iVar6 + -0x30,pvVar7,uVar9);
              if (pcVar4 == param_2) {
                iVar6 = param_3[1];
                iVar10 = iVar6 + -0x18;
                do {
                  param_3[1] = iVar6 + -0x18;
                  if ((*(byte *)(iVar6 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar6 + -4));
                  }
                  if ((*(byte *)(iVar6 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar6 + -0x10));
                  }
                  iVar6 = param_3[1];
                } while (iVar6 != iVar10);
                bVar2 = true;
              }
              else {
                bVar2 = false;
              }
              if (uVar11 != 0) {
                free(pvVar8);
              }
              pcVar3 = pcVar4;
              if (bVar2) goto LAB_001d2ae2;
            }
            while (*pcVar3 != 'E') {
              pcVar4 = (char *)FUN_001d4cdc(pcVar3,param_2,param_3);
              if ((pcVar4 == pcVar3 || pcVar4 == param_2) ||
                 (iVar10 = param_3[1], (uint)((iVar10 - *param_3 >> 3) * -0x55555555) < 2))
              goto LAB_001d2ae2;
              uVar9 = *(uint *)(iVar10 + -8);
              iVar6 = *(int *)(iVar10 + -4);
              if ((*(byte *)(iVar10 + -0xc) & 1) == 0) {
                iVar6 = iVar10 + -0xb;
                uVar9 = (uint)(*(byte *)(iVar10 + -0xc) >> 1);
              }
              puVar5 = (uint *)FUN_001cb080(iVar10 + -0x18,iVar6,uVar9);
              local_38 = *puVar5;
              local_34 = puVar5[1];
              local_30 = (void *)puVar5[2];
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              iVar6 = param_3[1];
              iVar10 = iVar6;
              do {
                param_3[1] = iVar10 + -0x18;
                if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar10 + -4));
                }
                if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar10 + -0x10));
                }
                iVar10 = param_3[1];
              } while (iVar10 != iVar6 + -0x18);
              puVar5 = (uint *)FUN_001caf2a(&local_38,0,&DAT_0022220f,2);
              local_48 = *puVar5;
              local_44 = puVar5[1];
              pvVar7 = (void *)puVar5[2];
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              uVar9 = local_48 & 1;
              uVar11 = local_44;
              pvVar8 = pvVar7;
              if ((local_48 & 1) == 0) {
                pvVar8 = (void *)((uint)&local_48 | 1);
                uVar11 = local_48 >> 1 & 0x7f;
              }
              local_40 = pvVar7;
              FUN_001cb080(iVar6 + -0x30,pvVar8,uVar11);
              if (uVar9 != 0) {
                free(pvVar7);
              }
              pcVar3 = pcVar4;
              if ((local_38 & 1) != 0) {
                free(local_30);
              }
            }
            pcVar4 = (char *)FUN_001d2fb0(pcVar3 + 1,param_2,param_3);
            if (pcVar4 == pcVar3 + 1) {
              iVar10 = param_3[1];
              if (*param_3 != iVar10) {
                iVar6 = iVar10 + -0x18;
                do {
                  param_3[1] = iVar10 + -0x18;
                  if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar10 + -4));
                  }
                  if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar10 + -0x10));
                  }
                  iVar10 = param_3[1];
                } while (iVar10 != iVar6);
              }
              goto LAB_001d2ae2;
            }
            iVar10 = param_3[1];
            if ((uint)((iVar10 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
            uVar9 = *(uint *)(iVar10 + -8);
            iVar6 = *(int *)(iVar10 + -4);
            if ((*(byte *)(iVar10 + -0xc) & 1) == 0) {
              iVar6 = iVar10 + -0xb;
              uVar9 = (uint)(*(byte *)(iVar10 + -0xc) >> 1);
            }
            puVar5 = (uint *)FUN_001cb080(iVar10 + -0x18,iVar6,uVar9);
            local_38 = *puVar5;
            local_34 = puVar5[1];
            local_30 = (void *)puVar5[2];
            *puVar5 = 0;
            puVar5[1] = 0;
            puVar5[2] = 0;
            iVar6 = param_3[1];
            iVar10 = iVar6;
            do {
              param_3[1] = iVar10 + -0x18;
              if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                free(*(void **)(iVar10 + -4));
              }
              if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                free(*(void **)(iVar10 + -0x10));
              }
              iVar10 = param_3[1];
            } while (iVar10 != iVar6 + -0x18);
          }
          else {
            pcVar4 = (char *)FUN_001d31dc(pcVar3,param_2,param_3);
            if (pcVar4 == pcVar3) {
              pcVar4 = (char *)FUN_001d4cdc(pcVar3,param_2,param_3);
              if (pcVar4 == pcVar3 || pcVar4 == param_2) goto LAB_001d2ae2;
              if (bVar2) {
                if (*param_3 == param_3[1]) goto LAB_001d2ae2;
                FUN_001caf2a(param_3[1] + -0x18,0,&DAT_0022220f,2);
              }
              cVar1 = *pcVar4;
              while (cVar1 != 'E') {
                pcVar3 = (char *)FUN_001d4cdc(pcVar4,param_2,param_3);
                if ((pcVar3 == pcVar4 || pcVar3 == param_2) ||
                   (iVar10 = param_3[1], (uint)((iVar10 - *param_3 >> 3) * -0x55555555) < 2))
                goto LAB_001d2ae2;
                uVar9 = *(uint *)(iVar10 + -8);
                iVar6 = *(int *)(iVar10 + -4);
                if ((*(byte *)(iVar10 + -0xc) & 1) == 0) {
                  iVar6 = iVar10 + -0xb;
                  uVar9 = (uint)(*(byte *)(iVar10 + -0xc) >> 1);
                }
                puVar5 = (uint *)FUN_001cb080(iVar10 + -0x18,iVar6,uVar9);
                local_38 = *puVar5;
                local_34 = puVar5[1];
                local_30 = (void *)puVar5[2];
                *puVar5 = 0;
                puVar5[1] = 0;
                puVar5[2] = 0;
                iVar6 = param_3[1];
                iVar10 = iVar6;
                do {
                  param_3[1] = iVar10 + -0x18;
                  if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar10 + -4));
                  }
                  if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar10 + -0x10));
                  }
                  iVar10 = param_3[1];
                } while (iVar10 != iVar6 + -0x18);
                puVar5 = (uint *)FUN_001caf2a(&local_38,0,&DAT_0022220f,2);
                local_48 = *puVar5;
                local_44 = puVar5[1];
                pvVar7 = (void *)puVar5[2];
                *puVar5 = 0;
                puVar5[1] = 0;
                puVar5[2] = 0;
                uVar9 = local_48 & 1;
                uVar11 = local_44;
                pvVar8 = pvVar7;
                if ((local_48 & 1) == 0) {
                  pvVar8 = (void *)((uint)&local_48 | 1);
                  uVar11 = local_48 >> 1 & 0x7f;
                }
                local_40 = pvVar7;
                FUN_001cb080(iVar6 + -0x30,pvVar8,uVar11);
                if (uVar9 != 0) {
                  free(pvVar7);
                }
                if ((local_38 & 1) != 0) {
                  free(local_30);
                }
                pcVar4 = pcVar3;
                cVar1 = *pcVar3;
              }
              pcVar3 = (char *)FUN_001d2fb0(pcVar4 + 1,param_2,param_3);
              if (pcVar3 == pcVar4 + 1) {
                iVar10 = param_3[1];
                if (*param_3 != iVar10) {
                  iVar6 = iVar10 + -0x18;
                  do {
                    param_3[1] = iVar10 + -0x18;
                    if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                      free(*(void **)(iVar10 + -4));
                    }
                    if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                      free(*(void **)(iVar10 + -0x10));
                    }
                    iVar10 = param_3[1];
                  } while (iVar10 != iVar6);
                }
                goto LAB_001d2ae2;
              }
              iVar10 = param_3[1];
              if ((uint)((iVar10 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
              uVar9 = *(uint *)(iVar10 + -8);
              iVar6 = *(int *)(iVar10 + -4);
              if ((*(byte *)(iVar10 + -0xc) & 1) == 0) {
                iVar6 = iVar10 + -0xb;
                uVar9 = (uint)(*(byte *)(iVar10 + -0xc) >> 1);
              }
              puVar5 = (uint *)FUN_001cb080(iVar10 + -0x18,iVar6,uVar9);
              local_38 = *puVar5;
              local_34 = puVar5[1];
              local_30 = (void *)puVar5[2];
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              iVar6 = param_3[1];
              iVar10 = iVar6;
              do {
                param_3[1] = iVar10 + -0x18;
                if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar10 + -4));
                }
                if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar10 + -0x10));
                }
                iVar10 = param_3[1];
              } while (iVar10 != iVar6 + -0x18);
            }
            else {
              pcVar3 = (char *)FUN_001cb15c(pcVar4,param_2,param_3);
              if (pcVar3 != pcVar4) {
                iVar10 = param_3[1];
                if ((uint)((iVar10 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
                uVar9 = *(uint *)(iVar10 + -8);
                iVar6 = *(int *)(iVar10 + -4);
                if ((*(byte *)(iVar10 + -0xc) & 1) == 0) {
                  iVar6 = iVar10 + -0xb;
                  uVar9 = (uint)(*(byte *)(iVar10 + -0xc) >> 1);
                }
                puVar5 = (uint *)FUN_001cb080(iVar10 + -0x18,iVar6,uVar9);
                local_38 = *puVar5;
                local_34 = puVar5[1];
                local_30 = (void *)puVar5[2];
                *puVar5 = 0;
                puVar5[1] = 0;
                puVar5[2] = 0;
                iVar6 = param_3[1];
                iVar10 = iVar6;
                do {
                  param_3[1] = iVar10 + -0x18;
                  if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                    free(*(void **)(iVar10 + -4));
                  }
                  if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                    free(*(void **)(iVar10 + -0x10));
                  }
                  pvVar8 = local_30;
                  iVar10 = param_3[1];
                } while (iVar10 != iVar6 + -0x18);
                uVar9 = local_38 & 1;
                uVar11 = local_34;
                pvVar7 = local_30;
                if ((local_38 & 1) == 0) {
                  pvVar7 = (void *)((uint)&local_38 | 1);
                  uVar11 = local_38 >> 1 & 0x7f;
                }
                FUN_001cb080(iVar6 + -0x30,pvVar7,uVar11);
                pcVar4 = pcVar3;
                if (uVar9 != 0) {
                  free(pvVar8);
                }
              }
              pcVar3 = (char *)FUN_001d2fb0(pcVar4,param_2,param_3);
              if (pcVar3 == pcVar4) {
                iVar10 = param_3[1];
                if (*param_3 != iVar10) {
                  iVar6 = iVar10 + -0x18;
                  do {
                    param_3[1] = iVar10 + -0x18;
                    if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                      free(*(void **)(iVar10 + -4));
                    }
                    if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                      free(*(void **)(iVar10 + -0x10));
                    }
                    iVar10 = param_3[1];
                  } while (iVar10 != iVar6);
                }
                goto LAB_001d2ae2;
              }
              iVar10 = param_3[1];
              if ((uint)((iVar10 - *param_3 >> 3) * -0x55555555) < 2) goto LAB_001d2ae2;
              uVar9 = *(uint *)(iVar10 + -8);
              iVar6 = *(int *)(iVar10 + -4);
              if ((*(byte *)(iVar10 + -0xc) & 1) == 0) {
                iVar6 = iVar10 + -0xb;
                uVar9 = (uint)(*(byte *)(iVar10 + -0xc) >> 1);
              }
              puVar5 = (uint *)FUN_001cb080(iVar10 + -0x18,iVar6,uVar9);
              local_38 = *puVar5;
              local_34 = puVar5[1];
              local_30 = (void *)puVar5[2];
              *puVar5 = 0;
              puVar5[1] = 0;
              puVar5[2] = 0;
              iVar6 = param_3[1];
              iVar10 = iVar6;
              do {
                param_3[1] = iVar10 + -0x18;
                if ((*(byte *)(iVar10 + -0xc) & 1) != 0) {
                  free(*(void **)(iVar10 + -4));
                }
                if ((*(byte *)(iVar10 + -0x18) & 1) != 0) {
                  free(*(void **)(iVar10 + -0x10));
                }
                iVar10 = param_3[1];
              } while (iVar10 != iVar6 + -0x18);
            }
          }
          puVar5 = (uint *)FUN_001caf2a(&local_38,0,&DAT_0022220f,2);
          local_48 = *puVar5;
          local_44 = puVar5[1];
          pvVar7 = (void *)puVar5[2];
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          uVar9 = local_48 & 1;
          uVar11 = local_44;
          pvVar8 = pvVar7;
          if ((local_48 & 1) == 0) {
            pvVar8 = (void *)((uint)&local_48 | 1);
            uVar11 = local_48 >> 1 & 0x7f;
          }
          local_40 = pvVar7;
          FUN_001cb080(iVar6 + -0x30,pvVar8,uVar11);
          if (uVar9 != 0) {
            free(pvVar7);
          }
          if ((local_38 & 1) != 0) {
            free(local_30);
          }
        }
      }
    }
    else if ((bVar2) && (*param_3 != param_3[1])) {
      FUN_001caf2a(param_3[1] + -0x18,0,&DAT_0022220f,2);
    }
  }
LAB_001d2ae2:
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001d2ba0  @0x001d2ba0  (660 bytes)
void FUN_001d2ba0(char *param_1,char *param_2,byte *param_3,int *param_4)

{
  undefined1 uVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  undefined1 *puVar10;
  uint uVar11;
  byte local_60 [8];
  void *local_58;
  undefined1 auStack_54 [8];
  undefined1 *local_4c;
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pcVar3 = (char *)FUN_001caeea(param_1);
  if ((pcVar3 != param_1 && pcVar3 != param_2) && (*pcVar3 == 'E')) {
    uVar4 = *(uint *)(param_3 + 4);
    if ((*param_3 & 1) == 0) {
      uVar4 = (uint)(*param_3 >> 1);
    }
    if (uVar4 < 4) {
      uVar4 = param_4[1];
      if (uVar4 < (uint)param_4[2]) {
        __aeabi_memclr4(uVar4,0x18);
        param_4[1] = param_4[1] + 0x18;
      }
      else {
        iVar9 = ((int)(uVar4 - *param_4) >> 3) * -0x55555555;
        iVar7 = param_4[2] - *param_4 >> 3;
        uVar4 = 0xaaaaaaa;
        if ((uint)(iVar7 * -0x55555555) < 0x5555555) {
          uVar11 = iVar9 + 1;
          uVar4 = iVar7 * 0x55555556;
          if (uVar4 < uVar11) {
            uVar4 = uVar11;
          }
        }
        FUN_001ccdd4(auStack_54,uVar4,iVar9,param_4 + 3);
        __aeabi_memclr4(local_4c,0x18);
        local_4c = local_4c + 0x18;
        FUN_001cce32(param_4,auStack_54);
        FUN_001cceae(auStack_54);
      }
    }
    else {
      FUN_001cbc00(local_60,&DAT_00222248,param_3);
      puVar5 = (undefined4 *)FUN_001cb080(local_60,&DAT_0022045d,1);
      uVar1 = *(undefined1 *)puVar5;
      __aeabi_memcpy(&local_40,(int)puVar5 + 1,7);
      uVar6 = puVar5[2];
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      __aeabi_memcpy(&local_30,&local_40,7);
      local_3a = 0;
      local_3c = 0;
      local_32 = 0;
      local_34 = 0;
      local_40 = 0;
      local_38 = 0;
      puVar10 = (undefined1 *)param_4[1];
      if (puVar10 < (undefined1 *)param_4[2]) {
        *puVar10 = uVar1;
        __aeabi_memcpy(puVar10 + 1,&local_30,7);
        *(undefined4 *)(puVar10 + 8) = uVar6;
        local_2a = 0;
        local_2c = 0;
        local_30 = 0;
        puVar10[0xc] = 0;
        __aeabi_memcpy(puVar10 + 0xd,&local_38,7);
        *(undefined4 *)(puVar10 + 0x14) = 0;
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        param_4[1] = param_4[1] + 0x18;
      }
      else {
        iVar7 = param_4[2] - *param_4 >> 3;
        iVar9 = ((int)puVar10 - *param_4 >> 3) * -0x55555555;
        uVar4 = 0xaaaaaaa;
        if ((uint)(iVar7 * -0x55555555) < 0x5555555) {
          uVar11 = iVar9 + 1;
          uVar4 = iVar7 * 0x55555556;
          if (uVar4 < uVar11) {
            uVar4 = uVar11;
          }
        }
        FUN_001ccdd4(auStack_54,uVar4,iVar9,param_4 + 3);
        puVar10 = local_4c;
        *local_4c = uVar1;
        __aeabi_memcpy(local_4c + 1,&local_30,7);
        *(undefined4 *)(puVar10 + 8) = uVar6;
        local_2a = 0;
        local_2c = 0;
        local_30 = 0;
        puVar10[0xc] = 0;
        __aeabi_memcpy(puVar10 + 0xd,&local_38,7);
        *(undefined4 *)(puVar10 + 0x14) = 0;
        local_32 = 0;
        local_4c = local_4c + 0x18;
        local_34 = 0;
        local_38 = 0;
        FUN_001cce32(param_4,auStack_54);
        FUN_001cceae(auStack_54);
      }
      if ((local_60[0] & 1) != 0) {
        free(local_58);
      }
    }
    if (*param_1 == 'n') {
      FUN_001d530c(param_4[1] + -0x18,0x2d);
      param_1 = param_1 + 1;
    }
    FUN_001d2e44(param_4[1] + -0x18,param_1,pcVar3);
    bVar2 = *param_3;
    uVar4 = *(uint *)(param_3 + 4);
    if ((bVar2 & 1) == 0) {
      uVar4 = (uint)(bVar2 >> 1);
    }
    if (uVar4 < 4) {
      pbVar8 = *(byte **)(param_3 + 8);
      if ((bVar2 & 1) == 0) {
        pbVar8 = param_3 + 1;
      }
      FUN_001cb080(param_4[1] + -0x18,pbVar8);
    }
  }
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001d2e44  @0x001d2e44  (142 bytes)
void FUN_001d2e44(uint *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar8;
  uint uVar9;
  byte *pbVar7;
  
  bVar1 = (byte)*param_1;
  uVar2 = (uint)bVar1;
  if ((bVar1 & 1) == 0) {
    uVar8 = (uint)(bVar1 >> 1);
    iVar4 = 10;
  }
  else {
    uVar2 = *param_1;
    uVar8 = param_1[1];
    iVar4 = (uVar2 & 0xfffffffe) - 1;
  }
  uVar9 = (int)param_3 - (int)param_2;
  if (uVar9 != 0) {
    if (iVar4 - uVar8 < uVar9) {
      FUN_001d2ed2(param_1,iVar4,(uVar8 + uVar9) - iVar4,uVar8,uVar8,0);
      uVar2 = (uint)(byte)*param_1;
    }
    if ((uVar2 & 1) == 0) {
      pbVar3 = (byte *)((int)param_1 + 1);
    }
    else {
      pbVar3 = (byte *)param_1[2];
    }
    pbVar5 = pbVar3 + uVar8;
    if (param_2 != param_3) {
      pbVar7 = param_2;
      do {
        pbVar6 = pbVar7 + 1;
        *pbVar5 = *pbVar7;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar6;
      } while (param_3 != pbVar6);
      pbVar5 = pbVar3 + (int)(param_3 + (uVar8 - (int)param_2));
    }
    *pbVar5 = 0;
    if ((*param_1 & 1) == 0) {
      *(char *)param_1 = (char)(uVar8 + uVar9) * '\x02';
    }
    else {
      param_1[1] = uVar8 + uVar9;
    }
  }
  return;
}

// ===== FUN_001d2ed2  @0x001d2ed2  (146 bytes)
void FUN_001d2ed2(uint *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  void *pvVar2;
  byte *__ptr;
  
  if ((*param_1 & 1) == 0) {
    __ptr = (byte *)((int)param_1 + 1);
  }
  else {
    __ptr = (byte *)param_1[2];
  }
  if (param_2 < 0x7fffffe7) {
    uVar1 = param_3 + param_2;
    if (uVar1 < param_2 << 1) {
      uVar1 = param_2 << 1;
    }
    if (uVar1 < 0xb) {
      uVar1 = 0xb;
    }
    else {
      uVar1 = uVar1 + 0x10 & 0xfffffff0;
    }
  }
  else {
    uVar1 = 0xffffffef;
  }
  pvVar2 = malloc(uVar1);
  if (param_5 != 0) {
    __aeabi_memcpy(pvVar2,__ptr,param_5);
  }
  if (param_4 != param_5) {
    __aeabi_memcpy((int)pvVar2 + param_6 + param_5,__ptr + param_5);
  }
  if (param_2 != 10) {
    free(__ptr);
  }
  param_1[2] = (uint)pvVar2;
  *param_1 = uVar1 | 1;
  return;
}

// ===== FUN_001d2f64  @0x001d2f64  (74 bytes)
void FUN_001d2f64(undefined4 *param_1,byte *param_2,char *param_3)

{
  byte bVar1;
  size_t sVar2;
  byte *pbVar3;
  uint uVar4;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar4 = *(uint *)(param_2 + 4);
  bVar1 = *param_2;
  sVar2 = strlen(param_3);
  pbVar3 = *(byte **)(param_2 + 8);
  if ((bVar1 & 1) == 0) {
    pbVar3 = param_2 + 1;
    uVar4 = (uint)(bVar1 >> 1);
  }
  FUN_001ccf70(param_1,pbVar3,uVar4,uVar4 + sVar2);
  FUN_001cb080(param_1,param_3,sVar2);
  return;
}

// ===== FUN_001d2fb0  @0x001d2fb0  (544 bytes)
void FUN_001d2fb0(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  void *__ptr;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  int iVar7;
  void *pvVar8;
  uint uVar9;
  uint uVar10;
  uint local_38;
  uint local_34;
  void *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pcVar6 = param_1;
  if ((int)param_2 - (int)param_1 < 2) goto LAB_001d31b8;
  cVar1 = *param_1;
  if ((cVar1 == 'o' || cVar1 == 'd') && (param_1[1] == 'n')) {
    param_1 = param_1 + 2;
    if (cVar1 != 'o') {
      if (param_1 != param_2) {
        pcVar2 = (char *)FUN_001d31dc(param_1,param_2,param_3);
        if (pcVar2 == param_1) {
          pcVar2 = (char *)FUN_001d4cdc(param_1,param_2,param_3);
        }
        param_2 = param_1;
        if ((pcVar2 != param_1) && (*param_3 != param_3[1])) {
          FUN_001caf2a(param_3[1] + -0x18,0,&DAT_00222226,1);
          param_2 = pcVar2;
        }
      }
      if (param_2 != param_1) {
        pcVar6 = param_2;
      }
      goto LAB_001d31b8;
    }
    pcVar2 = (char *)FUN_001d34d8(param_1,param_2,param_3);
    if (((pcVar2 == param_1) ||
        (pcVar3 = (char *)FUN_001cb15c(pcVar2,param_2,param_3), pcVar6 = pcVar2, pcVar3 == pcVar2))
       || (iVar4 = param_3[1], pcVar6 = pcVar3, (uint)((iVar4 - *param_3 >> 3) * -0x55555555) < 2))
    goto LAB_001d31b8;
    uVar9 = *(uint *)(iVar4 + -8);
    iVar7 = *(int *)(iVar4 + -4);
    if ((*(byte *)(iVar4 + -0xc) & 1) == 0) {
      iVar7 = iVar4 + -0xb;
      uVar9 = (uint)(*(byte *)(iVar4 + -0xc) >> 1);
    }
    puVar5 = (uint *)FUN_001cb080(iVar4 + -0x18,iVar7,uVar9);
    local_38 = *puVar5;
    local_34 = puVar5[1];
    local_30 = (void *)puVar5[2];
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    iVar7 = param_3[1];
    iVar4 = iVar7;
    do {
      param_3[1] = iVar4 + -0x18;
      if ((*(byte *)(iVar4 + -0xc) & 1) != 0) {
        free(*(void **)(iVar4 + -4));
      }
      if ((*(byte *)(iVar4 + -0x18) & 1) != 0) {
        free(*(void **)(iVar4 + -0x10));
      }
      iVar4 = param_3[1];
    } while (iVar4 != iVar7 + -0x18);
  }
  else {
    pcVar6 = (char *)FUN_001d4cdc(param_1,param_2,param_3);
    if ((pcVar6 != param_1) ||
       (((pcVar2 = (char *)FUN_001d34d8(param_1,param_2,param_3), pcVar6 = param_1,
         pcVar2 == param_1 ||
         (pcVar3 = (char *)FUN_001cb15c(pcVar2,param_2,param_3), pcVar6 = pcVar2, pcVar3 == pcVar2))
        || (iVar4 = param_3[1], pcVar6 = pcVar3, (uint)((iVar4 - *param_3 >> 3) * -0x55555555) < 2))
       )) goto LAB_001d31b8;
    uVar9 = *(uint *)(iVar4 + -8);
    iVar7 = *(int *)(iVar4 + -4);
    if ((*(byte *)(iVar4 + -0xc) & 1) == 0) {
      iVar7 = iVar4 + -0xb;
      uVar9 = (uint)(*(byte *)(iVar4 + -0xc) >> 1);
    }
    puVar5 = (uint *)FUN_001cb080(iVar4 + -0x18,iVar7,uVar9);
    local_38 = *puVar5;
    local_34 = puVar5[1];
    local_30 = (void *)puVar5[2];
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    iVar7 = param_3[1];
    iVar4 = iVar7;
    do {
      param_3[1] = iVar4 + -0x18;
      if ((*(byte *)(iVar4 + -0xc) & 1) != 0) {
        free(*(void **)(iVar4 + -4));
      }
      if ((*(byte *)(iVar4 + -0x18) & 1) != 0) {
        free(*(void **)(iVar4 + -0x10));
      }
      iVar4 = param_3[1];
    } while (iVar4 != iVar7 + -0x18);
  }
  __ptr = local_30;
  uVar9 = local_38 & 1;
  uVar10 = local_34;
  pvVar8 = local_30;
  if ((local_38 & 1) == 0) {
    pvVar8 = (void *)((uint)&local_38 | 1);
    uVar10 = local_38 >> 1 & 0x7f;
  }
  FUN_001cb080(iVar7 + -0x30,pvVar8,uVar10);
  pcVar6 = pcVar3;
  if (uVar9 != 0) {
    free(__ptr);
  }
LAB_001d31b8:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pcVar6);
  }
  return;
}

// ===== FUN_001d31dc  @0x001d31dc  (750 bytes)
void FUN_001d31dc(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 auStack_3c [8];
  undefined4 *local_34;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == param_2) goto LAB_001d33be;
  cVar1 = *param_1;
  if (cVar1 == 'D') {
    pcVar2 = (char *)FUN_001cc0b8(param_1,param_2,param_3);
    if ((pcVar2 == param_1) || (*param_3 == param_3[1])) goto LAB_001d33be;
    local_50 = param_3[3];
    FUN_001cb104(&local_4c,param_3[1] + -0x18,&local_50);
    puVar3 = (undefined4 *)param_3[5];
    puVar5 = (undefined4 *)param_3[6];
    if (puVar3 < puVar5) {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = local_40;
      *puVar3 = local_4c;
      puVar3[1] = local_48;
      puVar3[2] = local_44;
      goto LAB_001d3326;
    }
LAB_001d3408:
    iVar9 = (int)puVar5 - param_3[4];
    iVar8 = (int)puVar3 - param_3[4] >> 4;
    if ((uint)(iVar9 >> 4) < 0x7ffffff) {
      uVar4 = iVar8 + 1;
      uVar6 = iVar9 >> 3;
      if (uVar6 < uVar4) {
        uVar6 = uVar4;
      }
    }
    else {
      uVar6 = 0xfffffff;
    }
    FUN_001d53d2(auStack_3c,uVar6,iVar8,param_3 + 7);
    *local_34 = 0;
    local_34[1] = 0;
    local_34[2] = 0;
    local_34[3] = local_40;
    *local_34 = local_4c;
    local_34[1] = local_48;
    local_34[2] = local_44;
    local_44 = 0;
    local_34 = local_34 + 4;
    local_48 = 0;
    local_4c = 0;
    FUN_001d541e(param_3 + 4,auStack_3c);
    FUN_001d548a(auStack_3c);
  }
  else {
    if (cVar1 != 'S') {
      if (cVar1 == 'T') {
        iVar10 = *param_3;
        iVar8 = param_3[1];
        pcVar2 = (char *)FUN_001cbc74(param_1,param_2,param_3);
        iVar9 = param_3[1];
        iVar8 = (iVar8 - iVar10 >> 3) * -0x55555555;
        iVar10 = (iVar9 - *param_3 >> 3) * -0x55555555;
        if ((pcVar2 == param_1) || (iVar10 - (iVar8 + 1) != 0)) {
          for (; iVar10 != iVar8; iVar10 = iVar10 + -1) {
            iVar7 = iVar9 + -0x18;
            do {
              param_3[1] = iVar9 + -0x18;
              if ((*(byte *)(iVar9 + -0xc) & 1) != 0) {
                free(*(void **)(iVar9 + -4));
              }
              if ((*(byte *)(iVar9 + -0x18) & 1) != 0) {
                free(*(void **)(iVar9 + -0x10));
              }
              iVar9 = param_3[1];
            } while (iVar9 != iVar7);
            iVar9 = iVar7;
          }
        }
        else {
          local_50 = param_3[3];
          FUN_001cb104(&local_4c,iVar9 + -0x18,&local_50);
          puVar3 = (undefined4 *)param_3[5];
          if (puVar3 < (undefined4 *)param_3[6]) {
            *puVar3 = 0;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = local_40;
            *puVar3 = local_4c;
            puVar3[1] = local_48;
            puVar3[2] = local_44;
            local_44 = 0;
            local_4c = 0;
            local_48 = 0;
            param_3[5] = param_3[5] + 0x10;
          }
          else {
            iVar9 = param_3[6] - param_3[4];
            iVar8 = (int)puVar3 - param_3[4] >> 4;
            if ((uint)(iVar9 >> 4) < 0x7ffffff) {
              uVar4 = iVar8 + 1;
              uVar6 = iVar9 >> 3;
              if (uVar6 < uVar4) {
                uVar6 = uVar4;
              }
            }
            else {
              uVar6 = 0xfffffff;
            }
            FUN_001d53d2(auStack_3c,uVar6,iVar8,param_3 + 7);
            *local_34 = 0;
            local_34[1] = 0;
            local_34[2] = 0;
            local_34[3] = local_40;
            *local_34 = local_4c;
            local_34[1] = local_48;
            local_34[2] = local_44;
            local_44 = 0;
            local_4c = 0;
            local_48 = 0;
            local_34 = local_34 + 4;
            FUN_001d541e(param_3 + 4,auStack_3c);
            FUN_001d548a(auStack_3c);
          }
          FUN_001c5dac(&local_4c);
        }
      }
      goto LAB_001d33be;
    }
    pcVar2 = (char *)FUN_001cb6bc(param_1,param_2,param_3);
    if ((((pcVar2 != param_1) || ((int)param_2 - (int)param_1 < 3)) || (param_1[1] != 't')) ||
       ((pcVar2 = (char *)FUN_001cc234(param_1 + 2,param_2,param_3), pcVar2 == param_1 + 2 ||
        (*param_3 == param_3[1])))) goto LAB_001d33be;
    FUN_001caf2a(param_3[1] + -0x18,0,"std::",5);
    local_50 = param_3[3];
    FUN_001cb104(&local_4c,param_3[1] + -0x18,&local_50);
    puVar3 = (undefined4 *)param_3[5];
    puVar5 = (undefined4 *)param_3[6];
    if (puVar5 <= puVar3) goto LAB_001d3408;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = local_40;
    *puVar3 = local_4c;
    puVar3[1] = local_48;
    puVar3[2] = local_44;
LAB_001d3326:
    local_44 = 0;
    local_48 = 0;
    local_4c = 0;
    param_3[5] = param_3[5] + 0x10;
  }
  FUN_001c5dac(&local_4c);
LAB_001d33be:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FUN_001d34d8  @0x001d34d8  (5880 bytes)
void FUN_001d34d8(undefined1 *param_1,int param_2,int *param_3)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined4 uVar14;
  bool bVar15;
  undefined8 uVar16;
  undefined1 auStack_4c [8];
  undefined4 *local_44;
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_2 - (int)param_1 < 2) goto switchD_001d3522_caseD_62;
  uVar14 = 0x3d3d72;
  uVar13 = 0xaaaaaaa;
  switch(*param_1) {
  case 0x61:
    bVar2 = param_1[1];
    if (bVar2 < 0x61) {
      if (bVar2 == 0x4e) {
        __aeabi_memcpy(&local_30,"operator&=",7);
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        puVar11 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar11) {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar9 = iVar10 + 1;
            uVar13 = iVar6 * 0x55555556;
            if (uVar13 < uVar9) {
              uVar13 = uVar9;
            }
          }
          FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
          puVar12 = local_44;
          *(undefined1 *)local_44 = 0x14;
          __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
          uVar14 = 0x3d2672;
          goto LAB_001d4c2e;
        }
        *puVar11 = 0x14;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x3d2672;
      }
      else {
        if (bVar2 != 0x53) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator=",7);
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        puVar11 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar11) {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar9 = iVar10 + 1;
            uVar13 = iVar6 * 0x55555556;
            if (uVar13 < uVar9) {
              uVar13 = uVar9;
            }
          }
          FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
          puVar12 = local_44;
          *(undefined1 *)local_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
          uVar14 = 0x3d72;
          goto LAB_001d4baa;
        }
        *puVar11 = 0x12;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x3d72;
      }
    }
    else {
      if (bVar2 != 0x6e && bVar2 != 100) {
        if (bVar2 != 0x61) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator&&",7);
        uVar14 = 0x262672;
        goto LAB_001d42e6;
      }
      __aeabi_memcpy(&local_30,"operator&",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x2672;
        goto LAB_001d4baa;
      }
      *puVar11 = 0x12;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x2672;
    }
    break;
  default:
    goto switchD_001d3522_caseD_62;
  case 99:
    bVar2 = param_1[1];
    if (bVar2 < 0x6f) {
      if (bVar2 == 0x6c) {
        __aeabi_memcpy(&local_30,"operator()",7);
        uVar14 = 0x292872;
        goto LAB_001d42e6;
      }
      if (bVar2 != 0x6d) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator,",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x2c72;
        goto LAB_001d4baa;
      }
      *puVar11 = 0x12;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x2c72;
    }
    else {
      if (bVar2 != 0x6f) {
        if (bVar2 == 0x76) {
          param_1 = param_1 + 2;
          uVar3 = *(undefined1 *)((int)param_3 + 0x3f);
          *(undefined1 *)((int)param_3 + 0x3f) = 0;
          uVar16 = FUN_001c6af0(param_1,param_2,param_3);
          *(undefined1 *)((int)param_3 + 0x3f) = uVar3;
          bVar15 = (undefined1 *)uVar16 != param_1;
          if (bVar15) {
            uVar16 = CONCAT44(*param_3,param_3[1]);
          }
          if (bVar15 && (int)((ulonglong)uVar16 >> 0x20) != (int)uVar16) {
            FUN_001caf2a((int)uVar16 + -0x18,0,"operator ",9);
            *(undefined1 *)(param_3 + 0xf) = 1;
          }
        }
        goto switchD_001d3522_caseD_62;
      }
      __aeabi_memcpy(&local_30,"operator~",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x7e72;
        goto LAB_001d4baa;
      }
      *puVar11 = 0x12;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x7e72;
    }
    break;
  case 100:
    bVar2 = param_1[1];
    if (100 < bVar2) {
      if (bVar2 == 0x65) {
LAB_001d3f56:
        __aeabi_memcpy(&local_30,"operator*",7);
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        puVar11 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar11) {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar9 = iVar10 + 1;
            uVar13 = iVar6 * 0x55555556;
            if (uVar13 < uVar9) {
              uVar13 = uVar9;
            }
          }
          FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
          puVar12 = local_44;
          *(undefined1 *)local_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
          uVar14 = 0x2a72;
          goto LAB_001d4baa;
        }
        *puVar11 = 0x12;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x2a72;
      }
      else {
        if (bVar2 == 0x6c) {
          pvVar4 = malloc(0x10);
          uVar14 = 0xf;
          __aeabi_memcpy(pvVar4,"operator delete",0xf);
          local_2a = 0;
          local_2c = 0;
          *(undefined1 *)((int)pvVar4 + 0xf) = 0;
          local_30 = 0;
          puVar12 = (undefined4 *)param_3[1];
          if (puVar12 < (undefined4 *)param_3[2]) goto LAB_001d425a;
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar9 = iVar10 + 1;
            uVar13 = iVar6 * 0x55555556;
            if (uVar13 < uVar9) {
              uVar13 = uVar9;
            }
          }
          FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
          uVar14 = 0x11;
          uVar5 = 0xf;
          goto LAB_001d48d2;
        }
        if (bVar2 != 0x76) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator/",7);
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        puVar11 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar11) {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar9 = iVar10 + 1;
            uVar13 = iVar6 * 0x55555556;
            if (uVar13 < uVar9) {
              uVar13 = uVar9;
            }
          }
          FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
          puVar12 = local_44;
          *(undefined1 *)local_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
          uVar14 = 0x2f72;
          goto LAB_001d4baa;
        }
        *puVar11 = 0x12;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x2f72;
      }
      break;
    }
    if (bVar2 == 0x56) {
      __aeabi_memcpy(&local_30,"operator/=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x3d2f72;
        goto LAB_001d4c2e;
      }
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x3d2f72;
      break;
    }
    if (bVar2 != 0x61) goto switchD_001d3522_caseD_62;
    pvVar4 = malloc(0x20);
    uVar14 = 0x11;
    __aeabi_memcpy(pvVar4,"operator delete[]",0x11);
    local_2a = 0;
    local_2c = 0;
    *(undefined1 *)((int)pvVar4 + 0x11) = 0;
    local_30 = 0;
    puVar12 = (undefined4 *)param_3[1];
    if ((undefined4 *)param_3[2] <= puVar12) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      uVar14 = 0x21;
      uVar5 = 0x11;
      goto LAB_001d48d2;
    }
    uVar5 = 0x21;
LAB_001d425c:
    local_2a = 0;
    local_2c = 0;
    local_30 = 0;
    *puVar12 = uVar5;
    puVar12[1] = uVar14;
    puVar12[2] = pvVar4;
    *(undefined1 *)(puVar12 + 3) = 0;
    __aeabi_memcpy((int)puVar12 + 0xd,&local_30,7);
    puVar12[5] = 0;
    local_2a = 0;
    local_2c = 0;
    local_30 = 0;
    goto LAB_001d43b8;
  case 0x65:
    cVar1 = param_1[1];
    if (cVar1 != 'O') {
      if (cVar1 != 'q') {
        if (cVar1 != 'o') goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator^",7);
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        puVar11 = (undefined1 *)param_3[1];
        if (puVar11 < (undefined1 *)param_3[2]) {
          *puVar11 = 0x12;
          __aeabi_memcpy(puVar11 + 1,&local_30,7);
          uVar14 = 0x5e72;
          break;
        }
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x5e72;
        goto LAB_001d4baa;
      }
      __aeabi_memcpy(&local_30,"operator==",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      puVar7 = (undefined1 *)param_3[2];
      if (puVar11 < puVar7) {
        *puVar11 = 0x14;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        *(undefined4 *)(puVar11 + 8) = 0x3d3d72;
        goto LAB_001d3c16;
      }
      iVar6 = *param_3;
      iVar10 = (int)puVar11 - iVar6;
      goto LAB_001d4310;
    }
    __aeabi_memcpy(&local_30,"operator^=",7);
    local_32 = 0;
    local_34 = 0;
    local_38 = 0;
    puVar11 = (undefined1 *)param_3[1];
    if (puVar11 < (undefined1 *)param_3[2]) {
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      *(undefined4 *)(puVar11 + 8) = 0x3d5e72;
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
      puVar11[0xc] = 0;
      __aeabi_memcpy(puVar11 + 0xd,&local_38,7);
      *(undefined4 *)(puVar11 + 0x14) = 0;
LAB_001d4422:
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      goto LAB_001d43b8;
    }
    iVar6 = param_3[2] - *param_3 >> 3;
    iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
      uVar9 = iVar10 + 1;
      uVar13 = iVar6 * 0x55555556;
      if (uVar13 < uVar9) {
        uVar13 = uVar9;
      }
    }
    FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
    puVar12 = local_44;
    *(undefined1 *)local_44 = 0x14;
    __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
    uVar14 = 0x3d5e72;
    goto LAB_001d4baa;
  case 0x67:
    if (param_1[1] == 't') {
      __aeabi_memcpy(&local_30,"operator>",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if (puVar11 < (undefined1 *)param_3[2]) {
        *puVar11 = 0x12;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x3e72;
        break;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x3e72;
    }
    else {
      if (param_1[1] != 'e') goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator>=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if (puVar11 < (undefined1 *)param_3[2]) {
        *puVar11 = 0x14;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x3d3e72;
        goto LAB_001d3c14;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x3d3e72;
    }
    goto LAB_001d4baa;
  case 0x69:
    if (param_1[1] != 'x') goto switchD_001d3522_caseD_62;
    __aeabi_memcpy(&local_30,"operator[]",7);
    uVar14 = 0x5d5b72;
LAB_001d42e6:
    local_32 = 0;
    local_34 = 0;
    local_38 = 0;
    puVar11 = (undefined1 *)param_3[1];
    puVar7 = (undefined1 *)param_3[2];
    if (puVar7 <= puVar11) {
      iVar6 = *param_3;
      iVar10 = (int)puVar11 - iVar6;
LAB_001d4310:
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      iVar6 = (int)puVar7 - iVar6 >> 3;
      iVar10 = (iVar10 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      puVar12[2] = uVar14;
      goto LAB_001d4bac;
    }
    *puVar11 = 0x14;
    __aeabi_memcpy(puVar11 + 1,&local_30,7);
    *(undefined4 *)(puVar11 + 8) = uVar14;
    goto LAB_001d4394;
  case 0x6c:
    bVar2 = param_1[1];
    if (0x68 < bVar2) {
      if (bVar2 == 0x69) {
        param_1 = param_1 + 2;
        uVar16 = FUN_001d4de4(param_1,param_2,param_3);
        bVar15 = (undefined1 *)uVar16 != param_1;
        if (bVar15) {
          uVar16 = CONCAT44(*param_3,param_3[1]);
        }
        if (bVar15 && (int)((ulonglong)uVar16 >> 0x20) != (int)uVar16) {
          FUN_001caf2a((int)uVar16 + -0x18,0,"operator\"\" ",0xb);
        }
        goto switchD_001d3522_caseD_62;
      }
      if (bVar2 != 0x73) {
        if (bVar2 != 0x74) goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator<",7);
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        puVar11 = (undefined1 *)param_3[1];
        if ((undefined1 *)param_3[2] <= puVar11) {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar9 = iVar10 + 1;
            uVar13 = iVar6 * 0x55555556;
            if (uVar13 < uVar9) {
              uVar13 = uVar9;
            }
          }
          FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
          puVar12 = local_44;
          *(undefined1 *)local_44 = 0x12;
          __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
          uVar14 = 0x3c72;
          goto LAB_001d4baa;
        }
        *puVar11 = 0x12;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x3c72;
        break;
      }
      __aeabi_memcpy(&local_30,"operator<<",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        puVar12[2] = 0x3c3c72;
        goto LAB_001d4c30;
      }
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      *(undefined4 *)(puVar11 + 8) = 0x3c3c72;
      goto LAB_001d4394;
    }
    if (bVar2 == 0x53) {
      pvVar4 = malloc(0x10);
      pcVar8 = "operator<<=";
      goto LAB_001d4232;
    }
    if (bVar2 != 0x65) goto switchD_001d3522_caseD_62;
    __aeabi_memcpy(&local_30,"operator<=",7);
    local_32 = 0;
    local_34 = 0;
    local_38 = 0;
    puVar11 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar11) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x3d3c72;
      goto LAB_001d4c2e;
    }
    *puVar11 = 0x14;
    __aeabi_memcpy(puVar11 + 1,&local_30,7);
    uVar14 = 0x3d3c72;
    break;
  case 0x6d:
    bVar2 = param_1[1];
    if (0x68 < bVar2) {
      if (bVar2 != 0x6d) {
        if (bVar2 != 0x6c) {
          if (bVar2 != 0x69) goto switchD_001d3522_caseD_62;
          goto LAB_001d3f94;
        }
        goto LAB_001d3f56;
      }
      __aeabi_memcpy(&local_30,"operator--",7);
      uVar14 = 0x2d2d72;
      goto LAB_001d42e6;
    }
    if (bVar2 == 0x49) {
      __aeabi_memcpy(&local_30,"operator-=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x3d2d72;
LAB_001d4c2e:
        puVar12[2] = uVar14;
LAB_001d4c30:
        local_2a = 0;
        local_2c = 0;
        local_30 = 0;
        *(undefined1 *)(puVar12 + 3) = 0;
        __aeabi_memcpy((undefined1 *)((int)puVar12 + 0xd),&local_38,7);
        puVar12[5] = 0;
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        goto LAB_001d4c56;
      }
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x3d2d72;
    }
    else {
      if (bVar2 != 0x4c) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator*=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x3d2a72;
        goto LAB_001d4c2e;
      }
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x3d2a72;
    }
    break;
  case 0x6e:
    bVar2 = param_1[1];
    if (bVar2 < 0x67) {
      if (bVar2 == 0x61) {
        pvVar4 = malloc(0x10);
        uVar14 = 0xe;
        __aeabi_memcpy(pvVar4,"operator new[]",0xe);
        local_2a = 0;
        local_2c = 0;
        *(undefined1 *)((int)pvVar4 + 0xe) = 0;
        local_30 = 0;
        puVar12 = (undefined4 *)param_3[1];
        if ((undefined4 *)param_3[2] <= puVar12) {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar9 = iVar10 + 1;
            uVar13 = iVar6 * 0x55555556;
            if (uVar13 < uVar9) {
              uVar13 = uVar9;
            }
          }
          FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
          uVar14 = 0x11;
          uVar5 = 0xe;
          goto LAB_001d48d2;
        }
        goto LAB_001d425a;
      }
      if (bVar2 != 0x65) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator!=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x3d2172;
        goto LAB_001d4c2e;
      }
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x3d2172;
    }
    else if (bVar2 == 0x67) {
LAB_001d3f94:
      __aeabi_memcpy(&local_30,"operator-",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x2d72;
        goto LAB_001d4baa;
      }
      *puVar11 = 0x12;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x2d72;
    }
    else {
      if (bVar2 != 0x74) {
        if (bVar2 != 0x77) goto switchD_001d3522_caseD_62;
        pvVar4 = malloc(0x10);
        uVar14 = 0xc;
        __aeabi_memcpy(pvVar4,"operator new",0xc);
        local_2a = 0;
        local_2c = 0;
        *(undefined1 *)((int)pvVar4 + 0xc) = 0;
        local_30 = 0;
        puVar12 = (undefined4 *)param_3[1];
        if (puVar12 < (undefined4 *)param_3[2]) goto LAB_001d425a;
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        uVar14 = 0x11;
        uVar5 = 0xc;
        goto LAB_001d48d2;
      }
      __aeabi_memcpy(&local_30,"operator!",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x2172;
        goto LAB_001d4baa;
      }
      *puVar11 = 0x12;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x2172;
    }
    break;
  case 0x6f:
    cVar1 = param_1[1];
    if (cVar1 == 'R') {
      __aeabi_memcpy(&local_30,"operator|=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if (puVar11 < (undefined1 *)param_3[2]) {
        *puVar11 = 0x14;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x3d7c72;
LAB_001d3c14:
        *(undefined4 *)(puVar11 + 8) = uVar14;
LAB_001d3c16:
        local_2a = 0;
        local_2c = 0;
        local_30 = 0;
        puVar11[0xc] = 0;
        __aeabi_memcpy(puVar11 + 0xd,&local_38,7);
        *(undefined4 *)(puVar11 + 0x14) = 0;
        local_32 = 0;
        local_34 = 0;
        local_38 = 0;
        goto LAB_001d43b8;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x3d7c72;
    }
    else {
      if (cVar1 != 'r') {
        if (cVar1 != 'o') goto switchD_001d3522_caseD_62;
        __aeabi_memcpy(&local_30,"operator||",7);
        uVar14 = 0x7c7c72;
        goto LAB_001d42e6;
      }
      __aeabi_memcpy(&local_30,"operator|",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if (puVar11 < (undefined1 *)param_3[2]) {
        *puVar11 = 0x12;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        uVar14 = 0x7c72;
        break;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x7c72;
    }
LAB_001d4baa:
    puVar12[2] = uVar14;
LAB_001d4bac:
    local_2a = 0;
    local_2c = 0;
    local_30 = 0;
    *(undefined1 *)(puVar12 + 3) = 0;
    __aeabi_memcpy((undefined1 *)((int)puVar12 + 0xd),&local_38,7);
    puVar12[5] = 0;
    local_32 = 0;
    local_44 = local_44 + 6;
    local_34 = 0;
    local_38 = 0;
    FUN_001cce32(param_3,auStack_4c);
LAB_001d4c66:
    FUN_001cceae(auStack_4c);
    goto switchD_001d3522_caseD_62;
  case 0x70:
    switch(param_1[1]) {
    case 0x6c:
      break;
    case 0x6d:
      pvVar4 = malloc(0x10);
      pcVar8 = "operator->*";
LAB_001d4232:
      uVar14 = 0xb;
      __aeabi_memcpy(pvVar4,pcVar8,0xb);
      local_2a = 0;
      local_2c = 0;
      *(undefined1 *)((int)pvVar4 + 0xb) = 0;
      local_30 = 0;
      puVar12 = (undefined4 *)param_3[1];
      if (puVar12 < (undefined4 *)param_3[2]) {
LAB_001d425a:
        uVar5 = 0x11;
        goto LAB_001d425c;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      uVar14 = 0x11;
      uVar5 = 0xb;
LAB_001d48d2:
      puVar12 = local_44;
      *local_44 = uVar14;
      local_44[1] = uVar5;
      local_44[2] = pvVar4;
      *(undefined1 *)(local_44 + 3) = 0;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 0xd),&local_30,7);
      puVar12[5] = 0;
      local_2a = 0;
      local_2c = 0;
      local_30 = 0;
LAB_001d4c56:
      local_44 = local_44 + 6;
      FUN_001cce32(param_3,auStack_4c);
      goto LAB_001d4c66;
    case 0x6e:
    case 0x6f:
    case 0x71:
    case 0x72:
      goto switchD_001d3522_caseD_62;
    case 0x70:
      __aeabi_memcpy(&local_30,"operator++",7);
      uVar14 = 0x2b2b72;
      goto LAB_001d42e6;
    case 0x73:
      break;
    case 0x74:
      __aeabi_memcpy(&local_30,"operator->",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if (puVar11 < (undefined1 *)param_3[2]) {
        *puVar11 = 0x14;
        __aeabi_memcpy(puVar11 + 1,&local_30,7);
        *(undefined4 *)(puVar11 + 8) = 0x3e2d72;
        local_2a = 0;
        local_2c = 0;
        local_30 = 0;
        puVar11[0xc] = 0;
        __aeabi_memcpy(puVar11 + 0xd,&local_38,7);
        *(undefined4 *)(puVar11 + 0x14) = 0;
        goto LAB_001d4422;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x3e2d72;
      goto LAB_001d4baa;
    default:
      if (param_1[1] != 'L') goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator+=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x3d2b72;
        goto LAB_001d4c2e;
      }
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x3d2b72;
      goto LAB_001d4392;
    }
    __aeabi_memcpy(&local_30,"operator+",7);
    local_32 = 0;
    local_34 = 0;
    local_38 = 0;
    puVar11 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar11) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x2b72;
      goto LAB_001d4baa;
    }
    *puVar11 = 0x12;
    __aeabi_memcpy(puVar11 + 1,&local_30,7);
    uVar14 = 0x2b72;
    break;
  case 0x71:
    if (param_1[1] != 'u') goto switchD_001d3522_caseD_62;
    __aeabi_memcpy(&local_30,"operator?",7);
    local_32 = 0;
    local_34 = 0;
    local_38 = 0;
    puVar11 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar11) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar9 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar9) {
          uVar13 = uVar9;
        }
      }
      FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
      puVar12 = local_44;
      *(undefined1 *)local_44 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
      uVar14 = 0x3f72;
      goto LAB_001d4baa;
    }
    *puVar11 = 0x12;
    __aeabi_memcpy(puVar11 + 1,&local_30,7);
    uVar14 = 0x3f72;
    break;
  case 0x72:
    bVar2 = param_1[1];
    if (bVar2 < 0x6d) {
      if (bVar2 != 0x4d) {
        if (bVar2 != 0x53) goto switchD_001d3522_caseD_62;
        pvVar4 = malloc(0x10);
        pcVar8 = "operator>>=";
        goto LAB_001d4232;
      }
      __aeabi_memcpy(&local_30,"operator%=",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x14;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x3d2572;
        goto LAB_001d4c2e;
      }
      *puVar11 = 0x14;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x3d2572;
    }
    else {
      if (bVar2 == 0x73) {
        __aeabi_memcpy(&local_30,"operator>>",7);
        uVar14 = 0x3e3e72;
        goto LAB_001d42e6;
      }
      if (bVar2 != 0x6d) goto switchD_001d3522_caseD_62;
      __aeabi_memcpy(&local_30,"operator%",7);
      local_32 = 0;
      local_34 = 0;
      local_38 = 0;
      puVar11 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar11) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar9 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar9) {
            uVar13 = uVar9;
          }
        }
        FUN_001ccdd4(auStack_4c,uVar13,iVar10,param_3 + 3);
        puVar12 = local_44;
        *(undefined1 *)local_44 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_44 + 1),&local_30,7);
        uVar14 = 0x2572;
        goto LAB_001d4baa;
      }
      *puVar11 = 0x12;
      __aeabi_memcpy(puVar11 + 1,&local_30,7);
      uVar14 = 0x2572;
    }
    break;
  case 0x76:
    if ((byte)param_1[1] - 0x30 < 10) {
      param_1 = param_1 + 2;
      uVar16 = FUN_001d4de4(param_1,param_2,param_3);
      bVar15 = (undefined1 *)uVar16 != param_1;
      if (bVar15) {
        uVar16 = CONCAT44(*param_3,param_3[1]);
      }
      if (bVar15 && (int)((ulonglong)uVar16 >> 0x20) != (int)uVar16) {
        FUN_001caf2a((int)uVar16 + -0x18,0,"operator ",9);
      }
    }
    goto switchD_001d3522_caseD_62;
  }
LAB_001d4392:
  *(undefined4 *)(puVar11 + 8) = uVar14;
LAB_001d4394:
  local_2a = 0;
  local_2c = 0;
  local_30 = 0;
  puVar11[0xc] = 0;
  __aeabi_memcpy(puVar11 + 0xd,&local_38,7);
  *(undefined4 *)(puVar11 + 0x14) = 0;
  local_32 = 0;
  local_34 = 0;
  local_38 = 0;
LAB_001d43b8:
  param_3[1] = param_3[1] + 0x18;
switchD_001d3522_caseD_62:
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001d4cdc  @0x001d4cdc  (256 bytes)
void FUN_001d4cdc(int param_1,int param_2,int *param_3)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint local_38;
  uint local_34;
  void *local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((((param_1 != param_2) && (iVar1 = FUN_001d4de4(param_1,param_2,param_3), iVar1 != param_1))
      && (iVar2 = FUN_001cb15c(iVar1,param_2,param_3), iVar2 != iVar1)) &&
     (iVar1 = param_3[1], 1 < (uint)((iVar1 - *param_3 >> 3) * -0x55555555))) {
    uVar5 = *(uint *)(iVar1 + -8);
    iVar2 = *(int *)(iVar1 + -4);
    if ((*(byte *)(iVar1 + -0xc) & 1) == 0) {
      iVar2 = iVar1 + -0xb;
      uVar5 = (uint)(*(byte *)(iVar1 + -0xc) >> 1);
    }
    puVar3 = (uint *)FUN_001cb080(iVar1 + -0x18,iVar2,uVar5);
    local_38 = *puVar3;
    local_34 = puVar3[1];
    local_30 = (void *)puVar3[2];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    iVar2 = param_3[1];
    iVar1 = iVar2;
    do {
      param_3[1] = iVar1 + -0x18;
      if ((*(byte *)(iVar1 + -0xc) & 1) != 0) {
        free(*(void **)(iVar1 + -4));
      }
      if ((*(byte *)(iVar1 + -0x18) & 1) != 0) {
        free(*(void **)(iVar1 + -0x10));
      }
      __ptr = local_30;
      iVar1 = param_3[1];
    } while (iVar1 != iVar2 + -0x18);
    uVar5 = local_38 & 1;
    uVar6 = local_34;
    pvVar4 = local_30;
    if ((local_38 & 1) == 0) {
      pvVar4 = (void *)((uint)&local_38 | 1);
      uVar6 = local_38 >> 1 & 0x7f;
    }
    FUN_001cb080(iVar2 + -0x30,pvVar4,uVar6);
    if (uVar5 != 0) {
      free(__ptr);
    }
  }
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

// ===== FUN_001d4de4  @0x001d4de4  (776 bytes)
void FUN_001d4de4(byte *param_1,byte *param_2,int *param_3)

{
  bool bVar1;
  byte bVar2;
  void *__ptr;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  void *pvVar12;
  uint local_68;
  uint local_64;
  void *local_60;
  uint local_58;
  uint local_54;
  byte *local_50;
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_38;
  undefined2 local_34;
  undefined1 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (((param_1 != param_2) && (uVar9 = *param_1 - 0x30, uVar9 < 10)) &&
     (pbVar11 = param_1 + 1, pbVar11 != param_2)) {
    uVar4 = *pbVar11 - 0x30;
    if (uVar4 < 10) {
      pbVar3 = param_1 + 2;
      do {
        pbVar11 = pbVar3;
        if (param_2 == pbVar11) goto LAB_001d50d2;
        uVar9 = uVar4 + uVar9 * 10;
        uVar4 = *pbVar11 - 0x30;
        pbVar3 = pbVar11 + 1;
      } while (uVar4 < 10);
    }
    if (uVar9 <= (uint)((int)param_2 - (int)pbVar11)) {
      bVar1 = false;
      local_60 = (void *)0x0;
      local_68 = 0;
      local_64 = 0;
      FUN_001c5e62(&local_68,pbVar11,uVar9);
      __ptr = local_60;
      uVar9 = local_68;
      local_50 = (byte *)0x0;
      pvVar12 = (void *)((uint)&local_68 | 1);
      local_58 = 0;
      local_54 = 0;
      bVar2 = (byte)local_68;
      uVar4 = local_64;
      pvVar7 = local_60;
      if ((local_68 & 1) == 0) {
        uVar4 = (uint)((byte)local_68 >> 1);
        pvVar7 = pvVar12;
      }
      if (9 < uVar4) {
        uVar4 = 10;
      }
      FUN_001c5e62(&local_58,pvVar7,uVar4);
      uVar4 = local_58 & 1;
      uVar5 = local_54;
      if ((local_58 & 1) == 0) {
        uVar5 = local_58 >> 1 & 0x7f;
      }
      if (uVar5 == 10) {
        pbVar11 = local_50;
        if ((local_58 & 1) == 0) {
          pbVar11 = (byte *)((uint)&local_58 | 1);
        }
        iVar6 = memcmp(pbVar11,"_GLOBAL__N",10);
        if (iVar6 == 0) {
          bVar1 = true;
        }
      }
      if (uVar4 != 0) {
        free(local_50);
      }
      if (bVar1) {
        pvVar7 = malloc(0x20);
        __aeabi_memcpy(pvVar7,"(anonymous namespace)",0x15);
        local_2a = 0;
        local_2c = 0;
        *(undefined1 *)((int)pvVar7 + 0x15) = 0;
        local_30 = 0;
        puVar10 = (undefined4 *)param_3[1];
        if (puVar10 < (undefined4 *)param_3[2]) {
          *puVar10 = 0x21;
          puVar10[1] = 0x15;
          puVar10[2] = pvVar7;
          *(undefined1 *)(puVar10 + 3) = 0;
          __aeabi_memcpy((int)puVar10 + 0xd,&local_30,7);
          puVar10[5] = 0;
          local_2a = 0;
          local_2c = 0;
          local_30 = 0;
          param_3[1] = param_3[1] + 0x18;
        }
        else {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar8 = ((int)puVar10 - *param_3 >> 3) * -0x55555555;
          uVar4 = 0xaaaaaaa;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar5 = iVar8 + 1;
            uVar4 = iVar6 * 0x55555556;
            if (uVar4 < uVar5) {
              uVar4 = uVar5;
            }
          }
          FUN_001ccdd4(&local_58,uVar4,iVar8,param_3 + 3);
          pbVar11 = local_50;
          pbVar11[0] = 0x21;
          pbVar11[1] = 0;
          pbVar11[2] = 0;
          pbVar11[3] = 0;
          pbVar11[4] = 0x15;
          pbVar11[5] = 0;
          pbVar11[6] = 0;
          pbVar11[7] = 0;
          *(void **)(local_50 + 8) = pvVar7;
          local_50[0xc] = 0;
          __aeabi_memcpy(local_50 + 0xd,&local_30,7);
          pbVar11[0x14] = 0;
          pbVar11[0x15] = 0;
          pbVar11[0x16] = 0;
          pbVar11[0x17] = 0;
          local_2a = 0;
          local_50 = local_50 + 0x18;
          local_2c = 0;
          local_30 = 0;
          FUN_001cce32(param_3,&local_58);
          FUN_001cceae(&local_58);
        }
        if ((uVar9 & 1) != 0) {
          free(__ptr);
        }
      }
      else {
        __aeabi_memcpy(&local_40,pvVar12,7);
        local_60 = (void *)0x0;
        local_68 = 0;
        local_64 = 0;
        __aeabi_memcpy(&local_30,&local_40,7);
        local_3a = 0;
        local_3c = 0;
        local_32 = 0;
        local_34 = 0;
        local_40 = 0;
        local_38 = 0;
        pbVar11 = (byte *)param_3[1];
        if (pbVar11 < (byte *)param_3[2]) {
          *pbVar11 = bVar2;
          __aeabi_memcpy(pbVar11 + 1,&local_30,7);
          *(void **)(pbVar11 + 8) = __ptr;
          local_2a = 0;
          local_2c = 0;
          local_30 = 0;
          pbVar11[0xc] = 0;
          __aeabi_memcpy(pbVar11 + 0xd,&local_38,7);
          pbVar11[0x14] = 0;
          pbVar11[0x15] = 0;
          pbVar11[0x16] = 0;
          pbVar11[0x17] = 0;
          local_32 = 0;
          local_34 = 0;
          local_38 = 0;
          param_3[1] = param_3[1] + 0x18;
        }
        else {
          iVar6 = param_3[2] - *param_3 >> 3;
          iVar8 = ((int)pbVar11 - *param_3 >> 3) * -0x55555555;
          uVar9 = 0xaaaaaaa;
          if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
            uVar4 = iVar8 + 1;
            uVar9 = iVar6 * 0x55555556;
            if (uVar9 < uVar4) {
              uVar9 = uVar4;
            }
          }
          FUN_001ccdd4(&local_58,uVar9,iVar8,param_3 + 3);
          pbVar11 = local_50;
          *local_50 = bVar2;
          __aeabi_memcpy(local_50 + 1,&local_30,7);
          *(void **)(pbVar11 + 8) = __ptr;
          local_2a = 0;
          local_2c = 0;
          local_30 = 0;
          pbVar11[0xc] = 0;
          __aeabi_memcpy(pbVar11 + 0xd,&local_38,7);
          pbVar11[0x14] = 0;
          pbVar11[0x15] = 0;
          pbVar11[0x16] = 0;
          pbVar11[0x17] = 0;
          local_32 = 0;
          local_50 = local_50 + 0x18;
          local_34 = 0;
          local_38 = 0;
          FUN_001cce32(param_3,&local_58);
          FUN_001cceae(&local_58);
        }
      }
    }
  }
LAB_001d50d2:
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001d50fc  @0x001d50fc  (480 bytes)
void FUN_001d50fc(uint *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint __size;
  byte *pbVar9;
  
  bVar1 = *param_2;
  uVar6 = *(uint *)(param_2 + 4);
  if ((bVar1 & 1) == 0) {
    uVar6 = (uint)(bVar1 >> 1);
  }
  if ((int)uVar6 < 0xc) {
    if (uVar6 == 0) {
      FUN_001c5e34(param_1,param_2);
      return;
    }
    if (uVar6 == 0xb) {
      pbVar2 = *(byte **)(param_2 + 8);
      if ((bVar1 & 1) == 0) {
        pbVar2 = param_2 + 1;
      }
      iVar3 = memcmp(pbVar2,"std::string",0xb);
      if (iVar3 == 0) {
        FUN_001ccf02(param_2,
                     "std::basic_string<char, std::char_traits<char>, std::allocator<char> >",0x46);
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = 0;
        FUN_001c5e62(param_1,"basic_string",0xc);
        return;
      }
    }
  }
  else if (uVar6 == 0xc) {
    pbVar2 = *(byte **)(param_2 + 8);
    if ((bVar1 & 1) == 0) {
      pbVar2 = param_2 + 1;
    }
    iVar3 = memcmp(pbVar2,"std::istream",0xc);
    if (iVar3 == 0) {
      FUN_001ccf02(param_2,"std::basic_istream<char, std::char_traits<char> >",0x31);
      pcVar5 = "basic_istream";
LAB_001d52c2:
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      FUN_001c5e62(param_1,pcVar5,0xd);
      return;
    }
    pbVar2 = *(byte **)(param_2 + 8);
    if ((bVar1 & 1) == 0) {
      pbVar2 = param_2 + 1;
    }
    iVar3 = memcmp(pbVar2,"std::ostream",0xc);
    if (iVar3 == 0) {
      FUN_001ccf02(param_2,"std::basic_ostream<char, std::char_traits<char> >",0x31);
      pcVar5 = "basic_ostream";
      goto LAB_001d52c2;
    }
  }
  else if (uVar6 == 0xd) {
    pbVar9 = *(byte **)(param_2 + 8);
    pbVar2 = pbVar9;
    if ((bVar1 & 1) == 0) {
      pbVar2 = param_2 + 1;
    }
    iVar3 = memcmp(pbVar2,"std::iostream",0xd);
    if (iVar3 == 0) {
      FUN_001ccf02(param_2,"std::basic_iostream<char, std::char_traits<char> >",0x32);
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      FUN_001c5e62(param_1,"basic_iostream",0xe);
      return;
    }
    goto LAB_001d51f2;
  }
  pbVar9 = *(byte **)(param_2 + 8);
LAB_001d51f2:
  pbVar2 = param_2 + 1;
  if ((bVar1 & 1) != 0) {
    pbVar2 = pbVar9;
  }
  pbVar7 = pbVar2 + uVar6;
  pbVar9 = pbVar7;
  if (pbVar7[-1] == 0x3e) {
    iVar3 = 1;
LAB_001d520a:
    do {
      pbVar9 = pbVar7 + -1;
      do {
        pbVar7 = pbVar9;
        if (pbVar2 == pbVar7) goto LAB_001d522c;
        pbVar9 = pbVar7 + -1;
        if (*pbVar9 == 0x3e) {
          iVar3 = iVar3 + 1;
          goto LAB_001d520a;
        }
      } while (*pbVar9 != 0x3c);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  pbVar7 = pbVar9;
  if ((int)pbVar9 - (int)pbVar2 < 2) {
LAB_001d522c:
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    return;
  }
  do {
    pbVar4 = pbVar7 + -1;
    pbVar8 = pbVar2;
    if (pbVar2 == pbVar4) break;
    pbVar8 = pbVar7;
    pbVar7 = pbVar4;
  } while (*pbVar4 != 0x3a);
  uVar6 = (int)pbVar9 - (int)pbVar8;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar6 < 0xb) {
    pbVar2 = (byte *)((int)param_1 + 1);
    *(char *)param_1 = (char)uVar6 * '\x02';
  }
  else {
    __size = uVar6 + 0x10 & 0xfffffff0;
    pbVar2 = malloc(__size);
    *param_1 = __size | 1;
    param_1[1] = uVar6;
    param_1[2] = (uint)pbVar2;
  }
  pbVar7 = pbVar2;
  if (pbVar8 != pbVar9) {
    do {
      pbVar4 = pbVar8 + 1;
      *pbVar7 = *pbVar8;
      pbVar7 = pbVar7 + 1;
      pbVar8 = pbVar4;
    } while (pbVar9 != pbVar4);
    pbVar2 = pbVar2 + uVar6;
  }
  *pbVar2 = 0;
  return;
}

// ===== FUN_001d530c  @0x001d530c  (98 bytes)
void FUN_001d530c(uint *param_1,byte param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  bVar1 = (byte)*param_1;
  if ((bVar1 & 1) == 0) {
    uVar4 = (uint)(bVar1 >> 1);
    uVar2 = 10;
  }
  else {
    uVar4 = param_1[1];
    uVar2 = (*param_1 & 0xfffffffe) - 1;
  }
  if (uVar4 == uVar2) {
    FUN_001d2ed2(param_1,uVar2,1,uVar2,uVar2,0);
    bVar1 = (byte)*param_1;
  }
  if ((bVar1 & 1) == 0) {
    pbVar3 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = (char)(uVar4 << 1) + 2;
  }
  else {
    pbVar3 = (byte *)param_1[2];
    param_1[1] = uVar4 + 1;
  }
  pbVar3[uVar4] = param_2;
  pbVar3[uVar4 + 1] = 0;
  return;
}

// ===== FUN_001d536e  @0x001d536e  (100 bytes)
byte * FUN_001d536e(byte *param_1,byte *param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  if (param_1 != param_2) {
    if (*param_1 == 0x5f) {
      if (param_1 + 1 != param_2) {
        uVar1 = (uint)param_1[1];
        if (uVar1 - 0x30 < 10) {
          return param_1 + 2;
        }
        if (uVar1 == 0x5f) {
          for (pbVar2 = param_1 + 2; pbVar2 != param_2; pbVar2 = pbVar2 + 1) {
            if (9 < *pbVar2 - 0x30) {
              if (*pbVar2 == 0x5f) {
                param_1 = pbVar2 + 1;
              }
              return param_1;
            }
          }
        }
      }
    }
    else {
      pbVar2 = param_1;
      if (9 < *param_1 - 0x30) {
        return param_1;
      }
      do {
        pbVar2 = pbVar2 + 1;
        if (param_2 == pbVar2) {
          return param_2;
        }
      } while (*pbVar2 - 0x30 < 10);
    }
  }
  return param_1;
}

// ===== FUN_001d53d2  @0x001d53d2  (76 bytes)
undefined4 * FUN_001d53d2(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  void *pvVar1;
  void *pvVar2;
  undefined4 *puVar3;
  
  pvVar1 = (void *)0x0;
  param_1[3] = 0;
  param_1[4] = param_4;
  if (param_2 != 0) {
    puVar3 = (undefined4 *)(*param_4 + 0x1000);
    pvVar1 = *(void **)(*param_4 + 0x1000);
    if ((uint)((int)puVar3 - (int)pvVar1) < (uint)(param_2 << 4)) {
      pvVar1 = malloc(param_2 * 0x10);
    }
    else {
      *puVar3 = (void *)(param_2 * 0x10 + (int)pvVar1);
    }
  }
  pvVar2 = (void *)((int)pvVar1 + param_3 * 0x10);
  *param_1 = pvVar1;
  param_1[1] = pvVar2;
  param_1[2] = pvVar2;
  param_1[3] = (void *)((int)pvVar1 + param_2 * 0x10);
  return param_1;
}

// ===== FUN_001d541e  @0x001d541e  (108 bytes)
void FUN_001d541e(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)*param_1;
  if ((undefined4 *)param_1[1] == puVar5) {
    iVar3 = param_2[1];
  }
  else {
    iVar3 = param_2[1];
    puVar2 = (undefined4 *)param_1[1];
    do {
      *(undefined4 *)(iVar3 + -0x10) = 0;
      *(undefined4 *)(iVar3 + -0xc) = 0;
      uVar4 = puVar2[-1];
      *(undefined4 *)(iVar3 + -8) = 0;
      *(undefined4 *)(iVar3 + -4) = uVar4;
      puVar1 = puVar2 + -4;
      *(undefined4 *)(iVar3 + -0x10) = *puVar1;
      *(undefined4 *)(iVar3 + -0xc) = puVar2[-3];
      *(undefined4 *)(iVar3 + -8) = puVar2[-2];
      *puVar1 = 0;
      puVar2[-3] = 0;
      puVar2[-2] = 0;
      iVar3 = param_2[1] + -0x10;
      param_2[1] = iVar3;
      puVar2 = puVar1;
    } while (puVar5 != puVar1);
    puVar5 = (undefined4 *)*param_1;
  }
  *param_1 = iVar3;
  param_2[1] = puVar5;
  iVar3 = param_1[1];
  param_1[1] = param_2[2];
  param_2[2] = iVar3;
  iVar3 = param_1[2];
  param_1[2] = param_2[3];
  param_2[3] = iVar3;
  *param_2 = param_2[1];
  return;
}

// ===== FUN_001d548a  @0x001d548a  (44 bytes)
int * FUN_001d548a(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  while (param_1[2] != iVar1) {
    param_1[2] = param_1[2] + -0x10;
    FUN_001c5dac();
  }
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_001c5e0a(*(undefined4 *)param_1[4],iVar1,param_1[3] - iVar1);
  }
  return param_1;
}

// ===== FUN_001d54b6  @0x001d54b6  (166 bytes)
byte * FUN_001d54b6(byte *param_1,byte *param_2,int *param_3)

{
  undefined1 uVar1;
  byte bVar2;
  byte *__ptr;
  void *pvVar3;
  undefined1 *puVar4;
  int iVar5;
  float *pfVar6;
  uint *puVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  byte *pbVar17;
  char cVar18;
  uint uVar19;
  byte *pbVar20;
  undefined1 *puVar21;
  bool bVar22;
  double dVar23;
  undefined4 uStack_ac;
  float afStack_a8 [2];
  void *pvStack_a0;
  uint uStack_98;
  undefined4 uStack_94;
  byte *pbStack_90;
  undefined4 uStack_88;
  undefined2 uStack_84;
  undefined1 uStack_82;
  undefined4 uStack_80;
  undefined2 uStack_7c;
  undefined1 uStack_7a;
  uint uStack_78;
  uint uStack_74;
  void *pvStack_70;
  uint uStack_68;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  uint auStack_50 [2];
  undefined1 *puStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  void *pvStack_3c;
  int iStack_28;
  
  if (param_1 == param_2) {
    return param_1;
  }
  bVar2 = *param_1;
  if (bVar2 == 0x4a) {
    pbVar11 = param_1 + 1;
    if (param_1 + 1 == param_2) {
      return param_1;
    }
    do {
      if (*pbVar11 == 0x45) {
        return pbVar11 + 1;
      }
      pbVar17 = (byte *)FUN_001d54b6(pbVar11,param_2,param_3);
      bVar22 = pbVar17 != pbVar11;
      pbVar11 = pbVar17;
    } while (bVar22);
    return param_1;
  }
  if (bVar2 != 0x4c) {
    if (bVar2 != 0x58) {
      pbVar11 = (byte *)FUN_001c6af0(param_1,param_2,param_3);
      return pbVar11;
    }
    pbVar17 = param_1 + 1;
    pbVar11 = (byte *)FUN_001ccfb8(pbVar17,param_2,param_3);
LAB_001d5522:
    if ((pbVar11 != pbVar17 && pbVar11 != param_2) && (*pbVar11 == 0x45)) {
      param_1 = pbVar11 + 1;
    }
    return param_1;
  }
  if ((param_1 + 1 != param_2) && (param_1[1] == 0x5a)) {
    pbVar17 = param_1 + 2;
    pbVar11 = (byte *)FUN_001c5f90(pbVar17,param_2,param_3);
    goto LAB_001d5522;
  }
  iStack_28 = __stack_chk_guard;
  if (((int)param_2 - (int)param_1 < 4) || (*param_1 != 0x4c)) goto switchD_001d0fba_caseD_54;
  pbVar11 = param_1 + 1;
  uVar19 = 0xaaaaaaa;
  switch(*pbVar11) {
  case 0x54:
    goto switchD_001d0fba_caseD_54;
  default:
    pbVar17 = (byte *)FUN_001c6af0(pbVar11,param_2,param_3);
    if (pbVar17 != pbVar11 && pbVar17 != param_2) {
      uVar19 = (uint)*pbVar17;
      pbVar11 = pbVar17;
      if (uVar19 == 0x45) {
        param_1 = pbVar17 + 1;
      }
      else {
        while (uVar19 - 0x30 < 10) {
          pbVar11 = pbVar11 + 1;
          if (param_2 == pbVar11) goto switchD_001d0fba_caseD_54;
          uVar19 = (uint)*pbVar11;
        }
        if (((pbVar11 != pbVar17) && (uVar19 == 0x45)) && (iVar5 = param_3[1], *param_3 != iVar5)) {
          uVar19 = *(uint *)(iVar5 + -8);
          iVar14 = *(int *)(iVar5 + -4);
          if ((*(byte *)(iVar5 + -0xc) & 1) == 0) {
            iVar14 = iVar5 + -0xb;
            uVar19 = (uint)(*(byte *)(iVar5 + -0xc) >> 1);
          }
          uStack_ac = iVar5 - 0x18;
          pfVar6 = (float *)FUN_001cb080(uStack_ac,iVar14,uVar19);
          afStack_a8[0] = *pfVar6;
          afStack_a8[1] = pfVar6[1];
          pvStack_a0 = (void *)pfVar6[2];
          *pfVar6 = 0.0;
          pfVar6[1] = 0.0;
          pfVar6[2] = 0.0;
          puVar7 = (uint *)FUN_001caf2a(afStack_a8,0,&DAT_00222248,1);
          uStack_78 = *puVar7;
          uStack_74 = puVar7[1];
          pvStack_70 = (void *)puVar7[2];
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7[2] = 0;
          puVar7 = (uint *)FUN_001cb080(&uStack_78,&DAT_0022045d,1);
          uStack_68 = *puVar7;
          uStack_64 = puVar7[1];
          puStack_60 = (undefined1 *)puVar7[2];
          uVar19 = (int)pbVar11 - (int)pbVar17;
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7[2] = 0;
          pbStack_90 = (byte *)0x0;
          uStack_98 = 0;
          uStack_94 = 0;
          if (uVar19 < 0xb) {
            uStack_98 = (uint)(byte)((char)uVar19 * '\x02');
            pbVar8 = (byte *)((uint)&uStack_98 | 1);
            pbVar9 = pbVar8;
          }
          else {
            uVar16 = uVar19 + 0x10 & 0xfffffff0;
            pbVar8 = malloc(uVar16);
            uStack_98 = uVar16 | 1;
            pbStack_90 = pbVar8;
            uStack_94 = uVar19;
            pbVar9 = pbVar8;
          }
          do {
            __ptr = pbStack_90;
            uVar16 = uStack_98;
            pbVar20 = pbVar17 + 1;
            *pbVar8 = *pbVar17;
            pbVar8 = pbVar8 + 1;
            pbVar17 = pbVar20;
          } while (pbVar11 != pbVar20);
          pbVar9[uVar19] = 0;
          uVar19 = uStack_94;
          pbVar17 = pbStack_90;
          if ((uStack_98 & 1) == 0) {
            pbVar17 = (byte *)((uint)&uStack_98 | 1);
            uVar19 = uStack_98 >> 1 & 0x7f;
          }
          puVar10 = (undefined4 *)FUN_001cb080(&uStack_68,pbVar17,uVar19);
          uVar1 = *(undefined1 *)puVar10;
          __aeabi_memcpy(&uStack_88,(int)puVar10 + 1,7);
          puVar21 = (undefined1 *)puVar10[2];
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          auStack_50[0] = CONCAT31(auStack_50[0]._1_3_,uVar1);
          __aeabi_memcpy((uint)auStack_50 | 1,&uStack_88,7);
          uStack_82 = 0;
          uStack_84 = 0;
          uStack_88 = 0;
          pvStack_3c = (void *)0x0;
          uStack_44 = 0;
          uStack_40 = 0;
          puStack_48 = puVar21;
          FUN_001d0d6c(uStack_ac,auStack_50);
          if ((uStack_44 & 1) != 0) {
            free(pvStack_3c);
          }
          if ((auStack_50[0] & 1) != 0) {
            free(puStack_48);
          }
          if ((uVar16 & 1) != 0) {
            free(__ptr);
          }
          if ((uStack_68 & 1) != 0) {
            free(puStack_60);
          }
          if ((uStack_78 & 1) != 0) {
            free(pvStack_70);
          }
          if (((uint)afStack_a8[0] & 1) != 0) {
            free(pvStack_a0);
          }
          param_1 = pbVar11 + 1;
        }
      }
    }
    goto switchD_001d0fba_caseD_54;
  case 0x5f:
    if (((param_1[2] == 0x5a) &&
        (pbVar11 = (byte *)FUN_001c5f90(param_1 + 3,param_2,param_3),
        pbVar11 != param_1 + 3 && pbVar11 != param_2)) && (*pbVar11 == 0x45)) {
      param_1 = pbVar11 + 1;
    }
    goto switchD_001d0fba_caseD_54;
  case 0x61:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,"signed char",0xb);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x62:
    if (param_1[3] != 0x45) goto switchD_001d0fba_caseD_54;
    if (param_1[2] == 0x31) {
      uStack_64 = (uint)uStack_64._3_1_ << 0x18;
      uStack_68 = 0;
      puVar21 = (undefined1 *)param_3[1];
      if (puVar21 < (undefined1 *)param_3[2]) {
        *puVar21 = 8;
        *(undefined4 *)(puVar21 + 1) = 0x65757274;
        puVar21[5] = 0;
        *(undefined2 *)(puVar21 + 6) = 0;
        *(undefined4 *)(puVar21 + 8) = 0;
        goto LAB_001d172e;
      }
      iVar5 = param_3[2] - *param_3 >> 3;
      iVar14 = ((int)puVar21 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
        uVar16 = iVar14 + 1;
        uVar19 = iVar5 * 0x55555556;
        if (uVar19 < uVar16) {
          uVar19 = uVar16;
        }
      }
      FUN_001ccdd4(auStack_50,uVar19,iVar14,param_3 + 3);
      *puStack_48 = 8;
      *(undefined4 *)(puStack_48 + 1) = 0x65757274;
      puStack_48[5] = 0;
      *(undefined2 *)(puStack_48 + 6) = 0;
      *(undefined4 *)(puStack_48 + 8) = 0;
LAB_001d1880:
      puVar21 = puStack_48;
      puStack_48[0xc] = 0;
      __aeabi_memcpy(puStack_48 + 0xd,&uStack_68,7);
      *(undefined4 *)(puVar21 + 0x14) = 0;
      puStack_48 = puStack_48 + 0x18;
      uStack_64 = uStack_64 & 0xff000000;
      uStack_68 = 0;
      FUN_001cce32(param_3,auStack_50);
      FUN_001cceae(auStack_50);
    }
    else {
      if (param_1[2] != 0x30) goto switchD_001d0fba_caseD_54;
      uStack_74._0_1_ = 0x65;
      uStack_64 = (uint)uStack_64._3_1_ << 0x18;
      uStack_78 = 0x736c6166;
      uStack_68 = 0;
      puVar21 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar21) {
        iVar5 = param_3[2] - *param_3 >> 3;
        iVar14 = ((int)puVar21 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar5 * -0x55555555) < 0x5555555) {
          uVar16 = iVar14 + 1;
          uVar19 = iVar5 * 0x55555556;
          if (uVar19 < uVar16) {
            uVar19 = uVar16;
          }
        }
        FUN_001ccdd4(auStack_50,uVar19,iVar14,param_3 + 3);
        *puStack_48 = 10;
        puStack_48[5] = (undefined1)uStack_74;
        *(uint *)(puStack_48 + 1) = uStack_78;
        puStack_48[6] = 0;
        puStack_48[7] = 0;
        *(undefined4 *)(puStack_48 + 8) = 0;
        uStack_74 = (uint)uStack_74._1_3_ << 8;
        uStack_78 = 0;
        goto LAB_001d1880;
      }
      *puVar21 = 10;
      puVar21[5] = 0x65;
      *(undefined4 *)(puVar21 + 1) = 0x736c6166;
      puVar21[6] = 0;
      puVar21[7] = 0;
      *(undefined4 *)(puVar21 + 8) = 0;
      uStack_74 = (uint)uStack_74._1_3_ << 8;
      uStack_78 = 0;
LAB_001d172e:
      uStack_68 = 0;
      puVar21[0xc] = 0;
      __aeabi_memcpy(puVar21 + 0xd,&uStack_68,7);
      *(undefined4 *)(puVar21 + 0x14) = 0;
      uStack_64 = uStack_64 & 0xff000000;
      uStack_68 = 0;
      param_3[1] = param_3[1] + 0x18;
    }
    param_1 = param_1 + 4;
    goto switchD_001d0fba_caseD_54;
  case 99:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,&DAT_002222a1,4);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 100:
    if ((uint)((int)param_2 - (int)(param_1 + 2)) < 0x11) goto LAB_001d1364;
    uVar16 = (uint)param_1[2];
    iVar14 = -3;
    iVar5 = 0;
    do {
      iVar15 = iVar5;
      if ((*(byte *)(_ctype_ + 1 + uVar16) & 0x44) == 0) goto LAB_001d1364;
      if (9 < uVar16 - 0x30) {
        uVar16 = uVar16 + 9;
      }
      iVar14 = iVar14 + -2;
      cVar18 = -0x57;
      if (param_1[iVar15 * 2 + 3] - 0x30 < 10) {
        cVar18 = -0x30;
      }
      cVar18 = cVar18 + param_1[iVar15 * 2 + 3] + (char)(uVar16 << 4);
      *(char *)((int)afStack_a8 + iVar15) = cVar18;
      uVar16 = (uint)param_1[iVar15 * 2 + 4];
      iVar5 = iVar15 + 1;
    } while (iVar14 != -0x13);
    if (uVar16 != 0x45) goto LAB_001d1364;
    if ((afStack_a8 < (float *)((int)afStack_a8 + iVar15)) && (iVar15 + 1 != 0)) {
      uVar1 = afStack_a8[0]._0_1_;
      afStack_a8[0] = (float)CONCAT31(afStack_a8[0]._1_3_,cVar18);
      *(undefined1 *)((int)afStack_a8 + iVar15) = uVar1;
      if (1 < iVar15 + -1) {
        puVar21 = (undefined1 *)((uint)afStack_a8 | 1);
        puVar12 = (undefined1 *)((int)&uStack_ac + iVar15 + 3);
        do {
          uVar1 = *puVar21;
          puVar4 = puVar21 + 1;
          *puVar21 = *puVar12;
          puVar13 = puVar12 + -1;
          *puVar12 = uVar1;
          puVar21 = puVar4;
          puVar12 = puVar13;
        } while (puVar4 < puVar13);
      }
    }
    __aeabi_memclr8(auStack_50,0x20);
    dVar23 = (double)CONCAT44(afStack_a8[1],afStack_a8[0]);
    uVar16 = FUN_001d6588(auStack_50,0x20,&DAT_002222c7);
    if (0x1f < uVar16) goto LAB_001d1364;
    iVar5 = -0x13;
LAB_001d167c:
    pvStack_70 = (void *)0x0;
    uStack_74 = 0;
    uStack_78 = 0;
    FUN_001c5e62(&uStack_78,auStack_50);
    uStack_ac = uStack_78 & 0xff;
    __aeabi_memcpy(&uStack_98,(uint)&uStack_78 | 1,7);
    pvVar3 = pvStack_70;
    pvStack_70 = (void *)0x0;
    uStack_74 = 0;
    uStack_7a = 0;
    uStack_7c = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    puVar21 = (undefined1 *)param_3[1];
    if (puVar21 < (undefined1 *)param_3[2]) {
      *puVar21 = (char)uStack_ac;
      __aeabi_memcpy(puVar21 + 1,&uStack_98,7);
      *(void **)(puVar21 + 8) = pvVar3;
      uStack_94 = (uint)uStack_94._3_1_ << 0x18;
      uStack_98 = 0;
      puVar21[0xc] = 0;
      __aeabi_memcpy(puVar21 + 0xd,&uStack_80,7);
      *(undefined4 *)(puVar21 + 0x14) = 0;
      uStack_7a = 0;
      uStack_7c = 0;
      uStack_80 = 0;
      param_3[1] = param_3[1] + 0x18;
    }
    else {
      iVar14 = param_3[2] - *param_3 >> 3;
      iVar15 = ((int)puVar21 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar14 * -0x55555555) < 0x5555555) {
        uVar16 = iVar15 + 1;
        uVar19 = iVar14 * 0x55555556;
        if (uVar19 < uVar16) {
          uVar19 = uVar16;
        }
      }
      FUN_001ccdd4(&uStack_68,uVar19,iVar15,param_3 + 3,dVar23);
      puVar21 = puStack_60;
      *puStack_60 = (char)uStack_ac;
      __aeabi_memcpy(puStack_60 + 1,&uStack_98,7);
      *(void **)(puVar21 + 8) = pvVar3;
      uStack_94 = (uint)uStack_94._3_1_ << 0x18;
      uStack_98 = 0;
      puVar21[0xc] = 0;
      __aeabi_memcpy(puVar21 + 0xd,&uStack_80,7);
      *(undefined4 *)(puVar21 + 0x14) = 0;
      uStack_7a = 0;
      puStack_60 = puStack_60 + 0x18;
      uStack_7c = 0;
      uStack_80 = 0;
      FUN_001cce32(param_3,&uStack_68);
      FUN_001cceae(&uStack_68);
    }
    iVar5 = -iVar5;
    goto LAB_001d1366;
  case 0x65:
    if (0x10 < (uint)((int)param_2 - (int)(param_1 + 2))) {
      uVar16 = (uint)param_1[2];
      iVar14 = -3;
      iVar5 = 0;
      do {
        iVar15 = iVar5;
        if ((*(byte *)(_ctype_ + 1 + uVar16) & 0x44) == 0) goto LAB_001d1364;
        if (9 < uVar16 - 0x30) {
          uVar16 = uVar16 + 9;
        }
        iVar14 = iVar14 + -2;
        cVar18 = -0x57;
        if (param_1[iVar15 * 2 + 3] - 0x30 < 10) {
          cVar18 = -0x30;
        }
        cVar18 = cVar18 + param_1[iVar15 * 2 + 3] + (char)(uVar16 << 4);
        *(char *)((int)afStack_a8 + iVar15) = cVar18;
        uVar16 = (uint)param_1[iVar15 * 2 + 4];
        iVar5 = iVar15 + 1;
      } while (iVar14 != -0x13);
      if (uVar16 == 0x45) {
        if ((afStack_a8 < (float *)((int)afStack_a8 + iVar15)) && (iVar15 + 1 != 0)) {
          uVar1 = afStack_a8[0]._0_1_;
          afStack_a8[0] = (float)CONCAT31(afStack_a8[0]._1_3_,cVar18);
          *(undefined1 *)((int)afStack_a8 + iVar15) = uVar1;
          if (1 < iVar15 + -1) {
            puVar21 = (undefined1 *)((uint)afStack_a8 | 1);
            puVar12 = (undefined1 *)((int)&uStack_ac + iVar15 + 3);
            do {
              uVar1 = *puVar21;
              puVar4 = puVar21 + 1;
              *puVar21 = *puVar12;
              puVar13 = puVar12 + -1;
              *puVar12 = uVar1;
              puVar21 = puVar4;
              puVar12 = puVar13;
            } while (puVar4 < puVar13);
          }
        }
        __aeabi_memclr8(auStack_50,0x28);
        dVar23 = (double)CONCAT44(afStack_a8[1],afStack_a8[0]);
        uVar16 = FUN_001d6588(auStack_50,0x28,&DAT_002222ca);
        if (uVar16 < 0x28) {
          iVar5 = -0x13;
          goto LAB_001d167c;
        }
      }
    }
    goto LAB_001d1364;
  case 0x66:
    if (8 < (uint)((int)param_2 - (int)(param_1 + 2))) {
      uVar16 = (uint)param_1[2];
      iVar14 = -3;
      iVar5 = 0;
      do {
        iVar15 = iVar5;
        if ((*(byte *)(_ctype_ + 1 + uVar16) & 0x44) == 0) goto LAB_001d1364;
        if (9 < uVar16 - 0x30) {
          uVar16 = uVar16 + 9;
        }
        iVar14 = iVar14 + -2;
        cVar18 = -0x57;
        if (param_1[iVar15 * 2 + 3] - 0x30 < 10) {
          cVar18 = -0x30;
        }
        cVar18 = cVar18 + param_1[iVar15 * 2 + 3] + (char)(uVar16 << 4);
        *(char *)((int)afStack_a8 + iVar15) = cVar18;
        uVar16 = (uint)param_1[iVar15 * 2 + 4];
        iVar5 = iVar15 + 1;
      } while (iVar14 != -0xb);
      if (uVar16 == 0x45) {
        if ((afStack_a8 < (float *)((int)afStack_a8 + iVar15)) && (iVar15 + 1 != 0)) {
          uVar1 = afStack_a8[0]._0_1_;
          afStack_a8[0] = (float)CONCAT31(afStack_a8[0]._1_3_,cVar18);
          *(undefined1 *)((int)afStack_a8 + iVar15) = uVar1;
          if (1 < iVar15 + -1) {
            puVar21 = (undefined1 *)((uint)afStack_a8 | 1);
            puVar12 = (undefined1 *)((int)&uStack_ac + iVar15 + 3);
            do {
              uVar1 = *puVar21;
              puVar4 = puVar21 + 1;
              *puVar21 = *puVar12;
              puVar13 = puVar12 + -1;
              *puVar12 = uVar1;
              puVar21 = puVar4;
              puVar12 = puVar13;
            } while (puVar4 < puVar13);
          }
        }
        __aeabi_memclr8(auStack_50,0x18);
        dVar23 = (double)afStack_a8[0];
        uVar16 = FUN_001d6588(auStack_50,0x18,&DAT_002222c3);
        iVar5 = -0xb;
        if (uVar16 < 0x18) goto LAB_001d167c;
      }
    }
LAB_001d1364:
    iVar5 = 2;
LAB_001d1366:
    if (iVar5 != 2) {
      param_1 = param_1 + iVar5;
    }
    goto switchD_001d0fba_caseD_54;
  case 0x68:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,"unsigned char",0xd);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x69:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,&DAT_0021f762,0);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x6a:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,&DAT_002222ac,1);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x6c:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,&DAT_002222ae,1);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x6d:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,&DAT_002222b0,2);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x6e:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,"__int128",8);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x6f:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,"unsigned __int128",0x11);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x73:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,"short",5);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x74:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,"unsigned short",0xe);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x77:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,"wchar_t",7);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x78:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,&DAT_002222b3,2);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
    break;
  case 0x79:
    puStack_48 = (undefined1 *)0x0;
    auStack_50[0] = 0;
    auStack_50[1] = 0;
    FUN_001c5e62(auStack_50,&DAT_002222b6,3);
    pbVar11 = (byte *)FUN_001d2ba0(param_1 + 2,param_2,auStack_50,param_3);
  }
  if ((auStack_50[0] & 1) != 0) {
    free(puStack_48);
  }
  if (pbVar11 != param_1 + 2) {
    param_1 = pbVar11;
  }
switchD_001d0fba_caseD_54:
  if (__stack_chk_guard - iStack_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - iStack_28);
  }
  return param_1;
}

// ===== FUN_001d555c  @0x001d555c  (3754 bytes)
void FUN_001d555c(undefined1 *param_1,undefined1 *param_2,int *param_3)

{
  int3 iVar1;
  byte bVar2;
  undefined2 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  undefined1 auStack_58 [8];
  undefined4 *local_50;
  undefined2 local_44;
  undefined1 local_42;
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined1 local_2e;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == param_2) goto switchD_001d559e_caseD_45;
  uVar13 = 0xaaaaaaa;
  bVar2 = local_40._3_1_;
  switch(*param_1) {
  case 0x44:
    if (param_1 + 1 == param_2) goto switchD_001d559e_caseD_45;
    uVar5 = 0x745f3233;
    switch(param_1[1]) {
    case 0x61:
      local_34 = (uint)local_34._3_1_ << 0x18;
      local_38 = 0;
      puVar12 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar12) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar8 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar8) {
            uVar13 = uVar8;
          }
        }
        FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
        puVar11 = local_50;
        *(undefined1 *)local_50 = 8;
        *(undefined4 *)((int)local_50 + 1) = 0x6f747561;
        *(undefined1 *)((int)local_50 + 5) = 0;
        *(undefined2 *)((int)local_50 + 6) = 0;
        local_50[2] = 0;
        *(undefined1 *)(local_50 + 3) = 0;
        __aeabi_memcpy((undefined1 *)((int)local_50 + 0xd),&local_38,7);
        puVar11[5] = 0;
        local_34 = local_34 & 0xff000000;
        local_38 = 0;
        goto LAB_001d6484;
      }
      *puVar12 = 8;
      *(undefined4 *)(puVar12 + 1) = 0x6f747561;
      puVar12[5] = 0;
      *(undefined2 *)(puVar12 + 6) = 0;
      *(undefined4 *)(puVar12 + 8) = 0;
      puVar12[0xc] = 0;
      __aeabi_memcpy(puVar12 + 0xd,&local_38,7);
      *(undefined4 *)(puVar12 + 0x14) = 0;
      local_34 = local_34 & 0xff000000;
      local_38 = 0;
      goto LAB_001d623e;
    default:
      goto switchD_001d559e_caseD_45;
    case 99:
      pvVar4 = malloc(0x10);
      pcVar7 = "decltype(auto)";
      break;
    case 100:
      __aeabi_memcpy(&local_38,"decimal64",7);
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
      puVar12 = (undefined1 *)param_3[1];
      if ((undefined1 *)param_3[2] <= puVar12) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar8 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar8) {
            uVar13 = uVar8;
          }
        }
        FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
        puVar11 = local_50;
        *(undefined1 *)local_50 = 0x12;
        __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,7);
        uVar5 = 0x3436;
        goto LAB_001d645c;
      }
      *puVar12 = 0x12;
      __aeabi_memcpy(puVar12 + 1,&local_38,7);
      uVar5 = 0x3436;
LAB_001d61d2:
      *(undefined4 *)(puVar12 + 8) = uVar5;
      local_34 = (uint)local_34._3_1_ << 0x18;
      goto LAB_001d6222;
    case 0x65:
      __aeabi_memcpy(&local_38,"decimal128",7);
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
      puVar12 = (undefined1 *)param_3[1];
      if (puVar12 < (undefined1 *)param_3[2]) {
        *puVar12 = 0x14;
        __aeabi_memcpy(puVar12 + 1,&local_38,7);
        *(undefined4 *)(puVar12 + 8) = 0x383231;
        local_34 = (uint)local_34._3_1_ << 0x18;
        local_38 = 0;
        puVar12[0xc] = 0;
        __aeabi_memcpy(puVar12 + 0xd,&local_40,7);
        *(undefined4 *)(puVar12 + 0x14) = 0;
        local_3a = 0;
        local_3c = 0;
        local_40 = 0;
        goto LAB_001d623e;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      puVar11 = local_50;
      *(undefined1 *)local_50 = 0x14;
      __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,7);
      puVar11[2] = 0x383231;
      local_34 = (uint)local_34._3_1_ << 0x18;
      local_38 = 0;
      *(undefined1 *)(puVar11 + 3) = 0;
      __aeabi_memcpy((undefined1 *)((int)puVar11 + 0xd),&local_40,7);
      puVar11[5] = 0;
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
      goto LAB_001d63b4;
    case 0x66:
      __aeabi_memcpy(&local_38,"decimal32",7);
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
      puVar12 = (undefined1 *)param_3[1];
      if (puVar12 < (undefined1 *)param_3[2]) {
        *puVar12 = 0x12;
        __aeabi_memcpy(puVar12 + 1,&local_38,7);
        uVar5 = 0x3233;
        goto LAB_001d61d2;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      puVar11 = local_50;
      *(undefined1 *)local_50 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,7);
      uVar5 = 0x3233;
      goto LAB_001d645c;
    case 0x68:
      __aeabi_memcpy(&local_38,"decimal16",7);
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
      puVar12 = (undefined1 *)param_3[1];
      if (puVar12 < (undefined1 *)param_3[2]) {
        *puVar12 = 0x12;
        __aeabi_memcpy(puVar12 + 1,&local_38,7);
        uVar5 = 0x3631;
        goto LAB_001d61d2;
      }
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      puVar11 = local_50;
      *(undefined1 *)local_50 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,7);
      uVar5 = 0x3631;
LAB_001d645c:
      puVar11[2] = uVar5;
      local_34 = (uint)local_34._3_1_ << 0x18;
LAB_001d6468:
      local_38 = 0;
      *(undefined1 *)(puVar11 + 3) = 0;
      __aeabi_memcpy((undefined1 *)((int)puVar11 + 0xd),&local_40,7);
      puVar11[5] = 0;
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
LAB_001d6484:
      local_50 = local_50 + 6;
      FUN_001cce32(param_3,auStack_58);
      goto LAB_001d6494;
    case 0x69:
      goto LAB_001d61e4;
    case 0x6e:
      pvVar4 = malloc(0x10);
      pcVar7 = "std::nullptr_t";
      break;
    case 0x73:
      uVar5 = 0x745f3631;
LAB_001d61e4:
      local_2e = 0;
      local_38 = 0x72616863;
      local_3a = 0;
      local_3c = 0;
      local_30 = 0;
      local_40 = 0;
      puVar12 = (undefined1 *)param_3[1];
      local_34 = uVar5;
      if ((undefined1 *)param_3[2] <= puVar12) {
        iVar6 = param_3[2] - *param_3 >> 3;
        iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
        if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
          uVar8 = iVar10 + 1;
          uVar13 = iVar6 * 0x55555556;
          if (uVar13 < uVar8) {
            uVar13 = uVar8;
          }
        }
        FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
        puVar11 = local_50;
        *(undefined1 *)local_50 = 0x10;
        __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,0xb);
        local_2e = 0;
        local_30 = 0;
        local_34 = 0;
        goto LAB_001d6468;
      }
      *puVar12 = 0x10;
      __aeabi_memcpy(puVar12 + 1,&local_38,0xb);
      local_2e = 0;
      local_30 = 0;
      local_34 = 0;
LAB_001d6222:
      local_38 = 0;
      puVar12[0xc] = 0;
      __aeabi_memcpy(puVar12 + 0xd,&local_40,7);
      *(undefined4 *)(puVar12 + 0x14) = 0;
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
      goto LAB_001d623e;
    }
    __aeabi_memcpy(pvVar4,pcVar7,0xe);
    local_34 = (uint)local_34._3_1_ << 0x18;
    *(undefined1 *)((int)pvVar4 + 0xe) = 0;
    local_38 = 0;
    puVar11 = (undefined4 *)param_3[1];
    if (puVar11 < (undefined4 *)param_3[2]) {
      *puVar11 = 0x11;
      puVar11[1] = 0xe;
      puVar11[2] = pvVar4;
      *(undefined1 *)(puVar11 + 3) = 0;
      __aeabi_memcpy((int)puVar11 + 0xd,&local_38,7);
      puVar11[5] = 0;
      local_34 = local_34 & 0xff000000;
      local_38 = 0;
LAB_001d623e:
      param_3[1] = param_3[1] + 0x18;
    }
    else {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      puVar11 = local_50;
      *local_50 = 0x11;
      local_50[1] = 0xe;
      local_50[2] = pvVar4;
      *(undefined1 *)(local_50 + 3) = 0;
      __aeabi_memcpy((undefined1 *)((int)local_50 + 0xd),&local_38,7);
      puVar11[5] = 0;
      local_34 = local_34 & 0xff000000;
      local_38 = 0;
LAB_001d63b4:
      local_50 = local_50 + 6;
      FUN_001cce32(param_3,auStack_58);
LAB_001d6494:
      FUN_001cceae(auStack_58);
    }
  default:
    goto switchD_001d559e_caseD_45;
  case 0x61:
    pvVar4 = malloc(0x10);
    pcVar7 = "signed char";
    goto LAB_001d58ec;
  case 0x62:
    local_34 = (uint)local_34._3_1_ << 0x18;
    uVar5 = 0x6c6f6f62;
    break;
  case 99:
    local_34 = (uint)local_34._3_1_ << 0x18;
    uVar5 = 0x72616863;
    break;
  case 100:
    local_3c = 0x656c;
    local_34 = (uint)local_34._3_1_ << 0x18;
    local_40 = 0x62756f64;
    local_38 = 0;
    puVar12 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar12) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      *(undefined1 *)local_50 = 0xc;
      *(short *)((int)local_50 + 5) = local_3c;
      *(uint *)((int)local_50 + 1) = local_40;
      *(undefined1 *)((int)local_50 + 7) = 0;
      local_50[2] = 0;
      local_3c = 0;
      goto LAB_001d5d20;
    }
    *puVar12 = 0xc;
    *(undefined2 *)(puVar12 + 5) = 0x656c;
    *(undefined4 *)(puVar12 + 1) = 0x62756f64;
    puVar12[7] = 0;
    *(undefined4 *)(puVar12 + 8) = 0;
    local_3c = 0;
    local_40 = 0;
    puVar12[0xc] = 0;
    __aeabi_memcpy(puVar12 + 0xd,&local_38,7);
    *(undefined4 *)(puVar12 + 0x14) = 0;
    goto LAB_001d5b48;
  case 0x65:
    pvVar4 = malloc(0x10);
    pcVar7 = "long double";
LAB_001d58ec:
    __aeabi_memcpy(pvVar4,pcVar7,0xb);
    local_34 = (uint)local_34._3_1_ << 0x18;
    *(undefined1 *)((int)pvVar4 + 0xb) = 0;
    local_38 = 0;
    puVar11 = (undefined4 *)param_3[1];
    if ((undefined4 *)param_3[2] <= puVar11) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      uVar5 = 0x11;
      uVar9 = 0xb;
      goto LAB_001d5f36;
    }
    *puVar11 = 0x11;
    uVar5 = 0xb;
LAB_001d5b34:
    local_38 = 0;
    puVar11[1] = uVar5;
    puVar11[2] = pvVar4;
    *(undefined1 *)(puVar11 + 3) = 0;
    __aeabi_memcpy((int)puVar11 + 0xd,&local_38,7);
    puVar11[5] = 0;
LAB_001d5b48:
    local_34 = local_34 & 0xff000000;
    local_38 = 0;
    goto LAB_001d5bc4;
  case 0x66:
    local_40 = 0x616f6c66;
    goto LAB_001d5aae;
  case 0x67:
    __aeabi_memcpy(&local_38,"__float128",7);
    local_3a = 0;
    local_3c = 0;
    local_40 = 0;
    puVar12 = (undefined1 *)param_3[1];
    if (puVar12 < (undefined1 *)param_3[2]) {
      *puVar12 = 0x14;
      __aeabi_memcpy(puVar12 + 1,&local_38,7);
      *(undefined4 *)(puVar12 + 8) = 0x383231;
      local_34 = (uint)local_34._3_1_ << 0x18;
      local_38 = 0;
      puVar12[0xc] = 0;
      __aeabi_memcpy(puVar12 + 0xd,&local_40,7);
      *(undefined4 *)(puVar12 + 0x14) = 0;
      local_3a = 0;
      local_3c = 0;
      local_40 = 0;
      goto LAB_001d5bc4;
    }
    iVar6 = param_3[2] - *param_3 >> 3;
    iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
      uVar8 = iVar10 + 1;
      uVar13 = iVar6 * 0x55555556;
      if (uVar13 < uVar8) {
        uVar13 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
    puVar11 = local_50;
    *(undefined1 *)local_50 = 0x14;
    __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,7);
    puVar11[2] = 0x383231;
    local_34 = (uint)local_34._3_1_ << 0x18;
    local_38 = 0;
    *(undefined1 *)(puVar11 + 3) = 0;
    __aeabi_memcpy((undefined1 *)((int)puVar11 + 0xd),&local_40,7);
    puVar11[5] = 0;
    local_3a = 0;
    local_3c = 0;
    local_40 = 0;
    goto LAB_001d5f58;
  case 0x68:
    pvVar4 = malloc(0x10);
    pcVar7 = "unsigned char";
    goto LAB_001d59ca;
  case 0x69:
    iVar1 = 0x74;
    uVar3 = 0x6e69;
    goto LAB_001d5a06;
  case 0x6a:
    pvVar4 = malloc(0x10);
    __aeabi_memcpy(pvVar4,"unsigned int",0xc);
    local_34 = (uint)local_34._3_1_ << 0x18;
    *(undefined1 *)((int)pvVar4 + 0xc) = 0;
    local_38 = 0;
    puVar11 = (undefined4 *)param_3[1];
    if ((undefined4 *)param_3[2] <= puVar11) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      uVar5 = 0x11;
      uVar9 = 0xc;
      goto LAB_001d5f36;
    }
    *puVar11 = 0x11;
    uVar5 = 0xc;
    goto LAB_001d5b34;
  case 0x6c:
    local_34 = (uint)local_34._3_1_ << 0x18;
    uVar5 = 0x676e6f6c;
    break;
  case 0x6d:
    pvVar4 = malloc(0x10);
    pcVar7 = "unsigned long";
LAB_001d59ca:
    __aeabi_memcpy(pvVar4,pcVar7,0xd);
    local_34 = (uint)local_34._3_1_ << 0x18;
    *(undefined1 *)((int)pvVar4 + 0xd) = 0;
    local_38 = 0;
    puVar11 = (undefined4 *)param_3[1];
    if ((undefined4 *)param_3[2] <= puVar11) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      uVar5 = 0x11;
      uVar9 = 0xd;
      goto LAB_001d5f36;
    }
    *puVar11 = 0x11;
    uVar5 = 0xd;
    goto LAB_001d5b34;
  case 0x6e:
    local_2e = 0;
    local_34 = 0x38323174;
    local_3a = 0;
    local_38 = 0x6e695f5f;
    local_3c = 0;
    local_30 = 0;
    local_40 = 0;
    puVar12 = (undefined1 *)param_3[1];
    if (puVar12 < (undefined1 *)param_3[2]) {
      *puVar12 = 0x10;
      __aeabi_memcpy(puVar12 + 1,&local_38,0xb);
      local_2e = 0;
      local_30 = 0;
      local_34 = 0;
      goto LAB_001d5ba8;
    }
    iVar6 = param_3[2] - *param_3 >> 3;
    iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
      uVar8 = iVar10 + 1;
      uVar13 = iVar6 * 0x55555556;
      if (uVar13 < uVar8) {
        uVar13 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
    puVar11 = local_50;
    *(undefined1 *)local_50 = 0x10;
    __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,0xb);
    local_2e = 0;
    local_30 = 0;
    local_34 = 0;
LAB_001d5fbe:
    local_38 = 0;
    *(undefined1 *)(puVar11 + 3) = 0;
    __aeabi_memcpy((undefined1 *)((int)puVar11 + 0xd),&local_40,7);
    puVar11[5] = 0;
    local_3a = 0;
    local_3c = 0;
    local_40 = 0;
    goto LAB_001d5fda;
  case 0x6f:
    pvVar4 = malloc(0x20);
    __aeabi_memcpy(pvVar4,"unsigned __int128",0x11);
    local_34 = (uint)local_34._3_1_ << 0x18;
    *(undefined1 *)((int)pvVar4 + 0x11) = 0;
    local_38 = 0;
    puVar11 = (undefined4 *)param_3[1];
    if (puVar11 < (undefined4 *)param_3[2]) {
      *puVar11 = 0x21;
      uVar5 = 0x11;
      goto LAB_001d5b34;
    }
    iVar6 = param_3[2] - *param_3 >> 3;
    iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
      uVar8 = iVar10 + 1;
      uVar13 = iVar6 * 0x55555556;
      if (uVar13 < uVar8) {
        uVar13 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
    uVar5 = 0x21;
    uVar9 = 0x11;
    goto LAB_001d5f36;
  case 0x73:
    local_40 = 0x726f6873;
LAB_001d5aae:
    local_3c._0_1_ = 0x74;
    local_34 = (uint)local_34._3_1_ << 0x18;
    local_38 = 0;
    puVar12 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar12) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      *(undefined1 *)local_50 = 10;
      *(undefined1 *)((int)local_50 + 5) = (undefined1)local_3c;
      *(uint *)((int)local_50 + 1) = local_40;
      *(undefined1 *)((int)local_50 + 6) = 0;
      *(undefined1 *)((int)local_50 + 7) = 0;
      local_50[2] = 0;
      local_3c = (ushort)local_3c._1_1_ << 8;
LAB_001d5d20:
      local_40 = 0;
LAB_001d5d22:
      puVar11 = local_50;
      *(undefined1 *)(local_50 + 3) = 0;
      __aeabi_memcpy((undefined1 *)((int)local_50 + 0xd),&local_38,7);
      puVar11[5] = 0;
      local_34 = local_34 & 0xff000000;
      local_38 = 0;
      goto LAB_001d5fda;
    }
    *puVar12 = 10;
    puVar12[5] = 0x74;
    *(uint *)(puVar12 + 1) = local_40;
    puVar12[6] = 0;
    puVar12[7] = 0;
    *(undefined4 *)(puVar12 + 8) = 0;
    local_3c = (ushort)local_3c._1_1_ << 8;
    local_40 = 0;
    puVar12[0xc] = 0;
    __aeabi_memcpy(puVar12 + 0xd,&local_38,7);
    *(undefined4 *)(puVar12 + 0x14) = 0;
    goto LAB_001d5af6;
  case 0x74:
    pvVar4 = malloc(0x10);
    __aeabi_memcpy(pvVar4,"unsigned short",0xe);
    local_34 = (uint)local_34._3_1_ << 0x18;
    *(undefined1 *)((int)pvVar4 + 0xe) = 0;
    local_38 = 0;
    puVar11 = (undefined4 *)param_3[1];
    if (puVar11 < (undefined4 *)param_3[2]) {
      *puVar11 = 0x11;
      uVar5 = 0xe;
      goto LAB_001d5b34;
    }
    iVar6 = param_3[2] - *param_3 >> 3;
    iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
      uVar8 = iVar10 + 1;
      uVar13 = iVar6 * 0x55555556;
      if (uVar13 < uVar8) {
        uVar13 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
    uVar5 = 0x11;
    uVar9 = 0xe;
    goto LAB_001d5f36;
  case 0x75:
    FUN_001d4de4(param_1 + 1,param_2,param_3);
    goto switchD_001d559e_caseD_45;
  case 0x76:
    local_34 = (uint)local_34._3_1_ << 0x18;
    uVar5 = 0x64696f76;
    break;
  case 0x77:
    __aeabi_memcpy(&local_38,"wchar_t",7);
    local_3a = 0;
    local_3c = 0;
    local_40 = 0;
    puVar12 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar12) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      puVar11 = local_50;
      *(undefined1 *)local_50 = 0xe;
      __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,7);
      puVar11[2] = 0;
LAB_001d5fb6:
      local_34 = (uint)local_34._3_1_ << 0x18;
      goto LAB_001d5fbe;
    }
    *puVar12 = 0xe;
    __aeabi_memcpy(puVar12 + 1,&local_38,7);
    *(undefined4 *)(puVar12 + 8) = 0;
    goto LAB_001d5ba0;
  case 0x78:
    __aeabi_memcpy(&local_38,"long long",7);
    local_3a = 0;
    local_3c = 0;
    local_40 = 0;
    puVar12 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar12) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      puVar11 = local_50;
      *(undefined1 *)local_50 = 0x12;
      __aeabi_memcpy((undefined1 *)((int)local_50 + 1),&local_38,7);
      puVar11[2] = 0x676e;
      goto LAB_001d5fb6;
    }
    *puVar12 = 0x12;
    __aeabi_memcpy(puVar12 + 1,&local_38,7);
    *(undefined4 *)(puVar12 + 8) = 0x676e;
LAB_001d5ba0:
    local_34 = (uint)local_34._3_1_ << 0x18;
LAB_001d5ba8:
    local_38 = 0;
    puVar12[0xc] = 0;
    __aeabi_memcpy(puVar12 + 0xd,&local_40,7);
    *(undefined4 *)(puVar12 + 0x14) = 0;
    local_3a = 0;
    local_3c = 0;
    local_40 = 0;
    goto LAB_001d5bc4;
  case 0x79:
    pvVar4 = malloc(0x20);
    __aeabi_memcpy(pvVar4,"unsigned long long",0x12);
    local_34 = (uint)local_34._3_1_ << 0x18;
    *(undefined1 *)((int)pvVar4 + 0x12) = 0;
    local_38 = 0;
    puVar11 = (undefined4 *)param_3[1];
    if (puVar11 < (undefined4 *)param_3[2]) {
      *puVar11 = 0x21;
      uVar5 = 0x12;
      goto LAB_001d5b34;
    }
    iVar6 = param_3[2] - *param_3 >> 3;
    iVar10 = ((int)puVar11 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
      uVar8 = iVar10 + 1;
      uVar13 = iVar6 * 0x55555556;
      if (uVar13 < uVar8) {
        uVar13 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
    uVar5 = 0x21;
    uVar9 = 0x12;
LAB_001d5f36:
    puVar11 = local_50;
    *local_50 = uVar5;
    local_50[1] = uVar9;
    local_50[2] = pvVar4;
    *(undefined1 *)(local_50 + 3) = 0;
    __aeabi_memcpy((undefined1 *)((int)local_50 + 0xd),&local_38,7);
    puVar11[5] = 0;
    local_34 = local_34 & 0xff000000;
    local_38 = 0;
LAB_001d5f58:
    local_50 = local_50 + 6;
    FUN_001cce32(param_3,auStack_58);
    goto LAB_001d5fea;
  case 0x7a:
    iVar1 = 0x2e;
    uVar3 = 0x2e2e;
LAB_001d5a06:
    local_40 = CONCAT13(local_40._3_1_,iVar1 << 0x10);
    local_42 = 0;
    local_44 = 0;
    local_34 = (uint)local_34._3_1_ << 0x18;
    local_40 = CONCAT22(local_40._2_2_,uVar3);
    local_38 = 0;
    puVar12 = (undefined1 *)param_3[1];
    if ((undefined1 *)param_3[2] <= puVar12) {
      iVar6 = param_3[2] - *param_3 >> 3;
      iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
      if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
        uVar8 = iVar10 + 1;
        uVar13 = iVar6 * 0x55555556;
        if (uVar13 < uVar8) {
          uVar13 = uVar8;
        }
      }
      FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
      *(undefined1 *)local_50 = 6;
      *(undefined1 *)((int)local_50 + 3) = local_40._2_1_;
      *(undefined2 *)((int)local_50 + 1) = (undefined2)local_40;
      *(undefined1 *)(local_50 + 1) = 0;
      *(undefined1 *)((int)local_50 + 7) = local_42;
      *(undefined2 *)((int)local_50 + 5) = local_44;
      local_50[2] = 0;
      local_42 = 0;
      local_40 = local_40 & 0xff000000;
      local_44 = 0;
      goto LAB_001d5d22;
    }
    *puVar12 = 6;
    local_40._2_1_ = (undefined1)iVar1;
    puVar12[3] = local_40._2_1_;
    *(undefined2 *)(puVar12 + 1) = uVar3;
    puVar12[4] = 0;
    puVar12[7] = 0;
    *(undefined2 *)(puVar12 + 5) = 0;
    *(undefined4 *)(puVar12 + 8) = 0;
    local_42 = 0;
    local_40 = (uint)bVar2 << 0x18;
    local_44 = 0;
    goto LAB_001d5a5a;
  }
  local_34 = (uint)local_34._2_2_ << 0x10;
  local_38 = 0;
  puVar12 = (undefined1 *)param_3[1];
  if (puVar12 < (undefined1 *)param_3[2]) {
    *puVar12 = 8;
    *(undefined4 *)(puVar12 + 1) = uVar5;
    puVar12[5] = 0;
    *(undefined2 *)(puVar12 + 6) = 0;
    *(undefined4 *)(puVar12 + 8) = 0;
LAB_001d5a5a:
    local_38 = 0;
    puVar12[0xc] = 0;
    __aeabi_memcpy(puVar12 + 0xd,&local_38,7);
    *(undefined4 *)(puVar12 + 0x14) = 0;
LAB_001d5af6:
    local_34 = local_34 & 0xff000000;
    local_38 = 0;
LAB_001d5bc4:
    param_3[1] = param_3[1] + 0x18;
  }
  else {
    iVar6 = param_3[2] - *param_3 >> 3;
    iVar10 = ((int)puVar12 - *param_3 >> 3) * -0x55555555;
    if ((uint)(iVar6 * -0x55555555) < 0x5555555) {
      uVar8 = iVar10 + 1;
      uVar13 = iVar6 * 0x55555556;
      if (uVar13 < uVar8) {
        uVar13 = uVar8;
      }
    }
    FUN_001ccdd4(auStack_58,uVar13,iVar10,param_3 + 3);
    puVar11 = local_50;
    *(undefined1 *)local_50 = 8;
    *(undefined4 *)((int)local_50 + 1) = uVar5;
    *(undefined1 *)((int)local_50 + 5) = 0;
    *(undefined2 *)((int)local_50 + 6) = 0;
    local_50[2] = 0;
    *(undefined1 *)(local_50 + 3) = 0;
    __aeabi_memcpy((undefined1 *)((int)local_50 + 0xd),&local_38,7);
    puVar11[5] = 0;
    local_34 = local_34 & 0xff000000;
    local_38 = 0;
LAB_001d5fda:
    local_50 = local_50 + 6;
    FUN_001cce32(param_3,auStack_58);
LAB_001d5fea:
    FUN_001cceae(auStack_58);
  }
switchD_001d559e_caseD_45:
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== FUN_001d64e8  @0x001d64e8  (68 bytes)
void FUN_001d64e8(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  bVar1 = *param_1;
  if ((bVar1 & 1) == 0) {
    pbVar3 = param_1 + 1;
    uVar2 = (uint)(bVar1 >> 1);
  }
  else {
    uVar2 = *(uint *)(param_1 + 4);
    pbVar3 = *(byte **)(param_1 + 8);
  }
  iVar4 = uVar2 - (uVar2 != 0);
  if (iVar4 != 0) {
    __aeabi_memmove(pbVar3,pbVar3 + (uVar2 != 0),iVar4);
    bVar1 = *param_1;
  }
  if ((bVar1 & 1) == 0) {
    *param_1 = (char)iVar4 * '\x02';
  }
  else {
    *(int *)(param_1 + 4) = iVar4;
  }
  pbVar3[iVar4] = 0;
  return;
}

// ===== FUN_001d652c  @0x001d652c  (80 bytes)
void FUN_001d652c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_001d6628(__aeabi_uldivmod,param_1);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_001d6588  @0x001d6588  (64 bytes)
void FUN_001d6588(void)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_001d7888();
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_001d65d0  @0x001d65d0  (66 bytes)
void FUN_001d65d0(void)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  FUN_001d661c();
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_001d661c  @0x001d661c  (12 bytes)
void FUN_001d661c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_001d7888(param_1,0x7fffffff,param_2,param_3);
  return;
}

// ===== FUN_001d6628  @0x001d6628  (108 bytes)
void FUN_001d6628(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [80];
  undefined1 auStack_40 [40];
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_a4 = param_3;
  __aeabi_memclr8(auStack_40,0x28);
  FUN_001d7ac0(auStack_a0,param_1);
  local_a8 = local_a4;
  iVar1 = FUN_001d66a0(0,param_2,&local_a8,auStack_90,auStack_40);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    local_a8 = local_a4;
    uVar2 = FUN_001d66a0(auStack_a0,param_2,&local_a8,auStack_90,auStack_40);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

// ===== FUN_001d66a0  @0x001d66a0  (4418 bytes)
/* WARNING: Type propagation algorithm not settling */

void FUN_001d66a0(int param_1,byte *******param_2,undefined4 *param_3,int param_4,int param_5)

{
  longlong lVar1;
  bool bVar2;
  byte *******pppppppbVar3;
  undefined4 *puVar4;
  byte *******pppppppbVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 extraout_r0;
  int *piVar8;
  uint *puVar9;
  byte *******pppppppbVar10;
  undefined1 *puVar11;
  uint *puVar12;
  byte *pbVar13;
  double *pdVar14;
  int iVar15;
  byte bVar16;
  undefined4 extraout_r1;
  byte *******pppppppbVar17;
  uint *puVar18;
  uint uVar19;
  uint extraout_r1_00;
  int extraout_r1_01;
  uint uVar20;
  uint extraout_r2;
  uint uVar21;
  uint uVar22;
  byte *pbVar23;
  int iVar24;
  int iVar25;
  uint *puVar26;
  uint *puVar27;
  uint *puVar28;
  byte *pbVar29;
  uint uVar30;
  byte *******pppppppbVar31;
  byte *pbVar32;
  uint uVar33;
  char *pcVar34;
  byte *pbVar35;
  bool bVar36;
  uint in_fpscr;
  undefined4 extraout_s0;
  undefined4 uVar37;
  undefined4 extraout_s0_00;
  double in_d0;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined4 extraout_s1_02;
  undefined4 extraout_s1_03;
  double dVar38;
  undefined4 extraout_s1_04;
  undefined4 extraout_s1_05;
  double dVar39;
  uint local_31c;
  uint local_314;
  char *local_310;
  byte *local_2c0;
  byte *******local_2b8;
  uint uStack_2b4;
  uint local_2ac;
  undefined1 auStack_2a8 [4];
  byte *******local_2a4;
  undefined4 local_2a0;
  undefined1 local_275;
  undefined1 auStack_274 [11];
  byte local_269;
  byte abStack_268 [8];
  byte local_260;
  byte abStack_25f [19];
  uint auStack_24c [66];
  uint local_144 [54];
  int local_6c;
  
  pbVar32 = (byte *)0x0;
  local_6c = __stack_chk_guard;
  bVar2 = false;
  pbVar23 = (byte *)0x0;
LAB_001d6742:
  pppppppbVar10 = param_2;
  if (-1 < (int)pbVar32) {
    if (0x7fffffff - (int)pbVar32 < (int)pbVar23) {
      puVar4 = (undefined4 *)__errno();
      in_d0 = (double)CONCAT44(extraout_s1,extraout_s0);
      pbVar32 = (byte *)0xffffffff;
      *puVar4 = 0x4b;
    }
    else {
      pbVar32 = pbVar32 + (int)pbVar23;
    }
  }
  bVar16 = *(byte *)pppppppbVar10;
  pppppppbVar5 = pppppppbVar10;
  if (bVar16 != 0) {
    while (param_2 = pppppppbVar5, bVar16 != 0) {
      if (bVar16 == 0x25) goto LAB_001d677c;
      bVar16 = *(byte *)((int)pppppppbVar5 + 1);
      pppppppbVar5 = (byte *******)((int)pppppppbVar5 + 1);
    }
    goto LAB_001d6792;
  }
  if ((param_1 == 0) && (bVar2)) {
    iVar15 = 1;
    goto LAB_001d77aa;
  }
  goto LAB_001d77d8;
LAB_001d677c:
  do {
    bVar16 = *(byte *)((int)param_2 + 1);
    bVar36 = bVar16 == 0x25;
    if (bVar36) {
      param_2 = (byte *******)((int)param_2 + 2);
      bVar16 = *(byte *)param_2;
      pppppppbVar5 = (byte *******)((int)pppppppbVar5 + 1);
    }
  } while (bVar36 && bVar16 == 0x25);
LAB_001d6792:
  pbVar23 = (byte *)((int)pppppppbVar5 - (int)pppppppbVar10);
  if (param_1 != 0) {
    uVar37 = FUN_001d7ae6(param_1,pppppppbVar10,pbVar23);
    in_d0 = (double)CONCAT44(extraout_s1_00,uVar37);
  }
  if (pbVar23 != (byte *)0x0) goto LAB_001d6742;
  pppppppbVar5 = (byte *******)((int)param_2 + 1);
  uVar20 = (uint)*(byte *)pppppppbVar5;
  uVar33 = uVar20 - 0x30;
  if (uVar33 < 10) {
    bVar36 = *(byte *)((int)param_2 + 2) != 0x24;
    if (bVar36) {
      uVar33 = 0xffffffff;
    }
    else {
      pppppppbVar5 = (byte *******)((int)param_2 + 3);
    }
    uVar20 = (uint)*(byte *)pppppppbVar5;
    if (!bVar36) {
      bVar2 = true;
    }
  }
  else {
    uVar33 = 0xffffffff;
  }
  uVar30 = 0;
  while ((uVar20 - 0x20 < 0x20 && ((1 << (uVar20 - 0x20 & 0xff) & 0x12889U) != 0))) {
    uVar21 = uVar20 - 0x20;
    pppppppbVar5 = (byte *******)((int)pppppppbVar5 + 1);
    uVar20 = (uint)*(byte *)pppppppbVar5;
    uVar30 = uVar30 | 1 << (uVar21 & 0xff);
  }
  if (uVar20 == 0x2a) {
    pppppppbVar31 = (byte *******)((int)pppppppbVar5 + 1);
    bVar16 = *(byte *)pppppppbVar31;
    if ((bVar16 - 0x30 < 10) && (*(byte *)((int)pppppppbVar5 + 2) == 0x24)) {
      pppppppbVar31 = (byte *******)((int)pppppppbVar5 + 3);
      *(undefined4 *)(param_5 + (bVar16 - 0x30) * 4) = 10;
      bVar2 = true;
      pbVar35 = *(byte **)(param_4 + (uint)*(byte *)((int)pppppppbVar5 + 1) * 8 + -0x180);
    }
    else {
      if (bVar2) goto LAB_001d77d8;
      if (param_1 == 0) {
        pbVar35 = (byte *)0x0;
        bVar2 = false;
        goto LAB_001d68c6;
      }
      puVar4 = (undefined4 *)*param_3;
      *param_3 = puVar4 + 1;
      pbVar35 = (byte *)*puVar4;
      bVar2 = false;
    }
    if ((byte *)0x7fffffff < pbVar35) {
      pbVar35 = (byte *)-(int)pbVar35;
      uVar30 = uVar30 | 0x2000;
    }
  }
  else {
    uVar20 = uVar20 - 0x30;
    pbVar35 = (byte *)0x0;
    pppppppbVar31 = pppppppbVar5;
    if (uVar20 < 10) {
      do {
        pppppppbVar31 = (byte *******)((int)pppppppbVar31 + 1);
        pbVar35 = (byte *)(uVar20 + (int)pbVar35 * 10);
        uVar20 = *(byte *)pppppppbVar31 - 0x30;
      } while (uVar20 < 10);
      if ((int)pbVar35 < 0) goto LAB_001d77d8;
    }
  }
LAB_001d68c6:
  if (*(byte *)pppppppbVar31 == 0x2e) {
    uVar20 = (uint)*(byte *)((int)pppppppbVar31 + 1);
    if (uVar20 == 0x2a) {
      param_2 = (byte *******)((int)pppppppbVar31 + 2);
      if ((*(byte *)param_2 - 0x30 < 10) && (*(byte *)((int)pppppppbVar31 + 3) == 0x24)) {
        *(undefined4 *)(param_5 + (*(byte *)param_2 - 0x30) * 4) = 10;
        param_2 = pppppppbVar31 + 1;
        local_2c0 = *(byte **)(param_4 + (uint)*(byte *)((int)pppppppbVar31 + 2) * 8 + -0x180);
      }
      else {
        if (bVar2) goto LAB_001d77d8;
        if (param_1 == 0) {
          local_2c0 = (byte *)0x0;
        }
        else {
          puVar4 = (undefined4 *)*param_3;
          *param_3 = puVar4 + 1;
          local_2c0 = (byte *)*puVar4;
        }
      }
    }
    else {
      uVar20 = uVar20 - 0x30;
      if (uVar20 < 10) {
        local_2c0 = (byte *)0x0;
        pppppppbVar5 = (byte *******)((int)pppppppbVar31 + 2);
        do {
          param_2 = pppppppbVar5;
          local_2c0 = (byte *)(uVar20 + (int)local_2c0 * 10);
          uVar20 = *(byte *)param_2 - 0x30;
          pppppppbVar5 = (byte *******)((int)param_2 + 1);
        } while (uVar20 < 10);
      }
      else {
        local_2c0 = (byte *)0x0;
        param_2 = (byte *******)((int)pppppppbVar31 + 1);
      }
    }
  }
  else {
    local_2c0 = (byte *)0xffffffff;
    param_2 = pppppppbVar31;
  }
  uVar20 = 0;
  do {
    pppppppbVar5 = param_2;
    uVar21 = uVar20;
    if (0x39 < *(byte *)pppppppbVar5 - 0x41) goto LAB_001d77d8;
    param_2 = (byte *******)((int)pppppppbVar5 + 1);
    uVar20 = (uint)(byte)(&UNK_00261678)[(*(byte *)pppppppbVar5 - 0x41) + uVar21 * 0x3a];
  } while (uVar20 - 1 < 8);
  if (uVar20 == 0) goto LAB_001d77d8;
  if (uVar20 == 0x13) {
    if (-1 < (int)uVar33) goto LAB_001d77d8;
LAB_001d69ba:
    pbVar23 = (byte *)0x0;
    if (param_1 == 0) goto LAB_001d6742;
  }
  else {
    if (-1 < (int)uVar33) {
      *(uint *)(param_5 + uVar33 * 4) = uVar20;
      local_2b8 = *(byte ********)(param_4 + uVar33 * 8);
      uStack_2b4 = *(uint *)(param_4 + uVar33 * 8 + 4);
      goto LAB_001d69ba;
    }
    if (param_1 == 0) goto LAB_001d77d8;
    uVar37 = FUN_001d792c(&local_2b8,uVar20,param_3);
    in_d0 = (double)CONCAT44(extraout_s1_01,uVar37);
  }
  uVar33 = (uint)*(byte *)pppppppbVar5;
  uVar20 = uVar30 & 0xfffeffff;
  pbVar23 = (byte *)0x0;
  local_31c = uVar33;
  if ((uVar33 & 0xf) == 3) {
    local_31c = uVar33 & 0xdf;
  }
  if (uVar21 == 0) {
    local_31c = uVar33;
  }
  if ((uVar30 & 0x2000) != 0) {
    uVar30 = uVar20;
  }
  pcVar34 = "-+   0X0x";
  pppppppbVar5 = (byte *******)auStack_274;
  if (local_31c < 0x53) {
    if ((local_31c - 0x45 < 3) || (local_31c == 0x41)) goto LAB_001d6ba4;
    if (local_31c != 0x43) goto switchD_001d6a24_default;
    local_2a4 = local_2b8;
    local_2a0 = 0;
    local_2b8 = (byte *******)&local_2a4;
    local_2c0 = (byte *)0xffffffff;
LAB_001d6d0c:
    pppppppbVar10 = local_2b8;
    pbVar23 = (byte *)0x0;
    uVar33 = 0;
    pppppppbVar5 = local_2b8;
    do {
      if (((*pppppppbVar5 == (byte ******)0x0) ||
          (uVar33 = FUN_001d7ab4(auStack_2a8), (int)uVar33 < 0)) ||
         ((uint)((int)local_2c0 - (int)pbVar23) < uVar33)) break;
      pbVar23 = pbVar23 + uVar33;
      pppppppbVar5 = pppppppbVar5 + 1;
    } while (pbVar23 < local_2c0);
    if ((int)uVar33 < 0) goto LAB_001d77d8;
    FUN_001d7a28(param_1,0x20,pbVar35,pbVar23,uVar30);
    if (pbVar23 == (byte *)0x0) {
      pbVar23 = (byte *)0x0;
    }
    else {
      pbVar6 = (byte *)0x0;
      do {
        if (*pppppppbVar10 == (byte ******)0x0) break;
        iVar15 = FUN_001d7ab4(auStack_2a8);
        pbVar6 = pbVar6 + iVar15;
        if ((int)pbVar23 < (int)pbVar6) break;
        FUN_001d7ae6(param_1,auStack_2a8);
        pppppppbVar10 = pppppppbVar10 + 1;
      } while (pbVar6 < pbVar23);
    }
LAB_001d76cc:
    uVar37 = FUN_001d7a28(param_1,0x20,pbVar35,pbVar23,uVar30 ^ 0x2000);
    in_d0 = (double)CONCAT44(extraout_s1_05,uVar37);
    if ((int)pbVar23 < (int)pbVar35) {
      pbVar23 = pbVar35;
    }
    goto LAB_001d6742;
  }
  pppppppbVar31 = local_2b8;
  uVar33 = uStack_2b4;
  switch(local_31c) {
  case 0x53:
    if (local_2c0 == (byte *)0x0) {
      pbVar23 = (byte *)0x0;
      FUN_001d7a28(param_1,0x20,pbVar35,0,uVar30);
      goto LAB_001d76cc;
    }
    goto LAB_001d6d0c;
  case 0x54:
    break;
  case 0x55:
    break;
  case 0x56:
    break;
  case 0x57:
    break;
  case 0x58:
    goto LAB_001d6dba;
  case 0x59:
    break;
  case 0x5a:
    break;
  case 0x5b:
    break;
  case 0x5c:
    break;
  case 0x5d:
    break;
  case 0x5e:
    break;
  case 0x5f:
    break;
  case 0x60:
    break;
  case 0x61:
    goto LAB_001d6ba4;
  case 0x62:
    break;
  case 99:
    local_275 = local_2b8._0_1_;
    local_2c0 = (byte *)0x1;
    pppppppbVar10 = (byte *******)&local_275;
    uVar30 = uVar20;
  default:
switchD_001d6a24_default:
    pbVar23 = (byte *)0x0;
    pcVar34 = "-+   0X0x";
    break;
  case 100:
    goto LAB_001d6b56;
  case 0x65:
    goto LAB_001d6ba4;
  case 0x66:
    goto LAB_001d6ba4;
  case 0x67:
LAB_001d6ba4:
    dVar39 = (double)CONCAT44(uStack_2b4,local_2b8);
    local_2ac = 0;
    iVar15 = __signbit(in_d0);
    if (iVar15 == 0) {
      if ((uVar30 & 0x800) == 0) {
        local_314 = uVar30 & 1;
        local_310 = " 0X-0x+0x 0x";
        if (local_314 == 0) {
          local_310 = "0X+0X 0X-0x+0x 0x";
        }
      }
      else {
        local_310 = "+0X 0X-0x+0x 0x";
        local_314 = 1;
      }
    }
    else {
      dVar39 = -dVar39;
      local_314 = 1;
      local_310 = "-0X+0X 0X-0x+0x 0x";
    }
    iVar15 = __isfinite(SUB84(dVar39,0),(int)((ulonglong)dVar39 >> 0x20));
    if (iVar15 == 0) {
      in_fpscr = in_fpscr & 0xfffffff;
      if (NAN(dVar39)) {
        local_314 = 0;
      }
      pbVar23 = (byte *)(local_314 + 3);
      FUN_001d7a28(param_1,0x20,pbVar35,pbVar23,uVar20);
      FUN_001d7ae6(param_1,local_310,local_314);
      bVar36 = (local_31c & 0x20) != 0;
      in_fpscr = in_fpscr & 0xfffffff;
      pbVar6 = &UNK_0022256d;
      if (bVar36) {
        pbVar6 = &DAT_00222569;
      }
      pbVar7 = &UNK_00222565;
      if (bVar36) {
        pbVar7 = &UNK_00222561;
      }
      iVar15 = 3;
      if (NAN(dVar39)) {
        pbVar7 = pbVar6;
      }
    }
    else {
      frexp((double)CONCAT44(extraout_s1_03,extraout_s0_00),SUB84(dVar39,0));
      dVar39 = (double)CONCAT44(extraout_r1,extraout_r0) + (double)CONCAT44(extraout_r1,extraout_r0)
      ;
      uVar33 = in_fpscr & 0xfffffff;
      in_fpscr = uVar33 | (uint)(dVar39 == 0.0) << 0x1e;
      if ((byte)(in_fpscr >> 0x1e) == 0) {
        local_2ac = local_2ac - 1;
      }
      uVar20 = local_2ac;
      uVar21 = local_31c | 0x20;
      if (uVar21 == 0x61) {
        if ((local_31c & 0x20) != 0) {
          local_310 = local_310 + 9;
        }
        if ((local_2c0 < (byte *)0xc) && (local_2c0 != (byte *)0xc)) {
          dVar38 = 8.0;
          pbVar23 = local_2c0 + -0xc;
          do {
            dVar38 = dVar38 * 16.0;
            pbVar23 = pbVar23 + 1;
          } while (pbVar23 != (byte *)0x0);
          if (*local_310 == '-') {
            dVar39 = -(dVar38 + (-dVar39 - dVar38));
          }
          else {
            dVar39 = (dVar39 + dVar38) - dVar38;
          }
        }
        uVar33 = local_2ac;
        if ((int)local_2ac < 0) {
          uVar33 = -local_2ac;
        }
        pbVar7 = (byte *)FUN_001d79d8(uVar33,(int)uVar33 >> 0x1f,abStack_268);
        if (pbVar7 == abStack_268) {
          local_269 = 0x30;
          pbVar7 = &local_269;
        }
        pbVar7[-1] = (char)((uVar20 >> 0x1f) << 1) + 0x2b;
        pbVar7 = pbVar7 + -2;
        *pbVar7 = (char)local_31c + 0xf;
        pbVar23 = abStack_268;
        do {
          lVar1 = (longlong)dVar39;
          dVar38 = (double)VectorSignedToFloat((int)lVar1,(byte)(in_fpscr >> 0x16) & 3);
          dVar39 = (dVar39 - dVar38) * 16.0;
          pbVar6 = pbVar23 + 1;
          *pbVar23 = (&DAT_00261848)[(int)lVar1] | (byte)(local_31c & 0x20);
          if (((int)pbVar6 - (int)abStack_268 == 1) &&
             ((((uVar30 & 8) != 0 || (0 < (int)local_2c0)) ||
              (in_fpscr = in_fpscr & 0xfffffff | (uint)(dVar39 == 0.0) << 0x1e,
              (byte)(in_fpscr >> 0x1e) == 0)))) {
            pbVar6 = pbVar23 + 2;
            pbVar23[1] = 0x2e;
          }
          in_fpscr = in_fpscr & 0xfffffff | (uint)(dVar39 == 0.0) << 0x1e;
          pbVar23 = pbVar6;
        } while ((byte)(in_fpscr >> 0x1e) == 0);
        pbVar29 = pbVar6 + (int)(abStack_268 + (-(int)pbVar7 - (int)abStack_268));
        if ((int)(pbVar6 + (-2 - (int)abStack_268)) < (int)local_2c0) {
          pbVar29 = abStack_268 + 2 + (int)local_2c0 + -(int)pbVar7;
        }
        if (local_2c0 == (byte *)0x0) {
          pbVar29 = pbVar6 + (int)(abStack_268 + (-(int)pbVar7 - (int)abStack_268));
        }
        pbVar23 = pbVar29 + (local_314 | 2);
        FUN_001d7a28(param_1,0x20,pbVar35,pbVar23,uVar30);
        FUN_001d7ae6(param_1,local_310,local_314 | 2);
        FUN_001d7a28(param_1,0x30,pbVar35,pbVar23,uVar30 ^ 0x10000);
        iVar25 = (int)pbVar6 - (int)abStack_268;
        FUN_001d7ae6(param_1,abStack_268,iVar25);
        iVar15 = (int)abStack_268 - (int)pbVar7;
        FUN_001d7a28(param_1,0x30,(int)pbVar29 - (iVar15 + iVar25),0,0);
      }
      else {
        in_fpscr = uVar33 | (uint)(dVar39 == 0.0) << 0x1e;
        if ((int)local_2c0 < 0) {
          local_2c0 = (byte *)0x6;
        }
        if ((byte)(in_fpscr >> 0x1e) == 0) {
          dVar39 = dVar39 * 268435456.0;
          local_2ac = local_2ac - 0x1c;
        }
        puVar9 = auStack_24c;
        puVar18 = puVar9;
        if (-1 < (int)local_2ac) {
          puVar9 = local_144;
          puVar18 = puVar9;
        }
        do {
          uVar33 = (uint)(0.0 < dVar39) * (int)(longlong)dVar39;
          dVar38 = (double)VectorUnsignedToFloat(uVar33,(byte)(in_fpscr >> 0x16) & 3);
          dVar39 = (dVar39 - dVar38) * 1000000000.0;
          puVar12 = puVar9 + 1;
          *puVar9 = uVar33;
          in_fpscr = in_fpscr & 0xfffffff | (uint)(dVar39 == 0.0) << 0x1e;
          puVar9 = puVar12;
          puVar26 = puVar18;
        } while ((byte)(in_fpscr >> 0x1e) == 0);
        while (0 < (int)local_2ac) {
          puVar9 = puVar12 + -1;
          uVar33 = local_2ac;
          if (0x1d < (int)local_2ac) {
            uVar33 = 0x1d;
          }
          if (puVar9 < puVar26) {
            if (puVar12[-1] != 0) {
              puVar9 = puVar12;
            }
            if (puVar26 < puVar12) {
              puVar12 = puVar9;
            }
          }
          else {
            uVar20 = 0;
            puVar27 = puVar9;
            do {
              uVar19 = *puVar27;
              uVar22 = uVar19 >> (0x20 - uVar33 & 0xff);
              if (-1 < (int)(uVar33 - 0x20)) {
                uVar22 = uVar19 << (uVar33 - 0x20 & 0xff);
              }
              uVar19 = uVar19 << (uVar33 & 0xff);
              uVar20 = __aeabi_uldivmod(uVar20 + uVar19,uVar22 + CARRY4(uVar20,uVar19),1000000000,0)
              ;
              puVar28 = puVar27 + -1;
              *puVar27 = extraout_r2;
              puVar27 = puVar28;
            } while (puVar26 <= puVar28);
            if (puVar12[-1] != 0) {
              puVar9 = puVar12;
            }
            if (puVar26 < puVar12) {
              puVar12 = puVar9;
            }
            if (uVar20 != 0) {
              puVar26 = puVar26 + -1;
              *puVar26 = uVar20;
            }
          }
          local_2ac = local_2ac - uVar33;
        }
        if (0x7fffffff < local_2ac) {
          do {
            uVar33 = -local_2ac;
            if (local_2ac != 0xfffffff7 && 8 < (int)uVar33) {
              uVar33 = 9;
            }
            if (puVar26 < puVar12) {
              puVar9 = puVar26;
              uVar20 = 0;
              do {
                uVar19 = (1000000000U >> (uVar33 & 0xff)) * (*puVar9 & (1 << (uVar33 & 0xff)) - 1U);
                puVar27 = puVar9 + 1;
                *puVar9 = (*puVar9 >> (uVar33 & 0xff)) + uVar20;
                puVar9 = puVar27;
                uVar20 = uVar19;
              } while (puVar27 < puVar12);
              if (*puVar26 == 0) {
                puVar26 = puVar26 + 1;
              }
              if (uVar19 != 0) {
                *puVar12 = uVar19;
                puVar12 = puVar12 + 1;
              }
            }
            else if (*puVar26 == 0) {
              puVar26 = puVar26 + 1;
            }
            local_2ac = local_2ac + uVar33;
            puVar9 = puVar26;
            if (uVar21 == 0x66) {
              puVar9 = puVar18;
            }
            if ((int)local_2c0 / 9 + 2 < (int)puVar12 - (int)puVar9 >> 2) {
              puVar12 = puVar9 + (int)local_2c0 / 9 + 2;
            }
          } while ((int)local_2ac < 0);
        }
        if (puVar26 < puVar12) {
          uVar33 = ((int)puVar18 - (int)puVar26 >> 2) * 9;
          if (9 < *puVar26) {
            iVar15 = 10;
            do {
              uVar33 = uVar33 + 1;
              uVar20 = iVar15 * 10;
              iVar15 = iVar15 * 10;
            } while (uVar20 <= *puVar26);
          }
        }
        else {
          uVar33 = 0;
        }
        pbVar23 = local_2c0;
        if (uVar21 != 0x66) {
          pbVar23 = local_2c0 + -uVar33;
        }
        pbVar6 = pbVar23;
        if (uVar21 == 0x67) {
          pbVar6 = pbVar23 + -1;
        }
        if (local_2c0 == (byte *)0x0) {
          pbVar6 = pbVar23;
        }
        if ((int)pbVar6 < ((int)puVar12 - (int)puVar18 >> 2) * 9 + -9) {
          iVar15 = (int)(pbVar6 + 0x2400) / 9;
          puVar9 = puVar18 + iVar15 + -0x3ff;
          iVar25 = (int)(pbVar6 + 0x2400) % 9;
          if (iVar25 + 1 < 9) {
            iVar25 = 8 - iVar25;
            iVar24 = 10;
            do {
              iVar25 = iVar25 + -1;
              iVar24 = iVar24 * 10;
            } while (iVar25 != 0);
          }
          else {
            iVar24 = 10;
          }
          uVar20 = *puVar9;
          __aeabi_uidivmod(uVar20,iVar24);
          if (puVar18 + iVar15 + -0x3fe != puVar12 || extraout_r1_00 != 0) {
            uVar19 = __aeabi_uidiv(uVar20,iVar24);
            pdVar14 = (double *)&DAT_001d7808;
            if ((uVar19 & 1) == 0) {
              pdVar14 = (double *)&DAT_001d7810;
            }
            dVar39 = 0.5;
            if ((uint)(iVar24 / 2) <= extraout_r1_00) {
              dVar38 = 1.5;
              if (extraout_r1_00 == iVar24 / 2) {
                dVar38 = 1.0;
              }
              dVar39 = 1.5;
              if (puVar18 + iVar15 + -0x3fe == puVar12) {
                dVar39 = dVar38;
              }
            }
            dVar38 = *pdVar14;
            if ((local_314 != 0) && (*local_310 == '-')) {
              dVar39 = -dVar39;
              dVar38 = -dVar38;
            }
            *puVar9 = uVar20 - extraout_r1_00;
            in_fpscr = in_fpscr & 0xfffffff | (uint)(dVar38 + dVar39 == dVar38) << 0x1e;
            if ((byte)(in_fpscr >> 0x1e) == 0) {
              uVar33 = (uVar20 - extraout_r1_00) + iVar24;
              *puVar9 = uVar33;
              if (999999999 < uVar33) {
                puVar27 = puVar18 + iVar15 + -0x400;
                do {
                  puVar9 = puVar27;
                  puVar9[1] = 0;
                  uVar33 = *puVar9;
                  *puVar9 = uVar33 + 1;
                  puVar27 = puVar9 + -1;
                } while (999999999 < uVar33 + 1);
              }
              if (puVar9 < puVar26) {
                puVar26 = puVar9;
              }
              uVar33 = ((int)puVar18 - (int)puVar26 >> 2) * 9;
              if (9 < *puVar26) {
                iVar15 = 10;
                do {
                  uVar33 = uVar33 + 1;
                  uVar20 = iVar15 * 10;
                  iVar15 = iVar15 * 10;
                } while (uVar20 <= *puVar26);
              }
            }
          }
          puVar27 = puVar12;
          if (puVar9 + 1 < puVar12) {
            puVar27 = puVar9 + 1;
          }
          do {
            puVar12 = puVar27;
            if (puVar12 <= puVar26) break;
            puVar27 = puVar12 + -1;
          } while (puVar12[-1] == 0);
        }
        if (uVar21 == 0x67) {
          if (local_2c0 == (byte *)0x0) {
            local_2c0 = (byte *)0x1;
          }
          if (((int)uVar33 < (int)local_2c0) && (-5 < (int)uVar33)) {
            pbVar23 = local_2c0 + (-1 - uVar33);
            local_31c = local_31c - 1;
          }
          else {
            pbVar23 = local_2c0 + -1;
            local_31c = local_31c - 2;
          }
          uVar20 = uVar30 & 8;
          local_2c0 = pbVar23;
          if (uVar20 == 0) {
            if ((puVar26 < puVar12) && (uVar20 = puVar12[-1], uVar20 != 0)) {
              if (uVar20 % 10 == 0) {
                iVar25 = 10;
                iVar15 = 0;
                do {
                  iVar25 = iVar25 * 10;
                  __aeabi_uidivmod(uVar20,iVar25);
                  iVar15 = iVar15 + 1;
                } while (extraout_r1_01 == 0);
              }
              else {
                iVar15 = 0;
              }
            }
            else {
              iVar15 = 9;
            }
            iVar25 = ((int)puVar12 - (int)puVar18 >> 2) * 9 + -9;
            uVar20 = 0;
            if ((local_31c | 0x20) != 0x66) {
              iVar25 = iVar25 + uVar33;
            }
            local_2c0 = (byte *)(iVar25 - iVar15);
            if ((int)local_2c0 < 0) {
              local_2c0 = (byte *)0x0;
            }
            if ((int)pbVar23 < (int)local_2c0) {
              local_2c0 = pbVar23;
            }
          }
        }
        else {
          uVar20 = uVar30 & 8;
        }
        if ((local_31c | 0x20) == 0x66) {
          pbVar7 = (byte *)0x0;
          if ((int)uVar33 < 1) {
            uVar33 = 0;
          }
        }
        else {
          uVar21 = uVar33;
          if ((int)uVar33 < 0) {
            uVar21 = -uVar33;
          }
          puVar11 = (undefined1 *)FUN_001d79d8(uVar21,(int)uVar21 >> 0x1f,abStack_268);
          while ((int)abStack_268 - (int)puVar11 < 2) {
            puVar11 = puVar11 + -1;
            *puVar11 = 0x30;
          }
          puVar11[-1] = (char)((uVar33 >> 0x1f) << 1) + '+';
          pbVar7 = puVar11 + -2;
          *pbVar7 = (byte)local_31c;
          uVar33 = (int)abStack_268 - (int)pbVar7;
        }
        pbVar23 = local_2c0 + uVar33 + (local_2c0 != (byte *)0x0 || uVar20 != 0) + local_314 + 1;
        FUN_001d7a28(param_1,0x20,pbVar35,pbVar23,uVar30);
        FUN_001d7ae6(param_1,local_310,local_314);
        FUN_001d7a28(param_1,0x30,pbVar35,pbVar23,uVar30 ^ 0x10000);
        if ((local_31c | 0x20) == 0x66) {
          puVar9 = puVar26;
          if (puVar18 < puVar26) {
            puVar26 = puVar18;
            puVar9 = puVar18;
          }
          do {
            pbVar6 = (byte *)FUN_001d79d8(*puVar26,0,abStack_25f);
            if (puVar26 == puVar9) {
              if (pbVar6 == abStack_25f) {
                local_260 = 0x30;
                pbVar6 = &local_260;
              }
            }
            else if (abStack_268 < pbVar6) {
              __aeabi_memset8(abStack_268,(int)pbVar6 - (int)abStack_268,0x30);
              do {
                pbVar6 = pbVar6 + -1;
              } while (abStack_268 < pbVar6);
            }
            FUN_001d7ae6(param_1,pbVar6,(int)abStack_25f - (int)pbVar6);
            puVar26 = puVar26 + 1;
          } while (puVar26 <= puVar18);
          if (local_2c0 != (byte *)0x0 || uVar20 != 0) {
            FUN_001d7ae6(param_1,&DAT_0021f777,1);
          }
          if (0 < (int)local_2c0) {
            for (; puVar26 < puVar12; puVar26 = puVar26 + 1) {
              pbVar6 = (byte *)FUN_001d79d8(*puVar26,0,abStack_25f);
              if (abStack_268 < pbVar6) {
                __aeabi_memset8(abStack_268,(int)pbVar6 - (int)abStack_268,0x30);
                do {
                  pbVar6 = pbVar6 + -1;
                } while (abStack_268 < pbVar6);
              }
              pbVar7 = local_2c0;
              if (9 < (int)local_2c0) {
                pbVar7 = (byte *)0x9;
              }
              FUN_001d7ae6(param_1,pbVar6,pbVar7);
              pbVar6 = local_2c0 + -9;
              bVar36 = (int)local_2c0 < 10;
              local_2c0 = pbVar6;
              if (bVar36) break;
            }
          }
          FUN_001d7a28(param_1,0x30,local_2c0 + 9,9,0);
          goto LAB_001d756a;
        }
        if (puVar12 <= puVar26) {
          puVar12 = puVar26 + 1;
        }
        puVar9 = puVar26;
        if (-1 < (int)local_2c0) {
          do {
            pbVar6 = (byte *)FUN_001d79d8(*puVar9,0,abStack_25f);
            if (pbVar6 == abStack_25f) {
              local_260 = 0x30;
              pbVar6 = &local_260;
            }
            if (puVar9 == puVar26) {
              FUN_001d7ae6(param_1,pbVar6,1);
              pbVar6 = pbVar6 + 1;
              if ((uVar20 != 0) || (0 < (int)local_2c0)) {
                FUN_001d7ae6(param_1,&DAT_0021f777,1);
              }
            }
            else if (abStack_268 < pbVar6) {
              __aeabi_memset8(abStack_268,(int)pbVar6 - (int)abStack_268,0x30);
              do {
                pbVar6 = pbVar6 + -1;
              } while (abStack_268 < pbVar6);
            }
            pbVar13 = abStack_25f + -(int)pbVar6;
            pbVar29 = local_2c0;
            if ((int)pbVar13 < (int)local_2c0) {
              pbVar29 = pbVar13;
            }
            FUN_001d7ae6(param_1,pbVar6,pbVar29);
            local_2c0 = local_2c0 + -(int)pbVar13;
          } while ((puVar9 + 1 < puVar12) && (puVar9 = puVar9 + 1, local_2c0 < (byte *)0x80000000));
        }
        FUN_001d7a28(param_1,0x30,local_2c0 + 0x12,0x12,0);
        iVar15 = (int)abStack_268 - (int)pbVar7;
      }
    }
    FUN_001d7ae6(param_1,pbVar7,iVar15);
LAB_001d756a:
    uVar37 = FUN_001d7a28(param_1,0x20,pbVar35,pbVar23,uVar30 ^ 0x2000);
    in_d0 = (double)CONCAT44(extraout_s1_04,uVar37);
    if ((int)pbVar23 < (int)pbVar35) {
      pbVar23 = pbVar35;
    }
    goto LAB_001d6742;
  case 0x68:
    break;
  case 0x69:
LAB_001d6b56:
    if ((int)uStack_2b4 < 0) {
      bVar36 = local_2b8 != (byte *******)0x0;
      local_2b8 = (byte *******)-(int)local_2b8;
      uStack_2b4 = -(uint)bVar36 - uStack_2b4;
      pbVar23 = (byte *)0x1;
      pcVar34 = "-+   0X0x";
    }
    else if ((uVar30 & 0x800) == 0) {
      pbVar23 = (byte *)(uVar30 & 1);
      pcVar34 = "-+   0X0x";
      if (pbVar23 != (byte *)0x0) {
        pcVar34 = "   0X0x";
      }
    }
    else {
      pbVar23 = (byte *)0x1;
      pcVar34 = "+   0X0x";
    }
LAB_001d70da:
    uVar33 = uStack_2b4;
    pppppppbVar31 = local_2b8;
    pppppppbVar10 = (byte *******)FUN_001d79d8(local_2b8,uStack_2b4,auStack_274);
    goto LAB_001d765a;
  case 0x6a:
    break;
  case 0x6b:
    break;
  case 0x6c:
    break;
  case 0x6d:
    piVar8 = (int *)__errno();
    pppppppbVar10 = (byte *******)strerror(*piVar8);
    goto LAB_001d6e42;
  case 0x6e:
    goto LAB_001d6742;
  case 0x6f:
    pppppppbVar17 = local_2b8;
    uVar20 = uStack_2b4;
    pppppppbVar3 = (byte *******)&local_275;
    if (local_2b8 == (byte *******)0x0 && uStack_2b4 == 0) {
      uVar33 = 0;
      pppppppbVar31 = (byte *******)0x0;
      pppppppbVar10 = (byte *******)auStack_274;
    }
    else {
      do {
        pppppppbVar10 = pppppppbVar3;
        *(byte *)pppppppbVar10 = (byte)pppppppbVar17 & 7 | 0x30;
        pppppppbVar17 = (byte *******)((uint)pppppppbVar17 >> 3 | uVar20 << 0x1d);
        uVar21 = uVar20 >> 3;
        uVar20 = uVar20 >> 3;
        pppppppbVar3 = (byte *******)((int)pppppppbVar10 + -1);
      } while (pppppppbVar17 != (byte *******)0x0 || uVar21 != 0);
    }
    uVar20 = (uVar30 & 8) >> 3 ^ 1;
    if (pppppppbVar31 == (byte *******)0x0 && uVar33 == 0) {
      uVar20 = 1;
    }
    pbVar23 = (byte *)(uVar20 ^ 1);
    pcVar34 = "-+   0X0x";
    if (pppppppbVar31 != (byte *******)0x0 || uVar33 != 0) {
      pcVar34 = "0X0x";
    }
    if ((uVar30 & 8) == 0) {
      pcVar34 = "-+   0X0x";
    }
    goto LAB_001d765a;
  case 0x70:
    uVar30 = uVar30 | 8;
    local_31c = 0x78;
    if (local_2c0 < (byte *)0x9) {
      local_2c0 = (byte *)0x8;
    }
    goto LAB_001d6dba;
  case 0x71:
    break;
  case 0x72:
    break;
  case 0x73:
    pppppppbVar10 = local_2b8;
    if (local_2b8 == (byte *******)0x0) {
      pppppppbVar10 = (byte *******)"(null)";
    }
LAB_001d6e42:
    if ((int)local_2c0 < 0) {
      local_2c0 = (byte *)strlen((char *)pppppppbVar10);
      pppppppbVar5 = (byte *******)(local_2c0 + (int)pppppppbVar10);
    }
    else {
      pppppppbVar5 = memchr(pppppppbVar10,0,(size_t)local_2c0);
      if (pppppppbVar5 == (byte *******)0x0) {
        pppppppbVar5 = (byte *******)((int)pppppppbVar10 + (int)local_2c0);
      }
      else {
        local_2c0 = (byte *)((int)pppppppbVar5 - (int)pppppppbVar10);
      }
    }
    pcVar34 = "-+   0X0x";
    pbVar23 = (byte *)0x0;
    uVar30 = uVar20;
    break;
  case 0x74:
    break;
  case 0x75:
    pbVar23 = (byte *)0x0;
    pcVar34 = "-+   0X0x";
    goto LAB_001d70da;
  case 0x76:
    pcVar34 = "-+   0X0x";
    break;
  case 0x77:
    pcVar34 = "-+   0X0x";
    break;
  case 0x78:
LAB_001d6dba:
    if (local_2b8 == (byte *******)0x0 && uStack_2b4 == 0) {
      pppppppbVar31 = (byte *******)0x0;
      uVar33 = 0;
      pbVar23 = (byte *)0x0;
      pppppppbVar10 = (byte *******)auStack_274;
      pcVar34 = "-+   0X0x";
    }
    else {
      uVar20 = uStack_2b4;
      pppppppbVar17 = local_2b8;
      pppppppbVar3 = (byte *******)&local_275;
      do {
        pppppppbVar10 = pppppppbVar3;
        uVar19 = (uint)pppppppbVar17 & 0xf;
        pppppppbVar17 = (byte *******)((uint)pppppppbVar17 >> 4 | uVar20 << 0x1c);
        uVar21 = uVar20 >> 4;
        uVar20 = uVar20 >> 4;
        *(byte *)pppppppbVar10 = (&DAT_00261848)[uVar19] | (byte)local_31c & 0x20;
        pppppppbVar3 = (byte *******)((int)pppppppbVar10 + -1);
      } while (pppppppbVar17 != (byte *******)0x0 || uVar21 != 0);
      pbVar23 = (byte *)0x0;
      if ((uVar30 & 8) == 0) {
        pcVar34 = "-+   0X0x";
      }
      else if (local_2b8 == (byte *******)0x0 && uStack_2b4 == 0) {
        pcVar34 = "-+   0X0x";
      }
      else {
        pbVar23 = (byte *)0x2;
        pcVar34 = &DAT_0022253d + (local_31c >> 4);
      }
    }
LAB_001d765a:
    if (-1 < (int)local_2c0) {
      uVar30 = uVar30 & 0xfffeffff;
    }
    if ((local_2c0 == (byte *)0x0) && (pppppppbVar31 == (byte *******)0x0 && uVar33 == 0)) {
      local_2c0 = (byte *)0x0;
      pppppppbVar10 = (byte *******)auStack_274;
    }
    else {
      pppppppbVar17 = (byte *******)auStack_274;
      if (pppppppbVar31 == (byte *******)0x0 && uVar33 == 0) {
        pppppppbVar17 = (byte *******)(auStack_274 + 1);
      }
      if ((int)local_2c0 <= (int)pppppppbVar17 - (int)pppppppbVar10) {
        local_2c0 = (byte *)((int)pppppppbVar17 - (int)pppppppbVar10);
      }
    }
  }
  pbVar6 = (byte *)((int)pppppppbVar5 - (int)pppppppbVar10);
  if ((int)local_2c0 < (int)pbVar6) {
    local_2c0 = pbVar6;
  }
  pbVar7 = pbVar23 + (int)local_2c0;
  if ((int)pbVar35 < (int)pbVar7) {
    pbVar35 = pbVar7;
  }
  FUN_001d7a28(param_1,0x20,pbVar35,pbVar7,uVar30);
  FUN_001d7ae6(param_1,pcVar34,pbVar23);
  FUN_001d7a28(param_1,0x30,pbVar35,pbVar7,uVar30 ^ 0x10000);
  FUN_001d7a28(param_1,0x30,local_2c0,pbVar6,0);
  FUN_001d7ae6(param_1,pppppppbVar10,pbVar6);
  uVar37 = FUN_001d7a28(param_1,0x20,pbVar35,pbVar7,uVar30 ^ 0x2000);
  in_d0 = (double)CONCAT44(extraout_s1_02,uVar37);
  pbVar23 = pbVar35;
  goto LAB_001d6742;
  while( true ) {
    FUN_001d792c(param_4,iVar25,param_3);
    iVar15 = iVar15 + 1;
    if (9 < iVar15) break;
LAB_001d77aa:
    param_4 = param_4 + 8;
    iVar25 = *(int *)(param_5 + iVar15 * 4);
    if (iVar25 == 0) goto LAB_001d77c2;
  }
  goto LAB_001d77d8;
  while (iVar15 = iVar15 + 1, iVar15 < 10) {
LAB_001d77c2:
    if (*(int *)(param_5 + iVar15 * 4) != 0) break;
  }
LAB_001d77d8:
  if (__stack_chk_guard - local_6c == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_6c);
}

// ===== FUN_001d7888  @0x001d7888  (156 bytes)
void FUN_001d7888(undefined1 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined1 uStack_b1;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [16];
  undefined1 auStack_98 [80];
  undefined1 auStack_48 [40];
  int local_20;
  
  local_20 = __stack_chk_guard;
  local_ac = param_4;
  __aeabi_memclr8(auStack_48,0x28);
  if (0x7ffffffe < param_2 - 1) {
    if (param_2 != 0) {
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0x4b;
      uVar2 = 0xffffffff;
      goto LAB_001d790c;
    }
    param_1 = &uStack_b1;
    param_2 = 1;
  }
  if (-(int)param_1 - 2U < param_2) {
    param_2 = -(int)param_1 - 2U;
  }
  FUN_001d7acc(auStack_a8,param_1,param_2);
  local_b0 = local_ac;
  uVar2 = FUN_001d66a0(auStack_a8,param_3,&local_b0,auStack_98,auStack_48);
  if (uVar2 < param_2) {
    param_1[uVar2] = 0;
  }
  else {
    param_1[param_2 - 1] = 0;
  }
LAB_001d790c:
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}

// ===== FUN_001d792c  @0x001d792c  (16 bytes)
void FUN_001d792c(undefined4 param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  
  bVar2 = 0x13 < param_2;
  bVar1 = param_2 == 0x14;
  if (param_2 < 0x15) {
    param_2 = param_2 - 9;
    bVar2 = 8 < param_2;
    bVar1 = param_2 == 9;
  }
  if (bVar2 && !bVar1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x001d7936. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&DAT_001d793a + (uint)(byte)(&DAT_001d793a)[param_2] * 2))();
  return;
}

// ===== FUN_001d79d8  @0x001d79d8  (78 bytes)
byte * FUN_001d79d8(uint param_1,int param_2,byte *param_3)

{
  bool bVar1;
  ulonglong uVar2;
  byte extraout_r2;
  ulonglong uVar3;
  
  uVar2 = CONCAT44(param_2,param_1);
  if (param_2 != 0) {
    do {
      uVar3 = __aeabi_uldivmod((int)uVar2,(int)(uVar2 >> 0x20),10,0);
      param_1 = (uint)uVar3;
      param_3 = param_3 + -1;
      *param_3 = extraout_r2 | 0x30;
      bVar1 = 0x9ffffffff < uVar2;
      uVar2 = uVar3;
    } while (bVar1);
  }
  if (param_1 != 0) {
    do {
      param_3 = param_3 + -1;
      *param_3 = (char)param_1 + (char)(param_1 / 10) * -10 | 0x30;
      bVar1 = 9 < param_1;
      param_1 = param_1 / 10;
    } while (bVar1);
  }
  return param_3;
}

// ===== FUN_001d7a28  @0x001d7a28  (126 bytes)
void FUN_001d7a28(undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_120 [260];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((param_4 < param_3) && ((param_5 & 0x12000) == 0)) {
    uVar2 = param_3 - param_4;
    uVar1 = uVar2;
    if (0x100 < uVar2) {
      uVar1 = 0x100;
    }
    __aeabi_memset8(auStack_120,uVar1,param_2);
    uVar1 = uVar2;
    if (0xff < uVar2) {
      do {
        FUN_001d7ae6(param_1,auStack_120,0x100);
        uVar1 = uVar1 - 0x100;
      } while (0xff < uVar1);
      uVar2 = uVar2 & 0xff;
    }
    FUN_001d7ae6(param_1,auStack_120,uVar2);
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== FUN_001d7ab4  @0x001d7ab4  (12 bytes)
undefined4 FUN_001d7ab4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_001d7ce0(param_1,param_2,0);
    return uVar1;
  }
  return 0;
}

// ===== FUN_001d7ac0  @0x001d7ac0  (12 bytes)
void FUN_001d7ac0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

// ===== FUN_001d7acc  @0x001d7acc  (12 bytes)
undefined4 * FUN_001d7acc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[3] = 0;
  return param_1 + 4;
}

// ===== FUN_001d7ae6  @0x001d7ae6  (58 bytes)
void FUN_001d7ae6(undefined4 *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 != 0) {
    if ((FILE *)*param_1 != (FILE *)0x0) {
      fwrite(param_2,1,param_3,(FILE *)*param_1);
      return;
    }
    uVar1 = param_1[2] - param_1[3];
    if (uVar1 < param_3) {
      param_3 = uVar1;
    }
    __aeabi_memcpy(param_1[1] + param_1[3],param_2,param_3);
    param_1[3] = param_1[3] + param_3;
  }
  return;
}

// ===== FUN_001d7b1e  @0x001d7b1e  (118 bytes)
void FUN_001d7b1e(int *param_1,undefined4 param_2,uint param_3)

{
  size_t __size;
  void *__ptr;
  uint uVar1;
  
  if (param_3 != 0) {
    if (*param_1 != 0) {
      __size = FUN_001d7d80(0,param_2,param_3);
      __ptr = malloc(__size);
      FUN_001d7d80(__ptr,param_2,param_3);
      fwrite(__ptr,1,__size,(FILE *)*param_1);
      free(__ptr);
      return;
    }
    uVar1 = param_1[2] - param_1[3];
    if (uVar1 >> 2 < param_3) {
      param_3 = uVar1 >> 2;
    }
    __aeabi_memcpy(param_1[1] + param_1[3],param_2,param_3 << 2);
    param_1[3] = param_1[3] + param_3 * 4;
  }
  return;
}

// ===== FUN_001d7ca8  @0x001d7ca8  (48 bytes)
void FUN_001d7ca8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_10 = param_2;
  FUN_001d7db8(param_1,&local_10,param_3,0);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_001d7ce0  @0x001d7ce0  (160 bytes)
undefined4 FUN_001d7ce0(byte *param_1,uint param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  
  if (param_1 != (byte *)0x0) {
    bVar1 = (byte)param_2;
    if (0x7f < param_2) {
      if (param_2 >> 0xb == 0) {
        *param_1 = (byte)(param_2 >> 6) | 0xc0;
        param_1[1] = bVar1 & 0x3f | 0x80;
        return 2;
      }
      if ((0xd7ff < param_2) && ((param_2 & 0xffffe000) != 0xe000)) {
        if (param_2 - 0x10000 >> 0x14 == 0) {
          *param_1 = (byte)(param_2 >> 0x12) | 0xf0;
          param_1[1] = (byte)(param_2 >> 0xc) & 0x3f | 0x80;
          param_1[2] = (byte)(param_2 >> 6) & 0x3f | 0x80;
          param_1[3] = bVar1 & 0x3f | 0x80;
          return 4;
        }
        puVar2 = (undefined4 *)__errno();
        *puVar2 = 0x54;
        return 0xffffffff;
      }
      *param_1 = (byte)(param_2 >> 0xc) | 0xe0;
      param_1[1] = (byte)(param_2 >> 6) & 0x3f | 0x80;
      param_1[2] = bVar1 & 0x3f | 0x80;
      return 3;
    }
    *param_1 = bVar1;
  }
  return 1;
}

// ===== FUN_001d7d80  @0x001d7d80  (48 bytes)
void FUN_001d7d80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  int local_c;
  
  local_c = __stack_chk_guard;
  local_10 = param_2;
  FUN_001d7f84(param_1,&local_10,param_3,0);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== FUN_001d7db8  @0x001d7db8  (452 bytes)
uint FUN_001d7db8(uint *param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  
  puVar7 = (uint *)*param_2;
  uVar3 = param_3;
  if ((param_4 == (uint *)0x0) || (uVar8 = *param_4, uVar8 == 0)) {
    if (param_1 != (uint *)0x0) goto joined_r0x001d7e80;
    goto LAB_001d7dfa;
  }
  if (param_1 != (uint *)0x0) {
    *param_4 = 0;
LAB_001d7ef2:
    bVar2 = (byte)*puVar7;
    if (((bVar2 >> 3) - 0x10 | (uint)(bVar2 >> 3) + ((int)uVar8 >> 0x1a)) < 8) {
      puVar6 = (uint *)((int)puVar7 + 1);
      uVar8 = bVar2 - 0x80 | uVar8 << 6;
      if (uVar8 < 0x80000000) goto LAB_001d7f48;
      if (*(byte *)puVar6 - 0x80 < 0x40) {
        uVar8 = *(byte *)puVar6 - 0x80 | uVar8 << 6;
        puVar6 = (uint *)((int)puVar7 + 2);
        if (-1 < (int)uVar8) {
LAB_001d7f48:
          *param_1 = uVar8;
          uVar3 = uVar3 - 1;
          param_1 = param_1 + 1;
          puVar7 = puVar6;
joined_r0x001d7e80:
          do {
            if (uVar3 == 0) {
              *param_2 = puVar7;
              return param_3;
            }
            uVar8 = (uint)(byte)*puVar7;
            if (((uVar8 - 1 < 0x7f) && (4 < uVar3)) && (((uint)puVar7 & 3) == 0)) {
              do {
                uVar8 = *puVar7;
                if (((uVar8 + 0xfefefeff | uVar8) & 0x80808080) != 0) goto LAB_001d7ec4;
                uVar3 = uVar3 - 4;
                *param_1 = uVar8 & 0xff;
                param_1[1] = (uint)*(byte *)((int)puVar7 + 1);
                param_1[2] = (uint)*(byte *)((int)puVar7 + 2);
                pbVar1 = (byte *)((int)puVar7 + 3);
                puVar7 = puVar7 + 1;
                param_1[3] = (uint)*pbVar1;
                param_1 = param_1 + 4;
              } while (4 < uVar3);
              uVar8 = (uint)(byte)*puVar7;
            }
LAB_001d7ec4:
            if (0x7e < (uVar8 & 0xff) - 1) goto LAB_001d7ee0;
            *param_1 = uVar8 & 0xff;
            uVar3 = uVar3 - 1;
            param_1 = param_1 + 1;
            puVar7 = (uint *)((int)puVar7 + 1);
          } while( true );
        }
        if (*(byte *)puVar6 - 0x80 < 0x40) {
          uVar8 = *(byte *)puVar6 - 0x80 | uVar8 << 6;
          puVar6 = (uint *)((int)puVar7 + 3);
          goto LAB_001d7f48;
        }
      }
      puVar7 = (uint *)((int)puVar7 + -1);
      goto LAB_001d7f5a;
    }
    goto LAB_001d7f0a;
  }
  for (; ((byte)((byte)*puVar7 >> 3) - 0x10 |
         (uint)(byte)((byte)*puVar7 >> 3) + ((int)uVar8 >> 0x1a)) < 8;
      uVar8 = *(uint *)(&DAT_00261858 + uVar8 * 4)) {
    puVar6 = (uint *)((int)puVar7 + 1);
    if ((uVar8 & 0x2000000) != 0) {
      if ((*(byte *)puVar6 & 0xc0) != 0x80) break;
      puVar6 = (uint *)((int)puVar7 + 2);
      if ((uVar8 & 0x80000) != 0) {
        if ((*(byte *)puVar6 & 0xc0) != 0x80) break;
        puVar6 = (uint *)((int)puVar7 + 3);
      }
    }
    uVar3 = uVar3 - 1;
    puVar7 = puVar6;
LAB_001d7dfa:
    while( true ) {
      uVar8 = (uint)(byte)*puVar7;
      if ((uVar8 - 1 < 0x7f) && (((uint)puVar7 & 3) == 0)) {
        uVar8 = *puVar7;
        uVar5 = uVar8 + 0xfefefeff | uVar8;
        while ((uVar5 & 0x80808080) == 0) {
          puVar7 = puVar7 + 1;
          uVar8 = *puVar7;
          uVar3 = uVar3 - 4;
          uVar5 = uVar8 + 0xfefefeff | uVar8;
        }
      }
      if (0x7e < (uVar8 & 0xff) - 1) break;
      uVar3 = uVar3 - 1;
      puVar7 = (uint *)((int)puVar7 + 1);
    }
    uVar8 = (uVar8 & 0xff) - 0xc2;
    if (0x32 < uVar8) goto LAB_001d7f12;
    puVar7 = (uint *)((int)puVar7 + 1);
  }
LAB_001d7f0a:
  puVar7 = (uint *)((int)puVar7 + -1);
  if (uVar8 == 0) {
LAB_001d7f12:
    if ((byte)*puVar7 == 0) {
      if (param_1 != (uint *)0x0) {
        *param_1 = 0;
        *param_2 = 0;
      }
      return param_3 - uVar3;
    }
  }
LAB_001d7f5a:
  puVar4 = (undefined4 *)__errno();
  *puVar4 = 0x54;
  if (param_1 != (uint *)0x0) {
    *param_2 = puVar7;
  }
  return 0xffffffff;
LAB_001d7ee0:
  uVar8 = (uVar8 & 0xff) - 0xc2;
  if (0x32 < uVar8) goto LAB_001d7f12;
  puVar7 = (uint *)((int)puVar7 + 1);
  uVar8 = *(uint *)(&DAT_00261858 + uVar8 * 4);
  goto LAB_001d7ef2;
}

// ===== FUN_001d7f84  @0x001d7f84  (280 bytes)
void FUN_001d7f84(undefined1 *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_2c [4];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 == (undefined1 *)0x0) {
    puVar2 = (uint *)*param_2;
    uVar3 = *puVar2;
    if (uVar3 != 0) {
      do {
        puVar2 = puVar2 + 1;
        if ((0x7f < uVar3) && (iVar4 = FUN_001d7ce0(auStack_2c,uVar3,0), iVar4 == -1)) break;
        uVar3 = *puVar2;
      } while (uVar3 != 0);
    }
  }
  else {
    if (3 < param_3) {
      piVar5 = (int *)*param_2;
      puVar6 = param_1;
      do {
        iVar4 = *piVar5;
        if (iVar4 - 1U < 0x7f) {
          piVar5 = (int *)*param_2;
          iVar1 = -1;
          param_1 = puVar6 + 1;
          *puVar6 = (char)iVar4;
        }
        else {
          if (iVar4 == 0) goto LAB_001d8074;
          iVar4 = FUN_001d7ce0(puVar6,iVar4,0);
          if (iVar4 == -1) goto LAB_001d8082;
          iVar1 = -iVar4;
          param_1 = puVar6 + iVar4;
        }
        param_3 = param_3 + iVar1;
        piVar5 = piVar5 + 1;
        *param_2 = (int)piVar5;
        puVar6 = param_1;
      } while (3 < param_3);
    }
    if (param_3 != 0) {
      piVar5 = (int *)*param_2;
      puVar6 = param_1;
      do {
        iVar4 = *piVar5;
        if (iVar4 - 1U < 0x7f) {
          piVar5 = (int *)*param_2;
          iVar1 = -1;
          puVar7 = puVar6 + 1;
          *puVar6 = (char)iVar4;
        }
        else {
          if (iVar4 == 0) goto LAB_001d8074;
          uVar3 = FUN_001d7ce0(auStack_2c,iVar4,0);
          if ((uVar3 == 0xffffffff) || (param_3 < uVar3)) break;
          FUN_001d7ce0(puVar6,*piVar5,0);
          iVar1 = -uVar3;
          puVar7 = puVar6 + uVar3;
        }
        param_3 = param_3 + iVar1;
        piVar5 = piVar5 + 1;
        *param_2 = (int)piVar5;
        puVar6 = puVar7;
      } while (param_3 != 0);
    }
  }
LAB_001d8082:
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
LAB_001d8074:
  *puVar6 = 0;
  *param_2 = 0;
  goto LAB_001d8082;
}

// ===== FUN_00261924  @0x00261924  (62 bytes)
void FUN_00261924(undefined1 param_1)

{
  Engine *this;
  int unaff_r8;
  
  if (((*(char *)(unaff_r8 + 0x62) == '\0') &&
      (this = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager),
      this != (Engine *)0x0)) && ((*(uint *)(this + 0x400) & 1) != 0)) {
    AbyssEngine::Engine::SetPostEffect(this,0x1400000,false);
  }
  *(undefined1 *)(unaff_r8 + 0x62) = param_1;
  return;
}

// ===== FUN_002619a4  @0x002619a4  (62 bytes)
undefined8 FUN_002619a4(undefined4 param_1,undefined4 param_2)

{
  Engine *this;
  int unaff_r4;
  undefined1 unaff_r6;
  
  if (((*(char *)(unaff_r4 + 0x62) == '\0') &&
      (this = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager),
      this != (Engine *)0x0)) && ((*(uint *)(this + 0x400) & 1) != 0)) {
    AbyssEngine::Engine::SetPostEffect(this,0x1400000,false);
  }
  *(undefined1 *)(unaff_r4 + 0x62) = unaff_r6;
  return CONCAT44(param_2,param_1);
}

// ===== FUN_00261a24  @0x00261a24  (72 bytes)
void FUN_00261a24(void)

{
  Engine *this;
  int unaff_r4;
  
  if ((((*(char *)(unaff_r4 + 0x62) != '\0') &&
       (this = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager),
       this != (Engine *)0x0)) && (*(int *)(this + 0x404) != 0)) &&
     ((*(uint *)(this + 0x400) & 1) == 0)) {
    AbyssEngine::Engine::SetPostEffect(this,0x1400000,true);
  }
  *(undefined1 *)(unaff_r4 + 0x62) = 0;
  return;
}

// ===== FUN_00261aa4  @0x00261aa4  (36 bytes)
undefined8 FUN_00261aa4(undefined4 param_1,undefined4 param_2)

{
  Engine *this;
  int unaff_r9;
  
  this = *(Engine **)(unaff_r9 + 0xa8);
  if ((this != (Engine *)0x0) && (*(int *)(this + 0x404) == 0)) {
    AbyssEngine::Engine::SetPostEffect(this,0x1400000,true);
  }
  return CONCAT44(param_2,*(undefined4 *)(unaff_r9 + 0xa8));
}

