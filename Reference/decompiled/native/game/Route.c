// Class: Route
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Route::Route  @0x00140af8  (228 bytes)
/* Route::Route(int*, int) */

Route * __thiscall Route::Route(Route *this,int *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  Array *pAVar3;
  Waypoint *this_00;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  
  *(undefined4 *)this = 0;
  this[4] = (Route)0x0;
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  puVar1[1] = puVar2;
  *puVar2 = 0;
  puVar1[2] = 1;
  *puVar1 = 0;
  *(undefined4 **)(this + 0xc) = puVar1;
  pAVar3 = operator_new(0xc);
  puVar1 = operator_new__(4);
  *(undefined4 **)(pAVar3 + 4) = puVar1;
  *(undefined4 *)(pAVar3 + 8) = 1;
  *puVar1 = 0;
  *(undefined4 *)pAVar3 = 0;
  *(Array **)(this + 0x10) = pAVar3;
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  puVar1[1] = puVar2;
  puVar1[2] = 1;
  *puVar2 = 0;
  *puVar1 = 0;
  *(undefined4 **)(this + 0x14) = puVar1;
  ArraySetLength<KIPlayer*>(param_2 / 3,pAVar3);
  ArraySetLength<int>(param_2 / 3,*(Array **)(this + 0x14));
  if (0 < param_2) {
    iVar6 = 0;
    do {
      this_00 = operator_new(0x134);
      Waypoint::Waypoint(this_00,param_1[iVar6],param_1[iVar6 + 1],param_1[iVar6 + 2],this);
      piVar5 = *(int **)(this + 0xc);
      piVar5[2] = *piVar5 + 1;
      pvVar4 = realloc((void *)piVar5[1],(*piVar5 + 1) * 4);
      piVar5[1] = (int)pvVar4;
      iVar6 = iVar6 + 3;
      *(Waypoint **)((int)pvVar4 + *piVar5 * 4) = this_00;
      *piVar5 = piVar5[2];
    } while (iVar6 < param_2);
  }
  return this;
}

// ===== Route::Route  @0x00140bf4  (244 bytes)
/* Route::Route(int*, Array<KIPlayer*>*, int*, int) */

Route * __thiscall Route::Route(Route *this,int *param_1,Array *param_2,int *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  void *pvVar4;
  Waypoint *this_00;
  int iVar5;
  int iVar6;
  
  *(undefined4 *)this = 0;
  this[4] = (Route)0x0;
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  puVar1[1] = puVar2;
  *puVar2 = 0;
  puVar1[2] = 1;
  *puVar1 = 0;
  *(undefined4 **)(this + 0xc) = puVar1;
  piVar3 = operator_new(0xc);
  puVar1 = operator_new__(4);
  piVar3[1] = (int)puVar1;
  piVar3[2] = 1;
  *puVar1 = 0;
  *piVar3 = 0;
  *(Array **)(this + 0x10) = param_2;
  *(int **)(this + 0x14) = piVar3;
  if (0 < param_4) {
    iVar5 = 0;
    while( true ) {
      iVar6 = param_3[iVar5 / 3];
      piVar3[2] = *piVar3 + 1;
      pvVar4 = realloc((void *)piVar3[1],(*piVar3 + 1) * 4);
      piVar3[1] = (int)pvVar4;
      iVar5 = iVar5 + 3;
      *(int *)((int)pvVar4 + *piVar3 * 4) = iVar6;
      *piVar3 = piVar3[2];
      if (param_4 <= iVar5) break;
      piVar3 = *(int **)(this + 0x14);
    }
    if (0 < param_4) {
      iVar5 = 0;
      do {
        this_00 = operator_new(0x134);
        Waypoint::Waypoint(this_00,param_1[iVar5],param_1[iVar5 + 1],param_1[iVar5 + 2],this);
        piVar3 = *(int **)(this + 0xc);
        piVar3[2] = *piVar3 + 1;
        pvVar4 = realloc((void *)piVar3[1],(*piVar3 + 1) * 4);
        piVar3[1] = (int)pvVar4;
        iVar5 = iVar5 + 3;
        *(Waypoint **)((int)pvVar4 + *piVar3 * 4) = this_00;
        *piVar3 = piVar3[2];
      } while (iVar5 < param_4);
    }
  }
  return this;
}

