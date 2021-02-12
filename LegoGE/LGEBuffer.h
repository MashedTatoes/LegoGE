#pragma once
#include "common.h"
#include <vector>
namespace LGE
{
	template<class T>
	class LGEBuffer
	{
	protected:
		int m_bufferType;
		unsigned int m_bufferId;
		std::vector<T> m_buffer;
		int m_size;
		
	public:
		
		LGEBuffer()
		{
			
		}

		virtual void Bind() {}
		virtual void Unbind() {}

		void SetBuffer(std::vector<T> data, int size)
		{
			m_buffer = data;
			m_size = size;
		}

		int GetSize() { return m_size; }

		virtual void UpdateBuffer(){}
		virtual void BufferData(T* data, int size){}
		
		
		

	};
}


