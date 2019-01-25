#ifndef GAME_H
#define GAME_H
#include "Window.h"
#include "HungryDot.h"
#include "World.h"

class Game
{
	public: 
		//Call the world constructor here with all the properties
		Game() : m_window("Hungry dot" , sf::Vector2u(800,600))
		{
			
		}
		~Game(){}

		void HandleInput();
		void Update();
		void Render();
		Window* GetWindow();

	private:

		void MoveHungryDot();
		Window m_window;
		HungryDot m_hungryDot;
		World m_world;
		


};


#endif