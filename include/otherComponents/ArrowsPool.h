#ifndef ARROWS_POOL
#define ARROWS_POOL

#include "SFML/Graphics.hpp"
#include "Arrow.h"
#include <iostream>
#include <functional>
#include <memory>


class ArrowsObjectPool : public std::enable_shared_from_this<ArrowsObjectPool>
{

	public:

		struct CustomArrowDeleter
		{
			private:
				std::weak_ptr<ArrowsObjectPool> wpArrowObjPool;


			public:

				CustomArrowDeleter(std::shared_ptr<ArrowsObjectPool> arg_spArrowObjPool) : wpArrowObjPool(arg_spArrowObjPool)
				{

				}

				void operator ()(Arrow* arg_ptr)
				{
					std::shared_ptr<ArrowsObjectPool> spArrowObjPool = wpArrowObjPool.lock();

					if(spArrowObjPool != nullptr)
					{
						std::cout<<"Pool is still alive !"<<std::endl;
						spArrowObjPool->addToPool(arg_ptr);
					}
					else
					{
						std::cout<<"Pool no longer alive => delete arrow "<<std::endl;
						std::default_delete<Arrow>{}(arg_ptr);
					}
				}
		};

		//using arrowUniquePtr= std::unique_ptr<Arrow , std::function<void(Arrow*)> >;
	using arrowUniquePtr= std::unique_ptr<Arrow , CustomArrowDeleter>;

	private:

		const double DEFAULT_ARROW_SPEED = 3.0;
		const sf::Texture& texture;
		std::vector<Arrow*> pool;
		//std::vector<arrowUniquePtr> pool;
		const unsigned int MAX_NR_OF_ARROWS = 8;

	public:

		ArrowsObjectPool(const sf::Texture& arg_texture);
		arrowUniquePtr AcquireArrow(Arrow::DIRECTION arg_direction , bool , bool& arg_aquired);		

		void addToPool(Arrow* arg_arrow)
		{
			arg_arrow->ResetArrow(false);
			pool.push_back(arg_arrow);
		}

		std::shared_ptr<ArrowsObjectPool> getPtr()
		{
			return shared_from_this();
		}

		~ArrowsObjectPool();
};



#endif
