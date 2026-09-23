// Class: ParticleSystemMesh
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ParticleSystemMesh::ParticleSystemMesh  @0x001b646c  (300 bytes)
/* ParticleSystemMesh::ParticleSystemMesh(AbyssEngine::PaintCanvas*, AbyssEngine::AEMath::Matrix
   const*, Array<ParticleSettings::ParticleSet> const&, bool, bool) */

ParticleSystemMesh * __thiscall
ParticleSystemMesh::ParticleSystemMesh
          (ParticleSystemMesh *this,PaintCanvas *param_1,Matrix *param_2,Array *param_3,bool param_4
          ,bool param_5)

{
  longlong lVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  IParticleSystem::IParticleSystem((IParticleSystem *)this,param_1,param_2,param_3,param_4,param_5);
  *(undefined ***)this = &PTR_init_00264b00;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  uVar6 = *(uint *)(this + 0x34);
  iVar5 = -((int)(uVar6 << 0x13) >> 0x1f) - ((int)(uVar6 << 0x12) >> 0x1f);
  if ((uVar6 & 0x4000) != 0) {
    iVar5 = iVar5 + 1;
  }
  *(int *)(this + 0x98) = iVar5;
  this[0x74] = SUB41((uVar6 << 0xf) >> 0x1f,0);
  iVar2 = iVar5 << ((uVar6 & 0x1ffff) >> 0x10);
  *(int *)(this + 0x9c) = iVar2;
  uVar7 = *(uint *)(this + 0x48);
  iVar4 = uVar7 * iVar2 * 4;
  *(int *)(this + 0x70) = iVar4;
  if ((uVar6 & 0x8000) == 0) {
    uVar6 = (uint)((ulonglong)uVar7 * 0xc);
    if ((int)((ulonglong)uVar7 * 0xc >> 0x20) != 0) {
      uVar6 = 0xffffffff;
    }
    pvVar3 = operator_new__(uVar6);
    if (uVar7 == 0) goto LAB_001b6586;
    iVar5 = uVar7 * 0xc;
  }
  else {
    if (((*(int *)param_3 != 0) && (**(int **)(param_3 + 4) != -1)) &&
       (0.0 < *(float *)(ParticleSettingsRef::cur + **(int **)(param_3 + 4) * 0x9c + 0x3c))) {
      *(int *)(this + 0x70) = iVar4 + iVar2 * 4;
    }
    uVar8 = uVar7 * iVar5 * 2;
    lVar1 = (ulonglong)uVar8 * 0xc;
    uVar6 = (uint)lVar1;
    if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
      uVar6 = 0xffffffff;
    }
    pvVar3 = operator_new__(uVar6);
    if (uVar8 == 0) goto LAB_001b6586;
    iVar5 = uVar7 * iVar5 * 0x18;
  }
  __aeabi_memclr4(pvVar3,((iVar5 - 0xcU) / 0xc) * 0xc + 0xc);
LAB_001b6586:
  *(void **)(this + 100) = pvVar3;
  *(undefined8 *)(this + 0x78) = 0;
  return this;
}

// ===== ParticleSystemMesh::~ParticleSystemMesh  @0x001b65cc  (40 bytes)
/* ParticleSystemMesh::~ParticleSystemMesh() */

ParticleSystemMesh * __thiscall ParticleSystemMesh::~ParticleSystemMesh(ParticleSystemMesh *this)

{
  *(undefined ***)this = &PTR___cxa_pure_virtual_00264aa4;
  if (*(void **)(this + 0x3c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x3c));
  }
  *(undefined4 *)(this + 0x3c) = 0;
  AbyssEngine::AERandom::~AERandom((AERandom *)(this + 0x10));
  return this;
}

// ===== ParticleSystemMesh::startNewSection  @0x001b65f8  (8 bytes)
/* ParticleSystemMesh::startNewSection() */

void __thiscall ParticleSystemMesh::startNewSection(ParticleSystemMesh *this)

{
  this[0x90] = (ParticleSystemMesh)0x1;
  return;
}

// ===== ParticleSystemMesh::wasNewSectionStarted  @0x001b6600  (6 bytes)
/* ParticleSystemMesh::wasNewSectionStarted() */

ParticleSystemMesh __thiscall ParticleSystemMesh::wasNewSectionStarted(ParticleSystemMesh *this)

{
  return this[0x90];
}

// ===== ParticleSystemMesh::incId  @0x001b6606  (16 bytes)
/* ParticleSystemMesh::incId() */

void __thiscall ParticleSystemMesh::incId(ParticleSystemMesh *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x50) + 1;
  if (*(int *)(this + 0x48) <= iVar1) {
    iVar1 = 0;
  }
  *(int *)(this + 0x50) = iVar1;
  return;
}

// ===== ParticleSystemMesh::getPrevId  @0x001b6616  (8 bytes)
/* ParticleSystemMesh::getPrevId(int) */

int __thiscall ParticleSystemMesh::getPrevId(ParticleSystemMesh *this,int param_1)

{
  if (param_1 == 0) {
    param_1 = *(int *)(this + 0x48);
  }
  return param_1 + -1;
}

// ===== ParticleSystemMesh::finishCurrentTrailParticle  @0x001b661e  (90 bytes)
/* ParticleSystemMesh::finishCurrentTrailParticle(ParticleSettings::ParticleSet, int,
   AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&) */

void __thiscall
ParticleSystemMesh::finishCurrentTrailParticle
          (ParticleSystemMesh *this,undefined1 param_2,int param_3,Vector *param_4,Vector *param_5)

{
  uint uVar1;
  Vector *this_00;
  
  *(undefined1 *)(*(int *)(this + 0x6c) + param_3) = param_2;
  *(undefined4 *)(*(int *)(this + 0x68) + param_3 * 4) = 0;
  uVar1 = *(uint *)(this + 0x34);
  this_00 = (Vector *)(*(int *)(this + 100) + (*(int *)(this + 0x98) * param_3 * 2 | 1U) * 0xc);
  if ((uVar1 & 0x1000) != 0) {
    AbyssEngine::AEMath::Vector::operator=(this_00,param_4);
    uVar1 = *(uint *)(this + 0x34);
    this_00 = this_00 + 0x18;
  }
  if ((uVar1 & 0x2000) == 0) {
    return;
  }
  AbyssEngine::AEMath::Vector::operator=(this_00,param_5);
  return;
}

// ===== ParticleSystemMesh::emitTrail  @0x001b6678  (1810 bytes)
/* ParticleSystemMesh::emitTrail(int) */

