/*
 * StateGame.cpp
 *
 *  Created on: May 8, 2019
 *      Author: roland
 */


#include "StateGame.hpp"


StateGame::StateGame(SharedContext& arg_context , StateStack& arg_stateStack):
	BaseState(arg_context , arg_stateStack),
	m_hungryDot(HungryDot::Direction::RIGHT , 6 , 6 , 0.0f , 0.0f)
{

}


void StateGame::update(sf::Time dt)
{
	m_hungryDot.Update(dt);
	m_world.Update(m_hungryDot , dt);
}
void StateGame::render()
{

}

void StateGame::handleInput(InputEvents::Ev arg_event)
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
