// Class: ImagePart
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ImagePart::ImagePart  @0x000b4a10  (46 bytes)
/* ImagePart::ImagePart(unsigned int, int, int) */

ImagePart * __thiscall ImagePart::ImagePart(ImagePart *this,uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *(uint *)this = param_1;
  *(int *)(this + 4) = param_2;
  *(int *)(this + 8) = param_3;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DWidth(Globals::Canvas,param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = AbyssEngine::PaintCanvas::GetImage2DHeight(Globals::Canvas,param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  return this;
}

// ===== ImagePart::~ImagePart  @0x000b4a44  (2 bytes)
/* ImagePart::~ImagePart() */

ImagePart * __thiscall ImagePart::~ImagePart(ImagePart *this)

{
  return this;
}

// ===== ImagePart::draw  @0x000b4a48  (66 bytes)
/* ImagePart::draw(int, int, bool) */

void __thiscall ImagePart::draw(ImagePart *this,int param_1,int param_2,bool param_3)

{
  AbyssEngine::PaintCanvas::DrawImage2D
            (Globals::Canvas,*(uint *)this,param_1,*(int *)(this + 8) + param_2,*(int *)(this + 0xc)
             ,*(int *)(this + 0x10),'\x11',(byte)*(undefined4 *)(this + 4) | 1,param_3);
  return;
}

