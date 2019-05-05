#ifndef GAME_H
#define GAME_H
#include "Window.h"
#include "HungryDot.h"
#include "World.h"
#include "FpsRegulator.h"
#include "Arrow.h"
#include "BaseState.h"
#include "StateStack.h"

class Game
{
	public: 
		//Call the world constructor here with all the properties
		Game() : m_window("Hungry dot" , FpsRegulator::resolution) , stop(false) ,
		m_hungryDot(HungryDot::Direction::RIGHT , 6 , 6 , 0.0f , 0.0f) ,
		sharedContext(m_window.GetRenderWindow()),
		stateStack(sharedContext)
		{
			stateStack.addStateToStack(BaseState::STATES::STATE_INTRO);
		}
		~Game(){}

		void HandleInput();
		void Update(sf::Time deltaT);
		void Render();
		Window* GetWindow();

	private:

		void MoveHungryDot();
		struct BaseState::SharedContext sharedContext;
		StateStack stateStack;
		Window m_window;
		HungryDot m_hungryDot;
		//HungryDot m_hungryDot2;
		World m_world;
		bool stop;

		


};


#endif
