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
#include "MediaResources.h"

class StateGameOver : public BaseState
{
	public:

		StateGameOver(BaseState::SharedContext& arg_sharedContext , StateStack* arg_stateStack);

		void Update(sf::Time) override ;
		void Render() override;
		void HandleInput(InputEvents::Ev) override;

	private:

		sf::Text sgoGameOverText;
		sf::Font sgoFont;

};



#endif /* HUNGRYDOT_INCLUDE_STATEGAMEOVER_H_ */
