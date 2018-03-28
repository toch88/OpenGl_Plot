#include "Renderer.h"

void Renderer::Draw(std::shared_ptr<RawModel> rawModel, const Shader &shader) const
{

    rawModel->getVAO()->Bind();
    shader.Bind();
    rawModel->getIBO()->Bind();

    glDrawElements(GL_TRIANGLES, rawModel->getIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(TexturedModel &texturedModel) 
{
   

    glDrawElements(GL_TRIANGLES, texturedModel.rawModel->getIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}