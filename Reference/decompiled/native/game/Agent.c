// Class: Agent
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Agent::Agent  @0x001a65b4  (202 bytes)
/* Agent::Agent(int, AbyssEngine::String, int, int, int, bool, int, int, int, int) */

Agent * __thiscall
Agent::Agent(Agent *this,uint param_1,String *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,Agent param_7,int param_8,int param_9,int param_10,
            undefined4 param_11)

{
  undefined4 uVar1;
  
  AbyssEngine::String::String((String *)this);
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 100));
  AbyssEngine::String::String((String *)(this + 0x6c));
  *(uint *)(this + 0x38) = param_1;
  AbyssEngine::String::operator=((String *)this,param_3);
  *(undefined4 *)(this + 0x3c) = param_4;
  *(undefined4 *)(this + 0x40) = param_5;
  *(undefined4 *)(this + 0x44) = param_6;
  this[0x48] = param_7;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  *(int *)(this + 0x5c) = param_8;
  if (-1 < param_8) {
    *(undefined4 *)(this + 0x54) = 4;
  }
  *(int *)(this + 0x60) = param_9;
  if (-1 < param_9) {
    *(undefined4 *)(this + 0x54) = 3;
  }
  *(undefined4 *)(this + 0x34) = param_11;
  *(uint *)(this + 0x50) = param_1 >> 0x1f;
  *(undefined4 *)(this + 0x10) = 0;
  this[0x74] = (Agent)0x0;
  this[0x75] = (Agent)0x0;
  this[0x1c] = (Agent)0x0;
  this[0x1d] = (Agent)0x0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = 0xffffffff;
  if (-1 < param_10) {
    *(undefined4 *)(this + 0x54) = 8;
  }
  if (param_1 == 0x1a) {
    uVar1 = 10;
  }
  else {
    if (param_1 != 0x19) goto LAB_001a6672;
    uVar1 = 9;
  }
  *(undefined4 *)(this + 0x54) = uVar1;
LAB_001a6672:
  *(int *)(this + 0x84) = param_10;
  return this;
}

// ===== Agent::~Agent  @0x001a66aa  (68 bytes)
/* Agent::~Agent() */

void __thiscall Agent::~Agent(Agent *this)

{
  void *pvVar1;
  
  if (*(void **)(this + 0x78) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x78));
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(String **)(this + 8) != (String *)0x0) {
    pvVar1 = (void *)AbyssEngine::String::~String(*(String **)(this + 8));
    operator_delete(pvVar1);
    *(undefined4 *)(this + 8) = 0;
  }
  AbyssEngine::String::~String((String *)(this + 0x6c));
  AbyssEngine::String::~String((String *)(this + 100));
  AbyssEngine::String::~String((String *)(this + 0x14));
  AbyssEngine::String::~String((String *)this);
  return;
}

// ===== Agent::getIndex  @0x001a66ec  (4 bytes)
/* Agent::getIndex() */

