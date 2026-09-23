// Class: AbyssEngine::CubeMapping
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::CubeMapping::CubeMapping  @0x0009b404  (104 bytes)
/* AbyssEngine::CubeMapping::CubeMapping() */

void __thiscall AbyssEngine::CubeMapping::CubeMapping(CubeMapping *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263b0c;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"CubeMapping",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::CubeMapping::Init  @0x0009b4b0  (224 bytes)
/* AbyssEngine::CubeMapping::Init(AbyssEngine::Engine*) */

void AbyssEngine::CubeMapping::Init(Engine *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)param_1,
                     "attribute highp\tvec3 a_position;   \nattribute mediump\tvec3 a_normal;\t\t\nattribute mediump\tvec2 a_texCoord;   \nuniform highp\t mat4 u_WorldMatrix;  \nuniform mediump mat3 u_ModelMatrix;  \nuniform mediump vec3 u_eyeposmodel;  \nuniform highp\t vec4 u_lightposmodel;  \nvarying mediump vec3 v_reflectdir;   \nvarying mediump    vec2 v_texCoord;     \nvarying lowp vec3  v_DiffuseLight;\t\nvarying lowp vec3  v_SpecularLight;\t\nvarying highp float\tv_rimFactor; \nuniform lowp vec3   u_AmbientColor;\nuniform lowp vec3   u_DiffuseColor;\nuniform lowp vec3\tu_SpecularColor;\nuniform mediump float u_SpecularPower;\nvoid main()                  \n{                            \n\t// Transform position\n   gl_Position = u_WorldMatrix * vec4(a_position, 1.0);\t\t\n\t// Calculate eye direction in model space\n\tmediump vec3 eyeDir = normalize( a_position - u_eyeposmodel);\n\t//mediump vec3 eyeDir = normalize( u_eyeposmodel - a_position);\n\t// reflect eye direction over normal and transform to world space\n\tv_reflectdir = u_ModelMatrix * reflect(eyeDir, a_normal);\n\thighp vec3 lightDirLocal; \n\thighp float nDotL; \n\tlightDirLocal = u_lightposmodel.xyz; \n\tnDotL = dot(a_normal, lightDirLocal);\n\tv_DiffuseLight = vec3(max(nDotL, 0.0)); \n\t// Compute\treflection vector \n\thighp vec3 reflection = (2.0 * a_normal * nDotL) - lightDirLocal;\t\n   reflection = normalize(-reflect(lightDirLocal, a_normal)); \n\t// Compute R.V \n\thighp float rDotV = max(0.0, dot(reflection, normalize(u_eyeposmodel)));\n\t// Compute Specular term \n\tv_SpecularLight = u_SpecularColor * pow(rDotV, u_SpecularPower);\t\n\tv_DiffuseLight *= u_DiffuseColor;\n\tv_DiffuseLight += u_AmbientColor;\n   v_texCoord = a_texCoord;  \n\t//v_rimFactor = clamp( 1.2 - dot( normalize( u_eyeposmodel - a_position), a_normal ), 0.0, 1.0);  \n}                            \n"
                     ,
                     "precision mediump float;                            \nuniform samplerCube u_texture_cubemap;\t\t\t \nuniform sampler2D\t u_texture_base;                        \nuniform highp float u_envValue;  \nuniform lowp vec4   u_glColor;\t\nvarying mediump vec3 v_reflectdir;   \nvarying mediump vec2 v_texCoord;                            \nvarying lowp vec3    v_DiffuseLight;\t\nvarying lowp vec3  v_SpecularLight;\t\nvarying highp float\tv_rimFactor; \nvoid main()                                         \n{                                                   \n\t//lowp vec4 combineColor = mix(textureCube(u_texture_cubemap, v_reflectdir), texture2D( u_texture_base, v_texCoord ), (1.0- v_rimFactor)); \n\tlowp vec4 combineColor = mix(textureCube(u_texture_cubemap, v_reflectdir), texture2D( u_texture_base, v_texCoord ), u_envValue); \n\tgl_FragColor.xyz =  u_glColor.xyz*((v_DiffuseLight) * combineColor.xyz + v_SpecularLight);\n\t//gl_FragColor.xyz =  u_glColor.xyz*((v_DiffuseLight) * texture2D( u_texture_base, v_texCoord ).xyz + textureCube(u_texture_cubemap, v_reflectdir).xyz + v_SpecularLight);\n\tgl_FragColor.a = u_glColor.a * combineColor.a; \n   //gl_FragColor = vec4(v_rimFactor, v_rimFactor, v_rimFactor, 1.0); \n}   \t\t  \n"
                    );
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightposmodel");
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_base");
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_cubemap");
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_envValue");
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor");
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor");
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor");
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_glColor");
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x3c),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x38),1);
  return;
}

// ===== AbyssEngine::CubeMapping::SetInActive  @0x0009b5d4  (28 bytes)
/* AbyssEngine::CubeMapping::SetInActive() */

void __thiscall AbyssEngine::CubeMapping::SetInActive(CubeMapping *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  return;
}

// ===== AbyssEngine::CubeMapping::UpdateMeshData  @0x0009b5f0  (338 bytes)
/* AbyssEngine::CubeMapping::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::CubeMapping::UpdateMeshData(CubeMapping *this,Mesh *param_1,Engine *param_2)

{
  Mesh MVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (this[9] != (CubeMapping)0x0) {
    glUniform4fv(*(undefined4 *)(this + 0x54),1,param_2 + 0xc0);
    glUniform3fv(*(undefined4 *)(this + 0x44),1,param_2 + 700);
    glUniform3fv(*(undefined4 *)(this + 0x48),1,param_2 + 0x2ec);
    glUniform3fv(*(undefined4 *)(this + 0x4c),1,param_2 + 0x2d4);
    glUniform1f(*(undefined4 *)(this + 0x50),*(undefined4 *)(param_2 + 0x2b8));
    this[9] = (CubeMapping)0x0;
  }
  glUniform1f(*(undefined4 *)(this + 0x40),*(undefined4 *)(param_2 + 0xbc));
  glUniformMatrix4fv(*(undefined4 *)(this + 0x28),1,0,param_2 + 0xf4);
  glUniformMatrix3fv(*(undefined4 *)(this + 0x2c),1,0,param_2 + 500);
  glUniform4f(*(undefined4 *)(this + 0x34),*(undefined4 *)(param_2 + 800),
              *(undefined4 *)(param_2 + 0x324),*(undefined4 *)(param_2 + 0x328),
              *(undefined4 *)(param_2 + 0x368));
  glUniform3f(*(undefined4 *)(this + 0x30),*(undefined4 *)(param_2 + 0x33c),
              *(undefined4 *)(param_2 + 0x340),*(undefined4 *)(param_2 + 0x344));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x24));
  glEnableVertexAttribArray(*(undefined4 *)(this + 0x20));
  if (param_1[0x5c] == (Mesh)0x0) {
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    MVar1 = *param_1;
    if (((byte)MVar1 & 2) != 0) {
      glVertexAttribPointer(*(undefined4 *)(this + 0x24),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
      MVar1 = *param_1;
    }
    if (((byte)MVar1 & 4) == 0) {
      return;
    }
    uVar2 = *(undefined4 *)(this + 0x20);
    uVar3 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    uVar2 = *(undefined4 *)(this + 0x20);
    uVar3 = 0;
  }
  glVertexAttribPointer(uVar2,3,0x1406,0,0,uVar3);
  return;
}

