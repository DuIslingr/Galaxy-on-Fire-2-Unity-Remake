// Class: AbyssEngine::SpecCubeAlphaMapping
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::SpecCubeAlphaMapping::SpecCubeAlphaMapping  @0x00092908  (104 bytes)
/* AbyssEngine::SpecCubeAlphaMapping::SpecCubeAlphaMapping() */

void __thiscall AbyssEngine::SpecCubeAlphaMapping::SpecCubeAlphaMapping(SpecCubeAlphaMapping *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263410;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"SpecCubeAlphaMapping",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::SpecCubeAlphaMapping::Init  @0x000929b4  (242 bytes)
/* AbyssEngine::SpecCubeAlphaMapping::Init(AbyssEngine::Engine*) */

void AbyssEngine::SpecCubeAlphaMapping::Init(Engine *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ShaderBaseStruct::LoadBindShader
                    ((ShaderBaseStruct *)param_1,"data/shader/SpecCubeAlphaMapping.vs",
                     "data/shader/SpecCubeAlphaMapping.fs");
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    iVar1 = ShaderBaseStruct::ES2LoadProgram
                      ((ShaderBaseStruct *)param_1,
                       "attribute highp\tvec3 a_position;   \nattribute mediump\tvec3 a_normal;\t\t\nattribute mediump\tvec2 a_texCoord;   \nuniform highp\t mat4 u_WorldMatrix;  \nuniform mediump mat3 u_ModelMatrix;  \nuniform mediump vec3 u_eyeposmodel;  \nuniform highp\t vec4 u_lightposmodel;  \nvarying mediump vec3 v_reflectdir;   \nvarying mediump    vec2 v_texCoord;     \nvarying lowp vec3  v_DiffuseLight;\t\nuniform lowp vec3   u_AmbientColor;\nuniform lowp vec3   u_DiffuseColor;\nuniform lowp vec3\tu_SpecularColor;\nuniform mediump float u_SpecularPower;\nvoid main()                  \n{                            \n\t// Transform position\n   gl_Position = u_WorldMatrix * vec4(a_position, 1.0);\t\t\n\t// Calculate eye direction in model space\n\tmediump vec3 eyeDir = normalize( a_position - u_eyeposmodel);\n\t//mediump vec3 eyeDir = normalize( u_eyeposmodel - a_position);\n\t// reflect eye direction over normal and transform to world space\n\tv_reflectdir = u_ModelMatrix * reflect(eyeDir, a_normal);\n\thighp vec3 lightDirLocal; \n\thighp float nDotL; \n\tlightDirLocal = u_lightposmodel.xyz; \n\tnDotL = dot(a_normal, lightDirLocal);\n\tv_DiffuseLight = vec3(max(nDotL, 0.0)); \n\t// Compute\treflection vector \n\thighp vec3 reflection = (2.0 * a_normal * nDotL) - lightDirLocal;\t\n   reflection = normalize(-reflect(lightDirLocal, a_normal)); \n\t// Compute R.V \n\thighp float rDotV = max(0.0, dot(reflection, normalize(u_eyeposmodel)));\n\t// Compute Specular term \n\tv_DiffuseLight *= u_DiffuseColor;\n\tv_DiffuseLight += u_AmbientColor;\n   v_texCoord = a_texCoord;  \n}                            \n"
                       ,
                       "precision mediump float;                            \nuniform samplerCube u_texture_cubemap;\t\t\t \nuniform sampler2D\t u_texture_base;                        \nuniform lowp vec4   u_glColor;\t\nuniform lowp float   u_cubeMapFactor;\t\nvarying mediump vec3 v_reflectdir;   \nvarying mediump vec2 v_texCoord;                            \nvarying lowp vec3    v_DiffuseLight;\t\nvoid main()                                         \n{                                                   \n   lowp vec4 diffuseColor = texture2D( u_texture_base, v_texCoord ); \n\tgl_FragColor.xyz =  u_glColor.xyz*((v_DiffuseLight) * diffuseColor.xyz + u_cubeMapFactor * textureCube(u_texture_cubemap, v_reflectdir).xyz);\n\tgl_FragColor.a = diffuseColor.a; \n}   \t\t  \n"
                      );
    *(int *)(param_1 + 4) = iVar1;
  }
  uVar2 = glGetAttribLocation(iVar1,"a_position");
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_normal");
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  uVar2 = glGetAttribLocation(*(undefined4 *)(param_1 + 4),"a_texCoord");
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_WorldMatrix");
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_ModelMatrix");
  *(undefined4 *)(param_1 + 0x2c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_eyeposmodel");
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_lightposmodel");
  *(undefined4 *)(param_1 + 0x34) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_base");
  *(undefined4 *)(param_1 + 0x3c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_texture_cubemap");
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_AmbientColor");
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_DiffuseColor");
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularColor");
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_SpecularPower");
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_glColor");
  *(undefined4 *)(param_1 + 0x50) = uVar2;
  uVar2 = glGetUniformLocation(*(undefined4 *)(param_1 + 4),"u_cubeMapFactor");
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  glUseProgram(*(undefined4 *)(param_1 + 4));
  glUniform1i(*(undefined4 *)(param_1 + 0x3c),0);
  glUniform1i(*(undefined4 *)(param_1 + 0x38),1);
  return;
}

// ===== AbyssEngine::SpecCubeAlphaMapping::SetInActive  @0x00092af4  (28 bytes)
/* AbyssEngine::SpecCubeAlphaMapping::SetInActive() */

void __thiscall AbyssEngine::SpecCubeAlphaMapping::SetInActive(SpecCubeAlphaMapping *this)

{
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x1c));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x20));
  glDisableVertexAttribArray(*(undefined4 *)(this + 0x24));
  return;
}

