#include "layoutbuffer.h"

LayoutBuffer::LayoutBuffer()
{
    m_offsetCounter = 0;
}

const std::vector<Element> &LayoutBuffer::getElements() const { return m_elements; }

void LayoutBuffer::push(GLenum type, GLuint count, unsigned long offset)
{
    m_elements.push_back({type, count, GL_FALSE, m_offsetCounter});
    m_offsetCounter += offset;
}
