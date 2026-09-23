// Class: std
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== std::__throw_bad_alloc  @0x001c32dc  (30 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_bad_alloc() */

void std::__throw_bad_alloc(void)

{
  bad_alloc *this;
  undefined4 uVar1;
  
  this = (bad_alloc *)__cxa_allocate_exception(4);
  uVar1 = bad_alloc::bad_alloc(this);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(uVar1,&bad_alloc::typeinfo,bad_array_length::~bad_array_length);
}

// ===== std::get_unexpected  @0x001c39dc  (28 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::get_unexpected() */

void std::get_unexpected(void)

{
  bool bVar1;
  
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(&__cxa_unexpected_handler);
    bVar1 = (bool)hasExclusiveAccess(&__cxa_unexpected_handler);
  } while (!bVar1);
  DataMemoryBarrier(0x1b);
  return;
}

// ===== std::unexpected  @0x001c3a10  (12 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::unexpected() */

void std::unexpected(void)

{
  bool bVar1;
  
  get_unexpected();
  FUN_001c39fc();
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(&__cxa_terminate_handler);
    bVar1 = (bool)hasExclusiveAccess(&__cxa_terminate_handler);
  } while (!bVar1);
  DataMemoryBarrier(0x1b);
  return;
}

// ===== std::get_terminate  @0x001c3a1c  (28 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::get_terminate() */

void std::get_terminate(void)

{
  bool bVar1;
  
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(&__cxa_terminate_handler);
    bVar1 = (bool)hasExclusiveAccess(&__cxa_terminate_handler);
  } while (!bVar1);
  DataMemoryBarrier(0x1b);
  return;
}

// ===== std::terminate  @0x001c3a70  (66 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::terminate() */

void std::terminate(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)__cxa_get_globals_fast();
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
  }
  if ((piVar1 != (int *)0x0 && iVar2 != 0) &&
     ((*(uint *)(iVar2 + 0x28) >> 8 | *(uint *)(iVar2 + 0x2c) << 0x18) == 0x47432b2b &&
      *(uint *)(iVar2 + 0x2c) >> 8 == 0x434c4e)) {
                    /* WARNING: Subroutine does not return */
    FUN_001c3a3c(*(undefined4 *)(iVar2 + 0x10));
  }
  get_terminate();
                    /* WARNING: Subroutine does not return */
  FUN_001c3a3c();
}

// ===== std::set_new_handler  @0x001c3ab8  (30 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::set_new_handler(void (*)()) */

undefined4 std::set_new_handler(_func_void *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = __cxa_new_handler;
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(&__cxa_new_handler);
    bVar1 = (bool)hasExclusiveAccess(&__cxa_new_handler);
  } while (!bVar1);
  __cxa_new_handler = param_1;
  DataMemoryBarrier(0x1b);
  return uVar2;
}

// ===== std::get_new_handler  @0x001c3adc  (28 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::get_new_handler() */

void std::get_new_handler(void)

{
  bool bVar1;
  
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(&__cxa_new_handler);
    bVar1 = (bool)hasExclusiveAccess(&__cxa_new_handler);
  } while (!bVar1);
  DataMemoryBarrier(0x1b);
  return;
}

// ===== std::set_unexpected  @0x001c57c4  (38 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::set_unexpected(void (*)()) */

undefined4 std::set_unexpected(_func_void *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = __cxa_unexpected_handler;
  __cxa_unexpected_handler = (code *)0x1c57a9;
  if (param_1 != (_func_void *)0x0) {
    __cxa_unexpected_handler = param_1;
  }
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(&__cxa_unexpected_handler);
    bVar1 = (bool)hasExclusiveAccess(&__cxa_unexpected_handler);
  } while (!bVar1);
  DataMemoryBarrier(0x1b);
  return uVar2;
}

// ===== std::set_terminate  @0x001c57f4  (38 bytes)
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::set_terminate(void (*)()) */

undefined4 std::set_terminate(_func_void *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = __cxa_terminate_handler;
  __cxa_terminate_handler = (code *)0x1c56b1;
  if (param_1 != (_func_void *)0x0) {
    __cxa_terminate_handler = param_1;
  }
  DataMemoryBarrier(0x1b);
  do {
    ExclusiveAccess(&__cxa_terminate_handler);
    bVar1 = (bool)hasExclusiveAccess(&__cxa_terminate_handler);
  } while (!bVar1);
  DataMemoryBarrier(0x1b);
  return uVar2;
}

