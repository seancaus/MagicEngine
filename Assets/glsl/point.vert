#version 330 core

layout(location=0)in vec4 pos;
layout(location=1)in vec2 offset;

layout(std140)uniform Matrices{
    mat4 view;
    mat4 projection;
};

uniform mat4 model;

void main()
{
	gl_Position = pos + vec4(offset,0,0);
}
