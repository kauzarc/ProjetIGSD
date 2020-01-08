#include "setup.h"

Setup::Setup() : m_modelBuilder(m_data)
{
    setupBuffer();
    setupTexture();
}

void Setup::setupBuffer()
{
    const std::vector<std::string> &nameList = m_data.getNoms();
    const std::map<std::string, Equipe> &equipeList = m_data.getEquipes();

    for (unsigned int i = 0; i < nameList.size(); i++)
    {
        m_VBO.push_back(VertexBuffer());
        m_LBO.push_back(LayoutBuffer());
        m_VAO.push_back(ArrayBuffer());

        const Equipe &equipe = equipeList.at(nameList[i]);

        m_modelBuilder.build(m_VBO[i], m_LBO[i], equipe);

        m_VAO[i].addBuffer(m_VBO[i], m_LBO[i], 2 * 96000);
    }
}

void Setup::setupTexture()
{
    const std::vector<std::string> &nameList = m_data.getNoms();

    for (unsigned int i = 0; i < nameList.size(); i++)
    {
        std::string str = "images/" + nameList[i] + ".png";

        m_Texture.push_back(str);
    }
}

const std::vector<ArrayBuffer> &Setup::getVAO() const { return m_VAO; }
const std::vector<Texture> &Setup::getTexture() const { return m_Texture; }
const Shader &Setup::getShader() const { return m_shader; }