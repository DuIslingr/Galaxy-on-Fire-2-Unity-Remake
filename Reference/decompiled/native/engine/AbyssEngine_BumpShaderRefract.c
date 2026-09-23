// Class: AbyssEngine::BumpShaderRefract
// Decompiled from libgof2hdaa.so (armeabi-v7a) with Ghidra 12.1.4. Pseudocode, NOT compilable.
// Addresses use Ghidra image base 0x10000.

// ===== AbyssEngine::BumpShaderRefract::BumpShaderRefract  @0x0009a470  (104 bytes)
/* AbyssEngine::BumpShaderRefract::BumpShaderRefract() */

void __thiscall AbyssEngine::BumpShaderRefract::BumpShaderRefract(BumpShaderRefract *this)

{
  String aSStack_20 [8];
  int local_18;
  
  local_18 = __stack_chk_guard;
  ShaderBaseStruct::ShaderBaseStruct((ShaderBaseStruct *)this);
  *(undefined ***)this = &PTR_Init_00263a2c;
  ShaderIndex = ShaderBaseStruct::shaderIndexIntern;
  String::String(aSStack_20,"BumpShaderRefract",false);
  String::operator=((String *)(this + 0xc),aSStack_20);
  String::~String(aSStack_20);
  if (__stack_chk_guard - local_18 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(__stack_chk_guard - local_18);
  }
  return;
}

// ===== AbyssEngine::BumpShaderRefract::Init  @0x0009a51c  (214 bytes)
/* AbyssEngine::BumpShaderRefract::Init(AbyssEngine::Engine*) */