void __thiscall ParticleSystemMesh::emitTrail(ParticleSystemMesh *this,int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  Vector *pVVar8;
  undefined4 uVar9;
  uint in_fpscr;
  uint uVar10;
  float fVar11;
  undefined4 extraout_s1;
  float extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined4 extraout_s1_02;
  undefined4 extraout_s1_03;
  undefined4 extraout_s1_04;
  undefined8 uVar12;
  float extraout_s1_05;
  float extraout_s1_06;
  float extraout_s1_07;
  float extraout_s1_08;
  float fVar13;
  float extraout_s3;
  float fVar14;
  float extraout_s5;
  float fVar15;
  AEMath aAStack_d8 [12];
  AEMath aAStack_cc [12];
  AEMath aAStack_c0 [12];
  AEMath aAStack_b4 [12];
  AEMath aAStack_a8 [12];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  AEMath aAStack_90 [12];
  AEMath aAStack_84 [12];
  AEMath aAStack_78 [12];
  AEMath aAStack_6c [12];
  AEMath aAStack_60 [12];
  AEMath aAStack_54 [12];
  AEMath aAStack_48 [12];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  iVar7 = *(int *)(*(int *)(this + 0x3c) + (uint)(byte)this[0x44] * 4);
  AbyssEngine::AEMath::MatrixGetRight(aAStack_54,*(Matrix **)(this + 0x18));
  AbyssEngine::AEMath::operator*(aAStack_48,(Vector *)aAStack_54,-1.0);
  AbyssEngine::AEMath::MatrixGetUp(aAStack_54,*(Matrix **)(this + 0x18));
  fVar11 = (float)AbyssEngine::AEMath::MatrixGetDir(aAStack_60,*(Matrix **)(this + 0x18));
  if (((byte)this[0x36] & 2) == 0) {
    pVVar8 = (Vector *)aAStack_48;
  }
  else {
    pVVar8 = (Vector *)aAStack_78;
    AbyssEngine::AEMath::operator+((AEMath *)pVVar8,(Vector *)aAStack_48,(Vector *)aAStack_54);
    fVar11 = *(float *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x10) * 0.70710677;
  }
  fVar11 = (float)AbyssEngine::AEMath::operator*(aAStack_6c,pVVar8,fVar11);
  if (((byte)this[0x36] & 2) == 0) {
    fVar11 = (float)AbyssEngine::AEMath::operator*(aAStack_78,(Vector *)aAStack_54,fVar11);
  }
  else {
    AbyssEngine::AEMath::operator-(aAStack_84,(Vector *)aAStack_54,(Vector *)aAStack_48);
    fVar11 = (float)AbyssEngine::AEMath::operator*
                              (aAStack_78,(Vector *)aAStack_84,
                               *(float *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x10) *
                               0.70710677);
  }
  AbyssEngine::AEMath::operator*(aAStack_84,(Vector *)aAStack_60,fVar11);
  local_9c = VectorSignedToFloat(*(undefined4 *)(this + 0x78),(byte)(in_fpscr >> 0x16) & 3);
  local_94 = VectorSignedToFloat(*(undefined4 *)(this + 0x7c),(byte)(in_fpscr >> 0x16) & 3);
  local_98 = 0;
  fVar11 = (float)AbyssEngine::AEMath::MatrixTransformVector
                            (aAStack_90,*(Matrix **)(this + 0x18),(Vector *)&local_9c);
  iVar6 = iVar7 * 0x9c;
  AbyssEngine::AEMath::operator*
            (aAStack_c0,fVar11,*(Vector **)(ParticleSettingsRef::cur + iVar6 + 0x74));
  fVar11 = (float)AbyssEngine::AEMath::operator+
                            (aAStack_b4,(Vector *)aAStack_90,(Vector *)aAStack_c0);
  AbyssEngine::AEMath::operator*
            (aAStack_cc,fVar11,*(Vector **)(ParticleSettingsRef::cur + iVar6 + 0x78));
  fVar11 = (float)AbyssEngine::AEMath::operator+
                            (aAStack_a8,(Vector *)aAStack_b4,(Vector *)aAStack_cc);
  AbyssEngine::AEMath::operator*
            (aAStack_d8,fVar11,*(Vector **)(ParticleSettingsRef::cur + iVar6 + 0x7c));
  AbyssEngine::AEMath::operator+((AEMath *)&local_9c,(Vector *)aAStack_a8,(Vector *)aAStack_d8);
  AbyssEngine::AEMath::Vector::operator=((Vector *)aAStack_90,(Vector *)&local_9c);
  fVar11 = *(float *)(ParticleSettingsRef::cur + iVar6 + 0x3c);
  uVar3 = in_fpscr & 0xfffffff | (uint)(fVar11 < 0.0) << 0x1f | (uint)(fVar11 == 0.0) << 0x1e;
  uVar10 = uVar3 | (uint)NAN(fVar11) << 0x1c;
  bVar1 = (byte)(uVar3 >> 0x18);
  uVar9 = extraout_s1;
  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar10 >> 0x1c) & 1)) {
    uVar9 = *(undefined4 *)(this + 0x50);
    AbyssEngine::AEMath::operator*((AEMath *)&local_9c,fVar11 * 0.5,(Vector *)(fVar11 * 0.5));
    AbyssEngine::AEMath::Vector::operator-=((Vector *)aAStack_90,(Vector *)&local_9c);
    iVar5 = iVar7 * 0x9c;
    fVar13 = *(float *)(ParticleSettingsRef::cur + iVar5 + 0x88);
    fVar15 = *(float *)(ParticleSettingsRef::cur + iVar5 + 0x90);
    fVar11 = *(float *)(ParticleSettingsRef::cur + iVar5 + 0x84);
    fVar14 = *(float *)(ParticleSettingsRef::cur + iVar5 + 0x8c);
    *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x48);
    local_9c = 0;
    local_98 = 0;
    local_94 = 0;
    setParticle((Vector *)this,fVar11,(uint)aAStack_90,extraout_s1_00,fVar13,extraout_s3,fVar14,
                SUB41(*(undefined4 *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x10),0),extraout_s5
                ,fVar13 + (fVar15 - fVar13) * 0.05,
                *(Vector **)(ParticleSettingsRef::cur + iVar5 + 0x30),SUB41(fVar11,0));
    *(undefined4 *)(this + 0x50) = uVar9;
    AbyssEngine::AEMath::operator*
              ((AEMath *)&local_9c,*(float *)(ParticleSettingsRef::cur + iVar6 + 0x3c) * 0.5,
               (Vector *)(*(float *)(ParticleSettingsRef::cur + iVar6 + 0x3c) * 0.5));
    AbyssEngine::AEMath::Vector::operator-=((Vector *)aAStack_90,(Vector *)&local_9c);
    uVar9 = extraout_s1_01;
  }
  if (this[0x90] == (ParticleSystemMesh)0x0) {
    uVar3 = *(uint *)(this + 0x34);
    iVar6 = *(int *)(this + 0x58) + *(int *)(this + 0x9c) * *(int *)(this + 0x50) * 4;
    if ((uVar3 & 0x1000) != 0) {
      setQuadEdge(this,(Vector *)aAStack_90,iVar6 + 2,(Vector *)aAStack_6c);
      iVar5 = 4;
      uVar3 = *(uint *)(this + 0x34);
      if (this[0x74] != (ParticleSystemMesh)0x0) {
        iVar5 = 8;
      }
      iVar6 = iVar6 + iVar5;
      uVar9 = extraout_s1_02;
    }
    if ((uVar3 & 0x2000) != 0) {
      setQuadEdge(this,(Vector *)aAStack_90,iVar6 + 2,(Vector *)aAStack_78);
      iVar5 = 4;
      uVar3 = *(uint *)(this + 0x34);
      if (this[0x74] != (ParticleSystemMesh)0x0) {
        iVar5 = 8;
      }
      iVar6 = iVar6 + iVar5;
      uVar9 = extraout_s1_03;
    }
    if ((uVar3 & 0x4000) != 0) {
      setQuadEdge(this,(Vector *)aAStack_90,iVar6 + 2,(Vector *)aAStack_84);
      uVar3 = *(uint *)(this + 0x34);
      uVar9 = extraout_s1_04;
    }
    if ((uVar3 & 0x100000) != 0) {
      VectorSignedToFloat(*(int *)(this + 0x94) + param_1,(byte)(uVar10 >> 0x16) & 3);
      uVar10 = uVar10 & 0xfffffff;
      if (0 < *(int *)(this + 0x9c)) {
        iVar6 = 0;
        uVar12 = CONCAT44(uVar9,*(undefined4 *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x84));
        iVar5 = *(int *)(this + 0x50) * *(int *)(this + 0x9c) * 4 + *(int *)(this + 0x58) + 3;
        do {
          uVar12 = AbyssEngine::PaintCanvas::MeshSetUv
                             (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),(ushort)iVar5 - 1,
                              (float)uVar12,(float)((ulonglong)uVar12 >> 0x20));
          uVar12 = AbyssEngine::PaintCanvas::MeshSetUv
                             (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),(ushort)iVar5,
                              (float)uVar12,(float)((ulonglong)uVar12 >> 0x20));
          iVar5 = iVar5 + 4;
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(this + 0x9c));
      }
    }
  }
  fVar11 = (float)VectorSignedToFloat(*(int *)(this + 0x94) + param_1,(byte)(uVar10 >> 0x16) & 3);
  *(int *)(this + 0x94) = *(int *)(this + 0x94) + param_1;
  fVar13 = *(float *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x28);
  uVar10 = uVar10 & 0xfffffff | (uint)(fVar11 < fVar13) << 0x1f | (uint)(fVar11 == fVar13) << 0x1e;
  uVar3 = uVar10 | (uint)(NAN(fVar11) || NAN(fVar13)) << 0x1c;
  bVar1 = (byte)(uVar10 >> 0x18);
  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar3 >> 0x1c) & 1)) {
    AbyssEngine::AEMath::operator-((AEMath *)&local_9c,(Vector *)(this + 0x80),(Vector *)aAStack_90)
    ;
    fVar11 = (float)AbyssEngine::AEMath::VectorDot((Vector *)&local_9c,(Vector *)&local_9c);
    uVar10 = uVar3 & 0xfffffff | (uint)(fVar11 < 6000.0) << 0x1f | (uint)(fVar11 == 6000.0) << 0x1e;
    uVar3 = uVar10 | (uint)NAN(fVar11) << 0x1c;
    bVar1 = (byte)(uVar10 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar3 >> 0x1c) & 1)) {
      this[0x90] = (ParticleSystemMesh)0x1;
    }
  }
  if (this[0x90] != (ParticleSystemMesh)0x0) {
    *(undefined4 *)(this + 0x94) = 0;
    iVar5 = *(int *)(this + 0x50);
    iVar6 = iVar5;
    if (iVar5 == 0) {
      iVar6 = *(int *)(this + 0x48);
    }
    fVar11 = (float)VectorSignedToFloat(*(undefined4 *)
                                         (ParticleSettingsRef::cur + iVar7 * 0x9c + 0x40),
                                        (byte)(uVar3 >> 0x16) & 3);
    iVar4 = *(int *)(*(int *)(this + 0x68) + iVar6 * 4 + -4);
    fVar11 = (float)AbyssEngine::AEMath::operator*((AEMath *)&local_9c,(Vector *)aAStack_48,fVar11);
    AbyssEngine::AEMath::operator*(aAStack_a8,(Vector *)aAStack_54,fVar11);
    finishCurrentTrailParticle(this,iVar7,iVar5,(AEMath *)&local_9c,aAStack_a8);
    iVar6 = 0;
    if (*(int *)(this + 0x50) + 1 < *(int *)(this + 0x48)) {
      iVar6 = *(int *)(this + 0x50) + 1;
    }
    *(int *)(this + 0x50) = iVar6;
    uVar10 = *(uint *)(this + 0x34);
    iVar5 = *(int *)(this + 0x58) + iVar6 * *(int *)(this + 0x9c) * 4;
    pVVar8 = (Vector *)(*(int *)(this + 100) + iVar6 * *(int *)(this + 0x98) * 0x18);
    if ((uVar10 & 0x1000) != 0) {
      setQuadEdge(this,(Vector *)aAStack_90,iVar5,(Vector *)aAStack_6c);
      fVar11 = (float)setQuadEdge(this,(Vector *)aAStack_90,iVar5 + 2,(Vector *)aAStack_6c);
      AbyssEngine::AEMath::operator*((AEMath *)&local_9c,(Vector *)aAStack_48,fVar11);
      AbyssEngine::AEMath::Vector::operator=(pVVar8,(Vector *)&local_9c);
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      AbyssEngine::AEMath::Vector::operator=(pVVar8 + 0xc,(Vector *)&local_9c);
      iVar6 = 8;
      uVar10 = *(uint *)(this + 0x34);
      pVVar8 = pVVar8 + 0x18;
      if (this[0x74] == (ParticleSystemMesh)0x0) {
        iVar6 = 4;
      }
      iVar5 = iVar5 + iVar6;
    }
    if ((uVar10 & 0x2000) != 0) {
      setQuadEdge(this,(Vector *)aAStack_90,iVar5,(Vector *)aAStack_78);
      fVar11 = (float)setQuadEdge(this,(Vector *)aAStack_90,iVar5 + 2,(Vector *)aAStack_78);
      AbyssEngine::AEMath::operator*((AEMath *)&local_9c,(Vector *)aAStack_54,fVar11);
      AbyssEngine::AEMath::Vector::operator=(pVVar8,(Vector *)&local_9c);
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      AbyssEngine::AEMath::Vector::operator=(pVVar8 + 0xc,(Vector *)&local_9c);
    }
    AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x80),(Vector *)aAStack_90);
    uVar3 = *(uint *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x30);
    uVar10 = uVar3;
    if (iVar4 == -1) {
      uVar10 = 0xffffff00;
      if (this[0x45] != (ParticleSystemMesh)0x0) {
        uVar10 = 0xff;
      }
      uVar10 = uVar10 & uVar3;
    }
    iVar6 = *(int *)(this + 0x50);
    if (0 < *(int *)(this + 0x9c)) {
      iVar5 = 0;
      iVar6 = *(int *)(this + 0x9c) * iVar6 * 4 + *(int *)(this + 0x58) + 3;
      do {
        uVar2 = (ushort)iVar6;
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2 - 3,uVar10);
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2 - 2,uVar10);
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2 - 1,uVar3);
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2,uVar3);
        AbyssEngine::PaintCanvas::MeshSetUv
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2 - 3,
                   *(float *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x88),extraout_s1_05);
        AbyssEngine::PaintCanvas::MeshSetUv
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2 - 2,
                   *(float *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x88),extraout_s1_06);
        AbyssEngine::PaintCanvas::MeshSetUv
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2 - 1,
                   *(float *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x90),extraout_s1_07);
        AbyssEngine::PaintCanvas::MeshSetUv
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar2,
                   *(float *)(ParticleSettingsRef::cur + iVar7 * 0x9c + 0x90),extraout_s1_08);
        iVar6 = iVar6 + 4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(this + 0x9c));
      iVar6 = *(int *)(this + 0x50);
    }
    *(undefined4 *)(*(int *)(this + 0x68) + iVar6 * 4) = 0xfffffffe;
    this[0x90] = (ParticleSystemMesh)0x0;
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ParticleSystemMesh::setParticle  @0x001b6dcc  (882 bytes)
/* ParticleSystemMesh::setParticle(AbyssEngine::AEMath::Vector const&, float, unsigned int, float,
   float, float, float, bool, float, float, AbyssEngine::AEMath::Vector const&, bool) */

