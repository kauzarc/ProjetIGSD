#ifndef CONTROLER_H
#define CONTROLER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "uniform.h"
#include "shader.h"

class Controler
{
private:
    GLFWwindow *&m_window;

    Uniform<glm::mat4> &m_projectionMatrix;
    Uniform<glm::mat4> &m_viewMatrix;
    Uniform<glm::mat4> &m_modelMatrix;

    float angleRot;

public:
    Controler(GLFWwindow *&window, Uniform<glm::mat4> &projectionMatrix, Uniform<glm::mat4> &viewMatrix, Uniform<glm::mat4> &modelMatrix);

    void check(const Shader &shader);
};

#endif