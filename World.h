#ifndef WORLD_H
#define WORLD_H
#include "SFML/Graphics.hpp"


class World
{

	public:

		World();

		void Render(sf::RenderWindow&);
		void Update();
		
	private:

		sf::Sprite fruit;
		sf::Texture fruitsTexture;

};





#endif