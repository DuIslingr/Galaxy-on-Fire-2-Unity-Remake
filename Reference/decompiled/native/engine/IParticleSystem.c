// Class: IParticleSystem
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== IParticleSystem::IParticleSystem  @0x001b2370  (294 bytes)
/* IParticleSystem::IParticleSystem(AbyssEngine::PaintCanvas*, AbyssEngine::AEMath::Matrix const*,
   Array<ParticleSettings::ParticleSet> const&, bool, bool) */

IParticleSystem * __thiscall
IParticleSystem::IParticleSystem
          (IParticleSystem *this,PaintCanvas *param_1,Matrix *param_2,Array *param_3,bool param_4,
          bool param_5)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  *(undefined ***)this = &PTR___cxa_pure_virtual_00264aa4;
  *(PaintCanvas **)(this + 8) = param_1;
  AbyssEngine::AERandom::AERandom((AERandom *)(this + 0x10));
  *(Matrix **)(this + 0x18) = param_2;
  uVar7 = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  puVar1 = operator_new__(4);
  *(undefined4 **)(this + 0x3c) = puVar1;
  *(undefined4 *)(this + 0x40) = 1;
  *puVar1 = 0;
  *(undefined4 *)(this + 0x38) = 0;
  this[0x45] = (IParticleSystem)param_5;
  this[0x4c] = (IParticleSystem)param_4;
  ArraySet<ParticleSettings::ParticleSet>
            (*(ParticleSet **)(param_3 + 4),*(uint *)param_3,(Array *)(this + 0x38));
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  this[0xc] = (IParticleSystem)0x1;
  this[0xd] = (IParticleSystem)0x1;
  this[0xe] = (IParticleSystem)0x1;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  uVar9 = *(uint *)param_3;
  if (uVar9 != 0) {
    iVar5 = 0;
    iVar4 = *(int *)(param_3 + 4);
    uVar7 = 0;
    uVar6 = 0;
    do {
      iVar8 = *(int *)(iVar4 + uVar6 * 4);
      if (iVar8 != -1) {
        if ((int)uVar7 <= (int)*(uint *)(ParticleSettingsRef::cur + iVar8 * 0x9c + 0xc)) {
          uVar7 = *(uint *)(ParticleSettingsRef::cur + iVar8 * 0x9c + 0xc);
        }
        *(uint *)(this + 0x48) = uVar7;
        if (iVar5 == 0) {
          iVar5 = *(int *)(ParticleSettingsRef::cur + iVar8 * 0x9c + 8);
          *(int *)(this + 0x34) = iVar5;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar9);
  }
  uVar9 = (uint)((ulonglong)uVar7 * 4);
  this[0x44] = (IParticleSystem)0x0;
  *(undefined4 *)(this + 0x60) = 0;
  if ((int)((ulonglong)uVar7 * 4 >> 0x20) != 0) {
    uVar9 = 0xffffffff;
  }
  pvVar2 = operator_new__(uVar9);
  *(void **)(this + 0x68) = pvVar2;
  uVar9 = uVar7;
  if (0x7fffffff < uVar7) {
    uVar9 = 0xffffffff;
  }
  puVar3 = operator_new__(uVar9);
  *(undefined1 **)(this + 0x6c) = puVar3;
  if ((0 < (int)uVar7) && (*puVar3 = 200, 1 < *(int *)(this + 0x48))) {
    iVar4 = 1;
    do {
      *(undefined1 *)(*(int *)(this + 0x6c) + iVar4) = 200;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(this + 0x48));
  }
  *(undefined2 *)(this + 4) = 0x101;
  this[0x5c] = (IParticleSystem)0x0;
  return this;
}

// ===== IParticleSystem::getParticleCount  @0x001b24c0  (4 bytes)
/* IParticleSystem::getParticleCount() */

undefined4 __thiscall IParticleSystem::getParticleCount(IParticleSystem *this)

{
  return *(undefined4 *)(this + 0x48);
}

// ===== IParticleSystem::setParticleSetIndex  @0x001b24c4  (6 bytes)
/* IParticleSystem::setParticleSetIndex(unsigned char) */

void __thiscall IParticleSystem::setParticleSetIndex(IParticleSystem *this,uchar param_1)

{
  this[0x44] = (IParticleSystem)param_1;
  return;
}

// ===== IParticleSystem::setParticleSet  @0x001b24ca  (20 bytes)
/* IParticleSystem::setParticleSet(ParticleSettings::ParticleSet) */

void __thiscall IParticleSystem::setParticleSet(IParticleSystem *this,int param_2)

{
  if ((*(int *)(this + 0x38) != 0) && (**(int **)(this + 0x3c) == param_2)) {
    this[0x44] = (IParticleSystem)0x0;
  }
  return;
}

// ===== IParticleSystem::resetEmitterVelocity  @0x001b24e0  (84 bytes)
/* IParticleSystem::resetEmitterVelocity() */

void __thiscall IParticleSystem::resetEmitterVelocity(IParticleSystem *this)

{
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_24 = 0;
  uStack_20 = 0;
  local_1c = 0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x1c),(Vector *)&local_24);
  this[5] = (IParticleSystem)0x1;
  AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_24,*(Matrix **)(this + 0x18));
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)&local_24);
  this[4] = (IParticleSystem)0x0;
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== IParticleSystem::calcEmitterVelocity  @0x001b253c  (128 bytes)
/* IParticleSystem::calcEmitterVelocity(int) */

void __thiscall IParticleSystem::calcEmitterVelocity(IParticleSystem *this,int param_1)

