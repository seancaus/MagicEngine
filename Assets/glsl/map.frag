#version 410

in vec2 texCoord;

out vec4 fragColor;

uniform sampler2D texSampler;

void main()
{
    fragColor = texture(texSampler,texCoord);
//	fragColor = vec4(.3, 0.5, 0.0, 1.0);
}
