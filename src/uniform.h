#ifndef UNIFORM_H
#define UNIFORM_H

#include <GL/glew.h>

template <class T>
struct Uniform
{
    GLuint id;
    T value;
};

#endif