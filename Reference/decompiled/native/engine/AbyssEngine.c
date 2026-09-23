// Class: AbyssEngine
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::MeshConvertToVBO  @0x00074710  (56 bytes)
/* AbyssEngine::MeshConvertToVBO(AbyssEngine::Mesh*) */

undefined4 AbyssEngine::MeshConvertToVBO(Mesh *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xfffffffc;
  if ((param_1 != (Mesh *)0x0) && (Engine::vboSupported != '\0')) {
    if ((param_1[0x5c] != (Mesh)0x0) || (param_1[0x84] == (Mesh)0x0)) {
      return 0xfffffffc;
    }
    MeshConvertToVBOIntern(param_1);
    TransformConvertToVBO(*(Transform **)(param_1 + 0x34));
    uVar1 = 1;
  }
  return uVar1;
}

// ===== AbyssEngine::TransformRelease  @0x00074efc  (78 bytes)
/* AbyssEngine::TransformRelease(AbyssEngine::Engine*, AbyssEngine::Transform**) */

void AbyssEngine::TransformRelease(Engine *param_1,Transform **param_2)

{
  Transform *pTVar1;
  uint uVar2;
  int iVar3;
  
  pTVar1 = *param_2;
  if (pTVar1 != (Transform *)0x0) {
    if (*(int *)(pTVar1 + 0x4c) != 0) {
      iVar3 = 0;
      uVar2 = 0;
      do {
        TransformRelease(param_1,(Transform **)(*(int *)(pTVar1 + 0x50) + iVar3));
        pTVar1 = *param_2;
        iVar3 = iVar3 + 4;
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(pTVar1 + 0x4c));
    }
    if (*(int *)(pTVar1 + 0x3c) != 0) {
      iVar3 = 0;
      uVar2 = 0;
      do {
        MeshRelease(param_1,(Mesh **)(*(int *)(pTVar1 + 0x40) + iVar3));
        pTVar1 = *param_2;
        iVar3 = iVar3 + 4;
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(pTVar1 + 0x3c));
    }
  }
  return;
}

// ===== AbyssEngine::MeshRelease  @0x00074f4a  (32 bytes)
/* AbyssEngine::MeshRelease(AbyssEngine::Engine*, AbyssEngine::Mesh**) */

void AbyssEngine::MeshRelease(Engine *param_1,Mesh **param_2)

{
  Engine *pEVar1;
  
  if ((param_1 != (Engine *)0x0) && (*param_2 != (Mesh *)0x0)) {
    pEVar1 = (Engine *)TransformRelease(param_1,(Transform **)(*param_2 + 0x34));
    MeshReleaseIntern(pEVar1,param_2);
    return;
  }
  return;
}

// ===== AbyssEngine::MeshReleaseIntern  @0x00074f68  (288 bytes)
/* AbyssEngine::MeshReleaseIntern(AbyssEngine::Engine*, AbyssEngine::Mesh**) */

void AbyssEngine::MeshReleaseIntern(Engine *param_1,Mesh **param_2)

{
  Mesh MVar1;
  void *pvVar2;
  Mesh *pMVar3;
  
  pMVar3 = *param_2;
  if (pMVar3 != (Mesh *)0x0) {
    if (pMVar3[0x38] == (Mesh)0x0) {
      if (pMVar3[0x5c] != (Mesh)0x0) {
        glDeleteBuffers(1,pMVar3 + 0x60);
        glDeleteBuffers(1,*param_2 + 100);
        pMVar3 = *param_2;
        MVar1 = *pMVar3;
        if (((byte)MVar1 & 2) != 0) {
          glDeleteBuffers(1,pMVar3 + 0x68);
          pMVar3 = *param_2;
          MVar1 = *pMVar3;
        }
        if ((((byte)MVar1 & 4) != 0) &&
           (glDeleteBuffers(1,pMVar3 + 0x6c), Engine::enableShader != '\0')) {
          glDeleteBuffers(1,*param_2 + 0x70);
          glDeleteBuffers(1,*param_2 + 0x74);
        }
        pMVar3 = *param_2;
        if (((byte)*pMVar3 & 8) != 0) {
          glDeleteBuffers(1,pMVar3 + 0x78);
          pMVar3 = *param_2;
        }
      }
      if (*(void **)(pMVar3 + 0x2c) != (void *)0x0) {
        operator_delete__(*(void **)(pMVar3 + 0x2c));
        pMVar3 = *param_2;
      }
      *(undefined4 *)(pMVar3 + 0x2c) = 0;
      pMVar3 = *param_2;
      if (*(void **)(pMVar3 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pMVar3 + 4));
        pMVar3 = *param_2;
      }
      *(undefined4 *)(pMVar3 + 4) = 0;
      pMVar3 = *param_2;
      if (*(void **)(pMVar3 + 8) != (void *)0x0) {
        operator_delete__(*(void **)(pMVar3 + 8));
        pMVar3 = *param_2;
      }
      *(undefined4 *)(pMVar3 + 8) = 0;
      pMVar3 = *param_2;
      if (*(void **)(pMVar3 + 0xc) != (void *)0x0) {
        operator_delete__(*(void **)(pMVar3 + 0xc));
        pMVar3 = *param_2;
      }
      *(undefined4 *)(pMVar3 + 0xc) = 0;
      pMVar3 = *param_2;
      if (*(void **)(pMVar3 + 0x10) != (void *)0x0) {
        operator_delete__(*(void **)(pMVar3 + 0x10));
        pMVar3 = *param_2;
      }
      *(undefined4 *)(pMVar3 + 0x10) = 0;
      if (Engine::enableShader != '\0') {
        pMVar3 = *param_2;
        if (*(void **)(pMVar3 + 0x14) != (void *)0x0) {
          operator_delete__(*(void **)(pMVar3 + 0x14));
          pMVar3 = *param_2;
        }
        *(undefined4 *)(pMVar3 + 0x14) = 0;
        pMVar3 = *param_2;
        if (*(void **)(pMVar3 + 0x18) != (void *)0x0) {
          operator_delete__(*(void **)(pMVar3 + 0x18));
          pMVar3 = *param_2;
        }
        *(undefined4 *)(pMVar3 + 0x18) = 0;
      }
    }
    pMVar3 = *param_2;
    if (*(Transform **)(pMVar3 + 0x34) != (Transform *)0x0) {
      pvVar2 = (void *)Transform::~Transform(*(Transform **)(pMVar3 + 0x34));
      operator_delete(pvVar2);
      pMVar3 = *param_2;
    }
    *(undefined4 *)(pMVar3 + 0x34) = 0;
    if (*param_2 != (Mesh *)0x0) {
      operator_delete(*param_2);
    }
    *param_2 = (Mesh *)0x0;
  }
  return;
}

// ===== AbyssEngine::MeshCreate  @0x00075090  (366 bytes)
/* AbyssEngine::MeshCreate(AbyssEngine::Engine*, unsigned short, unsigned short, signed char,
   AbyssEngine::Mesh**) */

undefined4
AbyssEngine::MeshCreate(undefined4 param_1,uint param_2,int param_3,byte param_4,int *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  void *pvVar5;
  uint uVar6;
  
  if (((3 < param_2) && (param_3 != 0)) && ((param_4 & 1) != 0)) {
    pbVar4 = operator_new(0x88);
    uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    pbVar4[0x3c] = 0;
    pbVar4[0x3d] = 0;
    pbVar4[0x3e] = 0;
    pbVar4[0x3f] = 0;
    *(undefined4 *)(pbVar4 + 0x40) = uVar1;
    *(undefined4 *)(pbVar4 + 0x44) = uVar2;
    *(undefined4 *)(pbVar4 + 0x48) = uVar3;
    pbVar4[0x14] = 0;
    pbVar4[0x15] = 0;
    pbVar4[0x16] = 0;
    pbVar4[0x17] = 0;
    *(undefined4 *)(pbVar4 + 0x18) = uVar1;
    *(undefined4 *)(pbVar4 + 0x1c) = uVar2;
    *(undefined4 *)(pbVar4 + 0x20) = uVar3;
    pbVar4[8] = 0;
    pbVar4[9] = 0;
    pbVar4[10] = 0;
    pbVar4[0xb] = 0;
    *(undefined4 *)(pbVar4 + 0xc) = uVar1;
    *(undefined4 *)(pbVar4 + 0x10) = uVar2;
    *(undefined4 *)(pbVar4 + 0x14) = uVar3;
    pbVar4[0x28] = 0;
    pbVar4[0x29] = 0;
    pbVar4[0x2a] = 0;
    pbVar4[0x2b] = 0;
    *(undefined4 *)(pbVar4 + 0x2c) = uVar1;
    *(undefined4 *)(pbVar4 + 0x30) = uVar2;
    *(undefined4 *)(pbVar4 + 0x34) = uVar3;
    pbVar4[0x38] = 0;
    pbVar4[0x4c] = 0;
    pbVar4[0x4d] = 0;
    pbVar4[0x4e] = 0x80;
    pbVar4[0x4f] = 0x3f;
    pbVar4[0x50] = 0;
    pbVar4[0x51] = 0;
    pbVar4[0x52] = 0;
    pbVar4[0x53] = 0;
    pbVar4[0x54] = 0;
    pbVar4[0x55] = 0;
    pbVar4[0x56] = 0;
    pbVar4[0x57] = 0;
    pbVar4[0x59] = 0;
    pbVar4[0x5a] = 0;
    pbVar4[0x5b] = 0;
    pbVar4[0x5c] = 0;
    pbVar4[0x55] = 0;
    pbVar4[0x56] = 0;
    pbVar4[0x57] = 0;
    pbVar4[0x58] = 0;
    pbVar4[0x70] = 0;
    pbVar4[0x71] = 0;
    pbVar4[0x72] = 0;
    pbVar4[0x73] = 0;
    *(undefined4 *)(pbVar4 + 0x74) = uVar1;
    *(undefined4 *)(pbVar4 + 0x78) = uVar2;
    *(undefined4 *)(pbVar4 + 0x7c) = uVar3;
    pbVar4[0x60] = 0;
    pbVar4[0x61] = 0;
    pbVar4[0x62] = 0;
    pbVar4[99] = 0;
    *(undefined4 *)(pbVar4 + 100) = uVar1;
    *(undefined4 *)(pbVar4 + 0x68) = uVar2;
    *(undefined4 *)(pbVar4 + 0x6c) = uVar3;
    pbVar4[0x82] = 0;
    pbVar4[0x83] = 0;
    pbVar4[0x84] = 0;
    pbVar4[0x85] = 0;
    pbVar4[0x7e] = 0;
    pbVar4[0x7f] = 0;
    pbVar4[0x80] = 0;
    pbVar4[0x81] = 0;
    *param_5 = (int)pbVar4;
    *pbVar4 = param_4;
    *(short *)(pbVar4 + 2) = (short)param_2;
    *(short *)(pbVar4 + 0x28) = (short)param_3 * 3;
    *(short *)(pbVar4 + 0x2a) = (short)param_3;
    uVar6 = param_2 * 0xc;
    pvVar5 = operator_new__(uVar6);
    *(void **)(pbVar4 + 4) = pvVar5;
    __aeabi_memclr4(*(undefined4 *)(*param_5 + 4),uVar6);
    if ((param_4 & 0x10) != 0) {
      pvVar5 = operator_new__(param_3 * 6);
      *(void **)(*param_5 + 0x2c) = pvVar5;
      __aeabi_memclr(*(undefined4 *)(*param_5 + 0x2c),param_3 * 6);
    }
    if ((param_4 & 2) != 0) {
      pvVar5 = operator_new__(param_2 << 3);
      *(void **)(*param_5 + 8) = pvVar5;
      __aeabi_memclr4(*(undefined4 *)(*param_5 + 8),param_2 << 3);
    }
    if ((param_4 & 4) != 0) {
      pvVar5 = operator_new__(uVar6);
      *(void **)(*param_5 + 0x10) = pvVar5;
      __aeabi_memclr4(*(undefined4 *)(*param_5 + 0x10),uVar6);
      if (Engine::enableShader != '\0') {
        pvVar5 = operator_new__(uVar6);
        *(void **)(*param_5 + 0x14) = pvVar5;
        __aeabi_memclr4(*(undefined4 *)(*param_5 + 0x14),uVar6);
        pvVar5 = operator_new__(uVar6);
        *(void **)(*param_5 + 0x18) = pvVar5;
        __aeabi_memclr4(*(undefined4 *)(*param_5 + 0x18),uVar6);
      }
    }
    if ((param_4 & 8) != 0) {
      pvVar5 = operator_new__(param_2 << 4);
      *(void **)(*param_5 + 0xc) = pvVar5;
      __aeabi_memclr4(*(undefined4 *)(*param_5 + 0xc),param_2 << 4);
    }
    return 1;
  }
  return 0xfffffffc;
}

// ===== AbyssEngine::MeshReadData  @0x00075208  (2602 bytes)
/* AbyssEngine::MeshReadData(AbyssEngine::Engine*, unsigned int const&, unsigned int,
   AbyssEngine::Mesh**, AbyssEngine::Material*) */

void AbyssEngine::MeshReadData
               (Engine *param_1,uint *param_2,uint param_3,Mesh **param_4,Material *param_5)

