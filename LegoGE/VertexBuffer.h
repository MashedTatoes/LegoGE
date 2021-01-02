#pragma once
#include "common.h"
namespace LGE {
	class VertexBuffer
	{

	private:
		unsigned int m_bufferId;
		float* m_vertexBuffer;

	public:
		VertexBuffer(float* data, unsigned int size);
		~VertexBuffer();

		void Bind();
		void UnBind();
	};

}

