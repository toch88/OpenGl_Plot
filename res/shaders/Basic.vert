#shader vertex
#version 330 core 

layout(location=0) in vec4 position;
layout(location=1) in float i_color;

out vec4 o_color;
void main()
{
    gl_Position=position;
    o_color=vec4(position.xyz, 0.0);

};

#shader fragment  
#version 330 core 

out vec4 color;

in vec4 o_color;

void main()
{

    color=o_color+vec4(0.2,0.2,0.2,1);
    
};