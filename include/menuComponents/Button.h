/*
 * Button.h
 *
 *  Created on: May 19, 2019
 *      Author: roland
 */


#include "Component.h"
#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <array>
#include <iostream>
#include "BaseState.h"
#include "StateStack.h"

class Button : public Component
{

	public:

		Button(const std::string& arg_t , unsigned int arg_x_pos , unsigned int arg_y_pos , BaseState::STATES arg_state);

		void handleEvent(InputEvents::Ev) override;
		void setColor(sf::Color arg_color);

		BaseState::STATES buttonState;

		~Button()
		{
			std::cout<<"Calling Button destructor ! "<<std::endl;
		}

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Text buttonText;
		sf::Font buttonFont;



	private :


};

