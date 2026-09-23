// Class: MeshMerger
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MeshMerger::MeshMerger  @0x001a24d0  (726 bytes)
/* MeshMerger::MeshMerger(Array<unsigned short> const&, Array<AbyssEngine::AEMath::Matrix>,
   AbyssEngine::PaintCanvas*, unsigned short) */

void __thiscall
MeshMerger::MeshMerger
          (MeshMerger *this,uint *param_1,undefined4 *param_3,PaintCanvas *param_4,
          undefined4 param_5)

{
  int *piVar1;
  byte bVar2;
  longlong lVar3;
  short sVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  byte *pbVar8;
  uint uVar9;
  short sVar10;
  int iVar11;
  undefined2 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float fVar18;
  float extraout_s1_05;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s3_01;
  float extraout_s3_02;
  float extraout_s3_03;
  float fVar19;
  float extraout_s3_04;
  uint local_34;
  float local_30;
  float local_2c;
  int local_28;
  
  sVar10 = 0;
  local_28 = __stack_chk_guard;
  *(PaintCanvas **)(this + 0xc) = param_4;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x30) = 1;
  *(short *)(this + 4) = (short)param_5;
  *(undefined4 *)this = *param_3;
  uVar9 = *param_1;
  lVar3 = (ulonglong)uVar9 * 4;
  uVar5 = (uint)lVar3;
  if ((int)((ulonglong)lVar3 >> 0x20) != 0) {
    uVar5 = 0xffffffff;
  }
  puVar6 = operator_new__(uVar5);
  *(undefined4 **)(this + 8) = puVar6;
  if (uVar9 == 0) {
    uVar12 = 0;
  }
  else {
    sVar10 = 0;
    uVar5 = 0;
    iVar13 = 0;
    do {
      AbyssEngine::PaintCanvas::MeshCreate
                (param_4,*(ushort *)(param_1[1] + uVar5 * 2),&local_34,false);
      uVar7 = AbyssEngine::PaintCanvas::MeshGetPointer(param_4,local_34);
      *(undefined4 *)(*(int *)(this + 8) + uVar5 * 4) = uVar7;
      puVar6 = *(undefined4 **)(this + 8);
      piVar1 = puVar6 + uVar5;
      uVar5 = uVar5 + 1;
      sVar10 = sVar10 + *(short *)(*piVar1 + 2);
      iVar13 = iVar13 + *(ushort *)(*piVar1 + 0x28) / 3;
      uVar12 = (undefined2)iVar13;
    } while (uVar5 < *param_1);
  }
  AbyssEngine::PaintCanvas::MeshCreate
            (param_4,sVar10,uVar12,(int)*(char *)*puVar6,param_5,this + 0x10);
  if (*param_1 != 0) {
    iVar13 = *(int *)(this + 8);
    uVar5 = 0;
    iVar15 = 0;
    sVar10 = 0;
    fVar18 = extraout_s1;
    fVar19 = extraout_s3;
    do {
      pbVar8 = *(byte **)(iVar13 + uVar5 * 4);
      if (*(short *)(pbVar8 + 2) != 0) {
        iVar17 = 0;
        iVar14 = 4;
        iVar16 = 8;
        iVar11 = 0;
        do {
          bVar2 = *pbVar8;
          sVar4 = (short)iVar11;
          if ((bVar2 & 1) != 0) {
            AbyssEngine::AEMath::MatrixTransformVector
                      ((AEMath *)&local_34,(Matrix *)(param_3[1] + uVar5 * 0x3c),
                       (Vector *)(*(int *)(pbVar8 + 4) + iVar17));
            AbyssEngine::PaintCanvas::MeshSetPoint
                      (param_4,*(uint *)(this + 0x10),sVar10 + sVar4,local_30,extraout_s1_00,
                       local_2c);
            iVar13 = *(int *)(this + 8);
            pbVar8 = *(byte **)(iVar13 + uVar5 * 4);
            bVar2 = *pbVar8;
            fVar18 = extraout_s1_01;
            fVar19 = extraout_s3_00;
          }
          if ((bVar2 & 4) != 0) {
            AbyssEngine::AEMath::MatrixRotateVector
                      ((AEMath *)&local_34,(Matrix *)(param_3[1] + uVar5 * 0x3c),
                       (Vector *)(*(int *)(pbVar8 + 0x10) + iVar17));
            AbyssEngine::PaintCanvas::MeshSetNormal
                      (param_4,*(uint *)(this + 0x10),sVar10 + sVar4,(Vector *)&local_34);
            iVar13 = *(int *)(this + 8);
            pbVar8 = *(byte **)(iVar13 + uVar5 * 4);
            bVar2 = *pbVar8;
            fVar18 = extraout_s1_02;
            fVar19 = extraout_s3_01;
          }
          if ((bVar2 & 2) != 0) {
            AbyssEngine::PaintCanvas::MeshSetUv
                      (param_4,*(uint *)(this + 0x10),sVar10 + sVar4,
                       *(float *)(*(int *)(pbVar8 + 8) + iVar14),fVar18);
            iVar13 = *(int *)(this + 8);
            pbVar8 = *(byte **)(iVar13 + uVar5 * 4);
            bVar2 = *pbVar8;
            fVar18 = extraout_s1_03;
            fVar19 = extraout_s3_02;
          }
          if ((bVar2 & 8) != 0) {
            AbyssEngine::PaintCanvas::MeshSetColor
                      (param_4,*(uint *)(this + 0x10),sVar10 + sVar4,
                       ((float *)(*(int *)(pbVar8 + 0xc) + iVar16))[-1],fVar18,
                       *(float *)(*(int *)(pbVar8 + 0xc) + iVar16),fVar19);
            iVar13 = *(int *)(this + 8);
            pbVar8 = *(byte **)(iVar13 + uVar5 * 4);
            fVar18 = extraout_s1_04;
            fVar19 = extraout_s3_03;
          }
          iVar16 = iVar16 + 0x10;
          iVar14 = iVar14 + 8;
          iVar17 = iVar17 + 0xc;
          iVar11 = iVar11 + 1;
        } while (iVar11 < (int)(uint)*(ushort *)(pbVar8 + 2));
      }
      uVar9 = (uint)*(ushort *)(pbVar8 + 0x28);
      if (2 < uVar9) {
        iVar14 = 0;
        iVar11 = 0;
        do {
          if ((*pbVar8 & 0x10) != 0) {
            iVar13 = *(int *)(pbVar8 + 0x2c) + iVar14;
            AbyssEngine::PaintCanvas::MeshSetTriangle
                      (param_4,*(uint *)(this + 0x10),(short)iVar15 + (short)iVar11,
                       *(short *)(*(int *)(pbVar8 + 0x2c) + iVar14) + sVar10,
                       *(short *)(iVar13 + 2) + sVar10,*(short *)(iVar13 + 4) + sVar10);
            iVar13 = *(int *)(this + 8);
            fVar18 = extraout_s1_05;
            fVar19 = extraout_s3_04;
          }
          pbVar8 = *(byte **)(iVar13 + uVar5 * 4);
          iVar11 = iVar11 + 1;
          iVar14 = iVar14 + 6;
        } while (iVar11 < (int)(uVar9 / 3));
        uVar9 = (uint)*(ushort *)(pbVar8 + 0x28);
      }
      uVar5 = uVar5 + 1;
      sVar10 = sVar10 + *(short *)(pbVar8 + 2);
      iVar15 = iVar15 + uVar9 / 3;
    } while (uVar5 < *param_1);
  }
  AbyssEngine::PaintCanvas::TransformCreate(param_4,(uint *)(this + 0x14));
  AbyssEngine::PaintCanvas::TransformAddMeshId
            (param_4,*(uint *)(this + 0x14),*(uint *)(this + 0x10));
  this[6] = (MeshMerger)0x1;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  this[0x34] = (MeshMerger)0x0;
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== MeshMerger::MeshMerger  @0x001a27b0  (428 bytes)
/* MeshMerger::MeshMerger(int, int, AbyssEngine::PaintCanvas*, unsigned short) */

