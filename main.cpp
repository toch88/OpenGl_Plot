
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

double prev_tick = 0;
double tick = 0;
double deltaTime = 0;
double posX = 0;
double posY = 0;

int main(void)
{

    {
        DisplayManager &dispMngr = DisplayManager::getInstance();
        dispMngr.startup({800, 600});
        Renderer renderer;
        // TexturedModel point({0.5f, 0.5f});
        // TexturedModel point2({0.5f, 0.5f});
        // std::cout << point.rawModel->getVAO()->getVBO("position")->name << std::endl;
        LineSegment line({0.0, 0.0}, {0.5, 0.5});

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(dispMngr.GetWindow()))
        {

            renderer.Clear();
            // point.rawModel->getVAO()->getVBO("position")->Update(point.createVertexPosition({posX += 0.001, 0})._M_elems);
            // point2.rawModel->getVAO()->getVBO("position")->Update(point2.createVertexPosition({0, posY += 0.001})._M_elems);
            // renderer.Draw(point);
            // renderer.Draw(point2);

            line.SetAngle(line.angleInDeg+=0.1);
            if (line.angleInDeg == 360)
            {
                line.angleInDeg = 0;
            }
            line.Update();
            for (std::shared_ptr<TexturedModel> &point : line.points)
            {
                renderer.Draw(point);
            }

            glfwSwapBuffers(dispMngr.GetWindow());
            /* Poll for and process events */
            glfwPollEvents();
        }
        glfwTerminate();
    }

    return 0;
}
