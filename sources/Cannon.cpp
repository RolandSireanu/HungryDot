#include "Cannon.h"

unsigned int Cannon::CANNON_REC_SIZE = 32;

Cannon::Cannon(float arg_x , float arg_y , CANNON_DIRECTION arg_dir , sf::Texture& arg_texture) : isFiring(false)
{
    direction = arg_dir;

    firingFramesCounter = 0x00;

    std::cout<<"Cannon constructor ! "<<std::endl;
    srand((unsigned)time(0));

    cannonSprite.setTexture(arg_texture);
    cannonSprite.setPosition(arg_x , arg_y);

    fireLight.setFillColor(sf::Color(255,255,255));
    fireLight.setRadius(5);
    
}

sf::Sprite& Cannon::GetSprite()
{
    return cannonSprite;
}

void Cannon::MoveCannon(double arg_dt)
{
    static double defaultCannonSpeed = 1;
    static double acc = 0.0;    

    const sf::Vector2f pos = cannonSprite.getPosition();

    sf::Vector2f tempPos = cannonSprite.getPosition();

    switch (direction)
    {
        case CANNON_DIRECTION::CANNON_LEFT : 
            if((tempPos.y + defaultCannonSpeed) > FpsRegulator::resolution.y-50)
                defaultCannonSpeed = -1;
            else if((tempPos.y + defaultCannonSpeed) < 50)
                defaultCannonSpeed = 1;
            cannonSprite.move(0 , defaultCannonSpeed);
            break;

        case CANNON_DIRECTION::CANNON_RIGHT :
            cannonSprite.move( 0 , defaultCannonSpeed);
            break;

        case CANNON_DIRECTION::CANNON_UP :
            cannonSprite.move(defaultCannonSpeed , 0);
            break;

        case CANNON_DIRECTION::CANNON_DOWN : 
            cannonSprite.move(defaultCannonSpeed , 0);
            break;

        default : 
            printf("Bad bad case ! \n");
            break;           
    }

    if(isFiring == true)
    {
        firingFramesCounter++;
        if(firingFramesCounter >= 50)
        {
            firingFramesCounter = 0;
            isFiring = false;
        }
        fireLight.setPosition(cannonSprite.getPosition() + sf::Vector2f(10,10));
    }

}

void Cannon::SetFiringMode()
{
    isFiring = true;
    fireLight.setPosition(cannonSprite.getPosition());
}

void Cannon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
    target.draw(cannonSprite , states);
    if(isFiring == true)
        target.draw(fireLight);
	

}