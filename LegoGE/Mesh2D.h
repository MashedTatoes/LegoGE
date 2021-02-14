#pragma once
#include "common.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
namespace LGE {
	class Mesh2D
	{
	protected:
		Vertex* m_vertices;
		unsigned int* m_indices;
		size_t m_indicesSize;
		size_t m_verticesSize;
		
		
		size_t m_serializedSize;
		Transform* m_transform;

		int m_offset;
	
	public:
		Mesh2D(size_t numVertices, size_t numIndices);
		Mesh2D(size_t numVertices, size_t numIndices, Transform* transform) : Mesh2D(numVertices,numIndices) 
		{
			m_transform = transform;
		}

		Mesh2D(size_t numVertices, size_t numIndices, glm::vec3 position, glm::vec3 size) : Mesh2D(numVertices, numIndices, new Transform(position, size))
		{
			

		}

		~Mesh2D();
		void SetVertex(Vertex v, size_t index);
		void SetIndexBuffer(unsigned int* buffer);
		float* SerialzeToBuffer(size_t* bufferSize);
		unsigned int* GetIndices() { return m_indices; }
		
		size_t GetNumIndices() { return m_indicesSize; }
		LGE_RESULT GenerateVertexBuffer();
		LGE_RESULT GenerateIndexBuffer();
		virtual void GenerateVertexLayout(){ }
		void LoadIntoVertexBuffer(VertexBuffer* buffer,unsigned int offset);
		void LoadIntoIndexBuffer(IndexBuffer* buffer, unsigned int offset);
		size_t GetSize() { return m_serializedSize; }
		int GetOffset() { return m_offset; }
		Transform* GetTransform() { return m_transform; }

		static Mesh2D* quad();
		static Mesh2D* triangle();




	};
}


