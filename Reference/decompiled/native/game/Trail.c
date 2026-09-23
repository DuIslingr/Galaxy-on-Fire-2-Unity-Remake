// Class: Trail
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Trail::Trail  @0x0018826c  (432 bytes)
/* Trail::Trail(int, int) */

Trail * __thiscall Trail::Trail(Trail *this,int param_1,int param_2)

{
  longlong lVar1;
  ushort uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint in_fpscr;
  float fVar8;
  float extraout_s1;
  float extraout_s1_00;
  float fVar10;
  undefined8 uVar9;
  float extraout_s1_01;
  float fVar11;
  ushort uVar12;
  
  *(int *)(this + 0x24) = param_2;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0x3c;
  AbyssEngine::PaintCanvas::MeshCreate
            (Globals::Canvas,param_2 * 2 + 2U & 0xffff,(param_2 & 0x7fffU) << 1,0x13,0x4e77,
             this + 0x10);
  iVar3 = *(int *)(this + 0x24);
  fVar10 = extraout_s1;
  if (1 < (iVar3 << 1) >> 1) {
    iVar5 = 0;
    do {
      uVar2 = (ushort)iVar5;
      uVar12 = uVar2 + 1;
      iVar5 = iVar5 + 2;
      AbyssEngine::PaintCanvas::MeshSetTriangle
                (Globals::Canvas,*(uint *)(this + 0x10),uVar2,uVar2,uVar12,(ushort)iVar5);
      AbyssEngine::PaintCanvas::MeshSetTriangle
                (Globals::Canvas,*(uint *)(this + 0x10),uVar12,uVar2 + 3,(ushort)iVar5,uVar12);
      iVar3 = *(int *)(this + 0x24);
      fVar10 = extraout_s1_00;
    } while (iVar5 < iVar3 * 2 + -2);
  }
  if (iVar3 * 2 < -1) {
    iVar5 = iVar3 * 2 + 2;
  }
  else {
    iVar6 = 0;
    do {
      fVar8 = (float)VectorSignedToFloat(iVar3 + 1,(byte)(in_fpscr >> 0x16) & 3);
      fVar11 = (float)VectorSignedToFloat(iVar6 / 2,(byte)(in_fpscr >> 0x16) & 3);
      fVar8 = (float)-(int)((fVar11 / fVar8) * 0.0);
      VectorSignedToFloat(fVar8,(byte)(in_fpscr >> 0x16) & 3);
      uVar9 = AbyssEngine::PaintCanvas::MeshSetUv
                        (Globals::Canvas,*(uint *)(this + 0x10),(ushort)iVar6,fVar8,fVar10);
      AbyssEngine::PaintCanvas::MeshSetUv
                (Globals::Canvas,*(uint *)(this + 0x10),(ushort)iVar6 + 1,(float)uVar9,
                 (float)((ulonglong)uVar9 >> 0x20));
      iVar3 = *(int *)(this + 0x24);
      iVar6 = iVar6 + 2;
      iVar5 = iVar3 * 2 + 2;
      fVar10 = extraout_s1_01;
    } while (iVar6 < iVar5);
  }
  *(int *)(this + 0x20) = iVar5 * 3;
  lVar1 = (ulonglong)(uint)(iVar5 * 3) * 4;
  uVar7 = (uint)lVar1;
  if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
    uVar7 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar7);
  *(void **)(this + 0x18) = pvVar4;
  pvVar4 = operator_new__(uVar7);
  *(void **)(this + 0x1c) = pvVar4;
  AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(this + 0x14));
  AbyssEngine::PaintCanvas::TransformAddMeshId
            (Globals::Canvas,*(uint *)(this + 0x14),*(uint *)(this + 0x10));
  changeType(this,param_1);
  return this;
}

// ===== Trail::changeType  @0x00188430  (140 bytes)
/* Trail::changeType(int) */

void __thiscall Trail::changeType(Trail *this,int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff0000ff;
  switch(param_1) {
  case 1:
  case 0xb:
    goto LAB_001884aa;
  case 2:
  case 9:
    uVar1 = *(uint *)(this + 0x14);
    uVar2 = 0xff00ff;
    break;
  case 3:
  case 10:
    goto LAB_00188498;
  case 4:
  default:
    uVar1 = *(uint *)(this + 0x14);
    uVar2 = 0xffffffff;
    break;
  case 5:
    uVar1 = *(uint *)(this + 0x14);
    uVar2 = 0xff0000;
    break;
  case 6:
LAB_00188498:
    uVar1 = *(uint *)(this + 0x14);
    uVar2 = 0xffff00ff;
    break;
  case 7:
LAB_001884aa:
    uVar1 = *(uint *)(this + 0x14);
    break;
  case 8:
    uVar2 = 0xff4000ff;
    uVar1 = *(uint *)(this + 0x14);
  }
  AbyssEngine::PaintCanvas::TransformSetColor(Globals::Canvas,uVar1,uVar2);
  return;
}

