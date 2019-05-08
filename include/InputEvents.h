/*
 * InputEvents.h
 *
 *  Created on: May 8, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_INPUTEVENTS_H_
#define HUNGRYDOT_INCLUDE_INPUTEVENTS_H_

#include "SFML/Graphics.hpp"

namespace InputEvents
{
	struct Ev
	{
		Ev(unsigned int arg_jb , sf::Keyboard::Key arg_kk): joystickButton(arg_jb) , keyboardKey(arg_kk)
		{

		}

		bool operator==(const Ev& arg1)const
		{
			if(this->joystickButton == arg1.joystickButton && this->keyboardKey == arg1.keyboardKey)
				return true ;
			else
				return false;

		}

		unsigned int joystickButton;
		sf::Keyboard::Key keyboardKey;
	};

}
#endif /* HUNGRYDOT_INCLUDE_INPUTEVENTS_H_ */
