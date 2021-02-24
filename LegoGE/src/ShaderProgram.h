#pragma once
#include "common.h"
typedef int LGE_SHADER;
namespace LGE 
{
	enum class ShaderType {
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};
	class ShaderProgram
	{
	private:
		std::string m_vertexSrc;
		std::string m_fragmentSrc;
		int CompileShader(unsigned int type, const std::string& source);
		int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
		LGE_SHADER m_shaderProgram;

	public:
		std::string GetVertexSource() { return m_vertexSrc; }
		std::string GetFragmentSource() { return m_fragmentSrc; }
		LGE_SHADER GetProgram() { return m_shaderProgram; }
		ShaderProgram(const std::string& path);
		ShaderProgram(const std::string& vertex, const std::string& fragment) : m_vertexSrc(vertex),m_fragmentSrc(fragment),m_shaderProgram(LGE_SHADER_NOTCOMPILED){}

		void SetUniform1f(const std::string& name, float value);
		void SetUniform1i32(const std::string& name, int value);
		void SetUniform4f(const std::string& name, float x,float y, float z, float tex_x);
		void SetUniformMat4(const std::string& name, glm::mat4 value);
		

		int GetUniformLocation(const std::string& name);

		LGE_RESULT Compile();
		

	};
}


