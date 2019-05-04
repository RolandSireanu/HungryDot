/*
 * BaseState.h
 *
 *  Created on: Feb 25, 2019
 *      Author: roland
 */

#ifndef STATE_INTRO_H
#define STATE_INTRO_H

#include "BaseState.h"
#include "SFML/Graphics.hpp"

class StateIntro : public BaseState
{

	public:

		StateIntro(BaseState::SharedContext& arg_sharedContext , StateStack& arg_stateStack) : BaseState(arg_sharedContext , arg_stateStack)
		{
			font.loadFromFile("Media/arial.ttf");

			text.setFont(font);
			text.setCharacterSize(18);
			text.setPosition(50,50);
			text.setFillColor(sf::Color::Red);
			text.setColor(sf::Color::Blue);

			text.setString("WELCOME !");
		}

		void Update();
		void Render();
		void HandleInput();

		~StateIntro();

	private :

		sf::Font font;
		sf::Text text;

};



#endif /* BASESTATE_H_ */
