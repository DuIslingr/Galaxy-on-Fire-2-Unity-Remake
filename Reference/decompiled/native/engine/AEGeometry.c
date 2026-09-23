// Class: AEGeometry
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AEGeometry::AEGeometry  @0x000b0d20  (216 bytes)
/* AEGeometry::AEGeometry(unsigned short, AbyssEngine::PaintCanvas*, bool) */

AEGeometry * __thiscall
AEGeometry::AEGeometry(AEGeometry *this,ushort param_1,PaintCanvas *param_2,bool param_3)

{
  AEGeometry *pAVar1;
  Matrix *pMVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar3 = 0;
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar5 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar6 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x3f80000000000000;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = uVar4;
  *(undefined4 *)(this + 0x90) = uVar5;
  *(undefined4 *)(this + 0x94) = uVar6;
  *(undefined4 *)(this + 0x98) = 0x3f800000;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = uVar4;
  *(undefined4 *)(this + 0xa4) = uVar5;
  *(undefined4 *)(this + 0xa8) = uVar6;
  *(undefined8 *)(this + 0xac) = 0x3f800000;
  *(undefined8 *)(this + 0xb4) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xbc) = 0x3f800000;
  *(ushort *)(this + 8) = param_1;
  *(PaintCanvas **)(this + 0x2c) = param_2;
  *(undefined4 *)(this + 0xc) = 0;
  pAVar1 = this + 0x18;
  *(uint *)pAVar1 = 0;
  AbyssEngine::PaintCanvas::TransformCreate(param_2,(uint *)pAVar1);
  AbyssEngine::PaintCanvas::MeshCreate(param_2,param_1,(uint *)(this + 0x1c),param_3);
  AbyssEngine::PaintCanvas::TransformAddMeshId(param_2,*(uint *)pAVar1,*(uint *)(this + 0x1c));
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x40) = 0x3f800000;
  *(undefined4 *)(this + 0x44) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  this[0x48] = (AEGeometry)0x1;
  this[0x49] = (AEGeometry)0x1;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x54) = uVar3;
  *(undefined4 *)(this + 0x58) = uVar4;
  *(undefined4 *)(this + 0x5c) = uVar5;
  *(undefined4 *)(this + 0x60) = uVar6;
  *(undefined4 *)(this + 100) = 0;
  *(uint *)(this + 0xc) = *(uint *)pAVar1;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = 0xffffffff;
  pMVar2 = (Matrix *)AbyssEngine::PaintCanvas::TransformGetLocal(param_2,*(uint *)pAVar1);
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x84),pMVar2);
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== AEGeometry::AEGeometry  @0x000b0e20  (160 bytes)
/* AEGeometry::AEGeometry(AbyssEngine::PaintCanvas*) */

AEGeometry * __thiscall AEGeometry::AEGeometry(AEGeometry *this,PaintCanvas *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  uVar2 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar3 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0x3f80000000000000;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = uVar2;
  *(undefined4 *)(this + 0x90) = uVar3;
  *(undefined4 *)(this + 0x94) = uVar4;
  *(undefined4 *)(this + 0x98) = 0x3f800000;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0xa0) = uVar2;
  *(undefined4 *)(this + 0xa4) = uVar3;
  *(undefined4 *)(this + 0xa8) = uVar4;
  *(undefined8 *)(this + 0xac) = 0x3f800000;
  *(undefined8 *)(this + 0xb4) = 0x3f8000003f800000;
  *(undefined4 *)(this + 0xbc) = 0x3f800000;
  *(PaintCanvas **)(this + 0x2c) = param_1;
  *(undefined2 *)(this + 8) = 0;
  AbyssEngine::PaintCanvas::TransformCreate(param_1,(uint *)(this + 0x18));
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x40) = 0x3f800000;
  *(undefined4 *)(this + 0x44) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0x3f800000;
  this[0x48] = (AEGeometry)0x1;
  this[0x49] = (AEGeometry)0x1;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x54) = uVar1;
  *(undefined4 *)(this + 0x58) = uVar2;
  *(undefined4 *)(this + 0x5c) = uVar3;
  *(undefined4 *)(this + 0x60) = uVar4;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0x18);
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = 0xffffffff;
  *(undefined4 *)(this + 4) = 0;
  return this;
}

// ===== AEGeometry::~AEGeometry  @0x000b0ee0  (66 bytes)
/* AEGeometry::~AEGeometry() */

AEGeometry * __thiscall AEGeometry::~AEGeometry(AEGeometry *this)

{
  if (*(void **)(this + 0x54) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  if (*(void **)(this + 0x5c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x5c));
  }
  *(undefined4 *)(this + 0x5c) = 0;
  if (*(void **)(this + 0x58) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  if (*(void **)(this + 0x60) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x60));
  }
  *(undefined4 *)(this + 0x60) = 0;
  if (*(void **)(this + 100) != (void *)0x0) {
    operator_delete__(*(void **)(this + 100));
  }
  *(undefined4 *)(this + 100) = 0;
  return this;
}

