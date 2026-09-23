// Class: std::bad_array_length
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::bad_array_length::~bad_array_length  @0x001c3bac  (4 bytes)
/* std::bad_array_length::~bad_array_length() */

void __thiscall std::bad_array_length::~bad_array_length(bad_array_length *this)

{
  bad_exception::~bad_exception((bad_exception *)this);
  return;
}

// ===== std::bad_array_length::bad_array_length  @0x001c3bf8  (12 bytes)
/* std::bad_array_length::bad_array_length() */

void __thiscall std::bad_array_length::bad_array_length(bad_array_length *this)

{
  *(undefined ***)this = &PTR__bad_array_length_00264c58;
  return;
}

// ===== std::bad_array_length::~bad_array_length  @0x001c3c08  (16 bytes)
/* std::bad_array_length::~bad_array_length() */

void __thiscall std::bad_array_length::~bad_array_length(bad_array_length *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)bad_exception::~bad_exception((bad_exception *)this);
  operator_delete(pvVar1);
  return;
}

// ===== std::bad_array_length::what  @0x001c3c18  (6 bytes)
/* std::bad_array_length::what() const */

char * std::bad_array_length::what(void)

{
  return "bad_array_length";
}

