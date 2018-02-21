#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer
{
  public:
    void Clear();
    void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;
};

void APIENTRY openglCallbackFunction(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *, const void *);
