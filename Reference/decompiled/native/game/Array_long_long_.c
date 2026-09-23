// Class: Array<long_long>
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Array<long_long>::~Array  @0x0008c970  (22 bytes)
/* Array<long long>::~Array() */

Array<long_long> * __thiscall Array<long_long>::~Array(Array<long_long> *this)

{
  if (*(void **)(this + 4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 4));
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

