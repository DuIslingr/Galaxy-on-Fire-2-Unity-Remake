// Class: StarSystem
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== StarSystem::StarSystem  @0x0015c200  (3288 bytes)
/* StarSystem::StarSystem(int) */

void __thiscall StarSystem::StarSystem(StarSystem *this,int param_1)

{
  Status *this_00;
  AERandom *pAVar1;
  StarSystem SVar2;
  int iVar3;
  LensFlare *this_01;
  Array *pAVar4;
  undefined4 *puVar5;
  AEGeometry *pAVar6;
  SolarSystem *pSVar7;
  uint *puVar8;
  FileRead *this_02;
  void *pvVar9;
  Array *pAVar10;
  undefined4 uVar11;
  Station *pSVar12;
  int iVar13;
  PaintCanvas *pPVar14;
  Engine *pEVar15;
  PlayerStatic *this_03;
  uint uVar16;
  Vector *pVVar17;
  ushort uVar18;
  uint uVar19;
  int iVar20;
  Vector *pVVar21;
  int iVar22;
  int iVar23;
  uint in_fpscr;
  float fVar24;
  float extraout_s0;
  float fVar25;
  float extraout_s1;
  float extraout_s2;
  double dVar26;
  undefined1 *local_cc;
  undefined1 *local_c8;
  undefined1 *local_c4;
  float local_c0 [25];
  int local_5c;
  
  local_5c = __stack_chk_guard;
  pVVar21 = (Vector *)(this + 0x30);
  *(undefined4 *)pVVar21 = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  iVar3 = Status::getSystem(Globals::status);
  this[0x28] = (StarSystem)(iVar3 == 0);
  SVar2 = (StarSystem)Status::inSupernovaSystem(Globals::status);
  this[0xc] = SVar2;
  this_01 = operator_new(0x14);
  LensFlare::LensFlare(this_01,Globals::Canvas);
  *(LensFlare **)(this + 0x2c) = this_01;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  if (this[0x28] != (StarSystem)0x0) {
    pAVar4 = operator_new(0xc);
    puVar5 = operator_new__(4);
    *(undefined4 **)(pAVar4 + 4) = puVar5;
    *(undefined4 *)(pAVar4 + 8) = 1;
    *puVar5 = 0;
    *(undefined4 *)pAVar4 = 0;
    *(Array **)(this + 0x1c) = pAVar4;
    ArraySetLength<AEGeometry*>(2,pAVar4);
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,0x1a70,Globals::Canvas,false);
    **(undefined4 **)(*(int *)(this + 0x1c) + 4) = pAVar6;
    local_c0[0] = 0.22888184;
    local_c0[1] = 0.22888184;
    local_c0[2] = 0.22888184;
    fVar24 = (float)AEGeometry::setScaling((Vector *)**(undefined4 **)(*(int *)(this + 0x1c) + 4));
    AEGeometry::moveForward((AEGeometry *)**(undefined4 **)(*(int *)(this + 0x1c) + 4),fVar24);
    AEGeometry::getDirection();
    AbyssEngine::AEMath::Vector::operator=(pVVar21,(Vector *)local_c0);
    *(float *)(this + 0x30) = -*(float *)(this + 0x30);
    *(float *)(this + 0x34) = -*(float *)(this + 0x34);
    *(float *)(this + 0x38) = -*(float *)(this + 0x38);
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,0x1a70,Globals::Canvas,false);
    *(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + 4) = pAVar6;
    iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
    local_c0[0] = (float)VectorSignedToFloat(iVar3 + 20000,(byte)(in_fpscr >> 0x16) & 3);
    local_c0[0] = local_c0[0] * 1.5258789e-05;
    local_c0[1] = local_c0[0];
    local_c0[2] = local_c0[0];
    AEGeometry::setScaling(*(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + 4));
    local_c0[0] = 0.0;
    local_c0[1] = 5.2347097;
    local_c0[2] = 0.0;
    fVar24 = (float)AEGeometry::setRotation(*(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + 4));
    AEGeometry::moveForward(*(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + 4),fVar24);
    pAVar4 = operator_new(0xc);
    puVar5 = operator_new__(4);
    *(undefined4 **)(pAVar4 + 4) = puVar5;
    *puVar5 = 0;
    *(undefined4 *)(pAVar4 + 8) = 1;
    *(undefined4 *)pAVar4 = 0;
    *(Array **)(this + 0x14) = pAVar4;
    ArraySetLength<unsigned_int>(2,pAVar4);
    AbyssEngine::PaintCanvas::TextureCreate
              (Globals::Canvas,0x2739,*(uint **)(*(int *)(this + 0x14) + 4),false);
    AbyssEngine::PaintCanvas::TextureCreate
              (Globals::Canvas,0x2719,(uint *)(*(int *)(*(int *)(this + 0x14) + 4) + 4),false);
    pAVar4 = operator_new(0xc);
    puVar5 = operator_new__(0xc);
    *(undefined4 **)(pAVar4 + 4) = puVar5;
    *(undefined4 *)(pAVar4 + 8) = 1;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    *(undefined4 *)pAVar4 = 0;
    *(Array **)(this + 0x20) = pAVar4;
    ArraySetLength<AbyssEngine::AEMath::Vector>(2,pAVar4);
    pVVar21 = *(Vector **)(*(int *)(this + 0x20) + 4);
    AEGeometry::getPosition();
    AbyssEngine::AEMath::Vector::operator=(pVVar21,(Vector *)local_c0);
    iVar3 = *(int *)(*(int *)(this + 0x20) + 4);
    AEGeometry::getPosition();
    AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar3 + 0xc),(Vector *)local_c0);
    pAVar6 = operator_new(0xc0);
    AEGeometry::AEGeometry(pAVar6,0x1a70,Globals::Canvas,false);
    *(AEGeometry **)(this + 0x40) = pAVar6;
    local_c0[0] = 0.45776367;
    local_c0[1] = 0.045776367;
    local_c0[2] = 0.22888184;
    AEGeometry::setScaling((Vector *)pAVar6);
    goto LAB_0015ced2;
  }
  pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
  puVar8 = (uint *)SolarSystem::getStations(pSVar7);
  this_02 = operator_new(1);
  FileRead::FileRead(this_02);
  pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
  pAVar4 = (Array *)FileRead::loadStationsBinary(this_02,pSVar7);
  pvVar9 = (void *)FileRead::~FileRead(this_02);
  operator_delete(pvVar9);
  pAVar10 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar10 + 4) = puVar5;
  *(undefined4 *)(pAVar10 + 8) = 1;
  *puVar5 = 0;
  *(undefined4 *)pAVar10 = 0;
  *(Array **)(this + 0x14) = pAVar10;
  ArraySetLength<unsigned_int>(*(int *)pAVar4 + 1,pAVar10);
  pAVar10 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar10 + 4) = puVar5;
  *(undefined4 *)(pAVar10 + 8) = 1;
  *puVar5 = 0;
  *(undefined4 *)pAVar10 = 0;
  *(Array **)(this + 0x24) = pAVar10;
  ArraySetLength<int>(*puVar8,pAVar10);
  iVar3 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar3 == 0x59) {
    if (this[0xc] == (StarSystem)0x0) goto LAB_0015c5bc;
LAB_0015c59e:
    AbyssEngine::PaintCanvas::TextureCreate
              (Globals::Canvas,0x2dde,*(uint **)(*(int *)(this + 0x14) + 4),false);
    uVar11 = 3;
  }
  else {
    if (0x9d < iVar3) {
      pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::getIndex(pSVar7);
      if (iVar3 == 0x1b) goto LAB_0015c59e;
    }
LAB_0015c5bc:
    pPVar14 = Globals::Canvas;
    pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar3 = SolarSystem::getTextureIndex(pSVar7);
    AbyssEngine::PaintCanvas::TextureCreate
              (pPVar14,*(ushort *)(&DAT_00258960 + iVar3 * 4),*(uint **)(*(int *)(this + 0x14) + 4),
               false);
    pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar3 = SolarSystem::getIndex(pSVar7);
    uVar11 = *(undefined4 *)(&DAT_002589ac + iVar3 * 4);
  }
  *(undefined4 *)(this + 0x3c) = uVar11;
  if (1 < **(uint **)(this + 0x14)) {
    iVar20 = 4;
    iVar3 = 0;
    do {
      iVar22 = *(int *)(puVar8[1] + iVar3 * 4);
      pSVar12 = (Station *)Status::getStation(Globals::status);
      iVar23 = iVar3 + 1;
      iVar13 = Station::getIndex(pSVar12);
      pPVar14 = Globals::Canvas;
      if (iVar22 == iVar13) {
        iVar13 = Status::getCurrentCampaignMission(Globals::status);
        pPVar14 = Globals::Canvas;
        if (param_1 == 3 && iVar13 == 0) {
          *(int *)(this + 0x50) = iVar23;
          iVar13 = *(int *)(*(int *)(this + 0x14) + 4);
          uVar18 = 0x273b;
          pPVar14 = Globals::Canvas;
        }
        else {
          iVar22 = Station::getTextureIndex(*(Station **)(*(int *)(pAVar4 + 4) + iVar3 * 4));
          iVar13 = *(int *)(*(int *)(this + 0x14) + 4);
          uVar18 = *(ushort *)(&DAT_00258a34 + iVar22 * 4);
        }
        AbyssEngine::PaintCanvas::TextureCreate(pPVar14,uVar18,(uint *)(iVar13 + iVar20),false);
      }
      else {
        iVar13 = Station::getTextureIndex(*(Station **)(*(int *)(pAVar4 + 4) + iVar3 * 4));
        AbyssEngine::PaintCanvas::TextureCreate
                  (pPVar14,*(ushort *)(&DAT_00258aa0 + iVar13 * 4),
                   (uint *)(*(int *)(*(int *)(this + 0x14) + 4) + iVar20),false);
        this_00 = Globals::status;
        iVar13 = Station::getIndex(*(Station **)(*(int *)(pAVar4 + 4) + iVar3 * 4));
        iVar13 = Status::orbitHasPlanetRing(this_00,iVar13);
        if (iVar13 == 1) {
          pAVar6 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar6,0x1a70,Globals::Canvas,false);
          *(AEGeometry **)(this + 0x44) = pAVar6;
          AbyssEngine::PaintCanvas::TextureCreate
                    (Globals::Canvas,0x7198,(uint *)(this + 0x48),false);
          *(int *)(this + 0x4c) = iVar23;
        }
      }
      uVar11 = Station::getIndex(*(Station **)(*(int *)(pAVar4 + 4) + iVar3 * 4));
      iVar20 = iVar20 + 4;
      *(undefined4 *)(*(int *)(*(int *)(this + 0x24) + 4) + iVar3 * 4) = uVar11;
      uVar19 = iVar3 + 2;
      iVar3 = iVar23;
    } while (uVar19 < **(uint **)(this + 0x14));
  }
  ArrayReleaseClasses<Station*>(pAVar4);
  if (*(void **)(pAVar4 + 4) != (void *)0x0) {
    operator_delete__(*(void **)(pAVar4 + 4));
  }
  *(undefined4 *)(pAVar4 + 4) = 0;
  operator_delete(pAVar4);
  pAVar4 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar4 + 4) = puVar5;
  *(undefined4 *)(pAVar4 + 8) = 1;
  *puVar5 = 0;
  *(undefined4 *)pAVar4 = 0;
  *(Array **)(this + 0x18) = pAVar4;
  ArraySetLength<KIPlayer*>(*puVar8,pAVar4);
  pAVar4 = operator_new(0xc);
  puVar5 = operator_new__(4);
  *(undefined4 **)(pAVar4 + 4) = puVar5;
  *(undefined4 *)(pAVar4 + 8) = 1;
  *puVar5 = 0;
  *(undefined4 *)pAVar4 = 0;
  *(Array **)(this + 0x1c) = pAVar4;
  ArraySetLength<AEGeometry*>(*puVar8 + 1,pAVar4);
  pAVar4 = operator_new(0xc);
  puVar5 = operator_new__(0xc);
  *(undefined4 **)(pAVar4 + 4) = puVar5;
  *(undefined4 *)(pAVar4 + 8) = 1;
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = 0;
  *(undefined4 *)pAVar4 = 0;
  *(Array **)(this + 0x20) = pAVar4;
  ArraySetLength<AbyssEngine::AEMath::Vector>(*puVar8 + 1,pAVar4);
  pAVar1 = Globals::rnd;
  pSVar12 = (Station *)Status::getStation(Globals::status);
  Station::getIndex(pSVar12);
  AbyssEngine::AERandom::setSeed(CONCAT44(300,pAVar1));
  __aeabi_memclr8(local_c0,0x60);
  if (**(int **)(this + 0x1c) != 0) {
    uVar19 = 0;
    iVar3 = 0;
    do {
      pAVar6 = operator_new(0xc0);
      AEGeometry::AEGeometry(pAVar6,0x1a70,Globals::Canvas,false);
      *(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4) = pAVar6;
      if (this[0x28] == (StarSystem)0x0) {
        pSVar7 = (SolarSystem *)Status::getSystem(Globals::status);
        iVar20 = SolarSystem::getTextureIndex(pSVar7);
        if (0xe < iVar20) {
          pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
          iVar20 = AbyssEngine::Engine::IsPostEffectActivated(pEVar15);
          if (iVar20 == 1) {
            iVar20 = AbyssEngine::PaintCanvas::MeshGetPointer
                               (Globals::Canvas,
                                *(uint *)(*(int *)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4)
                                         + 0x1c));
            *(undefined4 *)(iVar20 + 0x1c) = 0x3e6147ae;
          }
        }
      }
      if (uVar19 == 0) {
        iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xe);
        pSVar12 = (Station *)Status::getStation(Globals::status);
        iVar3 = Station::getTextureIndex(pSVar12);
        uVar16 = iVar3 - 9;
        if ((uVar16 < 0xd) && ((0x1a31U >> (uVar16 & 0xff) & 1) != 0)) {
          iVar20 = *(int *)(&DAT_00258e20 + uVar16 * 4);
        }
        else {
          iVar20 = iVar20 + 5;
          if (iVar3 == 0x16) {
            iVar20 = 0x10;
          }
        }
        if (this[0xc] == (StarSystem)0x0) {
          local_cc = (undefined1 *)0x3e6a6000;
          local_c8 = (undefined1 *)0x3e6a6000;
          local_c4 = (undefined1 *)0x3e6a6000;
          AEGeometry::setScaling((Vector *)**(undefined4 **)(*(int *)(this + 0x1c) + 4));
          pAVar6 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar6,0x1a70,Globals::Canvas,false);
          *(AEGeometry **)(this + 0x40) = pAVar6;
          local_cc = (undefined1 *)0x3eea6000;
          local_c8 = (undefined1 *)0x3d3b8000;
          local_c4 = (undefined1 *)0x3e6a6000;
          AEGeometry::setScaling((Vector *)pAVar6);
        }
        else {
          iVar3 = Status::getCurrentCampaignMission(Globals::status);
          if (iVar3 < 0x6a) {
            local_cc = (undefined1 *)0x3f7de800;
          }
          else {
            local_cc = &LAB_3fafc800;
          }
          local_c8 = local_cc;
          local_c4 = local_cc;
          AEGeometry::setScaling((Vector *)**(undefined4 **)(*(int *)(this + 0x1c) + 4));
          pAVar6 = operator_new(0xc0);
          AEGeometry::AEGeometry(pAVar6,0x1a70,Globals::Canvas,false);
          *(AEGeometry **)(this + 0x40) = pAVar6;
          local_cc = (undefined1 *)0x3ffde800;
          local_c8 = (undefined1 *)0x3e4b2000;
          local_c4 = (undefined1 *)0x3f7de800;
          AEGeometry::setScaling((Vector *)pAVar6);
          pEVar15 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
          iVar3 = AbyssEngine::Engine::IsPostEffectActivated(pEVar15);
          if (iVar3 == 1) {
            iVar3 = AbyssEngine::PaintCanvas::MeshGetPointer
                              (Globals::Canvas,*(uint *)(*(int *)(this + 0x40) + 0x1c));
            *(undefined4 *)(iVar3 + 0x1c) = 0x3e6147ae;
          }
          AbyssEngine::PaintCanvas::TextureCreate
                    (Globals::Canvas,0x2dde,(uint *)(this + 0x10),false);
        }
        iVar13 = 0x8000;
        local_c0[iVar20] = 1.4013e-45;
        iVar3 = iVar20;
