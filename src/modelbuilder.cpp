#include "modelbuilder.h"

ModelBuilder::ModelBuilder(const Data &data) : m_data(data)
{
}

void ModelBuilder::build(VertexBuffer &vbo, LayoutBuffer &lbo, const Equipe &equipe) const
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

    vbo.add(18, position);
    lbo.push(GL_FLOAT, 3, 18);

    vbo.add(18, color);
    lbo.push(GL_FLOAT, 3, 18);

    vbo.add(12, textureCoord);
    lbo.push(GL_FLOAT, 2, 12);
}
