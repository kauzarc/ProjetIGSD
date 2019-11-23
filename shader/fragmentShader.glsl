#version 330 core

uniform float u_red;

out vec4 color;
void main(){
  color = vec4(u_red,0,0,0);
}