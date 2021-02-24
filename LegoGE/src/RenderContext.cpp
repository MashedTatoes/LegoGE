#include "RenderContext.h"

namespace LGE
{
	RenderContext::RenderContext(Projector projector)
	{
		m_projector = projector;
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);
		m_vertexBuffer = new VertexBuffer();
		glEnableVertexAttribArray(0);
		glEnableVertexArrayAttrib(m_vao, 0);
		glVertexAttribPointer(0, LGE_2DVERTEX_LAYOUT1, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, 0);
		glEnableVertexArrayAttrib(m_vao, 1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, (const void*)8);
		glVertexAttribPointer(2, LGE_2DVERTEX_LAYOUT2, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, (const void*)16);
		
		glEnableVertexArrayAttrib(m_vao, 2);
		m_indexBuffer = new IndexBuffer();

		shaderProgram = new ShaderProgram("res/shader/basic.shader");
		LGE_RESULT result = shaderProgram->Compile();
		UseShader(shaderProgram);
		shaderProgram->SetUniformMat4("u_mvp", projector.GetProjectionMatrix());



		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glUseProgram(0);
		glBindVertexArray(0);
	}
	
	void RenderContext::QueueMesh(Mesh* mesh)
	{
		m_meshQueue.push_back(mesh);

	}

	

	void RenderContext::LoadQueue(unsigned int target)
	{

		if((target & LGE_MESH_QUEUE) == LGE_MESH_QUEUE)
		{
			for (auto& mesh : m_meshQueue)
			{
				unsigned int* indexBuffer = new unsigned int[mesh->GetNumIndices()];
				for (int i = 0; i < mesh->GetNumIndices();i++)
				{

					indexBuffer[i] = mesh->GetIndices()[i] + (m_vertexBuffer->GetSize() / LGE_2DVERTEX_SIZE);

				}
				mesh->SetIndexBuffer(indexBuffer);
				mesh->LoadIntoVertexBuffer(m_vertexBuffer, 0);
				mesh->LoadIntoIndexBuffer(m_indexBuffer, 0);
				m_renderObjects.push_back(mesh);
			}
			m_meshQueue.clear();
		}
		
		

	}
	void RenderContext::UpdateBuffers()
	{
		for (auto& mesh : m_renderObjects)
		{
			
			size_t size;
			float* vertexData = mesh->SerialzeToBuffer(&size);
			m_vertexBuffer->UpdateBuffer(mesh->GetOffset(), size, vertexData);
		}

	}
	void RenderContext::Draw()
	{

		if (m_renderObjects.size() > 0)
		{
			UseShader(shaderProgram);

			//shaderProgram->SetUniform4f("u_color",0.5,1.0,0.25f,1.0f);
			shaderProgram->SetUniform1i32("u_MainTex",0);
			glBindVertexArray(m_vao);
			m_indexBuffer->Bind();
			
			glDrawElements(GL_TRIANGLES, m_indexBuffer->GetSize(), GL_UNSIGNED_INT, nullptr);
			glBindVertexArray(0);

		}



	}

	LGE_RESULT RenderContext::UseShader(ShaderProgram* shader)
	{
		if (shader->GetProgram() == LGE_SHADER_NOTCOMPILED) {
			std::cout << "Shader not compiled\n";
			//m_error = LGE_SHADER_NOTCOMPILED;
			return LGE_SHADER_NOTCOMPILED;
		}
		else {
			glUseProgram(shader->GetProgram());
		}


	}
}


