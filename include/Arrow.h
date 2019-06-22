#ifndef ARROW_H
#define ARROW_H
#include "SFML/Graphics.hpp"


class Arrow
{

	public:

		enum class DIRECTION : unsigned int { RIGHT_LEFT = 0 , LEFT_RIGHT = 1 , DOWN_UP = 2 , UP_DOWN = 3};

		Arrow(DIRECTION arg_direction , const sf::Texture& arg_arrowTexture , double arg_arrowSpeed , bool);

		//Arrow& operator = (Arrow&& arg_arrow) = default;


		bool MoveArrow(sf::Time);

		void ResetArrow(bool);

		sf::Vector2u GenNewArrowPos(DIRECTION arg_direction);
		sf::Vector2u GenNewArrowPos(DIRECTION arg_direction , sf::Vector2u , sf::Vector2u);
		void RandomizeArrowPos();

		DIRECTION direction;		

		sf::Sprite GetSprite()
		{
			return arrowSprite;
		}

	private:

		void IncreaseSpeedOfArrow();

		sf::Sprite arrowSprite;
		sf::Texture texture;
		static const std::vector<sf::IntRect> originPositions;
		static const std::vector<sf::Vector2f> arrowMoves;
		double defaultArrowSpeed;
		//static std::vector<
};




#endif