void ParticleSystemMesh::setParticle
               (Vector *param_1,float param_2,uint param_3,float param_4,float param_5,float param_6
               ,float param_7,bool param_8,float param_9,float param_10,Vector *param_11,
               bool param_12)

{
  ushort uVar1;
  uint uVar2;
  Vector *pVVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  undefined8 uVar7;
  int in_stack_00000010;
  float in_stack_00000014;
  Vector *in_stack_0000001c;
  int in_stack_00000020;
  AEMath aAStack_8c [12];
  AEMath aAStack_80 [12];
  AEMath aAStack_74 [12];
  AEMath aAStack_68 [12];
  AEMath aAStack_5c [12];
  AEMath aAStack_50 [12];
  int local_44;
  
  local_44 = __stack_chk_guard;
  fVar6 = (float)AbyssEngine::AEMath::MatrixGetRight(aAStack_5c,*(Matrix **)(param_1 + 0x18));
  AbyssEngine::AEMath::operator*(aAStack_50,(Vector *)aAStack_5c,fVar6);
  if (param_1[0x4c] != (Vector)0x0) {
    AbyssEngine::AEMath::operator-(aAStack_5c,(Vector *)aAStack_50);
    AbyssEngine::AEMath::Vector::operator=((Vector *)aAStack_50,(Vector *)aAStack_5c);
  }
  AbyssEngine::AEMath::MatrixGetUp(aAStack_68,*(Matrix **)(param_1 + 0x18));
  fVar6 = (float)(uint)param_8;
  if (in_stack_00000014 != 0.0) {
    fVar6 = in_stack_00000014;
  }
  AbyssEngine::AEMath::operator*(aAStack_5c,(Vector *)aAStack_68,fVar6);
  fVar6 = (float)AbyssEngine::AEMath::MatrixGetDir(aAStack_74,*(Matrix **)(param_1 + 0x18));
  AbyssEngine::AEMath::operator*(aAStack_68,(Vector *)aAStack_74,fVar6);
  uVar2 = *(uint *)(param_1 + 0x34);
  if ((uVar2 & 0x20000) != 0) {
    fVar6 = (float)AbyssEngine::AEMath::operator-
                             (aAStack_80,(Vector *)aAStack_5c,(Vector *)aAStack_50);
    AbyssEngine::AEMath::operator*(aAStack_74,(Vector *)aAStack_80,fVar6);
    fVar6 = (float)AbyssEngine::AEMath::operator+
                             (aAStack_8c,(Vector *)aAStack_50,(Vector *)aAStack_5c);
    AbyssEngine::AEMath::operator*(aAStack_80,(Vector *)aAStack_8c,fVar6);
    AbyssEngine::AEMath::Vector::operator=((Vector *)aAStack_50,(Vector *)aAStack_80);
    AbyssEngine::AEMath::Vector::operator=((Vector *)aAStack_5c,(Vector *)aAStack_74);
    uVar2 = *(uint *)(param_1 + 0x34);
  }
  iVar5 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x9c) * *(int *)(param_1 + 0x50) * 4;
  if ((uVar2 & 0x1000) != 0) {
    AbyssEngine::AEMath::operator-(aAStack_80,(Vector *)param_3,(Vector *)aAStack_68);
    AbyssEngine::AEMath::operator-(aAStack_74,(Vector *)aAStack_80,in_stack_0000001c);
    setQuadEdge((ParticleSystemMesh *)param_1,(Vector *)aAStack_74,iVar5,(Vector *)aAStack_50);
    AbyssEngine::AEMath::operator+(aAStack_80,(Vector *)param_3,(Vector *)aAStack_68);
    AbyssEngine::AEMath::operator+(aAStack_74,(Vector *)aAStack_80,in_stack_0000001c);
    setQuadEdge((ParticleSystemMesh *)param_1,(Vector *)aAStack_74,iVar5 + 2,(Vector *)aAStack_50);
    iVar4 = 8;
    uVar2 = *(uint *)(param_1 + 0x34);
    if (param_1[0x74] == (Vector)0x0) {
      iVar4 = 4;
    }
    iVar5 = iVar5 + iVar4;
  }
  if ((uVar2 & 0x2000) != 0) {
    AbyssEngine::AEMath::operator-(aAStack_80,(Vector *)param_3,(Vector *)aAStack_68);
    AbyssEngine::AEMath::operator+(aAStack_74,(Vector *)aAStack_80,in_stack_0000001c);
    setQuadEdge((ParticleSystemMesh *)param_1,(Vector *)aAStack_74,iVar5,(Vector *)aAStack_5c);
    AbyssEngine::AEMath::operator+(aAStack_80,(Vector *)param_3,(Vector *)aAStack_68);
    AbyssEngine::AEMath::operator-(aAStack_74,(Vector *)aAStack_80,in_stack_0000001c);
    setQuadEdge((ParticleSystemMesh *)param_1,(Vector *)aAStack_74,iVar5 + 2,(Vector *)aAStack_5c);
    iVar4 = 8;
    uVar2 = *(uint *)(param_1 + 0x34);
    if (param_1[0x74] == (Vector)0x0) {
      iVar4 = 4;
    }
    iVar5 = iVar5 + iVar4;
  }
  if ((uVar2 & 0x4000) != 0) {
    AbyssEngine::AEMath::operator+(aAStack_74,(Vector *)param_3,(Vector *)aAStack_5c);
    setQuadEdge((ParticleSystemMesh *)param_1,(Vector *)aAStack_74,iVar5,(Vector *)aAStack_50);
    AbyssEngine::AEMath::operator-(aAStack_74,(Vector *)param_3,(Vector *)aAStack_5c);
    setQuadEdge((ParticleSystemMesh *)param_1,(Vector *)aAStack_74,iVar5 + 2,(Vector *)aAStack_50);
  }
  pVVar3 = param_11;
  if ((in_stack_00000010 == 1) && (in_stack_00000020 == 0)) {
    uVar2 = 0xffffff00;
    if (param_1[0x45] != (Vector)0x0) {
      uVar2 = 0xff;
    }
    pVVar3 = (Vector *)(uVar2 & (uint)param_11);
  }
  if (in_stack_00000020 == 1) {
    uVar2 = 0xffffff00;
    if (param_1[0x45] != (Vector)0x0) {
      uVar2 = 0xff;
    }
    param_11 = (Vector *)((uint)param_11 & uVar2);
  }
  if (0 < *(int *)(param_1 + 0x9c)) {
    iVar4 = 0;
    iVar5 = *(int *)(param_1 + 0x50) * *(int *)(param_1 + 0x9c) * 4 + *(int *)(param_1 + 0x58) + 3;
    do {
      uVar1 = (ushort)iVar5;
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1 - 3,(uint)param_11);
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1 - 2,(uint)param_11);
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1 - 1,(uint)pVVar3);
      uVar7 = AbyssEngine::PaintCanvas::MeshSetColor
                        (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1,(uint)pVVar3
                        );
      uVar7 = AbyssEngine::PaintCanvas::MeshSetUv
                        (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1 - 3,
                         (float)uVar7,(float)((ulonglong)uVar7 >> 0x20));
      uVar7 = AbyssEngine::PaintCanvas::MeshSetUv
                        (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1 - 2,
                         (float)uVar7,(float)((ulonglong)uVar7 >> 0x20));
      uVar7 = AbyssEngine::PaintCanvas::MeshSetUv
                        (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1 - 1,
                         (float)uVar7,(float)((ulonglong)uVar7 >> 0x20));
      AbyssEngine::PaintCanvas::MeshSetUv
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),uVar1,(float)uVar7,
                 (float)((ulonglong)uVar7 >> 0x20));
      iVar5 = iVar5 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x9c));
  }
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ParticleSystemMesh::setQuadEdge  @0x001b7148  (232 bytes)
/* ParticleSystemMesh::setQuadEdge(AbyssEngine::AEMath::Vector const&, int,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
ParticleSystemMesh::setQuadEdge
          (ParticleSystemMesh *this,Vector *param_1,int param_2,Vector *param_3)

{
  ushort uVar1;
  PaintCanvas *this_00;
  uint uVar2;
  ushort uVar3;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float fVar4;
  AEMath aAStack_3c [12];
  AEMath local_30 [4];
  float local_2c;
  float local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  AbyssEngine::AEMath::operator-(local_30,param_1,param_3);
  uVar1 = (ushort)param_2;
  AbyssEngine::PaintCanvas::MeshSetPoint
            (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar1,local_2c,extraout_s1,local_28)
  ;
  AbyssEngine::AEMath::operator+(aAStack_3c,param_1,param_3);
  AbyssEngine::AEMath::Vector::operator=((Vector *)local_30,(Vector *)aAStack_3c);
  this_00 = *(PaintCanvas **)(this + 8);
  uVar3 = uVar1 + 1;
  uVar2 = *(uint *)(this + 0x54);
  fVar4 = extraout_s1_00;
  if (this[0x74] != (ParticleSystemMesh)0x0) {
    AbyssEngine::PaintCanvas::MeshSetPoint
              (this_00,uVar2,uVar3,*(float *)(param_1 + 4),extraout_s1_00,*(float *)(param_1 + 8));
    AbyssEngine::PaintCanvas::MeshSetPoint
              (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar1 + 5,*(float *)(param_1 + 4),
               extraout_s1_01,*(float *)(param_1 + 8));
    this_00 = *(PaintCanvas **)(this + 8);
    uVar3 = uVar1 + 4;
    uVar2 = *(uint *)(this + 0x54);
    fVar4 = extraout_s1_02;
  }
  AbyssEngine::PaintCanvas::MeshSetPoint(this_00,uVar2,uVar3,local_2c,fVar4,local_28);
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ParticleSystemMesh::emit  @0x001b7238  (48 bytes)
/* ParticleSystemMesh::emit(int) */

