#include "Renderer.h"


void Renderer::Draw(std::shared_ptr<RawModel> rawModel, const IndexBuffer &ib, const Shader &shader) const
{
    
    rawModel->getVAO()->Bind();
    shader.Bind();     

    ib.Bind();

    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
void Renderer::Clear(){
      glClear(GL_COLOR_BUFFER_BIT);
}