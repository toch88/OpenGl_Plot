#include "Renderer.h"

void Renderer::Draw(std::shared_ptr<RawModel> rawModel) const
{

    rawModel->getVAO()->Bind();
    this->_rscMngr.getResource<std::shared_ptr<Shader>>("BasicShader");
    rawModel->getIBO()->Bind();

    glDrawElements(GL_TRIANGLES, rawModel->getIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(TexturedModel &texturedModel)
{
    texturedModel.Bind();
    glDrawElements(GL_TRIANGLES, texturedModel.rawModel->getIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(std::shared_ptr<TexturedModel> texturedModel)
{

    texturedModel->Bind();
    glDrawElements(GL_TRIANGLES, texturedModel->rawModel->getIBO()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(Grid &grid)
{
    for (std::shared_ptr<LineSegment> line : grid.verticalLines)
    {
        for (std::shared_ptr<TexturedModel> point : line->points)
        {
            this->Draw(point);
        }
    }    
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}