{
  byte *pbVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  Mesh *pMVar6;
  void *pvVar7;
  void *pvVar8;
  uint uVar9;
  float extraout_r0;
  undefined4 uVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  float *pfVar16;
  float *pfVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  short *psVar21;
  uint uVar22;
  uint in_fpscr;
  float fVar23;
  float fVar24;
  undefined4 uVar28;
  undefined4 uVar30;
  undefined1 in_q4 [16];
  undefined1 auVar29 [12];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined4 uVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  AEMath aAStack_b4 [12];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  undefined8 local_90;
  float local_88;
  Mesh *local_80;
  float local_7c;
  float local_78;
  float local_74 [6];
  int local_5c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  
  uStack_58 = in_q4._0_8_;
  uStack_50 = in_q4._8_8_;
  uVar20 = param_3 & 0x1a;
  local_5c = __stack_chk_guard;
  if ((uVar20 == 0) || (iVar5 = AEFile::Read(0xc,*param_4 + 0x50,*param_2), iVar5 == 1)) {
    pMVar6 = *param_4;
    if (((byte)*pMVar6 & 0x10) == 0) {
LAB_00075292:
      iVar5 = AEFile::Read(2,pMVar6 + 2,*param_2);
      auVar29 = in_q4._4_12_;
      if (iVar5 == 1) {
        local_74[5] = 1e+07;
        local_74[3] = 1e+07;
        local_74[4] = 1e+07;
        local_74[2] = -1e+07;
        local_74[0] = -1e+07;
        local_74[1] = -1e+07;
        if ((param_3 & 4) == 0) {
          if ((param_3 & 3) == 0) {
            if ((param_3 & 0x18) != 0) {
              pMVar6 = *param_4;
              pvVar7 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 0xc);
              *(void **)(pMVar6 + 4) = pvVar7;
              iVar5 = AEFile::Read((uint)*(ushort *)(*param_4 + 2) * 0xc,*(void **)(*param_4 + 4),
                                   *param_2);
              auVar29 = in_q4._4_12_;
              if (iVar5 != 1) goto LAB_00075ad4;
            }
          }
          else {
            pMVar6 = *param_4;
            pvVar7 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 0xc);
            iVar5 = AEFile::Read((uint)*(ushort *)(pMVar6 + 2) * 0xc,pvVar7,*param_2);
            if (iVar5 != 1) goto LAB_00075ad0;
            pMVar6 = *param_4;
            pvVar8 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 0xc);
            *(void **)(pMVar6 + 4) = pvVar8;
            uVar9 = (uint)*(ushort *)(*param_4 + 2);
            if (uVar9 != 0) {
              pfVar11 = *(float **)(*param_4 + 4);
              uVar14 = 0;
              do {
                fVar23 = (float)VectorSignedToFloat(*(undefined4 *)((int)pvVar7 + uVar14 * 4),
                                                    (byte)(in_fpscr >> 0x16) & 3);
                uVar18 = uVar14 % 3;
                uVar14 = uVar14 + 1;
                *pfVar11 = fVar23;
                pfVar11 = pfVar11 + 1;
                in_fpscr = in_fpscr & 0xfffffff;
                if (fVar23 < local_74[uVar18 + 3]) {
                  local_74[uVar18 + 3] = fVar23;
                }
                if (local_74[uVar18] < fVar23) {
                  local_74[uVar18] = fVar23;
                }
              } while (uVar14 < uVar9 * 3);
            }
            operator_delete__(pvVar7);
            auVar29 = in_q4._4_12_;
          }
LAB_0007546a:
          fVar34 = local_74[5];
          fVar32 = local_74[2];
          fVar33 = local_74[1];
          fVar23 = local_74[0];
          auVar25._4_12_ = auVar29;
          auVar25._0_4_ = local_74[3];
          auVar26._12_4_ = auVar29._8_4_;
          auVar26._0_8_ = auVar25._0_8_;
          auVar26._8_4_ = local_74[4];
          local_80 = (Mesh *)((local_74[0] + local_74[3]) * 0.5);
          local_7c = (local_74[1] + local_74[4]) * 0.5;
          local_78 = (local_74[2] + local_74[5]) * 0.5;
          AEMath::Vector::operator=((Vector *)(*param_4 + 0x3c),(Vector *)&local_80);
          local_90 = CONCAT44(fVar33,fVar23);
          local_9c = auVar26._0_4_;
          local_98 = auVar26._8_4_;
          local_88 = fVar32;
          local_94 = fVar34;
          AEMath::operator-((AEMath *)&local_80,(Vector *)&local_90,(Vector *)&local_9c);
          uVar9 = AEMath::VectorLength((Vector *)&local_80);
          pMVar6 = *param_4;
          *(uint *)(pMVar6 + 0x48) = uVar9;
          if ((*(uint *)pMVar6 & 2) != 0) {
            uVar9 = *(uint *)pMVar6 >> 0x10;
            if ((param_3 & 7) == 0) {
              if ((param_3 & 0x18) != 0) {
                pvVar7 = operator_new__(uVar9 << 3);
                *(void **)(pMVar6 + 8) = pvVar7;
                iVar5 = AEFile::Read((uint)*(ushort *)(*param_4 + 2) << 3,*(void **)(*param_4 + 8),
                                     *param_2);
                if (iVar5 != 1) goto LAB_00075ad4;
                if (Engine::enableShader != '\0') {
                  uVar9 = (uint)*(ushort *)(*param_4 + 2);
                  if (uVar9 != 0) {
                    pfVar11 = (float *)(*(int *)(*param_4 + 8) + 4);
                    uVar14 = 0;
                    do {
                      uVar14 = uVar14 + 2;
                      *pfVar11 = 1.0 - *pfVar11;
                      pfVar11 = pfVar11 + 2;
                    } while (uVar14 < uVar9 << 1);
                  }
                }
              }
            }
            else {
              pvVar7 = operator_new__(uVar9 << 2);
              iVar5 = AEFile::Read((uint)*(ushort *)(pMVar6 + 2) << 2,pvVar7,*param_2);
              if (iVar5 != 1) goto LAB_00075ad0;
              pMVar6 = *param_4;
              pvVar8 = operator_new__((uint)*(ushort *)(pMVar6 + 2) << 3);
              *(void **)(pMVar6 + 8) = pvVar8;
              cVar4 = Engine::enableShader;
              uVar9 = (uint)*(ushort *)(*param_4 + 2);
              if (uVar9 != 0) {
                uVar14 = 0;
                pfVar11 = (float *)(*(int *)(*param_4 + 8) + 4);
                do {
                  dVar37 = (double)VectorSignedToFloat((int)*(short *)((int)pvVar7 + uVar14 * 2),
                                                       (byte)(in_fpscr >> 0x16) & 3);
                  pfVar11[-1] = (float)(dVar37 * 0.000244140625);
                  dVar37 = (double)VectorSignedToFloat((int)*(short *)((int)pvVar7 + uVar14 * 2 + 2)
                                                       ,(byte)(in_fpscr >> 0x16) & 3);
                  dVar37 = dVar37 * 0.000244140625;
                  if (cVar4 != '\0') {
                    dVar37 = 1.0 - dVar37;
                  }
                  uVar14 = uVar14 + 2;
                  *pfVar11 = (float)dVar37;
                  pfVar11 = pfVar11 + 2;
                } while (uVar14 < uVar9 << 1);
              }
              operator_delete__(pvVar7);
            }
          }
          pMVar6 = *param_4;
          if ((*(uint *)pMVar6 & 4) != 0) {
            uVar9 = *(uint *)pMVar6 >> 0x10;
            if ((param_3 & 7) == 0) {
              if ((param_3 & 0x18) != 0) {
                pvVar7 = operator_new__(uVar9 * 0xc);
                *(void **)(pMVar6 + 0x10) = pvVar7;
                iVar5 = AEFile::Read((uint)*(ushort *)(*param_4 + 2) * 0xc,
                                     *(void **)(*param_4 + 0x10),*param_2);
                if (iVar5 != 1) goto LAB_00075ad4;
              }
            }
            else {
              pvVar7 = operator_new__(uVar9 * 6);
              iVar5 = AEFile::Read((uint)*(ushort *)(pMVar6 + 2) * 6,pvVar7,*param_2);
              if (iVar5 != 1) goto LAB_00075ad0;
              pMVar6 = *param_4;
              pvVar8 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 0xc);
              *(void **)(pMVar6 + 0x10) = pvVar8;
              if (*(short *)(*param_4 + 2) != 0) {
                psVar21 = (short *)((int)pvVar7 + 2);
                iVar5 = 4;
                uVar9 = 0;
                auVar26._8_8_ = 0xbff0000000000000;
                auVar26._0_8_ = 0x3f00000000000000;
                do {
                  dVar35 = (double)VectorSignedToFloat((int)*psVar21,(byte)(in_fpscr >> 0x16) & 3);
                  dVar37 = auVar26._0_8_;
                  dVar36 = (double)VectorSignedToFloat((int)psVar21[-1],(byte)(in_fpscr >> 0x16) & 3
                                                      );
                  dVar38 = (double)VectorSignedToFloat((int)psVar21[1],(byte)(in_fpscr >> 0x16) & 3)
                  ;
                  fVar32 = (float)(dVar35 * dVar37);
                  fVar34 = (float)(dVar36 * dVar37);
                  fVar33 = (float)(dVar38 * dVar37);
                  fVar23 = SQRT(fVar34 * fVar34 + fVar32 * fVar32 + fVar33 * fVar33);
                  uVar14 = in_fpscr & 0xfffffff;
                  if (NAN(fVar23)) {
                    sqrtf(fVar23);
                    fVar23 = extraout_r0;
                  }
                  in_fpscr = uVar14 & 0xfffffff | (uint)(fVar23 == 0.0) << 0x1e;
                  if ((byte)(in_fpscr >> 0x1e) == 0) {
                    dVar37 = (double)(fVar34 / fVar23);
                    dVar35 = auVar26._8_8_;
                    fVar33 = fVar33 / fVar23;
                    if (dVar37 < dVar35) {
                      dVar37 = dVar35;
                    }
                    dVar36 = (double)(fVar32 / fVar23);
                    if (dVar36 < dVar35) {
                      dVar36 = dVar35;
                    }
                    dVar38 = (double)fVar33;
                    if ((double)fVar33 < dVar35) {
                      dVar38 = dVar35;
                    }
                    pMVar6 = *param_4;
                    fVar24 = (float)dVar37;
                    if (1.0 < fVar34 / fVar23) {
                      fVar24 = 1.0;
                    }
                    uVar14 = uVar14 & 0xfffffff | (uint)(fVar33 < 1.0) << 0x1f |
                             (uint)(fVar33 == 1.0) << 0x1e;
                    in_fpscr = uVar14 | (uint)NAN(fVar33) << 0x1c;
                    fVar33 = (float)dVar36;
                    if (1.0 < fVar32 / fVar23) {
                      fVar33 = 1.0;
                    }
                    bVar3 = (byte)(uVar14 >> 0x18);
                    fVar23 = (float)dVar38;
                    if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
                      fVar23 = 1.0;
                    }
                    pfVar11 = (float *)(*(int *)(pMVar6 + 0x10) + iVar5);
                    pfVar11[-1] = fVar24;
                    *pfVar11 = fVar33;
                    pfVar11[1] = fVar23;
                  }
                  else {
                    pMVar6 = *param_4;
                    iVar12 = *(int *)(pMVar6 + 0x10);
                    iVar15 = iVar12 + iVar5;
                    *(undefined4 *)(iVar15 + -4) = 0;
                    *(undefined4 *)(iVar12 + iVar5) = 0x3f800000;
                    *(undefined4 *)(iVar15 + 4) = 0;
                  }
                  psVar21 = psVar21 + 3;
                  iVar5 = iVar5 + 0xc;
                  uVar9 = uVar9 + 3;
                } while (uVar9 < (uint)*(ushort *)(pMVar6 + 2) * 3);
              }
              operator_delete__(pvVar7);
            }
            if (Engine::enableShader != '\0') {
              pMVar6 = *param_4;
              pvVar7 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 0xc);
              *(void **)(pMVar6 + 0x14) = pvVar7;
              pMVar6 = *param_4;
              pvVar7 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 0xc);
              *(void **)(pMVar6 + 0x18) = pvVar7;
              pMVar6 = *param_4;
              uVar2 = *(ushort *)(pMVar6 + 0x28);
              uVar9 = (uint)*(ushort *)(pMVar6 + 2);
              pvVar7 = operator_new__(uVar9 * 0xc);
              auVar29 = auVar26._4_12_;
              if (uVar9 != 0) {
                __aeabi_memclr4(pvVar7,((uVar9 * 0xc - 0xc) / 0xc) * 0xc + 0xc);
                auVar29 = auVar26._4_12_;
              }
              if (2 < uVar2) {
                auVar27._4_12_ = auVar29;
                auVar27._0_4_ = 0x3f800000;
                iVar5 = 0;
                iVar12 = 0;
                while( true ) {
                  iVar15 = *(int *)(pMVar6 + 4);
                  iVar13 = *(int *)(pMVar6 + 8);
                  iVar19 = *(int *)(pMVar6 + 0x2c) + iVar5;
                  uVar14 = (uint)*(ushort *)(*(int *)(pMVar6 + 0x2c) + iVar5);
                  uVar22 = (uint)*(ushort *)(iVar19 + 4);
                  uVar18 = (uint)*(ushort *)(iVar19 + 2);
                  fVar23 = *(float *)((uVar14 << 3 | 4) + iVar13);
                  fVar33 = *(float *)(iVar13 + uVar14 * 8);
                  fVar32 = *(float *)((uVar18 << 3 | 4) + iVar13) - fVar23;
                  pfVar16 = (float *)(iVar15 + uVar14 * 0xc);
                  fVar23 = *(float *)((uVar22 << 3 | 4) + iVar13) - fVar23;
                  pfVar17 = (float *)(iVar15 + uVar22 * 0xc);
                  pfVar11 = (float *)(iVar15 + uVar18 * 0xc);
                  local_78 = auVar27._0_4_ /
                             ((*(float *)(iVar13 + uVar18 * 8) - fVar33) * fVar23 -
                             (*(float *)(iVar13 + uVar22 * 8) - fVar33) * fVar32);
                  local_80 = (Mesh *)(((*pfVar11 - *pfVar16) * fVar23 -
                                      (*pfVar17 - *pfVar16) * fVar32) * local_78);
                  local_7c = ((pfVar11[1] - pfVar16[1]) * fVar23 -
                             (pfVar17[1] - pfVar16[1]) * fVar32) * local_78;
                  local_78 = ((pfVar11[2] - pfVar16[2]) * fVar23 -
                             (pfVar17[2] - pfVar16[2]) * fVar32) * local_78;
                  AEMath::Vector::operator+=
                            ((Vector *)((int)pvVar7 + uVar14 * 0xc),(Vector *)&local_80);
                  AEMath::Vector::operator+=
                            ((Vector *)((int)pvVar7 + uVar18 * 0xc),(Vector *)&local_80);
                  AEMath::Vector::operator+=
                            ((Vector *)((int)pvVar7 + uVar22 * 0xc),(Vector *)&local_80);
                  iVar12 = iVar12 + 1;
                  if ((int)(uVar2 / 3) <= iVar12) break;
                  iVar5 = iVar5 + 6;
                  pMVar6 = *param_4;
                }
              }
              if (uVar9 != 0) {
                pMVar6 = *param_4;
                iVar5 = 4;
                do {
                  local_7c = *(float *)(*(int *)(pMVar6 + 0x10) + iVar5);
                  iVar12 = *(int *)(pMVar6 + 0x10) + iVar5;
                  local_78 = *(float *)(iVar12 + 4);
                  local_80 = *(Mesh **)(iVar12 + -4);
                  local_90 = *(undefined8 *)((int)pvVar7 + iVar5 + -4);
                  local_88 = *(float *)((int)pvVar7 + iVar5 + 4);
                  fVar23 = (float)AEMath::VectorDot((Vector *)&local_80,(Vector *)&local_90);
                  AEMath::operator*(aAStack_b4,(Vector *)&local_80,fVar23);
                  AEMath::operator-((AEMath *)&local_a8,(Vector *)&local_90,(Vector *)aAStack_b4);
                  AEMath::VectorNormalize((AEMath *)&local_9c,(Vector *)&local_a8);
                  iVar12 = *(int *)(*param_4 + 0x14);
                  iVar15 = iVar12 + iVar5;
                  *(undefined4 *)(iVar15 + -4) = local_9c;
                  *(undefined4 *)(iVar12 + iVar5) = local_98;
                  *(float *)(iVar15 + 4) = local_94;
                  AEMath::VectorCross((AEMath *)&local_a8,(Vector *)&local_80,(Vector *)&local_9c);
                  pMVar6 = *param_4;
                  uVar9 = uVar9 - 1;
                  iVar12 = *(int *)(pMVar6 + 0x18);
                  iVar15 = iVar12 + iVar5;
                  *(undefined4 *)(iVar15 + -4) = local_a8;
                  *(undefined4 *)(iVar12 + iVar5) = local_a4;
                  iVar5 = iVar5 + 0xc;
                  *(undefined4 *)(iVar15 + 4) = local_a0;
                } while (uVar9 != 0);
              }
            }
          }
          pMVar6 = *param_4;
          if ((*(uint *)pMVar6 & 8) == 0) {
LAB_00075b2e:
            if (uVar20 != 0) goto LAB_00075b36;
          }
          else {
            uVar9 = *(uint *)pMVar6 >> 0x10;
            if ((param_3 & 7) != 0) {
              pvVar7 = operator_new__(uVar9 << 2);
              iVar5 = AEFile::Read((uint)*(ushort *)(pMVar6 + 2) << 2,pvVar7,*param_2);
              if (iVar5 != 1) goto LAB_00075ad0;
              pMVar6 = *param_4;
              pvVar8 = operator_new__((uint)*(ushort *)(pMVar6 + 2) << 4);
              *(void **)(pMVar6 + 0xc) = pvVar8;
              uVar9 = (uint)*(ushort *)(*param_4 + 2);
              if (uVar9 != 0) {
                pfVar11 = *(float **)(*param_4 + 0xc);
                uVar14 = 0;
                do {
                  pbVar1 = (byte *)((int)pvVar7 + uVar14);
                  uVar14 = uVar14 + 1;
                  fVar23 = (float)VectorUnsignedToFloat((uint)*pbVar1,(byte)(in_fpscr >> 0x16) & 3);
                  *pfVar11 = fVar23 / 255.0;
                  pfVar11 = pfVar11 + 1;
                } while (uVar14 < uVar9 << 2);
              }
              operator_delete__(pvVar7);
              goto LAB_00075b2e;
            }
            if ((param_3 & 0x18) == 0) goto LAB_00075b2e;
            pvVar7 = operator_new__(uVar9 << 4);
            *(void **)(pMVar6 + 0xc) = pvVar7;
            iVar5 = AEFile::Read((uint)*(ushort *)(*param_4 + 2) << 4,*(void **)(*param_4 + 0xc),
                                 *param_2);
            uVar10 = 0xffffffff;
            if (iVar5 != 0) {
              uVar10 = 1;
            }
            if ((uVar20 == 0) || (iVar5 != 1)) goto LAB_00075ad8;
LAB_00075b36:
            iVar5 = Mesh::ReadEnhancedDataFromFile(*param_4,*param_2,param_3);
            if ((iVar5 == 0) || (iVar5 = AEFile::Read(2,&local_90,*param_2), iVar5 != 1))
            goto LAB_00075ad4;
            iVar5 = *(int *)(*param_4 + 0x34);
            if (iVar5 != 0) {
              AEMath::BSphere::Merge((BSphere *)(*param_4 + 0x3c),(BSphere *)(iVar5 + 0xd4));
            }
            if ((ushort)local_90 != 0) {
              uVar10 = 0;
              uVar28 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
              uVar30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
              uVar31 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
              iVar5 = 0;
              do {
                local_80 = operator_new(0x88);
                *local_80 = (Mesh)0x0;
                *(undefined4 *)(local_80 + 0x3c) = uVar10;
                *(undefined4 *)(local_80 + 0x40) = uVar28;
                *(undefined4 *)(local_80 + 0x44) = uVar30;
                *(undefined4 *)(local_80 + 0x48) = uVar31;
                *(undefined4 *)(local_80 + 0x12) = uVar10;
                *(undefined4 *)(local_80 + 0x16) = uVar28;
                *(undefined4 *)(local_80 + 0x1a) = uVar30;
                *(undefined4 *)(local_80 + 0x1e) = uVar31;
                *(undefined4 *)(local_80 + 2) = uVar10;
                *(undefined4 *)(local_80 + 6) = uVar28;
                *(undefined4 *)(local_80 + 10) = uVar30;
                *(undefined4 *)(local_80 + 0xe) = uVar31;
                *(undefined2 *)(local_80 + 0x22) = 0;
                *(undefined4 *)(local_80 + 0x28) = uVar10;
                *(undefined4 *)(local_80 + 0x2c) = uVar28;
                *(undefined4 *)(local_80 + 0x30) = uVar30;
                *(undefined4 *)(local_80 + 0x34) = uVar31;
                local_80[0x38] = (Mesh)0x0;
                *(undefined4 *)(local_80 + 0x4c) = 0x3f800000;
                *(undefined4 *)(local_80 + 0x50) = 0;
                *(undefined4 *)(local_80 + 0x54) = 0;
                *(undefined4 *)(local_80 + 0x59) = 0;
                *(undefined4 *)(local_80 + 0x55) = 0;
                *(undefined4 *)(local_80 + 0x70) = uVar10;
                *(undefined4 *)(local_80 + 0x74) = uVar28;
                *(undefined4 *)(local_80 + 0x78) = uVar30;
                *(undefined4 *)(local_80 + 0x7c) = uVar31;
                *(undefined4 *)(local_80 + 0x60) = uVar10;
                *(undefined4 *)(local_80 + 100) = uVar28;
                *(undefined4 *)(local_80 + 0x68) = uVar30;
                *(undefined4 *)(local_80 + 0x6c) = uVar31;
                *(undefined4 *)(local_80 + 0x82) = 0;
                *(undefined4 *)(local_80 + 0x7e) = 0;
                local_80[0x84] = (Mesh)0x1;
                pMVar6 = *param_4;
                *local_80 = *pMVar6;
                *(undefined4 *)(local_80 + 0x30) = *(undefined4 *)(pMVar6 + 0x30);
                iVar12 = MeshReadData(param_1,param_2,param_3,&local_80,param_5);
                if (iVar12 == -1) goto LAB_00075ad4;
                AEMath::BSphere::Merge((BSphere *)(*param_4 + 0x3c),(BSphere *)(local_80 + 0x3c));
                pMVar6 = local_80;
                iVar15 = *(int *)(*param_4 + 0x34);
                iVar12 = *(int *)(iVar15 + 0x3c) + 1;
                *(int *)(iVar15 + 0x44) = iVar12;
                pvVar7 = realloc(*(void **)(iVar15 + 0x40),iVar12 * 4);
                *(void **)(iVar15 + 0x40) = pvVar7;
                iVar5 = iVar5 + 1;
                *(Mesh **)((int)pvVar7 + *(int *)(iVar15 + 0x3c) * 4) = pMVar6;
                *(undefined4 *)(iVar15 + 0x3c) = *(undefined4 *)(iVar15 + 0x44);
              } while (iVar5 < (int)(uint)(ushort)local_90);
            }
          }
          uVar10 = 1;
          goto LAB_00075ad8;
        }
        pMVar6 = *param_4;
        pvVar7 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 6);
        iVar5 = AEFile::Read((uint)*(ushort *)(pMVar6 + 2) * 6,pvVar7,*param_2);
        if (iVar5 == 1) {
          pMVar6 = *param_4;
          pvVar8 = operator_new__((uint)*(ushort *)(pMVar6 + 2) * 0xc);
          *(void **)(pMVar6 + 4) = pvVar8;
          uVar9 = (uint)*(ushort *)(*param_4 + 2);
          if (uVar9 != 0) {
            pfVar11 = *(float **)(*param_4 + 4);
            uVar14 = 0;
            do {
              fVar23 = (float)VectorSignedToFloat((int)*(short *)((int)pvVar7 + uVar14 * 2),
                                                  (byte)(in_fpscr >> 0x16) & 3);
              uVar18 = uVar14 % 3;
              uVar14 = uVar14 + 1;
              *pfVar11 = fVar23;
              pfVar11 = pfVar11 + 1;
              in_fpscr = in_fpscr & 0xfffffff;
              if (fVar23 < local_74[uVar18 + 3]) {
                local_74[uVar18 + 3] = fVar23;
              }
              if (local_74[uVar18] < fVar23) {
                local_74[uVar18] = fVar23;
              }
            } while (uVar14 < uVar9 * 3);
          }
          operator_delete__(pvVar7);
          auVar29 = in_q4._4_12_;
          goto LAB_0007546a;
        }
LAB_00075ad0:
        operator_delete__(pvVar7);
      }
    }
    else {
      iVar5 = AEFile::Read(2,pMVar6 + 0x28,*param_2);
      if (iVar5 == 1) {
        pMVar6 = *param_4;
        pvVar7 = operator_new__((uint)*(ushort *)(pMVar6 + 0x28) << 1);
        *(void **)(pMVar6 + 0x2c) = pvVar7;
        iVar5 = AEFile::Read((uint)*(ushort *)(*param_4 + 0x28) << 1,*(void **)(*param_4 + 0x2c),
                             *param_2);
        if (iVar5 == 1) {
          pMVar6 = *param_4;
          goto LAB_00075292;
        }
      }
    }
  }
LAB_00075ad4:
  uVar10 = 0xffffffff;
LAB_00075ad8:
  if (__stack_chk_guard == local_5c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar10);
}

// ===== AbyssEngine::MeshCreateFromFile  @0x00075c60  (804 bytes)
/* AbyssEngine::MeshCreateFromFile(AbyssEngine::Engine*, char const*, AbyssEngine::Mesh**,
   AbyssEngine::Material*) */

void AbyssEngine::MeshCreateFromFile(Engine *param_1,char *param_2,Mesh **param_3,Material *param_4)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  Mesh *pMVar4;
  int iVar5;
  Transform *this;
  int iVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  longlong lVar13;
  Mesh *local_50;
  ushort uStack_4a;
  char local_48 [8];
  uint local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  uVar3 = 0xfffffffc;
  if (param_1 == (Engine *)0x0 || param_2 == (char *)0x0) goto LAB_00075f66;
  pMVar4 = operator_new(0x88);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *pMVar4 = (Mesh)0x0;
  *(undefined4 *)(pMVar4 + 0x3c) = 0;
  *(undefined4 *)(pMVar4 + 0x40) = uVar3;
  *(undefined4 *)(pMVar4 + 0x44) = uVar10;
  *(undefined4 *)(pMVar4 + 0x48) = uVar11;
  *(undefined4 *)(pMVar4 + 0x12) = 0;
  *(undefined4 *)(pMVar4 + 0x16) = uVar3;
  *(undefined4 *)(pMVar4 + 0x1a) = uVar10;
  *(undefined4 *)(pMVar4 + 0x1e) = uVar11;
  *(undefined4 *)(pMVar4 + 2) = 0;
  *(undefined4 *)(pMVar4 + 6) = uVar3;
  *(undefined4 *)(pMVar4 + 10) = uVar10;
  *(undefined4 *)(pMVar4 + 0xe) = uVar11;
  *(undefined2 *)(pMVar4 + 0x22) = 0;
  *(undefined4 *)(pMVar4 + 0x28) = 0;
  *(undefined4 *)(pMVar4 + 0x2c) = uVar3;
  *(undefined4 *)(pMVar4 + 0x30) = uVar10;
  *(undefined4 *)(pMVar4 + 0x34) = uVar11;
  pMVar4[0x38] = (Mesh)0x0;
  *(undefined4 *)(pMVar4 + 0x4c) = 0x3f800000;
  *(undefined4 *)(pMVar4 + 0x50) = 0;
  *(undefined4 *)(pMVar4 + 0x54) = 0;
  *(undefined4 *)(pMVar4 + 0x59) = 0;
  *(undefined4 *)(pMVar4 + 0x55) = 0;
  *(undefined4 *)(pMVar4 + 0x70) = 0;
  *(undefined4 *)(pMVar4 + 0x74) = uVar3;
  *(undefined4 *)(pMVar4 + 0x78) = uVar10;
  *(undefined4 *)(pMVar4 + 0x7c) = uVar11;
  *(undefined4 *)(pMVar4 + 0x60) = 0;
  *(undefined4 *)(pMVar4 + 100) = uVar3;
  *(undefined4 *)(pMVar4 + 0x68) = uVar10;
  *(undefined4 *)(pMVar4 + 0x6c) = uVar11;
  *(undefined4 *)(pMVar4 + 0x82) = 0;
  *(undefined4 *)(pMVar4 + 0x7e) = 0;
  *param_3 = pMVar4;
  local_40 = 0;
  *(Material **)(pMVar4 + 0x30) = param_4;
  iVar5 = AEFile::OpenRead(param_2,&local_40);
  if (iVar5 == 0) {
    if (*param_3 != (Mesh *)0x0) {
      operator_delete(*param_3);
    }
    *param_3 = (Mesh *)0x0;
  }
  else {
    builtin_strncpy(local_48 + 4,"***",4);
    builtin_strncpy(local_48,"****",4);
    iVar5 = AEFile::Read(7,local_48,local_40);
    if (iVar5 == 1) {
      iVar5 = 0;
      uVar9 = 0x1f;
      do {
        cVar2 = local_48[iVar5];
        if ("AEMesh"[iVar5] != cVar2) {
          uVar9 = uVar9 & 0xfffffffb;
        }
        if ("V2AEMesh"[iVar5] != cVar2) {
          uVar9 = uVar9 & 0xfffffffe;
        }
        pcVar1 = "V5AEMesh" + iVar5;
        if ("V3AEMesh"[iVar5] != cVar2) {
          uVar9 = uVar9 & 0xfffffffd;
        }
        if ("V4AEMesh"[iVar5] != cVar2) {
          uVar9 = uVar9 & 0xfffffff7;
        }
        iVar5 = iVar5 + 1;
        if (*pcVar1 != cVar2) {
          uVar9 = uVar9 & 0xffffffef;
        }
      } while (iVar5 != 7);
      if (((uVar9 != 0) &&
          (((timeBetweenFrames = 0x49742400, (uVar9 & 0x1b) == 0 ||
            (iVar5 = AEFile::Read(2,local_48,local_40), iVar5 == 1)) &&
           (iVar5 = AEFile::Read(1,*param_3,local_40), iVar5 == 1)))) && (**param_3 != (Mesh)0x0)) {
        if ((uVar9 & 0x1a) == 0) {
LAB_00075f00:
          iVar5 = MeshReadData(param_1,&local_40,uVar9,param_3,param_4);
          if (iVar5 != -1) {
LAB_00075f16:
            AEFile::Close(local_40);
            if (*(Transform **)(*param_3 + 0x34) != (Transform *)0x0) {
              Transform::CollectAnimationData(*(Transform **)(*param_3 + 0x34));
              pMVar4 = *param_3;
              lVar13 = __aeabi_f2lz(timeBetweenFrames);
              Transform::SetAnimationRangeInTime
                        (CONCAT44((int)((ulonglong)lVar13 >> 0x20),*(undefined4 *)(pMVar4 + 0x34)),
                         lVar13);
            }
            uVar3 = 1;
            goto LAB_00075f66;
          }
        }
        else {
          iVar5 = AEFile::Read(2,&uStack_4a,local_40);
          if (iVar5 == 1) {
            if (uStack_4a < 2) goto LAB_00075f00;
            this = operator_new(0x180);
            Transform::Transform(this);
            *(Transform **)(*param_3 + 0x34) = this;
            if (uStack_4a != 0) {
              uVar3 = 0;
              uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
              uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
              uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
              iVar5 = 0;
              do {
                local_50 = operator_new(0x88);
                *local_50 = (Mesh)0x0;
                *(undefined4 *)(local_50 + 0x3c) = uVar3;
                *(undefined4 *)(local_50 + 0x40) = uVar10;
                *(undefined4 *)(local_50 + 0x44) = uVar11;
                *(undefined4 *)(local_50 + 0x48) = uVar12;
                *(undefined4 *)(local_50 + 0x12) = uVar3;
                *(undefined4 *)(local_50 + 0x16) = uVar10;
                *(undefined4 *)(local_50 + 0x1a) = uVar11;
                *(undefined4 *)(local_50 + 0x1e) = uVar12;
                *(undefined4 *)(local_50 + 2) = uVar3;
                *(undefined4 *)(local_50 + 6) = uVar10;
                *(undefined4 *)(local_50 + 10) = uVar11;
                *(undefined4 *)(local_50 + 0xe) = uVar12;
                *(undefined2 *)(local_50 + 0x22) = 0;
                *(undefined4 *)(local_50 + 0x28) = uVar3;
                *(undefined4 *)(local_50 + 0x2c) = uVar10;
                *(undefined4 *)(local_50 + 0x30) = uVar11;
                *(undefined4 *)(local_50 + 0x34) = uVar12;
                local_50[0x38] = (Mesh)0x0;
                *(undefined4 *)(local_50 + 0x4c) = 0x3f800000;
                *(undefined4 *)(local_50 + 0x50) = 0;
                *(undefined4 *)(local_50 + 0x54) = 0;
                *(undefined4 *)(local_50 + 0x59) = 0;
                *(undefined4 *)(local_50 + 0x55) = 0;
                *(undefined4 *)(local_50 + 0x70) = uVar3;
                *(undefined4 *)(local_50 + 0x74) = uVar10;
                *(undefined4 *)(local_50 + 0x78) = uVar11;
                *(undefined4 *)(local_50 + 0x7c) = uVar12;
                *(undefined4 *)(local_50 + 0x60) = uVar3;
                *(undefined4 *)(local_50 + 100) = uVar10;
                *(undefined4 *)(local_50 + 0x68) = uVar11;
                *(undefined4 *)(local_50 + 0x6c) = uVar12;
                *(undefined4 *)(local_50 + 0x82) = 0;
                *(undefined4 *)(local_50 + 0x7e) = 0;
                local_50[0x84] = (Mesh)0x1;
                *local_50 = **param_3;
                *(Material **)(local_50 + 0x30) = param_4;
                iVar6 = MeshReadData(param_1,&local_40,uVar9,&local_50,param_4);
                if (iVar6 == -1) goto LAB_00075f54;
                AEMath::BSphere::Merge((BSphere *)(*param_3 + 0x3c),(BSphere *)(local_50 + 0x3c));
                pMVar4 = local_50;
                iVar8 = *(int *)(*param_3 + 0x34);
                iVar6 = *(int *)(iVar8 + 0x3c) + 1;
                *(int *)(iVar8 + 0x44) = iVar6;
                pvVar7 = realloc(*(void **)(iVar8 + 0x40),iVar6 * 4);
                *(void **)(iVar8 + 0x40) = pvVar7;
                iVar5 = iVar5 + 1;
                *(Mesh **)((int)pvVar7 + *(int *)(iVar8 + 0x3c) * 4) = pMVar4;
                *(undefined4 *)(iVar8 + 0x3c) = *(undefined4 *)(iVar8 + 0x44);
              } while (iVar5 < (int)(uint)uStack_4a);
            }
            goto LAB_00075f16;
          }
        }
      }
    }
LAB_00075f54:
    MeshRelease(param_1,param_3);
    AEFile::Close(local_40);
  }
  uVar3 = 0xffffffff;
