#include "renderer.h"
#include "shader.h"
#include "vertexbuffer.h"
#include "arraybuffer.h"
#include "layoutbuffer.h"

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

    VertexBuffer vbo;
    LayoutBuffer layout;
    
    vbo.add(18, position);
    layout.push(GL_FLOAT, 3, 18);

    ArrayBuffer vao;
    vao.addBuffer(vbo, layout);

    float red = 1;
    float increment = -0.05;

    GLint location = glGetUniformLocation(shader.getProgramId(), "u_red");

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {
        if (red > 1.0)
        {
            increment = -0.05;
        }
        else if (red < 0.0)
        {
            increment = 0.05;
        }

        red += increment;
        glUniform1f(location, red);

        glClear(GL_COLOR_BUFFER_BIT);

        r.draw(shader, vao);

        // Swap buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();

    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while (glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);

    return 0;
}