#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <array>
#include "SFML/Graphics.hpp"
#include "HungryDot.h"
#include "ArrowsPool.h"
#include "Cannon.h"
#include "FpsRegulator.h"

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
		sf::Texture cannonTextureLeft;
		sf::Texture cannonTextureRight;
		sf::Texture cannonTextureUp;
		sf::Texture cannonTextureDown;


		std::vector<Cannon> cannons;
		//  = {
		// 	{FpsRegulator::resolution.x-Cannon::CANNON_REC_SIZE,FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_LEFT}, 
		// 	{0 , FpsRegulator::resolution.y / 2,Cannon::CANNON_DIRECTION::CANNON_RIGHT},
		// 	{FpsRegulator::resolution.x / 2 , FpsRegulator::resolution.y-32,Cannon::CANNON_DIRECTION::CANNON_UP},
		// 	{FpsRegulator::resolution.x / 2 , 0,Cannon::CANNON_DIRECTION::CANNON_DOWN} 
		// };


		
		sf::Font font;
		sf::Text textScore;

		std::vector<sf::Sprite> vegSprites;		
		std::vector<ArrowsObjectPool::arrowUniquePtr> arrowsToDraw;

		std::shared_ptr<ArrowsObjectPool> arrowsPool;

		unsigned int DEFAULT_NR_OF_VEG = 100;
		unsigned int DEFAULT_NR_OF_ARROWS = 4;

		

};





#endif