// ===== Trail::~Trail  @0x001884ec  (32 bytes)
/* Trail::~Trail() */

Trail * __thiscall Trail::~Trail(Trail *this)

{
  if (*(void **)(this + 0x18) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x18));
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(void **)(this + 0x1c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x1c));
  }
  *(undefined4 *)(this + 0x1c) = 0;
  return this;
}

// ===== Trail::update  @0x0018850c  (476 bytes)
/* Trail::update(float, float, float, float, float, float) */

void Trail::update(float param_1,float param_2,float param_3,float param_4,float param_5,
                  float param_6)

{
  int in_r0;
  int *piVar1;
  Matrix *pMVar2;
  float in_r1;
  int iVar3;
  int *piVar4;
  float in_r2;
  int iVar5;
  undefined4 *puVar6;
  float in_r3;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s1;
  float extraout_s1_00;
  float fVar7;
  float fVar8;
  float extraout_s2;
  int iVar9;
  float in_stack_00000000;
  float in_stack_00000004;
  float in_stack_00000008;
  AEMath aAStack_68 [60];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(in_r0 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
  piVar1 = *(int **)(in_r0 + 0x18);
  *piVar1 = (int)(in_r1 - fVar7);
  piVar1[1] = (int)in_r2;
  piVar1[2] = (int)in_r3;
  fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(in_r0 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
  piVar1[3] = (int)(fVar7 + in_r1);
  piVar1[4] = (int)in_r2;
  piVar1[5] = (int)in_r3;
  fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(in_r0 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
  piVar1[6] = (int)(in_stack_00000000 - fVar7);
  piVar1[7] = (int)in_stack_00000004;
  piVar1[8] = (int)in_stack_00000008;
  fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(in_r0 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
  piVar1[9] = (int)(fVar7 + in_stack_00000000);
  piVar1[10] = (int)in_stack_00000004;
  piVar1[0xb] = (int)in_stack_00000008;
  iVar5 = *(int *)(in_r0 + 0x20);
  iVar3 = iVar5 + -1;
  if (10 < iVar3) {
    piVar4 = piVar1 + iVar5 + -0xc;
    do {
      iVar3 = iVar3 + -6;
      piVar4[0xb] = piVar4[5];
      piVar4[10] = piVar4[4];
      *(undefined8 *)(piVar4 + 6) = *(undefined8 *)piVar4;
      *(undefined8 *)(piVar4 + 8) = *(undefined8 *)(piVar4 + 2);
      piVar4 = piVar4 + -6;
    } while (10 < iVar3);
    iVar5 = *(int *)(in_r0 + 0x20);
  }
  if (0 < iVar5) {
    piVar1 = piVar1 + 2;
    iVar3 = 2;
    piVar4 = (int *)(*(int *)(in_r0 + 0x1c) + 4);
    do {
      iVar5 = iVar3 + 1;
      iVar3 = iVar3 + 3;
      fVar7 = (float)VectorSignedToFloat(piVar1[-2],(byte)(in_fpscr >> 0x16) & 3);
      piVar4[-1] = (int)(fVar7 - in_r1);
      fVar7 = (float)VectorSignedToFloat(piVar1[-1],(byte)(in_fpscr >> 0x16) & 3);
      *piVar4 = (int)(fVar7 - in_r2);
      iVar9 = *piVar1;
      piVar1 = piVar1 + 3;
      fVar7 = (float)VectorSignedToFloat(iVar9,(byte)(in_fpscr >> 0x16) & 3);
      piVar4[1] = (int)(fVar7 - in_r3);
      piVar4 = piVar4 + 3;
    } while (iVar5 < *(int *)(in_r0 + 0x20));
  }
  if (-1 < (*(int *)(in_r0 + 0x24) << 1) >> 1) {
    iVar3 = -1;
    iVar5 = 0;
    do {
      iVar3 = iVar3 + 1;
      puVar6 = (undefined4 *)(*(int *)(in_r0 + 0x1c) + iVar5);
      VectorSignedToFloat(*puVar6,(byte)(in_fpscr >> 0x16) & 3);
      fVar7 = (float)VectorSignedToFloat(puVar6[2],(byte)(in_fpscr >> 0x16) & 3);
      fVar8 = (float)VectorSignedToFloat(puVar6[1],(byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(in_r0 + 0x10),(ushort)iVar3,fVar7,param_2,fVar8);
      iVar5 = iVar5 + 0xc;
      param_2 = extraout_s1;
    } while (iVar3 <= *(int *)(in_r0 + 0x24) * 2);
  }
  pMVar2 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal(Globals::Canvas,*(uint *)(in_r0 + 0x14));
  AbyssEngine::AEMath::MatrixSetTranslation
            (aAStack_68,pMVar2,extraout_s0,extraout_s1_00,extraout_s2);
  if (__stack_chk_guard != local_2c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Trail::setWidth  @0x001886f8  (122 bytes)
/* Trail::setWidth(int) */

void Trail::setWidth(int param_1)

{
  int iVar1;
  int iVar2;
  int in_r1;
  int iVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  float in_s1;
  float extraout_s1;
  float fVar7;
  
  if (-1 < (*(int *)(param_1 + 0x24) << 1) >> 1) {
    iVar1 = *(int *)(param_1 + 0xc);
    iVar4 = -1;
    iVar5 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0x18);
      iVar4 = iVar4 + 1;
      iVar3 = *(int *)(iVar2 + iVar5) + (iVar1 - in_r1);
      VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
      *(int *)(iVar2 + iVar5) = iVar3;
      fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(iVar2 + iVar5 + 8),
                                         (byte)(in_fpscr >> 0x16) & 3);
      fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(iVar2 + iVar5 + 4),
                                         (byte)(in_fpscr >> 0x16) & 3);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(param_1 + 0x10),(ushort)iVar4,fVar6,in_s1,fVar7);
      iVar5 = iVar5 + 0xc;
      in_s1 = extraout_s1;
    } while (iVar4 <= *(int *)(param_1 + 0x24) * 2);
  }
  *(int *)(param_1 + 0xc) = in_r1;
  return;
}

// ===== Trail::update  @0x00188778  (48 bytes)
/* Trail::update(AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&) */

void Trail::update(Vector *param_1,Vector *param_2)

{
  float *in_r2;
  float in_s1;
  float in_s3;
  float in_s5;
  
  update(*in_r2,in_s1,in_r2[1],in_s3,in_r2[2],in_s5);
  return;
}

// ===== Trail::update  @0x001887a8  (96 bytes)
/* Trail::update(AbyssEngine::AEMath::Matrix const&, AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall Trail::update(Trail *this,Matrix *param_1,Matrix *param_2,Vector *param_3)

{
  float extraout_s1;
  float extraout_s3;
  float extraout_s5;
  float local_30;
  float local_2c;
  float local_28;
  AEMath local_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::AEMath::MatrixTransformVector(local_24,param_1,param_3);
  AbyssEngine::AEMath::MatrixTransformVector((AEMath *)&local_30,param_2,param_3);
  update(local_30,extraout_s1,local_2c,extraout_s3,local_28,extraout_s5);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Trail::reset  @0x00188810  (98 bytes)
/* Trail::reset(AbyssEngine::AEMath::Vector) */

void Trail::reset(undefined4 param_1,float param_2,undefined4 param_3,float param_4,
                 undefined4 param_5,float param_6,int param_7,float param_8,float param_9,
                 float param_10)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param_7 + 0x20)) {
    iVar2 = 0;
    iVar3 = *(int *)(param_7 + 0x18);
    do {
      iVar1 = iVar3 + iVar2 * 4;
      *(int *)(iVar3 + iVar2 * 4) = (int)param_8;
      iVar2 = iVar2 + 3;
      *(int *)(iVar1 + 4) = (int)param_9;
      *(int *)(iVar1 + 8) = (int)param_10;
    } while (iVar2 < *(int *)(param_7 + 0x20));
  }
  update(param_8,param_2,param_10,param_4,param_9,param_6);
  return;
}

