#include "Projector.h"

glm::mat4 LGE::Projector::GetProjectionMatrix()
{
	glm::mat4 projection = glm::ortho(-(m_windowSize.x/2), m_windowSize.x/2, -(m_windowSize.y/2), m_windowSize.y/2, -1.0f, 1.0f);
	return projection;
}
