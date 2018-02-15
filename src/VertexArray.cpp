#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray()
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
    unsigned int offset=(intptr_t)0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto &element = elements[i];
        //which attrib you one enable in actual binded buffer array
        glEnableVertexAttribArray(0);
        //GL attributes telling how memory have to be interpreted
        //Layout of memory !
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStrid(), (void *) (intptr_t)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
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