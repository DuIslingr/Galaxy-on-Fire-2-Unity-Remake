// Class: Array<unsigned_int>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<unsigned_int>::~Array  @0x00081606  (22 bytes)
/* Array<unsigned int>::~Array() */

Array<unsigned_int> * __thiscall Array<unsigned_int>::~Array(Array<unsigned_int> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

