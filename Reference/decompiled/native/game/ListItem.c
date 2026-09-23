// Class: ListItem
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== ListItem::ListItem  @0x000b2ff6  (98 bytes)
/* ListItem::ListItem(int, int, AbyssEngine::String*) */

ListItem * __thiscall ListItem::ListItem(ListItem *this,int param_1,int param_2,String *param_3)

{
  String *this_00;
  
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(int *)(this + 0x34) = param_1;
  this_00 = operator_new(8);
  AbyssEngine::String::String(this_00,param_3,false);
  *(String **)(this + 0x1c) = this_00;
  *(int *)(this + 0x28) = param_2;
  this[0x24] = (ListItem)0x1;
  return this;
}

// ===== ListItem::init  @0x000b3066  (50 bytes)
/* ListItem::init() */

void __thiscall ListItem::init(ListItem *this)

{
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x44) = 0;
  return;
}

// ===== ListItem::ListItem  @0x000b3098  (194 bytes)
/* ListItem::ListItem(ListItem*) */

ListItem * __thiscall ListItem::ListItem(ListItem *this,ListItem *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  String *pSVar4;
  String *pSVar5;
  
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x44) = 0;
  uVar1 = *(undefined4 *)(param_1 + 8);
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  uVar3 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = uVar1;
  *(undefined4 *)(this + 0xc) = uVar2;
  *(undefined4 *)(this + 0x10) = uVar3;
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  this[0x24] = param_1[0x24];
  pSVar5 = *(String **)(param_1 + 0x1c);
  if (pSVar5 == (String *)0x0) {
    *(undefined4 *)(this + 0x1c) = 0;
  }
  else {
    pSVar4 = operator_new(8);
    AbyssEngine::String::String(pSVar4,pSVar5,false);
    *(String **)(this + 0x1c) = pSVar4;
  }
  pSVar5 = *(String **)(param_1 + 0x20);
  if (pSVar5 == (String *)0x0) {
    *(undefined4 *)(this + 0x20) = 0;
  }
  else {
    pSVar4 = operator_new(8);
    AbyssEngine::String::String(pSVar4,pSVar5,false);
    *(String **)(this + 0x20) = pSVar4;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *(undefined4 *)(param_1 + 0x30);
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = uVar1;
  *(undefined4 *)(this + 0x30) = uVar2;
  *(undefined4 *)(this + 0x34) = uVar3;
  this[0x38] = param_1[0x38];
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  return this;
}

// ===== ListItem::ListItem  @0x000b316a  (58 bytes)
/* ListItem::ListItem(BluePrint*) */