{
  uint in_fpscr;
  float fVar1;
  AEMath aAStack_44 [12];
  AEMath aAStack_38 [12];
  AEMath aAStack_2c [12];
  int local_20;
  
  local_20 = __stack_chk_guard;
  AbyssEngine::AEMath::MatrixGetPosition(aAStack_2c,*(Matrix **)(this + 0x18));
  AbyssEngine::AEMath::operator-(aAStack_44,(Vector *)aAStack_2c,(Vector *)(this + 0x28));
  fVar1 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::AEMath::operator*(aAStack_38,(Vector *)aAStack_44,1000.0 / fVar1);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x1c),(Vector *)aAStack_38);
  this[5] = (IParticleSystem)0x0;
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x28),(Vector *)aAStack_2c);
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== IParticleSystem::interpolateColor  @0x001b25c8  (332 bytes)
/* IParticleSystem::interpolateColor(int, float&, float&, float&, float&) */

void __thiscall
IParticleSystem::interpolateColor
          (IParticleSystem *this,int param_1,float *param_2,float *param_3,float *param_4,
          float *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined8 in_d1;
  undefined8 uVar8;
  float fVar9;
  undefined4 in_s5;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  iVar4 = *(int *)(*(int *)(this + 0x68) + param_1 * 4);
  iVar1 = *(char *)(*(int *)(this + 0x6c) + param_1) * 0x9c;
  fVar5 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
  fVar6 = (float)VectorSignedToFloat(*(undefined4 *)(ParticleSettingsRef::cur + iVar1 + 0x24),
                                     (byte)(in_fpscr >> 0x16) & 3);
  uVar3 = *(uint *)(ParticleSettingsRef::cur + iVar1 + 0x34);
  uVar2 = *(uint *)(ParticleSettingsRef::cur + iVar1 + 0x30);
  fVar11 = (float)VectorUnsignedToFloat(uVar3 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
  fVar13 = (float)VectorUnsignedToFloat(uVar2 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
  fVar14 = (float)VectorUnsignedToFloat(uVar3 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
  uVar8 = FloatVectorMin(CONCAT44((int)((ulonglong)in_d1 >> 0x20),fVar5 / fVar6),
                         CONCAT44(in_s5,0x3f800000),2,0x20);
  fVar15 = (float)VectorUnsignedToFloat((uVar3 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  fVar16 = (float)VectorUnsignedToFloat((uVar2 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  fVar7 = (float)uVar8;
  fVar9 = 1.0 - fVar7;
  fVar6 = (float)VectorUnsignedToFloat((uVar3 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
  fVar10 = (float)VectorUnsignedToFloat((uVar2 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
  fVar12 = (float)VectorUnsignedToFloat(uVar2 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (fVar11 * fVar7 + fVar12 * fVar9) * 0.003921569;
  *param_2 = (fVar14 * fVar7 + fVar13 * fVar9) * 0.003921569;
  *param_3 = (fVar15 * fVar7 + fVar16 * fVar9) * 0.003921569;
  *param_4 = (fVar6 * fVar7 + fVar10 * fVar9) * 0.003921569;
  *param_5 = fVar11;
  if (*(int *)(ParticleSettingsRef::cur + iVar1 + 0x38) <= iVar4) {
    return;
  }
  fVar6 = (float)VectorSignedToFloat(*(int *)(ParticleSettingsRef::cur + iVar1 + 0x38),
                                     (byte)(in_fpscr >> 0x16) & 3);
  fVar5 = fVar5 / fVar6;
  if (this[0x45] != (IParticleSystem)0x0) {
    *param_2 = fVar5 * *param_2;
    *param_3 = fVar5 * *param_3;
    *param_4 = fVar5 * *param_4;
    return;
  }
  *param_5 = fVar11 * fVar5;
  return;
}

// ===== IParticleSystem::update  @0x001b271c  (68 bytes)
/* IParticleSystem::update(int) */

void __thiscall IParticleSystem::update(IParticleSystem *this,int param_1)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  undefined4 uVar3;
  
  if ((this[0xe] != (IParticleSystem)0x0) && (iVar1 = *(int *)(this + 0x48), 0 < iVar1)) {
    iVar2 = 0;
    uVar3 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    do {
      if (*(int *)(*(int *)(this + 0x68) + iVar2 * 4) != -1) {
        (**(code **)(*(int *)this + 0x14))(this,iVar2,uVar3);
        iVar1 = *(int *)(this + 0x48);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}

// ===== IParticleSystem::enableEmit  @0x001b2760  (18 bytes)
/* IParticleSystem::enableEmit(bool) */

void IParticleSystem::enableEmit(bool param_1)

{
  uint uVar1;
  int in_r1;
  uint in_r2;
  
  uVar1 = (uint)param_1;
  if (in_r1 == 1) {
    in_r2 = (uint)*(byte *)(uVar1 + 0xc);
  }
  if (in_r1 == 1 && in_r2 == 0) {
    *(undefined4 *)(uVar1 + 0x60) = 0;
  }
  *(char *)(uVar1 + 0xc) = (char)in_r1;
  return;
}

// ===== IParticleSystem::enableRender  @0x001b2772  (26 bytes)
/* IParticleSystem::enableRender(bool) */

void __thiscall IParticleSystem::enableRender(IParticleSystem *this,bool param_1)

{
  if ((!param_1) && (this[0xd] != (IParticleSystem)0x0)) {
    (**(code **)(*(int *)this + 8))(this);
  }
  this[0xd] = (IParticleSystem)param_1;
  return;
}

// ===== IParticleSystem::enableUpdate  @0x001b278c  (4 bytes)
/* IParticleSystem::enableUpdate(bool) */

void __thiscall IParticleSystem::enableUpdate(IParticleSystem *this,bool param_1)

{
  this[0xe] = (IParticleSystem)param_1;
  return;
}

// ===== IParticleSystem::emit  @0x001b2790  (2468 bytes)
/* IParticleSystem::emit(int) */

void __thiscall IParticleSystem::emit(IParticleSystem *this,int param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  AERandom *this_00;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  AERandom *this_01;
  Vector *pVVar18;
  code *pcVar19;
  uint in_fpscr;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  undefined4 uVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  float fVar34;
  int local_110;
  undefined4 *local_108;
  AEMath aAStack_f8 [12];
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  AEMath aAStack_d4 [12];
  AEMath aAStack_c8 [12];
  AEMath aAStack_bc [12];
  AEMath aAStack_b0 [12];
  AEMath aAStack_a4 [12];
  AEMath aAStack_98 [12];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c [4];
  int local_6c;
  
  local_6c = __stack_chk_guard;
  if (((((*(ushort *)(this + 0xc) & 0xff) == 0) || (*(ushort *)(this + 0xc) < 0x100)) ||
      (iVar11 = *(int *)(*(int *)(this + 0x3c) + (uint)(byte)this[0x44] * 4), iVar11 == -1)) ||
     ((((*(uint *)(this + 0x34) & 0x80) != 0 && (**(int **)(this + 0x68) != -1)) ||
      ((*(uint *)(this + 0x34) & 0x100) != 0)))) goto LAB_001b312c;
  AbyssEngine::AEMath::MatrixGetPosition(aAStack_98,*(Matrix **)(this + 0x18));
  AbyssEngine::AEMath::MatrixGetRight(aAStack_a4,*(Matrix **)(this + 0x18));
  if (this[0x4c] != (IParticleSystem)0x0) {
    AbyssEngine::AEMath::operator-((AEMath *)local_7c,(Vector *)aAStack_a4);
    AbyssEngine::AEMath::Vector::operator=((Vector *)aAStack_a4,(Vector *)local_7c);
  }
  AbyssEngine::AEMath::MatrixGetUp(aAStack_b0,*(Matrix **)(this + 0x18));
  AbyssEngine::AEMath::MatrixGetDir(aAStack_bc,*(Matrix **)(this + 0x18));
  pVVar18 = (Vector *)(this + 0x1c);
  fVar4 = (float)AbyssEngine::AEMath::VectorDot(pVVar18,pVVar18);
  fVar20 = (float)VectorSignedToFloat(*(undefined4 *)
                                       (ParticleSettingsRef::cur + iVar11 * 0x9c + 0x94),
                                      (byte)(in_fpscr >> 0x16) & 3);
  in_fpscr = in_fpscr & 0xfffffff;
  if (fVar4 < fVar20) goto LAB_001b312c;
  fVar23 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  fVar20 = (float)AbyssEngine::AEMath::operator*
                            ((AEMath *)local_7c,pVVar18,fVar23 + *(float *)(this + 0x60));
  AbyssEngine::AEMath::operator/(aAStack_c8,(Vector *)local_7c,fVar20);
  fVar20 = (float)AbyssEngine::AEMath::VectorDot((Vector *)aAStack_c8,(Vector *)aAStack_c8);
  fVar5 = (float)(0x5f3759df - ((int)fVar20 >> 1));
  fVar21 = 1.5;
  fVar5 = fVar5 * (fVar5 * fVar20 * -0.5 * fVar5 + 1.5);
  fVar20 = 1.0 / fVar5;
  uVar6 = *(uint *)(this + 0x34);
  if ((uVar6 & 0x10) == 0) {
    if ((uVar6 & 0x20) != 0) {
      local_110 = (int)(*(float *)(ParticleSettingsRef::cur + iVar11 * 0x9c + 0x28) *
                        (fVar23 + *(float *)(this + 0x60)) * 0.001);
      fVar30 = (float)VectorSignedToFloat(local_110,(byte)(in_fpscr >> 0x16) & 3);
      fVar30 = fVar23 + *(float *)(this + 0x60) +
               (fVar30 * -1000.0) / *(float *)(ParticleSettingsRef::cur + iVar11 * 0x9c + 0x28);
      goto LAB_001b299c;
    }
    local_110 = *(int *)(ParticleSettingsRef::cur + iVar11 * 0x9c + 0xc);
    if ((uVar6 & 0x40) != 0) {
      this[0xc] = (IParticleSystem)0x0;
    }
  }
  else {
    fVar30 = fVar20 / *(float *)(ParticleSettingsRef::cur + iVar11 * 0x9c + 0x28);
    local_110 = (int)fVar30;
    fVar25 = (float)VectorSignedToFloat(local_110,(byte)(in_fpscr >> 0x16) & 3);
    fVar30 = ((fVar23 + *(float *)(this + 0x60)) * (fVar30 - fVar25)) / fVar30;
LAB_001b299c:
    *(float *)(this + 0x60) = fVar30;
  }
  if (0 < local_110) {
    AbyssEngine::AEMath::operator-(aAStack_d4,(Vector *)aAStack_98,(Vector *)aAStack_c8);
    fVar30 = 0.0;
    if (((byte)this[0x34] & 0xc0) == 0) {
      fVar30 = (float)(0x5f3759df - ((int)fVar4 >> 1));
      fVar30 = fVar30 * (fVar30 * fVar4 * -0.5 * fVar30 + 1.5);
    }
    this_01 = (AERandom *)(this + 0x10);
    iVar2 = iVar11 * 0x9c;
    local_7c[0] = *(undefined4 *)(ParticleSettingsRef::cur + iVar2 + 0x84);
    local_7c[1] = *(undefined4 *)(ParticleSettingsRef::cur + iVar2 + 0x8c);
    local_7c[2] = *(undefined4 *)(ParticleSettingsRef::cur + iVar2 + 0x88);
    local_7c[3] = *(undefined4 *)(ParticleSettingsRef::cur + iVar2 + 0x90);
    piVar12 = (int *)(ParticleSettingsRef::cur + iVar2 + 0x14);
    local_108 = local_7c;
    iVar7 = *(int *)(this + 0x50);
    iVar15 = 0;
    do {
      *(char *)(*(int *)(this + 0x6c) + iVar7) = (char)iVar11;
      *(undefined4 *)(*(int *)(this + 0x68) + *(int *)(this + 0x50) * 4) = 0;
      if (((byte)this[0x37] & 2) != 0) {
        this_00 = (AERandom *)
                  AbyssEngine::AERandom::AERandom
                            ((AERandom *)&local_e0,(longlong)*(int *)(this + 0x50));
        uVar6 = AbyssEngine::AERandom::nextInt(this_00,40000);
        local_8c = local_7c[uVar6 & 1];
        local_88 = local_7c[(uVar6 ^ 3) & 1];
        local_84 = local_7c[uVar6 >> 1 & 1 | 2];
        local_80 = local_7c[(uVar6 ^ 3) >> 1 & 1 | 2];
        AbyssEngine::AERandom::~AERandom((AERandom *)&local_e0);
        local_108 = &local_8c;
      }
      iVar7 = *(int *)(this + 0x50);
      iVar13 = *(int *)(this + 100);
      iVar14 = *(int *)(ParticleSettingsRef::cur + iVar2 + 0x4c);
      if (iVar14 == 0) {
        local_e0 = 0.0;
        local_dc = 0.0;
        local_d8 = 0.0;
      }
      else {
        iVar17 = iVar14 << 1;
        iVar8 = AbyssEngine::AERandom::nextInt(this_01,iVar17);
        fVar4 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x54);
        fVar25 = (float)VectorSignedToFloat(iVar8 - iVar14,(byte)(in_fpscr >> 0x16) & 3);
        iVar8 = AbyssEngine::AERandom::nextInt(this_01,iVar17);
        fVar27 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x58);
        fVar28 = (float)VectorSignedToFloat(iVar8 - iVar14,(byte)(in_fpscr >> 0x16) & 3);
        iVar8 = AbyssEngine::AERandom::nextInt(this_01,iVar17);
        local_e0 = fVar4 + fVar25;
        local_dc = fVar27 + fVar28;
        local_d8 = (float)VectorSignedToFloat(iVar8 - iVar14,(byte)(in_fpscr >> 0x16) & 3);
        local_d8 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x5c) + local_d8;
      }
      AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar13 + iVar7 * 0xc),(Vector *)&local_e0);
      fVar4 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x60);
      uVar6 = in_fpscr & 0xfffffff | (uint)(fVar4 == 0.0) << 0x1e;
      if ((byte)(uVar6 >> 0x1e) == 0) {
        iVar7 = *(int *)(this + 0x50);
        iVar13 = *(int *)(this + 100);
        AbyssEngine::AEMath::operator*((AEMath *)&local_e0,pVVar18,fVar4);
        AbyssEngine::AEMath::Vector::operator-=
                  ((Vector *)(iVar13 + iVar7 * 0xc),(Vector *)&local_e0);
      }
      uVar6 = uVar6 & 0xfffffff |
              (uint)(*(float *)(ParticleSettingsRef::cur + iVar2 + 100) == 0.0) << 0x1e;
      if ((byte)(uVar6 >> 0x1e) == 0) {
        iVar7 = *(int *)(this + 0x50);
        iVar13 = *(int *)(this + 100);
        AbyssEngine::AEMath::operator*
                  ((AEMath *)&local_e0,(Vector *)aAStack_a4,
                   *(float *)(ParticleSettingsRef::cur + iVar2 + 100));
        AbyssEngine::AEMath::Vector::operator+=
                  ((Vector *)(iVar13 + iVar7 * 0xc),(Vector *)&local_e0);
      }
      uVar6 = uVar6 & 0xfffffff |
              (uint)(*(float *)(ParticleSettingsRef::cur + iVar2 + 0x68) == 0.0) << 0x1e;
      if ((byte)(uVar6 >> 0x1e) == 0) {
        iVar7 = *(int *)(this + 0x50);
        iVar13 = *(int *)(this + 100);
        AbyssEngine::AEMath::operator*
                  ((AEMath *)&local_e0,(Vector *)aAStack_b0,
                   *(float *)(ParticleSettingsRef::cur + iVar2 + 0x68));
        AbyssEngine::AEMath::Vector::operator+=
                  ((Vector *)(iVar13 + iVar7 * 0xc),(Vector *)&local_e0);
      }
      iVar13 = iVar15 + 1;
      uVar6 = uVar6 & 0xfffffff |
              (uint)(*(float *)(ParticleSettingsRef::cur + iVar2 + 0x6c) == 0.0) << 0x1e;
      if ((byte)(uVar6 >> 0x1e) == 0) {
        iVar7 = *(int *)(this + 0x50);
        iVar14 = *(int *)(this + 100);
        AbyssEngine::AEMath::operator*
                  ((AEMath *)&local_e0,(Vector *)aAStack_bc,
                   *(float *)(ParticleSettingsRef::cur + iVar2 + 0x6c));
        AbyssEngine::AEMath::Vector::operator+=
                  ((Vector *)(iVar14 + iVar7 * 0xc),(Vector *)&local_e0);
      }
      if (*(int *)(ParticleSettingsRef::cur + iVar2 + 0x2c) == 1) {
        fVar4 = (float)VectorSignedToFloat(iVar13,(byte)(uVar6 >> 0x16) & 3);
      }
      else {
        uVar9 = AbyssEngine::AERandom::nextInt(this_01,10000);
        fVar25 = (float)VectorSignedToFloat(uVar9,(byte)(uVar6 >> 0x16) & 3);
        fVar4 = (float)VectorSignedToFloat(iVar15,(byte)(uVar6 >> 0x16) & 3);
        fVar4 = fVar4 + fVar25 * 0.0001;
      }
      local_e0 = 0.0;
      local_dc = 0.0;
      local_d8 = 0.0;
      if ((*(uint *)(this + 0x34) & 0xc0) == 0) {
        uVar6 = uVar6 & 0xfffffff;
        if (1.0 <= fVar20) {
          if ((*(uint *)(this + 0x34) & 0x10) == 0) {
            fVar21 = (float)VectorSignedToFloat(local_110,(byte)(uVar6 >> 0x16) & 3);
            fVar21 = fVar20 / fVar21;
          }
          else {
            fVar21 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x28);
          }
          AbyssEngine::AEMath::operator*(aAStack_f8,(Vector *)aAStack_c8,fVar4 * fVar21);
          AbyssEngine::AEMath::operator*((AEMath *)&local_ec,(Vector *)aAStack_f8,fVar5);
          AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e0,(Vector *)&local_ec);
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_ec,(Vector *)aAStack_d4,(Vector *)&local_e0);
          AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e0,(Vector *)&local_ec);
        }
        else {
          AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e0,(Vector *)aAStack_98);
          fVar4 = (float)VectorSignedToFloat(iVar13,(byte)(uVar6 >> 0x16) & 3);
          local_110 = iVar13;
        }
      }
      else {
        AbyssEngine::AEMath::Vector::operator=((Vector *)&local_e0,(Vector *)aAStack_98);
        fVar4 = 0.0;
      }
      fVar25 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x74);
      if (((byte)this[0x34] & 0x80) == 0) {
        uVar6 = uVar6 & 0xfffffff | (uint)(fVar25 == 0.0) << 0x1e;
        if ((byte)(uVar6 >> 0x1e) == 0) {
          AbyssEngine::AEMath::operator*((AEMath *)&local_ec,(Vector *)aAStack_a4,fVar25);
          AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_e0,(Vector *)&local_ec);
        }
        uVar6 = uVar6 & 0xfffffff |
                (uint)(*(float *)(ParticleSettingsRef::cur + iVar2 + 0x78) == 0.0) << 0x1e;
        if ((byte)(uVar6 >> 0x1e) == 0) {
          AbyssEngine::AEMath::operator*
                    ((AEMath *)&local_ec,(Vector *)aAStack_b0,
                     *(float *)(ParticleSettingsRef::cur + iVar2 + 0x78));
          AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_e0,(Vector *)&local_ec);
        }
        uVar6 = uVar6 & 0xfffffff |
                (uint)(*(float *)(ParticleSettingsRef::cur + iVar2 + 0x7c) == 0.0) << 0x1e;
        if ((byte)(uVar6 >> 0x1e) == 0) {
          AbyssEngine::AEMath::operator*
                    ((AEMath *)&local_ec,(Vector *)aAStack_bc,
                     *(float *)(ParticleSettingsRef::cur + iVar2 + 0x7c));
          AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_e0,(Vector *)&local_ec);
        }
        uVar6 = uVar6 & 0xfffffff |
                (uint)(*(float *)(ParticleSettingsRef::cur + iVar2 + 0x80) == 0.0) << 0x1e;
        if ((byte)(uVar6 >> 0x1e) == 0) {
          uVar9 = AbyssEngine::AERandom::nextInt
                            (this_01,(int)*(float *)(ParticleSettingsRef::cur + iVar2 + 0x80));
          fVar25 = (float)VectorSignedToFloat(uVar9,(byte)(uVar6 >> 0x16) & 3);
          AbyssEngine::AEMath::operator*((AEMath *)&local_ec,(Vector *)aAStack_bc,fVar25);
          AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_e0,(Vector *)&local_ec);
        }
        iVar15 = *(int *)(ParticleSettingsRef::cur + iVar2 + 0x44);
        if (iVar15 != 0) {
          iVar7 = AbyssEngine::AERandom::nextInt(this_01,iVar15 << 1);
          uVar9 = VectorSignedToFloat(iVar7 - iVar15,(byte)(uVar6 >> 0x16) & 3);
          iVar7 = AbyssEngine::AERandom::nextInt(this_01,iVar15 << 1);
          local_e4 = VectorSignedToFloat(iVar7 - iVar15,(byte)(uVar6 >> 0x16) & 3);
          local_e8 = 0;
          local_ec = uVar9;
          AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_e0,(Vector *)&local_ec);
        }
        iVar15 = *(int *)(ParticleSettingsRef::cur + iVar2 + 0x48);
        if (iVar15 != 0) {
          iVar15 = AbyssEngine::AERandom::nextInt(this_01,iVar15 << 1);
          fVar25 = (float)VectorSignedToFloat(iVar15 - *(int *)(ParticleSettingsRef::cur +
                                                               iVar2 + 0x48),
                                              (byte)(uVar6 >> 0x16) & 3);
          local_dc = local_dc + fVar25;
        }
      }
      else {
        iVar14 = (int)fVar25;
        iVar7 = iVar14 << 1;
        iVar15 = AbyssEngine::AERandom::nextInt(this_01,iVar7);
        uVar9 = VectorSignedToFloat(iVar15 - iVar14,(byte)(uVar6 >> 0x16) & 3);
        iVar15 = AbyssEngine::AERandom::nextInt(this_01,iVar7);
        uVar29 = VectorSignedToFloat(iVar15 - iVar14,(byte)(uVar6 >> 0x16) & 3);
        iVar15 = AbyssEngine::AERandom::nextInt(this_01,iVar7);
        local_e4 = VectorSignedToFloat(iVar15 - iVar14,(byte)(uVar6 >> 0x16) & 3);
        local_ec = uVar9;
        local_e8 = uVar29;
        AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_e0,(Vector *)&local_ec);
      }
      fVar25 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x10);
      pcVar19 = *(code **)(*(int *)this + 0x18);
      if (*piVar12 == 0) {
        uVar29 = *local_108;
        uVar32 = local_108[1];
        uVar31 = local_108[2];
        uVar33 = local_108[3];
        uVar9 = *(undefined4 *)(ParticleSettingsRef::cur + iVar2 + 0x30);
        if (*(int *)(ParticleSettingsRef::cur + iVar2 + 0x38) < 1) {
          uVar16 = 0;
          fVar27 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x3c);
          uVar1 = uVar6 & 0xfffffff | (uint)(fVar27 < 0.0) << 0x1f | (uint)(fVar27 == 0.0) << 0x1e;
          uVar6 = uVar1 | (uint)NAN(fVar27) << 0x1c;
          bVar3 = (byte)(uVar1 >> 0x18);
          if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar6 >> 0x1c) & 1)) {
            uVar16 = 1;
          }
        }
        else {
          uVar16 = 1;
        }
        fVar28 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x1c);
        fVar22 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x18);
        fVar27 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x20);
        uVar6 = uVar6 & 0xfffffff | (uint)(fVar27 == 0.0) << 0x1e;
        if ((byte)(uVar6 >> 0x1e) == 0) {
          AbyssEngine::AEMath::operator*((AEMath *)&local_ec,fVar27,(Vector *)fVar27);
        }
        else {
          local_ec = 0;
          local_e8 = 0;
          local_e4 = 0;
        }
        (*pcVar19)(this,&local_e0,fVar25,uVar9,uVar29,uVar31,uVar32,uVar33,uVar16,fVar22,fVar28,
                   (AEMath *)&local_ec);
      }
      else {
        uVar9 = AbyssEngine::AERandom::nextInt(this_01,*piVar12);
        fVar27 = (float)VectorSignedToFloat(uVar9,(byte)(uVar6 >> 0x16) & 3);
        uVar29 = *local_108;
        uVar32 = local_108[1];
        uVar31 = local_108[2];
        uVar33 = local_108[3];
        uVar9 = *(undefined4 *)(ParticleSettingsRef::cur + iVar2 + 0x30);
        if (*(int *)(ParticleSettingsRef::cur + iVar2 + 0x38) < 1) {
          uVar16 = 0;
          fVar28 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x3c);
          uVar1 = uVar6 & 0xfffffff | (uint)(fVar28 < 0.0) << 0x1f | (uint)(fVar28 == 0.0) << 0x1e;
          uVar6 = uVar1 | (uint)NAN(fVar28) << 0x1c;
          bVar3 = (byte)(uVar1 >> 0x18);
          if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(uVar6 >> 0x1c) & 1)) {
            uVar16 = 1;
          }
        }
        else {
          uVar16 = 1;
        }
        fVar24 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x18);
        uVar10 = AbyssEngine::AERandom::nextInt(this_01,*piVar12);
        fVar26 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x1c);
        fVar34 = (float)VectorSignedToFloat(uVar10,(byte)(uVar6 >> 0x16) & 3);
        uVar10 = AbyssEngine::AERandom::nextInt(this_01,*piVar12);
        fVar28 = (float)VectorSignedToFloat(uVar10,(byte)(uVar6 >> 0x16) & 3);
        fVar22 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x20);
        uVar6 = uVar6 & 0xfffffff | (uint)(fVar22 == 0.0) << 0x1e;
        if ((byte)(uVar6 >> 0x1e) == 0) {
          AbyssEngine::AEMath::operator*((AEMath *)&local_ec,fVar22,(Vector *)fVar22);
        }
        else {
          local_ec = 0;
          local_e8 = 0;
          local_e4 = 0;
        }
        (*pcVar19)(this,&local_e0,fVar25 + fVar27,uVar9,uVar29,uVar31,uVar32,uVar33,uVar16,
                   fVar24 + fVar34,fVar26 + fVar28,&local_ec);
      }
      fVar25 = *(float *)(ParticleSettingsRef::cur + iVar2 + 0x60);
      uVar6 = uVar6 & 0xfffffff | (uint)(fVar25 == 0.0) << 0x1e;
      if ((byte)(uVar6 >> 0x1e) == 0) {
        iVar15 = *(int *)(this + 0x50);
        iVar7 = *(int *)(this + 100);
        fVar25 = (float)AbyssEngine::AEMath::operator*(aAStack_f8,pVVar18,fVar25);
        AbyssEngine::AEMath::operator*((AEMath *)&local_ec,(Vector *)aAStack_f8,fVar25);
        AbyssEngine::AEMath::Vector::operator+=
                  ((Vector *)(iVar7 + iVar15 * 0xc),(Vector *)&local_ec);
      }
      fVar25 = (float)VectorSignedToFloat(local_110,(byte)(uVar6 >> 0x16) & 3);
      fVar4 = fVar30 * fVar21 * (fVar25 - fVar4) * 1000.0;
      uVar6 = uVar6 & 0xfffffff | (uint)(fVar4 < fVar23) << 0x1f | (uint)(fVar4 == fVar23) << 0x1e;
      in_fpscr = uVar6 | (uint)(NAN(fVar4) || NAN(fVar23)) << 0x1c;
      bVar3 = (byte)(uVar6 >> 0x18);
      if (!(bool)(bVar3 >> 6 & 1) && bVar3 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) {
        fVar4 = fVar23;
      }
      (**(code **)(*(int *)this + 0x14))(this,*(undefined4 *)(this + 0x50),fVar4);
      iVar7 = *(int *)(this + 0x50) + 1;
      if (*(int *)(this + 0x48) <= iVar7) {
        iVar7 = 0;
      }
      *(int *)(this + 0x50) = iVar7;
      iVar15 = iVar13;
    } while (iVar13 < local_110);
  }
