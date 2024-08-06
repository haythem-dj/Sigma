#pragma once

#include <glm/glm.hpp>

namespace Sigma
{
	class SIGMA_API Input
	{
	public:
		inline static bool IsKeyPressed(int keyCode) { return sInstance->IsKeyPressedImpl(keyCode); }
		inline static bool IsMouseButtonPressed(int button) { return sInstance->IsMouseButtonPressedImpl(button); }
		inline static glm::vec2 GetMousePos() { return sInstance->GetMousePos(); }
		inline static float GetMouseX() { return sInstance->GetMouseXImpl(); }
		inline static float GetMouseY() { return sInstance->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keyCode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual glm::vec2 GetMousePosImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:
		static Input* sInstance;
	};
}
