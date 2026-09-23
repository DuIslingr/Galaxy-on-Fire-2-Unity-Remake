// Class: std::bad_cast
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::bad_cast::bad_cast  @0x001c55f0  (12 bytes)
/* std::bad_cast::bad_cast() */

void __thiscall std::bad_cast::bad_cast(bad_cast *this)

{
  *(undefined ***)this = &PTR__bad_cast_00265290;
  return;
}

// ===== std::bad_cast::~bad_cast  @0x001c5600  (4 bytes)
/* std::bad_cast::~bad_cast() */

void __thiscall std::bad_cast::~bad_cast(bad_cast *this)

{
  bad_exception::~bad_exception((bad_exception *)this);
  return;
}

// ===== std::bad_cast::~bad_cast  @0x001c5604  (16 bytes)
/* std::bad_cast::~bad_cast() */

void __thiscall std::bad_cast::~bad_cast(bad_cast *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)bad_exception::~bad_exception((bad_exception *)this);
  operator_delete(pvVar1);
  return;
}

// ===== std::bad_cast::what  @0x001c5614  (6 bytes)
/* std::bad_cast::what() const */

char * std::bad_cast::what(void)

{
  return "std::bad_cast";
}

