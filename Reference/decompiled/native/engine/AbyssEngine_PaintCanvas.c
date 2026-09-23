// Class: AbyssEngine::PaintCanvas
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::PaintCanvas::PaintCanvas  @0x00081200  (654 bytes)
/* AbyssEngine::PaintCanvas::PaintCanvas(AbyssEngine::Engine*) */

PaintCanvas * __thiscall AbyssEngine::PaintCanvas::PaintCanvas(PaintCanvas *this,Engine *param_1)

{
  undefined1 auVar1 [16];
  short sVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x14) = puVar3;
  *(undefined4 *)(this + 0x18) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x10) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x28) = puVar3;
  *(undefined4 *)(this + 0x2c) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0xf8) = 0x3f800000;
  *(undefined4 *)(this + 0xfc) = 0;
  *(undefined4 *)(this + 0x100) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x104) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x108) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x10c) = 0x3f800000;
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x114) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x118) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x11c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined8 *)(this + 0x120) = 0x3f800000;
  *(undefined8 *)(this + 0x128) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0x130) = 0x3f800000;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x138) = puVar3;
  *(undefined4 *)(this + 0x13c) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x134) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x144) = puVar3;
  *(undefined4 *)(this + 0x148) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x140) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x150) = puVar3;
  *(undefined4 *)(this + 0x154) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x15c) = puVar3;
  *(undefined4 *)(this + 0x160) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x158) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x168) = puVar3;
  *(undefined4 *)(this + 0x16c) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x164) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x178) = puVar3;
  *(undefined4 *)(this + 0x17c) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x174) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x184) = puVar3;
  *(undefined4 *)(this + 0x188) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x180) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 400) = puVar3;
  *(undefined4 *)(this + 0x194) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  puVar3 = operator_new__(0x3c);
  uVar9 = 0;
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(this + 0x19c) = puVar3;
  *(undefined4 *)(this + 0x1a0) = 1;
  puVar3[0xb] = 0;
  puVar3[0xc] = uVar10;
  puVar3[0xd] = uVar11;
  puVar3[0xe] = uVar12;
  puVar3[8] = 0;
  puVar3[9] = uVar10;
  puVar3[10] = uVar11;
  puVar3[0xb] = uVar12;
  *puVar3 = 0;
  puVar3[1] = uVar10;
  puVar3[2] = uVar11;
  puVar3[3] = uVar12;
  puVar3[4] = 0;
  puVar3[5] = uVar10;
  puVar3[6] = uVar11;
  puVar3[7] = uVar12;
  *(undefined4 *)(this + 0x198) = 0;
  puVar3 = operator_new__(0x3c);
  *(undefined4 **)(this + 0x1a8) = puVar3;
  *(undefined4 *)(this + 0x1ac) = 1;
  puVar3[0xb] = uVar9;
  puVar3[0xc] = uVar10;
  puVar3[0xd] = uVar11;
  puVar3[0xe] = uVar12;
  puVar3[8] = uVar9;
  puVar3[9] = uVar10;
  puVar3[10] = uVar11;
  puVar3[0xb] = uVar12;
  *puVar3 = uVar9;
  puVar3[1] = uVar10;
  puVar3[2] = uVar11;
  puVar3[3] = uVar12;
  puVar3[4] = uVar9;
  puVar3[5] = uVar10;
  puVar3[6] = uVar11;
  puVar3[7] = uVar12;
  *(undefined4 *)(this + 0x1a4) = 0;
  puVar3 = operator_new__(4);
  *(undefined4 **)(this + 0x1b4) = puVar3;
  *(undefined4 *)(this + 0x1b8) = 1;
  *puVar3 = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  puVar3 = operator_new__(0x3c);
  uVar9 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 **)(this + 0x1c0) = puVar3;
  *(undefined4 *)(this + 0x1c4) = 1;
  puVar3[0xb] = 0;
  puVar3[0xc] = uVar9;
  puVar3[0xd] = uVar10;
  puVar3[0xe] = uVar11;
  puVar3[8] = 0;
  puVar3[9] = uVar9;
  puVar3[10] = uVar10;
  puVar3[0xb] = uVar11;
  *puVar3 = 0;
  puVar3[1] = uVar9;
  puVar3[2] = uVar10;
  puVar3[3] = uVar11;
  puVar3[4] = 0;
  puVar3[5] = uVar9;
  puVar3[6] = uVar10;
  puVar3[7] = uVar11;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  this[0x1f1] = (PaintCanvas)0x0;
  *(undefined4 *)(this + 500) = 1;
  *(undefined4 *)(this + 4) = 0;
  *this = (PaintCanvas)0x0;
  *(Engine **)(this + 0x34) = param_1;
  *(undefined4 *)(this + 0x170) = 0xffffffff;
  AbyssEngine::MeshCreate(param_1,4,2,0x11,this + 0x1c8);
  auVar1._8_8_ = SUB128(SUB1612((undefined1  [16])0x0,4),4);
  auVar1._0_8_ = 0x3f8000003f800000;
  auVar1 = auVar1 << 0x40 | auVar1;
  puVar4 = *(undefined2 **)(*(int *)(this + 0x1c8) + 0x2c);
  *puVar4 = 0;
  puVar4[1] = 2;
  puVar4[2] = 1;
  puVar4[3] = 0;
  puVar4[4] = 3;
  puVar4[5] = 2;
  *(undefined4 *)(this + 0x1fc) = *(undefined4 *)auVar1;
  *(undefined4 *)(this + 0x200) = *(undefined4 *)(auVar1 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x204) = *(undefined4 *)(auVar1 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x208) = *(undefined4 *)(auVar1 + (undefined1  [16])0xc);
  this[0x1c] = (PaintCanvas)0x1;
  param_1[0xec] = (Engine)0x1;
  AbyssEngine::MeshCreate(param_1,400,200,0x1b,this + 8);
  iVar5 = 0;
  iVar7 = 10;
  iVar6 = *(int *)(*(int *)(this + 8) + 0x2c);
  do {
    sVar2 = (short)iVar5;
    *(short *)(iVar6 + iVar7 + -10) = sVar2;
    iVar8 = iVar5 * 3 + iVar6;
    *(short *)(iVar8 + 2) = sVar2 + 2;
    *(short *)(iVar8 + 4) = sVar2 + 1;
    *(short *)(iVar8 + 6) = sVar2;
    iVar5 = iVar5 + 4;
    *(short *)(iVar8 + 8) = sVar2 + 3;
    *(short *)(iVar6 + iVar7) = sVar2 + 2;
    iVar7 = iVar7 + 0xc;
  } while (iVar5 != 400);
  *(undefined4 *)(this + 0x1cc) = 0;
  this[0x1f8] = (PaintCanvas)0x1;
  return this;
}

// ===== AbyssEngine::PaintCanvas::~PaintCanvas  @0x000816e4  (464 bytes)
/* AbyssEngine::PaintCanvas::~PaintCanvas() */

PaintCanvas * __thiscall AbyssEngine::PaintCanvas::~PaintCanvas(PaintCanvas *this)

{
  uint uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  
  ReleaseAllResources(this);
  uVar1 = *(uint *)(this + 0x134);
  if (uVar1 != 0) {
    uVar5 = 0;
    do {
      iVar4 = *(int *)(*(int *)(this + 0x138) + uVar5 * 4);
      if (iVar4 != 0) {
        switch(*(undefined4 *)(iVar4 + 4)) {
        case 1:
        case 3:
        case 6:
          puVar2 = *(undefined4 **)(iVar4 + 0xc);
          if (puVar2 != (undefined4 *)0x0) {
LAB_00081740:
            operator_delete(puVar2);
          }
          break;
        case 2:
        case 4:
          puVar2 = *(undefined4 **)(iVar4 + 0xc);
          if (puVar2 != (undefined4 *)0x0) {
            if ((void *)*puVar2 != (void *)0x0) {
              operator_delete__((void *)*puVar2);
            }
            goto LAB_00081740;
          }
          break;
        case 5:
          if (*(ResourceTransform **)(iVar4 + 0xc) != (ResourceTransform *)0x0) {
            puVar2 = (undefined4 *)
                     ResourceTransform::~ResourceTransform(*(ResourceTransform **)(iVar4 + 0xc));
            goto LAB_00081740;
          }
        }
        iVar4 = *(int *)(this + 0x138);
        pvVar3 = *(void **)(iVar4 + uVar5 * 4);
        if (pvVar3 != (void *)0x0) {
          operator_delete(pvVar3);
          iVar4 = *(int *)(this + 0x138);
        }
        *(undefined4 *)(iVar4 + uVar5 * 4) = 0;
        if (*(void **)(this + 400) != (void *)0x0) {
          operator_delete__(*(void **)(this + 400));
        }
        *(undefined4 *)(this + 400) = 0;
        if (*(void **)(this + 0x19c) != (void *)0x0) {
          operator_delete__(*(void **)(this + 0x19c));
        }
        *(undefined4 *)(this + 0x19c) = 0;
        if (*(void **)(this + 0x1a8) != (void *)0x0) {
          operator_delete__(*(void **)(this + 0x1a8));
        }
        *(undefined4 *)(this + 0x1a8) = 0;
        if (*(void **)(this + 0x1b4) != (void *)0x0) {
          operator_delete__(*(void **)(this + 0x1b4));
        }
        *(undefined4 *)(this + 0x1b4) = 0;
        if (*(void **)(this + 0x1c0) != (void *)0x0) {
          operator_delete__(*(void **)(this + 0x1c0));
        }
        *(undefined4 *)(this + 0x1c0) = 0;
        uVar1 = *(uint *)(this + 0x134);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  MeshRelease(*(Engine **)(this + 0x34),(Mesh **)(this + 8));
  MeshRelease(*(Engine **)(this + 0x34),(Mesh **)(this + 0x1c8));
  uVar1 = *(uint *)(this + 0x10);
  if (uVar1 != 0) {
    uVar5 = 0;
    do {
      iVar4 = *(int *)(this + 0x14);
      pvVar3 = *(void **)(iVar4 + uVar5 * 4);
      if (pvVar3 != (void *)0x0) {
        String::~String((String *)((int)pvVar3 + 4));
        operator_delete(pvVar3);
        uVar1 = *(uint *)(this + 0x10);
        iVar4 = *(int *)(this + 0x14);
      }
      *(undefined4 *)(iVar4 + uVar5 * 4) = 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  if (*(void **)(this + 0x1c0) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x1c0));
  }
  *(undefined4 *)(this + 0x1c0) = 0;
  if (*(void **)(this + 0x1b4) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x1b4));
  }
  *(undefined4 *)(this + 0x1b4) = 0;
  if (*(void **)(this + 0x1a8) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x1a8));
  }
  *(undefined4 *)(this + 0x1a8) = 0;
  if (*(void **)(this + 0x19c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x19c));
  }
  *(undefined4 *)(this + 0x19c) = 0;
  if (*(void **)(this + 400) != (void *)0x0) {
    operator_delete__(*(void **)(this + 400));
  }
  *(undefined4 *)(this + 400) = 0;
  if (*(void **)(this + 0x184) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x184));
  }
  *(undefined4 *)(this + 0x184) = 0;
  if (*(void **)(this + 0x178) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x178));
  }
  *(undefined4 *)(this + 0x178) = 0;
  if (*(void **)(this + 0x168) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x168));
  }
  *(undefined4 *)(this + 0x168) = 0;
  if (*(void **)(this + 0x15c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x15c));
  }
  *(undefined4 *)(this + 0x15c) = 0;
  if (*(void **)(this + 0x150) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x150));
  }
  *(undefined4 *)(this + 0x150) = 0;
  if (*(void **)(this + 0x144) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x144));
  }
  *(undefined4 *)(this + 0x144) = 0;
  if (*(void **)(this + 0x138) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x138));
  }
  *(undefined4 *)(this + 0x138) = 0;
  if (*(void **)(this + 0x28) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x28));
  }
  *(undefined4 *)(this + 0x28) = 0;
  if (*(void **)(this + 0x14) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x14));
  }
  *(undefined4 *)(this + 0x14) = 0;
  return this;
}

// ===== AbyssEngine::PaintCanvas::ReleaseAllResources  @0x00081934  (800 bytes)
/* AbyssEngine::PaintCanvas::ReleaseAllResources() */

void __thiscall AbyssEngine::PaintCanvas::ReleaseAllResources(PaintCanvas *this)

