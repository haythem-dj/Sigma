#include "sgpch.h"
#include "ShaderProgram.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sigma
{
	ShaderProgram::ShaderProgram()
	{
	}

	ShaderProgram::~ShaderProgram()
	{
		
	}

	void ShaderProgram::Init(const std::string& vsPath, const std::string& fsPath)
	{
		mID = CreateProgram(LoadShader(vsPath), LoadShader(fsPath));
	}

	void ShaderProgram::Activate() const
	{
		glUseProgram(mID);
	}

	void ShaderProgram::Deactivate() const
	{
		glUseProgram(0);
	}

	void ShaderProgram::Delete()
	{
		glDeleteProgram(mID);
	}

	std::string ShaderProgram::LoadShader(const std::string& path)
	{
		std::ifstream stream(path);

		std::string line;
		std::stringstream ss;

		while(getline(stream, line))
		{
			ss << line << "\n";
		}

		stream.close();
		
		return ss.str();
	}

	unsigned int ShaderProgram::CompileShader(unsigned int type, const std::string& source)
	{
		unsigned int shader = glCreateShader(type);
		const char* src = source.c_str();

		glShaderSource(shader, 1, &src, nullptr);
		glCompileShader(shader);

		int result;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			int length;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)malloc(length*sizeof(char));
			glGetShaderInfoLog(shader, length, &length, message);
			SG_CORE_ERROR("Failed to compile the {0} shader", (type==GL_VERTEX_SHADER ? "Vertex" : "Fragment"));
			SG_CORE_ERROR("{0}", message);
		}

		return shader;
	}

	unsigned int ShaderProgram::CreateProgram(const std::string& vertexShader, const std::string& fragmentShader)
	{
		unsigned int program = glCreateProgram();

		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		glAttachShader(program, vs);
		glAttachShader(program, fs);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}
}
