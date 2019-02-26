#ifndef ARROWS_POOL
#define ARROWS_POOL

#include "SFML/Graphics.hpp"
#include "Arrow.h"
#include <iostream>

class ArrowsObjectPool
{

	public:

		ArrowsObjectPool(const sf::Texture& arg_texture);
		bool AcquireArrow(Arrow::DIRECTION arg_direction , Arrow** retArrow);
		void ReleaseArrow(Arrow* arg_arrow);

	private:

		const sf::Texture& texture;
		std::vector<Arrow*> pool;
		const unsigned int MAX_NR_OF_ARROWS = 8;			
};







/*

tempPos.x , y = 650 , 423
tempPos.x , y = 0 , 273
tempPos.x , y = 418 , 450
tempPos.x , y = 618 , 0
tempPos.x , y = 650 , 273
tempPos.x , y = 0 , 373
tempPos.x , y = 618 , 450
tempPos.x , y = 18 , 0
*/







#endif