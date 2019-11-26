#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <vector>

class Texture
{
private:
    std::vector<float> m_image;
public:
    Texture(const std::string &path);
    ~Texture() = default;

    void bind();
};

#endif