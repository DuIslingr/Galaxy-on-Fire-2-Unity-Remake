// Class: LodMeshMerger
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== LodMeshMerger::LodMeshMerger  @0x001b1b00  (436 bytes)
/* LodMeshMerger::LodMeshMerger(int, int, AbyssEngine::PaintCanvas*, unsigned short) */

void __thiscall
LodMeshMerger::LodMeshMerger
          (LodMeshMerger *this,int param_1,int param_2,PaintCanvas *param_3,ushort param_4)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
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
  
  local_4c = __stack_chk_guard;
  puVar2 = operator_new__(4);
  *(undefined4 **)(this + 0xc) = puVar2;
  *(undefined4 *)(this + 0x10) = 1;
  *puVar2 = 0;
  *(undefined4 *)(this + 8) = 0;
  *(PaintCanvas **)(this + 0x14) = param_3;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(int *)this = param_1;
  *(int *)(this + 0x38) = param_2;
  ArraySetLength<AbyssEngine::Mesh*>(param_2 * param_1,(Array *)(this + 8));
  uVar6 = *(uint *)this;
  lVar1 = (ulonglong)(uVar6 * param_2) * 4;
  uVar3 = (uint)lVar1;
  if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
    uVar3 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar3);
  *(void **)(this + 0x24) = pvVar4;
  __aeabi_memclr4(pvVar4,uVar6 * param_2 * 4);
  uVar3 = uVar6;
  if (0x7fffffff < uVar6) {
    uVar3 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar3);
  *(void **)(this + 0x2c) = pvVar4;
  __aeabi_memclr(pvVar4,uVar6);
  uVar3 = (uint)((ulonglong)uVar6 * 0x3c);
  if ((int)((ulonglong)uVar6 * 0x3c >> 0x20) != 0) {
    uVar3 = 0xffffffff;
  }
  puVar2 = operator_new__(uVar3);
  if (uVar6 == 0) {
    uVar3 = 0;
    *(undefined4 **)(this + 0x28) = puVar2;
  }
  else {
    puVar7 = puVar2;
    do {
      *puVar7 = 0x3f800000;
      puVar7[1] = 0;
      puVar7[2] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      puVar7[3] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      puVar7[4] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar7[5] = 0x3f800000;
      puVar7[6] = 0;
      puVar7[7] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      puVar7[8] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      puVar7[9] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      *(undefined8 *)(puVar7 + 10) = 0x3f800000;
      *(undefined8 *)(puVar7 + 0xc) = 0x3f8000003f800000;
      puVar7[0xe] = 0x3f800000;
      puVar7 = puVar7 + 0xf;
    } while (puVar7 != puVar2 + uVar6 * 0xf);
    uVar3 = *(uint *)this;
    *(undefined4 **)(this + 0x28) = puVar2;
    if (0 < (int)uVar3) {
      uVar9 = 0;
      uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar7 = (undefined4 *)((uint)local_88 | 4);
      iVar5 = 0;
      iVar8 = 0;
      while( true ) {
        local_88[0] = 0x3f800000;
        *puVar7 = uVar9;
        puVar7[1] = uVar10;
        puVar7[2] = uVar11;
        puVar7[3] = uVar12;
        local_74 = 0x3f800000;
        local_60 = 0x3f800000;
        uStack_58 = 0x3f8000003f800000;
        local_50 = 0x3f800000;
        local_70 = uVar9;
        uStack_6c = uVar10;
        uStack_68 = uVar11;
        uStack_64 = uVar12;
        AbyssEngine::AEMath::Matrix::operator=((Matrix *)((int)puVar2 + iVar5),(Matrix *)local_88);
        iVar8 = iVar8 + 1;
        uVar3 = *(uint *)this;
        if ((int)uVar3 <= iVar8) break;
        iVar5 = iVar5 + 0x3c;
        puVar2 = *(undefined4 **)(this + 0x28);
      }
    }
  }
  uVar6 = uVar3;
  if (0x7fffffff < uVar3) {
    uVar6 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar6);
  *(void **)(this + 0x30) = pvVar4;
  if (0 < (int)uVar3) {
    __aeabi_memset(pvVar4,uVar3,1);
  }
  pvVar4 = operator_new__(uVar6);
  *(void **)(this + 0x34) = pvVar4;
  if (0 < (int)uVar3) {
    __aeabi_memset(pvVar4,uVar3,1);
  }
  *(ushort *)(this + 4) = param_4;
  this[0x3c] = (LodMeshMerger)0x0;
  this[6] = (LodMeshMerger)0x0;
  if (__stack_chk_guard - local_4c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_4c);
  }
  return;
}

