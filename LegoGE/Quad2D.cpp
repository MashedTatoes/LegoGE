#include "Quad2D.h"
namespace LGE {
	Quad2D::Quad2D() :Mesh2D(4, 6) {
		SetIndexBuffer(new unsigned int[3]{ 0,1,2 });
		SetVertex(Vertex(-0.5f, -0.5f, 0.0f, m_color), 0);
		SetVertex(Vertex(0.5f, -0.5f, 0.0f, m_color), 1);
		SetVertex(Vertex(0.5f, 0.5f, 0.0f, m_color), 2);
        SetVertex(Vertex(-0.5f, 0.5f, 0.0f, m_color), 3);
        SetIndexBuffer(new unsigned int[6]{ 0,1,2,2,3,0 });
	}

}