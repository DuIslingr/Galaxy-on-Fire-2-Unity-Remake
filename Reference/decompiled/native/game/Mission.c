// Class: Mission
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Mission::Mission  @0x00187ba8  (204 bytes)
/* Mission::Mission(int, AbyssEngine::String, int*, int, int, int, int) */

void __thiscall
Mission::Mission(Mission *this,undefined4 param_1,String *param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8)

{
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x34));
  AbyssEngine::String::String((String *)(this + 0x3c));
  *(undefined4 *)(this + 8) = param_1;
  AbyssEngine::String::operator=((String *)(this + 0xc),param_3);
  *(undefined4 *)(this + 0x1c) = param_4;
  *(undefined4 *)(this + 0x20) = param_5;
  *(undefined4 *)(this + 0x24) = param_6;
  *(int *)(this + 0x30) = param_7;
  Galaxy::getStation(Globals::galaxy,param_7);
  Station::getName();
  AbyssEngine::String::operator=((String *)(this + 0x34),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  *(undefined4 *)(this + 0x44) = param_8;
  AbyssEngine::String::String(aSStack_30,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x3c),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  *(undefined4 *)(this + 0x50) = 0;
  this[0x60] = (Mission)0x1;
  this[0x48] = (Mission)0x0;
  *this = (Mission)0x0;
  this[1] = (Mission)0x0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== Mission::Mission  @0x00187cc0  (208 bytes)
/* Mission::Mission(int, int, int) */

void __thiscall Mission::Mission(Mission *this,int param_1,int param_2,int param_3)

{
  String aSStack_30 [8];
  int local_28;
  
  local_28 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x34));
  AbyssEngine::String::String((String *)(this + 0x3c));
  *(int *)(this + 8) = param_1;
  *(int *)(this + 0x24) = param_2;
  *(int *)(this + 0x30) = param_3;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 4) = 0;
  if (param_3 < 0) {
    AbyssEngine::String::String(aSStack_30,"",false);
  }
  else {
    Galaxy::getStation(Globals::galaxy,param_3);
    Station::getName();
  }
  AbyssEngine::String::operator=((String *)(this + 0x34),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  AbyssEngine::String::String(aSStack_30,"",false);
  AbyssEngine::String::operator=((String *)(this + 0x3c),aSStack_30);
  AbyssEngine::String::~String(aSStack_30);
  *(undefined4 *)(this + 0x50) = 1;
  this[0x60] = (Mission)0x1;
  *this = (Mission)0x0;
  this[1] = (Mission)0x0;
  this[0x48] = (Mission)0x0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  if (__stack_chk_guard - local_28 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_28);
  }
  return;
}

// ===== Mission::Mission  @0x00187de0  (150 bytes)
/* Mission::Mission() */

void __thiscall Mission::Mission(Mission *this)

{
  String aSStack_28 [8];
  int local_20;
  
  local_20 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x34));
  AbyssEngine::String::String((String *)(this + 0x3c));
  AbyssEngine::String::String(aSStack_28,"",false);
  AbyssEngine::String::operator=((String *)(this + 0xc),aSStack_28);
  AbyssEngine::String::~String(aSStack_28);
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  this[0x60] = (Mission)0x0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  this[0x48] = (Mission)0x0;
  *(undefined4 *)(this + 0x5c) = 0;
  *this = (Mission)0x0;
  this[1] = (Mission)0x0;
  *(undefined4 *)(this + 0x2c) = 0;
  if (__stack_chk_guard - local_20 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_20);
  }
  return;
}

// ===== Mission::Mission  @0x00187eb8  (148 bytes)
/* Mission::Mission(int) */

void __thiscall Mission::Mission(Mission *this,int param_1)

{
  String aSStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  AbyssEngine::String::String((String *)(this + 0xc));
  AbyssEngine::String::String((String *)(this + 0x14));
  AbyssEngine::String::String((String *)(this + 0x34));
  AbyssEngine::String::String((String *)(this + 0x3c));
  AbyssEngine::String::String(aSStack_2c,"",false);
  AbyssEngine::String::operator=((String *)(this + 0xc),aSStack_2c);
  AbyssEngine::String::~String(aSStack_2c);
  *(int *)(this + 8) = param_1;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  this[0x60] = (Mission)0x0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  this[0x48] = (Mission)0x0;
  *(undefined4 *)(this + 0x5c) = 0;
  *this = (Mission)0x0;
  this[1] = (Mission)0x0;
  *(undefined4 *)(this + 0x2c) = 0;
  if (__stack_chk_guard - local_24 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_24);
  }
  return;
}

