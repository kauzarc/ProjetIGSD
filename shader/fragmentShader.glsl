#version 330 core

smooth in vec3 colort;
smooth in vec2 textCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main(){
  vec4 textureColor = texture(ourTexture, textCoord);
  
  if(length(textureColor) < 1.3)
  {
    color = textureColor;
  }else
  {
    color.xyz = colort;
    color.w = 0;  
  }
}