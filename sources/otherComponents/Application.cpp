/*
 * Application.cpp
 *
 *  Created on: May 7, 2019
 *      Author: roland
 */




#include "Application.h"
#include "DataBase.h"
#include "Timer.h"
#include "MediaResources.h"


Application::Application():m_window("Hungry dot" , {650,450}),
						   sharedContext(m_window.GetRenderWindow()),
						   stateStack(sharedContext)
{

	//stateStack.addStateToStack(BaseState::STATES::STATE_INTRO);
	stateStack.addStateToStack(BaseState::STATES::STATE_MENU);

}

Application::~Application()
{
}

void Application::run()
{

	sf::Clock clock;
	long long oldTimeStamp = 0;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	std::shared_ptr<DataBase> db = DataBase::GetObject();

	while(!m_window.IsDone() && Globals::closeGameNow != true)
	{		
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		handleInputs();
		while(timeSinceLastUpdate > FpsRegulator::timePerFrame)
		{
			Timer::StartTimer();
			timeSinceLastUpdate -= FpsRegulator::timePerFrame;
			update(FpsRegulator::timePerFrame);
			std::cout<<"Elapsed ms = "<<Timer::GetElapsedMs()<<std::endl;
		}

		render();
	}
}


void Application::update(sf::Time deltaT)
{
	m_window.Update(1);
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

		if(event.type == sf::Event::Closed)
			m_window.Exit();

		//std::cout<<"inputEvent = "<<inputEvent.joystickButton<<" , "<<(unsigned int)inputEvent.keyboardKey<<std::endl;

	}
}










