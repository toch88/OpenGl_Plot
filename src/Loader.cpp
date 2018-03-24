#include "Loader.h"

std::shared_ptr<RawModel> Loader::loadToVAO(const void *position, const void *color)
{
    VertexArray *vao = new VertexArray();
    vao->Bind();
    
    VertexBuffer *vbo = new VertexBuffer(position, sizeof(float) * 2 * 4);
    VertexBufferLayout layout;
    layout.Push<float>(2);
    vao->AddBuffer(vbo, layout);
    
    std::shared_ptr<RawModel> rawModel(new RawModel());
    rawModel->addVAO(vao);
    return rawModel;
}


Loader::Loader()
{
}

Loader::~Loader()
{
}