// ===== AEGeometry::addChild  @0x000b0f22  (32 bytes)
/* AEGeometry::addChild(unsigned int) */

void __thiscall AEGeometry::addChild(AEGeometry *this,uint param_1)

{
  AbyssEngine::PaintCanvas::TransformAddChild
            (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc),param_1);
  if (*(int *)(this + 0x14) != -1) {
    *(int *)(this + 0x10) = *(int *)(this + 0x14);
  }
  *(uint *)(this + 0x14) = param_1;
  return;
}

// ===== AEGeometry::setMesh  @0x000b0f42  (28 bytes)
/* AEGeometry::setMesh(unsigned short) */

void __thiscall AEGeometry::setMesh(AEGeometry *this,ushort param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0xc);
  if (uVar1 == 0) {
    AbyssEngine::PaintCanvas::TransformCreate
              (*(PaintCanvas **)(this + 0x2c),param_1,(uint *)(this + 0xc));
    return;
  }
  AbyssEngine::PaintCanvas::TransformAddMesh(*(PaintCanvas **)(this + 0x2c),uVar1,param_1,false);
  return;
}

// ===== AEGeometry::getParentPosition  @0x000b0f5c  (34 bytes)
/* AEGeometry::getParentPosition() */

void AEGeometry::getParentPosition(void)

{
  AEMath *in_r0;
  Matrix *pMVar1;
  int in_r1;
  uint uVar2;
  
  uVar2 = *(uint *)(in_r1 + 0x24);
  if (uVar2 == 0xffffffff) {
    uVar2 = *(uint *)(in_r1 + 0xc);
  }
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal(*(PaintCanvas **)(in_r1 + 0x2c),uVar2);
  AbyssEngine::AEMath::MatrixGetPosition(in_r0,pMVar1);
  return;
}

// ===== AEGeometry::getPosition  @0x000b0f7e  (26 bytes)
/* AEGeometry::getPosition() */

void AEGeometry::getPosition(void)

{
  AEMath *in_r0;
  Matrix *pMVar1;
  int in_r1;
  
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(in_r1 + 0x2c),*(uint *)(in_r1 + 0xc));
  AbyssEngine::AEMath::MatrixGetPosition(in_r0,pMVar1);
  return;
}

// ===== AEGeometry::getDirection  @0x000b0f98  (26 bytes)
/* AEGeometry::getDirection() */

void AEGeometry::getDirection(void)

{
  AEMath *in_r0;
  Matrix *pMVar1;
  int in_r1;
  
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(in_r1 + 0x2c),*(uint *)(in_r1 + 0xc));
  AbyssEngine::AEMath::MatrixGetDir(in_r0,pMVar1);
  return;
}

// ===== AEGeometry::getUpVector  @0x000b0fb2  (26 bytes)
/* AEGeometry::getUpVector() */

void AEGeometry::getUpVector(void)

{
  AEMath *in_r0;
  Matrix *pMVar1;
  int in_r1;
  
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(in_r1 + 0x2c),*(uint *)(in_r1 + 0xc));
  AbyssEngine::AEMath::MatrixGetUp(in_r0,pMVar1);
  return;
}

// ===== AEGeometry::getRightVector  @0x000b0fcc  (26 bytes)
/* AEGeometry::getRightVector() */

void AEGeometry::getRightVector(void)

{
  AEMath *in_r0;
  Matrix *pMVar1;
  int in_r1;
  
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(in_r1 + 0x2c),*(uint *)(in_r1 + 0xc));
  AbyssEngine::AEMath::MatrixGetRight(in_r0,pMVar1);
  return;
}

// ===== AEGeometry::getRotation  @0x000b0fe6  (14 bytes)
/* AEGeometry::getRotation() */

void AEGeometry::getRotation(void)

{
  undefined4 *in_r0;
  int in_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(in_r1 + 0x34);
  uVar1 = *(undefined4 *)(in_r1 + 0x38);
  *in_r0 = *(undefined4 *)(in_r1 + 0x30);
  in_r0[1] = uVar2;
  in_r0[2] = uVar1;
  return;
}

// ===== AEGeometry::getScaling  @0x000b0ff4  (14 bytes)
/* AEGeometry::getScaling() */

void AEGeometry::getScaling(void)

{
  undefined4 *in_r0;
  int in_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(in_r1 + 0x40);
  uVar1 = *(undefined4 *)(in_r1 + 0x44);
  *in_r0 = *(undefined4 *)(in_r1 + 0x3c);
  in_r0[1] = uVar2;
  in_r0[2] = uVar1;
  return;
}

// ===== AEGeometry::getMatrix  @0x000b1002  (14 bytes)
/* AEGeometry::getMatrix() */

void __thiscall AEGeometry::getMatrix(AEGeometry *this)

