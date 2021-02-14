#include "Projector.h"

glm::mat4 LGE::Projector::GetProjectionMatrix()
{
	glm::mat4 projection = glm::ortho(0.0f, m_windowSize.x, 0.0f, m_windowSize.y, -1.0f, 1.0f);
	return projection;
}