LAB_0015cdbe:
        pVVar17 = *(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4);
        iVar22 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x1000);
        fVar25 = (float)VectorSignedToFloat(iVar22 + -0x800,(byte)(in_fpscr >> 0x16) & 3);
        fVar24 = (float)VectorSignedToFloat(iVar20 * 0xaaa,(byte)(in_fpscr >> 0x16) & 3);
        local_cc = (undefined1 *)(fVar25 * 1.5258789e-05 * 6.2831855);
      }
      else {
        iVar22 = uVar19 - 1;
        iVar13 = *(int *)(puVar8[1] + iVar22 * 4);
        pSVar12 = (Station *)Status::getStation(Globals::status);
        iVar20 = Station::getIndex(pSVar12);
        this_03 = operator_new(300);
        pAVar6 = *(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4);
        if (iVar13 == iVar20) {
          PlayerStatic::PlayerStatic(this_03,0,pAVar6,extraout_s0,extraout_s1,extraout_s2);
          iVar13 = 0x8000;
          *(PlayerStatic **)(*(int *)(*(int *)(this + 0x18) + 4) + iVar22 * 4) = this_03;
          if (iVar3 < 0xc) {
            iVar13 = 0;
          }
          orbitPlanetIndex = iVar22;
          iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,20000);
          iVar20 = iVar20 + 20000;
          iVar23 = Status::getCurrentCampaignMission(Globals::status);
          if (iVar23 == 0) {
            fVar24 = (float)VectorSignedToFloat(iVar20,(byte)(in_fpscr >> 0x16) & 3);
            iVar20 = (int)(fVar24 * 0.5);
          }
          pSVar12 = (Station *)Status::getStation(Globals::status);
          uVar16 = Station::getTextureIndex(pSVar12);
          iVar23 = Status::inPlanetRingOrbit(Globals::status);
          if (iVar23 == 0) {
            if (uVar16 < 0x12) {
              uVar16 = 1 << (uVar16 & 0xff);
              if ((uVar16 & 0x21840) == 0) {
                if ((uVar16 & 0x10200) != 0) {
                  iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,13000);
                  iVar20 = iVar20 + 0x7ef4;
                }
              }
              else {
                iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,15000);
                iVar20 = iVar20 + 35000;
              }
            }
          }
          else {
            iVar20 = 26000;
          }
          fVar24 = (float)VectorSignedToFloat(iVar20,(byte)(in_fpscr >> 0x16) & 3);
          local_cc = (undefined1 *)(fVar24 * 1.5258789e-05);
          *(undefined1 **)(this + 0x58) = local_cc;
          local_c8 = local_cc;
          local_c4 = local_cc;
          AEGeometry::setScaling(*(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4));
          iVar20 = 0;
        }
        else {
          PlayerStatic::PlayerStatic(this_03,0,pAVar6,extraout_s0,extraout_s1,extraout_s2);
          *(PlayerStatic **)(*(int *)(*(int *)(this + 0x18) + 4) + iVar22 * 4) = this_03;
          do {
            iVar20 = AbyssEngine::AERandom::nextInt(Globals::rnd,0xb);
            iVar20 = iVar20 + 7;
            iVar13 = iVar20 - iVar3;
            if (iVar13 < 0) {
              iVar13 = -iVar13;
            }
          } while ((iVar13 < 3) || (local_c0[iVar20] != 0.0));
          uVar11 = AbyssEngine::AERandom::nextInt(Globals::rnd,0x28);
          dVar26 = (double)VectorSignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
          local_cc = (undefined1 *)(float)((dVar26 * 0.01 + 0.800000011920929) * 0.03509521484375);
          local_c8 = local_cc;
          local_c4 = local_cc;
          AEGeometry::setScaling(*(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4));
          iVar13 = 0x8000;
          if (iVar3 - iVar20 < 0xc) {
            iVar13 = 0;
          }
          if (iVar3 <= iVar20) {
            iVar13 = 0x8000;
          }
        }
        local_c0[iVar20] = 1.4013e-45;
        if (iVar20 != iVar3) {
          if (0 < (int)uVar19) {
            iVar23 = *(int *)(puVar8[1] + iVar22 * 4);
            pSVar12 = (Station *)Status::getStation(Globals::status);
            iVar22 = Station::getIndex(pSVar12);
            if (iVar23 == iVar22) {
              fVar24 = (float)VectorSignedToFloat(iVar20 * 0xaaa,(byte)(in_fpscr >> 0x16) & 3);
              pVVar17 = *(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4);
              local_cc = (undefined1 *)0x0;
              goto LAB_0015ce0e;
            }
          }
          goto LAB_0015cdbe;
        }
        fVar24 = (float)VectorSignedToFloat(iVar3 * 0xaaa,(byte)(in_fpscr >> 0x16) & 3);
        pVVar17 = *(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4);
        local_cc = (undefined1 *)0x0;
      }
