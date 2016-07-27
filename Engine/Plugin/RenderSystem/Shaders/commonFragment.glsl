#version 330 core

uniform vec3 ourColor;
out vec4 color;

void main()
{
//	gl_FragCoord = vec4(ourColor,.5);
    color = vec4(ourColor,.5);
}
