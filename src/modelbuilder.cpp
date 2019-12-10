#include "modelbuilder.h"

#include "geometry.h"

ModelBuilder::ModelBuilder(const Data &data) : m_data(data)
{
}

void ModelBuilder::build(VertexBuffer &vbo, LayoutBuffer &lbo, const Equipe &equipe) const
{

    Quad3 posTriangle = Quad3(
        glm::vec3(-0.5, 0.5, 0.0),
        glm::vec3(-0.5, -0.5, 0.0),
        glm::vec3(0.5, 0.5, 0.0),
        glm::vec3(0.5, -0.5, 0.0));

    Quad3 colTriangle = Quad3(
        glm::vec3(1, 0, 0),
        glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0),
        glm::vec3(0, 1, 0));

    Quad2 texTriangle = Quad2(
        glm::vec2(0, 1),
        glm::vec2(0, 0),
        glm::vec2(1, 1),
        glm::vec2(1, 0));

    vbo.add(18, posTriangle);
    lbo.push(GL_FLOAT, 3, 18);

    vbo.add(18, colTriangle);
    lbo.push(GL_FLOAT, 3, 18);

    vbo.add(12, texTriangle);
    lbo.push(GL_FLOAT, 2, 12);
}
