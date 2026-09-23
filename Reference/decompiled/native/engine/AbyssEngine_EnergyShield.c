// Class: AbyssEngine::EnergyShield
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::EnergyShield::EnergyShield  @0x000950f0  (104 bytes)
/* AbyssEngine::EnergyShield::EnergyShield() */

void __thiscall AbyssEngine::EnergyShield::EnergyShield(EnergyShield *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_002635d0;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"EnergyShield",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::EnergyShield::Init  @0x0009519c  (250 bytes)
/* AbyssEngine::EnergyShield::Init(AbyssEngine::Engine*) */

void __thiscall AbyssEngine::EnergyShield::Init(EnergyShield *this,Engine *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)this,
                     "attribute highp    vec3 a_position;\nattribute mediump  vec2 a_texCoord;\nattribute highp    vec3 a_normal;\nvarying mediump vec2 v_texCoord;  \nvarying lowp vec3 v_eye_dir;  \nvarying mediump vec3 v_normal;  \nvarying mediump vec3 v_normalView;  \nuniform highp mat4 u_ModelViewProjectionMatrix;\nuniform highp vec3 u_lightdirmodel[2];\nuniform highp vec3 u_eyeposmodel;\nuniform mediump mat4 u_ModelViewMatrix;\nvoid main()  \n{  \n\thighp vec3 vertex = a_position;\n\tgl_Position = u_ModelViewProjectionMatrix * vec4(vertex, 1.0);\n\tv_texCoord  = a_texCoord;\n\tv_normalView = normalize((u_ModelViewProjectionMatrix * vec4(a_normal, 0.0)).xyz);\n\tv_normal = a_normal;\n   v_eye_dir = normalize((u_ModelViewProjectionMatrix * vec4(u_eyeposmodel - a_position, 0.0)).rgb); \n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nvarying lowp vec3 v_eye_dir;\nvarying mediump vec3 v_normal;  \nvarying mediump vec3 v_normalView;  \nuniform sampler2D   s_texture[2];\nuniform sampler2D   s_texture_base;\nuniform highp vec2 u_texelSize;\nvoid main()\n{\n\tmediump vec4 normalTex  = texture2D( s_texture[1], v_texCoord);\n\tmediump vec3 normalTexX = normalTex.rgb*2.0 -1.0;\n\tfloat rim_intensity = (smoothstep(0.0, 1.0, 1.0 - dot( v_eye_dir,v_normalView )));\n\tlowp vec3 rim_effect = smoothstep(0.0, 1.0, 1.0 - dot( v_eye_dir,v_normalView * normalTexX)) * vec3(0.0, 0.6, 1.0);\n   mediump vec2 coord;\n   coord = (gl_FragCoord.xy + ((normalTexX.xy * 0.4 + v_normalView.xy*rim_intensity)*150.0)) * u_texelSize;\n\tgl_FragColor.rgb = texture2D(s_texture_base, coord).rgb + rim_effect;\n}\n"
                    );
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_texCoord");
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_normal");
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_ModelViewMatrix");
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_eyeposmodel");
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[0]");
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[1]");
  *(undefined4 *)(this + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"glColor");
  *(undefined4 *)(this + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_RimColor");
  *(undefined4 *)(this + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_texelSize");
  *(undefined4 *)(this + 0x54) = uVar1;
  glActiveTexture(0x84c7);
  Engine::ActivateRefractFBO(param_1);
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_vertTime");
  *(undefined4 *)(this + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_time");
  *(undefined4 *)(this + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture_base");
  *(undefined4 *)(this + 0x58) = uVar1;
  glUseProgram(*(undefined4 *)(this + 4));
  iVar2 = 0;
  do {
    if (-1 < *(int *)(this + iVar2 * 4 + 0x34)) {
      glUniform1i(*(int *)(this + iVar2 * 4 + 0x34),iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 2);
  glUniform1i(*(undefined4 *)(this + 0x58),7);
  return;
}

// ===== AbyssEngine::EnergyShield::SetInActive  @0x000952d8  (42 bytes)
/* AbyssEngine::EnergyShield::SetInActive() */

void __thiscall AbyssEngine::EnergyShield::SetInActive(EnergyShield *this)

{
  if (-1 < *(int *)(this + 0x1c)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glDisableVertexAttribArray();
  }
  if (*(int *)(this + 0x24) < 0) {
    return;
  }
  glDisableVertexAttribArray();
  return;
}

// ===== AbyssEngine::EnergyShield::UpdateMeshData  @0x00095302  (430 bytes)
/* AbyssEngine::EnergyShield::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::EnergyShield::UpdateMeshData(EnergyShield *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  
  if (-1 < *(int *)(this + 0x28)) {
    glUniformMatrix4fv(*(int *)(this + 0x28),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x2c)) {
    glUniformMatrix4fv(*(int *)(this + 0x2c),1,0,param_2 + 0x174);
  }
  if (this[9] != (EnergyShield)0x0) {
    if (-1 < *(int *)(this + 0x30)) {
      glUniform3f(*(int *)(this + 0x30),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    if (-1 < *(int *)(this + 0x40)) {
      glUniform4fv(*(int *)(this + 0x40),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x44)) {
      glUniform3fv(*(int *)(this + 0x44),1,param_2 + 0x310);
    }
    iVar2 = *(int *)(this + 0x54);
    if (-1 < iVar2) {
      uVar1 = Engine::GetDisplayWidth(param_2);
      fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      uVar1 = Engine::GetDisplayHeight(param_2);
      fVar3 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      glUniform2f(iVar2,1.0 / fVar4,1.0 / fVar3);
    }
    glActiveTexture(0x84c7);
    Engine::ActivateRefractFBO(param_2);
    glUniform1f(*(undefined4 *)(this + 0x4c),*(undefined4 *)(param_1 + 0x24));
    glUniform1f(*(undefined4 *)(this + 0x50),*(float *)(param_1 + 0x24) / 3.0);
    this[9] = (EnergyShield)0x0;
  }
  if (-1 < *(int *)(this + 0x1c)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x24)) {
    glEnableVertexAttribArray();
  }
  if (param_1[0x5c] == (Mesh)0x0) {
    if (-1 < *(int *)(this + 0x1c)) {
      glVertexAttribPointer(*(int *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    }
    if (-1 < *(int *)(this + 0x20)) {
      glVertexAttribPointer(*(int *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    }
    iVar2 = *(int *)(this + 0x24);
    if (iVar2 < 0) {
      return;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    iVar2 = *(int *)(this + 0x24);
    uVar1 = 0;
  }
  glVertexAttribPointer(iVar2,3,0x1406,0,0,uVar1);
  return;
}

