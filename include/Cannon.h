#ifndef CANNON_H
#define CANNON_H
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "SFML/Graphics.hpp"
#include "FpsRegulator.h"

class Cannon : public sf::Drawable, public sf::Transformable
{
    public:
    enum class CANNON_DIRECTION : unsigned int {
        CANNON_LEFT = 0x00 , 
        CANNON_RIGHT = 0x01 , 
        CANNON_UP = 0x02 , 
        CANNON_DOWN = 0x03
    };  // CANNON_LEFT = |>  , CANNON_RIGHT =  <|  

    public:
        Cannon(float arg_x , float arg_y , CANNON_DIRECTION arg_dir , sf::Texture& arg_texture);        
        void MoveCannon(double arg_dt);
        sf::Sprite& GetSprite();
        void SetFiringMode();
        bool IsFiringNow() { return isFiring; }
        sf::CircleShape& GetFireLight() { return fireLight; }
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


        static unsigned int CANNON_REC_SIZE ;

    private:

        sf::Texture texture;
        sf::Sprite cannonSprite;
        sf::CircleShape fireLight;
        CANNON_DIRECTION direction;
        bool isFiring;
        unsigned int firingFramesCounter;



}; // Wrapper over cannon sprite 




#endif