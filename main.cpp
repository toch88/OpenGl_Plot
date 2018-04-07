
#include "src/DisplayManager.h"
#include "src/Renderer.h"
#include "src/Loader.h"
#include "src/Test.h"
#include <memory>
#include <experimental/array>
#include <math.h>
#include "src/vendor/glm/glm.hpp"
#include "src/vendor/glm/gtc/matrix_transform.hpp"
#include "src/ResourceManager.h"
#include "src/TexturedModel.h"
#include <cmath>
#include <array>
#include <iostream>
#include <future>
#include "src/LineSegment.h"
#include <Windows.h>

void showTime(int test)
{
    while (1)
    {
        //std::cout << glfwGetTime() <<"Test varible: " <<test<<std::endl;
    }
}

int main(void)
{
    {
        DisplayManager &dispMngr = DisplayManager::getInstance();
        dispMngr.startup({800, 600});

       

        LineSegment line({0.0f, 0.0f}, {-1.0, -1.0});
        //Grid grid(0.1);

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
            // renderer.Draw(grid);
            glfwSwapBuffers(dispMngr.GetWindow());

            /* Poll for and process events */
            glfwPollEvents();
        }
        glfwTerminate();
    }
  
    return 0;
}
