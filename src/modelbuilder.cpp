#include "modelbuilder.h"

#include <cstdlib>

ModelBuilder::ModelBuilder(const Data &data) : m_data(data)
{
    std::srand(2);
}

void ModelBuilder::build(VertexBuffer &vbo, LayoutBuffer &lbo, const Equipe &equipe) const
{
    const glm::vec3 col = glm::vec3(float(std::rand() % 100) / 100.f, float(std::rand() % 100) / 100.f, float(std::rand() % 100) / 100.f);

    const std::vector<int> &scores = equipe.getScores();
    const std::vector<int> &classements = equipe.getClassements();

    Line3 position;
    Line3 color;
    Line2 texture;

    //std::cout << scores.size() << " " << classements.size() << std::endl;

    for (unsigned int i = 1; i < scores.size(); i++)
    {
        float t0 = float((19 - classements[i - 1]) * scores[i - 1]) / float(19 * 98);
        float t1 = float((19 - classements[i]) * scores[i]) / float(19 * 98);

        segmentBuilder(position, color, texture, glm::vec3(float(i - 1) / 20.f - 1.f, t0 - 1.f, 0), glm::vec3(float(i) / 20.f - 1.f, t1 - 1.f, 0), col);

        //std::cout << float(i - 1) / 20.f - 1.f << " " << float(i) / 20.f - 1.f << std::endl;
    }

    vbo.add(position.size() * sizeQ3, position[0]);
    lbo.push(GL_FLOAT, sizeV3, position.size() * sizeQ3);

    std::cout << position.size() * sizeQ3 << std::endl;

    vbo.add(color.size() * sizeQ3, color[0]);
    lbo.push(GL_FLOAT, sizeV3, color.size() * sizeQ3);

    vbo.add(texture.size() * sizeQ2, texture[0]);
    lbo.push(GL_FLOAT, sizeV2, texture.size() * sizeQ2);
}

void ModelBuilder::segmentBuilder(Line3 &positions, Line3 &colors, Line2 &textures, const glm::vec3 &pos1, const glm::vec3 &pos2, const glm::vec3 &col, const unsigned int segment) const
{
    float height = 2.f / 40.f;
    float gradient = pos2.y - pos1.y;

    float width = pos2.x - pos1.x;

    glm::vec3 Yaxes = glm::vec3(0, height / segment, 0);
    glm::vec3 Xaxes = glm::vec3(width / segment, gradient / segment, 0);

    for (unsigned int i = 0; i < segment; i++)
    {
        for (unsigned int j = 0; j < segment; j++)
        {
            positions.push_back(Quad3(
                pos1 + float(i) * Xaxes + float(j + 1) * Yaxes,
                pos1 + float(i) * Xaxes + float(j) * Yaxes,
                pos1 + float(i + 1) * Xaxes + float(j + 1) * Yaxes,
                pos1 + float(i + 1) * Xaxes + float(j) * Yaxes));

            // glm::vec3 v0 = pos1 + float(i) * Xaxes + float(j) * Yaxes;
            // std::cout << "v0: " << v0.x << " " << v0.y << " " << v0.z << std::endl;

            // glm::vec3 v1 = pos1 + float(i + 1) * Xaxes + float(j) * Yaxes;
            // std::cout << "v1: " << v1.x << " " << v1.y << " " << v1.z << std::endl;

            colors.push_back(Quad3(col, col, col, col));

            textures.push_back(Quad2(
                pos1 + float(i) * Xaxes + float(j + 1) * Yaxes,
                pos1 + float(i) * Xaxes + float(j) * Yaxes,
                pos1 + float(i + 1) * Xaxes + float(j + 1) * Yaxes,
                pos1 + float(i + 1) * Xaxes + float(j) * Yaxes));
        }
    }

    //std::cout << height << std::endl;
    std::cout << pos1.x << " " << pos1.y << std::endl;
}
