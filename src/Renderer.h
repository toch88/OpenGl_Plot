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
#include "ResourceMenager.h"
#include "Grid.h"


class Renderer
{
  public:
    void Clear();
    
    void Draw(TexturedModel& texturedModel);
    void Draw(std::shared_ptr<RawModel> vao) const;
    void Draw(std::shared_ptr<TexturedModel> texturedModel);
    void Draw(Grid& grid);

   
  private:
    ResourceMenager &_rscMngr=ResourceMenager::getInstance();  

};


