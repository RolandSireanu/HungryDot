/*
 * BaseState.h
 *
 *  Created on: Feb 25, 2019
 *      Author: roland
 */

#ifndef BASESTATE_H_
#define BASESTATE_H_

#include "SFML/Graphics.hpp"

class SharedContext
{
	private:
		SharedContext();

	public:
		static SharedContext* GetInstance()
		{
			if(sharedContext == nullptr)
			{
				sharedContext = new SharedContext();
			}

			return sharedContext;
		}


	sf::RenderWindow* sharedWindow;
	SharedContext* sharedContext;

};


class BaseState
{

	public:

		BaseState()
		{

		}

		virtual void Update() = 0;
		virtual void Render() = 0;

		struct SharedContext& sharedContext;

};



#endif /* BASESTATE_H_ */