void __thiscall ListItem::ListItem(ListItem *this,BluePrint *param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(BluePrint **)(this + 8) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b31a4  (58 bytes)
/* ListItem::ListItem(Ship*) */

void __thiscall ListItem::ListItem(ListItem *this,Ship *param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(Ship **)(this + 0xc) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b31de  (58 bytes)
/* ListItem::ListItem(Item*) */

void __thiscall ListItem::ListItem(ListItem *this,Item *param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(Item **)(this + 0x10) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b3218  (56 bytes)
/* ListItem::ListItem(PendingProduct*) */

void __thiscall ListItem::ListItem(ListItem *this,PendingProduct *param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(PendingProduct **)(this + 0x18) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b3250  (58 bytes)
/* ListItem::ListItem(Agent*) */

void __thiscall ListItem::ListItem(ListItem *this,Agent *param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(Agent **)(this + 4) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b328a  (104 bytes)
/* ListItem::ListItem(AbyssEngine::String*, bool, int) */

ListItem * __thiscall ListItem::ListItem(ListItem *this,String *param_1,bool param_2,int param_3)

{
  String *this_00;
  
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x44) = 0;
  this_00 = operator_new(8);
  AbyssEngine::String::String(this_00,param_1,false);
  *(String **)(this + 0x1c) = this_00;
  this[0x38] = (ListItem)0x1;
  *(int *)(this + 0x30) = param_3;
  this[0x24] = (ListItem)param_2;
  return this;
}

// ===== ListItem::ListItem  @0x000b3300  (86 bytes)
/* ListItem::ListItem(AbyssEngine::String*) */

ListItem * __thiscall ListItem::ListItem(ListItem *this,String *param_1)

{
  String *this_00;
  
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x44) = 0;
  this_00 = operator_new(8);
  AbyssEngine::String::String(this_00,param_1,false);
  *(String **)(this + 0x1c) = this_00;
  this[0x24] = (ListItem)0x0;
  return this;
}

// ===== ListItem::ListItem  @0x000b3364  (96 bytes)
/* ListItem::ListItem(AbyssEngine::String*, int) */

ListItem * __thiscall ListItem::ListItem(ListItem *this,String *param_1,int param_2)

{
  String *this_00;
  
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x44) = 0;
  this_00 = operator_new(8);
  AbyssEngine::String::String(this_00,param_1,false);
  *(String **)(this + 0x1c) = this_00;
  *(int *)(this + 0x30) = param_2;
  this[0x24] = (ListItem)0x0;
  return this;
}

// ===== ListItem::ListItem  @0x000b33d2  (96 bytes)
/* ListItem::ListItem(AbyssEngine::String*, bool) */

ListItem * __thiscall ListItem::ListItem(ListItem *this,String *param_1,bool param_2)

{
  String *this_00;
  
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x44) = 0;
  this_00 = operator_new(8);
  AbyssEngine::String::String(this_00,param_1,false);
  *(String **)(this + 0x1c) = this_00;
  this[0x44] = (ListItem)param_2;
  this[0x24] = (ListItem)0x0;
  return this;
}

// ===== ListItem::ListItem  @0x000b3440  (56 bytes)
/* ListItem::ListItem(int) */

void __thiscall ListItem::ListItem(ListItem *this,int param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(int *)(this + 0x28) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b3478  (108 bytes)
/* ListItem::ListItem(AbyssEngine::String*, AbyssEngine::String*) */

ListItem * __thiscall ListItem::ListItem(ListItem *this,String *param_1,String *param_2)

{
  String *pSVar1;
  
  this[0x24] = (ListItem)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined2 *)(this + 0x44) = 0;
  pSVar1 = operator_new(8);
  AbyssEngine::String::String(pSVar1,param_1,false);
  *(String **)(this + 0x1c) = pSVar1;
  pSVar1 = operator_new(8);
  AbyssEngine::String::String(pSVar1,param_2,false);
  *(String **)(this + 0x20) = pSVar1;
  this[0x24] = (ListItem)0x0;
  return this;
}

// ===== ListItem::ListItem  @0x000b34f4  (64 bytes)
/* ListItem::ListItem(int, int) */

void __thiscall ListItem::ListItem(ListItem *this,int param_1,int param_2)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(int *)(this + 0x28) = param_2;
  *(int *)(this + 0x2c) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b3534  (56 bytes)
/* ListItem::ListItem(Mission*) */

void __thiscall ListItem::ListItem(ListItem *this,Mission *param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(Mission **)(this + 0x14) = param_1;
  this[0x24] = (ListItem)0x1;
  return;
}

// ===== ListItem::ListItem  @0x000b356c  (56 bytes)
/* ListItem::ListItem(Array<AbyssEngine::String*>*) */

void __thiscall ListItem::ListItem(ListItem *this,Array *param_1)

{
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x30) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = 0xffffffff;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  this[0x38] = (ListItem)0x0;
  *(undefined4 *)(this + 0x3c) = 0xffffffff;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0;
  this[0x44] = (ListItem)0x0;
  this[0x45] = (ListItem)0x0;
  *(Array **)this = param_1;
  this[0x24] = (ListItem)0x0;
  return;
}

// ===== ListItem::~ListItem  @0x000b35a4  (42 bytes)
/* ListItem::~ListItem() */

