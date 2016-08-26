#version 410

layout(location=0)in vec2 pos;
layout(location=1)in vec2 inCoord;

layout(location=2)in mat4 model;
layout(location=6)in float foodType;

out vec2 samCoord;
flat out float ofoodType;

layout(std140)uniform Matrices
{
    mat4 view;
    mat4 projection;
};

void main()
{
    samCoord    = inCoord;
    ofoodType   = foodType;
	gl_Position = projection * view * model * vec4(pos,1.0, 1.0);
}
