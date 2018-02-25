#include "src/DisplayMenager.h"
#include "src/Renderer.h"
#include "src/VertexBuffer.h"

int main(void)
{

    DisplayMenager dispMngr;
    dispMngr.startup();    
    
        static const float position[] = {
            -0.5f, //v0
            0.5f, 1,

            -0.5f, //v1
            -0.5f, 0.5,

            0.5f, //v2
            -0.5f, 0};

        static const float position2[] = {
            0.5f, //v0
            0.5f, 0.5,

            -0.5f, //v1
            0.5f, 1,

            0.5f, //v2
            -0.5f, 0};

        static const unsigned int indices[] =
            {
                0,
                1,
                2,
            };
        unsigned int vao, vbo;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * 3, position, GL_STATIC_DRAW_ARB);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), reinterpret_cast<void *>(0));
        glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), reinterpret_cast<void *>(sizeof(GLfloat) * 2));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        unsigned int vao2, vbo2;
        glGenVertexArrays(1, &vao2);
        glBindVertexArray(vao2);

        glGenBuffers(1, &vbo2);
        glBindBuffer(GL_ARRAY_BUFFER, vbo2);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * 3, position2, GL_STATIC_DRAW_ARB);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), reinterpret_cast<void *>(0));
        glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), reinterpret_cast<void *>(sizeof(GLfloat) * 2));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        Shader shader("res/shaders/Basic.vert");
        shader.Bind();

        // init gui state

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(dispMngr.GetWindow()))
        {
            glBindVertexArray(vao);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            glBindVertexArray(0);

            glBindVertexArray(vao2);

            glDrawArrays(GL_TRIANGLES, 0, 3);

            glBindVertexArray(0);
            /* Swap front and back buffers */
            glfwSwapBuffers(dispMngr.GetWindow());

            /* Poll for and process events */
            glfwPollEvents();
        }
    
    //glDeleteProgram(program);
    glfwTerminate();
    return 0;
}
