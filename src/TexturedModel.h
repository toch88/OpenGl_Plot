#pragma once
#include "ResourceMenager.h"
#include "RawModel.h"
#include "vendor/glm/glm.hpp"
#include <iostream>
#include "Loader.h"

class TexturedModel
{
  public:
    std::shared_ptr<RawModel> rawModel;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<Shader> shader;
    float sizeOfRetancle = 0.1;

    TexturedModel(const glm::vec2 &position, const std::string &textureFilePath, const std::string &shaderFilePath = "res/shaders/Basic.vert");
    std::array<float, 8> createVertexPosition(const glm::vec2 &position);
    void Bind();
};


