#version 410

in vec2 samCoord;
flat in float ofoodType;
out vec4 fragColor;

uniform sampler2D samTex1;
uniform sampler2D samTex2;
uniform sampler2D samTex3;
uniform sampler2D samTex4;

void main()
{
    if(3 <= ofoodType)
    {
        fragColor = texture(samTex1 ,vec2(samCoord.s,1-samCoord.t));
    }else if(2 <= ofoodType)
    {
        fragColor = texture(samTex2 ,vec2(samCoord.s,1-samCoord.t));
    }else if(1 <= ofoodType)
    {
        fragColor = texture(samTex3 ,vec2(samCoord.s,1-samCoord.t));
    }else
    {
        fragColor = texture(samTex4 ,vec2(samCoord.s,1-samCoord.t));
    }
}
