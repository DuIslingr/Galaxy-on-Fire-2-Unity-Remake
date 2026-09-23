// Class: ParticleSystemSprite
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ParticleSystemSprite::ParticleSystemSprite  @0x001b364c  (140 bytes)
/* ParticleSystemSprite::ParticleSystemSprite(AbyssEngine::PaintCanvas*, AbyssEngine::AEMath::Matrix
   const*, Array<ParticleSettings::ParticleSet> const&, bool, bool) */

ParticleSystemSprite * __thiscall
ParticleSystemSprite::ParticleSystemSprite
          (ParticleSystemSprite *this,PaintCanvas *param_1,Matrix *param_2,Array *param_3,
          bool param_4,bool param_5)

{
  longlong lVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_s0;
  undefined4 extraout_s1;
  undefined8 uVar7;
  
  IParticleSystem::IParticleSystem((IParticleSystem *)this,param_1,param_2,param_3,param_4,param_5);
  *(undefined ***)this = &PTR_init_00264ad0;
  uVar5 = *(uint *)(this + 0x48);
  lVar1 = (ulonglong)uVar5 * 0xc;
  uVar6 = (uint)lVar1;
  uVar2 = uVar6;
  if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
    uVar2 = 0xffffffff;
  }
  pvVar3 = operator_new__(uVar2);
  uVar7 = CONCAT44(extraout_s1,extraout_s0);
  if (uVar5 != 0) {
    uVar7 = __aeabi_memclr4(pvVar3,((uVar6 - 0xc) / 0xc) * 0xc + 0xc);
  }
  *(void **)(this + 100) = pvVar3;
  uVar4 = AbyssEngine::AEMath::Pow((float)uVar7,(float)((ulonglong)uVar7 >> 0x20));
  *(undefined4 *)(this + 0x70) = uVar4;
  return this;
}

// ===== ParticleSystemSprite::init  @0x001b3708  (16 bytes)
/* ParticleSystemSprite::init(unsigned int, unsigned short) */

void __thiscall ParticleSystemSprite::init(ParticleSystemSprite *this,uint param_1,ushort param_2)

{
  *(uint *)(this + 0x54) = param_1;
  *(uint *)(this + 0x58) = (uint)param_2;
  this[0x5c] = (ParticleSystemSprite)0x1;
                    /* WARNING: Could not recover jumptable at 0x001b3716. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 8))();
  return;
}

// ===== ParticleSystemSprite::~ParticleSystemSprite  @0x001b3718  (56 bytes)
/* ParticleSystemSprite::~ParticleSystemSprite() */

ParticleSystemSprite * __thiscall
ParticleSystemSprite::~ParticleSystemSprite(ParticleSystemSprite *this)

{
  *(undefined ***)this = &PTR_init_00264ad0;
  release(this);
  *(undefined ***)this = &PTR___cxa_pure_virtual_00264aa4;
  if (*(void **)(this + 0x3c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x3c));
  }
  *(undefined4 *)(this + 0x3c) = 0;
  AbyssEngine::AERandom::~AERandom((AERandom *)(this + 0x10));
  return this;
}

// ===== ParticleSystemSprite::setParticle  @0x001b3758  (232 bytes)
/* ParticleSystemSprite::setParticle(AbyssEngine::AEMath::Vector const&, float, unsigned int, float,
   float, float, float, bool, float, float, AbyssEngine::AEMath::Vector const&) */

void ParticleSystemSprite::setParticle
               (Vector *param_1,float param_2,uint param_3,float param_4,float param_5,float param_6
               ,float param_7,bool param_8,float param_9,float param_10,Vector *param_11)

