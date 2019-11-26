#include "texture.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace std;

Texture::Texture(const string &path)
{
    glGenTextures(1, &m_ID);

    cv::Mat image = cv::imread(path, CV_LOAD_IMAGE_UNCHANGED);

    unsigned char pixel1 = *image.ptr();
    unsigned char pixel2 = *(image.ptr() + 1);
    unsigned char pixel3 = *(image.ptr() + 2);

    std::cout << (unsigned int)pixel1 << std::endl;
    std::cout << (unsigned int)pixel2 << std::endl;
    std::cout << (unsigned int)pixel3 << std::endl;
}