// Class: MovingStars
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MovingStars::MovingStars  @0x0016f7e4  (290 bytes)
/* MovingStars::MovingStars() */

void __thiscall MovingStars::MovingStars(MovingStars *this)

{
  void *pvVar1;
  undefined4 uVar2;
  Matrix *pMVar3;
  int iVar4;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s3;
  AEMath aAStack_64 [60];
  int local_28;
  
  iVar4 = 0;
  local_28 = __stack_chk_guard;
  *(uint *)(this + 8) = 0;
  pvVar1 = operator_new__(200);
  *(void **)this = pvVar1;
  pvVar1 = operator_new__(200);
  *(void **)(this + 4) = pvVar1;
  pvVar1 = operator_new__(200);
  *(void **)(this + 0x10) = pvVar1;
  pvVar1 = operator_new__(200);
  *(void **)(this + 0xc) = pvVar1;
  __aeabi_memset4(pvVar1,200,0xff);
  do {
    AbyssEngine::AERandom::nextInt(Globals::rnd,4);
    uVar2 = Globals::createBillBoard
                      (Globals::globals,0x46,extraout_s0,extraout_s1,extraout_s2,extraout_s3,500);
    *(undefined4 *)(*(int *)this + iVar4) = uVar2;
    AbyssEngine::PaintCanvas::TransformCreate(Globals::Canvas,(uint *)(*(int *)(this + 4) + iVar4));
    AbyssEngine::PaintCanvas::TransformAddMeshId
              (Globals::Canvas,*(uint *)(*(int *)(this + 4) + iVar4),*(uint *)(*(int *)this + iVar4)
              );
    pMVar3 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (Globals::Canvas,*(uint *)(*(int *)(this + 4) + iVar4));
    AbyssEngine::AEMath::MatrixSetTranslation
              (aAStack_64,pMVar3,extraout_s0_00,extraout_s1_00,extraout_s2_00);
    iVar4 = iVar4 + 4;
  } while (iVar4 != 200);
  AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,0x2711,(uint *)(this + 8),false);
  this[0x14] = (MovingStars)0x0;
  this[0x15] = (MovingStars)0x0;
  *(undefined4 *)(this + 0x18) = 0;
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== MovingStars::~MovingStars  @0x0016f920  (54 bytes)
/* MovingStars::~MovingStars() */

MovingStars * __thiscall MovingStars::~MovingStars(MovingStars *this)

{
  if (*(void **)this != (void *)0x0) {
    operator_delete__(*(void **)this);
  }
  *(undefined4 *)this = 0;
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  if (*(void **)(this + 0xc) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0xc));
  }
  *(undefined4 *)(this + 0xc) = 0;
  if (*(void **)(this + 0x10) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x10));
  }
  *(undefined4 *)(this + 0x10) = 0;
  return this;
}

// ===== MovingStars::update  @0x0016f958  (1464 bytes)
/* MovingStars::update(int, AbyssEngine::AEMath::Matrix, bool, float) */

void MovingStars::update(float param_1_00,float param_2,float param_3,int *param_1,int param_5,
                        undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                        undefined4 param_10,undefined4 param_11,undefined4 param_12,
                        undefined4 param_13,undefined4 param_14,undefined4 param_15,
                        undefined4 param_16,undefined4 param_17,undefined4 param_18,
                        undefined4 param_19,undefined4 param_20,int param_21,float param_22)

