#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/glew.h>

class Shader
{
private:
    unsigned int m_programID;
    bool m_ok;

    std::string readFile(const std::string &path);
    unsigned int compileShader(GLenum type, const std::string& file);
    unsigned int linkShader(unsigned int vertexShaderID, unsigned int fragmentShaderID);
public:
    Shader();
    ~Shader();

    unsigned int init();

    unsigned int getProgramId() const;

    bool isOk() const;
};

#endif