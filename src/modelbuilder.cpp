#include "modelbuilder.h"

#include "geometry.h"

ModelBuilder::ModelBuilder(const Data &data) : m_data(data)
{
}

void ModelBuilder::build(VertexBuffer &vbo, LayoutBuffer &lbo, const Equipe &equipe) const
{

    Triangle3 posTriangle[2];
    Triangle3 colTriangle[2];
    Triangle2 texTriangle[2];

    posTriangle[0] = Triangle3(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0.5, -0.5, 0.0), glm::vec3(-0.5, 0.5, 0.0));
    colTriangle[0] = Triangle3(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(1, 0, 0));
    texTriangle[0] = Triangle2(glm::vec2(0, 0), glm::vec2(1, 0), glm::vec2(0, 1));

    posTriangle[1] = Triangle3(glm::vec3(0.5, -0.5, 0), glm::vec3(-0.5, 0.5, 0), glm::vec3(0.5, 0.5, 0.0));
    colTriangle[1] = Triangle3(glm::vec3(0, 1, 0), glm::vec3(1, 0, 0), glm::vec3(0, 1, 0));
    texTriangle[1] = Triangle2(glm::vec2(1, 0), glm::vec2(0, 1), glm::vec2(1, 1));

    vbo.add(9, posTriangle[0]);
    vbo.add(9, posTriangle[1]);
    lbo.push(GL_FLOAT, 3, 18);

    vbo.add(9, colTriangle[0]);
    vbo.add(9, colTriangle[1]);
    lbo.push(GL_FLOAT, 3, 18);

    vbo.add(6, texTriangle[0]);
    vbo.add(6, texTriangle[1]);
    lbo.push(GL_FLOAT, 2, 12);
}
