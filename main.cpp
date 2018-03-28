
#include "src/DisplayMenager.h"
#include "src/Renderer.h"
#include "src/Loader.h"
#include "src/Test.h"
#include <memory>
#include <experimental/array>
#include <math.h>
#include "src/vendor/glm/glm.hpp"
#include "src/vendor/glm/gtc/matrix_transform.hpp"
// #include "src/ResourceMenager.h"

static const float textCord[] = {
    0.0f, 1.0f,
    0.0f, 0.0f,
    1.0f, 0.0f,
    1.0f, 1.0f};

static const unsigned int indices[] =
    {
        0,
        1,
        2,
        2,
        3,
        0,
};

std::array<float, 8> createVertexPosition(const glm::vec2 &P)
{
    float sizeOfRetancle=0.1;
    float size = (sizeOfRetancle / 2);
    std::array<float, 8> array;

    array[0] = P.x - size; //vo
    array[1] = P.y - size;

    array[2] = P.x + size; //v1
    array[3] = P.y - size;

    array[4] = P.x + size; //v2
    array[5] = P.y + size;

    array[6] = P.x - size; //v3
    array[7] = P.y + size;

    return array;
}

int main(void)
{

    DisplayMenager &dispMngr = DisplayMenager::getInstance();
    dispMngr.startup({800, 600});

    Loader loader;
    std::array<float, 8> arrayPosition = createVertexPosition({0.0f, 0.0f});
    std::shared_ptr<RawModel> rawModel = loader.loadToVAO<float>(arrayPosition);

    VertexBuffer *vbo_texture = new VertexBuffer(textCord, sizeof(float) * 2 * 4);
    VertexBufferLayout VertexTextureLayout;
    VertexTextureLayout.Push<float>(2);
    rawModel->getVAO()->AddBuffer(vbo_texture, VertexTextureLayout);

    Shader tempShader("res/shaders/Basic.vert");
    Texture tempTexture("res/point.png");

    tempShader.Bind();
    tempShader.SetUniform1i("u_Texture", 0);
    tempTexture.Bind();

    rawModel->addIBO(new IndexBuffer(indices, 6));
    rawModel->getIBO()->Bind();

    Renderer renderer;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(dispMngr.GetWindow()))
    {
        renderer.Clear();
        renderer.Draw(rawModel, tempShader);
        // renderer.Draw(textureModel2);
        // renderer.Draw(textureModel3);
        // renderer.Draw(textureModel4);
        glfwSwapBuffers(dispMngr.GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    //glDeleteProgram(program);
    glfwTerminate();

    return 0;
}
