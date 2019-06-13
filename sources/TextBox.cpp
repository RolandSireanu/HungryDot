/*
 * TextBox.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: roland
 */

#include "TextBox.h"

TextBox::TextBox(unsigned int arg_x_pos , unsigned int arg_y_pos) :
	enteredText("")
{
	font.loadFromFile("Media/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(36);
	text.setString("");
	text.setPosition((float)arg_x_pos , (float)arg_y_pos);
	text.setColor(sf::Color::White);

}



void TextBox::handleEvent(InputEvents::Ev arg_ev)
{
	std::cout<<"Input ev received by Textbox"<<std::endl;

	if(arg_ev.keyboardKey >= sf::Keyboard::A && arg_ev.keyboardKey <= sf::Keyboard::Z)
	{
		enteredText += mappedCharacters[arg_ev.keyboardKey];
	}

	text.setString(enteredText);
}


void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(text , states);

}

const std::string& TextBox::getText()
{
	return enteredText;
}
