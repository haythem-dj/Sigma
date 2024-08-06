#include "sgpch.h"
#include "Window.h"

#include "../../Platform/Windows/WindowsWindow.h"

namespace Sigma
{
	Window* Window::Create(WindowProps props)
	{
		#ifdef SG_PLATFORM_WINDOWS
		return new WindowsWindow(props);
		#else
		#error Sigma only supports Windows for now
		#endif
	}
}
