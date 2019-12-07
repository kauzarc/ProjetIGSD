#include "setup.h"

Setup::Setup() : m_modelBuilder(m_data)
{
    setupBuffer();
    setupTexture();
}

void Setup::setupBuffer()
{
    m_VBO.push_back(VertexBuffer());
    m_LBO.push_back(LayoutBuffer());
    m_VAO.push_back(ArrayBuffer());

    const std::map<std::string, Equipe> &listEquipe = m_data.getEquipes();
    const std::string &nom = m_data.getNoms()[0];
    const Equipe &equipe = listEquipe.at(nom);

    m_modelBuilder.build(m_VBO[0], m_LBO[0], equipe);

    m_VAO[0].addBuffer(m_VBO[0], m_LBO[0], 6);
}

void Setup::setupTexture()
{
    m_Texture.push_back(Texture("images/Arsenal.png"));
}

const std::vector<ArrayBuffer> &Setup::getVAO() const { return m_VAO; }
const std::vector<Texture> &Setup::getTexture() const { return m_Texture; }
const Shader &Setup::getShader() const { return m_shader; }