{
  uint in_fpscr;
  float fVar1;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s3;
  float extraout_s3_00;
  float in_stack_00000004;
  float in_stack_00000008;
  int in_stack_00000010;
  
  AbyssEngine::PaintCanvas::SpriteSystemSetPosition
            (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
             (short)*(undefined4 *)(param_1 + 0x58) + (short)*(undefined4 *)(param_1 + 0x50),
             *(float *)(param_3 + 4),param_4,*(float *)(param_3 + 8));
  AbyssEngine::PaintCanvas::SpriteSystemSetSize
            (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
             (short)*(undefined4 *)(param_1 + 0x50) + (short)*(undefined4 *)(param_1 + 0x58),
             (short)(int)(float)(uint)param_8);
  AbyssEngine::PaintCanvas::SpriteSystemSetUv
            (*(uint *)(param_1 + 8),(ushort)*(undefined4 *)(param_1 + 0x54),in_stack_00000008,
             extraout_s1,in_stack_00000004,extraout_s3);
  if (in_stack_00000010 != 0) {
    param_11 = (Vector *)((uint)param_11 & 0xffffff00);
  }
  VectorUnsignedToFloat((uint)param_11 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
  VectorUnsignedToFloat(((uint)param_11 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
  VectorUnsignedToFloat((uint)param_11 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (float)VectorUnsignedToFloat
                           (((uint)param_11 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::PaintCanvas::SpriteSystemSetRGBA
            (*(uint *)(param_1 + 8),(ushort)*(undefined4 *)(param_1 + 0x54),fVar1 * 0.003921569,
             extraout_s1_00,0.003921569,extraout_s3_00);
  return;
}

// ===== ParticleSystemSprite::updateAreaExitParticle  @0x001b3844  (1142 bytes)
/* ParticleSystemSprite::updateAreaExitParticle(int, float) */

void __thiscall
ParticleSystemSprite::updateAreaExitParticle(ParticleSystemSprite *this,int param_1,float param_2)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  AERandom *this_00;
  int iVar6;
  uint in_fpscr;
  uint uVar7;
  float fVar8;
  float fVar9;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float fVar10;
  float extraout_s3;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  AEMath local_50 [4];
  float local_4c;
  float local_48;
  int local_44;
  
  local_44 = __stack_chk_guard;
  iVar6 = (int)*(char *)(*(int *)(this + 0x6c) + param_1);
  fVar8 = (float)AbyssEngine::AEMath::operator*
                           ((AEMath *)&local_5c,(Vector *)(*(int *)(this + 100) + param_1 * 0xc),
                            param_2);
  AbyssEngine::AEMath::operator*(local_50,(Vector *)&local_5c,fVar8);
  sVar2 = (short)param_1;
  AbyssEngine::PaintCanvas::SpriteSystemAddPosition
            (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),
             (short)*(undefined4 *)(this + 0x58) + sVar2,local_4c,extraout_s1,local_48);
  local_5c = 0;
  uStack_58 = 0;
  local_54 = 0;
  AbyssEngine::PaintCanvas::SpriteSystemGetPosition
            (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),
             (short)*(undefined4 *)(this + 0x58) + sVar2,(Vector *)&local_5c);
  AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_74,*(Matrix **)(this + 0x18));
  AbyssEngine::AEMath::operator-((AEMath *)&local_68,(Vector *)&local_5c,(Vector *)&local_74);
  iVar4 = iVar6 * 0x9c;
  fVar8 = *(float *)(ParticleSettingsRef::cur + iVar4 + 0x74) *
          *(float *)(ParticleSettingsRef::cur + iVar4 + 0x74);
  fVar13 = local_68 * local_68 + local_64 * local_64 + local_60 * local_60;
  in_fpscr = in_fpscr & 0xfffffff;
  uVar3 = in_fpscr | (uint)(fVar13 < fVar8) << 0x1f | (uint)(fVar13 == fVar8) << 0x1e;
  uVar7 = uVar3 | (uint)(NAN(fVar13) || NAN(fVar8)) << 0x1c;
  bVar1 = (byte)(uVar3 >> 0x18);
  if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar7 >> 0x1c) & 1)) {
    uVar3 = *(uint *)(ParticleSettingsRef::cur + iVar6 * 0x9c + 0x30);
    fVar9 = (float)VectorUnsignedToFloat(uVar3 & 0xff,(byte)(uVar7 >> 0x16) & 3);
    fVar10 = (float)VectorUnsignedToFloat((uVar3 & 0xffff) >> 8,(byte)(uVar7 >> 0x16) & 3);
    VectorUnsignedToFloat((uVar3 & 0xffffff) >> 0x10,(byte)(uVar7 >> 0x16) & 3);
    VectorUnsignedToFloat(uVar3 >> 0x18,(byte)(uVar7 >> 0x16) & 3);
    fVar9 = fVar9 * 0.003921569;
    fVar10 = fVar10 * 0.003921569;
    if (this[0x45] == (ParticleSystemSprite)0x0) {
      fVar9 = fVar9 * 0.0;
    }
    else {
      fVar10 = fVar10 * 0.0;
    }
    AbyssEngine::PaintCanvas::SpriteSystemSetRGBA
              (*(uint *)(this + 8),(ushort)*(undefined4 *)(this + 0x54),fVar9,extraout_s1_00,fVar10,
               extraout_s3);
    fVar8 = fVar8 * 1.01;
    uVar3 = uVar7 & 0xfffffff | (uint)(fVar13 < fVar8) << 0x1f | (uint)(fVar13 == fVar8) << 0x1e;
    uVar7 = uVar3 | (uint)(NAN(fVar13) || NAN(fVar8)) << 0x1c;
    bVar1 = (byte)(uVar3 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar7 >> 0x1c) & 1)) {
      this_00 = (AERandom *)(this + 0x10);
      iVar4 = AbyssEngine::AERandom::nextInt(this_00,2000);
      fVar9 = (float)VectorSignedToFloat(iVar4 + -1000,(byte)(uVar7 >> 0x16) & 3);
      iVar4 = AbyssEngine::AERandom::nextInt(this_00,2000);
      fVar14 = (float)VectorSignedToFloat(iVar4 + -1000,(byte)(uVar7 >> 0x16) & 3);
      iVar4 = AbyssEngine::AERandom::nextInt(this_00,2000);
      fVar9 = fVar9 * 0.001;
      fVar10 = (float)VectorSignedToFloat(iVar4 + -1000,(byte)(uVar7 >> 0x16) & 3);
      fVar14 = fVar14 * 0.001;
      iVar4 = AbyssEngine::AERandom::nextInt(this_00,2000);
      fVar10 = fVar10 * 0.001;
      fVar8 = (float)VectorSignedToFloat(iVar4 + -1000,(byte)(uVar7 >> 0x16) & 3);
      fVar8 = fVar8 * 0.001;
      fVar13 = fVar9 * fVar9 + fVar14 * fVar14 + fVar10 * fVar10 + fVar8 * fVar8;
      if (-1 < (int)((uint)(fVar13 < 1.0) << 0x1f)) {
        fVar12 = fVar9 * fVar10 + fVar14 * fVar8;
        fVar11 = fVar10 * fVar8 - fVar9 * fVar14;
        local_6c = (((fVar9 * fVar9 + fVar8 * fVar8) - fVar14 * fVar14) - fVar10 * fVar10) / fVar13;
        local_74 = (fVar12 + fVar12) / fVar13;
        local_70 = (fVar11 + fVar11) / fVar13;
        AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_74,local_6c);
        AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_80,*(Matrix **)(this + 0x18));
        AbyssEngine::AEMath::Vector::operator+=((Vector *)&local_74,(Vector *)&local_80);
        AbyssEngine::PaintCanvas::SpriteSystemSetPosition
                  (*(PaintCanvas **)(this + 8),*(uint *)(this + 0x54),
                   (short)*(undefined4 *)(this + 0x58) + sVar2,local_70,extraout_s1_01,local_6c);
        iVar6 = iVar6 * 0x9c;
        local_80 = *(undefined4 *)(ParticleSettingsRef::cur + iVar6 + 0x54);
        uStack_7c = *(undefined4 *)(ParticleSettingsRef::cur + iVar6 + 0x58);
        local_78 = *(undefined4 *)(ParticleSettingsRef::cur + iVar6 + 0x5c);
        AbyssEngine::AEMath::Vector::operator=
                  ((Vector *)(*(int *)(this + 100) + param_1 * 0xc),(Vector *)&local_80);
      }
    }
    goto LAB_001b3c2e;
  }
  fVar10 = *(float *)(ParticleSettingsRef::cur + iVar4 + 0x78) *
           *(float *)(ParticleSettingsRef::cur + iVar4 + 0x78);
  uVar3 = in_fpscr | (uint)(fVar13 < fVar10) << 0x1f | (uint)(fVar13 == fVar10) << 0x1e;
  uVar7 = uVar3 | (uint)(NAN(fVar13) || NAN(fVar10)) << 0x1c;
  bVar1 = (byte)(uVar3 >> 0x18);
  if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar7 >> 0x1c) & 1)) {
    fVar10 = *(float *)(ParticleSettingsRef::cur + iVar4 + 0x7c) *
             *(float *)(ParticleSettingsRef::cur + iVar4 + 0x7c);
    uVar3 = in_fpscr | (uint)(fVar13 < fVar10) << 0x1f | (uint)(fVar13 == fVar10) << 0x1e;
    uVar7 = uVar3 | (uint)(NAN(fVar13) || NAN(fVar10)) << 0x1c;
    bVar1 = (byte)(uVar3 >> 0x18);
    if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar7 >> 0x1c) & 1)) {
      fVar8 = *(float *)(ParticleSettingsRef::cur + iVar4 + 0x3c) *
              *(float *)(ParticleSettingsRef::cur + iVar4 + 0x3c);
      uVar3 = in_fpscr | (uint)(fVar13 < fVar8) << 0x1f | (uint)(fVar13 == fVar8) << 0x1e;
      uVar7 = uVar3 | (uint)(NAN(fVar13) || NAN(fVar8)) << 0x1c;
      bVar1 = (byte)(uVar3 >> 0x18);
      if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar7 >> 0x1c) & 1)) {
        fVar10 = fVar10 - fVar8;
        fVar8 = fVar13 - fVar8;
        goto LAB_001b3bac;
      }
      uVar3 = *(uint *)(ParticleSettingsRef::cur + iVar6 * 0x9c + 0x30);
      fVar13 = (float)VectorUnsignedToFloat(uVar3 & 0xff,(byte)(uVar7 >> 0x16) & 3);
      fVar9 = (float)VectorUnsignedToFloat((uVar3 & 0xffff) >> 8,(byte)(uVar7 >> 0x16) & 3);
      VectorUnsignedToFloat((uVar3 & 0xffffff) >> 0x10,(byte)(uVar7 >> 0x16) & 3);
      VectorUnsignedToFloat(uVar3 >> 0x18,(byte)(uVar7 >> 0x16) & 3);
      fVar13 = fVar13 * 0.003921569;
      fVar9 = fVar9 * 0.003921569;
      if (this[0x45] == (ParticleSystemSprite)0x0) {
        fVar13 = fVar13 * 0.0;
      }
      else {
        fVar9 = fVar9 * 0.0;
      }
      goto LAB_001b3c14;
    }
    uVar3 = *(uint *)(ParticleSettingsRef::cur + iVar6 * 0x9c + 0x30);
    VectorUnsignedToFloat(uVar3 >> 0x18,(byte)(uVar7 >> 0x16) & 3);
    VectorUnsignedToFloat((uVar3 & 0xffff) >> 8,(byte)(uVar7 >> 0x16) & 3);
    fVar13 = (float)VectorUnsignedToFloat(uVar3 & 0xff,(byte)(uVar7 >> 0x16) & 3);
    fVar9 = (float)VectorUnsignedToFloat((uVar3 & 0xffffff) >> 0x10,(byte)(uVar7 >> 0x16) & 3);
    uVar3 = *(uint *)(this + 8);
    uVar5 = (ushort)*(undefined4 *)(this + 0x54);
    fVar13 = fVar13 * 0.003921569;
    fVar9 = fVar9 * 0.003921569;
  }
  else {
    fVar10 = fVar8 - fVar10;
    fVar8 = fVar8 - fVar13;
LAB_001b3bac:
    uVar3 = *(uint *)(ParticleSettingsRef::cur + iVar6 * 0x9c + 0x30);
    fVar13 = (float)VectorUnsignedToFloat(uVar3 & 0xff,(byte)(uVar7 >> 0x16) & 3);
    fVar9 = (float)VectorUnsignedToFloat((uVar3 & 0xffff) >> 8,(byte)(uVar7 >> 0x16) & 3);
    VectorUnsignedToFloat((uVar3 & 0xffffff) >> 0x10,(byte)(uVar7 >> 0x16) & 3);
    VectorUnsignedToFloat(uVar3 >> 0x18,(byte)(uVar7 >> 0x16) & 3);
    fVar13 = fVar13 * 0.003921569;
    fVar9 = fVar9 * 0.003921569;
    if (this[0x45] == (ParticleSystemSprite)0x0) {
      fVar13 = (fVar8 / fVar10) * fVar13;
    }
    else {
      fVar9 = (fVar8 / fVar10) * fVar9;
    }
LAB_001b3c14:
    uVar3 = *(uint *)(this + 8);
    uVar5 = (ushort)*(undefined4 *)(this + 0x54);
  }
  AbyssEngine::PaintCanvas::SpriteSystemSetRGBA(uVar3,uVar5,fVar13,extraout_s1_00,fVar9,extraout_s3)
  ;
