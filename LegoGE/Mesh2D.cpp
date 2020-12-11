#include "Mesh2D.h"

namespace LGE {
	
	Mesh2D::Mesh2D(size_t numVertices, size_t numIndices, LGEColor m_color )
	{
		this->m_color = m_color;
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
			out[(i * LGE_2DVERTEX_SIZE) + 3] = v.m_color.r;
			out[(i * LGE_2DVERTEX_SIZE) + 4] = v.m_color.g;
			out[(i * LGE_2DVERTEX_SIZE) + 5] = v.m_color.b;
			out[(i * LGE_2DVERTEX_SIZE) + 6] = v.m_color.a;


		}
		return out;

	}

	LGE_RESULT Mesh2D::SetColor(LGEColor val, int index)
	{
		if (index < 0) {
			for (int i = 0; i < m_verticesSize; i++) {
				m_vertices[i].m_color = val;
			}
		}
		else if (index >= m_verticesSize) {
			return LGE_NULL_VERTEX;

		}
		else {
			m_vertices[index].m_color = val;
		}
		return LGE_OK;

	}






}


