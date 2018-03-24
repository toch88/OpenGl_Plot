#include "src/DisplayMenager.h"
#include "src/Renderer.h"
#include "src/Shader.h"
#include "src/VertexBuffer.h"
#include "src/IndexBuffer.h"
#include "src/Loader.h"
#include "src/Test.h"
#include <memory>
#include <experimental/array>
#include <math.h>
#include "src/Texture.h"
#include "src/TexturedModel.h"
#include "src/vendor/glm/glm.hpp"
#include "src/vendor/glm/gtc/matrix_transform.hpp"

int main(void)
{

    DisplayMenager& dispMngr=DisplayMenager::getInstance();
    dispMngr.startup();

    auto position = array_of<float>(
        -0.01f, //v0
        0.01f,

        -0.01f, //v1
        -0.01f,

        0.01f, //v2
        -0.01f,

        0.01f,
        0.01f //v3
    );

    auto color = array_of<float>(
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
        0.5f);

    static const unsigned int indices[] =
        {
            0,
            1,
            2,
            2,
            3,
            0,
        };

    static const float textCord[] = {
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f
    };
   
    TexturedModel textureModel(glm::vec2(500,500), "filePath");

    
  
    Loader loader;
    std::shared_ptr<RawModel> rawModel = loader.loadToVAO<float>(position, color);

    VertexBuffer *vbo_texture = new VertexBuffer(textCord, sizeof(float)* 2 * 4);
    VertexBufferLayout layout3;
    layout3.Push<float>(2);
    rawModel->getVAO()->AddBuffer(vbo_texture,layout3);

    Renderer renderer;
    Shader shader("res/shaders/Basic.vert");   
    shader.Bind();
    
    shader.SetUniform1i("u_Texture", 0);
    Texture texture("res/point.png");
    texture.Bind(); 
   

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
