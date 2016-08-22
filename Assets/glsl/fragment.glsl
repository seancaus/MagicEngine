#version 330 core

in vec2 imgCoord;

uniform sampler2D samp;

void main()
{
//    gl_FragColor = texture(samp,imgCoord);
    gl_FragData[0] = texture(samp,imgCoord);
}
