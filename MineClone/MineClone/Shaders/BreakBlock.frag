#version 330

out vec4 outColour;

in vec2 passTextureCoord;

uniform sampler2D texSampler;
uniform float lighting;

void main()
{
    vec4 colour = texture(texSampler, passTextureCoord);
    outColour = vec4(colour.rgb * lighting, colour.a);
}