#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "src/Renderer.h"
#include "src/VertexBuffer.h"

int main(void)
{

    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, true);
    {
        static const float position[] = {
            -0.5f, //v0
            0.5f,

            -0.5f, //v1
            -0.5f,

            0.5f, //v2
            -0.5f};

        static const float position2[] = {
            0.5f, //v0
            0.5f,

            -0.5f, //v1
            0.5f,

            0.5f, //v2
            -0.5f
        };

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
        glBufferData(GL_ARRAY_BUFFER, sizeof(float)*3*2, position, GL_STATIC_DRAW_ARB);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindVertexArray(0);





        Shader shader("res/shaders/Basic.vert");
        shader.Bind();

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            glBindVertexArray(vao);

            glDrawArrays(GL_TRIANGLES,0,3);

            glBindVertexArray(0);
            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    //glDeleteProgram(program);
    glfwTerminate();
    return 0;
}
