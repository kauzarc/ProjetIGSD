#include "controler.h"

#define GLM_FORCE_RADIANS
#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cmath>
#include <iostream>

Controler::Controler(
    GLFWwindow *&window, Uniform<glm::mat4> &projectionMatrix, Uniform<glm::mat4> &viewMatrix, Uniform<glm::mat4> &modelMatrix, Uniform<bool> &selected) : m_window(window),
                                                                                                                                                           m_projectionMatrix(projectionMatrix),
                                                                                                                                                           m_viewMatrix(viewMatrix),
                                                                                                                                                           m_modelMatrix(modelMatrix),
                                                                                                                                                           m_selected(selected)
{
    m_angleRot_z = 0.f;
    m_angleRot_x = 0.f;
    m_arrowIsPressed = false;
    m_idSelected = 0;
}

void Controler::check(const Shader &shader)
{
    if (glfwGetKey(m_window, GLFW_KEY_UP) && !m_arrowIsPressed)
    {
        m_idSelected = (m_idSelected + 1) % 21;
        m_arrowIsPressed = true;
        std::cout << m_idSelected << std::endl;
    }
    else if (glfwGetKey(m_window, GLFW_KEY_DOWN) && !m_arrowIsPressed)
    {
        m_idSelected = m_idSelected - 1;
        if (m_idSelected < 0){
            m_idSelected = 20;
        }
        m_arrowIsPressed = true;
        std::cout << m_idSelected << std::endl;
    }
    else if (!glfwGetKey(m_window, GLFW_KEY_DOWN) && !glfwGetKey(m_window, GLFW_KEY_UP))
    {
        m_arrowIsPressed = false;
    }

    const float speed = 0.01;
    shader.bind();

    if (glfwGetKey(m_window, GLFW_KEY_A))
    {
        m_angleRot_z = (m_angleRot_z + speed);
    }
    if (glfwGetKey(m_window, GLFW_KEY_D))
    {
        m_angleRot_z = (m_angleRot_z - speed);
    }
    if (glfwGetKey(m_window, GLFW_KEY_W))
    {
        m_angleRot_x = (m_angleRot_x + speed);
    }
    if (glfwGetKey(m_window, GLFW_KEY_S))
    {
        m_angleRot_x = (m_angleRot_x - speed);
    }

    m_modelMatrix.value = glm::rotate(m_modelMatrix.value, m_angleRot_z, glm::vec3(0.f, 1.f, 0.f));
    m_modelMatrix.value = glm::rotate(m_modelMatrix.value, m_angleRot_x, glm::vec3(1.f, 0.f, 0.f));

    glUniformMatrix4fv(m_modelMatrix.id, 1, GL_FALSE, glm::value_ptr(m_projectionMatrix.value));
    glUniformMatrix4fv(m_viewMatrix.id, 1, GL_FALSE, glm::value_ptr(m_viewMatrix.value));
    glUniformMatrix4fv(m_projectionMatrix.id, 1, GL_FALSE, glm::value_ptr(m_modelMatrix.value));

    shader.unbind();

    m_angleRot_z = 0;
    m_angleRot_x = 0;
}

void Controler::updateSelected(const Shader &shader, int id)
{
    shader.bind();

    m_selected.value = m_idSelected == id;
    glUniform1i(m_selected.id, m_selected.value);

    shader.unbind();
    m_selected.value = m_idSelected == id;
}