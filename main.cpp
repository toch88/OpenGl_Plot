#include "src/DisplayMenager.h"
#include "src/Renderer.h"
#include "src/Shader.h"
#include "src/VertexBuffer.h"
#include "src/IndexBuffer.h"
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

        0.5,
        0.5  //v3
        };

    static const float position2[] = {
        0.5f, //v0
        0.5f, 0.5,

        -0.5f, //v1
        0.5f, 1,

        0.5f, //v2
        -0.5f, 0};

    static const unsigned int indices[] =
        {
            0,1,2,
            2,3,0            
        };

    VertexArray vao;
    VertexBuffer vbo(position, sizeof(float) * 2 * 4);

    VertexBufferLayout layout;
    layout.Push<float>(2);
    vao.AddBuffer(vbo, layout);
    Shader shader("res/shaders/Basic.vert");
    IndexBuffer ib(indices, 6);
    Renderer renderer;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(dispMngr.GetWindow()))
    {

        renderer.Clear();
        renderer.Draw(vao, ib, shader);
        /* Swap front and back buffers */
        glfwSwapBuffers(dispMngr.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    //glDeleteProgram(program);
    glfwTerminate();
    return 0;
}
