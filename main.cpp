#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string &filepath)
{
    std::ifstream stream(filepath);
    std::cerr << "Error";
    std::string line;
    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                //set vertex
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                //set fragment
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }

    return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *)(alloca(length * sizeof(char)));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "fragment ") << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

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

    float position[] = {
        -0.5f, //0
        -0.5f,

        0.5f, //1
        -0.5f,

        0.5f, //2
        0.5f,

        -0.5f, //3
        0.5f,
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };



    unsigned int buffer;
    glGenBuffers(1, &buffer);                                                       //I am getting buffer "ID"
    glBindBuffer(GL_ARRAY_BUFFER, buffer);                                          //This buffer is a ARRAY
    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), position, GL_STATIC_DRAW); //Fill buffer with data from position
    //which attrib you one enable in actual binded buffer array
    glEnableVertexAttribArray(0);
    //GL attributes telling how memory have to be interpreted
    //Layout of memory !
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    unsigned int ibo; //index object buffer
    glGenBuffers(1, &ibo);                                                       //I am getting buffer "ID"
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);                                          //This buffer is a ELEMENT_ARRAY
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,  6 * sizeof(unsigned int), indices, GL_STATIC_DRAW); //Fill buffer with data from indices

    ShaderProgramSource source = ParseShader("res/shaders/Basic.vert");
    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

       // glDrawArrays(GL_TRIANGLES, 0, 6); //it will be drawing this what is selected (binded)
       glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    //glDeleteProgram(program);
    glfwTerminate();
    return 0;
}