// ===== LodMeshMerger::setMesh  @0x001b1cf0  (76 bytes)
/* LodMeshMerger::setMesh(int, signed char, unsigned short) */

void __thiscall LodMeshMerger::setMesh(LodMeshMerger *this,int param_1,int param_3,ushort param_4)

{
  undefined4 uVar1;
  uint local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::MeshCreate(*(PaintCanvas **)(this + 0x14),param_4,&local_1c,false);
  uVar1 = AbyssEngine::PaintCanvas::MeshGetPointer(*(PaintCanvas **)(this + 0x14),local_1c);
  *(undefined4 *)(*(int *)(this + 0xc) + (*(int *)this * param_3 + param_1) * 4) = uVar1;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== LodMeshMerger::setLod  @0x001b1d44  (38 bytes)
/* LodMeshMerger::setLod(int, signed char) */

void __thiscall LodMeshMerger::setLod(LodMeshMerger *this,int param_1,char param_3)

{
  if (*(char *)(*(int *)(this + 0x2c) + param_1) != param_3) {
    *(char *)(*(int *)(this + 0x2c) + param_1) = param_3;
    if (*(char *)(*(int *)(this + 0x30) + param_1) == '\0') {
      return;
    }
    this[0x3c] = (LodMeshMerger)0x1;
  }
  return;
}

// ===== LodMeshMerger::setMatrix  @0x001b1d6a  (18 bytes)
/* LodMeshMerger::setMatrix(int, AbyssEngine::AEMath::Matrix const&) */

void __thiscall LodMeshMerger::setMatrix(LodMeshMerger *this,int param_1,Matrix *param_2)

{
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(*(int *)(this + 0x28) + param_1 * 0x3c),param_2)
  ;
  return;
}

// ===== LodMeshMerger::setEnabled  @0x001b1d7a  (34 bytes)
/* LodMeshMerger::setEnabled(int, bool) */

void __thiscall LodMeshMerger::setEnabled(LodMeshMerger *this,int param_1,bool param_2)

{
  if ((bool)*(char *)(*(int *)(this + 0x30) + param_1) != param_2) {
    *(bool *)(*(int *)(this + 0x30) + param_1) = param_2;
    if (*(char *)(*(int *)(this + 0x34) + param_1) == '\0') {
      return;
    }
    this[0x3c] = (LodMeshMerger)0x1;
  }
  return;
}

// ===== LodMeshMerger::init  @0x001b1d9c  (264 bytes)
/* LodMeshMerger::init() */

void __thiscall LodMeshMerger::init(LodMeshMerger *this)

