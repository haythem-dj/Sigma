#include "sgpch.h"
#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace
{
    void ErrorCallback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, const void* userParam)
	{
		switch (severity)
		{
			case GL_DEBUG_SEVERITY_HIGH:         SG_CORE_CRITICAL(message); return;
			case GL_DEBUG_SEVERITY_MEDIUM:       SG_CORE_ERROR(message); return;
			case GL_DEBUG_SEVERITY_LOW:          SG_CORE_WARN(message); return;
			case GL_DEBUG_SEVERITY_NOTIFICATION: SG_CORE_TRACE(message); return;
		}
	}

    void Resized(GLFWwindow* window, int width, int height)
	{
        Sigma::Application::Get().Resize(width, height);
	}

}

namespace Sigma
{
	Application* Application::sInstance;

	Application::Application()
		:mWidth(1080), mHeight(608)
	{
		sInstance = this;

		mWindow.Init(mWidth, mHeight, mTitle.c_str());

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEPTH_TEST);
		
		glDebugMessageCallback(ErrorCallback, 0);
		glfwSetWindowSizeCallback(mWindow.GetNativeWindow(), Resized);
	}

	Application::~Application()
	{
		mWindow.Delete();
		glfwTerminate();
	}

	void Application::Resize(unsigned int width, unsigned int height)
	{
		Application::Get().SetWidth(width);
		Application::Get().SetHeight(height);
		glViewport(0, 0, width, height);
	}

	void Application::Run()
	{
		float dt = 1.0f;
		while(!mWindow.IsClosed() && glfwGetKey(mWindow.GetNativeWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS)
		{
			double start = glfwGetTime();

			glClearColor(mBackgroundColor.x, mBackgroundColor.y, mBackgroundColor.z, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            mActiveScene->Update(dt);

			mWindow.Update();

			dt = (float)(glfwGetTime() - start);
			float fps = 1.0f / dt;
			glfwSetWindowTitle(mWindow.GetNativeWindow(), (mTitle + " | " + std::to_string(dt) + " | " + std::to_string(fps)).c_str());
		}
	}
}
