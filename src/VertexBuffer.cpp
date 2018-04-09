#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size)
{
    glGenBuffers(1, &_RendererID);                                                       //I am getting buffer "ID"
    this->Bind();                                     //This buffer is a ARRAY
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW); //Fill buffer with data from position
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_RendererID);
}

void VertexBuffer::Update(const void *data, unsigned int size){
    this->Bind();
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    this->Unbind();
}

void VertexBuffer::Bind() const
{
     glBindBuffer(GL_ARRAY_BUFFER, _RendererID);   
}

void VertexBuffer::Unbind() const
{
     glBindBuffer(GL_ARRAY_BUFFER, 0);   
}