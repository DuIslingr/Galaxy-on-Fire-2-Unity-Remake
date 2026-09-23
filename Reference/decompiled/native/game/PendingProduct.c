// Class: PendingProduct
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== PendingProduct::PendingProduct  @0x00154520  (96 bytes)
/* PendingProduct::PendingProduct(BluePrint*) */

void __thiscall PendingProduct::PendingProduct(PendingProduct *this,BluePrint *param_1)

{
  undefined4 uVar1;
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String((String *)this);
  uVar1 = BluePrint::getIndex(param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  BluePrint::getStationName();
  AbyssEngine::String::operator=((String *)this,aSStack_1c);
  AbyssEngine::String::~String(aSStack_1c);
  uVar1 = BluePrint::getStationIndex(param_1);
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = BluePrint::getQuantity(param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  if (__stack_chk_guard - local_14 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_14);
  }
  return;
}

// ===== PendingProduct::PendingProduct  @0x001545a4  (38 bytes)
/* PendingProduct::PendingProduct(int, AbyssEngine::String, int, int) */

PendingProduct * __thiscall
PendingProduct::PendingProduct
          (PendingProduct *this,undefined4 param_1,String *param_3,undefined4 param_4,
          undefined4 param_5)

{
  String *this_00;
  
  this_00 = (String *)AbyssEngine::String::String((String *)this);
  *(undefined4 *)(this + 0x10) = param_1;
  AbyssEngine::String::operator=(this_00,param_3);
  *(undefined4 *)(this + 8) = param_4;
  *(undefined4 *)(this + 0xc) = param_5;
  return this;
}

// ===== PendingProduct::~PendingProduct  @0x001545d8  (4 bytes)
/* PendingProduct::~PendingProduct() */

void __thiscall PendingProduct::~PendingProduct(PendingProduct *this)

{
  AbyssEngine::String::~String((String *)this);
  return;
}

