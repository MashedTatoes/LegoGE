#include "Transform.h"

namespace LGE
{
	void Transform::Translate(glm::vec3 pos)
	{
		
		this->m_position.x = this->m_position.x + pos.x;
		this->m_position.y = this->m_position.y + pos.y;

	}
	void Transform::Translate(float x, float y)
	{
		this->m_position.x = this->m_position.x + x;
		this->m_position.y = this->m_position.y + y;


	}
}


