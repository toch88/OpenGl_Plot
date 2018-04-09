#include "TexturedModel.h"

// TexturedModel::TexturedModel(){
    
// }

TexturedModel::TexturedModel(const glm::vec2 &position)
{

    Loader loader;
    std::array<float, 8> arrayPosition = this->createVertexPosition(position);

    this->rawModel = loader.loadToVAO<float>(arrayPosition);

    VertexBuffer *vbo_texture = new VertexBuffer(textCord, sizeof(float) * 2 * 4);
    VertexBufferLayout VertexTextureLayout;
    VertexTextureLayout.Push<float>(2);
    this->rawModel->getVAO()->AddBuffer(vbo_texture, VertexTextureLayout);
    this->rawModel->addIBO(new IndexBuffer(indices, 6));

    ResourceManager &rscMngr = ResourceManager::getInstance();
    this->shader = rscMngr.getResource<std::shared_ptr<Shader>>("BasicShader");
    this->texture = rscMngr.getResource<std::shared_ptr<Texture>>("point");
    this->Bind();

    this->shader->SetUniform1i("u_Texture", 0);
}

void TexturedModel::updatePosition(glm::vec2& pos){
    
}

void TexturedModel::Bind()
{   
    this->rawModel->BindModel();
    this->shader->Bind();
    this->texture ->Bind();
    
}

std::array<float, 8> TexturedModel::createVertexPosition(const glm::vec2 &P)
{
    float size = (sizeOfRetancle / 2);
    std::array<float, 8> array;

    array[0] = P.x - size; //vo
    array[1] = P.y - size;

    array[2] = P.x + size; //v1
    array[3] = P.y - size;

    array[4] = P.x + size; //v2
    array[5] = P.y + size;

    array[6] = P.x - size; //v3
    array[7] = P.y + size;

    return array;
}