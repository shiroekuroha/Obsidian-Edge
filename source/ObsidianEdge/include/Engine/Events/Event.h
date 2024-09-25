#ifndef OE_EVENT_H
#define OE_EVENT_H

namespace ObsidianEdge
{
	enum class EventType
	{
		None = 0,

		// Windows Events
		WindowResize,
		WindowClose,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		// App Events
		AppTick,
		AppUpdate,
		AppRender,

		// Key Events
		KeyPressed,
		KeyReleased,
		KeyTyped,

		// Mouse Events
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,

		EventCategoryApplication = 0b1,
		EventCategoryInput = 0b10,
		EventCategoryKeyboard = 0b100,
		EventCategoryMouse = 0b1000,
		EventCategoryMouseButton = 0b10000,
		EventCategoryMouseMotion = 0b100000
	};

	class Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategoryFlags() const = 0;

		virtual const char *GetEventName() const = 0;
		virtual std::string ToString() const { return GetEventName(); }

		inline bool IsInCategory(EventCategory e)
		{
			return GetEventCategoryFlags() & e;
		}

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event &event)
			: m_Event(event) {}

		template <typename T, typename F>
		bool Dispatch(F *func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(m_Event);
				return true;
			}

			return false;
		}

	private:
		Event &m_Event;
	};

#define EVENT_CLASS_TYPE(type)                                         \
	static EventType GetStaticType() { return EventType::type; }       \
	virtual EventType GetEventType() const { return GetStaticType(); } \
	virtual const char *GetName() const { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
	virtual int GetCategoryFlags() const { return category; }
}

#endif