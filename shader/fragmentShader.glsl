#version 330 core

smooth in vec3 colort;
smooth in vec2 textCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main(){
  color = texture(ourTexture, textCoord);
  //color = vec4(0.5, 0.5, 0.5 ,0);
}