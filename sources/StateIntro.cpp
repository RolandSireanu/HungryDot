#include "StateIntro.h"
#include <iostream>

void StateIntro::Update()
{
	std::cout<<"StateIntro::Update()"<<std::endl;
}

void StateIntro::Render()
{
	std::cout<<"StateIntro::Render()"<<std::endl;
	sharedContext.sharedRenderWindow.draw(text);
}

void StateIntro::HandleInput()
{

}

StateIntro::~StateIntro()
{

}
