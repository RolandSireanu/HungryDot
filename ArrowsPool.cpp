#include "ArrowsPool.h"


ArrowsObjectPool::ArrowsObjectPool(const sf::Texture& arg_texture) : texture(arg_texture)
{
	//pool.resize(MAX_NR_OF_ARROWS);
	unsigned int indexer = 0;


	for(int c = 0; c < MAX_NR_OF_ARROWS; c++)
	{
		Arrow* tempArrow = new Arrow((Arrow::DIRECTION) (indexer % 4) , texture);

		pool.push_back(tempArrow) ;
		indexer++;
	}   

}

bool ArrowsObjectPool::AcquireArrow(Arrow::DIRECTION arg_direction , Arrow** retArrow)
{
/*
	for(auto it=pool.begin(); it != pool.end(); it++)
	{
		std::cout<<" (*it)->direction = "<<(unsigned int)(*it)->direction<<std::endl;
	}
*/	
	std::cout<<"Trying to acquire arrow "<<std::endl;
	auto it = std::find_if(pool.begin() , pool.end() , [=](Arrow* a){
		return (arg_direction == a->direction) ? true : false;
	});



	if(it != pool.end())
	{
		std::cout<<"Arrow aquired !"<<std::endl;		
		*retArrow = (*it);
		pool.erase(it);
		return true;
	}
	else
	{
		std::cout<<"Arrow not aquired !"<<std::endl;
		return false;
	}

}

void ArrowsObjectPool::ReleaseArrow(Arrow* arg_arrow)
{
	arg_arrow->ResetArrow();
	pool.push_back(arg_arrow);
}