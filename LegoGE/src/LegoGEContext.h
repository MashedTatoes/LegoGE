#pragma once
#include "common.h"

#include <fstream>
#include "ShaderProgram.h"

#include "RenderContext.h"

namespace LGE {
	class LegoGEContext
	{
	private:
		

		GLFWwindow* glWindow;
		bool m_isRunning;
		
		LGE_RESULT m_error;
		void GLClearError();
		void GLCheckError();
		ShaderProgram* shaderProgram;
		RenderContext* m_renderer;
		Projector* m_projector;

		
	public:
		LGE_RESULT Init(int windowWidth, int windowHeight);
		LGE_RESULT Render();
		bool IsRunning() { return m_isRunning; }
		LGE_RESULT Update();
		LGE_RESULT GetError() { return m_error; }
		Projector GetProjector() { return *m_projector; }
		
		void BindRenderContext(RenderContext* renderer) { m_renderer = renderer; }
		
		

	};
}


