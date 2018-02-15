#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class IndexBuffer
{
    private:
        unsigned int _RendererID;
        unsigned int _Count;
    public:
        IndexBuffer(const unsigned int* data, unsigned int count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

        inline unsigned int GetCount() const {return _Count;}

};