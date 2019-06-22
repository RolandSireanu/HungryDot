#include "ArrowsPool.h"

ArrowsObjectPool::ArrowsObjectPool(const sf::Texture& arg_texture) : texture(arg_texture)
{

}

//Create new function for transition from GameOver -> GAME_STATE
//Reset all arrows and not generate new ones who can hit MOACA from first frames


ArrowsObjectPool::arrowUniquePtr ArrowsObjectPool::AcquireArrow(Arrow::DIRECTION arg_direction , bool arg_firstRun , bool& arg_aquired)
{

	Arrow* ptrArrow = nullptr;

	auto it = std::find_if(pool.begin() , pool.end() , [arg_direction](Arrow* a){
			return (arg_direction == a->direction) ? true : false;
		});

	if(it != pool.end())
	{
		ptrArrow = *it;
		pool.erase(it);
		arg_aquired = true;
	}
	else
	{	std::cout<<"Create new arrow ! "<<(unsigned int)arg_direction<<std::endl;
		ptrArrow = new Arrow((Arrow::DIRECTION) ((unsigned int)arg_direction % 4) , texture , DEFAULT_ARROW_SPEED , arg_firstRun);
		arg_aquired = true;
	}

	arrowUniquePtr uptr(ptrArrow , ArrowsObjectPool::CustomArrowDeleter(this->shared_from_this()));

	return std::move(uptr);

}


ArrowsObjectPool::~ArrowsObjectPool()
{
	std::cout<<"ArrowsObjectPool destructor !"<<std::endl;
	for(Arrow* p : pool)
	{
		delete p;
	}

}