undefined4 __thiscall Agent::getIndex(Agent *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== Agent::getName  @0x001a66f0  (12 bytes)
/* Agent::getName() */

void Agent::getName(void)

{
  String *in_r0;
  String *in_r1;
  
  AbyssEngine::String::String(in_r0,in_r1,false);
  return;
}

// ===== Agent::getType  @0x001a66fc  (4 bytes)
/* Agent::getType() */

undefined4 __thiscall Agent::getType(Agent *this)

{
  return *(undefined4 *)(this + 0x50);
}

// ===== Agent::getOffer  @0x001a6700  (4 bytes)
/* Agent::getOffer() */

undefined4 __thiscall Agent::getOffer(Agent *this)

{
  return *(undefined4 *)(this + 0x54);
}

// ===== Agent::getRace  @0x001a6704  (4 bytes)
/* Agent::getRace() */

undefined4 __thiscall Agent::getRace(Agent *this)

{
  return *(undefined4 *)(this + 0x44);
}

// ===== Agent::getSystem  @0x001a6708  (4 bytes)
/* Agent::getSystem() */

undefined4 __thiscall Agent::getSystem(Agent *this)

{
  return *(undefined4 *)(this + 0x40);
}

// ===== Agent::getStation  @0x001a670c  (4 bytes)
/* Agent::getStation() */

undefined4 __thiscall Agent::getStation(Agent *this)

{
  return *(undefined4 *)(this + 0x3c);
}

// ===== Agent::isMale  @0x001a6710  (6 bytes)
/* Agent::isMale() */

Agent __thiscall Agent::isMale(Agent *this)

{
  return this[0x48];
}

// ===== Agent::getEvent  @0x001a6716  (4 bytes)
/* Agent::getEvent() */

undefined4 __thiscall Agent::getEvent(Agent *this)

{
  return *(undefined4 *)(this + 0x4c);
}

// ===== Agent::setEvent  @0x001a671a  (4 bytes)
/* Agent::setEvent(int) */

void __thiscall Agent::setEvent(Agent *this,int param_1)

{
  *(int *)(this + 0x4c) = param_1;
  return;
}

// ===== Agent::nextEvent  @0x001a671e  (8 bytes)
/* Agent::nextEvent() */

void __thiscall Agent::nextEvent(Agent *this)

{
  *(int *)(this + 0x4c) = *(int *)(this + 0x4c) + 1;
  return;
}

// ===== Agent::isStoryAgent  @0x001a6726  (12 bytes)
/* Agent::isStoryAgent() */

bool __thiscall Agent::isStoryAgent(Agent *this)

{
  return *(int *)(this + 0x50) == 0;
}

// ===== Agent::isGenericAgent  @0x001a6732  (10 bytes)
/* Agent::isGenericAgent() */

bool __thiscall Agent::isGenericAgent(Agent *this)

{
  return *(int *)(this + 0x50) == 1;
}

// ===== Agent::setImageParts  @0x001a673c  (4 bytes)
/* Agent::setImageParts(int*) */

void __thiscall Agent::setImageParts(Agent *this,int *param_1)

{
  *(int **)(this + 0x78) = param_1;
  return;
}

// ===== Agent::getImageParts  @0x001a6740  (4 bytes)
/* Agent::getImageParts() */

undefined4 __thiscall Agent::getImageParts(Agent *this)

{
  return *(undefined4 *)(this + 0x78);
}

// ===== Agent::setOffer  @0x001a6744  (4 bytes)
/* Agent::setOffer(int) */

void __thiscall Agent::setOffer(Agent *this,int param_1)

{
  *(int *)(this + 0x54) = param_1;
  return;
}

// ===== Agent::setMission  @0x001a6748  (4 bytes)
/* Agent::setMission(Mission*) */

void __thiscall Agent::setMission(Agent *this,Mission *param_1)

{
  *(Mission **)(this + 0x7c) = param_1;
  return;
}

// ===== Agent::getMission  @0x001a674c  (4 bytes)
/* Agent::getMission() */

undefined4 __thiscall Agent::getMission(Agent *this)

{
  return *(undefined4 *)(this + 0x7c);
}

// ===== Agent::isKnown  @0x001a6750  (12 bytes)
/* Agent::isKnown() */

bool __thiscall Agent::isKnown(Agent *this)

{
  return 0 < *(int *)(this + 0x4c);
}

// ===== Agent::setWingmanFriendNames  @0x001a675c  (298 bytes)
/* Agent::setWingmanFriendNames(Array<AbyssEngine::String*>*) */

void __thiscall Agent::setWingmanFriendNames(Agent *this,Array *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  String *this_00;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  if (*(String **)(this + 8) != (String *)0x0) {
    pvVar1 = (void *)AbyssEngine::String::~String(*(String **)(this + 8));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 8) = 0;
  if (*(String **)(this + 0xc) != (String *)0x0) {
    pvVar1 = (void *)AbyssEngine::String::~String(*(String **)(this + 0xc));
    operator_delete(pvVar1);
  }
  *(undefined4 *)(this + 0xc) = 0;
  pvVar1 = *(void **)(this + 0x80);
  if (pvVar1 != (void *)0x0) {
    if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)((int)pvVar1 + 4));
    }
    operator_delete(pvVar1);
    *(undefined4 *)(this + 0x80) = 0;
  }
  puVar2 = operator_new(0xc);
  puVar3 = operator_new__(4);
  puVar2[1] = puVar3;
  *puVar3 = 0;
  puVar2[2] = 1;
  *puVar2 = 0;
  *(undefined4 **)(this + 0x80) = puVar2;
  this_00 = operator_new(8);
  AbyssEngine::String::String(this_00,this,false);
  piVar5 = *(int **)(this + 0x80);
  piVar5[2] = *piVar5 + 1;
  pvVar1 = realloc((void *)piVar5[1],(*piVar5 + 1) * 4);
  piVar5[1] = (int)pvVar1;
  *(String **)((int)pvVar1 + *piVar5 * 4) = this_00;
  *piVar5 = piVar5[2];
  *(undefined4 *)(this + 0x10) = 0;
  if (param_1 != (Array *)0x0) {
    uVar4 = *(uint *)param_1;
    if (uVar4 != 0) {
      iVar6 = **(int **)(param_1 + 4);
      if (iVar6 != 0) {
        *(int *)(this + 8) = iVar6;
        *(undefined4 *)(this + 0x10) = 1;
        piVar5 = *(int **)(this + 0x80);
        piVar5[2] = *piVar5 + 1;
        pvVar1 = realloc((void *)piVar5[1],(*piVar5 + 1) * 4);
        piVar5[1] = (int)pvVar1;
        *(int *)((int)pvVar1 + *piVar5 * 4) = iVar6;
        *piVar5 = piVar5[2];
        uVar4 = *(uint *)param_1;
      }
      if ((1 < uVar4) && (iVar6 = *(int *)(*(int *)(param_1 + 4) + 4), iVar6 != 0)) {
        *(int *)(this + 0xc) = iVar6;
        *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
        piVar5 = *(int **)(this + 0x80);
        piVar5[2] = *piVar5 + 1;
        pvVar1 = realloc((void *)piVar5[1],(*piVar5 + 1) * 4);
        piVar5[1] = (int)pvVar1;
        *(int *)((int)pvVar1 + *piVar5 * 4) = iVar6;
        *piVar5 = piVar5[2];
      }
    }
    if (*(void **)(param_1 + 4) != (void *)0x0) {
      operator_delete__(*(void **)(param_1 + 4));
    }
    *(undefined4 *)(param_1 + 4) = 0;
    operator_delete(param_1);
    return;
  }
  return;
}