void __thiscall
MeshMerger::MeshMerger(MeshMerger *this,int param_1,int param_2,PaintCanvas *param_3,ushort param_4)

{
  longlong lVar1;
  void *pvVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_88 [5];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  int local_4c;
  
  lVar1 = (ulonglong)(uint)(param_2 * param_1) * 4;
  uVar4 = (uint)lVar1;
  local_4c = __stack_chk_guard;
  *(PaintCanvas **)(this + 0xc) = param_3;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(int *)this = param_1;
  *(int *)(this + 0x30) = param_2;
  if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
    uVar4 = 0xffffffff;
  }
  pvVar2 = operator_new__(uVar4);
  iVar7 = param_2 * param_1 * 4;
  *(void **)(this + 8) = pvVar2;
  __aeabi_memclr4(pvVar2,iVar7);
  pvVar2 = operator_new__(uVar4);
  *(void **)(this + 0x18) = pvVar2;
  __aeabi_memclr4(pvVar2,iVar7);
  uVar4 = param_1;
  if (0x7fffffff < (uint)param_1) {
    uVar4 = 0xffffffff;
  }
  pvVar2 = operator_new__(uVar4);
  *(void **)(this + 0x24) = pvVar2;
  __aeabi_memclr(pvVar2,param_1);
  uVar4 = (uint)((ulonglong)(uint)param_1 * 0x3c);
  if ((int)((ulonglong)(uint)param_1 * 0x3c >> 0x20) != 0) {
    uVar4 = 0xffffffff;
  }
  puVar3 = operator_new__(uVar4);
  if (param_1 == 0) {
    uVar4 = 0;
    *(undefined4 **)(this + 0x1c) = puVar3;
  }
  else {
    puVar5 = puVar3;
    do {
      *puVar5 = 0x3f800000;
      puVar5[1] = 0;
      puVar5[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      puVar5[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      puVar5[4] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar5[5] = 0x3f800000;
      puVar5[6] = 0;
      puVar5[7] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      puVar5[8] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      puVar5[9] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      *(undefined8 *)(puVar5 + 10) = 0x3f800000;
      *(undefined8 *)(puVar5 + 0xc) = 0x3f8000003f800000;
      puVar5[0xe] = 0x3f800000;
      puVar5 = puVar5 + 0xf;
    } while (puVar5 != puVar3 + param_1 * 0xf);
    uVar4 = *(uint *)this;
    *(undefined4 **)(this + 0x1c) = puVar3;
    if (0 < (int)uVar4) {
      uVar9 = 0;
      uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar5 = (undefined4 *)((uint)local_88 | 4);
      iVar7 = 0;
      iVar8 = 0;
      while( true ) {
        local_88[0] = 0x3f800000;
        *puVar5 = uVar9;
        puVar5[1] = uVar10;
        puVar5[2] = uVar11;
        puVar5[3] = uVar12;
        local_74 = 0x3f800000;
        local_60 = 0x3f800000;
        uStack_58 = 0x3f8000003f800000;
        local_50 = 0x3f800000;
        local_70 = uVar9;
        uStack_6c = uVar10;
        uStack_68 = uVar11;
        uStack_64 = uVar12;
        AbyssEngine::AEMath::Matrix::operator=((Matrix *)((int)puVar3 + iVar7),(Matrix *)local_88);
        uVar4 = *(uint *)this;
        iVar8 = iVar8 + 1;
        if ((int)uVar4 <= iVar8) break;
        iVar7 = iVar7 + 0x3c;
        puVar3 = *(undefined4 **)(this + 0x1c);
      }
    }
  }
  uVar6 = uVar4;
  if (0x7fffffff < uVar4) {
    uVar6 = 0xffffffff;
  }
  pvVar2 = operator_new__(uVar6);
  *(void **)(this + 0x28) = pvVar2;
  if ((int)uVar4 < 1) {
    pvVar2 = operator_new__(uVar6);
    *(void **)(this + 0x2c) = pvVar2;
  }
  else {
    __aeabi_memset(pvVar2,uVar4,1);
    pvVar2 = operator_new__(uVar6);
    *(void **)(this + 0x2c) = pvVar2;
    pvVar2 = (void *)__aeabi_memset(pvVar2,uVar4,1);
  }
  *(ushort *)(this + 4) = param_4;
  this[0x34] = (MeshMerger)0x0;
  this[6] = (MeshMerger)0x0;
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pvVar2);
  }
  return;
}

