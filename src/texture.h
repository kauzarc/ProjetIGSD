#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>

#include <GL/glew.h>
#include <opencv2/core/core.hpp>

class Texture
{
private:
    GLuint m_ID;
    cv::Mat m_image;

public:
    Texture(const std::string &path);
    ~Texture() = default;

    void bind() const;
    void unbind() const;
};

#endif