void __thiscall AbyssEngine::BumpShaderRefract::Init(BumpShaderRefract *this,Engine *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ShaderBaseStruct::ES2LoadProgram
                    ((ShaderBaseStruct *)this,
                     "attribute highp vec3 a_position;\nattribute mediump vec2 a_texCoord;\nattribute mediump vec4 a_VertexColor;   \nvarying mediump vec2 v_texCoord;  \nvarying mediump vec4 v_VertexColor;     \nuniform highp mat4 u_ModelViewProjectionMatrix;\nuniform highp mat4 u_UvMatrix;  \nuniform bool u_UVAnimation; \nvoid main()  \n{  \n\tgl_Position = u_ModelViewProjectionMatrix * vec4(a_position, 1.0);\n   if ( u_UVAnimation ) \n       v_texCoord = (u_UvMatrix*vec4(a_texCoord.x, a_texCoord.y, 0.0, 1.0)).xy;  \n   else \n       v_texCoord = a_texCoord; \n   v_VertexColor = a_VertexColor;  \n}\n"
                     ,
                     "precision lowp float;  \nvarying mediump vec2 v_texCoord;\nvarying mediump vec4 v_VertexColor;     \nuniform sampler2D  s_texture[2];\nuniform mediump vec2 u_texelSize;\nuniform sampler2D s_texture_base;\nuniform lowp vec4 glColor;\t\t\t\t\t\t\t\t \nvoid main()\n{\n\tlowp vec4 colorTex   = (texture2D( s_texture[0], v_texCoord) * glColor);\n\tmediump vec4 normalTex  = texture2D( s_texture[1], v_texCoord);\n\tmediump vec3 normalTexX = normalTex.rgb * 2.0 - 1.0;\n   mediump vec2 coord;\n   mediump vec2 coord1;\n   coord1.x = (gl_FragCoord.x ) * u_texelSize.x;\n   coord1.y = (gl_FragCoord.y ) * u_texelSize.y;\n   coord.x = (gl_FragCoord.x + glColor.r*v_VertexColor.r*(normalTexX.x*40.0 * (0.75))) * u_texelSize.x;\n   coord.y = (gl_FragCoord.y + glColor.r*v_VertexColor.r*(normalTexX.y*30.0 * (0.75))) * u_texelSize.y;\n\tgl_FragColor.rgb = (colorTex.rgb*v_VertexColor.rgb + texture2D(s_texture_base, coord).rgb) - texture2D(s_texture_base, coord1).rgb;\n}\n"
                    );
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = glGetAttribLocation(uVar1,"a_position");
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_texCoord");
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = glGetAttribLocation(*(undefined4 *)(this + 4),"a_VertexColor");
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_ModelViewProjectionMatrix");
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[0]");
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture[1]");
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_texelSize");
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_UvMatrix");
  *(undefined4 *)(this + 0x3c) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"u_UVAnimation");
  *(undefined4 *)(this + 0x40) = uVar1;
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"glColor");
  *(undefined4 *)(this + 0x44) = uVar1;
  glActiveTexture(0x84c7);
  Engine::ActivateRefractFBO(param_1);
  uVar1 = glGetUniformLocation(*(undefined4 *)(this + 4),"s_texture_base");
  *(undefined4 *)(this + 0x38) = uVar1;
  glUseProgram(*(undefined4 *)(this + 4));
  iVar2 = 0;
  do {
    if (-1 < *(int *)(this + iVar2 * 4 + 0x2c)) {
      glUniform1i(*(int *)(this + iVar2 * 4 + 0x2c),iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 2);
  glUniform1i(*(undefined4 *)(this + 0x38),7);
  return;
}

// ===== AbyssEngine::BumpShaderRefract::SetInActive  @0x0009a628  (42 bytes)
/* AbyssEngine::BumpShaderRefract::SetInActive() */

void __thiscall AbyssEngine::BumpShaderRefract::SetInActive(BumpShaderRefract *this)

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

// ===== AbyssEngine::BumpShaderRefract::UpdateMeshData  @0x0009a652  (392 bytes)
/* AbyssEngine::BumpShaderRefract::UpdateMeshData(AbyssEngine::Mesh*, AbyssEngine::Engine*) */

void __thiscall
AbyssEngine::BumpShaderRefract::UpdateMeshData
          (BumpShaderRefract *this,Mesh *param_1,Engine *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  
  if (-1 < *(int *)(this + 0x28)) {
    glUniformMatrix4fv(*(int *)(this + 0x28),1,0,param_2 + 0xf4);
  }
  if (-1 < *(int *)(this + 0x3c)) {
    glUniformMatrix4fv(*(int *)(this + 0x3c),1,0,param_2 + 0x1b4);
  }
  if (this[9] != (BumpShaderRefract)0x0) {
    if (-1 < *(int *)(this + 0x40)) {
      glUniform1i(*(int *)(this + 0x40),param_1[0x85]);
    }
    glUniform4fv(*(undefined4 *)(this + 0x44),1,param_2 + 0xc0);
    iVar2 = *(int *)(this + 0x34);
    if (-1 < iVar2) {
      uVar1 = Engine::GetDisplayWidth(param_2);
      fVar4 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      uVar1 = Engine::GetDisplayHeight(param_2);
      fVar3 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
      glUniform2f(iVar2,1.0 / fVar4,1.0 / fVar3);
    }
    glActiveTexture(0x84c7);
    Engine::ActivateRefractFBO(param_2);
    this[9] = (BumpShaderRefract)0x0;
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
  iVar2 = *(int *)(this + 0x1c);
  if (param_1[0x5c] == (Mesh)0x0) {
    if (-1 < iVar2) {
      glVertexAttribPointer(iVar2,3,0x1406,0,0,*(undefined4 *)(param_1 + 4));
    }
    if (-1 < *(int *)(this + 0x20)) {
      glVertexAttribPointer(*(int *)(this + 0x20),2,0x1406,0,0,*(undefined4 *)(param_1 + 8));
    }
    iVar2 = *(int *)(this + 0x24);
    if (iVar2 < 0) {
      return;
    }
    uVar1 = *(undefined4 *)(param_1 + 0xc);
  }
  else {
    if (-1 < iVar2) {
      glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x60));
      glVertexAttribPointer(*(undefined4 *)(this + 0x1c),3,0x1406,0,0,0);
    }
    if (-1 < *(int *)(this + 0x20)) {
      glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x68));
      glVertexAttribPointer(*(undefined4 *)(this + 0x20),2,0x1406,0,0,0);
    }
    if (*(int *)(this + 0x24) < 0) {
      return;
    }
    glBindBuffer(0x8892,*(undefined4 *)(param_1 + 0x78));
    uVar1 = 0;
    iVar2 = *(int *)(this + 0x24);
  }
  glVertexAttribPointer(iVar2,4,0x1406,0,0,uVar1);
  return;
}

