#pragma once
#include "common.h"
#include "LGEBuffer.h"
namespace LGE {
	class IndexBuffer : public LGEBuffer<unsigned int>
	{



	public:
		IndexBuffer();
		~IndexBuffer();

		void Bind();
		void UnBind();
		void UpdateBuffer(unsigned int offset, size_t size, unsigned int* data);
		void SetBuffer(std::vector< unsigned int> data, int size) { LGEBuffer::SetBuffer(data, size); }
		size_t BufferData(unsigned int* data, int size);
		

	};

}