// ===== Mission::~Mission  @0x00187f90  (42 bytes)
/* Mission::~Mission() */

Mission * __thiscall Mission::~Mission(Mission *this)

{
  AbyssEngine::String::~String((String *)(this + 0x3c));
  AbyssEngine::String::~String((String *)(this + 0x34));
  AbyssEngine::String::~String((String *)(this + 0x14));
  AbyssEngine::String::~String((String *)(this + 0xc));
  return this;
}

// ===== Mission::isEmpty  @0x00187fba  (14 bytes)
/* Mission::isEmpty() */

bool __thiscall Mission::isEmpty(Mission *this)

{
  return *(int *)(this + 8) == -1;
}

// ===== Mission::setVisible  @0x00187fc8  (6 bytes)
/* Mission::setVisible(bool) */

void __thiscall Mission::setVisible(Mission *this,bool param_1)

{
  this[0x60] = (Mission)param_1;
  return;
}

// ===== Mission::isVisible  @0x00187fce  (6 bytes)
/* Mission::isVisible() */

Mission __thiscall Mission::isVisible(Mission *this)

{
  return this[0x60];
}

// ===== Mission::setFailed  @0x00187fd4  (4 bytes)
/* Mission::setFailed(bool) */

void __thiscall Mission::setFailed(Mission *this,bool param_1)

{
  *this = (Mission)param_1;
  return;
}

// ===== Mission::hasFailed  @0x00187fd8  (4 bytes)
/* Mission::hasFailed() */

Mission __thiscall Mission::hasFailed(Mission *this)

{
  return *this;
}

// ===== Mission::setWon  @0x00187fdc  (4 bytes)
/* Mission::setWon(bool) */

void __thiscall Mission::setWon(Mission *this,bool param_1)

{
  this[1] = (Mission)param_1;
  return;
}

// ===== Mission::hasWon  @0x00187fe0  (4 bytes)
/* Mission::hasWon() */

Mission __thiscall Mission::hasWon(Mission *this)

{
  return this[1];
}

// ===== Mission::setProductionGoods  @0x00187fe4  (6 bytes)
/* Mission::setProductionGoods(int, int) */

void __thiscall Mission::setProductionGoods(Mission *this,int param_1,int param_2)

{
  *(int *)(this + 0x54) = param_1;
  *(int *)(this + 0x58) = param_2;
  return;
}

// ===== Mission::getProductionGoodIndex  @0x00187fea  (4 bytes)
/* Mission::getProductionGoodIndex() */

undefined4 __thiscall Mission::getProductionGoodIndex(Mission *this)

{
  return *(undefined4 *)(this + 0x54);
}

// ===== Mission::getProductionGoodAmount  @0x00187fee  (4 bytes)
/* Mission::getProductionGoodAmount() */

undefined4 __thiscall Mission::getProductionGoodAmount(Mission *this)

{
  return *(undefined4 *)(this + 0x58);
}

// ===== Mission::setStatusValue  @0x00187ff2  (4 bytes)
/* Mission::setStatusValue(int) */

void __thiscall Mission::setStatusValue(Mission *this,int param_1)

{
  *(int *)(this + 0x5c) = param_1;
  return;
}

// ===== Mission::getStatusValue  @0x00187ff6  (4 bytes)
/* Mission::getStatusValue() */

undefined4 __thiscall Mission::getStatusValue(Mission *this)

{
  return *(undefined4 *)(this + 0x5c);
}

// ===== Mission::getType  @0x00187ffa  (4 bytes)
/* Mission::getType() */

undefined4 __thiscall Mission::getType(Mission *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== Mission::getName  @0x00188000  (54 bytes)
/* Mission::getName() */

void Mission::getName(void)

{
  String *in_r0;
  String *pSVar1;
  int in_r1;
  
  if (*(int *)(in_r1 + 0x50) != 0) {
    AbyssEngine::String::String(in_r0,"",false);
    return;
  }
  pSVar1 = (String *)GameText::getText(Globals::gameText,*(int *)(in_r1 + 8) + 0x162);
  AbyssEngine::String::String(in_r0,pSVar1,false);
  return;
}

// ===== Mission::getDescription  @0x00188040  (16 bytes)
/* Mission::getDescription() */

void __thiscall Mission::getDescription(Mission *this)

{
  AbyssEngine::String::String((String *)this,"",false);
  return;
}

// ===== Mission::isOutsideMission  @0x00188054  (4 bytes)
/* Mission::isOutsideMission() */

undefined4 Mission::isOutsideMission(void)

{
  return 1;
}

// ===== Mission::getClientName  @0x00188058  (14 bytes)
/* Mission::getClientName() */

void Mission::getClientName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0xc),false);
  return;
}

