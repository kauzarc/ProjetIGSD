#ifndef WINDOW_H
#define WINDOW_H

#include "setup.h"
#include "renderer.h"

class Window
{
private:
    Renderer m_renderer;
    Setup m_setup;

    GLFWwindow *m_window;
    const std::vector<ArrayBuffer> &m_VAO;
    const std::vector<Texture> &m_Texture;
    const Shader &m_shader;

public:
    Window();

    void run();
};

#endif