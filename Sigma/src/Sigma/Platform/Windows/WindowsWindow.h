#pragma once

#include "../../Sigma/Core/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sigma
{
	class SIGMA_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowProps props);
		~WindowsWindow();

		void Update() override;
		void SetEventCallback(const EventCallback& eventCallback) override { mData.Callback = eventCallback; }

		unsigned int GetWidth() const override { return mData.Width; }
		unsigned int GetHeight() const override { return mData.Height; }

		void* GetNativeWindow() const override { return mNativeWindow; }

	private:
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			EventCallback Callback;
		};

		WindowData mData;

		GLFWwindow* mNativeWindow;
		
	};
}