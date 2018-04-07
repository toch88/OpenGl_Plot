#pragma once
#include "ResourceManager.h"
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
    float sizeOfRetancle = 0.007;
    TexturedModel();
    TexturedModel(const glm::vec2 &position);
    std::array<float, 8> createVertexPosition(const glm::vec2 &position);
    void Bind();
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

