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
    VertexBuffer(unsigned int count = 0, float *tab = nullptr);
    ~VertexBuffer() = default;

    void bind() const;
    unsigned int count() const;
    
    void add(unsigned int count, float *tab);
};

#endif