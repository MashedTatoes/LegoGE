#pragma once
#include "common.h"

namespace LGE 
{
	class Transform
	{
	private:
		glm::vec3 m_position;
		glm::vec3 m_size;
	public:
		Transform()
		{
			m_position = glm::vec3(0.0f);
			m_size = glm::vec3(0.0f);
		}
		Transform(glm::vec3 pos, glm::vec3 size) : m_position(pos), m_size(size){}
		glm::vec3 GetPosition() { return m_position; }
		glm::vec3 GetSize() { return m_size; }
		void Translate(glm::vec3 pos);
		void Translate(float x, float y);


	};
}


