#include "VertexBuffer.h"
	
namespace LGE {
	VertexBuffer::VertexBuffer() : LGEBuffer()
	{
		

		glGenBuffers(1, &m_bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
		glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_STATIC_DRAW);
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

	void VertexBuffer::UpdateBuffer(unsigned int offset, size_t size, float* data)
	{
		Bind();
		glBufferSubData(GL_ARRAY_BUFFER,offset * sizeof(float), sizeof(float) * size, data);
	}

	size_t VertexBuffer::BufferData(float* data, int size)
	{
		Bind();
		size_t offset = m_size;
		m_size += size;
		
		m_buffer.insert(m_buffer.end(), data,data + size);
	
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_size, m_buffer.data(), GL_STATIC_DRAW);
		return offset;
		

	}

	

}