// ===== MeshMerger::setMesh  @0x001a2980  (76 bytes)
/* MeshMerger::setMesh(int, signed char, unsigned short) */

void __thiscall MeshMerger::setMesh(MeshMerger *this,int param_1,int param_3,ushort param_4)

{
  undefined4 uVar1;
  uint local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::MeshCreate(*(PaintCanvas **)(this + 0xc),param_4,&local_1c,false);
  uVar1 = AbyssEngine::PaintCanvas::MeshGetPointer(*(PaintCanvas **)(this + 0xc),local_1c);
  *(undefined4 *)(*(int *)(this + 8) + (*(int *)this * param_3 + param_1) * 4) = uVar1;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MeshMerger::setLod  @0x001a29d4  (38 bytes)
/* MeshMerger::setLod(int, signed char) */

void __thiscall MeshMerger::setLod(MeshMerger *this,int param_1,char param_3)

{
  if (*(char *)(*(int *)(this + 0x24) + param_1) != param_3) {
    *(char *)(*(int *)(this + 0x24) + param_1) = param_3;
    if (*(char *)(*(int *)(this + 0x28) + param_1) == '\0') {
      return;
    }
    this[0x34] = (MeshMerger)0x1;
  }
  return;
}

// ===== MeshMerger::setMatrix  @0x001a29fa  (16 bytes)
/* MeshMerger::setMatrix(int, AbyssEngine::AEMath::Matrix const&) */

void __thiscall MeshMerger::setMatrix(MeshMerger *this,int param_1,Matrix *param_2)

{
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(*(int *)(this + 0x1c) + param_1 * 0x3c),param_2)
  ;
  return;
}

