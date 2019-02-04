#ifndef WORLD_H
#define WORLD_H
#include "SFML/Graphics.hpp"
#include "HungryDot.h"
#include "ArrowsPool.h"


class World
{

	public:

		World();

		void Render(sf::RenderWindow&);
		void Update(const HungryDot& arg_hungryDot);

		void Level1();

		
	private:


		sf::Vector2u GenNewArrowPos(unsigned int startingDirection);
		void LoadArrows();


		sf::Texture fruitsTexture;
		sf::Texture arrowsTexture;
		
		std::vector<sf::Sprite> vegSprites;
		std::vector<Arrow*> arrowsToDraw;

		ArrowsObjectPool arrowsPool;

		const unsigned int DEFAULT_NR_OF_VEG = 12;
		const unsigned int DEFAULT_NR_OF_ARROWS = 4;		

};





#endif