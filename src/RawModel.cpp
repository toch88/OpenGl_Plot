#include "RawModel.h"
#include <map>
#include <algorithm>

RawModel::RawModel() {}

void RawModel::addVAO(VertexArray *vao)
{
    this->VAOs.emplace_back(vao);
}

void RawModel::addIBO(IndexBuffer *ibo)
{
    this->IBOs.emplace_back(ibo);
}

void RawModel::BindModel()
{
    this->VAOs[0]->Bind();
    this->IBOs[0]->Bind();

}


RawModel::~RawModel()
{

    for (VertexArray *element : this->VAOs)
    {
        delete element;
    }

    for (IndexBuffer *element : this->IBOs)
    {
        delete element;
    }
}