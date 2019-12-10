#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm/glm.hpp>

struct Triangle3
{
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;

    Triangle3() = default;

    Triangle3(const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec3 &v3)
    {
        a = v1;
        b = v2;
        c = v3;
    }

    operator float *()
    {
        return reinterpret_cast<float *>(&a);
    }
};

struct Triangle2
{
    glm::vec2 a;
    glm::vec2 b;
    glm::vec2 c;

    Triangle2() = default;

    Triangle2(const glm::vec2 &v1, const glm::vec2 &v2, const glm::vec2 &v3)
    {
        a = v1;
        b = v2;
        c = v3;
    }

    operator float *()
    {
        return reinterpret_cast<float *>(&a);
    }
};

struct Quad3
{
    Triangle3 t1;
    Triangle3 t2;

    Quad3() = default;

    Quad3(const Triangle3 &a, const Triangle3 &b)
    {
        t1 = a;
        t2 = b;
    }

    Quad3(const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec3 &v3, const glm::vec3 &v4)
    {
        t1 = Triangle3(v1, v2, v3);
        t2 = Triangle3(v2, v3, v4);
    }

    operator float *()
    {
        return t1;
    }
};

struct Quad2
{
    Triangle2 t1;
    Triangle2 t2;

    Quad2() = default;

    Quad2(const Triangle2 &a, const Triangle2 &b)
    {
        t1 = a;
        t2 = b;
    }

    Quad2(const glm::vec2 &v1, const glm::vec2 &v2, const glm::vec2 &v3, const glm::vec2 &v4)
    {
        t1 = Triangle2(v1, v2, v3);
        t2 = Triangle2(v2, v3, v4);
    }

    operator float *()
    {
        return t1;
    }
};

#endif