#shader vertex
#version 330 core 

layout(location=0) in vec4 position;
layout(location=1) in float i_color;

out float o_color;
void main()
{
    gl_Position=position;
    o_color=i_color;

};

#shader fragment  
#version 330 core 

layout(location=0) out vec4 color;

in float o_color;

void main()
{

    color=vec4(o_color, 0.2, 0.3, 1.0);
    
};