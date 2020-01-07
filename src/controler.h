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
    Uniform<bool> &m_selected;

    float m_angleRot_z;
    float m_angleRot_x;

    bool m_arrowIsPressed;

    int m_idSelected;

public:
    Controler(GLFWwindow *&window, Uniform<glm::mat4> &projectionMatrix, Uniform<glm::mat4> &viewMatrix, Uniform<glm::mat4> &modelMatrix, Uniform<bool> &selected);

    void check(const Shader &shader);

    void updateSelected(const Shader &shader, int id);
};

#endif