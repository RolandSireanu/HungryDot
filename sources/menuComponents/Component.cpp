/*
 * Component.cpp
 *
 *  Created on: May 19, 2019
 *      Author: roland
 */


#include "Component.h"

inline bool Component::isSelected() const noexcept
{
	return selected;
}


inline void Component::select() noexcept
{
	selected = true;
}

Component::~Component()
{

}
