// Class: std::bad_typeid
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::bad_typeid::bad_typeid  @0x001c5620  (12 bytes)
/* std::bad_typeid::bad_typeid() */

void __thiscall std::bad_typeid::bad_typeid(bad_typeid *this)

{
  *(undefined ***)this = &PTR__bad_typeid_002652a4;
  return;
}

// ===== std::bad_typeid::~bad_typeid  @0x001c5630  (4 bytes)
/* std::bad_typeid::~bad_typeid() */

void __thiscall std::bad_typeid::~bad_typeid(bad_typeid *this)

{
  bad_exception::~bad_exception((bad_exception *)this);
  return;
}

// ===== std::bad_typeid::~bad_typeid  @0x001c5634  (16 bytes)
/* std::bad_typeid::~bad_typeid() */

void __thiscall std::bad_typeid::~bad_typeid(bad_typeid *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)bad_exception::~bad_exception((bad_exception *)this);
  operator_delete(pvVar1);
  return;
}

// ===== std::bad_typeid::what  @0x001c5644  (6 bytes)
/* std::bad_typeid::what() const */

char * std::bad_typeid::what(void)

{
  return "std::bad_typeid";
}

