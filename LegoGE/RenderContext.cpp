#include "RenderContext.h"

namespace LGE
{
	RenderContext::RenderContext(Projector projector)
	{
		m_projector = projector;
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);
		m_vertexBuffer = new VertexBuffer();
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, LGE_2DVERTEX_SIZE, GL_FLOAT, GL_FALSE, sizeof(float) * LGE_2DVERTEX_SIZE, 0);
		m_indexBuffer = new IndexBuffer();
		
		
		
		shaderProgram = new ShaderProgram("res/shader/basic.shader");
		LGE_RESULT result = shaderProgram->Compile();
		UseShader(shaderProgram);
		int location = glGetUniformLocation(shaderProgram->GetProgram(), "u_mvp");
		glUniformMatrix4fv(location, 1, GL_FALSE, &m_projector.GetProjectionMatrix()[0][0]);


		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		glUseProgram(0);
		glBindVertexArray(0);
	}
	
	void RenderContext::QueueMesh(Mesh2D* mesh)
	{
		m_meshQueue.push_back(mesh);

	}
	void RenderContext::LoadMeshQueue()
	{
		for(auto& mesh : m_meshQueue)
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
			int location = glGetUniformLocation(shaderProgram->GetProgram(), "u_color");
			glUniform4f(location, 0.5, 1.0f, 0.25f, 1.0f);
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


