#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor_modelspace;

smooth out vec3 colort;

void main(){
  colort = vertexColor_modelspace;

  gl_Position.xyz = vertexPosition_modelspace;
  gl_Position.w = 1.0;
}