void ParticleSystemMesh::emit(int param_1)

{
  ushort uVar1;
  int in_r1;
  bool bVar2;
  undefined1 in_CY;
  
  uVar1 = *(ushort *)(param_1 + 0xc);
  bVar2 = (uVar1 & 0xff) != 0;
  if (bVar2) {
    in_CY = 0xfe < uVar1;
  }
  if (!(bool)in_CY || (!bVar2 || uVar1 == 0xff)) {
    *(undefined1 *)(param_1 + 0x90) = 1;
    return;
  }
  if ((*(uint *)(param_1 + 0x34) & 0x80) != 0) {
    return;
  }
  if ((*(uint *)(param_1 + 0x34) & 0x8000) == 0) {
    IParticleSystem::emit((IParticleSystem *)param_1,in_r1);
    return;
  }
  emitTrail((ParticleSystemMesh *)param_1,in_r1);
  return;
}

// ===== ParticleSystemMesh::render  @0x001b7264  (14 bytes)
/* ParticleSystemMesh::render(AbyssEngine::PaintCanvas*, unsigned int) */

void ParticleSystemMesh::render(PaintCanvas *param_1,uint param_2)

{
  if (param_2 != 0xffffffff) {
    AbyssEngine::PaintCanvas::DrawTransform(param_1,param_2,(Matrix *)0x0);
    return;
  }
  return;
}