LAB_0015ce0e:
      local_c8 = (undefined1 *)(fVar24 * 1.5258789e-05 * 6.2831855);
      local_c4 = (undefined1 *)0x0;
      fVar24 = (float)AEGeometry::setRotation(pVVar17);
      AEGeometry::moveForward
                (*(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4),fVar24);
      if (uVar19 == 0) {
        AEGeometry::getDirection();
        AbyssEngine::AEMath::Vector::operator=(pVVar21,(Vector *)&local_cc);
        *(float *)(this + 0x30) = -*(float *)(this + 0x30);
        *(float *)(this + 0x34) = -*(float *)(this + 0x34);
        *(float *)(this + 0x38) = -*(float *)(this + 0x38);
      }
      else if (iVar13 != 0) {
        fVar24 = (float)VectorSignedToFloat(iVar13,(byte)(in_fpscr >> 0x16) & 3);
        local_cc = (undefined1 *)0x0;
        local_c8 = (undefined1 *)(fVar24 * 1.5258789e-05 * 6.2831855);
        local_c4 = (undefined1 *)0x0;
        AEGeometry::rotate(*(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar19 * 4));
      }
      iVar20 = *(int *)(*(int *)(this + 0x20) + 4);
      AEGeometry::getPosition();
      AbyssEngine::AEMath::Vector::operator=((Vector *)(iVar20 + uVar19 * 0xc),(Vector *)&local_cc);
      uVar19 = uVar19 + 1;
    } while (uVar19 < **(uint **)(this + 0x1c));
  }
  AbyssEngine::AERandom::reset(Globals::rnd);
