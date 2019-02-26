#include "Game.h"

void Game::Render()
{
	m_window.BeginDraw();
	m_hungryDot.Render(m_window.GetRenderWindow());
	m_world.Render(m_window.GetRenderWindow());
	m_window.EndDraw();
}

void Game::Update()
{
	if(stop == false)
	{
		HandleInput();
		m_window.Update();
		m_hungryDot.Update();
		stop = m_world.Update(m_hungryDot);

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


	while(m_window.GetRenderWindow().pollEvent(event))
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