{
  AbyssEngine::PaintCanvas::TransformGetLocal(*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  return;
}

// ===== AEGeometry::setMatrix  @0x000b1010  (12 bytes)
/* AEGeometry::setMatrix(AbyssEngine::AEMath::Matrix const&) */

void AEGeometry::setMatrix(Matrix *param_1)

{
  Matrix *in_r1;
  
  AbyssEngine::PaintCanvas::TransformSetLocal
            (*(PaintCanvas **)(param_1 + 0x2c),*(uint *)(param_1 + 0xc),in_r1);
  return;
}

// ===== AEGeometry::getReferenceMatrix  @0x000b101a  (4 bytes)
/* AEGeometry::getReferenceMatrix() */

AEGeometry * __thiscall AEGeometry::getReferenceMatrix(AEGeometry *this)

{
  return this + 0x84;
}

// ===== AEGeometry::setPosition  @0x000b1020  (80 bytes)
/* AEGeometry::setPosition(AbyssEngine::AEMath::Vector const&) */

void AEGeometry::setPosition(Vector *param_1)

{
  Matrix *pMVar1;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_58 [60];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(param_1 + 0x2c),*(uint *)(param_1 + 0xc));
  AbyssEngine::AEMath::MatrixSetTranslation(aAStack_58,pMVar1,extraout_s0,extraout_s1,extraout_s2);
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::setPosition  @0x000b1078  (66 bytes)
/* AEGeometry::setPosition(float, float, float) */

void AEGeometry::setPosition(float param_1,float param_2,float param_3)

{
  int in_r0;
  Matrix *pMVar1;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_54 [60];
  int local_18;
  
  local_18 = __stack_chk_guard;
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(in_r0 + 0x2c),*(uint *)(in_r0 + 0xc));
  AbyssEngine::AEMath::MatrixSetTranslation(aAStack_54,pMVar1,extraout_s0,extraout_s1,extraout_s2);
  if (__stack_chk_guard != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::setDirection  @0x000b10c4  (254 bytes)
/* AEGeometry::setDirection(AbyssEngine::AEMath::Vector const&, AbyssEngine::AEMath::Vector const&)
    */

void __thiscall AEGeometry::setDirection(AEGeometry *this,Vector *param_1,Vector *param_2)

{
  undefined4 *puVar1;
  Matrix *pMVar2;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_c0 [60];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_28;
  
  local_28 = __stack_chk_guard;
  puVar1 = (undefined4 *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  local_68 = *puVar1;
  local_64 = puVar1[1];
  local_60 = puVar1[2];
  uStack_5c = puVar1[3];
  local_58 = puVar1[4];
  local_54 = puVar1[5];
  local_50 = puVar1[6];
  uStack_4c = puVar1[7];
  local_48 = puVar1[8];
  local_44 = puVar1[9];
  local_40 = puVar1[10];
  uStack_3c = puVar1[0xb];
  uStack_38 = puVar1[0xc];
  uStack_34 = puVar1[0xd];
  uStack_30 = puVar1[0xe];
  local_78 = *(undefined8 *)param_2;
  local_70 = *(undefined4 *)(param_2 + 8);
  AbyssEngine::AEMath::VectorCross((AEMath *)&local_84,(Vector *)&local_78,param_1);
  AbyssEngine::AEMath::VectorNormalize(aAStack_c0,(Vector *)&local_84);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_84,(Vector *)aAStack_c0);
  AbyssEngine::AEMath::VectorCross(aAStack_c0,param_1,(Vector *)&local_84);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_78,(Vector *)aAStack_c0);
  AbyssEngine::AEMath::VectorNormalize(aAStack_c0,(Vector *)&local_78);
  AbyssEngine::AEMath::Vector::operator=((Vector *)&local_78,(Vector *)aAStack_c0);
  local_68 = local_84;
  local_58 = local_80;
  local_48 = local_7c;
  local_64 = (undefined4)local_78;
  local_54 = local_78._4_4_;
  local_44 = local_70;
  local_60 = *(undefined4 *)param_1;
  local_50 = *(undefined4 *)(param_1 + 4);
  local_40 = *(undefined4 *)(param_1 + 8);
  AbyssEngine::PaintCanvas::TransformSetLocal
            (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc),(Matrix *)&local_68);
  pMVar2 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetScaling
            (aAStack_c0,pMVar2,*(float *)(this + 0x44),extraout_s1,extraout_s2);
  if (__stack_chk_guard != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::setRotation  @0x000b11cc  (14 bytes)
/* AEGeometry::setRotation(AbyssEngine::AEMath::Vector const&) */

void AEGeometry::setRotation(Vector *param_1)

{
  float in_s0;
  float in_s1;
  float in_s2;
  
  setRotation((AEGeometry *)param_1,in_s0,in_s1,in_s2);
  return;
}

// ===== AEGeometry::setRotation  @0x000b11d8  (112 bytes)
/* AEGeometry::setRotation(float, float, float) */

void __thiscall AEGeometry::setRotation(AEGeometry *this,float param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  Matrix *pMVar2;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_58 [60];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar1 = AbyssEngine::PaintCanvas::TransformGetLocal
                    (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetRotation(aAStack_58,uVar1);
  pMVar2 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetScaling
            (aAStack_58,pMVar2,*(float *)(this + 0x44),extraout_s1,extraout_s2);
  *(undefined4 *)(this + 0x30) = in_r1;
  *(undefined4 *)(this + 0x34) = in_r2;
  *(undefined4 *)(this + 0x38) = in_r3;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::setScaling  @0x000b1250  (8 bytes)
/* AEGeometry::setScaling(float) */

void AEGeometry::setScaling(float param_1)

{
  AEGeometry *in_r0;
  float in_s1;
  float in_s2;
  
  setScaling(in_r0,param_1,in_s1,in_s2);
  return;
}

// ===== AEGeometry::setScaling  @0x000b1258  (114 bytes)
/* AEGeometry::setScaling(float, float, float) */

void __thiscall AEGeometry::setScaling(AEGeometry *this,float param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  Matrix *pMVar2;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_58 [60];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  uVar1 = AbyssEngine::PaintCanvas::TransformGetLocal
                    (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetRotation
            (aAStack_58,uVar1,*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x34),
             *(undefined4 *)(this + 0x38),*(undefined4 *)(this + 0x4c));
  pMVar2 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetScaling(aAStack_58,pMVar2,extraout_s0,extraout_s1,extraout_s2);
  *(undefined4 *)(this + 0x3c) = in_r1;
  *(undefined4 *)(this + 0x40) = in_r2;
  *(undefined4 *)(this + 0x44) = in_r3;
  if (__stack_chk_guard != local_1c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::setScaling  @0x000b12d4  (12 bytes)
/* AEGeometry::setScaling(AbyssEngine::AEMath::Vector const&) */

void AEGeometry::setScaling(Vector *param_1)

{
  float in_s0;
  float in_s1;
  float in_s2;
  
  setScaling((AEGeometry *)param_1,in_s0,in_s1,in_s2);
  return;
}

// ===== AEGeometry::rotate  @0x000b12e0  (148 bytes)
/* AEGeometry::rotate(float, float, float) */

void __thiscall AEGeometry::rotate(AEGeometry *this,float param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  Matrix *pMVar2;
  float in_r1;
  float in_r2;
  float in_r3;
  float extraout_s1;
  float extraout_s2;
  AEMath aAStack_50 [60];
  int local_14;
  
  local_14 = __stack_chk_guard;
  *(float *)(this + 0x30) = *(float *)(this + 0x30) + in_r1;
  *(float *)(this + 0x34) = *(float *)(this + 0x34) + in_r2;
  *(float *)(this + 0x38) = *(float *)(this + 0x38) + in_r3;
  uVar1 = AbyssEngine::PaintCanvas::TransformGetLocal
                    (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetRotation
            (aAStack_50,uVar1,*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x34),
             *(undefined4 *)(this + 0x38),*(undefined4 *)(this + 0x4c));
  pMVar2 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetScaling
            (aAStack_50,pMVar2,*(float *)(this + 0x44),extraout_s1,extraout_s2);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::rotate  @0x000b137c  (14 bytes)
/* AEGeometry::rotate(AbyssEngine::AEMath::Vector const&) */

void AEGeometry::rotate(Vector *param_1)

{
  float in_s0;
  float in_s1;
  float in_s2;
  
  rotate((AEGeometry *)param_1,in_s0,in_s1,in_s2);
  return;
}

// ===== AEGeometry::translate  @0x000b1388  (12 bytes)
/* AEGeometry::translate(AbyssEngine::AEMath::Vector const&) */

void AEGeometry::translate(Vector *param_1)

{
  float in_s0;
  float in_s1;
  float in_s2;
  
  translate((AEGeometry *)param_1,in_s0,in_s1,in_s2);
  return;
}

// ===== AEGeometry::translate  @0x000b1394  (164 bytes)
/* AEGeometry::translate(float, float, float) */

void __thiscall AEGeometry::translate(AEGeometry *this,float param_1,float param_2,float param_3)

{
  undefined4 *puVar1;
  float in_r2;
  float in_r3;
  float extraout_s1;
  AEMath aAStack_ac [60];
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  float local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  float local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int local_34;
  
  local_34 = __stack_chk_guard;
  puVar1 = (undefined4 *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  local_70 = *puVar1;
  uStack_6c = puVar1[1];
  uStack_68 = puVar1[2];
  local_64 = puVar1[3];
  uStack_60 = puVar1[4];
  local_5c = puVar1[5];
  uStack_58 = puVar1[6];
  local_54 = (float)puVar1[7];
  uStack_50 = puVar1[8];
  uStack_4c = puVar1[9];
  local_48 = puVar1[10];
  local_44 = (float)puVar1[0xb];
  uStack_40 = puVar1[0xc];
  uStack_3c = puVar1[0xd];
  uStack_38 = puVar1[0xe];
  AbyssEngine::AEMath::MatrixSetTranslation
            (aAStack_ac,(Matrix *)&local_70,local_44 + in_r3,extraout_s1,local_54 + in_r2);
  AbyssEngine::PaintCanvas::TransformSetLocal
            (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc),(Matrix *)&local_70);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::moveForward  @0x000b1440  (188 bytes)
/* AEGeometry::moveForward(float) */

void __thiscall AEGeometry::moveForward(AEGeometry *this,float param_1)

{
  Matrix *pMVar1;
  float in_r1;
  float extraout_s0;
  float extraout_s1;
  float extraout_s2;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  AEMath aAStack_70 [60];
  int local_34;
  
  local_34 = __stack_chk_guard;
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixGetDir(aAStack_70,pMVar1);
  AbyssEngine::AEMath::VectorNormalize((AEMath *)&local_7c,(Vector *)aAStack_70);
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixGetPosition((AEMath *)&local_88,pMVar1);
  local_88 = local_88 + local_7c * in_r1;
  local_84 = local_84 + local_78 * in_r1;
  local_80 = local_80 + local_74 * in_r1;
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::MatrixSetTranslation(aAStack_70,pMVar1,extraout_s0,extraout_s1,extraout_s2);
  if (__stack_chk_guard != local_34) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::setVisible  @0x000b1504  (10 bytes)
/* AEGeometry::setVisible(bool) */

void __thiscall AEGeometry::setVisible(AEGeometry *this,bool param_1)

{
  this[0x48] = (AEGeometry)param_1;
  this[0x49] = (AEGeometry)param_1;
  return;
}

// ===== AEGeometry::isVisible  @0x000b150e  (6 bytes)
/* AEGeometry::isVisible() */

AEGeometry __thiscall AEGeometry::isVisible(AEGeometry *this)

{
  return this[0x48];
}

// ===== AEGeometry::render  @0x000b1514  (18 bytes)
/* AEGeometry::render() */

void __thiscall AEGeometry::render(AEGeometry *this)

{
  if (this[0x48] == (AEGeometry)0x0) {
    return;
  }
  AbyssEngine::PaintCanvas::DrawTransform
            (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc),(Matrix *)0x0);
  return;
}

// ===== AEGeometry::getID  @0x000b1526  (4 bytes)
/* AEGeometry::getID() */

undefined2 __thiscall AEGeometry::getID(AEGeometry *this)

{
  return *(undefined2 *)(this + 8);
}

// ===== AEGeometry::setRotationOrder  @0x000b152a  (4 bytes)
/* AEGeometry::setRotationOrder(AbyssEngine::AEMath::RotationOrder) */

void __thiscall AEGeometry::setRotationOrder(AEGeometry *this,undefined4 param_2)

{
  *(undefined4 *)(this + 0x4c) = param_2;
  return;
}

// ===== AEGeometry::updateReferenceMatrix  @0x000b152e  (30 bytes)
/* AEGeometry::updateReferenceMatrix() */

void __thiscall AEGeometry::updateReferenceMatrix(AEGeometry *this)

{
  Matrix *pMVar1;
  
  pMVar1 = (Matrix *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x84),pMVar1);
  return;
}

// ===== AEGeometry::setLodLastVisibleDistance  @0x000b154c  (18 bytes)
/* AEGeometry::setLodLastVisibleDistance(unsigned long long) */

void AEGeometry::setLodLastVisibleDistance(ulonglong param_1)

{
  uint in_r2;
  int in_r3;
  
  *(int *)((int)param_1 + 0x70) = (int)((ulonglong)in_r2 * (ulonglong)in_r2);
  *(uint *)((int)param_1 + 0x74) =
       in_r2 * in_r3 + in_r2 * in_r3 + (int)((ulonglong)in_r2 * (ulonglong)in_r2 >> 0x20);
  return;
}

// ===== AEGeometry::setLodChildMeshes  @0x000b155e  (168 bytes)
/* AEGeometry::setLodChildMeshes(unsigned short*) */

void __thiscall AEGeometry::setLodChildMeshes(AEGeometry *this,ushort *param_1)

{
  uint uVar1;
  void *pvVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = *(uint *)(this + 0x50);
  if (0 < (int)uVar4) {
    uVar1 = uVar4 * 2;
    if (uVar1 < uVar4) {
      uVar1 = 0xffffffff;
    }
    pvVar2 = operator_new__(uVar1);
    uVar1 = (uint)((ulonglong)uVar4 * 4);
    *(void **)(this + 0x60) = pvVar2;
    if ((int)((ulonglong)uVar4 * 4 >> 0x20) != 0) {
      uVar1 = 0xffffffff;
    }
    pvVar3 = operator_new__(uVar1);
    iVar5 = 0;
    *(void **)(this + 0x58) = pvVar3;
    while( true ) {
      *(ushort *)((int)pvVar2 + iVar5 * 2) = param_1[iVar5];
      AbyssEngine::PaintCanvas::TransformCreate
                (*(PaintCanvas **)(this + 0x2c),(uint *)((int)pvVar3 + iVar5 * 4));
      AbyssEngine::PaintCanvas::TransformAddMesh
                (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x58) + iVar5 * 4),
                 param_1[iVar5],false);
      AbyssEngine::PaintCanvas::TransformAddChild
                (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar5 * 4),
                 *(uint *)(*(int *)(this + 0x58) + iVar5 * 4));
      AbyssEngine::PaintCanvas::TransformRemoveChild
                (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar5 * 4),
                 *(uint *)(this + 0x14));
      AbyssEngine::PaintCanvas::TransformAddChild
                (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar5 * 4),
                 *(uint *)(this + 0x14));
      iVar5 = iVar5 + 1;
      if (*(int *)(this + 0x50) <= iVar5) break;
      pvVar3 = *(void **)(this + 0x58);
      pvVar2 = *(void **)(this + 0x60);
    }
    return;
  }
  return;
}

// ===== AEGeometry::setLodChildTransform  @0x000b1606  (70 bytes)
/* AEGeometry::setLodChildTransform(unsigned int) */

void __thiscall AEGeometry::setLodChildTransform(AEGeometry *this,uint param_1)

{
  longlong lVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  
  if (0 < (int)*(uint *)(this + 0x50)) {
    lVar1 = (ulonglong)*(uint *)(this + 0x50) * 4;
    uVar2 = (uint)lVar1;
    if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
      uVar2 = 0xffffffff;
    }
    pvVar3 = operator_new__(uVar2);
    iVar4 = 0;
    *(void **)(this + 0x58) = pvVar3;
    do {
      AbyssEngine::PaintCanvas::TransformAddChild
                (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar4 * 4),param_1
                );
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(this + 0x50));
  }
  return;
}

