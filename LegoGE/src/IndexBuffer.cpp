#include "IndexBuffer.h"

namespace LGE {
	IndexBuffer::IndexBuffer() : LGEBuffer()
	{
		

		glGenBuffers(1, &m_bufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, nullptr, GL_STATIC_DRAW);
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

	

	void IndexBuffer::UpdateBuffer(unsigned int offset, size_t size, unsigned int* data)
	{
		Bind();
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, sizeof(float) * size, data);

	}

	size_t IndexBuffer::BufferData(unsigned int* data, int size)
	{
		Bind();
		size_t offset = m_size;
		m_size += size;

		m_buffer.insert(m_buffer.end(), data, data + size);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_size, m_buffer.data(), GL_STATIC_DRAW);
		return offset;
	}

	

}

