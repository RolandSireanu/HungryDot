#include "EventManager.h"

template<class T>
bool EventManager::AddCallback(const std::string& arg_name ,
				void(T::*l_func)(EventDetails*) , T* arg_instance)
{

	//temporary is a std::function which keep a callable
	auto temporary = std::bind(l_func , arg_instance , std::placeholders::_1);
	bool insertionSuccess;

	insertionSuccess = m_callbacks.emplace(arg_name , temporary).second;

	return insertionSuccess;

}


