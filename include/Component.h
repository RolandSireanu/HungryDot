/*
 * Component.h
 *
 *  Created on: May 19, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_COMPONENT_H_
#define HUNGRYDOT_INCLUDE_COMPONENT_H_

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>
#include "InputEvents.h"

class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{

	public:

		virtual void handleEvent(InputEvents::Ev) = 0;

		bool isSelected() const noexcept;
		void select() noexcept;

		virtual ~Component();

	protected:

		bool selected;
};



#endif /* HUNGRYDOT_INCLUDE_COMPONENT_H_ */
