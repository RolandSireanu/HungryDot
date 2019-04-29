#include "Game.h"
#include "SFML/Window/Joystick.hpp"
#include <iostream>



void Game::Render()
{
	m_window.BeginDraw();
	m_hungryDot.Render(m_window.GetRenderWindow());
	m_world.Render(m_window.GetRenderWindow() , m_hungryDot);
	m_window.EndDraw();
}

void Game::Update(long long deltaT)
{
	if(stop == false)
	{
		HandleInput();
		m_window.Update(m_hungryDot.GetScore());
		m_hungryDot.Update(deltaT);
		stop = m_world.Update(m_hungryDot , deltaT);


	}
	else
	{
		std::cout<<"Your score is : "<<m_hungryDot.GetScore()<<std::endl;
		m_hungryDot.Reset();
//		m_hungryDot2.Reset();
		m_world.Reset();
		stop = false;
	}
}

Window* Game::GetWindow()
{
	return &m_window;
}

void Game::HandleInput()
{

	sf::Event event;
	bool joystickConnected = sf::Joystick::isConnected(0);

	while(m_window.GetRenderWindow().pollEvent(event))
	{		

		if(event.type == sf::Event::JoystickButtonPressed)
		{
			m_hungryDot.HanddleJoystickButton(event.joystickButton.button);
		}

		if(event.type == sf::Event::KeyPressed)
		{
			m_hungryDot.HandleKeyboardButton(event.key.code);
		}
	}
		
}










