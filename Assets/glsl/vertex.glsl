#version 330 core

layout(location = 0)in vec4 pos;
layout(location = 1)in vec2 coord;

out vec2 imgCoord;

void main()
{
    imgCoord = coord;
    gl_Position = pos;
}