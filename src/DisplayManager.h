#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "ResourceManager.h"
#include "./vendor/glm/glm.hpp"

void APIENTRY openglCallbackFunction(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *userParam);

class DisplayManager
{
  private:
    GLFWwindow *_window;
    unsigned int init();
    void enableDebug();
    void prepare();
    //Singleton so we have to disable all of public default constructor
    DisplayManager();
    DisplayManager(DisplayManager const &);
    void operator=(DisplayManager const &);

    void LoadResource();

  public:
    static DisplayManager &getInstance()
    {
        static DisplayManager instance;
        return instance;
    }
    int height, width;

    ~DisplayManager();
    virtual void startup(glm::vec2 wndSize);

    inline GLFWwindow *GetWindow() { return this->_window; }
};