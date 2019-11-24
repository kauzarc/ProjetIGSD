#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <string>

#include "arraybuffer.h"
#include "vertexbuffer.h"
#include "shader.h"

class Renderer
{
private:
    GLFWwindow *m_window;

    bool m_ok;

    bool initialiseGLFW(int width, int height);
    bool initialiseGLEW(); 
public:
    Renderer(int width, int height);
    ~Renderer();

    void draw(const Shader &shader, const ArrayBuffer &vao);

    const bool &ok() const;

    GLFWwindow *getWindow(){return m_window;}
};

#endif