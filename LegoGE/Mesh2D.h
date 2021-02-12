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
		
		Vector2 m_position;
		size_t m_serializedSize;
	
	
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

		void UpdateMesh();
		virtual void GenerateVertexLayout(){ }
		Vector2 GetPosition() { return m_position; }

		void LoadIntoVertexBuffer(VertexBuffer* buffer,unsigned int offset);
		void LoadIntoIndexBuffer(IndexBuffer* buffer, unsigned int offset);
		
		size_t GetSize() { return m_serializedSize; }

		static Mesh2D* quad();
		static Mesh2D* triangle();

		void SetPosition(Vector2 v)
		{
			m_position = v;


		}

	};
}


