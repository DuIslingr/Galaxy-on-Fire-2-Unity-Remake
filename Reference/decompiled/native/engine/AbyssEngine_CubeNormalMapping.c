// Class: AbyssEngine::CubeNormalMapping
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::CubeNormalMapping::CubeNormalMapping  @0x0009b744  (104 bytes)
/* AbyssEngine::CubeNormalMapping::CubeNormalMapping() */

void __thiscall AbyssEngine::CubeNormalMapping::CubeNormalMapping(CubeNormalMapping *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263b44;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"CubeNormalMapping",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::CubeNormalMapping::Init  @0x0009b7f0  (268 bytes)
/* AbyssEngine::CubeNormalMapping::Init(AbyssEngine::Engine*) */

void AbyssEngine::CubeNormalMapping::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp\tvec3 a_position;   \nattribute mediump\tvec3 a_normal;\t\t\nattribute mediump\tvec2 a_texCoord;   \nattribute lowp \tvec3 a_tangent;\t\t  \nattribute lowp \tvec3 a_bitangent;\t  \nuniform highp\t mat4 u_WorldMatrix;  \nuniform mediump mat3 u_ModelMatrix;  \nuniform mediump vec3 u_eyeposmodel;  \nuniform highp\t vec3 u_lightposmodel;  \nvarying mediump vec3 v_reflectdir;   \nvarying mediump    vec2 v_texCoord;     \nvarying lowp vec4  v_DiffuseLight;\t\nvarying lowp vec3 v_specular_dir;  \nvoid main()                  \n{                            \n\t// Transform position\n   gl_Position = u_WorldMatrix * vec4(a_position, 1.0);\t\t\n\thighp mat3 tangentSpaceXform = mat3(a_tangent.x, a_bitangent.x, a_normal.x,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.y, a_bitangent.y, a_normal.y,  \n\t\t\t\t\t\t\t\t\t\ta_tangent.z, a_bitangent.z, a_normal.z  \n\t\t\t\t\t\t\t\t\t\t);  \n\tvec3 shininesDirection = normalize(normalize(u_eyeposmodel - a_position.xyz) + u_lightposmodel) ;  \n\tv_specular_dir = tangentSpaceXform * shininesDirection;  \n\t// Calculate eye direction in model space\n\tmediump vec3 eyeDir = normalize(a_position - u_eyeposmodel);\n\t// reflect eye direction over normal and transform to world space\n\tv_reflectdir = u_ModelMatrix * reflect(eyeDir, a_normal);\n   v_texCoord = a_texCoord;  \n\tv_DiffuseLight.rgb = vec3(max(dot(normalize(a_normal), normalize(u_lightposmodel)), 0.0)); \n\tv_DiffuseLight.a = 1.0; \n}                            \n"
                     ,
                     "precision mediump float;                            \nuniform samplerCube u_texture_cubemap;\t\t\t \nuniform sampler2D\t u_texture_base;                        \nuniform sampler2D\t u_normalTexture;\t\nuniform highp float u_envValue;  \nuniform lowp vec4   u_AmbientColor;\nuniform lowp vec4   u_DiffuseColor;\nuniform lowp vec4   u_SpecularColor;\nuniform lowp vec4   u_glColor;\t\nuniform mediump float  u_SpecularPower;\nvarying mediump vec3 v_reflectdir;   \nvarying mediump vec2 v_texCoord;                            \nvarying lowp vec4    v_DiffuseLight;\t\nvarying lowp vec3\t  v_specular_dir;  \nvoid main()                                         \n{                                                   \n\tlowp vec4 normalTex  = texture2D( u_normalTexture, v_texCoord, -1.0 );  \n\tlowp vec3 normalTexX = normalTex.rgb*2.0 -1.0;  \n\tfloat specularIntensity = pow( clamp(dot( v_specular_dir,normalTexX ), 0.0, 1.0), u_SpecularPower );  \n\tlowp vec4 combineColor = mix(textureCube(u_texture_cubemap, v_reflectdir), texture2D( u_texture_base, v_texCoord ), u_envValue); \n\tgl_FragColor =  u_glColor*(u_AmbientColor + v_DiffuseLight * u_DiffuseColor) * combineColor + (specularIntensity * u_SpecularColor);\n\t//gl_FragColor =  textureCube(u_texture_cubemap, v_reflectdir);\n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_tangent");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_bitangent");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightposmodel");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_base");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_cubemap");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_normalTexture");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_envValue");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor");
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_glColor");
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x44),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x48),1);
  glUniform1i(*(undefined4 *)(param_1 + 0x40),2);
  return;
}

// ===== AbyssEngine::CubeNormalMapping::SetInActive  @0x0009b94c  (40 bytes)
/* AbyssEngine::CubeNormalMapping::SetInActive() */

void __thiscall AbyssEngine::CubeNormalMapping::SetInActive(CubeNormalMapping *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x28));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x2c));
  return;
}

// ===== AbyssEngine::CubeNormalMapping::UpdateMeshData  @0x0009b974  (452 bytes)
/* AbyssEngine::CubeNormalMapping::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::CubeNormalMapping::UpdateMeshData
          (CubeNormalMapping *this,Mesh *param_1,Engine *param_2)

{
  Mesh MVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (this[9] != (CubeNormalMapping)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x58),1,param_2 + 0xc0);
    glUniform4fv(*(undefined4 *)(this + 0x50),1,param_2 + 700);
    glUniform4fv(*(undefined4 *)(this + 0x54),1,param_2 + 0x2ec);
    glUniform4fv(*(undefined4 *)(this + 0x5c),1,param_2 + 0x2d4);
    glUniform1f(*(undefined4 *)(this + 0x60),*(undefined4 *)(param_2 + 0x2b8));
    this[9] = (CubeNormalMapping)0x0;
  }
  glUniform1f(*(undefined4 *)(this + 0x4c),*(undefined4 *)(param_2 + 0xbc));
  glUniformMatrix4fv(*(undefined4 *)(this + 0x30),1,0,param_2 + 0xf4);
  glUniformMatrix3fv(*(undefined4 *)(this + 0x34),1,0,param_2 + 500);
  glUniform3f(*(undefined4 *)(this + 0x3c),*(undefined4 *)(param_2 + 800),
              *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328));
  glUniform3f(*(undefined4 *)(this + 0x38),*(undefined4 *)(param_2 + 0x33c),
              *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x28));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x2c));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    MVar1 = *param_1;
    if (((byte)MVar1 & 2) != 0) {
      glVertexAttribPointer(*(undefined4 *)(this + 0x24),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
      MVar1 = *param_1;
    }
    if (((byte)MVar1 & 4) != 0) {
      glVertexAttribPointer
                (*(undefined4 *)(this + 0x20),3,0x1406,0,0,*(undefined4 *)(param_1 + 0x10));
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
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    glVertexAttribPointer(*(undefined4 *)(this + 0x20),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x70));
    glVertexAttribPointer(*(undefined4 *)(this + 0x28),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x74));
    iVar2 = *(int *)(this + 0x2c);
    uVar3 = 0;
  }
  glVertexAttribPointer(iVar2,3,0x1406,0,0,uVar3);
  return;
}

