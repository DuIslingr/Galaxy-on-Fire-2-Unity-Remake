// Class: AbyssEngine::BumpShaderCloak
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BumpShaderCloak::BumpShaderCloak  @0x00095ae8  (104 bytes)
/* AbyssEngine::BumpShaderCloak::BumpShaderCloak() */

void __thiscall AbyssEngine::BumpShaderCloak::BumpShaderCloak(BumpShaderCloak *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263640;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BumpShaderCloak",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BumpShaderCloak::Init  @0x00095b94  (396 bytes)
/* AbyssEngine::BumpShaderCloak::Init(AbyssEngine::Engine*) */

void __thiscall AbyssEngine::BumpShaderCloak::Init(BumpShaderCloak *this,Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)this,
                     "attribute highp vec3 a_position;\nattribute mediump vec2 a_texCoord;\nattribute highp vec3 a_normal;\nattribute lowp vec3 a_tangent;\nattribute lowp vec3 a_bitangent;\nvarying mediump vec2 v_texCoord;  \nvarying lowp vec3 v_eye_dir;  \nvarying lowp vec3 v_specular_dir[2];\nvarying lowp vec3 v_lightvec[2];\nuniform highp mat4 u_ModelViewProjectionMatrix;\nuniform highp vec3 u_lightdirmodel[2];\nuniform highp vec3 u_eyeposmodel;\nuniform mediump mat3 u_ModelMatrix;\nvoid main()  \n{  \n\thighp vec3 vertex = a_position;\n\tgl_Position = u_ModelViewProjectionMatrix * vec4(vertex, 1.0);\n\tv_texCoord  = a_texCoord;    \n\t// Calculate eye direction in model space\n\tmediump vec3 eyeDir = normalize( a_position - u_eyeposmodel);\n\t// reflect eye direction over normal and transform to world space\n\t//v_reflectdir = u_ModelMatrix * reflect(eyeDir, a_normal);\n\thighp mat3 tangentSpaceXform = mat3(a_tangent.x, a_bitangent.x, a_normal.x,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.y, a_bitangent.y, a_normal.y,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.z, a_bitangent.z, a_normal.z  \n\t\t\t\t\t\t\t\t\t\t);  \n   v_eye_dir = normalize(tangentSpaceXform*(u_eyeposmodel - a_position)); \n\tvec3 shininesDirection = normalize(normalize(u_eyeposmodel - a_position) + u_lightdirmodel[0]) ;  \n\tv_specular_dir[0] = tangentSpaceXform * shininesDirection;  \n\tv_lightvec[0] = tangentSpaceXform * u_lightdirmodel[0];  \n\tshininesDirection = normalize(normalize(u_eyeposmodel - a_position) + u_lightdirmodel[1]) ;  \n\tv_specular_dir[1] = tangentSpaceXform * shininesDirection;  \n\tv_lightvec[1] = tangentSpaceXform * u_lightdirmodel[1];  \n}\n"
                     ,
                     "precision lowp float;  \nvarying mediump vec2 v_texCoord;\nvarying lowp vec3 v_eye_dir;\nvarying lowp vec3 v_specular_dir[2];\nvarying lowp vec3 v_lightvec[2];\nuniform sampler2D  s_texture[3];\nuniform lowp vec3 u_AmbientColor[2];\nuniform lowp vec3 u_DiffuseColor[2];\nuniform lowp vec3 u_SpecularColor[2];\nuniform mediump float u_SpecularPower;\nuniform lowp vec3 u_RimColor;\nuniform mediump vec2 u_texelSize;\nuniform mediump float u_AnimValue;\nuniform highp float u_CloakRate;\nuniform sampler2D s_texture_base;\nuniform highp mat3 u_ModelMatrix;\nvoid main()\n{\n\tlowp vec4 colorTex   = texture2D( s_texture[0], v_texCoord);\n\tmediump vec4 normalTex  = texture2D( s_texture[1], v_texCoord);\n\tmediump vec4 cloakTex   = texture2D( s_texture[2], v_texCoord);\n\tmediump vec3 normalTexX = normalTex.rgb * 2.0 - 1.0;\n\tlowp vec4 specTex = vec4(vec3(normalTex.a), 0.0);\t \n\tfloat specularIntensity1 = pow( clamp(dot( v_specular_dir[0],normalTexX ), 0.0, 1.0), u_SpecularPower );  \n\tfloat specularIntensity2 = pow( clamp(dot( v_specular_dir[1],normalTexX ), 0.0, 1.0), u_SpecularPower );  \n\tlowp float diffuseIntensity1  = clamp( dot( normalTexX ,v_lightvec[0] ), 0.0, 1.0 );\n\tlowp float diffuseIntensity2  = clamp( dot( normalTexX ,v_lightvec[1] ), 0.0, 1.0 );\n\tfloat reflectTex = (normalTex.a*normalTex.a);\t\n\tfloat rim_intensity = (smoothstep(0.8, 1.0, 1.0 - dot( v_eye_dir,normalTexX )));\n\tlowp vec3 rim_effect = rim_intensity* reflectTex* u_RimColor;  \n\tmediump vec3 color;\n\t{\n\t\tcolor = (u_AmbientColor[0] + u_AmbientColor[1] + diffuseIntensity1*u_DiffuseColor[0] + diffuseIntensity2 * u_DiffuseColor[1]) * colorTex.rgb + (specularIntensity1 * u_SpecularColor[0] + specularIntensity2 * u_SpecularColor[1]) * specTex.rgb + rim_effect;\n   }\n   mediump vec2 coord;\n   coord.x = (gl_FragCoord.x + (normalTexX.x*100.0*(sin(u_CloakRate)))) * u_texelSize.x;\n   coord.y = (gl_FragCoord.y + (normalTexX.y*75.0 *(cos(u_CloakRate)))) * u_texelSize.y;\n\thighp vec3 color2 = color;\n\tif (cloakTex.r - 0.025 < u_AnimValue) {\n\t\tcolor2 = texture2D(s_texture_base, coord).rgb + vec3(0..." /* TRUNCATED STRING LITERAL */
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
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_ModelMatrix");
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_lightdirmodel[0]");
  *(undefined4 *)(this + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_lightdirmodel[1]");
  *(undefined4 *)(this + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_eyeposmodel");
  *(undefined4 *)(this + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[0]");
  *(undefined4 *)(this + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[1]");
  *(undefined4 *)(this + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[2]");
  *(undefined4 *)(this + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"glColor");
  *(undefined4 *)(this + 0x54) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_AmbientColor[0]");
  *(undefined4 *)(this + 0x58) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_DiffuseColor[0]");
  *(undefined4 *)(this + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_SpecularColor[0]");
  *(undefined4 *)(this + 0x68) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_AmbientColor[1]");
  *(undefined4 *)(this + 0x5c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_DiffuseColor[1]");
  *(undefined4 *)(this + 100) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_SpecularColor[1]");
  *(undefined4 *)(this + 0x6c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_SpecularPower");
  *(undefined4 *)(this + 0x70) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_RimColor");
  *(undefined4 *)(this + 0x74) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_texelSize");
  *(undefined4 *)(this + 0x88) = uVar1;
  glActiveTexture(0x84c7);
  Engine::ActivateRefractFBO(param_1);
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_AnimValue");
  *(undefined4 *)(this + 0x7c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_CloakRate");
  *(undefined4 *)(this + 0x80) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture_base");
  *(undefined4 *)(this + 0x8c) = uVar1;
  glUseProgram(*(undefined4 *)(this + 4));
  glUniform1i(*(undefined4 *)(this + 0x44),0);
  glUniform1i(*(undefined4 *)(this + 0x48),1);
  glUniform1i(*(undefined4 *)(this + 0x4c),6);
  glUniform1i(*(undefined4 *)(this + 0x8c),7);
  return;
}

// ===== AbyssEngine::BumpShaderCloak::SetInActive  @0x00095d90  (62 bytes)
/* AbyssEngine::BumpShaderCloak::SetInActive() */

void __thiscall AbyssEngine::BumpShaderCloak::SetInActive(BumpShaderCloak *this)

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

// ===== AbyssEngine::BumpShaderCloak::UpdateMeshData  @0x00095dce  (778 bytes)
/* AbyssEngine::BumpShaderCloak::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BumpShaderCloak::UpdateMeshData(BumpShaderCloak *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x34)) {
    glUniformMatrix3fv(*(int *)(this + 0x34),1,0,param_2 + 500);
  }
  if (this[9] != (BumpShaderCloak)0x0) {
    glUniform3f(*(undefined4 *)(this + 0x38),*(undefined4 *)(param_2 + 800),
                *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    if (-1 < *(int *)(this + 0x40)) {
      glUniform3f(*(int *)(this + 0x40),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    if (-1 < *(int *)(this + 0x54)) {
      glUniform4fv(*(int *)(this + 0x54),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x58)) {
      glUniform3fv(*(int *)(this + 0x58),1,param_2 + 700);
    }
    if (-1 < *(int *)(this + 0x60)) {
      glUniform3fv(*(int *)(this + 0x60),1,param_2 + 0x2ec);
    }
    if (-1 < *(int *)(this + 0x68)) {
      glUniform3fv(*(int *)(this + 0x68),1,param_2 + 0x2d4);
    }
    if (-1 < *(int *)(this + 0x70)) {
      glUniform1f(*(int *)(this + 0x70),*(undefined4 *)(param_2 + 0x2b8));
    }
    if (-1 < *(int *)(this + 0x74)) {
      glUniform3fv(*(int *)(this + 0x74),1,param_2 + 0x310);
    }
    iVar2 = *(int *)(this + 0x88);
    if (-1 < iVar2) {
      if (*(int *)(**(int **)(param_2 + 0x28) + 0x30) == 2) {
        uVar1 = Engine::GetDisplayWidth(param_2);
        fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
        uVar1 = Engine::GetDisplayHeight(param_2);
      }
      else {
        uVar1 = Engine::GetDisplayHeight(param_2);
        fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
        uVar1 = Engine::GetDisplayWidth(param_2);
      }
      fVar3 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      glUniform2f(iVar2,1.0 / fVar4,1.0 / fVar3);
    }
    glActiveTexture(0x84c7);
    Engine::ActivateRefractFBO(param_2);
    if (-1 < *(int *)(this + 0x7c)) {
      glUniform1f(*(int *)(this + 0x7c),*(undefined4 *)(param_1 + 0x1c));
    }
    if (-1 < *(int *)(this + 0x80)) {
      glUniform1f(*(int *)(this + 0x80),*(undefined4 *)(param_1 + 0x20));
    }
    if (*(int *)(param_2 + 0x31c) < 2) {
      glUniform3f(*(undefined4 *)(this + 0x5c),0,0,0);
      glUniform3f(*(undefined4 *)(this + 100),0,0,0);
      glUniform3f(*(undefined4 *)(this + 0x6c),0,0,0);
    }
    else {
      glUniform3fv(*(undefined4 *)(this + 0x5c),1,param_2 + 0x2c8);
      glUniform3fv(*(undefined4 *)(this + 100),1,param_2 + 0x2f8);
      glUniform3fv(*(undefined4 *)(this + 0x6c),1,param_2 + 0x2e0);
    }
    glUniform3f(*(undefined4 *)(this + 0x3c),*(undefined4 *)(param_2 + 0x32c),
                *(undefined4 *)(param_2 + 0x330),*(undefined4 *)(param_2 + 0x334));
    this[9] = (BumpShaderCloak)0x0;
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

