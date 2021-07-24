/*
 * Label.h
 *
 *  Created on: Jun 1, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_LABEL_H_
#define HUNGRYDOT_INCLUDE_LABEL_H_
#include "Component.h"
#include <string>

class Label : public Component
{

	public:
		Label(std::string arg_text , unsigned int arg_x_pos , unsigned int arg_y_pos);
		void handleEvent(InputEvents::Ev) override;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

		sf::Text labelText;
		sf::Font labelFont;

};



#endif /* HUNGRYDOT_INCLUDE_LABEL_H_ */
