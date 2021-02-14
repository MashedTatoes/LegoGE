#pragma once
#include "common.h"
#include <glm/gtc/matrix_transform.hpp>
namespace LGE {
	class Projector
	{
	private:
		glm::vec2 m_windowSize;
	public:
		Projector() : Projector(960,540)
		{


		}

		Projector(float width, float height)
		{
			m_windowSize = glm::vec2(0.0f);
			m_windowSize.x = width;
			m_windowSize.y = height;
		}

		glm::vec2 GetWindowSize() { return m_windowSize; }
		glm::mat4 GetProjectionMatrix();



	};
}


