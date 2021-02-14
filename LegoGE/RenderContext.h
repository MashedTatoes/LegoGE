#pragma once
#include "common.h"
#include "Mesh2D.h"
#include "ShaderProgram.h"
#include <vector>

namespace LGE {

	class RenderContext
	{
	private:
		unsigned int m_vao;
		std::vector<Mesh2D*> m_renderObjects;
		std::vector<Mesh2D*>  m_meshQueue;
		VertexBuffer* m_vertexBuffer;
		IndexBuffer* m_indexBuffer;
		ShaderProgram* shaderProgram;
		Projector m_projector;

	public:
		RenderContext(Projector projector);
		
		void QueueMesh(Mesh2D* mesh);
		void LoadMeshQueue();
		void UpdateBuffers();
		void Draw();
		
		LGE_RESULT UseShader(ShaderProgram* shaderProgram);

	};

}


