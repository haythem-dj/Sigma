#include "sgpch.h"
#include "Input.h"

#include "Platform/Windows/WindowsInput.h"

namespace Sigma
{
	#ifdef SG_PLATFORM_WINDOWS
	Input* Input::sInstance = new WindowsInput();
	#else
	#error Sigma only supports Windows for now
	#endif
}