{
  bool bVar1;
  int iVar2;
  Matrix *pMVar3;
  undefined4 *puVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint in_fpscr;
  float fVar9;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float extraout_s0_06;
  float extraout_s0_07;
  float extraout_s0_08;
  float extraout_s0_09;
  float extraout_s0_10;
  float extraout_s0_11;
  float extraout_s0_12;
  float extraout_s0_13;
  float extraout_s0_14;
  float extraout_s0_15;
  float extraout_s0_16;
  float extraout_s0_17;
  float extraout_s0_18;
  float extraout_s0_19;
  float extraout_s0_20;
  float extraout_s0_21;
  float extraout_s0_22;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s1_07;
  float extraout_s1_08;
  float extraout_s1_09;
  float extraout_s1_10;
  float extraout_s1_11;
  float extraout_s1_12;
  float extraout_s1_13;
  float extraout_s1_14;
  float extraout_s1_15;
  float extraout_s1_16;
  float extraout_s1_17;
  float extraout_s1_18;
  float extraout_s1_19;
  float extraout_s1_20;
  float extraout_s1_21;
  float extraout_s1_22;
  float extraout_s1_23;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float extraout_s2_02;
  float extraout_s2_03;
  float extraout_s2_04;
  float extraout_s2_05;
  float extraout_s2_06;
  float extraout_s2_07;
  float extraout_s2_08;
  float extraout_s2_09;
  float extraout_s2_10;
  float extraout_s2_11;
  float extraout_s2_12;
  float extraout_s2_13;
  float extraout_s2_14;
  float extraout_s2_15;
  float extraout_s2_16;
  float extraout_s2_17;
  float extraout_s2_18;
  float extraout_s2_19;
  float extraout_s2_20;
  float extraout_s2_21;
  float extraout_s2_22;
  float extraout_s2_23;
  undefined4 local_d8;
  undefined4 uStack_d4;
  float local_d0;
  float local_cc;
  undefined4 uStack_c8;
  undefined4 local_c4;
  float local_c0;
  float local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  float local_b0;
  float local_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 local_9c;
  undefined4 local_98;
  float local_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int local_54;
  
  local_54 = __stack_chk_guard;
  local_88 = param_8;
  local_84 = param_9;
  local_80 = param_10;
  local_7c = param_11;
  local_78 = param_12;
  uStack_74 = param_13;
  local_70 = param_14;
  uStack_6c = param_15;
  local_68 = param_16;
  uStack_64 = param_17;
  local_60 = param_18;
  uStack_5c = param_19;
  uStack_58 = param_20;
  param_1[6] = param_1[6] + param_5;
  local_90 = param_6;
  uStack_8c = param_7;
  if (param_21 == 1) {
    iVar7 = 0;
    fVar5 = (float)((int)(param_22 * 4500.0) + 500);
    VectorSignedToFloat(-500 - (int)(param_22 * 4500.0),(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(fVar5,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat((int)(param_22 * -20.0) + 0x46,(byte)(in_fpscr >> 0x16) & 3);
    VectorSignedToFloat(-0x46 - (int)(param_22 * -20.0),(byte)(in_fpscr >> 0x16) & 3);
    fVar9 = (float)(int)(param_22 * 1000.0);
    iVar8 = (int)fVar9 + 1000;
    do {
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),0,fVar9,param_2,fVar5);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),1,extraout_s0,extraout_s1,
                 extraout_s2);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),2,extraout_s0_00,extraout_s1_00,
                 extraout_s2_00);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),3,extraout_s0_01,extraout_s1_01,
                 extraout_s2_01);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),4,extraout_s0_02,extraout_s1_02,
                 extraout_s2_02);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),5,extraout_s0_03,extraout_s1_03,
                 extraout_s2_03);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),6,extraout_s0_04,extraout_s1_04,
                 extraout_s2_04);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),7,extraout_s0_05,extraout_s1_05,
                 extraout_s2_05);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),8,extraout_s0_06,extraout_s1_06,
                 extraout_s2_06);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),9,extraout_s0_07,extraout_s1_07,
                 extraout_s2_07);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),10,extraout_s0_08,extraout_s1_08,
                 extraout_s2_08);
      AbyssEngine::PaintCanvas::MeshSetPoint
                (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),0xb,extraout_s0_09,extraout_s1_09,
                 extraout_s2_09);
      *(int *)(param_1[4] + iVar7 * 4) = iVar8;
      iVar7 = iVar7 + 1;
      fVar9 = extraout_s0_10;
      param_2 = extraout_s1_10;
      fVar5 = extraout_s2_10;
    } while (iVar7 != 0x32);
    *(undefined2 *)(param_1 + 5) = 0x101;
  }
  else {
    *(undefined1 *)(param_1 + 5) = 0;
    if (*(char *)((int)param_1 + 0x15) != '\0') {
      iVar7 = 0;
      *(undefined1 *)((int)param_1 + 0x15) = 0;
      do {
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),0,param_1_00,param_2,param_3);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),1,extraout_s0_11,extraout_s1_11,
                   extraout_s2_11);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),2,extraout_s0_12,extraout_s1_12,
                   extraout_s2_12);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),3,extraout_s0_13,extraout_s1_13,
                   extraout_s2_13);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),4,extraout_s0_14,extraout_s1_14,
                   extraout_s2_14);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),5,extraout_s0_15,extraout_s1_15,
                   extraout_s2_15);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),6,extraout_s0_16,extraout_s1_16,
                   extraout_s2_16);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),7,extraout_s0_17,extraout_s1_17,
                   extraout_s2_17);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),8,extraout_s0_18,extraout_s1_18,
                   extraout_s2_18);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),9,extraout_s0_19,extraout_s1_19,
                   extraout_s2_19);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),10,extraout_s0_20,extraout_s1_20,
                   extraout_s2_20);
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (Globals::Canvas,*(uint *)(*param_1 + iVar7 * 4),0xb,extraout_s0_21,extraout_s1_21
                   ,extraout_s2_21);
        iVar7 = iVar7 + 1;
        param_1_00 = extraout_s0_22;
        param_2 = extraout_s1_22;
        param_3 = extraout_s2_22;
      } while (iVar7 != 0x32);
    }
  }
  iVar7 = 0;
  bVar1 = false;
  do {
    iVar8 = *(int *)(param_1[3] + iVar7);
    if (((bVar1) || (0 < iVar8)) || ((param_21 == 0 && (param_1[6] < 0x29)))) {
      *(int *)(param_1[3] + iVar7) = iVar8 - param_5;
      puVar4 = (undefined4 *)
               AbyssEngine::PaintCanvas::TransformGetLocal
                         (Globals::Canvas,*(uint *)(param_1[1] + iVar7));
      local_d8 = *puVar4;
      uStack_d4 = puVar4[1];
      local_d0 = (float)puVar4[2];
      uStack_c8 = puVar4[4];
      local_c4 = puVar4[5];
      local_c0 = (float)puVar4[6];
      uStack_b8 = puVar4[8];
      uStack_b4 = puVar4[9];
      local_b0 = (float)puVar4[10];
      uStack_a8 = puVar4[0xc];
      uStack_a4 = puVar4[0xd];
      uStack_a0 = puVar4[0xe];
      fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(param_1[4] + iVar7),
                                         (byte)(in_fpscr >> 0x16) & 3);
      local_cc = (float)puVar4[3] - local_d0 * fVar9;
      local_bc = (float)puVar4[7] - local_c0 * fVar9;
      local_ac = (float)puVar4[0xb] - local_b0 * fVar9;
      AbyssEngine::PaintCanvas::TransformSetLocal
                (Globals::Canvas,*(uint *)(param_1[1] + iVar7),(Matrix *)&local_d8);
    }
    else {
      param_1[6] = 0;
      iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
      iVar2 = AbyssEngine::AERandom::nextInt(Globals::rnd,18000);
      local_9c = VectorSignedToFloat(iVar8 + -10000,(byte)(in_fpscr >> 0x16) & 3);
      local_98 = VectorSignedToFloat(iVar2 + -9000,(byte)(in_fpscr >> 0x16) & 3);
      local_94 = 20000.0;
      AbyssEngine::AEMath::MatrixTransformVector
                ((AEMath *)&local_d8,(Matrix *)&local_90,(Vector *)&local_9c);
      AbyssEngine::AEMath::Vector::operator=((Vector *)&local_9c,(Vector *)&local_d8);
      AbyssEngine::PaintCanvas::TransformSetLocal
                (Globals::Canvas,*(uint *)(param_1[1] + iVar7),(Matrix *)&local_90);
      pMVar3 = (Matrix *)
               AbyssEngine::PaintCanvas::TransformGetLocal
                         (Globals::Canvas,*(uint *)(param_1[1] + iVar7));
      AbyssEngine::AEMath::MatrixSetTranslation
                ((AEMath *)&local_d8,pMVar3,local_94,extraout_s1_23,extraout_s2_23);
      if (param_21 == 1) {
        *(int *)(param_1[4] + iVar7) = (int)(param_22 * 1000.0) + 1000;
        uVar6 = 500;
      }
      else {
        iVar8 = AbyssEngine::AERandom::nextInt(Globals::rnd,500);
        *(int *)(param_1[4] + iVar7) = iVar8 + 500;
        uVar6 = 2000;
      }
      bVar1 = true;
      *(undefined4 *)(param_1[3] + iVar7) = uVar6;
    }
    iVar7 = iVar7 + 4;
  } while (iVar7 != 200);
  if (__stack_chk_guard != local_54) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== MovingStars::render  @0x0016ff3c  (66 bytes)
