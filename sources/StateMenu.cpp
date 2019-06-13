/*
 * StateMenu.cpp
 *
 *  Created on: May 24, 2019
 *      Author: roland
 */

#include "StateMenu.h"

StateMenu::StateMenu(SharedContext& arg_context , StateStack* arg_stateStack): BaseState(arg_context , arg_stateStack) ,
	newGameButton(std::string("NEW GAME") , 190,200 , BaseState::STATES::STATE_INTRO) , exitGameButton(std::string("EXIT GAME") , 190 , 320 , BaseState::STATES::STATE_GAME_OVER) ,
	registerNameButton(std::string("REGISTER") , 190,260 , BaseState::STATES::STATE_REGISTER),
	buttonCounter(0) , buttons{&newGameButton , &registerNameButton , &exitGameButton}
{
	std::cout<<"StateMenu constructor ! "<<std::endl;
	newGameButton.setColor(sf::Color::Blue);
}

void StateMenu::Update(sf::Time arg_dt)
{

}

void StateMenu::Render()
{
	sharedContext.sharedRenderWindow.draw(newGameButton);
	sharedContext.sharedRenderWindow.draw(registerNameButton);
	sharedContext.sharedRenderWindow.draw(exitGameButton);
}

void StateMenu::HandleInput(InputEvents::Ev arg_ev)
{
	std::cout<<"Input ev received !"<<std::endl;
	bool downOrUp = false;
	if(arg_ev.keyboardKey == sf::Keyboard::Key::Down )
	{
		buttonCounter = (buttonCounter+1) % StateMenu::nrOfButtons;
		downOrUp = true;
		//Down arrow or Cross
	}
	else if (arg_ev.keyboardKey == sf::Keyboard::Key::Up )
	{
		//buttonCounter = (Button::nrOfButtons - 1) - (buttonCounter-1);
		downOrUp = true;
		buttonCounter = (buttonCounter-1) < 0 ? 0 : (buttonCounter -1);
		//Up or Triangle
	}

	if(downOrUp)
	{
		for(std::array<Button* , StateMenu::nrOfButtons>::value_type i : buttons)
		{
			i->setColor(sf::Color::White);
		}

		buttons.at(buttonCounter)->setColor(sf::Color::Blue);
	}
	else if (arg_ev.keyboardKey == sf::Keyboard::Key::Return)
	{

		if(buttonCounter == (StateMenu::nrOfButtons-1))
		{
			Globals::closeGameNow = true;
		}
		else
		{
			std::cout<<"m_stateStack->addStateToStack(buttons.at(buttonCounter)->buttonState);"<<std::endl;
			m_stateStack->addStateToStack(buttons.at(buttonCounter)->buttonState);
		}
	}
	else
		return;


}


