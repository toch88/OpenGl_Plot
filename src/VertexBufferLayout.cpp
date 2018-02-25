#include "VertexBufferLayout.h"

template <typename T>
void VertexBufferLayout::Push(unsigned int count)
{
}

template <>
void VertexBufferLayout::Push<float>(unsigned int count)
{
  
    _Elements.push_back({GL_FLOAT, count, GL_FALSE, _offset});
    _offset = count * VertexBufferElement::GetSizeOfType(GL_FLOAT);;
    _Stride += _offset;
}

template <>
void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    _Elements.push_back({GL_UNSIGNED_INT, count, GL_TRUE, _offset});
    _offset =  count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);;
    _Stride += _offset;
}

template <>
void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    _Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE, _offset});
    _offset = count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);;
    _Stride += _offset;
}