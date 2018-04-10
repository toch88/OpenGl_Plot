#shader vertex
#version 330 core 

layout(location=0) in vec2 position;

void main()
{
    gl_Position=vec4(position.x, position.y, 0.0, 1.0);  
   
};

#shader fragment  
#version 330 core 

out vec4 color;


void main()
{
    color=vec4(1.0,0.0,0.0,1.0);    
};