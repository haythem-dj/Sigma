#pragma once

#include <glm/glm.hpp>

#include "../Core/Base.h"

namespace Sigma
{
	class SIGMA_API Input
	{
	public:
		static bool IsKeyPressed(int keyCode);
		static bool IsMouseButtonPressed(int button);
		static glm::vec2 GetMousePos();
		static float GetMouseX();
		static float GetMouseY();
	};
}
