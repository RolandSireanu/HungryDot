#include "StateIntro.h"
#include <iostream>

void StateIntro::Update(sf::Time deltaT)
{
	dotSprite->move((dotXSpeed * deltaT.asSeconds()) , 0);
	float x = dotSprite->getPosition().x;


	if(x > FpsRegulator::resolution.x)
	{
		spritesToDraw.erase(std::remove_if(spritesToDraw.begin() , spritesToDraw.end() , [&](std::shared_ptr<sf::Drawable> sprt){
			return (sprt == dotSprite);
		}) , spritesToDraw.end());

		spritesToDraw.push_back(text);
	}
	else
	{
		if(x >= (FpsRegulator::resolution.x * 0.70) && x <= (FpsRegulator::resolution.x * 0.75))
		{

			dotSprite->setTexture(dotTextureOpen);
			if(x >= (FpsRegulator::resolution.x * 0.72))
			{
				auto it = std::find_if(spritesToDraw.begin() , spritesToDraw.end() , [&](std::shared_ptr<sf::Drawable> argDrawable){
					if(argDrawable == greenBeanSprite)
						return true;
				});

				if(it != spritesToDraw.end())
				{
					std::cout<<"Erase sprite !"<<std::endl;
					spritesToDraw.erase(it);
				}
			}
		}
		else
			dotSprite->setTexture(dotTexture);


	}

}

void StateIntro::Render()
{

	std::for_each(spritesToDraw.begin() , spritesToDraw.end() , [&](std::shared_ptr<sf::Drawable> sprite){
		sharedContext.sharedRenderWindow.draw(*sprite);
	});

}


void StateIntro::HandleInput()
{



}

StateIntro::~StateIntro()
{

}
