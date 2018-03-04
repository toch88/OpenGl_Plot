#pragma once
#include <memory>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <map>
#include <algorithm>

class VertexArray
{
private:
  unsigned int _RendererID;
  unsigned int _currentAttrID;
  std::map<VertexBuffer*, VertexBufferLayout>* _bufforsMap;

public:
  VertexArray();
  ~VertexArray();

  void AddBuffer(VertexBuffer* vb, const VertexBufferLayout &layout);

  void Bind() const;
  void Unbind();
  void clearMapPtr();
  

   unsigned int GetVaoId(){return this->_RendererID; };
};