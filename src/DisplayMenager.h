#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "vendor/glm/glm.hpp"
#include "ResourceMenager.h"

void APIENTRY openglCallbackFunction(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *userParam);

class DisplayMenager
{
  private:
    GLFWwindow *_window;
    unsigned int init();
    void enableDebug();
    void prepare();
    ResourceMenager &_rscMngr=ResourceMenager::getInstance();
    //Singleton so we have to disable all of public default constructor
    DisplayMenager();
    DisplayMenager(DisplayMenager const &);
    void operator=(DisplayMenager const &);

    void LoadResource();

  public:
    static DisplayMenager &getInstance()
    {
        static DisplayMenager instance;
        return instance;
    }
    int height, width;

    ~DisplayMenager();
    virtual void startup(glm::vec2 wndSize);
   

    inline GLFWwindow *GetWindow() { return this->_window; }
};