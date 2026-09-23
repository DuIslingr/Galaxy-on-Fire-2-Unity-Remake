// Class: MiningGame
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== MiningGame::MiningGame  @0x00143994  (932 bytes)
/* MiningGame::MiningGame(int, int, Hud*) */

void __thiscall MiningGame::MiningGame(MiningGame *this,int param_1,int param_2,Hud *param_3)

{
  int iVar1;
  Ship *this_00;
  Item *this_01;
  Sprite *this_02;
  MarqueeImage *pMVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  undefined4 uVar6;
  float fVar7;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  undefined4 uVar8;
  uint local_30;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  *(int *)(this + 0x18) = param_1;
  *(int *)(this + 0x1c) = param_2;
  *(Hud **)(this + 0xd0) = param_3;
  iVar1 = Globals::w >> 1;
  *(int *)(this + 0x58) = iVar1;
  iVar4 = Globals::layout;
  uVar6 = VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = *(int *)(Globals::layout + 0xd0) + (Globals::h >> 1);
  *(int *)(this + 0x5c) = iVar1;
  uVar8 = VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 200) = *(undefined4 *)(iVar4 + 0xd4);
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(int *)(this + 0x7c) = param_1;
  this[0x80] = (MiningGame)(param_1 == 7);
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x70) = 0x9c4;
  this[0x81] = (MiningGame)0x0;
  this[0x82] = (MiningGame)0x0;
  this[0x83] = (MiningGame)0x0;
  *(undefined4 *)(this + 0x10) = uVar6;
  *(undefined4 *)(this + 0x14) = uVar8;
  this_00 = (Ship *)Status::getShip(Globals::status);
  this_01 = (Item *)Ship::getFirstEquipmentOfSort(this_00,0x13);
  if (this_01 != (Item *)0x0) {
    uVar6 = Item::getAttribute(this_01,0x20);
    fVar7 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(this + 0x2c) = (fVar7 / 100.0) * 1.5 + 0.3;
    uVar6 = Item::getAttribute(this_01,0x21);
    fVar7 = (float)VectorSignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(this + 0x28) = fVar7 / 100.0;
  }
  local_30 = 0xffffffff;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e6,&local_30);
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,local_30);
  this_02 = operator_new(0x40);
  Sprite::Sprite(this_02,local_30,iVar1,iVar1);
  *(Sprite **)(this + 0x94) = this_02;
  Sprite::defineReferencePixel(this_02,iVar1 >> 1,iVar1 >> 1);
  *(undefined4 *)(this + 0x68) = 0;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e2,(uint *)(this + 0xac));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4dd,(uint *)(this + 0xb0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4de,(uint *)(this + 0xb4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e1,(uint *)(this + 0xb8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4df,(uint *)(this + 0xbc));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e0,(uint *)(this + 0xc0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e5,(uint *)(this + 0x9c));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e4,(uint *)(this + 0xa0));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e7,(uint *)(this + 0x98));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e3,(uint *)(this + 0xa4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4e8,(uint *)(this + 0xa8));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4ed,(uint *)(this + 0xc4));
  if (this[0x80] != (MiningGame)0x0) {
    uVar3 = 0x523;
    if (param_2 == 0xa4) {
      uVar3 = 0x522;
    }
    AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,uVar3,(uint *)(this + 0x60));
  }
  uVar6 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0xa8));
  *(undefined4 *)(this + 0x48) = uVar6;
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0xa8));
  *(int *)(this + 0x4c) = iVar1;
  iVar5 = Globals::w / 2 - *(int *)(this + 0x48) / 2;
  *(int *)(this + 0x50) = iVar5;
  iVar4 = *(int *)(Globals::layout + 0xd8);
  *(int *)(this + 0x54) = iVar4;
  pMVar2 = operator_new(0x24);
  MarqueeImage::MarqueeImage(pMVar2,0x4eb,*(int *)(this + 200),iVar5,iVar4 + iVar1 + 5,extraout_s0);
  *(MarqueeImage **)(this + 0x8c) = pMVar2;
  pMVar2 = operator_new(0x24);
  MarqueeImage::MarqueeImage
            (pMVar2,0x4ec,*(int *)(this + 200),
             (*(int *)(this + 0x50) - *(int *)(this + 200)) + *(int *)(this + 0x48),
             *(int *)(this + 0x4c) + *(int *)(this + 0x54) + 5,extraout_s0_00);
  *(MarqueeImage **)(this + 0x90) = pMVar2;
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x98));
  *(int *)(this + 0x40) = iVar1 / 2 + 5;
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x9c));
  *(int *)(this + 0x44) = iVar1 >> 1;
  uVar6 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*(uint *)(this + 0xa0));
  *(undefined4 *)(this + 0x34) = uVar6;
  pMVar2 = operator_new(0x24);
  iVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*(uint *)(this + 0x9c));
  MarqueeImage::MarqueeImage(pMVar2,0x4e4,iVar1 + -8,0,0,extraout_s0_01);
  *(MarqueeImage **)(this + 0x88) = pMVar2;
  MarqueeImage::setSpeed
            (pMVar2,*(float *)(Globals::layout + 0xe0) *
                    *(float *)(LAYER_SPEEDS + *(int *)(this + 0x78) * 4));
  *(undefined4 *)(this + 100) = 0x3f800000;
  *(undefined4 *)(this + 0xcc) = 0;
  iVar1 = Status::getCurrentCampaignMission(Globals::status);
  this[0x84] = (MiningGame)(4 < iVar1);
  if (__stack_chk_guard - local_2c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_2c);
  }
  return;
}

