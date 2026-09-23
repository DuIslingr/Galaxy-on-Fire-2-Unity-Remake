// Class: AbyssEngine::SimpleRefractionShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::SimpleRefractionShader::SimpleRefractionShader  @0x000974dc  (104 bytes)
/* AbyssEngine::SimpleRefractionShader::SimpleRefractionShader() */

void __thiscall
AbyssEngine::SimpleRefractionShader::SimpleRefractionShader(SimpleRefractionShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263790;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"SimpleRefractionShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::SimpleRefractionShader::Init  @0x00097588  (250 bytes)
/* AbyssEngine::SimpleRefractionShader::Init(AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::SimpleRefractionShader::Init(SimpleRefractionShader *this,Engine *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)this,
                     "attribute highp    vec3 a_position;\nattribute mediump  vec2 a_texCoord;\nattribute lowp\t\tvec3  \ta_normal; \t  \nattribute lowp \tvec3 \ta_tangent;\t\t  \nattribute lowp \tvec3 \ta_bitangent;\t  \nuniform highp mat4 u_ModelViewProjectionMatrix;\nvarying lowp vec3 v_eye_dir;  \nuniform highp vec3 u_eyeposmodel;  \nvarying mediump vec2 v_texCoord;\nvarying mediump vec3 v_normal;  \nvoid main()  \n{  \n\tgl_Position = u_ModelViewProjectionMatrix * vec4(a_position, 1.0);\n\tv_texCoord  = a_texCoord;\n\tv_normal\t= a_normal;\n\thighp mat3 tangentSpaceXform = mat3(a_tangent.x, a_bitangent.x, a_normal.x,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.y, a_bitangent.y, a_normal.y,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.z, a_bitangent.z, a_normal.z  \n\t\t\t\t\t\t\t\t\t\t);  \n   v_eye_dir = normalize(tangentSpaceXform*(u_eyeposmodel - a_position)); \n}\n"
                     ,
                     "precision lowp float;\nvarying mediump vec2 v_texCoord;\nvarying lowp vec3 v_eye_dir;\nuniform sampler2D  s_texture[2];\nuniform sampler2D s_texture_base;\nuniform lowp vec4  glColor; \nuniform highp float u_TexBias; \nuniform highp vec2 u_texelSize;\nuniform mediump float u_CloakRate;\nvoid main()\n{\n\tlowp vec4 colorTex   = texture2D( s_texture[0], v_texCoord, u_TexBias);\n\tlowp vec4 normalTex  = texture2D( s_texture[1], v_texCoord, u_TexBias);\n\tlowp vec3 normalTexX = colorTex.rgb * 2.0 - 1.0;\n\tfloat rim_intensity = (smoothstep(0.0, 1.0, 1.0 - dot( v_eye_dir,normalTexX )));\n\tfloat time = (u_CloakRate);\n   vec2 coord;\n   coord = (gl_FragCoord.xy + ((glColor.a*(colorTex.xy-0.5)*rim_intensity)*180.0)) * u_texelSize;\n\tgl_FragColor.rgb = texture2D(s_texture_base, coord).rgb;\n\tgl_FragColor.a = colorTex.a;\n}\n"
                    );
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_texCoord");
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_normal");
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_tangent");
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_bitangent");
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_eyeposmodel");
  *(undefined4 *)(this + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[0]");
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[1]");
  *(undefined4 *)(this + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"glColor");
  *(undefined4 *)(this + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_TexBias");
  *(undefined4 *)(this + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_texelSize");
  *(undefined4 *)(this + 0x4c) = uVar1;
  glActiveTexture(0x84c7);
  Engine::ActivateRefractFBO(param_1);
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_CloakRate");
  *(undefined4 *)(this + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture_base");
  *(undefined4 *)(this + 0x50) = uVar1;
  glUseProgram(*(undefined4 *)(this + 4));
  iVar2 = 0;
  do {
    if (-1 < *(int *)(this + iVar2 * 4 + 0x34)) {
      glUniform1i(*(int *)(this + iVar2 * 4 + 0x34),iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 2);
  glUniform1i(*(undefined4 *)(this + 0x50),7);
  return;
}

// ===== AbyssEngine::SimpleRefractionShader::SetInActive  @0x000976c4  (62 bytes)
/* AbyssEngine::SimpleRefractionShader::SetInActive() */

void __thiscall AbyssEngine::SimpleRefractionShader::SetInActive(SimpleRefractionShader *this)

{
  if (-1 < *(int *)(this + 0x1c)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x20)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x24)) {
    glDisableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x28)) {
    glDisableVertexAttribArray();
  }
  if (*(int *)(this + 0x2c) < 0) {
    return;
  }
  glDisableVertexAttribArray();
  return;
}

// ===== AbyssEngine::SimpleRefractionShader::UpdateMeshData  @0x00097702  (522 bytes)
/* AbyssEngine::SimpleRefractionShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::SimpleRefractionShader::UpdateMeshData
          (SimpleRefractionShader *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0xf4);
  }
  if (this[9] != (SimpleRefractionShader)0x0) {
    if (-1 < *(int *)(this + 0x3c)) {
      glUniform1f(*(int *)(this + 0x3c),0xc0000000);
    }
    if (-1 < *(int *)(this + 0x40)) {
      glUniform4fv(*(int *)(this + 0x40),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x44)) {
      glUniform3f(*(int *)(this + 0x44),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    uVar3 = *(undefined4 *)(this + 0x4c);
    uVar1 = Engine::GetDisplayWidth(param_2);
    fVar5 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    uVar1 = Engine::GetDisplayHeight(param_2);
    fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    glUniform2f(uVar3,1.0 / fVar5,1.0 / fVar4);
    glActiveTexture(0x84c7);
    Engine::ActivateRefractFBO(param_2);
    glUniform1f(*(undefined4 *)(this + 0x48),*(undefined4 *)(param_1 + 0x20));
    this[9] = (SimpleRefractionShader)0x0;
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
  if (-1 < *(int *)(this + 0x28)) {
    glEnableVertexAttribArray();
  }
  if (-1 < *(int *)(this + 0x2c)) {
    glEnableVertexAttribArray();
  }
  if (param_1[0x5c] == (Mesh)0x0) {
    if (-1 < *(int *)(this + 0x1c)) {
      glVertexAttribPointer(*(int *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    }
    if (-1 < *(int *)(this + 0x20)) {
      glVertexAttribPointer(*(int *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    }
    if (-1 < *(int *)(this + 0x24)) {
      glVertexAttribPointer(*(int *)(this + 0x24),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x10));
    }
    if (-1 < *(int *)(this + 0x28)) {
      glVertexAttribPointer(*(int *)(this + 0x28),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x14));
    }
    iVar2 = *(int *)(this + 0x2c);
    if (iVar2 < 0) {
      return;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x70));
    glVertexAttribPointer(*(undefined4 *)(this + 0x28),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x74));
    iVar2 = *(int *)(this + 0x2c);
    uVar1 = 0;
  }
  glVertexAttribPointer(iVar2,3,0x1406,0,0,uVar1);
  return;
}