// ===== ParticleSystemMesh::render  @0x001b7272  (74 bytes)
/* ParticleSystemMesh::render(AbyssEngine::PaintCanvas*, unsigned int, unsigned int,
   AbyssEngine::BlendMode) */

void ParticleSystemMesh::render(PaintCanvas *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  Matrix *pMVar2;
  
  if (param_2 == 0xffffffff) {
    return;
  }
  AbyssEngine::PaintCanvas::SetTexture(param_1,param_3,0xffffffff);
  AbyssEngine::PaintCanvas::SetBlendMode(param_1,param_4);
  uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(param_1);
  pMVar2 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(param_1,uVar1);
  AbyssEngine::PaintCanvas::DrawTransform(param_1,param_2,pMVar2);
  return;
}

// ===== ParticleSystemMesh::reset  @0x001b72ba  (94 bytes)
/* ParticleSystemMesh::reset() */

void ParticleSystemMesh::reset(void)

{
  int in_r0;
  int iVar1;
  int iVar2;
  float in_s0;
  float extraout_s0;
  float in_s1;
  float extraout_s1;
  float in_s2;
  float extraout_s2;
  
  if (0 < *(int *)(in_r0 + 0x70)) {
    iVar2 = 0;
    do {
      AbyssEngine::PaintCanvas::MeshSetPoint
                (*(PaintCanvas **)(in_r0 + 8),*(uint *)(in_r0 + 0x54),
                 (short)*(undefined4 *)(in_r0 + 0x58) + (short)iVar2,in_s0,in_s1,in_s2);
      iVar2 = iVar2 + 1;
      in_s0 = extraout_s0;
      in_s1 = extraout_s1;
      in_s2 = extraout_s2;
    } while (iVar2 < *(int *)(in_r0 + 0x70));
  }
  if (0 < *(int *)(in_r0 + 0x48)) {
    iVar2 = *(int *)(in_r0 + 0x68);
    iVar1 = 0;
    do {
      *(undefined4 *)(iVar2 + iVar1 * 4) = 0xffffffff;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_r0 + 0x48));
  }
  *(undefined4 *)(in_r0 + 0x50) = 0;
  *(undefined4 *)(in_r0 + 0x94) = 0;
  *(undefined1 *)(in_r0 + 0x90) = 1;
  *(undefined4 *)(in_r0 + 0x60) = 0;
  *(undefined1 *)(in_r0 + 4) = 1;
  return;
}