{
  int *piVar1;
  Mesh *pMVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  if (this[6] != (LodMeshMerger)0x0) {
    return;
  }
  if (0 < *(int *)this) {
    iVar9 = 0;
    do {
      iVar4 = (int)*(char *)(*(int *)(this + 0x2c) + iVar9);
      if ((iVar4 < -1) || (iVar5 = *(int *)(this + 0x38), iVar5 <= iVar4)) {
        *(undefined1 *)(*(int *)(this + 0x2c) + iVar9) = 0;
        iVar5 = *(int *)(this + 0x38);
      }
      iVar4 = *(int *)this;
      if (0 < iVar5) {
        iVar7 = 0;
        do {
          pMVar2 = *(Mesh **)(*(int *)(this + 0xc) + (iVar4 * iVar7 + iVar9) * 4);
          if (pMVar2 != (Mesh *)0x0) {
            uVar3 = transformMesh(pMVar2,(Matrix *)(*(int *)(this + 0x28) + iVar9 * 0x3c));
            iVar4 = *(int *)this;
            *(undefined4 *)(*(int *)(this + 0x24) + (iVar4 * iVar7 + iVar9) * 4) = uVar3;
            iVar5 = *(int *)(this + 0x38);
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar5);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar4);
    if (0 < iVar4) {
      puVar11 = *(undefined4 **)(this + 0xc);
      iVar9 = 0;
      uVar6 = 0;
      uVar10 = 0;
      do {
        piVar1 = puVar11 + iVar9;
        iVar9 = iVar9 + 1;
        uVar10 = uVar10 + *(ushort *)(*piVar1 + 2);
        uVar6 = uVar6 + *(ushort *)(*piVar1 + 0x28) / 3;
      } while (iVar9 < iVar4);
      goto LAB_001b1e46;
    }
  }
  puVar11 = *(undefined4 **)(this + 0xc);
  uVar6 = 0;
  uVar10 = 0;
LAB_001b1e46:
  if (0xfffe < (int)uVar10) {
    uVar10 = 0xffff;
  }
  uVar8 = 0xffff;
  if ((int)uVar6 < 0xffff) {
    uVar8 = uVar6;
  }
  AbyssEngine::PaintCanvas::MeshCreate
            (*(PaintCanvas **)(this + 0x14),uVar10 & 0xffff,uVar8 & 0xffff,(int)*(char *)*puVar11,
             *(undefined2 *)(this + 4),this + 0x18);
  uVar3 = AbyssEngine::PaintCanvas::MeshGetPointer
                    (*(PaintCanvas **)(this + 0x14),*(uint *)(this + 0x18));
  *(undefined4 *)(this + 0x20) = uVar3;
  AbyssEngine::PaintCanvas::TransformCreate(*(PaintCanvas **)(this + 0x14),(uint *)(this + 0x1c));
  AbyssEngine::PaintCanvas::TransformAddMeshId
            (*(PaintCanvas **)(this + 0x14),*(uint *)(this + 0x1c),*(uint *)(this + 0x18));
  this[0x3c] = (LodMeshMerger)0x1;
  update();
  return;
}

// ===== LodMeshMerger::transformMesh  @0x001b1ea4  (492 bytes)
/* LodMeshMerger::transformMesh(AbyssEngine::Mesh*, AbyssEngine::AEMath::Matrix const&) */

void LodMeshMerger::transformMesh(Mesh *param_1,Matrix *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  float fVar5;
  undefined1 *puVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float fVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined8 uVar15;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  float local_48;
  float local_44;
  float fStack_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  puVar6 = operator_new(0x88);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(puVar6 + 0x3c) = 0;
  *(undefined4 *)(puVar6 + 0x40) = uVar1;
  *(undefined4 *)(puVar6 + 0x44) = uVar2;
  *(undefined4 *)(puVar6 + 0x48) = uVar3;
  *(undefined4 *)(puVar6 + 0x14) = 0;
  *(undefined4 *)(puVar6 + 0x18) = uVar1;
  *(undefined4 *)(puVar6 + 0x1c) = uVar2;
  *(undefined4 *)(puVar6 + 0x20) = uVar3;
  *(undefined4 *)(puVar6 + 4) = 0;
  *(undefined4 *)(puVar6 + 8) = uVar1;
  *(undefined4 *)(puVar6 + 0xc) = uVar2;
  *(undefined4 *)(puVar6 + 0x10) = uVar3;
  *(undefined4 *)(puVar6 + 0x28) = 0;
  *(undefined4 *)(puVar6 + 0x2c) = uVar1;
  *(undefined4 *)(puVar6 + 0x30) = uVar2;
  *(undefined4 *)(puVar6 + 0x34) = uVar3;
  puVar6[0x38] = 0;
  *(undefined4 *)(puVar6 + 0x4c) = 0x3f800000;
  *(undefined4 *)(puVar6 + 0x50) = 0;
  *(undefined4 *)(puVar6 + 0x54) = 0;
  *(undefined4 *)(puVar6 + 0x59) = 0;
  *(undefined4 *)(puVar6 + 0x55) = 0;
  *(undefined4 *)(puVar6 + 0x70) = 0;
  *(undefined4 *)(puVar6 + 0x74) = uVar1;
  *(undefined4 *)(puVar6 + 0x78) = uVar2;
  *(undefined4 *)(puVar6 + 0x7c) = uVar3;
  *(undefined4 *)(puVar6 + 0x60) = 0;
  *(undefined4 *)(puVar6 + 100) = uVar1;
  *(undefined4 *)(puVar6 + 0x68) = uVar2;
  *(undefined4 *)(puVar6 + 0x6c) = uVar3;
  *(undefined4 *)(puVar6 + 0x82) = 0;
  *(undefined4 *)(puVar6 + 0x7e) = 0;
  *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(puVar6 + 0x28) = *(undefined2 *)(param_1 + 0x28);
  uVar8 = *(uint *)param_1;
  *puVar6 = (char)uVar8;
  if ((uVar8 & 2) != 0) {
    *(undefined4 *)(puVar6 + 8) = *(undefined4 *)(param_1 + 8);
  }
  uVar10 = uVar8 >> 0x10;
  if ((uVar8 & 8) != 0) {
    *(undefined4 *)(puVar6 + 0xc) = *(undefined4 *)(param_1 + 0xc);
  }
  if ((uVar8 & 0x10) != 0) {
    *(undefined4 *)(puVar6 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  }
  if ((uVar8 & 1) != 0) {
    pvVar7 = operator_new__(uVar10 * 0xc);
    *(void **)(puVar6 + 4) = pvVar7;
    if (uVar10 == 0) {
      uVar10 = 0;
    }
    else {
      iVar11 = 0;
      iVar9 = 0;
      do {
        AbyssEngine::AEMath::MatrixTransformVector
                  ((AEMath *)&local_60,param_2,(Vector *)(*(int *)(param_1 + 4) + iVar11));
        AbyssEngine::AEMath::Vector::operator=
                  ((Vector *)(*(int *)(puVar6 + 4) + iVar11),(Vector *)&local_60);
        iVar11 = iVar11 + 0xc;
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)(uint)*(ushort *)(param_1 + 2));
      uVar8 = *(uint *)param_1;
      uVar10 = uVar8 >> 0x10;
    }
  }
  if ((uVar8 & 4) != 0) {
    pvVar7 = operator_new__(uVar10 * 0xc);
    *(void **)(puVar6 + 0x10) = pvVar7;
    if (uVar10 != 0) {
      iVar9 = 0;
      iVar11 = 0;
      do {
        AbyssEngine::AEMath::MatrixRotateVector
                  ((AEMath *)&local_48,param_2,(Vector *)(*(int *)(param_1 + 0x10) + iVar9));
        AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_60,(Vector *)&local_48);
        AbyssEngine::AEMath::Vector::operator=
                  ((Vector *)(*(int *)(puVar6 + 0x10) + iVar9),(Vector *)&local_60);
        iVar9 = iVar9 + 0xc;
        iVar11 = iVar11 + 1;
      } while (iVar11 < (int)(uint)*(ushort *)(param_1 + 2));
    }
  }
  local_48 = *(float *)(param_1 + 0x48);
  local_44 = local_48;
  fStack_40 = local_48;
  AbyssEngine::AEMath::MatrixTransformVector((AEMath *)&local_60,param_2,(Vector *)&local_48);
  fVar5 = local_48;
  uVar4 = CONCAT44(fStack_40,local_44);
  AbyssEngine::AEMath::MatrixTransformVector((AEMath *)&local_70,param_2,(Vector *)(param_1 + 0x3c))
  ;
  uVar15 = FloatVectorNeg(uVar4,2,2);
  uVar13 = FloatVectorCompareGreaterThan(uVar4,0,2);
  lVar14 = VectorBitwiseSelect(uVar13,uVar4,uVar15);
  if ((float)((ulonglong)lVar14 >> 0x20) < (float)lVar14) {
    lVar14 = lVar14 << 0x20;
  }
  local_54 = (float)((ulonglong)lVar14 >> 0x20);
  fVar12 = -fVar5;
  if (0.0 < fVar5) {
    fVar12 = fVar5;
  }
  if (local_54 < fVar12) {
    local_54 = fVar12;
  }
  local_58 = local_68;
  local_60 = local_70;
  local_50 = 0x3f800000;
  AbyssEngine::AEMath::BSphere::operator=((BSphere *)(puVar6 + 0x3c),(BSphere *)&local_60);
  if (__stack_chk_guard - local_3c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_3c);
  }
  return;
}