// ===== Agent::getSellSystemIndex  @0x001a6896  (4 bytes)
/* Agent::getSellSystemIndex() */

undefined4 __thiscall Agent::getSellSystemIndex(Agent *this)

{
  return *(undefined4 *)(this + 0x5c);
}

// ===== Agent::getSellBlueprintIndex  @0x001a689a  (4 bytes)
/* Agent::getSellBlueprintIndex() */

undefined4 __thiscall Agent::getSellBlueprintIndex(Agent *this)

{
  return *(undefined4 *)(this + 0x60);
}

// ===== Agent::setCosts  @0x001a689e  (4 bytes)
/* Agent::setCosts(int) */

void __thiscall Agent::setCosts(Agent *this,int param_1)

{
  *(int *)(this + 0x58) = param_1;
  return;
}

// ===== Agent::getCosts  @0x001a68a2  (4 bytes)
/* Agent::getCosts() */

undefined4 __thiscall Agent::getCosts(Agent *this)

{
  return *(undefined4 *)(this + 0x58);
}

// ===== Agent::getWingmanFriendsCount  @0x001a68a6  (4 bytes)
/* Agent::getWingmanFriendsCount() */

undefined4 __thiscall Agent::getWingmanFriendsCount(Agent *this)

{
  return *(undefined4 *)(this + 0x10);
}

// ===== Agent::getWingmanName  @0x001a68aa  (24 bytes)
/* Agent::getWingmanName(int) */

void Agent::getWingmanName(int param_1)

{
  String *in_r1;
  int in_r2;
  
  if (in_r2 == 1) {
    in_r1 = *(String **)(in_r1 + 8);
  }
  else if (in_r2 != 0) {
    in_r1 = *(String **)(in_r1 + 0xc);
  }
  AbyssEngine::String::String((String *)param_1,in_r1,false);
  return;
}

// ===== Agent::getWingmanNames  @0x001a68c2  (6 bytes)
/* Agent::getWingmanNames() */

undefined4 __thiscall Agent::getWingmanNames(Agent *this)

{
  return *(undefined4 *)(this + 0x80);
}

// ===== Agent::getMissionString  @0x001a68c8  (14 bytes)
/* Agent::getMissionString() */

void Agent::getMissionString(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 100),false);
  return;
}

// ===== Agent::setMissionString  @0x001a68d8  (66 bytes)
/* Agent::setMissionString(AbyssEngine::String) */

