#include "Renderer.h"


void Renderer::Draw(std::shared_ptr<RawModel> rawModel, const IndexBuffer &ib, const Shader &shader) const
{
    
    rawModel->getVAO()->Bind();
    shader.Bind();     

    ib.Bind();

    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}


void Renderer::Draw(const TexturedModel& texturedModel) const
{
    texturedModel.rawModel->getVAO()->Bind();   
    texturedModel.shader->Bind();     

    texturedModel.rawModel->getIBO()->Bind();

    //glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}


void Renderer::Clear(){
      glClear(GL_COLOR_BUFFER_BIT);
}