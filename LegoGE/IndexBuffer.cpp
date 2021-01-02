#include "IndexBuffer.h"

namespace LGE {
	IndexBuffer::IndexBuffer(unsigned int* data, unsigned int size)
	{
		glGenBuffers(1, &m_bufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * size, data, GL_STATIC_DRAW);
		m_indexBuffer = data;


	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_bufferId);
	}

	void IndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);

	}

	void IndexBuffer::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}

