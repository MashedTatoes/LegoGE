#include "Triangle2D.h"

namespace LGE {
	Triangle2D::Triangle2D() : Mesh2D(3, 3) {
		SetIndexBuffer(new unsigned int[3]{ 0,1,2 });
		SetVertex(Vertex(-0.5f, -0.5f, 0.0f, m_color), 0);
		SetVertex(Vertex(0.5f, -0.5f, 0.0f, m_color), 1);
		SetVertex(Vertex(0.0f, 0.5f, 0.0f, m_color), 2);
	}
}

