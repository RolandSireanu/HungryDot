#include "World.h"

World::World()
{
	fruitsTexture.loadFromFile("Media/Vegetable.png");

	fruit.setTexture(fruitsTexture);
	fruit.setTextureRect(sf::IntRect(0,0,50,50));

	/*fruit[0].position = sf::Vector2f(30,30);	
	fruit[1].position = sf::Vector2f(30,90);
	fruit[2].position = sf::Vector2f(90,30);
	fruit[3].position = sf::Vector2f(90,90);

	fruit[0].texCoords = sf::Vector2f(30,30);
	fruit[1].texCoords = sf::Vector2f(30,90);
	fruit[2].texCoords = sf::Vector2f(90,30);
	fruit[3].texCoords = sf::Vector2f(90,90);
	*/
}

void World::Update()
{

}

void World::Render(sf::RenderWindow& arg_window)
{
	arg_window.draw(fruit);
}