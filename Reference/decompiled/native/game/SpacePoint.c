// Class: SpacePoint
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== SpacePoint::SpacePoint  @0x0018cdf0  (56 bytes)
/* SpacePoint::SpacePoint(int, AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector
   const&, int) */

SpacePoint * __thiscall
SpacePoint::SpacePoint(SpacePoint *this,int param_1,Vector *param_2,Vector *param_3,int param_4)

{
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x10) = 0;
  *(int *)(this + 0x18) = param_1;
  AbyssEngine::AEMath::Vector::operator=((Vector *)this,param_2);
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0xc),param_3);
  this[0x1c] = (SpacePoint)0x1;
  *(int *)(this + 0x20) = param_4;
  return this;
}

// ===== SpacePoint::isFree  @0x0018ce28  (4 bytes)
/* SpacePoint::isFree() */

SpacePoint __thiscall SpacePoint::isFree(SpacePoint *this)

{
  return this[0x1c];
}

// ===== SpacePoint::take  @0x0018ce2c  (6 bytes)
/* SpacePoint::take() */

void __thiscall SpacePoint::take(SpacePoint *this)

{
  this[0x1c] = (SpacePoint)0x0;
  return;
}

// ===== SpacePoint::giveFree  @0x0018ce32  (6 bytes)
/* SpacePoint::giveFree() */

void __thiscall SpacePoint::giveFree(SpacePoint *this)

{
  this[0x1c] = (SpacePoint)0x1;
  return;
}

// ===== SpacePoint::getIndex  @0x0018ce38  (4 bytes)
/* SpacePoint::getIndex() */

undefined4 __thiscall SpacePoint::getIndex(SpacePoint *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== SpacePoint::~SpacePoint  @0x0018ce3c  (2 bytes)
/* SpacePoint::~SpacePoint() */

SpacePoint * __thiscall SpacePoint::~SpacePoint(SpacePoint *this)

{
  return this;
}

