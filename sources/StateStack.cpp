/*
 * StateStack.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: roland
 */


#include "StateStack.h"

#include "../include/StateGame.h"
#include "StateGameOver.h"
#include "StateIntro.h"


StateStack::StateStack(BaseState::SharedContext& arg_sharedContext) : context(arg_sharedContext) , statesFactory()
{

	registerState<StateIntro>(BaseState::STATES::STATE_INTRO);
	registerState<StateGame>(BaseState::STATES::STATE_GAME);
	registerState<StateGameOver>(BaseState::STATES::STATE_GAME_OVER);
}


template<typename StateType>
void StateStack::registerState(BaseState::STATES arg_stateID)
{
	statesFactory[arg_stateID] = [&] () -> std::unique_ptr<BaseState>
	{
		return std::unique_ptr<StateType>(new StateType(context ,  this)) ;

	};
}


void StateStack::handleInput(InputEvents::Ev arg_ev)
{
	currentState->HandleInput(arg_ev);

}
