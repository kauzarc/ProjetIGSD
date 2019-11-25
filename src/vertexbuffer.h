#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>

#include <vector>

class VertexBuffer
{
private:
    GLuint m_ID;
    std::vector<float> m_data;
    std::vector<int> m_offset;

public:
    VertexBuffer(unsigned int count = 0, float *tab = nullptr);
    ~VertexBuffer() = default;

    void bind() const;
    unsigned int count() const;
    const std::vector<int> &getOffset() const;
};

#endif