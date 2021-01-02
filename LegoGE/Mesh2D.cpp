#include "Mesh2D.h"

namespace LGE {
	
	Mesh2D::Mesh2D(size_t numVertices, size_t numIndices )
	{
		
		m_vertices = new Vertex[numVertices];
		m_indices = new unsigned int[numIndices];
		m_indicesSize = numIndices;
		m_verticesSize = numVertices;


		

	}

	Mesh2D::~Mesh2D()
	{
		delete[] m_vertices;
		delete[] m_indices;
		m_vertices = nullptr;
		m_indices = nullptr;
		
	}

	void Mesh2D::SetVertex(Vertex v, size_t index) {
		m_vertices[index] = v;

	}

	void Mesh2D::SetIndexBuffer(unsigned int* buffer)
	{
		m_indices = buffer;


	}

	float* Mesh2D::SerialzeToBuffer(size_t* bufferSize)
	{
		size_t size = LGE_2DVERTEX_SIZE * m_verticesSize;
		float *out = new float[size];
		*bufferSize = size;
		for (int i = 0; i < m_verticesSize; i++) {
			Vertex v = m_vertices[i];
			out[(i * LGE_2DVERTEX_SIZE) + 0] = v.x;
			out[(i * LGE_2DVERTEX_SIZE) + 1] = v.y;
			out[(i * LGE_2DVERTEX_SIZE) + 2] = v.z;
		}
		return out;

	}

	LGE_RESULT Mesh2D::GenerateVertexBuffer()
	{
		size_t size = 0;
		float* vertices = SerialzeToBuffer(&size);
		m_vertexBuffer = new VertexBuffer(vertices,size);
		return LGE_OK;
	}
	LGE_RESULT Mesh2D::GenerateIndexBuffer()
	{
		m_indexBuffer = new IndexBuffer(GetIndices(), GetNumIndices());
		return LGE_OK;
	}
}


