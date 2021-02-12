#pragma once

#include "LGEBuffer.h"
namespace LGE {
	class VertexBuffer : LGEBuffer<float>
	{

	private:
		

	public:
		VertexBuffer();
		~VertexBuffer();

		void Bind();
		void UnBind();
		void UpdateBuffer();
		void SetBuffer(std::vector<float> data, int size) { LGEBuffer::SetBuffer(data, size); }
		void BufferData(float* data, int size);
	};

}

