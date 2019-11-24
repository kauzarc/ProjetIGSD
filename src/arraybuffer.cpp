#include "arraybuffer.h"

ArrayBuffer::ArrayBuffer(const VertexBuffer &vertexBuffer)
{
    m_vertexbuffer = vertexBuffer;
    m_number = m_vertexbuffer.size() / 3;

    glGenVertexArrays(1, &m_ID);
    bind();
    m_vertexbuffer.bind();
}

void ArrayBuffer::bind() const
{
    glBindVertexArray(m_ID);
}

const unsigned int ArrayBuffer::size() const
{
    return m_number;
}