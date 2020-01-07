#include "modelbuilder.h"

#include <cstdlib>

ModelBuilder::ModelBuilder(const Data &data) : m_data(data)
{
    std::srand(2);
}

void ModelBuilder::build(VertexBuffer &vbo, LayoutBuffer &lbo, const Equipe &equipe) const
{
    const std::vector<int> &scores = equipe.getScores();
    const std::vector<int> &classements = equipe.getClassements();

    glm::vec3 col;
    if (classements.back() < 4)
    {
        col = glm::vec3(0.118, 0.565, 1.000);
    }
    else if (classements.back() < 7)
    {
        col = glm::vec3(1.000, 1.000, 0.000);
    }
    else if (classements.back() > 17)
    {
        col = glm::vec3(0.863, 0.078, 0.235);
    }
    else
    {
        col = glm::vec3(0.467, 0.533, 0.600);
    }

    Line3 position;
    Line3 color;
    Line2 texture;

    float posTab[scores.size()];
    posTab[0] = (float(19 - classements[0]) / 19. + float(scores[0]) / 98.) / 2.1;

    for (unsigned int i = 1; i < scores.size(); i++)
    {
        posTab[i] = (float(19 - classements[i]) / 19. + float(scores[i]) / 98.) / 2.1;

        float gradiant = 0.;
        if (posTab[i] - posTab[i - 1] < 0)
        {
            gradiant = -gradiant;
        }

        segmentBuilder(position,
                       color,
                       texture,
                       glm::vec3(float(i - 1) / 20.f - 1.f, 2.f * posTab[i - 1] - 1.f, -gradiant),
                       glm::vec3(float(i) / 20.f - 1.f, 2.f * posTab[i] - 1.f, -gradiant),
                       col,
                       i);
    }

    vbo.add(position.size() * sizeQ3, position[0]);
    lbo.push(GL_FLOAT, sizeV3, position.size() * sizeQ3);

    vbo.add(color.size() * sizeQ3, color[0]);
    lbo.push(GL_FLOAT, sizeV3, color.size() * sizeQ3);

    vbo.add(texture.size() * sizeQ2, texture[0]);
    lbo.push(GL_FLOAT, sizeV2, texture.size() * sizeQ2);
}

void ModelBuilder::segmentBuilder(
    Line3 &positions,
    Line3 &colors,
    Line2 &textures,
    const glm::vec3 &pos1,
    const glm::vec3 &pos2,
    const glm::vec3 &col,
    const unsigned int n,
    const unsigned int segment) const
{
    float height = 2.f / 55.f;
    float gradient = pos2.y - pos1.y;

    float directionHB = (gradient > 0) ? 0.4f : -0.4f;

    float width = pos2.x - pos1.x;

    glm::vec3 Yaxes = glm::vec3(0, height / segment, 0);
    glm::vec3 Xaxes = glm::vec3(width / segment, gradient / segment, 0);
    glm::vec3 Zaxes = glm::vec3(0, 0, 0.02);

    glm::vec2 Xtexture = glm::vec2(0.1, 0.) / (float)segment;
    glm::vec2 Ytexture = glm::vec2(0., 1.) / (float)segment;

    for (unsigned int i = 0; i < segment; i++)
    {
        for (unsigned int j = 0; j < segment; j++)
        {
            Quad3 pos = Quad3(pos1, pos1, pos1, pos1);
            pos += Quad3(
                float(i) * Xaxes,
                float(i) * Xaxes,
                float(i + 1) * Xaxes,
                float(i + 1) * Xaxes);
            pos += Quad3(
                float(j + 1) * Yaxes,
                float(j) * Yaxes,
                float(j + 1) * Yaxes,
                float(j) * Yaxes);
            pos += Quad3(
                glm::sin((float)M_PI * (float)(j + 1) / (float)segment) * -Zaxes,
                glm::sin((float)M_PI * (float)(j) / (float)segment) * -Zaxes,
                glm::sin((float)M_PI * (float)(j + 1) / (float)segment) * -Zaxes,
                glm::sin((float)M_PI * (float)(j) / (float)segment) * -Zaxes);
            pos += Quad3(
                directionHB * glm::sin((float)M_PI * (float)(i) / (float)segment) * -Zaxes,
                directionHB * glm::sin((float)M_PI * (float)(i) / (float)segment) * -Zaxes,
                directionHB * glm::sin((float)M_PI * (float)(i + 1) / (float)segment) * -Zaxes,
                directionHB * glm::sin((float)M_PI * (float)(i + 1) / (float)segment) * -Zaxes);

            positions.push_back(pos);

            const float min = 0.5;
            const float max = 0.6;
            colors.push_back(Quad3(
                glm::sin((float)M_PI * (float)(j + 1) / (float)segment) * max * col + min * col,
                glm::sin((float)M_PI * (float)(j) / (float)segment) * max * col + min * col,
                glm::sin((float)M_PI * (float)(j + 1) / (float)segment) * max * col + min * col,
                glm::sin((float)M_PI * (float)(j) / (float)segment) * max * col + min * col));

            textures.push_back(Quad2(
                float(i + n * segment) * Xtexture + float(j + 1) * Ytexture,
                float(i + n * segment) * Xtexture + float(j) * Ytexture,
                float(i + 1 + n * segment) * Xtexture + float(j + 1) * Ytexture,
                float(i + 1 + n * segment) * Xtexture + float(j) * Ytexture));
        }
    }
}
