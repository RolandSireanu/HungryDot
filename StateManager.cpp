#include "StateManager.h"


template<class T>
void StateManager::RegisterState(const StateType& l_type)
{
	m_stateFactory[l_type] = [this]() -> BaseState*
			{
				return new T(this);
			};
}


StateManager::StateManager(SharedContext* arg_shared):m_shared(arg_shared)
{
	//RegisterState<State_Intro>(StateType::Intro);
}
