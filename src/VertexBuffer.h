#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
    private:
        unsigned int _RendererID;
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

};