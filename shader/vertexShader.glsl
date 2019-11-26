#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor_modelspace;
layout(location = 2) in vec2 vertexTexture;

smooth out vec3 colort;
smooth out vec2 textCoord;

void main(){
  colort = vertexColor_modelspace;

  textCoord = vertexTexture;

  gl_Position.xyz = vertexPosition_modelspace;
  gl_Position.w = 1.0;
}