// ===== Mission::getClientImage  @0x00188066  (4 bytes)
/* Mission::getClientImage() */

undefined4 __thiscall Mission::getClientImage(Mission *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== Mission::getClientRace  @0x0018806a  (4 bytes)
/* Mission::getClientRace() */

undefined4 __thiscall Mission::getClientRace(Mission *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== Mission::getReward  @0x0018806e  (4 bytes)
/* Mission::getReward() */

undefined4 __thiscall Mission::getReward(Mission *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== Mission::setReward  @0x00188072  (4 bytes)
/* Mission::setReward(int) */

void __thiscall Mission::setReward(Mission *this,int param_1)

{
  *(int *)(this + 0x24) = param_1;
  return;
}

// ===== Mission::getCosts  @0x00188076  (4 bytes)
/* Mission::getCosts() */

undefined4 __thiscall Mission::getCosts(Mission *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== Mission::setCosts  @0x0018807a  (4 bytes)
/* Mission::setCosts(int) */

void __thiscall Mission::setCosts(Mission *this,int param_1)

{
  *(int *)(this + 0x28) = param_1;
  return;
}

// ===== Mission::getBonus  @0x0018807e  (4 bytes)
/* Mission::getBonus() */

undefined4 __thiscall Mission::getBonus(Mission *this)

{
  return *(undefined4 *)(this + 0x2c);
}

// ===== Mission::setBonus  @0x00188082  (4 bytes)
/* Mission::setBonus(int) */

void __thiscall Mission::setBonus(Mission *this,int param_1)

{
  *(int *)(this + 0x2c) = param_1;
  return;
}

// ===== Mission::setInstantActionMission  @0x00188086  (6 bytes)
/* Mission::setInstantActionMission(bool) */

void __thiscall Mission::setInstantActionMission(Mission *this,bool param_1)

{
  this[0x48] = (Mission)param_1;
  return;
}

// ===== Mission::isInstantActionMission  @0x0018808c  (6 bytes)
/* Mission::isInstantActionMission() */

Mission __thiscall Mission::isInstantActionMission(Mission *this)

{
  return this[0x48];
}

// ===== Mission::isCampaignMission  @0x00188092  (10 bytes)
/* Mission::isCampaignMission() */

bool __thiscall Mission::isCampaignMission(Mission *this)

{
  return *(int *)(this + 0x50) != 0;
}

// ===== Mission::setCampaignMission  @0x0018809c  (4 bytes)
/* Mission::setCampaignMission(bool) */

void __thiscall Mission::setCampaignMission(Mission *this,bool param_1)

{
  *(uint *)(this + 0x50) = (uint)param_1;
  return;
}

// ===== Mission::getTargetStation  @0x001880a0  (4 bytes)
/* Mission::getTargetStation() */

undefined4 __thiscall Mission::getTargetStation(Mission *this)

{
  return *(undefined4 *)(this + 0x30);
}

// ===== Mission::getTargetStationName  @0x001880a4  (14 bytes)
/* Mission::getTargetStationName() */

void Mission::getTargetStationName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0x34),false);
  return;
}

// ===== Mission::getTargetSystemName  @0x001880b2  (14 bytes)
/* Mission::getTargetSystemName() */

void Mission::getTargetSystemName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0x3c),false);
  return;
}

// ===== Mission::setTargetSystemName  @0x001880c0  (6 bytes)
/* Mission::setTargetSystemName(AbyssEngine::String const&) */

void __thiscall Mission::setTargetSystemName(Mission *this,String *param_1)

{
  AbyssEngine::String::operator=((String *)(this + 0x3c),param_1);
  return;
}

// ===== Mission::setTargetStation  @0x001880c8  (80 bytes)
/* Mission::setTargetStation(int) */

void __thiscall Mission::setTargetStation(Mission *this,int param_1)

