#ifndef GAME_H
#define GAME_H
#include "Window.h"
#include "HungryDot.h"
#include "World.h"
#include "FpsRegulator.h"
#include "Arrow.h"
#include "BaseState.h"

class Game : public BaseState
{
	public: 
		//Call the world constructor here with all the properties
		Game() : m_window("Hungry dot" , FpsRegulator::resolution) , stop(false) ,
		m_hungryDot(HungryDot::Direction::RIGHT , 6 , 6 , 0.0f , 0.0f)
		{

		}
		~Game(){}

		void HandleInput();
		void Update(long long deltaT);
		void Render();
		Window* GetWindow();

	private:

		void MoveHungryDot();
		Window m_window;
		HungryDot m_hungryDot;
		//HungryDot m_hungryDot2;
		World m_world;
		bool stop;

		


};


#endif
