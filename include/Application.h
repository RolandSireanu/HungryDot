/*
 * Application.h
 *
 *  Created on: May 7, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_APPLICATION_H_
#define HUNGRYDOT_INCLUDE_APPLICATION_H_

#include "StateStack.h"
#include "Window.h"
#include "World.h"
#include "FpsRegulator.h"



class Application
{

	public:
		Application();

		void run();


	private:

		void update(sf::Time deltaT);
		void render();
		void handleInputs();

		StateStack stateStack;
		Window m_window;
		World m_world;
		struct BaseState::SharedContext sharedContext;

};



#endif /* HUNGRYDOT_INCLUDE_APPLICATION_H_ */
