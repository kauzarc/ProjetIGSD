#include "layoutbuffer.h"

LayoutBuffer::LayoutBuffer()
{
    m_offsetCounter = 0;
}

const std::vector<Element> &LayoutBuffer::getElements() const { return m_elements; }

void LayoutBuffer::push(GLenum type, GLuint count, unsigned int offset)
{
    m_elements.push_back({type, count, GL_FALSE, (void *)m_offsetCounter});
    m_offsetCounter += offset * Element::getSizeOfType(type);
}
