#include "window.h"

#define GLM_FORCE_RADIANS
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Window::Window() : m_renderer(1024, 768),
                   m_VAO(m_setup.getVAO()),
                   m_Texture(m_setup.getTexture()),
                   m_shader(m_setup.getShader())
{
    m_window = m_renderer.getWindow();
}

void Window::run()
{
    GLuint modelMatrixLocation = glGetUniformLocation(m_shader.getProgramId(), "u_modelMatrix");
    GLuint viewMatrixLocation = glGetUniformLocation(m_shader.getProgramId(), "u_viewMatrix");
    GLuint projectionMatrixLocation = glGetUniformLocation(m_shader.getProgramId(), "u_projectionMatrix");

    glm::mat4 projectionMatrix = glm::ortho(-1.0f * 768 / 1024, 1.0f * 768 / 1024, -1.0f * 1024 / 768, 1.0f * 1024 / 768, -3.0f, 3.0f);
    glm::mat4 viewMatrix = glm::lookAt(
        glm::vec3(0, 0, 1), // where is the camara
        glm::vec3(0, 0, 0), //where it looks
        glm::vec3(0, 1, 0)  // head is up
    );
    glm::mat4 modelMatrix(1.0);

    m_shader.bind();

    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    m_shader.unbind();

    ////////////////////////////////////////////

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {

        glClear(GL_COLOR_BUFFER_BIT);

        m_renderer.draw(m_shader, m_VAO[0], m_Texture[0]);

        // Swap buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();

    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while (glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);
}