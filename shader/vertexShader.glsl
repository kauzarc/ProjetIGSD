#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor_modelspace;
layout(location = 2) in vec2 vertexTexture;

smooth out vec3 colort;
smooth out vec2 textCoord;

uniform mat4 u_modelMatrix;
uniform mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;
uniform bool u_selected;

void main(){
  colort = vertexColor_modelspace;

  textCoord = vertexTexture;

  vec3 position = vertexPosition_modelspace;
  if(u_selected)
  {
    position.z -= 0.1;
  }


  gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * vec4(position, 1);
}