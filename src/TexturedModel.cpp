#include "TexturedModel.h"
#include "DisplayMenager.h"
#include "Loader.h"

TexturedModel::TexturedModel(const glm::vec2 &position, const std::string &textureFilePath, const std::string &shaderFilePath)
{
    std::cout << "x: " << position.x << std::endl;
    std::cout << "y: " << position.y << std::endl;
    std::cout << "TextureFile:" << textureFilePath << std::endl;

    Loader loader;
    std::array<float, 8> arrayPosition = this->createVertexPosition(position);
    this->rawModel = loader.loadToVAO<float>(arrayPosition);

    VertexBuffer *vbo_texture = new VertexBuffer(textCord, sizeof(float) * 2 * 4);
    VertexBufferLayout VertexTextureLayout;
    VertexTextureLayout.Push<float>(2);
    this->rawModel->getVAO()->AddBuffer(vbo_texture, VertexTextureLayout);

    this->shader = std::make_shared<Shader>(shaderFilePath);
    this->shader->Bind();
    this->shader->SetUniform1i("u_Texture", 0);

    this->texture = std::make_shared<Texture>(textureFilePath);
    this->texture->Bind();

    this->rawModel->addIBO(new IndexBuffer(indices,6));
    this->rawModel->getIBO()->Bind();
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