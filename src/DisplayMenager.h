#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


void APIENTRY openglCallbackFunction(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *userParam);

class DisplayMenager{
private: 
    GLFWwindow* _window;
    unsigned int init(); 
    void enableDebug();

public:
    DisplayMenager();
    ~DisplayMenager();
    void startup();
    virtual void prepare();
    
     

    inline GLFWwindow* GetWindow(){return this->_window;}     
    

};