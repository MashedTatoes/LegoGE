#pragma once
#include "common.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
namespace LGE {
	class Mesh
	{
	protected:
		Vertex* m_vertices;
		unsigned int* m_indices;
		size_t m_indicesSize;
		size_t m_verticesSize;
		
		
		size_t m_serializedSize;
		Transform* m_transform;

		int m_offset;
		Texture* m_tex;

	
	public:
		Mesh(size_t numVertices, size_t numIndices);
		Mesh(size_t numVertices, size_t numIndices, Transform* transform) : Mesh(numVertices,numIndices) 
		{
			m_transform = transform;
		}

		Mesh(size_t numVertices, size_t numIndices, glm::vec3 position, glm::vec3 size) : Mesh(numVertices, numIndices, new Transform(position, size))
		{
			

		}

		~Mesh();
		void SetVertex(Vertex v, size_t index);
		Vertex GetVertex(size_t index) { return m_vertices[index]; }
		void SetColor(unsigned int* vertices,int amount, LGEColor clr);


		void SetIndexBuffer(unsigned int* buffer);
		float* SerialzeToBuffer(size_t* bufferSize);
		unsigned int* GetIndices() { return m_indices; }
		
		size_t GetNumIndices() { return m_indicesSize; }
		void LoadIntoVertexBuffer(VertexBuffer* buffer,unsigned int offset);
		void LoadIntoIndexBuffer(IndexBuffer* buffer, unsigned int offset);

		size_t GetSize() { return m_serializedSize; }
		int GetOffset() { return m_offset; }
		Transform* GetTransform() { return m_transform; }
		void SetTexture(Texture* tex);
		Texture GetTexture()
		{
			return *m_tex;
		}




		static Mesh* quad();
		static Mesh* triangle();
		static Mesh* cube();



	};
}


