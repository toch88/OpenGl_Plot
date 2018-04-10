#include "VertexArray.h"

VertexArray::VertexArray()
    : _currentAttrID(0)
{
    glGenVertexArrays(1, &_RendererID);
}
VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &_RendererID);
    this->clearMapPtr();
}

std::shared_ptr<VertexBuffer> VertexArray::getVBO(const std::string& nameToCompare)
{
   for (std::pair<std::shared_ptr<VertexBuffer>, VertexBufferLayout> element : this->_bufforsMap)
    {
      //std::cout<<element.first->name<<std::endl;
      if(element.first->name==nameToCompare){
          return element.first;
      }
    }
    
}

void VertexArray::AddBuffer(std::shared_ptr<VertexBuffer> vbo, const VertexBufferLayout &layout)
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
    this->_bufforsMap.emplace(vbo, layout);
}

void VertexArray::Bind() const
{
    glBindVertexArray(_RendererID);
}
void VertexArray::Unbind()
{
    glBindVertexArray(0);
}

void VertexArray::clearMapPtr()
{

    for (std::pair<std::shared_ptr<VertexBuffer>, VertexBufferLayout> element : this->_bufforsMap)
    {
        element.first->Unbind();
    }
}