LAB_0015ced2:
  initLight(this);
  if (__stack_chk_guard - local_5c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_5c);
  }
  return;
}

// ===== StarSystem::initLight  @0x0015d080  (1578 bytes)
/* StarSystem::initLight() */

void __thiscall StarSystem::initLight(StarSystem *this)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  SolarSystem *pSVar4;
  Engine *pEVar5;
  uint uVar6;
  Station *this_00;
  uint *puVar7;
  StarSystem SVar8;
  undefined4 uVar9;
  float *pfVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s0_02;
  float extraout_s0_03;
  float extraout_s0_04;
  float extraout_s0_05;
  float fVar14;
  float extraout_s0_06;
  float extraout_s0_07;
  float extraout_s0_08;
  float extraout_s0_09;
  float extraout_s0_10;
  float extraout_s0_11;
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
  float fVar15;
  float fVar16;
  float fVar17;
  
  iVar3 = AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  bVar1 = false;
  *(undefined4 *)(iVar3 + 0x31c) = 2;
  if (this[0x28] == (StarSystem)0x0) {
    pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar3 = SolarSystem::getTextureIndex(pSVar4);
    iVar3 = iVar3 * 3;
    if (this[0x28] == (StarSystem)0x0) {
      bVar1 = true;
    }
  }
  else {
    iVar3 = 0x1e;
  }
  fVar16 = 0.15;
  uVar9 = *(undefined4 *)(&DAT_00258b0c + (iVar3 + 1) * 4);
  uVar11 = *(undefined4 *)(&DAT_00258b0c + (iVar3 + 2) * 4);
  *(undefined4 *)this = *(undefined4 *)(&DAT_00258b0c + iVar3 * 4);
  *(undefined4 *)(this + 4) = uVar9;
  *(undefined4 *)(this + 8) = uVar11;
  if (bVar1) {
    pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar3 = SolarSystem::getTextureIndex(pSVar4);
    if ((iVar3 == 0xf) &&
       ((iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 == 0x59 ||
        (iVar3 = Status::getCurrentCampaignMission(Globals::status), 0x9d < iVar3)))) {
      *(float *)this = *(float *)this * 0.5;
      *(float *)(this + 4) = *(float *)(this + 4) * 0.5;
      *(float *)(this + 8) = *(float *)(this + 8) * 0.5;
    }
    SVar8 = this[0x28];
    if (SVar8 == (StarSystem)0x0) {
      pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
      iVar3 = SolarSystem::getTextureIndex(pSVar4);
      fVar16 = 0.15;
      if ((iVar3 == 0xf) &&
         (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 != 0x59)) {
        iVar3 = Status::getCurrentCampaignMission(Globals::status);
        pfVar10 = (float *)&DAT_0015d6e0;
        if (iVar3 < 0x9e) {
          pfVar10 = (float *)&DAT_0015d6e4;
        }
        fVar16 = *pfVar10;
      }
      SVar8 = this[0x28];
      if (SVar8 == (StarSystem)0x0) {
        this_00 = (Station *)Status::getStation(Globals::status);
        iVar3 = Station::getTextureIndex(this_00);
        SVar8 = this[0x28];
        iVar3 = iVar3 * 3;
        goto LAB_0015d1c0;
      }
    }
    iVar3 = 0x17;
  }
  else {
    iVar3 = 0x17;
    SVar8 = (StarSystem)0x1;
  }
