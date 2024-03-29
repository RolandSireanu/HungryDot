#ifndef WINDOW_H
#define WINDOW_H


#include "SFML/Graphics.hpp"

class Window{
	public:
		Window();
		Window(const std::string& l_title,const sf::Vector2u& l_size);		
		void BeginDraw(); // Clear the window.
		void EndDraw(); // Display the changes.
		void Update(unsigned int);
		void Exit();
		bool IsDone();
		bool IsFullscreen();
		sf::Vector2u GetWindowSize();
		void ToggleFullscreen();
		void Draw(sf::Drawable& l_drawable);
		sf::RenderWindow& GetRenderWindow();
	private:
		void Setup(const std::string& l_title , const sf::Vector2u& l_size);
		void Destroy();
		void Create();
		sf::RenderWindow m_window;
		sf::Vector2u m_windowSize;
		std::string m_windowTitle;
		bool m_isDone;
		bool m_isFullscreen;

};


#endif