// ===== AEGeometry::setLodMeshesWithMeshIds  @0x000b164c  (234 bytes)
/* AEGeometry::setLodMeshesWithMeshIds(unsigned short*, unsigned int*, int*, int) */

void __thiscall
AEGeometry::setLodMeshesWithMeshIds
          (AEGeometry *this,ushort *param_1,uint *param_2,int *param_3,int param_4)

{
  uint uVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar1 = param_4 * 2;
  if (uVar1 < (uint)param_4) {
    uVar1 = 0xffffffff;
  }
  pvVar2 = operator_new__(uVar1);
  uVar1 = (uint)((ulonglong)(uint)param_4 * 8);
  *(void **)(this + 0x5c) = pvVar2;
  if ((int)((ulonglong)(uint)param_4 * 8 >> 0x20) != 0) {
    uVar1 = 0xffffffff;
  }
  pvVar3 = operator_new__(uVar1);
  uVar1 = (uint)((ulonglong)(uint)param_4 * 4);
  *(void **)(this + 100) = pvVar3;
  *(int *)(this + 0x50) = param_4;
  if ((int)((ulonglong)(uint)param_4 * 4 >> 0x20) != 0) {
    uVar1 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar1);
  *(void **)(this + 0x54) = pvVar4;
  if (0 < param_4) {
    iVar8 = 0;
    while( true ) {
      *(ushort *)((int)pvVar2 + iVar8 * 2) = param_1[iVar8];
      iVar5 = param_3[iVar8];
      *(int *)((int)pvVar3 + iVar8 * 8) = iVar5;
      *(int *)((int)pvVar3 + iVar8 * 8 + 4) = iVar5 >> 0x1f;
      AbyssEngine::PaintCanvas::TransformCreate
                (*(PaintCanvas **)(this + 0x2c),(uint *)((int)pvVar4 + iVar8 * 4));
      AbyssEngine::PaintCanvas::TransformAddMeshId
                (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar8 * 4),
                 param_2[iVar8]);
      iVar5 = *(int *)(this + 100);
      iVar6 = iVar5 + iVar8 * 8;
      uVar1 = *(uint *)(iVar5 + iVar8 * 8);
      iVar7 = *(int *)(iVar6 + 4);
      *(int *)(iVar5 + iVar8 * 8) = (int)((ulonglong)uVar1 * (ulonglong)uVar1);
      *(uint *)(iVar6 + 4) =
           uVar1 * iVar7 + uVar1 * iVar7 + (int)((ulonglong)uVar1 * (ulonglong)uVar1 >> 0x20);
      if (*(uint *)(this + 0x14) != 0xffffffff) {
        AbyssEngine::PaintCanvas::TransformAddChild
                  (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar8 * 4),
                   *(uint *)(this + 0x14));
      }
      iVar8 = iVar8 + 1;
      if (iVar8 == param_4) break;
      pvVar4 = *(void **)(this + 0x54);
      pvVar2 = *(void **)(this + 0x5c);
      pvVar3 = *(void **)(this + 100);
    }
  }
  return;
}