LAB_0015d1c0:
  fVar14 = 15.0;
  fVar15 = *(float *)(&DAT_00258bf0 + iVar3 * 4);
  if (SVar8 == (StarSystem)0x0) {
    pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
    iVar3 = SolarSystem::getTextureIndex(pSVar4);
    if ((iVar3 == 0xf) &&
       (iVar3 = Status::getCurrentCampaignMission(Globals::status), iVar3 != 0x59)) {
      iVar3 = Status::getCurrentCampaignMission(Globals::status);
      fVar14 = 15.0;
      if (iVar3 < 0x9e) {
        fVar14 = 30.0;
      }
    }
  }
  fVar17 = *(float *)this;
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetGlobalSceneColorAmbient
            (pEVar5,fVar16 * *(float *)this,extraout_s1,fVar16 * *(float *)(this + 4));
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetRimColor(pEVar5,extraout_s0,extraout_s1_00,extraout_s2);
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorAmbient
            (pEVar5,extraout_s0_00,extraout_s1_01,extraout_s2_00);
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorDiffuse
            (pEVar5,extraout_s0_01,extraout_s1_02,extraout_s2_01);
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorSpecular
            (pEVar5,extraout_s0_02,extraout_s1_03,extraout_s2_02);
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetMaterialColorShininess(pEVar5,extraout_s0_03);
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightDirection
            (pEVar5,extraout_s0_04,extraout_s1_04,extraout_s2_03,*(uint *)(this + 0x30));
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorAmbient
            (pEVar5,extraout_s0_05,extraout_s1_05,extraout_s2_04,0);
  fVar14 = fVar14 * fVar17;
  in_fpscr = in_fpscr & 0xfffffff;
  fVar16 = 0.0;
  if (0.0 < fVar14) {
    fVar16 = fVar14;
  }
  fVar17 = fVar14;
  fVar2 = 0.0;
  if (2.0 < fVar16) {
    fVar17 = 2.0;
    fVar2 = fVar17;
  }
  if (fVar14 <= 0.0) {
    fVar17 = fVar2;
  }
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorDiffuse
            (pEVar5,extraout_s0_06,extraout_s1_06,extraout_s2_05,(uint)fVar17);
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorSpecular
            (pEVar5,extraout_s0_07,extraout_s1_07,extraout_s2_06,0x40000000);
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightDirection(pEVar5,extraout_s0_08,extraout_s1_08,extraout_s2_07,0)
  ;
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorDiffuse
            (pEVar5,extraout_s0_09,extraout_s1_09,extraout_s2_08,(uint)(fVar15 * 1.5));
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetLightColorSpecular
            (pEVar5,extraout_s0_10,extraout_s1_10,extraout_s2_09,(uint)(fVar15 * 1.5));
  pEVar5 = (Engine *)AbyssEngine::ApplicationManager::GetEngine(Globals::appManager);
  AbyssEngine::Engine::LightSetParticleAmbient(pEVar5,extraout_s0_11,extraout_s1_11,extraout_s2_10);
  AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,0,1);
  this[0x54] = (StarSystem)0x0;
  if (this[0x28] != (StarSystem)0x0) {
    return;
  }
  pSVar4 = (SolarSystem *)Status::getSystem(Globals::status);
  uVar6 = SolarSystem::getTextureIndex(pSVar4);
  uVar13 = 0xdb6923ff;
  switch(uVar6) {
  case 0xb:
    break;
  case 0xc:
    uVar13 = 0x163e7cff;
    break;
  default:
    goto switchD_0015d516_caseD_d;
  case 0xf:
    iVar3 = Status::getCurrentCampaignMission(Globals::status);
    if (iVar3 == 0x59) {
      return;
    }
    AbyssEngine::PaintCanvas::FogSetParameter
              (Globals::Canvas,0x2601,0,0x47c35000,0x3f800000,0x82441fff);
    AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,1,1);
    this[0x54] = (StarSystem)0x1;
    puVar7 = *(uint **)(this + 0x1c);
    if (*puVar7 < 2) {
      return;
    }
    uVar6 = 1;
    do {
      iVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(puVar7[1] + uVar6 * 4) + 0xc));
      *(undefined4 *)(iVar3 + 0x48) = 0x82441fff;
      uVar6 = uVar6 + 1;
      puVar7 = *(uint **)(this + 0x1c);
    } while (uVar6 < *puVar7);
    return;
  case 0x10:
    uVar13 = 0x47665eff;
    break;
  case 0x11:
    uVar13 = 0x738d95ff;
    break;
  case 0x12:
    uVar13 = 0xaba075ff;
  }
  puVar12 = &DAT_0015d718;
  if ((uVar6 | 1) == 0x11) {
    puVar12 = &DAT_0015d71c;
  }
  uVar9 = *puVar12;
  if (uVar6 == 0x12) {
    uVar9 = 0x48127c00;
  }
  AbyssEngine::PaintCanvas::FogSetParameter(Globals::Canvas,0x2601,0,uVar9,0x3f800000,uVar13);
  AbyssEngine::PaintCanvas::FogEnable(Globals::Canvas,1,1);
  fVar16 = (float)VectorSignedToFloat((uVar13 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
  fVar14 = (float)VectorSignedToFloat((uVar13 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  fVar15 = (float)VectorSignedToFloat(uVar13 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
  this[0x54] = (StarSystem)0x1;
  puVar7 = *(uint **)(this + 0x1c);
  if (1 < *puVar7) {
    uVar6 = 1;
    do {
      iVar3 = AbyssEngine::PaintCanvas::TransformGetTransform
                        (Globals::Canvas,*(uint *)(*(int *)(puVar7[1] + uVar6 * 4) + 0xc));
      *(uint *)(iVar3 + 0x48) =
           (int)(fVar15 * 0.7) << 0x18 | (int)(fVar14 * 0.7) << 0x10 | (int)(fVar16 * 0.7) << 8 |
           0xff;
      uVar6 = uVar6 + 1;
      puVar7 = *(uint **)(this + 0x1c);
    } while (uVar6 < *puVar7);
  }
switchD_0015d516_caseD_d:
  return;
}

// ===== StarSystem::~StarSystem  @0x0015d730  (226 bytes)
/* StarSystem::~StarSystem() */

StarSystem * __thiscall StarSystem::~StarSystem(StarSystem *this)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = *(void **)(this + 0x1c);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  if (*(Array **)(this + 0x18) != (Array *)0x0) {
    ArrayReleaseClasses<KIPlayer*>(*(Array **)(this + 0x18));
    pvVar1 = *(void **)(this + 0x18);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0x18) = 0;
  if (*(LensFlare **)(this + 0x2c) != (LensFlare *)0x0) {
    pvVar1 = (void *)LensFlare::~LensFlare(*(LensFlare **)(this + 0x2c));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x2c) = 0;
  pvVar1 = *(void **)(this + 0x14);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar1 + 4));
      pvVar2 = *(void **)(this + 0x14);
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      pvVar1 = pvVar2;
      if (pvVar2 == (void *)0x0) goto LAB_0015d7a8;
    }
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
LAB_0015d7a8:
  *(undefined4 *)(this + 0x14) = 0;
  pvVar1 = *(void **)(this + 0x24);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar1 + 4));
      pvVar2 = *(void **)(this + 0x24);
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      pvVar1 = pvVar2;
      if (pvVar2 == (void *)0x0) goto LAB_0015d7d6;
    }
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
LAB_0015d7d6:
  *(undefined4 *)(this + 0x24) = 0;
  pvVar1 = *(void **)(this + 0x20);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) == (void *)0x0) {
      *(undefined4 *)((int)pvVar1 + 4) = 0;
    }
    else {
      operator_delete__(*(void **)((int)pvVar1 + 4));
      pvVar2 = *(void **)(this + 0x20);
      *(undefined4 *)((int)pvVar1 + 4) = 0;
      pvVar1 = pvVar2;
      if (pvVar2 == (void *)0x0) goto LAB_0015d808;
    }
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
LAB_0015d808:
  *(undefined4 *)(this + 0x20) = 0;
  return this;
}

