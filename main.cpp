
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
#include "src/EventDispatcher.h"
#include "src/LineSegment.h"
#include "src/Timer.h"
#include "src/TimerListener.h"
using namespace std::literals;

int main(void)
{  
    DisplayManager &dispMngr = DisplayManager::getInstance();
    dispMngr.startup({800, 600});
   
    Renderer renderer;
    //LineSegment line({0.0, 0.0}, {0.5, 0.5});

    while (!glfwWindowShouldClose(dispMngr.GetWindow()))
    {

        renderer.Clear();
        // line.SetAngle(line.angleInDeg += 0.1);
        // if (line.angleInDeg == 360)
        // {
        //     line.angleInDeg = 0;
        // }
        // line.Update();
        // for (std::shared_ptr<TexturedModel> &point : line.points)
        // {
        //     renderer.Draw(point);
        // }

        glfwSwapBuffers(dispMngr.GetWindow());
        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