// ===== AbyssEngine::SpecCubeAlphaMapping::UpdateMeshData  @0x00092b10  (360 bytes)
/* AbyssEngine::SpecCubeAlphaMapping::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::SpecCubeAlphaMapping::UpdateMeshData
          (SpecCubeAlphaMapping *this,Mesh *param_1,Engine *param_2)

{
  Mesh MVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (this[9] != (SpecCubeAlphaMapping)0x0) {
    uVar3 = 0x3f800000;
    iVar2 = *(int *)(param_1 + 0x30);
    if (((iVar2 != 0) && (*(undefined4 **)(iVar2 + 0x24) != (undefined4 *)0x0)) &&
       (*(int *)(iVar2 + 0x28) == 4)) {
      uVar3 = **(undefined4 **)(iVar2 + 0x24);
    }
    glUniform1f(*(undefined4 *)(this + 0x54),uVar3);
    glUniform4fv(*(undefined4 *)(this + 0x50),1,param_2 + 0xc0);
    glUniform3fv(*(undefined4 *)(this + 0x40),1,param_2 + 700);
    glUniform3fv(*(undefined4 *)(this + 0x44),1,param_2 + 0x2ec);
    glUniform3fv(*(undefined4 *)(this + 0x48),1,param_2 + 0x2d4);
    glUniform1f(*(undefined4 *)(this + 0x4c),*(undefined4 *)(param_2 + 0x2b8));
    this[9] = (SpecCubeAlphaMapping)0x0;
  }
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
    uVar3 = *(undefined4 *)(this + 0x20);
    uVar4 = *(undefined4 *)(param_1 + 0x10);
  }
  else {
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
    glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
    glVertexAttribPointer(*(undefined4 *)(this + 0x24),2,0x1406,0,0,0);
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x6c));
    uVar3 = *(undefined4 *)(this + 0x20);
    uVar4 = 0;
  }
  glVertexAttribPointer(uVar3,3,0x1406,0,0,uVar4);
  return;
}

