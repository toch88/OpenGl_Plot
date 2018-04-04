
#include "src/DisplayMenager.h"
#include "src/Renderer.h"
#include "src/Loader.h"
#include "src/Test.h"
#include <memory>
#include <experimental/array>
#include <math.h>
#include "src/vendor/glm/glm.hpp"
#include "src/vendor/glm/gtc/matrix_transform.hpp"
#include "src/ResourceMenager.h"
#include "src/TexturedModel.h"
#include <cmath>
#include <array>
#include <iostream>
#include <future>
#include "src/LineSegment.h"

void showTime(int test)
{
    while (1)
    {
        //std::cout << glfwGetTime() <<"Test varible: " <<test<<std::endl;
    }
}

int main(void)
{

    DisplayMenager &dispMngr = DisplayMenager::getInstance();
    dispMngr.startup({800, 600});

    dispMngr.prepare();
    
    LineSegment line({0.0f, 0.0f}, {-1.0, -1.0});  

    Renderer renderer;
    int test = 1;
    auto fut = std::async(showTime, test);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(dispMngr.GetWindow()))
    {
        
        renderer.Clear();
        for(std::shared_ptr<TexturedModel> point: line.points){
            renderer.Draw(point);
        }    
        glfwSwapBuffers(dispMngr.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    //glDeleteProgram(program);
    glfwTerminate();

    return 0;
}
