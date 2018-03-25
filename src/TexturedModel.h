#pragma once
#include <memory>
#include <iostream>
#include "vendor/glm/glm.hpp"
#include "vendor/glm/vec2.hpp"
#include "RawModel.h"
#include "Texture.h"
#include <string>



class TexturedModel
{
  public:
    std::shared_ptr<RawModel> rawModel;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<Shader> shader;
    float sizeOfRetancle = 0.01;

    TexturedModel(const glm::vec2 &position, const std::string &textureFilePath, const std::string &shaderFilePath = "res/shaders/Basic.vert");
    std::array<float, 8> createVertexPosition(const glm::vec2 &position);
};

static const float textCord[] = {
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f};

static const unsigned int indices[] =
    {
        0,
        1,
        2,
        2,
        3,
        0,
};
