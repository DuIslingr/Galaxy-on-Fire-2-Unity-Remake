// Class: AbyssEngine::CheatHandler
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::CheatHandler::CheatHandler  @0x0007da62  (50 bytes)
/* AbyssEngine::CheatHandler::CheatHandler(AbyssEngine::KeyCode*) */

CheatHandler * __thiscall
AbyssEngine::CheatHandler::CheatHandler(CheatHandler *this,KeyCode *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  puVar1[1] = puVar2;
  *puVar2 = 0;
  puVar1[2] = 1;
  *puVar1 = 0;
  *(undefined4 **)(this + 8) = puVar1;
  *(KeyCode **)(this + 0xc) = param_1;
  return this;
}

// ===== AbyssEngine::CheatHandler::~CheatHandler  @0x0007daa2  (108 bytes)
/* AbyssEngine::CheatHandler::~CheatHandler() */

CheatHandler * __thiscall AbyssEngine::CheatHandler::~CheatHandler(CheatHandler *this)

{
  CheatCode *this_00;
  void *pvVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = *(uint **)(this + 8);
  if (puVar3 != (uint *)0x0) {
    if (*puVar3 != 0) {
      uVar4 = 0;
      do {
        uVar2 = puVar3[1];
        this_00 = *(CheatCode **)(uVar2 + uVar4 * 4);
        if (this_00 != (CheatCode *)0x0) {
          pvVar1 = (void *)CheatCode::~CheatCode(this_00);
          operator_delete(pvVar1);
          uVar2 = *(uint *)(*(int *)(this + 8) + 4);
        }
        *(undefined4 *)(uVar2 + uVar4 * 4) = 0;
        uVar4 = uVar4 + 1;
        puVar3 = *(uint **)(this + 8);
      } while (uVar4 < *puVar3);
    }
    *puVar3 = 0;
    puVar3[2] = 1;
    pvVar1 = realloc((void *)puVar3[1],4);
    puVar3[1] = (uint)pvVar1;
    __aeabi_memclr4(pvVar1,puVar3[2] << 2);
    pvVar1 = *(void **)(this + 8);
    if (pvVar1 != (void *)0x0) {
      if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
        operator_delete__(*(void **)((int)pvVar1 + 4));
      }
      operator_delete(pvVar1);
    }
    *(undefined4 *)(this + 8) = 0;
  }
  return this;
}

// ===== AbyssEngine::CheatHandler::AddCheatCode  @0x0007db10  (284 bytes)
/* AbyssEngine::CheatHandler::AddCheatCode(AbyssEngine::String const&, int) */

void __thiscall
AbyssEngine::CheatHandler::AddCheatCode(CheatHandler *this,String *param_1,int param_2)

{
  CheatCode *this_00;
  void *pvVar1;
  undefined2 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined2 uVar6;
  
  this_00 = operator_new(0xc);
  CheatCode::CheatCode(this_00);
  *(int *)(this_00 + 4) = param_2;
  piVar4 = *(int **)(this + 8);
  piVar4[2] = *piVar4 + 1;
  pvVar1 = realloc((void *)piVar4[1],(*piVar4 + 1) * 4);
  piVar4[1] = (int)pvVar1;
  *(CheatCode **)((int)pvVar1 + *piVar4 * 4) = this_00;
  *piVar4 = piVar4[2];
  if (*(int *)(param_1 + 4) != 0) {
    uVar5 = 0;
    do {
      puVar2 = (undefined2 *)String::operator[]((String *)param_1,uVar5);
      switch(*puVar2) {
      case 0x30:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)**(undefined4 **)(this + 0xc);
        break;
      case 0x31:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0xc);
        break;
      case 0x32:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x18);
        break;
      case 0x33:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x24);
        break;
      case 0x34:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x30);
        break;
      case 0x35:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x3c);
        break;
      case 0x36:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x48);
        break;
      case 0x37:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x54);
        break;
      case 0x38:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x60);
        break;
      case 0x39:
        piVar4 = *(int **)this_00;
        iVar3 = *piVar4;
        uVar6 = (undefined2)*(undefined4 *)(*(int *)(this + 0xc) + 0x6c);
        break;
      default:
        goto switchD_0007db64_default;
      }
      piVar4[2] = iVar3 + 1;
      pvVar1 = realloc((void *)piVar4[1],(iVar3 + 1) * 2);
      piVar4[1] = (int)pvVar1;
      *(undefined2 *)((int)pvVar1 + *piVar4 * 2) = uVar6;
      *piVar4 = piVar4[2];
switchD_0007db64_default:
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 4));
  }
  return;
}

// ===== AbyssEngine::CheatHandler::SetCheatFunc  @0x0007dc44  (6 bytes)
/* AbyssEngine::CheatHandler::SetCheatFunc(void (*)(int, void*), void*) */

void __thiscall
AbyssEngine::CheatHandler::SetCheatFunc
          (CheatHandler *this,_func_void_int_void_ptr *param_1,void *param_2)

{
  *(_func_void_int_void_ptr **)this = param_1;
  *(void **)(this + 4) = param_2;
  return;
}

// ===== AbyssEngine::CheatHandler::Update  @0x0007dc4a  (68 bytes)
/* AbyssEngine::CheatHandler::Update(unsigned short) */

void __thiscall AbyssEngine::CheatHandler::Update(CheatHandler *this,ushort param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(int *)this != 0) && (puVar1 = *(uint **)(this + 8), *puVar1 != 0)) {
    uVar3 = 0;
    do {
      iVar2 = CheatCode::Update(*(CheatCode **)(puVar1[1] + uVar3 * 4),param_1);
      if (iVar2 == 1) {
        (**(code **)this)(*(undefined4 *)
                           (*(int *)(*(int *)(*(int *)(this + 8) + 4) + uVar3 * 4) + 4),
                          *(undefined4 *)(this + 4));
      }
      puVar1 = *(uint **)(this + 8);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *puVar1);
  }
  return;
}