// ===== ParticleSystemMesh::init  @0x001b7318  (310 bytes)
/* ParticleSystemMesh::init(unsigned int, unsigned short) */

void ParticleSystemMesh::init(uint param_1,ushort param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 in_r2;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_s0;
  undefined4 in_s1;
  undefined8 uVar7;
  
  uVar7 = CONCAT44(in_s1,in_s0);
  uVar6 = (uint)param_2;
  *(uint *)(param_1 + 0x54) = uVar6;
  *(undefined4 *)(param_1 + 0x58) = in_r2;
  iVar3 = *(int *)(param_1 + 0x70);
  if (0 < iVar3) {
    iVar5 = 0;
    while( true ) {
      sVar1 = (short)iVar5;
      uVar7 = AbyssEngine::PaintCanvas::MeshSetUv
                        (*(PaintCanvas **)(param_1 + 8),uVar6,(short)in_r2 + sVar1,(float)uVar7,
                         (float)((ulonglong)uVar7 >> 0x20));
      uVar7 = AbyssEngine::PaintCanvas::MeshSetUv
                        (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                         (short)*(undefined4 *)(param_1 + 0x58) + sVar1 + 1,(float)uVar7,
                         (float)((ulonglong)uVar7 >> 0x20));
      uVar7 = AbyssEngine::PaintCanvas::MeshSetUv
                        (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                         (short)*(undefined4 *)(param_1 + 0x58) + sVar1 + 2,(float)uVar7,
                         (float)((ulonglong)uVar7 >> 0x20));
      AbyssEngine::PaintCanvas::MeshSetUv
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                 (short)*(undefined4 *)(param_1 + 0x58) + sVar1 + 3,(float)uVar7,
                 (float)((ulonglong)uVar7 >> 0x20));
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                 (short)*(undefined4 *)(param_1 + 0x58) + sVar1,0);
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                 (short)*(undefined4 *)(param_1 + 0x58) + sVar1 + 1,0);
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                 (short)*(undefined4 *)(param_1 + 0x58) + sVar1 + 2,0);
      uVar7 = AbyssEngine::PaintCanvas::MeshSetColor
                        (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                         (short)*(undefined4 *)(param_1 + 0x58) + sVar1 + 3,0);
      iVar3 = *(int *)(param_1 + 0x70);
      iVar5 = iVar5 + 4;
      if (iVar3 <= iVar5) break;
      uVar6 = *(uint *)(param_1 + 0x54);
      in_r2 = *(undefined4 *)(param_1 + 0x58);
    }
  }
  if (0 < iVar3 >> 1) {
    uVar4 = *(uint *)(param_1 + 0x58);
    iVar3 = 2;
    uVar6 = uVar4;
    while( true ) {
      uVar2 = (ushort)uVar6;
      AbyssEngine::PaintCanvas::MeshSetTriangle
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                 ((short)iVar3 + (short)(uVar4 >> 1)) - 2,uVar2 + 2,uVar2 + 1,uVar2);
      AbyssEngine::PaintCanvas::MeshSetTriangle
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                 ((short)iVar3 + (short)(*(uint *)(param_1 + 0x58) >> 1)) - 1,uVar2 + 1,uVar2 + 2,
                 uVar2 + 3);
      if (*(int *)(param_1 + 0x70) >> 1 <= iVar3) break;
      iVar3 = iVar3 + 2;
      uVar4 = *(uint *)(param_1 + 0x58);
      uVar6 = uVar6 + 4;
    }
  }
  *(undefined1 *)(param_1 + 0x5c) = 1;
                    /* WARNING: Could not recover jumptable at 0x001b744c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)param_1 + 8))(param_1);
  return;
}

// ===== ParticleSystemMesh::release  @0x001b744e  (2 bytes)
/* ParticleSystemMesh::release() */

void ParticleSystemMesh::release(void)

{
  return;
}

// ===== ParticleSystemMesh::updateSingleColor  @0x001b7450  (576 bytes)
/* ParticleSystemMesh::updateSingleColor(int) */

void ParticleSystemMesh::updateSingleColor(int param_1)

