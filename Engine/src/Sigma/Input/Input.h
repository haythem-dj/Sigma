#pragma once

#include <GLM/glm.hpp>

namespace Sigma
{
	class Input
	{
	public:
		static bool IsKeyPressed(int keyCode);
		static bool IsMouseButtonPressed(int button);
		static glm::vec2 GetMousePos();
		static float GetMouseX();
		static float GetMouseY();
	};
}
