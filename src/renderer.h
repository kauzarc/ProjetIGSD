#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>

#include "arraybuffer.h"
#include "vertexbuffer.h"
#include "shader.h"

class Renderer
{
private:    
public:
    Renderer() = default;
    ~Renderer() = default;

    void Draw(const Shader &shader, const ArrayBuffer &vao, const std::vector<VertexBuffer> &vbo);
};

#endif