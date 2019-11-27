#include "controler.h"

Controler::Controler(Uniform<glm::mat4> &projectionMatrix, Uniform<glm::mat4> &viewMatrix, Uniform<glm::mat4> &modelMatrix) : m_projectionMatrix(projectionMatrix),
                                                                                                                              m_viewMatrix(viewMatrix),
                                                                                                                              m_modelMatrix(modelMatrix)
{
}