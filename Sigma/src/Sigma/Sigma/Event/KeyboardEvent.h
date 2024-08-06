#pragma once

#include <sstream>

#include "Event.h"

namespace Sigma
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeycode() const { return mKeycode; }

		int GetCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }

	protected:
		KeyEvent(int keycode)
			:mKeycode(keycode)
		{}

		int mKeycode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			:KeyEvent(keycode), mRepeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const { return mRepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << mKeycode << " (" << mRepeatCount << " repeats";
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::KeyPressed; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "KeyPressed"; }

	private:
		int mRepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeycode;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::KeyReleased; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "KeyReleased"; }
	};
}