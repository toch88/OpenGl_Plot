#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
class VertexBuffer
{
    private:
        unsigned int _RendererID;
        unsigned int _sizeOfBuffer;
      
    public:
        std::string name;
        VertexBuffer(const void* data, unsigned int size,const std::string& _name);
        ~VertexBuffer();
        inline toString(){std::cout<<"Vertex Buffer: "<<this->_RendererID<<std::endl;}

        void Update(const void* data);

        void Bind() const;
        void Unbind() const;

};