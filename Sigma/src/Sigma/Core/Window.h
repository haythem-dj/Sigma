#pragma once

#include "Base.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sigma
{
	class SIGMA_API Window
	{
	public:
		Window();
		~Window();

		void Init(unsigned int width, unsigned int height, const char* title);
		void Update();
		void Delete();

		bool IsClosed();

		GLFWwindow* GetNativeWindow() const { return mWindow; }

	private:
		GLFWwindow* mWindow = nullptr;
	};
}
