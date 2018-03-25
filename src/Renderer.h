#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "RawModel.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include <iostream>
#include <memory>
#include "TexturedModel.h"


class Renderer
{
  public:
    void Clear();
    
    void Draw(const TexturedModel& texturedModel) const;
    void Draw(std::shared_ptr<RawModel> vao, const IndexBuffer &ib, const Shader &shader) const;
   
};


