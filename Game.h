#ifndef GAME_H
#define GAME_H
#include "Window.h"


class Game
{
	public: 
		Game() : m_window("Hungry dot" , sf::Vector2u(1600,1200))
		{
			m_hungryDotTexture.loadFromFile("Media/HungryDot.png");
			m_hungryDotSprite.setTexture(m_hungryDotTexture);
		}
		~Game(){}

		void HandleInput();
		void Update();
		void Render();
		Window* GetWindow();

	private:

		void MoveHungryDot();
		Window m_window;	
		sf::Texture m_hungryDotTexture; 
		sf::Sprite m_hungryDotSprite;


};


#endif