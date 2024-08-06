#pragma once

#include "Base.h"

#include "Sigma/Event/Event.h"

#include <string>

namespace Sigma
{
	struct SIGMA_API WindowProps
	{
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Sigma Window", unsigned int width = 1080, unsigned int height = 608)
			:Title(title), Width(width), Height(height)
		{}
	};

	class SIGMA_API Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void Update() = 0;
		virtual void SetEventCallback(const EventCallback& eventCallback) = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(WindowProps props = WindowProps());
	};
}
