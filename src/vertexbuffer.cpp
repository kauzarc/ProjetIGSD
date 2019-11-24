#include "vertexbuffer.h"

VertexBuffer::VertexBuffer(unsigned int size, float *tab)
{
    for (unsigned int i = 0; i < size; i++)
        m_data.push_back(tab[i]);
}

void VertexBuffer::bind()
{
    glCreateBuffers(1, &m_ID);
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
    glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(float), &m_data[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
}

unsigned int VertexBuffer::size() const { return m_data.size(); }