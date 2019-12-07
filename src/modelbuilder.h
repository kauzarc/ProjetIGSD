#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "vertexbuffer.h"
#include "layoutbuffer.h"
#include "data.h"

class ModelBuilder
{
private:
    const Data &m_data;

public:
    ModelBuilder(const Data &data);
    ~ModelBuilder() = default;

    void build(VertexBuffer &vbo, LayoutBuffer &lbo, const Equipe &equipe) const;
};

#endif