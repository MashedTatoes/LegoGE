#pragma once
#include "common.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
namespace LGE {
	class Mesh2D
	{
	private:
		Vertex* m_vertices;
		unsigned int* m_indices;
		size_t m_indicesSize;
		size_t m_verticesSize;
		VertexBuffer* m_vertexBuffer;
		IndexBuffer* m_indexBuffer;

	
	public:
		Mesh2D(size_t numVertices, size_t numIndices);

		~Mesh2D();
		void SetVertex(Vertex v, size_t index);
		void SetIndexBuffer(unsigned int* buffer);
		float* SerialzeToBuffer(size_t* bufferSize);
		unsigned int* GetIndices() { return m_indices; }
		
		size_t GetNumIndices() { return m_indicesSize; }
		LGE_RESULT GenerateVertexBuffer();
		LGE_RESULT GenerateIndexBuffer();

	};
}


