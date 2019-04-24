#include "Game.h"
#include "SFML/Window/Joystick.hpp"

void Game::Render()
{
	m_window.BeginDraw();
	m_hungryDot.Render(m_window.GetRenderWindow());
	m_world.Render(m_window.GetRenderWindow());
	m_window.EndDraw();
}

void Game::Update(long long deltaT)
{
	if(stop == false)
	{
		HandleInput();
		m_window.Update();
		m_hungryDot.Update(deltaT);
		stop = m_world.Update(m_hungryDot , deltaT);

	}
	else
	{
		m_hungryDot.Reset();
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
		if(joystickConnected)
		{
			if(event.type == sf::Event::JoystickButtonPressed)
			{
				if(sf::Joystick::isButtonPressed(0 , 1))
					m_hungryDot.SetDirection(HungryDot::Direction::RIGHT);
				if(sf::Joystick::isButtonPressed(0 , 2))
					m_hungryDot.SetDirection(HungryDot::Direction::UP);	
				if(sf::Joystick::isButtonPressed(0 , 3))
					m_hungryDot.SetDirection(HungryDot::Direction::LEFT);
				if(sf::Joystick::isButtonPressed(0 , 0))
					m_hungryDot.SetDirection(HungryDot::Direction::DOWN);	
			}
		}
		else 
		{
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Left)
				{
					m_hungryDot.SetDirection(HungryDot::Direction::LEFT);
				}
				else if(event.key.code == sf::Keyboard::Right)
				{
					m_hungryDot.SetDirection(HungryDot::Direction::RIGHT);
				}
				else if(event.key.code == sf::Keyboard::Up)			
				{
					m_hungryDot.SetDirection(HungryDot::Direction::UP);	
				}
				else if(event.key.code == sf::Keyboard::Down)
				{
					m_hungryDot.SetDirection(HungryDot::Direction::DOWN);	
				}
			}
		}
		
	}
}
