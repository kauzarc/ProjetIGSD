#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "vertexbuffer.h"
#include "layoutbuffer.h"
#include "data.h"
#include "geometry.h"

class ModelBuilder
{
private:
    const Data &m_data;

    void segmentBuilder(Line3 &positions,
                        Line3 &colors, Line2 &textures,
                        const glm::vec3 &pos1,
                        const glm::vec3 &pos2,
                        const glm::vec3 &col,
                        const unsigned int n,
                        const unsigned int segment = 20) const;

public:
    ModelBuilder(const Data &data);
    ~ModelBuilder() = default;

    void build(VertexBuffer &vbo, LayoutBuffer &lbo, const Equipe &equipe) const;
};

#endif