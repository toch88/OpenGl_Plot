#include "VertexBufferLayout.h"

template <typename T>
void VertexBufferLayout::Push(unsigned int count)
{
}

template <>
void VertexBufferLayout::Push<float>(unsigned int count)
{
    _Elements.push_back({GL_FLOAT, count, GL_FALSE});
    _Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template <>
void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    _Elements.push_back({GL_UNSIGNED_INT, count, GL_TRUE});
    _Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template <>
void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    _Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    _Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}