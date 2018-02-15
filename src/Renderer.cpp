#include "Renderer.h"
#include <iostream>

void APIENTRY openglCallbackFunction(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *userParam)
{
    (void)source;
    (void)type;
    (void)id;
    (void)severity;
    (void)length;
    (void)userParam;
    fprintf(stderr, "%s\n", message);
}