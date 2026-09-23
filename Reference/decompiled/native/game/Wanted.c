// Class: Wanted
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== Wanted::Wanted  @0x0014805c  (106 bytes)
/* Wanted::Wanted(int, AbyssEngine::String, int, int, bool, int, int, int, int, int, int, int, int,
   int) */

Wanted * __thiscall
Wanted::Wanted(Wanted *this,undefined4 param_1,String *param_3,undefined4 param_4,undefined4 param_5
              ,Wanted param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
              undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
              undefined4 param_14,undefined4 param_15)

{
  String *this_00;
  
  this_00 = (String *)AbyssEngine::String::String((String *)this);
  *(undefined4 *)(this + 8) = param_1;
  AbyssEngine::String::operator=(this_00,param_3);
  *(undefined4 *)(this + 0xc) = param_4;
  *(undefined4 *)(this + 0x10) = param_5;
  this[0x14] = param_6;
  *(undefined4 *)(this + 0x18) = param_7;
  *(undefined4 *)(this + 0x1c) = param_8;
  *(undefined4 *)(this + 0x20) = param_9;
  *(undefined4 *)(this + 0x24) = param_10;
  *(undefined4 *)(this + 0x28) = param_11;
  *(undefined4 *)(this + 0x2c) = param_12;
  *(undefined4 *)(this + 0x30) = param_13;
  this[0x4d] = (Wanted)0x0;
  this[0x4c] = (Wanted)0x0;
  *(undefined4 *)(this + 0x40) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 0xffffffff;
  *(undefined4 *)(this + 0x48) = 0xffffffff;
  *(undefined4 *)(this + 0x34) = param_14;
  *(undefined4 *)(this + 0x38) = param_15;
  return this;
}

// ===== Wanted::~Wanted  @0x001480d4  (28 bytes)
/* Wanted::~Wanted() */

void __thiscall Wanted::~Wanted(Wanted *this)

{
  if (*(void **)(this + 0x3c) != (void *)0x0) {
    operator_delete__(*(void **)(this + 0x3c));
  }
  *(undefined4 *)(this + 0x3c) = 0;
  AbyssEngine::String::~String((String *)this);
  return;
}

// ===== Wanted::getIndex  @0x001480f0  (4 bytes)
/* Wanted::getIndex() */

undefined4 __thiscall Wanted::getIndex(Wanted *this)

{
  return *(undefined4 *)(this + 8);
}

// ===== Wanted::getName  @0x001480f4  (12 bytes)
/* Wanted::getName() */

void Wanted::getName(void)

{
  String *in_r0;
  String *in_r1;
  
  AbyssEngine::String::String(in_r0,in_r1,false);
  return;
}

// ===== Wanted::getNumWingmen  @0x00148100  (4 bytes)
/* Wanted::getNumWingmen() */

undefined4 __thiscall Wanted::getNumWingmen(Wanted *this)

{
  return *(undefined4 *)(this + 0x38);
}

// ===== Wanted::getBoard  @0x00148104  (4 bytes)
/* Wanted::getBoard() */

undefined4 __thiscall Wanted::getBoard(Wanted *this)

{
  return *(undefined4 *)(this + 0xc);
}

// ===== Wanted::getRace  @0x00148108  (4 bytes)
/* Wanted::getRace() */

undefined4 __thiscall Wanted::getRace(Wanted *this)

{
  return *(undefined4 *)(this + 0x10);
}

// ===== Wanted::isMale  @0x0014810c  (4 bytes)
/* Wanted::isMale() */

Wanted __thiscall Wanted::isMale(Wanted *this)

{
  return this[0x14];
}

// ===== Wanted::getShip  @0x00148110  (4 bytes)
/* Wanted::getShip() */

undefined4 __thiscall Wanted::getShip(Wanted *this)

{
  return *(undefined4 *)(this + 0x18);
}

// ===== Wanted::getWeapon  @0x00148114  (4 bytes)
/* Wanted::getWeapon() */

undefined4 __thiscall Wanted::getWeapon(Wanted *this)

{
  return *(undefined4 *)(this + 0x1c);
}

// ===== Wanted::getHitpoints  @0x00148118  (4 bytes)
/* Wanted::getHitpoints() */

undefined4 __thiscall Wanted::getHitpoints(Wanted *this)

{
  return *(undefined4 *)(this + 0x20);
}

// ===== Wanted::getLoot  @0x0014811c  (4 bytes)
/* Wanted::getLoot() */

undefined4 __thiscall Wanted::getLoot(Wanted *this)