LAB_00075f66:
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

// ===== AbyssEngine::MeshDraw  @0x00075fb8  (368 bytes)
/* AbyssEngine::MeshDraw(AbyssEngine::Engine*, AbyssEngine::Mesh*) */

undefined4 AbyssEngine::MeshDraw(Engine *param_1,Mesh *param_2)

{
  if (((param_2 != (Mesh *)0x0) && (*(short *)(param_2 + 2) != 0)) && (((byte)*param_2 & 1) != 0)) {
    if ((Engine::enableShader == '\0') && (param_2[0x5c] != (Mesh)0x0)) {
      glBindBuffer(0x8892,*(undefined4 *)(param_2 + 0x60));
      Engine::AEClientState(param_1,0x8074,true);
      glVertexPointer(3,0x1406,0,0);
      glBindBuffer(0x8893,*(undefined4 *)(param_2 + 100));
      if (((byte)*param_2 & 2) == 0) {
        Engine::AEClientState(param_1,0x8078,false);
      }
      else {
        glBindBuffer(0x8892,*(undefined4 *)(param_2 + 0x68));
        Engine::AEClientState(param_1,0x8078,true);
        glTexCoordPointer(2,0x1406,0,0);
      }
      if (((byte)*param_2 & 4) == 0) {
        Engine::AEClientState(param_1,0x8075,false);
      }
      else {
        glBindBuffer(0x8892,*(undefined4 *)(param_2 + 0x6c));
        Engine::AEClientState(param_1,0x8075,true);
        glNormalPointer(0x1406,0,0);
      }
      if (((byte)*param_2 & 8) == 0) {
        Engine::AEClientState(param_1,0x8076,false);
      }
      else {
        glBindBuffer(0x8892,*(undefined4 *)(param_2 + 0x78));
        Engine::AEClientState(param_1,0x8076,true);
        glColorPointer(4,0x1406,0,0);
      }
      glDrawElements(4,*(undefined2 *)(param_2 + 0x28),0x1403,0);
      if (param_1[0xee] != (Engine)0x0) {
        if (param_1[0xed] == (Engine)0x0) {
          *(uint *)(param_1 + 0x58) = *(ushort *)(param_2 + 0x28) / 3 + *(int *)(param_1 + 0x58);
          *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
        }
        else {
          *(uint *)(param_1 + 0x5c) = *(ushort *)(param_2 + 0x28) / 3 + *(int *)(param_1 + 0x5c);
          *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
        }
      }
      glBindBuffer(0x8892,0);
      glBindBuffer(0x8893,0);
    }
    else {
      Engine::RenderMesh(param_1,param_2);
    }
    return 1;
  }
  return 0xfffffffc;
}

// ===== AbyssEngine::MeshConvertToVBOIntern  @0x0007612c  (724 bytes)
/* AbyssEngine::MeshConvertToVBOIntern(AbyssEngine::Mesh*) */

undefined4 AbyssEngine::MeshConvertToVBOIntern(Mesh *param_1)

{
  Mesh MVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar2 = 0xfffffffc;
  if ((param_1 != (Mesh *)0x0) && (Engine::vboSupported != '\0')) {
    if ((param_1[0x5c] == (Mesh)0x0) && (*(short *)(param_1 + 0x28) != 0)) {
      uVar6 = *(undefined4 *)(param_1 + 4);
      uVar4 = *(undefined4 *)(param_1 + 8);
      uVar2 = *(undefined4 *)(param_1 + 0xc);
      uVar5 = *(undefined4 *)(param_1 + 0x10);
      uVar8 = *(undefined4 *)(param_1 + 0x14);
      uVar7 = *(undefined4 *)(param_1 + 0x18);
      glGenBuffers(1,param_1 + 0x60);
      glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
      glBufferData(0x8892,(uint)*(ushort *)(param_1 + 2) * 0xc,uVar6,0x88e4);
      MVar1 = *param_1;
      if (((byte)MVar1 & 2) != 0) {
        glGenBuffers(1,param_1 + 0x68);
        glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
        glBufferData(0x8892,(uint)*(ushort *)(param_1 + 2) << 3,uVar4,0x88e4);
        *(uint *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 2) * 8;
        glGenBuffers(1,param_1 + 100);
        glBindBuffer(0x8893,*(undefined4 *)(param_1 + 100));
        glBufferData(0x8893,(uint)*(ushort *)(param_1 + 0x28) << 1,*(undefined4 *)(param_1 + 0x2c),
                     0x88e4);
        *(uint *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x28) * 2
        ;
        MVar1 = *param_1;
      }
      if (((byte)MVar1 & 4) != 0) {
        glGenBuffers(1,param_1 + 0x6c);
        glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
        glBufferData(0x8892,(uint)*(ushort *)(param_1 + 2) * 0xc,uVar5,0x88e4);
        *(uint *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 2) * 0xc;
        if (Engine::enableShader != '\0') {
          glGenBuffers(1,param_1 + 0x70);
          glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x70));
          glBufferData(0x8892,(uint)*(ushort *)(param_1 + 2) * 0xc,uVar8,0x88e4);
          *(uint *)(param_1 + 0x7c) =
               *(int *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 2) * 0xc;
          glGenBuffers(1,param_1 + 0x74);
          glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x74));
          glBufferData(0x8892,(uint)*(ushort *)(param_1 + 2) * 0xc,uVar7,0x88e4);
          *(uint *)(param_1 + 0x7c) =
               *(int *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 2) * 0xc;
        }
      }
      if (((byte)*param_1 & 8) != 0) {
        glGenBuffers(1,param_1 + 0x78);
        glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x78));
        glBufferData(0x8892,(uint)*(ushort *)(param_1 + 2) << 4,uVar2,0x88e4);
        *(uint *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 2) * 0x10
        ;
      }
      glBindBuffer(0x8892,0);
      glBindBuffer(0x8893,0);
      iVar3 = glGetError();
      if (iVar3 == 0) {
        if (Engine::KeepRawMeshData == '\0') {
          if (*(void **)(param_1 + 4) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 4));
          }
          *(undefined4 *)(param_1 + 4) = 0;
          if (*(void **)(param_1 + 8) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 8));
          }
          *(undefined4 *)(param_1 + 8) = 0;
          if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 0x2c));
          }
          *(undefined4 *)(param_1 + 0x2c) = 0;
          if (*(void **)(param_1 + 0x10) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 0x10));
          }
          *(undefined4 *)(param_1 + 0x10) = 0;
          if (*(void **)(param_1 + 0xc) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 0xc));
          }
          *(undefined4 *)(param_1 + 0xc) = 0;
          if (*(void **)(param_1 + 0x14) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 0x14));
          }
          *(undefined4 *)(param_1 + 0x14) = 0;
          if (*(void **)(param_1 + 0x18) != (void *)0x0) {
            operator_delete__(*(void **)(param_1 + 0x18));
          }
          *(undefined4 *)(param_1 + 0x18) = 0;
        }
        uVar2 = 1;
        param_1[0x5c] = (Mesh)0x1;
        Engine::vboSize = *(int *)(param_1 + 0x7c) + Engine::vboSize;
      }
      else {
        if (param_1[0x5c] != (Mesh)0x0) {
          glDeleteBuffers(1,param_1 + 0x60);
          glDeleteBuffers(1,param_1 + 100);
          MVar1 = *param_1;
          if (((byte)MVar1 & 2) != 0) {
            glDeleteBuffers(1,param_1 + 0x68);
            MVar1 = *param_1;
          }
          if ((((byte)MVar1 & 4) != 0) &&
             (glDeleteBuffers(1,param_1 + 0x6c), Engine::enableShader != '\0')) {
            glDeleteBuffers(1,param_1 + 0x70);
            glDeleteBuffers(1,param_1 + 0x74);
          }
          if (((byte)*param_1 & 8) != 0) {
            glDeleteBuffers(1,param_1 + 0x78);
          }
        }
        *(undefined4 *)(param_1 + 0x7c) = 0;
        uVar2 = 0xffffffff;
      }
    }
    else {
      uVar2 = 0xfffffffc;
    }
  }
  return uVar2;
}

// ===== AbyssEngine::TransformConvertToVBO  @0x00076414  (60 bytes)
/* AbyssEngine::TransformConvertToVBO(AbyssEngine::Transform*) */

undefined4 AbyssEngine::TransformConvertToVBO(Transform *param_1)

{
  uint uVar1;
  
  if (param_1 != (Transform *)0x0) {
    if (*(int *)(param_1 + 0x3c) != 0) {
      uVar1 = 0;
      do {
        MeshConvertToVBO(*(Mesh **)(*(int *)(param_1 + 0x40) + uVar1 * 4));
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0x3c));
    }
    if (*(int *)(param_1 + 0x4c) != 0) {
      uVar1 = 0;
      do {
        TransformConvertToVBO(*(Transform **)(*(int *)(param_1 + 0x50) + uVar1 * 4));
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0x4c));
    }
  }
  return 1;
}

// ===== AbyssEngine::MeshIntersect  @0x00076450  (714 bytes)
/* AbyssEngine::MeshIntersect(float, float, AbyssEngine::Mesh*) */

float __thiscall
AbyssEngine::MeshIntersect(AbyssEngine *this,float param_1,float param_2,Mesh *param_3)

{
  int iVar1;
  float extraout_r0;
  float extraout_r0_00;
  float extraout_r0_01;
  int iVar2;
  uint uVar3;
  float in_r2;
  float *pfVar4;
  float *pfVar5;
  uint uVar6;
  int in_r3;
  uint uVar7;
  int iVar8;
  bool bVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  if (*(short *)(in_r3 + 0x28) != 0) {
    iVar8 = 0;
    do {
      iVar1 = *(int *)(in_r3 + 4);
      iVar2 = *(int *)(in_r3 + 0x2c) + iVar8 * 2;
      pfVar4 = (float *)(iVar1 + (uint)*(ushort *)(*(int *)(in_r3 + 0x2c) + iVar8 * 2) * 0xc);
      fVar16 = *pfVar4;
      fVar17 = pfVar4[2];
      pfVar5 = (float *)(iVar1 + (uint)*(ushort *)(iVar2 + 2) * 0xc);
      pfVar4 = (float *)(iVar1 + (uint)*(ushort *)(iVar2 + 4) * 0xc);
      fVar19 = pfVar5[2];
      fVar18 = *pfVar5;
      param_1 = fVar17;
      fVar10 = fVar19;
      if (fVar19 < fVar17) {
        param_1 = fVar19;
        fVar10 = fVar17;
      }
      fVar13 = fVar16;
      fVar11 = fVar18;
      if (fVar18 < fVar16) {
        fVar13 = fVar18;
        fVar11 = fVar16;
      }
      fVar15 = pfVar4[2];
      fVar14 = *pfVar4;
      fVar12 = fVar15;
      if (fVar15 < fVar10) {
        fVar12 = fVar10;
      }
      if (fVar15 < param_1) {
        param_1 = fVar15;
      }
      fVar10 = fVar14;
      if (fVar14 < fVar11) {
        fVar10 = fVar11;
      }
      if (fVar14 < fVar13) {
        fVar13 = fVar14;
      }
      if ((((-1 < (int)((uint)(fVar12 < in_r2) << 0x1f)) && (fVar13 <= (float)param_3)) &&
          (-1 < (int)((uint)(fVar10 < (float)param_3) << 0x1f))) && (param_1 <= in_r2)) {
        fVar11 = fVar19 - fVar17;
        fVar13 = fVar18 - fVar16;
        fVar10 = SQRT(fVar13 * fVar13 + fVar11 * fVar11);
        if (NAN(fVar10)) {
          sqrtf(fVar10);
          fVar10 = extraout_r0;
        }
        param_1 = ((-fVar11 / fVar10) * (float)param_3 + (fVar13 / fVar10) * in_r2) -
                  (fVar16 * (-fVar11 / fVar10) + fVar17 * (fVar13 / fVar10));
        if (param_1 <= 0.0) {
          fVar11 = fVar15 - fVar19;
          fVar13 = fVar14 - fVar18;
          fVar10 = SQRT(fVar13 * fVar13 + fVar11 * fVar11);
          if (NAN(fVar10)) {
            sqrtf(fVar10);
            fVar10 = extraout_r0_00;
          }
          param_1 = ((-fVar11 / fVar10) * (float)param_3 + (fVar13 / fVar10) * in_r2) -
                    (fVar18 * (-fVar11 / fVar10) + fVar19 * (fVar13 / fVar10));
          if (param_1 <= 0.0) {
            fVar17 = fVar17 - fVar15;
            fVar16 = fVar16 - fVar14;
            fVar10 = SQRT(fVar16 * fVar16 + fVar17 * fVar17);
            if (NAN(fVar10)) {
              sqrtf(fVar10);
              fVar10 = extraout_r0_01;
            }
            param_1 = ((-fVar17 / fVar10) * (float)param_3 + (fVar16 / fVar10) * in_r2) -
                      (fVar14 * (-fVar17 / fVar10) + fVar15 * (fVar16 / fVar10));
            if (param_1 <= 0.0) {
              iVar1 = *(int *)(in_r3 + 8);
              iVar2 = *(int *)(in_r3 + 0x2c) + iVar8 * 2;
              uVar3 = (uint)*(ushort *)(*(int *)(in_r3 + 0x2c) + iVar8 * 2);
              uVar7 = (uint)*(ushort *)(iVar2 + 2);
              uVar6 = (uint)*(ushort *)(iVar2 + 4);
              *(float *)this =
                   (*(float *)(iVar1 + uVar3 * 8) + *(float *)(iVar1 + uVar7 * 8) +
                   *(float *)(iVar1 + uVar6 * 8)) / 3.0;
              bVar9 = Engine::enableShader == '\0';
              fVar10 = (*(float *)((uVar3 << 3 | 4) + iVar1) + *(float *)((uVar7 << 3 | 4) + iVar1)
                       + *(float *)(iVar1 + (uVar6 << 3 | 4))) / 3.0;
              *(float *)(this + 4) = fVar10;
              if (bVar9) {
                return fVar10;
              }
              *(float *)(this + 4) = 1.0 - fVar10;
              return 1.0 - fVar10;
            }
          }
        }
      }
      iVar8 = iVar8 + 3;
    } while (iVar8 < (int)(uint)*(ushort *)(in_r3 + 0x28));
  }
  *(undefined4 *)this = 0xbf800000;
  *(undefined4 *)(this + 4) = 0xbf800000;
  return param_1;
}

// ===== AbyssEngine::ImageRelease  @0x00077d2e  (36 bytes)
/* AbyssEngine::ImageRelease(AbyssEngine::Image**) */

void AbyssEngine::ImageRelease(Image **param_1)

{
  Image *pIVar1;
  
  pIVar1 = *param_1;
  if (pIVar1 != (Image *)0x0) {
    if (*(void **)(pIVar1 + 0xc) != (void *)0x0) {
      operator_delete__(*(void **)(pIVar1 + 0xc));
      pIVar1 = *param_1;
    }
    *(undefined4 *)(pIVar1 + 0xc) = 0;
    if (*param_1 != (Image *)0x0) {
      operator_delete(*param_1);
    }
    *param_1 = (Image *)0x0;
  }
  return;
}

// ===== AbyssEngine::ImageCreateRegionFromFile  @0x00077d54  (684 bytes)
/* AbyssEngine::ImageCreateRegionFromFile(AbyssEngine::Engine*, char const*, unsigned short,
   AbyssEngine::Image2D*) */