{
  uint uVar1;
  void *pvVar2;
  Transform *this_00;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  CubeMapSetIndex = 0;
  uVar1 = *(uint *)(this + 0x134);
  if (uVar1 != 0) {
    iVar3 = *(int *)(this + 0x138);
    uVar4 = 0;
    do {
      iVar5 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(*(int *)(iVar3 + iVar5) + 8) = 0xffffffff;
    } while (uVar4 < uVar1);
  }
  if (*(int *)(this + 0x10) != 0) {
    uVar1 = 0;
    do {
      iVar3 = *(int *)(this + 0x14);
      piVar6 = *(int **)(iVar3 + uVar1 * 4);
      if (*piVar6 != -1) {
        local_28 = *piVar6;
        glDeleteTextures(1,&local_28);
        Engine::ImageCount = Engine::ImageCount + -1;
        iVar3 = *(int *)(this + 0x14);
        *(int *)(*(int *)(this + 0x34) + 0x60) =
             *(int *)(*(int *)(this + 0x34) + 0x60) - *(int *)(*(int *)(iVar3 + uVar1 * 4) + 0x14);
        piVar6 = *(int **)(iVar3 + uVar1 * 4);
      }
      if (piVar6 != (int *)0x0) {
        String::~String((String *)(piVar6 + 1));
        operator_delete(piVar6);
        iVar3 = *(int *)(this + 0x14);
      }
      *(undefined4 *)(iVar3 + uVar1 * 4) = 0;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(this + 0x10));
  }
  *(undefined4 *)(this + 0x10) = 0;
  uVar1 = *(uint *)(this + 0x140);
  if (uVar1 != 0) {
    iVar3 = 0;
    uVar4 = 0;
    do {
      if (*(int *)(*(int *)(this + 0x144) + iVar3) != 0) {
        ImageFontRelease(*(Engine **)(this + 0x34),(ImageFont **)(*(int *)(this + 0x144) + iVar3));
        uVar1 = *(uint *)(this + 0x140);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x148) = 1;
  pvVar2 = realloc(*(void **)(this + 0x144),4);
  *(void **)(this + 0x144) = pvVar2;
  __aeabi_memclr4(pvVar2,*(int *)(this + 0x148) << 2);
  uVar1 = *(uint *)(this + 0x14c);
  if (uVar1 != 0) {
    iVar3 = 0;
    uVar4 = 0;
    do {
      if (*(int *)(*(int *)(this + 0x150) + iVar3) != 0) {
        Image2DRelease(*(Engine **)(this + 0x34),(Image2D **)(*(int *)(this + 0x150) + iVar3));
        uVar1 = *(uint *)(this + 0x14c);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x154) = 1;
  pvVar2 = realloc(*(void **)(this + 0x150),4);
  *(void **)(this + 0x150) = pvVar2;
  __aeabi_memclr4(pvVar2,*(int *)(this + 0x154) << 2);
  uVar1 = *(uint *)(this + 0x24);
  if (uVar1 != 0) {
    iVar3 = 0;
    uVar4 = 0;
    do {
      iVar5 = *(int *)(*(int *)(this + 0x28) + iVar3);
      if (iVar5 != 0) {
        Engine::vboSize = Engine::vboSize - *(int *)(iVar5 + 0x7c);
        MeshRelease(*(Engine **)(this + 0x34),(Mesh **)(*(int *)(this + 0x28) + iVar3));
        uVar1 = *(uint *)(this + 0x24);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x2c) = 1;
  pvVar2 = realloc(*(void **)(this + 0x28),4);
  *(void **)(this + 0x28) = pvVar2;
  __aeabi_memclr4(pvVar2,*(int *)(this + 0x2c) << 2);
  uVar1 = *(uint *)(this + 0x158);
  if (uVar1 != 0) {
    uVar4 = 0;
    do {
      this_00 = *(Transform **)(*(int *)(this + 0x15c) + uVar4 * 4);
      if (this_00 != (Transform *)0x0) {
        pvVar2 = (void *)Transform::~Transform(this_00);
        operator_delete(pvVar2);
        *(undefined4 *)(*(int *)(this + 0x15c) + uVar4 * 4) = 0;
        uVar1 = *(uint *)(this + 0x158);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x160) = 1;
  pvVar2 = realloc(*(void **)(this + 0x15c),4);
  *(void **)(this + 0x15c) = pvVar2;
  __aeabi_memclr4(pvVar2,*(int *)(this + 0x160) << 2);
  uVar1 = *(uint *)(this + 0x164);
  if (uVar1 != 0) {
    uVar4 = 0;
    do {
      pvVar2 = *(void **)(*(int *)(this + 0x168) + uVar4 * 4);
      if (pvVar2 != (void *)0x0) {
        operator_delete(pvVar2);
        *(undefined4 *)(*(int *)(this + 0x168) + uVar4 * 4) = 0;
        uVar1 = *(uint *)(this + 0x164);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x16c) = 1;
  pvVar2 = realloc(*(void **)(this + 0x168),4);
  *(void **)(this + 0x168) = pvVar2;
  __aeabi_memclr4(pvVar2,*(int *)(this + 0x16c) << 2);
  *(undefined4 *)(this + 0x170) = 0xffffffff;
  uVar1 = *(uint *)(this + 0x174);
  if (uVar1 != 0) {
    uVar4 = 0;
    do {
      pvVar2 = *(void **)(*(int *)(this + 0x178) + uVar4 * 4);
      if (pvVar2 != (void *)0x0) {
        if (*(void **)((int)pvVar2 + 0x60) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar2 + 0x60));
        }
        *(undefined4 *)((int)pvVar2 + 0x60) = 0;
        if (*(void **)((int)pvVar2 + 0x54) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar2 + 0x54));
        }
        *(undefined4 *)((int)pvVar2 + 0x54) = 0;
        if (*(void **)((int)pvVar2 + 0x48) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar2 + 0x48));
        }
        *(undefined4 *)((int)pvVar2 + 0x48) = 0;
        if (*(void **)((int)pvVar2 + 0x3c) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar2 + 0x3c));
        }
        *(undefined4 *)((int)pvVar2 + 0x3c) = 0;
        if (*(void **)((int)pvVar2 + 0x30) != (void *)0x0) {
          operator_delete__(*(void **)((int)pvVar2 + 0x30));
        }
        operator_delete(pvVar2);
        *(undefined4 *)(*(int *)(this + 0x178) + uVar4 * 4) = 0;
        uVar1 = *(uint *)(this + 0x174);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(this + 0x174) = 0;
  *(undefined4 *)(this + 0x17c) = 1;
  pvVar2 = realloc(*(void **)(this + 0x178),4);
  *(void **)(this + 0x178) = pvVar2;
  __aeabi_memclr4(pvVar2,*(int *)(this + 0x17c) << 2);
  uVar1 = *(uint *)(this + 0x180);
  if (uVar1 != 0) {
    iVar3 = 0;
    uVar4 = 0;
    do {
      if (*(int *)(*(int *)(this + 0x184) + iVar3) != 0) {
        SpriteSystemRelease(*(Engine **)(this + 0x34),
                            (SpriteSystem **)(*(int *)(this + 0x184) + iVar3));
        uVar1 = *(uint *)(this + 0x180);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < uVar1);
  }
  *(undefined4 *)(this + 0x180) = 0;
  *(undefined4 *)(this + 0x188) = 1;
  pvVar2 = realloc(*(void **)(this + 0x184),4);
  *(void **)(this + 0x184) = pvVar2;
  __aeabi_memclr4(pvVar2,*(int *)(this + 0x188) << 2);
  *(undefined4 *)(this + 0x1cc) = 0;
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SetResourceList  @0x00081c88  (64 bytes)
/* AbyssEngine::PaintCanvas::SetResourceList(AbyssEngine::Resource* const*, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::SetResourceList(PaintCanvas *this,Resource **param_1,uint param_2)

{
  void *pvVar1;
  
  *(uint *)(this + 0x13c) = *(int *)(this + 0x134) + param_2;
  pvVar1 = realloc(*(void **)(this + 0x138),(*(int *)(this + 0x134) + param_2) * 4);
  *(void **)(this + 0x138) = pvVar1;
  __aeabi_memcpy4((void *)((int)pvVar1 + *(int *)(this + 0x134) * 4),param_1,param_2 << 2);
  *(undefined4 *)(this + 0x134) = *(undefined4 *)(this + 0x13c);
  return;
}

// ===== AbyssEngine::PaintCanvas::AddResource  @0x00081cc8  (50 bytes)
/* AbyssEngine::PaintCanvas::AddResource(AbyssEngine::Resource*) */

void __thiscall AbyssEngine::PaintCanvas::AddResource(PaintCanvas *this,Resource *param_1)

{
  void *pvVar1;
  
  *(int *)(this + 0x13c) = *(int *)(this + 0x134) + 1;
  pvVar1 = realloc(*(void **)(this + 0x138),(*(int *)(this + 0x134) + 1) * 4);
  *(void **)(this + 0x138) = pvVar1;
  *(Resource **)((int)pvVar1 + *(int *)(this + 0x134) * 4) = param_1;
  *(undefined4 *)(this + 0x134) = *(undefined4 *)(this + 0x13c);
  return;
}

// ===== AbyssEngine::PaintCanvas::GetMeshResourceId  @0x00081cfa  (98 bytes)
/* AbyssEngine::PaintCanvas::GetMeshResourceId(AbyssEngine::String&, unsigned short) */

undefined2 __thiscall
AbyssEngine::PaintCanvas::GetMeshResourceId(PaintCanvas *this,String *param_1,ushort param_2)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  if (*(int *)(this + 0x134) != 0) {
    uVar4 = 0;
    do {
      iVar2 = *(int *)(*(int *)(this + 0x138) + uVar4 * 4);
      if ((((iVar2 != 0) && (*(int *)(iVar2 + 4) == 4)) &&
          (cVar1 = String::Compare((String *)param_1,(char *)**(undefined4 **)(iVar2 + 0xc)),
          cVar1 == '\0')) &&
         (puVar3 = *(undefined2 **)(*(int *)(this + 0x138) + uVar4 * 4),
         *(ushort *)(*(int *)(puVar3 + 6) + 4) == param_2)) {
        return *puVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(this + 0x134));
  }
  return 0xffff;
}

// ===== AbyssEngine::PaintCanvas::GetMeshResourceId  @0x00081d5c  (84 bytes)
/* AbyssEngine::PaintCanvas::GetMeshResourceId(AbyssEngine::String&) */

undefined2 __thiscall AbyssEngine::PaintCanvas::GetMeshResourceId(PaintCanvas *this,String *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(this + 0x134);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      iVar3 = *(int *)(*(int *)(this + 0x138) + uVar4 * 4);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 4)) {
        cVar1 = String::Compare((String *)param_1,(char *)**(undefined4 **)(iVar3 + 0xc));
        if (cVar1 == '\0') {
          return **(undefined2 **)(*(int *)(this + 0x138) + uVar4 * 4);
        }
        uVar2 = *(uint *)(this + 0x134);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return 0xffff;
}

// ===== AbyssEngine::PaintCanvas::GetTextureResourceId  @0x00081db0  (84 bytes)
/* AbyssEngine::PaintCanvas::GetTextureResourceId(AbyssEngine::String&) */

undefined2 __thiscall
AbyssEngine::PaintCanvas::GetTextureResourceId(PaintCanvas *this,String *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(this + 0x134);
  if (uVar2 != 0) {
    uVar4 = 0;
    do {
      iVar3 = *(int *)(*(int *)(this + 0x138) + uVar4 * 4);
      if ((iVar3 != 0) && (*(int *)(iVar3 + 4) == 2)) {
        cVar1 = String::Compare((String *)param_1,(char *)**(undefined4 **)(iVar3 + 0xc));
        if (cVar1 == '\0') {
          return **(undefined2 **)(*(int *)(this + 0x138) + uVar4 * 4);
        }
        uVar2 = *(uint *)(this + 0x134);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return 0xffff;
}

// ===== AbyssEngine::PaintCanvas::GetReverseString  @0x00081e04  (86 bytes)
/* AbyssEngine::PaintCanvas::GetReverseString(AbyssEngine::String) */

void AbyssEngine::PaintCanvas::GetReverseString(undefined4 param_1,int param_2,String *param_3)

{
  undefined4 extraout_r1;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  String::String(aSStack_24,param_3,false);
  GetReverseString(param_1,extraout_r1,aSStack_24,*(char *)(param_2 + 0x1c) == '\0');
  String::~String(aSStack_24);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::GetReverseString  @0x00081e70  (122 bytes)
/* AbyssEngine::PaintCanvas::GetReverseString(AbyssEngine::String, bool) */

void AbyssEngine::PaintCanvas::GetReverseString
               (String *param_1,undefined4 param_2,String *param_3,int param_4)

{
  uint uVar1;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (param_4 == 1) {
    String::String(param_1,"",false);
    uVar1 = *(int *)(param_3 + 4) - 1;
    if (-1 < (int)uVar1) {
      do {
        String::SubString((uint)aSStack_24,(uint)param_3);
        String::operator+=(param_1,aSStack_24);
        String::~String(aSStack_24);
        uVar1 = uVar1 - 1;
      } while (uVar1 < 0x80000000);
    }
  }
  else {
    String::String(param_1,param_3,false);
  }
  if (__stack_chk_guard == local_1c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::CheckString  @0x00081f14  (46 bytes)
/* AbyssEngine::PaintCanvas::CheckString(unsigned int, AbyssEngine::String const&) */

void __thiscall
AbyssEngine::PaintCanvas::CheckString(PaintCanvas *this,uint param_1,String *param_2)

{
  ushort *puVar1;
  ImageFont *pIVar2;
  
  if (param_1 < *(uint *)(this + 0x140)) {
    pIVar2 = *(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4);
    puVar1 = String::operator_cast_to_unsigned_short_((String *)param_2);
    ImageFontCheckString(pIVar2,puVar1,*(uint *)(param_2 + 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawString  @0x00081f40  (82 bytes)
/* AbyssEngine::PaintCanvas::DrawString(unsigned int, unsigned short const*, int, int, bool) */

void __thiscall
AbyssEngine::PaintCanvas::DrawString
          (PaintCanvas *this,uint param_1,ushort *param_2,int param_3,int param_4,bool param_5)

{
  if (param_1 < *(uint *)(this + 0x140)) {
    Engine::SetTextures(*(Engine **)(this + 0x34),
                        *(uint *)(*(int *)(*(int *)(this + 0x144) + param_1 * 4) + 8),0xffffffff);
    ImageFontDrawString(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4),param_2,param_3,
                        param_4,this,*(Engine **)(this + 0x34),param_5);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SetTexture  @0x00081f92  (8 bytes)
/* AbyssEngine::PaintCanvas::SetTexture(unsigned int, unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::SetTexture(PaintCanvas *this,uint param_1,uint param_2)

{
  Engine::SetTextures(*(Engine **)(this + 0x34),param_1,param_2);
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawString  @0x00081f98  (90 bytes)
/* AbyssEngine::PaintCanvas::DrawString(unsigned int, AbyssEngine::String const&, int, int, bool) */

void __thiscall
AbyssEngine::PaintCanvas::DrawString
          (PaintCanvas *this,uint param_1,String *param_2,int param_3,int param_4,bool param_5)

{
  ushort *puVar1;
  ImageFont *pIVar2;
  
  if (param_1 < *(uint *)(this + 0x140)) {
    Engine::SetTextures(*(Engine **)(this + 0x34),
                        *(uint *)(*(int *)(*(int *)(this + 0x144) + param_1 * 4) + 8),0xffffffff);
    pIVar2 = *(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4);
    puVar1 = String::operator_cast_to_unsigned_short_((String *)param_2);
    ImageFontDrawString(pIVar2,puVar1,*(uint *)(param_2 + 4),param_3,param_4,this,
                        *(Engine **)(this + 0x34),param_5);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawStringColor  @0x00081ff4  (398 bytes)
/* AbyssEngine::PaintCanvas::DrawStringColor(unsigned int, AbyssEngine::String const&, int, int,
   bool) */

void __thiscall
AbyssEngine::PaintCanvas::DrawStringColor
          (PaintCanvas *this,uint param_1,String *param_2,int param_3,int param_4,bool param_5)

{
  bool bVar1;
  Array *pAVar2;
  ushort *puVar3;
  int iVar4;
  String *this_00;
  char *__s;
  uint uVar5;
  ImageFont *pIVar6;
  undefined4 local_60;
  String aSStack_5c [8];
  String aSStack_54 [8];
  int local_4c;
  
  local_4c = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x140)) {
    Engine::SetTextures(*(Engine **)(this + 0x34),
                        *(uint *)(*(int *)(*(int *)(this + 0x144) + param_1 * 4) + 8),0xffffffff);
    String::String(aSStack_54,param_2,false);
    String::String(aSStack_5c,"c",false);
    pAVar2 = (Array *)String::SplitTags(aSStack_54,aSStack_5c);
    String::~String(aSStack_5c);
    if (pAVar2 != (Array *)0x0) {
      if (*(int *)pAVar2 != 0) {
        bVar1 = true;
        uVar5 = 0;
        do {
          if (bVar1) {
            pIVar6 = *(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4);
            puVar3 = String::operator_cast_to_unsigned_short_
                               (*(String **)(*(int *)(pAVar2 + 4) + uVar5 * 4));
            ImageFontDrawString(pIVar6,puVar3,
                                *(uint *)(*(int *)(*(int *)(pAVar2 + 4) + uVar5 * 4) + 4),param_3,
                                param_4,this,*(Engine **)(this + 0x34),param_5);
            iVar4 = GetTextWidth(this,param_1,*(String **)(*(int *)(pAVar2 + 4) + uVar5 * 4));
            param_3 = param_3 + iVar4;
          }
          else {
            this_00 = *(String **)(*(int *)(pAVar2 + 4) + uVar5 * 4);
            if (*(int *)(this_00 + 4) == 0) {
              SetColor((uint)this);
            }
            else {
              local_60 = 0;
              __s = (char *)String::GetAEChar(this_00);
              sscanf(__s,"%x",&local_60);
              SetColor((uint)this);
            }
          }
          uVar5 = uVar5 + 1;
          bVar1 = (bool)(bVar1 ^ 1);
        } while (uVar5 < *(uint *)pAVar2);
      }
      SetColor((uint)this);
      ArrayReleaseClasses<AbyssEngine::String*>(pAVar2);
      if (*(void **)(pAVar2 + 4) != (void *)0x0) {
        operator_delete__(*(void **)(pAVar2 + 4));
      }
      operator_delete(pAVar2);
    }
    String::~String(aSStack_54);
  }
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::GetColor  @0x000821b8  (82 bytes)
/* AbyssEngine::PaintCanvas::GetColor() */

int __thiscall AbyssEngine::PaintCanvas::GetColor(PaintCanvas *this)

{
  return (int)(*(float *)(this + 0x200) * 255.0) * 0x10000 +
         (int)(*(float *)(this + 0x1fc) * 255.0) * 0x1000000 +
         (int)(*(float *)(this + 0x204) * 255.0) * 0x100 + (int)(*(float *)(this + 0x208) * 255.0);
}

// ===== AbyssEngine::PaintCanvas::GetTextWidth  @0x00082210  (48 bytes)
/* AbyssEngine::PaintCanvas::GetTextWidth(unsigned int, AbyssEngine::String const&) */

void __thiscall
AbyssEngine::PaintCanvas::GetTextWidth(PaintCanvas *this,uint param_1,String *param_2)

{
  ushort *puVar1;
  ImageFont *pIVar2;
  
  if (*(uint *)(this + 0x140) <= param_1) {
    return;
  }
  pIVar2 = *(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4);
  puVar1 = String::operator_cast_to_unsigned_short_((String *)param_2);
  ImageFontGetWidth(pIVar2,puVar1,*(uint *)(param_2 + 4));
  return;
}

// ===== AbyssEngine::PaintCanvas::SetColor  @0x00082240  (128 bytes)
/* AbyssEngine::PaintCanvas::SetColor(unsigned int) */

void AbyssEngine::PaintCanvas::SetColor(uint param_1)

{
  uint in_r1;
  uint in_fpscr;
  float in_s1;
  float in_s3;
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)VectorUnsignedToFloat(in_r1 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
  dVar2 = (double)VectorUnsignedToFloat((in_r1 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  dVar3 = (double)VectorUnsignedToFloat((in_r1 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
  dVar4 = (double)VectorUnsignedToFloat(in_r1 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(param_1 + 0x1fc) = (float)(dVar1 / 255.0);
  *(float *)(param_1 + 0x200) = (float)(dVar2 / 255.0);
  *(float *)(param_1 + 0x204) = (float)(dVar3 / 255.0);
  *(float *)(param_1 + 0x208) = (float)(dVar4 / 255.0);
  Engine::SetColor(*(Engine **)(param_1 + 0x34),(float)(dVar1 / 255.0),in_s1,(float)(dVar2 / 255.0),
                   in_s3);
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawRegion2D  @0x00082310  (728 bytes)
/* AbyssEngine::PaintCanvas::DrawRegion2D(unsigned int, int, int, int, int, float, int, int, int,
   int) */

void __thiscall
AbyssEngine::PaintCanvas::DrawRegion2D
          (PaintCanvas *this,uint param_1,int param_2,int param_3,int param_4,int param_5,
          float param_6,int param_7,int param_8,int param_9,int param_10)

{
  uint uVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  undefined2 *puVar5;
  int *piVar6;
  uint in_fpscr;
  float fVar7;
  float extraout_s0;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int in_stack_00000018;
  AEMath aAStack_16c [60];
  undefined4 local_130 [5];
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8;
  undefined4 local_f0;
  uint local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  uint local_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined8 local_c4;
  undefined8 uStack_bc;
  undefined4 local_b0 [3];
  float local_a4;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 local_70 [3];
  undefined4 local_64;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x14c)) {
    Engine::SetTextures(*(Engine **)(this + 0x34),
                        *(uint *)(*(int *)(*(int *)(this + 0x150) + param_1 * 4) + 4),0xffffffff);
    piVar6 = *(int **)(*(int *)(this + 0x150) + param_1 * 4);
    uStack_114 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_110 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_10c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    iVar4 = *piVar6;
    fVar7 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined1 *)(piVar6 + 5) = 1;
    puVar2 = *(undefined4 **)(iVar4 + 4);
    fVar8 = (float)VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x16) & 3);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = fVar7;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = fVar7;
    puVar2[7] = fVar8;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = fVar8;
    puVar2[0xb] = 0;
    fVar9 = (float)VectorUnsignedToFloat(piVar6[3] & 0xffff,(byte)(in_fpscr >> 0x16) & 3);
    fVar10 = (float)VectorUnsignedToFloat((uint)piVar6[3] >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
    fVar12 = (float)VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
    fVar13 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar14 = (float)VectorSignedToFloat((int)(short)param_2,(byte)(in_fpscr >> 0x16) & 3);
    pfVar3 = *(float **)(iVar4 + 8);
    fVar11 = fVar12 + fVar10;
    fVar13 = fVar13 + fVar9;
    fVar14 = fVar14 + fVar7 + fVar9;
    fVar12 = fVar12 + fVar8 + fVar10;
    *pfVar3 = fVar13;
    pfVar3[1] = fVar11;
    pfVar3[2] = fVar14;
    pfVar3[3] = fVar11;
    pfVar3[4] = fVar14;
    pfVar3[5] = fVar12;
    pfVar3[6] = fVar13;
    pfVar3[7] = fVar12;
    fVar7 = (float)VectorUnsignedToFloat(piVar6[2] & 0xffff,(byte)(in_fpscr >> 0x16) & 3);
    fVar8 = (float)VectorUnsignedToFloat((uint)piVar6[2] >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
    fVar13 = fVar13 * (1.0 / fVar7);
    fVar11 = (1.0 / fVar8) * fVar11;
    fVar14 = (1.0 / fVar7) * fVar14;
    fVar12 = (1.0 / fVar8) * fVar12;
    *pfVar3 = fVar13;
    pfVar3[1] = fVar11;
    pfVar3[2] = fVar14;
    pfVar3[3] = fVar11;
    pfVar3[4] = fVar14;
    pfVar3[5] = fVar12;
    pfVar3[6] = fVar13;
    pfVar3[7] = fVar12;
    puVar5 = *(undefined2 **)(iVar4 + 0x2c);
    *puVar5 = 0;
    puVar5[1] = 2;
    puVar5[2] = 1;
    puVar5[3] = 0;
    puVar5[4] = 3;
    puVar5[5] = 2;
    puVar2 = (undefined4 *)((uint)local_70 | 4);
    local_70[0] = 0x3f800000;
    local_b0[0] = 0x3f800000;
    *puVar2 = 0;
    puVar2[1] = uStack_114;
    puVar2[2] = uStack_110;
    puVar2[3] = uStack_10c;
    local_5c = 0x3f800000;
    local_58 = 0;
    local_48 = 0x3f800000;
    uStack_40 = 0x3f8000003f800000;
    puVar2 = (undefined4 *)((uint)local_b0 | 4);
    *puVar2 = 0;
    puVar2[1] = uStack_114;
    puVar2[2] = uStack_110;
    puVar2[3] = uStack_10c;
    local_e4 = 0;
    local_e8 = 0;
    local_9c = 0x3f800000;
    local_98 = 0;
    local_88 = 0x3f800000;
    uStack_80 = 0x3f8000003f800000;
    local_38 = 0x3f800000;
    local_78 = 0x3f800000;
    uStack_94 = VectorSignedToFloat(in_stack_00000018 + param_9,(byte)(in_fpscr >> 0x16) & 3);
    local_d8 = 0;
    puVar2 = (undefined4 *)((uint)local_130 | 4);
    local_c4 = 0x3f80000000000000;
    uStack_bc = 0x3f8000003f800000;
    local_a4 = (float)VectorSignedToFloat(param_10 + param_8,(byte)(in_fpscr >> 0x16) & 3);
    local_130[0] = 0x3f800000;
    *puVar2 = 0;
    puVar2[1] = uStack_114;
    puVar2[2] = uStack_110;
    puVar2[3] = uStack_10c;
    local_64 = VectorSignedToFloat(-param_8,(byte)(in_fpscr >> 0x16) & 3);
    uStack_54 = VectorSignedToFloat(-param_9,(byte)(in_fpscr >> 0x16) & 3);
    local_11c = 0x3f800000;
    local_118 = 0;
    local_108 = 0x3f800000;
    uStack_100 = 0x3f8000003f800000;
    local_f8 = 0x3f800000;
    uStack_d4 = uStack_114;
    uStack_d0 = uStack_110;
    uStack_cc = uStack_10c;
    uStack_90 = uStack_110;
    uStack_8c = uStack_10c;
    uStack_50 = uStack_110;
    uStack_4c = uStack_10c;
    uVar1 = AEMath::Sinf(local_a4);
    local_f0 = AEMath::Cosf(extraout_s0);
    local_ec = uVar1 ^ 0x80000000;
    local_c8 = 0x3f800000;
    local_e0 = uVar1;
    uStack_dc = local_f0;
    AEMath::operator*(aAStack_16c,(Matrix *)&local_f0,(Matrix *)local_70);
    AEMath::Matrix::operator=((Matrix *)local_130,aAStack_16c);
    AEMath::operator*(aAStack_16c,(Matrix *)local_b0,(Matrix *)local_130);
    AEMath::Matrix::operator=((Matrix *)local_130,aAStack_16c);
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_130);
    glDisable(0xb44);
    MeshDraw(*(Engine **)(this + 0x34),
             (Mesh *)**(undefined4 **)(*(int *)(this + 0x150) + param_1 * 4));
    param_6 = (float)glEnable(0xb44);
  }
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_6);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SetWorldViewMatrix  @0x00082620  (8 bytes)
/* AbyssEngine::PaintCanvas::SetWorldViewMatrix(AbyssEngine::AEMath::Matrix const&) */

void AbyssEngine::PaintCanvas::SetWorldViewMatrix(Matrix *param_1)

{
  Matrix *in_r1;
  
  Engine::SetWorldViewMatrix(*(Engine **)(param_1 + 0x34),in_r1);
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawRegion2D  @0x00082630  (542 bytes)
/* AbyssEngine::PaintCanvas::DrawRegion2D(unsigned int, float, int, int, int, int, float, float) */

void __thiscall
AbyssEngine::PaintCanvas::DrawRegion2D
          (PaintCanvas *this,uint param_1,float param_2,int param_3,int param_4,int param_5,
          int param_6,float param_7,float param_8)

{
  uint uVar1;
  Image2D *pIVar2;
  undefined4 *puVar3;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s0_01;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s2_00;
  float fVar4;
  float fVar5;
  undefined4 in_stack_00000008;
  float in_stack_0000000c;
  float in_stack_00000010;
  AEMath aAStack_1f0 [60];
  AEMath aAStack_1b4 [60];
  undefined4 local_178 [5];
  undefined4 local_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined4 local_140;
  undefined4 local_138 [5];
  undefined4 local_124;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined4 local_100;
  undefined4 local_f8;
  uint local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  uint local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined8 uStack_c4;
  undefined4 local_b8 [3];
  float local_ac;
  undefined4 local_a4;
  undefined4 local_a0;
  float fStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  undefined4 local_78 [3];
  float local_6c;
  undefined4 local_64;
  undefined4 local_60;
  float fStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x14c)) {
    pIVar2 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    if ((PaintCanvas *)(uint)(byte)pIVar2[0x14] != (PaintCanvas *)0x0) {
      RestoreImage2D((PaintCanvas *)(uint)(byte)pIVar2[0x14],pIVar2);
      pIVar2 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    }
    Engine::SetTextures(*(Engine **)(this + 0x34),*(uint *)(pIVar2 + 4),0xffffffff);
    uStack_15c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_158 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_154 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar3 = (undefined4 *)((uint)local_78 | 4);
    local_ac = (float)VectorSignedToFloat(param_6,(byte)(in_fpscr >> 0x16) & 3);
    fStack_9c = (float)VectorSignedToFloat(in_stack_00000008,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (float)VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x16) & 3);
    fVar5 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
    local_78[0] = 0x3f800000;
    *puVar3 = 0;
    puVar3[1] = uStack_15c;
    puVar3[2] = uStack_158;
    puVar3[3] = uStack_154;
    local_64 = 0x3f800000;
    local_60 = 0;
    local_50 = 0x3f800000;
    uStack_48 = 0x3f8000003f800000;
    puVar3 = (undefined4 *)((uint)local_b8 | 4);
    local_b8[0] = 0x3f800000;
    *puVar3 = 0;
    puVar3[1] = uStack_15c;
    puVar3[2] = uStack_158;
    puVar3[3] = uStack_154;
    local_a4 = 0x3f800000;
    local_a0 = 0;
    local_90 = 0x3f800000;
    uStack_88 = 0x3f8000003f800000;
    local_ac = local_ac + fVar5 * in_stack_0000000c;
    local_ec = 0;
    local_f0 = 0;
    fStack_9c = fStack_9c + fVar4 * in_stack_00000010;
    local_e0 = 0;
    puVar3 = (undefined4 *)((uint)local_138 | 4);
    local_40 = 0x3f800000;
    local_80 = 0x3f800000;
    local_6c = (float)VectorSignedToFloat(-param_4,(byte)(in_fpscr >> 0x16) & 3);
    fStack_5c = (float)VectorSignedToFloat(-param_5,(byte)(in_fpscr >> 0x16) & 3);
    local_cc = 0x3f80000000000000;
    uStack_c4 = 0x3f8000003f800000;
    local_138[0] = 0x3f800000;
    *puVar3 = 0;
    puVar3[1] = uStack_15c;
    puVar3[2] = uStack_158;
    puVar3[3] = uStack_154;
    local_124 = 0x3f800000;
    local_120 = 0;
    local_6c = local_6c * in_stack_0000000c;
    fStack_5c = fStack_5c * in_stack_00000010;
    local_110 = 0x3f800000;
    uStack_108 = 0x3f8000003f800000;
    puVar3 = (undefined4 *)((uint)local_178 | 4);
    local_178[0] = 0x3f800000;
    *puVar3 = 0;
    puVar3[1] = uStack_15c;
    puVar3[2] = uStack_158;
    puVar3[3] = uStack_154;
    local_164 = 0x3f800000;
    local_160 = 0;
    local_150 = 0x3f800000;
    uStack_148 = 0x3f8000003f800000;
    local_100 = 0x3f800000;
    local_140 = 0x3f800000;
    uStack_11c = uStack_15c;
    uStack_118 = uStack_158;
    uStack_114 = uStack_154;
    uStack_dc = uStack_15c;
    uStack_d8 = uStack_158;
    uStack_d4 = uStack_154;
    uStack_98 = uStack_158;
    uStack_94 = uStack_154;
    uStack_58 = uStack_158;
    uStack_54 = uStack_154;
    uVar1 = AEMath::Sinf(local_ac);
    local_f8 = AEMath::Cosf(extraout_s0);
    local_f4 = uVar1 ^ 0x80000000;
    local_d0 = 0x3f800000;
    local_e8 = uVar1;
    local_e4 = local_f8;
    AEMath::MatrixSetScaling(aAStack_1b4,(Matrix *)local_178,extraout_s0_00,extraout_s1,extraout_s2)
    ;
    AEMath::operator*(aAStack_1b4,(Matrix *)&local_f8,(Matrix *)local_78);
    AEMath::Matrix::operator=((Matrix *)local_138,aAStack_1b4);
    AEMath::operator*(aAStack_1f0,(Matrix *)local_b8,(Matrix *)local_138);
    AEMath::operator*(aAStack_1b4,aAStack_1f0,(Matrix *)local_178);
    AEMath::Matrix::operator=((Matrix *)local_138,aAStack_1b4);
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_138);
    glDisable(0xb44);
    MeshDraw(*(Engine **)(this + 0x34),
             (Mesh *)**(undefined4 **)(*(int *)(this + 0x150) + param_1 * 4));
    glEnable(0xb44);
    param_2 = extraout_s0_01;
    param_7 = extraout_s1_00;
    param_8 = extraout_s2_00;
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2,param_7,param_8);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::RestoreImage2D  @0x00082880  (254 bytes)
/* AbyssEngine::PaintCanvas::RestoreImage2D(AbyssEngine::Image2D*) */

void __thiscall AbyssEngine::PaintCanvas::RestoreImage2D(PaintCanvas *this,Image2D *param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  
  iVar3 = *(int *)param_1;
  puVar2 = *(undefined4 **)(iVar3 + 4);
  param_1[0x14] = (Image2D)0x0;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  fVar4 = (float)VectorUnsignedToFloat
                           (*(uint *)(param_1 + 0x10) & 0xffff,(byte)(in_fpscr >> 0x16) & 3);
  fVar5 = (float)VectorUnsignedToFloat
                           (*(uint *)(param_1 + 0x10) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  puVar2[3] = fVar4;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = fVar4;
  puVar2[7] = fVar5;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = fVar5;
  puVar2[0xb] = 0;
  fVar6 = (float)VectorUnsignedToFloat
                           (*(uint *)(param_1 + 0xc) & 0xffff,(byte)(in_fpscr >> 0x16) & 3);
  fVar7 = (float)VectorUnsignedToFloat
                           (*(uint *)(param_1 + 0xc) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
  pfVar1 = *(float **)(iVar3 + 8);
  fVar4 = fVar4 + fVar6;
  *pfVar1 = fVar6;
  fVar5 = fVar5 + fVar7;
  pfVar1[1] = fVar7;
  pfVar1[2] = fVar4;
  pfVar1[3] = fVar7;
  pfVar1[4] = fVar4;
  pfVar1[5] = fVar5;
  pfVar1[6] = fVar6;
  pfVar1[7] = fVar5;
  dVar8 = (double)VectorUnsignedToFloat
                            (*(uint *)(param_1 + 8) & 0xffff,(byte)(in_fpscr >> 0x16) & 3);
  dVar9 = (double)VectorUnsignedToFloat(*(uint *)(param_1 + 8) >> 0x10,(byte)(in_fpscr >> 0x16) & 3)
  ;
  fVar6 = fVar6 * (float)(1.0 / dVar8);
  fVar7 = fVar7 * (float)(1.0 / dVar9);
  fVar4 = (float)(1.0 / dVar8) * fVar4;
  fVar5 = (float)(1.0 / dVar9) * fVar5;
  *pfVar1 = fVar6;
  pfVar1[1] = fVar7;
  pfVar1[2] = fVar4;
  pfVar1[3] = fVar7;
  pfVar1[4] = fVar4;
  pfVar1[5] = fVar5;
  pfVar1[6] = fVar6;
  pfVar1[7] = fVar5;
  puVar2 = *(undefined4 **)(*(int *)param_1 + 0x2c);
  *puVar2 = 0x20000;
  puVar2[1] = 1;
  puVar2[2] = 0x20003;
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshSet2DMask  @0x0008297e  (46 bytes)
/* AbyssEngine::PaintCanvas::MeshSet2DMask(unsigned int, int, int) */

void AbyssEngine::PaintCanvas::MeshSet2DMask(uint param_1,int param_2,int param_3)

{
  PaintCanvas *this;
  
  if (*(uint *)(param_1 + 0x14c) <= (uint)param_2) {
    return;
  }
  this = *(PaintCanvas **)(param_1 + 0x150);
  if ((*(Image2D **)(this + param_2 * 4))[0x14] != (Image2D)0x0) {
    RestoreImage2D(this,*(Image2D **)(this + param_2 * 4));
    this = *(PaintCanvas **)(param_1 + 0x150);
  }
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(this + param_2 * 4);
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshClear2DMask  @0x000829ac  (6 bytes)
/* AbyssEngine::PaintCanvas::MeshClear2DMask() */

void __thiscall AbyssEngine::PaintCanvas::MeshClear2DMask(PaintCanvas *this)

{
  *(undefined4 *)(this + 0x20) = 0;
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawImage2D  @0x000829c0  (202 bytes)
/* AbyssEngine::PaintCanvas::DrawImage2D(unsigned int, int, int) */

void __thiscall
AbyssEngine::PaintCanvas::DrawImage2D(PaintCanvas *this,uint param_1,int param_2,int param_3)

{
  Image2D *pIVar1;
  undefined4 *puVar2;
  uint in_fpscr;
  undefined4 local_58 [3];
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined4 local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x14c)) {
    pIVar1 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    if ((PaintCanvas *)(uint)(byte)pIVar1[0x14] != (PaintCanvas *)0x0) {
      RestoreImage2D((PaintCanvas *)(uint)(byte)pIVar1[0x14],pIVar1);
      pIVar1 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    }
    Engine::SetTextures(*(Engine **)(this + 0x34),*(uint *)(pIVar1 + 4),0xffffffff);
    uStack_3c = VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
    uStack_38 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar2 = (undefined4 *)((uint)local_58 | 4);
    local_4c = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    *puVar2 = 0;
    puVar2[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    puVar2[2] = uStack_38;
    puVar2[3] = uStack_34;
    local_40 = 0;
    local_20 = 0x3f800000;
    local_58[0] = 0x3f800000;
    local_44 = 0x3f800000;
    uStack_30 = 0x3f800000;
    uStack_28 = 0x3f8000003f800000;
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_58);
    glDisable(0xb44);
    MeshDraw(*(Engine **)(this + 0x34),
             (Mesh *)**(undefined4 **)(*(int *)(this + 0x150) + param_1 * 4));
    glEnable(0xb44);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawImage2D  @0x00082ab0  (318 bytes)
/* AbyssEngine::PaintCanvas::DrawImage2D(unsigned int, int, int, unsigned char) */

void __thiscall
AbyssEngine::PaintCanvas::DrawImage2D
          (PaintCanvas *this,uint param_1,int param_2,int param_3,uchar param_4)

{
  Image2D *pIVar1;
  undefined4 *puVar2;
  uint in_fpscr;
  float fVar3;
  undefined4 local_60 [3];
  float local_54;
  undefined4 local_4c;
  undefined4 local_48;
  float fStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x14c)) {
    pIVar1 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    if ((PaintCanvas *)(uint)(byte)pIVar1[0x14] != (PaintCanvas *)0x0) {
      RestoreImage2D((PaintCanvas *)(uint)(byte)pIVar1[0x14],pIVar1);
      pIVar1 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    }
    Engine::SetTextures(*(Engine **)(this + 0x34),*(uint *)(pIVar1 + 4),0xffffffff);
    fStack_44 = (float)VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
    local_54 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    puVar2 = (undefined4 *)((uint)local_60 | 4);
    uStack_40 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    *puVar2 = 0;
    puVar2[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    puVar2[2] = uStack_40;
    puVar2[3] = uStack_3c;
    local_48 = 0;
    local_28 = 0x3f800000;
    local_60[0] = 0x3f800000;
    local_4c = 0x3f800000;
    local_38 = 0x3f800000;
    uStack_30 = 0x3f8000003f800000;
    if ((param_4 & 1) != 0) {
      local_60[0] = 0xbf800000;
      if (param_1 < *(uint *)(this + 0x14c)) {
        fVar3 = (float)VectorUnsignedToFloat
                                 ((uint)*(ushort *)
                                         (*(int *)(*(int *)(this + 0x150) + param_1 * 4) + 0x10),
                                  (byte)(in_fpscr >> 0x16) & 3);
      }
      else {
        fVar3 = 0.0;
      }
      local_54 = fVar3 + local_54;
    }
    if ((param_4 & 2) != 0) {
      local_4c = 0xbf800000;
      if (param_1 < *(uint *)(this + 0x14c)) {
        fVar3 = (float)VectorUnsignedToFloat
                                 ((uint)*(ushort *)
                                         (*(int *)(*(int *)(this + 0x150) + param_1 * 4) + 0x12),
                                  (byte)(in_fpscr >> 0x16) & 3);
      }
      else {
        fVar3 = 0.0;
      }
      fStack_44 = fVar3 + fStack_44;
    }
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_60);
    glDisable(0xb44);
    MeshDraw(*(Engine **)(this + 0x34),
             (Mesh *)**(undefined4 **)(*(int *)(this + 0x150) + param_1 * 4));
    glEnable(0xb44);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::GetImage2DWidth  @0x00082c10  (22 bytes)
/* AbyssEngine::PaintCanvas::GetImage2DWidth(unsigned int) */

undefined2 __thiscall AbyssEngine::PaintCanvas::GetImage2DWidth(PaintCanvas *this,uint param_1)

{
  undefined2 uVar1;
  
  if (param_1 < *(uint *)(this + 0x14c)) {
    uVar1 = *(undefined2 *)(*(int *)(*(int *)(this + 0x150) + param_1 * 4) + 0x10);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== AbyssEngine::PaintCanvas::GetImage2DHeight  @0x00082c26  (22 bytes)
/* AbyssEngine::PaintCanvas::GetImage2DHeight(unsigned int) */

undefined2 __thiscall AbyssEngine::PaintCanvas::GetImage2DHeight(PaintCanvas *this,uint param_1)

{
  undefined2 uVar1;
  
  if (param_1 < *(uint *)(this + 0x14c)) {
    uVar1 = *(undefined2 *)(*(int *)(*(int *)(this + 0x150) + param_1 * 4) + 0x12);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== AbyssEngine::PaintCanvas::DrawImage2D  @0x00082c40  (466 bytes)
/* AbyssEngine::PaintCanvas::DrawImage2D(unsigned int, int, int, unsigned char, unsigned char) */

void __thiscall
AbyssEngine::PaintCanvas::DrawImage2D
          (PaintCanvas *this,uint param_1,int param_2,int param_3,uchar param_4,uchar param_5)

{
  PaintCanvas *this_00;
  int iVar1;
  Image2D *pIVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint in_fpscr;
  double dVar7;
  int local_6c;
  undefined4 local_68 [3];
  undefined4 local_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x14c)) {
    pIVar2 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    this_00 = (PaintCanvas *)(uint)(byte)pIVar2[0x14];
    if (this_00 != (PaintCanvas *)0x0) {
      RestoreImage2D(this_00,pIVar2);
    }
    if ((param_4 & 7) == 4) {
      iVar1 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
      iVar1 = iVar1 >> 1;
    }
    else if ((param_4 & 7) == 2) {
      iVar1 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
      param_2 = -param_2;
    }
    else {
      iVar1 = 0;
    }
    if ((param_4 & 0x70) == 0x40) {
      local_6c = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      local_6c = local_6c >> 1;
    }
    else if ((param_4 & 0x70) == 0x20) {
      local_6c = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      param_3 = -param_3;
    }
    else {
      local_6c = 0;
    }
    if ((param_5 & 7) == 4) {
      dVar7 = (double)VectorSignedToFloat((int)*(float *)(*(int *)(**(int **)(*(int *)(this + 0x150)
                                                                             + param_1 * 4) + 4) +
                                                         0xc),(byte)(in_fpscr >> 0x16) & 3);
      iVar6 = (int)(longlong)(dVar7 * -0.5);
    }
    else if ((param_5 & 7) == 2) {
      iVar6 = -(int)*(float *)(*(int *)(**(int **)(*(int *)(this + 0x150) + param_1 * 4) + 4) + 0xc)
      ;
    }
    else {
      iVar6 = 0;
    }
    if ((param_5 & 0x70) == 0x20) {
      piVar3 = *(int **)(*(int *)(this + 0x150) + param_1 * 4);
      iVar4 = -(int)*(float *)(*(int *)(*piVar3 + 4) + 0x1c);
    }
    else if ((param_5 & 0x70) == 0x40) {
      piVar3 = *(int **)(*(int *)(this + 0x150) + param_1 * 4);
      dVar7 = (double)VectorSignedToFloat((int)*(float *)(*(int *)(*piVar3 + 4) + 0x1c),
                                          (byte)(in_fpscr >> 0x16) & 3);
      iVar4 = (int)(longlong)(dVar7 * -0.5);
    }
    else {
      iVar4 = 0;
      piVar3 = *(int **)(*(int *)(this + 0x150) + param_1 * 4);
    }
    Engine::SetTextures(*(Engine **)(this + 0x34),piVar3[1],0xffffffff);
    puVar5 = (undefined4 *)((uint)local_68 | 4);
    uStack_48 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    uStack_4c = VectorSignedToFloat(local_6c + param_3 + iVar4,(byte)(in_fpscr >> 0x16) & 3);
    local_5c = VectorSignedToFloat(iVar1 + param_2 + iVar6,(byte)(in_fpscr >> 0x16) & 3);
    *puVar5 = 0;
    puVar5[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    puVar5[2] = uStack_48;
    puVar5[3] = uStack_44;
    local_50 = 0;
    local_30 = 0x3f800000;
    local_68[0] = 0x3f800000;
    local_54 = 0x3f800000;
    local_40 = 0x3f800000;
    uStack_38 = 0x3f8000003f800000;
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_68);
    MeshDraw(*(Engine **)(this + 0x34),
             (Mesh *)**(undefined4 **)(*(int *)(this + 0x150) + param_1 * 4));
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::GetWidth  @0x00082e40  (8 bytes)
/* AbyssEngine::PaintCanvas::GetWidth() */

void AbyssEngine::PaintCanvas::GetWidth(void)

{
  int in_r0;
  
  Engine::GetDisplayWidth(*(Engine **)(in_r0 + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::GetHeight  @0x00082e46  (8 bytes)
/* AbyssEngine::PaintCanvas::GetHeight() */

void AbyssEngine::PaintCanvas::GetHeight(void)

{
  int in_r0;
  
  Engine::GetDisplayHeight(*(Engine **)(in_r0 + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawImage2D  @0x00082e50  (738 bytes)
/* AbyssEngine::PaintCanvas::DrawImage2D(unsigned int, int, int, int, int, unsigned char, unsigned
   char, unsigned char) */

void __thiscall
AbyssEngine::PaintCanvas::DrawImage2D
          (PaintCanvas *this,uint param_1,int param_2,int param_3,int param_4,int param_5,
          uchar param_6,uchar param_7,uchar param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Image2D *pIVar5;
  undefined4 *puVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  int local_80;
  int local_7c;
  float local_78 [3];
  float local_6c;
  float local_64;
  undefined4 local_60;
  float fStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x14c)) {
    pIVar5 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    if ((PaintCanvas *)(uint)(byte)pIVar5[0x14] != (PaintCanvas *)0x0) {
      RestoreImage2D((PaintCanvas *)(uint)(byte)pIVar5[0x14],pIVar5);
      pIVar5 = *(Image2D **)(*(int *)(this + 0x150) + param_1 * 4);
    }
    Engine::SetTextures(*(Engine **)(this + 0x34),*(uint *)(pIVar5 + 4),0xffffffff);
    local_80 = param_2;
    if ((param_6 & 7) == 4) {
      local_7c = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
      local_7c = local_7c >> 1;
    }
    else if ((param_6 & 7) == 2) {
      local_80 = -param_2;
      local_7c = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
    }
    else {
      local_7c = 0;
    }
    if ((param_6 & 8) == 0) {
      fVar7 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
      iVar1 = *(int *)(**(int **)(*(int *)(this + 0x150) + param_1 * 4) + 4);
    }
    else {
      iVar1 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
      fVar7 = (float)VectorSignedToFloat(iVar1 - (param_4 + param_2),(byte)(in_fpscr >> 0x16) & 3);
      iVar1 = *(int *)(**(int **)(*(int *)(this + 0x150) + param_1 * 4) + 4);
    }
    fVar7 = fVar7 / *(float *)(iVar1 + 0xc);
    if ((param_6 & 0x80) == 0) {
      fVar8 = (float)VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x16) & 3);
    }
    else {
      iVar1 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      fVar8 = (float)VectorSignedToFloat(iVar1 - (param_5 + param_3),(byte)(in_fpscr >> 0x16) & 3);
      iVar1 = *(int *)(**(int **)(*(int *)(this + 0x150) + param_1 * 4) + 4);
    }
    fVar8 = fVar8 / *(float *)(iVar1 + 0x1c);
    iVar1 = param_3;
    if ((param_6 & 0x70) == 0x40) {
      iVar2 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      iVar2 = iVar2 >> 1;
    }
    else if ((param_6 & 0x70) == 0x20) {
      iVar2 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      iVar1 = -param_3;
    }
    else {
      iVar2 = 0;
    }
    if ((param_7 & 7) == 4) {
      if ((param_6 & 8) == 0) {
        iVar3 = -(param_4 >> 1);
      }
      else {
        iVar3 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
        iVar3 = (param_4 + param_2) - iVar3 >> 1;
      }
    }
    else if ((param_7 & 7) == 2) {
      if ((param_6 & 8) == 0) {
        iVar3 = -param_4;
      }
      else {
        iVar3 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
        iVar3 = (param_4 + param_2) - iVar3;
      }
    }
    else {
      iVar3 = 0;
    }
    if ((param_7 & 0x70) == 0x40) {
      if ((param_6 & 0x80) == 0) {
        iVar4 = -(param_5 >> 1);
      }
      else {
        iVar4 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
        iVar4 = (param_5 + param_3) - iVar4 >> 1;
      }
    }
    else if ((param_7 & 0x70) == 0x20) {
      if ((param_6 & 0x80) == 0) {
        iVar4 = -param_5;
      }
      else {
        iVar4 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
        iVar4 = (param_5 + param_3) - iVar4;
      }
    }
    else {
      iVar4 = 0;
    }
    uStack_58 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_54 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar6 = (undefined4 *)((uint)local_78 | 4);
    *puVar6 = 0;
    puVar6[1] = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    puVar6[2] = uStack_58;
    puVar6[3] = uStack_54;
    fStack_5c = (float)VectorSignedToFloat(iVar4 + iVar2 + iVar1,(byte)(in_fpscr >> 0x16) & 3);
    local_6c = (float)VectorSignedToFloat(local_7c + local_80 + iVar3,(byte)(in_fpscr >> 0x16) & 3);
    local_60 = 0;
    local_40 = 0x3f800000;
    local_50 = 0x3f800000;
    uStack_48 = 0x3f8000003f800000;
    local_78[0] = fVar7;
    if ((param_8 & 1) != 0) {
      local_78[0] = -fVar7;
      fVar7 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
      local_6c = fVar7 + local_6c;
    }
    local_64 = fVar8;
    if ((param_8 & 2) != 0) {
      local_64 = -fVar8;
      fVar7 = (float)VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x16) & 3);
      fStack_5c = fVar7 + fStack_5c;
    }
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_78);
    glDisable(0xb44);
    MeshDraw(*(Engine **)(this + 0x34),
             (Mesh *)**(undefined4 **)(*(int *)(this + 0x150) + param_1 * 4));
    glEnable(0xb44);
  }
  if (__stack_chk_guard == local_3c) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::DrawFrameBufferTexture  @0x00083160  (2 bytes)
/* AbyssEngine::PaintCanvas::DrawFrameBufferTexture(int, int, int, int, int, int) */

int AbyssEngine::PaintCanvas::DrawFrameBufferTexture
              (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  return param_1;
}

// ===== AbyssEngine::PaintCanvas::FillRectangle  @0x00083170  (206 bytes)
/* AbyssEngine::PaintCanvas::FillRectangle(int, int, int, int) */

void __thiscall
AbyssEngine::PaintCanvas::FillRectangle
          (PaintCanvas *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint in_fpscr;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_50 [5];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  int local_14;
  
  uVar3 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_14 = __stack_chk_guard;
  uVar4 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  uVar5 = VectorSignedToFloat(param_1 + param_3,(byte)(in_fpscr >> 0x16) & 3);
  puVar2 = (undefined4 *)((uint)local_50 | 4);
  puVar1 = *(undefined4 **)(*(int *)(this + 0x1c8) + 4);
  uVar6 = VectorSignedToFloat(param_4 + param_2,(byte)(in_fpscr >> 0x16) & 3);
  *puVar1 = uVar4;
  puVar1[1] = uVar3;
  puVar1[3] = uVar5;
  puVar1[4] = uVar3;
  puVar1[6] = uVar5;
  puVar1[7] = uVar6;
  puVar1[9] = uVar4;
  puVar1[10] = uVar6;
  local_50[0] = 0x3f800000;
  *puVar2 = 0;
  puVar2[1] = uStack_34;
  puVar2[2] = uStack_30;
  puVar2[3] = uStack_2c;
  local_3c = 0x3f800000;
  local_38 = 0;
  local_28 = 0x3f800000;
  uStack_20 = 0x3f8000003f800000;
  local_18 = 0x3f800000;
  Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_50);
  Engine::GlEnable(*(Engine **)(this + 0x34),0xde1,false);
  MeshDraw(*(Engine **)(this + 0x34),*(Mesh **)(this + 0x1c8));
  Engine::GlEnable(*(Engine **)(this + 0x34),0xde1,true);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawRectangle  @0x00083260  (336 bytes)
/* AbyssEngine::PaintCanvas::DrawRectangle(int, int, int, int) */

void __thiscall
AbyssEngine::PaintCanvas::DrawRectangle
          (PaintCanvas *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined4 local_50 [5];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  int local_14;
  
  dVar4 = (double)VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
  dVar5 = (double)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
  dVar6 = (double)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  dVar7 = (double)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  local_14 = __stack_chk_guard;
  fVar2 = (float)(dVar6 + dVar4 + -0.5);
  fVar3 = (float)(dVar7 + dVar5 + -0.5);
  uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar1 = (undefined4 *)((uint)local_50 | 4);
  *(float *)(this + 0x1d0) = (float)(dVar6 + 0.5);
  *(float *)(this + 0x1d4) = (float)(dVar7 + 0.5);
  *(float *)(this + 0x1d8) = fVar2;
  *(float *)(this + 0x1dc) = (float)(dVar7 + 0.5);
  *(float *)(this + 0x1e0) = fVar2;
  *(float *)(this + 0x1e4) = fVar3;
  *(float *)(this + 0x1e8) = (float)(dVar6 + 0.5);
  *(float *)(this + 0x1ec) = fVar3;
  local_50[0] = 0x3f800000;
  *puVar1 = 0;
  puVar1[1] = uStack_34;
  puVar1[2] = uStack_30;
  puVar1[3] = uStack_2c;
  local_3c = 0x3f800000;
  local_38 = 0;
  local_28 = 0x3f800000;
  uStack_20 = 0x3f8000003f800000;
  local_18 = 0x3f800000;
  Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_50);
  if (Engine::enableShader == '\0') {
    glLineWidth(0x3f800000);
    Engine::GlEnable(*(Engine **)(this + 0x34),0xde1,false);
    glVertexPointer(2,0x1406,0,this + 0x1d0);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8074,true);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8078,false);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8075,false);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8076,false);
    glDrawArrays(2,0,4);
    Engine::GlEnable(*(Engine **)(this + 0x34),0xde1,true);
  }
  else {
    Engine::DrawLine2D(*(Engine **)(this + 0x34),(float *)(this + 0x1d0),4,true);
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawLine  @0x000833d0  (404 bytes)
/* AbyssEngine::PaintCanvas::DrawLine(int, int, int, int) */

void __thiscall
AbyssEngine::PaintCanvas::DrawLine
          (PaintCanvas *this,int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  uint in_fpscr;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_60 [5];
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (Engine::enableShader == '\0') {
    glLineWidth(0x3f800000);
    Engine::GlEnable(*(Engine **)(this + 0x34),0xde1,false);
    uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_40 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    uVar3 = VectorSignedToFloat(param_1 + 1,(byte)(in_fpscr >> 0x16) & 3);
    uVar2 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    puVar1 = (undefined4 *)((uint)local_60 | 4);
    uVar4 = VectorSignedToFloat(param_3 + 1,(byte)(in_fpscr >> 0x16) & 3);
    uVar5 = VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)(this + 0x1d0) = uVar3;
    *(undefined4 *)(this + 0x1d4) = uVar2;
    *(undefined4 *)(this + 0x1d8) = uVar4;
    *(undefined4 *)(this + 0x1dc) = uVar5;
    local_60[0] = 0x3f800000;
    *puVar1 = 0;
    puVar1[1] = uStack_44;
    puVar1[2] = uStack_40;
    puVar1[3] = uStack_3c;
    local_4c = 0x3f800000;
    local_48 = 0;
    local_38 = 0x3f800000;
    uStack_30 = 0x3f8000003f800000;
    local_28 = 0x3f800000;
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_60);
    glVertexPointer(2,0x1406,0,this + 0x1d0);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8074,true);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8078,false);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8075,false);
    Engine::AEClientState(*(Engine **)(this + 0x34),0x8076,false);
    glDrawArrays(1,0,2);
    Engine::GlEnable(*(Engine **)(this + 0x34),0xde1,true);
  }
  else {
    uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_40 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar1 = (undefined4 *)((uint)local_60 | 4);
    local_60[0] = 0x3f800000;
    *puVar1 = 0;
    puVar1[1] = uStack_44;
    puVar1[2] = uStack_40;
    puVar1[3] = uStack_3c;
    local_4c = 0x3f800000;
    local_48 = 0;
    local_38 = 0x3f800000;
    uStack_30 = 0x3f8000003f800000;
    local_28 = 0x3f800000;
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_60);
    uVar3 = VectorSignedToFloat(param_1 + 1,(byte)(in_fpscr >> 0x16) & 3);
    uVar2 = VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    uVar4 = VectorSignedToFloat(param_3 + 1,(byte)(in_fpscr >> 0x16) & 3);
    uVar5 = VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)(this + 0x1d0) = uVar3;
    *(undefined4 *)(this + 0x1d4) = uVar2;
    *(undefined4 *)(this + 0x1d8) = uVar4;
    *(undefined4 *)(this + 0x1dc) = uVar5;
    Engine::DrawLine2D(*(Engine **)(this + 0x34),(float *)(this + 0x1d0),2,false);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawMesh  @0x00083590  (22 bytes)
/* AbyssEngine::PaintCanvas::DrawMesh(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::DrawMesh(PaintCanvas *this,uint param_1)

{
  if (param_1 < *(uint *)(this + 0x24)) {
    MeshDraw(*(Engine **)(this + 0x34),*(Mesh **)(*(int *)(this + 0x28) + param_1 * 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawTransform  @0x000835b0  (552 bytes)
/* AbyssEngine::PaintCanvas::DrawTransform(unsigned int, AbyssEngine::AEMath::Matrix const*) */

void __thiscall
AbyssEngine::PaintCanvas::DrawTransform(PaintCanvas *this,uint param_1,Matrix *param_2)

{
  int iVar1;
  uint uVar2;
  Transform *pTVar3;
  undefined4 *puVar4;
  AEMath *this_00;
  float extraout_s0;
  float extraout_s0_00;
  float extraout_s1;
  float extraout_s2;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  AEMath aAStack_154 [60];
  undefined4 local_118 [5];
  undefined4 local_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  uint local_d4;
  uint local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined4 local_a0;
  undefined4 local_98 [5];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined4 local_60;
  int local_5c;
  
  local_5c = __stack_chk_guard;
  if ((*(uint *)(this + 0x158) <= param_1) ||
     (iVar1 = *(int *)(this + 0x15c), *(char *)(*(int *)(iVar1 + param_1 * 4) + 0xec) == '\0'))
  goto LAB_000837a6;
  uVar5 = 0;
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  puVar4 = (undefined4 *)((uint)local_98 | 4);
  local_98[0] = 0x3f800000;
  *puVar4 = 0;
  puVar4[1] = uVar6;
  puVar4[2] = uVar7;
  puVar4[3] = uVar8;
  local_84 = 0x3f800000;
  local_80 = 0;
  uStack_70 = 0x3f800000;
  uStack_68 = 0x3f8000003f800000;
  local_60 = 0x3f800000;
  uStack_7c = uVar6;
  uStack_78 = uVar7;
  uStack_74 = uVar8;
  if (*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) {
    if (*this == (PaintCanvas)0x0) {
      iVar1 = Transform::InCameraVF
                        (*(Transform **)(iVar1 + param_1 * 4),(Matrix *)0x0,
                         *(Camera **)(*(int *)(this + 0x168) + *(uint *)(this + 0x170) * 4));
      if (iVar1 == 0) goto LAB_0008371c;
      if (param_2 == (Matrix *)0x0) {
        this_00 = (AEMath *)&local_d8;
        param_2 = (Matrix *)(*(int *)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4) + 0xc);
      }
      else {
        this_00 = (AEMath *)&local_d8;
      }
    }
    else {
      uVar9 = 0;
      uVar10 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar11 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar12 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar4 = (undefined4 *)((uint)&local_d8 | 4);
      local_d8 = 0x3f800000;
      *puVar4 = 0;
      puVar4[1] = uVar10;
      puVar4[2] = uVar11;
      puVar4[3] = uVar12;
      local_c4 = 0x3f800000;
      local_c0 = 0;
      uStack_b0 = 0x3f800000;
      uStack_a8 = 0x3f8000003f800000;
      local_a0 = 0x3f800000;
      uStack_bc = uVar10;
      uStack_b8 = uVar11;
      uStack_b4 = uVar12;
      AEMath::MatrixIdentity((AEMath *)local_118,(Matrix *)&local_d8);
      iVar1 = Engine::GetGravValue(*(Engine **)(this + 0x34));
      uVar2 = AEMath::Sinf((float)(*(double *)(iVar1 + 8) * 1.5707963705062866));
      local_d8 = AEMath::Cosf(extraout_s0);
      local_d4 = uVar2 ^ 0x80000000;
      local_c8 = uVar2;
      local_c4 = local_d8;
      iVar1 = Transform::InCameraVF
                        (*(Transform **)(*(int *)(this + 0x15c) + param_1 * 4),(Matrix *)&local_d8,
                         *(Camera **)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4));
      if (iVar1 == 0) {
LAB_0008371c:
        *(int *)(this + 4) = *(int *)(this + 4) + 1;
        goto LAB_000837a6;
      }
      local_118[0] = 0x3f800000;
      puVar4 = (undefined4 *)((uint)local_118 | 4);
      *puVar4 = uVar9;
      puVar4[1] = uVar10;
      puVar4[2] = uVar11;
      puVar4[3] = uVar12;
      local_104 = 0x3f800000;
      uStack_f0 = 0x3f800000;
      uStack_e8 = 0x3f8000003f800000;
      local_e0 = 0x3f800000;
      if (param_2 == (Matrix *)0x0) {
        param_2 = (Matrix *)(*(int *)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4) + 0xc);
      }
      local_100 = uVar9;
      uStack_fc = uVar10;
      uStack_f8 = uVar11;
      uStack_f4 = uVar12;
      AEMath::Matrix::operator=((Matrix *)local_118,param_2);
      param_2 = (Matrix *)local_118;
      AEMath::Matrix::operator*=((Matrix *)param_2,(Matrix *)&local_d8);
      this_00 = aAStack_154;
    }
    AEMath::MatrixGetInverse(this_00,param_2);
    AEMath::Matrix::operator=((Matrix *)local_98,this_00);
    Engine::SetEyePosition(*(Engine **)(this + 0x34),extraout_s0_00,extraout_s1,extraout_s2);
    iVar1 = *(int *)(this + 0x15c);
  }
  pTVar3 = *(Transform **)(iVar1 + param_1 * 4);
  puVar4 = (undefined4 *)((uint)&local_d8 | 4);
  local_d8 = 0x3f800000;
  *puVar4 = uVar5;
  puVar4[1] = uVar6;
  puVar4[2] = uVar7;
  puVar4[3] = uVar8;
  local_c4 = 0x3f800000;
  uStack_b0 = 0x3f800000;
  uStack_a8 = 0x3f8000003f800000;
  local_a0 = 0x3f800000;
  local_c0 = uVar5;
  uStack_bc = uVar6;
  uStack_b8 = uVar7;
  uStack_b4 = uVar8;
  DrawTransform(this,pTVar3,(Matrix *)&local_d8,(Matrix *)local_98);
LAB_000837a6:
  if (__stack_chk_guard != local_5c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawTransform  @0x00083800  (208 bytes)
/* AbyssEngine::PaintCanvas::DrawTransform(AbyssEngine::Transform*, AbyssEngine::AEMath::Matrix
   const&, AbyssEngine::AEMath::Matrix&) */

void __thiscall
AbyssEngine::PaintCanvas::DrawTransform
          (PaintCanvas *this,Transform *param_1,Matrix *param_2,Matrix *param_3)

{
  int iVar1;
  uint uVar2;
  AEMath aAStack_60 [60];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if ((param_1 != (Transform *)0x0) && (param_1[0xec] != (Transform)0x0)) {
    AEMath::operator*(aAStack_60,param_2,param_1);
    if (*(int *)(param_1 + 0x11c) != 0) {
      AEMath::Matrix::operator*=((Matrix *)aAStack_60,param_1 + 0x5c);
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      uVar2 = 0;
      do {
        DrawMesh((Mesh *)this,*(Matrix **)(*(int *)(param_1 + 0x40) + uVar2 * 4),aAStack_60,
                 (uint)param_3,*(Matrix **)(param_1 + 0x48));
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x3c));
    }
    if (*(int *)(param_1 + 0x4c) != 0) {
      uVar2 = 0;
      do {
        if ((*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) &&
           (iVar1 = Transform::InCameraVF
                              (*(Transform **)(*(int *)(param_1 + 0x50) + uVar2 * 4),aAStack_60,
                               *(Camera **)(*(int *)(this + 0x168) + *(uint *)(this + 0x170) * 4)),
           iVar1 == 1)) {
          DrawTransform(this,*(Transform **)(*(int *)(param_1 + 0x50) + uVar2 * 4),aAStack_60,
                        param_3);
        }
        else {
          *(int *)(this + 4) = *(int *)(this + 4) + 1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x4c));
    }
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TextureCreateGlobal  @0x000838d8  (118 bytes)
/* AbyssEngine::PaintCanvas::TextureCreateGlobal(AbyssEngine::String, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::TextureCreateGlobal(PaintCanvas *this,String *param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  float extraout_s0;
  uint local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  local_20 = 0;
  pcVar1 = (char *)String::GetAEChar(param_2);
  iVar2 = TextureCreateFromFile
                    (*(Engine **)(this + 0x34),pcVar1,(_func_void_Image_ptr_void_ptr *)0x0,
                     (void *)0x0,&local_20,false,extraout_s0);
  if (iVar2 == 1) {
    glActiveTexture(param_3 + 0x84c0);
    glBindTexture(0xde1,local_20);
    glActiveTexture(0x84c0);
  }
  if (pcVar1 != (char *)0x0) {
    operator_delete__(pcVar1);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TextureCreate  @0x00083958  (176 bytes)
/* AbyssEngine::PaintCanvas::TextureCreate(unsigned short, void (*)(AbyssEngine::Image*, void*),
   void*, unsigned int&, bool) */

void __thiscall
AbyssEngine::PaintCanvas::TextureCreate
          (PaintCanvas *this,ushort param_1,_func_void_Image_ptr_void_ptr *param_2,void *param_3,
          uint *param_4,bool param_5)

{
  Engine *pEVar1;
  int iVar2;
  char *pcVar3;
  ushort *puVar4;
  uint uVar5;
  float fVar6;
  undefined3 in_stack_00000005;
  uint local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  pEVar1 = *(Engine **)(this + 0x34);
  *(undefined4 *)(pEVar1 + 0x6c) = 0xffffffff;
  *(undefined4 *)(pEVar1 + 0x70) = 0xffffffff;
  if (*(uint *)(this + 0x134) != 0) {
    uVar5 = 0;
    do {
      puVar4 = *(ushort **)(*(int *)(this + 0x138) + uVar5 * 4);
      if ((puVar4 != (ushort *)0x0) && (*puVar4 == param_1)) {
        if (*(uint *)(puVar4 + 4) == 0xffffffff) {
          local_24 = 0;
          fVar6 = (float)(*(undefined4 **)(puVar4 + 6))[1];
          pcVar3 = (char *)**(undefined4 **)(puVar4 + 6);
          if (_param_5 == 1) {
            iVar2 = TextureCreateFromFile(pEVar1,pcVar3,param_2,param_3,&local_24,true,fVar6);
          }
          else {
            iVar2 = TextureCreateFromFileIntern
                              (pEVar1,pcVar3,param_2,param_3,&local_24,fVar6,
                               (AELoadedTexture *)fVar6,false);
          }
          if (iVar2 == 1) {
            *(uint *)(puVar4 + 4) = local_24;
            *param_4 = local_24;
          }
        }
        else {
          *param_4 = *(uint *)(puVar4 + 4);
        }
        break;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(this + 0x134));
  }
  if (__stack_chk_guard == local_20) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::TextureCreate  @0x00083a10  (20 bytes)
/* AbyssEngine::PaintCanvas::TextureCreate(unsigned short, unsigned int&, bool) */

void __thiscall
AbyssEngine::PaintCanvas::TextureCreate(PaintCanvas *this,ushort param_1,uint *param_2,bool param_3)

{
  TextureCreate(this,param_1,(_func_void_Image_ptr_void_ptr *)0x0,(void *)0x0,param_2,param_3);
  return;
}

// ===== AbyssEngine::PaintCanvas::FontCreate  @0x00083a24  (294 bytes)
/* AbyssEngine::PaintCanvas::FontCreate(unsigned short, unsigned int&, bool) */

void AbyssEngine::PaintCanvas::FontCreate(ushort param_1,uint *param_2,bool param_3)

{
  ushort uVar1;
  PaintCanvas *this;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  ImageFont *pIVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  undefined8 uVar12;
  ImageFont *local_2c;
  uint local_28;
  int local_24;
  
  piVar6 = (int *)(uint)param_3;
  this = (PaintCanvas *)(uint)param_1;
  local_24 = __stack_chk_guard;
  uVar2 = *(uint *)(this + 0x134);
  if (uVar2 != 0) {
    uVar7 = 0;
    do {
      puVar10 = *(ushort **)(*(int *)(this + 0x138) + uVar7 * 4);
      if ((puVar10 != (ushort *)0x0) && ((uint *)(uint)*puVar10 == param_2)) {
        puVar11 = *(ushort **)(puVar10 + 6);
        uVar7 = 0;
        uVar1 = *puVar11;
        goto LAB_00083a66;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar2);
  }
  goto LAB_00083b32;
  while (uVar7 = uVar7 + 1, uVar7 < uVar2) {
LAB_00083a66:
    puVar9 = *(ushort **)(*(int *)(this + 0x138) + uVar7 * 4);
    if ((puVar9 != (ushort *)0x0) && (*puVar9 == uVar1)) {
      if (*(int *)(puVar9 + 4) == -1) {
        local_28 = 0;
        TextureCreate(this,uVar1,(_func_void_Image_ptr_void_ptr *)0x0,(void *)0x0,&local_28,false);
      }
      if (*(int *)(puVar10 + 4) == -1) {
        local_2c = (ImageFont *)0x0;
        iVar3 = ImageCreateFontFromFile
                          (*(Engine **)(this + 0x34),(char *)**(undefined4 **)(puVar9 + 6),
                           puVar11[1],&local_2c);
        pIVar5 = local_2c;
        if (iVar3 == 1) {
          if (*(int *)(puVar9 + 4) != -1) {
            *(int *)(local_2c + 8) = *(int *)(puVar9 + 4);
          }
          *(int *)(this + 0x148) = *(int *)(this + 0x140) + 1;
          pvVar4 = realloc(*(void **)(this + 0x144),(*(int *)(this + 0x140) + 1) * 4);
          *(void **)(this + 0x144) = pvVar4;
          *(ImageFont **)((int)pvVar4 + *(int *)(this + 0x140) * 4) = pIVar5;
          *(int *)(this + 0x140) = *(int *)(this + 0x148);
          iVar3 = *(int *)(this + 0x148) + -1;
          *(int *)(puVar10 + 4) = iVar3;
          *piVar6 = iVar3;
          iVar8 = *(int *)(*(int *)(this + 0x34) + 0x68);
          if (iVar8 == -1) {
            *(int *)(*(int *)(this + 0x34) + 0x68) = iVar3;
          }
          else {
            pIVar5 = *(ImageFont **)((int)pvVar4 + iVar8 * 4);
            if (*(ushort *)pIVar5 <= *(ushort *)local_2c) {
              iVar3 = ImageFontGetHeight(pIVar5);
              uVar12 = ImageFontGetHeight(local_2c);
              iVar8 = (int)uVar12;
              if (iVar8 < iVar3) {
                uVar12 = CONCAT44(*piVar6,*(undefined4 *)(this + 0x34));
              }
              if (iVar8 < iVar3) {
                *(int *)((int)uVar12 + 0x68) = (int)((ulonglong)uVar12 >> 0x20);
              }
            }
          }
        }
      }
      else {
        *piVar6 = *(int *)(puVar10 + 4);
      }
      break;
    }
  }
LAB_00083b32:
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::FontSetSpacing  @0x00083b54  (26 bytes)
/* AbyssEngine::PaintCanvas::FontSetSpacing(unsigned int, short) */

void __thiscall
AbyssEngine::PaintCanvas::FontSetSpacing(PaintCanvas *this,uint param_1,short param_2)

{
  if (param_1 < *(uint *)(this + 0x140)) {
    ImageFontSetSpacing(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4),param_2);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::FontGetSpacing  @0x00083b6c  (30 bytes)
/* AbyssEngine::PaintCanvas::FontGetSpacing(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::FontGetSpacing(PaintCanvas *this,uint param_1)

{
  if (param_1 < *(uint *)(this + 0x140)) {
    ImageFontGetSpacing(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::FontSetYOffset  @0x00083b8a  (26 bytes)
/* AbyssEngine::PaintCanvas::FontSetYOffset(unsigned int, short) */

void __thiscall
AbyssEngine::PaintCanvas::FontSetYOffset(PaintCanvas *this,uint param_1,short param_2)

{
  if (param_1 < *(uint *)(this + 0x140)) {
    ImageFontSetYOffset(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4),param_2);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::FontGetYOffset  @0x00083ba2  (30 bytes)
/* AbyssEngine::PaintCanvas::FontGetYOffset(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::FontGetYOffset(PaintCanvas *this,uint param_1)

{
  if (param_1 < *(uint *)(this + 0x140)) {
    ImageFontGetYOffset(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::Image2DCreate  @0x00083bc0  (254 bytes)
/* AbyssEngine::PaintCanvas::Image2DCreate(unsigned short, unsigned int&) */

void __thiscall
AbyssEngine::PaintCanvas::Image2DCreate(PaintCanvas *this,ushort param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  Image2D *pIVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar2 = *(uint *)(this + 0x134);
  if (uVar2 != 0) {
    uVar6 = 0;
    do {
      puVar8 = *(ushort **)(*(int *)(this + 0x138) + uVar6 * 4);
      if ((puVar8 != (ushort *)0x0) && (*puVar8 == param_1)) {
        puVar9 = *(ushort **)(puVar8 + 6);
        uVar6 = 0;
        uVar1 = *puVar9;
        goto LAB_00083c02;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar2);
  }
  goto LAB_00083ca6;
  while (uVar6 = uVar6 + 1, uVar6 < uVar2) {
LAB_00083c02:
    puVar7 = *(ushort **)(*(int *)(this + 0x138) + uVar6 * 4);
    if ((puVar7 != (ushort *)0x0) && (*puVar7 == uVar1)) {
      if (*(int *)(puVar7 + 4) == -1) {
        local_2c = 0;
        TextureCreate(this,uVar1,(_func_void_Image_ptr_void_ptr *)0x0,(void *)0x0,&local_2c,false);
      }
      uVar2 = *(uint *)(puVar8 + 4);
      if (uVar2 == 0xffffffff) {
        pIVar3 = operator_new(0x18);
        *(undefined4 *)(pIVar3 + 0x11) = 0;
        *(undefined4 *)pIVar3 = 0;
        *(undefined4 *)(pIVar3 + 4) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4)
        ;
        *(undefined4 *)(pIVar3 + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8)
        ;
        *(undefined4 *)(pIVar3 + 0xc) =
             *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        *(undefined4 *)(pIVar3 + 0xd) = 0;
        iVar4 = ImageCreateRegionFromFile
                          (*(Engine **)(this + 0x34),(char *)**(undefined4 **)(puVar7 + 6),puVar9[1]
                           ,pIVar3);
        if (iVar4 != 1) break;
        if (*(int *)(puVar7 + 4) != -1) {
          *(int *)(pIVar3 + 4) = *(int *)(puVar7 + 4);
        }
        *(int *)(this + 0x154) = *(int *)(this + 0x14c) + 1;
        pvVar5 = realloc(*(void **)(this + 0x150),(*(int *)(this + 0x14c) + 1) * 4);
        *(void **)(this + 0x150) = pvVar5;
        *(Image2D **)((int)pvVar5 + *(int *)(this + 0x14c) * 4) = pIVar3;
        *(int *)(this + 0x14c) = *(int *)(this + 0x154);
        uVar2 = *(int *)(this + 0x154) - 1;
        *(uint *)(puVar8 + 4) = uVar2;
      }
      *param_2 = uVar2;
      break;
    }
  }
LAB_00083ca6:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::MeshCreate  @0x00083cc8  (302 bytes)
/* AbyssEngine::PaintCanvas::MeshCreate(unsigned short, unsigned int&, bool) */

void __thiscall
AbyssEngine::PaintCanvas::MeshCreate(PaintCanvas *this,ushort param_1,uint *param_2,bool param_3)

{
  Mesh *pMVar1;
  void *pvVar2;
  Material *pMVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  Mesh *local_2c;
  uint local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (*(uint *)(this + 0x134) != 0) {
    uVar4 = 0;
    do {
      puVar7 = *(ushort **)(*(int *)(this + 0x138) + uVar4 * 4);
      if ((puVar7 != (ushort *)0x0) && (*puVar7 == param_1)) {
        uVar4 = *(uint *)(puVar7 + 4);
        if (uVar4 == 0xffffffff) {
          puVar6 = *(undefined4 **)(puVar7 + 6);
          local_28 = 0xffffffff;
          MaterialCreate(this,*(ushort *)(puVar6 + 1),&local_28);
          local_2c = (Mesh *)0x0;
          if (*(uint *)(this + 0x174) < local_28) {
            pMVar3 = (Material *)0x0;
          }
          else {
            pMVar3 = *(Material **)(*(int *)(this + 0x178) + local_28 * 4);
          }
          iVar5 = MeshCreateFromFile(*(Engine **)(this + 0x34),(char *)*puVar6,&local_2c,pMVar3);
          if (iVar5 != 1) break;
          if (Engine::vboSupported != '\0') {
            local_2c[0x84] = (Mesh)0x1;
            AbyssEngine::MeshConvertToVBO(local_2c);
          }
          pMVar1 = local_2c;
          *(int *)(this + 0x2c) = *(int *)(this + 0x24) + 1;
          pvVar2 = realloc(*(void **)(this + 0x28),(*(int *)(this + 0x24) + 1) * 4);
          *(void **)(this + 0x28) = pvVar2;
          *(Mesh **)((int)pvVar2 + *(int *)(this + 0x24) * 4) = pMVar1;
          *(int *)(this + 0x24) = *(int *)(this + 0x2c);
          uVar4 = *(int *)(this + 0x2c) - 1;
          *(uint *)(puVar7 + 4) = uVar4;
        }
        else {
          iVar5 = *(int *)(this + 0x28);
          if ((*(int *)(*(int *)(iVar5 + uVar4 * 4) + 0x34) != 0) || (param_3)) {
            pMVar1 = operator_new(0x88);
            Mesh::Mesh(pMVar1,*(Mesh **)(iVar5 + *(int *)(puVar7 + 4) * 4));
            *(int *)(this + 0x2c) = *(int *)(this + 0x24) + 1;
            pvVar2 = realloc(*(void **)(this + 0x28),(*(int *)(this + 0x24) + 1) * 4);
            *(void **)(this + 0x28) = pvVar2;
            *(Mesh **)((int)pvVar2 + *(int *)(this + 0x24) * 4) = pMVar1;
            *(int *)(this + 0x24) = *(int *)(this + 0x2c);
            uVar4 = *(int *)(this + 0x2c) - 1;
          }
        }
        *param_2 = uVar4;
        break;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(this + 0x134));
  }
  if (__stack_chk_guard == local_24) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::MaterialCreate  @0x00083e10  (304 bytes)
/* AbyssEngine::PaintCanvas::MaterialCreate(unsigned short, unsigned int&) */

void __thiscall
AbyssEngine::PaintCanvas::MaterialCreate(PaintCanvas *this,ushort param_1,uint *param_2)

{
  ushort uVar1;
  Material *this_00;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(uint *)(this + 0x134) != 0) {
    uVar4 = 0;
    do {
      puVar5 = *(ushort **)(*(int *)(this + 0x138) + uVar4 * 4);
      if ((puVar5 != (ushort *)0x0) && (*puVar5 == param_1)) {
        uVar4 = *(uint *)(puVar5 + 4);
        if (uVar4 != 0xffffffff) goto LAB_00083f24;
        iVar6 = *(int *)(puVar5 + 6);
        this_00 = operator_new(0x74);
        Material::Material(this_00);
        iVar7 = 0;
        goto LAB_00083e6e;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(this + 0x134));
  }
  goto LAB_00083f28;
LAB_00083e6e:
  do {
    uVar1 = *(ushort *)(iVar6 + iVar7 * 2);
    if (uVar1 != 0xffff) {
      if (*(uint *)(this + 0x134) == 0) break;
      uVar4 = 0;
      while ((puVar8 = *(ushort **)(*(int *)(this + 0x138) + uVar4 * 4), puVar8 == (ushort *)0x0 ||
             (*puVar8 != uVar1))) {
        uVar4 = uVar4 + 1;
        if (*(uint *)(this + 0x134) <= uVar4) goto LAB_00083ed8;
      }
      iVar2 = *(int *)(puVar8 + 4);
      if (iVar2 == -1) {
        local_2c = 0;
        TextureCreate(this,uVar1,(_func_void_Image_ptr_void_ptr *)0x0,(void *)0x0,&local_2c,true);
        iVar2 = *(int *)(puVar8 + 4);
      }
      *(int *)(this_00 + iVar7 * 4) = iVar2;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 8);
LAB_00083ed8:
  *(undefined4 *)(this_00 + 0x20) = *(undefined4 *)(iVar6 + 0x10);
  *(undefined4 *)(this_00 + 0x24) = *(undefined4 *)(iVar6 + 0x14);
  *(undefined4 *)(this_00 + 0x28) = *(undefined4 *)(iVar6 + 0x18);
  AEMath::Vector::operator=((Vector *)(this_00 + 0x68),(Vector *)(iVar6 + 0x1c));
  *(int *)(this + 0x17c) = *(int *)(this + 0x174) + 1;
  pvVar3 = realloc(*(void **)(this + 0x178),(*(int *)(this + 0x174) + 1) * 4);
  *(void **)(this + 0x178) = pvVar3;
  *(Material **)((int)pvVar3 + *(int *)(this + 0x174) * 4) = this_00;
  *(int *)(this + 0x174) = *(int *)(this + 0x17c);
  uVar4 = *(int *)(this + 0x17c) - 1;
  *(uint *)(puVar5 + 4) = uVar4;
LAB_00083f24:
  *param_2 = uVar4;
LAB_00083f28:
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::MeshCreate  @0x00083f58  (148 bytes)
/* AbyssEngine::PaintCanvas::MeshCreate(unsigned short, unsigned short, signed char, unsigned short,
   unsigned int&) */

void __thiscall
AbyssEngine::PaintCanvas::MeshCreate
          (PaintCanvas *this,undefined4 param_2,undefined4 param_3,undefined4 param_4,ushort param_5
          ,int *param_6)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int local_28;
  uint local_24;
  int local_20;
  
  iVar4 = -1;
  local_20 = __stack_chk_guard;
  local_24 = 0xffffffff;
  MaterialCreate(this,param_5,&local_24);
  local_28 = 0;
  iVar2 = AbyssEngine::MeshCreate(*(undefined4 *)(this + 0x34),param_2,param_3,param_4,&local_28);
  iVar1 = local_28;
  if (iVar2 == 1) {
    if (local_24 <= *(uint *)(this + 0x174)) {
      *(undefined4 *)(local_28 + 0x30) = *(undefined4 *)(*(int *)(this + 0x178) + local_24 * 4);
    }
    *(int *)(this + 0x2c) = *(int *)(this + 0x24) + 1;
    pvVar3 = realloc(*(void **)(this + 0x28),(*(int *)(this + 0x24) + 1) * 4);
    *(void **)(this + 0x28) = pvVar3;
    *(int *)((int)pvVar3 + *(int *)(this + 0x24) * 4) = iVar1;
    *(int *)(this + 0x24) = *(int *)(this + 0x2c);
    iVar4 = *(int *)(this + 0x2c) + -1;
  }
  *param_6 = iVar4;
  if (__stack_chk_guard == local_20) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::MeshCreate  @0x00083ff4  (98 bytes)
/* AbyssEngine::PaintCanvas::MeshCreate(unsigned short, unsigned short, signed char, unsigned int&)
    */

void AbyssEngine::PaintCanvas::MeshCreate(int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *in_stack_00000000;
  
  iVar1 = __stack_chk_guard;
  iVar2 = AbyssEngine::MeshCreate(*(undefined4 *)(param_1 + 0x34));
  if (iVar2 == 1) {
    iVar2 = *(int *)(param_1 + 0x24) + 1;
    *(int *)(param_1 + 0x2c) = iVar2;
    pvVar3 = realloc(*(void **)(param_1 + 0x28),iVar2 * 4);
    *(void **)(param_1 + 0x28) = pvVar3;
    *(undefined4 *)((int)pvVar3 + *(int *)(param_1 + 0x24) * 4) = 0;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x2c);
    iVar2 = *(int *)(param_1 + 0x2c) + -1;
  }
  else {
    iVar2 = -1;
  }
  *in_stack_00000000 = iVar2;
  if (__stack_chk_guard != iVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshSetTriangleCount  @0x00084060  (32 bytes)
/* AbyssEngine::PaintCanvas::MeshSetTriangleCount(unsigned int, unsigned short) */

void __thiscall
AbyssEngine::PaintCanvas::MeshSetTriangleCount(PaintCanvas *this,uint param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  
  if (*(uint *)(this + 0x24) <= param_1) {
    return;
  }
  iVar2 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
  uVar1 = *(ushort *)(iVar2 + 0x2a);
  if (uVar1 < param_2) {
    param_2 = uVar1;
  }
  *(ushort *)(iVar2 + 0x28) = param_2 * 3;
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshSetPoint  @0x00084080  (58 bytes)
/* AbyssEngine::PaintCanvas::MeshSetPoint(unsigned int, unsigned short, float, float, float) */

float __thiscall
AbyssEngine::PaintCanvas::MeshSetPoint
          (PaintCanvas *this,uint param_1,ushort param_2,float param_3,float param_4,float param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  undefined4 in_stack_00000000;
  float in_stack_00000004;
  
  if (param_1 < *(uint *)(this + 0x24)) {
    iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
    if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
      return param_3;
    }
    puVar2 = (undefined4 *)(*(int *)(iVar1 + 4) + (uint)param_2 * 0xc);
    *puVar2 = in_r3;
    puVar2[1] = in_stack_00000000;
    puVar2[2] = in_stack_00000004;
    param_3 = in_stack_00000004;
  }
  return param_3;
}

// ===== AbyssEngine::PaintCanvas::MeshTranslatePoint  @0x000840ba  (82 bytes)
/* AbyssEngine::PaintCanvas::MeshTranslatePoint(unsigned int, unsigned short, float, float, float)
    */

float __thiscall
AbyssEngine::PaintCanvas::MeshTranslatePoint
          (PaintCanvas *this,uint param_1,ushort param_2,float param_3,float param_4,float param_5)

{
  int iVar1;
  float *pfVar2;
  float in_r3;
  float in_stack_00000000;
  float in_stack_00000004;
  
  if (param_1 < *(uint *)(this + 0x24)) {
    iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
    if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
      return param_3;
    }
    pfVar2 = (float *)(*(int *)(iVar1 + 4) + (uint)param_2 * 0xc);
    *pfVar2 = *pfVar2 + in_r3;
    pfVar2[1] = pfVar2[1] + in_stack_00000000;
    param_3 = pfVar2[2] + in_stack_00000004;
    pfVar2[2] = param_3;
  }
  return param_3;
}

// ===== AbyssEngine::PaintCanvas::MeshSetUv  @0x0008410c  (64 bytes)
/* AbyssEngine::PaintCanvas::MeshSetUv(unsigned int, unsigned short, float, float) */

float __thiscall
AbyssEngine::PaintCanvas::MeshSetUv
          (PaintCanvas *this,uint param_1,ushort param_2,float param_3,float param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  float in_stack_00000000;
  
  if (param_1 < *(uint *)(this + 0x24)) {
    iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
    if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
      return param_3;
    }
    puVar2 = (undefined4 *)(*(int *)(iVar1 + 8) + (uint)param_2 * 8);
    *puVar2 = in_r3;
    if (Engine::enableShader != '\0') {
      in_stack_00000000 = 1.0 - in_stack_00000000;
    }
    puVar2[1] = in_stack_00000000;
    param_3 = in_stack_00000000;
  }
  return param_3;
}

// ===== AbyssEngine::PaintCanvas::MeshSetColor  @0x00084150  (126 bytes)
/* AbyssEngine::PaintCanvas::MeshSetColor(unsigned int, unsigned short, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::MeshSetColor(PaintCanvas *this,uint param_1,ushort param_2,uint param_3)

{
  int iVar1;
  float *pfVar2;
  uint in_fpscr;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  if (param_1 < *(uint *)(this + 0x24)) {
    iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
    if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
      return;
    }
    dVar3 = (double)VectorUnsignedToFloat(param_3 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
    dVar4 = (double)VectorUnsignedToFloat((param_3 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3)
    ;
    dVar5 = (double)VectorUnsignedToFloat((param_3 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
    dVar6 = (double)VectorUnsignedToFloat(param_3 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
    pfVar2 = (float *)(*(int *)(iVar1 + 0xc) + (uint)param_2 * 0x10);
    *pfVar2 = (float)(dVar3 / 255.0);
    pfVar2[1] = (float)(dVar4 / 255.0);
    pfVar2[2] = (float)(dVar5 / 255.0);
    pfVar2[3] = (float)(dVar6 / 255.0);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshSetColor  @0x000841d8  (62 bytes)
/* AbyssEngine::PaintCanvas::MeshSetColor(unsigned int, unsigned short, float, float, float, float)
    */

float __thiscall
AbyssEngine::PaintCanvas::MeshSetColor
          (PaintCanvas *this,uint param_1,ushort param_2,float param_3,float param_4,float param_5,
          float param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  float in_stack_00000008;
  
  if (param_1 < *(uint *)(this + 0x24)) {
    iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
    if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
      return param_3;
    }
    puVar2 = (undefined4 *)(*(int *)(iVar1 + 0xc) + (uint)param_2 * 0x10);
    *puVar2 = in_r3;
    puVar2[1] = in_stack_00000000;
    puVar2[2] = in_stack_00000004;
    puVar2[3] = in_stack_00000008;
    param_3 = in_stack_00000008;
  }
  return param_3;
}

// ===== AbyssEngine::PaintCanvas::MeshSetTriangle  @0x00084216  (58 bytes)
/* AbyssEngine::PaintCanvas::MeshSetTriangle(unsigned int, unsigned short, unsigned short, unsigned
   short, unsigned short) */

void __thiscall
AbyssEngine::PaintCanvas::MeshSetTriangle
          (PaintCanvas *this,uint param_1,ushort param_2,ushort param_3,ushort param_4,
          ushort param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)param_2;
  if (param_1 < *(uint *)(this + 0x24)) {
    iVar2 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
    if ((uint)*(ushort *)(iVar2 + 0x28) <= uVar1 * 3) {
      return;
    }
    iVar2 = *(int *)(iVar2 + 0x2c);
    *(ushort *)(iVar2 + uVar1 * 6) = param_3;
    iVar2 = iVar2 + uVar1 * 6;
    *(ushort *)(iVar2 + 2) = param_4;
    *(ushort *)(iVar2 + 4) = param_5;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshSetNormal  @0x00084250  (40 bytes)
/* AbyssEngine::PaintCanvas::MeshSetNormal(unsigned int, unsigned short, AbyssEngine::AEMath::Vector
   const&) */

void __thiscall
AbyssEngine::PaintCanvas::MeshSetNormal
          (PaintCanvas *this,uint param_1,ushort param_2,Vector *param_3)

{
  int iVar1;
  
  if (*(uint *)(this + 0x24) <= param_1) {
    return;
  }
  iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
  if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
    return;
  }
  AEMath::Vector::operator=((Vector *)(*(int *)(iVar1 + 0x10) + (uint)param_2 * 0xc),param_3);
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshSetTangent  @0x00084278  (40 bytes)
/* AbyssEngine::PaintCanvas::MeshSetTangent(unsigned int, unsigned short,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::PaintCanvas::MeshSetTangent
          (PaintCanvas *this,uint param_1,ushort param_2,Vector *param_3)

{
  int iVar1;
  
  if (*(uint *)(this + 0x24) <= param_1) {
    return;
  }
  iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
  if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
    return;
  }
  AEMath::Vector::operator=((Vector *)(*(int *)(iVar1 + 0x14) + (uint)param_2 * 0xc),param_3);
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshSetBiTangent  @0x000842a0  (40 bytes)
/* AbyssEngine::PaintCanvas::MeshSetBiTangent(unsigned int, unsigned short,
   AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::PaintCanvas::MeshSetBiTangent
          (PaintCanvas *this,uint param_1,ushort param_2,Vector *param_3)

{
  int iVar1;
  
  if (*(uint *)(this + 0x24) <= param_1) {
    return;
  }
  iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
  if ((uint)*(ushort *)(iVar1 + 2) <= (uint)param_2) {
    return;
  }
  AEMath::Vector::operator=((Vector *)(*(int *)(iVar1 + 0x18) + (uint)param_2 * 0xc),param_3);
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshConvertToVBO  @0x000842c8  (20 bytes)
/* AbyssEngine::PaintCanvas::MeshConvertToVBO(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::MeshConvertToVBO(PaintCanvas *this,uint param_1)

{
  if (param_1 < *(uint *)(this + 0x24)) {
    AbyssEngine::MeshConvertToVBO(*(Mesh **)(*(int *)(this + 0x28) + param_1 * 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue  @0x000842da  (44 bytes)
/* AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(AbyssEngine::Mesh*, float, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
          (PaintCanvas *this,Mesh *param_1,float param_2,uint param_3)

{
  int in_r3;
  
  if (param_1 == (Mesh *)0x0) {
    return;
  }
  if (in_r3 == 4) {
    *(uint *)(param_1 + 0x24) = param_3;
  }
  else if (in_r3 == 2) {
    *(uint *)(param_1 + 0x20) = param_3;
  }
  else if (in_r3 == 1) {
    *(uint *)(param_1 + 0x1c) = param_3;
  }
  MeshChangeShaderAnimValue((Transform *)this,(float)param_3,*(uint *)(param_1 + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue  @0x00084304  (84 bytes)
/* AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue(AbyssEngine::Transform*, float, unsigned int)
    */

void AbyssEngine::PaintCanvas::MeshChangeShaderAnimValue
               (Transform *param_1,float param_2,uint param_3)

{
  uint in_r2;
  uint uVar1;
  
  if (param_3 != 0) {
    if (*(int *)(param_3 + 0x3c) != 0) {
      uVar1 = 0;
      do {
        param_2 = (float)MeshChangeShaderAnimValue
                                   ((PaintCanvas *)param_1,
                                    *(Mesh **)(*(int *)(param_3 + 0x40) + uVar1 * 4),param_2,in_r2);
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_3 + 0x3c));
    }
    if (*(int *)(param_3 + 0x4c) != 0) {
      uVar1 = 0;
      do {
        param_2 = (float)MeshChangeShaderAnimValue
                                   (param_1,param_2,*(uint *)(*(int *)(param_3 + 0x50) + uVar1 * 4))
        ;
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_3 + 0x4c));
    }
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshChangeMaterialIntern  @0x00084358  (82 bytes)
/* AbyssEngine::PaintCanvas::MeshChangeMaterialIntern(AbyssEngine::Transform*,
   AbyssEngine::Material*) */

void __thiscall
AbyssEngine::PaintCanvas::MeshChangeMaterialIntern
          (PaintCanvas *this,Transform *param_1,Material *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 != (Transform *)0x0) && (param_2 != (Material *)0x0)) {
    uVar1 = *(uint *)(param_1 + 0x3c);
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x40) + uVar3 * 4);
        if (iVar2 != 0) {
          *(Material **)(iVar2 + 0x30) = param_2;
          MeshChangeMaterialIntern(this,*(Transform **)(iVar2 + 0x34),param_2);
          uVar1 = *(uint *)(param_1 + 0x3c);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar1);
    }
    if (*(int *)(param_1 + 0x4c) != 0) {
      uVar1 = 0;
      do {
        MeshChangeMaterialIntern(this,*(Transform **)(*(int *)(param_1 + 0x50) + uVar1 * 4),param_2)
        ;
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0x4c));
    }
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshChangeMaterialIntern  @0x000843aa  (14 bytes)
/* AbyssEngine::PaintCanvas::MeshChangeMaterialIntern(AbyssEngine::Mesh*, AbyssEngine::Material*) */

void __thiscall
AbyssEngine::PaintCanvas::MeshChangeMaterialIntern
          (PaintCanvas *this,Mesh *param_1,Material *param_2)

{
  if ((param_1 != (Mesh *)0x0) && (param_2 != (Material *)0x0)) {
    *(Material **)(param_1 + 0x30) = param_2;
    MeshChangeMaterialIntern(this,*(Transform **)(param_1 + 0x34),param_2);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshCloneMaterial  @0x000843b8  (96 bytes)
/* AbyssEngine::PaintCanvas::MeshCloneMaterial(unsigned int, unsigned int&) */

void __thiscall
AbyssEngine::PaintCanvas::MeshCloneMaterial(PaintCanvas *this,uint param_1,uint *param_2)

{
  Material *this_00;
  void *pvVar1;
  uint uVar2;
  
  if (param_1 < *(uint *)(this + 0x24)) {
    this_00 = operator_new(0x74);
    Material::Material(this_00,*(Material **)(*(int *)(*(int *)(this + 0x28) + param_1 * 4) + 0x30))
    ;
    *(int *)(this + 0x17c) = *(int *)(this + 0x174) + 1;
    pvVar1 = realloc(*(void **)(this + 0x178),(*(int *)(this + 0x174) + 1) * 4);
    *(void **)(this + 0x178) = pvVar1;
    *(Material **)((int)pvVar1 + *(int *)(this + 0x174) * 4) = this_00;
    *(int *)(this + 0x174) = *(int *)(this + 0x17c);
    uVar2 = *(int *)(this + 0x17c) - 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  *param_2 = uVar2;
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshChangeResourceMaterial  @0x00084600  (82 bytes)
/* AbyssEngine::PaintCanvas::MeshChangeResourceMaterial(unsigned int, unsigned short) */

void __thiscall
AbyssEngine::PaintCanvas::MeshChangeResourceMaterial(PaintCanvas *this,uint param_1,ushort param_2)

{
  int iVar1;
  Material *pMVar2;
  uint uVar3;
  ushort *puVar4;
  
  if (*(uint *)(this + 0x134) == 0) {
    return;
  }
  uVar3 = 0;
  while ((puVar4 = *(ushort **)(*(int *)(this + 0x138) + uVar3 * 4), puVar4 == (ushort *)0x0 ||
         (*puVar4 != param_2))) {
    uVar3 = uVar3 + 1;
    if (*(uint *)(this + 0x134) <= uVar3) {
      return;
    }
  }
  iVar1 = *(int *)(puVar4 + 4);
  if (iVar1 != -1) {
    param_1 = *(uint *)(*(int *)(this + 0x28) + param_1 * 4);
  }
  if (iVar1 == -1 || param_1 == 0) {
    return;
  }
  pMVar2 = *(Material **)(*(int *)(this + 0x178) + iVar1 * 4);
  if (pMVar2 == (Material *)0x0) {
    return;
  }
  *(Material **)(param_1 + 0x30) = pMVar2;
  MeshChangeMaterialIntern(this,*(Transform **)(param_1 + 0x34),pMVar2);
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshChangeMaterial  @0x00084652  (48 bytes)
/* AbyssEngine::PaintCanvas::MeshChangeMaterial(unsigned int, unsigned short) */

void __thiscall
AbyssEngine::PaintCanvas::MeshChangeMaterial(PaintCanvas *this,uint param_1,ushort param_2)

{
  int iVar1;
  Material *pMVar2;
  
  if (((uint)param_2 < *(uint *)(this + 0x174)) && (param_1 < *(uint *)(this + 0x24))) {
    iVar1 = *(int *)(*(int *)(this + 0x28) + param_1 * 4);
    if (iVar1 == 0) {
      return;
    }
    pMVar2 = *(Material **)(*(int *)(this + 0x178) + (uint)param_2 * 4);
    if (pMVar2 != (Material *)0x0) {
      *(Material **)(iVar1 + 0x30) = pMVar2;
      MeshChangeMaterialIntern(this,*(Transform **)(iVar1 + 0x34),pMVar2);
      return;
    }
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshResourceChangeMaterial  @0x00084680  (48 bytes)
/* AbyssEngine::PaintCanvas::MeshResourceChangeMaterial(unsigned short, unsigned short) */

void __thiscall
AbyssEngine::PaintCanvas::MeshResourceChangeMaterial
          (PaintCanvas *this,ushort param_1,ushort param_2)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  uVar4 = *(uint *)(this + 0x134);
  if (uVar4 != 0) {
    iVar5 = *(int *)(this + 0x138);
    uVar2 = 0;
    do {
      puVar1 = *(ushort **)(iVar5 + uVar2 * 4);
      if (puVar1 != (ushort *)0x0) {
        uVar3 = (uint)*puVar1;
        bVar6 = uVar3 == param_1;
        if (bVar6) {
          uVar3 = *(uint *)(puVar1 + 6);
        }
        if (bVar6) {
          *(ushort *)(uVar3 + 4) = param_2;
          puVar1 = *(ushort **)(puVar1 + 6);
        }
        if (bVar6) {
          puVar1[2] = param_2;
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar4);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshResourceChangeAllMaterial  @0x000846b0  (44 bytes)
/* AbyssEngine::PaintCanvas::MeshResourceChangeAllMaterial(unsigned short, unsigned short) */

void __thiscall
AbyssEngine::PaintCanvas::MeshResourceChangeAllMaterial
          (PaintCanvas *this,ushort param_1,ushort param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(this + 0x134);
  if (uVar3 == 0) {
    return;
  }
  iVar4 = *(int *)(this + 0x138);
  uVar2 = 0;
  do {
    iVar1 = *(int *)(iVar4 + uVar2 * 4);
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xc), *(ushort *)(iVar1 + 4) == param_1)) {
      *(ushort *)(iVar1 + 4) = param_2;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < uVar3);
  return;
}

// ===== AbyssEngine::PaintCanvas::MeshGetPointer  @0x000846dc  (16 bytes)
/* AbyssEngine::PaintCanvas::MeshGetPointer(unsigned int) */

undefined4 __thiscall AbyssEngine::PaintCanvas::MeshGetPointer(PaintCanvas *this,uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < *(uint *)(this + 0x24)) {
    uVar1 = *(undefined4 *)(*(int *)(this + 0x28) + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== AbyssEngine::PaintCanvas::MeshGetTriCount  @0x000846ec  (44 bytes)
/* AbyssEngine::PaintCanvas::MeshGetTriCount(AbyssEngine::Mesh*) */

undefined8 __thiscall AbyssEngine::PaintCanvas::MeshGetTriCount(PaintCanvas *this,Mesh *param_1)

{
  int iVar1;
  
  if (param_1 != (Mesh *)0x0) {
    if (*(Transform **)(param_1 + 0x34) == (Transform *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = TransformGetTriCount(this,*(Transform **)(param_1 + 0x34));
    }
    return CONCAT44((uint)*(ushort *)(param_1 + 0x28) * -0x55555555,
                    iVar1 + *(ushort *)(param_1 + 0x28) / 3);
  }
  return 0;
}

// ===== AbyssEngine::PaintCanvas::TransformGetTriCount  @0x00084718  (100 bytes)
/* AbyssEngine::PaintCanvas::TransformGetTriCount(AbyssEngine::Transform*) */

int __thiscall AbyssEngine::PaintCanvas::TransformGetTriCount(PaintCanvas *this,Transform *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 == (Transform *)0x0) {
    iVar2 = 0;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x3c);
    if (uVar4 == 0) {
      iVar2 = 0;
    }
    else {
      iVar5 = *(int *)(param_1 + 0x40);
      uVar3 = 0;
      iVar2 = 0;
      do {
        iVar1 = MeshGetTriCount(this,*(Mesh **)(iVar5 + uVar3 * 4));
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + iVar1;
      } while (uVar3 < uVar4);
    }
    uVar4 = *(uint *)(param_1 + 0x4c);
    if (uVar4 != 0) {
      iVar5 = *(int *)(param_1 + 0x50);
      uVar3 = 0;
      do {
        iVar1 = TransformGetTriCount(this,*(Transform **)(iVar5 + uVar3 * 4));
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + iVar1;
      } while (uVar3 < uVar4);
    }
  }
  return iVar2;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemCreate  @0x0008477c  (192 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemCreate(unsigned short, bool, unsigned short, unsigned int&)
    */

void __thiscall
AbyssEngine::PaintCanvas::SpriteSystemCreate
          (PaintCanvas *this,ushort param_1,bool param_2,ushort param_3,uint *param_4)

{
  SpriteSystem *pSVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint local_20;
  SpriteSystem *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_1c = (SpriteSystem *)0x0;
  iVar2 = AbyssEngine::SpriteSystemCreate(*(Engine **)(this + 0x34),param_1,param_2,&local_1c);
  if (iVar2 == 1) {
    local_20 = 0xffffffff;
    MaterialCreate(this,param_3,&local_20);
    if (local_20 <= *(uint *)(this + 0x174)) {
      *(undefined4 *)(*(int *)(local_1c + 0x10) + 0x30) =
           *(undefined4 *)(*(int *)(this + 0x178) + local_20 * 4);
    }
    if (*(uint *)(this + 0x180) != 0) {
      uVar4 = 0;
      do {
        if (*(int *)(*(int *)(this + 0x184) + uVar4 * 4) == 0) {
          *(SpriteSystem **)(*(int *)(this + 0x184) + uVar4 * 4) = local_1c;
          local_1c = (SpriteSystem *)0x0;
          *param_4 = uVar4;
          break;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(this + 0x180));
    }
    pSVar1 = local_1c;
    if (local_1c == (SpriteSystem *)0x0) goto LAB_00084826;
    *(int *)(this + 0x188) = *(int *)(this + 0x180) + 1;
    pvVar3 = realloc(*(void **)(this + 0x184),(*(int *)(this + 0x180) + 1) * 4);
    *(void **)(this + 0x184) = pvVar3;
    *(SpriteSystem **)((int)pvVar3 + *(int *)(this + 0x180) * 4) = pSVar1;
    *(int *)(this + 0x180) = *(int *)(this + 0x188);
    uVar4 = *(int *)(this + 0x188) - 1;
  }
  else {
    uVar4 = 0xffffffff;
  }
  *param_4 = uVar4;
LAB_00084826:
  if (__stack_chk_guard == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemCreate  @0x00084844  (150 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemCreate(unsigned short, bool, unsigned int&) */

void __thiscall
AbyssEngine::PaintCanvas::SpriteSystemCreate
          (PaintCanvas *this,ushort param_1,bool param_2,uint *param_3)

{
  SpriteSystem *pSVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  SpriteSystem *local_1c;
  int local_18;
  
  local_18 = __stack_chk_guard;
  local_1c = (SpriteSystem *)0x0;
  iVar2 = AbyssEngine::SpriteSystemCreate(*(Engine **)(this + 0x34),param_1,param_2,&local_1c);
  if (iVar2 == 1) {
    if (*(uint *)(this + 0x180) != 0) {
      uVar4 = 0;
      do {
        if (*(int *)(*(int *)(this + 0x184) + uVar4 * 4) == 0) {
          *(SpriteSystem **)(*(int *)(this + 0x184) + uVar4 * 4) = local_1c;
          local_1c = (SpriteSystem *)0x0;
          *param_3 = uVar4;
          break;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(this + 0x180));
    }
    pSVar1 = local_1c;
    if (local_1c == (SpriteSystem *)0x0) goto LAB_000848c4;
    *(int *)(this + 0x188) = *(int *)(this + 0x180) + 1;
    pvVar3 = realloc(*(void **)(this + 0x184),(*(int *)(this + 0x180) + 1) * 4);
    *(void **)(this + 0x184) = pvVar3;
    *(SpriteSystem **)((int)pvVar3 + *(int *)(this + 0x180) * 4) = pSVar1;
    *(int *)(this + 0x180) = *(int *)(this + 0x188);
    uVar4 = *(int *)(this + 0x188) - 1;
  }
  else {
    uVar4 = 0xffffffff;
  }
  *param_3 = uVar4;
LAB_000848c4:
  if (__stack_chk_guard == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemSetAllSize  @0x000848e4  (30 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemSetAllSize(unsigned int, short) */

void __thiscall
AbyssEngine::PaintCanvas::SpriteSystemSetAllSize(PaintCanvas *this,uint param_1,short param_2)

{
  SpriteSystem *pSVar1;
  
  if (*(uint *)(this + 0x180) <= param_1) {
    return;
  }
  pSVar1 = *(SpriteSystem **)(*(int *)(this + 0x184) + param_1 * 4);
  if (pSVar1 == (SpriteSystem *)0x0) {
    return;
  }
  AbyssEngine::SpriteSystemSetAllSize(param_2,pSVar1);
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemSetAllUv  @0x00084900  (64 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemSetAllUv(unsigned int, float, float, float, float) */

void AbyssEngine::PaintCanvas::SpriteSystemSetAllUv
               (uint param_1,float param_2,float param_3,float param_4,float param_5)

{
  uint in_r1;
  SpriteSystem *in_r2;
  float in_stack_00000000;
  float in_stack_00000004;
  
  if (*(uint *)(param_1 + 0x180) <= in_r1) {
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0x184) + in_r1 * 4) == 0) {
    return;
  }
  AbyssEngine::SpriteSystemSetAllUv(in_stack_00000004,param_3,in_stack_00000000,param_5,in_r2);
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemSetUv  @0x00084940  (76 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemSetUv(unsigned int, unsigned short, float, float, float,
   float) */

void AbyssEngine::PaintCanvas::SpriteSystemSetUv
               (uint param_1,ushort param_2,float param_3,float param_4,float param_5,float param_6)

{
  ushort *puVar1;
  uint in_r2;
  SpriteSystem *in_r3;
  float in_stack_00000004;
  float in_stack_00000008;
  
  if (((uint)param_2 < *(uint *)(param_1 + 0x180)) &&
     (puVar1 = *(ushort **)(*(int *)(param_1 + 0x184) + (uint)param_2 * 4), puVar1 != (ushort *)0x0)
     ) {
    if (*puVar1 <= in_r2) {
      return;
    }
    AbyssEngine::SpriteSystemSetUv
              ((ushort)in_r2,in_stack_00000008,param_4,in_stack_00000004,param_6,in_r3);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemSetRGBA  @0x0008498c  (76 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemSetRGBA(unsigned int, unsigned short, float, float, float,
   float) */

void AbyssEngine::PaintCanvas::SpriteSystemSetRGBA
               (uint param_1,ushort param_2,float param_3,float param_4,float param_5,float param_6)

{
  ushort *puVar1;
  uint in_r2;
  SpriteSystem *in_r3;
  float in_stack_00000004;
  float in_stack_00000008;
  
  if (((uint)param_2 < *(uint *)(param_1 + 0x180)) &&
     (puVar1 = *(ushort **)(*(int *)(param_1 + 0x184) + (uint)param_2 * 4), puVar1 != (ushort *)0x0)
     ) {
    if (*puVar1 <= in_r2) {
      return;
    }
    AbyssEngine::SpriteSystemSetRGBA
              ((ushort)in_r2,in_stack_00000008,param_4,in_stack_00000004,param_6,in_r3);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemSetSize  @0x000849d8  (42 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemSetSize(unsigned int, unsigned short, short) */

void __thiscall
AbyssEngine::PaintCanvas::SpriteSystemSetSize
          (PaintCanvas *this,uint param_1,ushort param_2,short param_3)

{
  ushort *puVar1;
  
  if ((param_1 < *(uint *)(this + 0x180)) &&
     (puVar1 = *(ushort **)(*(int *)(this + 0x184) + param_1 * 4), puVar1 != (ushort *)0x0)) {
    if ((uint)*puVar1 <= (uint)param_2) {
      return;
    }
    if ((char)puVar1[6] != '\0') {
      **(short **)(puVar1 + 4) = param_3;
      return;
    }
    (*(short **)(puVar1 + 4))[param_2] = param_3;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemAddSize  @0x00084a02  (52 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemAddSize(unsigned int, unsigned short, short) */

void __thiscall
AbyssEngine::PaintCanvas::SpriteSystemAddSize
          (PaintCanvas *this,uint param_1,ushort param_2,short param_3)

{
  short *psVar1;
  ushort *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2;
  if ((param_1 < *(uint *)(this + 0x180)) &&
     (puVar2 = *(ushort **)(*(int *)(this + 0x184) + param_1 * 4), puVar2 != (ushort *)0x0)) {
    if (*puVar2 <= uVar3) {
      return;
    }
    psVar1 = *(short **)(puVar2 + 4);
    if ((char)puVar2[6] != '\0') {
      *psVar1 = *psVar1 + param_3;
      return;
    }
    psVar1[uVar3] = psVar1[uVar3] + param_3;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemGetPosition  @0x00084a36  (212 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemGetPosition(unsigned int, unsigned short,
   AbyssEngine::AEMath::Matrix const&, AbyssEngine::AEMath::Vector&) */

void __thiscall
AbyssEngine::PaintCanvas::SpriteSystemGetPosition
          (PaintCanvas *this,uint param_1,ushort param_2,Matrix *param_3,Vector *param_4)

{
  float *pfVar1;
  ushort *puVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  if ((param_1 < *(uint *)(this + 0x180)) &&
     (puVar2 = *(ushort **)(*(int *)(this + 0x184) + param_1 * 4), puVar2 != (ushort *)0x0)) {
    if ((uint)*puVar2 <= (uint)param_2) {
      return;
    }
    fVar14 = *(float *)(param_3 + 0x14);
    pfVar1 = (float *)(*(int *)(puVar2 + 2) + (uint)param_2 * 0xc);
    fVar3 = *(float *)(param_3 + 0x10);
    fVar5 = *(float *)(param_3 + 0x18);
    fVar8 = *pfVar1;
    fVar10 = pfVar1[1];
    fVar12 = pfVar1[2];
    fVar7 = *(float *)(param_3 + 0x24);
    fVar4 = *(float *)(param_3 + 0x20);
    fVar9 = *(float *)(param_3 + 0x28);
    fVar11 = *(float *)(param_3 + 0x1c);
    fVar13 = (float)VectorSignedToFloat((int)**(short **)(puVar2 + 4) >> 1,
                                        (byte)(in_fpscr >> 0x16) & 3);
    fVar6 = *(float *)(param_3 + 0x2c);
    *(float *)param_4 =
         (*(float *)(param_3 + 0xc) +
         *(float *)param_3 * fVar8 + *(float *)(param_3 + 4) * fVar10 +
         *(float *)(param_3 + 8) * fVar12) - fVar13;
    *(float *)(param_4 + 4) = fVar11 + fVar8 * fVar3 + fVar10 * fVar14 + fVar12 * fVar5 + fVar13;
    *(float *)(param_4 + 8) = fVar6 + fVar8 * fVar4 + fVar10 * fVar7 + fVar12 * fVar9;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemGetPosition  @0x00084b0a  (52 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemGetPosition(unsigned int, unsigned short,
   AbyssEngine::AEMath::Vector&) */

void __thiscall
AbyssEngine::PaintCanvas::SpriteSystemGetPosition
          (PaintCanvas *this,uint param_1,ushort param_2,Vector *param_3)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2;
  if ((param_1 < *(uint *)(this + 0x180)) &&
     (puVar1 = *(ushort **)(*(int *)(this + 0x184) + param_1 * 4), puVar1 != (ushort *)0x0)) {
    if (*puVar1 <= uVar3) {
      return;
    }
    iVar2 = *(int *)(puVar1 + 2) + uVar3 * 0xc;
    *(undefined4 *)param_3 = *(undefined4 *)(*(int *)(puVar1 + 2) + uVar3 * 0xc);
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar2 + 8);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemSetPosition  @0x00084b3e  (62 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemSetPosition(unsigned int, unsigned short, float, float,
   float) */

float __thiscall
AbyssEngine::PaintCanvas::SpriteSystemSetPosition
          (PaintCanvas *this,uint param_1,ushort param_2,float param_3,float param_4,float param_5)

{
  ushort *puVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  undefined4 in_stack_00000000;
  float in_stack_00000004;
  
  if ((param_1 < *(uint *)(this + 0x180)) &&
     (puVar1 = *(ushort **)(*(int *)(this + 0x184) + param_1 * 4), puVar1 != (ushort *)0x0)) {
    if ((uint)*puVar1 <= (uint)param_2) {
      return param_3;
    }
    puVar2 = (undefined4 *)(*(int *)(puVar1 + 2) + (uint)param_2 * 0xc);
    *puVar2 = in_r3;
    puVar2[1] = in_stack_00000000;
    puVar2[2] = in_stack_00000004;
    param_3 = in_stack_00000004;
  }
  return param_3;
}

// ===== AbyssEngine::PaintCanvas::SpriteSystemAddPosition  @0x00084b7c  (86 bytes)
/* AbyssEngine::PaintCanvas::SpriteSystemAddPosition(unsigned int, unsigned short, float, float,
   float) */

float __thiscall
AbyssEngine::PaintCanvas::SpriteSystemAddPosition
          (PaintCanvas *this,uint param_1,ushort param_2,float param_3,float param_4,float param_5)

{
  ushort *puVar1;
  float *pfVar2;
  float in_r3;
  float in_stack_00000000;
  float in_stack_00000004;
  
  if ((param_1 < *(uint *)(this + 0x180)) &&
     (puVar1 = *(ushort **)(*(int *)(this + 0x184) + param_1 * 4), puVar1 != (ushort *)0x0)) {
    if ((uint)*puVar1 <= (uint)param_2) {
      return param_3;
    }
    pfVar2 = (float *)(*(int *)(puVar1 + 2) + (uint)param_2 * 0xc);
    *pfVar2 = *pfVar2 + in_r3;
    pfVar2[1] = pfVar2[1] + in_stack_00000000;
    param_3 = pfVar2[2] + in_stack_00000004;
    pfVar2[2] = param_3;
  }
  return param_3;
}

// ===== AbyssEngine::PaintCanvas::DrawSpriteSystem  @0x00084be0  (408 bytes)
/* AbyssEngine::PaintCanvas::DrawSpriteSystem(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::DrawSpriteSystem(PaintCanvas *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  Engine *pEVar3;
  undefined4 *puVar4;
  AEMath *this_00;
  AEMath *this_01;
  float extraout_s0;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  AEMath aAStack_144 [60];
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 local_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 local_c8;
  uint local_c4;
  uint local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined4 local_88 [5];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  int local_4c;
  
  local_4c = __stack_chk_guard;
  if ((param_1 < *(uint *)(this + 0x180)) && (*(int *)(*(int *)(this + 0x184) + param_1 * 4) != 0))
  {
    uVar5 = 0;
    uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uVar8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar4 = (undefined4 *)((uint)local_88 | 4);
    local_88[0] = 0x3f800000;
    *puVar4 = 0;
    puVar4[1] = uVar6;
    puVar4[2] = uVar7;
    puVar4[3] = uVar8;
    local_74 = 0x3f800000;
    local_70 = 0;
    local_60 = 0x3f800000;
    uStack_58 = 0x3f8000003f800000;
    local_50 = 0x3f800000;
    uStack_6c = uVar6;
    uStack_68 = uVar7;
    uStack_64 = uVar8;
    if (*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) {
      if (*this == (PaintCanvas)0x0) {
        this_01 = (AEMath *)&local_c8;
        this_00 = (AEMath *)(*(int *)(*(int *)(this + 0x168) + *(uint *)(this + 0x170) * 4) + 0xc);
      }
      else {
        uStack_ac = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
        uStack_a8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
        uStack_a4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
        puVar4 = (undefined4 *)((uint)&local_c8 | 4);
        local_c8 = 0x3f800000;
        this_00 = (AEMath *)&local_108;
        *puVar4 = 0;
        puVar4[1] = uStack_ac;
        puVar4[2] = uStack_a8;
        puVar4[3] = uStack_a4;
        local_b4 = 0x3f800000;
        local_b0 = 0;
        local_a0 = 0x3f800000;
        uStack_98 = 0x3f8000003f800000;
        local_90 = 0x3f800000;
        AEMath::MatrixIdentity(this_00,(Matrix *)&local_c8);
        iVar1 = Engine::GetGravValue(*(Engine **)(this + 0x34));
        uVar2 = AEMath::Sinf((float)(*(double *)(iVar1 + 8) * 1.5707963705062866));
        local_c8 = AEMath::Cosf(extraout_s0);
        local_c4 = uVar2 ^ 0x80000000;
        iVar1 = *(int *)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4);
        local_108 = *(undefined4 *)(iVar1 + 0xc);
        uStack_104 = *(undefined4 *)(iVar1 + 0x10);
        uStack_100 = *(undefined4 *)(iVar1 + 0x14);
        uStack_fc = *(undefined4 *)(iVar1 + 0x18);
        uStack_f8 = *(undefined4 *)(iVar1 + 0x1c);
        local_f4 = *(undefined4 *)(iVar1 + 0x20);
        uStack_f0 = *(undefined4 *)(iVar1 + 0x24);
        uStack_ec = *(undefined4 *)(iVar1 + 0x28);
        uStack_e8 = *(undefined4 *)(iVar1 + 0x2c);
        uStack_e4 = *(undefined4 *)(iVar1 + 0x30);
        local_e0 = *(undefined4 *)(iVar1 + 0x34);
        uStack_dc = *(undefined4 *)(iVar1 + 0x38);
        uStack_d8 = *(undefined4 *)(iVar1 + 0x3c);
        uStack_d4 = *(undefined4 *)(iVar1 + 0x40);
        uStack_d0 = *(undefined4 *)(iVar1 + 0x44);
        local_b8 = uVar2;
        local_b4 = local_c8;
        AEMath::Matrix::operator*=((Matrix *)this_00,(Matrix *)&local_c8);
        this_01 = aAStack_144;
      }
      AEMath::MatrixGetInverse(this_01,this_00);
      AEMath::Matrix::operator=((Matrix *)local_88,this_01);
    }
    pEVar3 = *(Engine **)(this + 0x34);
    puVar4 = (undefined4 *)((uint)&local_c8 | 4);
    local_c8 = 0x3f800000;
    *puVar4 = uVar5;
    puVar4[1] = uVar6;
    puVar4[2] = uVar7;
    puVar4[3] = uVar8;
    local_b4 = 0x3f800000;
    local_a0 = 0x3f800000;
    uStack_98 = 0x3f8000003f800000;
    local_90 = 0x3f800000;
    local_b0 = uVar5;
    uStack_ac = uVar6;
    uStack_a8 = uVar7;
    uStack_a4 = uVar8;
    SpriteSystemDraw(pEVar3,(Matrix *)&local_c8,(Matrix *)local_88,
                     *(SpriteSystem **)(*(int *)(this + 0x184) + param_1 * 4));
  }
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawSpriteSystem  @0x00084da0  (354 bytes)
/* AbyssEngine::PaintCanvas::DrawSpriteSystem(unsigned int, AbyssEngine::AEMath::Matrix) */

void AbyssEngine::PaintCanvas::DrawSpriteSystem
               (char *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
               undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
               undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17)

{
  int iVar1;
  uint uVar2;
  Engine *pEVar3;
  undefined4 *puVar4;
  AEMath *this;
  float extraout_s0;
  AEMath aAStack_dc [60];
  undefined4 local_a0;
  uint local_9c;
  uint local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((param_2 < *(uint *)(param_1 + 0x180)) &&
     (*(int *)(*(int *)(param_1 + 0x184) + param_2 * 4) != 0)) {
    local_5c = param_5;
    uStack_58 = param_6;
    uStack_54 = param_7;
    uStack_50 = param_8;
    local_4c = param_9;
    uStack_48 = param_10;
    uStack_44 = param_11;
    uStack_40 = param_12;
    uStack_3c = param_13;
    local_38 = param_14;
    local_34 = param_15;
    local_30 = param_16;
    local_2c = param_17;
    local_64 = param_3;
    uStack_60 = param_4;
    if (*param_1 == '\0') {
      this = (AEMath *)&local_a0;
      AEMath::MatrixGetInverse(this,(Matrix *)&local_64);
    }
    else {
      uStack_84 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_80 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_7c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar4 = (undefined4 *)((uint)&local_a0 | 4);
      local_a0 = 0x3f800000;
      *puVar4 = 0;
      puVar4[1] = uStack_84;
      puVar4[2] = uStack_80;
      puVar4[3] = uStack_7c;
      local_8c = 0x3f800000;
      local_88 = 0;
      local_78 = 0x3f800000;
      uStack_70 = 0x3f8000003f800000;
      local_68 = 0x3f800000;
      AEMath::MatrixIdentity(aAStack_dc,(Matrix *)&local_a0);
      iVar1 = Engine::GetGravValue(*(Engine **)(param_1 + 0x34));
      uVar2 = AEMath::Sinf((float)(*(double *)(iVar1 + 8) * 1.5707963705062866));
      local_a0 = AEMath::Cosf(extraout_s0);
      local_9c = uVar2 ^ 0x80000000;
      local_90 = uVar2;
      local_8c = local_a0;
      AEMath::Matrix::operator*=((Matrix *)&local_64,(Matrix *)&local_a0);
      this = aAStack_dc;
      AEMath::MatrixGetInverse(this,(Matrix *)&local_64);
    }
    AEMath::Matrix::operator=((Matrix *)&local_64,this);
    uStack_84 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_80 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_7c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar4 = (undefined4 *)((uint)&local_a0 | 4);
    pEVar3 = *(Engine **)(param_1 + 0x34);
    local_a0 = 0x3f800000;
    *puVar4 = 0;
    puVar4[1] = uStack_84;
    puVar4[2] = uStack_80;
    puVar4[3] = uStack_7c;
    local_8c = 0x3f800000;
    local_88 = 0;
    local_78 = 0x3f800000;
    uStack_70 = 0x3f8000003f800000;
    local_68 = 0x3f800000;
    SpriteSystemDraw(pEVar3,(Matrix *)&local_a0,(Matrix *)&local_64,
                     *(SpriteSystem **)(*(int *)(param_1 + 0x184) + param_2 * 4));
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawSpriteSystem  @0x00084f30  (404 bytes)
/* AbyssEngine::PaintCanvas::DrawSpriteSystem(unsigned int, AbyssEngine::AEMath::Matrix,
   AbyssEngine::AEMath::Matrix) */

void AbyssEngine::PaintCanvas::DrawSpriteSystem
               (char *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
               undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
               undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
               undefined4 param_18,undefined4 param_19,undefined4 param_20,undefined4 param_21,
               undefined4 param_22,undefined4 param_23,undefined4 param_24,undefined4 param_25,
               undefined4 param_26,undefined4 param_27,undefined4 param_28,undefined4 param_29,
               undefined4 param_30,undefined4 param_31,undefined4 param_32)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint in_fpscr;
  float fVar4;
  float extraout_s0;
  AEMath aAStack_11c [60];
  undefined4 local_e0;
  uint local_dc;
  uint local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if ((param_2 < *(uint *)(param_1 + 0x180)) &&
     (*(int *)(*(int *)(param_1 + 0x184) + param_2 * 4) != 0)) {
    local_64 = param_18;
    local_60 = param_19;
    local_5c = param_20;
    local_58 = param_21;
    uStack_54 = param_22;
    local_50 = param_23;
    local_4c = param_24;
    local_48 = param_25;
    local_44 = param_26;
    local_40 = param_27;
    local_3c = param_28;
    local_38 = param_29;
    local_34 = param_30;
    local_30 = param_31;
    local_2c = param_32;
    uStack_98 = param_5;
    local_94 = param_6;
    uStack_90 = param_7;
    uStack_8c = param_8;
    local_88 = param_9;
    local_84 = param_10;
    local_80 = param_11;
    local_7c = param_12;
    local_78 = param_13;
    local_74 = param_14;
    local_70 = param_15;
    local_6c = param_16;
    local_68 = param_17;
    local_a0 = param_3;
    uStack_9c = param_4;
    if (*param_1 == '\0') {
      AEMath::MatrixGetInverse((AEMath *)&local_e0,(Matrix *)&local_64);
      AEMath::Matrix::operator=((Matrix *)&local_64,(AEMath *)&local_e0);
    }
    else {
      uStack_c4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_c0 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_bc = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar3 = (undefined4 *)((uint)&local_e0 | 4);
      local_e0 = 0x3f800000;
      *puVar3 = 0;
      puVar3[1] = uStack_c4;
      puVar3[2] = uStack_c0;
      puVar3[3] = uStack_bc;
      local_cc = 0x3f800000;
      local_c8 = 0;
      local_b8 = 0x3f800000;
      uStack_b0 = 0x3f8000003f800000;
      local_a8 = 0x3f800000;
      AEMath::MatrixIdentity(aAStack_11c,(Matrix *)&local_e0);
      iVar1 = Engine::GetGravValue(*(Engine **)(param_1 + 0x34));
      iVar1 = (int)(longlong)(*(double *)(iVar1 + 8) * -1.5707963705062866);
      if (*(int *)(param_1 + 0x30) == 1) {
        iVar1 = -iVar1;
      }
      fVar4 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
      uVar2 = AEMath::Sinf(fVar4);
      local_e0 = AEMath::Cosf(extraout_s0);
      local_dc = uVar2 ^ 0x80000000;
      local_d0 = uVar2;
      local_cc = local_e0;
      AEMath::Matrix::operator*=((Matrix *)&local_64,(Matrix *)&local_e0);
      AEMath::MatrixGetInverse(aAStack_11c,(Matrix *)&local_64);
      AEMath::Matrix::operator=((Matrix *)&local_64,aAStack_11c);
      AEMath::Matrix::operator*=((Matrix *)&local_a0,(Matrix *)&local_e0);
    }
    SpriteSystemDraw(*(Engine **)(param_1 + 0x34),(Matrix *)&local_a0,(Matrix *)&local_64,
                     *(SpriteSystem **)(*(int *)(param_1 + 0x184) + param_2 * 4));
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformCreate  @0x000850f0  (354 bytes)
/* AbyssEngine::PaintCanvas::TransformCreate(unsigned short, unsigned int&) */

void __thiscall
AbyssEngine::PaintCanvas::TransformCreate(PaintCanvas *this,ushort param_1,uint *param_2)

{
  Transform *this_00;
  void *pvVar1;
  uint uVar2;
  ushort uVar3;
  ushort *puVar4;
  undefined4 uVar5;
  Matrix *pMVar6;
  uint local_30;
  uint local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  if (*(uint *)(this + 0x134) != 0) {
    uVar2 = 0;
    do {
      puVar4 = *(ushort **)(*(int *)(this + 0x138) + uVar2 * 4);
      if ((puVar4 != (ushort *)0x0) && (*puVar4 == param_1)) {
        if (*(uint *)(puVar4 + 4) == 0xffffffff) {
          pMVar6 = *(Matrix **)(puVar4 + 6);
          this_00 = operator_new(0x180);
          Transform::Transform(this_00);
          *(int *)(this + 0x160) = *(int *)(this + 0x158) + 1;
          pvVar1 = realloc(*(void **)(this + 0x15c),(*(int *)(this + 0x158) + 1) * 4);
          *(void **)(this + 0x15c) = pvVar1;
          *(Transform **)((int)pvVar1 + *(int *)(this + 0x158) * 4) = this_00;
          *(int *)(this + 0x158) = *(int *)(this + 0x160);
          uVar2 = *(int *)(this + 0x160) - 1;
          *(uint *)(puVar4 + 4) = uVar2;
          *param_2 = uVar2;
          AEMath::Matrix::operator=((Matrix *)this_00,pMVar6);
          if (*(short *)(pMVar6 + 0x3c) != 0) {
            uVar3 = 0;
            do {
              local_2c = 0xffffffff;
              MeshCreate(this,*(ushort *)(*(int *)(pMVar6 + 0x40) + (uint)uVar3 * 2),&local_2c,false
                        );
              if (local_2c != 0xffffffff) {
                uVar5 = *(undefined4 *)(*(int *)(this + 0x28) + local_2c * 4);
                *(int *)(this_00 + 0x44) = *(int *)(this_00 + 0x3c) + 1;
                pvVar1 = realloc(*(void **)(this_00 + 0x40),(*(int *)(this_00 + 0x3c) + 1) * 4);
                *(void **)(this_00 + 0x40) = pvVar1;
                *(undefined4 *)((int)pvVar1 + *(int *)(this_00 + 0x3c) * 4) = uVar5;
                *(undefined4 *)(this_00 + 0x3c) = *(undefined4 *)(this_00 + 0x44);
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < *(ushort *)(pMVar6 + 0x3c));
          }
          if (*(short *)(pMVar6 + 0x44) != 0) {
            uVar3 = 0;
            do {
              local_30 = 0xffffffff;
              TransformCreate(this,*(ushort *)(*(int *)(pMVar6 + 0x48) + (uint)uVar3 * 2),&local_30)
              ;
              if (local_30 != 0xffffffff) {
                uVar5 = *(undefined4 *)(*(int *)(this + 0x15c) + local_30 * 4);
                *(int *)(this_00 + 0x54) = *(int *)(this_00 + 0x4c) + 1;
                pvVar1 = realloc(*(void **)(this_00 + 0x50),(*(int *)(this_00 + 0x4c) + 1) * 4);
                *(void **)(this_00 + 0x50) = pvVar1;
                *(undefined4 *)((int)pvVar1 + *(int *)(this_00 + 0x4c) * 4) = uVar5;
                *(undefined4 *)(this_00 + 0x4c) = *(undefined4 *)(this_00 + 0x54);
              }
              uVar3 = uVar3 + 1;
            } while (uVar3 < *(ushort *)(pMVar6 + 0x44));
          }
        }
        else {
          *param_2 = *(uint *)(puVar4 + 4);
        }
        break;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(this + 0x134));
  }
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::TransformCreate  @0x00085268  (72 bytes)
/* AbyssEngine::PaintCanvas::TransformCreate(unsigned int&) */

void __thiscall AbyssEngine::PaintCanvas::TransformCreate(PaintCanvas *this,uint *param_1)

{
  Transform *this_00;
  void *pvVar1;
  
  this_00 = operator_new(0x180);
  Transform::Transform(this_00);
  *(int *)(this + 0x160) = *(int *)(this + 0x158) + 1;
  pvVar1 = realloc(*(void **)(this + 0x15c),(*(int *)(this + 0x158) + 1) * 4);
  *(void **)(this + 0x15c) = pvVar1;
  *(Transform **)((int)pvVar1 + *(int *)(this + 0x158) * 4) = this_00;
  *(int *)(this + 0x158) = *(int *)(this + 0x160);
  *param_1 = *(int *)(this + 0x160) - 1;
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformAddMesh  @0x000852c0  (214 bytes)
/* AbyssEngine::PaintCanvas::TransformAddMesh(unsigned int, unsigned short, bool) */

void __thiscall
AbyssEngine::PaintCanvas::TransformAddMesh
          (PaintCanvas *this,uint param_1,ushort param_2,bool param_3)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  uint local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (param_1 < *(uint *)(this + 0x158)) {
    local_24 = 0xffffffff;
    MeshCreate(this,param_2,&local_24,param_3);
    uVar1 = local_24;
    if (local_24 != 0xffffffff) {
      iVar5 = *(int *)(*(int *)(this + 0x15c) + param_1 * 4);
      uVar7 = *(undefined4 *)(*(int *)(this + 0x28) + local_24 * 4);
      iVar3 = *(int *)(iVar5 + 0x3c) + 1;
      *(int *)(iVar5 + 0x44) = iVar3;
      pvVar2 = realloc(*(void **)(iVar5 + 0x40),iVar3 * 4);
      *(void **)(iVar5 + 0x40) = pvVar2;
      *(undefined4 *)((int)pvVar2 + *(int *)(iVar5 + 0x3c) * 4) = uVar7;
      *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x44);
      AEMath::BSphere::Merge
                ((BSphere *)(*(int *)(*(int *)(this + 0x15c) + param_1 * 4) + 0xd4),
                 (BSphere *)(*(int *)(*(int *)(this + 0x28) + uVar1 * 4) + 0x3c));
      iVar3 = *(int *)(*(int *)(*(int *)(this + 0x28) + uVar1 * 4) + 0x34);
      if (iVar3 != 0) {
        iVar4 = *(int *)(iVar3 + 0xfc);
        iVar5 = *(int *)(*(int *)(this + 0x15c) + param_1 * 4);
        iVar6 = *(int *)(iVar5 + 0xfc);
        bVar8 = *(uint *)(iVar5 + 0xf8) < *(uint *)(iVar3 + 0xf8);
        iVar3 = (iVar6 - iVar4) - (uint)bVar8;
        if (iVar3 < 0 != (SBORROW4(iVar6,iVar4) != SBORROW4(iVar6 - iVar4,(uint)bVar8))) {
          Transform::SetAnimationLength(CONCAT44(iVar3,iVar5));
          iVar5 = *(int *)(*(int *)(this + 0x15c) + param_1 * 4);
        }
        Transform::SetAnimationState(iVar5,2,0);
      }
      Transform::CollectAnimationData(*(Transform **)(*(int *)(this + 0x15c) + param_1 * 4));
    }
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformRemoveMesh  @0x000853a0  (60 bytes)
/* AbyssEngine::PaintCanvas::TransformRemoveMesh(unsigned int, unsigned short) */

void __thiscall
AbyssEngine::PaintCanvas::TransformRemoveMesh(PaintCanvas *this,uint param_1,ushort param_2)

{
  uint uVar1;
  ushort *puVar2;
  
  if (param_1 < *(uint *)(this + 0x158)) {
    if (*(uint *)(this + 0x134) == 0) {
      return;
    }
    uVar1 = 0;
    do {
      puVar2 = *(ushort **)(*(int *)(this + 0x138) + uVar1 * 4);
      if ((puVar2 != (ushort *)0x0) && (*puVar2 == param_2)) {
        TransformRemoveMeshId(this,param_1,*(uint *)(puVar2 + 4));
        return;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(this + 0x134));
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformRemoveMeshId  @0x000853da  (38 bytes)
/* AbyssEngine::PaintCanvas::TransformRemoveMeshId(unsigned int, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::TransformRemoveMeshId(PaintCanvas *this,uint param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  
  bVar2 = param_1 <= *(uint *)(this + 0x158);
  bVar1 = *(uint *)(this + 0x158) == param_1;
  if (bVar2 && !bVar1) {
    bVar2 = param_2 <= *(uint *)(this + 0x24);
    bVar1 = *(uint *)(this + 0x24) == param_2;
  }
  if (!bVar2 || bVar1) {
    return;
  }
  ArrayRemove<AbyssEngine::Mesh*>
            (*(Mesh **)(*(int *)(this + 0x28) + param_2 * 4),
             (Array *)(*(int *)(*(int *)(this + 0x15c) + param_1 * 4) + 0x3c));
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformAddMeshId  @0x000853fe  (210 bytes)
/* AbyssEngine::PaintCanvas::TransformAddMeshId(unsigned int, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::TransformAddMeshId(PaintCanvas *this,uint param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  
  bVar10 = param_1 <= *(uint *)(this + 0x158);
  bVar9 = *(uint *)(this + 0x158) == param_1;
  if (bVar10 && !bVar9) {
    bVar10 = param_2 <= *(uint *)(this + 0x24);
    bVar9 = *(uint *)(this + 0x24) == param_2;
  }
  if (!bVar10 || bVar9) {
    return;
  }
  iVar5 = *(int *)(*(int *)(this + 0x15c) + param_1 * 4);
  uVar8 = *(undefined4 *)(*(int *)(this + 0x28) + param_2 * 4);
  iVar2 = *(int *)(iVar5 + 0x3c) + 1;
  *(int *)(iVar5 + 0x44) = iVar2;
  pvVar1 = realloc(*(void **)(iVar5 + 0x40),iVar2 * 4);
  *(void **)(iVar5 + 0x40) = pvVar1;
  *(undefined4 *)((int)pvVar1 + *(int *)(iVar5 + 0x3c) * 4) = uVar8;
  *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x44);
  AEMath::BSphere::Merge
            ((BSphere *)(*(int *)(*(int *)(this + 0x15c) + param_1 * 4) + 0xd4),
             (BSphere *)(*(int *)(*(int *)(this + 0x28) + param_2 * 4) + 0x3c));
  iVar2 = *(int *)(*(int *)(*(int *)(this + 0x28) + param_2 * 4) + 0x34);
  if (iVar2 != 0) {
    iVar4 = *(int *)(iVar2 + 0xfc);
    iVar5 = *(int *)(*(int *)(this + 0x15c) + param_1 * 4);
    iVar6 = *(int *)(iVar5 + 0xfc);
    bVar9 = *(uint *)(iVar5 + 0xf8) < *(uint *)(iVar2 + 0xf8);
    iVar2 = (iVar6 - iVar4) - (uint)bVar9;
    if (iVar2 < 0 != (SBORROW4(iVar6,iVar4) != SBORROW4(iVar6 - iVar4,(uint)bVar9))) {
      Transform::SetAnimationLength(CONCAT44(iVar2,iVar5));
      iVar5 = *(int *)(*(int *)(this + 0x15c) + param_1 * 4);
    }
    uVar7 = *(uint *)(iVar5 + 0x100);
    iVar4 = *(int *)(iVar5 + 0x104);
    iVar2 = *(int *)(*(int *)(*(int *)(this + 0x28) + param_2 * 4) + 0x34);
    uVar3 = *(uint *)(iVar2 + 0x100);
    iVar2 = *(int *)(iVar2 + 0x104);
    if ((uVar7 == 0 && iVar4 == 0) ||
       ((int)((iVar2 - iVar4) - (uint)(uVar3 < uVar7)) < 0 !=
        (SBORROW4(iVar2,iVar4) != SBORROW4(iVar2 - iVar4,(uint)(uVar3 < uVar7))))) {
      *(uint *)(iVar5 + 0x100) = uVar3;
      *(int *)(iVar5 + 0x104) = iVar2;
    }
    Transform::SetAnimationState(iVar5,2,0);
  }
  Transform::CollectAnimationData(*(Transform **)(*(int *)(this + 0x15c) + param_1 * 4));
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformSetLocal  @0x00085512  (24 bytes)
/* AbyssEngine::PaintCanvas::TransformSetLocal(unsigned int, AbyssEngine::AEMath::Matrix const&) */

void __thiscall
AbyssEngine::PaintCanvas::TransformSetLocal(PaintCanvas *this,uint param_1,Matrix *param_2)

{
  if (param_1 < *(uint *)(this + 0x158)) {
    AEMath::Matrix::operator=(*(Matrix **)(*(int *)(this + 0x15c) + param_1 * 4),param_2);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformAddChild  @0x0008552a  (112 bytes)
/* AbyssEngine::PaintCanvas::TransformAddChild(unsigned int, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::TransformAddChild(PaintCanvas *this,uint param_1,uint param_2)

{
  PaintCanvas *pPVar1;
  PaintCanvas *pPVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  pPVar2 = (PaintCanvas *)param_1;
  pPVar1 = this;
  if (param_1 != param_2) {
    pPVar2 = *(PaintCanvas **)(this + 0x158);
    pPVar1 = pPVar2;
  }
  if ((param_2 <= pPVar2 && (param_1 != param_2 && pPVar1 != (PaintCanvas *)param_2)) &&
     (param_1 < pPVar1)) {
    iVar5 = *(int *)(*(int *)(this + 0x15c) + param_1 * 4);
    uVar6 = *(undefined4 *)(*(int *)(this + 0x15c) + param_2 * 4);
    iVar4 = *(int *)(iVar5 + 0x4c) + 1;
    *(int *)(iVar5 + 0x54) = iVar4;
    pvVar3 = realloc(*(void **)(iVar5 + 0x50),iVar4 * 4);
    *(void **)(iVar5 + 0x50) = pvVar3;
    *(undefined4 *)((int)pvVar3 + *(int *)(iVar5 + 0x4c) * 4) = uVar6;
    *(undefined4 *)(iVar5 + 0x4c) = *(undefined4 *)(iVar5 + 0x54);
    AEMath::BSphere::Merge
              ((BSphere *)(*(int *)(*(int *)(this + 0x15c) + param_1 * 4) + 0xd4),
               *(Transform **)(*(int *)(this + 0x15c) + param_2 * 4));
    Transform::CollectAnimationData(*(Transform **)(*(int *)(this + 0x15c) + param_1 * 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformRemoveChild  @0x0008559a  (64 bytes)
/* AbyssEngine::PaintCanvas::TransformRemoveChild(unsigned int, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::TransformRemoveChild(PaintCanvas *this,uint param_1,uint param_2)

{
  PaintCanvas *pPVar1;
  PaintCanvas *pPVar2;
  
  pPVar2 = (PaintCanvas *)param_1;
  pPVar1 = this;
  if (param_1 != param_2) {
    pPVar2 = *(PaintCanvas **)(this + 0x158);
    pPVar1 = pPVar2;
  }
  if (param_2 <= pPVar2 && (param_1 != param_2 && pPVar1 != (PaintCanvas *)param_2)) {
    if (pPVar1 <= param_1) {
      return;
    }
    ArrayRemove<AbyssEngine::Transform*>
              (*(Transform **)(*(int *)(this + 0x15c) + param_2 * 4),
               (Array *)(*(int *)(*(int *)(this + 0x15c) + param_1 * 4) + 0x4c));
    Transform::CollectAnimationData(*(Transform **)(*(int *)(this + 0x15c) + param_1 * 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformGetLocal  @0x0008561c  (70 bytes)
/* AbyssEngine::PaintCanvas::TransformGetLocal(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::TransformGetLocal(PaintCanvas *this,uint param_1)

{
  AEMath aAStack_50 [60];
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (*(uint *)(this + 0x158) <= param_1) {
    AEMath::MatrixIdentity(aAStack_50,this + 0xf8);
  }
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== AbyssEngine::PaintCanvas::TransformSetColor  @0x0008566c  (20 bytes)
/* AbyssEngine::PaintCanvas::TransformSetColor(unsigned int, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::TransformSetColor(PaintCanvas *this,uint param_1,uint param_2)

{
  PaintCanvas *pPVar1;
  
  pPVar1 = this + 0x158;
  if (param_1 < *(uint *)pPVar1) {
    this = *(PaintCanvas **)(*(int *)(this + 0x15c) + param_1 * 4);
  }
  if (param_1 < *(uint *)pPVar1) {
    *(uint *)(this + 0x48) = param_2;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformGet2DPickedTextureRegion  @0x00085680  (388 bytes)
/* AbyssEngine::PaintCanvas::TransformGet2DPickedTextureRegion(AbyssEngine::Transform*, int, int,
   int, int) */

void AbyssEngine::PaintCanvas::TransformGet2DPickedTextureRegion
               (Transform *param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  float in_s1;
  float extraout_s1;
  Mesh *pMVar8;
  undefined4 uVar9;
  float fVar10;
  int in_stack_00000004;
  uint in_stack_00000008;
  AEMath aAStack_a0 [12];
  float local_94;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int local_4c;
  
  local_4c = __stack_chk_guard;
  if (*(int *)(param_3 + 0x3c) != 0) {
    uVar3 = 0;
    fVar6 = (float)VectorSignedToFloat((in_stack_00000004 >> (in_stack_00000008 & 0xff)) >>
                                       (in_stack_00000008 & 0xff),(byte)(in_fpscr >> 0x16) & 3);
    pMVar8 = (Mesh *)VectorSignedToFloat((param_4 >> (in_stack_00000008 & 0xff)) >>
                                         (in_stack_00000008 & 0xff),(byte)(in_fpscr >> 0x16) & 3);
    do {
      MeshIntersect((AbyssEngine *)param_1,fVar6,in_s1,pMVar8);
      fVar6 = *(float *)param_1;
      uVar2 = in_fpscr & 0xfffffff;
      in_fpscr = uVar2 | (uint)(fVar6 == -1.0) << 0x1e;
      bVar5 = (byte)(in_fpscr >> 0x1e);
      if (bVar5 == 0) {
        fVar6 = *(float *)(param_1 + 4);
        in_fpscr = uVar2 | (uint)(fVar6 == -1.0) << 0x1e;
        bVar5 = (byte)(in_fpscr >> 0x1e);
      }
      if (bVar5 == 0) goto LAB_000857e6;
      uVar3 = uVar3 + 1;
      in_s1 = extraout_s1;
    } while (uVar3 < *(uint *)(param_3 + 0x3c));
  }
  if (*(int *)(param_3 + 0x4c) != 0) {
    uVar9 = VectorSignedToFloat(in_stack_00000004,(byte)(in_fpscr >> 0x16) & 3);
    uVar3 = 0;
    fVar6 = (float)VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x16) & 3);
    fVar10 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
    do {
      puVar4 = *(undefined4 **)(*(int *)(param_3 + 0x50) + uVar3 * 4);
      local_88 = *puVar4;
      uStack_84 = puVar4[1];
      uStack_80 = puVar4[2];
      uStack_7c = puVar4[3];
      uStack_78 = puVar4[4];
      local_74 = puVar4[5];
      uStack_70 = puVar4[6];
      uStack_6c = puVar4[7];
      uStack_68 = puVar4[8];
      uStack_64 = puVar4[9];
      local_60 = puVar4[10];
      uStack_5c = puVar4[0xb];
      uStack_58 = puVar4[0xc];
      uStack_54 = puVar4[0xd];
      uStack_50 = puVar4[0xe];
      local_94 = fVar10;
      local_90 = fVar6;
      local_8c = uVar9;
      AEMath::MatrixInverseTransformVector(aAStack_a0,(Matrix *)&local_88,(Vector *)&local_94);
      AEMath::Vector::operator=((Vector *)&local_94,(Vector *)aAStack_a0);
      TransformGet2DPickedTextureRegion
                (param_1,param_2,*(int *)(*(int *)(param_3 + 0x50) + uVar3 * 4),(int)local_94,
                 (int)local_90);
      fVar7 = *(float *)param_1;
      bVar1 = fVar7 != -1.0;
      if (bVar1) {
        fVar7 = *(float *)(param_1 + 4);
      }
      if (bVar1 && (bVar1 && fVar7 != -1.0)) goto LAB_000857e6;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_3 + 0x4c));
  }
  *(undefined4 *)param_1 = 0xbf800000;
  *(undefined4 *)(param_1 + 4) = 0xbf800000;
LAB_000857e6:
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformGet2DPickedTextureRegion  @0x0008580c  (232 bytes)
/* AbyssEngine::PaintCanvas::TransformGet2DPickedTextureRegion(unsigned int, int, int, int, int) */

void __thiscall
AbyssEngine::PaintCanvas::TransformGet2DPickedTextureRegion
          (PaintCanvas *this,uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  uint in_fpscr;
  AEMath aAStack_80 [12];
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  uVar1 = *(uint *)(param_1 + 0x158);
  if ((uint)param_2 < uVar1) {
    local_74 = (float)VectorSignedToFloat(param_3,(byte)(in_fpscr >> 0x16) & 3);
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x15c) + param_2 * 4);
    local_70 = (float)VectorSignedToFloat(param_4,(byte)(in_fpscr >> 0x16) & 3);
    local_6c = VectorSignedToFloat(param_5,(byte)(in_fpscr >> 0x16) & 3);
    local_68 = *puVar2;
    uStack_64 = puVar2[1];
    uStack_60 = puVar2[2];
    uStack_5c = puVar2[3];
    uStack_58 = puVar2[4];
    local_54 = puVar2[5];
    uStack_50 = puVar2[6];
    uStack_4c = puVar2[7];
    uStack_48 = puVar2[8];
    uStack_44 = puVar2[9];
    local_40 = puVar2[10];
    uStack_3c = puVar2[0xb];
    uStack_38 = puVar2[0xc];
    uStack_34 = puVar2[0xd];
    uStack_30 = puVar2[0xe];
    AEMath::MatrixInverseTransformVector(aAStack_80,(Matrix *)&local_68,(Vector *)&local_74);
    AEMath::Vector::operator=((Vector *)&local_74,(Vector *)aAStack_80);
    TransformGet2DPickedTextureRegion
              ((Transform *)this,param_1,(int)puVar2,(int)local_74,(int)local_70);
  }
  else {
    *(undefined4 *)this = 0xbf800000;
    *(undefined4 *)(this + 4) = 0xbf800000;
    fprintf((FILE *)glColorMask,"TransformGet2DPickedTextureRegion Error %d >= %d\n",param_2,uVar1);
  }
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::TransformGetTransform  @0x00085908  (20 bytes)
/* AbyssEngine::PaintCanvas::TransformGetTransform(unsigned int) */

undefined4 __thiscall
AbyssEngine::PaintCanvas::TransformGetTransform(PaintCanvas *this,uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < *(uint *)(this + 0x158)) {
    uVar1 = *(undefined4 *)(*(int *)(this + 0x15c) + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== AbyssEngine::PaintCanvas::TransformGetTriCount  @0x0008591c  (26 bytes)
/* AbyssEngine::PaintCanvas::TransformGetTriCount(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::TransformGetTriCount(PaintCanvas *this,uint param_1)

{
  if (*(uint *)(this + 0x158) <= param_1) {
    return;
  }
  TransformGetTriCount(this,*(Transform **)(*(int *)(this + 0x15c) + param_1 * 4));
  return;
}

// ===== AbyssEngine::PaintCanvas::CameraCreate  @0x00085940  (174 bytes)
/* AbyssEngine::PaintCanvas::CameraCreate(unsigned int&) */

void __thiscall AbyssEngine::PaintCanvas::CameraCreate(PaintCanvas *this,uint *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint in_fpscr;
  float fVar5;
  float extraout_s1;
  float fVar6;
  float extraout_s3;
  float extraout_s4;
  
  pvVar1 = operator_new(0x5c);
  uVar2 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
  uVar3 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
  fVar5 = (float)VectorSignedToFloat(uVar2,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x3f800000;
  fVar6 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)((int)pvVar1 + 0x10) = 0;
  *(undefined4 *)((int)pvVar1 + 0x14) =
       *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)((int)pvVar1 + 0x18) =
       *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)((int)pvVar1 + 0x1c) =
       *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)((int)pvVar1 + 0x20) = 0x3f800000;
  *(undefined4 *)((int)pvVar1 + 0x24) = 0;
  *(undefined4 *)((int)pvVar1 + 0x28) =
       *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)((int)pvVar1 + 0x2c) =
       *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)((int)pvVar1 + 0x30) =
       *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined8 *)((int)pvVar1 + 0x34) = 0x3f800000;
  *(undefined8 *)((int)pvVar1 + 0x3c) = 0x3f8000003f800000;
  *(undefined4 *)((int)pvVar1 + 0x44) = 0x3f800000;
  AbyssEngine::CameraSetPerspective
            (fVar5,extraout_s1,fVar6,extraout_s3,extraout_s4,(Camera *)0x45fa0000);
  *(int *)(this + 0x16c) = *(int *)(this + 0x164) + 1;
  pvVar4 = realloc(*(void **)(this + 0x168),(*(int *)(this + 0x164) + 1) * 4);
  *(void **)(this + 0x168) = pvVar4;
  *(void **)((int)pvVar4 + *(int *)(this + 0x164) * 4) = pvVar1;
  *(int *)(this + 0x164) = *(int *)(this + 0x16c);
  *param_1 = *(int *)(this + 0x16c) - 1;
  return;
}

// ===== AbyssEngine::PaintCanvas::CameraSetLocal  @0x00085a10  (26 bytes)
/* AbyssEngine::PaintCanvas::CameraSetLocal(unsigned int, AbyssEngine::AEMath::Matrix const&) */

void __thiscall
AbyssEngine::PaintCanvas::CameraSetLocal(PaintCanvas *this,uint param_1,Matrix *param_2)

{
  if (param_1 < *(uint *)(this + 0x164)) {
    AEMath::Matrix::operator=
              ((Matrix *)(*(int *)(*(int *)(this + 0x168) + param_1 * 4) + 0xc),param_2);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::CameraGetLocal  @0x00085a2c  (74 bytes)
/* AbyssEngine::PaintCanvas::CameraGetLocal(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::CameraGetLocal(PaintCanvas *this,uint param_1)

{
  AEMath aAStack_50 [60];
  int local_14;
  
  local_14 = __stack_chk_guard;
  if (*(uint *)(this + 0x164) <= param_1) {
    AEMath::MatrixIdentity(aAStack_50,this + 0xf8);
  }
  if (__stack_chk_guard - local_14 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_14);
}

// ===== AbyssEngine::PaintCanvas::CameraSetCurrent  @0x00085a80  (28 bytes)
/* AbyssEngine::PaintCanvas::CameraSetCurrent(unsigned int) */

void AbyssEngine::PaintCanvas::CameraSetCurrent(uint param_1)

{
  uint in_r1;
  float in_s0;
  float in_s1;
  float in_s2;
  
  *(uint *)(param_1 + 0x170) = in_r1;
  if (in_r1 < *(uint *)(param_1 + 0x164)) {
    SetProjectionMatrix3d((PaintCanvas *)param_1,in_s0,in_s1,in_s2);
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SetProjectionMatrix3d  @0x00085a9c  (330 bytes)
/* AbyssEngine::PaintCanvas::SetProjectionMatrix3d(float, float, float) */

void __thiscall
AbyssEngine::PaintCanvas::SetProjectionMatrix3d
          (PaintCanvas *this,float param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  undefined4 in_r1;
  float in_r2;
  float in_r3;
  uint in_fpscr;
  float extraout_s0;
  float extraout_s0_00;
  float fVar8;
  float fVar9;
  
  i_fov = in_r1;
  i_zNear = in_r2;
  i_zFar = in_r3;
  Engine::nearPlane = in_r2;
  Engine::farPlane = in_r3;
  uVar4 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
  uVar5 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
  fVar6 = (float)AEMath::Sinf(extraout_s0);
  fVar7 = (float)AEMath::Cosf(extraout_s0_00);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  fVar8 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
  fVar9 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = uVar1;
  *(undefined4 *)(this + 0x70) = uVar2;
  *(undefined4 *)(this + 0x74) = uVar3;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = uVar1;
  *(undefined4 *)(this + 0x60) = uVar2;
  *(undefined4 *)(this + 100) = uVar3;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = uVar1;
  *(undefined4 *)(this + 0x50) = uVar2;
  *(undefined4 *)(this + 0x54) = uVar3;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = uVar1;
  *(undefined4 *)(this + 0x40) = uVar2;
  *(undefined4 *)(this + 0x44) = uVar3;
  if (3 < *(uint *)(this + 0x30)) goto LAB_00085ba8;
  fVar8 = fVar8 / fVar9;
  fVar6 = 1.0 / (fVar6 / fVar7);
  switch(*(uint *)(this + 0x30)) {
  case 0:
    fVar8 = fVar6 / fVar8;
    fVar6 = -fVar6;
    break;
  case 1:
    fVar8 = -(fVar6 / fVar8);
    break;
  case 2:
    fVar8 = fVar6 / fVar8;
    goto LAB_00085ba0;
  case 3:
    fVar8 = -(fVar6 / fVar8);
    fVar6 = -fVar6;
LAB_00085ba0:
    *(float *)(this + 0x38) = fVar8;
    *(float *)(this + 0x4c) = fVar6;
    goto LAB_00085ba8;
  }
  *(float *)(this + 0x3c) = fVar8;
  *(float *)(this + 0x48) = fVar6;
LAB_00085ba8:
  *(float *)(this + 0x60) = (in_r2 + in_r3) / (in_r2 - in_r3);
  *(undefined4 *)(this + 100) = 0xbf800000;
  *(float *)(this + 0x70) = (in_r2 * (in_r3 + in_r3)) / (in_r2 - in_r3);
  return;
}

// ===== AbyssEngine::PaintCanvas::CameraGetCurrent  @0x00085c00  (18 bytes)
/* AbyssEngine::PaintCanvas::CameraGetCurrent() */

uint __thiscall AbyssEngine::PaintCanvas::CameraGetCurrent(PaintCanvas *this)

{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x170);
  if (*(uint *)(this + 0x164) <= uVar1) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

// ===== AbyssEngine::PaintCanvas::CameraGetCurrentFactor1  @0x00085c12  (36 bytes)
/* AbyssEngine::PaintCanvas::CameraGetCurrentFactor1() */

undefined4 __thiscall AbyssEngine::PaintCanvas::CameraGetCurrentFactor1(PaintCanvas *this)

{
  undefined4 uVar1;
  
  if (*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(this + 0x168) + *(uint *)(this + 0x170) * 4) + 0x48);
  }
  else {
    uVar1 = 0x3f800000;
  }
  return uVar1;
}

// ===== AbyssEngine::PaintCanvas::CameraSetPerspective  @0x00085c36  (126 bytes)
/* AbyssEngine::PaintCanvas::CameraSetPerspective(unsigned int, float, float, float) */

float AbyssEngine::PaintCanvas::CameraSetPerspective
                (uint param_1,float param_2,float param_3,float param_4)

{
  undefined4 uVar1;
  uint in_r1;
  Camera *in_r2;
  uint in_fpscr;
  float fVar2;
  float extraout_s1;
  float extraout_s2;
  float extraout_s3;
  float extraout_s4;
  
  if (in_r1 < *(uint *)(param_1 + 0x164)) {
    uVar1 = Engine::GetDisplayWidth(*(Engine **)(param_1 + 0x34));
    VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    uVar1 = Engine::GetDisplayHeight(*(Engine **)(param_1 + 0x34));
    fVar2 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    param_2 = (float)AbyssEngine::CameraSetPerspective
                               (fVar2,extraout_s1,extraout_s2,extraout_s3,extraout_s4,in_r2);
    if (*(uint *)(param_1 + 0x170) == in_r1) {
      fVar2 = (float)CameraSetCurrent(param_1);
      return fVar2;
    }
  }
  return param_2;
}

// ===== AbyssEngine::PaintCanvas::CameraSetPerspective  @0x00085cb4  (120 bytes)
/* AbyssEngine::PaintCanvas::CameraSetPerspective(unsigned int, float, float) */

float AbyssEngine::PaintCanvas::CameraSetPerspective(uint param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  uint in_r1;
  Camera *in_r2;
  uint in_fpscr;
  float fVar2;
  float extraout_s1;
  float extraout_s2;
  float extraout_s3;
  
  if (in_r1 < *(uint *)(param_1 + 0x164)) {
    uVar1 = Engine::GetDisplayWidth(*(Engine **)(param_1 + 0x34));
    VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    uVar1 = Engine::GetDisplayHeight(*(Engine **)(param_1 + 0x34));
    fVar2 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    param_2 = (float)AbyssEngine::CameraSetPerspective
                               (fVar2,extraout_s1,extraout_s2,extraout_s3,in_r2);
    if (*(uint *)(param_1 + 0x170) == in_r1) {
      fVar2 = (float)CameraSetCurrent(param_1);
      return fVar2;
    }
  }
  return param_2;
}

// ===== AbyssEngine::PaintCanvas::CameraIsPointinViewFrustum  @0x00085d30  (224 bytes)
/* AbyssEngine::PaintCanvas::CameraIsPointinViewFrustum(AbyssEngine::AEMath::Vector const&) */

void __thiscall
AbyssEngine::PaintCanvas::CameraIsPointinViewFrustum(PaintCanvas *this,Vector *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  Camera *pCVar6;
  float extraout_s0;
  AEMath aAStack_9c [60];
  undefined4 local_60;
  uint local_5c;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) {
    if (*this == (PaintCanvas)0x0) {
      pCVar6 = *(Camera **)(*(int *)(this + 0x168) + *(uint *)(this + 0x170) * 4);
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5 = &local_60;
      uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_40 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar4 = (undefined4 *)((uint)puVar5 | 4);
      local_60 = 0x3f800000;
      *puVar4 = 0;
      puVar4[1] = uStack_44;
      puVar4[2] = uStack_40;
      puVar4[3] = uStack_3c;
      local_4c = 0x3f800000;
      local_48 = 0;
      local_38 = 0x3f800000;
      uStack_30 = 0x3f8000003f800000;
      local_28 = 0x3f800000;
      AEMath::MatrixIdentity(aAStack_9c,(Matrix *)puVar5);
      iVar1 = Engine::GetGravValue(*(Engine **)(this + 0x34));
      uVar2 = AEMath::Sinf((float)(*(double *)(iVar1 + 8) * 1.5707963705062866));
      local_60 = AEMath::Cosf(extraout_s0);
      local_5c = uVar2 ^ 0x80000000;
      pCVar6 = *(Camera **)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4);
      local_50 = uVar2;
      local_4c = local_60;
    }
    uVar3 = AbyssEngine::CameraIsPointinViewFrustum(param_1,(Matrix *)puVar5,pCVar6);
  }
  else {
    uVar3 = 1;
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::CameraIsSphereinViewFrustum  @0x00085e30  (242 bytes)
/* AbyssEngine::PaintCanvas::CameraIsSphereinViewFrustum(AbyssEngine::AEMath::Vector const&, float)
    */

void __thiscall
AbyssEngine::PaintCanvas::CameraIsSphereinViewFrustum
          (PaintCanvas *this,Vector *param_1,float param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  Matrix *in_r2;
  Camera *pCVar5;
  float extraout_s0;
  Matrix *extraout_s0_00;
  Matrix *pMVar6;
  AEMath aAStack_9c [60];
  undefined4 local_60;
  uint local_5c;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (((float)in_r2 == 0.0) || (*(uint *)(this + 0x164) <= *(uint *)(this + 0x170))) {
    uVar3 = 1;
  }
  else {
    if (*this == (PaintCanvas)0x0) {
      pCVar5 = (Camera *)0x0;
      pMVar6 = in_r2;
    }
    else {
      pCVar5 = (Camera *)&local_60;
      uStack_44 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_40 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_3c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar4 = (undefined4 *)((uint)pCVar5 | 4);
      local_60 = 0x3f800000;
      *puVar4 = 0;
      puVar4[1] = uStack_44;
      puVar4[2] = uStack_40;
      puVar4[3] = uStack_3c;
      local_4c = 0x3f800000;
      local_48 = 0;
      local_38 = 0x3f800000;
      uStack_30 = 0x3f8000003f800000;
      local_28 = 0x3f800000;
      AEMath::MatrixIdentity(aAStack_9c,pCVar5);
      iVar1 = Engine::GetGravValue(*(Engine **)(this + 0x34));
      uVar2 = AEMath::Sinf((float)(*(double *)(iVar1 + 8) * 1.5707963705062866));
      local_60 = AEMath::Cosf(extraout_s0);
      local_5c = uVar2 ^ 0x80000000;
      pMVar6 = extraout_s0_00;
      local_50 = uVar2;
      local_4c = local_60;
    }
    uVar3 = AbyssEngine::CameraIsSphereinViewFrustum(param_1,(float)pMVar6,in_r2,pCVar5);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::GetScreenPosition  @0x00085f50  (96 bytes)
/* AbyssEngine::PaintCanvas::GetScreenPosition(AbyssEngine::AEMath::Vector const&,
   AbyssEngine::AEMath::Vector&) */

void __thiscall
AbyssEngine::PaintCanvas::GetScreenPosition(PaintCanvas *this,Vector *param_1,Vector *param_2)

{
  undefined4 *puVar1;
  undefined4 local_48 [5];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined4 local_10;
  int local_c;
  
  uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uStack_28 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uStack_24 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_c = __stack_chk_guard;
  puVar1 = (undefined4 *)((uint)local_48 | 4);
  local_48[0] = 0x3f800000;
  *puVar1 = 0;
  puVar1[1] = uStack_2c;
  puVar1[2] = uStack_28;
  puVar1[3] = uStack_24;
  local_34 = 0x3f800000;
  local_30 = 0;
  local_20 = 0x3f800000;
  uStack_18 = 0x3f8000003f800000;
  local_10 = 0x3f800000;
  GetScreenPosition(this,(Matrix *)local_48,param_1,param_2);
  if (__stack_chk_guard != local_c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::GetScreenPosition  @0x00085fd0  (598 bytes)
/* AbyssEngine::PaintCanvas::GetScreenPosition(AbyssEngine::AEMath::Matrix&,
   AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector&) */

void __thiscall
AbyssEngine::PaintCanvas::GetScreenPosition
          (PaintCanvas *this,Matrix *param_1,Vector *param_2,Vector *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  AEMath *this_00;
  AEMath *this_01;
  byte bVar6;
  byte bVar7;
  uint in_fpscr;
  uint uVar8;
  float extraout_s0;
  float fVar9;
  float fVar10;
  float unaff_s16;
  double dVar11;
  double dVar12;
  AEMath aAStack_dc [12];
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 local_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 local_90;
  uint local_8c;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  AEMath aAStack_50 [12];
  int local_44;
  
  local_44 = __stack_chk_guard;
  AEMath::MatrixTransformVector(aAStack_50,param_1,param_2);
  if (*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) {
    if (*this == (PaintCanvas)0x0) {
      this_01 = (AEMath *)&local_90;
      this_00 = (AEMath *)(*(int *)(*(int *)(this + 0x168) + *(uint *)(this + 0x170) * 4) + 0xc);
    }
    else {
      uStack_74 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uStack_70 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uStack_6c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      puVar5 = (undefined4 *)((uint)&local_90 | 4);
      this_00 = (AEMath *)&local_d0;
      local_90 = 0x3f800000;
      *puVar5 = 0;
      puVar5[1] = uStack_74;
      puVar5[2] = uStack_70;
      puVar5[3] = uStack_6c;
      local_7c = 0x3f800000;
      local_78 = 0;
      local_68 = 0x3f800000;
      uStack_60 = 0x3f8000003f800000;
      local_58 = 0x3f800000;
      AEMath::MatrixIdentity(this_00,(Matrix *)&local_90);
      iVar2 = Engine::GetGravValue(*(Engine **)(this + 0x34));
      uVar3 = AEMath::Sinf((float)(*(double *)(iVar2 + 8) * 1.5707963705062866));
      local_90 = AEMath::Cosf(extraout_s0);
      local_8c = uVar3 ^ 0x80000000;
      iVar2 = *(int *)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4);
      local_d0 = *(undefined4 *)(iVar2 + 0xc);
      uStack_cc = *(undefined4 *)(iVar2 + 0x10);
      uStack_c8 = *(undefined4 *)(iVar2 + 0x14);
      uStack_c4 = *(undefined4 *)(iVar2 + 0x18);
      uStack_c0 = *(undefined4 *)(iVar2 + 0x1c);
      local_bc = *(undefined4 *)(iVar2 + 0x20);
      uStack_b8 = *(undefined4 *)(iVar2 + 0x24);
      uStack_b4 = *(undefined4 *)(iVar2 + 0x28);
      uStack_b0 = *(undefined4 *)(iVar2 + 0x2c);
      uStack_ac = *(undefined4 *)(iVar2 + 0x30);
      local_a8 = *(undefined4 *)(iVar2 + 0x34);
      uStack_a4 = *(undefined4 *)(iVar2 + 0x38);
      uStack_a0 = *(undefined4 *)(iVar2 + 0x3c);
      uStack_9c = *(undefined4 *)(iVar2 + 0x40);
      uStack_98 = *(undefined4 *)(iVar2 + 0x44);
      local_80 = uVar3;
      local_7c = local_90;
      AEMath::Matrix::operator*=((Matrix *)this_00,(Matrix *)&local_90);
      this_01 = aAStack_dc;
    }
    AEMath::MatrixInverseTransformVector(this_01,this_00,(Vector *)aAStack_50);
    AEMath::Vector::operator=(param_3,(Vector *)this_01);
    fVar10 = *(float *)(param_3 + 8);
    iVar2 = *(int *)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4);
    if (fVar10 <= *(float *)(iVar2 + 4)) {
      fVar9 = fVar10 * *(float *)(iVar2 + 0x4c);
      uVar3 = in_fpscr & 0xfffffff | (uint)(fVar9 == 0.0) << 0x1e;
      bVar6 = (byte)(uVar3 >> 0x1e);
      if (bVar6 == 0) {
        unaff_s16 = fVar10 * *(float *)(iVar2 + 0x48);
        uVar3 = in_fpscr & 0xfffffff | (uint)(unaff_s16 == 0.0) << 0x1e;
        bVar6 = (byte)(uVar3 >> 0x1e);
      }
      if (bVar6 == 0) {
        fVar10 = *(float *)param_3;
        uVar4 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
        dVar11 = (double)VectorSignedToFloat(uVar4,(byte)(uVar3 >> 0x16) & 3);
        iVar2 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
        dVar12 = (double)VectorSignedToFloat(iVar2 >> 1,(byte)(uVar3 >> 0x16) & 3);
        *(float *)param_3 = (float)(dVar12 - (((double)fVar10 * 0.5) / (double)fVar9) * dVar11);
        fVar10 = *(float *)(param_3 + 4);
        uVar4 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
        dVar11 = (double)VectorSignedToFloat(uVar4,(byte)(uVar3 >> 0x16) & 3);
        iVar2 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
        dVar12 = (double)VectorSignedToFloat(iVar2 >> 1,(byte)(uVar3 >> 0x16) & 3);
        fVar10 = (float)((((double)fVar10 * 0.5) / (double)unaff_s16) * dVar11 + dVar12);
        *(float *)(param_3 + 4) = fVar10;
        fVar9 = *(float *)param_3;
        uVar1 = uVar3 & 0xfffffff | (uint)(fVar9 < 0.0) << 0x1f;
        uVar8 = uVar1 | (uint)NAN(fVar9) << 0x1c;
        bVar6 = (byte)(uVar1 >> 0x1f);
        bVar7 = (byte)(uVar8 >> 0x1c) & 1;
        if (bVar6 == bVar7) {
          uVar8 = uVar3 & 0xfffffff | (uint)(fVar10 < 0.0) << 0x1f | (uint)NAN(fVar10) << 0x1c;
          bVar7 = (byte)(uVar8 >> 0x18);
          bVar6 = bVar7 >> 7;
          bVar7 = bVar7 >> 4 & 1;
        }
        if (bVar6 == bVar7) {
          uVar4 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
          fVar10 = (float)VectorSignedToFloat(uVar4,(byte)(uVar8 >> 0x16) & 3);
          uVar8 = uVar8 & 0xfffffff;
          if (fVar9 < fVar10) {
            uVar4 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
            VectorSignedToFloat(uVar4,(byte)(uVar8 >> 0x16) & 3);
          }
        }
      }
    }
  }
  if (__stack_chk_guard - local_44 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_44);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::GetScreenPosition  @0x00086250  (396 bytes)
/* AbyssEngine::PaintCanvas::GetScreenPosition(AbyssEngine::AEMath::Matrix const&,
   AbyssEngine::AEMath::Vector&) */

void __thiscall
AbyssEngine::PaintCanvas::GetScreenPosition(PaintCanvas *this,Matrix *param_1,Vector *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  uint in_fpscr;
  uint uVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float unaff_s16;
  double dVar10;
  double dVar11;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  if (*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) {
    uStack_3c = *(undefined4 *)(param_1 + 0x1c);
    local_40 = *(undefined4 *)(param_1 + 0xc);
    local_38 = *(undefined4 *)(param_1 + 0x2c);
    AEMath::Vector::operator=(param_2,(Vector *)&local_40);
    iVar2 = *(int *)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4);
    fVar8 = *(float *)(iVar2 + 0x4c) * *(float *)(param_2 + 8);
    uVar6 = in_fpscr & 0xfffffff | (uint)(fVar8 == 0.0) << 0x1e;
    bVar4 = (byte)(uVar6 >> 0x1e);
    if (bVar4 == 0) {
      unaff_s16 = *(float *)(param_2 + 8) * *(float *)(iVar2 + 0x48);
      uVar6 = in_fpscr & 0xfffffff | (uint)(unaff_s16 == 0.0) << 0x1e;
      bVar4 = (byte)(uVar6 >> 0x1e);
    }
    if (bVar4 == 0) {
      fVar9 = *(float *)param_2;
      uVar3 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
      dVar10 = (double)VectorSignedToFloat(uVar3,(byte)(uVar6 >> 0x16) & 3);
      iVar2 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
      dVar11 = (double)VectorSignedToFloat(iVar2 >> 1,(byte)(uVar6 >> 0x16) & 3);
      *(float *)param_2 = (float)(dVar11 - (((double)fVar9 * 0.5) / (double)fVar8) * dVar10);
      fVar8 = *(float *)(param_2 + 4);
      uVar3 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      dVar10 = (double)VectorSignedToFloat(uVar3,(byte)(uVar6 >> 0x16) & 3);
      dVar10 = (((double)fVar8 * 0.5) / (double)unaff_s16) * dVar10;
      iVar2 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      dVar11 = (double)VectorSignedToFloat(iVar2 >> 1,(byte)(uVar6 >> 0x16) & 3);
      fVar8 = (float)(dVar10 + dVar11);
      *(float *)(param_2 + 4) = fVar8;
      if (*(float *)(param_2 + 8) <=
          *(float *)(*(int *)(*(int *)(this + 0x168) + *(int *)(this + 0x170) * 4) + 4)) {
        uVar1 = uVar6 & 0xfffffff | (uint)(fVar8 < 0.0) << 0x1f;
        uVar7 = uVar1 | (uint)NAN(fVar8) << 0x1c;
        bVar4 = (byte)(uVar1 >> 0x1f);
        bVar5 = (byte)(uVar7 >> 0x1c) & 1;
        fVar8 = SUB84(dVar10,0);
        if (bVar4 == bVar5) {
          fVar8 = *(float *)param_2;
          uVar7 = uVar6 & 0xfffffff | (uint)(fVar8 < 0.0) << 0x1f | (uint)NAN(fVar8) << 0x1c;
          bVar5 = (byte)(uVar7 >> 0x18);
          bVar4 = bVar5 >> 7;
          bVar5 = bVar5 >> 4 & 1;
        }
        if (bVar4 == bVar5) {
          uVar3 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
          fVar9 = (float)VectorSignedToFloat(uVar3,(byte)(uVar7 >> 0x16) & 3);
          uVar7 = uVar7 & 0xfffffff;
          if (fVar8 < fVar9) {
            uVar3 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
            VectorSignedToFloat(uVar3,(byte)(uVar7 >> 0x16) & 3);
          }
        }
      }
    }
  }
  if (__stack_chk_guard - local_34 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_34);
}

// ===== AbyssEngine::PaintCanvas::MaterialCreate  @0x000863e4  (86 bytes)
/* AbyssEngine::PaintCanvas::MaterialCreate(unsigned int&, AbyssEngine::BlendMode, unsigned int,
   unsigned short) */

void AbyssEngine::PaintCanvas::MaterialCreate
               (int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  Material *this;
  void *pvVar1;
  int iVar2;
  
  this = operator_new(0x74);
  Material::Material(this);
  *(undefined4 *)(this + 0x20) = param_3;
  *(undefined4 *)this = param_4;
  iVar2 = *(int *)(param_1 + 0x174) + 1;
  *(int *)(param_1 + 0x17c) = iVar2;
  pvVar1 = realloc(*(void **)(param_1 + 0x178),iVar2 * 4);
  *(void **)(param_1 + 0x178) = pvVar1;
  *(Material **)((int)pvVar1 + *(int *)(param_1 + 0x174) * 4) = this;
  *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x17c);
  *param_2 = *(int *)(param_1 + 0x17c) + -1;
  return;
}

// ===== AbyssEngine::PaintCanvas::MaterialChange  @0x0008658a  (22 bytes)
/* AbyssEngine::PaintCanvas::MaterialChange(unsigned int, AbyssEngine::BlendMode, unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::MaterialChange
          (PaintCanvas *this,uint param_1,undefined4 param_3,undefined4 param_4)

{
  PaintCanvas *pPVar1;
  
  pPVar1 = this + 0x174;
  if (param_1 < *(uint *)pPVar1) {
    this = *(PaintCanvas **)(*(int *)(this + 0x178) + param_1 * 4);
  }
  if (param_1 < *(uint *)pPVar1) {
    *(undefined4 *)(this + 0x20) = param_3;
    *(undefined4 *)this = param_4;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MaterialResourceChangeTexture  @0x000865a0  (76 bytes)
/* AbyssEngine::PaintCanvas::MaterialResourceChangeTexture(unsigned int, unsigned int, int) */

void __thiscall
AbyssEngine::PaintCanvas::MaterialResourceChangeTexture
          (PaintCanvas *this,uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  ushort *puVar2;
  
  if ((uint)param_3 < 8) {
    if (*(uint *)(this + 0x134) == 0) {
      return;
    }
    uVar1 = 0;
    do {
      puVar2 = *(ushort **)(*(int *)(this + 0x138) + uVar1 * 4);
      if ((puVar2 != (ushort *)0x0) && ((uint)*puVar2 == (param_1 & 0xffff))) {
        uVar1 = *(uint *)(puVar2 + 4);
        if (uVar1 == 0xffffffff) {
          return;
        }
        if (*(uint *)(this + 0x174) <= uVar1) {
          return;
        }
        *(uint *)(*(int *)(*(int *)(this + 0x178) + uVar1 * 4) + param_3 * 4) = param_2;
        return;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(this + 0x134));
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::MaterialGetMaterial  @0x000865ec  (20 bytes)
/* AbyssEngine::PaintCanvas::MaterialGetMaterial(unsigned int) */

undefined4 __thiscall AbyssEngine::PaintCanvas::MaterialGetMaterial(PaintCanvas *this,uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < *(uint *)(this + 0x174)) {
    uVar1 = *(undefined4 *)(*(int *)(this + 0x178) + param_1 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// ===== AbyssEngine::PaintCanvas::ChangeCubeTexture  @0x00086600  (98 bytes)
/* AbyssEngine::PaintCanvas::ChangeCubeTexture(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::ChangeCubeTexture(PaintCanvas *this,uint param_1)

{
  int iVar1;
  void *pvVar2;
  
  if ((Engine::enableShader != '\0') && (param_1 < *(uint *)(this + 0x10))) {
    iVar1 = *(int *)(*(int *)(this + 0x14) + param_1 * 4);
    if (*(char *)(iVar1 + 0x10) != '\0') {
      CubeMapSetIndex = param_1;
      glActiveTexture(0x84c7);
      glBindTexture(0x8513,**(undefined4 **)(*(int *)(this + 0x14) + param_1 * 4));
      glActiveTexture(0x84c0);
      return;
    }
    pvVar2 = (void *)String::GetAEChar((String *)(iVar1 + 4));
    if (pvVar2 != (void *)0x0) {
      operator_delete__(pvVar2);
      return;
    }
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::HasVibration  @0x00086668  (6 bytes)
/* AbyssEngine::PaintCanvas::HasVibration() */

void __thiscall AbyssEngine::PaintCanvas::HasVibration(PaintCanvas *this)

{
  Engine::HasVibration(*(Engine **)(this + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::Vibrate  @0x0008666e  (6 bytes)
/* AbyssEngine::PaintCanvas::Vibrate(unsigned short) */

void AbyssEngine::PaintCanvas::Vibrate(ushort param_1)

{
  Engine::Vibrate((ushort)*(undefined4 *)(param_1 + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::GetTextWidth  @0x00086674  (60 bytes)
/* AbyssEngine::PaintCanvas::GetTextWidth(unsigned int, AbyssEngine::String const&, unsigned int,
   unsigned int) */

undefined4 __thiscall
AbyssEngine::PaintCanvas::GetTextWidth
          (PaintCanvas *this,uint param_1,String *param_2,uint param_3,uint param_4)

{
  ushort *puVar1;
  undefined4 uVar2;
  ImageFont *pIVar3;
  
  if (*(uint *)(this + 0x140) <= param_1) {
    return 0;
  }
  pIVar3 = *(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4);
  puVar1 = String::operator_cast_to_unsigned_short_((String *)param_2);
  uVar2 = ImageFontGetWidth(pIVar3,puVar1,param_3,param_4 - param_3);
  return uVar2;
}

// ===== AbyssEngine::PaintCanvas::GetTextHeight  @0x000866ae  (26 bytes)
/* AbyssEngine::PaintCanvas::GetTextHeight(unsigned int) */

void __thiscall AbyssEngine::PaintCanvas::GetTextHeight(PaintCanvas *this,uint param_1)

{
  if (*(uint *)(this + 0x140) <= param_1) {
    return;
  }
  ImageFontGetHeight(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4));
  return;
}

// ===== AbyssEngine::PaintCanvas::GetLine  @0x000866c8  (274 bytes)
/* AbyssEngine::PaintCanvas::GetLine(unsigned int, AbyssEngine::String, int, AbyssEngine::String*)
    */

void __thiscall
AbyssEngine::PaintCanvas::GetLine
          (PaintCanvas *this,uint param_1,String *param_3,int param_4,String *param_5)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  String aSStack_30 [8];
  int local_28;
  
  uVar5 = 0;
  iVar6 = 5;
  local_28 = __stack_chk_guard;
  uVar4 = 0;
  while( true ) {
    if (*(uint *)(param_3 + 4) <= uVar4) {
      if ((int)*(uint *)(param_3 + 4) < 2) {
        String::String(aSStack_30,"",false);
        String::operator=(param_5,aSStack_30);
      }
      else {
        String::SubString((uint)aSStack_30,(uint)param_3);
        String::operator=(param_5,aSStack_30);
      }
      goto LAB_000867bc;
    }
    psVar2 = (short *)String::operator[](param_3,uVar4);
    sVar1 = *psVar2;
    iVar3 = GetTextWidth(this,param_1,param_3,uVar4,uVar4 + 1);
    iVar6 = iVar6 + iVar3;
    if (sVar1 == 0x20) {
      uVar5 = uVar4;
    }
    if (param_4 <= iVar6) break;
    psVar2 = (short *)String::operator[](param_3,uVar4);
    if ((*psVar2 == 10) ||
       (psVar2 = (short *)String::operator[](param_3,uVar4), uVar4 = uVar4 + 1, *psVar2 == 0xd)) {
      String::SubString((uint)aSStack_30,(uint)param_3);
      String::operator=(param_5,aSStack_30);
LAB_000867bc:
      String::~String(aSStack_30);
      if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
  if ((int)uVar5 < 1) {
    String::SubString((uint)aSStack_30,(uint)param_3);
    String::operator=(param_5,aSStack_30);
  }
  else {
    String::SubString((uint)aSStack_30,(uint)param_3);
    String::operator=(param_5,aSStack_30);
  }
  goto LAB_000867bc;
}

// ===== AbyssEngine::PaintCanvas::GetLineArray  @0x000867fc  (438 bytes)
/* AbyssEngine::PaintCanvas::GetLineArray(unsigned int, AbyssEngine::String const&, int,
   Array<AbyssEngine::String*>*) */

void __thiscall
AbyssEngine::PaintCanvas::GetLineArray
          (PaintCanvas *this,uint param_1,String *param_2,int param_3,Array *param_4)

{
  String *pSVar1;
  void *pvVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  String aSStack_50 [8];
  String aSStack_48 [8];
  String aSStack_40 [8];
  String aSStack_38 [8];
  String aSStack_30 [4];
  int local_2c;
  int local_28;
  
  local_28 = __stack_chk_guard;
  pSVar1 = operator_new(8);
  String::String(pSVar1);
  String::String(aSStack_30,param_2,false);
  String::String(aSStack_38,"\n",false);
  String::operator+=(aSStack_30,aSStack_38);
  String::~String(aSStack_38);
  if (local_2c < 1) {
    uVar6 = 0;
  }
  else {
    iVar5 = 0;
    uVar6 = 0;
    do {
      String::SubString((uint)aSStack_38,(uint)aSStack_30);
      String::String(aSStack_40,aSStack_38,false);
      GetLine(this,param_1,aSStack_40,param_3,pSVar1);
      String::~String(aSStack_40);
      iVar4 = *(int *)(pSVar1 + 4);
      String::~String(aSStack_38);
      iVar5 = iVar5 + iVar4;
      uVar6 = uVar6 + 1;
    } while (iVar5 < local_2c);
  }
  pvVar2 = (void *)String::~String(pSVar1);
  operator_delete(pvVar2);
  ArraySetLength<AbyssEngine::String*>(uVar6,param_4);
  if (0 < (int)uVar6) {
    iVar5 = 0;
    do {
      pSVar1 = operator_new(8);
      String::String(pSVar1);
      *(String **)(*(int *)(param_4 + 4) + iVar5 * 4) = pSVar1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)uVar6);
    if (0 < (int)uVar6) {
      iVar5 = 0;
      do {
        String::SubString((uint)aSStack_48,(uint)aSStack_30);
        String::String(aSStack_50,aSStack_48,false);
        GetLine(this,param_1,aSStack_50,param_3,*(undefined4 *)(*(int *)(param_4 + 4) + iVar5 * 4));
        String::~String(aSStack_50);
        iVar7 = 0;
        pSVar1 = *(String **)(*(int *)(param_4 + 4) + iVar5 * 4);
        iVar4 = *(int *)(pSVar1 + 4);
        while (psVar3 = (short *)String::operator[](pSVar1,iVar7), *psVar3 == 0x20) {
          iVar7 = iVar7 + 1;
          pSVar1 = *(String **)(*(int *)(param_4 + 4) + iVar5 * 4);
        }
        iVar4 = iVar4 + 1;
        do {
          psVar3 = (short *)String::operator[](*(String **)(*(int *)(param_4 + 4) + iVar5 * 4),
                                               iVar4 + -2);
          iVar4 = iVar4 + -1;
        } while (*psVar3 == 0x20);
        pSVar1 = *(String **)(*(int *)(param_4 + 4) + iVar5 * 4);
        String::SubString((uint)aSStack_38,(uint)pSVar1);
        String::operator=(pSVar1,aSStack_38);
        String::~String(aSStack_38);
        String::~String(aSStack_48);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar6);
    }
  }
  String::~String(aSStack_30);
  if (__stack_chk_guard == local_28) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

// ===== AbyssEngine::PaintCanvas::DrawTextLines  @0x00086a54  (130 bytes)
/* AbyssEngine::PaintCanvas::DrawTextLines(unsigned int, Array<AbyssEngine::String*>*, int, int,
   bool) */

void __thiscall
AbyssEngine::PaintCanvas::DrawTextLines
          (PaintCanvas *this,uint param_1,Array *param_2,int param_3,int param_4,bool param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined3 in_stack_00000005;
  
  if (*(int *)param_2 != 0) {
    uVar3 = 0;
    iVar2 = 0;
    do {
      if (_param_5 == 1) {
        iVar2 = GetTextWidth(this,param_1,*(String **)(*(int *)(param_2 + 4) + uVar3 * 4));
        iVar2 = -(iVar2 >> 1);
      }
      iVar1 = 0;
      DrawString(this,param_1,*(String **)(*(int *)(param_2 + 4) + uVar3 * 4),iVar2 + param_3,
                 param_4,false);
      if (param_1 < *(uint *)(this + 0x140)) {
        iVar1 = ImageFontGetHeight(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4));
      }
      param_4 = param_4 + iVar1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)param_2);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawTextLines  @0x00086ad6  (130 bytes)
/* AbyssEngine::PaintCanvas::DrawTextLines(unsigned int, Array<AbyssEngine::String*>*, int, int,
   unsigned int, bool) */

void __thiscall
AbyssEngine::PaintCanvas::DrawTextLines
          (PaintCanvas *this,uint param_1,Array *param_2,int param_3,int param_4,uint param_5,
          bool param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined3 in_stack_00000009;
  
  if (*(int *)param_2 != 0) {
    uVar3 = 0;
    iVar2 = 0;
    do {
      if (_param_6 == 0) {
        iVar2 = GetTextWidth(this,param_1,*(String **)(*(int *)(param_2 + 4) + uVar3 * 4));
        iVar2 = param_5 - iVar2;
      }
      iVar1 = 0;
      DrawString(this,param_1,*(String **)(*(int *)(param_2 + 4) + uVar3 * 4),iVar2 + param_3,
                 param_4,false);
      if (param_1 < *(uint *)(this + 0x140)) {
        iVar1 = ImageFontGetHeight(*(ImageFont **)(*(int *)(this + 0x144) + param_1 * 4));
      }
      param_4 = param_4 + iVar1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)param_2);
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::DrawTextLines  @0x00086b58  (26 bytes)
/* AbyssEngine::PaintCanvas::DrawTextLines(unsigned int, Array<AbyssEngine::String*>*, int, int) */

void __thiscall
AbyssEngine::PaintCanvas::DrawTextLines
          (PaintCanvas *this,uint param_1,Array *param_2,int param_3,int param_4)

{
  DrawTextLines(this,param_1,param_2,param_3,param_4,false);
  return;
}

// ===== AbyssEngine::PaintCanvas::ResourceLoaded  @0x00086b74  (80 bytes)
/* AbyssEngine::PaintCanvas::ResourceLoaded(unsigned int, AbyssEngine::ResourceType) */

bool __thiscall
AbyssEngine::PaintCanvas::ResourceLoaded(PaintCanvas *this,uint param_1,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  switch(param_3) {
  case 1:
    uVar2 = *(uint *)(this + 0x140);
    break;
  case 2:
    iVar1 = *(int *)(*(int *)(this + 0x138) + param_1 * 4);
    if (*(int *)(iVar1 + 4) == 2) {
      return *(int *)(iVar1 + 8) != -1;
    }
    return false;
  case 3:
    uVar2 = *(uint *)(this + 0x14c);
    break;
  case 4:
    uVar2 = *(uint *)(this + 0x24);
    break;
  case 5:
    uVar2 = *(uint *)(this + 0x158);
    break;
  case 6:
    uVar2 = *(uint *)(this + 0x174);
    break;
  default:
    return false;
  }
  return param_1 < uVar2;
}

// ===== AbyssEngine::PaintCanvas::ReleaseSpriteSystemResource  @0x00086bcc  (28 bytes)
/* AbyssEngine::PaintCanvas::ReleaseSpriteSystemResource(unsigned int) */

void __thiscall
AbyssEngine::PaintCanvas::ReleaseSpriteSystemResource(PaintCanvas *this,uint param_1)

{
  if (param_1 < *(uint *)(this + 0x180)) {
    SpriteSystemRelease(*(Engine **)(this + 0x34),
                        (SpriteSystem **)(*(int *)(this + 0x184) + param_1 * 4));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SetColor  @0x00086be8  (118 bytes)
/* AbyssEngine::PaintCanvas::SetColor(unsigned char, unsigned char, unsigned char, unsigned char) */

void AbyssEngine::PaintCanvas::SetColor(uchar param_1,uchar param_2,uchar param_3,uchar param_4)

{
  uint uVar1;
  uint in_fpscr;
  float in_s1;
  float in_s3;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined4 in_stack_00000000;
  
  uVar1 = (uint)param_1;
  dVar2 = (double)VectorUnsignedToFloat((uint)param_2,(byte)(in_fpscr >> 0x16) & 3);
  dVar3 = (double)VectorUnsignedToFloat((uint)param_3,(byte)(in_fpscr >> 0x16) & 3);
  dVar4 = (double)VectorUnsignedToFloat((uint)param_4,(byte)(in_fpscr >> 0x16) & 3);
  dVar5 = (double)VectorUnsignedToFloat(in_stack_00000000,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(uVar1 + 0x1fc) = (float)(dVar2 / 255.0);
  *(float *)(uVar1 + 0x200) = (float)(dVar3 / 255.0);
  *(float *)(uVar1 + 0x204) = (float)(dVar4 / 255.0);
  *(float *)(uVar1 + 0x208) = (float)(dVar5 / 255.0);
  Engine::SetColor(*(Engine **)(uVar1 + 0x34),(float)(dVar2 / 255.0),in_s1,(float)(dVar3 / 255.0),
                   in_s3);
  return;
}

// ===== AbyssEngine::PaintCanvas::SetProjOrthoMatrix  @0x00086c68  (192 bytes)
/* AbyssEngine::PaintCanvas::SetProjOrthoMatrix() */

void AbyssEngine::PaintCanvas::SetProjOrthoMatrix(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  PaintCanvas *in_r0;
  undefined4 uVar3;
  uint in_fpscr;
  uint uVar4;
  float in_s1;
  double dVar5;
  
  uVar4 = in_fpscr & 0xfffffff | (uint)(i_fov == -1.0) << 0x1e;
  if ((byte)(uVar4 >> 0x1e) == 0) {
    SetProjectionMatrix3d(in_r0,i_fov,in_s1,-1.0);
  }
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(in_r0 + 0xa8) = 0;
  *(undefined4 *)(in_r0 + 0xac) = uVar3;
  *(undefined4 *)(in_r0 + 0xb0) = uVar1;
  *(undefined4 *)(in_r0 + 0xb4) = uVar2;
  *(undefined4 *)(in_r0 + 0x98) = 0;
  *(undefined4 *)(in_r0 + 0x9c) = uVar3;
  *(undefined4 *)(in_r0 + 0xa0) = uVar1;
  *(undefined4 *)(in_r0 + 0xa4) = uVar2;
  *(undefined4 *)(in_r0 + 0x88) = 0;
  *(undefined4 *)(in_r0 + 0x8c) = uVar3;
  *(undefined4 *)(in_r0 + 0x90) = uVar1;
  *(undefined4 *)(in_r0 + 0x94) = uVar2;
  *(undefined4 *)(in_r0 + 0x78) = 0;
  *(undefined4 *)(in_r0 + 0x7c) = uVar3;
  *(undefined4 *)(in_r0 + 0x80) = uVar1;
  *(undefined4 *)(in_r0 + 0x84) = uVar2;
  uVar3 = Engine::GetDisplayWidth(*(Engine **)(in_r0 + 0x34));
  dVar5 = (double)VectorSignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
  *(float *)(in_r0 + 0x78) = (float)(2.0 / dVar5);
  uVar3 = Engine::GetDisplayHeight(*(Engine **)(in_r0 + 0x34));
  dVar5 = (double)VectorSignedToFloat(uVar3,(byte)(uVar4 >> 0x16) & 3);
  *(float *)(in_r0 + 0x8c) = -(float)(2.0 / dVar5);
  *(undefined4 *)(in_r0 + 0xa0) = 0xbd4ccccd;
  *(undefined4 *)(in_r0 + 0xb4) = 0x3f800000;
  *(undefined4 *)(in_r0 + 0xa8) = 0xbf800000;
  *(undefined4 *)(in_r0 + 0xac) = 0x3f800000;
  return;
}

// ===== AbyssEngine::PaintCanvas::ClearBuffer  @0x00086d34  (36 bytes)
/* AbyssEngine::PaintCanvas::ClearBuffer(unsigned int) */

void AbyssEngine::PaintCanvas::ClearBuffer(uint param_1)

{
  uint in_r1;
  
  glEnable(0xb71);
  glDepthMask(1);
  Engine::ClearBuffer(*(Engine **)(param_1 + 0x34),in_r1);
  return;
}

// ===== AbyssEngine::PaintCanvas::ClearDepth  @0x00086d56  (8 bytes)
/* AbyssEngine::PaintCanvas::ClearDepth() */

void AbyssEngine::PaintCanvas::ClearDepth(void)

{
  glClear(0x100);
  return;
}

// ===== AbyssEngine::PaintCanvas::SwapBuffer  @0x00086d5e  (2 bytes)
/* AbyssEngine::PaintCanvas::SwapBuffer() */

void AbyssEngine::PaintCanvas::SwapBuffer(void)

{
  return;
}

// ===== AbyssEngine::PaintCanvas::EnableClip  @0x00086d60  (130 bytes)
/* AbyssEngine::PaintCanvas::EnableClip(int, int, int, int) */

void __thiscall
AbyssEngine::PaintCanvas::EnableClip
          (PaintCanvas *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  glEnable(0xc11);
  iVar1 = param_2;
  iVar3 = param_3;
  switch(*(undefined4 *)(this + 0x30)) {
  case 0:
    iVar1 = param_1;
    iVar3 = param_4;
    param_4 = param_3;
    param_1 = param_2;
    break;
  case 1:
    iVar4 = param_2 + param_4;
    iVar2 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
    iVar1 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
    iVar1 = iVar1 - (param_3 + param_1);
    iVar3 = param_4;
    param_4 = param_3;
    param_1 = iVar2 - iVar4;
    break;
  case 2:
    iVar1 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
    iVar1 = iVar1 - (param_2 + param_4);
    break;
  case 3:
    iVar2 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
    param_1 = iVar2 - (param_3 + param_1);
  }
  glScissor(param_1,iVar1,iVar3,param_4);
  return;
}

// ===== AbyssEngine::PaintCanvas::DisableClip  @0x00086de4  (8 bytes)
/* AbyssEngine::PaintCanvas::DisableClip() */

void AbyssEngine::PaintCanvas::DisableClip(void)

{
  glDisable(0xc11);
  return;
}

// ===== AbyssEngine::PaintCanvas::SetShaderMode  @0x00086dec  (8 bytes)
/* AbyssEngine::PaintCanvas::SetShaderMode(int) */

void __thiscall AbyssEngine::PaintCanvas::SetShaderMode(PaintCanvas *this,int param_1)

{
  *(int *)(*(int *)(this + 0x34) + 0x498) = param_1;
  return;
}

// ===== AbyssEngine::PaintCanvas::SetBlendMode  @0x00086df4  (764 bytes)
/* AbyssEngine::PaintCanvas::SetBlendMode(AbyssEngine::BlendMode) */

void __thiscall AbyssEngine::PaintCanvas::SetBlendMode(PaintCanvas *this,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  Engine::LightEnable(SUB41(*(undefined4 *)(this + 0x34),0));
  if (Engine::enableShader == '\0') {
    glTexEnvi(0x2300,0x2200,0x2100);
  }
  else {
    Engine::GlEnable(*(Engine **)(this + 0x34),0x1100020,false);
  }
  switch(param_2) {
  case 1:
  case 5:
    goto switchD_00086e36_caseD_1;
  case 2:
    goto switchD_00086e36_caseD_2;
  case 3:
    glDisable(0xb44);
    goto LAB_00086eb8;
  case 4:
    glEnable(0xb44);
    glEnable(0xbe2);
    uVar1 = 0;
    uVar2 = 0x301;
    goto LAB_00086ef0;
  case 6:
    Engine::LightEnable(SUB41(*(undefined4 *)(this + 0x34),0));
    Engine::LightSetLight(*(Engine **)(this + 0x34),0x4000);
  case 0:
    glEnable(0xb44);
    glDisable(0xbe2);
LAB_00086f26:
    uVar1 = 1;
LAB_00086f28:
    glDepthMask(uVar1);
    return;
  case 7:
    Engine::LightEnable(SUB41(*(undefined4 *)(this + 0x34),0));
    Engine::LightSetLight(*(Engine **)(this + 0x34),0x4000);
    goto switchD_00086e36_caseD_2;
  case 8:
    Engine::LightEnable(SUB41(*(undefined4 *)(this + 0x34),0));
    Engine::LightSetLight(*(Engine **)(this + 0x34),0x4000);
    goto switchD_00086e36_caseD_1;
  case 9:
    Engine::LightEnable(SUB41(*(undefined4 *)(this + 0x34),0));
    Engine::LightSetLight(*(Engine **)(this + 0x34),0x4000);
    goto LAB_00086f0a;
  case 10:
    glEnable(0xb44);
    glDisable(0xbe2);
    glDepthMask(1);
    Engine::GlEnable(*(Engine **)(this + 0x34),0x1000000,true);
    if (Engine::enableShader == '\0') {
      glAlphaFunc(0x204,0x3f000000);
      return;
    }
    break;
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    break;
  case 0x15:
    glEnable(0xb44);
    glEnable(0xbe2);
    glBlendFunc(0x302,0x303);
    glDepthMask(0);
    if (Engine::enableShader != '\0') {
      Engine::GlEnable(*(Engine **)(this + 0x34),0x1100020,true);
      return;
    }
    glTexEnvi(0x2300,0x2200,0x8570);
    glTexEnvi(0x2300,0x8571,0x104);
    glTexEnvi(0x2300,0x8572,0x1e01);
    glTexEnvi(0x2300,0x8580,0x1702);
    glTexEnvi(0x2300,0x8590,0x300);
    glTexEnvi(0x2300,0x8581,0x8577);
    uVar1 = 0x8591;
    uVar2 = 0x300;
LAB_000870f6:
    glTexEnvi(0x2300,uVar1,uVar2);
    return;
  case 0x16:
    glEnable(0xb44);
    glEnable(0xbe2);
    glBlendFunc(0x302,0x303);
    glDepthMask(0);
    if (Engine::enableShader == '\0') {
      glTexEnvi(0x2300,0x2200,0x8570);
      glTexEnvi(0x2300,0x8571,0x8575);
      glTexEnvi(0x2300,0x8572,0x1e01);
      glTexEnvi(0x2300,0x8580,0x1702);
      glTexEnvi(0x2300,0x8590,0x300);
      glTexEnvi(0x2300,0x8588,0x1702);
      glTexEnvi(0x2300,0x8598,0x302);
      glTexEnvi(0x2300,0x8581,0x8577);
      glTexEnvi(0x2300,0x8591,0x300);
      glTexEnvi(0x2300,0x8582,0x8577);
      uVar1 = 0x8592;
      uVar2 = 0x302;
      goto LAB_000870f6;
    }
    break;
  default:
    if (param_2 != 0x25) {
      return;
    }
LAB_00086f0a:
    glEnable(0xb44);
    glEnable(0xbe2);
    glBlendFunc(0x302,0x303);
    goto LAB_00086f26;
  }
  return;
switchD_00086e36_caseD_2:
  glEnable(0xb44);
LAB_00086eb8:
  glEnable(0xbe2);
  uVar1 = 1;
  uVar2 = 1;
  goto LAB_00086ef0;
switchD_00086e36_caseD_1:
  glEnable(0xb44);
  glEnable(0xbe2);
  uVar1 = 0x302;
  uVar2 = 0x303;
LAB_00086ef0:
  glBlendFunc(uVar1,uVar2);
  uVar1 = 0;
  goto LAB_00086f28;
}

// ===== AbyssEngine::PaintCanvas::Begin3d  @0x00087110  (152 bytes)
/* AbyssEngine::PaintCanvas::Begin3d() */

void __thiscall AbyssEngine::PaintCanvas::Begin3d(PaintCanvas *this)

{
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  float extraout_s3;
  
  *(undefined1 *)(*(int *)(this + 0x34) + 0xed) = 0;
  glEnable(0xb71);
  glDepthMask(1);
  glDisable(0xbe2);
  Engine::SetColor(*(Engine **)(this + 0x34),extraout_s0,extraout_s1,extraout_s2,extraout_s3);
  if (Engine::enableShader == '\0') {
    glMatrixMode(0x1702);
    glLoadIdentity();
    glScalef(0x3f800000,0xbf800000,0x3f800000);
    glMatrixMode(0x1701);
    glLoadMatrixf(this + 0x38);
    glMatrixMode(0x1700);
    glLoadIdentity();
    return;
  }
  Engine::SetPerspMatrix(*(Engine **)(this + 0x34),(float *)(this + 0x38));
  return;
}

// ===== AbyssEngine::PaintCanvas::FogEnable  @0x000871ac  (66 bytes)
/* AbyssEngine::PaintCanvas::FogEnable(bool, AbyssEngine::FogMode) */

void __thiscall AbyssEngine::PaintCanvas::FogEnable(PaintCanvas *this,int param_2,int param_3)

{
  PaintCanvas PVar1;
  
  *(int *)(this + 500) = param_3;
  if (param_3 == 0) {
    PVar1 = SUB41(param_2,0);
    if (Engine::enableShader == '\0') {
      if (param_2 == 1) {
        glEnable();
        PVar1 = Engine::fogEnabled;
      }
      else {
        glDisable(0xb60);
        PVar1 = Engine::fogEnabled;
      }
    }
    Engine::fogEnabled = PVar1;
    this[0x1f1] = (PaintCanvas)0x0;
    return;
  }
  this[0x1f1] = SUB41(param_2,0);
  return;
}

// ===== AbyssEngine::PaintCanvas::FogSetParameter  @0x000871f8  (316 bytes)
/* AbyssEngine::PaintCanvas::FogSetParameter(AbyssEngine::FogMode, float, float, float, unsigned
   int) */

void __thiscall
AbyssEngine::PaintCanvas::FogSetParameter
          (PaintCanvas *this,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,uint param_6)

{
  int iVar1;
  uint in_fpscr;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (Engine::enableShader == '\0') {
    uVar2 = VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    glFogf(0xb65,uVar2);
    glFogf(0xb62,param_5);
    glFogf(0xb63,param_3);
    glFogf(0xb64,param_4);
    local_34 = (float)VectorUnsignedToFloat(param_6 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
    local_2c = (float)VectorUnsignedToFloat((param_6 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
    local_30 = (float)VectorUnsignedToFloat
                                ((param_6 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3);
    local_28 = (float)VectorUnsignedToFloat(param_6 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
    local_34 = local_34 / 255.0;
    local_30 = local_30 / 255.0;
    local_2c = local_2c / 255.0;
    local_28 = local_28 / 255.0;
    glFogfv(0xb66,&local_34);
  }
  else {
    dVar3 = (double)VectorUnsignedToFloat(param_6 >> 0x18,(byte)(in_fpscr >> 0x16) & 3);
    dVar4 = (double)VectorUnsignedToFloat((param_6 & 0xffffff) >> 0x10,(byte)(in_fpscr >> 0x16) & 3)
    ;
    dVar5 = (double)VectorUnsignedToFloat((param_6 & 0xffff) >> 8,(byte)(in_fpscr >> 0x16) & 3);
    iVar1 = *(int *)(this + 0x34);
    local_34 = (float)(dVar3 / 255.0);
    local_30 = (float)(dVar4 / 255.0);
    local_2c = (float)(dVar5 / 255.0);
    *(undefined4 *)(iVar1 + 0x3d8) = param_3;
    *(undefined4 *)(iVar1 + 0x3dc) = param_4;
    AEMath::Vector::operator=((Vector *)(iVar1 + 0x3e0),(Vector *)&local_34);
  }
  if (__stack_chk_guard != local_24) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::StartDraw2FBO  @0x00087350  (8 bytes)
/* AbyssEngine::PaintCanvas::StartDraw2FBO() */

void __thiscall AbyssEngine::PaintCanvas::StartDraw2FBO(PaintCanvas *this)

{
  Engine::ActivateRender2TextureFBO(*(Engine **)(this + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::StopDraw2FBO  @0x00087356  (38 bytes)
/* AbyssEngine::PaintCanvas::StopDraw2FBO() */

void __thiscall AbyssEngine::PaintCanvas::StopDraw2FBO(PaintCanvas *this)

{
  Engine::DeactivateRender2TextureFBO(*(Engine **)(this + 0x34));
  SetBlendMode(this,0);
  Engine::DoPostEffect(*(Engine **)(this + 0x34));
  Engine::ActivateViewBuffer(*(Engine **)(this + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::ResetPersMatrix  @0x0008737c  (384 bytes)
/* AbyssEngine::PaintCanvas::ResetPersMatrix() */

void __thiscall AbyssEngine::PaintCanvas::ResetPersMatrix(PaintCanvas *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  PaintCanvas *pPVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  
  uVar4 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
  uVar5 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
  fVar6 = (float)AEMath::Sinf(i_fov * 0.5);
  fVar7 = (float)AEMath::Cosf(i_fov * 0.5);
  uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  pPVar8 = this + 0x38;
  fVar9 = (float)VectorSignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
  fVar10 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = uVar1;
  *(undefined4 *)(this + 0x70) = uVar2;
  *(undefined4 *)(this + 0x74) = uVar3;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = uVar1;
  *(undefined4 *)(this + 0x60) = uVar2;
  *(undefined4 *)(this + 100) = uVar3;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = uVar1;
  *(undefined4 *)(this + 0x50) = uVar2;
  *(undefined4 *)(this + 0x54) = uVar3;
  *(undefined4 *)pPVar8 = 0;
  *(undefined4 *)(this + 0x3c) = uVar1;
  *(undefined4 *)(this + 0x40) = uVar2;
  *(undefined4 *)(this + 0x44) = uVar3;
  if (3 < *(uint *)(this + 0x30)) goto LAB_00087456;
  fVar9 = fVar9 / fVar10;
  fVar6 = 1.0 / (fVar6 / fVar7);
  switch(*(uint *)(this + 0x30)) {
  case 0:
    fVar9 = fVar6 / fVar9;
    fVar6 = -fVar6;
    break;
  case 1:
    fVar9 = -(fVar6 / fVar9);
    break;
  case 2:
    fVar9 = fVar6 / fVar9;
    goto LAB_0008744e;
  case 3:
    fVar9 = -(fVar6 / fVar9);
    fVar6 = -fVar6;
LAB_0008744e:
    *(float *)(this + 0x38) = fVar9;
    *(float *)(this + 0x4c) = fVar6;
    goto LAB_00087456;
  }
  *(float *)(this + 0x3c) = fVar9;
  *(float *)(this + 0x48) = fVar6;
LAB_00087456:
  fVar7 = i_zNear - i_zFar;
  fVar6 = (i_zFar + i_zFar) * i_zNear;
  *(float *)(this + 0x60) = (i_zFar + i_zNear) / fVar7;
  *(undefined4 *)(this + 100) = 0xbf800000;
  *(float *)(this + 0x70) = fVar6 / fVar7;
  if (Engine::enableShader == '\0') {
    glMatrixMode(0x1702);
    glLoadIdentity();
    glScalef(0x3f800000,0xbf800000,0x3f800000);
    glMatrixMode(0x1701);
    glLoadMatrixf(pPVar8);
    glMatrixMode(0x1700);
    glLoadIdentity();
    return;
  }
  Engine::SetPerspMatrix(*(Engine **)(this + 0x34),(float *)pPVar8);
  return;
}

// ===== AbyssEngine::PaintCanvas::SetMatForGlow  @0x00087510  (422 bytes)
/* AbyssEngine::PaintCanvas::SetMatForGlow(AbyssEngine::Material*) */

void __thiscall AbyssEngine::PaintCanvas::SetMatForGlow(PaintCanvas *this,Material *param_1)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar4 = 0;
    uVar2 = 0;
    do {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x48) + uVar2 * 4);
      *(int *)(this + 0x194) = *(int *)(this + 0x18c) + 1;
      pvVar1 = realloc(*(void **)(this + 400),(*(int *)(this + 0x18c) + 1) * 4);
      *(void **)(this + 400) = pvVar1;
      *(undefined4 *)((int)pvVar1 + *(int *)(this + 0x18c) * 4) = uVar5;
      *(undefined4 *)(this + 0x18c) = *(undefined4 *)(this + 0x194);
      iVar3 = *(int *)(param_1 + 0x30) + iVar4;
      ArrayAdd<AbyssEngine::AEMath::Matrix>
                (*(undefined4 *)(*(int *)(param_1 + 0x30) + iVar4),*(undefined4 *)(iVar3 + 4),
                 *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                 *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14),
                 *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                 *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24),
                 *(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x2c),
                 *(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x34),
                 *(undefined4 *)(iVar3 + 0x38),this + 0x198);
      iVar3 = *(int *)(param_1 + 0x3c) + iVar4;
      ArrayAdd<AbyssEngine::AEMath::Matrix>
                (*(undefined4 *)(*(int *)(param_1 + 0x3c) + iVar4),*(undefined4 *)(iVar3 + 4),
                 *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                 *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14),
                 *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                 *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24),
                 *(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x2c),
                 *(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x34),
                 *(undefined4 *)(iVar3 + 0x38),this + 0x1a4);
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x54) + uVar2 * 4);
      *(int *)(this + 0x1b8) = *(int *)(this + 0x1b0) + 1;
      pvVar1 = realloc(*(void **)(this + 0x1b4),(*(int *)(this + 0x1b0) + 1) * 4);
      *(void **)(this + 0x1b4) = pvVar1;
      *(undefined4 *)((int)pvVar1 + *(int *)(this + 0x1b0) * 4) = uVar5;
      *(undefined4 *)(this + 0x1b0) = *(undefined4 *)(this + 0x1b8);
      iVar3 = *(int *)(param_1 + 0x60) + iVar4;
      ArrayAdd<AbyssEngine::AEMath::Matrix>
                (*(undefined4 *)(*(int *)(param_1 + 0x60) + iVar4),*(undefined4 *)(iVar3 + 4),
                 *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                 *(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14),
                 *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c),
                 *(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24),
                 *(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x2c),
                 *(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x34),
                 *(undefined4 *)(iVar3 + 0x38),this + 0x1bc);
      iVar4 = iVar4 + 0x3c;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x44));
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::RemoveAllMatsForGlow  @0x00087740  (188 bytes)
/* AbyssEngine::PaintCanvas::RemoveAllMatsForGlow() */

void __thiscall AbyssEngine::PaintCanvas::RemoveAllMatsForGlow(PaintCanvas *this)

{
  void *pvVar1;
  
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 0x194) = 1;
  pvVar1 = realloc(*(void **)(this + 400),4);
  *(void **)(this + 400) = pvVar1;
  __aeabi_memclr4(pvVar1,*(int *)(this + 0x194) << 2);
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0x1a0) = 1;
  pvVar1 = realloc(*(void **)(this + 0x19c),0x3c);
  *(void **)(this + 0x19c) = pvVar1;
  __aeabi_memclr4(pvVar1,*(int *)(this + 0x1a0) * 0x3c);
  *(undefined4 *)(this + 0x1a4) = 0;
  *(undefined4 *)(this + 0x1ac) = 1;
  pvVar1 = realloc(*(void **)(this + 0x1a8),0x3c);
  *(void **)(this + 0x1a8) = pvVar1;
  __aeabi_memclr4(pvVar1,*(int *)(this + 0x1ac) * 0x3c);
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1b8) = 1;
  pvVar1 = realloc(*(void **)(this + 0x1b4),4);
  *(void **)(this + 0x1b4) = pvVar1;
  __aeabi_memclr4(pvVar1,*(int *)(this + 0x1b8) << 2);
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1c4) = 1;
  pvVar1 = realloc(*(void **)(this + 0x1c0),0x3c);
  *(void **)(this + 0x1c0) = pvVar1;
  __aeabi_memclr4(pvVar1,*(int *)(this + 0x1c4) * 0x3c);
  return;
}

// ===== AbyssEngine::PaintCanvas::CheckNUseRefractFBO  @0x000877fc  (48 bytes)
/* AbyssEngine::PaintCanvas::CheckNUseRefractFBO(bool) */

void AbyssEngine::PaintCanvas::CheckNUseRefractFBO(bool param_1)

{
  int iVar1;
  
  if (((Engine::enableShader != '\0') && (Engine::EnableRefract != '\0')) &&
     (iVar1 = Engine::IsPostEffectActivated(*(Engine **)(param_1 + 0x34)), iVar1 == 0)) {
    Engine::ActivateRender2FracFBO(*(Engine **)(param_1 + 0x34));
    return;
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::End3d  @0x00087840  (3576 bytes)
/* AbyssEngine::PaintCanvas::End3d() */

void __thiscall AbyssEngine::PaintCanvas::End3d(PaintCanvas *this)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  Material *pMVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  Engine *pEVar9;
  byte bVar10;
  PaintCanvas *pPVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  float extraout_s0;
  float extraout_s0_00;
  float fVar15;
  float extraout_s1;
  float extraout_s1_00;
  float fVar16;
  float extraout_s2;
  float extraout_s2_00;
  float fVar17;
  float extraout_s3;
  float extraout_s3_00;
  float fVar18;
  AEMath aAStack_b4 [60];
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int local_3c;
  
  local_3c = __stack_chk_guard;
  if (Engine::enableShader != '\0') {
    RemoveAllMatsForGlow(this);
  }
  if ((*(int *)(this + 500) == 1) && (this[0x1f1] != (PaintCanvas)0x0)) {
    if (Engine::enableShader == '\0') {
      glEnable(0xb60);
    }
    else {
      Engine::fogEnabled = 1;
    }
  }
  uVar6 = 0;
  SetBlendMode(this,0);
  uVar12 = 0;
  if (*(int *)(this + 0x174) != 0) {
    uVar13 = 0;
    do {
      if (*(int *)(*(int *)(*(int *)(this + 0x178) + uVar13 * 4) + 0x20) == 0) {
        if ((((Engine::enableShader != '\0') &&
             (iVar2 = Engine::IsPostEffectActivated(*(Engine **)(this + 0x34)),
             Engine::EnableGlow != '\0')) && (iVar2 == 1)) &&
           (pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar13 * 4),
           *(int *)(pMVar4 + 0x24) != 0)) {
          SetMatForGlow(this,pMVar4);
          uVar12 = 1;
        }
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar13 * 4),true);
      }
      if ((Engine::enableShader != '\0') &&
         (uVar6 = Engine::IsPostEffectActivated(*(Engine **)(this + 0x34)),
         Engine::EnableGlow != '\0')) {
        uVar6 = uVar6 ^ 1;
        bVar14 = uVar6 == 0;
        if (bVar14) {
          uVar6 = uVar12 ^ 1;
        }
        if (bVar14 && (uVar6 & 1) == 0) {
          if (*(int *)(this + 0x198) != 0) {
            iVar2 = 0;
            uVar12 = 0;
            do {
              iVar8 = *(int *)(*(int *)(this + 0x178) + uVar13 * 4);
              uVar7 = *(undefined4 *)(*(int *)(this + 400) + uVar12 * 4);
              iVar5 = *(int *)(iVar8 + 0x44) + 1;
              *(int *)(iVar8 + 0x4c) = iVar5;
              pvVar3 = realloc(*(void **)(iVar8 + 0x48),iVar5 * 4);
              *(void **)(iVar8 + 0x48) = pvVar3;
              *(undefined4 *)((int)pvVar3 + *(int *)(iVar8 + 0x44) * 4) = uVar7;
              *(undefined4 *)(iVar8 + 0x44) = *(undefined4 *)(iVar8 + 0x4c);
              iVar5 = *(int *)(this + 0x19c) + iVar2;
              ArrayAdd<AbyssEngine::AEMath::Matrix>
                        (*(undefined4 *)(*(int *)(this + 0x19c) + iVar2),*(undefined4 *)(iVar5 + 4),
                         *(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),
                         *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14),
                         *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                         *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                         *(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x2c),
                         *(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x34),
                         *(undefined4 *)(iVar5 + 0x38),
                         *(int *)(*(int *)(this + 0x178) + uVar13 * 4) + 0x2c);
              iVar5 = *(int *)(this + 0x1a8) + iVar2;
              ArrayAdd<AbyssEngine::AEMath::Matrix>
                        (*(undefined4 *)(*(int *)(this + 0x1a8) + iVar2),*(undefined4 *)(iVar5 + 4),
                         *(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),
                         *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14),
                         *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                         *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                         *(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x2c),
                         *(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x34),
                         *(undefined4 *)(iVar5 + 0x38),
                         *(int *)(*(int *)(this + 0x178) + uVar13 * 4) + 0x38);
              iVar8 = *(int *)(*(int *)(this + 0x178) + uVar13 * 4);
              uVar7 = *(undefined4 *)(*(int *)(this + 0x1b4) + uVar12 * 4);
              iVar5 = *(int *)(iVar8 + 0x50) + 1;
              *(int *)(iVar8 + 0x58) = iVar5;
              pvVar3 = realloc(*(void **)(iVar8 + 0x54),iVar5 * 4);
              *(void **)(iVar8 + 0x54) = pvVar3;
              *(undefined4 *)((int)pvVar3 + *(int *)(iVar8 + 0x50) * 4) = uVar7;
              *(undefined4 *)(iVar8 + 0x50) = *(undefined4 *)(iVar8 + 0x58);
              iVar5 = *(int *)(this + 0x1c0) + iVar2;
              ArrayAdd<AbyssEngine::AEMath::Matrix>
                        (*(undefined4 *)(*(int *)(this + 0x1c0) + iVar2),*(undefined4 *)(iVar5 + 4),
                         *(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),
                         *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14),
                         *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                         *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                         *(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x2c),
                         *(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x34),
                         *(undefined4 *)(iVar5 + 0x38),
                         *(int *)(*(int *)(this + 0x178) + uVar13 * 4) + 0x5c);
              iVar2 = iVar2 + 0x3c;
              uVar12 = uVar12 + 1;
            } while (uVar12 < *(uint *)(this + 0x198));
          }
          RemoveAllMatsForGlow(this);
          uVar12 = 0;
        }
      }
      uVar6 = *(uint *)(this + 0x174);
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar6);
  }
  if ((*(int *)(this + 500) == 1) && (this[0x1f1] != (PaintCanvas)0x0)) {
    if (Engine::enableShader == '\0') {
      glDisable(0xb60);
      uVar6 = *(uint *)(this + 0x174);
    }
    else {
      Engine::fogEnabled = 0;
    }
    if (uVar6 != 0) {
      uVar13 = 0;
      do {
        pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar13 * 4);
        if (*(int *)(pMVar4 + 0x20) == 0x17) {
          MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
          uVar6 = *(uint *)(this + 0x174);
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < uVar6);
    }
    if (Engine::enableShader == '\0') {
      glEnable(0xb60);
    }
    else {
      Engine::fogEnabled = 1;
    }
  }
  Engine::LightEnable(SUB41(*(undefined4 *)(this + 0x34),0));
  if (*(uint *)(this + 0x170) < *(uint *)(this + 0x164)) {
    pPVar11 = (PaintCanvas *)(*(int *)(*(int *)(this + 0x168) + *(uint *)(this + 0x170) * 4) + 0xc);
  }
  else {
    pPVar11 = this + 0xf8;
    AEMath::MatrixIdentity((AEMath *)&local_78,pPVar11);
  }
  local_78 = *(undefined4 *)pPVar11;
  uStack_74 = *(undefined4 *)(pPVar11 + 4);
  uStack_70 = *(undefined4 *)(pPVar11 + 8);
  uStack_6c = *(undefined4 *)(pPVar11 + 0xc);
  uStack_68 = *(undefined4 *)(pPVar11 + 0x10);
  local_64 = *(undefined4 *)(pPVar11 + 0x14);
  uStack_60 = *(undefined4 *)(pPVar11 + 0x18);
  uStack_5c = *(undefined4 *)(pPVar11 + 0x1c);
  uStack_58 = *(undefined4 *)(pPVar11 + 0x20);
  uStack_54 = *(undefined4 *)(pPVar11 + 0x24);
  local_50 = *(undefined4 *)(pPVar11 + 0x28);
  uStack_4c = *(undefined4 *)(pPVar11 + 0x2c);
  uStack_48 = *(undefined4 *)(pPVar11 + 0x30);
  uStack_44 = *(undefined4 *)(pPVar11 + 0x34);
  uStack_40 = *(undefined4 *)(pPVar11 + 0x38);
  pEVar9 = *(Engine **)(this + 0x34);
  AEMath::MatrixGetInverse(aAStack_b4,(Matrix *)&local_78);
  Engine::SetWorldViewMatrix(pEVar9,aAStack_b4);
  Engine::LightSetLight(*(Engine **)(this + 0x34),0x4000);
  if (*(int *)(this + 0x174) != 0) {
    uVar6 = 0;
    do {
      uVar13 = 0x1100001;
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      iVar2 = *(int *)(pMVar4 + 0x20);
      switch(iVar2) {
      case 6:
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xe:
      case 0x10:
      case 0x11:
      case 0x12:
        goto switchD_00087cbc_caseD_7;
      case 0xb:
        Engine::GlEnable(*(Engine **)(this + 0x34),0x1100000,true);
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),true);
        pEVar9 = *(Engine **)(this + 0x34);
        uVar13 = 0x1100000;
        break;
      case 0xc:
switchD_00087cbc_caseD_c:
        if (((Engine::enableShader != '\0') &&
            (iVar2 = Engine::IsPostEffectActivated(*(Engine **)(this + 0x34)),
            Engine::EnableGlow != '\0')) &&
           ((iVar2 == 1 &&
            (pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),
            *(int *)(pMVar4 + 0x24) != 0)))) {
          SetMatForGlow(this,pMVar4);
          uVar12 = 1;
        }
        pEVar9 = *(Engine **)(this + 0x34);
        if (CubeMapSetIndex == 0) {
          uVar13 = 0x1100013;
        }
        else {
          uVar13 = 0x1100014;
        }
        goto LAB_00087dd6;
      case 0xd:
        if ((((Engine::enableShader != '\0') &&
             (iVar2 = Engine::IsPostEffectActivated(*(Engine **)(this + 0x34)),
             Engine::EnableGlow != '\0')) && (iVar2 == 1)) &&
           (pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),
           *(int *)(pMVar4 + 0x24) != 0)) {
          SetMatForGlow(this,pMVar4);
          uVar12 = 1;
        }
        uVar13 = 0x1100014;
        Engine::GlEnable(*(Engine **)(this + 0x34),0x1100014,true);
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),true);
        pEVar9 = *(Engine **)(this + 0x34);
        break;
      case 0xf:
        Engine::GlEnable(*(Engine **)(this + 0x34),0x1100001,true);
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),true);
        pEVar9 = *(Engine **)(this + 0x34);
        break;
      case 0x13:
        pEVar9 = *(Engine **)(this + 0x34);
        uVar13 = 0x1100006;
LAB_00087dd6:
        Engine::GlEnable(pEVar9,uVar13,true);
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),true);
        pEVar9 = *(Engine **)(this + 0x34);
        break;
      default:
        if (iVar2 - 0x1cU < 2) goto switchD_00087cbc_caseD_c;
        if (iVar2 == 0x26) {
          pEVar9 = *(Engine **)(this + 0x34);
          uVar13 = 0x1100022;
          goto LAB_00087dd6;
        }
        goto switchD_00087cbc_caseD_7;
      }
      Engine::GlEnable(pEVar9,uVar13,false);
switchD_00087cbc_caseD_7:
      if ((Engine::enableShader != '\0') &&
         (uVar13 = Engine::IsPostEffectActivated(*(Engine **)(this + 0x34)),
         Engine::EnableGlow != '\0')) {
        uVar13 = uVar13 ^ 1;
        bVar14 = uVar13 == 0;
        if (bVar14) {
          uVar13 = uVar12 ^ 1;
        }
        if (bVar14 && (uVar13 & 1) == 0) {
          if (*(int *)(this + 0x198) != 0) {
            iVar2 = 0;
            uVar12 = 0;
            do {
              iVar8 = *(int *)(*(int *)(this + 0x178) + uVar6 * 4);
              uVar7 = *(undefined4 *)(*(int *)(this + 400) + uVar12 * 4);
              iVar5 = *(int *)(iVar8 + 0x44) + 1;
              *(int *)(iVar8 + 0x4c) = iVar5;
              pvVar3 = realloc(*(void **)(iVar8 + 0x48),iVar5 * 4);
              *(void **)(iVar8 + 0x48) = pvVar3;
              *(undefined4 *)((int)pvVar3 + *(int *)(iVar8 + 0x44) * 4) = uVar7;
              *(undefined4 *)(iVar8 + 0x44) = *(undefined4 *)(iVar8 + 0x4c);
              iVar5 = *(int *)(this + 0x19c) + iVar2;
              ArrayAdd<AbyssEngine::AEMath::Matrix>
                        (*(undefined4 *)(*(int *)(this + 0x19c) + iVar2),*(undefined4 *)(iVar5 + 4),
                         *(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),
                         *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14),
                         *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                         *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                         *(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x2c),
                         *(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x34),
                         *(undefined4 *)(iVar5 + 0x38),
                         *(int *)(*(int *)(this + 0x178) + uVar6 * 4) + 0x2c);
              iVar5 = *(int *)(this + 0x1a8) + iVar2;
              ArrayAdd<AbyssEngine::AEMath::Matrix>
                        (*(undefined4 *)(*(int *)(this + 0x1a8) + iVar2),*(undefined4 *)(iVar5 + 4),
                         *(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),
                         *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14),
                         *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                         *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                         *(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x2c),
                         *(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x34),
                         *(undefined4 *)(iVar5 + 0x38),
                         *(int *)(*(int *)(this + 0x178) + uVar6 * 4) + 0x38);
              iVar8 = *(int *)(*(int *)(this + 0x178) + uVar6 * 4);
              uVar7 = *(undefined4 *)(*(int *)(this + 0x1b4) + uVar12 * 4);
              iVar5 = *(int *)(iVar8 + 0x50) + 1;
              *(int *)(iVar8 + 0x58) = iVar5;
              pvVar3 = realloc(*(void **)(iVar8 + 0x54),iVar5 * 4);
              *(void **)(iVar8 + 0x54) = pvVar3;
              *(undefined4 *)((int)pvVar3 + *(int *)(iVar8 + 0x50) * 4) = uVar7;
              *(undefined4 *)(iVar8 + 0x50) = *(undefined4 *)(iVar8 + 0x58);
              iVar5 = *(int *)(this + 0x1c0) + iVar2;
              ArrayAdd<AbyssEngine::AEMath::Matrix>
                        (*(undefined4 *)(*(int *)(this + 0x1c0) + iVar2),*(undefined4 *)(iVar5 + 4),
                         *(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),
                         *(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar5 + 0x14),
                         *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),
                         *(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x24),
                         *(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x2c),
                         *(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x34),
                         *(undefined4 *)(iVar5 + 0x38),
                         *(int *)(*(int *)(this + 0x178) + uVar6 * 4) + 0x5c);
              iVar2 = iVar2 + 0x3c;
              uVar12 = uVar12 + 1;
            } while (uVar12 < *(uint *)(this + 0x198));
          }
          RemoveAllMatsForGlow(this);
          uVar12 = 0;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(this + 0x174));
  }
  SetBlendMode(this,8);
  if (*(int *)(this + 0x174) != 0) {
    uVar12 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar12 * 4);
      iVar2 = *(int *)(pMVar4 + 0x20);
      if (iVar2 == 8) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
      }
      else {
        if (iVar2 == 0x10) {
          pEVar9 = *(Engine **)(this + 0x34);
          uVar6 = 0x1100016;
        }
        else {
          if (iVar2 != 0x24) goto LAB_00088078;
          pEVar9 = *(Engine **)(this + 0x34);
          uVar6 = 0x1100021;
        }
        Engine::GlEnable(pEVar9,uVar6,true);
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar12 * 4),true);
        Engine::GlEnable(*(Engine **)(this + 0x34),uVar6,false);
      }
LAB_00088078:
      uVar12 = uVar12 + 1;
    } while (uVar12 < *(uint *)(this + 0x174));
  }
  SetBlendMode(this,9);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 9) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  SetBlendMode(this,7);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 7) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  Engine::LightEnable(SUB41(*(undefined4 *)(this + 0x34),0));
  SetBlendMode(this,0x25);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 0x25) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  SetBlendMode(this,1);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 == 0) {
    uVar12 = 0;
  }
  else {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 1) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  if ((*(int *)(this + 500) == 1) && (this[0x1f1] != (PaintCanvas)0x0)) {
    if (Engine::enableShader == '\0') {
      glDisable(0xb60);
      uVar12 = *(uint *)(this + 0x174);
    }
    else {
      Engine::fogEnabled = 0;
    }
    if (uVar12 != 0) {
      uVar6 = 0;
      do {
        pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
        if (*(int *)(pMVar4 + 0x20) == 0x18) {
          MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
          uVar12 = *(uint *)(this + 0x174);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar12);
    }
    if (Engine::enableShader == '\0') {
      glEnable(0xb60);
    }
    else {
      Engine::fogEnabled = 1;
    }
  }
  SetBlendMode(this,0x15);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 0x15) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  SetBlendMode(this,0x16);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 0x16) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  SetBlendMode(this,10);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 10) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  Engine::GlEnable(*(Engine **)(this + 0x34),0x1000000,false);
  SetBlendMode(this,2);
  if ((*(int *)(this + 500) == 1) && (this[0x1f1] != (PaintCanvas)0x0)) {
    if (Engine::enableShader == '\0') {
      glDisable(0xb60);
    }
    else {
      Engine::fogEnabled = 0;
    }
  }
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 2) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  SetBlendMode(this,3);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 3) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  if ((*(int *)(this + 500) == 1) && (this[0x1f1] != (PaintCanvas)0x0)) {
    if (Engine::enableShader == '\0') {
      glEnable(0xb60);
    }
    else {
      Engine::fogEnabled = 1;
    }
  }
  SetBlendMode(this,4);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 4) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  SetBlendMode(this,5);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    fVar15 = extraout_s0;
    fVar16 = extraout_s1;
    fVar17 = extraout_s2;
    fVar18 = extraout_s3;
    do {
      if (*(int *)(*(int *)(*(int *)(this + 0x178) + uVar6 * 4) + 0x20) == 5) {
        *(undefined8 *)(this + 0x1fc) = 0x3f8000003f800000;
        *(undefined8 *)(this + 0x204) = 0x3efefeff3f800000;
        Engine::SetColor(*(Engine **)(this + 0x34),fVar15,fVar16,fVar17,fVar18);
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),true);
        uVar12 = *(uint *)(this + 0x174);
        fVar15 = extraout_s0_00;
        fVar16 = extraout_s1_00;
        fVar17 = extraout_s2_00;
        fVar18 = extraout_s3_00;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  SetColor((uint)this);
  SetBlendMode(this,1);
  uVar12 = *(uint *)(this + 0x174);
  if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 0x12) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  if ((Engine::enableShader != '\0') && (Engine::EnableRefract != '\0')) {
    Engine::CopyFBO(*(Engine **)(this + 0x34));
    Engine::SetPerspMatrix(*(Engine **)(this + 0x34),(float *)(this + 0x38));
  }
  bVar10 = 0;
  SetBlendMode(this,0);
  if (*(int *)(this + 0x174) != 0) {
    uVar12 = 0;
    bVar10 = 0;
    do {
      iVar2 = *(int *)(*(int *)(this + 0x178) + uVar12 * 4);
      if (*(int *)(iVar2 + 0x20) == 0x22) {
        iVar2 = *(int *)(iVar2 + 0x44);
        uVar6 = 0x1100018;
LAB_00088490:
        Engine::GlEnable(*(Engine **)(this + 0x34),uVar6,true);
        MaterialDraw(this,*(Engine **)(this + 0x34),
                     *(Material **)(*(int *)(this + 0x178) + uVar12 * 4),true);
        Engine::GlEnable(*(Engine **)(this + 0x34),uVar6,false);
        bVar10 = bVar10 | iVar2 != 0;
      }
      else if (*(int *)(iVar2 + 0x20) == 0xe) {
        iVar2 = *(int *)(iVar2 + 0x44);
        uVar6 = 0x1100015;
        goto LAB_00088490;
      }
      uVar12 = uVar12 + 1;
    } while (uVar12 < *(uint *)(this + 0x174));
  }
  cVar1 = Engine::DisableRefract;
  SetBlendMode(this,3);
  uVar12 = *(uint *)(this + 0x174);
  if (cVar1 == '\0') {
    if (uVar12 != 0) {
      uVar6 = 0;
      do {
        iVar2 = *(int *)(*(int *)(this + 0x178) + uVar6 * 4);
        if (*(int *)(iVar2 + 0x20) == 0x27) {
          iVar2 = *(int *)(iVar2 + 0x44);
          Engine::GlEnable(*(Engine **)(this + 0x34),0x1100024,true);
          MaterialDraw(this,*(Engine **)(this + 0x34),
                       *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),true);
          Engine::GlEnable(*(Engine **)(this + 0x34),0x1100024,false);
          uVar12 = *(uint *)(this + 0x174);
          bVar10 = bVar10 | iVar2 != 0;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar12);
    }
  }
  else if (uVar12 != 0) {
    uVar6 = 0;
    do {
      pMVar4 = *(Material **)(*(int *)(this + 0x178) + uVar6 * 4);
      if (*(int *)(pMVar4 + 0x20) == 0x27) {
        MaterialDraw(this,*(Engine **)(this + 0x34),pMVar4,true);
        uVar12 = *(uint *)(this + 0x174);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar12);
  }
  Engine::EnableRefract = bVar10;
  if (this[0x1f1] != (PaintCanvas)0x0) {
    if (Engine::enableShader == '\0') {
      glDisable(0xb60);
    }
    else {
      Engine::fogEnabled = 0;
    }
  }
  if (((Engine::enableShader != '\0') &&
      (iVar2 = Engine::IsPostEffectActivated(*(Engine **)(this + 0x34)), Engine::EnableGlow != '\0')
      ) && (iVar2 == 1)) {
    SetBlendMode(this,0);
    Engine::GlowBeginGlow(*(Engine **)(this + 0x34),0x203);
    uVar12 = *(uint *)(this + 0x174);
    if (uVar12 != 0) {
      uVar6 = 0;
      do {
        if (*(int *)(*(int *)(*(int *)(this + 0x178) + uVar6 * 4) + 0x24) != 0) {
          Engine::GlEnable(*(Engine **)(this + 0x34),0x1100017,true);
          MaterialDraw(this,*(Engine **)(this + 0x34),
                       *(Material **)(*(int *)(this + 0x178) + uVar6 * 4),true);
          Engine::GlEnable(*(Engine **)(this + 0x34),0x1100017,false);
          uVar12 = *(uint *)(this + 0x174);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar12);
    }
    Engine::GlowEndGlow(*(Engine **)(this + 0x34));
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::BeginBG  @0x000886f0  (170 bytes)
/* AbyssEngine::PaintCanvas::BeginBG() */

void __thiscall AbyssEngine::PaintCanvas::BeginBG(PaintCanvas *this)

{
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  float extraout_s3;
  
  *(undefined1 *)(*(int *)(this + 0x34) + 0xed) = 0;
  glDisable(0xb71);
  glDepthMask(0);
  glDisable(0xbe2);
  Engine::SetColor(*(Engine **)(this + 0x34),extraout_s0,extraout_s1,extraout_s2,extraout_s3);
  this[0x1f0] = Engine::vfc;
  Engine::vfc = (PaintCanvas)0x0;
  if (Engine::enableShader == '\0') {
    glMatrixMode(0x1702);
    glLoadIdentity();
    glScalef(0x3f800000,0xbf800000,0x3f800000);
    glMatrixMode(0x1701);
    glLoadMatrixf(this + 0x38);
    glMatrixMode(0x1700);
    glLoadIdentity();
    return;
  }
  Engine::SetPerspMatrix(*(Engine **)(this + 0x34),(float *)(this + 0x38));
  return;
}

// ===== AbyssEngine::PaintCanvas::EndBG  @0x000887a0  (14 bytes)
/* AbyssEngine::PaintCanvas::EndBG() */

void __thiscall AbyssEngine::PaintCanvas::EndBG(PaintCanvas *this)

{
  Engine::vfc = this[0x1f0];
  return;
}

// ===== AbyssEngine::PaintCanvas::Begin2d  @0x000887b4  (218 bytes)
/* AbyssEngine::PaintCanvas::Begin2d() */

void __thiscall AbyssEngine::PaintCanvas::Begin2d(PaintCanvas *this)

{
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  float extraout_s3;
  
  *(undefined1 *)(*(int *)(this + 0x34) + 0xed) = 1;
  glDisable(0xb71);
  glDepthMask(0);
  glEnable(0xbe2);
  glBlendFunc(0x302,0x303);
  Engine::SetColor(*(Engine **)(this + 0x34),extraout_s0,extraout_s1,extraout_s2,extraout_s3);
  Engine::GlEnable(*(Engine **)(this + 0x34),0xde1,true);
  if (Engine::enableShader == '\0') {
    glTexEnvi(0x2300,0x2200,0x2100);
    glMatrixMode(0x1702);
    glLoadIdentity();
    glScalef(0x3f800000,0x3f800000,0x3f800000);
    glMatrixMode(0x1701);
    glLoadMatrixf(this + 0x78);
    if (*(int *)(this + 0x30) != 2) {
      glMultMatrixf(this + 0xb8);
    }
    glMatrixMode(0x1700);
    glLoadIdentity();
  }
  else {
    Engine::SetOrthoMatrix
              (*(Engine **)(this + 0x34),(float *)(this + 0x78),(float *)(this + 0xb8),
               *(int *)(this + 0x30) != 2);
  }
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

// ===== AbyssEngine::PaintCanvas::End2d  @0x000888a0  (116 bytes)
/* AbyssEngine::PaintCanvas::End2d() */

void __thiscall AbyssEngine::PaintCanvas::End2d(PaintCanvas *this)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [5];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  int local_14;
  
  local_14 = __stack_chk_guard;
  iVar1 = *(int *)(this + 0xc);
  if (0 < iVar1) {
    uStack_34 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uStack_30 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uStack_2c = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    *(short *)(*(int *)(this + 8) + 0x28) = ((short)iVar1 + (short)(iVar1 << 1)) * 2;
    puVar2 = (undefined4 *)((uint)local_50 | 4);
    local_50[0] = 0x3f800000;
    *puVar2 = 0;
    puVar2[1] = uStack_34;
    puVar2[2] = uStack_30;
    puVar2[3] = uStack_2c;
    local_3c = 0x3f800000;
    local_38 = 0;
    local_28 = 0x3f800000;
    uStack_20 = 0x3f8000003f800000;
    local_18 = 0x3f800000;
    Engine::SetWorldViewMatrix(*(Engine **)(this + 0x34),(Matrix *)local_50);
    MeshDraw(*(Engine **)(this + 0x34),*(Mesh **)(this + 8));
  }
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::SetGameOrientation  @0x00088940  (732 bytes)
/* AbyssEngine::PaintCanvas::SetGameOrientation(AbyssEngine::LandscapeMode) */

void __thiscall AbyssEngine::PaintCanvas::SetGameOrientation(PaintCanvas *this,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s1_01;
  float extraout_s1_02;
  float extraout_s2;
  float extraout_s2_00;
  float extraout_s2_01;
  float fVar6;
  
  if (*(int *)(this + 0x30) == param_2) {
    return;
  }
  *(int *)(this + 0x30) = param_2;
  Engine::SetScreenOrientation(*(undefined4 *)(this + 0x34),param_2);
  *(float *)(this + 0x3c) = -*(float *)(this + 0x3c);
  *(float *)(this + 0x48) = -*(float *)(this + 0x48);
  uVar3 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
  fVar6 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  uVar3 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
  fVar4 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  if (param_2 == 3) {
    *(undefined4 *)(this + 0xac) = 0;
    *(undefined4 *)(this + 0xb0) = 0;
    uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    *(undefined4 *)(this + 0x9c) = 0;
    *(undefined4 *)(this + 0xa0) = uVar3;
    *(undefined4 *)(this + 0xa4) = uVar1;
    *(undefined4 *)(this + 0xa8) = uVar2;
    *(undefined4 *)(this + 0x8c) = 0;
    *(undefined4 *)(this + 0x90) = uVar3;
    *(undefined4 *)(this + 0x94) = uVar1;
    *(undefined4 *)(this + 0x98) = uVar2;
    *(undefined4 *)(this + 0x7c) = 0;
    *(undefined4 *)(this + 0x80) = uVar3;
    *(undefined4 *)(this + 0x84) = uVar1;
    *(undefined4 *)(this + 0x88) = uVar2;
    *(float *)(this + 0x78) = 2.0 / fVar6;
    *(float *)(this + 0x8c) = -(2.0 / fVar4);
    *(undefined4 *)(this + 0xa0) = 0xbd4ccccd;
    *(undefined4 *)(this + 0xb4) = 0x3f800000;
    *(undefined4 *)(this + 0xa8) = 0xbf800000;
    *(undefined4 *)(this + 0xac) = 0x3f800000;
    *(undefined4 *)(this + 0xdc) = 0;
    *(undefined4 *)(this + 0xe0) = uVar3;
    *(undefined4 *)(this + 0xe4) = uVar1;
    *(undefined4 *)(this + 0xe8) = uVar2;
    *(undefined4 *)(this + 0xcc) = 0;
    *(undefined4 *)(this + 0xd0) = uVar3;
    *(undefined4 *)(this + 0xd4) = uVar1;
    *(undefined4 *)(this + 0xd8) = uVar2;
    *(undefined4 *)(this + 0xbc) = 0;
    *(undefined4 *)(this + 0xc0) = uVar3;
    *(undefined4 *)(this + 0xc4) = uVar1;
    *(undefined4 *)(this + 200) = uVar2;
    *(undefined4 *)(this + 0xec) = 0;
    *(undefined4 *)(this + 0xf0) = 0;
    *(undefined4 *)(this + 0xb8) = 0xbf800000;
    *(undefined4 *)(this + 0xcc) = 0xbf800000;
    *(undefined4 *)(this + 0xe0) = 0x3f800000;
    *(undefined4 *)(this + 0xf4) = 0x3f800000;
    uVar3 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
    uVar3 = VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
    *(undefined4 *)(this + 0xe8) = uVar3;
    uVar3 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
    fVar4 = extraout_s1_01;
    fVar6 = extraout_s2_00;
  }
  else {
    if (param_2 == 1) {
      *(undefined4 *)(this + 0xac) = 0;
      *(undefined4 *)(this + 0xb0) = 0;
      uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      *(undefined4 *)(this + 0x9c) = 0;
      *(undefined4 *)(this + 0xa0) = uVar3;
      *(undefined4 *)(this + 0xa4) = uVar1;
      *(undefined4 *)(this + 0xa8) = uVar2;
      *(undefined4 *)(this + 0x8c) = 0;
      *(undefined4 *)(this + 0x90) = uVar3;
      *(undefined4 *)(this + 0x94) = uVar1;
      *(undefined4 *)(this + 0x98) = uVar2;
      *(undefined4 *)(this + 0x7c) = 0;
      *(undefined4 *)(this + 0x80) = uVar3;
      *(undefined4 *)(this + 0x84) = uVar1;
      *(undefined4 *)(this + 0x88) = uVar2;
      *(float *)(this + 0x78) = 2.0 / fVar4;
      *(float *)(this + 0x8c) = -(2.0 / fVar6);
      *(undefined4 *)(this + 0xa0) = 0xbd4ccccd;
      *(undefined4 *)(this + 0xb4) = 0x3f800000;
      *(undefined4 *)(this + 0xa8) = 0xbf800000;
      *(undefined4 *)(this + 0xac) = 0x3f800000;
      *(undefined4 *)(this + 0xe4) = 0;
      *(undefined4 *)(this + 0xe8) = uVar3;
      *(undefined4 *)(this + 0xec) = uVar1;
      *(undefined4 *)(this + 0xf0) = uVar2;
      *(undefined4 *)(this + 0xd8) = 0;
      *(undefined4 *)(this + 0xdc) = uVar3;
      *(undefined4 *)(this + 0xe0) = uVar1;
      *(undefined4 *)(this + 0xe4) = uVar2;
      *(undefined4 *)(this + 200) = 0;
      *(undefined4 *)(this + 0xcc) = uVar3;
      *(undefined4 *)(this + 0xd0) = uVar1;
      *(undefined4 *)(this + 0xd4) = uVar2;
      *(undefined4 *)(this + 0xb8) = 0;
      *(undefined4 *)(this + 0xbc) = uVar3;
      *(undefined4 *)(this + 0xc0) = uVar1;
      *(undefined4 *)(this + 0xc4) = uVar2;
      *(undefined4 *)(this + 0xbc) = 0x3f800000;
      *(undefined4 *)(this + 200) = 0xbf800000;
      *(undefined4 *)(this + 0xe0) = 0x3f800000;
      *(undefined4 *)(this + 0xf4) = 0x3f800000;
      uVar3 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
      fVar5 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
      *(float *)(this + 0xe8) = fVar5;
      fVar4 = extraout_s1_02;
      fVar6 = extraout_s2_01;
      goto LAB_00088bf2;
    }
    if (param_2 != 0) {
      *(undefined4 *)(this + 0xac) = 0;
      *(undefined4 *)(this + 0xb0) = 0;
      fVar6 = 2.0 / fVar6;
      uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
      fVar5 = -(2.0 / fVar4);
      *(undefined4 *)(this + 0x9c) = 0;
      *(undefined4 *)(this + 0xa0) = uVar3;
      *(undefined4 *)(this + 0xa4) = uVar1;
      *(undefined4 *)(this + 0xa8) = uVar2;
      *(undefined4 *)(this + 0x8c) = 0;
      *(undefined4 *)(this + 0x90) = uVar3;
      *(undefined4 *)(this + 0x94) = uVar1;
      *(undefined4 *)(this + 0x98) = uVar2;
      *(undefined4 *)(this + 0x7c) = 0;
      *(undefined4 *)(this + 0x80) = uVar3;
      *(undefined4 *)(this + 0x84) = uVar1;
      *(undefined4 *)(this + 0x88) = uVar2;
      *(float *)(this + 0x78) = fVar6;
      *(float *)(this + 0x8c) = fVar5;
      *(undefined4 *)(this + 0xa0) = 0xbd4ccccd;
      *(undefined4 *)(this + 0xb4) = 0x3f800000;
      *(undefined4 *)(this + 0xa8) = 0xbf800000;
      *(undefined4 *)(this + 0xac) = 0x3f800000;
      *(undefined4 *)(this + 0xdc) = 0;
      *(undefined4 *)(this + 0xe0) = uVar3;
      *(undefined4 *)(this + 0xe4) = uVar1;
      *(undefined4 *)(this + 0xe8) = uVar2;
      *(undefined4 *)(this + 0xcc) = 0;
      *(undefined4 *)(this + 0xd0) = uVar3;
      *(undefined4 *)(this + 0xd4) = uVar1;
      *(undefined4 *)(this + 0xd8) = uVar2;
      *(undefined4 *)(this + 0xbc) = 0;
      *(undefined4 *)(this + 0xc0) = uVar3;
      *(undefined4 *)(this + 0xc4) = uVar1;
      *(undefined4 *)(this + 200) = uVar2;
      *(undefined4 *)(this + 0xec) = 0;
      *(undefined4 *)(this + 0xf0) = 0;
      *(undefined4 *)(this + 0xb8) = 0x3f800000;
      *(undefined4 *)(this + 0xcc) = 0x3f800000;
      *(undefined4 *)(this + 0xe0) = 0x3f800000;
      *(undefined4 *)(this + 0xf4) = 0x3f800000;
      fVar4 = extraout_s1;
      goto LAB_00088bf2;
    }
    *(undefined4 *)(this + 0xac) = 0;
    *(undefined4 *)(this + 0xb0) = 0;
    uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar1 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    *(undefined4 *)(this + 0x9c) = 0;
    *(undefined4 *)(this + 0xa0) = uVar3;
    *(undefined4 *)(this + 0xa4) = uVar1;
    *(undefined4 *)(this + 0xa8) = uVar2;
    *(undefined4 *)(this + 0x8c) = 0;
    *(undefined4 *)(this + 0x90) = uVar3;
    *(undefined4 *)(this + 0x94) = uVar1;
    *(undefined4 *)(this + 0x98) = uVar2;
    *(undefined4 *)(this + 0x7c) = 0;
    *(undefined4 *)(this + 0x80) = uVar3;
    *(undefined4 *)(this + 0x84) = uVar1;
    *(undefined4 *)(this + 0x88) = uVar2;
    *(float *)(this + 0x78) = 2.0 / fVar4;
    *(float *)(this + 0x8c) = -(2.0 / fVar6);
    *(undefined4 *)(this + 0xa0) = 0xbd4ccccd;
    *(undefined4 *)(this + 0xb4) = 0x3f800000;
    *(undefined4 *)(this + 0xa8) = 0xbf800000;
    *(undefined4 *)(this + 0xac) = 0x3f800000;
    *(undefined4 *)(this + 0xe4) = 0;
    *(undefined4 *)(this + 0xe8) = uVar3;
    *(undefined4 *)(this + 0xec) = uVar1;
    *(undefined4 *)(this + 0xf0) = uVar2;
    *(undefined4 *)(this + 0xd8) = 0;
    *(undefined4 *)(this + 0xdc) = uVar3;
    *(undefined4 *)(this + 0xe0) = uVar1;
    *(undefined4 *)(this + 0xe4) = uVar2;
    *(undefined4 *)(this + 200) = 0;
    *(undefined4 *)(this + 0xcc) = uVar3;
    *(undefined4 *)(this + 0xd0) = uVar1;
    *(undefined4 *)(this + 0xd4) = uVar2;
    *(undefined4 *)(this + 0xb8) = 0;
    *(undefined4 *)(this + 0xbc) = uVar3;
    *(undefined4 *)(this + 0xc0) = uVar1;
    *(undefined4 *)(this + 0xc4) = uVar2;
    *(undefined4 *)(this + 0xbc) = 0xbf800000;
    *(undefined4 *)(this + 200) = 0x3f800000;
    *(undefined4 *)(this + 0xe0) = 0x3f800000;
    *(undefined4 *)(this + 0xf4) = 0x3f800000;
    uVar3 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
    fVar4 = extraout_s1_00;
    fVar6 = extraout_s2;
  }
  fVar5 = (float)VectorSignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  *(float *)(this + 0xec) = fVar5;
LAB_00088bf2:
  if (*(int *)(this + 0x170) == -1) {
    return;
  }
  SetProjectionMatrix3d(this,fVar5,fVar4,fVar6);
  return;
}

// ===== AbyssEngine::PaintCanvas::Initialize  @0x00088c1c  (258 bytes)
/* AbyssEngine::PaintCanvas::Initialize(bool) */

void __thiscall AbyssEngine::PaintCanvas::Initialize(PaintCanvas *this,bool param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float extraout_s1;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  
  uVar2 = 0;
  if (param_1) {
    uVar2 = 2;
  }
  *(undefined4 *)(this + 0x30) = uVar2;
  Engine::SetScreenOrientation(*(undefined4 *)(this + 0x34));
  uVar2 = 0;
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar7 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar8 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xac) = uVar6;
  *(undefined4 *)(this + 0xb0) = uVar7;
  *(undefined4 *)(this + 0xb4) = uVar8;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = uVar6;
  *(undefined4 *)(this + 0xa0) = uVar7;
  *(undefined4 *)(this + 0xa4) = uVar8;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = uVar6;
  *(undefined4 *)(this + 0x90) = uVar7;
  *(undefined4 *)(this + 0x94) = uVar8;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = uVar6;
  *(undefined4 *)(this + 0x80) = uVar7;
  *(undefined4 *)(this + 0x84) = uVar8;
  iVar3 = *(int *)(this + 0x30);
  uVar1 = Engine::GetDisplayWidth(*(Engine **)(this + 0x34));
  fVar9 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  uVar1 = Engine::GetDisplayHeight(*(Engine **)(this + 0x34));
  fVar5 = 2.0;
  fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
  if (iVar3 == 2) {
    fVar5 = 2.0 / fVar9;
    *(float *)(this + 0x78) = fVar5;
    fVar9 = fVar4;
  }
  else {
    *(float *)(this + 0x78) = 2.0 / fVar4;
    *(undefined4 *)(this + 0xe4) = uVar2;
    *(undefined4 *)(this + 0xe8) = uVar6;
    *(undefined4 *)(this + 0xec) = uVar7;
    *(undefined4 *)(this + 0xf0) = uVar8;
    *(undefined4 *)(this + 0xd8) = uVar2;
    *(undefined4 *)(this + 0xdc) = uVar6;
    *(undefined4 *)(this + 0xe0) = uVar7;
    *(undefined4 *)(this + 0xe4) = uVar8;
    *(undefined4 *)(this + 200) = uVar2;
    *(undefined4 *)(this + 0xcc) = uVar6;
    *(undefined4 *)(this + 0xd0) = uVar7;
    *(undefined4 *)(this + 0xd4) = uVar8;
    *(undefined4 *)(this + 0xb8) = uVar2;
    *(undefined4 *)(this + 0xbc) = uVar6;
    *(undefined4 *)(this + 0xc0) = uVar7;
    *(undefined4 *)(this + 0xc4) = uVar8;
    *(undefined4 *)(this + 0xbc) = 0xbf800000;
    *(undefined4 *)(this + 200) = 0x3f800000;
    *(undefined4 *)(this + 0xe0) = 0x3f800000;
    *(undefined4 *)(this + 0xf4) = 0x3f800000;
    *(float *)(this + 0xec) = fVar9;
  }
  *(float *)(this + 0x8c) = -2.0 / fVar9;
  *(undefined4 *)(this + 0xa0) = 0xbd4ccccd;
  *(undefined4 *)(this + 0xb4) = 0x3f800000;
  *(undefined4 *)(this + 0xa8) = 0xbf800000;
  *(undefined4 *)(this + 0xac) = 0x3f800000;
  SetProjectionMatrix3d(this,-2.0 / fVar9,extraout_s1,fVar5);
  return;
}

// ===== AbyssEngine::PaintCanvas::GetGravValue  @0x00088d1c  (8 bytes)
/* AbyssEngine::PaintCanvas::GetGravValue() */

void AbyssEngine::PaintCanvas::GetGravValue(void)

{
  int in_r0;
  
  Engine::GetGravValue(*(Engine **)(in_r0 + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::GetAccelValue  @0x00088d22  (8 bytes)
/* AbyssEngine::PaintCanvas::GetAccelValue() */

void AbyssEngine::PaintCanvas::GetAccelValue(void)

{
  int in_r0;
  
  Engine::GetAccelValue(*(Engine **)(in_r0 + 0x34));
  return;
}

// ===== AbyssEngine::PaintCanvas::Suspend  @0x00088d28  (96 bytes)
/* AbyssEngine::PaintCanvas::Suspend() */

void __thiscall AbyssEngine::PaintCanvas::Suspend(PaintCanvas *this)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_20;
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar1 = *(uint *)(this + 0x10);
  if (uVar1 != 0) {
    iVar2 = *(int *)(this + 0x14);
    uVar4 = 0;
    do {
      piVar3 = *(int **)(iVar2 + uVar4 * 4);
      local_20 = *piVar3;
      if (local_20 != -1) {
        glDeleteTextures(1,&local_20);
        uVar1 = *(uint *)(this + 0x10);
        iVar2 = *(int *)(this + 0x14);
        piVar3 = *(int **)(iVar2 + uVar4 * 4);
      }
      uVar4 = uVar4 + 1;
      *piVar3 = -1;
    } while (uVar4 < uVar1);
  }
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::Resume  @0x00088d90  (186 bytes)
/* AbyssEngine::PaintCanvas::Resume() */

void __thiscall AbyssEngine::PaintCanvas::Resume(PaintCanvas *this)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  if (*(int *)(this + 0x10) != 0) {
    uVar3 = 0;
    do {
      local_24 = 0;
      pcVar1 = (char *)String::GetAEChar((String *)(*(int *)(*(int *)(this + 0x14) + uVar3 * 4) + 4)
                                        );
      iVar2 = TextureCreateFromFile
                        (*(Engine **)(this + 0x34),pcVar1,(_func_void_Image_ptr_void_ptr *)0x0,
                         (void *)0x0,&local_24,false,
                         *(float *)(*(int *)(*(int *)(this + 0x14) + uVar3 * 4) + 0xc));
      if (iVar2 == 1) {
        **(uint **)(*(int *)(this + 0x14) + uVar3 * 4) = local_24;
      }
      if (pcVar1 != (char *)0x0) {
        operator_delete__(pcVar1);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(this + 0x10));
  }
  if (CubeMapSetIndex != 0) {
    glActiveTexture(0x84c7);
    glBindTexture(0x8513,**(undefined4 **)(*(int *)(this + 0x14) + CubeMapSetIndex * 4));
    glActiveTexture(0x84c0);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::ReloadTextures  @0x00088e5c  (144 bytes)
/* AbyssEngine::PaintCanvas::ReloadTextures() */

void __thiscall AbyssEngine::PaintCanvas::ReloadTextures(PaintCanvas *this)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint local_24;
  int local_20;
  
  local_20 = __stack_chk_guard;
  uVar1 = *(uint *)(this + 0x10);
  if (uVar1 != 0) {
    uVar5 = 0;
    do {
      piVar4 = *(int **)(*(int *)(this + 0x14) + uVar5 * 4);
      if (*piVar4 == -1) {
        local_24 = 0;
        pcVar2 = (char *)String::GetAEChar((String *)(piVar4 + 1));
        iVar3 = TextureCreateFromFile
                          (*(Engine **)(this + 0x34),pcVar2,(_func_void_Image_ptr_void_ptr *)0x0,
                           (void *)0x0,&local_24,false,
                           *(float *)(*(int *)(*(int *)(this + 0x14) + uVar5 * 4) + 0xc));
        if (iVar3 == 1) {
          **(uint **)(*(int *)(this + 0x14) + uVar5 * 4) = local_24;
        }
        if (pcVar2 != (char *)0x0) {
          operator_delete__(pcVar2);
        }
        uVar1 = *(uint *)(this + 0x10);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  if (__stack_chk_guard != local_20) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AbyssEngine::PaintCanvas::WarmUpTexture  @0x00088ef4  (4 bytes)
/* AbyssEngine::PaintCanvas::WarmUpTexture() */

undefined4 AbyssEngine::PaintCanvas::WarmUpTexture(void)

{
  return 1;
}

// ===== AbyssEngine::PaintCanvas::DrawMesh  @0x00088f00  (1286 bytes)
/* AbyssEngine::PaintCanvas::DrawMesh(AbyssEngine::Mesh*, AbyssEngine::AEMath::Matrix&,
   AbyssEngine::AEMath::Matrix&, unsigned int, AbyssEngine::AEMath::Matrix&) */

void AbyssEngine::PaintCanvas::DrawMesh
               (Mesh *param_1,Matrix *param_2,Matrix *param_3,uint param_4,Matrix *param_5)

{
  byte bVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  Matrix *pMVar6;
  uint in_fpscr;
  uint uVar7;
  float fVar8;
  float in_s1;
  float extraout_s1;
  float extraout_s1_00;
  float in_s2;
  float extraout_s2;
  undefined8 uVar9;
  longlong lVar10;
  float extraout_s3;
  float fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  undefined4 *in_stack_00000004;
  AEMath aAStack_2b8 [60];
  AEMath aAStack_27c [60];
  AEMath aAStack_240 [60];
  AEMath aAStack_204 [60];
  undefined4 local_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 local_1bc;
  undefined4 uStack_1b8;
  undefined4 local_1b4;
  undefined4 uStack_1b0;
  undefined4 local_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  float local_188;
  float fStack_184;
  float local_180;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined4 local_150;
  undefined4 local_148 [5];
  undefined4 local_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined4 local_110;
  undefined4 local_108 [5];
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int local_4c;
  
  local_4c = __stack_chk_guard;
  local_88 = *(undefined4 *)param_3;
  local_84 = *(undefined4 *)(param_3 + 4);
  local_80 = *(undefined4 *)(param_3 + 8);
  local_7c = *(undefined4 *)(param_3 + 0xc);
  local_78 = *(undefined4 *)(param_3 + 0x10);
  local_74 = *(undefined4 *)(param_3 + 0x14);
  local_70 = *(undefined4 *)(param_3 + 0x18);
  uStack_6c = *(undefined4 *)(param_3 + 0x1c);
  local_68 = *(undefined4 *)(param_3 + 0x20);
  uStack_64 = *(undefined4 *)(param_3 + 0x24);
  local_60 = *(undefined4 *)(param_3 + 0x28);
  uStack_5c = *(undefined4 *)(param_3 + 0x2c);
  local_58 = *(undefined4 *)(param_3 + 0x30);
  uStack_54 = *(undefined4 *)(param_3 + 0x34);
  uStack_50 = *(undefined4 *)(param_3 + 0x38);
  local_c8 = *in_stack_00000004;
  local_c4 = in_stack_00000004[1];
  local_c0 = in_stack_00000004[2];
  local_bc = in_stack_00000004[3];
  local_b8 = in_stack_00000004[4];
  local_b4 = in_stack_00000004[5];
  local_b0 = in_stack_00000004[6];
  uStack_ac = in_stack_00000004[7];
  local_a8 = in_stack_00000004[8];
  uStack_a4 = in_stack_00000004[9];
  local_a0 = in_stack_00000004[10];
  uStack_9c = in_stack_00000004[0xb];
  local_98 = in_stack_00000004[0xc];
  uStack_94 = in_stack_00000004[0xd];
  uStack_90 = in_stack_00000004[0xe];
  pMVar6 = param_5;
  if (*(int *)(param_2 + 0x34) != 0) {
    uVar12 = 0;
    uVar13 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    uVar14 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    uVar15 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    puVar3 = (undefined4 *)((uint)local_108 | 4);
    local_108[0] = 0x3f800000;
    *puVar3 = 0;
    puVar3[1] = uVar13;
    puVar3[2] = uVar14;
    puVar3[3] = uVar15;
    local_f4 = 0x3f800000;
    local_f0 = 0;
    local_e0 = 0x3f800000;
    uStack_d8 = 0x3f8000003f800000;
    puVar3 = (undefined4 *)((uint)local_148 | 4);
    local_148[0] = 0x3f800000;
    *puVar3 = 0;
    puVar3[1] = uVar13;
    puVar3[2] = uVar14;
    puVar3[3] = uVar15;
    local_134 = 0x3f800000;
    local_130 = 0;
    local_120 = 0x3f800000;
    uStack_118 = 0x3f8000003f800000;
    local_d0 = 0x3f800000;
    local_110 = 0x3f800000;
    uStack_12c = uVar13;
    uStack_128 = uVar14;
    uStack_124 = uVar15;
    uStack_ec = uVar13;
    uStack_e8 = uVar14;
    uStack_e4 = uVar15;
    AEMath::MatrixSetTranslation
              ((AEMath *)&local_188,(Matrix *)local_108,*(float *)(param_2 + 0x54),in_s1,in_s2);
    AEMath::MatrixSetTranslation
              ((AEMath *)&local_188,(Matrix *)local_148,-*(float *)(param_2 + 0x54),extraout_s1,
               extraout_s2);
    puVar3 = (undefined4 *)((uint)&local_188 | 4);
    local_188 = 1.0;
    *puVar3 = uVar12;
    puVar3[1] = uVar13;
    puVar3[2] = uVar14;
    puVar3[3] = uVar15;
    local_174 = 0x3f800000;
    local_160 = 0x3f800000;
    uStack_158 = 0x3f8000003f800000;
    local_150 = 0x3f800000;
    local_170 = uVar12;
    uStack_16c = uVar13;
    uStack_168 = uVar14;
    uStack_164 = uVar15;
    AEMath::MatrixGetPosition(aAStack_204,(Matrix *)(*(int *)(param_2 + 0x34) + 0x5c));
    AEMath::MatrixSetTranslation((AEMath *)&local_1c8,(AEMath *)&local_188,(Vector *)aAStack_204);
    iVar4 = *(int *)(param_2 + 0x34);
    local_1c8 = *(undefined4 *)(iVar4 + 0x5c);
    uStack_1c4 = *(undefined4 *)(iVar4 + 0x60);
    uStack_1c0 = *(undefined4 *)(iVar4 + 100);
    uStack_1b8 = *(undefined4 *)(iVar4 + 0x6c);
    local_1b4 = *(undefined4 *)(iVar4 + 0x70);
    uStack_1b0 = *(undefined4 *)(iVar4 + 0x74);
    uStack_1a8 = *(undefined4 *)(iVar4 + 0x7c);
    uStack_1a4 = *(undefined4 *)(iVar4 + 0x80);
    local_1a0 = *(undefined4 *)(iVar4 + 0x84);
    uStack_198 = *(undefined4 *)(iVar4 + 0x8c);
    uStack_194 = *(undefined4 *)(iVar4 + 0x90);
    uStack_190 = *(undefined4 *)(iVar4 + 0x94);
    local_1bc = 0;
    local_1ac = 0;
    local_19c = 0;
    AEMath::operator*(aAStack_2b8,param_3,(AEMath *)&local_188);
    AEMath::operator*(aAStack_27c,aAStack_2b8,(Matrix *)local_148);
    AEMath::operator*(aAStack_240,aAStack_27c,(AEMath *)&local_1c8);
    AEMath::operator*(aAStack_204,aAStack_240,(Matrix *)local_108);
    AEMath::Matrix::operator=((Matrix *)&local_88,aAStack_204);
    uVar5 = *(uint *)(*(int *)(param_2 + 0x34) + 0x48);
    AEMath::Matrix::operator=((Matrix *)&local_c8,(Matrix *)(*(int *)(param_2 + 0x34) + 0x98));
    pMVar6 = (Matrix *)
             ((uVar5 >> 0x18) * ((uint)param_5 >> 0x18) * 0x10000 & 0xff000000 |
              ((uVar5 & 0xffff) >> 8) * (((uint)param_5 & 0xffff) >> 8) & 0xffffff00 |
              (uVar5 & 0xff) * ((uint)param_5 & 0xff) >> 8 |
             ((uVar5 & 0xffffff) >> 0x10) * (((uint)param_5 & 0xffffff) >> 0x10) * 0x100 & 0xff00ff)
    ;
  }
  AEMath::MatrixTransformVector((AEMath *)local_148,(Matrix *)&local_88,(Vector *)(param_2 + 0x3c));
  local_188 = *(float *)(param_2 + 0x48);
  fStack_184 = local_188;
  local_180 = local_188;
  AEMath::MatrixRotateVector((AEMath *)local_108,(Matrix *)&local_88,(Vector *)&local_188);
  AEMath::Vector::operator=((Vector *)&local_188,(Vector *)local_108);
  uVar2 = CONCAT44(fStack_184,local_188);
  uVar16 = FloatVectorNeg(uVar2,2,2);
  uVar9 = FloatVectorCompareGreaterThan(uVar2,0,2);
  lVar10 = VectorBitwiseSelect(uVar9,uVar2,uVar16);
  if ((float)((ulonglong)lVar10 >> 0x20) < (float)lVar10) {
    lVar10 = lVar10 << 0x20;
  }
  fVar8 = -local_180;
  if (0.0 < local_180) {
    fVar8 = local_180;
  }
  if (*(short *)(param_2 + 2) != 0) {
    fVar11 = (float)((ulonglong)lVar10 >> 0x20);
    uVar5 = in_fpscr & 0xfffffff | (uint)(fVar11 < fVar8) << 0x1f | (uint)(fVar11 == fVar8) << 0x1e;
    uVar7 = uVar5 | (uint)(NAN(fVar11) || NAN(fVar8)) << 0x1c;
    bVar1 = (byte)(uVar5 >> 0x18);
    if (!(bool)(bVar1 >> 6 & 1) && bVar1 >> 7 == ((byte)(uVar7 >> 0x1c) & 1)) {
      fVar8 = fVar11;
    }
    iVar4 = CameraIsSphereinViewFrustum
                      ((PaintCanvas *)param_1,(Vector *)local_148,fVar8 * *(float *)(param_2 + 0x4c)
                      );
    if (iVar4 != 1) {
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      goto LAB_000893e6;
    }
    if (*(short *)(param_2 + 2) != 0) {
      if (*(int *)(param_2 + 0x30) == 0) {
        fVar8 = (float)VectorUnsignedToFloat((uint)pMVar6 >> 0x18,(byte)(uVar7 >> 0x16) & 3);
        fVar11 = (float)VectorUnsignedToFloat
                                  (((uint)pMVar6 & 0xffffff) >> 0x10,(byte)(uVar7 >> 0x16) & 3);
        VectorUnsignedToFloat(((uint)pMVar6 & 0xffff) >> 8,(byte)(uVar7 >> 0x16) & 3);
        VectorUnsignedToFloat((uint)pMVar6 & 0xff,(byte)(uVar7 >> 0x16) & 3);
        Engine::SetColor(*(Engine **)(param_1 + 0x34),(fVar8 * *(float *)(param_1 + 0x1fc)) / 255.0,
                         extraout_s1_00,(fVar11 * *(float *)(param_1 + 0x200)) / 255.0,extraout_s3);
        AEMath::operator*((AEMath *)local_108,(Matrix *)param_4,(Matrix *)&local_88);
        Engine::SetWorldViewMatrix(*(Engine **)(param_1 + 0x34),(AEMath *)local_108);
        Engine::SetModelMatrix(*(Engine **)(param_1 + 0x34),(Matrix *)&local_88);
        Engine::SetUVMatrix(*(Engine **)(param_1 + 0x34),(Matrix *)&local_c8);
        MeshDraw(*(Engine **)(param_1 + 0x34),(Mesh *)param_2);
        Engine::ResetUVMatrix(*(Engine **)(param_1 + 0x34));
      }
      else {
        ArrayAddCached<AbyssEngine::Mesh*>
                  ((Mesh *)param_2,(Array *)(*(int *)(param_2 + 0x30) + 0x44));
        ArrayAddCached<AbyssEngine::AEMath::Matrix>
                  (local_88,local_84,local_80,local_7c,local_78,local_74,local_70,uStack_6c,local_68
                   ,uStack_64,local_60,uStack_5c,local_58,uStack_54,uStack_50,
                   *(int *)(param_2 + 0x30) + 0x2c);
        ArrayAddCached<AbyssEngine::AEMath::Matrix>
                  (local_c8,local_c4,local_c0,local_bc,local_b8,local_b4,local_b0,uStack_ac,local_a8
                   ,uStack_a4,local_a0,uStack_9c,local_98,uStack_94,uStack_90,
                   *(int *)(param_2 + 0x30) + 0x38);
        ArrayAddCached<AbyssEngine::AEMath::Matrix>
                  (*(undefined4 *)param_4,*(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 8),
                   *(undefined4 *)(param_4 + 0xc),*(undefined4 *)(param_4 + 0x10),
                   *(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x18),
                   *(undefined4 *)(param_4 + 0x1c),*(undefined4 *)(param_4 + 0x20),
                   *(undefined4 *)(param_4 + 0x24),*(undefined4 *)(param_4 + 0x28),
                   *(undefined4 *)(param_4 + 0x2c),*(undefined4 *)(param_4 + 0x30),
                   *(undefined4 *)(param_4 + 0x34),*(undefined4 *)(param_4 + 0x38),
                   *(int *)(param_2 + 0x30) + 0x5c);
        ArrayAddCached<unsigned_int>((uint)pMVar6,(Array *)(*(int *)(param_2 + 0x30) + 0x50));
      }
    }
  }
  iVar4 = *(int *)(param_2 + 0x34);
  if (iVar4 != 0) {
    uVar5 = *(int *)(iVar4 + 0x3c) - 1;
    if (-1 < (int)uVar5) {
      do {
        DrawMesh(param_1,*(Matrix **)(*(int *)(iVar4 + 0x40) + uVar5 * 4),(Matrix *)&local_88,
                 param_4,param_5);
        iVar4 = *(int *)(param_2 + 0x34);
        uVar5 = uVar5 - 1;
      } while (uVar5 < 0x80000000);
    }
    if (*(int *)(iVar4 + 0x4c) != 0) {
      uVar5 = 0;
      do {
        if ((*(uint *)(param_1 + 0x170) < *(uint *)(param_1 + 0x164)) &&
           (iVar4 = Transform::InCameraVF
                              (*(Transform **)(*(int *)(iVar4 + 0x50) + uVar5 * 4),param_3,
                               *(Camera **)
                                (*(int *)(param_1 + 0x168) + *(uint *)(param_1 + 0x170) * 4)),
           iVar4 == 1)) {
          DrawTransform((PaintCanvas *)param_1,
                        *(Transform **)(*(int *)(*(int *)(param_2 + 0x34) + 0x50) + uVar5 * 4),
                        (Matrix *)&local_88,(Matrix *)param_4);
        }
        iVar4 = *(int *)(param_2 + 0x34);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(iVar4 + 0x4c));
    }
  }
LAB_000893e6:
  if (__stack_chk_guard != local_4c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

