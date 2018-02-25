#include "VertexArray.h"

VertexArray::VertexArray()
    : _currentAttrID(0)
{
    glGenVertexArrays(1, &_RendererID);
}
VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &_RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    Bind();
    vb.Bind();
    const auto &elements = layout.GetElements();
    unsigned int offset = (intptr_t)0;

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto &element = elements[i];       
        glVertexAttribPointer(this->_currentAttrID,
                              element.count,
                              element.type,
                              element.normalized,
                              layout.GetStrid(),
                              reinterpret_cast<void *>(element.offset));                              
        this->_currentAttrID++;
        glEnableVertexAttribArray(this->_currentAttrID);    
    }
}

void VertexArray::Bind() const
{
    glBindVertexArray(_RendererID);
}
void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}