void AbyssEngine::ImageCreateRegionFromFile
               (Engine *param_1,char *param_2,ushort param_3,Image2D *param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  float *pfVar4;
  undefined4 *puVar5;
  ushort uVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  ushort uStack_42;
  char local_40 [8];
  uint local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  uVar1 = 0xfffffffc;
  if ((param_1 != (Engine *)0x0) && (param_2 != (char *)0x0)) {
    local_38 = 0;
    iVar2 = AEFile::OpenRead(param_2,&local_38);
    if (iVar2 == 1) {
      builtin_strncpy(local_40 + 4,"***",4);
      builtin_strncpy(local_40,"****",4);
      iVar2 = AEFile::Read(8,local_40,local_38);
      if (iVar2 == 1) {
        uVar3 = 0;
        do {
          if ("AEimage"[uVar3] != local_40[uVar3]) goto LAB_00077fde;
          uVar3 = uVar3 + 1;
        } while (uVar3 < 8);
        iVar2 = AEFile::Skip(1,local_38);
        if (((iVar2 == 1) && (iVar2 = AEFile::Read(2,param_4 + 8,local_38), iVar2 == 1)) &&
           (iVar2 = AEFile::Read(2,param_4 + 10,local_38), iVar2 == 1)) {
          uStack_42 = 0;
          iVar2 = AEFile::Read(2,&uStack_42,local_38);
          uVar1 = 0xffffffff;
          if ((iVar2 == 1) && (param_3 < uStack_42)) {
            iVar2 = MeshCreate(param_1,4,2,0x13,param_4);
            if (iVar2 == 1) {
              if (uStack_42 != 0) {
                uVar6 = 0;
                do {
                  if (uVar6 == param_3) {
                    iVar2 = AEFile::Read(2,param_4 + 0xc,local_38);
                    if (((iVar2 == 0) ||
                        (iVar2 = AEFile::Read(2,param_4 + 0xe,local_38), iVar2 == 0)) ||
                       ((iVar2 = AEFile::Read(2,param_4 + 0x10,local_38), iVar2 == 0 ||
                        (iVar2 = AEFile::Read(2,param_4 + 0x12,local_38), iVar2 == 0)))) {
LAB_00077fd6:
                      MeshRelease(param_1,(Mesh **)param_4);
                      goto LAB_00077fde;
                    }
                    iVar2 = *(int *)param_4;
                    puVar5 = *(undefined4 **)(iVar2 + 4);
                    *puVar5 = 0;
                    puVar5[1] = 0;
                    puVar5[2] = 0;
                    fVar7 = (float)VectorUnsignedToFloat
                                             (*(uint *)(param_4 + 0x10) & 0xffff,
                                              (byte)(in_fpscr >> 0x16) & 3);
                    fVar8 = (float)VectorUnsignedToFloat
                                             (*(uint *)(param_4 + 0x10) >> 0x10,
                                              (byte)(in_fpscr >> 0x16) & 3);
                    puVar5[3] = fVar7;
                    puVar5[4] = 0;
                    puVar5[5] = 0;
                    puVar5[6] = fVar7;
                    puVar5[7] = fVar8;
                    puVar5[8] = 0;
                    puVar5[9] = 0;
                    puVar5[10] = fVar8;
                    puVar5[0xb] = 0;
                    uVar3 = *(uint *)(param_4 + 0xc);
                    fVar9 = (float)VectorSignedToFloat((int)(short)uVar3,
                                                       (byte)(in_fpscr >> 0x16) & 3);
                    fVar10 = (float)VectorSignedToFloat((int)uVar3 >> 0x10,
                                                        (byte)(in_fpscr >> 0x16) & 3);
                    fVar11 = (float)VectorUnsignedToFloat
                                              (uVar3 & 0xffff,(byte)(in_fpscr >> 0x16) & 3);
                    fVar12 = (float)VectorUnsignedToFloat
                                              (uVar3 >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
                    pfVar4 = *(float **)(iVar2 + 8);
                    fVar7 = fVar7 + fVar9;
                    fVar8 = fVar8 + fVar10;
                    *pfVar4 = fVar11;
                    pfVar4[1] = fVar12;
                    pfVar4[2] = fVar7;
                    pfVar4[3] = fVar12;
                    pfVar4[4] = fVar7;
                    pfVar4[5] = fVar8;
                    pfVar4[6] = fVar11;
                    pfVar4[7] = fVar8;
                    dVar13 = (double)VectorUnsignedToFloat
                                               (*(uint *)(param_4 + 8) & 0xffff,
                                                (byte)(in_fpscr >> 0x16) & 3);
                    dVar14 = (double)VectorUnsignedToFloat
                                               (*(uint *)(param_4 + 8) >> 0x10,
                                                (byte)(in_fpscr >> 0x16) & 3);
                    fVar11 = fVar11 * (float)(1.0 / dVar13);
                    fVar12 = fVar12 * (float)(1.0 / dVar14);
                    fVar7 = (float)(1.0 / dVar13) * fVar7;
                    fVar8 = (float)(1.0 / dVar14) * fVar8;
                    *pfVar4 = fVar11;
                    pfVar4[1] = fVar12;
                    pfVar4[2] = fVar7;
                    pfVar4[3] = fVar12;
                    pfVar4[4] = fVar7;
                    pfVar4[5] = fVar8;
                    pfVar4[6] = fVar11;
                    pfVar4[7] = fVar8;
                    puVar5 = *(undefined4 **)(*(int *)param_4 + 0x2c);
                    *puVar5 = 0x20000;
                    puVar5[1] = 1;
                    puVar5[2] = 0x20003;
                  }
                  else {
                    iVar2 = AEFile::Skip(8,local_38);
                    if (iVar2 == 0) goto LAB_00077fd6;
                  }
                  uVar6 = uVar6 + 1;
                } while (uVar6 < uStack_42);
              }
              AEFile::Close(local_38);
              uVar1 = 1;
            }
            else {
              uVar1 = 0xfffffffe;
            }
          }
          goto LAB_00077fe2;
        }
      }
    }
LAB_00077fde:
    uVar1 = 0xffffffff;
  }
LAB_00077fe2:
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}

// ===== AbyssEngine::ImageCreateFontFromFile  @0x0007800c  (940 bytes)
/* AbyssEngine::ImageCreateFontFromFile(AbyssEngine::Engine*, char const*, unsigned short,
   AbyssEngine::ImageFont**) */

void AbyssEngine::ImageCreateFontFromFile
               (Engine *param_1,char *param_2,ushort param_3,ImageFont **param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  ImageFont *pIVar4;
  void *pvVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  undefined2 *puVar9;
  undefined4 *puVar10;
  float *pfVar11;
  ushort uVar12;
  uint in_fpscr;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  double dVar20;
  ushort uStack_5a;
  ushort local_58;
  ushort uStack_56;
  uint local_54;
  char local_50 [15];
  byte bStack_41;
  ushort local_40;
  ushort uStack_3e;
  ushort local_3c;
  ushort uStack_3a;
  uint local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  uVar1 = 0xfffffffc;
  if ((param_1 == (Engine *)0x0) || (param_2 == (char *)0x0)) goto LAB_0007839a;
  local_38 = 0;
  uStack_3a = 0;
  local_3c = 0;
  uStack_3e = 0;
  local_40 = 0;
  bStack_41 = 0;
  iVar2 = AEFile::OpenRead(param_2,&local_38);
  if (iVar2 == 1) {
    builtin_strncpy(local_50 + 4,"***",4);
    builtin_strncpy(local_50,"****",4);
    iVar2 = AEFile::Read(8,local_50,local_38);
    if (iVar2 == 1) {
      uVar3 = 0;
      do {
        if ("AEimage"[uVar3] != local_50[uVar3]) goto LAB_00078396;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 8);
      iVar2 = AEFile::Read(1,&bStack_41,local_38);
      if ((((iVar2 == 1) && (iVar2 = AEFile::Read(2,&uStack_3e,local_38), iVar2 == 1)) &&
          (iVar2 = AEFile::Read(2,&local_40,local_38), iVar2 == 1)) &&
         ((iVar2 = AEFile::Read(2,&local_3c,local_38), iVar2 == 1 &&
          (iVar2 = AEFile::Skip((uint)local_3c << 3,local_38), iVar2 == 1)))) {
        uVar3 = (uint)bStack_41;
        uVar6 = uVar3 - 3;
        if (uVar6 < 0x1f) {
          if ((1 << (uVar6 & 0xff) & 0x601bf400U) != 0) goto LAB_00078124;
          if (uVar6 != 0) goto LAB_0007810c;
LAB_00078146:
          iVar2 = AEFile::Skip((uint)uStack_3e * (uint)local_40 * 4,local_38);
          if (iVar2 != 0) goto LAB_0007815e;
        }
        else {
LAB_0007810c:
          if ((uVar3 - 0x24 < 0x1f) && ((1 << (uVar3 - 0x24 & 0xff) & 0x50000001U) != 0)) {
LAB_00078124:
            iVar2 = AEFile::Read(4,&local_54,local_38);
            if ((iVar2 == 0) || (iVar2 = AEFile::Skip(local_54,local_38), iVar2 != 1))
            goto LAB_0007838e;
          }
          else if (uVar3 == 1) goto LAB_00078146;
LAB_0007815e:
          iVar2 = AEFile::Read(2,&uStack_3a,local_38);
          uVar7 = uStack_3a;
          if ((iVar2 == 1) && (param_3 < uStack_3a)) {
            pIVar4 = operator_new(0x14);
            *(undefined2 *)pIVar4 = 0;
            *(undefined8 *)(pIVar4 + 4) = 0;
            *(undefined8 *)(pIVar4 + 0xc) = 0;
            *param_4 = pIVar4;
            if (uVar7 != 0) {
              uVar7 = 0;
              do {
                if (uVar7 == param_3) {
                  iVar2 = AEFile::Read(2,*param_4,local_38);
                  if (iVar2 != 1) goto LAB_0007838e;
                  pIVar4 = *param_4;
                  pvVar5 = operator_new__((uint)*(ushort *)pIVar4 << 1);
                  *(void **)(pIVar4 + 4) = pvVar5;
                  iVar2 = AEFile::Read((uint)*(ushort *)*param_4 << 1,*(void **)(*param_4 + 4),
                                       local_38);
                  if (iVar2 != 1) goto LAB_0007838e;
                  pIVar4 = *param_4;
                  pvVar5 = operator_new__((uint)*(ushort *)pIVar4 << 2);
                  *(void **)(pIVar4 + 0xc) = pvVar5;
                  if (*(short *)*param_4 != 0) {
                    iVar2 = *(int *)(*param_4 + 0xc);
                    uVar3 = 0;
                    uVar12 = 0;
                    do {
                      iVar2 = MeshCreate(param_1,4,2,0x13,iVar2 + uVar3 * 4);
                      if (iVar2 != 1) goto LAB_0007838e;
                      local_54 = local_54 & 0xffff0000;
                      uStack_56 = 0;
                      local_58 = 0;
                      uStack_5a = 0;
                      iVar2 = AEFile::Read(2,&local_54,local_38);
                      if ((((iVar2 != 1) ||
                           (iVar2 = AEFile::Read(2,&uStack_56,local_38), iVar2 != 1)) ||
                          (iVar2 = AEFile::Read(2,&local_58,local_38), iVar2 != 1)) ||
                         (iVar2 = AEFile::Read(2,&uStack_5a,local_38), iVar2 != 1))
                      goto LAB_0007838e;
                      pIVar4 = *param_4;
                      uVar12 = uVar12 + 1;
                      iVar2 = *(int *)(pIVar4 + 0xc);
                      iVar8 = *(int *)(iVar2 + uVar3 * 4);
                      uVar3 = (uint)uVar12;
                      puVar10 = *(undefined4 **)(iVar8 + 4);
                      *puVar10 = 0;
                      puVar10[1] = 0;
                      puVar10[2] = 0;
                      fVar13 = (float)VectorUnsignedToFloat
                                                ((uint)local_58,(byte)(in_fpscr >> 0x16) & 3);
                      puVar10[3] = fVar13;
                      puVar10[4] = 0;
                      puVar10[5] = 0;
                      puVar10[6] = fVar13;
                      fVar14 = (float)VectorUnsignedToFloat
                                                ((uint)uStack_5a,(byte)(in_fpscr >> 0x16) & 3);
                      puVar10[7] = fVar14;
                      puVar10[8] = 0;
                      puVar10[9] = 0;
                      puVar10[10] = fVar14;
                      puVar10[0xb] = 0;
                      dVar19 = (double)VectorUnsignedToFloat
                                                 ((uint)uStack_3e,(byte)(in_fpscr >> 0x16) & 3);
                      dVar20 = (double)VectorUnsignedToFloat
                                                 ((uint)local_40,(byte)(in_fpscr >> 0x16) & 3);
                      fVar15 = (float)VectorUnsignedToFloat
                                                (local_54 & 0xffff,(byte)(in_fpscr >> 0x16) & 3);
                      fVar17 = (float)VectorUnsignedToFloat
                                                ((uint)uStack_56,(byte)(in_fpscr >> 0x16) & 3);
                      pfVar11 = *(float **)(iVar8 + 8);
                      fVar16 = fVar15 * (float)(1.0 / dVar19);
                      fVar18 = fVar17 * (float)(1.0 / dVar20);
                      fVar13 = (float)(1.0 / dVar19) * (fVar13 + fVar15);
                      fVar14 = (float)(1.0 / dVar20) * (fVar14 + fVar17);
                      *pfVar11 = fVar16;
                      pfVar11[1] = fVar18;
                      pfVar11[2] = fVar13;
                      pfVar11[3] = fVar18;
                      pfVar11[4] = fVar13;
                      pfVar11[5] = fVar14;
                      pfVar11[6] = fVar16;
                      pfVar11[7] = fVar14;
                      puVar9 = *(undefined2 **)(iVar8 + 0x2c);
                      *puVar9 = 0;
                      puVar9[1] = 2;
                      puVar9[2] = 1;
                      puVar9[3] = 0;
                      puVar9[4] = 3;
                      puVar9[5] = 2;
                    } while (uVar3 < *(ushort *)pIVar4);
                  }
                }
                else {
                  local_54 = local_54 & 0xffff0000;
                  iVar2 = AEFile::Read(2,&local_54,local_38);
                  if ((iVar2 != 1) ||
                     (iVar2 = AEFile::Skip((local_54 & 0xffff) * 10,local_38), iVar2 == 0))
                  goto LAB_0007838e;
                }
                uVar7 = uVar7 + 1;
              } while (uVar7 < uStack_3a);
            }
            AEFile::Close(local_38);
            uVar1 = 1;
            goto LAB_0007839a;
          }
        }
      }
    }
LAB_0007838e:
    ImageFontRelease(param_1,param_4);
  }
LAB_00078396:
  uVar1 = 0xffffffff;
LAB_0007839a:
  if (__stack_chk_guard == local_34) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

// ===== AbyssEngine::ImageCreateFromFile  @0x000783c4  (708 bytes)
/* AbyssEngine::ImageCreateFromFile(AbyssEngine::Engine*, char const*, AbyssEngine::Image**) */

void AbyssEngine::ImageCreateFromFile(Engine *param_1,char *param_2,Image **param_3)

{
  undefined4 uVar1;
  Image *pIVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  Image *extraout_r1;
  uint uVar6;
  Image extraout_r2;
  Image IVar7;
  bool bVar8;
  uint local_2c;
  char local_28 [8];
  ushort local_20;
  byte bStack_1d;
  uint local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  uVar1 = 0xfffffffc;
  if ((param_1 == (Engine *)0x0) || (param_2 == (char *)0x0)) goto LAB_000786be;
  pIVar2 = operator_new(0x14);
  *(undefined4 *)(pIVar2 + 0xc) = 0;
  *(undefined4 *)pIVar2 = 0;
  *(undefined4 *)(pIVar2 + 4) = 0;
  pIVar2[8] = (Image)0x0;
  *param_3 = pIVar2;
  local_1c = 0;
  bStack_1d = 0;
  local_20 = 0;
  iVar3 = AEFile::OpenRead(param_2,&local_1c);
  if (iVar3 == 0) {
    if (*param_3 != (Image *)0x0) {
      operator_delete(*param_3);
    }
    *param_3 = (Image *)0x0;
  }
  else {
    builtin_strncpy(local_28 + 4,"***",4);
    builtin_strncpy(local_28,"****",4);
    iVar3 = AEFile::Read(8,local_28,local_1c);
    if (iVar3 == 1) {
      uVar4 = 0;
      do {
        if ("AEimage"[uVar4] != local_28[uVar4]) goto LAB_000786ae;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 8);
      iVar3 = AEFile::Read(1,&bStack_1d,local_1c);
      if ((((iVar3 == 1) && (iVar3 = AEFile::Read(2,*param_3,local_1c), iVar3 == 1)) &&
          (iVar3 = AEFile::Read(2,*param_3 + 2,local_1c), iVar3 == 1)) &&
         (iVar3 = AEFile::Read(2,&local_20,local_1c), iVar3 == 1)) {
        AEFile::Skip((uint)local_20 << 3,local_1c);
        bVar8 = (bStack_1d & 2) != 0;
        IVar7 = extraout_r2;
        pIVar2 = extraout_r1;
        if (bVar8) {
          pIVar2 = *param_3;
          IVar7 = (Image)0x1;
        }
        if (bVar8) {
          pIVar2[8] = IVar7;
        }
        if (bStack_1d < 0x40) {
          switch(bStack_1d) {
          case 1:
          case 3:
            goto switchD_000784b8_caseD_1;
          default:
            goto switchD_000784b8_caseD_2;
          case 0xd:
          case 0xf:
            iVar3 = AEFile::Read(4,&local_2c,local_1c);
            uVar4 = local_2c;
            if (iVar3 != 1) break;
            pvVar5 = operator_new__(local_2c);
            *(void **)(*param_3 + 0xc) = pvVar5;
            iVar3 = AEFile::Read(uVar4,*(void **)(*param_3 + 0xc),local_1c);
            if (iVar3 == 0) break;
            pIVar2 = *param_3;
            *(uint *)(pIVar2 + 0x10) = local_2c;
            uVar4 = 4;
            goto LAB_0007862a;
          case 0x10:
          case 0x12:
            iVar3 = AEFile::Read(4,&local_2c,local_1c);
            uVar4 = local_2c;
            if (iVar3 == 1) {
              pvVar5 = operator_new__(local_2c);
              *(void **)(*param_3 + 0xc) = pvVar5;
              iVar3 = AEFile::Read(uVar4,*(void **)(*param_3 + 0xc),local_1c);
              if (iVar3 != 0) {
                pIVar2 = *param_3;
                *(uint *)(pIVar2 + 0x10) = local_2c;
                uVar4 = 5;
                goto LAB_0007862a;
              }
            }
            break;
          case 0x11:
          case 0x13:
            iVar3 = AEFile::Read(4,*param_3 + 0x10,local_1c);
            if (iVar3 == 1) {
              pIVar2 = *param_3;
              uVar1 = 7;
LAB_0007868c:
              *(undefined4 *)(pIVar2 + 4) = uVar1;
              pvVar5 = operator_new__(*(uint *)(pIVar2 + 0x10));
              *(void **)(pIVar2 + 0xc) = pvVar5;
              iVar3 = AEFile::Read(*(uint *)(*param_3 + 0x10),*(void **)(*param_3 + 0xc),local_1c);
              if (iVar3 != 0) goto switchD_000784b8_caseD_2;
            }
            break;
          case 0x14:
          case 0x16:
          case 0x17:
switchD_000784b8_caseD_14:
            iVar3 = AEFile::Read(4,&local_2c,local_1c);
            uVar4 = local_2c;
            if (iVar3 == 1) {
              pvVar5 = operator_new__(local_2c);
              *(void **)(*param_3 + 0xc) = pvVar5;
              iVar3 = AEFile::Read(uVar4,*(void **)(*param_3 + 0xc),local_1c);
              if (iVar3 == 1) {
                pIVar2 = *param_3;
                *(uint *)(pIVar2 + 0x10) = local_2c;
                *(undefined4 *)(pIVar2 + 4) = 0xb;
                if (bStack_1d == 0x17) {
                  pIVar2[8] = (Image)0x0;
                }
                goto switchD_000784b8_caseD_2;
              }
            }
            break;
          case 0x20:
          case 0x22:
            iVar3 = AEFile::Read(4,*param_3 + 0x10,local_1c);
            if (iVar3 == 1) {
              pIVar2 = *param_3;
              uVar1 = 8;
              goto LAB_0007868c;
            }
            break;
          case 0x21:
          case 0x23:
            iVar3 = AEFile::Read(4,*param_3 + 0x10,local_1c);
            if (iVar3 == 1) {
              pIVar2 = *param_3;
              uVar1 = 9;
              goto LAB_0007868c;
            }
            break;
          case 0x24:
          case 0x26:
            iVar3 = AEFile::Read(4,*param_3 + 0x10,local_1c);
            if (iVar3 == 1) {
              pIVar2 = *param_3;
              uVar1 = 10;
              goto LAB_0007868c;
            }
          }
        }
        else {
          if (bStack_1d != 0x81) {
            if (bStack_1d != 0x42) {
              if (bStack_1d != 0x40) goto switchD_000784b8_caseD_2;
              (*param_3)[8] = (Image)0x0;
            }
            goto switchD_000784b8_caseD_14;
          }
switchD_000784b8_caseD_1:
          pIVar2 = *param_3;
          uVar4 = *(uint *)pIVar2;
          pvVar5 = operator_new__((uVar4 & 0xffff) * 4 * (uVar4 >> 0x10));
          *(void **)(pIVar2 + 0xc) = pvVar5;
          uVar4 = *(uint *)*param_3;
          iVar3 = AEFile::Read((uVar4 >> 0x10) * (uVar4 & 0xffff) * 4,*(void **)(*param_3 + 0xc),
                               local_1c);
          if (iVar3 == 1) {
            pIVar2 = *param_3;
            *(uint *)(pIVar2 + 0x10) = (*(uint *)pIVar2 & 0xffff) * 4 * (*(uint *)pIVar2 >> 0x10);
            uVar6 = (uint)(char)bStack_1d;
            uVar4 = uVar6;
            if (-1 < (int)uVar6) {
              uVar4 = 3;
            }
            if (0x7fffffff < uVar6) {
              uVar4 = 6;
            }
LAB_0007862a:
            *(uint *)(pIVar2 + 4) = uVar4;
switchD_000784b8_caseD_2:
            AEFile::Close(local_1c);
            uVar1 = 1;
            goto LAB_000786be;
          }
        }
      }
    }
LAB_000786ae:
    ImageRelease(param_3);
    AEFile::Close(local_1c);
  }
  uVar1 = 0xffffffff;
LAB_000786be:
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}

// ===== AbyssEngine::TextureCreateFromFile  @0x000786e0  (42 bytes)
/* AbyssEngine::TextureCreateFromFile(AbyssEngine::Engine*, char const*, void
   (*)(AbyssEngine::Image*, void*), void*, unsigned int*, bool, float) */

undefined4
AbyssEngine::TextureCreateFromFile
          (Engine *param_1,char *param_2,_func_void_Image_ptr_void_ptr *param_3,void *param_4,
          uint *param_5,bool param_6,float param_7)

{
  float in_stack_00000008;
  
  TextureCreateFromFileIntern
            (param_1,param_2,param_3,param_4,param_5,in_stack_00000008,
             (AELoadedTexture *)in_stack_00000008,false);
  return 1;
}

// ===== AbyssEngine::TextureCreateFromFileIntern  @0x0007870c  (2108 bytes)
/* WARNING: Removing unreachable block (ram,0x00078972) */
/* AbyssEngine::TextureCreateFromFileIntern(AbyssEngine::Engine*, char const*, void
   (*)(AbyssEngine::Image*, void*), void*, unsigned int*, float, AbyssEngine::AELoadedTexture*,
   bool) */

void AbyssEngine::TextureCreateFromFileIntern
               (Engine *param_1,char *param_2,_func_void_Image_ptr_void_ptr *param_3,void *param_4,
               uint *param_5,float param_6,AELoadedTexture *param_7,bool param_8)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  String *this;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined3 in_stack_00000009;
  int in_stack_0000000c;
  undefined4 uVar12;
  String aSStack_34 [8];
  Image *local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  local_2c = (Image *)0x0;
  *param_5 = 0;
  uVar1 = glGetError();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  iVar2 = ImageCreateFromFile(param_1,param_2,&local_2c);
  if (iVar2 != 1) goto LAB_00078f46;
  if (param_3 != (_func_void_Image_ptr_void_ptr *)0x0) {
    (*param_3)(local_2c,param_4);
  }
  glGenTextures(1,param_5);
  if (*(uint *)(local_2c + 4) == 6) {
    if (Engine::enableShader != '\0') {
      glBindTexture(0x8513,*param_5);
      glTexParameteri(0x8513,0x2800,0x2601);
      glTexParameteri(0x8513,0x2801,0x2601);
      uVar7 = *(uint *)local_2c & 0xffff;
      uVar8 = *(uint *)local_2c / 0x60000;
      glTexImage2D(0x8517,0,0x1908,uVar7,uVar8,0,0x1908,0x1401,*(uint *)(local_2c + 0xc));
      iVar2 = uVar7 * uVar8;
      glTexImage2D(0x8516,0,0x1908,uVar7,uVar8,0,0x1908,0x1401,*(uint *)(local_2c + 0xc) + iVar2 * 4
                  );
      glTexImage2D(0x8519,0,0x1908,uVar7,uVar8,0,0x1908,0x1401,*(uint *)(local_2c + 0xc) + iVar2 * 8
                  );
      glTexImage2D(0x8515,0,0x1908,uVar7,uVar8,0,0x1908,0x1401,
                   *(uint *)(local_2c + 0xc) + iVar2 * 0xc);
      glTexImage2D(0x851a,0,0x1908,uVar7,uVar8,0,0x1908,0x1401,
                   *(uint *)(local_2c + 0xc) + iVar2 * 0x10);
      glTexImage2D(0x8518,0,0x1908,uVar7,uVar8,0,0x1908,0x1401,
                   *(uint *)(local_2c + 0xc) + iVar2 * 0x14);
    }
    goto switchD_000789e8_caseD_6;
  }
  glBindTexture(0xde1,*param_5);
  glPixelStorei(0xcf5,1);
  if (Engine::enableShader == '\0') {
    glTexEnvi(0x2300,0x2200,0x2100);
  }
  if (Engine::clampTextures == '\0') {
    glTexParameteri(0xde1,0x2802,0x2901);
    uVar1 = 0x2901;
  }
  else {
    glTexParameteri(0xde1,0x2802,0x812f);
    uVar1 = 0x812f;
  }
  glTexParameteri(0xde1,0x2803,uVar1);
  if (local_2c[8] == (Image)0x0) {
    if (param_1[0x18] == (Engine)0x0) {
      glTexParameteri(0xde1,0x2800,0x2600);
      uVar1 = 0x2600;
    }
    else {
      glTexParameteri(0xde1,0x2800,0x2601);
      uVar1 = 0x2601;
    }
  }
  else {
    glTexParameterf(0xde1,0x84fe,0x41000000);
    uVar1 = 0x2703;
  }
  glTexParameteri(0xde1,0x2801,uVar1);
  if (Engine::clampTextures != '\0') {
    glTexParameteri(0xde1,0x2800,0x2601);
    glTexParameteri(0xde1,0x2801,0x2601);
  }
  uVar7 = *(uint *)(local_2c + 4);
  switch(uVar7) {
  case 1:
    uVar7 = *(uint *)(local_2c + 0xc);
    uVar11 = *(uint *)local_2c >> 0x10;
    uVar12 = 0x1909;
    uVar8 = *(uint *)local_2c & 0xffff;
    uVar1 = 0x1909;
    goto LAB_00078b38;
  case 2:
    uVar7 = *(uint *)(local_2c + 0xc);
    uVar11 = *(uint *)local_2c >> 0x10;
    uVar12 = 0x1907;
    uVar8 = *(uint *)local_2c & 0xffff;
    uVar1 = 0x1907;
    goto LAB_00078b38;
  case 3:
    uVar7 = *(uint *)(local_2c + 0xc);
    uVar11 = *(uint *)local_2c >> 0x10;
    uVar12 = 0x1908;
    uVar8 = *(uint *)local_2c & 0xffff;
    uVar1 = 0x1908;
LAB_00078b38:
    glTexImage2D(0xde1,0,uVar1,uVar8,uVar11,0,uVar12,0x1401,uVar7);
    if (local_2c[8] != (Image)0x0) {
      glGenerateMipmap(0xde1);
    }
    break;
  case 4:
    uVar5 = *(uint *)(local_2c + 0x10);
    uVar8 = *(uint *)local_2c >> 0x10;
    uVar11 = *(uint *)local_2c & 0xffff;
    if (local_2c[8] == (Image)0x0) {
      uVar7 = *(uint *)(local_2c + 0xc);
      uVar1 = 0x8c03;
LAB_00078dd8:
      glCompressedTexImage2D(0xde1,0,uVar1,uVar11,uVar8,0,uVar5,uVar7);
    }
    else if (uVar5 != 0) {
      uVar7 = 0;
      iVar2 = 0;
      do {
        iVar6 = (int)uVar11 >> 3;
        if (uVar11 < 0x10) {
          iVar6 = 2;
        }
        iVar10 = (uVar8 & 0x7ffffffc) << 1;
        if (uVar8 < 8) {
          iVar10 = 0x10;
        }
        glCompressedTexImage2D
                  (0xde1,iVar2,0x8c03,uVar11,uVar8,0,iVar10 * iVar6,
                   *(uint *)(local_2c + 0xc) + uVar7);
        uVar7 = iVar10 * iVar6 + uVar7;
        uVar9 = (int)uVar8 >> 1;
        uVar5 = (int)uVar11 >> 1;
        uVar8 = 1;
        if (1 < uVar9) {
          uVar8 = uVar9;
        }
        uVar11 = 1;
        if (1 < uVar5) {
          uVar11 = uVar5;
        }
        iVar2 = iVar2 + 1;
      } while (uVar7 < *(uint *)(local_2c + 0x10));
    }
    break;
  case 5:
    uVar5 = *(uint *)(local_2c + 0x10);
    uVar8 = *(uint *)local_2c >> 0x10;
    uVar11 = *(uint *)local_2c & 0xffff;
    if (local_2c[8] == (Image)0x0) {
      uVar7 = *(uint *)(local_2c + 0xc);
      uVar1 = 0x8c02;
      goto LAB_00078dd8;
    }
    if (uVar5 != 0) {
      iVar2 = 0;
      uVar7 = 0;
      do {
        iVar6 = (int)uVar8 >> 2;
        if (uVar8 < 8) {
          iVar6 = 2;
        }
        iVar10 = (uVar11 & 0x7ffffffc) << 1;
        if (uVar11 < 8) {
          iVar10 = 0x10;
        }
        glCompressedTexImage2D
                  (0xde1,iVar2,0x8c02,uVar11,uVar8,0,iVar10 * iVar6,
                   *(uint *)(local_2c + 0xc) + uVar7);
        uVar7 = iVar10 * iVar6 + uVar7;
        uVar9 = (int)uVar8 >> 1;
        uVar5 = (int)uVar11 >> 1;
        uVar8 = 1;
        if (1 < uVar9) {
          uVar8 = uVar9;
        }
        uVar11 = 1;
        if (1 < uVar5) {
          uVar11 = uVar5;
        }
        iVar2 = iVar2 + 1;
      } while (uVar7 < *(uint *)(local_2c + 0x10));
    }
    break;
  case 7:
    uVar5 = *(uint *)(local_2c + 0x10);
    uVar8 = *(uint *)local_2c >> 0x10;
    uVar11 = *(uint *)local_2c & 0xffff;
    if (local_2c[8] == (Image)0x0) {
      uVar7 = *(uint *)(local_2c + 0xc);
      uVar1 = 0x8c93;
      goto LAB_00078dd8;
    }
    if (uVar5 != 0) {
      iVar2 = 0;
      uVar7 = 0;
      do {
        iVar6 = uVar8 * uVar11;
        if (iVar6 < 0x11) {
          iVar6 = 0x10;
        }
        glCompressedTexImage2D
                  (0xde1,iVar2,0x8c93,uVar11,uVar8,0,iVar6,*(uint *)(local_2c + 0xc) + uVar7);
        uVar5 = (int)uVar8 >> 1;
        uVar9 = (int)uVar11 >> 1;
        uVar8 = 1;
        if (1 < uVar5) {
          uVar8 = uVar5;
        }
        uVar11 = 1;
        if (1 < uVar9) {
          uVar11 = uVar9;
        }
        uVar7 = uVar7 + iVar6;
        iVar2 = iVar2 + 1;
      } while (uVar7 < *(uint *)(local_2c + 0x10));
    }
    break;
  case 8:
  case 9:
  case 10:
    uVar1 = 0x83f0;
    if (uVar7 == 9) {
      uVar1 = 0x83f2;
    }
    uVar5 = *(uint *)(local_2c + 0x10);
    if (uVar7 == 10) {
      uVar1 = 0x83f3;
    }
    uVar8 = *(uint *)local_2c >> 0x10;
    uVar11 = *(uint *)local_2c & 0xffff;
    if (local_2c[8] == (Image)0x0) {
      uVar7 = *(uint *)(local_2c + 0xc);
      goto LAB_00078dd8;
    }
    if (uVar5 != 0) {
      iVar2 = 0;
      uVar5 = 0;
      while( true ) {
        uVar9 = uVar8 * uVar11;
        if (uVar7 - 9 < 2) {
          if ((int)uVar9 < 0x10) {
            uVar9 = 0x10;
          }
        }
        else if ((int)uVar9 < 0x10) {
          uVar9 = uVar7;
          if (uVar7 != 8) {
            uVar9 = 0x10;
          }
        }
        else {
          uVar9 = (int)uVar9 / 2;
        }
        glCompressedTexImage2D
                  (0xde1,iVar2,uVar1,uVar11,uVar8,0,uVar9,*(uint *)(local_2c + 0xc) + uVar5);
        uVar5 = uVar5 + uVar9;
        if (*(uint *)(local_2c + 0x10) <= uVar5) break;
        uVar11 = (int)uVar11 >> 1;
        uVar8 = (int)uVar8 >> 1;
        if (uVar11 < 2) {
          uVar11 = 1;
        }
        if (uVar8 < 2) {
          uVar8 = 1;
        }
        uVar7 = *(uint *)(local_2c + 4);
        iVar2 = iVar2 + 1;
      }
    }
    break;
  case 0xb:
    uVar5 = *(uint *)(local_2c + 0x10);
    uVar8 = *(uint *)local_2c >> 0x10;
    uVar11 = *(uint *)local_2c & 0xffff;
    if (local_2c[8] == (Image)0x0) {
      uVar7 = *(uint *)(local_2c + 0xc);
      uVar1 = 0x8d64;
      goto LAB_00078dd8;
    }
    if (uVar5 != 0) {
      iVar2 = 0;
      uVar7 = 0;
      do {
        iVar6 = (int)(uVar8 * uVar11) / 2;
        if (uVar11 < 8) {
          iVar6 = 8;
        }
        glCompressedTexImage2D
                  (0xde1,iVar2,0x8d64,uVar11,uVar8,0,iVar6,*(uint *)(local_2c + 0xc) + uVar7);
        uVar5 = (int)uVar8 >> 1;
        uVar9 = (int)uVar11 >> 1;
        uVar8 = 1;
        if (1 < uVar5) {
          uVar8 = uVar5;
        }
        uVar11 = 1;
        if (1 < uVar9) {
          uVar11 = uVar9;
        }
        uVar7 = uVar7 + iVar6;
        iVar2 = iVar2 + 1;
      } while (uVar7 < *(uint *)(local_2c + 0x10));
    }
  }
switchD_000789e8_caseD_6:
  if (in_stack_0000000c == 1) {
    if (_param_8 == (uint *)0x0) {
      puVar3 = operator_new(0x18);
      this = (String *)String::String((String *)(puVar3 + 1));
      uVar7 = 0;
      *(bool *)(puVar3 + 4) = *(uint *)(local_2c + 4) == 6;
      puVar3[3] = (uint)param_7;
      *(undefined1 *)((int)puVar3 + 0x11) = 1;
      String::Set(this,param_2);
      iVar2 = glGetError();
      if (iVar2 == 0) {
        AELabelObject(0x1702,*param_5,param_2);
        *puVar3 = *param_5;
        uVar7 = *(uint *)(local_2c + 0x10);
        puVar3[5] = uVar7;
        Engine::ImageCount = Engine::ImageCount + 1;
      }
      else {
        glDeleteTextures(1,param_5);
        *puVar3 = 0xffffffff;
        puVar3[5] = 0;
      }
      *(uint *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + uVar7;
      iVar6 = **(int **)(param_1 + 0x28);
      iVar2 = *(int *)(iVar6 + 0x10) + 1;
      *(int *)(iVar6 + 0x18) = iVar2;
      pvVar4 = realloc(*(void **)(iVar6 + 0x14),iVar2 * 4);
      *(void **)(iVar6 + 0x14) = pvVar4;
      *(uint **)((int)pvVar4 + *(int *)(iVar6 + 0x10) * 4) = puVar3;
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar6 + 0x18);
      *param_5 = *(int *)(**(int **)(param_1 + 0x28) + 0x10) - 1;
    }
    else {
      *(bool *)(_param_8 + 4) = *(uint *)(local_2c + 4) == 6;
      *(undefined1 *)((int)_param_8 + 0x11) = 1;
      iVar2 = glGetError();
      if (iVar2 == 0) {
        AELabelObject(0x1702,*param_5,param_2);
        *_param_8 = *param_5;
        uVar7 = *(uint *)(local_2c + 0x10);
        _param_8[5] = uVar7;
        Engine::ImageCount = Engine::ImageCount + 1;
      }
      else {
        _param_8[5] = 0;
        *_param_8 = 0xffffffff;
        glDeleteTextures(1,param_5);
        uVar7 = _param_8[5];
      }
      *(uint *)(param_1 + 0x60) = uVar7 + *(int *)(param_1 + 0x60);
    }
  }
  else {
    iVar2 = glGetError();
    *(int *)(param_1 + 0xc) = iVar2;
    if (iVar2 != 0) {
      String::String(aSStack_34,param_2,false);
      String::operator=((String *)(param_1 + 0x10),aSStack_34);
      String::~String(aSStack_34);
      glDeleteTextures(1,param_5);
      ImageRelease(&local_2c);
      iVar2 = -4;
      goto LAB_00078f46;
    }
    AELabelObject(0x1702,*param_5,param_2);
  }
  ImageRelease(&local_2c);
  iVar2 = 1;
LAB_00078f46:
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}

// ===== AbyssEngine::GenerateCompressedTexture  @0x00078f9c  (4 bytes)
/* AbyssEngine::GenerateCompressedTexture(AbyssEngine::Image*) */

undefined4 AbyssEngine::GenerateCompressedTexture(Image *param_1)

{
  return 1;
}

// ===== AbyssEngine::CameraSetPerspective  @0x0007a594  (166 bytes)
/* AbyssEngine::CameraSetPerspective(float, float, float, float, float, AbyssEngine::Camera*) */

float AbyssEngine::CameraSetPerspective
                (float param_1,float param_2,float param_3,float param_4,float param_5,
                Camera *param_6)

{
  float fVar1;
  float fVar2;
  undefined4 in_r1;
  float in_r2;
  float in_r3;
  float extraout_s0;
  float in_stack_00000000;
  undefined4 *in_stack_00000004;
  
  if (in_stack_00000004 != (undefined4 *)0x0) {
    *in_stack_00000004 = param_6;
    in_stack_00000004[1] = in_r1;
    in_stack_00000004[2] = in_r2;
    fVar1 = (float)AEMath::Sinf(in_r2);
    fVar2 = (float)AEMath::Cosf(extraout_s0);
    fVar1 = fVar1 / fVar2;
    in_stack_00000004[0x12] = fVar1;
    in_stack_00000004[0x13] = (in_r3 / in_stack_00000000) * fVar1;
    in_stack_00000004[0x14] = in_r3 / in_stack_00000000;
    fVar1 = (float)AEMath::Cosf(fVar1);
    in_stack_00000004[0x16] = 1.0 / fVar1;
    fVar1 = (float)AEMath::ATanf((float)in_stack_00000004[0x12] * (float)in_stack_00000004[0x14]);
    fVar1 = (float)AEMath::Cosf(fVar1);
    param_1 = 1.0 / fVar1;
    in_stack_00000004[0x15] = param_1;
  }
  return param_1;
}

// ===== AbyssEngine::CameraSetPerspective  @0x0007a63a  (140 bytes)
/* AbyssEngine::CameraSetPerspective(float, float, float, float, AbyssEngine::Camera*) */

float AbyssEngine::CameraSetPerspective
                (float param_1,float param_2,float param_3,float param_4,Camera *param_5)

{
  float fVar1;
  float fVar2;
  float in_r1;
  float in_r2;
  float in_r3;
  float *in_stack_00000000;
  
  if (in_stack_00000000 != (float *)0x0) {
    in_stack_00000000[1] = (float)param_5;
    in_stack_00000000[2] = in_r1;
    fVar1 = (float)AEMath::Sinf(*in_stack_00000000 * 0.5);
    fVar2 = (float)AEMath::Cosf(*in_stack_00000000 * 0.5);
    fVar1 = fVar1 / fVar2;
    in_stack_00000000[0x12] = fVar1;
    in_stack_00000000[0x13] = (in_r2 / in_r3) * fVar1;
    in_stack_00000000[0x14] = in_r2 / in_r3;
    fVar1 = (float)AEMath::ATanf(fVar1);
    fVar1 = (float)AEMath::Cosf(fVar1);
    param_1 = 1.0 / fVar1;
    in_stack_00000000[0x15] = param_1;
  }
  return param_1;
}

// ===== AbyssEngine::CameraIsPointinViewFrustum  @0x0007a6c8  (394 bytes)
/* AbyssEngine::CameraIsPointinViewFrustum(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Matrix*, AbyssEngine::Camera*) */

void AbyssEngine::CameraIsPointinViewFrustum(Vector *param_1,Matrix *param_2,Camera *param_3)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  AEMath *this;
  Camera *pCVar4;
  float fVar5;
  AEMath aAStack_ac [12];
  AEMath aAStack_a0 [12];
  AEMath aAStack_94 [12];
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (Engine::vfc == '\0') {
    bVar1 = true;
  }
  else {
    pCVar4 = param_3 + 0xc;
    local_48 = 0;
    uStack_44 = 0;
    local_40 = 0;
    if (param_2 == (Matrix *)0x0) {
      this = (AEMath *)&local_88;
      AEMath::MatrixInverseTransformVector(this,pCVar4,param_1);
    }
    else {
      local_88 = *(undefined4 *)pCVar4;
      uStack_84 = *(undefined4 *)(param_3 + 0x10);
      uStack_80 = *(undefined4 *)(param_3 + 0x14);
      uStack_7c = *(undefined4 *)(param_3 + 0x18);
      uStack_78 = *(undefined4 *)(param_3 + 0x1c);
      local_74 = *(undefined4 *)(param_3 + 0x20);
      uStack_70 = *(undefined4 *)(param_3 + 0x24);
      uStack_6c = *(undefined4 *)(param_3 + 0x28);
      uStack_68 = *(undefined4 *)(param_3 + 0x2c);
      uStack_64 = *(undefined4 *)(param_3 + 0x30);
      local_60 = *(undefined4 *)(param_3 + 0x34);
      uStack_5c = *(undefined4 *)(param_3 + 0x38);
      uStack_58 = *(undefined4 *)(param_3 + 0x3c);
      uStack_54 = *(undefined4 *)(param_3 + 0x40);
      uStack_50 = *(undefined4 *)(param_3 + 0x44);
      AEMath::Matrix::operator*=((Matrix *)&local_88,param_2);
      this = aAStack_94;
      AEMath::MatrixInverseTransformVector(this,(Matrix *)&local_88,param_1);
    }
    AEMath::Vector::operator=((Vector *)&local_48,(Vector *)this);
    AEMath::MatrixGetPosition(aAStack_94,pCVar4);
    AEMath::operator-((AEMath *)&local_88,param_1,(Vector *)aAStack_94);
    AEMath::MatrixGetDir(aAStack_ac,pCVar4);
    AEMath::operator-(aAStack_a0,(Vector *)aAStack_ac);
    AEMath::VectorNormalize(aAStack_94,(Vector *)aAStack_a0);
    fVar2 = (float)AEMath::VectorDot((Vector *)&local_88,(Vector *)aAStack_94);
    if ((*(float *)(param_3 + 8) < fVar2) ||
       ((int)((uint)(fVar2 < *(float *)(param_3 + 4)) << 0x1f) < 0)) {
      bVar1 = false;
    }
    else {
      AEMath::MatrixGetUp(aAStack_a0,pCVar4);
      AEMath::VectorNormalize(aAStack_94,(Vector *)aAStack_a0);
      fVar3 = (float)AEMath::VectorDot((Vector *)&local_88,(Vector *)aAStack_94);
      bVar1 = false;
      fVar5 = fVar2 * *(float *)(param_3 + 0x48);
      if ((fVar3 <= fVar5) &&
         (-1 < (int)((uint)(fVar3 < -(fVar2 * *(float *)(param_3 + 0x48))) << 0x1f))) {
        AEMath::MatrixGetRight(aAStack_a0,pCVar4);
        AEMath::VectorNormalize(aAStack_94,(Vector *)aAStack_a0);
        fVar2 = (float)AEMath::VectorDot((Vector *)&local_88,(Vector *)aAStack_94);
        bVar1 = -1 < (int)((uint)(fVar2 < -(fVar5 * *(float *)(param_3 + 0x50))) << 0x1f) &&
                fVar2 <= fVar5 * *(float *)(param_3 + 0x50);
      }
    }
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}

// ===== AbyssEngine::CameraIsSphereinViewFrustum  @0x0007a860  (456 bytes)
/* AbyssEngine::CameraIsSphereinViewFrustum(AbyssEngine::AEMath::Vector const&, float,
   AbyssEngine::AEMath::Matrix*, AbyssEngine::Camera*) */

void AbyssEngine::CameraIsSphereinViewFrustum
               (Vector *param_1,float param_2,Matrix *param_3,Camera *param_4)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  AEMath *this;
  int in_r3;
  undefined4 *puVar4;
  float fVar5;
  AEMath aAStack_ac [12];
  AEMath aAStack_a0 [12];
  AEMath aAStack_94 [12];
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  uVar1 = 1;
  if (((float)param_3 != 0.0) && (Engine::vfc != '\0')) {
    puVar4 = (undefined4 *)(in_r3 + 0xc);
    local_48 = 0;
    uStack_44 = 0;
    local_40 = 0;
    if (param_4 == (Camera *)0x0) {
      this = (AEMath *)&local_88;
      AEMath::MatrixInverseTransformVector(this,(Matrix *)puVar4,param_1);
    }
    else {
      local_88 = *puVar4;
      uStack_84 = *(undefined4 *)(in_r3 + 0x10);
      uStack_80 = *(undefined4 *)(in_r3 + 0x14);
      uStack_7c = *(undefined4 *)(in_r3 + 0x18);
      uStack_78 = *(undefined4 *)(in_r3 + 0x1c);
      local_74 = *(undefined4 *)(in_r3 + 0x20);
      uStack_70 = *(undefined4 *)(in_r3 + 0x24);
      uStack_6c = *(undefined4 *)(in_r3 + 0x28);
      uStack_68 = *(undefined4 *)(in_r3 + 0x2c);
      uStack_64 = *(undefined4 *)(in_r3 + 0x30);
      local_60 = *(undefined4 *)(in_r3 + 0x34);
      uStack_5c = *(undefined4 *)(in_r3 + 0x38);
      uStack_58 = *(undefined4 *)(in_r3 + 0x3c);
      uStack_54 = *(undefined4 *)(in_r3 + 0x40);
      uStack_50 = *(undefined4 *)(in_r3 + 0x44);
      AEMath::Matrix::operator*=((Matrix *)&local_88,param_4);
      this = aAStack_94;
      AEMath::MatrixInverseTransformVector(this,(Matrix *)&local_88,param_1);
    }
    AEMath::Vector::operator=((Vector *)&local_48,(Vector *)this);
    AEMath::MatrixGetPosition(aAStack_94,(Matrix *)puVar4);
    AEMath::operator-((AEMath *)&local_88,param_1,(Vector *)aAStack_94);
    AEMath::MatrixGetDir(aAStack_ac,(Matrix *)puVar4);
    AEMath::operator-(aAStack_a0,(Vector *)aAStack_ac);
    AEMath::VectorNormalize(aAStack_94,(Vector *)aAStack_a0);
    fVar2 = (float)AEMath::VectorDot((Vector *)&local_88,(Vector *)aAStack_94);
    param_2 = *(float *)(in_r3 + 8) + (float)param_3;
    if ((fVar2 <= param_2) &&
       (param_2 = *(float *)(in_r3 + 4) - (float)param_3,
       -1 < (int)((uint)(fVar2 < param_2) << 0x1f))) {
      AEMath::MatrixGetRight(aAStack_a0,(Matrix *)puVar4);
      AEMath::VectorNormalize(aAStack_94,(Vector *)aAStack_a0);
      fVar3 = (float)AEMath::VectorDot((Vector *)&local_88,(Vector *)aAStack_94);
      param_2 = *(float *)(in_r3 + 0x54) * (float)param_3;
      fVar5 = fVar2 * *(float *)(in_r3 + 0x48) * *(float *)(in_r3 + 0x50);
      if ((fVar3 <= fVar5 + param_2) &&
         (param_2 = -fVar5 - param_2, -1 < (int)((uint)(fVar3 < param_2) << 0x1f))) {
        AEMath::MatrixGetUp(aAStack_a0,(Matrix *)puVar4);
        AEMath::VectorNormalize(aAStack_94,(Vector *)aAStack_a0);
        fVar3 = (float)AEMath::VectorDot((Vector *)&local_88,(Vector *)aAStack_94);
        param_2 = *(float *)(in_r3 + 0x58) * (float)param_3;
        fVar2 = fVar2 * *(float *)(in_r3 + 0x48);
        if ((fVar3 <= fVar2 + param_2) &&
           (param_2 = -fVar2 - param_2, -1 < (int)((uint)(fVar3 < param_2) << 0x1f))) {
          uVar1 = 1;
          goto LAB_0007aa06;
        }
      }
    }
    uVar1 = 0;
  }
LAB_0007aa06:
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2,uVar1);
  }
  return;
}

