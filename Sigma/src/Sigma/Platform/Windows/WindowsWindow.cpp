#include "sgpch.h"
#include "WindowsWindow.h"

#include "Sigma/Core/Log.h"

#include "Sigma/Event/ApplicationEvent.h"
#include "Sigma/Event/KeyboardEvent.h"
#include "Sigma/Event/MouseEvent.h"

namespace Sigma
{
	WindowsWindow::WindowsWindow(WindowProps props)
	{
		mData.Title = props.Title;
		mData.Width = props.Width;
		mData.Height = props.Height;

		if(!glfwInit())
		{
			SG_CORE_ERROR("GLFW could not initalize");
			glfwTerminate();
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		SG_CORE_INFO("Creating Window {0} [{1}, {2}]", mData.Title, mData.Width, mData.Height);

		mNativeWindow = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), NULL, NULL);
		if (mNativeWindow == NULL)
		{
			SG_CORE_ERROR("mNativeWindow could not be created");
			glfwTerminate();
		}

		glfwSetWindowUserPointer(mNativeWindow, &mData);

		glfwSetWindowSizeCallback(mNativeWindow, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent e(width, height);
			data.Callback(e);
		});

		glfwSetWindowCloseCallback(mNativeWindow, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			WindowCloseEvent e(0);
			data.Callback(e);
		});

		glfwSetKeyCallback(mNativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key, 0);
					data.Callback(e);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent e(key, 1);
					data.Callback(e);
					break;
				}

			case GLFW_RELEASE:
				{
					KeyReleasedEvent e(key);
					data.Callback(e);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(mNativeWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					data.Callback(e);
					break;
				}

				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					data.Callback(e);
					break;
				}
			}
		});

		glfwSetScrollCallback(mNativeWindow, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent e((float)xoffset, (float)yoffset);
			data.Callback(e);
		});

		glfwSetCursorPosCallback(mNativeWindow, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent e((float)xpos, (float)ypos);
			data.Callback(e);
		});

		glfwMakeContextCurrent(mNativeWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			SG_CORE_ERROR("GLAD could not be inited");
			std::cin.get();
			glfwTerminate();
		}
        glViewport(0, 0, mData.Width, mData.Height);
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(mNativeWindow);
		glfwTerminate();
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(mNativeWindow);
	}
}