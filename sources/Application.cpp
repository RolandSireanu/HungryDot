/*
 * Application.cpp
 *
 *  Created on: May 7, 2019
 *      Author: roland
 */




#include "Application.h"



Application::Application():m_window("Hungry dot" , FpsRegulator::resolution),
						   sharedContext(m_window.GetRenderWindow()),
						   stateStack(sharedContext)
{
	stateStack.addStateToStack(BaseState::STATES::STATE_INTRO);
}


void Application::run()
{

	sf::Clock clock;
	long long oldTimeStamp = 0;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;


	while(!m_window.IsDone())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		handleInputs();
		while(timeSinceLastUpdate > FpsRegulator::timePerFrame)
		{
			timeSinceLastUpdate -= FpsRegulator::timePerFrame;
			update(FpsRegulator::timePerFrame);
		}

		render();
	}
}


void Application::update(sf::Time deltaT)
{

	stateStack.update(deltaT);

}

void Application::render()
{
	m_window.BeginDraw();

	stateStack.render();

	m_window.EndDraw();

}



void Application::handleInputs()
{
	sf::Event event;
	InputEvents::Ev inputEvent = {0xFF,sf::Keyboard::Key::Unknown};
	//bool joystickConnected = sf::Joystick::isConnected(0);

	while(m_window.GetRenderWindow().pollEvent(event))
	{

		if(event.type == sf::Event::JoystickButtonPressed)
		{
			inputEvent.joystickButton = event.joystickButton.button;
			stateStack.handleInput(inputEvent);
		}

		if(event.type == sf::Event::KeyPressed)
		{
			inputEvent.keyboardKey = event.key.code;
			stateStack.handleInput(inputEvent);
		}

		std::cout<<"inputEvent = "<<inputEvent.joystickButton<<" , "<<(unsigned int)inputEvent.keyboardKey<<std::endl;

	}
}