// ===== AEGeometry::setLodMeshes  @0x000b1736  (254 bytes)
/* AEGeometry::setLodMeshes(unsigned short*, int*, int) */

void __thiscall AEGeometry::setLodMeshes(AEGeometry *this,ushort *param_1,int *param_2,int param_3)

{
  uint uVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar1 = param_3 * 2;
  if (uVar1 < (uint)param_3) {
    uVar1 = 0xffffffff;
  }
  pvVar2 = operator_new__(uVar1);
  uVar1 = (uint)((ulonglong)(uint)param_3 * 8);
  *(void **)(this + 0x5c) = pvVar2;
  if ((int)((ulonglong)(uint)param_3 * 8 >> 0x20) != 0) {
    uVar1 = 0xffffffff;
  }
  pvVar3 = operator_new__(uVar1);
  uVar1 = (uint)((ulonglong)(uint)param_3 * 4);
  *(void **)(this + 100) = pvVar3;
  *(int *)(this + 0x50) = param_3;
  if ((int)((ulonglong)(uint)param_3 * 4 >> 0x20) != 0) {
    uVar1 = 0xffffffff;
  }
  pvVar4 = operator_new__(uVar1);
  *(void **)(this + 0x54) = pvVar4;
  if (0 < param_3) {
    iVar8 = 0;
    while( true ) {
      *(ushort *)((int)pvVar2 + iVar8 * 2) = param_1[iVar8];
      iVar5 = param_2[iVar8];
      *(int *)((int)pvVar3 + iVar8 * 8) = iVar5;
      *(int *)((int)pvVar3 + iVar8 * 8 + 4) = iVar5 >> 0x1f;
      AbyssEngine::PaintCanvas::TransformCreate
                (*(PaintCanvas **)(this + 0x2c),(uint *)((int)pvVar4 + iVar8 * 4));
      AbyssEngine::PaintCanvas::TransformAddMesh
                (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar8 * 4),
                 param_1[iVar8],false);
      iVar5 = *(int *)(this + 100);
      iVar6 = iVar5 + iVar8 * 8;
      uVar1 = *(uint *)(iVar5 + iVar8 * 8);
      iVar7 = *(int *)(iVar6 + 4);
      *(int *)(iVar5 + iVar8 * 8) = (int)((ulonglong)uVar1 * (ulonglong)uVar1);
      *(uint *)(iVar6 + 4) =
           uVar1 * iVar7 + uVar1 * iVar7 + (int)((ulonglong)uVar1 * (ulonglong)uVar1 >> 0x20);
      if (*(uint *)(this + 0x14) != 0xffffffff) {
        AbyssEngine::PaintCanvas::TransformAddChild
                  (*(PaintCanvas **)(this + 0x2c),*(uint *)(*(int *)(this + 0x54) + iVar8 * 4),
                   *(uint *)(this + 0x14));
      }
      iVar8 = iVar8 + 1;
      if (iVar8 == param_3) break;
      pvVar4 = *(void **)(this + 0x54);
      pvVar2 = *(void **)(this + 0x5c);
      pvVar3 = *(void **)(this + 100);
    }
  }
  return;
}

