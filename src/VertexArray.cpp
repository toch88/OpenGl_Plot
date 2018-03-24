#include "VertexArray.h"

VertexArray::VertexArray()
    : _currentAttrID(0)
{
    glGenVertexArrays(1, &_RendererID);
    this->_bufforsMap = new std::map<VertexBuffer *, VertexBufferLayout>();
}
VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &_RendererID);
    this->clearMapPtr();
}

void VertexArray::AddBuffer(VertexBuffer *vbo, const VertexBufferLayout &layout)
{
    Bind();
    vbo->Bind();
    const auto &elements = layout.GetElements();

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto &element = elements[i];
        glVertexAttribPointer(this->_currentAttrID,
                              element.count,
                              element.type,
                              element.normalized,
                              layout.GetStrid(),
                              reinterpret_cast<void *>(element.offset));

        glEnableVertexAttribArray(this->_currentAttrID);
        this->_currentAttrID++;
    }
    this->_bufforsMap->emplace(vbo, layout);
}

void VertexArray::Bind() const
{
    glBindVertexArray(_RendererID);
}
void VertexArray::Unbind()
{
    glBindVertexArray(0);
}

void VertexArray::clearMapPtr(){
    
    for(std::pair<VertexBuffer* , VertexBufferLayout> element: *(this->_bufforsMap)){
        element.first->Unbind();  
        delete(element.first);     
    } 
    /*
    std::map<VertexBuffer*, VertexBufferLayout>::iterator it = this->_bufforsMap->begin();
    while (it != this->_bufforsMap->end())
    {
        it->first->Unbind();
        it->second.~VertexBufferLayout();
        it++;
    }*/
}