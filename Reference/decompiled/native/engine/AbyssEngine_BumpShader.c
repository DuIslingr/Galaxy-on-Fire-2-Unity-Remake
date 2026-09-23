// Class: AbyssEngine::BumpShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BumpShader::BumpShader  @0x00096690  (104 bytes)
/* AbyssEngine::BumpShader::BumpShader() */

void __thiscall AbyssEngine::BumpShader::BumpShader(BumpShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_002636e8;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BumpShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BumpShader::Init  @0x0009673c  (344 bytes)
/* AbyssEngine::BumpShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::BumpShader::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec3 \ta_position;  \nattribute highp vec2  a_texCoord;    \nattribute highp vec3  \ta_normal; \t  \nvarying highp vec2 v_texCoord;  \nvarying highp vec3 v_normal;   \nuniform highp mat4 u_ModelViewProjectionMatrix;  \nuniform mediump mat3 u_ModelMatrix;  \nuniform highp float u_fogMaxDist; \nuniform highp float u_fogMinDist;\nuniform highp vec3 u_eyeposmodel;  \nvarying lowp float v_FogFactor;\nvarying vec3 DiffuseColor; \nconst float C1 = 0.429043;\nconst float C2 = 0.511664;\nconst float C3 = 0.743125;\nconst float C4 = 0.886227;\nconst float C5 = 0.247708;\nconst vec3 L00  = vec3( 0.871297, 0.875222, 0.864470 );\nconst vec3 L1m1 = vec3( 0.175058, 0.245335, 0.312891 );\nconst vec3 L10  = vec3( 0.034675, 0.036107, 0.037362 );\nconst vec3 L11  = vec3(-0.004629,-0.029448,-0.048028 );\nconst vec3 L2m2 = vec3(-0.120535,-0.121160,-0.117507 );\nconst vec3 L2m1 = vec3( 0.003242, 0.003624, 0.007511 );\nconst vec3 L20  = vec3(-0.028667,-0.024926,-0.020998 );\nconst vec3 L21  = vec3(-0.077539,-0.086325,-0.091591 );\nconst vec3 L22  = vec3(-0.161784,-0.191783,-0.219152 );\nlowp float computeLinearFogFactor(highp float eyeDist) { \n    highp float factor; \n    // Compute linear fog equation \n    factor = (u_fogMaxDist - eyeDist) / (u_fogMaxDist - u_fogMinDist);\n    // Clamp in the [0,1] range \n    factor = (1.0 - clamp(factor, 0.0, 1.0));\n    return factor; \n}    \nvoid main()  \n{  \n\tgl_Position = u_ModelViewProjectionMatrix * vec4(a_position, 1.0);  \n\tv_texCoord  = a_texCoord;    \n   highp float eyeDist = distance(u_eyeposmodel, a_position); \n   v_FogFactor = computeLinearFogFactor(eyeDist); \n   vec3 tnorm = normalize(u_ModelMatrix*a_normal);\n   DiffuseColor = C1 * L22 * (tnorm.x * tnorm.x - tnorm.y * tnorm.y) + \n                  C3 * L20 * tnorm.z * tnorm.z +\n                  C4 * L00 - \n                  C5 * L20 + \n                  2.0 * C1 * L2m2 * tnorm.x * tnorm.y +\n                  2.0 * C1 * L21  * tnorm.x * tnorm.z +\n                  2.0 * C1 * L2m1 * tnorm.y * tnorm.z +\n                  2.0 * C2 * L11  * tnorm.x +\n      ..." /* TRUNCATED STRING LITERAL */
                     ,
                     "precision lowp float;  \nvarying highp vec2 v_texCoord;  \nvarying highp vec3 v_normal;   \nvarying vec3 DiffuseColor; \nuniform sampler2D  s_texture;  \nuniform lowp vec3  u_AmbientColor[2];  \nuniform lowp vec3 u_DiffuseColor[2];\nuniform lowp vec3 u_SpecularColor[2];\nuniform mediump float u_SpecularPower;\nuniform highp float u_TexBiasDiffuse; \nuniform highp float u_TexBiasNormal; \nuniform highp vec3 u_lightdirmodel[2];  \nuniform highp vec3 u_eyeposmodel;  \nuniform bool u_EnableFog; \nuniform vec3 u_fogColor; \nvarying lowp float v_FogFactor;\nfloat specularIntensity1; \nfloat specularIntensity2; \nlowp float diffuseIntensity1; \nlowp float diffuseIntensity2; \nvec3 outColor; \nlowp vec4 colorTex;\nlowp vec4 normalTex;\nhighp vec3 reflection;\nvoid main()  \n{  \n\tcolorTex   = texture2D( s_texture, v_texCoord, u_TexBiasDiffuse );  \n\tdiffuseIntensity1 = clamp(dot(v_normal, u_lightdirmodel[0]), 0.0, 1.0);\n   reflection = normalize(-reflect(u_lightdirmodel[0], v_normal)); \n\tspecularIntensity1 = pow( clamp(dot(reflection, normalize(u_eyeposmodel)), 0.0, 1.0), u_SpecularPower );  \n\tdiffuseIntensity2 = clamp(dot(v_normal, u_lightdirmodel[1]), 0.0, 1.0);\n   reflection = normalize(-reflect(u_lightdirmodel[1], v_normal)); \n\tspecularIntensity2 = pow( clamp(dot(reflection, normalize(u_eyeposmodel)), 0.0, 1.0), u_SpecularPower );  \n   outColor = (u_AmbientColor[0] + u_AmbientColor[1] + diffuseIntensity1*u_DiffuseColor[0] + diffuseIntensity2*u_DiffuseColor[1])* colorTex.rgb  + (specularIntensity1 * u_SpecularColor[0] + specularIntensity2 * u_SpecularColor[1])*0.2;  \n   //outColor = (u_AmbientColor[0] + u_AmbientColor[1] + diffuseIntensity1*u_DiffuseColor[0] + diffuseIntensity2*u_DiffuseColor[1])* colorTex.rgb; \n   if ( u_EnableFog ) { \n       gl_FragColor.rgb = mix(outColor, u_fogColor, v_FogFactor); \n       gl_FragColor.a = colorTex.a;\n   } else { \n       gl_FragColor.rgb = outColor; \n       gl_FragColor.a = colorTex.a;\n   } \n}  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel[0]");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel[1]");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_cubemap");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[0]");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[0]");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[0]");
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[1]");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[1]");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[1]");
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_RimColor");
  *(undefined4 *)(param_1 + 100) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasDiffuse");
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasNormal");
  *(undefined4 *)(param_1 + 0x6c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_fogColor");
  *(undefined4 *)(param_1 + 0x70) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_fogMaxDist");
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_fogMinDist");
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_EnableFog");
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x3c),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x40),7);
  return;
}

