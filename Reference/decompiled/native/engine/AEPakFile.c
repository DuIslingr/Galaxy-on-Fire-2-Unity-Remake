// Class: AEPakFile
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AEPakFile::AEPakFile  @0x00078fa0  (34 bytes)
/* AEPakFile::AEPakFile(FileInterface*, int, int) */

void __thiscall AEPakFile::AEPakFile(AEPakFile *this,FileInterface *param_1,int param_2,int param_3)

{
  *(undefined ***)this = &PTR__AEPakFile_00263350;
  *(FileInterface **)(this + 4) = param_1;
  *(int *)(this + 8) = param_2;
  *(int *)(this + 0xc) = param_3;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

// ===== AEPakFile::~AEPakFile  @0x00078fc8  (44 bytes)
/* AEPakFile::~AEPakFile() */

AEPakFile * __thiscall AEPakFile::~AEPakFile(AEPakFile *this)

{
  *(undefined ***)this = &PTR__AEPakFile_00263350;
  if (*(int **)(this + 4) != (int *)0x0) {
    (**(code **)(**(int **)(this + 4) + 0x44))();
    if (*(int **)(this + 4) != (int *)0x0) {
      (**(code **)(**(int **)(this + 4) + 4))();
    }
    *(undefined4 *)(this + 4) = 0;
  }
  return this;
}

// ===== AEPakFile::~AEPakFile  @0x00078ffc  (16 bytes)
/* AEPakFile::~AEPakFile() */

void __thiscall AEPakFile::~AEPakFile(AEPakFile *this)

{
  void *pvVar1;
  
  pvVar1 = (void *)~AEPakFile(this);
  operator_delete(pvVar1);
  return;
}

// ===== AEPakFile::Read  @0x0007900c  (52 bytes)
/* AEPakFile::Read(unsigned int, void*) */

undefined4 AEPakFile::Read(uint param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 != (void *)0x0) && (*(int **)(param_1 + 4) != (int *)0x0)) {
    iVar2 = *(int *)(param_1 + 0x10);
    if (*(int *)(param_1 + 8) < iVar2 + (int)param_2) {
      param_2 = (void *)(*(int *)(param_1 + 8) - iVar2);
    }
    if (param_2 != (void *)0x0) {
      *(int *)(param_1 + 0x10) = (int)param_2 + iVar2;
      uVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x14))();
      return uVar1;
    }
  }
  return 0;
}

// ===== AEPakFile::Skip  @0x00079040  (42 bytes)
/* AEPakFile::Skip(unsigned int) */

undefined4 __thiscall AEPakFile::Skip(AEPakFile *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new__(param_1);
  (**(code **)(*(int *)this + 0xc))(this,param_1,pvVar1);
  operator_delete__(pvVar1);
  return 1;
}

// ===== AEPakFile::GetFileSize  @0x0007906a  (4 bytes)
/* AEPakFile::GetFileSize() */

undefined4 __thiscall AEPakFile::GetFileSize(AEPakFile *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== AEPakFile::Release  @0x0007906e  (34 bytes)
/* AEPakFile::Release() */

undefined4 __thiscall AEPakFile::Release(AEPakFile *this)

{
  if (*(int **)(this + 4) != (int *)0x0) {
    (**(code **)(**(int **)(this + 4) + 0x44))();
    if (*(int **)(this + 4) != (int *)0x0) {
      (**(code **)(**(int **)(this + 4) + 4))();
    }
    *(undefined4 *)(this + 4) = 0;
  }
  return 1;
}

// ===== AEPakFile::Write  @0x0007a590  (4 bytes)
/* AEPakFile::Write(unsigned int, void*) */

undefined4 AEPakFile::Write(uint param_1,void *param_2)

{
  return 0;
}

