// Class: AbyssEngine::Mesh
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::Mesh::Mesh  @0x000745e0  (248 bytes)
/* AbyssEngine::Mesh::Mesh(AbyssEngine::Mesh*) */

Mesh * __thiscall AbyssEngine::Mesh::Mesh(Mesh *this,Mesh *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  Transform *this_00;
  undefined4 uVar3;
  Transform *pTVar4;
  
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined8 *)(this + 0x4c) = 0x3f800000;
  *(undefined8 *)(this + 0x54) = 0;
  if (param_1 != (Mesh *)0x0) {
    if (param_1[0x84] != (Mesh)0x0) {
      MeshConvertToVBO(param_1);
    }
    AEMath::BSphere::operator=((BSphere *)(this + 0x3c),(BSphere *)(param_1 + 0x3c));
    uVar3 = *(undefined4 *)param_1;
    *this = SUB41(uVar3,0);
    *(undefined4 *)(this + 0x7c) = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(undefined4 *)(this + 0x20) = 0;
    *(short *)(this + 2) = (short)((uint)uVar3 >> 0x10);
    uVar3 = *(undefined4 *)(param_1 + 8);
    uVar1 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 8) = uVar3;
    *(undefined4 *)(this + 0xc) = uVar1;
    *(undefined4 *)(this + 0x10) = uVar2;
    if (Engine::enableShader != '\0') {
      *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
      *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
    }
    uVar3 = *(undefined4 *)(param_1 + 0x28);
    *(short *)(this + 0x28) = (short)uVar3;
    *(short *)(this + 0x2a) = (short)((uint)uVar3 >> 0x10);
    *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
    pTVar4 = *(Transform **)(param_1 + 0x34);
    if (pTVar4 == (Transform *)0x0) {
      *(undefined4 *)(this + 0x34) = 0;
    }
    else {
      this_00 = operator_new(0x180);
      Transform::Transform(this_00,pTVar4);
      *(Transform **)(this + 0x34) = this_00;
    }
    AEMath::Vector::operator=((Vector *)(this + 0x50),(Vector *)(param_1 + 0x50));
    this[0x85] = param_1[0x85];
    this[0x38] = (Mesh)0x1;
    this[0x5c] = param_1[0x5c];
    uVar3 = *(undefined4 *)(param_1 + 100);
    uVar1 = *(undefined4 *)(param_1 + 0x68);
    uVar2 = *(undefined4 *)(param_1 + 0x6c);
    *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(this + 100) = uVar3;
    *(undefined4 *)(this + 0x68) = uVar1;
    *(undefined4 *)(this + 0x6c) = uVar2;
    *(undefined4 *)(this + 0x78) = *(undefined4 *)(param_1 + 0x78);
    this[0x84] = param_1[0x84];
    if (Engine::enableShader != '\0') {
      *(undefined4 *)(this + 0x70) = *(undefined4 *)(param_1 + 0x70);
      *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
    }
    *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  }
  return this;
}

// ===== AbyssEngine::Mesh::ReadEnhancedDataFromFile  @0x0007474c  (1858 bytes)
/* AbyssEngine::Mesh::ReadEnhancedDataFromFile(unsigned int, unsigned int) */

void __thiscall AbyssEngine::Mesh::ReadEnhancedDataFromFile(Mesh *this,uint param_1,uint param_2)

