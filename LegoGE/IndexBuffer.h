#pragma once
#include "common.h"
#include "LGEBuffer.h"
namespace LGE {
	class IndexBuffer : LGEBuffer<unsigned int>
	{



	public:
		IndexBuffer();
		~IndexBuffer();

		void Bind();
		void UnBind();
		void UpdateBuffer();
		void SetBuffer(std::vector< unsigned int> data, int size) { LGEBuffer::SetBuffer(data, size); }
		void BufferData(unsigned int* data, int size);
		

	};

}

