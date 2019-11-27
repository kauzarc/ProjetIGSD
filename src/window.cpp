#include "window.h"

#define GLM_FORCE_RADIANS
#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Window::Window() : m_renderer(1024, 768),
                   m_controler(m_window, m_projectionMatrix, m_viewMatrix, m_modelMatrix),
                   m_VAO(m_setup.getVAO()),
                   m_Texture(m_setup.getTexture()),
                   m_shader(m_setup.getShader())
{
    m_window = m_renderer.getWindow();

    m_modelMatrix.id = glGetUniformLocation(m_shader.getProgramId(), "u_modelMatrix");
    m_viewMatrix.id = glGetUniformLocation(m_shader.getProgramId(), "u_viewMatrix");
    m_projectionMatrix.id = glGetUniformLocation(m_shader.getProgramId(), "u_projectionMatrix");

    // m_projectionMatrix.value = glm::ortho(-1.0f * 768.0f / 1024.0f, 1.0f * 768.0f / 1024.0f, -1.0f * 1024.0f / 768.0f, 1.0f * 1024.0f / 768.0f, -3.0f, 3.0f);
    // m_viewMatrix.value = lookAt(
    //     glm::vec3(1.5 * cos(0), 1.5 * sin(0), -0.35), // where is the camara
    //     glm::vec3(0, 0, 0.1),                        //where it looks
    //     glm::vec3(0, 1.0, 0)                         // head is up
    // );
    // m_modelMatrix.value = glm::mat4(1.0);

    m_projectionMatrix.value = glm::mat4(1.0);
    m_viewMatrix.value = glm::mat4(1.0);
    m_modelMatrix.value = glm::mat4(1.0);

    m_shader.bind();

    glUniformMatrix4fv(m_modelMatrix.id, 1, GL_FALSE, glm::value_ptr(m_projectionMatrix.value));
    glUniformMatrix4fv(m_viewMatrix.id, 1, GL_FALSE, glm::value_ptr(m_viewMatrix.value));
    glUniformMatrix4fv(m_projectionMatrix.id, 1, GL_FALSE, glm::value_ptr(m_modelMatrix.value));

    m_shader.unbind();
}

void Window::run()
{

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    do
    {

        glClear(GL_COLOR_BUFFER_BIT);

        m_renderer.draw(m_shader, m_VAO[0], m_Texture[0]);

        // Swap buffers
        glfwSwapBuffers(m_window);
        glfwPollEvents();
        // m_controler.check(m_shader);

    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while (glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);
}