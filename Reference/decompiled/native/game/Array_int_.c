// Class: Array<int>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<int>::~Array  @0x0008eb42  (22 bytes)
/* Array<int>::~Array() */

Array<int> * __thiscall Array<int>::~Array(Array<int> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

