// Class: ImageFactory
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ImageFactory::ImageFactory  @0x00141584  (102 bytes)
/* ImageFactory::ImageFactory() */

ImageFactory * __thiscall ImageFactory::ImageFactory(ImageFactory *this)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  
  *(undefined4 *)this = 0;
  if (Globals::retinaDisplay != '\0' || Globals::n9 != '\0') {
    iVar3 = 0;
    puVar7 = &DAT_00258180;
    puVar5 = IMAGE_OFFSETS;
    do {
      iVar4 = 4;
      puVar1 = puVar7;
      puVar2 = (undefined4 *)puVar5;
      do {
        uVar6 = puVar1[1];
        iVar4 = iVar4 + -1;
        *puVar2 = *puVar1;
        puVar2[1] = uVar6;
        puVar2 = puVar2 + 2;
        puVar1 = puVar1 + 2;
      } while (iVar4 != 0);
      iVar3 = iVar3 + 1;
      puVar5 = (undefined1 *)((int)puVar5 + 0x20);
      puVar7 = puVar7 + 8;
    } while (iVar3 != 0xd);
  }
  reload(this);
  return this;
}

// ===== ImageFactory::reload  @0x001415fc  (222 bytes)
/* ImageFactory::reload() */

void __thiscall ImageFactory::reload(ImageFactory *this)

{
  uint *puVar1;
  void *pvVar2;
  Sprite *this_00;
  int iVar3;
  int iVar4;
  
  puVar1 = operator_new__(0x18);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4fa,puVar1);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4fb,puVar1 + 1);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f7,puVar1 + 2);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f8,puVar1 + 3);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4f9,puVar1 + 4);
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x4fc,puVar1 + 5);
  if (*(Sprite **)this != (Sprite *)0x0) {
    pvVar2 = (void *)Sprite::~Sprite(*(Sprite **)this);
    operator_delete(pvVar2);
  }
  *(undefined4 *)this = 0;
  this_00 = operator_new(0x40);
  iVar3 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,*puVar1);
  iVar4 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,*puVar1);
  Sprite::Sprite(this_00,puVar1,6,iVar3,iVar4);
  *(Sprite **)this = this_00;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x485,(uint *)(this + 4));
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,0x511,(uint *)(this + 8));
  return;
}

// ===== ImageFactory::~ImageFactory  @0x001416f8  (26 bytes)
/* ImageFactory::~ImageFactory() */

ImageFactory * __thiscall ImageFactory::~ImageFactory(ImageFactory *this)

{
  void *pvVar1;
  
  if (*(Sprite **)this != (Sprite *)0x0) {
    pvVar1 = (void *)Sprite::~Sprite(*(Sprite **)this);
    operator_delete(pvVar1);
  }
  *(undefined4 *)this = 0;
  return this;
}

// ===== ImageFactory::createChar  @0x00141714  (36 bytes)
/* ImageFactory::createChar(int) */

void __thiscall ImageFactory::createChar(ImageFactory *this,int param_1)

{
  ImageFactory *this_00;
  
  this_00 = (ImageFactory *)AbyssEngine::AERandom::nextInt(Globals::rnd,2);
  createChar(this_00,this_00 == (ImageFactory *)0x0,param_1);
  return;
}

// ===== ImageFactory::createChar  @0x0014173c  (116 bytes)
/* ImageFactory::createChar(bool, int) */

int * __thiscall ImageFactory::createChar(ImageFactory *this,bool param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2 == 3) &&
     (iVar1 = AbyssEngine::AERandom::nextInt(Globals::rnd,4), param_2 = 0, iVar1 != 0)) {
    param_2 = 2;
  }
  iVar1 = param_2;
  if (param_2 == 0) {
    iVar1 = 10;
  }
  if (param_1) {
    iVar1 = param_2;
  }
  if (iVar1 == 5) {
    iVar1 = 0;
  }
  piVar2 = operator_new__(0x14);
  *piVar2 = iVar1;
  iVar4 = 0;
  do {
    iVar3 = AbyssEngine::AERandom::nextInt
                      (Globals::rnd,*(int *)(&UNK_00258320 + iVar4 * 4 + iVar1 * 0x10));
    piVar2[iVar4 + 1] = iVar3;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 4);
  return piVar2;
}

// ===== ImageFactory::loadChar  @0x001417bc  (114 bytes)
/* ImageFactory::loadChar(int*) */

Array * __thiscall ImageFactory::loadChar(ImageFactory *this,int *param_1)

{
  Array *pAVar1;
  undefined4 *puVar2;
  ImageFactory *extraout_r0;
  ImageFactory *this_00;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == (int *)0x0) {
    pAVar1 = (Array *)0x0;
  }
  else {
    pAVar1 = operator_new(0xc);
    puVar2 = operator_new__(4);
    iVar5 = 0;
    *(undefined4 **)(pAVar1 + 4) = puVar2;
    *(undefined4 *)(pAVar1 + 8) = 1;
    *puVar2 = 0;
    *(undefined4 *)pAVar1 = 0;
    ArraySetLength<ImagePart*>(4,pAVar1);
    iVar4 = *param_1;
    this_00 = extraout_r0;
    do {
      if (param_1[iVar5 + 1] != -1) {
        this_00 = (ImageFactory *)loadImage(this_00,iVar4,iVar5,param_1[iVar5 + 1]);
        *(ImageFactory **)(*(int *)(pAVar1 + 4) + iVar5 * 4) = this_00;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 4);
    puVar2 = *(undefined4 **)(pAVar1 + 4);
    uVar3 = *puVar2;
    *puVar2 = puVar2[2];
    *(undefined4 *)(*(int *)(pAVar1 + 4) + 8) = uVar3;
  }
  return pAVar1;
}

