#include "controler.h"

#define GLM_FORCE_RADIANS
#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Controler::Controler(
    GLFWwindow *&window, Uniform<glm::mat4> &projectionMatrix, Uniform<glm::mat4> &viewMatrix, Uniform<glm::mat4> &modelMatrix) : m_window(window),
                                                                                                                                  m_projectionMatrix(projectionMatrix),
                                                                                                                                  m_viewMatrix(viewMatrix),
                                                                                                                                  m_modelMatrix(modelMatrix)
{
    m_angleRot_z = 0.f;
    m_angleRot_x = 0.f;
}

void Controler::check(const Shader &shader)
{
    shader.bind();

    if (glfwGetKey(m_window, GLFW_KEY_A))
    {
        m_angleRot_z = (m_angleRot_z - 0.01);
    }
    if (glfwGetKey(m_window, GLFW_KEY_D))
    {
        m_angleRot_z = (m_angleRot_z + 0.01);
    }
    if (glfwGetKey(m_window, GLFW_KEY_W))
    {
        m_angleRot_x = (m_angleRot_x - 0.01);
    }
    if (glfwGetKey(m_window, GLFW_KEY_S))
    {
        m_angleRot_x = (m_angleRot_x + 0.01);
    }

    m_modelMatrix.value = glm::rotate(m_modelMatrix.value, m_angleRot_z, glm::vec3(0.f, 1.f, 0.f));
    m_modelMatrix.value = glm::rotate(m_modelMatrix.value, m_angleRot_x, glm::vec3(1.f, 0.f, 0.f));

    glUniformMatrix4fv(m_modelMatrix.id, 1, GL_FALSE, glm::value_ptr(m_modelMatrix.value));

    shader.unbind();

    m_angleRot_z = 0;
    m_angleRot_x = 0;
}