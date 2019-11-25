#include "arraybuffer.h"

ArrayBuffer::ArrayBuffer()
{
    glGenVertexArrays(1, &m_ID);
}

void ArrayBuffer::addBuffer(const VertexBuffer &vertexBuffer, const LayoutBuffer &layoutbuffer)
{
    bind();
    vertexBuffer.bind();

    const std::vector<Element> elements = layoutbuffer.getElements();

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, 0, elements[i].offset);
    }
}

void ArrayBuffer::bind() const
{
    glBindVertexArray(m_ID);
}

const unsigned int ArrayBuffer::count() const
{
    return m_number;
}