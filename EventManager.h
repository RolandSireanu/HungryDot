#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <unordered_map>
#include <functional>
#include "SFML/Graphics.hpp"

enum class EventType{
	KeyDown = sf::Event::KeyPressed,
	KeyUp = sf::Event::KeyReleased,
	MButtonDown = sf::Event::MouseButtonPressed,
	MButtonUp = sf::Event::MouseButtonReleased,
	MouseWheel = sf::Event::MouseWheelMoved,
	WindowResized = sf::Event::Resized,
	GainedFocus = sf::Event::GainedFocus,
	LostFocus = sf::Event::LostFocus,
	MouseEntered = sf::Event::MouseEntered,
	MouseLeft = sf::Event::MouseLeft,
	Closed = sf::Event::Closed,
	TextEntered = sf::Event::TextEntered,
	Keyboard = sf::Event::Count + 1,
	Mouse,
	Joystick
};

struct EventInfo
{
	EventInfo() { m_code = 0; }
	EventInfo(int arg_code) { m_code = arg_code; }

	union
	{
		int m_code;
	};

};

using Events = std::vector<std::pair<EventType , EventInfo>>;


struct EventDetails
{
	EventDetails(const std::string& arg_bindName)
	{
		m_name = arg_bindName;
	}

	std::string m_name;
	sf::Vector2i m_size;
	sf::Uint32 m_textEntered;
	sf::Vector2i m_mouse;
	int m_mouseWheelDelta;
	int m_keyCode;

	void Clear()
	{
		m_size = sf::Vector2i(0,0);
		m_textEntered = 0;
		m_mouse = sf::Vector2i(0,0);
		m_mouseWheelDelta = 0;
		m_keyCode = -1;
	}

};

struct Binding
{
	Binding(const std::string& arg_name): m_name(arg_name) , m_details(arg_name) , c(0)
	{}

	void AddEvent(EventType arg_evType , EventInfo arg_evInfo)
	{
		m_events.emplace_back(arg_evType , arg_evInfo);
	}


	Events m_events;
	EventDetails m_details;
	int c;
	std::string m_name;
};

using Callbacks = std::unordered_map<std::string , std::function<void(EventDetails*)>>;
using Bindings = std::unordered_map<std::string , Binding*>;

template <class T>
struct Callback
{
	T* CallbackInstance;
	void(T::*_callback)();


};


class EventManager
{
	public:

		EventManager();
		~EventManager();

		bool AddBinding(Binding* arg_binding);
		bool RemoveBinding(std::string& arg_name);
		void SetFocus(bool arg_focus);

		template<class T>
		bool AddCallback(const std::string& arg_name ,
				void(T::*l_func)(EventDetails*) , T* arg_instance);

		void RemoveCallback(const std::string& arg_name)
		{
			m_callbacks.erase(arg_name);
		}

	private:
		Bindings m_bindings;
		Callbacks m_callbacks;
		bool m_hasFocus;


};

#endif
