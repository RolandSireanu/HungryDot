/*
 * Button.cpp
 *
 *  Created on: May 19, 2019
 *      Author: roland
 */

#include "Button.h"

Button::Button(const std::string& arg_t , unsigned int arg_x_pos , unsigned int arg_y_pos , BaseState::STATES arg_state) : buttonState(arg_state)
{
	buttonFont.loadFromFile(MediaResources::getFont());
	buttonText.setFont(buttonFont);
	buttonText.setCharacterSize(42);
	buttonText.setPosition(arg_x_pos,arg_y_pos);
	buttonText.setColor(sf::Color::White);
	buttonText.setString(arg_t);
}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(buttonText , states);
}

void Button::setColor(sf::Color arg_color)
{
	buttonText.setColor(arg_color);
}

void Button::handleEvent(InputEvents::Ev arg_ev)
{
/*
	std::cout<<"Input ev received !"<<std::endl;
	if(arg_ev.keyboardKey == sf::Keyboard::Key::Down ||  arg_ev.joystickButton == 0)
	{
		buttonCounter = (buttonCounter+1) % Button::nrOfButtons;
		//Down arrow or Cross
	}
	else if (arg_ev.keyboardKey == sf::Keyboard::Key::Up ||  arg_ev.joystickButton == 2)
	{
		//buttonCounter = (Button::nrOfButtons - 1) - (buttonCounter-1);
		buttonCounter = (buttonCounter-1) < 0 ? Button::nrOfButtons : (buttonCounter -1);
		//Up or Triangle
	}

	for(auto i : buttons)
	{
		i->setColor(sf::Color::White);
	}

	buttons.at(buttonCounter)->setColor(sf::Color::Blue);
	*/
}