{
  String aSStack_1c [8];
  int local_14;
  
  local_14 = __stack_chk_guard;
  *(int *)(this + 0x30) = param_1;
  Galaxy::getStation(Globals::galaxy,param_1);
  Station::getName();
  AbyssEngine::String::operator=((String *)(this + 0x34),aSStack_1c);
  AbyssEngine::String::~String(aSStack_1c);
  if (__stack_chk_guard != local_14) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

// ===== Mission::setDifficulty  @0x00188134  (4 bytes)
/* Mission::setDifficulty(int) */

void __thiscall Mission::setDifficulty(Mission *this,int param_1)

{
  *(int *)(this + 0x44) = param_1;
  return;
}

// ===== Mission::getDifficulty  @0x00188138  (4 bytes)
/* Mission::getDifficulty() */

undefined4 __thiscall Mission::getDifficulty(Mission *this)

{
  return *(undefined4 *)(this + 0x44);
}

// ===== Mission::getDistance  @0x0018813c  (4 bytes)
/* Mission::getDistance() */

undefined4 __thiscall Mission::getDistance(Mission *this)

{
  return *(undefined4 *)(this + 0x4c);
}

// ===== Mission::calcDistance  @0x00188140  (120 bytes)
/* Mission::calcDistance() */

void __thiscall Mission::calcDistance(Mission *this)

{
  Galaxy *this_00;
  Station *this_01;
  int iVar1;
  Station *this_02;
  int iVar2;
  float fVar3;
  void *pvVar4;
  SolarSystem *pSVar5;
  
  this_01 = (Station *)Galaxy::getStation(Globals::galaxy,*(int *)(this + 0x30));
  iVar1 = Galaxy::getSystems(Globals::galaxy);
  this_00 = Globals::galaxy;
  this_02 = (Station *)Status::getStation(Globals::status);
  iVar2 = Station::getSystem(this_02);
  pSVar5 = *(SolarSystem **)(*(int *)(iVar1 + 4) + iVar2 * 4);
  iVar2 = Station::getSystem(this_01);
  fVar3 = (float)Galaxy::distance(this_00,pSVar5,*(SolarSystem **)(*(int *)(iVar1 + 4) + iVar2 * 4))
  ;
  *(int *)(this + 0x4c) = (int)fVar3;
  if (this_01 != (Station *)0x0) {
    pvVar4 = (void *)Station::~Station(this_01);
    operator_delete(pvVar4);
    return;
  }
  return;
}

// ===== Mission::getAgent  @0x001881c0  (4 bytes)
/* Mission::getAgent() */

undefined4 __thiscall Mission::getAgent(Mission *this)

{
  return *(undefined4 *)(this + 4);
}

// ===== Mission::setAgent  @0x001881c4  (4 bytes)
/* Mission::setAgent(Agent*) */

void __thiscall Mission::setAgent(Mission *this,Agent *param_1)

{
  *(Agent **)(this + 4) = param_1;
  return;
}

// ===== Mission::getTargetName  @0x001881c8  (14 bytes)
/* Mission::getTargetName() */

void Mission::getTargetName(void)

{
  String *in_r0;
  int in_r1;
  
  AbyssEngine::String::String(in_r0,(String *)(in_r1 + 0x14),false);
  return;
}

// ===== Mission::setTargetName  @0x001881d6  (6 bytes)
/* Mission::setTargetName(AbyssEngine::String) */

void __thiscall Mission::setTargetName(Mission *this,String *param_2)

{
  AbyssEngine::String::operator=((String *)(this + 0x14),param_2);
  return;
}

// ===== Mission::setType  @0x001881dc  (4 bytes)
/* Mission::setType(int) */

void __thiscall Mission::setType(Mission *this,int param_1)

{
  *(int *)(this + 8) = param_1;
  return;
}

// ===== Mission::clone  @0x001881e0  (108 bytes)
/* Mission::clone() */

void __thiscall Mission::clone(Mission *this)

{
  Mission *pMVar1;
  undefined4 uVar2;
  String aSStack_24 [8];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  pMVar1 = operator_new(100);
  uVar2 = *(undefined4 *)(this + 8);
  AbyssEngine::String::String(aSStack_24,this + 0xc,false);
  Mission(pMVar1,uVar2,aSStack_24,*(undefined4 *)(this + 0x1c),*(undefined4 *)(this + 0x20),
          *(undefined4 *)(this + 0x24),*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x44));
  AbyssEngine::String::~String(aSStack_24);
  pMVar1[0x48] = this[0x48];
  if (__stack_chk_guard - local_1c != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_1c);
  }
  return;
}

