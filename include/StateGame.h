/*
 * StateGame.h
 *
 *  Created on: May 8, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_STATEGAME_H_
#define HUNGRYDOT_INCLUDE_STATEGAME_H_

#include "HungryDot.h"
#include "World.h"
#include "BaseState.h"
#include "InputEvents.h"
#include "StateStack.h"

class StateGame : public BaseState
{

	public:

		StateGame(SharedContext& arg_context , StateStack* arg_stateStack);

		void Update(sf::Time dt) override ;
		void Render() override;
		void HandleInput(InputEvents::Ev) override;

		~StateGame()
		{
			std::cout<<"StateGame destructor"<<std::endl;
		}

	private:

		HungryDot m_hungryDot;
		World m_world;

};


#endif /* HUNGRYDOT_INCLUDE_STATEGAME_H_ */
