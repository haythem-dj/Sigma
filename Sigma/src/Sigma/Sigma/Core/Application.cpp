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
}

namespace Sigma
{
	Application* Application::sInstance;

	Application::Application()
	{
		sInstance = this;

		mWindow = Window::Create();
		mWindow->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEPTH_TEST);
		
		glDebugMessageCallback(ErrorCallback, 0);

		mRunning = true;
	}

	Application::~Application()
	{
		glfwTerminate();
	}

	bool Application::OnResize(WindowResizeEvent& e)
	{
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return true;
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		// dispatcher.Dispatch<WindowCloseEvent>((*)(&Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnResize));
	}

	void Application::Run()
	{
		float dt = 1.0f;
		while(mRunning)
		{
			double start = glfwGetTime();

			glClearColor(mBackgroundColor.x, mBackgroundColor.y, mBackgroundColor.z, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            mActiveScene->Update(dt);

			mWindow->Update();

			dt = (float)(glfwGetTime() - start);
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		mRunning = false;
		return true;
	}
}
