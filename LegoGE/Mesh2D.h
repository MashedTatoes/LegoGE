#pragma once
#include "common.h"

namespace LGE {
	class Mesh2D
	{
	private:
		Vertex* m_vertices;
		unsigned int* m_indices;
		size_t m_indicesSize;
		size_t m_verticesSize;
		
	protected:
		LGEColor m_color;
	public:
		Mesh2D(size_t numVertices, size_t numIndices,LGEColor = WHITE);

		~Mesh2D();
		void SetVertex(Vertex v, size_t index);
		void SetIndexBuffer(unsigned int* buffer);
		float* SerialzeToBuffer(size_t* bufferSize);
		unsigned int* GetIndices() { return m_indices; }
		LGE_RESULT SetColor(LGEColor val, int = -1);
		size_t GetNumIndices() { return m_indicesSize; }
		LGEColor GetColor() { return m_color; }

	};
}