{
  return *(undefined4 *)(this + 0x24);
}

// ===== Wanted::getLootAmount  @0x00148120  (4 bytes)
/* Wanted::getLootAmount() */

undefined4 __thiscall Wanted::getLootAmount(Wanted *this)

{
  return *(undefined4 *)(this + 0x28);
}

// ===== Wanted::getReward  @0x00148124  (4 bytes)
/* Wanted::getReward() */

undefined4 __thiscall Wanted::getReward(Wanted *this)

{
  return *(undefined4 *)(this + 0x2c);
}

// ===== Wanted::getRequiredBounties  @0x00148128  (4 bytes)
/* Wanted::getRequiredBounties() */

undefined4 __thiscall Wanted::getRequiredBounties(Wanted *this)

{
  return *(undefined4 *)(this + 0x30);
}

// ===== Wanted::getRequiredMission  @0x0014812c  (4 bytes)
/* Wanted::getRequiredMission() */

undefined4 __thiscall Wanted::getRequiredMission(Wanted *this)

{
  return *(undefined4 *)(this + 0x34);
}

// ===== Wanted::setRequiredMission  @0x00148130  (4 bytes)
/* Wanted::setRequiredMission(int) */

void __thiscall Wanted::setRequiredMission(Wanted *this,int param_1)

{
  *(int *)(this + 0x34) = param_1;
  return;
}

// ===== Wanted::setImageParts  @0x00148134  (4 bytes)
/* Wanted::setImageParts(int*) */

void __thiscall Wanted::setImageParts(Wanted *this,int *param_1)

{
  *(int **)(this + 0x3c) = param_1;
  return;
}

// ===== Wanted::getImageParts  @0x00148138  (4 bytes)
/* Wanted::getImageParts() */

undefined4 __thiscall Wanted::getImageParts(Wanted *this)

{
  return *(undefined4 *)(this + 0x3c);
}

// ===== Wanted::setTerminated  @0x0014813c  (6 bytes)
/* Wanted::setTerminated(bool) */

void __thiscall Wanted::setTerminated(Wanted *this,bool param_1)

{
  this[0x4c] = (Wanted)param_1;
  return;
}

// ===== Wanted::setActive  @0x00148142  (6 bytes)
/* Wanted::setActive(bool) */

void __thiscall Wanted::setActive(Wanted *this,bool param_1)

{
  this[0x4d] = (Wanted)param_1;
  return;
}

// ===== Wanted::setTravelsTo  @0x00148148  (4 bytes)
/* Wanted::setTravelsTo(int) */

void __thiscall Wanted::setTravelsTo(Wanted *this,int param_1)

{
  *(int *)(this + 0x44) = param_1;
  return;
}

// ===== Wanted::setCurrentLocation  @0x0014814c  (4 bytes)
/* Wanted::setCurrentLocation(int) */

void __thiscall Wanted::setCurrentLocation(Wanted *this,int param_1)

{
  *(int *)(this + 0x48) = param_1;
  return;
}

// ===== Wanted::setLastSeen  @0x00148150  (4 bytes)
/* Wanted::setLastSeen(int) */

void __thiscall Wanted::setLastSeen(Wanted *this,int param_1)

{
  *(int *)(this + 0x40) = param_1;
  return;
}

// ===== Wanted::isActive  @0x00148154  (6 bytes)
/* Wanted::isActive() */

Wanted __thiscall Wanted::isActive(Wanted *this)

{
  return this[0x4d];
}

// ===== Wanted::isTerminated  @0x0014815a  (6 bytes)
/* Wanted::isTerminated() */

Wanted __thiscall Wanted::isTerminated(Wanted *this)

{
  return this[0x4c];
}

// ===== Wanted::getLastSeen  @0x00148160  (4 bytes)
/* Wanted::getLastSeen() */

undefined4 __thiscall Wanted::getLastSeen(Wanted *this)

{
  return *(undefined4 *)(this + 0x40);
}

// ===== Wanted::getTravelsTo  @0x00148164  (4 bytes)
/* Wanted::getTravelsTo() */

undefined4 __thiscall Wanted::getTravelsTo(Wanted *this)

{
  return *(undefined4 *)(this + 0x44);
}

// ===== Wanted::getCurrentLocation  @0x00148168  (4 bytes)
/* Wanted::getCurrentLocation() */

undefined4 __thiscall Wanted::getCurrentLocation(Wanted *this)

{
  return *(undefined4 *)(this + 0x48);
}

