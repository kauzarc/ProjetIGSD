#ifndef SETUP_H
#define SETUP_H

#include <vector>

#include "vertexbuffer.h"
#include "layoutbuffer.h"
#include "arraybuffer.h"
#include "shader.h"
#include "texture.h"
#include "data.h"
#include "modelbuilder.h"

class Setup
{
private:
    Data m_data;
    ModelBuilder m_modelBuilder;

    std::vector<VertexBuffer> m_VBO;
    std::vector<LayoutBuffer> m_LBO;
    std::vector<ArrayBuffer> m_VAO;
    std::vector<Texture> m_Texture;
    Shader m_shader;

    void setupBuffer();
    void setupTexture();

public:
    Setup();

    const std::vector<ArrayBuffer> &getVAO() const;
    const std::vector<Texture> &getTexture() const;
    const Shader &getShader() const;
};

#endif