// ===== MeshMerger::setEnabled  @0x001a2a0a  (34 bytes)
/* MeshMerger::setEnabled(int, bool) */

void __thiscall MeshMerger::setEnabled(MeshMerger *this,int param_1,bool param_2)

{
  if ((bool)*(char *)(*(int *)(this + 0x28) + param_1) != param_2) {
    *(bool *)(*(int *)(this + 0x28) + param_1) = param_2;
    if (*(char *)(*(int *)(this + 0x2c) + param_1) == '\0') {
      return;
    }
    this[0x34] = (MeshMerger)0x1;
  }
  return;
}

// ===== MeshMerger::init  @0x001a2a2c  (248 bytes)
/* MeshMerger::init() */

void __thiscall MeshMerger::init(MeshMerger *this)

{
  int *piVar1;
  Mesh *pMVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  undefined4 *puVar10;
  
  if (this[6] != (MeshMerger)0x0) {
    return;
  }
  if (0 < *(int *)this) {
    iVar9 = 0;
    do {
      iVar4 = (int)*(char *)(*(int *)(this + 0x24) + iVar9);
      if ((iVar4 < -1) || (iVar6 = *(int *)(this + 0x30), iVar6 <= iVar4)) {
        *(undefined1 *)(*(int *)(this + 0x24) + iVar9) = 0;
        iVar6 = *(int *)(this + 0x30);
      }
      iVar4 = *(int *)this;
      if (0 < iVar6) {
        iVar7 = 0;
        do {
          pMVar2 = *(Mesh **)(*(int *)(this + 8) + (iVar4 * iVar7 + iVar9) * 4);
          if (pMVar2 != (Mesh *)0x0) {
            uVar3 = transformMesh(pMVar2,(Matrix *)(*(int *)(this + 0x1c) + iVar9 * 0x3c));
            iVar4 = *(int *)this;
            *(undefined4 *)(*(int *)(this + 0x18) + (iVar4 * iVar7 + iVar9) * 4) = uVar3;
            iVar6 = *(int *)(this + 0x30);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar6);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar4);
    if (0 < iVar4) {
      puVar10 = *(undefined4 **)(this + 8);
      iVar6 = 0;
      iVar9 = 0;
      sVar8 = 0;
      do {
        piVar1 = puVar10 + iVar6;
        iVar6 = iVar6 + 1;
        sVar8 = sVar8 + *(short *)(*piVar1 + 2);
        iVar9 = iVar9 + *(ushort *)(*piVar1 + 0x28) / 3;
        uVar5 = (undefined2)iVar9;
      } while (iVar6 < iVar4);
      goto LAB_001a2ad6;
    }
  }
  puVar10 = *(undefined4 **)(this + 8);
  uVar5 = 0;
  sVar8 = 0;
LAB_001a2ad6:
  AbyssEngine::PaintCanvas::MeshCreate
            (*(PaintCanvas **)(this + 0xc),sVar8,uVar5,(int)*(char *)*puVar10,
             *(undefined2 *)(this + 4),this + 0x10);
  uVar3 = AbyssEngine::PaintCanvas::MeshGetPointer
                    (*(PaintCanvas **)(this + 0xc),*(uint *)(this + 0x10));
  *(undefined4 *)(this + 0x20) = uVar3;
  AbyssEngine::PaintCanvas::TransformCreate(*(PaintCanvas **)(this + 0xc),(uint *)(this + 0x14));
  AbyssEngine::PaintCanvas::TransformAddMeshId
            (*(PaintCanvas **)(this + 0xc),*(uint *)(this + 0x14),*(uint *)(this + 0x10));
  this[0x34] = (MeshMerger)0x1;
  update();
  return;
}

// ===== MeshMerger::transformMesh  @0x001a2b24  (412 bytes)
/* MeshMerger::transformMesh(AbyssEngine::Mesh*, AbyssEngine::AEMath::Matrix const&) */

void MeshMerger::transformMesh(Mesh *param_1,Matrix *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined8 local_38;
  undefined4 local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar4 = operator_new(0x88);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(puVar4 + 0x3c) = 0;
  *(undefined4 *)(puVar4 + 0x40) = uVar1;
  *(undefined4 *)(puVar4 + 0x44) = uVar2;
  *(undefined4 *)(puVar4 + 0x48) = uVar3;
  *(undefined4 *)(puVar4 + 0x14) = 0;
  *(undefined4 *)(puVar4 + 0x18) = uVar1;
  *(undefined4 *)(puVar4 + 0x1c) = uVar2;
  *(undefined4 *)(puVar4 + 0x20) = uVar3;
  *(undefined4 *)(puVar4 + 4) = 0;
  *(undefined4 *)(puVar4 + 8) = uVar1;
  *(undefined4 *)(puVar4 + 0xc) = uVar2;
  *(undefined4 *)(puVar4 + 0x10) = uVar3;
  *(undefined4 *)(puVar4 + 0x28) = 0;
  *(undefined4 *)(puVar4 + 0x2c) = uVar1;
  *(undefined4 *)(puVar4 + 0x30) = uVar2;
  *(undefined4 *)(puVar4 + 0x34) = uVar3;
  puVar4[0x38] = 0;
  *(undefined4 *)(puVar4 + 0x4c) = 0x3f800000;
  *(undefined4 *)(puVar4 + 0x50) = 0;
  *(undefined4 *)(puVar4 + 0x54) = 0;
  *(undefined4 *)(puVar4 + 0x59) = 0;
  *(undefined4 *)(puVar4 + 0x55) = 0;
  *(undefined4 *)(puVar4 + 0x70) = 0;
  *(undefined4 *)(puVar4 + 0x74) = uVar1;
  *(undefined4 *)(puVar4 + 0x78) = uVar2;
  *(undefined4 *)(puVar4 + 0x7c) = uVar3;
  *(undefined4 *)(puVar4 + 0x60) = 0;
  *(undefined4 *)(puVar4 + 100) = uVar1;
  *(undefined4 *)(puVar4 + 0x68) = uVar2;
  *(undefined4 *)(puVar4 + 0x6c) = uVar3;
  *(undefined4 *)(puVar4 + 0x82) = 0;
  *(undefined4 *)(puVar4 + 0x7e) = 0;
  *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(puVar4 + 0x28) = *(undefined2 *)(param_1 + 0x28);
  uVar7 = *(uint *)param_1;
  *puVar4 = (char)uVar7;
  if ((uVar7 & 2) != 0) {
    *(undefined4 *)(puVar4 + 8) = *(undefined4 *)(param_1 + 8);
  }
  uVar9 = uVar7 >> 0x10;
  if ((uVar7 & 8) != 0) {
    *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)(param_1 + 0xc);
  }
  if ((uVar7 & 0x10) != 0) {
    *(undefined4 *)(puVar4 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  }
  if ((uVar7 & 1) != 0) {
    pvVar5 = operator_new__(uVar9 * 0xc);
    *(void **)(puVar4 + 4) = pvVar5;
    if (uVar9 == 0) {
      uVar9 = 0;
    }
    else {
      iVar6 = 0;
      iVar8 = 0;
      do {
        AbyssEngine::AEMath::MatrixTransformVector
                  ((AEMath *)&local_50,param_2,(Vector *)(*(int *)(param_1 + 4) + iVar6));
        AbyssEngine::AEMath::Vector::operator=
                  ((Vector *)(*(int *)(puVar4 + 4) + iVar6),(Vector *)&local_50);
        iVar6 = iVar6 + 0xc;
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)*(ushort *)(param_1 + 2));
      uVar7 = *(uint *)param_1;
      uVar9 = uVar7 >> 0x10;
    }
  }
  if ((uVar7 & 4) != 0) {
    pvVar5 = operator_new__(uVar9 * 0xc);
    *(void **)(puVar4 + 0x10) = pvVar5;
    if (uVar9 != 0) {
      iVar6 = 0;
      iVar8 = 0;
      do {
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_38,param_2,(Vector *)(*(int *)(param_1 + 0x10) + iVar6));
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_50,(Vector *)&local_38);
        AbyssEngine::AEMath::Vector::operator=
                  ((Vector *)(*(int *)(puVar4 + 0x10) + iVar6),(Vector *)&local_50);
        iVar6 = iVar6 + 0xc;
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)*(ushort *)(param_1 + 2));
    }
  }
  AbyssEngine::AEMath::MatrixTransformVector((AEMath *)&local_38,param_2,(Vector *)(param_1 + 0x3c))
  ;
  local_44 = *(undefined4 *)(param_1 + 0x48);
  local_48 = local_30;
  local_50 = local_38;
  local_40 = 0x3f800000;
  AbyssEngine::AEMath::BSphere::operator=((BSphere *)(puVar4 + 0x3c),(BSphere *)&local_50);
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== MeshMerger::update  @0x001a2cc8  (368 bytes)
/* MeshMerger::update() */

