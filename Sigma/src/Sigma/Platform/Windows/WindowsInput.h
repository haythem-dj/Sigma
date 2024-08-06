#pragma once

#include "../../Sigma/Input/Input.h"

namespace Sigma
{
	class SIGMA_API WindowsInput : public Input
	{
	private:
		bool IsKeyPressedImpl(int keyCode) override;
		bool IsMouseButtonPressedImpl(int button) override;
		glm::vec2 GetMousePosImpl() override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;
	};
}