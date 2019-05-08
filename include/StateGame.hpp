/*
 * StateGame.hpp
 *
 *  Created on: May 8, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_STATEGAME_HPP_
#define HUNGRYDOT_INCLUDE_STATEGAME_HPP_

#include "HungryDot.h"
#include "World.h"
#include "BaseState.h"
#include "InputEvents.h"

class StateGame : public BaseState
{

	public:

		StateGame(SharedContext& arg_context , StateStack& arg_stateStack);

		void update(sf::Time dt);
		void render();
		void handleInput(InputEvents::Ev);

	private:

		HungryDot m_hungryDot;
		World m_world;

};


#endif /* HUNGRYDOT_INCLUDE_STATEGAME_HPP_ */
