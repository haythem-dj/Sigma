#include "sgpch.h"
#include "Input.h"

#include "../Core/Application.h"

namespace Sigma
{
	bool Input::IsKeyPressed(int keyCode)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow().GetNativeWindow();
		int state = glfwGetKey(window, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(int button)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow().GetNativeWindow();
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	glm::vec2 Input::GetMousePos()
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow().GetNativeWindow();
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return glm::vec2((float)xPos, (float)yPos);
	}

	float Input::GetMouseX()
	{
		return GetMousePos().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePos().y;
	}
}
