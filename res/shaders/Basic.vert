#shader vertex
#version 330 core 

layout(location=0) in vec4 position;

out vec4 o_color;
void main()
{
    gl_Position=vec4(position.x, position.y, 0.0, 1.0);  

};

#shader fragment  
#version 330 core 

out vec4 color;

in vec4 o_color;

void main()
{

    color=vec4(0.2,0.2,0.2,1);
    
};