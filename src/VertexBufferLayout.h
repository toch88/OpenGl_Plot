#pragma once
#include <iostream>
#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;    
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
        case GL_FLOAT:
            return 4;
        case GL_UNSIGNED_INT:
            return 4;
        case GL_UNSIGNED_BYTE:
            return 1;
        }
        return 0;
    }
};

class VertexBufferLayout
{
  private:
    std::vector<VertexBufferElement> _Elements;
    unsigned int _Stride;

  public:
    VertexBufferLayout()
        : _Stride(0)
    {
    }

    template <typename T>
    void Push(unsigned int count);
    inline const std::vector<VertexBufferElement> GetElements() const & { return _Elements; }
    inline unsigned int GetStrid() const { return _Stride; }
};
