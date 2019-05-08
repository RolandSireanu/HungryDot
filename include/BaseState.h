/*
 * BaseState.h
 *
 *  Created on: Feb 25, 2019
 *      Author: roland
 */

#ifndef BASESTATE_H_
#define BASESTATE_H_

#include "SFML/Graphics.hpp"
#include <memory>
#include "InputEvents.h"

class StateStack;


class BaseState
{

	public:


		struct SharedContext
		{
				SharedContext(sf::RenderWindow& arg_renderWindow) : sharedRenderWindow(arg_renderWindow)
				{

				}

			public:

				sf::RenderWindow& sharedRenderWindow;
		};

		enum class STATES: unsigned int {STATE_INTRO=0x00};

		BaseState(SharedContext& arg_context , StateStack& arg_stateStack) : sharedContext(arg_context) , stateStack(arg_stateStack)
		{

		}

		virtual void Update(sf::Time) = 0;
		virtual void Render() = 0;
		virtual void HandleInput(InputEvents::Ev) =0;

		virtual ~BaseState(){}

	protected :
		struct SharedContext& sharedContext;
		StateStack& stateStack;


};



#endif /* BASESTATE_H_ */