// ===== StarSystem::getLightDirection  @0x0015d812  (14 bytes)
/* StarSystem::getLightDirection() */

void StarSystem::getLightDirection(void)

{
  undefined8 *in_r0;
  int in_r1;
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(in_r1 + 0x30);
  *(undefined4 *)(in_r0 + 1) = *(undefined4 *)(in_r1 + 0x38);
  *in_r0 = uVar1;
  return;
}

// ===== StarSystem::switchPlanetForIntro  @0x0015d820  (116 bytes)
/* StarSystem::switchPlanetForIntro() */

void __thiscall StarSystem::switchPlanetForIntro(StarSystem *this)

{
  float fVar1;
  Vector aVStack_30 [12];
  AEMath aAStack_24 [12];
  int local_18;
  
  local_18 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::TextureCreate
            (Globals::Canvas,0x273a,
             (uint *)(*(int *)(*(int *)(this + 0x14) + 4) + *(int *)(this + 0x50) * 4),false);
  fVar1 = (float)AEGeometry::getScaling();
  AbyssEngine::AEMath::operator*(aAStack_24,aVStack_30,fVar1);
  AEGeometry::setScaling
            (*(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + *(int *)(this + 0x50) * 4));
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarSystem::switchSunForSupernovaReversal  @0x0015d8a0  (88 bytes)
/* StarSystem::switchSunForSupernovaReversal() */

void __thiscall StarSystem::switchSunForSupernovaReversal(StarSystem *this)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::TextureCreate
            (Globals::Canvas,0x2734,*(uint **)(*(int *)(this + 0x14) + 4),false);
  AEGeometry::setScaling((Vector *)**(undefined4 **)(*(int *)(this + 0x1c) + 4));
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarSystem::switchSunForSupernovaIntro  @0x0015d904  (264 bytes)
/* StarSystem::switchSunForSupernovaIntro() */

void __thiscall StarSystem::switchSunForSupernovaIntro(StarSystem *this)

{
  undefined4 uVar1;
  SolarSystem *this_00;
  int iVar2;
  Vector *pVVar3;
  float fVar4;
  Vector aVStack_38 [12];
  AEMath aAStack_2c [12];
  int local_20;
  
  local_20 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::TextureCreate
            (Globals::Canvas,0x2df3,*(uint **)(*(int *)(this + 0x14) + 4),false);
  AbyssEngine::PaintCanvas::TextureCreate(Globals::Canvas,0x2df4,(uint *)(this + 0x10),false);
  AEGeometry::setMesh(*(AEGeometry **)(this + 0x40),0x2df2);
  pVVar3 = *(Vector **)(this + 0x40);
  fVar4 = (float)AEGeometry::getScaling();
  AbyssEngine::AEMath::operator*(aAStack_2c,aVStack_38,fVar4);
  AEGeometry::setScaling(pVVar3);
  fVar4 = (float)AEGeometry::setMesh((AEGeometry *)**(undefined4 **)(*(int *)(this + 0x1c) + 4),
                                     0x2df1);
  AEGeometry::setScaling(fVar4);
  uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(**(int **)(*(int *)(this + 0x1c) + 4) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar1,0,0);
  uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(**(int **)(*(int *)(this + 0x1c) + 4) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar1,3,0);
  uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                    (Globals::Canvas,*(uint *)(**(int **)(*(int *)(this + 0x1c) + 4) + 0xc));
  AbyssEngine::Transform::SetAnimationState(uVar1,1,0);
  this_00 = (SolarSystem *)Status::getSystem(Globals::status);
  iVar2 = SolarSystem::getIndex(this_00);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(&DAT_002589ac + iVar2 * 4);
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarSystem::switchSunForSupernovaExpansion  @0x0015da20  (64 bytes)
/* StarSystem::switchSunForSupernovaExpansion() */

void __thiscall StarSystem::switchSunForSupernovaExpansion(StarSystem *this)

{
  int iVar1;
  
  iVar1 = __stack_chk_guard;
  AEGeometry::setScaling((Vector *)**(undefined4 **)(*(int *)(this + 0x1c) + 4));
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarSystem::scaleSunDuringSupernovaIntro  @0x0015da68  (96 bytes)
/* StarSystem::scaleSunDuringSupernovaIntro(int) */

void __thiscall StarSystem::scaleSunDuringSupernovaIntro(StarSystem *this,int param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float extraout_s1;
  float local_20;
  
  iVar1 = __stack_chk_guard;
  AEGeometry::getScaling();
  fVar2 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  AEGeometry::setScaling
            ((AEGeometry *)**(undefined4 **)(*(int *)(this + 0x1c) + 4),fVar2 * 4e-05 + local_20,
             extraout_s1,local_20);
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarSystem::updateSupernova  @0x0015dad4  (78 bytes)
/* StarSystem::updateSupernova(int) */

void __thiscall StarSystem::updateSupernova(StarSystem *this,int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(int *)(this + 0x40) != 0) {
    uVar1 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(*(int *)(this + 0x40) + 0xc));
    AbyssEngine::Transform::Update((ulonglong)uVar1,SUB41(param_1,0));
  }
  if (**(int **)(*(int *)(this + 0x1c) + 4) != 0) {
    uVar2 = AbyssEngine::PaintCanvas::TransformGetTransform
                      (Globals::Canvas,*(uint *)(**(int **)(*(int *)(this + 0x1c) + 4) + 0xc));
    AbyssEngine::Transform::Update(CONCAT44(1,uVar2),SUB41(param_1,0));
  }
  return;
}

// ===== StarSystem::getPlanets  @0x0015db2c  (4 bytes)
/* StarSystem::getPlanets() */

undefined4 __thiscall StarSystem::getPlanets(StarSystem *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== StarSystem::getStationIndices  @0x0015db30  (4 bytes)
/* StarSystem::getStationIndices() */

undefined4 __thiscall StarSystem::getStationIndices(StarSystem *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== StarSystem::getPlanetTargets  @0x0015db34  (4 bytes)
/* StarSystem::getPlanetTargets() */

undefined4 __thiscall StarSystem::getPlanetTargets(StarSystem *this)

{
  return *(undefined4 *)(this + 0x18);
}

// ===== StarSystem::getPlanetScaleFactor  @0x0015db38  (4 bytes)
/* StarSystem::getPlanetScaleFactor() */

undefined4 __thiscall StarSystem::getPlanetScaleFactor(StarSystem *this)

{
  return *(undefined4 *)(this + 0x5c);
}

// ===== StarSystem::renderSunStreak  @0x0015db3c  (62 bytes)
/* StarSystem::renderSunStreak() */

void __thiscall StarSystem::renderSunStreak(StarSystem *this)

{
  StarSystem *pSVar1;
  
  if (this[0xc] == (StarSystem)0x0) {
    pSVar1 = *(StarSystem **)(*(int *)(this + 0x14) + 4);
  }
  else {
    pSVar1 = this + 0x10;
  }
  AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)pSVar1,0xffffffff);
  AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,2);
  AEGeometry::render(*(AEGeometry **)(this + 0x40));
  return;
}

// ===== StarSystem::render  @0x0015db84  (1028 bytes)
/* StarSystem::render() */

void __thiscall StarSystem::render(StarSystem *this)

{
  PaintCanvas *pPVar1;
  uint uVar2;
  Matrix *pMVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  Vector *pVVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  float extraout_s0;
  float fVar11;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s1_03;
  float extraout_s1_04;
  float extraout_s2;
  float fVar12;
  float extraout_s2_00;
  undefined4 extraout_s3;
  float fVar13;
  ulonglong unaff_d10;
  undefined8 uVar14;
  AEMath aAStack_118 [12];
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  float local_100;
  float local_fc;
  float local_f8;
  AEMath aAStack_f4 [60];
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  AEMath aAStack_78 [8];
  float local_70;
  int local_6c;
  
  pPVar1 = Globals::Canvas;
  local_6c = __stack_chk_guard;
  uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
  pMVar3 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar2);
  AbyssEngine::AEMath::MatrixGetPosition(aAStack_78,pMVar3);
  uVar2 = **(uint **)(this + 0x1c);
  if (uVar2 != 0) {
    iVar8 = 0;
    uVar9 = 0;
    do {
      pPVar1 = Globals::Canvas;
      if (1 < uVar2) {
        if (uVar9 == 0) {
          uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
          puVar4 = (undefined4 *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar2);
          local_b8 = *puVar4;
          uStack_b4 = puVar4[1];
          uStack_b0 = puVar4[2];
          uStack_ac = puVar4[3];
          uStack_a8 = puVar4[4];
          local_a4 = puVar4[5];
          uStack_a0 = puVar4[6];
          uStack_9c = puVar4[7];
          uStack_98 = puVar4[8];
          uStack_94 = puVar4[9];
          local_90 = puVar4[10];
          uStack_8c = puVar4[0xb];
          uStack_88 = puVar4[0xc];
          uStack_84 = puVar4[0xd];
          uStack_80 = puVar4[0xe];
          AbyssEngine::AEMath::operator+
                    ((AEMath *)&local_100,*(Vector **)(*(int *)(this + 0x20) + 4),
                     (Vector *)aAStack_78);
          if (this[0xc] == (StarSystem)0x0) {
            AbyssEngine::AEMath::MatrixGetUp((AEMath *)&local_10c,(Matrix *)&local_b8);
          }
          else {
            local_10c = 0x3f800000;
            local_108 = 0;
            uStack_104 = 0;
          }
          AbyssEngine::AEMath::MatrixGetLookAt
                    (aAStack_f4,(Vector *)&local_100,(Vector *)aAStack_78,(Vector *)&local_10c);
          AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_b8,aAStack_f4);
          AEGeometry::setRotation
                    ((AEGeometry *)**(undefined4 **)(*(int *)(this + 0x1c) + 4),extraout_s0,
                     extraout_s1,extraout_s2);
          AEGeometry::getScaling();
          fVar12 = (**(float **)(this + 0x2c) + -10.0) * 0.015625;
          uVar14 = FloatVectorMax(CONCAT44(extraout_s3,fVar12),unaff_d10 & 0xffffffff00000000,2,0x20
                                 );
          fVar13 = (float)uVar14;
          fVar11 = local_f8;
          if (this[0xc] == (StarSystem)0x0) {
            fVar12 = fVar13 + local_fc;
            fVar11 = local_100 + fVar13;
          }
          AbyssEngine::AEMath::MatrixSetScaling
                    (aAStack_f4,(Matrix *)&local_b8,fVar11,extraout_s1_00,fVar12);
          uVar14 = AEGeometry::setMatrix((Matrix *)**(undefined4 **)(*(int *)(this + 0x1c) + 4));
          fVar11 = (float)((ulonglong)uVar14 >> 0x20);
          if (this[0xc] != (StarSystem)0x0) {
            AbyssEngine::AEMath::Vector::operator*=((Vector *)&local_100,(float)uVar14);
            pPVar1 = Globals::Canvas;
            uVar2 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
            pMVar3 = (Matrix *)AbyssEngine::PaintCanvas::CameraGetLocal(pPVar1,uVar2);
            AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_b8,pMVar3);
            AbyssEngine::AEMath::operator+
                      ((AEMath *)&local_10c,*(Vector **)(*(int *)(this + 0x20) + 4),
                       (Vector *)aAStack_78);
            AbyssEngine::AEMath::MatrixGetUp(aAStack_118,(Matrix *)&local_b8);
            AbyssEngine::AEMath::MatrixGetLookAt
                      (aAStack_f4,(Vector *)&local_10c,(Vector *)aAStack_78,(Vector *)aAStack_118);
            AbyssEngine::AEMath::Matrix::operator=((Matrix *)&local_b8,aAStack_f4);
            AbyssEngine::AEMath::MatrixSetScaling
                      (aAStack_f4,(Matrix *)&local_b8,fVar13 + local_100,extraout_s1_01,
                       fVar13 + local_fc);
            AEGeometry::setMatrix(*(Matrix **)(this + 0x40));
            renderSunStreak(this);
            fVar11 = extraout_s1_02;
          }
          AbyssEngine::AEMath::MatrixSetScaling
                    (aAStack_f4,(Matrix *)&local_b8,local_fc / ((1.0 - fVar13) * 6.0 + 6.0),fVar11,
                     fVar13 * (fVar13 + local_100 + 1.0));
          AEGeometry::setMatrix(*(Matrix **)(this + 0x40));
        }
        bVar10 = uVar9 - 1 == orbitPlanetIndex;
        uVar2 = orbitPlanetIndex;
        if (bVar10) {
          uVar2 = (uint)(byte)this[0x28];
        }
        if ((bVar10 && uVar2 == 0) &&
           (iVar5 = Status::inPlanetRingOrbit(Globals::status), iVar5 == 0)) {
          fVar11 = local_70 / -800000.0;
          fVar12 = 0.2;
          if ((int)((uint)(fVar11 < 0.2) << 0x1f) < 0) {
            fVar12 = fVar11;
          }
          fVar13 = 0.2;
          if ((int)((uint)(fVar12 < -0.2) << 0x1f) < 0) {
            fVar13 = -0.2;
          }
          if (-1 < (int)((uint)(fVar11 < 0.2) << 0x1f)) {
            fVar11 = fVar13;
          }
          if ((int)((uint)(fVar12 < -0.2) << 0x1f) < 0) {
            fVar11 = fVar13;
          }
          *(float *)(this + 0x5c) = fVar11;
          AEGeometry::setScaling
                    (*(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar9 * 4),
                     *(float *)(this + 0x58) + fVar11,extraout_s1_03,*(float *)(this + 0x58));
        }
        pVVar7 = *(Vector **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar9 * 4);
        AbyssEngine::AEMath::operator+
                  ((AEMath *)&local_b8,(Vector *)(*(int *)(*(int *)(this + 0x20) + 4) + iVar8),
                   (Vector *)aAStack_78);
        AEGeometry::setPosition(pVVar7);
      }
      AbyssEngine::PaintCanvas::SetTexture
                (Globals::Canvas,*(uint *)(*(int *)(*(int *)(this + 0x14) + 4) + uVar9 * 4),
                 0xffffffff);
      if (uVar9 == 0) {
        uVar6 = 2;
      }
      else {
        uVar6 = 1;
        if (this[0x54] != (StarSystem)0x0) {
          uVar6 = 0x15;
        }
      }
      AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,uVar6);
      AEGeometry::render(*(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar9 * 4));
      if (uVar9 == *(uint *)(this + 0x4c)) {
        AbyssEngine::PaintCanvas::SetTexture(Globals::Canvas,*(uint *)(this + 0x48),0xffffffff);
        AbyssEngine::PaintCanvas::SetBlendMode(Globals::Canvas,1);
        puVar4 = (undefined4 *)
                 AEGeometry::getMatrix
                           (*(AEGeometry **)(*(int *)(*(int *)(this + 0x1c) + 4) + uVar9 * 4));
        local_b8 = *puVar4;
        uStack_b4 = puVar4[1];
        uStack_b0 = puVar4[2];
        uStack_ac = puVar4[3];
        uStack_a8 = puVar4[4];
        local_a4 = puVar4[5];
        uStack_a0 = puVar4[6];
        uStack_9c = puVar4[7];
        uStack_98 = puVar4[8];
        uStack_94 = puVar4[9];
        local_90 = puVar4[10];
        uStack_8c = puVar4[0xb];
        uStack_88 = puVar4[0xc];
        uStack_84 = puVar4[0xd];
        uStack_80 = puVar4[0xe];
        AbyssEngine::AEMath::MatrixSetScaling
                  (aAStack_f4,(Matrix *)&local_b8,extraout_s0_00,extraout_s1_04,extraout_s2_00);
        AEGeometry::setMatrix(*(Matrix **)(this + 0x44));
        AEGeometry::render(*(AEGeometry **)(this + 0x44));
      }
      iVar8 = iVar8 + 0xc;
      uVar9 = uVar9 + 1;
      uVar2 = **(uint **)(this + 0x1c);
    } while (uVar9 < uVar2);
  }
  if (__stack_chk_guard == local_6c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== StarSystem::render2D  @0x0015dfc0  (166 bytes)
/* StarSystem::render2D() */

void __thiscall StarSystem::render2D(StarSystem *this)

{
  PaintCanvas *this_00;
  uint uVar1;
  int iVar2;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  float local_24;
  float local_20;
  float local_1c;
  int local_18;
  
  this_00 = Globals::Canvas;
  local_18 = __stack_chk_guard;
  if (*(int *)(this + 0x2c) != 0) {
    uVar1 = AbyssEngine::PaintCanvas::CameraGetCurrent(Globals::Canvas);
    iVar2 = AbyssEngine::PaintCanvas::CameraGetLocal(this_00,uVar1);
    local_24 = *(float *)(iVar2 + 0xc) + *(float *)(this + 0x30) * 65536.0;
    local_20 = *(float *)(iVar2 + 0x1c) + *(float *)(this + 0x34) * 65536.0;
    local_1c = *(float *)(iVar2 + 0x2c) + *(float *)(this + 0x38) * 65536.0;
    LensFlare::update(*(int *)(this + 0x2c));
    iVar2 = AbyssEngine::PaintCanvas::GetScreenPosition
                      (Globals::Canvas,(Vector *)&local_24,(Vector *)&local_24);
    if (iVar2 == 1) {
      LensFlare::render2D(*(LensFlare **)(this + 0x2c),extraout_s0,extraout_s1,extraout_s2,
                          (int)local_24);
    }
  }
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== StarSystem::rotate  @0x0015e078  (2 bytes)
/* StarSystem::rotate(int, int, int) */

int StarSystem::rotate(int param_1,int param_2,int param_3)

{
  return param_1;
}

