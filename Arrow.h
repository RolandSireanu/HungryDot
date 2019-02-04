#ifndef ARROW_H
#define ARROW_H
#include "SFML/Graphics.hpp"


class Arrow
{

	public:

		enum class DIRECTION : unsigned int { RIGHT_LEFT = 0 , LEFT_RIGHT = 1 , DOWN_UP = 2 , UP_DOWN = 3};

		Arrow(DIRECTION direction , const sf::Texture& arg_arrowTexture);

		bool MoveArrow();

		void ResetArrow();

		sf::Vector2u GenNewArrowPos(DIRECTION arg_direction);

		DIRECTION direction;		

		sf::Sprite GetSprite()
		{
			return arrowSprite;
		}

	private:

		sf::Sprite arrowSprite;
		sf::Texture texture;
		static const std::vector<sf::IntRect> originPositions;
		static const std::vector<sf::Vector2f> arrowMoves;
		//static std::vector<
};




#endif