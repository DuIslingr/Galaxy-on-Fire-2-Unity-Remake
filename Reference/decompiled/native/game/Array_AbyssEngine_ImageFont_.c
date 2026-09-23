// Class: Array<AbyssEngine::ImageFont*>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::ImageFont*>::~Array  @0x000816a0  (22 bytes)
/* Array<AbyssEngine::ImageFont*>::~Array() */

Array<AbyssEngine::ImageFont*> * __thiscall
Array<AbyssEngine::ImageFont*>::~Array(Array<AbyssEngine::ImageFont*> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

