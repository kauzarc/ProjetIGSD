#ifndef LAYOUTBUFFER_H
#define LAYOUTBUFFER_H

#include <vector>

#include <GL/glew.h>

struct Element
{
    GLenum type;
    GLuint count;
    GLboolean normalized;
    unsigned long offset;

    static unsigned long getSizeOfType(GLenum type)
    {
        switch (type)
        {
        case GL_FLOAT:
            return sizeof(GLfloat);
        case GL_INT:
            return sizeof(GLint);
        case GL_UNSIGNED_INT:
            return sizeof(GLuint);
        }
        return 0;
    }
};

class LayoutBuffer
{
private:
    std::vector<Element> m_elements;
    unsigned long m_offsetCounter;

public:
    LayoutBuffer();
    const std::vector<Element> &getElements() const;

    void push(GLenum type, GLuint count, unsigned long offset);
};

#endif