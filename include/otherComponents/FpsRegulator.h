#ifndef FPS_H
#define FPS_H

#include "SFML/Graphics.hpp"

class FpsRegulator
{
	
	public:

		FpsRegulator()
		{			
		}

		static unsigned int GetMsOfSleepApp()
		{
			return 1000 / fps;
		}

		static unsigned int GetFpsDivDotTexture()
		{
			return fps / fpsDot;
		}

		static unsigned int GetFpsDivDot()
		{
			return 3;
		}


	public:
		static unsigned int fps;
		static unsigned int fpsDot;
		static sf::Vector2u resolution;		
		static sf::Vector2u sizeOfHungryDot;
		static sf::Time timePerFrame;
};



#endif
