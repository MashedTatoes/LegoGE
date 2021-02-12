#include "Triangle2D.h"

namespace LGE {
	Triangle2D::Triangle2D() : Mesh2D(3, 3) {
		SetIndexBuffer(new unsigned int[3]{ 0,1,2 });
		GenerateVertexLayout();
		
	}
	void Triangle2D::GenerateVertexLayout()
	{
		SetVertex(Vertex(-0.5f, -0.5f, 0.0f), 0);
		SetVertex(Vertex(0.5f, -0.5f, 0.0f), 1);
		SetVertex(Vertex(0.0f, 0.5f, 0.0f), 2);
	}
}

