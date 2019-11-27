#include "texture.h"

#include <opencv2/highgui/highgui.hpp>

using namespace std;

Texture::Texture(const string &path)
{
    glGenTextures(1, &m_ID);

    m_image = cv::imread(path, CV_LOAD_IMAGE_UNCHANGED);

    flip(m_image, m_image, 0);

    bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_image.cols, m_image.rows, 0, GL_BGRA, GL_UNSIGNED_BYTE, m_image.ptr());
    glGenerateMipmap(GL_TEXTURE_2D);

    unbind();
}

void Texture::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_ID);
}
void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}