#include <memory>
#include <iostream>
#include "vendor/glm/glm.hpp"
#include "vendor/glm/vec2.hpp"
#include "RawModel.h"
#include "Texture.h"
#include <string>

class TexturedModel{
public:
    std::shared_ptr<RawModel> rawModel;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<Shader> shader;     
   
    TexturedModel(const glm::vec2& position, const std::string& textureFilePath);     
};