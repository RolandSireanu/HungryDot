#ifndef WORLD_H
#define WORLD_H
#include "SFML/Graphics.hpp"


class World
{

	public:

		World();

		void Render(sf::RenderWindow&);
		void Update();

		void Level1();

		
	private:
		
		sf::Texture fruitsTexture;

		std::vector<sf::Sprite> vegSprites;

		const unsigned int DEFAULT_NR_OF_VEG = 12;
};





#endif