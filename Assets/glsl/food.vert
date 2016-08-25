#version 410

layout(location=0)in vec2 pos;
layout(location=1)in vec2 inCoord;
layout(location=2)in mat4 model;

out vec2 samCoord;

layout(std140)uniform Matrices
{
    mat4 view;
    mat4 projection;
};

void main()
{
    samCoord = inCoord;
	gl_Position = projection * view * model * vec4(pos,1.0, 1.0);
}
