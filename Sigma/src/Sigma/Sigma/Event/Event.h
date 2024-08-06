#pragma once

#include <string>
#include <functional>

#include "Sigma/Core/Base.h"

namespace Sigma
{
	enum class EventType
	{
		None = 0,
		WindowResize, WindowClose, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput =       BIT(1),
		EventCategoryKeyboard =    BIT(2),
		EventCategoryMouse =       BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class Event
	{
		friend class EventDispatcher;
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:mEvent(event)
		{}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (T::GetStaticType() == mEvent.GetEventType())
			{
				mEvent.Handled = func(*(T*)&mEvent);
				return true;
			}
			return false;
		}

	private:
		Event& mEvent;
	};
}