ListItem * __thiscall ListItem::~ListItem(ListItem *this)

{
  void *pvVar1;
  
  if (*(String **)(this + 0x1c) != (String *)0x0) {
    pvVar1 = (void *)AbyssEngine::String::~String(*(String **)(this + 0x1c));
    operator_delete(pvVar1);
    *(undefined4 *)(this + 0x1c) = 0;
  }
  if (*(String **)(this + 0x20) != (String *)0x0) {
    pvVar1 = (void *)AbyssEngine::String::~String(*(String **)(this + 0x20));
    operator_delete(pvVar1);
    *(undefined4 *)(this + 0x20) = 0;
  }
  return this;
}

// ===== ListItem::isSelectable  @0x000b35ce  (6 bytes)
/* ListItem::isSelectable() */

ListItem __thiscall ListItem::isSelectable(ListItem *this)

{
  return this[0x24];
}

// ===== ListItem::isImage  @0x000b35d4  (14 bytes)
/* ListItem::isImage() */

bool __thiscall ListItem::isImage(ListItem *this)

{
  return *(uint *)(this + 0x34) < 0x80000000;
}

// ===== ListItem::isShip  @0x000b35e2  (10 bytes)
/* ListItem::isShip() */

bool __thiscall ListItem::isShip(ListItem *this)

{
  return *(int *)(this + 0xc) != 0;
}

// ===== ListItem::isItem  @0x000b35ec  (10 bytes)
/* ListItem::isItem() */

bool __thiscall ListItem::isItem(ListItem *this)

{
  return *(int *)(this + 0x10) != 0;
}

// ===== ListItem::isCargo  @0x000b35f6  (10 bytes)
/* ListItem::isCargo() */

bool __thiscall ListItem::isCargo(ListItem *this)

{
  return *(int *)(this + 0x10) != 0;
}

// ===== ListItem::isTab  @0x000b3600  (32 bytes)
/* ListItem::isTab() */

undefined4 __thiscall ListItem::isTab(ListItem *this)