LAB_001b3c2e:
  if (__stack_chk_guard == local_44) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ParticleSystemSprite::updateSingle  @0x001b3cf0  (744 bytes)
/* WARNING: Removing unreachable block (ram,0x001b3dca) */
/* ParticleSystemSprite::updateSingle(int, float) */

void ParticleSystemSprite::updateSingle(int param_1,float param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  AERandom *this;
  uint uVar4;
  int in_r1;
  float in_r2;
  int iVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  uint in_fpscr;
  float fVar9;
  float extraout_s0;
  float in_s1;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float in_s2;
  float extraout_s3;
  float extraout_s3_00;
  float extraout_s3_01;
  float fVar10;
  float fVar11;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  AERandom aAStack_60 [12];
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44 [4];
  int local_34;
  
  local_34 = __stack_chk_guard;
  if ((*(byte *)(param_1 + 0x34) & 0x80) != 0) {
    updateAreaExitParticle((ParticleSystemSprite *)param_1,in_r1,param_2);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x68);
  fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(iVar2 + in_r1 * 4),(byte)(in_fpscr >> 0x16) & 3
                                    );
  iVar8 = (int)*(char *)(*(int *)(param_1 + 0x6c) + in_r1);
  fVar9 = (float)(int)(fVar9 + in_r2);
  *(float *)(iVar2 + in_r1 * 4) = fVar9;
  sVar1 = (short)in_r1;
  if (*(int *)(ParticleSettingsRef::cur + iVar8 * 0x9c + 0x24) < (int)fVar9) {
    *(undefined4 *)(iVar2 + in_r1 * 4) = 0xffffffff;
    AbyssEngine::PaintCanvas::SpriteSystemSetPosition
              (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
               (short)*(undefined4 *)(param_1 + 0x58) + sVar1,fVar9,in_s1,in_s2);
    if (__stack_chk_guard == local_34) {
      AbyssEngine::PaintCanvas::SpriteSystemSetSize
                (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
                 (short)*(undefined4 *)(param_1 + 0x58) + sVar1,0);
      return;
    }
  }
  else {
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)
                                        (ParticleSettingsRef::cur + iVar8 * 0x9c + 0x40),
                                       (byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::SpriteSystemAddSize
              (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
               (short)*(undefined4 *)(param_1 + 0x58) + sVar1,(short)(int)(fVar9 * in_r2 * 0.001));
    IParticleSystem::interpolateColor
              ((IParticleSystem *)param_1,in_r1,&local_64,&local_68,&local_6c,&local_70);
    fVar9 = (float)AbyssEngine::PaintCanvas::SpriteSystemSetRGBA
                             (*(uint *)(param_1 + 8),(ushort)*(undefined4 *)(param_1 + 0x54),
                              local_68,extraout_s1,local_6c,extraout_s3);
    iVar2 = *(int *)(ParticleSettingsRef::cur + iVar8 * 0x9c + 0x98);
    if (iVar2 != 0) {
      iVar5 = *(int *)(ParticleSettingsRef::cur + iVar8 * 0x9c + 0x24);
      iVar7 = *(int *)(*(int *)(param_1 + 0x68) + in_r1 * 4) + -1;
      iVar3 = __aeabi_idiv(iVar7 * iVar2,iVar5);
      iVar2 = __aeabi_idiv(iVar2 * (iVar7 - (int)in_r2),iVar5);
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      fVar9 = extraout_s0;
      if (iVar3 != iVar2) {
        pfVar6 = local_44;
        iVar8 = iVar8 * 0x9c;
        fVar11 = (float)VectorSignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
        fVar9 = *(float *)(ParticleSettingsRef::cur + iVar8 + 0x8c) -
                *(float *)(ParticleSettingsRef::cur + iVar8 + 0x84);
        fVar10 = *(float *)(ParticleSettingsRef::cur + iVar8 + 0x90) -
                 *(float *)(ParticleSettingsRef::cur + iVar8 + 0x88);
        local_44[0] = *(float *)(ParticleSettingsRef::cur + iVar8 + 0x84) + fVar11 * fVar9;
        fVar11 = (float)VectorSignedToFloat((int)(local_44[0] + 0.0009765625),
                                            (byte)(in_fpscr >> 0x16) & 3);
        local_44[0] = local_44[0] - fVar11;
        local_44[2] = *(float *)(ParticleSettingsRef::cur + iVar8 + 0x88) + fVar10 * fVar11;
        local_44[1] = fVar9 + local_44[0];
        local_44[3] = fVar10 + local_44[2];
        fVar9 = extraout_s1_00;
        fVar10 = extraout_s3_00;
        if ((*(byte *)(param_1 + 0x37) & 2) != 0) {
          this = (AERandom *)AbyssEngine::AERandom::AERandom(aAStack_60,(longlong)in_r1);
          uVar4 = AbyssEngine::AERandom::nextInt(this,40000);
          local_54 = pfVar6[uVar4 & 1];
          local_50 = pfVar6[(uVar4 ^ 3) & 1];
          local_4c = pfVar6[uVar4 >> 1 & 1 | 2];
          local_48 = pfVar6[(uVar4 ^ 3) >> 1 & 1 | 2];
          AbyssEngine::AERandom::~AERandom(aAStack_60);
          pfVar6 = &local_54;
          fVar9 = extraout_s1_01;
          fVar10 = extraout_s3_01;
        }
        fVar9 = (float)AbyssEngine::PaintCanvas::SpriteSystemSetUv
                                 (*(uint *)(param_1 + 8),(ushort)*(undefined4 *)(param_1 + 0x54),
                                  pfVar6[1],fVar9,pfVar6[2],fVar10);
      }
    }
    fVar9 = (float)AbyssEngine::AEMath::operator*
                             ((AEMath *)&local_54,(Vector *)(*(int *)(param_1 + 100) + in_r1 * 0xc),
                              fVar9);
    AbyssEngine::AEMath::operator*((AEMath *)local_44,(Vector *)&local_54,fVar9);
    AbyssEngine::PaintCanvas::SpriteSystemAddPosition
              (*(PaintCanvas **)(param_1 + 8),*(uint *)(param_1 + 0x54),
               (short)*(undefined4 *)(param_1 + 0x58) + sVar1,local_44[1],extraout_s1_02,local_44[2]
              );
    if (__stack_chk_guard == local_34) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== ParticleSystemSprite::reset  @0x001b4008  (92 bytes)
/* ParticleSystemSprite::reset() */

void ParticleSystemSprite::reset(void)

{
  int in_r0;
  int iVar1;
  float in_s0;
  float extraout_s0;
  float in_s1;
  float extraout_s1;
  float in_s2;
  float extraout_s2;
  
  if (0 < *(int *)(in_r0 + 0x48)) {
    iVar1 = 0;
    do {
      AbyssEngine::PaintCanvas::SpriteSystemSetPosition
                (*(PaintCanvas **)(in_r0 + 8),*(uint *)(in_r0 + 0x54),
                 (short)*(undefined4 *)(in_r0 + 0x58) + (short)iVar1,in_s0,in_s1,in_s2);
      AbyssEngine::PaintCanvas::SpriteSystemSetSize
                (*(PaintCanvas **)(in_r0 + 8),*(uint *)(in_r0 + 0x54),
                 (short)*(undefined4 *)(in_r0 + 0x58) + (short)iVar1,0);
      *(undefined4 *)(*(int *)(in_r0 + 0x68) + iVar1 * 4) = 0xffffffff;
      iVar1 = iVar1 + 1;
      in_s0 = extraout_s0;
      in_s1 = extraout_s1;
      in_s2 = extraout_s2;
    } while (iVar1 < *(int *)(in_r0 + 0x48));
  }
  *(undefined4 *)(in_r0 + 0x60) = 0;
  *(undefined1 *)(in_r0 + 4) = 1;
  return;
}

// ===== ParticleSystemSprite::release  @0x001b4064  (42 bytes)
/* ParticleSystemSprite::release() */

void __thiscall ParticleSystemSprite::release(ParticleSystemSprite *this)

{
  if (*(void **)(this + 100) != (void *)0x0) {
    operator_delete__(*(void **)(this + 100));
  }
  *(undefined4 *)(this + 100) = 0;
  if (*(void **)(this + 0x68) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x68));
  }
  *(undefined4 *)(this + 0x68) = 0;
  if (*(void **)(this + 0x6c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x6c));
  }
  *(undefined4 *)(this + 0x6c) = 0;
  return;
}

