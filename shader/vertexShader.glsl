#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor_modelspace;
layout(location = 2) in vec2 vertexTexture;

smooth out vec3 colort;
smooth out vec2 textCoord;

uniform mat4 u_modelMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;

void main(){
  colort = vertexColor_modelspace;

  textCoord = vertexTexture;

  gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(vertexPosition_modelspace, 1);
}