// ===== Route::~Route  @0x00140cfa  (86 bytes)
/* Route::~Route() */

Route * __thiscall Route::~Route(Route *this)

{
  void *pvVar1;
  
  if (*(Array **)(this + 0xc) != (Array *)0x0) {
    ArrayReleaseClasses<Waypoint*>(*(Array **)(this + 0xc));
    pvVar1 = *(void **)(this + 0xc);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
  }
  *(undefined4 *)(this + 0xc) = 0;
  pvVar1 = *(void **)(this + 0x10);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x10) = 0;
  pvVar1 = *(void **)(this + 0x14);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0x14) = 0;
  return this;
}

// ===== Route::reset  @0x00140d8e  (40 bytes)
/* Route::reset() */

void __thiscall Route::reset(Route *this)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = *(uint **)(this + 0xc);
  if (*puVar1 != 0) {
    uVar2 = 0;
    do {
      Waypoint::reset(*(Waypoint **)(puVar1[1] + uVar2 * 4));
      puVar1 = *(uint **)(this + 0xc);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *puVar1);
  }
  *(undefined4 *)this = 0;
  return;
}

// ===== Route::setNewCoords  @0x00140db6  (44 bytes)
/* Route::setNewCoords(AbyssEngine::AEMath::Vector) */

void Route::setNewCoords(int param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  
  iVar1 = **(int **)(*(int *)(param_1 + 0xc) + 4);
  *(int *)(iVar1 + 0x120) = (int)param_2;
  *(int *)(iVar1 + 0x124) = (int)param_3;
  *(int *)(iVar1 + 0x128) = (int)param_4;
  return;
}

// ===== Route::setLoop  @0x00140de2  (4 bytes)
/* Route::setLoop(bool) */

void __thiscall Route::setLoop(Route *this,bool param_1)

{
  this[4] = (Route)param_1;
  return;
}

// ===== Route::getDockingTarget  @0x00140de6  (24 bytes)
/* Route::getDockingTarget() */

undefined4 __thiscall Route::getDockingTarget(Route *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0x10);
  if ((piVar1 != (int *)0x0) && (*(int *)this < *piVar1)) {
    return *(undefined4 *)(piVar1[1] + *(int *)this * 4);
  }
  return 0;
}

// ===== Route::getDockingTarget  @0x00140dfe  (22 bytes)
/* Route::getDockingTarget(int) */

undefined4 __thiscall Route::getDockingTarget(Route *this,int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0x10);
  if ((piVar1 != (int *)0x0) && (param_1 < *piVar1)) {
    return *(undefined4 *)(piVar1[1] + param_1 * 4);
  }
  return 0;
}

// ===== Route::getDockingTime  @0x00140e14  (26 bytes)
/* Route::getDockingTime() */

undefined4 __thiscall Route::getDockingTime(Route *this)

{
  if (*(int *)(this + 0x10) != 0) {
    if (*(int *)this < **(int **)(this + 0x14)) {
      return *(undefined4 *)((*(int **)(this + 0x14))[1] + *(int *)this * 4);
    }
  }
  return 0;
}

// ===== Route::getDockingTime  @0x00140e2e  (24 bytes)
/* Route::getDockingTime(int) */

undefined4 __thiscall Route::getDockingTime(Route *this,int param_1)

{
  if ((*(int *)(this + 0x10) != 0) && (param_1 < **(int **)(this + 0x14))) {
    return *(undefined4 *)((*(int **)(this + 0x14))[1] + param_1 * 4);
  }
  return 0;
}

// ===== Route::getWaypoint  @0x00140e48  (150 bytes)
/* Route::getWaypoint(int) */