void MeshMerger::update(void)

{
  byte bVar1;
  int *in_r0;
  int iVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  byte *pbVar6;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  float in_s0;
  float extraout_s0;
  
  piVar9 = in_r0 + 0xd;
  iVar2 = *in_r0;
  if (0 < iVar2) {
    iVar7 = 0;
    do {
      uVar3 = AbyssEngine::PaintCanvas::CameraIsSphereinViewFrustum
                        ((PaintCanvas *)in_r0[3],(Vector *)(*(int *)(in_r0[6] + iVar7 * 4) + 0x3c),
                         in_s0);
      if ((uVar3 != *(byte *)(in_r0[0xb] + iVar7)) &&
         (*(char *)(in_r0[0xb] + iVar7) = (char)uVar3, *(char *)(in_r0[10] + iVar7) != '\0')) {
        *(char *)piVar9 = '\x01';
      }
      iVar2 = *in_r0;
      iVar7 = iVar7 + 1;
      in_s0 = extraout_s0;
    } while (iVar7 < iVar2);
  }
  if ((char)*piVar9 != '\0') {
    if (iVar2 < 1) {
      iVar11 = 0;
      iVar7 = 0;
    }
    else {
      piVar10 = in_r0 + 8;
      iVar8 = 0;
      iVar11 = 0;
      iVar7 = 0;
      do {
        if ((*(char *)(in_r0[10] + iVar8) != '\0') && (*(char *)(in_r0[0xb] + iVar8) != '\0')) {
          pbVar6 = (byte *)in_r0[8];
          uVar3 = *(char *)(in_r0[9] + iVar8) * iVar2 + iVar8;
          bVar1 = *pbVar6;
          iVar12 = *(int *)(in_r0[6] + uVar3 * 4);
          if ((bVar1 & 1) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar6 + 4) + iVar7 * 0xc,*(undefined4 *)(iVar12 + 4),
                            (uint)*(ushort *)(iVar12 + 2) * 0xc);
            pbVar6 = (byte *)*piVar10;
            bVar1 = *pbVar6;
            uVar3 = extraout_r3;
          }
          if ((bVar1 & 4) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar6 + 0x10) + iVar7 * 0xc,*(undefined4 *)(iVar12 + 0x10),
                            (uint)*(ushort *)(iVar12 + 2) * 0xc);
            pbVar6 = (byte *)*piVar10;
            bVar1 = *pbVar6;
            uVar3 = extraout_r3_00;
          }
          if ((bVar1 & 8) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar6 + 0xc) + iVar7 * 0x10,*(undefined4 *)(iVar12 + 0xc),
                            (uint)*(ushort *)(iVar12 + 2) << 4);
            pbVar6 = (byte *)*piVar10;
            bVar1 = *pbVar6;
            uVar3 = extraout_r3_01;
          }
          if ((bVar1 & 2) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar6 + 8) + iVar7 * 8,*(undefined4 *)(iVar12 + 8),
                            (uint)*(ushort *)(iVar12 + 2) << 3);
            pbVar6 = (byte *)*piVar10;
            bVar1 = *pbVar6;
            uVar3 = extraout_r3_02;
          }
          bVar13 = (bVar1 & 0x10) != 0;
          if (bVar13) {
            uVar3 = (uint)*(ushort *)(iVar12 + 0x28);
          }
          if (bVar13 && uVar3 != 0) {
            iVar2 = -uVar3;
            psVar4 = *(short **)(iVar12 + 0x2c);
            psVar5 = (short *)(*(int *)(pbVar6 + 0x2c) + iVar11 * 2);
            do {
              iVar2 = iVar2 + 1;
              *psVar5 = *psVar4 + (short)iVar7;
              psVar4 = psVar4 + 1;
              psVar5 = psVar5 + 1;
            } while (iVar2 != 0);
          }
          iVar2 = *in_r0;
          iVar11 = iVar11 + (uint)*(ushort *)(iVar12 + 0x28);
          iVar7 = iVar7 + (uint)*(ushort *)(iVar12 + 2);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar2);
    }
    iVar2 = in_r0[8];
    *(short *)(iVar2 + 2) = (short)iVar7;
    *(short *)(iVar2 + 0x28) = (short)iVar11;
    *(char *)piVar9 = '\0';
  }
  return;
}

