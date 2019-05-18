/*
 * StateGame.cpp
 *
 *  Created on: May 8, 2019
 *      Author: roland
 */


#include "../include/StateGame.h"


StateGame::StateGame(SharedContext& arg_context , StateStack* arg_stateStack):
	BaseState(arg_context , arg_stateStack),
	m_hungryDot(HungryDot::Direction::RIGHT , 6 , 6 , 0.0f , 0.0f),
	m_world()
{

}


void StateGame::Update(sf::Time dt)
{
	m_hungryDot.Update(dt);
	if(m_world.Update(m_hungryDot , dt) == true)
	{
		m_stateStack->addStateToStack(BaseState::STATES::STATE_GAME);
	}
}
void StateGame::Render()
{
	m_hungryDot.Render(sharedContext.sharedRenderWindow);
	m_world.Render(sharedContext.sharedRenderWindow , m_hungryDot);
}

void StateGame::HandleInput(InputEvents::Ev arg_event)
{
	/*sf::Event event;
	HungryDot::Ev inputEvent = {0xFF,sf::Keyboard::Key::Unknown};
	//bool joystickConnected = sf::Joystick::isConnected(0);

	//while(m_window.GetRenderWindow().pollEvent(event))
	while(sharedContext.sharedRenderWindow.pollEvent(event))
	{

		if(event.type == sf::Event::JoystickButtonPressed)
		{
			inputEvent.joystickButton = event.joystickButton.button;
		}

		if(event.type == sf::Event::KeyPressed)
		{
			inputEvent.keyboardKey = event.key.code;
		}

		std::cout<<"inputEvent = "<<inputEvent.joystickButton<<" , "<<(unsigned int)inputEvent.keyboardKey<<std::endl;
		*/
		m_hungryDot.HandleInput(arg_event);
}
