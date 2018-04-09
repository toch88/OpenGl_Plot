
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

double time2 = 0.016;
double tick = 0;

int main(void)
{
    {
        DisplayManager &dispMngr = DisplayManager::getInstance();
        dispMngr.startup({800, 600});

        Renderer renderer;
        LineSegment line({0.0, 0.0}, {0.5, 0.5});

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(dispMngr.GetWindow()))
        {
            tick = glfwGetTime();
            if (tick > time2)
            {
                tick = 0;
                glfwSetTime(0);
                renderer.Clear();
                line.SetAngle(++line.angleInDeg);
                line.Update();
                for (std::shared_ptr<TexturedModel> &point : line.points)
                {
                    renderer.Draw(point);
                }
                glfwSwapBuffers(dispMngr.GetWindow());

                /* Poll for and process events */
                glfwPollEvents();
            }
        }
        glfwTerminate();
    }

    return 0;
}