// ===== AbyssEngine::Image2DRelease  @0x0007ae6a  (28 bytes)
/* AbyssEngine::Image2DRelease(AbyssEngine::Engine*, AbyssEngine::Image2D**) */

void AbyssEngine::Image2DRelease(Engine *param_1,Image2D **param_2)

{
  if (*param_2 != (Image2D *)0x0) {
    MeshRelease(param_1,(Mesh **)*param_2);
    if (*param_2 != (Image2D *)0x0) {
      operator_delete(*param_2);
    }
    *param_2 = (Image2D *)0x0;
  }
  return;
}

// ===== AbyssEngine::ImageFontDrawString  @0x0007ae86  (54 bytes)
/* AbyssEngine::ImageFontDrawString(AbyssEngine::ImageFont*, unsigned short const*, int, int,
   AbyssEngine::PaintCanvas*, AbyssEngine::Engine*, bool) */

void AbyssEngine::ImageFontDrawString
               (ImageFont *param_1,ushort *param_2,int param_3,int param_4,PaintCanvas *param_5,
               Engine *param_6,bool param_7)

{
  uint uVar1;
  ushort uVar2;
  
  if ((param_1 != (ImageFont *)0x0) && (param_2 != (ushort *)0x0)) {
    uVar2 = 0;
    do {
      uVar1 = (uint)uVar2;
      uVar2 = uVar2 + 1;
    } while (param_2[uVar1] != 0);
    ImageFontDrawString(param_1,param_2,uVar1,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  return;
}

// ===== AbyssEngine::ImageFontDrawString  @0x0007aec0  (1492 bytes)
/* AbyssEngine::ImageFontDrawString(AbyssEngine::ImageFont*, unsigned short const*, unsigned int,
   int, int, AbyssEngine::PaintCanvas*, AbyssEngine::Engine*, bool) */

void AbyssEngine::ImageFontDrawString
               (ImageFont *param_1,ushort *param_2,uint param_3,int param_4,int param_5,
               PaintCanvas *param_6,Engine *param_7,bool param_8)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  undefined4 *puVar10;
  PaintCanvas PVar11;
  ushort uVar12;
  int iVar13;
  float *pfVar14;
  ushort uVar15;
  int iVar16;
  uint in_fpscr;
  int iVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined3 in_stack_0000000d;
  undefined4 local_90 [3];
  undefined4 local_84;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  int local_54;
  
  local_54 = __stack_chk_guard;
  bVar1 = param_2 != (ushort *)0x0 && param_1 != (ImageFont *)0x0;
  if (param_7[0xec] == (Engine)0x0) {
    if (bVar1) {
      iVar3 = ImageFontGetWidth(param_1,param_2,param_3);
      iVar17 = (int)*(float *)(*(int *)(**(int **)(param_1 + 0xc) + 4) + 0x1c);
      if (-1 < iVar3 + param_4) {
        iVar3 = *(short *)(param_1 + 0x12) + param_5;
        if (iVar17 == 0x18) {
          iVar17 = 0x13;
        }
        iVar4 = Engine::GetDisplayWidth(param_7);
        if (((-1 < iVar3 + iVar17) && (param_4 <= iVar4)) &&
           (iVar17 = Engine::GetDisplayHeight(param_7), iVar3 <= iVar17)) {
          local_84 = VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
          uVar20 = VectorSignedToFloat(iVar3 + -2,(byte)(in_fpscr >> 0x16) & 3);
          puVar6 = (undefined4 *)((uint)local_90 | 4);
          uStack_70 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
          uStack_6c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
          iVar3 = -1;
          *puVar6 = 0;
          puVar6[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
          puVar6[2] = uStack_70;
          puVar6[3] = uStack_6c;
          local_78 = 0;
          local_58 = 0x3f800000;
          local_90[0] = 0x3f800000;
          local_7c = 0x3f800000;
          local_68 = 0x3f800000;
          uStack_60 = 0x3f8000003f800000;
          PVar11 = param_6[0x1c];
          if (_param_8 != 0) {
            PVar11 = (PaintCanvas)0x1;
          }
          if (PVar11 != (PaintCanvas)0x0) {
            iVar3 = 1;
          }
          uStack_74 = uVar20;
          if (param_3 != 0) {
            iVar17 = param_3 - 1;
            if (PVar11 != (PaintCanvas)0x0) {
              iVar17 = 0;
            }
            uVar15 = 0;
            do {
              if (*(ushort *)param_1 != 0) {
                iVar4 = 0;
                uVar12 = 0;
                do {
                  if (*(ushort *)(*(int *)(param_1 + 4) + iVar4) == param_2[iVar17]) {
                    local_84 = VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
                    iVar5 = (int)*(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar4 * 2) +
                                                    4) + 0xc);
                    uStack_74 = uVar20;
                    if ((-1 < iVar5 + param_4) &&
                       (iVar7 = Engine::GetDisplayWidth(param_7), param_4 <= iVar7)) {
                      PaintCanvas::SetWorldViewMatrix(param_6);
                      MeshDraw(param_7,*(Mesh **)(*(int *)(param_1 + 0xc) + iVar4 * 2));
                    }
                    iVar7 = *(short *)(param_1 + 0x10) + iVar5;
                    iVar4 = iVar7;
                    if (param_2[iVar17] == 0x20) {
                      iVar4 = iVar7 + -2;
                    }
                    if (iVar5 != 0xb) {
                      iVar4 = iVar7;
                    }
                    param_4 = param_4 + iVar4;
                    break;
                  }
                  uVar12 = uVar12 + 1;
                  iVar4 = iVar4 + 2;
                } while (uVar12 < *(ushort *)param_1);
              }
              uVar15 = uVar15 + 1;
              iVar17 = iVar17 + iVar3;
            } while (uVar15 < param_3);
          }
        }
      }
    }
  }
  else if (bVar1) {
    iVar3 = ImageFontGetWidth(param_1,param_2,param_3);
    iVar17 = (int)*(float *)(*(int *)(**(int **)(param_1 + 0xc) + 4) + 0x1c);
    if (-1 < iVar3 + param_4) {
      iVar3 = param_5 + *(short *)(param_1 + 0x12);
      if (iVar17 == 0x18) {
        iVar17 = 0x13;
      }
      iVar4 = Engine::GetDisplayWidth(param_7);
      if (((-1 < iVar3 + iVar17) && (param_4 <= iVar4)) &&
         (iVar17 = Engine::GetDisplayHeight(param_7), iVar3 <= iVar17)) {
        PVar11 = param_6[0x1c];
        iVar17 = -1;
        if (_param_8 != 0) {
          PVar11 = (PaintCanvas)0x1;
        }
        iVar4 = param_3 - 1;
        if (PVar11 != (PaintCanvas)0x0) {
          iVar17 = 1;
          iVar4 = 0;
        }
        if (((Engine::enableReverseFlag != '\0') && (sVar2 = GameText::getLanguage(), sVar2 == 9))
           && (iVar5 = GameText::isNonArabicString(param_2,param_3), iVar5 != 0)) {
          iVar4 = 0;
          iVar17 = 1;
        }
        if (param_3 != 0) {
          uVar20 = 0;
          uVar21 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
          uVar22 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
          uVar23 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
          uVar15 = 0;
          fVar19 = (float)VectorSignedToFloat(iVar3 + -2,(byte)(in_fpscr >> 0x16) & 3);
          puVar6 = (undefined4 *)((uint)local_90 | 4);
          do {
            if (*(ushort *)param_1 != 0) {
              iVar3 = 0;
              uVar12 = 0;
              do {
                if (*(ushort *)(*(int *)(param_1 + 4) + iVar3) == param_2[iVar4]) {
                  iVar5 = (int)*(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar3 * 2) + 4
                                                  ) + 0xc);
                  if ((-1 < iVar5 + param_4) &&
                     (iVar7 = Engine::GetDisplayWidth(param_7), param_4 <= iVar7)) {
                    iVar8 = *(int *)(param_6 + 8);
                    iVar7 = *(int *)(param_6 + 0xc);
                    iVar13 = *(int *)(iVar8 + 4);
                    iVar16 = *(int *)(*(int *)(param_1 + 0xc) + iVar3 * 2);
                    fVar18 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
                    pfVar9 = (float *)(iVar13 + iVar7 * 0x30);
                    pfVar14 = *(float **)(iVar16 + 4);
                    *pfVar9 = fVar18 + *pfVar14;
                    *(float *)(iVar13 + (iVar7 * 0xc | 1U) * 4) = fVar19 + pfVar14[1];
                    *(float *)(iVar13 + (iVar7 * 0xc | 3U) * 4) = fVar18 + pfVar14[3];
                    pfVar9[4] = fVar19 + pfVar14[4];
                    pfVar9[6] = fVar18 + pfVar14[6];
                    pfVar9[7] = fVar19 + pfVar14[7];
                    pfVar9[9] = fVar18 + pfVar14[9];
                    pfVar9[10] = fVar19 + pfVar14[10];
                    puVar10 = *(undefined4 **)(iVar16 + 8);
                    iVar8 = *(int *)(iVar8 + 8);
                    *(undefined4 *)(iVar8 + iVar7 * 0x20) = *puVar10;
                    *(undefined4 *)(iVar8 + (iVar7 << 5 | 4U)) = puVar10[1];
                    *(undefined4 *)(iVar8 + (iVar7 << 5 | 8U)) = puVar10[2];
                    *(undefined4 *)(iVar8 + (iVar7 << 5 | 0xcU)) = puVar10[3];
                    *(undefined4 *)(iVar8 + (iVar7 << 5 | 0x10U)) = puVar10[4];
                    iVar8 = *(int *)(param_6 + 8);
                    iVar7 = *(int *)(param_6 + 0xc);
                    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar3 * 2) + 8);
                    iVar13 = *(int *)(iVar8 + 8);
                    *(undefined4 *)(iVar13 + (iVar7 << 5 | 0x14U)) = *(undefined4 *)(iVar3 + 0x14);
                    *(undefined4 *)(iVar13 + (iVar7 << 5 | 0x18U)) = *(undefined4 *)(iVar3 + 0x18);
                    *(undefined4 *)(iVar13 + (iVar7 << 5 | 0x1cU)) = *(undefined4 *)(iVar3 + 0x1c);
                    iVar3 = *(int *)(iVar8 + 0xc);
                    *(undefined4 *)(iVar3 + iVar7 * 0x40) = *(undefined4 *)(param_7 + 0xc0);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 4U)) = *(undefined4 *)(param_7 + 0xc4);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 8U)) = *(undefined4 *)(param_7 + 200);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0xcU)) = *(undefined4 *)(param_7 + 0xcc);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x10U)) = *(undefined4 *)(param_7 + 0xc0);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x14U)) = *(undefined4 *)(param_7 + 0xc4);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x18U)) = *(undefined4 *)(param_7 + 200);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x1cU)) = *(undefined4 *)(param_7 + 0xcc);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x20U)) = *(undefined4 *)(param_7 + 0xc0);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x24U)) = *(undefined4 *)(param_7 + 0xc4);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x28U)) = *(undefined4 *)(param_7 + 200);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x2cU)) = *(undefined4 *)(param_7 + 0xcc);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x30U)) = *(undefined4 *)(param_7 + 0xc0);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x34U)) = *(undefined4 *)(param_7 + 0xc4);
                    *(undefined4 *)(iVar3 + (iVar7 << 6 | 0x38U)) = *(undefined4 *)(param_7 + 200);
                    iVar3 = *(int *)(param_6 + 8);
                    iVar7 = *(int *)(param_6 + 0xc);
                    *(undefined4 *)(*(int *)(iVar3 + 0xc) + (iVar7 << 6 | 0x3cU)) =
                         *(undefined4 *)(param_7 + 0xcc);
                    *(int *)(param_6 + 0xc) = iVar7 + 1;
                    if (0x62 < iVar7) {
                      *(short *)(iVar3 + 0x28) = (short)(iVar7 + 1) * 6;
                      local_90[0] = 0x3f800000;
                      *puVar6 = uVar20;
                      puVar6[1] = uVar21;
                      puVar6[2] = uVar22;
                      puVar6[3] = uVar23;
                      local_7c = 0x3f800000;
                      local_68 = 0x3f800000;
                      uStack_60 = 0x3f8000003f800000;
                      local_58 = 0x3f800000;
                      local_78 = uVar20;
                      uStack_74 = uVar21;
                      uStack_70 = uVar22;
                      uStack_6c = uVar23;
                      PaintCanvas::SetWorldViewMatrix(param_6);
                      MeshDraw(param_7,*(Mesh **)(param_6 + 8));
                      *(undefined4 *)(param_6 + 0xc) = 0;
                    }
                  }
                  iVar7 = *(short *)(param_1 + 0x10) + iVar5;
                  iVar3 = iVar7;
                  if (param_2[iVar4] == 0x20) {
                    iVar3 = iVar7 + -2;
                  }
                  if (iVar5 != 0xb) {
                    iVar3 = iVar7;
                  }
                  param_4 = param_4 + iVar3;
                  break;
                }
                uVar12 = uVar12 + 1;
                iVar3 = iVar3 + 2;
              } while (uVar12 < *(ushort *)param_1);
            }
            uVar15 = uVar15 + 1;
            iVar4 = iVar4 + iVar17;
          } while (uVar15 < param_3);
        }
        iVar3 = *(int *)(param_6 + 0xc);
        if (0 < iVar3) {
          uStack_74 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
          uStack_70 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
          uStack_6c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
          *(short *)(*(int *)(param_6 + 8) + 0x28) = ((short)iVar3 + (short)(iVar3 << 1)) * 2;
          puVar6 = (undefined4 *)((uint)local_90 | 4);
          local_90[0] = 0x3f800000;
          *puVar6 = 0;
          puVar6[1] = uStack_74;
          puVar6[2] = uStack_70;
          puVar6[3] = uStack_6c;
          local_7c = 0x3f800000;
          local_78 = 0;
          local_68 = 0x3f800000;
          uStack_60 = 0x3f8000003f800000;
          local_58 = 0x3f800000;
          PaintCanvas::SetWorldViewMatrix(param_6);
          MeshDraw(param_7,*(Mesh **)(param_6 + 8));
          *(undefined4 *)(param_6 + 0xc) = 0;
        }
      }
    }
  }
  if (__stack_chk_guard == local_54) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::ImageFontCheckString  @0x0007b4c0  (60 bytes)
