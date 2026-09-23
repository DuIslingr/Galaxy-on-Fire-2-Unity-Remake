// Class: SimpleMeshMerger
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== SimpleMeshMerger::SimpleMeshMerger  @0x001b17a0  (724 bytes)
/* SimpleMeshMerger::SimpleMeshMerger(Array<unsigned short> const&,
   Array<AbyssEngine::AEMath::Matrix>, AbyssEngine::PaintCanvas*, unsigned short) */

void __thiscall
SimpleMeshMerger::SimpleMeshMerger
          (SimpleMeshMerger *this,uint *param_1,undefined4 *param_3,PaintCanvas *param_4,
          undefined4 param_5)

{
  int *piVar1;
  byte bVar2;
  short sVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  SimpleMeshMerger *pSVar6;
  byte *pbVar7;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  int iVar11;
  short sVar12;
  int iVar13;
  uint uVar14;
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
  AEMath aAStack_40 [12];
  uint local_34;
  float local_30;
  float local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar4 = operator_new__(4);
  *(undefined4 **)(this + 0xc) = puVar4;
  *(undefined4 *)(this + 0x10) = 1;
  *puVar4 = 0;
  *(undefined4 *)(this + 8) = 0;
  *(PaintCanvas **)(this + 0x14) = param_4;
  *(short *)(this + 4) = (short)param_5;
  *(undefined4 *)this = *param_3;
  ArraySetLength<AbyssEngine::Mesh*>(*param_1,(Array *)(this + 8));
  if (*param_1 == 0) {
    puVar4 = *(undefined4 **)(this + 0xc);
    sVar12 = 0;
    uVar9 = 0;
  }
  else {
    sVar12 = 0;
    uVar14 = 0;
    iVar10 = 0;
    do {
      AbyssEngine::PaintCanvas::MeshCreate
                (param_4,*(ushort *)(param_1[1] + uVar14 * 2),&local_34,false);
      uVar5 = AbyssEngine::PaintCanvas::MeshGetPointer(param_4,local_34);
      *(undefined4 *)(*(int *)(this + 0xc) + uVar14 * 4) = uVar5;
      puVar4 = *(undefined4 **)(this + 0xc);
      piVar1 = puVar4 + uVar14;
      uVar14 = uVar14 + 1;
      sVar12 = sVar12 + *(short *)(*piVar1 + 2);
      iVar10 = iVar10 + *(ushort *)(*piVar1 + 0x28) / 3;
      uVar9 = (undefined2)iVar10;
    } while (uVar14 < *param_1);
  }
  pSVar6 = this + 0x18;
  AbyssEngine::PaintCanvas::MeshCreate(param_4,sVar12,uVar9,(int)*(char *)*puVar4,param_5,pSVar6);
  if (*param_1 != 0) {
    iVar10 = *(int *)(this + 0xc);
    uVar14 = 0;
    iVar15 = 0;
    sVar12 = 0;
    fVar18 = extraout_s1;
    fVar19 = extraout_s3;
    do {
      pbVar7 = *(byte **)(iVar10 + uVar14 * 4);
      if (*(short *)(pbVar7 + 2) != 0) {
        iVar16 = 0;
        iVar17 = 4;
        iVar11 = 8;
        iVar13 = 0;
        do {
          bVar2 = *pbVar7;
          sVar3 = (short)iVar13;
          if ((bVar2 & 1) != 0) {
            AbyssEngine::AEMath::MatrixTransformVector
                      ((AEMath *)&local_34,(Matrix *)(param_3[1] + uVar14 * 0x3c),
                       (Vector *)(*(int *)(pbVar7 + 4) + iVar16));
            AbyssEngine::PaintCanvas::MeshSetPoint
                      (param_4,*(uint *)pSVar6,sVar12 + sVar3,local_30,extraout_s1_00,local_2c);
            iVar10 = *(int *)(this + 0xc);
            pbVar7 = *(byte **)(iVar10 + uVar14 * 4);
            bVar2 = *pbVar7;
            fVar18 = extraout_s1_01;
            fVar19 = extraout_s3_00;
          }
          if ((bVar2 & 4) != 0) {
            AbyssEngine::AEMath::MatrixRotateVector
                      (aAStack_40,(Matrix *)(param_3[1] + uVar14 * 0x3c),
                       (Vector *)(*(int *)(pbVar7 + 0x10) + iVar16));
            AbyssEngine::PaintCanvas::MeshSetNormal
                      (param_4,*(uint *)pSVar6,sVar12 + sVar3,(Vector *)aAStack_40);
            iVar10 = *(int *)(this + 0xc);
            pbVar7 = *(byte **)(iVar10 + uVar14 * 4);
            bVar2 = *pbVar7;
            fVar18 = extraout_s1_02;
            fVar19 = extraout_s3_01;
          }
          if ((bVar2 & 2) != 0) {
            AbyssEngine::PaintCanvas::MeshSetUv
                      (param_4,*(uint *)pSVar6,sVar12 + sVar3,
                       *(float *)(*(int *)(pbVar7 + 8) + iVar17),fVar18);
            iVar10 = *(int *)(this + 0xc);
            pbVar7 = *(byte **)(iVar10 + uVar14 * 4);
            bVar2 = *pbVar7;
            fVar18 = extraout_s1_03;
            fVar19 = extraout_s3_02;
          }
          if ((bVar2 & 8) != 0) {
            AbyssEngine::PaintCanvas::MeshSetColor
                      (param_4,*(uint *)pSVar6,sVar12 + sVar3,
                       ((float *)(*(int *)(pbVar7 + 0xc) + iVar11))[-1],fVar18,
                       *(float *)(*(int *)(pbVar7 + 0xc) + iVar11),fVar19);
            iVar10 = *(int *)(this + 0xc);
            pbVar7 = *(byte **)(iVar10 + uVar14 * 4);
            fVar18 = extraout_s1_04;
            fVar19 = extraout_s3_03;
          }
          iVar11 = iVar11 + 0x10;
          iVar17 = iVar17 + 8;
          iVar16 = iVar16 + 0xc;
          iVar13 = iVar13 + 1;
        } while (iVar13 < (int)(uint)*(ushort *)(pbVar7 + 2));
      }
      uVar8 = (uint)*(ushort *)(pbVar7 + 0x28);
      if (2 < uVar8) {
        iVar11 = 0;
        iVar13 = 0;
        do {
          if ((*pbVar7 & 0x10) != 0) {
            iVar10 = *(int *)(pbVar7 + 0x2c) + iVar11;
            AbyssEngine::PaintCanvas::MeshSetTriangle
                      (param_4,*(uint *)pSVar6,(short)iVar15 + (short)iVar13,
                       *(short *)(*(int *)(pbVar7 + 0x2c) + iVar11) + sVar12,
                       *(short *)(iVar10 + 2) + sVar12,*(short *)(iVar10 + 4) + sVar12);
            iVar10 = *(int *)(this + 0xc);
            fVar18 = extraout_s1_05;
            fVar19 = extraout_s3_04;
          }
          pbVar7 = *(byte **)(iVar10 + uVar14 * 4);
          iVar13 = iVar13 + 1;
          iVar11 = iVar11 + 6;
        } while (iVar13 < (int)(uVar8 / 3));
        uVar8 = (uint)*(ushort *)(pbVar7 + 0x28);
      }
      uVar14 = uVar14 + 1;
      sVar12 = sVar12 + *(short *)(pbVar7 + 2);
      iVar15 = iVar15 + uVar8 / 3;
    } while (uVar14 < *param_1);
  }
  AbyssEngine::PaintCanvas::TransformCreate(param_4,(uint *)(this + 0x1c));
  AbyssEngine::PaintCanvas::TransformAddMeshId(param_4,*(uint *)(this + 0x1c),*(uint *)pSVar6);
  this[6] = (SimpleMeshMerger)0x1;
  if (__stack_chk_guard - local_28 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_28);
}

