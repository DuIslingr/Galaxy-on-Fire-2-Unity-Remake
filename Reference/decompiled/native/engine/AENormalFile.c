// Class: AENormalFile
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AENormalFile::AENormalFile  @0x00079090  (14 bytes)
/* AENormalFile::AENormalFile(FileInterface*) */

void __thiscall AENormalFile::AENormalFile(AENormalFile *this,FileInterface *param_1)

{
  *(undefined ***)this = &PTR__AENormalFile_00263374;
  *(FileInterface **)(this + 4) = param_1;
  return;
}

// ===== AENormalFile::~AENormalFile  @0x000790a4  (44 bytes)
/* AENormalFile::~AENormalFile() */

AENormalFile * __thiscall AENormalFile::~AENormalFile(AENormalFile *this)

{
  *(undefined ***)this = &PTR__AENormalFile_00263374;
  if (*(int **)(this + 4) != (int *)0x0) {
    (**(code **)(**(int **)(this + 4) + 0x44))();
    if (*(int **)(this + 4) != (int *)0x0) {
      (**(code **)(**(int **)(this + 4) + 4))();
    }
  }
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== AENormalFile::~AENormalFile  @0x000790d8  (16 bytes)
/* AENormalFile::~AENormalFile() */

void __thiscall AENormalFile::~AENormalFile(AENormalFile *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~AENormalFile(this);
  operator_delete(pvVar1);
  return;
}

// ===== AENormalFile::Release  @0x000790e8  (34 bytes)
/* AENormalFile::Release() */

undefined4 __thiscall AENormalFile::Release(AENormalFile *this)

{
  if (*(int **)(this + 4) != (int *)0x0) {
    (**(code **)(**(int **)(this + 4) + 0x44))();
    if (*(int **)(this + 4) != (int *)0x0) {
      (**(code **)(**(int **)(this + 4) + 4))();
    }
  }
  *(undefined4 *)(this + 4) = 0;
  return 1;
}

// ===== AENormalFile::Read  @0x0007910a  (20 bytes)
/* AENormalFile::Read(unsigned int, void*) */

undefined4 AENormalFile::Read(uint param_1,void *param_2)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x14))();
    return uVar1;
  }
  return 0;
}

// ===== AENormalFile::Write  @0x0007911e  (20 bytes)
/* AENormalFile::Write(unsigned int, void*) */

undefined4 AENormalFile::Write(uint param_1,void *param_2)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x18))();
    return uVar1;
  }
  return 0;
}

// ===== AENormalFile::Skip  @0x00079132  (20 bytes)
/* AENormalFile::Skip(unsigned int) */

undefined4 AENormalFile::Skip(uint param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x1c))();
    return uVar1;
  }
  return 0;
}

// ===== AENormalFile::GetFileSize  @0x00079146  (14 bytes)
/* AENormalFile::GetFileSize() */

undefined4 __thiscall AENormalFile::GetFileSize(AENormalFile *this)

{
  undefined4 uVar1;
  
  if (*(int **)(this + 4) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0007914e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(this + 4) + 0x20))();
    return uVar1;
  }
  return 0;
}

