// Class: AbyssEngine::BumpShaderV3
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BumpShaderV3::BumpShaderV3  @0x00096f70  (104 bytes)
/* AbyssEngine::BumpShaderV3::BumpShaderV3() */

void __thiscall AbyssEngine::BumpShaderV3::BumpShaderV3(BumpShaderV3 *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263758;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BumpShaderV3",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BumpShaderV3::Init  @0x0009701c  (356 bytes)
/* AbyssEngine::BumpShaderV3::Init(AbyssEngine::Engine*) */

void AbyssEngine::BumpShaderV3::Init(Engine *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp vec4 \ta_position;  \nattribute mediump vec2  a_texCoord;    \nattribute highp vec3  \ta_normal; \t  \nattribute lowp \tvec3 \ta_tangent;\t\t  \nattribute lowp \tvec3 \ta_bitangent;\t  \nvarying mediump vec2 v_texCoord;  \nvarying lowp vec3 v_eye_dir;  \nvarying mediump vec3 v_normal;  \nvarying lowp vec3 v_specular_dir[2];  \nvarying lowp vec3 v_lightvec[2];  \nuniform highp mat4 u_ModelViewProjectionMatrix;  \nuniform highp vec3 u_lightdirmodel[2];  \nuniform highp vec3 u_eyeposmodel;  \nvoid main()  \n{  \n\tgl_Position = u_ModelViewProjectionMatrix * a_position;  \n\tv_texCoord  = a_texCoord;    \n\tv_normal \t= a_normal;  \n\thighp mat3 tangentSpaceXform = mat3(a_tangent.x, a_bitangent.x, a_normal.x,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.y, a_bitangent.y, a_normal.y,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.z, a_bitangent.z, a_normal.z  \n\t\t\t\t\t\t\t\t\t\t);  \n   v_eye_dir = normalize(tangentSpaceXform*(u_eyeposmodel - a_position.xyz)); \n\tvec3 shininesDirection = normalize(normalize(u_eyeposmodel - a_position.xyz) + u_lightdirmodel[0]) ;  \n\tv_specular_dir[0] = tangentSpaceXform * shininesDirection;  \n\tv_lightvec[0] = tangentSpaceXform * u_lightdirmodel[0];  \n\tshininesDirection = normalize(normalize(u_eyeposmodel - a_position.xyz) + u_lightdirmodel[1]) ;  \n\tv_specular_dir[1] = tangentSpaceXform * shininesDirection;  \n\tv_lightvec[1] = tangentSpaceXform * u_lightdirmodel[1];  \n}  \n"
                     ,
                     "precision lowp float;  \nvarying mediump vec2 v_texCoord;  \nvarying lowp vec3 v_eye_dir;  \nvarying mediump vec3 v_normal;  \nvarying lowp vec3 v_specular_dir[2];  \nvarying lowp vec3 v_lightvec[2];  \nuniform sampler2D  s_texture[3];  \nuniform lowp vec3  u_AmbientColor[2];  \nuniform lowp vec3 u_DiffuseColor[2];\nuniform lowp vec3 u_SpecularColor[2];\nuniform mediump float u_SpecularPower;\nuniform lowp vec3 u_RimColor;\nuniform highp float u_TexBiasDiffuse; \nuniform highp float u_TexBiasNormal; \nuniform lowp float u_IsGlowMat;\nvoid main()  \n{  \n\tlowp vec4 colorTex   = texture2D( s_texture[0], v_texCoord, u_TexBiasDiffuse );  \n\tlowp vec4 normalTex  = texture2D( s_texture[1], v_texCoord, u_TexBiasNormal );  \n\tlowp vec3 normalTexX = normalTex.rgb*2.0 -1.0;  \n\tlowp vec4 specTex = vec4(vec3(normalTex.a), 0.0);\t \n\tfloat specularIntensity1 = pow( clamp(dot( v_specular_dir[0],normalTexX ), 0.0, 1.0), u_SpecularPower );  \n\tfloat specularIntensity2 = pow( clamp(dot( v_specular_dir[1],normalTexX ), 0.0, 1.0), u_SpecularPower );  \n\t//lowp vec4 specular1 = texture2D( s_texture[2], vec2(abs(dot( v_specular_dir[0],normalTexX )),normalTex.a) );  \n\tlowp float diffuseIntensity1  = clamp( dot( normalTexX    ,v_lightvec[0] ), 0.0, 1.0 );  \n\t//lowp vec4 specular2 = texture2D( s_texture[2], vec2(abs(dot( v_specular_dir[1],normalTexX )),normalTex.a) );  \n\tlowp float diffuseIntensity2  = clamp( dot( normalTexX    ,v_lightvec[1] ), 0.0, 1.0 );  \n\t//lowp vec3 rim_effect = (smoothstep(0.7, 1.0, 1.0 - dot( v_eye_dir,normalTexX )))* normalTex.a* u_RimColor;  \n   if ( (u_IsGlowMat + colorTex.a) > 1.1) {\n       gl_FragColor.rgb = colorTex.rgb;\t\n\t} else {\t\n\t\tgl_FragColor.rgb = (u_AmbientColor[0] + u_AmbientColor[1] + diffuseIntensity1*u_DiffuseColor[0] + diffuseIntensity2*u_DiffuseColor[1]) * colorTex.rgb  + (specularIntensity1 * u_SpecularColor[0] + specularIntensity2 * u_SpecularColor[1]) * specTex.rgb;  \n\t\tgl_FragColor.a = colorTex.a; \n\t\t//gl_FragColor.rgb = vec3( -0.5 * u_TexBias, 0.0, 0.0); \n}  \n}  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_tangent");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_bitangent");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel[0]");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightdirmodel[1]");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[0]");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[1]");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"s_texture[2]");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"glColor");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[0]");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[0]");
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[0]");
  *(undefined4 *)(param_1 + 100) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor[1]");
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor[1]");
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor[1]");
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x6c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_RimColor");
  *(undefined4 *)(param_1 + 0x70) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasDiffuse");
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_TexBiasNormal");
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_IsGlowMat");
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  iVar2 = 0;
  do {
    if (-1 < *(int *)(param_1 + iVar2 * 4 + 0x44)) {
      glUniform1i(*(int *)(param_1 + iVar2 * 4 + 0x44),iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 3);
  return;
}

// ===== AbyssEngine::BumpShaderV3::SetInActive  @0x000971ec  (62 bytes)
/* AbyssEngine::BumpShaderV3::SetInActive() */

void __thiscall AbyssEngine::BumpShaderV3::SetInActive(BumpShaderV3 *this)

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

// ===== AbyssEngine::BumpShaderV3::UpdateMeshData  @0x0009722c  (674 bytes)
/* AbyssEngine::BumpShaderV3::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BumpShaderV3::UpdateMeshData(BumpShaderV3 *this,Mesh *param_1,Engine *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (-1 < *(int *)(this + 0x30)) {
    glUniformMatrix4fv(*(int *)(this + 0x30),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x34)) {
    glUniformMatrix3fv(*(int *)(this + 0x34),1,0,param_2 + 500);
  }
  if (-1 < *(int *)(this + 0x74)) {
    glUniform1f(*(int *)(this + 0x74),Engine::lodBiasDiffuse);
  }
  if (-1 < *(int *)(this + 0x78)) {
    glUniform1f(*(int *)(this + 0x78),Engine::lodBiasNormal);
  }
  if (this[9] != (BumpShaderV3)0x0) {
    glUniform3f(*(undefined4 *)(this + 0x38),*(undefined4 *)(param_2 + 800),
                *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
    if (-1 < *(int *)(this + 0x40)) {
      glUniform3f(*(int *)(this + 0x40),*(undefined4 *)(param_2 + 0x33c),
                  *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
    }
    if (-1 < *(int *)(this + 0x50)) {
      glUniform4fv(*(int *)(this + 0x50),1,param_2 + 0xc0);
    }
    if (-1 < *(int *)(this + 0x54)) {
      glUniform3fv(*(int *)(this + 0x54),1,param_2 + 700);
    }
    if (-1 < *(int *)(this + 0x5c)) {
      glUniform3fv(*(int *)(this + 0x5c),1,param_2 + 0x2ec);
    }
    if (-1 < *(int *)(this + 100)) {
      glUniform3fv(*(int *)(this + 100),1,param_2 + 0x2d4);
    }
    if (-1 < *(int *)(this + 0x6c)) {
      glUniform1f(*(int *)(this + 0x6c),*(undefined4 *)(param_2 + 0x2b8));
    }
    if (-1 < *(int *)(this + 0x70)) {
      glUniform3fv(*(int *)(this + 0x70),1,param_2 + 0x310);
    }
    if (-1 < *(int *)(this + 0x7c)) {
      uVar2 = 0;
      if (*(int *)(*(int *)(param_1 + 0x30) + 0x24) != 0) {
        uVar2 = 0x3f800000;
      }
      glUniform1f(*(int *)(this + 0x7c),uVar2);
    }
    if (*(int *)(param_2 + 0x31c) < 2) {
      glUniform3f(*(undefined4 *)(this + 0x58),0,0,0);
      glUniform3f(*(undefined4 *)(this + 0x60),0,0,0);
      glUniform3f(*(undefined4 *)(this + 0x68),0,0,0);
    }
    else {
      glUniform3fv(*(undefined4 *)(this + 0x58),1,param_2 + 0x2c8);
      glUniform3fv(*(undefined4 *)(this + 0x60),1,param_2 + 0x2f8);
      glUniform3fv(*(undefined4 *)(this + 0x68),1,param_2 + 0x2e0);
    }
    glUniform3f(*(undefined4 *)(this + 0x3c),*(undefined4 *)(param_2 + 0x32c),
                *(undefined4 *)(param_2 + 0x330),*(undefined4 *)(param_2 + 0x334));
    this[9] = (BumpShaderV3)0x0;
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
    iVar1 = *(int *)(this + 0x2c);
    if (iVar1 < 0) {
      return;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x18);
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
    iVar1 = *(int *)(this + 0x2c);
    uVar2 = 0;
  }
  glVertexAttribPointer(iVar1,3,0x1406,0,0,uVar2);
  return;
}