/* AbyssEngine::ImageFontCheckString(AbyssEngine::ImageFont*, unsigned short const*, unsigned int)
    */

void AbyssEngine::ImageFontCheckString(ImageFont *param_1,ushort *param_2,uint param_3)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  
  if (param_3 != 0) {
    uVar1 = 0;
    uVar3 = 0;
    do {
      if (*(ushort *)param_1 != 0) {
        uVar2 = 0;
        do {
          if (*(ushort *)(*(int *)(param_1 + 4) + (uint)uVar2 * 2) == param_2[uVar1]) break;
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(ushort *)param_1);
      }
      uVar3 = uVar3 + 1;
      uVar1 = (uint)uVar3;
    } while (uVar1 < param_3);
  }
  return;
}

// ===== AbyssEngine::ImageFontGetWidth  @0x0007b4fc  (130 bytes)
/* AbyssEngine::ImageFontGetWidth(AbyssEngine::ImageFont*, unsigned short const*, unsigned int) */

int AbyssEngine::ImageFontGetWidth(ImageFont *param_1,ushort *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  
  iVar1 = 0;
  if ((param_1 != (ImageFont *)0x0 && param_2 != (ushort *)0x0) && (param_3 != 0)) {
    uVar3 = 0;
    uVar6 = 0;
    iVar1 = 0;
    do {
      if (*(ushort *)param_1 != 0) {
        iVar4 = 0;
        uVar5 = 0;
        do {
          if (*(ushort *)(*(int *)(param_1 + 4) + iVar4) == param_2[uVar3]) {
            iVar7 = (int)*(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar4 * 2) + 4) +
                                   0xc);
            iVar2 = *(short *)(param_1 + 0x10) + iVar7;
            iVar4 = iVar2;
            if (iVar7 == 0xb) {
              iVar4 = iVar2 + -2;
            }
            if (param_2[uVar3] != 0x20) {
              iVar4 = iVar2;
            }
            iVar1 = iVar1 + iVar4;
            break;
          }
          uVar5 = uVar5 + 1;
          iVar4 = iVar4 + 2;
        } while (uVar5 < *(ushort *)param_1);
      }
      uVar6 = uVar6 + 1;
      uVar3 = (uint)uVar6;
    } while (uVar3 < param_3);
  }
  return iVar1;
}

// ===== AbyssEngine::ImageFontGetHeight  @0x0007b57e  (32 bytes)
/* AbyssEngine::ImageFontGetHeight(AbyssEngine::ImageFont*) */

int AbyssEngine::ImageFontGetHeight(ImageFont *param_1)

{
  int iVar1;
  
  if (param_1 != (ImageFont *)0x0) {
    iVar1 = (int)*(float *)(*(int *)(**(int **)(param_1 + 0xc) + 4) + 0x1c);
    if (iVar1 == 0x18) {
      iVar1 = 0x13;
    }
    return iVar1;
  }
  return 0;
}

// ===== AbyssEngine::ImageFontGetYOffset  @0x0007b59e  (12 bytes)
/* AbyssEngine::ImageFontGetYOffset(AbyssEngine::ImageFont*) */

int AbyssEngine::ImageFontGetYOffset(ImageFont *param_1)

{
  short sVar1;
  
  if (param_1 == (ImageFont *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = *(short *)(param_1 + 0x12);
  }
  return (int)sVar1;
}

// ===== AbyssEngine::ImageFontGetWidth  @0x0007b5aa  (128 bytes)
/* AbyssEngine::ImageFontGetWidth(AbyssEngine::ImageFont*, unsigned short const*, unsigned int,
   unsigned int) */

int AbyssEngine::ImageFontGetWidth(ImageFont *param_1,ushort *param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = 0;
  if (param_1 != (ImageFont *)0x0 && param_2 != (ushort *)0x0) {
    uVar6 = param_4 + param_3;
    uVar3 = param_3 & 0xffff;
    iVar1 = 0;
    if (uVar3 < uVar6) {
      do {
        if (*(ushort *)param_1 != 0) {
          iVar4 = 0;
          uVar5 = 0;
          do {
            if (*(ushort *)(*(int *)(param_1 + 4) + iVar4) == param_2[uVar3]) {
              iVar7 = (int)*(float *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + iVar4 * 2) + 4) +
                                     0xc);
              iVar2 = *(short *)(param_1 + 0x10) + iVar7;
              iVar4 = iVar2;
              if (iVar7 == 0xb) {
                iVar4 = iVar2 + -2;
              }
              if (param_2[uVar3] != 0x20) {
                iVar4 = iVar2;
              }
              iVar1 = iVar1 + iVar4;
              break;
            }
            uVar5 = uVar5 + 1;
            iVar4 = iVar4 + 2;
          } while (uVar5 < *(ushort *)param_1);
        }
        param_3 = param_3 + 1;
        uVar3 = param_3 & 0xffff;
      } while (uVar3 < uVar6);
    }
  }
  return iVar1;
}

// ===== AbyssEngine::ImageFontSetSpacing  @0x0007b62a  (6 bytes)
/* AbyssEngine::ImageFontSetSpacing(AbyssEngine::ImageFont*, short) */

void AbyssEngine::ImageFontSetSpacing(ImageFont *param_1,short param_2)

{
  if (param_1 != (ImageFont *)0x0) {
    *(short *)(param_1 + 0x10) = param_2;
  }
  return;
}

// ===== AbyssEngine::ImageFontGetSpacing  @0x0007b630  (12 bytes)
/* AbyssEngine::ImageFontGetSpacing(AbyssEngine::ImageFont*) */

int AbyssEngine::ImageFontGetSpacing(ImageFont *param_1)

