#ifndef ARRAYBUFFER_H
#define ARRAYBUFFER_H

#include <GL/glew.h>

#include "vertexbuffer.h"
#include "layoutbuffer.h"

class ArrayBuffer
{
private:
    GLuint m_ID;
    unsigned int m_number;

public:
    ArrayBuffer();
    ~ArrayBuffer() = default;

    void addBuffer(const VertexBuffer &vertexBuffer, const LayoutBuffer &layoutbuffer, unsigned int count);

    void bind() const;
    void unbind() const;
    const unsigned int count() const;
};

#endif