void __thiscall Route::getWaypoint(Route *this,int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_3c [8];
  float local_34;
  undefined1 auStack_30 [4];
  float local_2c;
  float local_24 [3];
  int local_18;
  
  local_18 = __stack_chk_guard;
  if (((param_1 < **(int **)(this + 0xc)) &&
      (iVar2 = *(int *)((*(int **)(this + 0xc))[1] + param_1 * 4), iVar2 != 0)) &&
     (piVar1 = *(int **)(*(int *)(*(int *)(this + 0x10) + 4) + param_1 * 4), piVar1 != (int *)0x0))
  {
    (**(code **)(*piVar1 + 0x28))(local_24);
    *(int *)(iVar2 + 0x120) = (int)local_24[0];
    (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x10) + 4) + param_1 * 4) + 0x28))(auStack_30);
    *(int *)(iVar2 + 0x124) = (int)local_2c;
    (**(code **)(**(int **)(*(int *)(*(int *)(this + 0x10) + 4) + param_1 * 4) + 0x28))(auStack_3c);
    *(int *)(iVar2 + 0x128) = (int)local_34;
  }
  if (__stack_chk_guard - local_18 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(__stack_chk_guard - local_18);
}

// ===== Route::getWaypoint  @0x00140ee8  (6 bytes)
/* Route::getWaypoint() */

void __thiscall Route::getWaypoint(Route *this)

{
  getWaypoint(this,*(int *)this);
  return;
}

// ===== Route::getLastWaypoint  @0x00140eee  (12 bytes)
/* Route::getLastWaypoint() */

void __thiscall Route::getLastWaypoint(Route *this)

{
  getWaypoint(this,**(int **)(this + 0xc) + -1);
  return;
}

// ===== Route::waypointDefined  @0x00140ef8  (10 bytes)
/* Route::waypointDefined() */

bool __thiscall Route::waypointDefined(Route *this)

{
  return *(int *)(this + 0xc) != 0;
}

// ===== Route::getCurrent  @0x00140f02  (4 bytes)
/* Route::getCurrent() */

undefined4 __thiscall Route::getCurrent(Route *this)

{
  return *(undefined4 *)this;
}

// ===== Route::reachWaypoint  @0x00140f06  (106 bytes)
/* Route::reachWaypoint(int) */

void __thiscall Route::reachWaypoint(Route *this,int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = *(int **)(this + 0xc);
  iVar3 = *piVar1;
  if (*(int *)this < iVar3 + -1) {
    *(int *)this = param_1 + 1;
  }
  else if (this[4] != (Route)0x0) {
    *(undefined4 *)this = 0;
    puVar2 = (undefined4 *)piVar1[1];
    if (iVar3 != 0) {
      uVar4 = 0;
      do {
        Waypoint::reset((Waypoint *)puVar2[uVar4]);
        uVar4 = uVar4 + 1;
        puVar2 = (undefined4 *)(*(uint **)(this + 0xc))[1];
      } while (uVar4 < **(uint **)(this + 0xc));
    }
    Waypoint::setActive((Waypoint *)*puVar2,true);
    piVar1 = *(int **)(this + 0xc);
  }
  Waypoint::setActive(*(Waypoint **)(piVar1[1] + param_1 * 4),false);
  Waypoint::reached(*(Waypoint **)(*(int *)(*(int *)(this + 0xc) + 4) + param_1 * 4));
  return;
}

// ===== Route::length  @0x00140f6e  (6 bytes)
/* Route::length() */

undefined4 __thiscall Route::length(Route *this)

{
  return **(undefined4 **)(this + 0xc);
}

// ===== Route::update  @0x00140f74  (14 bytes)
/* Route::update(AbyssEngine::AEMath::Vector const&) */

void Route::update(Vector *param_1)

{
  float in_s0;
  float in_s1;
  float in_s2;
  
  update((Route *)param_1,in_s0,in_s1,in_s2);
  return;
}

// ===== Route::update  @0x00140f80  (252 bytes)
/* Route::update(float, float, float) */

float __thiscall Route::update(Route *this,float param_1,float param_2,float param_3)

