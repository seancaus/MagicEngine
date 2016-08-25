#version 410

in vec2 samCoord;
out vec4 fragColor;

uniform sampler2D samTex;

void main()
{
	fragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