void __thiscall Agent::setMissionString(Agent *this,String *param_2)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  AbyssEngine::String::String(aSStack_1c,param_2,false);
  AbyssEngine::String::operator=((String *)(this + 100),aSStack_1c);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Agent::getSellItemIndex  @0x001a6930  (4 bytes)
/* Agent::getSellItemIndex() */

undefined4 __thiscall Agent::getSellItemIndex(Agent *this)

{
  return *(undefined4 *)(this + 0x2c);
}

// ===== Agent::getSellItemQuantity  @0x001a6934  (4 bytes)
/* Agent::getSellItemQuantity() */

undefined4 __thiscall Agent::getSellItemQuantity(Agent *this)

{
  return *(undefined4 *)(this + 0x30);
}

// ===== Agent::getSellItemPrice  @0x001a6938  (4 bytes)
/* Agent::getSellItemPrice() */

undefined4 __thiscall Agent::getSellItemPrice(Agent *this)

{
  return *(undefined4 *)(this + 0x34);
}

// ===== Agent::setSellItemPrice  @0x001a693c  (4 bytes)
/* Agent::setSellItemPrice(int) */

void __thiscall Agent::setSellItemPrice(Agent *this,int param_1)

{
  *(int *)(this + 0x34) = param_1;
  return;
}

// ===== Agent::setSellItemData  @0x001a6940  (6 bytes)
/* Agent::setSellItemData(int, int, int) */

Agent * __thiscall Agent::setSellItemData(Agent *this,int param_1,int param_2,int param_3)

{
  *(int *)(this + 0x2c) = param_1;
  *(int *)(this + 0x30) = param_2;
  *(int *)(this + 0x34) = param_3;
  return this + 0x38;
}

// ===== Agent::hasAcceptedOffer  @0x001a6946  (6 bytes)
/* Agent::hasAcceptedOffer() */

Agent __thiscall Agent::hasAcceptedOffer(Agent *this)

{
  return this[0x74];
}

// ===== Agent::setOfferAccepted  @0x001a694c  (6 bytes)
/* Agent::setOfferAccepted(bool) */

void __thiscall Agent::setOfferAccepted(Agent *this,bool param_1)

{
  this[0x74] = (Agent)param_1;
  return;
}

// ===== Agent::hasReward  @0x001a6952  (6 bytes)
/* Agent::hasReward() */

Agent __thiscall Agent::hasReward(Agent *this)

{
  return this[0x75];
}

// ===== Agent::giveRewardAtNextChat  @0x001a6958  (6 bytes)
/* Agent::giveRewardAtNextChat(bool) */

void __thiscall Agent::giveRewardAtNextChat(Agent *this,bool param_1)

{
  this[0x75] = (Agent)param_1;
  return;
}

// ===== Agent::getStationName  @0x001a695e  (14 bytes)
/* Agent::getStationName() */

void Agent::getStationName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0x6c),false);
  return;
}

// ===== Agent::setStationName  @0x001a696c  (6 bytes)
/* Agent::setStationName(AbyssEngine::String) */

void __thiscall Agent::setStationName(Agent *this,String *param_2)

{
  AbyssEngine::String::operator=((String *)(this + 0x6c),param_2);
  return;
}

// ===== Agent::getSystemName  @0x001a6972  (14 bytes)
/* Agent::getSystemName() */

void Agent::getSystemName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0x14),false);
  return;
}

// ===== Agent::setSystemName  @0x001a6980  (8 bytes)
/* Agent::setSystemName(AbyssEngine::String) */

void __thiscall Agent::setSystemName(Agent *this,String *param_2)

{
  AbyssEngine::String::operator=((String *)(this + 0x14),param_2);
  return;
}

// ===== Agent::getSellModIndex  @0x001a6986  (6 bytes)
/* Agent::getSellModIndex() */

undefined4 __thiscall Agent::getSellModIndex(Agent *this)

{
  return *(undefined4 *)(this + 0x84);
}

// ===== Agent::getModPricePercentage  @0x001a698c  (22 bytes)
/* Agent::getModPricePercentage() */

undefined4 __thiscall Agent::getModPricePercentage(Agent *this)

{
  if (*(uint *)(this + 0x84) < 4) {
    return *(undefined4 *)(&DAT_00252090 + *(uint *)(this + 0x84) * 4);
  }
  return 0x28;
}

