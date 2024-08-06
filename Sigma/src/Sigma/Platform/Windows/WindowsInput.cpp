#include "sgpch.h"
#include "WindowsInput.h"

#include "Sigma/Core/Application.h"

#include <glfw/glfw3.h>

namespace Sigma
{
	bool WindowsInput::IsKeyPressedImpl(int keyCode)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow();
		int state = glfwGetKey(window, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow();
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	glm::vec2 WindowsInput::GetMousePosImpl()
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow()->GetNativeWindow();
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return glm::vec2((float)xPos, (float)yPos);
	}

	float WindowsInput::GetMouseXImpl()
	{
		return GetMousePos().x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		return GetMousePos().y;
	}
}