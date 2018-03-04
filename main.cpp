#include "src/DisplayMenager.h"
#include "src/Renderer.h"
#include "src/Shader.h"
#include "src/VertexBuffer.h"
#include "src/IndexBuffer.h"
#include "src/Loader.h"
#include "src/Test.h"
#include <memory>
#include <experimental/array>

int main(void)
{

    DisplayMenager dispMngr;
    dispMngr.startup();

    static const float position[] = {
        -0.5f, //v0
        0.5f,

        -0.5f, //v1
        -0.5f,

        0.5f, //v2
        -0.5f,

        0.5f,
        0.5f //v3
    };

    auto arr = array_of<float>(
        -0.5f, //v0
        0.5f,

        -0.5f, //v1
        -0.5f,

        0.5f, //v2
        -0.5f,

        0.5f,
        0.5f //v3
    );

    static const float color[] = {
        1.0f,
        0.0f,
        0.0f,
        0.0f,
        1.0f,
        0.0f,
        0.0f,
        0.0f,
        1.0f,
        0.5f,
        0.5f,
        0.5f,
    };

    static const unsigned int indices[] =
        {
            0,
            1,
            2,
            2,
            3,
            0,
        };  

    Loader loader;
    std::shared_ptr<RawModel> rawModel = loader.loadToVAO<float>(arr, color);
    Renderer renderer;
    Shader shader("res/shaders/Basic.vert");
    shader.SetUniform4f("u_ourColor", 0.0f, 1.0f, 0.0f, 0.0f);
    shader.Bind();

    IndexBuffer ib(indices, 6);
    ib.Bind();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(dispMngr.GetWindow()))
    {
        renderer.Clear();
        renderer.Draw(rawModel, ib, shader);

        glfwSwapBuffers(dispMngr.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    //glDeleteProgram(program);
    glfwTerminate();

    return 0;
}
