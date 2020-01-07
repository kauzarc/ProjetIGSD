#ifndef WINDOW_H
#define WINDOW_H

#include <glm/glm.hpp>

#include "setup.h"
#include "renderer.h"
#include "controler.h"

class Window
{
private:
    Renderer m_renderer;
    Setup m_setup;

    Uniform<glm::mat4> m_projectionMatrix;
    Uniform<glm::mat4> m_viewMatrix;
    Uniform<glm::mat4> m_modelMatrix;
    Uniform<bool> m_selected;

    Controler m_controler;

    GLFWwindow *m_window;
    const std::vector<ArrayBuffer> &m_VAO;
    const std::vector<Texture> &m_Texture;
    const Shader &m_shader;

public:
    Window();

    void run();
};

#endif