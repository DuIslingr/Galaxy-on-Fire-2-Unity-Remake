// Class: std::bad_alloc
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::bad_alloc::bad_alloc  @0x001c3b9c  (12 bytes)
/* std::bad_alloc::bad_alloc() */

void __thiscall std::bad_alloc::bad_alloc(bad_alloc *this)

{
  *(undefined ***)this = &PTR__bad_array_length_00264c30;
  return;
}

// ===== std::bad_alloc::~bad_alloc  @0x001c3bb0  (16 bytes)
/* std::bad_alloc::~bad_alloc() */

void __thiscall std::bad_alloc::~bad_alloc(bad_alloc *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)bad_exception::~bad_exception((bad_exception *)this);
  operator_delete(pvVar1);
  return;
}

// ===== std::bad_alloc::what  @0x001c3bc0  (6 bytes)
/* std::bad_alloc::what() const */

char * std::bad_alloc::what(void)

{
  return "std::bad_alloc";
}

