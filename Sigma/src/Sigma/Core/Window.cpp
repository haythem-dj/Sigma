#include "sgpch.h"
#include "Window.h"

namespace Sigma
{
	Window::Window()
	{
		if(!glfwInit())
		{
			SG_CORE_ERROR("GLFW could not initalize");
			std::cin.get();
			glfwTerminate();
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	Window::~Window()
	{
		
	}

	void Window::Init(unsigned int width, unsigned int height, const char* title)
	{
		mWindow = glfwCreateWindow(width, height, title, NULL, NULL);
		if (mWindow == NULL)
		{
			SG_CORE_ERROR("mWindow could not be created");
			std::cin.get();
			glfwTerminate();
		}

		glfwMakeContextCurrent(mWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			SG_CORE_ERROR("GLAD could not be inited");
			std::cin.get();
			glfwTerminate();
		}
        glViewport(0, 0, width, height);
	}

	void Window::Update()
	{
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}

	void Window::Delete()
	{
		glfwDestroyWindow(mWindow);
	}

	bool Window::IsClosed()
	{
		return glfwWindowShouldClose(mWindow);
	}
}
