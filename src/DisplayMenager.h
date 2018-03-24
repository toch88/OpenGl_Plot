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
    //Singleton so we have to disable all of public default constructor 
    DisplayMenager();
    DisplayMenager(DisplayMenager const&);
    void operator=(DisplayMenager const&);    

public:
    static DisplayMenager& getInstance(){
        static DisplayMenager instance;
        return instance;
    }
    ~DisplayMenager();
    void startup();
    virtual void prepare();
    
     

    inline GLFWwindow* GetWindow(){return this->_window;}     
    

};