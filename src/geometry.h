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

    operator float *() const
    {
        float tab[9];
        for (int i = 0; i < 3; i++)
        {
            tab[3 * i + 0] = vertex[i].x;
            tab[3 * i + 1] = vertex[i].y;
            tab[3 * i + 2] = vertex[i].z;
        }
        return tab;
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

    operator float *() const
    {
        float tab[6];
        for (int i = 0; i < 3; i++)
        {
            tab[2 * i + 0] = vertex[i].x;
            tab[2 * i + 1] = vertex[i].y;
        }
        return tab;
    }
};

#endif