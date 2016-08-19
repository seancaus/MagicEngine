#version 330 core

in vec2 imgCoord;
out vec4 fcolor;

uniform sampler2D samp;

void main()
{
    fcolor = texture(samp,imgCoord);
}