// ===== AEGeometry::updateLod  @0x000b1834  (568 bytes)
/* AEGeometry::updateLod(AbyssEngine::AEMath::Vector const&, float) */

void __thiscall AEGeometry::updateLod(AEGeometry *this,Vector *param_1,float param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  Matrix *pMVar3;
  float fVar4;
  LodMeshMerger *pLVar5;
  uint uVar6;
  undefined4 uVar7;
  float in_r2;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  undefined8 uVar14;
  longlong lVar15;
  AEMath aAStack_90 [12];
  AEMath aAStack_84 [12];
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
  this[0x48] = this[0x49];
  puVar2 = (undefined4 *)
           AbyssEngine::PaintCanvas::TransformGetLocal
                     (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
  local_78 = *puVar2;
  uStack_74 = puVar2[1];
  uStack_70 = puVar2[2];
  uStack_6c = puVar2[3];
  uStack_68 = puVar2[4];
  local_64 = puVar2[5];
  uStack_60 = puVar2[6];
  uStack_5c = puVar2[7];
  uStack_58 = puVar2[8];
  uStack_54 = puVar2[9];
  local_50 = puVar2[10];
  uStack_4c = puVar2[0xb];
  uStack_48 = puVar2[0xc];
  uStack_44 = puVar2[0xd];
  uStack_40 = puVar2[0xe];
  if (*(uint *)(this + 0x24) == 0xffffffff) {
    pMVar3 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_90,pMVar3);
    AbyssEngine::AEMath::operator-(aAStack_84,(Vector *)aAStack_90,param_1);
  }
  else {
    pMVar3 = (Matrix *)
             AbyssEngine::PaintCanvas::TransformGetLocal
                       (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0x24));
    AbyssEngine::AEMath::MatrixGetPosition(aAStack_90,pMVar3);
    AbyssEngine::AEMath::operator-(aAStack_84,(Vector *)aAStack_90,param_1);
  }
  AbyssEngine::AEMath::Vector::operator=((Vector *)(this + 0x78),(Vector *)aAStack_84);
  uVar14 = __aeabi_f2ulz(*(float *)(this + 0x78) * *(float *)(this + 0x78) +
                         *(float *)(this + 0x7c) * *(float *)(this + 0x7c) +
                         *(float *)(this + 0x80) * *(float *)(this + 0x80));
  uVar6 = (uint)((ulonglong)uVar14 >> 0x20);
  *(undefined8 *)(this + 0x68) = uVar14;
  uVar8 = *(uint *)(this + 0x74);
  if ((*(uint *)(this + 0x70) == 0 && uVar8 == 0) ||
     (bVar1 = (uint)(*(uint *)(this + 0x70) <= (uint)uVar14) <= uVar6 - uVar8,
     this[0x48] = (AEGeometry)(uVar6 <= uVar8 && bVar1), uVar6 <= uVar8 && bVar1)) {
    AbyssEngine::PaintCanvas::TransformGetTransform
              (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0xc));
    fVar12 = 1.0;
    if (in_r2 <= 0.66) {
      fVar12 = 0.75;
    }
    iVar9 = -8;
    iVar11 = 0;
    fVar13 = 0.5;
    if (0.33 < in_r2) {
      fVar13 = fVar12;
    }
    do {
      iVar10 = iVar11;
      if (iVar10 < 1) {
        AbyssEngine::PaintCanvas::TransformSetLocal
                  (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0x18),(Matrix *)&local_78);
        *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0x18);
        *(undefined4 *)(this + 0x28) = 0;
        pLVar5 = *(LodMeshMerger **)(this + 4);
        if (pLVar5 == (LodMeshMerger *)0x0) goto LAB_000b1a4e;
        uVar7 = *(undefined4 *)this;
        iVar11 = 0;
        goto LAB_000b1a40;
      }
      iVar11 = iVar10 + -1;
      fVar12 = (float)__aeabi_ul2f(*(undefined4 *)(*(int *)(this + 100) + iVar9),
                                   *(undefined4 *)(*(int *)(this + 100) + iVar9 + 4));
      fVar4 = (float)__aeabi_ul2f(*(undefined4 *)(this + 0x68),*(undefined4 *)(this + 0x6c));
      iVar9 = iVar9 + -8;
    } while (fVar4 <= fVar13 * fVar12);
    uVar6 = *(uint *)(*(int *)(this + 0x54) + iVar11 * 4);
    if (uVar6 != *(uint *)(this + 0xc)) {
      AbyssEngine::PaintCanvas::TransformSetLocal
                (*(PaintCanvas **)(this + 0x2c),uVar6,(Matrix *)&local_78);
      *(undefined4 *)(this + 0xc) = *(undefined4 *)(*(int *)(this + 0x54) + iVar11 * 4);
      lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (*(PaintCanvas **)(this + 0x2c),
                          *(uint *)(*(int *)(this + 0x54) + iVar11 * 4));
      AbyssEngine::Transform::SetCurrentAnimationTime(lVar15);
      lVar15 = AbyssEngine::PaintCanvas::TransformGetTransform
                         (*(PaintCanvas **)(this + 0x2c),*(uint *)(this + 0x18));
      AbyssEngine::Transform::SetCurrentAnimationTime(lVar15);
      *(int *)(this + 0x28) = iVar10;
      AbyssEngine::AEMath::Matrix::operator=((Matrix *)(this + 0x84),(Matrix *)&local_78);
      pLVar5 = *(LodMeshMerger **)(this + 4);
      if (pLVar5 != (LodMeshMerger *)0x0) {
        uVar7 = *(undefined4 *)this;
        iVar11 = (int)(char)iVar10;
LAB_000b1a40:
        LodMeshMerger::setLod(pLVar5,uVar7,iVar11);
      }
    }
  }
  else {
    *(undefined4 *)(this + 0x28) = 0xffffffff;
  }
LAB_000b1a4e:
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== AEGeometry::hasLod  @0x000b1a7c  (10 bytes)
/* AEGeometry::hasLod() */

bool __thiscall AEGeometry::hasLod(AEGeometry *this)

{
  return *(int *)(this + 0x54) != 0;
}

// ===== AEGeometry::DEBUG_setMeshMergerIndex  @0x000b1a86  (6 bytes)
/* AEGeometry::DEBUG_setMeshMergerIndex(int, LodMeshMerger*) */

void __thiscall
AEGeometry::DEBUG_setMeshMergerIndex(AEGeometry *this,int param_1,LodMeshMerger *param_2)

{
  *(int *)this = param_1;
  *(LodMeshMerger **)(this + 4) = param_2;
  return;
}

