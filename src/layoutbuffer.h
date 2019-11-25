#ifndef LAYOUTBUFFER_H
#define LAYOUTBUFFER_H

#include <vector>

#include <GL/glew.h>

struct Element
{
    GLenum type;
    GLuint count;
    GLboolean normalized;
    void* offset;
};

class LayoutBuffer
{
private:
    std::vector<Element> m_elements;
    unsigned int m_offsetCounter;

public:
    LayoutBuffer();
    const std::vector<Element> &getElements() const;

    void push(GLenum type, GLuint count, unsigned int offset);
};

#endif