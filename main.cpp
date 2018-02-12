#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float position[6] = {
        -0.5f,
        -0.5f,

        0.0f,
        0.5f,

        0.5f,
        -0.5f,
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);              //I am getting buffer "ID"
    glBindBuffer(GL_ARRAY_BUFFER, buffer); //This buffer is a ARRAY
    glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float),position, GL_STATIC_DRAW); //Fill buffer with data from position

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
      
        glDrawArrays(GL_TRIANGLES, 0, 3); //it will be drawing this what is selected (binded)
        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
