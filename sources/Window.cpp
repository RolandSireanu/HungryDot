#include "Window.h"
#include "FpsRegulator.h"
#include <iostream>
#include <string>

Window::Window()
{
	Setup("Window" , FpsRegulator::resolution);
}

Window::Window(const std::string& title , const sf::Vector2u& windowSize )
{
	Setup(title , windowSize);

}


void Window::Setup(const std::string& title , const sf::Vector2u& windowSize)
{			
	m_windowTitle = title;
	m_windowSize = windowSize;
	m_isDone = false;
	m_isFullscreen = false;
	Create();

}

void Window::Create()
{
	auto windowStyle = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Close | sf::Style::Default | sf::Style::Resize);

	m_window.create(sf::VideoMode(m_windowSize.x , m_windowSize.y) , m_windowTitle ,  windowStyle);

}

void Window::Destroy()
{
	m_window.close();
}

void Window::Update(unsigned int argScore)
{

	sf::Event event;



	while(m_window.pollEvent(event))
	{
		std::cout<<"==================================================================="<<std::endl;
		if(event.type == sf::Event::Closed)
			m_isDone = true;
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
			ToggleFullscreen();
	}
}

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void Window::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
	m_window.display();
}

bool Window::IsDone()
{
	return m_isDone;
}

bool Window::IsFullscreen()
{
	return m_isFullscreen;
}

sf::Vector2u Window::GetWindowSize()
{
	return m_windowSize;
}

void Window::Draw(sf::Drawable& drawable)
{
	m_window.draw(drawable);
}

sf::RenderWindow& Window::GetRenderWindow()
{
	return m_window;
}

void Window::Exit()
{
	m_isDone = true;
}



