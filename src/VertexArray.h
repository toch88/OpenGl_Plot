#pragma once
#include <memory>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <map>
#include <algorithm>
#include <memory>

class VertexArray
{
private:
  unsigned int _RendererID;
  unsigned int _currentAttrID;
  std::map<std::shared_ptr<VertexBuffer>, VertexBufferLayout> _bufforsMap;

public:
  VertexArray();
  ~VertexArray();

  void AddBuffer(std::shared_ptr<VertexBuffer> vbo, const VertexBufferLayout &layout);
  std::shared_ptr<VertexBuffer> getVBO(const std::string& nameToCompare);

  void Bind() const;
  void Unbind();
  void clearMapPtr();
  

   unsigned int GetVaoId(){return this->_RendererID; };
};