#version 330 core

out vec4 FragColor;

in vec2 TexCoord;           // from vertex shader
uniform sampler2D tex0;     // the bound texture

void main()
{
    FragColor = texture(tex0, TexCoord);
}