// ===== MiningGame::~MiningGame  @0x00143d9c  (30 bytes)
/* MiningGame::~MiningGame() */

MiningGame * __thiscall MiningGame::~MiningGame(MiningGame *this)

{
  void *pvVar1;
  
  if (*(Sprite **)(this + 0x94) != (Sprite *)0x0) {
    pvVar1 = (void *)Sprite::~Sprite(*(Sprite **)(this + 0x94));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x94) = 0;
  return this;
}

// ===== MiningGame::gameWon  @0x00143dba  (6 bytes)
/* MiningGame::gameWon() */

MiningGame __thiscall MiningGame::gameWon(MiningGame *this)

{
  return this[0x81];
}

// ===== MiningGame::gameLost  @0x00143dc0  (6 bytes)
/* MiningGame::gameLost() */

MiningGame __thiscall MiningGame::gameLost(MiningGame *this)

{
  return this[0x82];
}

// ===== MiningGame::getOreAmount  @0x00143dc6  (14 bytes)
/* MiningGame::getOreAmount() */

int __thiscall MiningGame::getOreAmount(MiningGame *this)

{
  return (int)*(float *)(this + 0x24);
}

// ===== MiningGame::gotCore  @0x00143dd4  (6 bytes)
/* MiningGame::gotCore() */

MiningGame __thiscall MiningGame::gotCore(MiningGame *this)

{
  return this[0x83];
}

// ===== MiningGame::getAsteroidType  @0x00143dda  (4 bytes)
/* MiningGame::getAsteroidType() */

