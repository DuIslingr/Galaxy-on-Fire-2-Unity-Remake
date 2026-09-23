// Class: Array<AbyssEngine::AEMath::Matrix>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<AbyssEngine::AEMath::Matrix>::~Array  @0x000815f0  (22 bytes)
/* Array<AbyssEngine::AEMath::Matrix>::~Array() */

Array<AbyssEngine::AEMath::Matrix> * __thiscall
Array<AbyssEngine::AEMath::Matrix>::~Array(Array<AbyssEngine::AEMath::Matrix> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

