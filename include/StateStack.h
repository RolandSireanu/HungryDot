/*
 * StateStack.h
 *
 *  Created on: Apr 30, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_STATESTACK_H_
#define HUNGRYDOT_INCLUDE_STATESTACK_H_

#include "BaseState.h"
#include <map>
#include <functional>

class StateStack
{

	public:

		StateStack(BaseState::SharedContext& arg_sharedContext);


		void addStateToStack(BaseState::STATES arg_state)
		{
			currentState = statesFactory[arg_state]();
		}

		void update(sf::Time deltaT)
		{
			currentState->Update(deltaT);
		}

		void render()
		{
			currentState->Render();
		}

	private:
		struct BaseState::SharedContext context;

		template<typename StateType>
		void registerState(BaseState::STATES arg_stateID);


		//std::map<BaseState::STATES , std::function<std::unique_ptr<StateType>(void)> > statesFactory;
		std::map<BaseState::STATES , std::function<std::unique_ptr<BaseState> ()> > statesFactory;
		std::unique_ptr<BaseState> currentState;

};



#endif /* HUNGRYDOT_INCLUDE_STATESTACK_H_ */