{
  undefined4 uVar1;
  
  if (this[0x24] != (ListItem)0x0) {
    return 0;
  }
  uVar1 = 0;
  if ((*(int *)(*(int *)(this + 0x1c) + 4) != 0) && (this[0x38] == (ListItem)0x0)) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== ListItem::isMission  @0x000b3620  (10 bytes)
/* ListItem::isMission() */

bool __thiscall ListItem::isMission(ListItem *this)

{
  return *(int *)(this + 0x14) != 0;
}

// ===== ListItem::isSlot  @0x000b362a  (14 bytes)
/* ListItem::isSlot() */

bool __thiscall ListItem::isSlot(ListItem *this)

{
  return *(uint *)(this + 0x28) < 0x80000000;
}

// ===== ListItem::isTextButton  @0x000b3638  (6 bytes)
/* ListItem::isTextButton() */

ListItem __thiscall ListItem::isTextButton(ListItem *this)

{
  return this[0x38];
}

// ===== ListItem::isSellButton  @0x000b363e  (20 bytes)
/* ListItem::isSellButton() */

undefined4 __thiscall ListItem::isSellButton(ListItem *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this[0x38] != (ListItem)0x0) && (*(int *)(this + 0x30) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

// ===== ListItem::isMoveToCargoButton  @0x000b3652  (20 bytes)
/* ListItem::isMoveToCargoButton() */

bool __thiscall ListItem::isMoveToCargoButton(ListItem *this)

{
  if (this[0x38] != (ListItem)0x0) {
    return *(int *)(this + 0x30) == 1;
  }
  return false;
}

// ===== ListItem::isBluePrint  @0x000b3666  (10 bytes)
/* ListItem::isBluePrint() */

bool __thiscall ListItem::isBluePrint(ListItem *this)

{
  return *(int *)(this + 8) != 0;
}

// ===== ListItem::isPendingProduct  @0x000b3670  (10 bytes)
/* ListItem::isPendingProduct() */

bool __thiscall ListItem::isPendingProduct(ListItem *this)

{
  return *(int *)(this + 0x18) != 0;
}

// ===== ListItem::isText  @0x000b367a  (6 bytes)
/* ListItem::isText() */

ListItem __thiscall ListItem::isText(ListItem *this)

{
  return this[0x44];
}

// ===== ListItem::getNumLines  @0x000b3680  (16 bytes)
/* ListItem::getNumLines() */

undefined4 __thiscall ListItem::getNumLines(ListItem *this)

{
  undefined4 uVar1;
  
  if (this[0x44] == (ListItem)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = **(undefined4 **)this;
  }
  return uVar1;
}

// ===== ListItem::checkCredits  @0x000b3690  (66 bytes)
/* ListItem::checkCredits() */

bool __thiscall ListItem::checkCredits(ListItem *this)

{
  int iVar1;
  int iVar2;
  
  if (*(Ship **)(this + 0xc) == (Ship *)0x0) {
    if (*(Item **)(this + 0x10) == (Item *)0x0) {
      return false;
    }
    iVar1 = Item::getSinglePrice(*(Item **)(this + 0x10));
    iVar2 = Status::getCredits(Globals::status);
  }
  else {
    iVar1 = Ship::getPrice(*(Ship **)(this + 0xc));
    iVar2 = Status::getCredits(Globals::status);
  }
  return iVar1 <= iVar2;
}

// ===== ListItem::checkSlot  @0x000b36dc  (54 bytes)
/* ListItem::checkSlot() */

undefined4 __thiscall ListItem::checkSlot(ListItem *this)

{
  Ship *this_00;
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(this + 0x10) != 0) {
    this_00 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Item::getType(*(Item **)(this + 0x10));
    iVar1 = Ship::getFreeSlots(this_00,iVar1);
    if (0 < iVar1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

// ===== ListItem::checkSort  @0x000b3718  (44 bytes)
/* ListItem::checkSort() */

undefined4 __thiscall ListItem::checkSort(ListItem *this)

{
  Ship *this_00;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(this + 0x10) != 0) {
    this_00 = (Ship *)Status::getShip(Globals::status);
    iVar1 = Item::getSort(*(Item **)(this + 0x10));
    uVar2 = Ship::slotAvailable(this_00,iVar1);
    return uVar2;
  }
  return 0;
}

// ===== ListItem::getPrice  @0x000b3748  (26 bytes)
/* ListItem::getPrice() */

undefined4 __thiscall ListItem::getPrice(ListItem *this)

{
  undefined4 uVar1;
  
  if (*(Ship **)(this + 0xc) != (Ship *)0x0) {
    uVar1 = Ship::getPrice(*(Ship **)(this + 0xc));
    return uVar1;
  }
  if (*(Item **)(this + 0x10) == (Item *)0x0) {
    return 0;
  }
  uVar1 = Item::getSinglePrice(*(Item **)(this + 0x10));
  return uVar1;
}

// ===== ListItem::getIndex  @0x000b375e  (54 bytes)
/* ListItem::getIndex() */

undefined4 __thiscall ListItem::getIndex(ListItem *this)

{
  undefined4 uVar1;
  
  if (*(Ship **)(this + 0xc) != (Ship *)0x0) {
    uVar1 = Ship::getIndex(*(Ship **)(this + 0xc));
    return uVar1;
  }
  if (*(Item **)(this + 0x10) != (Item *)0x0) {
    uVar1 = Item::getIndex(*(Item **)(this + 0x10));
    return uVar1;
  }
  if (*(BluePrint **)(this + 8) != (BluePrint *)0x0) {
    uVar1 = BluePrint::getIndex(*(BluePrint **)(this + 8));
    return uVar1;
  }
  if (*(int *)(this + 0x18) == 0) {
    uVar1 = 999999;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(this + 0x18) + 0x10);
  }
  return uVar1;
}

