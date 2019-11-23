#include "shader.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Shader::Shader()
{
}

Shader::~Shader()
{
    glDeleteProgram(m_programID);
}

unsigned int Shader::init()
{
    const string path = "shader/";
    const string vertex_file_path = path + "vertexShader.glsl";
    const string fragment_file_path = path + "fragmentShader.glsl";

    // Read the Vertex Shader code from the file
    string vertexShaderCode = readFile(vertex_file_path);
    // Read the Fragment Shader code from the file
    string fragmentShaderCode = readFile(fragment_file_path);

    // Create and compile the shaders
    unsigned int vertexShaderID = compileShader(GL_VERTEX_SHADER, vertexShaderCode);
    unsigned int fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);

    // Link the program
    m_programID = linkShader(vertexShaderID, fragmentShaderID);

    return m_programID;
}

string Shader::readFile(const string &path)
{
    string file;
    ifstream stream(path, std::ios::in);
    if (stream.is_open())
    {
        string line = "";
        while (getline(stream, line))
        {
            file += "\n" + line;
        }
        stream.close();
    }
    else
    {
        cout << "Impossible to open file. "
             << path << endl;
        ;
        return "";
    }

    return file;
}

unsigned int Shader::compileShader(GLenum type, const string &file)
{
    unsigned int shaderID = glCreateShader(type);

    // Compile Vertex Shader
    char const *ptr = file.c_str();
    glShaderSource(shaderID, 1, &ptr, NULL);
    glCompileShader(shaderID);

    // Check Vertex Shader
    int result = GL_FALSE;
    int infoLogLength;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0)
    {
        vector<char> shaderErrorMessage(infoLogLength + 1);
        glGetShaderInfoLog(shaderID, infoLogLength, NULL, &shaderErrorMessage[0]);
        cout << &shaderErrorMessage[0] << endl;
    }

    return shaderID;
}

unsigned int Shader::linkShader(unsigned int vertexShaderID, unsigned int fragmentShaderID)
{
    // Link the program
    unsigned int programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    int result;
    int infoLogLength;
    // Check the program
    glGetProgramiv(programID, GL_LINK_STATUS, &result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0)
    {
        vector<char> ProgramErrorMessage(infoLogLength + 1);
        glGetProgramInfoLog(programID, infoLogLength, NULL, &ProgramErrorMessage[0]);
        cout << &ProgramErrorMessage[0] << endl;
    }

    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return programID;
}

unsigned int Shader::getProgramId() { return m_programID; }

bool Shader::isOk() { return m_ok; }