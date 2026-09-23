// Class: AbyssEngine::BumpRimCubeShader
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BumpRimCubeShader::BumpRimCubeShader  @0x0009a7dc  (104 bytes)
/* AbyssEngine::BumpRimCubeShader::BumpRimCubeShader() */

void __thiscall AbyssEngine::BumpRimCubeShader::BumpRimCubeShader(BumpRimCubeShader *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263a64;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BumpRimCubeShader",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BumpRimCubeShader::Init  @0x0009a888  (454 bytes)
/* AbyssEngine::BumpRimCubeShader::Init(AbyssEngine::Engine*) */

void AbyssEngine::BumpRimCubeShader::Init(Engine *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShaderBaseStruct::LoadBindShader
                    ((ShaderBaseStruct *)param_1,"data/shader/BumpRimCubeShader.vs",
                     "data/shader/BumpRimCubeShader.fs");
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    iVar1 = ShaderBaseStruct::ES2LoadProgram
                      ((ShaderBaseStruct *)param_1,
                       "attribute highp vec3 \ta_position;  \nattribute highp vec2  a_texCoord;    \nattribute highp vec3  \ta_normal; \t  \nattribute lowp \tvec3 \ta_tangent;\t\t  \nattribute lowp \tvec3 \ta_bitangent;\t  \nvarying highp vec2 v_texCoord;  \nvarying lowp vec3 v_eye_dir;  \nvarying lowp vec3 v_specular_dir[2];  \nvarying lowp vec3 v_lightvec[2];  \nvarying mediump vec3 v_reflectdir;   \nuniform highp mat4 u_ModelViewProjectionMatrix;  \nuniform highp vec3 u_lightdirmodel[2];  \nuniform highp vec3 u_eyeposmodel;  \nuniform mediump mat3 u_ModelMatrix;  \nuniform mediump mat4 u_ModelMatrixFull;  \nuniform highp float u_fogMaxDist; \nuniform highp float u_fogMinDist;\nvarying lowp float v_FogFactor;\nlowp float computeLinearFogFactor(highp float eyeDist) { \n    highp float factor; \n    // Compute linear fog equation \n    factor = (u_fogMaxDist - eyeDist) / (u_fogMaxDist - u_fogMinDist);\n    // Clamp in the [0,1] range \n    factor = (1.0 - clamp(factor, 0.0, 1.0));\n    return factor; \n}    \nvoid main()  \n{  \n\tgl_Position = u_ModelViewProjectionMatrix * vec4(a_position, 1.0);  \n\tv_texCoord  = a_texCoord;    \n\t// Calculate eye direction in model space\n\tmediump vec3 eyeDir = normalize( a_position - u_eyeposmodel);\n\t// reflect eye direction over normal and transform to world space\n\t//v_reflectdir = u_ModelMatrix * reflect(eyeDir, a_normal);\n\thighp mat3 tangentSpaceXform = mat3(a_tangent.x, a_bitangent.x, a_normal.x,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.y, a_bitangent.y, a_normal.y,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.z, a_bitangent.z, a_normal.z  \n\t\t\t\t\t\t\t\t\t\t);  \n   v_eye_dir = normalize(tangentSpaceXform*(u_eyeposmodel - a_position)); \n\tvec3 shininesDirection = normalize(normalize(u_eyeposmodel - a_position) + u_lightdirmodel[0]) ;  \n\tv_specular_dir[0] = tangentSpaceXform * shininesDirection;  \n\tv_lightvec[0] = tangentSpaceXform * u_lightdirmodel[0];  \n\tshininesDirection = normalize(normalize(u_eyeposmodel - a_position) + u_lightdirmodel[1]) ;  \n\tv_specular_dir[1] = tangentSpaceXform * shininesDirection;  \n\tv_lightvec[1] = tangentSpaceXform * u_lightdirmodel[1];  \n   highp float eyeDis..." /* TRUNCATED STRING LITERAL */
                       ,
                       "precision lowp float;  \nvarying highp vec2 v_texCoord;  \nvarying lowp vec3 v_eye_dir;  \nvarying lowp vec3 v_specular_dir[2];  \nvarying lowp vec3 v_lightvec[2];  \nuniform sampler2D  s_texture[2];  \nuniform samplerCube u_texture_cubemap;\t\t\t \nuniform lowp vec3  u_AmbientColor[2];  \nuniform lowp vec3 u_DiffuseColor[2];\nuniform lowp vec3 u_SpecularColor[2];\nuniform mediump float u_SpecularPower;\nuniform lowp vec3 u_RimColor;\nuniform mediump mat3 u_ModelMatrix;  \nuniform highp float u_TexBiasDiffuse; \nuniform highp float u_TexBiasNormal; \nuniform lowp float u_IsGlowMat;\nuniform bool u_EnableFog; \nuniform vec3 u_fogColor; \nvarying lowp float v_FogFactor;\nvoid main()  \n{  \n\tlowp vec4 colorTex   = texture2D( s_texture[0], v_texCoord, u_TexBiasDiffuse );  \n\tlowp vec4 normalTex  = texture2D( s_texture[1], v_texCoord, u_TexBiasNormal );  \n\tlowp vec3 normalTexX = normalTex.rgb*2.0 -1.0;  \n\tlowp vec4 specTex = vec4(vec3(normalTex.a), 0.0);\t \n\tfloat specularIntensity1 = pow( clamp(dot( v_specular_dir[0],normalTexX ), 0.0, 1.0), u_SpecularPower );  \n\tfloat specularIntensity2 = pow( clamp(dot( v_specular_dir[1],normalTexX ), 0.0, 1.0), u_SpecularPower );  \n\tlowp float diffuseIntensity1  = clamp( dot( normalTexX    ,v_lightvec[0] ), 0.0, 1.0 );  \n\tlowp float diffuseIntensity2  = clamp( dot( normalTexX    ,v_lightvec[1] ), 0.0, 1.0 );  \n\tfloat reflectTex = (normalTex.a*normalTex.a);\t\n\tfloat rim_intensity = (smoothstep(0.8, 1.0, 1.0 - dot( v_eye_dir,normalTexX )));\t\n\tlowp vec3 rim_effect = rim_intensity* reflectTex* u_RimColor;  \n\tfloat reflectivity = clamp(smoothstep(0.6, 1.0, 1.0 - dot( v_eye_dir,normalTexX )),reflectTex,(normalTex.a * 2.0 + rim_intensity));  \n\t//lowp vec4 combineColor = mix(textureCube(u_texture_cubemap, v_reflectdir), colorTex,  0.9 * ( 1.0 - (clamp(normalTex.a, 0.0, 0.9)))); \n\tmediump vec3 reflectDir = u_ModelMatrix * reflect(v_eye_dir, normalTexX);\n\t//gl_FragColor.rgb = (u_AmbientColor[0] + u_AmbientColor[1] + diffuseIntensity1*u_DiffuseColor[0] + diffuseIntensity2*u_DiffuseColor[1]) * combineColor.rgb  + (spe..." /* TRUNCATED STRING LITERAL */
                      );
    *(int *)(param_1 + 4) = iVar1;
  }
  uVar2 = glGetAttribLocation(iVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_tangent");
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_bitangent");
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrixFull");
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel[0]");
  *(undefined4 *)(param_1 + 0x3c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel[1]");
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[0]");
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[1]");
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_cubemap");
  *(undefined4 *)(param_1 + 0x50) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[0]");
  *(undefined4 *)(param_1 + 0x58) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[0]");
  *(undefined4 *)(param_1 + 0x60) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[0]");
  *(undefined4 *)(param_1 + 0x68) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[1]");
  *(undefined4 *)(param_1 + 0x5c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[1]");
  *(undefined4 *)(param_1 + 100) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[1]");
  *(undefined4 *)(param_1 + 0x6c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x70) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_RimColor");
  *(undefined4 *)(param_1 + 0x74) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasDiffuse");
  *(undefined4 *)(param_1 + 0x78) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasNormal");
  *(undefined4 *)(param_1 + 0x7c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_IsGlowMat");
  *(undefined4 *)(param_1 + 0x80) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_fogColor");
  *(undefined4 *)(param_1 + 0x84) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_fogMaxDist");
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_fogMinDist");
  *(undefined4 *)(param_1 + 0x8c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_EnableFog");
  *(undefined4 *)(param_1 + 0x90) = uVar2;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  iVar1 = 0;
  do {
    if (-1 < *(int *)(param_1 + iVar1 * 4 + 0x48)) {
      glUniform1i(*(int *)(param_1 + iVar1 * 4 + 0x48),iVar1);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 2);
  glUniform1i(*(undefined4 *)(param_1 + 0x50),7);
  return;
}

// ===== AbyssEngine::BumpRimCubeShader::SetInActive  @0x0009aad8  (62 bytes)
/* AbyssEngine::BumpRimCubeShader::SetInActive() */

void __thiscall AbyssEngine::BumpRimCubeShader::SetInActive(BumpRimCubeShader *this)

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

// ===== AbyssEngine::BumpRimCubeShader::UpdateMeshData  @0x0009ab18  (806 bytes)
/* AbyssEngine::BumpRimCubeShader::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BumpRimCubeShader::UpdateMeshData
          (BumpRimCubeShader *this,Mesh *param_1,Engine *param_2)

{
  float *pfVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x34)) {
    glUniformMatrix3fv(*(int *)(this + 0x34),1,0,param_2 + 500);
  }
  if (-1 < *(int *)(this + 0x38)) {
    glUniformMatrix4fv(*(int *)(this + 0x38),1,0,param_2 + 0x134);
  }
  if (-1 < *(int *)(this + 0x78)) {
    glUniform1f(*(int *)(this + 0x78),Engine::lodBiasDiffuse);
  }
  if (-1 < *(int *)(this + 0x7c)) {
    glUniform1f(*(int *)(this + 0x7c),Engine::lodBiasNormal);
  }
  if (this[9] != (BumpRimCubeShader)0x0) {
    glUniform3f(*(undefined4 *)(this + 0x3c),*(undefined4 *)(param_2 + 800),
                *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    if (-1 < *(int *)(this + 0x44)) {
      glUniform3f(*(int *)(this + 0x44),*(undefined4 *)(param_2 + 0x33c),
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
    iVar2 = *(int *)(this + 0x84);
    if (-1 < iVar2) {
      pfVar1 = AEMath::Vector::operator_cast_to_float_((Vector *)(param_2 + 0x3e0));
      glUniform3fv(iVar2,1,pfVar1);
    }
    if (-1 < *(int *)(this + 0x8c)) {
      glUniform1f(*(int *)(this + 0x8c),*(undefined4 *)(param_2 + 0x3d8));
    }
    if (-1 < *(int *)(this + 0x88)) {
      glUniform1f(*(int *)(this + 0x88),*(undefined4 *)(param_2 + 0x3dc));
    }
    if (-1 < *(int *)(this + 0x90)) {
      glUniform1i(*(int *)(this + 0x90),Engine::fogEnabled);
    }
    if (-1 < *(int *)(this + 0x80)) {
      if (*(int *)(param_1 + 0x30) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x3f800000;
        if (*(int *)(*(int *)(param_1 + 0x30) + 0x24) == 0) {
          uVar3 = 0;
        }
      }
      glUniform1f(*(int *)(this + 0x80),uVar3);
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
    glUniform3f(*(undefined4 *)(this + 0x40),*(undefined4 *)(param_2 + 0x32c),
                *(undefined4 *)(param_2 + 0x330),*(undefined4 *)(param_2 + 0x334));
    this[9] = (BumpRimCubeShader)0x0;
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
    uVar3 = *(undefined4 *)(param_1 + 0x18);
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
    uVar3 = 0;
  }
  glVertexAttribPointer(iVar2,3,0x1406,0,0,uVar3);
  return;
}

