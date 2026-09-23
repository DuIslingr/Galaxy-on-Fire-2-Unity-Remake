// Class: LensFlare
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== LensFlare::LensFlare  @0x00142130  (106 bytes)
/* LensFlare::LensFlare(AbyssEngine::PaintCanvas*) */

LensFlare * __thiscall LensFlare::LensFlare(LensFlare *this,PaintCanvas *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  ushort uVar3;
  int iVar4;
  
  puVar1 = operator_new__(0xc);
  *(uint **)(this + 0x10) = puVar1;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x508,puVar1);
  iVar4 = 4;
  uVar3 = 0x509;
  do {
    AbyssEngine::PaintCanvas::Image2DCreate
              (Globals::Canvas,uVar3,(uint *)(*(int *)(this + 0x10) + iVar4));
    iVar4 = iVar4 + 4;
    uVar3 = uVar3 + 1;
  } while (iVar4 != 0xc);
  uVar2 = AbyssEngine::PaintCanvas::GetWidth();
  *(undefined4 *)(this + 8) = uVar2;
  uVar2 = AbyssEngine::PaintCanvas::GetHeight();
  *(undefined4 *)(this + 0xc) = uVar2;
  *(PaintCanvas **)(this + 4) = param_1;
  return this;
}

// ===== LensFlare::~LensFlare  @0x001421a4  (22 bytes)
/* LensFlare::~LensFlare() */

LensFlare * __thiscall LensFlare::~LensFlare(LensFlare *this)

{
  if (*(void **)(this + 0x10) != (void *)0x0) {
    operator_delete(*(void **)(this + 0x10));
  }
  *(undefined4 *)(this + 0x10) = 0;
  return this;
}

// ===== LensFlare::update  @0x001421ba  (6 bytes)
/* LensFlare::update(int) */

void LensFlare::update(int param_1)

{
  *(undefined4 *)param_1 = 0;
  return;
}

// ===== LensFlare::render2D  @0x001421c0  (1526 bytes)
/* LensFlare::render2D(float, float, float, int) */

void __thiscall
LensFlare::render2D(LensFlare *this,float param_1,float param_2,float param_3,int param_4)

