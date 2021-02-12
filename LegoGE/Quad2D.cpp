#include "Quad2D.h"
namespace LGE {
	Quad2D::Quad2D() :Mesh2D(4, 6) {
		SetIndexBuffer(new unsigned int[6]{ 0,1,2,2,3,0 });
		GenerateVertexLayout();
        
        
	}

	void Quad2D::GenerateVertexLayout()
	{
		SetVertex(Vertex(-1.0f, 1.0f, 0.0f), 0); //Top left
		SetVertex(Vertex(-1.0f, 0.0f, 0.0f), 1); //Bottom left
		SetVertex(Vertex(0.0f, 0.0f, 0.0f), 2); //Bottom right
		SetVertex(Vertex(0.0f, 1.0f, 0.0f), 3); //Top right
	}

}