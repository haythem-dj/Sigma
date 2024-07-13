#pragma once

#include <string>

namespace Sigma
{
	class ShaderProgram
	{
	public:
		ShaderProgram();
		~ShaderProgram();

		void Init(const std::string& vsPath, const std::string& fsPath);

		void Activate() const;
		void Deactivate() const;
		void Delete();

		unsigned int GetID() const { return mID; }

	private:
		std::string LoadShader(const std::string& path);
		unsigned int CompileShader(unsigned int type, const std::string& source);
		unsigned int CreateProgram(const std::string& vertexShader, const std::string& fragmentShader);
		
	private:
		unsigned int mID = 0;
	};
}
