#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray{
    private:
      unsigned int _RendererID; 
      unsigned int _attrID;
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

        void Bind() const;
        void Unbind() const;
};