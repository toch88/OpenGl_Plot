#pragma once 
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class RawModel
{
    std::vector<VertexArray*> VAOs;
    std::vector<IndexBuffer*> IBOs;
    std::vector<Shader*> Shaders;
public:    
    RawModel();
    void addVAO(VertexArray* vao);
    void addIBO(IndexBuffer* ibo);
    void addShader(Shader* shader);
    void BindModel();

    VertexArray* getVAO(){return this->VAOs[0];}
    void bind();
    ~RawModel();
};