undefined4 __thiscall MiningGame::getAsteroidType(MiningGame *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== MiningGame::up  @0x00143dde  (18 bytes)
/* MiningGame::up(float) */

void __thiscall MiningGame::up(MiningGame *this,float param_1)

{
  float in_r1;
  
  *(float *)(this + 4) = in_r1 * 3.0;
  return;
}

// ===== MiningGame::down  @0x00143df0  (18 bytes)
/* MiningGame::down(float) */

void __thiscall MiningGame::down(MiningGame *this,float param_1)

{
  float in_r1;
  
  *(float *)(this + 4) = in_r1 * 3.0;
  return;
}

// ===== MiningGame::left  @0x00143e02  (18 bytes)
/* MiningGame::left(float) */

void __thiscall MiningGame::left(MiningGame *this,float param_1)

{
  float in_r1;
  
  *(float *)this = in_r1 * 3.0;
  return;
}

// ===== MiningGame::right  @0x00143e14  (18 bytes)
/* MiningGame::right(float) */

void __thiscall MiningGame::right(MiningGame *this,float param_1)

{
  float in_r1;
  
  *(float *)this = in_r1 * 3.0;
  return;
}

// ===== MiningGame::update  @0x00143e28  (1218 bytes)
/* MiningGame::update(int) */

undefined4 __thiscall MiningGame::update(MiningGame *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint in_fpscr;
  uint uVar8;
  float fVar9;
  float extraout_s0;
  undefined4 extraout_s1;
  undefined8 uVar10;
  float fVar11;
  float fVar12;
  undefined8 unaff_d9;
  
  iVar2 = *(int *)(this + 0xcc) + param_1;
  if (1999 < iVar2) {
    iVar2 = 0;
  }
  *(int *)(this + 0xcc) = iVar2;
  iVar2 = isInCurrentLayer(this);
  iVar3 = *(int *)(this + 0x6c);
  *(int *)(this + 0x6c) = iVar3 + param_1;
  if (0x9c4 < iVar3 + param_1) {
    iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,2000);
    *(int *)(this + 0x6c) = iVar3 + 500;
    iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    iVar5 = -1;
    if (iVar4 == 0) {
      iVar5 = 1;
    }
    iVar7 = -1;
    fVar9 = (float)VectorSignedToFloat((iVar3 + 5) * iVar5,(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(this + 8) = (fVar9 / 10.0) / *(float *)(this + 0x2c);
    iVar3 = AbyssEngine::AERandom::nextInt(Globals::rnd,7);
    iVar4 = AbyssEngine::AERandom::nextInt(Globals::rnd,2);
    if (iVar4 == 0) {
      iVar7 = 1;
    }
    fVar9 = (float)VectorSignedToFloat(iVar7 * (iVar3 + 5),(byte)(in_fpscr >> 0x16) & 3);
    fVar9 = (fVar9 / 10.0) / *(float *)(this + 0x2c);
    *(float *)(this + 0xc) = fVar9;
    if ((this[0x80] != (MiningGame)0x0) && (*(int *)(this + 0x78) == *(int *)(this + 0x7c) + -1)) {
      *(float *)(this + 8) = *(float *)(this + 8) * 0.3;
      *(float *)(this + 0xc) = fVar9 * 0.3;
    }
  }
  if ((this[0x84] == (MiningGame)0x0) && (iVar3 = isInCurrentLayer(this), iVar3 == 0)) {
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x58),(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(this + 8) = (fVar9 - *(float *)(this + 0x10)) * 0.03;
    fVar9 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x5c),(byte)(in_fpscr >> 0x16) & 3);
    *(float *)(this + 0xc) = (fVar9 - *(float *)(this + 0x14)) * 0.03;
  }
  fVar9 = *(float *)(Globals::layout + 0xe4);
  fVar12 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0x10) =
       *(float *)(this + 0x10) + fVar12 * ((*(float *)this + *(float *)(this + 8)) / fVar9);
  *(float *)(this + 0x14) =
       fVar12 * ((*(float *)(this + 4) + *(float *)(this + 0xc)) / fVar9) + *(float *)(this + 0x14);
  MarqueeImage::update(*(MarqueeImage **)(this + 0x8c),param_1);
  MarqueeImage::update(*(MarqueeImage **)(this + 0x90),param_1);
  FModSound::setParamValue
            ((int)Globals::sound,0,
             ((*(float *)(LAYER_SPEEDS + *(int *)(this + 0x78) * 4) + -5.0) / 33.0) * 3.0);
  iVar3 = isInCurrentLayer(this);
  if (iVar3 == 0) {
    if (iVar2 == 1) {
      fVar9 = (float)FModSound::stop(Globals::sound,1);
      FModSound::play(Globals::sound,3,(Vector *)0x0,(Vector *)0x0,fVar9);
    }
    iVar2 = *(int *)(this + 0x20);
    *(int *)(this + 0x20) = iVar2 + param_1;
    if (0x9c4 < iVar2 + param_1) {
      *(undefined4 *)(this + 0x20) = 0x9c4;
      *(undefined4 *)(this + 0x24) = 0;
      this[0x82] = (MiningGame)0x1;
      *(undefined4 *)(Globals::status + 0x124) = 0;
      return 0;
    }
    *(undefined4 *)(this + 100) = 0x3f800000;
  }
  else {
    if (iVar2 == 0) {
      FModSound::play(Globals::sound,1,(Vector *)0x0,(Vector *)0x0,extraout_s0);
      FModSound::stop(Globals::sound,3);
    }
    fVar9 = *(float *)(this + 0x68) +
            (fVar12 / 1000.0) *
            *(float *)(Globals::layout + 0xe0) *
            *(float *)(LAYER_SPEEDS + *(int *)(this + 0x78) * 4) * 3.0;
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar9 < 1.0) << 0x1f;
    uVar8 = uVar1 | (uint)NAN(fVar9) << 0x1c;
    *(float *)(this + 0x68) = fVar9;
    if ((byte)(uVar1 >> 0x1f) == ((byte)(uVar8 >> 0x1c) & 1)) {
      Sprite::nextFrame(*(Sprite **)(this + 0x94));
      *(undefined4 *)(this + 0x68) = 0;
    }
    MarqueeImage::update(*(MarqueeImage **)(this + 0x88),param_1);
    iVar2 = *(int *)(this + 0x78) + 1;
    fVar9 = (float)VectorSignedToFloat(iVar2,(byte)(uVar8 >> 0x16) & 3);
    fVar11 = *(float *)(this + 0x24);
    fVar9 = fVar11 + fVar12 * ((*(float *)(this + 0x28) * ((fVar9 / 7.0) * 2.35 + 0.15)) / 1000.0);
    *(float *)(this + 0x24) = fVar9;
    if ((int)fVar11 < (int)fVar9) {
      fVar9 = 0.0;
      *(undefined4 *)(this + 100) = 0;
    }
    else {
      fVar9 = *(float *)(this + 100);
    }
    uVar10 = FloatVectorMin(CONCAT44(extraout_s1,fVar12 / 500.0 + fVar9),
                            CONCAT44((int)((ulonglong)unaff_d9 >> 0x20),0x3f800000),2,0x20);
    *(int *)(this + 100) = (int)uVar10;
    iVar3 = *(int *)(this + 0x74);
    *(int *)(this + 0x74) = iVar3 + param_1;
    if (6000 < iVar3 + param_1) {
      *(undefined4 *)(this + 0x74) = 0;
      *(int *)(this + 0x78) = iVar2;
      if (*(int *)(this + 0x7c) <= iVar2) {
        this[0x81] = (MiningGame)0x1;
        this[0x83] = (MiningGame)(*(int *)(this + 0x7c) == 7);
        iVar2 = Achievements::hasMedal(Globals::achievements,0x26,1);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = *(int *)(Globals::status + 0x124) + 1;
        *(int *)(Globals::status + 0x124) = iVar2;
        uVar6 = Achievements::getValue(Globals::achievements,0x26,1);
        fVar9 = (float)VectorSignedToFloat(iVar2,(byte)(uVar8 >> 0x16) & 3);
        fVar12 = (float)VectorSignedToFloat(uVar6,(byte)(uVar8 >> 0x16) & 3);
        if ((int)((fVar9 / fVar12) * 100.0) % 10 == 0) {
          fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::status + 0x124),
                                              (byte)(uVar8 >> 0x16) & 3);
          uVar6 = Achievements::getValue(Globals::achievements,0x26,1);
          fVar9 = (float)VectorSignedToFloat(uVar6,(byte)(uVar8 >> 0x16) & 3);
          if (0x1d < (int)((fVar12 / fVar9) * 100.0)) {
            iVar2 = *(int *)(this + 0xd0);
            VectorSignedToFloat(*(undefined4 *)(Globals::status + 0x124),(byte)(uVar8 >> 0x16) & 3);
            uVar6 = Achievements::getValue(Globals::achievements,0x26,1);
            VectorSignedToFloat(uVar6,(byte)(uVar8 >> 0x16) & 3);
            Hud::hudEventMedal(iVar2,0x26);
          }
        }
        iVar3 = *(int *)(Globals::status + 0x124);
        iVar2 = Achievements::getValue(Globals::achievements,0x26,1);
        if (iVar2 <= iVar3) {
          *(undefined1 *)(Globals::status + 0x128) = 1;
        }
        return 0;
      }
      MarqueeImage::setSpeed
                (*(MarqueeImage **)(this + 0x88),
                 *(float *)(Globals::layout + 0xe0) * *(float *)(LAYER_SPEEDS + iVar2 * 4));
    }
  }
  return 1;
}