{
  byte bVar1;
  int iVar2;
  Waypoint *this_00;
  uint *puVar3;
  float in_r1;
  uint uVar4;
  float in_r2;
  float in_r3;
  int iVar5;
  uint uVar6;
  uint in_fpscr;
  float fVar7;
  
  iVar2 = *(int *)this;
  if ((iVar2 < **(int **)(this + 0xc)) &&
     (*(int *)(*(int *)(*(int *)(this + 0x10) + 4) + iVar2 * 4) == 0)) {
    this_00 = *(Waypoint **)((*(int **)(this + 0xc))[1] + iVar2 * 4);
    fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(this_00 + 0x120),(byte)(in_fpscr >> 0x16) & 3
                                      );
    fVar7 = in_r1 - fVar7;
    param_1 = 2000.0;
    if ((fVar7 < 2000.0) &&
       (uVar4 = in_fpscr & 0xfffffff | (uint)(fVar7 < -2000.0) << 0x1f |
                (uint)(fVar7 == -2000.0) << 0x1e, bVar1 = (byte)(uVar4 >> 0x18),
       !(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar7))) {
      fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(this_00 + 0x124),(byte)(uVar4 >> 0x16) & 3)
      ;
      fVar7 = in_r2 - fVar7;
      if ((fVar7 < 2000.0) &&
         (uVar4 = in_fpscr & 0xfffffff | (uint)(fVar7 < -2000.0) << 0x1f |
                  (uint)(fVar7 == -2000.0) << 0x1e, bVar1 = (byte)(uVar4 >> 0x18),
         !(bool)(bVar1 >> 6 & 1) && (bool)(bVar1 >> 7) == NAN(fVar7))) {
        fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(this_00 + 0x128),
                                           (byte)(uVar4 >> 0x16) & 3);
        if (((int)((uint)(in_r3 - fVar7 < 2000.0) << 0x1f) < 0) && (-2000.0 < in_r3 - fVar7)) {
          Waypoint::setActive(this_00,false);
          param_1 = (float)Waypoint::reached(*(Waypoint **)
                                              (*(int *)(*(int *)(this + 0xc) + 4) + *(int *)this * 4
                                              ));
          iVar5 = *(int *)this;
          iVar2 = iVar5 + 1;
          *(int *)this = iVar2;
          puVar3 = *(uint **)(this + 0xc);
          uVar4 = *puVar3;
          if ((this[4] != (Route)0x0) && ((int)(uVar4 - 1) <= iVar5)) {
            *(undefined4 *)this = 0;
            if (uVar4 == 0) {
              return param_1;
            }
            uVar6 = 0;
            do {
              param_1 = (float)Waypoint::reset(*(Waypoint **)(puVar3[1] + uVar6 * 4));
              puVar3 = *(uint **)(this + 0xc);
              uVar6 = uVar6 + 1;
              uVar4 = *puVar3;
            } while (uVar6 < uVar4);
            iVar2 = *(int *)this;
          }
          if (iVar2 < (int)uVar4) {
            fVar7 = (float)Waypoint::setActive(*(Waypoint **)(puVar3[1] + iVar2 * 4),true);
            return fVar7;
          }
        }
      }
    }
  }
  return param_1;
}

// ===== Route::getExactClone  @0x00141084  (68 bytes)
/* Route::getExactClone() */

undefined4 * __thiscall Route::getExactClone(Route *this)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar1 = (undefined4 *)clone(this);
  puVar2 = (uint *)puVar1[3];
  if (*puVar2 != 0) {
    uVar3 = 0;
    do {
      if (*(char *)(*(int *)(*(int *)(*(int *)(this + 0xc) + 4) + uVar3 * 4) + 300) != '\0') {
        Waypoint::reached(*(Waypoint **)(puVar2[1] + uVar3 * 4));
        puVar2 = (uint *)puVar1[3];
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar2);
  }
  *puVar1 = *(undefined4 *)this;
  return puVar1;
}

// ===== Route::clone  @0x001410c8  (326 bytes)
/* Route::clone() */

