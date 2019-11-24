#ifndef ARRAYBUFFER_H
#define ARRAYBUFFER_H

#include <GL/glew.h>

#include "vertexbuffer.h"

class ArrayBuffer
{
private:
    GLuint m_ID;
    unsigned int m_number;

    VertexBuffer m_vertexbuffer;

public:
    ArrayBuffer(const VertexBuffer &vertexBuffer);
    ~ArrayBuffer() = default;

    void bind() const;
    const unsigned int size() const;
};

#endif