// ===== LodMeshMerger::update  @0x001b2098  (562 bytes)
/* LodMeshMerger::update() */

void LodMeshMerger::update(void)

{
  byte bVar1;
  char cVar2;
  int *in_r0;
  int iVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  byte *pbVar7;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  float in_s0;
  float extraout_s0;
  
  piVar10 = in_r0 + 0xf;
  iVar3 = *in_r0;
  if (0 < iVar3) {
    iVar8 = 0;
    do {
      uVar4 = AbyssEngine::PaintCanvas::CameraIsSphereinViewFrustum
                        ((PaintCanvas *)in_r0[5],(Vector *)(*(int *)(in_r0[9] + iVar8 * 4) + 0x3c),
                         in_s0);
      if ((uVar4 != *(byte *)(in_r0[0xd] + iVar8)) &&
         (*(char *)(in_r0[0xd] + iVar8) = (char)uVar4, *(char *)(in_r0[0xc] + iVar8) != '\0')) {
        *(char *)piVar10 = '\x01';
      }
      iVar3 = *in_r0;
      iVar8 = iVar8 + 1;
      in_s0 = extraout_s0;
    } while (iVar8 < iVar3);
  }
  if ((char)*piVar10 == '\0') {
    return;
  }
  if (0 < iVar3) {
    iVar13 = 0;
    iVar8 = 0;
    do {
      if ((*(char *)(in_r0[0xc] + iVar8) != '\0') && (*(char *)(in_r0[0xd] + iVar8) != '\0')) {
        iVar13 = iVar13 + (uint)*(ushort *)
                                 (*(int *)(in_r0[9] +
                                          (*(char *)(in_r0[0xb] + iVar8) * iVar3 + iVar8) * 4) +
                                 0x28);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar3);
    if (0xffff < iVar13) {
      iVar8 = 0;
LAB_001b2122:
      if (iVar8 < iVar3) {
        iVar9 = 0;
        do {
          if ((*(char *)(in_r0[0xc] + iVar8 + iVar9) != '\0') &&
             (*(char *)(in_r0[0xd] + iVar8 + iVar9) != '\0')) {
            cVar2 = *(char *)(in_r0[0xb] + iVar8 + iVar9);
            if ((int)cVar2 < in_r0[0xe] + -1) goto LAB_001b2154;
          }
          iVar9 = iVar9 + 1;
          if (iVar3 <= iVar8 + iVar9) break;
        } while( true );
      }
    }
LAB_001b21a8:
    if (0 < iVar3) {
      piVar11 = in_r0 + 8;
      iVar9 = 0;
      iVar13 = 0;
      iVar8 = 0;
      do {
        if ((*(char *)(in_r0[0xc] + iVar9) != '\0') && (*(char *)(in_r0[0xd] + iVar9) != '\0')) {
          pbVar7 = (byte *)in_r0[8];
          uVar4 = *(char *)(in_r0[0xb] + iVar9) * iVar3 + iVar9;
          bVar1 = *pbVar7;
          iVar12 = *(int *)(in_r0[9] + uVar4 * 4);
          if ((bVar1 & 1) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar7 + 4) + iVar8 * 0xc,*(undefined4 *)(iVar12 + 4),
                            (uint)*(ushort *)(iVar12 + 2) * 0xc);
            pbVar7 = (byte *)*piVar11;
            bVar1 = *pbVar7;
            uVar4 = extraout_r3;
          }
          if ((bVar1 & 4) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar7 + 0x10) + iVar8 * 0xc,*(undefined4 *)(iVar12 + 0x10),
                            (uint)*(ushort *)(iVar12 + 2) * 0xc);
            pbVar7 = (byte *)*piVar11;
            bVar1 = *pbVar7;
            uVar4 = extraout_r3_00;
          }
          if ((bVar1 & 8) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar7 + 0xc) + iVar8 * 0x10,*(undefined4 *)(iVar12 + 0xc),
                            (uint)*(ushort *)(iVar12 + 2) << 4);
            pbVar7 = (byte *)*piVar11;
            bVar1 = *pbVar7;
            uVar4 = extraout_r3_01;
          }
          if ((bVar1 & 2) != 0) {
            __aeabi_memcpy4(*(int *)(pbVar7 + 8) + iVar8 * 8,*(undefined4 *)(iVar12 + 8),
                            (uint)*(ushort *)(iVar12 + 2) << 3);
            pbVar7 = (byte *)*piVar11;
            bVar1 = *pbVar7;
            uVar4 = extraout_r3_02;
          }
          bVar14 = (bVar1 & 0x10) != 0;
          if (bVar14) {
            uVar4 = (uint)*(ushort *)(iVar12 + 0x28);
          }
          if (bVar14 && uVar4 != 0) {
            iVar3 = -uVar4;
            psVar5 = *(short **)(iVar12 + 0x2c);
            psVar6 = (short *)(*(int *)(pbVar7 + 0x2c) + iVar13 * 2);
            do {
              iVar3 = iVar3 + 1;
              *psVar6 = *psVar5 + (short)iVar8;
              psVar5 = psVar5 + 1;
              psVar6 = psVar6 + 1;
            } while (iVar3 != 0);
          }
          iVar3 = *in_r0;
          iVar13 = iVar13 + (uint)*(ushort *)(iVar12 + 0x28);
          iVar8 = iVar8 + (uint)*(ushort *)(iVar12 + 2);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar3);
      goto LAB_001b22b4;
    }
  }
  iVar13 = 0;
  iVar8 = 0;