{
  byte bVar1;
  PaintCanvas *pPVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  float in_r2;
  float in_r3;
  uchar uVar8;
  uchar uVar9;
  uchar uVar10;
  uint in_fpscr;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  uint in_stack_00000000;
  
  if (in_stack_00000000 < 5) {
    uVar9 = (uchar)*(undefined4 *)(&DAT_00258530 + in_stack_00000000 * 4);
    uVar10 = (uchar)*(undefined4 *)(&DAT_00258510 + in_stack_00000000 * 4);
    uVar8 = (uchar)*(undefined4 *)(&DAT_002584f0 + in_stack_00000000 * 4);
  }
  else {
    uVar8 = 0xff;
    uVar10 = 0xff;
    uVar9 = 0xff;
  }
  uVar13 = in_fpscr & 0xfffffff;
  if (in_r3 < 0.0) {
    iVar3 = *(int *)(this + 8);
    fVar14 = (float)VectorSignedToFloat(-iVar3,(byte)(uVar13 >> 0x16) & 3);
    if (fVar14 < (float)param_4) {
      fVar14 = (float)VectorSignedToFloat(iVar3 << 1,(byte)(uVar13 >> 0x16) & 3);
      uVar12 = uVar13 | (uint)(fVar14 < (float)param_4) << 0x1f |
               (uint)(fVar14 == (float)param_4) << 0x1e;
      uVar11 = uVar12 | (uint)(NAN(fVar14) || NAN((float)param_4)) << 0x1c;
      bVar1 = (byte)(uVar12 >> 0x18);
      if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar11 >> 0x1c) & 1)) {
        iVar7 = *(int *)(this + 0xc);
        fVar14 = (float)VectorSignedToFloat(-iVar7,(byte)(uVar11 >> 0x16) & 3);
        if (fVar14 < in_r2) {
          fVar14 = (float)VectorSignedToFloat(iVar7 << 1,(byte)(uVar13 >> 0x16) & 3);
          uVar13 = uVar13 | (uint)(fVar14 < in_r2) << 0x1f | (uint)(fVar14 == in_r2) << 0x1e;
          uVar12 = uVar13 | (uint)(NAN(fVar14) || NAN(in_r2)) << 0x1c;
          bVar1 = (byte)(uVar13 >> 0x18);
          if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar12 >> 0x1c) & 1)) {
            fVar15 = (float)VectorSignedToFloat(iVar7 >> 1,(byte)(uVar12 >> 0x16) & 3);
            fVar17 = (float)VectorSignedToFloat(iVar3 >> 1,(byte)(uVar12 >> 0x16) & 3);
            fVar19 = fVar15 - in_r2;
            fVar20 = fVar17 - (float)param_4;
            fVar14 = (float)Globals::sqrt(fVar20 * fVar20 + fVar19 * fVar19);
            pfVar4 = (float *)&DAT_001427d8;
            uVar12 = uVar12 & 0xfffffff | (uint)(fVar14 < 0.0) << 0x1f |
                     (uint)(fVar14 == 0.0) << 0x1e;
            uVar13 = uVar12 | (uint)NAN(fVar14) << 0x1c;
            fVar21 = -(fVar19 * 65536.0);
            fVar19 = (float)VectorSignedToFloat(*(int *)(this + 0xc) >> 1,(byte)(uVar13 >> 0x16) & 3
                                               );
            if (in_stack_00000000 == 5) {
              pfVar4 = (float *)&DAT_001427dc;
            }
            fVar20 = -(fVar20 * 65536.0);
            bVar1 = (byte)(uVar12 >> 0x18);
            *(float *)this = *pfVar4 * (1.0 - fVar14 / fVar19);
            if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar13 >> 0x1c) & 1)) {
              fVar21 = fVar21 / fVar14;
              fVar20 = fVar20 / fVar14;
            }
            AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,uVar9,uVar10,uVar8);
            fVar20 = fVar14 * fVar20;
            fVar14 = fVar14 * fVar21;
            AbyssEngine::PaintCanvas::DrawImage2D
                      (Globals::Canvas,**(uint **)(this + 0x10),
                       (int)(fVar17 + fVar20 * 0.5 * 1.5258789e-05),
                       (int)(fVar15 + fVar14 * 0.5 * 1.5258789e-05),'\x11','D');
            pPVar2 = Globals::Canvas;
            uVar12 = **(uint **)(this + 0x10);
            uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar12);
            uVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth
                              (Globals::Canvas,**(uint **)(this + 0x10));
            fVar21 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
            fVar19 = (float)VectorSignedToFloat(uVar6,(byte)(uVar13 >> 0x16) & 3);
            AbyssEngine::PaintCanvas::DrawImage2D
                      (pPVar2,uVar12,(int)(fVar17 + fVar20 * 0.25 * 1.5258789e-05),
                       (int)(fVar15 + fVar14 * 0.25 * 1.5258789e-05),(int)(fVar21 * 0.75),
                       (int)(fVar19 * 0.75),'\x11','D','\0');
            pPVar2 = Globals::Canvas;
            uVar12 = *(uint *)(*(int *)(this + 0x10) + 4);
            uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar12);
            uVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth
                              (Globals::Canvas,*(uint *)(*(int *)(this + 0x10) + 4));
            fVar21 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
            fVar19 = (float)VectorSignedToFloat(uVar6,(byte)(uVar13 >> 0x16) & 3);
            fVar18 = fVar14 * 0.75 * 1.5258789e-05;
            fVar16 = fVar20 * 0.75 * 1.5258789e-05;
            AbyssEngine::PaintCanvas::DrawImage2D
                      (pPVar2,uVar12,(int)(fVar17 + fVar16),(int)(fVar15 + fVar18),
                       (int)(fVar21 * 0.5),(int)(fVar19 * 0.5),'\x11','D','\0');
            AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,uVar9,uVar10,uVar8);
            pPVar2 = Globals::Canvas;
            uVar13 = uVar13 & 0xfffffff;
            if (50.0 - *(float *)this < 90.0) {
              uVar12 = **(uint **)(this + 0x10);
              uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar12);
              fVar21 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
              uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth
                                (Globals::Canvas,**(uint **)(this + 0x10));
              fVar19 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
              AbyssEngine::PaintCanvas::DrawImage2D
                        (pPVar2,uVar12,(int)(fVar17 + fVar20 * 0.125 * 1.5258789e-05),
                         (int)(fVar15 + fVar14 * 0.125 * 1.5258789e-05),(int)(fVar21 * 1.25),
                         (int)(fVar19 * 1.25),'\x11','D','\0');
            }
            AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,uVar9,uVar10,uVar8);
            pPVar2 = Globals::Canvas;
            uVar12 = *(uint *)(*(int *)(this + 0x10) + 4);
            uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar12);
            fVar21 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
            uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth
                              (Globals::Canvas,*(uint *)(*(int *)(this + 0x10) + 4));
            fVar19 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
            AbyssEngine::PaintCanvas::DrawImage2D
                      (pPVar2,uVar12,(int)(fVar17 + (fVar20 / 11.0) * 1.5258789e-05),
                       (int)(fVar15 + (fVar14 / 11.0) * 1.5258789e-05),(int)(fVar21 * 0.5),
                       (int)(fVar19 * 0.5),'\x11','D','\0');
            AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,uVar9,uVar10,uVar8);
            pPVar2 = Globals::Canvas;
            uVar12 = *(uint *)(*(int *)(this + 0x10) + 8);
            uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar12);
            uVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth
                              (Globals::Canvas,*(uint *)(*(int *)(this + 0x10) + 8));
            fVar21 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
            fVar19 = (float)VectorSignedToFloat(uVar6,(byte)(uVar13 >> 0x16) & 3);
            AbyssEngine::PaintCanvas::DrawImage2D
                      (pPVar2,uVar12,(int)(fVar17 - fVar16),(int)(fVar15 - fVar18),
                       (int)(fVar21 + fVar21),(int)(fVar19 + fVar19),'\x11','D','\0');
            AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,uVar9,uVar10,uVar8);
            pPVar2 = Globals::Canvas;
            uVar12 = *(uint *)(*(int *)(this + 0x10) + 8);
            uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,uVar12);
            fVar21 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
            uVar5 = AbyssEngine::PaintCanvas::GetImage2DWidth
                              (Globals::Canvas,*(uint *)(*(int *)(this + 0x10) + 8));
            fVar19 = (float)VectorSignedToFloat(uVar5,(byte)(uVar13 >> 0x16) & 3);
            AbyssEngine::PaintCanvas::DrawImage2D
                      (pPVar2,uVar12,(int)(fVar17 - fVar20 * 0.2 * 1.5258789e-05),
                       (int)(fVar15 - fVar14 * 0.2 * 1.5258789e-05),(int)(fVar21 * 0.5),
                       (int)(fVar19 * 0.5),'\x11','D','\0');
            if (0.0 < *(float *)this) {
              AbyssEngine::PaintCanvas::GetColor(*(PaintCanvas **)(this + 4));
              AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
              AbyssEngine::PaintCanvas::FillRectangle
                        (*(PaintCanvas **)(this + 4),0,0,*(int *)(this + 8),*(int *)(this + 0xc));
              AbyssEngine::PaintCanvas::SetColor(*(uint *)(this + 4));
              return;
            }
          }
        }
      }
    }
  }
  return;
}

