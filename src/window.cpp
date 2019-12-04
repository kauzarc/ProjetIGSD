#include "window.h"

#define GLM_FORCE_RADIANS
#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

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

    m_projectionMatrix.value = glm::ortho(-1.f * 1024.f / 768.f, 1.f * 1024.f / 768.f, -1.f, 1.f, 1.f, -1.0f);
    m_viewMatrix.value = glm::mat4(1.f);
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
        m_controler.check(m_shader);

    } // Vérifie si on a appuyé sur la touche échap (ESC) ou si la fenêtre a été fermée
    while (glfwGetKey(m_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);
}