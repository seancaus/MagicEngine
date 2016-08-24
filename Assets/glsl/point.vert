#version 420 core

layout(location=0)in vec2 pos;
layout(location=1)in mat4 model;

layout(std140,binding=0)uniform Matrices{
    mat4 view;
    mat4 projection;
};

void main()
{
//	gl_Position = projection * view * model * pos;
//projection * view * model *
	gl_Position = projection * view * model * vec4(pos,1,1);
}

