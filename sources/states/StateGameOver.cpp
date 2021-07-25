/*
 * StateGameOver.cpp
 *
 *  Created on: May 18, 2019
 *      Author: roland
 */


#include "StateGameOver.h"


StateGameOver::StateGameOver(BaseState::SharedContext& arg_sharedContext , StateStack* arg_stateStack):BaseState(arg_sharedContext , arg_stateStack)
{
	sgoFont.loadFromFile(MediaResources::getFont());
	sgoGameOverText.setFont(sgoFont);
	sgoGameOverText.setCharacterSize(60);
	sgoGameOverText.setPosition(140,180);
	sgoGameOverText.setFillColor(sf::Color::Blue);
	sgoGameOverText.setColor(sf::Color::Red);
	sgoGameOverText.setString("GAME OVER");

}

void StateGameOver::Update(sf::Time)
{

}
void StateGameOver::Render()
{
	sharedContext.sharedRenderWindow.draw(sgoGameOverText);
}

void StateGameOver::HandleInput(InputEvents::Ev arg_ev)
{
	if(arg_ev.joystickButton == sf::Joystick::X || arg_ev.keyboardKey == sf::Keyboard::Return)
	{
		m_stateStack->addStateToStack(BaseState::STATES::STATE_GAME);
	}
}
