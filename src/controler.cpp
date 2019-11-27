#include "controler.h"

#include <iostream>

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
}

void Controler::check(const Shader &shader)
{
    shader.bind();

    angleRot = (angleRot - M_PI * 0.001);

    m_viewMatrix.value = glm::lookAt(
        glm::vec3(1.5 * cos(angleRot), 1.5 * sin(angleRot), -0.35), // where is the camara
        glm::vec3(0, 0, 0.1),                                       //where it looks
        glm::vec3(0, 1, 0)                                        // head is up
    );

    glUniformMatrix4fv(m_viewMatrix.id, 1, GL_FALSE, glm::value_ptr(m_viewMatrix.value));

    shader.unbind();
}