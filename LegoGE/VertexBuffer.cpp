#include "VertexBuffer.h"

namespace LGE {
	VertexBuffer::VertexBuffer(float* data, unsigned int size)
	{
		glGenBuffers(1, &m_bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, data, GL_STATIC_DRAW);
		m_vertexBuffer = data;


	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_bufferId);
	}

	void VertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);

	}

	void VertexBuffer::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}