// ===== MiningGame::isInCurrentLayer  @0x00144364  (156 bytes)
/* MiningGame::isInCurrentLayer() */

bool __thiscall MiningGame::isInCurrentLayer(MiningGame *this)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar3 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x5c),(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x58),(byte)(in_fpscr >> 0x16) & 3);
  iVar1 = *(int *)(LAYER_DIAMETERS + *(int *)(this + 0x78) * 4 + (7 - *(int *)(this + 0x7c)) * 0x1c)
  ;
  fVar4 = *(float *)(Globals::layout + 0xe8);
  fVar2 = (float)Globals::sqrt((*(float *)(this + 0x10) - fVar2) * (*(float *)(this + 0x10) - fVar2)
                               + (*(float *)(this + 0x14) - fVar3) *
                                 (*(float *)(this + 0x14) - fVar3));
  fVar3 = (float)VectorSignedToFloat(iVar1 / 2,(byte)(in_fpscr >> 0x16) & 3);
  return (int)((uint)(fVar2 < fVar3 * fVar4) << 0x1f) < 0;
}

// ===== MiningGame::render2D  @0x0014440c  (1430 bytes)
/* MiningGame::render2D() */

void __thiscall MiningGame::render2D(MiningGame *this)

{
  PaintCanvas *pPVar1;
  int iVar2;
  float fVar3;
  Ship *this_00;
  String *pSVar4;
  int iVar5;
  undefined4 extraout_r1;
  MiningGame *pMVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint in_fpscr;
  float fVar12;
  float extraout_s0;
  undefined8 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  String aSStack_54 [8];
  undefined4 local_4c [2];
  AbyssEngine aAStack_44 [8];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  uVar9 = *(uint *)(this + 0x78);
  iVar2 = *(int *)(this + 0x7c);
  if ((int)uVar9 < iVar2) {
    do {
      fVar12 = (float)VectorSignedToFloat(*(undefined4 *)
                                           (LISTITEMWINDOW_UNITS + iVar2 * -0x1c + uVar9 * 4),
                                          (byte)(in_fpscr >> 0x16) & 3);
      iVar2 = (int)(fVar12 * *(float *)(Globals::layout + 0xe8));
      if ((uVar9 & 1) == 0) {
        pMVar6 = this + 0xac;
        if ((*(int *)(Globals::layout + 0xec) < iVar2) &&
           (pMVar6 = this + 0xb4, iVar2 < *(int *)(Globals::layout + 0xf4))) {
          pMVar6 = this + 0xb0;
        }
      }
      else {
        pMVar6 = this + 0xb8;
        if ((*(int *)(Globals::layout + 0xec) < iVar2) &&
           (pMVar6 = this + 0xc0, iVar2 < *(int *)(Globals::layout + 0xf4))) {
          pMVar6 = this + 0xbc;
        }
      }
      uVar7 = *(uint *)pMVar6;
      iVar2 = iVar2 / 2;
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,uVar7,*(int *)(this + 0x58),*(int *)(this + 0x5c),iVar2,iVar2,
                 '\x11','\"','\0');
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,uVar7,*(int *)(this + 0x58),*(int *)(this + 0x5c),iVar2,iVar2,
                 '\x11','!','\x01');
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,uVar7,*(int *)(this + 0x58),*(int *)(this + 0x5c),iVar2,iVar2,
                 '\x11','\x12','\x02');
      AbyssEngine::PaintCanvas::DrawImage2D
                (Globals::Canvas,uVar7,*(int *)(this + 0x58),*(int *)(this + 0x5c),iVar2,iVar2,
                 '\x11','\x11','\x03');
      iVar2 = *(int *)(this + 0x7c);
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < iVar2);
  }
  if (this[0x80] != (MiningGame)0x0) {
    AbyssEngine::PaintCanvas::DrawImage2D
              (Globals::Canvas,*(uint *)(this + 0x60),*(int *)(this + 0x58),*(int *)(this + 0x5c),
               '\x11','D');
  }
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x98),(int)*(float *)(this + 0x10),
             (int)*(float *)(this + 0x14),'\x11','D');
  uVar13 = Sprite::setRefPixelPosition
                     (*(Sprite **)(this + 0x94),(int)*(float *)(this + 0x10),
                      (int)*(float *)(this + 0x14));
  Sprite::draw((float)uVar13,(float)((ulonglong)uVar13 >> 0x20));
  fVar12 = (float)AbyssEngine::PaintCanvas::DrawImage2D
                            (Globals::Canvas,*(uint *)(this + 0xa4),
                             *(int *)(this + 0x50) - *(int *)(Globals::layout + 0xfc),
                             *(int *)(this + 0x54) - *(int *)(Globals::layout + 0xfc));
  pPVar1 = Globals::Canvas;
  iVar2 = *(int *)(this + 0x20);
  if (0x341 < iVar2) {
    fVar12 = (float)Layout::getPulseValue(Globals::layout,fVar12);
    fVar3 = (float)Layout::getPulseValue(Globals::layout,extraout_s0);
    AbyssEngine::PaintCanvas::SetColor
              ((uchar)pPVar1,0xff,(0.0 < fVar12 * 255.0) * (char)(int)(fVar12 * 255.0),
               (0.0 < fVar3 * 255.0) * (char)(int)(fVar3 * 255.0));
    iVar2 = *(int *)(this + 0x20);
  }
  fVar12 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x48),(byte)(in_fpscr >> 0x16) & 3);
  iVar2 = (int)(fVar3 * ((2500.0 - fVar12) / 2500.0));
  AbyssEngine::PaintCanvas::DrawRegion2D
            (Globals::Canvas,*(uint *)(this + 0xa8),0,0,iVar2,*(int *)(this + 0x4c),(float)iVar2,0,0
             ,0,*(int *)(this + 0x50));
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0xc4),*(int *)(this + 0x58),*(int *)(this + 0x54) + -3
             ,'\x11','$');
  MarqueeImage::draw(*(MarqueeImage **)(this + 0x8c));
  MarqueeImage::draw(*(MarqueeImage **)(this + 0x90));
  fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x40),(byte)(in_fpscr >> 0x16) & 3);
  VectorSignedToFloat(*(undefined4 *)(this + 0x34),(byte)(in_fpscr >> 0x16) & 3);
  MarqueeImage::draw(*(int *)(this + 0x88),(int)(*(float *)(this + 0x10) + fVar12));
  fVar12 = (float)VectorSignedToFloat(*(undefined4 *)(this + 0x40),(byte)(in_fpscr >> 0x16) & 3);
  fVar15 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x100),
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0xfc),
                                     (byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)(this + 0x9c),
             (int)((*(float *)(this + 0x10) + fVar12) - fVar3),
             (int)(*(float *)(this + 0x14) - fVar15));
  local_4c[0] = 0;
  AbyssEngine::String::Set(CONCAT44(extraout_r1,local_4c));
  AbyssEngine::String::String(aSStack_54,"t",false);
  AbyssEngine::operator+(aAStack_44,(String *)local_4c,aSStack_54);
  AbyssEngine::String::~String(aSStack_54);
  AbyssEngine::String::~String((String *)local_4c);
  this_00 = (Ship *)Status::getShip(Globals::status);
  iVar2 = Ship::getFreeSpace(this_00);
  if (iVar2 < (int)*(float *)(this + 0x24)) {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,'*','\0');
  }
  else {
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
  }
  uVar9 = Globals::font;
  pPVar1 = Globals::Canvas;
  uVar10 = *(undefined4 *)(this + 0x40);
  uVar8 = *(undefined4 *)(this + 0x44);
  uVar11 = *(undefined4 *)(Globals::layout + 0xfc);
  fVar17 = *(float *)(this + 0x10);
  iVar2 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,aAStack_44);
  fVar12 = (float)VectorSignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (float)VectorSignedToFloat(uVar8,(byte)(in_fpscr >> 0x16) & 3);
  fVar14 = (float)VectorSignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
  fVar15 = (float)VectorSignedToFloat(*(undefined4 *)(Globals::layout + 0x104),
                                      (byte)(in_fpscr >> 0x16) & 3);
  fVar16 = (float)VectorSignedToFloat(iVar2 >> 1,(byte)(in_fpscr >> 0x16) & 3);
  AbyssEngine::PaintCanvas::DrawString
            (pPVar1,uVar9,aAStack_44,(int)(((fVar17 + fVar12 + fVar3) - fVar14) - fVar16),
             (int)(*(float *)(this + 0x14) + fVar15),false);
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  iVar2 = Status::getCurrentCampaignMission(Globals::status);
  if (iVar2 < 5) {
    VectorSignedToFloat(*(undefined4 *)(this + 0xcc),(byte)(in_fpscr >> 0x16) & 3);
    AbyssEngine::PaintCanvas::SetColor((uchar)Globals::Canvas,0xff,0xff,0xff);
    pSVar4 = (String *)GameText::getText(Globals::gameText,0x268);
    AbyssEngine::String::String((String *)local_4c,pSVar4,false);
    iVar2 = Globals::w;
    uVar9 = Globals::font;
    pPVar1 = Globals::Canvas;
    iVar5 = AbyssEngine::PaintCanvas::GetTextWidth(Globals::Canvas,Globals::font,(String *)local_4c)
    ;
    AbyssEngine::PaintCanvas::DrawString
              (pPVar1,uVar9,(String *)local_4c,iVar2 / 2 - iVar5 / 2,
               *(int *)(Globals::layout + 0x70) + *(int *)(this + 0x54),false);
    AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
    AbyssEngine::String::~String((String *)local_4c);
  }
  AbyssEngine::String::~String((String *)aAStack_44);
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