{
  int iVar1;
  int in_r1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint in_fpscr;
  float in_s1;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s1_05;
  float in_s3;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s3_01;
  float extraout_s3_02;
  float extraout_s3_03;
  float extraout_s3_04;
  float extraout_s3_05;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  iVar1 = *(int *)(param_1 + 0x9c);
  iVar6 = *(int *)(param_1 + 0x58);
  iVar4 = in_r1 * iVar1;
  if ((*(byte *)(param_1 + 0x35) & 0x80) != 0) {
    iVar2 = in_r1;
    if (in_r1 == 0) {
      iVar2 = *(int *)(param_1 + 0x48);
    }
    if (*(int *)(*(int *)(param_1 + 0x68) + iVar2 * 4 + -4) == -1) {
      uVar3 = 0xffffff00;
      if (*(char *)(param_1 + 0x45) != '\0') {
        uVar3 = 0xff;
      }
      uVar3 = *(uint *)(ParticleSettingsRef::cur +
                       *(char *)(*(int *)(param_1 + 0x6c) + in_r1) * 0x9c + 0x34) & uVar3;
      local_28 = (float)VectorUnsignedToFloat(uVar3 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
      local_2c = (float)VectorUnsignedToFloat
                                  ((uVar3 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
      local_30 = (float)VectorUnsignedToFloat((uVar3 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
      local_34 = (float)VectorUnsignedToFloat(uVar3 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
      local_28 = local_28 * 0.003921569;
      local_2c = local_2c * 0.003921569;
      local_30 = local_30 * 0.003921569;
      local_34 = local_34 * 0.003921569;
      goto LAB_001b7524;
    }
  }
  IParticleSystem::interpolateColor
            ((IParticleSystem *)param_1,in_r1,&local_28,&local_2c,&local_30,&local_34);
  iVar1 = *(int *)(param_1 + 0x9c);
  in_s1 = extraout_s1;
  in_s3 = extraout_s3;
LAB_001b7524:
  iVar4 = iVar4 * 4;
  if (0 < iVar1) {
    iVar2 = 0;
    iVar5 = iVar6 + iVar4 + 3;
    do {
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),(ushort)iVar5 - 1,local_2c
                 ,in_s1,local_30,in_s3);
      AbyssEngine::PaintCanvas::MeshSetColor
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),(ushort)iVar5,local_2c,
                 extraout_s1_00,local_30,extraout_s3_00);
      iVar1 = *(int *)(param_1 + 0x9c);
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + 4;
      in_s1 = extraout_s1_01;
      in_s3 = extraout_s3_01;
    } while (iVar2 < iVar1);
  }
  if ((*(byte *)(param_1 + 0x35) & 0x80) == 0) {
    if (0 < iVar1) {
      iVar2 = 0;
      iVar1 = iVar6 + iVar4 + 1;
      do {
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),(ushort)iVar1 - 1,
                   local_2c,in_s1,local_30,in_s3);
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),(ushort)iVar1,local_2c,
                   extraout_s1_02,local_30,extraout_s3_02);
        iVar1 = iVar1 + 4;
        iVar2 = iVar2 + 1;
        in_s1 = extraout_s1_03;
        in_s3 = extraout_s3_03;
      } while (iVar2 < *(int *)(param_1 + 0x9c));
    }
  }
  else {
    iVar4 = in_r1 + 1;
    if (*(int *)(param_1 + 0x48) + -1 == in_r1) {
      iVar4 = 0;
    }
    if ((*(int *)(*(int *)(param_1 + 0x68) + iVar4 * 4) != -1) && (0 < iVar1)) {
      iVar6 = 0;
      iVar1 = iVar4 * iVar1 * 4 + *(int *)(param_1 + 0x58) + 1;
      do {
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),(ushort)iVar1 - 1,
                   local_2c,in_s1,local_30,in_s3);
        AbyssEngine::PaintCanvas::MeshSetColor
                  (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),(ushort)iVar1,local_2c,
                   extraout_s1_04,local_30,extraout_s3_04);
        iVar1 = iVar1 + 4;
        iVar6 = iVar6 + 1;
        in_s1 = extraout_s1_05;
        in_s3 = extraout_s3_05;
      } while (iVar6 < *(int *)(param_1 + 0x9c));
    }
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ParticleSystemMesh::updateUsualEdges  @0x001b76a0  (208 bytes)
/* ParticleSystemMesh::updateUsualEdges(int, int) */

void __thiscall
ParticleSystemMesh::updateUsualEdges(ParticleSystemMesh *this,int param_1,int param_2)

{
  Vector *pVVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint in_fpscr;
  float fVar5;
  float extraout_s1;
  float extraout_s1_00;
  float fVar6;
  AEMath aAStack_38 [12];
  undefined4 local_2c;
  float local_28;
  float local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  uVar3 = *(undefined4 *)(this + 0x58);
  uVar4 = *(undefined4 *)(this + 0x9c);
  local_2c = 0;
  local_28 = 0.0;
  local_24 = 0.0;
  if (((byte)this[0x36] & 8) == 0) {
    fVar5 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar6 = 0.001;
    pVVar1 = (Vector *)(*(int *)(this + 100) + param_1 * 0xc);
  }
  else {
    fVar5 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    pVVar1 = (Vector *)(this + 0x1c);
    fVar5 = fVar5 * 0.001;
    fVar6 = *(float *)(*(int *)(this + 100) + param_1 * 0xc + 4);
  }
  AbyssEngine::AEMath::operator*(aAStack_38,pVVar1,fVar5 * fVar6);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_2c,(Vector *)aAStack_38);
  if (0 < *(int *)(this + 0x9c)) {
    iVar2 = 0;
    fVar5 = extraout_s1;
    do {
      AbyssEngine::PaintCanvas::MeshTranslatePoint
                (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),
                 (short)uVar3 + (short)param_1 * (short)uVar4 * 4 + (short)iVar2,local_28,fVar5,
                 local_24);
      iVar2 = iVar2 + 1;
      fVar5 = extraout_s1_00;
    } while (iVar2 < *(int *)(this + 0x9c) * 4);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ParticleSystemMesh::updateTrailEdges  @0x001b777c  (362 bytes)
/* ParticleSystemMesh::updateTrailEdges(int, int) */

