// Class: NewsItem
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== NewsItem::NewsItem  @0x000f49d4  (28 bytes)
/* NewsItem::NewsItem(int, bool, bool*, int, int, int) */

void __thiscall
NewsItem::NewsItem(NewsItem *this,int param_1,bool param_2,bool *param_3,int param_4,int param_5,
                  int param_6)

{
  *(int *)this = param_1;
  this[4] = (NewsItem)param_2;
  *(bool **)(this + 8) = param_3;
  *(int *)(this + 0xc) = param_4;
  *(int *)(this + 0x10) = param_5;
  *(int *)(this + 0x14) = param_6;
  this[0x18] = (NewsItem)0x0;
  return;
}

// ===== NewsItem::~NewsItem  @0x000f49f0  (22 bytes)
/* NewsItem::~NewsItem() */

NewsItem * __thiscall NewsItem::~NewsItem(NewsItem *this)

{
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete__(*(void **)(this + 8));
  }
  *(undefined4 *)(this + 8) = 0;
  return this;
}

// ===== NewsItem::clone  @0x000f4a06  (80 bytes)
/* NewsItem::clone() */

void __thiscall NewsItem::clone(NewsItem *this)

{
  NewsItem NVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar9 = *(uint *)(this + 0xc);
  uVar2 = uVar9;
  if (0x7fffffff < uVar9) {
    uVar2 = 0xffffffff;
  }
  pvVar3 = operator_new__(uVar2);
  if (0 < (int)uVar9) {
    iVar4 = *(int *)(this + 8);
    iVar6 = 0;
    do {
      *(undefined1 *)((int)pvVar3 + iVar6) = *(undefined1 *)(iVar4 + iVar6);
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)uVar9);
  }
  puVar5 = operator_new(0x1c);
  uVar7 = *(undefined4 *)(this + 0x10);
  uVar8 = *(undefined4 *)(this + 0x14);
  NVar1 = this[4];
  *puVar5 = *(undefined4 *)this;
  *(NewsItem *)(puVar5 + 1) = NVar1;
  puVar5[2] = pvVar3;
  puVar5[3] = uVar9;
  puVar5[4] = uVar7;
  puVar5[5] = uVar8;
  *(undefined1 *)(puVar5 + 6) = 0;
  return;
}

