#pragma once
#include "common.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include <vector>

namespace LGE {

	class RenderContext
	{
	private:
		unsigned int m_vao;
		std::vector<Mesh*> m_renderObjects;
		std::vector<Mesh*>  m_meshQueue;
		std::vector<float*> m_vertexGarbage;


		VertexBuffer* m_vertexBuffer;
		IndexBuffer* m_indexBuffer;
		ShaderProgram* shaderProgram;
		Projector m_projector;
		


	public:
		RenderContext(Projector projector);
		
		void QueueMesh(Mesh* mesh);
		//void QueueTexture(Texture* tex);

		void LoadQueue(unsigned int target);
		void UpdateBuffers();
		void Draw();
		


		LGE_RESULT UseShader(ShaderProgram* shaderProgram);

	};

}


