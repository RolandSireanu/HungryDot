/*
 * StateRegister.cpp
 *
 *  Created on: Jun 1, 2019
 *      Author: roland
 */




#include "StateRegister.h"

StateRegister::StateRegister(SharedContext& arg_context , StateStack* arg_stateStack) :
	BaseState(arg_context , arg_stateStack) , labelName("NAME : " , 80 , 240),
	textBox(210,240) , rectangle(sf::Vector2f(500, 50))
{
	rectangle.setPosition(70 , 238);
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setOutlineThickness(3.0f);

}

void StateRegister::Update(sf::Time)
{

}

void StateRegister::Render()
{
	sharedContext.sharedRenderWindow.draw(rectangle);
	sharedContext.sharedRenderWindow.draw(labelName);
	sharedContext.sharedRenderWindow.draw(textBox);
}

void StateRegister::HandleInput(InputEvents::Ev arg_ev)
{
	if(arg_ev.keyboardKey == sf::Keyboard::Return)
	{
			Globals::currentPlayer = textBox.getText();
			m_stateStack->addStateToStack(BaseState::STATES::STATE_INTRO);
	}
	else
		textBox.handleEvent(arg_ev);
}