Route * __thiscall Route::clone(Route *this)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  Route *pRVar5;
  int *piVar6;
  Array *pAVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  
  puVar13 = *(uint **)(this + 0xc);
  uVar11 = *puVar13;
  lVar1 = (ulonglong)(uVar11 * 3) * 4;
  uVar3 = (uint)lVar1;
  if ((int)((ulonglong)lVar1 >> 0x20) != 0) {
    uVar3 = 0xffffffff;
  }
  piVar4 = operator_new__(uVar3);
  if (uVar11 != 0) {
    uVar3 = puVar13[1];
    piVar6 = piVar4 + 1;
    uVar9 = 0;
    do {
      iVar10 = *(int *)(uVar3 + uVar9 * 4);
      uVar9 = uVar9 + 1;
      piVar6[-1] = *(int *)(iVar10 + 0x120);
      *piVar6 = *(int *)(iVar10 + 0x124);
      piVar6[1] = *(int *)(iVar10 + 0x128);
      piVar6 = piVar6 + 3;
    } while (uVar9 < uVar11);
  }
  puVar12 = *(uint **)(this + 0x10);
  if ((puVar12 != (uint *)0x0) && (*puVar12 != 0)) {
    bVar2 = false;
    uVar3 = 0;
    do {
      iVar10 = uVar3 * 4;
      uVar3 = uVar3 + 1;
      if (*(int *)(puVar12[1] + iVar10) != 0) {
        bVar2 = true;
      }
    } while (uVar3 < *puVar12);
    if (bVar2) {
      puVar13 = *(uint **)(this + 0x14);
      uVar3 = (uint)((ulonglong)*puVar13 * 4);
      if ((int)((ulonglong)*puVar13 * 4 >> 0x20) != 0) {
        uVar3 = 0xffffffff;
      }
      piVar6 = operator_new__(uVar3);
      if (*puVar13 != 0) {
        uVar3 = puVar13[1];
        uVar11 = 0;
        do {
          piVar6[uVar11] = *(int *)(uVar3 + uVar11 * 4);
          uVar11 = uVar11 + 1;
        } while (uVar11 < *puVar13);
      }
      pAVar7 = operator_new(0xc);
      puVar8 = operator_new__(4);
      *(undefined4 **)(pAVar7 + 4) = puVar8;
      *(undefined4 *)(pAVar7 + 8) = 1;
      *puVar8 = 0;
      *(undefined4 *)pAVar7 = 0;
      ArraySetLength<KIPlayer*>(*puVar12,pAVar7);
      puVar13 = *(uint **)(this + 0x10);
      if (*puVar13 != 0) {
        uVar3 = 0;
        do {
          *(undefined4 *)(*(int *)(pAVar7 + 4) + uVar3 * 4) =
               *(undefined4 *)(puVar13[1] + uVar3 * 4);
          uVar3 = uVar3 + 1;
          puVar13 = *(uint **)(this + 0x10);
        } while (uVar3 < *puVar13);
      }
      pRVar5 = operator_new(0x18);
      Route(pRVar5,piVar4,pAVar7,piVar6,**(int **)(this + 0xc) * 3);
      pRVar5[4] = this[4];
      operator_delete__(piVar6);
      return pRVar5;
    }
  }
  pRVar5 = operator_new(0x18);
  Route(pRVar5,piVar4,*puVar13 * 3);
  pRVar5[4] = this[4];
  return pRVar5;
}

// ===== Route::translate  @0x00141224  (94 bytes)
/* Route::translate(AbyssEngine::AEMath::Vector const&) */

void __thiscall Route::translate(Route *this,Vector *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  uVar1 = **(uint **)(this + 0xc);
  if (uVar1 != 0) {
    fVar5 = *(float *)param_1;
    fVar6 = *(float *)(param_1 + 4);
    fVar7 = *(float *)(param_1 + 8);
    uVar2 = (*(uint **)(this + 0xc))[1];
    uVar3 = 0;
    do {
      iVar4 = *(int *)(uVar2 + uVar3 * 4);
      uVar3 = uVar3 + 1;
      fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(iVar4 + 0x120),(byte)(in_fpscr >> 0x16) & 3
                                        );
      *(int *)(iVar4 + 0x120) = (int)(fVar5 + fVar8);
      fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(iVar4 + 0x124),(byte)(in_fpscr >> 0x16) & 3
                                        );
      *(int *)(iVar4 + 0x124) = (int)(fVar6 + fVar8);
      fVar8 = (float)VectorSignedToFloat(*(undefined4 *)(iVar4 + 0x128),(byte)(in_fpscr >> 0x16) & 3
                                        );
      *(int *)(iVar4 + 0x128) = (int)(fVar7 + fVar8);
    } while (uVar3 < uVar1);
  }
  return;
}

