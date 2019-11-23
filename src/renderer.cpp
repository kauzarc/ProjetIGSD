#include <iostream>

#include "renderer.h"

using namespace std;

Renderer::Renderer(int width, int height)
{
    if (initialiseGLFW(width, height))
    {
        m_ok = initialiseGLEW();
    }
    else
    {
        m_ok = false;
    }
}

Renderer::~Renderer()
{
    glfwTerminate();
}

bool Renderer::initialiseGLFW(int width, int height)
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW\n" << stderr << endl;
        return false;
    }

    // glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // On veut OpenGL 3.3
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // On ne veut pas l'ancien OpenGL

    m_window = glfwCreateWindow(width, height, "Projet d'info 226", NULL, NULL);
    if (m_window == NULL)
    {
        std::cout << "Failed to open GLFW window.\n" << stderr << endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window);
    return true;
}

bool Renderer::initialiseGLEW()
{
    glewExperimental = true; // Nécessaire pour le profil core
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW\n" << stderr << endl;
        return false;
    }
    return true;
}

const bool &Renderer::ok() const { return m_ok; }