LAB_001b22b4:
  iVar3 = in_r0[8];
  *(short *)(iVar3 + 2) = (short)iVar8;
  *(short *)(iVar3 + 0x28) = (short)iVar13;
  *(char *)piVar10 = '\0';
  return;
LAB_001b2154:
  iVar12 = *(int *)(in_r0[9] + (cVar2 * iVar3 + iVar8 + iVar9) * 4);
  if ((cVar2 != (char)(cVar2 + '\x01')) &&
     (*(char *)(in_r0[0xb] + iVar8 + iVar9) = cVar2 + '\x01',
     *(char *)(in_r0[0xc] + iVar8 + iVar9) != '\0')) {
    *(char *)piVar10 = '\x01';
  }
  iVar3 = *in_r0;
  iVar13 = (iVar13 - (uint)*(ushort *)(iVar12 + 0x28)) +
           (uint)*(ushort *)
                  (*(int *)(in_r0[9] + (*(char *)(in_r0[0xb] + iVar8 + iVar9) * iVar3 + iVar8) * 4 +
                           iVar9 * 4) + 0x28);
  iVar8 = iVar8 + iVar9 + 1;
  if (iVar13 < 0x10000) goto LAB_001b21a8;
  goto LAB_001b2122;
}

// ===== LodMeshMerger::~LodMeshMerger  @0x001b22ca  (168 bytes)
/* LodMeshMerger::~LodMeshMerger() */

