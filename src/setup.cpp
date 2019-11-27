#include "setup.h"

Setup::Setup()
{
    setupBuffer();
    setupTexture();
}

void Setup::setupBuffer()
{
    float position[18] = {
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
        -0.5, 0.5, 0.0,

        0.5, -0.5, 0,
        -0.5, 0.5, 0,
        0.5, 0.5, 0.0};

    float color[18] =
        {
            1, 0, 0,
            0, 1, 0,
            1, 0, 0,

            0, 1, 0,
            1, 0, 0,
            0, 1, 0};

    float textureCoord[12] =
        {
            0, 0,
            1, 0,
            0, 1,

            1, 0,
            0, 1,
            1, 1};

    m_VBO.push_back(VertexBuffer());
    m_LBO.push_back(LayoutBuffer());
    m_VAO.push_back(ArrayBuffer());

    m_VBO[0].add(18, position);
    m_LBO[0].push(GL_FLOAT, 3, 18);

    m_VBO[0].add(18, color);
    m_LBO[0].push(GL_FLOAT, 3, 18);

    m_VBO[0].add(12, textureCoord);
    m_LBO[0].push(GL_FLOAT, 2, 12);

    m_VAO[0].addBuffer(m_VBO[0], m_LBO[0], 6);
}

void Setup::setupTexture()
{
    m_Texture.push_back(Texture("images/Arsenal.png"));
}

const std::vector<ArrayBuffer> &Setup::getVAO() const { return m_VAO; }
const std::vector<Texture> &Setup::getTexture() const { return m_Texture; }
const Shader &Setup::getShader() const { return m_shader; }