// ===== AbyssEngine::BumpShader::SetInActive  @0x00096900  (42 bytes)
/* AbyssEngine::BumpShader::SetInActive() */

void __thiscall AbyssEngine::BumpShader::SetInActive(BumpShader *this)

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

// ===== AbyssEngine::BumpShader::UpdateMeshData  @0x0009692c  (596 bytes)
/* AbyssEngine::BumpShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BumpShader::UpdateMeshData(BumpShader *this,Mesh *param_1,Engine *param_2)

{
  float *pfVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (-1 < *(int *)(this + 0x28)) {
    glUniformMatrix4fv(*(int *)(this + 0x28),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x2c)) {
    glUniformMatrix3fv(*(int *)(this + 0x2c),1,0,param_2 + 500);
  }
  if (-1 < *(int *)(this + 0x68)) {
    glUniform1f(*(int *)(this + 0x68),Engine::lodBiasDiffuse);
  }
  if (-1 < *(int *)(this + 0x6c)) {
    glUniform1f(*(int *)(this + 0x6c),Engine::lodBiasNormal);
  }
  if (this[9] != (BumpShader)0x0) {
    glUniform3f(*(undefined4 *)(this + 0x30),*(undefined4 *)(param_2 + 800),
                *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    if (-1 < *(int *)(this + 0x38)) {
      glUniform3f(*(int *)(this + 0x38),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    if (-1 < *(int *)(this + 0x44)) {
      glUniform4fv(*(int *)(this + 0x44),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x48)) {
      glUniform3fv(*(int *)(this + 0x48),1,param_2 + 700);
    }
    if (-1 < *(int *)(this + 0x50)) {
      glUniform3fv(*(int *)(this + 0x50),1,param_2 + 0x2ec);
    }
    if (-1 < *(int *)(this + 0x58)) {
      glUniform3fv(*(int *)(this + 0x58),1,param_2 + 0x2d4);
    }
    if (-1 < *(int *)(this + 0x60)) {
      glUniform1f(*(int *)(this + 0x60),*(undefined4 *)(param_2 + 0x2b8));
    }
    if (-1 < *(int *)(this + 100)) {
      glUniform3fv(*(int *)(this + 100),1,param_2 + 0x310);
    }
    iVar2 = *(int *)(this + 0x70);
    if (-1 < iVar2) {
      pfVar1 = AEMath::Vector::operator_cast_to_float_((Vector *)(param_2 + 0x3e0));
      glUniform3fv(iVar2,1,pfVar1);
    }
    if (-1 < *(int *)(this + 0x78)) {
      glUniform1f(*(int *)(this + 0x78),*(undefined4 *)(param_2 + 0x3d8));
    }
    if (-1 < *(int *)(this + 0x74)) {
      glUniform1f(*(int *)(this + 0x74),*(undefined4 *)(param_2 + 0x3dc));
    }
    if (-1 < *(int *)(this + 0x7c)) {
      glUniform1i(*(int *)(this + 0x7c),Engine::fogEnabled);
    }
    if (*(int *)(param_2 + 0x31c) < 2) {
      glUniform3f(*(undefined4 *)(this + 0x4c),0,0,0);
      glUniform3f(*(undefined4 *)(this + 0x54),0,0,0);
      glUniform3f(*(undefined4 *)(this + 0x5c),0,0,0);
    }
    else {
      glUniform3fv(*(undefined4 *)(this + 0x4c),1,param_2 + 0x2c8);
      glUniform3fv(*(undefined4 *)(this + 0x54),1,param_2 + 0x2f8);
      glUniform3fv(*(undefined4 *)(this + 0x5c),1,param_2 + 0x2e0);
    }
    glUniform3f(*(undefined4 *)(this + 0x34),*(undefined4 *)(param_2 + 0x32c),
                *(undefined4 *)(param_2 + 0x330),*(undefined4 *)(param_2 + 0x334));
    this[9] = (BumpShader)0x0;
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
    uVar3 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    iVar2 = *(int *)(this + 0x24);
    uVar3 = 0;
  }
  glVertexAttribPointer(iVar2,3,0x1406,0,0,uVar3);
  return;
}

