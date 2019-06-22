#ifndef WORLD_H
#define WORLD_H
#include "SFML/Graphics.hpp"
#include "HungryDot.h"
#include "ArrowsPool.h"


class World
{

	public:

		World();

		void Render(sf::RenderWindow& , const HungryDot& arg_hungryDot);
		bool Update(HungryDot& arg_hungryDot , sf::Time , bool);
		void Reset();
		void Level1();

		~World()
		{
			std::cout<<"World destructor"<<std::endl;
		}

		
	private:


		sf::Vector2u GenNewArrowPos(unsigned int startingDirection);
		void ReloadVegetables();

		sf::Texture fruitsTexture;
		sf::Texture arrowsTexture;
		
		sf::Font font;
		sf::Text textScore;

		std::vector<sf::Sprite> vegSprites;
		//std::vector<std::unique_ptr<Arrow> > arrowsToDraw;
		std::vector<ArrowsObjectPool::arrowUniquePtr> arrowsToDraw;

		std::shared_ptr<ArrowsObjectPool> arrowsPool;

		unsigned int DEFAULT_NR_OF_VEG = 100;
		unsigned int DEFAULT_NR_OF_ARROWS = 4;

};





#endif
