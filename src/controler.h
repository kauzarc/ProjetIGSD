#ifndef CONTROLER_H
#define CONTROLER_H

#include <glm/glm.hpp>

#include "uniform.h"

class Controler
{
private:
    Uniform<glm::mat4> &m_projectionMatrix;
    Uniform<glm::mat4> &m_viewMatrix;
    Uniform<glm::mat4> &m_modelMatrix;

public:
    Controler(Uniform<glm::mat4> &projectionMatrix, Uniform<glm::mat4> &viewMatrix, Uniform<glm::mat4> &modelMatrix);
};

#endif