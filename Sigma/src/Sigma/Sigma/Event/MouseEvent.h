#pragma once

#include <sstream>

#include "Event.h"

namespace Sigma
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			:mMouseX(x), mMouseY(y)
		{}

		inline float GetX() const { return mMouseX; }
		inline float GetY() const { return mMouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mMouseX << ", " << mMouseY;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseMoved; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "MouseMoved"; }
		int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }

	private:
		float mMouseX, mMouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOff, float yOff)
			:mOffsetX(xOff), mOffsetY(yOff)
		{}

		inline float GetXOffset() const { return mOffsetX; }
		inline float GetYOffset() const { return mOffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << mOffsetX << ", " << mOffsetY;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseScrolled; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "MouseScrolled"; }
		int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }

	private:
		float mOffsetX, mOffsetY;
	};

	class MouseButton : public Event
	{
	public:
		inline int GetButton() const { return mButton; }

		int GetCategoryFlags() const override { return EventCategoryMouseButton | EventCategoryMouse | EventCategoryInput; }

	protected:
		MouseButton(int button)
			:mButton(button)
		{}
		int mButton;
	};

	class MouseButtonPressedEvent : public MouseButton
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButton(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mButton;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseButtonPressed; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "MouseButtonPressed"; }
	};

	class MouseButtonReleasedEvent : public MouseButton
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButton(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mButton;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseButtonReleased; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "MouseButtonReleased"; }
	};
}