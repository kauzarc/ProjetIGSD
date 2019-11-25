#include "vertexbuffer.h"

VertexBuffer::VertexBuffer(unsigned int size, float *tab)
{
    for (unsigned int i = 0; i < size; i++)
        m_data.push_back(tab[i]);

    glCreateBuffers(1, &m_ID);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(float), &m_data[0], GL_STATIC_DRAW);
}

unsigned int VertexBuffer::count() const { return m_data.size(); }

void VertexBuffer::add(unsigned int count, float *tab)
{
    for (unsigned int i = 0; i < count; i++)
        m_data.push_back(tab[i]);

    glCreateBuffers(1, &m_ID);
}