// ===== ParticleSystemSprite::render  @0x001b4090  (130 bytes)
/* ParticleSystemSprite::render(AbyssEngine::PaintCanvas*, unsigned int, unsigned int,
   AbyssEngine::BlendMode) */

void ParticleSystemSprite::render(PaintCanvas *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 local_58 [5];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (param_2 != 0xffffffff) {
    AbyssEngine::PaintCanvas::SetTexture(param_1,param_3,0xffffffff);
    AbyssEngine::PaintCanvas::SetBlendMode(param_1,param_4);
    uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_38 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar1 = (undefined4 *)((uint)local_58 | 4);
    local_58[0] = 0x3f800000;
    *puVar1 = 0;
    puVar1[1] = uStack_3c;
    puVar1[2] = uStack_38;
    puVar1[3] = uStack_34;
    local_44 = 0x3f800000;
    local_40 = 0;
    local_30 = 0x3f800000;
    uStack_28 = 0x3f8000003f800000;
    local_20 = 0x3f800000;
    AbyssEngine::PaintCanvas::SetWorldViewMatrix(param_1);
    AbyssEngine::PaintCanvas::DrawSpriteSystem(param_1,param_2);
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ParticleSystemSprite::render  @0x001b4140  (250 bytes)
/* ParticleSystemSprite::render(AbyssEngine::PaintCanvas*, unsigned int) */

void ParticleSystemSprite::render(PaintCanvas *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  if (param_2 != 0xffffffff) {
    uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(param_1);
    puVar2 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(param_1,uVar1);
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar6 = puVar2[3];
    uVar7 = puVar2[4];
    uVar8 = puVar2[5];
    uVar9 = puVar2[6];
    uVar10 = puVar2[7];
    uVar11 = *puVar2;
    uVar12 = puVar2[8];
    uVar13 = puVar2[9];
    uVar14 = puVar2[10];
    uVar15 = puVar2[0xb];
    uVar16 = puVar2[0xc];
    uVar17 = puVar2[0xd];
    uVar3 = puVar2[0xe];
    uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(param_1);
    puVar2 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(param_1,uVar1);
    AbyssEngine::PaintCanvas::DrawSpriteSystem
              (param_1,param_2,uVar11,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,uVar10,uVar12,uVar13,
               uVar14,uVar15,uVar16,uVar17,uVar3,*puVar2,puVar2[1],puVar2[2],puVar2[3],puVar2[4],
               puVar2[5],puVar2[6],puVar2[7],puVar2[8],puVar2[9],puVar2[10],puVar2[0xb],puVar2[0xc],
               puVar2[0xd],puVar2[0xe]);
  }
  return;
}

// ===== ParticleSystemSprite::enable  @0x001b423a  (2 bytes)
/* ParticleSystemSprite::enable(bool) */

bool ParticleSystemSprite::enable(bool param_1)

{
  return param_1;
}

// ===== ParticleSystemSprite::getQuadCount  @0x001b423c  (4 bytes)
/* ParticleSystemSprite::getQuadCount() */

undefined4 __thiscall ParticleSystemSprite::getQuadCount(ParticleSystemSprite *this)

{
  return *(undefined4 *)(this + 0x48);
}

