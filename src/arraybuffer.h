#ifndef ARRAYBUFFER_H
#define ARRAYBUFFER_H

#include <GL/glew.h>

#include "vertexbuffer.h"

class ArrayBuffer
{
    GLuint m_ID;

    VertexBuffer m_vertexbuffer;
private:
public:
    ArrayBuffer(VertexBuffer vertexBuffer);
    ~ArrayBuffer() = default;
};

#endif