void __thiscall LodMeshMerger::~LodMeshMerger(LodMeshMerger *this)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  pvVar1 = *(void **)(this + 0x24);
  if (0 < *(int *)(this + 0x38) * *(int *)this) {
    iVar4 = 0;
    do {
      iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      if (*(void **)(iVar3 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(iVar3 + 4));
        pvVar1 = *(void **)(this + 0x24);
        iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      }
      *(undefined4 *)(iVar3 + 4) = 0;
      iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      if (*(void **)(iVar3 + 0x10) != (void *)0x0) {
        operator_delete__(*(void **)(iVar3 + 0x10));
        pvVar1 = *(void **)(this + 0x24);
        iVar3 = *(int *)((int)pvVar1 + iVar4 * 4);
      }
      *(undefined4 *)(iVar3 + 0x10) = 0;
      pvVar2 = *(void **)((int)pvVar1 + iVar4 * 4);
      if (pvVar2 != (void *)0x0) {
        operator_delete(pvVar2);
        pvVar1 = *(void **)(this + 0x24);
      }
      *(undefined4 *)((int)pvVar1 + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
      pvVar1 = *(void **)(this + 0x24);
    } while (iVar4 < *(int *)(this + 0x38) * *(int *)this);
  }
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(this + 0x24) = 0;
  if (*(void **)(this + 0x2c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x2c));
  }
  *(undefined4 *)(this + 0x2c) = 0;
  if (*(void **)(this + 0x30) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x30));
  }
  *(undefined4 *)(this + 0x30) = 0;
  if (*(void **)(this + 0x34) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x34));
  }
  *(undefined4 *)(this + 0x34) = 0;
  if (*(void **)(this + 0x28) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x28));
  }
  *(undefined4 *)(this + 0x28) = 0;
  AMeshMerger::~AMeshMerger((AMeshMerger *)this);
  return;
}

