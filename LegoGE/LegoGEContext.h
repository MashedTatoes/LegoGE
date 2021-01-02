#pragma once
#include "common.h"

#include <fstream>
#include "ShaderProgram.h"
#include "Quad2D.h"


namespace LGE {
	class LegoGEContext
	{
	private:
		

		GLFWwindow* glWindow;
		bool m_isRunning;
		unsigned int buffer;
		unsigned int ibo;
		unsigned int vao;
		LGE_RESULT m_error;
		void GLClearError();
		void GLCheckError();
		ShaderProgram* shaderProgram;
		Quad2D* quad;
		
	public:
		LGE_RESULT Init();
		LGE_RESULT Render();
		bool IsRunning() { return m_isRunning; }
		LGE_RESULT Update();
		LGE_RESULT GetError() { return m_error; }
		LGE_RESULT UseShader(ShaderProgram* shaderProgram);
		LGE_RESULT FillRenderBuffer(Mesh2D* mesh);
		
		

	};
}