// ===== MeshMerger::render  @0x001a2e38  (12 bytes)
/* MeshMerger::render() */

void __thiscall MeshMerger::render(MeshMerger *this)

{
  AbyssEngine::PaintCanvas::DrawTransform
            (*(PaintCanvas **)(this + 0xc),*(uint *)(this + 0x14),(Matrix *)0x0);
  return;
}

// ===== MeshMerger::~MeshMerger  @0x001a2e44  (170 bytes)
/* MeshMerger::~MeshMerger() */

MeshMerger * __thiscall MeshMerger::~MeshMerger(MeshMerger *this)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete__(*(void **)(this + 8));
  }
  *(undefined4 *)(this + 8) = 0;
  pvVar1 = *(void **)(this + 0x18);
  if (0 < *(int *)(this + 0x30) * *(int *)this) {
    iVar4 = 0;
    do {
      iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      if (*(void **)(iVar3 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(iVar3 + 4));
        pvVar1 = *(void **)(this + 0x18);
        iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      }
      *(undefined4 *)(iVar3 + 4) = 0;
      iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      if (*(void **)(iVar3 + 0x10) != (void *)0x0) {
        operator_delete__(*(void **)(iVar3 + 0x10));
        pvVar1 = *(void **)(this + 0x18);
        iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      }
      *(undefined4 *)(iVar3 + 0x10) = 0;
      pvVar2 = *(void **)((int)pvVar1 + iVar4 * 4);
      if (pvVar2 != (void *)0x0) {
        operator_delete(pvVar2);
        pvVar1 = *(void **)(this + 0x18);
      }
      *(undefined4 *)((int)pvVar1 + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
      pvVar1 = *(void **)(this + 0x18);
    } while (iVar4 < *(int *)(this + 0x30) * *(int *)this);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(void **)(this + 0x24) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x24));
  }
  *(undefined4 *)(this + 0x24) = 0;
  if (*(void **)(this + 0x28) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x28));
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(void **)(this + 0x2c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x2c));
  }
  *(undefined4 *)(this + 0x2c) = 0;
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x1c));
  }
  *(undefined4 *)(this + 0x1c) = 0;
  return this;
}