{
  short sVar1;
  
  if (param_1 == (ImageFont *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = *(short *)(param_1 + 0x10);
  }
  return (int)sVar1;
}

// ===== AbyssEngine::ImageFontSetYOffset  @0x0007b63c  (6 bytes)
/* AbyssEngine::ImageFontSetYOffset(AbyssEngine::ImageFont*, short) */

void AbyssEngine::ImageFontSetYOffset(ImageFont *param_1,short param_2)

{
  if (param_1 != (ImageFont *)0x0) {
    *(short *)(param_1 + 0x12) = param_2;
  }
  return;
}

// ===== AbyssEngine::ImageFontRelease  @0x0007b642  (90 bytes)
/* AbyssEngine::ImageFontRelease(AbyssEngine::Engine*, AbyssEngine::ImageFont**) */

void AbyssEngine::ImageFontRelease(Engine *param_1,ImageFont **param_2)

{
  ImageFont *pIVar1;
  ushort uVar2;
  
  pIVar1 = *param_2;
  if (pIVar1 != (ImageFont *)0x0) {
    if (*(void **)(pIVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pIVar1 + 4));
      pIVar1 = *param_2;
    }
    *(undefined4 *)(pIVar1 + 4) = 0;
    pIVar1 = *param_2;
    if (*(ushort *)pIVar1 != 0) {
      uVar2 = 0;
      do {
        MeshRelease(param_1,(Mesh **)(*(int *)(pIVar1 + 0xc) + (uint)uVar2 * 4));
        pIVar1 = *param_2;
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)pIVar1);
    }
    if (*(void **)(pIVar1 + 0xc) != (void *)0x0) {
      operator_delete__(*(void **)(pIVar1 + 0xc));
      pIVar1 = *param_2;
    }
    *(undefined4 *)(pIVar1 + 0xc) = 0;
    if (*param_2 != (ImageFont *)0x0) {
      operator_delete(*param_2);
    }
    *param_2 = (ImageFont *)0x0;
  }
  return;
}

// ===== AbyssEngine::MODF  @0x0007be54  (26 bytes)
/* AbyssEngine::MODF(float, float*) */

float AbyssEngine::MODF(float param_1,float *param_2)

{
  float *in_r1;
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorSignedToFloat((int)(float)param_2,(byte)(in_fpscr >> 0x16) & 3);
  *in_r1 = fVar1;
  return (float)param_2 - fVar1;
}

// ===== AbyssEngine::computeFloatString  @0x0007be70  (440 bytes)
/* AbyssEngine::computeFloatString(float, int, int*, int*, int) */

void AbyssEngine::computeFloatString
               (float param_1,int param_2,int *param_3,int *param_4,int param_5)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  int iVar11;
  float fVar12;
  int in_stack_00000000;
  
  puVar2 = operator_new__(0x42);
  *(undefined4 *)param_5 = 0;
  if ((int)param_3 < 0) {
    param_3 = (int *)0x0;
  }
  in_fpscr = in_fpscr & 0xfffffff;
  if (0x1e < (int)param_3) {
    param_3 = (int *)0x1e;
  }
  if ((float)param_2 < 0.0) {
    param_2 = (int)-(float)param_2;
    *(undefined4 *)param_5 = 1;
  }
  fVar10 = (float)VectorSignedToFloat((int)(float)param_2,(byte)(in_fpscr >> 0x16) & 3);
  fVar9 = (float)param_2 - fVar10;
  puVar4 = puVar2;
  if ((int)(float)param_2 == 0) {
    if (0.0 < fVar9) {
      iVar6 = 1;
      fVar10 = fVar9;
      do {
        fVar9 = fVar10;
        iVar6 = iVar6 + -1;
        fVar10 = fVar9 * 10.0;
      } while (fVar9 * 10.0 < 1.0);
    }
    else {
      iVar6 = 0;
    }
  }
  else {
    iVar6 = 0;
    puVar8 = puVar2;
    do {
      puVar5 = puVar8;
      fVar12 = fVar10 / 10.0;
      iVar6 = iVar6 + 1;
      iVar11 = (int)fVar12;
      fVar10 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
      puVar5[0x1f] = (short)(longlong)(((fVar12 - fVar10) + 0.03) * 10.0) + 0x30;
      puVar8 = puVar5 + -1;
    } while (iVar11 != 0);
    if (puVar5 + 0x1f < puVar2 + 0x20) {
      iVar11 = 0;
      do {
        *(undefined2 *)((int)puVar2 + iVar11) = *(undefined2 *)((int)puVar8 + iVar11 + 0x40);
        iVar1 = iVar11 + 0x42;
        puVar4 = (ushort *)
                 (((int)puVar2 + (0x41 - (int)(puVar5 + 0x1f)) & 0xfffffffeU) + (int)puVar2);
        iVar11 = iVar11 + 2;
      } while ((ushort *)((int)puVar8 + iVar1) < puVar2 + 0x20);
    }
  }
  puVar8 = puVar2 + (int)param_3;
  *param_4 = iVar6;
  if (in_stack_00000000 == 0) {
    puVar8 = puVar8 + iVar6;
  }
  if (puVar8 < puVar2) {
    *puVar2 = 0;
  }
  else {
    puVar7 = puVar2 + 0x20;
    puVar5 = puVar8;
    if (puVar4 <= puVar8) {
      puVar5 = puVar7;
    }
    if (puVar4 < puVar5) {
      do {
        puVar5 = puVar4 + 1;
        fVar10 = (float)VectorSignedToFloat((int)(fVar9 * 10.0),(byte)(in_fpscr >> 0x16) & 3);
        *puVar4 = (short)(int)fVar10 + 0x30;
        if (puVar8 < puVar5) break;
        fVar9 = fVar9 * 10.0 - fVar10;
        puVar4 = puVar5;
      } while (puVar5 < puVar7);
    }
    if (puVar8 < puVar7) {
      uVar3 = *puVar8 + 5;
      *puVar8 = uVar3;
      puVar4 = puVar8;
      while (0x39 < uVar3) {
        *puVar8 = 0x30;
        if (puVar2 < puVar8) {
          puVar8 = puVar8 + -1;
          uVar3 = *puVar8 + 1;
          *puVar8 = uVar3;
        }
        else {
          iVar6 = iVar6 + 1;
          uVar3 = 0x31;
          *puVar8 = 0x31;
          *param_4 = iVar6;
          if (in_stack_00000000 == 0) {
            if (puVar2 < puVar4) {
              *puVar4 = 0x30;
              uVar3 = *puVar8;
            }
            else {
              uVar3 = 0x31;
            }
            puVar4 = puVar4 + 1;
          }
        }
      }
      *puVar4 = 0;
    }
    else {
      puVar2[0x1f] = 0;
    }
  }
  return;
}

// ===== AbyssEngine::operator+  @0x0007c258  (92 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&, AbyssEngine::String const&) */

void __thiscall AbyssEngine::operator+(AbyssEngine *this,String *param_1,String *param_2)

