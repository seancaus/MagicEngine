#version 410

layout(location=0)in vec2 pos;
layout(location=1)in vec2 inCoord;

out vec2 texCoord;

void main() {
    texCoord = inCoord;
	gl_Position = vec4(pos, 1.0 , 1.0);
}
