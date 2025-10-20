#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform sampler2D tex0;

void main()
{
    vec4 texColor = texture(tex0, TexCoord);
    // Use only alpha from the texture, force RGB to white
    FragColor = vec4(1.0, 1.0, 1.0, texColor.a);
}
