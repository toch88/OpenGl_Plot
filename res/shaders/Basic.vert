#shader vertex
#version 330 core 

layout(location=0) in vec2 position;
layout(location=1) in vec3 color;

uniform vec4 u_ourColor;

out vec4 o_color;

void main()
{
    gl_Position=vec4(position.x, position.y, 0.0, 1.0);  
    o_color=vec4(1.0, 0.0, 0.0 , 1);

};

#shader fragment  
#version 330 core 

out vec4 color;
in vec4 o_color;

uniform vec4 u_ourColor;
void main()
{

    color=u_ourColor;
    
};