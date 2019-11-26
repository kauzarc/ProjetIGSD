#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>

#include <GL/glew.h>

class Texture
{
private:
    GLuint m_ID;
    std::vector<float> m_image;
public:
    Texture(const std::string &path);
    ~Texture() = default;

    void bind();
};

#endif