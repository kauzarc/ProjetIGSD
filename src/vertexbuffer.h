#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>

#include <vector>

class VertexBuffer
{
private:
    GLuint m_ID;
    std::vector<float> m_data;

public:
    VertexBuffer(unsigned int size = 0, float *tab = nullptr);
    ~VertexBuffer() = default;

    void bind();
    unsigned int size() const;
};

#endif