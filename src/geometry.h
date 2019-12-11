#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm/glm.hpp>

const unsigned int sizeV3 = 3;
const unsigned int sizeV2 = 2;

const unsigned int sizeT3 = 3 * sizeV3;
const unsigned int sizeT2 = 3 * sizeV2;

const unsigned int sizeQ3 = 2 * sizeT3;
const unsigned int sizeQ2 = 2 * sizeT2;

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

    Triangle3 operator+(const Triangle3 &other)
    {
        return Triangle3(a + other.a, b + other.b, c + other.c);
    }

    Triangle3 &operator+=(const Triangle3 &other)
    {
        a += other.a;
        b += other.b;
        c += other.c;
        return *this;
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

    Triangle2 operator+(const Triangle2 &other)
    {
        return Triangle2(a + other.a, b + other.b, c + other.c);
    }

    Triangle2 &operator+=(const Triangle2 &other)
    {
        a += other.a;
        b += other.b;
        c += other.c;
        return *this;
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

    Quad3 operator+(const Quad3 &other)
    {
        return Quad3(t1 + other.t1, t2 + other.t2);
    }

    Quad3 &operator+=(const Quad3 &other)
    {
        t1 += other.t1;
        t2 += other.t2;
        return *this;
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

    Quad2 operator+(const Quad2 &other)
    {
        return Quad2(t1 + other.t1, t2 + other.t2);
    }

    Quad2 &operator+=(const Quad2 &other)
    {
        t1 += other.t1;
        t2 += other.t2;
        return *this;
    }

    operator float *()
    {
        return t1;
    }
};

typedef std::vector<Quad3> Line3;
typedef std::vector<Quad2> Line2;

#endif