// ===== Trail::translate  @0x00188872  (104 bytes)
/* Trail::translate(AbyssEngine::AEMath::Vector const&) */

void __thiscall Trail::translate(Trail *this,Vector *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  if (*(int *)(this + 0x20) < 1) {
    return;
  }
  iVar3 = *(int *)(this + 0x18);
  iVar1 = 0;
  fVar4 = *(float *)param_1;
  fVar5 = *(float *)(param_1 + 4);
  fVar6 = *(float *)(param_1 + 8);
  do {
    puVar2 = (undefined4 *)(iVar3 + iVar1 * 4);
    fVar7 = (float)VectorSignedToFloat(*puVar2,(byte)(in_fpscr >> 0x16) & 3);
    *(int *)(iVar3 + iVar1 * 4) = (int)(fVar4 + fVar7);
    iVar1 = iVar1 + 3;
    fVar7 = (float)VectorSignedToFloat(puVar2[1],(byte)(in_fpscr >> 0x16) & 3);
    puVar2[1] = (int)(fVar5 + fVar7);
    fVar7 = (float)VectorSignedToFloat(puVar2[2],(byte)(in_fpscr >> 0x16) & 3);
    puVar2[2] = (int)(fVar6 + fVar7);
  } while (iVar1 < *(int *)(this + 0x20));
  return;
}

// ===== Trail::render  @0x001888dc  (16 bytes)
/* Trail::render() */

void __thiscall Trail::render(Trail *this)

{
  AbyssEngine::PaintCanvas::DrawTransform(Globals::Canvas,*(uint *)(this + 0x14),(Matrix *)0x0);
  return;
}

