/*
 * TextBox.h
 *
 *  Created on: Jun 1, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_TEXTBOX_H_
#define HUNGRYDOT_INCLUDE_TEXTBOX_H_

#include "Component.h"
#include <iostream>
#include <string>
#include "Globals.h"
#include "StateStack.h"

class TextBox : public Component
{
	public:

	TextBox(unsigned int arg_x_pos , unsigned int arg_y_pos);

	void handleEvent(InputEvents::Ev) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	const std::string& getText();

	private:

		sf::Text text;
		sf::Font font;
		std::string enteredText;
		const std::array<unsigned char , 26> mappedCharacters {

			        'A',        		  ///< The A key
			        'B',            ///< The B key
			        'C',            ///< The C key
			        'D',            ///< The D key
			        'E',            ///< The E key
			        'F',            ///< The F key
			        'G',            ///< The G key
			        'H',            ///< The H key
			        'I',            ///< The I key
			        'J',            ///< The J key
			        'K',            ///< The K key
			        'L',            ///< The L key
			        'M',            ///< The M key
			        'N',            ///< The N key
			        'O',            ///< The O key
			        'P',            ///< The P key
			        'Q',            ///< The Q key
			        'R',            ///< The R key
			        'S',            ///< The S key
			        'T',            ///< The T key
			        'U',            ///< The U key
			        'V',            ///< The V key
			        'W',            ///< The W key
			        'X',            ///< The X key
			        'Y',            ///< The Y key
			        'Z'
		};

};



#endif /* HUNGRYDOT_INCLUDE_TEXTBOX_H_ */
