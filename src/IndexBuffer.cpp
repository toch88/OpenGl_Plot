#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
:_Count(count)
{
    glGenBuffers(1, &_RendererID);                                                       //I am getting buffer "ID"
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _RendererID);                                          //This buffer is a ARRAY
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), data, GL_STATIC_DRAW); //Fill buffer with data from position
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &_RendererID);
}

void IndexBuffer::Bind() const
{
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _RendererID);   
}

void IndexBuffer::Unbind() const
{
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   
}