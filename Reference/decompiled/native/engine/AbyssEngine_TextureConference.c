// Class: AbyssEngine::TextureConference
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::TextureConference::TextureConference  @0x0009790c  (110 bytes)
/* AbyssEngine::TextureConference::TextureConference() */

void __thiscall AbyssEngine::TextureConference::TextureConference(TextureConference *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_002637c8;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"TextureConference",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::TextureConference::Init  @0x000979bc  (108 bytes)
/* AbyssEngine::TextureConference::Init(AbyssEngine::Engine*) */

void AbyssEngine::TextureConference::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 a_position;   \nattribute mediump vec2 a_texCoord;   \nvarying mediump vec2 v_texCoord;     \nuniform highp mat4 u_WorldMatrix;  \nuniform highp int u_time;   \nvoid main()                  \n{                            \n\tfloat angle= (mod(u_time,360.0)*2.0); \n\tvec4 pos = a_position; \n\tpos.z  = sin( radians(pos.y+angle)); \n\tpos.z += sin( radians(pos.x/2.0+angle));\n\tpos.z *= pos.y * 0.09;\n\tgl_Position = u_WorldMatrix * pos;\t\t\n   v_texCoord = a_texCoord;  \n}                            \n"
                     ,
                     "precision lowp float;                            \nvarying mediump vec2 v_texCoord;                            \nvarying highp float v_dummy;     \nuniform sampler2D s_texture;                        \nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nvoid main()                                         \n{                                                   \n\tvec4 textureColor = texture2D( s_texture, v_texCoord );\t\n\tgl_FragColor = glColor * textureColor;\t\t\n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetUniformLocation(uVar1,"s_texture");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_time");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x30),0);
  return;
}

// ===== AbyssEngine::TextureConference::SetInActive  @0x00097a48  (22 bytes)
/* AbyssEngine::TextureConference::SetInActive() */

void __thiscall AbyssEngine::TextureConference::SetInActive(TextureConference *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  return;
}

// ===== AbyssEngine::TextureConference::UpdateMeshData  @0x00097a5e  (186 bytes)
/* AbyssEngine::TextureConference::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::TextureConference::UpdateMeshData
          (TextureConference *this,Mesh *param_1,Engine *param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  glUniformMatrix4fv(*(undefined4 *)(this + 0x28),1,0,param_2 + 0xf4);
  if (this[9] != (TextureConference)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x2c),1,param_2 + 0xc0);
    this[9] = (TextureConference)0x0;
  }
  uVar4 = ApplicationManager::GetElapsedTimeMillis(*(ApplicationManager **)(param_2 + 0x28));
  lVar5 = __aeabi_ldivmod((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),5,0);
  lVar5 = lVar5 + *(longlong *)(this + 0x38);
  uVar2 = (uint)lVar5;
  iVar3 = (int)((ulonglong)lVar5 >> 0x20);
  lVar1 = CONCAT44(iVar3 - (uint)(uVar2 < 0xe10),uVar2 - 0xe10);
  if ((int)(-(uint)(0xe10 < uVar2) - iVar3) < 0 ==
      (SBORROW4(0,iVar3) != SBORROW4(-iVar3,(uint)(0xe10 < uVar2)))) {
    lVar1 = lVar5;
  }
  *(longlong *)(this + 0x38) = lVar1;
  glUniform1i(*(undefined4 *)(this + 0x24));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
  if (((byte)*param_1 & 2) != 0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
  }
  return;
}