/* MovingStars::render() */

void __thiscall MovingStars::render(MovingStars *this)

{
  int iVar1;
  
  AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 8),0xffffffff);
  AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,1);
  iVar1 = 0;
  do {
    AbyssEngine::PaintCanvas::DrawTransform
              (Globals::Canvas,*(uint *)(*(int *)(this + 4) + iVar1 * 4),(Matrix *)0x0);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x32);
  return;
}

// ===== MovingStars::translate  @0x0016ff88  (128 bytes)
/* MovingStars::translate(AbyssEngine::AEMath::Vector const&) */

void __thiscall MovingStars::translate(MovingStars *this,Vector *param_1)

{
  Matrix *pMVar1;
  int iVar2;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_6c [60];
  AEMath local_30 [8];
  float local_28;
  int local_24;
  
  iVar2 = 0;
  local_24 = __stack_chk_guard;
  do {
    pMVar1 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (Globals::Canvas,*(uint *)(*(int *)(this + 4) + iVar2 * 4));
    AbyssEngine::AEMath::MatrixGetPosition(local_30,pMVar1);
    AbyssEngine::AEMath::Vector::operator+=((Vector *)local_30,param_1);
    pMVar1 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (Globals::Canvas,*(uint *)(*(int *)(this + 4) + iVar2 * 4));
    AbyssEngine::AEMath::MatrixSetTranslation(aAStack_6c,pMVar1,local_28,extraout_s1,extraout_s2);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x32);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

