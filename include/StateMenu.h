/*
 * StateMenu.h
 *
 *  Created on: May 24, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_STATEMENU_H_
#define HUNGRYDOT_INCLUDE_STATEMENU_H_

#include "SFML/Graphics.hpp"
#include "Button.h"
#include "BaseState.h"
#include <string>
#include "Globals.h"

class StateMenu : public BaseState
{
	public:

		StateMenu(SharedContext& arg_context , StateStack* arg_stateStack);

		void Update(sf::Time) override;
		void Render() override;
		void HandleInput(InputEvents::Ev) override;

		~StateMenu() = default;
//		{
//			std::cout<<"Calling StateMenu destructor !"<<std::endl;
//		}

	protected:

		Button newGameButton;
		Button registerNameButton;
		Button exitGameButton;
		int buttonCounter;
		static constexpr unsigned int nrOfButtons = 3;
		std::array<Button* , nrOfButtons> buttons;

};



#endif /* HUNGRYDOT_INCLUDE_STATEMENU_H_ */
