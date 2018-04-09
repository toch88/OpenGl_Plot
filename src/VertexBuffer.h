#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
class VertexBuffer
{
    private:
        unsigned int _RendererID;
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();
        inline toString(){std::cout<<"Vertex Buffer: "<<this->_RendererID<<std::endl;}

        void Update(const void* data, unsigned int size);

        void Bind() const;
        void Unbind() const;

};