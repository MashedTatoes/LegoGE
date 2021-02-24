#pragma once
#include "common.h"

namespace LGE 
{
	class Transform
	{
	private:
		glm::vec3 m_position;
		glm::vec3 m_size;
		glm::vec3 m_scale;
	public:
		Transform()
		{
			m_position = glm::vec3(0.0f);
			m_size = glm::vec3(0.0f);
			m_scale = glm::vec3(1.0f);
		}
		Transform(glm::vec3 pos, glm::vec3 size) : m_position(pos), m_size(size),m_scale(glm::vec3(1.0f)){}
		glm::vec3 GetPosition() { return m_position; }
		glm::vec3 GetSize() { return m_size; }
		glm::vec3 GetScale() { return m_scale; }
		void Translate(glm::vec3 pos);
		void Translate(float x, float y);
		void SetScale(glm::vec3 scale) { m_scale = scale; }
		


	};
}


