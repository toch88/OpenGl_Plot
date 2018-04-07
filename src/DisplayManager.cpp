#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
}

DisplayManager::~DisplayManager()
{
}

void DisplayManager::startup(glm::vec2 wndSize)
{
    this->width = wndSize.x;
    this->height = wndSize.y;
    this->init();
    this->enableDebug();
    this->prepare();
}

void DisplayManager::enableDebug()
{
    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    //glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, true);
}

unsigned int DisplayManager::init()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    this->_window = glfwCreateWindow(DisplayManager::width, DisplayManager::height, "PLOT", NULL, NULL);
    if (!this->_window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(this->_window);
    glfwSwapInterval(0);
    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;
}

void DisplayManager::prepare()
{
    //SETUP THE BLENDING MODE r-(1-a) g-(1-a) b-(1-a)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    this->LoadResource();
}

void DisplayManager::LoadResource()
{
    ResourceManager &_rscMngr = ResourceManager::getInstance();
    std::shared_ptr<Shader> tempShader(new Shader("res/shaders/Basic.vert"));
    _rscMngr.Add<Shader>("BasicShader", tempShader);
    std::shared_ptr<Texture> tempTexture(new Texture("res/point.png"));
    _rscMngr.Add<Texture>("point", tempTexture);
}

void APIENTRY openglCallbackFunction(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *userParam)
{
    (void)source;
    (void)type;
    (void)id;
    (void)severity;
    (void)length;
    (void)userParam;
    fprintf(stderr, "%s\n\n%d", message, severity);
}