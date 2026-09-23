// Class: std::bad_array_new_length
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::bad_array_new_length::bad_array_new_length  @0x001c3bcc  (12 bytes)
/* std::bad_array_new_length::bad_array_new_length() */

void __thiscall std::bad_array_new_length::bad_array_new_length(bad_array_new_length *this)

{
  *(undefined ***)this = &PTR__bad_array_length_00264c44;
  return;
}

// ===== std::bad_array_new_length::~bad_array_new_length  @0x001c3bdc  (16 bytes)
/* std::bad_array_new_length::~bad_array_new_length() */

void __thiscall std::bad_array_new_length::~bad_array_new_length(bad_array_new_length *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)bad_exception::~bad_exception((bad_exception *)this);
  operator_delete(pvVar1);
  return;
}

// ===== std::bad_array_new_length::what  @0x001c3bec  (6 bytes)
/* std::bad_array_new_length::what() const */

char * std::bad_array_new_length::what(void)

{
  return "bad_array_new_length";
}

