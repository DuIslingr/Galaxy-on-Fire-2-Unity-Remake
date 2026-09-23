// Class: Node
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Node::Node  @0x001405da  (46 bytes)
/* Node::Node(int) */

Node * __thiscall Node::Node(Node *this,int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(this + 4) = 0;
  *(int *)(this + 8) = param_1;
  puVar1 = operator_new(0xc);
  puVar2 = operator_new__(4);
  puVar1[1] = puVar2;
  puVar1[2] = 1;
  *puVar2 = 0;
  *puVar1 = 0;
  *(undefined4 **)this = puVar1;
  return this;
}

// ===== Node::~Node  @0x00140616  (24 bytes)
/* Node::~Node() */

Node * __thiscall Node::~Node(Node *this)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  pvVar1 = *(void **)(iVar2 + 4);
  if (pvVar1 != (void *)0x0) {
    operator_delete__(pvVar1);
  }
  *(undefined4 *)(iVar2 + 4) = 0;
  return this;
}

