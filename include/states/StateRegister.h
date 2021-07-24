/*
 * StateRegister.h
 *
 *  Created on: Jun 1, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_STATEREGISTER_H_
#define HUNGRYDOT_INCLUDE_STATEREGISTER_H_

#include "BaseState.h"
#include "Label.h"
#include "TextBox.h"

class StateRegister : public BaseState
{
	public:

		StateRegister(SharedContext& arg_context , StateStack* arg_stateStack);

		void Update(sf::Time) override;
		void Render() override;
		void HandleInput(InputEvents::Ev) override;

		~StateRegister(){}


	private:

		Label labelName;
		TextBox textBox;
		sf::RectangleShape rectangle;

};



#endif /* HUNGRYDOT_INCLUDE_STATEREGISTER_H_ */
