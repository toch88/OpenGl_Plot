#include "VertexArray.h"

VertexArray::VertexArray()
:_attrID(0)
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
    std::cout<<_attrID<<std::endl;

    for (unsigned int i = _attrID; i < elements.size()+_attrID; i++)
    {
        const auto &element = elements[i];
        //which attrib you one enable in actual binded buffer array
        glEnableVertexAttribArray(i);
        //GL attributes telling how memory have to be interpreted
        //Layout of memory !
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStrid(), reinterpret_cast<void*>(offset));
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
        
    }
    _attrID=elements.size()+_attrID;
}

void VertexArray::Bind() const
{
    glBindVertexArray(_RendererID);
}
void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}