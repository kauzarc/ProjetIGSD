#include "texture.h"

#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;

Texture::Texture(const string &path)
{
    glGenTextures(1, &m_ID);

    m_image = cv::imread(path, CV_LOAD_IMAGE_UNCHANGED);

    bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_image.cols, m_image.rows, 0, GL_BGRA, GL_UNSIGNED_BYTE, m_image.ptr());
    glGenerateMipmap(GL_TEXTURE_2D);

    unbind();
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, m_ID);
}
void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}