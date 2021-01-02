#pragma once
#include "common.h"
namespace LGE {
	class IndexBuffer
	{

	private:
		unsigned int m_bufferId;
		unsigned int* m_indexBuffer;

	public:
		IndexBuffer(unsigned int* data, unsigned int size);
		~IndexBuffer();

		void Bind();
		void UnBind();
	};

}

