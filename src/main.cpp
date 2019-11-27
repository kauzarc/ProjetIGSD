#include <iostream>

#include "renderer.h"
#include "shader.h"
#include "vertexbuffer.h"
#include "arraybuffer.h"
#include "layoutbuffer.h"
#include "texture.h"

#define GLM_FORCE_RADIANS
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main(int argc, char const *argv[])
{
    Renderer r(1024, 768);
    Shader shader;
    shader.init();

    GLFWwindow *m_window = r.getWindow();

    float position[18] = {
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0,

        0.5, -0.5, 0,
        -0.5, 0.5, 0,
        0.5, 0.5, 0.0};

    float color[18] =
        {
            1, 0, 0,
            0, 1, 0,
            1, 0, 0,

            0, 1, 0,
            1, 0, 0,
            0, 1, 0};

    float textureCoord[12] =
        {
            0, 0,
            1, 0,
            0, 1,

            1, 0,
            0, 1,
            1, 1};

    VertexBuffer vbo;
    LayoutBuffer layout;

    vbo.add(18, position);
    layout.push(GL_FLOAT, 3, 18);

    vbo.add(18, color);
    layout.push(GL_FLOAT, 3, 18);

    vbo.add(12, textureCoord);
    layout.push(GL_FLOAT, 2, 12);

    ArrayBuffer vao;
    vao.addBuffer(vbo, layout, 6);

    Texture texture("images/Arsenal.png");

    GLuint modelMatrixLocation = glGetUniformLocation(shader.getProgramId(), "u_modelMatrix");
    GLuint viewMatrixLocation = glGetUniformLocation(shader.getProgramId(), "u_viewMatrix");
    GLuint projectionMatrixLocation = glGetUniformLocation(shader.getProgramId(), "u_projectionMatrix");

    glm::mat4 projectionMatrix(1.0);
    glm::mat4 viewMatrix(1.0);
    glm::mat4 modelMatrix(1.0);

    glUseProgram(shader.getProgramId());

    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glUseProgram(0);


    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {

        glClear(GL_COLOR_BUFFER_BIT);

        r.draw(shader, vao, texture);

        // Swap buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();

    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while (glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);

    return 0;
}