{
  Transform *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  uint uVar6;
  Mesh *pMVar7;
  Mesh *pMVar8;
  float fVar9;
  longlong lVar10;
  short sStack_5a;
  float local_58;
  ushort local_54;
  short sStack_52;
  float local_50 [3];
  int local_44;
  
  local_44 = __stack_chk_guard;
  this_00 = operator_new(0x180);
  Transform::Transform(this_00);
  iVar1 = AEFile::Read(4,this + 0x3c,param_1);
  if (iVar1 != 0) {
    pMVar7 = this + 0x40;
    iVar1 = AEFile::Read(4,pMVar7,param_1);
    if (iVar1 == 1) {
      pMVar8 = this + 0x44;
      iVar1 = AEFile::Read(4,pMVar8,param_1);
      if ((iVar1 == 1) && (iVar1 = AEFile::Read(4,this + 0x48,param_1), iVar1 == 1)) {
        fVar9 = *(float *)pMVar7;
        *(undefined4 *)pMVar7 = *(undefined4 *)pMVar8;
        *(float *)pMVar8 = -fVar9;
        iVar1 = AEFile::Read(2,&sStack_52,param_1);
        if (iVar1 == 1) {
          if (sStack_52 == 1) {
            iVar1 = AEFile::Read(2,&local_54,param_1);
            if (iVar1 != 1) goto LAB_00074e5c;
            if (local_54 != 0) {
              iVar1 = 0;
              do {
                iVar2 = AEFile::Read(4,&local_58,param_1);
                if (iVar2 == 0) goto LAB_00074e5c;
                if ((0.0 < local_58) && (local_58 < timeBetweenFrames)) {
                  timeBetweenFrames = local_58;
                }
                iVar2 = AEFile::Read(0xc,local_50,param_1);
                if (iVar2 == 0) goto LAB_00074e5c;
                Transform::InsertKeyFrame((float *)this_00,7,(int)local_58);
                iVar1 = iVar1 + 1;
              } while (iVar1 < (int)(uint)local_54);
            }
          }
          else if (sStack_52 == 0) {
            iVar1 = 0;
            do {
              iVar2 = AEFile::Read(2,&local_54,param_1);
              if (iVar2 != 1) goto LAB_00074e5c;
              if (local_54 != 0) {
                iVar2 = 0;
                do {
                  iVar3 = AEFile::Read(4,local_50,param_1);
                  if (iVar3 == 0) goto LAB_00074e5c;
                  if ((0.0 < local_50[0]) && (local_50[0] < timeBetweenFrames)) {
                    timeBetweenFrames = local_50[0];
                  }
                  iVar3 = AEFile::Read(4,&local_58,param_1);
                  if (iVar3 != 1) goto LAB_00074e5c;
                  if (iVar1 == 2) {
                    uVar6 = 2;
LAB_000748a6:
                    Transform::InsertKeyFrame((float *)this_00,(ulonglong)uVar6,(int)local_50[0]);
                  }
                  else {
                    if (iVar1 == 1) {
                      uVar6 = 4;
                      local_58 = -local_58;
                      goto LAB_000748a6;
                    }
                    if (iVar1 == 0) {
                      uVar6 = 1;
                      goto LAB_000748a6;
                    }
                  }
                  iVar2 = iVar2 + 1;
                } while (iVar2 < (int)(uint)local_54);
              }
              iVar1 = iVar1 + 1;
            } while (iVar1 < 3);
          }
          iVar1 = AEFile::Read(2,&sStack_52,param_1);
          if (iVar1 == 1) {
            if (sStack_52 == 1) {
              iVar1 = AEFile::Read(2,&local_54,param_1);
              if (iVar1 != 1) goto LAB_00074e5c;
              if (local_54 != 0) {
                iVar1 = 0;
                do {
                  iVar2 = AEFile::Read(4,&local_58,param_1);
                  if (iVar2 == 0) goto LAB_00074e5c;
                  if ((0.0 < local_58) && (local_58 < timeBetweenFrames)) {
                    timeBetweenFrames = local_58;
                  }
                  iVar2 = AEFile::Read(0xc,local_50,param_1);
                  if (iVar2 == 0) goto LAB_00074e5c;
                  Transform::InsertKeyFrame((float *)this_00,0x1c0,(int)local_58);
                  iVar1 = iVar1 + 1;
                } while (iVar1 < (int)(uint)local_54);
              }
            }
            else if (sStack_52 == 0) {
              iVar1 = 0;
              do {
                iVar2 = AEFile::Read(2,&local_54,param_1);
                if (iVar2 != 1) goto LAB_00074e5c;
                if (local_54 != 0) {
                  iVar2 = 0;
                  do {
                    iVar3 = AEFile::Read(4,local_50,param_1);
                    if (iVar3 == 0) goto LAB_00074e5c;
                    if ((0.0 < local_50[0]) && (local_50[0] < timeBetweenFrames)) {
                      timeBetweenFrames = local_50[0];
                    }
                    iVar3 = AEFile::Read(4,&local_58,param_1);
                    if (iVar3 != 1) goto LAB_00074e5c;
                    if (iVar1 == 2) {
                      uVar6 = 0x100;
LAB_00074a20:
                      Transform::InsertKeyFrame((float *)this_00,(ulonglong)uVar6,(int)local_50[0]);
                    }
                    else {
                      if (iVar1 == 1) {
                        uVar6 = 0x80;
                        goto LAB_00074a20;
                      }
                      if (iVar1 == 0) {
                        uVar6 = 0x40;
                        goto LAB_00074a20;
                      }
                    }
                    iVar2 = iVar2 + 1;
                  } while (iVar2 < (int)(uint)local_54);
                }
                iVar1 = iVar1 + 1;
              } while (iVar1 < 3);
            }
            iVar1 = AEFile::Read(2,&sStack_52,param_1);
            if (iVar1 == 1) {
              if (sStack_52 == 1) {
                iVar1 = AEFile::Read(2,&local_54,param_1);
                if (iVar1 != 1) goto LAB_00074e5c;
                if (local_54 != 0) {
                  iVar1 = 0;
                  do {
                    iVar2 = AEFile::Read(4,&local_58,param_1);
                    if (iVar2 == 0) goto LAB_00074e5c;
                    if ((0.0 < local_58) && (local_58 < timeBetweenFrames)) {
                      timeBetweenFrames = local_58;
                    }
                    iVar2 = AEFile::Read(0xc,local_50,param_1);
                    if (iVar2 == 0) goto LAB_00074e5c;
                    Transform::InsertKeyFrame((float *)this_00,0x38,(int)local_58);
                    iVar1 = iVar1 + 1;
                  } while (iVar1 < (int)(uint)local_54);
                }
              }
              else if (sStack_52 == 0) {
                iVar1 = 0;
                do {
                  iVar2 = AEFile::Read(2,&local_54,param_1);
                  if (iVar2 != 1) goto LAB_00074e5c;
                  if (local_54 != 0) {
                    iVar2 = 0;
                    do {
                      iVar3 = AEFile::Read(4,local_50,param_1);
                      if (iVar3 == 0) goto LAB_00074e5c;
                      if ((0.0 < local_50[0]) && (local_50[0] < timeBetweenFrames)) {
                        timeBetweenFrames = local_50[0];
                      }
                      iVar3 = AEFile::Read(4,&local_58,param_1);
                      if (iVar3 != 1) goto LAB_00074e5c;
                      if (iVar1 == 2) {
                        uVar6 = 0x20;
LAB_00074b9a:
                        Transform::InsertKeyFrame
                                  ((float *)this_00,(ulonglong)uVar6,(int)local_50[0]);
                      }
                      else {
                        if (iVar1 == 1) {
                          uVar6 = 0x10;
                          goto LAB_00074b9a;
                        }
                        if (iVar1 == 0) {
                          uVar6 = 8;
                          goto LAB_00074b9a;
                        }
                      }
                      iVar2 = iVar2 + 1;
                    } while (iVar2 < (int)(uint)local_54);
                  }
                  iVar1 = iVar1 + 1;
                } while (iVar1 < 3);
              }
              if ((param_2 & 0x18) != 0) {
                iVar1 = AEFile::Read(2,&sStack_52,param_1);
                if (iVar1 != 1) goto LAB_00074e5c;
                if (sStack_52 == 2) {
                  iVar1 = AEFile::Read(2,&local_54,param_1);
                  if (iVar1 != 1) goto LAB_00074e5c;
                  if (local_54 != 0) {
                    iVar1 = 0;
                    do {
                      iVar2 = AEFile::Read(4,local_50,param_1);
                      if (iVar2 == 0) goto LAB_00074e5c;
                      if ((0.0 < local_50[0]) && (local_50[0] < timeBetweenFrames)) {
                        timeBetweenFrames = local_50[0];
                      }
                      iVar2 = AEFile::Read(4,&local_58,param_1);
                      if (iVar2 == 0) goto LAB_00074e5c;
                      Transform::InsertKeyFrame((float *)this_00,0x200,(int)local_50[0]);
                      iVar1 = iVar1 + 1;
                    } while (iVar1 < (int)(uint)local_54);
                  }
                }
              }
              if ((param_2 & 0x10) != 0) {
                iVar1 = AEFile::Read(2,&local_54,param_1);
                if (iVar1 == 0) goto LAB_00074e5c;
                if (local_54 != 0) {
                  iVar1 = 0;
                  do {
                    iVar2 = AEFile::Read(2,&sStack_5a,param_1);
                    if (iVar2 != 1) goto LAB_00074e5c;
                    if (0 < sStack_5a) {
                      iVar2 = 0;
                      do {
                        iVar3 = AEFile::Read(4,local_50,param_1);
                        if (iVar3 == 0) goto LAB_00074e5c;
                        if ((0.0 < local_50[0]) && (local_50[0] < timeBetweenFrames)) {
                          timeBetweenFrames = local_50[0];
                        }
                        iVar3 = AEFile::Read(4,&local_58,param_1);
                        if (iVar3 != 1) goto LAB_00074e5c;
                        local_58 = local_58 / 100.0;
                        uVar6 = 0x400;
                        switch(iVar1) {
                        case 0:
                          break;
                        case 1:
                          uVar6 = 0x800;
                          break;
                        case 2:
                          uVar6 = 0x2000;
                          break;
                        case 3:
                          uVar6 = 0x4000;
                          break;
                        default:
                          uVar6 = 0;
                          break;
                        case 6:
                          uVar6 = 0x40000;
                          local_58 = (local_58 * 6.2831855) / 360.0;
                        }
                        Transform::InsertKeyFrame
                                  ((float *)this_00,(ulonglong)uVar6,(int)local_50[0]);
                        iVar2 = iVar2 + 1;
                        this[0x85] = (Mesh)0x1;
                      } while (iVar2 < sStack_5a);
                    }
                    iVar1 = iVar1 + 1;
                  } while (iVar1 < 7);
                }
              }
              if (*(int *)(this_00 + 0x11c) < 1) {
                pvVar5 = (void *)Transform::~Transform(this_00);
                operator_delete(pvVar5);
                uVar4 = 1;
              }
              else {
                *(Transform **)(this + 0x34) = this_00;
                fVar9 = timeBetweenFrames;
                *(int *)(this_00 + 0xe8) = (int)timeBetweenFrames;
                lVar10 = __aeabi_f2lz(fVar9);
                Transform::SetAnimationRangeInTime
                          (CONCAT44((int)((ulonglong)lVar10 >> 0x20),this_00),lVar10);
                uVar4 = 1;
              }
              goto LAB_00074e6a;
            }
          }
        }
      }
    }
  }
LAB_00074e5c:
  pvVar5 = (void *)Transform::~Transform(this_00);
  operator_delete(pvVar5);
  uVar4 = 0xffffffff;
LAB_00074e6a:
  if (__stack_chk_guard != local_44) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}

