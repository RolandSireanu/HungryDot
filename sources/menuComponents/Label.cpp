/*
 * Label.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: roland
 */


#include "Label.h"

void Label::handleEvent(InputEvents::Ev)
{
	return;
}

Label::Label(std::string arg_text , unsigned int arg_x_pos , unsigned int arg_y_pos)
{
	labelFont.loadFromFile(MediaResources::getFont());
	labelText.setFont(labelFont);
	labelText.setCharacterSize(36);
	labelText.setColor(sf::Color::White);
	labelText.setPosition((float) arg_x_pos , (float)arg_y_pos);
	labelText.setString(arg_text);
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(labelText , states);
}