void __thiscall
ParticleSystemMesh::updateTrailEdges(ParticleSystemMesh *this,int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  Vector *pVVar3;
  short sVar4;
  int iVar5;
  Vector *pVVar6;
  int iVar7;
  uint in_fpscr;
  float fVar8;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  AEMath local_40 [4];
  float local_3c;
  float local_38;
  AEMath local_34 [4];
  float local_30;
  float local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (0 < *(int *)(this + 0x98)) {
    iVar7 = 0;
    fVar8 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar8 = fVar8 * 0.001;
    iVar5 = *(int *)(this + 0x58) + param_1 * *(int *)(this + 0x9c) * 4;
    pVVar6 = (Vector *)(*(int *)(this + 100) + param_1 * *(int *)(this + 0x98) * 0x18);
    do {
      AbyssEngine::AEMath::operator*(local_34,pVVar6,fVar8);
      uVar1 = (ushort)iVar5;
      AbyssEngine::PaintCanvas::MeshTranslatePoint
                (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar1,-local_2c,extraout_s1,
                 -local_30);
      sVar4 = 1;
      if (this[0x74] != (ParticleSystemMesh)0x0) {
        sVar4 = 4;
      }
      fVar8 = (float)AbyssEngine::PaintCanvas::MeshTranslatePoint
                               (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),sVar4 + uVar1,
                                local_30,extraout_s1_00,local_2c);
      pVVar3 = pVVar6 + 0xc;
      if ((*(int *)(*(int *)(this + 0x68) + param_1 * 4) != -2) || (((byte)this[0x35] & 0x80) == 0))
      {
        AbyssEngine::AEMath::operator*(local_40,pVVar3,fVar8);
        AbyssEngine::PaintCanvas::MeshTranslatePoint
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),uVar1 + 2,-local_38,
                   extraout_s1_01,-local_3c);
        sVar4 = 1;
        if (this[0x74] != (ParticleSystemMesh)0x0) {
          sVar4 = 4;
        }
        fVar8 = (float)AbyssEngine::PaintCanvas::MeshTranslatePoint
                                 (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),
                                  sVar4 + uVar1 + 2,local_3c,extraout_s1_02,local_38);
        pVVar3 = pVVar6 + 0x18;
        iVar2 = 4;
        if (this[0x74] != (ParticleSystemMesh)0x0) {
          iVar2 = 8;
        }
        iVar5 = iVar5 + iVar2;
      }
      iVar7 = iVar7 + 1;
      pVVar6 = pVVar3;
    } while (iVar7 < *(int *)(this + 0x98));
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ParticleSystemMesh::setParticle  @0x001b78f4  (80 bytes)
/* ParticleSystemMesh::setParticle(AbyssEngine::AEMath::Vector const&, float, unsigned int, float,
   float, float, float, bool, float, float, AbyssEngine::AEMath::Vector const&) */

void ParticleSystemMesh::setParticle
               (Vector *param_1,float param_2,uint param_3,float param_4,float param_5,float param_6
               ,float param_7,bool param_8,float param_9,float param_10,Vector *param_11)

{
  bool in_stack_00000000;
  float in_stack_00000004;
  float in_stack_00000008;
  float in_stack_0000000c;
  float in_stack_00000014;
  
  setParticle(param_1,in_stack_00000014,param_3,param_4,in_stack_0000000c,param_6,in_stack_00000008,
              param_8,param_9,in_stack_00000004,param_11,in_stack_00000000);
  return;
}

// ===== ParticleSystemMesh::updateSingle  @0x001b7944  (388 bytes)
/* ParticleSystemMesh::updateSingle(int, float) */

void __thiscall ParticleSystemMesh::updateSingle(ParticleSystemMesh *this,int param_1,float param_2)

{
  int iVar1;
  undefined4 uVar2;
  float in_r2;
  undefined4 uVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float fVar6;
  float extraout_s1_00;
  float extraout_s2;
  float fVar7;
  float extraout_s2_00;
  AEMath aAStack_64 [12];
  AEMath aAStack_58 [12];
  AEMath aAStack_4c [12];
  AEMath aAStack_40 [12];
  int local_34;
  
  local_34 = __stack_chk_guard;
  iVar4 = (int)*(char *)(*(int *)(this + 0x6c) + param_1);
  if (((byte)this[0x35] & 0x80) == 0) {
    updateUsualEdges(this,param_1,(int)in_r2);
  }
  else {
    updateTrailEdges(this,param_1,(int)in_r2);
    if (*(int *)(*(int *)(this + 0x68) + param_1 * 4) == -2) {
      if (this[0x90] == (ParticleSystemMesh)0x0) goto LAB_001b7aaa;
      AbyssEngine::AEMath::MatrixGetRight(aAStack_4c,*(Matrix **)(this + 0x18));
      fVar5 = 1.0;
      if (this[0x4c] != (ParticleSystemMesh)0x0) {
        fVar5 = -1.0;
      }
      AbyssEngine::AEMath::operator*(aAStack_40,(Vector *)aAStack_4c,fVar5);
      AbyssEngine::AEMath::MatrixGetUp(aAStack_4c,*(Matrix **)(this + 0x18));
      fVar5 = (float)VectorSignedToFloat(*(undefined4 *)
                                          (ParticleSettingsRef::cur + iVar4 * 0x9c + 0x40),
                                         (byte)(in_fpscr >> 0x16) & 3);
      fVar5 = (float)AbyssEngine::AEMath::operator*(aAStack_58,(Vector *)aAStack_40,fVar5);
      AbyssEngine::AEMath::operator*(aAStack_64,(Vector *)aAStack_4c,fVar5);
      finishCurrentTrailParticle(this,iVar4,param_1,aAStack_58,aAStack_64);
    }
  }
  iVar1 = *(int *)(this + 0x68);
  fVar5 = (float)VectorSignedToFloat(*(undefined4 *)(iVar1 + param_1 * 4),
                                     (byte)(in_fpscr >> 0x16) & 3);
  *(int *)(iVar1 + param_1 * 4) = (int)(fVar5 + in_r2);
  updateSingleColor((int)this);
  iVar1 = *(int *)(this + 0x68);
  if (*(int *)(ParticleSettingsRef::cur + iVar4 * 0x9c + 0x24) < *(int *)(iVar1 + param_1 * 4)) {
    uVar2 = *(undefined4 *)(this + 0x58);
    uVar3 = *(undefined4 *)(this + 0x9c);
    *(undefined4 *)(iVar1 + param_1 * 4) = 0xffffffff;
    if (0 < *(int *)(this + 0x9c)) {
      iVar4 = 0;
      fVar5 = extraout_s0;
      fVar6 = extraout_s1;
      fVar7 = extraout_s2;
      do {
        AbyssEngine::PaintCanvas::MeshSetPoint
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),
                   (short)uVar2 + (short)uVar3 * (short)param_1 * 4 + (short)iVar4,fVar5,fVar6,fVar7
                  );
        iVar4 = iVar4 + 1;
        fVar5 = extraout_s0_00;
        fVar6 = extraout_s1_00;
        fVar7 = extraout_s2_00;
      } while (iVar4 < *(int *)(this + 0x9c) * 4);
    }
  }
LAB_001b7aaa:
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ParticleSystemMesh::getQuadCount  @0x001b7ad8  (6 bytes)
/* ParticleSystemMesh::getQuadCount() */

int __thiscall ParticleSystemMesh::getQuadCount(ParticleSystemMesh *this)

{
  return *(int *)(this + 0x70) >> 2;
}

