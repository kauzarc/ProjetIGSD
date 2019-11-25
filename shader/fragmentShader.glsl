#version 330 core

smooth in vec3 colort;

out vec4 color;

void main(){
  color = vec4(colort.x, colort.y, colort.z ,0);
  //color = vec4(0.5, 0.5, 0.5 ,0);
}