// ===== ImageFactory::loadImage  @0x00141870  (226 bytes)
/* ImageFactory::loadImage(int, int, int) */

void __thiscall ImageFactory::loadImage(ImageFactory *this,int param_1,int param_2,int param_3)

{
  ImagePart *this_00;
  int *piVar1;
  undefined **ppuVar2;
  int iVar3;
  uint local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (-1 < *(int *)(&UNK_002583f0 + param_2 * 4 + param_1 * 0x10)) {
    local_1c = 0;
    AbyssEngine::PaintCanvas::Image2DCreate
              (Globals::Canvas,
               (short)*(int *)(&UNK_002583f0 + param_2 * 4 + param_1 * 0x10) + (short)param_3,
               &local_1c);
    this_00 = operator_new(0x14);
    if (Globals::iPadHD == '\0') {
      if (Globals::iPadLarge == '\0') {
        if (Globals::iPad == '\0') {
          ppuVar2 = &PTR_IMAGE_OFFSETS_00265a1c;
        }
        else {
          ppuVar2 = &PTR_IMAGE_OFFSETS_IPAD_00265a28;
        }
      }
      else {
        ppuVar2 = &PTR_IMAGE_OFFSETS_IPAD_LARGE_00265a24;
      }
      iVar3 = *(int *)(*ppuVar2 + param_2 * 8 + param_1 * 0x20);
      if (Globals::iPadLarge == '\0') {
        if (Globals::iPad == '\0') {
          ppuVar2 = &PTR_IMAGE_OFFSETS_00265a1c;
        }
        else {
          ppuVar2 = &PTR_IMAGE_OFFSETS_IPAD_00265a28;
        }
      }
      else {
        ppuVar2 = &PTR_IMAGE_OFFSETS_IPAD_LARGE_00265a24;
      }
      piVar1 = (int *)(*ppuVar2 + param_2 * 8 + param_1 * 0x20);
    }
    else {
      piVar1 = (int *)(IMAGE_OFFSETS_IPAD_HD + param_2 * 8 + param_1 * 0x20);
      iVar3 = *piVar1;
    }
    ImagePart::ImagePart(this_00,local_1c,iVar3,piVar1[1]);
  }
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== ImageFactory::drawChar  @0x001419a0  (102 bytes)
/* ImageFactory::drawChar(Array<ImagePart*>*, int, int, bool) */

void __thiscall
ImageFactory::drawChar(ImageFactory *this,Array *param_1,int param_2,int param_3,bool param_4)

{
  ImagePart *this_00;
  uint uVar1;
  uint uVar2;
  
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 4),param_2,param_3);
  uVar1 = *(uint *)param_1;
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      this_00 = *(ImagePart **)(*(int *)(param_1 + 4) + uVar2 * 4);
      if (this_00 != (ImagePart *)0x0) {
        ImagePart::draw(this_00,param_2,param_3,param_4);
        uVar1 = *(uint *)param_1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,*(uint *)(this + 8),param_2,param_3);
  return;
}

// ===== ImageFactory::drawItem  @0x00141a10  (146 bytes)
/* ImageFactory::drawItem(int, int, int, int) */

void __thiscall
ImageFactory::drawItem(ImageFactory *this,int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  undefined8 uVar2;
  uint local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  Sprite::setFrame(*(Sprite **)this,param_2);
  uVar2 = Sprite::setPosition(*(Sprite **)this,param_3,param_4);
  Sprite::draw((float)uVar2,(float)((ulonglong)uVar2 >> 0x20));
  sVar1 = 0xef0;
  local_28 = 0xffffffff;
  if (param_1 < 0xb0) {
    sVar1 = 0x898;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,sVar1 + (short)param_1,&local_28);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,local_28,param_3,param_4);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ImageFactory::getItemImageId  @0x00141ab0  (16 bytes)
/* ImageFactory::getItemImageId(int) */

int __thiscall ImageFactory::getItemImageId(ImageFactory *this,int param_1)

{
  int iVar1;
  
  iVar1 = 0xef0;
  if (param_1 < 0xb0) {
    iVar1 = 0x898;
  }
  return iVar1 + param_1;
}

// ===== ImageFactory::drawItem  @0x00141ac0  (108 bytes)
/* ImageFactory::drawItem(int, int, int) */

void __thiscall ImageFactory::drawItem(ImageFactory *this,int param_1,int param_2,int param_3)

{
  short sVar1;
  uint local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  sVar1 = 0xef0;
  local_24 = 0xffffffff;
  if (param_1 < 0xb0) {
    sVar1 = 0x898;
  }
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,sVar1 + (short)param_1,&local_24);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,local_24,param_2,param_3);
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== ImageFactory::drawShip  @0x00141b38  (132 bytes)
/* ImageFactory::drawShip(int, int, int) */

void __thiscall ImageFactory::drawShip(ImageFactory *this,int param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  uint local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  AbyssEngine::PaintCanvas::SetColor((uint)Globals::Canvas);
  Sprite::setFrame(*(Sprite **)this,5);
  uVar1 = Sprite::setPosition(*(Sprite **)this,param_2,param_3);
  Sprite::draw((float)uVar1,(float)((ulonglong)uVar1 >> 0x20));
  local_28 = 0xffffffff;
  AbyssEngine::PaintCanvas::Image2DCreate(Globals::Canvas,(short)param_1 + 0x971,&local_28);
  AbyssEngine::PaintCanvas::DrawImage2D(Globals::Canvas,local_28,param_2,param_3);
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

