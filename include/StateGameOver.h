/*
 * StateGameOver.h
 *
 *  Created on: May 18, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_STATEGAMEOVER_H_
#define HUNGRYDOT_INCLUDE_STATEGAMEOVER_H_

#include "BaseState.h"
#include "SFML/Graphics.hpp"
#include "FpsRegulator.h"
#include "StateStack.h"

class StateGameOver : public BaseState
{
	public:

		void Update(sf::Time) override ;
		void Render() override;
		void HandleInput(InputEvents::Ev) override;


};



#endif /* HUNGRYDOT_INCLUDE_STATEGAMEOVER_H_ */
