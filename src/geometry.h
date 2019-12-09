#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm/glm.hpp>

struct Triangle3
{
    glm::vec3 vertex[3];
    glm::vec3 &a;
    glm::vec3 &b;
    glm::vec3 &c;

    Triangle3() : a(vertex[0]), b(vertex[1]), c(vertex[2])
    {
    }

    Triangle3(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2) : a(vertex[0]), b(vertex[1]), c(vertex[2])
    {
        a = v0;
        b = v1;
        c = v2;
    }

    Triangle3(float *tab) : a(vertex[0]), b(vertex[1]), c(vertex[2])
    {
        for (int i = 0; i < 3; i++)
        {
            vertex[i].x = tab[3 * i + 0];
            vertex[i].y = tab[3 * i + 1];
            vertex[i].z = tab[3 * i + 2];
        }
    }

    Triangle3 &operator=(const Triangle3 &other)
    {
        if (this != &other)
        {
            a = other.a;
            b = other.b;
            c = other.c;
        }
        return *this;
    }

    operator float *()
    {
        return reinterpret_cast<float *>(vertex);
    }
};

struct Triangle2
{
    glm::vec2 vertex[3];
    glm::vec2 &a;
    glm::vec2 &b;
    glm::vec2 &c;

    Triangle2() : a(vertex[0]), b(vertex[1]), c(vertex[2])
    {
    }

    Triangle2(glm::vec2 v0, glm::vec2 v1, glm::vec2 v2) : a(vertex[0]), b(vertex[1]), c(vertex[2])
    {
        a = v0;
        b = v1;
        c = v2;
    }

    Triangle2(float *tab) : a(vertex[0]), b(vertex[1]), c(vertex[2])
    {
        for (int i = 0; i < 3; i++)
        {
            vertex[i].x = tab[2 * i + 0];
            vertex[i].y = tab[2 * i + 1];
        }
    }

    Triangle2 &operator=(const Triangle2 &other)
    {
        if (this != &other)
        {
            a = other.a;
            b = other.b;
            c = other.c;
        }
        return *this;
    }

    operator float *()
    {
        return reinterpret_cast<float *>(vertex);
    }
};

#endif