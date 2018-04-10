#shader vertex
#version 330 core 

layout(location=0) in vec2 position;
layout(location=1) in vec3 color;
layout(location=2) in vec2 texCoor;

out vec2 o_texCoor;

void main()
{
    gl_Position=vec4(position.x, position.y, 0.0, 1.0);  
    o_texCoor=texCoor;

};

#shader fragment  
#version 330 core 

out vec4 color;
in vec4 o_color;
in vec2 o_texCoor;


uniform sampler2D u_Texture;
void main()
{
    vec4 texColor=texture(u_Texture, o_texCoor);
    color=texColor;
};