{
  ushort *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24[0] = (ushort *)0x0;
  String::Set((String *)local_24,*(ushort **)param_1);
  String::operator+=((String *)local_24,param_2);
  *(undefined4 *)this = 0;
  String::Set((String *)this,local_24[0]);
  if (local_24[0] != (ushort *)0x0) {
    operator_delete__(local_24[0]);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::operator+  @0x0007cb8c  (16 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&) */

void __thiscall AbyssEngine::operator+(AbyssEngine *this,String *param_1)

{
  *(undefined4 *)this = 0;
  String::Set((String *)this,*(ushort **)param_1);
  return;
}

// ===== AbyssEngine::operator+  @0x0007cb9c  (102 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&, long long const&) */

void AbyssEngine::operator+(String *param_1,longlong *param_2)

{
  undefined4 extraout_r1;
  void *local_28 [2];
  ushort *local_20 [2];
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_20[0] = (ushort *)0x0;
  String::Set((String *)local_20,*(ushort **)param_2);
  local_28[0] = (void *)0x0;
  String::Set(CONCAT44(extraout_r1,local_28));
  String::operator+=((String *)local_20,(String *)local_28);
  if (local_28[0] != (void *)0x0) {
    operator_delete__(local_28[0]);
  }
  *(undefined4 *)param_1 = 0;
  String::Set((String *)param_1,local_20[0]);
  if (local_20[0] != (ushort *)0x0) {
    operator_delete__(local_20[0]);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::operator+  @0x0007cc2c  (94 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(long long const&, AbyssEngine::String const&) */

void __thiscall AbyssEngine::operator+(AbyssEngine *this,longlong *param_1,String *param_2)

{
  ushort *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24[0] = (ushort *)0x0;
  String::Set(CONCAT44(param_1,(String *)local_24));
  String::operator+=((String *)local_24,param_2);
  *(undefined4 *)this = 0;
  String::Set((String *)this,local_24[0]);
  if (local_24[0] != (ushort *)0x0) {
    operator_delete__(local_24[0]);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::operator+  @0x0007cca4  (102 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&, int const&) */

void AbyssEngine::operator+(String *param_1,int *param_2)

{
  undefined4 extraout_r1;
  void *local_28 [2];
  ushort *local_20 [2];
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_20[0] = (ushort *)0x0;
  String::Set((String *)local_20,(ushort *)*param_2);
  local_28[0] = (void *)0x0;
  String::Set(CONCAT44(extraout_r1,local_28));
  String::operator+=((String *)local_20,(String *)local_28);
  if (local_28[0] != (void *)0x0) {
    operator_delete__(local_28[0]);
  }
  *(undefined4 *)param_1 = 0;
  String::Set((String *)param_1,local_20[0]);
  if (local_20[0] != (ushort *)0x0) {
    operator_delete__(local_20[0]);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::operator+  @0x0007cd34  (94 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(int const&, AbyssEngine::String const&) */

void __thiscall AbyssEngine::operator+(AbyssEngine *this,int *param_1,String *param_2)

{
  ushort *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24[0] = (ushort *)0x0;
  String::Set(CONCAT44(param_1,(String *)local_24));
  String::operator+=((String *)local_24,param_2);
  *(undefined4 *)this = 0;
  String::Set((String *)this,local_24[0]);
  if (local_24[0] != (ushort *)0x0) {
    operator_delete__(local_24[0]);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::operator+  @0x0007cdac  (100 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&, float const&) */

void AbyssEngine::operator+(String *param_1,float *param_2)

{
  float fVar1;
  void *local_28 [2];
  ushort *local_20 [2];
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_20[0] = (ushort *)0x0;
  fVar1 = (float)String::Set((String *)local_20,(ushort *)*param_2);
  local_28[0] = (void *)0x0;
  String::Set(fVar1);
  String::operator+=((String *)local_20,(String *)local_28);
  if (local_28[0] != (void *)0x0) {
    operator_delete__(local_28[0]);
  }
  *(undefined4 *)param_1 = 0;
  String::Set((String *)param_1,local_20[0]);
  if (local_20[0] != (ushort *)0x0) {
    operator_delete__(local_20[0]);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::operator+  @0x0007ce3c  (92 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(float const&, AbyssEngine::String const&) */

void AbyssEngine::operator+(float *param_1,String *param_2)

{
  String *in_r2;
  float in_s0;
  ushort *local_24 [2];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_24[0] = (ushort *)0x0;
  String::Set(in_s0);
  String::operator+=((String *)local_24,in_r2);
  *param_1 = 0.0;
  String::Set((String *)param_1,local_24[0]);
  if (local_24[0] != (ushort *)0x0) {
    operator_delete__(local_24[0]);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::operator==  @0x0007ceb0  (82 bytes)
/* AbyssEngine::TEMPNAMEPLACEHOLDERVALUE(AbyssEngine::String const&, AbyssEngine::String const&) */

void AbyssEngine::operator==(String *param_1,String *param_2)

{
  void *local_20 [2];
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_20[0] = (void *)0x0;
  String::Set((String *)local_20,*(ushort **)param_1);
  String::Compare((String *)local_20,param_2);
  if (local_20[0] != (void *)0x0) {
    operator_delete__(local_20[0]);
  }
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::CurveCreate  @0x0007d798  (48 bytes)
/* AbyssEngine::CurveCreate(void**, unsigned short, AbyssEngine::Curve**) */

undefined4 AbyssEngine::CurveCreate(void **param_1,ushort param_2,Curve **param_3)

{
  Curve *pCVar1;
  void *pvVar2;
  
  pCVar1 = operator_new(8);
  *param_3 = pCVar1;
  *(ushort *)pCVar1 = param_2;
  pvVar2 = operator_new__((uint)param_2 << 2);
  *(void **)(pCVar1 + 4) = pvVar2;
  __aeabi_memcpy4(pvVar2,param_1,(uint)param_2 << 2);
  return 1;
}

// ===== AbyssEngine::CurveGetValue  @0x0007d7c8  (402 bytes)
/* AbyssEngine::CurveGetValue(unsigned long long, AbyssEngine::Curve*) */

int __thiscall AbyssEngine::CurveGetValue(AbyssEngine *this,ulonglong param_1,Curve *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint in_r1;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  AbyssEngine *pAVar14;
  uint uVar15;
  int iVar16;
  char *pcVar17;
  uint uVar18;
  uint uVar19;
  int *piVar20;
  uint uVar21;
  longlong lVar22;
  ulonglong uVar23;
  
  piVar20 = *(int **)((ushort *)param_1 + 2);
  iVar7 = *piVar20;
  if (*(uint *)(iVar7 + 0xc) <= in_r1 &&
      (uint)(this <= *(AbyssEngine **)(iVar7 + 8)) <= *(uint *)(iVar7 + 0xc) - in_r1) {
    uVar6 = *(ushort *)param_1 - 1;
    iVar7 = piVar20[uVar6];
    if (in_r1 <= *(uint *)(iVar7 + 0xc) &&
        (uint)(*(AbyssEngine **)(iVar7 + 8) <= this) <= in_r1 - *(uint *)(iVar7 + 0xc)) {
      do {
        uVar8 = uVar6 & 0xffff;
        uVar6 = uVar6 - 1;
        pcVar17 = (char *)piVar20[uVar8];
        pAVar14 = *(AbyssEngine **)(pcVar17 + 8);
        uVar12 = *(uint *)(pcVar17 + 0xc);
      } while (in_r1 <= uVar12 && (uint)(pAVar14 <= this) <= in_r1 - uVar12);
      cVar1 = *pcVar17;
      if (cVar1 == '\x03') {
        iVar7 = piVar20[uVar8 + 1];
        iVar16 = *(int *)(iVar7 + 0x10);
        lVar22 = __aeabi_uldivmod(((int)this - (int)pAVar14) * 0x1000,
                                  ((in_r1 - uVar12) - (uint)(this < pAVar14)) * 0x1000 |
                                  (uint)((int)this - (int)pAVar14) >> 0x14,
                                  (int)*(AbyssEngine **)(iVar7 + 8) - (int)pAVar14,
                                  (*(int *)(iVar7 + 0xc) - uVar12) -
                                  (uint)(*(AbyssEngine **)(iVar7 + 8) < pAVar14));
        uVar10 = (uint)((ulonglong)(lVar22 * lVar22) >> 0x20);
        uVar15 = (uint)(lVar22 * lVar22) >> 0xc | uVar10 * 0x100000;
        uVar18 = uVar10 >> 0xc;
        lVar4 = lVar22 * CONCAT44(uVar18,uVar15);
        uVar21 = (uint)((ulonglong)lVar4 >> 0x20);
        uVar19 = (uint)lVar4 >> 0xc | uVar21 * 0x100000;
        uVar9 = *(uint *)(pcVar17 + 0x14);
        uVar13 = *(uint *)(pcVar17 + 0x18);
        lVar4 = (ulonglong)(uVar19 - uVar15) * (ulonglong)uVar13;
        iVar7 = (int)uVar21 >> 0xc;
        uVar6 = (uint)lVar22 + uVar15 * -2;
        uVar8 = uVar6 + uVar19;
        lVar2 = (ulonglong)uVar8 * (ulonglong)uVar9;
        uVar11 = iVar16 - *(int *)(pcVar17 + 0x10);
        uVar12 = (uint)((ulonglong)uVar15 * 3);
        uVar5 = uVar12 + uVar19 * -2;
        lVar3 = (ulonglong)uVar5 * (ulonglong)uVar11;
        return ((uint)lVar2 >> 0xc |
               (((((int)((ulonglong)lVar22 >> 0x20) - (uVar18 << 1 | (uVar10 & 0xfff) >> 0xb)) -
                 (uint)((uint)lVar22 < uVar15 * 2)) + iVar7 + (uint)CARRY4(uVar6,uVar19)) * uVar9 +
               uVar8 * ((int)uVar9 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000) +
               ((uint)lVar4 >> 0xc |
               (((iVar7 - (uVar10 >> 0xc)) - (uint)(uVar19 < uVar15)) * uVar13 +
               (uVar19 - uVar15) * ((int)uVar13 >> 0x1f) + (int)((ulonglong)lVar4 >> 0x20)) *
               0x100000) + *(int *)(pcVar17 + 0x10) +
               ((uint)lVar3 >> 0xc |
               (((((int)((ulonglong)uVar15 * 3 >> 0x20) + uVar18 * 3) -
                 (iVar7 << 1 | (uVar21 & 0xfff) >> 0xb)) - (uint)(uVar12 < uVar19 * 2)) * uVar11 +
               uVar5 * ((int)uVar11 >> 0x1f) + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000);
      }
      if (cVar1 == '\x02') {
        iVar7 = piVar20[uVar8 + 1];
        iVar16 = *(int *)(iVar7 + 0x10);
        uVar23 = __aeabi_uldivmod(((int)this - (int)pAVar14) * 0x1000,
                                  ((in_r1 - uVar12) - (uint)(this < pAVar14)) * 0x1000 |
                                  (uint)((int)this - (int)pAVar14) >> 0x14,
                                  (int)*(AbyssEngine **)(iVar7 + 8) - (int)pAVar14,
                                  (*(int *)(iVar7 + 0xc) - uVar12) -
                                  (uint)(*(AbyssEngine **)(iVar7 + 8) < pAVar14));
        uVar6 = iVar16 - *(int *)(pcVar17 + 0x10);
        lVar4 = (uVar23 & 0xffffffff) * (ulonglong)uVar6;
        return ((uint)lVar4 >> 0xc |
               ((int)(uVar23 >> 0x20) * uVar6 +
               (int)uVar23 * ((int)uVar6 >> 0x1f) + (int)((ulonglong)lVar4 >> 0x20)) * 0x100000) +
               *(int *)(pcVar17 + 0x10);
      }
      if (cVar1 != '\x01') {
        return 0;
      }
      return *(int *)(pcVar17 + 0x10);
    }
  }
  return *(int *)(iVar7 + 0x10);
}

// ===== AbyssEngine::CurveRelease  @0x0007d95a  (84 bytes)
/* AbyssEngine::CurveRelease(AbyssEngine::Curve**) */

void AbyssEngine::CurveRelease(Curve **param_1)

{
  char cVar1;
  char *pcVar2;
  Curve *pCVar3;
  ushort uVar4;
  
  pCVar3 = *param_1;
  if (pCVar3 != (Curve *)0x0) {
    if (*(ushort *)pCVar3 != 0) {
      uVar4 = 0;
      do {
        pcVar2 = *(char **)(*(int *)(pCVar3 + 4) + (uint)uVar4 * 4);
        cVar1 = *pcVar2;
        if (((cVar1 == '\x03' || cVar1 == '\x02') || (cVar1 == '\x01')) && (pcVar2 != (char *)0x0))
        {
          operator_delete(pcVar2);
        }
        pCVar3 = *param_1;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(ushort *)pCVar3);
    }
    if (*(void **)(pCVar3 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pCVar3 + 4));
      pCVar3 = *param_1;
    }
    *(undefined4 *)(pCVar3 + 4) = 0;
    if (*param_1 != (Curve *)0x0) {
      operator_delete(*param_1);
    }
    *param_1 = (Curve *)0x0;
  }
  return;
}

// ===== AbyssEngine::esMatrixMultiply  @0x0008f2e4  (150 bytes)
/* AbyssEngine::esMatrixMultiply(AbyssEngine::ESMatrix*, AbyssEngine::ESMatrix*,
   AbyssEngine::ESMatrix*) */

void AbyssEngine::esMatrixMultiply(ESMatrix *param_1,ESMatrix *param_2,ESMatrix *param_3)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  ESMatrix *pEVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 in_s1;
  undefined4 uVar10;
  undefined4 in_s5;
  undefined8 in_d4;
  undefined8 in_d6;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int local_14;
  
  local_14 = __stack_chk_guard;
  auVar2 = *(undefined1 (*) [16])param_3;
  auVar5 = *(undefined1 (*) [16])(param_3 + 0x30);
  auVar3 = *(undefined1 (*) [16])(param_3 + 0x10);
  auVar4 = *(undefined1 (*) [16])(param_3 + 0x20);
  iVar7 = 0;
  do {
    pEVar6 = param_2 + iVar7;
    uVar9 = *(undefined4 *)pEVar6;
    uVar10 = *(undefined4 *)(pEVar6 + 4);
    uVar1 = VectorGetElement(CONCAT44(in_s1,uVar9),0,4,0);
    auVar12 = VectorMultiply(auVar2,uVar1,4);
    uVar1 = VectorGetElement(in_d6,0,4,0);
    auVar11 = VectorMultiply(auVar3,uVar1,4);
    iVar8 = iVar7 + 0x10;
    uVar1 = VectorGetElement(in_d4,0,4,0);
    auVar13 = VectorMultiply(auVar4,uVar1,4);
    auVar11 = FloatVectorAdd(auVar12,auVar11,2);
    uVar1 = VectorGetElement(CONCAT44(in_s5,*(undefined4 *)(pEVar6 + 8)),0,4,0);
    auVar12 = VectorMultiply(auVar5,uVar1,4);
    auVar11 = FloatVectorAdd(auVar11,auVar13,2);
    auVar11 = FloatVectorAdd(auVar11,auVar12,2);
    *(longlong *)((int)&local_58 + iVar7) = auVar11._0_8_;
    *(longlong *)((int)&uStack_50 + iVar7) = auVar11._8_8_;
    iVar7 = iVar8;
  } while (iVar8 != 0x40);
  *(undefined4 *)param_1 = (undefined4)local_58;
  *(undefined4 *)(param_1 + 4) = local_58._4_4_;
  *(undefined4 *)(param_1 + 8) = (undefined4)uStack_50;
  *(undefined4 *)(param_1 + 0xc) = uStack_50._4_4_;
  *(undefined4 *)(param_1 + 0x10) = uStack_48;
  *(undefined4 *)(param_1 + 0x14) = local_44;
  *(undefined4 *)(param_1 + 0x18) = uStack_40;
  *(undefined4 *)(param_1 + 0x1c) = uStack_3c;
  *(undefined4 *)(param_1 + 0x20) = uStack_38;
  *(undefined4 *)(param_1 + 0x24) = uStack_34;
  *(undefined4 *)(param_1 + 0x28) = local_30;
  *(undefined4 *)(param_1 + 0x2c) = uStack_2c;
  *(undefined4 *)(param_1 + 0x30) = uStack_28;
  *(undefined4 *)(param_1 + 0x34) = uStack_24;
  *(undefined4 *)(param_1 + 0x38) = uStack_20;
  *(undefined4 *)(param_1 + 0x3c) = uStack_1c;
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9,in_s1,uVar10);
  }
  return;
}

// ===== AbyssEngine::SetFXMaterial  @0x00090c7c  (2 bytes)
/* AbyssEngine::SetFXMaterial(AbyssEngine::BlendMode) */

void AbyssEngine::SetFXMaterial(void)

{
  return;
}

// ===== AbyssEngine::SpriteSystemCreate  @0x00091a78  (434 bytes)
/* AbyssEngine::SpriteSystemCreate(AbyssEngine::Engine*, unsigned short, bool,
   AbyssEngine::SpriteSystem**) */

undefined4
AbyssEngine::SpriteSystemCreate(Engine *param_1,ushort param_2,bool param_3,SpriteSystem **param_4)

{
  short sVar1;
  char cVar2;
  SpriteSystem *pSVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  short sVar8;
  int iVar9;
  SpriteSystem *pSVar10;
  ushort uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  
  uVar15 = (uint)param_2;
  if (uVar15 == 0) {
    uVar7 = 0xfffffffc;
  }
  else {
    pSVar3 = operator_new(0x14);
    *(undefined4 *)(pSVar3 + 4) = 0;
    *(undefined4 *)(pSVar3 + 8) = 0;
    uVar14 = uVar15 << 1;
    *(undefined4 *)(pSVar3 + 0x10) = 0;
    *param_4 = pSVar3;
    *(ushort *)pSVar3 = param_2;
    iVar4 = MeshCreate(param_1,(uVar15 & 0x3fff) << 2,uVar14 & 0xffff,0x1f,pSVar3 + 0x10);
    pSVar10 = *param_4;
    pSVar3 = pSVar10 + 0x10;
    if (iVar4 == 1) {
      iVar4 = *(int *)(*(Mesh **)pSVar3 + 0x2c);
      pvVar5 = operator_new__(uVar15 * 0xc);
      *(void **)(pSVar10 + 4) = pvVar5;
      __aeabi_memclr4(*(undefined4 *)(*param_4 + 4),uVar15 * 0xc);
      pSVar3 = *param_4;
      pSVar3[0xc] = (SpriteSystem)param_3;
      if (param_3) {
        pvVar5 = operator_new__(2);
        *(void **)(pSVar3 + 8) = pvVar5;
        **(undefined2 **)(*param_4 + 8) = 0;
      }
      else {
        pvVar5 = operator_new__(uVar14);
        *(void **)(pSVar3 + 8) = pvVar5;
        __aeabi_memclr(*(undefined4 *)(*param_4 + 8),uVar14);
      }
      uVar14 = 0;
      sVar8 = 0;
      do {
        iVar9 = iVar4 + uVar14 * 2;
        *(short *)(iVar4 + uVar14 * 2) = sVar8;
        *(short *)(iVar9 + 2) = sVar8 + 1;
        *(short *)(iVar9 + 4) = sVar8 + 2;
        uVar14 = uVar14 + 6 & 0xffff;
        *(short *)(iVar9 + 6) = sVar8;
        *(short *)(iVar9 + 8) = sVar8 + 2;
        sVar1 = sVar8 + 3;
        sVar8 = sVar8 + 4;
        *(short *)(iVar9 + 10) = sVar1;
      } while (uVar14 < uVar15 * 6);
      iVar4 = *(int *)(*param_4 + 0x10);
      uVar15 = (uint)*(ushort *)(iVar4 + 2);
      if (uVar15 != 0) {
        iVar9 = *(int *)(iVar4 + 0xc);
        uVar14 = 0;
        uVar11 = 0;
        do {
          uVar11 = uVar11 + 1;
          *(undefined4 *)(iVar9 + uVar14 * 4) = 0x3f800000;
          cVar2 = Engine::enableShader;
          uVar14 = (uint)uVar11;
        } while (uVar14 < uVar15 << 2);
        if (uVar15 != 0) {
          iVar9 = *(int *)(iVar4 + 0x10);
          iVar12 = 4;
          uVar14 = 0;
          do {
            iVar6 = iVar9 + iVar12;
            *(undefined4 *)(iVar6 + -4) = 0;
            *(undefined4 *)(iVar9 + iVar12) = 0;
            *(undefined4 *)(iVar6 + 4) = 0x3f800000;
            if (cVar2 != '\0') {
              iVar6 = *(int *)(iVar4 + 0x14);
              iVar13 = iVar6 + iVar12;
              *(undefined4 *)(iVar13 + -4) = 0x3f800000;
              *(undefined4 *)(iVar6 + iVar12) = 0;
              *(undefined4 *)(iVar13 + 4) = 0;
              iVar6 = *(int *)(iVar4 + 0x18);
              iVar13 = iVar6 + iVar12;
              *(undefined4 *)(iVar13 + -4) = 0;
              *(undefined4 *)(iVar6 + iVar12) = 0x3f800000;
              *(undefined4 *)(iVar13 + 4) = 0;
            }
            uVar14 = uVar14 + 1;
            iVar12 = iVar12 + 0xc;
          } while (uVar14 < uVar15);
        }
      }
      uVar7 = 1;
    }
    else {
      MeshRelease(param_1,(Mesh **)pSVar3);
      pSVar3 = *param_4;
      if (*(void **)(pSVar3 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pSVar3 + 4));
        pSVar3 = *param_4;
      }
      *(undefined4 *)(pSVar3 + 4) = 0;
      pSVar3 = *param_4;
      if (*(void **)(pSVar3 + 8) != (void *)0x0) {
        operator_delete__(*(void **)(pSVar3 + 8));
        pSVar3 = *param_4;
      }
      *(undefined4 *)(pSVar3 + 8) = 0;
      if (*param_4 != (SpriteSystem *)0x0) {
        operator_delete(*param_4);
      }
      *param_4 = (SpriteSystem *)0x0;
      uVar7 = 0xffffffff;
    }
  }
  return uVar7;
}

// ===== AbyssEngine::SpriteSystemSetAllUv  @0x00091c30  (108 bytes)
/* AbyssEngine::SpriteSystemSetAllUv(float, float, float, float, AbyssEngine::SpriteSystem*) */

void AbyssEngine::SpriteSystemSetAllUv
               (float param_1,float param_2,float param_3,float param_4,SpriteSystem *param_5)

{
  int iVar1;
  float in_r1;
  undefined4 in_r2;
  uint uVar2;
  float in_r3;
  undefined4 *puVar3;
  uint unaff_lr;
  ushort *in_stack_00000000;
  
  if (in_stack_00000000 != (ushort *)0x0) {
    unaff_lr = (uint)*in_stack_00000000;
  }
  if (in_stack_00000000 != (ushort *)0x0 && unaff_lr != 0) {
    uVar2 = 0;
    iVar1 = *(int *)(*(int *)(in_stack_00000000 + 8) + 8);
    do {
      puVar3 = (undefined4 *)(iVar1 + uVar2 * 4);
      uVar2 = uVar2 + 8 & 0xffff;
      *puVar3 = param_5;
      puVar3[1] = 1.0 - in_r1;
      puVar3[2] = in_r2;
      puVar3[3] = 1.0 - in_r1;
      puVar3[4] = in_r2;
      puVar3[5] = 1.0 - in_r3;
      puVar3[6] = param_5;
      puVar3[7] = 1.0 - in_r3;
    } while (uVar2 < unaff_lr << 3);
  }
  return;
}

// ===== AbyssEngine::SpriteSystemSetUv  @0x00091c9c  (102 bytes)
/* AbyssEngine::SpriteSystemSetUv(unsigned short, float, float, float, float,
   AbyssEngine::SpriteSystem*) */

float AbyssEngine::SpriteSystemSetUv
                (ushort param_1,float param_2,float param_3,float param_4,float param_5,
                SpriteSystem *param_6)

{
  char cVar1;
  undefined4 *puVar2;
  float in_r2;
  undefined4 in_r3;
  uint unaff_lr;
  float in_stack_00000000;
  ushort *in_stack_00000004;
  
  cVar1 = Engine::enableShader;
  if (in_stack_00000004 != (ushort *)0x0) {
    unaff_lr = (uint)*in_stack_00000004;
  }
  if (in_stack_00000004 != (ushort *)0x0 && param_1 < unaff_lr) {
    puVar2 = (undefined4 *)(*(int *)(*(int *)(in_stack_00000004 + 8) + 8) + (uint)param_1 * 0x20);
    *puVar2 = param_6;
    if (cVar1 == '\0') {
      in_r2 = 1.0 - in_r2;
      in_stack_00000000 = 1.0 - in_stack_00000000;
    }
    puVar2[1] = in_r2;
    puVar2[2] = in_r3;
    puVar2[3] = in_r2;
    puVar2[4] = in_r3;
    puVar2[5] = in_stack_00000000;
    puVar2[6] = param_6;
    puVar2[7] = in_stack_00000000;
    param_2 = (float)param_6;
  }
  return param_2;
}

// ===== AbyssEngine::SpriteSystemSetRGBA  @0x00091d08  (112 bytes)
/* AbyssEngine::SpriteSystemSetRGBA(unsigned short, float, float, float, float,
   AbyssEngine::SpriteSystem*) */

float AbyssEngine::SpriteSystemSetRGBA
                (ushort param_1,float param_2,float param_3,float param_4,float param_5,
                SpriteSystem *param_6)

{
  undefined4 *puVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  uint unaff_lr;
  float in_stack_00000000;
  ushort *in_stack_00000004;
  
  if (in_stack_00000004 != (ushort *)0x0) {
    unaff_lr = (uint)*in_stack_00000004;
  }
  if (in_stack_00000004 != (ushort *)0x0 && param_1 < unaff_lr) {
    puVar1 = (undefined4 *)(*(int *)(*(int *)(in_stack_00000004 + 8) + 0xc) + (uint)param_1 * 0x40);
    *puVar1 = param_6;
    puVar1[1] = in_r2;
    puVar1[2] = in_r3;
    puVar1[3] = in_stack_00000000;
    puVar1[4] = param_6;
    puVar1[5] = in_r2;
    puVar1[6] = in_r3;
    puVar1[7] = in_stack_00000000;
    puVar1[8] = param_6;
    puVar1[9] = in_r2;
    puVar1[10] = in_r3;
    puVar1[0xb] = in_stack_00000000;
    puVar1[0xc] = param_6;
    puVar1[0xd] = in_r2;
    puVar1[0xe] = in_r3;
    puVar1[0xf] = in_stack_00000000;
    param_2 = in_stack_00000000;
  }
  return param_2;
}

// ===== AbyssEngine::SpriteSystemSetAllSize  @0x00091d78  (44 bytes)
/* AbyssEngine::SpriteSystemSetAllSize(short, AbyssEngine::SpriteSystem*) */

void AbyssEngine::SpriteSystemSetAllSize(short param_1,SpriteSystem *param_2)

{
  uint uVar1;
  ushort uVar2;
  short *psVar3;
  
  if (param_2 != (SpriteSystem *)0x0) {
    psVar3 = *(short **)(param_2 + 8);
    if (param_2[0xc] != (SpriteSystem)0x0) {
      *psVar3 = param_1;
      return;
    }
    if (*(short *)param_2 != 0) {
      uVar2 = 0;
      do {
        uVar1 = (uint)uVar2;
        uVar2 = uVar2 + 1;
        psVar3[uVar1] = param_1;
      } while (uVar2 < *(ushort *)param_2);
    }
  }
  return;
}

// ===== AbyssEngine::SpriteSystemDraw  @0x00091da4  (662 bytes)
/* AbyssEngine::SpriteSystemDraw(AbyssEngine::Engine*, AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Matrix const&, AbyssEngine::SpriteSystem*) */

void AbyssEngine::SpriteSystemDraw
               (Engine *param_1,Matrix *param_2,Matrix *param_3,SpriteSystem *param_4)

{
  SpriteSystem SVar1;
  ushort uVar2;
  ushort uVar3;
  float *pfVar4;
  uint uVar5;
  Mesh *pMVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  AEMath aAStack_64 [60];
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_4 != (SpriteSystem *)0x0) {
    iVar10 = *(int *)(*(int *)(param_4 + 0x10) + 4);
    AEMath::operator*(aAStack_64,param_2,param_3);
    uVar2 = *(ushort *)param_4;
    if (uVar2 != 0) {
      uVar8 = 0;
      iVar11 = *(int *)(param_4 + 4);
      iVar9 = *(int *)(param_4 + 8);
      SVar1 = param_4[0xc];
      uVar7 = 0;
      uVar3 = 0;
      do {
        pfVar4 = (float *)(iVar11 + (uint)uVar7 * 4);
        uVar7 = uVar7 + 3;
        fVar13 = *pfVar4;
        fVar14 = pfVar4[1];
        fVar15 = pfVar4[2];
        uVar5 = (uint)uVar3;
        uVar3 = ((byte)SVar1 ^ 1) + uVar3;
        pfVar4 = (float *)(iVar10 + uVar8 * 4);
        fVar16 = (float)VectorSignedToFloat((int)*(short *)(iVar9 + uVar5 * 2) >> 1,
                                            (byte)(in_fpscr >> 0x16) & 3);
        fVar12 = *(float *)(param_3 + 0x1c) +
                 fVar13 * *(float *)(param_3 + 0x10) + fVar14 * *(float *)(param_3 + 0x14) +
                 fVar15 * *(float *)(param_3 + 0x18);
        fVar17 = *(float *)(param_3 + 0xc) +
                 *(float *)param_3 * fVar13 + *(float *)(param_3 + 4) * fVar14 +
                 *(float *)(param_3 + 8) * fVar15;
        fVar18 = fVar12 - fVar16;
        fVar12 = fVar12 + fVar16;
        fVar13 = *(float *)(param_3 + 0x2c) +
                 fVar13 * *(float *)(param_3 + 0x20) + fVar14 * *(float *)(param_3 + 0x24) +
                 fVar15 * *(float *)(param_3 + 0x28);
        fVar14 = fVar17 - fVar16;
        fVar17 = fVar17 + fVar16;
        *pfVar4 = fVar14;
        pfVar4[1] = fVar18;
        pfVar4[2] = fVar13;
        pfVar4[3] = fVar17;
        pfVar4[4] = fVar18;
        pfVar4[5] = fVar13;
        pfVar4[6] = fVar17;
        pfVar4[7] = fVar12;
        pfVar4[8] = fVar13;
        pfVar4[9] = fVar14;
        pfVar4[10] = fVar12;
        pfVar4[0xb] = fVar13;
        uVar8 = uVar8 + 0xc & 0xffff;
      } while (uVar8 < (uint)uVar2 * 0xc);
    }
    pMVar6 = *(Mesh **)(param_4 + 0x10);
    if (*(int *)(pMVar6 + 0x30) == 0) {
      MeshDraw(param_1,pMVar6);
    }
    else {
      ArrayAddCached<AbyssEngine::Mesh*>(pMVar6,(Array *)(*(int *)(pMVar6 + 0x30) + 0x44));
      ArrayAddCached<AbyssEngine::AEMath::Matrix>
                (*(undefined4 *)param_2,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                 *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
                 *(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),
                 *(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x20),
                 *(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x28),
                 *(undefined4 *)(param_2 + 0x2c),*(undefined4 *)(param_2 + 0x30),
                 *(undefined4 *)(param_2 + 0x34),*(undefined4 *)(param_2 + 0x38),
                 *(int *)(*(int *)(param_4 + 0x10) + 0x30) + 0x2c);
      ArrayAddCached<AbyssEngine::AEMath::Matrix>
                (0x3f800000,0,0,0,0,0xbf800000,0,0,0,0,0x3f800000,0,0x3f800000,0x3f800000,0x3f800000
                 ,*(int *)(*(int *)(param_4 + 0x10) + 0x30) + 0x38);
      ArrayAddCached<AbyssEngine::AEMath::Matrix>
                (*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),*(undefined4 *)(param_3 + 8),
                 *(undefined4 *)(param_3 + 0xc),*(undefined4 *)(param_3 + 0x10),
                 *(undefined4 *)(param_3 + 0x14),*(undefined4 *)(param_3 + 0x18),
                 *(undefined4 *)(param_3 + 0x1c),*(undefined4 *)(param_3 + 0x20),
                 *(undefined4 *)(param_3 + 0x24),*(undefined4 *)(param_3 + 0x28),
                 *(undefined4 *)(param_3 + 0x2c),*(undefined4 *)(param_3 + 0x30),
                 *(undefined4 *)(param_3 + 0x34),*(undefined4 *)(param_3 + 0x38),
                 *(int *)(*(int *)(param_4 + 0x10) + 0x30) + 0x5c);
      ArrayAddCached<unsigned_int>
                (0xffffffff,(Array *)(*(int *)(*(int *)(param_4 + 0x10) + 0x30) + 0x50));
    }
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::SpriteSystemRelease  @0x00092044  (70 bytes)
/* AbyssEngine::SpriteSystemRelease(AbyssEngine::Engine*, AbyssEngine::SpriteSystem**) */

void AbyssEngine::SpriteSystemRelease(Engine *param_1,SpriteSystem **param_2)

{
  SpriteSystem *pSVar1;
  
  pSVar1 = *param_2;
  if (pSVar1 != (SpriteSystem *)0x0) {
    if (*(void **)(pSVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(pSVar1 + 4));
      pSVar1 = *param_2;
    }
    *(undefined4 *)(pSVar1 + 4) = 0;
    pSVar1 = *param_2;
    if (*(void **)(pSVar1 + 8) != (void *)0x0) {
      operator_delete__(*(void **)(pSVar1 + 8));
      pSVar1 = *param_2;
    }
    *(undefined4 *)(pSVar1 + 8) = 0;
    MeshRelease(param_1,(Mesh **)(*param_2 + 0x10));
    if (*param_2 != (SpriteSystem *)0x0) {
      operator_delete(*param_2);
    }
    *param_2 = (SpriteSystem *)0x0;
  }
  return;
}

// ===== AbyssEngine::MaterialDraw  @0x00092090  (398 bytes)
/* AbyssEngine::MaterialDraw(AbyssEngine::PaintCanvas*, AbyssEngine::Engine*,
   AbyssEngine::Material*, bool) */

void AbyssEngine::MaterialDraw(PaintCanvas *param_1,Engine *param_2,Material *param_3,bool param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint in_fpscr;
  uint uVar4;
  float fVar5;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar6;
  float extraout_s3;
  uint uVar7;
  double dVar8;
  double dVar9;
  AEMath aAStack_88 [60];
  int local_4c;
  
  local_4c = __stack_chk_guard;
  if (param_1 != (PaintCanvas *)0x0 && param_3 != (Material *)0x0) {
    if (param_4) {
      Engine::SetTexturesExt
                ((uint)param_2,*(undefined4 *)param_3,*(undefined4 *)(param_3 + 4),
                 *(undefined4 *)(param_3 + 8),0xffffffff);
    }
    Engine::SetAddData(param_2,*(void **)(param_3 + 0x24),*(int *)(param_3 + 0x28));
    fVar5 = *(float *)(param_3 + 0x68);
    uVar4 = in_fpscr & 0xfffffff | (uint)(fVar5 == -10.0) << 0x1e;
    if ((byte)(uVar4 >> 0x1e) == 0) {
      uVar7 = *(uint *)(param_2 + 600);
      Engine::LightSetLightColorAmbient(param_2,fVar5,extraout_s1,extraout_s2,(uint)fVar5);
      fVar5 = extraout_s1_00;
      fVar6 = extraout_s2_00;
    }
    else {
      uVar7 = 0;
      fVar5 = extraout_s1;
      fVar6 = extraout_s2;
    }
    if (*(int *)(param_3 + 0x44) != 0) {
      iVar3 = 0;
      uVar2 = 0;
      do {
        AEMath::operator*(aAStack_88,(Matrix *)(*(int *)(param_3 + 0x60) + iVar3),
                          (Matrix *)(*(int *)(param_3 + 0x30) + iVar3));
        PaintCanvas::SetWorldViewMatrix(param_1);
        Engine::SetModelMatrix(param_2,(Matrix *)(*(int *)(param_3 + 0x30) + iVar3));
        Engine::SetUVMatrix(param_2,(Matrix *)(*(int *)(param_3 + 0x3c) + iVar3));
        uVar1 = *(uint *)(*(int *)(param_3 + 0x54) + uVar2 * 4);
        VectorUnsignedToFloat(uVar1 >> 0x18,(byte)(uVar4 >> 0x16) & 3);
        dVar8 = (double)VectorUnsignedToFloat((uVar1 & 0xffffff) >> 0x10,(byte)(uVar4 >> 0x16) & 3);
        VectorUnsignedToFloat((uVar1 & 0xffff) >> 8,(byte)(uVar4 >> 0x16) & 3);
        dVar9 = (double)VectorUnsignedToFloat(uVar1 & 0xff,(byte)(uVar4 >> 0x16) & 3);
        Engine::SetColor(param_2,(float)(dVar9 / 255.0),extraout_s1_01,(float)(dVar8 / 255.0),
                         extraout_s3);
        MeshDraw(param_2,*(Mesh **)(*(int *)(param_3 + 0x48) + uVar2 * 4));
        iVar3 = iVar3 + 0x3c;
        uVar2 = uVar2 + 1;
        fVar5 = extraout_s1_02;
        fVar6 = extraout_s2_01;
      } while (uVar2 < *(uint *)(param_3 + 0x44));
    }
    if (*(float *)(param_3 + 0x68) != -10.0) {
      Engine::LightSetLightColorAmbient(param_2,*(float *)(param_3 + 0x68),fVar5,fVar6,uVar7);
    }
    *(undefined4 *)(param_3 + 0x5c) = 0;
    *(undefined4 *)(param_3 + 0x2c) = 0;
    *(undefined4 *)(param_3 + 0x38) = 0;
    *(undefined4 *)(param_3 + 0x44) = 0;
    *(undefined4 *)(param_3 + 0x50) = 0;
  }
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