LAB_001b312c:
  if (__stack_chk_guard == local_6c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== IParticleSystem::emitManual  @0x001b3174  (1110 bytes)
/* IParticleSystem::emitManual(AbyssEngine::AEMath::Vector, int, AbyssEngine::AEMath::Vector const*,
   float) */

void IParticleSystem::emitManual
               (int *param_1,undefined4 param_2,float param_3,undefined4 param_4,int param_5,
               Vector *param_6,float param_7)

{
  int *piVar1;
  AERandom *pAVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  uint in_fpscr;
  uint uVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  float fVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  AEMath aAStack_b4 [12];
  undefined4 local_a8;
  float local_a4;
  undefined4 local_a0;
  undefined4 local_98;
  float local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c [4];
  int local_6c;
  
  local_6c = __stack_chk_guard;
  local_98 = param_2;
  local_94 = param_3;
  uStack_90 = param_4;
  if (param_5 != -1) {
    puVar9 = local_7c;
    iVar14 = *(int *)(param_1[0xf] + param_5 * 4);
    iVar7 = iVar14 * 0x9c;
    *(char *)(param_1[0x1b] + param_1[0x14]) = (char)iVar14;
    *(undefined4 *)(param_1[0x1a] + param_1[0x14] * 4) = 0;
    local_7c[0] = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x84);
    local_7c[1] = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x8c);
    local_7c[2] = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x88);
    local_7c[3] = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x90);
    if ((*(byte *)((int)param_1 + 0x37) & 2) != 0) {
      pAVar2 = (AERandom *)
               AbyssEngine::AERandom::AERandom((AERandom *)&local_a8,(longlong)param_1[0x14]);
      uVar3 = AbyssEngine::AERandom::nextInt(pAVar2,40000);
      local_8c = puVar9[uVar3 & 1];
      local_88 = puVar9[(uVar3 ^ 3) & 1];
      local_84 = puVar9[uVar3 >> 1 & 1 | 2];
      local_80 = puVar9[(uVar3 ^ 3) >> 1 & 1 | 2];
      AbyssEngine::AERandom::~AERandom((AERandom *)&local_a8);
      puVar9 = &local_8c;
    }
    iVar7 = param_1[0x14];
    iVar8 = param_1[0x19];
    iVar12 = *(int *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x4c);
    if (iVar12 == 0) {
      local_a8 = 0;
      local_a4 = 0.0;
      local_a0 = 0;
    }
    else {
      pAVar2 = (AERandom *)(param_1 + 4);
      iVar11 = iVar12 << 1;
      iVar4 = AbyssEngine::AERandom::nextInt(pAVar2,iVar11);
      iVar5 = AbyssEngine::AERandom::nextInt(pAVar2,iVar11);
      fVar16 = (float)VectorSignedToFloat(iVar5 - iVar12,(byte)(in_fpscr >> 0x16) & 3);
      fVar17 = *(float *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x58);
      uVar18 = VectorSignedToFloat(iVar4 - iVar12,(byte)(in_fpscr >> 0x16) & 3);
      iVar4 = AbyssEngine::AERandom::nextInt(pAVar2,iVar11);
      local_a0 = VectorSignedToFloat(iVar4 - iVar12,(byte)(in_fpscr >> 0x16) & 3);
      local_a8 = uVar18;
      local_a4 = fVar17 + fVar16;
    }
    AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar8 + iVar7 * 0xc),(Vector *)&local_a8);
    if (param_6 != (Vector *)0x0) {
      in_fpscr = in_fpscr & 0xfffffff |
                 (uint)(*(float *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x60) == 0.0) << 0x1e;
      if ((byte)(in_fpscr >> 0x1e) == 0) {
        iVar7 = param_1[0x14];
        iVar8 = param_1[0x19];
        AbyssEngine::AEMath::operator*
                  ((AEMath *)&local_a8,param_6,
                   *(float *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x60));
        AbyssEngine::AEMath::Vector::operator-=((Vector *)(iVar8 + iVar7 * 0xc),(Vector *)&local_a8)
        ;
      }
    }
    iVar7 = *(int *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x44);
    if (iVar7 != 0) {
      iVar8 = AbyssEngine::AERandom::nextInt((AERandom *)(param_1 + 4),iVar7 << 1);
      uVar18 = VectorSignedToFloat(iVar8 - iVar7,(byte)(in_fpscr >> 0x16) & 3);
      iVar8 = AbyssEngine::AERandom::nextInt((AERandom *)(param_1 + 4),iVar7 << 1);
      local_a0 = VectorSignedToFloat(iVar8 - iVar7,(byte)(in_fpscr >> 0x16) & 3);
      local_a4 = 0.0;
      local_a8 = uVar18;
      AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_98,(Vector *)&local_a8);
    }
    iVar7 = *(int *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x48);
    if (iVar7 != 0) {
      iVar7 = AbyssEngine::AERandom::nextInt((AERandom *)(param_1 + 4),iVar7 << 1);
      fVar16 = (float)VectorSignedToFloat(iVar7 - *(int *)(ParticleSettingsRef::cur +
                                                          iVar14 * 0x9c + 0x48),
                                          (byte)(in_fpscr >> 0x16) & 3);
      local_94 = local_94 + fVar16;
    }
    uVar3 = in_fpscr & 0xfffffff | (uint)(param_7 < 0.0) << 0x1f;
    uVar15 = uVar3 | (uint)NAN(param_7) << 0x1c;
    if ((byte)(uVar3 >> 0x1f) != ((byte)(uVar15 >> 0x1c) & 1)) {
      param_7 = *(float *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x10);
    }
    pcVar10 = *(code **)(*param_1 + 0x18);
    piVar1 = (int *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x14);
    if (*piVar1 == 0) {
      iVar7 = iVar14 * 0x9c;
      uVar6 = *puVar9;
      uVar20 = puVar9[1];
      fVar16 = *(float *)(ParticleSettingsRef::cur + iVar7 + 0x20);
      iVar8 = *(int *)(ParticleSettingsRef::cur + iVar7 + 0x38);
      uVar18 = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x30);
      uVar13 = puVar9[2];
      uVar21 = puVar9[3];
      uVar22 = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x1c);
      uVar23 = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x18);
      if (fVar16 == 0.0) {
        local_a8 = 0;
        local_a4 = 0.0;
        local_a0 = 0;
      }
      else {
        AbyssEngine::AEMath::operator*((AEMath *)&local_a8,fVar16,(Vector *)fVar16);
      }
      (*pcVar10)(param_1,&local_98,param_7,uVar18,uVar6,uVar13,uVar20,uVar21,0 < iVar8,uVar23,uVar22
                 ,&local_a8);
    }
    else {
      pAVar2 = (AERandom *)(param_1 + 4);
      iVar7 = iVar14 * 0x9c;
      uVar18 = AbyssEngine::AERandom::nextInt(pAVar2,*piVar1);
      iVar8 = *(int *)(ParticleSettingsRef::cur + iVar7 + 0x38);
      uVar13 = *(undefined4 *)(ParticleSettingsRef::cur + iVar7 + 0x30);
      uVar20 = *puVar9;
      uVar22 = puVar9[1];
      uVar21 = puVar9[2];
      uVar23 = puVar9[3];
      fVar24 = *(float *)(ParticleSettingsRef::cur + iVar7 + 0x18);
      uVar6 = AbyssEngine::AERandom::nextInt(pAVar2,*piVar1);
      fVar26 = *(float *)(ParticleSettingsRef::cur + iVar7 + 0x1c);
      fVar25 = (float)VectorSignedToFloat(uVar18,(byte)(uVar15 >> 0x16) & 3);
      fVar19 = (float)VectorSignedToFloat(uVar6,(byte)(uVar15 >> 0x16) & 3);
      uVar18 = AbyssEngine::AERandom::nextInt(pAVar2,*piVar1);
      fVar16 = (float)VectorSignedToFloat(uVar18,(byte)(uVar15 >> 0x16) & 3);
      fVar17 = *(float *)(ParticleSettingsRef::cur + iVar7 + 0x20);
      if (fVar17 == 0.0) {
        local_a8 = 0;
        local_a4 = 0.0;
        local_a0 = 0;
      }
      else {
        AbyssEngine::AEMath::operator*((AEMath *)&local_a8,fVar17,(Vector *)fVar17);
      }
      (*pcVar10)(param_1,&local_98,param_7 + fVar25,uVar13,uVar20,uVar21,uVar22,uVar23,0 < iVar8,
                 fVar24 + fVar19,fVar26 + fVar16,&local_a8);
    }
    if (*(float *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x60) != 0.0) {
      iVar7 = param_1[0x14];
      iVar8 = param_1[0x19];
      fVar16 = (float)AbyssEngine::AEMath::operator*
                                (aAStack_b4,(Vector *)(param_1 + 7),
                                 *(float *)(ParticleSettingsRef::cur + iVar14 * 0x9c + 0x60));
      AbyssEngine::AEMath::operator*((AEMath *)&local_a8,(Vector *)aAStack_b4,fVar16);
      AbyssEngine::AEMath::Vector::operator+=((Vector *)(iVar8 + iVar7 * 0xc),(Vector *)&local_a8);
    }
    iVar7 = param_1[0x14] + 1;
    if (param_1[0x12] <= iVar7) {
      iVar7 = 0;
    }
    param_1[0x14] = iVar7;
  }
  if (__stack_chk_guard != local_6c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== IParticleSystem::setMatrix  @0x001b3608  (10 bytes)
/* IParticleSystem::setMatrix(AbyssEngine::AEMath::Matrix const*) */

void __thiscall IParticleSystem::setMatrix(IParticleSystem *this,Matrix *param_1)

{
  *(Matrix **)(this + 0x18) = param_1;
  *(undefined2 *)(this + 4) = 0x100;
  return;
}

