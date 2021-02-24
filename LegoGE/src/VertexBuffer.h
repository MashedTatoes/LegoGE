#pragma once

#include "LGEBuffer.h"
namespace LGE {
	class VertexBuffer : public LGEBuffer<float>
	{

	private:
		

	public:
		VertexBuffer();
		~VertexBuffer();

		void Bind();
		void UnBind();
		void UpdateBuffer(unsigned int offset, size_t size, float* data);
		void SetBuffer(std::vector<float> data, int size) { LGEBuffer::SetBuffer(data, size); }
		size_t BufferData(float* data, int offset);
	};

}

